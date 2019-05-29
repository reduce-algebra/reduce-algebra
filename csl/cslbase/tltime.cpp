// tltime.c                                       Copyright A C Norman 2019

// Released under the modified BSD license - you can find the terms
// of that easily enough!

// $Id$

// Cygwin and mingw32 both seem to use "emutls" to support the C++11
// keyword "thread_local". This can have performance consequences.
//
// The first thing is that this code illustrates is that in a worst case
// scenario where a small and heavily-used function accesses a thread_local
// variable the emutls scheme on x86_64 imposes a penalty that is a factor
// of up to 20. The use-case I had in mind was a function like:
//    void *allocate(size_t n)
//    {   void *r = (void *)fringe;
//        if ((fringe += n) < limit) return r;
//        ...
//    }
// where making the variables fringe and limit thread_local can really hurt
// overall system-wide performance.
//
// The resolution proposed here starts by giving up on the flexibility that
// C++11 thread_local provides as regards declaring thread_local variables
// anywhere and sometimes initializing them at the side of their definition.
// It places all values that need to be thread_local (or at least all those
// where access will be performance critical) in a structure, and using a
// low level scheme to get a thread-specific pointer to that structure.
// Allocating and initializing the thread-local structure is not an issue
// addressed here! I use the Windows TlsAlloc, TlsSetValue and TlsGetValue
// functions. I have two versions of this, one using the official Windows
// entrypoints and the other re-implementing TlsGetValue (but omitting
// validity checks!) such that it can be expanded in-line in my code.
//
// To use this one needs to collect all (or most) thread local variables
// and replace them with structure members as in
//    typedef struct hread_locals_
//    {   uintptr_t fringe;
//        uintptr_t limit;
//        ...
//    } thread_locals;
//    thread_local thread_locals my_thread_locals;
// Then at the startup of your code you need to allocate my_slot as shown
// in the main() function here, and in EVERY thread you start you must go
//    TlsSetValue(my_slot, (void *)&my_thread_locals);
// With that done, what used to be a simple reference to a variable, fringe
// say, must be rewritten as ((thread_locals *)TlsGetValue(my_slot))->fringe.
// or ((thread_locals *)tls_load())->fringe. These long and messy-looking
// fragments might perhaps best be concealed via a header file containing
//    inline uintptr_t &TLfringe()
//    {    return ((thread_locals *)tls_load())->fringe;
//    }
// so that the main source code merely writes TLfringe() where it used to
// write just fringe. Furthemore by wrapping the access through a function
// like that it will be easy to conditionalize the code so that if C++11
// native thread_local is good enough it can be used:
//    inline uintptr_t &TLfringe()
//    {    return my_thread_locals->fringe;
//    }
//
//
// Timings as reported here are sensitive to minor issues such (perhaps) as
// the alignment that various code fragments end up relative to where
// cache lines fall. However the main message is that at least sometimes
// on my Windows 10 host and Cygwin64 I see
//     simple non-thread-local case     1
//     inline code working via GS       1.5
//     use of TlsGetValue()             3
//     use of C++11 thread_local       30 Cygwin, 15 Mingw

// You are in fact entitles to use several different slots if your whole
// project is split into several components - but you will then need to adapt
// the code here so that each component uses its own "my_slot".

#include <time.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>

// The task I will perform will be just incrementing an integer. By
// making it an integer in the middle of an array I illustrate that
// I could be handling lots of thread-local data not just a single
// word. This was set up as a simpler illustration that the use of
// a struct as in the explanation above!

thread_local int tl_vars[10];
int              simple_vars[10];

// The messy parts of thies file are only relevant on Cygwin and Mingw.

#if defined __CYGWIN__ || defined __MINGW32__
#define ON_WINDOWS 1
#if __SIZEOF_POINTER__ == 4
#define ON_WINDOWS_32 1
#endif
#endif


#if defined ON_WINDOWS

// This version uses direct access via the GS segment register, which is
// where 64-bit Windows saves a thread information block. The mode of access
// here is not following properly documented policies and so is basically
// unsafe. But I observe
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved.
// On a 64-bit machine the first 64 thread-local slots are at
// offset 0x1480. Then there are more available via TlsExpansionSlots
// at offset 0x1780. For 32-bit platforms those offsets are different:
// 0xe10 and 0xf94. Yuk!!!!!

#include <intrin.h>    // Provides code to read relative to FS or GS
#include <windows.h>

static unsigned int my_slot, my_slot_scaled;

#ifdef ON_WINDOWS_32

uint32_t extended_tls_load()
{   uint32_t a = __readfsdword(0xf94);
    return *(uint32_t *)(a - 0x100 + my_slot_scaled);
}

