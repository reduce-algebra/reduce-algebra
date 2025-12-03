/* Correctly-rounded arc-tangent for bfloat16 value.

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
#include <math.h> // only used for performance tests

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;

// the following polynomials were generated using Sollya (cf atan.sollya)

/* degree-7 minimax polynomial for atan(x) over [0,0.25], with relative error
   bounded by 2^-25.419, with coefficients of odd degree only, and degree-1
   coefficient forced to 1 */
static const float p0[] = {1.0f, -0x1.55546ep-2, 0x1.98d0e2p-3,
                           -0x1.0c7c54p-3};

/* degree-4 minimax polynomial for atan(x) over [0.25,0.5], with relative error
   bounded by 2^-22.573 */
static const float p1[] = {0x1.411628p-14, 0x1.ff0772p-1, 0x1.1ee658p-6,
                           -0x1.a6fc8ep-2, 0x1.81dd4ap-3};

/* degree-4 minimax polynomial for atan(x) over [0.5,0.75], with relative error
   bounded by 2^-21.757 */
static const float p2[] = {-0x1.95964cp-8, 0x1.0bad76p0, -0x1.e652e2p-4,
                           -0x1.e70ab4p-3, 0x1.a5eb88p-4};

/* degree-4 minimax polynomial for atan(x) over [0.75,1], with relative error
   bounded by 2^-23.027 */
static const float p3[] = {-0x1.f75b16p-6, 0x1.2d3d1p+0, -0x1.882376p-2,
                           0x1.d18c96p-13, 0x1.6aa268p-6};

__bf16 cr_atan_bf16 (__bf16 x)
{
  b32u32_u v = {.f = x};
  uint32_t u = v.u;
  uint32_t au = u & 0x7fffffffu;

#define HALF_PI 0x1.921fb6p+0f

  /* for x >= 0x1.04p+11, atan(x) rounds to the same value as HALF_PI,
     and atan(-x) to the same value as -HALF_PI, cf check_large() in
     atan.sage */
  if (au >= 0x45020000u) { // NaN or Inf or |x| >= 0x1.04p+11
    if (au <= 0x7f800000u) // Inf or |x| >= 0x1.04p+11
      return (au == u) ? HALF_PI : -HALF_PI;
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    return x + x; // will signal invalid for sNaN and return qNaN
  }
  
  float t = v.f;

  // for x < 0 we use atan(-x) = -atan(x)
  int neg = u >> 31;
  static const float Neg[] = {1.0f, -1.0f};
  float s = Neg[neg];
  t = t * s;

  // now t >= 0

  // for x > 1 we use atan(x) = pi/2 - atan(1/x)
  int reduce = au > 0x3f800000u;
  if (reduce) t = 1.0f / t;

  // now 0 <= t <= 1

  const float *p;
  float y;
  if (t <= 0.25f) {
    // for |x| < 0x1.7p-4, atan(x) rounds to x to nearest
    if (!reduce && au <= 0x3db80000u) {
      if (au == 0) return x; // case x = 0
      float res = __builtin_fmaf (x, -0x1p-25f, x);
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* We get underflow for |x| < 2^-126, and for |x| = 2^-126 and
         rounding towards zero. */
      if (au < 0x800000u || (au == 0x800000u && res != x))
        errno = ERANGE; // underflow
#endif
      return res;
    }
    
    p = p0;
    float tt = t * t;
    float c5 = __builtin_fmaf (p[3], tt, p[2]);
    float c1 = __builtin_fmaf (p[1], tt, p[0]);
    c1 = __builtin_fmaf (c5, tt * tt, c1);
    y = t * c1;
  }
  else {
    p = (t <= 0.5f) ? p1 : (t <= 0.75f) ? p2 : p3;
    float c3 = __builtin_fmaf (p[4], t, p[3]);
    float c2 = __builtin_fmaf (c3, t, p[2]);
    y = __builtin_fmaf (p[1], t, p[0]);
    y = __builtin_fmaf (c2, t * t, y);
  }

  if (reduce) y = HALF_PI - y; // argument reconstruction

  if (neg) y = -y;

  return y;
}

// dummy function since GNU libc does not provide it
__bf16 atan_bf16 (__bf16 x) {
  return (__bf16) atanf ((float) x);
}
