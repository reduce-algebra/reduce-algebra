/* Correctly-rounded Euclidean distance function (hypot) for binary32 values.

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
#include <fenv.h> // for fegetround, FE_UPWARD, FE_TONEAREST

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

float cr_hypotf(float x, float y){
  float ax = __builtin_fabsf(x), ay = __builtin_fabsf(y);
  b32u32_u tx = {.f = ax}, ty = {.f = ay};
  if(__builtin_expect(tx.u >= (0xffu<<23) || ty.u >= (0xffu<<23), 0)){
    // either x or y is Inf or NaN
    int snan_x = tx.u > (0xffu<<23) && !((tx.u >> 22) & 1);
    int snan_y = ty.u > (0xffu<<23) && !((ty.u >> 22) & 1);
    if (snan_x || snan_y)
      return x + y; // will return qNaN
    if(tx.u == (0xffu<<23)) return ax;
    if(ty.u == (0xffu<<23)) return ay;
    return ax + ay;
  }
  float at = __builtin_fmaxf(ax, ay), c;
  ay = __builtin_fminf(ax, ay);
  double xd = at, yd = ay, x2 = xd*xd, y2 = yd*yd, r2 = x2 + y2;
  if(__builtin_expect(yd < xd*0x1.fffffep-13, 0))
  {
    /* Since xd<=0x1.fffffep127, we have
       yd < 0x1.fffffep127*0x1.fffffep-13=0x1.fffffc000002p+115,
       thus sqrt(xd^2+yd^2) < 0x1.fffffefffffcdp+127 < 2^128,
       thus for rounding towards zero or downwards, overflow cannot happen. */
    c = __builtin_fmaf(0x1p-13f, ay, at);
#ifdef CORE_MATH_SUPPORT_ERRNO
    /* If we replace v.u > 0x7f7fffffu by c > 0x1.fffffep+127,
       the test fails with gcc 14.2.0 under Debian Linux. */
    b32u32_u v = {.f = c};
    if(v.u > 0x7f7fffffu) errno = ERANGE; // overflow
#endif
    return c;
  }
  double r = __builtin_sqrt(r2);
  b64u64_u t = {.f = r};
  c = r;
  if(t.u>(uint64_t)0x47efffffe0000000ull){ // t > 0x1.fffffep+127
#ifdef CORE_MATH_SUPPORT_ERRNO
    b32u32_u v = {.f = c};
    /* Same trick as above, but here overflow also happens when r >= 2^128
       and rounding towards zero or downwards. */
    if(v.u > 0x7f7fffffu || r >= 0x1p128) errno = ERANGE; // overflow
#endif
    return c;
  }
  if(__builtin_expect(((t.u + 1)&0xfffffff) > 2, 1)) {
#ifdef CORE_MATH_SUPPORT_ERRNO
    // For RNDN, we have underflow when hypot(x,y) < 2^-126*(1-2^-25)
    // FOR RNDZ/RNDD, we have underflow when hypot(x,y) < 2^-126
    // For RNDU, we have underflow when hypot(x,y) < 2^-126*(1-2^-24)
    double thres = (fegetround () == FE_TONEAREST) ? 0x1.ffffffp-127
      : (fegetround () == FE_UPWARD) ? 0x1.fffffep-127
      : 0x1p-126;
    if (t.f < thres)
      errno = ERANGE; // underflow
#endif
    return c;
  }
  double cd = c;
  if((cd*cd - x2) - y2 == 0.0) return c;
  double ir2 = 0.5/r2, dr2 = (x2 - r2) + y2;
  double rs = r*ir2, dz = dr2 - __builtin_fma(r, r, -r2), dr = rs*dz;
  double rh = r + dr, rl = dr + (r - rh);
  t.f = rh;
  if(__builtin_expect((t.u&0xfffffff) == 0, 1)){
    if(rl>0.0) t.u += 1;
    if(rl<0.0) t.u -= 1;
  }
  return t.f;
}
