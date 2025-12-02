/* Correctly rounded log(1+x) for binary64 values.

Copyright (c) 2024-2025 Alexei Sibidanov.

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

/* __builtin_roundeven was introduced in gcc 10:
   https://gcc.gnu.org/gcc-10/changes.html,
   and in clang 17 */
#if ((defined(__GNUC__) && __GNUC__ >= 10) || (defined(__clang__) && __clang_major__ >= 17)) && (defined(__aarch64__) || defined(__x86_64__) || defined(__i386__))
# define roundeven_finite(x) __builtin_roundeven (x)
#else
/* round x to nearest integer, breaking ties to even */
static double
roundeven_finite (double x)
{
  double ix;
# if (defined(__GNUC__) || defined(__clang__)) && (defined(__AVX__) || defined(__SSE4_1__) || (__ARM_ARCH >= 8))
#  if defined __AVX__
   __asm__("vroundsd $0x8,%1,%1,%0":"=x"(ix):"x"(x));
#  elif __ARM_ARCH >= 8
   __asm__ ("frintn %d0, %d1":"=w"(ix):"w"(x));
#  else /* __SSE4_1__ */
   __asm__("roundsd $0x8,%1,%0":"=x"(ix):"x"(x));
#  endif
# else
  ix = __builtin_round (x); /* nearest, away from 0 */
  if (__builtin_fabs (ix - x) == 0.5)
  {
    /* if ix is odd, we should return ix-1 if x>0, and ix+1 if x<0 */
    union { double f; uint64_t n; } u, v;
    u.f = ix;
    v.f = ix - __builtin_copysign (1.0, x);
    if (__builtin_ctz (v.n) > __builtin_ctz (u.n))
      ix = v.f;
  }
# endif
  return ix;
}
#endif

typedef uint64_t u64;
typedef int64_t i64;
typedef unsigned short ushort;
typedef union {double f; uint64_t u;} b64u64_u;

static inline double fasttwosum(double x, double y, double *e){
  double s = x + y, z = s - x;
  *e = y - z;
  return s;
}

static inline double twosum(double xh, double ch, double *l){
  double s = xh + ch, d = s - xh;
  *l = (ch - d) + (xh + (d - s));
  return s;
}

static inline double fastsum(double xh, double xl, double yh, double yl, double *e){
  double sl, sh = fasttwosum(xh, yh, &sl);
  *e = (xl + yl) + sl;
  return sh;
}

static inline double sum(double xh, double xl, double ch, double cl, double *l){
  double sl, sh = twosum(xh,ch, &sl);
  *l = (xl + cl) + sl;
  return sh;
}

static inline double muldd(double xh, double xl, double ch, double cl, double *l){
  double ahhh = ch*xh;
  *l = (cl*xh + ch*xl) + __builtin_fma(ch, xh, -ahhh);
  return ahhh;
}

static inline double mulddd(double x, double ch, double cl, double *l){
  double ahhh = ch*x;
  *l = cl*x + __builtin_fma(ch, x, -ahhh);
  return ahhh;
}

static inline double polydd(double xh, double xl, int n, const double c[][2], double *l){
  int i = n-1;
  double ch = fasttwosum(c[i][0], *l, l), cl = c[i][1] + *l;
  while(--i>=0){
    ch = muldd(xh,xl, ch,cl, &cl);
    ch = fastsum(c[i][0],c[i][1], ch,cl, &cl);
  }
  *l = cl;
  return ch;
}

static inline double polyddd(double x, int n, const double c[][2], double *l){
  int i = n-1;
  double ch = fasttwosum(c[i][0], *l, l), cl = c[i][1] + *l;
  while(--i>=0){
    ch = mulddd(x, ch,cl, &cl);
    ch = fastsum(c[i][0],c[i][1], ch,cl, &cl);
  }
  *l = cl;
  return ch;
}

static double __attribute__((noinline)) as_log1p_refine(double, double);

