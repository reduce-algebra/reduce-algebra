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

INLINE_VAR const size_t pageSize = 8*1024*1024u;     // Use 8 Mbyte pages
INLINE_VAR const size_t chunkSize = 16*1024u;        // 16 Kbyte chunks
INLINE_VAR const size_t chunkMask = chunkSize-1;

extern bool allocateSegment(size_t);

enum PageType
{   emptyPageType,
    consPageType,
    vecPageType,
};

class Page;
class PageListIter;

class PageList
{
public:
    Page *head;
    size_t count;
// I want (rather minimal) support for an iterator over the Pages in
// a PageList.
    typedef std::input_iterator_tag iterator_category;
    typedef std::ptrdiff_t          difference_type;
    typedef Page                    value_type;
    typedef Page*                   pointer;
    typedef Page&                   reference;
    PageListIter begin();
    PageListIter end();

    PageList()
    {   head = nullptr;
        count = 0;
    }
    Page*& page()
    {   return head;
    }
    bool isEmpty()
    {   return head == nullptr;
    }
    PageList& operator=(PageList& a)
    {   head = a.head;     a.head = nullptr;
        count = a.count;   a.count = 0;
        return *this;
    }
    PageList& operator+=(PageList& a)
    {   while (!a.isEmpty())
            push(a.pop());
        return *this;
    }
    void push(Page* a);
    Page* pop();
};

class PageListIter
{
public:
    PageList& L;
    Page* loc;
    PageListIter(PageList& a, Page* p) : L(a), loc(p)
    {
    }
    Page* operator*()
    {   return loc;
    }
    Page* operator++();
    bool operator!=(PageListIter& a)
    {   return a.loc != loc;
    }
};

inline PageListIter PageList::begin()
{   return PageListIter(*this, head);
}

inline PageListIter PageList::end()
{   return PageListIter(*this, nullptr);
}

extern PageList emptyPages;        // Fully empty.
extern PageList consPinPages;      // Not active but contains some pinned data.
extern PageList vecPinPages;       // Ditto, but with vectors not cons cells.
extern PageList consCloggedPages;  // Not active and contains much pinned data.
extern PageList vecCloggedPages;   // Not active and contains much pinned data.
extern PageList consPages;         // Active pages containing cons cells.
extern PageList vecPages;          // Active pages containing vectors.
extern PageList borrowPages;       // Temporarily active pages.
extern PageList consOldPages;      // Used during GC.
extern PageList vecOldPages;       // Ditto.

extern Page* consCurrent;       // Where cons cells are allocated.
extern Page* vecCurrent;        // Where vectors are allocated.
extern Page* borrowCurrent;     // Where temporary vectors are allocated.

extern Page* potentiallyPinned; // For GC.
extern Page* pinnedPages;       // For GC.
extern Page* pendingPages;      // For GC.


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

class alignas(pageSize) Page
{
public:
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
            Page* borrowChain;
            bool borrowPinned;
            Page* oldPinnedPages;
            Page* pinnedPages;
            Page* pendingPages;
            LispObject pinnedObjects;
            uintptr_t scanPoint;
            uintptr_t dataEnd;
            uintptr_t initialLimit;
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
                {   uint64_t consPins[pageSize/
                                        (2*sizeof(LispObject))/
                                        (8*sizeof(uint64_t))];
                    uint64_t newConsPins[pageSize/
                                           (2*sizeof(LispObject))/
                                           (8*sizeof(uint64_t))];
                    ConsCell consData[1];
                };
                struct
                {   bool potentiallyPinnedFlag;
                    Page* potentiallyPinnedChain;
// I make chunkStatus an array of uint8_t values so that I understand
// its layout very clearly. The values stored are explained elsewhere.
                    uint8_t  chunkStatus[pageSize/chunkSize];
                    uint64_t potentiallyPinnedChunks[pageSize/
                                                     chunkSize/(8*sizeof(uint64_t))];
                    uint64_t vecPins[pageSize/8/(8*sizeof(uint64_t))];
                    uint64_t newVecPins[pageSize/8/(8*sizeof(uint64_t))];
                    Chunk chunks[1];
                };
            };
        };
    };
};

