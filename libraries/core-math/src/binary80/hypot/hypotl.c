/* Correctly rounded hypotl function for binary80 values.

Copyright (c) 2025 Alexei Sibidanov and Paul Zimmermann

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

/* This code assumes "long double" corresponds to the 80-bit double extended
   format.
*/

#include <stdint.h>
#include <fenv.h> // for fexcept_t, fegetexceptflag, FE_INEXACT
#include <errno.h>

#if (defined(__clang__) && __clang_major__ >= 14) || (defined(__GNUC__) && __GNUC__ >= 14 && __BITINT_MAXWIDTH__ && __BITINT_MAXWIDTH__ >= 128)
typedef unsigned _BitInt(128) u128;
#else
typedef unsigned __int128 u128;
#endif

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

// return non-zero iff x is a NaN (assuming x_exp = 0x4000)
inline static int
is_nan (b80u80_t s)
{
  int e = s.e;
  uint64_t m = s.m;
  return (e & 0x7fff) == 0x7fff && (m << 1) != 0;
}

// return non-zero iff x is a sNaN (assuming x_exp = 0x4000)
inline static int
is_snan (b80u80_t s)
{
  int e = s.e;
  uint64_t m = s.m;
  m = m << 1; // discard bit 63
  return (e & 0x7fff) == 0x7fff && m != 0 && (m >> 63) == 0;
}

