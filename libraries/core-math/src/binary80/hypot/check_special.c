/* Generate special cases for hypotl testing.

Copyright (c) 2024-2025 Sélène Corbineau and Paul Zimmermann, Inria.

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

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000UL /* total number of tests */
#endif

void doloop (int, int);
extern long double cr_hypotl (long double, long double);
extern int ref_fesetround (int);
extern void ref_init (void);
extern mpfr_rnd_t rnd2[];
extern long double ref_hypotl (long double, long double);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd;
int verbose = 0;

typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

#define MAX_THREADS 192

static unsigned int Seed[MAX_THREADS];

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

/* define our own is_nan function to avoid depending from math.h */
static inline int
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
  return v.e == w.e && v.m == w.m;
}

static void
check_aux (long double x, long double y)
{
  long double z, t;
  mpfr_t X, Y, Z;
  ref_init();
  ref_fesetround(rnd);
  mpfr_init2 (X, 64);
  mpfr_init2 (Y, 64);
  mpfr_init2 (Z, 64);
  mpfr_set_ld (X, x, MPFR_RNDN);
  mpfr_set_ld (Y, y, MPFR_RNDN);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  t = ref_hypotl (x, y);
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
  fesetround(rnd1[rnd]);
  feclearexcept (FE_INEXACT);
  z = cr_hypotl (x, y);
  fexcept_t inex2;
  fegetexceptflag (&inex2, FE_INEXACT);
  mpfr_clear (X);
  mpfr_clear (Y);
  mpfr_clear (Z);
  if (!is_equal (z, t))
  {
    printf("FAIL x,y=%La,%La ref=%La z=%La\n", x,y,t,z);
#ifdef DO_NOT_ABORT
//    return 1;
//#else
    exit(1);
#endif
  }
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x,y=%La,%La (z=%La)\n", x, y, z);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x,y=%La,%La (z=%La)\n", x, y, z);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
}

static void
check (long double x, long double y)
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

#define SKIP 500000

// check x = p^2-q^2, y = 2*p*q
static void
check_exact (void)
{
  long double x, y;
  srand (getpid ());
  uint64_t p0 = 1 + (rand () % SKIP);
  uint64_t q0 = 1 + (rand () % SKIP);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  for (uint64_t p = p0; p < 0x100000000ul; p += SKIP)
    for (uint64_t q = q0; q < p; q += SKIP)
    {
      x = (long double) (p * p - q * q);
      y = 2.0 * (long double) (p * q); // p*q is always < 2^64
      check (x, y);
    }
}