/*
  rt[4][16] and ln[4][16][3] are lookup tables for the quadripartite scheme
  centered around zero.
  -ln(rt[][]) = ln[][][2] + ln[][][1] + ln[][][0]
*/
static const double rt[4][16] = {
  {0x1.6a09e68p+0, 0x1.5ab07ep+0, 0x1.4bfdad8p+0, 0x1.3dea65p+0,
   0x1.306fe08p+0, 0x1.2387a7p+0, 0x1.172b84p+0, 0x1.0b5587p+0,
   0x1p+0, 0x1.ea4afap-1, 0x1.d5818ep-1, 0x1.c199bep-1,
   0x1.ae89f98p-1, 0x1.9c4918p-1, 0x1.8ace54p-1, 0x1.7a1147p-1},
  {0x1.059b0dp+0, 0x1.04e5f7p+0, 0x1.04315e8p+0, 0x1.037d43p+0,
   0x1.02c9a4p+0, 0x1.0216818p+0, 0x1.0163da8p+0, 0x1.00b1af8p+0,
   0x1p+0, 0x1.fe9d968p-1, 0x1.fd3c228p-1, 0x1.fbdba38p-1,
   0x1.fa7c18p-1, 0x1.f91d8p-1, 0x1.f7bfdbp-1, 0x1.f663278p-1},
  {0x1.0058c88p+0, 0x1.004dad8p+0, 0x1.0042938p+0, 0x1.0037798p+0,
   0x1.002c608p+0, 0x1.0021478p+0, 0x1.00162fp+0, 0x1.000b178p+0,
   0x1p+0, 0x1.ffe9d2p-1, 0x1.ffd3a58p-1, 0x1.ffbd798p-1,
   0x1.ffa74e8p-1, 0x1.ff91248p-1, 0x1.ff7afb8p-1, 0x1.ff64d38p-1},
  {0x1.00058b8p+0, 0x1.0004dap+0, 0x1.0004288p+0, 0x1.0003778p+0,
   0x1.0002c6p+0,  0x1.0002148p+0, 0x1.000163p+0, 0x1.0000b18p+0,
   0x1p+0, 0x1.fffe9dp-1, 0x1.fffd3ap-1, 0x1.fffbd78p-1,
   0x1.fffa748p-1, 0x1.fff9118p-1, 0x1.fff7ae8p-1, 0x1.fff64cp-1}
};

