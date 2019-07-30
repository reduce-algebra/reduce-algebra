// newallocate.cpp                         Copyright (C) 1989-2019 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//


// Development game-plan for this stuff - showing the steps or stages
// to go through:
// (1) Work towards being able to allocate vectors and lists and
//     set up an initial large chunk of memory. Hope that the code in
//     restart.cpp for a cold start can be got working again.
// (2) Test a bit of execution that can happen eithout garbage collection.
//     I rather hope that PRESERVE will then "just work", and that will
//     let me build a csl.img
// (3) Arrange that every garbage collection will be a major one and
//     re-work the allocation and re-allocation of memory blocks for that.
//     By keeping the code with precise list-bases for everything that
//     matters the ambiguous pointers should never be the only reason
//     for saving any data - they just pin things and hance mess up memory
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

/*!!! csl
*/

#include "headers.h"

//
// This is a place for my latest round of thinking about a new storage
// management scheme. The ideal I set now is that garbage collection should
// be both conservative and generational and that it should be able to
// support multiple mutator threads. I am NOT intending either to run
// garbage collection concurrently with the mutator (so the GC is a "stop
// the world" one, although most garbage collections should be "minor" ones
// and hence not too disruptive). I am also not at present planning on having
// garbage collection use more than one thread to do its work, although that
// might be seriously easier to retrofit later then having the GC and the
// mutator concurrent.

// In previous sketches relating to this I was considering using memory
// protection and thus exceptions to implement a write barrier that is needed
// to make the collector ephemeral/generational. My thoughts are now moving
// to accepting that having the operating system handle exceptions is liable
// to be unpleasantly expensive and that a software scheme can in fact have
// almost modest overhead.

// The design here has to mingle plans for global storage allocation,
// the CONS operation as well as operations involving Lisp atoms, the
// way that Lisp threads can access the values of variables, synchronization
// matters and so on. In general it seems that almost all aspects from the
// lowest to the most global level interact. So some of what I have here
// are my CURRENT notes on how I think I will make it all work. The code
// in this file is at present generall the OLD code and much of it will be
// thrown away and replaced!




size_t pagesCount;
size_t activePagesCount;

// Ha ha potentially clever idea. Have activetheads an atomic<int32_t> and use
// the bottom 10 bits for the number of threads that are busy and the next
// 10 bits for the number potentially busy and finally 10 bits for the total
// number of threads in play. That way I can eg subtract (1<<10)+1 when a
// thread temporarily removes itself from the pool because it
// may be about to block! Etc etc. The second idea is that there is potential
// misert about needing to get every thread to exit when STOP is called. Well
// maybe I can avoid using mutexes at all as places that code can block and
// instead use condition variables with a condition of the form
// (<sensible-condition> || need_to_exit) and then when the barrier is passed
// I immediately check need_to_exit and tidy up a bit more. To make that work
// I suspect I will need a table of every muxex/condition variable anywhere
// so that when I set need_tO-exit I can notify all of them!
// Well for muxexes and condition variables visible at the Lisp level I will
// need underlying C++ ones which will sort of need garbage collection but
// must never move. I think that the best bet is to have a vector pool of
// synchronization objects with the Lisp objects that encapsulate them holding
// an integer index that will need to be treated as a weak pointer to
// keep the object "alive". Whe not alive the object is just available for
// re-use... That is all going to be a bit messy.

// Another though to be left as comments here until I implement it and comment
// it where the code ends up:
// The copying GC can probably be coded so as to use multiple threads to do the
// copying! I have bits of that sketched in my mind, butil until I can sit down
// quietly with a full sized keyboard and code some of it things are a bit
// uncertain.
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
//    w = allocat1();
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
// Making almost every value std::atomic<T> might also do the job, but that
// would then imply fences everywhere and could hurt performance and it would
// also be horribly ponderous and clumsy.
// 

std::atomic<int> activeThreads;
int threadcount = 0;
bool gc_started = false, gc_finished = false;
std::mutex mutex_for_gc;
std::condition_variable cv_for_gc_idling, cv_for_gc_busy;


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
// In my first sketch here I have not put in all the data I expect to need
// to put into the header - eg I will need more to let me allocate around
// pinned items.

std::atomic<uintptr_t> Afringe;
std::atomic<uintptr_t> Alimit;

