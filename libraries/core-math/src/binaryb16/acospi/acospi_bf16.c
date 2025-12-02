/* Correctly-rounded half-revolution arc-cosine for bfloat16 value.

Copyright (c) 2025 Paul Zimmermann

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
#include <math.h> // for sqrtf

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {__bf16 f; uint16_t u;} b16u16_u;

/* convert exactly a __bf16 to float, keeping sNaN
   (the cast float f = x transforms a sNaN into a qNaN) */
static float
bf16_to_float (__bf16 x)
{
  b16u16_u v = {.f = x};
  b32u32_u w = {.u = (uint32_t) v.u << 16};
  return w.f;
}

/* rounds a float to a __bf16. This is slightly faster than the libgcc
   routine, as of GCC 15.2.0. The libgcc routine for float to __b16
   conversion is at libgcc/soft-fp/extendbfsf2.c, and for __bf16 to float
   at libgcc/soft-fp/truncsfbf2.c. The libgcc routines do more work: they
   also emulate FP exceptions (FP_INIT_EXCEPTIONS and FP_HANDLE_EXCEPTIONS)
   which are ABI-specific. */
static __bf16
float_to_bf16 (float x)
{
  b32u32_u w = {.f = x};
  int a = 1.0f - 0x1p-25f == 1.0f;   // true for RNDN and RNDU
  int b = -1.0f + 0x1p-25f == -1.0f; // true for RNDN and RNDD
  b16u16_u v;
  uint16_t frac = w.u; // trailing bits
  switch ((a<<1) | b) {
  case 0: // RNDZ
    v.u = w.u >> 16;
    break;
  case 1: // RNDD
    v.u = (w.u >> 31) ? (w.u >> 16) + (frac != 0) : w.u >> 16;
    break;
  case 2: // RNDU
    v.u = (w.u >> 31) ? w.u >> 16 : (w.u >> 16) + (frac != 0);
    break;
  case 3: // RNDN
    v.u = (frac < 0x8000) ? w.u >> 16
      : (frac > 0x8000) ? (w.u >> 16) + 1
      : (w.u >> 16) + ((w.u >> 16) & 1);
    break;
  }
  return v.f;
}

// the following polynomials were generated using Sollya (cf acos.sollya)

/* degree-3 minimax polynomial for acos(x) over [0,0.25], with relative error
   bounded by 2^-19.783 */
static const float p0[] = {0x1.921fd2p0f, -0x1.000c5cp0f, 0x1.9ed63ap-9f,
                           -0x1.731646p-3f};

/* degree-3 minimax polynomial for acos(x) over [0.25,0.5], with relative error
   bounded by 2^-17.104, manually optimized to reduce the number of exceptions
*/
static const float p1[] = {0x1.92fdc4p0f, -0x1.08e352p0f, 0x1.f5273p-4f,
                           -0x1.4961b2p-2f};

/* degree-3 minimax polynomial for acos(x)/sqrt(1-x) over [0.5,1],
   with relative error bounded by 2^-19.338 */
static const float p2[] = {0x1.91a802p0f, -0x1.9fd22cp-3f, 0x1.e9bcc4p-5f,
                           -0x1.78f01ep-7f};

__bf16 cr_acospi_bf16 (__bf16 x)
{
  b32u32_u v = {.f = bf16_to_float (x)};
  uint32_t u = v.u;
  uint32_t au = u & 0x7fffffffu;

  if (au >= 0x3f800000u) { // NaN, Inf, or |x| >= 1
    if (au == 0x3f800000u)
      return (u == 0x3f800000u) ? 0.0f : 1.0f;
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    if ((au >> 23) == 0x3ff && ((au & 0x7fffff) != 0)) // qNaN or sNaN
      return x;
    return 0.0f / 0.0f; // will signal invalid and return sNaN
  }

  float t, c1, y;

  v.u = au;
  t = v.f;

  if (au < 0x3e800000u) { // |x| < 0.25
    /* avoid a spurious underflow for tiny x:
       for |x| <= 0x1.92p-9, acospi(x) rounds to 0.5 to nearest */
    if (au <= 0x3b490000u) return __builtin_fmaf (x, -0.25f, 0.5f);
    c1 = __builtin_fmaf (p0[2], t, p0[1]);
    y = __builtin_fmaf (p0[3], t * t, c1);
    y = __builtin_fmaf (y, t, p0[0]);
  }
  else if (au < 0x3f000000u) { // 0.25 <= |x| < 0.5
    c1 = __builtin_fmaf (p1[2], t, p1[1]);
    y = __builtin_fmaf (p1[3], t * t, c1);
    y = __builtin_fmaf (y, t, p1[0]);
  }
  else { // 0.5 <= |x| <= 1
    c1 = __builtin_fmaf (p2[2], t, p2[1]);
    y = __builtin_fmaf (p2[3], t * t, c1);
    y = __builtin_fmaf (y, t, p2[0]);
    y = sqrtf (1.0f - t) * y;
  }

#define INV_PI 0x1.45f306p-2f
  y = y * INV_PI;
  // for x < 0, use acospi(-x) = 1 - acospi(x)
  y = (au == u) ? y : 1.0f - y;
  return float_to_bf16 (y);
}

// dummy function since GNU libc does not provide it
__bf16 acospi_bf16 (__bf16 x) {
  return (__bf16) acosf ((float) x) / (float) M_PI;
}
