"""Which QML model binds a given device vtable slot?

The models store std::bind(&KDevice::virtualX, device, _1) in std::function members.
MSVC compiles &KDevice::virtualX to a thunk "mov eax,[ecx]; jmp [eax+off]". For each
vtable byte offset given, find those thunks, the functions that take their address,
the member offset the bound function is stored at, and the class that owns that
function (static_metacall -> qt_metacall -> vtable slot 2 -> RTTI name).

Usage: python3 -I slot_users.py <pe> <vtable byte offset> [...]
"""
import re
import struct
import sys

d = open(sys.argv[1], 'rb').read()
pe = struct.unpack_from('<I', d, 0x3C)[0]
n = struct.unpack_from('<H', d, pe + 6)[0]
opt = struct.unpack_from('<H', d, pe + 20)[0]
base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
secs = {}
for i in range(n):
    o = pe + 24 + opt + 40 * i
    nm = d[o:o + 8].rstrip(b'\0').decode()
    vs, va, rs, rp = struct.unpack_from('<IIII', d, o + 8)
    secs[nm] = (base + va, vs, rp, rs)
tva, tvs, trp, trs = secs['.text']
code = d[trp:trp + trs]
rva_, rvs, rrp, rrs = secs['.rdata']
rdata = d[rrp:rrp + rrs]


def va2off(va):
    for sva, vs, rp, rs in secs.values():
        if sva <= va < sva + max(vs, rs):
            return rp + va - sva


def func_start(va):
    # unoptimized MSVC: functions start 16-aligned with "push ebp; mov ebp, esp"
    a = va & ~0xF
    while a > tva:
        if code[a - tva:a - tva + 3] == b'\x55\x8b\xec' and code[a - tva - 1] in (0xCC, 0xC3, 0xC2, 0x00):
            return a
        a -= 16
    return None


def callers(target):
    out = []
    for m in re.finditer(b'\xe8', code):
        src = tva + m.start()
        rel = struct.unpack_from('<i', code, m.start() + 1)[0] if m.start() + 5 <= len(code) else None
        if rel is not None and src + 5 + rel == target:
            out.append(src)
    return out


_call_index = None


def call_index():
    global _call_index
    if _call_index is None:
        idx = {}
        for m in re.finditer(b'\xe8', code):
            s = m.start()
            if s + 5 > len(code):
                continue
            t = tva + s + 5 + struct.unpack_from('<i', code, s + 1)[0]
            if tva <= t < tva + tvs:
                idx.setdefault(t, []).append(tva + s)
        _call_index = idx
    return _call_index


def class_of_metacall(m):
    """m = qt_metacall address -> class names whose vtable slot 2 is m"""
    names = []
    key = struct.pack('<I', m)
    i = 0
    while True:
        i = rdata.find(key, i)
        if i < 0:
            break
        slot_va = rva_ + i
        vt = slot_va - 8
        try:
            col = struct.unpack_from('<I', d, va2off(vt - 4))[0]
            td = struct.unpack_from('<I', d, va2off(col + 12))[0]
            nm = d[va2off(td + 8):va2off(td + 8) + 200].split(b'\0')[0].decode()
            names.append(nm)
        except Exception:
            pass
        i += 1
    return names


ci = call_index()
for arg in sys.argv[2:]:
    off = int(arg, 0)
    if off < 0x80:
        pats = [b'\x8b\x01\xff\x60' + bytes([off])]
    else:
        pats = [b'\x8b\x01\xff\xa0' + struct.pack('<I', off)]
    thunks = []
    for p in pats:
        for m in re.finditer(re.escape(p), code):
            thunks.append(tva + m.start())
    print(f'== vtable +{off:#x} (slot {off // 4}): thunks {[hex(t) for t in thunks]}')
    for t in thunks:
        imm = struct.pack('<I', t)
        for m in re.finditer(re.escape(imm), code):
            ref = tva + m.start()
            f = func_start(ref)
            # member offset: next "add ecx, imm32" after the ref
            tail = code[m.start():m.start() + 80]
            mm = re.search(b'\x81\xc1(....)', tail, re.S)
            member = struct.unpack('<I', mm.group(1))[0] if mm else None
            owners = []
            for c in ci.get(f, []):
                sm = func_start(c)
                for c2 in ci.get(sm, []):
                    mc = func_start(c2)
                    owners += class_of_metacall(mc)
            print(f'   ref {ref:#x} in func {f and hex(f)}  stored at this+{member and hex(member)}  owner {sorted(set(owners))}')
