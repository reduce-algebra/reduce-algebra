/* Generate special cases for atan2 testing.

Copyright (c) 2022-2024 Stéphane Glondu, Paul Zimmermann, Inria.

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
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <unistd.h>
#include <math.h>

void doloop (int, int);
extern double cr_atan2 (double, double);
extern int ref_fesetround (int);
extern void ref_init (void);
extern mpfr_rnd_t rnd2[];
extern double ref_atan2 (double, double);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd;
int verbose = 0;

typedef union {double f; uint64_t u;} b64u64_u;

static double
get_random (struct drand48_data *buffer)
{
  b64u64_u v;
  int64_t l;
  lrand48_r (buffer, &l);
  v.u = l;
  lrand48_r (buffer, &l);
  v.u |= (uint64_t) l << 31;
  lrand48_r (buffer, &l);
  v.u |= (uint64_t) l << 62;
  return v.f;
}

static inline uint64_t
asuint64 (double f)
{
  union
  {
    double f;
    uint64_t i;
  } u = {f};
  return u.i;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (double x)
{
  uint64_t u = asuint64 (x);
  int e = u >> 52;
  return (e == 0x7ff || e == 0xfff) && (u << 12) != 0;
}

static inline int
is_equal (double x, double y)
{
  if (is_nan (x))
    return is_nan (y);
  if (is_nan (y))
    return is_nan (x);
  return asuint64 (x) == asuint64 (y);
}

static void
check (double x, double y)
{
  double z, t;
  mpfr_t X, Y, Z;
  mpfr_init2 (X, 53);
  mpfr_init2 (Y, 53);
  mpfr_init2 (Z, 53);
  mpfr_set_d (X, x, MPFR_RNDN);
  mpfr_set_d (Y, y, MPFR_RNDN);
  z = cr_atan2 (y, x);
  t = ref_atan2 (y, x);
  if (!is_equal (z, t))
  {
    printf ("cr_atan2 and ref_atan2 differ for y,x=%la,%la\n", y, x);
    printf ("cr_atan2  gives %la\n", z);
    printf ("ref_atan2 gives %la\n", t);
    exit (1);
  }
  mpfr_clear (X);
  mpfr_clear (Y);
  mpfr_clear (Z);
}

static void
check_all (double y, double x)
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
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  struct drand48_data buffer[1];
  double x, y;
  srand48_r (i, buffer);
  for (uint64_t n = 0; n < CORE_MATH_TESTS; n += nthreads)
  {
    x = get_random (buffer);
    y = get_random (buffer);
    check (x, y);
  }
}

static void
check_random_all (void)
{
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads ();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_random (getpid () + i, nthreads);
}

// check with |y/x| in the range [2^-64,1]
static void
check_small_aux (int i, int nthreads)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  struct drand48_data buffer[1];
  double x, y;
  srand48_r (i, buffer);
  double ratio = 0, dratio = 64.0 / (CORE_MATH_TESTS / nthreads);
  for (uint64_t n = 0; n < CORE_MATH_TESTS; n += nthreads)
  {
    x = get_random (buffer);
    y = get_random (buffer);
    int ex, ey;
    frexp (x, &ex);
    frexp (y, &ey);
    y = ldexp (y, ex - ey - (int) ratio);
    check (x, y);
    ratio += dratio;
  }
}

static void
check_small (void)
{
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads ();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_small_aux (getpid () + i, nthreads);
}

/* check y,x near power of 2 */
static void
check_near_pow2 (void)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int ex = -1074; ex <= 1024; ex++)
  {
    ref_init ();
    ref_fesetround (rnd);
    fesetround(rnd1[rnd]);
    double x = ldexp (0x1.fffffffffffffp-1, ex);
    double xl = nextafter (x, 0.0);
    double xh = nextafter (x, 0x1.fffffffffffffp1023);
    for (int ey = -1074; ey <= 1024; ey++)
    {
      double y = ldexp (0x1.fffffffffffffp-1, ey);
      double yl = nextafter (y, 0.0);
      double yh = nextafter (y, 0x1.fffffffffffffp1023);
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

  printf ("Checking y,x near powers of 2\n");
  check_near_pow2 ();

  printf ("Checking small values\n");
  check_small ();

  printf ("Checking random values\n");
  check_random_all ();

  return 0;
}
