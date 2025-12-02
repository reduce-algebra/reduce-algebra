/* Correctly-rounded compound function for binary32 values.

Copyright (c) 2022-2025 Alexei Sibidanov and Paul Zimmermann

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

/* References:
   [1] FastTwoSum revisited, Claude-Pierre Jeannerod and Paul Zimmermann,
       Proceedings of Arith'2025, preliminary version at
       https://inria.hal.science/hal-04875749
   [2] Correct Rounding in Double Extended Precision, Sélène Corbineau
       and Paul Zimmermann, Proceedings of Arith'2025, preliminary version at
       https://inria.hal.science/hal-04861251
*/

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <math.h> // needed to define compoundf since it is not in glibc
#include <fenv.h> // for fegetexceptflag, fesetexceptflag
#ifdef __x86_64__
#include <x86intrin.h>
#define FLAG_T uint32_t
#else
#define FLAG_T fexcept_t
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;

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

static FLAG_T
get_flag (void)
{
#if defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
  return _mm_getcsr ();
#else
  fexcept_t flag;
  fegetexceptflag (&flag, FE_INEXACT);
  return flag;
#endif
}

static void
set_flag (FLAG_T flag)
{
#ifdef __x86_64__
  _mm_setcsr (flag);
#else
  fesetexceptflag (&flag, FE_INEXACT);
#endif
}

static inline int is_signalingf(float x) {
  b32u32_u u = {.f = x};
  /* To keep the following comparison simple, toggle the quiet/signaling bit,
   so that it is set for sNaNs.  This is inverse to IEEE 754-2008 (as well as
   common practice for IEEE 754-1985).  */
  u.u ^= 0x00400000;
  /* We have to compare for greater (instead of greater or equal), because x's
     significand being all-zero designates infinity not NaN.  */
  return (u.u & 0x7fffffff) > 0x7fc00000;
}

static inline int isint(float y){
  b32u32_u wy = {.f = y};
  int ey = ((wy.u>>23) & 0xff) - 127, s = ey + 9;
  if(ey>=0){
    if(s>=32) return 1;
    return !(wy.u<<s);
  }
  if(!(wy.u<<1)) return 1;
  return 0;
}

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

/* s + t <- a + b, assuming |a| >= |b|
   By Theorem 6 from [1], the error is bounded by 2u^2*ufp(s)
   where u = 2^-53, thus by 2^-105*ufp(s) <= 2^-105 |s|
*/
static void
fast_two_sum (double *s, double *t, double a, double b)
{
  *s = a + b;
  double e = *s - a;
  *t = b - e;
}

// Multiply exactly a and b, such that *hi + *lo = a * b.
static inline void a_mul(double *hi, double *lo, double a, double b) {
  *hi = a * b;
  *lo = __builtin_fma (a, b, -*hi);
}

// Multiply a double with a double double : a * (bh + bl)
static inline void s_mul (double *hi, double *lo, double a, double bh,
                          double bl) {
  a_mul (hi, lo, a, bh); /* exact */
  *lo = __builtin_fma (a, bl, *lo);
}

// Returns (ah + al) * (bh + bl) - (al * bl)
// We can ignore al * bl when assuming al <= ulp(ah) and bl <= ulp(bh)
static inline void d_mul(double *hi, double *lo, double ah, double al,
                         double bh, double bl) {
  double s, t;

  a_mul(hi, &s, ah, bh);
  t = __builtin_fma(al, bh, s);
  *lo = __builtin_fma(ah, bl, t);
}

// INVLOG2 = 1/log(2) * (1 + eps1) with |eps1| < 2^-55.976
#define INVLOG2 0x1.71547652b82fep+0
// LOG2 = log(2) * (1 + eps) with |eps| < 2^-54.730
#define LOG2 0x1.62e42fefa39efp-1

/* for |z| <= 1/64, returns an approximation of log2(1+z)
   with relative error < 2^-49.642 (see analyze_p1() in compoundf.sage)
   and |p1(z)| < 2^-5.459 */
static double p1 (double z)
{
  // we include P[0] = 0 so that P[i] corresponds to degree i
  // this degree-8 polynomial generated by Sollya (cf p1.sollya)
  // has relative error < 2^-50.98
  static const double P[] = {0, 0x1.71547652b82fep0, -0x1.71547652b8d11p-1,
    0x1.ec709dc3a5014p-2, -0x1.715475b144983p-2, 0x1.2776c3fda300ep-2,
    -0x1.ec990162358cep-3, 0x1.a645337c29e27p-3};

  double z2 = z * z;
  double c5 = __builtin_fma (P[6], z, P[5]);
  double c3 = __builtin_fma (P[4], z, P[3]);
  double c1 = __builtin_fma (P[2], z, P[1]);
  double z4 = z2 * z2;
  c5 = __builtin_fma (P[7], z2, c5);
  c1 = __builtin_fma (c3, z2, c1);
  c1 = __builtin_fma (c5, z4, c1);
  return z * c1;
}

/* put in h+l an approximation of log2(1+zh+zl)
   for |zh| <= 1/64 + 2^-51.508, |zl| < 2^-58 and |zl| < ulp(zh).
   We have |h|, |h+l| < 2^-5.459, |l| < 2^-56.162,
   the relative error is bounded by 2^-91.196,
   and |l| < 2^-50.523 |h| (see analyze_p2() in compoundf.sage).
*/
static void p2 (double *h, double *l, double zh, double zl)
{
  /* degree-13 polynomial generated by Sollya which approximates
     log2(1+z) for |z| <= 1/64 with relative error < 2^-93.777
     (cf file p2.sollya)
  */
  static const double P2[] = {
    0x1.71547652b82fep+0, 0x1.777d0ffda0d8p-56,    // degree 1 (0, 1)
    -0x1.71547652b82fep-1, -0x1.777d0fd20b49cp-57, // degree 2 (2, 3)
    0x1.ec709dc3a03fdp-2, 0x1.d27f05171b74ap-56,   // degree 3 (4, 5)
    -0x1.71547652b82fep-2, -0x1.7814e70b828bp-58,  // degree 4 (6, 7)
    0x1.2776c50ef9bfep-2, 0x1.e4f63e12bff83p-56,   // degree 5 (8, 9)
    -0x1.ec709dc3a03f4p-3,                         // degree 6 (10)
    0x1.a61762a7adeccp-3,                          // degree 7 (11)
    -0x1.71547652d8849p-3,                         // degree 8 (12)
    0x1.484b13d7e7029p-3,                          // degree 9 (13)
    -0x1.2776c1b2a40fdp-3,                         // degree 10 (14)
    0x1.0c9a80f9b7c1cp-3,                          // degree 11 (15)
    -0x1.ecc68011212p-4,                           // degree 12 (16)
    0x1.c6e4b91fd10e5p-4,                          // degree 13 (17)
  };
  /* since we can't expect a relative accuracy better than 2^-93.777,
     the lower part of the double-double approximation only needs to
     have about 94-53 = 41 accurate bits. Since |p7*z^7/p1| < 2^-44,
     we evaluate terms of degree 7 or more in double precision only. */
  double t;
  *h = P2[4+13]; // degree 13
  for (int i = 12; i >= 7; i--)
    *h = __builtin_fma (*h, zh, P2[4+i]);
  // now evaluate in double-double
  s_mul (h, l, *h, zh, zl);
  fast_two_sum (h, &t, P2[10], *h);
  *l += t;                         // h+l = h_old*z + p[6]
  d_mul (h, l, *h, *l, zh, zl);
  fast_two_sum (h, &t, P2[8], *h);
  *l += t + P2[9];                 // h+l = (h_old+l_old)*z + p[5]
  d_mul (h, l, *h, *l, zh, zl);
  fast_two_sum (h, &t, P2[6], *h);
  *l += t + P2[7];                 // h+l = (h_old+l_old)*z + p[4]
  d_mul (h, l, *h, *l, zh, zl);
  fast_two_sum (h, &t, P2[4], *h);
  *l += t + P2[5];                 // h+l = (h_old+l_old)*z + p[3]
  d_mul (h, l, *h, *l, zh, zl);
  fast_two_sum (h, &t, P2[2], *h);
  *l += t + P2[3];                 // h+l = (h_old+l_old)*z + p[2]
  d_mul (h, l, *h, *l, zh, zl);
  fast_two_sum (h, &t, P2[0], *h);
  *l += t + P2[1];                 // h+l = (h_old+l_old)*z + p[1]
  // final multiplication by z
  d_mul (h, l, *h, *l, zh, zl);
}

