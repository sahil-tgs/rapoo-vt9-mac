# Rapoo VT9 Pro teardown

Everything known about the Rapoo VT9 Pro (VT950 platform, Nordic nRF52833) and its
official Windows driver, how it was found, and how the Mac app uses it.

- 2.4 GHz receiver: USB `24AE:185A`, driver class `FDeviceVT9PRO_Wireless`, header byte `0xA5`.
- Cable: USB `24AE:418A`, class `FDeviceVT9PRO`, header byte `0xFF` (not tested here).
- Bluetooth carries no settings channel.

Dates: teardown and app built on 1 Nov 2026, 18:17–19:35 IST, with REA 6.4.0 driving
Ghidra 12.1.4, plus radare2 for raw disassembly.

## Sources taken apart

| Artifact | What it is | Tool |
|---|---|---|
| `RapooGameDevDriver_Setup_1.6.29_20251011.exe` | NSIS installer with 64-bit block lengths and 9-int script entries; 7-Zip and The Unarchiver both refuse it | `tools/nsis64_extract.py` → `bin/app3/` (913 files) |
| `RapooGameDev.exe` | The driver: 32-bit Qt 5 / QML app, 55 MB, unoptimised MSVC build (easy to read) | REA MCP session (`tools/rea_daemon.py`, first analysis 424 s), radare2 |
| 204 JSON device configs | Embedded zlib streams: per-model defaults and UI specs | `bin/qml/` |
| QML UI | Precompiled (264 `qv4cdata` units); identifiers and literals survive as UTF-16 | `strings`-style UTF-16 scan |
| Firmware | `VT950S_nRF52833_MS5_S113.bin` (Nordic DFU) and others | `bin/fw/` |
| The mouse | Vendor reports 0xBA / 0xBB through the app's dev console | `tools/rapoo_console.py` |

## How the protocol was found

1. RTTI names gave the device class and its 91-slot vtable (`tools/class_vtable.py`).
   Each slot is one device operation; decompiling them gave the command bytes and the
   flash address each one reads or writes (`rea/main/vt9pro_wireless_methods.c`).
2. To name the slots, follow the UI instead. Every settings page is a QML model
   (`KDpiModel`, `KReportModel`, `FDeviceSysModel`, `KKeyModel`, ...). Its moc
   `qt_static_metacall` leads to the Q_INVOKABLE writer, and the writer calls a
   `std::function` bound to `&KDevice::virtualX`. MSVC compiles that member pointer to
   a thunk `mov eax,[ecx]; jmp [eax+offset]`, so the offset is the slot.
   `tools/slot_users.py <exe> <offset>...` finds every model that binds a slot.
3. Value meanings came from the QML string tables (choices such as "1ms…32ms",
   "(min)", "-30…30") and from the readers, which decode the same bytes.
4. Which features this model has comes from `KImageModel::slot_onVerisonupdateFunc`
   (0x1030470): PID lists plus firmware-version thresholds (below).

## Transport

- Interface: the one with vendor collections on usage page `0xFF00`. It also carries a
  keyboard, a consumer-control and a system-control collection, which is why macOS
  asks for Input Monitoring before it can be opened.
- Request: output report `0xBA`, 31 data bytes: `[header, cmd, len, addr LE32, data...]`.
- Reply: polled with GET_REPORT (input `0xBA`). macOS strips the report ID, so `reply[0]`
  is the status (1 = OK, 0 = busy, 2 = error) and read data starts at `reply[4]`.
- Send, wait 50 ms, poll up to 3 times; the driver retries the whole exchange 3 times.
- The first command after the mouse wakes often returns status 2; resending works.
- The driver sends `AB B2` (`B1` for PIDs below 0x1800) on connect. Before it, A5 writes
  were refused once.
- Report `0xBB` (6 data bytes) carries unprompted messages. Seen so far:
  `B0 42 40 06 <state> <percent>`, a battery report.

| Cmd | Request | Reply / meaning |
|---|---|---|
| `A3` | `A5 A3` | firmware = `reply[2]*100 + reply[1]` (this mouse: 220) |
| `B0` | `B0` (no header) | receiver firmware `reply[1]` (this receiver: 9) |
| `AA` | `A5 AA` | `reply[1]`: 1 discharging, 2 charging; `reply[2]`: percent |
| `AB` | `A5 AB B2` | handshake |
| `A4` | `A5 A4 len addr` | read flash, up to 0x18 bytes |
| `A5` | `A5 A5 len addr data` | write flash; the driver uses 4, 8 or 16 bytes |
| `AD` | 0x52 bytes | macros (not implemented) |

## Flash map

| Address | Bytes | Meaning | Written by (slot) |
|---|---|---|---|
| `0x600` | 14 × 4 | Button actions, entry *i* = UI key `[0,2,1,5,6,7,8,9,10,11,12,0x8E,0x8F,13][i]` | `KKeyModel` (51) |
| `0x880` | 4 | Polling code: byte 0 wireless, byte 2 cable, byte 1 4K receiver. 8/4/2/1 = 125/250/500/1000 Hz; `0x84/0x82/0x81` = 2/4/8 kHz | `KReportModel` (45) |
| `0x884` | 4 | Lift-off: byte 0 = step + 1 (1–11 = 1.0–2.0 mm). Bytes 1–3 default `01 00 03` | `KReportModel` (54) |
| `0x888` | 16 | DPI: 7 × u16 LE (DPI ÷ 50), enabled stages first, then `[last enabled index, 0]` | `KDpiModel` (44) |
| `0x898` | 4 | Byte 0: active DPI stage. Bytes 1–3: LED mode / speed / brightness (models with lights) | `KDpiModel` (43), `KLightModelItem` (46–48) |
| `0x8C0` | 8 | System block, see below | `FDeviceSysModel` (70) |
| `0x8C8` | 16 | Y-axis DPI table when X/Y DPI is on | `KDpiModel` (72) |
| `0x89C`, `0x8AC` | 4 | OLED settings, power-saving flag (other models) | `FOledModel`, `FBattreyModel` |

