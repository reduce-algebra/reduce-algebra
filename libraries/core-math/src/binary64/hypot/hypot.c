/* Correctly-rounded Euclidean distance function (hypot) for binary64 values.

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

#include <stdint.h>
#include <errno.h>
#include <fenv.h> // for fexcept_t

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

static inline fexcept_t get_flags (void)
{
  /* Warning: on __aarch64__ (for example cfarm103), FE_UPWARD=0x400000
     instead of 0x800. */
#if (defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  return _mm_getcsr ();
#else
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT);
  return flag;
#endif
}

static inline void set_flags (fexcept_t flag)
{
#if (defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  _mm_setcsr (flag);
#else
  fesetexceptflag (&flag, FE_ALL_EXCEPT);
#endif
}

typedef uint64_t u64;
typedef int64_t i64;

#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif
typedef union {double f; u64 u;} b64u64_u;

static inline double fasttwosum(double x, double y, double *e){
  double s = x + y;
  double z = s - x;
  *e = y - z;
  return s;
}

/* This routine deals with the case where both x and y are subnormal.
   a is the encoding of x, and b is the encoding of y.
   We assume x >= y > 0 thus 2^52 > a >= b > 0. */
static double __attribute__((noinline)) as_hypot_denorm(u64 a, u64 b){
  double af = (i64)a, bf = (i64)b;
  int underflow = 0;
  // af and bf are x and y multiplied by 2^1074, thus integers
  a <<= 1;
  b <<= 1;
  u64 rm = __builtin_sqrt(af*af + bf*bf);
  i64 tm = rm << 1;
  i64 D = a*a + b*b - (u64)tm*(u64)tm;
  // D = a^2+b^2 - tm^2
  while (D > 2 * tm) { // tm too small
    D -= 2 * tm + 1;   // (tm+1)^2 = tm^2 + 2*tm + 1
    tm ++;
  }
  while (D < 0) {      // tm too large
    D += 2 * tm - 1;   // (tm-1)^2 = tm^2 - 2*tm + 1
    tm --;
  }
  // tm = floor(sqrt(a^2+b^2)) and 0 <= D = a^2+b^2 - tm^2 < 2*tm+1
  // if D=0 and tm is even, the result is exact
  // if D=0 and tm is odd, the result is a midpoint
  int rb = tm & 1; // round bit for rm
  int rb2 = D >= tm; // round bit for tm
  int sb = D != 0; // sticky bit for rm
  rm = tm >> 1; // truncate the low bit
  underflow = rm < 0x10000000000000ull;
  if(__builtin_expect(rb || sb, 1)){
    double op = 1.0 + 0x1p-54, om = 1.0 - 0x1p-54;
    if(__builtin_expect(op == om, 1)){ // rounding to nearest
      if(__builtin_expect(sb, 1)) {
	rm += rb;
        // we have no underflow when rm is now 2^52 and rb2 != 0
        // Remark: we cannot have a^2+b^2 = (tm+1/2)^2 exactly
        // since this would mean a^2+b^2 = tm^2+tm+1/4,
        // thus a^2+b^2 would be an odd multiple of 2^-1077
        // (since ulp(tm) = 2^-1075)
        if (rm >> 52 && rb2) underflow = 0;
      }
      else // sticky bit is 0, round bit is 1: underflow doos not change
	rm += rm & 1; // even rounding
    } else if (op > 1.0) { // rounding upwards
      rm ++;
      // we have no underflow when rm is now 2^52 and tm was odd
      if (rm >> 52 && (tm & 1)) underflow = 0;
    }
    if(underflow){ // trigger underflow exception _after_ rounding for inexact results
      volatile double trig_uf = 0x1p-1022;
      trig_uf *= trig_uf; // triggers underflow
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // underflow
#endif
    }
  }
  // else the result is exact, and we have no underflow
  b64u64_u xi = {.u = rm};
  return xi.f;
}

/* Here the square root is refined by Newton iterations: x^2+y^2 is exact
   and fits in a 128-bit integer, so the approximation is squared (which
   also fits in a 128-bit integer), compared and adjusted if necessary using
   the exact value of x^2+y^2. */
