/* Correctly-rounded square root of binary128 value.

Copyright (c) 2025 Alexei Sibidanov <sibid@uvic.ca>

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

#define _GNU_SOURCE /* to define ...f128 functions */

#include <errno.h>
#include <fenv.h> // for feraiseexcept, FE_INVALID, FE_INEXACT
#include <stdint.h>
#include <math.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

//#pragma STDC FENV_ACCESS ON

// This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
// fegetexceptflag accesses the FPSR register, which seems to be much slower
// than accessing FPCR, so it should be avoided if possible.
// Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
#if defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
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

inline static unsigned int _mm_getcsr()
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
#endif  // defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef union {
  u128 a;
  i128 as;
  u64 b[2];
  i64 bs[2];
  __float128 f;
} b128u128_u;

#if (defined(__x86_64__) && (defined(__APPLE__) || defined(_WIN32)))
static inline __float128 local_nanq(__attribute__((unused)) const char *tagp){
  b128u128_u u;
  u.a = ~(u128)0u;
  return u.f;
}
#define __builtin_nanf128(tagp) local_nanq(tagp)
#endif

// get high part of unsigned 64x64 bit multiplication
static inline u64 mhuu(u64 _a, u64 _b){
  return ((u128)_a*_b)>>64;
}

// get high part of signed 64x64 bit multiplication
static inline i64 mhii(i64 x, i64 y){
  return ((i128)x*y)>>64;
}

static inline u128 mhuU(u64 y, u128 x){
  b128u128_u ux; ux.a = x;
  u128 xy0 = ux.b[0]*(u128)y;
  u128 xy1 = ux.b[1]*(u128)y;
  return xy1 + (xy0>>64);
}

// get appoximate high part of unsigned 128x128 bit multiplication
static inline u128 mhUU(u128 _a, u128 _b){
  b128u128_u a, b, a1b0, a0b1, a1b1;
  a.a = _a;
  b.a = _b;
  a1b0.a = (u128)a.b[1]*b.b[0];
  a0b1.a = (u128)a.b[0]*b.b[1];
  a1b1.a = (u128)a.b[1]*b.b[1];
  a1b1.a += a1b0.b[1];
  a1b1.a += a0b1.b[1];
  return a1b1.a;
}

// get high 128 bit part of (unsigned 128)x(signed 128) bit
// multiplication with sign mask
static inline i128 mhUIm(u128 _a, i128 _b, u64 mask){
  b128u128_u sub; sub.a = _a;
  sub.b[0] &= mask;
  sub.b[1] &= mask;
  return mhUU(_a,_b) - sub.a;
}

// get high 128 bit part of (unsigned 128)x(signed 128) bit
// multiplication
static inline i128 mhIU(i128 _b, u128 _a){
  return mhUIm(_a,_b,(u64)(_b>>127));
}

static inline __float128 reinterpret_u128_as_f128(u128 t){
#if defined(__x86_64__) && !defined(__clang__)
  // put u128 into xmm register
  __m128i m = {0, 0};
  m = _mm_insert_epi64 (m, t, 0);
  m = _mm_insert_epi64 (m, t>>64, 1);
  __float128 r;
  asm("": "=x"(r): "0"(m));
  return r;
#else
  b128u128_u u = {.a = t};
  return u.f;
#endif
}

static inline u128 reinterpret_f128_as_u128(__float128 z){
#if defined(__x86_64__) && !defined(__clang__)
  __m128i t;
  asm("" : "=x" (t) :"0" (z));
  u64 h = _mm_extract_epi64(t, 1);
  u64 l = _mm_extract_epi64(t, 0);
  return ((u128)h<<64)|l;
#else
  b128u128_u u = {.f = z};
  return u.a;
#endif
}

