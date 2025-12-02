/* Correctly rounded cbrt function for long-double values.

Copyright (c) 2024 Alexei Sibidanov and Paul Zimmermann

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
   [1] Note on the Veltkamp/Dekker Algorithms with Directed Roundings,
       Paul Zimmermann, https://inria.hal.science/hal-04480440, February 2024.
   [2] CR-LIBM A library of correctly rounded elementary functions in
       double-precision, Catherine Daramy-Loirat, David Defour, Florent de
       Dinechin, Matthieu Gallet, Nicolas Gast, Christoph Lauter, Jean-Michel
       Muller, https://ens-lyon.hal.science/ensl-01529804, 2017.
   [3] Handbook of Floating-Point Arithmetic, Jean-Michel Muller, Nicolas
       Brunie, Florent de Dinechin, Claude-Pierre Jeannerod, Mioara Joldes,
       Vincent Lefèvre, Guillaume Melquiond, Nathalie Revol, Serge Torres,
       2018.
 */

#include <stdint.h>
#include <fenv.h> // for fexcept_t, fegetexceptflag, FE_INEXACT

#ifdef __x86_64__
#include <x86intrin.h>
#endif

#if defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
#define FLAG_T uint32_t
#else
#define FLAG_T fexcept_t
#endif

// This code emulates the _mm_getcsr SSE intrinsic by reading the FPCR register.
// fegetexceptflag accesses the FPSR register, which seems to be much slower
// than accessing FPCR, so it should be avoided if possible.
// Adapted from sse2neon: https://github.com/DLTcollab/sse2neon
#if (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
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
#endif  // (defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)

/* Note that on x86, the x87 FPU has its own set of flags, which would need
to be backed up and restored separately if we touched them. However, the
code below preserves them, except when we know we won't need to restore them
in such that a way that only saving the SSE status register is enough.
*/
static FLAG_T
get_flag_quick (void)
{
#if(defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  return _mm_getcsr ();
#else
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT);
  return flag;
#endif
}

static void
set_flag_quick (FLAG_T flag)
{
#if(defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)) && !defined(__aarch64__)
  _mm_setcsr (flag);
#else
  fesetexceptflag (&flag, FE_ALL_EXCEPT);
#endif
}

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// anonymous structs, see https://port70.net/~nsz/c/c11/n1570.html#6.7.2.1p19
typedef union {
  long double f;
  struct __attribute__((__packed__))
  {uint64_t m; uint32_t e:16; uint32_t empty:16;};
} b96u96_u;

typedef union {double f; uint64_t u;} b64u64_u;
typedef union {float f; uint32_t u;} b32u32_u;

/* s + t <- a + b, assuming |a| >= |b| */
static inline void
fast_two_sum (long double *s, long double *t, long double a, long double b)
{
  *s = a + b;
  long double e = *s - a;
  *t = b - e;
}

// Veltkamp's splitting: split x into xh + xl such that
// x = xh + xl exactly
// xh fits in 32 bits and |xh| <= 2^e if 2^(e-1) <= |x| < 2^e
// xl fits in 32 bits and |xl| < 2^(e-32)
// See reference [1].
static inline void
split (long double *xh, long double *xl, long double x)
{
  static const long double C = 0x1.00000001p+32L;
  long double gamma = C * x;
  long double delta = x - gamma;
  *xh = gamma + delta;
  *xl = x - *xh;
}

/* Dekker's algorithm: rh + rl = u * v
   Reference: Algorithm Mul12 from reference [2], pages 21-22.
   See also reference [3], Veltkamp splitting (Algorithm 4.9) and
   Dekker's product (Algorithm 4.10).
   The Handbook only mentions rounding to nearest, but Veltkamp's and
   Dekker's algorithms also work for directed roundings.
   See reference [1].
*/
static inline void
a_mul (long double *rh, long double *rl, long double u, long double v)
{
  long double u1, u2, v1, v2;
  split (&u1, &u2, u);
  split (&v1, &v2, v);
  *rh = u * v;
  *rl = (((u1 * v1 - *rh) + u1 * v2) + u2 * v1) + u2 * v2;
}

// Multiply exactly a and b, such that *hi + *lo = a * b.
static inline void a_mul_double (double *hi, double *lo, double a, double b) {
  *hi = a * b;
  *lo = __builtin_fma (a, b, -*hi);
}

// Return in hi+lo a 128-bit approximation of (ah + al) * (bh + bl)
static inline void
d_mul (long double *hi, long double *lo, long double ah, long double al,
       long double bh, long double bl) {
  a_mul (hi, lo, ah, bh); // exact
  *lo += ah * bl;
  *lo += al * bh;
}

