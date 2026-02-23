
#include <iostream>

const static bool avx_available =
   ([]()->bool
    {  __builtin_cpu_init();
       return __builtin_cpu_supports("avx");
    })();
const static bool sse4_available =
   ([]()->bool
    {  return __builtin_cpu_supports("sse4.2");
    })();


int main()
{   std::cout << avx_available << " " << sse4_available << "\n";
    return 0;
}
