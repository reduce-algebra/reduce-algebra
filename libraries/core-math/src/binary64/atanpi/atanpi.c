/* Correctly-rounded atanpi of binary64 value.

Copyright (c) 2023-2025 Alexei Sibidanov and Paul Zimmermann

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

/* This implementation is based on the CORE-MATH atan.c implementation
   (commit b9d8cae), using the formula atanpi(x) = atan(x) / pi.
   The parts that differ from atan(x) are between comments
   "atanpi_begin" and "atanpi_end", or marked "atanpi_specific",
   to ease maintaining that code if/when atan.c is fixed or improved.
*/

#include <stdint.h>
#include <math.h> // needed for atan()
#include <errno.h>

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// atanpi_begin
// ONE_OVER_PIH + ONE_OVER_PIL approximates 1/pi
#define ONE_OVER_PIH 0x1.45f306dc9c883p-2
#define ONE_OVER_PIL -0x1.6b01ec5417056p-56
#define ONE_OVER_3PI 0x1.b2995e7b7b604p-4 // approximates 1/(3pi)
// atanpi_end

typedef union {double f; uint64_t u;} b64u64_u;
typedef uint64_t u64;

static inline double fasttwosum(double x, double y, double *e){
  double s = x + y, z = s - x;
  *e = y - z;
  return s;
}

static inline double adddd(double xh, double xl, double ch, double cl, double *l) {
  double s = xh + ch, d = s - xh;
  *l = ((ch - d) + (xh + (d - s))) + (xl + cl);
  return s;
}

static inline double muldd(double xh, double xl, double ch, double cl, double *l){
  double ahlh = ch*xl, alhh = cl*xh, ahhh = ch*xh, ahhl = __builtin_fma(ch, xh, -ahhh);
  ahhl += alhh + ahlh;
  return fasttwosum (ahhh, ahhl, l);
}

static double polydd(double xh, double xl, int n, const double c[][2], double *l){
  int i = n-1;
  double ch = c[i][0] + *l, cl = (c[i][0] - ch) + *l + c[i][1];
  while(--i>=0){
    ch = muldd(xh,xl,ch,cl,&cl);
    double th = ch + c[i][0], tl = (c[i][0] - th) + ch;
    ch = th;
    cl += tl + c[i][1];
  }
  *l = cl;
  return ch;
}

