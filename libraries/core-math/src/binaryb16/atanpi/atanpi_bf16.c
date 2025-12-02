/* Correctly-rounded half-revolution arc-tangent for bfloat16 value.

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

// rounds a float to a __bf16
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

// the following polynomials were generated using Sollya (cf atan.sollya)

/* degree-5 minimax polynomial for atan(x) over [0,0.25], with relative error
   bounded by 2^-19.365, with coefficients of odd degree only, and degree-1
   coefficient forced to 1 */
static const float p0[] = {1.0f, -0x1.551f2ap-2f, 0x1.82264ep-3f};

/* degree-3 minimax polynomial for atan(x) over [0.25,0.5], with relative error
   bounded by 2^-15.881 */
static const float p1[] = {-0x1.90db86p-9f, 0x1.08b988p0f, -0x1.12e4fcp-3f,
  -0x1.1304c6p-3f};

/* degree-3 minimax polynomial for atan(x) over [0.5,0.75], with relative error
   bounded by 2^-17.419 */
static const float p2[] = {-0x1.576262p-6f, 0x1.248264p0f, -0x1.6c86fap-2f,
                           0x1.2c6dc4p-6f};

/* degree-3 minimax polynomial for atan(x) over [0.75,1], with relative error
   bounded by 2^-19.998 */
static const float p3[] = {-0x1.622642p-5f, 0x1.3c169p0f, -0x1.ef1362p-2f,
                           0x1.3cf48ap-4f};

__bf16 cr_atanpi_bf16 (__bf16 x)
{
  b32u32_u v = {.f = bf16_to_float (x)};
  uint32_t u = v.u;
  uint32_t au = u & 0x7fffffffu;

  float st = v.f;

  // for x < 0 we use atan(-x) = -atan(x)
  static const float Neg[] = {1.0f, -1.0f};
  int neg = u >> 31;
  float s = Neg[neg];

#define HALF_LOW 0x1.fffffep-2f

  /* for x >= 0x1.46p+8, atan(x) rounds to the same value as HALF_LOW,
     and atan(-x) to the same value as -HALF_LOW, cf check_large() in
     atanpi.sage */
  if (au >= 0x43a30000u) { // NaN or Inf or |x| >= 0x1.46p+8
    if (au <= 0x7f800000u) // Inf or |x| >= 0x1.46p+8
      return s * ((au == 0x7f800000u) ? 0.5f : HALF_LOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    return x + x; // will signal invalid for sNaN and return qNaN
  }
  
  v.u = au;
  float t = v.f;
  // now t >= 0

  // for x > 1 we use atan(x) = pi/2 - atan(1/x)
  int reduce = au > 0x3f800000u;
  if (reduce) t = 1.0f / t;

  // now 0 <= t <= 1

#define INV_PI 0x1.45f306p-2f

  const float *p;
  float y;
  if (t <= 0.25f) {
    /* for |x| <= 0x1.6cp-7, atanpi(x) rounds to the same value as
       (float) x * INV_PI, cf check_small() in atanpi.sage */
    if (!reduce && au <= 0x3c360000u) {
      if (au == 0) return x; // case x = 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* like for asinpi, we have underflow for |x| < 0x1.92p-125 or
         for |x| = 0x1.92p-125 and rounding toward zero */
      if (au < 0x1490000u || (au == 0x1490000u &&
                              __builtin_fmaf (st, -0x1p-25f, st) != st))
        errno = ERANGE; // underflow
#endif
      // avoid a spurious underflow exception for |x|=0x1.92p-125
      if (au == 0x1490000u)
        return (au == u) ? 0x1.ffd7ap-127f : -0x1.ffd7ap-127f;
      return st * INV_PI;
    }
    
    float tt = t * t;
    float c1 = __builtin_fmaf (p0[1], tt, p0[0]);
    c1 = __builtin_fmaf (p0[2], tt * tt, c1);
    y = t * c1;
  }
  else {
    if (t <= 0.5f)
      p = p1;
    else if (t <= 0.75f)
      p = p2;
    else {
      if (au == 0x3f800000) return s * 0.25f; // |x| = 1
      p = p3;
    }
    float c2 = __builtin_fmaf (p[3], t, p[2]);
    y = __builtin_fmaf (p[1], t, p[0]);
    y = __builtin_fmaf (c2, t * t, y);
  }

#define HALF_PI 0x1.921fb6p+0f
  if (reduce) y = HALF_PI - y; // argument reconstruction

  static const float r[] = {INV_PI, -INV_PI};
  return float_to_bf16 (y * r[neg]);
}

// dummy function since GNU libc does not provide it
__bf16 atanpi_bf16 (__bf16 x) {
  return (__bf16) atanf ((float) x) / (float) M_PI;
}
