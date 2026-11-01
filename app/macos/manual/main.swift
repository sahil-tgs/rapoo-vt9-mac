// Programmatic entry point used by build_no_xcode.sh.
//
// The regular Xcode build uses macos/Runner/AppDelegate.swift plus the
// MainMenu.xib storyboard. Compiling a .xib needs ibtool, which only ships
// with full Xcode, so this file recreates the same window and menu bar in
// code and is compiled with the command-line-tools swiftc instead.
import Cocoa
import FlutterMacOS

final class ManualAppDelegate: NSObject, NSApplicationDelegate {
  private var window: MainFlutterWindow?

  func applicationDidFinishLaunching(_ notification: Notification) {
    installMenuBar()
    let w = MainFlutterWindow(
      contentRect: NSRect(x: 0, y: 0, width: 860, height: 760),
      styleMask: [.titled, .closable, .miniaturizable, .resizable],
      backing: .buffered,
      defer: false)
    w.isReleasedWhenClosed = false
    w.setup()
    w.center()
    w.makeKeyAndOrderFront(nil)
    window = w
    NSApp.activate(ignoringOtherApps: true)
  }

  // Keep running with the window closed: the side-button driver lives here.
  func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
    return false
  }

  // Clicking the Dock icon brings the window back.
  func applicationShouldHandleReopen(_ sender: NSApplication, hasVisibleWindows flag: Bool) -> Bool {
    if !flag { window?.makeKeyAndOrderFront(nil) }
    return true
  }

  func applicationSupportsSecureRestorableState(_ app: NSApplication) -> Bool {
    return true
  }

  private func installMenuBar() {
    let appName = ProcessInfo.processInfo.processName
    let mainMenu = NSMenu()

    let appItem = NSMenuItem()
    let appMenu = NSMenu()
    appMenu.addItem(withTitle: "About \(appName)",
                    action: #selector(NSApplication.orderFrontStandardAboutPanel(_:)), keyEquivalent: "")
    appMenu.addItem(.separator())
    appMenu.addItem(withTitle: "Hide \(appName)", action: #selector(NSApplication.hide(_:)), keyEquivalent: "h")
    let hideOthers = appMenu.addItem(withTitle: "Hide Others",
                                     action: #selector(NSApplication.hideOtherApplications(_:)), keyEquivalent: "h")
    hideOthers.keyEquivalentModifierMask = [.command, .option]
    appMenu.addItem(withTitle: "Show All", action: #selector(NSApplication.unhideAllApplications(_:)), keyEquivalent: "")
    appMenu.addItem(.separator())
    appMenu.addItem(withTitle: "Quit \(appName)", action: #selector(NSApplication.terminate(_:)), keyEquivalent: "q")
    appItem.submenu = appMenu
    mainMenu.addItem(appItem)

    let editItem = NSMenuItem()
    let editMenu = NSMenu(title: "Edit")
    editMenu.addItem(withTitle: "Undo", action: Selector(("undo:")), keyEquivalent: "z")
    editMenu.addItem(withTitle: "Redo", action: Selector(("redo:")), keyEquivalent: "Z")
    editMenu.addItem(.separator())
    editMenu.addItem(withTitle: "Cut", action: #selector(NSText.cut(_:)), keyEquivalent: "x")
    editMenu.addItem(withTitle: "Copy", action: #selector(NSText.copy(_:)), keyEquivalent: "c")
    editMenu.addItem(withTitle: "Paste", action: #selector(NSText.paste(_:)), keyEquivalent: "v")
    editMenu.addItem(withTitle: "Select All", action: #selector(NSText.selectAll(_:)), keyEquivalent: "a")
    editItem.submenu = editMenu
    mainMenu.addItem(editItem)

    let windowItem = NSMenuItem()
    let windowMenu = NSMenu(title: "Window")
    windowMenu.addItem(withTitle: "Minimize", action: #selector(NSWindow.performMiniaturize(_:)), keyEquivalent: "m")
    windowMenu.addItem(withTitle: "Zoom", action: #selector(NSWindow.performZoom(_:)), keyEquivalent: "")
    windowMenu.addItem(.separator())
    windowMenu.addItem(withTitle: "Close", action: #selector(NSWindow.performClose(_:)), keyEquivalent: "w")
    windowItem.submenu = windowMenu
    mainMenu.addItem(windowItem)
    NSApp.windowsMenu = windowMenu

    NSApp.mainMenu = mainMenu
  }
}

let app = NSApplication.shared
let delegate = ManualAppDelegate()
app.delegate = delegate
app.setActivationPolicy(.regular)
app.run()
