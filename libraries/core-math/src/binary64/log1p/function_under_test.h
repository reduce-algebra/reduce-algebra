#define cr_function_under_test cr_log1p
#define ref_function_under_test ref_log1p
#define mpfr_function_under_test mpfr_log1p

/* log1p is not symmetric, but for tiny values around 0, it behaves
   like x, thus it is almost symmetric */
#define WORST_SYMMETRIC

