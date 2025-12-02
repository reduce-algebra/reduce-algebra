/* Correctly-rounded reciprocal square root of binary128 value.

Copyright (c) 2025 Alexei Sibidanov.

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

#define MPFR_WANT_FLOAT128

// clang and the Intel compiler do not support yet _Float128
#if defined(__clang__) || defined(__INTEL_CLANG_COMPILER)
#define mpfr_float128 __float128
#endif

#include <mpfr.h>
#include "fenv_mpfr.h"

typedef union {
  unsigned __int128 a;
  __float128 f;
} b128u128_u;

__float128 ref_rsqrtq(__float128 x){
  b128u128_u u = {.f = x};

  /* mpfr_rec_sqrt differs from IEEE 754-2019: IEEE 754-2019 says that
     rsqrt(-0) should give -Inf, whereas mpfr_rec_sqrt(-0) gives +Inf */
  if(!(u.a<<1)){ // case x = 0
    if(u.a>>127) return -__builtin_inff128(); // x=-0
    return __builtin_inff128(); // x=+0
  }

  if((u.a<<1)>(unsigned __int128)0x7fff<<113){ // sNaN/qNaN case
    u.a |= (unsigned __int128)1<<111; // set to qNaN
    return u.f;
  }

  mpfr_t y;
  mpfr_init2 (y, 113);
  mpfr_set_float128 (y, x, MPFR_RNDN);
  mpfr_rec_sqrt (y, y, rnd2[rnd]);
  __float128 ret = mpfr_get_float128 (y, MPFR_RNDN);
  mpfr_clear (y);
  return ret;
}
