static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-20,20] */
  return 40. * ((double) rand() / (double) RAND_MAX) - 20.0;
}
