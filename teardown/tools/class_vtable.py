"""Print the vtable(s) of an MSVC class by RTTI name.  Usage: python3 -I class_vtable.py <pe> <ClassName> [...]"""
import struct, sys
d = open(sys.argv[1], 'rb').read()
pe = struct.unpack_from('<I', d, 0x3C)[0]; n = struct.unpack_from('<H', d, pe + 6)[0]
opt = struct.unpack_from('<H', d, pe + 20)[0]; base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
secs = [(d[pe+24+opt+40*i:pe+24+opt+40*i+8].rstrip(b'\0').decode(),) + struct.unpack_from('<IIII', d, pe+24+opt+40*i+8) for i in range(n)]
def sec(name): return [s for s in secs if s[0] == name][0]
_, tvs, tva, trs, trp = sec('.text'); _, rvs, rva, rrs, rrp = sec('.rdata'); _, dvs, dva, drs, drp = sec('.data')
text_lo, text_hi = base + tva, base + tva + tvs
rdata = d[rrp:rrp + rrs]; rbase = base + rva
def find_all(blob, key, off_va):
    i = 0
    while True:
        i = blob.find(key, i)
        if i < 0: return
        if i % 4 == 0: yield off_va + i
        i += 1
for cls in sys.argv[2:]:
    name = f'.?AV{cls}@@'.encode() + b'\0'
    i = d.find(name)
    if i < 0: print(cls, 'not found'); continue
    # type descriptor = name - 8; it lives in .data
    td_off = i - 8
    td_va = base + dva + (td_off - drp) if drp <= td_off < drp + drs else None
    print(f'== {cls}: type descriptor {td_va and hex(td_va)}')
    for col_field in find_all(rdata, struct.pack('<I', td_va), rbase):
        col = col_field - 12
        sig = struct.unpack_from('<I', rdata, col - rbase)[0]
        if sig != 0: continue
        off = struct.unpack_from('<I', rdata, col - rbase + 4)[0]
        for ref in find_all(rdata, struct.pack('<I', col), rbase):
            vt = ref + 4
            slots = []
            for k in range(120):
                v = struct.unpack_from('<I', rdata, vt - rbase + 4 * k)[0]
                if not (text_lo <= v < text_hi): break
                slots.append(v)
            print(f'   vtable {vt:#x} (this-offset {off}) {len(slots)} slots:')
            print('   ' + ' '.join(f'{k}:{v:#x}' for k, v in enumerate(slots)))
