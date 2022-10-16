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
// Each vector Page is viewed as made up of a sequence of chunks each in
// 16Kb units that are basic chunks. Associated with each 16K segment there
// are four values: chunkSeqNo[n], chunkLength[n], chunkPinned(n,p) and
// newChunkPinned(n,p). The first two are arrays the second two functions
// that access bitmaps.
// Suppose a chunk has N basic chunks making it up. Then the chunkLength[]
// for its start will hold N. Everywhere else chunkLength[] will be
// unused. The kth unit in the extended chunk has the value k in chunkSeqNo[]
// so the first one is 0, the second 1 etc. chunkLength[] makes it possible
// to scan chunks sequentially visiting the start of each. chunkSeqNo[]
// means that given any pointer into a chunk it is easy to identify the
// start of the block. The two pinning bits identify the starts of
// chunks that contain pinned material. By using nextOneBit() it is possible
// to find just pinned chunks reasonably fast.
// 
//

// The purpose of all this is that if I have an ambiguous pointer that
// refers within a vector page I can first easily identify the chunk
// it is within. Then I probe the array. Using chunkSeqNo[] I can find
// that start of chunk even if it is made up of many basic ones.
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
// by 16K) and checks its sequence number in chunkSeqNo[]. That makes
// it possible to identify the start and hence iusing chunnLength[] the
// end of the chunk. The data can then be parsed until that is reached.
// Then the next non-pinned chunk is found (by skipping over pinned chunks)
// and scanning continues until either vecFringe or the end of the Page
// is reached.
//
// When there is an attempt to allocate a rather large vector a big padder
// may be needed. Well most padders will just be from vecFringe to the
// end of the current chunk, so inserting then will not adjust
// chunkSeqNo[], but sometimes it will be necessary to have large padders.
// Eg suppose a Page is around 50% full and there is a request for a
// block of memory that is 70% of the Page size. The residual half page
// has to be turned into padder. That should be done by putting in multiple
// padders each of size (up to) 16Kb so that the space is left so that the
// unused memory is a sequence of basic chunks. The alternative would
// involve as much effort because chunkSeqNo[] values would need updating
// all through it.
//
// A vector page that is empty apart from some pinned stuff needs to have
// the chunkPinned filled in to identify each chunk that contains
// pinned material, and then chunkSeqNo[] and chunkLength[] for at least
// that pinned part. When a totally fresh page is made into a vector page
// the chunkBitmap[] array and chunkSeqNo[] can be set to zero and
// every element of chunkLength[] set to 1 to show every chunk is basic
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
// disasters I would need to trigger GC when memory became just 1/2 full.

// A conservative GC can waste memory when ambiguous pointers cause data to
// be preserved when it is in fact no longer in use. With large memory
// this waste will usually (I really hope!) be modest. An issue I had not
// recognised when I started this work is that when there is an ambiguous
// pointer to a symbol or vector then the page that contains that object
// has to remain one for vector use until subsequent GCs manage to notice
// that the ambiguity has evaporated. In bad cases and especially with
// fairly small memory allocation so there are not many pages this can
// lead to many pages ending up dedicated for use for vectors - to an extent
// that there end up not being enough for lists. Of course the same issue
// could arise the other way around. A conseqence of that is that allocating
// a fully empty page carries some danger of that page ending up dedicated
// to either lists or vectors - and so despite the fact that it may impact
// allocation speed a little I now preferentially grab types rather than
// empty pages... 

// With at least some compilers if I have an "inline" function definition
// but there are no calls to it then no space is wasted. Well compile time
// may be impacted. So I put some functions that can display or validate
// Pages here for use while debugging and expect there not to be any space
// overhead in the compiled binary of builds that happen not to use them.

INLINE_VAR const size_t pageSize = 8*1024*1024u;     // Use 8 Mbyte pages
INLINE_VAR const size_t chunkSize = 16*1024u;        // 16 Kbyte chunks
INLINE_VAR const size_t chunkMask = chunkSize-1;

extern bool allocateSegment(size_t);

enum PageType
{   emptyPageType,
    consPageType,
    vecPageType,
};

inline const char* pageTypeName(PageType x)
{   switch (x)
    {
    case emptyPageType:
        return "Empty";
    case consPageType:
        return "Cons";
    case vecPageType:
        return "Vec";
    default:
        return "Unknown";
    }
}

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

enum PinStatus
{   wasEmpty,
    wasPinned,
    wasClogged
};

