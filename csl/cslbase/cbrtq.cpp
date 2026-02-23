/* Correctly-rounded cubic root of binary128 value.

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
#include <fenv.h> // for feraiseexcept, FE_INVALID and FE_INEXACT
#include <stdint.h>
#include <math.h>
//- #ifdef __x86_64__
//- #include <x86intrin.h>
//- #endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

//#pragma STDC FENV_ACCESS ON

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
} b128u128_u;

// get high part of unsigned 64x64 bit multiplication
inline uint64_t mhuu(uint64_t _a, uint64_t _b){
  return ((uint128_t)_a*_b)>>64;
}

// get high part of signed 64x64 bit multiplication
inline int64_t mhii(int64_t x, int64_t y){
  return ((int128_t)x*y)>>64;
}

// get appoximate high part of unsigned 128x128 bit multiplication
inline uint128_t mhUU(uint128_t _a, uint128_t _b){
  b128u128_u a, b, a1b0, a0b1, a1b1;
  a.a = _a;
  b.a = _b;
  a1b0.a = (uint128_t)a.b[1]*b.b[0];
  a0b1.a = (uint128_t)a.b[0]*b.b[1];
  a1b1.a = (uint128_t)a.b[1]*b.b[1];
  a1b1.a += a1b0.b[1];
  a1b1.a += a0b1.b[1];
  return a1b1.a;
}

inline uint128_t mhuU(uint64_t y, uint128_t x){
  b128u128_u ux = {.a = x};
  uint128_t xy0 = ux.b[0]*(uint128_t)y;
  uint128_t xy1 = ux.b[1]*(uint128_t)y;
  return xy1 + (xy0>>64);
}

inline int64_t mhium(int64_t x, uint64_t y, int64_t masky){
  uint64_t z = x, s = masky&y;
  int64_t r = (uint128_t)z*y>>64;
  r -= s;
  return r;
};

inline int128_t mhiUm(int64_t y, uint128_t x, int64_t m){
  b128u128_u ux = {.a = x};
  uint128_t xy1 = (uint128_t)ux.b[1]*(uint64_t)y;
  uint128_t xy0 = (uint128_t)ux.b[0]*(uint64_t)y;
  return xy1 - (m&x) + (xy0>>64);
}

// get full product of unsigned 128x128 bit multiplication
inline uint128_t mUU(uint128_t _a, uint128_t _b, uint128_t *t){
  b128u128_u a, b, a1b0, a0b1, a1b1, a0b0;
  a.a = _a;
  b.a = _b;
  a1b0.a = (uint128_t)a.b[1]*b.b[0];
  a0b1.a = (uint128_t)a.b[0]*b.b[1];
  a1b1.a = (uint128_t)a.b[1]*b.b[1];
  a0b0.a = (uint128_t)a.b[0]*b.b[0];
  //     a0b0
  //   a1b0
  //   a0b1
  // a1b1
  unsigned int c;
  a0b0.b[1] = add_with_carry(a0b0.b[1], a1b0.b[0], 0, c);
  a1b1.b[0] = add_with_carry(a1b1.b[0], a1b0.b[1], c, c);
  a1b1.b[1] = add_with_carry(a1b1.b[1], 0, c, c);
  a0b0.b[1] = add_with_carry(a0b0.b[1], a0b1.b[0], 0, c);
  a1b1.b[0] = add_with_carry(a1b1.b[0], a0b1.b[1], c, c);
  a1b1.b[1] = add_with_carry(a1b1.b[1], 0, c, c);
  *t = a0b0.a;
  return a1b1.a;
}

inline float128_t reinterpret_uint128_t_as_f128(uint128_t t){
//- #if defined(__x86_64__) && !defined(__clang__)
//-   // put uint128_t into xmm register
//-   __m128i m = {0, 0};
//-   m = _mm_insert_epi64 (m, t, 0);
//-   m = _mm_insert_epi64 (m, t>>64, 1);
//-   float128_t r;
//-   asm("": "=x"(r): "0"(m));
//-   return r;
//- #else
  b128u128_u u = {.a = t};
  return u.f;
//- #endif
}

inline uint128_t reinterpret_f128_as_uint128_t(float128_t z){
//- #if defined(__x86_64__) && !defined(__clang__)
//-   __m128i t;
//-   asm("" : "=x" (t) :"0" (z));
//-   uint64_t h = _mm_extract_epi64(t, 1);
//-   uint64_t l = _mm_extract_epi64(t, 0);
//-   return ((uint128_t)h<<64)|l;
//- #else
  b128u128_u u = {.f = z};
  return u.a;
//- #endif
}

static const struct {
  uint64_t knst[16];
  unsigned char knsth[16];
} coef_bind =
  {.knst =
   {0xd3ed1e72efd6337b, 0xb8bcbb918f877572, 0xa244650b6f3e7f80, 0x8f8418c89efa9d5e,
    0x7fb3d5217ebb3895, 0x724398c31e7fd263, 0x66c3629b4e47ff19, 0x5cd331ca2e136288,
    0x543b0596ede1ad3b, 0x4cbadd683db29a42, 0x4622b8bd8d85ed78, 0x4052972a5d5b7219,
    0x3b327852ad32f99e, 0x369a5be7fd0c5ad6, 0x328241a6bce7711b, 0x2eda2954acc41bb2},
   .knsth =
   {0xa0, 0x83, 0x6d, 0x5c, 0x4e, 0x42, 0x39, 0x31, 0x2b, 0x25, 0x21, 0x1d, 0x1a, 0x17, 0x15, 0x13}
  };

// return 1 + r, where r is signed
inline int64_t as_rcbrt(uint64_t m){
  const int n0 = 28, n1 = 23, n2 = 13, s = 22;
  uint64_t indx = m>>60;
  uint64_t C = coef_bind.knst[indx];
  uint64_t c3 = (uint64_t)coef_bind.knsth[indx];
  uint64_t c0 = (C<<(64-n0));
  uint64_t c1 = (C<<(64-n0-n1))>>(5+32);
  uint64_t c2 = (C<<(64-n0-n1-n2))>>(10+32);
  int64_t d = (int64_t)((m<<4)-(1ll<<63))>>32;
  uint64_t d2 = ((uint64_t)(d*d))>>32;
  uint64_t re = c0  + d2*c2;
  uint64_t ro = d*(c1 + ((d2*c3)>>22));
  uint64_t r = re - ro; // error < 1e-7
  uint64_t r2 = mhuu(r, r), r3 = mhuu(r2, r);
  int64_t h = mhuu(m, r3) + r3;
  h <<= s;
  h = mhii(h,0x5555555555555555);
  uint64_t h2 = mhii(h,h);
  h -= h2>>(s-1);
  int64_t hr = mhii(h,r) + h;
  return r-(hr>>s);
}

/**
 * sx = r0*r0*x ~ cbrt(x) or initial approximation
 * h = r0^3*x - 1 = r0*sx - 1
 * ds = h*(2/3)*sx
 * sx1 = sx - ds is the refined cubic root
 **/
