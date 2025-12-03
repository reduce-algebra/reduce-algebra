static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* const double low = exp(-0.5) - 1, high = exp(0.5) - 1; */
  const double low = -0x1.92e9a0720d3ecp-2, high = 0x1.4c2531c3c0d38p-1;
  return (high - low) * ((double) rand() / (double) RAND_MAX) + low;
}
