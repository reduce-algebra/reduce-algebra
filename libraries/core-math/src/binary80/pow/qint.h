/* Correctly-rounded power function for two binary64 values.

Copyright (c) 2022-2025 CERN and Inria
Authors: Tom Hubrecht and Paul Zimmermann

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

/*
  This file contains type definition and functions to manipulate the qint64_t
  data type used in the third iteration of Ziv's method. It is composed of four
  uint64_t values for the mantissa and the exponent is represented by a signed
  int64_t value.
*/

#ifndef QINT_H
#define QINT_H

#include <stdint.h>
#include <stdio.h>
#include <errno.h>

/*
  Type definition
*/

#ifndef UINT128_T
#define UINT128_T

typedef unsigned __int128 u128;

typedef union {
  u128 r;
  struct {
    uint64_t l;
    uint64_t h;
  };
} uint128_t;

// Add two 128-bit integers and return 1 if a carry occured
static inline int addu_128 (uint128_t a, uint128_t b, uint128_t *r) {
  r->r = a.r + b.r;
  // Return the carry
  return r->r < a.r;
}

// Subtract two 128-bit integers and return 1 if a borrow occured
static inline int subu_128 (uint128_t a, uint128_t b, uint128_t *r) {
  r->r = a.r - b.r;
  // Return the borrow
  return r->r > a.r;
}

// Compare two 64-bit signed integers
// Return +1 if a > b, 0 if a=b, -1 if a < b
static inline signed char cmp (int64_t a, int64_t b) {
  return (a > b) - (a < b);
}

// Compare two 64-bit unsigned integers
// Return +1 if a > b, 0 if a=b, -1 if a < b
static inline signed char cmpu (uint64_t a, uint64_t b) {
  return (a > b) - (a < b);
}

#endif

// Add two 128-bit integers and return 1 if a carry occured
static inline int addu128 (u128 a, u128 b, u128 *r) {
  *r = a + b;
  // Return the carry
  return *r < a;
}

// Subtract two 128-bit integers and return 1 if a borrow occured
static inline int subu128 (u128 a, u128 b, u128 *r) {
  *r = a - b;
  // Return the borrow
  return *r > a;
}

typedef union {
  /* Use a little-endian representation.
     FIXME: adapt for big-endian processors. */
  struct {
    u128 rl;
    u128 rh;
    int64_t _ex;
    uint64_t _sgn;
  };
  struct {
    /* for a non-zero qint, hh has its most significant bit set,
       and the significand is in [1, 2):
       x = (-1)^sgn * m * 2^ex
       with m = hh/2^63 + hl/2^127 + lh/2^191 + ll/2^255
    */
    uint64_t ll; /* lower low part */
    uint64_t lh; /* upper low part */
    uint64_t hl; /* lower high part */
    uint64_t hh; /* upper high part */
    int64_t ex;
    uint64_t sgn;
  };
} qint64_t;

/*
  Constants
*/

// this encodes 1 (exact)
static const qint64_t ONE_Q = {.hh = 0x8000000000000000,
                               .hl = 0x0,
                               .lh = 0x0,
                               .ll = 0x0,
                               .ex = 0,
                               .sgn = 0x0};

// this encodes -1 (exact)
static const qint64_t M_ONE_Q = {.hh = 0x8000000000000000,
                                 .hl = 0x0,
                                 .lh = 0x0,
                                 .ll = 0x0,
                                 .ex = 0,
                                 .sgn = 0x1};

// LOG2_Q approximates log(2), with absolute error < 2^-256.14
static const qint64_t LOG2_Q = {.hh = 0xb17217f7d1cf79ab,
                                .hl = 0xc9e3b39803f2f6af,
                                .lh = 0x40f343267298b62d,
                                .ll = 0x8a0d175b8baafa2b,
                                .ex = -1,
                                .sgn = 0x0};

// LOG2_INV_Q approximates 2^12/log(2), with absolute error < 2^-52.96
static const qint64_t LOG2_INV_Q = {.hh = 0xb8aa3b295c17f0bc,
                                    .hl = 0x0,
                                    .lh = 0x0,
                                    .ll = 0x0,
                                    .ex = 12,
                                    .sgn = 0x0};

// this encodes 0 (exact)
static const qint64_t ZERO_Q = {
    .hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0};

/*
  Base functions
*/

// Copy a qint64_t value
static inline void cp_qint (qint64_t *r, const qint64_t *a) {
  r->ex = a->ex;
  r->rh = a->rh;
  r->rl = a->rl;
  r->sgn = a->sgn;
}

typedef union {
  double f;
  uint64_t u;
} f64_u;

// Extract both the mantissa and exponent of a double
static inline void fast_extract (int64_t *e, uint64_t *m, double x) {
  f64_u _x = {.f = x};

  *e = (_x.u >> 52) & 0x7ff;
  *m = (_x.u & (~0ul >> 12)) + (*e ? (1ul << 52) : 0);
  *e = *e - 0x3ff;
}

