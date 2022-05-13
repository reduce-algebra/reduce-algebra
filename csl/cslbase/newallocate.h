// newallocate.h                          Copyright (C) Codemist, 2018-2022


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#include "log.h"
#include <cstring>
#include <csetjmp>


using std::hex;
using std::dec;

static const size_t pageSize = 8*1024*1024u;     // Use 8 Mbyte pages
static const size_t chunkSize = 16*1024u;        // 16 Kbyte chunks

extern bool allocateSegment(size_t);

enum PageType
{   emptyPageType,
    consPinPageType,
    vecPinPageType,
    consFullPageType,
    vecFullPageType
};

class Page;

extern Page* emptyPages;
extern Page* consPinPages;
extern Page* vecPinPages;
extern Page* oldConsPinPages;
extern Page* oldVecPinPages;
extern Page* consFullPages;
extern Page* vecFullPages;
extern Page* consOldPages;
extern Page* vecOldPages;
extern Page* consCurrent;
extern Page* vecCurrent;
extern Page* borrowPages;
extern Page* borrowCurrent;
extern Page* potentiallyPinned;
extern Page* pinnedPages;

extern Page* emptyPagesTail;
extern Page* consPinPagesTail;
extern Page* vecPinPagesTail;
extern Page* consFullPagesTail;
extern Page* vecFullPagesTail;
extern Page* borrowPagesTail;

extern size_t emptyPagesCount;
extern size_t consPinPagesCount;
extern size_t vecPinPagesCount;
extern size_t consFullPagesCount;
extern size_t vecFullPagesCount;
extern size_t borrowPagesCount;


class alignas(pageSize) Page
{
public:
// Define two structs used when setting out the rest of the
// layout. In many respects the most important thing about these is
// the alignment that they impose.
    struct alignas(2*sizeof(LispObject)) ConsCell
    {   LispObject car;
        LispObject cdr;
    };
    struct alignas(chunkSize) Chunk
    {   uintptr_t data[chunkSize/sizeof(uintptr_t)];
    };
    union
    {
// The sole purpose of the forceSize[] array is to ensure that the
// Page class ends up the size I want it to. The other entries in the
// union end up with arrays that are declared as having size 1 but which
// are in fact intended to span all the way up to pageSize
        char forceSize[pageSize];
        struct
        {
// There are some fields that every Page will have...
            PageType type;
            Page* chain;
            Page* oldPinnedPages;
            Page* pinnedPages;
            LispObject pinnedObjects;
            uintptr_t dataEnd;
// Now based on the "type" field I will have either a CONS page or
// a VEC page, and the union here defines how each is to be laid out. Note
// that the arrays consData[] and chunks[] are in fact expected to run
// out up to pageSize rather than being of length 1 as declared here...
// I can not see a tidy C++ way to make the length of each array what I
// want. Well I can do it using something like
//   consData[(pagesize - sizeof(PageType) - sizeof(Page*) - ...)/
//            sizeof(ConsCell)]
// but that becomes hideous to maintain and delicate as regards alignment.
// I might clean it up a bit by embedding the whole header in a further
// struct so I could use the size of that in my arithmetic, but it still
// feels uncomfortable!
            union
            {   struct
                {   uint64_t previousConsPins[pageSize/
                                              (2*sizeof(LispObject))/
                                              (8*sizeof(uint64_t))];
                    uint64_t currentConsPins[pageSize/
                                             (2*sizeof(LispObject))/
                                             (8*sizeof(uint64_t))];
                    ConsCell consData[1];
                };
                struct
                {   bool potentiallyPinnedFlag;
                    Page* potentiallyPinnedChain;
// I make chunkStatus an array of uint8_t values so that I understand
// its layout very clearly. The values stored will be:
//    0x00        first (or only) chunk in a Chunk. Or unused chunk.
//    0x01-0x7f   continuation chunks, where the count saturates at 07f.
//    0x80        first or only chunk in a pinned Chunk.
//    0x81-0xff   continuations of pinned Chunks.
                    uint8_t  chunkStatus[pageSize/chunkSize];
                    uint64_t potentiallyPinnedChunks[pageSize/
                                                     chunkSize/(8*sizeof(uint64_t))];
                    uint64_t previousVecPins[pageSize/8/(8*sizeof(uint64_t))];
                    uint64_t currentVecPins[pageSize/8/(8*sizeof(uint64_t))];
                    Chunk chunks[1];
                };
            };
        };
    };
};

inline bool isPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
    return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
    p->potentiallyPinnedChunks[chunkNo/84] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

inline bool isPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   p->potentiallyPinnedChunks[chunkNo/84] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

// Here p must be a CONS page and a a pointer within it.

inline bool consIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    return (p->currentConsPins[o/64] >> (o&63)) != 0;
}

inline bool consIsPreviousPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    return (p->previousConsPins[o/64] >> (o&63)) != 0;
}

inline void consSetPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    p->currentConsPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void consClearPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    p->currentConsPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}

// And versions for VEC pages, which pin with granularity a single
// LispObject, so the bitmaps are twice as large as the ones for CONS pages
// where granularity only needs to be the size of a pair of adjacent
// objects.

inline bool vecIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    return (p->currentVecPins[o/64] >> (o&63)) != 0;
}

inline bool vecIsPreviousPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    return (p->previousVecPins[o/64] >> (o&63)) != 0;
}

inline void vecSetPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    p->currentVecPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void vecClearPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    p->currentVecPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}


// Set up the given Page as one for use with CONS supposing it is
// totally free to start with. This sets up global fringe and limit pointers.

extern uintptr_t consFringe, consLimit, consEnd;

inline void initConsPage(Page* p)
{   p->type = consFullPageType;
    p->pinnedObjects = TAG_FIXNUM;
    std::memset(p->previousConsPins, 0, sizeof(p->previousConsPins));
    std::memset(p->currentConsPins, 0, sizeof(p->currentConsPins));
    consFringe = reinterpret_cast<uintptr_t>(&p->consData);
    consLimit = consEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    consCurrent = p;
}

inline void pageAppend(Page* p, Page*& list, Page*& tail, size_t& count)
{   p->chain = nullptr;
    if (count == 0)
    {   list = tail = p;
        count = 1;
    }
    else
    {   tail->chain = p;
        tail = p;
        count++;
    }
}

extern uintptr_t consEndOfPage();
extern uintptr_t doubleConsEndOfPage();
extern uintptr_t consGCEndOfPage();
extern void garbage_collect();

