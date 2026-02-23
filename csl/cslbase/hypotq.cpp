/* Correctly-rounded Euclidean distance function (hypot) for the binary128 format.

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

// $Id$

// This code, originally part of "core math", has been adjusted (and
// some might say hacked!) by ACN for use within CSL. The changes are...
// (1) It will be compiled as C++ code not  C code.
// (2) It only needs to support the "round to nearest" option so
//     other capabilities have been commented out.
// (3) Specialisations for particular architectures have been removed
//     so the code no longer uses (eg) x86_64 SSE intrinsics. This
//     will make it a bit slower!
// (4) On the Mac there is no built in type for 128-bit floats and
//     elsewhere in CSL I do not try to use __float128, so the type
//     there has been adjusted.
// (5) In due course I will (I hope) change __builtin_expect to use
//     the more modern and general C++ decorations for code, and in
//     general I wish to avoid use of intrinsics as much as possible
//     or at least provide fallbacks for when they are not available.

#include "float128_t.h"
#include "int128_t.h"
using namespace CSL_LISP;

//- #define _GNU_SOURCE /* to define ...f128 functions */

#include <errno.h>
#include <fenv.h> // for FE_INVALID, FE_INEXACT, FE_OVERFLOW, FE_UNDERFLOW
#include <stdint.h>
#include <math.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

//- // Warning: clang also defines __GNUC__
//- #if defined(__GNUC__) && !defined(__clang__)
//- #pragma GCC diagnostic ignored "-Wunknown-pragmas"
//- #endif

//- // This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
//- // fegetexceptflag accesses the FPSR register, which seems to be much slower
//- // than accessing FPCR, so it should be avoided if possible.
//- // Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
//- #if defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
//- #if defined(_MSC_VER)
//- #include <arm64intr.h>
//- #endif
//-
//- typedef struct
//- {
//-   uint16_t res0;
//-   uint8_t  res1  : 6;
//-   uint8_t  bit22 : 1;
//-   uint8_t  bit23 : 1;
//-   uint8_t  bit24 : 1;
//-   uint8_t  res2  : 7;
//-   uint32_t res3;
//- } fpcr_bitfield;
//-
//- inline unsigned int _mm_getcsr()
//- {
//-   union
//-   {
//-     fpcr_bitfield field;
//-     uint64_t value;
//-   } r;
//-
//- #if defined(_MSC_VER) && !defined(__clang__)
//-   r.value = _ReadStatusReg(ARM64_FPCR);
//- #else
//-   __asm__ __volatile__("mrs %0, FPCR" : "=r"(r.value));
//- #endif
//-   static const unsigned int lut[2][2] = {{0x0000, 0x2000}, {0x4000, 0x6000}};
//-   return lut[r.field.bit22][r.field.bit23];
//- }
//- #endif  // defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)

typedef union {
  uint128_t a;
  int128_t as;
  uint64_t b[2];
  int64_t bs[2];
  float128_t f;
} b128uint128_t_u;

//- #if (defined(__x86_64__) && (defined(__APPLE__) || defined(_WIN32)))
//- inline float128_t local_nanq(__attribute__((unused)) const char *tagp){
//-   b128uint128_t_u u;
//-   u.a = ~(uint128_t)0u;
//-   return u.f;
//- }
//- #define __builtin_nanf128(tagp) local_nanq(tagp)
//- #endif

// get high part of unsigned 64x64 bit multiplication
inline uint64_t mhuu(uint64_t _a, uint64_t _b){
  return ((uint128_t)_a*_b)>>64;
}

// get high part of signed 64x64 bit multiplication
inline int64_t mhii(int64_t x, int64_t y){
  return ((int128_t)x*y)>>64;
}

inline uint128_t mhuU(uint64_t y, uint128_t x){
  b128uint128_t_u ux; ux.a = x;
  uint128_t xy0 = ux.b[0]*(uint128_t)y;
  uint128_t xy1 = ux.b[1]*(uint128_t)y;
  return xy1 + (xy0>>64);
}

// get appoximate high part of unsigned 128 bit squaring
inline uint128_t sqrhU(uint128_t _a){
  b128uint128_t_u a, a10, a11;
  a.a = _a;
  a10.a = (uint128_t)a.b[1]*a.b[0];
  a11.a = (uint128_t)a.b[1]*a.b[1];
  a11.a += a10.b[1];
  a11.a += a10.b[1];
  return a11.a;
}

