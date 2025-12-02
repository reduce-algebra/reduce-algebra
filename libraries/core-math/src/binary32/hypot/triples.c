/* Generate special cases for hypotf testing.

Copyright (c) 2022 Paul Zimmermann, Inria.

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
#include <inttypes.h>
#include <math.h>
#include <fenv.h>
#include <assert.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <mpfr.h>

float cr_hypotf (float, float);
float ref_hypot (float, float);
int ref_fesetround (int);
void ref_init (void);

extern int rnd1[];
extern int rnd;
extern int verbose;

static inline uint32_t
asuint (float f)
{
  union
  {
    float f;
    uint32_t i;
  } u = {f};
  return u.i;
}

/* define our own is_nan function to avoid depending from math.h */
static inline int
is_nan (double x)
{
  uint32_t u = asuint (x);
  int e = u >> 23;
  return (e == 0xff || e == 0x1ff) && (u << 9) != 0;
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
check_aux (float x, float y)
{
  float z1, z2;
  ref_init();
  ref_fesetround(rnd);
  mpfr_flags_clear (MPFR_FLAGS_INEXACT);
  z1 = ref_hypot(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  mpfr_flags_t inex1 = mpfr_flags_test (MPFR_FLAGS_INEXACT);
#endif
  fesetround(rnd1[rnd]);
  feclearexcept (FE_INEXACT);
  z2 = cr_hypotf(x, y);
#ifdef CORE_MATH_CHECK_INEXACT
  int inex2 = fetestexcept (FE_INEXACT);
#endif
  if (!is_equal (z1, z2)) {
    printf("FAIL x=%a y=%a ref=%a z=%a\n", x, y, z1, z2);
    fflush(stdout);
    exit(1);
  }
#ifdef CORE_MATH_CHECK_INEXACT
  if ((inex1 == 0) && (inex2 != 0))
  {
    printf ("Spurious inexact exception for x=%a y=%a\n", x, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
  if ((inex1 != 0) && (inex2 == 0))
  {
    printf ("Missing inexact exception for x=%a y=%a\n", x, y);
    fflush (stdout);
#ifndef DO_NOT_ABORT
    exit(1);
#endif
  }
#endif
}

void
check (float x, float y)
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

/* check that x = m * 2*k for 2^23 <= m < 2^24,
   that 2^23 <= y < 2^24, and that z is exactly representable on 25 bits */
static int
valid (uint64_t x, uint64_t y, uint64_t z, int k)
{
  uint64_t m = x >> k;
  if (x != (m << k))
    return 0;
  if (m < 0x800000 || 0x1000000 <= m)
    return 0;
  if (y < 0x800000 || 0x1000000 <= y)
    return 0;
  assert (z > 0);
  int e = __builtin_ctz (z);
  z = z >> e;
  int ret = z < 0x2000000;
  return ret;
}

uint64_t
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

/* generate all inputs x=j*(p^2-q^2), y=j*(2pq) that satisfy
   2^(23+k) <= x < 2^(24+k), 2^23 <= y < 2^24
   Return the number of generated inputs. */
static uint64_t
generate1 (uint64_t p, uint64_t q, int k)
{
  /* ensure p and q are coprime, otherwise we will get duplicates */
  if (gcd (p, q) != 1)
    return 0;
  uint64_t count = 0;
  assert (p > q);
  uint64_t x = p * p - q * q;
  uint64_t y = 2 * p * q;
  uint64_t z = p * p + q * q;
  uint64_t xmax = 0xffffffull << k;
  uint64_t ymax = 0xffffffull;
  for (uint64_t j = 1; ; j++)
  {
    uint64_t xj = j * x;
    uint64_t yj = j * y;
    uint64_t zj = j * z;
    if (xj > xmax)
      break;
    if (yj > ymax)
      break;
    if (valid (xj, yj, zj, k))
    {
      check (xj, yj);
      count ++;
    }
  }
  return count;
}

/* generate all inputs x=j*(2pq), y=j*(p^2-q^2) that satisfy
   2^(23+k) <= x < 2^(24+k), 2^23 <= y < 2^24
   Return the number of generated inputs. */
static uint64_t
generate2 (uint64_t p, uint64_t q, int k)
{
  /* ensure p and q are coprime, otherwise we will get duplicates */
  if (gcd (p, q) != 1)
    return 0;
  uint64_t count = 0;
  assert (p > q);
  uint64_t x = 2 * p * q;
  uint64_t y = p * p - q * q;
  uint64_t z = p * p + q * q;
  uint64_t xmax = 0xffffffull << k;
  uint64_t ymax = 0xffffffull;
  for (uint64_t j = 1; ; j++)
  {
    uint64_t xj = j * x;
    uint64_t yj = j * y;
    uint64_t zj = j * z;
    if (xj > xmax)
      break;
    if (yj > ymax)
      break;
    if (valid (xj, yj, zj, k))
    {
      check (xj, yj);
      count ++;
    }
  }
  return count;
}

#ifndef CORE_MATH_TESTS
#define CORE_MATH_TESTS 1000000000ul // total number of tests
#endif

/* check all Pythagorean triples x^2 + y^2 = z^2,
   with 2^23 <= y < 2^24, 2^(23+k) <= x < 2^(24+k),
   and z of the form m*2^e with m < 2^25 */
static void
check_pythagorean_triples (int k)
{
  uint64_t p, q;
  uint64_t count1 = 0, count2 = 0;

  if (verbose)
    fprintf (stderr, "# k=%d\n", k);

  /* Type 1: x = p^2-q^2, y = 2pq, z = p^2+q^2 */
  /* since y = 2pq < 2^24 and q < p, this gives q <= 2895 */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for reduction(+: count1)
#endif
  for (q = 1; q <= 2895; q++)
    for (p = q + 1; 2 * p * q < 0x1000000ull; p+=2)
    {
      if (count1 < CORE_MATH_TESTS / 2)
        count1 += generate1 (p, q, k);
    }

  if (verbose)
    fprintf (stderr, "# Type 1: %"PRIu64"\n", count1);

  /* Type 2: x = 2pq, y = p^2-q^2, z = p^2+q^2, with p even */
  /* since y = p^2-q^2 >= 2*p-1 and y < 2^24, this gives p <= 2^23 */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for reduction(+: count2)
#endif
  for (p = 2; p <= 0x800000; p++)
  {
    /* we want y < 2^24, thus p^2-q^2 < 2^24 thus p^2 - 2^24 < q^2 */
    uint64_t qmin = 1;
    if (p * p < 0x1000000ull)
      q = 0;
    else
    {
      q = sqrt (p * p - 0x1000000ull);
      while (q * q <= p * p - 0x1000000ull)
        q ++;
    }
    if (qmin < q)
      qmin = q;
    if ((p + qmin) % 2 == 0)
      qmin ++; /* ensure p and q have different parities */
    for (q = qmin; q < p; q += 2)
      if (count2 < CORE_MATH_TESTS / 2)
        count2 += generate2 (p, q, k);
  }
  if (verbose) {
    fprintf (stderr, "# Type 2: %"PRIu64"\n", count2);
    fprintf (stderr, "# Total: %"PRIu64"\n", count1 + count2);
  }
}

void
doloop (int k0, int k1)
{
  ref_init ();
  ref_fesetround (rnd);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
  for (int k = k0; k <= k1; k++)
    check_pythagorean_triples (k);
}
