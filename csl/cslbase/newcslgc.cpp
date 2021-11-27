// File newcslgc.cpp                      Copyright (c) Codemist, 2018-2021

//
// Garbage collection. This is a version intended to be conservative
// from the outset but to be structured so that it can be incrementally
// entended to be generational, so that it supports threads in the Lisp
// run time and so that it can at least experiment with concurrency within
// parts of garbage collection. All that scope for generalisation has
// caused me repeated pauses in the design process, and various evaluations
// of performance issues have also meant that getting this going has been a
// long haul. See newallocate.h for a few comments on the time-line!
//

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

#include "headers.h"

// Pinning:
// When I have an ambigious pointer any object it (might) point at must
// not be relocated by the GC, and that means that subsequent allocation must
// work around such static data. What I describe here is my April 2021 set of
// thoughts, which are a significant update to ones from earlier!
// There are three stages where these ambiguous pointers impact what I have
// to do:
// (1) Identifying them at the start of garbage collection;
// (2) Tracing and processing data pointed at from pinned regions;
// (3) Coping with pointers from live data to pinned items;
// (4) Arranging free storage so that subsequent allocation does not
//     overwrite them.
// The scheme I use interacts with the general storage allocation procedures
// that I use, which are themselves conditioned by thoughts of concurrency
// and thread support.
//
// I will comment on (3) first. When I inspect a (precise) pointer during the
// copy phase of the GC I must check if it in fact points to data that is
// "pinned" because an ambiguous pointer appears to refer to it. This test
// has to be made for every pointer considered, and so is speed critical.
// To spell things out further, if a safe, valid, precise pointer from any
// list base or from anywhere within the active heap happens to point at a
// pinned object then it must detect that fact and avoid relocating the
// object.
// To make this acceptably fast I will use a bitmap. Given the precise pointer
// I mask it based on my page size - that gets me to the base of the Page that
// it lies within. In the header to that page there is a map with 1 bit for
// each 8-byte unit. If the Page is 8 Mbytes this map is only 128K so as a
// burden on space it is not a disaster.
// With that design decision made I now need to cope with the other issues.
// Note that the bitmap I have just discussed must have a bit set to mark
// the first or header word of every object. That is because when it is
// inspected only precise pointers and so pointers refer to that header.
// It would not make sense to have to check for pin-bits elsewhere!
// The hard part of (1) is that an ambiguous pointer may (appear to) point
// into the middle of a large object that contains binary information. For
// instance a string or a bignum. Any inspection of data near where the
// reference points then sees part of that arbitrary material which can
// not be relied upon to be informative.
// My resolution of this is to note that for the purposes of allocation in
// a threaded implementation I have my memory split into "Chunks". These
// are typically 16Kbytes long but have to be longer when a huge object
// get allocated, but even when that happens the number of items within any
// one Chunk will be around 1000 on a 64-bit machine (or up to twice that
// on a 32-bit system).
// So when I am recording ambiguous pointers I will take two steps. The
// easy one is to mark in my bitmap the 8-byte address referenced. If the
// value was in fact pointing at or very close to the object head that
// is great, but in general it will mark some memory within an object. The
// harder part is that I will identify and mark the Chunk containing the
// address. Well given the pointer I can identify the Page that it lies within
// using a simple masking operation. Each Page will then need to contain a
// sorted table of the Chunks within it. There can be at most about 500
// Chunks so a binary search costs about 9 comparisons. I set a flag in the
// Chunk header to the effect that it contains pinned data and I push it
// onto a chain of such Chunks. I am going to expect that when ambiguous
// pointers are found on the stack that very often a bunch of them will
// refer to objects allocated at about the same time and that those objects
// will tend to cluster in memory and hence within a modest number of Chunks.
// After collecting all ambiguous values in that way I need to refine the
// bitmaps so that they have a bit set for the header of each pinned item. I
// have to perform a linear scan of each Chunk that contains pinned data.
// For each object present I need to consult the bitmap to see if a bit is
// set for some address within it. While doing so I will clear any bits
// associated with non-header locations. This can be optimised by using
// the fact that I can use word operations in the bitmap to check 32 or
// 64 locations at at time. In the first version of the code I will not
// do that optimizations - and ideally at a later stage I will measure to
// see if it is liable to be useful.
// HMMMM - later on I note that an ambiguous pointer must only lead to
// pinning if it refers either within data allocated from the start of the
// previous GC onwards. The procedure above copes for that provided the
// pointer is within a newish Chunk. But one any Busy or MostlyFree page
// there can also be Chunks left over by the previous GC just because they
// used to contain pinned data. The regions within them that are not
// actually pinned may contain the remains of old evacuated structure
// and that must never be pinned. So my new plan is that when during GC
// I have found the starts of every pinned item I form a list to record
// that. At the start of the next GC when I identify the Chunk that an
// address is within it it was a pinned chunk I will need to scan the
// data from this list to see if I have a possible reference to something
// that might be live.
// For (2) I note that each Chunk that contains pinned material is also
// liable to contain non-pinned stuff, and as I evacuate from fields in
// pinned data I may move some of that non-pinned data. That leaves behind
// forwarding pointers. Their presence would make a linear scan of the
// Chunk less pleasant (although not impossible!) if I did it based on
// parsing the data. But by virtue of having arranges that the bitmap only
// has pinned bits for the heads of pinned items I can use it to help me
// visit just the pinned material.
// Now to issue (4). Allocating around a pinned item has overhead, and so
// I for later storage allocation purposes I will view whole Chunks as
// pinned. Well I can take a Chunk that contains pinned items within it and
// truncate it so it starts with the first pinned item and ends with the last.
// That is easy and avoids memory waste. However perhaps unexpectedly it has
// a down-side. If pinned Chunks shrink then new Chunks can be allocated
// near them. It in turn collects pinned data. Over time one can end up with
// many small pinned regions. As well as being bad for allocation costs this
// could give trouble with step (1) as explained above where a table of all
// Chunks in a page is used. The fixed size for this table could not cope with
// many many small pinned Chunks.
// My proposed resolution adds two complications to the simple truncation
// scheme. First, pinned chunk truncation is only performed if the Page
// has at most 5 Chunks that contained pinned items (the number 5 is subject
// to review!) and the Chunk table is made 5 entries larger than it might
// otherwise have been. Secondly if two Chunks end up pinned and the gap
// that would end up between them would be lower than the standard Chunk size
// then those two are consolidated into one bigger Chunk. Well more than just
// two Chunks may end up merged, leading to an especially large blocked
// region in worst case behaviour. For a first implementation I will not
// perform this truncation - it may in fact be a micro-optimisation that
// would not improve things enough to be justified.
//

