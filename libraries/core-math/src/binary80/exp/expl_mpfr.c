#include <mpfr.h>
#include "fenv_mpfr.h"

long double
ref_expl(long double x)
{
	mpfr_t y;
	mpfr_exp_t emin = mpfr_get_emin();
	mpfr_set_emin(-16444); 
	mpfr_init2(y, 64);
	mpfr_set_ld(y, x, MPFR_RNDN);
	int inex = mpfr_exp(y, y, rnd2[rnd]);
	mpfr_subnormalize (y, inex, rnd2[rnd]);
	long double ret = mpfr_get_ld(y, MPFR_RNDN);
	mpfr_clear(y);
	mpfr_set_emin(emin);
	return ret;
}
