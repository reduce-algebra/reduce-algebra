/* Check correctness of univariate binary64 function on worst cases.

Copyright (c) 2022-2025 Stéphane Glondu and Paul Zimmermann, Inria.

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

#ifndef __APPLE__
#define _POSIX_C_SOURCE 200809L  /* for getline */
#endif /* !__APPLE */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <fenv.h>
#include <math.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <errno.h>

#include "function_under_test.h"

double cr_function_under_test (double);
double ref_function_under_test (double);
int ref_fesetround (int);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
static int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd = 0;

typedef union { double f; uint64_t i; } d64u64;

static void
readstdin(double **result, int *count)
{
  char *buf = NULL;
  size_t buflength = 0;
  ssize_t n;
  int allocated = 512;

  *count = 0;
  if (NULL == (*result = malloc(allocated * sizeof(double)))) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  while ((n = getline(&buf, &buflength, stdin)) >= 0) {
    if (n > 0 && buf[0] == '#') continue;
    if (*count >= allocated) {
      int newsize = 2 * allocated;
      double *newresult = realloc(*result, newsize * sizeof(double));
      if (NULL == newresult) {
        fprintf(stderr, "realloc(%d) failed\n", newsize);
        exit(1);
      }
      allocated = newsize;
      *result = newresult;
    }
    double *item = *result + *count;

    // special code for snan, since glibc does not read them
    if (strncmp (buf, "snan", 4) == 0 || strncmp (buf, "+snan", 5) == 0)
    {
      /* According to IEEE 754-2019, qNaN's have 1 as upper bit of their
         52-bit significand, and sNaN's have 0 */
      d64u64 u = {.i = 0x7ff4000000000000};
      *item = u.f;
      (*count)++;
    }
    else if (strncmp (buf, "-snan", 5) == 0)
    {
      d64u64 u = {.i = 0xfff4000000000000};
      *item = u.f;
      (*count)++;
    }
    else if (sscanf(buf, "%la", item) == 1)
      (*count)++;
  }
  free (buf);
}

static inline uint64_t
asuint64 (double f)
{
  d64u64 u = {.f = f};
  return u.i;
}

static inline double
asfloat64 (uint64_t i)
{
  d64u64 u = {.i = i};
  return u.f;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (double x)
{
  uint64_t u = asuint64 (x);
  uint64_t e = u >> 52;
  return (e == 0x7ff || e == 0xfff) && (u << 12) != 0;
}

#ifdef CORE_MATH_SUPPORT_ERRNO
/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (double x)
{
  uint64_t u = asuint64 (x);
  uint64_t e = u >> 52;
  return (e == 0x7ff || e == 0xfff) && (u << 12) == 0;
}
#endif

static inline int
is_equal (double x, double y)
{
  if (is_nan (x))
    return is_nan (y);
  if (is_nan (y))
    return is_nan (x);
  return asuint64 (x) == asuint64 (y);
}

int underflow_before; // non-zero if processor raises underflow before rounding

// return non-zero if the processor raises underflow before rounding
// (e.g., aarch64)
static void
check_underflow_before (void)
{
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  fesetround (FE_TONEAREST);
  feclearexcept (FE_UNDERFLOW);
  float x = 0x1p-126f;
  float y = __builtin_fmaf (-x, x, x);
  if (x == y) // this is needed otherwise the compiler says y is unused
    underflow_before = fetestexcept (FE_UNDERFLOW);
  fesetexceptflag (&flag, FE_ALL_EXCEPT); //restore flags
}

/* For |y| = 2^-1022 and underflow after rounding, clear the MPFR
   underflow exception when the rounded result (with unbounded exponent)
   equals +/-2^-1022 (might be set due to a bug in MPFR <= 4.2.1).
   For |y| = 2^-1022 and underflow before rounding, clear the fenv.h
   underflow exception when |f(x)| < 2^-1022 but there is no underflow
   after rounding (thus we mimic underflow after rounding). */
static void
fix_underflow (double x, double y)
{
  if (__builtin_fabs (y) != 0x1p-1022)
    return;
  if (underflow_before) {
    if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) == 0)
      feclearexcept (FE_UNDERFLOW);
    return;
  }
  mpfr_t t;
  mpfr_init2 (t, 53);
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  mpfr_set_d (t, x, MPFR_RNDN); // exact
  /* mpfr_set_d might raise the processor underflow/overflow/inexact flags
     (https://gitlab.inria.fr/mpfr/mpfr/-/issues/2) */
  fesetexceptflag (&flag, FE_ALL_EXCEPT); // restore flags
  mpfr_function_under_test (t, t, rnd2[rnd]);
  /* don't call mpfr_subnormalize here since we precisely want an unbounded
     exponent */
  mpfr_abs (t, t, MPFR_RNDN); // exact
