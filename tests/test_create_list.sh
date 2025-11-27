#!/bin/sh
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT_DIR"

printf "Running test_create_list...\n"
OUTPUT=$(printf "1\nTestPlayer1\n5\n0\n" | ./bin/main 2>&1 || true)
printf "%s\n" "$OUTPUT" > /tmp/smoke_output_create_list.txt

printf "%s\n" "$OUTPUT" | grep -q "created successfully" || { printf "[test_create_list] Player creation message not found\n"; exit 2; }
printf "%s\n" "$OUTPUT" | grep -q "TestPlayer1" || { printf "[test_create_list] Player 'TestPlayer1' not shown\n"; exit 3; }

printf "[test_create_list] passed.\n"
