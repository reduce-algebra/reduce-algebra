/* Count/print non-trivial exact and midpoint cases for binary32 power function.

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

/* Exact cases are such that x^y is exactly representable in binary32.
   Midpoint cases are such that x^y is exactly in the middle of two representable
   binary32 numbers: the smallest possible value of x^y is 2^-150 (middle of 0
   and 2^-149), and the maximal one is 2^128*(1-2^-25) (middle of FLT_MAX and 2^128,
   which is not representable, but this would be a hard-to-round case for rounding
   to nearest).
   We don't count/print trivial solutions: |x|=1, y=0 or y=1.

   $ gcc -W -Wall exact.c -lm -lmpfr
   $ ./a.out # count all exact and midpoint cases
   ...
   # count=1071899
   $ ./a.out -mid 0 # count only exact cases
   ...
   # count=842073
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <mpfr.h>
#include <assert.h>

int print = 0; /* by default, we only count exact and midpoint cases */
int mid = 1;   /* by default, we count or print midpoint cases */
uint64_t count = 0; /* number of solutions */
int check = 0; /* check solutions */

static void
print_sol (float x, float y)
{
  if (check)
  {
    mpfr_t xx, yy, zz;
    int ret;
    mpfr_init2 (xx, 24);
    mpfr_init2 (yy, 24);
    mpfr_init2 (zz, 24 + mid);
    ret = mpfr_set_flt (xx, x, MPFR_RNDN);
    assert (ret == 0);
    ret = mpfr_set_flt (yy, y, MPFR_RNDN);
    assert (ret == 0);
    ret = mpfr_pow (zz, xx, yy, MPFR_RNDN);
    assert (ret == 0);
    mpfr_exp_t e = mpfr_get_exp (zz);
    assert (e <= 128);
    if (e < -125) /* smallest normal is 2^-126, which has MPFR exponent -125 */
    {
      /* check zz is an exact multiple of 2^(-149-mid) */
      mpfr_mul_2exp (zz, zz, 149 + mid, MPFR_RNDN);
      assert (mpfr_integer_p (zz));
    }
    mpfr_clear (xx);
    mpfr_clear (yy);
    mpfr_clear (zz);
  }
  count ++;
  if (print)
    printf ("%a,%a\n", x, y);
}

/* y positive integer: both x and -x are solutions */
static void
count_uint_y (int y)
{
  float xmin, xmax;
  int emin, emax;
  mpfr_t z;
  uint64_t local_count = 0;
  mpfr_init2 (z, 25);
  mpfr_set_ui_2exp (z, 1, -150, MPFR_RNDN);
  mpfr_rootn_ui (z, z, y, MPFR_RNDU);
  xmin = mpfr_get_flt (z, MPFR_RNDU);
  mpfr_set_ui_2exp (z, 1, 128, MPFR_RNDN);
  mpfr_nextbelow (z);
  mpfr_rootn_ui (z, z, y, MPFR_RNDD);
  xmax = mpfr_get_flt (z, MPFR_RNDD);
  /* we want xmin <= x <= xmax, with x^y exact */
  /* write x = m*2^e with m odd, m >= 3 */
  /* compute the maximum odd m such that m^y < 2^(24+mid) */
  mpfr_set_ui_2exp (z, 1, 24 + mid, MPFR_RNDN);
  mpfr_nextbelow (z);
  mpfr_rootn_ui (z, z, y, MPFR_RNDD);
  assert (mpfr_fits_sint_p (z, MPFR_RNDD));
  int maxm = mpfr_get_ui (z, MPFR_RNDD);
  /* since m*2^e <= xmax, we have 2^e <= xmax/m <= xmax/3 */
  mpfr_set_flt (z, xmax, MPFR_RNDD);
  mpfr_div_ui (z, z, 3, MPFR_RNDD);
  emax = mpfr_get_exp (z) - 1;
  /* for the minimal exponent, since x is an odd multiple of 2^e,
     x^y is an odd multiple of 2^(y*e), thus we want y*e >= -149-mid */
  emin = - ((149 + mid) / y);
  for (int e = emin; e <= emax; e++)
    for (int m = 3; m <= maxm; m += 2)
    {
      mpfr_set_ui_2exp (z, m, e, MPFR_RNDN);
      if (mpfr_cmp_d (z, xmin) >= 0 && mpfr_cmp_d (z, xmax) <= 0)
      {
        float x = mpfr_get_flt (z, MPFR_RNDN);
        print_sol (x, (float) y);
        local_count ++;
        print_sol (-x, (float) y);
        local_count ++;
      }

    }
  mpfr_clear (z);
  printf ("# y=%d: %lu\n", y, local_count);
}