#if MPFR_VERSION_MAJOR<4 || (MPFR_VERSION_MAJOR==4 && MPFR_VERSION_MINOR<=2)
  if (mpfr_cmp_ui_2exp (t, 1, -1022) == 0) // |o(f(x,y))| = 2^-1022
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
#endif
  mpfr_clear (t);
}

// return 1 if failure, 0 otherwise
static int
check (double x)
{
  ref_init();
  ref_fesetround(rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
  double z1 = ref_function_under_test(x);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround(rnd1[rnd]);
  feclearexcept (FE_ALL_EXCEPT);
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif
  double z2 = cr_function_under_test(x);
  /* Note: the test z1 != z2 would not distinguish +0 and -0. */
  if (is_equal (z1, z2) == 0) {
    printf("FAIL x=%la ref=%la z=%la\n", x, z1, z2);
    fflush(stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }

  /* When there is underflow but the result is exact, IEEE 754-2019 says the
     underflow exception should not be signaled. However MPFR raises the
     underflow exception in this case: we clear it to mimic IEEE 754-2019. */
  if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_INEXACT))
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);

  fix_underflow (x, z1);

  // Check for spurious/missing underflow exception
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Spurious underflow exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Missing underflow exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }

  /* Check for spurious/missing overflow exception */
  if (fetestexcept (FE_OVERFLOW) && !mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Spurious overflow exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Missing overflow exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }

#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x=%la (y=%la)\n", x, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
#endif

  // check errno
