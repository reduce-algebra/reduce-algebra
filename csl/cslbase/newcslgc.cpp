// File newcslgc.cpp                      Copyright (c) Codemist, 1990-2020

//
// Garbage collection.
//

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

using std::hex;
using std::dec;

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
// pushed on the pages pinnedChunks list using its pinChain field.
// When the first Chunk on a Page is pinned the hasPinned flag in the
// Page is set and the Page is pushed onto globalPinChain through its
// pinChain field.
// Note that the process of pinning something never creates a new Chunk, so
// the chunkMap just needs to be as established while allocation within the
// Page was happening, and the it only needs sorting once at the start of
// a GC.
// When at some later stage it is necessary to allocate within a Page that
// has some pinned Chunks the otherwise empty Page should end up with
// a chunkMap that only mentions the pinned Chunks. This is all dealt with
// in setUpUsedPage. the chunkMap is cleared and then re-created from the
// list pinnedChunks. That may leave it is an arbitrary order, so it is then
// sorted and with that done pinnedChunks can be re-created in ascending
// order. Then fringe and limit are set up within the Page. limit will
// point to the first pinned Chunk. That will have a length field indicating
// where there is free space beyond it and a pinChain entry that refers to
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
// all space within it will be filled with padding items. This has to be done
// because one or more Chunks within it may be pinned, and any such Chunks
// are scanned sequentially as precise list bases.
// @@@ Hmmm @@@ I could have another field in a Chunk header called (say)
// usedLength so that if a Chunk was not totally full then rather than
// putting a padder at the end the tail of it could avoid scanning by
// reference to that. A benefit of such a scheme would be that if the Chunk
// ended up pinned then it would be possible to reserve space just up as far
// as usedLength and use the space at the end.
//
// MOSTLYFREE pages are chained on mostlyFreePages while FREE ones are on
// freePages.
//
// During early stages of Garbage Collection all BUSY pages and all MOSTLYFREE
// ones will need their chunkMaps. Neither need and pinChain information.
// At the time I sort the chunkMap (ie when I find the first pin in the
// Page) I must reset the isPinned flag on all Chunks in that page and
// chear the pinChain. Then while pinning a Chunk those two get updated.
// The situation after that is that I have a list of the Pages that contain
// pinned Chunks this time, and within each such Page I can identify those
// Chunks easily. 
//
// Now move busyPages to OldPages and set up a new CurrentPage. While
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
// For statistical and evaluation purposes at this stage it will be
// interesting to see how many Pages contain pinned Chunks and both how
// many Chunks are involved and what proportion of the Pages concerned they
// use. That will be information I can gather before getting all the rest
// of the GC working!
//

//
// Evacution:
//   If the location to be evacuated holds immediate data do nothing,
//     otherwise it holds a pointer to some object.
//   If that object is to something in a MostlyFree page or one of the
//     pages I am at present allocating in then it must be to something that
//     had been pinned last time.
//   [now it is points into an oldPage. I must check if it is in a
//     pinned Chunk. Well at this stage I will have set things up so that
//     the ONLY Chunks in the chunkMap of such a page are the [newly] pinned
//     ones and I do not expoct there to be many, so binary search in the
//     chunkMap should be quick.] If into a pinned chunk it is left alone.
//   If the CAR field of the object holds a forwarding address use that to
//     update the location to be a proper pointer to relocated data. Done!
//   Make a (binary) copy of the object in the next free space within C.
//   Set the CAR field to be a forwarding address to the copy.
// Note that the copy will then (in due course) be scanned. For that to be
// feasible the Pages where I allocate copied material (including pinned
// Chunks embedded within them) must have padder items etc such that I will
// be able to perform a linear scan.


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

// During garbage collection I will allocate items in the half of my memory
// that has been free up to now.
// In an earlier draft of this I had a separate bit of code to do that, such
// that the code was a ralative of that in get_n_bytes but did not support
// concurrency at all. My thought now is that for a major garbage collection
// I will be abandoning the old half-space and when it is complete I will
// allocate in the new one - and so a tidy scheme is to make that change-over
// at the start of the GC and then throughout the copying process I just
// use the existing get_n_bytes code. Well I will need to review that so
// that when a Page becomes full I always just allocate a fresh one rather
// that having any thought of (re-)entering the GC.
// Doing things this way automatically provides support for multi-thread
// allocation and so for future experiments with multi-thread copying in
// the (global) garbage collection. It adds some overhead in that at the end
// of each Chunk I will need to perform atomic increments, and my fringe and
// limit values will have to be thread-local - again that would ne essential
// for parallelism within the GC and I am going to hope it is a modest
// overhead anyway.

