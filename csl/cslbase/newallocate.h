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
// When a page is the Nursery or the I keep fringe and limit pointers
// showing how the next allocation must happen. There will be further
// variables related to mapping pinned items within the page where it
// is necessary to allocate around them. When a page ceases being the
// Nursery it may still have some free space at its end (for instance
// when it overflowed due to an attempt to allocate a vector). So the
// fringe and limit values are saved in it so that if an ambiguous
// pointer refers into the page but indicates an address beyond the fringe
// it can be ignored.
        uintptr_t fringe;
// To follow on from the above, when a page has been evacuated by the
// garbage collector fresh values of fringe and limit can be set into it.
// When the page is selected as a new Nursery these values can be transferred
// into the global locations.
// Neither of these fields is used other than during garbage collection and
// so neither needs a std::atomic<> wrapping.
        uintptr_t limit;
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
// the address of a valid Lisp location - that can be one of &qcar(x),
// &qcdr(x) or &elt(v, n). It records the fact that an update has
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

// I make the fringe and limit pointers uintptr_t types because that
// way I can be certain how arithmetic baheves. I will need to cast to
// pointer types when I want to read or write the memory that they address.
// Obviously!

extern std::atomic<uintptr_t> Afringe;
extern std::atomic<uintptr_t> Alimit;

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

extern std::mutex gc_mutex;
extern uintptr_t gc_and_allocate(uintptr_t r, size_t n);

inline LispObject get_n_bytes(size_t n)
{   size_t n1 = doubleword_align_up(n);
// The next two lines will need lengthy discussion if only so I understand
// what I need to do after them.
    uintptr_t limit = Alimit.load();
    uintptr_t result = Afringe.fetch_add(n1);
// The above updated Afringe in an atomic manner, so that if multiple
// threads perform this operation concurrently each will get a result
// corresponding to a distinct chunk of memory. The worry at this stage
// is that Afringe and Alimit might be changed by some other thread after
// Alimit was loaded. Well if the other thread takes its simple path
// all will be well, because all that can happen is that the other thread
// increments Afringe so the space that gets allocated here is at a higher
// address. The messy situation would be if the other thread called
// gc_and_allocate() and that led to Afringe being set to be within a
// different page that happened to be at an address lower than the current
// one. Then the value of result would be based on that that new fringe
// but an old limit...
// However all is not totally lost! If ANY thread sets fringe>=limit then
// until fringe and thread are reset all other threads will come to the
// "need to GC" state, and none will complete a successful allocation.
// However all threads can reset fringe, incrementing it by almost arbitrarily
// large amounts before before the threads synchronize! 
    if (result+n1 >= limit)
        result = gc_and_allocate(result, n);
    return static_cast<LispObject>(result);
}

// It will be important to poll frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupted.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

inline void poll()
{   if (Afringe.load() >= Alimit.load()) (void)gc_and_allocate(0, 0);
}

// Here we will have:
//    fringe a pointer to where one would next try to allocate;
//    limit an address such that only memory below it may be allocated;
//    r the start of a block that allocation had attempted at;
//    n the size of the block being allocated;
//    fringe >= limit.
// Several threads can be allocating at about the same time, so one will
// be the first to use fetch_add() in a way that makes fringe >= limit.
// But then others can follow on and increment fringe further, but all but
// the first such will deliver r >= limit, and unless recovery action
// resets fringe and/or limit for them to soon all will call gc_and_allocate().
// Well this is an issue, because if gc_and_allocate running in some thread
// can reset things such that fringe < limit before a different thread tests
// for that we can have a memory overflow event undetected.
// As a special case this may be called with r = n = 0 as a way for a
// thread not actually needing memory at the moment to synchronize.

// Now a HORRID feature of the scheme I have here is that I need to keep
// track of how many threads exist and how many are currently running. A
// thread will contribute to the count in "activeThreads" if its is in a
// state where it will poll or allocate memory soon.

extern std::atomic<int> activeThreads;
extern std::atomic<bool> gc_complete;
extern std::mutex mutex_for_gc;
extern std::condition_variable cv_for_gc;


inline LispObject cons(LispObject a, LispObject b)
{   LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r) = a;
    qcdr(r) = b;
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
    qcar(r) = a;
    qcdr(r) = nil;
    return r;
}

// Here I can wonder if there is a good way to save overhead by allocating
// both cells as one operation...

inline LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = nil;
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = d;
    return r1;
}

inline LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(8*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    LispObject r4 = r3 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcar(r4) = d;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = r4;
    qcdr(r4) = nil;
    return r1;
}

inline LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = r2;
    qcar(r2) = a;
    qcdr(r1) = c;
    qcdr(r2) = b;
    return r1;
}

inline LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   return acons(a, b, c);
}

inline LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcdr(r1) = b;
    return onevalue(r1);
}

inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = b;
    qcdr(r1) = a;
    return onevalue(r1);
}

inline LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

inline LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcdr(r1) = nil;
    return onevalue(r1);
}

// The following can be used as in
//   with_clean_stack([&]{ ... });
// where the "..." represents some actions. Its job is to arrange that
// the C stack has all local values on (in particular that nothing is
// referenced solely via machine registers) and that a stack_top variable
// is set so that the garbage collector can do its job properly.

static const int max_threads = 16;
extern thread_local int thread_id;
extern void *stack_bases[max_threads];
extern void *stack_fringes[max_threads];

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
// There can be at most max_threads threads in play, and each must have
// the thread-local value thread_id set.

extern jmp_buf *buffer_pointer;

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline void with_clean_stack(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = buffer;
    static_cast<void>(setjmp(buffer));
    stack_fringes[thread_id] = reinterpret_cast<void *>(buffer);
    action();
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
