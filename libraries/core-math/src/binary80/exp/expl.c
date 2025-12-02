/* Correctly rounded expl function for binary80 values.

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
   [1] Markstein, P. IA-64 and Elementary Functions.
       Hewlett-Packard Professional Books, 2000.
   [2] Note on FastTwoSum with Directed Roundings,
       Sélène Corbineau and Paul Zimmermann,
       Research Report, 2004, https://inria.hal.science/hal-03798376
*/

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#include "expl_tables.h"
#include "tint.h"

// Warning: clang also defines __GNUC__
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma STDC FENV_ACCESS ON

typedef union {
	long double f;
	struct __attribute__((packed)) {uint64_t m;uint32_t e:16;uint32_t empty:16;};
} b96u96_u;

typedef union {
	double f;
	struct __attribute__((packed)) {uint64_t m:52;uint32_t e:11;uint32_t s:1;};
	uint64_t u;
} b64u64_u;

// this is always exact, whatever the rounding mode
static inline void a_mul(double *hi, double *lo, double a, double b) {
	*hi = a * b;
	*lo = __builtin_fma (a, b, -*hi);
}

/* For rounding to nearest, fast_two_sum_double() is exact.
   However for directed roundings, it is not necessarily.
   The rounding error is bounded by 2^-105 * |s|.
   See Note on FastTwoSum with Directed Roundings,
   Sélène Corbineau and Paul Zimmermann, 2024,
   https://inria.hal.science/hal-03798376 */
static inline void
fast_two_sum(double *s, double *t, double a, double b)
{
  *s = a + b;
  double e = *s - a;
  *t = b - e;
}

static inline void d_mul(double *hi, double *lo, double ah, double al,
                         double bh, double bl) {
	double s, t;
	a_mul (hi, &s, ah, bh);
	t = __builtin_fma (al, bh, s);
	*lo = __builtin_fma (ah, bl, t);
} 

// this stores information computed within the fast path
// x/log(2) ~ extra_exponent + xs
// where extra_exponent is an integer and
// xs is an integer multiple of 2^-20 such that |xs - x/log(2)| < 2^-19.999
// (fracpart contains in its low 20 bits the value of xs*2^20)
typedef struct {
  int32_t extra_exponent;
  uint64_t fracpart;
  double xs;
} redinfo;

/* Implement the improved evaluation strategy of reference [1].
   Assume |x| < 2^14.
   Set need_accurate to true if the rounding test fails. */
