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
extern LispObject initial_heap_setup(LispObject *stacksegment);

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
// entries in the dirty[] map can get set. I use a map made out of
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


class ThreadStartup
{
public:
    ThreadStartup();
    ~ThreadStartup();
};

extern Page *currentPage;       // where allocation is happening
extern Page *previousPage;
extern Page *busyPages;
extern Page *mostlyFreePages;
extern Page *freePages;

extern size_t busyPagesCount;
extern size_t mostlyFreePagesCount;
extern size_t freePagesCount;


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

inline bool inCurrentPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(currentPage);
    return (p >= n &&
            p < (n + pageSize));
}

inline bool inPreviousPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(previousPage);
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

static const unsigned int maxThreads = 64;

extern std::mutex gc_mutex;
static ThreadLocal<uintptr_t> threadId;
static ThreadLocal<uintptr_t> fringe;
extern std::atomic<uintptr_t> limit[maxThreads];
extern uintptr_t              limitBis[maxThreads];
extern uintptr_t              fringeBis[maxThreads];
extern size_t                 request[maxThreads];
extern LispObject             result[maxThreads];
extern size_t                 gIncrement[maxThreads];
extern std::atomic<uintptr_t> gFringe;
extern uintptr_t              gLimit;
extern uintptr_t              gNext;

// With the scheme I have here when an 8 Mbyte page gets full all of it
// will be scheduled for evacuation (ie garbage collection). In the extreme
// case that I had 64 active threads but only one was performing allocation
// that would leave 63 chunks within the page essentially empty - that is
// about 1 Mbyte. Is (1/8) of the page is not used. That is not a disaster!
// In the more plausible case of say 8 threads the overhead decreases to a
// level where I really stop worrying.
// Well if needbe I could try being clever and allocating each thread chunks
// whose size was sensitive to their history of allocation, so that
// threads that were almost always dormant or which hardly did any allocation
// got much smaller chunks. At the very very least to do anything like that
// now would be premature!

// When I need to trigger or participate in a garbage collection I
// call difficult_n_bytes() with an argument that is the amount of memory I
// am wanting to allocate. That is allowed to be zero (for instance when
// I am just polling). It will return a pointer to an allocated block, and
// set fringe, limit etc to reflect the allocation performed. Within it
// it may have to try several times: the fundamental version guarantees to
// achieve allocation for at least one of the threads (and that thread will
// continue and only join in with subsequent collections later on).
// Note that limit[] can be forced to zero as a call to difficult_allocate
// is exiting.

//
// These are the circumstances and preconditions for when difficult_n_bytes
// gets called:
// Possibility 1: The system needs to allocate n bytes (and the case n=0 is
//   permitted here) but the thread_local variable limit has been set to
//   zero (by somebody else). When difficult_n_bytes() is called everything
//   apart from limit should be unaltered, (specifically fringe will be
//   as it was at the start and will NOT have changed) but
//    . The word at fringe has been set to be a dummy header using up all
//      the space as far as limitBis[threadId].
//    . fringe has been copied into fringeBis{threadId].
//    . request[threadId] has been set to the request size n.
//    . gIncrement[threadId] is set to zero.
// Possibility 2: gFringe has just been incremented and now lies beyond
//   gLimit. Because gFringe is incremented atomically once any thread
//   moves it beyond gLimit any other thread that attempts to use it will
//   find that it has also overrun its range.
//   Variables will be set as for Possibility 1 save that gIncrement[threadId]
//   is set to the amount by which gFringe had been incremented.
// In the above values are places in arrays indexed by threadId so that the
// single thread that happens to end up doing the work of garbage collection
// can both observe what requests each of the other threads had been making
// and can update their versions of fringe and limit.
//
// A challenge leading to some of the behaviour explained above is that with
// a conservative generational collector one expects each (minor) garbage
// collection to allocate a new page, but that may be fragmented with pinned
// data (from where there have been ambiguous pointers). This together with
// the possibility that multiple threads might simultaneously all ask for
// large blocks of memory means that there can be no guarantee that a
// single minor collection will make it possible to satisfy all the concurrent
// requests. Howver it does make sense to insist that any new block allocated
// for use as a nursery has sufficient clear space to satisfy at least one
// request. So in pathological cases (whihc I expect to be vanishingly
// uncommon) at the end of a GC it will not be possible to satisfy all current
// requests. In such a case at least one will be dealt with, but a further
// garbage collection activity will be run to find space for the rest.