/* for |z| <= 2^-6, returns an approximation of 2^z
   with absolute error < 2^-43.540 (see analyze_q1() in compoundf.sage) */
static double q1 (double z)
{
  /* Q is a degree-4 polynomial generated by Sollya (cf q1.sollya)
     with absolute error < 2^-43.549 */
  static const double Q[] = {1.0, 0x1.62e42fef6d01ap-1,
             0x1.ebfbdff7feebap-3, 0x1.c6b167e579beep-5, 0x1.3b2b3428d06dep-7};
  double z2 = z * z;
  double c3 = __builtin_fma (Q[4], z, Q[3]);
  double c0 = __builtin_fma (Q[1], z, Q[0]);
  double c2 = __builtin_fma (c3  , z, Q[2]);
  return __builtin_fma (c2, z2, c0);
}

/* for |h| <= 2^-6 and |l| <= 2^-58, put in qh+ql a double-double approximation
   of 2^(h+l), with 0.989 < qh < 1.011, |ql| < 2^-51.959, and the absolute
   error bounded by 2^-85.210 (see analyze_q2() in compoundf.sage).
   When |h+l| <= 2^-9, the absolute error is bounded by 2^-102.646. */
static void q2 (double *qh, double *ql, double h, double l)
{
  /* Q2 is a degree-8 polynomial generated by Sollya (cf q2.sollya)
     with absolute error < 2^-85.218 */
  static const double Q2[] = {1.0,                // degree 0 (index 0)
    0x1.62e42fefa39efp-1, 0x1.abc9d45534d06p-56,  // degree 1 (1,2)
    0x1.ebfbdff82c58fp-3, -0x1.5e4383cf9ddf7p-57, // degree 2 (3,4)
    0x1.c6b08d704a0cp-5, -0x1.6cbc55586c8f1p-59,  // degree 3 (5,6)
    0x1.3b2ab6fba4e77p-7,                         // degree 4 (7)
    0x1.5d87fe789aec5p-10,                        // degree 5 (8)
    0x1.430912f879daap-13,                        // degree 6 (9)
    0x1.ffcc774b2367ap-17,                        // degree 7 (10)
    0x1.62c017b9bdfe6p-20,                        // degree 8 (11)
  };
  double h2 = h * h;
  double c7 = __builtin_fma (Q2[11], h, Q2[10]);
  double c5 = __builtin_fma (Q2[9], h, Q2[8]);
  c5 = __builtin_fma (c7, h2, c5);
  // since ulp(c5*h^5) <= 2^-86, we still compute c5*z as double
  *qh = c5 * h;
  fast_two_sum (qh, ql, Q2[7], *qh);
  double t;
  // multiply by h+l
  d_mul (qh, ql, *qh, *ql, h, l);
  // add coefficient of degree 3
  fast_two_sum (qh, &t, Q2[5], *qh);
  *ql += t + Q2[6];
  // multiply by h+l and add coefficient of degree 2
  d_mul (qh, ql, *qh, *ql, h, l);
  fast_two_sum (qh, &t, Q2[3], *qh);
  *ql += t + Q2[4];
  // multiply by h+l and add coefficient of degree 1
  d_mul (qh, ql, *qh, *ql, h, l);
  fast_two_sum (qh, &t, Q2[1], *qh);
  *ql += t + Q2[2];
  // multiply by h+l and add coefficient of degree 0
  d_mul (qh, ql, *qh, *ql, h, l);
  fast_two_sum (qh, &t, Q2[0], *qh);
  *ql += t;
}

// for 0<=i<46, inv[i] approximates 1/t for 1/2+(i+13)/64 <= t < 1/2+(i+14)/64
static const double inv[] = {
  0x1.68p+0, 0x1.6p+0, 0x1.58p+0, 0x1.5p+0, 0x1.4cp+0, 0x1.44p+0, 0x1.4p+0,
  0x1.38p+0, 0x1.34p+0, 0x1.2cp+0, 0x1.28p+0, 0x1.2p+0, 0x1.1cp+0, 0x1.18p+0,
  0x1.14p+0, 0x1.1p+0, 0x1.0cp+0, 0x1.08p+0, 0x1p+0, 0x1p+0, 0x1.f4p-1,
  0x1.ecp-1, 0x1.e4p-1, 0x1.ep-1, 0x1.d8p-1, 0x1.dp-1, 0x1.cap-1, 0x1.c4p-1,
  0x1.bep-1, 0x1.b8p-1, 0x1.b2p-1, 0x1.acp-1, 0x1.a8p-1, 0x1.a2p-1,
  0x1.9cp-1, 0x1.98p-1, 0x1.92p-1, 0x1.8cp-1, 0x1.88p-1, 0x1.84p-1,
  0x1.8p-1, 0x1.7cp-1, 0x1.76p-1, 0x1.72p-1, 0x1.6ep-1, 0x1.6ap-1,
};

/* log2inv[i][0]+log2inv[i][1] is a double-double approximation of
   -log2(inv[i]), with log2inv[i][0] having absolute error < 2^-54.462,
   and log2inv[i][0]+log2inv[i][1] absolute error < 2^-109.101 */