inline uintptr_t harderGCGet2Words()
{
// Here consFringe == consLimit. One possibility is tha this is because
// consLimit points at a pinned item, and there could of course be
// several consecutive pinned things. And in a bad case that could
// extend so that the very last location in the Page was pinned. Another
// possibility is that consLimit==consEnd so the Page is already all used up.
// The loop here skips over pinned stuff.
    while (consFringe < consEnd &&
           consIsPinned(consFringe, consCurrent))
        consFringe += 2*sizeof(LispObject);
// Now if the Page is full I need to try to allocate another, and if that
// does not make sense I will have to garbage collect.
    if (consFringe == consEnd) return consGCEndOfPage();
// When I skip pinned data and if there is space beyond same then the first
// word of that region holds a padder header that lets me know where the
// next usable section of memory ends.
    consLimit = consFringe +
        length_of_header(*reinterpret_cast<Header*>(consFringe));
// Now I can allocate.
    uintptr_t r = consFringe;
    consFringe += 2*sizeof(LispObject);
    return r;
}

// This is the main function for allocating CONS cells and any
// other item that only use up 2 cells. I hope it will often have
// calls to it expanded inline.

inline uintptr_t GCGet2Words()
{   uintptr_t r = consFringe;
    if (r != consLimit)
    {   consFringe += 2*sizeof(LispObject);
        return r;
    }
    return harderGCGet2Words();
}

// It may be that allocating two CONS cells at a time can save a little
// bit of overhead... If there are not two consecutive units of memory
// immediately available it will leave a gap. In case there is ever a
// linear scan of the memory it will put in a padder.

inline Header makeHeader(size_t n, int type)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + type;
}

// At times I want to put a vector header at the start of a block of
// memory. This does the job. Note that a is an untagged pointer here.

inline void setHeaderWord(uintptr_t a, size_t n, int type=TYPE_PADDER)
{   *reinterpret_cast<uintptr_t*>(a) = makeHeader(n, type);
}

extern uintptr_t vecFringe, vecLimit, vecEnd;

inline void initVecPage(Page* p)
{   p->type = vecFullPageType;
    p->potentiallyPinnedFlag = false;
    p->potentiallyPinnedChain = nullptr;
    std::memset(p->previousVecPins, 0, sizeof(p->previousVecPins));
    std::memset(p->currentVecPins, 0, sizeof(p->currentVecPins));
    std::memset(p->chunkStatus, 0, sizeof(p->chunkStatus));
    std::memset(p->potentiallyPinnedChunks, 0,
                sizeof(p->potentiallyPinnedChunks));
    vecFringe = reinterpret_cast<uintptr_t>(&p->chunks);
    vecLimit = vecEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    vecCurrent = p;
}

extern uintptr_t vecEndOfPage(size_t n);
extern uintptr_t vecGCEndOfPage(size_t n);

inline uintptr_t harderGCGetNBytes(size_t n)
// Write in a padder item (if necessary) so that the current chunk is
// properly filled up.
{   if (vecFringe != vecLimit)
        setHeaderWord(vecFringe, vecLimit-vecFringe);
    size_t chunkNo = (vecFringe -
                      reinterpret_cast<uintptr_t>(vecCurrent))/chunkSize;
    while (vecFringe < vecEnd &&
           (vecCurrent->chunkStatus[chunkNo] & 0x80) != 0)
    {   vecFringe += chunkSize;
        chunkNo++;
    }
#pragma message "improper treatment of vectors over 16KB"
// here I need code akin to that in harderGetNBytes that sets
// sequence numbers into chunkStatus. Well what I actually do at
// is I waste all the space in a Page when a request will not fit in
// easily. I think this may be valid but just wasteful.
    return vecGCEndOfPage(n);
}

// This allocates from the vector-heap. It would not be essential to
// detect and take special action on two-word requests, but I think the
// cost will be low and the effect will be to make things just a bit tidier.
// Again the case I hope will be common is cheap and may well get compiled
// inline.

inline uintptr_t GCGetNBytes(size_t n)
{   if (n == 2*sizeof(LispObject)) return GCGet2Words();
    uintptr_t r = vecFringe;
    size_t gap = vecLimit - r;
    if (n <= gap)
    {   vecFringe += n;
        return r;
    }
    return harderGCGetNBytes(n);
}

// This is the main function for allocating CONS cells and any
// other item that only use up 2 cells. I hope it will often have
// calls to it expanded inline.

inline uintptr_t get2Words()
{   uintptr_t r = consFringe;
    if (r != consLimit)
    {   consFringe += 2*sizeof(LispObject);
        return r;
    }
    return consEndOfPage();
}

inline uintptr_t get4Words()
{   uintptr_t r = consFringe;
    size_t gap = consLimit - consFringe;
    if (gap >= 4*sizeof(LispObject))         // The simple case!
    {   consFringe += 4*sizeof(LispObject);
        return r;
    }
    else if (gap != 0)
    {   setHeaderWord(consFringe, 2*sizeof(LispObject));
        consFringe += 2*sizeof(LispObject);
    }
    return doubleConsEndOfPage();
}

extern uintptr_t vecFringe, vecLimit, vecEnd;

extern uintptr_t vecEndOfPage(size_t n);

inline uintptr_t harderGetNBytes(size_t n)
// Write in a padder item (if necessary) so that the current chunk is
// properly filled up.
{   setHeaderWord(vecFringe, vecLimit-vecFringe);
// Here the requested vector will not fit in the existing chunk, so
// a few one will need to be allocated. Well it is much worse than that!
// First the request may be for a vector that will not fit into a single
// chunk, so then extension chunks will be needed to build up a Chunk.
// That that may or may not fit within the current Page, and if the Page
// gets filled I will need to allocate another. The key thing I need
// to do is to fill in the chunkStatus information in the page to track
// those composite Chunks.
    size_t free = vecEnd-vecLimit;
    if (n <= free)       // Can fit in one or more chunks within current Page
    {   uintptr_t r = vecLimit;
        vecFringe = r + n;
        size_t chunkNo =
            (r - reinterpret_cast<uintptr_t>(vecCurrent))/chunkSize;
        unsigned int seq = 0;
// Deal with all the chunks that end up totally full. Note that chunk
// sequence numbers saturate at 0x7f.
        while (n > chunkSize)
        {   vecCurrent->chunkStatus[chunkNo++] = seq;
            if (seq < 0x7f) seq++;
            vecLimit += chunkSize;
            n -= chunkSize;
        }
// Now set up the last (or the only) chunk.
        vecCurrent->chunkStatus[chunkNo++] = seq;
        vecLimit += chunkSize;
        return r;
    }
    return vecEndOfPage(n);
}

// This allocates from the vector-heap. It would not be essential to
// detect and take special action on two-word requests, but I think the
// cost will be low and the effect will be to make things just a bit tidier.
// Again the case I hope will be common is cheap and may well get compiled
// inline.

