/* Check correctness of univariate binary32 function by exhaustive search.

Copyright (c) 2022-2025 Alexei Sibidanov and Paul Zimmermann

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
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

#include "function_under_test.h"

float cr_function_under_test (float);
float ref_function_under_test (float);
int mpfr_function_under_test (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
int ref_fesetround (int);
void ref_init (void);

/* the code below is to check correctness by exhaustive search */

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN,    MPFR_RNDZ,     MPFR_RNDU, MPFR_RNDD   };

int rnd = 0;
int keep = 0;

typedef union { uint32_t n; float f; } union_t;

static inline float
asfloat (uint32_t n)
{
  union_t u = {.n = n};
  return u.f;
}

static inline uint32_t
asuint (float f)
{
  union_t u = {.f = f};
  return u.n;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) != 0;
}

/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) == 0;
}

static int
is_equal (float y1, float y2)
{
  if (is_nan (y1))
    return is_nan (y2);
  if (is_nan (y2))
    return is_nan (y1);
  return asuint (y1) == asuint (y2);
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

/* For |y| = 2^-126 and underflow after rounding, clear the MPFR
   underflow exception when the rounded result (with unbounded exponent)
   equals +/-2^-126 (might be set due to a bug in MPFR <= 4.2.1).
   For |y| = 2^-126 and underflow before rounding, clear the fenv.h
   underflow exception when |f(x)| < 2^-126 but there is no underflow
   after rounding (thus we mimic underflow after rounding). */
static void
fix_underflow (float x, float y)
{
  if (__builtin_fabsf (y) != 0x1p-126f)
    return;
  if (underflow_before) {
    if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) == 0)
      feclearexcept (FE_UNDERFLOW);
    return;
  }
  mpfr_t t;
  mpfr_init2 (t, 24);
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  mpfr_set_flt (t, x, MPFR_RNDN); // exact
  /* mpfr_set_d might raise the processor underflow/overflow/inexact flags
     (https://gitlab.inria.fr/mpfr/mpfr/-/issues/2) */
  fesetexceptflag (&flag, FE_ALL_EXCEPT); // restore flags
  mpfr_function_under_test (t, t, rnd2[rnd]);
  /* don't call mpfr_subnormalize here since we precisely want an unbounded
     exponent */
  mpfr_abs (t, t, MPFR_RNDN); // exact
#if MPFR_VERSION_MAJOR<4 || (MPFR_VERSION_MAJOR==4 && MPFR_VERSION_MINOR<=2)
  if (mpfr_cmp_ui_2exp (t, 1, -126) == 0) // |o(f(x))| = 2^-126
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
#endif
  mpfr_clear (t);
}

