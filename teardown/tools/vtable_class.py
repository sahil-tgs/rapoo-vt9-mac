"""For each function VA, find vtables that contain it and print the MSVC RTTI class name.
Usage: python3 -I vtable_class.py <pe> <func_va> [...]"""
import struct, sys
d = open(sys.argv[1], 'rb').read()
pe = struct.unpack_from('<I', d, 0x3C)[0]; n = struct.unpack_from('<H', d, pe + 6)[0]
opt = struct.unpack_from('<H', d, pe + 20)[0]; base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
secs = []
for i in range(n):
    o = pe + 24 + opt + 40 * i
    secs.append((d[o:o + 8].rstrip(b'\0').decode(),) + struct.unpack_from('<IIII', d, o + 8))
def va2off(va):
    for nm, vs, sva, rs, rp in secs:
        if base + sva <= va < base + sva + max(vs, rs):
            return rp + va - base - sva
def u32(va):
    o = va2off(va)
    return None if o is None or o + 4 > len(d) else struct.unpack_from('<I', d, o)[0]
def cstr(va):
    o = va2off(va)
    return d[o:d.index(b'\0', o)].decode(errors='replace') if o is not None else None
def class_of_vtable_slot(slot_va):
    # walk back to the vtable start: the dword before it points to a Complete Object Locator
    for back in range(0, 400):
        start = slot_va - 4 * back
        col = u32(start - 4)
        if col is None:
            continue
        sig, off, cdoff, td = (u32(col), u32(col + 4), u32(col + 8), u32(col + 12)) if u32(col) is not None else (None,)*4
        if sig == 0 and td is not None:
            name = cstr(td + 8)
            if name and name.startswith('.?AV'):
                return name, start, back
    return None, None, None
rdata = [s for s in secs if s[0] == '.rdata'][0]
r_off, r_size, r_va = rdata[4], rdata[3], base + rdata[2]
blob = d[r_off:r_off + r_size]
for fa in sys.argv[2:]:
    f = int(fa, 16)
    key = struct.pack('<I', f)
    i = 0; found = False
    while True:
        i = blob.find(key, i)
        if i < 0: break
        if i % 4 == 0:
            slot = r_va + i
            name, start, idx = class_of_vtable_slot(slot)
            print(f"{fa}: slot {slot:#x} -> class {name} vtable {start and hex(start)} index {idx}")
            found = True
        i += 1
    if not found:
        print(f"{fa}: no vtable slot found")
