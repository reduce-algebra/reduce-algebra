#!/bin/bash
# Examples of usage:
# DRY=--dry ./ci.sh to only try compilation (of last modified functions)
# FORCE=true DRY=--dry ./ci.sh to only try compilation (of all functions)
# FORCE_FUNCTIONS="xxx yyy" ./ci.sh to force checking xxx and yyy
# CC=clang CFLAGS=-Werror ./ci.sh
# SKIP16=1 ./ci.sh to avoid _Float16 tests
# SKIPBF16=1 ./ci.sh to avoid __bf16 tests (clang 19 does not properly support them)

set -e # We want the above command to potentially fail, only set -e now.

if [ -z "$LAST_COMMIT" ]; then
    LAST_COMMIT="HEAD~"
    if [ -n "$CI_COMMIT_BEFORE_SHA" ] && [ "$CI_COMMIT_BEFORE_SHA" != "0000000000000000000000000000000000000000" ]; then
        LAST_COMMIT="$CI_COMMIT_BEFORE_SHA"
    fi
fi

# use the same order as on https://core-math.gitlabpages.inria.fr/
FUNCTIONS_EXHAUSTIVE=(acosf acosf16 acos_bf16 acoshf acoshf16 acosh_bf16 acospif acospif16 acospi_bf16 asinf asinf16 asin_bf16 asinhf asinhf16 asinh_bf16 asinpif asinpif16 asinpi_bf16 atanf atanf16 atan_bf16 atan2f16 atan2_bf16 atan2pif16 atan2pi_bf16 atanhf atanhf16 atanh_bf16 atanpif atanpif16 atanpi_bf16 cbrtf cbrtf16 cbrt_bf16 compoundf16 compound_bf16 cosf cosf16 cos_bf16 coshf coshf16 cosh_bf16 cospif cospif16 cospi_bf16 erff erff16 erf_bf16 erfcf erfcf16 erfc_bf16 expf expf16 exp_bf16 exp10f exp10_bf16 exp10f16 exp10m1f exp10m1f16 exp2f exp2_bf16 exp2f16 exp2m1f exp2m1f16 exp2m1_bf16 expm1f expm1f16 expm1_bf16 hypotf16 hypot_bf16 lgammaf lgammaf16 lgamma_bf16 logf logf16 log_bf16 log10f log10f16 log10_bf16 log10p1f log10p1f16 log1pf log1pf16 log2f log2f16 log2_bf16 log2p1f log2p1f16 powf16 pow_bf16 rsqrtf rsqrtf16 rsqrt_bf16 sincosf sincosf16 sincos_bf16 sinf sinf16 sin_bf16 sinhf sinhf16 sinh_bf16 sinpif sinpif16 sinpi_bf16 sqrtf16 sqrt_bf16 tanf tanf16 tan_bf16 tanhf tanhf16 tanh_bf16 tanpif tanpif16 tanpi_bf16 tgammaf tgammaf16 tgamma_bf16)
FUNCTIONS_WORST=(acos acosh acospi asin asinh asinpi atan atan2 atan2f atan2pi atan2pif atanh atanpi cbrt cbrtl cbrtq compoundf cos cosh cospi erf erfc exp expl expq exp10 exp10q exp10m1 exp2 exp2l exp2q exp2m1 expm1 expm1q hypot hypotf hypotl hypotq lgamma log logq log10 log10p1 log1p log2 log2l log2p1 pow powf powl rsqrt rsqrtl rsqrtq sin sincos sinh sinpi sqrtq tan tanh tanpi tgamma)
FUNCTIONS_SPECIAL=(acos acosf acosh acospi acospif asin asinh asinpi asinpif atan atanf atan2 atan2f atan2pi atan2pif atanh atanpi atanpif cbrt cbrtl compoundf cos cosh cospi cospif erf erfc erfcf exp expf expl expq exp10 exp10q exp10m1 exp2 exp2l exp2q exp2m1 exp2m1f expm1 expm1q hypot hypotf hypotl hypotq lgamma lgammaf log log10 log10p1 log1p log2 log2l log2p1 pow powf powl rsqrt rsqrtl rsqrtq sin sincos sinh sinpi tan tanh tanpi tanpif tgamma)

echo "Reference commit is $LAST_COMMIT"

check () {
    KIND="$1"
    if [ "$FORCE" != "" ]; then
        doit=1
    elif ! { echo "$FORCE_FUNCTIONS" | tr ' ' '\n' | grep --quiet '^'"$FUNCTION"'$'; } && git diff --quiet "$LAST_COMMIT".. -- src/*/*/$FUNCTION.c; then
        doit=0
    else
        doit=1
    fi
    if [ "$doit" == "1" ] && [ "$SKIP128" == "1" ] && $CC -E src/*/*/$FUNCTION.c | grep -q  __int128; then
        echo "__int128 support is needed for" $FUNCTION "but is not available"
        doit=0
    fi
    if [ "$doit" == "1" ] && [ "$SKIP80" == "1" ] && echo src/*/*/$FUNCTION.c | grep -q binary80; then
        echo "binary80 support is needed for" $FUNCTION "but is not available"
        doit=0
    fi
    if [ "$doit" == "1" ] && [ "$SKIP16" == "1" ] && echo src/*/*/$FUNCTION.c | grep -q binary16; then
        echo "With SKIP16, skipping " $FUNCTION
        doit=0
    fi
    if [ "$doit" == "1" ] && [ "$SKIPBF16" == "1" ] && echo src/*/*/$FUNCTION.c | grep -q binaryb16; then
        echo "With SKIPBF16, skipping " $FUNCTION
        doit=0
    fi
    if [ "$doit" == "1" ] && [ "$SKIPQ" == "1" ] && [ "`basename $FUNCTION q`" != "$FUNCTION" ]; then
        echo "libquadmath is needed for" $FUNCTION "but is not available"
        doit=0
    fi

    if [ "$doit" == "0" ]; then
        echo "Skip $FUNCTION"
    else
        echo "Checking $FUNCTION..."				
	# we want to detect compiler warnings
        EXTRA_CFLAGS="$EXTRA_CFLAGS -Werror"
        EXTRA_CFLAGS=$EXTRA_CFLAGS ./check.sh $DRY "$KIND" "$FUNCTION"
    fi
}

if [ -z "$CC" ]; then
	CC="cc"
fi

if $CC -E $CFLAGS ci/int128test.c -o /dev/null &> /dev/null; then
    echo "Compiler supports __int128"
else
    echo "Compiler lacks __int128 support"
    SKIP128=1
fi

if $CC -E $CFLAGS ci/ldbl80test.c -o /dev/null &> /dev/null; then
    echo "long double is binary80"
else
    echo "long double is not binary80"
    SKIP80=1
fi

if $CC -c $CFLAGS ci/quadmath_test.c -o /dev/null &> /dev/null; then
   echo "Compiler supports libquadmath"
else
   echo "Compiler lacks libquadmath support"
   SKIPQ=1
fi

for FUNCTION in "${FUNCTIONS_EXHAUSTIVE[@]}"; do
    check --exhaustive
done

for FUNCTION in "${FUNCTIONS_WORST[@]}"; do
    check --worst
done

for FUNCTION in "${FUNCTIONS_SPECIAL[@]}"; do
    check --special
done