static const double log2inv[][2] = {
  {-0x1.f7a8568cb06cfp-2,0x1.8f3673ffdd785p-57},
  {-0x1.d6753e032ea0fp-2,0x1.c141e66faaaadp-62},
  {-0x1.b47ebf73882a1p-2,0x1.6fae441c09d76p-56},
  {-0x1.91bba891f1709p-2,0x1.2d352bea51e59p-56},
  {-0x1.800a563161c54p-2,-0x1.9575b04fa6fbdp-57},
  {-0x1.5c01a39fbd688p-2,0x1.817fd3b7d7e5dp-56},
  {-0x1.49a784bcd1b8bp-2,0x1.b6d40900b2502p-62},
  {-0x1.24407ab0e073ap-2,0x1.f6e91ad16ecffp-56},
  {-0x1.11307dad30b76p-2,0x1.a7b47d2c352d9p-57},
  {-0x1.d49ee4c32597p-3,0x1.b85a54d7ee2fdp-58},
  {-0x1.acf5e2db4ec94p-3,0x1.01ee1343fe7cap-59},
  {-0x1.5c01a39fbd688p-3,0x1.817fd3b7d7e5dp-57},
  {-0x1.32ae9e278ae1ap-3,-0x1.f51f2c075a74cp-59},
  {-0x1.08c588cda79e4p-3,0x1.a7610e40bd6abp-57},
  {-0x1.bc84240adabbap-4,-0x1.8ecb169b9465fp-58},
  {-0x1.663f6fac91316p-4,-0x1.f3314e0985116p-58},
  {-0x1.0eb389fa29f9bp-4,0x1.30c22d15199b8p-58},
  {-0x1.6bad3758efd87p-5,-0x1.89b03784b5be1p-60},
  {0x0p+0,0x0p+0},
  {0x0p+0,0x0p+0},
  {0x1.184b8e4c56af8p-5,0x1.491f06c085bc2p-60},
  {0x1.d6ebd1f1febfep-5,0x1.155660710eb2ap-63},
  {0x1.4c560fe68af88p-4,0x1.c141e66faaaadp-61},
  {0x1.7d60496cfbb4cp-4,0x1.9ced1447e30adp-58},
  {0x1.e0b1ae8f2fd56p-4,0x1.92ce9636c90ap-58},
  {0x1.22dadc2ab3497p-3,-0x1.696e2866c718ep-58},
  {0x1.494f863b8df35p-3,-0x1.1562d61af73f8p-57},
  {0x1.7046031c79f85p-3,-0x1.0798d1aa21694p-57},
  {0x1.97c1cb13c7ec1p-3,-0x1.e95734abd2fccp-57},
  {0x1.bfc67a7fff4ccp-3,0x1.bc0af7b82e7d7p-61},
  {0x1.e857d3d361368p-3,-0x1.086fce864a1f6p-57},
  {0x1.08bce0d95fa38p-2,-0x1.3d56efe4338fep-58},
  {0x1.169c05363f158p-2,0x1.c8d43e017579bp-56},
  {0x1.2baa0c34be1ecp-2,-0x1.0132ae5e417cdp-58},
  {0x1.4106017c3eca3p-2,-0x1.c658d602e66bp-56},
  {0x1.4f6fbb2cec598p-2,0x1.e393a16b94b52p-56},
  {0x1.6552b49986277p-2,0x1.ac9080333c605p-56},
  {0x1.7b89f02cf2aadp-2,0x1.8f89e2eb553b2p-57},
  {0x1.8a8980abfbd32p-2,0x1.99aa6df8b7d83p-56},
  {0x1.99b072a96c6b2p-2,0x1.bca36fd02defp-56},
  {0x1.a8ff971810a5ep-2,0x1.817fd3b7d7e5dp-58},
  {0x1.b877c57b1b07p-2,-0x1.01d98c3531027p-58},
  {0x1.cffae611ad12bp-2,0x1.8a38b4175d665p-56},
  {0x1.dfdd89d586e2bp-2,0x1.38c8946414c6ap-59},
  {0x1.efec61b011f85p-2,0x1.6d261f1753e0bp-56},
  {0x1.0014332be0033p-1,-0x1.7398fe685f171p-55},
};

/* for -1 < x < 2^128, approximates log2(1+x)
   Note: assume x is representable in binary32.
   For |x| < 2^-29, the relative error is bounded by 2^-50.950,
   and for |x| >= 2^-29, it is bounded by 2^-47.997 (see analyze_log2p1()
   in compoundf.sage).
   Thus for all x, the relative error is bounded by 2^-47.997.
*/
static double _log2p1 (double x)
{
  /* for x > 0, 1+x is exact when 2^-29 <=  x < 2^53
     for x < 0, 1+x is exact when -1 < x <= 2^-30 */

  //  double u = (x >= 0x1p53) ? x : 1.0 + x;
  double u = 1.0 + x;
  /* For x < 0x1p53, x + 1 is exact thus u = x+1.
     For x >= 2^53, we estimate log2(x) instead of log2(1+x),
     since log2(1+x) = log2(x) + log2(1+1/x),
     log2(x) >= 53 and |log2(1+1/x)| < 2^-52.471, the additional relative
     error is bounded by 2^-52.471/53 < 2^-58.198 */

  b64u64_u v = {.f = u};
  uint64_t m = v.u & 0xfffffffffffffull;
  int64_t e = (v.u >> 52) - 0x3ff + (m >= 0x6a09e667f3bcdull);
  // 2^e/sqrt(2) < u < 2^e*sqrt(2), with -29 <= e <= 128
  v.u -= e * 0x10000000000000ll;
  double t = v.f;
  // u = 2^e*t with 1/sqrt(2) < t < sqrt(2)
  // thus log2(u) = e + log2(t)
  v.f += 2.0; // add 2 so that v.f is always in the binade [2, 4)
  int i = (v.u >> 45) - 0x2002d; // 0 <= i <= 45
  double r = inv[i];
  double z = __builtin_fma (r, t, -1.0); // exact, -1/64 <= z <= 1/64
  // we approximates log2(t) by -log2(r) + log2(r*t)
  double p = p1 (z);
  // p approximates log2(r*t) with rel. error < 2^-49.642, and |p| < 2^-5.459
  return (double) e + (log2inv[i][0] + p);
}

// for 0 <= i <= 32, exp2_T[i] = (i-16)/2^5
static const double exp2_T[] = {
  -0x1p-1, -0x1.ep-2, -0x1.cp-2, -0x1.ap-2, -0x1.8p-2, -0x1.6p-2, -0x1.4p-2,
  -0x1.2p-2, -0x1p-2, -0x1.cp-3, -0x1.8p-3, -0x1.4p-3, -0x1p-3, -0x1.8p-4,
  -0x1p-4, -0x1p-5, 0x0p+0, 0x1p-5, 0x1p-4, 0x1.8p-4, 0x1p-3, 0x1.4p-3,
  0x1.8p-3, 0x1.cp-3, 0x1p-2, 0x1.2p-2, 0x1.4p-2, 0x1.6p-2, 0x1.8p-2,
  0x1.ap-2, 0x1.cp-2, 0x1.ep-2, 0x1p-1,
};

/* exp2_U[i] is a double-double approximation h+l of 2^exp2_T[i]
   so that h approximates 2^exp2_T[i] with absolute error < 2^-53.092,
   and h+l approximates 2^exp2_T[i] with absolute error < 2^-107.385 */