static inline long double
fastpath(long double x, redinfo* ri, bool* need_accurate) {
	/* Strategy : compute x/log(2) and split it like
	   m + 2^-20 fracpart + xr
	   with m, fracpart integers.
	   Then, compute 2^(2^-20 fracpart) using tables and 2^xr using
	   a Taylor polynomial. 
	*/

	b96u96_u cvt_x; cvt_x.f = x;
	b64u64_u cvt_w, cvt_aux;

	/* Split x into xh0 + xl0, where |xl0| < ulp(xh0). We exploit the fact that x
	   is a normal number. Since |x| < 2^14, we have |xh0|<=2^14 and
	   |xl0| <= ulp(2^13) = 2^-39
	*/

	cvt_w.u = ((cvt_x.e&0x8000ul) << (63 - 15)) | (((cvt_x.e&0x7ffful) + (1023ul - 16383ul)) << (64 - 12)) |
		((cvt_x.m >> 11) & ~(1ul << 52)); // Explicitely remove leading 1 bit
	double xh0 = cvt_w.f;

	/* The bottom bit of x's mantissa has weight e - 63, were e is y's exponent.
	   Therefore, the exponent of xl should (at first) be e - 63 + 52 = e - 11
	*/
	cvt_w.u = ((cvt_x.e&0x8000ul) << (63 - 15)) | (((cvt_x.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12)) |
		(cvt_x.m & ((1ul << 11) - 1ul));

	// Replicate parasitic implicit leading bit
	cvt_aux.u = ((cvt_x.e&0x8000ul) << (63 - 15)) | (((cvt_x.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12));
	double xl0 = cvt_w.f - cvt_aux.f; // Remove implicit one introduced before


	/* Let ln2inv = ln2invh + ln2invl. Then
	   |1/ln(2) - ln2inv| < 2^-109.5
	*/
	static const double ln2invh = 0x1.71547652b82fep+0;
	static const double ln2invl = 0x1.777d0ffda0d24p-56;

	static const double C = 0x1.8p+32;
	double xh, xl;
	// Short-circuit d_mul, wining 1 op in critical path
	// Note that the high part of the result of the d_mul is xh0*ln2invh
	b64u64_u y = {.f = __builtin_fma (xh0, ln2invh, C)};
	d_mul (&xh, &xl, ln2invh, ln2invl, xh0, xl0);
	/* Note that |xh| < 2^15. That way, given how large is C, C and y.f are
	   in the same binade and ulp(y.f) = 2^-20. Therefore, y.f = r + C
	   where r is xh0*ln2invh rounded to 2^-20. Given that
	   |xh| <= 2^14*2^.6 (see below), the rounding error on xh is less than
	   ulp(2^14.6) = 2^-38. Therefore, |r - xh| < 2^-20 + 2^-38.
	   Moreover, since y.f and xh are rounded in the same direction,
	   we even have |r - xh| < 2^-20 (for rounding to nearest,
	   both rounding errors are bounded by 2^-21 and 2^-39, whose sum
	   is less than 2^-20).

	   Expanding the call to d_mul, the a_mul is exact. Since
	   |xh0 * ln2invh| < 2^14*2^.6 = 2^14.6, we get |xh| = |hi| <= 2^14.6
	   and |s| < ulp(hi) <= 2^-38. Since |ln2invl| < 2^-55 and
	   |xh0| <= 2^14, this implies |ln2invl*xh0+s| < 2^-41+2^-38 < 2^-37.8.
	   Therefore |t| <= 2^-37.8 and the rounding error on t is less than
	   ulp(2^-37.8) = 2^-90.
	   Since |ln2invh| < 2^.6 and |xl0| <= 2^-39,
	   |ln2invh*xl0 + t| < 2^-38.4 + 2^-37.8 < 2^-37.
	   Therefore |xl| < 2^-37 and the rounding error on xl is at most
	   ulp(2^-38) = 2^-90. The total rounding error of the d_mul() is thus
	   2^-90 + 2^-90 = 2^-89.

	   The error due to neglecting xl0*ln2invl is bounded by
	     |xl0*ln2invl| < 2^-39*2^-55.4 = 2^-94.4

	   The intrinsic error due to ln2invh + ln2invl not being a perfect
	   approximation of 1/ln(2) is bounded by
	     |x * (ln2inv - 1/ln(2))| < 2^14*2^-109.5 <= 2^-95.5
	   In summary: |xh + xl - x/log(2)| < 2^-89 + 2^-94.4 + 2^-95.5 < 2^-88.9.

	   If |xh| < 2^-20, we will need later on to bound |xl| by 2^-72.
	   If |xh| < 2^-20, since xh = o(ln2invh * xh0), necessarily
	   xh0 < t0 := 0x1.62e42fefa39fp-21, because if we multiply
	   ln2invh by t0 with rounding towards 0, we get 2^-20.
	   This implies |xl0| < ulp(t0) = 2^-73. Thus when expanding the
	   d_mul() call, we get |s| < ulp(hi) <= ulp(2^-21) = 2^-73,
	     |ln2invl*xh0+s| < 2^-55.4 * t0 + 2^-73 < 2^-72.82, and
	     |ln2invh*xl0+t| < 2^0.53 * 2^-73 + 2^-72.82 < 2^-71.63.
	   In this case the rounding error of d_mul() is bounded
	   by ulp(2^-72.82) + ulp(2^-71.63) <= 2^-125 + 2^-124 < 2^-123.4:
	     |xh + xl - (xh0 + xl0) * (ln2invh + ln2invl)| < 2^-123.4.

	   Since |1/ln(2) - ln2inv| < 2^-109.5 we deduce:
	     |xh + xl - x/log(2)| < 2^-123.4 + 2^-20 * 2^-109.5 < 2^-123.3.
	*/

	b64u64_u cvt = {.f = xh};
	bool do_red = cvt.e >= -20 + 0x3ff; // |xh| >= 2^-20

	if (__builtin_expect (do_red, 1)) {// |xh| >= 2^-20
		double remaining = xh - (y.f - C);
		/* Both differences below are exact by Sterbenz's lemma.
		   For y.f - C this follows from |xh0 * ln2invh| < 2^14.6,
		   thus C - 2^15 <= |y.f| <= C + 2^15.
		   Let r = y.f - C, we have shown above that |r - xh| < 2^-20,
		   thus if |xh| >= 2*2^-20, r and xh differ by at most a factor 2,
		   Sterbenz's lemma applies and xh - r is exact.
		   It remains the case |xh| < 2*2^-20. When |xh| >= 2^-20,
		   since |r - xh| < 2^-20 and r is an integer multiple of 2^-20,
		   the only possible value for |r| are 2^-20 and 2*2^-20 (with r
		   being of the same sign as xh). Then xh and r are in the same
		   binade, thus their difference is exact.*/

		fast_two_sum (&xh, &xl, remaining, xl);
		/* Let xh_old/xl_old be the values of xh/xl before this
		   fast_two_sum(), and xh/xl the values afterwards.
		   We have |remaining+xl_old| < 2^-20+2^-37. This ensures that
		   |xh| <= 2^-19.9999.
		   If remaining = 0 or remaining's exponent is at least that of
		   xl_old, then the rounding error is at most
		   2^-105*|xh| <= 2^-124.9999 and |xl| < ulp(xh) <= 2^-72.
		   If this is not the case, since |xl_old| < 2^-37 then necessarily
		   |remaining| < 2^-38 so that |remaining+xl_old| < 2^-38+2^-37 and
		   in the end |xh| <= 3*2^-38. We then know that the rounding error
		   is at most 3*2^-53*|xh| <= 2^-87.83 (Theorem 2 from ref. [2]).
		   Let xh = remaining + xl_old + delta_x, with |delta_x| < ulp(xh)
		   <= 2^-89. Then since |(xh + xl) - (remaining + xl_old)|
		   < 2^-87.83, We deduce |xl| < |delta_x| + 2^-87.83
		   <= 2^-89 + 2^-87.83.
		  It is easy to see that |xl| <= 2^-72 in that case too.
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

	/* Up to here, we have computed and split into parts the quantity
	   x/log(2), introducing absolute errors bounded by:

	   When do_red=false, i.e., |x| < 2^-20:
	   - 2^-123.4 by d_mul's rounding
	   - 2^-73 * ln2invl < 2^-128.4 by neglecting xl0*ln2invl
	   - 2^-20 * 2^-109.5 < 2^-129.5 by ln2inv's finite precision
	   These errors induce an absolute error bounded by:
	     | xh + xl - x / log(2) | < 2^-123.4 + 2^-128.4 + 2^-129.5
	                              < 2^-123.3
	   with |xh| <= 2^-20 and |xl| <= 2^-71.63 (r is considered as 0
	   in this case).
	   Thus xh + xl = x / log(2) + eps1 with |eps1| < 2^-123.3.
	   It follows 2^(xh + xl) = exp(x) * (1 + rho1)
	   with |rho1| < 2^eps1 - 1 < 2^-123.8.

	   When do_red=true, i.e., |x| >= 2^-20:
	   - 2^-89   by d_mul's rounding
	   - 2^-94.4 by neglecting xl0*ln2invl
	   - 2^-95.5 by ln2inv's finite precision
	   - 2^-87.83 by rounding in fast_two_sum
	   These errors induce an absolute error bounded by:
	     | r + xh + xl - x / log(2) | < 2^-89 + 2^-94.4 + 2^-95.5 + 2^-87.83
	                                  < 2^-87.284,
	   with r integer multiple of 2^-20, |r| < 2^15,
	     |xh| <= 2^-19.9999 and |xl| <= 2^-72.
	   Thus r + xh + xl = x / log(2) + eps1 with |eps1| < 2^-87.284.
	   It follows 2^(r + xh + xl) = exp(x) * (1 + rho1)
	   with |rho1| < 2^eps1 - 1 < 2^-87.812.
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
           where t3[i3] approximates 2^(i3/2^5),
                 t2[i2] approximates 2^(i2/2^10),
                 t1[i1] approximates 2^(i1/2^15),
                 t0[i0] approximates 2^(i0/2^20),
           thus t3[i3] * t2[i2] * t1[i1] * t0[i0] approximates 2^frac(r),
           where each table t3, t2, t1, t0 has its lower elements
           smaller than 1/2 ulp(1) = 2^-53. */

	d_mul(&frcp_acc0_h, &frcp_acc0_l,
		t0[i0][0], t0[i0][1],   // 2^(i0/2^20)
		t1[i1][0], t1[i1][1]);  // 2^(i1/2^15)
	/* frcp_acc0_h + frcp_acc0_l approximates 2^(i1/2^15+i0/2^20).
	   Each term t0[i0], t1[i1] is in [1, 2) and has
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

	d_mul(&frcp_acc2_h, &frcp_acc2_l,
		t2[i2][0], t2[i2][1],   // 2^(i2/2^10)
		t3[i3][0], t3[i3][1]);  // 2^(i3/2^5)
	/* The same analysis as above applies:
	   |frcp_acc2_h + frcp_acc2_l - 2^(i3/2^5+i2/2^10)| < 2^-102.1
	   with |frcp_acc2_l| < 2^-50.4.
	*/

	d_mul(&xs_pow2_h, &xs_pow2_l, frcp_acc0_h, frcp_acc0_l,
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
	   (again from routine check_t3t2t1t0()).
	*/

	/* Evaluating the Taylor polynomial for 2^xr where xr = xh + xl.
	   This is done both for |x| < 2^-20 and |x| >= 2^-20.
	   We evaluate 2^xr through a polynomial approximation. Note that
	   |xh| <= 2^-19.9999 and |xl| <= 2^-71.63, therefore |xr| <= 2^-19.999.
	
	   Over this interval, Sollya gives the polynomial
	   1 + x * 0x1.62e42fefa39ef35793c766d326cp-1 + x^2*0x1.ebfbdff82c696p-3
	   + x^3 * 0x1.c6b08d704a1cdp-5
	   precise to 2^-89.218 (absolute error, cf exp.sollya).
	*/

	double xsq = xh * xh;
	/* Neglecting 2*xl*xh + xl^2 brings an error of at most
	   |2*xl*xh + xl^2| <= 2 * 2^-71.63 * 2^-19.999 + 2^-71.63 * 2^-71.63
	                    <= 2^-90.629.
	   Since |xh| <= 2^-19.999, we have |xh*xh| <= 2^-39.998. The rounding
	   error on xsq is therefore at most ulp(2^-39.998) = 2^-92, and
	     |xsq| <= 2^-39.998 + 2^-92 <= 2^-39.997.
	   We have thus |xsq - xr^2| <= 2^-90.629 + 2^-92 <= 2^-90.157.
	*/
	double orders23 = xsq * __builtin_fma (xh, 0x1.c6b08d704a1cdp-5,
	                                           0x1.ebfbdff82c696p-3);
	/* We note A = 0x1.c6b08d704a1cdp-5 and B = 0x1.ebfbdff82c696p-3.
	   Analyzing the fma call:
	   Neglecting xl * A imparts an error bounded by
	     |A * xl| <= A*2^-71.63 <= 2^-75.8
	   Since |xh| <= 2^-19.999, |A*xh+B| <= 2^-19.999*A + B < 1/4 - 0.008.
	   This implies that the fma's result is strictly less than 1/4.
	   The rounding error of the fma is therefore at most ulp(1/8) = 2^-55.
	   The total error evaluating Axr+B is thus at most
	     2^-55 + 2^-75.8 <= 2^-54.999.

	   Given the errors on each factor, the product xsq * fma() carries an
	   intrinsic error
	     |xr|^2*2^-54.999 + 2^-90.157*|Axr+B| + 2^-90.157*2^-54.999
	   Since |xr|<= 2^-19.999 we check that |Axr+B| <= 2^-2.049 and thus
	   the error is at most 2^-92.011.

	   Since |xsq| <= 2^-39.997 and |A*xh+B| < 1/4 - 0.008, the product
	   is bounded by 2^-39.997 * (1/4 - 0.008) < 2^-42.04. The rounding
	   error on orders23 is thus at most ulp(2^-42.04) = 2^-95.
	   Therefore |orders23| <= 2^-42.04 + 2^-95 < 2^-42.03.
	   The total error on orders23 is at most 2^-92.011+2^-95 <= 2^-91.839.
	*/

	double order1h, order1l;
	static const double coeff1h = 0x1.62e42fefa39efp-1;
	static const double coeff1l = 0x1.abc9e3b369936p-56;
	// 0x1.62e42fefa39ef35793c766d326cp-1 = coeff1h + coeff1l
	d_mul (&order1h, &order1l, coeff1h, coeff1l, xh, xl);
	/* Let's expand the d_mul call.
	   Since |coeff1h| < 2^-0.5287 and |xh| <= 2^-19.999 we have
	         |ah*bh| <= 2^-20.527. This implies
	   |order1h| < 2^-20.5 and |s| < ulp(2^-20.5) = 2^-73.
	   Since |coeff1l| <= 2^-55.25, we compute that
	     |coeff1l*xh + s| <= 2^-55.25*2^-19.999 + 2^-73 <= 2^-72.724.
	   This ensures that the rounding error computing t is at most
	         ulp(2^-72.724) = 2^-125 and that |t| <= 2^-72.7.
	   Since |coeff1h| <= 2^-0.528 and |xl| < 2^-71.63, we compute that
	     |coeff1h*xl + t| <= 2^-0.528 * 2^-71.63 + 2^-72.7 <= 2^-71.403.
	   The rounding error on order1l is therefore at most ulp(2^-71.403)
	   = 2^-124. We also get |order1l| < 2^-71.4.
	   The total rounding error is at most 2^-125 + 2^-124 = 2^-123.415:

	   The error due to neglecting xl*coeff1l is at most
	     |xl*coeff1l| <= 2^-71.63 * 2^-55.25 <= 2^-126.88.
	   The total error on order1 is at most 2^-123.415 + 2^-126.88 <= 2^-123.289:
	     |order1h + order1l - (coeff1h + coeff1l) * (xh + xl)| < 2^-123.289.
	*/

	double finalh, finall;
	fast_two_sum (&finalh, &finall, 1, orders23);
	/* Since |orders23| < 2^-42.03, clearly |finalh| < 2, so that
	     |finalh| <= 1 + 2^-42.03 + ulp(1) <= 2^0.001.
	   The arguments are in the right order, so this fast_two_sum
	   introduces an error at most 2^-105*2^0.001 <= 2^-104.999.
	   Also since |finalh| < 2 we get |finall| < ulp(1) = 2^-52.
	*/

	double tmp;
	fast_two_sum(&finalh, &tmp, finalh, order1h);
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
	   - 2^-91.839  computing orders23,
	   - 2^-123.289 computing order1,
	   - 2^-104.999 in the first fast_two_sum,
	   - 2^-104.998 in the second fast_two_sum,
	   - 2^-102.415 in the last sum.
	  The polynomial itself was only precise to 2^-89.218. Therefore,
	  we have computed 2^xr with error at most :
	     2^-91.839 + 2^-123.289 + 2^-104.999 + 2^-104.998 + 2^-102.415
	     + 2^-89.218 <= 2^-89.0005.
	   Since xr >= -2^-19.999, this gives a relative error rho3 less than
	   2^-89.0005/2^(-2^-19.999) < 2^-89.0004:
	     finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-89.0004
	*/

	int64_t err; // error bound
	if(__builtin_expect(do_red,1)) {
		d_mul(&finalh, &finall, finalh, finall, xs_pow2_h, xs_pow2_l);
		/* We have xs_pow2_h + xs_pow2_l = 2^frac(r) * (1 + rho2)
		   with |rho2| < 2^-99.1, and
		   finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-89.0004.
		   The intrinsic relative error of the product is at most
		   (1 + rho2) * (1 + rho3) - 1 <= 2^-99.1 + 2^-89.0004
		                                + 2^-99.1*2^-89.0004 <= 2^-88.99908.

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
		   (1 + 2^-88.99908)(1 + rho1)(1 + rho4) - 1 <= 2^-87.286.
		*/
		err = -87;
		/* Remark: some tests fail with -90, thus the error analysis
		   is quite tight. */
	} else {
		extra_exponent = 0;
		/* In the case |x| < 2^-20, only the errors on xh + xl (rho1)
		   and on the polynomial evaluation (rho3) do appear, with
		   |rho1| < 2^-123.8 and |rho3| < 2^-89.0004, thus we get:
		   (1 + rho1) * (1 + rho3) - 1 < 2^-89.0003. */
		err = -89;
		/* Remark: some tests fail with -90, thus the error analysis
		   is very tight. */
	}

	/* In all cases we have:
	   |finalh + finall - 2^frac(r) * 2^xr| < 2^err*|finalh + finall| */

	/* From exp2/exp2l.c */
	fast_two_sum(&finalh, &finall, finalh, finall);
	// This add a 2^-105 relative error but ensures there is no overflow
	// in mh = ml+mlt

	b64u64_u th = {.f = finalh}, tl = {.f = finall};
	// the high part is always positive, the low part can be positive
	// or negative, thus we mask the sign bit
	long eh = th.u>>52, el = (tl.u>>52) & 0x3ff, de = eh - el;

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
	// We use a kind of floating representation where m = mh||ml is the
	// mantissa (whose leading 1 has weight 2^exponent) and
	// extra_exponent is the exponent.

	int64_t eps = (mh >> (-err - 64));
	// In both cases (err = -87 or err = -89),
	// we have eps > 2^err * mh - 2^-63, scaled so we can add it to ml.
	// Since mh has its most significant bit set, it follows
	// eps > (2^err - 2^-127) * mh, and err > 2^-87.286 * mh or
	// err > 2^-89.0003 * mh respectively.

	mh += mlt; // add contribution from low part
	if(__builtin_expect(!(mh>>63),0)){
		// the low part is negative and
		// can unset the msb so shift the number back
		mh = (mh << 1) | ((uint64_t)ml >> 63);
		ml = (uint64_t)ml<<1;
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
		ml ^= (1ul << 63);
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

	// We had a denormal but rounding made it into the smallest normal
	if(__builtin_expect((mh>>63) && !wanted_exponent, 0)) {
		wanted_exponent = 1;
	}

	b96u96_u v;	
	v.m = mh; // mantissa
	v.e = wanted_exponent; //extra_exponent + 0x3c00 + eh; // exponent

	// Given the signedness, this test expresses that ml >= -eps and that
	// ml <= eps.	This holds true because eps fits in 128-87=41 bits.
	bool b1 = (uint64_t)ml + eps <= (uint64_t)(2*eps);

	// Denormals *inside* the computation don't seem to pause a problem
	// given the error analysis (we used absolute bounds mostly)
	// rounding test
	*need_accurate = b1;
	if(__builtin_expect(b1 != 0, 0)) {
		ri->fracpart = fracpart;
		ri->xs = y.f - C;
		/* y.f - C = r (see above). Since we have
		   xh + xl = x / log(2) + eps1 with |eps1| < 2^-123.3,
		   |r - xh| < 2^-20 and |xl| < 2^-37, we have:
		   |xs - x/log(2)| < 2^-20 + 2^-37 + 2^-123.3 < 2^-19.999 */
		ri->extra_exponent = extra_exponent;
	}

	// Infinity output case
	if(__builtin_expect(wanted_exponent >= 32767, 0)) {
#ifdef CORE_MATH_SUPPORT_ERRNO
          errno = ERANGE; // overflow
#endif
          return 0x1p16383L + 0x1p16383L;
	}
	return v.f;
}

typedef struct {
	double h,l;
} dd;

// r has value a * 2^exp
static inline
void tint_mul2exp(tint_t* r, int64_t a, int64_t exp) {
	r->sgn = (uint64_t)a >> 63;
	if(r->sgn) {a = -a;}
	
	if(__builtin_expect(!a, 0)) {
		cp_tint(r, &ZERO);
	}

	int clz = (a) ? __builtin_clzll(a) : 0;
	r->ex = exp - clz + 64;
	r->h  = (uint64_t)a << clz;
	r->m  = r->l = 0;
}

/*
Convert a double double into tint_t representation.
This is minimalistic : it assumes toload->h is nonzero,
that toload->h + toload->l has the binade of toload->h,
and that the exponent difference is less than 75.

Under those assumptions (which are satisfied by the 
lookup tables t0...t3) the operation is exact.
*/
static inline void
load_dd (tint_t *a, const dd* toload) {
	b64u64_u u = {.f = toload->h};
	a->sgn = u.u >> 63;
	uint64_t ax = u.u & (-1l ^ (1ul << 63));

	u.f = toload->l;
	uint64_t bx = u.u & (-1l ^ (1ul << 63));

	// We assume toload->h is not 0
	int64_t exp = (ax >> 52) - 1023;

	a->ex = exp + 1;
	unsigned __int128 mantissa  = (1ul << 63) | (ax << 11);
	mantissa <<= 64;

	a->_h = mantissa;
	a->l = 0;
	if(__builtin_expect(bx >> 52 != 0, 1)) { // toload->l != 0
		int de = (ax >> 52) - (bx >> 52);
		unsigned __int128 mantissa_b =  (1ul << 52) | (bx & ((1ul << 52) - 1));
		mantissa_b <<= 75 - de; // If de was 0, we would shift 12+63

		if((u.u>>63) ^ a->sgn) { // We do *not* handle underflows/overflows
			mantissa_b = -mantissa_b;
		}
		mantissa += mantissa_b;
	}

	a->_h = mantissa;
	a->l  = 0;
}

// load x into a tint assuming it is not a denormal (exact).
static inline void
load_ld(tint_t *t, long double x) {
	b96u96_u cvt = {.f = x};
	// for tints, a number with exponent 0 is in [1/2, 1)
	// for long double, a a number with (unbiased) exponent 0 is in [1, 2)
	// thus we have to add 1 to the unbiased exponent
	t->ex = 1 + ((cvt.e & 0x7fff) - 16383);
	t->h  = cvt.m;
	t->m  = t->l = 0;
	t->sgn = cvt.e >> 15;
}

/*
  pow2_xs(x, fracpart, &corr) puts a value c in corr
  such that 2^fracpart * exp(c/2^168) = x * (1 + e) with
  |e| < 2^-167.026, where by "fracpart" we mean the low 20 bits
  of fracpart, divided by 2^20.
*/
static inline void
pow2_xs (tint_t *x, uint64_t fracpart, int64_t* corr) {
	// Decompose fracpart as i0/2^20 + i1/2^15 + i2/2^10 + i3/2^5
	int i0 = fracpart & 0x1f;
	int i1 = (fracpart >> 5) & 0x1f;
	int i2 = (fracpart >> 10) & 0x1f;
	int i3 = (fracpart >> 15) & 0x1f;

	/*
	  By construction, we have for all k, 0 <= k < 4,
	  2^(ik/2^(20 - 5k)) * exp(tk_corr[ik]/2^168 + errk) = tmpk
	  with |err0| < 2^-169.005, |err1| < 2^-169.049, |err2| < 2^-169.031,
	  and |err3| < 2^-169.024.
	  Therefore, discounting rounding,
	  2^fracpart * exp(corr0 + ... + corr3) = tmp0 * ... * tmp3 * exp(-t)
	  for some t with |t| < 2^-169.005 + 2^-169.049 + 2^-169.031 + 2^-169.024
	                      < 2^-167.027.
	*/

	tint_t tmp0[1], tmp1[1], tmp2[1], tmp3[1];
	load_dd (tmp0, (dd*)(&t0[i0]));	int64_t corr0 = t0_corr[i0];
	load_dd (tmp1, (dd*)(&t1[i1]));	int64_t corr1 = t1_corr[i1];
	load_dd (tmp2, (dd*)(&t2[i2]));	int64_t corr2 = t2_corr[i2];
	load_dd (tmp3, (dd*)(&t3[i3]));	int64_t corr3 = t3_corr[i3];

	tint_t acc0[1], acc1[1];
	mul_tint(acc0, tmp0, tmp1);
	mul_tint(acc1, tmp2, tmp3);

	mul_tint(x, acc0, acc1);

	/*By mul_tint's analysis, acc0 = tmp0*tmp1*(1 + s0) with |s0| <= 2^-187.67.
	  Same holds for acc1 with some s1. Then
	    x = tmp0 *...* tmp3 * (1 + s0)(1 + s1)(1 + s2)
	  with again |s2| <= 2^-187.67. Therefore
	    x = tmp0 *...* tmp3 * (1 + s)
	  with |s| = (1 + |s0|)(1 + |s1|)(1 + |s2|) - 1 < 2^-186.08
	*/

	*corr = corr0 + corr1 + corr2 + corr3;
	/* Since each |corrk| < 2^61, we have |corr| < 2^63 thus no
	overflow occurs. */

	/*Accounting for t, we end up with
	    2^fracpart * exp(corr/2^168) = x * (1 + s) exp(-t)
	  Since |s| < 2^-186.08 and |t| <= 2^-167.027,
	  we introduced a relative error of at most
	  (1 + 2^-186.08) * exp(2^-167.027) - 1 < 2^-167.026.
	*/
}

/*
  Put in xred a value such that xred = x - xs*log(2) - correction/2^168
  with absolute error at most 2^-173.6.
  Ensure |xred| < 2^-20.
*/
static inline void
compute_reducted(tint_t *xred,
                 const tint_t* x, double xs, int64_t correction) {
	/* We hold an approximation of log(2) such that |logeff2 - log(2)| <= 2^-193
	   since |xs| <= 2^15, this introduces an error of at most 2^-178.
	*/
	static const tint_t logeff2 = {
		.h = 0xb17217f7d1cf79abUL,
		.m = 0xc9e3b39803f2f6afUL,
		.l = 0x40f343267298b62eUL,
		.ex = 0, .sgn = 0};

	tint_t t_xs;
	tint_fromd(&t_xs, -xs); // exact

	// Scale logeff2 by xs
	mul_tint(xred, &logeff2, &t_xs);
	add_tint(xred, xred, x);
	/* We compute that |t_xs * logeff2| <= 2^15*2^-.5, so an ulp of the xred
	   is at most 2^(15 - 192) = 2^-177. The product has <= 10 ulp error so its
	   rounding error is at most 10*2^-177 <= 2^-173.678.
	   The addition has rounding error <= 2 ulps.
	   Since |xs - x/log(2)| < 2^-19.999 we deduce that
	   |x - xs * logeff2| < 2^-20.5 so that the addition's error
	   is at most 2 * ulp_192(2^-20.5) = 2^-211.
	*/

	tint_t corr;
	tint_mul2exp(&corr, correction, -168); // exact
	corr.sgn ^= 1; // We want to subtract. Maybe bake that in the tables

	add_tint(xred, xred, &corr);
	/* Given |correction| < 2^63, we can show that in the end, |xred| < 2^-20.
	   The addition's error is again at most 2^-211

	   Summing the errors we get :
	     - 2^-178     because of logeff2's imprecision
	     - 2^-173.678 for the product xs * logeff2
	     - 2^-211    for the first addition
	     - 2^-211    for the second addition
	   The total error is therefore less than
	       2^-178 + 2^-173.678 + 2^-210 <= 2^-173.6.
	*/
}

struct fint {
	int ex;
	int64_t m; // 2^exp * m/2^63, m represented in 2's complement.
};

// Given x with |x| < 2^-20, put in y an approximation of exp(x)
// with absolute error at most 2^-175.298: |y - exp(x)| < 2^-175.298
static inline void
evaluate_polynomial(tint_t *y, const tint_t* x) {
	/* Evaluate exp(x) with the 7th degree Taylor polynomial,
	   with coefficients approximated at 192 bits.
	   The intrinsic absolute error of the polynomial is bounded by
	   2^-175.299 (cf exp_accurate.sollya).
	   This includes the error due to the approximated coefficients. */

	tint_t x2[1]; mul_tint(x2,  x,  x);
	/* We have |x| <= 2^-20 so |x^2| <= 2^-40. Therefore |x2| <= 2^-40
           and the rounding error on x2 is at most
           10 ulp_192(2^-41) = 10*2^(-41-191) <= 2^-228.6
	*/
	tint_t x4[1]; mul_tint(x4, x2, x2);
	/* We have |x2| <= 2^-40. Therefore |x2*x2| <= 2^-80 which implies
	   |x4| <= 2^-80 and a rounding error at most
	   10 ulp_192(2^-81) <= 2^-268.6
	   Since |x^2 - x2| <= 2^-228.6, we have
	   |x2*x2 - x^4| <= |x2 - x^2| * |x2 + x^2|
	                 <= 2^-228.6 * (2^-40 + 2^-40)
	                 <= 2^-267.6
	   Therefore, we have |x4 - x^4| <= 2^-267.6 + 2^-268.6 <= 2^-267.015
	*/

	static const tint_t c2 = {.h = 0x8000000000000000ul,
	                          .m = 0x0000000000000000ul,
	                          .l = 0x0000000000000000ul,
	                          .ex = 0, .sgn = 0};
	static const tint_t c3 = {.h = 0xaaaaaaaaaaaaaaaaul,
	                          .m = 0xaaaaaaaaaaaaaaaaul,
	                          .l = 0xaaaaaaaaaaaaaaabul,
	                          .ex = -2, .sgn = 0};

	tint_t order23[1];
	mul_tint(order23, &c3, x);
	/* Note that |x*c3| <= 2^-22.584. Therefore |order23| <= 2^-22.583 and
	   the rounding error is at most 10ulp_192(2^-23) <= 2^-210.678.
	*/

	add_tint(order23, order23, &c2);
	/* Let order23 designate the value of order23 at input. We have
	   |1/2 + order23| <= .5 + 2^-22.583. Therefore the result has
	   magnitude at most .5 + 2^-22.582 and the rounding error is at most
	   2ulp_192(1/2) = 2^-191. The total error on c2 + c3*x is therefore
	   at most 2^-210.678 + 2^-191 < 2^-190.999.
	*/

	mul_tint(order23, order23, x2);
	/* The errors on c2 + c3*x and x^2 create an intrinsic error of at most
	   (.5 + 2^-22.583)*2^-228.6 + 2^-190.999*2^-40 <= 2^-229.136.
	   Also, calling order23 the input value, we compute that
	     |order23*x2| <= (.5 + 2^-22.583)*2^-40 <= 2^-40.999.
	   This ensures that the result has magnitude at most 2^-40.998 and
	   that the rounding error is at most 10ulp_192(2^-41) <= 2^-228.678.
	   The total error computing orders 2 and 3 of the polynomial is
	   therefore at most 2^-229.136 + 2^-228.678 <= 2^-227.888.
	*/

	static const tint_t c4 = {.h = 0xaaaaaaaaaaaaaaaaul,
	                          .m = 0xaaaaaaaaaaaaaaaaul,
	                          .l = 0xaaaaaaaaaaaaaaabul,
	                          .ex = -4, .sgn = 0};

	static const tint_t c5 = {.h = 0x8888888888888888ul,
	                          .m = 0x8888888888888888ul,
	                          .l = 0x8888888888888889ul,
	                          .ex = -6, .sgn = 0};

	static const tint_t c6 = {.h = 0xb60b60b60b60b60bul,
	                          .m = 0x60b60b60b60b60b6ul,
	                          .l = 0x0b60b60b60b60b61ul,
	                          .ex = -9, .sgn = 0};

	static const tint_t c7 = {.h = 0xd00d00d00d00d00dul,
	                          .m = 0x00d00d00d00d00d0ul,
	                          .l = 0x0d00d00d00d00d01ul,
	                          .ex = -12, .sgn = 0};

	tint_t order45[1];
	mul_tint(order45, &c5, x);
	/* We have |x*c5| <= 2^-26.906 therefore |order45| <= 2^-26.905.
	   The error in the multiplication is at most
	   10ulp_192(2^-27) <= 2^-214.678.
	*/

	add_tint(order45, order45, &c4);
	/* Calling order45 the input value, we have |order45 + c4| <= 2^-4.584.
	   This ensures that the result is at most 2^-4.583 and that the error
	   computing the sum is at most 2ulp_192(2^-5) = 2^-195.
	   The total error computing |c4 + c5*x| is therefore bounded by
	   2^-195 + 2^-214.678 <= 2^-194.999.
	*/

	tint_t order67[1];
	mul_tint(order67, &c7, x);
	/* We have |c7*x| <= 2^-32.299 therefore |order67| <= 2^-32.298 and the
	   error in the product is at most 10ulp_192(2^-33) <= 2^-220.678.
	*/

	add_tint(order67, order67, &c6);
	/* Calling order67 the input value, we have |order67 + c6| <= 2^-9.491.
	   Therefore the result's magnitude is at most 2^-9.490 and the error
	   doing the addition is at most 2ulp_192(2^-10) = 2^-200.
	   The total error computing |c6 + c7*x| is therefore bounded by
	   2^-200 + 2^-220.678 <= 2^-199.999.
	*/

	mul_tint(order67, order67, x2);
	/* The intrinsic error of the product is
	   2^-9.490*2^-228.6 + 2^-199.999*2^-40 <= 2^-237.749.
	   We check that (order67 denoting the input value)
	     |order67*x2| <= 2^-9.490*2^-40 <= 2^-49.490.
	   This implies that the result's magnitude is at most 2^-49.489 and
	   that the error made computing the product is at most
	   10ulp_192(2^-50) <= 2^-237.678.
	   The total error computing x^2*(c6 + c7*x) is thus at most
	   2^-237.749 + 2^-237.678 <= 2^-236.713.
	*/

	tint_t order4567[1];
	add_tint(order4567, order45, order67);
	/* The error due to order45 and order67's errors is at most
	   2^-194.999 + 2^-236.713 <= 2^-194.998.
	   We check |order45+order67| <= 2^-4.583 + 2^-49.489 <= 2^-4.582.
	   This implies that |order4567| < 2^-4.581 and that the error made in
	   the sum is at most 2ulp_192(2^-5) = 2^-195. The total error
	   computing c4 + c5*x + c6*x^2 + c7*x^3 is thus at most
	   2^-194.998 + 2^-195 <= 2^-193.998.
	*/

	mul_tint(order4567, order4567, x4);
	/* The error due to the inputs' errors is at most
	   2^-193.998*2^-80 + 2^-4.582*2^-267.015 < 2^-271.346.
	   Also, we compute that (order4567 denoting the input value)
	     |order4567*x4| <= 2^-4.582*2^-80 <= 2^-84.582.
	   Therefore the result's magnitude is at most 2^-84.581 and the error
	   computing the product is at most 10ulp_192(2^-85) <= 2^-272.678.

	   The total error computing c4*x^4 + c5*x^5 + c6*x^6 + c7*x^7 is
	   therefore at most 2^-271.346 + 2^-272.678 <= 2^-270.863.
	*/

	add_tint(y, &ONE, x);
	add_tint(y, y, order23);
	add_tint(y, y, order4567);
	/* In these additions, the result is always strictly less than 2.
	   Each one therefore incurs an error of at most 2ulp_192(1) = 2^-190.
	   The total error of this step is at most 3*2^-190.

	   Propagating the errors of order23 and order4567, we get a total
	   error on the polynomial evaluation of
	   3*2^-190 + 2^-227.888 + 2^-270.863 <= 2^-188.415.

	   Doing the additions in reverse order gives better precision.
	   However, ONE and x are immediately available whereas order23 and
	   order4567 are results in the critical path (and anyway this error
	   is dominated by the polynomial approximation error).
	   Given the polynomial's intrinsic error, we have |exp(x)-y|
	   at most 2^-188.415 + 2^-175.299 <= 2^-175.298.
	*/
}

// accurate path, where ri contains some information computed in the fast path:
// x/log(2) ~ extra_exponent + 2^-20 fracpart + xs
__attribute__((cold))
static
long double accurate_path(long double x, const redinfo* ri) {
	tint_t tx[1];
	load_ld(tx, x); // exact
	tint_t final[1];
	if(tx->ex > -20) { // |x| >= 2^-20
		int64_t correction;
		tint_t p2_xs[1];
		pow2_xs (p2_xs, ri->fracpart, &correction);

		tint_t xred[1];
		compute_reducted (xred, tx, ri->xs, correction);
		tint_t poly[1];
		evaluate_polynomial (poly, xred);

		mul_tint(final, poly, p2_xs);
		final->ex += ri->extra_exponent;
	} else { // |x| < 2^-20
		evaluate_polynomial (final, tx);
	}

  /*Summing up the errors :
	   - computing 2^fracpart introduced a relative error of at most 2^-167.026
	     (function pow2_xs):
	     2^fracpart * exp(corr/2^168) = x * (1 + e1) with |e1| < 2^-167.026
	   - the reduction introduced an absolute error of at most 2^-173.6:
	     xred = x - xs*log(2) - corr/2^168 + d2 with |d2| < 2^-173.6
	     thus when taking the exponential we get:
	     exp(x) = 2^xs * exp(corr/2^168) * (1 + e2)
	     with |e2| < exp(2^-173.6) - 1 < 2^-173.599 (function compute_reducted)
	   - the polynomial evaluation introduced an absolute error < 2^-175.298
	     (function evaluate_polynomial):
	     |poly - exp(xred)| < 2^-175.298.
	     Since |xred| < 2^-20, this error translates to a relative error of at
	     most 2^-175.298/exp(-2^-20) = 2^-175.297.
	
	  The total relative error of the accurate path is therefore at most
	  (1 + 2^-167.026)*(1 + 2^-173.599)*(1 + 2^-175.297) - 1 < 2^-167.006.

	  If we compute all worst cases with bacsel and -m 102, then we can get
	  rid of the rounding test below. Indeed, bacsel with -m 102 computes
	  all inputs such that |exp(x) - z| < 2^-102 ulp(z), where z is a 65-bit
	  floating-point (exact long double or midpoint).
	  Thus if x was not output by bacsel, we have:
	  |exp(x) - z| >= 2^-102 2^(-64)|z| for all z.

	   Let y be the approximation of exp(x) we have. We know
	   |exp(x) - y| < 2^-167.006|y|. Assume the confidence interval crosses a 
	   rounding boundary z and that x is not output by bacsel. We then have :
	     - |z - y| <= 2^-167.006|y|
	     - |exp(x) - y| <= 2^-167.006|y|
	     - |exp(x) - z| >= 2^-166|z|
	   By the triangular inequality we get :
	     2 * 2^-167.006 |y| >= 2^-166|z|
	                        >= 2^-166(1 - 2^-167.006)|y|
	   This is absurd. Therefore, if x is not an exception, then the confidence
	   interval around y does not contain any rounding boundary which ensures
	   correct rounding.
	*/

	/* eps is >= 2^-167.006 of the result, scaled for addition with final.l
	   (the difference between 2^(-167.006+128)*h and 2^(-167+128)*h is at
	   least 2^16, thus largely dominates the terms m and l that are
	   neglected in the shift) */

	final->ex += 16383 - 1; // binary80 exponent shift
	if(final->ex <= 0) {
		int shiftby = 1 - final->ex;
		if(__builtin_expect(shiftby == 64, 0)) {
			return 0x1p-16445L * .75L;
		}

		if(__builtin_expect(shiftby > 64, 0)) {	
				return 0x1p-16445L * .25L;
		}
		rshift (final, final, shiftby);

		final->ex = 0;
	}

	float op = 1.0f + 0x1p-25f, om = 1.0f - 0x1p-25f;
	if(op == om) {
		final->h += final->m >> 63;
		final->m ^= 1ul << 63;
	} else if(op > 1.0f) {
		final->h += 1;
	}

	if(__builtin_expect(!final->h, 0)) {
		final->h = 1ul << 63;

		final->l >>= 1;
		final->l |= (final->m & 1) << 63;
		final->m /= 2; // Signed semantics matter
		final->ex++;
	}

	if(__builtin_expect((final->h>>63) && !final->ex, 0)) {
		final->ex = 1;
	}

	if(__builtin_expect(final->ex >= 32767, 0)) {
		return 0x1p16383L + 0x1p16383L;
	}

        /* The search for hard-to-round cases is done, thus at this point
           we are sure that all values are correctly rounded. */

	b96u96_u retval;
	retval.e = final->ex;
	retval.m = final->h;

	return retval.f;
};

__attribute__((cold))
static
long double catch_exceptions(long double x, bool* caught) {
 
	/* upper_except holds pairs (x, y) where exp(x) is rounded down to y
	   when rounding to nearest (the real value is a bit above y).
	   lower_except holds pairs where exp(x) is rounded up to y when rounding
	   to nearest (the real value is a bit below y).

	   We do not expect a lot of exceptions; if they become too numerous
	   binary search would be more efficient.
	*/
#define UPPER_EXCEPT 21
static const long double upper_except[UPPER_EXCEPT][2] = {
{-0x1.0000000000000002p-62L,0x1.fffffffffffffff8p-1L},
{-0x1.0000000000000004p-61L,0x1.fffffffffffffffp-1L},
{-0x1.8000000000000012p-60L,0x1.ffffffffffffffdp-1L},
{-0x1.0000000000000008p-60L,0x1.ffffffffffffffep-1L},
{-0x1.8000000000000024p-59L,0x1.ffffffffffffffap-1L},
{-0x1.000000000000001p-59L,0x1.ffffffffffffffcp-1L},
{-0x1.c000000000000062p-58L,0x1.ffffffffffffff2p-1L},
{-0x1.8000000000000048p-58L,0x1.ffffffffffffff4p-1L},
{-0x1.4000000000000032p-58L,0x1.ffffffffffffff6p-1L},
{-0x1.000000000000002p-58L,0x1.ffffffffffffff8p-1L},
{-0x1.c0000000000000c4p-57L,0x1.fffffffffffffe4p-1L},
{-0x1.800000000000009p-57L,0x1.fffffffffffffe8p-1L},
{-0x1.4000000000000064p-57L,0x1.fffffffffffffecp-1L},
{-0x1.000000000000004p-57L,0x1.ffffffffffffffp-1L},
{-0x1.c000000000000188p-56L,0x1.fffffffffffffc8p-1L},
{-0x1.a000000000000152p-56L,0x1.fffffffffffffccp-1L},
{-0x1.800000000000012p-56L,0x1.fffffffffffffdp-1L},
{-0x1.60000000000000f2p-56L,0x1.fffffffffffffd4p-1L},
{-0x1.40000000000000c8p-56L,0x1.fffffffffffffd8p-1L},
{-0x1.20000000000000a2p-56L,0x1.fffffffffffffdcp-1L},
{-0x1.000000000000008p-56L,0x1.fffffffffffffep-1L},
};
#define LOWER_EXCEPT 22
static const long double lower_except[LOWER_EXCEPT][2] = {
{0x1.1fffffffffffff5ep-56L,0x1.000000000000012p+0L},
{0x1.3fffffffffffff38p-56L,0x1.000000000000014p+0L},
{0x1.5fffffffffffff0ep-56L,0x1.000000000000016p+0L},
{0x1.7ffffffffffffeep-56L,0x1.000000000000018p+0L},
{0x1.9ffffffffffffeaep-56L,0x1.00000000000001ap+0L},
{0x1.bffffffffffffe78p-56L,0x1.00000000000001cp+0L},
{0x1.3fffffffffffff9cp-57L,0x1.00000000000000ap+0L},
{0x1.7fffffffffffff7p-57L,0x1.00000000000000cp+0L},
{0x1.bfffffffffffff3cp-57L,0x1.00000000000000ep+0L},
{0x1.ffffffffffffffp-57L,0x1.00000000000001p+0L},
{0x1.ffffffffffffff8p-58L,0x1.000000000000008p+0L},
{0x1.bfffffffffffff9ep-58L,0x1.000000000000007p+0L},
{0x1.fffffffffffffffep-64L,0x1.0000000000000002p+0L},
{0x1.3fffffffffffffcep-58L,0x1.000000000000005p+0L},
{0x1.7fffffffffffffb8p-58L,0x1.000000000000006p+0L},
{0x1.7fffffffffffffdcp-59L,0x1.000000000000003p+0L},
{0x1.ffffffffffffffcp-59L,0x1.000000000000004p+0L},
{0x1.7fffffffffffffeep-60L,0x1.0000000000000018p+0L},
{0x1.ffffffffffffffep-60L,0x1.000000000000002p+0L},
{0x1.fffffffffffffffp-61L,0x1.000000000000001p+0L},
{0x1.fffffffffffffff8p-62L,0x1.0000000000000008p+0L},
{0x1.fffffffffffffffcp-63L,0x1.0000000000000004p+0L},
};

	for(unsigned i = 0; i < UPPER_EXCEPT; ++i) {
		if(__builtin_expect(x == upper_except[i][0], 0)) {
			long double y = upper_except[i][1];
			*caught = true;
			return y + 0x1.p-16445L;
		}
	}
	for(unsigned i = 0; i < LOWER_EXCEPT; ++i) {
		if(__builtin_expect(x == lower_except[i][0], 0)) {
			long double y = lower_except[i][1];
			*caught = true;
			return y -  0x1.p-16445L;
		}
	}
	*caught = false;
	return x;
}

long double cr_expl(long double x) {
	b96u96_u cvt_x = {.f = x};
	int e = cvt_x.e & 0x7fff;


	if (__builtin_expect(e >= 14 + 16383, 0)) { // |x| >= 2^14
		if(__builtin_expect(e == 0x7fff, 0)) {
			if (cvt_x.e == 0xffff && cvt_x.m == 0x8000000000000000ul) // -Inf
				return 0x0p0L;
			return x+x; // Nan or +Inf.
			/* Makes signalling NaNs raise the invalid exception
			   Note that qNaN+qNaN does not raise it, and +Inf + (+Inf) does not
			   raise overflow. */
		}

		// Note that exp(2^14) > 2^16384 and that exp(-2^14) < 2^-16446.
	  if(cvt_x.e&0x8000) {
#ifdef CORE_MATH_SUPPORT_ERRNO
            errno = ERANGE; // underflow
#endif
	      return 0x1p-16445L * 0.25L;
	  } else {
#ifdef CORE_MATH_SUPPORT_ERRNO
            errno = ERANGE; // overflow
#endif
            return 0x1p16383L + 0x1p16383L;
	  }
	}

	if(__builtin_expect(e <= -65 + 16383, 0)) { // |x| < 2^-64
	  if(__builtin_expect(!cvt_x.m && !e, 0)) return 1.L;
		return 1.L + x;
		/* If x = 0, we have 1 = 1 + x = exp(x) so we get a correct result.
		   Assume 0 < x < 2^-64. Let u = ulp(1) = 2^-63. Then we have
		   1 < 1 + x < exp(x) < 1 + u. If the rounding mode is directed
		   this ensures that 1 + x and exp(x) round to the same value.
		   If the rounding mode is to nearest, 1 + x rounds to 1 and we
		   need to show that exp(x) <= 1 + u/2.
		   Since x < 2^-64, in fact x <= x0 := 2^-64 - 2^-128. We check with
		   Sage that exp(x0) <= 1 + u/2, which ensures returning 1 + x
		   is correct.
		   Assume -2^-64 < x < 0. By the alternating series, we have
		   1 - u/2 < 1 + x < exp(x) < 1. Again, if the rounding mode is
		   directed, 1 + x and exp(x) round to the same value.
		   If x >= -u/4, then 1 + x and exp(x) also round to the same value
		   (namely 1) when rounding to nearest.
		   We therefore only have to check that when -u/2 < x < -u/4,
		     exp(x) < 1 - u/4.
		   If x < -2^-65, then x <= x1 := -2^-65 - 2^-128. With Sage we
		   again check that exp(x1) < 1 - u/4.
		*/
	}
	

	// now |x| < 2^14
	redinfo ri;
	bool do_accurate = false;
	long double fp_expx = fastpath(x, &ri, &do_accurate);
	if(__builtin_expect(!do_accurate, 1)) {
		return fp_expx;
	} else {
		bool is_exception;
		fp_expx = catch_exceptions(x, &is_exception);
		if(__builtin_expect(is_exception, 0)) {return fp_expx;}
		else {return accurate_path(x, &ri);}
	}
}
