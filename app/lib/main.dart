import 'dart:async';
import 'dart:io';
import 'dart:math' as math;

import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import 'hid.dart';
import 'side.dart';
import 'vt9.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  runApp(const RapooApp());
}

class RapooApp extends StatelessWidget {
  const RapooApp({super.key});

  @override
  Widget build(BuildContext context) {
    const seed = Color(0xFFE5482A); // Rapoo-ish signal red
    return MaterialApp(
      title: 'Rapoo VT9',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(useMaterial3: true, colorSchemeSeed: seed, brightness: Brightness.light),
      darkTheme: ThemeData(useMaterial3: true, colorSchemeSeed: seed, brightness: Brightness.dark),
      home: const HomePage(),
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  final RapooHidChannel _hid = RapooHidChannel();
  late final Vt9 _vt9 = Vt9(_hid);
  HidStatus _status = const HidStatus();
  final SideKeyChannel _sideCh = SideKeyChannel();
  SideStatus _side = const SideStatus();
  StreamSubscription<RxFrame>? _rxSub;
  StreamSubscription<HidStatus>? _stSub;
  StreamSubscription<SideStatus>? _sideSub;
  Timer? _poll;
  Timer? _batteryTimer;

  MouseState? _m;
  int? _pid;
  bool _busy = false;
  bool _connecting = false;
  String? _error;
  DateTime? _backupAt;

  // Local edits; written to the mouse by each card's Apply button.
  List<DpiStage> _stages = [];
  DpiStage? _active;
  bool _activeTouched = false;
  int _pollHz = 1000;
  int _lod = 0;
  SysBlock _sys = SysBlock();

  final List<String> _tests = <String>[];
  DateTime _lastScroll = DateTime(0);
  final FocusNode _testFocus = FocusNode(debugLabel: 'button tester');
  final List<String> _log = <String>[];
  final TextEditingController _tx = TextEditingController(text: 'ba a5 a3');

  @override
  void initState() {
    super.initState();
    _rxSub = _hid.rx.listen(_onRx);
    _stSub = _hid.statusChanges.listen(_onStatus);
    _sideSub = _sideCh.statusChanges.listen((s) {
      if (mounted) setState(() => _side = s);
    });
    _refreshStatus();
    _poll = Timer.periodic(const Duration(seconds: 2), (_) => _refreshStatus());
    _batteryTimer = Timer.periodic(const Duration(seconds: 60), (_) => _readBattery());
  }

  @override
  void dispose() {
    _rxSub?.cancel();
    _stSub?.cancel();
    _sideSub?.cancel();
    _poll?.cancel();
    _batteryTimer?.cancel();
    _testFocus.dispose();
    _tx.dispose();
    super.dispose();
  }

  // ---- connection

  Future<void> _refreshStatus() async {
    _onStatus(await _hid.status());
    final side = await _sideCh.status();
    if (mounted) setState(() => _side = side);
  }

  void _onStatus(HidStatus s) {
    if (!mounted) return;
    final pids = s.devices.map((d) => (d['pid'] as num?)?.toInt() ?? 0).toSet();
    final want = !s.connected
        ? null
        : pids.contains(kWiredPid)
            ? kWiredPid
            : pids.contains(kReceiverPid)
                ? kReceiverPid
                : (pids.isEmpty ? null : pids.first);
    setState(() => _status = s);
    if (want != _pid) {
      setState(() {
        _pid = want;
        _m = null;
        _error = null;
      });
      if (want != null) _connect();
    }
  }

  Future<void> _connect() async {
    final pid = _pid;
    if (pid == null || _connecting) return;
    _connecting = true;
    setState(() {
      _busy = true;
      _error = null;
    });
    try {
      _vt9.pid = pid;
      try {
        await _vt9.handshake(); // the official driver sends this first; reads may fail without it
      } on Vt9Exception {
        // a sleeping mouse ignores it; readAll() below reports the real problem
      }
      final m = await _vt9.readAll();
      await saveBackupOnce(m);
      final f = backupFile(pid);
      final at = await f.exists() ? (await f.stat()).modified : null;
      if (!mounted || _pid != pid) return;
      setState(() {
        _m = m;
        _backupAt = at;
        _load(m);
      });
    } catch (e) {
      if (mounted) setState(() => _error = '$e');
    } finally {
      _connecting = false;
      if (mounted) setState(() => _busy = false);
    }
  }

  Future<void> _reload() async {
    if (_m == null) return _connect();
    if (_busy) return;
    setState(() => _busy = true);
    try {
      final m = await _vt9.readAll();
      if (mounted) {
        setState(() {
          _m = m;
          _error = null;
          _load(m);
        });
      }
    } catch (e) {
      _toast('Could not read the mouse: $e', error: true);
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  void _load(MouseState m) {
    _stages = m.stages;
    final st = m.stage.clamp(0, 6);
    _active = _stages[st].enabled ? _stages[st] : _stages.first;
    _activeTouched = false;
    _pollHz = m.pollHz ?? 1000;
    _lod = m.lodStep;
    _sys = m.sys;
  }

  Future<void> _readBattery() async {
    final m = _m;
    if (m == null || _busy) return;
    try {
      final b = await _vt9.battery();
      if (mounted && b != null) setState(() => m.battery = b);
    } catch (_) {
      // asleep; the next push or poll will catch up
    }
  }

  void _onRx(RxFrame f) {
    final d = f.data;
    // Unprompted battery report: bb b0 42 40 06 <state> <percent>
    if (d.length >= 7 && d[0] == 0xBB && d[1] == 0xB0 && _m != null) {
      setState(() => _m!.battery = Battery(d[6].clamp(0, 100), d[5] == 2));
    }
    _addLog('rx  ${f.hex}');
  }

  // ---- writes

  Future<void> _run(String what, Future<void> Function() op) async {
    if (_busy || _m == null) return;
    setState(() => _busy = true);
    try {
      await op();
      if (mounted) {
        setState(() => _load(_m!));
        _toast('$what saved to the mouse');
      }
    } catch (e) {
      _toast('$what failed: $e', error: true);
      try {
        final m = await _vt9.readAll();
        if (mounted) {
          setState(() {
            _m = m;
            _load(m);
          });
        }
      } catch (_) {}
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  List<DpiStage> get _enabledStages => _stages.where((e) => e.enabled).toList();

  bool get _dpiDirty {
    final m = _m;
    if (m == null || _stages.isEmpty) return false;
    final idx = math.max(0, _enabledStages.indexOf(_active ?? _stages.first));
    return !_eq(Vt9.encodeStages(_stages), m.raw[addrDpi]!) || (_activeTouched && idx != m.stage);
  }

  bool get _perfDirty => _m != null && (_pollHz != _m!.pollHz || _lod != _m!.lodStep);

  bool get _sysDirty => _m != null && !_eq(_sys.encode(), _m!.raw[addrSys]!);

  Future<void> _applyDpi() => _run('DPI', () async {
        final idx = math.max(0, _enabledStages.indexOf(_active ?? _stages.first));
        await _vt9.setDpi(_m!, _stages, _activeTouched ? idx : null);
      });

  Future<void> _applyPerf() => _run('Performance', () async {
        final m = _m!;
        if (_pollHz != m.pollHz) await _vt9.setPolling(m, _pollHz);
        if (_lod != m.lodStep) await _vt9.setLod(m, _lod);
      });

  Future<void> _applySys() => _run('Sensor settings', () => _vt9.setSys(_m!, _sys));

  Future<void> _pickKey(int key, String name) async {
    final m = _m;
    if (m == null || _busy) return;
    final picked = await showDialog<List<int>>(
      context: context,
      builder: (ctx) => _ActionPicker(name: name, current: m.keyAction(key)),
    );
    if (picked == null || _eq(picked, m.keyAction(key))) return;
    await _run(name, () => _vt9.setKey(m, key, picked));
  }

  /// Back -> F15 and Forward -> F13 on the mouse, then the F-key -> button 6/7 conversion on.
  Future<void> _setGestureKeys() async {
    await _run('Side buttons', () async {
      final m = _m!;
      if (!_eq(m.keyAction(8), keyF15)) await _vt9.setKey(m, 8, keyF15);
      if (!_eq(m.keyAction(7), keyF13)) await _vt9.setKey(m, 7, keyF13);
    });
    if (!_side.enabled) {
      final s = await _sideCh.setEnabled(true);
      if (mounted) setState(() => _side = s);
    }
  }

  Future<void> _restore() async {
    final m = _m;
    if (m == null) return;
    final raw = await loadBackup(m.pid);
    if (raw == null) return _toast('No backup found for this mouse', error: true);
    if (!mounted) return;
    final ok = await showDialog<bool>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: const Text('Restore saved settings?'),
        content: Text('This writes the settings backed up ${_fmt(_backupAt)} back to the mouse: '
            'DPI stages, polling rate, lift-off distance, sensor settings and every button.'),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx, false), child: const Text('Cancel')),
          FilledButton(onPressed: () => Navigator.pop(ctx, true), child: const Text('Restore')),
        ],
      ),
    );
    if (ok == true) await _run('Restore', () => _vt9.restore(m, raw));
  }

  // ---- helpers

  static bool _eq(List<int> a, List<int> b) {
    if (a.length != b.length) return false;
    for (var i = 0; i < a.length; i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }

  static String _two(int v) => v.toString().padLeft(2, '0');

  static String _fmt(DateTime? d) {
    if (d == null) return 'earlier';
    const months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
    return 'on ${d.day} ${months[d.month - 1]} ${d.year}, ${_two(d.hour)}:${_two(d.minute)}';
  }

  void _toast(String msg, {bool error = false}) {
    if (!mounted) return;
    final cs = Theme.of(context).colorScheme;
    ScaffoldMessenger.of(context).showSnackBar(SnackBar(
      content: Text(msg, style: error ? TextStyle(color: cs.onError) : null),
      backgroundColor: error ? cs.error : null,
      behavior: SnackBarBehavior.floating,
      duration: Duration(seconds: error ? 6 : 2),
    ));
  }

  void _addLog(String line) {
    if (!mounted) return;
    final t = DateTime.now();
    final stamp = '${_two(t.hour)}:${_two(t.minute)}:${_two(t.second)}.${t.millisecond.toString().padLeft(3, '0')}';
    setState(() {
      _log.insert(0, '$stamp  $line');
      if (_log.length > 400) _log.removeLast();
    });
  }

  void _test(String what) {
    setState(() {
      _tests.insert(0, what);
      if (_tests.length > 8) _tests.removeLast();
    });
  }

  // Log scale: 50 .. 26000 DPI over the slider, rounded to steps that grow with the value.
  static double _dpiToPos(int dpi) => math.log(dpi / 50) / math.log(520);

  static int _posToDpi(double p) {
    final raw = 50 * math.pow(520, p);
    final step = raw < 1000 ? 50 : raw < 4000 ? 100 : raw < 10000 ? 200 : 500;
    return ((raw / step).round() * step).clamp(50, 26000).toInt();
  }

  // ---- UI

  @override
  Widget build(BuildContext context) {
    final cs = Theme.of(context).colorScheme;
    final m = _m;
    final b = m?.battery;
    return Scaffold(
      appBar: AppBar(
        title: const Text('Rapoo VT9 Pro'),
        actions: [
          if (b != null)
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 4),
              child: Chip(
                avatar: Icon(
                  b.charging
                      ? Icons.battery_charging_full
                      : b.percent > 80
                          ? Icons.battery_full
                          : b.percent > 50
                              ? Icons.battery_5_bar
                              : b.percent > 20
                                  ? Icons.battery_3_bar
                                  : Icons.battery_alert,
                  size: 18,
                  color: b.percent <= 20 && !b.charging ? cs.error : cs.primary,
                ),
                label: Text('${b.percent}%${b.charging ? ' · charging' : ''}'),
              ),
            ),
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 4),
            child: Chip(
              avatar: Icon(m != null ? Icons.mouse : Icons.mouse_outlined,
                  size: 18, color: m != null ? cs.primary : cs.error),
              label: Text(m == null
                  ? (_status.connected ? 'Connecting…' : 'Not connected')
                  : m.wired
                      ? 'USB cable'
                      : '2.4 GHz receiver'),
            ),
          ),
          IconButton(
            tooltip: 'Read settings from the mouse',
            onPressed: _status.connected && !_busy ? _reload : null,
            icon: const Icon(Icons.refresh),
          ),
          PopupMenuButton<String>(
            tooltip: 'More',
            onSelected: (v) {
              if (v == 'restore') _restore();
              if (v == 'folder') Process.run('open', [supportDir]);
            },
            itemBuilder: (_) => [
              PopupMenuItem(value: 'restore', enabled: m != null && !_busy, child: const Text('Restore saved settings…')),
              const PopupMenuItem(value: 'folder', child: Text('Show backups in Finder')),
            ],
          ),
          const SizedBox(width: 8),
        ],
      ),
      body: Stack(
        children: [
          Center(
            child: ConstrainedBox(
              constraints: const BoxConstraints(maxWidth: 820),
              child: ListView(
                padding: const EdgeInsets.all(16),
                children: [
                  if (_status.inputMonitoring != 'granted') _permissionBanner(cs),
                  if (_status.inputMonitoring == 'granted' && !_status.connected) _notConnectedBanner(cs),
                  if (_error != null) _errorBanner(cs),
                  if (m != null) ...[
                    _deviceCard(m),
                    _gestureCard(cs, m),
                    _dpiCard(cs),
                    _performanceCard(),
                    _sensorCard(),
                    _buttonsCard(m),
                    _testerCard(cs),
                  ] else if (_status.connected && _error == null)
                    const Padding(
                      padding: EdgeInsets.all(32),
                      child: Center(child: Text('Reading settings from the mouse…')),
                    ),
                  _consoleCard(cs),
                ],
              ),
            ),
          ),
          if (_busy) const Positioned(left: 0, right: 0, top: 0, child: LinearProgressIndicator()),
        ],
      ),
    );
  }

  Widget _banner(ColorScheme cs, IconData icon, String text, {Widget? action}) => Card(
        color: cs.errorContainer,
        margin: const EdgeInsets.only(bottom: 16),
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Row(
            children: [
              Icon(icon, color: cs.onErrorContainer),
              const SizedBox(width: 12),
              Expanded(child: Text(text, style: TextStyle(color: cs.onErrorContainer))),
              if (action != null) ...[const SizedBox(width: 12), action],
            ],
          ),
        ),
      );

  Widget _permissionBanner(ColorScheme cs) => _banner(
        cs,
        Icons.lock_outline,
        'Input Monitoring is needed. The mouse\'s settings channel shares a USB interface with its '
        'macro keyboard, so macOS asks before the app can open it. Only the mouse\'s settings '
        'messages are read; keyboard reports are discarded.',
        action: FilledButton(
          onPressed: () async {
            final st = await _hid.requestInputMonitoring();
            if (mounted) setState(() => _status = st);
          },
          child: const Text('Grant…'),
        ),
      );

  Widget _notConnectedBanner(ColorScheme cs) => _banner(
        cs,
        Icons.info_outline,
        'Plug in the VT9 Pro\'s 2.4 GHz receiver, or connect the mouse with its USB cable. '
        'Bluetooth does not carry the settings channel.',
      );

  Widget _errorBanner(ColorScheme cs) => _banner(
        cs,
        Icons.error_outline,
        'Could not read the mouse: $_error. Move it to wake it up, then try again.',
        action: FilledButton(onPressed: _busy ? null : _connect, child: const Text('Try again')),
      );

  Widget _card({
    required String title,
    String? subtitle,
    required Widget child,
    VoidCallback? onApply,
    bool dirty = false,
  }) {
    final text = Theme.of(context).textTheme;
    return Card(
      margin: const EdgeInsets.only(bottom: 16),
      child: Padding(
        padding: const EdgeInsets.all(20),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(title, style: text.titleLarge),
                      if (subtitle != null)
                        Padding(
                          padding: const EdgeInsets.only(top: 4),
                          child: Text(subtitle, style: text.bodySmall),
                        ),
                    ],
                  ),
                ),
                if (onApply != null)
                  FilledButton.icon(
                    onPressed: dirty && !_busy ? onApply : null,
                    icon: const Icon(Icons.check),
                    label: const Text('Apply'),
                  ),
              ],
            ),
            const SizedBox(height: 16),
            child,
          ],
        ),
      ),
    );
  }

  Widget _label(String text) => Padding(
        padding: const EdgeInsets.only(top: 12, bottom: 6),
        child: Text(text, style: Theme.of(context).textTheme.labelLarge),
      );

  Widget _deviceCard(MouseState m) => _card(
        title: 'Mouse',
        subtitle: [
          m.wired ? 'USB cable' : '2.4 GHz receiver',
          if (m.firmware != null) 'firmware ${m.firmware}',
          if (m.receiver != null) 'receiver firmware ${m.receiver}',
        ].join(' · '),
        child: Row(
          children: [
            const Icon(Icons.history, size: 18),
            const SizedBox(width: 8),
            Expanded(
              child: Text(_backupAt == null
                  ? 'The settings found on the mouse will be backed up before anything is changed.'
                  : 'The settings found on the mouse were backed up ${_fmt(_backupAt)}.'),
            ),
            OutlinedButton(onPressed: _busy ? null : _restore, child: const Text('Restore…')),
          ],
        ),
      );

  Widget _gestureCard(ColorScheme cs, MouseState m) {
    final s = _side;
    final keysSet = _eq(m.keyAction(8), keyF15) && _eq(m.keyAction(7), keyF13);
    final state = !s.enabled
        ? 'Off: the side buttons reach apps as the F15 / F13 keys.'
        : s.tapActive
            ? 'On: Back is mouse button 6, Forward is mouse button 7.'
            : s.accessibility
                ? 'Starting…'
                : 'Waiting for Accessibility permission.';
    return _card(
      title: 'LinearMouse gesture button',
      subtitle: 'Back sends F15 and Forward sends F13. The app turns them into mouse buttons 6 and 7, '
          'which no app uses by default, so LinearMouse can take button 6 as its gesture button. '
          'Keep this app running (it can stay closed in the Dock).',
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          if (!keysSet)
            Padding(
              padding: const EdgeInsets.only(bottom: 8),
              child: Row(
                children: [
                  const Expanded(child: Text('Back and Forward are not set to F15 / F13 on the mouse yet.')),
                  FilledButton(onPressed: _busy ? null : _setGestureKeys, child: const Text('Set them')),
                ],
              ),
            ),
          SwitchListTile(
            contentPadding: EdgeInsets.zero,
            title: const Text('Turn F15 / F13 into mouse buttons 6 / 7'),
            subtitle: Text(state),
            value: s.enabled,
            onChanged: (v) async {
              final st = await _sideCh.setEnabled(v);
              if (mounted) setState(() => _side = st);
            },
          ),
          if (s.enabled && !s.accessibility)
            Padding(
              padding: const EdgeInsets.only(bottom: 8),
              child: Row(
                children: [
                  Icon(Icons.lock_outline, color: cs.error),
                  const SizedBox(width: 8),
                  const Expanded(
                    child: Text('Needs Accessibility: in System Settings › Privacy & Security › '
                        'Accessibility, switch on "Rapoo VT9".'),
                  ),
                  FilledButton(
                    onPressed: () async {
                      final st = await _sideCh.requestAccessibility();
                      if (mounted) setState(() => _side = st);
                    },
                    child: const Text('Grant…'),
                  ),
                ],
              ),
            ),
          SwitchListTile(
            contentPadding: EdgeInsets.zero,
            title: const Text('Open at login'),
            subtitle: Text(s.loginItem == 'requiresApproval'
                ? 'Approve it in System Settings › General › Login Items.'
                : 'Keeps the buttons working after a restart.'),
            value: s.loginItem == 'enabled' || s.loginItem == 'requiresApproval',
            onChanged: s.loginItem == 'unsupported'
                ? null
                : (v) async {
                    final st = await _sideCh.setLoginItem(v);
                    if (mounted) setState(() => _side = st);
                  },
          ),
          if (s.error.isNotEmpty) Text(s.error, style: TextStyle(color: cs.error)),
        ],
      ),
    );
  }

  Widget _dpiCard(ColorScheme cs) => _card(
        title: 'DPI stages',
        subtitle: 'The DPI button cycles through the stages that are switched on. '
            'The filled dot is the stage in use. 50 – 26000 DPI.',
        dirty: _dpiDirty,
        onApply: _applyDpi,
        child: Column(
          children: [
            for (var i = 0; i < _stages.length; i++) _dpiRow(cs, i, _stages[i]),
          ],
        ),
      );

  Widget _dpiRow(ColorScheme cs, int i, DpiStage st) {
    final active = identical(st, _active);
    return Row(
      children: [
        IconButton(
          tooltip: 'Use this stage now',
          onPressed: st.enabled
              ? () => setState(() {
                    _active = st;
                    _activeTouched = true;
                  })
              : null,
          icon: Icon(active ? Icons.radio_button_checked : Icons.radio_button_unchecked,
              color: active ? cs.primary : null),
        ),
        Switch(
          value: st.enabled,
          onChanged: (v) {
            if (!v && _enabledStages.length == 1) {
              _toast('At least one stage has to stay on');
              return;
            }
            setState(() {
              st.enabled = v;
              if (!v && active) {
                _active = _enabledStages.first;
                _activeTouched = true;
              }
            });
          },
        ),
        Expanded(
          child: Slider(
            value: _dpiToPos(st.dpi).clamp(0.0, 1.0),
            label: '${st.dpi}',
            onChanged: (p) => setState(() => st.dpi = _posToDpi(p)),
          ),
        ),
        SizedBox(
          width: 88,
          child: TextButton(
            onPressed: () => _editDpi(st),
            child: Text('${st.dpi}',
                style: TextStyle(color: st.enabled ? null : Theme.of(context).disabledColor)),
          ),
        ),
      ],
    );
  }

  Future<void> _editDpi(DpiStage st) async {
    final c = TextEditingController(text: '${st.dpi}');
    final v = await showDialog<int>(
      context: context,
      builder: (ctx) {
        void done() => Navigator.pop(ctx, int.tryParse(c.text.trim()));
        return AlertDialog(
          title: const Text('DPI'),
          content: TextField(
            controller: c,
            autofocus: true,
            keyboardType: TextInputType.number,
            inputFormatters: [FilteringTextInputFormatter.digitsOnly],
            decoration: const InputDecoration(helperText: '50 – 26000, in steps of 50'),
            onSubmitted: (_) => done(),
          ),
          actions: [
            TextButton(onPressed: () => Navigator.pop(ctx), child: const Text('Cancel')),
            FilledButton(onPressed: done, child: const Text('OK')),
          ],
        );
      },
    );
    c.dispose();
    if (v != null) setState(() => st.dpi = ((v / 50).round() * 50).clamp(50, 26000));
  }

  Widget _performanceCard() => _card(
        title: 'Performance',
        subtitle: 'How often the mouse reports, and how high it can be lifted before it stops tracking.',
        dirty: _perfDirty,
        onApply: _applyPerf,
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            _label('Polling rate'),
            SegmentedButton<int>(
              segments: [for (final hz in pollRates) ButtonSegment(value: hz, label: Text('$hz Hz'))],
              selected: {_pollHz},
              onSelectionChanged: (s) => setState(() => _pollHz = s.first),
            ),
            _label('Lift-off distance: ${(1 + _lod / 10).toStringAsFixed(1)} mm'),
            Slider(
              value: _lod.toDouble(),
              min: 0,
              max: 10,
              divisions: 10,
              label: '${(1 + _lod / 10).toStringAsFixed(1)} mm',
              onChanged: (v) => setState(() => _lod = v.round()),
            ),
          ],
        ),
      );

  Widget _sensorCard() => _card(
        title: 'Sensor and buttons',
        subtitle: _sys.valid
            ? 'Stored on the mouse.'
            : 'Not stored on the mouse yet, so it runs on its built-in defaults. '
                'Shown here are Rapoo\'s defaults; Apply stores them along with your changes.',
        dirty: _sysDirty,
        onApply: _applySys,
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            SwitchListTile(
              contentPadding: EdgeInsets.zero,
              title: const Text('Motion Sync'),
              subtitle: const Text('Smooths the reported path. Off gives the rawest tracking.'),
              value: _sys.motionSync,
              onChanged: (v) => setState(() => _sys.motionSync = v),
            ),
            SwitchListTile(
              contentPadding: EdgeInsets.zero,
              title: const Text('Angle snapping'),
              subtitle: const Text('Rapoo calls it linear correction: straightens near-horizontal '
                  'and near-vertical strokes.'),
              value: _sys.linear,
              onChanged: (v) => setState(() => _sys.linear = v),
            ),
            SwitchListTile(
              contentPadding: EdgeInsets.zero,
              title: const Text('Ripple control'),
              subtitle: const Text('Rapoo calls it ripple correction: smooths jitter at high DPI.'),
              value: _sys.ripple,
              onChanged: (v) => setState(() => _sys.ripple = v),
            ),
            _label('Sensor angle: ${_sys.angle > 0 ? '+' : ''}${_sys.angle}°'),
            Slider(
              value: _sys.angle.clamp(-30, 30).toDouble(),
              min: -30,
              max: 30,
              divisions: 60,
              label: '${_sys.angle}°',
              onChanged: (v) => setState(() => _sys.angle = v.round()),
            ),
            _label('Button press debounce (ms)'),
            SegmentedButton<int>(
              showSelectedIcon: false,
              segments: [for (final ms in debounceMs) ButtonSegment(value: ms, label: Text('$ms'))],
              selected: {_sys.down},
              onSelectionChanged: (s) => setState(() => _sys.down = s.first),
            ),
            _label('Button release debounce (ms)'),
            SegmentedButton<int>(
              showSelectedIcon: false,
              segments: [for (final ms in debounceMs) ButtonSegment(value: ms, label: Text('$ms'))],
              selected: {_sys.up},
              onSelectionChanged: (s) => setState(() => _sys.up = s.first),
            ),
            _label('Sleep after ${_sys.sleepMin} min without movement (wireless only)'),
            Slider(
              value: _sys.sleepMin.clamp(1, 120).toDouble(),
              min: 1,
              max: 120,
              divisions: 119,
              label: '${_sys.sleepMin} min',
              onChanged: (v) => setState(() => _sys.sleepMin = v.round()),
            ),
            Wrap(
              spacing: 8,
              children: [
                for (final min in const [5, 10, 30, 60, 120])
                  ChoiceChip(
                    label: Text('$min min'),
                    selected: _sys.sleepMin == min,
                    onSelected: (_) => setState(() => _sys.sleepMin = min),
                  ),
              ],
            ),
          ],
        ),
      );

  static IconData _keyIcon(int key) => switch (key) {
        0 || 1 || 2 => Icons.mouse_outlined,
        5 => Icons.add,
        6 => Icons.remove,
        7 => Icons.arrow_forward,
        8 => Icons.arrow_back,
        11 => Icons.keyboard_arrow_up,
        12 => Icons.keyboard_arrow_down,
        _ => Icons.radio_button_unchecked,
      };

  Widget _buttonsCard(MouseState m) => _card(
        title: 'Buttons',
        subtitle: 'Click a button to change what it does. Each change is saved to the mouse straight away.',
        child: Column(
          children: [
            for (final (key, name) in vt9Keys)
              ListTile(
                contentPadding: EdgeInsets.zero,
                dense: true,
                leading: Icon(_keyIcon(key)),
                title: Text(name),
                subtitle: Text(describeAction(m.keyAction(key))),
                trailing: const Icon(Icons.chevron_right),
                onTap: _busy ? null : () => _pickKey(key, name),
              ),
          ],
        ),
      );

  static String _buttonsName(int b) => [
        if (b & kPrimaryButton != 0) 'Left click',
        if (b & kSecondaryMouseButton != 0) 'Right click',
        if (b & kMiddleMouseButton != 0) 'Middle click',
        if (b & kBackMouseButton != 0) 'Back (button 4)',
        if (b & kForwardMouseButton != 0) 'Forward (button 5)',
        for (var i = 5; i < 16; i++)
          if (b & (1 << i) != 0) 'Mouse button ${i + 1}',
      ].join(' + ');

  Widget _testerCard(ColorScheme cs) => _card(
        title: 'Button tester',
        subtitle: 'Point at the box, then click, scroll or press the mouse\'s buttons to see what the Mac receives.',
        child: Focus(
          focusNode: _testFocus,
          onKeyEvent: (node, e) {
            if (e is KeyDownEvent) {
              final hid = e.physicalKey.usbHidUsage;
              final k = HardwareKeyboard.instance;
              final mods = (k.isControlPressed ? 1 : 0) | (k.isShiftPressed ? 2 : 0) |
                  (k.isAltPressed ? 4 : 0) | (k.isMetaPressed ? 8 : 0);
              _test((hid >> 16) == 0x07
                  ? 'Key ${comboName(mods, hid & 0xFFFF)}'
                  : 'Key ${e.logicalKey.keyLabel}');
            }
            return KeyEventResult.handled;
          },
          child: MouseRegion(
            onEnter: (_) => _testFocus.requestFocus(),
            child: Listener(
              onPointerDown: (e) => _test(_buttonsName(e.buttons)),
              onPointerSignal: (e) {
                if (e is PointerScrollEvent) {
                  final now = DateTime.now();
                  if (now.difference(_lastScroll).inMilliseconds < 200) return;
                  _lastScroll = now;
                  _test(e.scrollDelta.dy < 0
                      ? 'Wheel up'
                      : e.scrollDelta.dy > 0
                          ? 'Wheel down'
                          : 'Wheel sideways');
                }
              },
              child: Container(
                height: 150,
                width: double.infinity,
                decoration: BoxDecoration(
                  color: cs.surfaceContainerHighest,
                  borderRadius: BorderRadius.circular(8),
                ),
                padding: const EdgeInsets.all(12),
                child: _tests.isEmpty
                    ? const Center(child: Text('Waiting for a click, scroll or key…'))
                    : ListView(
                        children: [
                          for (var i = 0; i < _tests.length; i++)
                            Text(_tests[i],
                                style: TextStyle(
                                  fontWeight: i == 0 ? FontWeight.w600 : FontWeight.normal,
                                  color: i == 0 ? null : cs.onSurfaceVariant,
                                )),
                        ],
                      ),
              ),
            ),
          ),
        ),
      );

  Widget _consoleCard(ColorScheme cs) => Card(
        margin: const EdgeInsets.only(bottom: 16),
        child: ExpansionTile(
          title: const Text('Developer console'),
          subtitle: Text('Raw 0xBA / 0xBB reports. Sent ${_status.tx}, received ${_status.rx}.'),
          childrenPadding: const EdgeInsets.fromLTRB(16, 0, 16, 16),
          children: [
            Row(
              children: [
                Expanded(
                  child: TextField(
                    controller: _tx,
                    style: const TextStyle(fontFamily: 'Menlo'),
                    decoration: const InputDecoration(
                      isDense: true,
                      border: OutlineInputBorder(),
                      hintText: 'ba a5 a3 …  (first byte = report ID)',
                    ),
                    onSubmitted: (_) => _send(),
                  ),
                ),
                const SizedBox(width: 8),
                FilledButton(onPressed: _status.connected && !_busy ? _send : null, child: const Text('Send')),
              ],
            ),
            const SizedBox(height: 12),
            Container(
              height: 240,
              decoration: BoxDecoration(
                color: cs.surfaceContainerHighest,
                borderRadius: BorderRadius.circular(8),
              ),
              padding: const EdgeInsets.all(8),
              child: _log.isEmpty
                  ? const Center(child: Text('No traffic yet'))
                  : ListView.builder(
                      itemCount: _log.length,
                      itemBuilder: (_, i) =>
                          Text(_log[i], style: const TextStyle(fontFamily: 'Menlo', fontSize: 12)),
                    ),
            ),
          ],
        ),
      );

  Future<void> _send() async {
    final bytes = _tx.text
        .trim()
        .split(RegExp(r'[\s,]+'))
        .where((s) => s.isNotEmpty)
        .map((s) => int.tryParse(s.replaceFirst('0x', ''), radix: 16))
        .whereType<int>()
        .toList();
    if (bytes.isEmpty) return;
    final r = await _hid.transact(bytes, pid: _pid);
    _addLog('tx  ${bytes.map((b) => b.toRadixString(16).padLeft(2, '0')).join(' ')}');
    _addLog('  → ${r == null ? 'no reply' : r.map((b) => b.toRadixString(16).padLeft(2, '0')).join(' ')}');
  }
}