Page *nurseryPage;       // where allocation is happening
Page *pendingPage;
Page *scavengablePage;
Page *stablePages;
Page *mostlyFreePages;
Page *freePages;
size_t freePagesCount;

void *heapSegment[32];
void *heapSegmentBase[32];
size_t heapSegmentSize[32];
size_t heapSegmentCount;



// I make some assumptions about the variations on std::atomic<> that I
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
// Well std::atomic_flag is guaranteed lock-free and to my mind that would
// suggest it had no need for extra memory and I might hope it was thus
// of size 1, but this is not guaranteed either. So my code is not guaranteed
// portable! What an amazing situation (ha ha).

class MakeAssertions
{
public:
    MakeAssertions()
    {   if (sizeof(std::atomic<uint8_t>) != 1)
        {   std::cout << "Atomics bytes are too large" << std::endl;
            std::abort();
        }
        if (!std::atomic<uint8_t>().is_lock_free())
        {   std::cout << "Atomic<uint8_t> not lock-free" << std::endl;
            std::abort();
        }
        if (!std::atomic<uintptr_t>().is_lock_free())
        {   std::cout << "Atomic<uintptr_t> not lock-free" << std::endl;
            std::abort();
        }
    }
};

static MakeAssertions test_for_lockfree;

// Before checking an ambiguous pointer I need to set up the bitmap that
// notes the start-point of objects. This function does that for one page.

void recordObjectStarts(Page *x)
{   memset(x->pageBody.pageBitmaps.maps.objstart, 0,
           sizeof(x->pageBody.pageBitmaps.maps.objstart));
    LispObject *p = x->pageBody.data;
// @@ The version I have here does not yet allow fror the fact that the
// data region within the page will have some pinned objects in and they
// will all need object start tags set - and that fringe may be the
// current level of allocation but the way that interacts with interleaved
// pinned items is not really considered.
    while (reinterpret_cast<uintptr_t>(p) < x->pageHeader.fringe)
    {   size_t os = (reinterpret_cast<uintptr_t>(p) -
                     reinterpret_cast<uintptr_t>(x))/8;
        x->pageBody.pageBitmaps.maps.objstart[os/64] |= UINT64_C(1)<<(os%64);
        LispObject v = *p;
        if (!is_odds(v)) p += 2;
        else if (is_symbol_header(v)) p += symhdr_length/sizeof(LispObject);
        else p += doubleword_align_up(length_of_header(v))/sizeof(LispObject);
    }
    x->pageHeader.onstarts_present = true;
}

// For findObjectStart() the objectstart bitmap is set in the relevant page
// and I must return the untagged address of the item containing the address
// p, or NULL if there is none such. This is used when an ambiguous pointer
// is processed and it maps from the random address-like value to either 0
// which is taken to indicate that the value is not a valid pointer, or
// to the 8-byte aligned address of the start of an object that the
// address lies within. This is perhaps the part of dealing with ambiguous
// pointers that I view as having required most thought!

