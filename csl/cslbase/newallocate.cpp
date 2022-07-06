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
// to set up some randomized testing for this code. That will only
// compile if you have a "modern" C++ compiler. For use here arithlib.hpp
// need to know it is being used from within CSL...

#ifndef LISP
#define LISP 1
#endif
#ifndef CSL
#define CSL 1
#endif // CSL
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

int vecStopCache = -1;
int borrowStopCache = -1;

uintptr_t consFringe, consLimit, consEnd;
uintptr_t vecFringe, vecLimit, vecEnd;
uintptr_t borrowFringe, borrowLimit, borrowEnd;

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
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
// Basic vectors must be small enough to be ones that I can allocate.
// There are two potential limitations. One is via the chunkStatus
// array and the scheme I have sets that at 8096 Kbytes...
    if (allocSize > 2*ExtendedChunkMax*chunkSize)
        return aerror1("request for basic vector too big",
                       fixnum_of_int(allocSize/CELL-1));
// The other is the size of the region within a page that chunks can
// be put in while allowing for page headers and the like. That turns
// out to be 7904 Kbytes and so is the real limit. For Lisp vectors
// neither of these are important limits because big vectors and hash
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
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
#ifdef DEBUG
   for (size_t i=CELL; i<allocSize; i+=4)
       *reinterpret_cast<uint32_t*>(r+i) = 0xfeedface;
#endif // DEBUG
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *reinterpret_cast<LispObject*>(r+allocSize-CELL) = 0xdeadbeef;
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
    *(reinterpret_cast<Header*>(r)) = type + (size <<
                                       (Tw+5)) + TAG_HDR_IMMED;
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
size_t heapSegmentCount;

// This next tracks how much memory has been grabbed from the operating
// system, and accounts for it in uints of Page.
size_t totalAllocatedMemory = 0;
bool memorySeemsFull = false;

Page* pageFringe = nullptr;
Page* pageEnd = nullptr;

bool allocateSegment(size_t n)
{   assert(pageFringe == pageEnd);
// I will round up the size to allocate so it is a multiple of the
// page size, ie of 8 Mbytes.
    n = (n + pageSize - 1) & -pageSize;
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
{   size_t maxPages = static_cast<size_t>(max_store_size);
    if (memorySeemsFull ||
        totalAllocatedMemory >= maxPages ||
        heapSegmentCount == 15) return false;
    size_t inc = totalAllocatedMemory;
    if ((totalAllocatedMemory+inc) > maxPages)
        inc = maxPages - totalAllocatedMemory;
    std::cout << "@@@ Current heap size " << (8*totalAllocatedMemory) << " MB\n";
    if (allocateSegment(inc*pageSize)) return true;
    memorySeemsFull = true;
    if (totalAllocatedMemory <= 8) return false;
    else if (allocateSegment(inc*pageSize/2)) return true;
    else if (allocateSegment(inc*pageSize/4)) return true;
    else return false;
}

void initConsPage(Page* p, bool empty)
{   consPages.push(p);
    p->type = consPageType;
    consCurrent = p;
    p->dataEnd = consEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {   p->pinnedObjects = TAG_FIXNUM;
        std::memset(p->consPins, 0, sizeof(p->consPins));
        std::memset(p->newConsPins, 0, sizeof(p->newConsPins));
        consFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->consData);
        consLimit = consEnd;
    }
    else
    {   consFringe = p->scanPoint;
        consLimit = p->initialLimit;
    }
}

// Again pages that have any pinned data in them specify their initial
// fringe and limit in scanPoint and initialLimit.