System block at `0x8C0` (reader slot 39, writer slot 70):

| Byte | Setting | Encoding |
|---|---|---|
| 0 | Button press debounce | ms value: 1, 2, 4, 8, 16, 24 or 32 |
| 1 | Button release debounce | same |
| 2 | Sleep time | minutes |
| 3 | Angle snapping ("linear correction"), ripple control | bit 0 clear = angle snapping on, bit 1 clear = ripple on |
| 4 | Sensor angle | signed, −30…+30 |
| 5 | Motion Sync | 0 / 1 |
| 6–7 | unused | 0 |

If byte 0 or 1 is not a valid debounce value, the driver ignores the block and shows its
JSON defaults (8 ms, 8 ms, 30 min, both corrections off, 0°, Motion Sync on). This mouse
still had the factory block `00 FF FF 00 FF FF FF FF`.

## Button actions

Four bytes `[type, flag, b2, b3]` (encoder `FUN_011817e0`, decoder `FUN_010e3880`):

| Type | Action | Bytes |
|---|---|---|
| 3 | Mouse button | `b2` mask: 01 left, 02 right, 04 middle, 08 back, 10 forward; `b3 = 1` = rapid fire |
| 0 | Single key | `b2` = HID keyboard usage (`00 00 00 00` = disabled) |
| 2 | Key combination | `b2` = modifier mask (01 Ctrl, 02 Shift, 04 Alt/Option, 08 GUI/Command), `b3` = usage |
| 4 | Media | consumer usage `b2:b3`, e.g. `00 CD` play/pause, `00 E9` volume up |
| 5 | Macro | `b2` = macro number |
| 8 | DPI | `b2`: 3 cycle, 5 up, 6 down |
| 9 | Special | `b2`: 1 sniper, 3 macro switch |
| FF | Default | `FF FF FF FF` (wheel keys scroll) |

## Features by firmware

The VT9 Pro's PIDs are in the gate list `0x37C1D40` and the family list `0x37C1D60`:

| Firmware | Enabled |
|---|---|
| > 224 | Everything, including separate X/Y DPI |
| 220–224 | Debounce, sleep, sensor angle, Motion Sync, angle snapping, ripple, 11-step lift-off; no X/Y DPI |
| 213–219 | 11-step lift-off only |
| ≤ 212 | 1 mm / 2 mm lift-off only |

This mouse reports 220.

## macOS notes

- HID descriptor of the pointer collection: 5 buttons, X/Y 16-bit, wheel, AC Pan.
  Button 6 and up cannot come from the firmware.
- The keyboard collection's logical maximum is `0x65`, so the firmware cannot send
  F13–F24. Print Screen, Scroll Lock and Pause (`0x46–0x48`) arrive on a Mac as F13, F14
  and F15, which gives three keys no app uses.
- For LinearMouse, the app's `SideKeyDriver` swallows F15 / F13 and posts mouse buttons
  6 / 7 instead (Accessibility permission), as the Kreo app's key mode does.

## This mouse

Found on 1 Nov 2026 (backup: `~/Library/Application Support/RapooVT9/backup-185a.json`):
one DPI stage on (1600), 1000 Hz, 1.0 mm lift-off, factory system block.
Buttons: Left/Middle/Right normal, bottom button DPI cycle, DPI+ `→`, DPI− `←`,
Forward `]`, Back `Y`.

Changed: polling 1000 → 500 → 1000 Hz as a write test (restored, 19:24 IST). Forward set to
F13 and Back to F15 for LinearMouse at Sahil's request (19:34 IST).

## Tools

| Tool | Purpose |
|---|---|
| `nsis64_extract.py`, `nsis_probe.py` | Unpack this NSIS variant |
| `rea_daemon.py`, `rea_q.py` | Keep one REA/Ghidra session alive; query it (`rea/main/`) |
| `class_vtable.py`, `vtable_class.py` | RTTI class ↔ vtable |
| `slot_users.py` | Which QML model binds a device vtable slot |
| `string_xrefs.py`, `follow_call.sh` | Code that uses a string; disassemble one function |
| `rapoo_console.py` | Talk to the mouse through the app's dev console |

## Open questions

- Whether this unit has physical DPI+ / DPI− buttons (keys 5 and 6). The official app lists
  them for the VT9 Pro; the Button tester in the app answers it.
- Type-7 entries (`07 00 08 00`) in the unused keys 9 and 10.
- `0x8A0`–`0x8BC`, and `0x89C` byte 2 (slot 60, never called for this model).
- Macros (`AD`, 0x52-byte records) and the sniper DPI value.
- Other `0xBB` messages, for example after pressing the DPI button.
