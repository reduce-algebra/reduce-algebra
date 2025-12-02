static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [-4,4] (for binary16 tanh(x) rounds to 1 for x > 4.51) */
  return 8 * ((double) rand() / (double) RAND_MAX) - 4;
}
