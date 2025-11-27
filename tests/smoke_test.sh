#!/bin/sh
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT_DIR"

printf "Building project...\n"
make

printf "Running smoke test (create player, list, exit)...\n"
OUTPUT=$(printf "1\nSmokePlayer\n5\n0\n" | ./bin/main 2>&1 || true)

printf "%s\n" "$OUTPUT" > /tmp/smoke_output.txt

printf "Checking output...\n"
printf "%s\n" "$OUTPUT" | grep -q "created successfully" || { printf "Player creation message not found\n"; exit 2; }
printf "%s\n" "$OUTPUT" | grep -q "SmokePlayer" || { printf "Player 'SmokePlayer' not shown\n"; exit 3; }

printf "Smoke test passed.\n"