// Returns (ah + al) * (bh + bl) - (al * bl)
// We can ignore al * bl when assuming al <= ulp(ah) and bl <= ulp(bh)
static inline void d_mul_double (double *hi, double *lo, double ah, double al,
                                 double bh, double bl) {
  double s, t;

  a_mul_double (hi, &s, ah, bh);
  t = __builtin_fma (al, bh, s);
  *lo = __builtin_fma (ah, bl, t);
}

static inline void fast_two_sum_double(double* h, double* l,
double a, double b) {
	*h = a + b;
	double e = *h - a;
	*l = b - e;
}

/* Return err, and update h,l,e such that (h+l)*2^exp is an an approximation
   of |x|^(1/3) with absolute error less than err*2^exp. */
static void 
fast_path (double *h, double *l, int *exp, long double x)
{
  b96u96_u v = {.f = x};
  int e = v.e & 0x7fff; // 0 <= e < 32767
  uint64_t m = v.m;
  if (e == 0) // subnormal
  {
    int k = __builtin_clzll (m);
    v.m = m << k;
    e -= k - 1;
  }
  // now x = (m/2^63)*2^(e-16383) with 2^63 <= m < 2^64
  v.e = 16383; // reduce v.f in [1,2)
  int i = (e + 63) % 3; // we add 63 since e can be negative
  *exp = ((e + 63) / 3) - 5482;
  // cbrt(x) = (-1)^s * cbrt(m/2^63) * 2^e * 2^(i/3)
  // split x into xh + xl (rounding towards zero)
  b64u64_u xhu = {.u = (v.m>>11)+((int64_t)0x3fe<<52)},
           xlu = {.u = (v.m<<53)>>12|((int64_t)0x3ff-52)<<52};
  static const double off = 0x1p-52;
  double xh = xhu.f, xl = xlu.f - off;

  /* the polynomial c0+c1*x+...+c5*x^5 approximates x^(1/3) on [1,2] with
     absolute error bounded by 2^-19.473 (cf cbrt.sollya) */
  static const double c[] = {0x1.e53b7c444f1cep-2, 0x1.ac2d3134803e2p-1,
                             -0x1.ddcd3b46e2071p-2, 0x1.9b95b5c19bd0bp-3,
                             -0x1.97bd99b63f65ep-5, 0x1.592445ed9c63ap-8};
  double xx = xh * xh;
  double r = 1.0 / xh;
  double x4 = __builtin_fma (c[5], xh, c[4]);
  double x2 = __builtin_fma (c[3], xh, c[2]);
  double x0 = __builtin_fma (c[1], xh, c[0]);
  x2 = __builtin_fma (x4, xx, x2);
  x0 = __builtin_fma (x2, xx, x0);
  // x0 approximates cbrt(xh) with absolute error < 2^-19.473
  double h0 = __builtin_fma (x0 * x0, x0, -xh) * r;
  /* Note: all ulp() below are for a precision of 53 bits (binary64).
     Write a = x, and x0 = a^(1/3) + e0, with |e0| < 2^-19.473.
     Then x0^3 - a = 3*a^(2/3)*e0 + 3*a^(1/3)*e0^2 + e0^3.
     Ignoring rounding errors, we have:
     h0 = (x0^3-a)/a = 3*a^(-1/3)*e0 + f with |f|=|(3*a^(1/3)*e0^2 + e0^3)/a|.
     The maximum of (3*a^(1/3)*e0^2 + e0^3)/a is attained at a=1, thus
     |f| < 2^-37.36. Since |h0| < 2^-17, ulp(h0) <= 2^-70, the difference
     between |(3*a^(1/3)*e0^2 + e0^3)/a| and 2^-37.36 is more than 4e6 ulp(h0),
     thus the bound 2^-37.36 clearly includes the rounding errors. */

#define MINUS_ONE_THIRD -0x1.5555555555555p-2
  double x1 = __builtin_fma (x0 * h0, MINUS_ONE_THIRD, x0);
  /* x0*h0/3 = (a^(1/3) + e0) * (a^(-1/3)*e0 + f/3)
             = e0 + a^(1/3)*f/3 + a^(-1/3)*e0^2 + e0*f/3
     Ignoring rounding errors, the maximum of a^(1/3)*f/3 + a^(-1/3)*e0^2
     + e0*f/3 is attained at a=2, thus:
     x0*h0/3 = e0 - e1 with |e1| < 2^-37.90.
     Thus x1 = a^(1/3) + e1 with |e1| < 2^-37.90.
     Since |x0*h0/3| < 2^-19, ulp(x0*h0/3) <= 2^-72, the difference between
     |a^(1/3)*f/3 + a^(-1/3)*e0^2 + e0*f/3| and 2^-37.90 is more than
     9e7 ulp(x0*h0/3), thus the bound 2^-37.90 clearly includes the
     rounding errors. */

  double th, tl;
  a_mul_double (&th, &tl, x1, x1); // x1^2 = th + tl
  double h1 = __builtin_fma (th, x1, -xh);
  double h1l = __builtin_fma (tl, x1, -xl);
  h1 = (h1 + h1l) * r;
  /* Since x1 = a^(1/3) + e1 with |e1| < 2^-37.90, |h1| < 2^-35.64
     (this bound is attained in a=2, for x1 = a^(1/3) + 2^-37.90).
     Since h1 is a correction term, we can compute it in double precision only.
     Ignoring rounding errors again, we have:
     h1 = (x1^3-a)/a = 3*a^(-1/3)*e1 + f', |f'| := |(3*a^(1/3)*e1^2 + e1^3)/a|.
     The maximum of (3*a^(1/3)*e1^2 + e1^3)/a is attained at a=1, thus
     |f'| < 2^-74.21.
     Now let us analyze rounding errors:
     * a_mul_double is exact, thus there is no rounding error
     * the rounding error in h1 is bounded by ulp(h1).
       Since |h1| < |3*a^(-1/3)*e1 + f'| < 2^-36, ulp(h1) <= 2^-89.
       This error is multiplied by r with |r| <= 1 thus contributes to
       at most 2^-89 in h1.
     * the rounding error in h1l is bounded by ulp(h1l).
       We have |tl| <= ulp(th), where |th| <= x1^2 < 2, thus
       |tl| <= ulp(th) <= 2^-52.
       Since |x1| < 2, this yields |tl*x1| < 2^-51.
       Now |xl| <= ulp(xh) <= 2^-52, thus |h1l| < 2^-51+2^-52, and the
       rounding error on tl is bounded by ulp(2^-51+2^-52) = 2^-103.
       This error is multiplied by r with |r| <= 1 thus contributes to at
       most 2^-103 in h1.
     * |h1 + h1l| < |3*a^(-1/3)*e1 + f' + 2^-51+2^-52| < 2^-36, thus the
       rounding error on h1 + h1l is bounded by ulp(2^-37) = 2^-89, and is
       multiplied by r with |r| <= 1 thus contributes to at most 2^-89 in h1.
     * |(h1 + h1l) * r| < 2^-36, thus the rounding error in the product is
       bounded by ulp(2^-37) = 2^-89.
     The contribution of the rounding errors is thus bounded by:
     2^-89 + 2^-103 + 2^-89 + 2^-89 < 2^-87.41. This is much smaller than
     the difference between (3*a^(1/3)*e1^2 + e1^3)/a and the bound 2^-74.21,
     thus this bound covers also rounding errors. */

  /* x1*h1/3 = (a^(1/3) + e1) * (a^(-1/3)*e1 + f'/3)
             = e1 + a^(1/3)*f'/3 + a^(-1/3)*e1^2 + e1*f'/3
     The maximum of a^(1/3)*f'/3 + a^(-1/3)*e1^2 + e1*f'/3 is attained at a=2,
     thus: x1*h1/3 = e1 - e2 with |e2| < 2^-74.75.
     Thus x1 - x1*h1/3 = a^(1/3) + e2 with |e2| < 2^-74.75. */

  double corr = (x1 * h1) * MINUS_ONE_THIRD;
  /* Here we have two rounding errors:
     (a) the rounding error on x1 * h1. Since |x1| < 2 and |h1| < 2^-36,
         |x1*h1| < 2^-35 thus this rounding error is bounded by
         ulp(2^-36) = 2^-88. This rounding error is multiplied by
         MINUS_ONE_THIRD thus contributes to at most
         2^-88 * |MINUS_ONE_THIRD| < 2^-89.58.
     (b) the rounding error on w * MINUS_ONE_THIRD where w = RND(x1*h1).
         Since |w| < 2^-35 and |MINUS_ONE_THIRD| < 1/2, we have |corr| < 2^-36,
         thus this rounding error is bounded by ulp(corr) <= 2^-89.
     The sum (a) + (b) is thus bounded by 2^-89.58 + 2^-89 < 2^-88.26.
     This yields a total error bound for x1 + corr of:
     2^-74.75 + 2^-88.26 < 2^-74.749.
   */

  /* multiply (x1,corr) by 2^(i/3): sh[i]+sl[i] is a double-double
     approximation of 2^(i/3) */
  static const double sh[] = {1.0, 0x1.428a2f98d728bp+0, 0x1.965fea53d6e3dp+0};
  static const double sl[] = {0.0, -0x1.ddc22548ea41ep-56, -0x1.f53e999952f09p-54};
  d_mul_double (&x1, &corr, x1, corr, sh[i], sl[i]);

	fast_two_sum_double(h, l, x1, corr);

/*
  // err[i] is a bound for 2^-74.749*2^(i/3)
  static const double err[] = {0x1.31p-75, 0x1.80p-75, 0x1.e4p-75};
  return err[i];*/
}

