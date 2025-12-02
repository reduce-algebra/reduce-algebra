/* Correctly-rounded tangent function for binary64 half-revolution arguments

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
#include <math.h> // needed to provide tanpi() since glibc does not have it

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {double f; uint64_t u;} b64u64_u;

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

static inline double fastsumddd(double xh, double xl, double ch, double *l){
  double tl, th = fasttwosum(xh,ch,&tl);
  *l = xl + tl;
  return th;
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

static __attribute__((noinline)) double as_tanpi_database(double x, double f){
  static const double db[][3] = {
    {0x1.b44453e2404e7p-55, 0x1.56a4aa740a5a7p-53, 0x1p-107},
    {0x1.45435c15060dcp-54, 0x1.feec101084f24p-53,-0x1p-107},
    {0x1.ac84c88f979a2p-54, 0x1.508ecb38f52f9p-52, 0x1p-106},
    {0x1.b44453e2404e7p-54, 0x1.56a4aa740a5a7p-52, 0x1p-106},
    {0x1.5f095755008fp-52, 0x1.13b412ea2182dp-50, 0x1p-104},
    {0x1.736d8818a1ef3p-48, 0x1.23b8007cd2448p-46,-0x1p-100},
    {0x1.c7c00d31634a6p-48, 0x1.65f203d6bb18ep-46, 0x1p-100},
    {0x1.df6d9f7748faep-45, 0x1.788ac313fc061p-43, 0x1p-97},
    {0x1.292b56d105932p-44, 0x1.d2cadcfe9f85fp-43,-0x1p-97},
    {0x1.45a65501d94d3p-44, 0x1.ff878736a1bcdp-43, 0x1p-97},
    {0x1.e4a84b3095d13p-43, 0x1.7ca626cfcf41p-41,-0x1p-95},
    {0x1.9eb0b7b0519dap-42, 0x1.45b26ebd51c87p-40, 0x1p-94},
    {0x1.1d0798b3403ebp-41, 0x1.bfb93b8757f7cp-40,-0x1p-94},
    {0x1.05d3aa746e163p-38, 0x1.9b46cfb0f10cap-37, 0x1p-91},
    {0x1.d3f710390db87p-36, 0x1.6f89f6df8258dp-34, 0x1p-88},
    {0x1.9e2371e233d1bp-34, 0x1.45437a2ebe657p-32, 0x1p-86},
    {0x1.386de1f01225ap-32, 0x1.eac33f52580c1p-31, 0x1p-85},
    {0x1.520cc578bf7ccp-30, 0x1.0980f68058c7fp-28,-0x1p-82},
    {0x1.a5bdf2b61615bp-23, 0x1.4b3c41e10a1d4p-21, 0x1p-75},
    {0x1.ed835e8ecc245p-23, 0x1.839ab56b14ffdp-21, 0x1p-75},
    {0x1.5b79e364c2d17p-22, 0x1.10e838704c63dp-20, 0x1p-74},
    {0x1.a96d0004e5b8bp-21, 0x1.4e20edbb1c21bp-19, 0x1p-73},
    {0x1.7b544ccbafe6ap-18, 0x1.29ecae32f9ca3p-16, 0x1p-70},
    {0x1.a2f422a07a3d4p-16, 0x1.490ba1569549fp-14, 0x1p-68},
    {0x1.ee10ecdb9b092p-15, 0x1.8409e333ea2e8p-13,-0x1p-67},
    {0x1.ee3f52b4af0dcp-15, 0x1.842e540b07ac1p-13, 0x1p-67},
    {0x1.1c2dc0a9340efp-13, 0x1.be630d1090fe6p-12, 0x1p-66},
    {0x1.75fdc341dc7a1p-13, 0x1.25bb6997b4387p-11,-0x1p-65},
    {0x1.a572fa6b3d117p-12, 0x1.4b016bd111ed5p-10, -0x1p-64},
    {0x1.a537a6de092a1p-11, 0x1.4ad2f60d5240bp-9,  0x1p-63},
    {0x1.db74ba716abb6p-11, 0x1.756c5a7eec959p-9,  0x1p-63},
    {0x1.5d89dc03193cdp-10, 0x1.12874c9307181p-8, -0x1p-62},
    {0x1.54ae0fa9f24b9p-7, 0x1.0baa21da88501p-5, -0x1p-59},
    {0x1.8582f89424fcep-7, 0x1.321061924ca03p-5,  0x1p-59},
    {0x1.14fc0e0c2dacep-6, 0x1.b37ef5831a537p-5,  0x1p-59},
    {0x1.309ce21202ccap-5, 0x1.e0ac5527e7f0dp-4,  0x1p-58},
    {0x1.bb6715a0b1f81p-5, 0x1.5fa4b5e7ce93fp-3,  0x1p-57},
    {0x1.1e38ee7c71b98p-4, 0x1.c8f62be40c3a1p-3, -0x1p-57},
    {0x1.983c8c74ade5dp-4, 0x1.4b88c3e5b04d0p-2,  0x1p-56},
    {0x1.a334561b8192cp-4, 0x1.5513de069862bp-2,  0x1p-56},
    {0x1.a33741abea942p-4, 0x1.55166a4d7d836p-2,  0x1p-56},
    {0x1.c176d0b4666d3p-4, 0x1.6fb0d2df2ae41p-2,  0x1p-56},
    {0x1.ca50e673ede6bp-3, 0x1.b1ed1cc270a2dp-1,  0x1p-55},
    {0x1.df3c63292f1f3p-3, 0x1.cef531bfb44bfp-1, -0x1p-55},
    {0x1.f551afda4c896p-3, 0x1.ef7dd0e5c6350p-1,  0x1p-55},
    {0x1.8b9be647e02a9p-2, 0x1.5717df9abccd3p+1,  0x1p-53},
    {0x1.b648e5b0804dap-2, 0x1.16265f83e8121p+2, -0x1p-52},
    {0x1.dd9d1ecffc9a0p-2, 0x1.2e342ca2440eep+3,  0x1p-51},
    {0x1.ee846d3680301p-2, 0x1.2a04fa64d35ffp+4,  0x1p-50},
  };
  b64u64_u ix = {.f = x};
  uint64_t aix = ix.u&(~(uint64_t)0>>1);
  uint64_t p = 0;
  double ax = __builtin_fabs(x);
  int32_t e = (aix>>52)-1022;
  if(e>=0){ // take into account periodic structure of tan
    b64u64_u t = {.u = aix&~(~(uint64_t)0>>(12+e))};
    ax -= t.f;
    p = ((aix|(uint64_t)1<<52)>>(52-e))&1;
    if(p) ax = 0.5 - ax;
  }
  double sgn = 1;
  if(p^(ix.u>>63)) sgn = -1; // select proper sign
  if(e<-54) { // arguments near zero have worst cases scaled by 2^n
    b64u64_u a = {.f = ((int64_t)1023 - (54 + e))<<52},
            ia = {.f = ((int64_t)1023 + (54 + e))<<52};
    ax *= a.f;
    sgn *= ia.f;
  }
  int a = 0, b = sizeof(db)/sizeof(db[0]) - 1, m = (a + b)/2;
  while (a <= b) { // binary search
    if (db[m][0] < ax)
      a = m + 1;
    else if (db[m][0] == ax) {
      f = sgn*db[m][1] + sgn*db[m][2];
      break;
    } else
      b = m - 1;
    m = (a + b)/2;
  }
  return f;
}

double cr_tanpi(double x){
  static const double T[][2] =
    {{0x0p+0, 0x0p+0},{0x1.ada13ceebab9dp-64, 0x1.927278a3b1162p-5},
     {0x1.87d054f689d7ap-58, 0x1.936bb8c5b2da2p-4},{0x1.2cfb5a746f62cp-58, 0x1.2fcac73a6064p-3},
     {0x1.ef5d367441946p-61, 0x1.975f5e0553158p-3},{0x1.5a6d6c3c8b6a7p-57, 0x1.007fa758626aep-2},
     {-0x1.d704d1bfdb6e8p-57, 0x1.36a08355c63dcp-2},{0x1.78e945dc3913cp-57, 0x1.6e649f7d78649p-2},
     {0x1.08b2fb1366ea9p-56, 0x1.a827999fcef32p-2},{0x1.41522f15e53c5p-56, 0x1.e450e0d273e7ap-2},
     {-0x1.e564bcd1e635dp-55, 0x1.11ab7190834ecp-1},{-0x1.10b4421e6a4f8p-55, 0x1.32e1889047ffdp-1},
     {0x1.7a8c52172b675p-55, 0x1.561b82ab7f99p-1},{-0x1.aa7538e44e996p-55, 0x1.7bb99ed2990cfp-1},
     {-0x1.a6db80fe796fep-56, 0x1.a43002ae4285p-1},{0x1.8dcad85e60fbep-56, 0x1.d00cbc7384d2ep-1},
     {0x0p+0, 0x1p+0},{0x1.946cc0b66979fp-54, 0x1.1a73d55278c4bp+0},
     {-0x1.87e5ad9735569p-56, 0x1.37efd8d87607ep+0},{0x1.6a085e3bc3af6p-55, 0x1.592d11142fa55p+0},
     {0x1.419fa6954928fp-54, 0x1.7f218e25a7461p+0},{-0x1.b6fb77846d763p-56, 0x1.ab1c35d8a74eap+0},
     {0x1.0fb3e75c7098ep-55, 0x1.def13b73c1406p+0},{0x1.7ce6cb463c972p-54, 0x1.0ea21d716fbf7p+1},
     {0x1.21165f626cdd5p-53, 0x1.3504f333f9de6p+1},{0x1.aca947bfb1dccp-56, 0x1.65bc6cc825147p+1},
     {-0x1.b7a14d0d691bep-54, 0x1.a5f59e90600ddp+1},{-0x1.89fcd637fbf3bp-55, 0x1.ff01305ecd8dcp+1},
     {0x1.10706fed37f0ep-55, 0x1.41bfee2424771p+2},{-0x1.ae397239c5a0dp-53, 0x1.af73f4ca3310fp+2},
     {0x1.351daea79411dp-51, 0x1.44e6c595afdccp+3},{-0x1.b6e6b4de0cd24p-56, 0x1.45affed201b55p+4}};

  static const double c[] = {0x1.4abbce625be51p-207, 0x1.466bc6776a9b1p-345, 0x1.45fff6eb26045p-483, 0x1.4627663861052p-621};
  const double ph = 0x1.921fb54442d18p-69, pl = 0x1.1a62633145c07p-123;
  double th, tl, res;

  b64u64_u ix = {.f = x};
  uint64_t ax = ix.u&(~(uint64_t)0>>1);
  if(__builtin_expect(ax >= ((uint64_t)0x3f3<<52), 1)) { // |x| >= 0x1p-12
    if(__builtin_expect(ax >= ((uint64_t)0x42d<<52), 0)) { // |x| >= 0x1p+46
      if(__builtin_expect(ax >= ((uint64_t)0x7ff<<52), 0)) { // NaN, Inf
	if(__builtin_expect(ax > ((uint64_t)0x7ff<<52), 0)) return x + x; // NaN
#ifdef CORE_MATH_SUPPORT_ERRNO
	errno = EDOM;
#endif
	return 0.0/0.0; // x=Inf
      }
      int32_t e = ax>>52, s = e - 1069;
      if(s>6) return __builtin_copysign(0,x);
      int64_t m = ax, sgn = (int64_t)ix.u>>63;
      uint64_t iq = ((uint64_t)((m^sgn)-sgn)<<s)&127;
      if(!(iq&31)){
	int64_t jq = iq>>5;
	if(jq&1){
#ifdef CORE_MATH_SUPPORT_ERRNO
          errno = ERANGE; // overflow
#endif
	  if(jq&2)
	    return -1.0/0.0;
	  else
	    return  1.0/0.0;
	} else {
	  if((jq^sgn)&2)
	    return -0.0;
	  else
	    return 0.0;
	}
      } else {
	double nl,nh;
	if(iq&32){
	  nl = -T[32-(iq&31)][0]; nh = -T[32-(iq&31)][1];
	} else {
	  nl = T[iq&31][0]; nh = T[iq&31][1];
	}
	return nh+nl;
      }
    }
    // now 0x1p-12 <= |x| < 0x1p+46, we have 1011 <= e <= 1068
    int32_t e = ax>>52, s = 1068 - e, s1 = e - 1011;
    int64_t m = (ax&(~(uint64_t)0>>12))|((uint64_t)1<<52),
      ms = (int64_t)((uint64_t)m<<s1)>>63, sgn = (int64_t)ix.u>>63;
    // m is the significand, 2^52 <= m < 2^53
    // 0 <= s1 <= 57 is a biased exponent, with s1=0 for 2^-12 <= |x| < 2^-11
    // 0 <= s <= 57 is another biased exponent, with s=0 for 2^45 <= |x| < 2^46
    // ms is the bit of weight 1/2 in x
    uint64_t iq = ((m^ms)>>s)&63;
    iq = (iq + 1)>>1;
    ms ^= sgn;
    int64_t sm = (m ^ sgn) - sgn; // sm = sign(x)*m
    int64_t k = (uint64_t)sm<<(e-1005); // 6 <= e-1005 <= 63
    // k contains the bits of m of weight <= 2^-7
    double z = k;
    if(__builtin_expect(((uint64_t)k<<1)==0,0)) { // x mod 2^-8 = 0
      if(__builtin_expect(k==0, 0)){ // x mod 2^-7 = 0
	if(!(iq&31)){
	  int64_t jq = sm>>(s+6);
	  if(jq&1){
#ifdef CORE_MATH_SUPPORT_ERRNO
            errno = ERANGE; // overflow
#endif
	    if(jq&2)
	      return -1.0/0.0;
	    else
	      return  1.0/0.0;
	  } else {
	    if((jq^sgn)&2)
	      return -0.0;
	    else
	      return 0.0;
	  }
	}
        // avoid spurious inexact exception for x=1/4 mod 1/2
        uint64_t kq = ((uint64_t) m<<s1)>>58;
        if (kq == 0x10) // |x| = 1/4 mod 1
          return __builtin_copysign(1,x);
        if (kq == 0x30) // |x| = 3/4 mod 1
          return -__builtin_copysign(1,x);
      }
      z = __builtin_copysign(1,x)*z;
    }
    double z2 = z*z, z4 = z2*z2, z3 = z*z2, f = z3*((c[0] + z2*c[1]) + z4*(c[2] + z2*c[3]));
    double eps = z3*0x1p-256 + __builtin_copysign(0x1p-104, z);
    th = mulddd(ph, pl, z, &tl);
    th = fastsumddd(th, tl, f, &tl);
    if(__builtin_expect(iq==32,0)){
      double ith = -1.0/th;
      tl = (__builtin_fma(ith, th, 1) + tl * ith) * ith;
      th = ith;
    } else {
      double nl = T[iq][0], nh = T[iq][1];
      static const double s2[2] = {-1, 1};
      nh *= s2[ms+1];
      nl *= s2[ms+1];
      double ml, mh = muldd(th,tl,nh,nl, &ml), dm, dn;
      mh = fasttwosub(1.0, mh, &dm);
      ml = dm - ml;
      nh = fasttwosum(nh, th, &dn);
      nl += dn + tl;
      double imh = 1/mh;
      th = nh*imh;
      tl = __builtin_fma(nh, imh,-th) + (nl + nh * (__builtin_fma(-mh, imh, 1) - ml * imh)) * imh;
    }
    eps += eps*(th*th);
    double lb = th + (tl - eps), ub = th + (tl + eps);
    if(lb==ub) return lb;
    z *= 0x1p-63;

    static const double ch[][2] = {
      {0x1.921fb54442d18p-6, 0x1.1a62633145c07p-60}, {0x1.4abbce625be53p-18, -0x1.05511c6842515p-72},
      {0x1.466bc6775aae2p-30, -0x1.6dc0d93fb2ecep-85}, {0x1.45fff9b48e95ep-42, 0x1.b226b250d2cc3p-98},
      {0x1.45f472e3af011p-54, 0x1.90612a0755449p-110},};
    static const double cl[] = {0x1.45f32f25dab7fp-66, 0x1.45f3030c82af4p-78, 0x1.464490600a978p-90};
    z2 = z*z; double dz2 = __builtin_fma(z,z,-z2);
    tl = z2 * (cl[0] + z2 * (cl[1] + z2 * (cl[2])));
    th = polydd(z2, dz2, 5, ch, &tl);
    th = mulddd(th,tl,z,&tl);
    if(__builtin_expect(iq==32,0)){
      double ith = -1.0/th;
      tl = (__builtin_fma(ith, th, 1) + tl * ith) * ith;
      th = ith;
    } else {
      double nl = T[iq][0], nh = T[iq][1];
      static const double s2[2] = {-1, 1};
      nh *= s2[ms+1];
      nl *= s2[ms+1];
      double ml, mh = muldd(th,tl,nh,nl, &ml), dm, dn;
      mh = fasttwosub(1.0, mh, &dm);
      ml = dm - ml;
      nh = fasttwosum(nh, th, &dn);
      nl += dn + tl;
      double imh = 1/mh;
      th = nh*imh;
      tl = __builtin_fma(nh, imh,-th) + (nl + nh * (__builtin_fma(-mh, imh, 1) - ml * imh)) * imh;
    }
    th = fasttwosum(th,tl,&tl);
    res = th;
  } else { // |x| < 0x1p-12
    if(__builtin_expect(ax==0, 0)) return x;
    const double pi0 = 0x1.921fb54442d18p+1, pi1 = 0x1.1a62633145c07p-53;
    if(__builtin_expect(ax<((uint64_t)0x3ca<<52), 0)) { // |x| < 0x1p-53
      if(__builtin_expect(ax<((uint64_t)0x36<<52), 0)) { // |x| < 0x1p-969
	int32_t e = ax>>52;
	b64u64_u sc = {.u = ((int64_t)2045-e)<<52},
                isc = {.u = ((int64_t)1+e)<<52};
	double z = x * sc.f;
	th = mulddd(pi0, pi1, z, &tl);
	res = th * isc.f;
	if(__builtin_fabs(res)<0x1p-1022){
#ifdef CORE_MATH_SUPPORT_ERRNO
          /* For all rounding modes, we have underflow (before or after
             rounding) for |x| <= 0x1.45f306dc9c882p-1024. */
          errno = ERANGE; // underflow
