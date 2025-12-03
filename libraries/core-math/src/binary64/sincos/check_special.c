/* Check sincos on random inputs.

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
#include <errno.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

int ref_init (void);
int ref_fesetround (int);

void cr_sincos (double, double*, double*);
void ref_sincos (double, double*, double*);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;

#define MAX_THREADS 192

static unsigned int Seed[MAX_THREADS];

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

typedef union {double f; uint64_t u;} b64u64_u;

static double
get_random (int tid)
{
  b64u64_u v;
  v.u = rand_r (Seed + tid);
  v.u |= (uint64_t) rand_r (Seed + tid) << 31;
  v.u |= (uint64_t) rand_r (Seed + tid) << 62;
  return v.f;
}

static inline double
asfloat64 (uint64_t i)
{
  b64u64_u u = {.u = i};
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

static void
check (double x)
{
  int bug;
  double s1, c1, s2, c2;
  ref_init ();
  ref_fesetround (rnd);
  ref_sincos (x, &s1, &c1);
  fesetround (rnd1[rnd]);
  cr_sincos (x, &s2, &c2);
  if (isnan (s1))
    bug = !isnan (s2);
  else if (isnan (s2))
    bug = !isnan (s1);
  else
    bug = asuint64 (s1) != asuint64 (s2);
  if (bug)
  {
    printf ("FAIL x=%la sin: ref=%la z=%la\n", x, s1, s2);
    fflush (stdout);
    exit (1);
  }
  if (isnan (c1))
    bug = !isnan (c2);
  else if (isnan (c2))
    bug = !isnan (c1);
  else
    bug = asuint64 (c1) != asuint64 (c2);
  if (bug)
  {
    printf ("FAIL x=%la cos: ref=%la z=%la\n", x, c1, c2);
    fflush (stdout);
    exit (1);
  }
}

static void
check_invalid (void)
{

  double inf = asfloat64 (0x7ff0000000000000ull);
  double minInf = asfloat64 (0xfff0000000000000ull);
  double sNan = asfloat64 (0x7ff0000000000001ull);
  double minsNan = asfloat64 (0xfff0000000000001ull);
  double qNan = asfloat64 (0x7ff8000000000000ull);
  double minqNan = asfloat64 (0xfff8000000000000ull);
  double s, c;

  // check Inf
  feclearexcept (FE_INVALID);
  cr_sincos (inf, &s, &c);
  // check the invalid exception was set
  int flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x=Inf\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  // Check minInf
  feclearexcept (FE_INVALID);
  cr_sincos (minInf, &s, &c);
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x=-Inf\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // Check sNaN
  feclearexcept (FE_INVALID);
  cr_sincos (sNan, &s, &c);
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x=sNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  // check EDOM
  // If sNaN is a normal number and s or c is NaN, we should have errno = EDOM.
  int expected_edom = !is_nan (sNan) && (is_nan (s) || is_nan (c));
  if (expected_edom && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%la (s=%la)  (c=%la)\n", sNan, s, c);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }

  // Check -sNaN
  feclearexcept (FE_INVALID);
  cr_sincos (minsNan, &s, &c);
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (!flag)
  {
    printf ("Missing invalid exception for x=-sNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  // check EDOM
  // If -sNaN is a normal number and s or c is NaN, we should have errno = EDOM.
  expected_edom = !is_nan (minsNan) && (is_nan (s) || is_nan (c));
  if (expected_edom && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%la (s=%la)  (c=%la)\n", minsNan, s, c);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }

  // Check qNaN
  feclearexcept (FE_INVALID);
  cr_sincos (qNan, &s, &c);
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Missing invalid exception for x=qNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  // check EDOM
  // If qNaN is a normal number and s or c is NaN, we should have errno = EDOM.
  expected_edom = !is_nan (qNan) && (is_nan (s) || is_nan (c));
  if (expected_edom && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%la (s=%la)  (c=%la)\n", qNan, s, c);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
#endif
    }

  // Check -qNaN
  feclearexcept (FE_INVALID);
  cr_sincos (minqNan, &s, &c);
  // check the invalid exception was set
  flag = fetestexcept (FE_INVALID);
  if (flag)
  {
    printf ("Missing invalid exception for x=-qNaN\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  // check EDOM
  // If -qNaN is a normal number and s or c is NaN, we should have errno = EDOM.
  expected_edom = !is_nan (minqNan) && (is_nan (s) || is_nan (c));
  if (expected_edom && errno != EDOM)
    {
      printf ("Missing errno=EDOM for x=%la (s=%la)  (c=%la)\n", minqNan, s, c);
      fflush (stdout);
#ifndef DO_NOT_ABORT
      exit(1);
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

  check_invalid ();

#define N 1000000000UL /* total number of tests */

  unsigned int seed = getpid ();
  srand (seed);

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t n = 0; n < N; n++)
  {
    double x;
    int tid;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
    tid = omp_get_thread_num ();
#else
    tid = 0;
#endif
    x = get_random (tid);
    check (x);
  }

  return 0;
}