uintptr_t findObjectStart(uintptr_t p, Page *x)
{
// First check if p is actually within the (active) data region in the page.
    if (p < reinterpret_cast<uintptr_t>(x->pageBody.data) ||
        p >= reinterpret_cast<uintptr_t>(x->pageHeader.fringe)) return 0;
// Now, and I have NOT done this yet, I shoule cope with the case where p
// points within an item that had been pinned within page x by an earlier
// GC.
//  @@ unfinished work here
// Next search for the nearest object start at a lower address than p,
// using the objectstart bitmap to help.
    size_t os = (p - reinterpret_cast<uintptr_t>(x))/8;
    size_t word = os/64;
    int bit = os%64;
// I am going to expect that an especially common case will be when the
// pointer p is just to the start of an object with at most a tag value
// added. My division by 8 a few lines above disarded those low bits, so
// I will see if what I end up with is in fact a proper object start.
    if ((x->pageBody.pageBitmaps.maps.objstart[word] & (UINT64_C(1)<<bit)) != 0)
        return p & -(uintptr_t)8;
// The next case I will consider is if the object header is fairly close
// to p, and the word in the bitmap that covers p includes mention of it.
    if (bit != 0)
    {   uint64_t v = ((UINT64_C(1)<<bit) - 1) &
                     x->pageBody.pageBitmaps.maps.objstart[word];
// Now v records any headers just before p.
        if (v != 0)
        {   int n = 63-nlz(v);
// Convert back from an address in the bitmap to the location in memory.
            return reinterpret_cast<uintptr_t>(x) + 8*(word*64 + n);
        }
    }
// Now I can scan down 64 8-byte locations at a time, ie 512 bytes at a go.
// The distance I may need to go is certainly bounded by the possible size
// of an object that I seem to point within, but for any pointer that is
// really valid it is related to how far down that object I am pointing,
// and so to have a really bad cost here I would have to have a (probable)
// pointer referring to almost the end of a huge object. Because of the
// finite size of a page the very worst cost could be going round the
// simple loop 16K times. Well in fact it is better than that. These days
// the largest basic Lisp object I ever create is of size maybe pageSize/4
// (specifically VECTOR_CHUNK_BYTES), and this sets the worst case distance
// that it can ever be necessary to scan to find an object start.
    word--;
    while (x->pageBody.pageBitmaps.maps.objstart[word] == 0) word--;
// The loop must terminate because any page either has no data in it at all,
// and in that case an ambiguous pointer will be detected as invalid because
// it addresses above fringe, or it will have at least one item in it,
// including one right at its start.
// I will need to double-check this when I put in full support for items that
// where pinned by the last garbage collection, including the case where the
// very first item in the page has that status. Anyway when I find a nonzero
// entry in the map the top bit it identifies the highest-addressed object
// start, and that is what I want.
    int n = 63-nlz(x->pageBody.pageBitmaps.maps.objstart[word]);
    return reinterpret_cast<uintptr_t>(x) + 8*(word*64 + n);
}

// Here we have a function to call during a major garbage collection. It is
// given an (ambiguous) pointer. If necessary it established an objectt-start
// map for the page that addresses, and then it marks as pinned the object
// referenced.