static const double ln[4][16][3] = {
  {{0x1.61fa45b636ea2p-95, -0x1.497697cb3134p-45, -0x1.62e43033a8p-2},
   {-0x1.42b671e5e6d5ep-93, 0x1.fc50ee605bd8p-44, -0x1.3687aa721cp-2},
   {0x1.0cc2ea968d329p-95, 0x1.f48666c24eacp-43, -0x1.0a2b247d58p-2},
   {-0x1.963904db0a34ep-93, -0x1.58495e50d36ap-43, -0x1.bb9d3d808p-3},
   {0x1.337e0d9f81652p-95, 0x1.c89a0bede978p-45, -0x1.62e42f0378p-3},
   {-0x1.1bdf53871d50bp-95, 0x1.2d67e8a0c1d7p-42, -0x1.0a2b24a1p-3},
   {-0x1.781dd6fc4053p-98, 0x1.07a22a9e81ed8p-42, -0x1.62e43327cp-4},
   {-0x1.84e4562b8f2f3p-96, -0x1.868afe14895p-43, -0x1.62e435baep-5},
   {0x0p+0, 0x0p+0, 0x0p+0},
   {-0x1.17e3ec05cde7p-96, 0x1.174a19689569p-42, 0x1.62e432b22p-5},
   {-0x1.8067ec2a27738p-95, 0x1.111a4eadf313p-43, 0x1.62e42e4a8p-4},
   {-0x1.60bef06b14405p-93, 0x1.dd4ec4e1d421p-43, 0x1.0a2b233f08p-3},
   {-0x1.b18e160362c24p-94, 0x1.6bd65e8b0b7p-45, 0x1.62e43056cp-3},
   {-0x1.c6ac3f1862a6bp-93, -0x1.0f5aad509ea8p-44, 0x1.bb9d3cbd68p-3},
   {-0x1.dead1a4581acfp-93, -0x1.ac842de00564p-43, 0x1.0a2b244da4p-2},
   {-0x1.96b1f2f60e3e4p-93, 0x1.9cec9a50db228p-42, 0x1.3687aa9b78p-2}},
  {{0x1.dbd93cdc08613p-96, 0x1.96f39c49fa8ap-44, -0x1.62e423dd4p-6},
   {-0x1.3c008f058a015p-94, -0x1.f26429af65b7p-43, -0x1.36879e514p-6},
   {0x1.f96a86136c1d1p-93, -0x1.bfc5afb2bd378p-42, -0x1.0a2b2240cp-6},
   {0x1.3917cea885bep-93, -0x1.421e0c297638p-46, -0x1.bb9d4b288p-7},
   {0x1.f0f1b5d989675p-93, 0x1.92a7506c90a18p-42, -0x1.62e43c12p-7},
   {-0x1.f7f8d6a190051p-93, -0x1.94925ae0e524p-42, -0x1.0a2b41ddp-7},
   {0x1.ccb0919263869p-94, -0x1.0fb337ff2cf28p-42, -0x1.62e41068p-8},
   {0x1.c9a5efe4b7c6cp-93, -0x1.966c27788d1cp-44, -0x1.62e3e4ccp-9},
   {0x0p+0, 0x0p+0, 0x0p+0},
   {-0x1.40288ccae8f0fp-95, -0x1.f3c5ff88d19c8p-42, 0x1.62e462b6p-9},
   {-0x1.f7e788a87135p-94, -0x1.a9610028771cp-43, 0x1.62e44c93p-8},
   {0x1.574cc6d3f577dp-93, 0x1.2a3a1a65aa398p-42, 0x1.0a2b1e33p-7},
   {-0x1.56bb79b254f33p-99, -0x1.4a995b6d9ddcp-44, 0x1.62e4367cp-7},
   {0x1.c4c209ca6783dp-94, -0x1.d7b98ef45911p-43, 0x1.bb9d449a8p-7},
   {0x1.e9731de7f0155p-93, -0x1.de722390bbd6p-43, 0x1.0a2b1f194p-6},
   {0x1.fadc62522444dp-96, -0x1.fd95cb835e38p-45, 0x1.3687ad114p-6}},
  {{-0x1.1f72d2a6a460ep-95, 0x1.a25045c37c33p-43, -0x1.62e4795p-10},
   {0x1.2847e318fd3ffp-93, -0x1.c633239e1cdc8p-42, -0x1.3686e5dcp-10},
   {0x1.63f5750b9d826p-93, -0x1.cb15590f1cd78p-42, -0x1.0a2b6538p-10},
   {-0x1.1382d6395c24cp-94, 0x1.7636a5400e2bp-43, -0x1.bb9bf138p-11},
   {0x1.be4491ec20322p-94, 0x1.d0c5e2c9b6be8p-42, -0x1.62e53e5p-11},
   {-0x1.706f04cc2c9f6p-93, -0x1.f3bc0ce9b9a08p-42, -0x1.0a2ab37p-11},
   {0x1.ab6f41df01d7fp-93, 0x1.a7cbc9a97ba4p-44, -0x1.62e0ap-12},
   {-0x1.67e487663ca3ep-100, -0x1.957976dc5f36p-43, -0x1.62e84fcp-13},
   {0x0p+0, 0x0p+0, 0x0p+0},
   {0x1.9681e48dde135p-93, -0x1.868625640a69p-43, 0x1.62e7bp-13},
   {0x1.a2948cd558655p-93, -0x1.2ee3d96b696ap-42, 0x1.62e35f6p-12},
   {-0x1.cfc26ccf6d0e4p-96, 0x1.53edbcf1165p-46, 0x1.0a2b4b2p-11},
   {0x1.f68d24b9e338dp-93, 0x1.783e334613p-51, 0x1.62e4be1p-11},
   {-0x1.f33369bf7dff1p-95, -0x1.60785f20acb2p-42, 0x1.bb9e085p-11},
   {-0x1.685a35575eff1p-95, -0x1.5a62ec66568p-48, 0x1.0a2b94d4p-10},
   {-0x1.4c4d1abca79bfp-95, 0x1.7ded26dc813p-46, 0x1.368810f8p-10}},
  {{0x1.40676dea39b19p-94, 0x1.25337681fa9p-42, -0x1.62dc284p-14},
   {-0x1.ec76c964ac8d6p-94, -0x1.504032e2ed388p-42, -0x1.367d0ecp-14},
   {0x1.8ecaeb6d9523cp-95, 0x1.c28fde83047ep-44, -0x1.0a1dd6cp-14},
   {-0x1.e4069214576bep-93, 0x1.58f2757976ef8p-42, -0x1.bbbcffp-15},
   {0x1.86146d1f9b91fp-93, -0x1.d4717ca0a323p-42, -0x1.62fe138p-15},
   {0x1.1eb44b07102c5p-93, -0x1.86ffcda25278p-43, -0x1.0a3eebp-15},
   {-0x1.95bbb5fd5a466p-93, 0x1.1ce399729e7bp-43, -0x1.62ff0ap-16},
   {-0x1.79059023f8767p-93, -0x1.dbf1c6a400408p-42, -0x1.62ff84p-17},
   {0x0p+0, 0x0p+0, 0x0p+0},
   {-0x1.b4cb08d6fd48fp-93, -0x1.db0e38e5aaa98p-42, 0x1.63007cp-17},
   {-0x1.0e6a88bfc3838p-93, 0x1.2b1c75580439p-43, 0x1.6300f6p-16},
   {0x1.8074feacfe49dp-94, 0x1.401bb919f14ep-42, 0x1.0a21148p-15},
   {-0x1.f56f5f168db15p-93, -0x1.85d6f6487ce2p-44, 0x1.62e1ecp-15},
   {0x1.9eae7e05a0143p-93, -0x1.af5d58a7c9218p-42, 0x1.bba301p-15},
   {-0x1.a859095999ae3p-94, 0x1.590faa0883bd8p-42, 0x1.0a32298p-14},
   {0x1.4f787e495e5ep-93, -0x1.fbb791220a18p-46, 0x1.3682f14p-14}}
};

