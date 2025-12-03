/* Correctly-rounded binary64 arcsine function.

Copyright (c) 2022-2025 Alexei Sibidanov.

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
#include <fenv.h> // for FE_TONEAREST, FE_DOWNWARD, FE_UPWARD, feraiseexcept...
#include <stdint.h>

#ifdef __x86_64__
#include <x86intrin.h>
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
// fegetexceptflag accesses the FPSR register, which seems to be much slower
// than accessing FPCR, so it should be avoided if possible.
// Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
#if (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
#if defined(_MSC_VER)
#include <arm64intr.h>
#endif

typedef struct
{
  uint16_t res0;
  uint8_t  res1  : 6;
  uint8_t  bit22 : 1;
  uint8_t  bit23 : 1;
  uint8_t  bit24 : 1;
  uint8_t  res2  : 7;
  uint32_t res3;
} fpcr_bitfield;

inline static unsigned int _mm_getcsr(void)
{
  union
  {
    fpcr_bitfield field;
    uint64_t value;
  } r;

#if defined(_MSC_VER) && !defined(__clang__)
  r.value = _ReadStatusReg(ARM64_FPCR);
#else
  __asm__ __volatile__("mrs %0, FPCR" : "=r"(r.value));
#endif
  static const unsigned int lut[2][2] = {{0x0000, 0x2000}, {0x4000, 0x6000}};
  return lut[r.field.bit22][r.field.bit23];
}
#endif  // (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)

static inline int get_rounding_mode (void)
{
  /* Warning: on __aarch64__ (for example cfarm103), FE_UPWARD=0x400000
     instead of 0x800. */
#if (defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  const unsigned flagp = _mm_getcsr ();
  return (flagp&(3<<13))>>3;
#else
  return fegetround ();
#endif
}

#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
typedef _BitInt(128) i128;
#else
typedef unsigned __int128 u128;
typedef __int128 i128;
#endif

typedef uint64_t u64;
typedef int64_t i64;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
typedef union {u128 a; struct {u64 bl, bh;};} u128_u;
#else
typedef union {u128 a; struct {u64 bh, bl;};} u128_u;
#endif
typedef union {double f; uint64_t u;} b64u64_u;

inline static void shl(u128_u *a, int n){(*a).a <<= n;}
inline static void shr(u128_u *a, int n){(*a).a >>= n;}

inline static u64 muuh(u64 a, u64 b){return (a*(u128)b)>>64;}
inline static i64 mh(i64 a, i64 b){return (i64)((a*(i128)b)>>64);}
inline static i128 imul(i64 a, i64 b){return a*(i128)b;}
inline static u128 mUU(u128 a, u128 b){
  u128_u x = {.a = a}, y = {.a = b};
  u128 o = x.bh*(u128)y.bh;
  o += (u64)(x.bl*(u128)y.bh>>64);
  o += (u64)(x.bh*(u128)y.bl>>64);
  return o;
}

inline static u128 muU(u64 a, u128 b){
  u128_u y = {.a = b};
  u128 o = a*(u128)y.bh;
  o += a*(u128)y.bl>>64;
  return o;
}

inline static u128 sqrU(u128 a){
  u128_u x = {.a = a};
  u128 os = x.bl*(u128)x.bh>>63;
  u128 o = x.bh*(u128)x.bh;
  return o + os;
}

static u128 pasin(u128 x){
  u64 xh = x>>64;
  static const u64 b[] = {0x5ba2e8ba2e8ad9b7, 0x0004713b13b29079, 0x000000393331e196, 0x0000000002f5c315};
  static const u128_u ch[] = {
    {.bl = 0xaaaaaaaaaaaaaaa5, .bh = 0x0002aaaaaaaaaaaa}, // *+1
    {.bl = 0x3333333333333484, .bh = 0x0000001333333333}, // *+1
    {.bl = 0xb6db6db6db6da950, .bh = 0x0000000000b6db6d}, // *+1
    {.bl = 0x1c71c71c71c76217, .bh = 0x00000000000007c7}, // *+1
  };
  u128_u t = ch[3];
  t.bl += muuh(xh, b[0] + muuh(xh, b[1] + muuh(xh, b[2] + muuh(xh, b[3]))));
  return mUU(x, ch[0].a + mUU(x, ch[1].a + mUU(x, ch[2].a + mUU(x, t.a))));
}

