/* Correctly rounded hyperbolic tangent function for binary64 values.

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

#include <stdint.h>
#include <errno.h>
#if defined(__x86_64__)
#include <x86intrin.h>
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef uint64_t u64;
typedef union {double f; u64 u;} b64u64_u;

static __attribute__((noinline)) double as_tanh_database(double, double);

static inline double fasttwosum(double x, double y, double *e){
  double s = x + y, z = s - x;
  *e = y - z;
  return s;
}

static inline double fasttwosub(double x, double y, double *e){
  double s = x - y, z = x - s;
  *e = z - y;
  return s;
}

static inline double muldd(double xh, double xl, double ch, double cl, double *l){
  double ahlh = ch*xl, alhh = cl*xh, ahhh = ch*xh, ahhl = __builtin_fma(ch, xh, -ahhh);
  ahhl += alhh + ahlh;
  return fasttwosum (ahhh, ahhl, l);
}

static inline double mulddd(double xh, double xl, double ch, double *l){
  double ahlh = ch*xl, ahhh = ch*xh, ahhl = __builtin_fma(ch, xh, -ahhh);
  ahhl += ahlh;
  ch = ahhh + ahhl;
  *l = (ahhh - ch) + ahhl;
  return ch;
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

static double __attribute__((noinline)) as_exp_accurate(double x, double t, double th, double tl, double *l){
  static const double ch[][2] = {
    {0x1p+0, 0x1.6c16bd194535dp-94}, {0x1p-1, -0x1.8259d904fd34fp-93},
    {0x1.5555555555555p-3, 0x1.53e93e9f26e62p-57}};
  const double l2h = 0x1.62e42ffp-13, l2l = 0x1.718432a1b0e26p-47, l2ll = 0x1.9ff0342542fc3p-102;
  double dx = x - l2h*t, dxl = l2l*t, dxll = l2ll*t + __builtin_fma(l2l,t,-dxl);
  double dxh = dx + dxl; dxl = ((dx - dxh) + dxl) + dxll;
  double fl = dxh*(0x1.5555555555555p-5 + dxh *(0x1.11111113e93e9p-7 + dxh *0x1.6c16c169400a7p-10));
  double fh = polydd(dxh,dxl,3,ch, &fl);
  fh = muldd(dxh,dxl,fh,fl,&fl);
  fh = muldd(th,tl,fh,fl,&fl);
  double zh = th + fh, zl = (th-zh) + fh;
  double uh = zh + tl, ul = ((zh-uh) + tl) + zl;
  double vh = uh + fl, vl = ((uh-vh) + fl) + ul;
  *l = vl;
  return vh;
}

static double __attribute__((noinline)) as_tanh_zero(double x){ // |x|<0.25
  static const double ch[][2] = {
    {-0x1.5555555555555p-2, -0x1.5555555555555p-56}, {0x1.1111111111111p-3, 0x1.1111111110916p-59},
    {-0x1.ba1ba1ba1ba1cp-5, 0x1.7917917a46f2cp-59}, {0x1.664f4882c10fap-6, -0x1.9a52a06f1e599p-63},
    {-0x1.226e355e6c23dp-7, 0x1.c297394c24e38p-61}, {0x1.d6d3d0e157dep-9, -0x1.311087e5b1526p-63},
    {-0x1.7da36452b75e1p-10, -0x1.2868cde54ea0cp-65}, {0x1.355824803667bp-11, 0x1.2cd8fc406c3f7p-66},
    {-0x1.f57d7734c821dp-13, 0x1.da22861b4ca8p-70}, {0x1.967e18ad3facfp-14, -0x1.0831108273a74p-68}
  };
  static const double cl[] = {
    -0x1.497d8e6462927p-15, 0x1.0b1318c243bd7p-16, -0x1.b0f2935e9a12p-18, 0x1.5e9444536e654p-19,
    -0x1.174ff2a31908cp-20, 0x1.749698c8d338dp-22};
  double x2 = x*x , x2l = __builtin_fma(x, x,-x2);
  double y2 = x2 * (cl[0] + x2 * (cl[1] + x2 * (cl[2] + x2 * (cl[3] + x2 * (cl[4] + x2 * (cl[5]))))));
  double y1 = polydd(x2, x2l, 10, ch, &y2);
  y1 = mulddd(y1, y2, x, &y2);
  y1 = muldd(y1, y2, x2, x2l, &y2);
  double y0 = fasttwosum(x, y1, &y1);
  y1 = fasttwosum(y1, y2, &y2);
  b64u64_u t = {.f = y1};
  if(__builtin_expect(!(t.u&(~0ul>>12)), 0)){
    b64u64_u w = {.f = y2};
    if((w.u^t.u)>>63)
      t.u--;
    else
      t.u++;
    y1 = t.f;
    if(__builtin_expect(y2==0.0, 0)) return  as_tanh_database(x, y0 + y1);
  }
  return y0 + y1;
}

static __attribute__((noinline)) double as_tanh_database(double x, double f){
  static const double db[][3] = {
    {0x1.ac343b179fec4p-3, 0x1.a612499c53078p-3,  0x1p-57},
    {0x1.00764a988bf73p-2, 0x1.f676484c0703bp-3, -0x1p-104},
    {0x1.17d1e8a63711fp-2, 0x1.110e96a6c2d96p-2, -0x1p-105},
    {0x1.291c601a05276p-2, 0x1.210b7d0c03743p-2,  0x1p-56},
    {0x1.36f33d51c264dp-2, 0x1.2dbb7b1c91363p-2, -0x1p-106},
    {0x1.43eaea23649c3p-2, 0x1.39877ed028641p-2, -0x1p-55},
    {0x1.d88d7550b2826p-2, 0x1.b9a3637366afdp-2,  0x1p-56},
    {0x1.e611aa58ab608p-2, 0x1.c493dc899e4a6p-2, -0x1p-55},
    {0x1.01efe7ac8c15dp-1, 0x1.dc3fe1b524821p-2, -0x1p-104},
    {0x1.1005ec0bccabbp-1, 0x1.f20b1c8557dedp-2, -0x1p-55},
    {0x1.33dfeb0fa4bfep-1, 0x1.1372f9ee76e99p-1,  0x1p-55},
    {0x1.49f24ac5cac35p-1, 0x1.22c495ff06104p-1, -0x1p-104},
  };
  int a = 0, b = sizeof(db)/sizeof(db[0]) - 1, m = (a + b)/2;
  double ax = __builtin_fabs(x);
  while (a <= b) {
    if (db[m][0] < ax)
      a = m + 1;
    else if (db[m][0] == ax) {
      f = __builtin_copysign(1, x)*db[m][1] + __builtin_copysign(1, x)*db[m][2];
      break;
    } else
      b = m - 1;
    m = (a + b)/2;
  }
  return f;
}

double cr_tanh(double x){
  /*
    The function tanh(x) is approximated by minimax polynomial for
    |x|<0.25.  For other values we use this identity tanh(|x|) = 1 -
    2*exp(-2*|x|)/(1 + exp(-2*|x|)).  For large |x|>3.683 the term
    2*exp(-2*|x|)/(1 + exp(-2*|x|)) becomes small and we can use less
    precise formula for exponent.
  */
  static const double t0[][2] = {
    {0x0p+0, 0x1p+0}, {-0x1.19083535b085ep-56, 0x1.02c9a3e778061p+0},
      {0x1.d73e2a475b466p-55, 0x1.059b0d3158574p+0}, {0x1.186be4bb285p-57, 0x1.0874518759bc8p+0},
      {0x1.8a62e4adc610ap-54, 0x1.0b5586cf9890fp+0}, {0x1.03a1727c57b52p-59, 0x1.0e3ec32d3d1a2p+0},
      {-0x1.6c51039449b3ap-54, 0x1.11301d0125b51p+0}, {-0x1.32fbf9af1369ep-54, 0x1.1429aaea92dep+0},
      {-0x1.19041b9d78a76p-55, 0x1.172b83c7d517bp+0}, {0x1.e5b4c7b4968e4p-55, 0x1.1a35beb6fcb75p+0},
      {0x1.e016e00a2643cp-54, 0x1.1d4873168b9aap+0}, {0x1.dc775814a8494p-55, 0x1.2063b88628cd6p+0},
      {0x1.9b07eb6c70572p-54, 0x1.2387a6e756238p+0}, {0x1.2bd339940e9dap-55, 0x1.26b4565e27cddp+0},
      {0x1.612e8afad1256p-55, 0x1.29e9df51fdee1p+0}, {0x1.0024754db41d4p-54, 0x1.2d285a6e4030bp+0},
      {0x1.6f46ad23182e4p-55, 0x1.306fe0a31b715p+0}, {0x1.32721843659a6p-54, 0x1.33c08b26416ffp+0},
      {-0x1.63aeabf42eae2p-54, 0x1.371a7373aa9cbp+0}, {-0x1.5e436d661f5e2p-56, 0x1.3a7db34e59ff7p+0},
      {0x1.ada0911f09ebcp-55, 0x1.3dea64c123422p+0}, {-0x1.ef3691c309278p-58, 0x1.4160a21f72e2ap+0},
      {0x1.89b7a04ef80dp-59, 0x1.44e086061892dp+0}, {0x1.3c1a3b69062fp-56, 0x1.486a2b5c13cdp+0},
      {0x1.d4397afec42e2p-56, 0x1.4bfdad5362a27p+0}, {-0x1.4b309d25957e4p-54, 0x1.4f9b2769d2ca7p+0},
      {-0x1.07abe1db13cacp-55, 0x1.5342b569d4f82p+0}, {0x1.9bb2c011d93acp-54, 0x1.56f4736b527dap+0},
      {0x1.6324c054647acp-54, 0x1.5ab07dd485429p+0}, {0x1.ba6f93080e65ep-54, 0x1.5e76f15ad2148p+0},
      {-0x1.383c17e40b496p-54, 0x1.6247eb03a5585p+0}, {-0x1.bb60987591c34p-54, 0x1.6623882552225p+0},
      {-0x1.bdd3413b26456p-54, 0x1.6a09e667f3bcdp+0}, {-0x1.bbe3a683c88aap-57, 0x1.6dfb23c651a2fp+0},
      {-0x1.16e4786887a9ap-55, 0x1.71f75e8ec5f74p+0}, {-0x1.0245957316dd4p-54, 0x1.75feb564267c9p+0},
      {-0x1.41577ee04993p-55, 0x1.7a11473eb0187p+0}, {0x1.05d02ba15797ep-56, 0x1.7e2f336cf4e62p+0},
      {-0x1.d4c1dd41532d8p-54, 0x1.82589994cce13p+0}, {-0x1.fc6f89bd4f6bap-54, 0x1.868d99b4492edp+0},
      {0x1.6e9f156864b26p-54, 0x1.8ace5422aa0dbp+0}, {0x1.5cc13a2e3976cp-55, 0x1.8f1ae99157736p+0},
      {-0x1.75fc781b57ebcp-57, 0x1.93737b0cdc5e5p+0}, {-0x1.d185b7c1b85dp-54, 0x1.97d829fde4e5p+0},
      {0x1.c7c46b071f2bep-56, 0x1.9c49182a3f09p+0}, {-0x1.359495d1cd532p-54, 0x1.a0c667b5de565p+0},
      {-0x1.d2f6edb8d41e2p-54, 0x1.a5503b23e255dp+0}, {0x1.0fac90ef7fd32p-54, 0x1.a9e6b5579fdbfp+0},
      {0x1.7a1cd345dcc82p-54, 0x1.ae89f995ad3adp+0}, {-0x1.2805e3084d708p-57, 0x1.b33a2b84f15fbp+0},
      {-0x1.5584f7e54ac3ap-56, 0x1.b7f76f2fb5e47p+0}, {0x1.23dd07a2d9e84p-55, 0x1.bcc1e904bc1d2p+0},
      {0x1.11065895048dep-55, 0x1.c199bdd85529cp+0}, {0x1.2884dff483cacp-54, 0x1.c67f12e57d14bp+0},
      {0x1.503cbd1e949dcp-56, 0x1.cb720dcef9069p+0}, {-0x1.cbc3743797a9cp-54, 0x1.d072d4a07897cp+0},
      {0x1.2ed02d75b3706p-55, 0x1.d5818dcfba487p+0}, {0x1.c2300696db532p-54, 0x1.da9e603db3285p+0},
      {-0x1.1a5cd4f184b5cp-54, 0x1.dfc97337b9b5fp+0}, {0x1.39e8980a9cc9p-55, 0x1.e502ee78b3ff6p+0},
      {-0x1.e9c23179c2894p-54, 0x1.ea4afa2a490dap+0}, {0x1.dc7f486a4b6bp-54, 0x1.efa1bee615a27p+0},
      {0x1.9d3e12dd8a18ap-54, 0x1.f50765b6e454p+0}, {0x1.74853f3a5931ep-55, 0x1.fa7c1819e90d8p+0}
  };
  static const double t1[][2] = {
    {0x0p+0, 0x1p+0}, {0x1.ae8e38c59c72ap-54, 0x1.000b175effdc7p+0},
    {-0x1.7b5d0d58ea8f4p-58, 0x1.00162f3904052p+0}, {0x1.4115cb6b16a8ep-54, 0x1.0021478e11ce6p+0},
    {-0x1.d7c96f201bb2ep-55, 0x1.002c605e2e8cfp+0}, {0x1.84711d4c35eap-54, 0x1.003779a95f959p+0},
    {-0x1.0484245243778p-55, 0x1.0042936faa3d8p+0}, {-0x1.4b237da2025fap-54, 0x1.004dadb113dap+0},
    {-0x1.5e00e62d6b30ep-56, 0x1.0058c86da1c0ap+0}, {0x1.a1d6cedbb948p-54, 0x1.0063e3a559473p+0},
    {-0x1.4acf197a00142p-54, 0x1.006eff583fc3dp+0}, {-0x1.eaf2ea42391a6p-57, 0x1.007a1b865a8cap+0},
    {0x1.da93f90835f76p-56, 0x1.0085382faef83p+0}, {-0x1.6a79084ab093cp-55, 0x1.00905554425d4p+0},
    {0x1.86364f8fbe8f8p-54, 0x1.009b72f41a12bp+0}, {-0x1.82e8e14e3110ep-55, 0x1.00a6910f3b6fdp+0},
    {-0x1.4f6b2a7609f72p-55, 0x1.00b1afa5abcbfp+0}, {-0x1.e1a258ea8f71ap-56, 0x1.00bcceb7707ecp+0},
    {0x1.4362ca5bc26f2p-56, 0x1.00c7ee448ee02p+0}, {0x1.095a56c919d02p-54, 0x1.00d30e4d0c483p+0},
    {-0x1.406ac4e81a646p-57, 0x1.00de2ed0ee0f5p+0}, {0x1.b5a6902767e08p-54, 0x1.00e94fd0398ep+0},
    {-0x1.91b206085932p-54, 0x1.00f4714af41d3p+0}, {0x1.427068ab22306p-55, 0x1.00ff93412315cp+0},
    {0x1.c1d0660524e08p-54, 0x1.010ab5b2cbd11p+0}, {-0x1.e7bdfb3204be8p-54, 0x1.0115d89ff3a8bp+0},
    {0x1.843aa8b9cbbc6p-55, 0x1.0120fc089ff63p+0}, {-0x1.34104ee7edae8p-56, 0x1.012c1fecd613bp+0},
    {-0x1.2b6aeb6176892p-56, 0x1.0137444c9b5b5p+0}, {0x1.a8cd33b8a1bb2p-56, 0x1.01426927f5278p+0},
    {0x1.2edc08e5da99ap-56, 0x1.014d8e7ee8d2fp+0}, {0x1.57ba2dc7e0c72p-55, 0x1.0158b4517bb88p+0},
    {0x1.b61299ab8cdb8p-54, 0x1.0163da9fb3335p+0}, {-0x1.90565902c5f44p-54, 0x1.016f0169949edp+0},
    {0x1.70fc41c5c2d54p-55, 0x1.017a28af25567p+0}, {0x1.4b9a6e145d76cp-54, 0x1.018550706ab62p+0},
    {-0x1.008eff5142bfap-56, 0x1.019078ad6a19fp+0}, {-0x1.77669f033c7dep-54, 0x1.019ba16628de2p+0},
    {-0x1.09bb78eeead0ap-54, 0x1.01a6ca9aac5f3p+0}, {0x1.371231477ece6p-54, 0x1.01b1f44af9f9ep+0},
    {0x1.5e7626621eb5ap-56, 0x1.01bd1e77170b4p+0}, {-0x1.bc72b100828a4p-54, 0x1.01c8491f08f08p+0},
    {-0x1.ce39cbbab8bbep-57, 0x1.01d37442d507p+0}, {0x1.16996709da2e2p-55, 0x1.01de9fe280ac8p+0},
    {-0x1.c11f5239bf536p-55, 0x1.01e9cbfe113efp+0}, {0x1.e1d4eb5edc6b4p-55, 0x1.01f4f8958c1c6p+0},
    {-0x1.afb99946ee3fp-54, 0x1.020025a8f6a35p+0}, {-0x1.8f06d8a148a32p-54, 0x1.020b533856324p+0},
    {-0x1.2bf310fc54eb6p-55, 0x1.02168143b0281p+0}, {-0x1.c95a035eb4176p-54, 0x1.0221afcb09e3ep+0},
    {-0x1.491793e46834cp-54, 0x1.022cdece68c4fp+0}, {-0x1.3e8d0d9c4909p-56, 0x1.02380e4dd22adp+0},
    {-0x1.314aa16278aa4p-54, 0x1.02433e494b755p+0}, {0x1.48daf888e965p-55, 0x1.024e6ec0da046p+0},
    {0x1.56dc8046821f4p-55, 0x1.02599fb483385p+0}, {0x1.45b42356b9d46p-54, 0x1.0264d1244c719p+0},
    {-0x1.082ef51b61d7ep-56, 0x1.027003103b10ep+0}, {0x1.2106ed0920a34p-56, 0x1.027b357854772p+0},
    {-0x1.fd4cf26ea5d0ep-54, 0x1.0286685c9e059p+0}, {-0x1.09f8775e78084p-54, 0x1.02919bbd1d1d8p+0},
    {0x1.64cbba902ca28p-58, 0x1.029ccf99d720ap+0}, {0x1.4383ef231d206p-54, 0x1.02a803f2d170dp+0},
    {0x1.4a47a505b3a46p-54, 0x1.02b338c811703p+0}, {0x1.e47120223468p-54, 0x1.02be6e199c811p+0},
  };
  double ax = __builtin_fabs(x);
  b64u64_u ix = {.f = ax};
  u64 aix = ix.u;
  /* for |x| >= 0x1.30fc1931f09cap+4, tanh(x) rounds to +1 or -1 to nearest,
     this avoid a spurious overflow in the computation of v0 below */
  if (__builtin_expect (aix >=0x40330fc1931f09caull, 0)) {
    if(aix>0x7ff0000000000000ull) return x + x; // nan
    double f = __builtin_copysign(1.0, x);
    if(aix==0x7ff0000000000000ull) return f;
    double df = __builtin_copysign(0x1p-55, x);
    return f - df;
  }
  const double s = -0x1.71547652b82fep+13;
  double v0 = __builtin_fma(ax, s, 0x1.8000004p+25);
  b64u64_u jt = {.f = v0};