// check x = p^2-q^2, y = 2*p*q, so that p^2+q^2 has 65 bits
static void
check_midpoint (void)
{
  long double x, y;
  srand (getpid ());
  uint64_t p0 = rand () % SKIP;
  uint64_t q0 = rand () % SKIP;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  // since we want p^2+q^2 >= 2^64 with p > q, we need p > sqrt(2^63)
  for (uint64_t p = 0xb504f334ul + p0; p < 0x100000000ul; p += SKIP)
  {
    // we want p^2+q^2 >= 2^64
    uint64_t r = - p * p; // we want q^2 >= r
    uint64_t qmin = (uint64_t) sqrtl ((long double) r);
    for (uint64_t q = qmin + q0; q < p; q += SKIP)
    {
      x = (long double) (p * p - q * q);
      y = 2.0L * (long double) (p * q); // p*q is always < 2^64
      check (x, y);
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

#define LIMIT 0xffffffffffffffffull // 2^64-1

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
  for (uint64_t x = x0; x <= LIMIT - skip; x += skip)
  {
    for (uint64_t y = y0; y <= x; y += skip)
    {
      uint64_t t = x * x + y * y;
      if (is_near_square (t))
      {
        check ((long double) x, (long double) y);
        // also check in the subnormal range
        check (ldexpl ((long double) x, -16445),
               ldexpl ((long double) y, -16445));
      }
    }
  }
}

#ifdef CORE_MATH_SUPPORT_ERRNO
/* define our own is_inf function to avoid depending from math.h */
static inline int
is_inf (long double x)
{
  b80u80_t v = {.f = x};
  return ((v.e & (uint64_t)0x7fff) == 0x7fff && (v.m == ((uint64_t)1 << 63)));
}
#endif

static void
check_invalid (void)
{
  b80u80_t v;
  v.e = 0x7fff;
  v.m = 0xc000000000000000ul;
  long double qnan = v.f;
  v.e = 0xffff;
  long double minqnan = v.f;

  v.e = 0x7fff;
  v.m = 0x8000000000000000ul;
  long double inf = v.f;
  v.e = 0xffff;
  long double minInf = v.f;


  /* Check hypotl(qNaN,+/-Inf), don't need to test the opposite because it's the same result */
  // Check hypot(qNaN,+Inf)
  feclearexcept (FE_DIVBYZERO);
  long double z = cr_hypotl (qnan,inf);
  int flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       qnan, inf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(!is_inf(z)){
  printf("Error, foo(qNaN, +Inf) should be +Inf, got %La \n", z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  // Check hypot(qNaN,-Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (qnan,minInf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       qnan, minInf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(!is_inf(z)){
  printf("Error, foo(qNaN, -Inf) should be +Inf, got %La \n", z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  // Check hypot(-qNaN,+Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (minqnan,inf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       minqnan, inf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(!is_inf(z)){
  printf("Error, foo(-qNaN, +Inf) should be +Inf, got %La \n", z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  // Check hypot(-qNaN,-Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (minqnan,minInf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       minqnan, minInf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(!is_inf(z)){
  printf("Error, foo(-qNaN, -Inf) should be +Inf, got %La \n", z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  // Check hypot(+Inf, qNaN)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (inf, qnan);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       inf, qnan, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

#ifdef CORE_MATH_SUPPORT_ERRNO
  if(!is_inf(z)){
  printf("Error, foo(+Inf, qNaN) should be +Inf, got %La \n", z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
#endif

  /* Check hypot(+/-Inf, +/-Inf) */

  // Check hypot(Inf, Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (inf,inf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       inf, inf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // Check hypot(Inf, -Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (inf,minInf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       inf, minInf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // Check hypot(-Inf, Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (minInf,inf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       minInf, inf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // Check hypot(-Inf, -Inf)
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (minInf,minInf);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%La (z=%La)\n",
       minInf, minInf, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }

  // Check hypot(-Inf, 1) test with normal number
  feclearexcept (FE_DIVBYZERO);
  z = cr_hypotl (minInf,1);
  flag = fetestexcept (FE_DIVBYZERO);
  if(flag){
    printf("Spurious divbyzero exception for x=%La y=%d (z=%La)\n",
       minInf, 1, z);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

static void
check_subnormal(void)
{
  printf ("Check subnormal output range\n");
  long double u = ldexpl(1.0L, -16445); // smallest denormal
  for (int k = -16445; k <= -16383; k++)
  {
    long double x = ldexpl (1.0L, k);
    for (int l = -16445; l <= -16383; l++){
      long double y = ldexpl (1.0L, l);
#define N 3 // test x-N*u up to x+N*u
      for (int i = -N; i <= N; i++) {
        for (int j = -N; j <= N; j++) {
          check(x + (long double) i * u, y + (long double) j * u);
        }
      }
#undef N
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
  long double x, y;
  uint64_t p, q;

  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  gmp_randinit_default (state);
  gmp_randseed_ui (state, getpid ());
  mpz_init (P);
  mpz_init (Q);
  while (k--) {
    // if p,q < 2^32 then x and y are representable in binary80
    mpz_urandomb (P, state, 32);
    mpz_urandomb (Q, state, 32);
    p = mpz_get_ui (P);
    q = mpz_get_ui (Q);
    x = (p >= q) ? p * p - q * q : q * q - p * p;
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

  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);

  printf ("Checking Pythagorean triples\n");
  check_triples (1000000);

  check_invalid ();
  check_subnormal ();

  printf ("Checking exact values\n");
  check_exact ();

  printf ("Checking midpoint values\n");
  check_midpoint ();

  printf ("Checking near-exact values\n");
  fflush (stdout);
  check_near_exact ();

  printf ("Checking random values\n");
  unsigned int seed = getpid ();
  for (int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
	for(uint64_t n = 0; n < CORE_MATH_TESTS; n++) {
		ref_init();
		ref_fesetround(rnd);
		fesetround(rnd1[rnd]);
                int tid;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
                tid = omp_get_thread_num ();
#else
                tid = 0;
#endif
		long double x = get_random(tid), y = get_random(tid);
		check(x, y);
	}

  return 0;
}
