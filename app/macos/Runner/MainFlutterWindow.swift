import Cocoa
import FlutterMacOS
import IOKit
import IOKit.hid
import ServiceManagement

class MainFlutterWindow: NSWindow {
  /// Xcode builds: the window comes from MainMenu.xib.
  override func awakeFromNib() {
    setup()
    super.awakeFromNib()
  }

  /// Shared by the xib path and the programmatic path (macos/manual/main.swift).
  func setup() {
    let flutterViewController = FlutterViewController()
    let windowFrame = self.frame
    self.contentViewController = flutterViewController
    self.setFrame(windowFrame, display: true)
    self.minSize = NSSize(width: 760, height: 600)
    self.title = "Rapoo VT9"

    RegisterGeneratedPlugins(registry: flutterViewController)
    RapooHid.shared.attach(to: flutterViewController.engine.binaryMessenger)
    SideKeyDriver.shared.attach(to: flutterViewController.engine.binaryMessenger)
  }
}

/// Turns the F15 / F13 key presses that the side buttons can be set to send into
/// mouse buttons 6 / 7, which no app acts on by default but which LinearMouse can use
/// as its gesture button. The mouse cannot send button 6 itself: its HID descriptor
/// declares five buttons. Nor can it send real F13-F15 (its keyboard collection stops
/// at usage 0x65), so the firmware sends Pause and Print Screen, which macOS reads as
/// F15 and F13. Needs Accessibility for the key tap and for posting the mouse buttons.
final class SideKeyDriver {
  static let shared = SideKeyDriver()

  /// Written into eventSourceUserData of every event we post ("RAPO").
  static let userDataMarker: Int64 = 0x5241_504F
  /// macOS key code -> CG button number (0-based): F15 -> button 6, F13 -> button 7.
  private static let buttonForKey: [Int64: Int] = [113: 5, 105: 6]

  private(set) var enabled: Bool
  private var pressed: [Int64: Int] = [:]
  private var tap: CFMachPort?
  private var tapSource: CFRunLoopSource?
  private var channel: FlutterMethodChannel?
  private var dartReady = false
  private var retryTimer: Timer?
  private var lastStatus = ""
  private var lastError = ""
  private lazy var eventSource = CGEventSource(stateID: .hidSystemState)

  private init() {
    enabled = UserDefaults.standard.bool(forKey: "sideKeys.enabled")
    NotificationCenter.default.addObserver(
      forName: NSApplication.willTerminateNotification, object: nil, queue: .main
    ) { [weak self] _ in self?.releaseAll() }
  }

  func attach(to messenger: FlutterBinaryMessenger) {
    let ch = FlutterMethodChannel(name: "rapoo/side", binaryMessenger: messenger)
    ch.setMethodCallHandler { [weak self] call, result in
      guard let self = self else { return result(nil) }
      self.dartReady = true
      self.handle(call, result: result)
    }
    channel = ch
    if enabled {
      if !AXIsProcessTrusted() { promptAccessibility() }
      installTap()
    }
    // Accessibility is usually granted while the app is running; keep retrying.
    retryTimer = Timer.scheduledTimer(withTimeInterval: 2.0, repeats: true) { [weak self] _ in self?.retry() }
  }

