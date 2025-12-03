/* Generate special cases for rsqrtl testing.

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
#include <mpfr.h>
#include <unistd.h>
#include <math.h> // for ldexpl, rsqrtl
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

int ref_fesetround (int);
void ref_init (void);

long double cr_rsqrtl (long double);
long double ref_rsqrtl (long double);

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
  b80u80_t v = {.f = x}, w = {.f = y};
  return v.e == w.e && v.m == w.m; // ensures +0 and -0 differ
}

static void
check (long double x)
{
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  long double y1 = ref_rsqrtl (x);
#ifdef CORE_MATH_CHECK_INEXACT
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround (rnd1[rnd]);
  feclearexcept (FE_INEXACT);
  long double y2 = cr_rsqrtl (x);
  int inex2 = fetestexcept (FE_INEXACT);
  if (! is_equal (y1, y2))
  {
    printf ("FAIL x=%La ref=%La z=%La\n", x, y1, y2);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x=%La (y=%La)\n", x, y1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x=%La (y=%La)\n", x, y1);
    fflush (stdout);
#ifdef DO_NOT_ABORT
    return 1;
#else
    exit(1);
#endif
  }
#endif
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

// check exact values
static void
check_exact (void)
{
  /* The only exact values for 1/sqrt(x) are when sqrt(x) is a power of 2,
     thus x = 2^(2*k). */
#pragma omp parallel for
  for (int e = -16444; e < 16384; e+=2)
  {
    long double x;
    x = ldexpl ((long double) 1.0, e);
    check (x);
  }
}

static void
readstdin(long double **result, int *count)
{
  char *buf = NULL;
  size_t buflength = 0;
  ssize_t n;
  int allocated = 512;

  *count = 0;
  if (NULL == (*result = malloc(allocated * sizeof(long double)))) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  while ((n = getline(&buf, &buflength, stdin)) >= 0) {
    if (n > 0 && buf[0] == '#') continue;
    if (*count >= allocated) {
      int newsize = 2 * allocated;
      long double *newresult = realloc(*result, newsize * sizeof(long double));
      if (NULL == newresult) {
        fprintf(stderr, "realloc(%d) failed\n", newsize);
        exit(1);
      }
      allocated = newsize;
      *result = newresult;
    }
    long double *item = *result + *count;
    // special code for snan, since glibc does not read them
    if (strncmp (buf, "snan", 4) == 0 || strncmp (buf, "+snan", 5) == 0)
    {
      b80u80_t v;
      // +snan has encoding m=2^63+1, e=32767 (for example)
      v.e = 0x7fff;
      v.m = 0x8000000000000001ul;
      *item = v.f;
      (*count)++;
    }
    else if (strncmp (buf, "-snan", 5) == 0)
    {
      b80u80_t v;
      // -snan has encoding m=2^63+1, e=65535 (for example)
      v.e = 0xffff;
      v.m = 0x8000000000000001ul;
      *item = v.f;
      (*count)++;
    }
    else if (sscanf(buf, "%La", item) == 1)
    {
      (*count)++;
    }
  }
  free (buf);
}

/* for worst-cases in [0.5,2), check all values x*2^(2k) that are in
   [2^-16445, 2^16384) */
static void
check_extended (long double x)
{
  if (is_nan (x) || x < 0.5L || 2.0L <= x) // avoid NaN and x not in [0.5,2)
    return;

  int e, emin, emax;
  emin = -16444;
  emax = 16384;
  for (e = emin; e <= emax; e+=2)
    check (ldexpl (x, e));
}

/* check scaled worst-cases from rsqrtl.wc */
static void
check_scaled_worst_cases (void)
{
  long double *items;
  int count;
  readstdin (&items, &count);
#ifndef CORE_MATH_NO_OPENMP
#pragma omp parallel for
#endif
  for (int i = 0; i < count; i++) {
    ref_init();
    ref_fesetround(rnd);
    fesetround(rnd1[rnd]);
    long double x = items[i];
    check_extended (x);
  }
  free (items);
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

  printf ("Checking exact values\n");
  check_exact ();

  printf ("Checking scaled worst cases\n");
  check_scaled_worst_cases ();

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

  printf ("Checking random values\n");

  unsigned int seed = getpid ();
  for (int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;

#pragma omp parallel for
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
