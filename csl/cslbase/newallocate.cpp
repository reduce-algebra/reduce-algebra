// newallocate.cpp                         Copyright (C) 2018-2021 Codemist
//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//

// I have planned all this and even started work on it several times, with
// leter rounds of work reflecting gradually clearing understanding of some
// of the challenges and trade-offs. However I am concerned that the
// iteration may have left some blocks of comments or fragments of code from
// earlier versions still in place. I will try to go through and tidy up
// on that front, but to some extent that will best happen if and when I get
// a fairly fully working version so that there starts to be real stability.



// Development game-plan for this stuff - showing the steps or stages
// to go through:
// [Steps I have achieved are deleted from this list!]
//
// (3) Arrange that every garbage collection will be a major one and
//     re-work the allocation and re-allocation of memory blocks for that.
//     By keeping the code with precise list-bases for everything that
//     matters the ambiguous pointers should never be the only reason
//     for saving any data - they just pin things and hence mess up memory
//     layout. Get that version of GC working. Note that write barriers
//     may collect information but it is never used!
// (4) Make some collections minor ones, thus needing to cope with the
//     consequences of the write barrier.
// (5) Put in explicit test cases for data that is only preserved via an
//     ambiguous list-base.
// (6) Thread-synchronization for GC entry.
// (7) Thread-local support for fluid bindings, and simple code in the Lisp
//     for creating threads, even though almost everything is not thread-safe.
// (8) [in various orders] get rid of push/pop stuff if the main code in
//     favour of just letting conservative memory management cope. And
//     migrate more status to thread-local and/or protect it with critical
//     regions.
// (9) Fix ccomp.red and bytes2.cpp regarding new treatment of fluids and
//     for thread safety.
// (10)Protection of blocking calls so that GC can still happen.


// Well by the time I have got started at all on that list the issue of
// the exact sequence towards the end will become clearer! Really it is the
// first 3 that are my initial plan.


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

/*!!! csl
*/

#include "headers.h"

#ifdef HAVE_CXX17

// In code that at present (February 2021) is disabled with "#if 0"
// I use the Mersenne Twister generator as set up in arithlib.hpp
// to set up some ransomized testing for this code. That will only
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

//
// This is a place for my latest round of thinking about a new storage
// management scheme. The ideal I set now is that garbage collection should
// be both conservative and generational and that it should be able to
// support multiple mutator threads. I have some ideas about using multiple
// threads during garbage collection but serious worries about possible
// synchronization overheads so that will not be an early target. And I have
// no plans to try and garbage collect and compute concurrently - so every
// garbage collection will need to synchronize and stop all worker threads.

// The design here has to mingle plans for global storage allocation,
// the CONS operation as well as operations involving Lisp atoms, the
// way that Lisp threads can access the values of variables, synchronization
// matters and so on. In general it seems that almost all aspects from the
// lowest to the most global level interact. Ugh!

// So here is an overview. Well I fear I may have written bits of this already
// in several places, but writing it out helps me to plan. All of the numeric
// values given here are indicative rather than guaanteed final.

// Memory is grabbed from the operating system in large chunks, with a few
// hundred megabytes for the first chunk and larger ones potentially sized
// in geometric progression, so that with a maximum of 16 chunks I can end up
// with as much memory as can ever be useful. The limit on the total number
// of chunks used as so that given a value that might be a pointer it will
// be possible to identify the chunk it might point within using a small
// number of comparison operations. The mega-chunk allocation is such that the
// system can start with fairly sane amounts of memory but expand on need.
//
// Each chunk is divided into 8Mbyte pages. At any one moment one page will
// be "Current", a second will be "Previous", some others will be "Busy" and
// the rest "Free". All mutator allocation happens within the Current page.
// When that becomes full live data is evacuated from the Previous page into
// Busy memory and what was Current becomes Previous. The old Previous page
// becomes Free and a Free page is chosen to be the new Current. Note this
// might be done by swapping the sense of Current and Previous, but if I
// did that then if those two pages get severly fragmented that that situation
// would persist, so I will want to arrange that pages get moved to be
// extensions to the Busy pool from time to time. Which will tend to happen
// naturally but may need forcing in pathological case!
//
// Because garbage collection is conservative there can be ambiguous pointers
// that refer into Previous. Data at the locations so addressed must not be
// moved: I will refer to it as "pinned". The Current and each Free page may
// have some pinned items present. When a page becomes Current it will have
// two pointers - gFringe and gLimit. gFringe identifies the first
// point at which data could be allocated, gLimit points either one beyond
// the end of the page or to the start address of the next pinned chunk.
// If there is a pinned chunk then it will contain one field that indicates
// its length and a second one that points to any pinned chunk beyond it.
// In Previous and Busy each page will be kept full by placement of padder
// pseudo-objects anywhere where there could be gaps: that is so that it is
// possible to perform a sequential scan of the page with each item within
// it identifiable by inspection of its first (header) word. This linear scan
// is needed because pinning works by pinning significant-size chunks of
// memory were the chunk always has an object starting at its start address
// and is always neatly filled. The garbage collectore has to treat all
// pointer-containing fields in such a chunk as roots. I argue that if some
// data is pinned then pinning other data that is close to it in memory will
// probably not lead to TOO much additional waste! But until I have it
// coded and tested I might not know.
//
// Allocation within Current is by incrementing gFringe and if necessary
// skipping on to gNext. By making gFringe atomic this allocation can be
// thread-safe.
//
// Within a page allocation (via gFringe) allocated 16Kbyte chunks to each
// thread. The thread holds variable fringe and limit to allow it to perform
// simple sequential allocation within the chunk with low overhead. During
// garbage collection it is necessary to access and update fringe and limit
// values for every thread, and to support that I have data such as the
// array fringeBis[] that is indexed by a thread-number. Especially when
// garbage collection is being triggered data can be moved from the simple
// (albeit thread-local) variable into this array. Because each thread has
// its own chunk most allocation within a chunk doe snot involve any locks.
// When a chunk overflows a fresh one needs to be allocated. If the request
// that triggered this was for n bytes of memory that the next chunk that is
// grabbed is of size 16K+n so that 16Kbytes are left available after the
// potentiallt large allocation. As regards space use the worst case for this
// is if there are many sequential requests each needing just over 16Kbytes
// apiece. In that case around 50% of memory in Current end up unused. This
// space will remain unused in Previous, but when data is evacuated to Busy
// it will be packed properly closely, so across the whole system the worst
// possible "waste" that way will be 8Mbytes. Of course most allocations will
// be of much smaller objects and so I am not worried in this area.
//
// The trigger for garbage collection is when at least one thread attempts
// an allocation and moved gFringe on beyond gLimit. As a C pedant I ough to
// worry if that led to a pointer beyond the range of the mega-chunk that
// had been grabbed from the OS, or (worse) if it led to overflow in address
// arithmetic. If I was super-cautious I would leave the top of each huge
// chunk as unused buffer against just such concerns. The amount I would
// need to reserve would be VECTOR_CHUNK_BYTES (2Mb) times the maximum number
// of threads (64), and that may be way more that I am happy with! So just
// for now I will duck that concern. But I will want the higgest-addressed
// huge chunk to end at least 128M before the end of memory address space!
//
// When a thread (or several threads) overflows a page it must trigger garbage
// collection. In the process it must synchronize with all the other threads.
// To achieve that it sets the limit value in every (active) thread to zero.
// The consequence will be that when the thread next tried to allocate memory
// it will get the initial impression that its chunk was full and can go into
// a more elaborate path which detects that actual situation. There are two
// cases when a memory allocation request might not arise promptly. One is
// code loops that do not allocate memory: each of those must contain a
// polling request which will be implemented as a request for zero bytes of
// memory - which in term will merely amount to a comparison between fringe
// and limit. The other would be when the thread was perfroming some operation
// that could or did block. That will obviously include when it uses range of
// synchronization primitives. In such case before blocking it must remove
// itself from the pool of active threads, and it can reinstate itself later.
//
// As garbage collection starts each thread must record its stack pointer and
// ensure that all pointer-objects that it is using are recorded on the
// stack (as well as potentially being in machine registers). The (C++) stack
// will then be scanned with all values on it treated as potential or
// ambiguous pointers.
//
// Given a potential pointer the system must be able to determine if it in
// fact points within a properly allocated object. This process starts by
// checking which mega-block is involved. From that information simple
// arithmetic can identify a page. Pointers that are into the header sections
// of a page or beyond its gLimit are certainly not references to live
// objects. I will then have a table of all the chunks within the page, and
// after sorting that a simple binary search can narrow the target of the
// ambiguous pointer down to a single 16K chunk. I tag that entire chunk as
// pinned.
// During a minor GC the only page that needs pinned information collected
// is the Previous one, since material in all other pages will stay put anyway.
// My expectation is that the vast majority of (valid) potential pointers
// will be into Current, with the next higher number into Previous. That is
// because fairly recently allocated objects are most likely to have
// references to them on the stack. For older material I think I expect a
// tendancy for clustering and with a large memory configuration only a
// small fraction of the total number of pages will be involved.
//
// A consequence of using a generational system is that I need to be able
// to respond to updates to old data that lead to references to new data.
// When I perform a major GC I will be scavanging everything and so no special
// treatment is called for, but to support minor GCs I will arrange that any
// use of RPLACD, RPLACD or PUTV (or derived operations such as PUTHASH, PUT
// and NCONC) set a mark indicating a region of memory that must be treated
// as roots. I record "dirty" information in bitmaps so that I can identify
// updated objects to a resolution of individual calls. During a minor GC
// I need to visit each such cell and that basically involves scanning the
// bitmap looking for nonzero bits. Since I expect it to be sparse I will have
// multiple levels of bitmap so I can in general avoid inspecting areas
// of memory that will not be interesting. When I do this during a minor
// GC if I only need to concern myself with words that now point into
// Current or Previous, and anything that points to older material can have
// its dirty bit reset to zero.
// Note that dirty bits may end up set on pinned items in pages that are
// (mostly) Free.


