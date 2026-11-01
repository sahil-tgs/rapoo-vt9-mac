// Rapoo VT9 Pro (VT950 platform) configuration protocol, reverse-engineered from
// RapooGameDev.exe 1.6.29 (FDeviceVT9PRO_Wireless). See teardown/TEARDOWN.md.
//
// Every exchange is one 0xBA output report answered by a 0xBA input report:
//   request  [0xBA, header, cmd, len, addr0, addr1, addr2, addr3, data...]
//   reply    [status, x, x, x, data...]   (macOS strips the report ID; status 1 = OK)
// header is 0xA5 through the 2.4 GHz receiver and 0xFF on the cable.
//
// Settings live in the mouse's flash and are read/written with A4/A5:
//   0x600  14 x 4-byte button actions (see keyOrder)
//   0x880  polling rate code (byte 0 wireless, byte 2 wired)
//   0x884  lift-off distance: byte 0 = step + 1 (1..11 = 1.0..2.0 mm)
//   0x888  DPI table: 7 x u16 LE (DPI / 50), enabled stages first, then [last enabled index, 0]
//   0x898  byte 0 = current DPI stage
//   0x8c0  system block: debounce down/up, sleep, linear/ripple bits, sensor angle, motion sync

import 'dart:async';
import 'dart:convert';
import 'dart:io';
import 'dart:typed_data';

import 'hid.dart';

const int kReceiverPid = 0x185A;
const int kWiredPid = 0x418A;

const int addrKeys = 0x600;
const int addrPoll = 0x880;
const int addrLod = 0x884;
const int addrDpi = 0x888;
const int addrStage = 0x898;
const int addrSys = 0x8C0;

/// Flash entry i (0x600 + 4*i) holds the action of UI key keyOrder[i].
const List<int> keyOrder = [0, 2, 1, 5, 6, 7, 8, 9, 10, 11, 12, 0x8E, 0x8F, 13];

/// The keys the official app shows for the VT9 Pro, in its order and with its names.
const List<(int, String)> vt9Keys = [
  (0, 'Left button'),
  (1, 'Right button'),
  (2, 'Wheel click'),
  (7, 'Forward'),
  (8, 'Back'),
  (5, 'DPI +'),
  (6, 'DPI −'),
  (11, 'Wheel up'),
  (12, 'Wheel down'),
  (13, 'Bottom button'),
];

const List<int> pollRates = [125, 250, 500, 1000];
const Map<int, int> pollCode = {125: 8, 250: 4, 500: 2, 1000: 1};

/// Debounce choices in ms; the firmware stores the ms value itself.
const List<int> debounceMs = [1, 2, 4, 8, 16, 24, 32];

class Battery {
  const Battery(this.percent, this.charging);
  final int percent;
  final bool charging;
}

/// The 8-byte block at 0x8c0. `valid` is false while the mouse still has its factory
/// (unwritten) block; the official app then shows its defaults, and so do we.
class SysBlock {
  SysBlock({
    this.down = 8,
    this.up = 8,
    this.sleepMin = 30,
    this.linear = false,
    this.ripple = false,
    this.angle = 0,
    this.motionSync = true,
    this.valid = false,
  });

  factory SysBlock.parse(List<int> b) {
    if (b.length < 6 || !debounceMs.contains(b[0]) || !debounceMs.contains(b[1])) return SysBlock();
    return SysBlock(
      down: b[0],
      up: b[1],
      sleepMin: b[2],
      linear: (b[3] & 1) == 0,
      ripple: (b[3] & 2) == 0,
      angle: b[4] >= 0x80 ? b[4] - 0x100 : b[4],
      motionSync: b[5] != 0,
      valid: true,
    );
  }

  int down, up, sleepMin, angle;
  bool linear, ripple, motionSync, valid;

  List<int> encode() => [
        down,
        up,
        sleepMin.clamp(1, 255),
        (linear ? 0 : 1) | (ripple ? 0 : 2),
        angle & 0xFF,
        motionSync ? 1 : 0,
        0,
        0,
      ];

