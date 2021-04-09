// newallocate.h                          Copyright (C) Codemist, 2018-2021

// Serious work here started with a check-in in May 2018, but that followed
// one from some significant time - specifically I had started work on
// a conservative GC for the VSL Lisp in summer 2012!
// This version represents a substantial re-though in April 2020, with the
// ideas mainly ones that emerged while I was thinking about and implementing
// a project called Zappa that was intended to explore concurrency in
// garbage collection.


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

// There are some places in this file and also in newallocate.cpp and
// newcslgc.cpp where I write   xxx.load()  to be explicit that I want
// the underlying object of type T wrapped within a std::atomic<T>. In
// quite a few of those I would have hoped to be able to write merely xxx,
// and let C++ type deduction conclude what was intended, and with some
// versions of clang and gcc that seemed to happen, but with other
// compilers (well it happens that gcc 8.3.0 on a 32-bit ARM is the one
// I have noticed most) there were reports of ambiguity or worse. Being
// explicit only makes the code a bit more verbose so it is not that bad,
// but what it reveals is that I do not really understand that C++ type
// system well enough so there may be more marginal cases lurking.
// On concrete instance was
//    std::atomic<bool> flag(true);   std::cout << flag;
// where I at least appeared to need flag.load(), but I am having problems
// constructing a small example that gives the same trouble that the full
// version of the code seemed to. Again that alerts me to limits in my
// C++ skill-set.
// On looking further I come to suspect that the problems may derive
// from int128_t.h in the case that the 128-bit integer type is modelled
// using a class, and then many operations and casts to and from that are
// introduced often in template definitions that can probably specialise
// to more things than are good for them, leading to reports of ambiguity
// in apparently remote parts of the code!
// So it would be very nice if somebody who undetstands these things
// a bit better could look at int128_t.h and improve it to avoid it
// introducing extra type ambiguities...


#include "log.h"
#include <csetjmp>

#ifdef DEBUG
inline void testLayout();
#endif // DEBUG

// I have a 4-level hierarchy in my storage allocation scheme. At the
// large end I ask C++ to give me really large blocks, and I will call
// these "segments". I do not grab all the memory I might need right from
// the start, but as one segment starts to ger full I allocate another.
// I limit myself to having 16 segments in total and maybe the first
// might sensibly be say 128 Mbytes and subsequent ones each double in size.
// Given that using more than say a couple of hundred gigabytes of memory
// is not going to be feasible (and if and when it is this code will not
// represent sane use of it!) this lets me expand to provide as much as could
// ever be useful.
//
// Each segment is split into "pages" with each page at present 8 Mbytes.
// The emphemeral garbage collector arranges that allocation happens in
// one page. When that becomes full the PREVIOUS allocation-page is evacuated.
// The rest of the pages are either full of data assumed to be stable or are
// free for re-use (although some which are mostly free will contain data that
// had to be retained without migrating it as part of the consequence of a
// conservative collection policy). The largest single Lisp Object must fit
// within a page, and so this granularity for instance limits the size of the
// biggest integer that can be stored - but not in a way liable to disrupt
// the use-cases I envisage here - it is of the order of 20 million decimal
// digits.
//
// Within each page there are "chunks". The current expected chunk size will
// be 16 Kbytes (so there are about 512 chunks per page). At any stage each
// thread will have its own active chunk within which it can allocate without
// and special need for synchronization. When a thread fills a chunk another
// is allocated until the page becomes full. When a page becomes full a minor
// garbage collection can be triggered, and if that does not recover enough
// space a major one can be attempted.
//
// Chunks do not need to be consecutive within a page - there can be gaps
// between them and such gaps will naturally arise when pinned data and
// the allocation of large vectors leads to fragmentation. The system must
// keep track of all the chunks in each page with a combination of an index
// vector and chaining.
//
// Each chunk contains a sequence of Objects - these may be cons cells,
// strings, vectors, bignums etc. In the normal course of allocation all
// different sorts of objects may coexist in a chunk. When it is not possible
// to fit more data into a chunk it will be necessary to allocate a new one.
// The existing chunk can have its length reset so that it only contains
// valid data. The contents of chunks must be kept clean since the
// garbage collector can sometimes need to make a linear scan of them
// identifying all pointers within a chunk - so in particular binary data
// always needs protection with a header word in front of it and no
// uninitialized locations may be left. Truncating chunks when they are
// complete is part of the mechanism to ensure this.
//
// Chunks and fragmentation:
// There are three sources of fragmentation in the memory system:
// (1) Each Page is 8MB and individual CSL objects can be up to 2MB large.
//     Attempting to allocate a maximum size object thus risks leaving a
//     gap of up to 2MB, ie 25% of the Page.
// (2) Within each Page there can be some pinned chunks where at the time
//     of a recent garbage collection some sub-regions were (possibly)
//     referenced by ambiguous pointers. If there are a sequence of pinned
//     regions separated by just under 2MB and an attempt is made to allocate
//     a new huge object then essentially the whole page may be wasted!
//     More closely separated pinned items can cause havoc to allocation
//     of smaller items.
// (3) To support concurrent allocation each thread allocates within Chunks
//     that are typically pre-allocated at a size of 16KB. Allocating an
//     object larger than this default Chunk size can lead to a waste of
//     space in a previous partly-used Chunk.
// Of these (2) is has by far the most dramatic worst-case consequence!
// But in realistic use-cases there will only be a very few large objects
// allocated (I hope) and only a small number of pinned chunks, and so my
// guess is that in reality (3) will represent the greatest inefficiency in
// memory use.
// However (1) and (2) could be fatal. Suppose that allocation starts off
// somehow luckily and neatly so there is almost no loss down to
// fragmentation. Then garbage collection is triggered and all existing data
// gets copies into new space. If the allocation in that new space manages
// to suffer from really severe fragmentation and if all dats is alive then
// the copy could require dramatically more address space than the original
// active part of the heap. In the light of (2) there is no sane limit to
// how bad this could be.
// HOWEVER I think I should note three things.
// (a) ANY scheme that for allocating variable sized blocks of memory can
//     suffer from fragmentation and have really horrible worst cases. Well
//     ones that can subsequently move the memory blocks around may be immune,
//     but my situation is not truly unusual.
// (b) For a system with a copying GC to be running viably the amount of
//     live data at the end of garbage collection would need to be much
//     less than the total occupancy at the start of GC (or else the system
//     will need to GC again almost instantly). So at the end of GC the
//     target haf-space ought to have only modest occupancy - so the chance
//     of it overflowing because of fragmentation will be low!
// (c) There is no special reason for fragmentation in GC-copied material to
//     be worse than that in the heap that is being copied, so gross
//     expansion of the memory footprint is not to be expected.