// get full product of unsigned 128x128 bit squaring
inline uint128_t sqrU(uint128_t _a, uint128_t *t){
  b128uint128_t_u a, a10, a11, a00;
  a.a = _a;
  a10.a = (uint128_t)a.b[1]*a.b[0];
  a11.a = (uint128_t)a.b[1]*a.b[1];
  a00.a = (uint128_t)a.b[0]*a.b[0];
  //     a0a0
  //   a1a0
  //   a1a0
  // a1a1
  unsigned int c;
// addcl(x, y, carry_in, *carry_out)
  a00.b[1] = add_with_carry(a00.b[1], a10.b[0], 0U, c);
  a11.b[0] = add_with_carry(a11.b[0], a10.b[1], c, c);
  a11.b[1] = add_with_carry(a11.b[1], 0, c, c);
  a00.b[1] = add_with_carry(a00.b[1], a10.b[0], 0U, c);
  a11.b[0] = add_with_carry(a11.b[0], a10.b[1], c, c);
  a11.b[1] = add_with_carry(a11.b[1], 0, c, c);
  *t = a00.a;
  return a11.a;
}

// add two 128 bit numbers with overflow bit
inline uint128_t addUU(uint64_t *c, uint128_t _a, uint128_t _b){
  b128uint128_t_u a, b;
  unsigned int d;
  a.a = _a;
  b.a = _b;
  a.b[0] = add_with_carry(a.b[0], b.b[0], 0U, d);
  a.b[1] = add_with_carry(a.b[1], b.b[1], d, d);
  *c = d;
  return a.a;
}

// get appoximate high part of unsigned 128x128 bit multiplication
inline uint128_t mhUU(uint128_t _a, uint128_t _b){
  b128uint128_t_u a, b, a1b0, a0b1, a1b1;
  a.a = _a;
  b.a = _b;
  a1b0.a = (uint128_t)a.b[1]*b.b[0];
  a0b1.a = (uint128_t)a.b[0]*b.b[1];
  a1b1.a = (uint128_t)a.b[1]*b.b[1];
  a1b1.a += a1b0.b[1];
  a1b1.a += a0b1.b[1];
  return a1b1.a;
}

// get high 128 bit part of (unsigned 128)x(signed 128) bit
// multiplication with sign mask
inline int128_t mhUIm(uint128_t _a, int128_t _b, uint64_t mask){
  b128uint128_t_u sub; sub.a = _a;
  sub.b[0] &= mask;
  sub.b[1] &= mask;
  return mhUU(_a,_b) - sub.a;
}

// get high 128 bit part of (unsigned 128)x(signed 128) bit
// multiplication
inline int128_t mhIU(int128_t _b, uint128_t _a){
  return mhUIm(_a,_b,(uint64_t)(_b>>127));
}

inline float128_t reinterpret_uint128_t_as_f128(uint128_t t){
//- #if defined(__x86_64__) && !defined(__clang__)
//-   // put uint128_t into xmm register
//-   __m128i m = {0, 0};
//-   m = _mm_insert_epint64_t (m, t, 0);
//-   m = _mm_insert_epint64_t (m, t>>64, 1);
//-   float128_t r;
//-   asm("": "=x"(r): "0"(m));
//-   return r;
//- #else
  b128uint128_t_u u = {.a = t};
  return u.f;
//- #endif
}

inline uint128_t reinterpret_f128_as_uint128_t(float128_t z){
//- #if defined(__x86_64__) && !defined(__clang__)
//-   __m128i t;
//-   asm("" : "=x" (t) :"0" (z));
//-   uint64_t h = _mm_extract_epint64_t(t, 1);
//-   uint64_t l = _mm_extract_epint64_t(t, 0);
//-   return ((uint128_t)h<<64)|l;
//- #else
  b128uint128_t_u u = {.f = z};
  return u.a;
//- #endif
}

// for low precision approxmation use 64x64->64 bit multiplication
inline uint64_t rsqrt9(uint64_t m){
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
  uint64_t indx = m>>58; // subrange index
  uint64_t c3 = c[indx][3], c0 = c[indx][0], c1 = c[indx][1], c2 = c[indx][2];
  c0 <<= 31; // to 64 bit with the space for the implicit bit
  c0 |= 1ull<<63; // add implicit bit
  c1 <<= 25; // to 64 bit format
  uint64_t d = (m<<6)>>32; // local coordinate in the subrange [0, 2^32]
  uint64_t d2 = ((uint64_t)(d*d))>>32; // square of the local coordinate
  uint64_t re = c0 + (d2*c2>>13); // even part of the polynomial (positive)
  uint64_t ro = d*((c1 + ((d2*c3)>>19))>>26)>>6; // odd part of the polynomial (negative)
  uint64_t r = re - ro; // maximal error < 1.55e-10 and it is less than 2^-32
  // Newton-Raphson first order step to improve accuracy of the result to almost 64 bits
  // r1 = r0 - r0*(r0^2*x - 1)/2
  uint64_t r2 = mhuu(r,r);
  int64_t h = mhuu(m,r2) + r2; // h = r0^2*x - 1
  int64_t hr = mhii(h,r>>1); // r0*h/2
  r -= hr;
  if(__builtin_expect(!r, 0)) r--; // adjust in the unlucky case x~1
  return r;
}

