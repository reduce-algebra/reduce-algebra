static mpfr_rnd_t rnd2[] = { MPFR_RNDN, MPFR_RNDZ, MPFR_RNDU, MPFR_RNDD };

static int rnd = 0; /* default is to nearest */

int ref_fesetround(int rounding_mode)
{
  /* With OpenMP, rnd is a global variable, but should be set to the same
     value by all threads. */
#if (defined(_OPENMP) && !defined(CORE_MATH_NO_OPENMP))
#pragma omp critical
#endif
  rnd = rounding_mode;
  return 0;
}

void ref_init(void)
{
  mpfr_set_emin (-132);
  mpfr_set_emax (128);
}