inline b128u128_u as_icbrt(b128u128_u x, unsigned i){
  static const uint64_t rcbrt_i[] = {0x8000000000000000, 0x6597fa94f5b8f20b, 0x50a28be635ca2b89}; // 2^63/cbrt(2^i)
  uint64_t r = as_rcbrt(x.b[1]);
  if(__builtin_expect((int64_t)r>=0, 0)) r = ~0ll; // now r cannot be above 1 it is strictly <1
  r = mhuu(r, rcbrt_i[i]);
  uint128_t r2 = (uint128_t)r*r;
  x.a >>= 3-i;
  x.b[1] |= 1ull<<(61+i);
  b128u128_u sx = {.a = mhUU(r2, x.a)};
  int128_t H = mhuU(r, sx.a);
  int64_t h = H, m = h>>63;
  int64_t h3 = mhium(h, 0xaaaaaaaaaaaaaaab, m); // h *= 2/3
  int128_t ds = (int128_t)(mhiUm(h3, sx.a, m))>>(58-5);
  sx.a <<= 5;
  b128u128_u sx1 = {.a = sx.a - ds};
  short dd = sx1.bs[0]<<1;
  if(__builtin_expect(dd>-512&&dd<512, 0)){ // can round ?
    uint128_t c = (sx1.a + (1<<14))>>15 | (uint128_t)1<<113;
    uint128_t R2l, R2h = mUU(c, c, &R2l);
    uint128_t R30, R31 = R2h*c + mUU(R2l, c, &R30);
    R31 -= x.a<<86;
    sx1.a = c<<15;
    if((int128_t)R31<0)
      sx1.a += 1;
    else if((int128_t)R31>0)
      sx1.a -= 1;
    else
      if(R30 != 0) sx1.a -= 1;
  }
  return sx1;
}

