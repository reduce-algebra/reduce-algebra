/* Generate special cases for atan2pif testing.

Copyright (c) 2022 Stéphane Glondu and Paul Zimmermann, Inria.

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
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <mpfr.h>

float cr_atan2pif (float, float);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd = 0;

int verbose = 0;

/* reference code using MPFR */
static float
ref_atan2pi (float y, float x)
{
  mpfr_t xi, yi;
  mpfr_inits2 (24, xi, yi, NULL);
  mpfr_set_flt (xi, x, MPFR_RNDN);
  mpfr_set_flt (yi, y, MPFR_RNDN);
  int inex = mpfr_atan2pi (xi, yi, xi, rnd2[rnd]);
  mpfr_subnormalize (xi, inex, rnd2[rnd]);
  float ret = mpfr_get_flt (xi, MPFR_RNDN);
  mpfr_clears (xi, yi, NULL);
  return ret;
}

typedef union { uint32_t n; float x; } union_t;

static float
asfloat (uint32_t n)
{
  union_t u;
  u.n = n;
  return u.x;
}

static void
check (float y, float x)
{
  float z, t;
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  t = ref_atan2pi (y, x);
#ifdef CORE_MATH_CHECK_INEXACT
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  feclearexcept (FE_INEXACT);
  z = cr_atan2pif (y, x);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
#endif
  if ((isnan (t) && !isnan(z)) || (!isnan (t) && isnan(z)) ||
      (!isnan (t) && !isnan(z) && z != t))
  {
    printf ("FAIL y=%a x=%a ref=%a z=%a\n", y, x, t, z);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x=%a y=%a\n", x, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x=%a y=%a\n", x, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
#endif
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 100000000ul // total number of tests
#endif

static void
check_random (int i, int nthreads)
{
  int64_t l;
  float x, y;
  ref_init ();
  fesetround (rnd1[rnd]);
  srand (i);
  for (unsigned int n = 0; n < CORE_MATH_TESTS; n += nthreads)
  {
    l = rand () | (int64_t) rand () << 31;
    y = asfloat (l);
    l = rand () | (int64_t) rand () << 31;
    x = asfloat (l);
    check (y, x);
    check (y, -x);
    check (-y, x);
    check (-y, -x);
  }
}

static void
check_spurious_underflow (void)
{
  float T[6][2] = {
    {0x1p+0f, 0xf.fffffp+124f},
    {0x4p-128f, 0xf.fffffp+124f},
    {0x8p-152f, 0x1p+0f},
    {0x8p-152f, 0xf.fffffp+124f},
    {0xf.fffffp+124f, 0x4p-128f},
    {0xf.fffffp+124f, 0x8p-152f},
  };
  for (int i = 0; i < 6; i++)
  {
    float y = T[i][0], x = T[i][1];
    feclearexcept (FE_UNDERFLOW);
    float z = cr_atan2pif (y, x);
    int inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) > 0x1p-126f)
    {
      fprintf (stderr, "Unexpected underflow exception for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test -y,x
    y = -y;
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2pif (y, x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) > 0x1p-126f)
    {
      fprintf (stderr, "Unexpected underflow exception for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test -y,-x
    x = -x;
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2pif (y, x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) > 0x1p-126f)
    {
      fprintf (stderr, "Unexpected underflow exception for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test y,-x
    y = -y;
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2pif (y, x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) > 0x1p-126f)
    {
      fprintf (stderr, "Unexpected underflow exception for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
  }
}

#ifdef CORE_MATH_SUPPORT_ERRNO
static void
check_errno (void)
{
  float T[2][2] = {
    {0x1p-149f, 0x1.fffffep+127f},
    {0x1.8p-148f, 0x1.20f90cp+1f},
  };
  for (int i = 0; i < 2; i++)
  {
    float y = T[i][0], x = T[i][1];
    errno = 0;
    float z = cr_atan2pif (y, x);
    if (fabsf (z) <= 0x1p-149 && errno == 0)
    {
      fprintf (stderr, "Missing errno=ERANGE for for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test -y,x
    y = -y;
    errno = 0;
    z = cr_atan2pif (y, x);
    if (fabsf (z) <= 0x1p-149 && errno == 0)
    {
      fprintf (stderr, "Missing errno=ERANGE for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test -y,-x
    x = -x;
    errno = 0;
    z = cr_atan2pif (y, x);
    if (fabsf (z) <= 0x1p-149 && errno == 0)
    {
      fprintf (stderr, "Missing errno=ERANGE for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test y,-x
    y = -y;
    errno = 0;
    z = cr_atan2pif (y, x);
    if (fabsf (z) <= 0x1p-149 && errno == 0)
    {
      fprintf (stderr, "Missing errno=ERANGE for y,x=%a,%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
  }
}
#endif

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

#ifdef CORE_MATH_SUPPORT_ERRNO
  printf ("Checking errno\n");
  check_errno ();
#endif

  printf ("Checking spurious underflow\n");
  check_spurious_underflow ();

  printf ("Checking random inputs\n");
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads ();
#endif
  /* check random values */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_random (getpid () + i, nthreads);
  return 0;
}
