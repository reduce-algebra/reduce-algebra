/* Code to generate all solutions of x^2+y^2 = z^2+1 for z < N.

Copyright (c) 2023-2024 Paul Zimmermann, Inria.

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
#include <assert.h>
#include <gmp.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <math.h>

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000ul // total number of tests
#endif

extern void check (float, float); // defined in triples.c

typedef struct { uint32_t p; uint64_t pe; uint64_t r, a, b; } fb_entry;
typedef struct { fb_entry *l; int size; int alloc; } fb_t[1];
typedef struct { int64_t a, b; int e; } fb2_entry;
typedef struct { fb2_entry *l; int size, alloc; } fb2_t[1];

static void
fb_init (fb_t f)
{
  f->l = NULL;
  f->size = f->alloc = 0;
}

static void
fb_clear (fb_t f)
{
  free (f->l);
}

static void
fb_add (fb_t f, int p, uint64_t pe, uint64_t r, uint64_t a, uint64_t b)
{
  if (f->size == f->alloc)
  {
    f->alloc = 2 * f->alloc + 1;
    f->l = realloc (f->l, f->alloc * sizeof (fb_entry));
  }
  f->l[f->size].p = p;
  f->l[f->size].pe = pe;
  f->l[f->size].r = r;
  f->l[f->size].a = a;
  f->l[f->size].b = b;
  f->size++;
}

static void
fb2_init (fb2_t f)
{
  f->l = NULL;
  f->size = f->alloc = 0;
}

static void
fb2_clear (fb2_t f)
{
  free (f->l);
}

static void
fb2_add (fb2_t f, int64_t a, int64_t b)
{
  int n = f->size;
  if (n == f->alloc)
  {
    f->alloc = 2 * f->alloc + 1;
    f->l = realloc (f->l, f->alloc * sizeof (fb2_entry));
  }
  f->l[n].a = a;
  f->l[n].b = b;
  f->l[n].e = 1;
  f->size++;
}

// add new divisor a+i*b
static void
fb2_divide (fb2_t f, int64_t a, int64_t b)
{
  int64_t re = f->l[0].a, im = f->l[0].b;
  // divide re+i*im by a+i*b: (re+i*im)*(a-i*b)/(a^2+b^2)
  int64_t p = a * a + b * b;
  int64_t c = re * a + im * b;
  int64_t d = im * a - re * b;
  assert ((c % p) == 0);
  assert ((d % p) == 0);
  f->l[0].a = c / p;
  f->l[0].b = d	/ p;
  fb2_add (f, a, b);
}

// assume n odd
static int
is_prime (uint64_t n)
{
  for (uint64_t p = 3; p * p <= n; p += 2)
    if ((n % p) == 0)
      return 0;
  return 1;
}

// return a^n mod p, assuming a, p < 2^32
static uint64_t
mod_exp (uint64_t a, uint64_t n, uint64_t p)
{
  assert (p < 0x100000000ull);
  int nbits = 0;
  for (uint64_t t = n; t > 0; t = t >> 1, nbits++);
  int i = nbits - 2;
  uint64_t x = a; // invariant: x=a^upper_bits(n,i)
  while (i >= 0)
  {
    x = (x * x) % p;
    if (n & (1ul << i))
      x = (x * a) % p;
    i--;
  }
  return x;
}

/* returns a square root of n mod p,
   see https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm
   assert p is odd and p < 2^32
*/
static uint64_t
TonelliShanks (uint64_t n, uint64_t p)
{
  assert (p & 1);
  assert (p < 0x100000000ull);
  // step 1: write p-1 = Q*2^S with Q odd
  uint64_t Q = p - 1;
  int S = 0;
  while ((Q % 2) == 0)
    Q = Q/2, S ++;

  // step 2: find a quadratic non-residue z
  uint64_t z;
  for (z = 2; z < p; z++)
    if (mod_exp (z, (p-1)/2, p) != 1)
      break;

  // step 3
  int M = S;
  uint64_t c = mod_exp (z, Q, p);
  uint64_t t = mod_exp (n, Q, p);
  uint64_t R = mod_exp (n, (Q+1)/2, p);

  // step 4
  while (1)
  {
    if (t == 0)
      return 0;
    if (t == 1)
      return R;
    uint64_t i = 1;
    uint64_t u = (t * t) % p;
    while (u != 1)
      i ++, u = (u * u) % p;
    uint64_t b = mod_exp (c, 1ul << (M - i - 1), p);
    M = i;
    c = (b * b) % p;
    t = (t * c) % p;
    R = (R * b) % p;
  }
}

