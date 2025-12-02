/* Correctly-rounded Euclidean distance function (hypot) for binary128 values.

Copyright (c) 2025 Alexei Sibidanov <sibid@uvic.ca>

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

#include <stdio.h>
#include <mpfr.h>
#include "fenv_mpfr.h"
#include <stdint.h>

typedef unsigned __int128 u128;
typedef uint64_t u64;
typedef union {u128 a; u64 b[2]; __float128 f;} b128u128_u;

__float128 ref_hypotq(__float128 x, __float128 y){
  /* since MPFR does not distinguish between quiet/signaling NaN,
     we have to deal with them separately to apply the IEEE rules */
  b128u128_u xi = {.f = x}, yi = {.f = y};
  if((xi.a<<1)<((u128)0xffffull<<112) && (xi.a<<1)>((u128)0x7fffull<<113)){ // x = sNAN
    xi.b[1] |= 1ull<<47;
    return xi.f; // return qNAN
  }
  if((yi.a<<1)<((u128)0xffffull<<112) && (yi.a<<1)>((u128)0x7fffull<<113)){ // y = sNAN
    yi.b[1] |= 1ull<<47;
    return yi.f; // return qNAN
  }
  if((xi.a<<1) == 0){ // x = +/-0
    yi.b[1] = (yi.b[1]<<1)>>1;
    return yi.f;
  }
  if((yi.a<<1) == 0){ // y = +/-0
    xi.b[1] = (xi.b[1]<<1)>>1;
    return xi.f;
  }
  mpfr_t xm, ym;
  mpfr_init2 (xm, 113);
  mpfr_init2 (ym, 113);
  mpfr_set_float128 (xm, x, MPFR_RNDN);
  mpfr_set_float128 (ym, y, MPFR_RNDN);
  int inex = mpfr_hypot (xm, xm, ym, rnd2[rnd]);
  mpfr_subnormalize (xm, inex, rnd2[rnd]);
  __float128 ret = mpfr_get_float128 (xm, MPFR_RNDN);
  mpfr_clear (xm);
  mpfr_clear (ym);
  return ret;
}
