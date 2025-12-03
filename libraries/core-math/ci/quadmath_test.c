#include <quadmath.h>
#ifdef __x86_64__
#include <x86intrin.h>
#endif

typedef unsigned __int128 u128;

int main(){
#if defined(__x86_64__) && !defined(__clang__)
  __m128i m = {0, 0};
  u128 t = 0;
  m = _mm_insert_epi64 (m, t, 0);
#endif
}
