#define CORE_MATH_BIVARIATE

static inline TYPE_UNDER_TEST random_under_test_0 (void)
{
  /* 
    Sample x in [-0.0002,0.0002] since (1+x)^y should be mainly used for x near zero.
  */
  return (((double) rand() / (double) RAND_MAX) - 0.5)*0.0004;
}

static inline TYPE_UNDER_TEST random_under_test_1 (void)
{
  /*
    Sample integer y in (-1024,1024] since (1+x)^y is supposed to be used mainly for large integer y.
  */
  return (rand()&0x7ff) - 0x3ff;
}