inline uintptr_t getNBytes(size_t n)
{   if (n == 2*sizeof(LispObject)) return get2Words();
    uintptr_t r = vecFringe;
    size_t gap = vecLimit - r;
    if (n <= gap)
    {   vecFringe += n;
        return r;
    }
    return harderGetNBytes(n);
}

// "Borrowing" is a concept I introduce here. Its key use is when a hash
// table needs to be re-hashed. A requirement here is that garbage
// collection can not be triggered while borrowing is active.
// The idea is that apart from when garbage collection is happening
// around half of all memory is unused - when a GC starts it will be
// treated as the "new space" into which live data will be copied.
// Between garbage collections I allow myself to allocate from it
// on a strictly temporary basis. I only ever need to store vectors
// in it, so the logic here closely follow that for the normal
// allocation of vectors. Its use for hash tables is that a copy
// of all the data in a table can be made in "borrowed" space. The
// original table can then be cleared and everything re-hashed back
// into it. When that has been done the borrowed memory can be
// released.

extern Page* pageFringe;

extern unsigned int borrowingDepth;
extern uintptr_t borrowFringe, borrowEnd;

class Borrowing
{
    Page* save;
public:
    Borrowing()
    {   if (borrowingDepth++ == 0)
        {   save = pageFringe;
        }
    }
    ~Borrowing()
    {   if (--borrowingDepth == 0)
        {   while (borrowPages != nullptr)
            {   Page* p = borrowPages;
                borrowPages = p->chain;
                p->chain = emptyPages;
                emptyPages = p;
            }
            borrowCurrent = nullptr;
            borrowFringe = borrowEnd = 0;
            pageFringe = save;
        }
    }
};

inline void initBorrowPage(Page* p)
{
// borrowed pages do not need any magic structures set up in them beyond
// the fringe and end pointers, because they will never be active at GC time. 
    borrowFringe = reinterpret_cast<uintptr_t>(&p->chunks);
    borrowEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    borrowCurrent = p;
}

extern uintptr_t borrowEndOfPage(size_t n);

// Borrowed pages are never in use during garbage collection, and so
// I do not need to worry about chunks or padders or anything. I can
// allocate big vectors right up to their end.

inline uintptr_t borrowNBytes(size_t n)
{   uintptr_t r = borrowFringe;
    size_t gap = borrowEnd - r;
    if (n <= gap)
    {   borrowFringe += n;
        return r;
    }
    return borrowEndOfPage(n);
}

inline void poll()
{
}

extern Page* grabFreshPage();

// Now for higher level code that performs Lisp-specific allocation.

inline LispObject cons(LispObject a, LispObject b)
{   LispObject r = get2Words() + TAG_CONS;
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
{   LispObject r = get2Words() + TAG_CONS;
    setcar(r,  a);
    setcdr(r,  nil);
    return r;
}


inline LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, nil);
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b,
                               LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c,
                            LispObject d)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
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
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    LispObject r4 = get2Words() + TAG_CONS;
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
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
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
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, b);
    return onevalue(r1);
}

inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, b);
    setcdr(r1, a);
    return onevalue(r1);
}

inline LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

inline LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, nil);
    return onevalue(r1);
}

extern LispObject Lgctest_0(LispObject);
extern LispObject Lgctest_1(LispObject, LispObject);
extern LispObject Lgctest_2(LispObject, LispObject, LispObject);
extern void gcTestCode(); // temporary and for debugging.

// For up to 16 segments I have...
//   heapSegmentCount   number of allocated segments
//   heapSegment[i]      base address of a segment of memory
//   heapSegmentSize[i] size of useful part of that segment, in bytes
//   heapSegmentTotalSize[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

extern void* heapSegment[16];
extern char* heapSegmentBase[16];
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

// If I print addresses "naturally" I tend to get huge numbers with lots of
// leading digits - especially on a 64-bit system. This little function
// maps addresses to offsets within their heap segment. It is not really going
// to help a huge amount of you have multiple segments each full with
// gigabytes of data, but may ease early debugging on small cases quite
// a lot!
// If a value p is an address within the data region of a Page then
// the display will be of the form "#pagenumber:offset" if in the first
// heapsegment and "#segment:pagenumber:offset" otherwise. An offset
// of zero should correspond to the start of the first Chunk within the Page,
// and so the first bit of allocated user data lies (on a 64-bit machine)
// at address #0:30 because of the size of the Chunk header.

extern LispObject nil;

