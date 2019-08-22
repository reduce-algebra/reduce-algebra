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
//     thread_local ConsCeell *fringe;
//     ConsCell *allocate_cons_cell()
//     {   ConsCell *r = fringe++;
//         ..
//     where now each thread must be given a separate pool of memory
//     to allocate from. This has two main disadvantages compared with
//     scheme (1). The first is tha need to fragment memory into per-thread
//     allocation regions. The second is that in (1) once memory is
//     exhausted every thread naturally ends up entering the garbage
//     collector. With (2) finding a good scheme to synchronize all threads
//     involvex extra work.
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



#include <iostream>
#include <atomic>
#include <cinttypes>
#include <cstdint>
#include <ctime>

#ifdef __CYGWIN__
#define select xxxselect
#include <windows.h>
#endif


typedef intptr_t LispObject;

// Cygwin and mingw32 both seem to use "emutls" to support the C++11
// keyword "thread_local". This can have severe performance consequences
// in the sort of use I wish to make of it where rather small leaf functions
// access thread_local values.
//


#if defined __CYGWIN__ || defined __MINGW32__
#define ON_WINDOWS 1
extern void *tls_load();
extern void tls_store(void *v);
#if __SIZEOF_POINTER__ == 4
#define ON_WINDOWS_32 1
#endif
#endif // __CYGWIN__ || __MINGW32__

#ifdef ON_WINDOWS

#include <windows.h>

// Ideally I should go TlsFree(myTebSlot) at the end.

static int32_t myTebSlot = TlsAlloc();


#ifdef CAUTIOUS
// The CAUTIOUS option uses the Microsoft API to access thread-local slots,
// and so should be robust against potential changes in Windows.


inline void *tls_load()
{   return TlsGetValue(myTebSlot);
}

inline void tls_store(void *v)
{   TlsSetValue(myTebSlot, v);
}

#else // CAUTIOUS
// The version is intended and expected to behave exactly like the version
// that calls the Microsoft-provided functions, except (1) it does not
// do even basic sanity checks on the slot-number saved via myTebSlot
// and (b) it can expand into inline code that then runs faster that the
// official version even if it does just the same thing.

// I abstract away 32 vs 64-bit Windows issues here. The offsets used are from
// www.geoffchappell.com/studies/windows/win32/ntdll/structs/teb/index.htm
// which has repeated comments about the long term stability of the memory
// layout involved.

#ifdef ON_WINDOWS_32

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movl %%fs:(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(uint32_t n, void *v)
{   asm volatile
    (   "movl %0, %%fs:(%1)"
        :
        : "r" (v), "r" (n)
        :
    );
}

#define basic_TLS_offset           0xe10
#define extended_TLS_offset        0xf94

#else

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movq %%gs:(%1), %0"
        : "=r" (r)
        : "r" (n)
        :
    );
    return r;
}
inline void write_via_segment_register(uint32_t n, void *v)
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

inline void *extended_tls_load()
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    return a[myTebSlot - 64];
}

inline void extended_tls_store(void *v)
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    a[myTebSlot - 64] = v;
}

inline void *tls_load()
{   if (myTebSlot >= 64) return extended_tls_load();
    else return (void *)read_via_segment_register(
        basic_TLS_offset + sizeof(void *)*myTebSlot);
}

inline void tls_store(void *v)
{   if (myTebSlot >= 64) return extended_tls_store(v);
    else write_via_segment_register(
        basic_TLS_offset + sizeof(void *)*myTebSlot, v);
}

#endif // CAUTIOUS
#endif // ON_WINDOWS



std::atomic<uintptr_t> Afringe;
uintptr_t fringe;
thread_local uintptr_t Tfringe;

[[gnu::noinline]] LispObject simple_get_n_bytes(size_t n)
{   uintptr_t result = fringe; fringe += n;
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject relaxed_get_n_bytes(size_t n)
{   uintptr_t result = Afringe.fetch_add(n, std::memory_order_relaxed);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject default_get_n_bytes(size_t n)
{   uintptr_t result = Afringe.fetch_add(n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject threadlocal_get_n_bytes(size_t n)
{   uintptr_t result = Tfringe; Tfringe += n;
    return static_cast<LispObject>(result);
}

#ifdef ON_WINDOWS
[[gnu::noinline]] LispObject fakelocal_get_n_bytes(size_t n)
{   uintptr_t result = (uintptr_t)tls_load();
    tls_store((void *)(result+n));
    return static_cast<LispObject>(result);
}
#endif

const size_t HEAPSIZE = (512*1024*1024/sizeof(uintptr_t));

typedef LispObject (*testfn)(size_t);

void time1(const char *name, testfn fn)
{   uintptr_t *mem = new uintptr_t[HEAPSIZE];
    clock_t c0 = std::clock();
    for (int count=0; count<100; count++)
    {   Afringe.store(fringe = (uintptr_t)mem);
        for (size_t i=0; i<HEAPSIZE-2; i++) (*fn)(sizeof(uintptr_t));
    }
    clock_t c1 = std::clock();
    std::cout << name << " " << ((c1-c0)/CLOCKS_PER_SEC) << std::endl;
}

int main(int argc, char *argv[])
{
    time1("simple", simple_get_n_bytes);
    time1("relaxed", relaxed_get_n_bytes);
    time1("default", default_get_n_bytes);
#ifdef ON_WINDOWS
    time1("fakelocal", fakelocal_get_n_bytes);
#endif
    time1("threadlocal", threadlocal_get_n_bytes);
    return 0;
}