// Overview of procedure for full garbage collection:
//
// I have Pages (8M) and Chunks (16K). Pinning is at a granularity of Chunks.
//
// First I will provide a reminder of the fields and data involved in
// pinning things.
//
// When a page has pinned regions within it its chunkCount field will be
// non-zero, because the pinned regsions will be represented as Chunks.
// When testing if an ambiguous pointer is pinned I will arrange that the
// chunkMap be sorted so I can identify the Chunk that an address is within
// using binary search.
// A field chunkMapSorted is used to avoid too many repeat sorting steps.
// Binary search of chunkMap lets me identify a candidate Chunk for an
// ambiguous pointer and then pointsWithin() tests if the address is within
// the used data portion of that Chunk. If so an isPinned flag indicates
// whether the Chunk is a pinned one and when it first becomes pinned it is
// pushed on the page's pin chain list using its chunkPinChain field.
// When the first Chunk on a Page is pinned the hasPinned flag in the
// Page is set and the Page is pushed onto pagesPinChain through its
// pagePinChain field.
// Note that the process of pinning something never creates a new Chunk, so
// the chunkMap just needs to be as established while allocation within the
// Page was happening, and the it only needs sorting once at the start of
// a GC.
// When at some later stage it is necessary to allocate within a Page that
// has some pinned Chunks the otherwise empty Page should end up with
// a chunkMap that only mentions the pinned Chunks. This is all dealt with
// in setUpUsedPage. the chunkMap is cleared and then re-created from the
// list chunkPinChain. That may leave it is an arbitrary order, so it is then
// sorted and with that done chunkPinChain can be re-created in ascending
// order. Then fringe and limit are set up within the Page. limit will
// point to the first pinned Chunk. That will have a length field indicating
// where there is free space beyond it and a chunkPinChain entry that refers to
// the start of the next pinned Chunk (and hence the end of the free region).
//
// Pages are classified as BUSY, MOSTLYFREE or FREE and have a pageClass
// indicating which applies.
//
// Of the BUSY pages two will be specially identified - currentPage and
// previousPage, but all busy pages will be chained on busyPages. While
// the system is NOT in the garbage collector currentPage is where allocation
// is proceeding. Its limit may refer to the start of a pinned Chunk within
// it. As the GC is entered (and as it graduated to become previousPage)
// every Chunk will have its chunkFringe filled in to show the limit of
// valid material stored in it. This is in case the Chunk ends up pinned,
// in which case all objects stored in it will need to be treated as precise
// list bases - they are identified using a linear scan of the (active part
// of) the Chunk. At an earlier stage I had planned to put padder objects
// to full every chunk right up to the end, but by following the current
// plan I can arrange that when a pinned chunk survives garbage collection
// and ends up in a MostlyFree page it gets truncated down to its chunkFringe,
// and that avoids a bit of memory waste.
//
// MOSTLYFREE pages are chained on mostlyFreePages while FREE ones are on
// freePages.
//
// During early stages of Garbage Collection all BUSY pages and all MOSTLYFREE
// ones will need their chunkMaps. Neither need any pagePinChain information.
// At the time I sort the chunkMap (ie when I find the first pin in the
// Page) I must reset the isPinned flag on all Chunks in that page and
// chear the pagePinChain. Then while pinning a Chunk those two get updated.
// The situation after that is that I end up with a list of the Pages that
// contain pinned Chunks this time, and within each such Page I can identify
// those Chunks easily. 
//
// Now move busyPages to oldPages and set up a new CurrentPage. While
// performing a major GC always allocate a MOSTLYFREE page rather than a
// fully free one if possible. This is because doing to embeds the previously
// pinned data among newly copies data. Much of it is liable NOT to be
// pinned on the next garbage collection (because I hope that values on the
// stack will have changed by then). So by doing that the stuff pinned by the
// previous GC will have a chance to be fully recovered by the next one.
//
// Scan the stack (ie the "ambiguous bases") so that Chunks in OldPages and
// MostlyFree that are accessible via that collection of values are marked
// as pinned. Note that the only Chunks present in the MostlyFree pages will
// be ones that has been pinned last time, and so things there that are
// pinned now are "re-pinned".
//
// Hmm - there is a messy issue about my current plans - it is a worst-case
// matter not one liable to occur in any normal use.
// With my concurrent-allocation scheme there can be waste space due to
// fragmentation when the code attempts to allocate a large object. Suppose
// my target chunk-size is C and I first allocate single small item then
// try to allocate something of size C. It will not fit and I will have to
// allocate a fresh chunk. I have some lack of clarity in my mind about
// the consequences of size-choice for the new chunk, but if it either JUST
// fits the new object (and I then allocate yet another standard-sized new
// chunk beyond it or it the new chunk is object-size+C I think we end up
// with an occupancy of around 50%.
// Now suppose that ordinary operation has by magic achieved perfect packing
// but the GC (while copying into its new space) suffers worst-case
// fragmentation. It gums up unless GC was triggered when total system
// memory was (1/3) full. One can not afford to wait until it is (1/2) full.
// With the scheme I have of Pages (8MB) and a limit I set at 2MB for any
// individual object I can have only 75% of a page occupied when a big
// vector will fail to fit at the end. That puts a limit at a bit over 42%
// and that applies in the system I had before this re-written GC.
// Well I now thing that if I put these together I spot that space wasted
// at the end of the Page will lead to a nice big contiguous block at the
// start of the next Page, and in the end my previous calculation that a
// major GC needs to be triggered when memory is (1/3) full stands.
//
// For statistical and evaluation purposes at this stage it will be
// interesting to see how many Pages contain pinned Chunks and both how
// many Chunks are involved and what proportion of the Pages concerned they
// use. That will be information I can gather before getting all the rest
// of the GC working!
//
// Evacution:
//   If the location to be evacuated holds immediate data do nothing,
//     otherwise it holds a pointer to some object.
//   If that object is to something in a MostlyFree page or one of the
//     pages I am at present allocating in then it must be to something that
//     had been pinned last time. So do nothing.
//   Now it is points into an oldPage. I must check if it is in a
//     pinned Chunk. Well at this stage I will have set things up so that
//     the ONLY Chunks in the chunkMap of such a page are the [newly] pinned
//     ones and I do not expoct there to be many, so binary search in the
//     chunkMap should be quick. If into a pinned chunk it is left alone.
//     That will be something that had been pinned both in a previous GC
//     (and hence ended up mingled with live data) and pinned again this
//     time.
//   If the CAR field of the object holds a forwarding address use that to
//     update the location to be a proper pointer to relocated data.
//     The item pointed at will need to be inspected to reconstruct the
//     proper tag bits for the adjusted reference. Done!
//   Make a (binary) copy of the object in the next free space within C.
//   Set the CAR field to be a forwarding address to the copy.
//
// Note that the copy will then (in due course) be scanned. For that to be
// feasible the Pages where I allocate copied material (including pinned
// Chunks embedded within them) must be such that I can perform a linear
// scan, so chunkFringe must be set up where relevent.
//
// My first version of the major GC will run sequentially, however in the
// future I hope to experiment with concurrency within it. So I will write
// this as for a parallel implementation, although for that the details
// above under "Evacuation" will need to be enhanced to allow for thread
// interlocks.
//
// The GC has two parts. In one - seeding - the precise list bases are
// evacuated. I will seed from all the static precise list bases (ie
// variables and arrays in the C++ code) and also from each item present in
// a pinned chunk.  This part is done in the master thread. I expect that the
// total number of items processed will be reasonably modest, but in the
// worst case there could be quite a lot of pinned material. An initial
// evaluation suggests that in a fairly heavy case I may evacuate around
// 100K items here - around (1/5) of a Page-full.
// From then on I need to scan and evacuate all copied material. I do that
// Chunk by Chunk, and when within a Page I find a Chunk tagged as with
// isPinned I know it has already been processed. I hope to distribute
// Chunks to different threads for processing, and then in the same way that
// multiple threads can allocate during normal use, each GC thread will
// have its own Chunk that it is copying material into.
// Apart from the administration of thread start-up that is fairly clean and
// easy! When any thread completes evacuating a chunk it needs to grab
// another. That will usually happen using an atomic increment instruction
// much as in storage allocation.
// There is then a significant complication towards the end of GC. When
// a thread completes filling up a chunk with evacuated data it will push
// that chunk onto a needsEvacuating chain. When it completes clearing a
// chunk then the cleared chunk can not be re-used yet. The thread tries
// to grab another from needsEvacuating. That list may be empty, and in
// that case it should start evacuating the Chunk it is currently evacuating
// within. If it catches up with the fringe there it needs to wait until
// a new chunk needs to be evacuated. Eventually every thread will be paused
// on that basis: the evacuation phase of GC will be complete. 
// Well I talk cheerily there of a chain of chunks recently filled by the
// evacuation process. In a single-thread world this does not need much
// because Chunks can be scanned sequentially through Pages. The relevent
// Pages will need to be chained but that is simple.
// In a multi-thread world this is much much less nice! I will certainly
// need a thread-safe process to identify the next sequential Chunk within
// a page. Well this feels like the need for a "lock free pop" but it is
// in the especially happy case that it traverses a chain that is not being
// updated, so the mess of the ABA problem does not arise.
// The uglier issue is that Chunks do not get completely filled sequentially,
// and so one could have the sequential scan needing to skip past (several)
// chunks that are in the process of being filled by other threads. A bad
// case for this might be if one thread is processing a chunk that contains
// references to very many rather large vectors - as it processes these it
// need to allocate additional Chunks (that will need scanning later). A
// different thread keeps performing a linear scan to find another Chunk
// to process - and gets as far as the now-in-use Chunk and has to skip past
// it. I think that means that a large number of Chunks could end up "left
// behind". These need to be recorded on a chain and a lock-free stack seems
// what is needed. Well if every completed Chunk is placed on this stack
// then the linear scan of Chunks is not needed. Note that every Chunk
// that is involved gets put on this stack just once and removed just once
// (per GC) so the ABA issue does not arise and implementing the stack can
// follow the recipe often characterised as "naive".
// The final mess is that to select a Chunk to scan it will be necessary
// to pop from the chain there and if that is empty to wait until either
// another Chunk is made available by some other thread or until every
// thread is also stalling.
// At this stage in the explanation I can adjust something said before: I
// need to seed from all pinned chunks. That can be done by just pushing
// those chunks ono the stack that I have just described and then their
// contents will be processed (potentially in a multi-threaded manner)
// as part of the normal scheme of things.




// Code for sorting "lists"...

// This is to sort some form of structure that is in abstract terms a list.
// The "list" is passed and returned an an item of type Concrete. This might
// but a type that is a pointer to a node object, or it could be "void *"
// where implementation details are being hidden from other parts of the
// code, or it might be "uintptr_t" and a handle for the start of the list.
// Abstract then needs to be a class that provides a collection of static
// methods to inspect and update the list. Because this sorts the list
// in-place there is no need for any storage allocation. I will expect that
// the Concrete type is small, so that creating an array of length 1000 will
// not strain stack-size.

#include <algorithm>

template <typename Concrete, class Abstract>
Concrete sortList(Concrete a)
{   if (Abstract::isNil(a)) return a; // a trivial case
// Count the length of the list.
    size_t n = 0;
    for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b)) n++;
// If the list is short enough then I will copy the data to a simple
// C++ array, use std::sort to get it in the right order and then patch
// things back into list form.
    const size_t LIMIT = 1000;
    if (n < LIMIT)
    {   Concrete v[LIMIT];
        size_t i=0;
        for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b))
            v[i++] = b;
        std::sort(&v[0], &v[n], Abstract::before);
        Concrete r = v[0];
        Concrete pr = r;
        for (i=1; i<n; i++)
        {   Abstract::rplacd(pr, v[i]);
            pr = v[i];
        }
        Abstract::rplacd(pr, Abstract::nil());
        return r;
    }
// If I have too much data to be able to sort it all at once I will partition
// into two lists, sort each and then merge. The partitioning does not need
// to preserve ordering at all.
    Concrete l1 = Abstract::nil();
    Concrete l2 = Abstract::nil();
    while (!Abstract::isNil(a))
    {   Concrete w = a;
        a = Abstract::cdr(a);
        Abstract::rplacd(w, l1);
        l1 = w;
        if (!Abstract::isNil(a))
        {   w = a;
            a = Abstract::cdr(a);
            Abstract::rplacd(w, l2);
            l2 = w;
        }
    }
    l1 = sortList<Concrete,Abstract>(l1);
    l2 = sortList<Concrete,Abstract>(l2);
// Now merge.
    Concrete r = Abstract::nil();
    Concrete rp = r;
    bool some = false;
    while (!Abstract::isNil(l1) &&
           !Abstract::isNil(l2))
    {   if (Abstract::before(l1, l2))
        {   Concrete w = l1;
            l1 = Abstract::cdr(l1);
            if (some)
            {   Abstract::rplacd(rp, w);
                rp = w;
            }
            else
            {   r = rp = w;
                some = true;
            }
        }
        else
        {   Concrete w = l2;
            l2 = Abstract::cdr(l2);
            if (some)
            {   Abstract::rplacd(rp, w);
                rp = w;
            }
            else
            {   r = rp = w;
                some = true;
            }
        }
    }
    if (Abstract::isNil(l1)) Abstract::rplacd(rp, l2);
    else Abstract::rplacd(rp, l1);
    return r;
};

// Pages are chained via a "chain" field. I will want to
// sort the list of mostlyFreePages based on their memory address.

class PageListClass
{
public:
    static Page *nil()
    {   return (Page *)0;
    }
    static bool isNil(Page *p)
    {   return p == (Page *)0;
    }
    static Page *cdr(Page *p)
    {   return p->chain;
    }
    static void rplacd(Page *p, Page *x)
    {   p->chain = x;
    }
    static bool before(Page *x, Page *y)
    {   return (uintptr_t)x < (uintptr_t)y;
    }
};

Page *sortPages(Page *p)
{   return sortList<Page *, PageListClass>(p);
}

// I will have a list of pinned items, with chaining through what would
// normally be the CAR field and with chaining pointers using TAG_FORWARD.
// I will want this sorted on the address value stored in the CDR field.

class PinChainClass
{
public:
    static uintptr_t nil()
    {   return TAG_FORWARD;
    }
    static bool isNil(uintptr_t p)
    {   return p == TAG_FORWARD;
    }
    static uintptr_t cdr(uintptr_t p)
    {   return ((uintptr_t *)(p-TAG_FORWARD))[0];
    }
    static void rplacd(uintptr_t p, uintptr_t x)
    {   ((uintptr_t *)(p-TAG_FORWARD))[0] = x;
    }
    static bool before(uintptr_t x, uintptr_t y)
    {   return ((uintptr_t *)(x-TAG_FORWARD))[1] <
               ((uintptr_t *)(y-TAG_FORWARD))[1];
    }
};

uintptr_t sortPinList(uintptr_t l)
{   return sortList<uintptr_t, PinChainClass>(l);
}

bool gcComplete;
Chunk *pendingChunks = nullptr;
std::condition_variable cvForChunkStack;
unsigned int activeHelpers = 0;

// I originally planned to make this a lock-free data structure, or at
// lease code it so that it was lock-free most of the time. However I
// will want to use a condition variable to deal with the issue of
// whether the queue has any items in it at all, and that rather forces
// the use of a mutex.

void pushChunk(Chunk *c)
{   std::lock_guard<std::mutex> lock(mutexForGc);
    Chunk *old = pendingChunks;
    if (gcTrace) cout << "Push " << Addr(c) << " onto queue [" << Addr(old) << "]\n";
    c->pendingChunks = old;
    pendingChunks = c;
// If I put a new Chunk onto an otherwise empty queue then I will need to
// wake up any threads that had been waiting for something to do.
    if (old == nullptr) cvForChunkStack.notify_all();
}

