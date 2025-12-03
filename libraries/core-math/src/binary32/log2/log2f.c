/* Correctly-rounded binary logarithm function for binary32 value.

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

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

float cr_log2f(float x) {
  static const double ix[] = {
    0x1p+0, 0x1.fc07f01fcp-1, 0x1.f81f81f82p-1, 0x1.f44659e4ap-1, 0x1.f07c1f07cp-1,
    0x1.ecc07b302p-1, 0x1.e9131abfp-1, 0x1.e573ac902p-1, 0x1.e1e1e1e1ep-1,
    0x1.de5d6e3f8p-1, 0x1.dae6076bap-1, 0x1.d77b654b8p-1, 0x1.d41d41d42p-1,
    0x1.d0cb58f6ep-1, 0x1.cd8568904p-1, 0x1.ca4b3055ep-1, 0x1.c71c71c72p-1,
    0x1.c3f8f01c4p-1, 0x1.c0e070382p-1, 0x1.bdd2b8994p-1, 0x1.bacf914c2p-1,
    0x1.b7d6c3ddap-1, 0x1.b4e81b4e8p-1, 0x1.b2036406cp-1, 0x1.af286bca2p-1,
    0x1.ac5701ac6p-1, 0x1.a98ef606ap-1, 0x1.a6d01a6dp-1, 0x1.a41a41a42p-1,
    0x1.a16d3f97ap-1, 0x1.9ec8e951p-1, 0x1.9c2d14ee4p-1, 0x1.99999999ap-1,
    0x1.970e4f80cp-1, 0x1.948b0fcd6p-1, 0x1.920fb49dp-1, 0x1.8f9c18f9cp-1,
    0x1.8d3018d3p-1, 0x1.8acb90f6cp-1, 0x1.886e5f0acp-1, 0x1.861861862p-1,
    0x1.83c977ab2p-1, 0x1.818181818p-1, 0x1.7f405fd02p-1, 0x1.7d05f417ep-1,
    0x1.7ad2208ep-1, 0x1.78a4c8178p-1, 0x1.767dce434p-1, 0x1.745d1745ep-1,
    0x1.724287f46p-1, 0x1.702e05c0cp-1, 0x1.6e1f76b44p-1, 0x1.6c16c16c2p-1,
    0x1.6a13cd154p-1, 0x1.681681682p-1, 0x1.661ec6a52p-1, 0x1.642c8590cp-1,
    0x1.623fa7702p-1, 0x1.605816058p-1, 0x1.5e75bb8dp-1, 0x1.5c9882b94p-1,
    0x1.5ac056b02p-1, 0x1.58ed23082p-1, 0x1.571ed3c5p-1, 0x1.555555556p-1,
    0x1.5390948f4p-1, 0x1.51d07eae2p-1, 0x1.501501502p-1, 0x1.4e5e0a73p-1,
    0x1.4cab88726p-1, 0x1.4afd6a052p-1, 0x1.49539e3b2p-1, 0x1.47ae147aep-1,
    0x1.460cbc7f6p-1, 0x1.446f86562p-1, 0x1.42d6625d6p-1, 0x1.414141414p-1,
    0x1.3fb013fbp-1, 0x1.3e22cbce4p-1, 0x1.3c995a47cp-1, 0x1.3b13b13b2p-1,
    0x1.3991c2c18p-1, 0x1.381381382p-1, 0x1.3698df3dep-1, 0x1.3521cfb2cp-1,
    0x1.33ae45b58p-1, 0x1.323e34a2cp-1, 0x1.30d19013p-1, 0x1.2f684bda2p-1,
    0x1.2e025c04cp-1, 0x1.2c9fb4d82p-1, 0x1.2b404ad02p-1, 0x1.29e4129e4p-1,
    0x1.288b01288p-1, 0x1.27350b882p-1, 0x1.25e22708p-1, 0x1.24924924ap-1,
    0x1.23456789ap-1, 0x1.21fb78122p-1, 0x1.20b470c68p-1, 0x1.1f7047dc2p-1,
    0x1.1e2ef3b4p-1, 0x1.1cf06ada2p-1, 0x1.1bb4a4046p-1, 0x1.1a7b9611ap-1,
    0x1.19453808cp-1, 0x1.181181182p-1, 0x1.16e068942p-1, 0x1.15b1e5f76p-1,
    0x1.1485f0e0ap-1, 0x1.135c81136p-1, 0x1.12358e75ep-1, 0x1.111111112p-1,
    0x1.0fef010fep-1, 0x1.0ecf56be6p-1, 0x1.0db20a89p-1, 0x1.0c9714fbcp-1,
    0x1.0b7e6ec26p-1, 0x1.0a6810a68p-1, 0x1.0953f3902p-1, 0x1.084210842p-1,
    0x1.073260a48p-1, 0x1.0624dd2f2p-1, 0x1.05197f7d8p-1, 0x1.041041042p-1,
    0x1.03091b52p-1, 0x1.020408102p-1, 0x1.01010101p-1, 0x1p-1 };

  static const double lix[] = {
    0x0p+0,
    -0x1.fe02a6b146789p-8, -0x1.fc0a8b0fa03e4p-7, -0x1.7b91b07de311bp-6, -0x1.f829b0e7c33p-6,
    -0x1.39e87b9fd7d6p-5, -0x1.77458f63edcfcp-5, -0x1.b42dd7117b1bfp-5, -0x1.f0a30c01362a6p-5,
    -0x1.16536eea7fae1p-4, -0x1.341d7961791d1p-4, -0x1.51b073f07983fp-4, -0x1.6f0d28ae3eb4cp-4,
    -0x1.8c345d6383b21p-4, -0x1.a926d3a475563p-4, -0x1.c5e548f63a743p-4, -0x1.e27076e28f2e6p-4,
    -0x1.fec9131dbaabbp-4, -0x1.0d77e7ccf6e59p-3, -0x1.1b72ad52f87ap-3, -0x1.29552f81eb523p-3,
    -0x1.371fc201f7f74p-3, -0x1.44d2b6ccbfd1ep-3, -0x1.526e5e3a41438p-3, -0x1.5ff3070a613d4p-3,
    -0x1.6d60fe717221dp-3, -0x1.7ab890212b909p-3, -0x1.87fa065214911p-3, -0x1.9525a9cf296b4p-3,
    -0x1.a23bc1fe42563p-3, -0x1.af3c94e81bff3p-3, -0x1.bc2867430acd6p-3, -0x1.c8ff7c7989a22p-3,
    -0x1.d5c216b535b91p-3, -0x1.e27076e2f92e6p-3, -0x1.ef0adcbe0d936p-3, -0x1.fb9186d5ebe2bp-3,
    -0x1.0402594b51041p-2, -0x1.0a324e27370e3p-2, -0x1.1058bf9ad7ad5p-2, -0x1.1675cabaa660ep-2,
    -0x1.1c898c16b91fbp-2, -0x1.22941fbcfb966p-2, -0x1.2895a13dd2ea3p-2, -0x1.2e8e2bade7d31p-2,
    -0x1.347dd9a9afd55p-2, -0x1.3a64c556b05eap-2, -0x1.40430868877e4p-2, -0x1.4618bc219dec2p-2,
    -0x1.4be5f9579e0a1p-2, -0x1.51aad872c982dp-2, -0x1.5767717432a6cp-2, -0x1.5d1bdbf5669cap-2,
    -0x1.62c82f2b83795p-2, 0x1.5d5bddf5b0f3p-2, 0x1.57bf753cb49fbp-2, 0x1.522ae073b23d8p-2,
    0x1.4c9e09e18f43cp-2, 0x1.4718dc271841bp-2, 0x1.419b423d5a8c7p-2, 0x1.3c2527735f184p-2,
    0x1.36b6776bff917p-2, 0x1.314f1e1d54ce4p-2, 0x1.2bef07cdb5354p-2, 0x1.269621136db92p-2,
    0x1.214456d0e88d4p-2, 0x1.1bf9963577b95p-2, 0x1.16b5ccbaf1373p-2, 0x1.1178e822ae47cp-2,
    0x1.0c42d67625ae3p-2, 0x1.07138604b0862p-2, 0x1.01eae56243e91p-2, 0x1.f991c6cb33379p-3,
    0x1.ef5ade4de2fe6p-3, 0x1.e530effe1b012p-3, 0x1.db13db0da194p-3, 0x1.d1037f264de7bp-3,
    0x1.c6ffbc6ef8f71p-3, 0x1.bd087383798adp-3, 0x1.b31d8575dee3dp-3, 0x1.a93ed3c8fd9e3p-3,
    0x1.9f6c407055664p-3, 0x1.95a5adcfc217fp-3, 0x1.8beafeb38ce8cp-3, 0x1.823c1655523c2p-3,
    0x1.7898d85460c73p-3, 0x1.6f0128b7baabcp-3, 0x1.6574ebe86933ap-3, 0x1.5bf406b59bdb2p-3,
    0x1.527e5e4a5158dp-3, 0x1.4913d83395561p-3, 0x1.3fb45a59ed8ccp-3, 0x1.365fcb0151016p-3,
    0x1.2d1610c81c13ap-3, 0x1.23d712a4fa202p-3, 0x1.1aa2b7e1ff72ap-3, 0x1.1178e822de47cp-3,
    0x1.08598b5990a07p-3, 0x1.fe89139dc1566p-4, 0x1.ec739830d912p-4, 0x1.da7276390c6a2p-4,
    0x1.c885801c04b23p-4, 0x1.b6ac88da61b1cp-4, 0x1.a4e7640a45c38p-4, 0x1.9335e5d524989p-4,
    0x1.8197e2f37a3fp-4, 0x1.700d30af800e1p-4, 0x1.5e95a4d90f1cbp-4, 0x1.4d3115d2cfeacp-4,
    0x1.3bdf5a7c60e64p-4, 0x1.2aa04a44a57a5p-4, 0x1.1973bd1527567p-4, 0x1.08598b5ac3a07p-4,
    0x1.eea31bfea787cp-5, 0x1.ccb73cdcb32ccp-5, 0x1.aaef2d11110fcp-5, 0x1.894aa1485b343p-5,
    0x1.67c94f2e07b58p-5, 0x1.466aed42be3eap-5, 0x1.252f32faad83fp-5, 0x1.0415d89e54444p-5,
    0x1.c63d2ec16aaf2p-6, 0x1.8492528ddcabfp-6, 0x1.432a925ca0cc1p-6, 0x1.0205658d15847p-6,
    0x1.82448a3d8a2aap-7, 0x1.010157586de71p-7, 0x1.0080559488b35p-8, 0x0p+0 };

  b32u32_u t = {.f = x};
  uint32_t ux = t.u;
  uint64_t m = ux&(~0u>>9); m <<= 52-23;
  int e = (ux>>23) - 0x7f;
  if (__builtin_expect(ux < 1u<<23 || ux >= 0xffu<<23, 0)) {
    if (ux==0||ux==(1u<<31)) { // x = +/-0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      return -1.0f / 0.0f; // should raise 'Divide by zero' exception.
    }
    uint32_t inf_or_nan = ((ux>>23)&0xff) == 0xff, nan = inf_or_nan && (ux<<9);
    if (ux>>31 && !nan) { // x < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      return (x - x) / (x - x);  // should raise 'Invalid operation' exception.
    }
    if (inf_or_nan) return x + x;
    // subnormal
    int nz = __builtin_clzll(m);
    m <<= nz-11;
    m &= ~(uint64_t)0>>12;
    e -= nz-12;
  }
  if(__builtin_expect(!m, 0)) return e;
  int j = (m + ((int64_t)1<<(52-8)))>>(52-7), k = j>53;
  e += k;
  b64u64_u xd = {.u = m | (uint64_t)0x3ff<<52};
  double z = __builtin_fma(xd.f, ix[j], -1.0); // z is exact
  static const double c[] =
    {0x1p+0, -0x1p-1, 0x1.55555555030bcp-2, -0x1.ffffffff2b4e5p-3, 0x1.999b5076a42f2p-3, -0x1.55570c45a647dp-3};
  double z2 = z*z;
  double c0 = c[0] + z*c[1];
  double c2 = c[2] + z*c[3];
  double c4 = c[4] + z*c[5];
  c0 += z2*(c2 + z2*c4);
  const double iln2 = 0x1.71547652b82fep+0;
  return  (z*iln2)*c0 + (e - lix[j]*iln2);
}