// round h to nearest to precision 22 bits
static long double
round22 (long double h)
{
  b96u96_u v = {.f = h};
  uint64_t m = v.m;
  m = (m + 0x20000000000ul) & 0xfffffc0000000000ul;
  if (m == 0)
  {
    m = (uint64_t)1 << 63;
    v.e ++;
  }
  v.m = m;
  return v.f;
}

// (h+l)*2^e is the approximation from the fast path
__attribute__((cold))
static long double
accurate_path (long double h, long double l, int e, long double x, fexcept_t flagp)
{
  /* Since the fast path delivers an approximation with about 75-bit accuracy,
     it suffices to perform one step of Newton's iteration:
     (1) letting x2 = h + l, first compute the error e2 = (x2^3 - x) / x
     (2) then compute x3 = x2 - x2*e2/3
  */

  /* Rescale x so that 1 <= x < 8. With x' = 2^(-3e)*x, we have 1 <= x' < 8
     and h+l is an approximation of cbrt(x'), thus 1 <= h+l <= 2. */
  x = __builtin_ldexpl (x, -3 * e);

  // detect exact cases
  long double t = round22 (h);
  if (t * t * t == x){
    // restore inexact flag
    fesetexceptflag (&flagp, FE_INEXACT);
    return __builtin_ldexpl (t, e);
  }

  // normalize h+l
  fast_two_sum (&h, &l, h, l);

  long double yh, yl;
  // compute yh+yl = (h+l)^3
  d_mul (&yh, &yl, h, l, h, l);
  d_mul (&yh, &yl, yh, yl, h, l);
  // subtract x and normalize
  yh = yh - x;
  yh = yh + yl;
  /* since we had a 75-bit accurate approximation, |yh| should be bounded
     by 2^-75 thus working with a single long double is enough */
  yh = yh / x; // approximates ((h+l)^3 - x) / x

  // multiply yh by h
  yh = yh * h;
  // divide by -3
#define MINUS_ONE_THIRD_L -0x1.5555555555555556p-2L
  yh = yh * MINUS_ONE_THIRD_L;
  // add to lower term
  l += yh;

#define EXCEPTIONS 10
  static const long double exceptions[EXCEPTIONS][3] = {
    { 0x1.0dbd07c3a0effc3cp+0L, 0x1.047ff9c4763635f4p+0L, -0x1.0d01be7c7ddff78p-125L },
    { 0x1.345f2e864d24dc48p+0L, 0x1.1062d441bcb66ac6p+0L, -0x1.25760941fbabef0ap-126L },
    { 0x1.39bccadcdf06cf52p+0L, 0x1.11f4f1c51a59cf1cp+0L, -0x1.127fbd1eec03180cp-127L },
    { 0x1.5ab3b8cd6331f996p+0L, 0x1.1b3be9d3a867aed2p+0L, -0x1.b9f3f168683e9cp-126L },
    { 0x1.49aeac6ab7339f56p+1L, 0x1.5eea399f6210bb34p+0L, -0x1.241533845f3ac4b2p-128L },
    { 0x1.edf2b3c243a75f86p+1L, 0x1.918a9da0f7d771fcp+0L, 0x1.34ebc81a251fb1b4p-128L },
    { 0x1.fb9eff906fae397ep+1L, 0x1.95367c64ec46dc9ap+0L, 0x1.fffffffffffffffep-65L },
    { 0x1.338421a3be1fd548p+2L, 0x1.affc50cd58267d3ep+0L, -0x1.2d4a23684179c0b2p-127L },
    { 0x1.6557399d292630dcp+2L, 0x1.c62895951870d52p+0L, -0x1.8f30a09c6585d70cp-126L },
    { 0x1.fffffffffffffffap+2L, 0x1.fffffffffffffffep+0L, -0x1.0000000000000002p-127L },
  };
  for (int i = 0; i < EXCEPTIONS; i++)
    if (x == exceptions[i][0])
    {
      h = exceptions[i][1];
      l = exceptions[i][2];
      return __builtin_ldexpl (h + l, e);
    }

  // multiply by 2^e, there can be no overflow/underflow
  return __builtin_ldexpl (h + l, e);
}

