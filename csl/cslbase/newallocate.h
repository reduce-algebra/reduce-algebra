// newallocate.h                          Copyright (C) Codemist, 1990-2019


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

#ifndef header_newallocate_h
#define header_newallocate_h 1

#include <csetjmp>

// allocSegment grabs a chunk of memory of the given size, which must
// be a multiple of CSL_PAGE_SIZE. The memory block is recorded in a table
// that can hold up to 32 segments.

extern void set_up_signal_handlers();
extern void *allocateSegment(size_t);

// Here is a layout for an 8 Mbyte page, specifying the various
// ways in which data can be accessed. This uses a union so that the page
// header will overlap the beginning of the objstart[] bitmap, but because
// objects only reside in the data[] part the first couple of kilobytes
// of objstart[] will never be used.
// In my first sketch here I have not put in all the data I expect to need
// to put into the header - eg I will need more to let me allocate around
// pinned items.

static const size_t pageSize = 8*1024*1024; // Use 8 Mbyte pages
static const size_t bytesForMap = pageSize/64;
static const size_t qwordsForMap = bytesForMap/8;
static const size_t spareBytes = 2*bytesForMap;

// I am going to require Pages to be aligned at nice neat boundaries
// because then if I have an arbitrary address within one I will be able to
// find the page header using a simple AND operation.

union alignas(pageSize) Page
{   struct PageHeader
    {
// Pages can be chained through this field, so e.g. there will be a
// chain of all the pages that are not currently full but that (may)
// have pinned live data within them.
        union Page *chain;
// When a page is the Nursery or the I keep fringe and heaplimit pointers
// showing how the next allocation must happen. There will be further
// variables related to mapping pinned items within the page where it
// is necessary to allocate around them. When a page ceases being the
// Nursery it may still have some free space at its end (for instance
// when it overflowed due to an attempt to allocate a vector). So the
// fringe and heaplimit values are saved in it so that if an ambiguous
// pointer refers into the page but indicates an address beyond the fringe
// it can be ignored.
        uintptr_t fringe;
// To follow on from the above, when a page has been evacuated by the
// garbage collector fresh values of fringe and heaplimit can be set into it.
// When the page is selected as a new Nursery these values can be transferred
// into the global locations.
// Neither of these fields is used other than during garbage collection and
// so neither needs a std::atomic<> wrapping.
        uintptr_t heaplimit;
// I use a software write-barrier that sets bytes in the dirty[] array
// when something is referenced. There are then times when I need to
// process every dirty region. Well I hope that many pages will not have any
// dirty segments, and in that case processing the entire page reduces to
// checking this simple flag. Otherwise I need to scan the entire dirty[]
// array.
        std::atomic<bool> dirtypage;
// During garbage collection I need a map showing where each object on a
// page starts. This boolean is set when that map is set up and available
// for use. Because the map shares space with the "dirty[]" map it will
// be invalidated whenever the mutator runs, and so the information will
// have to be regenerated at the start of each garbage collection.
        bool onstarts_present;
        double endOfHeader;
    } pageHeader;
// Here I need to explain the bit and byte-maps I use and when I use them,
// and in particular how uses could conflict.
// To cope with the generational nature of the GC I have a software
// write barrier such that every use of RPLACx or PUTV sets a byte in
// the addressed page. This byte specifies a small block of words within which
// the update occured. The RPLACx etc operations are always precise - ie they
// will update a valid live Lisp object, and so I do not need to validate
// the address concerned. But this means that any time the mutator is active
// entried in the dirty[] map can get set. I use a map made out of
// std::atomic<uint8_t> rather than a bitmap to keep the overhead in the
// write barrier as low as I can while also keeping it thread-safe.
//
// At the start of a minor GC I will need to identify all pinned items in the
// scavengable region. I only need to do that for the scavengable page because
// only items inside that could be subject to evacuation. For this I can
// have two maps, one of which lets me identify the starts of all objects
// in the scavengable page and making use of that a second that marks the
// pinned items there. Each of these need to be bitmaps that cover the page
// to a resolution of 8 bytes. Since they are only used by the garbage
// collector they do not need to be atomic or thread-local or any such.
// Ambiguous pointers arise on the (C++) stack but also in segments of
// heap that may be in the stable region or within pages that are mostly
// free but contain some data that was pinned during a previous garbage
// collection, when these regions either contained pointers to nursery or
// pending at the end of a previous minor collection or have been updates
// by RPLACx etc. since then. During a minor GC I will need dirty bits on
// just stable and mostly-free pages, and object-start and pinned bits on
// just the scavengable page, so I can overlap the maps.
// For a major garbage collection the concept of "dirty" does not arise,
// because I will be inspecting every live object everywhere. However I
// will need to end up setting up pinned bits within all regions where
// currently live data exists. While setting up those pinned bits I will need
// object-start information.
    struct PageBody
    {   union PageBitmaps
        {
// Whenever I process an ambiguous pointer I need to identify the
// start address of the object (if any!) that it refers to an address
// within. Notionally I do that by performing a linear scan of the data
// region in the Page. However I can speed things up very usefully by
// first setting up a bitmap that records where each object in the page
// starts and then scanning that bitmap 64-bits at a time. Given 8 Mbyte
// pages there are 1 million potential object start locations (because
// everything gets aligned at 8-byte boundaries). That translates into
// 16K quadwords in the bitmap, and I can skip zero words rapidly and
// easily and then use "find-first-bit" operations when I get close to
// where I need to be.
            std::atomic<uint8_t> dirty[2*bytesForMap];
            uint64_t qwordsDirty[2*qwordsForMap];
            struct Maps
            {   uint64_t objstart[qwordsForMap];
                uint64_t pinned[qwordsForMap];
            } maps;
        } pageBitmaps;
        LispObject data[(pageSize - spareBytes)/sizeof(LispObject)];
    } pageBody;
};