// Convert a double to the corresponding qint64_t value
static inline void qint_fromd (qint64_t *a, double b) {
  fast_extract (&a->ex, &a->hh, b);

  /* |b| = 2^(ex-52)*hi */

  uint32_t t = (a->hh) ? __builtin_clzl (a->hh) : 0;

  a->sgn = b < 0.0;
  a->ex = a->ex - (t > 11 ? t - 12 : 0);
  a->hh = a->hh << t;
  a->lh = 0;
  a->hl = 0;
  a->ll = 0;
  /* b = 2^ex*hh/2^64 where 1 <= hh/2^63 < 2 */
}

/* Convert a long double to a qint64_t value. Assumes x != 0.
*/
static inline void qint_fromld(qint64_t* a, long double x) {
	b80u80_t cvt_x = {.f = x};
	a->sgn = cvt_x.e>>15;
	a->ex  = (cvt_x.e&0x7fff) - 16383;
	a->hh  = cvt_x.m;
	int shiftamnt = __builtin_clzl(a->hh);
	a->hh <<= shiftamnt;
	a->ex -=  shiftamnt; // Subnormal handling
	a->hl = a->lh = a->ll = 0;
}

/*
Convert a double double into tint_t representation.
This is minimalistic : it assumes h and l are not denormals
and that the exponent difference is at most 75 when h,l != 0.
Also, we must have h = 0 or |h| >= |l|.

If the exponent difference is strictly less than 75, the operation
is exact; if it is 75 there may be a 2^-129 relative error in case
the binade of a is higher than that of h.
*/

static inline void qint_fromdd(qint64_t* a, double h, double l) {
	f64_u u = {.f = h};
	a->sgn = u.u >> 63;
	a->rl = 0;

	uint64_t ax = u.u & (-1l ^ (1ul<<63));
	u.f = l;
	uint64_t bx = u.u & (-1l ^ (1ul<<63));

	if(__builtin_expect(ax == 0, 0)) {
		qint_fromd(a, l);
		return;
	}

	int64_t exp = (ax >> 52) - 1023;
	a->ex = exp;
	unsigned __int128 mantissa = (1ul << 63) | (ax << 11);
	mantissa <<= 64;
	a->rh = mantissa;

	if(__builtin_expect(bx >> 52 != 0, 1)) { // bx != 0
		int de = (ax >> 52) - (bx >> 52);
		unsigned __int128 mantissa_b = (1ul << 52) | (bx & ((1ul<<52)-1));
		mantissa_b <<= 75 - de;

		unsigned __int128 new_mantissa;
		if((u.u>>63) ^ a->sgn) {
			new_mantissa = mantissa - mantissa_b;
			if(__builtin_expect(new_mantissa > mantissa, 0)) { // underflow
				a->sgn ^= 1;
				new_mantissa = -new_mantissa; // Positive mantissa
				// Renormalize
				if(new_mantissa >> 64) {
					unsigned shiftamnt = __builtin_clzl((new_mantissa >> 64));
					new_mantissa <<= shiftamnt;
					a->ex -= shiftamnt;
				} else {
					unsigned shiftamnt = __builtin_clzl((unsigned long)new_mantissa) + 64;
					new_mantissa <<= shiftamnt;
					a->ex -= shiftamnt;
				}
			}
		} else {
			new_mantissa = mantissa + mantissa_b;
			if(__builtin_expect(new_mantissa < mantissa, 0)) { // overflow
				a->ex += 1;
				new_mantissa >>= 1;
	      // If exponent difference is exactly 75, this may contribute 1 ulp of
	      // error.
				new_mantissa |= (unsigned __int128)(1) << 127;
			}
		}
		a->rh = new_mantissa;
	}
}

/* Converts a signed integer to qint exactly */
static inline void qint_fromsi(qint64_t* a, int32_t d) {
	if(__builtin_expect(d == 0, 0)) {
		cp_qint(a, &ZERO_Q);
		return;
	}

	a->sgn = d < 0;
	if(a->sgn) {
		d = -d;
	}
	unsigned shiftamnt = __builtin_clz(d);
	a->hh = (uint64_t) d << (32 + shiftamnt);
	a->ex = 31 - shiftamnt; // If shiftamnt == 31 then a->ex = 0
	a->hl = a->lh = a->ll = 0;
}