/* y = n/2^f */
static void
count_uint_2exp_y (int n, int f)
{
  int F = 1 << f;
  float xmin, xmax;
  int emin, emax;
  mpfr_t z;
  uint64_t local_count = 0;
  float y = ldexpf (n, -f);
  mpfr_init2 (z, 25);
  mpfr_set_ui_2exp (z, 1, -150, MPFR_RNDN);
  mpfr_rootn_ui (z, z, n, MPFR_RNDU);
  mpfr_pow_ui (z, z, F, MPFR_RNDU);
  xmin = mpfr_get_flt (z, MPFR_RNDU);
  mpfr_set_ui_2exp (z, 1, 128, MPFR_RNDN);
  mpfr_nextbelow (z);
  mpfr_rootn_ui (z, z, n, MPFR_RNDD);
  mpfr_pow_ui (z, z, F, MPFR_RNDD);
  xmax = mpfr_get_flt (z, MPFR_RNDD);
  /* we want xmin <= x <= xmax, with x^y exact */
  /* write x = m*2^e with m odd, m >= 3, m = k^(2^f) */
  /* we should have both k^(2^f) < 2^24 and k^n < 2^(24+mid) */
  /* compute the maximum odd k such that k^(2^f) < 2^24 */
  mpfr_set_ui_2exp (z, 1, 24, MPFR_RNDN);
  mpfr_nextbelow (z);
  mpfr_rootn_ui (z, z, F, MPFR_RNDD);
  assert (mpfr_fits_sint_p (z, MPFR_RNDD));
  int maxk = mpfr_get_ui (z, MPFR_RNDD);
  /* compute the maximum odd k such that k^n < 2^(24+mid) */
  mpfr_set_ui_2exp (z, 1, 24 + mid, MPFR_RNDN);
  mpfr_nextbelow (z);
  mpfr_rootn_ui (z, z, n, MPFR_RNDD);
  assert (mpfr_fits_sint_p (z, MPFR_RNDD));
  int maxk2 = mpfr_get_ui (z, MPFR_RNDD);
  maxk = (maxk < maxk2) ? maxk : maxk2;
  /* Write x=m*2^e, we should have m=k^(2^f) and e multiple of 2^f,
     then x^y = k^n*2^(e*n/2^f).
     We should have m=k^(2^f) with k <= kmax. */
  /* since m*2^e <= xmax, we have 2^e <= xmax/m <= xmax/3 */
  mpfr_set_flt (z, xmax, MPFR_RNDD);
  mpfr_div_ui (z, z, 3, MPFR_RNDD);
  emax = mpfr_get_exp (z) - 1;
  /* for the minimal exponent, since x is an odd multiple of 2^e,
     x^y is an odd multiple of 2^(y*e), thus we want e >= -149 and y*e >= -149-mid */
  emin = - ((149 + mid) / y);
  if (emin < -149)
    emin = -149; /* so that x is representable */
  /* we should have e multiple of F */
  while (emin % F)
    emin ++;
  for (int e = emin; e <= emax; e += F)
  {
    for (int k = 3; k <= maxk; k += 2)
    {
      uint64_t m = k;
      for (int j = 0; j < f; j++)
        m = m * m;
      /* m (odd) should be less than 2^24 */
      assert (m < 0x1000000);
      mpfr_set_ui_2exp (z, m, e, MPFR_RNDN);
      if (mpfr_cmp_d (z, xmin) >= 0 && mpfr_cmp_d (z, xmax) <= 0)
      {
        print_sol (mpfr_get_flt (z, MPFR_RNDN), y);
        local_count ++;
      }
    }
  }
  mpfr_clear (z);
  printf ("# y=%a: %lu\n", y, local_count);
}