// assume |x| >= 2^-26 since the case |x| < 2^-26 is treated in the fast path
static double asin_acc(double x){
  static const u128_u s[] =
    {{.bl = 0x4e29cf6e5fed0679, .bh = 0x648557de8d99f7e},
     {.bl = 0x76a17954b2b7c517, .bh = 0xc8fb2f886ec09f3},
     {.bl = 0xbeeeae8129a786b9, .bh = 0x12d52092ce19f5cc},
     {.bl = 0xd8e72d912977ee71, .bh = 0x1917a6bc29b42be1},
     {.bl = 0x4e08e535cadaf147, .bh = 0x1f564e56a9730e34},
     {.bl = 0xc002a2684781f080, .bh = 0x259020dd1cc27444},
     {.bl = 0x8ffbbceed62c7c43, .bh = 0x2bc42889167f8ca9},
     {.bl = 0x9732300393f33614, .bh = 0x31f17078d34c156c},
     {.bl = 0x43af186b79b2a0f3, .bh = 0x381704d4fc9ec5f9},
     {.bl = 0x90887712e9dc9663, .bh = 0x3e33f2f642be355e},
     {.bl = 0x4c20ab7aa99a2183, .bh = 0x4447498ac7d9dd82},
     {.bl = 0xd725d3b9ed35fbaa, .bh = 0x4a5018bb567c16a2},
     {.bl = 0x97c4afa25181e605, .bh = 0x504d72505d98050c},
     {.bl = 0x408fca9cc277fc1f, .bh = 0x563e69d6ac7f73f8},
     {.bl = 0x4e61f79b3a36f1dc, .bh = 0x5c2214c3e9167abb},
     {.bl = 0x98916152cf7eee1c, .bh = 0x61f78a9abaa58b46},
     {.bl = 0xd409485edd56b172, .bh = 0x67bde50ea3b628b6},
     {.bl = 0x9b165cba0c171818, .bh = 0x6d744027857300ad},
     {.bl = 0x1439670dfe3d68e6, .bh = 0x7319ba64c711785a},
     {.bl = 0x362474f1a105878f, .bh = 0x78ad74e01bd8ec78},
     {.bl = 0x13e03e4889485c69, .bh = 0x7e2e936fe26ae7ed},
     {.bl = 0xbfd79717f2880abf, .bh = 0x839c3cc917ff6cb4},
     {.bl = 0xb892ca8361d8c84c, .bh = 0x88f59aa0da591421},
     {.bl = 0xbba4cfecbff54867, .bh = 0x8e39d9cd73464364},
     {.bl = 0xb17821911e71c16e, .bh = 0x93682a66e896f544},
     {.bl = 0x19cec845ac87a5c6, .bh = 0x987fbfe70b81a708},
     {.bl = 0xe25e39549638ae68, .bh = 0x9d7fd1490285c9e3},
     {.bl = 0x3b5167ee359a234e, .bh = 0xa267992848eeb0c0},
     {.bl = 0x149f6e75993468a3, .bh = 0xa73655df1f2f489e},
     {.bl = 0x1becda8089c1a94c, .bh = 0xabeb49a46764fd15},
     {.bl = 0xe4cad00d5c94bcd2, .bh = 0xb085baa8e966f6da},
     {.bl = 0x597d89b3754abe9f, .bh = 0xb504f333f9de6484},
     {.bl = 0x9de1e3b22b8bf4db, .bh = 0xb96841bf7ffcb21a},
     {.bl = 0xac85320f528d6d5d, .bh = 0xbdaef913557d76f0},
     {.bl = 0xbdf0715cb8b20bd7, .bh = 0xc1d8705ffcbb6e90},
     {.bl = 0x43da25d99267326b, .bh = 0xc5e40358a8ba05a7},
     {.bl = 0x8335241be1693225, .bh = 0xc9d1124c931fda7a},
     {.bl = 0x23af31db7179a4aa, .bh = 0xcd9f023f9c3a059e},
     {.bl = 0x744fea20e8abef92, .bh = 0xd14d3d02313c0eed},
     {.bl = 0xf630e8b6dac83e69, .bh = 0xd4db3148750d1819},
     {.bl = 0x24b9fe00663574a4, .bh = 0xd84852c0a80ffcdb},
     {.bl = 0x2c19b63253da43fc, .bh = 0xdb941a28cb71ec87},
     {.bl = 0x4b19aa71fec3ae6d, .bh = 0xdebe05637ca94cfb},
     {.bl = 0xf4e8a8372f8c5810, .bh = 0xe1c5978c05ed8691},
     {.bl = 0x122785ae67f5515d, .bh = 0xe4aa5909a08fa7b4},
     {.bl = 0x125129529d48a92f, .bh = 0xe76bd7a1e63b9786},
     {.bl = 0x15ad45b4a1b5e823, .bh = 0xea09a68a6e49cd62},
     {.bl = 0x7e610231ac1d6181, .bh = 0xec835e79946a3145},
     {.bl = 0x86f8c20fb664b01b, .bh = 0xeed89db66611e307},
     {.bl = 0x67127db35b287316, .bh = 0xf1090827b43725fd},
     {.bl = 0xa5486bdc455d56a2, .bh = 0xf314476247088f74},
     {.bl = 0x163c5c7f03b718c5, .bh = 0xf4fa0ab6316ed2ec},
     {.bl = 0x2c791f59cc1ffc23, .bh = 0xf6ba073b424b19e8},
     {.bl = 0xc7adc6b4988891bb, .bh = 0xf853f7dc9186b952},
     {.bl = 0x4504ae08d19b2980, .bh = 0xf9c79d63272c4628},
     {.bl = 0x2172a361fd2a722f, .bh = 0xfb14be7fbae58156},
     {.bl = 0x256778ffcb5c1769, .bh = 0xfc3b27d38a5d49ab},
     {.bl = 0xeae6bd951c1dabbe, .bh = 0xfd3aabf84528b50b},
     {.bl = 0x90cd1d959db674ef, .bh = 0xfe1323870cfe9a3d},
     {.bl = 0x41390efdc726e9ef, .bh = 0xfec46d1e89292cf0},
     {.bl = 0xf668633f1ab858a, .bh = 0xff4e6d680c41d0a9},
     {.bl = 0x421e8edaaf59453e, .bh = 0xffb10f1bcb6bef1d},
     {.bl = 0x5657552366961732, .bh = 0xffec4304266865d9}
    };
    
#define X1 0x1.fff8133aa33e4p-1

  const unsigned rm = get_rounding_mode ();
  b64u64_u t = {.f = x};
  int se = (((i64)t.u>>52)&0x7ff)-0x3ff; // -26 <= se
  i64 xsign = t.u&((u64)1<<63);
  double ax = __builtin_fabs(x);
  u128_u fi;
  u64 sm = (t.u<<11)|(u64)1<<63;
  u128_u sm2 = {.a = (u128)sm * sm};
  if(__builtin_expect(ax<0.0131875,0)) { // then -26 <= se <= -7
    int ss = 2*se; // -52 <= ss <= -14
    sm2.a >>= -14 - ss; // the shift is well defined since 0 <= -14 - ss <= 38
    u128 Sm = (u128)(sm>>1)<<64;
    fi.a = Sm + muU(sm>>1, pasin(sm2.a));
    se += 0x3ff;
  } else { // |x| >= 0.0131875, -7 <= se <= -1
    double xx = __builtin_fma(x,-x,1.0);
    b64u64_u ixx = {.f = 1.0/xx}, c = {.f = __builtin_sqrt(xx)};
    ixx.f *= c.f;
    double x2 = x*x;
    static const double ch[] = {0x1.ffb77e06e54aap+5, -0x1.3b200d87cc0fep+5, 0x1.79457faf679e3p+4, -0x1.dc7d5a91dfb7ep+2};
    double c0 = ch[0] + ax*ch[1];
    double c2 = ch[2] + ax*ch[3];
    c0 += x2*c2;
    b64u64_u ic = {.f = c0*c.f + 64.0};
    int indx = ((ic.u&(~0ull>>12)) + ((i64)1<<(52-7)))>>(52-6);
    u64 cm = (c.u<<11)|(u64)1<<63; int ce = ((i64)c.u>>52) - 0x3ff;
    u128_u cm2 = {.a = (u128)cm * cm};
    const int off = 36 - 22 + 14;
    int ss = 128 - 104 + 2*se + off;
    shl(&sm2, ss);
    int sc = 128 - 104 + 2*ce + off;
    shl(&cm2, sc);
    sm2.a += cm2.a;
    i64 h = sm2.bh;
    u64 ixm = (ixx.u&(~0ull>>12))|(i64)1<<52; int ixe = ((i64)ixx.u>>52) - 0x3ff;
    i64 dc = mh(h, ixm);
    u128_u dsm2 = {.a = (u128)imul(dc,cm>>1)};
    dsm2.a <<= 13;
    sm2.a -= dsm2.a;
    u128_u dsm3 = {.a = (u128)imul(dc,dc)};
    sc = 28 - ixe*2;
    if(__builtin_expect(sc>=0, 1))
      shr(&dsm3, sc);
    else
      dsm3.a <<= -sc; // since sc < 0, the shift by -sc is legitimate
    sm2.a += dsm3.a;
    int k = ixe-ce;
    ss = 24 + k;
    u128_u Cm = {.bl = 0, .bh = cm},
      D = {.bl = (u64)dc << ss, .bh = (u64)(dc>>(64-ss))};
    Cm.a -= D.a;
    h = sm2.a>>14;
    dc = mh(h, ixm);
    ss = 26-k;
    if(__builtin_expect(ss>=0,1))
      Cm.a -= (i128)dc>> ss;
    else
      Cm.a -= (u128)dc<<-ss; // since ss < 0, the shift by -ss is legitimate
    fi.bl = 0xd313198a2e037073;
    fi.bh = 0x3243f6a8885a308;
    fi.a *= (u64)(64u - indx);
    if(__builtin_expect(indx==0, 0)){
      shr(&Cm, -ce-7);
      u128 c2a = sqrU(Cm.a);
      u128_u z = {.a = pasin(c2a)};
      Cm.a += mUU(Cm.a, z.a);
      fi.a -= Cm.a>>7;
    } else {
      i128 v = muU(sm>>-se, s[indx-1].a) - (mUU(Cm.a,s[63-indx].a)>>-ce), msk = v>>127, v2 = sqrU(v) - (msk&(v+v)); // since se<0 and ce<0, the shifts by -se and -ce are legitimate
      v2 = (u128)v2 << 14;
      u128 p = pasin(v2);
      v += mUU(p,v)-(msk&p);
      fi.a += v;
    }
    se = 0x3fe;
  }
  int nz = __builtin_clzll(fi.bh);
  u64 rnd;
  if(__builtin_expect(rm==FE_TONEAREST, 1)){
    rnd = (fi.bh>>(10-nz))&1;
  } else if(rm==FE_DOWNWARD){
    rnd =  (u64)xsign>>63;
  } else if(rm==FE_UPWARD){
    rnd =  ((u64)xsign>>63)^1;
  } else {
    rnd = 0;
  }
  volatile double k0 = 1.0, __attribute__((unused)) k = k0 + 0x1p-1022;
  t.u = (fi.bh>>(11-nz))+(((u64)se-nz)<<52|xsign|rnd);
  return t.f;
}

