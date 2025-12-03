/* Generate special cases for rsqrt testing.

Copyright (c) 2022-2024 Stéphane Glondu and Paul Zimmermann, Inria.

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
#include <unistd.h>
#include <inttypes.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

int ref_fesetround (int);
void ref_init (void);

double cr_rsqrt (double);
double ref_rsqrt (double);

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
check (double x)
{
  double y1 = ref_rsqrt (x);
  fesetround (rnd1[rnd]);
  double y2 = cr_rsqrt (x);
  if (!is_equal (y1, y2))
  {
    printf ("FAIL x=%la ref=%la z=%la\n", x, y1, y2);
    fflush (stdout);
    exit (1);
  }
}

typedef union {
  double f;
  uint64_t i;
} d64u64;

static double
get_random (int tid)
{
  d64u64 v;
  v.i = rand_r (Seed + tid);
  v.i |= (uint64_t) rand_r (Seed + tid) << 31;
  v.i |= (uint64_t) rand_r (Seed + tid) << 62;
  return v.f;
}

static inline double
asfloat64 (uint64_t i)
{
  d64u64 u = {.i = i};
  return u.f;
}

static void
check_invalid (void)
{
  double zero = asfloat64 (0x0000000000000000);
  double minZero = asfloat64 (0x8000000000000000);

  feclearexcept (FE_DIVBYZERO);
  //Check +0
  double y = cr_rsqrt (zero);

  // check that foo(+0) != NaN
  if (is_nan (y))
  {
    fprintf (stderr, "Error, foo(+0) should not be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
  
  int flag = fetestexcept (FE_DIVBYZERO);
  if(!flag)
  {
    printf("Missing divide by zero exception for x=+0\n");
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }


  // check -0
  feclearexcept (FE_DIVBYZERO);
  y = cr_rsqrt (minZero);

  // check that foo(+0) != NaN
  if (is_nan (y))
  {
    fprintf (stderr, "Error, foo(-0) should not be NaN, got %la=%"PRIx64"\n",
             y, asuint64 (y));
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  flag = fetestexcept (FE_DIVBYZERO);
  if(!flag)
  {
    printf("Missing divide by zero exception for x=-0\n");
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

  ref_init();
  ref_fesetround (rnd);

  check_invalid ();

  printf ("Checking random values\n");
#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

  unsigned int seed = getpid ();
  for (int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t n = 0; n < CORE_MATH_TESTS; n++)
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