static const double A[][2] = {
  {0x0p+0, 0x0p+0}, {0x1.9224e047e368ep-7, 0x1.a3ca6c727c59dp-62},
  {0x1.92346247a91fp-6, 0x1.138b0ef96a186p-64}, {0x1.2dbaae9a05dbp-5, 0x1.36e7f8a3f5e42p-59},
  {0x1.927278a3b1162p-5, -0x1.ac986efb92662p-64}, {0x1.f7495ea3f3783p-5, 0x1.06ec8011ee816p-59},
  {0x1.2e239ccff3831p-4, -0x1.858437d431332p-58}, {0x1.60b9f7597fdecp-4, -0x1.cebd13eb7c513p-60},
  {0x1.936bb8c5b2da2p-4, -0x1.840cac0d81db5p-58}, {0x1.c63ce377fc802p-4, 0x1.400b0fdaa109ep-58},
  {0x1.f93183a8db9e9p-4, 0x1.0e04e06c86e72p-59}, {0x1.1626d85a91e7p-3, 0x1.f7ad829163ca7p-59},
  {0x1.2fcac73a6064p-3, -0x1.2680735ce2cd8p-58}, {0x1.4986a74cf4e57p-3, -0x1.90559690b42e4p-57},
  {0x1.635c990ce0d36p-3, 0x1.91d29110b41aap-58}, {0x1.7d4ec54fb5968p-3, -0x1.ea90e2718278p-59},
  {0x1.975f5e0553158p-3, -0x1.dc82ac14e3e1cp-61}, {0x1.b1909efd8b762p-3, -0x1.73a10fd13daafp-58},
  {0x1.cbe4ceb4b4cf2p-3, -0x1.3a7ffbeabda0bp-57}, {0x1.e65e3f27c9f2ap-3, -0x1.db6627a24d523p-57},
  {0x1.007fa758626aep-2, -0x1.45f97dd3099f6p-57}, {0x1.0de53475f3b3cp-2, -0x1.6293f68741816p-57},
  {0x1.1b6103d3597e9p-2, -0x1.ab240d40633e9p-57}, {0x1.28f459ecad74dp-2, -0x1.de34d14e832ep-61},
  {0x1.36a08355c63dcp-2, 0x1.af540d9fb4926p-57}, {0x1.4466d542bac92p-2, 0x1.da60fdbc82ac4p-57},
  {0x1.5248ae1701b17p-2, -0x1.92a601170138ap-56}, {0x1.604775fbb27dfp-2, -0x1.7f1fca1d5d15bp-57},
  {0x1.6e649f7d78649p-2, -0x1.4e223ea716c7bp-57}, {0x1.7ca1a832d0f84p-2, 0x1.b24c824ac51fcp-56},
  {0x1.8b00196b3d022p-2, 0x1.4314cd132ba43p-57}, {0x1.998188e816bfp-2, -0x1.11f1e0817879ap-56},
  {0x1.a827999fcef32p-2, -0x1.c3dea4dbad538p-57}, {0x1.b6f3fc8c61e5bp-2, 0x1.60d1b780ee3ebp-57},
  {0x1.c5e87185e67b6p-2, -0x1.ab5edb7dfa545p-59}, {0x1.d506c82a2c8p-2, -0x1.8e1437048b5bdp-57},
  {0x1.e450e0d273e7ap-2, -0x1.06951c97b050fp-56}, {0x1.f3c8ad985d9eep-2, -0x1.14af9522ab518p-59},
  {0x1.01b819b5a7cf7p-1, -0x1.aba0d7d97d1f2p-56}, {0x1.09a4c59bd0d4dp-1, 0x1.095bc4ebc2c42p-59},
  {0x1.11ab7190834ecp-1, 0x1.798826fa27774p-55}, {0x1.19cd3fe8e405dp-1, 0x1.008f6258fc98fp-55},
  {0x1.220b5ef047825p-1, -0x1.462af7ceb7de6p-58}, {0x1.2a6709a74f289p-1, -0x1.1184dfd78b472p-56},
  {0x1.32e1889047ffdp-1, 0x1.9141876dc40c5p-56}, {0x1.3b7c3289ed6f3p-1, 0x1.481c20189726cp-55},
  {0x1.44386db9ce5dbp-1, 0x1.2e851bd025441p-55}, {0x1.4d17b087b265dp-1, 0x1.13ada9b8bc419p-56},
  {0x1.561b82ab7f99p-1, -0x1.05b4c3c4cbee8p-55}, {0x1.5f457e4f4812ep-1, -0x1.5619249bd96f1p-55},
  {0x1.6897514751db6p-1, -0x1.b0a0fbcafc671p-57}, {0x1.7212be621be6dp-1, -0x1.19ff2dc66da45p-55},
  {0x1.7bb99ed2990cfp-1, 0x1.1320449592d92p-55}, {0x1.858de3b716571p-1, -0x1.1fddcd2f3da8ep-55},
  {0x1.8f9197bf85eebp-1, 0x1.d44a42e35cc97p-57}, {0x1.99c6e0f634394p-1, -0x1.585a178b4a18dp-56},
  {0x1.a43002ae4285p-1, 0x1.f95a531b3a97p-57}, {0x1.aecf5f9ba35a6p-1, -0x1.96c2d43ca3392p-60},
  {0x1.b9a77c18c1af2p-1, -0x1.a5bed94b05defp-57}, {0x1.c4bb009e77983p-1, 0x1.54509d2bff511p-59},
  {0x1.d00cbc7384d2ep-1, -0x1.b4c867cef300cp-57}, {0x1.db9fa89953fcfp-1, -0x1.ddfac663d6bc6p-62},
  {0x1.e776eafc91706p-1, -0x1.a510683ff7cb6p-56}, {0x1.f395d9f0e3c92p-1, 0x1.4fdcd8e4e871p-59},
  {0x1p+0, 0x0p+0}, {0x1.065c900aaf2d8p+0, -0x1.deec7fc9042adp-55},
  {0x1.0ce29d0883c99p+0, -0x1.395ae45e0657dp-55}, {0x1.139447e6a86eep+0, 0x1.332cf301a97f3p-55},
  {0x1.1a73d55278c4bp+0, -0x1.6cc8c4b78213bp-55}, {0x1.2183b0c4573ffp+0, 0x1.70a90841da57ap-55},
  {0x1.28c66fdaf8f09p+0, -0x1.ba39bad450eep-57}, {0x1.303ed61109e2p+0, -0x1.8692946d9f93cp-55},
  {0x1.37efd8d87607ep+0, 0x1.3b711bf765b58p-57}, {0x1.3fdca42847507p+0, 0x1.c21387985b081p-56},
  {0x1.48089f8bf42ccp+0, -0x1.7ddb19d3d0efcp-55}, {0x1.507773c537eadp+0, -0x1.f5e354cf971f3p-56},
  {0x1.592d11142fa55p+0, -0x1.00f0ad675330dp-56}, {0x1.622db63c8ecc2p+0, -0x1.2c93f50ab2c0ep-55},
  {0x1.6b7df862652p+0, 0x1.bec391adc37d5p-56}, {0x1.7522cbdd428a8p+0, -0x1.9686ddc9ffcf5p-57},
  {0x1.7f218e25a7461p+0, -0x1.8d16529514246p-56}, {0x1.89801106cc709p+0, -0x1.092f51e9c2803p-55},
  {0x1.9444a7462122ap+0, -0x1.07c06755404c4p-55}, {0x1.9f7632fa9e871p+0, 0x1.02e0d43abc92bp-55},
  {0x1.ab1c35d8a74eap+0, 0x1.d0184e48af6f7p-58}, {0x1.b73ee3c3ef16ap+0, 0x1.73be957380bc2p-56},
  {0x1.c3e738086bc0fp+0, -0x1.02b6e26c84462p-56}, {0x1.d11f0dae40609p+0, 0x1.25c4f3ffa6e1fp-58},
  {0x1.def13b73c1406p+0, -0x1.e302db3c6823fp-58}, {0x1.ed69b4153a45dp+0, 0x1.3207830326c0ep-56},
  {0x1.fc95abad6cf4ap+0, -0x1.6308cee7927bfp-57}, {0x1.0641e192ceab3p+1, -0x1.0147ebf0df4c5p-56},
  {0x1.0ea21d716fbf7p+1, -0x1.168533cc41d8bp-56}, {0x1.17749711a6679p+1, -0x1.52a0b0333e9c5p-57},
  {0x1.20c36c6a7f38ep+1, 0x1.8659eece35395p-57}, {0x1.2a99f50fd4f4fp+1, 0x1.20fcad18cb36fp-55},
  {0x1.3504f333f9de6p+1, -0x1.52afdbd5a8c74p-56}, {0x1.4012ce2586a17p+1, -0x1.9747a792907d7p-56},
  {0x1.4bd3d87fe065p+1, 0x1.90c59393b52c8p-56}, {0x1.585aa4e1530fap+1, 0x1.af6934f13a3a8p-56},
  {0x1.65bc6cc825147p+1, -0x1.8534dcab5ad3ep-59}, {0x1.74118e4b6a7c8p+1, -0x1.555aa8bfca9a1p-56},
  {0x1.837626d70fdb8p+1, -0x1.56b3fee9ca72bp-58}, {0x1.940ad30abc792p+1, 0x1.4b3fdd4fdc06cp-58},
  {0x1.a5f59e90600ddp+1, 0x1.285d367c55ddcp-57}, {0x1.b9633283b6d14p+1, -0x1.8712976f17a16p-59},
  {0x1.ce885653127e7p+1, -0x1.abe8ab65d49fcp-60}, {0x1.e5a3de972a377p+1, 0x1.cd9be81ad764bp-58},
  {0x1.ff01305ecd8dcp+1, 0x1.742c2922656fap-59}, {0x1.0d7dc7cff4c9ep+2, -0x1.7c842978bee09p-56},
  {0x1.1d0143e71565fp+2, 0x1.7bc7dea7c3c03p-57}, {0x1.2e4ff1626b949p+2, 0x1.aefbe25b404e9p-59},
  {0x1.41bfee2424771p+2, -0x1.4bcfaaa95cb2cp-60}, {0x1.57be4eaa5e11bp+2, 0x1.0fe741e4ec679p-58},
  {0x1.70d751908c1b1p+2, 0x1.fe74a5b0ec709p-58}, {0x1.8dc25c117782bp+2, 0x1.0ca1c19f710efp-58},
  {0x1.af73f4ca3310fp+2, 0x1.2867b40ba77d6p-58}, {0x1.d7398d15e70dbp+2, 0x1.0fd4e0d4b1547p-57},
  {0x1.0372fb36b87e2p+3, 0x1.c16c9ecc1621dp-58}, {0x1.208dbdae055efp+3, 0x1.6b81a36e75e8cp-58},
  {0x1.44e6c595afdccp+3, -0x1.7c22045771848p-58}, {0x1.7398c57f3f1adp+3, 0x1.970503be105cp-58},
  {0x1.b1d03c03d2f7fp+3, -0x1.f299d010aead2p-60}, {0x1.046e9fe60a77ep+4, 0x1.d2b61deff33ecp-58},
  {0x1.45affed201b55p+4, 0x1.0e84d9567203ap-64}, {0x1.b267195b1ffaep+4, -0x1.ad44b44b92653p-64},
  {0x1.45e2455e4aaa7p+5, -0x1.296d577b5e21dp-60}, {0x1.45eed6854ce99p+6, 0x1.2db53886013cap-63},
  {0,0}
};