/* x = +/-2^e:
   for y integer, and -149-mid <= e*y <= 127, both x=2^e and -2^e are solutions
   for y=n/2^f for f>=1, n odd, we need e divisible by 2^f, and -149-mid <= e*y/2^f <= 127 */
static void
count_pow2_x (int e)
{
  uint64_t local_count = 0;
  if (e == 0) /* trivial solutions */
    return;

  /* case y integer */
  float x = ldexpf (1.0f, e);
  int ymin, ymax;
  if (e > 0)
  {
    ymin = - ((149+mid) / e);
    ymax = 127 / e;
  }
  else /* e < 0 */
  {
    ymin = - (127 / -e);
    ymax = (149+mid) / (-e);
  }
  for (int y = ymin; y <= ymax; y++)
    if (y != 0 && y != 1)
    {
      print_sol (x, (float) y);
      local_count ++;
      print_sol (-x, (float) y);
      local_count ++;
    }

  /* case y = n/2^f */
  int f = 1;
  while ((e % 2) == 0)
  {
    /* invariant: e = e_orig/2^f */
    e = e / 2;
    /* -149-mid <= e*y <= 127 */
    if (e > 0)
    {
      ymin = - ((149+mid) / e);
      ymax = 127 / e;
    }
    else /* e < 0 */
    {
      ymin = - (127 / -e);
      ymax = (149+mid) / (-e);
    }
    /* y should be odd */
    if ((ymin % 2) == 0)
      ymin ++;
    for (int y = ymin; y <= ymax; y += 2)
    {
      print_sol (x, ldexpf (y, -f));
      local_count ++;
    }
    f ++;
  }
  printf ("# x=2^%d: %lu\n", e, local_count);
}

int
main (int argc, char *argv[])
{
  while (argc >= 2 && argv[1][0] == '-')
  {
    if (strcmp (argv[1], "-print") == 0)
    {
      print = 1;
      argv ++;
      argc --;
    }
    else if (strcmp (argv[1], "-check") == 0)
    {
      check = 1;
      argv ++;
      argc --;
    }
    else if (argc >= 3 && strcmp (argv[1], "-mid") == 0)
    {
      mid = atoi (argv[2]);
      argv += 2;
      argc -= 2;
    }
    else
    {
      fprintf (stderr, "Error, unknown option %s\n", argv[1]);
      exit (1);
    }
  }

  /* First deal with integer y >= 2. If x is not a power of 2, then y <= 15
     whatever the value of mid, since 3^15 has 24 bits, and 3^16 has 26 bits.
     Indeed, assume x = m*2^e with m odd, then m >= 3, thus we should have
     m^y < 2^(24+mid). */
  for (int n = 2; n <= 15; n++)
    count_uint_y (n);
  /* Now deal with y = n/2^f for a positive integer f, and an odd n. If x is not a power of 2,
     assume x = m*2^e with m odd, m >= 3. Then m^(1/2^f) should be an odd integer >= 3,
     which implies f <= 3 whatever the value of mid, since 3^(2^3) has 13 bits, and 3^(2^4)
     has 26 bits.
     For the same reason as above, n <= 15. */
  for (int f = 1; f <= 3; f++)
    for (int n = 1; n <= 15; n += 2)
      count_uint_2exp_y (n, f);
  /* Now deal with x=2^e. */
  for (int e = -149; e <= 127; e++)
    count_pow2_x (e);
  printf ("# count=%lu\n", count);
}