void initVecPage(Page* p, bool empty)
{   vecPages.push(p);
    p->type = vecPageType;
    vecCurrent = p;
    p->dataEnd = vecEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {   p->potentiallyPinnedFlag = false;
        p->potentiallyPinnedChain = nullptr;
        std::memset(p->vecPins, 0, sizeof(p->vecPins));
        std::memset(p->newVecPins, 0, sizeof(p->newVecPins));
        std::memset(p->chunkStatus, BasicChunk, sizeof(p->chunkStatus));
        std::memset(p->potentiallyPinnedChunks, 0,
                    sizeof(p->potentiallyPinnedChunks));
        vecFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->chunks);
        vecLimit = vecEnd;
    }
    else
    {   vecFringe = p->scanPoint;
        vecLimit = p->initialLimit;
    }
    my_assert(vecLimit > vecFringe &&
              vecLimit <= vecEnd, LOCATION);
//  displayVecPage(p);
}

// This finds another Page to use.
// Within the GC it will be willing to re-use pages that contain
// pinned data, but otherwise it will insist on finding a fully
// empty page, and will invoke the GC when things start to feel a bit
// cluttered.

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

void grabFreshPage(PageType type)
{   bool mustGrab = withinGarbageCollector;
// Ha ha - the careful type-checking in zprintf understands that a
// value of "enum" type is not of "integer" type, so the case gere is
// required!
//  zprintf("grabFreshPage %d\n", static_cast<int>(type));
    size_t busy = emptyPages.count +
        consPinPages.count +
        vecPinPages.count +
        consCloggedPages.count +
        vecCloggedPages.count +
        consPages.count +
        vecPages.count +
        borrowPages.count;
    zprintf("There are %d pages in use of %d\n", busy, totalAllocatedMemory);  
    for (;;)
    {   size_t unused = totalAllocatedMemory - busy;
// If the memory I have allocated thus far is less then 2/3 full I will
// merely try to grab an empty page from the spare space. I will
// use emptyPages that have been used before for choice, but when there are
// none of those I will gust use the next Page in the currently partly used
// Segment. Here I will only ever return a fully empty Page, never one that
// contains any pinned data.
#ifdef DEBUG
        if (mustGrab || busy < 2*unused)
#else // DEBUG
// For now if I am in the release version not the debug one I will use up ALL
// memory before considering GC. This is because GC is not implemented yet,
// so this lets me test just a few more things.
        if (mustGrab || true || busy < 2*unused)
#endif // DEBUG
        {   if (!emptyPages.isEmpty())
            {   Page* r = emptyPages.pop();
                r->type = emptyPageType;
                initPage(type, r, true);
//              zprintf("return empty %a type %d\n", r, (int)type);
                return;
            }
            else if (pageFringe != pageEnd)
            {   Page* r = pageFringe++;
                r->type = emptyPageType;
                initPage(type, r, true);
//              zprintf("return new %a type %d\n", r, (int)type);
                return;
            }
            else if (mustGrab)
            {   if (type==vecPageType && !vecPinPages.isEmpty())
                {   Page* r = vecPinPages.pop();
                    initPage(type, r, false);
//                  zprintf("return pinned vec %a type %d\n", r, (int)type);
                    return;
                }
                else if (type==consPageType && !consPinPages.isEmpty())
                {   Page* r = consPinPages.pop();
                    initPage(type, r, false);
//                  zprintf("return pinned cons %a type %d\n", r, (int)type);
                    return;
                }
            }
        }
// If current memory is at least (2/3) full or (really improbably) more
// than 1/3 of all pages contain pinned data then I will try to grab
// more memory from the operating system. If that succeeds I very much
// expect that the enlarged memory will be well less than (2/3) full. If
// however I can not allocate any more then I will need to garbage collect.
        if (!allocateAnotherSegment()) break;
    }
    if (withinGarbageCollector) fatal_error(err_no_store);
    cout << "\n@@@ MEMORY FULL @@@\n" << endl;
    garbage_collect();
// After garbage collection there had BETTER be some available memory left!
// At the end of garbage collection everything should be ready to do the
// next bit of allocation.
}

