#define cr_function_under_test cr_log2p1
#define ref_function_under_test ref_log2p1
#define mpfr_function_under_test mpfr_log2p1

/* the function log2p1 is almost symmetric around 0, we define WORST_SYMMETRIC
   so that we can put only positive worst cases around 0 in log2p1.wc */
#define WORST_SYMMETRIC
