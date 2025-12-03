static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-1,1] */
  return 2 * ((double) rand() / (double) RAND_MAX) - 1;
}
