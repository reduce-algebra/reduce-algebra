#define pi 0x1.921fb54442d18p+1

/* sample in [-pi,pi] by default */
#ifndef XMIN
#define XMIN -pi
#endif
#ifndef XMAX
#define XMAX pi
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-pi,pi] */
  return (XMAX - XMIN) * ((double) rand() / (double) RAND_MAX) + XMIN;
}
