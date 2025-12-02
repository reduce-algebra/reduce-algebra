/* Compute worst cases of powf.

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

Example:

./worst -m 44 -ymin 0x1p0 -ymax 0x1p1 -d 2 [-inv]

-m 44 looks for 44 identical bits after the round bit
-ymin 0x1p0 starts the search for y >= 0x1p0
-ymax 0x1p1 stops the search at y < 0x1p1
-d 2 uses a degree-2 approximation (use degree 0 for |y| very small)
-inv considers the inverse function (faster for |y| small)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <mpfr.h>
#include <assert.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <math.h>
#include <sys/types.h>
#include <sys/resource.h>

#ifdef TIME
int
cputime ()
{
  struct rusage rus;

  getrusage (RUSAGE_SELF, &rus);
  return rus.ru_utime.tv_sec * 1000 + rus.ru_utime.tv_usec / 1000;
}
#endif

/* define COUNT to only count the number of (x,y) pairs to check */
// #define COUNT

/* define PRINT_EXACT to print also the exact cases
   (otherwise we only count them) */
// #define PRINT_EXACT

#define TRACEX 0x1.81e7dep-79f
#define TRACEY -0x1.24eadp-20f
#define TRACEZ 16782903
#define TRACEE -24

#define PREC_INV 100

int target_m; /* number of identical bits after round bit */
uint64_t nsols = 0, nexact = 0;
uint64_t calls_mpfr_pow = 0; /* number of calls to mpfr_pow */
uint64_t calls_print_sol = 0; /* number of calls to print_sol[2] */
uint64_t tot_checks = 0;
int d = -1; /* degree of approximating polynomial (default 1) */
float Xmin = 0x1p-149f;
float Xmax = 0x1.fffffep127f;
int inv = 0; /* if inv is non-zero, search for HR cases of the inverse */
int verbose = 0;

typedef union { uint32_t n; float x; } union_t;

static inline uint32_t
asuint (float x)
{
  union_t u;
  u.x = x;
  return u.n;
}

static float
asfloat (uint32_t n)
{
  union_t u;
  u.n = n;
  return u.x;
}

float
ref_pow (uint32_t m, int e, float y, mpfr_rnd_t rnd)
{
  mpfr_t xx, yy;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_set_ui_2exp (xx, m, e, MPFR_RNDN);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  int inex = mpfr_pow (yy, xx, yy, rnd);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_subnormalize (yy, inex, rnd);
  float ret = mpfr_get_flt (yy, MPFR_RNDN);
  mpfr_clear (xx);
  mpfr_clear (yy);
  return ret;
}

/* return z^(1/y) rounded wrt rnd, with z=n*2^e */
float
ref_pow_inv (uint32_t n, int e, float y, mpfr_rnd_t rnd)
{
  mpfr_t zz, yy;
  mpfr_init2 (zz, 25);
  mpfr_init2 (yy, PREC_INV);
  mpfr_set_ui_2exp (zz, n, e, MPFR_RNDN);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  mpfr_ui_div (yy, 1, yy, MPFR_RNDN);
  int inex = mpfr_pow (yy, zz, yy, rnd);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_subnormalize (yy, inex, rnd);
  float ret = mpfr_get_flt (yy, MPFR_RNDN);
  mpfr_clear (zz);
  mpfr_clear (yy);
  return ret;
}

/* return the smallest x=m*2^e >= Xmin such that 2^-150 <= x^y <= 2^128,
   where m is the returned value, and e is stored in the 2nd argument */
