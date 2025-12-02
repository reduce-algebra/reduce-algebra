#define cr_function_under_test cr_acos
#define ref_function_under_test ref_acos
#define mpfr_function_under_test mpfr_acos

// the following says that if x is in acos.wc, -x will be tested too
#define WORST_SYMMETRIC