extern uintptr_t difficult_n_bytes();

inline Header makePaddingHeader(size_t n)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_PADDER;
}

inline Header makeVectorHeader(size_t n)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_VEC32;
}

// I will want to treat the first word of every object as atomic, so this
// takes an address and casts it suitably.

inline std::atomic<uintptr_t>& firstWord(uintptr_t a)
{   return ((std::atomic<uintptr_t> *)a)[0];
}

// This is the core part of CONS and also of the code that allocates
// bignums, strings and vectors.

static const size_t CHUNK=16384;

inline LispObject get_n_bytes(size_t n)
{   n = doubleword_align_up(n);
// I have a thread-local variable fringe and limit[threadId] is in effect
// thread-local. These delimit a region of size CHUNK within which allocation
// can be especially cheap. limit[threadId] is atomic and that indicates that
// other threads may access it. In particular another thread can set it to
// zero to cause this thread to synchronize with others to participate in
// garbage collection.
    uintptr_t r = fringe;
    uintptr_t w = limit[threadId].load();
    fringe += n;
// The simple case completes here. If CHUNK is around 16K then only 1 cons
// in 1000 will take the longer route.
    if (fringe <= w) return static_cast<LispObject>(r);
// There are two possibilities here. One is that the new block I need to
// allocate really will not fit in the current chunk, and the other is that
// some other thread had set limit[] to zero to force this one to join in
// with garbage collection. In the latter case I may in fact be able to make
// this allocation simply by grabbing a fresh chunk.
    if (w != 0)
    {   size_t gap = w - r;
        if (gap != 0) firstWord(r).store(makePaddingHeader(gap));
// I now need to allocate a new chunk. gFringe and gLimit delimit a region
// within of size PAGE (perhaps 8 Mbytes) and I will start by allocating
// chunks sequentially within that page. By making gFringe atomic I can so
// this in a lock-free manner.
// I will make my next chunk big enough for the current allocation request
// with CHUNK left over after that. This ensures that even big vector
// requests can be satisfied.
        r = gFringe.fetch_add(CHUNK+n);
// Be aware that other threads might be doing (atomic) increments on gFringe
// at the same time that this one does. They will each reserve separate
// new chunks, but some of these may fall in memory well above gLimit.
// I am going to assume (ha ha) that even if the maximum number of threads
// each increment gFringe by the largest possible amount the it will not
// suffer arithmetic overflow.
        uintptr_t oldFringe = fringe - n;
        fringe = r + n;
        uint64_t newLimit = fringe + CHUNK;
// Possibly the allocation of the new chunk ran beyond the current page
// and that will be cause to consider triggering garbage collection. If the
// chunk size is 16K and the page size 8M it will take 512 chunk allocations
// before a page is filled. If for now I suppose that having 16 threads all
// allocating cons cells furiously is an extreme case then that will mean
// that each thread gets through 32 chunks before the extra (probably severe)
// costs of page allocation arise. 
        if (newLimit <= gLimit)
        {
// now my allocation of a new chunk has been successful. I wish to write
// back limit[threadId] but it is possible that in the meanwhile somebody
// set that to zero, so I need to be a bit careful. Specifically I will
// only write back the new limit if the old one was still in force.
//
// Here I have (successfully) allocated a new chunk, and I have set my
// fringe to point within it. Because limit[threadId] can be arbitrarily
// clobbered by others I will only update it if it has not changed since
// I loaded it earlier. If it has changed it will have been set to zero
// and I must participate in a GC.
            limitBis[threadId] = newLimit;
            bool ok = limit[threadId].compare_exchange_strong(w, newLimit);
            if (ok) return static_cast<LispObject>(r);
        }
        gIncrement[threadId] = CHUNK+n;
        fringe = oldFringe;
    }
    else
    {
// Here I am about to be forced to participate in garbage collection,
// typically for the benefit of some other thread.
        size_t gap = limitBis[threadId] - r;
        if (gap != 0) firstWord(r).store(makePaddingHeader(gap));
        gIncrement[threadId] = 0;
        fringe = r;
    }
    fringeBis[threadId] = fringe;
    request[threadId] = n;
// Here I can not complete the work with this inline function because
// either I have run out of space for a new chunk or because some
// other thread had done that and had set my limit register to zero
// to tell me. I set fringe back to the value that it had on entry, so the
// situation when I call difficult_n_bytes() is just as if it had been
// called directly from the main program save that gFringe may have been
// incremented - possibly beyond gLimit.
    return static_cast<LispObject>(difficult_n_bytes());
}

