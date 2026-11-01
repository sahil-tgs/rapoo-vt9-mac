# Rapoo VT9 (macOS)

A native Mac app for the Rapoo VT9 Pro, built from a teardown of Rapoo's Windows driver
(`../teardown/TEARDOWN.md`). It talks to the mouse over its 2.4 GHz receiver (or cable)
and stores every setting in the mouse itself, so they also apply on other computers.

## What it sets

- DPI: 7 stages, 50–26000, on/off per stage, the active stage.
- Polling rate (125–1000 Hz) and lift-off distance (1.0–2.0 mm).
- Motion Sync, angle snapping, ripple control, sensor angle, press and release debounce,
  sleep time.
- Every button: mouse buttons, DPI actions, media keys, any key or shortcut, disabled.
- Battery and firmware versions.
- LinearMouse gesture button: Back sends F15 and Forward F13; the app turns them into
  mouse buttons 6 and 7, which no app uses, so LinearMouse can use button 6.

The first time it sees the mouse it saves the settings it found to
`~/Library/Application Support/RapooVT9/backup-<pid>.json`. **Restore…** writes them back.

## Build and run

No Xcode needed:

```sh
./macos/manual/build_no_xcode.sh          # installs ~/Applications/Rapoo VT9.app
open -a ~/Applications/"Rapoo VT9.app"    # launch with open -a, not from a terminal
```

Permissions (asked on first use):

- **Input Monitoring**: the settings channel shares a USB interface with the mouse's
  keyboard functions. Only the settings messages are read.
- **Accessibility**: only for the LinearMouse gesture button (swallowing F15/F13 and
  posting mouse buttons 6/7).

The app keeps running when its window is closed; **Open at login** keeps the gesture
button working after a restart.

## Development

- `flutter test` drives the whole UI against an emulated mouse and checks each write.
- Developer console (a Unix socket for `../teardown/tools/rapoo_console.py`), off by default:
  `defaults write local.sahil.rapooVt9 devConsole -bool true`, then relaunch.