void extended_tls_store(uint32_t v)
{   uint32_t a = __readfsdword(0xf94);
    *(uint32_t *)(a - 0x100 + my_slot_scaled) = v;
}

uint32_t tls_load()
{   if (my_slot_scaled >= 0x100) return extended_tls_load();
    else return __readfsdword(my_slot_scaled+0xe10);
}

void tls_store(uint32_t v)
{   if (my_slot_scaled >= 0x100) return extended_tls_store(v);
    else __writefsdword(my_slot_scaled+0xe10, v);
}

#else

uint64_t extended_tls_load()
{   uint64_t a = __readgsqword(0x1780);
    return *(uint64_t *)(a - 0x200 + my_slot_scaled);
}

void extended_tls_store(uint64_t v)
{   uint64_t a = __readgsqword(0x1780);
    *(uint64_t *)(a - 0x200 + my_slot_scaled) = v;
}

uint64_t tls_load()
{   if (my_slot_scaled >= 0x200) return extended_tls_load();
    else return __readgsqword(my_slot_scaled+0x1480);
}

void tls_store(uint64_t v)
{   if (my_slot_scaled >= 0x200) return extended_tls_store(v);
    else __writegsqword(my_slot_scaled+0x1480, v);
}

#endif // Windows 32 vs 64 bit
#endif // ON_WINDOWS

// Now the four versions that I will compare. I force each to avoid getting
// inlines because gcc is so clever that if it can inline them it does not
// do anthting at all like the work I intend! Of course in a "real" use-case
// the individual functions using data that might want to be thread_local
// will be such that optimisation is not so easy, and inlining may be
// prevented by complicated code or separate compilation.

[[gnu::noinline]] void simple_inc()
{   simple_vars[5]++;
}

[[gnu::noinline]] void tl_inc()
{   tl_vars[5]++;
}

#ifdef ON_WINDOWS

[[gnu::noinline]] void windows_inc()
{   ((int *)TlsGetValue(my_slot))[5]++;
}

[[gnu::noinline]] void gs_inc()
{   ((int *)tls_load())[5]++;
}

#endif // ON_WINDOWS

// This function times a function by calling it 0x40000000 times. It
// sets the location to be incremented to zero first and displays the
// value it has at the end as a rather crude verification that something
// has happened.

void timeit(const char *name, void (*fn)(), int *var)
{   std::cout << "Address of my workspace is " << var << std::endl;
    clock_t c0 = clock();
    var[5] = 0;
    for (unsigned int i=0; i<0x40000000; i++) (*fn)();
    clock_t c1 = clock();
    std::cout << "incremented value = " << var[5] << "  ";
    std::cout << std::setw(25) << name << "  "
              << std::fixed << std::setprecision(2)
              << ((c1-c0)/(double)CLOCKS_PER_SEC)
              << std::flush << std::endl;
}

std::mutex mm;

// Here I run all the three test cases that I have. I use a lock_guard so
// that only one instance of this runs at any time, and in particular so
// that the output that is generated ends up tidy.

void runtests(const char *msg)
{   std::lock_guard<std::mutex> gg(mm);
    std::cout << "Running " << msg << std::endl;
    timeit("simple variable",     simple_inc, simple_vars);
#if defined ON_WINDOWS
// Each thread must set the slot that is relative to ITS version of the GS
// segment register to point at the data that it will use.
    TlsSetValue(my_slot, (void *)&tl_vars);
#ifdef ON_WINDOWS_32
    timeit("thread local via FS", gs_inc,     tl_vars);
#else
    timeit("thread local via GS", gs_inc,     tl_vars);
#endif
    TlsSetValue(my_slot, (void *)&tl_vars);
    timeit("Using Windows Tls API", windows_inc, tl_vars);
#endif // ON_WINDOWS
// The final test uses direct C++11 "thread_local" storage qualification.
// It is the "obvious" way to use thread local data.
    timeit("C++11 thread_local",  tl_inc,     tl_vars);
}

int main(int argc, char *argv[])
{
#if defined ON_WINDOWS
// Allocate a slot in the Windows threal-local vector.
// I deliberatly allocate (and waste) over 64 slots to start with so that
// the one I end up with will be an "extension slot", which will lead
// to the more expensive path through my access code.
    for (int i=0; i<70; i++)
        my_slot = TlsAlloc();
    std::cout << "My slot will be " << my_slot << std::endl;
    my_slot_scaled = my_slot*sizeof(void *);
#endif // ON_WINDOWS

// Run all tests in the main program...
    runtests("direct");
// ...then create a thread and run them in it.
    std::thread t1(runtests, "in a thread");
    t1.join();
    return 0;
}

// end of tltime.cpp

