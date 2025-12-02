/* Correctly rounded base-2 logarithm of binary64 values.

Copyright (c) 2023 Alexei Sibidanov.

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

#include <errno.h>
#include <stdint.h>

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef uint64_t u64;
typedef unsigned short ushort;
typedef union {double f; u64 u;} b64u64_u;

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

static inline double polydd(double xh, double xl, int n, const double c[][2], double *l){
  int i = n-1;
  double ch = c[i][0] + *l, cl = ((c[i][0] - ch) + *l) + c[i][1];
  while(--i>=0){
    ch = muldd(xh, xl, ch, cl, &cl);
    double th = ch + c[i][0], tl = (c[i][0] - th) + ch;
    ch = th;
    cl += tl + c[i][1];
  }
  *l = cl;
  return ch;
}

static double __attribute__((noinline)) as_log2_refine(double, double);
static double __attribute__((noinline)) as_log2_exact(int e){return e;}

double cr_log2(double x){
  static const struct {ushort c0; short c1;} B[] = {
    {301, 27565}, {7189, 24786}, {13383, 22167}, {18923, 19696}, {23845, 17361}, {28184, 15150},
    {31969, 13054}, {35231, 11064}, {37996, 9173}, {40288, 7372}, {42129, 5657}, {43542, 4020}, {44546,
    2457}, {45160, 962}, {45399, -468}, {45281, -1838}, {44821, -3151}, {44032, -4412}, {42929, -5622},
    {41522, -6786}, {39825, -7905}, {37848, -8982}, {35602, -10020}, {33097, -11020}, {30341, -11985},
    {27345, -12916}, {24115, -13816}, {20661, -14685}, {16989, -15526}, {13107, -16339}, {9022,
    -17126}, {4740, -17889}};
  static const double r1[] =
    {0x1.71548p+0, 0x1.696af492p+0, 0x1.61ab3fb68p+0, 0x1.5a1844168p+0,
    0x1.52adadb48p+0, 0x1.4b6b7c908p+0, 0x1.4451b0aa8p+0, 0x1.3d5ed8aep+0,
    0x1.369183468p+0, 0x1.2fe9b074p+0, 0x1.296760368p+0, 0x1.2307afe5p+0,
    0x1.1cca9f7f8p+0, 0x1.16b02f06p+0, 0x1.10b85e788p+0, 0x1.0ae04b2ep+0,
    0x1.0527f5268p+0, 0x1.ff1eb8c4p-1, 0x1.f42a1f18p-1, 0x1.e9721d49p-1,
    0x1.def6b357p-1, 0x1.d4b21bfp-1, 0x1.caa739bdp-1, 0x1.c0d32a15p-1,
    0x1.b735ecf8p-1, 0x1.adcc9fbdp-1, 0x1.a4974264p-1, 0x1.9b92f244p-1,
    0x1.92c29206p-1, 0x1.8a205c58p-1, 0x1.81af33e3p-1, 0x1.796c35fep-1, 0x1.71548p-1};
  static const double r2[] =
    {0x1p+0, 0x1.ffa7p-1, 0x1.ff4fp-1, 0x1.fef6p-1, 0x1.fe9ep-1, 0x1.fe45p-1,
    0x1.fdedp-1, 0x1.fd94p-1, 0x1.fd3cp-1, 0x1.fce4p-1, 0x1.fc8cp-1, 0x1.fc34p-1,
    0x1.fbdcp-1, 0x1.fb84p-1, 0x1.fb2cp-1, 0x1.fad4p-1, 0x1.fa7cp-1, 0x1.fa24p-1,
    0x1.f9cdp-1, 0x1.f975p-1, 0x1.f91ep-1, 0x1.f8c6p-1, 0x1.f86fp-1, 0x1.f817p-1,
    0x1.f7cp-1, 0x1.f769p-1, 0x1.f711p-1, 0x1.f6bap-1, 0x1.f663p-1, 0x1.f60cp-1,
    0x1.f5b5p-1, 0x1.f55ep-1, 0x1.f507p-1};
  static const double l1[][2] = {
    {0x0p+0, 0x0p+0}, {0x1.1435edc775b51p-26, 0x1.ffe38p-6},
    {0x1.c8f1cbf9e4073p-26, 0x1.000bcp-4}, {-0x1.7bf30fa53957bp-26, 0x1.7ff94p-4},
    {0x1.674d30b6276edp-27, 0x1.fffa6p-4}, {0x1.99fcf0d796acep-28, 0x1.400058p-3},
    {-0x1.5ffd8b92706d2p-26, 0x1.7ffe5p-3}, {0x1.bef90bc5a116dp-26, 0x1.bffc3p-3},
    {0x1.fca73b3d53f0dp-26, 0x1.ffffdp-3}, {-0x1.41024e560e04ep-27, 0x1.2000dp-2},
    {0x1.484024fad8461p-26, 0x1.3ffccp-2}, {0x1.2d9ab90ba7694p-26, 0x1.5ffe18p-2},
    {-0x1.2c998ea30ba7bp-26, 0x1.80013cp-2}, {-0x1.75fc8682f918ep-27, 0x1.a0024cp-2},
    {-0x1.f02f268a85fb8p-26, 0x1.bffd3p-2}, {-0x1.50030ea7fae4bp-27, 0x1.dffd7cp-2},
    {-0x1.bffb8da5b849dp-28, 0x1.ffff98p-2}, {0x1.f71993ff95475p-28, 0x1.0fffd4p-1},
    {0x1.88028e67f78fap-29, 0x1.20010cp-1}, {0x1.f915f5a0b4e89p-26, 0x1.30018ap-1},
    {0x1.c2fe288f968f8p-30, 0x1.3fff48p-1}, {0x1.7375a75ae0837p-26, 0x1.50013p-1},
    {0x1.91e48be920323p-29, 0x1.6000eap-1}, {0x1.ee7bc0d39a3dbp-29, 0x1.700112p-1},
    {-0x1.899e2ac5f778cp-29, 0x1.7fffb4p-1}, {0x1.f1f20176130a7p-26, 0x1.8fffaep-1},
    {0x1.03fc59d34a4f3p-27, 0x1.9fff1ep-1}, {-0x1.68722010e4653p-32, 0x1.b0012ap-1},
    {-0x1.58783d505a6ecp-26, 0x1.bffeb8p-1}, {0x1.b212ab9f8d51dp-27, 0x1.d0004ep-1},
    {-0x1.b3ecd767be776p-26, 0x1.dffeb2p-1}, {0x1.b1ad41f07fc1p-27, 0x1.effd52p-1},
    {0x0p+0, 0x1p+0}};
 static const double l2[][2] = {
    {0x0p+0, 0x0p+0}, {-0x1.e2b19f9c7b84p-27, 0x1.00e4p-10},
    {-0x1.b1d68137631fep-27, 0x1.ff1p-10}, {-0x1.aa92227513fc3p-27, 0x1.8026p-9},
    {-0x1.52918e3ab6f5ep-27, 0x1.ff68p-9}, {0x1.1a0b9b9010a9cp-27, 0x1.4019p-8},
    {0x1.09b87f57867ecp-26, 0x1.7fdp-8}, {-0x1.3d6b70c673be6p-28, 0x1.c04cp-8},
    {0x1.76d340a6780abp-27, 0x1.000c8p-7}, {0x1.e4181e37d9e05p-26, 0x1.1ff88p-7},
    {-0x1.8c181f042b901p-27, 0x1.3fea8p-7}, {0x1.9890ae7761d66p-27, 0x1.5fe18p-7},
    {-0x1.55977ae613d5fp-26, 0x1.7fde8p-7}, {0x1.c75f49acf5e56p-27, 0x1.9fe08p-7},
    {-0x1.e1fc84d0d42bcp-28, 0x1.bfe88p-7}, {-0x1.5ab8a182ed279p-26, 0x1.dff6p-7},
    {-0x1.b389a7d8a21d9p-26, 0x1.00048p-6}, {-0x1.7376f1a891fa5p-26, 0x1.1010cp-6},
    {-0x1.0915581b87a8ap-28, 0x1.1ff1p-6}, {0x1.b7f2eaa894fcap-27, 0x1.3002cp-6},
    {-0x1.f8c41bdd38c23p-26, 0x1.3fe8cp-6}, {0x1.04ffb1f3c8215p-28, 0x1.5p-6},
    {0x1.a398ccf2b137dp-26, 0x1.5feb4p-6}, {0x1.373b5bce07f39p-26, 0x1.70084p-6},
    {-0x1.e42040fd9d454p-27, 0x1.7ff94p-6}, {0x1.ea00eb5770526p-27, 0x1.8feccp-6},
    {-0x1.3e2002bb54bb8p-26, 0x1.a0124p-6}, {0x1.797ec835db8d3p-26, 0x1.b00b4p-6},
    {0x1.bdcd45fedd285p-28, 0x1.c0074p-6}, {-0x1.33b8f09d1a21p-28, 0x1.d006p-6},
    {-0x1.58937a8eea36fp-27, 0x1.e0078p-6}, {-0x1.3e76203ff54cdp-27, 0x1.f00bcp-6},
    {-0x1.6560f19fc3f41p-30, 0x1.00096p-5}};
  static const double c[] =
    {-0x1.62e41d56c64p-2, 0x1.47fd2632d2d32p-3, -0x1.5504497831ba7p-4, 0x1.7a3314c5bef3cp-5};
  b64u64_u t = {.f = x};
  int ex = t.u>>52, e = ex - 0x3ff;
  if (__builtin_expect(!ex, 0)){ // 0 or subnormal
    if(!t.u) { // +0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // pole error
#endif
      return -1.0 / 0.0;
    }
    int k = __builtin_clzll(t.u);
    e -= k-12;
    t.u <<= k-11;
  }
  if (__builtin_expect(ex >= 0x7ff, 0)){
    if(!(t.u<<1)) { // -0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // pole error
#endif
      return -1.0 / 0.0;
    }
    if((t.u<<1)>((u64)0x7ff<<53)) return x + x; // nan
    if(t.u>>63) { // < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      return 0.0 / 0.0;
    }
    return x; // inf
  }
  t.u &= ~(u64)0>>12;
  if(__builtin_expect(t.u==0, 0)) return as_log2_exact(e);
  double ed = e;
  u64 i = t.u>>(52-5);
  int64_t d = t.u & (~(u64)0>>17);
  u64 j = (t.u + ((u64)B[i].c0<<33) + ((int64_t)B[i].c1*(d>>16)))>>(52-10);
  t.u |= (int64_t)0x3ff<<52;
  int i1 = j>>5, i2 = j&0x1f;
  const double l2h = 0x1.71548p+0, l2l = -0x1.ad47a2f472159p-22;
  double r = r1[i1]*r2[i2];
  double o = r*t.f, dxl = __builtin_fma(r,t.f,-o), dxh = o - l2h, dx = dxh + dxl, dx2 = dx*dx;
  double f = dx2*((c[0] + dx*c[1]) + dx2*(c[2] + dx*c[3]));
  double lt = (l1[i1][1] + l2[i2][1]) + ed;
  double lh = lt + dxh, ll = (lt - lh) + dxh;
  ll += ((l1[i1][0] + l2[i2][0]) + dxl) + dxh*l2l;
  ll += f;
  const double eps = 1.6e-22;
  double lb = lh + (ll - eps), ub = lh + (ll + eps);
  if(__builtin_expect(lb==ub, 1)) return lb;
  return as_log2_refine(x, ub);
}

static double __attribute__((noinline)) as_log2_refine(double x, double a){
  static const double t1[] = {
    0x1p+0, 0x1.ea4afap-1, 0x1.d5818ep-1, 0x1.c199bep-1, 0x1.ae89f98p-1, 0x1.9c4918p-1,
    0x1.8ace54p-1, 0x1.7a1147p-1, 0x1.6a09e68p-1, 0x1.5ab07ep-1, 0x1.4bfdad8p-1,
    0x1.3dea65p-1, 0x1.306fe08p-1, 0x1.2387a7p-1, 0x1.172b84p-1, 0x1.0b5587p-1, 0x1p-1};
  static const double t2[] = {
    0x1p+0, 0x1.fe9d968p-1, 0x1.fd3c228p-1, 0x1.fbdba38p-1, 0x1.fa7c18p-1, 0x1.f91d8p-1,
    0x1.f7bfdbp-1, 0x1.f663278p-1, 0x1.f507658p-1, 0x1.f3ac948p-1, 0x1.f252b38p-1,
    0x1.f0f9c2p-1, 0x1.efa1bfp-1, 0x1.ee4aaap-1, 0x1.ecf483p-1, 0x1.eb9f488p-1};
  static const double t3[] = {
    0x1p+0, 0x1.ffe9d2p-1, 0x1.ffd3a58p-1, 0x1.ffbd798p-1, 0x1.ffa74e8p-1, 0x1.ff91248p-1,
    0x1.ff7afb8p-1, 0x1.ff64d38p-1, 0x1.ff4eac8p-1, 0x1.ff38868p-1, 0x1.ff22618p-1,
    0x1.ff0c3dp-1, 0x1.fef61ap-1, 0x1.fedff78p-1, 0x1.fec9d68p-1, 0x1.feb3b6p-1};
  static const double t4[] = {
    0x1p+0, 0x1.fffe9dp-1, 0x1.fffd3ap-1, 0x1.fffbd78p-1, 0x1.fffa748p-1, 0x1.fff9118p-1,
    0x1.fff7ae8p-1, 0x1.fff64cp-1, 0x1.fff4e9p-1, 0x1.fff386p-1, 0x1.fff2238p-1,
    0x1.fff0c08p-1, 0x1.ffef5d8p-1, 0x1.ffedfa8p-1, 0x1.ffec98p-1, 0x1.ffeb35p-1};
  static const double LL[4][17][3] = {
    {{0x0p+0, 0x0p+0, 0x0p+0}, {0x1.000001fdap-4, 0x1.5ed58a7ff2c4p-42, 0x1.512acbb219717p-96},
     {0x1.fffffda07p-4, -0x1.b38ae1c2d54p-47, -0x1.10f11908c5c8dp-93},
     {0x1.7ffffefb5p-3, 0x1.785d91bb0832p-43, 0x1.f5ded30ca48cp-93},
     {0x1.0000004a6p-2, 0x1.380abf8fe7ebp-42, -0x1.ebd3f567df886p-93},
     {0x1.400000976p-2, 0x1.d321385bf0a1p-43, -0x1.c95a3d59b6c33p-94},
     {0x1.80000081b4p-2, 0x1.b6e8f25ff261p-42, -0x1.4072d39d4427p-93},
     {0x1.c00000f4f4p-2, 0x1.a5fed334580ap-43, -0x1.6f8fdabadd77ap-96},
     {0x1.ffffff9dep-2, -0x1.f85a54fb4a6p-43, -0x1.50083897ee638p-96},
     {0x1.1fffffa35cp-1, 0x1.795db9d18514p-42, -0x1.594f07d4d693fp-94},
     {0x1.3fffff9cbcp-1, 0x1.2fb09a99477ap-44, 0x1.b2c6248382152p-94},
     {0x1.5fffff6df2p-1, -0x1.3ecf24077c3ap-42, -0x1.382c6b4e2daa6p-93},
     {0x1.800000552ep-1, 0x1.7044806f7238p-43, -0x1.6da3eb126c999p-93},
     {0x1.9fffffc182p-1, 0x1.5cf031d5d4cfp-43, 0x1.302c44da79f4bp-93},
     {0x1.bfffff6b62p-1, 0x1.48d11d13372a8p-42, 0x1.f045032543c0dp-93},
     {0x1.dfffff7a42p-1, -0x1.0cbf3e62fa86p-43, 0x1.1cfaf84227211p-93}, {1, 0, 0}},
    {{0x0p+0, 0x0p+0, 0x0p+0}, {0x1.000024ap-8, -0x1.799935d03065p-42, -0x1.cacad0b61c964p-95},
     {0x1.000014a88p-7, -0x1.86dd926d35ee8p-42, -0x1.277ab54c00e64p-93},
     {0x1.7ffff7b38p-7, 0x1.5ffc7ff00e6p-46, 0x1.5870383c1225dp-93},
     {0x1.000004b94p-6, -0x1.4aa9da7ea012p-43, -0x1.47decfe981022p-93},
     {0x1.400006438p-6, -0x1.015d79fd24c7p-42, 0x1.ec26c231ddb4cp-93},
     {0x1.7ffff8ff8p-6, -0x1.a62a2b755f048p-42, -0x1.eebe936e9a3f9p-93},
     {0x1.c00004818p-6, 0x1.d1a1bbce5f58p-46, -0x1.4dd25e141ad16p-93},
     {0x1.0000050eep-5, -0x1.b32450688d5ep-42, 0x1.577a1c80a65bp-93},
     {0x1.200001476p-5, -0x1.bac8f6c103d4p-44, -0x1.157a2472c9532p-94},
     {0x1.3fffff244p-5, -0x1.fbab0c9d05aap-43, -0x1.3680ffabf1a5bp-94},
     {0x1.5ffffb1cep-5, 0x1.ef9ec2ba4914p-43, -0x1.24850720b73abp-93},
     {0x1.7ffffd96p-5, 0x1.14e3a91abeffp-42, -0x1.40e3565c114ddp-94},
     {0x1.a0000321cp-5, 0x1.e33c6a073234p-44, -0x1.7e8c937a981d8p-93},
     {0x1.bffffc56ap-5, -0x1.2076781ff046p-42, -0x1.96e054ec8f31ep-93},
     {0x1.dffffdba4p-5, -0x1.ea8b4476eddep-43, -0x1.07bfb9fde770fp-97},
     {0x1.000001fdap-4, 0x1.5ed58a7ff2c4p-42, 0x1.512acbb219717p-96}, },
    {{0x0p+0, 0x0p+0, 0x0p+0}, {0x1.0002866p-12, -0x1.329e31412b688p-42, 0x1.279ddc3585863p-93},
     {0x1.fffed31p-12, 0x1.546dcb40b0518p-42, -0x1.6d048f41debecp-93},
     {0x1.8000388p-11, 0x1.fce6789678c88p-42, 0x1.4959dc2fea03p-93},
     {0x1.00006684p-10, 0x1.c5caec0aa662p-42, -0x1.89d58a2e0d287p-93},
     {0x1.4000937p-10, -0x1.df91bf5db20f8p-42, 0x1.d4fc35005498ap-93},
     {0x1.8000a2d8p-10, 0x1.e7464f400a7p-44, -0x1.6365a147ce4a8p-93},
     {0x1.c00094a4p-10, -0x1.c55c526e65a68p-42, -0x1.a7ea2cf16d2cep-93},
     {0x1.00003454p-9, 0x1.8e815121136dp-43, -0x1.68f8f7a924fd6p-94},
     {0x1.20000f64p-9, 0x1.7fb19a44da298p-42, -0x1.a05fc6ed4124dp-93},
     {0x1.3fffdb7p-9, 0x1.bfac3b1abe2e8p-42, -0x1.9ab1f45a1efb1p-95},
     {0x1.6000516ap-9, -0x1.02544d9faf83p-43, 0x1.286c39adffa8cp-93},
     {0x1.7fffff42p-9, -0x1.2878b893da79p-42, 0x1.b55c5e09022b1p-93},
     {0x1.a00056f4p-9, -0x1.9d7ccf4019608p-42, 0x1.f4b05553fe34p-93},
     {0x1.bfffe652p-9, -0x1.ee85f47c2b5ap-42, 0x1.53fa913d4e9a6p-93},
     {0x1.e0001f76p-9, 0x1.2e594fb2af5ep-43, -0x1.afaec77ca8d86p-99},
     {0x1.000024ap-8, -0x1.799935d03065p-42, -0x1.cacad0b61c964p-95}, },
    {{0x0p+0, 0x0p+0, 0x0p+0}, {0x1.001469p-16, -0x1.743d8ea40a4dp-43, -0x1.75086a21c12abp-97},
     {0x1.0014c18p-15, 0x1.8e7fa3cf5908p-43, 0x1.a11bdcdb1ace3p-93},
     {0x1.7ff17c8p-15, 0x1.118dbbcce847p-42, 0x1.09806ecd1976p-95},
     {0x1.fffcbb8p-15, -0x1.eaa70b2051e38p-42, 0x1.0d287c5aa12b4p-97},
     {0x1.4004294p-14, 0x1.602b04d79b0c8p-42, 0x1.8d2c8ddf31648p-96},
     {0x1.800a218p-14, -0x1.0a2311217863p-42, -0x1.c4652435118f1p-93},
     {0x1.bff9304p-14, -0x1.385dc475c16bp-43, -0x1.e7288f74bbbdap-96},
     {0x1.ffff81p-14, 0x1.355edcff4e19p-43, 0x1.f8daae6c1db11p-95},
     {0x1.2002ff2p-13, 0x1.3fbb7cd36614p-45, 0x1.93c0e5b4dca92p-93},
     {0x1.3ffac9p-13, -0x1.9bde416de25cp-44, -0x1.f4df1d74776b3p-93},
     {0x1.5ffe34p-13, -0x1.21735d0955dcp-42, -0x1.1b0e10765842fp-93},
     {0x1.8001b52p-13, 0x1.0c0949e96881p-43, -0x1.d3771c0b220f3p-94},
     {0x1.a0054c8p-13, 0x1.26936197b105p-43, 0x1.e59caa334554ap-93},
     {0x1.bffd6fp-13, 0x1.27097b0b27d4p-43, 0x1.78a37896a0d1fp-93},
     {0x1.e00132cp-13, 0x1.df1e08412028p-44, 0x1.c61f449a4b5d5p-94},
     {0x1.0002866p-12, -0x1.329e31412b688p-42, 0x1.279ddc3585863p-93}}};
  static const double cy[][2] = {
    {0x1.71547652b82fep+0, 0x1.777d0ffda0d24p-56}, {-0x1.71547652b82fep-1, -0x1.777d0ffda0d24p-57},
    {0x1.ec709dc3a03fdp-2, 0x1.d27e96be541e5p-56}};
  static const double cl[3] = {-0x1.71547652b82fep-2, 0x1.2776c50f1ff14p-2, -0x1.ec709dc3eca5dp-3};
  b64u64_u t = {.f = x};
  int ex = t.u>>52, e = ex-0x3ff;
  if (__builtin_expect(!ex, 0)){ // 0 or subnormal
    int k = __builtin_clzll(t.u);
    e -= k-12;
    t.u <<= k-11;
  }
  t.u &= ~(u64)0>>12;
  t.u |= (u64)0x3ff<<52;
  double ed = e;
  b64u64_u v = {.f = a - ed + 0x1.00008p+0};
  u64 i = (v.u - ((u64)0x3ff<<52))>>(52-16);  
  int i1 = i>>12, i2 = (i>>8)&0xf, i3 = (i>>4)&0xf, i4 = i&0xf;
  double L[3];
  L[0] = LL[0][i1][0] + LL[1][i2][0] + (LL[2][i3][0] + LL[3][i4][0]) + ed;
  L[1] = LL[0][i1][1] + LL[1][i2][1] + (LL[2][i3][1] + LL[3][i4][1]);
  L[2] = LL[0][i1][2] + LL[1][i2][2] + (LL[2][i3][2] + LL[3][i4][2]);
  double t12 = t1[i1]*t2[i2], t34 = t3[i3]*t4[i4];
  double th = t12*t34, tl = __builtin_fma(t12,t34,-th);
  double dh = th*t.f, dl = __builtin_fma(th,t.f,-dh);
  double sh = tl*t.f, sl = __builtin_fma(tl,t.f,-sh);
  double xl, xh = fasttwosum(dh-1, dl, &xl);
  xh = adddd(xh, xl, sh, sl, &xl);
  sl = xh*(cl[0] + xh*(cl[1] + xh*cl[2]));
  sh = polydd(xh, xl, 3, cy, &sl);
  sh = muldd(xh, xl, sh, sl, &sl);
  sh = adddd(sh, sl, L[1], L[2], &sl);
  double v2, v0 = fasttwosum(L[0], sh, &v2), v1 = fasttwosum(v2, sl, &v2);
  t.f = v1;
  if(__builtin_expect(!(t.u&(~(u64)0>>12)), 0)){
    b64u64_u w = {.f = v2};
    if((w.u^t.u)>>63)
      t.u--;
    else
      t.u++;
    v1 = t.f;
  }
  return v1 + v0;
}