// for low precision approxmation use 64x64->64 bit multiplication
static inline u64 rsqrt9(u64 m){
  static const unsigned c[][4] = {
    {0xffffffff, 0xfffff780, 0xbff55815, 0x9bb5b6e7}, {0xfc0bd889, 0xfa1d6e7d, 0xb8a95a89, 0x938bf8f0},
    {0xf82ec882, 0xf473bea9, 0xb1bf4705, 0x8bed0079}, {0xf467f280, 0xeefff2a1, 0xab309d4a, 0x84cdb431},
    {0xf0b6848c, 0xe9bf46f4, 0xa4f76232, 0x7e24037b}, {0xed19b75e, 0xe4af2628, 0x9f0e1340, 0x77e6ca62},
    {0xe990cdad, 0xdfcd2521, 0x996f9b96, 0x720db8df}, {0xe61b138e, 0xdb16ffde, 0x94174a00, 0x6c913cff},
    {0xe2b7dddf, 0xd68a967b, 0x8f00c812, 0x676a6f92}, {0xdf6689b7, 0xd225ea80, 0x8a281226, 0x62930308},
    {0xdc267bea, 0xcde71c63, 0x8589702c, 0x5e05343e}, {0xd8f7208e, 0xc9cc6948, 0x81216f2e, 0x59bbbcf8},
    {0xd5d7ea91, 0xc5d428ee, 0x7cecdb76, 0x55b1c7d6}, {0xd2c8534e, 0xc1fccbc9, 0x78e8bb45, 0x51e2e592},
    {0xcfc7da32, 0xbe44d94a, 0x75124a0a, 0x4e4b0369}, {0xccd6045f, 0xbaaaee41, 0x7166f40f, 0x4ae66284},
    {0xc9f25c5c, 0xb72dbb69, 0x6de45288, 0x47b19045}, {0xc71c71c7, 0xb3cc040f, 0x6a882804, 0x44a95f5f},
    {0xc453d90f, 0xb0849cd4, 0x67505d2a, 0x41cae1a0}, {0xc1982b2e, 0xad566a85, 0x643afdc8, 0x3f13625c},
    {0xbee9056f, 0xaa406113, 0x6146361f, 0x3c806169}, {0xbc46092e, 0xa7418293, 0x5e70506d, 0x3a0f8e8e},
    {0xb9aedba5, 0xa458de58, 0x5bb7b2b1, 0x37bec572}, {0xb72325b7, 0xa1859022, 0x591adc9a, 0x358c09e2},
    {0xb4a293c2, 0x9ec6bf52, 0x569865a7, 0x33758476}, {0xb22cd56d, 0x9c1b9e36, 0x542efb6a, 0x31797f8a},
    {0xafc19d86, 0x9983695c, 0x51dd5ffb, 0x2f96647a}, {0xad60a1d1, 0x96fd66f7, 0x4fa2687c, 0x2dcab91f},
    {0xab099ae9, 0x9488e64b, 0x4d7cfbc9, 0x2c151d8a}, {0xa8bc441a, 0x92253f20, 0x4b6c1139, 0x2a7449ef},
    {0xa6785b42, 0x8fd1d14a, 0x496eaf82, 0x28e70cc3}, {0xa43da0ae, 0x8d8e042a, 0x4783eba7, 0x276c4900},
    {0xa20bd701, 0x8b594648, 0x45aae80a, 0x2602f493}, {0x9fe2c315, 0x89330ce4, 0x43e2d382, 0x24aa16ec},
    {0x9dc22be4, 0x871ad399, 0x422ae88c, 0x2360c7af}, {0x9ba9da6c, 0x85101c05, 0x40826c88, 0x22262d7b},
    {0x99999999, 0x83126d70, 0x3ee8af07, 0x20f97cd2}, {0x97913630, 0x81215480, 0x3d5d0922, 0x1fd9f714},
    {0x95907eb8, 0x7f3c62ef, 0x3bdedce0, 0x1ec6e994}, {0x93974369, 0x7d632f45, 0x3a6d94a9, 0x1dbfacbb},
    {0x91a55615, 0x7b955498, 0x3908a2be, 0x1cc3a33b}, {0x8fba8a1c, 0x79d2724e, 0x37af80bf, 0x1bd23960},
    {0x8dd6b456, 0x781a2be4, 0x3661af39, 0x1aeae458}, {0x8bf9ab07, 0x766c28ba, 0x351eb539, 0x1a0d21a2},
    {0x8a2345cc, 0x74c813dd, 0x33e61feb, 0x19387676}, {0x88535d90, 0x732d9bdc, 0x32b7823a, 0x186c6f3e},
    {0x8689cc7e, 0x719c7297, 0x3192747d, 0x17a89f21}, {0x84c66df1, 0x70144d19, 0x30769424, 0x16ec9f89},
    {0x83091e6a, 0x6e94e36c, 0x2f63836f, 0x16380fbf}, {0x8151bb87, 0x6d1df079, 0x2e58e925, 0x158a9484},
    {0x7fa023f1, 0x6baf31de, 0x2d567053, 0x14e3d7ba}, {0x7df43758, 0x6a4867d3, 0x2c5bc811, 0x1443880e},
    {0x7c4dd664, 0x68e95508, 0x2b68a346, 0x13a958ab}, {0x7aace2b0, 0x6791be86, 0x2a7cb871, 0x131500ee},
    {0x79113ebc, 0x66416b95, 0x2997c17a, 0x12863c29}, {0x777acde8, 0x64f825a1, 0x28b97b82, 0x11fcc95c},
    {0x75e9746a, 0x63b5b822, 0x27e1a6b4, 0x11786b03}, {0x745d1746, 0x6279f081, 0x2710061d, 0x10f8e6da},
    {0x72d59c46, 0x61449e06, 0x26445f86, 0x107e05ac}, {0x7152e9f4, 0x601591be, 0x257e7b4d, 0x10079327},
    {0x6fd4e793, 0x5eec9e6b, 0x24be2445, 0x0f955da9}, {0x6e5b7d16, 0x5dc9986e, 0x24032795, 0x0f273620},
    {0x6ce6931d, 0x5cac55b7, 0x234d5496, 0x0ebcefdb}, {0x6b7612ec, 0x5b94adb2, 0x229c7cbc, 0x0e56606e},
  };
  // The range [1,2] is splitted into 64 equal sub-ranges and the
  // reciprocal square root is approximated by a cubic polynomial by
  // the minimax method in each subrange. The approximation accuracy
  // fits into 32-33 bits and thus it is natural to round
  // coefficients into 32 bit. The constant coefficient can be
  // rounded to 33 bits since the most significant bit is always 1
  // and implicitly assumed in the table.
  u64 indx = m>>58; // subrange index
  u64 c3 = c[indx][3], c0 = c[indx][0], c1 = c[indx][1], c2 = c[indx][2];
  c0 <<= 31; // to 64 bit with the space for the implicit bit
  c0 |= 1ull<<63; // add implicit bit
  c1 <<= 25; // to 64 bit format
  u64 d = (m<<6)>>32; // local coordinate in the subrange [0, 2^32]
  u64 d2 = ((u64)(d*d))>>32; // square of the local coordinate
  u64 re = c0 + (d2*c2>>13); // even part of the polynomial (positive)
  u64 ro = d*((c1 + ((d2*c3)>>19))>>26)>>6; // odd part of the polynomial (negative)
  u64 r = re - ro; // maximal error < 1.55e-10 and it is less than 2^-32
  // Newton-Raphson first order step to improve accuracy of the result to almost 64 bits
  // r1 = r0 - r0*(r0^2*x - 1)/2
  u64 r2 = mhuu(r,r);
  i64 h = mhuu(m,r2) + r2; // h = r0^2*x - 1
  i64 hr = mhii(h,r>>1); // r0*h/2
  r -= hr;
  if(__builtin_expect(!r, 0)) r--; // adjust in the unlucky case x~1
  return r;
}

