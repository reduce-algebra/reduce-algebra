/* Correctly-rounded logarithm function for binary32 value.

Copyright (c) 2023-2024 Alexei Sibidanov and Paul Zimmermann.

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
  uint32_t ux = t.u;
  if(ux == 0u){// +0.0
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    return -1.0f/0.0f; // to raise FE_DIVBYZERO
  }
  if(ux == 0x7f800000u) return x; // +inf
  uint32_t ax = ux<<1;
  if(ax == 0u) { // -0.0
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    return -1.0f/0.0f; // to raise FE_DIVBYZERO
  }
  if(ax > 0xff000000u) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = EDOM;
#endif
  return 0.0f/0.0f; // to raise FE_INVALID and return nan
}

float cr_logf(float x){
  static const double tr[] = {
    0x1p+0, 0x1.f81f82p-1, 0x1.f07c1fp-1, 0x1.e9131acp-1,
    0x1.e1e1e1ep-1, 0x1.dae6077p-1, 0x1.d41d41dp-1, 0x1.cd85689p-1,
    0x1.c71c71cp-1, 0x1.c0e0704p-1, 0x1.bacf915p-1, 0x1.b4e81b5p-1,
    0x1.af286bdp-1, 0x1.a98ef6p-1, 0x1.a41a41ap-1, 0x1.9ec8e95p-1,
    0x1.999999ap-1, 0x1.948b0fdp-1, 0x1.8f9c19p-1, 0x1.8acb90fp-1,
    0x1.8618618p-1, 0x1.8181818p-1, 0x1.7d05f41p-1, 0x1.78a4c81p-1,
    0x1.745d174p-1, 0x1.702e05cp-1, 0x1.6c16c17p-1, 0x1.6816817p-1,
    0x1.642c859p-1, 0x1.605816p-1, 0x1.5c9882cp-1, 0x1.58ed231p-1,
    0x1.5555555p-1, 0x1.51d07ebp-1, 0x1.4e5e0a7p-1, 0x1.4afd6ap-1,
    0x1.47ae148p-1, 0x1.446f865p-1, 0x1.4141414p-1, 0x1.3e22cbdp-1,
    0x1.3b13b14p-1, 0x1.3813814p-1, 0x1.3521cfbp-1, 0x1.323e34ap-1,
    0x1.2f684bep-1, 0x1.2c9fb4ep-1, 0x1.29e412ap-1, 0x1.27350b9p-1,
    0x1.2492492p-1, 0x1.21fb781p-1, 0x1.1f7047ep-1, 0x1.1cf06aep-1,
    0x1.1a7b961p-1, 0x1.1811812p-1, 0x1.15b1e5fp-1, 0x1.135c811p-1,
    0x1.1111111p-1, 0x1.0ecf56cp-1, 0x1.0c9715p-1, 0x1.0a6810ap-1,
    0x1.0842108p-1, 0x1.0624dd3p-1, 0x1.041041p-1, 0x1.0204081p-1, 0.5};
  static const double tl[] = {
    -0x1.3b40815cd0628p-45, 0x1.fc0a890fbb514p-7, 0x1.f829b1e780b98p-6, 0x1.77458f532c948p-5,
    0x1.f0a30c2114ef2p-5, 0x1.341d793bbc7f7p-4, 0x1.6f0d28d256172p-4, 0x1.a926d3a6acb89p-4,
    0x1.e2707722ae90cp-4, 0x1.0d77e7a90896cp-3, 0x1.29552f6fff036p-3, 0x1.44d2b6c5b7831p-3,
    0x1.5ff306ee78ee7p-3, 0x1.7ab890410d41cp-3, 0x1.9525a9e3451c7p-3, 0x1.af3c94ed0bb06p-3,
    0x1.c8ff7c59a9535p-3, 0x1.e27076d5aedf9p-3, 0x1.fb9186b5e393ep-3, 0x1.0a324e38b8e6dp-2,
    0x1.1675cacaba398p-2, 0x1.22941fc0f76efp-2, 0x1.2e8e2bc311abap-2, 0x1.3a64c56b14373p-2,
    0x1.4618bc31c5c4cp-2, 0x1.51aad874df5b7p-2, 0x1.5d1bdbea80754p-2, 0x1.686c81d331238p-2,
    0x1.739d7f6dbcd9p-2, 0x1.7eaf83c82ad4dp-2, 0x1.89a3385813fe4p-2, 0x1.947941aa91484p-2,
    0x1.9f323edbf95d5p-2, 0x1.a9cec9a4205d3p-2, 0x1.b44f77c5c8cecp-2, 0x1.beb4d9ea71905p-2,
    0x1.c8ff7c69a97abp-2, 0x1.d32fe7f38e95fp-2, 0x1.dd46a0501c22ap-2, 0x1.e7442617e8511p-2,
    0x1.f128f5eaf0476p-2, 0x1.faf588dd8f0a8p-2, 0x1.02552a5edcfc4p-1, 0x1.0723e5c64de05p-1,
    0x1.0be72e3852947p-1, 0x1.109f39d554b5cp-1, 0x1.154c3d2c4d4aep-1, 0x1.19ee6b38bc834p-1,
    0x1.1e85f5ef03f95p-1, 0x1.23130d7fabe07p-1, 0x1.2795e1219afep-1, 0x1.2c0e9ec9c8d5p-1,
    0x1.307d7337f0f83p-1, 0x1.34e289cb4e098p-1, 0x1.393e0d42e28dep-1, 0x1.3d9026ad555bfp-1,
    0x1.41d8fe8667173p-1, 0x1.4618bc1ec5d87p-1, 0x1.4a4f85d303d8p-1, 0x1.4e7d8127f5a75p-1,
    0x1.52a2d26dbc47p-1, 0x1.56bf9d597f25ep-1, 0x1.5ad404cb59df2p-1, 0x1.5ee02a928153ap-1,
    0x1.62e42fefa38b4p-1};
  static const double b[] = {0x1.00000006342eap+0, -0x1.0001f7fdc3977p-1, 0x1.554a4e5cae9cfp-2};
  static const double c[] =
    {-0x1p-1, 0x1.55555555571cap-2, -0x1.0000000002d85p-2, 0x1.9999987d0c963p-3,
     -0x1.555554059a8bbp-3, 0x1.24aebcf71a38fp-3, -0x1.001c73915d758p-3};
  b32u32_u t = {.f = x};
  uint32_t ux = t.u;
  if(__builtin_expect(ux<(1<<23) || ux >= 0x7f800000u, 0)){
    if(ux==0 || ux >= 0x7f800000u) return as_special(x); // <=0, nan, inf
    // subnormal
    int n = __builtin_clz(ux) - 8;
    ux <<= n;
    ux -= n<<23;
  }
  if(__builtin_expect(ux == 127u<<23, 0)) return 0.0f;
  uint32_t m = ux&((1<<23)-1), j = (m + (1<<(23-7)))>>(23-6);
  int32_t e = ((int32_t)ux>>23)-127;
  b64u64_u tz = {.u = ((uint64_t)m|((int64_t)1023<<23))<<(52-23)};
  double z = tz.f*tr[j] - 1, z2 = z*z;
  double r = ((e*0x1.62e42fefa39efp-1 + tl[j]) + z*b[0]) + z2*(b[1] + z*b[2]);
  float ub = r, lb = r + 0x1.f06p-33;
  if(__builtin_expect(ub != lb, 0)){
    double f = z2*((c[0] + z*c[1]) + z2*((c[2] + z*c[3]) + z2*(c[4] + z*c[5] + z2*c[6])));
    if(__builtin_expect(__builtin_fabsf(x-1.0f)<0x1p-10f, 0)) {
      return z + f;
    }
    f -= 0x1.0ca86c3898dp-49*e;
    f += z;
    f += tl[j]-tl[0];
    double el = e*0x1.62e42fefa3ap-1;
    r = el + f;
    ub = r;
    tz.f = r;
    if(__builtin_expect(!(tz.u&((1u<<28)-1u)), 0) ){
      double dr = (el - r) + f;
      r += dr*64.0;
      ub = r;
    }
  }
  return ub;
}
