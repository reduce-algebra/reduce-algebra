#define cr_function_under_test cr_erf
#define ref_function_under_test ref_erf
#define mpfr_function_under_test mpfr_erf

/* WORST_SYMMETRIC means that if x is a worst-case of f(x),
   then -x is a worst case too */
#define WORST_SYMMETRIC
