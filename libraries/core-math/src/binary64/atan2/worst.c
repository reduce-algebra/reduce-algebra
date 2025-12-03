/* Generate worst cases for atan2

Copyright (c) 2023 Paul Zimmermann, Inria.

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

Usage:

   $ gcc -O3 worst.c -o worst -lmpfr -lm
   $ ./worst <nnn>

   where <nnn> is the minimum number of identical bits after the round bit.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <mpfr.h>
#include <math.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <fenv.h>
#include <unistd.h>

double maxerr;

static void
check_one (uint64_t p, int64_t q, mpfr_exp_t e)
{
  mpfr_t x, y, z, t;
  mpfr_init2 (x, 53);
  mpfr_init2 (y, 53);
  mpfr_init2 (z, 54);
  mpfr_init2 (t, 127);
  mpfr_set_ui_2exp (y, p, e, MPFR_RNDN);
  mpfr_set_si (x, q, MPFR_RNDN);
  mpfr_atan2 (z, y, x, MPFR_RNDN);
  double err;
  while (1)
  {
    mpfr_atan2 (t, y, x, MPFR_RNDN);
    mpfr_sub (t, t, z, MPFR_RNDN);
    if (mpfr_cmp_ui (t, 0) != 0)
    {
      mpfr_exp_t e = mpfr_get_exp (z);
      // ulp(z) = 2^(e-54)
      mpfr_mul_2exp (t, t, 54 - e, MPFR_RNDN);
      err = fabs (mpfr_get_d (t, MPFR_RNDN));
      break;
    }
    mpfr_set_prec (t, 2 * mpfr_get_prec (t));
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
  if (err < maxerr)
  {
    mpfr_printf ("%Ra,%Ra\n", y, x);
    fflush (stdout);
  }
  mpfr_clear (x);
  mpfr_clear (y);
  mpfr_clear (z);
  mpfr_clear (t);
}

// return trailing zeroes
uint64_t red (uint64_t x)
{
  if (x == 0)
    return x;
  int e = __builtin_ctzl (x);
  return x >> e;
}

/* given z, find the largest convergent p/q of tan(z)/2^e such that
   red(p),red(q) < 2^53, with 1/2 <= |tan(z)|/2^e < 1, and output the
   corresponding worst case if it has at least m identical bits after
   the round bit */
static void
confrac (long double z)
{
  mpfr_prec_t prec;
  mpfr_t yl, yh;
  int sign, e, ok = 0, last_i = -1;

  prec = 150;
  while (ok == 0) {
  ok = 1;
  mpfr_init2 (yl, prec);
  mpfr_init2 (yh, prec);
  mpfr_set_ld (yl, z, MPFR_RNDN);
  mpfr_tan (yl, yl, MPFR_RNDD);
  sign = (mpfr_sgn (yl) > 0) ? 1 : -1;
  mpfr_abs (yl, yl, MPFR_RNDN);
  e = mpfr_get_exp (yl); /* 2^(e-1) <= yl < 2^e */
  mpfr_div_2si (yl, yl, e, MPFR_RNDN);
  /* now 1/2 <= yl < 1 */
  mpfr_set (yh, yl, MPFR_RNDN);
  mpfr_nextabove (yh);
  /* yl <= |tan(z)|/2^e < yh */
  uint64_t p0 = 1, p1 = 0, q0 = 0, q1 = 1, p2, q2;
  for (int i = 0; ; i++)
  {
    mpfr_ui_div (yl, 1, yl, MPFR_RNDU);
    mpfr_ui_div	(yh, 1, yh, MPFR_RNDD);
    mpfr_swap (yl, yh);
    /* yl <= 1/y <= yh */
    uint64_t al = mpfr_get_ui (yl, MPFR_RNDD);
    uint64_t ah = mpfr_get_ui (yh, MPFR_RNDD);
    if (al != ah)
    {
      ok = 0;
      prec = 2 * prec;
      goto end;
    }
    mpfr_sub_ui (yl, yl, al, MPFR_RNDD);
    mpfr_sub_ui (yh, yh, ah, MPFR_RNDU);
    p2 = al * p1 + p0;
    q2 = al * q1 + q0;
    /* in case prec was increased, we don't want to check twice the
       same convergents */
#define MAX 0x20000000000000ul
    if (i > last_i)
    {
      if (red(p2) >= MAX || red(q2) >= MAX)
      {
        check_one (p1, (sign == 1) ? (long) q1 : - (long) q1, e);
        break;
      }
      last_i = i;
    }
    p0 = p1; p1 = p2;
    q0 = q1; q1 = q2;
  }
  end:
  mpfr_clear (yl);
  mpfr_clear (yh);
  }
}

typedef union { uint64_t n; double x; } union_t;

static inline uint64_t
asuint64 (double x)
{
  union_t u;
  u.x = x;
  return u.n;
}

static double
asfloat64 (uint64_t n)
{
  union_t u;
  u.n = n;
  return u.x;
}

static void
doit (double z)
{
  confrac ((long double) z);
  double t = nextafter (z, 0);
  long double u = ((long double) z + (long double) t) / 2.0;
  confrac (u);
}

int
main (int argc, char *argv[])
{
  int m = atoi (argv[1]);
  maxerr = ldexp (1.0, -m);
  double z0, z1;
  uint64_t n0 = asuint64 (0x1p-1);
  uint64_t n1 = asuint64 (0x1p+0);
  srand48 (getpid ());
  while (1)
  {
#define LENGTH 1000000
    double buf[LENGTH];
    for (int i = 0; i < LENGTH; i++)
    {
      uint64_t n = lrand48 ();
      n = (n << 31) + lrand48 ();
      n = n0 + (n % (n1 - n0));
      buf[i] = asfloat64 (n);
    }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(static,1024)
#endif
      for (int i = 0; i < LENGTH; i++)
        doit (buf[i]);
  }
}
