static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-4.16,4.16] */
  return 8.32 * ((double) rand() / (double) RAND_MAX) - 4.16;
}