inline void PageList::push(Page* p)
{   p->chain = head;
    head = p;
    count++;
}

inline Page* PageList::pop()
{   my_assert(head != nullptr, "popping from empty page list");
    Page* r = head;
    head = head->chain;
    count--;
    return r;
}

inline Page* PageListIter::operator++()
{   return (loc = loc->chain);
}

INLINE_VAR const size_t vecDataSize = sizeof(Page) - offsetof(Page, chunks);

inline size_t chunkNoFromAddress(Page* p, uintptr_t a)
{   my_assert((a - reinterpret_cast<uintptr_t>(p))/chunkSize <= 512, LOCATION);
    return (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
}

inline uintptr_t addressFromChunkNo(Page* p, size_t n)
{   my_assert(n <= 512, LOCATION);
    return reinterpret_cast<uintptr_t>(p) + chunkSize*n;
}

inline bool isPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = chunkNoFromAddress(p, a);
    return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = chunkNoFromAddress(p, a);
    p->potentiallyPinnedChunks[chunkNo/64] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

inline bool isPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   p->potentiallyPinnedChunks[chunkNo/64] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

// Here p must be a CONS page and a a pointer within it.

inline bool consIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->consData))/(2*sizeof(LispObject));
    return (p->consPins[o/64] >> (o&63)) != 0;
}

inline bool consIsNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->consData))/(2*sizeof(LispObject));
    return (p->newConsPins[o/64] >> (o&63)) != 0;
}

inline void consSetNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->consData))/(2*sizeof(LispObject));
    p->newConsPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void consClearNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->consData))/(2*sizeof(LispObject));
    p->newConsPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}

// And versions for VEC pages, which pin with granularity a single
// LispObject, so the bitmaps are twice as large as the ones for CONS pages
// where granularity only needs to be the size of a pair of adjacent
// objects.

inline bool vecIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->chunks))/sizeof(LispObject);
    return (p->vecPins[o/64] >> (o&63)) != 0;
}

inline bool vecIsNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->chunks))/sizeof(LispObject);
    return (p->newVecPins[o/64] >> (o&63)) != 0;
}

inline void vecSetNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->chunks))/sizeof(LispObject);
    p->newVecPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void vecClearNewPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p->chunks))/sizeof(LispObject);
    p->newVecPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}


// Set up the given Page as one for use with CONS supposing it is
// totally free to start with. This sets up global fringe and limit pointers.

// Note that a page that has any pinned items in it will hold the relevant
// values for those in scanPoint and initialLimit fields.

extern uintptr_t consFringe, consLimit, consEnd;

extern uintptr_t consEndOfPage();
extern void garbage_collect();

// A totally unused page must still have its type field filled in as
// emptyPageType so that ambiguous pointers that refer within it can
// be disregarded.
// 

