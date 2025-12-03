/* Generate special cases for exp2l testing.

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
#include <unistd.h>
#include <math.h> // for ldexpl
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

int ref_fesetround (int);
void ref_init (void);

long double cr_exp2l (long double);
long double ref_exp2l (long double);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;

// only the lower 16 bits of e are used
// 1.0 has encoding m=2^63, e=16383
// -1.0 has encoding m=2^63, e=49151
// 2 has encoding m=2^63, e=16384
// +qnan has encoding m=2^63+2^62, e=32767
// -qnan has encoding m=2^63+2^62, e=65535
// +inf has encoding m=2^63, e=32767
// -inf has encoding m=2^63, e=65535
// +snan has encoding m=2^63+2^62-1, e=32767
// -snan has encoding m=2^63+2^62-1, e=65535
typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

#define MAX_THREADS 192

static unsigned int Seed[MAX_THREADS];

static int
is_nan (long double x)
{
  b80u80_t v = {.f = x};
  return ((v.e == 0x7fff || v.e == 0xffff) && (v.m != (1ul << 63)));
}

static inline int
is_equal (long double x, long double y)
{
  if (is_nan (x))
    return is_nan (y);
  if (is_nan (y))
    return is_nan (x);
  return x == y;
}

static void
check (long double x)
{
  long double y1 = ref_exp2l (x);
  fesetround (rnd1[rnd]);
  long double y2 = cr_exp2l (x);
  if (! is_equal (y1, y2))
  {
    printf ("FAIL x=%La ref=%La z=%La\n", x, y1, y2);
    fflush (stdout);
    exit (1);
  }
}

static long double
get_random (int tid)
{
  b80u80_t v;
  v.m = rand_r (Seed + tid);
  v.m |= (uint64_t) rand_r (Seed + tid) << 31;
  v.m |= (uint64_t) (rand_r (Seed + tid) & 1) << 62;
  // the low 63 bits of m are random
  v.e = rand_r (Seed + tid) & 0xffff;
  // if e is not 0 nor 0x8000 (0 or subnormal), m should have its most
  // significant bit set, otherwise it should be cleared
  // cf https://en.wikipedia.org/wiki/Extended_precision
  uint64_t t = (v.e & 0x7fff) != 0;
  v.m |= t << 63;
  return v.f;
}

static void
check_exact (void)
{
  for (int e = -16445; e < 16384; e++)
    check ((long double) e);
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

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

  printf ("Checking exact cases\n");
  check_exact ();

  printf ("Checking results in subnormal range\n");
  /* check subnormal results */
  /* x0 is the smallest x such that 2^-16446 <= RN(2^-x) */
  long double x0 = 16446;
  /* x1 is the smallest x such that 2^-16384 <= RN(2^-x) */
  long double x1 = 16384;
  /* in the [x0,x1) range, floating-point numbers have an integer part
     of 15 bits, thus we multiply by 2^49 to get integers, where 49 = 64-15 */
  uint64_t n0 = ldexpl (x0, 49);
  uint64_t n1 = ldexpl (x1, 49);
  uint64_t skip = (n1 - n0) / CORE_MATH_TESTS + 1;
  n0 -= getpid () % skip;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t n = n0; n > n1; n -= skip)
    check (-ldexpl ((long double) n, -49));
  /* x2 is the smallest x such that 2^-16382 <= RN(2^-x) */
  long double x2 = 16382;
  /* in the [x1,x2) range, floating-point numbers have an integer part
     of 14 bits, thus we multiply by 2^50 to get integers, where 50 = 64-14 */
  n1 = ldexpl (x1, 50);
  uint64_t n2 = ldexpl (x2, 50);
  skip = (n2 - n1) / CORE_MATH_TESTS + 1;
  n1 -= getpid () % skip;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t n = n1; n > n2; n -= skip)
    check (-ldexpl ((long double) n, -50));

  printf ("Checking random values\n");

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
    long double x = get_random (tid);
    check (x);
  }

  return 0;
}
