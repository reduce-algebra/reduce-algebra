/* Correctly-rounded sine of binary32 value.

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

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

/* __builtin_roundeven was introduced in gcc 10:
   https://gcc.gnu.org/gcc-10/changes.html,
   and in clang 17 */
#if ((defined(__GNUC__) && __GNUC__ >= 10) || (defined(__clang__) && __clang_major__ >= 17)) && (defined(__aarch64__) || defined(__x86_64__) || defined(__i386__))
# define roundeven_finite(x) __builtin_roundeven (x)
#else
/* round x to nearest integer, breaking ties to even */
static double
roundeven_finite (double x)
{
  double ix;
# if (defined(__GNUC__) || defined(__clang__)) && (defined(__AVX__) || defined(__SSE4_1__) || (__ARM_ARCH >= 8))
#  if defined __AVX__
   __asm__("vroundsd $0x8,%1,%1,%0":"=x"(ix):"x"(x));
#  elif __ARM_ARCH >= 8
   __asm__ ("frintn %d0, %d1":"=w"(ix):"w"(x));
#  else /* __SSE4_1__ */
   __asm__("roundsd $0x8,%1,%0":"=x"(ix):"x"(x));
#  endif
# else
  ix = __builtin_round (x); /* nearest, away from 0 */
  if (__builtin_fabs (ix - x) == 0.5)
  {
    /* if ix is odd, we should return ix-1 if x>0, and ix+1 if x<0 */
    union { double f; uint64_t n; } u, v;
    u.f = ix;
    v.f = ix - __builtin_copysign (1.0, x);
    if (__builtin_ctz (v.n) > __builtin_ctz (u.n))
      ix = v.f;
  }
# endif
  return ix;
}
#endif

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;
#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif
typedef uint64_t u64;

static double __attribute__((noinline)) rbig(uint32_t u, int *q){
  static const u64 ipi[] = {0xfe5163abdebbc562, 0xdb6295993c439041, 0xfc2757d1f534ddc0, 0xa2f9836e4e441529};
  int e = (u>>23)&0xff, i;
  u64 m = (u&(~0u>>9))|1<<23;
  u128 p0 = (u128)m*ipi[0];
  u128 p1 = (u128)m*ipi[1]; p1 += p0>>64;
  u128 p2 = (u128)m*ipi[2]; p2 += p1>>64;
  u128 p3 = (u128)m*ipi[3]; p3 += p2>>64;
  u64 p3h = p3>>64, p3l = p3, p2l = p2, p1l = p1;
  int64_t a;
  int k = e-124, s = k-23;
  /* in cr_sinf(), rbig() is called in the case 127+28 <= e < 0xff
     thus 155 <= e <= 254, which yields 28 <= k <= 127 and 5 <= s <= 104 */
  if (s<64) {
    i = p3h<<s|p3l>>(64-s);
    a = p3l<<s|p2l>>(64-s);
  } else if(s==64) {
    i = p3l;
    a = p2l;
  } else { /* s > 64 */
    i = p3l<<(s-64)|p2l>>(128-s);
    a = p2l<<(s-64)|p1l>>(128-s);
  }
  int sgn = u; sgn >>= 31;
  int64_t sm = a>>63;
  i -= sm;
  double z = (a^sgn)*0x1p-64;
  i = (i^sgn) - sgn;
  *q = i;
  return z;
}

static inline double rltl(float z, int *q){
  double x = z;
  double idl = -0x1.b1bbead603d8bp-29*x, idh = 0x1.45f306ep+2*x, id = roundeven_finite(idh);
  b64u64_u Q = {.f = 0x1.8p52 + id}; *q = Q.u;
  return (idh - id) + idl;
}

static inline double rltl0(double x, int *q){
  double idh = 0x1.45f306dc9c883p+2*x, id = roundeven_finite(idh);
  b64u64_u Q = {.f = 0x1.8p52 + id}; *q = Q.u;
  return idh - id;
}

static inline float add_sign(float x, float rh, float rl){
  float sgn = __builtin_copysignf(1.0f, x);
  return sgn*rh + sgn*rl;
}

static float __attribute__((noinline)) as_sinf_database(float x, double r){
  static const struct {union{float arg; uint32_t uarg;}; float rh, rl;} st[] = {
    {{0x1.33333p+13}, -0x1.63f4bap-2, -0x1p-27},
    {{0x1.75b8a2p-1}, 0x1.55688ap-1, -0x1p-26},
    {{0x1.4f0654p+0}, 0x1.ee836cp-1, -0x1p-26},
    {{0x1.2d97c8p+3}, -0x1.99bc5ap-26, -0x1p-51},
  };
  b32u32_u t = {.f = x};
  uint32_t ax = t.u&(~0u>>1);
  for(unsigned i=0;i<sizeof(st)/sizeof(st[0]);i++)
    if(__builtin_expect(st[i].uarg == ax, 0)) return add_sign(x, st[i].rh, st[i].rl);
  return r;
}