// My allocation strategy will be
//     If a new object fits in the current chunk it goes there.
// otherwise
//     If the new object will be of size >= 8K then it goes in its
//     own new chunk and the existing one is left active. This arranges
//     that all chunks are >= 8K.
// otherwise
//     The existing chunk is terminated and a new one created of size
//     16K. The new object will fit into it! The waste space at the end
//     of the old chunk is at worst 8K and the new chunk will have at
//     least 8K free in it.
//
// So when a new chunk is allocated to make space for an object of size n
// the chunk size will be (n>=8K ? n : 16K) with some small adjustments
// relating to the size of chunk headers.
//
// In the worst case around half space is lost to fragmentation. In
// the worst case the number of chunks in a page may be up to 1024 (8M/8K).
// 
// Note that I have not yet updated the code here to implement the above!


using std::hex;
using std::dec;

static const size_t pageSize = 8*1024*1024;      // Use 8 Mbyte pages

// targetChunkSize will be taken to include the few words of header
// at the start of each Chunk.
static const size_t targetChunkSize = 16*1024;   // Target chunk size

// It may be useful to arrange that each page has a field in it that
// explains its status. In particular when an ambiguous pointer refers into
// a page it can be useful for it to have a simple test to see if that page
// is in use or not. The enumeration here lists the possibilities.

enum PageClass
{   reservedPageTag   = 0x00,     // Reserved value, never used.

    freePageTag       = 0x01,     // All the data area in this page is free.
    mostlyFreePageTag = 0x02,     // Mostly empty page but with
                                  //    some pinned data within it.
    busyPageTag       = 0x03,     // Page contains active data.
};

extern bool allocateSegment(size_t);

// Each Chunk has a header that contains various information, including in
// particular its length and information that is used to keep track of
// Chunks that have ambiguous pointers within them - ie that are pinned.
// When a Chunk has been used and is full, its chunkFringe will be set to
// identify the end of the last allocated item in it. Often this will be
// before its length is all used up, because the item to be allocated next
// might be bigger than the remaining available block of memory. In the
// case that the Chunk ends up pinned and garbage collection leaves this
// Chunk as part of a MostlyFree Page the length can be decreased down to
// chunkFringe, just slightly reclaiming the waste space.

class Chunk
{
public:
    atomic<uintptr_t> length;
    atomic<uintptr_t> chunkFringe;
    atomic<bool> isPinned;
    atomic<Chunk *>chunkStack;
// At the start of garbage collection as I collect a chain of pinned chunks
// those chunks may appear on the list in arbitrary order, but at the end
// of garbage collection if a Page has a number of pinned Chunks within it
// they must be sorted into ascending order. Arranging that will mean that
// I can release the gaps between chunks for allocation easily.
// So within a chunk I start off with gFringe pointing at usableSpace and
// gLimit at either the start of the first pinned chunk or at the end of
// the whole page. When that region gets full the gLimit pointer either
// tells me that I have used up the entire page, or the pinned chunk it
// points at lets me find the new gFringe (using the length field) and the
// end of the next free block (using pinChain - and if that is nullptr the
// relevant limit is the end of the page.
    atomic<Chunk *>pinChain;
// During GC it is sometimes necessary for the GC to scan material
// within the chunk that it itself is allocating copied stull within. It
// may in fact do this in several stages, each processing material until
// everything currently in that chunk is tidy. But then it may find another
// Chunk to scan and that can add a bit more. This pointer has to be
// initialized in every Chunk that is a candidate for scanning.
    atomic<uintptr_t> selfScanPoint;
// The rest of the chunk is the region within which data is kept.
// Its size will be such that the entire Chunk has length a specified by
// its first word.
    atomic<LispObject>usableSpace[];
// Now I can have some accessor (etc) methods:
//
    uintptr_t dataStart()
    {   return reinterpret_cast<uintptr_t>(&usableSpace);
    }
    uintptr_t dataEnd()
    {   return reinterpret_cast<uintptr_t>(this) + length;
    }
    bool pointsWithin(uintptr_t p)
    {   return p >= dataStart() && p < chunkFringe;
    }
};

// I am going to require Pages to be aligned at nice neat boundaries
// because then if I have an arbitrary address within one I will be able to
// find the page header using a simple AND operation.

// I will allocate chunks that have size AT LEAST targetChunkSize/2. When
// That means I can be confident that no page will every end up with more
// than chunksPerPage chunks (and the numeric value with 8M pages and 16K
// chunks is 1024).

static const size_t chunksPerPage = 2*pageSize/targetChunkSize;

class alignas(pageSize) Page
{
public:
    atomic <Page *>chain;
    atomic<uintptr_t>fringe;
    atomic<uintptr_t>limit;
    atomic<PageClass> pageClass;
    atomic<bool> hasPinned;
    atomic<Page *> pinChain;
    atomic<Chunk *> pinnedChunks;
// In general I expect chunks all to be at least targetChunkSize large,
// but fragmentation may mean I end up with some that are smaller. I
// need a table showing all the chunks in the page and I will limit its size
// in such a way that only in extreme cases will it set a limit.
    bool chunkMapSorted;
    atomic<size_t> chunkCount;
    atomic<Chunk *> chunkMap[chunksPerPage];
    static const size_t pageWords = pageSize/sizeof(LispObject);
    static const size_t bpw = 8*sizeof(uintptr_t);// bits per word in map.
    static const size_t bitmapSize = (pageWords+bpw-1)/bpw;
    static const size_t bitmap1Size = (bitmapSize+bpw-1)/bpw;
    static const size_t bitmap2Size = (bitmap1Size+bpw-1)/bpw;
// dirtyMap has one bit for every pointer-sized unit within the Page.
// so one factor of bpw here is so I cover a resolution of uintptr_t
    atomic<uintptr_t> dirtyMap[bitmapSize];
// The two smaller maps make it possible to use bit-search operations
// such as the one that finds the top set bit in a word to find all the
// "dirty" doublewords in a Page fairly rapidly. See the implementation of
// write-barrier() for how these are used.
    atomic<uintptr_t> dirtyMap1[bitmap1Size];
    atomic<uintptr_t> dirtyMap2[bitmap2Size];
    atomic<bool> hasDirty;
    atomic<Page *>dirtyChain;
    atomic<Page *>dirtyChainBack;

    alignas(64) atomic<LispObject> data[2];   // The real data in the page.
// The data[] field really extends up to make the overall size of
// the page be pageSize.
};

extern Page *currentPage;       // Where allocation is happening.
extern Page *previousPage;      // Previous currentPage. Evacuated by
                                // the generational collector.