static const uint16_t c[31][3] = {
  {419, 81, 0}, {500, 81, 0}, {582, 163, 0}, {745, 163, 0}, {908, 326, 0}, {1234, 326, 0},
  {1559, 651, 0}, {2210, 650, 1}, {2860, 1299, 3}, {4156, 1293, 4}, {5444, 2569, 24},
  {7989, 2520, 32}, {10476, 4917, 168}, {15224, 4576, 200}, {19601, 8341, 838},
  {27105, 6648, 731}, {33036, 10210, 1998}, {41266, 6292, 1117}, {46469, 7926, 2048},
  {52375, 4038, 849}, {55587, 4591, 1291}, {58906, 2172, 479}, {60612, 2390, 688},
  {62325, 1107, 247}, {63192, 1207, 349}, {64056, 556, 124}, {64491, 605, 175},
  {64923, 278, 62}, {65141, 303, 88}, {65358, 139, 31}, {65467, 151, 44}
};

/* Deal with the case where |x| is large:
   for x > 0, atanpi(x) = 1/2 - 1/pi * 1/x + 1/(3pi) * 1/x^3 + O(1/x^5)
   for x < 0, atanpi(x) = -1/2 - 1/pi * 1/x + 1/(3pi) * 1/x^3 + O(1/x^5).
   The next term 1/5*x^5/pi is smaller than 2^-107 * atanpi(x)
   when |x| > 0x1.bep20. */
