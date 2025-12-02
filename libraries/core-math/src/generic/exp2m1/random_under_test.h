/* sample in [-10,10] by default */
#ifndef XMIN
#define XMIN -10.0
#endif
#ifndef XMAX
#define XMAX 10.0
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  return (XMAX - XMIN) * ((TYPE_UNDER_TEST) rand() / (TYPE_UNDER_TEST) RAND_MAX) + XMIN;
}