// expects x->ex >= -16447
// Causes a loss of precision for very small numbers. The introduced
// error is at most 2^-255|x|.
// Puts in extralow the low (shifted) part of weight ll/2^64
// (plus maybe an extra bit if ex = -16447)
// Ensures a->ex >= -16383 at output.
void qint_subnormalize(qint64_t* a, uint64_t* extralow, const qint64_t* x) {
	if(__builtin_expect(!x->hh, 0)) {
		cp_qint(a, &ZERO_Q);
		a->sgn = x->sgn;
		return;
	}

	if(__builtin_expect(x->ex <= -16383, 0)) { // subnormal number
		int shiftby = -x->ex - 16383 + 1; // 1 <= shiftby <= 65
		/* Put in a->ex the real exponent shifted by one
		   (it should be -16382), so that qint_told() does not have to
		   distinguish between normal and subnormal numbers. */
		a->ex = -16383;
		if(__builtin_expect(shiftby >= 64, 0)) { // shiftby = 64 or 65
			shiftby -= 64; // now shiftby = 0 or 1
			a->hh = 0;
			a->hl = x->hh >> shiftby;
			a->lh = (x->hh << (64 - shiftby)) | (x->hl >> shiftby);
			a->ll = (x->hl << (64 - shiftby)) | (x->lh >> shiftby);
			*extralow = (x->lh << (64 - shiftby)) | (x->ll >> shiftby) | (x->ll&1);
			// If shiftby = 0, the last part does nothing. If shiftby = 1 it ensures
			// that we can correctly compute directed roundings. In any case, since
			// we lose a bit, this introduces error 2^-255|x|.
			a->sgn = x->sgn;

			return;
		}

		// Here 1 <= shiftby < 64
		a->hh = x->hh >> shiftby;
		a->hl = (x->hh << (64 - shiftby)) | (x->hl >> shiftby);
		a->lh = (x->hl << (64 - shiftby)) | (x->lh >> shiftby);
		a->ll = (x->lh << (64 - shiftby)) | (x->ll >> shiftby);
		*extralow = x->ll << (64 - shiftby);
		a->sgn = x->sgn;

		return;
	}
	cp_qint(a, x);
	*extralow = 0;
}

// Subnormalization is already done, this only deals with infinities/zeroes
// and rounding.
// Assumes extralow is an extra limb of weight ll/2^64,
// and b->ex >= -16383.
// invert is true iff x^y < 0
long double qint_told(qint64_t* a, uint64_t extralow,
                      unsigned rm, bool invert, bool* hard) {
	bool f = false; // true iff overflow is possible
	if(rm==FE_TONEAREST) {
		a->hh += a->hl>>63;
		f = a->hl>>63; // round bit
		a->hl ^= (uint64_t) 1 << 63;
		if(a->hl == 0 && a->lh == 0 && a->ll == 0 && extralow==0 && (a->hh&1)) {
			// We were on the rounding boundary and rounded away instead of to zero
			a->hh -= 1;
			f = false;
		}
	} else if((rm==FE_UPWARD && !invert) || (rm==FE_DOWNWARD && invert)) {
		// The special handling of extralow described above ensures this is
		// correct in all cases.
		a->hh += a->hl || a->lh || a->ll || extralow;
		f = true;
	}

	// Note that hl || lh || ll holds the distance from the rounding
	// boundary, with same sign as hh

	if(__builtin_expect(f && (a->hh == 0), 0)) { // overflow
			a->hh = (uint64_t) 1 << 63;
			extralow = (extralow >> 1) | (a->ll << 63);
			a->ll = (a->ll >> 1) | (a->lh << 63);
			a->lh = (a->lh >> 1) | (a->hl << 63);
			a->hl = (a->hl >> 1) | (a->hl & ((uint64_t)1 << 63)); // Sign extend
			a->ex++;
	}

	/* If we "overflowed" here, we are back to the smallest normal number. Undo
	   the exponent shift by 1 which was done by qint_subnormalize()
	   to correctly encode this smallest normal number
	*/
	if(__builtin_expect((a->hh>>63) && a->ex == -16383, 0)) {
		a->ex = -16382;
	}

	b80u80_t v;
	v.m = a->hh;         // significand
	v.e = a->ex + 16383; // biased exponent
	static const int sign_bit[] = {0, 1<<15};
	v.e += sign_bit[invert];

	uint64_t original_hl = a->hl;
	if(rm==FE_TONEAREST) {
		/* We shift the rounding part, so that for rm==FE_TONEAREST, it
		   represents the cfrac of the distance to the closest rounding boundary
		   (midpoint OR exact).
		   The following arguments assume that we are in a directed rounding mode.
		   They still hold for rm==FE_TONEAREST because then we shift left a's
		   rounding part AND epsilon. (So the net effect is only a wraparound at the
		   midpoint).
		*/
		a->hl = (a->hl << 1) | (a->lh >> 63);
		a->lh = (a->lh << 1) | (a->ll >> 63);
		a->ll = (a->ll << 1) | (extralow >> 63);
		extralow = extralow << 1;
	}

	/* cfrac(d/2^128) is the signed distance to the rounding boundary,
	   in terms of ulp(v), with error less than 1/2^-128, where cfrac()
	   is the centered fractional part. */
	unsigned __int128 d = ((unsigned __int128) a->hl << 64) + a->lh;

	/* The relative error is bounded by 2^-234.861 (see analysis of
	   cr_powl in powl.c) thus by 2^(64-234.861) = 2^-170.861 ulp(v).
	   Therefore, if d != 0 and d != -1, then the rounding test must pass
	   because this implies that the distance to the rounding boundary is
	   at least (1-2^-128)/2^128 ulp > 2^-170.861 ulp for a normal result.
	   If we are in the denormal range, d has even more relative weight
	   and this stays true.
	*/
	if(__builtin_expect(d != 0 && d+1 != 0, 1)) {
		*hard = false;
	} else {
		/* d||d_extra holds the 192 low bits of the fractional part. The higher
		   bits are all 0 or all 1.
		*/
		d = (d << 64) + a->ll;
		uint64_t d_extra = extralow;

	  /* cfrac(d/2^128)/2^64 is the signed distance to the rounding
	     boundary, in terms of ulp(v) */
		unsigned __int128 eps = ((unsigned __int128)(a->hh) << 64) + original_hl;
		uint64_t eps_extra  = 0;

		/* Not counting the lower limbs, the error bound is
		   2^-234.861*|v| <= 2^-234.861 * hh * ulp(v),
		   where hh is interpreted as a 64-bit integer.
		   To align with d, which is the signed distance in terms of
		   2^-192 ulp(v), we have multiply by 2^192 and divide by ulp(v):
		   2^192 * 2^-234.861 * hh = 2^-42.861 * hh,
		   where hh is interpreted as a 64-bit integer.
		   In terms of eps which is a 128-bit integer this yields:
		   2^-64 * 2^-42.861 * eps < 2^-106 * eps
		   We scale accordingly.
		*/

		/* If rm==FE_TONEAREST, because of the wraparound behavior we introduced,
		   we only shift by 105 bits.
		*/
		if(rm==FE_TONEAREST) {
			eps_extra = (uint64_t)(eps >> (105-64));
			eps >>= 105;
		} else {
			eps_extra = (uint64_t) (eps >> (106-64));
			eps >>= 106;
		}

		eps_extra += 1; // Make sure we over-approximate eps.

		/* The scaling introduces an error at most 1 lsb of eps_extra.
		   Assume we are in a directed rounding mode.
		   We know that initially a's MSB is at most at position 65 counting
		   from the highest bit of the mantissa. Therefore 1 lsb of eps_extra
		   has relative weight 2^(-255 - 64 + 65) = 2^-254.

		   Failure of the rounding test therefore implies that
		   |z - r| <= (2^-234 + 2^-254)|z|.

		   If rm==FE_TONEAREST, the same bound applies by noticing that given our
		   scalings, we introduced a relative error half that of the directed case.
		*/

		/* Implements the usual rounding test d + eps <= 2*eps on 192 bits */
		uint64_t d_plus_eps_extra = eps_extra + d_extra; 
		unsigned __int128 d_plus_eps = d + eps;
		if (d_plus_eps_extra < eps_extra)
			d_plus_eps++; // carry in eps_extra + d_extra

		uint64_t eps2_extra = eps_extra << 1;
		unsigned __int128 eps2 = (eps << 1) | (eps_extra >> 63);
		// eps2 + eps2_extra/2^64 = 2*(eps + eps_extra/2^64)

		*hard = (d_plus_eps < eps2) ||
		        (d_plus_eps == eps2 && d_plus_eps_extra < eps2_extra);
	}

	if(__builtin_expect(a->ex >= 16384, 0)) {// overflow case
#ifdef CORE_MATH_SUPPORT_ERRNO
	  errno = ERANGE;
#endif
	  return invert ? (-0x1p16383L - 0x1p16383L) : (0x1p16383L + 0x1p16383L);
	}
	return v.f;
}