// I should document the layout of a Cons Page, and the structure depends
// on the status of the page:
//
// Empty:      value in consData[0].car = consEnd
//             Well actually that will get set as the page is allocated to
//             be one containing Cons style data. Also a fully empty page
//             will have the bitmaps relating to pinning all clear.
//             dataEnd points at the start of the page.
//
// Empty+Pins: first unpinned word points to either consEnd or the next
//             pinned location, and similarly beyond that. dataEnd refers
//             to the start of the page. So a fully empty page is just a
//             special case of that.
//
// Full:       Valid data is present from consData[0] to dataEnd
//             but skipping items marked as pinned in the bitmap and the
//             pinning bitmap will identify any pinned data. Ah well
//             in fact all of these have the same structure. I just show
//             them separately here because allocating an unused page as
//             a cons page makes an empty one, the GC can release pages
//             as either unused or empty+pins and both GC and general
//             computation can allocate memory as full pages.
// 
//
// Current:    data runs from consData[0] to scanPoint and then scanPoint
//             up to consFringe, but any cells marked as pinned will be
//             ignored on scanning.
//             During allocation new data is placed from consFringe to
//             consLimit.
//             There are two possibilities there. One is that consLimit is
//             at consEnd in which case the Page has become full. The other
//             is that the cell at consLimit is pinned. In such a case one
//             can perform a linear scan upwards looking for either no
//             pinning or consEnd. If an unpinned item is found its
//             contents show where the next setting of consLimit should
//             be, and that will either be the next pinned item or consEnd.
//
// Note that some of the words there refer to global variables (eg consFringe)
// while others are fields stored within the Page (eg scanPoint).
//
// When allocation fills up a page or when GC is about to start (which
// may happen when the current cons page is only partly filled) the
// current Page has its dataEnd field set to consFringe.
// Whenever a new current (cons) page is established it has its scanPoint
// and dataEnd fields set to the first address after &consData[0]
// that is not pinned, and consFringe also points there. consLimit is set
// based on the initial value set there. This means that a Page that contains
// any pinned cons cells may not be re-allocated to hold vectors, because it
// has to have the internal structure as per here,
// "Current:" above. So that defines the state that the GC must leave
// a cons Page in. So for clarity, if the page is utterly empty and without
// any pinned items it starts off with its first word containing the
// address one beyond its last.

// Well I will also explain a Vector Page.
//
// Each vector Page is viewed as made up of a sequence of chunks each of
// 16KB and a 512 byte array provides a small amount of information about
// each. The values are used as follows:
// 0          A basic chunk, ie everything fits within 16KB.
// 1          The first segment of an extended chunk.
// 2,3,..253  Subsequent segments of an extended chunk.
// 254        Initial segment of an extended chunk containing some pins.
// 255        A basic chunk that contains some pinned data.
// In CSL I arrange that the largest basic vector I allocate is of size
// around 2MB and a consequence of that is that I will never need an
// extended chunk much larger than that, and so I will never overflow
// the limit (253) of segments in an extended chunk. Phew. Note that setting
// the array so it just contains zero leaves it is a "safe" state, and when
// an unused Page is made into a Vector one this must happen.
//
enum ChunkStatus
{
    BasicChunk          = 0u,
    ExtendedChunkStart  = 1u,
    ExtendedChunkMax    = 253u,
    ExtendedPinnedChunk = 254u,
    BasicPinnedChunk    = 255u
};

// The purpose of all this is that if I have an ambiguous pointer that
// refers within a vector page I can first easily identify the chunk
// it is within. Then I probe the byte array. If the value I find is
// 0, 1, 254 or 255 I have the first or only 16KB part of the chunk.
// Otherwise I can subtract the number I find from the address to identify
// the first part, and then if I need to re-probe to see if an extended
// chunk contains any pinned objects. I saturate counts at 253.
//
// A full vector page will contain its sequence of chunks. some will be
// flagged as containing pinned material by the entry on their first
// (or only) segment. A bitmap will identify the headers of the pinned
// objects within them.
// Chunks up to dataEnd will will contain a sequence of Lisp items,
// with a padder object at the end so that the chunk is totally full,
// ir if it is a current Page live date runs up to vecFringe.
// Only chunks containing pinned material beyond that are at all
// useful.
//
// A current vector page will have a scanPoint that refers just beyond
// some object and has vecFringe and vecLimit set properly.
// Each chunk apart from the one that vecFringe points within
// and any that contain pinned data are totally full (with a padder at
// the end). So to scan, one identifies the chunk concerned (by dividing
// by 16K) and checks its sequence number in the byte-array. That makes
// it possible to identify the end of the chunk or extended chunk, and
// the data can then be parsed until that is reached. Then the next
// non-pinned chunk is found (by skipping over pinned chunks) and scanning
// continues until either vecFringe or the end of the Page is reached.
//
// Allocation will test currentChunkIsEmpty. If it is empty then it is
// OK to allocate a block up as far as vecHardLimit, which is either the
// start of the next pinned chunk is is vecEnd. In that case the allocated
// space is set up as an extended chunk if needbe and vecLimit set so that
// subsequent small requests can potentially fill up spare space at the
// end. Of course that clears currentChunkIsEmpty. The next allocation(s)
// can fit in blocks of memory up as far as vecLimit. A common case may be
// when multiple smallish vectors build up within a basic chunk.
// When the next request will not fit a padder has to be put in and
// a new empty chunk started.
// When there is an attempt to allocate a rather large vector a big padder
// may be needed. Well most padders will just be from vecFringe to the
// end of the current chunk, so inserting then will not adjust
// chunkStatus[], but it will be possible to need to insert a padder
// when currentChunkIsEmpty and that may cvall for an extended chunk to
// hold it.
//
// A vector page that is empty apart from some pinned stuff needs to have
// the chunkStatus array filled in to identify each chunk that contains
// pinned material. When a totally fresh page is made into a vector page
// the chunkStatus[] array can be set to zero as if every chunk is basic
// and not pinned.