static uint32_t
get_xmin (float y, int *e)
{
  mpfr_t x, z, u, yy;
  mpfr_init2 (x, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (z, 24);
  mpfr_init2 (u, PREC_INV);
  mpfr_set_flt (yy, y, MPFR_RNDN);           /* exact */
  if (y > 0)
  {
    mpfr_ui_div (u, 1, yy, MPFR_RNDD);         /* u <= 1/y */
    mpfr_set_ui_2exp (z, 1, -150, MPFR_RNDN);  /* exact */
    mpfr_pow (x, z, u, MPFR_RNDD);             /* x <= (2^-150)^(1/y) */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_pow (z, x, yy, MPFR_RNDZ);
    calls_mpfr_pow ++;
    while (mpfr_cmp_ui_2exp (z, 1, -150) < 0)
    {
      mpfr_nextabove (x);
      mpfr_pow (z, x, yy, MPFR_RNDZ);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
      calls_mpfr_pow ++;
    }
  }
  else /* y < 0: z^(1/y) is decreasing */
  {
    mpfr_ui_div (u, 1, yy, MPFR_RNDZ);         /* u >= 1/y */
    mpfr_set_ui_2exp (z, 1, 128, MPFR_RNDN);   /* exact */
    mpfr_pow (x, z, u, MPFR_RNDU);             /* x >= (2^128)^(1/y) */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_pow (z, x, yy, MPFR_RNDZ);
    calls_mpfr_pow ++;
    while (mpfr_cmp_ui_2exp (z, 1, 128) >= 0)
    {
      mpfr_nextabove (x);
      mpfr_pow (z, x, yy, MPFR_RNDZ);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
      calls_mpfr_pow ++;
    }
  }
  mpfr_set_flt (z, Xmin, MPFR_RNDN);
  if (mpfr_cmp (x, z) < 0)
    mpfr_set (x, z, MPFR_RNDN);
  *e = mpfr_get_exp (x) - 24;
  mpfr_mul_2si (x, x, -*e, MPFR_RNDN);
  uint32_t m = mpfr_get_ui (x, MPFR_RNDN);
  mpfr_clear (x);
  mpfr_clear (yy);
  mpfr_clear (z);
  mpfr_clear (u);
  return m;
}

/* return the smallest 25-bit z such that x^y <= z for Xmin <= x <= Xmax
   z is encoded as m*2^e with m < 2^25 */
static uint32_t
get_zmin (float y, int *e)
{
  mpfr_t t, u;
  uint64_t z;
  mpfr_init2 (t, 25);
  mpfr_init2 (u, 24);
  mpfr_set_flt (t, (y > 0) ? Xmin : Xmax, MPFR_RNDN);        /* exact */
  mpfr_set_flt (u, y, MPFR_RNDN);           /* exact */
  mpfr_pow (t, t, u, MPFR_RNDU);            /* Xmin^y <= t */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  *e = mpfr_get_exp (t);
  mpfr_mul_2si (t, t, 25 - *e, MPFR_RNDN);
  assert (mpfr_integer_p (t) && mpfr_fits_ulong_p (t, MPFR_RNDN));
  z = mpfr_get_ui (t, MPFR_RNDN);
  *e -= 25;
  assert (z < 0x2000000);
  mpfr_clear (t);
  mpfr_clear (u);
  return z;
}

/* return the largest x <= Xmax such that 2^-150 <= x^y <= 0x1.ffffffp127f */
static uint32_t
get_xmax (float y, int *e)
{
  mpfr_t x, yy, z, u;
  mpfr_init2 (x, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (z, 25);
  mpfr_init2 (u, PREC_INV);
  mpfr_set_flt (yy, y, MPFR_RNDN);           /* exact */
  if (y > 0)
  {
    mpfr_ui_div (u, 1, yy, MPFR_RNDU);
    mpfr_set_ui_2exp (z, 1, 128, MPFR_RNDN);  /* exact */
    mpfr_nextbelow (z);
    mpfr_pow (x, z, u, MPFR_RNDU);            /* 0x1.ffffffp127f^(1/y) <= x */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_pow (z, x, yy, MPFR_RNDU);
    while (mpfr_cmp_ui_2exp (z, 0x1ffffff, 103) > 0)
    {
      mpfr_nextbelow (x);
      mpfr_pow (z, x, yy, MPFR_RNDU);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
      calls_mpfr_pow ++;
    }
  }
  else /* y < 0 */
  {
    mpfr_ui_div (u, 1, yy, MPFR_RNDD);
    mpfr_set_ui_2exp (z, 1, -150, MPFR_RNDN);  /* exact */
    mpfr_pow (x, z, u, MPFR_RNDD);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_pow (z, x, yy, MPFR_RNDD);
    while (mpfr_cmp_ui_2exp (z, 1, -150) < 0)
    {
      mpfr_nextbelow (x);
      mpfr_pow (z, x, yy, MPFR_RNDD);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
      calls_mpfr_pow ++;
    }
  }
  mpfr_set_flt (z, Xmax, MPFR_RNDN);
  if (mpfr_cmp (x, z) > 0)
    mpfr_set (x, z, MPFR_RNDN);
  *e = mpfr_get_exp (x) - 24;
  mpfr_mul_2si (x, x, -*e, MPFR_RNDN);
  uint32_t m = mpfr_get_ui (x, MPFR_RNDN);
  mpfr_clear (x);
  mpfr_clear (yy);
  mpfr_clear (z);
  mpfr_clear (u);
  return m;
}

/* return the largest 25-bit z such that z <= x^y for Xmin <= x <= Xmax
   z is encoded as m*2^e with m < 2^25 */
static uint32_t
get_zmax (float y, int *e)
{
  mpfr_t t, u;
  uint32_t z;
  mpfr_init2 (t, 25);
  mpfr_init2 (u, 24);
  mpfr_set_flt (t, (y > 0) ? Xmax : Xmin, MPFR_RNDN);          /* exact */
  mpfr_set_flt (u, y, MPFR_RNDN);             /* exact */
  mpfr_pow (t, t, u, MPFR_RNDD);              /* t <= FLT_MAX^y */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  *e = mpfr_get_exp (t);
  mpfr_mul_2si (t, t, 25 - *e, MPFR_RNDN);
  assert (mpfr_integer_p (t) && mpfr_fits_ulong_p (t, MPFR_RNDN));
  z = mpfr_get_ui (t, MPFR_RNDN);
  *e -= 25;
  mpfr_clear (t);
  mpfr_clear (u);
  return z;
}

static int
get_exp (float x)
{
  int e;
  float y = y;
  y = frexpf (x, &e);
  return e;
}

/* return non-zero if a solution is found */
static int
print_sol (float x, float y)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_print_sol ++;

  if (x == 1.0f) /* don't print solutions with x=1 */
    return 0;
  mpfr_t xx, yy, zz, tt;
  int k, found = 0;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (zz, 24 + target_m);
  mpfr_init2 (tt, 24 + 1);
  mpfr_set_flt (xx, x, MPFR_RNDN);
  mpfr_set_flt (yy, y, MPFR_RNDN);

  /* first check if x^y is exact on 25 bits */
  int ret = mpfr_pow (zz, xx, yy, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  ret = mpfr_set (tt, zz, MPFR_RNDN) || ret;
  if (ret == 0)
  {
#ifdef PRINT_EXACT
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
    {
      printf ("%a,%a # exact\n", x, y);
      fflush (stdout);
      found = 1;
    }
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    nexact ++;
    goto end;
  }

  /* check if we have at least target_m identical bits after the round bit */
  if (mpfr_cmp (tt, zz) != 0)
    goto end;

  /* if at least target_m identical bits, determine the nb of identical bits */
  for (k = target_m + 1; ; k++)
  {
    mpfr_set_prec (zz, 24 + k);
    mpfr_pow (zz, xx, yy, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_set (tt, zz, MPFR_RNDN);
    if (mpfr_cmp (tt, zz) != 0)
      break;
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
  {
    printf ("%a,%a # %d\n", x, y, k - 1);
    fflush (stdout);
    found = 1;
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    nsols ++;
 end:
  mpfr_clear (xx);
  mpfr_clear (yy);
  mpfr_clear (zz);
  mpfr_clear (tt);
  return found;
}

/* return non-zero if a solution is found */
static int
print_sol2 (uint32_t x, int e, float y)
{
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_print_sol ++;

  assert (0x800000 <= x && x < 0x1000000);
  mpfr_t xx, yy, zz, tt;
  int k, found = 0;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (zz, 24 + target_m);
  mpfr_init2 (tt, 24 + 1);
  mpfr_set_ui_2exp (xx, x, e, MPFR_RNDN);
  
  if (mpfr_cmp_ui (xx, 1) == 0)
    goto end; /* don't print solutions with x=1 */

  if (mpfr_get_exp (xx) - mpfr_min_prec (xx) < -149)
    goto end; /* non representable subnormal */

  mpfr_set_flt (yy, y, MPFR_RNDN);

  /* first check if x^y is exact on 25 bits */
  int ret = mpfr_pow (zz, xx, yy, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  ret = mpfr_set (tt, zz, MPFR_RNDN) || ret;
  if (ret == 0)
  {
#ifdef PRINT_EXACT
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
    {
      printf ("%a,%a # exact\n", ldexpf (x, e), y);
      fflush (stdout);
      found = 1;
    }
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    nexact ++;
    goto end;
  }

  /* check if we have at least target_m identical bits after the round bit */
  if (mpfr_cmp (tt, zz) != 0)
    goto end;

  /* if at least target_m identical bits, determine the number of identical
     bits */
  for (k = target_m + 1; ; k++)
  {
    mpfr_set_prec (zz, 24 + k);
    mpfr_pow (zz, xx, yy, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    calls_mpfr_pow ++;
    mpfr_set (tt, zz, MPFR_RNDN);
    if (mpfr_cmp (tt, zz) != 0)
      break;
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
  {
    printf ("%a,%a # %d\n", ldexpf (x, e), y, k - 1);
    fflush (stdout);
    found = 1;
  }
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
    nsols ++;
 end:
  mpfr_clear (xx);
  mpfr_clear (yy);
  mpfr_clear (zz);
  mpfr_clear (tt);
  return found;
}

/* exhaustive search using MPFR from x0 = m0*2^e to x1 = m1*2^e */
static uint64_t
search_binade_mpfr (uint32_t m0, uint32_t m1, int e, float y)
{
  //  if (y == TRACEY && ldexpf (m0, e) <= TRACEX && TRACEX <= ldexpf (m1, e)) printf ("search_binade_mpfr: m0=%u m1=%u e=%d\n", m0, m1, e);
  mpfr_t xx, yy, zz, tt;
  uint64_t calls = 0;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (zz, 24 + target_m);
  mpfr_init2 (tt, 24 + 1);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  for (uint32_t m = m0; m <= m1; m++)
  {
    mpfr_set_ui_2exp (xx, m, e, MPFR_RNDN);
    mpfr_pow (zz, xx, yy, MPFR_RNDN);
    calls ++;
    mpfr_set (tt, zz, MPFR_RNDN);
    if (mpfr_cmp (tt, zz) == 0)
      print_sol2 (m, e, y);
  }
  mpfr_clear (xx);
  mpfr_clear (yy);
  mpfr_clear (zz);
  mpfr_clear (tt);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow += calls;
  return m1 - m0 + 1;
}

static void
check_sol_z (uint32_t n, int e, float y, mpfr_t yy, mpfr_t iy, int target_m)
{
  mpfr_t xx, z2, tt;
  mpfr_init2 (xx, 24);
  mpfr_init2 (tt, 25);
  mpfr_init2 (z2, 24 + target_m);
  mpfr_set_ui_2exp (tt, n, e, MPFR_RNDN);
  mpfr_pow (xx, tt, iy, MPFR_RNDN);
  /* xx is a candidate for a worst-case input */
  mpfr_pow (z2, xx, yy, MPFR_RNDN);
  mpfr_set (tt, z2, MPFR_RNDN);
  if (mpfr_cmp (tt, z2) == 0)
    print_sol (mpfr_get_flt (xx, MPFR_RNDN), y);
  mpfr_clear (xx);
  mpfr_clear (tt);
  mpfr_clear (z2);
}

/* exhaustive search using MPFR from z0 = n0^2^e to z1 = n1*2^e
   for the inverse function */
static uint64_t
search_binade_mpfr_z (uint32_t n0, uint32_t n1, int e, float y)
{
  // printf ("search_binade_mpfr_z n0=%u n1=%u e=%d\n", n0, n1, e);
  mpfr_t xx, yy, iy, z2, tt;
  uint64_t calls = 0;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (iy, PREC_INV);
  mpfr_init2 (z2, 24 + target_m);
  mpfr_init2 (tt, 25);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  mpfr_ui_div (iy, 1, yy, MPFR_RNDN); /* 1/y */
  for (uint32_t n = n0; n <= n1; n++)
  {
    mpfr_set_ui_2exp (tt, n, e, MPFR_RNDN);
    mpfr_pow (xx, tt, iy, MPFR_RNDN);
    /* xx is a candidate for a worst-case input */
    mpfr_pow (z2, xx, yy, MPFR_RNDN);
    mpfr_set (tt, z2, MPFR_RNDN);
    if (mpfr_cmp (tt, z2) == 0)
      print_sol (mpfr_get_flt (xx, MPFR_RNDN), y);

    calls += 2;
  }
  mpfr_clear (xx);
  mpfr_clear (yy);
  mpfr_clear (iy);
  mpfr_clear (z2);
  mpfr_clear (tt);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow += calls;
  return n1 - n0 + 1;
}

/* assuming |x| < 2^64:
   if x > 0, return mpfr_get_ui (x)
   otherwise return 2^64 - mpfr_get_ui (x) */
uint64_t
my_mpfr_get_ui (mpfr_t x, mpfr_rnd_t rnd)
{
  if (mpfr_cmp_ui (x, 0) >= 0)
    return mpfr_get_ui (x, rnd);
  else
  {
    mpfr_t t;
    mpfr_init2 (t, mpfr_get_prec (x));
    mpfr_neg (t, x, MPFR_RNDN);
    uint64_t u = mpfr_get_ui (t, rnd);
    mpfr_clear (t);
    return -u;
  }
}

/* return non-zero of the significand from xx is less than that of zz
   (not taking into account their exponents) */
static int
cmp_significand (mpfr_t x, mpfr_t z)
{
  mpfr_t t;
  mpfr_init2 (t, mpfr_get_prec (x));
  mpfr_set (t, x, MPFR_RNDN);
  mpfr_set_exp (t, mpfr_get_exp (z));
  int ret = mpfr_cmpabs (t, z) < 0;
  mpfr_clear (t);
  return ret;
}

#ifndef USE_MPFR
/* let f(x) = x^y, x0 = m0*2^e, x1 = m1*2^e.
   Let a the bits of f(x0) after the round bit,
   b the bits of f'(x0)*ulp(f(x0)) after the round bit,
   and c the bits of f''(x0)*ulp(f(x0))^2 after the round bit.
   Let ea (resp. eb and ec) the maximal error on a (resp. on b and c),
   and ed the maximal error coming from the 3rd derivative,
   where the error in ea includes the bound to have at least m
   identical bits after the round bit.
   A necessary condition to have at least m identical bits after the
   round bit for x0+i*ulp(x0) is:
   |a + i*b + i^2*c| cmod 2^64 < ea + i*eb + i^2*ec + i^3*ed,
   where 'cmod' means a centered modulus.
   The return values (a,b,c) are the initial values of the difference table,
   so that by doing a += b and b += c (in that order) we get in a the next
   value of a + i*b + i^2*c. More precisely we return (a,b+c,2c).
   Idem for the return values of (ea,eb,ec,ed): we return
   (ea,eb+ec+ed,2ec+6ed,6ed).
   Return -1 if failure.
  */
static int
init_quadratic (uint32_t m0, uint32_t m1, int e, float y,
                uint64_t *a, uint64_t *b,
                uint64_t *c, uint64_t *ea, uint64_t *eb, uint64_t *ec,
                uint64_t *ed)
{
  int ret = -1; /* failure */
  // printf ("init_quadratic m0=%u m1=%u e=%d y=%a\n", m0, m1, e, y);
  mpfr_t xx, yy, aa, bb, cc, dd;
  mpfr_init2 (xx, 24);
  mpfr_init2 (yy, 24);
  mpfr_init2 (aa, 24 + 1 + 64);
  mpfr_init2 (bb, 24 + 1 + 64);
  mpfr_init2 (cc, 100);
  mpfr_init2 (dd, 24 + 1 + 64);
  mpfr_set_ui_2exp (xx, m0, e, MPFR_RNDN);
  mpfr_exp_t exp_x = mpfr_get_exp (xx);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  mpfr_pow (aa, xx, yy, MPFR_RNDN); /* err < 1 ulp */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_set (bb, aa, MPFR_RNDN);     /* err < 1 ulp */
  mpfr_exp_t exp_a = mpfr_get_exp (aa);
  if (exp_a < -125) /* subnormal number */
    exp_a = -125; /* multiply aa below by 2^150 */
  mpfr_mul_2si (aa, aa, 25 - exp_a, MPFR_RNDN); /* exact */
  /* now 2^24 <= aa < 2^25 */
  mpfr_frac (aa, aa, MPFR_RNDN); /* exact */
  mpfr_mul_2ui (aa, aa, 64, MPFR_RNDN); /* exact */
  *a = my_mpfr_get_ui (aa, MPFR_RNDN); /* exact */
  // printf ("a=%lu\n", *a);
  *ea = 1;
  /* derivative is x^y*(y/x) */
  mpfr_mul (bb, bb, yy, MPFR_RNDN);
  mpfr_div (bb, bb, xx, MPFR_RNDN);
  mpfr_set (cc, bb, MPFR_RNDN);     /* cc approximates x^y*(y/x) */
  /* the relative error is bounded by (1+theta)^3-1 where 0 <= theta < 2^(1-p)
     which is less than 4*theta for p>=3 (here p = 89). */
  mpfr_exp_t ulp_x = exp_x - 24;
  mpfr_mul_2si (bb, bb, ulp_x, MPFR_RNDN); /* multiply by ulp(x) */
  mpfr_mul_2si (bb, bb, 25 - exp_a, MPFR_RNDN); /* scale like aa */
  mpfr_frac (bb, bb, MPFR_RNDN); /* exact */
  mpfr_mul_2ui (bb, bb, 64, MPFR_RNDN);
  *b = my_mpfr_get_ui (bb, MPFR_RNDN); /* exact */
  // printf ("b=%lu\n", *b);
  *eb = 2; /* 1 ulp for the rounding to 64 bits, and 4*2^(1-89) for the
              above roundings */
  /* 2nd derivative is x^(y-2)*y*(y-1), where we saved x^(y-1)*y in cc */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_div (cc, cc, xx, MPFR_RNDN);
  while (1)
  {
    int ret = mpfr_sub_ui (aa, yy, 1, MPFR_RNDN);
    if (ret == 0)
      break;
    mpfr_prec_round (aa, 2 * mpfr_get_prec (aa), MPFR_RNDN);
  }
  mpfr_mul (cc, cc, aa, MPFR_RNDN);
  mpfr_mul_2si (cc, cc, 2 * ulp_x, MPFR_RNDN); /* multiply by ulp(x)^2 */
  mpfr_mul_2si (cc, cc, 25 - exp_a, MPFR_RNDN); /* scale like aa */
  /* divide by 2 since Taylor expansion is f''(x0)/2 */
  mpfr_div_2ui (cc, cc, 1, MPFR_RNDN);
  mpfr_frac (cc, cc, MPFR_RNDN);
  mpfr_mul_2ui (cc, cc, 64, MPFR_RNDN);
  *c = my_mpfr_get_ui (cc, MPFR_RNDN);
  // printf ("c=%lu\n", *c);
  *ec = 5; /* 1 ulp for mpfr_pow, 1 for each division by xx,
              1 for the multiply by y, one for the multiply by y-1 */
  /* 3rd derivative is x^(y-3)*y*(y-1)*(y-2).
     If y >= 3, it is maximal at x1, otherwise it is maximal at x0
     (this also holds for y < 0). */
  mpfr_set_ui_2exp (xx, (y >= 3.0f) ? m1 : m0, e, MPFR_RNDU);
  mpfr_pow (dd, xx, yy, MPFR_RNDU);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_div (dd, dd, xx, MPFR_RNDU);
  mpfr_div (dd, dd, xx, MPFR_RNDU);
  mpfr_div (dd, dd, xx, MPFR_RNDU);
  mpfr_mul (dd, dd, yy, MPFR_RNDU);
  mpfr_sub_ui (yy, yy, 1, MPFR_RNDA);
  mpfr_mul (dd, dd, yy, MPFR_RNDA);
  mpfr_sub_ui (yy, yy, 1, MPFR_RNDA);
  mpfr_mul (dd, dd, yy, MPFR_RNDA);
  mpfr_abs (dd, dd, MPFR_RNDA);
  mpfr_mul_2si (dd, dd, 3 * ulp_x, MPFR_RNDA); /* multiply by ulp(x)^3 */
  mpfr_mul_2si (dd, dd, 25 - exp_a, MPFR_RNDA); /* scale like aa */
  /* divide by 6 since 3rd term of explicit Taylor expansion is
     f'''(x0)/3! */
  mpfr_div_ui (dd, dd, 6, MPFR_RNDA);
  if (mpfr_cmpabs_ui (dd, 1) >= 0)
    goto end;
  mpfr_mul_2ui (dd, dd, 64, MPFR_RNDA);
  mpfr_abs (dd, dd, MPFR_RNDA);
  *ed = mpfr_get_ui (dd, MPFR_RNDA);
  // printf ("ed=%lu\n", *ed);
  /* add error bound to ea */
  *ea += (uint64_t) 1 << (64 - target_m);
  ret = 1;
 end:
  mpfr_clear (xx);
  mpfr_clear (yy);
  mpfr_clear (aa);
  mpfr_clear (bb);
  mpfr_clear (cc);
  mpfr_clear (dd);
  *b += *c;
  *c += *c;
  *eb = *eb + *ec + *ed;
  *ec = 2 * *ec + 6 * *ed;
  *ed = 6 * *ed;
  return ret;
}

/* return -1 if failure, iy is an approximation of 1/y */
static int
init_quadratic_z (uint32_t m0, uint32_t m1, int e, float y,
                  uint64_t *a, uint64_t *b,
                  uint64_t *c, uint64_t *ea, uint64_t *eb, uint64_t *ec,
                  uint64_t *ed, mpfr_t iy)
{
  // int bug = m0 == 33554305 && y == 0x1.744308p-25f;
  // printf ("init_quadratic_z m0=%u m1=%u e=%d y=%a\n", m0, m1, e, y);
  mpfr_t zz, aa, bb, cc, dd;
  mpfr_init2 (zz, 25);
  mpfr_init2 (aa, 24 + 1 + 64);
  mpfr_init2 (bb, 24 + 1 + 64);
  mpfr_init2 (cc, 100);
  mpfr_init2 (dd, 24 + 1 + 64);
  mpfr_set_ui_2exp (zz, m0, e, MPFR_RNDN);
  mpfr_exp_t exp_z = mpfr_get_exp (zz);
  mpfr_pow (aa, zz, iy, MPFR_RNDN); /* err < 1 ulp */
  int opt = cmp_significand (aa, zz);
  // if (bug) mpfr_printf ("a=%Ra\n", aa);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_set (bb, aa, MPFR_RNDN);     /* err < 1 ulp */
  mpfr_exp_t exp_a = mpfr_get_exp (aa);
  mpfr_mul_2si (aa, aa, 24 - exp_a, MPFR_RNDN); /* exact */
  /* now 2^23 <= aa < 2^24 */
  mpfr_frac (aa, aa, MPFR_RNDN); /* exact */
  mpfr_mul_2ui (aa, aa, 64, MPFR_RNDN); /* exact */
  *a = my_mpfr_get_ui (aa, MPFR_RNDN); /* exact */
  // printf ("a=%lu\n", *a);
  *ea = 1;
  /* derivative is z^iy*(iy/z) */
  mpfr_mul (bb, bb, iy, MPFR_RNDN);
  mpfr_div (bb, bb, zz, MPFR_RNDN);
  mpfr_set (cc, bb, MPFR_RNDN);
  // if (bug) mpfr_printf ("b=%Ra\n", bb);
  /* the relative error is bounded by (1+theta)^3-1 where 0 <= theta < 2^(1-p)
     which is less than 4*theta for p>=3 (here p = 89). */
  mpfr_exp_t ulp_z = exp_z - 25;
  mpfr_mul_2si (bb, bb, ulp_z, MPFR_RNDZ); /* multiply by ulp(z) */
  mpfr_mul_2si (bb, bb, 24 - exp_a, MPFR_RNDN); /* scale like aa */
  mpfr_frac (bb, bb, MPFR_RNDN); /* exact */
  mpfr_mul_2ui (bb, bb, 64, MPFR_RNDN);
  *b = my_mpfr_get_ui (bb, MPFR_RNDN); /* exact */
  // printf ("b=%lu\n", *b);
  *eb = 2; /* 1 ulp for the rounding to 64 bits, and 4*2^(1-89) for the
              above roundings */
  /* 2nd derivative is z^(iy-2)*iy*(iy-1), where we saved z^iy in cc */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_div (cc, cc, zz, MPFR_RNDN);
  while (1)
  {
    int ret = mpfr_sub_ui (aa, iy, 1, MPFR_RNDN);
    if (ret == 0)
      break;
    mpfr_prec_round (aa, 2 * mpfr_get_prec (aa), MPFR_RNDN);
  }
  mpfr_mul (cc, cc, aa, MPFR_RNDN);
  // if (bug) mpfr_printf ("c=%Ra\n", cc);
  mpfr_mul_2si (cc, cc, 2 * ulp_z, MPFR_RNDN); /* multiply by ulp(z)^2 */
  mpfr_mul_2si (cc, cc, 24 - exp_a, MPFR_RNDN); /* scale like aa */
  /* divide by 2 since Taylor expansion is f''(z0)/2 */
  mpfr_div_2ui (cc, cc, 1, MPFR_RNDN);
  mpfr_frac (cc, cc, MPFR_RNDN);
  mpfr_mul_2ui (cc, cc, 64, MPFR_RNDN);
  *c = my_mpfr_get_ui (cc, MPFR_RNDN);
  // printf ("c=%lu\n", *c);
  *ec = 5; /* 1 ulp for mpfr_pow, 1 for each division by xx,
              1 for the multiply by y, one for the multiply by y-1 */
  /* 3rd derivative is z^(iy-3)*iy*(iy-1)*(iy-2).
     If iy >= 3, it is maximal in absolute value at x1,
     otherwise it is maximal at x0.
     This is also valid for iy < 0. */
  int cmp = mpfr_cmp_ui (iy, 3) >= 0;
  mpfr_set_ui_2exp (zz, (cmp) ? m1 : m0, e, MPFR_RNDA);
  mpfr_pow (dd, zz, iy, MPFR_RNDA);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  calls_mpfr_pow ++;
  mpfr_div (dd, dd, zz, MPFR_RNDA);
  mpfr_div (dd, dd, zz, MPFR_RNDA);
  mpfr_div (dd, dd, zz, MPFR_RNDA);
  mpfr_mul (dd, dd, iy, MPFR_RNDA);
  mpfr_sub_ui (cc, iy, 1, MPFR_RNDA);
  mpfr_mul (dd, dd, cc, MPFR_RNDA);
  mpfr_sub_ui (cc, cc, 1, MPFR_RNDA);
  mpfr_mul (dd, dd, cc, MPFR_RNDA);
  // if (bug) mpfr_printf ("d=%Ra\n", dd);
  mpfr_abs (dd, dd, MPFR_RNDA);
  mpfr_mul_2si (dd, dd, 3 * ulp_z, MPFR_RNDA); /* multiply by ulp(z)^3 */
  mpfr_mul_2si (dd, dd, 24 - exp_a, MPFR_RNDA); /* scale like aa */
  /* divide by 6 since 3rd term of explicit Taylor expansion is
     f'''(x0)/3! */
  mpfr_div_ui (dd, dd, 6, MPFR_RNDA);
  int my;
  if (mpfr_cmpabs_ui (dd, 1) >= 0)
  {
    my = -1;
    goto end;
  }
  assert (mpfr_cmpabs_ui (dd, 1) < 0);
  mpfr_mul_2ui (dd, dd, 64, MPFR_RNDA);
  mpfr_abs (dd, dd, MPFR_RNDA);
  *ed = mpfr_get_ui (dd, MPFR_RNDA);
  // printf ("ed=%lu\n", *ed);
  /* add error bound to ea */
  int ey;
  frexpf (y, &ey);
  my = (opt) ? target_m + ey - 1 : target_m + ey - 2;
  assert (0 < my && my < 64);
  *ea += (uint64_t) 1 << (64 - my);
  *b += *c;
  *c += *c;
  // printf ("eb=%lu ec=%lu ed=%lu\n", *eb, *ec, *ed);
  *eb = *eb + *ec + *ed;
  *ec = 2 * *ec + 6 * *ed;
  *ed = 6 * *ed;
 end:
  mpfr_clear (zz);
  mpfr_clear (aa);
  mpfr_clear (bb);
  mpfr_clear (cc);
  mpfr_clear (dd);
  return my;
}
#endif

#ifndef USE_MPFR
/* Use a quadratic approximation a + b*i + c*i^2,
   with error bounded by ea + eb*i + ec*i^2 + ed*i^3.
   Return 0 in case of failure, otherwise return the number m1-m0+1 of values
   checked. */
static uint64_t
search_binade_quadratic (uint32_t m0, uint32_t m1, int e, float y)
{
  // int bug = y == TRACEY && ldexpf (m0, e) <= TRACEX && TRACEX <= ldexpf (m1, e);
  // if (bug) printf ("search_binade_quadratic: m0=%u m1=%u e=%d\n", m0, m1, e);
  uint64_t a, b, c, ea, eb, ec, ed;
  int ret = init_quadratic (m0, m1, e, y, &a, &b, &c, &ea, &eb, &ec, &ed);
  if (ret == -1)
    return 0;
  // if (bug) printf ("m0=%u m1=%u e=%d y=%a a=%lu b=%lu c=%lu ea=%lu eb=%lu ec=%lu ed=%lu\n", m0, m1, e, y, a, b, c, ea, eb, ec, ed);
  //  uint32_t last_init = m0;
  for (uint32_t m = m0; m <= m1; )
  {
    /* check if a cmod 2^64 < ea */
    // if (y == TRACEY && ldexpf (m, e) == TRACEX) printf ("last_init=%u m=%u\n", last_init, m);
    if (a + ea <= ea + ea)
      print_sol2 (m, e, y);
    m ++;
    if (m > m1)
      break;
    a += b;
    b += c;
    if (ea > (1ul << 53))
    {
    recompute:
      ret = init_quadratic (m, m1, e, y, &a, &b, &c, &ea, &eb, &ec, &ed);
      if (ret == -1)
        return 0;
      // last_init = m;
      continue;
    }
    assert (ea + eb >= ea);
    ea += eb;
    if (ea > 0x8000000000000000ull)
      goto recompute;
    assert (eb + ec >= eb);
    eb += ec;
    assert (ec + ed >= ec);
    ec += ed;
  }
  return m1 - m0 + 1;
}

/* Use a quadratic approximation a + b*i + c*i^2,
   with error bounded by ea + eb*i + ec*i^2 + ed*i^3.
   Return 0 in case of failure, otherwise return the number m1-m0+1 of values
   checked. */
static uint64_t
search_binade_quadratic_z (uint32_t m0, uint32_t m1, int e, float y)
{
  // int bug = y == TRACEY && e == TRACEE && m0 <= TRACEZ && TRACEZ <= m1;
  // if (bug) printf ("search_binade_quadratic_z m0=%u m1=%u e=%d\n", m0, m1, e);
  uint64_t a, b, c, ea, eb, ec, ed;
  mpfr_t yy, iy;
  mpfr_init2 (yy, 24);
  mpfr_init2 (iy, PREC_INV);
  mpfr_set_flt (yy, y, MPFR_RNDN);
  mpfr_ui_div (iy, 1, yy, MPFR_RNDN);
  int my = init_quadratic_z (m0, m1, e, y, &a, &b, &c, &ea, &eb, &ec, &ed, iy);
  // uint32_t last_init = m0;
  if (my == -1)
    goto end;
  // if (bug) printf ("m0=%u m1=%u a=%lu b=%lu c=%lu ea=%lu eb=%lu ec=%lu ed=%lu\n", m0, m1, a, b, c, ea, eb, ec, ed);
  for (uint32_t m = m0; m <= m1; )
  {
    /* check if a cmod 2^64 < ea */
    // if (y == TRACEY && e == TRACEE && m == TRACEZ) printf ("m=%u a=%lu ea=%lu last_init=%u\n", m, a, ea, last_init);
    if (a + ea <= ea + ea)
      check_sol_z (m, e, y, yy, iy, my);
    m ++;
    if (m > m1)
      break;
    a += b;
    b += c;
    if (ea > (1ul << 53))
    {
    recompute:
      my = init_quadratic_z (m, m1, e, y, &a, &b, &c, &ea, &eb, &ec, &ed, iy);
      // last_init = m;
      if (my == -1)
        goto end;
      // if (y == TRACEY && e == TRACEE && m == 16782902) printf ("m=%u a=%lu b=%lu c=%lu ea=%lu eb=%lu ec=%lu ed=%lu\n", m, a, b, c, ea, eb, ec, ed);
      continue;
    }
    if (ea + eb < ea)
      goto recompute;
    ea += eb;
    if (ea >= 0x8000000000000000ull) /* ensure ea + ea does not overflow */
      goto recompute;
    if (eb + ec < eb)
      goto recompute;
    eb += ec;
    if (ec + ed < ec)
      goto recompute;
    ec += ed;
  }
 end:
  mpfr_clear (yy);
  mpfr_clear (iy);
  return (my == -1) ? 0 : m1 - m0 + 1;
}
#endif

/* search m-worst cases of x^y for x0 <= x <= x1, where 2^e <= x^y < 2^(e+1),
   and x0 = m0*2^e, and x1 = m1*2^e, where z0 = x0^y.
   x0 and x1 are in the same binade. */
static void
search_binade_x (uint32_t m0, uint32_t m1, int e, float y)
{
  // if (y == TRACEY && asfloat (n0) <= TRACEX && TRACEX <= asfloat (n1)) printf ("search_binade: x0=%a x1=%a y=%a\n", asfloat (n0), asfloat (n1), y);
  uint64_t checks;
#ifdef USE_MPFR
  checks = search_binade_mpfr (m0, m1, e, y);
#else
  if (d == 0)
    checks = search_binade_mpfr (m0, m1, e, y);
  else
  {
    checks = search_binade_quadratic (m0, m1, e, y);
    if (checks == 0)
      checks = search_binade_mpfr (m0, m1, e, y);
  }
#endif
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tot_checks += checks;
}

static void
search_binade_z (uint32_t n0, uint32_t n1, int e, float y)
{
  // if (y == TRACEY && e == TRACEE && n0 <= TRACEZ && TRACEZ <= n1) printf ("search_binade_z n0=%u n1=%u e=%d\n", n0, n1, e);
  assert (n0 <= n1);
  uint64_t checks;
  assert (d == 0 || d == 2);
  if (d == 0 || n1 - n0 <= 7)
    checks = search_binade_mpfr_z (n0, n1, e, y);
  else
    checks = search_binade_quadratic_z (n0, n1, e, y);
  if (checks == 0)
    checks = search_binade_mpfr_z (n0, n1, e, y);
  assert (checks != 0);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tot_checks += checks;
}

/* search m-worst cases of x^y for x0 <= x <= x1,
   where x0 = m0*2^e, and x1 = m1*2^e are in the same binade */
static void
search_x (uint32_t m0, uint32_t m1, int e, float y)
{
  // printf ("enter search x0=%a x1=%a y=%a\n", x0, x1, y);
  /* first split the input range so that x^y is in the same binade */
  float z0 = ref_pow (m0, e, y, MPFR_RNDZ);
  float z1 = ref_pow (m1, e, y, MPFR_RNDZ);
  int e0 = get_exp (z0);
  int e1 = get_exp (z1);
  if (e0 == e1)
  {
    search_binade_x (m0, m1, e, y);
    return;
  }
  /* split by dichotomy to find smallest x such that 2^(e0+1) <= x^y */
  uint32_t a = m0;
  uint32_t b = m1;
  while (a + 1 < b)
  {
    uint32_t c = (a + b) / 2;
    float z = ref_pow (c, e, y, MPFR_RNDZ);
    if (get_exp (z) == e0)
      a = c;
    else
      b = c;
  }
  assert (a + 1 == b);
  search_binade_x (m0, a, e, y);
  search_x (b, m1, e, y);
}

static void
search_z (uint32_t n0, uint32_t n1, int e, float y)
{
  // if (y == TRACEY && e == TRACEE && n0 <= TRACEZ && TRACEZ <= n1) printf ("search_z n0=%u n1=%u e=%d\n", n0, n1, e);
  assert (n0 <= n1);
  float x0 = ref_pow_inv ((y > 0) ? n0 : n1, e, y, MPFR_RNDZ);
  float x1 = ref_pow_inv ((y > 0) ? n1 : n0, e, y, MPFR_RNDZ);
  assert (x0 <= x1);
  if (d == 0)
  {
    search_binade_z (n0, n1, e, y);
    return;
  }
  /* for search_binade_quadratic_z we need to split into binades on the x-side */
  int e0 = get_exp (x0);
  int e1 = get_exp (x1);
  if (e0 == e1)
  {
    search_binade_z (n0, n1, e, y);
    return;
  }
  uint32_t a = n0;
  uint32_t b = n1;
  while (a + 1 < b)
  {
    uint32_t c = (a + b) / 2;
    float z = ref_pow_inv (c, e, y, MPFR_RNDZ);
    if (get_exp (z) == e0)
      a = c;
    else
      b = c;
  }
  assert (a + 1 == b);
  search_binade_z (n0, a, e, y);
  search_z (b, n1, e, y);
}

/* check worst cases with at least m identical bits after the round bit
   of x^y, for y = asfloat (n) */
static void
doit_x (float y)
{
  int emin, emax;
  uint32_t mmin = get_xmin (y, &emin);
  // printf ("y=%a mmin=%u emin=%d\n", y, mmin, emin);
  uint32_t mmax = get_xmax (y, &emax);
  // printf ("y=%a mmax=%u emax=%d\n", y, mmax, emax);
  if (verbose)
    printf ("y=%a xmin=%a xmax=%a\n", y, ldexpf (mmin, emin),
            ldexpf (mmax, emax));
  assert (emin < emax || (emin == emax && mmin <= mmax));
#ifdef COUNT
  uint64_t count = 0;
  while (emin < emax)
  {
    count += 0x1000000 - mmin;
    emin ++;
    mmin = 0x800000;
  }
  /* last binade */
  count += mmax - mmin;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tot_checks += count;
  return;
#endif
  while (emin < emax)
  {
    search_x (mmin, 0xffffff, emin, y);
    emin ++;
    mmin = 0x800000;
  }
  /* last binade is maybe incomplete */
  search_x (mmin, mmax, emin, y);
}

static void
doit_z (float y)
{
  // if (y == TRACEY) printf ("doit_z y=%a\n", y);
  int emin, emax;
  uint32_t zmin = get_zmin (y, &emin);
  // if (y == TRACEY) printf ("zmin=%u emin=%d\n", zmin, emin);
  assert (0x1000000 <= zmin && zmin < 0x2000000);
  uint32_t zmax = get_zmax (y, &emax);
  // if (y == TRACEY) printf ("zmax=%u emax=%d\n", zmax, emax);
  assert (0x1000000 <= zmax && zmax < 0x2000000);
  // if (y == TRACEY) printf ("doit_z y=%a emin=%d emax=%d\n", y, emin, emax);
  assert (emin < emax || (emin == emax && zmin <= zmax));
#ifdef COUNT
  uint64_t count = 0;
  while (emin < emax)
  {
    count += 0x2000000 - zmin;
    emin ++;
    zmin = 0x1000000;
  }
  count += zmax - zmin;
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp atomic update
#endif
  tot_checks += 2 * count;
  return;
#endif
  while (emin < emax)
  {
    // if (y == TRACEY) printf ("doit_z y=%a n0=%u n1=%u %d\n", y, zmin, 0x1ffffff, emin);
    search_z (zmin, 0x1ffffff, emin, y);
    // if (y == TRACEY && emin == TRACEE) abort();
    emin ++;
    zmin = 0x1000000;
  }
  /* last binade is maybe incomplete */
  search_z (zmin, zmax, emin, y);
}

static void
doit (uint32_t n)
{
#ifdef TIME
  int st = cputime ();
#endif
  float y = asfloat (n);
  if (inv == 0)
    doit_x (y);
  else
    doit_z (y);
#ifdef TIME
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp master
#endif
  printf ("# y=%a: %dms\n", y, cputime () - st);
#endif
}

int
main (int argc, char *argv[])
{
  /* print command line */
  printf ("#");
  for (int i = 0; i < argc; i++)
    printf (" %s", argv[i]);
  printf ("\n");
  fflush (stdout);

  /* y>0: for 0 < y < 0x1.3d46d8p-32, x^y = 1 (to nearest) for all binary32 x
     y<0: for -0x1.715478p-32 < y < 0, x^y = 1 for all binary32 x */
  /* y>0: for 0x1.9fe366p+30 < y, x^y = 0 or +Inf for x<>1 (to nearest)
     y<0: for y < -0x1.62e42ep+30, x^y = 0 or +Inf for x<>1 (to nearest) */
  float ymin = 0x1.3d46d8p-32f;
  float ymax = 0x1.9fe368p+30f; /* one ulp more since ymax is not treated */
  while (argc >= 2 && argv[1][0] == '-')
  {
    if (strcmp (argv[1], "-m") == 0)
    {
      target_m = atoi (argv[2]);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-d") == 0)
    {
      d = atoi (argv[2]);
      assert (d == 0 || d == 2);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-xmin") == 0)
    {
      Xmin = strtod (argv[2], NULL);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-xmax") == 0)
    {
      Xmax = strtod (argv[2], NULL);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-ymin") == 0)
    {
      ymin = strtod (argv[2], NULL);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-ymax") == 0)
    {
      ymax = strtod (argv[2], NULL);
      argv += 2;
      argc -= 2;
    }
    else if (strcmp (argv[1], "-inv") == 0)
    {
      inv = 1;
      argv += 1;
      argc -= 1;
    }
    else if (strcmp (argv[1], "-v") == 0)
    {
      verbose ++;
      argv += 1;
      argc -= 1;
    }
    else
    {
      fprintf (stderr, "Error, unknown option %s\n", argv[1]);
      exit (1);
    }
  }

  if (d == -1)
  {
    fprintf (stderr, "Error, missing -d option\n");
    exit (1);
  }

  assert (0 < target_m && target_m < 64);

  /* ymin and ymax should be of same sign */
  assert ((ymin > 0 && ymax > 0) || (ymin < 0 && ymax < 0));
  assert (ymin < ymax);
  uint32_t nmin, nmax;
  if (ymin > 0)
  {
    nmin = asuint (ymin);
    nmax = asuint (ymax);
  }
  else
  {
    nmin = asuint (ymax) + 1;
    nmax = asuint (ymin) + 1;
  }
  assert (nmin < nmax);
#ifndef COUNT
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
#else
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for
#endif
#endif
  for (uint32_t n = nmin; n < nmax; n++)
    doit (n);
  /* check y < 0 here */
  printf ("# tot_checks=%lu\n", tot_checks);
  printf ("# worst=%lu exact=%lu calls_mpfr_pow=%lu calls_print_sol=%lu\n",
          nsols, nexact, calls_mpfr_pow, calls_print_sol);
}