static inline int cmpu128 (u128 a, u128 b) { return (a > b) - (a < b); }

/* Compare the absolute values of a and b:
   return +1 if |a| > |b|, 0 if |a| = |b|, -1 if |a| < |b| */
static inline signed char cmp_qint(const qint64_t *a, const qint64_t *b) {
  return cmp(a->ex, b->ex)  ? cmp(a->ex, b->ex)
    : cmpu128(a->rh, b->rh) ? cmpu128(a->rh, b->rh)
    : cmpu128(a->rl, b->rl);
}

/* same as cmp_qint, but only compare the upper 2 limbs */
static inline signed char cmp_qint_22(const qint64_t *a, const qint64_t *b) {
  return cmp(a->ex, b->ex)  ? cmp(a->ex, b->ex)
    : cmpu128(a->rh, b->rh);
}

/* Add two qint64_t values, with error bounded by 2 ulps (ulp_256).
   If Sterbenz theorem applies, i.e., a and b are of opposite signs
   with |a|/2 <= |b| <= |a|, then the operation is exact. */
static inline void
add_qint (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  if (a->rh == 0 && a->rl == 0) {
    cp_qint (r, b); // exact
    return;
  }

    if (b->rh == 0 && b->rl == 0) {
    cp_qint (r, a); // exact
    return;
  }

  /* compare the absolute values of a and b */
  switch (cmp_qint (a, b)) {
  case 0: /* |a| = |b| */
    if (a->sgn ^ b->sgn) { /* signs differ */
      cp_qint (r, &ZERO_Q); // exact
      return;
    }

    cp_qint (r, a);
    r->ex++; // exact
    return;

  case -1: /* |a| < |b| */
    add_qint (r, b, a);
    return;
  }

  // From now on, |A| > |B|

  u128 ah = a->rh, al = a->rl, bh = b->rh, bl = b->rl;

  int64_t m_ex = a->ex;
  int64_t k = a->ex - b->ex;

  if (k > 0) {
    if (k >= 128) {
      bl = (k < 256) ? bh >> (k - 128) : 0;
      bh = 0;
    } else { /* 1 <= k <= 127 */
      bl = (bl >> k) | (bh << (128 - k));
      bh = bh >> k;
    }
  }

  /* now we have to add (ah,al) + (bh,bl), with error <= 1 ulp
     corresponding to the ignored part of (bh,bl) */

  unsigned char sgn = a->sgn;
  uint64_t ex;
  u128 ch, cl;

  r->ex = m_ex;

  if (a->sgn ^ b->sgn) { // subtraction case
    /* a and b have different signs: C = A + (-B) */
    ch = ah - bh;

    if (subu128 (al, bl, &cl))
      ch --;
    /* we cannot have C=0 since |A| > |B| */
    uint64_t chh = ch >> 64, clh = cl >> 64;
    ex =
      chh ? __builtin_clzl(chh)
      : 64 + (ch ? __builtin_clzl(ch)
              : 64 + (clh ? __builtin_clzl(clh)
                      : 64 + __builtin_clzl(cl)));
    /* ex < 256 since |A| > |B| */

    /* If ex=0 or ex=1, the rounding error is bounded by 2 ulps. */
    if (ex > 0)
      {
        /* shift A by ex bits to the left, and B by ex-k bits to the left */
        if (ex >= 128)
          {
            ah = al << (ex - 128);
            al = 0;
          }
        else /* 1 <= ex < 128 */
          {
            ah = (ah << ex) | (al >> (128 - ex));
            al = al << ex;
          }
        int sh = ex - k;
        bh = b->rh;
        bl = b->rl;
        if (sh >= 0) {
          if (sh >= 128) {
            bh = bl << (sh - 128);
            bl = 0;
          }
          else if (sh > 0) { /* 1 <= sh < 128 */
            bh = (bh << sh) | (bl >> (128 - sh));
            bl = bl << sh;
          }
        }
        else { /* sh < 0: shift b by -sh bits to the right */
          int j = -sh;
          if (j >= 128) {
            bl = bh >> (j - 128);
            bh = 0;
          }
          else { /* 0 < j < 128 (j cannot be 0 since sh < 0) */
            bl = (bh << (128 - j)) | (bl >> j);
            bh = bh >> j;
          }
        }
        r->ex -= ex;
        ch = ah - bh;

        if (subu128 (al, bl, &cl))
          ch --;
        /* we cannot have C=0 since |A| > |B| */
        chh = ch >> 64;
        clh = cl >> 64;
        ex =
          chh ? __builtin_clzl(chh)
          : 64 + (ch ? __builtin_clzl(ch)
                  : 64 + (clh ? __builtin_clzl(clh)
                          : 64 + __builtin_clzl(cl)));
      }
    if (ex) {
      ch = (ch << ex) | (cl >> (128 - ex));
      cl = cl << ex;
    }
    r->ex -= ex;
    /* We distinguish three cases according to the first value of ex:
       If ex=0, the error is bounded by 1 ulp (ignored part of B).
       If ex=1, the error is bounded by 2 ulps (ignored part of B
         multiplied by 2).
       In the case ex>1, the error is bounded by 1 ulp (truncated part of B),
       which might be multiplied by 2 if the final value of ex is 1.
    */
  } else { // addition case
    char cy = addu128 (ah, bh, &ch);

    if (addu128 (al, bl, &cl))
      cy += !(++ch);

    /* 0 <= cy <= 1 */

    if (cy) { // carry in the 256-bit addition
      cl = (ch << 127) | (cl >> 1);
      ch = ((u128)1 << 127) | (ch >> 1);
      r->ex ++;
    }
    /* In the addition case, the rounding error is bounded by 1 ulp. */
  }

  r->sgn = sgn;
  r->rh = ch;
  r->rl = cl;
}

