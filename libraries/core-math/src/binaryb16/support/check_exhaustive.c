/* Check correctness of bivariate bfloat16 function by exhaustive search.

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

__bf16 cr_function_under_test (__bf16, __bf16);
__bf16 ref_function_under_test (__bf16, __bf16);
int mpfr_function_under_test (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t);
int ref_fesetround (int);
void ref_init (void);

/* the code below is to check correctness by exhaustive search */

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };
int rnd2[] = { MPFR_RNDN,    MPFR_RNDZ,     MPFR_RNDU, MPFR_RNDD   };

int rnd = 0;

typedef union { uint16_t n; __bf16 x; } union_t;

__bf16
asfloat (uint16_t n)
{
  union_t u;
  u.n = n;
  return u.x;
}

static inline uint16_t
asuint (__bf16 f)
{
	union_t u;
	u.x = f;
	return u.n;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (__bf16 x)
{
  // +snan is encoded as 0x7f81 to 0x7fbf
  // +qnan is encoded as 0x7fc0 to 0x7fff
  uint16_t u = asuint (x);
  int e = u >> 7;
  return (e == 0xff || e == 0x1ff) && (u & 0x7f) != 0;
}

/* define our own is_inf function to avoid depending from math.h */
/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (__bf16 x)
{
  // +Inf is encoded as 0x7f80, and -Inf as 0xff80
  uint16_t u = asuint (x);
  int e =  u >> 7;
  return (e == 0xff || e == 0x1ff) && (u & 0x7f) == 0;
}

static int
is_equal (__bf16 y1, __bf16 y2)
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
fix_underflow (__bf16 x1, __bf16 x2, __bf16 y)
{
  if (__builtin_fabsf (y) != 0x1p-126f)
    return;
  if (underflow_before) {
    if (mpfr_flags_test (MPFR_FLAGS_UNDERFLOW) == 0)
      feclearexcept (FE_UNDERFLOW);
    return;
  }
  mpfr_t t1, t2;
  mpfr_init2 (t1, 11);
  mpfr_init2 (t2, 11);
  fexcept_t flag;
  fegetexceptflag (&flag, FE_ALL_EXCEPT); // save flags
  mpfr_set_flt (t1, (float) x1, MPFR_RNDN); // exact
  mpfr_set_flt (t2, (float) x2, MPFR_RNDN); // exact
  /* mpfr_set_d might raise the processor underflow/overflow/inexact flags
     (https://gitlab.inria.fr/mpfr/mpfr/-/issues/2) */
  fesetexceptflag (&flag, FE_ALL_EXCEPT); // restore flags
  mpfr_function_under_test (t1, t1, t2, rnd2[rnd]);
  /* don't call mpfr_subnormalize here since we precisely want an unbounded
     exponent */
  mpfr_abs (t1, t1, MPFR_RNDN); // exact
#if MPFR_VERSION_MAJOR<4 || (MPFR_VERSION_MAJOR==4 && MPFR_VERSION_MINOR<=2)
  if (mpfr_cmp_ui_2exp (t1, 1, -126) == 0) // |o(f(x,y))| = 2^-126
    mpfr_flags_clear (MPFR_FLAGS_UNDERFLOW);
#endif
  mpfr_clear (t1);
  mpfr_clear (t2);
}

void
doit (uint16_t n1, uint16_t n2)
{
  __bf16 x1, x2, y, z;
  x1 = asfloat (n1);
  x2 = asfloat (n2);
  ref_init ();
  ref_fesetround (rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT | MPFR_FLAGS_UNDERFLOW | MPFR_FLAGS_OVERFLOW);
  y = ref_function_under_test (x1, x2);
#if defined(CORE_MATH_CHECK_INEXACT) || defined(CORE_MATH_SUPPORT_ERRNO)
  mpfr_flags_t inex_y = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround (rnd1[rnd]);
  feclearexcept (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW);
#ifdef CORE_MATH_SUPPORT_ERRNO
  errno = 0;
#endif
  z = cr_function_under_test (x1, x2);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex_z = fetestexcept (FE_INEXACT);
#endif
  /* Note: the test y != z would not distinguish +0 and -0, instead we compare
     the 16-bit encodings. */
  if (!is_equal (y, z))
  {
#ifndef EXCHANGE_X_Y
    printf ("FAIL x,y=%a,%a ref=%a z=%a\n", (double) x1, (double) x2, (double) y, (double) z);
#else
    printf ("FAIL y,x=%a,%a ref=%a z=%a\n", (double) x1, (double) x2, (double) y, (double) z);
#endif
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

  fix_underflow (x1, x2, y);

#ifndef CORE_MATH_NOCHECK_UNDERFLOW
  // check spurious/missing underflow
  if (fetestexcept (FE_UNDERFLOW) && !mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Spurious underflow exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
  if (!fetestexcept (FE_UNDERFLOW) && mpfr_flags_test (MPFR_FLAGS_UNDERFLOW))
  {
    printf ("Missing underflow exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
#endif // CORE_MATH_NOCHECK_UNDERFLOW

#ifndef CORE_MATH_NOCHECK_OVERFLOW
  // check spurious/missing overflow
  if (fetestexcept (FE_OVERFLOW) && !mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Spurious overflow exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
  if (!fetestexcept (FE_OVERFLOW) && mpfr_flags_test (MPFR_FLAGS_OVERFLOW))
  {
    printf ("Missing overflow exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
#endif // CORE_MATH_NOCHECK_OVERFLOW

  // check inexact exception
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex_y == 0) && (inex_z != 0))
  {
    printf ("Spurious inexact exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
  if ((inex_y != 0) && (inex_z == 0))
  {
    printf ("Missing inexact exception for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
   	exit (1);
#endif
  }
#endif

  // check errno
#ifdef CORE_MATH_SUPPORT_ERRNO
  // If x1 and x2 are normal numbers and y is NaN, we should have errno = EDOM.
  if (!is_nan (x1) && !is_inf (x1) && !is_nan (x2) && !is_inf (x2))
  {
    if (is_nan (y) && errno != EDOM)
    {
#ifndef EXCHANGE_X_Y
      printf ("Missing errno=EDOM for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
#else
      printf ("Missing errno=EDOM for y,x=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
#endif
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
    if (!is_nan (y) && errno == EDOM)
    {
      printf ("Spurious errno=EDOM for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
    int expected_erange = (is_inf (y) && inex_y == 0) ||
      mpfr_flags_test (MPFR_FLAGS_OVERFLOW) ||
      mpfr_flags_test (MPFR_FLAGS_UNDERFLOW);
    if (expected_erange && errno != ERANGE)
    {
#ifndef EXCHANGE_X_Y
      printf ("Missing errno=ERANGE for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
#else
      printf ("Missing errno=ERANGE for y,x=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
#endif
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
    if (!expected_erange && errno == ERANGE)
    {
      printf ("Spurious errno=ERANGE for x,y=%a,%a (z=%a)\n", (double) x1, (double) x2, (double) y);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit (1);
#endif
    }
  }
#endif

#ifdef CORE_MATH_CHECK_INEXACT
  // check if the inexact exception was reset
  feraiseexcept (FE_INEXACT);
  y = cr_function_under_test (x1, x2);
  if (!fetestexcept (FE_INEXACT)) {
    printf ("Exception inexact was reset for x,y=%a,%a (z=%a)\n",
            (double) x1, (double) x2, (double) y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif
}

// When x is a NaN, returns 1 if x is an sNaN and 0 if it is a qNaN
static inline int is_signaling(__bf16 x) {
  union_t _x = {.x = x};

  return !(_x.n & (1u << 6));
}

/* check for signaling NaN input */
static void
check_signaling_nan (void)
{
  /* signaling NaNs have encoding 0x7f81 to 0x7fbf */
  __bf16 snan;
  for (uint16_t u1 = 0x7f81u; u1 < 0x7fc0u; u1++) {
    snan = asfloat (u1);
    for (uint32_t u2 = 0; u2 < 0x10000; u2++) {
      __bf16 x2 = asfloat((uint16_t) u2);
      __bf16 y = cr_function_under_test (snan, x2);
      // check that foo(NaN, x) = NaN
      if (!is_nan (y))
      {
      	fprintf (stderr, "Error, foo(sNaN=%x,y=%a) should be NaN, got %a=%x\n",
                 u1, (double) x2, (double) y, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
      // check that the signaling bit disappeared
      if (is_signaling (y))
      {
      	fprintf (stderr, "Error, foo(sNaN=%x,y=%a) should be qNaN, got sNaN=%x\n",
               	 u1, (double) x2, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
      y = cr_function_under_test (x2, snan);
      // check that foo(x, NaN) = NaN
      if (!is_nan (y))
      {
      	fprintf (stderr, "Error, foo(x=%a,sNaN=%x) should be NaN, got %a=%x\n",
                 (double) x2, u1, (double) y, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
    	// check that the signaling bit disappeared
      if (is_signaling (y))
      {
      	fprintf (stderr, "Error, foo(x=%a,sNaN=%x) should be qNaN, got sNaN=%x\n",
               	 (double) x2, u1, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
    }
    // also test sNaN with sign bit set
    snan = asfloat (0x8000 + u1);
    for (uint32_t u2 = 0; u2 < 0x10000; u2++) {
      __bf16 x2 = asfloat((uint16_t) u2);
      __bf16 y = cr_function_under_test (snan, x2);
      // check that foo(NaN, x) = NaN
      if (!is_nan (y))
      {
      	fprintf (stderr, "Error, foo(sNaN=%x,y=%a) should be NaN, got %a=%x\n",
                 u1, (double) x2, (double) y, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
      // check that the signaling bit disappeared
      if (is_signaling (y))
      {
      	fprintf (stderr, "Error, foo(sNaN=%x,y=%a) should be qNaN, got sNaN=%x\n",
               	 u1, (double) x2, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
      y = cr_function_under_test (x2, snan);
      // check that foo(x, NaN) = NaN
      if (!is_nan (y))
      {
      	fprintf (stderr, "Error, foo(x=%a,sNaN=%x) should be NaN, got %a=%x\n",
                 (double) x2, u1, (double) y, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
    	// check that the signaling bit disappeared
      if (is_signaling (y))
      {
      	fprintf (stderr, "Error, foo(x=%a,sNaN=%x) should be qNaN, got sNaN=%x\n",
               	 (double) x2, u1, asuint (y));
#ifndef DO_NOT_ABORT
      	exit (1);
#endif
      }
    }
  }
}

static void
check_exceptions_aux (uint16_t n1, uint16_t n2)
{
  __bf16 x1 = asfloat (n1);
  __bf16 x2 = asfloat (n2);
  feclearexcept (FE_INEXACT);
  __bf16 y = cr_function_under_test (x1, x2);
  int inex = fetestexcept (FE_INEXACT);
  // there should be no inexact exception if the result is NaN, +/-Inf or +/-0
  if (inex && (is_nan (y) || is_inf (y) || y == 0))
  {
#ifndef EXCHANGE_X_Y
    fprintf (stderr, "Error, for x,y=%a,%a, inexact exception set (z=%a)\n",
             (double) x1, (double) x2, (double) y);
#else
    fprintf (stderr, "Error, for y,x=%a,%a, inexact exception set (z=%a)\n",
             (double) x1, (double) x2, (double) y);
#endif
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  feclearexcept (FE_OVERFLOW);
  y = cr_function_under_test (x1, x2);
  inex = fetestexcept (FE_OVERFLOW);
  if (inex)
  {
    fprintf (stderr, "Error, for x,y=%a,%a, overflow exception set (z=%a)\n",
						 (double) x1, (double) x2, (double) y);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  feclearexcept (FE_UNDERFLOW);
  y = cr_function_under_test (x1, x2);
  inex = fetestexcept (FE_UNDERFLOW);
  if (inex)
  {
    fprintf (stderr, "Error, for x,y=%a,%a, underflow exception set (z=%a)\n",
						 (double) x1, (double) x2, (double) y);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

// check that no overflow/underflow/inexact is set for input NaN, Inf, 0
// when the output is also NaN, Inf, 0
static void
check_exceptions (void)
{
  // checking all sNaN, qNaN, Inf, 0
  for (uint16_t u1 = 0x7f80; u1 <= 0x8000; u1++) {
    for (uint32_t u2 = 0; u2 < 0x10000; u2++) {
      check_exceptions_aux (u1, (uint16_t) u2);
      check_exceptions_aux ((uint16_t) u2, u1);
      // checking for -u1
      u1 ^= 0x8000;
      check_exceptions_aux (u1, (uint16_t) u2);
      check_exceptions_aux ((uint16_t) u2, u1);
      // set u1 to u1 instead of -u1
      u1 ^= 0x8000;
    }
  }
}

static int doloop (void)
{
	
  //checking all sNaN, qNaN, Inf
  for (uint16_t u1 = 0x7f81; u1 < 0x8000; u1++) {
    for (uint32_t u2 = 0; u2 < 0x10000; u2++) {
      check_exceptions_aux (u1, (uint16_t) u2);
      check_exceptions_aux ((uint16_t) u2, u1);
      // checking for -u1
      u1 ^= 0x8000;
      check_exceptions_aux (u1, (uint16_t) u2);
      check_exceptions_aux ((uint16_t) u2, u1);
      // set u1 to u1 instead of -u1
      u1 ^= 0x8000;
    }
  }

  check_signaling_nan ();

  check_exceptions ();

  // check regular numbers
  uint16_t nmin = asuint (0x0p0f), nmax = asuint (0x1.fep+127f);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint16_t n1 = nmin; n1 <= nmax; n1++)
    for (uint16_t n2 = nmin; n2 <= nmax; n2++)
  	{
          doit (n1, n2);
          doit (n1 | 0x8000, n2);
          doit (n1, n2 | 0x8000);
          doit (n1 | 0x8000, n2 | 0x8000);
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
      else
        {
          fprintf (stderr, "Error, unknown option %s\n", argv[1]);
          exit (1);
        }
    }

  check_underflow_before ();

  return doloop();
}