// First I will give code that implements the write-barrier. It is passed
// the address of a valid Lisp location - that can be one of &car(x),
// &cdr(x) or &elt(v, n). It records the fact that an update has
// been made to memory in that region by setting a byte in dirty[]. Because
// the address it is given will always be a VALID address of some location
// in the Lisp heap it can easily find the relevant page...

inline void write_barrier(LispObject *p)
{   uintptr_t a = reinterpret_cast<uintptr_t>(p);
 // round down to 8M boundary
    Page *x = reinterpret_cast<Page *>(a & -UINT64_C(0x800000));
// I mark the page as a whole as containing some regions that are dirty...
    x->pageHeader.dirtypage.store(true);
// and then use the offset within the page to mark a 32-byte region as
// dirty. The map used here is std::atomic<uint8_t>
    uintptr_t offset = a & 0x7fffffU;
    x->pageBody.pageBitmaps.dirty[offset/32].store(1);
}

inline void write_barrier(std::atomic<LispObject> *p)
{   write_barrier((LispObject *)p);
}

// I will have variables fringe and heaplimit that are thread_local.
// On Cygwin and Mingw32 I use the Microsoft low-level API directly
// because the version provided via C++ has severe overheads (at the time
// or writing this - August 2019). The classes ForFringe and ForLimit
// are there so that while in the rest of the source code use of variables
// fringe and heaplimit looks natural, at run-time access to them both
// gets diverted so as to use the platform-specific scheme for thread-local
// and so that heaplimit is a std::atomic<T> item.


#if defined WIN32 || defined __CYGWIN__

// If I go "#include <windows.h>" (well the bit I actually need seems to be
// processthreadsapi.h) that tends to define all sorts of things that can
// clash with my own code. So here I put in explicit declarations for the
// thread-local support functions I use, trying rather hard to match just
// what Windows will use.

extern "C"
{
extern __declspec(dllimport) uint32_t TlsAlloc();
};

// For now I will use inline variables, which become available with
// C++17. This will not be good for general use since even slightly
// "not the latest" versions of C++ compilers do not support it. In
// particular Ubuntu LTS 16.04 (expiry date April 2021) comes with a
// version of gcc too old for that. However it may be that I am not ready
// to deploy this until June 2021, in which case all will be well!!!!

const inline uint63_t threadid_slot = TlsAlloc();
const inline uint32_t fringe_slot = TlsAlloc();
const inline uint32_t heaplimit_slot = TlsAlloc();
inline thread_local std::atomic<uintptr_t> real_heaplimit;

#ifdef CAUTIOUS

// This version uses the official Windows API for accessing thread-local
// values.

extern "C"
{
extern __declspec(dllimport) void *TlsGetValue(uint32_t);
extern __declspec(dllimport) int TlsSetValue(uint32_t, void *);
};

inline void *tls_load(uint32_t n)
{   return TlsGetValue(n);
}

inline void tls_store(uint32_t n, void *v)
{   TlsSetValue(n, v);
}

#else // CAUTIOUS

