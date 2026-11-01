"""Find code that references given strings in a 32-bit PE, without full analysis.

For each string, compute its virtual address and scan .text for that address
used as a 4-byte immediate (push imm32, mov reg/mem imm32, lea, ...).

Usage: python3 -I string_xrefs.py <pe> <string> [<string> ...]
"""
import struct
import sys

pe_path, needles = sys.argv[1], sys.argv[2:]
d = open(pe_path, 'rb').read()
pe = struct.unpack_from('<I', d, 0x3C)[0]
nsec = struct.unpack_from('<H', d, pe + 6)[0]
optsz = struct.unpack_from('<H', d, pe + 20)[0]
image_base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
sections = []
for i in range(nsec):
    off = pe + 24 + optsz + 40 * i
    name = d[off:off + 8].rstrip(b'\0').decode()
    vsize, va, rawsize, rawptr = struct.unpack_from('<IIII', d, off + 8)
    sections.append((name, va, vsize, rawptr, rawsize))


def off_to_va(o):
    for name, va, vsize, rawptr, rawsize in sections:
        if rawptr <= o < rawptr + rawsize:
            return image_base + va + (o - rawptr)
    return None


text = next(s for s in sections if s[0] == '.text')
t_raw, t_size, t_va = text[3], text[4], text[1]
code = d[t_raw:t_raw + t_size]

for needle in needles:
    nb = needle.encode()
    start = 0
    found_any = False
    while True:
        i = d.find(nb + b'\0', start)
        if i < 0:
            break
        start = i + 1
        # must be the start of a C string
        if i > 0 and d[i - 1] != 0:
            continue
        va = off_to_va(i)
        if va is None:
            continue
        found_any = True
        imm = struct.pack('<I', va)
        refs = []
        j = 0
        while True:
            j = code.find(imm, j)
            if j < 0:
                break
            refs.append(image_base + t_va + j)
            j += 1
        print(f"{needle!r} @ {va:#x}: {len(refs)} code refs " + " ".join(f"{r:#x}" for r in refs[:12]))
    if not found_any:
        print(f"{needle!r}: string not found as a C string")