  private func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    let args = call.arguments as? [String: Any] ?? [:]
    switch call.method {
    case "status":
      result(status())
    case "setEnabled":
      enabled = args["enabled"] as? Bool ?? false
      UserDefaults.standard.set(enabled, forKey: "sideKeys.enabled")
      if enabled {
        if !AXIsProcessTrusted() { promptAccessibility() }
        installTap()
      } else {
        releaseAll()
        removeTap()
      }
      result(status())
    case "requestAccessibility":
      promptAccessibility()
      retry()
      result(status())
    case "setLoginItem":
      result(setLoginItem(args["enabled"] as? Bool ?? false))
    default:
      result(FlutterMethodNotImplemented)
    }
  }

  private func promptAccessibility() {
    let opts = [kAXTrustedCheckOptionPrompt.takeUnretainedValue() as String: true] as CFDictionary
    if !AXIsProcessTrustedWithOptions(opts) {
      _ = CGRequestPostEventAccess()
      if let url = URL(string: "x-apple.systempreferences:com.apple.preference.security?Privacy_Accessibility") {
        NSWorkspace.shared.open(url)
      }
    }
  }

  func status() -> [String: Any] {
    [
      "enabled": enabled,
      "accessibility": AXIsProcessTrusted(),
      "tapActive": tapHealthy(),
      "loginItem": loginItemState(),
      "error": lastError,
    ]
  }

  private func retry() {
    if enabled && !tapHealthy() && AXIsProcessTrusted() {
      releaseAll()
      removeTap()
      installTap()
    }
    // Dictionary order is not stable between calls: compare a sorted rendering.
    let s = status().sorted { $0.key < $1.key }.map { "\($0.key)=\($0.value)" }.joined(separator: " ")
    if s != lastStatus {
      lastStatus = s
      NSLog("[rapoo-side] %@", s)
      if dartReady { channel?.invokeMethod("status", arguments: status()) }
    }
  }

  private func loginItemState() -> String {
    if #available(macOS 13.0, *) {
      switch SMAppService.mainApp.status {
      case .enabled: return "enabled"
      case .requiresApproval: return "requiresApproval"
      default: return "off"
      }
    }
    return "unsupported"
  }

  private func setLoginItem(_ on: Bool) -> [String: Any] {
    if #available(macOS 13.0, *) {
      do {
        if on { try SMAppService.mainApp.register() } else { try SMAppService.mainApp.unregister() }
        lastError = ""
      } catch {
        lastError = "Open at login: \(error.localizedDescription)"
      }
    } else {
      lastError = "Open at login needs macOS 13 or later"
    }
    return status()
  }

  // MARK: key tap

  private func tapHealthy() -> Bool {
    guard let t = tap else { return false }
    return CFMachPortIsValid(t) && CGEvent.tapIsEnabled(tap: t)
  }

  private func installTap() {
    guard tap == nil else { return }
    let mask = CGEventMask(1 << CGEventType.keyDown.rawValue) | CGEventMask(1 << CGEventType.keyUp.rawValue)
    let ctx = Unmanaged.passUnretained(self).toOpaque()
    guard let t = CGEvent.tapCreate(
      tap: .cghidEventTap, place: .headInsertEventTap, options: .defaultTap,
      eventsOfInterest: mask,
      callback: { _, type, event, ctx in
        guard let ctx = ctx else { return Unmanaged.passUnretained(event) }
        return Unmanaged<SideKeyDriver>.fromOpaque(ctx).takeUnretainedValue().handleTap(type: type, event: event)
      },
      userInfo: ctx)
    else {
      lastError = "Accessibility permission needed"
      return
    }
    let src = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, t, 0)
    CFRunLoopAddSource(CFRunLoopGetMain(), src, .commonModes)
    CGEvent.tapEnable(tap: t, enable: true)
    tap = t
    tapSource = src
    lastError = ""
  }

  private func removeTap() {
    if let t = tap { CGEvent.tapEnable(tap: t, enable: false); CFMachPortInvalidate(t) }
    if let s = tapSource { CFRunLoopRemoveSource(CFRunLoopGetMain(), s, .commonModes) }
    tap = nil
    tapSource = nil
  }

  private func handleTap(type: CGEventType, event: CGEvent) -> Unmanaged<CGEvent>? {
    if type == .tapDisabledByTimeout || type == .tapDisabledByUserInput {
      if let t = tap { CGEvent.tapEnable(tap: t, enable: true) }
      return Unmanaged.passUnretained(event)
    }
    let code = event.getIntegerValueField(.keyboardEventKeycode)
    guard enabled, type == .keyDown || type == .keyUp, let button = Self.buttonForKey[code] else {
      return Unmanaged.passUnretained(event)
    }
    if type == .keyDown {
      // Key repeat arrives while the side button is held: swallow it.
      if pressed[code] == nil {
        pressed[code] = button
        post(button: button, down: true)
      }
    } else if let b = pressed.removeValue(forKey: code) {
      post(button: b, down: false)
    }
    return nil
  }

  private func releaseAll() {
    for (_, b) in pressed { post(button: b, down: false) }
    pressed.removeAll()
  }

  private func post(button: Int, down: Bool) {
    let location = CGEvent(source: nil)?.location ?? .zero
    guard let ev = CGEvent(mouseEventSource: eventSource,
                           mouseType: down ? .otherMouseDown : .otherMouseUp,
                           mouseCursorPosition: location,
                           mouseButton: .center) else { return }
    ev.setIntegerValueField(.mouseEventButtonNumber, value: Int64(button))
    ev.setIntegerValueField(.mouseEventClickState, value: 1)
    ev.setIntegerValueField(.eventSourceUserData, value: Self.userDataMarker)
    ev.flags = CGEventSource.flagsState(.combinedSessionState)
    ev.post(tap: .cghidEventTap)
    NSLog("[rapoo-side] posted mouse button %d %@", button + 1, down ? "down" : "up")
  }
}

