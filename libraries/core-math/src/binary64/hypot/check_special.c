/* Generate special cases for hypot testing.

Copyright (c) 2022-2023 Stéphane Glondu, Paul Zimmermann, Inria.

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
#include <gmp.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <unistd.h>
#include <math.h>
#include <assert.h>

void doloop (int, int);
extern double cr_hypot (double, double);
extern int ref_fesetround (int);
extern void ref_init (void);
extern mpfr_rnd_t rnd2[];
extern double ref_hypot (double, double);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd;
int verbose = 0;

typedef union {double f; uint64_t u;} b64u64_u;

static double
get_random (void)
{
  b64u64_u v;
  int64_t l;
  l = rand ();
  v.u = l;
  l = rand ();
  v.u |= (uint64_t) l << 31;
  l = rand ();
  v.u |= (uint64_t) l << 62;
  return v.f;
}

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
check_aux (double x, double y)
{
  double z, t;
  mpfr_t X, Y, Z;
  mpfr_init2 (X, 53);
  mpfr_init2 (Y, 53);
  mpfr_init2 (Z, 53);
  mpfr_set_d (X, x, MPFR_RNDN);
  mpfr_set_d (Y, y, MPFR_RNDN);
  z = cr_hypot (x, y);
  t = ref_hypot (x, y);
  if (!is_equal (z, t))
  {
    printf ("cr_hypot and ref_hypot differ for x=%la y=%la\n", x, y);
    printf ("cr_hypot  gives %la\n", z);
    printf ("ref_hypot gives %la\n", t);
    exit (1);
  }
  mpfr_clear (X);
  mpfr_clear (Y);
  mpfr_clear (Z);
}

void
check (double x, double y)
{
  check_aux (x, y);
  check_aux (x, -y);
  check_aux (-x, y);
  check_aux (-x, -y);
  check_aux (y, x);
  check_aux (y, -x);
  check_aux (-y, x);
  check_aux (-y, -x);
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 100000000ul // total number of tests
#endif

static void
check_random (int i, int nthreads)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  double x, y;
  srand (i);

  for (uint64_t n = 0; n < CORE_MATH_TESTS; n += nthreads)
  {
    x = get_random ();
    y = get_random ();
    check (x, y);
  }
#undef N
}

static void
check_random_all (void)
{
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads ();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_random (getpid () + i, nthreads);
}

/* check values in underflow region */
static void
check_underflow (void)
{
  double x, y;
  y = 0x1p-1074;
#define N 1000
  for (int i = 0; i < N; i++)
  {
    x = 0x1p-1074;
    for (int j = 0; j < N; j++)
    {
      check (x, y);
      x = nextafter (x, 2 * x);
    }
    y = nextafter (y, 2 * y);
  }
#undef N
}

/* check values with huge exponent difference */
static void
check_large_diff (void)
{
  double x, y;
  y = 0x1p-1074;
#define N 1000
  for (int i = 0; i < N; i++)
  {
    x = 0x1.fffffffffffffp+1023;
    for (int j = 0; j < N; j++)
    {
      check (x, y);
      x = nextafter (x, 0.5 * x);
    }
    y = nextafter (y, 2 * y);
  }
#undef N
}

/* check values in overflow range */
static void
check_overflow (void)
{
  double x, y;
  y = 0x1.fffffffffffffp+1023;
#define N 1000
  for (int i = 0; i < N; i++)
  {
    x = 0x1.fffffffffffffp+1023;
    for (int j = 0; j < N; j++)
    {
      check (x, y);
      x = nextafter (x, 0.5 * x);
    }
    y = nextafter (y, 0.5 * y);
  }
#undef N
}

/* return y' such that sqrt(x^2+y'^2) is closest to the 54-bit number
   closest to sqrt(x^2+y^2) */
static double y_worst (double x, double y)
{
  mpfr_t X, Y, Z;
  mpfr_init2 (X, 192);
  mpfr_init2 (Y, 192);
  mpfr_init2 (Z, 54);
  mpfr_set_d (X, x, MPFR_RNDN);
  mpfr_sqr (X, X, MPFR_RNDN);
  mpfr_set_d (Y, y, MPFR_RNDN);
  mpfr_sqr (Y, Y, MPFR_RNDN);
  mpfr_add (Y, X, Y, MPFR_RNDN);
  mpfr_sqrt (Z, Y, MPFR_RNDN);
  mpfr_prec_round (Z, 192, MPFR_RNDN);
  mpfr_sqr (Z, Z, MPFR_RNDN); // square Z
  mpfr_sub (Z, Z, X, MPFR_RNDN); // subtract X
  mpfr_sqrt (Z, Z, MPFR_RNDN);
  y = mpfr_get_d (Z, MPFR_RNDN);
  mpfr_clear (X);
  mpfr_clear (Y);
  mpfr_clear (Z);
  return y;
}

