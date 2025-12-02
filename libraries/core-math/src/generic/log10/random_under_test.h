static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* sample in [exp(-1),exp(1)] */
  const double low = 0x1.78b56362cef38p-2, high = 0x1.5bf0a8b145769p+1;
  return (TYPE_UNDER_TEST) ((high - low) * ((double) rand() / (double) RAND_MAX) + low);
}