// Allocation while programs are running normally and when garbage
// collection is in progress are identical until a Page becomes full.
// In normal cases filling a page leads to a check as to whether 2/3 of
// all available pages are in use, and if now a further page is just
// grabbed, and otherwise GC is triggered. Well "available" needs to include
// available via requesting more from the operating system.
// During GC fresh pages are always grabbed save that if none are available
// at all then a "run out of memory" event must be reported. This is a
// horrible situation because memory is in a messed up state with some
// stuff copied to the "new half space" and some not, so recovery is
// not possible but I suspect that by making print routines able to
// traverse forwarding pointers transparently it may still be possible to
// generate a backtrace. If I want to be able to recover from memory-full
// disasters I would need to trigger GC when memory became just 1/2 full
// (and still worry about fragmentation!) and then complain at the end
// of GC unless there was not say 1/6 of memory still unused, ie that
// half memory load had compressed into 1/3 of memory, which is the
// same stopping point that I am at present envisaging. But my proposed
// scheme garbage collects less frequently so improves performance at the
// cost of recovery in circumstances that I tend to view as unrecoverable!

inline ChunkStatus saturateChunk(size_t n)
{   if (n >= ExtendedChunkMax) return ExtendedChunkMax;
    else return static_cast<ChunkStatus>(n+1);
}

// With at least some compilers if I have an "inline" function definition
// but there are no calls to it then no space is wasted. Well compile time
// may be impacted. So I put some functions that can display or validate
// Pages here for use while debugging and expect there not to be any space
// overhead in the compiled binary of builds that happen not to use them.

inline void displayConsPage(Page* p)
{   zprintf("Cons page %a\n", p);
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowChain = %a borrowPinned=%s\n",
        p->borrowChain, p->borrowPinned);
    zprintf("oldPinnedPages = %a\n", p->oldPinnedPages);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("scanPoint=%a dataEnd=%a initialLimit=%a\n",
        p->scanPoint, p->dataEnd, p->initialLimit);
    uintptr_t prev = 0x1234567887654321u;
    for (uintptr_t q=reinterpret_cast<uintptr_t>(&p->consData);
                   q<p->dataEnd;
                   q+=sizeof(uintptr_t))
    {   uintptr_t n = *reinterpret_cast<uintptr_t*>(q);
        if (n != prev)
        {   zprintf("%a: %a\n", q, n);
            prev = n;
        }
    }
    zprintf("end of page %a\n", p);
}

inline void displayVecPage(Page* p)
{   zprintf("Vec page %a\n", p);
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowChain = %a borrowPinned=%s\n",
        p->borrowChain, p->borrowPinned);
    zprintf("oldPinnedPages = %a\n", p->oldPinnedPages);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("scanPoint=%a dataEnd=%a initialLimit=%a\n",
        p->scanPoint, p->dataEnd, p->initialLimit);
    unsigned int n = 0;
    for (unsigned int i=0; i<sizeof(p->chunkStatus); i++)
    {   unsigned int k = p->chunkStatus[i];
        if (k == BasicChunk)
        {   n++;
            continue;
        }
        if (n != 0)
        {   zprintf("~%d ", n);
            n = 0;
        }
        zprintf("^%d ", k);
    }
    if (n != 0) zprintf("~%d ", n);
    zprintf("\n");
}