extern Page *busyPages;         // All pages that are in use (including above).
extern Page *mostlyFreePages;   // Free apart from some pinned data.
extern Page *freePages;         // Free and clear of pinning.
extern Page *oldPages;          // Used during garbage collection.

extern size_t busyPagesCount;
extern size_t mostlyFreePagesCount;
extern size_t freePagesCount;
extern size_t oldPagesCount;

// First I will give code that implements the write-barrier. It is passed
// the address of a valid Lisp location - that can be one of &car(x),
// &cdr(x) or &elt(v, n). It records the fact that an update has
// been made to memory in that region by setting a byte in dirty[]. Because
// the address it is given will always be a VALID address of some location
// in the Lisp heap it can easily find the relevant page...

extern atomic<Page *> dirtyPages;
extern Page *globalPinChain;

inline void write_barrier(LispObject *p, LispObject q)
{   *p = q;
// Only up-pointers can cause trouble, so if I write in something that
// is not even a pointer or that is a pointer into a page that the
// generational collector will not move I do not need to do anything. And
// maybe the tests for that situation are cheap enough that the test is
// a good idea. Note that NIL is a very special case - it is tagged as a
// pointer but it lives outside the main heap. Note here that q should
// be a valid (precise) LispObject and hence is a pointer to an address
// strictly within a page.
    Page *pp;
    if (q == nil ||
        !is_pointer_type(q) ||
        ((pp = reinterpret_cast<Page *>(
              static_cast<uintptr_t>(q) & -pageSize)) != currentPage &&
          pp != previousPage &&
          pp->pageClass.load() == busyPageTag))
        return;
    uintptr_t a = reinterpret_cast<uintptr_t>(p);
// Round down to a Page boundary. Because pages are always allocated
// properly aligned this will give the start of the Page containing the
// word being addressed. p was also a precise pointer and so (eg) it can not
// point to one beyond the end of the page. So the mask operator here that
// identifies its page is safe.
    Page *x = reinterpret_cast<Page *>(a & -pageSize);
    const size_t bpw = 8*sizeof(uintptr_t);   // bits per word in bitmap.
// The bit-position is measured in units of sizeof(LispObject)
    uintptr_t offset = (a & (pageSize-1))/sizeof(LispObject);
// I can now convert that to a location and a bit and offset in the bitmap.
    uintptr_t bit = uptr_1 << (offset%bpw);
    size_t wordAddr = offset/bpw;
// Recording what is dirty is one thing but later on I will need to be
// able to inspect every dirty word, and that means I need to scan
// the recorded information fairly rapidly. The idea i use is that a dirty
// word is recorded via a bit in a per-page bitmap. That needs 1 bit per
// 64-bits on a 64-bit machine or 1 per 32 on a 32-bit machine.
// Making must be possible from multiple threads, hence the may is made using
// std::atomic and updates using fetch_or(). The first time a bit is set
// in the main bit-map a secondary map will be marked to show that a word
// in the main map is in use. Subsequent use of exactly the same input
// will not need to do this so will be cheaper. The first time a bit is set
// in the second map a bit gets set in a third. And the first time one gets
// set in the third map the entire page is pushed onto a list called
// dirtyPages - again using a thread-safe lock-free process. The effect of
// all of this is that to find all dirty words the chain of dirty pages
// is traversed and the various levels of bitmaps strongly reduce the
// cost of spotting the locations of interest by using "count leading zeros"
// operations in words from the bitmaps.
    if ((x->dirtyMap[wordAddr].fetch_or(bit) & bit) == 0)
    {   bit = uptr_1 << (wordAddr%bpw);
        wordAddr /= bpw;
        if ((x->dirtyMap1[wordAddr].fetch_or(bit) & bit) == 0)
        {   bit = uptr_1 << (wordAddr%bpw);
            wordAddr /= bpw;
            if ((x->dirtyMap2[wordAddr].fetch_or(bit) & bit) == 0)
            {   x->hasDirty.store(true);
                for (;;)
                {   Page *old = dirtyPages;
                    x->dirtyChain.store(old);
                    if (dirtyPages.compare_exchange_weak(old, x)) break;
                }
            }
        }
    }
}

// There will be times when I can clear an individual cell's status as
// dirty, and this function is here to do just that.

inline void write_unBarrier(LispObject *p)
{   uintptr_t a = reinterpret_cast<uintptr_t>(p);
    Page *x = reinterpret_cast<Page *>(a & -pageSize);
    const size_t bpw = 8*sizeof(uintptr_t);   // bits per word in bitmap.
    uintptr_t offset = (a & (pageSize-1))/sizeof(LispObject);
    uintptr_t bit = uptr_1 << (offset%bpw);
    size_t wordAddr = offset/bpw;
// Here I want to clear a bit in the bitmap, and if that leaves the whole
// word zero I can clear a bit in the next level map up. Because this is
// only done within the garbage collector at a stage where I am only running
// on one thread I do not need to worry about use of explicitly thread-safe
// updates, but the items being worked on are still atomic<T> ones,
    if (x->dirtyMap[wordAddr].fetch_and(~bit) == bit)
    {   bit = uptr_1 << (wordAddr%bpw);
        wordAddr /= bpw;
        if (x->dirtyMap1[wordAddr].fetch_and(~bit) == bit)
        {   bit = uptr_1 << (wordAddr%bpw);
            wordAddr /= bpw;
            if (x->dirtyMap2[wordAddr].fetch_and(~bit) == bit)
            {   x->hasDirty = false;
// Here I want to delete the page from the chain of dirty pages. During
// regular computation I have just a singly linked list but at the
// start of garbage collection I can scan that and set up dirtyChainBack
// entries on each page involved so that I have a two-way list, and then
// the deletion here can have unit cost.
                Page *prev = x->dirtyChainBack;
                Page *next = x->dirtyChain;
                if (prev == nullptr) dirtyPages = next;
                else prev->dirtyChain = next;
                if (next != nullptr) next->dirtyChainBack = prev;
            }
        }
    }
}

// This is a function for the GC to call to fill in the back-pointers.

inline void fillInBackChains()
{   Page *prev = nullptr;
    for (Page *p=dirtyPages; p!=nullptr; p=p->dirtyChain)
    {   p->dirtyChainBack = prev;
        prev = p;
    }
}

// Here I make what is a potentially delicate but pragmatic assumption,
// that an atomic<LispObject> is represented in memory in just the same
// way as a simple LispObject - so the only difference is that when one
// accesses treating it as atomic the compiler is both more careful about
// re-ordering memory reference instructions and it may put in extra
// memory fence instructions so that the hardware does not shuffle access
// or leave some write sitting in the cache associated with one CPU but
// not visible to others.

inline void write_barrier(atomic<LispObject> *p, LispObject q)
{   write_barrier(reinterpret_cast<LispObject *>(p), q);
}

