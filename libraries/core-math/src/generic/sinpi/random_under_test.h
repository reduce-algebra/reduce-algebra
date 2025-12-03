static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-4,4] */
  return 8 * ((double) rand() / (double) RAND_MAX) - 4;
}
