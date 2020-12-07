//
// This is a tiny and unfair bit of code to check various options for
// implementing CONS for multi-threaded use.
//
// There are two (and a half) competing schemes:
//
// (1) Use std::atomic::fetch_add. The idea is roughly
//     std::atomic <ConsCell *>fringe;
//     ConsCell *allocate_cons_cell()
//     {   ConsCell *r = fringe++;
//         if (fringe >= limit) r = garbage_collect();
//         return r;
//     }
//     with the "fringe++" operation performed atomically, so that
//     even if several threads all call allocate_cons_cell() simultaneously
//     each will get a different address returned. The code above is not
//     intended to compile - it is intended to convey the concept, and in
//     particular the way an atomic increment operation is used.
//
// (2) Use
//     thread_local ConsCell *fringe;
//     ConsCell *allocate_cons_cell()
//     {   ConsCell *r = fringe++;
//         ..
//     where now each thread must be given a separate pool of memory
//     to allocate from. This has two main disadvantages compared with
//     scheme (1). The first is tha need to fragment memory into per-thread
//     allocation regions. The second is that in (1) once memory is
//     exhausted every thread naturally ends up entering the garbage
//     collector. With (2) finding a good scheme to synchronize all threads
//     involves extra work.
//
// The test here is because I found quite substantial performance issues.
// I have cut the code down to just the "fringe++" kernel. I have then tried
// on cygwin64/g++, cygwin64/x86_64-pc-mingw32-g++, linux64, a macbook and
// aarch64 (Raspberry pi 4). The main conclusion I see is that use of the
// std::atomic<T> increment increases the costs in this very focussed test
// but a factor of about 5 over the cost of a non-atomic increment. In
// some cases the level of memory order consistency matters a bit, but
// not spectacularly.
// Use the plain "thread_local" storage class for fringe costs a factor
// of pergaps 1.8 on the Macintush, has no effect on x86_64 or aarch64 Linux
// but hurts by a factor of 30 (!) on Cygwin64/g++.
// By using a fragment of assembly code and making not quite proper (but
// probably reliable) assumptions about Windows memory layout the thread_local
// overhead can be essentially removed, but at the cost of using separate
// code in that case.

// Here are some sample results, with explanation and commentary:
//
// Test on CYGWIN
// simple        100%   234 centiseconds
// atomic inc R  501%
// atomic inc    503%
// fakelocal     181%
// winlocal      180%
// MS fakelocal  472%
// MS winlocal   520%
// thread local  5317%
//
// That was with 64-bit Cygwin running on Windows 10. The "simple" case
// provides a baseline and uses unadorned C++ variables, so no thread_local
// and not atomic. It would not be suitable for use in a multi-threaded
// context. All other times are normalized to it, which is why it is shown
// at "100%". The timing after that is an absolute timing and makes it
// possible to get some idea about the relative speeds of the computers
// used in the test run.  The two "atomic inc" cases use a std::atomic
// fetch_add operation. One used "relaxed" memoy order, the other
// sequentially consistent. On all the platforms this shows that code that
// says fringe.fetch_add(n) is significantly slower than having just
// fringe+=n. On Windows platforms I collect 5 variants on use of thread-local
// storage for the fringe register. The line just labelled "thread local"
// uses "thread_local uintptr_t fringe;" in a straightforward way. Observe
// that on Cygwin/Mingw32 g++ makes that very slow. Inspecting the generated
// code reveals calls to "emutls". However Linux on x86_64 shows minimal
// overhead for this option, while the Mac and aarch64 show some noticable
// pain. I have fakelocal/winlocal and MS variants of those two. The MS
// versions use the official Microsoft access functions TlsGetValue and
// TlsSetValue. The others replace those calls with my own verions that can
// be expanded inline. "fakelocal" just uses the special code for thread
// local storage for fringe and limit and so while it could allocate within
// its own nursery heap it does not have provision for synchronizations
// with other threads. "winlocal" expands on that by reading the limit value
// with an ACQUIRE atomic operation so that other threads could change it and
// the allocating one would then notice.
//
// Test on MINGW
// simple        100%   281 centiseconds
// atomic inc R  416%
// atomic inc    416%
// fakelocal     150%
// winlocal      150%
// MS fakelocal  399%
// MS winlocal   433%
// thread local  1952%
//
// x86_64-w64-mingw32-g++ on Windows 10 shows timings that are interestingly
// different in detail but that probably lead to the same conclusions.
//
// Test on LINUX64
// simple        100%   374 centiseconds
// atomic inc R  328%
// atomic inc    328%
// thread local  99%
//
// 64-bit Ubuntu was run on a different computer so it is not at all
// amazing that the actual run time for the simple test is different. Having
// a CPU that is slower in absolute terms may explain the slightly lower
// overhead associated with the atomic increments. The thread_local time
// shows good performance!
//
// Test on MAC
// simple        100%   366 centiseconds
// atomic inc R  438%
// atomic inc    434%
// thread local  283%
//
// A 2014 Macbook still shows that the atomic increment is painfully
// expensive.
//
// Test on RPI64
// simple        100%   982 centiseconds
// atomic inc R  615%
// atomic inc    531%
// thread local  315%
// thread localR 121%
// A Raspberry Pi 4 running 64-bit Manjaro Linux shows absolute times
// for the test that are amazingly good. Nota that the time reported as
// "thread local" uses an atomic load to access the limit value (with
// an ACQUIRE memory ordering specified". Thhis is compiled using an
// LDAR instruction where otherwise an LDR might have been. This is what
// is mostly responsible for the slowdown, because using memory_order_relaxed
// (which is not consistent with using limit for inter-thread communication)
// drops the cost substantially.



