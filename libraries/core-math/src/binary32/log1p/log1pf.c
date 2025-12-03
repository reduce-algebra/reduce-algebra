/* Correctly-rounded biased argument natural logarithm function for binary32 value.

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
  if(t.u==0xbf800000u){// +0.0
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    return -1.0f/0.0f; // to raise FE_DIVBYZERO
  }
  if(t.u == 0x7f800000u) return x; // +inf
  uint32_t ax = t.u<<1;
  if(ax > 0xff000000u) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = EDOM;
#endif
  return 0.0f/0.0f; // to raise FE_INVALID
}

float cr_log1pf(float x) {
  static const double x0[] = {
    0x1.f81f82p-1, 0x1.e9131acp-1, 0x1.dae6077p-1, 0x1.cd85689p-1, 0x1.c0e0704p-1, 0x1.b4e81b5p-1,
    0x1.a98ef6p-1, 0x1.9ec8e95p-1, 0x1.948b0fdp-1, 0x1.8acb90fp-1, 0x1.8181818p-1, 0x1.78a4c81p-1,
    0x1.702e05cp-1, 0x1.6816817p-1, 0x1.605816p-1, 0x1.58ed231p-1, 0x1.51d07ebp-1, 0x1.4afd6ap-1,
    0x1.446f865p-1, 0x1.3e22cbdp-1, 0x1.3813814p-1, 0x1.323e34ap-1, 0x1.2c9fb4ep-1, 0x1.27350b9p-1,
    0x1.21fb781p-1, 0x1.1cf06aep-1, 0x1.1811812p-1, 0x1.135c811p-1, 0x1.0ecf56cp-1, 0x1.0a6810ap-1,
    0x1.0624dd3p-1, 0x1.0204081p-1};
  static const double lixb[] = {
    0x1.fc0a8909b4218p-7, 0x1.77458f51aac89p-5, 0x1.341d793afb997p-4, 0x1.a926d3a5ebd2ap-4,
    0x1.0d77e7a8a823dp-3, 0x1.44d2b6c557102p-3, 0x1.7ab89040accecp-3, 0x1.af3c94ecab3d6p-3,
    0x1.e27076d54e6c9p-3, 0x1.0a324e3888ad5p-2, 0x1.22941fc0c7357p-2, 0x1.3a64c56ae3fdbp-2,
    0x1.51aad874af21fp-2, 0x1.686c81d300eap-2, 0x1.7eaf83c7fa9b5p-2, 0x1.947941aa610ecp-2,
    0x1.a9cec9a3f023bp-2, 0x1.beb4d9ea4156ep-2, 0x1.d32fe7f35e5c7p-2, 0x1.e7442617b817ap-2,
    0x1.faf588dd5ed1p-2, 0x1.0723e5c635c39p-1, 0x1.109f39d53c99p-1, 0x1.19ee6b38a4668p-1,
    0x1.23130d7f93c3bp-1, 0x1.2c0e9ec9b0b85p-1, 0x1.34e289cb35eccp-1, 0x1.3d9026ad3d3f3p-1,
    0x1.4618bc1eadbbbp-1, 0x1.4e7d8127dd8a9p-1, 0x1.56bf9d5967092p-1, 0x1.5ee02a926936ep-1};
  static const double lix[] = {
    0x1.fc0a890fc03e4p-7, 0x1.77458f532dcfcp-5, 0x1.341d793bbd1d1p-4, 0x1.a926d3a6ad563p-4,
    0x1.0d77e7a908e59p-3, 0x1.44d2b6c5b7d1ep-3, 0x1.7ab890410d909p-3, 0x1.af3c94ed0bff3p-3,
    0x1.e27076d5af2e6p-3, 0x1.0a324e38b90e3p-2, 0x1.22941fc0f7966p-2, 0x1.3a64c56b145eap-2,
    0x1.51aad874df82dp-2, 0x1.686c81d3314afp-2, 0x1.7eaf83c82afc3p-2, 0x1.947941aa916fbp-2,
    0x1.a9cec9a42084ap-2, 0x1.beb4d9ea71b7cp-2, 0x1.d32fe7f38ebd5p-2, 0x1.e7442617e8788p-2,
    0x1.faf588dd8f31fp-2, 0x1.0723e5c64df4p-1, 0x1.109f39d554c97p-1, 0x1.19ee6b38bc96fp-1,
    0x1.23130d7fabf43p-1, 0x1.2c0e9ec9c8e8cp-1, 0x1.34e289cb4e1d3p-1, 0x1.3d9026ad556fbp-1,
    0x1.4618bc1ec5ec2p-1, 0x1.4e7d8127f5bb1p-1, 0x1.56bf9d597f399p-1, 0x1.5ee02a9281675p-1};
  static const double b[] =
    {0x1p+0, -0x1p-1, 0x1.5555555556f6bp-2, -0x1.00000000029b9p-2,
     0x1.9999988d176e4p-3, -0x1.55555418889a7p-3, 0x1.24adeca50e2bcp-3, -0x1.001ba33bf57cfp-3};

  double z = x;
  b32u32_u t = {.f = x};
  uint32_t ux = t.u, ax = ux&(~0u>>1);
  if(__builtin_expect(ax<0x3c880000u, 1)){ // |x| < 0x1.1p-6
    if(__builtin_expect(ax<0x33000000u, 0)){ // |x| < 0x1p-25
      if(!ax) return x;
      float res = __builtin_fmaf(x,-x,x);
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* log1p(x) underflows exactly when |res| < 2^-126
         and for x=-0x1.fffffcp-127 and rounding downwards */
      if (__builtin_fabsf (res) < 0x1p-126f ||
          (x == -0x1.fffffcp-127f && res == -0x1p-126f))
        errno = ERANGE; // underflow
