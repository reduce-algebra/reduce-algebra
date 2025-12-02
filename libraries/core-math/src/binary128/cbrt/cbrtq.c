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

#define _GNU_SOURCE /* to define ...f128 functions */

#include <errno.h>
#include <fenv.h> // for feraiseexcept, FE_INVALID and FE_INEXACT
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

// get high part of unsigned 64x64 bit multiplication
static inline u64 mhuu(u64 _a, u64 _b){
  return ((u128)_a*_b)>>64;
}

// get high part of signed 64x64 bit multiplication
static inline i64 mhii(i64 x, i64 y){
  return ((i128)x*y)>>64;
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

static inline u128 mhuU(u64 y, u128 x){
  b128u128_u ux = {.a = x};
  u128 xy0 = ux.b[0]*(u128)y;
  u128 xy1 = ux.b[1]*(u128)y;
  return xy1 + (xy0>>64);
}

static inline i64 mhium(i64 x, u64 y, i64 masky){
  u64 z = x, s = masky&y;
  i64 r = (u128)z*y>>64;
  r -= s;
  return r;
};

static inline i128 mhiUm(i64 y, u128 x, i64 m){
  b128u128_u ux = {.a = x};
  u128 xy1 = (u128)ux.b[1]*(u64)y;
  u128 xy0 = (u128)ux.b[0]*(u64)y;
  return xy1 - (m&x) + (xy0>>64);
}

// get full product of unsigned 128x128 bit multiplication
static inline u128 mUU(u128 _a, u128 _b, u128 *t){
  b128u128_u a, b, a1b0, a0b1, a1b1, a0b0;
  a.a = _a;
  b.a = _b;
  a1b0.a = (u128)a.b[1]*b.b[0];
  a0b1.a = (u128)a.b[0]*b.b[1];
  a1b1.a = (u128)a.b[1]*b.b[1];
  a0b0.a = (u128)a.b[0]*b.b[0];
  //     a0b0
  //   a1b0
  //   a0b1
  // a1b1
  unsigned long c;
  a0b0.b[1] = __builtin_addcl(a0b0.b[1], a1b0.b[0], 0, &c);
  a1b1.b[0] = __builtin_addcl(a1b1.b[0], a1b0.b[1], c, &c);
  a1b1.b[1] = __builtin_addcl(a1b1.b[1], 0, c, &c);
  a0b0.b[1] = __builtin_addcl(a0b0.b[1], a0b1.b[0], 0, &c);
  a1b1.b[0] = __builtin_addcl(a1b1.b[0], a0b1.b[1], c, &c);
  a1b1.b[1] = __builtin_addcl(a1b1.b[1], 0, c, &c);
  *t = a0b0.a;
  return a1b1.a;
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

static const struct {
  u64 knst[16];
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
inline static i64 as_rcbrt(u64 m){
  const int n0 = 28, n1 = 23, n2 = 13, s = 22;
  u64 indx = m>>60;
  u64 C = coef_bind.knst[indx];
  u64 c3 = (u64)coef_bind.knsth[indx];
  u64 c0 = (C<<(64-n0));
  u64 c1 = (C<<(64-n0-n1))>>(5+32);
  u64 c2 = (C<<(64-n0-n1-n2))>>(10+32);
  i64 d = (i64)((m<<4)-(1ll<<63))>>32;
  u64 d2 = ((u64)(d*d))>>32;
  u64 re = c0  + d2*c2;
  u64 ro = d*(c1 + ((d2*c3)>>22));
  u64 r = re - ro; // error < 1e-7
  u64 r2 = mhuu(r, r), r3 = mhuu(r2, r);
  i64 h = mhuu(m, r3) + r3;
  h <<= s;
  h = mhii(h,0x5555555555555555);
  u64 h2 = mhii(h,h);
  h -= h2>>(s-1);
  i64 hr = mhii(h,r) + h;
  return r-(hr>>s);
}

/**
 * sx = r0*r0*x ~ cbrt(x) or initial approximation
 * h = r0^3*x - 1 = r0*sx - 1
 * ds = h*(2/3)*sx
 * sx1 = sx - ds is the refined cubic root
 **/
inline static b128u128_u as_icbrt(b128u128_u x, unsigned i){
  static const u64 rcbrt_i[] = {0x8000000000000000, 0x6597fa94f5b8f20b, 0x50a28be635ca2b89}; // 2^63/cbrt(2^i)
  u64 r = as_rcbrt(x.b[1]);
  if(__builtin_expect((i64)r>=0, 0)) r = ~0ll; // now r cannot be above 1 it is strictly <1
  r = mhuu(r, rcbrt_i[i]);
  u128 r2 = (u128)r*r;
  x.a >>= 3-i;
  x.b[1] |= 1ull<<(61+i);
  b128u128_u sx = {.a = mhUU(r2, x.a)};
  i128 H = mhuU(r, sx.a);
  i64 h = H, m = h>>63;
  i64 h3 = mhium(h, 0xaaaaaaaaaaaaaaab, m); // h *= 2/3
  i128 ds = (i128)(mhiUm(h3, sx.a, m))>>(58-5);
  sx.a <<= 5;
  b128u128_u sx1 = {.a = sx.a - ds};
  short dd = sx1.bs[0]<<1;
  if(__builtin_expect(dd>-512&&dd<512, 0)){ // can round ?
    u128 c = (sx1.a + (1<<14))>>15 | (u128)1<<113;
    u128 R2l, R2h = mUU(c, c, &R2l);
    u128 R30, R31 = R2h*c + mUU(R2l, c, &R30);
    R31 -= x.a<<86;
    sx1.a = c<<15;
    if((i128)R31<0)
      sx1.a += 1;
    else if((i128)R31>0)
      sx1.a -= 1;
    else
      if(R30 != 0) sx1.a -= 1;
  }
  return sx1;
}

__float128 cr_cbrtq(__float128 x){
  unsigned flagp = _mm_getcsr(), oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  b128u128_u u = {.a = reinterpret_f128_as_u128(x)};
  i64 sign = u.b[1]>>63, e3;
  u32 e = (u.b[1]>>48)&0x7fff, i; // exponent
  if(__builtin_expect(e==0, 0)){ // x is subnormal or x=+-0
    i32 ns = -15;
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
  u64 b1 = v.b[1], b0 = v.b[0];
  u64 sbit = !!(b0<<48); // there are non-zero bits
  if(__builtin_expect(sbit, 1)) flagp |= FE_INEXACT;
  u64 rbit = (b0>>15)&1; // round bit
  b0 >>= 16;
  u64 rnd;
  if(__builtin_expect(rm == _MM_ROUND_NEAREST, 1)){
    rnd = rbit;
  } else if(rm == _MM_ROUND_UP){
    rnd = (1^sign)&sbit; // round up
  } else if(rm == _MM_ROUND_DOWN){
    rnd = sign&sbit; // round down
  } else { // _MM_ROUND_TOWARD_ZERO
    rnd = 0;
  }
  b0 |= b1<<48;
  b1 >>= 16;
  v.a = (u128)b1<<64|b0;
  e3 = e3<<48|sign<<63;
  u128 dv = (u128)e3<<64|rnd;
  v.a += dv;
  // set inexact flag only if it is not already set
  if(__builtin_expect(oflagp != flagp, 0)) _mm_setcsr(flagp);
  x = reinterpret_u128_as_f128(v.a);
  return x;
}

// somewhat we need to include that for icx and the Intel math library
extern __float128 __cbrtq (__float128);

// cbrtq is called cbrtf128 in GNU libc, and __cbrtq in the Intel math library
__float128 cbrtq(__float128 x) {
#ifdef __INTEL_CLANG_COMPILER
  return __cbrtq (x);
#else
  return cbrtf128 (x);
#endif
}
