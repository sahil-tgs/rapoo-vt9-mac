// Drives the real UI against an emulated VT9 Pro whose flash starts as a copy of the
// mouse this app was built against (read on 1 Nov 2026), and checks every write byte for byte.

import 'dart:io';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:rapoo_vt9/main.dart';
import 'package:rapoo_vt9/vt9.dart';

const Map<int, List<int>> original = {
  0x600: [
    0x03, 0x00, 0x01, 0x00, 0x03, 0x00, 0x04, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x4f, 0x00, //
    0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x07, 0x00, 0x08, 0x00,
    0x07, 0x00, 0x08, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x08, 0x00, 0x03, 0x00,
  ],
  0x880: [0x01, 0x82, 0x01, 0xff],
  0x884: [0x01, 0x01, 0x00, 0x03],
  0x888: [0x20, 0x00, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x02, 0x00, 0x00],
  0x898: [0x00, 0x00, 0x02, 0x01],
  0x8c0: [0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff],
};

class FakeMouse {
  FakeMouse() {
    for (final e in original.entries) {
      for (var i = 0; i < e.value.length; i++) {
        mem[e.key + i] = e.value[i];
      }
    }
  }

  final Map<int, int> mem = {};
  final List<String> log = [];
  bool sideEnabled = false;

  List<int> at(int addr, int n) => [for (var i = 0; i < n; i++) mem[addr + i] ?? 0xff];

  Uint8List reply(Uint8List f) {
    final out = Uint8List(32)..[0] = 1;
    if (f[1] == 0xB0) return out..[1] = 9;
    expect(f[1], 0xA5, reason: 'receiver header');
    final addr = f.length >= 8 ? f[4] | f[5] << 8 | f[6] << 16 | f[7] << 24 : 0;
    switch (f[2]) {
      case 0xA3:
        out..[1] = 0x14..[2] = 0x02;
      case 0xAA:
        out..[1] = 1..[2] = 26;
      case 0xA4:
        for (var i = 0; i < f[3]; i++) {
          out[4 + i] = mem[addr + i] ?? 0xff;
        }
      case 0xA5:
        log.add('write 0x${addr.toRadixString(16)} ${f.sublist(8, 8 + f[3])}');
        for (var i = 0; i < f[3]; i++) {
          mem[addr + i] = f[8 + i];
        }
    }
    return out;
  }
}

Future<void> settle(WidgetTester tester) async {
  for (var i = 0; i < 25; i++) {
    await tester.runAsync(() => Future<void>.delayed(const Duration(milliseconds: 5)));
    await tester.pump(const Duration(milliseconds: 60));
  }
}

Finder inCard(String cardTitle, Finder f) => find.descendant(
      of: find.ancestor(of: find.text(cardTitle).first, matching: find.byType(Card)).first,
      matching: f,
    );

Finder applyIn(String cardTitle) => inCard(cardTitle, find.widgetWithText(FilledButton, 'Apply'));

FakeMouse connectFake(WidgetTester tester, double width) {
  tester.view.physicalSize = Size(width, 4200);
  tester.view.devicePixelRatio = 1.0;
  addTearDown(tester.view.reset);
  supportDirOverride = Directory.systemTemp.createTempSync('rapoo_test').path;
  final mouse = FakeMouse();
  TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger
      .setMockMethodCallHandler(const MethodChannel('rapoo/hid'), (call) async {
    switch (call.method) {
      case 'status':
        return {
          'inputMonitoring': 'granted',
          'open': true,
          'devices': [
            {'pid': kReceiverPid, 'product': 'Rapoo Gaming Device'},
          ],
          'rx': 0,
          'tx': 0,
        };
      case 'transact':
        return mouse.reply((call.arguments as Map)['data'] as Uint8List);
    }
    return null;
  });
  TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger
      .setMockMethodCallHandler(const MethodChannel('rapoo/side'), (call) async {
    if (call.method == 'setEnabled') mouse.sideEnabled = (call.arguments as Map)['enabled'] as bool;
    return {
      'enabled': mouse.sideEnabled,
      'accessibility': true,
      'tapActive': mouse.sideEnabled,
      'loginItem': 'off',
      'error': '',
    };
  });
  return mouse;
}