  SysBlock copy() => SysBlock(
      down: down, up: up, sleepMin: sleepMin, linear: linear, ripple: ripple,
      angle: angle, motionSync: motionSync, valid: valid);
}

class DpiStage {
  DpiStage(this.dpi, this.enabled);
  int dpi;
  bool enabled;
}

class MouseState {
  MouseState({
    required this.pid,
    required this.firmware,
    required this.receiver,
    required this.battery,
    required this.raw,
  });

  final int pid;
  final int? firmware;
  final int? receiver;
  Battery? battery;

  /// Raw flash blocks by address, as read from the mouse (also the backup format).
  final Map<int, List<int>> raw;

  bool get wired => pid == kWiredPid;

  List<DpiStage> get stages {
    final t = raw[addrDpi]!;
    final last = t[14].clamp(0, 6);
    return List.generate(7, (i) => DpiStage((t[2 * i] | (t[2 * i + 1] << 8)) * 50, i <= last));
  }

  int get stage => raw[addrStage]![0];

  int? get pollHz {
    final code = raw[addrPoll]![wired ? 2 : 0];
    for (final e in pollCode.entries) {
      if (e.value == code) return e.key;
    }
    return null;
  }

  /// Lift-off distance step 0..10 (1.0..2.0 mm).
  int get lodStep => (raw[addrLod]![0] - 1).clamp(0, 10);

  SysBlock get sys => SysBlock.parse(raw[addrSys]!);

  List<int> keyAction(int key) {
    final i = keyOrder.indexOf(key);
    return raw[addrKeys]!.sublist(4 * i, 4 * i + 4);
  }
}

class Vt9Exception implements Exception {
  Vt9Exception(this.message);
  final String message;
  @override
  String toString() => message;
}

/// One VT9 Pro behind the HID channel. All operations are serialised.
class Vt9 {
  Vt9(this.hid);

  final RapooHidChannel hid;
  int pid = kReceiverPid;
  Future<void> _tail = Future.value();

  int get header => pid == kWiredPid ? 0xFF : 0xA5;

  Future<T> _locked<T>(Future<T> Function() op) {
    final done = Completer<T>();
    _tail = _tail.then((_) async {
      try {
        done.complete(await op());
      } catch (e, st) {
        done.completeError(e, st);
      }
    });
    return done.future;
  }

  /// Sends one request; retries while the mouse answers "busy" (status 2 after waking up).
  Future<Uint8List> _xfer(List<int> payload) async {
    for (var attempt = 0; attempt < 4; attempt++) {
      final r = await hid.transact([0xBA, ...payload], pid: pid);
      if (r != null && r.isNotEmpty && r[0] == 1) return r;
      await Future<void>.delayed(const Duration(milliseconds: 150));
    }
    throw Vt9Exception('No answer from the mouse (is it awake?)');
  }

  List<int> _addr(int a) => [a & 0xFF, (a >> 8) & 0xFF, (a >> 16) & 0xFF, (a >> 24) & 0xFF];

  Future<List<int>> _read(int addr, int len) async {
    final out = <int>[];
    while (out.length < len) {
      final n = (len - out.length).clamp(1, 0x18);
      final r = await _xfer([header, 0xA4, n, ..._addr(addr + out.length)]);
      out.addAll(r.sublist(4, 4 + n));
    }
    return out;
  }

  Future<void> _write(int addr, List<int> data) async {
    await _xfer([header, 0xA5, data.length, ..._addr(addr), ...data]);
    final back = await _read(addr, data.length);
    for (var i = 0; i < data.length; i++) {
      if (back[i] != data[i]) {
        throw Vt9Exception('Write to 0x${addr.toRadixString(16)} did not stick');
      }
    }
  }

  Future<void> handshake() => _locked(() async {
        await _xfer([header, 0xAB, pid >= 0x1800 ? 0xB2 : 0xB1]);
      });

  Future<Battery?> battery() => _locked(() async {
        final r = await _xfer([header, 0xAA]);
        return Battery(r[2].clamp(0, 100), r[1] == 2);
      });