size_t pagesCount;
size_t activePagesCount;

// Ha ha potentially clever idea. Have activeTheads an atomic<uint32_t> and use
// the bottom 10 bits for the number of threads that are busy and the next
// 10 bits for the number potentially busy and finally 10 bits for the total
// number of threads in play. That way I can eg subtract (1<<10)+1 when a
// thread temporarily removes itself from the pool because it
// may be about to block! Etc etc. The second idea is that there is potential
// misery about needing to get every thread to exit when STOP is called. Well
// maybe I can avoid using mutexes at all as places that code can block and
// instead use condition variables with a condition of the form
// (<sensible-condition> || need_to_exit) and then when the barrier is passed
// I immediately check need_to_exit and tidy up a bit more. To make that work
// I suspect I will need a table of every muxex/condition variable anywhere
// so that when I set need_to_exit I can notify all of them!
// Well for muxexes and condition variables visible at the Lisp level I will
// need underlying C++ ones which will sort of need garbage collection but
// must never move. I think that the best bet is to have a vector pool of
// synchronization objects with the Lisp objects that encapsulate them holding
// an integer index that will need to be treated as a weak pointer to
// keep the object "alive". Whe not alive the object is just available for
// re-use... That is all going to be a bit messy.

// Another though to be left as comments here until I implement it and comment
// it where the code ends up:
// The copying GC can probably be coded so as to use multiple threads to do
// the copying! I have bits of that sketched in my mind, util until I can sit
// down quietly with a full sized keyboard and code some of it things are a
// bit uncertain. In particular there will be issues about the cost of
// the test-and-set operations I would need to use to keep threads from
// entanglement.
// A though is that when I am about to evactuate the item it address p I
// start with a = atomic_store(p, TAG_FORWARD) where tht returns the
// previous value at p. Then if that was TAG_FORWARD I will know that
// somebody else had been evacuating that location - I just re-try in a busy-
// waiting style. If what was there was a forwarding address then I do an
// (atomic) store to put it back. Otherwise I have the original contents and
// I have marked the word with TAG_FORWARD so that no other thread will mess
// with it (much). As quickly as I can I work out where the data will need
// to end up. This is going to be an atomic_add operation on the fringe of
// the new heap. Then I can store a proper forwarding address in place.
// I HOPE that it will be rare that two threads try to evacuate the same
// location at once, so the spin-wait will be uncommon, and I hope that
// working out where something moves to will be quick so that when it does
// happen it will not need to run for long.
// I can batch the identification of locations to evacuate so I can use a
// mutex to protect that code that grabs them, and that will be ok provided
// identifting locations is (much) cheaper than actually altering stuff.