Chunk *popChunk()
{   std::unique_lock<std::mutex> lock(mutexForGc);
// If I have to wait then while I am waiting I am not active...
    my_assert(activeHelpers != 0);
    activeHelpers--;
#ifndef NO_THREADS
    bool st =
        cvForChunkStack.wait_until(lock,
            std::chrono::steady_clock::now() + cvTimeout,
            []{   return pendingChunks != nullptr ||
                         activeHelpers == 0;
              });
    if (!st) my_abort(LOCATION ": condition variable timed out");
#endif // NO_THREADS
    Chunk *r = pendingChunks;
    if (r != nullptr)
    {   pendingChunks = r->pendingChunks;
// If I manage to grab a chunk to work on I will then become active again.
        activeHelpers++;
    }
// I can only return a nullptr here is activeHelpers is zero.
    return r;
}

Chunk *nonblockingPopChunk()
{   std::lock_guard<std::mutex> lock(mutexForGc);
// This will grab a Chunk if one is available, but return nullptr if not.
// If other threads are active one of them might be just abou to push another
// Chunk, so getting a nullptr here is no a definitive indication that
// ther is and will never be work to be done.
    Chunk *r = pendingChunks;
    if (r != nullptr) pendingChunks = r->pendingChunks;
    return r;
}

// The short path through the code here is as for the main system, but
// beyond allocation within a Chunk it takes a different path - which makes
// sense because here I am already within the GC and so I never need to
// bring all threads into struct synchronization to start one.
//
// I am still concerned about overheads in concurrency support, so the
// plan at present is to maintain a pool of new standard sized
// chunks in a little queue. Checking whether the queue is empty and
// grabbing a chunk from it if not can be done using simple atomic operations
// if the queue is implemented as a ring-buffer. If a thread either finds
// that the queue is empty or that it is trying to grab space larger than
// (say) 2/3 of the standard chunk size (and especially if it is allocating
// something that would not fit at all in a standard Chunk) it enters a
// critical region. That can do whatever global activity is required to
// arrange space for some more Chunks including an oversized one. It will
// (in a lock-free manner) top the queue up until it is full - (say) 16
// Chunks. At this level the stack has reserved around 256K of memory.
// If there have not been overlarge grabs that mess things up it will be
// possible to unwind some of those allocations in the single thread code at
// the end of GC, so there is no necessary loss. But at 1/4 Mbyte even if I
// were to leave it wasted it is not a disaster!
// The pointers used with the circular buffer are counting Chunks (which are
// around 16Kbytes) so if on a 32-bit machine I used 32-bit uintptr_t values
// those would overflow when 2^32 chunks has been used and given that each
// GC can at worst be allocating from a half-space that would not happen until
// over 30000 garbage collections had happened. That is not perfect headroom
// but I will accept it - and on 64-bit machines there is no problem after
// and imaginable amount of time.

const size_t gcQSize = 16;
atomic<uintptr_t> gcInQ(0);
atomic<uintptr_t> gcOutQ(0);
atomic<Chunk *>   gcQ[gcQSize];

// This is a single producer multiple consumer queue, so the insert operation
// needs to update data using sequentially consistent atomic operations so
// that consumers notice, and so that data is in the queue ahead of the
// pointer being incremented to indicate that. But it does not have to worry
// about interlocks against other producers.

static void gcEnqueue(Chunk *c)
{   uintptr_t in = gcInQ;
//  if (gcTrace) cout << "Grab another Chunk at " << Addr(c) << "\n";
    gcQ[in & (gcQSize-1)] = c;
    in = in+1;
    if (in == 0) Lstop(nil); // wrap in queue pointer
    gcInQ = in;
}

static Chunk *grabAnotherChunk(size_t size)
{
// This function is called within a critical region and so it does not
// need to worry about synchronization issues!
    for (;;)
    {
// (1) Use gFringe to gLimit is possible
        uintptr_t r = gFringe;
        uintptr_t l = r + size;
        if (l <= gLimit)
        {   gFringe = l;
            return reinterpret_cast<Chunk *>(r);
        }
// (2) Skip pinned items if necessary
        uintptr_t pageEnd = ((r-1) & -pageSize) + pageSize;
        if (gLimit != pageEnd)
        {   Chunk *c = reinterpret_cast<Chunk *>(gLimit);
            gFringe = gLimit + c->length; // past the pinned Chunk
            gLimit = reinterpret_cast<uintptr_t>(
                         static_cast<Chunk *>(c->chunkPinChain));
            if (gLimit == 0) gLimit = pageEnd;
            continue;
        }
// (3) Allocate a totally new page if the above two strategies fail.
//     This resets gFringe and gLimit. In a REALLY nasty case I might
//     be trying to allocate a huge Chunk that is to store a huge vector,
//     and the Page that I grab could be fragmented with loads of pinned
//     data, so even this does not guarantee success! If circumstances like
//     that lead to ultimate failure it is fatal.
        grabNewCurrentPage(withinMajorGarbageCollection);
    }
}

static std::mutex grabNewSegments;

static Chunk *gcReserveMoreChunks(uintptr_t out)
{   std::lock_guard<std::mutex> lock(grabNewSegments);
// When I get here there can still be other threads running and incrementing
// gcOutQ. My task is to insert chunks into the queue until it holds (about)
// gcQSize.
    cout << "Reserve several chunks for GC use\n";
    while (gcInQ < static_cast<uintptr_t>(gcOutQ) + gcQSize - 1)
    {   gcEnqueue(grabAnotherChunk(targetChunkSize));
    }
    return gcQ[out & (gcQSize-1)];
}

static Chunk *gcDequeue()
{   uintptr_t out = gcOutQ.fetch_add(1);
    if (out < gcInQ) LIKELY return gcQ[out & (gcQSize-1)];
    UNLIKELY
    return gcReserveMoreChunks(out);
}

thread_local Chunk *myBusyChunk = nullptr;

extern void testLayout();

LispObject gc_n_bytes1(size_t n, THREADFORMAL uintptr_t r)
{   Chunk *newChunk;
    size_t nSize;
    my_assert(n < pageSize/2, "ridiculous size in gc_n_bytes");
    if (n <= (2*targetChunkSize)/3) LIKELY
    {   newChunk = gcDequeue();
        nSize = targetChunkSize;   // All Chunks on queue are standard size.
    }
    else
    UNLIKELY
    {   std::lock_guard<std::mutex> lock(grabNewSegments);
        newChunk = grabAnotherChunk(nSize = (targetChunkSize+n));
        while (gcInQ < static_cast<uintptr_t>(gcOutQ) + gcQSize - 1)
        {   gcEnqueue(grabAnotherChunk(targetChunkSize));
        }
    }
// nSize is now the size of the next chunk.
    uintptr_t oldFringe = r;
//  uintptr_t oldLimit = gLimit;
    uint64_t newLimit = reinterpret_cast<uintptr_t>(newChunk) + nSize;
    r = newChunk->dataStart();
    fringeBis = fringe = r + n;
    Page *p = reinterpret_cast<Page *>((oldFringe-1) & -pageSize);
    Chunk *justFilled = myChunkBase;
    if (justFilled != nullptr &&
        justFilled != myBusyChunk) pushChunk(justFilled);
    myChunkBase = newChunk;
    if (gcTrace) cout << "New Chunk at " << Addr(newChunk)
                      << " fringe = " << Addr(fringe) << "\n";
    newChunk->length = nSize;
    newChunk->isPinned = 0;
    newChunk->pinnedObjects = TAG_FIXNUM;
    newChunk->chunkPinChain = nullptr;
    size_t chunkNo = p->chunkCount.fetch_add(1);
    std::cout << "Page " << p << " gets chunkCount "
              << static_cast<unsigned int>(p->chunkCount) << "\n";
    p->chunkMap[chunkNo] = newChunk;
    limitBis = newLimit;
    limit = newLimit;
#ifdef DEBUG
    testLayout();
#endif
    if (gcTrace) cout << "gc_n_bytes1 = " << Addr(r) << " fringe = " << Addr(fringe) << "\n";
    if (gcTrace) cout << "limit = " << Addr(limit) << "\n";
    return static_cast<LispObject>(r);
}

inline LispObject gc_n_bytes(size_t n)
{
// First the path that applies if the allocation will be possible within the
// current Chunk.
    THREADID;
    if (gcTrace) cout << "gc_n_bytes " << n
                      << " with fringe = " << Addr(fringe) << "\n";
    uintptr_t r = fringe;
    uintptr_t fr1 = r + n;
    uintptr_t w = limit;
    if (fr1 <= w) LIKELY
    {   fringe = fr1;
        if (gcTrace) cout << "simple success at " << Addr(r)
                          << " leaves fringe = " << Addr(fringe) << "\n";
#ifdef DEBUG
        for (size_t i=0; i<n; i+=4)
            *reinterpret_cast<uint32_t *>(r+i) = 0xacebead5;
#endif // DEBUG
        return static_cast<LispObject>(r);
    }
// Now the case where a fresh Chunk has to be allocated.
    UNLIKELY
    Chunk *c = myChunkBase;
// If I am going to have to allocate a new Chunk and if there is actually
// one in use at present then I need to record where the existing Chunk ends
// and insert a padder to fill up to its end.
    if (c != nullptr)
    {   c->chunkFringe = r;
        size_t gap = w - r;
        if (gap != 0) setHeaderWord(r, gap);
    }
    LispObject r1 = gc_n_bytes1(n, THREADARG r);
    if (gcTrace) cout << "complex success at " << Addr(r1) << "\n";
#ifdef DEBUG
    for (size_t i=0; i<n; i+=4)
        *reinterpret_cast<uint32_t *>(r1+i) = 0x9decade9;
#endif // DEBUG
    return r1;
}

// Note that I define this guard once here and then also in newallocate.cpp.
// By undefining it here I can activate the thread-safe code but still only
// use one thread, and that will be a good thing to do to observe the overhead
// that synchronization imposes. If that is not too bad and once the thread-
// safe version is stable I can adjust newallocate.cpp and that would gate
// more threads in to participare in GC - however until I put in extra
// work somewhere to create those extra threads there are not any available
// to help!

#define NO_EXTRA_GC_THREADS 1

#ifdef NO_EXTRA_GC_THREADS

// The version here is for single-threaded use only, however my intent is
// to gradually start adding in the framework for a parallel version. As I
// do so I am going to make an assumption that I hope will be valid in all
// the cases that I come across, but which is clearly improper as far as C++
// is concerned. That is that when I access an atomic<T> the memory layout
// involved and the data representation in that memory will be exactly
// as for something of type just plain T. I expect that the only difference
// will be that in the atomic case the compiler takes any extra trouble it
// needs to to ensure that updates happen either completely or not at all,
// and that multi-processor issues are addressed in the sense of memory
// fences etc. This assumption is going to violate strict aliasing rules and
// so a sufficiently clever compiler could spot what I was doing and mangle
// my code quite grievously!
 
bool isPinned(uintptr_t a);

