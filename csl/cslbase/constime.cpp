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

extern void tls_store(int32_t, void *);

class GeneralTLVars
{
public:
    int32_t TLvar1;
    double TLvar2;
    void *TLvar3;
    std::atomic<uintptr_t> limit;
    void setGeneralSlot(int32_t generalSlot)
    {   tls_store(generalSlot, (void *)this);
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
    int32_t fringeSlot;
    int32_t limitSlot;
    int32_t generalSlot;

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

inline void *extended_tls_load(int32_t slot)
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    return a[slot - 64];
}

inline void extended_tls_store(int32_t slot, void *v)
{   void **a = (void **)read_via_segment_register(extended_TLS_offset);
    a[slot - 64] = v;
}

inline void *tls_load(int32_t slot)
{   if (slot >= 64) return extended_tls_load(slot);
    else return (void *)read_via_segment_register(
        basic_TLS_offset + sizeof(void *)*slot);
}

inline void tls_store(int32_t slot, void *v)
{   if (slot >= 64) return extended_tls_store(slot, v);
    else write_via_segment_register(
        basic_TLS_offset + sizeof(void *)*slot, v);
}

inline uintptr_t load_fringe()
{   return (uintptr_t)tls_load(myTEBSlots.fringeSlot);
}

inline void store_fringe(uintptr_t v)
{   tls_store(myTEBSlots.fringeSlot, (void *)v);
}

inline uintptr_t load_limit()
{   return (uintptr_t)tls_load(myTEBSlots.limitSlot);
}

inline void store_limit(uintptr_t v)
{   tls_store(myTEBSlots.limitSlot, (void *)v);
}

inline GeneralTLVars *load_general()
{   return (GeneralTLVars *)tls_load(myTEBSlots.generalSlot);
}

inline void store_general(GeneralTLVars *v)
{   tls_store(myTEBSlots.generalSlot, (void *)v);
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

#else

inline void tls_store(int32_t slot, void *v)
{
}

thread_local std::atomic<uintptr_t> Tlimit;
thread_local GeneralTLVars generalVars;

inline uintptr_t load_fringe()
{   return fringe;
}

inline void store_fringe(uintptr_t v)
{   fringe = v;
}

inline uintptr_t load_limit()
{   return limit;
}

inline void store_limit(uintptr_t v)
{   limit = v;
}

inline GeneralTLVars *load_general()
{   return &generalVars;
}

#endif // ON_WINDOWS

inline int32_t &TLvar1()
{   return load_general()->TLvar1;
}

inline double &TLvar2()
{   return load_general()->TLvar2;
}

inline void * &TLvar3()
{   return load_general()->TLvar3;
}

inline std::atomic<uintptr_t> &TLlimit()
{   return load_general()->limit;
} 

std::atomic<uintptr_t> Afringe;
uintptr_t fringe;
thread_local uintptr_t Tfringe;

std::atomic<uintptr_t> Alimit;
uintptr_t limit;
thread_local std::atomic<uintptr_t> Tlimit;

[[gnu::noinline]] LispObject garbage_collect(uintptr_t fringe, size_t n)
{   std::cout << "GC invoked" << std::endl;
    return 0;
}


// This "simple" version is to provide a baseline measurement of what
// one might achieve if threads were not an issue.

[[gnu::noinline]] LispObject simple_get_n_bytes(size_t n)
{   uintptr_t result = (fringe -= n);
    if (fringe < limit) result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

// Now a version based on having a single heap region and using an
// atomic fetch_add.

[[gnu::noinline]] LispObject relaxed_get_n_bytes(size_t n)
{   uintptr_t result = Afringe.fetch_sub(n, std::memory_order_relaxed);
    if (result-n < Alimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result-n);
}

// As above but expressing the increment using "-=" and letting the
// default memory order discipline apply. This allocates downwards in
// memory rather than upwards.

[[gnu::noinline]] LispObject default_get_n_bytes(size_t n)
{   uintptr_t result = (Afringe -= n);
// The next line really needs "<=" not "<".
    if (result < Alimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

// Now I will suppose that there are separate "nursery" areas for each
// thread and simple thread-local variables Tfringe and Tlimit apply
// in each. Tlimit needs to be atomic so that other threads can force
// a GC here by setting it.

[[gnu::noinline]] LispObject fakelocal_get_n_bytes(size_t n)
{   uintptr_t result = load_fringe() - n;
    store_fringe(result);
    if (result < load_limit())
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject winlocal_get_n_bytes(size_t n)
{   uintptr_t result = load_fringe() - n;
    store_fringe(result);
    if (result < TLlimit().load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

[[gnu::noinline]] LispObject threadlocal_get_n_bytes(size_t n)
{   uintptr_t result = (Tfringe -= n);
    if (Tfringe < Tlimit.load(std::memory_order_acquire))
        result = garbage_collect(result, n);
    return static_cast<LispObject>(result);
}

const size_t HEAPSIZE = (512*1024*1024/sizeof(uintptr_t));

typedef LispObject (*testfn)(size_t);

bool first = true;
int64_t basetime = 0;

void time1(const char *name, testfn fn)
{   uintptr_t *mem = new uintptr_t[HEAPSIZE];
    clock_t c0 = std::clock();
    for (int count=0; count<30; count++)
    {   Afringe.store(fringe = (uintptr_t)mem);
        store_fringe((uintptr_t)mem);
        Tfringe = (uintptr_t)mem;
        Alimit.store(limit = (uintptr_t)(-1));
        store_limit((uintptr_t)(-1));
        Tlimit = (uintptr_t)(-1);
        TLlimit() = (uintptr_t)(-1);
        for (size_t i=0; i<HEAPSIZE-2; i++) (*fn)(sizeof(uintptr_t));
    }
    clock_t c1 = std::clock();
    if (first) basetime = (int64_t)(c1 - c0);
    int64_t ms = (int64_t)(100.0*(c1-c0)/(double)basetime);
    std::cout << name << " " << ms << "%";
    if (first) std::cout << "   "
                         << (int64_t)(100.0*(c1-c0)/(double)CLOCKS_PER_SEC)
                         << " centiseconds";
    std::cout << std::endl;
    first = false;
}

int main(int argc, char *argv[])
{   if (argc>1) std::cout << "Test on " << argv[1] << std::endl;
    first = true;
    basetime = 0;
    time1("simple     ", simple_get_n_bytes);
    time1("relaxed    ", relaxed_get_n_bytes);
    time1("default    ", default_get_n_bytes);
    time1("fakelocal  ", fakelocal_get_n_bytes);
    time1("winlocal   ", winlocal_get_n_bytes);
    time1("threadlocal", threadlocal_get_n_bytes);
    return 0;
}