// This version uses inline functions including a tiny amount of assembly
// code and should match the behaviour of the Microsoft version. It goes
// beyond anything that Windows guaranteed, but is believed tto be using
// information that so many others rely on that it is not liable to
// change.

#if __SIZEOF_POINTER == 4

// On 32-bit Windows the FS segment register provides access to the TEB,
// while on a 64-bit system it would be GS with some different offsets.

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movl %%fs:(%1), %0"
        : "=r" (r)
        : "ri" (n)
        :
    );
    return r;
}

inline void write_via_segment_register(uint32_t n, void *v)
{   asm volatile
    (   "movl %0, %%fs:(%1)"
        :
        : "ri" (v), "r" (n)
        :
    );
}

const uint32_t basic_TLS_offset    = 0xe10;
const uint32_t extended_TLS_offset = 0xf94;

#else // 32 vs 64-bit

inline void *read_via_segment_register(uint32_t n)
{   void *r;
    asm volatile
    (   "movq %%gs:(%1), %0"
        : "=r" (r)
        : "mri" (n)
        :
    );
    return r;
}

inline void write_via_segment_register(uint32_t n, void *v)
{   asm volatile
    (   "movq %0, %%gs:(%1)"
        :
        : "mri" (v), "r" (n)
        :
    );
}

const uint32_t basic_TLS_offset    = 0x1480;
const uint32_t extended_TLS_offset = 0x1780;

#endif // 32 vs 64-bit

inline void *tls_load(int32_t slot)
{   if (slot >= 64)
    {   void **a = (void **)read_via_segment_register(extended_TLS_offset);
        return a[slot - 64];
    }
    else return (void *)read_via_segment_register(
        basic_TLS_offset + sizeof(void *)*slot);
}

inline void tls_store(int32_t slot, void *v)
{   if (slot >= 64)
    {   void **a = (void **)read_via_segment_register(extended_TLS_offset);
        a[slot - 64] = v;
    }
    else write_via_segment_register(
        basic_TLS_offset + sizeof(void *)*slot, v);
}

#endif // CAUTIOUS

class ForThreadId
{
public:
    operator unsigned int()
    {   return (unsigned int)tls_Load(threadId_slot);
    };
    ForFringe& operator= (const unsigned int a)
    {    tls_store(threadId_slot, (void *)(uintptr_t)a);
         return *this;
    };
};

class ForFringe
{
public:
    operator uintptr_t()
    {   return (uintptr_t)tls_Load(fringe_slot);
    };
    ForFringe& operator= (const uintptr_t a)
    {    tls_store(fringe_slot, (void *)a);
         return *this;
    };
    ForFringe& operator+= (const size_t a)
    {    uintptr_t v = (uintptr_t)tls_Load(fringe_slot) + a;
         tls_store(fringe_slot, (void *)v);
         return *this;
    };
};

class ForHeapLimit
{
public:
    operator uintptr_t()
    {   return *(std::atomic<uintptr_t> *)tls_Load(heaplimit_slot);
    };
    ForHeapLimit& operator= (const uintptr_t a)
    {    *(std::atomic<uintptr_t> *)tls_Load(heaplimit_slot) = a;
         return *this;
    };
    ForHeapLimit& operator+= (const uintptr_t a)
    {    ((std::atomic<uintptr_t> *)tls_Load(heaplimit_slot))->fetch_add(a);
         return *this;
    };
    ForHeapLimit()
    {   tls_store(heaplimit_slot, (void *)&real_heaplimit);
    };
};

inline ForThreadId threadId;
inline ForFringe fringe;
inline ForHeapLimit heaplimit;

#else

inline thread_local uintptr_t fringe;
inline thread_local uintptr_t heaplimit;

#endif

extern Page *nurseryPage;       // where allocation is happening
extern Page *pendingPage;
extern Page *scavengablePage;
extern Page *stablePages;
extern Page *mostlyFreePages;
extern Page *freePages;
extern size_t freePagesCount;
extern size_t activePagesCount;


// For up to 32 segments I have...
//   heapSegmentCount   number of allocated segments
//   heapSegment[i]      base address of a segment of memory
//   heapSegmentSize[i] size of useful part of that segment, in bytes
//   heapSegmentTotalSize[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

extern void *heapSegment[32];
extern void *heapSegmentBase[32];
extern size_t heapSegmentSize[32];
extern size_t heapSegmentCount;

void initHeapSegments(double n);

// find_heapSegment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it, or -1 if the
// bit-pattern could not be interpreted as a pointer to within the
// memory I have allocated.

