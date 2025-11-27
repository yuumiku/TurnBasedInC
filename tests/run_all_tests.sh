#!/bin/sh
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT_DIR"

printf "Running all tests in %s/tests\n" "$ROOT_DIR"

for t in tests/*.sh; do
    [ "$t" = "tests/run_all_tests.sh" ] && continue
    printf "\n=== %s ===\n" "$t"
    chmod +x "$t" || true
    if sh "$t"; then
        echo "-- $t: PASS"
    else
        echo "-- $t: FAIL"
        exit 1
    fi
done

printf "\nAll tests passed.\n"