#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x is a normal number and y is NaN, we should have errno = EDOM.
  int expected_edom = !is_nan (x) && is_nan (z1);
  if (expected_edom && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%la (y=%la)\n", x, z1);
      fflush (stdout);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
    if (!expected_edom && errno == EDOM)
    {
      printf ("Spurious errno=EDOM for x=%la (y=%la)\n", x, z1);
      fflush (stdout);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }

    /* If x is a normal number and a pole error (y exact infinity) or an
       overflow/underflow occurs, we should have errno = ERANGE. */
    int expected_erange = !is_nan (x) && !is_inf (x) &&
      ((is_inf (z1) && inex1 == 0) ||
       mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
       mpfr_flags_test (MPFR_FLAGS_UNDERFLOW));
    if (expected_erange && errno != ERANGE)
    {
      printf ("Missing errno=ERANGE for x=%la (y=%la)\n", x, z1);
      fflush (stdout);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
    if (!expected_erange && errno == ERANGE)
    {
      printf ("Spurious errno=ERANGE for x=%la (y=%la)\n", x, z1);
      fflush (stdout);
#ifdef DO_NOT_ABORT
      return 1;
#else
      exit(1);
#endif
    }
#endif

  // check underflow flag is not reset
  feraiseexcept (FE_UNDERFLOW);
  z1 = cr_function_under_test(x);
  if (!fetestexcept (FE_UNDERFLOW)){
    printf ("Underflow exception was reset for x=%la (z=%la)\n",
      x, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check divbyzero flag is not reset
  feraiseexcept (FE_DIVBYZERO);
  z1 = cr_function_under_test(x);
  if (!fetestexcept (FE_DIVBYZERO)){
    printf ("Division by zero exception was reset for x=%la (z=%la)\n",
      x, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check inexact flag is not reset
  feraiseexcept (FE_INEXACT);
  z1 = cr_function_under_test(x);
  if (!fetestexcept (FE_INEXACT)){
    printf ("Inexact exception was reset for x=%la (z=%la)\n",
      x, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check invalid flag is not reset
  feraiseexcept (FE_INVALID);
  z1 = cr_function_under_test(x);
  if (!fetestexcept (FE_INVALID)){
    printf ("Invalid exception was reset for x=%la (z=%la)\n",
      x, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check overflow flag is not reset
  feraiseexcept (FE_OVERFLOW);
  z1 = cr_function_under_test(x);
  if (!fetestexcept (FE_OVERFLOW)){
    printf ("Overflow exception was reset for x=%la (z=%la)\n",
      x, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }
  return 0;
}

void
doloop(void)
{
  double *items;
  int count, tests = 0, failures = 0;

  readstdin(&items, &count);

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for reduction(+: failures,tests)
#endif
  for (int i = 0; i < count; i++) {
    double x = items[i];
    tests ++;
    if (check (x))
      failures ++;
#ifdef WORST_SYMMETRIC
    tests ++;
    x = -x;
    if (check (x))
      failures ++;
#endif
  }

  free(items);
  printf("%d tests passed, %d failure(s)\n", tests, failures);
}

// When x is a NaN, returns 1 if x is an sNaN and 0 if it is a qNaN
static inline int is_signaling(double x) {
  d64u64 _x = {.f = x};

  return !(_x.i & (1ull << 51));
}

/* check for signaling NaN input */
static void
check_signaling_nan (void)
{
  feclearexcept (FE_INVALID);
  double snan = asfloat64 (0x7ff0000000000001ull);
  double y = cr_function_under_test (snan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN) should be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN) should be qNaN, got sNaN=%"PRIx64"\n",
             asuint64 (y));
    exit (1);
  }
  // check the invalid exception was set
  int flag = fetestexcept (FE_INVALID);
  if(!flag)
  {
    printf ("Missing invalid exception for x=sNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  feclearexcept (FE_INVALID);
  // check also sNaN with the sign bit set
  snan = asfloat64 (0xfff0000000000001ull);
  y = cr_function_under_test (snan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(-sNaN) should be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(-sNaN) should be qNaN, got sNaN=%"PRIx64"\n",
             asuint64 (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if(!flag)
  {
    printf ("Missing invalid exception for x=-sNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  feclearexcept (FE_INVALID);
  double qnan = asfloat64 (0x7ff8000000000000ull);
  y = cr_function_under_test (qnan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(qNaN) should be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(qNaN) should be qNaN, got sNaN=%"PRIx64"\n",
             asuint64 (y));
    exit (1);
  }
  // check the invalid exception was not set
  flag = fetestexcept (FE_INVALID);
  if(flag)
  {
    printf ("Spurious invalid exception for x=qNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  feclearexcept (FE_INVALID);
  // check also qNaN with the sign bit set
  qnan = asfloat64 (0xfff8000000000000ull);
  y = cr_function_under_test (qnan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(-qNaN) should be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(-qNaN) should be qNaN, got sNaN=%"PRIx64"\n",
             asuint64 (y));
    exit (1);
  }
  // check the invalid exception was not set
  flag = fetestexcept (FE_INVALID);
  if(flag)
  {
    printf ("Spurious invalid exception for x=qNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
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
      else
        {
          fprintf (stderr, "Error, unknown option %s\n", argv[1]);
          exit (1);
        }
    }

  check_underflow_before ();

  doloop();

  check_signaling_nan ();
}
