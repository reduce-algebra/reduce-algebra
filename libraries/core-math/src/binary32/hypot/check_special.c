/* Generate special cases for hypotf testing.

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
#include <math.h>
#include <gmp.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <assert.h>

int ref_fesetround (int);
void ref_init (void);

// triples.c
extern void doloop (int, int);
extern void check (float, float);
extern uint64_t gcd (uint64_t, uint64_t);
float cr_hypotf (float, float);

// worst_p1.c
extern void doit_subnormal_above (uint32_t);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;

/* Check all Pythagorean triples z^2 = x^2 + y^2 with z in the subnormal
   range. We necessarily have x = r^2 - s^2, y = 2*r*s, z = r^2 + s^2
   with gcd(r,s) = 1 and one of r, s even
   (see https://oeis.org/wiki/Pythagorean_triples).
*/
static void
check_triples_subnormal (void)
{
  uint64_t r, s, x, y, z;
  /* the smallest denormal is 2^-149, the smallest normal is 2^-126,
     thus x, y, z are of the form k*2^-149 with k < 2^23. */

  // type I: r is odd
  for (r = 1; r <= 2896; r += 2)
    for (s = 2; s < r; s += 2)
    {
      if (gcd (r, s) == 1)
      {
        x = r * r - s * s;
        y = 2 * r * s;
        z = r * r + s * s;
        if (z > 0x7fffff)
          break;
        // now (x,y,z) is a primitive Pythagorean triple
        for (int n = 1; ; n++)
        {
          uint64_t nn = n * n;
          uint64_t xx = x * nn, yy = y * nn, zz = z * nn;
          if (zz > 0x7fffff)
            break;
          check (ldexpf (xx, -149), ldexpf (yy, -149));
        }
      }
    }

  // type II: r is even
  for (r = 2; r <= 2896; r += 2)
    for (s = 1; s < r; s += 2)
    {
      if (gcd (r, s) == 1)
      {
        x = r * r - s * s;
        y = 2 * r * s;
        z = r * r + s * s;
        if (z > 0x7fffff)
          break;
        // now (x,y,z) is a primitive Pythagorean triple
        for (int n = 1; ; n++)
        {
          uint64_t nn = n * n;
          uint64_t xx = x * nn, yy = y * nn, zz = z * nn;
          if (zz > 0x7fffff)
            break;
          check (ldexpf (xx, -149), ldexpf (yy, -149));
        }
      }
    }
}

/* Check pairs (x,y) in subnormal range such that x = u*2^-149, y = v*2^-149,
   with u^2 + v^2 = w^2 + 1, u <= v. We force 2 <= u to avoid the trivial
   solutions u=1, v=w. See https://oeis.org/A050796. */
static void
check_triples_subnormal_above (void)
{
  doit_subnormal_above (8388608);
}

typedef union {float f; uint32_t u;} b32u32_u;

static float
get_random (void)
{
  b32u32_u v;
  int64_t l;
  l = rand ();
  v.u = l;
  // rand() generates only 31 bits
  l = rand ();
  v.u |= (uint32_t) l << 31;
  return v.f;
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000ul // total number of tests
#endif

static void
check_random (int seed, int nthreads)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  float x, y;
  srand (seed);
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
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_random (getpid () + i, nthreads);
}

// return 1 if t = k^2 + c with c in {-1,0,1}
static int
is_near_square (uint64_t t)
{
  t ++;
  uint64_t k = (uint64_t) sqrt ((double) t);
  uint64_t r;
  if (k * k > t)
  {
    k--;
    assert (k * k <= t);
    r = t - k * k;
  }
  else
    r = t - k * k;
  assert (r <= 2 * k);
  return r <= 2;
}

#define LIMIT 0x1000000ull // 2^24

static void
check_near_exact (void)
{
  uint64_t nx = CORE_MATH_TESTS / LIMIT; // wanted number of tested x-values
  if (nx == 0)
    nx = 1;
  nx = nx * 20000; // so that this takes comparable time wrt check_random
  uint64_t skip = (nx > LIMIT) ? 1 : LIMIT / nx;
  uint64_t x0 = 2 + (getpid () % skip);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  for (uint64_t x = x0; x < LIMIT; x += skip)
  {
    for (uint64_t y = 2; y <= x; y++)
    {
      uint64_t t = x * x + y * y;
      if (is_near_square (t))
      {
        check ((float) x, (float) y);
        // also check in the subnormal range
        check (ldexpf ((float) x, -149), ldexpf ((float) y, -149));
      }
    }
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

  printf ("Checking near-exact values\n");
  fflush (stdout);
  check_near_exact ();

  printf ("Checking random values\n");
  fflush (stdout);
  check_random_all ();

  /* we check triples with exponent difference 0 <= k <= 12 */
  printf ("Checking near-exact subnormal values\n");
  fflush (stdout);
  check_triples_subnormal_above ();
  printf ("Checking exact subnormal values\n");
  fflush (stdout);
  check_triples_subnormal ();
  printf ("Checking Pythagorean triples\n");
  fflush (stdout);
  doloop(0, 12);
  return 0;
}