static const double b[] =
  {0x1.3bd3cc9be45dcp-6, -0x1.03c1f081b0833p-14, 0x1.55d3c6fc9ac1fp-24, -0x1.e1d3ff281b40dp-35};
static const double a[] =
  {0x1.921fb54442d17p-3, -0x1.4abbce6256a39p-10, 0x1.466bc5a518c16p-19, -0x1.32bdc61074ff6p-29};
static const double tb[] =
  {0x0p+0, 0x1.8f8b83c69a60bp-3, 0x1.87de2a6aea963p-2, 0x1.1c73b39ae68c8p-1,
   0x1.6a09e667f3bcdp-1, 0x1.a9b66290ea1a3p-1, 0x1.d906bcf328d46p-1, 0x1.f6297cff75cbp-1,
   0x1p+0, 0x1.f6297cff75cbp-1, 0x1.d906bcf328d46p-1, 0x1.a9b66290ea1a3p-1,
   0x1.6a09e667f3bcdp-1, 0x1.1c73b39ae68c8p-1, 0x1.87de2a6aea963p-2, 0x1.8f8b83c69a60bp-3,
   0x0p+0, -0x1.8f8b83c69a60bp-3, -0x1.87de2a6aea963p-2, -0x1.1c73b39ae68c8p-1,
   -0x1.6a09e667f3bcdp-1, -0x1.a9b66290ea1a3p-1, -0x1.d906bcf328d46p-1, -0x1.f6297cff75cbp-1,
   -0x1p+0, -0x1.f6297cff75cbp-1, -0x1.d906bcf328d46p-1, -0x1.a9b66290ea1a3p-1,
   -0x1.6a09e667f3bcdp-1, -0x1.1c73b39ae68c8p-1, -0x1.87de2a6aea963p-2, -0x1.8f8b83c69a60bp-3};

static float __attribute__((noinline)) as_sinf_big(float x){
  b32u32_u t = {.f = x};
  uint32_t ax = t.u<<1;
  if(__builtin_expect(ax>=0xffu<<24, 0)){ // nan or +-inf
    if(ax<<8) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    return 0.0f/0.0f; // to raise FE_INVALID
  }
  int ia;
  double z = rbig(t.u, &ia);
  double z2 = z*z, z4 = z2*z2;
  double aa = (a[0] + z2*a[1]) + z4*(a[2] + z2*a[3]);
  double bb = (b[0] + z2*b[1]) + z4*(b[2] + z2*b[3]);
  double s0 = tb[ia&31], c0 = tb[(ia+8u)&31];
  double r = s0 + z*(aa*c0 - bb*(z*s0));
  return r;
}

float cr_sinf(float x){
  b32u32_u t = {.f = x};
  uint32_t ax = t.u<<1;
  int ia;
  double z0 = x, z;
  if (__builtin_expect(ax>0x99000000u || ax<0x73000000u, 0)){
    // |x| > 0x1p+26 or |x| < 0x1p-12
    if (__builtin_expect(ax<0x73000000u, 1)){ // |x| < 0x1p-12
      if (__builtin_expect(ax<0x66000000u, 0)){ // |x| < 0x1p-25
	if (__builtin_expect(ax==0u, 0))
	  return x;
        float res = __builtin_fmaf(-x, __builtin_fabsf(x), x);
#ifdef CORE_MATH_SUPPORT_ERRNO
        /* The Taylor expansion of sin(x) at x=0 is x - x^3/6 + o(x^3).
           For |x| > 2^-126 we have no underflow, whatever the rounding mode.
           For |x| < 2^-126, since |sin(x)| < |x|, we always have underflow.
           For |x| = 2^-126, we have underflow for rounding towards zero,
           i.e., when sin(x) rounds to nextbelow(2^-126).
           In summary, we have underflow whenever |x|<2^-126 or |res|<2^-126. */
        if (__builtin_fabsf (x) < 0x1p-126f || __builtin_fabsf (res) < 0x1p-126f)
          errno = ERANGE; // underflow
#endif
        return res;
      }
      return (-0x1.555556p-3f*x)*(x*x) + x;
    }
    return as_sinf_big(x);
  }
  if(__builtin_expect(ax<0x822d97c8u, 1)){
    if (__builtin_expect(ax==0x7e75b8a2u||ax==0x7f4f0654u, 0)) return as_sinf_database(x,0.0);
    z = rltl0(z0, &ia);
  } else {
    if (__builtin_expect(ax==0x8c333330u, 0)) return as_sinf_database(x,0.0);
    z = rltl(z0, &ia);
  }
  double z2 = z*z, z4 = z2*z2;
  double aa = (a[0] + z2*a[1]) + z4*(a[2] + z2*a[3]);
  double bb = (b[0] + z2*b[1]) + z4*(b[2] + z2*b[3]);
  double s0 = tb[ia&31], c0 = tb[(ia+8)&31];
  double r = s0 + aa*(z*c0) - bb*(z2*s0);
  return r;
}
