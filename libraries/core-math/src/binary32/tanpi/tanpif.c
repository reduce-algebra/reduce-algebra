/* Correctly-rounded tangent of binary32 value for angles in half-revolutions

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
#include <fenv.h> // for feraiseexcept, FE_INVALID

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

/* __builtin_roundeven was introduced in gcc 10:
   https://gcc.gnu.org/gcc-10/changes.html,
   and in clang 17 */
#if ((defined(__GNUC__) && __GNUC__ >= 10) || (defined(__clang__) && __clang_major__ >= 17)) && (defined(__aarch64__) || defined(__x86_64__) || defined(__i386__))
# define roundevenf_finite(x) __builtin_roundevenf (x)
#else
/* round x to nearest integer, breaking ties to even */
static float
roundevenf_finite (float x)
{
  float ix;
# if (defined(__GNUC__) || defined(__clang__)) && (defined(__AVX__) || defined(__SSE4_1__) || (__ARM_ARCH >= 8))
#  if defined __AVX__
   __asm__("vroundss $0x8,%1,%1,%0":"=x"(ix):"x"(x));
#  elif __ARM_ARCH >= 8
   __asm__ ("frintn %s0, %s1":"=w"(ix):"w"(x));
#  else /* __SSE4_1__ */
   __asm__("roundss $0x8,%1,%0":"=x"(ix):"x"(x));
#  endif
# else
  ix = __builtin_roundf (x); /* nearest, away from 0 */
  if (__builtin_fabsf (ix - x) == 0.5)
  {
    /* if ix is odd, we should return ix-1 if x>0, and ix+1 if x<0 */
    union { float f; uint32_t n; } u, v;
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

float cr_tanpif(float x){
  b32u32_u ix = {.f = x};
  uint32_t e = ix.u&(0xff<<23);
  if(__builtin_expect(e > (150<<23), 0)){ // |x| > 2^23
    if(e==(0xff<<23)){ // x = nan or inf
      if(!(ix.u << 9)){ // x = inf
#ifdef CORE_MATH_SUPPORT_ERRNO
	errno = EDOM;
#endif
	feraiseexcept (FE_INVALID);
	return __builtin_nanf("inf");
      }
      return x + x; // x = nan
    }
    return __builtin_copysign(0.0f, x);
  }
  float x4 = 4.0f*x, nx4 = roundevenf_finite(x4), dx4 = x4-nx4;
  float ni = roundevenf_finite(x), zf = x-ni;
  if(__builtin_expect(dx4 == 0.0f, 0)){ // 4*x integer
    int k = x4;
    if(k&1) return __builtin_copysignf(1.0f,zf); // x = 1/4 mod 1/2
    k &= 6;
    if(k==0) return  __builtin_copysignf(0.0f,x); // x = 0 mod 2
    if(k==4) return  -__builtin_copysignf(0.0f,x); // x = 1 mod 2
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    if(k==2) return  1.0f/0.0f; // x = 1/2 mod 2
    // now necessarily k=6
    return -1.0f/0.0f; // x = -1/2 mod 2
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  /* For |x| <= 0x1.45f3p-128, tanpi(x) underflows whatever the rounding mode,
     and for |x| >= nextabove(0x1.45f3p-128) = 0x1.45f308p-128, tanpi(x) does
     not underflow whatever the rounding mode. */
  if (__builtin_fabsf (x) <= 0x1.45f3p-128f)
    errno = ERANGE; // underflow
#endif

  ix.f = zf;
  uint32_t a = ix.u&(~0u>>1);
  // x=0x1.267004p-2 is not correctly rounded for RNDZ/RNDD by the code below
  if(__builtin_expect(a == 0x3e933802u, 0)) return  __builtin_copysignf(0x1.44cfbap+0f,zf) + __builtin_copysignf(0x1p-25f,zf);
  // x=-0x1.e4cd0ap-14 is not correctly rounded for RNDU by the code below
  if(__builtin_expect(a == 0x38f26685u, 0)) return  __builtin_copysignf(0x1.7cc304p-12,zf) + __builtin_copysignf(0x1p-37f,zf);
  double z = zf, z2 = z*z;

  static const double cn[] = {0x1.921fb54442d19p-1, -0x1.1f458b3e1f8d6p-2, 0x1.68a34bd0b8f6ap-6, -0x1.e4866f7a25f99p-13};
  static const double cd[] = {0x1p+0, -0x1.4b4b98d2df3a7p-1, 0x1.8e9926d2bb901p-4, -0x1.a6f77fd847eep-9};
  double z4 = z2*z2, r = (z-z*z2)*((cn[0]+z2*cn[1])+z4*(cn[2]+z2*cn[3]))/(((cd[0]+z2*cd[1])+z4*(cd[2]+z2*cd[3]))*(0.25-z2));
  return r;
}