/// Native HID layer for Rapoo VT9-family mice (vendor 0x24AE).
///
/// The configuration protocol lives on the interface that carries vendor
/// collections on usage page 0xFF00: report 0xBA (31 data bytes each way) and
/// report 0xBB (6 data bytes each way), sent as OUTPUT reports with replies as
/// INPUT reports. That interface also carries a keyboard collection (used for
/// the mouse's macro keys), so macOS requires Input Monitoring to open it.
/// Only vendor reports 0xBA/0xBB are ever forwarded; keyboard reports are dropped.
final class RapooHid {
  static let shared = RapooHid()
  static let vendorID = 0x24AE
  static let vendorReportIDs: Set<UInt32> = [0xBA, 0xBB]

  private var channel: FlutterMethodChannel?
  private var dartReady = false
  private var manager: IOHIDManager?
  private var openResult: IOReturn = kIOReturnNotOpen
  private var devices: [ObjectIdentifier: IOHIDDevice] = [:]
  private var retryTimer: Timer?
  private(set) var console: DevConsole?
  private var rxCount = 0
  private var txCount = 0

  // MARK: lifecycle

  func attach(to messenger: FlutterBinaryMessenger) {
    let ch = FlutterMethodChannel(name: "rapoo/hid", binaryMessenger: messenger)
    ch.setMethodCallHandler { [weak self] call, result in
      guard let self = self else { return result(nil) }
      self.dartReady = true
      self.handle(call, result: result)
    }
    channel = ch
    start()
    // Off unless enabled: defaults write local.sahil.rapooVt9 devConsole -bool true
    if UserDefaults.standard.bool(forKey: "devConsole") {
      console = DevConsole(hid: self)
      console?.start()
    }
    retryTimer = Timer.scheduledTimer(withTimeInterval: 2.0, repeats: true) { [weak self] _ in
      guard let self = self else { return }
      if self.openResult != kIOReturnSuccess && self.inputMonitoring() == "granted" {
        NSLog("[rapoo] Input Monitoring granted: reopening")
        self.stop()
        self.start()
        self.notify()
      }
    }
  }

  func inputMonitoring() -> String {
    let a = IOHIDCheckAccess(kIOHIDRequestTypeListenEvent)
    if a == kIOHIDAccessTypeGranted { return "granted" }
    if a == kIOHIDAccessTypeDenied { return "denied" }
    return "unknown"
  }

