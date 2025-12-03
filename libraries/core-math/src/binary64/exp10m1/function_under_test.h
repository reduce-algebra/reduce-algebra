#define cr_function_under_test cr_exp10m1
#define ref_function_under_test ref_exp10m1
#define mpfr_function_under_test mpfr_exp10m1

/* exp10m1 is almost symmetric around 0: we define WORST_SYMMETRIC, so that
   we can put in exp10m1.wc only positive worst cases around zero */
#define WORST_SYMMETRIC