  /// Reads everything the UI needs. Throws if the mouse does not answer.
  Future<MouseState> readAll() => _locked(() async {
        int? fw, rx;
        Battery? bat;
        try {
          final v = await _xfer([header, 0xA3]);
          fw = v[2] * 100 + v[1];
        } on Vt9Exception {
          fw = null;
        }
        if (pid != kWiredPid) {
          try {
            final v = await _xfer([0xB0]);
            rx = v[1];
          } on Vt9Exception {
            rx = null;
          }
        }
        try {
          final b = await _xfer([header, 0xAA]);
          bat = Battery(b[2].clamp(0, 100), b[1] == 2);
        } on Vt9Exception {
          bat = null;
        }
        final raw = <int, List<int>>{
          addrKeys: await _read(addrKeys, 56),
          addrPoll: await _read(addrPoll, 4),
          addrLod: await _read(addrLod, 4),
          addrDpi: await _read(addrDpi, 16),
          addrStage: await _read(addrStage, 4),
          addrSys: await _read(addrSys, 8),
        };
        return MouseState(pid: pid, firmware: fw, receiver: rx, battery: bat, raw: raw);
      });

  // ---- setters: each one is a read-modify-write of one flash block, verified by read-back.

  /// The DPI table the way the official app writes it: enabled stages first.
  static List<int> encodeStages(List<DpiStage> stages) {
    final on = stages.where((e) => e.enabled).toList();
    final off = stages.where((e) => !e.enabled).toList();
    final t = <int>[];
    for (final e in [...on, ...off]) {
      final v = (e.dpi ~/ 50).clamp(1, 520);
      t..add(v & 0xFF)..add(v >> 8);
    }
    return t..add(on.length - 1)..add(0);
  }

  /// Writes the table if it changed, then the active stage: [active] when given,
  /// otherwise the mouse's own current stage, clamped to the enabled ones.
  Future<void> setDpi(MouseState s, List<DpiStage> stages, int? active) => _locked(() async {
        final enabled = stages.where((e) => e.enabled).length;
        if (enabled == 0) throw Vt9Exception('At least one DPI stage must stay on');
        final t = encodeStages(stages);
        if (!_same(t, s.raw[addrDpi]!)) {
          await _write(addrDpi, t);
          s.raw[addrDpi] = t;
        }
        final cur = await _read(addrStage, 4);
        final want = (active ?? cur[0]).clamp(0, enabled - 1);
        if (cur[0] != want) {
          cur[0] = want;
          await _write(addrStage, cur);
        }
        s.raw[addrStage] = cur;
      });

  Future<void> setPolling(MouseState s, int hz) => _locked(() async {
        final b = await _read(addrPoll, 4);
        b[0] = pollCode[hz]!;
        if (s.wired) b[2] = pollCode[hz]!;
        await _write(addrPoll, b);
        s.raw[addrPoll] = b;
      });

  Future<void> setLod(MouseState s, int step) => _locked(() async {
        final b = await _read(addrLod, 4);
        b[0] = step.clamp(0, 10) + 1;
        // Same repair the official app makes when the rest of the block is blank.
        if (b[2] == 0 && b[3] == 0 && (b[1] == 0 || b[1] == 1)) {
          b[1] = 1;
          b[3] = 3;
        }
        await _write(addrLod, b);
        s.raw[addrLod] = b;
      });

  Future<void> setSys(MouseState s, SysBlock sys) => _locked(() async {
        final b = sys.encode();
        await _write(addrSys, b);
        s.raw[addrSys] = b;
      });

  Future<void> setKey(MouseState s, int key, List<int> action) => _locked(() async {
        final i = keyOrder.indexOf(key);
        await _write(addrKeys + 4 * i, action);
        s.raw[addrKeys]!.setRange(4 * i, 4 * i + 4, action);
      });