  private func start() {
    guard manager == nil else { return }
    let m = IOHIDManagerCreate(kCFAllocatorDefault, IOOptionBits(kIOHIDOptionsTypeNone))
    IOHIDManagerSetDeviceMatching(m, [kIOHIDVendorIDKey: Self.vendorID,
                                      kIOHIDDeviceUsagePageKey: 0xFF00] as CFDictionary)
    let ctx = Unmanaged.passUnretained(self).toOpaque()
    IOHIDManagerRegisterDeviceMatchingCallback(m, { ctx, _, _, device in
      guard let ctx = ctx else { return }
      let me = Unmanaged<RapooHid>.fromOpaque(ctx).takeUnretainedValue()
      me.devices[ObjectIdentifier(device)] = device
      NSLog("[rapoo] device attached pid=0x%04x", me.intProp(device, kIOHIDProductIDKey))
      me.notify()
    }, ctx)
    IOHIDManagerRegisterDeviceRemovalCallback(m, { ctx, _, _, device in
      guard let ctx = ctx else { return }
      let me = Unmanaged<RapooHid>.fromOpaque(ctx).takeUnretainedValue()
      me.devices.removeValue(forKey: ObjectIdentifier(device))
      me.notify()
    }, ctx)
    IOHIDManagerRegisterInputReportWithTimeStampCallback(m, { ctx, _, sender, _, reportID, report, length, _ in
      guard let ctx = ctx, RapooHid.vendorReportIDs.contains(reportID) else { return }  // drop keyboard reports
      let me = Unmanaged<RapooHid>.fromOpaque(ctx).takeUnretainedValue()
      let bytes = Array(UnsafeBufferPointer(start: report, count: length))
      let pid = sender.map { me.intProp(Unmanaged<IOHIDDevice>.fromOpaque($0).takeUnretainedValue(), kIOHIDProductIDKey) } ?? 0
      me.receive(reportID: Int(reportID), bytes: bytes, pid: pid)
    }, ctx)
    IOHIDManagerScheduleWithRunLoop(m, CFRunLoopGetMain(), CFRunLoopMode.defaultMode.rawValue)
    openResult = IOHIDManagerOpen(m, IOOptionBits(kIOHIDOptionsTypeNone))
    manager = m
    NSLog("[rapoo] IOHIDManagerOpen -> 0x%08x (Input Monitoring: %@)", UInt32(bitPattern: openResult), inputMonitoring())
  }

  private func stop() {
    if let m = manager {
      IOHIDManagerUnscheduleFromRunLoop(m, CFRunLoopGetMain(), CFRunLoopMode.defaultMode.rawValue)
      IOHIDManagerClose(m, IOOptionBits(kIOHIDOptionsTypeNone))
    }
    manager = nil
    devices.removeAll()
    openResult = kIOReturnNotOpen
  }

  // MARK: I/O

  private func receive(reportID: Int, bytes: [UInt8], pid: Int) {
    rxCount += 1
    // The buffer starts with the report ID for numbered reports; normalise to [id, data...].
    let frame = (bytes.first.map { Int($0) } == reportID) ? bytes : [UInt8(reportID)] + bytes
    console?.broadcast("rx " + frame.map { String(format: "%02x", $0) }.joined(separator: " "))
    if dartReady {
      channel?.invokeMethod("rx", arguments: ["pid": pid, "data": FlutterStandardTypedData(bytes: Data(frame))])
    }
  }

  /// Sends one output report. `frame[0]` is the report ID (0xBA or 0xBB).
  @discardableResult
  func write(_ frame: [UInt8], pid: Int? = nil) -> IOReturn {
    guard let first = frame.first, let dev = target(pid: pid) else { return kIOReturnNotOpen }
    let size = first == 0xBB ? 7 : 32
    var buf = [UInt8](repeating: 0, count: size)
    for (i, b) in frame.prefix(size).enumerated() { buf[i] = b }
    let r = IOHIDDeviceSetReport(dev, kIOHIDReportTypeOutput, CFIndex(first), buf, buf.count)
    txCount += 1
    console?.broadcast(String(format: "tx-result 0x%08x ", UInt32(bitPattern: r)) + buf.map { String(format: "%02x", $0) }.joined(separator: " "))
    return r
  }

  /// Fetches an input report with GET_REPORT (what Rapoo's HidD_GetInputReport does).
  func getInput(_ reportID: UInt8, size: Int = 32, pid: Int? = nil) -> (IOReturn, [UInt8]) {
    guard let dev = target(pid: pid) else { return (kIOReturnNotOpen, []) }
    var buf = [UInt8](repeating: 0, count: size)
    buf[0] = reportID
    var len = CFIndex(size)
    let r = IOHIDDeviceGetReport(dev, kIOHIDReportTypeInput, CFIndex(reportID), &buf, &len)
    // Keep the whole buffer: macOS sometimes reports a shorter length than it filled.
    console?.broadcast(String(format: "get-result 0x%08x len=%ld ", UInt32(bitPattern: r), len) + buf.map { String(format: "%02x", $0) }.joined(separator: " "))
    return (r, buf)
  }