static const double exp2_U[][2] = {
  {0x1.6a09e667f3bcdp-1,-0x1.bdd3413b26456p-55},
  {0x1.71f75e8ec5f74p-1,-0x1.16e4786887a99p-56},
  {0x1.7a11473eb0187p-1,-0x1.41577ee04992fp-56},
  {0x1.82589994cce13p-1,-0x1.d4c1dd41532d8p-55},
  {0x1.8ace5422aa0dbp-1,0x1.6e9f156864b27p-55},
  {0x1.93737b0cdc5e5p-1,-0x1.75fc781b57ebcp-58},
  {0x1.9c49182a3f09p-1,0x1.c7c46b071f2bep-57},
  {0x1.a5503b23e255dp-1,-0x1.d2f6edb8d41e1p-55},
  {0x1.ae89f995ad3adp-1,0x1.7a1cd345dcc81p-55},
  {0x1.b7f76f2fb5e47p-1,-0x1.5584f7e54ac3bp-57},
  {0x1.c199bdd85529cp-1,0x1.11065895048ddp-56},
  {0x1.cb720dcef9069p-1,0x1.503cbd1e949dbp-57},
  {0x1.d5818dcfba487p-1,0x1.2ed02d75b3707p-56},
  {0x1.dfc97337b9b5fp-1,-0x1.1a5cd4f184b5cp-55},
  {0x1.ea4afa2a490dap-1,-0x1.e9c23179c2893p-55},
  {0x1.f50765b6e454p-1,0x1.9d3e12dd8a18bp-55},
  {0x1p+0,0x0p+0},
  {0x1.059b0d3158574p+0,0x1.d73e2a475b465p-55},
  {0x1.0b5586cf9890fp+0,0x1.8a62e4adc610bp-54},
  {0x1.11301d0125b51p+0,-0x1.6c51039449b3ap-54},
  {0x1.172b83c7d517bp+0,-0x1.19041b9d78a76p-55},
  {0x1.1d4873168b9aap+0,0x1.e016e00a2643cp-54},
  {0x1.2387a6e756238p+0,0x1.9b07eb6c70573p-54},
  {0x1.29e9df51fdee1p+0,0x1.612e8afad1255p-55},
  {0x1.306fe0a31b715p+0,0x1.6f46ad23182e4p-55},
  {0x1.371a7373aa9cbp+0,-0x1.63aeabf42eae2p-54},
  {0x1.3dea64c123422p+0,0x1.ada0911f09ebcp-55},
  {0x1.44e086061892dp+0,0x1.89b7a04ef80dp-59},
  {0x1.4bfdad5362a27p+0,0x1.d4397afec42e2p-56},
  {0x1.5342b569d4f82p+0,-0x1.07abe1db13cadp-55},
  {0x1.5ab07dd485429p+0,0x1.6324c054647adp-54},
  {0x1.6247eb03a5585p+0,-0x1.383c17e40b497p-54},
  {0x1.6a09e667f3bcdp+0,-0x1.bdd3413b26456p-54},
};

/* return the correct rounding of (1+x)^y, otherwise -1.0
   where t is an approximation of y*log2(1+x) with absolute error < 2^-40.680,
   assuming 0x1.7154759a0df53p-24 <= |t| <= 150 */
static float exp2_1 (double t)
{
  double k = roundeven_finite (t); // 0 <= |k| <= 150
  double r = t - k; // |r| <= 1/2, exact
  b64u64_u v = {.f = 3.015625 + r}; // 2.5 <= v <= 3.5015625
  // we add 2^-6 so that i is rounded to nearest
  int i = (v.u >> 46) - 0x10010; // 0 <= i <= 32
  // r is near (i-16)/2^5
  r -= exp2_T[i]; // exact
  // now |r| <= 2^-6
  // 2^t = 2^k * exp2_U[i][0] * 2^r
  v.f = exp2_U[i][0] * q1 (r);
  /* the absolute error on exp2_U[i][0] is bounded by 2^-53.092, with
     exp2_U[i][0] < 2^0.5, and that on q1(r) is bounded by 2^-43.540,
     with |q1(r)| < 1.011, thus |v| < 1.43, and the absolute error on v is
     bounded by ulp(v) + 2^0.5 * 2^-43.540 + 2^-53.092 * 1.011 < 2^-43.035.
     Now t approximates u := y*log2(1+x) with |t-u| < 2^-40.680 thus
     2^u = 2^t * (1 + eps) with eps < 2^(2^-40.680)-1 < 2^-41.208.
     The total absolute error is thus bounded by 2^-43.035 + 2^-41.208
     < 2^-40.849. */
  b64u64_u err = {.f = 0x1.1dp-41}; // 2^-40.849 < 0x1.1dp-41
  v.u += (int64_t) k * 0x10000000000000ll; // scale v by 2^k

  // in case of potential underflow, we defer to the accurate path
  if (__builtin_expect (v.f < 0x1.00000000008e2p-126, 0))
    return -1.0f;

  err.u += (int64_t) k * 0x10000000000000ll; // scale the error by 2^k too
  float lb = v.f - err.f, rb = v.f + err.f;
  if (lb != rb) return -1.0f; // rounding test failed

#ifdef CORE_MATH_SUPPORT_ERRNO
  if (lb > 0x1.fffffep+127f)
    errno = ERANGE; // overflow
#endif

  return lb;
}

