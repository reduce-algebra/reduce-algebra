/* Correctly-rounded compound function for bfloat16 value.

Copyright (c) 2025 Paul Zimmermann

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

typedef union {__bf16 f; uint16_t u; } b16u16_u;

// return non-zero iff x is a signaling NaN
static inline int is_snan(__bf16 x) {
  b16u16_u v = {.f = x};
  int e = v.u >> 7;
  return (e == 0xff || e == 0x1ff) && (v.u & 0x7f) != 0;

}

/* reference code using MPFR */
__bf16
ref_compound (__bf16 x, __bf16 y)
{
  // since MPFR does not distinguish between qNaN and sNaN, we have to
  // deal with signaling NaNs separately
  if (is_snan (x) || is_snan (y))
    return x + y;

  mpfr_t xm, ym, zm;
  mpfr_init2 (xm, 8);
  mpfr_init2 (ym, 8);
  mpfr_init2 (zm, 8);
  mpfr_set_flt (xm, x, MPFR_RNDN);
  mpfr_set_flt (ym, y, MPFR_RNDN);
  int inex = mpfr_compound (zm, xm, ym, rnd2[rnd]);
  mpfr_subnormalize (zm, inex, rnd2[rnd]);
  __bf16 ret = mpfr_get_flt (zm, MPFR_RNDN);
  mpfr_clear (xm);
  mpfr_clear (ym);
  mpfr_clear (zm);
  return ret;
}

