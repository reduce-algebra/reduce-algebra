#pragma once

// extracts e and m such that |x| = 2^e*m with m odd.
// Assumes x!=0
static inline
void q_extract(int64_t* e, uint64_t* m, long double x) {
	const b80u80_t cvt_x = {.f = x};
	int shift = __builtin_ctzl(cvt_x.m);
	int exponent = (cvt_x.e&0x7fff) - 16383;	
	if(exponent == -16383) {exponent++;}

	*e = exponent - (63 - shift);
	*m = cvt_x.m >> shift;
}

// round z to the nearest 65-bit integer (ties to away)
static inline
void q_extract65(int64_t* e, const qint64_t* z) {
	uint64_t l = (z->hl >> 62) | (z->hh << 2), h = z->hh >> 62;
	// now h has 2 bits and l has 64 bits, thus 66 bits in total
	if(l & 1) {l+=1; if(l == 0) {h++;}}

	if(l == 0) { // Bit 1 of h has weight z->ex
		*e = z->ex + __builtin_ctzll(h) - 1;
	} else {
		*e = z->ex + __builtin_ctzll(l) - 65;
	}
}

/* return true iff x^y is exact or midpoint (with unlimited exponent range),
   using an approximation z with relative error < 2^-234.862.

   This is adapted from Lefèvre's algorithm in [2].
*/
static
bool check_rb(long double x, long double y, const qint64_t* z) {
	uint64_t m;
	int64_t E;
	q_extract(&E, &m, x); // |x| = m*2^E

	uint64_t n;
	int64_t F;
	q_extract(&F, &n, y); // |y| = n*2^F

	if (m == 1) { // This is exact iff E*n*2^F is in Z, that is 2^-F | E
		if(F >= 0) return true;
		if(F <= -31) return false;
		return !(E & (((int64_t)1 << (-F)) - 1)); // Lower |F| bits of E must be 0 if exact.
	}

	/* x is not a power of 2 */	
	if(y < 0) return false;
	/* Since m is odd >= 3, the numerator of x^y contains some non-zero
	   power of m, thus cannot be a power of 2 */

	if(F > 5 || n > 41 || (F >= 0 && (n * (1 << F) > 41)))
          return false; // y>41
	/* If F > 5, then m^(2^F) >= 3^(2^6) which does not fit in 65 bits.
	   If n > 41, then m^n >= 3^42 which does not fit in 65 bits.
	   If F >= 0 and n*2^F > 41, then y is integer and m^y >= 3^42 too.
	*/

	if (F < -5) return false;
	/* We would have to extract at least 6 times an exact square root
	   from m, which is not possible for m < 2^64. */

	if(F < 0) {
		/* Since |x| = m*2^E with m odd, we have to be able to extract |F|
		   times an exact square root from m, and |F| times an exact square
		   root from 2^E. The second condition requires 2^|F| divides E. */
		if(E & (((int64_t)1 << (-F)) - 1)) return false;
		// 2^|F| does not divide E
		int64_t off = n*(E >> (-F)); // Cannot overflow given the ranges.
		int64_t G;
		q_extract65(&G, z);
		// Finds G such that round65(z) = 2^G*k for some odd k
		if(G != off) return false;
		// The test 2^(G - E*y)k in 2Z + 1 in detectRoundingBoundaryCase [2] becomes
		// G == E*y.
	}

	return true;
}

/* Given a not subnormalized approximating a rounding boundary
modifies a in place so that it exactly represents the rounding boundary.
*/ 
static inline
void exactify(qint64_t* a) {
	if((a->hl>>62) & 1) {
		uint64_t oldhl = a->hl;
		a->hl += (1ul << 63);
		if(a->hl < oldhl) {
			a->hh++;
		}

		if(__builtin_expect(!a->hh, 0)) {
			a->hh = 1ul << 63;
			a->ex++;
		}
	}
	a->hl &= 1ul<<63; a->lh = a->ll = 0;
}
