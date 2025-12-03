#define cr_function_under_test cr_sincos
#define ref_function_under_test ref_sincos
#define mpfr_function_under_test mpfr_sin_cos

/* WORST_SYMMETRIC means that if x is a worst-case of f(x),
   then -x is a worst case too */
#define WORST_SYMMETRIC
