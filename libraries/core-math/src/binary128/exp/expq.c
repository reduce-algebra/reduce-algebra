/* Correctly-rounded exponential function for the IEEE-754 binary128 format

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

#ifdef CORE_MATH_SUPPORT_ERRNO
#include <errno.h>
#endif
#include <fenv.h> // for FE_INEXACT, FE_INVALID, FE_OVERFLOW, FE_UNDERFLOW
#include <stdint.h>
#include <math.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u2x64[2];
typedef uint64_t u3x64[3];
typedef uint64_t u4x64[4];
typedef uint64_t u6x64[6];
typedef uint64_t u7x64[7];
typedef union {
  u128 a;
  i128 as;
  u64 b[2];
  i64 bs[2];
  __float128 f;
} b128u128_u;

// get high part of unsigned 64x64 bit multiplication
static inline u64 __attribute__((always_inline)) mhuu(u64 _a, u64 _b){
  return ((u128)_a*_b)>>64;
}

// get appoximate high part of unsigned 128x128 bit multiplication
static inline u128 __attribute__((always_inline)) mhUU(u128 _a, u128 _b){
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

static inline __float128 __attribute__((always_inline)) reinterpret_u128_as_f128(u128 t){
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

static inline u128 __attribute__((always_inline)) reinterpret_f128_as_u128(__float128 z){
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

static void __attribute__((noinline)) mhu7xu2(u7x64 o, const u7x64 a, u128 b){
  u64 b0 = b, b1 = b>>64;
  u128 a0b1 = a[0]*(u128)b1;
  u128 a1b1 = a[1]*(u128)b1;
  u128 a2b1 = a[2]*(u128)b1;
  u128 a3b1 = a[3]*(u128)b1;
  u128 a4b1 = a[4]*(u128)b1;
  u128 a5b1 = a[5]*(u128)b1;
  u128 a6b1 = a[6]*(u128)b1;

  u64 c0;
  o[0] = __builtin_addcl(a1b1, a0b1>>64,  0, &c0);
  o[1] = __builtin_addcl(a2b1, a1b1>>64, c0, &c0);
  o[2] = __builtin_addcl(a3b1, a2b1>>64, c0, &c0);
  o[3] = __builtin_addcl(a4b1, a3b1>>64, c0, &c0);
  o[4] = __builtin_addcl(a5b1, a4b1>>64, c0, &c0);
  o[5] = __builtin_addcl(a6b1, a5b1>>64, c0, &c0);
  o[6] = __builtin_addcl(   0, a6b1>>64, c0, &c0);

  u128 a1b0 = a[1]*(u128)b0;
  u128 a2b0 = a[2]*(u128)b0;
  u128 a3b0 = a[3]*(u128)b0;
  u128 a4b0 = a[4]*(u128)b0;
  u128 a5b0 = a[5]*(u128)b0;
  u128 a6b0 = a[6]*(u128)b0;
  u64 c1, t;
  t    = __builtin_addcl(a2b0, a1b0>>64,  0, &c1);
  o[0] = __builtin_addcl(o[0],        t,  0, &c0);
  t    = __builtin_addcl(a3b0, a2b0>>64, c1, &c1);
  o[1] = __builtin_addcl(o[1],        t, c0, &c0);
  t    = __builtin_addcl(a4b0, a3b0>>64, c1, &c1);
  o[2] = __builtin_addcl(o[2],        t, c0, &c0);
  t    = __builtin_addcl(a5b0, a4b0>>64, c1, &c1);
  o[3] = __builtin_addcl(o[3],        t, c0, &c0);
  t    = __builtin_addcl(a6b0, a5b0>>64, c1, &c1);
  o[4] = __builtin_addcl(o[4],        t, c0, &c0);
  t    = __builtin_addcl(   0, a6b0>>64, c1, &c1);
  o[5] = __builtin_addcl(o[5],        t, c0, &c0);
  o[6] = __builtin_addcl(o[6],        0, c0, &c0);
}

static inline void __attribute__((always_inline)) mhu4xu2(u4x64 o, const u4x64 a, u128 b){
  u64 b0 = b, b1 = b>>64;
  u128 a0b1 = a[0]*(u128)b1;
  u128 a1b1 = a[1]*(u128)b1;
  u128 a2b1 = a[2]*(u128)b1;
  u128 a3b1 = a[3]*(u128)b1;

  u64 c0;
  o[0] = __builtin_addcl(a1b1, a0b1>>64,  0, &c0);
  o[1] = __builtin_addcl(a2b1, a1b1>>64, c0, &c0);
  o[2] = __builtin_addcl(a3b1, a2b1>>64, c0, &c0);
  o[3] = __builtin_addcl(   0, a3b1>>64, c0, &c0);

  u128 a1b0 = a[1]*(u128)b0;
  u128 a2b0 = a[2]*(u128)b0;
  u128 a3b0 = a[3]*(u128)b0;
  u64 c1, t;
  t    = __builtin_addcl(a2b0, a1b0>>64,  0, &c1);
  o[0] = __builtin_addcl(o[0],        t,  0, &c0);
  t    = __builtin_addcl(a3b0, a2b0>>64, c1, &c1);
  o[1] = __builtin_addcl(o[1],        t, c0, &c0);
  t    = __builtin_addcl(   0, a3b0>>64, c1, &c1);
  o[2] = __builtin_addcl(o[2],        t, c0, &c0);
  o[3] = __builtin_addcl(o[3],        0, c0, &c0);
}

static inline void __attribute__((always_inline)) mhu3xu2(u3x64 o, const u3x64 a, u128 b){
  u64 b0 = b, b1 = b>>64;
  u128 a1b0 = a[1]*(u128)b0;
  u128 a2b0 = a[2]*(u128)b0;
  u128 a0b1 = a[0]*(u128)b1;
  u128 a1b1 = a[1]*(u128)b1;
  u128 a2b1 = a[2]*(u128)b1;
  u64 c0, c1, t;
  o[0] = __builtin_addcl(a1b1, a0b1>>64,  0, &c0);
  o[1] = __builtin_addcl(a2b1, a1b1>>64, c0, &c0);
  o[2] = __builtin_addcl(   0, a2b1>>64, c0, &c0);
  t    = __builtin_addcl(a2b0, a1b0>>64,  0, &c1);
  o[0] = __builtin_addcl(o[0],        t,  0, &c0);
  t    = __builtin_addcl(   0, a2b0>>64, c1, &c1);
  o[1] = __builtin_addcl(o[1],        t, c0, &c0);
  o[2] = __builtin_addcl(o[2],        0, c0, &c0);
}

// right arithmetic bitwise shift of an array
static void __attribute__((noinline)) arsu7(u7x64 o, int n){
  int rk = n&63, lk = 64 - rk, qk = n>>6, k = qk;
  if(__builtin_expect(rk==0,0)){
    do {
      o[0] = o[k++];
      o[1] = o[k++];
      o[2] = o[k++];
      o[3] = o[k++];
      if(k==6) break;
      o[4] = o[k++];
      if(k==6) break;
      o[5] = o[k++];
    } while(0);
  } else {
    do {
      u64 tr = o[k], tl = o[k+1];
      o[0] = tl<<lk|tr>>rk; ++k;
      tr = tl; tl = o[k+1];
      o[1] = tl<<lk|tr>>rk; ++k;
      tr = tl; tl = o[k+1];
      o[2] = tl<<lk|tr>>rk; ++k;
      tr = tl; tl = o[k+1];
      o[3] = tl<<lk|tr>>rk; ++k;
      if(k==6) break;
      tr = tl; tl = o[k+1];
      o[4] = tl<<lk|tr>>rk; ++k;
      if(k==6) break;
      tr = tl; tl = o[k+1];
      o[5] = tl<<lk|tr>>rk; ++k;
    } while(0);
  }
  i64 h = o[6];
  k = 6-qk;
  o[k++] = h>>rk;
  if(k==7) return;
  h>>=63;
  o[k++] = h;
  if(k==7) return;
  o[k++] = h;
}

// right arithmetic bitwise shift of an array
static inline void __attribute__((always_inline)) arsu4(u4x64 o, int n){
  if(__builtin_expect(n<64, 1)){
    int lk = 64-n;
    o[0] = o[1]<<lk|o[0]>>n;
    o[1] = o[2]<<lk|o[1]>>n;
    o[2] = o[3]<<lk|o[2]>>n;
    o[3] = (i64)o[3]>>n;
    return;
  }
  int rk = n&63, lk = 64 - rk, qk = n>>6;
  if(rk==0){
    if(qk==0) return;
    i64 h = o[3];
    h>>=63;
    if(qk==1) {
      o[0] = o[1];
      o[1] = o[2];
      o[2] = o[3];
      o[3] = h;
    }
    if(qk==2) {
      o[0] = o[2];
      o[1] = o[3];
      o[2] = h;
      o[3] = h;
    }
  } else {
    i64 h = o[3];
    if(qk==0) {
      o[0] = o[1]<<lk|o[0]>>rk;
      o[1] = o[2]<<lk|o[1]>>rk;
      o[2] = o[3]<<lk|o[2]>>rk;
      o[3] = h>>rk;
    }
    if(qk==1) {
      o[0] = o[2]<<lk|o[1]>>rk;
      o[1] = o[3]<<lk|o[2]>>rk;
      o[2] = h>>rk;
      o[3] = h>>63;
    }
    if(qk==2) {
      o[0] = o[3]<<lk|o[2]>>rk;
      o[1] = h>>rk;
      o[2] = h>>63;
      o[3] = h>>63;
    }
  }
}

// right arithmetic bitwise shift of an array
static inline void __attribute__((always_inline)) arsu3(u3x64 o, int n){
  if(__builtin_expect(n<64, 1)){
    int lk = 64-n;
    o[0] = o[1]<<lk|o[0]>>n;
    o[1] = o[2]<<lk|o[1]>>n;
    o[2] = (i64)o[2]>>n;
    return;
  }
  int rk = n&63, lk = 64 - rk, qk = n>>6;
  if(rk==0){
    if(qk==0) return;
    i64 h = o[2];
    h>>=63;
    if(qk==1) {
      o[0] = o[1];
      o[1] = o[2];
      o[2] = h;
    }
    if(qk==2) {
      o[0] = o[2];
      o[1] = h;
      o[2] = h;
    }
  } else {
    i64 h = o[2];
    if(qk==0) {
      o[0] = o[1]<<lk|o[0]>>rk;
      o[1] = o[2]<<lk|o[1]>>rk;
      o[2] = h>>rk;
    }
    if(qk==1) {
      o[0] = o[2]<<lk|o[1]>>rk;
      o[1] = h>>rk;
      o[2] = h>>63;
    }
    if(qk==2) {
      o[0] = h>>rk;
      o[1] = h>>63;
      o[2] = h>>63;
    }
  }
}

// o += b
static inline void addu6u6(u6x64 o, const u6x64 b){
  u64 c;
  o[0] = __builtin_addcl(o[0], b[0], 0, &c);
  o[1] = __builtin_addcl(o[1], b[1], c, &c);
  o[2] = __builtin_addcl(o[2], b[2], c, &c);
  o[3] = __builtin_addcl(o[3], b[3], c, &c);
  o[4] = __builtin_addcl(o[4], b[4], c, &c);
  o[5] = __builtin_addcl(o[5], b[5], c, &c);
}

// get appoximate high part of unsigned 192x192 bit multiplication
static void __attribute__((noinline)) mhu3u3u3(u3x64 o, const u3x64 b, const u3x64 a){
  u128 a2b0 = (u128)a[2]*b[0];
  u128 a2b1 = (u128)a[2]*b[1];
  u128 a2b2 = (u128)a[2]*b[2];

  u64 c0, c1, t, o0, o1, o2;
  o0 = __builtin_addcl(a2b1, a2b0>>64,  0, &c0);
  o1 = __builtin_addcl(a2b2, a2b1>>64, c0, &c0);
  o2 = __builtin_addcl(   0, a2b2>>64, c0, &c0);

  u128 a1b1 = (u128)a[1]*b[1];
  u128 a1b2 = (u128)a[1]*b[2];
  t  = __builtin_addcl(a1b2, a1b1>>64,  0, &c0);
  o0 = __builtin_addcl(  o0,        t,  0, &c1);
  t  = __builtin_addcl(   0, a1b2>>64, c0, &c0);
  o1 = __builtin_addcl(  o1,        t, c1, &c1);
  o2 = __builtin_addcl(  o2,        0, c1, &c1);

  u128 a0b2 = (u128)a[0]*b[2];
  o0 = __builtin_addcl(  o0, a0b2>>64,  0, &c1);
  o1 = __builtin_addcl(  o1,        0, c1, &c1);
  o2 = __builtin_addcl(  o2,        0, c1, &c1);

  o[0] = o0;
  o[1] = o1;
  o[2] = o2;
}

// get appoximate high part of unsigned 384x384 bit multiplication
static void __attribute__((noinline)) mhu6u6u6(u6x64 o, const u6x64 b, const u6x64 a){
  u64 c0, c1, t, o0, o1, o2, o3, o4, o5;

  u128 a5b5 = (u128)a[5]*b[5];
  u128 a5b4 = (u128)a[5]*b[4];
  u128 a5b3 = (u128)a[5]*b[3];
  u128 a5b2 = (u128)a[5]*b[2];
  u128 a5b1 = (u128)a[5]*b[1];
  u128 a5b0 = (u128)a[5]*b[0];
  o0 = __builtin_addcl(a5b1, a5b0>>64,  0, &c0);
  o1 = __builtin_addcl(a5b2, a5b1>>64, c0, &c0);
  o2 = __builtin_addcl(a5b3, a5b2>>64, c0, &c0);
  o3 = __builtin_addcl(a5b4, a5b3>>64, c0, &c0);
  o4 = __builtin_addcl(a5b5, a5b4>>64, c0, &c0);
  o5 = __builtin_addcl(   0, a5b5>>64, c0, &c0);

  u128 a4b5 = (u128)a[4]*b[5];
  u128 a4b4 = (u128)a[4]*b[4];
  u128 a4b3 = (u128)a[4]*b[3];
  u128 a4b2 = (u128)a[4]*b[2];
  u128 a4b1 = (u128)a[4]*b[1];
  t  = __builtin_addcl(a4b2, a4b1>>64,  0, &c0);
  o0 = __builtin_addcl(  o0,        t,  0, &c1);
  t  = __builtin_addcl(a4b3, a4b2>>64, c0, &c0);
  o1 = __builtin_addcl(  o1,        t, c1, &c1);
  t  = __builtin_addcl(a4b4, a4b3>>64, c0, &c0);
  o2 = __builtin_addcl(  o2,        t, c1, &c1);
  t  = __builtin_addcl(a4b5, a4b4>>64, c0, &c0);
  o3 = __builtin_addcl(  o3,        t, c1, &c1);
  t  = __builtin_addcl(   0, a4b5>>64, c0, &c0);
  o4 = __builtin_addcl(  o4,        t, c1, &c1);
  o5 = __builtin_addcl(  o5,        0, c1, &c1);

  u128 a3b5 = (u128)a[3]*b[5];
  u128 a3b4 = (u128)a[3]*b[4];
  u128 a3b3 = (u128)a[3]*b[3];
  u128 a3b2 = (u128)a[3]*b[2];
  t  = __builtin_addcl(a3b3, a3b2>>64,  0, &c0);
  o0 = __builtin_addcl(  o0,        t,  0, &c1);
  t  = __builtin_addcl(a3b4, a3b3>>64, c0, &c0);
  o1 = __builtin_addcl(  o1,        t, c1, &c1);
  t  = __builtin_addcl(a3b5, a3b4>>64, c0, &c0);
  o2 = __builtin_addcl(  o2,        t, c1, &c1);
  t  = __builtin_addcl(   0, a3b5>>64, c0, &c0);
  o3 = __builtin_addcl(  o3,        t, c1, &c1);
  o4 = __builtin_addcl(  o4,        0, c1, &c1);
  o5 = __builtin_addcl(  o5,        0, c1, &c1);

  u128 a2b5 = (u128)a[2]*b[5];
  u128 a2b4 = (u128)a[2]*b[4];
  u128 a2b3 = (u128)a[2]*b[3];
  t  = __builtin_addcl(a2b4, a2b3>>64,  0, &c0);
  o0 = __builtin_addcl(  o0,        t,  0, &c1);
  t  = __builtin_addcl(a2b5, a2b4>>64, c0, &c0);
  o1 = __builtin_addcl(  o1,        t, c1, &c1);
  t  = __builtin_addcl(   0, a2b5>>64, c0, &c0);
  o2 = __builtin_addcl(  o2,        t, c1, &c1);
  o3 = __builtin_addcl(  o3,        0, c1, &c1);
  o4 = __builtin_addcl(  o4,        0, c1, &c1);
  o5 = __builtin_addcl(  o5,        0, c1, &c1);

  u128 a1b5 = (u128)a[1]*b[5];
  u128 a1b4 = (u128)a[1]*b[4];
  t  = __builtin_addcl(a1b5, a1b4>>64,  0, &c0);
  o0 = __builtin_addcl(  o0,        t,  0, &c1);
  t  = __builtin_addcl(   0, a1b5>>64, c0, &c0);
  o1 = __builtin_addcl(  o1,        t, c1, &c1);
  o2 = __builtin_addcl(  o2,        0, c1, &c1);
  o3 = __builtin_addcl(  o3,        0, c1, &c1);
  o4 = __builtin_addcl(  o4,        0, c1, &c1);
  o5 = __builtin_addcl(  o5,        0, c1, &c1);

  u128 a0b5 = (u128)a[0]*b[5];
  o[0] = __builtin_addcl(o0, a0b5>>64,  0, &c1);
  o[1] = __builtin_addcl(o1,        0, c1, &c1);
  o[2] = __builtin_addcl(o2,        0, c1, &c1);
  o[3] = __builtin_addcl(o3,        0, c1, &c1);
  o[4] = __builtin_addcl(o4,        0, c1, &c1);
  o[5] = __builtin_addcl(o5,        0, c1, &c1);
}

// o = a*b + c
static inline void __attribute__((always_inline)) mahu1u6u6(u6x64 o, u64 a, const u6x64 b, const u6x64 c){
  u64 c0, c1, t;
  u128 ab0 = (u128)a*b[0];
  u128 ab1 = (u128)a*b[1];
  t    = __builtin_addcl( ab1, ab0>>64,  0, &c0);
  o[0] = __builtin_addcl(c[0],       t,  0, &c1);
  u128 ab2 = (u128)a*b[2];
  t    = __builtin_addcl( ab2, ab1>>64, c0, &c0);
  o[1] = __builtin_addcl(c[1],       t, c1, &c1);
  u128 ab3 = (u128)a*b[3];
  t    = __builtin_addcl( ab3, ab2>>64, c0, &c0);
  o[2] = __builtin_addcl(c[2],       t, c1, &c1);
  u128 ab4 = (u128)a*b[4];
  t    = __builtin_addcl( ab4, ab3>>64, c0, &c0);
  o[3] = __builtin_addcl(c[3],       t, c1, &c1);
  u128 ab5 = (u128)a*b[5];
  t    = __builtin_addcl( ab5, ab4>>64, c0, &c0);
  o[4] = __builtin_addcl(c[4],       t, c1, &c1);
  t    = __builtin_addcl(   0, ab5>>64, c0, &c0);
  o[5] = __builtin_addcl(c[5],       t, c1, &c1);
}

// o = a*b + c
static inline void __attribute__((always_inline)) mahu1u3u3(u3x64 o, u64 a, const u3x64 b, const u3x64 c){
  u64 c0, c1, t;
  u128 ab0 = (u128)a*b[0];
  u128 ab1 = (u128)a*b[1];
  t    = __builtin_addcl( ab1, ab0>>64,  0, &c0);
  o[0] = __builtin_addcl(c[0],       t,  0, &c1);
  u128 ab2 = (u128)a*b[2];
  t    = __builtin_addcl( ab2, ab1>>64, c0, &c0);
  o[1] = __builtin_addcl(c[1],       t, c1, &c1);
  t    = __builtin_addcl(   0, ab2>>64, c0, &c0);
  o[2] = __builtin_addcl(c[2],       t, c1, &c1);
}

// a*b + c
static inline u128 __attribute__((always_inline)) mahuUU(u64 a, u128 b, u128 c){
  c += (u128)a*(u64)b >> 64;
  return a*(b>>64) + c;
}

static void __attribute__((noinline)) pol6(u6x64 f, u64 x, long n, const u6x64 c[]){
  u6x64 a;
  mahu1u6u6(a, x, c[n-1], c[n-2]);
  long i = n - 2;
  do {
    mahu1u6u6(a, x, a, c[--i]);
  } while(i>1);
  mahu1u6u6(f, x, a, c[0]);
}

static inline void pol6red(u6x64 f, u64 x, const u6x64 c[]){
  u6x64 a = {0,0,0,0,0,0}, b;
  b[0] = c[5][5]; b[1] = b[2] = b[3] = b[4] = b[5] = 0;
  mahu1u6u6(a, x, a, b);
  b[0] = c[4][4]; b[1] = c[4][5]; b[2] = b[3] = b[4] = b[5] = 0;
  mahu1u6u6(a, x, a, b);
  b[0] = c[3][3]; b[1] = c[3][4]; b[2] = c[3][5]; b[3] = b[4] = b[5] = 0;
  mahu1u6u6(a, x, a, b);
  b[0] = c[2][2]; b[1] = c[2][3]; b[2] = c[2][4]; b[3] = c[2][5]; b[4] = b[5] = 0;
  mahu1u6u6(a, x, a, b);
  b[0] = c[1][1]; b[1] = c[1][2]; b[2] = c[1][3]; b[3] = c[1][4]; b[4] = c[1][5]; b[5] = 0;
  mahu1u6u6(a, x, a, b);
  mahu1u6u6(f, x, a, c[0]);
}

static inline void pol6redred(u6x64 f, u6x64 x, const u6x64 c[]){
  x[5] = x[3]; x[4] = x[2]; x[3] = x[1]; x[2] = x[0]; x[1] = x[0] = 0;
  mhu6u6u6(f, x, c[2]);
  f[0] = f[2]; f[1] = f[3]; f[2] = f[4]; f[3] = f[5]; f[4] = 0; f[5] = 0;
  addu6u6(f, c[1]);
  mhu6u6u6(f, x, f);
  f[0] = f[2]; f[1] = f[3]; f[2] = f[4]; f[3] = f[5]; f[4] = c[0][4]; f[5] = c[0][5];
}

static void __attribute__((noinline)) pol3(u3x64 f, u64 x, long n, const u3x64 c[]){
  u3x64 a;
  mahu1u3u3(a, x, c[n-1], c[n-2]);
  long i = n - 2;
  do {
    mahu1u3u3(a, x, a, c[--i]);
  } while(i>1);
  mahu1u3u3(f, x, a, c[0]);
}

static inline u128 __attribute__((always_inline)) pol(u64 x, u128 f0, long n, const u128 c[]){
  long i = n;
  u128 f = c[--i] + f0;
  do {
    f = mahuUU(x, f, c[--i]);
  } while(i);
  return f;
}

// reciprocal of ln(2)
static const u7x64 iln2 = {
  0xea90b9e60c4a90a0, 0x24d92f75c16be0b3, 0xde1c43f755176cd6, 0x8b25166cd1a13247,
  0xeb577aa8dd695a58, 0xbe87fed0691d3e88, 0xb8aa3b295c17f0bb};

static void __attribute__((noinline)) as_expq_superaccurate(int *el, u2x64 m, u128 x0){
  static const u64 tbl[][6] = {
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x8000000000000000},
    {0x82dc9bf3421840d1, 0x7835af9ab4e6355c, 0x5d42b362af1ee859, 0x148a0459e7585151, 0xc5c95b8c2154c1b2, 0x85aac367cc487b14},
    {0x9994fac7f4ea654b, 0xb4f28c879a524bd4, 0x91e135ee84a3f733, 0x1aa84ffbebac349f, 0xfbe4628758a53c90, 0x8b95c1e3ea8bd6e6},
    {0x23b504fb5dadbb25, 0x4e0d990c27c43643, 0xf1203caf65bfb9b9, 0x1942b34816fb4f26, 0x0fd6d8e0ae5ac9d8, 0x91c3d373ab11c336},
    {0x4e9f94ee0c90dbbd, 0xbe47c34d380250a8, 0xd78b65cbefa7bb6f, 0x5e139a1b14fa8178, 0x46ad23182e42f6f6, 0x9837f0518db8a96f},
    {0xa264696b6f6e2b1c, 0xcd12e5ada91eef7b, 0x21f977fe7c7fa117, 0x65c15c122133e2a2, 0xa0911f09ebb9fdd1, 0x9ef5326091a111ad},
    {0xad35e8e58c5ce4f4, 0x5343b4a0330a8052, 0x2589c98a8290d3f0, 0x1dd170ace2bcfc17, 0x1cbd7f621710701b, 0xa5fed6a9b15138ea},
    {0x739a3d061fea7592, 0x458fd5f44e26a7a7, 0xb165f141833a67da, 0x6be409407034fded, 0x4980a8c8f59a2ec4, 0xad583eea42a14ac6},
    {0xa8b1fe6fdc83db39, 0x4afc83043ab8a2c3, 0xed17ac8583339915, 0x1d6f60ba893ba84c, 0x597d89b3754abe9f, 0xb504f333f9de6484},
    {0x283c66db56df97f8, 0x9b985f3a0eae1c1d, 0x0d9a4be023ece031, 0x15b34bbcb0298f41, 0xa8811fb66d0faf7a, 0xbd08a39f580c36be},
    {0xefba190ed1a58a51, 0xbb2068be237512df, 0xc7686006e4e6c092, 0x6b0f939998251a36, 0x3e2ad0c964dd9f37, 0xc5672a115506dadd},
    {0xcd8caebc5d894c26, 0x1b8343088bbdadd4, 0x2bbd398af35c079f, 0x6f28610b8c36485a, 0xe235838f95f2c6ed, 0xce248c151f8480e3},
    {0x81247458fb61e576, 0xefb01fda334bca9a, 0xb5c13ada0e778299, 0x1d733af522058b16, 0x39a68bb9902d3fde, 0xd744fccad69d6af4},
    {0xf44e17262da49b5d, 0x188081fe7062f61e, 0x1cb99d3f1ff298a2, 0x224b251b33092002, 0x065895048dd333ca, 0xe0ccdeec2a94e111},
    {0x091482854d819e44, 0xb338fcd2ac2ffbc8, 0x17d8d1e8ca31880a, 0xc4faace043b7f91c, 0xd02d75b3706e54fa, 0xeac0c6e7dd24392e},
    {0x29f075f23730e918, 0xd22dd036f1906094, 0xbdd80329364aa29f, 0x6f510308677709f5, 0x7b9d0c7aed980fc3, 0xf5257d152486cc2c}};
  static const u64 c[][6] = {
    {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x8000000000000000},
    {0x2acaa97da57cadbe, 0xf3dc3b1036f5d64c, 0xc5068badc5d57d15, 0xa079a193394c5b16, 0xe4f1d9cc01f97b57, 0x58b90bfbe8e7bcd5},
    {0xd344071b5ec47714, 0x524eb0376b9686e0, 0xc2be93bbb1396e6e, 0xa3a2751c30ce69d4, 0x6f16b06ec9735fca, 0x1ebfbdff82c58ea8},
    {0x80960837d68b3044, 0x44545f2e4dd67d06, 0x4753198ade236146, 0xa7ae23a226d00887, 0xcce9d8aeccaf4b7b, 0x071ac235c1282fe2},
    {0xeee877628d8f6274, 0x8f7e8887e73829d7, 0x699b709699e1815f, 0x72478ea53e63911d, 0x9ccbbe0b53eeac50, 0x013b2ab6fba4e772},
    {0x318a9f63b2f3ec5c, 0x2f040f926e2c93be, 0xc8cdc36aa406093f, 0x60aed94d2dce32e1, 0x20e2fed34a297d86, 0x002bb0ffcf14ce62},
    {0x2d3c7b9299d0d3e1, 0x91ec7aec4e3f0a35, 0x549592ff6d6ab786, 0xcfb314ffccc47bb0, 0xdbd2c2a261ac8d07, 0x00050c244be1b1e1},
    {0xcd46dc2cd5899528, 0x95ce94549c9a636a, 0x5d3119327fac831d, 0x4ace1152e8810fee, 0x1a1ac547321f639a, 0x00007ff2ff1622c3},
    {0x8531a13788143560, 0x5c5f54178a891b6b, 0x7d5b21cd05968068, 0x2586e1a0f7107ab9, 0x11fec7ff3036d3be, 0x00000b160111d2e4},
    {0xe590c3fdfb446be7, 0x2d5087b376c0214d, 0x738afd2a4917377a, 0x84518cb8caa9ba26, 0x3e1ed253872d27fc, 0x000000da929e9caf},
    {0xcc782de6ff640fd0, 0x68569686f1264ea6, 0x98468b24acd303be, 0xb4ce2a0608a16570, 0xc764fb7ed0eca973, 0x0000000f267a8ac5},
    {0xee22a537a6d9a8b8, 0x08110963d1d9380f, 0x43b147aa9f2c11b5, 0x90a4edc7b3f29c1c, 0x8dd92607abccaf23, 0x00000000f465639a},
    {0x38202f8bf18f1943, 0xbc2fb66e0bf68e76, 0x511f7698b91cba26, 0xd17730e76aaedf16, 0x7e14c2f15ab43f0b, 0x000000000e1deb28},
    {0xea93b5cedf528c2f, 0x6ee667b44f788f66, 0x714aa5175cd8c9ab, 0x7b8d8ce6fe81f087, 0x8b3687cb140d6180, 0x0000000000c0b0c9},
    {0x88ad1fe5bcec581b, 0xa772e0b581376df7, 0x1d1edb9f5248282a, 0x2ae5761242913279, 0x26ac3c54b9f8a1b1, 0x0000000000098a4b},
    {0x9d19faf9f3a16e65, 0xc2fde1c74321a361, 0x3787e55bad70a464, 0xfc6a729280d47c69, 0xa10ec1008799ec55, 0x00000000000070db},
    {0xf708ee5bf7061dee, 0x921cfcdbbccf2eb0, 0x7cd64e11a79215fe, 0x93b26377e3b574bd, 0xa26b9e7e2ce48e3f, 0x00000000000004e3},
    {0x9bb4d4ccb609d71e, 0x6ef9409a4cd3ac24, 0xc560a32b4349d4dd, 0xb1001eff03e83f71, 0x088968384b4faac3, 0x0000000000000033},
    {0xb5c5f81b7e235f48, 0x9c1837383fef6aa4, 0xcf80a6c83ea7dc89, 0x2ed389743c9aa15c, 0xf7176bdb43695d73, 0x0000000000000001},
    {0x4e3f1412be77b88a, 0x75f070df1338e5db, 0xd970f6d684dcca91, 0xe056ab257aa7f274, 0x125a7ecb835c64da, 0x0000000000000000},
    {0x6c8a502410b3a92b, 0x5ae22ff5b3b87c53, 0x5510cef268f5a4f6, 0x27126f802bc39d75, 0x00a2d6625a8289ac, 0x0000000000000000},
    {0xa851c04a8293fece, 0x95e77dec82b8eb58, 0xef60eb192fe67eda, 0xe0aadf36ddf86f4f, 0x00055ff15e0f8271, 0x0000000000000000},
    {0x7e2f1903476d3f72, 0x991510e40164f6ec, 0xb93a9cf471520656, 0x81d8f91aed9d0512, 0x00002b59f5a6e03b, 0x0000000000000000},
    {0xe661b8b0f04bd98d, 0xc0c7162d7c443b27, 0x48eb10aa6d041426, 0xfb5cb2465d33a354, 0x0000014e7515dc98, 0x0000000000000000},
    {0xa2de610b24affa88, 0x36d51a1c2cf018ae, 0xe823660bee34df2b, 0xd5e52102fa4f3d47, 0x00000009a8d57b65, 0x0000000000000000},
    {0x8297d75925cf8a0e, 0xb19c48d3a13188f6, 0x08ec765f339c0710, 0x6a09e41e7a3814f9, 0x00000000448fbf65, 0x0000000000000000},
    {0x11744278158dd70d, 0xd10b922fb4d1b574, 0xdd8263d932a8a20c, 0x99f1cc682af884c5, 0x0000000001d3ebc2, 0x0000000000000000},
    {0x20127ee09bb9f25c, 0x5ed98d7cde9ecace, 0x46da42907892bb39, 0x9af8dbd36a3b0863, 0x00000000000c0334, 0x0000000000000000},
    {0xafd75d37c82b15ca, 0xf0acd37674cf3129, 0xae8a3fb59540ab8d, 0xa3dfeb50d4131639, 0x0000000000004c20, 0x0000000000000000},
    {0xdaaf1913e1cb12f0, 0xe352ea644fb69c62, 0xf3fac0750b414cc5, 0xcf69a29f13de20e8, 0x00000000000001d1, 0x0000000000000000},
    {0x0587a7d1a7ec6c45, 0x05eaca3704dcd2f6, 0x12dcbe8116eada8f, 0xc333445e3155f79b, 0x000000000000000a, 0x0000000000000000},
    {0x183f54470927dbcd, 0x76bc8f5b8e8b7093, 0x8f099fb908474b26, 0x3d9aea5b4d0ebfae, 0x0000000000000000, 0x0000000000000000},
    {0x261c179f4bdffa1d, 0x0909a0681e2103a8, 0x4dbdd766d2d9a092, 0x01559c86508b1539, 0x0000000000000000, 0x0000000000000000},
    {0x3816a7ca0ca85578, 0x6b7fd2696989cdee, 0xd34dacabb2d48a6c, 0x00072ce49e65a3ac, 0x0000000000000000, 0x0000000000000000},
    {0xd4e29d35fe14e115, 0xc30d08011bdafd19, 0xa9a6bf19955b2132, 0x00002572be492f62, 0x0000000000000000, 0x0000000000000000},
    {0xe4df41884be86bb5, 0x0c5772ee960fd5bf, 0x9dbee3b9355d1fb0, 0x000000bdd01d5d84, 0x0000000000000000, 0x0000000000000000},
    {0x80446608d32c4ed3, 0xb4d5892fe7709c19, 0xd3840403fcefe8a9, 0x00000003bc4fb6d4, 0x0000000000000000, 0x0000000000000000}};

  i64 sm = (i64)(x0>>64)>>63;
  u128 t = x0 & ~(u128)0>>16;
  t |= (u128)1<<112;
  u7x64 x; mhu7xu2(x, iln2, t);
  x[0] ^= sm; x[1] ^= sm; x[2] ^= sm; x[3] ^= sm; x[4] ^= sm; x[5] ^= sm; x[6] ^= sm;
  arsu7(x, 0x402e - ((x0 >> 112)&0x7fff));
  *el = x[6];
  int jt = x[5]>>60;
  x[5] &= ~0ull>>4;
  u6x64 f,f1,f2,ft;
  pol6(f, x[5], sizeof(c)/sizeof(c[0]), c);
  pol6red(f1, x[4], c);
  pol6redred(f2, x, c);
  mhu6u6u6(ft, f, f1);
  mhu6u6u6(ft, ft, f2);
  mhu6u6u6(ft, ft, tbl[jt]);
  m[0] = ft[4]>>1|ft[5]<<63;
  m[1] = ft[5]>>1;
}

static void __attribute__((noinline)) as_expq_accurate(int *el, u2x64 m, u128 x0){
  static const u64 tbl0[][3] = {
    {0x0000000000000000, 0x0000000000000000, 0x8000000000000000},
    {0x148a0459e7585151, 0xc5c95b8c2154c1b2, 0x85aac367cc487b14},
    {0x1aa84ffbebac349f, 0xfbe4628758a53c90, 0x8b95c1e3ea8bd6e6},
    {0x1942b34816fb4f26, 0x0fd6d8e0ae5ac9d8, 0x91c3d373ab11c336},
    {0x5e139a1b14fa8178, 0x46ad23182e42f6f6, 0x9837f0518db8a96f},
    {0x65c15c122133e2a2, 0xa0911f09ebb9fdd1, 0x9ef5326091a111ad},
    {0x1dd170ace2bcfc17, 0x1cbd7f621710701b, 0xa5fed6a9b15138ea},
    {0x6be409407034fded, 0x4980a8c8f59a2ec4, 0xad583eea42a14ac6},
    {0x1d6f60ba893ba84c, 0x597d89b3754abe9f, 0xb504f333f9de6484},
    {0x15b34bbcb0298f41, 0xa8811fb66d0faf7a, 0xbd08a39f580c36be},
    {0x6b0f939998251a36, 0x3e2ad0c964dd9f37, 0xc5672a115506dadd},
    {0x6f28610b8c36485a, 0xe235838f95f2c6ed, 0xce248c151f8480e3},
    {0x1d733af522058b16, 0x39a68bb9902d3fde, 0xd744fccad69d6af4},
    {0x224b251b33092002, 0x065895048dd333ca, 0xe0ccdeec2a94e111},
    {0xc4faace043b7f91c, 0xd02d75b3706e54fa, 0xeac0c6e7dd24392e},
    {0x6f510308677709f5, 0x7b9d0c7aed980fc3, 0xf5257d152486cc2c}};
  static const u64 tbl1[][3] = {
    {0x0000000000000000, 0x0000000000000000, 0x8000000000000000},
    {0x2adc0c3f864ba0f5, 0x94d589f608ee4aa2, 0x8058d7d2d5e5f6b0},
    {0x01f60261b05f1202, 0x25335719b6e6fd20, 0x80b1ed4fd999ab6c},
    {0xa9c9ffc2ca67ffde, 0x0cef03ab14a6654f, 0x810b40a1d81406d4},
    {0x9eb851655e2e5c4d, 0x7be56527bd14def4, 0x8164d1f3bc030773},
    {0xd5abd77e8e1d3a02, 0xa047bab784691313, 0x81bea1708dde6055},
    {0x205da5fe02d7b22a, 0x9c7cd106d23f3768, 0x8218af4373fc25eb},
    {0x352354079f8705c1, 0x3793aa0d08c818fb, 0x8272fb97b2a5894c},
    {0x29f1a4afbefa5d7c, 0x3e2a475b46520bff, 0x82cd8698ac2ba1d7},
    {0xff36264c3caa8a43, 0x90950cc78d29f056, 0x83285071e0fc4546},
    {0xe5c5849563af188b, 0xe201d4ec3d93f683, 0x8383594eefb6ee36},
    {0x2af66c991b2a1028, 0x334544586ffe6d47, 0x83dea15b9541b132},
    {0x0d96b414ec4c9d06, 0x1af92eca13fd1582, 0x843a28c3acde4046},
    {0xff8d63ef80157021, 0xf38ffeb805e14189, 0x8495efb3303efd2f},
    {0x17011ed39873fe65, 0x0f03062c26b5ba5d, 0x84f1f656379c1a29},
    {0xa23f7708cf218f12, 0x16c873d1d378c1c9, 0x854e3cd8f9c8c95d}};
  static const u64 c[][3] = {
    {0x0000000000000000, 0x0000000000000000, 0x8000000000000000},
    {0xa079a193394c54e1, 0xe4f1d9cc01f97b57, 0x58b90bfbe8e7bcd5},
    {0xa3a2751c329dec63, 0x6f16b06ec9735fca, 0x1ebfbdff82c58ea8},
    {0xa7ae236cccddaf6f, 0xcce9d8aeccaf4b7b, 0x071ac235c1282fe2},
    {0x724ac5c53418fab2, 0x9ccbbe0b53eeac50, 0x013b2ab6fba4e772},
    {0x42d10a63971b725e, 0x20e2fed34a297d86, 0x002bb0ffcf14ce62},
    {0xd132fe878c97b1ac, 0xdbd2c2a261ac8dbc, 0x00050c244be1b1e1},
    {0xf9ce89ab39b2c8cf, 0x1a1ac547321c73be, 0x00007ff2ff1622c3},
    {0xd0096a8f975ae04e, 0x11fec7ff38d4399b, 0x00000b160111d2e4},
    {0x2965d6ecab7d25ba, 0x3e1ed24165e0982b, 0x000000da929e9caf},
    {0x96be361027c23482, 0xc76516f9cc9face5, 0x0000000f267a8ac5},
    {0xa8358f9d94f711b3, 0x8dbb68c80b739ee8, 0x00000000f465639a},
    {0x4b1c3c1e37a9e553, 0x947ddee7032a7546, 0x000000000e1deb28},
    {0xfb45ff03de0da11f, 0x5fd29dc12646b116, 0x0000000000c0b0be},
    {0xe66d2a5194015941, 0x2dd5a6458bb23f71, 0x0000000000098d9a}};

  i64 sm = (i64)(x0>>64)>>63;
  u128 t = x0 & ~(u128)0>>16;
  t |= (u128)1<<112;
  u4x64 x; mhu4xu2(x, iln2+3, t);
  x[0] ^= sm; x[1] ^= sm; x[2] ^= sm; x[3] ^= sm;
  arsu4(x, 0x402e - ((x0 >> 112)&0x7fff));
  *el = x[3];
  int jt0 = x[2]>>60, jt1 = (x[2]>>56)&15;
  x[2] &= ~0ull>>8;
  u3x64 f,f1,ft;
  mhu3u3u3(ft, tbl0[jt0], tbl1[jt1]);
  pol3(f, x[2], sizeof(c)/sizeof(c[0]), c);
  mhu3u3u3(ft, f, ft);
  u128 c1 = (u128)c[1][2]<<64|c[1][1];
  u128 f2 = mhUU((u128)x[1]<<64|x[0], c1+mhuu(c[2][2],x[1]));
  f1[0] = f2;
  f1[1] = f2>>64;
  f1[2] = c[0][2];
  mhu3u3u3(f,ft,f1);

  m[0] = f[1]>>1|f[2]<<63;
  m[1] = f[2]>>1;
  int rndfail = 0;
  if(__builtin_expect(*el>=-16382, 1)){
    f2 = (u128)f[1]<<64|f[0];
    u128 d = (f2+8)&(~(u128)0>>53);
    rndfail = d<=16;
  } else {
    int s = -16371 - *el;
    u64 k;
    f[0] = __builtin_addcl(f[0],8,0,&k);
    f[1] = __builtin_addcl(f[1],0,k,&k);
    f[2] = __builtin_addcl(f[2],0,k,&k);
    if(s<64){
      f[1] &= (1ul<<s)-1;
      f[2] = 0;
    } else if(s<128){
      f[2] &= (1ul<<(s-64))-1;
    }
    rndfail = (f[0]<=16) && ((f[1] | f[2]) == 0);
  }
  if(rndfail)
    return as_expq_superaccurate(el, m, x0);
}

__float128 cr_expq(__float128 x) {
  static const u64 r0[][2] = {
    {                 0, 0x8000000000000000}, {0x3e2a475b46520bff, 0x82cd8698ac2ba1d7},
    {0xc5c95b8c2154c1b2, 0x85aac367cc487b14}, {0x5df8d76c98c67563, 0x88980e8092da8527},
    {0xfbe4628758a53c90, 0x8b95c1e3ea8bd6e6}, {0x2dc0144c8783d4c6, 0x8ea4398b45cd53c0},
    {0x0fd6d8e0ae5ac9d8, 0x91c3d373ab11c336}, {0x2e8afad12551de54, 0x94f4efa8fef70961},
    {0x46ad23182e42f6f6, 0x9837f0518db8a96f}, {0xa2a817a2a3cc3f1f, 0x9b8d39b9d54e5538},
    {0xa0911f09ebb9fdd1, 0x9ef5326091a111ad}, {0x9b7a04ef80cfdea8, 0xa27043030c496818},
    {0x1cbd7f621710701b, 0xa5fed6a9b15138ea}, {0x541e24ec3531fa73, 0xa9a15ab4ea7c0ef8},
    {0x4980a8c8f59a2ec4, 0xad583eea42a14ac6}, {0x87d037e96d215d8e, 0xb123f581d2ac258f},
    {0x597d89b3754abe9f, 0xb504f333f9de6484}, {0x1b879778566b65a2, 0xb8fbaf4762fb9ee9},
    {0xa8811fb66d0faf7a, 0xbd08a39f580c36be}, {0x7c457d59a50087b5, 0xc12c4cca66709456},
    {0x3e2ad0c964dd9f37, 0xc5672a115506dadd}, {0x80e1f92a0511697e, 0xc9b9bd866e2f27a2},
    {0xe235838f95f2c6ed, 0xce248c151f8480e3}, {0x12248e57c3de4028, 0xd2a81d91f12ae45a},
    {0x39a68bb9902d3fde, 0xd744fccad69d6af4}, {0x3d840d5a9e29aa64, 0xdbfbb797daf23755},
    {0x065895048dd333ca, 0xe0ccdeec2a94e111}, {0x1e5e8f4a4edbb0ed, 0xe5b906e77c8348a8},
    {0xd02d75b3706e54fb, 0xeac0c6e7dd24392e}, {0x46561cf6948db913, 0xefe4b99bdcdaf5cb},
    {0x7b9d0c7aed980fc3, 0xf5257d152486cc2c}, {0x7c25bb14315d7fcd, 0xfa83b2db722a033a},
  };
  static const u64 r1[][2] = {
    {                 0, 0x8000000000000000}, {0x3690dfe44d11d008, 0x8016302f17467628},
    {0xff8ce94a6797b3ce, 0x802c6436d0e04f50}, {0x49fc841afba9c3c6, 0x80429c17d77c18ed},
    {0x94d589f608ee4aa2, 0x8058d7d2d5e5f6b0}, {0xe54ec5f966eb1872, 0x806f17687707a7af},
    {0xa0cc0a49c10ea66b, 0x80855ad965e88b83}, {0x4a8a4f44bb703db6, 0x809ba2264dada76a},
    {0x25335719b6e6fd20, 0x80b1ed4fd999ab6c}, {0xb880575ea03548c1, 0x80c83c56b50cf77f},
    {0x3b13310f5ad57fb1, 0x80de8f3b8b85a0af}, {0xe0adc640acaa6b0b, 0x80f4e5ff089f763e},
    {0x0cef03ab14a66550, 0x810b40a1d81406d4}, {0x6abd3b0eab9c7048, 0x81219f24a5baa59d},
    {0xe885724f14131287, 0x813801881d886f7b}, {0x99775205944eadc4, 0x814e67cceb90502c},
    {0x7be56527bd14def5, 0x8164d1f3bc030773}, {0x24f1624278193c37, 0x817b3ffd3b2f2e47},
    {0x51ac3dac02ca5008, 0x8191b1ea15813bfd}, {0x5dd1caf33588f2d3, 0x81a827baf7838b78},
    {0xa047bab784691314, 0x81bea1708dde6055}, {0xad87c8fb65a6993c, 0x81d51f0b8557ec1c},
    {0x801cf6ea3b3068f3, 0x81eba08c8ad4536f}, {0x875bb1f380439fee, 0x820225f44b55b33b},
    {0x9c7cd106d23f3768, 0x8218af4373fc25eb}, {0xde4357a774d13d5c, 0x822f3c7ab205c89a},
    {0x7354f57a2d982491, 0x8245cd9ab2cec048}, {0x336d3fddc28165ad, 0x825c62a423d13f0c},
    {0x3793aa0d08c818fb, 0x8272fb97b2a5894c}, {0x517c473948af9a0c, 0x828998760d01faf3},
    {0x6a3b68fcc424ff9f, 0x82a0393fe0bb0ca8}, {0xc87433776c8b975c, 0x82b6ddf5dbc35906},
  };
  static const u64 r2[][2] = {
    {                 0, 0x8000000000000000}, {0xaa22beacca949013, 0x8000b17292f702a3},
    {0xe84c2e1a463473da, 0x800162e61bed4a48}, {0xe9b3d4c106428682, 0x8002145a9ae42bf6},
    {0xb6566a58c048be1f, 0x8002c5d00fdcfcb6}, {0x2ef8674028829792, 0x800377467ad91193},
    {0x0d2893e85affca64, 0x800428bddbd9bf99}, {0xe3429843d1643041, 0x8004da3632e05bd6},
    {0x1c718b38e549cb93, 0x80058baf7fee3b5d}, {0xfcb28217df49d908, 0x80063d29c304b33d},
    {0xa0d7201492b1d78a, 0x8006eea4fc25188d}, {0xfe8825c385e97278, 0x8007a0212b50c061},
    {0xe448009aa78e39cd, 0x8008519e5088ffd2}, {0xf9755a75904a13f7, 0x8009031c6bcf2bf9},
    {0xbe4da91d51695528, 0x8009b49b7d2499f2}, {0x8befbdd3d03567f0, 0x800a661b848a9eda},
    {0x945e54e2ae18f2f0, 0x800b179c82028fd0}, {0xe282a52dbd92678a, 0x800bc91e758dc1f5},
    {0x5a2eefc903f9e56b, 0x800c7aa15f2d8a6d}, {0xb8210f92481f5ed7, 0x800d2c253ee33e5b},
    {0x920508ce2dc5e9b3, 0x800dddaa14b032e7}, {0x567798c8de012934, 0x800e8f2fe095bd39},
    {0x4d08c57a3c79bc3e, 0x800f40b6a295327b}, {0x963e6d2da99d9c76, 0x800ff23e5aafe7d9},
    {0x2b96d62d51c15a07, 0x8010a3c708e73282}, {0xdf8b3e7109372044, 0x80115550ad3c67a4},
    {0x5d926b50b5606f22, 0x801206db47b0dc73}, {0x2a23393a42bf75ce, 0x8012b866d845e621},
    {0xa2b72b6b280cfa61, 0x801369f35efcd9e3}, {0xfdccfbad7657bafd, 0x80141b80dbd70cf1},
    {0x4aeb2a187632347d, 0x8014cd0f4ed5d485}, {0x72a28cd4d1f3bae9, 0x80157e9eb7fa85d8},
  };
  static const u64 r3[][2] = {
    {                 0, 0x8000000000000000}, {0xecfc487503488bb2, 0x8000058b90de7e4c},
    {0x8307016c1cd4e8b7, 0x80000b1721fa7c18}, {0x6c292b5fbf0c0ab5, 0x800010a2b353f965},
    {0x526be456600bdbe5, 0x8000162e44eaf636}, {0xdfd867e27af0ecb1, 0x80001bb9d6bf728d},
    {0xbe780f22911e236a, 0x8000214568d16e6e}, {0x985450c12b846c01, 0x800026d0fb20e9db},
    {0x1776c0f4dbea67d6, 0x80002c5c8dade4d7}, {0xe5e911803e341d94, 0x800031e820785f63},
    {0xadb511b1f9aaa919, 0x80003773b3805984}, {0x18e4ae64c243eb6d, 0x80003cff46c5d33c},
    {0xd181f1ff59ea3ac5, 0x8000428ada48cc8c}, {0x8197047491c4129c, 0x800048166e094579},
    {0xd32e2b434b7bc3d3, 0x80004da202073e04}, {0x7051c9767a8724db, 0x8000532d9642b631},
    {0x030c5fa5256f41fe, 0x800058b92abbae02}, {0x35688bf267180da2, 0x80005e44bf722579},
    {0xb1710a0d700810a8, 0x800063d054661c99}, {0x2130b33187b01ad5, 0x8000695be9979366},
    {0x2eb27e260db2f346, 0x80006ee77f0689e1}, {0x84017f3e7b2d08fa, 0x8000747314b3000d},
    {0xcb28e85a63fc235f, 0x800079feaa9cf5ed}, {0xae3408e5780712fb, 0x80007f8a40c46b84},
    {0xd72e4dd784856215, 0x80008515d72960d4}, {0xf02341b475470578, 0x80008aa16dcbd5e0},
    {0xa31e8c8c55fc0d3b, 0x8000902d04abcaab}, {0x9a2bf3fb537c55a0, 0x800095b89bc93f37},
    {0x7f575b29bd0f37f7, 0x80009b4433243387}, {0xfcacc2cc05b33b9c, 0x8000a0cfcabca79d},
    {0xbc384922c565c6f3, 0x8000a65b62929b7d}, {0x680629faba6ad083, 0x8000abe6faa60f29},
  };
  static const u64 c[][2] = {
    {0xffffffffffffffff, 0x7fffffffffffffff},
    {0x7bcd5e4f1d9cc01f, 0x0000058b90bfbe8e},
    {0xff82c58ea86f16b0, 0x00000000001ebfbd},
    {0x71ac235c1282fe2c, 0x0000000000000000},
    {0x0000013b2ab6fba4, 0x0000000000000000},
    {0x000000000002bb10, 0x0000000000000000}
  };

  unsigned flagp = _mm_getcsr(), oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  b128u128_u u = {.a = reinterpret_f128_as_u128(x)};
  u64 b1 = u.b[1]&~0ull>>1; // strip the sign
  if(__builtin_expect(b1<((16383ull-114)<<48), 0)){ // x is small
    static const __float128 sa[] = {0x1.ffffffffffffffffffffffffffffp-1q, 1.0q, 0x1.0000000000000000000000000001p+0q};
    if(!(u.b[1]<<1|u.b[0])) return sa[1]; // exact result
    flagp |= FE_INEXACT;
    if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
    return sa[1 + (rm == _MM_ROUND_UP) - ((u.b[1]>>63)&(rm != _MM_ROUND_NEAREST))];
  }
  if(__builtin_expect(b1>=0x400c62e42fefa39eull, 0)){// other special cases: nan, inf, overflow, underflow
    if(b1==0x7fffull<<48&&u.b[0]==0){
      if(!(u.b[1]>>63))
	return x; // x = +Inf
      else
	return 0.0q; // x = -Inf
    }
    if(b1>0x7fffull<<48 || (b1==0x7fffull<<48 && u.b[0])){
      if(!(b1&(1ull<<47))) flagp |= FE_INVALID; // complain about the snan argument by the invalid exception
      u.b[1] |= 1ull<<47; // snan -> qnan
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      return reinterpret_u128_as_f128(u.a); // qNaN
    }
    b128u128_u xmin = {.f = -0x1.654bb3b2c73ebb059fabb506ff34p+13q}, xmax = {.f = 0x1.62e42fefa39ef35793c7673007e6p+13q};
    if(!(u.b[1]>>63) && u.a >= xmax.a){
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      b128u128_u kinf = {.b = {0,0x7fffull<<48}};
      kinf.a -= rm != _MM_ROUND_UP && rm != _MM_ROUND_NEAREST;
      flagp |= FE_OVERFLOW|FE_INEXACT;
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      return kinf.f;
    } else if(u.a >= xmin.a){
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      flagp |= FE_UNDERFLOW|FE_INEXACT;
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      b128u128_u kinf = {.a = rm == _MM_ROUND_UP};
      return kinf.f;
    }
  }
  b128u128_u gf = {.f = x}, m = gf, res;
  i64 sm = gf.bs[1]>>63;
  m.b[1] = (m.b[1]&~0ull>>16)|1ull<<48;
  u3x64 fs; mhu3xu2(fs, iln2+4, m.a);
  fs[0] ^= sm; fs[1] ^= sm; fs[2] ^= sm;
  arsu3(fs, 0x401a - ((gf.b[1] >> 48)&0x7fff));
  i64 fs2 = fs[2];
  int el = fs2>>20, i0 = (fs2>>15)&31, i1 = (fs2>>10)&31, i2 = (fs2>>5)&31, i3 = fs2&31;
  u64 z = fs[1];
  res.a = pol(z, mhuu(z, c[3][0] + mhuu(z, c[4][0] + mhuu(z, c[5][0]))), 3, (u128*)c);
  b128u128_u t0 = {.b = {r0[i0][0], r0[i0][1]}};
  b128u128_u t1 = {.b = {r1[i1][0], r1[i1][1]}};
  b128u128_u t2 = {.b = {r2[i2][0], r2[i2][1]}};
  b128u128_u t3 = {.b = {r3[i3][0], r3[i3][1]}};
  m.a = mhUU(mhUU(t0.a, t1.a),mhUU(t2.a, t3.a));
  u64 k = (u128)0xb17217f7d1cf79ac*fs[0]>>64;
  m.a += m.b[1]*(u128)k>>84;
  res.a = mhUU(res.a, m.a);
  u64 rnd;
  if(__builtin_expect(el>=-16382, 1)){
    u64 s = (rm==_MM_ROUND_NEAREST)<<10;
    if(__builtin_expect(((res.b[0]+s+6)&0x7ff) <= 6, 0))as_expq_accurate(&el, res.b, gf.a);
    rnd = (res.b[0]>>10)&1;
    res.a >>= 11;
    el += 16382;
  } else {
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    flagp |= FE_UNDERFLOW;
    if(el>-16499){
      u128 s = (u128)(rm==_MM_ROUND_NEAREST)<<(-16372-el);
      if(__builtin_expect(((res.a+s+6)&(((u128)2<<(-16372-el))-1)) <= 6, 0)) as_expq_accurate(&el, res.b, gf.a);
      rnd = (res.a>>(-16372-el))&1;
      res.a >>= -16371-el;
    } else {
      rnd = 0;
      res.a = 0;
    }
    el = 0;
  }
  if(__builtin_expect(rm != _MM_ROUND_NEAREST, 0)){
    rnd = rm==_MM_ROUND_UP;
  }
  b128u128_u dres = {.b = {rnd, (u64)el<<48}};
  res.a += dres.a;

  flagp |= FE_INEXACT;
  if(__builtin_expect(oflagp != flagp, 0)) _mm_setcsr(flagp);
  return reinterpret_u128_as_f128(res.a); // put into xmm register
}

// somewhat we need to include that for icx and the Intel math library
extern __float128 __expq (__float128);

// expq is called expf128 in GNU libc, and __expq in the Intel math library
__float128 expq(__float128 x) {
#ifdef __INTEL_CLANG_COMPILER
  return __expq (x);
#else
  return expf128 (x);
#endif
}