// BEWARE:
//   consider the imlemention of v = cons(a,b) where v is some value that may
// be shared across threads. Eg rplacd(V, cons(a, b)) is almost certainly
// going to count. The natural implementation will be along the lines
//    w = allocate();
//    w[0] = a;
//    w[1] = b;
//    v = w;
// but as a first issue the compiler might use v in place of the temporary w,
// and then we have
//    v = allocate();
//    some other thread accesses uninitialized car v here!
//    v[0] = a; v[1] = b;
// Things are even worse because with the code written in vanilla form the CPU
// may re-order all the memory writes, again leaving v referencing a chunk of
// memory not fully initialized. The two issues must be dealt with using one
// of two ideas. Synchronization primitives such as mutexes could be used to
// enclose the operation as a critical region, and potential accesses would
// do likewise. The performance and ugliness costs are horrendous! Or memory
// fences can be used. So that shows I will need to study thread-fence methods
// and all the options that provide. Note that without a fence after the update
// of v it could be that the chance made would reside locally so that other
// threads would not see it, so a fence may be needed to "publish" it.
// Making almost every value atomic<T> might also do the job, but that
// would then imply fences everywhere and could hurt performance and it would
// also be horribly ponderous and clumsy.
//


uintptr_t *C_stackbase;   // base of the main thread
atomic<uint32_t> activeThreads;
//  0x00 : total_threads : lisp_threads : still_busy_threads

// The variables defined as thread_local here MAY be just rendered as
// (eg)    "thread_local uintptr_t threadId;"   but on Windows they end
// up as instances of a slightly strange class that supports assignment
// from the the specified type and static casts to the specified type, but
// where more complicated casts (explicit or implicit) may not be tolerated.
// So there are places where I am obliged to write odd-looking code like
// ... static_cast<uintptr_t>(threadId) ... or "threadId = static_cast<..."
// to make the type conversion process especially explicit and simple.
// I could avoid that if I made the wrapper class rather a lot more
// compilicated, but I think that transparancy there and a modest amount of
// redundancy here is the path that leaves me happiest (at present).

DEFINE_THREAD_LOCAL(uintptr_t,    threadId);
DEFINE_THREAD_LOCAL(uintptr_t,    fringe);
DEFINE_THREAD_LOCAL(Page *,       borrowPages);
DEFINE_THREAD_LOCAL(uintptr_t,    borrowFringe);
DEFINE_THREAD_LOCAL(uintptr_t,    borrowLimit);
DEFINE_THREAD_LOCAL(uintptr_t,    borrowNext);



// All the heap memory I use here will be allocated within (up to) 32
// segments that are grabbed using "new" etc...
// Each segment of memory will start aligned at a multiple of CSL_PAGE_SIZE
// which is (at present) 8 Mbytes. The idea here is that I grab seriously
// large chunks of memory from the system and these chunks may not be
// contiguous. But with at most 32 of them I can take any bit-pattern and
// with around 5 comparisons I can identify which (if any!) of these
// chunks it points within. Then division by 8M can get me to the start of
// the 8 Mbyte segment that is involved. That bit of search will be heavily
// used when processing ambiguous pointers.
//


// Provide the kernel of the allocation code...

// This is an updated and fuller explanation of memory layout on each
// page.
// A page may either be one where allopcation is currently happening within
// it or one that is full of data, or it may be one that is currently
// free. A messy complication is that in each situation its general pattern
// of use can be disrupted by virtue of it having some data within it that
// was pinned during a previous garbage collection and so had to be left
// in place. That means my idea of having separate pages for cons cells and
// for vectors seems to fail.

// A page will have as its layout:
// (1) A smallish header that contains its fringe, arrangements so it can
//     be chained along with other pages etc. Details will emerge as I code
//     all this and discover what I need!
// (2) A region that acts as a "dirty map". This region will be present in
//     every page and is an array of atomic<uint8_t>, where each byte maps
//     a 64-byte block within the page and will get set non-zero if a RPLAC
//     or PUTV (style) operation updates anything within that small block.
//     for 8 Mbyte pages this map will be 128 Kbytes large. It only gets
//     written to when Lisp performs a valid RPLAC/PUTV and so addresses
//     such as those in the bitmap itself will never become dirty. So if
//     this map is aliased to start at the beginning of the page the first
//     2 Kbytes may be used (eg for the header) without risk.
// (3) A bitmap that can be used to tag "pinned" objects. To have one bit for
//     each 8-byte item in the heap (and every valid LispObject will be
//     positioned so as to be 8-byte aligned, whether on a 32 or 64-bit
//     platform) will require 128 Kbytes, and this will be set up as an
//     array of uint64_t values which will mean that any linear scan of it
//     only has 16 K words to check. Pinned status is established for memory
//     in the scavengable region as a first step in garbage collection. Two
//     cases arise. In Minor garbage collection pinning only happens in the
//     single page of scavengable material, and all of that will be processed
//     so issues as to whether there are up-pointers present in it do not
//     arise. Pinned bits are not set in the Stable part of the heap so
//     dirty bits there are unaffected. On the other hand during a Major
//     garbage collection all memory is Scavangable and will need pin
//     information, but dirty bits are not relevant. So provided pinned bits
//     are ONLY used or inspected during garbage collection the bitmap here
//     can overlay the dirty map.
//     If at the end of garbage collection there had been pinned items in the
//     Scavengable region and if the contents of any of those are up-pointers
//     then they must be marked as dirty when the page is put in the Free area.
// (4) A further 128 Kbyte bitmap that can mark which addresses within a page
//     are at the start of a LispObject. These get set in the Scavengable
//     region as a prelude and prerequisite for setting pinned bits. Well to
//     be more careful about that statement, when an ambiguous address is
//     inspected to use it for pinning the page it refers into will need its
//     object-start map set up. So pages that contain no pinned items at all
//     avoid this. So during a minor GC only the scavengable region gets
//     scanned to identify object starts, while during a major GC only pages
//     that are the targets of ambiguous pointers will.
//

// Here is a layout for an 8 Mbyte page, specifying the various
// ways in which data can be accessed. This uses a union so that the page
// header will overlap the beginning of the objstart[] bitmap, but because
// objects only reside in the data[] part the first couple of kilobytes
// of objstart[] will never be used.

// The initializeation here is intended to make the code more fragile
// so that unless I initialize elsewhere I stand a good chance of seeing
// a prompt sigsegv.
static Page *px = reinterpret_cast<Page *>(-0x5a5a5a5aU);

Page *currentPage = px;     // Where allocation is happening. The "nursery".
Page *previousPage = px;    // A page that was recently the current one.
Page *busyPages = px;       // Chained list of pages that contain live data.
Page *oldPages = px;        // Page from which live stuff is being evacuated.
Page *mostlyFreePages = px; // Chained list of pages that the GC has mostly
                            // cleared but that have some pinned data left
                            // in them.
Page *freePages = px;       // Chained list of pages that are not currently
                            // in use and that contain no useful information.

size_t busyPagesCount = -1, mostlyFreePagesCount = -1,
       freePagesCount = -1, oldPagesCount = -1;

