/* Correctly rounded exp2l function for binary80 values.

Copyright (c) 2024-2025 Sélène Corbineau, Alexei Sibidanov and Paul Zimmermann

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

   References:
   [1] Note on the Veltkamp/Dekker Algorithms with Directed Roundings,
       Paul Zimmermann, https://inria.hal.science/hal-04480440, February 2024.
   [2] CR-LIBM A library of correctly rounded elementary functions in double-precision,
       Catherine Daramy-Loirat, David Defour, Florent de Dinechin, Matthieu Gallet, Nicolas Gast,
       Christoph Lauter, Jean-Michel Muller, https://ens-lyon.hal.science/ensl-01529804, 2017.
   [3] Handbook of Floating-Point Arithmetic, Jean-Michel Muller, Nicolas Brunie, Florent de Dinechin,
       Claude-Pierre Jeannerod, Mioara Joldes, Vincent Lefèvre, Guillaume Melquiond, Nathalie Revol,
       Serge Torres, 2018.
   [4] Markstein, P. IA-64 and Elementary Functions.
       Hewlett-Packard Professional Books, 2000.
*/

/* This code was obtained from the expl.c code (revision e5fddf4), which
   approximates exp(x) as 2^(x/log(2)), by removing the division by log(2),
   and adjusting the error analysis.
 */

#include <stdint.h>
#include <errno.h>
#include <fenv.h> // for feraiseexcept, FE_UNDERFLOW

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

// anonymous structs, see https://port70.net/~nsz/c/c11/n1570.html#6.7.2.1p19
typedef union {
  long double f;
  struct __attribute__((__packed__)) {uint64_t m; uint32_t e:16; uint32_t empty:16;};
} b96u96_u;

typedef union {
	double f;
	struct __attribute__((packed)) {uint64_t m:52;uint32_t e:11;uint32_t s:1;};
	uint64_t u;
} b64u64_u;

/* s + t <- a + b, assuming |a| >= |b| */
static inline void
fast_two_sum (long double *s, long double *t, long double a, long double b)
{
  *s = a + b;
  long double e = *s - a;
  *t = b - e;
}

/* s + t <- a + b, assuming |a| >= |b| */
/* For rounding to nearest, fast_two_sum_double() is exact.
   However for directed roundings, it is not necessarily.
   The rounding error is bounded by 2^-105 * |s|.
   See Note on FastTwoSum with Directed Roundings,
   Sélène Corbineau and Paul Zimmermann, 2024,
   https://inria.hal.science/hal-03798376 */
