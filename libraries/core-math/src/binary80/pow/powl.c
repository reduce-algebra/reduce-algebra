/* Correctly rounded powl function for binary80 values.

Copyright (c) 2024-2025 Sélène Corbineau and Paul Zimmermann

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
   [1] Note on FastTwoSum with Directed Roundings, Sélène Corbineau and Paul
       Zimmermann, July 2024, https://inria.hal.science/hal-03798376.
   [2] An efficient rounding boundary test for pow(x,y) in double precision,
       Christoph Lauter and Vincent Lefèvre, IEEE Transactions on Computers,
       vol. 58, nb. 2, pages 197-207, 2009.
 */

#include <stdint.h>
#include <fenv.h> // for FE_TONEAREST, FE_UPWARD, FE_DOWNWARD, ...
#include <stdbool.h>
#include <errno.h>

#ifndef CORE_MATH_FAIL_QUIET
#include <stdio.h> // needed in case of unexpected worst case
#include <stdlib.h> // for exit
#endif

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
get_flag (void)
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
set_flag (FLAG_T flag)
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

typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;
typedef union {
	double f;
	struct __attribute__((packed)) {uint64_t m:52;uint32_t e:11;uint32_t s:1;};
	uint64_t u;
} b64u64_t;

#include "qint.h"
static inline int get_rounding_mode (void)
{
  /* Warning: on __aarch64__ (for example cfarm103), FE_UPWARD=0x400000
     instead of 0x800. */
#if defined(__x86_64__) || defined(__arm64__) || defined(_M_ARM64)
  const unsigned flagp = _mm_getcsr ();
  return (flagp&(3<<13))>>3;
#else
  return fegetround ();
#endif
}

/* Split a number of exponent 0 (1 <= |x| < 2), discarding its sign.
   into a high part fitting in 33 bits and a low part fitting in 31 bits:
   we get 1 <= rh <= 2 and rl < 2^-32 such that |x| = rh + rl exactly.
*/

static inline
void split(double* rh, double* rl, long double x) {
	b80u80_t cvt_x; cvt_x.f = x;
	b64u64_t cvt_w;

	// Keep low 31 bits of x's mantissa. Since the lowest bit should have
	// weight 2^-63, the exponent should be set to -11 (that is, 0x3f4)
	cvt_w.u = (0x3f4ul << (64 - 12)) | (cvt_x.m & ((1ul << 31) - 1ul));
	*rl = cvt_w.f - 0x1p-11;

	// Lowest bit here has weight 2^(-63 + 31) = 2^-32, so exponent should be
	// -32 + 52, i.e. 20, or 0x413. Note how the explicit 1 bit of x helps here.
	cvt_w.u =  (0x413ul << (64 - 12)) | (cvt_x.m >> 31);
	*rh = cvt_w.f - 0x1p20;
}

// assumes a = 0 or |a| >= |b| (or ulp(a) >= ulp(b))
// ensures |rl| <= 2^-52*|rh| and a rounding error <= 2^-105*|rh|
// |rh + rl - (a + b)| <= 2^-105*|rh| (whatever the rounding mode)
// See reference [1].
static inline
void fast_two_sum(double* rh, double* rl, double a, double b) {
	*rh = a + b;
	double e = *rh - a;
	*rl = b - e;
}

static inline
void two_sum(double* rh, double* rl, double a, double b) {
	*rh = a + b;
	double ap = *rh - b;
	double bp = *rh - ap;
	*rl = (a - ap) + (b - bp);
}

/* Computes an approximation of a + bh + bl assuming a = 0 or |a| >= |bh|*/
static inline
void high_sum(double* rh, double* rl, double a, double bh, double bl) {
	double e;
	fast_two_sum(rh, &e, a, bh);
	*rl = bl + e;
}

/* Computes rh + rl = a * b exactly */
static inline
void a_mul(double* rh, double* rl, double a, double b) {
	*rh = a*b;
	*rl = __builtin_fma(a,b,-*rh);
}

/* Computes an approximation of (ah+al)(bh+bl)-al*bl */
static inline
void d_mul(double* rh, double* rl, double ah, double al,
                                   double bh, double bl) {
	double p;
	a_mul(rh, &p, ah, bh); // exact
	double q = __builtin_fma(al, bh, p);
	*rl = __builtin_fma(ah, bl, q);
}

#include "powl_tables.h"