// i is the thread number
static void
check_worst_i (int m, int i, int nthreads)
{
  ref_init ();
  ref_fesetround (rnd);
  fesetround(rnd1[rnd]);
  double x, y;
  srand (getpid () + i);

  for (uint64_t n = i; n < CORE_MATH_TESTS; n += nthreads)
  {
    int e;
    x = get_random ();
    x = fabs (x);
    x = frexp (x, &e); // 1/2 <= x < 1
    y = get_random ();
    y = frexp (y, &e);
    y = ldexp (y, -m);
    y = y_worst (x, y);
    check (x, y);
  }
}

// check worst cases with exp(y) = exp(x) - i
static void
check_worst (int m)
{
  int nthreads = 1;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel
  nthreads = omp_get_num_threads ();
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int i = 0; i < nthreads; i++)
    check_worst_i (m, i, nthreads);
}

static uint64_t
gcd (uint64_t a, uint64_t b)
{
  while (b != 0)
  {
    uint64_t r = a % b;
    a = b;
    b = r;
  }
  return a;
}

#define STEP 5000

/* Check all Pythagorean triples z^2 = x^2 + y^2 with z in the subnormal
   range. We necessarily have x = r^2 - s^2, y = 2*r*s, z = r^2 + s^2
   with gcd(r,s) = 1 and one of r, s even
   (see https://oeis.org/wiki/Pythagorean_triples).
*/
static void
check_triples_subnormal (void)
{
  /* the smallest denormal is 2^-1074, the smallest normal is 2^-1022,
     thus x, y, z are of the form k*2^-1074 with k < 2^52. */

  srand48 (getpid ());
  uint64_t r0 = lrand48 () % (2 * STEP);
  if ((r0 & 1) == 0)
    r0 ++; // ensures r0 is odd and >= 1
  uint64_t s0 = 1 + (lrand48 () % (2 * STEP));
  if ((s0 & 1) == 1)
    s0 ++; // ensures s0 is even and >= 2

  // type I: r is odd
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t r = r0; r <= 0x4000000; r += 2 * STEP)
  {
    ref_init ();
    ref_fesetround (rnd);
    fesetround(rnd1[rnd]);
    for (uint64_t s = s0; s < r; s += 2 * STEP)
    {
      if (gcd (r, s) == 1)
      {
        uint64_t x = r * r - s * s;
        uint64_t y = 2 * r * s;
        uint64_t z = r * r + s * s;
        if (z > 0xffffffffffffful)
          break;
        // now (x,y,z) is a primitive Pythagorean triple
        for (int n = 1; ; n++)
        {
          uint64_t nn = n * n;
          uint64_t xx = x * nn, yy = y * nn, zz = z * nn;
          if (zz > 0xffffffffffffful)
            break;
          check (ldexp (xx, -1074), ldexp (yy, -1074));
        }
      }
    }
  }

  // type II: r is even
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (uint64_t r = r0+1; r <= 0x4000000; r += 2 * STEP)
  {
    ref_init ();
    ref_fesetround (rnd);
    fesetround(rnd1[rnd]);
    for (uint64_t s = s0-1; s < r; s += 2 * STEP)
    {
      if (gcd (r, s) == 1)
      {
        uint64_t x = r * r - s * s;
        uint64_t y = 2 * r * s;
        uint64_t z = r * r + s * s;
        if (z > 0xffffffffffffful)
          break;
        // now (x,y,z) is a primitive Pythagorean triple
        for (int n = 1; ; n++)
        {
          uint64_t nn = n * n;
          uint64_t xx = x * nn, yy = y * nn, zz = z * nn;
          if (zz > 0xffffffffffffful)
            break;
          check (ldexp (xx, -1074), ldexp (yy, -1074));
        }
      }
    }
  }
}

