#define cr_function_under_test cr_atan2pi
#define ref_function_under_test ref_atan2pi
#define mpfr_function_under_test mpfr_atan2pi

#define EXCHANGE_X_Y // first argument is named "y"

#define WORST_SYMMETRIC_X // test x and -x
#define WORST_SYMMETRIC_Y // test y and -y
#define WORST_SWAP        // test x,y and y,x
