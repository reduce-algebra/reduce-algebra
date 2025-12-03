/* Check correctness of bivariate binary32 function on worst cases.

Copyright (c) 2024-2025 Stéphane Glondu and Paul Zimmermann, Inria.

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
#include <errno.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

#include "function_under_test.h"

float cr_function_under_test (float, float);
float ref_function_under_test (float, float);
int ref_fesetround (int);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN,    MPFR_RNDZ,     MPFR_RNDU, MPFR_RNDD   };

int rnd = 0;

typedef float float2[2];

typedef union { float f; uint32_t i; } d32u32;

/* scanf %a from buf, allowing snan, +snan and -snan */
static int
sscanf_snan (char *buf, float *x)
{
  if (sscanf(buf, "%a", x) == 1)
    return 1;
  else if (strncmp (buf, "snan", 4) == 0 || strncmp (buf, "+snan", 5) == 0)
  {
    d32u32 u = {.i = 0x7f800001};
    *x = u.f;
    return 1;
  }
  else if (strncmp (buf, "-snan", 5) == 0)
  {
    d32u32 u = {.i = 0xff800001};
    *x = u.f;
    return 1;
  }
  return 0;
}

static void
readstdin(float2 **result, int *count)
{
  char *buf = NULL;
  size_t buflength = 0;
  ssize_t n;
  int allocated = 512;

  *count = 0;
  if (NULL == (*result = malloc(allocated * sizeof(float2)))) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  while ((n = getline(&buf, &buflength, stdin)) >= 0) {
    if (n > 0 && buf[0] == '#') continue;
    if (*count >= allocated) {
      int newsize = 2 * allocated;
      float2 *newresult = realloc(*result, newsize * sizeof(float2));
      if (NULL == newresult) {
        fprintf(stderr, "realloc(%d) failed\n", newsize);
        exit(1);
      }
      allocated = newsize;
      *result = newresult;
    }
    float2 *item = *result + *count;
    if (sscanf(buf, "%a,%a", &(*item)[0], &(*item)[1]) == 2)
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

typedef union {float f; uint32_t u;} b32u32_u;

static inline uint32_t
asuint (float f)
{
  b32u32_u u = {.f = f};
  return u.u;
}

static inline float
asfloat (uint32_t n)
{
  b32u32_u u = {.u = n};
  return u.f;
}

#ifdef CORE_MATH_SUPPORT_ERRNO
/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) == 0;
}
#endif

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) != 0;
}

static inline int
is_equal (float x, float y)
{
  if (is_nan (x))
    return is_nan (y);
  if (is_nan (y))
    return is_nan (x);
  return asuint (x) == asuint (y);
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

/* For |z| = 2^-126 and underflow after rounding, clear the MPFR
   underflow exception when the rounded result (with unbounded exponent)
   equals +/-2^-126 (might be set due to a bug in MPFR <= 4.2.1).
   For |z| = 2^-126 and underflow before rounding, clear the fenv.h
   underflow exception when |f(x,y)| < 2^-126 but there is no underflow
   after rounding (thus we mimic underflow after rounding). */
static void
fix_underflow (float x, float y, float z)
{
  if (__builtin_fabsf (z) != 0x1p-126f)
    return;
  if (underflow_before) {
    if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) == 0)
      feclearexcept (FE_UNDERFLOW);
    return;
  }
  mpfr_t t, u;
  mpfr_init2 (t, 24);
  mpfr_init2 (u, 24);
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  mpfr_set_flt (t, x, MPFR_RNDN); // exact
  mpfr_set_flt (u, y, MPFR_RNDN); // exact
  /* mpfr_set_flt might raise the processor underflow/overflow/inexact flags
     (https://gitlab.inria.fr/mpfr/mpfr/-/issues/2) */
  fesetexceptflag (&flag, FE_ALL_EXCEPT); // restore flags
  // printf ("MPFR_FLAGS_UNDERFLOW: %d\n", mpfr_flags_test (MPFR_FLAGS_UNDERFLOW));
  mpfr_function_under_test (t, t, u, rnd2[rnd]);
  // printf ("MPFR_FLAGS_UNDERFLOW: %d\n", mpfr_flags_test (MPFR_FLAGS_UNDERFLOW));
  /* don't call mpfr_subnormalize here since we precisely want an unbounded
     exponent */
  mpfr_abs (t, t, MPFR_RNDN); // exact