void setPinnedMajor(uintptr_t p)
{   Page *x = findPage(p);
    if (x == NULL) return;
    if (!x->pageHeader.onstarts_present) recordObjectStarts(x);
    uintptr_t os = findObjectStart(p, x);
    if (os == 0) return;
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// At the start of a minor garbage collection it it is necessary to call
// this so that the start-point of all objects in the scavengable region
// are known. This is done explicitly rather than having it done
// conditionally on each case where a pointer (seems to) refer to that region.

void recordObjectStartsMinor()
{   recordObjectStarts(scavengablePage);
}

// Set a pinned bit for an address if it lies within the single scavengable
// page that exists during a minor collection.

void setPinnedMinor(uintptr_t p)
{
// If the address is not in the scavengable page I can ignore it.
    if (!inScavengablePage(p)) return;
// Find the object within the page that it is within, or return NULL if none.
// This will always return a value that is an address aligned zero mod 8.
    uintptr_t os = findObjectStart(p, scavengablePage);
    if (os == 0) return;
// Now I set a bit in the pinned map.
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// Just to provide a level of abstraction I provide a function that clears
// the pinned map in a page. At the start of a minor collection this should
// be called on the scavengable region. Before a major collection on all
// pages.

void clearPinnedMap(Page *x)
{   memset(x->pageBody.pageBitmaps.maps.pinned, 0,
           sizeof(x->pageBody.pageBitmaps.maps.pinned));
}

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
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = get_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
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
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

inline Header make_padding_header(size_t n)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_PADDER;
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
    vechdr(v) = TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED;
    len = doubleword_align_up(len);
    if (len != oldlen) vechdr(v + len) = make_padding_header(oldlen-len);
    return v;
}

// As well as shrinking vectors the hash table code can want to "borrow"
// space by allocating vectors (never lists) from the half of memory that
// the copying garbage collector is not keeping live data in at present.
// The protocol I have is that it goes
//      prepare_for_borrowing();
//      ... get_vector() ... get_vector() ...
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

// Perhaps I could invent and then use an alternative protocol so that each
// thread could do its own borrowing without messy clashes. Perhaps the main
// issue there is recovering memory when a thread has finished. To think
// about how vital that might be I would need to consider whether hash tables
// might need rehashing multiple times between garbage collections - if the
// answer is "no" then each hash table could have its own associated
// borrowed shadow ... that starts to sound sensible to me! I will get a LOT
// more of this code working before I worry about that detail.

void prepare_for_borrowing()
{   my_abort();
}

// It would be a fatal error if there was not space for the borrow!

LispObject borrow_n_bytes(size_t n)
{   my_abort();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   size_t allocSize = (size_t)doubleword_align_up(size);
    if (allocSize > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = borrow_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

LispObject borrow_vector(int tag, int type, size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
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
// I put the code here adjacent to the code that allocates from pages so
// that the setup and use can be compared.

static_assert(spareBytes/64 > offsetof(Page, pageHeader.endOfHeader));

void set_up_empty_page(Page *p)
{   p->pageHeader.fringe = reinterpret_cast<uintptr_t>(&p->pageBody.data);
    p->pageHeader.limit = reinterpret_cast<uintptr_t>(p) + sizeof(Page);
    p->pageHeader.dirtypage.store(false);
    p->pageHeader.onstarts_present = false;
// I would like to be able to set the dirty bitmap all zero other than by
// using the store() method one byte at a time. It is also possible that
// when I first allocate a page that page will not be put in the stable
// region of the heap so its dirty map will not be inspected - and if that is
// the case this initialization loop is not actually needed. I will put it
// in for now to be tidy! But another delicacy here is that while the map
// is defined as a vector covering the whole page, the only parts of it that
// will be used are the ones mapping addresses within pageBody.data. So
// I must not clobber memory earlier than that because the first bytes of the
// page are always needed for the pageHeader! Well what I will do is zero
// out everything from the end of pageHeader onwards.
    for (size_t i=spareBytes/64; i<2*bytesForMap; i++)
        p->pageBody.pageBitmaps.dirty[i].store(0);
}

void set_variables_from_page(Page *p)
{
// Set the variable that are used when allocating within the active page.
    Afringe = p->pageHeader.fringe;
    Alimit = p->pageHeader.limit;
}

void save_variables_to_page(Page *p)
{
// Dump global variable values back into a page header.
    p->pageHeader.fringe = Afringe;
    p->pageHeader.limit  = Alimit;
}

// This code allocates a segment by asking the operating system.
// It grabs a block that is aligned to sizeof(Page).
// The collection of segments must be stored in heapSegments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.

void allocate_segment(size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// page size. Note that this will be quite a large value!
    n = (n + pageSize - 1) & -pageSize;
    Page *r;
    void *rbase;
// If I have C++17 I can rely on alignment constraints and just allocate
// using new[]
#ifdef __cpp_aligned_new
    r = new Page[n/pageSize];
    my_assert(r != NULL);
    rbase = static_cast<void *>(r);
#else // !__cpp_aligned_new
// On older platforms I need to allocate extra memory and then use std::align
// to get the address within the bigger block that I want.
// In this case I will need to preserve the base of the full block because
// that will be what I will be able to free at the end.
    size_t N = n + pageSize - 1;
    rbase = static_cast<void *>(new char[N]);
    my_assert(rbase != NULL);
    void *work = rbase;
    work = std::align(pageSize, n, work, N);
    my_assert(work != NULL);
    r = static_cast<Page *>(work);
#endif // !__cpp_aligned_new
    heapSegment[heapSegmentCount] = r;
    heapSegmentBase[heapSegmentCount] = rbase;
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
        std::swap(heapSegmentBase[i], heapSegmentBase[j]);
        std::swap(heapSegmentSize[i], heapSegmentSize[j]);
    }
// r now refers to a new segment of size n, I want to structure it into
// pages.
    for (size_t k=0; k<n; k+=CSL_PAGE_SIZE)
    {   Page *p = reinterpret_cast<Page *>(reinterpret_cast<char *>(r) + k);
// Keep a chain of all the pages.
        set_up_empty_page(p);
        p->pageHeader.chain = freePages;
        freePages = p;
        freePagesCount++;
    }
    printf("%" PRIu64 " pages available\n", (uint64_t)freePagesCount);
}

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

// The following need to be atomic because they get updates by one thread
// and read by another. Without the std::atomic stuff the update could
// remain in a local cache of the writer thread and not reach the one that
// tries to read the information. Hmm that may not be the case if there are
// uses of mutexes and condition variables along the way, since those may
// activate suitable fences. However making these atomic will not be terribly
// costly!

std::atomic<void *> stack_bases[max_threads];
std::atomic<void *> stack_fringes[max_threads];
std::atomic<size_t> request_sizes[max_threads];
std::atomic<std::atomic<uintptr_t> *> request_locations[max_threads];

void master_gc_work()
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

void master_gc_thread()
{
// When I get here I know that actveThreads==0 and that all other threads
// have just decremented that variable and are ready to wait on gc_started.
// Before I release them from that I will ensure that gc_finished is false so
// that they do not get over-enthusiastic!
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        gc_finished = false;
        gc_started = true;
    }
    cv_for_gc_idling.notify_all();
// Now while the other threads chew on that I can perform some garbage
// collection and fill in results via request_locations[] based on
// request_sizes[].
    master_gc_work();
// Now I need to be confident that the other threads have all accessed
// gc_started. When they have they will increment activeThreads and when the
// last one does that it will notify me.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc_busy.wait(lock,
            []{ return activeThreads.load() == threadcount-1; });
    }
// OK, so now I know that all the other threads are ready to wait on
// gc_finished, so I ensure that useful variables are set ready for next
// time and release all the threads that have been idling.
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        gc_started = false;
        activeThreads.fetch_add(1);
        gc_finished = true;
        cv_for_gc_idling.notify_all();
    }
}