static void
doit (uint32_t n)
{
  float x, y, z;
  x = asfloat (n);
  ref_init ();
  ref_fesetround (rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
  y = ref_function_under_test (x);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
  mpfr_flags_t inex_y = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround (rnd1[rnd]);
  feclearexcept (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif
  z = cr_function_under_test (x);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex_z = fetestexcept (FE_INEXACT);
#endif
  /* Note: the test y != z would not distinguish +0 and -0, instead we compare
     the 32-bit encodings. */
  if (!is_equal (y, z))
  {
    printf ("FAIL x=%a ref=%a y=%a\n", (double) x, (double) y, (double) z);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  /* When there is underflow but the result is exact, IEEE 754-2019 says the
     underflow exception should not be signaled. However MPFR raises the
     underflow exception in this case: we clear it to mimic IEEE 754-2019. */
  if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_INEXACT))
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);

  fix_underflow (x, y);

  // check spurious/missing underflow
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Spurious underflow exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Missing underflow exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }

  // check spurious/missing overflow
  if (fetestexcept (FE_OVERFLOW) && !mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Spurious overflow exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Missing overflow exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }

  // check inexact exception
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex_y == 0) && (inex_z != 0))
  {
    printf ("Spurious inexact exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }
  if ((inex_y != 0) && (inex_z == 0))
  {
    printf ("Missing inexact exception for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
    if (!keep) exit (1);
  }
#endif

  // check errno
#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x is a normal number and y is NaN, we should have errno = EDOM.
  if (!is_nan (x) && !is_inf (x))
  {
    if (is_nan (y) && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%a (y=%a)\n",
              (double) x, (double) y);
      fflush (stdout);
      if (!keep) exit (1);
    }
    if (!is_nan (y) && errno == EDOM)
    {
      printf ("Spurious errno=EDOM for x=%a (y=%a)\n",
              (double) x, (double) y);
      fflush (stdout);
      if (!keep) exit (1);
    }
    int expected_erange = (is_inf (y) && inex_y == 0) ||
      mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
      mpfr_flags_test (MPFR_FLAGS_UNDERFLOW);
    if (expected_erange && errno != ERANGE)
    {
      printf ("Missing errno=ERANGE for x=%a (y=%a)\n",
              (double) x, (double) y);
      fflush (stdout);
      if (!keep) exit (1);
    }
    if (!expected_erange && errno == ERANGE)
    {
      printf ("Spurious errno=ERANGE for x=%a (y=%a)\n",
              (double) x, (double) y);
      fflush (stdout);
      if (!keep) exit (1);
    }
  }
#endif
}

// When x is a NaN, returns 1 if x is an sNaN and 0 if it is a qNaN
static inline int is_signaling(float x) {
  union_t _x = {.f = x};

  return !(_x.n & (1ull << 22));
}

/* check for signaling NaN input */
static void
check_signaling_nan (void)
{
  // Signaling NaNs have encoding from 0x7f800001 to 0x7fbfffff
  float snan;
  for (uint32_t u = 0x7f800001ul; u < 0x7fc00000ul; u++) {
    snan = asfloat (u);
    float y = cr_function_under_test (snan);
    // check that foo(NaN) = NaN
    if (!is_nan (y))
    {
      fprintf (stderr, "Error, foo(sNaN=%x) should be NaN, got %a=%x\n",
               u, (double) y, asuint (y));
      exit (1);
    }
    // check that the signaling bit disappeared
    if (is_signaling (y))
    {
      fprintf (stderr, "Error, foo(sNaN=%x) should be qNaN, got sNaN=%x\n",
               u, asuint (y));
      exit (1);
    }
    // also test sNaN with sign bit set
    uint32_t v = 0x80000000ul + u;
    snan = asfloat (v);
    y = cr_function_under_test (snan);
    // check that foo(NaN) = NaN
    if (!is_nan (y))
    {
      fprintf (stderr, "Error, foo(sNaN=%x) should be NaN, got %a=%x\n",
               v, (double) y, asuint (y));
      exit (1);
    }
    // check that the signaling bit disappeared
    if (is_signaling (y))
    {
      fprintf (stderr, "Error, foo(sNaN=%x) should be qNaN, got sNaN=%x\n",
               v, asuint (y));
      exit (1);
    }
  }
}

static void
check_exceptions_aux (uint32_t n)
{
  float x = asfloat (n);
  feclearexcept (FE_INEXACT);
  float y = cr_function_under_test (x);
  int inex = fetestexcept (FE_INEXACT);
  // there should be no inexact exception if the result is NaN, +/-Inf or +/-0
  if (inex && (is_nan (y) || is_inf (y) || y == 0))
  {
    fprintf (stderr, "Error, for x=%a=%x, inexact exception set (y=%a=%x)\n",
             (double) x, asuint (x), (double) y, asuint (y));
    exit (1);
  }
  feclearexcept (FE_OVERFLOW);
  y = cr_function_under_test (x);
  inex = fetestexcept (FE_OVERFLOW);
  if (inex)
  {
    fprintf (stderr, "Error, for x=%a, overflow exception set (y=%a)\n",
             (double) x, (double) y);
    exit (1);
  }
  feclearexcept (FE_UNDERFLOW);
  y = cr_function_under_test (x);
  inex = fetestexcept (FE_UNDERFLOW);
  if (inex)
  {
    fprintf (stderr, "Error, for x=%a, underflow exception set (y=%a)\n",
             (double) x, (double) y);
    exit (1);
  }

  /* Check that all flags are not reset */
  // check underflow flag is not reset
  feraiseexcept (FE_UNDERFLOW);
  y = cr_function_under_test(x);
  if (!fetestexcept (FE_UNDERFLOW)){
    printf ("Underflow exception was reset for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check divbyzero flag is not reset
  feraiseexcept (FE_DIVBYZERO);
  y = cr_function_under_test(x);
  if (!fetestexcept (FE_DIVBYZERO)){
    printf ("Division by zero exception was reset for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check inexact flag is not reset
  feraiseexcept (FE_INEXACT);
  y = cr_function_under_test(x);
  if (!fetestexcept (FE_INEXACT)){
    printf ("Inexact exception was reset for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check invalid flag is not reset
  feraiseexcept (FE_INVALID);
  y = cr_function_under_test(x);
  if (!fetestexcept (FE_INVALID)){
    printf ("Invalid exception was reset for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }

  // check overflow flag is not reset
  feraiseexcept (FE_OVERFLOW);
  y = cr_function_under_test(x);
  if (!fetestexcept (FE_OVERFLOW)){
    printf ("Overflow exception was reset for x=%a (y=%a)\n",
            (double) x, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
  exit(1);
#endif
  }
}

// check that no overflow/underflor/inexact is set for input NaN, Inf, 0
// when the output is also NaN, Inf, 0
static void
check_exceptions (void)
{
	// checking all Inf, sNaN, qNaN, 0
	for (uint32_t u = 0x7f800000; u <= 0x80000000; u++) {
		check_exceptions_aux (u);
		check_exceptions_aux (u ^ 0x80000000); // -u
	}
}

static int doloop (void)
{
  // checking all Inf, sNaN and qNaN
	for (uint32_t u = 0x7f800000; u < 0x80000000; u++) {
		doit (u);
		doit (u ^ 0x80000000); // -u
	}

  check_signaling_nan ();

  check_exceptions ();

  // check regular numbers
  uint32_t nmin = asuint (0x0p0f), nmax = asuint (0x1.fffffep+127f);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
  /* Use a static schedule with small chunks, since the function might be
     very easy to evaluate in some ranges, for example log of x < 0. */
#pragma omp parallel for schedule(static,1024)
#endif
  for (uint32_t n = nmin; n <= nmax; n++)
  {
    doit (n);
    doit (n | 0x80000000);
  }
  printf ("all ok\n");
  return 0;
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
      else if (strcmp (argv[1], "--keep") == 0)
        {
          keep = 1;
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

  return doloop();
}