#include <iostream>
#include <atomic>
#include <cinttypes>
#include <cstdint>
#include <ctime>

#ifdef __CYGWIN__
// <windows.h> tends to clash with various cygwin headers, so I
// rename "select" to avoid one of the ones that caused most grief. It
// it just as well I do not want to use that function here!
#define select xxxselect
#include <windows.h>
#endif


typedef std::intptr_t LispObject;

extern void tls_store(std::int32_t, void *);

class GeneralTLVars
{
public:
    std::int32_t TLvar1;
    double TLvar2;
    void *TLvar3;
    std::atomic<std::uintptr_t> limit;
    void setGeneralSlot(std::int32_t generalSlot)
    {   tls_store(generalSlot, reinterpret_cast<void *>(this));
    }
};

// Cygwin and mingw32 both seem to use "emutls" to support the C++11
// keyword "thread_local". This can have severe performance consequences
// in the sort of use I wish to make of it where rather small leaf functions
// access thread_local values.
//

// I will provide three (at present!) bits of thread_local stuff:
//
//   load_fringe() and store_fringe(uintptr_t)
//   load_limit() and store_limit(uintptr_t)
//   TLvar1(), TLvar2, TLval3() as representatives of all the rest!



#if defined __CYGWIN__ || defined __MINGW32__
#define ON_WINDOWS 1
#if __SIZEOF_POINTER__ == 4
#define ON_WINDOWS_32 1
#endif
#endif // __CYGWIN__ || __MINGW32__

#ifdef ON_WINDOWS

#include <windows.h>

class TEBSlots
{
public:
    std::int32_t fringeSlot;
    std::int32_t limitSlot;
    std::int32_t generalSlot;

    TEBSlots()
    {   fringeSlot = TlsAlloc();
        limitSlot = TlsAlloc();
        generalSlot = TlsAlloc();
    }

    ~TEBSlots()
    {   TlsFree(fringeSlot);
        TlsFree(limitSlot);
        TlsFree(generalSlot);
    }
};


inline TEBSlots myTEBSlots;

// I abstract away 32 vs 64-bit Windows issues here. The offsets used are from
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved.
// By coding these accessors for myself rather than using the official
// Microsoft entrypoints I arrange that the code can be expanded in-line. I
// also omit checks that the index value used is proper.

// I have to have separate read and write functions because it is hard to
// return the address of a location that is addressed with a segment
// override. I had wanted to use "leal %%fx:(%1), %0" but the CPU does not
// support that.

#ifdef ON_WINDOWS_32

