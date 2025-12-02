/* Correctly-rounded Euclidean distance function (hypot) for bfloat16 value.

Copyright (c) 2025 Maxence Ponsardin and Paul Zimmermann

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

typedef union {__bf16 f; int16_t u;} b16u16;

/* code from MPFR */

__bf16
ref_hypot (__bf16 x, __bf16 y)
{
  mpfr_t xm, ym, zm;

  b16u16 xi = {.f = x}, yi = {.f = y};
  if((xi.u & 0x7fff)<0x7fc0 && (xi.u & 0x7fff)>0x7f80) // x = sNAN
    return x + y; // will return qNaN
  if((yi.u & 0x7fff)<0x7fc0 && (yi.u & 0x7fff)>0x7f80) // y = sNAN
    return x + y; // will return qNaN
  if((xi.u & 0x7fff) == 0){ // x = +/-0
    yi.u = yi.u & 0x7fff; // take the absolute value
    return yi.f;
  }
  if((yi.u & 0x7fff) == 0){ // y = +/-0
    xi.u = xi.u & 0x7fff; // take the absolute value
    return xi.f;
  }

  mpfr_init2 (xm, 8);
  mpfr_init2 (ym, 8);
  mpfr_init2 (zm, 8);
  mpfr_set_flt (xm, (float) x, MPFR_RNDN);
  mpfr_set_flt (ym, (float) y, MPFR_RNDN);
  int inex = mpfr_hypot (zm, xm, ym, rnd2[rnd]);
  mpfr_subnormalize (zm, inex, rnd2[rnd]);
  __bf16 ret = (__bf16) mpfr_get_flt (zm, MPFR_RNDN);
  mpfr_clear (xm);
  mpfr_clear (ym);
  mpfr_clear (zm);
  return ret;
}