// Now to match the above I need code that will identify every dirty
// item. It calls the function that is provided as an argument on each
// dirty address.

typedef void processDirtyCell(atomic<LispObject> *a);
extern int nlz(uint64_t a);

inline void scanDirtyCells(processDirtyCell fn)
{   for (Page *p=dirtyPages; p!=nullptr; p=p->dirtyChain.load())
    {   if (!p->hasDirty) continue;
        for (size_t i2=0; i2<sizeof(p->dirtyMap2)/sizeof(p->dirtyMap2[0]);
             i2++)
        {   uintptr_t b2 = p->dirtyMap2[i2];
            while (b2 != 0)
            {   int n2 = nlz(static_cast<uint64_t>(b2));
                size_t i1 = 8*sizeof(uintptr_t)*i2 + 63 - n2;
                uintptr_t b1 = p->dirtyMap1[i1];
                while (b1 != 0)
                {   int n1 = nlz(static_cast<uint64_t>(b1));
                    size_t i0 = 8*sizeof(uintptr_t)*i1 + 63 - n1;
                    uintptr_t b0 = p->dirtyMap[i0];
                    while (b0 != 0)
                    {   int n0 = nlz(static_cast<uint64_t>(b0));
                        size_t i = 8*sizeof(uintptr_t)*i0 + 63 - n0;
                        (*fn)(reinterpret_cast<atomic<LispObject> *>(
                             reinterpret_cast<uintptr_t>(p) + i*sizeof(LispObject)));
                        b0 -= uptr_1<<(63-n0);
                    }
                    b1 -= uptr_1<<(63-n1);
                }
                b2 -= uptr_1<<(63-n2);
            }
        }
    }
}

// Here there may be some items that have been marked as "dirty" but I want
// to discard that information totally. This is for instance something that
// happens when I perform a global garbage collection, since at the end
// of that there is no data at all that is at risk of scavenging and that
// hence needs protecting if there is an up-reference to it.

inline void clearAllDirtyBits()
{   for (Page *p=dirtyPages; p!=nullptr; p=p->dirtyChain.load())
    {   if (!p->hasDirty) continue;
        p->hasDirty = false;

        for (size_t i2=0; i2<sizeof(p->dirtyMap2)/sizeof(p->dirtyMap2[0]);
             i2++)
        {   uintptr_t b2 = p->dirtyMap2[i2];
            if (b2 != 0) continue;
            {   p->dirtyMap2[i2] = 0;
                while (b2 != 0)
                {   int n2 = nlz(static_cast<uint64_t>(b2));
                    size_t i1 = 8*sizeof(uintptr_t)*i2 + 63 - n2;
                    uintptr_t b1 = p->dirtyMap1[i1];
                    if (b1 != 0)
                    {   p->dirtyMap1[i1] = 0;
                        while (b1 != 0)
                        {   int n1 = nlz(static_cast<uint64_t>(b1));
                            size_t i0 = 8*sizeof(uintptr_t)*i1 + 63 - n1;
                            p->dirtyMap[i0] = 0;
                            b1 -= uptr_1<<(63-n1);
                        }
                    }
                    b2 -= uptr_1<<(63-n2);
                }
            }
        }
    }
    dirtyPages = nullptr;
}

// The code that implements pinning is in cslgc.cpp. In some respects the
// capabilities it provides are a bit like those of my write barrier in that
// I can record the fact that some address is to be pinned and I can scan
// all regions containig pinned data. There are three crucial differences:
// (1) The address I ask to pin may not even be a pointer to anywhere within
//     the Lisp heap - while that used with the write barrier is guaranteed
//     to be a precise reference to a valid Lisp cell.
// (2) For the write barrier I end up recording the exact location that is
//     marked. For pinning I only pin to the granularity of a Chunk.
// (3) The pinning operation is run from a single thread, while the write
//     barrier could be used simultaneously from multiple threads, so the
//     letter needs much more care over thread safety.

extern void processAmbiguousValue(bool major, uintptr_t a);
typedef void processPinnedChunk(Chunk *c);
extern void scanPinnedChunks(processPinnedChunk *pc);
extern void clearAllPins();

extern uint64_t threadMap;

class ThreadStartup
{
public:
    ThreadStartup();
    ~ThreadStartup();
};


// For up to 16 segments I have...
//   heapSegmentCount   number of allocated segments
//   heapSegment[i]      base address of a segment of memory
//   heapSegmentSize[i] size of useful part of that segment, in bytes
//   heapSegmentTotalSize[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

extern void *heapSegment[16];
extern char *heapSegmentBase[16];
extern size_t heapSegmentSize[16];
extern size_t heapSegmentCount;

void initHeapSegments(double n);

// findHeapSegment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it, or -1 if the
// bit-pattern could not be interpreted as a pointer to within the
// memory I have allocated.

// Given a value I want to see if it could be a pointer into one of the
// allocated segments. Because there are only 16 of them and if I keep my
// table of segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

inline int findSegment2(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int findSegment4(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+2]))
        return findSegment2(p, n);
    else return findSegment2(p, n+2);
}

inline int findSegment8(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+4]))
        return findSegment4(p, n);
    else return findSegment4(p, n+4);
}

inline int findSegment16(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+8]))
        return findSegment8(p, n);
    else return findSegment8(p, n+8);
}

inline int findHeapSegment(uintptr_t p)
{   int n = findSegment16(p, 0);
    if (p < reinterpret_cast<uintptr_t>(heapSegment[n]) ||
        p >= reinterpret_cast<uintptr_t>(heapSegment[n]) +
        heapSegmentSize[n]) return -1;
    return n;
}

// This finds a page that a potential pointer p is within, or returns nullptr
// if there is not one

inline Page *findPage(uintptr_t p)
{   int n = findHeapSegment(p);
    if (n < 0) return nullptr;
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
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n +32;
        x = x <<32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n +16;
        x = x <<16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFU)
    {   n = n + 1;
    }
    return n;
}

#endif // __GNUC__
#define NLZ_DEFINED 1

//static const unsigned int maxThreads = 64;
static const unsigned int maxThreads = 2; // Nicer for debugging!

#define TL_threadId 50
DECLARE_THREAD_LOCAL(uintptr_t, threadId);
#define TL_fringe 51
DECLARE_THREAD_LOCAL(uintptr_t, fringe);

extern atomic<uintptr_t> limit[maxThreads];
extern Chunk*                 myChunkBase[maxThreads];
extern uintptr_t              limitBis[maxThreads];
extern uintptr_t              fringeBis[maxThreads];
extern size_t                 request[maxThreads];
extern LispObject             result[maxThreads];
extern size_t                 gIncrement[maxThreads];
extern atomic<uintptr_t>      gFringe;
extern uintptr_t              gLimit;

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
//   Variables will be set as for Possibility 1 save that
//   gIncrement[threadId] is set to the amount by which gFringe
//   had been incremented.
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