// return non-zero if (1+x)^y is exact or midpoint in binary32
// adapted from powf.c, commit 8ec0730
// set midpoint to non-zero if (1+x)^y is a midpoint
// (assume midpoint=0 initially)
static int
is_exact_or_midpoint (float x, float y, int *midpoint)
{
  /* All cases such that (1+x)^y might be exact are:
     (a) x = 0
     (b) y integer, 0 <= y <= 15 (because 3^16 has 26 bits)
     (c) y<0: x=0 or (1+x=2^e and |y|=n*2^-k with 2^k dividing e)
     (d) y>0: y=n*2^f with -4 <= f <= -1 and 1 <= n <= 15
     In cases (b)-(d), the low 16 bits of the encoding of y are zero,
     thus we use that for an early exit test.
     (For case (c), x=1 and y=-149, only 16 low bits of the
     encoding of y are zero.) */

  b32u32_u v = {.f = x}, w = {.f = y};
  if (__builtin_expect ((v.u << 1) != 0 && // |0| <> 1
                        (w.u << (32 - 16)) != 0, 1))
    return 0;

  if (__builtin_expect ((v.u << 1) == 0, 0)) // x = 0
    return 1; // never midpoint

  int32_t e = ((v.u << 1) >> 24) - 0x96; // ulp(x) = 2^e

  /* We assume (1+x)^y cannot be exact in binary32 if 1+x is not exact in
     binary64:
     * 1+x cannot be exact in double when |x| < 2^-53, thus since
       ufp(x)=2^(e+23), when e+23 < -53, i.e., when e < -76.
     * similarly, 1+x cannot be exact when |x| > 2^53, which occurs when
       e+23 > 53, i.e., e > 30. */

  if (e < -76 || 30 < e)
    return 0;

  b64u64_u vd = {.f = 1.0 + (double) x};

  // recompute e for 1+x
  e = ((vd.u << 1) >> 53) - 0x433; // ulp53(1+x) = 2^e

  // xmax[y] for 1<=y<=15 is the largest odd m such that m^y fits in 25 bits
  static const uint64_t xmax[] = { 0, 0xffffff, 5791, 321, 75, 31, 17, 11,
                                   7, 5, 5, 3, 3, 3, 3, 3};
  if (y >= 0 && isint (y)) {
    /* let 1+x = m*2^e with m an odd integer, (1+x)^y is exact when
       - y = 0 or y = 1
       - m = 1 or -1 and -149 <= e*y < 128
       - if |1+x| is not a power of 2, 2 <= y <= 15 and
         m^y should fit in 25 bits
    */
    uint64_t m = vd.u & 0xfffffffffffffull; // low 52 bits of significand
    if (e >= -1074)
      m |= 0x10000000000000ull;
    else // subnormal numbers
      e++;
    int t = __builtin_ctzl (m);
    m = m >> t;
    e += t;
    /* For normal numbers, we have 1+x = m*2^e. */
    if (y == 0 || y == 1)
    {
      *midpoint = m > 0x1000000u;
      return 1;
    }
    if (m == 1)
      return -149 <= y * e && y * e < 128; // never midpoint
    // now for y < 0 or 15 < y it cannot be exact
    if (y < 0 || 15 < y)
      return 0;
    // now 2 <= y <= 15
    int y_int = (int) y;
    if (m > xmax[y_int])
      return 0;
    // |x^y| = m^y * 2^(e*y)
    uint64_t my = m * m;
    for (int i = 2; i < y_int; i++)
      my = my * m;
    // my = m^y
    t = 64 - __builtin_clzl (my);
    // 2^(t-1) <= m^y < 2^t thus 2^(e*y + t - 1) <= |(1+x)^y| < 2^(e*y + t)
    int32_t ez = e * y_int + t;
    if (ez <= -149 || 128 < ez)
      return 0;
    // since m is odd, x^y is an odd multiple of 2^(e*y)
    *midpoint = my > 0x1000000u;
    return e * y_int >= -149;
  }

  uint32_t n = w.u & 0x7fffff;
  int32_t f = ((w.u << 1) >> 24) - 0x96;
  if (f >= -149)
    n |= 0x800000;
  else // subnormal numbers
    f++;
  int t = __builtin_ctz (n);
  n = n >> t;
  f += t;
  // |y| = n*2^f with n odd

  uint64_t m = vd.u & 0xfffffffffffffull;
  if (e >= -1074)
    m |= 0x10000000000000ull;
  else // subnormal numbers
    e++;
  t = __builtin_ctzl (m);
  m = m >> t;
  e += t;
  // |1+x| = m*2^e with m odd

  /* if y < 0, the only cases where (1+x)^y might be exact are:
     (a) y integer and 1+x = 2^e
     (b) y = -n/2^k with k >= 1 and 1+x = 2^e with 2^k dividing e */
  if (y < 0)
  {
    if (m != 1) return 0;
    // now |1+x| = 2^e with e <> 0
    // in case (a), f >= 0; in case (b), f < 0 and k = -f
    t = __builtin_ctz (e);
    if (-f > t) return 0; // only possible with (b), when 2^k does not divide e
    int32_t ez;
    if (e >= 0)
      ez = ((f >= 0) ? -(e << f) : -(e >> (-f))) * n;
    else
      ez = ((f >= 0) ? (-e << f) : (-e >> (-f))) * n;
    return -149 <= ez && ez < 128;
  }

  /* now y > 0, y is not a integer, y = n*2^f with n odd and f < 0.
     Since x^(n*2^f) = (x^(2^f))^n, and n is odd, necessarily
     x is an exact (2^k)th power with k=-f.
     This implies x is a square. Since x = m*2^e with m odd,
     necessarily m is a square, and e is even. */
  while (f++) {
    // try to extract a square from m*2^e
    if (e&1) return 0;
    e = e / 2;
    double dm = (double) m;
    double s = __builtin_round (__builtin_sqrt (dm));
    if (s * s != dm)
      return 0;
    /* The above call of sqrtf() might set the inexact flag, but in case
       it happens, m is not a square, thus x^y cannot be exact. */
    m = (uint64_t) s;
  }

  // Now |x^y| = (m*2^e)^n with m, n odd integers
  // now for 15 < n it cannot be exact, unless m=1
  if (m > 1)
  {
    if (15 < n)
      return 0;
    // now n <= 15
    if (m > xmax[n])
      return 0;
  }
  // |x^y| = m^n * 2^(e*n) with m odd
  uint32_t my = m, n0 = n;
  while (n0-- > 1)
    my = my * m;
  // |x^y| = my * 2^(e*n)
  t = 32 - __builtin_clz (my); // number of significant bits of m^n
  /* x^y is an odd multiple of 2^(e*n) thus we should have e*n >= -149,
     we also have 2^(t-1) <= m^n thus 2^(e*n+t-1) <= |x^y| < 2^(e*n+t)
     and we need e*n+t <= 128 */
  return -149 <= e * (int) n && e * (int) n + t <= 128;
}

/* return the correct rounding of (1+x)^y or -1 if the rounding test failed,
   where t is an approximation of y*log2(1+x).
   We assume |h+l| < 150, |l/h| < 2^-48.445 |h|,
   and the relative error between h+l and y*log2(1+x) is < 2^-91.120.
   x and y are the original inputs of compound. */