static double  __attribute__((noinline)) as_hypot_hard(double x, double y, const fexcept_t flag){
  double op = 1.0 + 0x1p-54, om = 1.0 - 0x1p-54;
  b64u64_u xi = {.f = x}, yi = {.f = y};
  u64 bm = (xi.u&(~0ull>>12))|1ll<<52;
  u64 lm = (yi.u&(~0ull>>12))|1ll<<52;
  int be = xi.u>>52;
  int le = yi.u>>52;
  b64u64_u ri = {.f = __builtin_sqrt(x*x + y*y)};
  const int bs = 2;
  u64 rm = (ri.u&(~0ull>>12)); int re = (ri.u>>52)-0x3ff;
  rm |= 1ll<<52;
  for(int i=0;i<3;i++){
    if(__builtin_expect(rm == 1ll<<52,1)){
      rm = ~0ull>>11;
      re--;
    } else
      rm--;
  }
  bm <<= bs;
  u64 m2 = bm*bm;
  int de = be-le;
  int ls = bs-de;
  if(__builtin_expect(ls>=0, 1)){
    lm <<= ls;
    m2 += lm*lm;
  } else {
    u128 lm2 = (u128)lm*lm;
    ls *= 2;
    m2 += lm2 >> -ls; // since ls < 0, the shift by -ls is legitimate
    m2 |= !!(lm2 << (128 + ls));
  }
  int k = bs+re;
  i64 D;
  do {
    rm += 1 + (rm>=(1ll<<53));
    u64 tm = rm << k, rm2 = tm*tm;
    D = m2 - rm2;
  } while(D>0);
  if(D==0){
    set_flags(flag);
  } else {
    if(__builtin_expect(op == om, 1)){
      u64 tm = (rm << k) - (1<<(k-(rm<=(1ll<<53))));
      D = m2 - tm*tm;
      if(__builtin_expect(D != 0, 1))
	rm += D>>63;
      else
	rm -= rm&1;
    } else {
      rm -= (op==1)<<(rm>(1ll<<53));
    }
  }
  if(rm>=(1ull<<53)){
    rm >>= 1;
    re ++;
  }

  i64 e = be - 1 + re;
  xi.u = (e<<52) + rm;
  return xi.f;
}

// case hypot(x,y) >= 2^1024
static double __attribute__((noinline)) as_hypot_overflow (void){
  volatile double z = 0x1.fffffffffffffp1023;
  double f = z + z;
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = ERANGE; // always overflow, whatever the rounding mode
#endif
  return f;
}

double cr_hypot(double x, double y){
  volatile fexcept_t flag = get_flags();
  b64u64_u xi = {.f = x}, yi = {.f = y};
  u64 emsk = 0x7ffll<<52, ex = xi.u&emsk, ey = yi.u&emsk;
  /* emsk corresponds to the upper bits of NaN and Inf (apart the sign bit) */
  x = __builtin_fabs(x), y = __builtin_fabs(y);
  if(__builtin_expect(ex==emsk||ey==emsk, 0)){
    /* Either x or y is NaN or Inf */
    u64 wx = xi.u<<1, wy = yi.u<<1, wm = emsk<<1;
    int ninf = (wx==wm) ^ (wy==wm);
    int nqnn = ((wx>>52)==0xfff) ^ ((wy>>52)==0xfff);
    /* ninf is 1 when only one of x and y is +/-Inf
       nqnn is 1 when only one of x and y is qNaN
       IEEE 754 says that hypot(+/-Inf,qNaN)=hypot(qNaN,+/-Inf)=+Inf. */
    if (ninf && nqnn) return (wx==wm) ? x * x : y * y;
    return x + y; /* inf, nan */
  }
  double u = __builtin_fmax(x,y), v = __builtin_fmin(x,y);
  b64u64_u xd = {.f = u}, yd = {.f = v};
  ey = yd.u;
  if(__builtin_expect(!(ey>>52),0)){ // y is subnormal
    if(!yd.u) return xd.f;
    ex = xd.u;
    if(__builtin_expect(!(ex>>52),0)){ // x is subnormal too
      if(!ex) return 0;
      return as_hypot_denorm(ex,ey);
    }
    int nz = __builtin_clzll(ey);
    ey <<= nz-11;
    ey &= ~0ull>>12;
    ey -= (nz-12ll)<<52;
    b64u64_u t = {.u = ey};
    yd.f = t.f;
  }
  u64 de = xd.u - yd.u;
  if(__builtin_expect(de>(27ll<<52),0)) {
    double r = __builtin_fma(0x1p-27, v, u);
#ifdef CORE_MATH_SUPPORT_ERRNO
    b64u64_u t = {.f = r};
    if (t.u >= 0x7ff0000000000000ull) errno = ERANGE; // overflow
#endif
    return r;
  }
  i64 off = (0x3ffll<<52) - (xd.u & emsk);
  xd.u += off;
  yd.u += off;
  x = xd.f;
  y = yd.f;
  double x2 = x*x, dx2 = __builtin_fma(x,x,-x2);
  double y2 = y*y, dy2 = __builtin_fma(y,y,-y2);
  double r2 = x2 + y2, ir2 = 0.5/r2, dr2 = ((x2 - r2) + y2) + (dx2 + dy2);
  double th = __builtin_sqrt(r2), rsqrt = th*ir2;
  double dz = dr2 - __builtin_fma(th,th,-r2), tl = rsqrt*dz;
  th = fasttwosum(th, tl, &tl);
  b64u64_u thd = {.f = th}, tld = {.f = __builtin_fabs(tl)};
  ex = thd.u;
  ey = tld.u;
  ex &= 0x7ffll<<52;
  u64 aidr = ey + (0x3fell<<52) - ex;
  u64 mid = (aidr - 0x3c90000000000000 + 16)>>5;
  if(__builtin_expect( mid==0 || aidr<0x39b0000000000000ull || aidr>0x3c9fffffffffff80ull, 0)) 
    thd.f = as_hypot_hard(x,y,flag);
  thd.u -= off;
  if(__builtin_expect(thd.u>=(0x7ffull<<52), 0)) return as_hypot_overflow();
  return thd.f;
}
