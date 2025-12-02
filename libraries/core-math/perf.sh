#!/usr/bin/env bash
# Usage: ./perf.sh acos

set -e

export LC_ALL=C.UTF-8

S=20 # trial
N=${PERF_COUNT:-100000} # count
M=${PERF_REPEAT:-500} # repeat

if [ -z "$CORE_MATH_QUIET" ]; then
{ read -r -d '' prog_end || true; } <<EOF
END {
  s = 0;
  nout = int(5*i/100);
  for(k = 1; k < i-nout; k++){
    d = a[k] - a[0];
    s += d*d;
  }
  rms = sqrt(s/(i-nout-1));
  nmd = a[int(i/2)] - a[0];
  printf "Ntrial = %d ; Min = %.3f + %.3f clc/call; Median-Min = %.3f clc/call; Max = %.3f clc/call;\n", i, a[0], rms, nmd, a[i-1];
}
EOF
else
{ read -r -d '' prog_end || true; } <<EOF
END {
  s = 0;
  nout = int(5*i/100);
  for(k = 1; k < i-nout; k++){
    d = a[k] - a[0];
    s += d*d;
  }
  rms = sqrt(s/(i-nout-1));
  nmd = a[int(i/2)] - a[0];
  printf "%.3f\n", a[0];
}
EOF
fi

prog_bar () {
    local T=$1 i=$2
    local p=$(( i * 100 / T ))
    local j=$(( T - i ))
    printf "[%s%s] %3d %%\r" "${str_hsh:0:${i}}" "${str_dot:0:${j}}" $p
    if (( i == T )); then
       echo
    fi
}

collect_perf_stat () {
    echo -n "" > $LOG_FILE
    if [ -z "$CORE_MATH_QUIET" ]; then
        prog_bar $S 0
    fi
    local i=1
    while [ $i -le $S ]; do
        perf stat -e cycles -x " " $CORE_MATH_LAUNCHER ./perf $PERF_ARGS &>> $LOG_FILE
        if [ -z "$CORE_MATH_QUIET" ]; then
            prog_bar $S $i
        fi
        i=$(( i + 1 ))
    done
}
process_perf_stat () {
    sort -g -k 1 $LOG_FILE | awk "/cycles/{a[i++]=\$1/(${N}*${M});} ${prog_end}"
}
perform_perf_stat () {
    perf stat -e cycles -x " " $CORE_MATH_LAUNCHER ./perf $PERF_ARGS 2>&1 | awk "/cycles/{print \$1/(${N}*${M})}"
}
proc_perf () {
    if [ -z "$CORE_MATH_SIMPLE_STAT" ]; then
        collect_perf_stat
        process_perf_stat
    else
        perform_perf_stat
    fi
}

collect_rdtsc_stat () {
    echo -n "" > $LOG_FILE
    if [ -z "$CORE_MATH_QUIET" ]; then
        prog_bar $S 0
    fi
    local i=1
    while [ $i -le $S ]; do
        $CORE_MATH_LAUNCHER ./perf $PERF_ARGS &>> $LOG_FILE
        if [ -z "$CORE_MATH_QUIET" ]; then
            prog_bar $S $i
        fi
        i=$(( i + 1 ))
    done
}
process_rdtsc_stat () {
    sort -g $LOG_FILE | awk "{a[i++]=\$1;} ${prog_end}"
}
perform_rdtsc_stat () {
    $CORE_MATH_LAUNCHER ./perf $PERF_ARGS
}
proc_rdtsc () {
    if [ -z "$CORE_MATH_SIMPLE_STAT" ]; then
        collect_rdtsc_stat
        process_rdtsc_stat
    else
        perform_rdtsc_stat
    fi
}

has_symbol () {
    [ "$(nm "$LIBM" | while read a b c; do if [ "$c" = "$f" ]; then echo OK; return; fi; done | wc -l)" -ge 1 ]
}

RANDOMS_FILE="$(mktemp /tmp/core-math.XXXXXX)"
LOG_FILE="$(mktemp /tmp/core-math.XXXXXX)"
# trap "rm -f $RANDOMS_FILE $LOG_FILE" 0

f=$1
u="$(echo src/binary*/*/$f.c)"

if [ -z "$CORE_MATH_PERF_MODE" ]; then
    if [ -z "$CORE_MATH_QUIET" ]; then
        echo 'CORE_MATH_PERF_MODE (perf or rdtsc) environment variable is not set. The default is perf.'
    fi
    CORE_MATH_PERF_MODE=perf
fi

if [ -f "$u" ]; then
    dir="${u%/*}"
else
    echo "Unknown function: $f"
    exit 2
fi

# for clang we might want to add -ffp-contract=on to enable FMA
if [ "$CFLAGS" == "" ]; then
   CFLAGS="-O3 -march=native"
   ROUNDING_MATH="-frounding-math"
   if [ "$CC" == "icx" ]; then
      # for icx we need to add -fp-model=strict for full IEEE 754 support
      # and we don't need -frounding-math (which does slow down acoshf for example)
      CFLAGS="-O3 -fp-model=strict"
      ROUNDING_MATH=
   fi
fi
CFLAGS="$CFLAGS $EXTRA_CFLAGS"
export CFLAGS ROUNDING_MATH

if [ -n "$LIBM" ]; then
    BACKUP_LIBM="$LIBM"
    unset LIBM
fi

if [ -z "$CORE_MATH_QUIET" ]; then
    make -s -C src/generic/support clean
    make -s -C src/generic/support all
    $CORE_MATH_LAUNCHER src/generic/support/glibc_version >&2
    str_hsh=""
    str_dot=""
    i=1
    while [ $i -le $S ]; do
        str_hsh="${str_hsh}#"
        str_dot="${str_dot}."
        i=$(( i + 1 ))
    done
fi

cd $dir
make -s clean
make -s perf

# prepare random arguments for performance test
./perf --file ${RANDOMS_FILE} --count ${N} --reference

PERF_ARGS="${PERF_ARGS} --file ${RANDOMS_FILE} --count ${N} --repeat ${M}"

if [ "$CORE_MATH_PERF_MODE" = perf ]; then
    proc_perf

    PERF_ARGS="${PERF_ARGS} --libc"
    proc_perf

elif [ "$CORE_MATH_PERF_MODE" = rdtsc ]; then
    PERF_ARGS="${PERF_ARGS} --rdtsc"
    proc_rdtsc

    PERF_ARGS="${PERF_ARGS} --libc"
    proc_rdtsc
fi

has_symbol () {
    [ "$(nm "$LIBM" | while read a b c; do if [ "$c" = "$f" ]; then echo OK; return; fi; done | wc -l)" -ge 1 ]
}

if [ -n "$BACKUP_LIBM" ]; then
    export LIBM="$BACKUP_LIBM"
    if has_symbol; then
        PERF_ARGS="${PERF_ARGS} --libc"
        make -s clean
        make -s perf
        if [ "$CORE_MATH_PERF_MODE" = perf ]; then
            proc_perf

        elif [ "$CORE_MATH_PERF_MODE" = rdtsc ]; then
            PERF_ARGS="${PERF_ARGS} --rdtsc"
            proc_rdtsc
        fi
    elif [ -z "$CORE_MATH_QUIET" ]; then
        echo "$f is not present in $LIBM; skipping" >&2
    fi
fi