// Given a value I want to see if it could be a pointer into one of the
// allocated segments. Because there are only 32 of them and if I keep my
// table of segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

inline int find_segment2(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int find_segment4(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+2]))
        return find_segment2(p, n);
    else return find_segment2(p, n+2);
}

inline int find_segment8(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+4]))
        return find_segment4(p, n);
    else return find_segment4(p, n+4);
}

inline int find_segment16(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+8]))
        return find_segment8(p, n);
    else return find_segment8(p, n+8);
}

inline int find_segment32(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+16]))
        return find_segment8(p, n);
    else return find_segment16(p, n+16);
}

inline int find_heapSegment(uintptr_t p)
{   int n = find_segment32(p, 0);
    if (p < reinterpret_cast<uintptr_t>(heapSegment[n]) ||
        p >= reinterpret_cast<uintptr_t>(heapSegment[n]) +
             heapSegmentSize[n]) return -1;
    return n;
}

// This finds a page that a potential pointer p is within, or returns NULL
// if there is not one

inline Page *findPage(uintptr_t p)
{   int n = find_heapSegment(p);
    if (n < 0) return NULL;
    return reinterpret_cast<Page *>(p & -pageSize);
}

// I can do cheaper tests if I only concerned with one of the special pages.

inline bool inNurseryPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(nurseryPage);
    return (p >= n &&
            p < (n + pageSize));
}

inline bool inPendingPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(pendingPage);
    return (p >= n &&
            p < (n + pageSize));
}

inline bool inScavengablePage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(scavengablePage);
    return (p >= n &&
            p < (n + pageSize));
}

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. This must NEVER be called
// with a zero argument. Also note that this function is also defined
// in arithlib.hpp, but since it is "inline" there is not need to worry
// about clashing multiple definitions.

// Count the leading zeros in a 64-bit word.

inline int nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU) {n = n +32; x = x <<32;}
    if (x <= 0x0000FFFFFFFFFFFFU) {n = n +16; x = x <<16;}
    if (x <= 0x00FFFFFFFFFFFFFFU) {n = n + 8; x = x << 8;}
    if (x <= 0x0FFFFFFFFFFFFFFFU) {n = n + 4; x = x << 4;}
    if (x <= 0x3FFFFFFFFFFFFFFFU) {n = n + 2; x = x << 2;}
    if (x <= 0x7FFFFFFFFFFFFFFFU) {n = n + 1;}
    return n;
}

#endif // __GNUC__
#define NLZ_DEFINED 1

extern std::mutex gc_mutex;
extern uintptr_t gc_and_allocate(uintptr_t r, size_t n);

// I am going to explain what I do regarding synchronization for garbage
// collection several times in different places, writing and re-writing
// until I feel I have things straight!
//
// Each thread will have a separate region within which it allocates. It
// will have thread-local variables fringe and heaplimit. To allocate
// a block of N bytes it records the existing value of fringe and then
// increments fringe by N. If that yields a value >= heaplimit then there
// is not enough space at present, and garbage collection is called for.
// The garbage collection call will only return when it has been able to
// allocate the required memory, and it will (at least in general) reset
// both fringe and heaplimit.
//
// When garbage collection is needed all threads have to be halted. To
// arrange this any thread that concludes it needs GC will set the heaplimit
// information for ALL threads to zero. Well to be a little more careful,
// if it finds that its own heaplimit is zero it knows that that has already
// been done, however given that several threads can be in this situation
// at once I think the sane choices are either (a) put the zero-ing out
// loop in a critical region or (b) accept that each thread will have its
// heaplimit set to zero multiple times. Probably the former is going to
// be cheaper and probably neither will have cost big enough to matter in the
// context of garbage collection.
// Since it is expected that every (active) Lisp thread will perform CONS
// operations rather frequently every thread is expected to participate
// soon. Obviously allocating strings, vectors or big-numbers will also get
// fringe compared against heaplimit. Explicit checks to serve as polling
// operations can be placed on backward jumps and other places of plausible
// interest. Special handling will be needed for system calls that might
// block: threads obeying thos emust not be counted as "active".
//
// To make it possible to zero out every heaplimit there will be a reference
// to each thread's heaplimit in an array indexed by thread-number.
//
// An atomic variable records the number of active threads. As a thread
// enters garbage collection it decrements this using an atomic fetch_sub().
// Eventually one thread (which might not be the one that initially called
// for GC) will set the count to zero. It will act as a master GC thread and
// all the other threads will need to idle while it works.
//
// When a thread discovers that it is the master it knows that all the other
// threads have done everything that gets done before the decrement operation.
// It can thefore use all the information that threads have deposited and
// do the main work of garbage collection. The information it can thus have
// can be
//    stack base and top for every thread.
//    base and size of the block currently being allocated and that
//      ran beyond the thread's heaplimit.
//    when a heaplimit is set to zero its old non-zero value can be recorded
//      through use of a test-and-set style atomic access (or if the loop
//      that sets the heaplimits to zero is within a critical region).
// The master thread will be able to update heaplimit directly. It can leave
// values that the other threads can copy into their own fringe and result
// locations.
// When a master thread has completed its work it can set a variable
// gc_complete and notify all the others.
//
// A non-master thread will wait for gc_complete. When that is seen it can
// increment active_threads. One thread will increment so as to reach the
// maximum value of that count - it can then set gc_complete to false and
// notify everybody.
// All threads, master or not, end by waiting for !gc_complete. That should
// leave every thread ready to continue work and puts things such that the
// next time garbage collection is called for everything is set up as
// required.
// 