  private let ioQueue = DispatchQueue(label: "rapoo.io")

  /// Same exchange as Rapoo's driver: send, wait 50 ms, GET_REPORT up to 3 times until the
  /// status byte says OK; the whole thing is retried up to 3 times. Runs off the main thread.
  func transact(_ frame: [UInt8], pid: Int? = nil, completion: @escaping ([UInt8]?) -> Void) {
    ioQueue.async { [weak self] in
      guard let self = self, let rid = frame.first else { return completion(nil) }
      for _ in 0..<3 {
        let w = DispatchQueue.main.sync { self.write(frame, pid: pid) }
        guard w == kIOReturnSuccess else { usleep(50_000); continue }
        usleep(50_000)
        for _ in 0..<3 {
          let (r, data) = DispatchQueue.main.sync { self.getInput(rid, pid: pid) }
          if r == kIOReturnSuccess, let status = data.first {
            // macOS strips the report ID: data[0] is the status (1 = OK, 0 = busy, 2 = error)
            if status == 1 || status == 2 { DispatchQueue.main.async { completion(data) }; return }
          }
          usleep(50_000)
        }
        usleep(50_000)
      }
      DispatchQueue.main.async { completion(nil) }
    }
  }

  private func target(pid: Int?) -> IOHIDDevice? {
    let all = Array(devices.values)
    if let pid = pid { return all.first { intProp($0, kIOHIDProductIDKey) == pid } }
    return all.first
  }

  func intProp(_ d: IOHIDDevice, _ key: String) -> Int {
    (IOHIDDeviceGetProperty(d, key as CFString) as? NSNumber)?.intValue ?? -1
  }

  func status() -> [String: Any] {
    let list: [[String: Any]] = devices.values.map { d in
      [
        "pid": intProp(d, kIOHIDProductIDKey),
        "product": (IOHIDDeviceGetProperty(d, kIOHIDProductKey as CFString) as? String) ?? "",
        "version": intProp(d, kIOHIDVersionNumberKey),
        "transport": (IOHIDDeviceGetProperty(d, kIOHIDTransportKey as CFString) as? String) ?? "",
      ]
    }
    return [
      "inputMonitoring": inputMonitoring(),
      "open": openResult == kIOReturnSuccess,
      "openResult": Int(UInt32(bitPattern: openResult)),
      "devices": list,
      "rx": rxCount,
      "tx": txCount,
      "console": console?.path ?? "",
    ]
  }

  private func notify() {
    if dartReady { channel?.invokeMethod("status", arguments: status()) }
  }

  // MARK: channel

  private func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    let args = call.arguments as? [String: Any] ?? [:]
    switch call.method {
    case "status":
      result(status())
    case "requestInputMonitoring":
      if !IOHIDRequestAccess(kIOHIDRequestTypeListenEvent),
         let url = URL(string: "x-apple.systempreferences:com.apple.preference.security?Privacy_ListenEvent") {
        NSWorkspace.shared.open(url)
      }
      result(status())
    case "write":
      guard let td = args["data"] as? FlutterStandardTypedData else { return result(-1) }
      result(Int(UInt32(bitPattern: write([UInt8](td.data), pid: args["pid"] as? Int))))
    case "getInput":
      let (r, data) = getInput(UInt8(args["reportId"] as? Int ?? 0xBA), size: args["size"] as? Int ?? 32)
      result(r == kIOReturnSuccess ? FlutterStandardTypedData(bytes: Data(data)) : nil)
    case "transact":
      guard let td = args["data"] as? FlutterStandardTypedData else { return result(nil) }
      transact([UInt8](td.data), pid: args["pid"] as? Int) { data in
        result(data.map { FlutterStandardTypedData(bytes: Data($0)) })
      }
    default:
      result(FlutterMethodNotImplemented)
    }
  }
}

