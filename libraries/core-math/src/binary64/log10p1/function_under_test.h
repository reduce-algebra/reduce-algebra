#define cr_function_under_test cr_log10p1
#define ref_function_under_test ref_log10p1
#define mpfr_function_under_test mpfr_log10p1

/* log10p1 is not symmetric, but for tiny values around 0, it behaves
   as x/log(10), thus it is almost symmetric */
#define WORST_SYMMETRIC
