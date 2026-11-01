"""Find the compressed stream inside an NSIS data block and report what decodes.
Usage: python3 -I nsis_probe.py <blob>"""
import sys, zlib, lzma, bz2

blob = open(sys.argv[1], 'rb').read()
for off in range(24, 64, 4):
    chunk = blob[off:off + 4_000_000]
    # raw deflate (NSIS zlib mode)
    try:
        d = zlib.decompressobj(-15).decompress(chunk, 2_000_000)
        if len(d) > 1000:
            print(f"off {off}: deflate -> {len(d)} bytes; head {d[:24].hex(' ')}")
    except Exception:
        pass
    # NSIS lzma: 5 property bytes + raw stream, no size field
    try:
        props = chunk[:5]
        dict_size = int.from_bytes(props[1:5], 'little')
        lc_lp_pb = props[0]
        lc, rem = lc_lp_pb % 9, lc_lp_pb // 9
        lp, pb = rem % 5, rem // 5
        filt = [{"id": lzma.FILTER_LZMA1, "dict_size": dict_size, "lc": lc, "lp": lp, "pb": pb}]
        d = lzma.LZMADecompressor(format=lzma.FORMAT_RAW, filters=filt).decompress(chunk[5:], 2_000_000)
        if len(d) > 1000:
            print(f"off {off}: lzma(props {props.hex()}) -> {len(d)} bytes; head {d[:24].hex(' ')}")
    except Exception:
        pass
    try:
        d = bz2.BZ2Decompressor().decompress(b'BZh9' + chunk)
        if len(d) > 1000:
            print(f"off {off}: bzip2 -> {len(d)} bytes; head {d[:24].hex(' ')}")
    except Exception:
        pass