static double atanpi_asympt (double x)
{
  double h, m, l;
  h = __builtin_copysign (0.5, x);
  // approximate 1/x as yh + yl
  double yh, yl;
  yh = 1.0 / x;
  // Newton's iteration for the inverse is y = y + y*(1-x*y)
  yl = yh * __builtin_fma (yh, -x, 1.0);
  m = muldd (yh, yl, ONE_OVER_PIH, ONE_OVER_PIL, &l);
  // m + l ~ 1/pi * 1/x
  m = -m;
  l = __builtin_fma (ONE_OVER_3PI * yh, yh * yh, - l);
  // m + l ~ - 1/pi * 1/x + 1/(3pi) * 1/x^3
  h = fasttwosum (h, m, &m);
  m = fasttwosum (m, l, &l);
  if (__builtin_fabs (m) == 0x1p-55) // this is 1/2 ulp(atan(x))
    m = (m * l > 0) ? __builtin_copysign (0x1.0000000000001p-55, m)
      : __builtin_copysign (0x1.fffffffffffffp-56, m);
  return h + m;
}

/* Deal with |x| small: atanpi(x) = x/pi - 1/(3pi) * 1/x^3 + O(x^5).
   The O(x^5) starts with 1/(5pi) * 1/x^5, and is less than 2^-107 * atanpi(x)
   when 1/5*x^4 < 2^-107, thus x < 0x1.c7p-27. */
static double atanpi_tiny (double x)
{
  double h, l;
  h = x * ONE_OVER_PIH;
  l = __builtin_fma (x, ONE_OVER_PIH, -h);
  l = __builtin_fma (x, ONE_OVER_PIL, l);
  l = __builtin_fma (-ONE_OVER_3PI * x, x * x,  l);
#define EXCEPTIONS 20
  static const double exceptions[EXCEPTIONS][3] = {
   {0x1.9b46cfb0f10cap-37, 0x1.05d3aa746e163p-38, -0x1.94a704a0e798p-149},
   {0x1.eac33f52580c1p-31, 0x1.386de1f01225ap-32, -0x1.2be95e5723a66p-139},
   {0x1.56a4aa740a5a7p-53, 0x1.b44453e2404e7p-55, -0x1.c5376c33c7a5p-164},
   {0x1.9d47b2e2a4deep-38, 0x1.071a2e1e2e7ap-39, -0x1.e948955ed137ap-146},
   {0x1.932ddaeecdabep-44, 0x1.00abfb23406c5p-45, -0x1.fffffffffffffp-99},
   {0x1.e0b9044e5a1cfp-46, 0x1.32099f7c94e82p-47, -0x1.22752cf9b0bc5p-152},
   {0x1.13b412ea2182dp-50, 0x1.5f095755008fp-52, -0x1.a8ad4502b5f1p-160},
   {0x1.ff878736a1bcdp-43, 0x1.45a65501d94d3p-44, -0x1.7cb6951d7806dp-152},
   {0x1.4f03bd4cedd49p-38, 0x1.aa8dc8da24739p-40, -0x1.fe11160ec4ee9p-146},
   {0x1.0f2bf03e38a9ep-36, 0x1.594435f8c0326p-38, -0x1.8eef034a3526ep-145},
   {0x1.508ecb38f52f9p-52, 0x1.ac84c88f979a2p-54, -0x1.63773cbd64d5cp-164},
   {0x1.8ddcd3207fe6p-42, 0x1.fa930b4eb436cp-44, 0x1p-97},
   {0x1.1331b44547444p-48, 0x1.5e63596a62718p-50, -0x1.4a9f744d7cea7p-156},
   {0x1.f7681fa730e73p-31, 0x1.407a8ac1c768ap-32, -0x1.3c6a80c812c54p-138},
   {0x1.09df162e4049cp-36, 0x1.52849d0b1e523p-38, -0x1.fffffffffffffp-92},
   {0x1.59af9a1194efep-54, 0x1.b824198b94a89p-56, 0x1.fffffffffffffp-110},
   {0x1.65f203d6bb18ep-46, 0x1.c7c00d31634a6p-48, -0x1.d4af6699e375fp-157},
   {0x1.6f89f6df8258dp-34, 0x1.d3f710390db87p-36, -0x1.936061594fad7p-145},
   {0x1.3e4d2d87b5aefp-51, 0x1.954626979d7d3p-53, -0x1.6f8dbd4f38cdbp-161},
   {0x1.f46e9e25a51d1p-36, 0x1.3e95c097e08ep-37, -0x1.8e5f60920b571p-144},
  };
  for (int i = 0; i < EXCEPTIONS; i++)
    if (__builtin_fabs (x) == exceptions[i][0])
    {
      h = exceptions[i][1] * __builtin_copysign (1.0, x);
      l = exceptions[i][2] * __builtin_copysign (1.0, x);
      break;
    }
#undef EXCEPTIONS
  return h + l;
}