#endif
      return res;
    }
    double z2 = z*z, z4 = z2*z2;
    double f = z2*((b[1] + z*b[2]) + z2*(b[3] + z*b[4]) + z4*((b[5] + z*b[6]) + z2*b[7]));
    b64u64_u r = {.f = z + f};
    if(__builtin_expect((r.u&0xfffffffll) == 0, 0)) r.f += 0x1p14*(f + (z - r.f));
    return r.f;
  } else {
    if(__builtin_expect(ux>=0xbf800000u||ax>=0x7f800000u, 0)) return as_special(x);
    b64u64_u tp = {.f = z + 1};
    int e = tp.u>>52;
    uint64_t m52 = tp.u&(~(uint64_t)0>>12);
    unsigned j = (tp.u >> (52-5))&31;
    e -= 0x3ff;
    b64u64_u xd = {.u = m52 | ((uint64_t)0x3ff<<52)};
    z = xd.f*x0[j] - 1;
    static const double c[] =
      {-0x1.3902c33434e7fp-43, 0x1.ffffffe1cbed5p-1, -0x1.ffffff7d1b014p-2, 0x1.5564e0ed3613ap-2, -0x1.0012232a00d4ap-2};
    const double ln2 = 0x1.62e42fefa39efp-1;
    double z2 = z*z, r = (ln2*e + lixb[j]) + z*((c[1] + z*c[2]) + z2*(c[3] + z*c[4]));
    float ub = r, lb = r + 2.2e-11;
    if(__builtin_expect(ub != lb, 0)){
      double z4 = z2*z2, f = z*((b[0] + z*b[1]) + z2*(b[2] + z*b[3]) + z4*((b[4] + z*b[5]) + z2*(b[6] + z*b[7])));
      const double ln2l = 0x1.7f7d1cf79abcap-20, ln2h = 0x1.62e4p-1;
      double Lh = ln2h * e, Ll = ln2l * e, rl = f + Ll + lix[j];
      b64u64_u tr = {.f = rl + Lh};
      if(__builtin_expect((tr.u&0xfffffffll) == 0 , 0)){
	if(x==-0x1.247ab0p-6f) return -0x1.271f0ep-6f - 0x1p-31f;
	if(x==-0x1.3a415ep-5f) return -0x1.407112p-5f + 0x1p-30f;
	if(x== 0x1.fb035ap-2f) return  0x1.9bddc2p-2f + 0x1p-27f;
	tr.f += 64*(rl + (Lh - tr.f));
      } else if(rl+(Lh-tr.f)==0.0){
	if(x== 0x1.b7fd86p-4f) return  0x1.a1ece2p-4f + 0x1p-29f;
	if(x==-0x1.3a415ep-5f) return -0x1.407112p-5f + 0x1p-30f;
	if(x== 0x1.43c7e2p-6f) return  0x1.409f80p-6f + 0x1p-31f;
      }
      ub = tr.f;
    }
    return ub;
  }
}