// This is the core part of CONS and also of the code that allocates
// bignums, strings and vectors.

inline LispObject get_n_bytes(size_t n)
{   n = doubleword_align_up(n);
    uintptr_t r = fringe;
    fringe += n;
// fringe is thread-local. heaplimit is both thread-local and atomic, and
// so if other threads alter heaplimit that fact will be noticed here. In
// particular if another thread sets heaplimit to zero then the
// gc_and_allocate() recovery code will be triggered on the next
// allocation attempt.
    if (fringe >= (uintptr_t)heaplimit)
        r = gc_and_allocate(r, n, fringe, heaplimit);
    return static_cast<LispObject>(r);
}

// It will be important to poll frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupted.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

inline void poll()
{   if (fringe >= (uintptr_t)heaplimit)
        (void)gc_and_allocate(0, 0, fringe, heaplimit);
}

// Here we will have:
//    fringe a pointer to where one would next try to allocate;
//    limit an address such that only memory below it may be allocated;
//    r the start of a block that allocation had attempted at;
//    n the size of the block being allocated;
//    fringe >= heaplimit.
// Several threads can be allocating at about the same time, so one will
// be the first to use fetch_add() in a way that makes fringe >= heaplimit.
// But then others can follow on and increment fringe further, but all but
// the first such will deliver r >= heaplimit, and unless recovery action
// resets fringe and/or heaplimit for them to soon all will call gc_and_allocate().
// Well this is an issue, because if gc_and_allocate running in some thread
// can reset things such that fringe < heaplimit before a different thread tests
// for that we can have a memory overflow event undetected.
// As a special case this may be called with r = n = 0 as a way for a
// thread not actually needing memory at the moment to synchronize.


extern std::atomic<uint32_t> threadCount;
extern std::mutex mutex_for_gc;
extern std::atomic<bool> gc_started;
extern std::condition_variable cv_for_gc_started;
extern std::condition_variable cv_for_gc_busy;
extern std::atomic<bool> gc_complete;
extern std::condition_variable cv_for_gc_complete;


inline LispObject cons(LispObject a, LispObject b)
{   LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    setcar(r, a);
    setcdr(r, b);
    return r;
}

// With the conservative collector I maybe do not need to avoid garbage
// collection on any particular individual uses of cons().

inline LispObject cons_no_gc(LispObject a, LispObject b)
{   return cons(a, b);
}

inline LispObject cons_gc_test(LispObject p)
{   return p;
}

inline LispObject ncons(LispObject a)
{   LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    setcar(r,  a);
    setcdr(r,  nil);
    return r;
}

// Here I can wonder if there is a good way to save overhead by allocating
// both cells as one operation...

inline LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, nil);
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r1 + 4*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, d);
    return r1;
}

inline LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(8*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r1 + 4*sizeof(LispObject);
    LispObject r4 = r1 + 6*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcar(r4, d);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, r4);
    setcdr(r4, nil);
    return r1;
}

inline LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    setcar(r1, r2);
    setcar(r2, a);
    setcdr(r1, c);
    setcdr(r2, b);
    return r1;
}

inline LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   return acons(a, b, c);
}

inline LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r1 + 4*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r1 + 4*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, b);
    return onevalue(r1);
}

inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    setcar(r1, b);
    setcdr(r1, a);
    return onevalue(r1);
}

inline LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

inline LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, nil);
    return onevalue(r1);
}