static double __attribute__((noinline)) as_atan_refine2(double x, double a){
  if (__builtin_fabs (x) > 0x1.bep20)
    return atanpi_asympt (x);
  if (__builtin_fabs (x) < 0x1.c7p-27)
    return atanpi_tiny (x);
#define EXCEPTIONS 56
  static const double exceptions[EXCEPTIONS][3] = {
   {0x1.16265f83e8121p+2, 0x1.b648e5b0804dap-2, 0x1.9db921c686893p-109},
   {0x1.8a5c063607fbap+6, 0x1.fcb1a9f45a781p-2, -0x1.fffffffffffffp-56},
   {0x1.1a5e744ff1806p-6, 0x1.677cdc7dea093p-8, 0x1.417d05c2a4506p-115},
   {0x1.2eee26511c903p-7, 0x1.81b11ac01389p-9, 0x1.508c83c3db5e3p-116},
   {0x1.bb0ba10084de6p-8, 0x1.1a0c1411a3dc1p-9, 0x1.a854b560fe4dbp-115},
   {0x1.55166a4d7d836p-2, 0x1.a33741abea942p-4, -0x1.54a4c868a708ep-110},
   {0x1.5fa4b5e7ce94p-3, 0x1.bb6715a0b1f81p-5, 0x1.00037a0bfdfaep-111},
   {0x1.2a04fa64d36p+4, 0x1.ee846d3680301p-2, 0x1.3015b69c79ef4p-111},
   {0x1.0fb7e1298320cp+4, 0x1.ecd42a2ef8667p-2, -0x1.21d6585c13d1p-107},
   {0x1.b6daa66352e75p+3, 0x1.e84651d4c9934p-2, 0x1.34e0b5a33a1dbp-108},
   {0x1.5717df9abccd3p+1, 0x1.8b9be647e02a9p-2, -0x1.6c5194938e976p-109},
   {0x1.e0ac5527e7f0dp-4, 0x1.309ce21202ccap-5, -0x1.141be39e1919dp-111},
   {0x1.932f168987539p+3, 0x1.e62f20aba165cp-2, -0x1.839c5638718f2p-109},
   {0x1.2e342ca2440eep+3, 0x1.dd9d1ecffc9ap-2, -0x1.53deddde1dde1p-109},
   {0x1.b37ef5831a537p-5, 0x1.14fc0e0c2dacep-6, -0x1.f6b67ef93b398p-113},
   {0x1.d8ea551d1d795p-8, 0x1.2d0fe21df78dp-9, -0x1.0f4d438d8dd24p-114},
   {0x1.badb08cd8b1c5p-3, 0x1.15a7db07daa97p-4, -0x1.fffffffffffffp-58},
   {0x1.18071548e23a6p+7, 0x1.fdac0c22a86c5p-2, 0x1.fffffffffffffp-56},
   {0x1.e8b9c1fe81ca3p+6, 0x1.fd55124d78891p-2, -0x1.ffffffffffffep-56},
   {0x1.e2faab41052e7p-6, 0x1.33629443d32f5p-7, 0x1.fffffffffffffp-61},
   {0x1.03f709107440dp-7, 0x1.4afda1e054259p-9, 0x1.ffffffffffffep-63},
   {0x1.928a1ca94d1dcp-15, 0x1.0043bd1fd5baep-16, -0x1.12e31518bad19p-122},
   {0x1.deda0ddb0795cp+11, 0x1.ffea37cae8f37p-2, -0x1.ffffffffffffep-56},
   {0x1.72f4cb85b8404p-11, 0x1.d850e9850ab33p-13, -0x1.014404207eb42p-119},
   {0x1.4b3c41e10a1d4p-21, 0x1.a5bdf2b61615bp-23, -0x1.180c42f2c36bbp-131},
   {0x1.4ad2f60d5240bp-9, 0x1.a537a6de092a1p-11, -0x1.f2e112f36eca4p-117},
   {0x1.1151841058e68p+20, 0x1.ffffeceb437e6p-2, -0x1.2dd2f50460971p-108},
   {0x1.8b012d530c5c8p-20, 0x1.f6ef7b3ee090cp-22, -0x1.9d79d9fb153c4p-128},
   {0x1.0fa189169e75ep+9, 0x1.ff666764f1751p-2, -0x1.da2823e32e295p-108},
   {0x1.46c64e8717ccfp+7, 0x1.fe014cac09e73p-2, 0x1.fffffffffffffp-56},
   {0x1.5a9ee4b581471p+12, 0x1.fff0f445bee08p-2, -0x1.4256eae14a448p-108},
   {0x1.6ab7e3b9e35cdp+12, 0x1.fff19f36d9901p-2, -0x1.246ecd835d1c3p-107},
   {0x1.842e540b07ac1p-13, 0x1.ee3f52b4af0dcp-15, -0x1.8c285bfa8c0ecp-121},
   {0x1.5d2c01b65f659p+18, 0x1.ffffc441a900dp-2, -0x1.8137cc73dd777p-107},
   {0x1.9d18f49824d6ap+17, 0x1.ffff9b00d35d1p-2, 0x1.fe1e36287467bp-110},
   {0x1.400b2b748da28p+20, 0x1.ffffefb46ade3p-2, -0x1.10ca50f3bfef4p-111},
   {0x1.27b786b2f1baep+20, 0x1.ffffee5d3f843p-2, -0x1.8afee3bdfb07bp-108},
   {0x1.bbc4a4251b4b9p-20, 0x1.1a82f5f7f86bdp-21, 0x1.fffffffffffffp-75},
   {0x1.72a01aef844e5p-11, 0x1.d7e514f3ffe99p-13, 0x1.7c2d5be2b88d8p-119},
   {0x1.95e2b447c5ed5p+13, 0x1.fff99356bf911p-2, 0x1.fffffffffffffp-56},
   {0x1.88d8109598821p+19, 0x1.ffffe572f576ap-2, 0x1.5430c0b185e51p-108},
   {0x1.3ef59f63222ccp-23, 0x1.961c9f0bc5519p-25, 0x1.fffffffffffffp-79},
   {0x1.72f2198034e17p+18, 0x1.ffffc7c36896ep-2, -0x1.adfc30e218aafp-109},
   {0x1.df1c8e36bbccp-27, 0x1.31030abf0398fp-28, 0x1.ffffffffffffep-82},
   {0x1.ad5781ab29bbap+9, 0x1.ff9ed31438683p-2, 0x1.fffffffffffffp-56},
   {0x1.ede23d6624a3ap+11, 0x1.ffeae182f312ep-2, -0x1.26eee3b0a2ccbp-107},
   {0x1.4a7e234cdce9bp+19, 0x1.ffffe0709e4e1p-2, -0x1.ffffffffffffdp-56},
   {0x1.1c404899ca42p-23, 0x1.69eb74ce9e7edp-25, 0x1.d126a89bf70e8p-131},
   {0x1.7422a8342383p+8, 0x1.ff1fc5deb1c5cp-2, -0x1.0cf8b48b700a5p-108},
   {0x1.f37be8c1f5dfp-15, 0x1.3dfb3d39744cfp-16, -0x1.cae8f0c659368p-123},
   {0x1.8c9f8999242b7p+20, 0x1.fffff2d9dca7bp-2, 0x1.fffffffffffffp-56},
   {0x1.427f51dcf1d68p+19, 0x1.ffffdfa850495p-2, 0x1.ffffffffffffdp-56},
   {0x1.abb7b457cdf84p+20, 0x1.fffff3ce932e2p-2, 0x1.6f17a18f91149p-112},
   {0x1.be630d1090fe6p-12, 0x1.1c2dc0a9340efp-13, -0x1.8147b0a8785f5p-121},
   {0x1.27f67f799ccbdp+13, 0x1.fff730800f741p-2, 0x1.fffffffffffffp-56},
   {0x1.3f91b5b198cddp+9, 0x1.ff7d71d1d656bp-2, -0x1.c90dde6f07a4p-110},
  };
  for (int i = 0; i < EXCEPTIONS; i++)
    if (__builtin_fabs (x) == exceptions[i][0])
    {
      double h = exceptions[i][1] * __builtin_copysign (1.0, x);
      double l = exceptions[i][2] * __builtin_copysign (1.0, x);
      return h + l;
    }
#undef EXCEPTIONS
  static const double ch[][2] = {
    {-0x1.5555555555555p-2, -0x1.5555555555555p-56}, {0x1.999999999999ap-3, -0x1.999999999bcb8p-57},
    {-0x1.2492492492492p-3, -0x1.249242093c016p-57}};
  static const double cl[] = {
    0x1.c71c71c71c71cp-4, -0x1.745d1745d1265p-4, 0x1.3b13b115bcbc4p-4, -0x1.1107c41ad3253p-4};
  b64u64_u phi = {.f = __builtin_fabs(a)*0x1.45f306dc9c883p6 + 256.5};
  int64_t i = (phi.u>>(52-8))&0xff;
  double h,hl;
  if(i==128) {
    h = -1.0/x;
    hl = __builtin_fma(h,x,1)*h;
  } else {
    double ta = __builtin_copysign(A[i][0], x);
    double zta = x*ta, ztal = __builtin_fma(x, ta, -zta), zmta = x - ta;
    double v = 1 + zta, d = 1 - v, ev = (d + zta) - ((d + v) - 1) + ztal;
    double r = 1.0/v, rl = (__builtin_fma(r, -v, 1.0) - ev*r)*r;
    h = r*zmta;
    hl = __builtin_fma(r,zmta,-h) + rl*zmta;
  }
  double h2l, h2 = muldd(h, hl, h, hl, &h2l), h4 = h2*h2;
  double h3l, h3 = muldd(h, hl, h2, h2l, &h3l);
  double fl = h2*((cl[0] + h2*cl[1]) + h4*(cl[2] + h2*cl[3])), f = polydd(h2, h2l, 3, ch, &fl);
  f = muldd(h3,h3l,f,fl,&fl);
  double ah, al, at;
  if(i==0){
    ah = h;
    al = f;
    at = fl;    
  } else { 
    double df = 0;
    if(i<128) df = __builtin_copysign(1.0,x)*A[i][1];
    double id = __builtin_copysign(i,x);
    ah = 0x1.921fb54442dp-7*id; al = 0x1.8469898cc518p-55*id, at = -0x1.fc8f8cbb5bf8p-104*id;
    al = adddd(al, at, df, 0, &at);
    al = adddd(al, at, h, hl, &at);
    al = adddd(al, at, f, fl, &at);
  }
  double v2, v0 = fasttwosum(ah, al, &v2), v1 = fasttwosum(v2, at, &v2);
  // now v0 + v1 approximates atan(x)
  // atanpi_begin
  v0 = muldd (v0, v1, ONE_OVER_PIH, ONE_OVER_PIL, &v1);
  // atanpi_end
  return v1 + v0;
}

