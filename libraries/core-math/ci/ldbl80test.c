#include <float.h>

#if LDBL_MANT_DIG != 64
#error "Long double is not binary80"
#endif
