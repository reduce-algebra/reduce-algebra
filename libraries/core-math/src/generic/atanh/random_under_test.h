#ifndef XMAX
#define XMAX 1.0
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-XMAX,XMAX] */
  return 2.0 * XMAX * ((double) rand() / (double) RAND_MAX) - XMAX;
}