/*
  rf[64] and lf[64][2] are lookup tables for the fast path
  -ln(rf[][]) = lf[][1] + lf[][0]
  values are approximately from 1/sqrt(2) to sqrt(2)
*/
static const double rf[64] = {
  0x1.6816818p+0, 0x1.642c858p+0, 0x1.605816p+0, 0x1.5c98828p+0,
  0x1.58ed23p+0, 0x1.5555558p+0, 0x1.51d07e8p+0, 0x1.4e5e0a8p+0,
  0x1.4afd6ap+0, 0x1.47ae148p+0, 0x1.446f868p+0, 0x1.4141418p+0,
  0x1.3e22ccp+0, 0x1.3b13b1p+0, 0x1.381381p+0, 0x1.3521cf8p+0,
  0x1.323e348p+0, 0x1.2f684cp+0, 0x1.2c9fb5p+0, 0x1.29e4128p+0,
  0x1.27350b8p+0, 0x1.249249p+0, 0x1.21fb78p+0, 0x1.1f7048p+0,
  0x1.1cf06bp+0, 0x1.1a7b96p+0, 0x1.181181p+0, 0x1.15b1e6p+0,
  0x1.135c81p+0, 0x1.111111p+0, 0x1.0ecf568p+0, 0x1.0c9715p+0,
  0x1.0a68108p+0, 0x1.0842108p+0, 0x1.0624ddp+0, 0x1.041041p+0,
  0x1.020408p+0, 0x1p+0, 0x1.f81f82p-1, 0x1.f07c1fp-1,
  0x1.e9131a8p-1, 0x1.e1e1e2p-1, 0x1.dae6078p-1, 0x1.d41d42p-1,
  0x1.cd85688p-1, 0x1.c71c72p-1, 0x1.c0e07p-1, 0x1.bacf918p-1,
  0x1.b4e81b8p-1, 0x1.af286cp-1, 0x1.a98ef6p-1, 0x1.a41a418p-1,
  0x1.9ec8e98p-1, 0x1.9999998p-1, 0x1.948b1p-1, 0x1.8f9c19p-1,
  0x1.8acb91p-1, 0x1.8618618p-1, 0x1.8181818p-1, 0x1.7d05f4p-1,
  0x1.78a4c8p-1, 0x1.745d178p-1, 0x1.702e06p-1, 0x1.6c16c18p-1
};