// What I want is for my Page structure to have a known size (8Mbytes)
// and I want that to be a round numbers so I can use cheap mask operations
// to tell which page any pointer is within. A cons-Page has to contain
// some header information, two bitmaps and then the main part is an
// array ConsCell[]. Each bitmap will use 1/64 as much space as the main
// array. The header size is fixed until I change the code and add or remove
// items, or until a variant C++ compiler alters its layout.
// I use some "jolly" C++ metaprogramming to derive suitable sized for the
// bitmaps and main array.

template <int ConsN, int ChunkN>
class alignas(pageSize) PageTemplate
{
    using Page = PageTemplate<ConsN,ChunkN>;

public:
    static const size_t consDataCount = ConsN;
    static const size_t consPinWords = (consDataCount+63)/64;

    static const size_t chunkDataCount = ChunkN;
    static const size_t chunkInfoSize = chunkDataCount;
    static const size_t vecPinWords = (chunkSize*ChunkN+8*64-1)/(8*64);
    static const size_t chunkBitmapWords = (chunkDataCount+63)/64;
    
    union
    {
// A Page can be either a Cons page or a Vector page. The initial components
// are the same in each case
        struct
        {   PageType type;            // empty, cons or vector.
            Page* chain;              // general purpose chaining.
            size_t hasPinned;         // count of pinned locations/chunks
            Page* pinnedPages;        // chain used during GC
            Page* pendingPages;       // chain used during GC
            LispObject pinnedObjects; // chain used during GC
            uintptr_t scanPoint;      // for when GC has parly evacuated page
            uintptr_t dataEnd;        // end of data in this page
            PinStatus borrowStatus;   // used when borrowed page is discarded
            bool liveData;            // is there valid data here?
        };
// Because I am using anonymous structs here I make the names of all the
// initial fields that are expected to be present in every case different
// in each branch of the union.
        struct
        {   PageType Ctype;
            Page* Cchain;
            size_t ChasPinned;
            Page* CpinnedPages;
            Page* CpendingPages;
            LispObject CpinnedObjects;
            uintptr_t CscanPoint;
            uintptr_t CdataEnd;
            PinStatus CborrowStatus;
            bool CliveData;
// The above are the common fields...
            uint64_t consPins[consPinWords];
            uint64_t newConsPins[consPinWords];
            ConsCell consData[consDataCount];
        };
        struct
        {   PageType Vtype;
            Page* Vchain;
            size_t VhasPinned;
            Page* VpinnedPages;
            Page* VpendingPages;
            LispObject VpinnedObjects;
            uintptr_t VscanPoint;
            uintptr_t VdataEnd;
            PinStatus VborrowStatus;
            bool VliveData;
// The above are the common fields.
            bool potentiallyPinnedFlag;
            Page* potentiallyPinnedChain;
            uint64_t newChunkBitmap[chunkBitmapWords];
            uint64_t chunkBitmap[chunkBitmapWords];
            uint32_t chunkLength[chunkInfoSize];
            uint32_t chunkSeqNo[chunkInfoSize];
            uint64_t vecPins[vecPinWords];
            uint64_t newVecPins[vecPinWords];
            Chunk chunks[chunkDataCount];
        };
    };
};

// I now want to find values for ConsN and ChunkN that lead to the
// data in the Page being such that both consData[] and chunks[] run
// right up to the end of a pageSize object. There is no certainty in
// advance that this will be possible. For instance for consData
// most times that ConsN is incremented that adds sizeof(ConsCell) to
// the space used, but one time in 64 it adds an extra 8 bytes. What that
// happens that could skip past the target size. In such a case in order
// to fill right up to pageSize I would need to insert an item somewhere
// to pad the previous case up to the right size. And whether or not that
// was needed can depend on just how much space is used by the common
// header fields and also whether I am on a 32 or 64-bit system. Well
// I am going to argue that this would only arise about 1 time in 64 for
// each for each word-length considered. Similar issues arise in the
// ChunkN case but the fact that the array of Chunks will end up aligned
// on 16Kbyte boundaries means that the chances of difficulty are very
// low.

// I use template meta-programming to find the values I need.

// With meta-programming one NEEDS some debugging tools!
// I want to see the value of (eg) sizeof(Page) at compile-time. C++ does
// not have a built-in static_print function to help me, but
// https://stackoverflow.com/questions/28852574/
//         how-to-print-result-of-a-compile-time-calculation-in-c
// contained a suggestion that works with g++ and clang++ by putting the
// value of interest into a part of a warning about an unused variable.
// There are other suggestions that use errors rather than warnings,
// but this seems gentler to me.

