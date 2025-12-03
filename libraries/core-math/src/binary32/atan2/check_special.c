/* Generate special cases for atan2f testing.

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
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <mpfr.h>

float cr_atan2f (float, float);
extern int ref_fesetround (int);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd = 0;

int verbose = 0;

/* reference code using MPFR */
static float
ref_atan2 (float y, float x)
{
  mpfr_t xi, yi;
  mpfr_inits2 (24, xi, yi, NULL);
  mpfr_set_flt (xi, x, MPFR_RNDN);
  mpfr_set_flt (yi, y, MPFR_RNDN);
  int inex = mpfr_atan2 (xi, yi, xi, rnd2[rnd]);
  mpfr_subnormalize (xi, inex, rnd2[rnd]);
  float ret = mpfr_get_flt (xi, MPFR_RNDN);
  mpfr_clears (xi, yi, NULL);
  return ret;
}

typedef union { uint32_t n; float x; } union_t;

static float
asfloat (uint32_t n)
{
  union_t u = {.n = n};
  return u.x;
}

static uint32_t
asuint (float x)
{
  union_t u = {.x = x};
  return u.n;
}

static void
check (float y, float x)
{
  float z, t;
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  t = ref_atan2 (y, x);
#ifdef CORE_MATH_CHECK_INEXACT
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  feclearexcept (FE_INEXACT);
  z = cr_atan2f (y, x);
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

static void
check_all (float y, float x)
{
  check (y, x);
  check (y, -x);
  check (-y, x);
  check (-y, -x);
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000ul // total number of tests
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
    check_all (y, x);
  }
}

static void
check_spurious_underflow (void)
{
  float T[][2] = {{0x1p+0f, 0xf.fffffp+124f},
                  {0x4p-128f, 0xf.fffffp+124f},
                  {0x8p-152f, 0x1p+0f},
                  {0x8p-152f, 0xf.fffffp+124f},
                  {0xf.fffffp+124f, 0x4p-128f},
                  {0xf.fffffp+124f, 0x8p-152f}};
  for (int i = 0; i < 6; i++)
  {
    float y = T[i][0], x = T[i][1];
    feclearexcept (FE_UNDERFLOW);
    float z = cr_atan2f (y, x);
    int inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) >= 0x1p-122f)
    {
      fprintf (stderr, "Unexpected underflow exception for y=%a x=%a [z=%a]\n",
               y, x, z);
      exit (1);
    }
    // also test -y, x
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2f (-y, x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) >= 0x1p-122f)
    {
      fprintf (stderr, "Unexpected underflow exception for y=%a x=%a [z=%a]\n",
               -y, x, z);
      exit (1);
    }
    // also test y, -x
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2f (y, -x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) >= 0x1p-122f)
    {
      fprintf (stderr, "Unexpected underflow exception for y=%a x=%a [z=%a]\n",
               y, -x, z);
      exit (1);
    }
    // also test -y, -x
    feclearexcept (FE_UNDERFLOW);
    z = cr_atan2f (-y, -x);
    inex = fetestexcept (FE_UNDERFLOW);
    if (inex && fabsf (z) >= 0x1p-122f)
    {
      fprintf (stderr, "Unexpected underflow exception for y=%a x=%a [z=%a]\n",
               -y, -x, z);
      exit (1);
    }
  }
}

// check when y/x is near underflow threshold 2^-126
static void
check_near_underflow (void)
{
  /* y/x near 2^-126 implies y near 2^-126*x
     this requires x >= 2^-23 */
  uint32_t umin = asuint (0x1p-23f);
#define MAXF 0x1.fffffep+127f
  uint32_t umax = asuint (MAXF);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint32_t u = umin; u <= umax; u++) {
    ref_init ();
    ref_fesetround (rnd);
    fesetround (rnd1[rnd]);
    float x = asfloat (u);
    float y = 0x1p-126f * x;
    check (y, x);
    check (nextafterf (y, -MAXF), x);
    check (nextafterf (y, MAXF), x);
  }
}

/* check y,x near power of 2 */
static void
check_near_pow2 (void)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  for (int ex = -149; ex <= 128; ex++)
  {
    float x = ldexpf (0x1.fffffep-1f, ex);
    float xl = nextafterf (x, 0.0);
    float xh = nextafterf (x, 0x1.fffffep+127f);
    for (int ey = -149; ey <= 128; ey++)
    {
      float y = ldexpf (0x1.fffffep-1f, ey);
      float yl = nextafterf (y, 0.0);
      float yh = nextafterf (y, 0x1.fffffep+127f);
      check_all (y, x);
      check_all (y, xl);
      check_all (y, xh);
      check_all (yl, x);
      check_all (yl, xl);
      check_all (yl, xh);
      check_all (yh, x);
      check_all (yh, xl);
      check_all (yh, xh);
    }
  }
}

#ifdef CORE_MATH_SUPPORT_ERRNO
static void
check_errno (void)
{
  float x, y, z;
  x = 0x1.fffffep+127f;
  y = 0x1p-149f;
  errno = 0;
  z = cr_atan2f (y, x);
  if (errno != ERANGE)
  {
    printf ("Missing errno=ERANGE for y=%a x=%a (z=%a)\n", y, x, z);
    exit (1);
  }
  x = 0x1.fffffep+127f;
  y = -0x1p-149f;
  errno = 0;
  z = cr_atan2f (y, x);
  if (errno != ERANGE)
  {
    printf ("Missing errno=ERANGE for y=%a x=%a (z=%a)\n", y, x, z);
    exit (1);
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
  check_errno ();
#endif

  printf ("Checking near underflow\n");
  check_near_underflow ();

  printf ("Checking spurious underflow\n");
  check_spurious_underflow ();

  printf ("Checking y,x near powers of 2\n");
  check_near_pow2 ();

  printf ("Checking random values\n");
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