void idle_during_gc()
{
// If I am a thread that will not myself perform garbage collection I need
// to wait for the one that does. This needs to be done in two phases. During
// the first I know that I have decremented activeThreads and determined that
// I was the last, but I can not be certain that all other threads have done
// that. I wait until gc_started gets set, and that happens when some thread
// has found itself to be the last one. And so by construction that means that
// all other threads will be able to reach here when they get a time-slice.
// It will then of course be important that gc_started had been false before
// that and that it then remains true until there is confirmation that each
// idle thread has passed this gateway.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc_idling.wait(lock, []{ return gc_started; });
    }
// To record that threads have paused they can then increment activeThreads
// again. When one of them increments it to the value threadcount-1 I will
// know that all the idle threads have got here, and I nofify the master GC
// thread.
    bool inform = false;
    {   std::lock_guard<std::mutex> guard(mutex_for_gc);
        if (activeThreads.fetch_add(1) == threadcount-2) inform = true;
    }
    if (inform) cv_for_gc_busy.notify_one();
// Once the master thread has been notified as above it can go forward and
// in due course notify gc_finished. Before it does that it must ensure that
// it has filled in results for everybody, incremented activeTHreads to
// reflect that it is busy again and made certain that gc_started is false
// again so that everything is tidily ready for next time.
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc_idling.wait(lock, []{ return gc_finished; });
    }
}

// Here I have just attempted to allocate n bytes but the attempt failed
// because it left fringe>=limit. I must synchronmize with all other
// threads and one of the threads (it may not be me!) must garbage collect.
// When they synchronize with me here the other threads will also have tried
// an allocation, but the largest request any is allowed to make is
// VECTOR_CHUNK_BYTES (at present 1 megabyte). If all the max_threads do
// this they can have caused fringe to overshoot by about an amount
// max_threads*VECTOR_CHUNK_BYTES and if that caused uintptr_t arithmetic to
// overflow and wrap round then there could be big trouble. So when I
// allocate chunks of memory I ought to ensure that none has an end-address
// that close to UINTPTR_MAX! I think that on all realistic systems that is
// a problem that will not actually arise.
//
// I must arrange that memory close to where the failed allocation arose is
// left tidy. I will put in a padder item if needbe just to be cautious. And
// I must arrange that whether I am the thread that does GO or one of the
// others that I return a valid allocation address.

uintptr_t gc_and_allocate(uintptr_t r, size_t n)
{   return with_clean_stack([&]
    {   std::atomic<uintptr_t>rr;
        rr.store(r);
// The use of std::atomic for rr is so that it can be updated by one
// thread and then read by another.
        request_locations[thread_id].store(&rr);
        request_sizes[thread_id].store(n);
// The next line will count down the number of threads that have entered
// this synchronization block. The last one to do so can serve as the
// thread that performs garbage collection, the other will just need to wait.
        int a = activeThreads.fetch_sub(1);
        if (a == 1) master_gc_thread();
        else idle_during_gc();
// The thread that performs garbage collection must perform allocation on
// behalf of every thread.
        return rr.load();
    });
}