// I find that if I have two uses of static_print both of which happen to
// want to display the same value that the template expansions match well
// enough that only one survives. The result is that one of the messages
// is omitted. To make me feel happier about things I have two copies
// called static_print and static_print1 which use different names
// internally and so avoid this effect.

#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a ## b
#define UNIQUE(base) CONCAT(base, __LINE__)
template <size_t val> constexpr void s_p_f()
{
#ifndef __clang__
// clang does not support this trick nicely!
    int unused = 0;
#endif // !__clang__
};
#define static_print(v) \
  UNUSED_NAME static void UNIQUE(s_p_)() { s_p_f<v>(); }
template <size_t val1> constexpr void s_q_f()
{
#ifndef __clang__
    int unused1 = 0;
#endif // !__clang__
};
#define static_print1(v) \
  UNUSED_NAME static void UNIQUE(s_q_)() { s_q_f<v>(); }

// This next template finds a value of ConsN that will fill up the
// Page nicely.

template <size_t ConsN, size_t TargetSize, size_t Gap>
class FindConsN
{   using Page = PageTemplate<ConsN, 1>;
    enum { W = TargetSize -
               offsetof(Page,consData) -
               sizeof(Page::consData) };
public:
    enum { value = FindConsN<W==0  ? ConsN :
                            (W>16) ? ConsN + W/(sizeof(ConsCell)+2) :
                                     ConsN + 1,
                            TargetSize, W>::value };
};

template <size_t ConsN, size_t TargetSize>
class FindConsN<ConsN,TargetSize,0>
{
public:
    enum { value = ConsN };
};

INLINE_VAR const size_t ConsN = FindConsN<1,pageSize,1>::value;
//static_print(ConsN);

template <size_t ChunkN, size_t TargetSize, size_t Gap>
class FindChunkN
{   using Page = PageTemplate<1,ChunkN>;
    enum { W = TargetSize -
               offsetof(Page,chunks) -
               sizeof(Page::chunks) };
public:
    enum { value = FindChunkN<W==0             ? ChunkN :
                              (W>10*chunkSize) ? ChunkN + W/(chunkSize+2000) :
                                                 ChunkN + 1,
                              TargetSize, W>::value };
};

template <size_t ChunkN, size_t TargetSize>
class FindChunkN<ChunkN,TargetSize,0>
{
public:
    enum { value = ChunkN };
};

INLINE_VAR const size_t ChunkN = FindChunkN<1,pageSize,1>::value;
//static_print(ChunkN);

typedef PageTemplate<ConsN,ChunkN> Page;

INLINE_VAR const size_t consPinBits     = Page::consDataCount;
INLINE_VAR const size_t consPinBytes    = Page::consPinWords*8;
INLINE_VAR const size_t vecPinBytes     = Page::vecPinWords*8;
INLINE_VAR const size_t chunkInfoSize   = Page::chunkInfoSize;
INLINE_VAR const size_t chunkBitmapBits = Page::chunkDataCount;


// So "just for fun and to show off" I will generate a warning message
// here (if using gcc or clang) that includes the size of various
// aspects of the Page class.
//static_print(offsetof(Page,consData)+sizeof(Page::consData) - pageSize);
//static_print1(offsetof(Page,chunks)+sizeof(Page::chunks) - pageSize);

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
    bool contains(Page* a);
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
extern Page* oldVecPinPages;       // For GC.

inline uintptr_t endOfConsPage(Page* p)
{   return bit_cast<uintptr_t>(p) +
           offsetof(Page, consData) + sizeof(Page::consData);
}

inline uintptr_t endOfVecPage(Page* p)
{   return bit_cast<uintptr_t>(p) +
           offsetof(Page, chunks) + sizeof(Page::chunks);
}

