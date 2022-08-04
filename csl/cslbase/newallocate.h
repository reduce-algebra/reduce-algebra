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

extern Page* consCurrent;          // Where cons cells are allocated.
extern Page* vecCurrent;           // Where vectors are allocated.
extern Page* borrowCurrent;        // Where temporary vectors are allocated.

extern Page* potentiallyPinned;    // For GC.
extern Page* pinnedPages;          // For GC.
extern Page* pendingPages;         // For GC.
extern Page* oldVecPinPages;       // for GC.

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

// In each case here the "/64" is because the bitmaps I use are
// always based on uint64_t words. This may add to cost on 32-bit machines
// but having a uniform word size in bitmaps leads to cleaner simpler code
// for me.

INLINE_VAR const size_t consPinSize = pageSize/sizeof(ConsCell)/64;
INLINE_VAR const size_t consPinBytes = 8*consPinSize;
INLINE_VAR const size_t chunkStatusSize = pageSize/chunkSize;
INLINE_VAR const size_t chunkStatusMapSize = chunkStatusSize/64;
// Note that vector pinning always works to resolution 8 bytes because on
// a 32-bit machine all vector-like objects are kept aligned on 8 byte
// boundaries, with padding if necessary.
INLINE_VAR const size_t vecPinSize = pageSize/8/64;
INLINE_VAR const size_t vecPinBytes = 8*vecPinSize;

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
                {   uint64_t consPins[consPinSize];
                    uint64_t newConsPins[consPinSize];
                    ConsCell consData[1];
                };
                struct
                {   bool potentiallyPinnedFlag;
                    Page* potentiallyPinnedChain;
                    bool hasVecPins;
                    bool isInVecPages;
                    Page* oldVecPinPages;
// At one stage I used a single arrray of uint8_t values here thinking
// to avoid loss of space. Doing that led to the need for special
// handling of vectors larger than around 256*16384 bytes, and also
// scanning forward across chunks could be clumsy. However because
// each chunk wants to be aligned at a 16K boundary I actually have quite
// a lot of spare space here, so having two arrays of ints does not reduce
// the memory free for storing vectors at all, and it cleans up my code
// in various ways! I have checked and even if on the platform concerned
// unsigned ints are 64-bit values this all fits in happily.
//
// The initial chunk of any extended chunk will have a value on chunkLength
// that is not 1 and that indicated how many chunks make it up. The
// other component chunks within the extended chunk can have the value 1.
                    unsigned int  chunkLength[chunkStatusSize];
// 
                    unsigned int  chunkStatus[chunkStatusSize];
// chunkStatusMap[] has one bit for each item in chunkStatus[], and that is
// a 1 if the indicated chunk is a pinned simple chunk or is a chunk within
// a pinned extended chunk. This plus "clz()" makes scanning forward to find
// the start of a free chunk or the end of a block of free chunks fairly
// cheap. Findding the end if a pinned extended chunk is a bit messier
// but can be done by finding the next free chunk then checking the backwards
// chaining in chunkStatus[] to skip back past any pinned chunks adjacent to
// the one being considered.
                    uint64_t chunkStatusMap[chunkStatusMapSize];
                    uint64_t vecPins[vecPinSize];
                    uint64_t newVecPins[vecPinSize];
                    Chunk chunks[1];
                };
            };
        };
    };
};

inline uintptr_t endOfPage(Page* p)
{   return csl_cast<uintptr_t>(p+1);
}

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

inline Page* pageOf(uintptr_t a)
{  return csl_cast<Page*>(a & (-pageSize));
}

inline size_t chunkNoFromAddress(Page* p, uintptr_t a)
{   return (a - csl_cast<uintptr_t>(p))/chunkSize;
}

inline size_t chunkNoFromAddress(uintptr_t a)
{   return chunkNoFromAddress(pageOf(a), a);
}