// 0 - ordinary number, 1 -- infinity, 2 -- snan, 3 -- qnan
__attribute__((noinline)) char getclass(uint128_t x){
  uint64_t xh = x>>64, xl = x;
  int t = xh>>32 | !!(xh<<32|xl);
  return (t>=0x7fff<<16) + (t>=(0x7fff<<16)+1) + (t>=(0x7fff8<<12));
}

float128_t cr_hypotq(float128_t x, float128_t y) {
//-  unsigned flagp = _mm_getcsr(), oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  const uint64_t smsk = 1ll<<63;
  b128uint128_t_u X = {.a = reinterpret_f128_as_uint128_t(x)};
  b128uint128_t_u Y = {.a = reinterpret_f128_as_uint128_t(y)};

  X.b[1] &= ~smsk; // strip sign
  Y.b[1] &= ~smsk; // strip sign

  b128uint128_t_u a, b;
  int128_t dab = X.a - Y.a;
  dab &= dab>>127;
  a.a = X.a - dab;
  b.a = Y.a + dab;
  int xn = a.b[1]>>48, yn = b.b[1]>>48;
  if(__builtin_expect(xn==0x7fff, 0)){
    float128_t out;
    // 1 -- infinity, 2 -- snan, 3 -- qnan
    char xnan = getclass(a.a), ynan = getclass(b.a);
    if(xnan==2||ynan==2){ // signaling NAN
//-      flagp |= FE_INVALID;
//-      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
//-      out = __builtin_nanf128("hypot");
      out = f128_NaN; // __builtin_nanf128("hypot");
    } else if(xnan+ynan==4) {//quiet NAN
//-      out = __builtin_inff128(); // hypot(+-inf,qnan) = inf and hypot(qnan, +-inf) = inf
      out = f128_inf; // __builtin_inff128(); // hypot(+-inf,qnan) = inf and hypot(qnan, +-inf) = inf
    } else if(xnan==3) {//quiet NAN
      out = reinterpret_uint128_t_as_f128(a.a); // propagate nan
    } else if(ynan==3) {//quiet NAN
      out = reinterpret_uint128_t_as_f128(b.a); // propagate nan
    } else { // infinity and a normal number
//-      out = __builtin_inff128();
      out = f128_inf; // __builtin_inff128();
    }
    return out;
  }
  if(__builtin_expect(yn==0, 0)){
    int32_t ns = -15;
    if(b.b[1]){
// count leading zeros in 64-bit value.
      ns += __builtin_clzll(b.b[1]);
    } else {
      if(b.b[0]) {
	ns += __builtin_clzll(b.b[0]) + 64;
      } else {
	return reinterpret_uint128_t_as_f128(a.a);
      }
    }
    yn = 1 - ns;
    b.a <<= ns; // normalize mantissa
    if(__builtin_expect(xn==0, 0)){
      ns = -15;
      if(a.b[1]){
	ns += __builtin_clzll(a.b[1]);
      } else {
	ns += __builtin_clzll(a.b[0]) + 64;
      }
      xn = 1 - ns;
      a.a <<= ns; // normalize mantissa
    }
  }

  int dn = xn - yn;
  a.a <<= 15; a.b[1] |= 1ull<<63;
  b128uint128_t_u v, dv;
  if(__builtin_expect(dn>56, 0)){
    // if x or y is too small compare to the other number
    // return the largest number
    v.a = a.a|1;
  } else {
    b.a <<= 15; b.b[1] |= 1ull<<63;
    b128uint128_t_u a2128 = {.a = sqrhU(a.a)}, b2 = {.a = sqrhU(b.a>>dn)};
    uint64_t overflow;
    a2128.a = addUU(&overflow, a2128.a, b2.a);
    int nz = (~0u + overflow) & __builtin_clzll(a2128.b[1]);
    unsigned i = (!overflow + nz)&1;
    int s = 1 - overflow + nz;
    a2128.a <<= s;
    xn += overflow;
    const uint64_t rsqrt_2[] = {~0ull,0xb504f333f9de6484ull}; // 2^64/sqrt(2)
    uint64_t rx = a2128.b[1], r = rsqrt9(rx);
    uint128_t r2 = (uint128_t)r*rsqrt_2[i];
    unsigned shft = 2-i;
    a2128.a >>= shft;
    a2128.b[1] |= 1ull<<(62+i);
    r = r2>>64;
    uint128_t sx = mhuU(r, a2128.a);
    int128_t h  = mhuU(r, sx)<<2, ds = mhIU(h, sx);
    sx <<= 1;
    v.a = sx - ds;
    short dd = v.b[0]<<2;
    if(dd>-37 && dd<13){ // rounding test
      v.a += 1<<13;
      v.b[0] &= ~0ull<<14;
      overflow = v.a==0;
      uint128_t c = v.a>>13;
      uint128_t c2 = c*c;
      a.a >>= 13;
      uint128_t al, ah = sqrU(a.a, &al);
      b.a >>= 13;
      uint128_t bl, bh = sqrU(b.a, &bl);
      if(dn){
	bl = (bl>>2*dn|bh<<(128-2*dn)) | !!(bl << (128-2*dn));
	bh = bh>>2*dn;
      }
      al += bl;
      ah += bh + (al<bl);
      s = (ah>>102)*2;
      if(s) {
	al = (al>>s|ah<<(128-s))|!!(al<<(128-s));
      }
      al -= c2;
      v.b[1] |= (uint64_t)overflow<<63;
      xn += overflow;
      if((int128_t)al<0)
	v.a -= 1;
      else if((int128_t)al>0)
	v.a += 1;
    }
  }

  if(__builtin_expect(--xn>0,1)){
    if(__builtin_expect(xn>=32766,0)){
      uint64_t rnd, over = v.b[1]>>63;
//-       if(__builtin_expect(rm==_MM_ROUND_NEAREST, 1)){
	rnd = 1;  // round to nearest tie to even
//-       } else if(rm==_MM_ROUND_UP){
//- 	rnd = 1; // round up
//-       } else if(rm==_MM_ROUND_DOWN){
//- 	rnd = 0; // round down
//-       } else {
//- 	rnd = 0; // round to zero
//-       }
      v.a = ((uint128_t)0x7fff<<112) - 1;
      v.a += rnd;
//-      flagp |= FE_INEXACT;
      // set overflow exception for result which is indeed overflow as well as rounded to infinity
      if(v.b[1] == 0x7fffull<<48 || over){
//-	flagp |= FE_OVERFLOW;
#ifdef CORE_MATH_SUPPORT_ERRNO
	errno = ERANGE;
#endif
      }
    } else {
      unsigned frac = v.b[0]&0x7fffull; // fractional part
      uint64_t rnd;
//-       if(__builtin_expect(rm==_MM_ROUND_NEAREST, 1)){
	if(__builtin_expect(frac==0x4000, 0)){  // round to nearest tie to even
	  rnd = (v.b[0]>>15)&1;
	} else
        rnd = frac>>14;
//-      } else if(rm==_MM_ROUND_UP){
//- 	rnd = !!frac; // round up
//-       } else if(rm==_MM_ROUND_DOWN){
//- 	rnd = 0; // round down
//-       } else {
//- 	rnd = 0; // round to zero
//-       }
      v.a >>= 15; // position mantissa
      dv.b[0] = rnd;
      dv.b[1] = (uint128_t)xn<<48;
      v.a += dv.a;
      // set inexact flag only if hypot is really inexact
//-       if(__builtin_expect(frac, 1)) flagp |= FE_INEXACT;
    }
  } else {
    uint128_t frac = v.a&(((uint128_t)1<<(15-xn))-1); // fractional part
    uint64_t rnd;
//-     if(__builtin_expect(rm==_MM_ROUND_NEAREST, 1)){
      if(__builtin_expect(frac==(uint128_t)1<<(14-xn), 0)){  // round to nearest tie to even
	rnd = (v.a>>(15-xn))&1;
      } else
	rnd = frac>>(14-xn);
//-     } else if(rm==_MM_ROUND_UP){
//-       rnd = !!frac; // round up
//-     } else if(rm==_MM_ROUND_DOWN){
//-       rnd = 0; // round down
//-     } else {
//-       rnd = 0; // round to zero
//-     }
    v.a >>= 15 - xn; // position mantissa
    v.a += rnd;
    // set inexact and underflow flags only if hypot is really inexact
    if(__builtin_expect(frac, 1)){
//-       flagp |= FE_INEXACT;
//-       if(v.b[1]<(1ull<<48)) flagp |= FE_UNDERFLOW;
    }
  }
//-   if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
  return reinterpret_uint128_t_as_f128(v.a); // put into xmm register
}

//- // somewhat we need to include that for icx and the Intel math library
//- extern float128_t __hypotq (float128_t, float128_t);
//-
//- // hypotq is called hypotf128 in GNU libc, and __hypotq in the Intel math library
//- float128_t hypotq(float128_t x, float128_t y) {
//- #ifdef __INTEL_CLANG_COMPILER
//-   return __hypotq (x, y);
//- #else
//-   return hypotf128 (x, y);
//- #endif
//- }

// end of hypotq.cpp