// deal with |x| < 2^-54 (including 0)
static double
atanpi_small (double x)
{
  double h;
  if (x == 0)
    return x;
  if (__builtin_fabs (x) == 0x1.5cba89af1f855p-1022) {
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE; // underflow
#endif
    return (x > 0)
      ? __builtin_fma (-0x1p-600, 0x1p-600, 0x1.bc03df34e902cp-1024)
      :__builtin_fma (0x1p-600, 0x1p-600, -0x1.bc03df34e902cp-1024);
  }
  // generic worst case
  b64u64_u v = {.f = x};
  if ((v.u & 0xfffffffffffff) == 0x59af9a1194efe) // +/-0x1.59af9a1194efe*2^e
  {
    uint64_t e = v.u >> 52;
    if ((e & 0x7ff) > 2) {
      v.u = ((e - 2) << 52) | 0xb824198b94a89;
    return (x > 0)
      ? __builtin_fma (0x1p-600, 0x1p-600, v.f)
      : __builtin_fma (-0x1p-600, 0x1p-600, v.f);
    }
  }
  h = x * ONE_OVER_PIH;
  /* Assuming h = x*ONE_OVER_PIH - e, the correction term is
     e + x * ONE_OVER_PIL, but we need to scale values to avoid underflow. */
  double corr = __builtin_fma (x * 0x1p106, ONE_OVER_PIH, -h * 0x1p106);
  corr = __builtin_fma (x * 0x1p106, ONE_OVER_PIL, corr);
  // now return h + corr * 2^-106
  double res = __builtin_fma (corr, 0x1p-106, h);
#ifdef CORE_MATH_SUPPORT_ERRNO
  if (__builtin_fabs (x) <= 0x1.921fb54442d17p-1021
      || __builtin_fabs (res) < 0x1p-1022)
    errno = ERANGE; // underflow
#endif
  return res;
}

