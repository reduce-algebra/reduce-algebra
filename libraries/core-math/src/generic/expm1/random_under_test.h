/* sample in [-1,1] by default */

#ifndef XMIN
#define XMIN -0.5
#endif

#ifndef XMAX
#define XMAX 0.5
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  return (XMAX - XMIN) * ((TYPE_UNDER_TEST) rand() / (TYPE_UNDER_TEST) RAND_MAX) + XMIN;
}
