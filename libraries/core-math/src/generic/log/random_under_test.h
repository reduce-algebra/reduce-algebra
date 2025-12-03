/* sample in [exp(-1),exp(1)] by default */

#ifndef XMIN
#define XMIN 0x1.78b56362cef38p-2
#endif

#ifndef XMAX
#define XMAX 0x1.5bf0a8b145769p+1
#endif

static inline TYPE_UNDER_TEST random_under_test (void)
{
  const double low = XMIN, high = XMAX;
  return (TYPE_UNDER_TEST) ((high - low) * ((double) rand() / (double) RAND_MAX) + low);
}