/// Picks a new action for one button.
class _ActionPicker extends StatelessWidget {
  const _ActionPicker({required this.name, required this.current});

  final String name;
  final List<int> current;

  @override
  Widget build(BuildContext context) {
    final groups = <String>[];
    for (final a in presetActions) {
      if (!groups.contains(a.group)) groups.add(a.group);
    }
    final text = Theme.of(context).textTheme;
    bool same(List<int> a) => a[0] == current[0] && a[2] == current[2] && a[3] == current[3];
    return AlertDialog(
      title: Text(name),
      content: SizedBox(
        width: 380,
        height: 480,
        child: ListView(
          children: [
            Padding(
              padding: const EdgeInsets.only(bottom: 8),
              child: Text('Now: ${describeAction(current)}', style: text.bodySmall),
            ),
            ListTile(
              dense: true,
              leading: const Icon(Icons.keyboard_outlined),
              title: const Text('Key or shortcut…'),
              subtitle: const Text('Press it on the keyboard, e.g. ⌘C or Space'),
              onTap: () async {
                final a = await showDialog<List<int>>(context: context, builder: (_) => const _KeyCapture());
                if (a != null && context.mounted) Navigator.pop(context, a);
              },
            ),
            for (final g in groups) ...[
              Padding(
                padding: const EdgeInsets.only(top: 12, bottom: 4),
                child: Text(g, style: text.labelLarge),
              ),
              for (final a in presetActions.where((a) => a.group == g))
                ListTile(
                  dense: true,
                  title: Text(a.label),
                  selected: same(a.bytes),
                  trailing: same(a.bytes) ? const Icon(Icons.check) : null,
                  onTap: () => Navigator.pop(context, a.bytes),
                ),
            ],
          ],
        ),
      ),
      actions: [TextButton(onPressed: () => Navigator.pop(context), child: const Text('Cancel'))],
    );
  }
}

