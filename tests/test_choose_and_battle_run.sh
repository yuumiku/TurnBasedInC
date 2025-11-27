#!/bin/sh
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT_DIR"

printf "Running test_choose_and_battle_run...\n"
INPUT=$(printf "1\nRunner\n2\n1\n4\n")
OUTPUT=$(printf "%s" "$INPUT" | ./bin/main 2>&1 || true)
printf "%s\n" "$OUTPUT" > /tmp/smoke_output_choose_battle.txt

printf "%s\n" "$OUTPUT" | grep -q "You ran away" || { printf "[test_choose_and_battle_run] 'You ran away' not found\n"; exit 2; }

printf "[test_choose_and_battle_run] passed.\n"