/* The algorithm is as follows:
   - first swap x and y if |x| < |y| (where NaN > Inf > normal number)
   - then deal with x or y being NaN or Inf
   - if x or y is subnormal, normalize their significands mx and my
     so that 2^63 <= mx, my < 2^64
   - compute the exponent difference d = x_exp - y_exp
   - if d >= 32, we deduce directly the correct rounding
   - otherwise we compute two 128-bit integers hh and ll
     such that hh*2^128 + ll = mx^2 + (my/d)^2
   - deal with overflow
   - compute a 64-bit integer approximation th of sqrt(hh) by first
   - in the subnormal case, shift right hh, ll and th so that the last
     significant bit of th corresponds to 2^-16445 (smallest subnormal)
   - compute the remainder r = hh - th^2, and adjust it and th so that
     0 <= r < 2th+1, thus th = floor(sqrt(hh))
   - if r=0 and ll=0, we are in the exact case, restore the inexact flag
   - return th or th+1 (with appropriate exponent) according to the rounding
     mode
*/
long double
cr_hypotl (long double x, long double y)
{
  // save the inexact flag
  fexcept_t flag;
  fegetexceptflag (&flag, FE_INEXACT);

  b80u80_t sx = {.f = x}, sy = {.f = y};

  int x_exp = (sx.e & 0x7fff) - 0x3fff;
  int y_exp = (sy.e & 0x7fff) - 0x3fff;

  if (x_exp - y_exp - (sx.m < sy.m) < 0) // swap x and y
  {
    uint64_t m = sx.m;
    sx.m = sy.m;
    sy.m = m;
    int e = sx.e;
    sx.e = sy.e;
    sy.e = e;
    int t = x_exp;
    x_exp = y_exp;
    y_exp = t;
  }

  // now x_exp > y_exp or (x_exp == y_exp and sx.m >= sy.m)

  if (__builtin_expect (x_exp == 0x4000, 0)) {
    // x or y is NaN or Inf
    /* According to IEEE 754-2019:
       hypot(±Inf, qNaN) is +Inf
       hypot(qNaN, ±Inf) is +Inf */
    if (is_snan (sx) || is_snan (sy))
      return sx.f + sy.f;
    if (is_nan (sx) || is_nan (sy)) {
      if (is_nan (sx) && is_nan (sy)) // x = y = qNaN
        return sx.f + sy.f;
      // now one is qNaN and the other is either Inf or a normal number
      if (x_exp != 0x4000 || y_exp != 0x4000) // x or y is not qNaN/Inf
        return sx.f + sy.f;
    }
    // now neither x nor y is sNaN, at least one is Inf
    return (sx.m == 0x8000000000000000ull) ? sx.f * sx.f : sy.f * sy.f;
  }

  uint64_t mx = sx.m, my = sy.m;

  if (__builtin_expect (y_exp == -0x3fff, 0)) { // y is 0 or subnormal
    if (__builtin_expect (my == 0, 0)) // y = 0
    {
      /* hypot(±0, ±0) is +0 */
      if (x_exp == -0x3fff && mx == 0){
        return +0.0L;
      }
      else // hypot(x,0) = |x|
      {
        sx.e &= 0x7fff; // clear sign bit
        return sx.f;    // |x|
      }
    }

    // normalize y
    int k = __builtin_clzll (my);
    my <<= k;
    y_exp -= k - 1;
    if (x_exp == -0x3fff) // x is subnormal too
    {
      k = __builtin_clzll (sx.m); // x cannot be 0
      mx <<= k;
      x_exp -= k - 1;
    }
  }

  // now x = mx * 2^(x_exp-63) and y = my * 2^(y_exp-63)

  int d = x_exp - y_exp;
  /* assume without loss of generality x = m with 2^63 <= m < 2^64,
     thus ulp(x) = 1, then if x^2+y^2 < (m+1/2)^2,
     hypot(x,y) rounds to m for rounding to nearest.
     This simplifies to y^2 < m+1/4.
     If d > 32, this is always true since y = my/2^d with my < 2^64,
     thus y^2 < 2^128/2^(2d) <= 2^62 < m.
     If d < 32, this is always false since y = my/2^d with my >= 2^63,
     thus y^2 >= 2^126/2^62 = 2^64 > m+1/4.
  */
  if (d >= 32) { // hypot(x,y) = |x| or nextabove(|x|)
    double z = 1.0;
    if (d == 32) {
      u128 yy = (u128) my * (u128) my;
      uint64_t h = yy >> 64, l = yy, m = mx;
#define ONE_FOURTH 0x4000000000000000ull
      /* The midpoint case l == ONE_FOURTH and m odd cannot happen,
         since if m + 1/4 = y^2 with y = k + 1/2, then y^2 = k^2 + k + 1/4
         thus m = k^2+k is always even.
         However, if x is subnormal (x_exp < -16382), then if d==32 we have
         y_exp < -16414, thus x^2 + y^2 < (x + u/2)^2 where u = 2^-16445.
         Then when x is subnormal we never round upwards for rounding to
         nearest. */
      if (x_exp >= -16382 && (h > m || (h == m && l > ONE_FOURTH)))
        z = 0x1.0000000000001p+0; // z + 0x1p-53 will round upwards for RNDN
      // else y^2 < m+1/4: z + 0x1p-53 will round downwards for RNDN
    }
    sx.e &= 0x7fff; // clear sign bit
    if (z + 0x1p-53 > z) // raises inexact, but result is inexact anyway
    {
      sx.m ++;
      if (__builtin_expect (sx.m == 0, 0)) // overflow case
      {
        // in case sx.e = 0x7ffe, this will round to +Inf as wanted
        sx.e ++;
        sx.m = 0x8000000000000000ull;
	feraiseexcept (FE_OVERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
	errno = ERANGE; // overflow
#endif
      }
    }
    if (sx.e == 0) // subnormal case, result is always inexact
    {
      feraiseexcept (FE_UNDERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // underflow
#endif
    }
    return sx.f;
  }

  // now 0 <= d < 32
  int dd = d + d; // 0 <= dd < 64
  u128 xx = (u128) mx * (u128) mx;
  u128 yy = (u128) my * (u128) my;
  u128 hh = xx + (yy >> dd);
  u128 ll = (dd > 0) ? yy << (128 - dd) : 0;
  // since dd <= 62, the low 66 bits of ll should be 0
  if (hh < xx) { // overflow
    ll = (hh << 126) | (ll >> 2);
    hh = (((u128) 1) << 126) | (hh >> 2);
    x_exp ++;
    // since ll was shifted by 2 to the right, its low 64 bits are 0
  }
  // sqrt(x^2 + y^2) = sqrt (hh + ll/2^128) * 2^(x_exp-63)
  // with 2^126 <= hh < 2^128 thus sqrt(x^2 + y^2) >= 2^x_exp

  if (__builtin_expect (x_exp >= 0x3fff, 0)) { // potential overflow
#define HUGE 0x1.fffffffffffffffep+16383L
    if (x_exp >= 0x4000) { // sure overflow
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // overflow
#endif
      return HUGE + HUGE;
    }
    // now x_exp = 0x3fff
    u128 HT, LT;
    switch (fegetround ()) {
    case FE_TONEAREST: // threshold is (2^64-1/2)^2
      HT = ((u128) 0xffffffffffffffffull) << 64;
      LT = (u128) 1 << 126;
      break;
    case FE_UPWARD: // threshold is (2^64-1)^2
      HT = (((u128) 0xfffffffffffffffeull) << 64) + 1;
      LT = 0;
      break;
    default: // FE_DOWNWARD and FE_TOWARDZERO: threshold is (2^64)^2
      HT = LT = ~ (u128) 0;
      // since the low 64 bits of ll are zero, we can't have hh=HT and ll=LT
    }
    // we have overflow iff hh*2^128+ll >= HT*2^128+LT
    if (hh > HT || (hh == HT && ll >= LT)) {
      long double res = HUGE + 0x1p+16319L; // add 1/2 ulp(HUGE)
#ifdef CORE_MATH_SUPPORT_ERRNO
      /* We have overflow:
       * for RNDZ or RNDD: never
       * for RNDN: when res = +Inf
       * for RNDU: always */
      if (res > 0x1.fffffffffffffffep+16383L)
	errno = ERANGE; // overflow
#endif
      return res;
    }
  }

  // now sqrt(x^2 + y^2) < 2^16384*(1-2^-65)

  // use sqrtl to compute a 64-bit approximation of sqrt(hh)
  b80u80_t z;
  int high = hh >> 127;
  z.m = hh >> (63 + high); // upper 64 bits from hh
  z.e = 16509 + high;      // ensure 2^126 <= z < 2^128
  z.f = __builtin_sqrtl (z.f);
  u128 th = z.m;
  /* Warning: for RNDU, z.f might be rounded to 2^64, in which case
     z.e = 16447 instead of 16446 as expected. */
  if (__builtin_expect (z.e > 16446, 0))
    // we should have z.e = 16447 and th = 2^63
    th = th << 1;

  /* sqrt(x^2+y^2) ~ th * 2^(x_exp - 63) with 2^63 <= th < 2^64
     thus 2^x_exp <= sqrt(x^2+y^2) < 2^(x_exp + 1)
     and since the smallest normal is 2^-16382,
     we are in the subnormal case when x_exp < -16382 = -0x3ffe */
  if (__builtin_expect (x_exp < -0x3ffe, 0)) // subnormal case
  {
    int k = -0x3ffe - x_exp; // we should have k < 64
    // shift right hh and ll by 2k bits, and th by k bits
    th >>= k;
    ll = (hh << (128 - 2 * k)) | (ll >> (2 * k));
    hh = hh >> (2 * k);
    x_exp += k - 1; // -1 due to exponent shift for subnormals
  }

  // compute r = hh - th^2
  u128 r = hh - th * th;
  if ((r >> 127) != 0) // th too large
  {
    // th -> th-1 thus r -> r + 2*th - 1
    r += 2 * th - 1;
    th --;
  }
  // if th was too large, then r < 2th+1 now, thus using "else" is ok
  else if (r >= 2 * th + 1) // th too small
  {
    // th -> th+1, thus r -> r - 2*th - 1
    r -= 2 * th + 1;
    th ++;
  }
  // invariant: r = hh - th^2

  int exact = 0;
  if (__builtin_expect (r == 0 && ll == 0, 0)) // exact case
  {
    // restore the inexact flag
    fesetexceptflag (&flag, FE_INEXACT);
    exact = 1;
  }

  double eps = 0x1p-53;

  /* In the midpoint case, we have hh + ll = (th+1/2)^2 thus
     r = th and ll = 2^126. */
  const u128 thres = (u128) 1 << 126;
  if (r > th || (r == th && (ll > thres || (ll == thres && (th & 1)))))
    // for RNDN we should round upward
    eps = 0x1.8p-53;

  b80u80_t res = {.m = th, .e = x_exp + 0x3fff};
  int underflow = res.e == 0;
  if (!exact && 1.0 + eps > 1.0) {
    /* 1.0 + eps rounds to nextabove(1) either for RNDU (whatever the value
       of eps) and for RNDN when eps = 0x1.8p-53 */
    res.m ++;
    /* when res.e = 0 (subnormal) and m becomes 2^63 (normal) this is exactly
       what we want, but then we have no underflow for RNDU when
       hypot(x,y) >= (th+1/2)^2, which corresponds to r = th and ll = 2^126,
       and for RNDN when hypot(x,y) >= (th+3/4)^2, which corresponds to
       r = 0xbfffffffffffffff and ll = 2^112. */
    if (__builtin_expect (res.e == 0 && th == 0x7fffffffffffffffull, 0)) {
      if (1.0 + 0x1p-53 == 1.0) { // to nearest
        const u128 thres_r = 0xbfffffffffffffffull;
        const u128 thres_ll = (u128) 1 << 112;
        if (r > thres_r || (r == thres_r && ll >= thres_ll))
          underflow = 0;
      }
      if (1.0 + 0x1p-53 > 1.0) // RNDU
        /* to r = th and ll = 2^126 is exactly the same threshold than for
           rounding upwards for RNDN, since we know th is odd */
        if (eps == 0x1.8p-53)
          underflow = 0;
    }
    if (res.m == 0) // change of binade
    {
      res.e ++;
      res.m = (uint64_t) 1 << 63;
    }
  }

  if (underflow && !exact) {
    feraiseexcept (FE_UNDERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
    errno = ERANGE; // underflow
#endif
  }

  return res.f;
}