enum GcStyle
{
    GcStyleNone,
    GcStyleMinor,
    GcStyleMajor
};

extern GcStyle userGcRequest;

extern uintptr_t difficult_n_bytes();

inline Header makeHeader(size_t n, int type)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + type;
}

// At times I want to put a vector header at the start of a block of
// memory, using an atomic access to insert it. This does the job. Note that
// a is an untagged pointer here.

inline void setHeaderWord(uintptr_t a, size_t n, int type=TYPE_PADDER)
{   reinterpret_cast<atomic<uintptr_t> *>(a)->store(makeHeader(n, type));
}

// This is the core part of CONS and also of the code that allocates
// bignums, strings and vectors.


#ifdef DEBUG
namespace REAL
{
#endif // DEBUG

inline LispObject get_n_bytes1(size_t n, uintptr_t thr,
                               uintptr_t r, uintptr_t w)
{
// There are two possibilities here. One is that the new block I need to
// allocate really will not fit in the current chunk, and the other is that
// some other thread had set limit[] to zero to force this one to join in
// with garbage collection. In the former case I may in fact be able to make
// this allocation simply by grabbing a fresh chunk. In either case I need to
// record the end-point within this Chunk...
// I want to make every chunk "tidy" because when I have one that gets
// pinned I will need to make a linear scan of it treating every pointer
// field within it as an unambiguous list-base. Any uninitialized or otherwise
// wild regions within it could cause disaster! I do this by recording its
// high water mark.
    if (w != 0)
    {
// I now need to allocate a new chunk. gFringe and gLimit delimit a region
// within of size PAGE (perhaps 8 Mbytes) and I will start by allocating
// chunks sequentially within that page. By making gFringe atomic I can so
// this in a lock-free manner.
// I will make my next chunk big enough for the current allocation request
// with targetChunkSize left over after that. This ensures that even big
// vector requests can be satisfied.
        uintptr_t oldFringe = r;
        Chunk *newChunk =
            reinterpret_cast<Chunk *>(gFringe.fetch_add(targetChunkSize+n));
        r = newChunk->dataStart(); // safe even if chunk pointer is bad!
// Be aware that other threads might be doing (atomic) increments on gFringe
// at the same time that this one does. They will each reserve separate
// new chunks, but some of these may fall in memory well above gLimit. And
// hence they could be beyond the end of the current Page.
// I am going to assume (ha ha) that even if the maximum number of threads
// each increment gFringe by the largest possible amount then it will not
// suffer arithmetic overflow. If I have a maximum of 16 threads then I ought
// to ensure that gLimit+130M > gLimit.
        fringe = r + n;
// I can not use newChunk->dataEnd() on the next line because the chunk does
// not yet have its length field filled in. And that has to be the case
// because the region I have set aside for this Chunk may be beyond the end
// of the current Page (or the next pinned place within the Page).
        uint64_t newLimit = reinterpret_cast<uintptr_t>(newChunk) + targetChunkSize+n;
// Possibly the allocation of the new chunk ran beyond the current page
// and that will be cause to consider triggering garbage collection. If the
// chunk size is 16K and the page size 8M it will take 512 chunk allocations
// before a page is filled. If for now I suppose that having 16 threads all
// allocating cons cells furiously is an extreme case then that will mean
// that each thread gets through 32 chunks before the extra (probably severe)
// costs of page allocation arise. So this is about 1 in 32000 conses in the
// heaviest multi-thread case and only 1 in 0.5 million in a single thread
// scenario.
//
// I want to identify the Page that I am currently allocating within. In an
// earlier draft I masked newChunk with -pageSize. However newChunk could
// be well above the end of valid allocation space in the current page and
// might in fact be within the next sequential page. So rather than that I
// use oldFringe-1. The "-1" is because maybe the previous fringe had
// ended up such that the previously allocated item had totally filled the
// Chunk and Page, so it points at the location just beyond the Page end.
        Page *p = reinterpret_cast<Page *>((oldFringe-1) & -pageSize);
        if (newLimit <= gLimit)
        {
// Now my allocation of a new chunk has been successful. Before I test if
// participation in a garbage collection on behalf of some other thread
// is required I need to record this chunk in the table of chunks that
// the page maintains. I also need to fill in the chunk header -- well the
// pinChain pointer does not need initializing until and unless the page
// gets pinned, but the isPinned flag must start off false so that when the
// GC finds an ambiguous pointer within this chunk it knows when that is the
// first such.
            myChunkBase[thr] = newChunk;
            newChunk->length.store(targetChunkSize+n);
            newChunk->isPinned.store(false);
            newChunk->pinChain.store(nullptr);
            size_t chunkNo = p->chunkCount.fetch_add(1);
            p->chunkMap[chunkNo].store(newChunk);
// I wish to write back limit[thr] but it is possible that in
// the meanwhile somebody set that to zero, so I need to be a bit careful.
// Specifically I will only write back the new limit if the old one was
// still in force.
//
// Here I have (successfully) allocated a new chunk, and I have set my
// fringe to point within it. Because limit[thr] can
// be arbitrarily clobbered by others I will only update it if it has
// not changed since I loaded it earlier. If it has changed it will have
// been set to zero and I must participate in a GC.
            limitBis[thr] = newLimit;
            bool ok = limit[thr].compare_exchange_strong(w, newLimit);
#ifdef DEBUG
            if (ok) testLayout();
#endif // DEBUG
            if (ok) return static_cast<LispObject>(r);
        }
        gIncrement[thr] = targetChunkSize+n;
        fringe = oldFringe;
//        cout << "At " << __WHERE__ << " fringe set to oldFringe = " << hex << oldFringe << dec << "\r" << endl;
    }
    else
    {
// Here I am about to be forced to participate in garbage collection,
// typically for the benefit of some other thread.
        cout << "GC triggered\r\n";
        if (myChunkBase[thr] != nullptr) myChunkBase[thr]->chunkFringe = r;
        gIncrement[thr] = 0;
        fringe = r;
//        cout << "At " << __WHERE__ << " fringe set to r = " << r << "\r" << endl;
    }
    fringeBis[thr] = fringe;
//    cout << "At " << __WHERE__ << " fringeBis[" << thr
//         << "] = " << hex << fringeBis[thr] << dec << "\r" << endl;
    request[thr] = n;
// Here I can not complete the work with this inline function because
// either I have run out of space for a new chunk or because some
// other thread had done that and had set my limit register to zero
// to tell me. I set fringe back to the value that it had on entry,
// so the situation when I call difficult_n_bytes() is just as if it had
// been called directly from the main program save that gFringe may have
// been incremented - possibly beyond gLimit.
    return static_cast<LispObject>(difficult_n_bytes());
}

inline LispObject get_n_bytes(size_t n)
{
// The size passed here MUST be a multiple of 8.
// I have a thread-local variable fringe, and limit[threadId]
// is in effect thread-local. These delimit a region of size about
// targetChunkSize within which allocation can be especially cheap.
// limit[threadId] is atomic and that indicates that
// other threads may access it. In particular another thread can set it to
// zero to cause this thread to synchronize with others to participate in
// garbage collection. Because on some platforms access to thread-locals is
// more expensive than use of simple variables or is even achieved via
// strange C++ trickery, I isolate loading and storing such values into
// simple statements that transfer values to local variables.
    uintptr_t thr = threadId;
    uintptr_t r = fringe;
    uintptr_t fr1 = r + n;
    fringe = fr1;
    uintptr_t w = limit[thr].load();
// The simple case completes here. If each chunk is around 16K then only 1
// CONS in 1000 or so will take the longer route. I rather hope that the
// common case will be lifted to be rendered in-line
    if (fr1 <= w) LIKELY return static_cast<LispObject>(r);
    UNLIKELY
    return get_n_bytes1(n, threadId, r, w);
}

#ifdef DEBUG
} // end of namespace

