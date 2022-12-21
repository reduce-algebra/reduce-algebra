// newallocate.cpp                         Copyright (C) 2018-2022 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//

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

/*!!! csl
*/

#include "headers.h"

#ifdef HAVE_CXX17

// In code that at present (February 2021) is disabled with "#if 0"
// I use the Mersenne Twister generator as set up in arithlib.hpp
// to set up some randomized testing for this code.

#ifndef LISP
#define LISP 1
#endif // !LISP
#ifndef CSL
#define CSL 1
#endif // !CSL
#include "arithlib.hpp"  // For random number support
#endif

Page* consCurrent;
Page* vecCurrent;
Page* borrowCurrent;
unsigned int borrowingDepth = 0;

PageList emptyPages;
PageList consPinPages;
PageList vecPinPages;
PageList consCloggedPages;
PageList vecCloggedPages;
PageList consPages;
PageList vecPages;
PageList consOldPages;
PageList vecOldPages;
PageList borrowPages;
Page*    potentiallyPinned;
Page*    pinnedPages;
Page*    pendingPages;
Page*    oldVecPinPages;

uintptr_t consFringe, consLimit, consEnd;
uintptr_t vecFringe, vecLimit, vecEnd;
uintptr_t borrowFringe, borrowLimit, borrowEnd;

uintptr_t consCounter = 0;

#ifdef DEMONSTRATE_STATIC_PRINT
// Here I will have a demonstration of my "static_print" mechanism that
// causes g++ or clang++ to generate a warning message that includes the
// numeric value give. Note that I hope the two "gap" values are both 0.
// This works in an interesting way with gcc but less so with clang.

#pragma message ("ConsN ChunkN and 2 gaps at end of a Page")
static_print(ConsN);
static_print(ChunkN);
static_print(offsetof(Page,consData)+sizeof(Page::consData) - pageSize);
static_print1(offsetof(Page,chunks)+sizeof(Page::chunks) - pageSize);
#endif // DEMONSTRATE_STATIC_PRINT

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
#ifdef ARITHLIB
    static int count = 0;
    if (type == TYPE_BIGNUM && garbage_collection_permitted && ++count < 10)
        zprintf("creating old style bignum @" LOCATION "\n");
#endif // ARITHLIB
// tag is the value (e.g. TAG_VECTOR) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_STRING) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
    size_t allocSize = (size_t)doubleword_align_up(size);
// There is a limit to the size of the region within a page that chunks can
// be put in while allowing for page headers and the like. That turns
// out to be 7904 Kbytes and so is the real limit. For Lisp vectors
// this is not an important limit because big vectors and hash
// tables are stored in chunks rather smaller than that. But for
// arithmetic this sets a limit on the largest representable integer such
// that it will have between 19 and 20 million (decimal) digits.
    if (allocSize > vecDataSize)
        return aerror1("request for basic vector too big",
                       fixnum_of_int(allocSize/CELL-1));