/* same as add_qint, but only considers the upper 2 limbs of a and b,
   with rounding error < 2 ulp_128(r) */
static inline void
add_qint_22 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  if (a->rh == 0) {
    cp_qint (r, b); // exact
    return;
  }

    if (b->rh == 0) {
    cp_qint (r, a); // exact
    return;
  }

  /* compare the absolute values of a and b */
  switch (cmp_qint_22 (a, b)) {
  case 0: /* |a| = |b| */
    if (a->sgn ^ b->sgn) { /* signs differ */
      cp_qint (r, &ZERO_Q); // exact
      return;
    }

    cp_qint (r, a);
    r->ex++; // exact
    return;

  case -1: /* |a| < |b| */
    add_qint_22 (r, b, a);
    return;
  }

  // From now on, |A| > |B|

  u128 ah = a->rh, bh = b->rh;

  int64_t m_ex = a->ex;
  uint64_t k = a->ex - b->ex;

  if (k > 0)
    bh = (k >= 128) ? 0 : bh >> k;

  /* now we have to add ah + bh, with error <= 1 ulp
     corresponding to the ignored part of bh */

  unsigned char sgn = a->sgn;
  uint64_t ex;
  u128 ch;

  r->ex = m_ex;

  if (a->sgn ^ b->sgn) { // subtraction case
    /* a and b have different signs: C = A + (-B) */
    ch = ah - bh;

    /* we cannot have ch=0 since |A| > |B| */
    uint64_t chh = ch >> 64;
    ex = chh ? __builtin_clzl(chh) : 64 + __builtin_clzl(ch);

    /* ex < 128 since |A| > |B| */

    if (ex > 0)
      {
        /* shift A and B by ex bits to the left */
        ah = ah << ex;
        /* for B, we have to shift by k bits to the right and ex to the left */
        if (ex >= k)
          bh = b->rh << (ex - k); // since ex < 128, the shift is well defined
        else
          bh = b->rh >> (k - ex);
        /* since k < 128 (otherwise bh=0 and ch=ah thus ex=0), this shift is
           also well defined */
        r->ex -= ex;
        ch = ah - bh;

        /* we cannot have C=0 since |A| > |B| */
        chh = ch >> 64;
        ex = chh ? __builtin_clzl(chh) : 64 + __builtin_clzl(ch);
        /* rounding error is bounded by 1 ulp(128) */
      }
    ch = ch << ex;
    /* if ex=1, the rounding error is multiplied by 2, thus < 2 ulp(128) */
    r->ex -= ex;
  } else { // addition case
    char cy = addu128 (ah, bh, &ch);

    if (cy) { // carry in the 128-bit addition
      ch = ((u128) 1 << 127) | (ch >> 1);
      r->ex ++;
    }
    /* In the addition case, the rounding error is bounded by 1 ulp(128) */
  }

  r->sgn = sgn;
  r->rh = ch;
  r->rl = 0;
}

