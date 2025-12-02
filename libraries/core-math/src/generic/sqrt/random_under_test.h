static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [1,4] */
  return  (TYPE_UNDER_TEST) (3*((double) rand() / (double) RAND_MAX) + 1);
}
