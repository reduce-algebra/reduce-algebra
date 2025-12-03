/* sample in [-10,10] by default */

#ifndef XMAX
#define XMAX 10
#endif

#ifndef XMIN
#define XMIN -XMAX
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  return XMIN + (XMAX - XMIN) * ((double) rand() / (double) RAND_MAX);
}