bool withinMajorGarbageCollection = false;

void evacuate(LispObject *p)
{
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
    {   *p = aa + ((a&TAG_BITS)-TAG_FORWARD);
        return;
    }
    size_t len;
    if (is_cons(a)) len = 2*CELL;
    else if (is_symbol(a)) len = symhdr_length;
    else len = doubleword_align_up(length_of_header(aa));
    aa = get_n_bytes(len);
    std::memcpy(reinterpret_cast<void *>(aa), ap, len);
    *ap = TAG_FORWARD + aa;
    *p = aa + (a&TAG_BITS);
}

// For the following p starts off as a pointer to the first word of an object.
// It must identify the object type and call evacuate() on every pointer-
// holding field within it. It returns a pointer just beyond the object.

LispObject *evacuateContents(LispObject *p)
{   LispObject a = *p;
// a will NOT be a forwarding pointer because any object may only have this
// operation invoked on it once. If the object is a symbol or a vector then
// a will be tagged as its header. In other cases the object will be just
// a CONS cell.
    if (!is_odds(a) || !is_header(a))
    {   evacuate(&p[0]);            // A cons cell.
        evacuate(&p[1]);
        return &p[2];
    }
    if (is_symbol_header(a))
    {
//...
        return &p[symhdr_length/CELL];
    }
    size_t len = length_of_header(a);
    if (vector_holds_binary(a)) return &p[doubleword_align_up(len)/CELL];
//...
    return &p[doubleword_align_up(len)/CELL];
}

void prepareForGarbageCollection(bool major)
{   cout << "prepareForGarbageCollection" << endl;
    if (major)
    {   withinMajorGarbageCollection = true;
        oldPages = busyPages;
        oldPagesCount = busyPagesCount;
        busyPages = nullptr;
        busyPagesCount = 0;
        currentPage->chain = oldPages;
        oldPages = currentPage;
        oldPagesCount++;
        grabNewCurrentPage();
    }
    else
    {   cout << "prepare for minor GC not coded yet\n";
        my_abort();
    }
}

void clearPinnedInformation(bool major)
{   cout << "clearPinnedInformation" << endl;
    my_abort();
}

// Each page consists of a header followed by a number of chunks. There may
// be unused space in the page after the last chunk. For the purposes of
// pinning I want to identify the chunk (if any) that (a) points into, and
// arrange that it is on a per-page list of pinned chunks and that if there
// are any such chunks that the page itself is on a list of pages that contain
// pinned material.

void processAmbiguousInPage(bool major, Page *p, uintptr_t a)
{   if (p->chunkCount.load() == 0) return;  // An empty Page.
    cout << "Ambig " << hex << a << " in page " << p << dec << endl;
// The list of chunks will be arranged such that the highest address one
// is first in the list. I will now scan it until I find one such that
// the chunk has (a) pointing within it, and I should not need many tries
// at all. The soring order MUST be consistent with the order I assume in
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
    size_t low = 0, high = p->chunkCount.load()-1;
    while (low < high)
    {   size_t middle = (low + high + 1)/2;
        if (a < reinterpret_cast<uintptr_t>(p->chunkMap[middle].load()))
            high = middle-1;
        else low = middle;
    }
    Chunk *c = p->chunkMap[low];
    cout << "pointer is maybe within chunk " << low << " at " << hex << c << dec << endl;
    if (!c->pointsWithin(a)) return;
    cout << "Within that chunk: isPinned = " << c->isPinned << endl;
// Here (a) lies within the range of the chunk c. Every page that has any
// pinning must record that both by being on a chain of pages with pins
// and by having a list of its own pinned chunks.
// If the chunk is already tagged as pinned there is no need to do so again.
    if (c->isPinned) return;
    c->isPinned = true;
// Note that a single thread looks at ambiguous pointers so while I want
// everything atomic<> so that later on if other threads happen to look you
// you know they will see updates, I do not need to worry about race
// conditions while I form the chain of pinned chunks and pages.
    c->pinChain = p->pinnedChunks.load();
    p->pinnedChunks = c;
// When a chunk gets pinned then page must be too unless it already has been.
    cout << "Page hasPinned = " << p->hasPinned << endl;
    if (p->hasPinned) return;
    p->hasPinned = true;
    p->pinChain = globalPinChain;
    globalPinChain = p;
}