float128_t cr_cbrtq(float128_t x){
//-   unsigned flagp = _mm_getcsr(), oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  b128u128_u u = {.a = reinterpret_f128_as_uint128_t(x)};
  int64_t sign = u.b[1]>>63, e3;
  uint32_t e = (u.b[1]>>48)&0x7fff, i; // exponent
  if(__builtin_expect(e==0, 0)){ // x is subnormal or x=+-0
    int32_t ns = -15;
    u.b[1] &= ~0ull>>1;
    if(u.b[1]){
      ns += __builtin_clzll(u.b[1]);
    } else {
      if(u.b[0]) {
	ns += __builtin_clzll(u.b[0]) + 64;
      } else {
	return x; // x = +-0
      }
    }
    e = 121 - ns;
    e3 = e/3 + 10882;
    i = e%3;
    u.a <<= ns; // normalize mantissa
  } else if(__builtin_expect(e==0x7fff, 0)){// other special cases: NaN, inf
    if((u.b[1]<<16|u.b[0]) && !(u.b[1]&(1ull<<47))){ // x = sNaN
      u.b[1] |= 1ull<<47; // sNaN -> qNaN
      feraiseexcept (FE_INVALID);
      return u.f; // NaN
    }
    return x; // x = +-Inf, +-qNaN
  } else {
    e3 = e/3 + 10922;
    i = e%3;
  }
  u.a <<= 16;
  b128u128_u v = as_icbrt(u,i);
  uint64_t b1 = v.b[1], b0 = v.b[0];
//-   uint64_t sbit = !!(b0<<48); // there are non-zero bits
//-   if(__builtin_expect(sbit, 1)) flagp |= FE_INEXACT;
  uint64_t rbit = (b0>>15)&1; // round bit
  b0 >>= 16;
  uint64_t rnd;
// For my purposes I will only want to handld the ROUND_NEAREST case.
//-  if(__builtin_expect(rm == _MM_ROUND_NEAREST, 1)){
    rnd = rbit;
//-  } else if(rm == _MM_ROUND_UP){
//-    rnd = (1^sign)&sbit; // round up
//-  } else if(rm == _MM_ROUND_DOWN){
//-    rnd = sign&sbit; // round down
//-  } else { // _MM_ROUND_TOWARD_ZERO
//- rnd = 0;
//-  }
  b0 |= b1<<48;
  b1 >>= 16;
  v.a = (uint128_t)b1<<64|b0;
  e3 = e3<<48|sign<<63;
  uint128_t dv = (uint128_t)e3<<64|rnd;
  v.a += dv;
  // set inexact flag only if it is not already set
//-  if(__builtin_expect(oflagp != flagp, 0)) _mm_setcsr(flagp);
  x = reinterpret_uint128_t_as_f128(v.a);
  return x;
}

//- // somewhat we need to include that for icx and the Intel math library
//- extern float128_t __cbrtq (float128_t);
//-
//- // cbrtq is called cbrtf128 in GNU libc, and __cbrtq in the Intel math library
//- float128_t cbrtq(float128_t x) {
//- #ifdef __INTEL_CLANG_COMPILER
//-   return __cbrtq (x);
//- #else
//-   return cbrtf128 (x);
//- #endif
//- }