// given p, find a <= b such that a^2+b^2 = p, assume p < 2^32
static void
find_ab (int64_t *A, int64_t *B, uint64_t p)
{
  assert (p <= 0xffffffffull);
  uint64_t a;
  uint64_t a2max = p / 2;
  for (a = 1; a * a <= a2max; a++)
  {
    uint64_t r = p - a * a;
    double s = sqrt ((double) r);
    uint64_t b = s;
    if (r == b * b)
    {
      *A = a;
      *B = b;
      return;
    }
  }
  assert (0);
}

// return 1/r mod p
static uint64_t
inv_mod (uint64_t r, uint64_t p)
{
  mpz_t rr, pp;
  mpz_init (rr);
  mpz_init (pp);
  mpz_set_ui (rr, r);
  mpz_set_ui (pp, p);
  mpz_invert (rr, rr, pp);
  r = mpz_get_ui (rr);
  mpz_clear (rr);
  mpz_clear (pp);
  return r;
}

/* Lift root r^2 = -1 mod p^e to root r'^2 mod p^(e+1) for e >= 1.
   Let r' = r + lambda*p^e,
   then r'^2 = r^2 + 2*lambda*r*p^e+lambda^2*p^(2*e)
             = r^2 + 2*lambda*r*p^e mod p^(e+1) since 2*e >= e+1
   thus we need r^2 + 2*lambda*r*p^e = -1 mod p^(e+1)
                2*lambda*r*p^e = -1-r^2 mod p^(e+1)
   Since r^2 = -1 mod p^e we have r^2+1 = k*p^e thus
   2*lambda*r*p^e = -k*p^e mod p^(e+1)
   2*lambda*r = -k mod p
   lambda = -k/(2*r) mod p
   Warning: r and pe might be larger than 2^32.
*/
static uint64_t
lift_root (uint64_t r, uint64_t p, uint64_t pe) // pe = p^e
{
  mpz_t s;
  mpz_init (s);
  mpz_set_ui (s, r);
  mpz_mul (s, s, s);
  mpz_add_ui (s, s, 1); // s = r^2+1
  mpz_divexact_ui (s, s, pe);
  uint64_t k = mpz_get_ui (s);
  k = (pe - k) % p; // -k
  uint64_t lambda;
  uint64_t inv = inv_mod ((2 * r) % p, p);
  lambda = (k * inv) % p;
  r = (r + lambda * pe) % (pe * p);
  mpz_clear (s);
  return r;
}

static void
fb_prepare (fb_t *f, uint64_t N)
{
  int e;
  uint64_t p, pe, r = 0;
  for (p = 3; p < N; p+=2)
    if (is_prime (p))
    {
      if ((p % 4) != 1)
        continue;
      int64_t a, b;
      find_ab (&a, &b, p);
      // p = a^2+b^2 thus a+I*b has norm p
      pe = e = 1;
      while (1)
      {
        if (pe >= (N * N) / p) // avoids an overflow in pe*p below
          break;
        pe *= p;
        if (p == pe)
          r = TonelliShanks (p - 1, p);
        else
          r = lift_root (r, p, pe / p);
        fb_add (f[e], p, pe, r, a, b);
        fb_add (f[e], p, pe, pe - r, a, -b);
        e ++;
      }
    }
}

// return 1 + 2*digits(N,3)
static int
get_maxpow (uint32_t N)
{
  int s = 1;
  while (N > 0)
  {
    s += 2;
    N = N / 3;
  }
  return s;
}

uint32_t **TT;
uint64_t *TTl;
fb2_t *f2;

