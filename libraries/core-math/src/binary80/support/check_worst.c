/* Check correctness of bivariate long double function on worst cases.

Copyright (c) 2022-2025 Stéphane Glondu, Paul Zimmermann, Inria.

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
#include <fenv.h>
#include <mpfr.h>
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

#include "function_under_test.h"

long double cr_function_under_test (long double, long double);
long double ref_function_under_test (long double, long double);
int ref_fesetround (int);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
static int rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

int rnd;

typedef long double ldouble2[2];

typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

// check long double has 64 bits of precision
static void
check_format (void)
{
  long double x = 0x1p-1074L; // smallest positive binary64
  int saved_rnd = fegetround ();
  fesetround (FE_TONEAREST);
  x = x * 0.5L;
  if (x == 0) {
    fprintf (stderr, "Error, long double is probably double\n");
    exit (1);
  }
  fesetround (saved_rnd);
}

/* scanf %La from buf, allowing snan, +snan and -snan */
static int
sscanf_snan (char *buf, long double *x)
{
  if (sscanf(buf, "%La", x) == 1)
    return 1;
  else if (strncmp (buf, "snan", 4) == 0 || strncmp (buf, "+snan", 5) == 0)
  {
    b80u80_t v;
    // +snan has encoding m=2^63+1, e=32767 (for example)
    v.e = 0x7fff;
    v.m = 0x8000000000000001ul;
    *x = v.f;
    return 1;
  }
  else if (strncmp (buf, "-snan", 5) == 0)
  {
    b80u80_t v;
    // -snan has encoding m=2^63+1, e=65535 (for example)
    v.e = 0xffff;
    v.m = 0x8000000000000001ul;
    *x = v.f;
    return 1;
  }
  return 0;
}

static void
readstdin(ldouble2 **result, int *count)
{
  char *buf = NULL;
  size_t buflength = 0;
  ssize_t n;
  int allocated = 512;

  *count = 0;
  if (NULL == (*result = malloc(allocated * sizeof(ldouble2)))) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  while ((n = getline(&buf, &buflength, stdin)) >= 0) {
    if (n > 0 && buf[0] == '#') continue;
    if (*count >= allocated) {
      int newsize = 2 * allocated;
      ldouble2 *newresult = realloc(*result, newsize * sizeof(ldouble2));
      if (NULL == newresult) {
        fprintf(stderr, "realloc(%d) failed\n", newsize);
        exit(1);
      }
      allocated = newsize;
      *result = newresult;
    }
    ldouble2 *item = *result + *count;
    if (sscanf(buf, "%La,%La", &(*item)[0], &(*item)[1]) == 2)
      (*count)++;
    else if (sscanf_snan (buf, &(*item)[0]) == 1)
    {
      char *tbuf = buf;
      while (*tbuf++ != ',');
      if (sscanf_snan (tbuf, &(*item)[1]) == 1)
        (*count)++;
    }
  }
  free (buf);
}

static int
is_nan (long double x)
{
  b80u80_t v = {.f = x};
  return ((v.e&0x7fff) == 0x7fff && (v.m != (1ul << 63)));
}

#ifdef CORE_MATH_SUPPORT_ERRNO
/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (long double x)
{
  b80u80_t v = {.f = x};
  return ((v.e & (uint64_t)0x7fff) == 0x7fff && (v.m == ((uint64_t)1 << 63)));
}
#endif

static inline int
is_equal (long double x, long double y)
{
  if (is_nan (x))
    return is_nan (y);
  if (is_nan (y))
    return is_nan (x);
  return x == y;
}

int tests = 0;

/* For |z| = 2^-16382 and underflow after rounding, clear the MPFR
   underflow exception when the rounded result (with unbounded exponent)
   equals +/-2^-16382 (might be set due to a bug in MPFR <= 4.2.1). */
static void
fix_underflow (long double x, long double y, long double z)
{
  if (__builtin_fabsl (z) != 0x1p-16382L)
    return;
  mpfr_t t, u;
  mpfr_init2 (t, 64);
  mpfr_init2 (u, 64);
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  mpfr_set_ld (t, x, MPFR_RNDN); // exact
  mpfr_set_ld (u, y, MPFR_RNDN); // exact
  /* mpfr_set_ld might raise the processor underflow/overflow/inexact flags
     (https://gitlab.inria.fr/mpfr/mpfr/-/issues/2) */
  fesetexceptflag (&flag, FE_ALL_EXCEPT); // restore flags
  mpfr_function_under_test (t, t, u, rnd2[rnd]);
  /* don't call mpfr_subnormalize here since we precisely want an unbounded
     exponent */
  mpfr_abs (t, t, MPFR_RNDN); // exact
#if MPFR_VERSION_MAJOR<4 || (MPFR_VERSION_MAJOR==4 && MPFR_VERSION_MINOR<=2)
  if (mpfr_cmp_ui_2exp (t, 1, -16382) == 0) // |o(f(x,y))| = 2^-16382
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
#endif
  mpfr_clear (t);
  mpfr_clear (u);
}