static const double lf[64][2] = {
  {-0x1.f2f8281bade6ap-42, -0x1.5d5bde3994p-2}, {0x1.c2843fdd367a4p-42, -0x1.522ae0438cp-2},
  {-0x1.06c10c34c14bp-44, -0x1.4718dc171cp-2}, {0x1.cfa4e853f589p-43, -0x1.3c2526cb34p-2},
  {-0x1.ce3ac179bd856p-42, -0x1.314f1e0534p-2}, {-0x1.b91f82deb8122p-42, -0x1.269621934cp-2},
  {0x1.46bbb83d7163ep-42, -0x1.1bf995a9a8p-2}, {0x1.b842e5a74bdbp-42, -0x1.1178e84a8p-2},
  {-0x1.862715e5bb534p-42, -0x1.071385f4d4p-2}, {-0x1.9bcbcbea0cdf8p-42, -0x1.f991c6eb38p-3},
  {-0x1.01101cb605958p-43, -0x1.e530f1067p-3}, {0x1.0c38c81ad8f06p-42, -0x1.d10380b658p-3},
  {0x1.3aa40992a6d82p-42, -0x1.bd0874c3cp-3}, {0x1.30f68780ae82ep-42, -0x1.a93ed248bp-3},
  {-0x1.7d116989d098p-47, -0x1.95a5ac5f7p-3}, {-0x1.1e0012ba619cap-42, -0x1.823c150518p-3},
  {0x1.54535d5671858p-43, -0x1.6f0127cf58p-3}, {-0x1.ed87db3498128p-42, -0x1.5bf407b54p-3},
  {-0x1.aafde9c9fc39ap-42, -0x1.4913d94338p-3}, {-0x1.015868c234p-43, -0x1.365fca3158p-3},
  {0x1.eff33f502c226p-42, -0x1.23d7126cap-3}, {0x1.b8521e874d358p-43, -0x1.1178e7228p-3},
  {0x1.54d75afe84568p-43, -0x1.fe89129dcp-4}, {-0x1.1a813f3fa7c1ep-42, -0x1.da7278384p-4},
  {-0x1.6c6676f40963ep-42, -0x1.b6ac8afadp-4}, {-0x1.2620b7957a7a6p-42, -0x1.9335e4d59p-4},
  {0x1.f8ffee5598f38p-43, -0x1.700d2f4ebp-4}, {-0x1.fab0f5bf42ca2p-42, -0x1.4d311652p-4},
  {-0x1.7a3e970b1c3a8p-44, -0x1.2aa049247p-4}, {-0x1.d030435fecb5p-43, -0x1.08598a59ep-4},
  {0x1.35084a4fb8ab8p-43, -0x1.ccb7357dep-5}, {0x1.32f36d60b44c4p-43, -0x1.894aa1cap-5},
  {0x1.c1bcce5be811p-45, -0x1.466ae8a2ep-5}, {0x1.777740b18714ap-42, -0x1.0415d81e8p-5},
  {-0x1.955c057693d94p-43, -0x1.8492470c8p-6}, {0x1.4f71addb8bep-43, -0x1.020564894p-6},
  {-0x1.bcda4e198afbp-44, -0x1.01014f588p-7}, {0x1.cp-67, 0x0p+0},
  {-0x1.fe0df75092c5ep-42, 0x1.fc0a891p-7}, {0x1.98036ec7e0a1p-45, 0x1.f829b1e78p-6},
  {0x1.ba010f49e5ffp-42, 0x1.774593832p-5}, {-0x1.3ab13c266d328p-42, 0x1.f0a30a012p-5},
  {-0x1.71798573e45d4p-43, 0x1.341d78b1cp-4}, {0x1.ad32f072669fcp-42, 0x1.6f0d272e5p-4},
  {-0x1.54e391e16ea38p-43, 0x1.a926d434bp-4}, {-0x1.a302bbaf0559p-45, 0x1.e27074e2bp-4},
  {0x1.cb4cd66e31f3p-44, 0x1.0d77e8cd08p-3}, {-0x1.5b7a5bc474128p-44, 0x1.29552e92p-3},
  {-0x1.7062e8135f74p-46, 0x1.44d2b5e4b8p-3}, {0x1.3d4c88fe1f4bp-43, 0x1.5ff3060a78p-3},
  {-0x1.37b70004a6946p-42, 0x1.7ab890411p-3}, {-0x1.4a5885167c1ecp-42, 0x1.9525aa7f48p-3},
  {0x1.ff9d5953004acp-42, 0x1.af3c940008p-3}, {0x1.a21ec41d8219cp-43, 0x1.c8ff7cf9a8p-3},
  {-0x1.a322bf2f02ae8p-44, 0x1.e27075e2bp-3}, {0x1.f1548b8a33616p-42, 0x1.fb9186b5ep-3},
  {0x1.0e36401f7a006p-42, 0x1.0a324e0f38p-2}, {-0x1.9f1fa55382a8ap-42, 0x1.1675cacabcp-2},
  {-0x1.a69763deb096p-44, 0x1.22941fc0f8p-2}, {0x1.d30bc3ac91bdap-42, 0x1.2e8e2bee1p-2},
  {0x1.7a79cf4d73b28p-44, 0x1.3a64c59694p-2}, {0x1.ec345197b22dep-42, 0x1.4618bb81c4p-2},
  {-0x1.f4810a30aeba8p-44, 0x1.51aad7c2ep-2}, {0x1.394d2371c1d1cp-43, 0x1.5d1bdbbd8p-2}
};