// Note that allocSize has been rounded up suitably.
    LispObject r = getNBytes(allocSize);
    *(reinterpret_cast<Header*>(r)) =
        type + (size<<(Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ. Well with a
// conservative GC the junk values should no actually cause breakage, but they
// can cause stuff to be pinned and hence preserved when I do not want that.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multiple of 8 bytes long naturally
// gets padded out.
#ifdef DEBUG
   for (size_t i=CELL; i<allocSize; i+=4)
       *reinterpret_cast<uint32_t*>(r+i) = 0xfeedface;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *reinterpret_cast<LispObject*>(r+allocSize-CELL) = 0xdeadbeef;
#endif // DEBUG
    return static_cast<LispObject>(r + tag);
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors. This is ONLY used when a hash table
// finds that the number of items in it has decreased dramatically and it
// wants to shrink. For big tables the index vector will decrease in size
// but each sub-vector stored in it will remain as it is. For smaller tables
// it can be the table itself that shrinks. When a vector shrinks I should
// put a padder in the vacated space so that it will still be possible to
// do linear scans of memory.

LispObject reduce_basic_vector_size(LispObject v, size_t len)
{   size_t oldlen = doubleword_align_up(length_of_header(vechdr(v)));
    setvechdr(v, TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED);
    len = doubleword_align_up(len);
    if (len != oldlen) setvechdr(v + len, makeHeader(oldlen-len, TYPE_PADDER));
    return v;
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   size_t allocSize = (size_t)doubleword_align_up(size);
    if (allocSize > (CSL_PAGE_SIZE - 32))
        return aerror1("request for basic vector too big",
                       fixnum_of_int(allocSize/CELL-1));
    LispObject r = borrowNBytes(allocSize);
    *(reinterpret_cast<Header*>(r)) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *reinterpret_cast<LispObject*>(r+allocSize-CELL) = 0;
    return static_cast<LispObject>(r + tag);
}

LispObject borrow_vector(int tag, int type, size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n-CELL+VECTOR_CHUNK_BYTES-1)/VECTOR_CHUNK_BYTES;
        size_t lastSize = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (lastSize == 0) lastSize = VECTOR_CHUNK_BYTES;
        LispObject v =
            borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (size_t i=0; i<chunks; i++)
        {   size_t k = i==chunks-1 ? lastSize : VECTOR_CHUNK_BYTES;
            basic_elt(v, i) = borrow_basic_vector(tag, type, k+CELL);
        }
        return v;
    }
    else return borrow_basic_vector(tag, type, n);
}

// This code allocates a segment by asking the operating system.
// It grabs a block that is aligned to sizeof(Page).
// The collection of segments must be stored in heapSegments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.
//
// Returns false and does nothing if it can not grab the memory.
// If this does manage to allocate a new segment it sets pageFringe to
// the start of it and pageEnd to the end. So in general this should not
// be called until the previous segment has been fully allocated and
// pageFringe==pageEnd.

void* heapSegment[16];
char* heapSegmentBase[16];
size_t heapSegmentSize[16];
size_t heapSegmentCount = 0;

// This next tracks how much memory has been grabbed from the operating
// system, and accounts for it in units of Page.
size_t totalAllocatedMemory = 0;
bool memorySeemsFull = false;

Page* pageFringe = nullptr;
Page* pageEnd = nullptr;

bool allocateSegment(size_t n)
{   my_assert(pageFringe == pageEnd, where("pageFringe != pageEnd"));
// I will round up the size to allocate so it is a multiple of the
// page size, ie of 8 Mbytes.
    n = (n+pageSize-1) & -pageSize;
    Page* r;
// If I have C++17 I can rely on alignment constraints and just allocate
// using new[]. And for this CONSERVATIVE version I will insist on C++17,
// at least until it is all working at which stage I can check how much pain
// there would be in using older compilers.
#ifdef MACINTOSH
// I would like to use aligned allocation via "new" in the C++17 style, but
// on the Macintosh that is only supported if your operating system is at
// least 10.14. That is your operating system not a constraint on the release
// of the C++ compiler and library! For backwards compatibility at present I
// set a deployment target of 10.13 so I have to do something different here!
    {   size_t sz = n+pageSize-1;
        char* tr = new (std::nothrow) char[sz];
        heapSegmentBase[heapSegmentCount] = tr;
        void* trv = reinterpret_cast<void*>(tr);
        std::align(pageSize, n*pageSize, trv, sz);
        r = reinterpret_cast<Page*>(trv);
    }
#else // MACINTOSH
    r = new (std::nothrow) Page[n/pageSize];
#endif // MACINTOSH
    totalAllocatedMemory += n/pageSize;    // counting in units of Page. 
    if (r == nullptr) return false;
    heapSegment[heapSegmentCount] = r;
    heapSegmentSize[heapSegmentCount] = n;
    heapSegmentCount++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (size_t i=heapSegmentCount-1; i!=0; i--)
    {   int j = i-1;
        void* h1 = heapSegment[i],* h2 = heapSegment[j];
        if (reinterpret_cast<uintptr_t>(h2) < reinterpret_cast<uintptr_t>(h1))
            break; // Ordering is OK
// The segment must sink a place in the tables.
        std::swap(heapSegment[i], heapSegment[j]);
        std::swap(heapSegmentSize[i], heapSegmentSize[j]);
    }
// r now refers to a new segment of size n.
    pageFringe = r;
    pageEnd = &r[n/pageSize];
    while (pageFringe != pageEnd)
    {   Page* r = pageFringe++;
        r->type = emptyPageType;
        emptyPages.push(r);
//      zprintf("set up new empty page %a\n", r);
    }
    return true; // Success!
}

