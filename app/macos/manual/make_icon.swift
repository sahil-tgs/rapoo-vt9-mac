// Draws the app icon (an angular V on a violet-to-magenta plate, after the VT9 Pro's
// colours) into the AppIcon.appiconset PNGs. build_no_xcode.sh turns those into AppIcon.icns.
//
//   swift macos/manual/make_icon.swift macos/Runner/Assets.xcassets/AppIcon.appiconset
import CoreGraphics
import Foundation
import ImageIO

let outDir = CommandLine.arguments.count > 1 ? CommandLine.arguments[1] : "."

func rgb(_ hex: UInt32, _ a: CGFloat = 1) -> CGColor {
  CGColor(srgbRed: CGFloat((hex >> 16) & 0xFF) / 255, green: CGFloat((hex >> 8) & 0xFF) / 255,
          blue: CGFloat(hex & 0xFF) / 255, alpha: a)
}

/// macOS icon plate: an 824-point superellipse centred on the 1024 canvas.
func platePath() -> CGPath {
  let p = CGMutablePath()
  let c = CGPoint(x: 512, y: 512), r: CGFloat = 412, n: CGFloat = 5
  for i in 0...720 {
    let t = CGFloat(i) / 720 * 2 * .pi
    let ct = cos(t), st = sin(t)
    let x = c.x + r * (ct < 0 ? -1 : 1) * pow(abs(ct), 2 / n)
    let y = c.y + r * (st < 0 ? -1 : 1) * pow(abs(st), 2 / n)
    i == 0 ? p.move(to: CGPoint(x: x, y: y)) : p.addLine(to: CGPoint(x: x, y: y))
  }
  p.closeSubpath()
  return p
}

/// The V, in top-left-origin coordinates: a thick left arm whose top is cut on a slant,
/// a slimmer right arm, joined at the bottom point.
func vPath() -> CGPath {
  let pts: [CGPoint] = [
    CGPoint(x: 236, y: 300),  // left arm, outer top
    CGPoint(x: 436, y: 396),  // left arm, inner top (slanted cut)
    CGPoint(x: 520, y: 594),  // crotch
    CGPoint(x: 714, y: 262),  // right arm, inner top
    CGPoint(x: 800, y: 262),  // right arm, outer top
    CGPoint(x: 528, y: 768),  // bottom point
  ]
  // Shrink to about 60% of the plate around the V's centre, a little low for optical balance.
  let centre = CGPoint(x: 518, y: 515)
  let t = CGAffineTransform(translationX: centre.x, y: centre.y + 8)
    .scaledBy(x: 0.9, y: 0.9)
    .translatedBy(x: -centre.x, y: -centre.y)
  let p = CGMutablePath()
  p.addLines(between: pts, transform: t)
  p.closeSubpath()
  return p
}

func render(_ size: Int) -> CGImage {
  let ctx = CGContext(data: nil, width: size, height: size, bitsPerComponent: 8, bytesPerRow: 0,
                      space: CGColorSpace(name: CGColorSpace.sRGB)!,
                      bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue)!
  let s = CGFloat(size) / 1024
  ctx.scaleBy(x: s, y: s)
  ctx.translateBy(x: 0, y: 1024)
  ctx.scaleBy(x: 1, y: -1)  // top-left origin from here on
  ctx.interpolationQuality = .high
  let plate = platePath()

  // Plate with its drop shadow (shadow offsets are in device space: negative y = down).
  ctx.saveGState()
  ctx.setShadow(offset: CGSize(width: 0, height: -12 * s), blur: 26 * s, color: rgb(0x000000, 0.32))
  ctx.addPath(plate)
  ctx.setFillColor(rgb(0x3A1663))
  ctx.fillPath()
  ctx.restoreGState()

  // Violet -> magenta diagonal gradient, plus a soft light from the top left.
  ctx.saveGState()
  ctx.addPath(plate)
  ctx.clip()
  let grad = CGGradient(colorsSpace: nil,
                        colors: [rgb(0x2B1052), rgb(0x5E1F86), rgb(0xA92C86), rgb(0xD8407A)] as CFArray,
                        locations: [0, 0.38, 0.78, 1])!
  ctx.drawLinearGradient(grad, start: CGPoint(x: 140, y: 120), end: CGPoint(x: 900, y: 930), options: [])
  let glow = CGGradient(colorsSpace: nil, colors: [rgb(0xFFFFFF, 0.20), rgb(0xFFFFFF, 0)] as CFArray,
                        locations: [0, 1])!
  ctx.drawRadialGradient(glow, startCenter: CGPoint(x: 300, y: 210), startRadius: 0,
                         endCenter: CGPoint(x: 300, y: 210), endRadius: 620, options: [])
  // Thin inner rim.
  ctx.addPath(plate)
  ctx.setStrokeColor(rgb(0xFFFFFF, 0.14))
  ctx.setLineWidth(4)
  ctx.strokePath()
  ctx.restoreGState()

  // The V: white with a faint pink fall-off and a shadow that lifts it off the plate.
  let v = vPath()
  ctx.saveGState()
  ctx.setShadow(offset: CGSize(width: 0, height: -10 * s), blur: 30 * s, color: rgb(0x14051F, 0.45))
  ctx.addPath(v)
  ctx.setFillColor(rgb(0xFFFFFF))
  ctx.fillPath()
  ctx.restoreGState()
  ctx.saveGState()
  ctx.addPath(v)
  ctx.clip()
  let vGrad = CGGradient(colorsSpace: nil, colors: [rgb(0xFFFFFF), rgb(0xF6E3F1)] as CFArray,
                         locations: [0, 1])!
  ctx.drawLinearGradient(vGrad, start: CGPoint(x: 512, y: 262), end: CGPoint(x: 512, y: 768), options: [])
  ctx.restoreGState()

  return ctx.makeImage()!
}

for size in [16, 32, 64, 128, 256, 512, 1024] {
  let url = URL(fileURLWithPath: outDir).appendingPathComponent("app_icon_\(size).png")
  let dest = CGImageDestinationCreateWithURL(url as CFURL, "public.png" as CFString, 1, nil)!
  CGImageDestinationAddImage(dest, render(size), nil)
  guard CGImageDestinationFinalize(dest) else { fatalError("could not write \(url.path)") }
  print("wrote \(url.path)")
}
