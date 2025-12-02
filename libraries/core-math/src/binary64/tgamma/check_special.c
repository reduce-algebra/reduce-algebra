/* Generate special cases for tgamma testing.

Copyright (c) 2022-2024 Paul Zimmermann, Inria.

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
#include <inttypes.h>
#include <errno.h>
#include <omp.h>
#include "function_under_test.h"

int ref_init (void);
int ref_fesetround (int);

double cr_tgamma (double);
double ref_tgamma (double);

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

static inline int
is_inf (double x)
{
  uint64_t u = asuint64 (x);
  uint64_t e = u >> 52;
  return (e == 0x7ff || e == 0xfff) && (u << 12) == 0;
}

static void
check_invalid (void)
{
  double zero = asfloat64 (0x0000000000000000);
  double minZero = asfloat64 (0x8000000000000000);
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif

  //Check +0
  feclearexcept (FE_INVALID);
  double y = cr_tgamma (zero);

  // check the invalid exception was not set
  int flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Spurious invalid exception for x=+0\n");
#ifndef DO_NOT_ABORT
  exit (1);
#endif
  }

  // Check that tgamma(+0) = +Inf
  if (!is_inf(y) || y < 0)
  {
    fprintf (stderr, "Error, tgamma(+0) should be +Inf, got %la=%"PRIx64"\n",
      y, asuint64 (y));
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(errno != ERANGE)
  {
      fprintf (stderr, "Expected errno=ERANGE, got errno=%d for x=+0 [y=%a]\n", errno, y);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  // check -0
  feclearexcept (FE_INVALID);
  y = cr_tgamma (minZero);

  // check the invalid exception was not set
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
      printf ("Spurious invalid exception for x=-0\n");
#ifndef DO_NOT_ABORT
  exit (1);
#endif
  }

  // Check that tgamma(-0) = -Inf
  if (!is_inf(y) || y > 0)
  {
    fprintf (stderr, "Error, tgamma(-0) should be -Inf, got %la=%"PRIx64"\n",
      y, asuint64 (y));
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(errno != ERANGE)
  {
      fprintf (stderr, "Expected errno=ERANGE, got errno=%d for x=-0 [y=%a]\n", errno, y);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif
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
  double y1 = ref_tgamma (x);
  fesetround (rnd1[rnd]);
  double y2 = cr_tgamma (x);
  if (!is_equal (y1,y2))
  {
    printf ("FAIL x=%la ref=%la z=%la\n", x, y1, y2);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

typedef union { double f; uint64_t i; } d64u64;

static void
check_negative (void)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int n = -1000000; n < 0; n++)
  {
    check (nextafter ((double) n, 0.0));
    check (nextafter ((double) (n+1), (double) n));
    check ((double) n + 0.5);
  }
}

// return x0 such that |gamma(x0)| is minimal on (n,n+1), for n < 0
static double
find_min (int n)
{
  double x0, x1, x2, x3, v0, v1, v2, v3;
  x0 = nextafter (n, n+1);
  x3 = nextafter (n+1, n);
  // use trichotomy
  while (1)
  {
    x1 = (2.0 * x0 + x3) / 3.0;
    x2 = (x0 + 2.0 * x3) / 3.0;
    if (x0 == x1 || x1 == x2 || x2 == x3)
      break;
    v1 = fabs (cr_tgamma (x1));
    v2 = fabs (cr_tgamma (x2));
    if (v1 < v2)
      x3 = x2;
    else
      x0 = x1;
  }
  v0 = fabs (cr_tgamma (x0));
  v1 = fabs (cr_tgamma (x1));
  v2 = fabs (cr_tgamma (x2));
  v3 = fabs (cr_tgamma (x3));
  if (v0 <= v1 && v0 <= v2 && v0 <= v3)
    return x0;
  if (v1 <= v2 && v1 <= v3)
    return x1;
  if (v2 <= v3)
    return x2;
  return x3;
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

static void
check_subnormal_aux (double x1, double x2)
{
  if (!(x1 <= x2))
    return;
  uint64_t n1 = asuint64 (x1);
  uint64_t n2 = asuint64 (x2);
  // for negative numbers, x1 < x2 means n2 < n1
  int64_t d = n1 - n2;
  // with s=d/40000, we perform 929699 tests
  uint64_t s = d / (CORE_MATH_TESTS / 23);
  if (s == 0)
    s = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t n = n2; n <= n1; n += s)
    check (asfloat64 (n));
}

static void
check_subnormal (void)
{
  double x0, y0, a, b, c, x1, x2, x3, x4;
  for (int k = -184; k <= -171; k++)
  {
    x0 = find_min (k);
    // |gamma(x)| is decreasing on (k,x0), increasing on (x0,k+1)
    y0 = fabs (cr_tgamma (x0));
    if (y0 >= 0x1p-1022)
      continue; // no subnormal value
    a = k;
    b = x0;
    while (nextafter (a, x0) != b)
    {
      c = (a + b) / 2.0;
      if (fabs (cr_tgamma (c)) >= 0x1p-1022)
        a = c;
      else
        b = c;
    }
    x1 = b; // smallest value in (k,x0) such that |gamma(x)| < 2^-1022
    a = k;
    b = x0;
    while (nextafter (a, x0) != b)
    {
      c = (a + b) / 2.0;
      if (fabs (cr_tgamma (c)) >= 0x1p-1074)
        a = c;
      else
        b = c;
    }
    x2 = a; // largest value in (k,x0) such that |gamma(x)| >= 2^-1074
    check_subnormal_aux (x1, x2);
    a = x0;
    b = k+1;
    while (nextafter (a, k+1) != b)
    {
      c = (a + b) / 2.0;
      if (fabs (cr_tgamma (c)) >= 0x1p-1022)
        b = c;
      else
        a = c;
    }
    x4 = a; // smallest value in (x0,k+1) such that |gamma(x)| < 2^-1022
    a = x0;
    b = k+1;
    while (nextafter (a, k+1) != b)
    {
      c = (a + b) / 2.0;
      if (fabs (cr_tgamma (c)) >= 0x1p-1074)
        b = c;
      else
        a = c;
    }
    x3 = b; // largest value in (k,x0) such that |gamma(x)| >= 2^-1074
    check_subnormal_aux (x3, x4);
  }
}

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

double cr_function_under_test(double);

static inline double tfun(double x){
  return cr_function_under_test(x);
}

// put in h+l a double-double approximation of tgamma(x)
static void
dd_tgamma (double *h, double *l, double x)
{
  mpfr_t t;
  mpfr_init2 (t, 107);
  mpfr_set_d (t, x, MPFR_RNDN);
  mpfr_gamma (t, t, MPFR_RNDN);
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
    dd_tgamma (&h, &l, x);
    double psi = digamma (x);
    d = h * psi; // derivative: gamma(x)*psi(x)
    // 2nd derivative is gamma(x)*(psi(x)^2 + trigamma(x))
    dd = fabs (h * (psi * psi + trigamma (x)));
    int e;
    frexp (x, &e);
    /* 2^(e-1) <= |x| < 2^e thus ulp(x) = 2^(e-53) */
    d = ldexp (d, e - 53); // multiply d by ulp(x)
    // for negative values, it seems we have to negate d
    if (x < 0) d = -d;
    dd = ldexp (dd, 2 * (e - 53)); // multiply dd by ulp(x)^2
    /* we want j^2*dd < 2^-11 ulp(h) so that the 2nd-order term
       produces an error bounded by 2^-11 ulp(h), to that MPFR
       will be called with probability about 2^-11.
       Thus approximately j^2*dd < 2^-64 |h|,
       or j < 2^-32 sqrt(|h|/dd) */
    double jmax_d = 0x1p-32 * sqrt (fabs (h) / dd);
    int64_t jmax = (jmax_d > n) ? n : jmax_d;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
    for(int64_t j=0;j<jmax;j++){
      b64u64_u v = {.f = x};
      v.u += j;
      double t = tfun (v.f);
      // asinh(x+j*u) is approximated by h + l + j*d
      double w = h + __builtin_fma (j, d, l);
      if (t != w) { // expensive test
        check(v.f);
      }
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

  check_invalid ();

  printf ("Check low-precision inputs\n");
  check_low_precision (10);

  printf ("Check subnormal output\n");
  check_subnormal ();

  printf ("Check negative inputs\n");
  check_negative ();

  long seed = getpid ();
  for (int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;
  
  printf ("Checking random numbers...\n");
  for (uint64_t i = 0; i < CORE_MATH_TESTS; i++)
  {
    ref_init ();
    ref_fesetround (rnd);
    int tid;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
    tid = omp_get_thread_num ();
#else
    tid = 0;
#endif
    double x = get_random (tid);
    check (x);
  }

  return 0;
}
