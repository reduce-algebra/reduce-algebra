/* Correctly-rounded cosine of binary32 value for angles in half-revolutions

Copyright (c) 2022 Alexei Sibidanov.

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

typedef union {float f; uint32_t u;} b32u32_u;

float cr_cospif(float x){
  static const double sn[] = { 0x1.921fb54442d0fp-37, -0x1.4abbce6102b94p-112,  0x1.4669fa3c58463p-189};
  static const double cn[] = {-0x1.3bd3cc9be45cfp-74, 0x1.03c1f08088742p-150, -0x1.55d1e5eff55a5p-228};
  // S[i] approximates sin(i*pi/2^6)
  static const double S[] =
    {0x0p+0, 0x1.91f65f10dd814p-5, 0x1.917a6bc29b42cp-4, 0x1.2c8106e8e613ap-3, 0x1.8f8b83c69a60bp-3, 0x1.f19f97b215f1bp-3,
    0x1.294062ed59f06p-2, 0x1.58f9a75ab1fddp-2, 0x1.87de2a6aea963p-2, 0x1.b5d1009e15ccp-2, 0x1.e2b5d3806f63bp-2,
    0x1.073879922ffeep-1, 0x1.1c73b39ae68c8p-1, 0x1.30ff7fce17035p-1, 0x1.44cf325091dd6p-1, 0x1.57d69348cecap-1,
    0x1.6a09e667f3bcdp-1, 0x1.7b5df226aafafp-1, 0x1.8bc806b151741p-1, 0x1.9b3e047f38741p-1, 0x1.a9b66290ea1a3p-1,
    0x1.b728345196e3ep-1, 0x1.c38b2f180bdb1p-1, 0x1.ced7af43cc773p-1, 0x1.d906bcf328d46p-1, 0x1.e212104f686e5p-1,
    0x1.e9f4156c62ddap-1, 0x1.f0a7efb9230d7p-1, 0x1.f6297cff75cbp-1, 0x1.fa7557f08a517p-1, 0x1.fd88da3d12526p-1,
    0x1.ff621e3796d7ep-1, 0x1p+0, 0x1.ff621e3796d7ep-1, 0x1.fd88da3d12526p-1, 0x1.fa7557f08a517p-1, 0x1.f6297cff75cbp-1,
    0x1.f0a7efb9230d7p-1, 0x1.e9f4156c62ddap-1, 0x1.e212104f686e5p-1, 0x1.d906bcf328d46p-1, 0x1.ced7af43cc773p-1,
    0x1.c38b2f180bdb1p-1, 0x1.b728345196e3ep-1, 0x1.a9b66290ea1a3p-1, 0x1.9b3e047f38741p-1, 0x1.8bc806b151741p-1,
    0x1.7b5df226aafafp-1, 0x1.6a09e667f3bcdp-1, 0x1.57d69348cecap-1, 0x1.44cf325091dd6p-1, 0x1.30ff7fce17035p-1,
    0x1.1c73b39ae68c8p-1, 0x1.073879922ffeep-1, 0x1.e2b5d3806f63bp-2, 0x1.b5d1009e15ccp-2, 0x1.87de2a6aea963p-2,
    0x1.58f9a75ab1fddp-2, 0x1.294062ed59f06p-2, 0x1.f19f97b215f1bp-3, 0x1.8f8b83c69a60bp-3, 0x1.2c8106e8e613ap-3,
    0x1.917a6bc29b42cp-4, 0x1.91f65f10dd814p-5,0x0p+0, -0x1.91f65f10dd814p-5, -0x1.917a6bc29b42cp-4, -0x1.2c8106e8e613ap-3,
    -0x1.8f8b83c69a60bp-3, -0x1.f19f97b215f1bp-3, -0x1.294062ed59f06p-2, -0x1.58f9a75ab1fddp-2, -0x1.87de2a6aea963p-2,
    -0x1.b5d1009e15ccp-2, -0x1.e2b5d3806f63bp-2, -0x1.073879922ffeep-1, -0x1.1c73b39ae68c8p-1, -0x1.30ff7fce17035p-1,
    -0x1.44cf325091dd6p-1, -0x1.57d69348cecap-1, -0x1.6a09e667f3bcdp-1, -0x1.7b5df226aafafp-1, -0x1.8bc806b151741p-1,
    -0x1.9b3e047f38741p-1, -0x1.a9b66290ea1a3p-1, -0x1.b728345196e3ep-1, -0x1.c38b2f180bdb1p-1, -0x1.ced7af43cc773p-1,
    -0x1.d906bcf328d46p-1, -0x1.e212104f686e5p-1, -0x1.e9f4156c62ddap-1, -0x1.f0a7efb9230d7p-1, -0x1.f6297cff75cbp-1,
    -0x1.fa7557f08a517p-1, -0x1.fd88da3d12526p-1, -0x1.ff621e3796d7ep-1,-0x1p+0, -0x1.ff621e3796d7ep-1,
    -0x1.fd88da3d12526p-1, -0x1.fa7557f08a517p-1, -0x1.f6297cff75cbp-1, -0x1.f0a7efb9230d7p-1, -0x1.e9f4156c62ddap-1,
    -0x1.e212104f686e5p-1, -0x1.d906bcf328d46p-1, -0x1.ced7af43cc773p-1, -0x1.c38b2f180bdb1p-1, -0x1.b728345196e3ep-1,
    -0x1.a9b66290ea1a3p-1, -0x1.9b3e047f38741p-1, -0x1.8bc806b151741p-1, -0x1.7b5df226aafafp-1, -0x1.6a09e667f3bcdp-1,
    -0x1.57d69348cecap-1, -0x1.44cf325091dd6p-1, -0x1.30ff7fce17035p-1, -0x1.1c73b39ae68c8p-1, -0x1.073879922ffeep-1,
    -0x1.e2b5d3806f63bp-2, -0x1.b5d1009e15ccp-2, -0x1.87de2a6aea963p-2, -0x1.58f9a75ab1fddp-2, -0x1.294062ed59f06p-2,
    -0x1.f19f97b215f1bp-3, -0x1.8f8b83c69a60bp-3, -0x1.2c8106e8e613ap-3, -0x1.917a6bc29b42cp-4, -0x1.91f65f10dd814p-5};

  b32u32_u ix = {.f = x};
  int32_t e = (ix.u>>23)&0xff;
  if(__builtin_expect(e == 0xff, 0)){
    if(!(ix.u << 9)){
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      feraiseexcept (FE_INVALID);
      return __builtin_nanf("inf");
    }
    return x + x; // nan
  }
  int32_t m = (ix.u&~0u>>9)|1<<23, s = 143 - e, p = e - 112;
  if(__builtin_expect(p<0, 0)) // |x| < 2^-15
  {
    uint32_t ax = ix.u & (~0u>>1);
    // Warning: -0x1.3bd3ccp+2f * x underflows for |x| < 0x1.9f03p-129
    if (ax >= 0x19f030u)
      return __builtin_fmaf (-0x1.3bd3ccp+2f * x, x, 1.0f);
    else // |x| < 0x1.9f03p-129
      return __builtin_fmaf (-x, x, 1.0f);
  }
  if(__builtin_expect(p>31, 0)) {
    if(__builtin_expect(p>63, 0)) return 1.0f;
    int32_t iq = (uint32_t)m << (p - 32);
    return S[(iq+32)&127];
  }
  int32_t k = (uint32_t)m << p;
  if(__builtin_expect(k==0, 0)){
    int32_t iq = m >> (32-p);
    return S[(iq+32)&127];
  }
  double z = k, z2 = z*z;
  double fs = sn[0] + z2*(sn[1] + z2*sn[2]);
  double fc = cn[0] + z2*(cn[1] + z2*cn[2]);
  uint32_t iq = m>>s; iq = (iq + 1)>>1;
  uint32_t is = iq&127, ic = (iq + 32)&127;
  double ts = S[ic], tc = S[is];
  double r = ts + (ts*z2)*fc - (tc*z)*fs;
  return r;
}