inline void *read_via_segment_register(std::uint32_t n)
{   void *r;
    asm volatile
    (   "movl %%fs:(%1), %0"
        : "=r" (r)
        : "ri" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(std::uint32_t n, void *v)
{   asm volatile
    (   "movl %0, %%fs:(%1)"
        :
        : "ri" (v), "r" (n)
        :
    );
}

#define basic_TLS_offset           0xe10
#define extended_TLS_offset        0xf94

#else

inline void *read_via_segment_register(std::uint32_t n)
{   void *r;
    asm volatile
    (   "movq %%gs:(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(std::uint32_t n, void *v)
{   asm volatile
    (   "movq %0, %%gs:(%1)"
        :
        : "r" (v), "r" (n)
        :
    );
}

#define basic_TLS_offset           0x1480
#define extended_TLS_offset        0x1780

#endif // Windows 32 vs 64 bit

inline void *extended_tls_load(std::int32_t slot)
{   void **a = (void **)read_via_segment_register(
                   extended_TLS_offset);
    return a[slot - 64];
}

inline void extended_tls_store(std::int32_t slot, void *v)
{   void **a = (void **)read_via_segment_register(
                   extended_TLS_offset);
    a[slot - 64] = v;
}

inline void *tls_load(std::int32_t slot)
{   if (slot >= 64) return extended_tls_load(slot);
    else return reinterpret_cast<void *>(read_via_segment_register(
                basic_TLS_offset + sizeof(void *)*slot));
}

inline void tls_store(std::int32_t slot, void *v)
{   if (slot >= 64) return extended_tls_store(slot, v);
    else write_via_segment_register(
            basic_TLS_offset + sizeof(void *)*slot, v);
}

inline std::uintptr_t load_fringe()
{   return reinterpret_cast<std::uintptr_t>(tls_load(
            myTEBSlots.fringeSlot));
}

inline void store_fringe(std::uintptr_t v)
{   tls_store(myTEBSlots.fringeSlot, reinterpret_cast<void *>(v));
}

inline std::uintptr_t load_limit()
{   return reinterpret_cast<std::uintptr_t>(tls_load(
            myTEBSlots.limitSlot));
}

inline void store_limit(std::uintptr_t v)
{   tls_store(myTEBSlots.limitSlot, reinterpret_cast<void *>(v));
}

inline GeneralTLVars *load_general()
{   return (GeneralTLVars *)tls_load(myTEBSlots.generalSlot);
}

inline void store_general(GeneralTLVars *v)
{   tls_store(myTEBSlots.generalSlot, reinterpret_cast<void *>(v));
}

inline std::uintptr_t MS_load_fringe()
{   return reinterpret_cast<std::uintptr_t>(TlsGetValue(
            myTEBSlots.fringeSlot));
}

inline void MS_store_fringe(std::uintptr_t v)
{   TlsSetValue(myTEBSlots.fringeSlot, reinterpret_cast<void *>(v));
}

inline std::uintptr_t MS_load_limit()
{   return reinterpret_cast<std::uintptr_t>(TlsGetValue(
            myTEBSlots.limitSlot));
}

inline void MS_store_limit(std::uintptr_t v)
{   TlsSetValue(myTEBSlots.limitSlot, reinterpret_cast<void *>(v));
}

inline GeneralTLVars *MS_load_general()
{   return (GeneralTLVars *)TlsGetValue(myTEBSlots.generalSlot);
}

inline void MS_store_general(GeneralTLVars *v)
{   TlsSetValue(myTEBSlots.generalSlot, reinterpret_cast<void *>(v));
}

class SetUpGeneralVars
{
public:
    GeneralTLVars generalVars;
    SetUpGeneralVars()
    {   generalVars.setGeneralSlot(myTEBSlots.generalSlot);
        store_general(&generalVars);
    }
};

// The object here exists so that on a thread-local basis versions of the
// GeneralTLVars class get construced and stored in the right place. The
// actual object created here is not accessed of itself - just the
// GeneralTLVars object that it contains is.

/*inline thread_local*/ SetUpGeneralVars setUpGeneralVars;

#else // ON_WINDOWS

inline void store_fringe(std::uintptr_t w)
{
}

inline void store_limit(std::uintptr_t w)
{
}

inline void tls_store(std::int32_t slot, void *v)
{
}

thread_local GeneralTLVars generalTLVars;

inline GeneralTLVars *load_general()
{   return &generalTLVars;
}

inline GeneralTLVars *MS_load_general()
{   return &generalTLVars;
}

#endif // ON_WINDOWS

inline std::atomic<std::uintptr_t> &TLlimit()
{   return load_general()->limit;
}

inline std::atomic<std::uintptr_t> &MS_TLlimit()
{   return MS_load_general()->limit;
}

std::atomic<std::uintptr_t> Afringe;
std::uintptr_t fringe;
thread_local std::uintptr_t Tfringe;

std::atomic<std::uintptr_t> Alimit;
volatile std::uintptr_t
limit;     // so that compiler does not optimize
// out accesses.
thread_local std::atomic<std::uintptr_t> Tlimit;

[[gnu::noinline]] LispObject garbage_collect(std::uintptr_t fringe,
        std::size_t n)
{   std::cout << "GC invoked" << std::endl;
    return 0;
}


// This "simple" version is to provide a baseline measurement of what
// one might achieve if threads were not an issue.

// I make the test for the need for garbage collection "==" rather than
// ">" or "<" because all I want there is a test that will cause the
// limit register to be checked but that will then always fail.

[[gnu::noinline]] LispObject simple_get_n_bytes(std::size_t n)
{   std::uintptr_t result = (fringe -= n);
    if (fringe == limit) result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

// Now a version based on having a single heap region and using an
// atomic fetch_add. On Intel/AMD the specification of memory_order_relaxed
// will not make a difference, but on systems with other memory models it
// might. I believe that Alpha was the most dramatic case. PPC also had
// extra need for memory barriers, and ARMV7 has some. I have not yet
// understood the impact on ARMV8.

[[gnu::noinline]] LispObject relaxed_get_n_bytes(std::size_t n)
{   std::uintptr_t result = Afringe.fetch_sub(n,
                            std::memory_order_relaxed);
    if (result-n == Alimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result-n);
}

// As above but expressing the increment using "-=" and letting the
// default memory order discipline apply. This allocates downwards in
// memory rather than upwards. This where using "==" as my test for
// the end of the heap region is a help.

[[gnu::noinline]] LispObject default_get_n_bytes(std::size_t n)
{   std::uintptr_t result = (Afringe -= n);
    if (result == Alimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

// Now I will suppose that there are separate "nursery" areas for each
// thread and simple thread-local variables Tfringe and Tlimit apply
// in each. Tlimit needs to be atomic so that other threads can force
// a GC here by setting it.

#ifdef ON_WINDOWS

[[gnu::noinline]] LispObject fakelocal_get_n_bytes(std::size_t n)
{   std::uintptr_t result = load_fringe() - n;
    store_fringe(result);
    if (result == load_limit())
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject winlocal_get_n_bytes(std::size_t n)
{   std::uintptr_t result = load_fringe() - n;
    store_fringe(result);
    if (result == TLlimit().load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject MS_fakelocal_get_n_bytes(std::size_t n)
{   std::uintptr_t result = MS_load_fringe() - n;
    MS_store_fringe(result);
    if (result == MS_load_limit())
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject MS_winlocal_get_n_bytes(std::size_t n)
{   std::uintptr_t result = MS_load_fringe() - n;
    MS_store_fringe(result);
    if (result == MS_TLlimit().load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

#endif // ON_WINDOWS

[[gnu::noinline]] LispObject threadlocal_get_n_bytes(std::size_t n)
{   std::uintptr_t result = (Tfringe -= n);
    if (Tfringe == Tlimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject relaxed_threadlocal_get_n_bytes(
    std::size_t n)
{   std::uintptr_t result = (Tfringe -= n);
    if (Tfringe == Tlimit.load(std::memory_order_relaxed))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

const std::size_t HEAPSIZE = (512*1024*1024/sizeof(std::uintptr_t));

typedef LispObject (*testfn)(std::size_t);

bool first = true;
std::int64_t basetime = 0;

void time1(const char *name, testfn fn)
{   std::uintptr_t *mem = new std::uintptr_t[HEAPSIZE];
    std::clock_t c0 = std::clock();
    for (int count=0; count<30; count++)
    {   Afringe.store(fringe = reinterpret_cast<std::uintptr_t>(mem));
        store_fringe(reinterpret_cast<std::uintptr_t>(mem));
        Tfringe = reinterpret_cast<std::uintptr_t>(mem);
        Alimit.store(limit = reinterpret_cast<std::uintptr_t>(-1));
        store_limit(reinterpret_cast<std::uintptr_t>(-1));
        Tlimit = reinterpret_cast<std::uintptr_t>(-1);
        TLlimit() = reinterpret_cast<std::uintptr_t>(-1);
        for (std::size_t i=0; i<HEAPSIZE-2;
             i++) (*fn)(sizeof(std::uintptr_t));
    }
    std::clock_t c1 = std::clock();
    if (first) basetime = static_cast<std::int64_t>(c1 - c0);
    std::int64_t ms = static_cast<std::int64_t>(100.0*
                      (c1-c0)/static_cast<double>(basetime));
    std::cout << name << " " << ms << "%";
    if (first) std::cout << "   "
                             << static_cast<std::int64_t>(100.0*(c1-c0)/static_cast<double>
                                     (CLOCKS_PER_SEC))
                             << " centiseconds";
    std::cout << std::endl;
    first = false;
}

int main(int argc, char *argv[])
{   if (argc>1) std::cout << "Test on " << argv[1] << std::endl;
    first = true;
    basetime = 0;
    time1("simple       ", simple_get_n_bytes);
    time1("atomic inc R ", relaxed_get_n_bytes);
    time1("atomic inc   ", default_get_n_bytes);
#ifdef ON_WINDOWS
    time1("fakelocal    ", fakelocal_get_n_bytes);
    time1("winlocal     ", winlocal_get_n_bytes);
    time1("MS fakelocal ", MS_fakelocal_get_n_bytes);
    time1("MS winlocal  ", MS_winlocal_get_n_bytes);
#endif
    time1("thread local ", threadlocal_get_n_bytes);
    time1("thread localR", relaxed_threadlocal_get_n_bytes);
    return 0;
}

// end of constime.cpp