// Multiply two dint64_t numbers, with error < 14 ulps
static inline void
mul_qint (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);

  u128 r32 = (u128)(a->hh) * (u128)(b->hl);
  u128 r23 = (u128)(a->hl) * (u128)(b->hh);

  u128 r31 = (u128)(a->hh) * (u128)(b->lh);
  u128 r13 = (u128)(a->lh) * (u128)(b->hh);
  u128 r22 = (u128)(a->hl) * (u128)(b->hl);

  u128 r30 = (u128)(a->hh) * (u128)(b->ll);
  u128 r03 = (u128)(a->ll) * (u128)(b->hh);
  u128 r21 = (u128)(a->hl) * (u128)(b->lh);
  u128 r12 = (u128)(a->lh) * (u128)(b->hl);

  u128 t6, t5, t4, t3;
  u128 c5, c4;

  t3 = (r12 >> 64) + (r21 >> 64) + (r03 >> 64) + (r30 >> 64);
  /* no overflow since each term is < 2^64, thus the sum < 2^66 */

  /* t3 is the sum of the terms of "degree" 3 divided by 2^64 */

  c4 = addu128 (r22, t3, &t4);
  c4 += addu128 (r13, t4, &t4);
  c4 += addu128 (r31, t4, &t4);

  /* (c4:1,t4:128) is the sum of the terms of "degree" 3 and 4 */

  c5 = addu128 (r23, t4 >> 64, &t5);
  c5 += addu128 (r32, t5, &t5);

  /* (c5:1,t5:128,low(t4):64) is the sum of the terms of "degree" 3 to 5 */

  t6 = r33 + ((c5 << 64) | (t5 >> 64)) + c4;

  /* (t6:128,low(t5):64,low(t4):64) is the sum of the terms of "degree" 3-6 */

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
     The approximated sum is:
     t6 (128 bits) + low(t5) (64 bits) + low(t4) (64 bits) + low(t3) (64 bits)
     with error bounded by:
     * 3*(B-1)^2/B^2 ulp for the neglected terms of "degree" 2: r20 + r11 + r02
     * 2*(B-1)^2/B^3 ulp for the neglected terms of "degree" 1: r10 + r01
     * 1*(B-1)^2/B^4 ulp for the neglected term of "degree" 0: r00
     * 1 ulp for each of the neglected low parts of r12, r21, r03 and r30
       thus 4 ulps in total
     The sum of the first three terms is less than 3, thus bounded by 3 ulps.
     This yields an error bound of 7 ulps so far.
  */

  uint64_t ex = !(t6 >> 127);

  t5 = (t5 << 64) | (t4 & (u128) 0xffffffffffffffff);
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
    /* the previous rounding error is multiplied by 2, thus < 14 ulps now */
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
    /* error < 7 ulps */
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the upper 3 limbs from a and b,
   and with error < 6 ulps */