#if defined(__x86_64__)
  __m128d v = _mm_set_sd (v0);
  __m128i tt = {~((1<<27)-1l), 0};
  v = _mm_and_pd(v,(__m128d)tt);
  double t = v[0] - 0x1.8p25;
#else
  b64u64_u v = {.f = v0};
  uint64_t tt = ~((1<<27)-1l);
  v.u &= tt;
  double t = v.f - 0x1.8p25;
#endif
  int64_t i1 = (jt.u>>27)&0x3f, i0 = (jt.u>>33)&0x3f, ie = (int64_t)(jt.u<<13)>>52;
  const b64u64_u sp = {.u = (1023 + ie)<<52};
  static const double ch[] = {0x1p+1, 0x1p+1, 0x1.55555557e54ffp+0, 0x1.55555553a12f4p-1};
  double t0h = t0[i0][1], t1h = t1[i1][1], th = t0h*t1h, tl;
  if(aix<0x400d76c8b4395810ull){ // |x| ~< 3.683
    if(__builtin_expect(aix<0x3fd0000000000000ull, 0)){ // |x| < 0x1p-2
      if(__builtin_expect(aix<0x3e10000000000000ull, 0)){ // |x| < 0x1p-30
	if(__builtin_expect(aix<0x3df0000000000000ull, 0)){ // |x| < 0x1p-32
	  if(__builtin_expect(!aix, 0)) return x;
          /* We have underflow when 0 < |x| < 2^-1022 or when |x| = 2^-1022
             and rounding towards zero. */
          double res = __builtin_fma (x, -0x1p-55, x);
#ifdef CORE_MATH_SUPPORT_ERRNO
          if (__builtin_fabs (x) < 0x1p-1022 ||
              __builtin_fabs (res) < 0x1p-1022)
            errno = ERANGE; // underflow
#endif
          return res;
	}
	double x3 = x*x*x;
	return x - x3/3;
      }
      static const double c[] = {
	-0x1.5555555555554p-2, 0x1.1111111110d61p-3, -0x1.ba1ba1b983d8bp-5, 0x1.664f4820e99fp-6,
	-0x1.226e11e4ac7cfp-7, 0x1.d6c4ab70668b6p-9, -0x1.7bbecb57ce996p-10, 0x1.1451443697dd8p-11};
      double x2 = x*x, x3 = x2*x, x4 = x2*x2, x8 = x4*x4;
      double p1 = (c[4] + x2*c[5]) + x4*(c[6] + x2*c[7]);
      double p0 = (c[0] + x2*c[1]) + x4*(c[2] + x2*c[3]);
      p0 += x8*p1;
      p0 *= x3;
      double rl, rh = fasttwosum(x,p0,&rl);
      double e = x3*0x1.ap-52, lb = rh + (rl - e), ub = rh + (rl + e);
      if(lb == ub) return lb;
      return as_tanh_zero(x);
    }

    double t0l = t0[i0][0], t1l = t1[i1][0];
    tl = t0h*t1l + t1h*t0l + __builtin_fma(t0h, t1h,-th);
    th *= sp.f;
    tl *= sp.f;
    const double l2h = -0x1.62e42ffp-14, l2l = -0x1.718432a1b0e26p-48;
    double dx = (l2h*t - ax) - l2l*t, dx2 = dx*dx;
    double p = dx*((ch[0] + dx*ch[1]) + dx2*(ch[2] + dx*ch[3]));
    double rh = th, rl = tl + rh*p;
    rh = fasttwosum(rh, rl, &rl);

    double ph = rh, pl = rl;
    double qh = rh, ql = rl, qd;
    qh = fasttwosum(1, qh, &qd); ql += qd;

    double rqh = 1/qh, rql = (ql*rqh + __builtin_fma(rqh,qh,-1))*-rqh;
    ph = muldd(ph,pl, rqh,rql, &pl);

    double e = rh*0x1p-62;
    rh = fasttwosub(0.5, ph, &rl); rl -= pl;
    rh *= __builtin_copysign(2, x);
    rl *= __builtin_copysign(2, x);
    double lb = rh + (rl - e), ub = rh + (rl + e);
    if(lb == ub) return lb;
  } else {
    static const double l2 = -0x1.62e42fefa39efp-14;
    double dx = __builtin_fma(l2, t, -ax), dx2 = dx*dx;
    double p = dx*((ch[0] + dx*ch[1]) + dx2*(ch[2] + dx*ch[3]));
    double rh = th*sp.f;
    rh += (p + ((2*0x1.3p-55)*ax))*rh;
    double e = rh*0x1.1p-49;
    rh = (2*rh)/(1 + rh);
    double one = __builtin_copysign(1,x);
    rh = __builtin_copysign(rh, x);
    double lb = one - (rh + e), ub = one - (rh - e);
    if(lb == ub) return lb;

    double t0l = t0[i0][0], t1l = t1[i1][0];
    tl = t0h*t1l + t1h*t0l + __builtin_fma(t0h, t1h,-th);
    th *= sp.f;
    tl *= sp.f;
  }
  double rl, rh = as_exp_accurate(-2*ax, t, th, tl, &rl);
  double qd, qh = fasttwosum(1, rh, &qd), ql = rl + qd;
  qh = fasttwosum(qh, ql, &ql);
  double rqh = 1/qh, rql = (ql*rqh + __builtin_fma(rqh,qh,-1))*-rqh;
  double pl, ph = muldd(rh,rl, rqh,rql, &pl);
  rh = fasttwosub(0.5, ph, &rl); rl -= pl;
  rh = fasttwosum(rh, rl, &rl);
  double res = __builtin_copysign(2,x)*rh + __builtin_copysign(2,x)*rl;
  b64u64_u lu = {.f = rl};
  if(__builtin_expect(((lu.u+32)&(~0ul>>12))<65, 0)) return as_tanh_database(x, res);
  return res;
}
