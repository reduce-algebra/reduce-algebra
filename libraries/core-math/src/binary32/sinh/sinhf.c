/* Correctly-rounded hyperbolic sine function for binary32 value.

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

float cr_sinhf(float x){
  static const double c[] =
    {1, 0x1.62e42fef4c4e7p-6, 0x1.ebfd1b232f475p-13, 0x1.c6b19384ecd93p-20};
  static const double ch[] =
    {1, 0x1.62e42fefa39efp-6, 0x1.ebfbdff82c58fp-13, 0x1.c6b08d702e0edp-20, 0x1.3b2ab6fb92e5ep-27,
     0x1.5d886e6d54203p-35, 0x1.430976b8ce6efp-43};
  static const uint64_t tb[] =
    {0x3fe0000000000000, 0x3fe059b0d3158574, 0x3fe0b5586cf9890f, 0x3fe11301d0125b51,
     0x3fe172b83c7d517b, 0x3fe1d4873168b9aa, 0x3fe2387a6e756238, 0x3fe29e9df51fdee1,
     0x3fe306fe0a31b715, 0x3fe371a7373aa9cb, 0x3fe3dea64c123422, 0x3fe44e086061892d,
     0x3fe4bfdad5362a27, 0x3fe5342b569d4f82, 0x3fe5ab07dd485429, 0x3fe6247eb03a5585,
     0x3fe6a09e667f3bcd, 0x3fe71f75e8ec5f74, 0x3fe7a11473eb0187, 0x3fe82589994cce13,
     0x3fe8ace5422aa0db, 0x3fe93737b0cdc5e5, 0x3fe9c49182a3f090, 0x3fea5503b23e255d,
     0x3feae89f995ad3ad, 0x3feb7f76f2fb5e47, 0x3fec199bdd85529c, 0x3fecb720dcef9069,
     0x3fed5818dcfba487, 0x3fedfc97337b9b5f, 0x3feea4afa2a490da, 0x3fef50765b6e4540};
  static const struct {union{float arg; uint32_t uarg;}; float rh, rl;} st[] = {
    {{.uarg = 0x74250bfeu}, 0x1.250bfep-11, 0x1p-36}
  };
  const double iln2 = 0x1.71547652b82fep+5;
  b32u32_u t = {.f = x};
  double z = x;
  uint32_t ux = t.u<<1;
  if(__builtin_expect(ux>0x8565a9f8u, 0)){ // |x| > 0x1.65a9f8p+6
    float sgn = __builtin_copysignf(2.0f, x);
    if(ux>=0xff000000u) {
      if(ux<<8) return x + x; // nan
      return sgn*1.0f/0.0f; // +-inf
    }
    float r = sgn*0x1.fffffep127f;
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE;
#endif
    return r;
  }
  if(__builtin_expect(ux<0x7c000000u, 0)){ // |x| < 0.125
    if(__builtin_expect(ux<=0x74250bfeu, 0)){ // |x| <= 0x1.250bfep-11
      if(__builtin_expect(ux<0x66000000u, 0)) { // |x| < 0x1p-24
#ifdef CORE_MATH_SUPPORT_ERRNO
        /* The Taylor expansion of sinh(x) at x=0 is x + x^3/6 + o(x^3),
           thus for |x| >= 2^-126 we have no underflow, whatever the
           rounding mode.
           For |x| < 2^-126 and rounding towards zero, we have underflow.
           For x = nextbelow(2^-126) = 0x1.fffffcp-127, sinh(x) would round
           upward to 0x1.fffffep-127 with unbounded exponent range, which is not
           representable, thus we have underflow too.
           In summary, we have underflow whenever |x| < 2^-126. */
        if (x != 0 && __builtin_fabsf (x) < 0x1p-126f)
          errno = ERANGE; // underflow
#endif
	return __builtin_fmaf(x, __builtin_fabsf(x), x);
      }
      if(__builtin_expect(st[0].uarg == ux, 0)){
	float sgn = __builtin_copysignf(1.0f, x);
	return sgn*st[0].rh + sgn*st[0].rl;
      }
      return (x*0x1.555556p-3f)*(x*x) + x;
    }
    static const double cp[] =
      {0x1.5555555555555p-3, 0x1.11111111146e1p-7, 0x1.a01a00930dda6p-13, 0x1.71f92198aa6e9p-19};
    double z2 = z*z, z4 = z2*z2;
    return z + (z2*z)*((cp[0] + z2*cp[1]) + z4*(cp[2] + z2*(cp[3])));
  }
  double a = iln2*z, ia = roundeven_finite(a), h = a - ia, h2 = h*h;
  b64u64_u ja = {.f = ia + 0x1.8p52};
  int64_t jp = ja.u, jm = -jp;
  b64u64_u sp = {.u = tb[jp&31] + ((uint64_t)(jp>>5)<<52)}, sm = {.u = tb[jm&31] + ((uint64_t)(jm>>5)<<52)};
  double te = c[0] + h2*c[2], to = (c[1] + h2*c[3]);
  double rp = sp.f*(te + h*to), rm = sm.f*(te - h*to), r = rp - rm;
  float ub = r, lb = r  - 1.52e-10*r;
  if(__builtin_expect(ub != lb, 0)){
    const double iln2h = 0x1.7154765p+5, iln2l = 0x1.5c17f0bbbe88p-26;
    h = (iln2h*z - ia) + iln2l*z;
    h2 = h*h;
    te = ch[0] + h2*ch[2] + (h2*h2)*(ch[4] + h2*ch[6]);
    to = ch[1] + h2*(ch[3] + h2*ch[5]);
    r = sp.f*(te + h*to) - sm.f*(te - h*to);
    ub = r;
  }
  return ub;
}