static inline void
mul_qint_33 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);

  u128 r32 = (u128)(a->hh) * (u128)(b->hl);
  u128 r23 = (u128)(a->hl) * (u128)(b->hh);

  u128 r31 = (u128)(a->hh) * (u128)(b->lh);
  u128 r13 = (u128)(a->lh) * (u128)(b->hh);
  u128 r22 = (u128)(a->hl) * (u128)(b->hl);

  u128 r21 = (u128)(a->hl) * (u128)(b->lh);
  u128 r12 = (u128)(a->lh) * (u128)(b->hl);

  u128 t6, t5, t4, t3;
  u128 c5, c4;

  t3 = (r12 >> 64) + (r21 >> 64);
  /* no overflow since each term is < 2^64, thus the sum < 2*2^64 */

  /* t3 is the sum of the terms of "degree" 3 divided by 2^64 */

  c4 = addu128 (r22, t3, &t4);
  c4 += addu128 (r13, t4, &t4);
  c4 += addu128 (r31, t4, &t4);

  /* (c4:1,t4:128) is the sum of the terms of "degree" 3 and 4 */

  c5 = addu128 (r23, t4 >> 64, &t5);
  c5 += addu128 (r32, t5, &t5);

  /* (c5:1,t5:128,low(t4):64) is the sum of the terms of "degree" 3 to 5 */

  t6 = r33 + ((c5 << 64) | (t5 >> 64)) + c4;

  /* (t6:128,low(t5):64,low(t4):64) is the sum of the terms of "degree" 3-6 */

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
     The approximated sum is:
     t6 (128 bits) + low(t5) (64 bits) + low(t4) (64 bits) + low(t3) (64 bits)
     with error bounded by:
     * 1 ulp for the neglected term of "degree" 2: r11
     * 1 ulp for each of the neglected low parts of r12, r21
       thus 2 ulps in total
     This yields an error bound of 3 ulps so far.
  */

  uint64_t ex = !(t6 >> 127);

  t5 = (t5 << 64) | (t4 & (u128) 0xffffffffffffffff);
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
    /* the previous rounding error is multiplied by 2, thus < 6 ulps now */
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
    /* error < 3 ulps */
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the upper limb from b,
   and with error < 2 ulps */
static inline void
mul_qint_41 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);

  u128 r23 = (u128)(a->hl) * (u128)(b->hh);

  u128 r13 = (u128)(a->lh) * (u128)(b->hh);

  u128 r03 = (u128)(a->ll) * (u128)(b->hh);

  u128 t6, t5, t4, t3;
  u128 c5, c4;

  t3 = r03 >> 64;

  /* t3 is the term of "degree" 3 divided by 2^64 */

  c4 = addu128 (r13, t3, &t4);

  /* (c4:1,t4:128) is the sum of the terms of "degree" 3 and 4 */

  c5 = addu128 (r23, t4 >> 64, &t5);

  /* (c5:1,t5:128,low(t4):64) is the sum of the terms of "degree" 3 to 5 */

  t6 = r33 + ((c5 << 64) | (t5 >> 64)) + c4;

  /* (t6:128,low(t5):64,low(t4):64) is the sum of the terms of "degree" 3-6 */

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
     The approximated sum is:
     t6 (128 bits) + low(t5) (64 bits) + low(t4) (64 bits) + low(t3) (64 bits)
     with error bounded by 1 ulp for the neglected low part of r03.
  */

  uint64_t ex = !(t6 >> 127);

  t5 = (t5 << 64) | (t4 & (u128) 0xffffffffffffffff);
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
    /* the previous rounding error is multiplied by 2, thus < 2 ulps now */
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
    /* error < 1 ulp */
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the 3 upper limbs from a,
   and the upper limb from b, with no error (exact product) */
static inline void
mul_qint_31 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);
  u128 r23 = (u128)(a->hl) * (u128)(b->hh);
  u128 r13 = (u128)(a->lh) * (u128)(b->hh);

  u128 t6, t5, t4;
  u128 c5;

  t4 = r13;

  /* t4 is the only term of "degree" 4 */

  c5 = addu128 (r23, t4 >> 64, &t5);

  /* (c5:1,t5:128,low(t4):64) is the sum of the terms of "degree" 4 to 5 */

  t6 = r33 + ((c5 << 64) | (t5 >> 64));

  /* (t6:128,low(t5):64,low(t4):64) is the sum of the terms of "degree" 4-6 */

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
     The approximated sum is:
     t6 (128 bits) + low(t5) (64 bits) + low(t4) (64 bits)
     with no error.
  */

  uint64_t ex = !(t6 >> 127);

  t5 = (t5 << 64) | (t4 & (u128) 0xffffffffffffffff);
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
    /* the previous rounding error is multiplied by 2, thus < 2 ulps now */
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
    /* error < 1 ulp */
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the 2 upper limbs from a and b,
   with no error (exact product) */