inline uintptr_t addressFromChunkNo(Page* p, size_t n)
{   return csl_cast<uintptr_t>(p) + chunkSize*n;
}

inline bool isPotentiallyPinned(Page* p, uintptr_t a)
{   return testBit(p->chunkStatusMap, chunkNoFromAddress(p, a));
}

inline void setPotentiallyPinned(Page* p, uintptr_t a)
{   setBit(p->chunkStatusMap, chunkNoFromAddress(p, a));
}

inline bool isPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   return testBit(p->chunkStatusMap, chunkNo);
}

inline void setPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   setBit(p->chunkStatusMap, chunkNo);
}

inline size_t consToOffset(uintptr_t a, Page* p)
{   return (a - csl_cast<uintptr_t>(&p->consData)) / (2*sizeof(LispObject));
}

inline uintptr_t offsetToCons(size_t o, Page* p)
{   return csl_cast<uintptr_t>(&p->consData) + 2*sizeof(LispObject)*o;
}

// Here p must be a CONS page and a is a pointer within it.

inline bool consIsPinned(uintptr_t a, Page* p)
{   return testBit(p->consPins, consToOffset(a, p));
}

inline bool consIsNewPinned(uintptr_t a, Page* p)
{   return testBit(p->newConsPins, consToOffset(a, p));
}

inline void consSetNewPinned(uintptr_t a, Page* p)
{   setBit(p->newConsPins, consToOffset(a, p));
}

inline void consClearNewPinned(uintptr_t a, Page* p)
{   clearBit(p->newConsPins, consToOffset(a, p));
}

// And versions for VEC pages, which pin with granularity a single
// LispObject, so the bitmaps are twice as large as the ones for CONS pages
// where granularity only needs to be the size of a pair of adjacent
// objects.

inline size_t vecToOffset(uintptr_t a, Page* p)
{   return (a - csl_cast<uintptr_t>(&p->chunks)) / sizeof(LispObject);
}

inline uintptr_t offsetToVec(size_t o, Page* p)
{   return csl_cast<uintptr_t>(&p->chunks) + sizeof(LispObject)*o;
}

inline bool vecIsPinned(uintptr_t a, Page* p)
{   return testBit(p->vecPins, vecToOffset(a, p));
}

inline bool vecIsNewPinned(uintptr_t a, Page* p)
{   return testBit(p->newVecPins, vecToOffset(a, p));
}

inline void vecSetNewPinned(uintptr_t a, Page* p)
{   setBit(p->newVecPins, vecToOffset(a, p));
}

inline void vecClearNewPinned(uintptr_t a, Page* p)
{   clearBit(p->newVecPins, vecToOffset(a, p));
}

inline bool consIsPinned(uintptr_t a)
{   return consIsPinned(a, pageOf(a));
}

inline bool consIsNewPinned(uintptr_t a)
{   return consIsNewPinned(a, pageOf(a));
}

inline void consSetNewPinned(uintptr_t a)
{   consSetNewPinned(a, pageOf(a));
}

inline void consClearNewPinned(uintptr_t a)
{   consClearNewPinned(a, pageOf(a));
}

inline bool vecIsPinned(uintptr_t a)
{   return vecIsPinned(a, pageOf(a));
}

inline bool vecIsNewPinned(uintptr_t a)
{   return vecIsNewPinned(a, pageOf(a));
}

inline void vecSetNewPinned(uintptr_t a)
{   vecSetNewPinned(a, pageOf(a));
}

