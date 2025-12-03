/* Correctly-rounded mpfr-based sincos of binary64 value.

Copyright (c) 2023-2024 Paul Zimmermann

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

void ref_sincos (double x, double *s, double *c){
  mpfr_t y, z;
  mpfr_init2 (y, 53);
  mpfr_init2 (z, 53);
  mpfr_set_d (y, x, MPFR_RNDN);
  int inex = mpfr_sin_cos (y, z, y, rnd2[rnd]);
  int inex_sin = inex & 3;
  int inex_cos = inex >> 2;
  inex_sin = (inex_sin == 0) ? 0 : (inex_sin == 1) ? 1 : -1;
  inex_cos = (inex_cos == 0) ? 0 : (inex_cos == 1) ? 1 : -1;
  mpfr_subnormalize (y, inex_sin, rnd2[rnd]);
  mpfr_subnormalize (z, inex_cos, rnd2[rnd]);
  *s = mpfr_get_d (y, MPFR_RNDN);
  *c = mpfr_get_d (z, MPFR_RNDN);
  mpfr_clear (y);
  mpfr_clear (z);
}
