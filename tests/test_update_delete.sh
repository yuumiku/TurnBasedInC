#!/bin/sh
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT_DIR"

printf "Running test_update_delete...\n"
INPUT=$(printf "1\nAlice\n1\nBob\n3\n2\nBobby\n4\n1\n5\n0\n")
OUTPUT=$(printf "%s" "$INPUT" | ./bin/main 2>&1 || true)
printf "%s\n" "$OUTPUT" > /tmp/smoke_output_update_delete.txt

printf "%s\n" "$OUTPUT" | grep -q "created successfully" || { printf "[test_update_delete] creation messages missing\n"; exit 2; }
printf "%s\n" "$OUTPUT" | grep -q "Bobby" || { printf "[test_update_delete] updated name 'Bobby' not found\n"; exit 3; }
printf "%s\n" "$OUTPUT" | grep -q "deleted" || { printf "[test_update_delete] delete confirmation not found\n"; exit 4; }

printf "[test_update_delete] passed.\n"