LispObject *nilSegmentBase, *stackSegmentBase;
LispObject *nilSegment, *stackSegment;
LispObject *stackBase;

void initHeapSegments(double storeSize)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
{
// I will make the default initial store size around 64M on a 64-bit
// machine and 512M on a 64-bit system. If the user specified a "-K" option
// they can override this, and also the system will tend to allocate more
// space (if it can) when its memory starts to get full.
    size_t freeSpace = (SIXTY_FOUR_BIT ? 512 : 64)*1024*1024;
    size_t request = (size_t)storeSize;
    if (request != 0) freeSpace = 1024*request;
// Now freeSpace is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heapSegmentCount = 0;
    freePages = NULL;
    printf("Allocate %" PRIu64 " Kbytes\n", (uint64_t)freeSpace/1024);
    allocate_segment(freeSpace);

// There are other bits of memory that I will grab manually for now...
// and at present csl.cpp ALSO sets them up... @@@@
#if defined __cpp_aligned_new && defined HAVE_ALIGNED_ALLOC
    nilSegment = nilSegmentBase =
        reinterpret_cast<LispObject *>(
            aligned_alloc(16, NIL_SEGMENT_SIZE));
#else
    nilSegment =
       reinterpret_cast<LispObject *>(malloc(NIL_SEGMENT_SIZE+32));
    nilSegment = static_cast<LispObject *>(
        doubleword_align_up(static_cast<uintptr_t>(nilSegment_base)));
#endif
    if (nilSegment == NULL) fatal_error(err_no_store);
    nil = (LispObject)((uintptr_t)nilSegment + TAG_SYMBOL);
#if defined __cpp_aligned_new&& defined HAVE_ALIGNED_ALLOC
    stackSegment = stackSegmentBase =
        reinterpret_cast<LispObject *>(
            aligned_alloc(16, CSL_PAGE_SIZE));
#else
    stackSegment =
        reinterpret_cast<LispObject *>(malloc(CSL_PAGE_SIZE+32));
    stackSegment = static_cast<LispObject *>(
        doubleword_align_up(static_cast<uintptr_t>(stackSegment_base)));
#endif
    if (stackSegment == NULL) fatal_error(err_no_store);
    stackBase = (LispObject *)stackSegment;
}

void drop_heapSegments(void)
{   for (size_t i=0; i<heapSegmentCount; i++)
        delete [] static_cast<Page *>(heapSegmentBase[i]);
    free(nilSegmentBase);
    free(stackSegmentBase);
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   return false;
//  if ((init_flags & INIT_EXPANDABLE) == 0) return false;
//  void *page = (void *)aligned_alloc((size_t)CSL_PAGE_SIZE);
//  if (page == NULL)
//  {   init_flags &= ~INIT_EXPANDABLE;
//      return false;
//  }
//  else
//  {   pages[pagesCount++] = page;
//      return true;
//  }
}

extern double maxStoreSize;

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
        {   double pageLimit = maxStoreSize*1024*1024/(double)CSL_PAGE_SIZE;
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


#ifdef WIN32
#include <conio.h>
#endif

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;
uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

//static intptr_t cons_cells, symbol_heads, strings, user_vectors,
//       big_numbers, box_floats, bytestreams, other_mem,
//       litvecs, getvecs;

LispObject Lgc0(LispObject env)
{   return Lgc(env, lisp_true);
}

LispObject Lgc(LispObject env, LispObject a)
{
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be soft and may do hardly
// anything.
#if 0
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
#endif
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
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}

bool volatile already_in_gc;
bool volatile interrupt_pending;
LispObject volatile saveheaplimit;
LispObject *volatile savestacklimit;

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


// I put the signal handler code in this file at a stage when I was
// considering a write-barrier implemented using write-protected memory
// pages. I think I have now come to believe that the operating system
// overheads involved in memory-access exception handling would make that
// even more expensive that the scheme I now have that is entirely in
// software.

#ifdef USE_SIGALTSTACK

static unsigned char signal_stack_block[SIGSTKSZ];
stack_t signal_stack;

#endif

#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *t, void *v);
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo);
#endif // !HAVE_SIGACTION

