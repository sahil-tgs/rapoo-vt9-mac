#!/bin/sh
# follow_call.sh <exe> <addr> [len]: disassemble one function (until ret) without analysis
r2 -q -e scr.color=0 -e asm.bytes=false -e asm.lines=false -e asm.comments=false -c "pD ${3:-0x200} @ $2" "$1" 2>/dev/null | awk '{print} / ret( |$)/{exit}'
