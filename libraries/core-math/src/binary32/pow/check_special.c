/* Generate special cases for powf testing.

Copyright (c) 2022-2023 Stéphane Glondu and Paul Zimmermann, Inria.

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
#include <unistd.h>
#include <fenv.h>
#include <mpfr.h>
#include <math.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

float cr_powf (float, float);
float ref_pow (float, float);
int ref_fesetround (int);
void ref_init (void);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;

int mid = 1; // if mid=1, also check midpoint cases

typedef union {float f; uint32_t u;} b32u32_u;

static inline uint32_t
asuint (float f)
{
  b32u32_u v = {.f = f};
  return v.u;
}

static inline float
asfloat (uint32_t u)
{
  b32u32_u v = {.u = u};
  return v.f;
}

// this code was contributed by Adhemerval Zanella
// (rand_state, wyhash64, init_rand_state)
static __thread uint64_t rand_state;

static uint64_t wyhash64 (void)
{
  rand_state += 0x60bee2bee120fc15;
  __uint128_t tmp;
  tmp = (__uint128_t) rand_state * 0xa3b195354a39b70d;
  uint64_t m1 = (tmp >> 64) ^ tmp;
  tmp = (__uint128_t)m1 * 0x1b03738712fad5c9;
  uint64_t m2 = (tmp >> 64) ^ tmp;
  return m2;
}

static void
init_rand_state (int seed)
{
  rand_state = seed;
}

static float
get_random (void)
{
  b32u32_u v = {.u = wyhash64 ()};
  return v.f;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) != 0;
}

static inline int
is_qnan (float x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u & 0x400000) != 0;
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

static void
check (float x, float y)
{
  float z1, z2;
  ref_init();
  ref_fesetround(rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  z1 = ref_pow(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround(rnd1[rnd]);
  feclearexcept (FE_INEXACT);
  z2 = cr_powf(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
#endif
  if (!is_equal (z1, z2)) {
    printf("FAIL x,y=%a,%a ref=%a z=%a\n", x, y, z1, z2);
    fflush(stdout);
    exit(1);
  }
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x=%a y=%a (z=%a)\n", x, y, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x=%a y=%a (z=%a)\n", x, y, z1);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
#endif
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000ul // total number of tests
#endif

static void
check_random (int seed, int nthreads)
{
  init_rand_state (seed);

  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  float x, y;
  for (uint64_t n = 0; n < CORE_MATH_TESTS; n += nthreads)
  {
    x = get_random ();
    y = get_random ();
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
#pragma omp parallel for
  for (int i = 0; i < nthreads; i++)
    check_random (getpid () + i, nthreads);
}

// check exact and midpoint values
static void
check_exact_or_midpoint (void)
{
  float zmin = 0x1p-149f;
  float zmax = 0x1.fffffep+12f;
  // max_pow[n] is the largest x such that x^n fits in 25 bits
  float max_pow[] = {0, 0, 5792, 322, 76, 31, 17, 11, 8, 6, 5, 4, 4, 3, 3, 3};
  // max_m[ey] is the largest m such that m^(2^ey) fits in 24 bits
  float max_m[] = {0x1.fffffep+23f, 0x1.ffep+11f, 0x1.f8p+5f, 0x1.cp+2f};
  for (int ey = 3; ey >= 0; ey--)
  {
    int dn = (ey == 0) ? 1 : 2; // for ey > 0, we can restrict to odd n
    int d = 1 << ey; // denominator of y
    for (int n = 15; n >= 2; n -= dn)
    {
      float y = (float) n / (float) d;
      float xmin = powf (zmin, 1.0f / y);
      float xmax = powf (zmax, 1.0f / y);
      for (float m = 3.0f; m <= max_pow[n] && m <= max_m[ey]; m += 2.0f)
      {
        // x = m^d*2^e with m odd and e divisible by d
        float md = powf (m, d);
        float tmin = xmin / md;
        float tmax = xmax / md;
        // we want tmin <= 2^e <= tmax
        int emin, emax;
        frexpf (tmin, &emin); // 2^(emin-1) <= tmin < 2^emin
        frexpf (tmax, &emax); // 2^(emax-1) <= tmax < 2^emax
        // we want emin divisible by d
        while (emin % d) emin++;
#pragma omp parallel for
        for (int e = emin; e <= emax; e += d)
        {
          ref_init();
          ref_fesetround(rnd);
          fesetround(rnd1[rnd]);
          float x = ldexpf (md, e);
          check (x, y);
        }
      }
    }
  }
}

static void
check_signaling (void)
{
  /* Added volatile as workaround for gcc bug, where with -O1 or higher,
     the instruction z = cr_powf (x, y) does not seem to call cr_powf(). */
  volatile float x, y, z;

  // check 1^sNaN gives qNaN
  x = 1.0f;
  y = asfloat ((0xff << 23) + 1);
  z = cr_powf (x, y);
  if (!is_qnan (z))
  {
    fprintf (stderr, "Error for 1^sNaN, expected qNaN, got %a [%x]\n",
             z, asuint (z));
    exit (1);
  }

  // check sNaN^0 gives qNaN
  x = asfloat ((0xff << 23) + 1);
  y = 0.0f;
  z = cr_powf (x, y);
  if (!is_qnan (z))
  {
    fprintf (stderr, "Error for sNaN^0, expected qNaN, got %a [%x]\n",
             z, asuint (z));
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

  printf ("Checking signaling NaN\n");
  check_signaling ();

  printf ("Checking random values\n");
  check_random_all ();

  printf ("Checking exact and midpoint values\n");
  check_exact_or_midpoint ();

  return 0;
}