long double
cr_cbrtl (long double x)
{
  b96u96_u v = {.f = x};
  int e = v.e & 0x7fff;

  // check NaN, Inf, 0: cbrtl(x) = x
  if (__builtin_expect (e == 32767 || (e == 0 && v.m == 0), 0))
    return x+x;

  // save inexact flag. We do not save the x87 status flag here, we won't
	// touch it now.
  FLAG_T flagp = get_flag_quick();

  double h, l;
  fast_path (&h, &l, &e, x);

	int olde = e;

	// Check whether h + (l - err) and h + (l + err) round to the same value,
	// as long double. Here 0 < err < 2^{-74}|h| is the error of the fast path.
	// Note that there is no risk of underflow/overflow here.

	// We construct a 128-bit mantissa

	b64u64_u th = {.f = h};
	b64u64_u tl = {.f = l};
	int de = (th.u >> 52) - ((tl.u >> 52) & 0x3ff);

	// Note that only the low part has eventually a sign bit

	// represent the mantissa of the low part in two's complement format,
	// where 1l<<52 represents the implicit leading bit
	int64_t ml = (tl.u & ~(0xfffull<<52)) | (1l<<52), sgnl = -(tl.u >> 63);
	ml = (ml ^ sgnl) - sgnl;
	int64_t mlt;
	// we have to shift ml by 11 bits to the left to align with mh below,
	// and by de bits to the right, thus by de-11 bits to the right
	long sh = de - 11;
	if(__builtin_expect(sh>63,0)){ // ml shifted does not overlap with mh
		mlt = sgnl;
		if(__builtin_expect(sh-64>63,0)) // ml shifted vanishes
			ml = sgnl;
		else
			ml >>= sh - 64;
	} else {
		mlt = ml>>sh; // high part of ml, overlapping with mh
		ml = (uint64_t)ml<<(64-sh); // low part of ml
	}

	// construct the mantissa of the long double number
	uint64_t mh = (th.u<<11) | (1ull<<63);
	int64_t eps = (mh >> (74 - 64));

	mh += mlt; // add contribution from low part

	if(__builtin_expect(!(mh>>63),0)){
		// the low part is negative and
		// can unset the msb so shift the number back
		mh = (mh << 1) | ((uint64_t)ml >> 63);
		ml = (uint64_t)ml<<1;
		e--;
		eps <<= 1;
	}

	uint64_t oldmh = mh;

	b32u32_u sgn = {.f = 1.0f};
	sgn.u |= (v.e & 0x8000) << (32 - 16);
	float sign = sgn.f;
	float op = sign + sign*0x1p-25f, om = sign - sign*0x1p-25f;
	if(op==om){ // round to nearest
		mh += (uint64_t)ml>>63;
		ml ^= (1ul << 63);
	} else if(sign*op>1.0f) { // round away from zero for numbers with sign sign. 
		mh += 1;
	}

	/* Notice that having modified the high bit of ml suitably (which is the 
	   rounding bit) we have that ml, as a signed integer, has as (scaled)
	   absolute value the distance between m and the rounding boundary.
	   This will be used for the rounding test.
	*/

	if(__builtin_expect(mh < oldmh, 0)) {
		ml = ml/2; // Signed semantics matter
		eps >>= 1;
		mh = 1ull << 63;
	  e++;
	}

	// Given the signedness, this test expresses that ml < -eps or that
	// ml > eps.	This holds true because eps fits in 128-74 < 63 bits.
  if (__builtin_expect ((uint64_t)ml + eps > (uint64_t)(2*eps) , 1))
  {
		e += (th.u >> 52);
    // build final result 
    b96u96_u r;
		unsigned wanted_exp = (unsigned)(e + 0x3c00);
    r.e = wanted_exp | (v.e & 0x8000);
		r.m = mh; 
    if(__builtin_expect((r.m<<22)==0,0)){
      int k = __builtin_ctzll(r.m);
      uint64_t p = r.m>>k, p3 = p*p*p;
      k = __builtin_clzll(p3);
      if ( (v.m>>63) == 0) v.m <<= __builtin_clzll(v.m);
      if ( (p3<<k) == v.m) {
				// restore inexact flag
				set_flag_quick(flagp);
      }
    }
    return r.f;
  } 

  set_flag_quick(flagp);
  fexcept_t full_flag;
  fegetexceptflag	(&full_flag, FE_INEXACT);
  // we reuse the initial approximation (h+l)*2^e in the accurate path
  return accurate_path (h * (double) sign, l * (double) sign, olde, x,
                        full_flag);
}
