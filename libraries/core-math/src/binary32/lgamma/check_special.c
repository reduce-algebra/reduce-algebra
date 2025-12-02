/* Generate special cases for lgammaf testing.

Copyright (c) 2022-2024 Stéphane Glondu and Paul Zimmermann, Inria.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fenv.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <mpfr.h>

float cr_lgammaf (float);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd = 0;

int verbose = 0;

static void
check_spurious_invalid (void)
{
  float x, y;
  int flag;
  x = 0x1p31f;
  feclearexcept (FE_INVALID);
  y = cr_lgammaf (x);
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Spurious invalid exception for x=%a (y=%a)\n", x, y);
    exit (1);
  }
  x = 0x1.fffffep+127f;
  feclearexcept (FE_INVALID);
  y = cr_lgammaf (x);
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Spurious invalid exception for x=%a (y=%a)\n", x, y);
    exit (1);
  }
  x = -0x1.000002p+31f;
  feclearexcept (FE_INVALID);
  y = cr_lgammaf (x);
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Spurious invalid exception for x=%a (y=%a)\n", x, y);
    exit (1);
  }
  x = -0x1.fffffep+127f;
  feclearexcept (FE_INVALID);
  y = cr_lgammaf (x);
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Spurious invalid exception for x=%a (y=%a)\n", x, y);
    exit (1);
  }
}

// return +1 when gamma(x) > 0, -1 when gamma(x) < 0 and 0 when undefined
static int
expected_signgam (float x)
{
  if (x > 0)
    return +1;
  if (x == 0)
    return (signbit (x)) ? -1 : +1;
  float y = floorf (x);
  if (x == y)
    return 0; // x is integer, gamma(x) tends to +Inf and -Inf on both sides
  // gamma(x) is negative in (-2k-1,-2k), positive in (-2k,-2k+1)
  // return -1 if y is odd, +1 if y is even
  // since y != x, necessarily |x| < 2^23, thus we can cast y to uint32_t
  uint32_t k = y;
  return (k & 1) ? -1 : +1;
}

typedef union { uint32_t n; float f; } union_t;

static inline float
asfloat (uint32_t n)
{
  union_t u = {.n = n};
  return u.f;
}

static inline uint32_t
asuint (float f)
{
  union_t u = {.f = f};
  return u.n;
}

static void
doit (uint32_t n)
{
  float x, y;
  x = asfloat (n);
  signgam = 0;
  y = cr_lgammaf (x);
  int s = expected_signgam (x);

  // check signgam is correctly set
  if (s != 0 && signgam == 0)
  {
    printf ("Error, signgam is not set for x=%a (y=%a)\n", x, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // check signgam is correctly set
  if (s != 0 && s != signgam)
  {
    printf ("Error, signgam is wrong for x=%a (y=%a)\n", x, y);
    printf ("expected %d, got %d\n", s, signgam);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

static void
check_signgam (void)
{
  uint32_t nmin = asuint (0x0p0f), nmax = asuint (0x1.fffffep+127f);
  // this loop should not be parallelized, since signgam is a global variable
  for (uint32_t n = nmin; n <= nmax; n++)
  {
    doit (n);
    doit (n | 0x80000000);
  }
}

int
main (int argc, char *argv[])
{
  while (argc >= 2)
    {
      if (strcmp (argv[1], "--rndn") == 0)
        {
          rnd = 0;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndz") == 0)
        {
          rnd = 1;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndu") == 0)
        {
          rnd = 2;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--rndd") == 0)
        {
          rnd = 3;
          argc --;
          argv ++;
        }
      else if (strcmp (argv[1], "--verbose") == 0)
        {
          verbose = 1;
          argc --;
          argv ++;
        }
      else
        {
          fprintf (stderr, "Error, unknown option %s\n", argv[1]);
          exit (1);
        }
    }

  check_spurious_invalid ();

  check_signgam ();

  return 0;
}
