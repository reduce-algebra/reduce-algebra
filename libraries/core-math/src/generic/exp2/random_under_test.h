static inline TYPE_UNDER_TEST random_under_test (void)
{
  /* Sample in [-10,10]. We first generate using doubles, since
     RAND_MAX is not representable in float16. */
  double r = 20 * ((double) rand() / (double) RAND_MAX) - 10;
  return (TYPE_UNDER_TEST) r;

  /* for performance test of denormal results in the binary64 format */
  /* return -0x1.205966f2b4f1p+5*((TYPE_UNDER_TEST) rand() / (TYPE_UNDER_TEST) RAND_MAX) - 0x1.6232bdd7abcd2p+9; */
}
