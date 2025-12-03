/* Correctly rounded powl function for binary80 values.

Copyright (c) 2024 Sélène Corbineau and Paul Zimmermann

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

#include <mpfr.h>
#include "fenv_mpfr.h"
#include <stdint.h>


typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

inline
static int is_nan(long double x) {
  b80u80_t v = {.f = x};
  return ((v.e&0x7fff) == 0x7fff && (v.m != (1ul << 63)));
}

inline
static int issnan(long double x) {
	b80u80_t v = {.f = x};
	return is_nan(x) && (!((v.m>>62)&1));
}

/* reference code using MPFR */
long double ref_powl(long double x, long double y) {
	if(issnan(x) || issnan(y)) {
		b80u80_t v;
		v.m = 0x8000000000000001ul;
		v.e = 0x7fff;
		return v.f;
	}
	mpfr_t z, _x, _y;
	mpfr_exp_t emin = mpfr_get_emin ();
  mpfr_set_emin (-16444);
  
	mpfr_inits2(64, z, _x, _y, NULL);
  mpfr_set_ld(_x, x, MPFR_RNDN);
  mpfr_set_ld(_y, y, MPFR_RNDN);
  int inex = mpfr_pow(z, _x, _y, rnd2[rnd]);
  mpfr_subnormalize(z, inex, rnd2[rnd]);
  long double ret = mpfr_get_ld(z, rnd2[rnd]);

  mpfr_clears(z, _x, _y, NULL);
  mpfr_set_emin (emin);
  return ret;
}