// fix sign of b such that a+i*b divides z+i
static int64_t
fix_b (int64_t z, int64_t a, int64_t b)
{
  // (z+i)/(a+i*b) = (z+i)*(a-i*b)/(a^2+b^2) = [(z*a+b) + i*(a-z*b)]/(a^2+b^2)
  int64_t p = a * a + b * b;
  int64_t re = z * a + b;
  int64_t im = a - z * b;
  if ((re % p) == 0 && (im % p) == 0)
    return b;
  re = z * a - b;
  im = a + z * b;
  assert ((re % p) == 0 && (im % p) == 0);
  return -b;
}

/* fill TT and TTl:
   TT[e][r] is the number of ideals dividing e times r+i
   TTl[r] is the remaining norm of r+i (1 if it has been divided
   by all ideals, >= 2 if a large ideal remains) */
static void
sieve (fb_t *f, int maxpow, uint32_t N)
{
  // initialize TTl
  for (uint32_t z = 0; z < N; z++)
  {
    uint64_t u = (uint64_t) z * (uint64_t) z + 1ul; // norm of ideal z+i
    // for z odd, u is divisible by 2 once since (2k+1)^2 + 1 = 4k^2 + 4k + 2
    // and we don't consider 1+i and 1-i in the factor base
    if (z & 1)
    {
      u = u / 2ul;
      fb2_divide (f2[z], 1, 1);
    }
    TTl[z] = u;
  }

  for (int e = 1; e < maxpow; e++)
    for (int i = 0; i < f[e]->size; i++)
    {
      uint32_t p = f[e]->l[i].p;
      uint64_t pe = f[e]->l[i].pe;
      uint64_t r0 = f[e]->l[i].r;
      int64_t a = f[e]->l[i].a;
      int64_t b = f[e]->l[i].b;
      b = fix_b (r0, a, b);
      for (uint64_t r = r0; r < N; r += pe)
      {
        /* z^2+1 is the product of terms (a+i*b)^e*(a-i*b)^e.
           For each (a+i*b)^e, we consider all (a+i*b)^j*(a-i*b)^(e-j)
           and make the product of all those, giving say x+i*y.
           Then x^2+y^2 = z^2+1, and we consider all non-trivial solutions
           with |x| <> 1 and |y| <> 1. */
        TT[e][r] ++;
        assert (TTl[r] % p == 0);
        TTl[r] /= p;
        fb2_divide (f2[r], a, b);
      }
    }
}

static int64_t
norm (fb2_entry f)
{
  return f.a * f.a + f.b * f.b;
}

// swap f[i] and f[j]
static void
fb2_swap (fb2_t f, int i, int j)
{
  int64_t t;
  t = f->l[i].a; f->l[i].a = f->l[j].a; f->l[j].a = t;
  t = f->l[i].b; f->l[i].b = f->l[j].b; f->l[j].b = t;
  // don't swap e values since they both equal 1
  assert (f->l[i].e == 1 && f->l[j].e == 1);
}

static void
cleanup (fb2_t f)
{
  // check that first element has norm 1 or a prime p
  assert (f->size >= 1);
  int64_t a = f->l[0].a, b = f->l[0].b;
  int64_t p = a * a + b * b;
  assert (p == 1 || is_prime (p));
  
  // if first element has norm 1, remove it
  if (p == 1)
  {
    if (f->size == 1)
      f->size = 0;
    else // put last element first
    {
      int k = f->size;
      int64_t c = f->l[k-1].a, d = f->l[k-1].b;
      f->l[0].a = c;
      f->l[0].b = d;
      f->size --;
    }
  }

  // sort by increasing norm
  int k = f->size;
  for (int i = 1; i < k; i++)
  {
    // assuming f[0..i-1] are sorted by increasing norm, insert f[i]
    int j = i;
    while (j > 0 && norm (f->l[j]) < norm (f->l[j-1]))
    {
      fb2_swap (f, j-1, j);
      j --;
    }
  }

  // now collect exponents
  int i, j, i0;
  for (i = i0 = 0; i < k; )
  {
    for (j = i+1; j < k && norm (f->l[j]) == norm (f->l[i]); j++);
    // f[i] = ... = f[j-1]
    f->l[i0].a = f->l[i].a;
    f->l[i0].b = f->l[i].b;
    f->l[i0].e = j - i;
    i0 ++;
    i = j;
  }
  f->size = i0;
}