#if MPFR_VERSION_MAJOR<4 || (MPFR_VERSION_MAJOR==4 && MPFR_VERSION_MINOR<=2)
  if (mpfr_cmp_ui_2exp (t, 1, -126) == 0) // |o(f(x,y))| = 2^-126
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
#endif
  mpfr_clear (t);
  mpfr_clear (u);
}

int tests = 0, failures = 0;

static void
check (float x, float y)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tests ++;
  ref_init();
  ref_fesetround(rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
  float z1 = ref_function_under_test(x, y);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround(rnd1[rnd]);
  feclearexcept (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW);
  errno = 0;
  float z2 = cr_function_under_test(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
#endif
  if (! is_equal (z1, z2)) {
    printf("FAIL x,y=%a,%a ref=%a z=%a\n",
           (double) x, (double) y, (double) z1, (double) z2);
    fflush(stdout);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    failures ++;
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  /* When there is underflow but the result is exact, IEEE 754-2019 says the
     underflow exception should not be signaled. However MPFR raises the underflow
     exception in this case: we clear it to mimic IEEE 754-2019. */
  if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_INEXACT))
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);

  fix_underflow (x, y, z1);

  // check spurious/missing underflow
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Spurious underflow exception for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Missing underflow exception for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  // check spurious/missing overflow
  if (fetestexcept (FE_OVERFLOW) && !mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Spurious overflow exception for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Missing overflow exception for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x,y=%a,%a\n",
            (double) x, (double) y);
    fflush (stdout);
    failures ++;
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x,y=%a,%a\n",
            (double) x, (double) y);
    fflush (stdout);
    failures ++;
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
#endif

  // check errno
