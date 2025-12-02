#include <stdio.h>
#include <stdint.h>
#include <mpfr.h>
#include <fenv.h>
#include <math.h>
#include <float.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif
#include <stdbool.h>
#include <assert.h>

/* Define MODE=0 to analyze the maximal value of the ratios
   |mlogrh/mlogr12h|, |mlogr1h/mlogr12h|, |mlogr2h/mlogr12h|.
   With -DMODE=0 we get these last lines as output (where the ratios
   are rounded upwards):

r=0 extra_int=0 i1=126 i2=15 |mlogrh/mlogr12h|=0x1.f33513c1b9974p+0
r=0 extra_int=0 i1=126 i2=15 |mlogr1h/mlogr12h|=0x1.f33513c1b9974p+0
r=0 extra_int=0 i1=0 i2=1 |mlogr2h/mlogr12h|=0x1p+0

   thus the first two ratios are bounded by 0x1.f33513c1b9974p+0 < 1.951,
   and the last one by 1.

   Define MODE=1 to analyze the maximal relative error between the
   computed value mlogr12h + mlogr12l and the true value
   (add -fopenmp on the command line to make the computation faster).
   With -DMODE=1 we get these last lines as output:

r=1 extra_int=258 i1=3 i2=12 err=7.110497e-32
r=1 extra_int=258 i1=59 i2=12 err=7.182856e-32
r=1 extra_int=8194 i1=16 i2=17 err=7.235989e-32

   This means the largest relative error is 7.235989e-32 < 2^-103.446,
   obtained for rounding to zero (RNDZ), with extra_int=8194, i1=16, i2=17.

   Define MODE=2 to analyse the maximal value of |mlogr12l/mlogr12h|.
   With -DMODE=2 we get these last lines as output:

r=1 extra_int=-513 i1=43 i2=1 |mlogr12l/mlogr12h|=4.4084763153344564e-16
r=2 extra_int=-513 i1=43 i2=1 |mlogr12l/mlogr12h|=4.4084763153344570e-16
r=2 extra_int=512 i1=43 i2=1 |mlogr12l/mlogr12h|=4.4097994937579496e-16

   This means the largest value of |mlogr12l/mlogr12h| is
   4.4097994937579496e-16 < 2^-51.010.

   Define MODE=3 to find the smallest non-zero value of |mlogr12h|,
   after the renormalization. With -DMODE=3 we get:

r=0 extra_int=0 i1=0 i2=1 |mlogr12h|=0x1.150c5586012b8p-11
r=0 extra_int=0 i1=127 i2=125 |mlogr12h|=0x1.7148ec2a1bfc9p-12
r=1 extra_int=0 i1=127 i2=125 |mlogr12h|=0x1.7148ec2a1bfc8p-12

   Thus the smallest non-zero value of |mlogr12h| is 0x1.7148ec2a1bfc8p-12.
*/

#ifndef MODE
#error "You should define MODE (0, 1, or 2)"
#endif

typedef union {long double f; struct {uint64_t m; uint16_t e;};} b80u80_t;

#define POWL_DPRINTF(x,y,z)

#include "qint.h"
#include "powl_tables.h"

// return non-zero iff the combination (i1,i2) is possible
static int
is_possible (int i1, int i2)
{
  assert (0 <= i1 && i1 < 128);
  double xmin = 1.0 + (double) i1 * 0x1p-7;
  double xmax = 1.0 + (double) (i1 + 1) * 0x1p-7;
  double r1 = coarse[i1].r;
  xmin = r1 * xmin;
  xmax = r1 * xmax;
  // [xmin, xmax] is near 1, whatever the value of coarse[i1].z
  assert ((0 <= i2 && i2 < 32) || (32 <= i2 && i2 < 128));
  double ymin, ymax;
  if (i2 < 32)
  {
    ymin = 1.0 + (double) i2 * 0x1p-12;
    ymax = 1.0 + (double) (i2 + 1) * 0x1p-12;
  }
  else
  {
    ymin = 1.0 - 0x1p-7 + (double) (i2 - 64) * 0x1p-13;
    ymax = 1.0 - 0x1p-7 + (double) (i2 + 1 - 64) * 0x1p-13;
  }
  return (xmax <= ymin || ymax <= xmin) ? 0 : 1;
}

static inline
void fast_two_sum(double* rh, double* rl, double a, double b) {
	*rh = a + b;
	double e = *rh - a;
	*rl = b - e;
}

/* Computes an approximation of a + bh + bl assuming a = 0 or |a| >= |bh|*/
static inline
void high_sum(double* rh, double* rl, double a, double bh, double bl) {
	double e;
	fast_two_sum(rh, &e, a, bh);
	*rl = bl + e;
}

