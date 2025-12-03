/* Correctly-rounded natural logarithm function for the IEEE-754 binary128 format

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

#ifdef CORE_MATH_SUPPORT_ERRNO
#include <errno.h>
#endif
#include <fenv.h> // for FE_INEXACT, FE_INVALID, FE_DIVBYZERO
#include <stdint.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef uint64_t u64;
typedef int64_t i64;
typedef uint64_t u2x64[2];
typedef uint64_t u3x64[3];
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

static inline u128 __attribute__((always_inline)) mUUp(u128 *t, u128 _a, u128 _b){
  b128u128_u a, b, a1b0, a0b1, a1b1, a0b0;
  a.a = _a;
  b.a = _b;
  a1b0.a = (u128)a.b[1]*b.b[0];
  a0b1.a = (u128)a.b[0]*b.b[1];
  a1b1.a = (u128)a.b[1]*b.b[1];
  a0b0.a = (u128)a.b[0]*b.b[0];
  unsigned long c0;
  a0b0.b[1] = __builtin_addcl(a0b0.b[1], a1b0.b[0], 0, &c0);
  a1b1.b[0] = __builtin_addcl(a1b1.b[0], a1b0.b[1], c0, &c0);
  a1b1.b[1] = __builtin_addcl(a1b1.b[1], 0, c0, &c0);
  a0b0.b[1] = __builtin_addcl(a0b0.b[1], a0b1.b[0], 0, &c0);
  a1b1.b[0] = __builtin_addcl(a1b1.b[0], a0b1.b[1], c0, &c0);
  a1b1.b[1] = __builtin_addcl(a1b1.b[1], 0, c0, &c0);
  *t = a0b0.a;
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


// right arithmetic bitwise shift of an array
static void __attribute__((noinline)) arsu7(u7x64 o, int n){
  int rk = n&63, lk = -rk&63, qk = n>>6, k = qk;
  if(__builtin_expect(rk==0, 0)){
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

static u64 __attribute__((noinline)) as_logq_refine(i64 el, u2x64 m, __float128 x0){
  // reciprocal of ln(2)
  static const u7x64 iln2 = {
    0xea90b9e60c4a90a0, 0x24d92f75c16be0b3, 0xde1c43f755176cd6, 0x8b25166cd1a13247,
    0xeb577aa8dd695a58, 0xbe87fed0691d3e88, 0xb8aa3b295c17f0bb};
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

  b128u128_u u = {.a = reinterpret_f128_as_u128(x0)};
  i64 sm = -((el>>15)&1);
  u128 t = (u128)m[1]<<64|m[0];
  u7x64 x; mhu7xu2(x, iln2, t);
  x[0] ^= sm; x[1] ^= sm; x[2] ^= sm; x[3] ^= sm; x[4] ^= sm; x[5] ^= sm; x[6] ^= sm;
  arsu7(x, 0x402e - (el&0x7fff));

  int jt = x[5]>>60;
  x[5] &= ~0ull>>4;
  u6x64 f,f1,f2,ft;
  pol6(f, x[5], sizeof(c)/sizeof(c[0]), c);
  pol6red(f1, x[4], c);
  pol6redred(f2, x, c);
  mhu6u6u6(ft, f, f1);
  mhu6u6u6(ft, ft, f2);
  mhu6u6u6(ft, ft, tbl[jt]);

  ft[4] |= !!(ft[0]|ft[1]|ft[2]|ft[3]);

  i64 d = (ft[4] - (u.b[0]<<12));
  if(d>=0)
    d = 1;
  else
    d = -1;
  if(sm) d = -d;
  u128 M = (u128)m[1]<<64|m[0];
  M = (M << 1) - d;
  m[0] = M>>2;
  m[1] = M>>66;
  return (M>>1)&1;
}

static u64 as_log2(u64 x){
  static const unsigned c[][4] = {
    {0xb8aa3af4, 0xb8a9cf24, 0xf5ec11e6, 0x56cde26},
    {0xb311ad8d, 0xada42c83, 0xe04081e5, 0x4ce4aa7},
    {0xadcd64b4, 0xa393d29c, 0xcd0df3b5, 0x445b73b},
    {0xa8d62754, 0x9a5d2082, 0xbbfca4ed, 0x3cf93b1},
    {0xa42589ce, 0x91e83e37, 0xacc3070b, 0x368f7a9},
    {0x9fb5d233, 0x8a208126, 0x9f23232c, 0x30f8032},
    {0x9b81e0e3, 0x82f3ed8d, 0x92e88678, 0x2c13522},
    {0x97851cc6, 0x7c52ce34, 0x87e698b1, 0x27c744d},
    {0x93bb6276, 0x762f5e29, 0x7df7458b, 0x23fe121},
    {0x9020f5eb, 0x707d8107, 0x74f9e730, 0x20a57bf},
    {0x8cb2762a, 0x6b32870b, 0x6cd26447, 0x1dae2aa},
    {0x896cd2ad, 0x6644fad1, 0x656876ff, 0x1b0b28c},
    {0x864d4241, 0x61ac76ef, 0x5ea714e9, 0x18b1793},
    {0x83513b19, 0x5d618220, 0x587bf145, 0x1697c1a},
    {0x80766be7, 0x595d70c9, 0x52d714a2, 0x14b6048},
    {0x7dbab5de, 0x559a4b07, 0x4daa85e3, 0x1305684},
    {0x7b1c276a, 0x5212b66c, 0x48ea016f, 0x118008b},
    {0x7898f797, 0x4ec1e2f3, 0x448abc05, 0x1020d05},
    {0x762f8200, 0x4ba37a8a, 0x40832f23, 0xee3590},
    {0x73de4338, 0x48b392e0, 0x3ccaed5b, 0xdc3d0f},
    {0x71a3d59e, 0x45eea114, 0x395a7d42, 0xcbee53},
    {0x6f7eee92, 0x43516f02, 0x362b39d1, 0xbd1af0},
    {0x6d6e5bef, 0x40d911ef, 0x3337376a, 0xaf9a47},
    {0x6b7101d3, 0x3e82e265, 0x30792cad, 0xa348b4},
    {0x6985d8a7, 0x3c4c750a, 0x2dec5e91, 0x9806e0},
    {0x67abeb4f, 0x3a33945d, 0x2b8c8f3c, 0x8db92c},
    {0x65e25598, 0x38363b33, 0x2955ef28, 0x844732},
    {0x642842ca, 0x36528fd2, 0x2745104e, 0x7b9b57},
    {0x627cec58, 0x3486dfa6, 0x2556daef, 0x73a270},
    {0x60df98bb, 0x32d19b70, 0x238883e0, 0x6c4b75},
    {0x5f4f9a66, 0x313153de, 0x21d78407, 0x658739},
    {0x5dcc4ece, 0x2fa4b68c, 0x204190e7, 0x5f4832}
  };
  static const u64 c0[] = {
    0x00000000111843d8, 0x0b5d69bad62fa11a, 0x1663f6fad5c18924, 0x2118b119bff1fa3b,
    0x2b803474013e4469, 0x359ebc5b7234baed, 0x3f782d720c23d39b, 0x49101eac3e8ee930,
    0x5269e12f3a1e46c3, 0x5b888736793c6255, 0x646eea2480d45e3c, 0x6d1fafdce6051f08,
    0x759d4f80cf356a9b, 0x7dea15a32f48cb06, 0x86082806b4aef51c, 0x8df988f4b11089fe,
    0x95c01a39fe25b941, 0x9d5d9fd503210d19, 0xa4d3c25e6abf605b, 0xac241134c69f89b6,
    0xb35004723dd423a6, 0xba58feb271a49370, 0xc1404eadf4cd88f9, 0xc80730b00143ad7b,
    0xceaecfea8199248c, 0xd53847ac01a300ff, 0xdba4a47aaa7e5e5b, 0xe1f4e5170dd764e5,
    0xe829fb6931086c4e, 0xee44cd5a005fb44d, 0xf446359b13f9edef, 0xfa2f045e78cc51cc
  };
  int j = (x>>43)&31;
  unsigned z = x>>11, z2 = (u64)z*z>>32;
  unsigned t0 = c[j][0] - ((u64)z*c[j][1]>>38);
  unsigned t2 = c[j][2] - ((u64)z*c[j][3]>>32);
  t0 += (u64)z2*t2>>44;
  u64 r = c0[j] + ((u64)z*t0>>4);
  return r;
}

static inline void __attribute__((always_inline)) add3(u3x64 a, u3x64 b, const u3x64 c){
  u64 k;
  a[0] = __builtin_addcl(b[0],c[0],0,&k);
  a[1] = __builtin_addcl(b[1],c[1],k,&k);
  a[2] = __builtin_addcl(b[2],c[2],k,&k);
}

static inline void __attribute__((always_inline)) sub3(u3x64 a, u3x64 b, const u3x64 c){
  u64 k;
  a[0] = __builtin_subcl(b[0],c[0],0,&k);
  a[1] = __builtin_subcl(b[1],c[1],k,&k);
  a[2] = __builtin_subcl(b[2],c[2],k,&k);
}

static inline void rlshft(u3x64 t, int s){
  int rs = s&63;
  if(__builtin_expect(rs, 1)){
    int ls = -s&63;
    t[0] = t[0]>>rs|t[1]<<ls;
    t[1] = t[1]>>rs|t[2]<<ls;
    t[2] = t[2]>>rs;
  }
  while(__builtin_expect(s>=64, 0)){
    t[0] = t[1];
    t[1] = t[2];
    t[2] = 0;
    s -= 64;
  }
}

static __float128 as_logq_nearone(b128u128_u x, unsigned flagp){
  static const b128u128_u cp[] = {
    {.b = {0xfffffffffffffffful, 0x7ffffffffffffffful}},
    {.b = {0x5555555555555555ul, 0x0000055555555555ul}},
    {.b = {0xfffffffffffffffdul, 0x00000000003ffffful}},
    {.b = {0x3333333333333326ul, 0x0000000000000003ul}},
    {.b = {0x00002aaaaaaaaa84ul, 0x0000000000000000ul}},
    {.b = {0x000000000249245aul, 0x0000000000000000ul}}
  };
  static const b128u128_u cn[] = {
    {.b = {0x0000000000000000ul, 0x8000000000000000ul}},
    {.b = {0xaaaaaaaaaaaaaaaaul, 0x000002aaaaaaaaaaul}},
    {.b = {0xfffffffffffffffful, 0x00000000000ffffful}},
    {.b = {0x6666666666666668ul, 0x0000000000000000ul}},
    {.b = {0x000002aaaaaaaaa8ul, 0x0000000000000000ul}},
    {.b = {0x0000000000124926ul, 0x0000000000000000ul}}
  };
  unsigned oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  u64 tr = rm == _MM_ROUND_NEAREST, crnd = 0;
  i64 e, neg;
  b128u128_u u = x, res, one = {.b = {0, 0x3ffful<<48}};
  if(u.b[1]>=one.b[1]){ // x>=1
    neg = 0;
    u.b[1] -= one.b[1];
    int nz;
    if(__builtin_expect(u.b[1],1)){
      nz = __builtin_clzll(u.b[1]);
    } else if(u.b[0]){
      nz = __builtin_clzll(u.b[0])+64;
    } else {
      return 0.0q;
    }
    u.a <<= nz;
    e = nz - 16;
    u128 u2 = mhUU(u.a,u.a);
    b128u128_u m = u;
    m.a >>= e-20;
    int i = 3;
    u128 f = (u128)cp[3].b[1]<<64|(cp[3].b[0] - mhuu(m.b[1], cp[4].b[0] - mhuu(m.b[1], cp[5].b[0])));
    while(--i>=0) f = cp[i].a - mhUU(m.a, f);
    m.a = mhUU(u2, f);
    u3x64 z = {0, u.b[0], u.b[1]}, t = {0, m.b[0], m.b[1]};
    rlshft(t, e);
    sub3(z,z,t);
    u64 eps = 12;
    u128 tl = (u128)z[1]<<64|z[0], msk = -1, nrnd = (u128)tr<<(13+(z[2]>>63));
    msk >>= 50-(z[2]>>63);
    if(e<64){
      tl >>= 64-e;
      msk >>= 64-e;
      nrnd = nrnd<<e|eps;
    } else {
      eps = 1 + (eps >> (e-64));
      nrnd = nrnd<<64|eps;
    }
    tl = msk & (tl + nrnd);
    crnd = tl <= 2*eps;
    res.b[1] = z[2];
    res.b[0] = z[1];
  } else { // x<1
    neg = 1;
    u.a = one.a - u.a;
    int nz;
    if(__builtin_expect(u.b[1],1)){
      nz = __builtin_clzll(u.b[1]);
    } else {
      nz = __builtin_clzll(u.b[0]) + 64;
    }
    u.a <<= nz;
    e = nz - 16;
    u128 u2 = mhUU(u.a,u.a);
    b128u128_u m = u;
    m.a >>= e-20;
    int i = 2;
    u128 f = cn[2].a + mhuu(m.b[1], cn[3].b[0] + mhuu(m.b[1], cn[4].b[0] + mhuu(m.b[1], cn[5].b[0])));
    while(--i>=0) f = cn[i].a + mhUU(m.a, f);
    m.a = mhUU(u2, f);
    u.a >>= 1;
    u3x64 z = {0, u.b[0], u.b[1]}, t = {0, m.b[0], m.b[1]};
    rlshft(t, e+2);
    add3(z,z,t);
    u64 eps = 12;
    u128 tl = (u128)z[1]<<64|z[0], msk = -1, nrnd = (u128)tr<<(13+(z[2]>>63));
    msk >>= 50-(z[2]>>63);
    if(e<=62){
      tl >>= 62-e;
      msk >>= 62-e;
      nrnd = nrnd<<e|eps;
    } else {
      eps = 1 + (eps >> (e-62));
      nrnd = nrnd<<62|eps;
    }
    tl = msk & (tl + nrnd);
    crnd = tl <= 2*eps;

    res.b[1] = z[2];
    res.b[0] = z[1];
  }
  if((res.b[1]>>63) == 0){
    res.a <<= 1;
    e++;
  }
  u64 rnd = (res.b[0]>>14)&1;
  e = 16381-e;
  if(__builtin_expect(crnd, 0)){
    res.a += 1ul<<13;
    res.a >>= 14;
    rnd = as_logq_refine(e|neg<<15, res.b, x.f);
  } else
    res.a >>= 15;
  if(__builtin_expect(!tr, 0)){
    rnd = (rm==_MM_ROUND_UP)*!neg + (rm==_MM_ROUND_DOWN)*!!neg;
  }
  b128u128_u dres = {.b = {rnd, e<<48|neg<<63}};
  res.a += dres.a;

  flagp |= FE_INEXACT;
  if(__builtin_expect(oflagp != flagp, 0)) _mm_setcsr(flagp);
  return reinterpret_u128_as_f128(res.a); // put into xmm register
}

__float128 cr_logq(__float128 x) {
  static const u3x64
    ln2a = {0x3f2f6af40f343267,0x1cf79abc9e3b3980,0xb17217f7d},
    offa = {0x198bfb39c605bc5,0x718289f4c0a895f2,0xfffffffd3568989a};
  static const unsigned rt0[32] = {
    0x80000000, 0x7d41d96e, 0x7a92be8b, 0x77f25cce, 0x75606374, 0x72dc8374, 0x70666f77, 0x6dfddbcc,
    0x6ba27e66, 0x69540ec9, 0x6712460b, 0x64dcdec4, 0x62b39509, 0x60962666, 0x5e8451d0, 0x5c7dd7a4,
    0x5a82799a, 0x5891fac1, 0x56ac1f76, 0x54d0ad5b, 0x52ff6b55, 0x51382182, 0x4f7a9931, 0x4dc69cdd,
    0x4c1bf829, 0x4a7a77d5, 0x48e1e9ba, 0x47521cc6, 0x45cae0f2, 0x444c0741, 0x42d561b4, 0x4166c34d};
  static const unsigned rt1[32] = {
    0x80000000, 0x7fe9d3a9, 0x7fd3ab2a, 0x7fbd8680, 0x7fa765ad, 0x7f9148af, 0x7f7b2f86, 0x7f651a31,
    0x7f4f08af, 0x7f38faff, 0x7f22f122, 0x7f0ceb16, 0x7ef6e8db, 0x7ee0ea6f, 0x7ecaefd4, 0x7eb4f906,
    0x7e9f0607, 0x7e8916d5, 0x7e732b70, 0x7e5d43d7, 0x7e476009, 0x7e318006, 0x7e1ba3cd, 0x7e05cb5e,
    0x7deff6b7, 0x7dda25d8, 0x7dc458c1, 0x7dae8f71, 0x7d98c9e7, 0x7d830822, 0x7d6d4a22, 0x7d578fe6};
  static const unsigned rt2[32] = {
    0x80000000, 0x7fff4e8f, 0x7ffe9d1e, 0x7ffdebaf, 0x7ffd3a40, 0x7ffc88d2, 0x7ffbd765, 0x7ffb25f9,
    0x7ffa748e, 0x7ff9c325, 0x7ff911bc, 0x7ff86054, 0x7ff7aeed, 0x7ff6fd86, 0x7ff64c21, 0x7ff59abd,
    0x7ff4e95a, 0x7ff437f8, 0x7ff38696, 0x7ff2d536, 0x7ff223d7, 0x7ff17278, 0x7ff0c11b, 0x7ff00fbe,
    0x7fef5e63, 0x7feead08, 0x7fedfbaf, 0x7fed4a56, 0x7fec98fe, 0x7febe7a8, 0x7feb3652, 0x7fea84fd};
  static const unsigned rt3[32] = {
    0x80000000, 0x7ffffa75, 0x7ffff4e9, 0x7fffef5e, 0x7fffe9d2, 0x7fffe447, 0x7fffdebb, 0x7fffd930,
    0x7fffd3a4, 0x7fffce18, 0x7fffc88d, 0x7fffc301, 0x7fffbd76, 0x7fffb7ea, 0x7fffb25f, 0x7fffacd3,
    0x7fffa748, 0x7fffa1bc, 0x7fff9c30, 0x7fff96a5, 0x7fff9119, 0x7fff8b8e, 0x7fff8602, 0x7fff8077,
    0x7fff7aeb, 0x7fff7560, 0x7fff6fd4, 0x7fff6a49, 0x7fff64bd, 0x7fff5f31, 0x7fff59a6, 0x7fff541a};
  static const u3x64 lt0a[32] = {
    {0,0,0}, {0xa89586efcf459616,0xbf2d9d6938e7957,0x58b9},
    {0x1c4217ac03d7f347,0x17e97ec3bbbe7fa5,0xb172}, {0xefb93ff266057747,0x23f162a58989f516,0x10a2b},
    {0xe785fee03979770c,0x2fed4367cab6f34c,0x162e4}, {0xb7178705eb425d19,0x3be26415cb5ffca2,0x1bb9d},
    {0x99d386fe1e67fe52,0x47c60c5651fc6826,0x21456}, {0xdc33ca27ae76c0e3,0x53e0ac68af0f8d45,0x26d0f},
    {0xb920987460ccab06,0x5fc92ccd6bb8f0a7,0x2c5c8}, {0x1668340ee9fe5a93,0x6bda0fbed4c7f913,0x31e81},
    {0x8ea18591547f82b,0x77c5aca6064ac9d5,0x3773a}, {0x10be2ce034ff1e0b,0x83b323296e47fd8a,0x3cff3},
    {0xe27d52ae22538cbb,0x8fc10f43ea11902b,0x428ac}, {0x6d1339a150080f6b,0x9ba8e78a4a916975,0x48165},
    {0x6cb99b86deff0b66,0xa7b88577d11699be,0x4da1e}, {0x88b410857d77a113,0xb3b510d166b0bfcd,0x532d7},
    {0x9328234a71b9e39e,0xbfbe03bfa45e53d0,0x58b90}, {0xa9113370e6c95819,0xcbb65f48e215a1be,0x5e449},
    {0xe92c7c696e7f112c,0xd78d448cda05aa76,0x63d02}, {0xc391aa17bb2e306d,0xe3981c232f9c13af,0x695bb},
    {0x938a7d8cffa8155e,0xefa69c9432396c18,0x6ee74}, {0xf2a451564d1c4467,0xfb92199c68d6317e,0x7472d},
    {0x298ed4e3413defd5,0x7812354074df8f7,0x79fe7}, {0xb9020c95072a113f,0x139d8899037598bf,0x7f8a0},
    {0xfac4d6a530c11dcb,0x1f91d2a304280c6d,0x85159}, {0x361eba5f7b210f8e,0x2b7e22b48dc9c3ac,0x8aa12},
    {0x67b013198bff7bb,0x378c54fb8df946f4,0x902cb}, {0x668e61761f70153b,0x437cadb3f378d692,0x95b84},
    {0xa7e6655ea0f729e3,0x4f8b03cdfc0665f2,0x9b43d}, {0x67731aa1f81e8841,0x5b5e9cb8ea72447e,0xa0cf6},
    {0x1a7b7c5aef8482a9,0x677f1a61810b457c,0xa65af}, {0xa5e22a09ade4180e,0x7357a288fc7e3de4,0xabe68}
  };
  static const u3x64 lt1a[32] = {
    {0,0,0}, {0xfcd4886923dae6b6,0xc85bee167cab86ce,0x2c5},
    {0x635e6b704ed2f5fa,0x90a17ceecc3fe577,0x58b}, {0xdf932da91371dd2,0x591b7d0a4d0016a7,0x851},
    {0x73159a852516c020,0x2174877366ab0cec,0xb17}, {0x6daf0fee571d4b99,0xe9d76cbddb12b19d,0xddc},
    {0xc537f3bccf1bcdda,0xb22edc3896d8e511,0x10a2}, {0x7acd5f3c275334bc,0x7a85a1047f10c872,0x1368},
    {0xcf11c6053e5e8a85,0x42e69173390188dc,0x162e}, {0x5263d7113ff4ec99,0xb5c8f0cfa3bcd0d,0x18f4},
    {0xb72b8544c29a9cca,0xd3b2174ebd216daa,0x1bb9}, {0xc46fc691949a5aab,0x9c123df6aaf7611b,0x1e7f},
    {0xc10a731729fcd789,0x6467b2b9aea50be5,0x2145}, {0x893fa461cbbd9064,0x2cddab05d780030b,0x240b},
    {0x34c38552cb1a0b96,0xf51e45f22e4b220e,0x26d0}, {0x70f1813d88d0193b,0xbd95605269b91143,0x2996},
    {0x73e5b8717251d0f7,0x85ed0e45f6c8616d,0x2c5c}, {0x7f5ae5d5b9581561,0x4e50a741a891eeb4,0x2f22},
    {0x56594d2d9101bad3,0x16aadba73393c1a7,0x31e8}, {0xef4a8eb0c15fbf7a,0xdf06bacc0921d568,0x34ad},
    {0x5d054864b92a7751,0xa76f5f65463c79f7,0x3773}, {0x7a5575cf1df04df6,0x6fcf7a45d5191939,0x3a39},
    {0x9618ad49bb912343,0x38322c12b8541a4a,0x3cff}, {0x2edce206b7063305,0x822052fab58fd5,0x3fc5},
    {0x2e80337b06ed4e80,0xc8eb03cd67c0701c,0x428a}, {0xd46ea81c5e577187,0x91578da94328a582,0x4550},
    {0x8705f6efe46e502b,0x59b269f9f7d32471,0x4816}, {0xfbdb66ebecf00a88,0x2206d0d3e982fcd2,0x4adc},
    {0xc819e2a66efb2206,0xea6005c8e6da3826,0x4da1}, {0xed64886cdf895904,0xb2c957ee1aac3666,0x5067},
    {0xb1f969dae7edc113,0x7b2d79d3afecbfbe,0x532d}, {0x1b3b44759b966886,0x4397c0abdea76dc5,0x55f3}
  };
  static const u3x64 lt2a[32] = {
    {0,0,0}, {0x9cf3bc3d208c9185,0x2e2f5fbcb16ff027,0x16},
    {0xda087301ff6274d4,0x5c7d7f2b9b75afe0,0x2c}, {0x134a54f71a0236c3,0x8aaa5d97d2591b8f,0x42},
    {0xd9c68a61183ce86a,0xb8f5fbaf4fb0944a,0x58}, {0x9c822a201eb1fc42,0xe74058e9835896c7,0x6e},
    {0x5441bb438a9fa9a5,0x1589751695c42b17,0x85}, {0xbd2d2405a0df752a,0x43d15006aea6e5e2,0x9b},
    {0xe419cb9011950b79,0x7217e989f4f4e681,0xb1}, {0x534a67bfdf41cfa2,0xa03d3fe1448d8184,0xc7},
    {0x51f2181bf5cf5458,0xce8155cef8c016e6,0xdd}, {0x2db9191ec9fc2eb3,0xfcc429c04a827e7e,0xf3},
    {0xcd759d3f967fc6f7,0x2b05bb855dcaef6b,0x10a}, {0x95ef9cbd1c7b13c7,0x59660d2f1cc94616,0x120},
    {0x2af332ca6cc1b350,0x87a51a387bbee256,0x136}, {0x7948f090babd87b8,0xb5e2e48603db2b0e,0x14c},
    {0xc53979d14662ef59,0xe41f6be7d6165086,0x162}, {0xeabba1758308d7b9,0x125ab02e12a8fc92,0x179},
    {0xbecf1149da50de5e,0x40b4b4478141a2f2,0x18f}, {0x477f919cf0a27011,0x6eed71f351129ea7,0x1a5},
    {0xba7e797e9eb461b6,0x9d24ebf3e7a2e2a7,0x1bb}, {0x3a5e7941bef2e816,0xcb7b25bd2dfd7f94,0x1d1},
    {0xc9b5422a00ceabbf,0xf9b018040a909da4,0x1e7}, {0xcade12d9d3e36920,0x2803ca0c93032d7e,0x1fe},
    {0x222f102eb784552b,0x563633da2572876c,0x214}, {0x75d47798f62ff1c7,0x84875d625dc415f0,0x22a},
    {0x63e729d32c4f6e9e,0xb2b73df70fec66b5,0x240}, {0x7b5afeebc54c49ab,0xe105de3f5fe748eb,0x256},
    {0x221ca10aac8a3b6a,0xf5339b6125ee838,0x26d}, {0x9e9e828d80c1cf32,0x3d7f4b245f1a3bff,0x283},
    {0x88ad9ab83fc30a52,0x6bca1c3bb9eb9390,0x299}, {0x4d28b6b2476ee8f8,0x9a13a7f1bc8c0d71,0x2af}
  };
  static const u3x64 lt3a[32] = {
    {0,0,0}, {0x347fb733d023cc27,0xb16003d72f3c6259,0},
    {0x8679ca1f8e0297b8,0x62e00f5f83035049,1}, {0x5490ab9896a762f9,0x14402294d37ee9e5,2},
    {0x5e57ae0f99d9a1e6,0xc5c03d7e0f9a82c2,2}, {0x78d5d5583fad6e57,0x7720601183ff07b0,3},
    {0xce2ece6e0065f25a,0x28a08a5bab197ade,4}, {0x17fd57b0c9f4117d,0xda00bc4d46109fe0,4},
    {0x9cdc64425d00b1f6,0x8b80f5f85ad41d75,5}, {0x3ae1d5be90ad7893,0x3d01375498ec7536,6},
    {0x12009a12eb106fa8,0xee618054241e50c0,6}, {0x1c52307d1547e6a6,0x9fe1d11153df1b17,7},
    {0xf679672ea03b5b71,0x5142296f0c4bfc59,8}, {0xa28c66c32c76df90,0x2c2898d305f6b18,9},
    {0x94dd6b2c7f525610,0xb422f14918b10941,9}, {0x692d440a10a891f7,0x65a360c833c14eea,0xa},
    {0xb9f6c9a02410801a,0x1703d7e24ea161d7,0xb}, {0x8e428b3fdd4ff401,0xc88456c26358b19e,0xb},
    {0x798bb05020bcb8ca,0x7a04dd53a7646701,0xc}, {0xb2c5d2cbf27d3f39,0x2b656b7bc4797fa9,0xd},
    {0xee8203ed92fd41cf,0xdce6016e062bac06,0xd}, {0xfb1760c891901812,0x8e469ef45c77a6e2,0xe},
    {0xb33a3b423eeaedd0,0x3fc744479e7a7f29,0xf}, {0xf790771b31f0c07,0xf127f12c30a71684,0xf},
    {0xc210dfa087d58623,0xa2a8a5e075a4d054,0x10}, {0x1c8901c916301142,0x54096223465bbf29,0x11},
    {0x99fc5710ac4e702e,0x58a263890fe90d5,0x12}, {0xd3bcd06f88ddb2f1,0xb6eaf1d9a2e992d0,0x12},
    {0x3f07c144adf4e354,0x686bc54ff5dbb35c,0x13}, {0x288d50e0d51ab78a,0x19eca0777f77067f,0x14},
    {0x3acdd4c172d84d84,0xcb4d8326a9902bfb,0x14}, {0x81f0878a8d99e057,0x7cce6daf3f7a4090,0x15}
  };
  static const b128u128_u c[] = {
    {.b = {0xfffffffffffffffful, 0xfffffffffffffffful}},
    {.b = {0xfffffffffffffffful, 0x000007fffffffffful}},
    {.b = {0x5555555555555551ul, 0x0000000000555555ul}},
    {.b = {0xffffffffffffffeaul, 0x0000000000000003ul}},
    {.b = {0x00003333333332f7ul, 0x0000000000000000ul}},
    {.b = {0x0000000002aaaa5eul, 0x0000000000000000ul}}
  };

  unsigned flagp = _mm_getcsr(), oflagp = flagp, rm = flagp&_MM_ROUND_MASK;
  b128u128_u u = {.a = reinterpret_f128_as_u128(x)}, m, res;
  if(__builtin_expect(u.b[1]>=0x7fffull<<48, 0)){
    u64 b1 = u.b[1]&~0ull>>1; // strip the sign
    if(b1>0x7fffull<<48 || (b1==0x7fffull<<48 && u.b[0])){
      if(!(b1&(1ull<<47))) flagp |= FE_INVALID; // complain about the snan argument by the invalid exception
      u.b[1] |= 1ull<<47; // snan -> qnan
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      return reinterpret_u128_as_f128(u.a); // qNaN
    }
    if(u.b[1]==0x7fffull<<48&&u.b[0]==0) return x; // x = +Inf
    if(b1==0&&u.b[0]==0){
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      flagp |= FE_DIVBYZERO;
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      res.b[0] = 0;
      res.b[1] = 0xfffful<<48;
      return res.f; // x = -0
    }
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    flagp |= FE_INVALID;
    if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
    res.b[0] = 11;
    res.b[1] = 0xffff8ul<<44;
    return res.f; // x<0
  }

  if(0x3ffefffff0000040ull <= u.b[1] && u.b[1] <= 0x3fff000008000020ull){ // too close to 1 so we need specific treatment
    return as_logq_nearone(u, flagp);
  }

  m = u;
  u64 e = u.b[1]&(0xfffful<<48);
  if(__builtin_expect(e==0,0)){ // denormal argument
    if(u.a==0){
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      flagp |= FE_DIVBYZERO;
      if(__builtin_expect(oflagp!=flagp, 0)) _mm_setcsr(flagp);
      res.b[0] = 0;
      res.b[1] = 0xfffful<<48;
      return res.f; // x = +0
    }
    int nz = __builtin_clzl(u.b[1]) + __builtin_clzl(u.b[0])*!u.b[1];
    m.a <<= nz-15;
    e -= (nz-16ul)<<48;
  }
  e += 112ul<<48;

  u64 l = as_log2(m.b[1]); // crude approximation
  int j0 = l>>59, j1 = (l>>54)&31, j2 = (l>>49)&31, j3 = (l>>44)&31;
  m.b[1] &= ~0ull>>16;
  m.b[1] |= 1ull<<48;
  u64 r0 = rt0[j0], r1 = rt1[j1], r01 = r1*r0, r2 = rt2[j2], r3 = rt3[j3], r23 = r2*r3;
  u128 rl, rh = mUUp(&rl, m.a, (u128)r01*r23);
  u64 rhh = rh>>64, rhl = rh, rlh = rl>>64;
  m.b[1] = rhh<<40|rhl>>24;
  m.b[0] = rhl<<40|rlh>>24;
  u3x64 fs; mahu1u3u3(fs,e,ln2a,offa);
  add3(fs,fs,lt0a[j0]);
  add3(fs,fs,lt1a[j1]);
  add3(fs,fs,lt2a[j2]);
  add3(fs,fs,lt3a[j3]);
  int i = 3;
  u128 f = (u128)c[3].b[1]<<64|(c[3].b[0] - mhuu(m.b[1], c[4].b[0] - mhuu(m.b[1], c[5].b[0])));
  while(--i>=0) f = c[i].a - mhUU(m.a, f);
  res.a = mhUU(m.a, f);
  u3x64 d = {res.b[0], res.b[1], 0};
  add3(fs,fs,d);
  i64 msk = fs[2]; msk>>=63;
  fs[0] ^= msk; fs[1] ^= msk; fs[2] ^= msk;
  int nz = __builtin_clzll(fs[2]);
  int ns = nz - 15;
  u64 t = fs[0], tm = ~0ul>>ns, tr = rm == _MM_ROUND_NEAREST;
  u64 rnd = (fs[0]>>(63-ns))&1;
  i64 el = (0x4029ul-nz)|msk<<15;
  if(__builtin_expect(((t + (tr<<(63-ns)) + 12)&tm) <= 24, 0)){ // rounding test
    int ls = nz-14, rs = -ls&63;
    res.b[1] = fs[2]<<ls|fs[1]>>rs;
    res.b[0] = fs[1]<<ls|fs[0]>>rs;
    res.a += (fs[0]>>(63-ls))&1;
    rnd = as_logq_refine(el,res.b,x);
  } else {
    res.b[1] = fs[2]<<ns|fs[1]>>(-ns&63);
    res.b[0] = fs[1]<<ns|fs[0]>>(-ns&63);
  }
  if(__builtin_expect(!tr, 0)){
    rnd = (rm==_MM_ROUND_UP)*!msk + (rm==_MM_ROUND_DOWN)*!!msk;
  }
  b128u128_u dres = {.b = {rnd, el<<48}};
  res.a += dres.a;

  flagp |= FE_INEXACT;
  if(__builtin_expect(oflagp != flagp, 0)) _mm_setcsr(flagp);
  return reinterpret_u128_as_f128(res.a); // put into xmm register
}
