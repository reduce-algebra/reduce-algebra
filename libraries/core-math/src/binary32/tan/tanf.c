/* Correctly-rounded tangent of binary32 value.

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

#include <stdint.h>
#include <fenv.h> // for feraiseexcept, FE_INVALID
#include <errno.h>

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

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

typedef union {float f; uint32_t u;} b32u32_u;
typedef union {double f; uint64_t u;} b64u64_u;
#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif
typedef uint64_t u64;


// argument reduction
// for |z| < 2^28, return r such that 2/pi*x = q + r
static inline double rltl(float z, int *q){
  double x = z;
  /* The constants in idh, idl approximate 2/pi. Since idh is representable
     on 28 bits, and x on 24 bits, idh is exact */
  double idl = -0x1.b1bbead603d8bp-32*x, idh = 0x1.45f306ep-1*x, id = roundeven_finite(idh);
  *q = (int64_t)id;
  return (idh - id) + idl;
}

// argument reduction
// same as rltl, but for |x| >= 2^28
static double __attribute__((noinline)) rbig(uint32_t u, int *q){
  static const u64 ipi[] = {0xfe5163abdebbc562, 0xdb6295993c439041, 0xfc2757d1f534ddc0, 0xa2f9836e4e441529};
  int e = (u>>23)&0xff, i;
  u64 m = (u&(~0u>>9))|1<<23;
  u128 p0 = (u128)m*ipi[0];
  u128 p1 = (u128)m*ipi[1]; p1 += p0>>64;
  u128 p2 = (u128)m*ipi[2]; p2 += p1>>64;
  u128 p3 = (u128)m*ipi[3]; p3 += p2>>64;
  u64 p3h = p3>>64, p3l = p3, p2l = p2, p1l = p1;
  int64_t a;
  int k = e-127, s = k-23;
  /* in cr_tanf(), rbig() is called in the case 127+28 <= e < 0xff
     thus 155 <= e <= 254, which yields 28 <= k <= 127 and 5 <= s <= 104 */

  if (s<64) {
    i = p3h<<s|p3l>>(64-s);
    a = p3l<<s|p2l>>(64-s);
  } else if(s==64) {
    i = p3l;
    a = p2l;
  } else { /* s > 64 */
    i = p3l<<(s-64)|p2l>>(128-s);
    a = p2l<<(s-64)|p1l>>(128-s);
  }
  int sgn = u; sgn >>= 31;
  int64_t sm = a>>63;
  i -= sm;
  double z = (a^sgn)*0x1p-64;
  i = (i^sgn) - sgn;
  *q = i;
  return z;
}

float cr_tanf(float x){
  b32u32_u t = {.f = x};
  int e = (t.u>>23)&0xff, i;
  double z;
  if (__builtin_expect(e<127+28, 1)){ // |x| < 2^28
    if (__builtin_expect(e<115, 0)){ // |x| < 2^-13
      if (__builtin_expect(e<102, 0)) { // |x| < 2^-26
#ifdef CORE_MATH_SUPPORT_ERRNO
        /* The Taylor expansion of tan(x) at x=0 is x + x^3/3 + o(x^3),
           thus for |x| >= 2^-126 we have no underflow, whatever the
           rounding mode.
           For |x| < 2^-126 and rounding towards zero, we have underflow.
           For x = nextbelow(2^-126) = 0x1.fffffcp-127, tan(x) would round
           upward to 0x1.fffffep-127 with unbounded exponent range, which is
           not representable, thus we have underflow too.
           In summary, we have underflow whenever |x| < 2^-126. */
        if (x != 0 && __builtin_fabsf (x) < 0x1p-126f)
          errno = ERANGE; // underflow
#endif
	return __builtin_fmaf(x, __builtin_fabsf(x), x);
      }
      float x2 = x*x;
      return __builtin_fmaf(x, 0x1.555556p-2f*x2, x);
    }
    z = rltl(x, &i);
  } else if (e<0xff){
    z = rbig(t.u, &i);
  } else {
    if(t.u<<9) return x + x; // nan
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = EDOM;
#endif
    feraiseexcept(FE_INVALID);
    return __builtin_nanf("tinf"); // inf
  }
  double z2 = z*z, z4 = z2*z2;
  static const double cn[] = {0x1.921fb54442d18p+0, -0x1.fd226e573289fp-2, 0x1.b7a60c8dac9f6p-6, -0x1.725beb40f33e5p-13};
  static const double cd[] = {0x1p+0, -0x1.2395347fb829dp+0, 0x1.2313660f29c36p-3, -0x1.9a707ab98d1c1p-9};
  static const double s[] = {0, 1};
  double n = cn[0] + z2*cn[1], n2 = cn[2] + z2*cn[3]; n += z4*n2;
  double d = cd[0] + z2*cd[1], d2 = cd[2] + z2*cd[3]; d += z4*d2;
  n *= z;
  double s0 = s[i&1], s1 = s[1-(i&1)];
  double r1 = (n*s1 - d*s0)/(n*s0 + d*s1);
  b64u64_u tr = {.f = r1};
  u64 tail = (tr.u + 7)&(~(uint64_t)0>>35);
  if(__builtin_expect(tail<=14, 0)){
    static const struct {union{float arg; uint32_t uarg;}; float rh, rl;} st[] = {
      {{0x1.143ec4p+0f}, 0x1.ddf9f6p+0f, -0x1.891d24p-52f},
      {{0x1.ada6aap+27f}, 0x1.e80304p-3f, 0x1.419f46p-58f},
      {{0x1.af61dap+48f}, 0x1.60d1c8p-2f, -0x1.2d6c3ap-55f},
      {{0x1.0088bcp+52f}, 0x1.ca1edp+0f, 0x1.f6053p-53f},
      {{0x1.f90dfcp+72f}, 0x1.597f9cp-1f, 0x1.925978p-53f},
      {{0x1.cc4e22p+85f}, -0x1.f33584p+1f, 0x1.d7254ap-51f},
      {{0x1.a6ce12p+86f}, -0x1.c5612ep-1f, -0x1.26c33ep-53f},
      {{0x1.6a0b76p+102f}, -0x1.e42a1ep+0f, -0x1.1dc906p-52f},
    };
    uint32_t ax = t.u&(~0u>>1), sgn = t.u>>31;
    for(int j=0;j<8;j++) {
      if(__builtin_expect(st[j].uarg == ax, 0)){
	if(sgn)
	  return -st[j].rh - st[j].rl;
	else
	  return  st[j].rh + st[j].rl;
      }
    }
  }
  return r1;
}