/* Let x = xh + xl. Assume |x|, |xh| <= 2^-11.999 and |xl| <= 2^-52 |xl|
Then polyeval(&rh, &rl, xh, xl) returns in 
rh + rl an estimate of log2(1 + x) with relative error at most 2^-98.285,
with |rl| <= 2^-48.946 |rh|.
*/
static inline
void polyeval(double* rh, double* rl, double xh, double xl) {
	/* We approximate log2(1 + x)/x/(ln2invh + ln2invl) by
	   a polynomial c0 + c1*x + ... + c7*x^7 (see powl.sollya).
	   This polynomial, say p(x), has intrinsic relative error 2^-105.879:
	   log2(1 + x)/x/(ln2invh + ln2invl) = p(x) * (1 + eps1), thus
	   log2(1 + x) = (ln2invh + ln2invl) * x * p(x) * (1 + eps1)
	   with |eps1| < 2^-105.879.
	*/
	static const double ln2invh = 0x1.71547652b82fep+0,
	                    ln2invl = 0x1.777d0ffda0d24p-56;
	// ln2invh + ln2invl = 1/log(2) * (1 + e) with |e| < 2^-110.066
	double scaleh, scalel;
	d_mul(&scaleh, &scalel, ln2invh, ln2invl, xh, xl);
	/* Expanding the d_mul call we get that:
             with ah=ln2invh, al=ln2invl, bh=xh, bl=xl:
	   - |p| <= 2^-52|ah*bh|
	   - |al*bh+p| <= 2^-55.976|ah*bh| + 2^-52|ah*bh| so that
	     |q| <= 2^-51.911|ah*bh| and q's rounding error is
	     at most 2^-103.911|ah*bh|.
	   - |ah*bl+q| <= 2^-52|ah*bh| + 2^-51.911|ah*bh| so that
	     |scalel| <= 2^-50.954|ah*bh| and scalel's rounding error is
	     at most 2^-102.954|ah*bh|.
	   - the error neglecting |al*bl| is at most 2^-52*2^-55.976|ah*bh|
	   The total relative error in terms of |ah*bh| is thus at most
	     (1 + 2^-103.911) * (1 + 2^-102.954) * (1 + 2^-107.979) - 1
             <= 2^-102.325.
	   Expressing the error relative to ln2inv*x, we get a relative error
           at most 2^-102.324:
           scaleh + scalel = (ln2invh + ln2invl) * x * (1 + eps2)
           with |eps2| < 2^-102.324.
	*/

	// compute c0 + c1*x = 1 - x/2
	double ord01h, ord01l;
	ord01h = -xh/2; ord01l = -xl/2; // Exact since c1=-1/2
	high_sum(&ord01h, &ord01l, 1.0, ord01h, ord01l);
	/* Expanding the high_sum call we get that :
	   - the fast_two_sum incurs an error <= 2^-105(1 + 2^-11.999)
	                                      <= 2^-104.999
	     and its' low value is at most ulp(1 + 2^-11.999) = 2^-52.
	   - the final sum has value <= 2^-11.999*2^-52+2^-52 <= 2^-51.999;
             this implies a rounding error <= ulp(2^-51.999) = 2^-104.
	   Therefore, at output we have |ord01h| <= 1 + 2^-11.998,
	   |ord01l| <= 2^-51.999 and the total error on c0 + c1*x is
	   at most 2^-104.999 + 2^-104 < 2^-103.414:
	   ord01h + ord01l = c0 + c1*x + eps01 with |eps01| < 2^-103.414.
	*/


	// compute c2 + c3*x = 0x1.555555555555555555696dc16a8p-2 - x/4
	double ord23h, ord23l;
	ord23h = -xh/4; /*c3 = -1/4*/
	ord23l = __builtin_fma(-xl, 1./4, 0x1.55555a5b705aap-56); /*c2l*/
	high_sum(&ord23h, &ord23l, 0x1.5555555555555p-2, ord23h, ord23l); /*c2h*/
	/* We compute that
	    |-xl/4 + c2l| <= 2^-11.999*2^-52/4 + 2^-55.584 <= 2^-55.582.
	   Therefore after the fma |ord23l| <= 2^-55.581 and the associated
	   rounding error is at most ulp(2^-55.581) = 2^-108.

	   Expanding the high_sum call we get that :
	   - the fast_two_sum incurs an error of 2^-105(2^-1.584 + 2^-13.999)
	     <= 2^-106.583 and its low value is at most
	     ulp(2^-1.584 + 2^-13.999) = 2^-54.
	   - the final sum has value at most 2^-55.581 + 2^-54 <= 2^-53.583;
	     this implies a rounding error of at most ulp(2^-53.583) = 2^-106.
	   At output we thus have |ord23h| <= 2^-1.583, |ord23l| <= 2^-53.582
	   and the total error on c2 + c3*x is at most
	      2^-108 + 2^-106.583 + 2^-106 <= 2^-105.060:
	   ord23h + ord23l = c2 + c3*x + eps23 with |eps23| < 2^-105.060.
	*/

	// approximate x^2
	double xsqh, xsql;
	d_mul(&xsqh, &xsql, xh, xl, xh, xl);
	/* Expanding the d_mul call we get that :
	   - |p| <= ulp(xh^2) <= 2^-76
	   - |xl*xh+p| <= 2^-52|xh^2| + 2^-76 <= 2^-74.998
	     so that q's rounding error is at most ulp(2^-74.998) = 2^-127
	   - |xh*xl+q| <= 2^-52|xh^2| + 2^-74.998 <= 2^-74.413
	     so that the rounding error on xsql is at most ulp(2^-74.413) = 2^-127
	   - the error made by neglecting xl^2 is at most 2^-104|xh^2| <= 2^-127.998
	   The total error is thus at most:
	     2^-127 + 2^-127 + 2^-127.998 <= 2^-125.677:
	   |xsqh + xsql - x^2| <= 2^-125.677.
	   Also, at output we have |xsqh| <= 2^-23.997 and |xsql| <= 2^-74.413.
	*/

	// multiply c2+c3*x by x^2
	d_mul(&ord23h, &ord23l, ord23h, ord23l, xsqh, xsql);
	/* Recall we have |ord23h_old| <= 2^-1.583, |ord23l| <= 2^-53.582,
	   |xsqh| <= 2^-23.997, |xsql| <= 2^-74.413.
	   Expanding the d_mul call we get that:
	   - |ord23h| <= |ord23h_old * xsqh| <= 2^-1.583 * 2^-23.997 <= 2^-25.579
	   - |p| <= 2^-52 * (2^-1.583*2^-23.997) <= 2^-77.580.
	   - |al*bh + p| <= 2^-53.582*2^-23.997 + 2^-77.580 <= 2^-76.579,
	      so that |q| <= 2^-76.578 and the associated rounding error is
	      at most ulp(2^-76.578) = 2^-129.
	   - |ah*bl + q| <= 2^-1.583*2^-74.413 + 2^-76.578 <= 2^-75.257.
	      Therefore at output |ord23l| <= 2^-75.256) and the associated
	      rounding error is at most ulp(2^-75.256) = 2^-128.
	   - the error made by neglecting ord23l*xsql is at most
	      2^-53.582*2^-74.413 <= 2^-127.995.
	   Propagating the errors on x^2 and c2 + c3*x gives an intrinsic error of
	   at most :
	     (c2 + 2^-11.999*|c3|) * 2^-125.677 + eps23 * 2^(-11.999*2)
	     + eps23 * 2^-125.677 <= 2^-126.896
	   The total absolute error computing x^2(c2 + c3*x) is thus bounded by
	     2^-129+2^-128+2^-127.995+2^-126.896 <= 2^-125.781:
	   |ord23h + ord23l - (c2*x^2 + c3*x^3)| < 2^-125.781
	*/

	double x4 = xsqh*xsqh;
	/* Neglecting 2*xsqh*xsql + xsql^2 creates an error of at most
	   2*2^-23.997*2^-74.413 + 2^(-74.413*2) <= 2^-97.409.
	   Also, |xsqh*xsqh| <= 2^(-23.997*2) <= 2^-47.994. Therefore,
	   the rounding error of the product is <= ulp(2^-47.994) = 2^-100.

	   We obtain that |x4| <= 2^-47.993
	   and that |x4 - x^4| <= 2^-97.409 + 2^-100 + |(xsqh+xsql)^2 - x^4|
	                       <= 2^-97.187 + |(xsqh+xsql) + x^2||(xsqh+xsql) - x^2|
	                       <= 2^-97.187 + (2*(2^-11.999)^2 + 2^-125.677)*2^-125.41
	                       <= 2^-97.186
	*/

	double acc = __builtin_fma(xh, -0x1.555555555554dp-3/*c5*/,
	                                0x1.999999999998ap-3/*c4*/);
	double bcc = __builtin_fma(xh, -0x1.0000014f8ec21p-3/*c7*/,
	                                0x1.24924ad7557bep-3/*c6*/);
	/* We compute that |xh*c5 + c4| <= 2^-2.3216. This implies that
	   |acc| <= 2^-2.321 and that its rounding error is at most
	   ulp(2^-2.321) = 2^-55.
	   Neglecting xl*c5 incurs an error of at most 2^-64*2^-2.584 <= 2^-66.584.
	   The total error computing c4 + c5x is thus at most
	     2^-55+2^-66.584 <= 2^-54.999:
           |acc - (c4+c5*x)| < 2^-54.999.

	   In the same way, we compute that |xh*c7 + c6| <= 2^-2.807, which
	   implies |bcc| <= 2^-2.806 and its rounding error is at most
	   ulp(2^-2.806) = 2^-55.
	   Neglecting xl*c7 incurs an error of at most 2^-64*2^-2.999 <= 2^-66.999.
	   The total error computing c6 + c7x is thus at most
	     2^-55+2^-66.999 <= 2^-54.999:
	   |bcc - (c6+c7*x)| < 2^-54.999.
	*/

	// approximate c4+c5*x+c6*x^2+c7*x^3
	acc = __builtin_fma(xsqh, bcc, acc);
	/* We compute that |xsqh*bcc + acc| <= 2^-23.997*2^-2.806+2^-2.321
	   <= 2^-2.320.
	   This ensures that at output, |acc| <= 2^-2.319. Also, the rounding
	   error is at most ulp(2^-2.319) = 2^-55.
	   Since |xsqh+xsql - x^2| <= 2^-125.677, we have
	   |xsqh - x^2| <= 2^-125.677+2^-74.413 <= 2^-74.412.
	   We thus get:
	   |acc - (c4+c5*x+c6*x^2+c7*x^3)|
	   <= |acc - (xsqh*bcc+acc_old)| + |xsqh*bcc - (c6*x^2+c7*x^3)|
	      + |acc_old - (c4+c5*x)|
	   <= 2^-55 + |xsqh-x^2|*|bcc| + x^2*|bcc - (c6+c7*x)| + 2^-54.999
	   <= 2^-55 + 2^-74.412*2^-2.806 + 2^-23.998*2^-54.999 + 2^-54.999
	   <= 2^-53.999.
	*/

	ord01l = __builtin_fma(x4, acc, ord01l);
	/* We have |x4 - x| <= 2^-97.186
                   |acc - (c4+c5*x+c6*x^2+c7*x^3)| <= 2^-53.999 and
             ord01h + ord01l = c0 + c1*x + eps01 with |eps01| < 2^-103.414.
	   We compute that |x4*acc+ord01l|<=2^-47.993*2^-2.319+2^-51.999
           <= 2^-49.921.
	   This implies that at output |ord01l| <= 2^-49.920 and that the
	   rounding error is at most ulp(2^-49.921) = 2^-102.
	   We deduce with ord01l_old denoting the previous value of ord01l:
	   |ord01h + ord01l - (c0 + c1*x + x^4*(c4+c5*x+c6*x^2+c7*x^3))|
	   <= 2^-103.414 [approximation error on ord01h + ord01l_old]
	    + 2^-102     [rounding error on ord01l]
	    + |x4*acc - x^4*(c4+c5*x+c6*x^2+c7*x^3)|
	   <= 2^-103.414 + 2^-102 + |x4-x^4|*|acc|
	    + x^4*|acc-(c4+c5*x+c6*x^2+c7*x^3)|
	   <= 2^-103.414 + 2^-102 + 2^-97.186*2^-2.319 + 2^-47.996*2^-53.999
	   <= 2^-98.997.
	*/

	high_sum(&ord23h, &ord23l, ord01h, ord23h, ord23l);
	ord23l += ord01l;
	/* At input, ord01h + ord01l approximates
	   c0 + c1*x + x^4*(c4+c5*x+c6*x^2+c7*x^3) with error <= 2^-98.997,
	   with |ord01h| <= 1 + 2^-11.998, |ord01l| <= 2^-49.920,
	   and ord23h + ord23l approximates c2*x^2 + c3*x^3 with error
	   <= 2^-125.781 (the error eps01 on ord01h + ord01l_old was already
	   taken into account above), with |ord23h| <= 2^-25.579, |ord23l| <= 2^-75.255,
	   This yields a total intrinsic error of
	   2^-98.997 + 2^-125.781 <= 2^-98.996.

	   Expanding high_sum, we see that the fast_two_sum incurs an error at most
	   2^-105(1 + 2^-12.998 + 2^-25.579) <= 2^-104.999. We also see that
	   |ord23h| <= 1.001 at output, and the fast_two_sum's low value
	   is at most ulp(1.001) = 2^-52. The final sum has absolute value at most
	   2^-75.255 + 2^-52 <= 2^-51.999. This ensures that |ord23l| <= 2^-51.998
	   after the high_sum and that the associated rounding error is at most
	   ulp(2^-51.998) = 2^-104.

	   Given that |ord01l| <= 2^-49.920 we get that the sum |ord23l + ord01l| is
	   at most 2^-51.998 + 2^-49.920 <= 2^-49.613.
	   This ensures that at output |ord23l| <= 2^-49.613
	   and that the sum's rounding error is at most ulp(2^-49.613) = 2^-102.

	   The total accumulated error is therefore at most
	   2^-98.996 + 2^-104.999 + 2^-104 + 2^-102 <= 2^-98.767:

	   |ord23h + ord23l - p(x)| <= 2^-98.767
	   where p(x) = c0 + c1*x + c2*x^2 + c3*x^3 + c4*x^4 + c5*x^5 + c6*x^6 + c7*x^7.

	   The value ord23h + ord23l approximates log2(1 + x)/(ln2inv*x), which
	   is positive and decreasing by concavity. We can check that it's value
	   at x = 2^-11.999 is at least .9998. Therefore, the absolute error above
	   translates to a relative error <= 2^-98.767/.9998 <= 2^-98.766. Taking into
	   account to the polynomial's intrinsic relative error of 2^-105.879, we ensure
	   that we have computed log2(1+xr)/(ln2inv*xr) with relative error at most
	   (1 + 2^-105.879) * (1 + 2^-98.766) - 1 <= 2^-98.755. */

	d_mul(rh, rl, scaleh, scalel, ord23h, ord23l);
	/* Recall scaleh + scalel approximates ln2inv*x with relative error
	   at most 2^-102.324, with |scalel| <= 2^-50.954|scaleh|,
	   and ord23h + ord23l approximates log2(1 + x)/(ln2inv*x)
	   with relative error <= 2^-98.755, with |ord23h| < 1.001, |ord23l| <= 2^-49.613.
	   Propagating each term's relative errors we get a total intrinsic relative
	   error of (1 + 2^-102.324)*(1 + 2^-98.755) - 1 <= 2^-98.638.
	   Expanding the d_mul call we get :
	     - |p| <= 2^-52*|scaleh|*1.001
	     - |scalel*ord23h + p| <= (2^-50.954+2^-52)*1.001*|scaleh|. This ensures
	       that |q| <= 2^-50.382|scaleh| and that the rounding error is bounded by
	       2^-102.382|scaleh|.
	     - |scaleh*ord23l + q| <= (2^-49.613 + 2^-50.382)|scaleh|. This ensures
	       that |rl| <= 2^-48.946|scaleh| and that the final rounding error is
	       at most 2^-100.946|scaleh|.
	  The total rounding error is thus at most
	    (2^-102.382+2^-100.946)|scaleh| <= 2^-100.492|scaleh|:
	    rh + rl = (scaleh + scalel) * (ord23h + ord23l) + eps1 * |scaleh|
	    with |eps1| <= 2^-100.492.

	  Since |scalel| <= 2^-50.954|scaleh|, we deduce with scale := scaleh + scalel:
	    rh + rl = scale * (ord23h + ord23l) + eps2 * |scale|
	    with |eps2| <= |eps1|/(1-2^-50.954) <= 2^-100.491.

	  Since |ord23h + ord23l| >= 0.999, we deduce with ord23 := ord23h + ord23l:

	    rh + rl = scale * ord23 + eps3 * |scale*ord23|
	    with |eps3| <= |eps2|/0.999 <= 2^-100.489.

	  Now scale = (ln2invh + ln2invl) * x * (1 + eps) with |eps| < 2^-102.324,
	  and ord23 = log2(1 + x)/(ln2inv*x) * (1 + eps) with |eps| < 2^-98.755, thus:
	  scale * ord23 = log2(1+x) * (1 + eps4) with
	  |eps4| <= (1 + 2^-102.324) * (1 + 2^-98.755) - 1 <= 2^-98.638.

	  It follows:
	    rh + rl = log2(1+x) * (1 + eps4) + eps3 * log2(1+x) * (1 + eps4)
	            = log2(1+x) * (1 + eps5)
	    with |eps5| <= |eps4| + |eps3| * (1 + |eps4|)
	                <= 2^-98.285.
	  We also have the postcondition |rl| <= 2^-48.946|rh|.
	*/
}

