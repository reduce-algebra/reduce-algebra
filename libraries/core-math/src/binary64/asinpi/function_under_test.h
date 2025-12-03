#define cr_function_under_test cr_asinpi
#define ref_function_under_test ref_asinpi
#define mpfr_function_under_test mpfr_asinpi

/* we define WORST_SYMMETRIC, so that we can only put positive worst cases
   in asinpi.wc */
#define WORST_SYMMETRIC
