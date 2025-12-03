#define CORE_MATH_BIVARIATE

static inline TYPE_UNDER_TEST random_under_test_0 (void)
{
  /* sample x in [0,6] since x^y gives NaN for x negative and y non-integer */
  return (TYPE_UNDER_TEST) (6 * ((double) rand() / (double) RAND_MAX));
}

/* For y, we allow negative values, as discussed on
   https://sympa.inria.fr/sympa/arc/core-math/2025-07/msg00001.html */
static inline TYPE_UNDER_TEST random_under_test_1 (void)
{
  /* sample y in [-6,6] */
  return (TYPE_UNDER_TEST) ((6 * ((double) rand() / (double) RAND_MAX)) - 12.0);
}