#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x,y are normal numbers and z is NaN, we should have errno = EDOM.
  if (!is_nan (x) && !is_inf (x) && !is_nan (y) && !is_inf (y))
  {
    if (is_nan (z1) && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x,y=%a,%a (z=%a)\n",
              (double) x, (double) y, (double) z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
    if (!is_nan (z1) && errno == EDOM)
    {
      printf ("Spurious errno=EDOM for x,y=%a,%a (z=%a)\n",
              (double) x, (double) y, (double) z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
    int expected_erange = (is_inf (z1) && inex1 == 0) ||
      mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
      mpfr_flags_test (MPFR_FLAGS_UNDERFLOW);
    if (expected_erange && errno != ERANGE)
    {
      printf ("Missing errno=ERANGE for x,y=%a,%a (z=%a)\n",
              (double) x, (double) y, (double) z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
    if (!expected_erange && errno == ERANGE)
    {
      printf ("Spurious errno=ERANGE for x,y=%a,%a (z=%a)\n",
              (double) x, (double) y, (double) z1);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }
  }
#endif

  // check underflow flag is not reset
  feraiseexcept (FE_UNDERFLOW);
  z1 = cr_function_under_test(x, y);
  if (!fetestexcept (FE_UNDERFLOW)) {
    printf ("Underflow exception was reset for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  // check divbyzero flag is not reset
  feraiseexcept (FE_DIVBYZERO);
  z1 = cr_function_under_test(x, y);
  if (!fetestexcept (FE_DIVBYZERO)) {
    printf ("Division by zero exception was reset for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  /* Check that all flags are not reset */
  // check inexact flag is not reset
  feraiseexcept (FE_INEXACT);
  z1 = cr_function_under_test(x, y);
  if (!fetestexcept (FE_INEXACT)) {
    printf ("Inexact exception was reset for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  // check invalid flag is not reset
  feraiseexcept (FE_INVALID);
  z1 = cr_function_under_test(x, y);
  if (!fetestexcept (FE_INVALID)) {
    printf ("Invalid exception was reset for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }

  // check overflow flag is not reset
  feraiseexcept (FE_OVERFLOW);
  z1 = cr_function_under_test(x, y);
  if (!fetestexcept (FE_OVERFLOW)) {
    printf ("Overflow exception was reset for x,y=%a,%a (z=%a)\n",
            (double) x, (double) y, (double) z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
}

void
doloop(void)
{
  float2 *items;
  int count;

  readstdin(&items, &count);

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < count; i++) {
    float x = items[i][0], y = items[i][1];
    check (x, y);
#ifdef WORST_SYMMETRIC_Y
    check (x, -y);
#endif
#ifdef WORST_SYMMETRIC_X
    check (-x, y);
#ifdef WORST_SYMMETRIC_Y
    check (-x, -y);
#endif
#endif
#ifdef WORST_SWAP
    check (y, x);
#ifdef WORST_SYMMETRIC_Y
    check (-y, x);
#endif
#ifdef WORST_SYMMETRIC_X
    check (y, -x);
#ifdef WORST_SYMMETRIC_Y
    check (-y, -x);
#endif
#endif
#endif
  }

  free(items);
  printf("%d tests passed, %d failure(s)\n", tests, failures);
}

// When x is a NaN, returns 1 if x is an sNaN and 0 if it is a qNaN
static inline int is_signaling(float x) {
  b32u32_u u = {.f = x};

  return !(u.u & (1ull << 22));
}

/* check for signaling NaN input */
static void
check_signaling_nan (void)
{
  float snan = asfloat (0x7f800001);
  float qnan = asfloat (0x7fc00000);

  feclearexcept (FE_INVALID);
  float y = cr_function_under_test (snan, qnan);
  // check that foo(sNaN,qNaN) = qNaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN,qNaN) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN,qNaN) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  int flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x,y=%a,%a\n",
            (double) snan, (double) qnan);
    exit (1);
  }

  feclearexcept (FE_INVALID);
  y = cr_function_under_test (snan, 2.0f);
  // check that foo(NaN,1.0) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN,2.0) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN,2.0) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x,y=%a,%a\n", (double) snan, 2.0);
    exit (1);
  }

  feclearexcept (FE_INVALID);
  y = cr_function_under_test (qnan, snan);
  // check that foo(qNaN,sNaN) = qNaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(qNaN,sNaN) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(qNaN,sNaN) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x=qNaN,y=%a\n", (double) snan);
    exit (1);
  }

  feclearexcept (FE_INVALID);
  // don't use 1 for 1st argument since powf(1,sNaN) = 1
  y = cr_function_under_test (-1.0f, snan);
  // check that foo(x,NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x,y=%a,%a\n", -1.0, (double) snan);
    exit (1);
  }

  // also check sNaN with sign bit set
  snan = asfloat (0xff800001);
  feclearexcept (FE_INVALID);
  y = cr_function_under_test (snan, 2.0f);
  // check that foo(NaN,x) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(sNaN,2.0) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(sNaN,2.0) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x,y=%a,%a\n", (double) snan, 2.0);
    exit (1);
  }

  feclearexcept (FE_INVALID);
  // don't use 1 for 1st argument since powf(1,sNaN) = 1
  y = cr_function_under_test (-1.0f, snan);
  // check that foo(x,NaN) = NaN
  if (!is_nan (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be NaN, got %a=%x\n",
             (double) y, asuint (y));
    exit (1);
  }
  // check that the signaling bit disappeared
  if (is_signaling (y))
  {
    fprintf (stderr, "Error, foo(x,sNaN) should be qNaN, got sNaN=%x\n",
             asuint (y));
    exit (1);
  }
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x,y=%a,%a\n", -1.0, (double) snan);
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

  check_underflow_before ();

  doloop();

  check_signaling_nan ();
}
