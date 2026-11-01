#!/usr/bin/env python3
"""Send one query to a running rea_daemon.py session and print the result.

Usage: rea_q.py <work dir> <tool> '<json arguments>' [--save name.json] [--raw]
Prints normalized_result (or the whole payload with --raw), truncated to 6000 chars.
"""
import json
import os
import sys
import time
import uuid

work, tool, args = sys.argv[1], sys.argv[2], json.loads(sys.argv[3])
save = sys.argv[sys.argv.index("--save") + 1] if "--save" in sys.argv else None
raw = "--raw" in sys.argv
rid = f"{time.strftime('%H%M%S')}-{uuid.uuid4().hex[:6]}.json"
tmp = os.path.join(work, "requests", rid + ".tmp")
json.dump({"name": tool, "arguments": args}, open(tmp, "w"))
os.replace(tmp, os.path.join(work, "requests", rid))
resp = os.path.join(work, "responses", rid)
t0 = time.time()
while not os.path.exists(resp):
    if time.time() - t0 > 1800:
        sys.exit("timeout")
    time.sleep(0.2)
data = json.load(open(resp))
if save:
    json.dump(data, open(os.path.join(work, save), "w"), indent=1)
out = data if raw else data.get("normalized_result", data)
s = out if isinstance(out, str) else json.dumps(out, indent=1)
print(s[:6000] + ("\n…[truncated]" if len(s) > 6000 else ""))