// typedef processPinnedChunk(Chunk *c);

void scanPinnedChunks(processPinnedChunk *pc)
{   cout << "scanPinnedChunks globalPinChain = " << hex << globalPinChain << dec << endl;
    for (Page *p = globalPinChain; p!=nullptr; p=p->pinChain)
    {   cout << hex << p << dec << " hasPinned=" << p->hasPinned << endl;
        if (!p->hasPinned) continue;
        cout << hex << p << " pinnedChunks=" << p->pinnedChunks << dec << endl;
        for (Chunk *c = p->pinnedChunks; c!=nullptr; c=c->pinChain)
        {    cout << hex << c << dec << " isPinned=" << c->isPinned << endl;
            if (!c->isPinned) continue;
            (*pc)(c);
        }
    }
}

void clearAllPins()
{   for (Page *p = globalPinChain; p!=nullptr; p=p->pinChain)
    {   p->hasPinned = false;
        for (Chunk *c = p->pinnedChunks; c!=nullptr; c=c->pinChain)
            c->isPinned = false;
        p->pinnedChunks = nullptr;
    }
    globalPinChain = nullptr;
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
            processAmbiguousInPage(major, previousPage, a);
        return;
    }
    Page *p = findPage(a);
    if (p!=nullptr) processAmbiguousInPage(major, p, a);
}

void identifyPinnedItems(bool major)
{
// For each ambiguous value (ie value on the stack associated with
// any thread) do processAmbiguousValue(). This must ensure that if
// the item might be a LispObject that is a reference that the destination
// address of that reference is marked as "pinned". During a minor GC
// the only items that need special marking will be one in the "previous"
// page since nothing else will ever be moved.
    for (unsigned int thr=0; thr<maxThreads; thr++)
    {   if ((threadMap & threadBit(thr)) != 0)
        {   uintptr_t base = stackBases[thr];
            uintptr_t fringe = stackFringes[thr];
// Here I am supposing that for each thread the (C++) stack is a single
// block of memory, that it is aligned as a sizeof(LispObject) boundary
// and that EVERY interesting value is present on the stack with no change
// that the only live pointer to some data is in a machine register. On the
// way in to the Garbage Collector I have tried quite hard to ensure that
// last point, but none of this can be guaranteed by reference to the rules
// of the C++ standard!
          for (uintptr_t s=fringe; s<base; s+=sizeof(uintptr_t))
            {   processAmbiguousValue(major,
                                      *reinterpret_cast<uintptr_t *>(s));
            }
        }
    }
}

void evacuateFromUnambiguousBases(bool major)
{   cout << "evacuateFromUnambiguousBases" << endl;
    my_abort();
}

void evacuateFromPinnedItems(bool major)
{   cout << "evacuateFromPinnedItems" << endl;
    my_abort();
}

void evacuateFromDirty()
{   cout << "evacuateFromDirty" << endl;
    my_abort();
}

void evacuateFromCopiedData(bool major)
{   cout << "evacuateFromCopiedData" << endl;
    my_abort();
}

void endOfGarbageCollection(bool major)
{   cout << "endOfGarbageCollection" << endl;
    my_abort();
}

void garbageCollect(bool major)
{   cout << "\n+++++ Start of a "
         << (major ? "major" : "minor")
         << " GC\n";
    prepareForGarbageCollection(major);
    clearPinnedInformation(major);
    identifyPinnedItems(major);
    evacuateFromUnambiguousBases(major);
    evacuateFromPinnedItems(major);
    if (!major) evacuateFromDirty();
    evacuateFromCopiedData(major);
    endOfGarbageCollection(major);
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

// end of file newcslgc.cpp