double cr_asin(double x){
  /* For 0 <= i <= 64, s[i]=floor(sin(pi/2*i/64)*2^63), except for i=64
     where s[i]=2^63-1.
     Thus s[i]/2^63 approximates sin(pi/2*i/64)=cos(pi/2*(64-i)/64).
     We use only 63 bits since we use it as a signed value.
     The maximal difference between s[i] and sin(pi/2*i/64)*2^63 is 1
     (for i=64). */
  static const u64 s[] = {
    0, 0x3242abef46ccfbf, 0x647d97c437604f9, 0x96a9049670cfae6, 
    0xc8bd35e14da15f0, 0xfab272b54b9871a, 0x12c8106e8e613a22, 0x15e214448b3fc654, 
    0x18f8b83c69a60ab6, 0x1c0b826a7e4f62fc, 0x1f19f97b215f1aaf, 0x2223a4c563eceec1, 
    0x25280c5dab3e0b51, 0x2826b9282ecc0286, 0x2b1f34eb563fb9fc, 0x2e110a61f48b3d5d, 
    0x30fbc54d5d52c5a3, 0x33def28751db145b, 0x36ba2013c2b98056, 0x398cdd326388bc2d, 
    0x3c56ba700dec763c, 0x3f1749b7f13573f6, 0x41ce1e648bffb65a, 0x447acd506d2c8a10, 
    0x471cece6b9a321b2, 0x49b41533744b7aa2, 0x4c3fdff385c0d384, 0x4ebfe8a48142e4f1, 
    0x5133cc9424775860, 0x539b2aef8f97a44f, 0x55f5a4d233b27e8a, 0x5842dd5474b37b6d, 
    0x5a827999fcef3242, 0x5cb420dfbffe590d, 0x5ed77c89aabebb78, 0x60ec382ffe5db748, 
    0x62f201ac545d02d3, 0x64e88926498fed3d, 0x66cf811fce1d02cf, 0x68a69e81189e0776, 
    0x6a6d98a43a868c0c, 0x6c2429605407fe6d, 0x6dca0d1465b8f643, 0x6f5f02b1be54a67d, 
    0x70e2cbc602f6c348, 0x72552c84d047d3da, 0x73b5ebd0f31dcbc3, 0x7504d3453724e6b1, 
    0x7641af3cca3518a2, 0x776c4edb3308f183, 0x78848413da1b92fe, 0x798a23b1238447ba, 
    0x7a7d055b18b76976, 0x7b5d039da1258cf4, 0x7c29fbee48c35ca9, 0x7ce3ceb193962314, 
    0x7d8a5f3fdd72c0ab, 0x7e1d93e9c52ea4d5, 0x7e9d55fc22945a85, 0x7f0991c3867f4d1e, 
    0x7f62368f44949678, 0x7fa736b40620e854, 0x7fd8878de5b5f78e, 0x7ff62182133432ec, ~0ull>>1 };
  /* For 0 <= i <= 64, sh[i] = round(sin(i*pi/2/64)*2^69) mod 2^64,
     with maximal error < 0.496 (for i=17). */
  static const u64 sh[] = {
    0, 0xc90aafbd1b33efca, 0x91f65f10dd813e6f, 0x5aa41259c33eb998, 
    0x22f4d78536857c3b, 0xeac9cad52e61c68a, 0xb2041ba3984e8898, 0x78851122cff19532, 
    0x3e2e0f1a6982ad93, 0x2e09a9f93d8bf28, 0xc67e5ec857c6abd2, 0x88e93158fb3bb04a, 
    0x4a03176acf82d45b, 0x9ae4a0bb300a193, 0xc7cd3ad58fee7f08, 0x8442987d22cf576a, 
    0x3ef1535754b168d3, 0xf7bca1d476c516db, 0xae8804f0ae6015b3, 0x63374c98e22f0b43, 
    0x15ae9c037b1d8f07, 0xc5d26dfc4d5cfda2, 0x73879922ffed9698, 0x1eb3541b4b228437, 
    0xc73b39ae68c86c97, 0x6d054cdd12dea896, 0xff7fce17034e103, 0xaffa292050b93c7c, 
    0x4cf325091dd61807, 0xe6cabbe3e5e913c3, 0x7d69348cec9fa2a3, 0x10b7551d2cdedb5d, 
    0xa09e667f3bcc908b, 0x2d0837efff964354, 0xb5df226aafaede16, 0x3b0e0bff976dd218, 
    0xbc806b151740b4e8, 0x3a22499263fb4f50, 0xb3e047f38740b3c4, 0x29a7a0462781ddaf, 
    0x9b66290ea1a3033f, 0x90a581501ff9b65, 0x728345196e3d90e6, 0xd7c0ac6f95299f69, 
    0x38b2f180bdb0d23f, 0x954b213411f4f682, 0xed7af43cc772f0c2, 0x4134d14dc939ac43, 
    0x906bcf328d4628b0, 0xdb13b6ccc23c60f1, 0x212104f686e4bfad, 0x6288ec48e111ee95, 
    0x9f4156c62dda5d83, 0xd740e76849633d06, 0xa7efb9230d72a59, 0x38f3ac64e588c509, 
    0x6297cff75cb02ac4, 0x8764fa714ba93565, 0xa7557f08a516a17d, 0xc26470e19fd347b2, 
    0xd88da3d125259e08, 0xe9cdad01883a1522, 0xf621e3796d7de3a8, 0xfd886084cd0cbb2b, 0};
  /* a[0]...a[3] are approximations of the Taylor coefficients of
     2^68*asin(x/2^4) at x=0 of order 3, ..., 9. */
  static const u64 a[] = {0x002aaaaaaaaaaaaa, 0x0000133333333344, 0x0000000b6db6d69d, 0x0000000007c7aa6f};
  /* b[0]...b[4] are approximations towards zero of the Taylor coefficients of
     2^84*asin(x/2^6) at x=0 of order 3, ..., 11.
     The corresponding polynomial has a maximal absolute error
     less than 2^-82.731 with respect to asin(x)-x over [0,2^-6].
     Since coefficients are rounded towards zero, and the evaluation is also
     rounded towards zero (using integer arithmetic), this guarantees the
     final approximation is a lower bound of asin(x). */
  static const u64 b[] = {0xaaaaaaaaaaaaaaaa, 0x0004cccccccccccc, 0x0000002db6db6db6, 0x0000000001f1c71c, 0x00000000000016e8};
  /* pi/2*sqrt(1-x^2)*(ch[0]*x + ch[1]*x^2 + ch[2]*x^3 + ch[3]*x^4) is a rough
     approximation of 64*acos(x) for 0 <= x <= 1, with error less than 0.056 */
  static const double ch[] = {0x1.ffb77e06e54aap+5, -0x1.3b200d87cc0fep+5, 0x1.79457faf679e3p+4, -0x1.dc7d5a91dfb7ep+2};
  const unsigned rm = get_rounding_mode ();
  b64u64_u t = {.f = x};
  int e = (((i64)t.u>>52)&0x7ff)-0x3ff;
  /* x = 2^e*y with 1 <= |y| < 2 */
  i64 xsign = t.u&((u64)1<<63);
  /* xsign=0 for x > 0, xsign=1 for x < 0 */
  u64 sm = (t.u<<11)|(u64)1<<63;
  /* sm contains in its high 53 bits: the implicit leading bit, and the
     the 52 explicit bits from the significand, thus |x| = 2^(e+1)*sm/2^64
     where 2^63 <= sm < 2^64 */
  u128_u fi;
  if(__builtin_expect (e>=0,0)){ /* |x| >= 1 */
    u64 m = t.u<<12; /* m contains the 52 explicit bits from the significand */
    if (e==0 && m == 0) /* case x = 1 or -1 */
      /* h=0x1.921fb54442d18p+0 is pi/2 rounded to nearest,
         and 0x1.1a62633145c07p-54 is pi/2-h rounded to nearest */
      return __builtin_copysign (0x1.921fb54442d18p+0, x)
        + __builtin_copysign (0x1.1a62633145c07p-54, x);
    if (e==0x400 && m) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    feraiseexcept (FE_INVALID);
    return __builtin_nan (">1");
  } else if (__builtin_expect(e < -6,0)){ /* |x| < 2^-6 */
    if (__builtin_expect (e < -26,0)) { /* |x| < 2^-26 */
      /* For |x| < 2^-2, we have |asin(x)-x| < 0.25x^3
         thus the difference between asin(x) and x is less than
         0.25|x|^3, and since |x| < 2^53 ulp(x) and |x| < 2^-26:
         |asin(x)-x| < 2^51 x^2 ulp(x) < 1/2 ulp(x), which
         proves that asin(x) rounds either to x (always for
         rounding to nearest), either to nextabove(x), or to nextbelow(x),
         depending on the rounding mode and the sign of x.
         The expression x + 2^-54*x rounds identically, where the constant
         2^-54 can be replaced by any expression c <= 2^-54, such that
         c*x < 1/2 ulp(x). */
      /* We have underflow exactly when 0 < |x| < 2^-1022:
         for RNDU, asin(2^-1022-2^-1074) would round to 2^-1022-2^-1075
         with unbounded exponent range */
#ifdef CORE_MATH_SUPPORT_ERRNO
      if (x != 0 && __builtin_fabs (x) < 0x1p-1022)
        errno = ERANGE; // underflow
#endif
      return __builtin_fma (x, 0x1p-54, x);
    }
    /* now 2^-26 <= |x| < 2^-6 */
    /* We also have |x| = 2^e*sm/2^63, since e <= -7 we have e+1 <= -6,
       thus we write |x| = 2^(e+1)*y with y=sm/2^64 */
    u64 v2 = muuh(sm, sm), v3 = muuh(sm, v2);
    /* v2 = floor(sm^2/2^64), v3 = floor(sm*v2/2^64) */
    /* since -26 <= e <= -7, 0 <= -2*e-14 <= 38 thus the shift is valid */
    v2 >>= -2*e-14;
    /* v2/2^64 approximates 2^(-2e-14)*y^2: err(v2) <= 1 */
    /* v3/2^64 approximates y^3: err(v3) <= 2 */
    u64 d = muuh(v3, b[0] + muuh(v2, b[1] + muuh(v2, b[2] + muuh(v2, b[3] + muuh(v2, b[4])))));
    /* err(muuh(v2, b[4])) <= 1
       let c3=muuh(v2, b[4])
       b[3] + c3 is exact, and does not overflow since c3 < b[4], and
       b[3]+b[4] < 2^64
       err(muuh(v2, b[3] + c3)) <= err(v2) + err(muuh(v2, b[4])) + 1
                                <= 3
       let c2=muuh(v2,b[3]+c3)
       b[2] + c2 is exact, and does not overflow since c2 < b[3]+b[4],
       and b[2]+b[3]+b[4] < 2^64
       err(muuh(v2, b[2] + c2)) <= 1 + 3 + 1 <= 5
       let c1=muuh(v2, b[2] + c2)
       b[1] + c1 is exact, and does not overflow since c1 < b[2]+b[3]+b[4],
       and b[1]+b[2]+b[3]+b[4] < 2^64
       err(muuh(v2, b[1] + c1)) <= 1 + 5 + 1 <= 7
       let c0=muuh(v2, b[1] + c1)
       b[0] + c0 is exact, and does not overflow since c0 < b[1]+...+b[4],
       and b[0]+...+b[4] < 2^64
       err(muuh(v3, b[0] + c0)) <= err(v3) + 7 + 1 <= 10 */
    /* d/2^64 approximates (up to some power of two) 1/6*x^3 + 3/40*x^5 + ...
       + 63/2816*x^11 with maximal absolute error:
       * 2^(84-82.731) < 3 between asin(x)-x and the b[] polynomial
       * 10/2^64 for the total rounding error in d
       Thus the total error is bounded by 3+10=13 (which means we can put
       u.a += 12l<<ss below, since the error is below 13, and the left
       bound is exact, thus adding 12.999 cannot yield any borrow).
     */
    int ss = 63 + 2*e;
    fi.bl = d<<ss;
    fi.bh = (d>>(64-ss)) + (sm>>1);
    /* fi.a/2^127 approximates y + 1/6*y^3 + 3/40*y^5 + ... + 63/2816*y^11 */
    int nz = __builtin_clzll (fi.bh) + (rm==FE_TONEAREST);
    /* the number of leading zeros in fi.bh is usually 1, but it can also
       be 0, for example for x=0x1.fffffffffffffp-7, thus nz is 0, 1 or 2 */
    u128_u u = fi;
    u.a += 12ll<<ss;
    /* Here fi is the 'left' approximation, and u is the 'right' approximation,
       with error bounded by 9 ulp(d). We check the last bit (or the round bit
       for FE_TONEAREST) does not change between fi and u. */
    if( __builtin_expect(((fi.bh^u.bh)>>(11-nz))&1, 0)){
      return asin_acc (x);
    }
    e += 0x3ff;
  } else { /* case |x| >= 2^-6 */
    double xx = __builtin_fma(x,-x,1.0); /* xx = 1-x^2 */
    b64u64_u ixx = {.f = 1.0/xx}, c = {.f = __builtin_sqrt (xx)};
    /* we have xx = (1-x^2)*(1+theta1) with |theta1| < 2^-52
       thus c = sqrt(1-x^2)*sqrt(1+theta1)*(1+theta2) with |theta2| < 2^-52
       which can be written:
       c = sqrt(1-x^2)*(1+theta3)^(3/2) with |theta3| < 2^-52 or:
       c = sqrt(1-x^2)*(1+theta4) with |theta4| < 2^-51.41
       thus the absolute error on c is bounded by:
       |c - sqrt(1-x^2)| < sqrt(1-x^2)*2^51.41 < 2^-51.41.
       Thus the absolute error on c is bounded by 2^-51.41. */
    /* ixx ~ 1/(1-x^2), c ~ sqrt(1-x^2) */
    ixx.f *= c.f;
    /* ixx approximates 1/sqrt(1-x^2). Let t = o(1/xx) the previous
       value of ixx. We have t = 1/xx*(1+theta1) with |theta1| < 2^-52,
       c = sqrt(xx)*(1+theta2) with |theta2| < 2^-52, then
       ixx = o(t*c) = t*c*(1+theta3) with |theta3| < 2^-52, which yields:
       ixx = 1/sqrt(xx)*(1+theta1)*(1+theta2)*(1+theta3)
           = 1/c*(1+theta1)*(1+theta2)^2*(1+theta3)
       thus |ixx-1/c| < 1/c*|(1+theta1)*(1+theta2)^2*(1+theta3)-1|.
       The maximal values are attained when all thetaj are +/-2^-52,
       which yields |ixx-1/c| < 2^-49.9*1/c.
    */
    double ax = __builtin_fabs (x), x2 = x*x;
    double c0 = ch[0] + ax*ch[1];
    double c2 = ch[2] + ax*ch[3];
    c0 += x2*c2;
    /* FIXME: use FMA here: c0 = fma (c0, c.f, 64) */
    c0 *= c.f;
    c0 += 64;
    /* now c0 approximates 64+64*acos(x)/(pi/2), which lies in [64,128] */
    b64u64_u ic = {.f = c0};
    int indx = ((ic.u&(~0ull>>12)) + ((i64)1<<(52-7))) >> (52-6);
    /* indx = round(c0)-64. We have indx < 64 since c0 is decreasing with
       |x|, thus the largest value is obtained for |x| = 2^-6, and for this
       value we get c0 = 0x1.fd637111d9943p+6 = 127.347111014276
       with rounding upwards.
       Let y=asin(x), i=64-indx, and y[i]=i*pi/2/64, then we have the rotation
       formula:
       sin(y-y[i]) = sin(y)*cos(y[i]) - cos(y)*sin(y[i])
                   = x*cos(y[i]) - sqrt(1-x^2)*sin(y[i])
       thus:
       y = y[i] + asin(x*cos(y[i]) - sqrt(1-x^2)*sin(y[i]))
       where x*cos(y[i]) - sqrt(1-x^2)*sin(y[i]) is small. */
    u64 cm = (c.u<<11)|(u64)1<<63; int ce = ((i64)c.u>>52) - 0x3ff;
    /* cm contains in its high bits the 53 significant bits from c,
       which approximates sqrt(1-x^2), including the implicit bit,
       ce is the corresponding exponent, such that c = 2^ce*cm/2^63.
       We now refine the approximation c of sqrt(1-x^2) using one step
       of Newton's iteration: c += 1/2*e/sqrt(1-x^2) where e = (1-x^2) - c^2.
       It can be proven (by using the same kind of analysis than in Modern
       Computer Arithmetic, Lemma 3.7) that if c is an approximation of
       sqrt(a), and c' = c + 1/2*(a-c^2)/c, then
       |c'-sqrt(a)| = (sqrt(a)-c)^2/(2c).
       Here a=1-x^2, and since |c - sqrt(1-x^2)| < 2^-51.41, we get:
       |c'-sqrt(a)| < 2^-103.82/c. */
    u128_u sm2 = {.a = (u128)sm * sm}, cm2 = {.a = (u128)cm * cm};
    /* x^2 = 2^(2*e)*sm2/2^126 and c^2 = 2^(2*ce)*cm2/2^126 */
    const int off = 36 - 22 + 14;   /* off = 28 */
    int ss = 128 - 104 + 2*e + off; /* ss = 52 + 2*e */
    /* for e=-6, ss=40; for x=0x1.fffffffffffffp-1, ss=50 */
    shl(&sm2, ss);
    /* now frac(2^50*x^2) = sm2/2^128 */
    int sc = 128 - 104 + 2*ce + off;
    if(__builtin_expect(sc>=0, 1))
      shl(&cm2, sc);
    else
      cm2.a >>= -sc; // since sc < 0, the shift by -sc is legitimate
    /* now frac(2^50*c^2) = cm2/2^128 */
    sm2.a += cm2.a; /* now frac(2^50*(x^2+c^2)) = sm2/2^128 */
    /* since |c-sqrt(xx)| < 2^-51.41, we have:
       |c^2-xx| < 2^-51.41*|c+sqrt(xx)| < 2^-50.41 since c,xx < 1.
       This proves that |2^50*e| < 2^-0.41 with e = (1-x^2) - c^2.
       Thus frac(2^50*(x^2+c^2)) is enough to uniquely identify the
       value of 2^50*(x^2+c^2). */
    i64 h = sm2.bh;
    /* h/2^64 approximates 2^50*(x^2+c^2) mod 1, with error bounded by
       1/2^64 for the truncated part sm2.bl/2^128. */
    u64 ixm = (ixx.u&(~0ull>>12))|(i64)1<<52; int ixe = ((i64)ixx.u>>52) - 0x3ff;
    /* ixx = ixm*2^(ixe-52) */
    /* x*cos(y[i]) - sqrt(1-x^2)*sin(y[i]) is computed as
       (x-sin(y[i]))*cos(y[i]) - (sqrt(1-x^2)-cos(y[i]))*sin(y[i]) */
    i64 Smh;
    ss = 6 + e; /* ss >= 0 */
    Smh = (sm<<ss) - sh[64-indx];
    /* since |x| = 2^(e+1)*sm/2^64, sm*2^ss = |x|*2^69 */
    /* now Smh approximates 2^69*(|x|-sin(y[i])) mod 2^64,
       with maximal error < 0.5 */
    i64 Cmh;
    sc = 6 + ce;
    /* Here ce might be less than -6, and thus sc negative, for example when
       |x| is very near 1, since sqrt(1-x^2) ~ c^2 = 2^(2*ce)*cm2/2^126.
       The worst case for |x|=0x1.fffffffffffffp-1 is ce=-26. */
    if(__builtin_expect(sc>=0,1))
      Cmh = cm<<sc;
    else
      Cmh = cm>>-sc; // since sc < 0, the shift by -sc is legitimate
    Cmh -= sh[indx];
    /* We now need to add
       1/2*(1-x^2-c^2)/c to c. Instead we subtract 1/2*h/2^114*ixm*2^(ixe-52),
       with error bounded by:
       (a) 2^-103.82/c for the error in Newton's method
       (b) 1/2/2^114/c for the error on h (neglecting lower order terms)
       (c) 1/2/2^50*2^-49.9*1/c for the error between ixx and 1/c
       Altogether we have an error bounded by 2^-100.72*1/c.
       Since c >= 2^-26 this yields 2^-74.72.
    */
    Cmh -= mh(h, ixm)>>(34-ixe);
    /* now Cmh approximates 2^69*(sqrt(1-x^2)-cos(y[i]))
       with maximal error 2^69*2^-74.72+0.5 < 0.52 */
    i64 v = mh(Smh, s[indx]) - mh(Cmh, s[64-indx]), v2 = mh(v, v), v3 = mh(v2, v);
    /* v approximates 2^68*[(|x|-sin(y[i]))*cos(y[i])
                            -(sqrt(1-x^2)-cos(y[i]))*sin(y[i])] with error
       bounded by:
       1 (truncation error in mh(Smh, s[indx]))
       +1 (truncation error in mh(Cmh, s[64-indx]))
       +0.5*0.5=0.25 (error on Smh multiplied by s[indx]/2^64)
       +0.52*0.5=0.26 (error on Cmh multiplied by s[64-indx])
       which yields 2.51 neglecting second order terms. */
    /* the error on v2 is thus bounded by 5.02, and that on v3 by 7.53, still
       neglecting second order terms */
    v += mh(v3, a[0] + muuh(v2, a[1] + muuh(v2, a[2] + muuh(v2, a[3]))));
    /* err(muuh(v2, a[3]) <= 1
       let c2=muuh(v2, a[3])
       a[2] + c2 is exact, and does not overflow since c2 < a[3], and
       a[2]+a[3] < 2^64
       err(muuh(v2, a[2] + c2)) <= err(v2) + err(muuh(v2, a[3])) + 1
                                <= 5.02 + 1 + 1 = 7.02
       let c1=muuh(v2, a[2] + c2)
       a[1] + c1 is exact, and does not overflow since c1 < a[2]+a[3],
       and a[2]+a[3] < 2^64
       err(muuh(v2, a[1] + c1)) <= err(v2) + err(muuh(v2, a[2] + c2)) + 1
                                <= 5.02 + 7.02 + 1 = 13.04
       let c0=muuh(v2, a[1] + c1)
       a[0] + c0 is exact, and does not overflow since c0 < a[1]+a[2]+a[3],
       and a[1]+a[2]+a[3] < 2^64
       err(mh(v3, a[0] + c0) <= err(v3) + err(c0) + 1 <= 7.53+13.04+1 = 21.57
       The total error on v is thus bounded by 2.51 (order 1) + 21.57 (orders
       3 and more), thus by 24.08.
     */

    fi.bl = 0xd313198a2e037073;
    fi.bh = 0x3243f6a8885a308;
    /* fi.a/2^127 approximates pi/2/64 */
    fi.a *= (u64)(64u - indx); /* multiply pi/2/64 by i=64-indx */
    /* we add v after normalization */
    u64 Vh = v>>5, Vl = (u64)v<<59;
    /* the maximal error 24.08 on v translates into an error of 24.08*2^59
       on Vl */
    i128 V = (u128)Vh<<64|Vl;
    fi.a += V;
    /* now fi/2^127 approximates asin(|x|) */

    int nz = __builtin_clzll(fi.bh) + (rm==FE_TONEAREST);    
    u128_u u = fi, d = fi;
    /* The error is bounded by 24.08*2^59 here, thus by 386*2^55.
       For reference, the original (non proven) error bounds are:
       u.a += 50l<<55 and d.a -= 27l<<55. */
    u.a += (u64)386<<55;
    d.a -= (u64)386<<55;
    if( __builtin_expect(((d.bh^u.bh)>>(11-nz))&1, 0)){
      return asin_acc(x);
    }
    e = 0x3fel;
  }

  int nz = __builtin_clzll(fi.bh);
  u64 rnd;
  if(__builtin_expect(rm==FE_TONEAREST, 1)){
    rnd = (fi.bh>>(10-nz))&1;
  } else if(rm==FE_DOWNWARD){
    rnd =  (u64)xsign>>63;
  } else if(rm==FE_UPWARD){
    rnd =  ((u64)xsign>>63)^1;
  } else {
    rnd = 0;
  }
  volatile double k0 = 1.0, __attribute__((unused)) k = k0 + 0x1p-1022;
  t.u = ((fi.bh>>(11-nz))+((u64)(e-nz)<<52|rnd))|xsign;
  return t.f;
}