inline const char* Addr(uintptr_t p)
{
// This function may be called several times in a single expression. I
// do not want it to have to allocate fresh memory, so I set it up with
// four (4) buffers and use those in turn. 
    static char rr[4*40];
    static int seq=0;
    char* r = &rr[40*(seq++ & 0x3)];
    if (p == static_cast<uintptr_t>(nil))
    {   std::strcpy(r, "nil");
        return r;
    }
    else if (p == 0U)
    {   std::strcpy(r, "zero");
        return r;
    }
    int hs = findHeapSegment(p);
    if (hs != -1)
    {   uintptr_t segBase = reinterpret_cast<uintptr_t>(heapSegment[hs]);
        uintptr_t o = p - segBase;
        uintptr_t pNum = o/pageSize;
        Page* pp = reinterpret_cast<Page*>(segBase + pNum*pageSize); 
        uintptr_t pOff = o%pageSize;
        if ((pp->type==consPinPageType || pp->type==consFullPageType) &&
            pOff >= offsetof(Page, consData))
        {   pOff -= offsetof(Page, consData);
            if (hs == 0) std::snprintf(r, 40,
                "#%" PRIxPTR ":%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 40,
                "#[%d]: %" PRIxPTR ":%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if ((pp->type==vecPinPageType || pp->type==vecFullPageType) &&
                 pOff >= offsetof(Page, chunks))
        {   pOff -= offsetof(Page, chunks);
            if (hs == 0) std::snprintf(r, 40,
                "#%" PRIxPTR "::%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 40,
                "#[%d]: %" PRIxPTR "::%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pOff == 0)
        {   if (hs == 0) std::snprintf(r, 40, "#%" PRIxPTR ":", pNum);
            else std::snprintf(r, 40, "#[%d]: %" PRIxPTR ":", hs, pNum);
            return r;
        }
    }
    bool maybeChars = true;
    for (uintptr_t w=p; w!=0; w=w>>8)
    {   int c = w & 0xff;
        if (c < ' ' || c >= 0x7f) maybeChars = false;
    }
    if (maybeChars && p!=0)
    {   std::snprintf(r, 40, "%#" PRIxPTR "/%" PRIdPTR, p, p);
        size_t q = strlen(r);
        r[q++] = '/';
        r[q++] = '"';
        while (p != 0)
        {   r[q++] = p & 0xff;
            p = p>>8;
        }
        r[q++] = '"';
        r[q] = 0;
    }
    else std::snprintf(r, 40, "%#" PRIxPTR "/%" PRIdPTR, p, p);
    return r;
}

template <typename T>
inline const char* Addr(T p)
{   return Addr((uintptr_t)p);
}

// If Addr(n) yields #p:o then unAddr(p,o) should return n, however the code
// here does not achieve this because Addr subtracts the start address of
// data within a Page!

inline uintptr_t unAddr(uintptr_t p, uintptr_t o)
{    return reinterpret_cast<uintptr_t>(heapSegment[0]) + pageSize*p + o;
}

// .. and extra for the case of addresses in segments 1 and beyond.

inline uintptr_t unAddr(unsigned int s, uintptr_t p, uintptr_t o)
{    return reinterpret_cast<uintptr_t>(heapSegment[s]) + pageSize*p + o;
}

// This finds a page that a potential pointer p is within, or returns nullptr
// if there is not one

inline Page* findPage(uintptr_t p)
{   int n = findHeapSegment(p);
    if (n < 0) return nullptr;
    return reinterpret_cast<Page*>(p & -pageSize);
}

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. This must NEVER be called
// with a zero argument. Also note that this function is also defined
// in arithlib.hpp, but since it is "inline" there is not need to worry
// about having multiple definitions, although it will be best if they
// all match.

// Count the leading zeros in a 64-bit word.

inline int nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

// Count the trailing zeros in a 64-bit word.

inline int ntz(uint64_t x)
{   return __builtin_ctzll(x);  // Must use the 64-bit version.
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n + 32;
        x = x << 32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n + 16;
        x = x << 16;
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

// This code is to identify the least significant bit in a 64-bit
// value. The function leastBit() just removes all other bits. It is probably
// not going to be used a lot.

uint64_t leastBit(uint64_t n)
{   return n & (-n);
}

// ntz find the bit-number of the least significant bit, So here are some
// values it will return:
//    1      0
//    2      1
//    4      2
//    8      3
//   16      4
// etc. The name is for "Number of Trailing Zeros".
// If the input value is zero it returns -1, but the GNU builting does not
// guarantee any such behaviour, so zero input should be considered illegal.

int ntz(uint64_t n)
{   static int8_t lsbTable[67] =
    {  -1,   0,   1,  39,   2,  15,  40,  23,   3,  12,
       16,  59,  41,  19,  24,  54,   4,  -1,  13,  10,
       17,  62,  60,  28,  42,  30,  20,  51,  25,  44,
       55,  47,   5,  32,  -1,  38,  14,  22,  11,  58,
       18,  53,  63,   9,  61,  27,  29,  50,  43,  46,
       31,  37,  21,  57,  52,   8,  26,  49,  45,  36,
       56,   7,  48,  35,   6,  34,  33,  -1
    };
    else return lsbTable[leastBit(n) % 67];
}

#endif // __GNUC__
#define NLZ_DEFINED 1
#define NTZ_DEFINED 1



#if 0 ///////////////////////////////////////////////@@@@@@@@@@@@@@@@@@@@@
//~ 
//~ extern uintptr_t              fringe;
//~ extern uintptr_t              limit;
//~ extern Chunk*                 currentChunk;
//~ extern uintptr_t              limitBis;
//~ extern uintptr_t              fringeBis;
//~ extern size_t                 request;
//~ extern LispObject             result;
//~ extern size_t                 gIncrement;
//~
//~ extern uintptr_t              gFringe;
//~ extern uintptr_t              gLimit;
//~
//~ // With the scheme I have here when an 8 Mbyte page gets full all of it
//~ // will be scheduled for evacuation (ie garbage collection). In the extreme
//~ // case that I had 64 active threads but only one was performing allocation
//~ // that would leave 63 chunks within the page essentially empty - that is
//~ // about 1 Mbyte. Is (1/8) of the page is not used. That is not a disaster!
//~ // In the more plausible case of say 8 threads the overhead decreases to a
//~ // level where I really stop worrying.
//~ // Well if needbe I could try being clever and allocating each thread chunks
//~ // whose size was sensitive to their history of allocation, so that
//~ // threads that were almost always dormant or which hardly did any allocation
//~ // got much smaller chunks. At the very very least to do anything like that
//~ // now would be premature!
//~
//~ // When I need to trigger or participate in a garbage collection I
//~ // call difficult_n_bytes() with an argument that is the amount of memory I
//~ // am wanting to allocate. That is allowed to be zero (for instance when
//~ // I am just polling). It will return a pointer to an allocated block, and
//~ // set fringe, limit etc to reflect the allocation performed. Within it
//~ // it may have to try several times: the fundamental version guarantees to
//~ // achieve allocation for at least one of the threads (and that thread will
//~ // continue and only join in with subsequent collections later on).
//~ // Note that limit[] can be forced to zero as a call to difficult_allocate
//~ // is exiting.
//~
//~ enum GcStyle
//~ {
//~     GcStyleNone,
//~     GcStyleMinor,
//~     GcStyleMajor
//~ };
//~
//~ extern GcStyle userGcRequest;
//~
//~ extern uintptr_t difficult_n_bytes();
//~
//~ // This is the core part of CONS and also of the code that allocates
//~ // bignums, strings and vectors.
//~
//~
//~ #ifdef DEBUG
//~ extern void testLayout();
//~ #endif // DEBUG
//~
//~ #ifdef DEBUG
//~ namespace REAL
//~ {
//~ #endif // DEBUG
//~
//~ inline LispObject get_n_bytes(size_t n, uintptr_t r, uintptr_t w)
//~ {
//~ // The new block I need to allocate really will not fit in the current
//~ // chunk.
//~ // I may in fact be able to make this allocation simply by grabbing a
//~ // fresh chunk. I need to record the end-point within this Chunk...
//~ // I want to make every chunk "tidy" because when I have one that gets
//~ // pinned I will need to make a linear scan of it treating every pointer
//~ // field within it as an unambiguous list-base. Any uninitialized or otherwise
//~ // wild regions within it could cause disaster! I do this by recording its
//~ // high water mark.
//~     if (w != 0)
//~     {
//~ // I now need to allocate a new chunk. gFringe and gLimit delimit a region
//~ // within of size PAGE (perhaps 8 Mbytes) and I will start by allocating
//~ // chunks sequentially within that page. By making gFringe atomic I can so
//~ // this in a lock-free manner.
//~ // I will make my next chunk big enough for the current allocation request
//~ // with targetChunkSize left over after that. This ensures that even big
//~ // vector requests can be satisfied.
//~         uintptr_t oldFringe = r;
//~         Chunk* newChunk = reinterpret_cast<Chunk*>(gFringe);
//~         gFringe += targetChunkSize+n;
//~         r = newChunk->dataStart(); // safe even if chunk pointer is bad!
//~ // Be aware that other threads might be doing (atomic) increments on gFringe
//~ // at the same time that this one does. They will each reserve separate
//~ // new chunks, but some of these may fall in memory well above gLimit. And
//~ // hence they could be beyond the end of the current Page.
//~ // I am going to assume (ha ha) that even if the maximum number of threads
//~ // each increment gFringe by the largest possible amount then it will not
//~ // suffer arithmetic overflow. If I have a maximum of 16 threads then I ought
//~ // to ensure that gLimit+130M > gLimit.
//~         fringe = r + n;
//~ // I can not use newChunk->dataEnd() on the next line because the chunk does
//~ // not yet have its length field filled in. And that has to be the case
//~ // because the region I have set aside for this Chunk may be beyond the end
//~ // of the current Page (or the next pinned place within the Page).
//~         uint64_t newLimit =
//~             reinterpret_cast<uintptr_t>(newChunk) + targetChunkSize+n;
//~ // Possibly the allocation of the new chunk ran beyond the current page
//~ // and that will be cause to consider triggering garbage collection. If the
//~ // chunk size is 16K and the page size 8M it will take 512 chunk allocations
//~ // before a page is filled. If for now I suppose that having 16 threads all
//~ // allocating cons cells furiously is an extreme case then that will mean
//~ // that each thread gets through 32 chunks before the extra (probably severe)
//~ // costs of page allocation arise. So this is about 1 in 32000 conses in the
//~ // heaviest multi-thread case and only 1 in 0.5 million in a single thread
//~ // scenario.
//~ //
//~ // I want to identify the Page that I am currently allocating within. In an
//~ // earlier draft I masked newChunk with -pageSize. However newChunk could
//~ // be well above the end of valid allocation space in the current page and
//~ // might in fact be within the next sequential page. So rather than that I
//~ // use oldFringe-1. The "-1" is because maybe the previous fringe had
//~ // ended up such that the previously allocated item had totally filled the
//~ // Chunk and Page, so it points at the location just beyond the Page end.
//~         Page* p = reinterpret_cast<Page*>((oldFringe-1) & -pageSize);
//~         if (newLimit <= gLimit)
//~         {
//~ // Now my allocation of a new chunk has been successful. Before I test if
//~ // participation in a garbage collection on behalf of some other thread
//~ // is required I need to record this chunk in the table of chunks that
//~ // the page maintains. I also need to fill in the chunk header -- well the
//~ // pinChain pointer does not need initializing until and unless the page
//~ // gets pinned, but the isPinned flag must start off false so that when the
//~ // GC finds an ambiguous pointer within this chunk it knows when that is the
//~ // first such.
//~             currentChunk = newChunk;
//~             newChunk->length = targetChunkSize+n;
//~             newChunk->isPinned = false;
//~             newChunk->evacuated = false;
//~             newChunk->pinnedObjects = TAG_FIXNUM;
//~             newChunk->chunkPinChain = nullptr;
//~             size_t chunkNo = p->chunkCount++;
//~ //#         zprintf("allocation in page %a increments chunkCount to %d\n",
//~ //#                 p, p->chunkCount);
//~             p->chunkMap[chunkNo] = newChunk;
//~             limitBis = newLimit;
//~ #ifdef NO_THREADS
//~             limit = newLimit;
//~             zprintf("limit = %a\n", limit);
//~             bool ok = true;
//~ #else // NO_THREADS
//~ // I wish to write back limit but it is possible that in
//~ // the meanwhile somebody set that to zero, so I need to be a bit careful.
//~ // Specifically I will only write back the new limit if the old one was
//~ // still in force.
//~ //
//~ // Here I have (successfully) allocated a new chunk, and I have set my
//~ // fringe to point within it. Because limit can be arbitrarily clobbered
//~ // by others I will only update it if it has not changed since I loaded
//~ // it earlier. If it has changed it will have been set to zero and I
//~ // must participate in a GC.
//~             bool ok = limit.compare_exchange_strong(w, newLimit);
//~ #endif // NO_THREADS
//~ #ifdef DEBUG
//~             if (ok) testLayout();
//~ #endif // DEBUG
//~             if (ok) return static_cast<LispObject>(r);
//~         }
//~         gIncrement = targetChunkSize+n;
//~         fringe = oldFringe;
//~ //      zprintf("At %s fringe set to oldFringe = %a\n", __WHERE__, oldFringe);
//~     }
//~     else
//~     {
//~ // Here I am about to be forced to participate in garbage collection,
//~ // typically for the benefit of some other thread.
//~         if (gcTrace) zprintf("GC triggered\n");
//~         if (currentChunk != nullptr)
//~             currentChunk->chunkFringe = r;
//~         gIncrement = 0;
//~         fringe = r;
//~ //      zprintf("At %s fringe set to %a\n", __WHERE__, r);
//~     }
//~     THREADID;
//~     fringeBis = fringe;
//~ //# zprintf("At %s fringeBis[%d] = %a\n", __WHERE__, threadId, fringeBis);
//~     request = n;
//~ // Here I can not complete the work with this inline function because
//~ // either I have run out of space for a new chunk or because some
//~ // other thread had done that and had set my limit register to zero
//~ // to tell me. I set fringe back to the value that it had on entry,
//~ // so the situation when I call difficult_n_bytes() is just as if it had
//~ // been called directly from the main program save that gFringe may have
//~ // been incremented - possibly beyond gLimit.
//~     r = difficult_n_bytes();
//~     my_assert(is_cons(r), "difficult_n_bytes should return a CONS");
//~     return static_cast<LispObject>(r);
//~ }
//~
//~ inline LispObject get_n_bytes(size_t n)
//~ {
//~ // The size passed here MUST be a multiple of 8.
//~ // I have a thread-local variable fringe, and limit is in effect
//~ // thread-local. These delimit a region of size about targetChunkSize
//~ // within which allocation can be especially cheap. limit is atomic and
//~ // that indicates that other threads may access it. In particular another
//~ // thread can set it to zero to cause this thread to synchronize with
//~ // others to participate in garbage collection. Because on some platforms
//~ // access to thread-locals is more expensive than use of simple variables
//~ // or is even achieved via strange C++ trickery, I isolate loading and
//~ // storing such values into simple statements that transfer values to
//~ // local variables.
//~     THREADID;
//~     uintptr_t r = fringe;
//~     uintptr_t fr1 = r + n;
//~     fringe = fr1;
//~     uintptr_t w = limit;
//~ // The simple case completes here. If each chunk is around 16K then only 1
//~ // CONS in 1000 or so will take the longer route. I rather hope that the
//~ // common case will be lifted to be rendered in-line.
//~     if (fr1 <= w) LIKELY
//~     {
//~ #ifdef DEBUG
//~         testLayout();
//~ //      if (gcTrace) zprintf("get_n_bytes(%d) = %a\n", n, r);
//~ #endif // DEBUG
//~         return static_cast<LispObject>(r);
//~     }
//~     UNLIKELY return get_n_bytes(n, THREADARG r, w);
//~ }
//~
//~ #ifdef DEBUG
//~ } // end of namespace
//~
//~ inline size_t get_size[8];
//~ inline unsigned int get_count = 0;
//~ inline unsigned int get_trace = 0x7fffffff; // 514572-10;
//~
//~ inline LispObject previousCons = 0;
//~
//~ inline LispObject get_n_bytes(size_t n)
//~ {   LispObject r = REAL::get_n_bytes(n);
//~ //# zprintf("get_n_bytes %d => %a\n", n, r);
//~ // The following assertion may sometimes be violated maybe. Eg if a large
//~ // [vector] request causes a new Chunk to be allocated, but after that
//~ // a smaller object fits into the end of the existing Chunk.
//~ //  my_assert(r > previousCons, []{zprintf("non-increasing allocation\n"); });
//~     previousCons = r;
//~     return r;
//~ }
//~
//~ #endif // DEBUG
//~
//~
//~ // It will be important to poll frequently because when one thread
//~ // observes that it needs to garbage collect all other threads must be
//~ // paused. Any other that calls cons() or getvec() will pause there, but
//~ // code in a loop that did not allocate memory could cause an unbounded
//~ // delay unless this is called such that the loop can be interrupted.
//~ // Extra steps will be needed when library calls that might block are
//~ // made, but details of that belong elsewhere.
//~
//~ inline void poll()
//~ {   uintptr_t w;
//~     THREADID;
//~     if (fringe > (w = limit))
//~     {
//~ // Here I need to set everything up just as if I had been making an
//~ // allocation request for zero bytes.
//~         fringeBis = fringe;
//~ //#     zprintf("Polling at %s fringeBis[%d] = %a\n",
//~ //#             __WHERE__, threadId, fringeBis);
//~         request = 0;
//~         gIncrement = 0;
//~         static_cast<void>(difficult_n_bytes());
//~     }
//~ }
//~
//~ // The following can be used as in
//~ //   withRecordedStack([&]{ ... });
//~ // where the "..." represents some actions. Its job is to arrange that
//~ // the C stack has all local values on (in particular that nothing is
//~ // referenced solely via machine registers) and that a stackFringe variable
//~ // is set so that the garbage collector can do its job properly.
//~
//~
//~
//~
//~ extern std::mutex mutexForGc;
//~ extern std::mutex mutexForFreePages;
//~ extern bool gc_started;
//~ extern bool gc_complete;
//~ extern std::condition_variable cv_for_gc_idling;
//~ extern std::condition_variable cv_for_gc_busy;
//~ extern std::condition_variable cvForChunkStack;
//~ extern std::condition_variable cvForCopying;
//~ extern std::condition_variable cv_for_gc_complete;
//~
//~ // I am going to put the code that synchronizes threads for garbage
//~ // collection here as an inline function mainly so that the code is
//~ // present close to the procedures that call it - they have to cooperate
//~ // in a way that feels delicate enough that having them in separate files
//~ // would increase the risk of confusion.
//~
//~ extern uint32_t activeThreads;
//~ inline uint32_t FactiveThreads() { return activeThreads; }
//~
//~ //  0x00 : total_threads : lisp_threads : still_busy_threads
//~ //
//~ // The meaning of all those is as follows:
//~ //   total_threads: Count of all the threads that CSL has started and that
//~ //                  might ever participate as Lisp mutators.
//~ //   lisp_threads:  The number of threads that are at present running as
//~ //                  Lisp mutators. This can be less than total_threads
//~ //                  because if a thread is about to perform a (potentially)
//~ //                  blocking system call it must decrease thsi count. All
//~ //                  threads included in this count thereby guarantee that they
//~ //                  will either allocate memory or perform a polling operation
//~ //                  fairly soon.
//~ //   still_busy_threads: Used during synchronization at the start and end of
//~ //                  garbage collection. Specifically as threads poll and
//~ //                  discover that a garbage collection is pending they
//~ //                  decrement this field. When it reaches zero that indicates
//~ //                  that all (lisp) threads have become quiescent, and so
//~ //                  global action can start.
//~ // There can be delicacies involved in updating all these! In particular
//~ // starting or terminating a thread while all others are in the process
//~ // of synchronizing for or after garbage collection is something that will
//~ // involve some care!
//~
//~ extern unsigned int activeHelpers;
//~
//~ extern bool generationalGarbageCollection;
//~ extern void generationalGarbageCollect();
//~ extern void fullGarbageCollect();
//~
//~ // I have multiple threads, and when a GC is needed they need to synchronize.
//~ // My plan is that one thread is selected as the key one, with that
//~ // being the last one to decrement an "activeThreads" counter. By virtue
//~ // of being last there the thread knows that all the other threads are
//~ // quiescent. All the others first wait on a condition variable until the
//~ // key one releases it, and then wait on a second condition variable until
//~ // that too is released.
//~ // The two variables are to let the underpinning variables get set up.
//~ // So outside GC-time a variable "gc_started" will be false, and all
//~ // non-key threads can go
//~ //      {   std::unique_lock<std::mutex> lock(mutexForGc);
//~ //          gc_start_cv.wait(lock, []{ return gc_started; });
//~ //      }
//~ // followed immediately  by
//~ //      activeThreads++;
//~ //      {   std::unique_lock<std::mutex> lock(mutexForGc);
//~ //          gc_end_cv.wait(lock, []{ return gc_finished; });
//~ //      }
//~ // The key thread on the other hand can go
//~ //      gc_finished = false;
//~ // MUST ensure that gc_finished will be seen as false by all other threads
//~ // before gc_started is seen as true, because otherwise spurious wake-ups
//~ // on gc_start_cv and gc_end_cv could let one of the other threads run
//~ // through improperly.
//~ //      {   std::lock_guard<std::mutex> lock(mutexForGc);
//~ //          gc_started = true;
//~ //      }
//~ //      gc_start_cv.notify_all();
//~ // At this point the key thread can perform garbage collection. It can not
//~ // tell if the other threads are still waiting to respond to the gc_start
//~ // notification or if they have gone on to wait for gc_finished! So to let
//~ // it know the subsidiary threads each increment activeThreads when they
//~ // have passed the first hurdle, and the one that brings that up to maximum
//~ // can notify yet another condition variable. At the end of GC the key thread
//~ // can wait on that CV until the thread count is high enough, and then it
//~ // can afford to clear gc_started and set gc_finished and finally notify
//~ // all other threads. Ught this feels heavy-handed and messy!
//~
//~ extern void setupEmptyPage(Page* p);
//~ extern void setupMostlyFreePage(Page* p);
//~ extern void setVariablesFromPage(Page* p);
//~ extern void saveVariablesToPage(Page* p);
//~
//~ inline void restoreGfringe()
//~ {   size_t inc = 0;
//~ #ifdef NO_THREADS
//~     result = nil;
//~     inc = gIncrement;
//~     gIncrement = 0;
//~ #else // NO_THREADS
//~     for (uintptr_t threadId=0; threadId<maxThreads; threadId++)
//~     {   result[i] = nil;
//~ //      zprintf("result[%d] = nil = %a\n", threadId, nil);
//~         inc += gIncrement;
//~         gIncrement = 0;
//~     }
//~ #endif // NO_THREADS
//~     gFringe = gFringe - inc;
//~ }
//~
//~ inline void fitsWithinExistingGap(unsigned int threadId, size_t n, size_t gap)
//~ {
//~ // The request made will fit within the existing Chunk for thraed i.
//~     result = fringeBis + TAG_VECTOR;
//~ //  zprintf("result[%d] = %a\n", threadId, result);
//~ // If I fill in a result for this I set it to show it does not need any more.
//~     request = 0;
//~     setHeaderWord(result-TAG_VECTOR, n, TYPE_VEC32);
//~     fringeBis += n;
//~ //  zprintf("At %s fringeBis[%d] = %a\n", __WHERE__, threadId, fringeBis);
//~     gap -= n;
//~ // Make the end of the Chunk safe. This Chunk is not full, but a GC that is
//~ // (probably) about to happen can need to scan it so its chunkFringe info
//~ // must be filled in.
//~ // If I get here during a GC
//~     currentChunk->chunkFringe = fringeBis;
//~ }
//~
//~ inline void regionInPageIsFull(unsigned int threadId, size_t n,
//~                                size_t gap, unsigned int &pendingCount)
//~ {
//~ #ifdef DEBUG
//~     previousCons = 0;
//~ #endif // DEBUG
//~ // Here the current region in the Page is full. I may either have reached the
//~ // very end of the page or I may have merely run up against a pinned Chunk
//~ // within it.
//~ //  zprintf("At %s gFringe = %a\n", __WHERE__, gFringe);
//~ //  zprintf("At %s pageSize = %a\n", __WHERE__, pageSize);
//~ //
//~ // Take care because gFringe can point at the start of the next consecutive
//~ // Page.
//~     uintptr_t pageEnd = ((gFringe-1) & -pageSize) + pageSize;
//~ //# zprintf("At %s pageEnd = %a\n", __WHERE__, pageEnd);
//~     while (gLimit != pageEnd)
//~     {   gFringe = gLimit + reinterpret_cast<Chunk*>(gLimit)->length;
//~         gLimit = reinterpret_cast<uintptr_t>(
//~             static_cast<Chunk*>(
//~                 reinterpret_cast<Chunk*>(gLimit)->chunkPinChain));
//~ //      zprintf("At %s gLimit = %a\n", __WHERE__, gLimit);
//~         if (gLimit == 0) gLimit = pageEnd;
//~ //#     zprintf("At %s gLimit = %a\n", __WHERE__, gLimit);
//~         size_t gap1 = gLimit - gFringe;
//~         currentChunk->chunkFringe = fringeBis;
//~         if (n+targetChunkSize < gap1)
//~         {   Chunk* c = reinterpret_cast<Chunk*>(
//~                            static_cast<uintptr_t>(gFringe));
//~             c->length = n + targetChunkSize;
//~             c->isPinned = false;
//~             c->evacuated = false;
//~             c->pinnedObjects = TAG_FIXNUM;
//~             size_t chunkNo = currentPage->chunkCount++;
//~ //#         zprintf("regioninpagefull %a %d\n", currentPage, currentPage->chunkCount);
//~             currentPage->chunkMap[chunkNo] = c;
//~             currentChunk = c;
//~             result = gFringe + TAG_VECTOR;
//~             request = 0;
//~             setHeaderWord(result-TAG_VECTOR, n, TYPE_VEC32);
//~             fringeBis = gFringe + n;
//~ //#         zprintf("At %s fringeBis[%d] = %a\n", __WHERE__, threadId, fringeBis);
//~             gFringe = limitBis = limit = fringeBis + targetChunkSize;
//~             break;
//~         }
//~     }
//~ // pendingCount will be a count of the requests NOT satisfied. So I increment
//~ // it if I do not manage to make an allocation.
//~     if (request != 0) pendingCount++;
//~ }
//~
//~ // Eventually I expect I will always wish to allocate a Free page rather
//~ // than a MostlyFree one, but while developing and debugging it is good
//~ // to be able to exercise the recycling of cluttered space.
//~
//~ inline void grabNewCurrentPage(bool preferMostlyFree)
//~ {   //# zprintf("[1] Old current = %a\n", currentPage);
//~     if (preferMostlyFree && mostlyFreePages != nullptr)
//~     {   currentPage = mostlyFreePages;
//~         currentPage->type = busyPage;
//~         previousCons = 0;
//~ //#     zprintf("new current from mostlyFree = %a\n", currentPage);
//~         mostlyFreePages = mostlyFreePages->chain;
//~         if (mostlyFreePages == nullptr) mostlyFreeTail = nullptr;
//~         mostlyFreePagesCount--;
//~     }
//~     else if (freePages != nullptr)
//~     {   currentPage = freePages;
//~         currentPage->type = busyPage;
//~         previousCons = 0;
//~ //#     zprintf("new current from Free = %a\n", currentPage);
//~         freePages = freePages->chain;
//~ //#     zprintf("freePages := %a\n", freePages);
//~         freePagesCount--;
//~ // When I take something from freePages it may not have been initialised
//~ // at all or it may contain more or less arbitrary mess left over from when
//~ // the garbage collector put it on that list, so I will initialise all of
//~ // its contents here.
//~         setupEmptyPage(currentPage);
//~     }
//~     else
//~     {   currentPage = mostlyFreePages;
//~         currentPage->type = busyPage;
//~         previousCons = 0;
//~ //#     zprintf("new current from mostlyFree = %a\n", currentPage);
//~         my_assert(currentPage != nullptr,
//~             [&]{ zprintf("Utterly out of memory\n");
//~ #ifdef HAVE_QUICK_EXIT
//~                  std::quick_exit(99); });
//~ #else // HAVE_QUICK_EXIT
//~                  std::exit(99); });
//~ #endif // HAVE_QUICK_EXIT
//~         mostlyFreePages = mostlyFreePages->chain;
//~         if (mostlyFreePages == nullptr) mostlyFreeTail = nullptr;
//~         mostlyFreePagesCount--;
//~     }
//~     currentPage->chain = busyPages;
//~     busyPages = currentPage;
//~ //# zprintf("busyPages := %a\n", busyPages);
//~     busyPagesCount++;
//~     setVariablesFromPage(currentPage);
//~ // Every thread will now need to grab its own fresh chunk!
//~     for (unsigned int threadId=0; threadId<maxThreads; threadId++)
//~         limit = fringeBis = limitBis = gFringe;
//~ //  zprintf("At %s fringeBis = limitBis = gFringe = %a\n",
//~ //          __WHERE__, gFringe);
//~ //  zprintf("@@ just allocated a fresh page\n");
//~ }
//~
//~ extern bool withinMajorGarbageCollection;
//~
//~ // Low level functions for allocating objects.
//~
//~ // Entry to a garbage collector.
//~
//~ extern void garbageCollect();
//~
//~ void allocate_segment(size_t n);
//~ extern void clearPinnedMap(Page* x);
//~ extern uint64_t threadBit(unsigned int n);
//~ extern bool isPinned(Page* x, uintptr_t p);   // test if pin bit set
//~ extern void setPinned(Page* x, uintptr_t p);  // just set mark in pinmap
//~ extern void setPinnedMajor(uintptr_t p); // used during major GC
//~ extern void setPinnedMinor(uintptr_t p); // used during minor GC
//~
//~ // "Borrowing" is a concept that I introduce for use as part of the
//~ // Lisp implementation. The key place that it is used is when a hash
//~ // table needs to be re-hashed, and a particular case of that is a table
//~ // keyed on EQ when garbage collection has just relocated all the contents.
//~ // If I have an ephemeral GC I will probably not be copying the table itself
//~ // and so I can not re-hash as part of that process. So what I want to do
//~ // is to "borrow" some space from the part of the memory pool that is not
//~ // currently in use. I can then copy the table data into that and then
//~ // transfer it back hashing it using the new set of hash values that
//~ // relocation of data has led to. There is no heap allocation while that
//~ // copy and re-hash is happening and when it is done the borrowed memory can
//~ // be returned to the general free pool. In the middle of a run there will
//~ // need to be plenty of free space to make available because there has to be
//~ // enough for all live data to be copied into by a full GC.
//~
//~ //#define TL_borrowPages 52
//~ //DECLARE_THREAD_LOCAL(Page* , borrowPages);
//~ //#define TL_borrowFringe 53
//~ //DECLARE_THREAD_LOCAL(uintptr_t, borrowFringe);
//~ //#define TL_borrowLimit 54
//~ //DECLARE_THREAD_LOCAL(uintptr_t, borrowLimit);
//~ //#define TL_borrowNext 55
//~ //DECLARE_THREAD_LOCAL(uintptr_t, borrowNext);
//~
//~ #ifdef NO_THREADS
//~ extern Page* borrowPages;
//~ extern uintptr_t borrowFringe;
//~ extern uintptr_t borrowLimit;
//~ extern uintptr_t borrowNext;
//~ #else // NO_THREADS
//~ extern Page* borrowPagess[maxThreads];
//~ #define borrowPages borrowPagess[threadId]
//~ extern uintptr_t borrowFringes[maxThreads];
//~ #define borrowFringe borrowFringes[threadId]
//~ extern uintptr_t borrowLimits[maxThreads];
//~ #define borrowLimit borrowLimits[threadId]
//~ extern uintptr_t borrowNexts[maxThreads];
//~ #define borrowNext borrowNexts[threadId]
//~ #endif // NO_THREADS
//~
//~ class Borrowing
//~ {
//~ public:
//~     Borrowing()
//~     {   THREADID;
//~         borrowPages = nullptr;
//~         borrowFringe = 0;
//~         borrowLimit = 0;
//~         borrowNext = 0;
//~     }
//~     ~Borrowing()
//~     {   std::lock_guard<std::mutex> lock(mutexForFreePages);
//~         THREADID;
//~         while (static_cast<Page*>(borrowPages) != nullptr)
//~         {   if (static_cast<Page*>(borrowPages)->chunkCount != 0)
//~             {   Page* w = static_cast<Page*>(borrowPages)->chain;
//~                 appendMostlyFree(borrowPages);
//~                 borrowPages = w;
//~             }
//~             else
//~             {   Page* w = static_cast<Page*>(borrowPages)->chain;
//~                 static_cast<Page*>(borrowPages)->chain = freePages;
//~                 freePages = borrowPages;
//~                 freePages->type = freePage;
//~ //#             zprintf("freePages := %a\n", freePages);
//~                 borrowPages = w;
//~             }
//~         }
//~     }
//~ };
//~
//~
//~ // I will arrange that if the GC takes more than this time waiting on a
//~ // condition variable it will abort. Such timeouts are dangerous in various
//~ // various ways and the amount of time it could make sense to allow will
//~ // depend on the speed of the computer in use. However while I am only
//~ // using one thread there ought not be to any contention and no thread
//~ // should ever stall during GC, so having a short period here is not a
//~ // big issue. When I have multiple threads the value set here will need
//~ // to be thought about much more carefully, or the timeout may have to
//~ // be withdrawn! It seems certain that I should arrange that the time limit
//~ // here is as long as the slowest garbage collection.
//~
//~ #ifdef DEBUG
//~ // While debugging I may be single stepping code or printing copious
//~ // trace ouput, so I will set a limit at 5 minutes (and adjust that further
//~ // if it causes me trouble).
//~ INLINE_VAR const std::chrono::seconds cvTimeout(300);
//~ #else // DEBUG
//~ INLINE_VAR const std::chrono::seconds cvTimeout(1);
//~ #endif // DEBUG
//~
//~ #ifdef DEBUG
//~
//~ // The following is intended to help me check if allocation is going
//~ // smoothly. It can be removed once debugging is complete (ha ha).
//~
//~ inline void testLayout()
//~ {   THREADID;
//~     uintptr_t r = fringe;
//~     uintptr_t w = limit;
//~     my_assert(w==0 || r <= w,    []{zprintf("fringe > limit\n"); });
//~     my_assert(gFringe <= gLimit, []{zprintf("gFringe > gLimit\n");});
//~ }
//~
//~ #endif // DEBUG

#endif // 0 /////////////////// @@@@@@@@@@@@@@@@@@@@@@@@@@@

#endif // header_newallocate_h

// end of newallocate.h