// It will be important to poll frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupted.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

inline void poll()
{   uintptr_t w;
    if (fringe > (w = limit[threadId].load()))
    {
// Here I need to set everything up just as if I had been making an
// allocation request for zero bytes.
        size_t gap = w - fringe;
        if (gap != 0) firstWord(fringe).store(makePaddingHeader(gap));
        fringeBis[threadId] = fringe;
        request[threadId] = 0;
        gIncrement[threadId] = 0;
        (void)difficult_n_bytes();
    }
}

// The following can be used as in
//   withRecordedStack([&]{ ... });
// where the "..." represents some actions. Its job is to arrange that
// the C stack has all local values on (in particular that nothing is
// referenced solely via machine registers) and that a stack_top variable
// is set so that the garbage collector can do its job properly.


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
// withRecordedStack() has its own stack frame with almost nothing except
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

extern std::atomic<uintptr_t> stack_bases[maxThreads];
extern std::atomic<uintptr_t> stack_fringes[maxThreads];

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline void may_block(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
// ASSUME that setjmp dumps all the machine registers into the jmp_buf.
    if (setjmp(buffer) == 0)
    {   stack_fringes[threadId] = reinterpret_cast<uintptr_t>(buffer);
// I will need to do more here to decrement the count of threads that
// the system knows to be potentially involved in memory allocation.
        action();
// ... and fix it up again here, possibly with a RAII style object.
// This use of longjmp is intended to help guarantee that the buffer
// and its contents are kept intact across the call to action().
        longjmp(buffer, 1);
    }
};

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline void withRecordedStack(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
    if (setjmp(buffer) == 0)
    {   stack_fringes[threadId] = reinterpret_cast<uintptr_t>(buffer);
        action();
        longjmp(buffer, 1);
    }
};



extern std::atomic<uint32_t> threadCount;
extern std::mutex mutex_for_gc;
extern bool gc_started;
extern std::condition_variable cv_for_gc_idling;
extern std::condition_variable cv_for_gc_busy;
extern bool gc_complete;
extern std::condition_variable cv_for_gc_complete;

// I am going to put the code that synchronizes threads for garbage
// collection here as an inline function mainly so that the code is
// present close to the procedures that call it - they have to cooperate
// in a way that feels delicate enough that having them in separate files
// would increase the risk of confusion.

extern std::atomic<uint32_t> activeThreads;
//  0x00 : total_threads : lisp_threads : still_busy_threads


inline void performGarbageCollection()
{   std::printf("Hello, this is the master_GC\n");
// set space in via request_sizes[] etc. Note that especially if I am
// dealing with fragmented heap-space because of pinned items left over by
// the conservative collector I may actually end up doing two or even more
// garbage collections here before I can satisfy all the pending memory
// requests. On a second or subsequent GC I must allow for the newly-
// allocated blocks that are here.
    fflush(stdout);
    my_abort(); // give up for now
}

// I have multiple threads, and when a GC is needed they need to synchronize.
// My plan is that one thread is selected as the key one, with that
// being the last one to decrement an "activeThreads" counter. By virtue
// of being last there the thread knows that all the other threads are
// quiescent. All the others first wait on a condition variable until the
// key one releases it, and then wait on a second condition variable until
// that too is released.
// The two variables are to let the underpinning variables get set up.
// So outside GC-time a variable "gc_started" will be false, and all
// non-key threads can go
//      {   std::unique_lock<std::mutex> lock(mutex_for_gc);
//          gc_start_cv.wait(lock, []{ return gc_started; });
//      }
// followed immediately  by
//      activeThreads++;
//      {   std::unique_lock<std::mutex> lock(mutex_for_gc);
//          gc_end_cv.wait(lock, []{ return gc_finished; });
//      }
// The key thread on the other hand can go
//      gc_finished = false;
// MUST ensure that gc_finished will be seen as false by all other threads
// before gc_started is seen as true, because otherwise spurious wake-ups
// on gc_start_cv and gc_end_cv could let one of the other threads run
// through improperly.
//      {   std::lock_guard<std::mutex> lock(mutex_for_gc);
//          gc_started = true;
//      }
//      gc_start_cv.notify_all();
// At this point the key thread can perform garbage collection. It can not
// tell if the other threads are still waiting to respond to the gc_start
// notification or if they have gone on to wait for gc_finished! So to let
// it know the subsidiary threads each increment activeThreads when they
// have passed the first hurdle, and the one that brings that up to maximum
// can notify yet another condition variable. At the end of GC the key thread
// can wait on that CV until the thread count is high enough, and then it
// can afford to clear gc_started and set gc_finished and finally notify
// all other threads. Ught this feels heavy-handed and messy!

