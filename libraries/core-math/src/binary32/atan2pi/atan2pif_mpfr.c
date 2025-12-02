/* Correctly-rounded half revolution arctangent function of two binary32 values.

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

#define FTYPE float
#define FSET flt
#define FBIT 24
#define JOIN2(x,y) x ## y
#define JOIN(x,y) JOIN2(x,y)
/* reference code using MPFR */
FTYPE
ref_atan2pi (FTYPE y, FTYPE x)
{
  mpfr_t xi, yi;
  mpfr_inits2 (FBIT, xi, yi, NULL);
  JOIN(mpfr_set_, FSET) (xi, x, MPFR_RNDN);
  JOIN(mpfr_set_, FSET) (yi, y, MPFR_RNDN);
  int inex = mpfr_atan2pi (xi, yi, xi, rnd2[rnd]);
  mpfr_subnormalize (xi, inex, rnd2[rnd]);
  FTYPE ret = JOIN(mpfr_get_, FSET) (xi, MPFR_RNDN);
  mpfr_clears (xi, yi, NULL);
  return ret;
}
