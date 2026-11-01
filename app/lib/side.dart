import 'dart:async';

import 'package:flutter/services.dart';

/// State of SideKeyDriver (macos/Runner/MainFlutterWindow.swift), which turns the F15 / F13
/// keys sent by the side buttons into mouse buttons 6 / 7 for LinearMouse.
class SideStatus {
  const SideStatus({
    this.enabled = false,
    this.accessibility = false,
    this.tapActive = false,
    this.loginItem = 'off',
    this.error = '',
  });

  factory SideStatus.fromMap(Map<dynamic, dynamic> m) => SideStatus(
        enabled: m['enabled'] == true,
        accessibility: m['accessibility'] == true,
        tapActive: m['tapActive'] == true,
        loginItem: m['loginItem'] as String? ?? 'off',
        error: m['error'] as String? ?? '',
      );

  final bool enabled;
  final bool accessibility;
  final bool tapActive;
  final String loginItem;
  final String error;
}

class SideKeyChannel {
  SideKeyChannel() {
    _ch.setMethodCallHandler((call) async {
      if (call.method == 'status' && call.arguments is Map) {
        _status.add(SideStatus.fromMap(call.arguments as Map));
      }
      return null;
    });
  }

  static const MethodChannel _ch = MethodChannel('rapoo/side');
  final _status = StreamController<SideStatus>.broadcast();

  Stream<SideStatus> get statusChanges => _status.stream;

  Future<SideStatus> _call(String method, [Map<String, Object>? args]) async {
    try {
      return SideStatus.fromMap(await _ch.invokeMethod<Map<dynamic, dynamic>>(method, args) ?? const {});
    } on MissingPluginException {
      return const SideStatus();
    }
  }

  Future<SideStatus> status() => _call('status');
  Future<SideStatus> setEnabled(bool on) => _call('setEnabled', {'enabled': on});
  Future<SideStatus> requestAccessibility() => _call('requestAccessibility');
  Future<SideStatus> setLoginItem(bool on) => _call('setLoginItem', {'enabled': on});
}
