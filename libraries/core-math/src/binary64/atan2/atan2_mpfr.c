/* Correctly-rounded atan2 of two binary64 values.

Copyright (c) 2023 Paul Zimmermann

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

/* reference code using MPFR */
double ref_atan2 (double y, double x) {
  mpfr_t z, _x, _y;
  mpfr_inits2(53, z, _x, _y, NULL);
  mpfr_set_d(_x, x, MPFR_RNDN);
  mpfr_set_d(_y, y, MPFR_RNDN);
  int inex = mpfr_atan2 (z, _y, _x, rnd2[rnd]);
  mpfr_subnormalize(z, inex, rnd2[rnd]);
  double ret = mpfr_get_d(z, rnd2[rnd]);
  mpfr_clears(z, _x, _y, NULL);
  return ret;
}