static int
check (long double x, long double y)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tests ++;
  ref_init();
  ref_fesetround(rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
  long double z1 = ref_function_under_test(x, y);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround(rnd1[rnd]);
  feclearexcept (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif
  long double z2 = cr_function_under_test(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
#endif
  /* Note: the test z1 != z2 would not distinguish +0 and -0. */
  if (is_equal (z1, z2) == 0) {
#ifndef EXCHANGE_X_Y
    printf("FAIL x=%La y=%La ref=%La z=%La\n", x, y, z1, z2);
#else
    printf("FAIL y=%La x=%La ref=%La z=%La\n", x, y, z1, z2);
#endif
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

  fix_underflow (x, y, z1);

  // Check for spurious/missing underflow exception
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Spurious underflow exception for x,y=%La,%La (z=%La)\n",
            x, y, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Missing underflow exception for x,y=%La,%La (z=%La)\n",
            x, y, z1);
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
    printf ("Spurious overflow exception for x,y=%La,%La (z=%La)\n",
            x, y, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Missing overflow exception for x,y=%La,%La (z=%La)\n",
            x, y, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }

#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x,y=%La,%La (z=%La)\n", x, y, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x,y=%La,%La (z=%La)\n", x, y, z1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
#endif

#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x,y are normal numbers and z is NaN, we should have errno = EDOM.
  if (!is_nan (x) && !is_inf (x) && !is_nan (y) && !is_inf (y))
  {
    if (is_nan (z1) && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x,y=%La,%La (z=%La)\n", x, y, z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
    if (!is_nan (z1) && errno == EDOM)
    {
      printf ("Spurious errno=EDOM for x,y=%La,%La (z=%La)\n", x, y, z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }

    /* If x,y are normal numbers and z is an exact infinity, or if there is
       an overflow, we should have errno=ERANGE. */
    int expected_erange = (is_inf (z1) && inex1 == 0) ||
      mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
      mpfr_flags_test (MPFR_FLAGS_UNDERFLOW);
    if (expected_erange && errno != ERANGE)
    {
      printf ("Missing errno=ERANGE for x,y=%La,%La (z=%La)\n", x, y, z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
    if (!expected_erange && errno == ERANGE)
    {
      printf ("Spurious errno=ERANGE for x,y=%La,%La (z=%La)\n", x, y, z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
  }
#endif

  return 0;
}

void
doloop(void)
{
  ldouble2 *items;
  int count, failures = 0;

  readstdin(&items, &count);

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for reduction(+:failures)
#endif
  for (int i = 0; i < count; i++) {
    long double x = items[i][0], y = items[i][1];
    failures += check (x, y);
#ifdef WORST_SYMMETRIC_Y
    failures += check (x, -y);
#endif
#ifdef WORST_SYMMETRIC_X
    failures += check (-x, y);
#ifdef WORST_SYMMETRIC_Y
    failures += check (-x, -y);
#endif
#endif
#ifdef WORST_SWAP
    failures += check (y, x);
#ifdef WORST_SYMMETRIC_Y
    failures += check (-y, x);
#endif
#ifdef WORST_SYMMETRIC_X
    failures += check (y, -x);
#ifdef WORST_SYMMETRIC_Y
    failures += check (-y, -x);
#endif
#endif
#endif
  }

  free(items);
  printf("%d tests passed, %d failure(s)\n", tests, failures);
}

/* When x is a NaN, returns 1 if x is an sNaN and 0 if it is a qNaN.
   According to https://en.wikipedia.org/wiki/Extended_precision,
   sNaN's have bits 63-62 equal to 10 (and bits 61-0 non-zero),
   while qNaN's have bits 63-62 equal to 11. */
static inline int is_signaling(long double x) {
  b80u80_t u = {.f = x};

  return ((u.m >> 62) & 1) == 0;
}

/* check for signaling NaN input */
static void
check_signaling_nan (void)
{
  b80u80_t u;
  u.e = 0x7fffu;
  u.m = 0xa000000000000000ull;
  long double snan = u.f;
  long double y = cr_function_under_test (snan, 2.0L);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN,x) should be NaN, got %La\n", y);
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN,x) should be qNaN, got %La\n", y);
    exit (1);
  }
  y = cr_function_under_test (2.0L, snan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be NaN, got %La\n", y);
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be qNaN, got %La\n", y);
    exit (1);
  }
  // check also sNaN with the sign bit set
  u.e = 0xffffu;
  u.m = 0xa000000000000000ull;
  snan = u.f;
  y = cr_function_under_test (snan, 2.0L);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN,x) should be NaN, got %La\n", y);
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN,x) should be qNaN, got %La\n", y);
    exit (1);
  }
  y = cr_function_under_test (2.0L, snan);
  // check that foo(NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be NaN, got %La\n", y);
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be qNaN, got %La\n", y);
    exit (1);
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

  check_format ();

  check_signaling_nan ();

  doloop();
}