inline size_t get_size[8];
inline LispObject get_value[8];
inline unsigned int get_count = 0;
inline unsigned int get_trace = 0x7fffffff; // 514572-10;

inline LispObject previousCons = 0;

inline LispObject get_n_bytes(size_t n)
{   if (++get_count >= get_trace) cout << "get_n_bytes " << n << "\r\n";
    LispObject r = REAL::get_n_bytes(n);
    if (get_count >= get_trace) cout << hex << r << dec << "\r\n";
    for (int i=0; i<8; i++)
        my_assert(r != get_value[i], []{ cout << "repeat result\r\n";});
    get_size[get_count & 7] = n;
    get_value[get_count & 7] = r;
    my_assert(r > previousCons, []{ cout << "non-increasing allocation\r\n"; });
    previousCons = r;
    return r;
}

extern void crudeprin(LispObject a);
extern void crudeprint(LispObject a);

inline void dump_gets()
{   cout << "get_count = " << get_count << "\r\n";
    for (int i=1; i<=8; i++)
    {   LispObject v = get_value[(get_count+i)&7];
        cout << (8-i) << "... "
             << "size=" << get_size[(get_count+i)&7] << ": "
             << hex << v << dec << " ";
        if (is_cons(v))
        {   crudeprin(car(v));
            cout << " . ";
            crudeprin(cdr(v));
        }
        cout << "\r\n";
    }
}

#else // DEBUG

inline void dump_gets()
{
}

#endif // DEBUG


// It will be important to poll frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupted.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

inline void poll()
{   uintptr_t w;
    uintptr_t thr = threadId;
    if (fringe > (w = limit[thr].load()))
    {
// Here I need to set everything up just as if I had been making an
// allocation request for zero bytes.
        fringeBis[thr] = fringe;
//        cout << "Polling at " << __WHERE__ << "fringeBis[" << thr
//             << " = " << hex << fringeBis[thr] << dec << "\r" << endl;
        request[thr] = 0;
        gIncrement[thr] = 0;
        static_cast<void>(difficult_n_bytes());
    }
}

// The following can be used as in
//   withRecordedStack([&]{ ... });
// where the "..." represents some actions. Its job is to arrange that
// the C stack has all local values on (in particular that nothing is
// referenced solely via machine registers) and that a stackFringe variable
// is set so that the garbage collector can do its job properly.


// The following code makes a whole slew of assumptions about how the
// compiler and system library will treat it! I will explain what I hope
// will happen, but a sufficiently clever compiler could without doubt
// defeat me.

// A C++ system is liable to have some "callee save" registers and keep the
// values of some variable in them. A conservative garbage collector needs
// to access their values. I EXPECT that setjmp will dump copies of all
// such registers (at least!) into the jmp_buf, thus ensuring that a copy of
// all the data is present on the stack. Well here the jmp_buf is not
// referenced again or elsewhere, so maybe a compiler could consider it
// unused and just remove the call to setjmp. To discourage that I have
// buffer_pointer referring to the jmp_buf, and then at least potentially
// (as far as the compiler can tell) in some other compilation unit there
// might be code reachable from action() that does a longjmp() via it.
// I alse want the jmp_buf to have been allocate on the stack at a lower
// address than any other values currently in use. The "noinline" qualifier
// as provided by gcc is intended to help to enforce that by arranging that
// withRecordedStack() has its own stack frame with almost nothing except
// action() and the jmp_buf in it. If values used within action() end up
// on the stack above buffer that should not be a problem.
//
// There can be at most maxThreads threads in play, and each must have
// the thread-local value threadId set.

extern std::jmp_buf *buffer_pointer;

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

extern uintptr_t stackBases[maxThreads];
extern uintptr_t stackFringes[maxThreads];

template <typename F>
#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
inline void may_block(F &&action)
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
// ASSUME that setjmp dumps all the machine registers into the jmp_buf.
    if (setjmp(buffer) == 0)
    {   stackFringes[threadId] = reinterpret_cast<uintptr_t>(buffer);
// I will need to do more here to decrement the count of threads that
// the system knows to be potentially involved in memory allocation.
        action();
// ... and fix it up again here, possibly with a RAII style object.
// This use of longjmp is intended to help guarantee that the buffer
// and its contents are kept intact across the call to action().
        std::longjmp(buffer, 1);
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
    {   stackFringes[threadId] = reinterpret_cast<uintptr_t>(buffer);
        action();
        std::longjmp(buffer, 1);
    }
};



extern std::mutex mutexForGc;
extern std::mutex mutexForFreePages;
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

extern atomic<uint32_t> activeThreads;
//  0x00 : total_threads : lisp_threads : still_busy_threads
//
// The meaning of all those is as follows:
//   total_threads: Count of all the threads that CSL has started and that
//                  might ever participate as Lisp mutators.
//   lisp_threads:  The number of threads that are at present running as
//                  Lisp mutators. This can be less than total_threads
//                  because if a thread is about to perform a (potentially)
//                  blocking system call it must decrease thsi count. All
//                  threads included in this count thereby guarantee that they
//                  will either allocate memory or perform a polling operation
//                  fairly soon.
//   still_busy_threads: Used during synchronization at the start and end of
//                  garbage collection. Specifically as threads poll and
//                  discover that a garbage collection is pending they
//                  decrement this field. When it reaches zero that indicates
//                  that all (lisp) threads have become quiescent, and so
//                  global action can start.
// There can be delicacies involved in updating all these! In particular
// starting or terminating a thread while all others are in the process
// of synchronizing for or after garbage collection is something that will
// involve some care!