static void
Check (int64_t x, int64_t y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  int64_t t;
  if (x > y) { t = x; x = y; y = t; }
  
  // now 0 < x <= y
  
  for (int e = 0; e < 23; e++)
  {
    float X = ldexpf (x, -149 + e);
    float Y = ldexpf (y, -149 + e);
    check (X, Y);
  }
}

// x+i*y is the current complex number from elements < i
// return the number of tests done
static uint64_t
gen_solutions_aux (fb2_t f, int64_t x, int64_t y, int i)
{
  if (i == f->size)
  {
    if (x != 1 && x != -1 && y != 1 && y != -1)
      Check (x, y);
    return 1;
  }

  int64_t a = f->l[i].a;
  int64_t b = f->l[i].b;
  int e = f->l[i].e;
  // multiply by (a+i*b)^j*(a-i*b)^(e-j) for 0 <= j <= e
  int64_t *a1, *b1;
  a1 = malloc ((e + 1) * sizeof (int64_t));
  b1 = malloc ((e + 1) * sizeof (int64_t));
  // a1+i*b1 = (a+i*b)^j
  a1[0] = 1; b1[0] = 0;
  for (int j = 1; j <= e; j++) // (a1[j-1]+i*b1[j-1])*(a+i*b)
  {
    a1[j] = a1[j-1] * a - b1[j-1] * b;
    b1[j] = a1[j-1] * b + b1[j-1] * a;
  }
  uint64_t tests = 0;
  for (int j = 0; j <= e; j++)
  {
    int64_t c, d, u, v;
    // multiply (x+i*y) by (a+i*b)^j
    c = x * a1[j] - y * b1[j];
    d = x * b1[j] + y * a1[j];
    // multiply (c+i*d) by (a-i*b)^(e-j) = conj((a+i*b)^(e-j))
    u = c * a1[e-j] + d * b1[e-j];
    v = c * -b1[e-j] + d * a1[e-j];
    tests += gen_solutions_aux (f, u, v, i+1);
  }
  free (a1);
  free (b1);
  return tests;
}

static uint64_t
gen_solutions (fb2_t f)
{
  return gen_solutions_aux (f, 1, 0, 0);
}

// generate all solutions of x^2 + y^2 = z^2 + 1
static void
generate_solutions (uint32_t N)
{
  uint64_t tests = 0;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(static,1) reduction(+: tests)
#endif
  for (uint32_t z = 0; z < N; z++)
  {
    if (tests < CORE_MATH_TESTS / 1000)
    {
      cleanup (f2[z]);
      uint64_t t = gen_solutions (f2[z]);
      tests += t;
    }
  }
}

// generate all (x,y) with x^2+y^2 = z^2+1 and z < N
void
doit_subnormal_above (uint32_t N)
{
  int maxpow = get_maxpow (N);
  fb_t *f;

  f = malloc (maxpow * sizeof (fb_t));
  f2 = malloc (N * sizeof (fb2_t));
  TT = malloc (maxpow * sizeof (uint32_t*));
  TTl = malloc (N * sizeof (uint64_t));

  for (int e = 0; e < maxpow; e++)
  {
    fb_init (f[e]);
    TT[e] = malloc (N * sizeof (uint32_t));
  }
  for (uint32_t z = 0; z < N; z++)
  {
    fb2_init (f2[z]);
    fb2_add (f2[z], z, 1); // z+I
  }
  fb_prepare (f, N);
  sieve (f, maxpow, N);
  generate_solutions (N);
  for (int e = 0; e < maxpow; e++)
  {
    fb_clear (f[e]);
    free (TT[e]);
  }
  for (uint32_t n = 0; n < N; n++)
    fb2_clear (f2[n]);
  free (f);
  free (f2);
  free (TT);
  free (TTl);
}