// The following can be used as in
//   with_clean_stack([&]{ ... });
// where the "..." represents some actions. Its job is to arrange that
// the C stack has all local values on (in particular that nothing is
// referenced solely via machine registers) and that a stack_top variable
// is set so that the garbage collector can do its job properly.

static const int maxThreads = 64;
extern std::atomic<uintptr_t> stack_bases[maxThreads];
extern std::atomic<uintptr_t> stack_fringes[maxThreads];
extern std::atomic<uintptr_t> heap_fringe[maxThreads];
extern std::atomic<uintptr_t> *heap_heaplimit_addr[maxThreads];
extern std::atomic<uintptr_t> heap_heaplimit[maxThreads];
extern std::atomic<uintptr_t> request_values[maxThreads];
extern std::atomic<size_t> request_sizes[maxThreads];


// The following code makes a whole slew of assumptions about how the
// compiler and system library will treat it! I will explain what I hope
// will happen, but a sufficiently clever compiler could without doubt
// defeat me.

// A C++ system is liable to have some "callee save" registers and keep the
// values of some variable in them. A conservative garbage collector needs
// to access their values. I EXPECT that setjmp will dump copies of all
// such registers (at least!) into the jmp_buff, thus ensuring that a copy of
// all the data is present on the stack. Well here the jmp_buff is not
// referenced again or elsewhere, so maybe a compiler could consider it
// unused and just remove the call to setjmp. To discourage that I have
// buffer_pointer referring to the jmp_buff, and then at least potentially
// (as far as the compiler can tell) in some other compilation uint there
// might be code reachable from action() that does a longjmp() via it.
// I alse want the jmp_buff to have been allocate on the stack at a lower
// address than any other values currently in use. The "noinline" qualifier
// as provided by gcc is intended to help to enforce that by arranging that
// with_clean_stack() has its own stack frame with almost nothing except
// action() and the jmp_buff in it. If values used within action() end up
// on the stack above buffer that should not be a problem.
//
// There can be at most maxThreads threads in play, and each must have
// the thread-local value threadId set.

extern jmp_buf *buffer_pointer;

// Usage:
//   may_block([&]{
//      ... ... ... });
// This is to be used if the contents "..." etc do not do any Lisp memory
// allocation but might block. Ie there could be use of a synchronization
// primitive involving a muxex or a comdition variable, or there may be
// a read-request from some source that might not be instently ready (such
// as the keyboard or a network connection or pipe). The reason this is needed
// is that other threads may need to garbage collect, and that involves
// getting every thread into synchronization - one that is blocked will not
// be able to participate actively in that! Yes another plausible user-case
// is the code performing a "sleep" operation.kx 

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline auto may_block(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
// ASSUME that setjmp dumps all the machine registers into the jmp_buf.
    static_cast<void>(setjmp(buffer));
    stack_fringes[threadId].store(reinterpret_cast<void *>(buffer));
// Hmm - what do I do here.
    return action();
};

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline auto with_clean_stack(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
    static_cast<void>(setjmp(buffer));
    stack_fringes[threadId].store(reinterpret_cast<void *>(buffer));
    return action();
};

// Low level functions for allocating objects.

extern void set_up_empty_page(Page *p);
extern void set_variables_from_page(Page *p);
extern void save_variables_to_page(Page *p);

// Entry to a garbage collector.

extern void garbageCollect();

void allocate_segment(size_t n);

#endif // header_newallocate_h

// end of newallocate.h



#if 0


Here I will start to code my stop-the-world stuff:

===========

int activeThreads = THREAD_COUNT, idleThreads = 0;
bool gc_started = false;
bool gc_ended = true;
cv start_cv, finished_cv, all_idle;
mutex gc_entry;

===========

//if (--activeThreads == 0) master_for_gc()
//else idle_during_gc();

===========

idle_during_gc()
{   start_cv.wait([]{ return gc_started; });
    if (++activeThreads == THREAD_COUNT) all_idle.notify_one();
    finished_cv.wait([]{ return gc_finished; });
}

===========

master_for_gc()
{   gc_finished = false;
    gc_started = true;
    start_cv.notify_all();
    //DO STUFF;
    all_idle.wait(activeThreads == THREAD_COUNT);
    gc_started = false;
    gc_finished = true;
    finished_cv.notify_all();
}

===========

potentially_blocking()
{   //THREAD_COUNT--;
    if (--active_threads == 0) master_for_gc();
    //DO WHATEVER MIGHT BLOCK;
    //THREAD_COUNT++;
    ++active_thread_count;
}

===========

#endif