inline void garbageCollectOnBehalfOfAll()
{
// When I get here I know that actveThreads==0 and that all other threads
// have just decremented that variable and are ready to wait on gc_started.
// Before I release them from that I will ensure that gc_finished is false so
// that they do not get over-enthusiastic!
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        gc_complete = false;
        gc_started = true;
    }
    cv_for_gc_idling.notify_all();
// Now while the other threads are idle I can perform some garbage
// collection and fill in results via result[] based on request[].
// I will also put gFringe back to the value it had before any thread
// had done anthing with it.
    size_t inc = 0;
    for (unsigned int i=0; i<maxThreads; i++)
    {   result[i] = nil;
        inc += gIncrement[i];
        gIncrement[i] = 0;
    }
// Note that I write this as "gFringe = gFringe - inc;" rather than as
// "gFringe -= inc;" because there is a risk that the latter might compile
// into an atomic decrement - and that is not needed here and may be a lot
// more expensive than the load and store of the alternative.
    gFringe = gFringe - inc;
// I now have a loop because in the facte of fragmentation and many
// simultaneous large requests just one pass of the generational GC might
// not clear out enough space. That should only be a problem that arises
// in somewhat pathalogical cases, but I need to allow for it!
    for (;;)
    {   performGarbageCollection();
// After garbage collection I will perform as many of the allocations as I
// can. The vector result[] must be treated as list-bases and so the values
// I store in it are kep neatly tagged.
// Here some threads may have been left with fringeBis[i] and limitBis[i]
// such that space can be allocated in that gap. I can use that space
// for any purposes at all, not only for the thread it officially belongs to.
// Some may have been left with those values equal, so that when that
// particular thread next needs to allocate it will need to go via gFringe.
        unsigned int tryFrom = 0;
        bool success = true;
        for (unsigned int i=0; i<maxThreads; i++)
        {   size_t n;
            if ((n = request[i]) != 0)
            {   if (tryFrom < maxThreads)
                {   size_t gap = limitBis[tryFrom] - fringeBis[tryFrom];
                    if (n <= gap) // can allocate here
                    {   result[i] = fringeBis[tryFrom] + TAG_VECTOR;
// If I have filled in result[i] I can set request[i] to zero so that any
// subsequent pass does not try to do this allocation again. But note that
// result[i] must be treated as a list-base.
                        request[i] = 0;
                        firstWord(fringeBis[tryFrom]).store(
                            makeVectorHeader(n));
                        fringeBis[tryFrom] += n;
                        gap -= n;
                        if (gap != 0)
                            firstWord(fringeBis[tryFrom]).store(
                                makePaddingHeader(gap));
                        continue;
                    }
// If the request was small but failed that means that the chunk I had been
// using is full up, and if another is available I will move on and try it.
// Note that all this requires the fringeBis[] and limitBis[] values to
// have been set up for all potential threads, not just for the ones that
// actually exist!
                    if (n <= 2*sizeof(uintptr_t))
                    {   tryFrom++;
                        i--;
                        continue;
                    }
                }
// Here either I had a large request or I had run out of chunks to try
// to fill up, so I need to use space at gFringe.
                if (n <= gLimit - gFringe)
                {   result[i] = gFringe + TAG_VECTOR;
                    request[i] = 0;
                    firstWord(gFringe).store(makeVectorHeader(n));
                    gFringe = gFringe + n;
                    continue;
                }
// A yet worse case - the request did not fit in the space up to gLimit.
// However this may be purely because of pinned items getting in the way
// so I will skip the next pinned item (supposing there is one) and re-try.
                size_t gap = gLimit - gFringe;
                if (gap != 0) firstWord(gFringe).store(makePaddingHeader(gap));
                if (gNext == 0)
                {   success = false;
                    break;
                }
                gFringe = gNext;
                gLimit = ((uintptr_t *)gFringe.load())[0];
                gNext = ((uintptr_t *)gFringe.load())[1];
                i--;
                continue;
            }
        }
        if (success) break;
    }
