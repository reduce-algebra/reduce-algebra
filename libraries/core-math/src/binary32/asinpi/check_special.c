/* Generate special cases for asinpif testing.

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

float cr_asinpif (float);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd = 0;

int verbose = 0;

static void
check_near_underflow (void)
{
  float Y[] = {0x1.921fb6p-125f, 0.0f};
  /* for entries in Y[], asinpi(x) should not underflow */
  for (int i = 0; i < 2; i++) {
    float x = Y[i];
    feclearexcept (FE_UNDERFLOW);
    errno = 0;
    float y = cr_asinpif (x);
    int inex = fetestexcept (FE_UNDERFLOW);
    if (inex)
    {
      fprintf (stderr, "Unexpected underflow exception for x=%a [y=%a]\n", x, y);
      exit (1);
    }
#ifdef CORE_MATH_SUPPORT_ERRNO
    // there should be no underflow
    if (errno)
    {
      fprintf (stderr, "Unexpected errno=%d for x=%a [y=%a]\n", errno, x, y);
      exit (1);
    }
#endif
    // also try -x
    x = -x;
    feclearexcept (FE_UNDERFLOW);
    errno = 0;
    y = cr_asinpif (x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex)
    {
      fprintf (stderr, "Unexpected underflow exception for x=%a [y=%a]\n", x, y);
      exit (1);
    }
#ifdef CORE_MATH_SUPPORT_ERRNO
    // there should be no underflow
    if (errno)
    {
      fprintf (stderr, "Unexpected errno=%d for x=%a [y=%a]\n", errno, x, y);
      exit (1);
    }
#endif
  }
  float X[] = {0x1.921fb4p-126f, 0x1.921fb2p-126f, 0x1p-126f,
               0x1p-147f, 0x1p-148f, 0x1p-149f};
  for (int i = 0; i < 6; i++) {
    float x = X[i];
    feclearexcept (FE_UNDERFLOW);
    errno = 0;
    float y = cr_asinpif (x);
    int inex = fetestexcept (FE_UNDERFLOW);
    if (!inex)
    {
      fprintf (stderr, "Missing underflow exception for x=%a [y=%a]\n",
               x, y);
      exit (1);
    }
#ifdef CORE_MATH_SUPPORT_ERRNO
    // there should be underflow
    if (errno != ERANGE)
    {
      fprintf (stderr, "Expected errno=ERANGE, got %d for x=%a [y=%a]\n", errno, x, y);
      exit (1);
    }
#endif
    // also test -x
    x = -X[i];
    feclearexcept (FE_UNDERFLOW);
    errno = 0;
    y = cr_asinpif (x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (!inex)
    {
      fprintf (stderr, "Missing underflow exception for x=%a [y=%a]\n",
               x, y);
      exit (1);
    }
#ifdef CORE_MATH_SUPPORT_ERRNO
    // there should be underflow
    if (errno != ERANGE)
    {
      fprintf (stderr, "Expected errno=ERANGE, got %d for x=%a [y=%a]\n", errno, x, y);
      exit (1);
    }
#endif
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

  check_near_underflow ();

  return 0;
}