  /// Writes every block of a backup back to the mouse.
  Future<void> restore(MouseState s, Map<int, List<int>> raw) => _locked(() async {
        final keys = raw[addrKeys]!;
        for (var i = 0; i < keys.length ~/ 4; i++) {
          final a = keys.sublist(4 * i, 4 * i + 4);
          if (!_same(a, s.raw[addrKeys]!.sublist(4 * i, 4 * i + 4))) await _write(addrKeys + 4 * i, a);
        }
        for (final addr in [addrPoll, addrLod, addrDpi, addrStage, addrSys]) {
          if (!_same(raw[addr]!, s.raw[addr]!)) await _write(addr, raw[addr]!);
        }
        for (final e in raw.entries) {
          s.raw[e.key] = List.of(e.value);
        }
      });

  static bool _same(List<int> a, List<int> b) {
    if (a.length != b.length) return false;
    for (var i = 0; i < a.length; i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
}

// ---- backups: the first full read of each mouse is kept so every change can be undone.

String? _supportDirOverride;

/// Tests point backups at a temporary folder.
set supportDirOverride(String? path) => _supportDirOverride = path;

String get supportDir =>
    _supportDirOverride ?? '${Platform.environment['HOME']}/Library/Application Support/RapooVT9';

File backupFile(int pid) => File('$supportDir/backup-${pid.toRadixString(16)}.json');

Future<void> saveBackupOnce(MouseState s) async {
  final f = backupFile(s.pid);
  if (await f.exists()) return;
  await Directory(supportDir).create(recursive: true);
  await f.writeAsString(const JsonEncoder.withIndent(' ').convert({
    'savedAt': DateTime.now().toIso8601String(),
    'pid': s.pid,
    'firmware': s.firmware,
    'blocks': {for (final e in s.raw.entries) '0x${e.key.toRadixString(16)}': e.value},
  }));
}

Future<Map<int, List<int>>?> loadBackup(int pid) async {
  final f = backupFile(pid);
  if (!await f.exists()) return null;
  final j = jsonDecode(await f.readAsString()) as Map<String, dynamic>;
  final blocks = j['blocks'] as Map<String, dynamic>;
  return {
    for (final e in blocks.entries)
      int.parse(e.key.substring(2), radix: 16): (e.value as List).cast<int>(),
  };
}

// ---- button actions: [type, flag, b2, b3] as the firmware stores them.

class KeyAction {
  const KeyAction(this.label, this.bytes, {this.group = 'Mouse'});
  final String label;
  final List<int> bytes;
  final String group;
}

/// The mouse's keyboard collection only reaches usage 0x65, so it cannot send F13-F15
/// directly. It sends Print Screen / Scroll Lock / Pause instead, which macOS reads as
/// F13 / F14 / F15.
const List<int> keyF13 = [0, 0, 0x46, 0];
const List<int> keyF14 = [0, 0, 0x47, 0];
const List<int> keyF15 = [0, 0, 0x48, 0];

/// Highest keyboard usage the mouse can send (its descriptor's logical maximum).
const int maxKeyUsage = 0x65;

/// Maps a captured Mac key to one the mouse can send, or null if it cannot.
int? sendableUsage(int usage) => switch (usage) {
      0x68 => 0x46, // F13
      0x69 => 0x47, // F14
      0x6A => 0x48, // F15
      _ => usage <= maxKeyUsage ? usage : null,
    };

const List<KeyAction> presetActions = [
  KeyAction('Left click', [3, 0, 0x01, 0]),
  KeyAction('Right click', [3, 0, 0x02, 0]),
  KeyAction('Middle click', [3, 0, 0x04, 0]),
  KeyAction('Back (button 4)', [3, 0, 0x08, 0]),
  KeyAction('Forward (button 5)', [3, 0, 0x10, 0]),
  KeyAction('Fire (rapid left click)', [3, 0, 0x01, 1]),
  KeyAction('DPI cycle', [8, 0, 3, 0], group: 'DPI'),
  KeyAction('DPI +', [8, 0, 5, 0], group: 'DPI'),
  KeyAction('DPI −', [8, 0, 6, 0], group: 'DPI'),
  KeyAction('Sniper (hold for low DPI)', [9, 0, 1, 0], group: 'DPI'),
  KeyAction('Play / pause', [4, 0, 0x00, 0xCD], group: 'Media'),
  KeyAction('Next track', [4, 0, 0x00, 0xB5], group: 'Media'),
  KeyAction('Previous track', [4, 0, 0x00, 0xB6], group: 'Media'),
  KeyAction('Volume up', [4, 0, 0x00, 0xE9], group: 'Media'),
  KeyAction('Volume down', [4, 0, 0x00, 0xEA], group: 'Media'),
  KeyAction('Mute', [4, 0, 0x00, 0xE2], group: 'Media'),
  KeyAction('F13', keyF13, group: 'Keys nothing uses (for LinearMouse and similar)'),
  KeyAction('F14', keyF14, group: 'Keys nothing uses (for LinearMouse and similar)'),
  KeyAction('F15', keyF15, group: 'Keys nothing uses (for LinearMouse and similar)'),
  KeyAction('Wheel default (scroll)', [0xFF, 0xFF, 0xFF, 0xFF], group: 'Other'),
  KeyAction('Disabled', [0, 0, 0, 0], group: 'Other'),
];

const Map<int, String> _media = {
  0xCD: 'Play / pause', 0xB5: 'Next track', 0xB6: 'Previous track', 0xB7: 'Stop',
  0xE9: 'Volume up', 0xEA: 'Volume down', 0xE2: 'Mute', 0x183: 'Media player',
};

String describeAction(List<int> a) {
  if (a.every((b) => b == 0xFF)) return 'Default';
  for (final p in presetActions) {
    if (p.bytes[0] == a[0] && p.bytes[2] == a[2] && p.bytes[3] == a[3] && a[0] != 0xFF) return p.label;
  }
  switch (a[0]) {
    case 0:
      return a[2] == 0 ? 'Disabled' : 'Key ${hidKeyName(a[2])}';
    case 2:
      return 'Keys ${comboName(a[2], a[3])}';
    case 3:
      return 'Mouse button 0x${a[2].toRadixString(16)}';
    case 4:
      return _media[(a[2] << 8) | a[3]] ?? 'Media 0x${((a[2] << 8) | a[3]).toRadixString(16)}';
    case 5:
      return 'Macro ${a[2]}';
    case 9:
      if (a[2] == 3) return 'Macro switch';
  }
  return 'Custom (${a.map((b) => b.toRadixString(16).padLeft(2, '0')).join(' ')})';
}

String comboName(int mods, int usage) {
  final parts = <String>[
    if (mods & 0x11 != 0) '⌃',
    if (mods & 0x44 != 0) '⌥',
    if (mods & 0x22 != 0) '⇧',
    if (mods & 0x88 != 0) '⌘',
  ];
  return '${parts.join()}${hidKeyName(usage)}';
}

String hidKeyName(int u) {
  if (u >= 0x04 && u <= 0x1D) return String.fromCharCode(0x41 + u - 0x04);
  if (u >= 0x1E && u <= 0x26) return '${u - 0x1D}';
  if (u == 0x27) return '0';
  if (u >= 0x3A && u <= 0x45) return 'F${u - 0x39}';
  if (u >= 0x68 && u <= 0x73) return 'F${u - 0x5B}';
  return _hidNames[u] ?? '0x${u.toRadixString(16)}';
}

const Map<int, String> _hidNames = {
  0x28: 'Return', 0x29: 'Esc', 0x2A: 'Delete', 0x2B: 'Tab', 0x2C: 'Space', 0x2D: '-', 0x2E: '=',
  0x2F: '[', 0x30: ']', 0x31: '\\', 0x33: ';', 0x34: "'", 0x35: '`', 0x36: ',', 0x37: '.',
  0x38: '/', 0x39: 'Caps Lock', 0x46: 'F13', 0x47: 'F14', 0x48: 'F15', // as macOS reads them
  0x49: 'Insert', 0x4A: 'Home', 0x4B: 'Page Up', 0x4C: 'Forward Delete', 0x4D: 'End',
  0x4E: 'Page Down', 0x4F: '→', 0x50: '←', 0x51: '↓', 0x52: '↑',
};