static inline void
mul_qint_22 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);

  u128 r32 = (u128)(a->hh) * (u128)(b->hl);
  u128 r23 = (u128)(a->hl) * (u128)(b->hh);

  u128 r22 = (u128)(a->hl) * (u128)(b->hl);

  u128 t6, t5, t4;
  u128 c5;

  t4 = r22;

  c5 = addu128 (r23, t4 >> 64, &t5);
  c5 += addu128 (r32, t5, &t5);

  /* (c5:1,t5:128,low(t4):64) is the sum of the terms of "degree" 3 to 5 */

  t6 = r33 + ((c5 << 64) | (t5 >> 64));

  /* (t6:128,low(t5):64,low(t4):64) is the sum of the terms of "degree" 3-6 */

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
     The exact sum is:
     t6 (128 bits) + low(t5) (64 bits) + low(t4) (64 bits)
  */

  uint64_t ex = !(t6 >> 127);

  t5 = (t5 << 64) | (t4 & (u128) 0xffffffffffffffff);
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the 2 upper limbs from a, and the
   upper limb of b, with no error (exact product) */
static inline void
mul_qint_21 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 r33 = (u128)(a->hh) * (u128)(b->hh);
  u128 r23 = (u128)(a->hl) * (u128)(b->hh);

  u128 t6 = r33 + (r23 >> 64);

  /* No carry can happen since the full product of the significands is
     bounded by 2^512.
  */

  uint64_t ex = !(t6 >> 127);

  u128 t5 = r23 << 64;
  if (ex) { /* ex=1 */
    r->rh = (t6 << 1) | (t5 >> 127);
    r->rl = t5 << 1;
  }
  else { /* ex=0 */
    r->rh = t6;
    r->rl = t5;
  }

  r->ex = a->ex + b->ex + 1 - ex;

  r->sgn = a->sgn ^ b->sgn;
}

/* same as mul_qint, but considering only the upper limb from a and b,
   with no error (exact product) */
static inline void
mul_qint_11 (qint64_t *r, const qint64_t *a, const qint64_t *b) {
  u128 t6 = (u128)(a->hh) * (u128)(b->hh);
  uint64_t ex = !(t6 >> 127);

  /* ex can be 0 or 1 */

  r->rh = t6 << ex;
  r->rl = 0;
  r->ex = a->ex + b->ex + 1 - ex;
  r->sgn = a->sgn ^ b->sgn;
}

// Multiply an integer with a qint64_t variable, with error < 2 ulps
static inline void mul_qint_2 (qint64_t *r, int64_t b, const qint64_t *a) {
  if (!b) {
    cp_qint (r, &ZERO_Q); // exact
    return;
  }

  uint64_t c = b < 0 ? -b : b;
  if (c == 1) {
    cp_qint (r, a); // exact
    r->sgn = (b < 0) ^ a->sgn;

    return;
  }

  r->sgn = (b < 0) ^ a->sgn;
  r->ex = a->ex + 64;

  /* scale c so that 2^63 <= c < 2^64 */
  int k = __builtin_clzl (c);
  c = c << k;
  r->ex -= k;

  u128 t3 = (u128) a->hh * (u128) c;
  u128 t2 = (u128) a->hl * (u128) c;
  u128 t1 = (u128) a->lh * (u128) c;
  u128 t0 = (u128) a->ll * (u128) c;

  u128 cy;
  u128 t = t0 >> 64;

  /* t:64 is the term of degree 0 (divided by 2^64) */

  cy = addu128 (t, t1, &t1);
  /* (cy:1,t1:128) is the sum of the terms of degree 0 and 1 */

  t = ((u128) cy << 64) | (t1 >> 64);
  cy = addu128 (t, t2, &t2);
  /* (cy:1,t2:128,low(t1):64) is the sum of the terms of degree 0 to 2 */

  t3 += (((u128) cy << 64) | (t2 >> 64));
  /* (t3,low(t2):64,low(t1):64) is the sum of the terms of degree 0 to 3 */

  uint32_t ex = __builtin_clzl (t3 >> 64);

  t2 = (t2 << 64) | (t1 & (u128) 0xffffffffffffffff);

  /* ex is 0 or 1 because a and c are normalized (2^63 <= a->hh, c < 2^64) */

  /* we only ignore the low part of t0 which contributes less than 1 ulp */

  if (ex)
    {
      r->rh = (t3 << 1) | (t2 >> 127);
      r->rl = t2 << 1;
      /* the error is scaled by 2, thus less than 2 ulps */
      r->ex --;
    }
  else
    {
      r->rh = t3;
      r->rl = t2;
      /* error less than 1 ulp in that case */
    }
}

#if 0
// Prints a qint64_t value for debugging purposes
static inline void print_qint(const qint64_t *a) {
  printf("{.hh=0x%lx, .hl=0x%lx, .lh=0x%lx, .ll=0x%lx, .ex=%ld, .sgn=0x%lx}\n",
         a->hh, a->hl, a->lh, a->ll, a->ex, a->sgn);
}
#endif

#endif
