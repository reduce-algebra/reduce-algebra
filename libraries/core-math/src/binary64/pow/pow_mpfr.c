/* Correctly-rounded power of two binary64 values.

Copyright (c) 2022, 2023 CERN and Inria
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

#include <stdint.h>
#include <mpfr.h>
#include "fenv_mpfr.h"
#include <math.h>

typedef union { double f; uint64_t u; } f64_u;

// return non-zero iff x is a signaling NaN
static inline int is_snan(double x) {
  f64_u v = {.f = x};
  return isnan (x) && !(v.u & (1ull << 51));
}

/* reference code using MPFR */
double ref_pow(double x, double y) {
  // since MPFR does not distinguish between qNaN and sNaN, we have to
  // deal with signaling NaNs separately
  if (is_snan (x) || is_snan (y))
    return x + y;

  mpfr_t z, _x, _y;
  int underflow = mpfr_flags_test (MPFR_FLAGS_UNDERFLOW);
  mpfr_inits2(53, z, _x, _y, NULL);
  mpfr_set_d(_x, x, MPFR_RNDN);
  mpfr_set_d(_y, y, MPFR_RNDN);
  int inex = mpfr_pow(z, _x, _y, rnd2[rnd]);
  inex = mpfr_subnormalize(z, inex, rnd2[rnd]);
  /* Workaround for bug in mpfr_subnormalize for MPFR <= 4.2.1: the underflow
     flag is set by mpfr_subnormalize() even for exact results. */
  if (inex == 0 && !underflow)
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
  double ret = mpfr_get_d(z, rnd2[rnd]);
  mpfr_clears(z, _x, _y, NULL);
  return ret;
}
