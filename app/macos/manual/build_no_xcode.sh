#!/bin/zsh
# Builds "Kreo Chimera.app" WITHOUT Xcode, using only the Xcode Command Line
# Tools and the Flutter SDK:
#   1. `flutter assemble` compiles the Dart code to App.framework and copies
#      FlutterMacOS.framework (this step does not need Xcode).
#   2. swiftc compiles the small native runner (window + IOKit HID bridge).
#   3. The .app bundle is assembled by hand and ad-hoc signed.
#
# With full Xcode installed you can instead simply run:  flutter build macos
set -euo pipefail
export PATH="/opt/homebrew/bin:$PATH"

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$ROOT"

APPNAME="Rapoo VT9"
OUT="$ROOT/build/manual"
STAGE="$ROOT/build/manual-app"
APP="$STAGE/$APPNAME.app"
SDK="$(xcrun --show-sdk-path)"
ARCH="${ARCH:-$(uname -m)}"
VERSION="$(sed -n 's/^version: *\([0-9.]*\).*/\1/p' pubspec.yaml)"
BUILD_NUMBER="$(sed -n 's/^version: *[0-9.]*+\([0-9]*\).*/\1/p' pubspec.yaml)"
: "${VERSION:=1.0.0}"; : "${BUILD_NUMBER:=1}"

echo "==> 1/4 flutter assemble (release, $ARCH)  [$(date +%T)]"
flutter assemble --output="$OUT" \
  -dTargetPlatform=darwin -dBuildMode=release -dDarwinArchs="$ARCH" \
  -dTreeShakeIcons=false -dDartObfuscation=false -dTrackWidgetCreation=false \
  release_macos_bundle_flutter_assets

echo "==> 2/4 compile native runner with swiftc ($(swiftc --version 2>&1 | head -1))  [$(date +%T)]"
rm -rf "$APP"
mkdir -p "$APP/Contents/MacOS" "$APP/Contents/Frameworks" "$APP/Contents/Resources"
swiftc -O \
  -target "$ARCH-apple-macos12.0" -sdk "$SDK" \
  -module-name Runner \
  -F "$OUT" -framework FlutterMacOS -framework Cocoa -framework IOKit \
  -Xlinker -rpath -Xlinker @executable_path/../Frameworks \
  -o "$APP/Contents/MacOS/$APPNAME" \
  macos/manual/main.swift \
  macos/Runner/MainFlutterWindow.swift \
  macos/Flutter/GeneratedPluginRegistrant.swift

echo "==> 3/4 assemble bundle  [$(date +%T)]"
cp -R "$OUT/App.framework" "$APP/Contents/Frameworks/"
cp -R "$OUT/FlutterMacOS.framework" "$APP/Contents/Frameworks/"

# App icon: build an .icns from the template PNGs (iconutil ships with macOS).
ICONSET="$STAGE/AppIcon.iconset"
SRC="$ROOT/macos/Runner/Assets.xcassets/AppIcon.appiconset"
rm -rf "$ICONSET"; mkdir -p "$ICONSET"
cp "$SRC/app_icon_16.png"   "$ICONSET/icon_16x16.png"
cp "$SRC/app_icon_32.png"   "$ICONSET/icon_16x16@2x.png"
cp "$SRC/app_icon_32.png"   "$ICONSET/icon_32x32.png"
cp "$SRC/app_icon_64.png"   "$ICONSET/icon_32x32@2x.png"
cp "$SRC/app_icon_128.png"  "$ICONSET/icon_128x128.png"
cp "$SRC/app_icon_256.png"  "$ICONSET/icon_128x128@2x.png"
cp "$SRC/app_icon_256.png"  "$ICONSET/icon_256x256.png"
cp "$SRC/app_icon_512.png"  "$ICONSET/icon_256x256@2x.png"
cp "$SRC/app_icon_512.png"  "$ICONSET/icon_512x512.png"
cp "$SRC/app_icon_1024.png" "$ICONSET/icon_512x512@2x.png"
iconutil -c icns "$ICONSET" -o "$APP/Contents/Resources/AppIcon.icns"

cat > "$APP/Contents/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>CFBundleDevelopmentRegion</key>
	<string>en</string>
	<key>CFBundleExecutable</key>
	<string>$APPNAME</string>
	<key>CFBundleIconFile</key>
	<string>AppIcon</string>
	<key>CFBundleIdentifier</key>
	<string>local.sahil.rapooVt9</string>
	<key>CFBundleInfoDictionaryVersion</key>
	<string>6.0</string>
	<key>CFBundleName</key>
	<string>$APPNAME</string>
	<key>CFBundleDisplayName</key>
	<string>$APPNAME</string>
	<key>CFBundlePackageType</key>
	<string>APPL</string>
	<key>CFBundleShortVersionString</key>
	<string>$VERSION</string>
	<key>CFBundleVersion</key>
	<string>$BUILD_NUMBER</string>
	<key>LSMinimumSystemVersion</key>
	<string>12.0</string>
	<key>NSHighResolutionCapable</key>
	<true/>
	<key>NSHumanReadableCopyright</key>
	<string>Rapoo VT9 macOS tool</string>
	<key>NSPrincipalClass</key>
	<string>NSApplication</string>
	<key>NSSupportsAutomaticGraphicsSwitching</key>
	<true/>
</dict>
</plist>
PLIST
printf 'APPL????' > "$APP/Contents/PkgInfo"

echo "==> 4/4 ad-hoc codesign  [$(date +%T)]"
# Ad-hoc signatures normally get a cdhash-based designated requirement, which
# changes on every rebuild and silently voids Input Monitoring / Accessibility
# grants. Give the app an explicit, stable requirement based on its bundle ID
# so macOS privacy grants survive rebuilds.
for fw in "$APP/Contents/Frameworks/"*.framework; do
  codesign --force --sign - "$fw"
done
codesign --force --sign - -r='designated => identifier "local.sahil.rapooVt9"' "$APP"
codesign --verify --deep --strict "$APP" && echo "signature OK"
codesign -dr - "$APP" 2>&1 | grep designated

mkdir -p "$HOME/Applications"
pkill -f "$APPNAME.app/Contents/MacOS" 2>/dev/null || true
rm -rf "$HOME/Applications/$APPNAME.app"
cp -R "$APP" "$HOME/Applications/"
echo
echo "Built: $HOME/Applications/$APPNAME.app"