void *heapSegment[16];
char *heapSegmentBase[16];
size_t heapSegmentSize[16];
size_t heapSegmentCount;

// I make some assumptions about the variations on atomic<> that I
// use, but then would like to use static_assert to confirm them or to
// cause CSL to fail to compile. However the test has to be dynamic, so I can
// at best cause things to fail at system startup. Boo Hiss!
// I believe that my assumptions have a good chance of being satisfied
// on almost all machines, even though I can imagine architectures
// where there may be trouble. But what matters most to me will be x86,
// x86_64 and both 32 and 64-bit ARM when using g++ or clang, and those will
// get checked the first time I compile this code on each.
//
// Note that the C++ standard explictly says that there is no guarantee that
// the sizes of atomic specializations match those of the underlying raw
// types, but that implementations are encouraged to make that the situation
// where they can.
// Here I verify the HOPES that I have by checking them in the constructor
// for an otherwise worthless class that I then define an instance of.

class MakeAssertions
{
public:
    MakeAssertions()
    {   if (sizeof(atomic<std::uint8_t>) != 1)
        {   cout << "atomic<int8_t> is not the expected size" << "\r" << endl;
            my_abort();
        }
        if (!atomic<std::uint8_t>().is_lock_free())
        {   cout << "atomic<uint8_t> not lock-free" << "\r" << endl;
            my_abort();
        }
        if (sizeof(atomic<std::uintptr_t>) != sizeof(intptr_t))
        {   cout << "atomic<uintptr_t> is not the expected size" << "\r" << endl;
            my_abort();
        }
        if (!atomic<uintptr_t>().is_lock_free())
        {   cout << "Atomic<uintptr_t> not lock-free" << "\r" << endl;
            my_abort();
        }
        if (sizeof(atomic<std::uint32_t>) != 4)
        {   cout << "atomic<uint32_t> is not the expected size" << "\r" << endl;
            my_abort();
        }
        if (!atomic<std::uint32_t>().is_lock_free())
        {   cout << "atomic<uint32_t> not lock-free" << "\r" << endl;
            my_abort();
        }
        if (SIXTY_FOUR_BIT)
        {   if (sizeof(atomic<std::uint64_t>) != 8)
            {   cout << "atomic<uint64_t> is not the expected size" << "\r" << endl;
                my_abort();
            }
            if (!atomic<std::uint64_t>().is_lock_free())
            {   cout << "atomic<uint64_t> not lock-free" << "\r" << endl;
                my_abort();
            }
        }
        cout << "is_standard_layout(Chunk) = "
             << std::is_standard_layout<Chunk>::value << "\r" << endl;
    }
};