inline bool PageList::contains(Page* p)
{   for (Page* p1=head; p1!=nullptr; p1=p1->chain)
        if (p == p1) return true;
    return false;
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
{  return bit_cast<Page*>(a & (-pageSize));
}

inline size_t chunkNoFromAddress(Page* p, uintptr_t a)
{   return (a - bit_cast<uintptr_t>(&p->chunks[0]))/chunkSize;
}

inline size_t chunkNoFromAddress(uintptr_t a)
{   return chunkNoFromAddress(pageOf(a), a);
}

inline uintptr_t addressFromChunkNo(Page* p, size_t n)
{   return bit_cast<uintptr_t>(&p->chunks[0]) + chunkSize*n;
}

inline bool chunkIsNewPinned(Page* p, uintptr_t a)
{   return testBit(p->newChunkBitmap, chunkNoFromAddress(p, a));
}

inline void chunkSetNewPinned(Page* p, uintptr_t a)
{   setBit(p->newChunkBitmap, chunkNoFromAddress(p, a));
}

inline void chunkClearNewPinned(Page* p, uintptr_t a)
{   clearBit(p->newChunkBitmap, chunkNoFromAddress(p, a));
}

inline bool chunkNoIsNewPinned(Page* p, size_t chunkNo)
{   return testBit(p->newChunkBitmap, chunkNo);
}

inline void chunkNoSetNewPinned(Page* p, size_t chunkNo)
{   setBit(p->newChunkBitmap, chunkNo);
}

inline void chunkNoClearNewPinned(Page* p, size_t chunkNo)
{   clearBit(p->newChunkBitmap, chunkNo);
}

inline bool chunkIsPinned(Page* p, uintptr_t a)
{   return testBit(p->chunkBitmap, chunkNoFromAddress(p, a));
}

inline void chunkSetPinned(Page* p, uintptr_t a)
{   setBit(p->chunkBitmap, chunkNoFromAddress(p, a));
}

inline void chunkClearPinned(Page* p, uintptr_t a)
{   clearBit(p->chunkBitmap, chunkNoFromAddress(p, a));
}

inline bool chunkNoIsPinned(Page* p, size_t chunkNo)
{   return testBit(p->chunkBitmap, chunkNo);
}

inline void chunkNoSetPinned(Page* p, size_t chunkNo)
{   setBit(p->chunkBitmap, chunkNo);
}

inline void chunkNoClearPinned(Page* p, size_t chunkNo)
{   clearBit(p->chunkBitmap, chunkNo);
}

inline size_t consToOffset(uintptr_t a, Page* p)
{   return (a - bit_cast<uintptr_t>(&p->consData)) / sizeof(ConsCell);
}

inline uintptr_t offsetToCons(size_t o, Page* p)
{   return bit_cast<uintptr_t>(&p->consData) + sizeof(ConsCell)*o;
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
{   return (a - bit_cast<uintptr_t>(&p->chunks)) / sizeof(LispObject);
}

inline uintptr_t offsetToVec(size_t o, Page* p)
{   return bit_cast<uintptr_t>(&p->chunks) + sizeof(LispObject)*o;
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

extern uintptr_t consFringe, consLimit, consEnd;

extern uintptr_t consEndOfPage();
extern void garbage_collect();
extern void garbage_collect(const char* why);

extern uintptr_t vecFringe, vecLimit, vecEnd;
extern uintptr_t borrowFringe, borrowLimit, borrowEnd;

inline void displayConsPage(Page* p)
{   zprintf("Cons page %a type=%s\n", p, pageTypeName(p->type));
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowStatus=%s\n", p->borrowStatus);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("pinnedObjects = %a\n", p->pinnedObjects);
    zprintf("scanPoint=%a dataEnd=%a fr=%a lim=%a\n",
        p->scanPoint, p->dataEnd, consFringe, consLimit); 
    LispObject prevCar = 0, prevCdr = 0;
    prevCar = ~p->consData[0].car; // so it is NOT the start of a run
    size_t repeats = 0;
    for (uintptr_t q=offsetToCons(0, p);
                   q<p->dataEnd && q!=consFringe;
                   q+=sizeof(ConsCell))
    {   if (car(q) == prevCar && cdr(q) == prevCdr) repeats++;
        else
        {   if (repeats != 0) zprintf(" ... and %d repeats\n", repeats);
            const char* s;
            if (consIsPinned(q, p))
                if (consIsNewPinned(q, p)) s = "!|";
                else s = "!";
            else if (consIsNewPinned(q, p)) s = "|";
            else s = "";
            zprintf("%a%s: %a@%s  .  %a@%s\n",
                q, s, prevCar=car(q), objectType(car(q)),
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
{   zprintf("Vec page %a type=%s\n", p, pageTypeName(p->type));
    zprintf("chain = %a\n", p->chain);
    zprintf("borrowStatus=%s\n", p->borrowStatus);
    zprintf("hasPinned = %s\n", p->hasPinned);
    zprintf("pinnedPages = %a\n", p->pinnedPages);
    zprintf("pendingPages = %a\n", p->pendingPages);
    zprintf("pinnedObjects = %a\n", p->pinnedObjects);
    zprintf("scanPoint=%a dataEnd=%a fr=%a lim=%a\n",
        p->scanPoint, p->dataEnd, vecFringe, vecLimit);
    zprintf("potentiallPinnedFlag = %s\n", p->potentiallyPinnedFlag);
    zprintf("potentiallPinnedChain = %a\n", p->potentiallyPinnedChain);
    zprintf("chunkPins:\n");
    size_t q = 0;
    while ((q = nextOneBit(p->chunkBitmap, chunkBitmapBits, q)) != SIZE_MAX)
    {   zprintf("chunkBitmap[%d] set (%a)\n", q, addressFromChunkNo(p, q));
        q++;
    }
    zprintf("newChunkPins:\n");
    q = 0;
    while ((q = nextOneBit(p->newChunkBitmap, chunkBitmapBits, q)) != SIZE_MAX)
    {   zprintf("newChunkBitmap[%d] set (%a)\n", q, addressFromChunkNo(p, q));
        q++;
    }
    unsigned int n = 0;
    for (size_t i=0; i<chunkInfoSize; i++)
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
    for (uintptr_t q=offsetToVec(0, p);
                   q<p->dataEnd && q!=vecFringe;
                   q+=sizeof(uintptr_t))
    {   uintptr_t n = *bit_cast<uintptr_t*>(q);
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
            const char* s;
            if (vecIsPinned(q, p))
                if (vecIsNewPinned(q, p)) s = "!|";
                else s = "!";
            else if (vecIsNewPinned(q, p)) s = "|";
            else s = "";
            if (std::strcmp(ff, "unknown") == 0)
                zprintf("%a%s: %a %s", q, s, n, objectType(n));
            else zprintf("%a%s: %a %s", q, s, n, ff);
            prev = n;
            count = 1;
            if (symhdr > 0) symhdr++;
            if (streamhdr > 0) streamhdr++;
        }
        else count++;
    }
    if (count != 1) zprintf(" * %d\n", count);
    else zprintf("\n");
    zprintf("end of page %a\n\n", p);
}

inline void displayAllPages(const char* s)
{   zprintf("displayAllPages %s\n", s);
    int k = 0;
    for (auto p:list_bases)
        zprintf("%s: %a\n", list_names[k++], *p);
    zprintf("\nconsPages......");
    for (auto p:consPages)
    {   if (p == consCurrent) zprintf(" *%a_%d", p, p->hasPinned);
        else zprintf(" %a_%d", p, p->hasPinned);
    }
    zprintf("\n");
    for (auto p:consPages)
    {   if (p == consCurrent) zprintf("*** consCurrent ***\n");
        my_assert(p->type == consPageType, "page has incorrect type");
        displayConsPage(p);
    }
    zprintf("\nvecPages......");
    for (auto p:vecPages)
    {   if (p == vecCurrent) zprintf(" *%a_%d", p, p->hasPinned);
        else zprintf(" %a_%d", p, p->hasPinned);
    }
    zprintf("\n");
    for (auto p:vecPages)
    {   if (p == vecCurrent) zprintf("*** vecCurrent ***\n");
        my_assert(p->type == vecPageType, "page has incorrect type");
        displayVecPage(p);
    }
    zprintf("\nconsOldPages......");
    for (auto p:consOldPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:consOldPages)
    {   my_assert(p->type == consPageType, "page has incorrect type");
        displayConsPage(p);
    }
    zprintf("\nvecOldPages......");
    for (auto p:vecOldPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:vecOldPages)
    {   my_assert(p->type == vecPageType, "page has incorrect type");
        displayVecPage(p);
    }
    zprintf("\nconsPinPages......");
    for (auto p:consPinPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:consPinPages)
    {   my_assert(p->type == consPageType, "page has incorrect type");
        displayConsPage(p);
    }
    zprintf("\nvecPinPages......");
    for (auto p:vecPinPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:vecPinPages)
    {   my_assert(p->type == vecPageType, "page has incorrect type");
        displayVecPage(p);
    }
    zprintf("\nconsCloggedPages......");
    for (auto p:consCloggedPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:consCloggedPages)
    {   my_assert(p->type == consPageType, "page has incorrect type");
        displayConsPage(p);
    }
    zprintf("\nvecCloggedPages......");
    for (auto p:vecCloggedPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    for (auto p:vecCloggedPages)
    {   my_assert(p->type == vecPageType, "page has incorrect type");
        displayVecPage(p);
    }
    zprintf("\nemptyPages......");
    for (auto p:emptyPages) zprintf(" %a_%d", p, p->hasPinned);
    zprintf("\n");
    zprintf("gcNumber = %d\n", gcNumber);
    zprintf("end of display\n\n");
}

extern bool withinGarbageCollector;

// The class here is to ensure that the flag gets reset when GC terminates.

class WithinGarbageCollector
{
public:
    WithinGarbageCollector()
    {   my_assert(!withinGarbageCollector, "Attempt to recurse into GC");
        withinGarbageCollector = true;
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
        consFringe += sizeof(ConsCell);
// Now if the Page is full I need to try to allocate another, and if that
// does not make sense I will have to garbage collect.
    if (consFringe == consEnd) return consEndOfPage();
// When I skip pinned data and if there is space beyond same then the first
// word of that region holds a pointer showing where the next usable
// section of memory ends.
    consLimit = indirect(consFringe);
// Now I can allocate.
    uintptr_t r = consFringe;
    consFringe += sizeof(ConsCell);
    return r;
}

// This is the main function for allocating CONS cells and any
// other item that only use up 2 cells. I hope it will often have
// calls to it expanded inline. If harderGet2Words remains a function
// call that does not matter much.

extern uintptr_t consCounter;

inline uintptr_t get2Words()
{
#ifdef DEBUG
    consCounter++;
    if (garbage_collection_permitted &&
        !withinGarbageCollector &&
        consCounter==gcEvery)
    {   garbage_collect("gc-every");
        consCounter = 0;
    }
#endif // DEBUG
    uintptr_t r = consFringe;
    if (r < consLimit)
    {   consFringe += sizeof(ConsCell);
        return r;
    }
    return harderGet2Words();
}

// The next two may provide very minor speedup for list2 and list3 in what
// I hope will be the common case where allocation can be sequential. They
// have to be calle din two steps - the first will check if the second would
// be valid.

inline bool get4WordsValid()
{   return consFringe + sizeof(ConsCell) < consLimit;
}

inline uintptr_t get4Words()
{   uintptr_t r = consFringe;
    consFringe += 2*sizeof(ConsCell);
    return r;
}

inline bool get6WordsValid()
{   return consFringe + 2*sizeof(ConsCell) < consLimit;
}

inline uintptr_t get6Words()
{
    uintptr_t r = consFringe;
    consFringe += 3*sizeof(ConsCell);
    return r;
}

inline Header makeHeader(size_t n, int type)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + type;
}

// At times I want to put a vector header at the start of a block of
// memory. This does the job. Note that a is an untagged pointer here.

inline void setHeaderWord(uintptr_t a, size_t n, int type=TYPE_PADDER)
{   my_assert((n & (-CELL)) == n, "odd size to setHeaderWord");
    indirect(a) = makeHeader(n, type);
#ifdef EXTREME_DEBUG
// The idea here is to fill all the cells that are unused (as marked by
// use of a padder vector) with data that is otherwise improbable and that
// is liable to cause a prompt disaster if encountered.
    if (type==TYPE_PADDER)
    {   for (size_t i=CELL; i<n; i+=CELL)
            indirect(a+i) = 0xfeedadeadbeefc03;
    }
#endif // EXTREME_DEBUG
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
        my_assert(fringe <= limit, where("fringe < limit"));
        my_assert(fringe > (uintptr_t)current &&
                  fringe <= (uintptr_t)(current+1), where("fringe not in current page"));
// Now I will see if the new item will fit within the current chunk. Note
// that this test applies whether I am in a basic chunk or at the end of
// an extended one. The chunkSeqNo[] entry must already be set up and
// for an unused region that was always initialised to 0 so in the easy
// case I do not need to set or re-set it.
// The test against limit is needed because a previous allocation may have
// totally filled eg the last chunk on the page.
        if ((r&chunkMask) + n <= chunkSize && r!=limit)
        {   fringe += n;
            my_assert(fringe <= limit, __WHERE__);
            return r;
        }
// Here either the request will not fit in the current chunk or really there
// is no current chunk. Insert a padder in the former case. Note that
// if r!=limit there is at least a bit of space that needs a padder.
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
// requires chunkSeqNo[] to have been initialised to 0 all
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
// need to use chunkPinmap and chunkLength to find how far I can really go.
        size_t chunkNo = chunkNoFromAddress(current, fringe);
// chunkNo is now the number of the chunk that I had reached at limit. I
// will skip over any pinned chunks (they must be pinned because I hit
// the limit). Note that while I am allocating I use chunkPinmap, not the
// "new" version (which gets involved while I am in the garbage collector).
        while (chunkNoIsPinned(current, chunkNo))
            chunkNo += current->chunkLength[chunkNo]; // Skip any pinned
// Now I know where the next available region starts. Find its end.
// That will let me set fresh values for fringe and limit.
        size_t stopPoint = nextOneBit(current->chunkBitmap,
                                      chunkInfoSize,
                                      chunkNo);
        if (stopPoint == SIZE_MAX) stopPoint = chunkInfoSize; 
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
// It should not be necessary to write back a zero against the initial
// part of a chunk, but it feels clearer to me if I do so.
                for (size_t i=0; i<chunksNeeded; i++)
                    current->chunkSeqNo[chunkNo+i] = i;
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
{
#ifdef DEBUG
    consCounter++;
    if (garbage_collection_permitted &&
        !withinGarbageCollector &&
        consCounter==gcEvery)
    {   garbage_collect("gc-every");
        consCounter = 0;
    }
#endif // DEBUG
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
                          vecLimit, vecEnd, false)) == 0)
    {
// Here vecFringe should point at the start of a chunk just beyond
// all the ones that are in use.
        vecCurrent->dataEnd = vecFringe;
        if (GCTRACE) zprintf("set %a dataEnd = %a\n", vecCurrent, vecFringe);
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

inline void setVecFringeAndLimit(Page* p, uintptr_t& fringe, uintptr_t& limit)
{   size_t chunk = 0;
// First skip any initial pinned chunks.
    while (chunk<chunkInfoSize && chunkNoIsPinned(p, chunk))
        chunk+=p->chunkLength[chunk];
// Now find the next pinned chunk beyond that, if there is one.
    size_t end = nextOneBit(p->chunkBitmap, chunkBitmapBits, chunk);
    p->scanPoint = fringe = addressFromChunkNo(p, chunk);
    if (end == SIZE_MAX) limit = endOfVecPage(p);
    else limit = addressFromChunkNo(p, end);
}

inline Page* initBorrowPage(Page* p, PinStatus status)
{
// borrowed pages do not need anything like as much initialisation since
// they will never participate in GC. However they must have chunkStatus
// set up since that is inspected in case there might have been pinned
// items within them.
    borrowCurrent = p;
    borrowPages.push(p);
    borrowCurrent = p;
    p->borrowStatus = status;
    borrowEnd = bit_cast<uintptr_t>(p) + pageSize;
    if (status == wasEmpty)
    {
// I do not need to do anything with pinning bitmaps here, but I must
// initialise chunkInfo since that is used during allocation.
        for (size_t i=0; i<chunkInfoSize; i++)
        {   p->chunkSeqNo[i] = 0;
            p->chunkLength[i] = 1;
        } 
        borrowFringe = p->scanPoint = offsetToVec(0, p);
        borrowLimit = borrowEnd;
    }
    else setVecFringeAndLimit(p, borrowFringe, borrowLimit);
//  displayVectorPage(p);
    return p;
}

inline void grabBorrowPage()
{   if (!emptyPages.isEmpty()) initBorrowPage(emptyPages.pop(), wasEmpty);
    else if (pageFringe != pageEnd) initBorrowPage(pageFringe++, wasEmpty);
    else if (!vecPinPages.isEmpty()) initBorrowPage(vecPinPages.pop(), wasPinned);
    else if (!vecCloggedPages.isEmpty()) initBorrowPage(vecCloggedPages.pop(), wasClogged);
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
    Page* previous;
public:
    Borrowing()
    {   previous = borrowPages.head;
        grabBorrowPage();
    }
    ~Borrowing()
    {   while (borrowPages.head != previous)
        {   Page* p = borrowPages.pop();
            switch (p->borrowStatus)
            {
            default:
                my_abort(where("Bad status on borrowed page"));
            case wasClogged:
                vecCloggedPages.push(p);
                return;
            case wasPinned:
                vecPinPages.push(p);
                return;
            case wasEmpty:
                emptyPages.push(p);
                return;
            }
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
{   if (get4WordsValid()) LIKELY
    {   LispObject r1 = get4Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, nil);
        return r1;
    }
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, nil);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   if (get4WordsValid()) LIKELY
    {   LispObject r1 = get4Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, c);
        return r1;
    }
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, c);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b,
                               LispObject a)
{   if (get4WordsValid()) LIKELY
    {   LispObject r1 = get4Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, c);
        return r1;
    }
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, c);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c,
                            LispObject d)
{   if (get6WordsValid()) LIKELY
    {   LispObject r1 = get6Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        LispObject r3 = r2 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, r3);
        setcar(r3, c);
        setcdr(r3, d);
        return r1;
    }
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r3, c);
    setcdr(r3, d);
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, r3);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
    return r1;
}

inline LispObject list4(LispObject a, LispObject b, LispObject c,
                        LispObject d)
{   LispObject w = list2(c, d);
    return list2star(a, b, w);
}

inline LispObject acons(LispObject a, LispObject b, LispObject c)
{   if (get4WordsValid()) LIKELY
    {   LispObject r1 = get4Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        setcar(r1, r2);
        setcdr(r1, c);
        setcar(r2, a);
        setcdr(r2, b);
        return r1;
    }
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, a);
    setcdr(r2, b);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, r2);
    setcdr(r1, c);
    return r1;


}

