// This code is to help me track performance of thread_local values with
// C++ on various platforms. At the time of writing g++ for Cygwin uses
// "emutls" with rather severe cost consequences!

// I can try this on Windows every so often. I really hope that at some stage
// it will show up a change that removes the bad costs of emutls, because
// then I can safely move to using the C++ "thread_local" qualifier in my
// code rather than the significantly messy scheme I use now!

#include <iostream>
#include <chrono>

// The use of "volatile" and "[[gnu::noinline]]" is to (try to) prevent
// compiler optimisations that otherwise defeat the purpose of this test!

volatile size_t inc = 1;
volatile size_t x1 = 0;
thread_local volatile size_t x2 = 0;
static const size_t count = 1000000000U;

[[gnu::noinline]] void incx1()
{   x1 += inc;
}

[[gnu::noinline]] void incx2()
{   x2 += inc;
}

int main()
{
    std::chrono::high_resolution_clock::time_point clk, clk2;
    std::chrono::duration<double, std::micro> elapsed;
    std::chrono::nanoseconds timing;

    x1 = 0;
    clk = std::chrono::high_resolution_clock::now();

    for (size_t i=0; i<count; i++)
        incx1();

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Time = " << timing.count()/1000000 << " ms" << std::endl;
    std::cout << x1 << std::endl;

    x2 = 0;
    clk = std::chrono::high_resolution_clock::now();

    for (size_t i=0; i<count; i++)
        incx2();

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Time = " << timing.count()/1000000 << " ms" << std::endl;
    std::cout << x2 << std::endl;
    return 0;
}



