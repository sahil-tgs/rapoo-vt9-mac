"""Extract an NSIS installer whose blocks use 8-byte length fields.

The Rapoo installer (RapooGameDevDriver_Setup_1.6.29) uses an NSIS build where
each block is framed by a 64-bit length (bit 63 = deflate-compressed) instead of
the usual 32-bit one, so 7-Zip and The Unarchiver both refuse it.

Usage: python3 -I nsis64_extract.py <nsis data block "[0]"> <empty output dir>

The NSIS header is parsed for EW_EXTRACTFILE / SetOutPath entries so files get
their real names. Never executes anything from the installer.
"""
import collections
import os
import struct
import sys
import zlib

blob = open(sys.argv[1], 'rb').read()
out_root = sys.argv[2]
os.makedirs(out_root, exist_ok=True)

FIRST = 28                     # flags, sig, "NullsoftInst", header len, data len
assert blob[4:20] == b'\xef\xbe\xad\xdeNullsoftInst'
hdr_len, data_len = struct.unpack_from('<II', blob, 20)


def read_block(pos):
    """Return (payload, next_pos) for the 8-byte-framed block at pos."""
    v = struct.unpack_from('<Q', blob, pos)[0]
    compressed, size = bool(v >> 63), v & ((1 << 63) - 1)
    raw = blob[pos + 8:pos + 8 + size]
    if compressed:
        return zlib.decompressobj(-15).decompress(raw), pos + 8 + size
    return raw, pos + 8 + size


# The header block sits after 8 unknown bytes (zeros) following the first header.
hdr, data_start = read_block(FIRST + 8)
assert len(hdr) == hdr_len, (len(hdr), hdr_len)

# Walk all data blocks once: offset (relative to data_start) -> payload.
blocks = {}
pos = data_start
while pos + 8 <= len(blob):
    rel = pos - data_start
    try:
        payload, nxt = read_block(pos)
    except Exception as e:  # trailing bytes / CRC
        break
    blocks[rel] = payload
    pos = nxt

# Header: flags (4) then 8 x (offset, count).
names = ['pages', 'sections', 'entries', 'strings', 'langtables', 'ctlcolors', 'bgfont', 'data']
tab = {n: struct.unpack_from('<II', hdr, 4 + 8 * i) for i, n in enumerate(names)}
ent_off, ent_num = tab['entries']
str_off = tab['strings'][0]

VARS = {20: 'CMDLINE', 21: 'INSTDIR', 22: 'OUTDIR', 23: 'EXEDIR', 24: 'LANGUAGE', 25: 'TEMP',
        26: 'PLUGINSDIR', 27: 'EXEPATH', 28: 'EXEFILE', 29: 'HWNDPARENT', 30: '_CLICK', 31: '_OUTDIR'}


def nsis_str(idx):
    """Decode a Unicode NSIS string at character index idx."""
    p = str_off + idx * 2
    out = []
    while p + 1 < len(hdr):
        ch = struct.unpack_from('<H', hdr, p)[0]
        p += 2
        if ch == 0:
            break
        if ch in (1, 2, 3, 4):           # LANG, SHELL, VAR, SKIP codes + one parameter
            param = struct.unpack_from('<H', hdr, p)[0]
            p += 2
            if ch == 3:
                # 14-bit index packed as two 7-bit halves with the 0x8080 marker bits
                n = (param & 0x7F) | ((param & 0x7F00) >> 1)
                out.append('$' + VARS.get(n, (f'{n}' if n < 10 else f'R{n - 10}' if n < 20 else f'V{n}')))
            elif ch == 2:
                out.append(f'$SHELL{param:04x}')
            elif ch == 1:
                out.append(f'$(LANG{param})')
            else:
                out.append(chr(param))
            continue
        out.append(chr(ch))
    return ''.join(out)


# This build stores 9 ints per entry (opcode + 8 params); verified because
# entries_offset + count * 36 == strings_offset.
ENTRY_INTS = (str_off - ent_off) // ent_num // 4
assert ent_off + ent_num * ENTRY_INTS * 4 == str_off, ENTRY_INTS
entries = [struct.unpack_from(f'<{ENTRY_INTS}i', hdr, ent_off + ENTRY_INTS * 4 * i) for i in range(ent_num)]

# Find the EW_EXTRACTFILE opcode: the opcode whose parm2 values hit block offsets most.
# Ignore opcode 0 and data offset 0: zero-filled entries collide with block 0.
hits = collections.Counter(e[0] for e in entries if e[0] != 0 and e[3] in blocks and e[3] > 0)
extract_op = 20 if hits.get(20) else hits.most_common(1)[0][0]   # EW_EXTRACTFILE is 20 in NSIS 3
# SetOutPath is EW_CREATEDIR (one below EW_IFFILEEXISTS, nine below EW_EXTRACTFILE in NSIS 3).
createdir_op = extract_op - 9

outdir = '$INSTDIR'
written = []
for e in entries:
    op, p = e[0], e[1:]
    if op == createdir_op and p[1] != 0:          # SetOutPath
        outdir = nsis_str(p[0])
    elif op == extract_op and p[2] in blocks:
        name = nsis_str(p[1])
        full = name if ('\\' in name or name.startswith('$')) else outdir + '\\' + name
        rel = full.replace('$INSTDIR', 'INSTDIR').replace('$PLUGINSDIR', '_PLUGINSDIR').replace('$', '_')
        rel = rel.replace('\\', '/').lstrip('/')
        dest = os.path.join(out_root, rel)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, 'wb') as f:
            f.write(blocks[p[2]])
        written.append((rel, len(blocks[p[2]])))

print(f"entry size {ENTRY_INTS} ints; header {len(hdr)} bytes, {ent_num} entries, {len(blocks)} data blocks, "
      f"extract opcode {extract_op}, setoutpath opcode {createdir_op}")
print(f"wrote {len(written)} files, {sum(s for _, s in written):,} bytes")
for rel, size in sorted(written, key=lambda x: -x[1])[:40]:
    print(f"{size:>12,}  {rel}")
