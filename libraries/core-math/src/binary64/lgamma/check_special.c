/* Generate special cases for lgamma testing.

Copyright (c) 2022-2025 Paul Zimmermann, Inria.

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
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <mpfr.h>
#include <omp.h>
#include "function_under_test.h"

int ref_init (void);
int ref_fesetround (int);

double cr_lgamma (double);
double ref_lgamma (double);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;
unsigned long tested = 0;
int nthreads;

#define MAX_THREADS 192

static unsigned int Seed[MAX_THREADS];

typedef union {double f; uint64_t u;} b64u64_u;

static inline uint64_t
asuint64 (double f)
{
  b64u64_u u = {.f = f};
  return u.u;
}

static inline double
asfloat64 (uint64_t n)
{
  b64u64_u u = {.u = n};
  return u.f;
}

static double
get_random (int tid)
{
  b64u64_u v;
  v.u = rand_r (Seed + tid);
  v.u |= (uint64_t) rand_r (Seed + tid) << 31;
  v.u |= (uint64_t) rand_r (Seed + tid) << 62;
  return v.f;
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

// return +1 when gamma(x) > 0, -1 when gamma(x) < 0 and 0 when undefined
static int
expected_signgam (double x)
{
  if (x > 0)
    return +1;
  if (x == 0)
    return (signbit (x)) ? -1 : +1;
  double y = floor (x);
  if (x == y)
    return 0; // x is integer, gamma(x) tends to +Inf and -Inf on both sides
  // gamma(x) is negative in (-2k-1,-2k), positive in (-2k,-2k+1)
  // return -1 if y is odd, +1 if y is even

  // since y != x, necessarily |x| < 2^52, thus we can cast y to uint64_t
  uint64_t k = y;
  return (k & 1) ? -1 : +1;
}

static void
check (double x)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tested ++;
  ref_init ();
  ref_fesetround (rnd);
  double y1 = ref_lgamma (x);
  fesetround (rnd1[rnd]);
  signgam = 0;
  double y2 = cr_lgamma (x);
  if (!is_equal (y1,y2))
  {
    printf ("FAIL x=%la ref=%la z=%la\n", x, y1, y2);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // don't check signgam in multi-thread mode since it is not thread-safe
  if (nthreads == 1) {
    int s = expected_signgam (x);
    // check signgam is correctly set
    if (s != 0 && signgam == 0)
    {
      printf ("Error, signgam is not set for x=%la (y=%la,s=%d)\n", x, y1, s);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
    // check signgam is correctly set
    if (s != 0 && s != signgam)
    {
      printf ("Error, signgam is wrong for x=%la (y=%la)\n", x, y1);
      printf ("expected %d, got %d\n", s, signgam);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
  }
}

typedef union { double f; uint64_t i; } d64u64;

static void
check_negative (void)
{
  /* this code should not be run in parallel, since the use of signgam is
     not thread-safe */
  for (int n = -1000000; n < 0; n++)
  {
    check (nextafter ((double) n, 0.0));
    check (nextafter ((double) (n+1), (double) n));
    check ((double) n + 0.5);
  }
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 10000000UL /* total number of tests */
#endif

// check precision-p inputs
static void
check_low_precision (int p)
{
  int e;
  double x = 0x1p-1074, oldx = 0;
  while (x > oldx)
  {
    oldx = x;
    check (x);
    check (-x);
    frexp (x, &e);
    // 0.5*2^e <= x < 2^e
    x += (e - p >= -1074) ? ldexp (1.0, e - p) : 0x1p-1074;
  }
}