// Here I will try allocating a new segment that has size the same as
// all memory allocated to date. I.e. I will try to double the total
// amount of memory allocated. If that is not possible because the
// system refuses to allow allocating that much I will try half that
// increment or a quarter. but after such a fallback I will not try any
// subsequent expansion. This is intended to fill up a decent fraction of
// all available memory. Well it could be that one of the allocations
// succeeds and leaves memory so full that things run into trouble later.
// so MAYBE I need to be a bit mote sophisticated. That could maybe
// especially arise if a computer with limited real memory has been
// given a really large swap file, then this code might expand into
// virtual memory in ways that could be really bad for performance.
// but the max_store_size command-line option will allow me to limit
// things. I grab memory right up to that limit if I can.

bool allocateAnotherSegment()
{   if (memorySeemsFull ||
        (max_store_size != 0.0 && totalAllocatedMemory >= maxPages) ||
        heapSegmentCount == 15) return false;
    size_t inc = totalAllocatedMemory;
    if ((totalAllocatedMemory+inc) > maxPages)
        inc = maxPages - totalAllocatedMemory;
    std::cout << "@@@ Current heap size " << (8*totalAllocatedMemory) << " MB\n";
    if (inc == 0) return false;
    else if (allocateSegment(inc*pageSize)) return true;
    memorySeemsFull = true;
    if (totalAllocatedMemory <= 8) return false;
    else if (allocateSegment(inc*pageSize/2)) return true;
    else if (allocateSegment(inc*pageSize/4)) return true;
    else return false;
}

void initConsPage(Page* p, bool empty)
{   consPages.push(p);
    p->liveData = true;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("Allocate page %a as a CONS page (was %s)\n", p, pageTypeName(p->type));
#endif // EXTREME_DEBUG
    p->type = consPageType;
    consCurrent = p;
    p->dataEnd = consEnd = endOfConsPage(p);
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("set %a dataEnd = %a\n", p, p->dataEnd);
#endif // EXTREME_DEBUG
    if (empty)
    {   p->hasPinned = 0;
        p->pinnedPages = nullptr;
        p->pinnedObjects = TAG_FIXNUM;
        std::memset(p->consPins, 0, sizeof(p->consPins));
        std::memset(p->newConsPins, 0, sizeof(p->newConsPins));
        consFringe = p->scanPoint = offsetToCons(0, p);
        consLimit = consEnd;
    }
    else
    {   consFringe = p->scanPoint = offsetToCons(0, p);
// Now because this iafe will have had some pinned data in it I need to
// skip any initial pinned locations and set consLimit ahead of any
// subsequent ones.
        while (consFringe < consEnd &&
               consIsPinned(consFringe, consCurrent))
            consFringe += 2*sizeof(LispObject);
// It would be pathological if ALL the page was pinned, and in that case
// it should have ended up in consCloggedPages and not re-issued, but to
// be cautious I will cover that case... In normal cases I will have left
// a reference to the end of free space in the first word of a free block.
        if (consFringe == consEnd) consLimit = consEnd;
        else consLimit = indirect(consFringe);
    }
}