static float exp2_2 (double h, double l, float x, float y, int exact,
                     FLAG_T flag)
{
  if (y == 1.0f) {
    set_flag (flag); // restore flags
    float res = 1.0f + x;
#ifdef CORE_MATH_SUPPORT_ERRNO
    if (res > 0x1.fffffep+127f)
        errno = ERANGE; // overflow
#endif
    return res;
  }

  double k = roundeven_finite (h); // |k| <= 150

  // check easy cases h+l is tiny thus 2^(h+l) rounds to 1, 1- or 1+
  if (k == 0 && __builtin_fabs (h) <= 0x1.715476af0d4c8p-25) {
    /* the relative error between h and y*log2(1+x) is bounded by
       (1 + 2^-48.445) * (1 + 2^-91.120) - 1 < 2^-48.444.
       2^h rounds to 1 to nearest for |h| <= H0 := 0x1.715476af0d4d9p-25.
       The above threshold is such that h*(1+2^-48.444) < H0. */
    return 1.0 + h * 0.5;
  }

  double r = h - k; // |r| <= 1/2, exact
  // since r is an integer multiple of ulp(h), fast_two_sum() below is exact
  fast_two_sum (&h, &l, r, l);
  b64u64_u v = {.f = 3.015625 + h}; // 2.5 <= v <= 3.5015625
  // we add 2^-6 so that i is rounded to nearest
  int i = (v.u >> 46) - 0x10010; // 0 <= i <= 32
  // h is near (i-16)/2^5
  h -= exp2_T[i]; // exact
  // now |h| <= 2^-6
  // 2^(h+l) = 2^k * exp2_U[i] * 2^(h+l)
  fast_two_sum (&h, &l, h, l); // renormalize
  // now |l| <= ulp(2^-6) = 2^-58
  double qh, ql;
  q2 (&qh, &ql, h, l);
  /* we have 0.989 < qh < 1.011, |ql| < 2^-51.959, and
     |qh + ql - 2^(h+l)| < 2^-85.210 */
  d_mul (&qh, &ql, exp2_U[i][0], exp2_U[i][1], qh, ql);
  fast_two_sum (&qh, &ql, qh, ql); // renormalize

  /* Total error:
   * at input we have a relative error between h+l and y*log2(1+x) bounded
     by 2^-91.120: h + l = y*log2(1+x) * (1 + eps1) with |eps1| < 2^-91.120.
     Since |h+l| <= 150, this yields an absolute error bounded
     by 150*2^-91.120 < 2^-83.891:
     h + l = y*log2(1+x) + eps2 with |eps2| <= 150*2^-91.120 < 2^-83.891.
   * the absolute error in q2() is bounded by 2^-85.210
     and is multiplied by exp2_U[i] < 1.415
   * the absolute d_mul() error is bounded by 2^-102.199
   * the fast_two_sum() error is bounded by 2^-105
   All this yields an absolute error on qh+ql bounded by:
     2^-83.891 + 2^-85.210*1.415 + 2^-102.199 + 2^-105 < 2^-83.242.

   We distinguish the "small" case when at input |h+l| <= 2^-18.
   In this case k=0, i=16, thus exp2_T[i]=0, exp2_U[i]=1,
   and absolute error in q2() is bounded by 2^-94.055,
   and remains unchanged since the d_mul() call does not change qh, ql.
  */

  /* Rounding test: since |ql| < ulp(qh), and the error is less than ulp(qh),
     the rounding test can fail only when the last 53-25 = 28 bits of qh
     represent a signed number in [-1,1] (when it is -2 or 2, adding ql and
     the error cannot cross a rounding boundary). */
  b64u64_u w = {.f = qh};
  if (((w.u + 1) & 0xfffffffull) <= 2) {
    static const double Err[2] = {0x1.b1p-84, // 2^-83.242 < 0x1.b1p-84
                                  0x1.edp-95, // error bound in the small case
    };
    int small = k == 0 && i == 16 && __builtin_fabs (h) <= 0x1p-18;
    double err = Err[small];

    v.f = qh + (ql - err);
    v.u += (int64_t) k * 0x10000000000000ll;
    w.f = qh + (ql + err);
    w.u += (int64_t) k * 0x10000000000000ll;
    float left, right;

    if (exact) {
      /* exact/midpoint case: the one with the more trailing zeros between v.u and
         w.u is the correct one, except when y=1, since for x=0x1.fffffep+127
         and y=1 we get left=0x1.fffffep+127 and right=inf */
      int vtz = __builtin_ctzll (v.u);
      int wtz = __builtin_ctzll (w.u);
      set_flag (flag); // restore flags
      return (vtz >= wtz) ? v.f : w.f;
    }

    left = v.f;
    right = w.f;

    // check whether (1+x)^y is exact
    // we assume this can hold only when 1+x is exactly representable

    if (left != right) {
        printf ("Rounding test of accurate path failed for compound(%a,%a)\n",
                (double) x, (double) y);
        printf ("Please report the above to core-math@inria.fr\n");
        exit (1);
    }
  }

  /* multiply qh+ql by 2^k: since 0.989 < qh_in < 1.011 and
     0.707 < exp2_U[i] < 1.415, we have 0.69 < qh+ql < 1.44 */
  v.f = qh + ql;
  /* For RNDN, if qh fits exactly in 25 bits, and ql is tiny, so that
     qh + ql rounds to qh, then we might have a double-rounding issue. */
  if ((w.u << 36) == 0 && v.f == qh && ql != 0)
      v.u += (ql > 0) ? 1 : -1; // simulate round to odd
  v.u += (int64_t) k * 0x10000000000000ll; // scale v by 2^k
  // there is no underflow/overflow in the scaling by 2^k since |k| <= 150
  float res = v.f;
#ifdef CORE_MATH_SUPPORT_ERRNO
  double tiny = 0x1p-55;
  if (res < 0x1p-126f                                 // RNDZ, RNDD
      || (res == 0x1p-126f && v.f <= 0x1.fffffep-127) // RNDN or RNDU
      || (res == 0x1p-126f && v.f < 0x1.ffffffp-127 && 1.0 - tiny == 1.0 + tiny))
    errno = ERANGE; // underflow
#endif
  return res; // convert to float
}

/* assuming -1 < x < 2^128, and x is representable in binary32,
   put in h+l a double-double approximation of log2(1+x),
   with relative error bounded by 2^-91.123, and |l| < 2^-48.574 |h|
   (see analyze_log2p1_accurate() in compoundf.sage) */