inline LispObject acons_no_gc(LispObject a, LispObject b,
                              LispObject c)
{   return acons(a, b, c);
}

inline LispObject list3(LispObject a, LispObject b, LispObject c)
{   if (get6WordsValid()) LIKELY
    {   LispObject r1 = get6Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        LispObject r3 = r2 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, r3);
        setcar(r3, c);
        setcdr(r3, nil);
        return r1;
    }
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r3, c);
    setcdr(r3, nil);
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, r3);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   if (get6WordsValid()) LIKELY
    {   LispObject r1 = get6Words() + TAG_CONS;
        LispObject r2 = r1 + sizeof(ConsCell);
        LispObject r3 = r2 + sizeof(ConsCell);
        setcar(r1, a);
        setcdr(r1, r2);
        setcar(r2, b);
        setcdr(r2, r3);
        setcar(r3, c);
        setcdr(r3, nil);
        return r1;
    }
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r3, c);
    setcdr(r3, nil);
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r2, b);
    setcdr(r2, r3);
    LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, r2);
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
{   if (p < bit_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int findSegment4(uintptr_t p, int n)
{   if (p < bit_cast<uintptr_t>(heapSegment[n+2]))
        return findSegment2(p, n);
    else return findSegment2(p, n+2);
}

inline int findSegment8(uintptr_t p, int n)
{   if (p < bit_cast<uintptr_t>(heapSegment[n+4]))
        return findSegment4(p, n);
    else return findSegment4(p, n+4);
}

inline int findSegment16(uintptr_t p, int n)
{   if (p < bit_cast<uintptr_t>(heapSegment[n+8]))
        return findSegment8(p, n);
    else return findSegment8(p, n+8);
}

inline int findHeapSegment(uintptr_t p)
{   int n = findSegment16(p, 0);
    if (p < bit_cast<uintptr_t>(heapSegment[n]) ||
        p >= bit_cast<uintptr_t>(heapSegment[n]) +
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
    {   uintptr_t segBase = bit_cast<uintptr_t>(heapSegment[hs]);
        uintptr_t o = p - segBase;
        uintptr_t pNum = o/pageSize;
        Page* pp = bit_cast<Page*>(segBase + pNum*pageSize); 
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
                "#%" PRIxPTR ":%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 80,
                "#[%d]: %" PRIxPTR ":%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pOff == 0)
        {   if (hs == 0) std::snprintf(r, 80, "#%" PRIxPTR "^:", pNum);
            else std::snprintf(r, 80, "#[%d]: %" PRIxPTR "^:", hs, pNum);
            return r;
        }
    }
    else if ((p & (pageSize-1)) == 0)
    {   int hs1 = findHeapSegment(p-pageSize);
        if (hs1 != -1)
        {   uintptr_t segBase = bit_cast<uintptr_t>(heapSegment[hs1]);
            uintptr_t o = p - segBase;
            uintptr_t pNum = o/pageSize;
            if (hs == 0) std::snprintf(r, 80, "#%" PRIxPTR ": end:", pNum);
            else std::snprintf(r, 80, "#[%d]%" PRIxPTR ": end:", hs1, pNum);
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
{    return bit_cast<uintptr_t>(heapSegment[0]) + pageSize*p + o;
}

// .. and extra for the case of addresses in segments 1 and beyond.

inline uintptr_t unAddr(unsigned int s, uintptr_t p, uintptr_t o)
{    return bit_cast<uintptr_t>(heapSegment[s]) + pageSize*p + o;
}

// This finds a page that a potential pointer p is within, or returns nullptr
// if there is not one

inline Page* findPage(uintptr_t p)
{   int n = findHeapSegment(p);
    if (n < 0) return nullptr;
    return bit_cast<Page*>(p & -pageSize);
}

#endif // header_newallocate_h

// end of newallocate.h