void initVecPage(Page* p, bool empty)
{   vecPages.push(p);
    p->liveData = true;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("Allocate page %a as a VEC page (was %s)\n", p, pageTypeName(p->type));
#endif // EXTREME_DEBUG
    p->type = vecPageType;
    p->dataEnd = endOfVecPage(p);
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("set %a dataEnd = %a\n", p, p->dataEnd);
#endif // EXTREME_DEBUG
    vecCurrent = p;
    vecEnd = endOfVecPage(p);
    if (empty)
    {   p->hasPinned = 0;
        p->pinnedPages = nullptr;
        p->potentiallyPinnedFlag = false;
        p->potentiallyPinnedChain = nullptr;
        p->pinnedObjects = TAG_FIXNUM;
        std::memset(p->vecPins, 0, sizeof(p->vecPins));
        std::memset(p->newVecPins, 0, sizeof(p->newVecPins));
        for (size_t i=0; i<chunkInfoSize; i++)
        {   p->chunkSeqNo[i] = 0;
            p->chunkLength[i] = 1;
        }
        std::memset(p->chunkBitmap, 0, sizeof(p->chunkBitmap));
        std::memset(p->newChunkBitmap, 0, sizeof(p->chunkBitmap));
        vecFringe = p->scanPoint = offsetToVec(0, p);
        vecLimit = vecEnd;
    }
    else setVecFringeAndLimit(p, vecFringe, vecLimit);
    
    my_assert(vecLimit > vecFringe &&
              vecLimit <= vecEnd, where("vecFringe, VecLimit, vecEnd bad"));
//  displayVecPage(p);
}

void initPage(PageType type, Page* p, bool empty)
{   switch (type)
    {
    default:
        my_abort("bad page type in initPage");
    case consPageType:
        initConsPage(p, empty);
        return;
    case vecPageType:
        initVecPage(p, empty);
        return;
    }
}

// This finds another Page to use. If must ensure that there is a Page
// of the specified type set up as current, and it is called when the
// existing current page is full up.
// I use pinned pages first, then free ones and clogged only in extremis.
// When I do not have a page readily to hand the garbage collector is
// invoked - once I am within the GC I will use every bit of memory I
// can and not try a recusive call to the GC!

// canAllocate() checks if it is possible to allocate a page of the
// specified type while then leaving memory such that it ought to be
// possible to run a garbage collection and copy all live data to a
// fresh new half-space.

bool canAllocateSub(PageType type,
    size_t consInUse, size_t vecInUse, size_t consFree, size_t vecFree)
{   size_t reallyFree = emptyPages.count + (pageEnd-pageFringe);

// Account on the basis of taking a new CONS page preferentially from
// consPinPages or consCloggedPages and only from emptyPages if those
// are not available. Then similarly for a vector Page.
    if (type == consPageType)
    {   if (consFree != 0) consFree--;
        else if (reallyFree == 0) return false;
        else reallyFree--;
    }
    else if (vecFree != 0) vecFree--;
    else if (reallyFree == 0) return false;
    else reallyFree--;
// I have now modelled how many pages will have each status after another
// one of the indicated type has been allocated. So now see if I will have
// enough to copy into a new half space... This is achieved by pretending it
// is copying every active cons and vec page that it can and then looking to
// see if it managed to copy them all.
    if (consInUse <= consFree)
    {   consFree -= consInUse;
        consInUse = 0;
    }
    else
    {   consInUse -= consFree;
        consFree = 0;
    }
    if (vecInUse <= vecFree)
    {   vecFree -= vecInUse;
        vecInUse = 0;
    }
    else
    {   vecInUse -= vecFree;
        vecFree = 0;
    }
    if (consInUse <= reallyFree)
    {   reallyFree -= consInUse;
        consInUse = 0;
    }
    else
    {   consInUse -= reallyFree;
        reallyFree = 0;
    }
    if (vecInUse <= reallyFree)
    {   reallyFree -= vecInUse;
        vecInUse = 0;
    }
    else
    {   vecInUse -= reallyFree;
        reallyFree = 0;
    }
    return (consInUse==0 && vecInUse==0);
}

