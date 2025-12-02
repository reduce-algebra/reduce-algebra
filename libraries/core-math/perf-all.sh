#!/bin/bash
# Usage:
# ./perf-all.sh
# CORE_MATH_QUIET=1 ./perf-all.sh
# CORE_MATH_SIMPLE_STAT=1 ./perf-all.sh (old stat mechanism)

# this is to make the order of functions deterministic
export LC_ALL=C

if [ -z "$CORE_MATH_QUIET" ]; then
    make -s -C src/generic/support clean
    make -s -C src/generic/support all
    $CORE_MATH_LAUNCHER src/generic/support/glibc_version >&2
fi

for u in src/binary*/*/Makefile; do
    f="$(sed -n 's/FUNCTION_UNDER_TEST := //p' $u)"
    echo -n "$f "
    ./perf.sh $f | xargs echo
done