static void
log2p1_accurate (double *h, double *l, double x)
{
  if (1.0 >= x) { // then 1.0 >= |x| since x > -1
    if (__builtin_expect (__builtin_fabs (x) >= 0x1p-53, 1))
      fast_two_sum (h, l, 1.0, x); // exact by Lemma 1 condition (ii) of [1]
    else
      *h = 1.0, *l = x; // exact
  }
  else
    // fast_two_sum() is exact when |x| < 2^54 by Lemma 1 condition (ii) of [1]
    fast_two_sum (h, l, x, 1.0);

  // now h + l = 1 + x + eps with |eps| <= 2^-105 |h| and |l| <= ulp(h)

  b64u64_u v = {.f = *h};
  uint64_t m = v.u & 0xfffffffffffffull;
  int64_t e = (v.u >> 52) - 0x3ff + (m >= 0x6a09e667f3bcdull);
  // 2^e/sqrt(2) < h < 2^e*sqrt(2), with -29 <= e <= 128
  // divide h, l by 2^e
  static const double scale[] = {
    0x1p+29, 0x1p+28, 0x1p+27, 0x1p+26, 0x1p+25, 0x1p+24, 0x1p+23, 0x1p+22,
    0x1p+21, 0x1p+20, 0x1p+19, 0x1p+18, 0x1p+17, 0x1p+16, 0x1p+15, 0x1p+14,
    0x1p+13, 0x1p+12, 0x1p+11, 0x1p+10, 0x1p+9, 0x1p+8, 0x1p+7, 0x1p+6,
    0x1p+5, 0x1p+4, 0x1p+3, 0x1p+2, 0x1p+1, 0x1p+0, 0x1p-1, 0x1p-2, 0x1p-3,
    0x1p-4, 0x1p-5, 0x1p-6, 0x1p-7, 0x1p-8, 0x1p-9, 0x1p-10, 0x1p-11, 0x1p-12,
    0x1p-13, 0x1p-14, 0x1p-15, 0x1p-16, 0x1p-17, 0x1p-18, 0x1p-19, 0x1p-20,
    0x1p-21, 0x1p-22, 0x1p-23, 0x1p-24, 0x1p-25, 0x1p-26, 0x1p-27, 0x1p-28,
    0x1p-29, 0x1p-30, 0x1p-31, 0x1p-32, 0x1p-33, 0x1p-34, 0x1p-35, 0x1p-36,
    0x1p-37, 0x1p-38, 0x1p-39, 0x1p-40, 0x1p-41, 0x1p-42, 0x1p-43, 0x1p-44,
    0x1p-45, 0x1p-46, 0x1p-47, 0x1p-48, 0x1p-49, 0x1p-50, 0x1p-51, 0x1p-52,
    0x1p-53, 0x1p-54, 0x1p-55, 0x1p-56, 0x1p-57, 0x1p-58, 0x1p-59, 0x1p-60,
    0x1p-61, 0x1p-62, 0x1p-63, 0x1p-64, 0x1p-65, 0x1p-66, 0x1p-67, 0x1p-68,
    0x1p-69, 0x1p-70, 0x1p-71, 0x1p-72, 0x1p-73, 0x1p-74, 0x1p-75, 0x1p-76,
    0x1p-77, 0x1p-78, 0x1p-79, 0x1p-80, 0x1p-81, 0x1p-82, 0x1p-83, 0x1p-84,
    0x1p-85, 0x1p-86, 0x1p-87, 0x1p-88, 0x1p-89, 0x1p-90, 0x1p-91, 0x1p-92,
    0x1p-93, 0x1p-94, 0x1p-95, 0x1p-96, 0x1p-97, 0x1p-98, 0x1p-99, 0x1p-100,
    0x1p-101, 0x1p-102, 0x1p-103, 0x1p-104, 0x1p-105, 0x1p-106, 0x1p-107,
    0x1p-108, 0x1p-109, 0x1p-110, 0x1p-111, 0x1p-112, 0x1p-113, 0x1p-114,
    0x1p-115, 0x1p-116, 0x1p-117, 0x1p-118, 0x1p-119, 0x1p-120, 0x1p-121,
    0x1p-122, 0x1p-123, 0x1p-124, 0x1p-125, 0x1p-126, 0x1p-127, 0x1p-128,
  };
  *h *= scale[e + 29];
  *l *= scale[e + 29];
  // now |h| < sqrt(2) and |l| <= ulp(h) <= 2^-52

  // now 1 + x ~ 2^e * (h + l) thus log2(1+x) ~ e + log2(h+l)

  v.f = 2.0 + *h; // add 2 so that v.f is always in the binade [2, 4)
  int i = (v.u >> 45) - 0x2002d; // h is near 1/2+(i+13)/64
  double r = inv[i];
  double zh = __builtin_fma (r, *h, -1.0); // exact, -1/64 <= zh <= 1/64
  double zl = r * *l;
  // since |r| <= 0x1.68p+0 and |l| <= 2^-52, |zl| <= 2^-51.508
  // zh + zl = r*(h+l)-1
  // log2(h+l) = -log2(r) + log2(r*(h+l)) = -log2(r) + log2(1+zh+zl)
  fast_two_sum (&zh, &zl, zh, zl);
  // now |zh| <= 1/64 + 2^-51.508 and |zl| < 2^-58
  /* the relative error of fast_two_sum() is bounded by 2^-105,
     this amplified the relative error on p2() as follows:
     (1+2^-91.196)*(1+2^-105)-1 < 2^-91.195. */
  double ph, pl;
  p2 (&ph, &pl, zh, zl);
  // ph + pl approximates log2(1+zh+zl) with relative error < 2^-93.471

  /* since |log2inv[i][0]| < 1 and e is integer, the precondition of
     fast_two_sum is fulfilled: either |e| >= 1, or e=0 and fast_two_sum
     is exact */
  fast_two_sum (h, l, (double) e, log2inv[i][0]);
  *l += log2inv[i][1];
  // e + log2(h+l) ~ rh + rl + ph + pl
  double t;
  /* if e=0 and log2inv[i][0]=log2inv[i][1]=0, then h=l=0 here,
     h = ph below and t=0, thus l = pl at the end, and the only
     error is that from p2() */
  fast_two_sum (h, &t, *h, ph);
  *l += t + pl;
}

// at input, exact is non-zero iff (1+x)^y is exact
// x,y=0x1.0f6f1ap+1,0x1.c643bp+5: 49 identical bits after round bit
// x,y=0x1.ef272cp+15,-0x1.746ab2p+1: 55 identical bits after round bit
// x,y=0x1.07ffcp+0,-0x1.921a8ap+4: 47 identical bits after round bit
static double
accurate_path (float x, float y, int exact, FLAG_T flag)
{
  double h, l;

  log2p1_accurate (&h, &l, x);
  /* h + l is a double-double approximation of log2(1+x),
     with relative error bounded by 2^-91.123,
     and |l| < 2^-48.574 |h| */

  s_mul (&h, &l, y, h, l);
  /* h + l is a double-double approximation of y*log(1+x).
     Since 2^-149 <= |h_in+l_in| < 128 and 2^-149 <= |y| < 2^128, we have
     2^-298 <= |h+l| < 2^135, thus no underflow/overflow in double is possible.
     The s_mul() error is bounded by ulp(l). Since |l_in| < 2^-48.574 |h_in|,
     and the intermediate variable lo in s_mul() satisfies |lo| < ulp(h),
     we have |l| < ulp(h) + |y l_in| <= ulp(h) + 2^-48.574 |y h_in|
     < (2^-52 + 2^-48.574) |h| < 2^-48.445 |h|. The s_mul() error is thus
     bounded by 2^-48.445*2^-52 = 2^-100.445 |h|. This yields a total relative
     error bounded by (1+2^-91.123)*(1+2^-100.445)-1 < 2^-91.120. */

  return exp2_2 (h, l, x, y, exact, flag);
}

/* this routine is called with x <= -1
   or with x = 0, Inf, NaN or with y = 0, Inf, NaN */