bool canAllocate(PageType type)
{   size_t consInUse = consPages.count;
    size_t vecInUse = vecPages.count;
    if (type == consPageType) consInUse++; else vecInUse++;
    size_t consFree = consPinPages.count + consCloggedPages.count;
    size_t vecFree = vecPinPages.count + vecCloggedPages.count;
    return canAllocateSub(type, consInUse, vecInUse, consFree, vecFree);
}

bool canAllocateAvoidingClogged(PageType type)
{   size_t consInUse = consPages.count;
    size_t vecInUse = vecPages.count;
    if (type == consPageType) consInUse++; else vecInUse++;
    size_t consFree = consPinPages.count;
    size_t vecFree = vecPinPages.count;
    return canAllocateSub(type, consInUse, vecInUse, consFree, vecFree);
}

void grabFreshPage(PageType type)
{   bool mustGrab = withinGarbageCollector;
// When called from within the GC this MUST succeed! So the key issue is
// to trigger a GC early enough to make this so. The criterion I will
// use is to imagine that a page of the specified type gets allocated and
// is then totally filled. Then beyond that there must be enough pages
// to copy all the potentially live data into, allowing for the fact that
// eg a vecPinPage may be mosyly empty but it can only be re-allocated
// as a vector page. I will do any memory expansion after not before
// garbage collection, so the judgement here is to be based on memory
// currently active. I will count in units of Pages rather than anything
// more refined. Note that this is going to mean that if the total allocated
// memory is an odd multiple of the Page size there may be some waste -
// in general "sensible" memory allocations will be at multiples of 16Mb!
    if (mustGrab || canAllocate(type))
    {
// Here I grab a page that is already dedicated to the type of use required
// (ie list or vector) if one is available. When I do that I accept that I
// then have to allocate around the pinned data in it, but I have placed
// any pages that contain painful amounts of pinning on consCloggedPages
// and vecCloggedPages and I only re-use them if I am needing space to
// copy into during garbage collection and there is no alternative.
// The motivation here is to keep emptyPages available for allocation as
// either list of vector ones and so avoid having to fail for lack of space
// for one of the sorts of data while there may be plenty of room for the
// other.
        if (type==vecPageType && !vecPinPages.isEmpty())
        {   Page* r = vecPinPages.pop();
            initPage(type, r, false);
            return;
        }
        if (type==consPageType && !consPinPages.isEmpty())
        {   Page* r = consPinPages.pop();
            initPage(type, r, false);
            return;
        }
// I rather want to use empty pages in preference to clogged ones. So
// if that is possible I will do it.
        if (!canAllocateAvoidingClogged(type) || mustGrab)
        {   if (type==vecPageType && !vecCloggedPages.isEmpty())
            {   Page* r = vecCloggedPages.pop();
                initPage(type, r, false);
                return;
            }
            else if (type==consPageType && !consCloggedPages.isEmpty())
            {   Page* r = consCloggedPages.pop();
                initPage(type, r, false);
                return;
            }
        }
        if (!emptyPages.isEmpty())
        {   Page* r = emptyPages.pop();
            r->type = emptyPageType;
            initPage(type, r, true);
            return;
        }
        if (pageFringe != pageEnd)
        {   Page* r = pageFringe++;
            r->type = emptyPageType;
            initPage(type, r, true);
            return;
        }
        if (type==vecPageType && !vecCloggedPages.isEmpty())
        {   Page* r = vecCloggedPages.pop();
            initPage(type, r, false);
            return;
        }
        if (type==consPageType && !consCloggedPages.isEmpty())
        {   Page* r = consCloggedPages.pop();
            initPage(type, r, false);
            return;
        }
        my_abort(where("I had expected to be able to allocate a Page"));
    }
// Here I need to garbage collect.
    if (withinGarbageCollector) fatal_error(err_no_store_in_gc);
    garbage_collect(type==consPageType ? "list space" : "vector space");
// After garbage collection there had BETTER be some available memory left!
// At the end of garbage collection everything should be ready to do the
// next bit of allocation. And with the space now free should be sufficient
// for the next garbage collection!
// First report on memory use...
// This calculation does not allow for padders that has been put in
// when previously-pinned items are now no longer pinned, and it does not
// include the space used by pinned data in otherwise free pages.
    size_t consUsed = Page::consDataCount*consPages.count -
        (endOfConsPage(consCurrent)-consFringe)/sizeof(ConsCell);
    size_t vecUsed = (chunkSize*Page::chunkDataCount*vecPages.count -
        (endOfVecPage(vecCurrent)-vecFringe))/sizeof(LispObject);
    if (force_verbos)
    {   zprintf("%.3g Mbytes lists, %.3g Mbytes vectors\n",
            consUsed*sizeof(ConsCell)/1024.0/1024.0,
            vecUsed*sizeof(LispObject)/1024.0/1024.0);
        zprintf("Cons just pages = %.3g\n",
            (double)Page::consDataCount*consPages.count*sizeof(ConsCell));
    }

// I try expanding memory with a target that the heap should be at
// most 25% full at the end of GC. Ie that the half-space within which
// I am working be at most 50% full. In the test applied here I am not
// counting cons and vector pages independently and in particular I am
// not worrying about the type-commitment represented by pinned Pages etc.
    if (consPages.count + vecPages.count > totalAllocatedMemory/4 &&
        totalAllocatedMemory < maxPages)
        allocateAnotherSegment();
// I am going to take a somewhat neurotic stance regarding cons pinning...
// I put in a number of padders equal to the total number of pinned cells
// in unused cons pages. The result should be that I will then ALWAYS have
// space for the GC to copy list data. Well I am not 100% careful because
// if there is in fact an extra page or so available here but the current one
// is nearly full I will fill the page up but that may not have reserved
// quite enough space...
    size_t pinCount = 0;
    for (auto p:consPinPages)
        pinCount += countBits(p->consPins, 0, Page::consDataCount-1);
    while (pinCount != 0 &&
           consFringe < consEnd)
    {   uintptr_t r = consFringe;
        if (r < consLimit)
        {   consFringe += sizeof(ConsCell);
            indirect(r) = CONS_PADDER_HEADER;
            pinCount--;
            continue;
        }
        while (consFringe < consEnd &&
               consIsPinned(consFringe, consCurrent))
            consFringe += sizeof(ConsCell);
        if (consFringe == consEnd) break;   // a bit dubious!
        r = consFringe;
        consFringe += 2;
        indirect(r) = CONS_PADDER_HEADER;
        pinCount--;
    }
// I might want to do the same for vector pages...
//
// At the end of GC know that consCurrent and vecCurrent are both active.
// I will want to report a failure if the new half space is too close to
// to being full. The threshold I apply is that there is at least (about)
// a megabyte of both cons and vector space available.
    if (!canAllocate(consPageType) &&
        consFringe > (endOfConsPage(consCurrent) - pageSize/8))
        fatal_error(err_no_store);
    if (!canAllocate(vecPageType) &&
        vecFringe > (endOfVecPage(vecCurrent) - pageSize/8))
        fatal_error(err_no_store);
}

