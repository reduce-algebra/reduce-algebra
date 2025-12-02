/* Correctly-rounded reciprocal square root of binary64 value.

Copyright (c) 2022-2025 Alexei Sibidanov.

This file is part of the CORE-MATH project
(https://core-math.gitlabpages.inria.fr/).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <errno.h>
#include <fenv.h> // for FE_TONEAREST, FE_UPWARD, feraiseexcept, FE_INVALID
#include <stdint.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
// fegetexceptflag accesses the FPSR register, which seems to be much slower
// than accessing FPCR, so it should be avoided if possible.
// Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
#if (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
#if defined(_MSC_VER)
#include <arm64intr.h>
#endif

typedef struct
{
  uint16_t res0;
  uint8_t  res1  : 6;
  uint8_t  bit22 : 1;
  uint8_t  bit23 : 1;
  uint8_t  bit24 : 1;
  uint8_t  res2  : 7;
  uint32_t res3;
} fpcr_bitfield;

inline static unsigned int _mm_getcsr(void)
{
  union
  {
    fpcr_bitfield field;
    uint64_t value;
  } r;

#if defined(_MSC_VER) && !defined(__clang__)
  r.value = _ReadStatusReg(ARM64_FPCR);
#else
  __asm__ __volatile__("mrs %0, FPCR" : "=r"(r.value));
#endif
  static const unsigned int lut[2][2] = {{0x0000, 0x2000}, {0x4000, 0x6000}};
  return lut[r.field.bit22][r.field.bit23];
}
#endif  // (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)

static inline int get_rounding_mode (void)
{
  /* Warning: on __aarch64__ (for example cfarm103), FE_UPWARD=0x400000
     instead of 0x800. */
#if (defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  const unsigned flagp = _mm_getcsr ();
  return (flagp&(3<<13))>>3;
#else
  return fegetround ();
#endif
}

#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif

typedef uint64_t u64;
typedef int64_t i64;
typedef union {double f; uint64_t u;} b64u64_u;

static double __attribute__((noinline)) as_rsqrt_refine(double rf, double a){
  b64u64_u ir = {.f = rf}, ia = {.f = a};
  if(ia.u < 1ll<<52){
    i64 nz = __builtin_clzll(ia.u);
    ia.u <<= nz - 11;
    ia.u &= ~0ull>>12;
    i64 e = nz - 12;
    ia.u |= e<<52;
  }
  if(ia.u<<11 == 1ull<<63){
  } else {
    unsigned mode = get_rounding_mode ();
    int e = (ia.u>>52)&1;
    u64 rm, am;
    rm = (ir.u<<11|1ull<<63)>>11;
    am = ((ia.u&(~0ull>>12))|1ull<<52)<<(5-e);
    u128 rt = (u128)rm*am;
    u64 rth = rt>>64, rtl = rt;
    u128 rrt = (u128)rtl*rm;
    u64 t0 = rrt, t1 = (rrt>>64) + rth*rm;
    rrt = (u128)t1<<64|t0;
    i64 s = rrt>>127, dd = 1 - 2*s;
    u128 rts = ((rt<<1)^(-s)) + s;
    u128 prrt;
    u64 am2 = am<<1, am20 = -am;
    do {
      ir.u -= dd;
      prrt = rrt;
      am20 += am2;
      u128 tt = rts - am20;
      rrt -= tt;
    } while(__builtin_expect(!((prrt^rrt)>>127), 0));
    ir.u += (rrt>>127)?0:dd;
    rrt = (rrt>>127)?rrt:prrt;
    if(__builtin_expect(mode==FE_TONEAREST, 1)){
      rm = (ir.u<<11|1ull<<63)>>11;
      rt = (u128)rm*am;
      rrt += am>>2;
      rrt += rt;
      u64 inc = rrt>>127;
      ir.u += inc;
    } else {
      ir.u += mode==FE_UPWARD;
    }
    rf = ir.f;
  }
  return rf;
}

double cr_rsqrt(double x){
  b64u64_u ix = {.f = x};
  double r;
  if(__builtin_expect(ix.u < 1ll<<52, 0)){ // 0 <= x < 0x1p-1022
    if(__builtin_expect(ix.u, 1)){ // x <> +0
      r = __builtin_sqrt(x)/x;
    } else {
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // pole error
#endif
      return 1.0 / 0.0; // case x = +0
    }
  } else if(__builtin_expect(ix.u >= 0x7ffull<<52, 0)){ // NaN, Inf, x <= 0
    if(!(ix.u<<1)) {
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // pole error
#endif
      return 1.0 / -0.0; // x=-0
    }
    if(ix.u > 0xfff0000000000000ull) return x + x; // -NaN
    if(ix.u >> 63){ // x < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      feraiseexcept (FE_INVALID);
      return __builtin_nan("<0");
    }
    if(!(ix.u<<12)) return 0.0; // +/-Inf
    return x + x; // +NaN
  } else { // 0x1p-1022 <= x < 2^1024
    if (__builtin_expect (ix.u > 0x7fd000000000000ull, 0)) // x > 2^1022
      // avoid spurious underflow in 1/x
      r = (4.0 / x) * (0.25 * __builtin_sqrt(x));
    else
      r = (1.0 / x) * __builtin_sqrt(x);
  }
  double rx = r*x, drx = __builtin_fma(r, x, -rx);
  double h = __builtin_fma(r,rx,-1.0) + r*drx, dr = (r*0.5)*h;
  double rf = r - dr;
  dr -= r - rf;
  b64u64_u idr = {.f = dr}, ir = {.f = rf};
  u64 aidr = (idr.u&(~0ull>>1)) - (ir.u & (0x7ffll<<52)) + (0x3fell<<52), mid = (aidr - 0x3c90000000000000 + 16)>>5;
  if(__builtin_expect( mid==0 || aidr<0x39b0000000000000ll || aidr>0x3c9fffffffffff80ll, 0))
    rf = as_rsqrt_refine(rf, x);
  return rf;
}

#ifdef __INTEL_CLANG_COMPILER // rsqrt is called invsqrt with icx
extern double invsqrt (double);
double rsqrt(double x){
  return invsqrt(x);
}
#endif
