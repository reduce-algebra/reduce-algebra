/* Generate special cases for pow testing.

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
#include <math.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <unistd.h>

void doloop (int, int);
extern double cr_pow (double, double);
extern int ref_fesetround (int);
extern void ref_init (void);
extern mpfr_rnd_t rnd2[];
extern double ref_pow (double, double);

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
  z = cr_pow (x, y);
  t = ref_pow (x, y);
  if (!is_equal (z, t))
  {
    printf ("cr_pow and ref_pow differ for x=%la y=%la\n", x, y);
    printf ("cr_pow  gives %la\n", z);
    printf ("ref_pow gives %la\n", t);
    exit (1);
  }
  mpfr_clear (X);
  mpfr_clear (Y);
  mpfr_clear (Z);
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 500000000ul // total number of tests
#endif

static void
check_random (int seed, int nthreads)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  struct drand48_data buffer[1];
  double x, y;
  srand48_r (seed, buffer);
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

// check exact and midpoint values
static void
check_exact_or_midpoint (void)
{
  uint64_t tests = 0;
  double zmin = 0x1p-1074;
  double zmax = 0x1.fffffffffffffp+1023;
  // max_pow[n] is the largest x such that x^n fits in 54 bits
  double max_pow[] = {0, 0, 134217727, 262143, 11585, 1782, 511, 210, 107, 63, 42, 30, 22, 17, 14, 12, 10, 9, 7, 7, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3};
  // max_m[ey] is the largest m such that m^(2^ey) fits in 53 bits
  double max_m[] = {0x1.fffffffffffffp+52, 0x1.6a09e64p+26,
                         0x1.3068p+13, 0x1.88p+6, 0x1.2p+3, 0x1.8p+1};
  for (int ey = 5; ey >= 0; ey--)
  {
    int dn = (ey == 0) ? 1 : 2; // for ey > 0, we can restrict to odd n
    int d = 1 << ey; // denominator of y
    for (int n = 34; n >= 2; n -= dn)
    {
      double y = (double) n / (double) d;
      double xmin = pow (zmin, 1.0 / y);
      double xmax = pow (zmax, 1.0 / y);
      double m0 = 3.0; // should be odd
      double dm = 2.0; // should be even
      /* For n=2, we only sample some of the values of m, otherwise it would
         take of the order of 2 days on a 64-core machine. Just disable the
         test below to perform the full check. The value of STEP below ensures
         the test for n=2 takes about the same time as for all other values. */
      if (n == 2 && ey <= 1)
      {
#define STEP 512 // about max_pow[2] / max_pow[3]
        m0 += 2.0 * (lrand48 () % STEP);
        dm *= STEP;
      }
      for (double m = m0; m <= max_pow[n] && m <= max_m[ey]; m += dm)
      {
        // x = m^d*2^e with m odd and e divisible by d
        double md = pow (m, d);
        double tmin = xmin / md;
        double tmax = xmax / md;
        // we want tmin <= 2^e <= tmax
        int emin, emax;
        frexp (tmin, &emin); // 2^(emin-1) <= tmin < 2^emin
        frexp (tmax, &emax); // 2^(emax-1) <= tmax < 2^emax
        // we want emin divisible by d
        while (emin % d) emin++;
#pragma omp parallel for reduction(+: tests)
        for (int e = emin; e <= emax; e += d)
        {
          ref_init();
          ref_fesetround(rnd);
          fesetround(rnd1[rnd]);
          double x = ldexp (md, e);
          check (x, y);
          tests ++;
        }
        /* these exact/midpoint tests are more expensive than random tests,
           thus reduce the number of tests */
        if (tests >= CORE_MATH_TESTS / 15)
          return;
      }
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

  printf ("Checking exact/midpoint values\n");
  check_exact_or_midpoint ();

  printf ("Checking random values\n");
  check_random_all ();

  return 0;
}