// check k values below/above each power of 2
static void
check_near_power_two (int k)
{
  double min, max;
  min = max = 1.0;
  for (int i = 0; i < k; i++)
  {
    min = nextafter (min, 0.5);
    max = nextafter (max, 2.0);
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int ex = -1074; ex <= 1024; ex++)
  {
    // since emin,emax are thread-local, we need to initialize them here
    ref_init ();
    ref_fesetround (rnd);
    fesetround(rnd1[rnd]);
    // since "check" also checks y,x, we only test for ey <= ex
    for (int ey = -1074; ey <= ex; ey++)
    {
      double x, y;
      for (x = min; x <= max; x = nextafter (x, 2.0))
        for (y = min; y <= max; y = nextafter (y, 2.0))
          // "check" also checks various signs
          check (ldexp (x, ex), ldexp (y, ey));
    }
  }
}

// return 1 if t = k^2 + c with c in {-1,0,1}
static int
is_near_square (uint64_t t)
{
  t ++;
  uint64_t k = (uint64_t) sqrt ((double) t);
  uint64_t r;
  if (k * k > t) // k too large
  {
    k--;
    assert (k * k <= t);
    r = t - k * k;
  }
  else
  {
    r = t - k * k;
    if (r > 2 * k) // k too small
    {
      k++;
      r = t - k * k;
    }
  }
  assert (r <= 2 * k);
  return r <= 2;
}

#define LIMIT 0x20000000000000ull // 2^53

static void
check_near_exact (void)
{
  // we want LIMIT^2 / skip^2 ~ CORE_MATH_TESTS
  // thus LIMIT/SKIP ~ sqrt(CORE_MATH_TESTS)
  // thus SKIP ~ LIMIT/sqrt(CORE_MATH_TESTS)
  uint64_t u = (uint64_t) sqrt ((double) CORE_MATH_TESTS);
  u = 50 * u; // so that this takes comparable time wrt check_random
  uint64_t skip = (LIMIT >= u) ? LIMIT / u : 1;
  srand (getpid ());
  uint64_t x0 = 2 + (rand () % skip);
  uint64_t y0 = 2 + (rand () % skip);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  for (uint64_t x = x0; x < LIMIT; x += skip)
  {
    ref_init ();
    ref_fesetround (rnd);
    fesetround(rnd1[rnd]);
    for (uint64_t y = y0; y <= x; y += skip)
    {
      uint64_t t = x * x + y * y;
      if (is_near_square (t))
      {
        check ((double) x, (double) y);
        // also check in the subnormal range
        check (ldexp ((double) x, -1074), ldexp ((double) y, -1074));
      }
    }
  }
}

// check k random Pythagorean triples
// x = p^2-q^2 y = 2pq with gcd(p,q)=1 and one of p,q even
static void
check_triples (int k)
{
  mpz_t P, Q;
  gmp_randstate_t state;
  double x, y;
  int64_t p, q;

  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  gmp_randinit_default (state);
  gmp_randseed_ui (state, getpid ());
  mpz_init (P);
  mpz_init (Q);
  while (k--) {
    // if p,q < 2^(53/2) then x and y are representable in binary80
#define MAXP 0x5a82799lu // floor(2^(53/2))
    mpz_urandomb (P, state, 32);
    mpz_urandomb (Q, state, 32);
    p = mpz_get_ui (P) % MAXP;
    q = mpz_get_ui (Q) % MAXP;
    x = p * p - q * q;
    y = 2 * p * q;
    check (x, y);
  }
  mpz_clear (P);
  mpz_clear (Q);
  gmp_randclear (state);
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
  fesetround(rnd1[rnd]);

  printf ("Checking Pythagorean triples\n");
  check_triples (1000000);

  printf ("Checking near-exact values\n");
  fflush (stdout);
  check_near_exact ();

  printf ("Checking values near 2^e\n");
  check_near_power_two (2);

  printf ("Checking exact subnormal values\n");
  check_triples_subnormal ();

  printf ("Checking worst cases with exp(y) = exp(x) - m\n");
  for (int m = 1; m <= 27; m++)
    check_worst (m);

  printf ("Checking in underflow range\n");
  check_underflow ();

  printf ("Checking values with large exponent difference\n");
  check_large_diff ();

  printf ("Checking in overflow range\n");
  check_overflow ();

  printf ("Checking random values\n");
  check_random_all ();

  printf ("Checking near overflow, underflow and Pythagorean triples\n");
  /* we check triples with exponent difference 0 <= k <= 26 */
  doloop(0, 26);
  return 0;
}
