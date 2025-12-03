/* Generate special cases for rsqrt testing.

Copyright (c) 2025 Alexei Sibidanov and Paul Zimmermann

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
#include <quadmath.h>
#include <gmp.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

typedef union {
  unsigned __int128 a;
  __float128 f;
} b128u128_u;

int ref_fesetround(int);
void ref_init(void);

__float128 cr_hypotq(__float128,__float128);
__float128 ref_hypotq(__float128,__float128);

int rnd1[] = { FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD };

int rnd = 0;
int verbose = 0;

#define MAX_THREADS 192

static unsigned int Seed[MAX_THREADS];

/* define our own is_nan function to avoid depending from math.h */
static inline int is_nan(__float128 x){
  b128u128_u u = {.f = x};
  return (u.a<<1)>((unsigned __int128)0x7fff<<113);
}

static inline int is_equal(__float128 x, __float128 y){
  if(is_nan(x)) return is_nan(y);
  if(is_nan(y)) return is_nan(x);
  b128u128_u ux = {.f = x}, uy = {.f = y};
  return ux.a == uy.a;
}

static void
error2 (__float128 x, __float128 y, __float128 ref, __float128 z)
{
  char buf[256];
  int n;
  n = snprintf (buf, sizeof buf, "FAIL x,y=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", x);
  n += snprintf (buf + n, sizeof buf, ",");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", y);
  n += snprintf (buf + n, sizeof buf - n, " ref=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", ref);
  n += snprintf (buf + n, sizeof buf - n, " z=");
  n += quadmath_snprintf (buf + n, sizeof buf - n, "%Qa", z);
  printf ("%s\n", buf);
}

static void check(__float128 x, __float128 y){
  __float128 y1 = ref_hypotq(x, y), y2 = cr_hypotq(x, y);
  if(!is_equal(y1, y2)) {
    error2 (x, y, y1, y2);
    fflush(stdout);
#ifndef DO_NOT_ABORT
    exit (1);
#endif
  }
}

static __float128 get_random(int tid){
  b128u128_u v = {.a = 0};
  v.a |= (__int128)rand_r(Seed + tid) << 31*0;
  v.a |= (__int128)rand_r(Seed + tid) << 31*1;
  v.a |= (__int128)rand_r(Seed + tid) << 31*2;
  v.a |= (__int128)rand_r(Seed + tid) << 31*3;
  v.a |= (__int128)rand_r(Seed + tid) << 31*4;
  v.a &= ~((__int128)1<<127);
  return v.f;
}

static _Float128 below (_Float128 x)
{
  b128u128_u v = {.f = x};
  v.a --;
  return v.f;
}

static _Float128 above (_Float128 x)
{
  b128u128_u v = {.f = x};
  v.a ++;
  return v.f;
}

// for i=0, return x
// for i=1, return above(x)
// for i=-1, return below(x)
// and so on
static _Float128 neighbour (_Float128 x, int i)
{
  while (i-- > 0) x = above (x);
  while (i++ < 0) x = below (x);
  return x;
}

// check corner cases, where x and y are near powers of 2
static void check_corner_cases ()
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int ex = -16494; ex <= 16383; ex ++) {
    ref_init();
    ref_fesetround(rnd);
    fesetround(rnd1[rnd]);
    _Float128 x;
    for (int i = -2; i <= 2; i++) {
      x = ldexpq (1.0f128, ex);
      _Float128 xx = neighbour (x, i);
      for (int ey = ex - 256; ey <= ex; ey ++) {
        _Float128 y = ldexpq (1.0f128, ey);
        for (int j = -2; j <= 2; j++) {
          _Float128 yy = neighbour (y, j);
          check (xx, yy);
        }
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
  __float128 x, y;
  __int128 p, q;

  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);
  gmp_randinit_default (state);
  gmp_randseed_ui (state, getpid ());
  mpz_init (P);
  mpz_init (Q);
  while (k--) {
    // if p,q < 2^(113/2) then x and y are representable in binary128
#define MAXP 0x16a09e667f3bcc9ull // floor(2^(113/2))
    mpz_urandomb (P, state, 64);
    mpz_urandomb (Q, state, 64);
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

int main(int argc, char *argv[]){
  while(argc >= 2){
    if(strcmp(argv[1], "--rndn") == 0){
      rnd = 0;
      argc --;
      argv ++;
    } else if(strcmp(argv[1], "--rndz") == 0){
      rnd = 1;
      argc --;
      argv ++;
    } else if(strcmp(argv[1], "--rndu") == 0){
      rnd = 2;
      argc --;
      argv ++;
    } else if(strcmp(argv[1], "--rndd") == 0){
      rnd = 3;
      argc --;
      argv ++;
    } else if(strcmp(argv[1], "--verbose") == 0){
      verbose = 1;
      argc --;
      argv ++;
    } else {
      fprintf(stderr, "Error, unknown option %s\n", argv[1]);
      exit(1);
    }
  }

  ref_init();
  ref_fesetround(rnd);
  fesetround(rnd1[rnd]);

  printf ("Checking Pythagorean triples\n");
  check_triples (100000);

  printf("Checking corner cases\n");
  check_corner_cases ();

  printf("Checking random values\n");
#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000UL*1000*1000 /* total number of tests */
#endif

  unsigned int seed = getpid();
  for(int i = 0; i < MAX_THREADS; i++)
    Seed[i] = seed + i;

#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for(uint64_t n = 0; n < CORE_MATH_TESTS; n++){
    ref_init();
    ref_fesetround(rnd);
    fesetround(rnd1[rnd]);
    int tid;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
    tid = omp_get_thread_num();
#else
    tid = 0;
#endif
    __float128 x = get_random(tid);
    __float128 y = get_random(tid);
    check(x,y);
  }
  return 0;
}