static void
check_special (void)
{
  double zero = asfloat64 (0x0000000000000000);
  double minZero = asfloat64 (0x8000000000000000);

  // check signgam is correctly set for lgamma (+0)
  signgam = 0;
  double y = cr_lgamma (zero);
  int s = expected_signgam (zero);
  if(s != 0 && signgam == 0){
    printf ("Error, signgam is not set for x=%la (y=%la)\n", zero, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // check signgam is correctly set
  if (s != 0 && s != signgam)
  {
    printf ("Error, signgam is wrong for x=%la (y=%la)\n", zero, y);
    printf ("expected %d, got %d\n", s, signgam);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // check signgam is correctly set for lgamma(-0)
  signgam = 0;
  y = cr_lgamma (minZero);
  s = expected_signgam (minZero);
  if(s != 0 && signgam == 0){
    printf ("Error, signgam is not set for x=%la (y=%la)\n", minZero, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // check signgam is correctly set
  if (s != 0 && s != signgam)
  {
    printf ("Error, signgam is wrong for x=%la (y=%la)\n", minZero, y);
    printf ("expected %d, got %d\n", s, signgam);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

// put in h+l a double-double approximation of lgamma(x)
static void
dd_lgamma (double *h, double *l, double x)
{
  mpfr_t t;
  mpfr_init2 (t, 107);
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_lgamma (t, &signgam, t, MPFR_RNDN);
  *h = mpfr_get_d (t, MPFR_RNDN);
  mpfr_sub_d (t, t, *h, MPFR_RNDN);
  *l = mpfr_get_d (t, MPFR_RNDN);
  mpfr_clear (t);
}

// return a double approximation of digamma(x) = lgamma'(x)
static double
digamma (double x)
{
  mpfr_t t;
  mpfr_init2 (t, 53);
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_digamma (t, t, MPFR_RNDN);
  double ret = mpfr_get_d (t, MPFR_RNDN);
  mpfr_clear (t);
  return ret;
}

// return a double approximation of trigamma(x) = lgamma''(x)
static double
trigamma (double x)
{
  mpfr_t t;
  mpfr_init2 (t, 53);
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_trigamma (t, t, MPFR_RNDN);
  double ret = mpfr_get_d (t, MPFR_RNDN);
  mpfr_clear (t);
  return ret;
}

double cr_function_under_test(double);

static inline double tfun(double x){
  return cr_function_under_test(x);
}

static void scan_consecutive(int64_t n, double x){
  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  if (n < 0) {
    n = -n;
    x = asfloat64 (asuint64 (x) - n);
  }
  int64_t n0 = n;
  while (n) {
    double h, l, d, dd;
    dd_lgamma (&h, &l, x);
    d = digamma (x); // derivative of lgamma(x)
    dd = fabs (trigamma (x)); // absolute value of 2nd derivative
    int e;
    frexp (x, &e);
    /* 2^(e-1) <= |x| < 2^e thus ulp(x) = 2^(e-53) */
    d = ldexp (d, e - 53); // multiply d by ulp(x)
    dd = ldexp (dd, 2 * (e - 53)); // multiply dd by ulp(x)^2
    /* we want j^2*dd < 2^-11 ulp(h) so that the 2nd-order term
       produces an error bounded by 2^-11 ulp(h), to that MPFR
       will be called with probability about 2^-11.
       Thus approximately j^2*dd < 2^-64 |h|,
       or j < 2^-32 sqrt(|h|/dd) */
    int64_t jmax = 0x1p-32 * sqrt (fabs (h) / dd);
    if (jmax > n) jmax = n; // cap to n
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
    for(int64_t j=0;j<jmax;j++){
      b64u64_u v = {.f = x};
      v.u += j;
      double t = tfun (v.f);
      // asinh(x+j*u) is approximated by h + l + j*d
      double w = h + __builtin_fma (j, d, l);
      if (t != w) // expensive test
        check(v.f);
    }
    n -= jmax;
    x += jmax * ldexp (1.0, e - 53);
  }
  printf ("checked %lu values, expensive checks %lu\n", n0, tested);
}

int
main (int argc, char *argv[])
{
  int conseq = 0;
  unsigned long n = 1000000; // length of consecutive runs with -C
  double a = 1.5;  // starting point of consecutive runs with -C

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
      else if (strcmp (argv[1], "-C") == 0)
        {
          conseq = 1;
          n = strtoul (argv[2], NULL, 0);
          argc -= 2;
          argv += 2;
        }
      else if (strcmp (argv[1], "-a") == 0)
        {
          a = strtod (argv[2], NULL);
          argc -= 2;
          argv += 2;
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
  ref_init ();
  ref_fesetround (rnd);

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
#endif
  nthreads = omp_get_num_threads ();

  if (conseq) {
    scan_consecutive (n, a);
    return 0;
  }

  check_special ();

  printf ("Check low-precision inputs\n");
  check_low_precision (10);

  printf ("Check negative inputs\n");
  check_negative ();

  long seed = getpid ();
  for (int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;
  
  printf ("Checking random numbers...\n");
  /* this code should not be run in parallel, since the use of signgam is
     not thread-safe */
  for (n = 0; n < CORE_MATH_TESTS; n++)
  {
    ref_init ();
    ref_fesetround (rnd);
    double x = get_random (0);
    check (x);
  }

  return 0;
}