#endif
          // we force underflow since the code below might be exact
          volatile double __attribute__((unused)) dummy = x * x;
	  double o = __builtin_copysign(0x1p-1022, x);
	  double v0b = (o + res)*sc.f, v0h = res*sc.f;
	  tl += th - v0h;
	  v0b += tl;
	  return v0b*isc.f - o;
	}
      } else { // 0x1p-969 <= |x| < 0x1p-53
	th = mulddd(pi0, pi1, x, &tl);
	res = th;
      }
    } else {
      static const double c2[] = {0x1.4abbce625be53p+3, 0x1.466bc6775aa2ap+5, 0x1.46000158496c2p+7};
      double x2 = x*x, x3 = x*x2;
      double f = x3*(c2[0] + x2*(c2[1] + x2*(c2[2])));
      double px1, px0 = mulddd(pi0,pi1,x,&px1);
      th = fastsumddd(px0,px1,f,&tl);
      double eps = x*(x2*0x1.1p-47 + 0x1p-101);
      double lb = th + (tl - eps), ub = th + (tl + eps);
      if(lb == ub) return lb;

      static const double ch[][2] = {
	{0x1.4abbce625be53p+3, -0x1.05511c68476a8p-51}, {0x1.466bc6775aae2p+5, -0x1.6dc0cbddc0e69p-50},
	{0x1.45fff9b48e95ep+7, 0x1.a5047910ae0efp-49}};
      static const double cl[] = {0x1.45f472e3aed7dp+9, 0x1.45f33be0e9598p+11};
      double dx2 = __builtin_fma(x,x,-x2), dx3 = __builtin_fma(x2,x,-x3) + dx2*x, dv;
      tl = x2 * (cl[0] + x2 * cl[1]);
      th = polydd(x2, dx2, 3, ch, &tl);
      th = muldd(x3, dx3, th, tl, &tl);
      th = fasttwosum(px0, th, &dv);
      tl = tl + px1 + dv;
      th = fasttwosum(th, tl, &tl);
      res = th;
    }
  }
  b64u64_u ul = {.f = tl}, uh = {.f = th};
  uint64_t er = ((ul.u + 6) & (~(uint64_t)0>>12)),
           de = ((uh.u-ul.u)>>52)&(uint64_t)0x7ff;
  if(__builtin_expect(er<=12||de>102, 0)) return as_tanpi_database(x, res);
  return res;
}