extern std::condition_variable cvForCopying;
extern unsigned int activeHelpers;

extern bool generationalGarbageCollection;
extern void generationalGarbageCollect();
extern void fullGarbageCollect();

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
//      {   std::unique_lock<std::mutex> lock(mutexForGc);
//          gc_start_cv.wait(lock, []{ return gc_started; });
//      }
// followed immediately  by
//      activeThreads++;
//      {   std::unique_lock<std::mutex> lock(mutexForGc);
//          gc_end_cv.wait(lock, []{ return gc_finished; });
//      }
// The key thread on the other hand can go
//      gc_finished = false;
// MUST ensure that gc_finished will be seen as false by all other threads
// before gc_started is seen as true, because otherwise spurious wake-ups
// on gc_start_cv and gc_end_cv could let one of the other threads run
// through improperly.
//      {   std::lock_guard<std::mutex> lock(mutexForGc);
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

extern void setUpEmptyPage(Page *p);
extern void setVariablesFromPage(Page *p);
extern void saveVariablesToPage(Page *p);

inline void restoreGfringe()
{   size_t inc = 0;
    for (unsigned int i=0; i<maxThreads; i++)
    {   result[i] = nil;
//        cout << "result[" << i << "] = nil = " << std::hex << nil << std::dec << "\r" << endl;
        inc += gIncrement[i];
        gIncrement[i] = 0;
    }
// Note that I write this as "gFringe = gFringe - inc;" rather than as
// "gFringe -= inc;" because there is a risk that the latter might compile
// into an atomic decrement - and that is not needed here and may be a lot
// more expensive than the load and store of the alternative. I further put
// in an explicit ".load()" because without that the subtraction leads to
// an "ambigious overload" moan at least on 32-bit ARM.
    gFringe = gFringe.load() - inc;
}

inline void fitsWithinExistingGap(unsigned int i, size_t n, size_t gap)
{
// The request made will fit within the existing Chunk for thraed i.
    result[i] = fringeBis[i] + TAG_VECTOR;
//    cout << "result[" << i << "] = " << std::hex << result[i] << std::dec << "\r" << endl;
// If I fill in a result for this I set it to show it does not need any more.
    request[i] = 0;
    setHeaderWord(result[i]-TAG_VECTOR, n, TYPE_VEC32);
    fringeBis[i] += n;
//    cout << "At " << __WHERE__ << "fringeBis[" << i
//         << " = " << hex << fringeBis[i] << dec << "\r" << endl;
    gap -= n;
// Make the end of the Chunk safe. This Chunk is not full, but a GC that is
// (probably) about to happen can need to scan it so its chunkFringe info
// must be filled in.
// If I get here during a GC 
    myChunkBase[i]->chunkFringe = fringeBis[i];
}

inline void ableToAllocateNewChunk(unsigned int i, size_t n, size_t gap)
{
// OK I can allocate a new Chunk for one of the threads here. First I should
// insert padding so that the tail end of the previous chunk is tidily
// filled in.
//    cout << "At " << __WHERE__ << " ableToAllocateNewChunk\r\n";
    myChunkBase[i]->chunkFringe = fringeBis[i];
    Chunk *newChunk = reinterpret_cast<Chunk *>(gFringe.load());
    newChunk->length = n+targetChunkSize;
    newChunk->isPinned = false;
    newChunk->pinChain = nullptr;
    size_t chunkNo = currentPage->chunkCount.fetch_add(1);
    currentPage->chunkMap[chunkNo].store(newChunk);
    result[i] = newChunk->dataStart() + TAG_VECTOR;
//    cout << "result[" << i << "] = " << std::hex << result[i] << std::dec << "\r" << endl;
    uintptr_t thr = threadId;
    myChunkBase[thr] = newChunk;
    request[i] = 0;
// If I allocate a block here it will need to be alive through an impending
// garbage collection, so I will make it seem like a respectable Lisp
// vector with binary content.
//    LispObject rr = result[i];
    my_assert(findPage(result[i]) != nullptr); // @@@
//    cout << std::hex << result[i] << " " << rr << "\r" << endl;
    setHeaderWord(result[i]-TAG_VECTOR, n, TYPE_VEC32);
    fringeBis[i] = newChunk->dataStart() + n;
//    cout << "At " << __WHERE__ << " fringeBis[" << i
//         << "] = " << hex << fringeBis[i] << dec << "\r" << endl;
    gFringe = limitBis[i] = limit[i] =
              fringeBis[i] + targetChunkSize;
}

inline void regionInPageIsFull(unsigned int i, size_t n,
                               size_t gap, unsigned int &pendingCount)
{
// Here the current region in the Page is full. I may either have reached the
// very end of the page or I may have merely run up against a pinned Chunk
// within it.
//    cout << "At " << __WHERE__ << " gFringe = " << hex << gFringe << dec << "\r" << endl;
//    cout << "At " << __WHERE__ << " pageSize = " << hex << pageSize << dec << "\r" << endl;
//
// Take care because gFringe can point at the start of the next consecutive
// Page.
    uintptr_t pageEnd = ((gFringe.load()-1) & -pageSize) + pageSize;
//    cout << "At " << __WHERE__ << " pageEnd = " << hex << pageEnd << dec << "\r" << endl;
    while (gLimit != pageEnd)
    {   gFringe = gLimit + reinterpret_cast<Chunk *>(gLimit)->length;
        gLimit = reinterpret_cast<uintptr_t>(
            reinterpret_cast<Chunk *>(gLimit)->pinChain.load());
//        cout << "At " << __WHERE__ << " gLimit = " << hex << gLimit << dec << "\r" << endl;
        if (gLimit == 0) gLimit = pageEnd;
//        cout << "At " << __WHERE__ << " gLimit = " << hex << gLimit << dec << "\r" << endl;
        size_t gap1 = gLimit - gFringe;
        myChunkBase[i]->chunkFringe = fringeBis[i];
        if (n+targetChunkSize < gap1)
        {   Chunk *c = reinterpret_cast<Chunk *>(gFringe.load());
            c->length = n + targetChunkSize;
            c->isPinned = false;
            size_t chunkNo = currentPage->chunkCount.fetch_add(1);
            currentPage->chunkMap[chunkNo].store(c);
            myChunkBase[i] = c;
            result[i] = gFringe.load() + TAG_VECTOR;
            request[i] = 0;
            setHeaderWord(result[i]-TAG_VECTOR, n, TYPE_VEC32);
            fringeBis[i] = gFringe.load() + n;
//            cout << "At " << __WHERE__ << "fringeBis[" << i
//                 << " = " << hex << fringeBis[i] << dec << "\r" << endl;
            gFringe = limitBis[i] = limit[i] = fringeBis[i] + targetChunkSize;
            break;
        }
    }
// pendingCount will be a count of the requests NOT satisfied. So I increment
// it if I do not manage to make an allocation.
    if (request[i] != 0) pendingCount++;
}

