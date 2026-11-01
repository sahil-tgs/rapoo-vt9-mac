import 'dart:async';

import 'package:flutter/services.dart';

/// One vendor input report from the mouse: data[0] is the report ID (0xBA / 0xBB).
class RxFrame {
  RxFrame(this.pid, this.data) : at = DateTime.now();
  final int pid;
  final Uint8List data;
  final DateTime at;

  String get hex => data.map((b) => b.toRadixString(16).padLeft(2, '0')).join(' ');
}

class HidStatus {
  const HidStatus({
    this.inputMonitoring = 'unknown',
    this.open = false,
    this.devices = const <Map<String, dynamic>>[],
    this.rx = 0,
    this.tx = 0,
  });

  factory HidStatus.fromMap(Map<dynamic, dynamic> m) => HidStatus(
        inputMonitoring: m['inputMonitoring'] as String? ?? 'unknown',
        open: m['open'] == true,
        devices: ((m['devices'] as List<dynamic>?) ?? const <dynamic>[])
            .map((e) => Map<String, dynamic>.from(e as Map))
            .toList(),
        rx: (m['rx'] as num?)?.toInt() ?? 0,
        tx: (m['tx'] as num?)?.toInt() ?? 0,
      );

  final String inputMonitoring;
  final bool open;
  final List<Map<String, dynamic>> devices;
  final int rx;
  final int tx;

  bool get connected => open && devices.isNotEmpty;
}

/// Bridge to RapooHid in macos/Runner/MainFlutterWindow.swift (channel "rapoo/hid").
class RapooHidChannel {
  RapooHidChannel() {
    _ch.setMethodCallHandler((call) async {
      final a = call.arguments;
      if (call.method == 'rx' && a is Map) {
        _rx.add(RxFrame((a['pid'] as num?)?.toInt() ?? 0, a['data'] as Uint8List));
      } else if (call.method == 'status' && a is Map) {
        _status.add(HidStatus.fromMap(a));
      }
      return null;
    });
  }

  static const MethodChannel _ch = MethodChannel('rapoo/hid');
  final _rx = StreamController<RxFrame>.broadcast();
  final _status = StreamController<HidStatus>.broadcast();

  Stream<RxFrame> get rx => _rx.stream;
  Stream<HidStatus> get statusChanges => _status.stream;

  Future<HidStatus> status() async =>
      HidStatus.fromMap(await _ch.invokeMethod<Map<dynamic, dynamic>>('status') ?? const {});

  Future<HidStatus> requestInputMonitoring() async =>
      HidStatus.fromMap(await _ch.invokeMethod<Map<dynamic, dynamic>>('requestInputMonitoring') ?? const {});

  /// Sends one output report; frame[0] is the report ID. Returns the IOReturn code (0 = success).
  Future<int> write(List<int> frame) async =>
      await _ch.invokeMethod<int>('write', <String, Object>{'data': Uint8List.fromList(frame)}) ?? -1;

  /// Sends [frame] and polls the reply with GET_REPORT (see RapooHid.transact).
  /// The reply has no report ID: reply[0] is the status (1 = OK, 2 = error/busy).
  Future<Uint8List?> transact(List<int> frame, {int? pid}) => _ch.invokeMethod<Uint8List>(
      'transact', <String, Object>{'data': Uint8List.fromList(frame), 'pid': ?pid});
}