void set_up_signal_handlers()
{
//
#ifdef USE_SIGALTSTACK
// If I get a SIGSEGV that is caused by a stack overflow then I am in
// a world of pain because the regular stack does not have space to run my
// exception handler. So where I can I will arrange that the exception
// handler runs in its own small stack. This may itself lead to pain,
// but perhaps less?
    signal_stack.ss_sp = (void *)signal_stack_block;
    signal_stack.ss_size = SIGSTKSZ;
    signal_stack.ss_flags = 0;
    sigaltstack(&signal_stack, (stack_t *)0);
#endif
    for (int i=0; i<32; i++)
        heapSegment[i] = reinterpret_cast<void *>(UINTPTR_MAX);
#ifdef HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_sigaction = low_level_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO; //???@@@ | SA_ONSTACK | SA_NODEFER;
// (a) restart system calls after signal (if possible),
// (b) use handler that gets more information,
// (c) use alternative stack for the handler,
// (d) leave the exception unmasked while the handler is active. This
//     will be vital if then handler "exits" using longjmp, because as
//     far as the exception system is concerned that leaves us within the
//     handler. But after the  exit is caught by setjmp I want the
//     exception to remain trapped.
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#ifdef SIGBUS
    if (sigaction(SIGBUS, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#endif
#ifdef SIGILL
    if (sigaction(SIGILL, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#endif
    if (sigaction(SIGFPE, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#else // !HAVE_SIGACTION
#ifndef WIN32
#error All platforms other than Windows are expected to support sigaction.
#endif // !WIN32
    signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
    signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
    signal(SIGILL, low_level_signal_handler);
#endif
    signal(SIGFPE, low_level_signal_handler);
#endif // !HAVE_SIGACTION
}

// Elsewhere I worry about thread_local performance but here in the code that
// recovers after an exception I am not worried about that.

static volatile thread_local char signal_msg[32];

static volatile char *int2str(volatile char *s, int n)
{   unsigned int n1;
// Even though I really only expect this to be called with small positive
// arguments I will code it so it should support ANY integer value, including
// the most negative one.
    if (n >= 0) n1 = (unsigned int)n;
    {   *s++ = '-';
        n1 = -(unsigned int)n;
    }
    if (n1 >= 10)
    {   s = int2str(s, n1/10);
        n1 = n1 % 10;
    }
    *s++ = '0' + n1;
    return s;
}

#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *si, void *v)
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo)
#endif // !HAVE_SIGACTION
{
// There are really very restrictive rules about what I can do in a
// signal handler and remain safe. For a start I should only reference
// variables that are of type atomic_t (or its friends) and that are
// volatile, and there are fairly few system functions that are
// "async signal safe" and generally permitted. However I am going to
// stray well beyond the rules here! Well in most cases I will view this
// as acceptable, because in most cases these low level signals will only
// arise in case of a system-level bug, and so ANY recovery or diagnostic
// I can produce will be better than nothing, and if things get confused
// or crash again then that is not much worse than the exception having
// arisen in the first case!
    if (miscflags & HEADLINE_FLAG)
    {   switch (signo)
        {   default:
                {   volatile char *p = signal_msg; // NB thread-local memory
                    const char *m1 = "Signal (signo=";
                    while (*m1) *p++ = *m1++;
                    p = int2str(p, signo);
                    *p++ = ')';
                    *p = 0;
                }
                errorset_msg = signal_msg;
                break;
#ifdef SIGFPE
            case SIGFPE:
                errorset_msg = "Arithmetic exception";
                break;
#endif
#ifdef SIGSEGV
            case SIGSEGV:
                errorset_msg = "Memory access violation";
                break;
#endif
#ifdef SIGBUS
            case SIGBUS:
                errorset_msg = "Bus error";
                break;
#endif
#ifdef SIGILL
            case SIGILL:
                errorset_msg = "Illegal instruction";
                break;
#endif
        }
    }
// I am NOT ALLOWED TO USE THROW to exit from a signal handler in C++. I
// can at best try use of longjmp, and that is not really legal
// This has the malign consequence that destructors
// associated with stack frames passed through will not be activated. And
// I use destructors in a RAII style to tidy up bindings at times, so I
// hope I never do a really long longjmp, because that would bypass things!
    global_longjmp();
}

// end of newallocate.cpp