// When I make a page "full" I will put a pointer just beyond the
// last data allocated in it there so that the GC can be aware that
// space beyond that is unused (apart from potential pinned stuff).

uintptr_t consEndOfPage()
{   consCurrent->dataEnd = consFringe;
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
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
                     force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
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
    potentiallyPinned = nullptr;
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
    vecStopCache = borrowStopCache = -1;
}

// This function receives a target heap size in megabytes. If the user
// has specified (using -K) a size then that is given, otherwise the
// default will be half the amount of memory the machine has. Save that
// on a 32-bit system a limit at 1600Mb is set and in all cases the flag
// --maxmem can be used to force a smaller limit.

void init_heap_segments(double d)
{   zprintf("init_heap_segments %.2g Mbytes\n", d);
// For historical reasons initHeapSegments takes its size in Kbytes not Mbytes
    initHeapSegments(d*1024.0);
}

LispObject Lgc(LispObject env)
{   return Lgc(env, fixnum_of_int(1));
}

LispObject Lgc(LispObject env, LispObject a)
{   garbage_collect();
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
{   int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = static_cast<int>(int_of_fixnum(a));
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}

bool volatile already_in_gc;
bool volatile interrupt_pending;

static unsigned int MEM=2u*1024u*1024u*1024u;
bool pageFull;

LispObject Lgctest_0(LispObject env)
{   LispObject a = nil;
    for (unsigned int i=0; i<MEM/16u; i++)
    {   a = cons(fixnum_of_int(i), a);
        zprintf(":");
        if (i % 1000000 == 0)
        {   zprintf("%d", i);
            LispObject b = a;
            for (unsigned int j=i; j!=static_cast<unsigned int>(-1); j--)
            {   if (!is_cons(b)) my_abort(LOCATION ": gc test failure");
                if (car(b) != fixnum_of_int(j))
                    my_abort(LOCATION ": gc test failure");
                b = cdr(b);
            }
            if (b != nil) my_abort(LOCATION ": gc test failure");
        }
    }
    return nil;
}

LispObject Lgctest_1(LispObject env, LispObject a1)
{   LispObject a = nil, b;
    size_t n = int_of_fixnum(a1);
    for (unsigned int i=0; i<n; i++)
        a = cons(fixnum_of_int(i), a);
    zprintf("list created\n");
    b = a;
    for (unsigned int j=n-1; j!=static_cast<unsigned int>(-1); j--)
    {   if (!is_cons(b)) goto failing2;
        if (car(b) != fixnum_of_int(j))
        {   zprintf("Fail3 case with j = %d\n"
                    " fixnum_of_int(j) = %x\n"
                    " car(b) = %x which differs\n"
                    " %d items down the list\n",
                j, fixnum_of_int(j), car(b), n-1-j);
            goto failing3; //<<<<<<<<<
        }
        b = cdr(b);
    }
    if (b != nil) goto failing4;
    return nil;
failing2:
    zprintf("Crashed2 b = %a car(b) = %a\n", b, car(b));
    zprintf("n = %d\n", n);
    for (int z=1; z<10; z++)
    {   zprintf("%d ", car(b)/16);
        b = cdr(b);
    }
    zprintf("\n");
    return nil;
failing3:
    zprintf("Crashed3 b = %a car(b) = %a\n", b, car(b));
    zprintf("n = %d\n", n);
    for (int z=1; z<10; z++)
    {   zprintf("%d ", car(b)/16);
        b = cdr(b);
    }
    zprintf("\n");
    return nil;
failing4:
    zprintf("Crashed3 4 = %a car(b) = %a\n", b, car(b));
    zprintf("n = %d\n", n);
    for (int z=1; z<10; z++)
    {   zprintf("%d ", car(b)/16);
        b = cdr(b);
    }
    zprintf("\n");
    return nil;
}

LispObject Lgctest_2(LispObject env, LispObject a1, LispObject a2)
{   return nil;
}

// end of newallocate.cpp
