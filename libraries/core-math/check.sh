#!/usr/bin/env bash
# Usages:
# (1) to use check.sh with GNU MPFR installed in a non-standard
#     place, say /tmp/include and /tmp/lib, use the following
#     (LD_LIBRARY_PATH is needed because of dynamic linking):
#     LD_LIBRARY_PATH=/tmp/lib CFLAGS=-I/tmp/include LDFLAGS=-L/tmp/lib ./check.sh ...
# (2) to check the GNU libc instead of CORE-MATH:
#     CORE_MATH_CHECK_STD=true ./check.sh ...
# (3) to check the GNU libc 2.27, installed in say /tmp:
#     CORE_MATH_CHECK_STD=true CORE_MATH_LAUNCHER="/tmp/lib/ld-2.27.so --library-path /tmp/lib" LDFLAGS="-L /tmp/lib" ./check.sh --worst --rndn exp
#     for newer versions of the GNU libc, installed in say /tmp:
#     CORE_MATH_CHECK_STD=true CORE_MATH_LAUNCHER="/tmp/lib/ld-linux-x86-64.so.2 --library-path /tmp/lib:/usr/lib/x86_64-linux-gnu" LDFLAGS="-L /tmp/lib" ./check.sh exp

# ensures CI fails in case of an error
set -e

if [ "`which gmake`" != "" ]; then
   MAKE=gmake
else
   MAKE=make
fi

FUN="${!#}"
ARGS=("${@:1:$#-1}")

MODES=()
for i in "${!ARGS[@]}"; do
    case "${ARGS[i]}" in
        --rnd*)
            MODES+=("${ARGS[i]}")
            unset 'ARGS[i]'
            ;;
        --dry)
            DRY="true"
						unset 'ARGS[i]'
            ;;
    esac
done

if [[ "${#MODES[@]}" -eq 0 ]]; then
    MODES=("--rndn" "--rndz" "--rndu" "--rndd")
fi

FILE="$(echo src/*/*/"$FUN".c)"
ORIG_DIR="$(dirname "$FILE")"

if ! [ -d "$ORIG_DIR" ]; then
    echo "Could not find $FUN"
    exit 1
fi

TMP_DIR="$(mktemp -d -t core-math.XXXXXX)"

trap 'rm -rf "$TMP_DIR"' EXIT

DIR="$TMP_DIR/toto/$(basename "$ORIG_DIR")"

mkdir "$TMP_DIR/toto"
cp -a "$ORIG_DIR" "$ORIG_DIR/../support" "$TMP_DIR/toto"
cp -a "$ORIG_DIR/../../generic" "$TMP_DIR"

if [ -n "${ARGS[0]}" ]; then
    KIND="${ARGS[0]}"
    unset 'ARGS[0]'
