/* Correctly-rounded inverse hyperbolic cosine function for the binary64 format

Copyright (c) 2023 Alexei Sibidanov

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

double ref_acosh(double x){
  b64u64_u ix = {.f = x};
  if(__builtin_expect(ix.u<=0x3ff0000000000000ull, 0)){
    if(ix.u==0x3ff0000000000000ull) return 0;
    return __builtin_nan("x<1");
  }
  if(__builtin_expect(ix.u>=0x7ff0000000000000ull, 0)){
    u64 aix = ix.u<<1;
    if(ix.u==0x7ff0000000000000ull || aix>((u64)0x7ff<<53)) return x; // +inf or nan
    return __builtin_nan("x<1");
  }

  mpfr_t y;
  mpfr_init2(y, 53);
  mpfr_set_d(y, x, MPFR_RNDN);
  mpfr_acosh(y, y, rnd2[rnd]);
  double ret = mpfr_get_d(y, MPFR_RNDN);
  mpfr_clear(y);
  return ret;
}