static inline void
fast_two_sum_double (double *s, double *t, double a, double b)
{
  *s = a + b;
  double e = *s - a;
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

// put in h+l an approximation of 2^x for |x| < 2^-16, with relative error
// bounded by 2^-125.403 (see routine analyze_Pacc in exp2l.sage)
// and |l| < 2^-62.999
static void
Pacc (long double *h, long double *l, long double x)
{
  /* the following degree-6 polynomial generated by exp2acc.sollya has absolute
     error bounded by 2^-133.987 for |x| < 2^-16 */
  static const long double p[] = {1.0L, // degree 0
                                  0x1.62e42fefa39ef358p-1L, -0x1.b0e2633fe0676a9cp-67L, // degree 1
                                  0x1.ebfbdff82c58ea86p-3L, 0x1.e2d60dd936b9ba5ep-68L,  // degree 2
                                  0x1.c6b08d704a0bf8b4p-5L, -0x1.8b4ba2fbcf44117p-70L,  // degree 3
                                  0x1.3b2ab6fba4e7729cp-7L,  // degree 4
                                  0x1.5d87fe78ad725bcep-10L, // degree 5
                                  0x1.4309131bde9fabeap-13L, // degree 6
  };
  long double y = p[9] * x + p[8]; // a6*x+a5
  y = y * x + p[7];                // y*x+a4
  y = y * x;                       // y*x
  fast_two_sum (h, l, p[5], y);    // a3h+y
  *l += p[6];                      // +a3l
  // multiply h+l by x
  long double t;
  a_mul (h, &t, *h, x);            // exact
  *l = *l * x + t;
  // add a2h+a2l
  fast_two_sum (h, &t, p[3], *h);
  *l += t + p[4];
  // multiply h+l by x
  a_mul (h, &t, *h, x);            // exact
  *l = *l * x + t;
  // add a1h+a1l
  fast_two_sum (h, &t, p[1], *h);
  *l += t + p[2];
  // multiply h+l by x
  a_mul (h, &t, *h, x);            // exact
  *l = *l * x + t;
  // add a0
  fast_two_sum (h, &t, p[0], *h);
  *l += t;
}

#include "exp2l_tables.h"

/* Assuming |x| < 2^15, return an approximation of 2^x with relative
   error < 2^-89.020.
   Uses the evaluation strategy from [4].
   If needmoreaccuracy is set to zero, returns in x
   a correctly rounded approximation to the long double format. */
static inline long double
fast_path(long double x, int* needmoreaccuracy) {
	/* Strategy : split x like
	   m + 2^-20 fracpart + xr
	   with m, fracpart integers.
	   Then, compute 2^(2^-20 fracpart) using tables and 2^xr using
	   a Taylor polynomial.
	*/

	b96u96_u cvt_x; cvt_x.f = x;
	b64u64_u cvt_w, cvt_aux;

	/* Split x into xh + xl, where |xl| < ulp(xh). We exploit the fact that x
	   is a normal number.
	   Since |x| < 2^15, we have |xh| <= 2^15 and |xl| <= ulp(2^14) = 2^-38
	   Note that if |xh| < 2^-20, then |xl| <= ulp(2^-21) = 2^-73.
	*/

	cvt_w.u = ((cvt_x.e&0x8000ul) << (63 - 15)) |
		(((cvt_x.e&0x7ffful) + (1023ul - 16383ul)) << (64 - 12)) |
		((cvt_x.m >> 11) & ~(1ul << 52)); // Explicitely remove leading 1 bit
	double xh = cvt_w.f;

	/* The bottom bit of x's mantissa has weight e - 63, were e is y's exponent.
	   Therefore, the exponent of xl should (at first) be e - 63 + 52 = e - 11
	*/
	cvt_w.u = ((cvt_x.e&0x8000ul) << (63 - 15)) |
		(((cvt_x.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12)) |
		(cvt_x.m & ((1ul << 11) - 1ul));

	// Replicate parasitic implicit leading bit
	cvt_aux.u = ((cvt_x.e&0x8000ul) << (63 - 15)) | (((cvt_x.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12));
	double xl = cvt_w.f - cvt_aux.f; // Remove implicit one introduced before

	static const double C = 0x1.8p+32;
	b64u64_u y = {.f = xh+C};
	/* Note that |xh| <= 2^15. That way, given how large is C, C and y.f are
	   in the same binade and ulp(y.f) = 2^-20. Therefore, y.f = r + C
	   where r is xh rounded to 2^-20. We have |r - xh| < 2^-20.
	*/

	b64u64_u cvt = {.f = xh};
	int do_red = cvt.e >= -20 + 0x3ff; // |xh| >= 2^-20

	if (__builtin_expect (do_red, 1)) {// |xh| >= 2^-20
		double remaining = xh - (y.f - C);
		/* Both differences below are exact by Sterbenz's lemma.
		   For y.f - C this follows from |xh| <= 2^15,
		   thus C - 2^15 <= |y.f| <= C + 2^15.
		   Let r = y.f - C, we have shown above that |r - xh| < 2^-20,
		   thus if |xh| >= 2*2^-20, r and xh differ by at most a factor 2,
		   Sterbenz's lemma applies and xh - r is exact.
		   It remains the case |xh| < 2*2^-20. When |xh| >= 2^-20,
		   since |r - xh| < 2^-20 and r is an integer multiple of 2^-20,
		   the only possible value for |r| are 2^-20 and 2*2^-20 (with r
		   being of the same sign as xh). Then xh and r are in the same
		   binade, thus their difference is exact.
	     Notice that r is a multiple of 2^-20 and that ulp(xh) <= ulp(2^14)=2^-39.
	     This implies that remaining is a multiple of ulp(xh).
	   */

		fast_two_sum_double (&xh, &xl, remaining, xl);
		/* Let xh_old/xl_old be the values of xh/xl before this
		   fast_two_sum(), and xh/xl the values afterwards.
		   We have that remaining is a multiple of ulp(xh), and |xl| < ulp(xh).
		   Therefore, the fast_two_sum precondition holds.
		   We have |remaining + xl_old| < 2^-20 + 2^-38. This ensures that
		   |xh| <= 2^-19.9999. This implies that
		   * |xl| <= ulp(xh) <= 2^-72
		   * the rounding error is at most 2^-105|xh| <= 2^-124.999
		*/
	}

	uint64_t fracpart = y.u; // only meaningful for |x| >= 2^-20
	/* Since y.f = C + r with C = 0x1.8p+32 and r multiple of 2^-20,
	   and |r| < 2^14.6, we can read r (in two's complement notation)
	   in the 35 low bits of y.u. */

	int16_t extra_exponent = y.u >> 20; // will be set to 0 if |x| < 2^-20
	/* If r >= 0, then y.u = eee1000...000rrr, where eee denotes the
	   exponent field, 1 stands for the 8 (value) 2^31 in C, and rrr is
	   the value of r*2^20, thus we get extra_exponent = 000...000rrr.
	   If r < 0, then y.u = eee0111...111rrr, where 0111...111 stands for
	   the 8 in C from which we subtracted |r|, and 111...111rrr is the
	   two's complement notation of r*2^20,
	   thus we get extra_exponent = 111...111rrr.
	   In both cases we get in extra_exponent the 16-bit two's complement
	   notation of floor(r). */

	/* Up to here, we have split x into parts, with the following errors:

	   When do_red=false, i.e. |x| < 2^-20, computations up to here were exact.
	   Therefore 2^x = 2^(xh+xl).

	   When do_red=true, i.e. |x| >= 2^-20, the total error is at most 2^-124.999.
	   Therefore 2^x = 2^r*2^(xh+xl)*(1 + rho1) with
	     |rho1| <= 2^(2^-124.999) - 1 = 2^-125.527
	*/

	/* Compute using lookup tables: fracpart contains in its low 20 bits
	   the value of frac(r), where r = floor(r) + frac(r).
	   Note: the values of xs_pow2_h, xs_pow2_l computed below are not
	   used when |x| < 2^-20 (do_red = false). */

	int i0 = fracpart & 0x1f;
	int i1 = (fracpart >> 5) & 0x1f;
	int i2 = (fracpart >> 10) & 0x1f;
	int i3 = (fracpart >> 15) & 0x1f;
	double frcp_acc0_l, frcp_acc0_h, frcp_acc2_h, frcp_acc2_l;
	double xs_pow2_h, xs_pow2_l;

        /* frac(r) = i3/2^5 + i2/2^10 + i1/2^15 + i0/2^20
           where S3[i3] approximates 2^(i3/2^5),
                 S2[i2] approximates 2^(i2/2^10),
                 S1[i1] approximates 2^(i1/2^15),
                 S0[i0] approximates 2^(i0/2^20),
           thus S3[i3] * S2[i2] * S1[i1] * S0[i0] approximates 2^frac(r),
           where each table S3, S2, S1, S0 has its lower elements
           smaller than 1/2 ulp(1) = 2^-53. */

	d_mul_double(&frcp_acc0_h, &frcp_acc0_l,
		S0[i0][0], S0[i0][1],   // 2^(i0/2^20)
		S1[i1][0], S1[i1][1]);  // 2^(i1/2^15)
	/* frcp_acc0_h + frcp_acc0_l approximates 2^(i1/2^15+i0/2^20).
	   Each term S0[i0], S1[i1] is in [1, 2) and has
	   absolute error less than 2^-107, thus when multiplying them
	   the absolute error is bounded by:
	   2*2^-107 + 2^-107*2 + 2^-107*2^-107 < 2^-104.9.
	   If we expand the d_mul() call, the computation of hi
	   and s is exact, and since 1 <= ah, bh < 2:
	   1 <= h <= 2 and |s| < ulp(h) = 2^-52;
	   then since |al| < 2^-53, |al*bh+s| < 2^-53*2+2^-52 = 2^-51
	   thus |t| <= 2^-51 and the rounding error on t is less than
	   ulp(2^-52) = 2^-104, then since |bl| < 2^-53,
	   |ah*bl+t| < 2*2^-53+2^-51 < 2^-50.4 thus |lo| <= 2^-50.4
	   and the rounding error on lo is less than
	   ulp(2^-50.4) = 2^-103. We thus have:
	   |frcp_acc0_h + frcp_acc0_l - 2^(i1/2^15+i0/2^20)| <
	   2^-104.9 + 2^-104 + 2^-103 < 2^-102.1
	   with |frcp_acc0_l| < 2^-50.4.
	*/

	d_mul_double(&frcp_acc2_h, &frcp_acc2_l,
		S2[i2][0], S2[i2][1],   // 2^(i2/2^10)
		S3[i3][0], S3[i3][1]);  // 2^(i3/2^5)
	/* The same analysis as above applies:
	   |frcp_acc2_h + frcp_acc2_l - 2^(i3/2^5+i2/2^10)| < 2^-102.1
	   with |frcp_acc2_l| < 2^-50.4.
	*/

	d_mul_double(&xs_pow2_h, &xs_pow2_l, frcp_acc0_h, frcp_acc0_l,
		frcp_acc2_h, frcp_acc2_l);

	/* frcp_acc0_h + frcp_acc0_l approximates 2^(i1/2^15+i0/2^20)
	   with absolute error bounded by 2^-102.1, and
	   frcp_acc2_h + frcp_acc2_l approximates 2^(i3/2^5+i2/2^10)
	   with absolute error bounded by 2^-102.1, and both values
	   are in [1,2), thus their product approximates
	   2^frac(r) with absolute error bounded by:
	   2^-102.1*2 + 2*2^-102.1 + 2^-102.1*2^-102.1 < 2^-100.
	     Moreover we know that |frcp_acc0_l|, |frcp_acc2_l| < 2^-50.4.
	   If we expand the d_mul_double() call, the computation of hi
	   and s is exact, and since 1 <= ah, bh <= 2:
	   1 <= h <= 4 (but in fact we have h < 2, see routine
	     check_t3t2t1t0() in expl.sage), and |s| < ulp(h) = 2^-52; then
	   since |al| < 2^-50.4, |al*bh+s| < 2^-50.4*2+2^-52 < 2^-49.1
	   thus |t| <= 2^-49.1 and the rounding error on t is less than
	   ulp(2^-49.1) = 2^-102, then since |bl| < 2^-50.4,
	   |ah*bl+t| < 2*2^-50.4+2^-49.1 < 2^-48.2 thus |lo| <= 2^-48.2
	   and the rounding error on lo is less than
	   ulp(2^-48.2) = 2^-101. We thus have:
	   |xs_pow2_h + xs_pow2_l - 2^frac(r)|
	   < 2^-100 + 2^-102 + 2^-101 < 2^-99.1.
	*/


	/* Therefore we have when |x| >= 2^-20:
	   |xs_pow2_h + xs_pow2_l - 2^frac(r)| < 2^-99.1.
	   Since 2^frac(r) >= 1, this is also a relative error bound:
	     xs_pow2_h + xs_pow2_l = 2^frac(r) * (1 + rho2)
	   with |rho2| < 2^-99.1.

	   Note that that |xs_pow2_l| <= 2^-48.2 and |xs_pow2_h| < 2
	   (from routine check_t3t2t1t0() in expl.c).
	*/

	/* Evaluating the Taylor polynomial for 2^xr where xr = xh + xl.
	   This is done both for |x| < 2^-20 and |x| >= 2^-20.
	   We evaluate 2^xr through a polynomial approximation. Note that
	   |xh| <= 2^-19.9999 and |xl| <= 2^-72, therefore |xr| <= 2^-19.999.

	   Over this interval, Sollya gives the polynomial
	   1 + x * 0x1.62e42fefa39ef35793c766d326cp-1 + x^2*0x1.ebfbdff82c696p-3
	   + x^3 * 0x1.c6b08d704a1cdp-5
	   precise to 2^-89.218 (absolute error, cf ../exp/exp.sollya).
	*/

	double xsq = xh * xh;
	/* Neglecting 2*xl*xh + xl^2 brings an error of at most
	   |2*xl*xh + xl^2| <= 2 * 2^-72 * 2^-19.999 + 2^-72 * 2^-72
	                    <= 2^-90.998.
	   Since |xh| <= 2^-19.999, we have |xh*xh| <= 2^-39.998. The rounding
	   error on xsq is therefore at most ulp(2^-39.998) = 2^-92, and
	     |xsq| <= 2^-39.998 + 2^-92 <= 2^-39.997.
	   We have thus |xsq - xr^2| <= 2^-90.998 + 2^-92 <= 2^-90.413.
	*/
	double orders23 = xsq * __builtin_fma (xh, 0x1.c6b08d704a1cdp-5,
	                                           0x1.ebfbdff82c696p-3);
	/* We note A = 0x1.c6b08d704a1cdp-5 and B = 0x1.ebfbdff82c696p-3.
	   Analyzing the fma call:
	   Neglecting xl * A imparts an error bounded by
	     |A * xl| <= A*2^-72 <= 2^-76.171
	   Since |xh| <= 2^-19.999, |A*xh+B| <= 2^-19.999*A + B < 1/4 - 0.008.
	   This implies that the fma's result is strictly less than 1/4.
	   The rounding error of the fma is therefore at most ulp(1/8) = 2^-55.
	   The total error evaluating Axr+B is thus at most
	     2^-55 + 2^-76.171 <= 2^-54.999.

	   Given the errors on each factor, the product xsq * fma() carries an
	   intrinsic error
	     |xr|^2*2^-54.999 + 2^-90.413*|Axr+B| + 2^-90.413*2^-54.999
	   Since |xr|<= 2^-19.999 we check that |Axr+B| <= 2^-2.049 and thus
	   the error is at most 2^-92.232.

	   Since |xsq| <= 2^-39.997 and ||A*xh+B| < 1/4 - 0.008, the product
	   is bounded by 2^-39.997 * (1/4 - 0.008) < 2^-42.04. The rounding
	   error on orders23 is thus at most ulp(2^-42.04) = 2^-95.
	   Therefore |orders23| <= 2^-42.04 + 2^-95 < 2^-42.03.
	   The total error on orders23 is at most 2^-92.232+2^-95 <= 2^-92.034.
	*/

	double order1h, order1l;
	static const double coeff1h = 0x1.62e42fefa39efp-1;
	static const double coeff1l = 0x1.abc9e3b369936p-56;
	// 0x1.62e42fefa39ef35793c766d326cp-1 = coeff1h + coeff1l
	d_mul_double(&order1h, &order1l, coeff1h, coeff1l, xh, xl);
	/* Let's expand the d_mul call.
	   Since |coeff1h| < 2^-0.5287 and |xh| <= 2^-19.999 we have
	         |ah*bh| <= 2^-20.527. This implies
	   |order1h| < 2^-20.5 and |s| < ulp(2^-20.5) = 2^-73.
	   Since |coeff1l| <= 2^-55.25, we compute that
	     |coeff1l*xh + s| <= 2^-55.25*2^-19.999 + 2^-73 <= 2^-72.724.
	   This ensures that the rounding error computing t is at most
	         ulp(2^-72.724) = 2^-125 and that |t| <= 2^-72.7.
	   Since |coeff1h| <= 2^-0.528 and |xl| < 2^-72, we compute that
	     |coeff1h*xl + t| <= 2^-0.528 * 2^-72 + 2^-72.7 <= 2^-71.611.
	   The rounding error on order1l is therefore at most ulp(2^-71.611)
	   = 2^-124. We also get |order1l| < 2^-71.610.
	   The total rounding error is at most 2^-125 + 2^-124 = 2^-123.415:

	   The error due to neglecting xl*coeff1l is at most
	     |xl*coeff1l| <= 2^-72 * 2^-55.25 <= 2^-127.25.
	   The total error on order1 is at most 2^-123.415 + 2^-127.25 <= 2^-123.317:
	     |order1h + order1l - (coeff1h + coeff1l) * (xh + xl)| < 2^-123.317.
	*/

	double finalh, finall;
	fast_two_sum_double(&finalh, &finall, 1, orders23);
	/* Since |orders23| < 2^-42.03, clearly |finalh| < 2, so that
	     |finalh| <= 1 + 2^-42.03 + ulp(1) <= 2^0.001.
	   The arguments are in the right order, so this fast_two_sum
	   introduces an error at most 2^-105*2^0.001 <= 2^-104.999.
	   Also since |finalh| < 2 we get |finall| < ulp(1) = 2^-52.
	*/

	double tmp;
	fast_two_sum_double(&finalh, &tmp, finalh, order1h);
	/* At input we have 1/2 < |finalh| < 2^0.001 and |order1h| < 2^-20.5,
           which ensures that the order is respected.
           Furthermore |finalh+order1h| <= 2^0.001 + 2^-20.5 < 2^0.002. This
           ensures that the error is bounded by 2^-105*2^0.002 <= 2^-104.998.
           Also, we get for the new value of finalh:
           |finalh| <= 2^0.002 and |tmp| <= ulp(2^0.002) = 2^-52.
	*/

	finall = tmp + (finall + order1l);
	/* At input, we have |finall| < 2^-52 and |order1l| <= 2^-71.4.
	   Therefore the internal sum is strictly bounded by 2^-51.9 and has
	   rounding error at most ulp(2^-51.9) = 2^-104.
	   Calling S the intermediate result, since |tmp| <= 2^-52 we have
	   |tmp + S| < 2^-52 + 2^-51.9 < 2^-50.9, which ensures a
	   rounding error of at most ulp(2^-50.9) = 2^-103 and that the
	   new value of finall satisfies:
	     |finall| < 2^-50.9 + 2^-103 <= 2^-50.8.
	   The total rounding error here is 2^-104 + 2^-103 <= 2^-102.415.
	*/

	/* Summing up the errors we get :
	   - 2^-92.034  computing orders23,
	   - 2^-123.317 computing order1,
	   - 2^-104.999 in the first fast_two_sum,
	   - 2^-104.998 in the second fast_two_sum,
	   - 2^-102.415 in the last sum.
	  The polynomial itself was only precise to 2^-89.218. Therefore,
	  we have computed 2^xr with error at most :
	     2^-92.034 + 2^-123.317 + 2^-104.999 + 2^-104.998 + 2^-102.415 + 2^-89.218
	     <= 2^-89.026.
	   Since xr >= -2^-19.999, this gives a relative error rho3 less than
	   2^-89.026/2^(-2^-19.999) < 2^-89.025:
	     finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-89.025
	*/

	int64_t err; // error bound
	if(__builtin_expect(do_red,1)) {
		d_mul_double(&finalh, &finall, finalh, finall, xs_pow2_h, xs_pow2_l);
		/* We have xs_pow2_h + xs_pow2_l = 2^frac(r) * (1 + rho2)
		   with |rho2| < 2^-99.1, and
		   finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-89.025
		   The intrinsic relative error of the product is at most
		   (1 + rho2) * (1 + rho3) - 1 <= 2^-99.1 + 2^-89.025 + 2^-99.1*2^-89.025
		                               <= 2^-89.023.

		   Expanding the d_mul call, we see that:
		   Since |finalh*xs_pow2_h| < 2^0.002*2 <= 2^1.002,
		         |s| <= ulp(2^1.002) = 2^-51. Then, since
		   |finall*xs_pow2_h + s| <= 2^-50.8 * 2 + 2^-51 <= 2^-49.278 we get
		   |t| <= 2^-49.277 and that the rounding error on t is at most
		         ulp(2^-49.278) = 2^-102.
		   We compute |finalh*xs_pow2_l + t| <= 2^0.002*2^-48.2+2^-49.277
		   <= 2^-47.638. This ensures that the rounding error computing
		  *lo is less than ulp(2^-47.638) = 2^-100.
		   The total rounding error is therefore at most
		   2^-102 + 2^-100 <= 2^-99.678.
		   The error due to neglecting xs_pow2_l * finall is at most
		     |xs_pow2_l * finall| <= 2^-48.2 * 2^-50.8 <= 2^-99, thus adding it
		  yields an error < 2^-99.678 + 2^-99 <= 2^-98.299.

		   Since the product should be at least exp(-2^-19.999), this
		   translates to an additional relative error
		     rho4 <= 2^-98.299/2^(-2^-19.999), so rho4 <= 2^-98.298.
		   Taking into account rho1, the total relative error is thus at most
		   (1 + 2^-89.023)(1 + rho1)(1 + rho4) - 1 <= 2^-89.020.
		*/
	} else {
		extra_exponent = 0;
		/* In the case |x| < 2^-20, only the errors on the polynomial
		   evaluation (rho3) do appear, with |rho3| < 2^-89.025, thus we get:
		   (1 + rho1) * (1 + rho3) - 1 < 2^-89.024. */
	}
	// the error bound is the same in both cases
	err = -89;
	/* Remark: some tests fail with err=-90, thus the error
	   analysis is very tight. */

	/* In all cases we have:
	   |finalh + finall - 2^frac(r) * 2^xr| < 2^err|finalh + finall| */

	fast_two_sum_double(&finalh, &finall, finalh, finall);
	// This add a 2^-105 relative error but ensures there is no overflow
	// in mh = ml+mlt

	b64u64_u th = {.f = finalh}, tl = {.f = finall};
	// the high part is always positive, the low part can be positive
	// or negative, thus we mask the sign bit
	long eh = th.u>>52, el = (tl.u>>52) & 0x3ff, de = eh - el;

	// represent the mantissa of the low part in two's complement format,
	// where 1l<<52 represents the implicit leading bit
	int64_t ml = (tl.u & ~(0xfffull<<52)) | (1ll<<52), sgnl = -(tl.u >> 63);
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
		ml = (uint64_t) ml << (64-sh); // low part of ml
	}

	// construct the mantissa of the long double number
	uint64_t mh = (th.u<<11) | (1ull<<63);
	// We use a kind of floating representation where m = mh||ml is the
	// mantissa (whose leading 1 has weight 2^exponent) and
	// extra_exponent is the exponent.

	int64_t eps = (mh >> (-err - 64));
	// We have eps > 2^err * mh - 2^-63, scaled so we can add it to ml.
	// Since mh has its most significant bit set, it follows
	// eps > (2^err - 2^-127) * mh, and err > 2^-89.019 * mh respectively.

	mh += mlt; // add contribution from low part
	if(__builtin_expect(!(mh>>63),0)){
		// the low part is negative and
		// can unset the msb so shift the number back
		mh = (mh << 1) | ((uint64_t)ml >> 63);
		ml = (uint64_t) ml << 1;
		extra_exponent--;
		eps <<= 1;
	}

	int wanted_exponent = extra_exponent + 0x3c00 + eh;
	if(__builtin_expect(wanted_exponent <= 0, 0)) {
		int shiftby = 1 - wanted_exponent;

		if(__builtin_expect(shiftby >= 64, 0)) {
			ml = mh >> (shiftby-64);
			eps = 1;
			mh = 0;
			if(__builtin_expect(shiftby > 65, 0)) {
					return 0x1p-16445L * .25L;
			}
		} else {
			ml = (uint64_t)ml >> shiftby;
			ml |= mh << (64 - shiftby);
			mh >>= shiftby;
			eps >>= shiftby;
		}
		wanted_exponent = 0;
	}

	uint64_t oldmh = mh;
	float op = 1.0f + 0x1p-25f, om = 1.0f - 0x1p-25f;
	if(op==om){ // round to nearest
		mh += (uint64_t)ml>>63;
		ml ^= (1ull << 63);
	} else if(op>1.0f) { // round to +inf
		mh += 1;
	}
	/* Notice that having modified the high bit of ml suitably (which is the
	   rounding bit) we have that ml, as a signed integer, has as (scaled)
	   absolute value the distance between m and the rounding boundary.
	   This will be used for the rounding test.
	*/

	// This branch can only be taken if wanted_exponent != 0
	// Else we simply cannot have an overflow
	if(__builtin_expect(mh < oldmh, 0)) {
		ml = ml/2; // Signed semantics matter
		eps >>= 1;
		mh = 1ull << 63;
	  wanted_exponent++;
	}

	// We had a subnormal but rounding made it into the smallest normal
        if (__builtin_expect (wanted_exponent == 0, 0)) { // subnormal case
          if (mh>>63)
            wanted_exponent = 1;
          else {
            feraiseexcept (FE_UNDERFLOW); // raise underflow
#ifdef CORE_MATH_SUPPORT_ERRNO
            errno = ERANGE; // underflow
#endif
          }
	}

	b96u96_u v;
	v.m = mh; // mantissa
	v.e = wanted_exponent; //extra_exponent + 0x3c00 + eh; // exponent

	// Given the signedness, this test expresses that ml >= -eps and that
	// ml <= eps.	This holds true because eps fits in 128-87=41 bits.
	int b1 = (uint64_t)ml + eps <= (uint64_t)(2*eps);

	// Subnormals *inside* the computation don't seem to pause a problem
	// given the error analysis (we used absolute bounds mostly)
	// rounding test
	*needmoreaccuracy = b1;

	// Infinity output case
	if(__builtin_expect(wanted_exponent >= 32767, 0)) {
		return 0x1p16383L + 0x1p16383L;
	}
	return v.f;
}

static void __attribute__((noinline))
accurate_path (long double *h, long double *l, long double x)
{
#define EXCEPTIONS 152
  static const long double db[EXCEPTIONS][2] = {
    {-0x1.93156bf341603b4ep+1L, 0x1.cdbb2250ecf28d18p-4L},
    {-0x1.a74f43feae4bf1dap+0L, 0x1.457c21a3a033a3ecp-2L},
    {-0x1.82f673645e984b46p+0L, 0x1.6725658526f34c7ap-2L},
    {-0x1.489f0eef9e5a0dfep+0L, 0x1.a49af00837c3b46ap-2L},
    {-0x1.262ad7e682c0769cp+0L, 0x1.cdbb2250ecf28d18p-2L},
    {-0x1.56b05bdd054d245ep-1L, 0x1.41f2cb598284c76ap-1L},
    {-0x1.4e9e87fd5c97e3b4p-1L, 0x1.457c21a3a033a3ecp-1L},
    {-0x1.3928fef54f77ebe6p-1L, 0x1.4f145246ca66c496p-1L},
    {-0x1.05ece6c8bd30968cp-1L, 0x1.6725658526f34c7ap-1L},
    {-0x1.37b7d6ebc3c535c2p-2L, 0x1.9e9a71830d784296p-1L},
    {-0x1.227c3bbe796837f8p-2L, 0x1.a49af00837c3b46ap-1L},
    {-0x1.a1e464cd5bc4a23ap-3L, 0x1.bc7904bc8f246052p-1L},
    {-0x1.9ed07fa75f06bea6p-3L, 0x1.bcef9ae152269ee2p-1L},
    {-0x1.604925c5bf3474d6p-3L, 0x1.c673d28ce068abb6p-1L},
    {-0x1.3156bf341603b4ep-3L, 0x1.cdbb2250ecf28d18p-1L},
    {-0x1.8505d93927bb4c3ep-4L, 0x1.df6117f984663e66p-1L},
    {-0x1.5e2587ada2074bcep-4L, 0x1.e28b1e5c682df14ap-1L},
    {-0x1.4a8794b3444605b6p-4L, 0x1.e425e2a6cf326f64p-1L},
    {-0x1.e215318af03341a6p-5L, 0x1.eb891af3c386ff94p-1L},
    {-0x1.c8bc4afa684dfb16p-5L, 0x1.ec9744ec13971318p-1L},
    {-0x1.938fc9609a1d4edap-5L, 0x1.eecfe8bd94c212a6p-1L},
    {-0x1.45610e6cbd8dbbdap-5L, 0x1.f218a6c2e13d511p-1L},
    {-0x1.1478d76251cf60c6p-5L, 0x1.f429699bc0bf4ca6p-1L},
    {-0x1.0ab19befd67fc6f8p-5L, 0x1.f49364ab7e379fc8p-1L},
    {-0x1.ce77a76194b6190ap-6L, 0x1.f61475edd297533ep-1L},
    {-0x1.80b57cdb68b5d27ep-6L, 0x1.f7bbfcb382ac4c1ep-1L},
    {-0x1.333f5952d8506128p-6L, 0x1.f9634897f4b3e7bcp-1L},
    {-0x1.2c6c02eaf7d1b836p-6L, 0x1.f988a623c6d84c8p-1L},
    {-0x1.c2395606661e0442p-7L, 0x1.fb25a3b00bcab8acp-1L},
    {-0x1.364995dca344ad7p-7L, 0x1.fca68486e6ac91f4p-1L},
    {-0x1.321d2989bbf9a8eep-7L, 0x1.fcb2039343b4a4d6p-1L},
    {-0x1.5e0e3ccfed32c13ep-8L, 0x1.fe1b9dfb49e09ad2p-1L},
    {-0x1.0611463d175f85ap-8L, 0x1.fe95334b2831567ep-1L},
    {-0x1.e4e518f1dc4e4e3ep-9L, 0x1.feb053b79bb6bb94p-1L},
    {-0x1.b9e793210ea77cd2p-9L, 0x1.fece0d7e315971e2p-1L},
    {-0x1.af3968477ccaa31ep-9L, 0x1.fed5704d93985996p-1L},
    {-0x1.74e0d86793c6427p-9L, 0x1.fefdcb8cb398fcacp-1L},
    {-0x1.4309583c53a5b05p-9L, 0x1.ff20478094da34cep-1L},
    {-0x1.3e8ea85e774dbeb6p-9L, 0x1.ff2360fa55a6ded6p-1L},
    {-0x1.2bfe8ec84fe88d2cp-9L, 0x1.ff30397fe83cdbacp-1L},
    {-0x1.218bf3fadd1d1dc4p-9L, 0x1.ff377481b5e56918p-1L},
    {-0x1.b6270cdcb5d62e2p-10L, 0x1.ff683c5f631723d4p-1L},
    {-0x1.9b9cf2aa73d238d2p-10L, 0x1.ff716c629b6cc1f6p-1L},
    {-0x1.662ae8d7db1d7b64p-10L, 0x1.ff83ed651f45aadp-1L},
    {-0x1.44779ac3b17ba42cp-10L, 0x1.ff8f98b19fa02628p-1L},
    {-0x1.2771f9c4f8e81c2p-10L, 0x1.ff99a57f5f0ca2aep-1L},
    {-0x1.ef4f6db7dd41df6p-11L, 0x1.ffaa3286acf30704p-1L},
    {-0x1.ec5b7502dd091e32p-11L, 0x1.ffaab570c1cc7738p-1L},
    {-0x1.e39e86a4effe162cp-11L, 0x1.ffac38d23251f566p-1L},
    {-0x1.b8654bd94a95d0b6p-11L, 0x1.ffb3b51bc1dd03dep-1L},
    {-0x1.9606bc444cdfdb8ep-11L, 0x1.ffb9a8ee14823cecp-1L},
    {-0x1.6694a2efb4b2a60cp-11L, 0x1.ffc1e0a000f69c52p-1L},
    {-0x1.42978fbd5903d9c8p-11L, 0x1.ffc81c69192eabdap-1L},
    {-0x1.0924dceecfaa488cp-11L, 0x1.ffd20fe5b28de0dcp-1L},
    {-0x1.06777344730121ap-11L, 0x1.ffd286a0fa3d2996p-1L},
    {-0x1.ea3acc97462ccf9ap-12L, 0x1.ffd5881e8b4652e2p-1L},
    {-0x1.d92ae26a88c884dep-12L, 0x1.ffd702732609618cp-1L},
    {-0x1.b78bf7500259df88p-12L, 0x1.ffd9ebf51ffc3274p-1L},
    {-0x1.9c58f6ff042fa28ap-13L, 0x1.ffee233b3604cefap-1L},
    {-0x1.958e70bf63affe9ap-13L, 0x1.ffee6e89752e81ap-1L},
    {-0x1.533bd3dbd08af5a4p-13L, 0x1.fff14dfd1fed1ep-1L},
    {-0x1.02c6e20796e48112p-13L, 0x1.fff4ca31fa11d54ap-1L},
    {-0x1.8ab5703915d7e7b6p-14L, 0x1.fff77357636a03ap-1L},
    {-0x1.7ce1f43c7d85bb2ep-14L, 0x1.fff7c00132fd1274p-1L},
    {-0x1.6ba69f937e83e83ap-14L, 0x1.fff81f8d4e4c103cp-1L},
    {-0x1.67ea37c6de6a2772p-14L, 0x1.fff834446d42642ap-1L},
    {-0x1.5ddcb2f8e0723232p-14L, 0x1.fff86c023545a07ap-1L},
    {-0x1.24c0df7eef4cfac2p-14L, 0x1.fff9a8ab6eed77e2p-1L},
    {-0x1.23ad39ace8276538p-14L, 0x1.fff9aea3e0070826p-1L},
    {-0x1.009a4503c87f2d6ep-14L, 0x1.fffa711f85aa0ed8p-1L},
    {-0x1.e72e5f9c812b5b42p-15L, 0x1.fffab9463445011ap-1L},
    {-0x1.d8b40a96c0713da2p-15L, 0x1.fffae169ee695a74p-1L},
    {-0x1.96b881a89db711a6p-15L, 0x1.fffb9859824377a6p-1L},
    {-0x1.7c6bb99fdcfc558ap-15L, 0x1.fffbe14422b12992p-1L},
    {-0x1.5ab466bb2121b42ep-15L, 0x1.fffc3ebe8713b664p-1L},
    {-0x1.4b8845d4d3bce1dcp-15L, 0x1.fffc68cf5119c93ep-1L},
    {-0x1.30bdeead0ab9134cp-15L, 0x1.fffcb3162ca0ab18p-1L},
    {-0x1.e4510ac98ee39be4p-16L, 0x1.fffd6099f46ef5e2p-1L},
    {-0x1.dc3b0251ef38ec24p-16L, 0x1.fffd6bcf92b3de66p-1L},
    {-0x1.d8a770dbc7a8d258p-16L, 0x1.fffd70c4cb93c8bap-1L},
    {-0x1.c483049c00e8420cp-16L, 0x1.fffd8cb0fa80cba6p-1L},
    {-0x1.9632fa92f69b0c6p-16L, 0x1.fffdcce4a5b33a76p-1L},
    {-0x1.8acea303b9027c9ep-16L, 0x1.fffddcaf7d274244p-1L},
    {-0xd.15f3e165e7e7965p-29L, 0x1.ffffff6edfd62336p-1L},
    {-0xe.ceb5c7152d2355cp-40L, 0x1.ffffffffeb78f5c2p-1L},
    {-0xf.80d811a47bbbfb8p-44L, 0x1.fffffffffea8203ap-1L},
    {-0x9.dd2c3c92e75472bp-49L, 0x1.fffffffffff929aep-1L},
    {-0xd.4759a60edbc72d3p-55L, 0x1.ffffffffffffdb2ep-1L},
    {-0xc.81571d9f0287227p-57L, 0x1.fffffffffffff756p-1L},
    {-0xe.2dd21ae4fa369cap-59L, 0x1.fffffffffffffd8ap-1L},
    {-0xb.fe0e178f9b0e03cp-61L, 0x1.ffffffffffffff7ap-1L},
    {-0xb.738e6b3095fc0f1p-61L, 0x1.ffffffffffffff82p-1L},
    {-0xd.b4a26411d5c6de3p-64L, 0x1.ffffffffffffffeep-1L},
    {-0xb.8aa3b295c17f0bcp-68L, 0x1.fffffffffffffffep-1L},
    {0xb.8aa3b295c17f0bcp-67L, 0x1.0000000000000002p+0L},
    {0xa.194f3c43094f2a2p-64L, 0x1.0000000000000006p+0L},
    {0xc.434dedbf1d96fc1p-63L, 0x1.0000000000000012p+0L},
    {0xb.6fc4ed79fcd7255p-53L, 0x1.0000000000003f6ap+0L},
    {0xf.49f104ab3cc2d94p-52L, 0x1.000000000000a98ep+0L},
    {0x9.f1ecf60af3e5853p-47L, 0x1.00000000000dc966p+0L},
    {0xc.3dc8cf1463af62fp-47L, 0x1.000000000010f85ap+0L},
    {0x9.ad1f062a8ab29ffp-40L, 0x1.0000000006b50272p+0L},
    {0xd.abfd779809f67b6p-38L, 0x1.0000000025e8087ap+0L},
    {0xc.762d7684ae1beeap-37L, 0x1.00000000451a19cep+0L},
    {0xe.0c9e1609da847dbp-37L, 0x1.000000004de7e1e2p+0L},
    {0x9.aab514ef3077eddp-36L, 0x1.000000006b3561fep+0L},
    {0xd.f39d71dc272a58p-29L, 0x1.0000004d5d3d3d86p+0L},
    {0xa.824ad65265e94b6p-25L, 0x1.000003a4626653aap+0L},
    {0xd.0527fc86dd2ec59p-25L, 0x1.000004832f1eead2p+0L},
    {0xd.ca1bcc03e818338p-25L, 0x1.000004c7714ce422p+0L},
    {0x1.248230c2bb787ce4p-16L, 0x1.0000cac0b15d6024p+0L},
    {0x1.5ead8ebb36c52e3p-16L, 0x1.0000f312bd341228p+0L},
    {0x1.d00a4c793a1d6d4ep-16L, 0x1.000141a6b8f91d42p+0L},
    {0x1.2574cfe96b07e51ep-15L, 0x1.000196d25dbbb85p+0L},
    {0x1.5f5b152690eba5dap-13L, 0x1.00079c717ef7efcp+0L},
    {0x1.db4b22a09e022f6p-13L, 0x1.000a4bcb36ef561p+0L},
    {0x1.aaded45884e59364p-12L, 0x1.00127ed001fc8accp+0L},
    {0x1.ae30b1e652dca39ap-12L, 0x1.0012a3a3fccb6446p+0L},
    {0x1.e2dda3cd8c341298p-11L, 0x1.0029d9b9a11881b8p+0L},
    {0x1.658382b8511ee5ccp-10L, 0x1.003dfb508259ecacp+0L},
    {0xc.5f396165dfc60bap-11L, 0x1.0112fe9112c95b06p+0L},
    {0x1.270a4a527eb90b6cp-7L, 0x1.019a4aa31b259dccp+0L},
    {0x1.35e0b2e14748db7cp-7L, 0x1.01aefe25aea5272ap+0L},
    {0x1.6f9ce5a8b3243262p-7L, 0x1.01ff9b337f526032p+0L},
    {0x1.1cac23cf32997fa6p-6L, 0x1.031a0d2f944dc4d8p+0L},
    {0x1.4df4919b6022268cp-6L, 0x1.03a47e1e06af54d4p+0L},
    {0x1.5afc7d79dedd2a4cp-6L, 0x1.03c92571dc388a4cp+0L},
    {0x1.70fd6310d1b4994cp-6L, 0x1.0407157c0ce85144p+0L},
    {0x1.3ac9a43d4e7d192ep-5L, 0x1.06e901f58091b67ap+0L},
    {0x1.50919d96b5fae21p-5L, 0x1.0765299e343f756ep+0L},
    {0x1.5178a614b366f2fap-5L, 0x1.076a4fcbe306eadp+0L},
    {0x1.e5b7eae7259fcb4cp-5L, 0x1.0abd81e709e4f1a4p+0L},
    {0x1.eb990e74b7582b7p-5L, 0x1.0adf7c7d0f3e7b3p+0L},
    {0x1.491705f0ae9f98bep-4L, 0x1.0ea943b7cdc4830cp+0L},
    {0x1.a4ed7fbb4a9fb356p-4L, 0x1.12e68526b08d8282p+0L},
    {0x1.ad988d3081bcbb9cp-4L, 0x1.134dd395bd76f908p+0L},
    {0x1.c400323ab65060d8p-4L, 0x1.14598c62848ce032p+0L},
    {0x1.d2eb2bfd12d6f486p-4L, 0x1.150c5eb3832acc14p+0L},
    {0x1.eaab0d7de0384c5ap-3L, 0x1.2e3f3978515cbfap+0L},
    {0x1.3f02d33da85d3b6ep-2L, 0x1.3db3eddfcd080064p+0L},
    {0x1.529f4845f565b744p-2L, 0x1.41f2cb598284c76ap+0L},
    {0x1.62c2f00546d03898p-2L, 0x1.457c21a3a033a3ecp+0L},
    {0x1.8dae021561102834p-2L, 0x1.4f145246ca66c496p+0L},
    {0x1.cf8852012559841ep-2L, 0x1.5e5a8e406ecbb63ap+0L},
    {0x1.f426326e859ed2e8p-2L, 0x1.6725658526f34c7ap+0L},
    {0x1.6ec1e220c34be404p-1L, 0x1.a49af00837c3b46ap+0L},
    {0x1.b3aa5032fa7f12c8p-1L, 0x1.cdbb2250ecf28d18p+0L},
    {0x1.58b0bc0151b40e26p+0L, 0x1.457c21a3a033a3ecp+1L},
    {0x1.7d098c9ba167b4bap+0L, 0x1.6725658526f34c7ap+1L},
    {0x1.b760f11061a5f202p+0L, 0x1.a49af00837c3b46ap+1L},
    {0x1.d9d528197d3f8964p+0L, 0x1.cdbb2250ecf28d18p+1L},
    {0x1.ecea940cbe9fc4b2p+1L, 0x1.cdbb2250ecf28d18p+3L},
  };
  static const uint64_t dbt[] = {0x6058f40154a13b46, 0x265b5e51592208fc, 0x192060};
  int a = 0, b = sizeof(db)/sizeof(db[0]) - 1, m = (a + b)/2;
  while (a <= b) { // binary search
    if (db[m][0] < x)
      a = m + 1;
    else if (db[m][0] == x) {
      *h = db[m][1];
      b96u96_u v = {.f = *h};
      v.e -= 66;
      v.e |= ((dbt[m/64]>>(m%64))&1)<<15;
      v.m = (uint64_t)1<<63;
      *l = v.f;
      return;
    } else
      b = m - 1;
    m = (a + b)/2;
  }

  int32_t k = __builtin_roundl (0x1p15L * x); // -16445*2^15 <= k <= 16383*2^15
  long double r = x - (long double) k * 0x1p-15L;
  int32_t i = (k + 538869760) & 32767;
  int32_t e = (k - i) >> 15;
  // x = 2^15*e + 2^10*i2 + 2^15*i1 + i0 + r
  int32_t i0 = i & 0x1f, i1 = (i >> 5) & 0x1f, i2 = i >> 10;
  Pacc (h, l, r);
  long double hh, ll;
  d_mul (&hh, &ll, T2[i2][0], T2[i2][1], T1[i1][0], T1[i1][1]);
  d_mul (&hh, &ll, hh, ll, T0[i0][0], T0[i0][1]);
  d_mul (h, l, *h, *l, hh, ll);
  // normalize h+l
  fast_two_sum (h, l, *h, *l);
  /* Warning: we might have a double-rounding issue here with rounding to nearest.
     Consider for example x=-0xf.ff1ad89a52a4115p+10. We have h=0xb.f69348826640047p-3
     which is scaled to 0xb.f69348826640047p-16384 (e=-16381), and l=0x8.befc7707a661334p-68
     which is scaled to 0x0.000000000000001p-16385, then h+l yields 0xb.f69348826640048p-16384. */
  ll = __builtin_ldexpl (*l, e);
  if (e >= -16381 && __builtin_ldexpl (ll, -e) == *l)
  {
    /* Since |h| > 0.5, ulp(h) >= 2^-64, thus ulp(h)*2^e >= 2^-16445 which is the smallest
       subnormal, thus 2^e*h is exact. Moreover since ll*2^-e = l, ll = l*2^e exactly,
       thus we can't have the double-rounding issue. */
    *h = __builtin_ldexpl (*h, e);
    *l = __builtin_ldexpl (*l, e);
  }
  else // near subnormal range
  {
    hh = *h;
    *h = __builtin_ldexpl (*h, e); // might not equal 2^e*h
    hh = hh - __builtin_ldexpl (*h, -e); // remaining (truncated) part
    hh += *l;
    /* We use __builtin_fmal to avoid the double-rounding issue, even if it is
       slow because emulated in software, this code is called very rarely. */
    *h = __builtin_fmal (hh, __builtin_ldexpl (1.0L, e), *h);
    *l = 0;
  }
}

long double
cr_exp2l (long double x)
{
  b96u96_u cvt_x = {.f = x};
  uint32_t e = cvt_x.e & 0x7fff;

  // check NaN, Inf, overflow, underflow
  // overflow for x >= 16384, i.e., 16397 <= e <= 32767
  // the smallest subnormal is 2^-16445
  if (__builtin_expect (e >= 16383 + 14, 0)) // |x| >= 2^14
  {
    if (e == 0x7fff)
    { // NaN or Inf: 2^x = x for x = NaN or +Inf, 2^-Inf = 0
      if (cvt_x.e == 0xffff && cvt_x.m == 0x8000000000000000ul) // -Inf
        return 0;
      return x+x;
    }

    if(cvt_x.e&0x8000) { // x <= -2^15
      if (e >= 16383 + 15) { // x <= -2^15
#ifdef CORE_MATH_SUPPORT_ERRNO
        errno = ERANGE; // underflow
#endif
        return 0x1p-16445L * 0.25L;
      }
    } else {
#ifdef CORE_MATH_SUPPORT_ERRNO
      errno = ERANGE; // overflow
#endif
      return 0x1p16383L + 0x1p16383L;
    }
  }

  if( __builtin_expect((cvt_x.m&0x1fffffffffffful) == 0, 0)){
    // identify and return exact results immediately
    int k = e - 16382;
    if( k>0 && __builtin_expect((cvt_x.m<<k) == 0, 0)){
      int sgn = -(cvt_x.e>>15);
      k = ((cvt_x.m>>(64-k))^sgn) - sgn;
      if(k>16383) {return 0x1p16383L + 0x1p16383L;}
      if(k>-16383){
				cvt_x.m = (uint64_t)1<<63;
				cvt_x.e = k + 16383;
      } else { // subnormal
        int shiftamnt = 16445+k;
        if(shiftamnt <= -1) {
#ifdef CORE_MATH_SUPPORT_ERRNO
          errno = ERANGE; // underflow
#endif
          return 0x1p-16445L*.5L;
        }
        cvt_x.m = (uint64_t)1<<shiftamnt;
        cvt_x.e = 0;
      }
      return cvt_x.f;
    }
  }

  // case of tiny inputs
  // for 0 <= x <= 0x1.71547652b82fe176p-64, 2^x rounds to 1 to nearest
  // for -0x1.71547652b82fe176p-65 <= x <= 0, 2^x rounds to 1 to nearest
	if (__builtin_expect (e <= 16383 - 66, 0)) // |x| < 2^-65
  { if(__builtin_expect(!e && !cvt_x.m, 0)) {return 1.L;}
		return 1.0L + x;
  }

  int needmoreaccuracy = 0;
  long double h = fast_path (x, &needmoreaccuracy);
  if(__builtin_expect(!needmoreaccuracy, 1)) return h;

  long double hi, lo;
  accurate_path (&hi, &lo, x);
  return hi + lo;
}
