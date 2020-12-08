#include <iostream>
#include <atomic>

std::atomic<int> v[1000000];

volatile int w = 0;

int main()
{   std::cout << "Starting" << std::endl;
    for (int i=0; i<1000000; i++) v[i] = i;
    for (int j=0; j<50000; j++)
    {   int r = 0;
        for (int i=0; i<1000000; i++) r += v[i];
        w += r;
    }
    std::cout << "Finishing " << w << std::endl;
    return 0;
}