inline void tryToSatisfyAtLeastOneThread(unsigned int &pendingCount)
{   for (unsigned int i=0; i<maxThreads; i++)
    {   size_t n = request[i];
// Check if request (i) can be satisfied trivially. First I try within
// its current chunk, because the garbage collection may have been triggered
// by some other thread and the chunk for (i) may have plenty of space left.
        if (n != 0)
        {
// Thread i may not be making a request, either because it participated in
// this GC because of poll() not allocation or because somehow I have already
// managed to satisfy the request it make, and result[i] contains a reference
// to the memory block it needs.
            uintptr_t f = fringeBis[i];
            uintptr_t l = limitBis[i];
//            cout << "At " << __WHERE__ << " fringeBis[" << i
//                 << "] = " << hex << f << "and l = " << l << dec << "\r" << endl;
            size_t gap = l - f;
            if (n <= gap) fitsWithinExistingGap(i, n, gap);
            else
            {   size_t gap1 = gLimit - gFringe;
// If the current chunk for (i) is full I will see if I can allocate another
// one. This can be possible if GC was triggered by another thread that was
// trying to allocate a huge object - so huge that it would have pushed
// gFringe beyong gLimit but this thread is making a simple request such
// that a more or less standard sized chunk will suffice.
                if (n+targetChunkSize < gap1)
                    ableToAllocateNewChunk(i, n, gap);
                else regionInPageIsFull(i, n, gap, pendingCount);
            }
        }
    }
}

inline void grabNewCurrentPage(bool preferMostlyFree)
{   if (preferMostlyFree && mostlyFreePages != nullptr)
    {   currentPage = mostlyFreePages;
        mostlyFreePages = mostlyFreePages->chain;
        mostlyFreePagesCount--;
    }
    else if (freePages != nullptr)
    {   currentPage = freePages;
        freePages = freePages->chain;
        freePagesCount--;
    }
    else
    {   currentPage = mostlyFreePages;
        my_assert(currentPage != nullptr,
            [&]{ cout << "Utterly out of memory" << "\r" << endl;
                 std::exit(99); });
        mostlyFreePages = mostlyFreePages->chain;
        mostlyFreePagesCount--;
    }
    currentPage->pageClass = busyPageTag;
    currentPage->chain = busyPages;
    busyPages = currentPage;
    busyPagesCount++;
// I require that the fringe and limit values stored with a page refer to
// the first available block allowing for any pinned chunks within the page.
    gFringe = currentPage->fringe.load();
    gLimit = currentPage->limit;
//  cout << "At " << __WHERE__ << " gFringe = " << hex << gFringe << dec << "\r" << endl;
//  cout << "At " << __WHERE__ << " gLimit = " << hex << gLimit << dec << "\r" << endl;
// Every thread will now need to grab its own fresh chunk!
    for (unsigned int k=0; k<maxThreads; k++)
        limit[k] = fringeBis[k] = limitBis[k] = gFringe;
//  cout << "At " << __WHERE__
//  << " fringeBis[k] = limitBis[k] = gFringe = "
//  << hex << gFringe << dec << "\r" << endl;
//  cout << "@@ just allocated a fresh page\r\n";
}

extern bool withinMajorGarbageCollection;

extern LispObject Lgctest_0(LispObject);
extern LispObject Lgctest_1(LispObject, LispObject);
extern LispObject Lgctest_2(LispObject, LispObject, LispObject);

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

inline LispObject list2starrev(LispObject c, LispObject b,
                               LispObject a)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c,
                            LispObject d)
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

inline LispObject list4(LispObject a, LispObject b, LispObject c,
                        LispObject d)
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

inline LispObject acons_no_gc(LispObject a, LispObject b,
                              LispObject c)
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

// Entry to a garbage collector.

extern void garbageCollect();

void allocate_segment(size_t n);
extern void clearPinnedMap(Page *x);
extern uint64_t threadBit(unsigned int n);
extern bool isPinned(Page *x, uintptr_t p);   // test if pin bit set
extern void setPinned(Page *x,
                      uintptr_t p);  // just set mark in pinmap
extern void setPinnedMajor(uintptr_t p); // used during major GC
extern void setPinnedMinor(uintptr_t p); // used during minor GC

#define TL_borrowPages 52
DECLARE_THREAD_LOCAL(Page *, borrowPages);
#define TL_borrowFringe 53
DECLARE_THREAD_LOCAL(uintptr_t, borrowFringe);
#define TL_borrowLimit 54
DECLARE_THREAD_LOCAL(uintptr_t, borrowLimit);
#define TL_borrowNext 55
DECLARE_THREAD_LOCAL(uintptr_t, borrowNext);

class Borrowing
{
public:
    Borrowing()
    {   borrowPages = nullptr;
        borrowFringe = 0;
        borrowLimit = 0;
        borrowNext = 0;
    }
    ~Borrowing()
    {   std::lock_guard<std::mutex> lock(mutexForFreePages);
        while (static_cast<Page *>(borrowPages) != nullptr)
        {   if (static_cast<Page *>(borrowPages)->pageClass.load() == mostlyFreePageTag)
            {   Page *w = static_cast<Page *>(borrowPages)->chain;
                static_cast<Page *>(borrowPages)->chain = mostlyFreePages;
                mostlyFreePages = borrowPages;
                borrowPages = w;
            }
            else
            {   Page *w = static_cast<Page *>(borrowPages)->chain;
                static_cast<Page *>(borrowPages)->chain = freePages;
                freePages = borrowPages;
                borrowPages = w;
            }
        }
    }
};

#ifdef DEBUG

// The following is intended to help me check if allocation is going
// smoothly. It can be removed once debugging is complete (ha ha).

inline void testLayout()
{
    uintptr_t r = fringe;
    uintptr_t w = limit[threadId].load();
    my_assert(w==0 || r <= w, [] { cout << "fringe > limit\r\n"; });
    my_assert(w <= gFringe.load(), [] {cout << "limit > gFringe\r\n";});
    my_assert(gFringe.load() <= gLimit, [] {cout << "gFringe > gLimit\r\n";});
}

#endif // DEBUG

#endif // header_newallocate_h

// end of newallocate.h