__float128 cr_sqrtq(__float128 x) {
  unsigned flagp = _mm_getcsr(), oflagp = flagp;
  b128u128_u u = {.a = reinterpret_f128_as_u128(x)};
  i32 e = u.b[1]>>48; // exponent
  if(__builtin_expect(e==0, 0)){ // x is subnormal or x=+0
    i32 ns = -15;
    if(u.b[1]){
      ns += __builtin_clzll(u.b[1]);
    } else {
      if(u.b[0]) {
	ns += __builtin_clzll(u.b[0]) + 64;
      } else {
	return x; // x = +0
      }
    }
    e = 1 - ns;
    u.a <<= ns; // normalize mantissa
  }
  if(__builtin_expect(e>=0x7fff, 0)){// other special cases: NAN, inf, negative numbers
    if(!(u.a<<1)) return x; // x = -0
    if(u.a==(u128)0x7fff<<112) return x; // x = +Inf
    if(u.a<=(u128)0xffff<<112 && u.a>(u128)0x8000<<112){ // -inf <= x < -0
      // x < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      feraiseexcept (FE_INVALID);
      return __builtin_nanf128("<0");
    } else{
      if(!(u.b[1]&(1ull<<47))) feraiseexcept (FE_INVALID); // complain about the snan argument by the invalid exception
      u.b[1] |= 1ull<<47; // snan -> qnan
      return reinterpret_u128_as_f128(u.a); // qNaN
    }
  }
  e+=1; // adjust parity
  i32 q2 = e>>1, i = e&1;
  // exponent of the final result
  i64 e2 = (q2+8191ull-1)<<48;

  u.a <<= 16;
  const u64 rsqrt_2[] = {~0ull,0xb504f333f9de6484ull}; // 2^64/sqrt(2)
  u64 rx = u.b[1], r = rsqrt9(rx);
  u128 r2 = (u128)r*rsqrt_2[i];// + r;
  unsigned shft = 2-i;
  u.a >>= shft;
  u.b[1] |= 1ull<<(62+i);
  r = r2>>64;
  u128 sx = mhuU(r, u.a);
  i128 h  = mhuU(r, sx)<<2, ds = mhIU(h, sx);
  sx <<= 1;
  b128u128_u v; v.a = sx - ds;
  unsigned rm = flagp&_MM_ROUND_MASK, nrst = rm == _MM_ROUND_NEAREST;
  short dd = v.bs[0]<<2;
  if(__builtin_expect(!(dd<-37||dd>13), 0)){ // can round correctly?
    // m is almost the final result it can be only 1 ulp off so we
    // just need to test both possibilities. We square it and
    // compare with the initial argument.
    v.a += 1<<13;
    u128 m = v.a>>14, m2 = m*m;
    // the difference of the squared result and the argument
    i128 dm2 = m2 - (u.a<<100);
    v.b[0] &= ~0x3fffull;
    if(dm2>0) v.a --;
    if(dm2<0) v.a ++;
  }

  unsigned frac = v.b[0]&0x7fffull; // fractional part
  u64 rnd;
  if(__builtin_expect(nrst, 1)){
    rnd = frac>>14;  // round to nearest tie to even
  } else if(rm==_MM_ROUND_UP){
    rnd = !!frac; // round up
  } else if(rm==_MM_ROUND_DOWN){
    rnd = 0; // round down
  } else {
    rnd = 0; // round to zero
  }
  v.a >>= 15; // position mantissa
  v.a += rnd; // round

  // set inexact flag only if square root is really inexact or not already set
  if(__builtin_expect(frac, 1)) flagp |= FE_INEXACT;
  if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);

  v.b[1] += e2; // place exponent
  return reinterpret_u128_as_f128(v.a); // put into xmm register
}

// somewhat we need to include that for icx and the Intel math library
extern __float128 __sqrtq (__float128);

// sqrtq is called sqrtf128 in GNU libc, and __sqrtq in the Intel math library
__float128 sqrtq(__float128 x) {
#ifdef __INTEL_CLANG_COMPILER
  return __sqrtq (x);
#else
  return sqrtf128 (x);
#endif
}