void evacuate(atomic<LispObject> &a)
{
#ifdef DEBUG
// I am silent on NIL because otherwise I am overall too noisy.
    if (a!=nil && !is_immediate(a))
        if (gcTrace) cout << "evacuating " << Addr(a) << "\n";
#endif
// Here p is a pointer to a location that is a list-base, ie it contains
// a valid Lisp object. I want to arrange that the object and all its
// components are moved to the new half space, and (if necessary) the
// list base is updated to refer to the copy and a forwarding pointer is left
// where the original had been. The procedure is:
//   Let a = *p, ie the object that may need to be copied.
//   If a is tagged as immediate data do nothing.
//   [now a is some sort of tagged pointer]
//   If *a is a forwarding pointer replace the list base with the
//      object referred to, reconstructing suitable tag bits.
//   If the address that a refers to is in the free half-space it must be
//      a pointer to an object that had been pinned last time, so do nothing.
//   Determine the length, b, of the object that a refers to.
//   Allocate b byte in the new space and do a simple binary copy of all
//      of object a to there.
//   Write in a forwarding pointer.
//   Update the list-base to refer to the copy.
// Note that this is a shallow copy operation. A later stage must perform
// a linear scan of the newly copied material. That stage is not discussed
// here because this function does not directly cause it to happen.
//
    my_assert(a != 0, "zero word in scanning");
    my_assert(!is_forward(a), "forwarding ptr in scanning");
    if (is_immediate(a) || a == nil)
    {
//#ifdef DEBUG
//        if (a != nil)
//            if (gcTrace) cout << "immediate data: easy " << Addr(a) << "\n";
//#endif // DEBUG
        return;
    }
    if (isPinned(a))
    {   if (gcTrace)
        {   cout << "precise ptr to pinned " << Addr(a) << "\n";
            cout << "pinned item is ";
            simple_print(a);
            cout << "@" << std::hex
                 << static_cast<LispObject>(a) << " in page "
                 << (a & -pageSize) << "\n"; 
        }
        return;
    }
    LispObject *ap = reinterpret_cast<LispObject *>(a & ~TAG_BITS);
    LispObject aa = *ap;
    if (gcTrace) cout << "item is " << Addr(a) << " [not immediate] "
         << " contents of that is " << Addr(aa) << "\n";
    if (is_forward(aa))
    {   a = aa - TAG_FORWARD + (a & TAG_BITS);
#ifdef DEBUG
        if (gcTrace) cout << "Process forwarding address\n";
#endif // DEBUG
        return;
    }
// Now I will need to make a copy of the item.
    size_t len;
// Finding its length is not too hard here because I have a validly tagged
// pointer to it.
    if (is_cons(a)) len = 2*CELL;
    else if (is_symbol(a)) len = symhdr_length;
    else len = length_of_header(aa);
#ifdef DEBUG
    if (gcTrace) cout << "about to allocate " << len << " bytes\n";
#endif // DEBUG
    aa = gc_n_bytes(len);
#ifdef DEBUG
    if (gcTrace) cout << "@ " << Addr(aa) << "\n";
#endif // DEBUG
// I will copy the full final doubleword of a vector, and in the case of
// a 32-bit machine or for vectors that contain components that are smaller
// than CELL this will include material beyond that which is meaningful.
// This at least keeps any zero-padding of the last word intact.
    std::memcpy(reinterpret_cast<void *>(aa), ap, doubleword_align_up(len));
    *ap = TAG_FORWARD + aa;
    a = aa + (a & TAG_BITS);
}

#else // NO_EXTRA_GC_THREADS

// Here is where I will work on a version that is thread-safe! Just for now
// it is a direct copy of the unsafe code...

void evacuate(atomic<LispObject> *p)
{
#error This need to be made thread-safe!

// Here p is a pointer to a location that is a list-base, ie it contains
// a valid Lisp object. I want to arrange that the object and all its
// components are moved to the new half space, and (if necessary) the
// list base is updated to refer to the copy and a forwarding pointer is left
// where the original had been. The procedure is:
//   Let a = *p, ie the object that may need to be copied.
//   If a is tagged as immediate data do nothing.
//   [now a is some sort of tagged pointer]
//   If *a is a forwarding pointer replace the list base with the
//      object referred to, reconstructing suitable tag bits.
//   If the address that a refers to is in the free half-space it must be
//      a pointer to an object that had been pinned last time, so do nothing.
//   Determine the length, b, of the object that a refers to.
//   Allocate b byte in the new space and do a simple binary copy of all
//      of object a to there.
//   Write in a forwarding pointer.
//   Update the list-base to refer to the copy.
// Note that this is a shallow copy operation. A later stage must perform
// a linear scan of the newly copied material. That stage is not discussed
// here because this function does not directly cause it to happen.
//
    LispObject a = *p;
    if (is_odds(a) || is_immediate_num(a) || a == nil) return;
    LispObject *ap = reinterpret_cast<LispObject *>(a & ~TAG_BITS);
    LispObject aa = *ap;
    if (is_forward(aa))
    {   *p = aa - TAG_FORWARD + (a&TAG_BITS);
        return;
    }
// Now I will need to make a copy of the item.
    size_t len;
// Finding its length is not too hard here because I have a validly tagged
// pointer to it.
    if (is_cons(a)) len = 2*CELL;
    else if (is_symbol(a)) len = symhdr_length;
    else len = doubleword_align_up(length_of_header(aa));
    aa = gc_n_bytes(len);
    std::memcpy(reinterpret_cast<void *>(aa), ap, len);
    *ap = TAG_FORWARD + aa;
    *p = aa + (a&TAG_BITS);
}



#endif // NO_EXTRA_GC_THREADS

void evacuate(LispObject &p)
{   atomic<LispObject> ap(p);
    evacuate(ap);
    p = ap;
}

bool withinMajorGarbageCollection = false;
size_t pinnedChunkCount = 0, pinnedPageCount = 0;

void prepareForGarbageCollection(bool major)
{   if (gcTrace) cout << "prepareForGarbageCollection" << endl;
    if (major)
    {   withinMajorGarbageCollection = true;
        oldPages = busyPages;
        oldPagesCount = busyPagesCount;
        busyPages = nullptr;
        busyPagesCount = 0;
// Having moved all the busy pages to oldPages I can set up a fresh
// current page to be the start of the "new half-space" that I will
// copy things into.
        grabNewCurrentPage(true);
        pinnedChunkCount = pinnedPageCount = 0;
// I will want pendingChunks empty basically all the time because that
// can be the main guard blocking GC threads from trying to run when I do
// not want them to!
        pendingChunks = nullptr;
// The next bit is really rather a cheat. It "allocates zero bytes" but
// but diving into the allocation code beyond the initial test for easy cases
// it will allocate a fresh Chunk. I set myBusyChunk so that the allocation
// of the new Chunk does not mark the existing one as needing scanning.
        THREADID;
        myBusyChunk = myChunkBase;
        if (myBusyChunk != nullptr)
            myBusyChunk->chunkFringe = static_cast<uintptr_t>(fringe);
        myChunkBase = myBusyChunk = nullptr;
        fringe = limit;
        gcInQ = gcOutQ = 0;
        gc_n_bytes1(0, THREADARG fringe);
    }
    else
    {   withinMajorGarbageCollection = false;
        if (gcTrace) cout << "prepare for minor GC not coded yet\n";
        Lstop(nil);
    }
}

void clearPinnedInformation(bool major)
{   if (gcTrace) cout << "clearPinnedInformation" << endl;
// Any pages pinned by the previous garbage collection will be recorded
// via pagesPinChain.
   clearAllPins();
}

// The version of IsPinned here requires its argument to be a valid
// LispObject that is not immediate data. Or at least the word address
// of a valid object. It it was a value that amounted to an illegal
// memory address there would be trouble.

bool isPinned(uintptr_t a)
{   Page *p = reinterpret_cast<Page *>(a & -pageSize);
    uintptr_t o = (a & (pageSize-1))/8;
    uintptr_t mask = static_cast<uintptr_t>(1)<<(o&(8*sizeof(uintptr_t)-1));
    uintptr_t word = p->pinnedMap[o/(8*sizeof(uintptr_t))];
    return (word & mask) != 0;
}

void setPinned(uintptr_t a)
{   Page *p = reinterpret_cast<Page *>(a & -pageSize);
    uintptr_t o = (a & (pageSize-1))/8;
    uintptr_t mask = static_cast<uintptr_t>(1)<<(o&(8*sizeof(uintptr_t)-1));
    p->pinnedMap[o/(8*sizeof(uintptr_t))] |= mask;
    cout << "setPinned " << std::hex << a << "\n";
}

void setPinned(Page *p, uintptr_t a)
{   uintptr_t o = (a & (pageSize-1))/8;
    uintptr_t mask = static_cast<uintptr_t>(1)<<(o&(8*sizeof(uintptr_t)-1));
    p->pinnedMap[o/(8*sizeof(uintptr_t))] |= mask;
    cout << "setPinned " << std::hex << a << "\n";
}

void clearPinned(uintptr_t a)
{   Page *p = reinterpret_cast<Page *>(a & -pageSize);
    uintptr_t o = (a & (pageSize-1))/8;
    uintptr_t mask = static_cast<uintptr_t>(1)<<(o&(8*sizeof(uintptr_t)-1));
    p->pinnedMap[o/(8*sizeof(uintptr_t))] &= ~mask;
}

void clearPinned(Page *p, uintptr_t a)
{   uintptr_t o = (a & (pageSize-1))/8;
    uintptr_t mask = static_cast<uintptr_t>(1)<<(o&(8*sizeof(uintptr_t)-1));
    p->pinnedMap[o/(8*sizeof(uintptr_t))] &= ~mask;
}

// Each page consists of a header followed by a number of chunks. There may
// be unused space in the page after the last chunk. For the purposes of
// pinning I want to identify the chunk (if any) that (a) points into, and
// arrange that it is on a per-page list of pinned chunks and that if there
// are any such chunks that the page itself is on a list of pages that contain
// pinned material.
// I must ignore any value that points other than within a genuine valid live
// object that was either pinned by the previous GC or allocated during or
// since it. So I start by identifying which Chunk (if any) an address lies
// within. Chunks can have a flag pinnedObjects that records their status at
// the end of the previous GC. If that is NOT set then all addresses within
// the chunk from its (data) start to its fringe are valid. If pinnedObjects is
// set I need to check in great detail whether the address is within one
// of the objects in the chunk that had let to it being pinned. Well
// pinnedObjects is not a boolean, it is a list (albeit with its pointers tagged
// as TAG_FIXNUM!) of such items. The pointers are represented as fixnums
// because the list is ephemeral and I do not want this GC to view it as
// data to be traced through and preserved.