double cr_atanpi (double x){
  static const double ch[] = {0x1p+0, -0x1.555555555552bp-2, 0x1.9999999069c2p-3, -0x1.248d2c8444ac6p-3};
  b64u64_u t = {.f = x};
  u64 at = t.u&(~(u64)0>>1);
  int64_t i = (at>>51) - 2030l;
  if (__builtin_expect(at < 0x3f7b21c475e6362aull, 0)) { // |x| < 0.006624
    if (at < 0x3c90000000000000ull) // |x| < 2^-54
      return atanpi_small (x);
    if (__builtin_expect (x == 0, 0)) return x;
    static const double ch2[] = {
      -0x1.5555555555555p-2, 0x1.99999999998c1p-3, -0x1.249249176aecp-3, 0x1.c711fd121ae8p-4};
    double x2 = x*x, x3 = x*x2, x4 = x2*x2;
    double f = x3*((ch2[0] + x2*ch2[1]) + x4*(ch2[2] + x2*ch2[3]));
    // begin_atanpi
    /* Here x+f approximates atan(x), with absolute error bounded by
       0x4.8p-52*f (see atan.c). After multiplying by 1/pi this error
       will be bounded by 0x1.6fp-52*f. For |x| < 0x1.b21c475e6362ap-8
       we have |f| < 2^-16*|x|, thus the error is bounded by
       0x1.6fp-52*2^-16*|x| < 0x1.6fp-68. */
    // multiply x + f by 1/pi
    double h, l;
    h = muldd (x, f, ONE_OVER_PIH, ONE_OVER_PIL, &l);
    /* The rounding error in muldd and the approximation error between
       1/pi and ONE_OVER_PIH + ONE_OVER_PIL are covered by the difference
       between 0x4.8p-52*pi and 0x1.6fp-52, which is > 2^-61.8. */
    double ub = h + __builtin_fma (0x1.6fp-68, x, l);
    double lb = h + __builtin_fma (-0x1.6fp-68, x, l);
    if (__builtin_expect (ub == lb, 1)) return ub;
    // end_atanpi
    ub = (f + f*0x4.8p-52) + x; // atanpi_specific, original value in atan.c
    return as_atan_refine2(x, ub);
  }
  // now |x| >= 0x1.b21c475e6362ap-8
  double h, ah, al;
  if(__builtin_expect(at>0x4062ded8e34a9035ull, 0)) {
    // |x| > 0x1.2ded8e34a9035p+7, atanpi|x| > 0.49789
    if(__builtin_expect(at >= 0x43445f306dc9c883ull, 0)){
      // |x| >= 0x1.45f306dc9c883p+53, atanpi|x| > 0.5 - 0x1p-55
      if(__builtin_expect(at >= ((u64)0x7ff<<52), 0)){
	// case Inf or NaN
	if(at == ((u64)0x7ff<<52)) // Inf
	  return __builtin_copysign(0.5, x); // atanpi_specific
	return x + x; // NaN
      }
      return __builtin_copysign(0.5, x) - __builtin_copysign(0x1p-56, x);
    }
    h = -1.0/x;
    ah = __builtin_copysign(0x1.921fb54442d18p+0, x);
    al = __builtin_copysign(0x1.1a62633145c07p-54, x);
  } else {
    // 0x1.b21c475e6362ap-8 <= |x| <= 0x1.2ded8e34a9035p+7
    /* we need to deal with |x| = 1 separately since in this case
       h=0 below, and the error is measured in terms of multiple of h */
    if (__builtin_expect (at == 0x3ff0000000000000, 0)) // |x| = 1
      return __builtin_copysign (0x1p-2, x);
    u64 u = t.u & (~(u64)0>>13);
    u64 ut = u>>(51-16), ut2 = ut*ut>>16;
    i = (((u64)c[i][0]<<16) + ut*c[i][1] - ut2*c[i][2])>>(16+9);
    double ta = __builtin_copysign(1.0, x)*A[i][0], id = __builtin_copysign(1.0, x)*(double)i;
    al = __builtin_copysign(1.0, x)*A[i][1] + 0x1.8469898cc517p-55*id;
    h = (x - ta)/(1 + x*ta);
    ah = 0x1.921fb54442dp-7*id;
  }
  double h2 = h*h, h4 = h2*h2;
  double f = (ch[0] + h2*ch[1]) + h4*(ch[2] + h2*ch[3]);
  al = __builtin_fma(h, f, al);
  // begin_atanpi
  /* Now ah + al approximates atan(x) with error bounded by 0x3.fp-52*h
     (see atan.c), thus by 0x1.41p-52*h after multiplication by 1/pi.
     We normalize ah+al so that the rounding error in muldd is negligible
     below. */
  double e0 = h*0x3.fp-52;    // original value in atan.c
  double ub0 = (al + e0) + ah; // original value in atan.c
  ah = fasttwosum (ah, al, &al);
  ah = muldd (ah, al, ONE_OVER_PIH, ONE_OVER_PIL, &al);
  /* The rounding error in muldd() and the approximation error between 1/pi
     and ONE_OVER_PIH+ONE_OVER_PIL are absorbed when rounding up 0x3.fp-52*pi
     to 0x1.41p-52. */
  double e = h * 0x1.41p-52; // atanpi_specific
  // end_atanpi
  double ub = (al + e) + ah, lb = (al - e) + ah;
  if(__builtin_expect(ub == lb, 1)) return ub;
  return as_atan_refine2(x, ub0);
}