/// Records one key (with modifiers) as a button action: [0,0,usage,0] or [2,0,mods,usage].
class _KeyCapture extends StatefulWidget {
  const _KeyCapture();

  @override
  State<_KeyCapture> createState() => _KeyCaptureState();
}

class _KeyCaptureState extends State<_KeyCapture> {
  int? _usage;
  int _mods = 0;

  KeyEventResult _onKey(FocusNode node, KeyEvent e) {
    if (e is KeyDownEvent) {
      final hid = e.physicalKey.usbHidUsage;
      final u = hid & 0xFFFF;
      if ((hid >> 16) == 0x07 && (u < 0xE0 || u > 0xE7)) {
        final k = HardwareKeyboard.instance;
        setState(() {
          _usage = sendableUsage(u);
          _unsendable = _usage == null ? e.logicalKey.keyLabel : null;
          _mods = (k.isControlPressed ? 1 : 0) | (k.isShiftPressed ? 2 : 0) |
              (k.isAltPressed ? 4 : 0) | (k.isMetaPressed ? 8 : 0);
        });
      }
    }
    return KeyEventResult.handled;
  }

  String? _unsendable;

  @override
  Widget build(BuildContext context) {
    final cs = Theme.of(context).colorScheme;
    final u = _usage;
    return AlertDialog(
      title: const Text('Press a key or shortcut'),
      content: Focus(
        autofocus: true,
        onKeyEvent: _onKey,
        child: Container(
          width: 320,
          height: 110,
          alignment: Alignment.center,
          decoration: BoxDecoration(
            color: cs.surfaceContainerHighest,
            borderRadius: BorderRadius.circular(8),
          ),
          child: Text(
            _unsendable != null
                ? 'The mouse can\'t send ${_unsendable!.isEmpty ? 'that key' : _unsendable}'
                : u == null
                    ? 'Waiting…'
                    : comboName(_mods, u),
            textAlign: TextAlign.center,
            style: _unsendable != null
                ? Theme.of(context).textTheme.titleMedium
                : Theme.of(context).textTheme.headlineMedium,
          ),
        ),
      ),
      actions: [
        TextButton(onPressed: () => Navigator.pop(context), child: const Text('Cancel')),
        FilledButton(
          onPressed: u == null ? null : () => Navigator.pop(context, _mods == 0 ? [0, 0, u, 0] : [2, 0, _mods, u]),
          child: const Text('Use this'),
        ),
      ],
    );
  }
}