// return |mlogr12h + mlogr12l - (extra_int - log2(r1) - log2(r2)| / |mlogr12h|
static double
compute_error (int extra_int, int i1, int i2, double mlogr12h, double mlogr12l)
{
  mpfr_t x, y;
  mpfr_init2 (x, 127);
  mpfr_init2 (y, 127);
  // compute in x the sum with 127-bit precision
  mpfr_set_si (x, extra_int, MPFR_RNDN);
  mpfr_set_d (y, coarse[i1].r, MPFR_RNDN);
  if (coarse[i1].z)
    mpfr_mul_2ui (y, y, 1, MPFR_RNDN);
  mpfr_log2 (y, y, MPFR_RNDN);
  mpfr_sub (x, x, y, MPFR_RNDN);
  mpfr_set_d (y, fine[i2].r, MPFR_RNDN);
  mpfr_log2 (y, y, MPFR_RNDN);
  mpfr_sub (x, x, y, MPFR_RNDN);
  // put in y the value of mlogr12h + mlogr12l
  mpfr_set_d (y, mlogr12h, MPFR_RNDN);
  mpfr_add_d (y, y, mlogr12l, MPFR_RNDN);
  mpfr_sub (x, x, y, MPFR_RNDN);
  mpfr_abs (x, x, MPFR_RNDN);
  double err = mpfr_get_d (x, MPFR_RNDN);
  mpfr_clear (x);
  mpfr_clear (y);
  return err / mlogr12h;
}

// return |a/b| rounded up
static double get_ratio (double a, double b)
{
  a = fabs (a);
  b = fabs (b);
  int r = fegetround ();
  fesetround (FE_UPWARD);
  double ratio = a / b;
  fesetround (r);
  return ratio;
}

// find by brute-force the maximal relative error of the 2nd high_sum call
// in compute_log2pow()
static void
analyze_second_sum (void)
{
  double maxerr = 0, maxratio1 = 0, maxratio2 = 0, maxratio3 = 0;
  double min_mlogr12h = DBL_MAX;
  static int R[4] = {FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD};
  for (int r = 0; r < 4; r++)
  {
    fesetround (R[r]);
#if MODE==1
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(static,1)
#endif
#endif
    for (int extra_int = -16382; extra_int < 16384; extra_int ++)
      for (int i1 = 0; i1 < 128; i1++)
      {
        double mlogr1h = coarse[i1].mlogrh;
        double mlogr1l = coarse[i1].mlogrl;
        double mlogrh, mlogrl;
        high_sum(&mlogrh, &mlogrl, (double) extra_int, mlogr1h, mlogr1l);
        for (int i2 = 0; i2 < 128; i2++)
        {
          if (32 <= i2 && i2 < 64)
            continue;
          if (!is_possible (i1, i2))
            continue;
          double mlogr2h = fine[i2].mlogrh;
          double mlogr2l = fine[i2].mlogrl;
          // printf ("%d %d %d %d\n", r, extra_int, i1, i2);
          double mlogr12h, mlogr12l;
          high_sum(&mlogr12h, &mlogr12l, mlogrh, mlogr2h, mlogr2l);
          mlogr12l += mlogrl;
#if MODE==0
          double ratio1 = get_ratio (mlogrh, mlogr12h);
          double ratio2 = get_ratio (mlogr2h, mlogr12h);
          double ratio3 = get_ratio (mlogr1h, mlogr12h);
          if (ratio1 > maxratio1)
            printf ("r=%d extra_int=%d i1=%d i2=%d |mlogrh/mlogr12h|=%la\n",
                    r, extra_int, i1, i2, maxratio1 = ratio1);
          if (ratio2 > maxratio2)
            printf ("r=%d extra_int=%d i1=%d i2=%d |mlogr2h/mlogr12h|=%la\n",
                    r, extra_int, i1, i2, maxratio2 = ratio2);
          if (ratio3 > maxratio3)
            printf ("r=%d extra_int=%d i1=%d i2=%d |mlogr1h/mlogr12h|=%la\n",
                    r, extra_int, i1, i2, maxratio3 = ratio3);
          fflush (stdout);
#elif MODE==1
          double err = compute_error (extra_int, i1, i2, mlogr12h, mlogr12l);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
          if (err > maxerr)
          {
            printf ("r=%d extra_int=%d i1=%d i2=%d err=%e\n",
                    r, extra_int, i1, i2, maxerr = err);
            // printf ("r1=%la r2=%la mlogr12h=%la mlogr12l=%la\n", coarse[i1].r, fine[i2].r, mlogr12h, mlogr12l);
          }
#elif MODE==2
          double ratio1 = fabs (mlogr12l / mlogr12h);
          if (ratio1 > maxratio1)
            printf ("r=%d extra_int=%d i1=%d i2=%d |mlogr12l/mlogr12h|=%.16e\n",
                    r, extra_int, i1, i2, maxratio1 = ratio1);
#elif MODE==3
          fast_two_sum(&mlogr12h, &mlogr12l, mlogr12h, mlogr12l);
          if (mlogr12h != 0 && fabs (mlogr12h) < min_mlogr12h)
            printf ("r=%d extra_int=%d i1=%d i2=%d |mlogr12h|=%la\n",
                    r, extra_int, i1, i2, min_mlogr12h = fabs (mlogr12h));
#else
#error "Invalid value of MODE"
#endif
        }
      }
  }
}

static void
count_possible (void)
{
  int possible = 0;
  for (int i1 = 0; i1 < 128; i1++)
    for (int i2 = 0; i2 < 128; i2++)
      if (i2 < 32 || 64 <= i2)
        possible += is_possible (i1, i2);
  printf ("Number of possible (i1,i2) combinations: %d\n", possible);
}

int
main ()
{
  count_possible ();
  analyze_second_sum ();
  return 0;
}