__attribute__((noinline)) float as_compoundf_special(float x, float y){
  b32u32_u nx = {.f = x}, ny = {.f = y};
  uint32_t ax = nx.u<<1, ay = ny.u<<1;

  if (__builtin_expect(ax == 0 || ay == 0, 0)) { // x or y is 0
    if (ax == 0)   // compound(0,y) = 1 except for y = sNaN
      return is_signalingf (y) ? x + y : 1.0f;

    if (ay == 0) { // compound (x, 0)
      if (is_signalingf (x)) return x + y; // x = sNaN
      if (x < -1.0f) {
#ifdef CORE_MATH_SUPPORT_ERRNO
        errno = EDOM;
#endif
        return 0.0f / 0.0f; // rule (g)
      }
      else
        return 1.0f; // rule (a)
    }
  }

  const b32u32_u mone = {.f = -1.0f};
  if(__builtin_expect (ay >= 0xffu<<24, 0)){ // y=Inf/NaN
    // the case x=0 was already checked above
    if(ax > 0xffu<<24) return x + y; // x=NaN
    if(ay == 0xffu<<24) { // y = +/-Inf
      if (nx.u > mone.u) return 0.0f / 0.0f; // rule (g)
      int sy = ny.u>>31; // sign bit of y
      if (nx.u == mone.u){
	if(sy == 0)
	  return 0.0f; // Rule (c)
	else
	  return 1.0f/0.0f; // Rule (b)
      }
      if (x < 0.0f){
	if(sy == 0)
	  return 0.0f;
	else
	  return 1.0f/0.0f;
      }
      if (x > 0.0f){
	if(sy != 0)
	  return 0.0f;
	else
	  return 1.0f/0.0f;
      }
      return 1.0f;
    }
    return x + y; // case y=NaN
  }

  // since we can't have -1 < x < 0, the following test is enough
  if (__builtin_expect (nx.u >= 0xffu<<23, 0)){
    // x is Inf, NaN or <= -1
    if (ax == 0xffu<<24){ // x is +Inf or -Inf
      if (nx.u>>31) return 0.0f / 0.0f; // x = -Inf, rule (g)
      // (1 + Inf)^y = +Inf for y > 0, +0 for y < 0
      return (ny.u>>31) ? 1.0f/x : x;
    }
    if (ax > 0xffu<<24) return x + y; // x is NaN
    if (nx.u > mone.u) {
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = EDOM;
#endif
      return 0.0f / 0.0f; // x < -1.0: rule (g)
    }
    // now x = -1
    if (ny.u>>31) { // y < 0
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE;
#endif
      return 1.0f/0.0f;
    } else // y > 0
      return 0.0f;
  }
  return 0.0f;
}

float cr_compoundf (float x, float y)
{
  /* Rules from IEEE 754-2019 for compound (x, n) with n integer:
     (a) compound (x, 0) is 1 for x >= -1 or quiet NaN
     (b) compound (-1, n) is +Inf and signals the divideByZero exception for n < 0
     (c) compound (-1, n) is +0 for n > 0
     (d) compound (+/-0, n) is 1
     (e) compound (+Inf, n) is +Inf for n > 0
     (f) compound (+Inf, n) is +0 for n < 0
     (g) compound (x, n) is qNaN and signals the invalid exception for x < -1
     (h) compound (qNaN, n) is qNaN for n <> 0.
  */
  const b32u32_u mone = {.f = -1.0f};
  b32u32_u nx = {.f = x}, ny = {.f = y};
  if (__builtin_expect(nx.u >= mone.u, 0) ) return as_compoundf_special(x,y); // x <= -1
  // now x > -1

  uint32_t ax = nx.u<<1, ay = ny.u<<1;
  if (__builtin_expect(ax == 0 || ax >= 0xffu<<24 || ay == 0 || ay >= 0xffu<<24, 0) ) return as_compoundf_special(x,y); // x=+-0 || x=+-inf/nan || y=+-0 || y=+-inf/nan

  double xd = x, yd = y;
  b64u64_u tx = {.f = xd}, ty = {.f = yd};

  volatile FLAG_T flag = get_flag ();
  double l;
  if (__builtin_expect (ax < 0x62000000u, 0)) { // |x| < 2^-29
    /* |log2(1+x) - 1/log(2) * (x - x^2/2)| < 2^-59.584 * |log2(1+x)|
       (cf compoundf.sollya) */
    double t = xd - (xd * xd) * 0.5;
    /* since x is representable in binary32, x*x is exact, and so is (x * x) * 0.5.
       Thus the only error in the computation of t is the final rounding, which
       is bounded by ulp(t): t = (x - x^2/2) * (1 + eps2) with |eps2| < 2^-52
    */
    l = INVLOG2 * t;
    /* since INVLOG2 = 1/log(2) * (1 + eps1) and
       and   t = (x - x^2/2) * (1 + eps2)
       let u = o(INVLOG2 * t) then u = INVLOG2 * t * (1 + eps3) with |eps3|<2^-53
       thus u = 1/log(2) * (x - x^2/2) * (1 + eps1)*(1 + eps2)*(1 + eps3)
       = 1/log(2) * (x - x^2/2) * (1 + eps4) with |eps4| < 2^-50.954
       Now Sollya says the relative error by approximating log2(1+x) by
       1/log(2) * (x - x^2/2) for |x| < 2^-29 is bounded by 2^-59.584
       (file compoundf.sollya), thus:
       u = log2(1+x) * (1+eps4)*(1+eps5) with |eps5| < 2^-59.584
       = log2(1+x) * (1+eps6) with |eps6| < 2^-50.950 */
  } else {
    l = _log2p1 (tx.f);
  }
  /* l approximates log2(1+x) with relative error < 2^-47.997,
     and 2^-149 <= |l| < 128 */

  b64u64_u t = {.f = l * ty.f};
  /* since 2^-149 <= |l| < 128 and 2^-149 <= |y| < 2^128, we have
     2^-298 <= |t| < 2^135, thus no underflow/overflow in double is possible.
     The relative error is bounded by (1+2^-47.997)*(1+2^-52)-1 < 2^-47.909 */

  // detect overflow/underflow
  if (__builtin_expect ((t.u << 1) >= (0x406ull<<53), 0)) { // |t| >= 128
    if (t.u >= 0x3018bull<<46) { // t <= -150
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // underflow
#endif
      return 0x1p-126f * 0x1p-126f;
    } else if (!(t.u >> 63)) { // t >= 128: overflow
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // overflow
#endif
      return 0x1p126f * 0x1p126f;
    }
  }

  /* since |t| < 150, the absolute error on t is bounded by
     150*2^-47.909 < 2^-40.680 */

  // 2^t rounds to 1 to nearest when |t| <= 0x1.715476af0d4d9p-25
  if (__builtin_expect ((t.u << 1) <= 0x7cce2a8ed5e1a9b2ull, 0))
    return (t.u >> 63) ? 1.0f - 0x1p-25f : 1.0f + 0x1p-25f;

  int midpoint = 0;
  int exact = is_exact_or_midpoint (x, y, &midpoint);

  float res = exp2_1 (t.f);
  if (__builtin_expect (res != -1.0f, 1))
  {
    if (exact && !midpoint)
      set_flag (flag); // restore flags
    return res;
  }

  /* we restore the flags, since exp2_1() might yield a spurious overflow,
     for example for x,y=0x1.59ff68p+71,0x1.cab692p+0 */
    set_flag (flag); // restore flags

  // fast path failed
  return accurate_path (x, y, exact, flag);
}

#ifndef SKIP_C_FUNC_REDEF // icx provides this function
/* just to compile since glibc does not contain this function */
float compoundf(float x, float y){
  return powf(1.0f+x,y);
}
#endif