// When I make a page "full" I will put a pointer just beyond the
// last data allocated in it there so that the GC can be aware that
// space beyond that is unused (apart from potential pinned stuff).

uintptr_t consEndOfPage()
{   consCurrent->dataEnd = consFringe;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("set %a dataEnd = %a\n", consCurrent, consCurrent->dataEnd);
#endif // EXTREME_DEBUG
// Maintain a list of all full pages, regardless of type.
    consCurrent->pendingPages = pendingPages;
    pendingPages = consCurrent;
    grabFreshPage(consPageType);
    return get2Words();
}

size_t pages_count = 0;
size_t heap_pages_count = 0;
size_t vheap_pages_count = 0;
bool garbage_collection_permitted = true;
bool force_verbos = false;

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
                     force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return nil;
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   SingleValued fn;
    return Lgc_forcer(env, a, a);
}

LispObject* nilSegment,* stackSegment;

void initHeapSegments(double storeSize)
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double rather
// than as an integer so that overflow is not an issue. The value will
// already have had defaults and limits applied.
{   withinGarbageCollector = false;               // Just to be very clear!
    size_t freeSpace = 1024*static_cast<size_t>(storeSize); // now in bytes
// Now freeSpace is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heapSegmentCount = 0;
// The values I put into heapSegment here are intended to be invalid so
// that if by mischance I try using them I hope to get a crash.
    for (int i=0; i<16; i++)
        heapSegment[i] = reinterpret_cast<void*>(-1);
    emptyPages.head = consPinPages.head = vecPinPages.head =
        consCloggedPages.head = vecCloggedPages.head =
        consPages.head = vecPages.head = borrowPages.head =
        consOldPages.head = vecOldPages.head = pendingPages = nullptr;
    emptyPages.count = consPinPages.count = vecPinPages.count =
        consCloggedPages.count = vecCloggedPages.count =
        consPages.count = vecPages.count = borrowPages.count =
        consOldPages.count = vecOldPages.count = 0;
    potentiallyPinned = pinnedPages = pendingPages = oldVecPinPages = nullptr;
    nilSegment = reinterpret_cast<LispObject*>(
        new (std::nothrow) Align8[(NIL_SEGMENT_SIZE)/8]);
    if (nilSegment == nullptr) fatal_error(err_no_store);
    nil = static_cast<LispObject>((uintptr_t)nilSegment + TAG_SYMBOL);
    stackSegment = reinterpret_cast<LispObject*>(
        new (std::nothrow) Align8[CSL_PAGE_SIZE/8]);
    if (stackSegment == nullptr) fatal_error(err_no_store);
    stackBase = reinterpret_cast<uintptr_t>(stackSegment);
    if (!allocateSegment(freeSpace)) fatal_error(err_no_store);
    grabFreshPage(consPageType);
    grabFreshPage(vecPageType);
    borrowCurrent = nullptr;
}

