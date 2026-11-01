#!/usr/bin/env python3
"""Talk to the Rapoo VT9 mouse through the running "Rapoo VT9" app's dev console.

The app (which has Input Monitoring) owns the HID connection; this client sends
lines to its owner-only Unix socket and prints what comes back.

    rapoo_console.py status
    rapoo_console.py listen 5                 # print vendor input reports for 5 s
    rapoo_console.py tx "bb 01 02" [wait_ms]  # send one output report, print replies
    rapoo_console.py script file.txt          # one "tx ..." or "sleep ms" per line
"""
import os
import socket
import sys
import time

SOCK = os.path.expanduser("~/Library/Application Support/RapooVT9/console.sock")


def connect():
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    s.connect(SOCK)
    s.settimeout(0.05)
    return s


def drain(s, seconds, out):
    end = time.time() + seconds
    buf = b""
    while time.time() < end:
        try:
            chunk = s.recv(65536)
            if not chunk:
                break
            buf += chunk
            while b"\n" in buf:
                line, buf = buf.split(b"\n", 1)
                out.append(line.decode(errors="replace"))
                print(f"{time.strftime('%H:%M:%S')}.{int(time.time() * 1000) % 1000:03d}  {out[-1]}", flush=True)
        except socket.timeout:
            pass


def main():
    cmd = sys.argv[1]
    s = connect()
    out = []
    if cmd == "status":
        s.sendall(b"status\n")
        drain(s, 0.5, out)
    elif cmd == "raw":                      # send one console line verbatim, e.g. "xfer ba a5 a3"
        s.sendall((" ".join(sys.argv[2:-1] if sys.argv[-1].isdigit() else sys.argv[2:]) + "\n").encode())
        drain(s, (int(sys.argv[-1]) if sys.argv[-1].isdigit() else 1500) / 1000, out)
    elif cmd == "listen":
        drain(s, float(sys.argv[2]) if len(sys.argv) > 2 else 5, out)
    elif cmd == "tx":
        s.sendall(f"tx {sys.argv[2]}\n".encode())
        drain(s, (int(sys.argv[3]) if len(sys.argv) > 3 else 400) / 1000, out)
    elif cmd == "script":
        for line in open(sys.argv[2]):
            line = line.split("#")[0].strip()
            if not line:
                continue
            if line.startswith("sleep"):
                drain(s, int(line.split()[1]) / 1000, out)
            else:
                print(f"--> {line}", flush=True)
                s.sendall((line + "\n").encode())
                drain(s, 0.15, out)
        drain(s, 0.5, out)
    s.close()


if __name__ == "__main__":
    main()