inline void displayAllPages(const char* s)
{   zprintf("displayAllPages %s\n", s);
    for (auto p:consPages) displayConsPage(p);
    for (auto p:vecPages) displayVecPage(p);
    zprintf("end of display\n\n");
}

extern bool withinGarbageCollector;

// The class here is to ensure that the flag gets reset when GC terminates.

class WithinGarbageCollector
{
public:
    WithinGarbageCollector()
    {   withinGarbageCollector = true;
    }
    ~WithinGarbageCollector()
    {   withinGarbageCollector = false;
    }
};

inline uintptr_t harderGet2Words()
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
    if (consFringe == consEnd) return consEndOfPage();
// When I skip pinned data and if there is space beyond same then the first
// word of that region holds a pointer showing where the next usable
// section of memory ends.
    consLimit = *reinterpret_cast<uintptr_t*>(consFringe);
// Now I can allocate.
    uintptr_t r = consFringe;
    consFringe += 2*sizeof(LispObject);
    return r;
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
    return harderGet2Words();
}

inline Header makeHeader(size_t n, int type)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + type;
}

// At times I want to put a vector header at the start of a block of
// memory. This does the job. Note that a is an untagged pointer here.

inline void setHeaderWord(uintptr_t a, size_t n, int type=TYPE_PADDER)
{   *reinterpret_cast<uintptr_t*>(a) = makeHeader(n, type);
}

extern uintptr_t vecFringe, vecLimit, vecEnd;
extern uintptr_t borrowFringe, borrowLimit, borrowEnd;


extern void grabFreshPage(PageType type);
extern int vecStopCache;
extern int borrowStopCache;
    
// The big function here is now shared between use for long-term vectors
// and borrowed ones. Allocations within a 16K chunk do not get to it and
// so my expectation is that its extra reference arguments will not lead
// to severe overhead. The key difference between the two use cases is that
// borrowing must not update chunkStatus. This function must be called
// potentially repeatedly until it returns a value other than zero! 

