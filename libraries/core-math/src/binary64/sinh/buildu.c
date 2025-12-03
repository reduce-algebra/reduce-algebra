#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#include <omp.h>
#endif

int next_print = 0;
double maxerr = 0;
double U[256][3] = {};

static int
sinh_ok (mpfr_t x, int k)
{
  mpfr_t y;
  int ret;
  mpfr_init2 (y, 53 + k);
  mpfr_sinh (y, x, MPFR_RNDN);
  ret = mpfr_min_prec (y) <= 53;
  mpfr_clear (y);
  return ret;
}

static int
cosh_ok (mpfr_t x, int k)
{
  mpfr_t y;
  int ret;
  mpfr_init2 (y, 53 + k);
  mpfr_cosh (y, x, MPFR_RNDN);
  ret = mpfr_min_prec (y) <= 53;
  mpfr_clear (y);
  return ret;
}

static void
doit (int i, int k)
{
  double h = 0x1.633d9a9a6cd52p-7;
  mpfr_t x0, x1;
  mpfr_init2 (x0, 53);
  mpfr_init2 (x1, 53);
  if (i == 0)
    mpfr_set_ui (x0, 0, MPFR_RNDN);
  else
  {
    mpfr_set_d (x0, h*i, MPFR_RNDN);
    mpfr_set (x1, x0, MPFR_RNDN);
    while (1)
    {
      if (sinh_ok (x0, k) && cosh_ok (x0, k))
        break;
      mpfr_nextbelow (x0);
      mpfr_nextabove (x1);
      if (sinh_ok (x1, k) && cosh_ok (x1, k))
      {
        mpfr_set (x0, x1, MPFR_RNDN);
        break;
      }
    }
  }
  mpfr_set_d (x1, h*i, MPFR_RNDN);
  mpfr_sub (x1, x0, x1, MPFR_RNDN);
  mpfr_abs (x1, x1, MPFR_RNDN);
  double err = mpfr_get_d (x1, MPFR_RNDN);
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
  U[i][0] = mpfr_get_d (x0, MPFR_RNDN);
  mpfr_sinh (x1, x0, MPFR_RNDN);
  U[i][1] = mpfr_get_d (x1, MPFR_RNDN);
  mpfr_cosh (x1, x0, MPFR_RNDN);
  U[i][2] = mpfr_get_d (x1, MPFR_RNDN);
  {
    if (err > maxerr)
      maxerr = err;
    while (next_print < 256 && U[next_print][0] != -1)
    {
      printf ("   {%la, %la, %la}, /* i=%d */\n", U[next_print][0],
              U[next_print][1], U[next_print][2], next_print);
      next_print ++;
    }
  }
  mpfr_clear (x0);
  mpfr_clear (x1);
}

int
main (int argc, char *argv[])
{
  int k = atoi (argv[1]);
  for (int i = 0; i < 256; i++)
    U[i][0] = -1;
  printf ("static const double U[256][3] = {\n");
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp parallel for schedule(dynamic,1)
#endif
  for (int i = 0; i < 256; i++)
    doit (i, k);
  printf ("};\n");
  printf ("maxerr=%e\n", maxerr);
}