inline void vecClearNewPinned(uintptr_t a)
{   vecClearNewPinned(a, pageOf(a));
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
// 16KB and a 512 element array provides a small amount of information about
// each. The values are used as follows:
//    ChunkStart       The first or only chunk of one without any pinning.
//    PinnedChunkStart Ditto but for chunks that do have pinned data within.
//    2,3,...          Chunk number N of an extended chunk.
//
enum ChunkStatus
{
    ChunkStart             = 0u,
    PinnedChunkStart       = 1u,
    ExtendedChunkInterior  = 2u    // and up
};

// The purpose of all this is that if I have an ambiguous pointer that
// refers within a vector page I can first easily identify the chunk
// it is within. Then I probe the array. If the value I find is at least 2
// I can use it to adjust until I am looking at the entry for the initial
// chunk of any extended one. The value stored against that tells me
// whether the chunk already has pinned material, and I can update it
// if necessary. The chunkLength array also lets me know both how long
// any extended chunk is and gives me an direct way to identify the
// following chunk.
// I keep chunkStatusMap as a bitmap with set bits for the every chunk
// containing pinned material (in the case of extended chunks the bit
// is only set for the start).
// Chunks up to dataEnd will will contain a sequence of Lisp items,
// with a padder object at the end so that the chunk is totally full,
// Or if it is a current Page, live date runs up to vecFringe.
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

// With at least some compilers if I have an "inline" function definition
// but there are no calls to it then no space is wasted. Well compile time
// may be impacted. So I put some functions that can display or validate
// Pages here for use while debugging and expect there not to be any space
// overhead in the compiled binary of builds that happen not to use them.

extern uintptr_t vecFringe, vecLimit, vecEnd;
extern uintptr_t borrowFringe, borrowLimit, borrowEnd;

inline void displayConsPage(Page* p)
{   zprintf("Cons page %a\n", p);
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowChain = %a borrowPinned=%s\n",
        p->borrowChain, p->borrowPinned);
    zprintf("oldPinnedPages = %a\n", p->oldPinnedPages);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("scanPoint=%a dataEnd=%a initialLimit=%a fr=%a lim=%a\n",
        p->scanPoint, p->dataEnd, p->initialLimit, consFringe, consLimit); 
    LispObject prevCar = 0, prevCdr = 0;
    prevCar = ~p->consData[0].car; // so it is NOT the start of a run
    size_t repeats = 0;
    for (uintptr_t q=csl_cast<uintptr_t>(&p->consData);
                   q<p->dataEnd && q!=consFringe;
                   q+=2*sizeof(uintptr_t))
    {   if (car(q) == prevCar && cdr(q) == prevCdr) repeats++;
        else
        {   if (repeats != 0) zprintf(" ... and %d repeats\n", repeats);
            zprintf("%a: %a@%s  .  %a@%s\n",
                q, prevCar=car(q), objectType(car(q)),
                   prevCdr=cdr(q), objectType(cdr(q)));
            repeats = 0;
        }
    }
    zprintf("end of page %a\n\n", p);
}

extern const char* show_fn0(no_args* x);
extern const char* show_fn1(one_arg* x);
extern const char* show_fn2(two_args* x);
extern const char* show_fn3(three_args* x);
extern const char* show_fn4up(fourup_args*x);
extern const char* streamop(uintptr_t x);

#define xSTREAM_HEADER (TAG_HDR_IMMED + TYPE_STREAM + ((14*CELL)<<(Tw+5)))

