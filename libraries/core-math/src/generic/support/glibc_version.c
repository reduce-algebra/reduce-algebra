#include <stdio.h>
/* warning: clang defines __GNUC__ on MacOS */
#if defined(__GNUC__) && !defined(__MACH__)
#include <gnu/libc-version.h>
#endif

int main() {
#if defined(__GNUC__) && !defined(__MACH__)
  printf ("GNU libc version: %s\n", gnu_get_libc_version ());
  printf ("GNU libc release: %s\n", gnu_get_libc_release ());
#endif
  return 0;
}
