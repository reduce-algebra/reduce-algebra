static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* acos is defined over [-1,1] */
  return 2 * ((double) rand() / (double) RAND_MAX) - 1;
}