inline void displayVecPage(Page* p)
{   zprintf("Vec page %a\n", p);
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowChain = %a borrowPinned=%s\n",
        p->borrowChain, p->borrowPinned);
    zprintf("oldPinnedPages = %a\n", p->oldPinnedPages);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("scanPoint=%a dataEnd=%a initialLimit=%a fr=%a lim=%a\n",
        p->scanPoint, p->dataEnd, p->initialLimit, vecFringe, vecLimit);
    unsigned int n = 0;
    for (size_t i=0; i<chunkStatusSize; i++)
    {   unsigned int len = p->chunkLength[i];
        if (len == 1)
        {   n++;
            continue;
        }
        if (n != 0)
        {   zprintf("~%d ", n);
            n = 0;
        }
        zprintf("^%d ", len);
    }
    if (n != 0) zprintf("~%d ", n);
    zprintf("=====");
    size_t count = 1;
    int symhdr = 0, streamhdr = 0;
    uintptr_t prev = ~p->chunks[0].data[0];
    for (uintptr_t q=csl_cast<uintptr_t>(&p->chunks);
                   q<p->dataEnd && q!=vecFringe;
                   q+=sizeof(uintptr_t))
    {   uintptr_t n = *csl_cast<uintptr_t*>(q);
        if (is_symbol_header_full_test(n)) symhdr = 1;
        else if (n == xSTREAM_HEADER) streamhdr = 1;
        if (n != prev)
        {   if (count != 1) zprintf(" * %d\n", count);
            else zprintf("\n");
            const char* ff = "unknown";
            if (symhdr == 8) ff = show_fn0((no_args*)n);
            else if (symhdr == 9) ff = show_fn1((one_arg*)n);
            else if (symhdr == 10) ff = show_fn2((two_args*)n);
            else if (symhdr == 11) ff = show_fn3((three_args*)n);
            else if (symhdr == 12)
            {   ff = show_fn4up((fourup_args*)n);
                symhdr = 0;
            }
            else if (streamhdr == 5 ||
                     streamhdr == 6 ||
                     streamhdr == 9 ||
                     streamhdr == 10) ff = streamop(n);
            else if (streamhdr == 12) streamhdr = 0;
            if (std::strcmp(ff, "unknown") == 0)
                zprintf("%a: %a %s", q, n, objectType(n));
            else zprintf("%a: %a %s", q, n, ff);
            prev = n;
            count = 1;
            if (symhdr > 0) symhdr++;
            if (streamhdr > 0) streamhdr++;
        }
        else count++;
    }
    zprintf("\nend of page %a\n\n", p);
}

inline void displayAllPages(const char* s)
{   zprintf("displayAllPages %s\n", s);
    for (auto p:consPages) displayConsPage(p);
    for (auto p:vecPages) displayVecPage(p);
    for (auto p:consOldPages) displayConsPage(p);
    for (auto p:vecOldPages) displayVecPage(p);
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
    consLimit = *csl_cast<uintptr_t*>(consFringe);
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
{   *csl_cast<uintptr_t*>(a) = makeHeader(n, type);
}

extern void grabFreshPage(PageType type);
    
// The big function here is now shared between use for long-term vectors
// and borrowed ones. Allocations within a 16K chunk do not get to it and
// so my expectation is that its extra reference arguments will not lead
// to severe overhead. The key difference between the two use cases is that
// borrowing must not update chunkStatus. This function must be called
// potentially repeatedly until it returns a value other than zero! 

inline uintptr_t getNBytes(size_t n, Page* current,
                           uintptr_t& fringe, uintptr_t& limit, uintptr_t &end,
                           bool borrowing)
{   for (;;)
    {   uintptr_t r = fringe;
        my_assert(fringe <= limit, __WHERE__);
        my_assert(fringe > (uintptr_t)current &&
                  fringe <= (uintptr_t)(current+1), __WHERE__);
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
            my_assert(fringe <= limit, __WHERE__);
            return r;
        }
// Here either the request will not fit in the current chunk or really there
// is no current chunk. Insert a padder in the former case. Note that
// if r!=limit there is at least a bif of space that needs a padder.
        if (r!=limit)
        {   if (!borrowing) setHeaderWord(r, (-r)&chunkMask);
            my_assert(fringe > (uintptr_t)current &&
                      fringe <= (uintptr_t)(current+1), __WHERE__);
            fringe = r + ((-r)&chunkMask);
            my_assert(fringe <= limit, __WHERE__);
            my_assert(fringe > (uintptr_t)current &&
                      fringe <= (uintptr_t)(current+1), __WHERE__);
        }
// Now fringe points at the start of a chunk. In some cases that will
// mean I can just move on and use that chunk easily. Note that this
// requires chunkStatus[] to have been initialised to ChunkStart all
// the way through the page.
        if (n <= chunkSize && fringe != limit)
        {   r = fringe;
            fringe += n;
            my_assert(fringe <= limit, __WHERE__);
            return r;
        }
        my_assert(fringe > (uintptr_t)current &&
                  fringe <= (uintptr_t)(current+1), __WHERE__);
// Here is the messy case. It could be that the request is small and
// I have just filled memory up as far as limit, or it could be that
// there is space before limit but I need to confirm that there are
// enough consecutive free unpinned chunks to accommodate a large
// vector request. This is ugly because limit is not the end of
// where real available space is - it is just the end of a chunk. I will
// need to use chunkStatus and chunkLength to find how far I can really go.
        size_t chunkNo = chunkNoFromAddress(current, fringe);
// chunkNo is now the number of the chunk that I had reached at limit. I
// will skip over any pinned chunks (they must be pinned because I hit
// the limit).
        while (current->chunkStatus[chunkNo] != ChunkStart)
            chunkNo += current->chunkLength[chunkNo]; // Skip any pinned
// Now I know where the next available region starts. Find its end.
// That will let me set fresh values for fringe and limit.
        size_t stopPoint = nextOneBit(current->chunkStatusMap,
                                      chunkStatusMapSize,
                                      chunkNo);
        if (stopPoint == SIZE_MAX) stopPoint = chunkStatusSize; 
        fringe = addressFromChunkNo(current, chunkNo); // in case skipped pins
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
                current->chunkLength[chunkNo] = chunksNeeded;
// Write in the back-pointers into all but the first word of chunkStatus.
                for (size_t i=1; i<chunksNeeded; i++)
                    current->chunkStatus[chunkNo+i] = i+1;
            }
//          displayVectorPage(current);
            return r;
        }