// This function receives a target heap size in megabytes. If the user
// has specified (using -K) a size then that is given, otherwise the
// default will be half the amount of memory the machine has. Save that
// on a 32-bit system a limit at 1600Mb is set and in all cases the flag
// --maxmem can be used to force a smaller limit.

void init_heap_segments(double d)
{   if (d < 1000.0) zprintf("init_heap_segments %.3g Mbytes\n", d);
    else zprintf("init_heap_segments %.3g Gbytes\n", d/1000.0);
// For historical reasons initHeapSegments takes its size in Kbytes not Mbytes
    initHeapSegments(d*1024.0);
}

LispObject Lgc(LispObject env)
{   return Lgc(env, fixnum_of_int(1));
}

LispObject Lgc(LispObject env, LispObject a)
{   garbage_collect("user request");
    return nil;
}

void dropHeapSegments()
{
    for (size_t i=0; i<heapSegmentCount; i++)
    {
#ifdef MACINTOSH
        delete [] heapSegmentBase[i];
#else // MACINTOSH
        delete [] static_cast<Page*>(heapSegment[i]);
#endif // MACINTOSH
    }
    delete [] reinterpret_cast<Align8*>(nilSegment);
    delete [] reinterpret_cast<Align8*>(stackSegment);
}

void drop_heap_segments()
{   dropHeapSegments();
}

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;
uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

LispObject Lverbos(LispObject env, LispObject a)
// (verbos 0) or (verbos nil)       silent garbage collection
// (verbos 1) or (verbos t)         standard GC messages
// (verbos 2)                       messages when FASL module loaded
// (verbos 4)                       extra timing info for GC process
// These bits can be added to get combination effects, except that
// "4" has no effect unless "1" is present.
{   SingleValued fn;
    int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = static_cast<int>(int_of_fixnum(a));
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return fixnum_of_int(old_code);
}

bool volatile already_in_gc;
bool volatile interrupt_pending;
bool pageFull;

// end of newallocate.cpp
