/* Correctly-rounded Euclidean distance function (hypot) for binary64 values.

Copyright (c) 2022 Alexei Sibidanov.

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
SOFTWARE. */

#include <mpfr.h>
#include "fenv_mpfr.h"
#include <stdint.h>

typedef uint64_t u64;
typedef union {double f; u64 u;} b64u64_u;

double ref_hypot (double x, double y){
  /* since MPFR does not distinguish between quiet/signaling NaN,
     we have to deal with them separately to apply the IEEE rules */
  b64u64_u xi = {.f = x}, yi = {.f = y};
  if((xi.u<<1)<(0xfffull<<52) && (xi.u<<1)>(0x7ffull<<53)) // x = sNAN
    return x + y; // will return qNAN
  if((yi.u<<1)<(0xfffull<<52) && (yi.u<<1)>(0x7ffull<<53)) // y = sNAN
    return x + y; // will return qNAN
  if((xi.u<<1) == 0){ // x = +/-0
    yi.u = (yi.u<<1)>>1;
    return yi.f;
  }
  if((yi.u<<1) == 0){ // y = +/-0
    xi.u = (xi.u<<1)>>1;
    return xi.f;
  }

  mpfr_t xm, ym, zm;
  mpfr_set_emin (-1073);
  mpfr_init2 (xm, 53);
  mpfr_init2 (ym, 53);
  mpfr_init2 (zm, 53);
  mpfr_set_d (xm, x, MPFR_RNDN);
  mpfr_set_d (ym, y, MPFR_RNDN);
  int inex = mpfr_hypot (zm, xm, ym, rnd2[rnd]);
  mpfr_subnormalize (zm, inex, rnd2[rnd]);
  double ret = mpfr_get_d (zm, MPFR_RNDN);
  mpfr_clear (xm);
  mpfr_clear (ym);
  mpfr_clear (zm);
  return ret;
}