double cr_log1p(double x){
  b64u64_u ix = {.f = x};
  u64 ax = ix.u<<1;
  double ln1, ln0, eps;
  /* logp1 is expected to be used for x near 0, where it is more accurate than
     log(1+x), thus we expect x near 0 */
  if(__builtin_expect(ax<0x7f60000000000000ull, 1)){ // |x| < 0.0625
    // check case x tiny first to avoid spurious underflow in x*x
    if(__builtin_expect(ax<0x7940000000000000ull, 0)){ // |x| < 0x1p-53
      if(!ax) return x;
      /* we have underflow when |x| < 2^-1022, or when |x| = 2^-1022 and
         the result is smaller than 2^-1022 in absolute value */
      double res = __builtin_fma(__builtin_fabs(x), -0x1p-54, x);
#ifdef CORE_MATH_SUPPORT_ERRNO
      if (__builtin_fabs (x) < 0x1p-1022 || __builtin_fabs (res) < 0x1p-1022)
        errno = ERANGE; // underflow
#endif
      return res;
    }
    double x2 = x*x;
    if(__builtin_expect(ax<0x7e60000000000000ull, 1)){ // |x| < 0x1p-12
      ln1 = x;
      eps = 0x1.6p-64*x;
      if(__builtin_expect(ax<0x7d43360000000000ull, 1)){ // |x| < 0x1.19bp-21
	static const double c[] = {-0x1.00000000001d1p-1, 0x1.55555555558f7p-2};
	ln0 = x2*(c[0] + x*c[1]);
      } else {
	static const double c[] =
	  {-0x1.ffffffffffffdp-2, 0x1.5555555555551p-2, -0x1.000000d5555e1p-2, 0x1.99999b442f73fp-3};
	ln0 = x2*((c[0]+x*c[1])+x2*(c[2]+x*c[3]));
      }
    } else {
      static const double c[] =
	{0x1.5555555555555p-2, -0x1p-2, 0x1.9999999999b41p-3, -0x1.555555555583bp-3,
	 0x1.24924923f39ep-3, -0x1.fffffffe42e43p-4, 0x1.c71c75511d70bp-4, -0x1.99999de10510fp-4,
	 0x1.7457e81b175f6p-4, -0x1.554fb43e54e0fp-4, 0x1.3ed68744f3d18p-4, -0x1.28558ad5a7ac4p-4};
      double x3 = x2*x, x4 = x2*x2, hx = -0.5*x;
      ln1 = __builtin_fma(hx,x,x);
      ln0 = __builtin_fma(hx,x,x-ln1);
      double f = ((c[0]+x*c[1])+x2*(c[2]+x*c[3])) +
	x4*(((c[4]+x*c[5])+x2*(c[6]+x*c[7])) + x4*((c[8]+x*c[9])+x2*(c[10]+x*c[11])));
      ln0 += x3*f;
      eps = x3*0x1.94p-52;
    }
  } else { // |x| >= 0.0625
    static const double c[] = {
      -0x1.000000000003dp-1, 0x1.5555555554cf5p-2, -0x1.ffffffeca2939p-3, 0x1.99999a3661724p-3,
      -0x1.555d345bfe6fdp-3, 0x1.247b887a6e5edp-3};
    b64u64_u t, dt;
    if(__builtin_expect((i64)ix.u<0x4340000000000000ll && ix.u<0xbff0000000000000ull, 1)){
      /* 0.0625 < x < 0x1p+53 or -1 < x < -0.0625. In the case 1 < x < 2^53
         the fasttwosum() pre-condition is not fulfilled. But in that case
         the 2nd operation z = s - x = s - 1 of fasttwosum() is exact, since
         x+y <= 2^53, thus the last operation computes e = (x+y) - s, which is
         exact by Sterbenz theorem. */
      t.f = fasttwosum(1.0, x, &dt.f);
    } else {
      if(__builtin_expect(ix.u<0x4690000000000000ull, 1)){ // x < 0x1p+106
	t.f = x; dt.f = 1;
      } else {
	if(__builtin_expect(ix.u<0x7ff0000000000000ull, 1)){ // x < 0x1p+1024
	  t.f = x; dt.f = 0;
	} else {
	  if(ax>0xffe0000000000000ull) return x + x; // nan
	  if(ix.u==0x7ff0000000000000ull) return x; // +inf
	  if(ix.u==0xbff0000000000000ull){ // -1
#ifdef CORE_MATH_SUPPORT_ERRNO
            errno = ERANGE; // pole error
#endif
            return -1./0.0;
          }
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
	  return 0.0/0.0; // <-1
	}
      }
    }
    i64 j = t.u - 0x3fe6a00000000000ll, j1 = (j>>(52-6))&0x3f, je = (j>>52),
      eoff = (u64)je<<52;
    b64u64_u rs = {.f = rf[j1]};
    if(__builtin_expect(je<1022, 1)){
      rs.u -= eoff;
    } else {
      rs.u -= (i64)1021<<52;
      static const double sc[] = {0x1p-1, 0x1p-2, 0x1p-3};
      rs.f *= sc[je-1022];
    }
    double dh = rs.f*t.f, dl = __builtin_fma(rs.f,t.f,-dh) + rs.f*dt.f;
    double xl, xh = fasttwosum(dh-1.0, dl, &xl), x2 = xh*xh;
    xl += x2*((c[0] + xh*c[1]) + x2*((c[2] + xh*c[3]) + x2*(c[4] + xh*c[5])));
    double L1 = 0x1.62e42fefa4p-1*je, L0 = -0x1.8432a1b0e2634p-43*je;
    ln1 = lf[j1][1] + L1;
    ln0 = lf[j1][0] + L0;
    ln1 = fastsum(ln1, ln0, xh, xl, &ln0);
    eps = 0x1.ap-65;
  }
  double lb = ln1 + (ln0 - eps), ub = ln1 + (ln0 + eps);
  if(__builtin_expect(lb != ub, 0)) return as_log1p_refine(x, lb);
  return lb;
}

