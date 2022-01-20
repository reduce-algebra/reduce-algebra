// Measure times of various forms of memory access potentially relevant
// in multi-threaded work.

// A C Norman 2021-22.
// Available to anybody who wants any of this under the BSD license.

/*
This is a fairly naive test that performs a loop where the loop
content is a call to a function that increments a variable. The different
cases handle the variable in different ways. Well a base case does not
do an increment at all so established a baseline for the loop, and that is
reported as a timing of 1.0. The next uses a simple (static) variable.
Then there are two variations with use of std::atomic, one with relaxed
and one with sequentially consistent ordering (observe that on some CPUs
this difference makes no difference while on others it matters quite a lot!).
Then I protect the increment with a mutex, but here there is no contention.
Sometimes this leads to almost no overhead, sometimes it is bad. Finally I
make the variable that is being incremented thread local, and on Windows I
test a fairly unprincipled hack intended to boost performance there.

I think that a major message from this is that support for concurrency
using atomics, mutexes and thread local data may have rather different
performance profiles on different platforms. The differences are sufficiently
stark that it is very possible that slighly different patterns of use could
disrupt the timings suggested by the results here so these figures are not
definitive comments on the various platforms. However if taken at face value
these would suggest that on Linux and with low contention I might prefer
us of mutexes to std:atomic and that sequential consistency carries a penalty,
while on Windows the strategic design decision shoudld go the other way.

Here are some results I collected using "g++ -O3 -std=gnu++17 choices.c"
and it could be that the exact model of computer used in each is important
but I am not reporting that here since if this matters to you then you
need to run your own tests!

                    mingw  cygwin OldMac MacARM rpi64  rpi32 PClinux
Null operation       1.00    1.00   1.00   1.00  1.00   1.00   1.00
Simple variable      1.00    1.00   1.03   1.84  1.66   1.06   1.20
atomic (relaxed)     4.98    4.98   4.39   1.82  3.58   3.26   3.80
atomic (sequential)  4.95    4.98   4.38   6.14  5.35   4.56   3.80
mutex               10.53   60.58  12.29   7.95  1.84   1.24   1.40
mutex unique lock   10.52   60.41  12.29   7.97  2.44   1.40   1.60
mutex with wrapper  10.07   10.04   9.02  12.05 12.29  15.16  15.16
thread_local        11.11   29.36   1.72   1.84  1.63   2.17   1.20
WIN thread_local     1.00    1.00
*/

#include <atomic>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cinttypes>
#include <cstdint>
#include <mutex>

#include "mymutex.h"

// A loop that does noting to show measurement overhead.
[[gnu::noinline]] void NULLcase()
{
}

std::uintptr_t PLfringe;

// Use a simple variable with no thread protection at all.
[[gnu::noinline]] void PLcase()
{   PLfringe += 2*sizeof(void *);
}

std::mutex theMutex;

// Use a simple variable with simple mutex
[[gnu::noinline]] void Mucase()
{   std::lock_guard<std::mutex> lock(theMutex);
    PLfringe += 2*sizeof(void *);
}

// Use a simple variable with unique mutex
[[gnu::noinline]] void MUcase()
{   std::unique_lock<std::mutex> lock(theMutex);
    PLfringe += 2*sizeof(void *);
}

wrappedMutex theWrappedMutex;

// Use a simple variable with my mutex wrapper
[[gnu::noinline]] void Mycase()
{   std::lock_guard<wrappedMutex> lock(theWrappedMutex);
    PLfringe += 2*sizeof(void *);
}

std::atomic<std::uintptr_t> counter(0);

// Use a simple variable with my mutex wrapper but written out inline
[[gnu::noinline]] void Mycase1()
{   if (counter.fetch_add(1) != 0) UNLIKELY theMutex.lock();
    PLfringe += 2*sizeof(void *);
    if (counter.fetch_sub(1) != 1) UNLIKELY theMutex.unlock();
}

std::atomic<std::uintptr_t> ATfringe;

// An atomic variable but with "relaxed" memory ordering.
[[gnu::noinline]] void ATcase1()
{   ATfringe.fetch_add(2*sizeof(void *), std::memory_order_relaxed);
}

// An explicitly atomic variable with full sequential consistency.
[[gnu::noinline]] void ATcase()
{   ATfringe.fetch_add(2*sizeof(void *));
}

thread_local std::uintptr_t TLfringe;

// A thread_local variable.
[[gnu::noinline]] void TLcase()
{   TLfringe += 2*sizeof(void *);
}

#ifdef __CYGWIN__
#define WIN32 1
#endif

#ifdef WIN32

// This is going to use a scheme that uses a fixed slot in the
// Windows thread-block. It is utterly reliant on there not being
// changes to Windows and is really something of an abuse of the
// Microsoft API, but is intended to put speed above propriety!

#include "threadloc.h"

#define TL_fringe 48
DEFINE_THREAD_LOCAL(std::uintptr_t, WINfringe);

// Use A special Windows hack!
[[gnu::noinline]] void WINcase()
{   WINfringe += 2*sizeof(void *);
}

#endif // WIN32

typedef void proc();

static double t = 0.0;

void measure(std::string s, proc *p)
{   const size_t count = 200000000;

    std::chrono::high_resolution_clock::time_point clk, clk2;
    std::chrono::duration<double, std::micro> elapsed;
    std::chrono::nanoseconds timing;

    clk = std::chrono::high_resolution_clock::now();
    for (auto i=0; i<count; i++)
        (*p)();
    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    double t1 = timing.count();
// All timings will be reported as ratios againt the time of the empty loop.
    if (t == 0.0) t = t1;
    std::cout << s << std::fixed << std::setprecision(2) << std::setw(5)
              << (t1/t) << std::endl;
}

int main()
{
    measure("Null operation      ", NULLcase);
    measure("Simple variable     ", PLcase);
    measure("atomic (relaxed)    ", ATcase1);
    measure("atomic (sequential) ", ATcase);
    measure("mutex               ", Mucase);
    measure("mutex unique lock   ", MUcase);
    measure("wrappedMutex        ", Mycase);
    measure("wrappedMutex inline ", Mycase1);
    measure("thread_local        ", TLcase);
#ifdef WIN32
    initThreadLocals();
    measure("WIN thread_local    ", WINcase);
#endif

    return 0;
}