/// Development console: a Unix socket (owner-only) at
/// ~/Library/Application Support/RapooVT9/console.sock.
/// Lines in:  "tx <hex bytes>"  (first byte = report ID)   |   "status"
/// Lines out: "rx <hex>" for every vendor input report, "tx-result <IOReturn> <hex>", JSON for status.
final class DevConsole {
  let path: String
  private weak var hid: RapooHid?
  private var listenFD: Int32 = -1
  private var clients: [Int32] = []
  private let lock = NSLock()

  init(hid: RapooHid) {
    self.hid = hid
    let dir = FileManager.default.homeDirectoryForCurrentUser
      .appendingPathComponent("Library/Application Support/RapooVT9", isDirectory: true)
    try? FileManager.default.createDirectory(at: dir, withIntermediateDirectories: true)
    path = dir.appendingPathComponent("console.sock").path
  }

  func start() {
    unlink(path)
    listenFD = socket(AF_UNIX, SOCK_STREAM, 0)
    guard listenFD >= 0 else { return }
    var addr = sockaddr_un()
    addr.sun_family = sa_family_t(AF_UNIX)
    let bytes = Array(path.utf8)
    guard bytes.count < MemoryLayout.size(ofValue: addr.sun_path) else { return }
    withUnsafeMutableBytes(of: &addr.sun_path) { raw in
      for (i, b) in bytes.enumerated() { raw[i] = b }
      raw[bytes.count] = 0
    }
    let ok = withUnsafePointer(to: &addr) {
      $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
        bind(listenFD, $0, socklen_t(MemoryLayout<sockaddr_un>.size))
      }
    }
    guard ok == 0, listen(listenFD, 4) == 0 else { NSLog("[rapoo] console: bind/listen failed"); return }
    chmod(path, 0o600)
    NSLog("[rapoo] console listening at %@", path)
    Thread.detachNewThread { [weak self] in self?.acceptLoop() }
  }

  private func acceptLoop() {
    while true {
      let fd = accept(listenFD, nil, nil)
      if fd < 0 { continue }
      lock.lock(); clients.append(fd); lock.unlock()
      Thread.detachNewThread { [weak self] in self?.readLoop(fd) }
    }
  }

  private func readLoop(_ fd: Int32) {
    var pending = Data()
    var buf = [UInt8](repeating: 0, count: 4096)
    while true {
      let n = read(fd, &buf, buf.count)
      if n <= 0 { break }
      pending.append(buf, count: n)
      while let nl = pending.firstIndex(of: 0x0A) {
        let line = String(data: pending[pending.startIndex..<nl], encoding: .utf8) ?? ""
        pending.removeSubrange(pending.startIndex...nl)
        DispatchQueue.main.async { [weak self] in self?.command(line.trimmingCharacters(in: .whitespaces), fd: fd) }
      }
    }
    lock.lock(); clients.removeAll { $0 == fd }; lock.unlock()
    close(fd)
  }

  private func command(_ line: String, fd: Int32) {
    guard let hid = hid else { return }
    if line == "status" {
      if let json = try? JSONSerialization.data(withJSONObject: hid.status()),
         let s = String(data: json, encoding: .utf8) { send(s, to: fd) }
    } else if line.hasPrefix("tx ") {
      let bytes = line.dropFirst(3).split(separator: " ").compactMap { UInt8($0, radix: 16) }
      hid.write(bytes)
    } else if line.hasPrefix("get ") {
      let id = UInt8(line.dropFirst(4).trimmingCharacters(in: .whitespaces), radix: 16) ?? 0xBA
      _ = hid.getInput(id)
    } else if line.hasPrefix("xfer ") {
      let bytes = line.dropFirst(5).split(separator: " ").compactMap { UInt8($0, radix: 16) }
      hid.transact(bytes) { [weak self] data in
        self?.send("xfer-result " + (data.map { $0.map { String(format: "%02x", $0) }.joined(separator: " ") } ?? "none"), to: fd)
      }
    } else {
      send("error unknown command", to: fd)
    }
  }

  private func send(_ s: String, to fd: Int32) {
    let data = Array((s + "\n").utf8)
    _ = data.withUnsafeBytes { write(fd, $0.baseAddress, data.count) }
  }

  func broadcast(_ s: String) {
    lock.lock(); let fds = clients; lock.unlock()
    for fd in fds { send(s, to: fd) }
  }
}
