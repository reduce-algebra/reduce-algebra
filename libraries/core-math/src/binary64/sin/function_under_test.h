#define cr_function_under_test cr_sin
#define ref_function_under_test ref_sin
#define mpfr_function_under_test mpfr_sin

/* WORST_SYMMETRIC means that if x is a worst-case of f(x),
   then -x is a worst case too */
#define WORST_SYMMETRIC
