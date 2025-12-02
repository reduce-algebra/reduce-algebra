#define cr_function_under_test cr_exp2m1
#define ref_function_under_test ref_exp2m1
#define mpfr_function_under_test mpfr_exp2m1

/* exp2m1 is almost symmetric around 0: we define WORST_SYMMETRIC, so that
   we can put in exp2m1.wc only positive worst cases around zero */
#define WORST_SYMMETRIC
