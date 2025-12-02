// compute worst cases of bfloat16 pow
// x=0x1.fep-1 y=0x1p-133 err=4.600767e-41
// count=1073068453

// define IGNORE_ONE to ignore results rounding to 1
// #define IGNORE_ONE
// with IGNORE_ONE
// x=0x1.8p+108 y=0x1.bp-13 err=1.200418e-09 ~ 2^-29.6 ulp

// define SUBNORMAL to only consider x^y in the subnormal range
// and then we consider the error with respect to 2^-133
#define SUBNORMAL
// with SUBNORMAL
// x=0x1.08p-90 y=0x1.7ap+0 err=7.327734e-09

#include <stdio.h>
#include <stdint.h>
#include <mpfr.h>
#include <math.h>
#include <assert.h>
#include <omp.h>

double minerr = 1;
unsigned long count = 0;

typedef union {__bf16 f; uint16_t u;} b16u16_u;

// compare x^y with 2^e
static int
compare (__bf16 x, __bf16 y, int e)
{
  mpfr_t X, Y;
  mpfr_init2 (X, 8);
  mpfr_init2 (Y, 8);
  mpfr_set_flt (X, (float) x, MPFR_RNDN);
  mpfr_set_flt (Y, (float) y, MPFR_RNDN);
  mpfr_pow (X, X, Y, MPFR_RNDZ);
  mpfr_set_ui (Y, 1, MPFR_RNDZ);
  mpfr_mul_2si (Y, Y, e, MPFR_RNDZ);
  int ret = mpfr_cmp (X, Y);
  mpfr_clear (X);
  mpfr_clear (Y);
  return ret;
}

static double
get_err (__bf16 x, __bf16 y)
{
  mpfr_t X, Y;
  mpfr_init2 (X, 255);
  mpfr_init2 (Y, 9);
  mpfr_set_flt (X, (float) x, MPFR_RNDN);
  mpfr_set_flt (Y, (float) y, MPFR_RNDN);
  int inex = mpfr_pow (X, X, Y, MPFR_RNDN);
  inex = mpfr_set (Y, X, MPFR_RNDN) | inex; // round to 9 bits
#ifdef IGNORE_ONE
  if (mpfr_cmp_ui (Y, 1) == 0) inex = 0;
#endif
  mpfr_sub (X, X, Y, MPFR_RNDN);
  mpfr_abs (X, X, MPFR_RNDN);
  assert (!mpfr_zero_p (Y));
  mpfr_exp_t ey = mpfr_get_exp (Y);
#ifdef SUBNORMAL
  if (ey <= -133 || -125 <= ey)
    inex = 0;
  double u = 0x1p-133;
#else
  double u = pow (2.0, ey - 8);
#endif
  double ret = mpfr_get_d (X, MPFR_RNDN) / u;
  mpfr_clear (X);
  mpfr_clear (Y);
  return (inex == 0) ? 0 : ret;
}

static void
doit (__bf16 y)
{
  /* search the largest range [x0,x1] such that for x0 <= x <= x1,
     we have 2^-134 <= |x^y| < 2^128 */
  b16u16_u x0, x1, a, b;
  if (fabs (y) <= 1) {
    x0.f = 0x1p-133f;
    x1.f = 0x1.fep+127f;
  } else if (y > 0) { // y > 0: x^y is increasing
    // determine x0 by binary search
    a.f = 0x1p-133f;
    b.f = 0x1.fep+127f;
    while (a.u + 1 < b.u) {
      b16u16_u c = {.u = (a.u + b.u) / 2};
      if (compare (c.f, y, -134) >= 0) // c^y >= 2^-134
        b.f = c.f;
      else // c^y < 2^-134
        a.f = c.f;
    }
    x0.f = b.f; // for all y > 1, (2^-133)^y < 2^-134
    // determine x1 by binary search
    a.f = 0x1p-133f;
    b.f = 0x1.fep+127f;
    while (a.u + 1 < b.u) {
      b16u16_u c = {.u = (a.u + b.u) / 2};
      if (compare (c.f, y, 128) >= 0) // c^y > 2^128
        b.f = c.f;
      else // c^y <= 2^128
        a.f = c.f;
    }
    x1.f = a.f;
  } else { // case y < 0: x^y is decreasing
    // determine x1 by binary search
    a.f = 0x1p-133f;
    b.f = 0x1.fep+127f;
    while (a.u + 1 < b.u) {
      b16u16_u c = {.u = (a.u + b.u) / 2};
      if (compare (c.f, y, -134) >= 0) // c^y >= 2^-134
        a.f = c.f;
      else // c^y < 2^-134
        b.f = c.f;
    }
    x1.f = a.f;
    // determine x0 by binary search
    a.f = 0x1p-133f;
    b.f = 0x1.fep+127f;
    while (a.u + 1 < b.u) {
      b16u16_u c = {.u = (a.u + b.u) / 2};
      if (compare (c.f, y, 128) > 0) // c^y > 2^128
        a.f = c.f;
      else // c^y <= 2^128
        b.f = c.f;
    }
    x0.f = a.f;
  }
  if (x1.u < x0.u) printf ("y=%a x0=%a x1=%a\n", (float) y, (float) x0.f, (float) x1.f);
  assert (x0.u <= x1.u);

#pragma omp atomic update
  count += x1.u - x0.u + 1;
#pragma omp parallel for
  for (uint16_t ux = x0.u; ux <= x1.u; ux++) {
    b16u16_u x = {.u = ux};
    double err = get_err (x.f, y);
#pragma omp critical
    if (err != 0 && err < minerr)
      printf ("x=%a y=%a err=%e\n", (float) x.f, (float) y, minerr = err);
  }
}

int
main()
{
  for (uint16_t uy = 1; uy < 0x7f80; uy++) {
    b16u16_u v = {.u = uy};
    __bf16 y = v.f;
    doit (y);
    doit (-y);
  }
  printf ("count=%lu\n", count);
}
