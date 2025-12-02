/* Correctly-rounded arc-tangent of binary32 value.

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

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;
typedef uint64_t u64;

float cr_atanf(float x){
  const double pi2 = 0x1.921fb54442d18p+0;
  b32u32_u t = {.f = x};
  int e = (t.u>>23)&0xff, gt = e>=127;
  uint32_t ta = t.u & 0x7fffffff;
  if(__builtin_expect(ta >= 0x4c700518u, 0)) { // |x| >= 0x1.e00a3p+25
    if (ta > 0x7f800000u) return x + x; // nan
    return __builtin_copysign(pi2,(double)x); // inf or |x| >= 0x1.e00a3p+25
  }
  if (__builtin_expect(e<127-13, 0)){ // |x| < 2^-13
    if (__builtin_expect(e<127-25, 0)){ // |x| < 2^-25
      if(!(t.u<<1)) return x;
      float res = __builtin_fmaf(-x, __builtin_fabsf(x), x);
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* The Taylor expansion of atan(x) at x=0 is x - x^3/3 + o(x^3).
         For |x| > 2^-126 we have no underflow, whatever the rounding mode.
         For |x| < 2^-126, since |atan(x)| < |x|, we always have underflow.
         For |x| = 2^-126, we have underflow for rounding towards zero,
         i.e., when atan(x) rounds to nextbelow(2^-126).
         In summary, we have underflow whenever |x|<2^-126 or |res|<2^-126. */
      if (__builtin_fabsf (x) < 0x1p-126f || __builtin_fabsf (res) < 0x1p-126f)
        errno = ERANGE; // underflow
#endif
      return res;
    }
    return __builtin_fmaf(-0x1.5555555555555p-2f*x, x*x, x);
  }
  /* now |x| >= 0x1p-13 */
  double z = x;
  if (gt) z = 1/z; /* gt is non-zero for |x| >= 1 */
  double z2 = z*z, z4 = z2*z2, z8 = z4*z4;
  /* polynomials generated using rminimax
     (https://gitlab.inria.fr/sfilip/rminimax) with the following command:
     ./ratapprox --function="atan(x)" --dom=[0.000122070,1] --num=[x,x^3,x^5,x^7,x^9,x^11,x^13] --den=[1,x^2,x^4,x^6,x^8,x^10,x^12] --output=atanf.sollya --log
     (see output atanf.sollya)
     The coefficient cd[0] was slightly reduced from the original value
     0x1.51eccde075d67p-2 to avoid an exceptional case for |x| = 0x1.1ad646p-4
     and rounding to nearest.
  */
  static const double cn[] =
    {0x1.51eccde075d67p-2, 0x1.a76bb5637f2f2p-1, 0x1.81e0eed20de88p-1,
     0x1.376c8ca67d11dp-2, 0x1.aec7b69202ac6p-5, 0x1.9561899acc73ep-9,
     0x1.bf9fa5b67e6p-16};
  static const double cd[] =
    {0x1.51eccde075d66p-2, 0x1.dfbdd7b392d28p-1, 0x1p+0,
     0x1.fd22bf0e89b54p-2, 0x1.d91ff8b576282p-4, 0x1.653ea99fc9bbp-7,
     0x1.1e7fcc202340ap-12};
  double cn0 = cn[0] + z2*cn[1];
  double cn2 = cn[2] + z2*cn[3];
  double cn4 = cn[4] + z2*cn[5];
  double cn6 = cn[6];
  cn0 += z4*cn2;
  cn4 += z4*cn6;
  cn0 += z8*cn4;
  cn0 *= z;
  double cd0 = cd[0] + z2*cd[1];
  double cd2 = cd[2] + z2*cd[3];
  double cd4 = cd[4] + z2*cd[5];
  double cd6 = cd[6];
  cd0 += z4*cd2;
  cd4 += z4*cd6;
  cd0 += z8*cd4;
  double r = cn0/cd0;
  if (!gt) return r; /* for |x| < 1, (float) r is correctly rounded */

#define PI_OVER2_H 0x1.9p0
#define PI_OVER2_L 0x1.0fdaa22168c23p-7
  /* now r approximates atan(1/x), we use atan(x) + atan(1/x) = sign(x)*pi/2,
     where PI_OVER2_H + PI_OVER2_L approximates pi/2.
     With sign(z)*L + (-r + sign(z)*H), it fails for x=0x1.98c252p+12 and
     rounding upward.
     With sign(z)*PI - r, where PI is a double approximation of pi to nearest,
     it fails for x=0x1.ddf9f6p+0 and rounding upward. */
  r = (__builtin_copysign(PI_OVER2_L, z) - r) + __builtin_copysign(PI_OVER2_H, z);
  return r;
}
