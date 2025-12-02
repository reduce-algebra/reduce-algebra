/* Correctly-rounded inverse hyperbolic tangent function for binary32 value.

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

static __attribute__((noinline)) float as_special(float x){
  b32u32_u t = {.f = x};
  uint32_t ax = t.u<<1;
  if(ax == 0x7f000000u){ // +-1
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    return x/0.0f; // to raise FE_DIVBYZERO
  }
  if(ax > 0xff000000u) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = EDOM;
#endif
  return 0.0f/0.0f; // to raise FE_INVALID
}

float cr_atanhf(float x){
  // Calculate atanh(x) using the difference of two logarithms -- atanh(x) = (ln(1+x) - ln(1-x))/2
  static const double tr[] = {
    0x1.fc07f02p-1, 0x1.f44659ep-1, 0x1.ecc07b3p-1, 0x1.e573ac9p-1,
    0x1.de5d6e4p-1, 0x1.d77b655p-1, 0x1.d0cb58fp-1, 0x1.ca4b305p-1,
    0x1.c3f8f02p-1, 0x1.bdd2b8ap-1, 0x1.b7d6c3ep-1, 0x1.b20364p-1,
    0x1.ac5701bp-1, 0x1.a6d01a7p-1, 0x1.a16d3f9p-1, 0x1.9c2d14fp-1,
    0x1.970e4f8p-1, 0x1.920fb4ap-1, 0x1.8d3018dp-1, 0x1.886e5f1p-1,
    0x1.83c977bp-1, 0x1.7f405fdp-1, 0x1.7ad2209p-1, 0x1.767dce4p-1,
    0x1.724287fp-1, 0x1.6e1f76bp-1, 0x1.6a13cd1p-1, 0x1.661ec6ap-1,
    0x1.623fa77p-1, 0x1.5e75bb9p-1, 0x1.5ac056bp-1, 0x1.571ed3cp-1,
    0x1.5390949p-1, 0x1.5015015p-1, 0x1.4cab887p-1, 0x1.49539e4p-1,
    0x1.460cbc8p-1, 0x1.42d6626p-1, 0x1.3fb014p-1, 0x1.3c995a4p-1,
    0x1.3991c2cp-1, 0x1.3698df4p-1, 0x1.33ae45bp-1, 0x1.30d1901p-1,
    0x1.2e025cp-1, 0x1.2b404adp-1, 0x1.288b013p-1, 0x1.25e2271p-1,
    0x1.2345679p-1, 0x1.20b470cp-1, 0x1.1e2ef3bp-1, 0x1.1bb4a4p-1,
    0x1.1945381p-1, 0x1.16e0689p-1, 0x1.1485f0ep-1, 0x1.12358e7p-1,
    0x1.0fef011p-1, 0x1.0db20a9p-1, 0x1.0b7e6ecp-1, 0x1.0953f39p-1,
    0x1.073260ap-1, 0x1.05197f8p-1, 0x1.03091b5p-1, 0x1.010101p-1};
  static const double tl[] = {
    0x1.fe02a69106789p-9, 0x1.7b91b1155b11bp-7, 0x1.39e87ba1ebd6p-6, 0x1.b42dd713971bfp-6,
    0x1.16536ee637ae1p-5, 0x1.51b073c96183fp-5, 0x1.8c345da019b21p-5, 0x1.c5e5492abc743p-5,
    0x1.fec912fbbeabbp-5, 0x1.1b72ad33f67ap-4, 0x1.371fc1f6e8f74p-4, 0x1.526e5e5a1b438p-4,
    0x1.6d60fe601d21dp-4, 0x1.87fa06438c911p-4, 0x1.a23bc223ab563p-4, 0x1.bc28673a58cd6p-4,
    0x1.d5c216b8fbb91p-4, 0x1.ef0adcaec5936p-4, 0x1.040259530d041p-3, 0x1.1058bf8d24ad5p-3,
    0x1.1c898c09d99fbp-3, 0x1.2895a13e286a3p-3, 0x1.347dd9a447d55p-3, 0x1.404308716a7e4p-3,
    0x1.4be5f963b78a1p-3, 0x1.5767718015a6cp-3, 0x1.62c82f3a5c795p-3, 0x1.6e08eab13a1e4p-3,
    0x1.792a55fe147a2p-3, 0x1.842d1d9928b17p-3, 0x1.8f11e873a62c7p-3, 0x1.99d958207e08bp-3,
    0x1.a484090c1bb0ap-3, 0x1.af129324b786bp-3, 0x1.b9858970710fbp-3, 0x1.c3dd7a6ddad4dp-3,
    0x1.ce1af0b65f3ebp-3, 0x1.d83e725022f3ep-3, 0x1.e2488197c6c26p-3, 0x1.ec399d3d68ccp-3,
    0x1.f6123fac028acp-3, 0x1.ffd2e07e7f498p-3, 0x1.04bdf9e3b26d2p-2, 0x1.0986f4fa93521p-2,
    0x1.0e4498651cc8cp-2, 0x1.12f719595efbcp-2, 0x1.179eabb0a99a1p-2, 0x1.1c3b81e933c25p-2,
    0x1.20cdcd0e0ab6ep-2, 0x1.2555bcf50f7cbp-2, 0x1.29d37ff34b08bp-2, 0x1.2e47437640268p-2,
    0x1.32b1338401d71p-2, 0x1.37117b5c147b6p-2, 0x1.3b6844a13fc23p-2, 0x1.3fb5b857f6f42p-2,
    0x1.43f9fe2f7ce67p-2, 0x1.48353d11488dfp-2, 0x1.4c679b014ee3ap-2, 0x1.50913cc03686bp-2,
    0x1.54b2468259498p-2, 0x1.58cadb57d7989p-2, 0x1.5cdb1dcaa1765p-2, 0x1.60e32f46788d9p-2};
  static const double ln2n[] = {
    0x1.62e42fedb2a44p-2, 0x1.62e42feeab21ap-1, 0x1.0a2b23f33e789p+0, 0x1.62e42fef27604p+0,
    0x1.bb9d3beb1048p+0, 0x1.0a2b23f37c97ep+1, 0x1.3687a9f1710bcp+1, 0x1.62e42fef657fap+1,
    0x1.8f40b5ed59f38p+1, 0x1.bb9d3beb4e676p+1, 0x1.e7f9c1e942db4p+1, 0x1.0a2b23f39ba79p+2,
    0x1.205966f295e18p+2, 0x1.3687a9f1901b7p+2, 0x1.4cb5ecf08a556p+2, 0x1.62e42fef848f5p+2,
    0x1.791272ee7ec93p+2, 0x1.8f40b5ed79032p+2, 0x1.a56ef8ec733d1p+2, 0x1.bb9d3beb6d77p+2,
    0x1.d1cb7eea67b0fp+2, 0x1.e7f9c1e961eaep+2, 0x1.fe2804e85c24dp+2, 0x1.0a2b23f3ab2f6p+3};
  static const double b[] = {0x1.fffffffce5a6ap-2, -0x1.0001f81ec0ab8p-2, 0x1.555a0f53d79a5p-3};
  static const double s[] = {1,-1};

  b32u32_u t = {.f = x};
  uint32_t ux = t.u, ax = ux<<1;
  if(__builtin_expect(ax<0x7a300000u || ax >= 0x7f000000u, 0)){
    // |x| < 0x1.5a3116p-5 or x is NaN/Inf
    if(__builtin_expect(ax >= 0x7f000000u, 0)) return as_special(x); // NaN/Inf
    if(__builtin_expect(ax < 0x73713744u, 0)) { // |x| < 0x1.f5a956p-12
      if(!ax) return x; // x = +-0
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* The Taylor expansion of atanh(x) at x=0 is x + x^3/3 + o(x^3),
         thus for |x| >= 2^-126 we have no underflow, whatever the
         rounding mode.
         For |x| < 2^-126 and rounding towards zero, we have underflow.
         For x = nextbelow(2^-126) = 0x1.fffffcp-127, atanh(x) would round
         upward to 0x1.fffffep-127 with unbounded exponent range, which is not
         representable, thus we have underflow too.
         In summary, we have underflow whenever |x| < 2^-126. */
      if (__builtin_fabsf (x) < 0x1p-126f)
        errno = ERANGE; // underflow