inline uintptr_t getNBytes(size_t n, Page* current,
                           uintptr_t& fringe, uintptr_t& limit, uintptr_t &end,
                           int& stopCache, bool borrowing)
{   for (;;)
    {   uintptr_t r = fringe;
        my_assert(fringe <= limit, LOCATION);
        my_assert(fringe > (uintptr_t)current &&
                  fringe <= (uintptr_t)(current+1), LOCATION);
// Now I will see if the new item will fit within the current chunk. Note
// that this test applies whether I am in a basic chunk or at the end of
// an extended one. The chunkStatus[] entry must already be set up and
// at the start that will always indicate basic chunks, so when this fills
// one chunk perfectly and moves on to the next that next one will be
// ready to be a basic chunk. The test against limit is needed because
// a previous allocation may have totally filled eg the last chunk on
// the page.
        if ((r&chunkMask) + n <= chunkSize && r!=limit)
        {   fringe += n;
            my_assert(fringe <= limit, LOCATION);
            return r;
        }
// Here either the request will not fit in the current chunk or really there
// is no current chunk. Insert a padder in the former case.
        if (r!=limit)
        {   if (!borrowing) setHeaderWord(r, (-r)&chunkMask);
            my_assert(fringe > (uintptr_t)current &&
                      fringe <= (uintptr_t)(current+1), LOCATION);
            fringe = r + ((-r)&chunkMask);
            my_assert(fringe <= limit, LOCATION);
            my_assert(fringe > (uintptr_t)current &&
                      fringe <= (uintptr_t)(current+1), LOCATION);
        }
// Now fringe points at the start of a chunk. In some cases that will
// mean I can just move on and use that chunk easily. Note that this
// requires chunkStatus[] to have been initialised to BasicChunk
        if (n <= chunkSize && fringe != limit)
        {   r = fringe;
            fringe += n;
            my_assert(fringe <= limit, LOCATION);
            return r;
        }
        my_assert(fringe > (uintptr_t)current &&
                  fringe <= (uintptr_t)(current+1), LOCATION);
// Here is the messy case. It could be that the request is small and
// I have just filled memory up as far as limit, or it could be that
// there is space before limit but I need to confirm that there are
// enough consecutive free unpinned chunks to accommodate a large
// vector request. This is ugly because limit is not the end of
// where real available space is - it is just the end of a chunk. I will
// need to scan chunkStatus to find how far I can really go, but stopCache
// is used so I do not do that more often that needbe.
        size_t chunkNo = chunkNoFromAddress(current, fringe);
// chunkNo is now the number of the chunk that I had reached at limit. I
// will skip over any pinned chunks. If there are any then stopCache needs
// resetting.
        while (chunkNo<sizeof(current->chunkStatus) &&
               current->chunkStatus[chunkNo] != BasicChunk)
        {   chunkNo++;
            stopCache = -1;
        }
// Now I know where the next available region is. Scan to find its end.
// That will let me set fresh values for fringe and limit.
        size_t stopPoint;
        if (stopCache >= 0 && false) stopPoint = stopCache;
        else
        {   stopPoint = chunkNo;
            while (stopPoint<sizeof(current->chunkStatus) &&
                   current->chunkStatus[stopPoint] == BasicChunk)
                stopPoint++;
            stopCache = stopPoint;
        }
        fringe = addressFromChunkNo(current, chunkNo);
        limit = addressFromChunkNo(current, stopPoint);
// I hope that very often the allocation can use available space now.
        if (n <= limit-fringe)
        {   // It will fit : hoorah!
            uintptr_t r = fringe;
            fringe += n;
// Set limit the the chunk boundary just above the newly allocated
// region of memory
            limit = fringe + ((-fringe) & chunkMask);
// Mark up an extended block if needbe.
            if (n > chunkSize && !borrowing)  // leave as Basic if possible.
            {   size_t chunksNeeded = (n + chunkSize - 1)/chunkSize;
                for (size_t i=0; i<chunksNeeded; i++)
                    current->chunkStatus[chunkNo+i] =
                        saturateChunk(ExtendedChunkStart+i);
            }
//          displayVectorPage(current);
            return r;
        }
// Ugh - the request will not fit in this block. I need to fill this block
// with a padder and scan on looking for another. Make the space into
// and extended block (if necessary)
        if (limit != fringe+chunkSize && !borrowing)
            for (size_t i=chunkNo; i<stopPoint; i++)
                current->chunkStatus[i] =
                    saturateChunk(ExtendedChunkStart+(i-chunkNo));
        if (!borrowing) setHeaderWord(fringe, limit-fringe);
//      displayVectorPage(current);
        fringe = limit;
        stopCache = -1;
// If I have reached the end of a Page then I must grab a new one.
        if (limit == end) return 0;
        continue;    
    }
}

// This function should always be used with an argument that is
// a multiple of sizeof(uintptr_t).

inline uintptr_t getNBytes(size_t n)
{   if (n == 2*sizeof(LispObject)) return get2Words();
    uintptr_t r = vecFringe;
// Now I will see if the new item will fit within the current chunk. Note
// that this test applies whether I am in a basic chunk or at the end of
// an extended one. The chunkStatus[] entry must already be set up and
// at the start that will always indicate basic chunks, so when this fills
// one chunk perfectly and moves on to the next that next one will be
// ready to be a basic chunk. The test against vecLimit is needed because
// a previous allocation may have totally filled eg the last chunk on
// the page. I expect this to be the most common case
    if ((r&chunkMask) + n <= chunkSize && r!=vecLimit)
    {   vecFringe += n;
        return r;
    }
    while ((r = getNBytes(n, vecCurrent, vecFringe,
                          vecLimit, vecEnd, vecStopCache, false)) == 0)
    {   vecCurrent->dataEnd = vecFringe;
// If I am within the GC I need a chain of all pages that have been filled
// up, and if I am not in the GC then establishing such a chain is an utterly
// trivial overhead so I may as well do it anyway.
        vecCurrent->pendingPages = pendingPages;
        pendingPages = vecCurrent;
        grabFreshPage(vecPageType);
        vecStopCache = -1;
    }
    return r;
}

