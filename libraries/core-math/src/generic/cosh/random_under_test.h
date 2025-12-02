static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-10,10] */
  return 20 * ((double) rand() / (double) RAND_MAX) - 10;
}
