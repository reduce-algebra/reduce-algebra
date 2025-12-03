static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-5,5] */
#define XMIN -5.0
#define XMAX +5.0
  return (XMAX - XMIN) * ((double) rand() / (double) RAND_MAX) + XMIN;
}