void main() {
  testWidgets('lays out at the narrowest window size', (tester) async {
    connectFake(tester, 760);
    await tester.pumpWidget(const RapooApp());
    await settle(tester);
    expect(find.text('Sensor and buttons'), findsOneWidget);
    expect(tester.takeException(), isNull);
    await tester.pumpWidget(const SizedBox());
    await tester.pump(const Duration(seconds: 10));
  });

  testWidgets('reads the mouse, applies every card and restores the backup', (tester) async {
    final mouse = connectFake(tester, 1000);
    await tester.pumpWidget(const RapooApp());
    await settle(tester);

    for (final t in ['DPI stages', 'Performance', 'Sensor and buttons', 'Buttons', 'Button tester']) {
      expect(find.text(t), findsWidgets, reason: t);
    }
    expect(find.text('firmware 220'), findsNothing); // part of a joined subtitle
    expect(find.textContaining('firmware 220'), findsOneWidget);
    expect(find.text('26%'), findsOneWidget);
    expect(find.text('Key →'), findsOneWidget); // DPI + key holds Right Arrow on this mouse
    expect(find.text('DPI cycle'), findsOneWidget); // bottom button
    expect(mouse.log, isEmpty, reason: 'reading must not write');
    expect(File('$supportDir/backup-185a.json').existsSync(), isTrue);

    // Polling rate 1000 -> 500 Hz: only byte 0 of 0x880 changes.
    await tester.tap(find.text('500 Hz'));
    await tester.pump();
    await tester.tap(applyIn('Performance'));
    await settle(tester);
    expect(mouse.at(0x880, 4), [0x02, 0x82, 0x01, 0xff]);

    // Lift-off 1.0 -> 2.0 mm (drag the slider to the far right): 0x884 byte 0 = 11.
    final lod = find.descendant(
        of: find.ancestor(of: find.text('Performance').first, matching: find.byType(Card)).first,
        matching: find.byType(Slider));
    await tester.drag(lod, const Offset(600, 0));
    await tester.pump();
    await tester.tap(applyIn('Performance'));
    await settle(tester);
    expect(mouse.at(0x884, 4), [11, 0x01, 0x00, 0x03]);

    // System block: defaults plus Motion Sync off -> 8 8 30 03 00 00 00 00.
    await tester.tap(find.text('Motion Sync'));
    await tester.pump();
    await tester.tap(applyIn('Sensor and buttons'));
    await settle(tester);
    expect(mouse.at(0x8c0, 8), [8, 8, 30, 3, 0, 0, 0, 0]);

    // Switch the second DPI stage (400) on: table keeps order, last-enabled index becomes 1.
    await tester.tap(inCard('DPI stages', find.byType(Switch)).at(1));
    await tester.pump();
    await tester.tap(applyIn('DPI stages'));
    await settle(tester);
    expect(mouse.at(0x888, 16),
        [0x20, 0x00, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x02, 0x01, 0x00]);
    expect(mouse.at(0x898, 4), [0x00, 0x00, 0x02, 0x01], reason: 'stage untouched');

    // Make 400 the active stage: 0x898 byte 0 = 1.
    await tester.tap(inCard('DPI stages', find.byIcon(Icons.radio_button_unchecked)).first);
    await tester.pump();
    await tester.tap(applyIn('DPI stages'));
    await settle(tester);
    expect(mouse.at(0x898, 4), [0x01, 0x00, 0x02, 0x01]);

    // Forward button -> "Forward (button 5)": entry 5 (0x614) = 03 00 10 00.
    await tester.tap(find.text('Forward'));
    await settle(tester);
    await tester.tap(find.text('Forward (button 5)'));
    await settle(tester);
    expect(mouse.at(0x614, 4), [0x03, 0x00, 0x10, 0x00]);

    // Back button -> keyboard shortcut ⌘[ : entry 6 (0x618) = 02 00 08 2f.
    await tester.tap(find.text('Back'));
    await settle(tester);
    await tester.tap(find.text('Key or shortcut…'));
    await settle(tester);
    await tester.sendKeyDownEvent(LogicalKeyboardKey.metaLeft);
    await tester.sendKeyDownEvent(LogicalKeyboardKey.bracketLeft);
    await tester.sendKeyUpEvent(LogicalKeyboardKey.bracketLeft);
    await tester.sendKeyUpEvent(LogicalKeyboardKey.metaLeft);
    await tester.pump();
    expect(find.text('⌘['), findsOneWidget);
    await tester.tap(find.text('Use this'));
    await settle(tester);
    expect(mouse.at(0x618, 4), [0x02, 0x00, 0x08, 0x2f]);
    expect(find.text('Keys ⌘['), findsOneWidget);

    // LinearMouse setup: Back -> F15 (sent as Pause, 0x48), Forward -> F13 (Print Screen, 0x46),
    // and the key -> mouse button 6/7 conversion switched on.
    await tester.tap(find.text('Set them'));
    await settle(tester);
    expect(mouse.at(0x618, 4), [0x00, 0x00, 0x48, 0x00]);
    expect(mouse.at(0x614, 4), [0x00, 0x00, 0x46, 0x00]);
    expect(mouse.sideEnabled, isTrue);
    expect(find.text('Set them'), findsNothing);
    expect(find.text('F15'), findsOneWidget);
    expect(find.text('F13'), findsOneWidget);

    // Restore everything from the backup taken at connect time.
    await tester.tap(find.text('Restore…'));
    await settle(tester);
    await tester.tap(find.widgetWithText(FilledButton, 'Restore'));
    await settle(tester);
    for (final e in original.entries) {
      expect(mouse.at(e.key, e.value.length), e.value, reason: 'restored 0x${e.key.toRadixString(16)}');
    }

    expect(tester.takeException(), isNull);
    await tester.pumpWidget(const SizedBox());
    await tester.pump(const Duration(seconds: 10));
  });
}
