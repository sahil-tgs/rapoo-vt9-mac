#!/usr/bin/env python3
"""Keep one REA MCP session (one Ghidra analysis) alive and serve queries from a folder.

Usage: python3 rea_daemon.py <binary> <work dir>

    <work dir>/requests/<id>.json   {"name": <tool>, "arguments": {...}}   (written by you)
    <work dir>/responses/<id>.json  the tool's structuredContent           (written here)
    <work dir>/daemon.log           progress

The binary is opened once; Ghidra's auto-analysis runs on the first query and
every later query reuses it. Stop by creating <work dir>/STOP.
"""
import json
import os
import subprocess
import sys
import time

HOME = os.path.expanduser("~")
target, work = os.path.abspath(sys.argv[1]), os.path.abspath(sys.argv[2])
req_dir, resp_dir = os.path.join(work, "requests"), os.path.join(work, "responses")
os.makedirs(req_dir, exist_ok=True)
os.makedirs(resp_dir, exist_ok=True)
log = open(os.path.join(work, "daemon.log"), "a", buffering=1)

env = dict(
    os.environ,
    PATH=f"/opt/homebrew/opt/node@24/bin:/opt/homebrew/opt/openjdk@21/bin:{HOME}/tools/rea/node_modules/.bin:"
    + os.environ.get("PATH", ""),
    GHIDRA_INSTALL_DIR=f"{HOME}/tools/ghidra_12.1.4_PUBLIC",
    JAVA_HOME="/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home",
    REA_GHIDRA_STARTUP_TIMEOUT_MS="5400000",   # 90 min for a 15 MB .text section
    GHIDRA_HEADLESS_MAXMEM="5G",
)
p = subprocess.Popen(["rea", "mcp"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                     stderr=open(os.path.join(work, "rea-stderr.log"), "a"), env=env, text=True, bufsize=1)
next_id = [1]


def request(method, params=None):
    rid = next_id[0]
    next_id[0] += 1
    p.stdin.write(json.dumps({"jsonrpc": "2.0", "id": rid, "method": method, "params": params or {}}) + "\n")
    p.stdin.flush()
    while True:
        line = p.stdout.readline()
        if not line:
            raise RuntimeError("rea mcp exited")
        msg = json.loads(line)
        if msg.get("id") == rid:
            if "error" in msg:
                return {"client_error": msg["error"]}
            r = msg["result"]
            return r.get("structuredContent") or r


def stamp():
    return time.strftime("%H:%M:%S")


request("initialize", {"protocolVersion": "2025-06-18", "capabilities": {},
                       "clientInfo": {"name": "rapoo-teardown", "version": "1.0"}})
p.stdin.write(json.dumps({"jsonrpc": "2.0", "method": "notifications/initialized"}) + "\n")
p.stdin.flush()
def call(name, arguments):
    return request("tools/call", {"name": name, "arguments": arguments})


print(stamp(), "open_binary", json.dumps(call("open_binary", {"path": target, "provider_id": "ghidra"}))[:300], file=log)
t0 = time.time()
first = call("search_procedures", {"pattern": "HidD_", "mode": "literal"})   # triggers analysis
json.dump(first, open(os.path.join(resp_dir, "_warmup_hid_procs.json"), "w"), indent=1)
print(stamp(), f"analysis ready after {time.time() - t0:.0f}s", file=log)
open(os.path.join(work, "READY"), "w").write(stamp())

while not os.path.exists(os.path.join(work, "STOP")):
    pending = sorted(f for f in os.listdir(req_dir) if f.endswith(".json"))
    if not pending:
        time.sleep(0.5)
        continue
    for f in pending:
        path = os.path.join(req_dir, f)
        try:
            req = json.load(open(path))
        except Exception:
            continue            # still being written
        os.remove(path)
        t1 = time.time()
        res = call(req["name"], req.get("arguments", {}))
        tmp = os.path.join(resp_dir, f + ".tmp")
        json.dump(res, open(tmp, "w"), indent=1)
        os.replace(tmp, os.path.join(resp_dir, f))
        print(stamp(), f"{f}: {req['name']} {time.time() - t1:.1f}s", file=log)

call("close_binary", {})
p.stdin.close()
p.wait(timeout=120)
print(stamp(), "stopped", file=log)
