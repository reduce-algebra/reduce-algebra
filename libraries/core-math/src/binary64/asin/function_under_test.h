#define cr_function_under_test cr_asin
#define ref_function_under_test ref_asin
#define mpfr_function_under_test mpfr_asin

/* we define WORST_SYMMETRIC, so that we can only put positive worst cases
   in asin.wc */
#define WORST_SYMMETRIC