#endif
      return __builtin_fmaf(x, 0x1p-25f, x); // |x| < 0.000352112(0x1.713744p-12)
    } else { // |x| < 0x1.3p-5
      static const double c[] =
	{0x1.5555555555527p-2, 0x1.9999999ba4ee8p-3, 0x1.24922c280990ap-3, 0x1.c8236aae809c6p-4};
      double z = x, z2 = z*z, z4 = z2*z2, r = c[0] + z2*c[1] + z4*(c[2] + z2*c[3]);
      return z + (z*z2)*r;
    }
  }
  double sgn = s[ux>>31];
  uint32_t e = ax>>24, md = ((ux<<8)|1ul<<31)>>(126-e), mn = -md;
  int nz = __builtin_clz(mn) + 1;
  mn <<= nz;
  unsigned jn = mn>>26, jd = md>>26;
  b64u64_u tn = {.u = ((int64_t)mn<<20) | ((int64_t)1023<<52)},
           td = {.u = ((int64_t)md<<20) | ((int64_t)1023<<52)};
  double zn = tn.f*tr[jn] - 1, zd = td.f*tr[jd] - 1, zn2 = zn*zn, zd2 = zd*zd;
  double rn = ((tl[jn] - ln2n[nz-1]) + zn*b[0]) + zn2*(b[1] + zn*b[2]);
  double rd = (tl[jd] + zd*b[0]) + zd2*(b[1] + zd*b[2]);
  double r = sgn*(rd - rn);
  float ub = r, lb = r + sgn*0.226e-9;
  if(__builtin_expect(ub != lb, 0)){
    static const double c[] =
      {0x1p-1, -0x1.000000000001bp-2, 0x1.55555555555bap-3, -0x1.fffffff26d72ep-4,
       0x1.99999989035p-4, -0x1.555c39cb9ee8p-4, 0x1.24992d8b014a1p-4};
    double zn4 = zn2*zn2, zd4 = zd2*zd2;
    double fn = zn*(((c[0] + zn*c[1]) + zn2*(c[2] + zn*c[3])) + zn4*((c[4] + zn*c[5]) + zn2*c[6]));
    fn += 0x1.0ca86c3898dp-50*nz;
    fn += tl[jn];
    double en = nz*0x1.62e42fefa3ap-2;
    double fd = zd*(((c[0] + zd*c[1]) + zd2*(c[2] + zd*c[3])) + zd4*((c[4] + zd*c[5]) + zd2*c[6]));
    fd += tl[jd];
    r = fd - fn + en;
    ub = sgn*r;
  }
  return ub;
}