/* Computes an approximation of ylog2|x| under the following conditions :

- 2^-80 <= |y| < 2^78
- x is normal, i.e., |x| >= 2^-16382

Ensures:
|rh + rl - y * log2(x)| < 2^-97.286 |rh| with |rl| <= 2^-48.262 |rh|.
*/
static inline
void compute_log2pow(double* rh, double* rl, long double x, long double y) {
	b80u80_t cvt_x = {.f = x};
	int extra_int = (cvt_x.e&0x7fff) - 16383;
	// -16382 <= extra_int <= 16383
	cvt_x.e = 16383; // New wanted exponent
	x = cvt_x.f;
	// original x = 2^extra_int * x

	double xh, xl; // a (resp b) bits
	split(&xh, &xl, x);
	// x = xh + xl with xh on 33 bits and xl on 31 bits, |xl| < 2^-32

	// Uses the high 7 bits of x's mantissa.
	lut_t l = coarse[cvt_x.m>>56 & 0x7f];

	/* We always have |x*r1 - 1| <= 0x1p-7. The term l.z is chosen such that
	   l.z+mlogr1h + mlogr1 approximates -log2(r1) with
	   relative error < 2^-107.22. Note that |mlogr1h+mlogr1l| < .5
	   The tables are constructed in such a way that r fits in 9 bits.
	*/
	double r1      = l.r;
	double mlogr1h = l.mlogrh;
	double mlogr1l = l.mlogrl;
	extra_int     += l.z;

	xh *= r1; xl *= r1;
	/* The above multiplications are exact.
	   Since xh, xl did fit in 33 and 31 bits respectively,
	   and r1 fits in 9 bits, now xh fits in 42 bits, and xl in 40.
	   More precisely the initial xh was a multiple of 2^-32.
	   Since r1 is a multiple of 2^-9 then the new value of xh is a
	   multiple of 2^-41.
	   Since we had |rl| < 2^-32 and |r1| <= 1, we still have |rl| < 2^-32.
	*/

	/* Note that now |xh - 1| <= 1p-7
	   Therefore, xh's mantissa (seen as a 53-bit integer) is either
	   1.00000 00p or 1.11111 1q.
	   We skip the upper 6 bits of the mantissa and use the next 7 bits
	   to index another lookup table. A quarter of the table is wasted!

	   We're looking at 1 + 2^-12*k, 1 + 2^-12*(k+1) for 0 <= k < 32.
	   Else we're looking at 1 - 2^-6 + 2^-13*k', 1 - 2^-6 + 2^-13*(k'+1)
	   for 64 <= k' < 128.
	*/

	b64u64_t cvt_xh = {.f = xh};
	lut_t l2 = fine[(cvt_xh.u>>40) & 0x7f]; // k' = (cvt_xh.u>>40) & 0x7f
	// bit 52 goes to 6+5 = 11. Bits 11 - 8
	double r2 = l2.r;
	double mlogr2h = l2.mlogrh;
	double mlogr2l = l2.mlogrl;
	/* The fine table is built in such a way that :
	   i)  |r2*xh - 1| <= 2^-12
	   ii) r2 fits in 13 bits
	   iii) mlogr2h + mlogr2l approximates -log2(r2) with
	        relative error at most 2^-107.27
	   iv) |mlogr2h+mlogr2l| < 2^-6.47
	       Since r2 is a multiple of 2^-13, xh*r2 is a multiple of 2^-54,
	       and since |r2*xh - 1| <= 2^-12, then r2*xh - 1 is representable
	       exactly on 42 bits.
	*/

	double mlogrh, mlogrl;
	high_sum(&mlogrh, &mlogrl, extra_int, mlogr1h, mlogr1l);
	/* Since |mlogr1h + mlogr1l| < .5, we indeed have extra_int = 0 or
	   |extra_int| > |mlogr1h|. If extra_int=0 everything is exact,
	   and we get mlogrh=mlogr1h, mlogrl=mlogr1l.
	   Assume |extra_int| >= 1. Expanding the high_sum call, this implies
	   that the fast_two_sum introduces an error <= 2^-105|mlogrh| and
	   that the low part of its result is at most 2^-52|mlogrh|. Notice
	   that |mlogrh| >= .5 > |mlogr1h| so that
	   2^-52|mlogrh| >= 2^-52|mlogr1h| >= |mlogr1l|.
	   This implies that the "rl" sum of high_sum (i.e., mlogrl)
	   is at most 2^-51|mlogrh| and that its rounding error is
	   at most 2^-103|mlogrh|.

	   The total rounding error is at most
	   (2^-103+2^-105)|mlogrh| <= 2^-102.678 |mlogrh|:         
	   |mlogrh + mlogrl - (extra_int + mlogr1h + mlogr1l)|
	   <= 2^-102.678 |mlogrh|.

	   If one performs an exhaustive search on all possible values
	   of extra_int (-16382 to 16383), on all rounding modes, and
	   on all values of mlogr1h/mlogr1l, we obtain that the maximal
	   relative error is bounded by 2^-105.003 |mlogrh|
	   (see function analyse_first_high_sum() in powl.sage).
	*/

        double mlogr12h, mlogr12l;
	high_sum(&mlogr12h, &mlogr12l, mlogrh, mlogr2h, mlogr2l);
	mlogr12l += mlogrl;
	/* Let us prove that unless it is zero, |mlogrh| is in the same binade
	   of |mlogr2h| or in a larger binade (so that the fast_two_sum
	   condition is fulfilled).
	   If extra_int != 0, this is obvious because |mlogrh+mlogrl| >= .5,
	   and |mlogr2h| < 2^-6.47.
	   Assume extra_int = 0. Then mlogrh = mlogr1h and looking at the
	   tables we see that mlogr1h = 0 or
	   |mlogr1h| >= 0x1.6fe50b6ef0851p-7 >= |mlogr2h| which allows us to conclude.

	   The accompanying program high_sum.c, compiled with -DMODE=0, gives
	   the following upper-bounds (all attained for extra_int=0):
    
	   |mlogrh/mlogr12h|  < 1.951
	   |mlogr1h/mlogr12h| < 1.951
	   |mlogr2h/mlogr12h| <= 1

	   Expanding high_sum(), let t the low part of the fast_two_sum() call.
	   As above the fast_two_sum yields an error <= 2^-105 |mlogr12h|
	   and |t| <= 2^-52 |mlogr12h|.
	   In the last sum of the fast_two_sum(), notice that
	   |mlogr2l| <= 2^-53 |mlogr2h| <= 2^-53 * |mlogr12h|,
	   where we used the above bound |mlogr2h/mlogr12h| <= 1.

	   Therefore, |mlogr2l + t| <= (2^-53 + 2^-52) |mlogr12h|
	                            <= 2^-51.415 |mlogr12h|.
	   This implies that |mlogr12l| <= 2^-51.415 |mlogr12h| and that the
	   rounding error of the high_sum's final sum is
	   at most 2^-103.415 |mlogr12h|.

	   Note that the following sum mlogr12l + mlogrl is at most
	     |mlogr12l| + 2^-51 |mlogrh| <= (2^-51.415 + 1.951 * 2^-51) |mlogr12h|
	   (where |mlogrl| <= 2^-51|mlogrh| was proven in the analysis of
	   the first high_sum, and |mlogrh/mlogr12h| < 1.951 from the above
	   bounds), we thus get:
	     |mlogr12l| <= 2^-49.566 |mlogr12h| and a rounding error
	   of at most 2^-101.566 |mlogr12h|.

	   These steps of computation created an error at most
	     (2^-105 + 2^-103.415 + 2^-101.566) |mlogr12h| < 2^-101.111 |mlogr12h|
	   Propagating the previous absolute errors gives:
	   2^-102.678 |mlogrh| + 2^-107.22 |mlogr1h| + 2^-107.27 |mlogr2h|
	   where 2^-102.678 |mlogrh| comes from the first high_sum() call,
	   2^-107.22 |mlogr1h| comes from the accuracy of the coarse[] table,
	   and 2^-107.27 |mlogr2h| comes from the accuracy of the fine[] table.
	   Using the above bounds, this yields a relative error bound of:
	     (1.951 * (2^-102.678 + 2^-107.22) + 1 * 2^-107.27) |mlogr12h|
	     < 2^-101.624 |mlogr12h|
	   We thus get a total relative error of at most:
	   (2^-101.111 + 2^-101.624) < 2^-100.344 |mlogr12h|:

	   |mlogr12h + mlogr12l - (extra_int - log2(r1) - log2(r2))|
	   < 2^-100.344 |mlogr12h|.

	   However, a better bound is obtained by brute force,
	   by trying all the values of extra_int, r1, r2 and all
	   rounding modes. This is done in the accompanying high_sum.c
	   program, which yields the bound (with -DMODE=1):
	   |mlogr12h + mlogr12l - (extra_int - log2(r1) - log2(r2))|
	   < 2^-103.446 |mlogr12h|.

	   Additionally, this program also shows:
	   |mlogr12l/mlogr12h| < 2^-47.961.
	*/

	fast_two_sum(&mlogr12h, &mlogr12l, mlogr12h, mlogr12l);
	/* This renormalization incurs a relative error at most 2^-105.
           The total relative error becomes at most:
           (1 + 2^-103.446) * (1 + 2^-105) - 1 < 2^-103.023. This ensures
	   |mlogr12l| <= 2^-52 |mlogr12h|.
	*/

	// |xh| <= 1p-12
	xh = __builtin_fma(r2, xh, -1); xl *= r2;
	/* The product old_xl * r2 is exact since old_xl fits in 40 bits
	   and r2 in 13 bits.
	   We know that xh is a multiple of 2^-41. Since r2 is a multiple of
	   2^-13, then r2*xh is a multiple of 2^-54, and so is r2*xh - 1.
	   Since |r2*xh - 1| <= 2^-12, r2*xh - 1 fits in 42 bits,
	   and thus the above fma() is exact too.
	   Moreover since old_xl fits in 40 bits, and r2 in 13 bits,
	   then xl fits in 53 bits, thus old_xl * r2 is exact
	   and both operations are exact. */

	two_sum(&xh, &xl, xh, xl); // We probably cannot use Fast2Sum
	/* At input, we have |xh| <= 1p-12 and |xl| < 2^-32. Therefore at
	   output we have |xh| <= 2^-11.999, |xl| <= ulp(xh) <= 2^-64 and 
	   xr = xh + xl is such that |xr| <= 2^-11.999.

	   We use two_sum because we have no guarantees on the relative
	   sizes of xh and xl. However, since we know |xl| < 2^-32 at input,
	   if the Fast2Sum condition is not fulfilled, this would mean
	   |xh| < 2^-33,
	   Theorem 2 from reference [1] than says that if we used Fast2Sum,
	   the rounding error would be less than 3 2^-53 |xh|, thus less than
	   3 * 2^-53 * (2^-33 + 2^-32) < 2^-82.830.
	*/

	polyeval(rh, rl, xh, xl);
	/* By polyeval's error analysis, rh + rl gets an estimate of log2(1+x)
	   with relative error at most 2^-98.285, and |rl| <= 2^-48.946 |rh|.
	   Since |x| < 2^-11.999, it follows |rh| < 2^-11.470.
	*/

	high_sum(rh, rl, mlogr12h, *rh, *rl);
	*rl += mlogr12l;
	/* Let us call rh', rl' the results of the computation, rh and rl the inputs.
	   Note that if mlogr12h != 0, then the program high_sum.c with MODE=3
	   shows that |mlogr12h| >= 0x1.7148ec2a1bfc8p-12.
	   Since |rh| < 2^-11.470 < 0x1.8p-12, this implies mlogr12h is 0 or
	   lies in the same binade than rh, or in a larger binade.
	   Thus the fast_two_sum() condition in high_sum() is fulfilled.

	   Expanding the high_sum call and calling t the fast_two_sum result's
	   low part, fast_two_sum() yields a rounding error <= 2^-105|rh'|
	   and |t| <= 2^-52|rh'|. In the last sum inside high_sum(), notice
	   that |rl + t| <= 2^-48.946 |rh| + 2^-52|rh'|. Now, since
	   |rh| < 1.002 |rh'| (see max_rh_over_rh_prime_all() in powl.sage),
	   we have |rl + t| <= (2^-48.946 * 1.002 + 2^-52)|rh'|.
	   This shows that after high_sum(), |rl'| <= 2^-48.779|rh'| and that
	   the associated rounding error is at most
	   2^-105 |rh'| + 2^-52 |rl'| <= (2^-105 + 2^-52*2^-48.779) |rh'|
	   <= 2^-100.703 |rh'|.

	   Since |rl'| <= 2^-48.779|rh'|, |mlogr12l| <= 2^-52 |mlogr12h|,
	   and the routine max_mlogr12h_over_rh_prime_all() in powl.sage
	   shows that |mlogr12h| < 2.002 |rh'|,
	   the sum rl' + mlogr12l is thus at most
	     2^-48.779|rh'| + 2.002*2^-52|rh'| <= 2^-48.498|rh'|
	   which implies that in the end |rl'| <= 2^-48.497|rh'| and that the
	   associated rounding error is at most 2^-100.497|rh'|.

	   These steps of computation created an error at most
	     (2^-105 + 2^-100.703 + 2^-100.497)|rh'| <= 2^-99.562|rh'|:
	     |rh' + rl' - (mlogr12h + rh + rl)| <= 2^-99.562 |rh'|.

	   We had a relative error <= 2^-103.023 on mlogr12h + mlogr12l:
	   |mlogr12h + mlogr12l - (extra_int - log2(r1) - log2(r2))|
	   < 2^-103.023 |mlogr12h|
	   which since |mlogr12h/rh'| <= 2.002 translates to
	   2.002*2^-103.023. And we had a relative error <= 2^-98.285 on rh + rl:
	   |rh + rl - log2(1+x)| <= 2^-98.285 |rh|
	   which since |rh/rh'| <= 1.002 translates to 1.002*2^-98.285.

	   In summary we get:
	   |rh' + rl' - (extra_int - log2(r1) - log2(r2) + log2(1+xr))|
	   <= eps * rh'
	   with |eps| <= (1 + 2^-99.562) * (1 + 2.002*2^-103.023)
	              * (1 + 1.002*2^-98.285) - 1 <= 2^-97.710.
	   The total relative error computing log2(x) is therefore at most
	   2^-97.710. Also, |rl'| <= 2^-48.497|rh'|.
	*/


	b80u80_t cvt_y; cvt_y.f = y;
	b64u64_t cvt_w, cvt_aux;

	/* Split y into yh + yl, where |yl| < ulp(yh). We exploit the fact that y
	   is a normal number.
	*/

	cvt_w.u = ((cvt_y.e&0x8000ul) << (63 - 15)) | (((cvt_y.e&0x7ffful) + (1023ul - 16383ul)) << (64 - 12)) |
		((cvt_y.m >> 11) & ~(1ul << 52)); // Explicitely remove leading 1 bit
	double yh = cvt_w.f;

	/* The bottom bit of y's mantissa has weight e - 63, were e is y's exponent.
	   Therefore, the exponent of yl should (at first) be e - 63 + 52 = e - 11
	*/
	cvt_w.u = ((cvt_y.e&0x8000ul) << (63 - 15)) | (((cvt_y.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12)) |
		(cvt_y.m & ((1ul << 11) - 1ul));

	// Replicate parasitic implicit leading bit
	cvt_aux.u = ((cvt_y.e&0x8000ul) << (63 - 15)) | (((cvt_y.e&0x7ffful) + (1023ul - 16383ul - 11)) << (64 - 12));
	double yl = cvt_w.f - cvt_aux.f; // Remove implicit one introduced before


	d_mul(rh, rl, yh, yl, *rh, *rl);
	/* Let us call again rh', rl' the output values for rh and rl,
	   and rh and rl the input values. The relative error on log2(1 + x)
	   propagates, creating an intrinsic relative error of 2^-97.710.
	   Expanding the d_mul call, we see that |p| <= 2^-52|yh*rh|; then
	     - |yl*rh + p| <= 2^-52|yh*rh| + 2^-52|yh*rh| <= 2^-51|yh*rh|.
	       This ensures |q| <= 2^-51|yh*rh|. Also, the associated
	       rounding error is at most 2^-103|yh*rh|.
	     - |yh*rl + q| <= (2^-48.497 + 2^-51)|yh*rh|. This ensures that 
	       |rl'| <= 2^-48.262|rh'| and that the associated rounding error
	       is at most 2^-100.262|rh'|.
	     - the error produced by neglecting |yl*rl| is at most
	       2^-52*2^-48.497|yh*rh|.
	   The total error of this d_mul() is thus at most:
	   (2^-103 + 2^-100.262 + 2^-52*2^-48.497) |yh*rh| <= 2^-99.262 |yh*rh|
	   Adding the relative error on rh+rl we get:
	   rh' + rl' - y * log2(x) = eps * rh'
	   with |eps| <= (1 + 2^-97.710) * (1 + 2^-99.262) - 1 <= 2^-97.286.
	   We also have |rl'| <= 2^-48.262|rh'|.
	*/
}

// approximates 2^(xh + xl) by 2^extra_exponent * (resh + resl)
// where extra_exponent is the returned value
// assuming |xl| <= 2^-48.262 |xh| and |xh| < 16446.1
// ensure 2^extra_exponent * (resh + resl) = 2^(xh + xl) * (1 + eps)
// with |eps| <= 2^-85.010, 0.499 < |resh| < 2.004, |resl| <= 2^-47.638
static inline
int exp2d(double* resh, double* resl, double xh, double xl) {
	b64u64_t cvt = {.f = xh};
	bool do_red	= cvt.e >= -20 + 0x3ff;
        // do_red is true iff |xh| >= 2^-20

	static const double C = 0x1.8p+32; // ulp(C) = 2^-20
	b64u64_t y = {.f = xh + C};
	uint64_t fracpart = y.u;
	int16_t extra_exponent = y.u>>20;

	// r = y.f - C is the rounding of xh to an integer multiple of 2^-20
	// extra_exponent is the integer part of r
	// and the low 20 bits of fracpart are the fractional part of r

	if(__builtin_expect(do_red, 1)) {
		double rem = xh - (y.f - C); // rem = xh - r
		fast_two_sum (&xh,&xl,rem,xl);
		/* Let xh_old/xl_old be the old values to xh and xl, and xh/xl the
		   new values. Note that we can have |rem| < |xl_old| here.
		   We have |rem| < 2^-20 and |xl_old| <= 2^-48.262*16446.1 < 2^-34.256.
		   Therefore |rem+xl_old| <= 2^-20 + 2^-34.256 which ensures
		   |xh| <= 2^-19.9994.
		   If rem = 0 or ulp(rem) >= ulp(xl_old), then the pre-condition of
		   fast_two_sum() is fulfilled, the rounding error is at most
		   2^-105|xh| <= 2^-124.9994 and |xl| < ulp(xh) <= 2^-72.
		   If this is not the case, since |xl_old| < 2^-34.256 we must have
		   |rem| < 2^-35 which implies |xh| < 2^-33.580, and the rounding
		   error is at most 3 * 2^-53 * |xh| < 2^-84.995 (see Theorem 2 from
		   reference [1]).
		   We also have |xl| <= 2^-72 in that case too, since
		   |xh - (rem + xl_old)| < ulp(xh) <= 2^-86, and
		   |xh + xl - (rem + xl_old)| < 2^-84.995, thus by the triangle
		   inequality |xl| < 2^-86 + 2^-84.995 < 2^-84.411.
		*/
	}

	/* If do_red=0 we had |xh| < 2^-20 thus
	   |xl| < 2^-48.262*2^-20 <= 2^-68.262,
	   and xh = xh_old, xl = xl_old, r = 0. In summary, in all cases
	   we have (with r=0 in case do_red=0):
	   |xh + xl - (xh_old + xl_old - frac(r))| < 2^-84.995
	   thus: 2^(frac(r) + xh + xl) = 2^(xh_old + xl_old) * (1 + rho1)
	   with |rho1| < 2^(2^-84.995) - 1 < 2^-85.523,
	   and |xh| <= 2^-19.9994, |xl| < 2^-68.262. */

	int i0 = fracpart & 0x1f;
	int i1 = (fracpart >> 5) & 0x1f;
	int i2 = (fracpart >> 10) & 0x1f;
	int i3 = (fracpart >> 15) & 0x1f;

	double frcp_acc0_l, frcp_acc0_h, frcp_acc2_h, frcp_acc2_l;
	double xs_pow2_h, xs_pow2_l;

	d_mul(&frcp_acc0_h, &frcp_acc0_l,
		t0[i0][0], t0[i0][1],   // 2^(i0/2^20)
		t1[i1][0], t1[i1][1]);  // 2^(i1/2^15)
	d_mul(&frcp_acc2_h, &frcp_acc2_l,
		t2[i2][0], t2[i2][1],   // 2^(i2/2^10)
		t3[i3][0], t3[i3][1]);  // 2^(i3/2^5)
	d_mul(&xs_pow2_h, &xs_pow2_l, frcp_acc0_h, frcp_acc0_l,
		frcp_acc2_h, frcp_acc2_l);
	/* This step introduces a relative error rho2 (see the analysis
	   in fastpath() from expl.c), since the tables t0, t1, t2, t3
	   are the same as for expl:
	   xs_pow2_h + xs_pow2_l = 2^frac(r) * (1 + rho2)
	   with |rho2| < 2^-99.1. Moreover, |xs_pow2_l| <= 2^-48.2 and
	   1 <= |xs_pow2_h| < 2 (1 <= |xs_pow2_h| comes from the fact
	   that all tables t0, t1, t2, t3 are >= 1). */

	/* Evaluating the Taylor polynomial for 2^xr where xr = xh + xl.
	   If do_red is true, then |xh| <= 2^-19.9994 and |xl| <= 2^-72 so that
	   |xr| <= 2^-19.999.
	   If do_red is false, we have |xr| < 2^-20 + 2^-68.262 <= 2^-19.999,
	   and |xl| <= 2^-68.262.

	   Over the interval [-2^-19.999, 2^-19.999] the polynomial used has
	   absolute error <= 2^-89.218 (same polynomial as in expl.c).
	*/

	double xsq = xh * xh;
	/* Neglecting 2*xl*xh + xl^2 brings an error of at most
	   |2*xl*xh + xl^2| <= 2 * 2^-68.262 * 2^-19.999 + 2^(-68.262*2)
	                    <= 2^-87.260.
	   Since |xh| <= 2^-19.999, we have |xh*xh| <= 2^-39.998. The rounding
	   error on xsq is therefore at most ulp(2^-39.998) = 2^-92, and
	     |xsq| <= 2^-39.998 + 2^-92 <= 2^-39.997.
	   We have thus |xsq - xr^2| <= 2^-87.260 + 2^-92 <= 2^-87.206.
	*/
	double orders23 = xsq * __builtin_fma(xh,0x1.c6b08d704a1cdp-5,
		0x1.ebfbdff82c696p-3);

	/* We note A = 0x1.c6b08d704a1cdp-5 and B = 0x1.ebfbdff82c696p-3.
	   Analyzing the fma call:
	   Neglecting xl * A imparts an error bounded by
	     |A * xl| <= A*2^-68.262 <= 2^-72.433.
	   Since |xh| <= 2^-19.999, |A*xh+B| <= 2^-19.999*A + B < 1/4 - 0.008.
	   This implies that the fma's result is strictly less than 1/4.
	   The rounding error of the fma is therefore at most ulp(1/8) = 2^-55.
	   The total error evaluating Axr+B is thus at most
	         2^-55 + 2^-72.433 <= 2^-54.999.

	   Given the errors on each factor, the product xsq * fma() carries an
	   intrinsic error
	     |xr|^2*2^-54.999 + 2^-84.995*|Axr+B| + 2^-84.995*2^-54.999
	   Since |xr|<= 2^-19.999 we check that |Axr+B| <= 2^-2.057 and thus
	   the error is at most 2^-87.046.

	   Since |xsq| <= 2^-39.997 and |A*xh+B| < 1/4 - 0.008, the product
	   is bounded by 2^-39.997 * (1/4 - 0.008) < 2^-42.04. The rounding
	   error on orders23 is thus at most ulp(2^-42.04) = 2^-95.
	   Therefore |orders23| <= 2^-42.04 + 2^-95 < 2^-42.03.
	   The total error on orders23 is at most 2^-87.046+2^-95 <= 2^-87.040.
	*/

	double order1h, order1l;
	static const double coeff1h = 0x1.62e42fefa39efp-1;
	static const double coeff1l = 0x1.abc9e3b369936p-56;
	// 0x1.62e42fefa39ef35793c766d326cp-1 = coeff1h + coeff1l
	d_mul(&order1h, &order1l, coeff1h, coeff1l, xh, xl);
	/* Let's expand the d_mul call.
	   Since |coeff1h| < 2^-0.5287 and |xh| <= 2^-19.999 we have
	   |ah*bh| <= 2^-20.527. This implies
	   |order1h| < 2^-20.5 and |s| < ulp(2^-20.5) = 2^-73.
	   Since |coeff1l| <= 2^-55.25, we compute that
	     |coeff1l*xh + s| <= 2^-55.25*2^-19.999 + 2^-73 <= 2^-72.724.
	   This ensures that the rounding error computing t is at most
	   ulp(2^-72.724) = 2^-125 and that |t| <= 2^-72.7.
	   Since |coeff1h| <= 2^-0.528 and |xl| < 2^-68.262, we compute that
	     |coeff1h*xl + t| <= 2^-0.528 * 2^-68.262 + 2^-72.7 <= 2^-68.697.
	   The rounding error on order1l is therefore at most ulp(2^-68.697)
	   = 2^-121. We also get |order1l| < 2^-68.6.
	   The total rounding error is at most 2^-125 + 2^-121 <= 2^-120.912.

	   The error due to neglecting xl*coeff1l is at most
	     |xl*coeff1l| <= 2^-68.262 * 2^-55.25 <= 2^-123.512.
	   The total error on order1 is at most
	   2^-120.912 + 2^-123.512 <= 2^-120.691:
	   |order1h + order1l - (coeff1h + coeff1l) * (xh + xl)| < 2^-120.691.
	*/
	double finalh, finall;
	fast_two_sum(&finalh, &finall, 1, orders23);
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
	   0.499 < |finalh| <= 1.002 and |tmp| <= ulp(1.002) = 2^-52.
	*/

	finall = tmp + (finall + order1l);
	/* At input, we have |finall| < 2^-52 and |order1l| <= 2^-68.6.
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
	   - 2^-87.040  computing orders23,
	   - 2^-120.691 computing order1,
	   - 2^-104.999 in the first fast_two_sum,
	   - 2^-104.998 in the second fast_two_sum,
	   - 2^-102.415 in the last sum.
	  The polynomial itself was only precise to 2^-89.218. Therefore,
	  we have computed 2^xr with error at most :
	   2^-87.040 + 2^-120.691 + 2^-104.999 + 2^-104.998 + 2^-102.415
	   + 2^-89.218 <= 2^-86.7519.
	   Since xr >= -2^-19.999, this gives a relative error rho3 less than
	   2^-86.7519/2^(-2^-19.999) < 2^-86.7518:
	   finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-86.7518
	*/
	if(__builtin_expect(do_red,1)) {
		d_mul(&finalh, &finall, finalh, finall, xs_pow2_h, xs_pow2_l);
	  /* We have xs_pow2_h + xs_pow2_l = 2^frac(r) * (1 + rho2)
	     with |rho2| < 2^-99.1, and
	     finalh + finall = 2^xr * (1 + rho3) with |rho3| < 2^-86.7518.
	     The intrinsic relative error of the product is at most
	     (1 + rho2) * (1 + rho3) - 1 <= 2^-99.1 + 2^-86.7518
	                                  + 2^-99.1*2^-86.7518 <= 2^-86.7515

	     Expanding the d_mul call, we see that:
	     Since |finalh*xs_pow2_h| < 1.002*2 = 2.004,
	     |s| <= ulp(2.004) = 2^-51. Then, since
	     |finall*xs_pow2_h + s| <= 2^-50.8 * 2 + 2^-51 <= 2^-49.278 we get
	     |t| <= 2^-49.277 and that the rounding error on t is at most
	     ulp(2^-49.278) = 2^-102.
	     We compute |finalh*xs_pow2_l + t| <= 1.004*2^-48.2+2^-49.277
	     <= 2^-47.636. This ensures that the rounding error computing
	     *lo is less than ulp(2^-47.636) = 2^-100.
	     The total rounding error is therefore at most
	     2^-102 + 2^-100 <= 2^-99.678.
	     The error due to neglecting xs_pow2_l * finall is at most
	     |xs_pow2_l * finall| <= 2^-48.2 * 2^-50.8 <= 2^-99, thus adding
	     it yields an error < 2^-99.678 + 2^-99 <= 2^-98.299.

	     Since the product should be at least exp(-2^-19.999), this
	     translates to an additional relative error
	     rho4 <= 2^-98.299/2^(-2^-19.999), so rho4 <= 2^-98.298.
	     Taking into account rho1, the total relative error is thus at most
	     (1 + 2^-86.7515)(1 + rho1)(1 + rho4) - 1 <= 2^-85.010:
	     |finalh + finall - 2^frac(r) * 2^xr| < 2^-85.010.

	     Moreover since 0.499 < |finalh_old| <= 1.002 and
	     1 <= xs_pow2_h < 2, we deduce 0.499 < |finalh| < 2.004.
	  */
	} else {
		/* The only error made is rho3, the total relative error
		   is at most 2^-86.7518. */
		extra_exponent = 0;
	}
	*resh = finalh;
	*resl = finall;
	return extra_exponent;
}

/* Rounding and rounding test for the fastpath.
   Assume 2^extra_exp * (rh + rl) = x^y * (1 + eps) with |eps| < 2^-83.287,
   with 0.499 < |rh| < 2.004, |rl| <= 2^-47.638.
*/
static
long double fastpath_roundtest(double rh, double rl, int extra_exp,
                               bool invert, bool* fail) {
	unsigned rm = get_rounding_mode();
	fast_two_sum(&rh, &rl, rh, rl); // The fast_two_sum precondition is satisfied

	b64u64_t th = {.f = rh}, tl = {.f = rl};
	long eh = th.u>>52, el = (tl.u>>52)&0x3ff, de = eh - el;
	// the high part is always positive, the low part can be positive or negative
	// represent the mantissa of the low part in two's complement format
	long ml = (tl.u&~(0xffful<<52))|1l<<52, sgnl = -(tl.u>>63);
	ml = (ml^sgnl) - sgnl;
	int64_t mlt;
	long sh = de-11;
	if(__builtin_expect(sh>63,0)){
		mlt = sgnl;
		if(__builtin_expect(sh-64>63,0)) ml = sgnl;
		else ml >>= sh-64;
	} else {
		mlt = ml>>sh;
		ml = (uint64_t)ml << (64-sh);
	}

	// construct the mantissa of the long double number
	uint64_t mh = ((th.u<<11)|1ull<<63);

	mh += mlt;
	if(__builtin_expect(!(mh>>63),0)){ // the low part is negative and
	                                   // can unset the msb so shift the
	                                   // number back
		mh = mh<<1 | (uint64_t)ml>>63;
		ml = (uint64_t)ml<<1;
		extra_exp--;
	}
	int64_t eps = (mh >> (83 - 64));
	// 83 comes from |eps| < 2^-83.287 and the fast_two_sum's error

	int wanted_exponent = extra_exp + 0x3c00 + eh;

	if(__builtin_expect(wanted_exponent <= 0, 0)) { // underflow case
		int shiftby = 1 - wanted_exponent;

		if(__builtin_expect(shiftby >= 64, 0)) {	
			ml = mh >> (shiftby - 64); mh = 0; eps = 1;
			if(__builtin_expect(shiftby > 65, 0)) {
				*fail = false; return invert ? -0x1p-16445L*.25L : 0x1p-16445L*0.25L;
			}
			// This overestimates epsilon, which is safe
		} else {
			ml = (uint64_t)ml >> shiftby;
			ml |= mh << (64 - shiftby);
			mh >>= shiftby;
			eps >>= shiftby;
			eps += 1;
		}
		wanted_exponent = 0;
	}

	uint64_t oldmh = mh; // For overflow detection
	if(rm==FE_TONEAREST){ // round to nearest
		mh += (uint64_t)ml>>63; // add the round bit
		ml = (uint64_t)ml<<1;
                eps <<= 1;
		/* Multiplying ml by 2 we discard the round bit,
		   thus the rounding test will fail even if we are
		   near an exact value. The reason is that when x^y
		   is exact, we should reset the inexact flag. Since
		   testing whether x^y is exact is expensive, we delegate
		   this case to the accurate path. Thus we sacrifice
		   x^y exact to make the average case faster. */
	} else if((rm==FE_UPWARD && !invert) || (rm==FE_DOWNWARD && invert)) {
		mh += 1;
		// This is as if ml had a trailing 1.
		// We are not precise up to an LSB of ml anyway.
	}

	// This branch can only be taken if wanted_exponent != 0
	// Else we simply cannot have an overflow
	if(__builtin_expect(mh < oldmh, 0)) {
		ml = ml/2; // Signed semantics matter
		eps >>= 1;
		mh = (uint64_t) 1 << 63;
		wanted_exponent++;
	}

	// We had a denormal but rounding made it into the smallest normal
	if(__builtin_expect((mh>>63) && !wanted_exponent, 0)) {
		wanted_exponent = 1;
	}

	b80u80_t v;
	v.m = mh; // mantissa
	v.e = wanted_exponent; // exponent
	if(__builtin_expect(invert, 0)) {v.e += (1<<15);}
	bool b1 = (uint64_t)ml + eps <= (uint64_t)(2*eps);
	*fail = b1;

	// Denormals *inside* the computation don't seem to be a problem
	// given the error analysis (we used absolute bounds mostly)

	// Infinity output case, when we know we won't take the accurate path
	if(__builtin_expect(wanted_exponent >= 32767 && !*fail, 0)) {
		return (invert ? -0x1p16383L - 0x1p16383L : 0x1p16383L + 0x1p16383L);
	}

	// inexact underflow case
	if (__builtin_expect (wanted_exponent == 0 && !*fail, 0)) {
	  feraiseexcept (FE_UNDERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
	  errno = ERANGE; // underflow
#endif
	}

	return v.f;
}

/* Given |x| < 2^-11.999 fitting in 128 bits,
computes an approximation of log2(1 + x).
Relative error at most 2^-249.997 (see analyze_logpoly() in
accurate_analysis.sage)
*/
inline static
void q_logpoly(qint64_t* r, const qint64_t* x) {
	/* We use a naïve Horner scheme as a placeholder,
	   can most definitely be improved.
	   Coefficients for log2(1 + x)/x
	   Minimax polynomial of degree 18 from accurate_log2.sollya,
	   with maximal relative error < 2^-250.299.
	*/
	static const qint64_t P[19] = {
		{.hh = 0x9b81e344cc4acd3f, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x0}, /* degree 18 */
		{.hh = 0xa4258caa93661016, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x1}, /* degree 17 */
		{.hh = 0xadcd64dba1f4c039, .hl = 0x2cdde110238be8d8, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x0}, /* degree 16 */
		{.hh = 0xb8aa3b295c127161, .hl = 0xfba1b1615d052d58, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x1}, /* degree 15 */
		{.hh = 0xc4f9d8b4a67fefb7, .hl = 0x3425410828a24674, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x0}, /* degree 14 */
		{.hh = 0xd30bb153d6f6c9fb, .hl = 0x28e9fdc71f70e43e, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x1}, /* degree 13 */
		{.hh = 0xe347ab4698bb00e7, .hl = 0x11e274b19fcf82ca, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x0}, /* degree 12 */
		{.hh = 0xf6384ee1d01feba4, .hl = 0xfe0aa911f62b593b, .lh = 0x0, .ll = 0x0, .ex = -4, .sgn = 0x1}, /* degree 11 */
		{.hh = 0x864d424ca0116942, .hl = 0xb91d166906a0e72e, .lh = 0xfbc828ff26a1984a, .ll = 0x4e591874ecaec24e, .ex = -3, .sgn = 0x0}, /* degree 10 */
		{.hh = 0x93bb62877cdff3c9, .hl = 0x653998a6ba7dcc66, .lh = 0x16bdfd507a428b04, .ll = 0x41d10daaa8adc41c, .ex = -3, .sgn = 0x1}, /* degree 9 */
		{.hh = 0xa42589ebe01547c3, .hl = 0x54071b63eba83796, .lh = 0x2686f8891574e5f5, .ll = 0x4a2c567591c942f9, .ex = -3, .sgn = 0x0}, /* degree 8 */
		{.hh = 0xb8aa3b295c17f0bb, .hl = 0xbe87fed0691d3e88, .lh = 0xeb574d0da8d33458, .ll = 0x9fa51eba24fafe8, .ex = -3, .sgn = 0x1}, /* degree 7 */
		{.hh = 0xd30bb153d6f6c9fb, .hl = 0x22e490ee2efcd9c1, .lh = 0xcf6430a218437c7, .ll = 0x94f364a4987e6e8, .ex = -3, .sgn = 0x0}, /* degree 6 */
 		{.hh = 0xf6384ee1d01feba4, .hl = 0xfe0aa915e17c5361, .lh = 0x39c9f8e1273cd88d, .ll = 0x96a06e6ed417ed99, .ex = -3, .sgn = 0x1}, /* degree 5 */
		{.hh = 0x93bb62877cdff3c9, .hl = 0x653998a6ba7dcba0, .lh = 0xbc45fbba4abaaead, .ll = 0x3dee003a9576c9a2, .ex = -2, .sgn = 0x0}, /* degree 4 */
		{.hh = 0xb8aa3b295c17f0bb, .hl = 0xbe87fed0691d3e88, .lh = 0xeb577aa8dd695a58, .ll = 0x8afb83221b9653eb, .ex = -2, .sgn = 0x1}, /* degree 3 */
		{.hh = 0xf6384ee1d01feba4, .hl = 0xfe0aa915e17c5361, .lh = 0x39c9f8e127372320, .ll = 0xb986c890fa1e97e5, .ex = -2, .sgn = 0x0}, /* degree 2 */
		{.hh = 0xb8aa3b295c17f0bb, .hl = 0xbe87fed0691d3e88, .lh = 0xeb577aa8dd695a58, .ll = 0x8b25166cd1fa0378, .ex = -1, .sgn = 0x1}, /* degree 1 */
		{.hh = 0xb8aa3b295c17f0bb, .hl = 0xbe87fed0691d3e88, .lh = 0xeb577aa8dd695a58, .ll = 0x8b25166cd1a13248, .ex = 0, .sgn = 0x0}, /* degree 0 */
	};

	mul_qint_11(r, x, &P[0]); // Relative error ~2^-64 here is fine
	/* mul_qint_11 is exact when its inputs have only one limb, but here x might have
	   up to 75 bits, thus the relative error is < 2^-63 */

	for(int i = 1; i <= 7; i++) {
		add_qint_22(r, &P[i], r);
		mul_qint_22(r, r, x);
	}

	for(int i = 8; i <= 18; i++) {
			add_qint(r, &P[i], r);
			mul_qint(r, r, x);
	}
}

// put in r an 256-bit approximation of y*log2(x)
// assume x is normal, not 0, 2^-80 <= |y| < 2^78
// if x is negative, y should be an integer
// ensure r = y*log2(x) * (1 + eps) with |eps| < 2^-249.064
inline static
void q_log2pow(qint64_t* r, long double x, long double y) {
	b80u80_t cvt_x = {.f = x};
	int extra_int = (cvt_x.e&0x7fff) - 16383;
	int shiftamnt = __builtin_clzl(cvt_x.m); // We know x is not 0 so not UB

	extra_int -= shiftamnt ? (shiftamnt - 1) : 0;
	cvt_x.m <<= shiftamnt; // Handle denormals
	cvt_x.e = 16383; // new wanted exponent
	x = cvt_x.f; // original x = 2^extra_int * x

	/* Really, this is the same as in the fastpath. Try to merge to reduce
	   code cache footprint ?
	*/
	double xh, xl; // 33 and 31 bits
	split(&xh, &xl, x);
	// x = xh + xl with 1 <= |xh| <= 2 and |xl| < 2^-32
	// since 1 <= |x| < 2, xl is multiple of 2^-63

	// Uses the high 7 bits of x's mantissa.
	int i1 = cvt_x.m>>56 & 0x7f; // index in the coarse[] table
	lut_t l = coarse[i1];
	extra_int += l.z;
	xh *= l.r; xl *= l.r; // exact (see compute_log2pow)

	b64u64_t cvt_xh = {.f = xh};
	int i2 = (cvt_xh.u>>40) & 0x7f; // index in the fine[] table
	lut_t l2 = fine[i2];
	// bit 52 goes to 6+5 = 11. Bits 11 - 8
	xh = __builtin_fma(l2.r, xh, -1); xl *= l2.r;
	/* The above operations are exact (see the analysis in compute_log2pow). */

	two_sum(&xh, &xl, xh, xl);

	qint64_t reducted[1];
	qint_fromdd(reducted, xh, xl);
	/* From the fastpath we know that we should have |reducted| <= 2^-11.999.

	   Since the original xl was multiple of 2^-63, r1 is multiple of 2^-9
	   and r2 is multiple of 2^13, xl is a multiple of 2^-63*2^-9*2^-13 = 2^-85.
	   Furthermore, since the original xl satisfied |xl| < 2^-32, r1 <= 1 and r2 <= 2,
	   xl is at most 2*2^-32 = 2^-31. On the other hand, xh is a multiple of
	   2^-32*2^-9*2^-13 = 2^-54, and is at most 2^-12.
	   This ensures that when xh != 0 and xl != 0, the exponent difference
	   between xh and xl is at most 85 - 12 = 73, so that qint_fromdd's
	   precondition applies; computing reducted is exact.
	   Also, reducted must be a multiple of 2^-85
	   which is less than 2^-11.999 therefore reducted fits in 128 bits.
	*/

	qint64_t eint[1];
	qint_fromsi(eint, extra_int); // eint = extra_int

	qint64_t mlogr[1];
	add_qint(mlogr, &acc_coarsetbl[i1], eint);
	// mlogr approximates extra_int - log2(2^z*r1)

	qint64_t mlogr12[1];
	add_qint(mlogr12, &acc_finetbl[i2], mlogr);
	// mlogr12 approximates extra_int - log2(2^z*r1) - log2(r2)

	/* We have log2(x)= reduction + log2(1 + xr) */

	/* Since the accurate tables merely extend the precision of the fast
	   tables, the ratios computed by high_sum.c (-DMODE=0) stay valid.
	   By analogy to the fastpath, let us call mlogr1 and mlogr2 the values
	   looked up from the coarse and fine table respectively.

	   We then know that
	     |mlogr/mlogr12|  < 1.951
	     |mlogr2/mlogr12| <= 1
	   Furthermore, since |mlogr1| < .5 it is straightforward to see that
	     |mlogr| >= |mlogr1| (if eint=0, then mlogr=mlogr1).
	   The total relative error computing mlogr is 2^-254 due to rounding
	   errors and (at most) 2^-256 relative error due mlogr1's error:
	   this yields a relative error < 2^-254+2^-256 < 2^-253.7.
	   The total relative error of mlogr2 is also <= 2^-256.
	   This gives a relative error bound on mlogr12 as follows :
	   2^-254 + 2^-256*|mlogr2/mlogr12| + 2^-253.7*|mlogr/mlogr12|
	   <= 2^-254 + 2^-256*1 + 2^-253.7*1.951
	   <= 2^-252.131
	   We thus have an error on mlogr12 which is <= 2^-252.131 |mlogr12|.
	*/

	qint64_t q_y[1];
	qint_fromld(q_y, y); // exact

	q_logpoly(r, reducted);
	/* As mentioned in q_logpoly(), the relative error on the result is
	   at most 2^-249.997:
	   r = log2(1+reducted) * (1 + eps) with |eps| <= 2^-249.997
	*/

	add_qint(r, mlogr12, r);
	/* Let us call r_in/r_out the values of r as input/output.
	   From max_rh_over_rh_prime_all() in powl.sage, we have here
	   |mlogr12/r_out| <= 2.002 and |r_in/r_out| <= 1.002.
	   The relative errors 2^-252.131 on mlogr12 and 2^-249.997 on r,
	   together with the sum's rounding error, yield an error bound of
	     |r_out|*(2^-254 + 2.002*2^-252.131 + 1.002*2^-249.997)
	     <= |r_out|*2^-249.392
	   The total relative error computing log2(x) is therefore at most
	   2^-249.392:
	   r = log2(x) * (1 + eps) with |eps| <= 2^-249.392.
	*/

	mul_qint_41(r, r, q_y);
	/* The product imparts an additional relative rounding error of 2^-254.
	   The total relative error computing y log2(x) is thus at most
	     (1 + 2^-249.392) * (1 + 2^-254) - 1 < 2^-249.334 */
}

/* Let f be the low 20 bits of fracpart. Computes r and corr
such that 2^(f/2^20)*2^corr = r*(1 + e) with |e| < 2^-251.192,
and |corr| < 2^-103.
*/
inline static
void q_exp2xs(qint64_t* r, uint64_t fracpart, qint64_t* corr) {
	int i0 = fracpart & 0x1f;
	int i1 = (fracpart >> 5) & 0x1f;
	int i2 = (fracpart >> 10) & 0x1f;
	int i3 = (fracpart >> 15) & 0x1f;

	qint64_t tmp0[1], tmp1[1], tmp2[1], tmp3[1];
	qint_fromdd(tmp0, t0[i0][0], t0[i0][1]); corr_t corr0 = t0_corr[i0];
	qint_fromdd(tmp1, t1[i1][0], t1[i1][1]); corr_t corr1 = t1_corr[i1];
	qint_fromdd(tmp2, t2[i2][0], t2[i2][1]); corr_t corr2 = t2_corr[i2];
	qint_fromdd(tmp3, t3[i3][0], t3[i3][1]); corr_t corr3 = t3_corr[i3];
	/* Given the tables' construction, we have
	   2^(f/2^20)*2^corr0*...*2^corr3 = tmp0*...*tmp3*2^e0 with
	   |e0| <= 2^-294.064 + 2^-294.003 + 2^-294.051 + 2^-294.057
	        <= 2^-292.043 
	*/

	// as an unsigned value, MSB of corr_h has weight 2^-167*2^63 = 2^-104
	int exponent = -104;
	int64_t  corr_h = corr0.h + corr1.h + corr2.h + corr3.h;
	// no overflow in corr_h since each |corri.h| < 2^61
	unsigned __int128 corr_l = corr0.l + corr1.l + corr2.l + corr3.l;
	// no overflow in corr_l since each |corri.l| < 2^126

	corr_h += (unsigned) (corr_l >> 126); // add carry
	// by inspecting the corri.h values, we see
	// |corri.h| <= 1652397245814591285 thus no overflow is possible above
	corr_l <<= 2; // shift out overlap

	// the correction term is 2^exponent/2^63*(corr_h + corr_l/2^128)

	int sgn = corr_h < 0;
	if(sgn) {
	// Convert to sign and magnitude. Can be seen as a 196 2s complement
	// mantissa being inverted
		 corr_h = -corr_h - 1;
		 corr_l = -corr_l;
		/* The routine check_trivialzeroes() in powl.sage checks
		   that corr_l=0 can only happen for i0=i1=i2=i3=0,
		   thus here corr_l <> 0 and subtracting 1 to corr_h is right.
		*/
	}

	/* We use the fact that if corr_h == 0, then the whole reduction was
	   trivial. This is proven by check_trivialzeroes() in powl.sage */
	if(__builtin_expect(corr_h == 0, 0)) {
		cp_qint(corr, &ZERO_Q);
	} else {
		// Convert corr_h and corr_l to a qint
		int shift = __builtin_clzl(corr_h);
		corr_h = (uint64_t)corr_h<<shift;
		corr_h |= shift ? (corr_l >> (128 - shift)) : 0;
		corr_l <<= shift;
		corr->hh = corr_h;
		corr->hl = corr_l >> 64;
		corr->lh = (uint64_t) corr_l;
		corr->ll = 0;
		corr->sgn = sgn;
		corr->ex = exponent - shift;
	}

	qint64_t acc0[1], acc1[1];
	mul_qint_22(acc0, tmp0, tmp1);
	mul_qint_22(acc1, tmp2, tmp3);
	// The products above are exact
	mul_qint(r, acc0, acc1);
	/* This product introduces an error <= 14 ulps, i.e. a relative error
	   |r - tmp0*...*tmp3| <= 14*|r|*2^-255.

	   Therefore
	   |r - 2^(f/2^20)*2^-corr| <= |r - tmp0*...tmp3| + |(2^e0 - 1)*tmp0...tmp3|
	                            <= 14*2^-255|r| + |2^e0-1|(1 + 14*2^-255)|r|
	   This gives a total relative error of at most
	     14*2^-255 + (1 + 14*2^-255)*(2^(2^-292.043) - 1) < 2^-251.192
	*/
}

/* Approximates 2^x with a polynomial for |x| < 2^-20 + 2^-103.
Relative error bounded by 2^-253.896 (see accurate_analysis.sage)
*/
inline static
void q_exp2poly(qint64_t* r, const qint64_t* x) {
	/* This is a polynomial of degree 10 approximating 2^x on
	   [-2^-20-2^-103,2^-20+2^-103] with relative error bounded by 2^-261.066.
	   It was generated by Sollya (cf accurate_exp2.sollya).
	   Polynomial output with output_exppoly() from powl.sage.
	*/
	static const qint64_t Q[11] = {
    {.hh = 0xf267a8ac5c749bda, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = -28, .sgn = 0x0},
    {.hh = 0xda929e9caf40bee9, .hl = 0x28ba755cfbeb15af, .lh = 0x0, .ll = 0x0, .ex = -24, .sgn = 0x0},
    {.hh = 0xb160111d2e411fec, .hl = 0x7ff30374d01cdca8, .lh = 0x0, .ll = 0x0, .ex = -20, .sgn = 0x0},
    {.hh = 0xffe5fe2c45863435, .hl = 0x8a8e64398706e1c3, .lh = 0x0, .ll = 0x0, .ex = -17, .sgn = 0x0},
    {.hh = 0xa184897c363c3b7a, .hl = 0x58544c3591a0f9f6, .lh = 0x62916db41ee8676d, .ll = 0x9a0f49f2428577c7, .ex = -13, .sgn = 0x0},
    {.hh = 0xaec3ff3c53398883, .hl = 0x8bfb4d28a5f61982, .lh = 0xbb69ccdf430a035d, .ll = 0xc86feff9c6e5d36f, .ex = -10, .sgn = 0x0},
    {.hh = 0x9d955b7dd273b94e, .hl = 0x65df05a9f7562839, .lh = 0x23c7529f31c88ec9, .ll = 0x10b5dbd81066669c, .ex = -7, .sgn = 0x0},
    {.hh = 0xe35846b82505fc59, .hl = 0x9d3b15d995e96f74, .lh = 0xf5c47444da0110e2, .ll = 0x5a29dd80d795db82, .ex = -5, .sgn = 0x0},
    {.hh = 0xf5fdeffc162c7543, .hl = 0x78b583764b9afe55, .lh = 0x1d13a8e186734ea6, .ll = 0x15f49ddd89a9bc73, .ex = -3, .sgn = 0x0},
    {.hh = 0xb17217f7d1cf79ab, .hl = 0xc9e3b39803f2f6af, .lh = 0x40f343267298b62d, .ll = 0x8a0d175b8bb03a5a, .ex = -1, .sgn = 0x0},
    {.hh = 0x8000000000000000, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
	};

	mul_qint_11(r, &Q[0], x); // relative error of 2^-64 is fine here

	for(int i = 1; i <= 4; ++i) {
		add_qint_22(r, &Q[i], r);
		mul_qint_22(r, r, x);
	}

	for(int i = 5; i <= 9; i++) {
		add_qint(r, &Q[i], r);
		mul_qint(r, r, x);
	}

	add_qint(r, &Q[10], r);
}


/* Put in r an approximation of 2^x, assuming |x| < 2^15,
   with relative error bounded by 2^-250.085:
   r = 2^x * (1 + eps) with |eps| < 2^-250.085 */
inline static
void q_exp2(qint64_t* r, const qint64_t* x) {
	uint64_t xs = x->ex >= -20 ? (x->hh >> (43 - x->ex)) : 0;
	// xs = trunc(2^20*x), with low bit of xs having weight 2^-20,
	// and xs having the same (implicit) sign as x

	qint64_t reducted[1];
	reducted->hh = x->ex >= -20 ? (xs << (43 - x->ex)) : 0;
	reducted->hl = reducted->lh = reducted->ll = 0;
	reducted->sgn = x->sgn ^ 1;
	reducted->ex = x->ex;
	// reducted = -xs/2^20
        
	add_qint(reducted, x, reducted);
	// now x = xs/2^20 + reducted
	// With inlining, probably almost as fast as doing it by hand
	// Note that this is exact and that at output, we have
	// |reducted| < 2^-20

	/* Split xs * (-1)^x->sgn into entire part and fractional part.
	   If x >= 0 this is straightforward.
	   If x < 0, then we need to split -xs.
	   Calling e0 = xs>>20 and f0 = xs&0xfffff we have
	   xs = 2^20*e0 + f0 so -xs = 2^20*(-e0-1) + (2^20 - f0),
	   unless f0 == 0 in which case we need to split like 2^20*(-e0) + 0.
	*/
	int extra_exp;
	uint64_t fracpart;
	if(x->sgn) {
		fracpart = (1 << 20) - xs; // Only the low bits matter, notice that 0 -> 0.
		if(__builtin_expect(xs & 0xfffff, 1)) {
			extra_exp = -(xs>>20) - 1;
		} else {
			extra_exp = -(xs>>20); // case low(fracpart) = 0
		}
	} else {
		extra_exp = xs>>20;
		fracpart  = xs;
	}
	// now xs/2^20 * (-1)^x->sgn = extra_exp + low(fracpart)/2^20
	// with 0 <= low(fracpart) < 2^20

	qint64_t corr[1], exp2frac[1];
	q_exp2xs(exp2frac, fracpart, corr);
	// 2^(low(fracpart)/2^20) * 2^corr = exp2frac * (1 + e)
	// with |e| < 2^-251.192

	/* Now we have to multiply exp2frac by 2^reducted and divide
	   by 2^corr, thus multiply by 2^(reducted-corr) */
	corr->sgn ^= 1;
	add_qint(reducted, corr, reducted);
	/* Remark that the result is at most 2^-20 + 2^-103 < 2^-19.999.
	   Therefore the addition's rounding error is at most
	   2*ulp_256(2^-19.999) = 2^-274.
	*/

	qint64_t exp2red[1];
	q_exp2poly(exp2red, reducted);
	/* The polynomial evaluation incurs a relative error <= 2^-253.896:
	   exp2red = 2^reducted * (1 + eps) with |eps| <= 2^-253.896.
	*/

	mul_qint(r, exp2red, exp2frac);
	r->ex += extra_exp;
	/* We have the following errors:
	       * relative error < 14*2^-255 < 2^-251.192 for the product
	         exp2red*exp2frac
	       * relative error < 2^-253.896 for the approximation of 2^reducted
	       * absolute error < 2^-274 on the computation of reducted, which
	         translates into a relative error 2^(2^-274)-1 < 2^-274.528
	       * a relative error < 2^-251.192 for the approximation exp2frac
	   This yields a total relative error bounded by:
	   (1 + 2^-251.192)^2 * (1 + 2^-253.896) * (1 + 2^-274.528) - 1
	   <= 2^-250.085.
	*/
}

#include "powl_exact.h"

inline static
bool is_integer(long double x) {
	const b80u80_t cvt = {.f = x};
	int e = (cvt.e & 0x7fff) - 16383; // 2^e <= |x| < 2^(e+1)
	if (e >= 63) return true; // ulp(x) >= ulp(2^63) = 1 thus x is integer
	else {
		if (e <= -1) return cvt.m == 0; // |x| < 1
		// bit 0 of cvt.m has weight 2^(e-63)
		// thus bit 62-e corresponds to weight 1/2
		// we need the low 63-e bits to equal 000...000
		// now 0 <= e <= 62
		else {
			uint64_t u = cvt.m << (e + 1);
			return u == 0;
		}
	}
}

// return non-zero iff x is an odd integer
inline static
bool is_odd_integer(long double x) {
	const b80u80_t cvt = {.f = x};
	int e = (cvt.e&0x7fff) - 16383; // 2^e <= |x| < 2^(e+1)
	if (e >= 64) return false; // ulp(x) >= ulp(2^64) = 2 thus x is even
	else {
		if (e <= -1) return false; // |x| < 1
		// bit 0 of cvt.m has weight 2^(e-63)
		// thus bit 63-e corresponds to weight 1
		// we need the low 64-e bits to equal 1000...000
		// now 0 <= e <= 63
		else {
			uint64_t u = cvt.m << e;
			return u == (uint64_t) 1 << 63;
		}
	}
}

// return non-zero iff x is a NaN
inline static
int _isnan(long double x) {
	const b80u80_t v = {.f = x};
	return ((v.e&0x7fff) == 0x7fff && (v.m<<1));
}

// return non-zero iff x is a signaling NaN
inline static
int _issnan(long double x) {
	const b80u80_t v = {.f = x};
	return _isnan(x) && ((int64_t)(v.m<<1) > 0);
}

__attribute__((cold))
static
long double accurate_path(long double x, long double y, FLAG_T inex, bool invert) {
	qint64_t q_r[1]; q_log2pow(q_r, x, y);
	// q_r = y*log2|x| * (1 + eps_log) with |eps_log| < 2^-249.334

	if(q_r->ex >= 15) {
		// |q_r| >= 2^15 thus |y*log2|x|| >= 2^15/(1 + 2^-249.334) > 32767
		if(q_r->sgn) { // y*log2|x| < -32768: underflow
			return (invert ? -0x1p-16445L : 0x1p-16445L)*.25L;
		} else { // y*log2|x| > 32767: overflow
			return (invert ? -0x1p16383L : 0x1p16383L) * 2L;
		}
	}

	q_exp2(q_r, q_r);
	/* q_r = 2^(q_r_in) * (1 + eps_exp) with |eps_exp| < 2^-250.085
	   and since q_r_in = y*log2|x| * (1 + eps_log)
	   with |eps_log| < 2^-249.334, and |q_r_in| < 2^15,
	   we have:
	   q_r_in = y*log2|x| + eps with |eps| < 2^15*|eps_log| < 2^-234.334,

	   thus q_r = |x|^y * (1 + eps_pow)

	   with |eps_pow| = |(1 + eps_exp) * 2^eps - 1| < 2^-234.862
	*/

	unsigned rm = get_rounding_mode();

	qint64_t subqr[1];
	if(q_r->ex <= -16448) { 
		/* If q_r->ex = -16447 we may still really have exponent -16446 because
		   of errors, then round to 1p-16445.
		*/
		return (invert ? -0x1p-16445L : 0x1p-16445L) * .25L;
	}

	uint64_t extralow[1] = {0};
	// Extra-low limb to avoid loss of precision
	// when the final result is denormal. 
	qint_subnormalize(subqr, extralow, q_r);
	// In corner cases, qint_subnormalize creates a relative error 2^-255. This
	// implies that the total relative error is at most
	// 2^-234.862 + 2^-255 + 2^-255 * 2^-234.862 <= 2^-234.861

	bool exact_if_hard = __builtin_expect(check_rb(x,y,q_r),0);
	bool hard = false;
	long double r = qint_told(subqr, *extralow, rm, invert, &hard);
	b80u80_t cvt_r = {.f = r};

	/* Assume that (x,y) is a hard case in the sense that the accurate path
	   rounding test fails. Assume further that (x,y) is potentially exact or
	   midpoint, i.e. is in the set S defined in reference [2] for double
	   precision. For extended double the inputs (x,y) such that x^y is
	   exact or midpoint satisfy necessarily one of the following:

	   (a) x=2^k and y integer
	   (b) y integer, 2 <= y <= 41 (2 <= y <= 40 if x^y is exact)
	   (c) x=m*2^E and y=n*2^F with -5 <= F <= -1 and 3 <= n <= 41,
	       n odd (with n <= 40 if x^y is exact)

	   Let us note z the approximation we computed. We know that for some rounding
	   boundary r, |z - r| <= (2^-234 + 2^-254)|z| because the rounding test
	   failed. We also know that |z - x^y| <= 2^-234.861|z|. Thus we have
	   x^y = z * (1 + eps) with |eps| <= 2^-234.861, or |x^y/z - 1| <= 2^-234.861.
	   This implies that |x^y - r| <= (2^-234.861 + 2^-234 + 2^-254)|z|, or
	   |x^y - r| <= (2^-234.861+2^-234+2^-254)/(1-2^-234.861) |x^y|
	             <= 2^-233.367 |x^y|.

	   If we list with BaCSeL all cases where |x^y - r| <= 2^-233.367 |x^y|,
	   we may be able to certify that in all these cases, x^y is exact. When
	   run with parameter m, BaCSeL will output all pairs (x,y) in S at distance
	   less than 2^-m ulp(r') from a rounding boundary r'.
	   Since |x^y - r| <= 2^-233.367 |x^y| implies |x^y - r| <= 2^-169.367 ulp(r),
	   taking m=169 ensures we miss no hard case in S.
	   (It is obvious that r = r' whenever the discussed situation arises.
	   The argument above applies even when x^y is subnormal. Indeed, subnormal
	   rounding boundaries are a subset of the boundaries considered by BaCSeL.)
	*/

	if(hard && exact_if_hard) {
		/* If we are here, then either the rounding mode is not FE_TONEAREST
		   and we are on an exact number, or rm == FE_TONEAREST and we are near a
		   rounding boundary. 
		*/

		exactify(q_r);
		// Makes an exact rounding boundary out of q_r on unbounded exponent range

		qint_subnormalize(subqr,extralow, q_r);

		bool restore_flags = ((cvt_r.e&0x7fff) != 0x7fff) && !subqr->hl && !subqr->lh;
		// restore the inexact flag
		if( restore_flags ) {
			set_flag (inex);
		} else {
			feraiseexcept(FE_INEXACT);
		}

		/* If the result overflows, even if it would be exact with an unbounded
		   exponent range, the inexact flag must not be cleared. The mantissa checks
		   are there to check if the result is exact even accounting for
		   subnormalization.
		*/
		b80u80_t cvt = {.f = qint_told(subqr,*extralow, rm, invert, &hard)};
		// We return a non-exact subnormal
		if((cvt.e&0x7fff) == 0 && !restore_flags) {
			feraiseexcept(FE_UNDERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
			errno = ERANGE;
#endif
		}

		return cvt.f;
	}

//FIXME Do we have a standard macro switch ?
#ifndef CORE_MATH_FAIL_QUIET
	else if(hard) {
		printf ("Unexpected worst-case found.\n");
		printf ("Please report to core-math@inria.fr:\n");
		printf ("Worst-case of powl found: x,y=%La,%La\n", x, y);
		exit(1);
	}
#endif
	else {
		b80u80_t cvt = {.f = r};
		feraiseexcept(FE_INEXACT);
		if((cvt.e&0x7fff) == 0) { // We return a non-exact subnormal
			feraiseexcept(FE_UNDERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
			errno = ERANGE;
#endif
		}
		return r;
	}

}

long double cr_powl(long double x, long double y) {
	const b80u80_t cvt_x = {.f = x}, cvt_y = {.f = y};
	int x_exp = (cvt_x.e&0x7fff) - 16383;
	int y_exp = (cvt_y.e&0x7fff) - 16383;

	bool invert = false;     // true iff x^y < 0
	long double sign = 1.0L; // sign of x^y
	/* Both these variables hold the same information, but 
	   invert is more convenient for conditionals (in the rounding tests)
	   whereas sign is more convenient during special value handling.
	*/

	static const long double inf = __builtin_infl();
	bool lt1 = (x_exp < 0) ^ (cvt_y.e>>15);
	// If lt1 is set, then |x|^y < 1.
	// If lt1 is not set, then either |x|^y > 1 or |x|==1

	/* x is negative */
	if(__builtin_expect(cvt_x.e>>15, 0)) {
		if(__builtin_expect(_isnan(y)
		                    || (!is_integer(y) && cvt_x.m && x_exp != 0x7fff-16383)
		                    ,0)) {
			feraiseexcept(FE_INVALID);
#ifdef CORE_MATH_SUPPORT_ERRNO
			errno = EDOM;
#endif
			return __builtin_nanl("");
		}

		if(is_odd_integer(y)) {
			invert = true;
			sign = -1.0L;
		}
	}

	// x is either (s)NaN or +-infty
	if(__builtin_expect(x_exp == 0x7fff - 16383, 0)) {
		if(_issnan(x)) {
			feraiseexcept(FE_INVALID);
			return __builtin_nanl("");
		}
		if(!cvt_y.m) {return 1L;}
		if(_isnan(x) || _isnan(y)) {
			feraiseexcept(FE_INVALID);
			return __builtin_nanl("");
		}
		// Here x == +-infty and y != 0
		return lt1 ? sign*0L : sign*inf;
	} else

	// From now on, x is normal
	if(__builtin_expect(!cvt_x.m, 0)) { // x == +-0
		if(_isnan(y)) {feraiseexcept(FE_INVALID); return __builtin_nanl("");}
		if(!cvt_y.m) {return 1L;} // y == 0
		if(cvt_y.e>>15 && cvt_y.e != 0xffff) {
		  feraiseexcept(FE_DIVBYZERO);
#ifdef CORE_MATH_SUPPORT_ERRNO
		  errno = ERANGE; // pole error
#endif
		}
		return lt1 ? sign*0L : sign*inf;
	}

	/* For |y| >= 2^78, and |x| <> 1, the smallest value of
	   |y * log2(x)| is attained for x = 1 - 2^-64, and is > 23637,
	   thus |x^y| is smaller than the smallest positive subnormal
	   2^-16445, or largest than MAX_LDBL = 2^16384*(1-2^-64).
	   Here y is either +-inf, (s)NaN, or very large.
	*/
	else if(__builtin_expect(y_exp >= 78, 0)) {
		if(_issnan(y)) {feraiseexcept(FE_INVALID); return __builtin_nanl("");}
		if(x == 1.L) {return 1.L;}
		if(_isnan(y)) {feraiseexcept(FE_INVALID); return __builtin_nanl("");}
		if(x == -1.L) {return sign;}
		// y == +-infty
		if(y_exp == 0x7fff - 16383) {
			return lt1 ? sign*0L : sign*inf;
		} else {
#ifdef CORE_MATH_SUPPORT_ERRNO
		  errno = ERANGE; // overflow
#endif
			return lt1 ? (sign*0x1p-16445L)*.25L : (sign*0x1p16383L)*2L;
		}
	} else if(__builtin_expect(y_exp <= -81, 0)) {
		/* For y_exp <= -81, we have |y| < 2^-80,
		thus since |log2(x)| <= 16445, we have |y*log2(x)| < 0x1.00f4p-66.
		Since for |t| <= 0x1.71547652b82fe176p-65, 2^t rounds to 1
		to nearest, we can deduce the correct rounding. */
		if(!cvt_y.m || x == 1.L) {
			return 1.L;
		} else { // Here we know sign == 1.
				return lt1 ? 1. - 0x1p-16445L : 1. + 0x1p-16445L; 
		}
	}

	const FLAG_T inex = get_flag();

	// now -80 <= y_exp <= 77 thus 2^-80 <= |y| < 2^78
#ifndef ACCURATE_ONLY
	// Automatic giveup if x subnormal
	if(__builtin_expect(cvt_x.m >> 63, 1)) {
		long double r;
		double rh, rl;
		compute_log2pow(&rh, &rl, x, y);
                // rh + rl = y * log2(x) * (1 + eps1) with
                // |eps1| <= 2^-97.286 |rh| and |rl| <= 2^-48.262 |rh|
		double rhsq = rh*rh;
		/* This implies |rh| <= 1p-66;
		   Since |rl| <= 2^-48.262 |rh|,
		   |y * log2(x)| < 2^-66 * (1+2^-48.262) * (1+2^-97.286)
		   < 2^-65, and exp(+/-2^-65) rounds to 1 to nearest,
		   thus by monotonicity of rounding x^y rounds to 1
		   to nearest. */
		if(__builtin_expect(rhsq <= 0x1p-132, 0)) {
			return sign * 1.L + sign * rh;
		} else if(__builtin_expect(rhsq >= (16447*16447), 0)) {
		/* If |rh| >= 16447, then |rh + rl| > 164456.9 and depending on the
		   sign of rh we can deduce the correctly rounded result.
		*/
			if(rh > 0) {return sign*0x1p16383L + sign*0x1p16383L;}
			else {return (sign*0x1p-16445L)*.25L;}
		} else {
			// rh + rl approximates y*log2(x)
			double resh, resl;
			int extra_exponent = exp2d(&resh, &resl, rh, rl);
			/* 2^extra_exponent * (resh + resl)
			   = 2^(rh + rl) * (1 + eps2) with |eps2| <= 2^-85.010,
			   0.499 < |resh| < 2.004, |resl| <= 2^-47.638.
			   Since rh + rl = y * log2(x) * (1 + eps1) with
			   |eps1| <= 2^-97.286,
			   and |rh+rl| < 16446.1 * (1 + 2^-48.262),
			   we deduce |y * log2(x)| < 16446.2, thus
			   rh + rl = y * log2(x) + eps1_abs
			   with |eps1_abs| < 16446.2 * 2^-97.286 < 2^-83.280.
			   It follows:
			   2^extra_exponent * (resh + resl)
			   = x^y * 2^eps1_abs * (1 + eps2)
			   = x^y * (1 + eps)
			   with |eps| < 2^eps1_abs * (1 + eps2) - 1 < 2^-83.287
*/

			bool fail = false;
			r = fastpath_roundtest(resh, resl, extra_exponent, invert, &fail);
			if(__builtin_expect(!fail, 1)) {	
				return r;
			}
		}
	} // Fastpath failed or x was subnormal
#endif
	return accurate_path(x, y, inex, invert);
}