// Ugh - the request will not fit in this block. I need to fill this block
// with a padder and scan on looking for another. Well fill each basic
// chunk with a padder that totally fills it.
        if (limit != fringe+chunkSize && !borrowing)
            for (size_t i=chunkNo; i<stopPoint; i++)
                if (!borrowing)
                    setHeaderWord(addressFromChunkNo(current, i), chunkSize);
//      displayVectorPage(current);
        fringe = limit;
// If I have reached the end of a Page then I must grab a new one.
        if (limit == end) return 0;
        continue;    
    }
}

// This function should always be used with an argument that is
// a multiple of sizeof(uintptr_t).

// At one stage I had a test in here so that vector-like things of
// size exectly 2*CELL get allocated in CONS pages not VEC ones. That
// was intended to reduce overhead dealing with them. The case I was
// particularly thinking of was boxed double precision floats. Well I
// may provide special treatment for JUST that case at some stage, but
// for now I will keep vectors and cons cells separated since that will
// make treatment of pinning easier.

inline uintptr_t getNBytes(size_t n)
{   uintptr_t r = vecFringe;
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
                          vecLimit, vecEnd, false)) == 0)
    {
// Here vecFringe should point at the start of a chunk just beyond
// all the ones that are in use.
        vecCurrent->dataEnd = vecFringe;
// If I am within the GC I need a chain of all pages that have been filled
// up, and if I am not in the GC then establishing such a chain is an utterly
// trivial overhead so I may as well do it anyway.
        vecCurrent->pendingPages = pendingPages;
        pendingPages = vecCurrent;
        grabFreshPage(vecPageType);
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
    borrowEnd = csl_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {
// I do not need to do anything with pinning bitmaps here, but I must
// initialise chunkStatus since that is used during allocation.
        for (size_t i=0; i<chunkStatusSize; i++)
        {   p->chunkStatus[i] = ChunkStart;
            p->chunkLength[i] = 1;
        } 
        borrowFringe = p->scanPoint = csl_cast<uintptr_t>(&p->chunks);
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
                          borrowLimit, borrowEnd, true)) == 0)
    {
// Full borrowed do not go on the pendingPages list because they are not
// relevant to the GC.
        grabBorrowPage();
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
{   if (p < csl_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int findSegment4(uintptr_t p, int n)
{   if (p < csl_cast<uintptr_t>(heapSegment[n+2]))
        return findSegment2(p, n);
    else return findSegment2(p, n+2);
}

inline int findSegment8(uintptr_t p, int n)
{   if (p < csl_cast<uintptr_t>(heapSegment[n+4]))
        return findSegment4(p, n);
    else return findSegment4(p, n+4);
}

inline int findSegment16(uintptr_t p, int n)
{   if (p < csl_cast<uintptr_t>(heapSegment[n+8]))
        return findSegment8(p, n);
    else return findSegment8(p, n+8);
}

inline int findHeapSegment(uintptr_t p)
{   int n = findSegment16(p, 0);
    if (p < csl_cast<uintptr_t>(heapSegment[n]) ||
        p >= csl_cast<uintptr_t>(heapSegment[n]) +
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
    static char rr[4*80];
    static int seq=0;
    char* r = &rr[80*(seq++ & 0x3)];
    if (p == static_cast<uintptr_t>(nil))
    {   std::strcpy(r, "nil");
        return r;
    }
    else if (p == 0U)
    {   std::strcpy(r, "zero");
        return r;
    }
    *r = 0;
    int hs = findHeapSegment(p);
    if (hs != -1)
    {   uintptr_t segBase = csl_cast<uintptr_t>(heapSegment[hs]);
        uintptr_t o = p - segBase;
        uintptr_t pNum = o/pageSize;
        Page* pp = csl_cast<Page*>(segBase + pNum*pageSize); 
        uintptr_t pOff = o%pageSize;
        if (pp->type==consPageType &&
            pOff >= offsetof(Page, consData))
        {   pOff -= offsetof(Page, consData);
            if (hs == 0) std::snprintf(r, 80,
                "#%" PRIxPTR ":%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 80,
                "#[%d]: %" PRIxPTR ":%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pp->type==vecPageType &&
                 pOff >= offsetof(Page, chunks))
        {   pOff -= offsetof(Page, chunks);
            if (hs == 0) std::snprintf(r, 80,
                "#%" PRIxPTR "::%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 80,
                "#[%d]: %" PRIxPTR "::%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pOff == 0)
        {   if (hs == 0) std::snprintf(r, 80, "#%" PRIxPTR ":", pNum);
            else std::snprintf(r, 80, "#[%d]: %" PRIxPTR ":", hs, pNum);
            return r;
        }
    }
    bool maybeChars = true;
    for (uintptr_t w=p; w!=0; w=w>>8)
    {   int c = w & 0xff;
        if (c < ' ' || c >= 0x7f) maybeChars = false;
    }
    if (maybeChars && p!=0)
    {   std::snprintf(r, 80, "%#" PRIxPTR "/%" PRIdPTR, p, p);
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
    else if (is_vector_header_full_test(p) &&
             length_of_header(p) < pageSize/2)
    {   char buf[40];
        std::snprintf(buf, 40, " %#" PRIxPTR ":L%u", p, (unsigned int)length_of_header(p));
        std::strcat(r, buf); // buffer overflow not protected here
    }
    else std::snprintf(r, 80, "%#" PRIxPTR "/%" PRIdPTR, p, p);
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
{    return csl_cast<uintptr_t>(heapSegment[0]) + pageSize*p + o;
}

// .. and extra for the case of addresses in segments 1 and beyond.

inline uintptr_t unAddr(unsigned int s, uintptr_t p, uintptr_t o)
{    return csl_cast<uintptr_t>(heapSegment[s]) + pageSize*p + o;
}

// This finds a page that a potential pointer p is within, or returns nullptr
// if there is not one

inline Page* findPage(uintptr_t p)
{   int n = findHeapSegment(p);
    if (n < 0) return nullptr;
    return csl_cast<Page*>(p & -pageSize);
}

#endif // header_newallocate_h

// end of newallocate.h