// Now I need to be confident that the other threads have all accessed
// gc_started. When they have they will increment activeThreads and when the
// last one does that it will notify me.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
// Note that if my entire system had only one thread then the condition
// tested here would always be true and the computation would not pause at
// all.
        cv_for_gc_busy.wait(lock,
            []{   uint32_t n = activeThreads.load();
                  return (n & 0xff) == ((n>>8) & 0xff) - 1;
              });
    }
// OK, so now I know that all the other threads are ready to wait on
// gc_finished, so I ensure that useful variables are set ready for next
// time and release all the threads that have been idling.
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        gc_started = false;
        activeThreads.fetch_add(0x0000001);
        gc_complete = true;
    }
    cv_for_gc_complete.notify_all();
}

inline void waitWhileAnotherThreadGarbageCollects()
{
// If I am a thread that will not myself perform garbage collection I need
// to wait for the one that does. This needs to be done in two phases. During
// the first I know that I have decremented activeThreads and determined that
// I was not the last, but I can not be certain that all other threads have
// done that. I wait until gc_started gets set, and that happens when some
// thread has found itself to be the last one. And so by construction that
// means that all other threads will have reached here.
//
// I need every idle thread to be woken up here. So when the master GC thread
// starts  it can set gc_started and notify everybody through the condition
// variable. It can not know how long each will take to notice that so it
// must not clear gc_started until it has had positive confirmation that
// all the idle threads have responded.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc_idling.wait(lock, []{ return gc_started; });
    }
// To record that threads have paused they can then increment activeThreads
// again. When one of them increments it to the value threadcount-1 I will
// know that all the idle threads have got here, and I nofify the master GC
// thread.
    bool inform = false;
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        uint32_t n = activeThreads.fetch_add(0x000001);
        if ((n & 0xff) == ((n>>8) & 0xff) - 2) inform = true;
    }
    if (inform) cv_for_gc_busy.notify_one();
// Once the master thread has been notified as above it can go forward and
// in due course notify gc_complete. Before it does that it must ensure that
// it has filled in results for everybody, incremented activeThreads to
// reflect that it is busy again and made certain that gc_started is false
// again so that everything is tidily ready for next time.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc_complete.wait(lock, []{ return gc_complete; });
    }
    fringe = fringeBis[threadId];
}

// Here I have just attempted to allocate n bytes but the attempt failed
// because it left fringe>=limit. I must synchronize with all other
// threads and one of the threads (it may not be me!) must garbage collect.
// When they synchronize with me here the other threads will also have tried
// an allocation, but the largest request any is allowed to make is
// VECTOR_CHUNK_BYTES (at present 2 megabyte). If all the maxThreads do
// this they can have caused fringe to overshoot by about an amount
// maxThreads*VECTOR_CHUNK_BYTES and if that caused uintptr_t arithmetic to
// overflow and wrap round then there could be big trouble. So when I
// allocate chunks of memory I ought to ensure that none has an end-address
// that close to UINTPTR_MAX! I think that on all realistic systems that is
// a problem that will not actually arise.
//
inline uintptr_t difficult_n_bytes()
{
// Every thread that comes here will need to record the value of its
// stack pointer so that the thread that ends up performing garbage
// collection can identify the regions of stack it must scan. For that to
// be proper the code must not be hiding values in register variables. The
// function "withRecordedStack()" tries to arrange that, so that when the
// body of code is executed stack_fringes[] has that information nicely
// set up. 
    withRecordedStack([&]
    {
// The next line will count down the number of threads that have entered
// this synchronization block. The last one to do so can serve as the
// thread that performs garbage collection, the other will just need to wait.
// The fetch_sub() operation here may cost much more than simple access to
// a variable, but I am in context were I am about to do things costing a
// lot more than that.
        int32_t a = activeThreads.fetch_sub(0x000001);
// The low byte of activeThreads counts the number of Lisp threads properly
// busy in the mutator. When it returns a value > 1 it means that at least
// one other thread has not yet joined in with this synchronization. It will
// be that last thread that actually performs the GC, so the current one
// has nothing to do - it must just sit and wait! When the final thread
// performs the fetch_sub() it will know that every other thread is now
// quiescent and it can perform as the master garbage collection thread.
        if ((a & 0xff) > 1) waitWhileAnotherThreadGarbageCollects();
        else garbageCollectOnBehalfOfAll();
// I must arrange that threads continue after idling only when the master
// thread has completed its work.
// At the end the GC can have updated the fringe and heaplimit values for
// each thread, so I need to put its updates in the correct place.
//
    });
    return result[threadId] - TAG_VECTOR;
}


// Now for higher level code that performs Lisp-specific allocation.

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

