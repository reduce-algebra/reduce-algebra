/* Correctly-rounded 10^x function for binary32 value.

Copyright (c) 2023-2025 Alexei Sibidanov.

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

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

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

float cr_exp10f(float x){
  static const double c[] =
    {0x1.62e42fefa39efp-1, 0x1.ebfbdff82c58fp-3, 0x1.c6b08d702e0edp-5,
     0x1.3b2ab6fb92e5ep-7, 0x1.5d886e6d54203p-10, 0x1.430976b8ce6efp-13};
  static const double b[] =
    {1, 0x1.62e42fef4c4e7p-6, 0x1.ebfd1b232f475p-13, 0x1.c6b19384ecd93p-20};
  static const uint64_t tb[] =
    {0x3ff0000000000000, 0x3ff059b0d3158574, 0x3ff0b5586cf9890f, 0x3ff11301d0125b51,
     0x3ff172b83c7d517b, 0x3ff1d4873168b9aa, 0x3ff2387a6e756238, 0x3ff29e9df51fdee1,
     0x3ff306fe0a31b715, 0x3ff371a7373aa9cb, 0x3ff3dea64c123422, 0x3ff44e086061892d,
     0x3ff4bfdad5362a27, 0x3ff5342b569d4f82, 0x3ff5ab07dd485429, 0x3ff6247eb03a5585,
     0x3ff6a09e667f3bcd, 0x3ff71f75e8ec5f74, 0x3ff7a11473eb0187, 0x3ff82589994cce13,
     0x3ff8ace5422aa0db, 0x3ff93737b0cdc5e5, 0x3ff9c49182a3f090, 0x3ffa5503b23e255d,
     0x3ffae89f995ad3ad, 0x3ffb7f76f2fb5e47, 0x3ffc199bdd85529c, 0x3ffcb720dcef9069,
     0x3ffd5818dcfba487, 0x3ffdfc97337b9b5f, 0x3ffea4afa2a490da, 0x3fff50765b6e4540};
  static const float ex[] =
    {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
  const double iln102 = 0x1.a934f0979a371p+6, iln102h = 0x1.a934f09p+1, iln102l = 0x1.e68dc57f2496p-29;
  b32u32_u t = {.f = x};
  double z = x;
  uint32_t ux = t.u<<1;
  if (__builtin_expect(ux>0x84344134u || ux<0x72adf1c6u, 0)){
    // |x| > 0x1.344134p+5 or x=nan or |x| < 0x1.adf1c6p-13
    if(ux < 0x72adf1c6u) // |x| < 0x1.adf1c6p-13
      return 1.0 + z*(0x1.26bb1bbb55516p+1 + z*(0x1.53524c73cea69p+1 + z*0x1.0470591de2ca4p+1));
    if(ux >= 0xffu<<24) { // x is inf or nan
      if(ux > 0xffu<<24) return x + x; // x = nan
      static const float ir[] = {__builtin_inff(), 0.0f};
      return ir[t.u>>31]; // x = +-inf
    }
    if(t.u>0xc23369f4u){ // x < -0x1.66d3e8p+5
      double y = 0x1p-149 + (z + 0x1.66d3e7bd9a403p+5)*0x1.a934f0979a37p-149;
      y = __builtin_fmax(y, 0x1p-151);
      float r = y;
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // underflow
#endif
      return r;
    }
    if(t.u<0x80000000u){ // x > 0x1.344134p+5
      float r = 0x1p127f * 0x1p127f;
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // overflow
#endif
      return r;
    }
  }
  if(__builtin_expect(!(t.u<<12), 0)){
    unsigned k = (t.u >> 20) - 1016;
    if(k<=26){
      unsigned bt = 1<<k, msk = 0x7551101;
      if(bt&msk) return ex[__builtin_popcount(msk&(bt-1))];
    }
  }
  double a = iln102*z, ia = roundeven_finite(a), h = a - ia;
  int64_t ja = ia;
  b64u64_u sv = {.u = tb[ja&0x1f] + ((uint64_t)(ja>>5)<<52)};
  double h2 = h*h, r = ((b[0] + h*b[1]) + h2*(b[2] + h*(b[3])))*(sv.f);
  float ub = r, lb = r - r*1.45e-10;
  if(__builtin_expect(ub != lb, 0)){
    h = (iln102h*z - ia*0.03125) + iln102l*z;
    double s = sv.f;
    h2 = h*h;
    double w = s*h;
    r = s + w*((c[0] + h*c[1]) + h2*((c[2] + h*c[3]) + h2*(c[4] + h*c[5])));
    ub = r;
  }
#ifdef CORE_MATH_SUPPORT_ERRNO
  // for x <= -0x1.2f7032p+5, exp10(x) underflows, whatever the rounding mode
  if (x <= -0x1.2f7032p+5f)
    errno = ERANGE; // underflow
#endif
  return ub;
}
