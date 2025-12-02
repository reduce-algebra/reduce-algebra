#define cr_function_under_test cr_atanpi
#define ref_function_under_test ref_atanpi
#define mpfr_function_under_test mpfr_atanpi

/* we define WORST_SYMMETRIC, so that we can only put positive worst cases
   in atanpi.wc */
#define WORST_SYMMETRIC