static double __attribute__((noinline)) as_log1p_refine(double x, double a){
  static const double cz[][2] = {
    {0x1.5555555555555p-2, 0x1.5555555555556p-56}, {-0x1p-2, 0x1.25558eff3c1efp-86},
    {0x1.999999999999ap-3, -0x1.999999a91d6cap-57}, {-0x1.5555555555555p-3, -0x1.588aab185593ap-57},
    {0x1.2492492492492p-3, 0x1.28c490abc528fp-57}
  };
  static const double czl[] = {
    -0x1.fffffffffc555p-4, 0x1.c71c71c7185aap-4, -0x1.9999d44449a31p-4, 0x1.745d51f1817c7p-4
  };
  static const double cy[][2] = {
    {1,0}, {-0.5, 0},
    {0x1.5555555555555p-2, 0x1.5555555555555p-56}, {-0x1p-2, -0x1.80007ed9858b7p-107},
    {0x1.999999999999ap-3, -0x1.9999999999991p-57}
  };
  static const double cl[4] = {
    -0x1.5555555555555p-3, 0x1.2492492492492p-3, -0x1.0000000073334p-3, 0x1.c71c71c802f68p-4
  };
  b64u64_u ix = {.f = x};
  double ln22, ln21, ln20;
  u64 ax = ix.u<<1;
  if(ax<0x7ea0000000000000ull){
    if(ax<0x7940000000000000ull){
      if(!ax) return x;
      return __builtin_fma(__builtin_fabs(x), -0x1p-54, x);
    }
    double x2h = x*x, x2l = __builtin_fma(x,x,-x2h);
    double x3l, x3h = mulddd(x,x2h, x2l, &x3l);
    double sl = x*((czl[0] + x*czl[1]) + x2h*(czl[2] + x*czl[3]));
    double sh = polyddd(x, 5,cz, &sl);
    sh = muldd(sh,sl,x3h,x3l, &sl);
    x2h *= -0.5;
    x2l *= -0.5;
    ln22 = x;
    ln21 = fastsum(x2h,x2l, sh,sl, &ln20);
  } else {
    i64 j = roundeven_finite(a*0x1.71547652b82fep+16);
    i64 i = j + 34952;
    int j1 = (i>>12)&0xf, j2 = (i>>8)&0xf, j3 = (i>>4)&0xf, j4 = i&0xf, je = i>>16;
    double L[3];
    L[0] = (ln[0][j1][0] + ln[1][j2][0]) + (ln[2][j3][0] + ln[3][j4][0]);
    L[1] = (ln[0][j1][1] + ln[1][j2][1]) + (ln[2][j3][1] + ln[3][j4][1]);
    L[2] = (ln[0][j1][2] + ln[1][j2][2]) + (ln[2][j3][2] + ln[3][j4][2]);

    b64u64_u t, dt;
    if((i64)ix.u<0x4690000000000000ll && ix.u<0xbfe0000000000000ull ){
      t.f = twosum(1.0, x, &dt.f);
      if(__builtin_expect(!(dt.u<<1), 0)) dt.u = 0;
    } else {
      if(__builtin_expect((i64)ix.u>=0x4690000000000000ll, 0))
	t.f = x;
      else
	t.f = 1 + x;
      dt.u = 0;
    }
    t.u -= (u64)je<<52;

    double t12 = rt[0][j1]*rt[1][j2], t34 = rt[2][j3]*rt[3][j4];
    double th = t12*t34, tl = __builtin_fma(t12,t34,-th);
    double dh = th*t.f, dl = __builtin_fma(th,t.f,-dh);
    double sh = tl*t.f, sl = __builtin_fma(tl,t.f,-sh);
    double xl, xh = fasttwosum(dh-1, dl, &xl);
    xh = fastsum(xh, xl, sh, sl, &xl);
    if(dt.u){
      dt.u -= (u64)je<<52;
      double ddh = th*dt.f, ddl = __builtin_fma(th,dt.f,-ddh) + tl*dt.f;
      xh = fastsum(xh, xl, ddh, ddl, &xl);
    }
    sl = xh*((cl[0] + xh*cl[1]) + (xh*xh)*(cl[2] + xh*cl[3]));
    sh = polydd(xh,xl, 5,cy, &sl);
    sh = muldd(xh,xl, sh,sl, &sl);
    if(je){
      ln22 = 0x1.62e42fefa4p-1*je; ln21 = -0x1.8432a1b0e28p-43*je; ln20 = 0x1.cc01f97b57a08p-87*je;
      ln22 += L[2];
      ln21 = fastsum(ln21, ln20, L[1], L[0], &ln20);
    } else {
      ln22 = L[2];
      ln21 = L[1];
      ln20 = L[0];
    }
    ln21 = sum(ln21, ln20, sh, sl, &ln20);
  }
  ln22 = fasttwosum(ln22,ln21, &ln21);
  ln21 = fasttwosum(ln21,ln20, &ln20);

  b64u64_u t = {.f = ln21};
  if(__builtin_expect(!(t.u&(~0ul>>12)), 0)){
    b64u64_u w = {.f = ln20};
    if((w.u^t.u)>>63)
      t.u--;
    else
      t.u++;
    ln21 = t.f;
  }
  return ln22 + ln21;
}