extern Page* pageFringe;
extern Page* pageEnd;

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

inline Page* initBorrowPage(Page* p, bool empty)
{
// borrowed pages do not need anything like as much initialisation since
// they will never participate in GC. However they must have chunkStatus
// set up since that is inspected in case there might have been pinned
// items within them.
    borrowCurrent = p;
    p->borrowChain = borrowPages.page();
    p->borrowPinned = !empty;
    borrowPages.page() = p;
    borrowEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {
// I do not need to do anything with pinning bitmaps here, but I must
// initialise chunkStatus since that is used during allocation.
        std::memset(p->chunkStatus, BasicChunk, sizeof(p->chunkStatus));
        borrowFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->chunks);
        borrowLimit = borrowEnd;
    }
    else
    {   borrowFringe = p->scanPoint;
        borrowLimit = p->initialLimit;
    }
//  displayVectorPage(p);
    return p;
}

inline void grabBorrowPage()
{   if (!emptyPages.isEmpty()) initBorrowPage(emptyPages.pop(), true);
    else if (pageFringe != pageEnd) initBorrowPage(pageFringe++, true);
    else if (!vecPinPages.isEmpty()) initBorrowPage(vecPinPages.pop(), false);
    else fatal_error(err_no_store);
}

inline uintptr_t borrowNBytes(size_t n)
{   uintptr_t r = borrowFringe;
    if ((r&chunkMask) + n <= chunkSize && r!=borrowLimit)
    {   borrowFringe += n;
        return r;
    }
    while ((r = getNBytes(n, borrowCurrent, borrowFringe,
                          borrowLimit, borrowEnd, borrowStopCache, true)) == 0)
    {
// Full borrowed do not go on the pendingPages list because they are not
// relevant to the GC.
        grabBorrowPage();
        borrowStopCache = -1;
    }
    return r;
}

class Borrowing
{
public:
    Borrowing()
    {   grabBorrowPage();
    }
    ~Borrowing()
    {   while (!borrowPages.isEmpty())
        {   Page* p = borrowPages.pop();
            zprintf("return borrowed page %a\n", p);
            if (p->borrowPinned) vecPinPages.push(p);
            else emptyPages.push(p);
        }
    }
};

inline void poll()
{
}

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
        if (pp->type==consPageType &&
            pOff >= offsetof(Page, consData))
        {   pOff -= offsetof(Page, consData);
            if (hs == 0) std::snprintf(r, 40,
                "#%" PRIxPTR ":%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 40,
                "#[%d]: %" PRIxPTR ":%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pp->type==vecPageType &&
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

#ifdef OLD_VERSION

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

#else // OLD_VERSION

// This version seems faster to me.

inline int nlz(uint64_t x)
{   x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x |= x>>32;
// Now x is a number with all bits up as far as its highest one set, and I
// have achieved that without performing any tests. Now I can use a lookup
// table in much the same wau as I do for trailing zero bits.
    static int8_t nlzTable[67] =
    {   64,  63,  25,  62,  49,  24,  41,  61,  52,  48,
         5,  23,  45,  40,  10,  60,   0,  51,  54,  47,
         2,   4,  36,  22,  34,  44,  13,  39,  20,   9,
        17,  59,  32,  -1,  26,  50,  42,  53,   6,  46,
        11,   1,  55,   3,  37,  35,  14,  21,  18,  33,
        27,  43,   7,  12,  56,  38,  15,  19,  28,   8,
        57,  16,  29,  58,  30,  31,  -1
    };
    return nlzTable[x % 67];
}

#endif // OLD_VERSION

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
// If the input value is zero it returns -1, but the GNU builtin does not
// guarantee any such behaviour, so zero input should be considered illegal.

// This is related to the function intlog2() in tags.h, but that function
// is only to be applied on inputs that are a power of 2.

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

#endif // header_newallocate_h

// end of newallocate.h