void processAmbiguousInPage(bool major, Page *p, uintptr_t a)
// If the page is pending or empty that any apparent pointer into it is
// not of interest. Note that at the very start of a run much of the
// memory will only have chunkCount and chain fields filled in, and that is
// why it is important to do this check using only those.
{   if (p->chunkCount == 0) return;  // An empty Page.
    if (gcTrace || true)
        cout << "Ambig " << Addr(a) << " in non-empty page "
             << Addr(p) << endl;
// The list of chunks will be arranged such that the highest address one
// is first in the list. I will now scan it until I find one such that
// the chunk has (a) pointing within it, and I should not need many tries
// at all. The sorting order MUST be consistent with the order I assume in
// my binary search code lower down, and so I use std::qsort which lets
// me specify my own ordering predicate without needing to wait for c++2x,
// at which stage std::sort gets such a generality.
    if (!p->chunkMapSorted)
    {   std::qsort(p->chunkMap, p->chunkCount, sizeof(p->chunkMap[0]),
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
        p->chunkMapSorted = true;
    }
// chunkMap is now a table of pointers to chunks sorted into ascending order.
// I will use binary search to find out which (if any) of those chunks
// contains the address a.
    size_t low = 0, high = p->chunkCount-1;
    while (low < high)
    {   size_t middle = (low + high + 1)/2;
        if (a < reinterpret_cast<uintptr_t>(
                    static_cast<Chunk *>(p->chunkMap[middle])))
            high = middle-1;
        else low = middle;
    }
// Ha ha - another issue that I do not think is a problem but that deserves
// a comment. At the start of GC I will have tidied up all existing Pages and
// the Chunks within them. But as I scan ambiguous pointers here I can
// set up "fake cons" lists that point to where pinned items are. Doing so
// involves allocating a new Chunk or Chunks to store those lists in, and
// those go in a new Page. A slighly later ambiguous pointer could refer
// to Part of this new data. the Page's chunkMap gets sorted once when the
// first ambiguous pointer hits the Page and in that case the Chunk can
// be identified, and because this is an active chunk (not one pinned from
// last time) a bit gets set in the associated bitmap. Subsequent pinned items
// can extend the "fake list" and spill over into another Chunk - and that
// can leave the chunkMap for the page not properly sorted. So ambiguous
// pointers in that region may or may not identify a Chunk to taint. If they
// do not then that does not matter because then no pin will be recorded and
// the data here really does not want to count as pinned! But the pad thing
// here is that Chunks in the new page can end up on the list of ones
// containing pinned data amd they may then be subject to a linear scan so
// that the pinning can be put on object heads. That is dangerous because the
// Chunk may not be tidy at the end. And the same sort of issue may mean that
// the pinning can be confused by an ambiguous address towards the end of
// the Chunk well beyond the bits that have been filled in. Oh dear!
// So I must be able to identify such Pages and not pin within them, or
// to be more precise only pin things in them that had been pinned during
// a previous GC. To cope there I will need to be able to identify Chunks that
// already existed even when new ones are allocated around them.
// OK so how can I fix this? Well the most painful case I can see is if the
// GC starts to build new data in a mostlyFree Page. Or in a succession of
// same.
//  

    Chunk *c = p->chunkMap[low];
    if (gcTrace) cout << "pointer is maybe within chunk " << low << " at " << Addr(c) << endl;
// This may be a chunk where a previous GC had left some items pinned within
// it, and in that case the pointer here is only interesting if if points
// within one of those, since the remainder of the Chunk is not in use.
    if (c->pinnedObjects != TAG_FIXNUM)
    {   bool valid = false;
        for (LispObject ch=c->pinnedObjects;
                        ch!=TAG_FIXNUM;
                        ch=cdr(ch&~TAG_BITS))
        {   if ((a&~TAG_BITS) == (car(ch&~TAG_BITS) & ~TAG_BITS))
            // needs to be "a points within" not "==" if I want ambiguous
            // pointers to addresses within objects (rather than just to
            // their start) to keep them alive.
            {   valid = true;
                break;
            }
        }
        if (!valid) return;
    }
    else if (!c->pointsWithin(a)) return;
    if (gcTrace) cout << "Within that chunk: isPinned = "
                      << static_cast<bool>(c->isPinned) << endl;
    setPinned(p, a);
// Here (a) lies within the range of the chunk c. Every page that has any
// pinning must record that both by being on a chain of pages with pins
// and by having a list of its own pinned chunks.
// If the chunk is already tagged as pinned there is no need to do so again.
    if (c->isPinned != 0) return;
    c->isPinned++;
    pinnedChunkCount++;
// Note that a single thread looks at ambiguous pointers so while I want
// everything atomic<> so that later on if other threads happen to look you
// you know they will see updates, I do not need to worry about race
// conditions while I form the chain of pinned chunks and pages.
    c->chunkPinChain = static_cast<Chunk *>(p->chunkPinChain);
    p->chunkPinChain = c;
// When a chunk gets pinned then page must be too unless it already has been.
    if (gcTrace) cout << "Page hasPinned = "
                      << static_cast<bool>(p->hasPinned) << endl;
    if (p->hasPinned) return;
    pinnedPageCount++;
    p->hasPinned = true;
    p->pagePinChain = pagesPinChain;
    pagesPinChain = p;
}

void clearAllPins()
{   for (Page *p = pagesPinChain; p!=nullptr; p=p->pagePinChain)
    {   p->hasPinned = false;
        for (Chunk *c = p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
            c->isPinned = 0;
        p->chunkPinChain = nullptr;
        std::memset(p->pinnedMap, 0, sizeof(p->pinnedMap));
    }
    pagesPinChain = nullptr;
}

// Here I have an item that may be arbitrary binary material but which COULD
// be a LispObject that will later be re-used. If it is a LispObject that
// refers to memory address (a) then I will want to be certain that garbage
// collection does not relocate material at (a). For a minor collection only
// objects in the previous page will be evacuated, so I have a simple initial
// filter. For a full GC I will need to determine whether (a) points anywhere
// within memory that is currently in use holding active Lisp data. This
// could be within the page currently bein allocated into, its predecessor
// page, all the pages that ephemeral collection would view as stable plus
// those sections of otherwise empty pages that might have live data that
// had been pinned during a previous GC. But not pages that had ended up
// totally empty.

void processAmbiguousValue(bool major, uintptr_t a)
{   if (!major)
    {   uintptr_t previousBase =
            reinterpret_cast<uintptr_t>(previousPage);
        if (previousBase <= a && a < previousBase+pageSize)
            processAmbiguousInPage(false, previousPage, a);
        return;
    }
    Page *p = findPage(a);
    if (p!=nullptr) processAmbiguousInPage(true, p, a);
}

// The following function scans the stack for each thread. The address
// sanitizer gets upset at this when it looks at return addresses and
// the like, so I need to disable it here... After all looking at locations
// on the stack but between the proper stack frames is indeed a bit
// "dodgy"!

NO_SANITIZE_ADDRESS
void identifyPinnedItems(bool major)
{
// For each ambiguous value (ie value on the stack associated with
// any thread) do processAmbiguousValue(). This must ensure that if
// the item might be a LispObject that is a reference that the destination
// address of that reference is marked as "pinned". During a minor GC
// the only items that need special marking will be one in the "previous"
// page since nothing else will ever be moved.
    for (uintptr_t threadId=0; threadId<maxThreads; threadId++)
    {
#ifndef NO_THREADS
// If I am not using threads I should always scan the stack!
        if ((threadMap & threadBit(threadId)) == 0)
#endif // NO_THREADS
        {   uintptr_t sbase = C_stackBase;
            uintptr_t sfringe = C_stackFringe;
// Here I am supposing that for each thread the (C++) stack is a single
// block of memory, that it is aligned as a sizeof(LispObject) boundary
// and that EVERY interesting value is present on the stack with no chance
// that the only live pointer to some data is in a machine register. On the
// way in to the Garbage Collector I have tried quite hard to ensure that
// last point, but none of this can be guaranteed by reference to the rules
// of the C++ standard!
            if (gcTrace) cout << "scan stack from " << Addr(sfringe) << " to "
                 << Addr(sbase) << endl;
            for (uintptr_t s=sfringe; s<sbase; s+=sizeof(uintptr_t))
            {   processAmbiguousValue(major,
                                      *reinterpret_cast<uintptr_t *>(s));
            }
        }
    }
}

// This not only ensures that the bitmap identifies the head of every
// pinned item, but it also arranges that no addresses with objects are
// marked. This is relied upon by evacuatePinnedInChunk.
//
// There can be two sorts of Chunks here. On is a Chunk that contained
// pinned items during the previous GC, and has a non-empty pinnedObjects
// chain. If it had pinned items during the previous GC then those pinned
// objects were the only valid ones within it. The rest of the space may
// contain objects that were either dead at the start of the previous GC
// or that got evacuated and so have a forwarding address in their first
// word. If the Chunk has continued to be pinned over several GCs then
// all pointers in old data in it (including the forwarding addresses)
// can refer to locations that are no longer valid. So the ONLY data
// that is valid there is the stuff that was pinned last time. Some
// of that may remain pinned and the bitmap entry for object heads must
// reflect that. Some may now now be pinned and will be evacuated (or not)
// later. The Chunk can not be subject to any linear scan based on its
// contents, but it will have a pinnedObjects list that identified the objects
// pinned last time. This must be replaced with a freshly allocated
// new list documenting what both used to be and still is pinned.
// Other Chunks may be ones that have more recent data in. These two
// situations are mutually exclusive. A non-pinned Chunk should be
// such that it can be scanned linearly so that object heads can be
// identified and a again pinned items within it must end up on a
// freshly created pinnedObjects list.

void findHeadersOfPinnedItems()
{   for (Page *p=pagesPinChain; p!=nullptr; p=p->pagePinChain)
    {   for (Chunk *c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
        {   uintptr_t p = c->dataStart();
            if (gcTrace) cout << "Hunting through pinned chunk: data "
                << Addr(c->dataStart())
                << " to " << Addr(c->chunkFringe)
                << " end " << Addr(c->dataEnd()) << "\n";
            if (c->pinnedObjects != TAG_FIXNUM)
            {   // here I believe that the headers have already been found.
            }
            else while (p < c->chunkFringe)
            {   LispObject *pp = reinterpret_cast<LispObject *>(p);
// In the loop here p will point in turn at each item in the Chunk. I know
// that some items in the Chunk are pinned, but the pinning bitmap may
// (until here) not tag the header word. So when I have an item of size > 8
// I need to check isPinned() on all subsequent words and if one is
// marked I need to setPinned() on the header. A crude version can just do
// a linear scan word by word while a cleverer one would use the bitmap
// to go much faster. I will use the crude strategy first for simplicity!
                LispObject a = *pp;
                size_t len;
                switch (a & 0x1f) // tag bits plus 2 more
                {
// Here is is immaterial whether a vector holds binary or lisp data, any
// ambiguous pointer within it counts.
                case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                         // Note TYPE_STREAM etc is in with this.
                case 0x12: // 0b10010:   // Header for bit-vector
                case 0x1a: // 0b11010:   // Header for vector holding binary data
// I demand that length_of_header() gives a proper length for byte- and
// bit-vectors at least as far as the number of words that are used.
                    len = doubleword_align_up(length_of_header(a));
                    cout << "Vector of length " << len << " to scan\n";
// On a 64-bit machine this is one probe per LispObject. On a 32-bit one
// because my pinning bitmap has a resolution of 8 bytes I will handle
// two LispObjects at a time.
// Here is where I could probably improve things by consulting multiple
// bits in the bitmap at once... The loop here will ensure that if any
// (double-)word in the vector is pinned that the pin marker is put on the
// header word and not on any one within the vector.
                    for (size_t i=8; i<len; i+=8)
                    {   if (isPinned(p+i))
                        {   setPinned(p);
                            clearPinned(p+i);
                            break;
                        }
                    }
                    if (isPinned(p))
                    {   cout << "Pinned vector at " << Addr(p) << "\n";
                        LispObject ch = gc_n_bytes(2*CELL);
// I am going to make a chain of all pinned items. But I do not want
// ambiguous pointers to the chain to cause it ot its contents to
// get pinned in any significant way and the list is only needed until
// the start phases of the next GC. I tag the references in it as fixnums
// which lets me work with them and keeps all but the low 3 bits intact,
// but which - as immediate data - will not complicate pinning in the
// next GC.
                        car(ch) = p + TAG_FIXNUM;
                        cdr(ch) = static_cast<LispObject>(c->pinnedObjects);
                        c->pinnedObjects = ch + TAG_FIXNUM;
                    }
                    my_assert(len != 0, "zero length vector of some sort");
                    p += len;
                    continue;

                case 0x02: // 0b00010:   // Symbol headers plus char literals etc
                    if (is_symbol_header(a))
                    {   for (size_t i=8; i<symhdr_length; i+=8)
                        {   if (isPinned(p+i))
                            {   setPinned(p);
                                clearPinned(p+i);
                                break;
                            }
                        }
                        if (isPinned(p))
                        {   cout << "Pinned symbol at " << Addr(p) << "\n";
                            LispObject ch = gc_n_bytes(2*CELL);
                            car(ch) = p + TAG_FIXNUM;
                            cdr(ch) = static_cast<LispObject>(c->pinnedObjects);
                            c->pinnedObjects = ch + TAG_FIXNUM;
                        }
                        p += symhdr_length;
                        continue;
                    }
                    // drop through.
                default:                 // None of the above cases...
                                         // ... must be a CONS cell.
// Only need an extra probe on 64-bit platforms.
                    if (SIXTY_FOUR_BIT && isPinned(p+CELL))
                    {   setPinned(p);
                        clearPinned(p+CELL);
                    }
                    if (isPinned(p))
                    {   cout << "Pinned cons cell at " << Addr(p) << "\n";
                        LispObject ch = gc_n_bytes(2*CELL);
                        car(ch) = p + TAG_FIXNUM;
                        cdr(ch) = static_cast<LispObject>(c->pinnedObjects);
                        c->pinnedObjects = ch + TAG_FIXNUM;
                    }
                    p += 2*CELL;
                    continue;
                }
            }
        }
    }
}

void evacuateFromUnambiguousBases(bool major)
{   if (gcTrace) cout << "evacuateFromUnambiguousBases\n";
// This code has to know where ALL the definitive references to LispObjects
// are in the C++ code. The main way it achieves this is through a vector
// "list_bases" that holds the address of every static location involved.
// That vector is about 200 items long. In addition the dedicated Lisp
// stack has to be processed.
    my_assert(qvalue(nil) == nil);
    evacuate(qvalue(nil));
    my_assert(qvalue(nil) == nil);
    evacuate(qenv(nil));
    my_assert(qvalue(nil) == nil);
    evacuate(qplist(nil));
    my_assert(qvalue(nil) == nil);
    evacuate(qpname(nil));
    my_assert(qvalue(nil) == nil);
    evacuate(qfastgets(nil));
    my_assert(qvalue(nil) == nil);
    evacuate(qpackage(nil));
    my_assert(qvalue(nil) == nil);
    for (auto p = list_bases; *p!=nullptr; p++) evacuate(**p);
    my_assert(qvalue(nil) == nil);
    THREADID;
    for (LispObject *sp=stack;
         sp>reinterpret_cast<LispObject *>(stackBase); sp--) evacuate(*sp);
    my_assert(qvalue(nil) == nil);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != nullptr)
    {   for (size_t i=1; i<=repeat_count; i++)
            evacuate(repeat_heap[i]);
        my_assert(qvalue(nil) == nil);
    }
}

// Evacuate every pinned item in the Chunk

void evacuatePinnedInChunk(Chunk *c)
{   uintptr_t p = c->dataStart();
    if (gcTrace) cout << "Pinned chunk has data " << Addr(c->dataStart())
         << " to " << Addr(c->chunkFringe)
         << " end " << Addr(c->dataEnd()) << "\n";
    while (p < c->chunkFringe)
    {
// I could skip up to 512 bytes at a time by using word operations on the
// bitmap, and if I did then the fact that there are only 32 (64-bit) words
// in the bitmap makes this whole scan feel not too bad.
        if (!isPinned(p))
        {   p += 8;
            continue;
        }
// Here p is the (word address of) the start of a valid pinned object. By
// inspecting its first word I can deduce its type - that word could be
// a header of some sort of vector or if a symbol.
        LispObject *pp = reinterpret_cast<LispObject *>(p);
        if (gcTrace) cout << "Scanning pinned item at " << Addr(p) << "\n";
        LispObject a = *pp;
        if (gcTrace) cout << "Item at " << Addr(pp) << " = " << std::hex << a
                          << std::dec << " = " << Addr(a) << "\n";
        my_assert(a != 0, "zero item in heap");
        my_assert(!is_forward(a), "forwarding pointer found");
        size_t len, len1;
        switch (a & 0x1f) // tag bits plus 2 more
        {
// binary literals are C++14, so just for now I will use hex, but I will
// write what the binary literal would be...
        case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                 // Note TYPE_STREAM etc is in with this.
            len = doubleword_align_up(length_of_header(a));
            if (is_mixed_header(a))
            {   if (gcTrace) cout << "Mixed/Stream header\n";
                len1 = 4*CELL;
            }
            else len1 = len;
            if (gcTrace) cout << "vector (" << std::hex << a << std::dec << ") uses " << len << " bytes\n";
            if (len == 0) if (gcTrace) cout << "At " << Addr(pp) << " up to " << Addr(c->chunkFringe) << "\n";
            if (gcTrace)
            {   cout << "Pinned lisp vector: "; 
                simple_print(p+TAG_VECTOR);
            }
            for (size_t i = CELL; i<len1; i += CELL)
                evacuate(*reinterpret_cast<atomic<LispObject>*>(p+i));
            my_assert(len != 0, "lisp vector size zero");
            p += len;
            continue;

        case 0x12: // 0b10010:   // Header for bit-vector
            len = doubleword_align_up(length_of_header(a));
            my_assert(len != 0, "bit vector size zero");
            if (gcTrace) cout << "bit-vector uses " << len << " bytes\n";
            if (gcTrace)
            {   cout << "Pinned bit vector: ";
                simple_print(p+TAG_VECTOR);
            }
            p += len;
            continue;

        case 0x1a: // 0b11010:   // Header for vector holding binary data
            len = doubleword_align_up(length_of_header(a));
            my_assert(len != 0, "binary vector size zero");
            if (gcTrace) cout << "binary-vector uses " << len << " bytes\n";
            if (gcTrace)
            {   cout << "Pinned binary vector: ";
                simple_print(p+TAG_VECTOR);
            }
            p += len;
            continue;

        case 0x02: // 0b00010:   // Symbol headers plus char literals etc
            if (is_symbol_header(a))
            {   Symbol_Head *s = reinterpret_cast<Symbol_Head *>(p);
                if (gcTrace)
                {   cout << "Pinned symbol: ";
                    simple_print(p+TAG_SYMBOL);
                }
                evacuate(s->value);
                evacuate(s->env);
                evacuate(s->plist);
                evacuate(s->fastgets);
                evacuate(s->package);
                evacuate(s->pname);
                if (gcTrace) cout << "symbol uses " << symhdr_length << " bytes\n";
                if (gcTrace) cout << "inc from " << Addr(p) << " to " << Addr(p+symhdr_length) << "\n";
                p += symhdr_length;
                continue;
            }
            // drop through.
        default:                 // None of the above cases...
                                 // ... must be a CONS cell.
            if (gcTrace)
            {   cout << "Pinned cons cell: ";
                simple_print(p+TAG_CONS);
            }
            evacuate(pp[0]);
            evacuate(pp[1]);
            if (gcTrace) cout << "cons cell uses " << (2*CELL) << " bytes\n";
            p += 2*CELL;
            continue;
        }
    }
}


void evacuateFromPinnedItems(bool major)
{   if (gcTrace) cout << "evacuateFromPinnedItems\n";
    for (Page *p=pagesPinChain; p!=nullptr; p=p->pagePinChain)
    {   for (Chunk *c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
        {   if (gcTrace) cout << "Pinned items in " << Addr(c) << " to evacuate\n";
            evacuatePinnedInChunk(c);
        }
    }
}

// This next will be relevant with a generational GC. It needs to deal with
// up-pointers that have been introduced by RPLACx style operations.

void evacuateFromDirty()
{   if (gcTrace) cout << "evacuateFromDirty\n";
    Lstop(nil);
}

// Here are the states that a Chunk can be in:
//
// (1) | header | raw data                       | waste |
// (2) | header | evacuated data | raw data      | waste |
// (3) | header | evacuated data                 | waste |
// (4) | header | raw data | free space                  |
// (5) | header | evacuated data | raw data | free space | 
// (6) | header | evacuated data | free space            |
//

//
// There can be multiple GC threads. Overall coordination is through
// an atomic uintptr_t where its value is treated with the low few bits
// being a count of the number of GC threads that are still busy and bits
// above that a count of the un-processed Chunks on the Chunk Queue
// waiting to be scanned. This value is used with a condition variable
// such that threads can wait until EITHER another Chunk is placed on
// the queue OR until the magic counter is zero.
// All threads are signalled either when a Chunk is queued or when a
// thread becomes idle and decreases the count such that it ends up zero.
//
// The early stages of GC run using just one thread and that evacuates
// from list bases. If while doing so it fills one or nor chunks those
// are queued for later processing and the count is suitably updated.
// Meanwhile all other threads are waiting for such a Chunk to scan.
//
// The general policy then is that each thread starts by trying to tidy up
// everything in the Chunk it is currently writing to. If it "catches up"
// there it will grab further Chunks from the queue for as long as it can and
// scan each of those. In general that will copy more information into its
// own space, and it may or may not cause allocation of further Chunks.
// If the queue appears to be empty (which may be a transient situation if
// other threads happen to be busy scanning blocks that are in fact mostly
// full of immediate data or material that has already been coped) the thread
// returns to work on whatever is had been its own output Chunk, and after
// that whatever has become that.


extern void gcHelper();

void evacuateFromCopiedData(bool major)
{   if (gcTrace) cout << "evacuateFromCopiedData\n";
// This is gcHelper being called from the GC driver thread.
    gcHelper();
}

void evacuateOneChunk(Chunk *c)
{   uintptr_t p = c->dataStart();
    while (p < c->chunkFringe)
    {   LispObject *pp = reinterpret_cast<LispObject *>(p);
// The first word of an object may be one of several possibilities:
//    Header for vector holding binary data;
//    Header for vector holding Lisp data;
//    Header for object with 3 lisp items then binary stuff;
//    Header for symbol;
//    anything else (item is a cons cell).
        LispObject a = *pp;
        size_t len, len1;
        switch (a & 0x1f) // tag bits plus 2 more
        {
// binary literals are C++14, so just for now I will use hex, but I will
// write what the binary literal would be...
        case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                 // Note TYPE_STREAM etc is in with this.
            len = doubleword_align_up(length_of_header(a));
            if (is_mixed_header(a)) len1 = 4*CELL;
            else len1 = len;
            for (size_t i = CELL; i<len1; i += CELL)
                evacuate(*reinterpret_cast<LispObject *>(p+i));
            p += len;
            continue;

        case 0x12: // 0b10010:   // Header for bit-vector
            len = doubleword_align_up(length_of_header(a));
            p += len;
            continue;

        case 0x1a: // 0b11010:   // Header for vector holding binary data
            len = doubleword_align_up(length_of_header(a));
            p += len;
            continue;
        case 0x02: // 0b00010:   // Symbol headers plus char literals etc
            if (is_symbol_header(a))
            {   Symbol_Head *s = reinterpret_cast<Symbol_Head *>(p);
                evacuate(s->value);
                evacuate(s->env);
                evacuate(s->plist);
                evacuate(s->fastgets);
                evacuate(s->package);
                evacuate(s->pname);
                p += symhdr_length;
                continue;
            }
            // drop through.
        default:                 // None of the above cases...
                                 // ... must be a CONS cell.
            evacuate(pp[0]);
            evacuate(pp[1]);
            p += 2*CELL;
            continue;
        }
    }
}

void evacuatePartOfMyOwnChunk()
{
// This is the core of the copying GC. It starts by identifying the Chunk
// that its thread is allocating within.
// The steps are:
// (1) The "busy Chunk" will start off in state (4) - ie it will have some
// data within it (well a degenerate case is that there is in fact no data,
// but that is not a problem) and it also has some free space at the end. I
// know the latter because it is the Chunk I am allocating into and if it
// was full I would have moved on. I guess that a further minor special case
// is if there is no such Chunk yet - in which case I just allocate one and
// it will start off empty.
// (2) The code here points myBusyChunk at that Chunk. That is needed
// so that when (and if!) allocation fills up that Chunk it will not be
// enqueued for other threads to scan. It also sets a pointer to the start
// of data within the Chunk.
// (3) Data within the Chunk is scanned. Where there are old pointers in it
// those are "evacuated". Doing this may involve creating copies of lists.
// These copies may (or may not) fill up the Chunk - when it is filled a
// new one gets allocated. If scanning leads to creation of second or
// subsequent Chunks then the full ones get enqueued. The scan can terminate
// in one of two manners. (a) the Chunk may not become full but all data in
// it has been inspected or (b) the Chunk may have become full in which
// case scanning terminates at its end.
// (4) In a non-blocking mode the code attempts to obtain a Chunk to work on.
// While that succeeds it scans/evacuates contents. It only continues from
// this step if there seems to be no data available.
// (5) If more copying had occured then return to step (3), resetting
// myActiveChunk to wherever allocation is now active. This will commonly
// happen if (4) had found more Chunks to scan, and it is easily noticed
// by checking if fringe has changed.
// (6) If scanning stopped for lack of data (local or from the queue) the
// thread must make a blocking request from the Chunk queue (well in fact
// it is run as a stack). This can either return more memory to be scanned
// and this is treated as if it had been found at step (4). Or it can
// report that no more will ever become available, in which case we are
// finished. 
    THREADID;
    for (;;)
    {
// myBusyChunk is set here so because the Chunk being worked on is
// simultaneously on that has some copied but not cleaned up material in
// it AND the one in which this thread will be placing any further
// copied material.
        myBusyChunk = myChunkBase;
        uintptr_t p = myBusyChunk->dataStart();
        if (gcTrace) cout << "Start of data in my Chunk is at "
                          << Addr(p) << "\n";
        if (gcTrace) cout << "fringe = " << Addr(fringe) << "\n";
        for (;;)
        {
// The start of this loop is what I describe as "step (3)" in the
// above commentary.
            if (p == fringe)
            {   Chunk *c1;
                for (;;)
                {   while ((c1 = nonblockingPopChunk()) != nullptr)
                    {   if (gcTrace) cout << "another chunk at " << Addr(c1) << " from queue\n";
                        evacuateOneChunk(c1);
                    }
                    if (fringe == p)
                    {   c1 = popChunk(); // blocking
                        if (c1 == nullptr) return;
                        if (gcTrace) cout << "!Another chunk at " << Addr(c1) << " from queue\n";
                        evacuateOneChunk(c1);
                        continue;
                    }
                    else break;
                }
                if (myBusyChunk != myChunkBase)
                {   myBusyChunk = myChunkBase;
                    p = myBusyChunk->dataStart();
                }
                continue;
            }
            else if (p >= myBusyChunk->dataEnd())
            {
// The test here is based on scanning right up to the very end of the Chunk,
// so it will be important that when a Chunk overflows that a padder object
// is inserted to fill any gap at the end. There is then a jolly edge case.
// If the most recent call to gc_n_bytes() allocated memory that just
// filled up the Chunk and that was used such that evacuating it did not need
// and more memory. Then this thread will not have been allocated its
// next Chunk. However in that case fringe would be set to the same value
// as dataEnd() and I always check for p==fringe before p>=dataEnd() so this
// odd case will never lead to trouble here. Phew! Relief!! The fact that
// I do not hit fringe but do reach dataEnd() must be because a new Chunk
// had been set up for allocation and fringe points within it, and in that
// situation myChunkBase[] will have been updated.
                my_assert(myBusyChunk != myChunkBase);
                myBusyChunk = myChunkBase;
                p = myBusyChunk->dataStart();
                continue;
            }
if (gcTrace) cout << "scanning (1) at " << Addr(p) << "\n";
            LispObject *pp = reinterpret_cast<LispObject *>(p);
// The first word of an object may be one of several possibilities:
//    Header for vector holding binary data;
//    Header for vector holding Lisp data;
//    Header for object with 3 lisp items then binary stuff;
//    Header for symbol;
//    anything else (item is a cons cell).
            LispObject a = *pp;
            size_t len, len1;
#ifdef DEBUG
            if (gcTrace) cout << "First word of " << Addr(pp)
                 << " = " << Addr(a) << "  " << std::hex << (a & 0x1f) << "\n";
if (gcTrace)
{   if (is_cons(a)) cout << "a cons pointer\n";
    else if (is_vector(a)) cout << "pointer to a vector of some sort\n";
    else if (is_forward(a)) cout << "forwarding pointer ILLEGAL HERE\n";
    else if (is_symbol(a)) cout << "pointer to a symbol\n";
    else if (is_numbers(a)) cout << "pointer to a symbol\n";
    else if (is_bfloat(a)) cout << "pointer to a boxfloat\n";
    else if (is_fixnum(a)) cout << "pointer to a number\n";
    else if (is_odds(a))
    {   if (is_header(a))
        {   cout << "header found " << Addr(a) << "   ";
            cout << std::hex << length_of_header(a) << ":"
                 << ((a & header_mask)>>Tw) << ":" << (a & TAG_BITS) << "\n";
        }
        else cout << "immed " << Addr(a) << "\n";
    }
    else cout << "??? " << Addr(a) << "\n";
}
#endif
            my_assert(!is_forward(a), "Forwarding pointer not expected");
            switch (a & 0x1f) // tag bits plus 2 more
            {
// binary literals are C++14, so just for now I will use hex, but I will
// write what the binary literal would be...
            case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                     // Note TYPE_STREAM etc is in with this.
                len = length_of_header(a);
                if (is_mixed_header(a)) len1 = 4*CELL;
                else len1 = len;
// Remember that on a 32-bit machine the final doubleword of a vector
// could be padded with junk.
                for (size_t i = CELL; i<len1; i += CELL)
                    evacuate(*reinterpret_cast<LispObject *>(p+i));
                p += doubleword_align_up(len);
                continue;

            case 0x12: // 0b10010:   // Header for bit-vector
                len = doubleword_align_up(length_of_header(a));
                p += len;
                continue;

            case 0x1a: // 0b11010:   // Header for vector holding binary data
                len = doubleword_align_up(length_of_header(a));
                p += len;
                continue;
            case 0x02: // 0b00010:   // Symbol headers plus char literals etc
                if (is_symbol_header(a))
                {   Symbol_Head *s = reinterpret_cast<Symbol_Head *>(p);
                    evacuate(s->value);
                    evacuate(s->env);
                    evacuate(s->plist);
                    evacuate(s->fastgets);
                    evacuate(s->package);
                    evacuate(s->pname);
                    p += symhdr_length;
                    continue;
                }
                // drop through.
            default:                 // None of the above cases...
                                     // ... must be a CONS cell.
                evacuate(pp[0]);
                evacuate(pp[1]);
                p += 2*CELL;
                continue;
            }
        }
    }
}

void gcHelper()
{
// gcHelper is called to evacuate data from Chunks that have already been
// copied. If none are available and if all GC copying threads agree that
// they have no work to do then just terminate.
    evacuatePartOfMyOwnChunk();
}

void endOfGarbageCollection(bool major)
{   if (gcTrace) cout << "endOfGarbageCollection\n";
// Here all non-pinned live data has been copied to fresh space, so all
// the pages chained up in oldPages can be grabbed and recycled. If such
// a page has no pinned material in it goes in freePages and freePagesCount
// gets incremented. If it has pinned stuff then it needs a sort of free
// chain set up within it to allow for allocation around that, and it then
// goes in mostlyFreePages.
    int count = 0;
    while (oldPages!=nullptr)
    {   Page *p = oldPages;
        oldPages = oldPages->chain;
        if (p->hasPinned)
        {   setUpMostlyEmptyPage(p);
            p->chain = mostlyFreePages;
            mostlyFreePages = p;
            mostlyFreePagesCount++;
        }
        else
        {   setUpEmptyPage(p);
            p->chain = freePages;
            freePages = p;
            freePagesCount++;
        }
        count++;
    }
}

void tellTime(const char *s,
              std::chrono::high_resolution_clock::time_point start,
              std::chrono::high_resolution_clock::time_point finish)
{   std::chrono::duration<double, std::micro> elapsed = finish-start;
    std::chrono::nanoseconds t =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    cout << s << ": " << std::dec << std::fixed << std::setprecision(3)
         << (t.count()/1000.0) << " usec\n";
}

void validatePointers();

void garbageCollect(bool major)
{
#ifdef DEBUG
    gcTrace = true;
#endif // DEBUG
    if (gcTrace) cout << "\n+++++ Start of a "
         << (major ? "major" : "minor")
         << " GC\n";
    auto gcTime1 = std::chrono::high_resolution_clock::now();
    prepareForGarbageCollection(major);
    auto gcTime2 = std::chrono::high_resolution_clock::now();
    clearPinnedInformation(major);
    auto gcTime3 = std::chrono::high_resolution_clock::now();
    identifyPinnedItems(major);
    auto gcTime4 = std::chrono::high_resolution_clock::now();
    findHeadersOfPinnedItems();
    auto gcTime5 = std::chrono::high_resolution_clock::now();
// Report on pinning.
    if (gcTrace) cout << pinnedChunkCount << " pinned Chunks\n";
    if (gcTrace) cout << pinnedPageCount << " pinned Pages\n";
// At this point I am ready to start! I have a fresh part of the heap set
// up so that get_n_bytes() can grab memory from it. I will have
// a number of GC threads all waiting for Chunks to scan.
// I can start the GC by putting all pinned Chunks on the queue of Chunks
// to be processed. Doing so can release some of the worker threads to
// start evacuating their contents.
    evacuateFromPinnedItems(major);
    auto gcTime6 = std::chrono::high_resolution_clock::now();
// Next, and running as the main thread, I evacuate everything that
// is referenced from a precise list-base. These list-bases are the
// fixed variables used by the Lisp system and all items on the Lisp stack.
// In due course I am liable to have to worry about making some of those
// fixed variables thread-local and having one stack per thread, but for now
// I do not!
    evacuateFromUnambiguousBases(major);
    auto gcTime7 = std::chrono::high_resolution_clock::now();
// If I am running a minor GC I will need to deal with "up-pointers" where
// a RPLACx style operation updated old data so that it now points at
// something new enough that the GC may move it.
    if (!major) evacuateFromDirty();
    auto gcTime8 = std::chrono::high_resolution_clock::now();
// Having got everything started I can let the main thread join in with the
// sort of processing that all the worker threads are involved in. This
// scans data that has just been copied and processes anything that it refers
// to. In many respects the hardest part of designing how this works is
// getting a proper termination condition.
    evacuateFromCopiedData(major);
    auto gcTime9 = std::chrono::high_resolution_clock::now();
// Now all relevant data has been copied from old to new space. I need to
// tidy up by releasing the old space so it becomes available for re-use.
// I also need to ensure that the fringe and limit pointers used by the
// GC helper threads are transferred so that they become usable by ordinary
// worker threads. 
    endOfGarbageCollection(major);
    auto gcTime10 = std::chrono::high_resolution_clock::now();
// The timings reported here will at present be deeply misleading because
// they include the time taken by all the debug printing. But at a later
// stage when I disable that the display from here may help me judge
// which parts of the GC deserve the greatest attention by way of tuning.
    tellTime("prepare               ", gcTime1, gcTime2);
    tellTime("clear pins            ", gcTime2, gcTime3);
    tellTime("identify pinned       ", gcTime3, gcTime4);
    tellTime("get headers of pinned ", gcTime4, gcTime5);
    tellTime("evac from pinned      ", gcTime5, gcTime6);
    tellTime("evac from precise     ", gcTime6, gcTime7);
    tellTime("evac from dirty       ", gcTime7, gcTime8);
    tellTime("evac from copied      ", gcTime8, gcTime9);
    tellTime("tidy up               ", gcTime9, gcTime10);
#ifdef DEBUG
// Just to test things!
    testLayout();
    validatePointers();
#endif // DEBUG
}

// This flag generally controls whether a generational collector will be
// used, however an explicit call (reclaim nil) will try a generational
// collection regardless of its setting. It is really just here to help me
// keep control of things until the generation collector has been implemented
// and for switching it on and off for testing and debugging purposes.

bool generationalGarbageCollection = false;

void generationalGarbageCollect()
{   garbageCollect(false);
}

void fullGarbageCollect()
{   garbageCollect(true);
}


//==================

#ifdef DEBUG

static const size_t hashSize = 0x100000;
static LispObject visitedHash[hashSize];

bool inActivePage(LispObject a)
{   if (a==0 || a==nil || is_immediate(a)) return true;
    Page *p = reinterpret_cast<Page *>(a & -pageSize);
    return p->chunkCount != 0;
}

void clearRepeats()
{   memset(visitedHash, 0, sizeof(visitedHash));
}

void validateForGC(LispObject a)
{   if (a == nil || is_immediate(a)) return;
    if (!inActivePage(a))
    {   Page *p = reinterpret_cast<Page *>(a & -pageSize);
        std::cout << "Item " << std::hex << a << " is in page "
            << p << " with count "
            << static_cast<unsigned int>(p->chunkCount) << "\n";
        simple_print(a);
        std::cout << "Quitting\n";
        my_abort();
    }
//  my_assert(inActivePage(a), "item is not in active page");
    my_assert(!is_forward(a), "forwarding pointer in validateForGC");
    size_t h = ((a*3141592653589793237u) >> 40) & (hashSize-1);
    for (;;)
    {   if (visitedHash[h] == a) return;
        else if (visitedHash[h] == 0)
        {   visitedHash[h] = a;
            break;
        }
        h = (h + 1) & (hashSize-1);
    }
    if (is_cons(a))
    {   validateForGC(car(a));
        validateForGC(cdr(a));
        return;
    }
    if (is_symbol(a))
    {   validateForGC(qvalue(a));
        validateForGC(qenv(a));
        validateForGC(qplist(a));
        validateForGC(qfastgets(a));
        validateForGC(qpackage(a));
        validateForGC(qpname(a));
        return;
    }
//    if (is_vector(a)) 
}

void validateUnambiguousBases(bool major)
{   if (gcTrace) cout << "validateFromUnambiguousBases\n";
// This code has to know where ALL the definitive references to LispObjects
// are in the C++ code. The main way it achieves this is through a vector
// "list_bases" that holds the address of every static location involved.
// That vector is about 200 items long. In addition the dedicated Lisp
// stack has to be processed.
    validateForGC(qvalue(nil));
    validateForGC(qenv(nil));
    validateForGC(qplist(nil));
    validateForGC(qpname(nil));
    validateForGC(qfastgets(nil));
    validateForGC(qpackage(nil));
    if (gcTrace) cout << "validate regular list bases\n";
    for (auto p = list_bases; *p!=nullptr; p++)
    {   // cout << (p - list_bases) << "\n";
        validateForGC(**p);
    }
    cout << "\n";
    if (gcTrace) cout << "validate lisp stack\n";
    for (LispObject *sp=stack;
         sp>reinterpret_cast<LispObject *>(stackBase); sp--) validateForGC(*sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (gcTrace) cout << "validate repeat heap\n";
    if (repeat_heap != nullptr)
    {   for (size_t i=1; i<=repeat_count; i++)
            validateForGC(repeat_heap[i]);
    }
}

void validatePinnedInChunk(Chunk *c)
{   uintptr_t p = c->dataStart();
    if (gcTrace) cout << "Pinned chunk has data " << Addr(c->dataStart())
         << " to " << Addr(c->chunkFringe)
         << " end " << Addr(c->dataEnd()) << "\n";
    while (p < c->chunkFringe)
    {
// I could skip up to 512 bytes at a time by using word operations on the
// bitmap, and if I did then the fact that there are only 32 (64-bit) words
// in the bitmap makes this whole scan feel not too bad.
        if (!isPinned(p))
        {   p += 8;
            continue;
        }
        LispObject *pp = reinterpret_cast<LispObject *>(p);
        if (gcTrace) cout << "Scanning pinned item at " << Addr(p) << "\n";
        LispObject a = *pp;
        if (gcTrace) cout << "Item at " << Addr(pp) << " = " << std::hex << a
                          << std::dec << " = " << Addr(a) << "\n";
        my_assert(a != 0, "zero item in heap");
        my_assert(!is_forward(a), "forwarding pointer found");
        size_t len, len1;
        switch (a & 0x1f) // tag bits plus 2 more
        {
// binary literals are C++14, so just for now I will use hex, but I will
// write what the binary literal would be...
        case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                 // Note TYPE_STREAM etc is in with this.
            len = doubleword_align_up(length_of_header(a));
            if (is_mixed_header(a)) len1 = 4*CELL;
            else len1 = len;
            if (gcTrace) cout << "vector (" << std::hex << a << std::dec << ") uses " << len << " bytes\n";
            if (len == 0) if (gcTrace) cout << "At " << Addr(pp) << " up to " << Addr(c->chunkFringe) << "\n";
            for (size_t i = CELL; i<len1; i += CELL)
                validateForGC(*reinterpret_cast<LispObject *>(p+i));
            my_assert(len != 0, "lisp vector size zero");
            p += len;
            continue;

        case 0x12: // 0b10010:   // Header for bit-vector
            len = doubleword_align_up(length_of_header(a));
            my_assert(len != 0, "bit vector size zero");
            if (gcTrace) cout << "bit-vector uses " << len << " bytes\n";
            p += len;
            continue;

        case 0x1a: // 0b11010:   // Header for vector holding binary data
            len = doubleword_align_up(length_of_header(a));
            my_assert(len != 0, "binary vector size zero");
            if (gcTrace) cout << "binary-vector uses " << len << " bytes\n";
            p += len;
            continue;

        case 0x02: // 0b00010:   // Symbol headers plus char literals etc
            if (is_symbol_header(a))
            {   Symbol_Head *s = reinterpret_cast<Symbol_Head *>(p);
                validateForGC(s->value);
                validateForGC(s->env);
                validateForGC(s->plist);
                validateForGC(s->fastgets);
                validateForGC(s->package);
                validateForGC(s->pname);
                if (gcTrace) cout << "symbol uses " << symhdr_length << " bytes\n";
                if (gcTrace) cout << "inc from " << Addr(p) << " to " << Addr(p+symhdr_length) << "\n";
                p += symhdr_length;
                continue;
            }
            // drop through.
        default:                 // None of the above cases...
                                 // ... must be a CONS cell.
            validateForGC(pp[0]);
            validateForGC(pp[1]);
            if (gcTrace) cout << "cons cell uses " << (2*CELL) << " bytes\n";
            p += 2*CELL;
            continue;
        }
    }
}

void validatePinnedItems(bool major)
{   if (gcTrace) cout << "validate Pinned Items\n";
    for (Page *p=pagesPinChain; p!=nullptr; p=p->pagePinChain)
    {   for (Chunk *c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
        {   if (gcTrace) cout << "Pinned items in " << Addr(c) << " to check\n";
            validatePinnedInChunk(c);
        }
    }
}

void validatePointers()
{   clearRepeats();
    validateUnambiguousBases(true);
    validatePinnedItems(true);
    if (gcTrace) cout << "Validation complete\n";
}

#endif // DEBUG

// These functions whose initial letter is "F" are ones that give me
// access to the value of atomic items in Chunk, Page and globally. I have
// these because gdb (at least on some platforms) will not let me go (eg)
// "print gFringe" because it has inlined the load function. So I
// use "print FgFringe()" instead. Well if FgFringe() is defined in a header
// as an inline function and then never referenced in the code it is omitted
// totally and so is not available for debugging. So this function is here
// to contain rather stupid references to all these "F" functions. I disable
// optimisation when I compile it to try to ensure that it serves the purpose
// of making external references to all the functions. It would not be a very
// good idea to call this!

#if defined __clang__
#pragma clang optimize off
#elif defined __GNUC__ // __clang__
#pragma GCC optimize("0")
#endif //__clang__ or __GNUC__

void getInlineFunctionsDefined()
{   Chunk c;
    (void)c.Flength();
    (void)c.FchunkFringe();
    (void)c.FpinnedObjects();
    (void)c.FisPinned();
    (void)c.FpendingChunks();
    Page p;
    (void)p.Ffringe();
    (void)p.Flimit();
    (void)p.FhasPinned();
    (void)p.FpagePinChain();
    (void)p.FchunkPinChain();
    (void)p.FchunkCount();
    (void)p.FchunkMap(0);
    (void)Flimit();
    (void)FgFringe();
    (void)FactiveThreads();
}

// end of file newcslgc.cpp
