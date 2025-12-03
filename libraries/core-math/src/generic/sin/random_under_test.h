#define pi 0x1.921fb54442d18p+1

static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-pi,pi] */
  return (TYPE_UNDER_TEST) (2 * pi * ((double) rand() / (double) RAND_MAX) - pi);
}