else
    SIZE=${FILE#src/}
    if [ ${SIZE:0:7} == "binaryb" ]; then
       SIZE=${SIZE#binaryb}
    else
       SIZE=${SIZE#binary}
    fi
    SIZE=${SIZE%%/*}
	case "$SIZE" in
	16)
		KIND=--exhaustive;;
        32)
	    case "$FUN" in
		atan2f)
		     KIND=--worst;;
		atan2pif)
		     KIND=--worst;;
		compoundf)
		     KIND=--worst;;
		hypotf)
		     KIND=--worst;;
		powf)
		     KIND=--worst;;
		*)
		    KIND=--exhaustive;;
	    esac;;
        *)
            KIND=--worst
    esac
fi

if [[ -z "$CORE_MATH_VERBOSE" ]]; then
    QUIET=--quiet
else
    QUIET=
fi


has_symbol () {
    [ "$(nm "$LIBM" | while read a b c; do if [ "$c" = "$FUN" ]; then echo OK; return; fi; done | wc -l)" -ge 1 ]
}

if [[ -n "$LIBM" ]] && ! has_symbol; then
    echo "Error: symbol $FUN is not present in $LIBM" >&2
    exit 2
fi

if [ "$CFLAGS" == "" ]; then
   MACHINE=`uname -m`
   if [ "$CC" == "clang" ]; then
      # clang does not provide -fsignaling-nans
      # (https://gitlab.inria.fr/core-math/core-math/-/issues/8)
      # -fhonor-nans is needed to disable warnings about __builtin_nan()
      # (https://clang.llvm.org/docs/DiagnosticsReference.html#wnan-infinity-disabled)
      # clang does not define trapping-math by default
      export CFLAGS="-O3 -march=native -Wshadow -fno-finite-math-only -frounding-math -fhonor-nans -ftrapping-math"
   elif [ "$CC" == "icx" ]; then
      # icx needs -fp-model=precise and doesn't like -fsignaling-nans
      export CFLAGS="-fp-model=precise -O3 -march=native -Wshadow -fno-finite-math-only -frounding-math"
   elif [[ $MACHINE == ppc64* ]]; then
      # -march=native is not supported by gcc 14 on ppc64le
      export CFLAGS="-O3 -mcpu=native -Wshadow -fno-finite-math-only -frounding-math -fsignaling-nans"
   else
      # gcc defines trapping-math by default
      export CFLAGS="-O3 -march=native -Wshadow -fno-finite-math-only -frounding-math -fsignaling-nans"
   fi
   unset MACHINE
else
   # the core-math code assumes -frounding-math
   # see also https://gcc.gnu.org/bugzilla/show_bug.cgi?id=34678
   # and https://gcc.gnu.org/bugzilla/show_bug.cgi?id=57245 (fixed in gcc12)
   export ROUNDING_MATH="-frounding-math"
fi

# define CORE_MATH_NO_OPENMP if you don't want OpenMP
if [[ -z "$CORE_MATH_NO_OPENMP" ]]; then
   if [ "$CC" == "icx" ]; then
      OPENMP=-qopenmp # icx prefers -qopenmp
   else
      OPENMP=-fopenmp
   fi
else
   if [ "$CC" == "icx" ]; then
      OPENMP=-qno-openmp # icx prefers -qno-openmp
   else
      OPENMP=-fno-openmp
   fi
   export CFLAGS="$CFLAGS -DCORE_MATH_NO_OPENMP"
fi

# add EXTRA_CFLAGS if given
export CFLAGS="$CFLAGS $EXTRA_CFLAGS"

case "$KIND" in
    --exhaustive)
        "$MAKE" --quiet -C "$DIR" clean
        OPENMP=$OPENMP "$MAKE" $QUIET -C "$DIR" check_exhaustive
        if [[ -z "$DRY" ]]; then
        for MODE in "${MODES[@]}"; do
            echo "Running exhaustive check in $MODE mode..."
            $CORE_MATH_LAUNCHER "$DIR/check_exhaustive" "$MODE" "${ARGS[@]}"
        done
        fi
        ;;
    --worst)
        "$MAKE" --quiet -C "$DIR" clean
        OPENMP=$OPENMP "$MAKE" $QUIET -C "$DIR" check_worst
        if [[ -z "$DRY" ]]; then
        for MODE in "${MODES[@]}"; do
            echo "Running worst cases check in $MODE mode..."
            $CORE_MATH_LAUNCHER "$DIR/check_worst" "$MODE" "${ARGS[@]}" < "${FILE%.c}.wc"
        done
        fi
        ;;
    --special)
        "$MAKE" --quiet -C "$DIR" clean
        OPENMP=$OPENMP "$MAKE" $QUIET -C "$DIR" check_special
        if [[ -z "$DRY" ]]; then
        for MODE in "${MODES[@]}"; do
            echo "Running special checks in $MODE mode..."
            # we also give xxx.wc in input to check --special since some
	    # functions use it (for example log2)
            $CORE_MATH_LAUNCHER "$DIR/check_special" "$MODE" "${ARGS[@]}" < "${FILE%.c}.wc"
        done
        fi
        ;;
    *)
        echo "Unrecognized command"
        exit 1
esac
