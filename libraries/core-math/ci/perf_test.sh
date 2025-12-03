#!/bin/sh
export CORE_MATH_PERF_MODE=rdtsc
export CFLAGS="-O3 -march=x86-64-v2 -I/usr/local/include"
export LDFLAGS="-L/usr/local/lib"
./perf.sh expf
./perf.sh exp
./perf.sh expl
./perf.sh sqrtq