static MakeAssertions test_for_lockfree;

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
// Basic vectors must be smaller then the CSL page size.
    if (allocSize > (CSL_PAGE_SIZE - 32))
        return aerror1("request for basic vector too big",
                       fixnum_of_int(allocSize/CELL-1));
    LispObject r = get_n_bytes(allocSize);
    *(reinterpret_cast<Header *>(r)) = type + (size <<
                                       (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multiple of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *reinterpret_cast<LispObject *>(r+allocSize-CELL) = 0;
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

// As well as shrinking vectors the hash table code can want to "borrow"
// space by allocating vectors (never lists) from the half of memory that
// the copying garbage collector is not keeping live data in at present.
// The protocol I have is that it goes
//      {   Borrowing borrowObject;
//          ... get_vector() ... get_vector() ...
//      }
// and it MUST be coded so that it can not trigger garbage collection while
// the "borrowed" vectors are in use. It does not have any specific way of
// indicating when the space is no longer needed, save that a subsequent
// call to prepare_for_borrowing() must not happen while borrowed space is
// still needed. The key use for this is when a hash table needs to be
// re-hashed - the code borrows space and copies the existing table contents
// into it. It then re-hashes everything back into the existing vector.
// Doing things that way really simplifies the hash table code, and avoids
// having the temporary space anything other than rather temporary and
// transient. However the scheme is not very thread-friendly! My current
// plan is that only one thread may be re-hashing (and hence borrowing) at
// once, and while that is happening any other thread that needs to trigger
// garbage collection will have to wait. I am putting in stubs of code here
// but the code to borrow memory will in fact be very similar to that used
// during garbage collection to allocate space in the new half-space when
// a vector needs to be evacuated to there.
// Note that other threads might be busy allocating memory during the
// time that one is borrowing, so they can need garbage collection. It will
// have to wait until the use of borrowed memory is over.

// Perhaps I could invent and then use an alternative protocol so that each
// thread could do its own borrowing without messy clashes. Perhaps the main
// issue there is recovering memory when a thread has finished. To think
// about how vital that might be I would need to consider whether hash tables
// might need rehashing multiple times between garbage collections - if the
// answer is "no" then each hash table could have its own associated
// borrowed shadow ... that starts to sound sensible to me! I will get a LOT
// more of this code working before I worry about that detail.

//thread_local Page *borrowPages;
//thread_local uintptr_t borrowFringe;
//thread_local uintptr_t borrowLimit;
//thread_local uintptr_t borrowNext;

// Here I need to arrange that if several threads each try to borrow memory
// at the same (or overlapping) times that they end up with separate
// chunks. I do this by letting each grab memory from mostlyFreePages and
// freePages, but with a mutex to protect the allocation. Then when borrowing
// is complete I push stuff back. I do not change the recorded counts of
// free pages.

LispObject borrow_n_bytes(size_t n)
{   for (;;)
    {   size_t gap=borrowLimit - borrowFringe;
        if (n <= gap)
        {   uintptr_t r = borrowFringe;
            borrowFringe = borrowFringe + n;
            return static_cast<LispObject>(r);
        }
        if (borrowNext != 0)
        {   borrowFringe = static_cast<uintptr_t>(borrowNext);
            borrowLimit = reinterpret_cast<uintptr_t *>(
                static_cast<uintptr_t>(borrowFringe))[0];
            borrowNext = reinterpret_cast<uintptr_t *>(
                static_cast<uintptr_t>(borrowFringe))[1];
            continue;
        }
// here I need to allocate a new page....
        std::lock_guard<std::mutex> lock(mutexForFreePages);
        Page *w;
        if (mostlyFreePages != nullptr)
        {   w = mostlyFreePages;
            mostlyFreePages = mostlyFreePages->chain;
        }
        else
        {   w = freePages;
            freePages = freePages->chain;
        }
        w->chain = static_cast<Page *>(borrowPages);
        borrowPages = w;
        borrowFringe = w->fringe;
        borrowLimit = w->limit;
        borrowNext = 0;    // BAD....
    }
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   size_t allocSize = (size_t)doubleword_align_up(size);
    if (allocSize > (CSL_PAGE_SIZE - 32))
        return aerror1("request for basic vector too big",
                       fixnum_of_int(allocSize/CELL-1));
    LispObject r = borrow_n_bytes(allocSize);
    *(reinterpret_cast<Header *>(r)) = type + (size <<
                                       (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *reinterpret_cast<LispObject *>(r+allocSize-CELL) = 0;
    return static_cast<LispObject>(r + tag);
}

LispObject borrow_vector(int tag, int type, size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES -
                         1)/VECTOR_CHUNK_BYTES;
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

// This code sets up an empty page - it is ONLY intended for use at the
// start of a run when there can not be any pinned items present anywhere.
// I put the code here adjacent to the code that allocates from the list of
// pages so that the setup and use can be compared.

void setUpEmptyPage(Page *p)
{   p->chain = nullptr;
    p->chunkCount = 0;
    p->chunkMapSorted = false;
    for (size_t i=0; i<sizeof(p->dirtyMap)/sizeof(p->dirtyMap[0]); i++)
        p->dirtyMap[i] = 0;
    for (size_t i=0; i<sizeof(p->dirtyMap1)/sizeof(p->dirtyMap1[0]); i++)
        p->dirtyMap1[i] = 0;
    for (size_t i=0; i<sizeof(p->dirtyMap2)/sizeof(p->dirtyMap2[0]); i++)
        p->dirtyMap2[i] = 0;
    p->hasDirty = false;
    p->dirtyChain = nullptr;
    p->hasPinned = false;
    p->pinChain = nullptr;
    p->pinnedChunks = nullptr;
    p->chain = freePages;
    freePages = p;
    p->pageClass = freePageTag;
    p->fringe = reinterpret_cast<uintptr_t>(&p->data);
    p->limit = reinterpret_cast<uintptr_t>(p) + sizeof(Page);
}

// Now something that takes a page where it must be left free apart from
// any pinned Chunks within it. The fringe and limit fields must be set up
// to reflect them. Note that this does NOT alter the "chain" field or set
// pageClass - those must be dealt with otherwise.
// The page concerned MUST have some clear space on it. If it was
// enirely full of pinned chunks this code would fail.

void setUpUsedPage(Page *p)
{   p->chunkCount = 0;
    p->chunkMapSorted = false;
    for (size_t i=0; i<sizeof(p->dirtyMap)/sizeof(p->dirtyMap[0]); i++)
        p->dirtyMap[i] = 0;
    for (size_t i=0; i<sizeof(p->dirtyMap1)/sizeof(p->dirtyMap1[0]); i++)
        p->dirtyMap1[i] = 0;
    for (size_t i=0; i<sizeof(p->dirtyMap2)/sizeof(p->dirtyMap2[0]); i++)
        p->dirtyMap2[i] = 0;
    p->hasDirty = false;
    p->dirtyChain = nullptr;
// Those Chunks that are on the pinChain need to be put into chunkMap..
// other chunks will get added as they are allocated, but the pinned ones
// are there right from the start.
    for (Chunk *c = p->pinnedChunks; c!=nullptr; c=c->pinChain)
        p->chunkMap[p->chunkCount++] = c;
// I want the pinned chunks sorted so that the lowest address one comes
// first. That will ensure that when one comes to skip past a pinned
// chunk that the next chunk on the cgain will be the next one up in
// memory.
    std::qsort(p->chunkMap, p->chunkCount, sizeof(p->chunkMap[0]),
               [](const void *a, const void *b)
               {   const Chunk *aa =
                       static_cast<const atomic<Chunk *>*>(a)->load();
                   const Chunk *bb =
                       static_cast<const atomic<Chunk *>*>(b)->load();
                   uintptr_t aaa = reinterpret_cast<uintptr_t>(aa);
                   uintptr_t bbb = reinterpret_cast<uintptr_t>(bb);
                   return aaa < bbb ? -1 :
                          aaa > bbb ? 1 : 0;
               });
    p->pinnedChunks = nullptr;
    for (size_t i=p->chunkCount; i!=0; i--)
    {   p->chunkMap[i].load()->pinChain = p->pinnedChunks.load();
        p->pinnedChunks = p->chunkMap[i].load();
    }
// Start as if the page is utterly empty.
    p->fringe = reinterpret_cast<uintptr_t>(&p->data);
// Now if MAY be that the first part of memory is consumed by one (or a
// succession) of pinned chunks, or that the start of the page has a small
// vacant region terminated by a pinned chunk. I cope with this by setting
// the limit to either the start of the first pinned chunk or to the end of
// the whole page. In an extreme case this will leave fringe==limit. But
// that is not going to be a problem because the first time I try to
// perform allocation I will find that my chunk is empty and scan to grab
// another.
    if (p->pinnedChunks!=nullptr)
        p->limit = reinterpret_cast<uintptr_t>(p->pinnedChunks.load());
    else p->limit = reinterpret_cast<uintptr_t>(p) + sizeof(Page);
}

void setVariablesFromPage(Page *p)
{
// Set the variable that are used when allocating within the active page.
// Here I require that when a page it set up the fringe and limit values
// stored within it reflect any pinned chunks. When I do this I set the
// limit for the current page equal to the fringe, and that will mean
// that the very first time I try to allocate I will arrange to set up
// a fresh Chunk. That seems nicer to me than creating that chunk here.
    uintptr_t thr = threadId;
    fringe = limit[thr] = limitBis[thr] = gFringe = p->fringe.load();
    myChunkBase[thr] = nullptr;
    gLimit = p->limit;
//    cout << "setVariablesFromPage\r\n";
//    cout << "At " << __WHERE__ << " gFringe = " << std::hex << gFringe << "\r" << endl;
//    cout << "At " << __WHERE__ << " gLimit = " << std::hex << gLimit << "\r" << endl;
//    cout << std::dec;
}

// This code allocates a segment by asking the operating system.
// It grabs a block that is aligned to sizeof(Page).
// The collection of segments must be stored in heapSegments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.
//
// Returns false and does nothing if it can not grab the memory.

bool allocateSegment(size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// page size. Note that this will be quite a large value!
    n = (n + pageSize - 1) & -pageSize;
    Page *r;
// If I have C++17 I can rely on alignment constraints and just allocate
// using new[]
#ifdef MACINTOSH
// I would like to use aligned allocation via "new" in the C++17 style, but
// on the Macintosh that is only supported if your operating system is at
// least 10.14. That is your operating system not a constraint on the release
// of the C++ compiler and library! For backwards compatibility at present I
// set a deployment target of 10.13 so I have to do something different here!
    {   size_t sz = n+pageSize-1;
        char *tr = new (std::nothrow) char[sz];
        heapSegmentBase[heapSegmentCount] = tr;
        void *trv = reinterpret_cast<void *>(tr);
        std::align(pageSize, n*pageSize, trv, sz);
        r = reinterpret_cast<Page *>(trv);
    }
#else // MACINTOSH
    r = new (std::nothrow) Page[n/pageSize];
#endif // MACINTOSH
    if (r == nullptr) return false;
    heapSegment[heapSegmentCount] = r;
    heapSegmentSize[heapSegmentCount] = n;
    heapSegmentCount++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (size_t i=heapSegmentCount-1; i!=0; i--)
    {   int j = i-1;
        void *h1 = heapSegment[i], *h2 = heapSegment[j];
        if (reinterpret_cast<uintptr_t>(h2) < reinterpret_cast<uintptr_t>(h1))
            break; // Ordering is OK
// The segment must sink a place in the tables.
        std::swap(heapSegment[i], heapSegment[j]);
        std::swap(heapSegmentSize[i], heapSegmentSize[j]);
    }
// r now refers to a new segment of size n, I want to structure it into
// pages.
//
//  for (size_t k=0; k<n; k+=CSL_PAGE_SIZE)
// Go forwards or backwards!
    for (size_t k=n; k!=0; k-=CSL_PAGE_SIZE)
    {   Page *p =
            reinterpret_cast<Page *>(
                reinterpret_cast<char *>(r) + k - CSL_PAGE_SIZE);
// Keep a chain of all the pages.
        setUpEmptyPage(p);
        freePagesCount++;
    }
    cout << freePagesCount << " pages available\r\n";
    return true; // Success!
}

size_t pages_count = 0;
size_t heap_pages_count = 0;
size_t vheap_pages_count = 0;
bool garbage_collection_permitted = true;
bool force_verbos = false;
atomic<Page *> dirtyPages;
Page *globalPinChain;
atomic<Chunk *> chunkStack;

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

bool next_gc_is_hard = false;
uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\r\n",
                     force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
}

// When a thread exhausts memory (to be more specific, when it fills up
// the nursery page) it must arrange that all but one threads are stopped
// with information about their stacks visible somewhere central and all
// their active values on the stack rather than in machine registers.
// Then garbage collection car occur - or sometimes in simplet cases just
// the allocation of a fresh nursery page.
// To organize this threads need to be suspended. The following are the
// techiques that could potentially apply:
// (1) Busy-waiting on a suitable atomic flag. Hmm busy waiting is generally
//     not a good strategy except for very short periods.
// (2) Arranging that the thread receives a signal that takes it into
//     a signal handler that sleeps, in such a manner that it can be woken
//     from the sleep by a further notification. Well the rules about
//     proper portable use of signals and their handler make this hard to
//     arrange ina way that can be counted on across architectures, and I
//     do not really want to get down to that level of grungy detail and
//     verify it on Windows and with various Linux releases.
// (3) A thread can wait when it attempts to claim a semaphore, so for
//     each thread to be paused each will have to claim its own particular
//     semaphore. There are then two follow-on challenges - one is to
//     detect when every thread has become inactive and hence garbage
//     collection can proceed. The second arises when the threads release
//     their semaphores - somebody else must then lock them all with certainty
//     that that has happened before anybody runs out of memory again. There
//     are potential race conditions there and so further synchronization
//     steps are required. I think that this means that the associated
//     complexity means that the apparent simplicity of each thread "just
//     needing to lock a mutex" is apparent rather then real.
// (4) Somewhat in the style of (3) I can use condition variables, and
//     all the threads that are to pause can wait on the same condition
//     variable with a notify_all() operation releasing then all. This is
//     what I have tried to code here and it still feels messier than I
//     would have liked. But this section of comments is to suggest what else
//     I considered and how I ended up with this plan.

std::jmp_buf *buffer_pointer;

// Each thread will need a thread_number and I need to be able to allocate
// and release such identifying numbers. I will allow for up to 64 threads.

std::mutex threadStartingMutex;
// threadMap will have a zero bit in places that correspond to thread
// numbers that are allocated.

uint64_t threadMap = -1;

uint64_t threadBit(unsigned int n)
{   return (uint64_t)1 << (63-n);
}

unsigned int allocateThreadNumber()
{   my_assert(threadMap != 0); // I need at least one spare.
    unsigned int n = nlz(threadMap);
// Now n is 0 if the top bit is set, 1 for the next etc down to 63 when
// the least bit is the only one set.
    threadMap &= ~threadBit(n);
    return n;
}

void releaseThreadNumber(unsigned int n)
{   my_assert(n <=63);
    threadMap |= threadBit(n);
}

ThreadStartup::ThreadStartup()
{   // cout << "ThreadStartup" << "\r" << endl;
    initThreadLocals();
    std::lock_guard<std::mutex> lock(mutexForGc);
    threadId = allocateThreadNumber();
// The update here is just fine while I am in fact single threaded, but I
// will need to review it when multiple threads can be in play.
    activeThreads.fetch_add(0x00010101);
}

ThreadStartup::~ThreadStartup()
{   // cout << "~ThreadStartup" << "\r" << endl;
    std::lock_guard<std::mutex> lock(mutexForGc);
    releaseThreadNumber(static_cast<uintptr_t>(threadId));
    activeThreads.fetch_sub(0x00010101);
}

LispObject *nilSegment, *stackSegment;

uintptr_t               stackBases[maxThreads];
uintptr_t               stackFringes[maxThreads];
extern atomic<uint32_t> threadCount;
std::mutex              mutexForGc;
std::mutex              mutexForFreePages;
bool                    gc_started;
std::condition_variable cv_for_gc_idling;
std::condition_variable cv_for_gc_busy;
bool                    gc_complete;
std::condition_variable cv_for_gc_complete;
atomic<uintptr_t>       limit[maxThreads];
Chunk*                  myChunkBase[maxThreads];
uintptr_t               limitBis[maxThreads];
uintptr_t               fringeBis[maxThreads];
size_t                  request[maxThreads];
LispObject              result[maxThreads];
size_t                  gIncrement[maxThreads];
atomic<uintptr_t>       gFringe;
uintptr_t               gLimit = 0xaaaaaaaaU*0x80000001U;


void initHeapSegments(double storeSize)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double rather
// than as an integer so that overflow is not an issue.
{
// Most of the arrays initialized here are just set up for the sake of
// being tidy, but myChunkBase[] must be nullptr for safety.
    for (unsigned int i=0; i<maxThreads; i++)
    {   limit[i] = 0U;
        myChunkBase[i] = nullptr;
        limitBis[i] = 0U;
        fringeBis[i] = 0U;
        request[i] = 0U;
        result[i] = 0;
        gIncrement[i] = 0U;
    }
    withinMajorGarbageCollection = false;
    globalPinChain = nullptr;
// I will make the default initial store size around 64M on a 64-bit
// machine and 2048M on a 64-bit system. If the user specified a "-K" option
// they can override this, and also the system will tend to allocate more
// space (if it can) when its memory starts to get full.
    size_t freeSpace = static_cast<size_t>(SIXTY_FOUR_BIT ? 2048 : 64) *
                       1024*1024;
    size_t req = (size_t)storeSize;
    if (req != 0) freeSpace = 1024*req;
// Now freeSpace is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heapSegmentCount = 0;
    for (int i=0; i<16; i++)
        heapSegment[i] = reinterpret_cast<void *>(-1);
    freePages = mostlyFreePages = nullptr;
    cout << "Allocate " << (freeSpace/1024U) << " Kbytes" << "\r" << endl;
    allocateSegment(freeSpace);

    nilSegment = reinterpret_cast<LispObject *>(
        new (std::nothrow) Align8[(NIL_SEGMENT_SIZE)/8]);
    if (nilSegment == nullptr) fatal_error(err_no_store);
    nil = static_cast<LispObject>((uintptr_t)nilSegment + TAG_SYMBOL);
    stackSegment = reinterpret_cast<LispObject *>(
        new (std::nothrow) Align8[CSL_PAGE_SIZE/8]);
    if (stackSegment == nullptr) fatal_error(err_no_store);
    stackBase = reinterpret_cast<LispObject *>(stackSegment);
    previousPage = nullptr;
    currentPage = freePages;
    freePages = freePages->chain;
    freePagesCount--;
    currentPage->chain = nullptr;
    busyPages = currentPage;
    busyPagesCount = 1;
    setVariablesFromPage(currentPage);
    mostlyFreePages = nullptr;
    mostlyFreePagesCount = 0;

#if 0
//- Now as a temporary issue I will try to test my write barrier and
//- pinning scheme. For the write barrier I do not need any data in the
//- pages concerned, but for pinning I need much of the memory to be full -
//- what I do here is make it roughly (2/3) full.
    cout << "Total mem = " << freeSpace << "\r" << endl;
    size_t conses = freeSpace/(2*sizeof(LispObject));
    cout << "conses = " << conses << "\r" << endl;
    size_t which[5];
    for (int j=0; j<5; j++)
        which[j] = arithlib::mersenne_twister() % (conses/3);
    LispObject barriered[5];
    for (int j=0; j<5; j++) barriered[j] = fixnum_of_int(j);
    for (size_t i=0; i<conses/3; i++)
    {   LispObject a = cons(nil, nil);
        for (int j=0; j<5; j++)
            if (i == which[j]) barriered[j] = a;
    }
    for (int j=0; j<5; j++)
    {   uintptr_t n1 = static_cast<uintptr_t>(barriered[j]);
        cout << "Barrier on " << std::hex << n1 << std::dec << "\r" << endl;
        write_barrier(reinterpret_cast<LispObject *>(n1),
                      *reinterpret_cast<LispObject *>(n1));
    }
    cout << "About to scan all the dirty cells\r\n";
    scanDirtyCells(
        [](atomic<LispObject> *a) -> void
        {   cout << std::hex << reinterpret_cast<intptr_t>(a) << std::dec
                 << "\r" << endl;
        });
    cout << "Dirty cells scanned\r\n";   
    for (int i=0; i<5; i++)
    {   uint64_t n1;
// I want to conjure up an address that is within the region that is so far
// in use. This may point at page or chunk headers, in which case it ought
// not to mark anything.
        n1 = arithlib::mersenne_twister();
        cout << "Use " << std::hex << n1 << " as ambiguous" << std::dec << "\r" << endl;
        processAmbiguousValue(true, n1);
        n1 = reinterpret_cast<int64_t>(heapSegment[0]) +
             (n1 % heapSegmentSize[0]);
        n1 = n1 & ~UINT64_C(7);
        cout << "Use " << std::hex << n1 << " as ambiguous" << std::dec << "\r" << endl;
        processAmbiguousValue(true, n1);
        n1 = barriered[i];
        cout << "Use " << std::hex << n1 << " as ambiguous" << std::dec << "\r" << endl;
        processAmbiguousValue(true, n1);
    }
    cout << "About to scan all the pinned chunks\r\n";
    scanPinnedChunks(
        [](Chunk *c) -> void
        {   cout << "Chunk at "
                 << std::hex << reinterpret_cast<intptr_t>(c)
                 << " to " << (reinterpret_cast<intptr_t>(c)+c->length)
                 << std::dec << "\r" << endl;
        });
    cout << "Pinned chunks scanned\r\n";   

// End of temp testing code
#endif // 0

}

void dropHeapSegments()
{
    for (size_t i=0; i<heapSegmentCount; i++)
    {
#ifdef MACINTOSH
        delete [] heapSegmentBase[i];
#else // MACINTOSH
        delete [] static_cast<Page *>(heapSegment[i]);
#endif // MACINTOSH
    }
    delete [] reinterpret_cast<Align8 *>(nilSegment);
    delete [] reinterpret_cast<Align8 *>(stackSegment);
}

void drop_heap_segments()
{   dropHeapSegments();
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   return false;
//  if ((init_flags & INIT_EXPANDABLE) == 0) return false;
//  void *page = (void *)std::aligned_alloc((size_t)CSL_PAGE_SIZE);
//  if (page == nullptr)
//  {   init_flags &= ~INIT_EXPANDABLE;
//      return false;
//  }
//  else
//  {   pages[pagesCount++] = page;
//      return true;
//  }
}

double maxStoreSize = 0.0;

void grab_more_memory(size_t npages)
{
// Here I grab more memory (if I am allowed to).
// An initial version here, and one still suitable on machines that will
// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
// 3*n + 2. This expands until the proportion of the heap active at the
// end of garbage collection is less than 1/4.
// If the attempt to grab more memory fails I clear the bit in init_flags
// that allows me to try to expand, so I will not waste time again.  If
// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
// available memory may cause a crash) I do not try this operation.  The
// aim of keeping the heap less than half full is an heuristic and could be
// adjusted on the basis of experience with this code.
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
    if (init_flags & INIT_EXPANDABLE)
    {   size_t ideal = MAX_PAGES; //
//@@@@ ok_to_grab_memory(heap_pagesCount + vheap_pagesCount);
        size_t more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (maxStoreSize != 0.0)
        {   double pageLimit = maxStoreSize*1024*1024/static_cast<double>
                               (CSL_PAGE_SIZE);
// Limit memory to (about) the amount the user indicated with --max-mem
            size_t plim = (size_t)pageLimit;
            if (ideal > plim) ideal = plim;
        }
        if (ideal > pagesCount)
        {   more = ideal - pagesCount;
            while (more > 0)
            {   if (!allocate_more_memory()) break;
                more--;
            }
        }
    }
}

void init_heap_segments(double d)
{   cout << "init_heap_segments " << d << "\r" << endl;
    size_t mem;
#ifdef WIN32
    mem = getMemorySize();
#else // WIN32
// BEWARE: _SC_PHYS_PAGES is a glibc extension and is not mandated by POSIX.
// However it (maybe obviously) should work on all variants of Linux and
// experimentally it works on a Macintosh, and on Windows there is a clear
// and proper alternative... Also a FreeBSD manual page suggests that
// _SC_PHYS_PAGES will (often?) be available there. That covers some of the
// more important platforms so anybody with some alternative that is more
// specialised can patch in their own code here!
    long pageCount = sysconf(_SC_PHYS_PAGES);
    long pageSize = sysconf(_SC_PAGE_SIZE);
    mem = pageCount*static_cast<size_t>(pageSize);
#endif // WIN32
    mem /= (1024*1024);    // Physical memory now in megabytes
    size_t g3 = 3u*1024u;  // 3Gbytes
    if (mem <= 2*g3) mem = g3;
    else mem -= g3;
// I think if my machine has at most 6GB I will default to using 3GB. If
// has more than that I will use (physmem-3G) up to the stage that I
// use a total of 16GB. All subject to any --maxmem that the user had
// specified.
    static const size_t K = 16384;
    if (K < mem) mem = K;
    if (d == 0.0) d = 1024.0*1024.0*mem; // back to bytes
    if (maxStoreSize != 0.0 && maxStoreSize < d) d = maxStoreSize;
// I have to pass the amount to initHeapSegments inkilobytes. On a 32-bit
// machine I will limit myself to 1.6G here, because trying to use 2G or
// more starts to risk muddle with sign bits and address arithmetic overflow.
    if (!SIXTY_FOUR_BIT) d = 1600.0*1024.0*1024.0;
    initHeapSegments(d/1024.0);
}

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;
uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

//static intptr_t cons_cells, symbol_heads, strings, user_vectors,
//       big_numbers, box_floats, bytestreams, other_mem,
//       litvecs, getvecs;

LispObject Lgc0(LispObject env)
{   return Lgc(env, fixnum_of_int(1));
}

GcStyle userGcRequest = GcStyleNone;

LispObject Lgc(LispObject env, LispObject a)
{
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be incremental and may do hardly
// anything. This distinction will only apply once I have a generational
// collector implemented and so "incremental" collections become possible.
    for (unsigned int i=0; i<maxThreads; i++) limit[i].store(0);
// For now I will make (reclaim t) and (reclaim) force a major GC while
// (reclaim nil) will be a minor GC.
    userGcRequest = a==nil ? GcStyleMinor : GcStyleMajor;
    poll();
    return nil;
}

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

// static int stop_after_gc = 0;

// bool force_verbos = false;

// bool garbage_collection_permitted = false;

// static void real_garbage_collector()
// {
// // I lift the real garbage collector to a separate function mainly
// // so that I can set breakpoints on it!
//     for (int i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
//         free_vectors[i] = 0;
//
// }

// LispObject reclaim(LispObject p, const char *why, int stg_class, size_t size)
// {   return p;
// }

static unsigned int MEM=2u*1024u*1024u*1024u;
bool pageFull;

LispObject Lgctest_0(LispObject env)
{   LispObject a = nil;
    for (unsigned int i=0; i<MEM/16u; i++)
    {   a = cons(fixnum_of_int(i), a);
        cout << ":" << std::flush;
        if (i % 1000000 == 0)
        {   cout << i;
            LispObject b = a;
            for (unsigned int j=i; j!=static_cast<unsigned int>(-1); j--)
            {   if (!is_cons(b)) my_abort("gc test failure");
                if (car(b) != fixnum_of_int(j)) my_abort("gc test failure");
                b = cdr(b);
            }
            if (b != nil) my_abort("gc test failure");
        }
    }
    return nil;
}

LispObject Lgctest_1(LispObject env, LispObject a1)
{   LispObject a = nil, b;
    size_t n = int_of_fixnum(a1);
    for (unsigned int i=0; i<n; i++)
        a = cons(fixnum_of_int(i), a);
    cout << "list created" << "\r" << endl;
    b = a;
    for (unsigned int j=n-1; j!=static_cast<unsigned int>(-1); j--)
    {   if (!is_cons(b)) goto failing2;
        if (car(b) != fixnum_of_int(j))
        {   cout << "Fail3 case with j = " << std::dec << j << "\r" << endl
                 << " fixnum_of_int(j) = " << std::hex << fixnum_of_int(j) << "\r" << endl
                 << " car(b) = " << car(b) << " which differs" << "\r" << endl
                 << " " << (n-1-j) << " items down the list" << "\r" << endl;
            goto failing3; //<<<<<<<<<
        }
        b = cdr(b);
    }
    if (b != nil) goto failing4;
    return nil;
failing2:
    cout << "Crashed2 " << std::hex << "b = " << b
         << " car(b) = " << car(b) << "\r" << endl;
    cout << "n = " << n << "\r" << endl;
    for (int z=1; z<10; z++)
    {   cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    cout << "\r" << endl;
    return nil;
failing3:
    cout << "Crashed3 " << std::hex << "b = " << b
         << " car(b) = " << car(b) << "\r" << endl;
    cout << "n = " << n << "\r" << endl;
    for (int z=1; z<10; z++)
    {   cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    cout << "\r" << endl;
    return nil;
failing4:
    cout << "Crashed4 " << std::hex << "b = " << b
         << " car(b) = " << car(b) << "\r" << endl;
    cout << "n = " << n << "\r" << endl;
    for (int z=1; z<10; z++)
    {   cout << std::dec << (car(b)/16) << " ";
        b = cdr(b);
    }
    cout << "\r" << endl;
    return nil;
}

LispObject Lgctest_2(LispObject env, LispObject a1, LispObject a2)
{   return nil;
}

// end of newallocate.cpp
