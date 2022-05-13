// File newcslgc.cpp                      Copyright (c) Codemist, 2018-2022


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

#include "headers.h"


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

// There is a messy issue here. Suppose a Page P has a Chunk C that contained
// some pinned items during the last GC then P is on the list of pages that
// have pinned data and C is in a chain starting from P. Now suppose that
// the pinned items in C are not referenced this time. Then C must not end
// up on the chain of pinned items within P. That may be OK because
// I set up that chaining here. But if P ends up without any pinned Chunks
// it needs to be unlinked from the chain of pages with pins. Maybe that too
// will be OK because I can do that when I conclude it is a Free page rather
// than a MostlyFree one.

// v is the untagged address of a LispObject and a is an ambiguous
// reference. This must return true if a refers to an address within the
// object identified by v. The type of v has to be deduced by inspecting
// its first word.

bool withinObject(LispObject* v, uintptr_t a)
{   size_t len;
    uintptr_t uv = reinterpret_cast<uintptr_t>(v);
    LispObject h = *v;
    switch (h & 0x1f)
    {
// Here is is immaterial whether a vector holds binary or Lisp data.
        case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                               // Note TYPE_STREAM is in with this.
        case 0x12: // 0b10010: // Header for bit-vector
        case 0x1a: // 0b11010: // Header for vector of binary data
// I demand that length_of_header() gives a proper length for byte- and
// bit-vectors at least as far as the number of words that are used. But then
// I round it up to a multiple of 8.
            len = doubleword_align_up(length_of_header(a));
            break;
        case 0x02: // 0b00010: // Symbol headers, char literals etc.
            if (is_symbol_header(h)) len = symhdr_length;
            else len = 2*CELL;
            break;
        default:                 // None of the above cases...
            len = 2*CELL;        // ... must be a CONS cell.
            break;
    }
    return (a >= uv && a < (uv+len));
}

// The ambiguous value (a) seems to point within the page (p). I do
// different things based on the sort of page involved... pointers into
// CONS pages will be the simplest to handle.

void processAmbiguousInPage(Page* p, uintptr_t a)
{   uintptr_t dataStart;
    switch (p->type)
    {
    case emptyPageType:
        return;
    case consFullPageType:
    case consPinPageType:
// This is the simplest case, mainly because all objects in the page
// are neatly aligned on 2-cell boundaries.
        a = a & -(2*sizeof(LispObject));   // align the pointer (a).
        dataStart = reinterpret_cast<uintptr_t>(&p->consData);
// If the ambigious pointer points before any real data in the page
// it is invalid. If it points before consDataEnd it is valid, but this
// needs a small extra bit of commentary. Either it is a pointer to
// recently allocated data in the page, or it is to some item previously
// pinned and which is still to be pinned. Finally if it is above
// consDataEnd then it is only valid if it refers to data that had
// previously been pinned.
// Any pages that are of type consPinPageType get handled the same way
// provided I ensure that they always have consDataEnd set to the value
// of dataStart, because then the ambiguous reference will only be deemed
// valid if it points to old pinned material.
        if (a < dataStart) return;
        else if (a < p->dataEnd ||
                 consIsPreviousPinned(a, p))
        {   consSetPinned(a, p);
// The first time I find an object pinned on a page I will put that page
// in a chain of ones containing pinned material.
            if (p->pinnedObjects == TAG_FIXNUM)
            {   p->pinnedPages = pinnedPages;
                pinnedPages = p;
            }
            LispObject z = GCGet2Words();
// The next line is to ensure that the CONS just allocated never gets pinned.
            consCurrent->type = emptyPageType;
            car(z) = a + TAG_FIXNUM;
            cdr(z) = p->pinnedObjects;
            p->pinnedObjects = z + TAG_FIXNUM;
        }
        return;
    case vecFullPageType:
    case vecPinPageType:
// pointers into vector pages can refer to any individual cell. The biggest
// cause of pain here is that the pointers may refer to addresses within
// objects (as distinct from just identifying the object header). I do
// not have a trivial way to tell where objects start, so I will tend to
// set mark bits now even when they are not on object headers and correct
// in a later phase. This is where I rely on "chunks" and I will view
// an ambiguous pointer as "provisionally valid" either if it is at an
// address before vecDataEnd or if it is into a chunk beyond that where
// the chunkStatus entry has the 0x80 bit set to indicate that it contains
// at least some old pinned material. When I set a mark bit I will tag
// the chunk as "of interest" in another little bitmap, and push the Page
// onto a chain of one to deal with later.
        {   a = a & -(sizeof(LispObject));   // align the pointer (a).
            dataStart = reinterpret_cast<uintptr_t>(&p->chunks);
            if (a < dataStart) return;
            size_t chunkNo = (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
// The pointer may be valid either if it refers ro an address below the
// fringe or if it is withing a chunk that had been pinned during an
// earlier GC.
            if (a < p->dataEnd ||
                (p->chunkStatus[chunkNo] & 0x80) != 0)
            {   int c = p->chunkStatus[chunkNo];
// If the pointer is somewhere within an extended Chunk then I will
// skip back to the first chunk making it up. This case can apply if
// there is a reference some way down a rather large vector.
                while ((c & 0x7f) != 0)
                    c = p->chunkStatus[chunkNo -= c & 0x7f];
// Now I tag the Chunk as potentially pinned. It will not actually be pinned
// if the dodgy address points within a padder item in it.
                if (!isPotentiallyPinnedChunk(p, chunkNo))
                {   setPotentiallyPinnedChunk(p, chunkNo);
// ... and note when Pages contain such material.
                    if (!p->potentiallyPinnedFlag)
                    {   p->potentiallyPinnedFlag = true;
                        p->potentiallyPinnedChain = potentiallyPinned;
                        potentiallyPinned = p;
                    }
                }
                vecSetPinned(a, p);
            }
            return;
        }
    default:
        my_abort("page type not recognised");
    }
}

// Here I have an item that may be arbitrary binary material but which COULD
// be a LispObject that will later be re-used. If it is a LispObject that
// refers to memory address (a) then I will want to be certain that garbage
// collection does not relocate material at (a).
// During GC I will need to determine whether (a) points anywhere
// within memory that is currently in use holding active Lisp data. This
// could be within the page currently beinf allocated into, and page full
// of live data or it could be a continuing reference to material pinned
// but a previous GC but now in an almost empty page.

void processAmbiguousValue(uintptr_t a)
{
// I find the Page (if any!) the value is in. That Page may be empty,
// one containing old pinned stuff or one full of live data.
    Page* p = findPage(a);
    if (p!=nullptr) processAmbiguousInPage(p, a);
}

// The following function scans the stack for each thread. The address
// sanitizer gets upset at this when it looks at return addresses and
// the like, so I need to disable it here... After all looking at locations
// on the stack but between the proper stack frames is indeed a bit
// "dodgy"!

NO_SANITIZE_ADDRESS
void identifyPinnedItems()
{
#ifdef DEBUG
// Just while I develop the code.
    for (int i=0; i<10; i++)
        processAmbiguousValue(ambiguous[i]);
#else // DEBUG
// For each ambiguous value (ie value on the stack) processAmbiguousValue().
// This must ensure that if the item might be a LispObject that is a
// reference that the destination address of that reference is marked as
// "pinned".
// Here I am supposing that the (C++) stack is a single block of memory,
// that it is aligned as a sizeof(LispObject) boundary and that EVERY
// interesting value is present on the stack with no chance that the only
// live pointer to some data is in a machine register. On the
// way in to the Garbage Collector I have tried quite hard to ensure that
// last point, but none of this can be guaranteed by reference to the rules
// of the C++ standard!
    for (uintptr_t s=C_stackFringe; s<C_stackBase; s+=sizeof(uintptr_t))
        processAmbiguousValue(*reinterpret_cast<uintptr_t*>(s));
#endif // DEBUG
}

// This not only ensures that the bitmap identifies the head of every
// pinned item, but it also arranges that no addresses within objects are
// marked. This is relied upon by evacuatePinnedInChunk.
//
// It only needs to look at vector pages where there was fresh (potential)
// pinning. Within those it needs to look at chunks where a new ambiguous
// pointer is relevant. If the chunk is one that had left over pinned
// data from a previous GC then it will have padder objects between
// all those old pinned items, so I can easily skip those to find just
// where the pinned material is. A non-extended chunk is 16KB so has a
// max of 2K objects in it (on a 64-bit machine) and that is covered by
// just 32 words (of 64-bits each) in the pin-bitmap. So I will use
// find-first-bit operations so I can scan the new bitmap and I will
// skip over padders and then parse actual pinned items. By doing that
// I can tell if a new pin bit is actually within a previously pinned
// object. If it is not it was not a valid pin. If it is I need to move
// the pin bit so it is on the object header.
// The second case is if the chunk in question was new. In that case any
// pointer into it that does not refer to a padder is valid and must be
// moved to the object header.
// Well happily I can deal with both cases using the same code, because
// pointers into previously pinned chunks that are invalid will be to
// addresses within padder objects, so the general rule that padders are not
// proper data will apply to them.

// In find HeadersInChunk the pointer a starts off at the start of a chunk,
// and it could be that this will be the first of an extended Chunk. I
// need to parse it to identify the objects present. Then the
// currentVecPins[] bitmap should identify where ambiguous pointers
// fall. So as I parse and identify an object I need to sort out the
// range of bits within that map and test them. If any are set then I
// clear any that are not to the header of the object and set one on
// the header (unless the object is a padder).

void findHeadersInChunk(size_t firstChunk, Page* p)
{   size_t lastChunk = firstChunk+1;
// First I need to sort out the start and end addresses associated with
// what may be an extended Chunk. So I will arrange that lastChunk is
// either the number beyond that for the last chunk in the Page or
// is tha number for the next chunk that has a zero status, ie is
// either a freestanding chunk or the first part of an extended one. Then
    while (lastChunk < pageSize/chunkSize &&
           (p->chunkStatus[lastChunk] & 0x7f) != 0) lastChunk++;
    uintptr_t firstAddr = reinterpret_cast<uintptr_t>(p) +
                          firstChunk*chunkSize;
// endAddr is just beyond the last data I need to scan here.
    uintptr_t endAddr   = reinterpret_cast<uintptr_t>(p) +
                          lastChunk*chunkSize;
    uintptr_t s = firstAddr;
    while (s < endAddr)
    {   uintptr_t a = *reinterpret_cast<uintptr_t*>(s);
        size_t len;
// Now based on its first word I need to decode the LispObject at address s.
// In many cases it will have an explicit header word that contains length
// information. Here I do not need to worry whether vectors contain
// binary data or more Lisp pointers - all I need to sort out is the
// length of the object concerned.
        switch (a & 0x1f)
        {
    case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                           // Note TYPE_STREAM is in with this.
    case 0x12: // 0b10010: // Header for bit-vector
            len = doubleword_align_up(length_of_header(a));
            break;
    case 0x02: // 0b00010: // Symbol headers, char literals etc.
// The code is either for the header of a symbol or for some sort
// of immediate data, and in the latter case the object must be
// a CONS cell.
            if (is_symbol_header(a)) len = symhdr_length;
            else len = 2*CELL;
            break;
    default:                 // None of the above cases...
            len = 2*CELL;    // ... must be a CONS cell.
            break;
        }
        uintptr_t final = s + len - sizeof(LispObject);
// I will take special action of the object found is a padder. In that
// case I will clear all the pin bits for addresses within the object.
        uintptr_t o1 = (s - reinterpret_cast<uintptr_t>(p)) /
                       sizeof(LispObject);
        uintptr_t o2 = (final - reinterpret_cast<uintptr_t>(p)) /
                       sizeof(LispObject);
        size_t w1 = o1/64;
        size_t w2 = o2/64;
        int bit1 = o1 & 63;
        int bit2 = o2 & 63;
        uint64_t mask1 = static_cast<uint64_t>(-1) << bit1;
        uint64_t mask2 = static_cast<uint64_t>(-1) >> (63-bit2);
        if (is_padder_header(a))
        {   // what I have here is in effect "clearVecPins(s, endS, p)";
            if (w1 == w2)
                p->currentVecPins[w1] &= ~(mask1 & mask2);
            else
            {   p->currentVecPins[w1] &= ~mask1;
                for (uintptr_t w=w1+1; w<w2; w++)
                    p->currentVecPins[w] = 0;
                p->currentVecPins[w2] &= ~mask2;
            }
            s += len;
            continue;
        }
        else if (w1 == w2)
        {   bool pinFound = (p->currentVecPins[w1] & mask1 & mask2) != 0;
            p->currentVecPins[w1] &= ~(mask1 & mask2);
            if (pinFound)
                p->currentVecPins[w1] |= static_cast<uint64_t>(-1) << bit1;
        }
        else
        {
// Now I need to check if any address in the range s <= x <= final has
// been marked as pinned, and if so clear internal pin bits and set one
// on the header word.
            bool pinFound = (p->currentVecPins[w1] & mask1) != 0;
            p->currentVecPins[w1] &= ~mask1;
            for (size_t w=w1+1; w<w2; w++)
            {   if (p->currentVecPins[w] != 0) pinFound = true;
                p->currentVecPins[w] = 0;
            }
            if ((p->currentVecPins[w2] & mask2) != 0) pinFound = true;
            p->currentVecPins[w2] &= ~mask2;
            if (pinFound)
            {   p->currentVecPins[w1] |= static_cast<uint64_t>(-1) << bit1;
                if (p->pinnedObjects == TAG_FIXNUM)
                {   p->pinnedPages = pinnedPages;
                    pinnedPages = p;
                }
                LispObject z = GCGet2Words();
// The next line is to ensure that the CONS just allocated never gets pinned.
                consCurrent->type = emptyPageType;
                car(z) = s + TAG_FIXNUM;
                cdr(z) = p->pinnedObjects;
                p->pinnedObjects = z + TAG_FIXNUM;
            }
        }
        s += len;
    }
}

void findHeadersOfPinnedItems()
{   for (Page* p=potentiallyPinned; p!=nullptr; p=p->potentiallyPinnedChain)
    {   for (size_t i=0; i<sizeof(p->potentiallyPinnedChunks)/8; i++)
        {   uint64_t bits = p->potentiallyPinnedChunks[i];
            while (bits != 0)
            {   int trailingZeros = ntz(bits);
                size_t chunkNo = 64*i + trailingZeros;
                findHeadersInChunk(chunkNo, p);
                bits &= ~(static_cast<uint64_t>(1) << trailingZeros);
            }
        }
    }
}

// I start garbage collection by  making the current allocation pages
// have the structure of ones that are full. The only thing that involves
// is storing fringe pointers in them.

void inner_garbage_collect()
{
    cout << "Page size = " <<std::hex << sizeof(Page) << std::dec << "\n";
// I start by setting the end-point information in the two current pages.
// That leaves them in the proprer state to count as "full", so that when
// the GC looks at ambiguous pointers it will be able to be aware when
// an apparent pointer is to a location above the fringe. Note that any
// final chunk in the vector page needs to have a padder inserted.
    if (vecFringe != vecLimit)
        setHeaderWord(vecFringe, vecLimit-vecFringe);
    consCurrent->dataEnd = consFringe;
    vecCurrent->dataEnd = vecFringe;
// Next I move the currently used pages to an "old" chain.
    consOldPages = consFullPages;
    vecOldPages = vecFullPages;
    consFullPages = vecFullPages =
        consFullPagesTail = vecFullPagesTail = nullptr;
    consFullPagesCount = vecFullPagesCount = 0;
    pinnedPages = nullptr;
// ... and allocate what will be the start of the new half-space.
// Well here I will not want any ambiguous pointers into this new
// space to be deemed valid, and I will be putting stuff into the
// CONS region as a list of pinned objects - so on a temporary basis
// I will mark the pages as free!
    consCurrent = grabFreshPage();  initConsPage(consCurrent);
    pageAppend(consCurrent,
               consFullPages, consFullPagesTail, consFullPagesCount);
    consCurrent->type = emptyPageType;
    vecCurrent = grabFreshPage();   initVecPage(vecCurrent);
    pageAppend(vecCurrent,
               vecFullPages, vecFullPagesTail, vecFullPagesCount);
// Now I can scan the stack and mark up pinned items. This will build
// up a chain of pages still 
    identifyPinnedItems();
    findHeadersOfPinnedItems();
    zprintf("Try to report on pinning...\n");
    {   for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
        {   zprintf("Page %a contains some pinned material\n", pp);
            for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                            c!=0;
                            c=cdr(c)-TAG_FIXNUM)
            {   zprintf("Pinned object at address %a\n", car(c)-TAG_FIXNUM);
            }
        }
    }
    my_abort("This is how far GC has got");
}

// The following code makes a whole slew of assumptions about how the
// compiler and system library will treat it! I will explain what I hope
// will happen, but a sufficiently clever compiler could without doubt
// defeat me.

// A C++ system is liable to have some "callee save" registers and keep the
// values of some variable in them. A conservative garbage collector needs
// to access their values. I EXPECT that setjmp will dump copies of all
// such registers (at least!) into the jmp_buf, thus ensuring that a copy of
// all the data is present on the stack. Well here the jmp_buf is not
// referenced again or elsewhere, so maybe a compiler could consider it
// unused and just remove the call to setjmp. To discourage that I have
// buffer_pointer referring to the jmp_buf, and then at least potentially
// (as far as the compiler can tell) in some other compilation unit there
// might be code reachable from inner_garbage_collect() that does a longjmp()
// via it.
// Well that I guess would depend on there being a call from the code in
// action() to something far enough away that the ocmpiler does not see it,
// and whole-program optimisation could defeat that!
// I alse want the jmp_buf to have been allocate on the stack at a lower
// address than any other values currently in use. The "NOINLINE" qualifier
// as provided by gcc is intended to help to enforce that by arranging that
// garbage_collect() has its own stack frame with almost nothing except
// inner_garbage_collect() and the jmp_buf in it. If inner_garbage_collect
// has its code lifted inline ans some of then values used within it
// ended up on the stack above buffer that should not be a problem. It
// would merely lead to those being candidate ambiguous pointers.
//

std::jmp_buf* buffer_pointer;

NOINLINE void garbage_collect()
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
    if (setjmp(buffer) == 0)
    {   C_stackFringe = reinterpret_cast<uintptr_t>(&buffer);
        inner_garbage_collect();
        std::longjmp(buffer, 1);
    }
}


#ifdef REWORKED
//~
//~ extern void dumpHeap(const char*);
//~ extern void dumpHeap(const char*, const char*);
//~ extern void dumpHeap(const char*, unsigned int);
//~ extern void dumpHeap(const char*, const char*, unsigned int);
//~
//~ extern void rawHeap(const char*);
//~ extern void rawHeap(const char*, const char*);
//~ extern void rawHeap(const char*, unsigned int);
//~ extern void rawHeap(const char*, const char*, unsigned int);
//~ 
//~
//~ // Pinning:
//~ // When I have an ambigious pointer any object it (might) point at must
//~ // not be relocated by the GC, and that means that subsequent allocation must
//~ // work around such static data. What I describe here is my April 2021 set of
//~ // thoughts, which are a significant update to ones from earlier!
//~ // There are three stages where these ambiguous pointers impact what I have
//~ // to do:
//~ // (1) Identifying them at the start of garbage collection;
//~ // (2) Tracing and processing data pointed at from pinned regions;
//~ // (3) Coping with pointers from live data to pinned items;
//~ // (4) Arranging free storage so that subsequent allocation does not
//~ //     overwrite them.
//~ // The scheme I use interacts with the general storage allocation procedures
//~ // that I use, which are themselves conditioned by thoughts of concurrency
//~ // and thread support.
//~ //
//~ // I will comment on (3) first. When I inspect a (precise) pointer during the
//~ // copy phase of the GC I must check if it in fact points to data that is
//~ // "pinned" because an ambiguous pointer appears to refer to it. This test
//~ // has to be made for every pointer considered, and so is speed critical.
//~ // To spell things out further, if a safe, valid, precise pointer from any
//~ // list base or from anywhere within the active heap happens to point at a
//~ // pinned object then it must detect that fact and avoid relocating the
//~ // object.
//~ // To make this acceptably fast I will use a bitmap. Given the precise pointer
//~ // I mask it based on my page size - that gets me to the base of the Page that
//~ // it lies within. In the header to that page there is a map with 1 bit for
//~ // each 8-byte unit. If the Page is 8 Mbytes this map is only 128K so as a
//~ // burden on space it is not a disaster.
//~ // With that design decision made I now need to cope with the other issues.
//~ // Note that the bitmap I have just discussed must have a bit set to mark
//~ // the first or header word of every object. That is because when it is
//~ // inspected only precise pointers and so pointers refer to that header.
//~ // It would not make sense to have to check for pin-bits elsewhere!
//~ // The hard part of (1) is that an ambiguous pointer may (appear to) point
//~ // into the middle of a large object that contains binary information. For
//~ // instance a string or a bignum. Any inspection of data near where the
//~ // reference points then sees part of that arbitrary material which can
//~ // not be relied upon to be informative.
//~ // My resolution of this is to note that for the purposes of allocation in
//~ // a threaded implementation I have my memory split into "Chunks". These
//~ // are typically 16Kbytes long but have to be longer when a huge object
//~ // get allocated, but even when that happens the number of items within any
//~ // one Chunk will be around 1000 on a 64-bit machine (or up to twice that
//~ // on a 32-bit system).
//~ // So when I am recording ambiguous pointers I will take two steps. The
//~ // easy one is to mark in my bitmap the 8-byte address referenced. If the
//~ // value was in fact pointing at or very close to the object head that
//~ // is great, but in general it will mark some memory within an object. The
//~ // harder part is that I will identify and mark the Chunk containing the
//~ // address. Well given the pointer I can identify the Page that it lies within
//~ // using a simple masking operation. Each Page will then need to contain a
//~ // sorted table of the Chunks within it. There can be at most about 500
//~ // Chunks so a binary search costs about 9 comparisons. I set a flag in the
//~ // Chunk header to the effect that it contains pinned data and I push it
//~ // onto a chain of such Chunks. I am going to expect that when ambiguous
//~ // pointers are found on the stack that very often a bunch of them will
//~ // refer to objects allocated at about the same time and that those objects
//~ // will tend to cluster in memory and hence within a modest number of Chunks.
//~ // After collecting all ambiguous values in that way I need to refine the
//~ // bitmaps so that they have a bit set for the header of each pinned item. I
//~ // have to perform a linear scan of each Chunk that contains pinned data.
//~ // For each object present I need to consult the bitmap to see if a bit is
//~ // set for some address within it. While doing so I will clear any bits
//~ // associated with non-header locations. This can be optimised by using
//~ // the fact that I can use word operations in the bitmap to check 32 or
//~ // 64 locations at at time. In the first version of the code I will not
//~ // do that optimizations - and ideally at a later stage I will measure to
//~ // see if it is liable to be useful.
//~ // HMMMM - later on I note that an ambiguous pointer must only lead to
//~ // pinning if it refers either within data allocated from the start of the
//~ // previous GC onwards. The procedure above copes for that provided the
//~ // pointer is within a newish Chunk. But one any Busy or MostlyFree page
//~ // there can also be Chunks left over by the previous GC just because they
//~ // used to contain pinned data. The regions within them that are not
//~ // actually pinned may contain the remains of old evacuated structure
//~ // and that must never be pinned. So my new plan is that when during GC
//~ // I have found the starts of every pinned item I form a list to record
//~ // that. At the start of the next GC when I identify the Chunk that an
//~ // address is within it it was a pinned chunk I will need to scan the
//~ // data from this list to see if I have a possible reference to something
//~ // that might be live.
//~ // For (2) I note that each Chunk that contains pinned material is also
//~ // liable to contain non-pinned stuff, and as I evacuate from fields in
//~ // pinned data I may move some of that non-pinned data. That leaves behind
//~ // forwarding pointers. Their presence would make a linear scan of the
//~ // Chunk less pleasant (although not impossible!) if I did it based on
//~ // parsing the data. But by virtue of having arranges that the bitmap only
//~ // has pinned bits for the heads of pinned items I can use it to help me
//~ // visit just the pinned material.
//~ // Now to issue (4). Allocating around a pinned item has overhead, and so
//~ // I for later storage allocation purposes I will view whole Chunks as
//~ // pinned. Well I can take a Chunk that contains pinned items within it and
//~ // truncate it so it starts with the first pinned item and ends with the last.
//~ // That is easy and avoids memory waste. However perhaps unexpectedly it has
//~ // a down-side. If pinned Chunks shrink then new Chunks can be allocated
//~ // near them. It in turn collects pinned data. Over time one can end up with
//~ // many small pinned regions. As well as being bad for allocation costs this
//~ // could give trouble with step (1) as explained above where a table of all
//~ // Chunks in a page is used. The fixed size for this table could not cope with
//~ // many many small pinned Chunks.
//~ // My proposed resolution adds two complications to the simple truncation
//~ // scheme. First, pinned chunk truncation is only performed if the Page
//~ // has at most 5 Chunks that contained pinned items (the number 5 is subject
//~ // to review!) and the Chunk table is made 5 entries larger than it might
//~ // otherwise have been. Secondly if two Chunks end up pinned and the gap
//~ // that would end up between them would be lower than the standard Chunk size
//~ // then those two are consolidated into one bigger Chunk. Well more than just
//~ // two Chunks may end up merged, leading to an especially large blocked
//~ // region in worst case behaviour. For a first implementation I will not
//~ // perform this truncation - it may in fact be a micro-optimisation that
//~ // would not improve things enough to be justified.
//~ //
//~
//~ // Overview of procedure for full garbage collection:
//~ //
//~ // I have Pages (8M) and Chunks (16K). Pinning is at a granularity of Chunks.
//~ //
//~ // First I will provide a reminder of the fields and data involved in
//~ // pinning things.
//~ //
//~ // When a page has pinned regions within it its chunkCount field will be
//~ // non-zero, because the pinned regions will be represented as Chunks.
//~ // When testing if an ambiguous pointer is pinned I will arrange that the
//~ // chunkMap be sorted so I can identify the Chunk that an address is within
//~ // using binary search.
//~ // A field chunkMapSorted is used to avoid too many repeat sorting steps.
//~ // Binary search of chunkMap lets me identify a candidate Chunk for an
//~ // ambiguous pointer and then pointsWithinChunk() tests if the address is within
//~ // the used data portion of that Chunk. If so an isPinned flag indicates
//~ // whether the Chunk is a pinned one and when it first becomes pinned it is
//~ // pushed on the page's pin chain list using its chunkPinChain field.
//~ // When the first Chunk on a Page is pinned the hasPinned flag in the
//~ // Page is set and the Page is pushed onto pagesPinChain through its
//~ // pagePinChain field.
//~ // Note that the process of pinning something never creates a new Chunk, so
//~ // the chunkMap just needs to be as established while allocation within the
//~ // Page was happening, and the it only needs sorting once at the start of
//~ // a GC.
//~ // When at some later stage it is necessary to allocate within a Page that
//~ // has some pinned Chunks the otherwise empty Page should end up with
//~ // a chunkMap that only mentions the pinned Chunks. This is all dealt with
//~ // in setupMostlyFreePage. the chunkMap is cleared and then re-created from
//~ // the list chunkPinChain. That may leave it is an arbitrary order, so it is
//~ // then sorted and with that done chunkPinChain can be re-created in ascending
//~ // order. Then fringe and limit are set up within the Page. limit will
//~ // point to the first pinned Chunk. That will have a length field indicating
//~ // where there is free space beyond it and a chunkPinChain entry that refers to
//~ // the start of the next pinned Chunk (and hence the end of the free region).
//~ //
//~ // Pages are classified as BUSY, MOSTLYFREE or FREE and have a pageClass
//~ // indicating which applies.
//~ //
//~ // Of the BUSY pages two will be specially identified - currentPage and
//~ // previousPage, but all busy pages will be chained on busyPages. While
//~ // the system is NOT in the garbage collector currentPage is where allocation
//~ // is proceeding. Its limit may refer to the start of a pinned Chunk within
//~ // it. As the GC is entered (and as it graduated to become previousPage)
//~ // every Chunk will have its chunkFringe filled in to show the limit of
//~ // valid material stored in it. This is in case the Chunk ends up pinned,
//~ // in which case all objects stored in it will need to be treated as precise
//~ // list bases - they are identified using a linear scan of the (active part
//~ // of) the Chunk. At an earlier stage I had planned to put padder objects
//~ // to full every chunk right up to the end, but by following the current
//~ // plan I can arrange that when a pinned chunk survives garbage collection
//~ // and ends up in a MostlyFree page it gets truncated down to its chunkFringe,
//~ // and that avoids a bit of memory waste.
//~ //
//~ // MOSTLYFREE pages are chained on mostlyFreePages while FREE ones are on
//~ // freePages.
//~ //
//~ // During early stages of Garbage Collection all BUSY pages and all MOSTLYFREE
//~ // ones will need their chunkMaps. Neither need any pagePinChain information.
//~ // At the time I sort the chunkMap (ie when I find the first pin in the
//~ // Page) I must reset the isPinned flag on all Chunks in that page and
//~ // chear the pagePinChain. Then while pinning a Chunk those two get updated.
//~ // The situation after that is that I end up with a list of the Pages that
//~ // contain pinned Chunks this time, and within each such Page I can identify
//~ // those Chunks easily.
//~ //
//~ // Now move busyPages to oldPages and set up a new CurrentPage. While
//~ // performing a major GC always allocate a MOSTLYFREE page rather than a
//~ // fully free one if possible. This is because doing to embeds the previously
//~ // pinned data among newly copies data. Much of it is liable NOT to be
//~ // pinned on the next garbage collection (because I hope that values on the
//~ // stack will have changed by then). So by doing that the stuff pinned by the
//~ // previous GC will have a chance to be fully recovered by the next one.
//~ //
//~ // Scan the stack (ie the "ambiguous bases") so that Chunks in OldPages and
//~ // MostlyFree that are accessible via that collection of values are marked
//~ // as pinned. Note that the only Chunks present in the MostlyFree pages will
//~ // be ones that has been pinned last time, and so things there that are
//~ // pinned now are "re-pinned".
//~ //
//~ // Hmm - there is a messy issue about my current plans - it is a worst-case
//~ // matter not one liable to occur in any normal use.
//~ // With my concurrent-allocation scheme there can be waste space due to
//~ // fragmentation when the code attempts to allocate a large object. Suppose
//~ // my target chunk-size is C and I first allocate single small item then
//~ // try to allocate something of size C. It will not fit and I will have to
//~ // allocate a fresh chunk. I have some lack of clarity in my mind about
//~ // the consequences of size-choice for the new chunk, but if it either JUST
//~ // fits the new object (and I then allocate yet another standard-sized new
//~ // chunk beyond it or it the new chunk is object-size+C I think we end up
//~ // with an occupancy of around 50%.
//~ // Now suppose that ordinary operation has by magic achieved perfect packing
//~ // but the GC (while copying into its new space) suffers worst-case
//~ // fragmentation. It gums up unless GC was triggered when total system
//~ // memory was (1/3) full. One can not afford to wait until it is (1/2) full.
//~ // With the scheme I have of Pages (8MB) and a limit I set at 2MB for any
//~ // individual object I can have only 75% of a page occupied when a big
//~ // vector will fail to fit at the end. That puts a limit at a bit over 42%
//~ // and that applies in the system I had before this re-written GC.
//~ // Well I now thing that if I put these together I spot that space wasted
//~ // at the end of the Page will lead to a nice big contiguous block at the
//~ // start of the next Page, and in the end my previous calculation that a
//~ // major GC needs to be triggered when memory is (1/3) full stands.
//~ //
//~ // For statistical and evaluation purposes at this stage it will be
//~ // interesting to see how many Pages contain pinned Chunks and both how
//~ // many Chunks are involved and what proportion of the Pages concerned they
//~ // use. That will be information I can gather before getting all the rest
//~ // of the GC working!
//~ //
//~ // Evacution:
//~ //   If the location to be evacuated holds immediate data do nothing,
//~ //     otherwise it holds a pointer to some object.
//~ //   If that object is to something in a MostlyFree page or one of the
//~ //     pages I am at present allocating in then it must be to something that
//~ //     had been pinned last time. So do nothing.
//~ //   Now it is points into an oldPage. I must check if it is in a
//~ //     pinned Chunk. Well at this stage I will have set things up so that
//~ //     the ONLY Chunks in the chunkMap of such a page are the [newly] pinned
//~ //     ones and I do not expoct there to be many, so binary search in the
//~ //     chunkMap should be quick. If into a pinned chunk it is left alone.
//~ //     That will be something that had been pinned both in a previous GC
//~ //     (and hence ended up mingled with live data) and pinned again this
//~ //     time.
//~ //   If the CAR field of the object holds a forwarding address use that to
//~ //     update the location to be a proper pointer to relocated data.
//~ //     The item pointed at will need to be inspected to reconstruct the
//~ //     proper tag bits for the adjusted reference. Done!
//~ //   Make a (binary) copy of the object in the next free space within C.
//~ //   Set the CAR field to be a forwarding address to the copy.
//~ //
//~ // Note that the copy will then (in due course) be scanned. For that to be
//~ // feasible the Pages where I allocate copied material (including pinned
//~ // Chunks embedded within them) must be such that I can perform a linear
//~ // scan, so chunkFringe must be set up where relevent.
//~ //
//~ // My first version of the major GC will run sequentially, however in the
//~ // future I hope to experiment with concurrency within it. So I will write
//~ // this as for a parallel implementation, although for that the details
//~ // above under "Evacuation" will need to be enhanced to allow for thread
//~ // interlocks.
//~ //
//~ // The GC has two parts. In one - seeding - the precise list bases are
//~ // evacuated. I will seed from all the static precise list bases (ie
//~ // variables and arrays in the C++ code) and also from each item present in
//~ // a pinned chunk.  This part is done in the master thread. I expect that the
//~ // total number of items processed will be reasonably modest, but in the
//~ // worst case there could be quite a lot of pinned material. An initial
//~ // evaluation suggests that in a fairly heavy case I may evacuate around
//~ // 100K items here - around (1/5) of a Page-full.
//~ // From then on I need to scan and evacuate all copied material. I do that
//~ // Chunk by Chunk, and when within a Page I find a Chunk tagged as with
//~ // isPinned I know it has already been processed. I hope to distribute
//~ // Chunks to different threads for processing, and then in the same way that
//~ // multiple threads can allocate during normal use, each GC thread will
//~ // have its own Chunk that it is copying material into.
//~ // Apart from the administration of thread start-up that is fairly clean and
//~ // easy! When any thread completes evacuating a chunk it needs to grab
//~ // another. That will usually happen using an atomic increment instruction
//~ // much as in storage allocation.
//~ // There is then a significant complication towards the end of GC. When
//~ // a thread completes filling up a chunk with evacuated data it will push
//~ // that chunk onto a needsEvacuating chain. When it completes clearing a
//~ // chunk then the cleared chunk can not be re-used yet. The thread tries
//~ // to grab another from needsEvacuating. That list may be empty, and in
//~ // that case it should start evacuating the Chunk it is currently evacuating
//~ // within. If it catches up with the fringe there it needs to wait until
//~ // a new chunk needs to be evacuated. Eventually every thread will be paused
//~ // on that basis: the evacuation phase of GC will be complete.
//~ // Well I talk cheerily there of a chain of chunks recently filled by the
//~ // evacuation process. In a single-thread world this does not need much
//~ // because Chunks can be scanned sequentially through Pages. The relevent
//~ // Pages will need to be chained but that is simple.
//~ // In a multi-thread world this is much much less nice! I will certainly
//~ // need a thread-safe process to identify the next sequential Chunk within
//~ // a page. Well this feels like the need for a "lock free pop" but it is
//~ // in the especially happy case that it traverses a chain that is not being
//~ // updated, so the mess of the ABA problem does not arise.
//~ // The uglier issue is that Chunks do not get completely filled sequentially,
//~ // and so one could have the sequential scan needing to skip past (several)
//~ // chunks that are in the process of being filled by other threads. A bad
//~ // case for this might be if one thread is processing a chunk that contains
//~ // references to very many rather large vectors - as it processes these it
//~ // need to allocate additional Chunks (that will need scanning later). A
//~ // different thread keeps performing a linear scan to find another Chunk
//~ // to process - and gets as far as the now-in-use Chunk and has to skip past
//~ // it. I think that means that a large number of Chunks could end up "left
//~ // behind". These need to be recorded on a chain and a lock-free stack seems
//~ // what is needed. Well if every completed Chunk is placed on this stack
//~ // then the linear scan of Chunks is not needed. Note that every Chunk
//~ // that is involved gets put on this stack just once and removed just once
//~ // (per GC) so the ABA issue does not arise and implementing the stack can
//~ // follow the recipe often characterised as "naive".
//~ // The final mess is that to select a Chunk to scan it will be necessary
//~ // to pop from the chain there and if that is empty to wait until either
//~ // another Chunk is made available by some other thread or until every
//~ // thread is also stalling.
//~ // At this stage in the explanation I can adjust something said before: I
//~ // need to seed from all pinned chunks. That can be done by just pushing
//~ // those chunks ono the stack that I have just described and then their
//~ // contents will be processed (potentially in a multi-threaded manner)
//~ // as part of the normal scheme of things.
//~
//~
//~
//~
//~ // Code for sorting "lists"...
//~
//~ // This is to sort some form of structure that is in abstract terms a list.
//~ // The "list" is passed and returned an an item of type Concrete. This might
//~ // but a type that is a pointer to a node object, or it could be "void*"
//~ // where implementation details are being hidden from other parts of the
//~ // code, or it might be "uintptr_t" and a handle for the start of the list.
//~ // Abstract then needs to be a class that provides a collection of static
//~ // methods to inspect and update the list. Because this sorts the list
//~ // in-place there is no need for any storage allocation. I will expect that
//~ // the Concrete type is small, so that creating an array of length 1000 will
//~ // not strain stack-size.
//~
//~ #include <algorithm>
//~
//~ template <typename Concrete, class Abstract>
//~ Concrete sortList(Concrete a)
//~ {   if (Abstract::isNil(a)) return a; // a trivial case
//~ // Count the length of the list.
//~     size_t n = 0;
//~     for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b)) n++;
//~ // If the list is short enough then I will copy the data to a simple
//~ // C++ array, use std::sort to get it in the right order and then patch
//~ // things back into list form.
//~     const size_t LIMIT = 1000;
//~     if (n < LIMIT)
//~     {   Concrete v[LIMIT];
//~         size_t i=0;
//~         for (Concrete b = a; !Abstract::isNil(b); b = Abstract::cdr(b))
//~             v[i++] = b;
//~         std::sort(&v[0], &v[n], Abstract::before);
//~         Concrete r = v[0];
//~         Concrete pr = r;
//~         for (i=1; i<n; i++)
//~         {   Abstract::rplacd(pr, v[i]);
//~             pr = v[i];
//~         }
//~         Abstract::rplacd(pr, Abstract::nil());
//~         return r;
//~     }
//~ // If I have too much data to be able to sort it all at once I will partition
//~ // into two lists, sort each and then merge. The partitioning does not need
//~ // to preserve ordering at all.
//~     Concrete l1 = Abstract::nil();
//~     Concrete l2 = Abstract::nil();
//~     while (!Abstract::isNil(a))
//~     {   Concrete w = a;
//~         a = Abstract::cdr(a);
//~         Abstract::rplacd(w, l1);
//~         l1 = w;
//~         if (!Abstract::isNil(a))
//~         {   w = a;
//~             a = Abstract::cdr(a);
//~             Abstract::rplacd(w, l2);
//~             l2 = w;
//~         }
//~     }
//~     l1 = sortList<Concrete,Abstract>(l1);
//~     l2 = sortList<Concrete,Abstract>(l2);
//~ // Now merge.
//~     Concrete r = Abstract::nil();
//~     Concrete rp = r;
//~     bool some = false;
//~     while (!Abstract::isNil(l1) &&
//~            !Abstract::isNil(l2))
//~     {   if (Abstract::before(l1, l2))
//~         {   Concrete w = l1;
//~             l1 = Abstract::cdr(l1);
//~             if (some)
//~             {   Abstract::rplacd(rp, w);
//~                 rp = w;
//~             }
//~             else
//~             {   r = rp = w;
//~                 some = true;
//~             }
//~         }
//~         else
//~         {   Concrete w = l2;
//~             l2 = Abstract::cdr(l2);
//~             if (some)
//~             {   Abstract::rplacd(rp, w);
//~                 rp = w;
//~             }
//~             else
//~             {   r = rp = w;
//~                 some = true;
//~             }
//~         }
//~     }
//~     if (Abstract::isNil(l1)) Abstract::rplacd(rp, l2);
//~     else Abstract::rplacd(rp, l1);
//~     return r;
//~ };
//~
//~ // Pages are chained via a "chain" field. I will want to
//~ // sort the list of mostlyFreePages based on their memory address.
//~
//~ class PageListClass
//~ {
//~ public:
//~     static Page* nil()
//~     {   return (Page*)0;
//~     }
//~     static bool isNil(Page* p)
//~     {   return p == (Page*)0;
//~     }
//~     static Page* cdr(Page* p)
//~     {   return p->chain;
//~     }
//~     static void rplacd(Page* p, Page* x)
//~     {   p->chain = x;
//~     }
//~     static bool before(Page* x, Page* y)
//~     {   return reinterpret_cast<uintptr_t>(x) < reinterpret_cast<uintptr_t>(y);
//~     }
//~ };
//~
//~ Page* sortPages(Page* p)
//~ {   return sortList<Page*, PageListClass>(p);
//~ }
//~
//~ // I will have a list of pinned items, with chaining through what would
//~ // normally be the CAR field and with chaining pointers using TAG_FORWARD.
//~ // I will want this sorted on the address value stored in the CDR field.
//~
//~ class PinChainClass
//~ {
//~ public:
//~     static uintptr_t nil()
//~     {   return TAG_FORWARD;
//~     }
//~     static bool isNil(uintptr_t p)
//~     {   return p == TAG_FORWARD;
//~     }
//~     static uintptr_t cdr(uintptr_t p)
//~     {   return ((uintptr_t*)(p-TAG_FORWARD))[0];
//~     }
//~     static void rplacd(uintptr_t p, uintptr_t x)
//~     {   ((uintptr_t*)(p-TAG_FORWARD))[0] = x;
//~     }
//~     static bool before(uintptr_t x, uintptr_t y)
//~     {   return ((uintptr_t*)(x-TAG_FORWARD))[1] <
//~                ((uintptr_t*)(y-TAG_FORWARD))[1];
//~     }
//~ };
//~
//~ uintptr_t sortPinList(uintptr_t l)
//~ {   return sortList<uintptr_t, PinChainClass>(l);
//~ }
//~
//~ bool gcComplete;
//~ Chunk* pendingChunks = nullptr;
//~ std::condition_variable cvForChunkStack;
//~ unsigned int activeHelpers = 0;
//~
//~ // I originally planned to make this a lock-free data structure, or at
//~ // lease code it so that it was lock-free most of the time. However I
//~ // will want to use a condition variable to deal with the issue of
//~ // whether the queue has any items in it at all, and that rather forces
//~ // the use of a mutex.
//~
//~ void pushChunk(Chunk* c)
//~ {   std::lock_guard<std::mutex> lock(mutexForGc);
//~     Chunk* old = pendingChunks;
//~ //# if (gcTrace) zprintf("Push %a onto queue [%a]\n", c, old);
//~     c->pendingChunks = old;
//~     pendingChunks = c;
//~ // If I put a new Chunk onto an otherwise empty queue then I will need to
//~ // wake up any threads that had been waiting for something to do.
//~     if (old == nullptr) cvForChunkStack.notify_all();
//~ }
//~
//~ Chunk* popChunk()
//~ {   std::unique_lock<std::mutex> lock(mutexForGc);
//~ // If I have to wait then while I am waiting I am not active...
//~     my_assert(activeHelpers != 0, "no activeHelpers available");
//~     activeHelpers--;
//~ #ifndef NO_THREADS
//~     bool st =
//~         cvForChunkStack.wait_until(lock,
//~             std::chrono::steady_clock::now() + cvTimeout,
//~             []{   return pendingChunks != nullptr ||
//~                          activeHelpers == 0;
//~               });
//~     if (!st) my_abort(LOCATION ": condition variable timed out");
//~ #endif // NO_THREADS
//~     Chunk* r = pendingChunks;
//~     if (r != nullptr)
//~     {   pendingChunks = r->pendingChunks;
//~ // If I manage to grab a chunk to work on I will then become active again.
//~         activeHelpers++;
//~     }
//~ // I can only return a nullptr here is activeHelpers is zero.
//~     return r;
//~ }
//~
//~ Chunk* nonblockingPopChunk()
//~ {   std::lock_guard<std::mutex> lock(mutexForGc);
//~ // This will grab a Chunk if one is available, but return nullptr if not.
//~ // If other threads are active one of them might be just abou to push another
//~ // Chunk, so getting a nullptr here is no a definitive indication that
//~ // ther is and will never be work to be done.
//~     Chunk* r = pendingChunks;
//~     if (r != nullptr) pendingChunks = r->pendingChunks;
//~     return r;
//~ }
//~
//~ // The short path through the code here is as for the main system, but
//~ // beyond allocation within a Chunk it takes a different path - which makes
//~ // sense because here I am already within the GC and so I never need to
//~ // bring all threads into struct synchronization to start one.
//~ //
//~ // I am still concerned about overheads in concurrency support, so the
//~ // plan at present is to maintain a pool of new standard sized
//~ // chunks in a little queue. Checking whether the queue is empty and
//~ // grabbing a chunk from it if not can be done using simple atomic operations
//~ // if the queue is implemented as a ring-buffer. If a thread either finds
//~ // that the queue is empty or that it is trying to grab space larger than
//~ // (say) 2/3 of the standard chunk size (and especially if it is allocating
//~ // something that would not fit at all in a standard Chunk) it enters a
//~ // critical region. That can do whatever global activity is required to
//~ // arrange space for some more Chunks including an oversized one. It will
//~ // (in a lock-free manner) top the queue up until it is full - (say) 16
//~ // Chunks. At this level the stack has reserved around 256K of memory.
//~ // If there have not been overlarge grabs that mess things up it will be
//~ // possible to unwind some of those allocations in the single thread code at
//~ // the end of GC, so there is no necessary loss. But at 1/4 Mbyte even if I
//~ // were to leave it wasted it is not a disaster!
//~ // The pointers used with the circular buffer are counting Chunks (which are
//~ // around 16Kbytes) so if on a 32-bit machine I used 32-bit uintptr_t values
//~ // those would overflow when 2^32 chunks has been used and given that each
//~ // GC can at worst be allocating from a half-space that would not happen until
//~ // over 30000 garbage collections had happened. That is not perfect headroom
//~ // but I will accept it - and on 64-bit machines there is no problem after
//~ // and imaginable amount of time.
//~
//~ const size_t gcQSize = 1u<<2; // 1u<<4;   // Must be a power of 2.
//~ const size_t gcQMask = gcQSize-1;
//~ uintptr_t    gcInQ(0);
//~ uintptr_t    gcOutQ(0);
//~ Chunk*       gcQ[gcQSize];
//~
//~ // This is a single producer multiple consumer queue, so the insert operation
//~ // needs to update data using sequentially consistent atomic operations so
//~ // that consumers notice, and so that data is in the queue ahead of the
//~ // pointer being incremented to indicate that. But it does not have to worry
//~ // about interlocks against other producers.
//~
//~ static void gcEnqueue(Chunk* c)
//~ {   uintptr_t in = gcInQ;
//~ //  if (gcTrace) zprintf("Grab another Chunk at %a\n", c);
//~     gcQ[in & gcQMask] = c;
//~     gcInQ = in+1;
//~ }
//~
//~ static Chunk* grabAnotherChunk(size_t size)
//~ {
//~ // Extra printing because I have a bug around here!
//~ //# Page* p = reinterpret_cast<Page*>(gFringe & -pageSize);
//~ //# zprintf("Page %a has %d chunks:", p, p->chunkCount);
//~ //# for (size_t i=0; i<p->chunkCount; i++)
//~ //#     zprintf(" %a", p->chunkMap[i]);
//~ //# zprintf("\n");
//~ //# if (p->chunkPinChain != nullptr) zprintf("\nPinned:");
//~ //# for (Chunk* c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~ //#     zprintf(" %a", c);
//~ //# if (p->chunkPinChain != nullptr) zprintf("\n");
//~ // This function is called within a critical region and so it does not
//~ // need to worry about synchronization issues!
//~     for (;;)
//~     {
//~ //#     zprintf("grabAnotherChunk gFringe=%a gLimit=%a\n", gFringe, gLimit);
//~ // (1) Use gFringe to gLimit is possible
//~         uintptr_t r = gFringe;
//~         uintptr_t l = r + size;
//~         if (l <= gLimit)
//~         {   gFringe = l;
//~             Chunk* c = reinterpret_cast<Chunk*>(r);
//~             c->length = size;
//~             c->isPinned = false;
//~             c->pinnedObjects = TAG_FIXNUM;
//~             c->chunkPinChain = nullptr;
//~             Page* p = reinterpret_cast<Page*>(r & -pageSize);
//~ //#         zprintf("@@@ Line 652 set chunk %d = %a len=%d\n", p->chunkCount, c, size);
//~             p->chunkMap[p->chunkCount++] = c;
//~             return c;
//~         }
//~ // (2) Skip pinned items if necessary
//~         uintptr_t pageEnd = ((r-1) & -pageSize) + pageSize;
//~         if (gLimit != pageEnd)
//~         {   Chunk* c = reinterpret_cast<Chunk*>(gLimit);
//~             gFringe = gLimit + c->length; // past the pinned Chunk
//~             gLimit = reinterpret_cast<uintptr_t>(
//~                          static_cast<Chunk*>(c->chunkPinChain));
//~             if (gLimit == 0) gLimit = pageEnd;
//~ //#         zprintf("Skipping existing pinned chunk\n");
//~             continue;
//~         }
//~ // (3) Allocate a totally new page if the above two strategies fail.
//~ //     This resets gFringe and gLimit. In a REALLY nasty case I might
//~ //     be trying to allocate a huge Chunk that is to store a huge vector,
//~ //     and the Page that I grab could be fragmented with loads of pinned
//~ //     data, so even this does not guarantee success! If circumstances like
//~ //     that lead to ultimate failure it is fatal.
//~         grabNewCurrentPage(withinMajorGarbageCollection);
//~     }
//~ }
//~
//~ static std::mutex grabNewSegments;
//~
//~ static Chunk* gcReserveMoreChunks(uintptr_t out)
//~ {   std::lock_guard<std::mutex> lock(grabNewSegments);
//~ // When I get here there can still be other threads running and incrementing
//~ // gcOutQ. My task is to insert chunks into the queue until it holds (about)
//~ // gcQSize.
//~ //# zprintf("Reserve several chunks for GC use\n");
//~     while (gcInQ < static_cast<uintptr_t>(gcOutQ) + gcQSize - 1)
//~     {   gcEnqueue(grabAnotherChunk(targetChunkSize));
//~     }
//~     return gcQ[out & gcQMask];
//~ }
//~
//~ static Chunk* gcDequeue()
//~ {   uintptr_t out = gcOutQ++;
//~     if (out < gcInQ) LIKELY return gcQ[out & gcQMask];
//~     UNLIKELY
//~     return gcReserveMoreChunks(out);
//~ }
//~
//~ thread_local Chunk* myBusyChunk = nullptr;
//~
//~ extern void testLayout();
//~
//~ LispObject gc_n_bytes1(size_t n, THREADFORMAL uintptr_t r)
//~ {   Chunk* newChunk;
//~     size_t nSize;
//~     my_assert(n < pageSize/2, "ridiculous size in gc_n_bytes");
//~     if (n <= (2*targetChunkSize)/3) LIKELY
//~     {   newChunk = gcDequeue();
//~         nSize = targetChunkSize;   // All Chunks on queue are standard size.
//~     }
//~     else
//~     UNLIKELY
//~     {   std::lock_guard<std::mutex> lock(grabNewSegments);
//~         newChunk = grabAnotherChunk(nSize = (targetChunkSize+n));
//~ //#     zprintf("newChunk = %a size %d\n", newChunk, targetChunkSize+n);
//~         while (gcInQ < static_cast<uintptr_t>(gcOutQ) + gcQSize - 1)
//~         {   gcEnqueue(grabAnotherChunk(targetChunkSize));
//~         }
//~     }
//~ // nSize is now the size of the next chunk.
//~ //# uintptr_t oldFringe = r;
//~ //  uintptr_t oldLimit = gLimit;
//~     uint64_t newLimit = reinterpret_cast<uintptr_t>(newChunk) + nSize;
//~     r = newChunk->dataStart();
//~     fringeBis = fringe = r + n;
//~ //    Page* p = reinterpret_cast<Page*>((oldFringe-1) & -pageSize);
//~     Chunk* justFilled = currentChunk;
//~     if (justFilled != nullptr &&
//~         justFilled != myBusyChunk) pushChunk(justFilled);
//~     currentChunk = newChunk;
//~ //# if (gcTrace)
//~ //#    zprintf("New Chunk at %a fringe = %a\n", newChunk, fringe);
//~     newChunk->length = nSize;
//~     newChunk->isPinned = false;
//~     newChunk->pinnedObjects = TAG_FIXNUM;
//~     newChunk->chunkPinChain = nullptr;
//~ //  zprintf("@@@ line 736 checkCount increased from %d for %a\n", p->chunkCount, newChunk);
//~ //  size_t chunkNo = p->chunkCount++;
//~ //  zprintf("Page %a gets chunkCount %d\n",  p, p->chunkCount);
//~ //  p->chunkMap[chunkNo] = newChunk;
//~     limitBis = newLimit;
//~     limit = newLimit;
//~     zprintf("!set limit = %a fringe = %a\n", limit, fringe);
//~ #ifdef DEBUG
//~     testLayout();
//~ #endif
//~ //# if (gcTrace) zprintf("gc_n_bytes1 = %a fringe = %a limit = %a\n",
//~ //#                      r, fringe, limit);
//~     return static_cast<LispObject>(r);
//~ }
//~
//~ inline LispObject gc_n_bytes(size_t n)
//~ {
//~ // First I have the code that will be executed if the allocation will
//~ // be possible within the current Chunk.
//~     THREADID;
//~ //# if (gcTrace) zprintf("gc_n_bytes %d with fringe = %a and limit = %a\n",
//~ //#                      n, fringe, limit);
//~     uintptr_t r = fringe;
//~     uintptr_t fr1 = r + n;
//~     uintptr_t w = limit;
//~     if (fr1 <= w) LIKELY
//~     {   fringe = fr1;
//~         if (gcTrace) zprintf("simple success at %a leaves fringe = %a "
//~                              "currentChunk = %a limit = %a\n",
//~                              r, fringe, currentChunk, limit);
//~ #ifdef DEBUG
//~         for (size_t i=0; i<n; i+=4)
//~            * reinterpret_cast<uint32_t*>(r+i) = 0xacebead5;
//~ #endif // DEBUG
//~         return static_cast<LispObject>(r);
//~     }
//~ // Now the case where a fresh Chunk has to be allocated.
//~     UNLIKELY
//~     Chunk* c = currentChunk;
//~ // If I am going to have to allocate a new Chunk and if there is actually
//~ // one in use at present then I need to record where the existing Chunk ends
//~ // and insert a padder to fill up to its end.
//~     if (c != nullptr)
//~     {   c->chunkFringe = r;
//~         size_t gap = w - r;
//~         if (gap != 0) setHeaderWord(r, gap);
//~     }
//~     LispObject r1 = gc_n_bytes1(n, THREADARG r);
//~ //# if (gcTrace) zprintf("complex success at %a\n", r1);
//~ #ifdef DEBUG
//~     for (size_t i=0; i<n; i+=4)
//~        *reinterpret_cast<uint32_t*>(r1+i) = 0x9decade9;
//~ #endif // DEBUG
//~     return r1;
//~ }
//~
//~ // Note that I define this guard once here and then also in newallocate.cpp.
//~ // By undefining it here I can activate the thread-safe code but still only
//~ // use one thread, and that will be a good thing to do to observe the overhead
//~ // that synchronization imposes. If that is not too bad and once the thread-
//~ // safe version is stable I can adjust newallocate.cpp and that would gate
//~ // more threads in to participare in GC - however until I put in extra
//~ // work somewhere to create those extra threads there are not any available
//~ // to help!
//~
//~ #define NO_EXTRA_GC_THREADS 1
//~
//~ #ifdef NO_EXTRA_GC_THREADS
//~
//~ // The version here is for single-threaded use only, however my intent is
//~ // to gradually start adding in the framework for a parallel version. As I
//~ // do so I am going to make an assumption that I hope will be valid in all
//~ // the cases that I come across, but which is clearly improper as far as C++
//~ // is concerned. That is that when I access an atomic<T> the memory layout
//~ // involved and the data representation in that memory will be exactly
//~ // as for something of type just plain T. I expect that the only difference
//~ // will be that in the atomic case the compiler takes any extra trouble it
//~ // needs to to ensure that updates happen either completely or not at all,
//~ // and that multi-processor issues are addressed in the sense of memory
//~ // fences etc. This assumption is going to violate strict aliasing rules and
//~ // so a sufficiently clever compiler could spot what I was doing and mangle
//~ // my code quite grievously!
//~
//~ bool isPinned(uintptr_t a);
//~
//~ extern void validateAsLive(LispObject a);
//~
//~ static uintptr_t evaccount = 0;
//~
//~ void evacuate(LispObject &a)
//~ {
//~     zprintf("[%d]", ++evaccount);    // to track count of calls to evacuate
//~     if (evaccount >= 4970)
//~     {   rawHeap("starting to evacuate something");
//~         zprintf("evacuating %a\n", a);
//~     }
//~ #ifdef DEBUG
//~ // I am silent on NIL because otherwise I am overall too noisy.
//~ //# if (a!=nil && !is_immediate(a))
//~ //#    if (gcTrace) zprintf("evacuating %a\n", a);
//~ #endif
//~ // Here a is a pointer to a location that is a list-base, ie it contains
//~ // a valid Lisp object. I want to arrange that the object and all its
//~ // components are moved to the new half space, and (if necessary) the
//~ // list base is updated to refer to the copy and a forwarding pointer is left
//~ // where the original had been. The procedure is:
//~ //   a is the object that may need to be copied.
//~ //   If a is tagged as immediate data do nothing.
//~ //   [now a is some sort of tagged pointer]
//~ //   If *a is a forwarding pointer replace the list base with the
//~ //      object referred to, reconstructing suitable tag bits.
//~ //   If the address that a refers to is in the free half-space it must be
//~ //      a pointer to an object that had been pinned last time, so do nothing.
//~ //   Determine the length, b, of the object that a refers to.
//~ //   Allocate b byte in the new space and do a simple binary copy of all
//~ //      of object a to there.
//~ //   Write in a forwarding pointer.
//~ //   Update the list-base to refer to the copy.
//~ // Note that this is a shallow copy operation. A later stage must perform
//~ // a linear scan of the newly copied material. That stage is not discussed
//~ // here because this function does not directly cause it to happen.
//~ //
//~     if (a == 0) zprintf("EEk %a : %a\n", &a, a);
//~     my_assert(a != 0, "zero word in scanning");
//~     if (is_forward(a)) zprintf("EEk %a : %a\n", &a, a);
//~     my_assert(!is_forward(a), "forwarding ptr in scanning");
//~     if (is_immediate(a) || a == nil)
//~     {
//~ //#ifdef DEBUG
//~ //        if (a != nil)
//~ //            if (gcTrace) zprintf("immediate data: easy %a\n", a);
//~ //#endif // DEBUG
//~         return;
//~     }
//~     if (currentChunk != nullptr)
//~         currentChunk->chunkFringe = fringe;
//~     validateAsLive(a);
//~     if (isPinned(a))
//~     {   if (gcTrace)
//~         {   //# zprintf("precise ptr to pinned %a\n", a);
//~             //# zprintf("pinned item is ");
//~             //# simple_print(a);
//~             //# zprintf("@ %x in page %x\n", a, a & -pageSize);
//~         }
//~         zprintf("~~Reference to pinned item %a preserved\n", a);
//~         return;
//~     }
//~     LispObject* ap = reinterpret_cast<LispObject*>(a & ~TAG_BITS);
//~     LispObject aa = *ap;
//~ //# if (gcTrace) zprintf("item is %a [not immediate] contents of that is %a\n",
//~ //#                      a, aa);
//~     if (is_forward(aa))
//~     {   zprintf("~~re-visit %a which is now at %a\n", a, aa-TAG_FORWARD+(a&TAG_BITS));
//~         static int count = 0;
//~         if (count++ > 1000000) my_abort("too many re-visits");
//~         a = aa - TAG_FORWARD + (a & TAG_BITS);
//~ #ifdef DEBUG
//~ //#     if (gcTrace) zprintf("Process forwarding address\n");
//~ #endif // DEBUG
//~         return;
//~     }
//~ // Now I will need to make a copy of the item.
//~     size_t len;
//~ // Finding its length is not too hard here because I have a validly tagged
//~ // pointer to it.
//~     if (is_cons(a)) len = 2*CELL;
//~     else if (is_symbol(a)) len = symhdr_length;
//~     else len = length_of_header(aa);
//~ #ifdef DEBUG
//~ //# if (gcTrace) zprintf("about to allocate space for %d bytes\n", len);
//~ #endif // DEBUG
//~ // Note that gc_n_bytes() is uesd to allocate the amount of space I need
//~ // but the header information for the copied object is transferred later
//~ // so if the object is a string or a vector on a 32-bit platform with
//~ // an unused final word there will not be a problem here/
//~     aa = gc_n_bytes(doubleword_align_up(len));
//~ #ifdef DEBUG
//~ //# if (gcTrace) zprintf( "@ %a\n", aa);
//~ #endif // DEBUG
//~     zprintf("~~copy item from %a at %a to new space at %a\n", &a, a, aa);
//~     zprintf("~~fringe now %a\n", fringe);
//~     if (is_symbol(a))
//~     {   zprintf("~~~%a: Sym value %x : %a\n", a, qvalue(a), qvalue(a));
//~         zprintf("~~~ Sym pname %x : %a\n", qpname(a), qpname(a));
//~         zprintf("~~~ Sym plist %x : %a\n", qplist(a), qplist(a));
//~         zprintf("~~~ Sym env   %x : %a\n", qenv(a),   qenv(a));
//~     }
//~     else for (size_t i=0; i<len; i+=CELL)
//~         zprintf("~~~%a: %x : %a\n", &ap[i/CELL], ap[i/CELL], ap[i/CELL]);
//~ // I will copy the full final doubleword of a vector, and in the case of
//~ // a 32-bit machine or for vectors that contain components that are smaller
//~ // than CELL this will include material beyond that which is meaningful.
//~ // This at least keeps any zero-padding of the last word intact.
//~     std::memcpy(reinterpret_cast<void*>(aa), ap, doubleword_align_up(len));
//~     *ap = TAG_FORWARD + aa;
//~     zprintf("~! set %a to forward to %a\n", a, *ap);
//~     a = aa + (a & TAG_BITS);
//~ }
//~
//~ #else // NO_EXTRA_GC_THREADS
//~
//~ // Here is where I will work on a version that is thread-safe! Just for now
//~ // it is a direct copy of the unsafe code...
//~
//~ void evacuate(LispObject* p)
//~ {
//~ #error This need to be made thread-safe! And then debugged.
//~
//~ // Here p is a pointer to a location that is a list-base, ie it contains
//~ // a valid Lisp object. I want to arrange that the object and all its
//~ // components are moved to the new half space, and (if necessary) the
//~ // list base is updated to refer to the copy and a forwarding pointer is left
//~ // where the original had been. The procedure is:
//~ //   Let a = *p, ie the object that may need to be copied.
//~ //   If a is tagged as immediate data do nothing.
//~ //   [now a is some sort of tagged pointer]
//~ //   If* a is a forwarding pointer replace the list base with the
//~ //      object referred to, reconstructing suitable tag bits.
//~ //   If the address that a refers to is in the free half-space it must be
//~ //      a pointer to an object that had been pinned last time, so do nothing.
//~ //   Determine the length, b, of the object that a refers to.
//~ //   Allocate b byte in the new space and do a simple binary copy of all
//~ //      of object a to there.
//~ //   Write in a forwarding pointer.
//~ //   Update the list-base to refer to the copy.
//~ // Note that this is a shallow copy operation. A later stage must perform
//~ // a linear scan of the newly copied material. That stage is not discussed
//~ // here because this function does not directly cause it to happen.
//~ //
//~     LispObject a = *p;
//~     if (is_odds(a) || is_immediate_num(a) || a == nil) return;
//~     LispObject* ap = reinterpret_cast<LispObject*>(a & ~TAG_BITS);
//~     LispObject aa = *ap;
//~     if (is_forward(aa))
//~     {  * p = aa - TAG_FORWARD + (a&TAG_BITS);
//~         return;
//~     }
//~ // Now I will need to make a copy of the item.
//~     size_t len;
//~ // Finding its length is not too hard here because I have a validly tagged
//~ // pointer to it.
//~     if (is_cons(a)) len = 2*CELL;
//~     else if (is_symbol(a)) len = symhdr_length;
//~     else len = doubleword_align_up(length_of_header(aa));
//~     aa = gc_n_bytes(len);
//~     std::memcpy(reinterpret_cast<void*>(aa), ap, len);
//~    * ap = TAG_FORWARD + aa;
//~    * p = aa + (a&TAG_BITS);
//~ }
//~
//~ #endif // NO_EXTRA_GC_THREADS
//~
//~ bool withinMajorGarbageCollection = false;
//~ size_t pinnedChunkCount = 0, pinnedPageCount = 0;
//~
//~ void prepareForGarbageCollection(bool major)
//~ {   //# if (gcTrace) zprintf("prepareForGarbageCollection\n");
//~     if (major)
//~     {   withinMajorGarbageCollection = true;
//~         oldPages = busyPages;
//~         for (Page* p = oldPages; p!=nullptr; p=p->chain)
//~             p->type = oldPage;
//~         oldPagesCount = busyPagesCount;
//~         busyPages = nullptr;
//~         busyPagesCount = 0;
//~     }
//~     else
//~     {   withinMajorGarbageCollection = false;
//~         zprintf("prepare for minor GC not coded yet\n");
//~         Lstop(nil);
//~     }
//~ }
//~
//~ void setupNewHalfspace()
//~ {
//~ // Having moved all the busy pages to oldPages I can set up a fresh
//~ // current page to be the start of the "new half-space" that I will
//~ // copy things into.
//~     grabNewCurrentPage(true);  // sets up a starter Chunk.
//~     pinnedChunkCount = pinnedPageCount = 0;
//~ // I will want pendingChunks empty basically all the time because that
//~ // can be the main guard blocking GC threads from trying to run when I do
//~ // not want them to!
//~     pendingChunks = nullptr;
//~ // The next bit is really rather a cheat. It "allocates zero bytes" but
//~ // but diving into the allocation code beyond the initial test for easy cases
//~ // it will allocate a fresh Chunk. I set myBusyChunk so that the allocation
//~ // of the new Chunk does not mark the existing one as needing scanning.
//~     THREADID;
//~     myBusyChunk = currentChunk;
//~     if (myBusyChunk != nullptr)
//~         myBusyChunk->chunkFringe = static_cast<uintptr_t>(fringe);
//~     currentChunk = myBusyChunk = nullptr;
//~ //    fringe = limit;
//~     gcInQ = gcOutQ = 0;
//~ //    gc_n_bytes1(0, THREADARG fringe);
//~ }
//~
//~ // These are the fields in Pages and Chunks that have some relevance to
//~ // pinning...
//~ // ::pagesPinChain
//~ // Page:
//~ //   chain
//~ //   type
//~ //   hasPinned
//~ //   pagePinChain
//~ //   chunkPinChain
//~ //   chunkCount
//~ //   chunkMap[]
//~ //   chunkMapSorted
//~ //   pinnedMap[]
//~ // Chunk:
//~ //   isPinned
//~ //   pinnedObjects
//~ //   chunkPinChain
//~ //   chunkFringe
//~ //
//~
//~ // During GC a lot of pin information needs to be updated. This happens
//~ // in a sequence of operations
//~ //
//~ // (1) Start GC
//~ //   use pagesPinChain and Page::pagePinChain to scan all pages that have
//~ //   any pinned chunks in them.
//~ //     Clear pinnedMap[]
//~ //     (note do not clear Page::hasPinned because that records that
//~ //      the page is in pagesPinChain)
//~ //   use Page::chunkPinChain and Chunk::chunkPinChain to visit every
//~ //   pinned Chunk.
//~ //     clear Chunk::isPinned
//~ // Note that this preserved the chain of Pages that contain pinned Chunks
//~ // and the chains of the pinned Chunks within them.
//~ //
//~ // (2) Scan for pinned items, but perhaps spot refs into middle of objects
//~ //   Given a pointer into a Page, use chunkMap[] (and chunkMapSorted) to
//~ //   identify a Chunk. There are then two cases. If the Chunk has
//~ //   a non-empty pinnedObjects then this must be a part of memory that
//~ //   was pinned by the last GC. Then a reference within it is only valid
//~ //   if it is to an object on that list. If that situation arises the
//~ //   Chunk gets isPinned set.
//~ //   If the pinnedObjects list is empty the reference is only valid of the
//~ //   Chunk is in a Page that is busy and the pointer is below chunkFringe.
//~ //   Again isPinned gets set and if necessary the Chunk is put on
//~ //   a chunkPinChain and if this is the first in a Page then pagePinChain
//~ //   and Page::hasPinned get updated.
//~ //
//~ //   Now we have a list of Pages that have some pinned Chunks, Each has a
//~ //   chain of those Chunks and a bitmap with a bit set for at least one
//~ //   doubleword within each item that must end up pinned. Some of the
//~ //   pinned Chunks will have isPinned set but some may not.
//~ //
//~ // (3) Create new half-space to copy data into
//~ //   The new half-space may use some Pages that contain existing pinned
//~ //   data, and at the stage that I create new Chunks within them to
//~ //   allocate their chunkMap[] data will change. I delayed this step
//~ //   until now so I could be certain that chunkMap[] was in a simple
//~ //   state while I looked for pinned things.
//~ //
//~ // (4) Identify header words of pinned items
//~ //   Scan all Pages using pagesPinChain and for each all the chunks in
//~ //   the associated chunkPinChain. If the chunk already has pinnedObjects
//~ //   then do A else do B.
//~ //   A: scan pinnedObjects and if there are pinned bits associated with
//~ //      objects move those to refer to the object header.
//~ //      Copy the pinnedObjects information so that it is in the new
//~ //      half-space. Note that some items on the chain may not be pinned.
//~ //      That can happen when they were in fact pinned during the previous
//~ //      GC but are not any more. They may or may not be alive based on
//~ //      precise pointers. Ensure bitmap only set on headers. In this
//~ //      situation the Chunk::isPinned flag should remain clear.
//~ //   B: linear scan up to chunkFringe checking the bitmap, and ensure
//~ //      bitmap just identifies headers - build a new pinnedObjects chain.
//~ //      Chunk::isPinned will have been set.
//~ //
//~ // (5) evacuate contents of pinned items
//~ //   We wait until step (4) is complete rather than overlapping things
//~ //   because the evacuate() operation wants any pinned items to have the
//~ //   pin bit set on their head rather than part way down. But we scan all
//~ //   the newly created pinnedObjects chains. Each item in such a chain
//~ //   identifies the starting address in memory of a pinned object. By
//~ //   inspecting the first word there it will be possible to tell whether
//~ //   it is a symbol, vector or cons cell. All its fields are then precise
//~ //   values that can be processed.
//~ //
//~ // (6) evacuate everything else
//~ //   The "everything else" will be the Lisp stack, Lisp bases and then
//~ //   the sub-fields of copied data. Almost all of the work in GC will
//~ //   happen here.
//~ //
//~ // (7) restructure heap to be ready for normal use, with old space
//~ //     re-labeled as free.
//~ //   Now a step that in my earlier drafts I had not recognised the need
//~ //   for. I work through all Pages that have pinned Chunks and inspect
//~ //   each such Chunk. All those Chunks will have a non-empty pinnedObjects
//~ //   list. I scan that list and remove from it any entry to a location that
//~ //   does not have its pin bit set. If that leaves the pinnedObject list
//~ //   empty then the Chunk can be removed from then pinnedChunks list
//~ //   associated with its Page. If that list becomes empty the Page can
//~ //   be removed from the chain of pages that contain pinned data. This is
//~ //   the step where something that had historically been pinned ends up
//~ //   rehabilitated. Note that this must be done at the very end of GC so
//~ //   that any data that has been within those historically pinned Chunks
//~ //   has had time to be moved out before there is any chance of allocation
//~ //   within the Page recycling the Chunk.
//~ //   Now all pages in the "old half-space" can be declared available
//~ //   for re-use. Note that some Pages in pagePinChain will be busy and
//~ //   some free, so I can not conflate this list with the ones that
//~ //   track which Pages I will allocate next. When I allocate a mostlyFree
//~ //   page I should however try to grab one that has been in that state
//~ //   for as long as possible because that should improve the changes that
//~ //   an internediate GC will have a chance to promote such pages to Free.
//~
//~
//~ void clearPinnedInformation(bool major)
//~ {   //# if (gcTrace) zprintf("clearPinnedInformation\n");
//~     for (Page* p = pagesPinChain; p!=nullptr; p=p->pagePinChain)
//~     {   std::memset(p->pinnedMap, 0, sizeof(p->pinnedMap));
//~         static int count = 0;
//~         if (count++ > 1000000) my_abort("too many pinned pages");
//~         for (Chunk* c = p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~             c->isPinned = false;
//~     }
//~ }
//~
//~ // The version of IsPinned here requires its argument to be a valid
//~ // LispObject that is not immediate data. Or at least the word address
//~ // of a valid object. It it was a value that amounted to an illegal
//~ // memory address there would be trouble.
//~
//~ bool isPinned(uintptr_t a)
//~ {   Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~     uintptr_t o = (a & (pageSize-1))/8;
//~     uintptr_t mask = static_cast<uintptr_t>(1) <<
//~                      (o&(8*sizeof(uintptr_t)-1));
//~     uintptr_t word = p->pinnedMap[o/(8*sizeof(uintptr_t))];
//~     return (word & mask) != 0;
//~ }
//~
//~ void setPinned(uintptr_t a)
//~ {   Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~     uintptr_t o = (a & (pageSize-1))/8;
//~     uintptr_t mask = static_cast<uintptr_t>(1) <<
//~                      (o&(8*sizeof(uintptr_t)-1));
//~     p->pinnedMap[o/(8*sizeof(uintptr_t))] |= mask;
//~ //# zprintf("setPinned %x %a\n", a, a);
//~ }
//~
//~ void setPinned(Page* p, uintptr_t a)
//~ {   uintptr_t o = (a & (pageSize-1))/8;
//~     uintptr_t mask = static_cast<uintptr_t>(1) <<
//~                      (o&(8*sizeof(uintptr_t)-1));
//~     p->pinnedMap[o/(8*sizeof(uintptr_t))] |= mask;
//~ //# zprintf("setPinned %x %a\n", a, a);
//~ }
//~
//~ void clearPinned(uintptr_t a)
//~ {   Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~     uintptr_t o = (a & (pageSize-1))/8;
//~     uintptr_t mask = static_cast<uintptr_t>(1) <<
//~                      (o&(8*sizeof(uintptr_t)-1));
//~     p->pinnedMap[o/(8*sizeof(uintptr_t))] &= ~mask;
//~ }
//~
//~ void clearPinned(Page* p, uintptr_t a)
//~ {   uintptr_t o = (a & (pageSize-1))/8;
//~     uintptr_t mask = static_cast<uintptr_t>(1) <<
//~                      (o&(8*sizeof(uintptr_t)-1));
//~     p->pinnedMap[o/(8*sizeof(uintptr_t))] &= ~mask;
//~ }
//~
//~ void evacuateFromUnambiguousBases(bool major)
//~ {   //# if (gcTrace) zprintf("evacuateFromUnambiguousBases\n");
//~ // This code has to know where ALL the definitive references to LispObjects
//~ // are in the C++ code. The main way it achieves this is through a vector
//~ // "list_bases" that holds the address of every static location involved.
//~ // That vector is about 200 items long. In addition the dedicated Lisp
//~ // stack has to be processed.
//~     evacuate(qvalue(nil));
//~     evacuate(qenv(nil));
//~     evacuate(qplist(nil));
//~     evacuate(qpname(nil));
//~     evacuate(qfastgets(nil));
//~     evacuate(qpackage(nil));
//~     for (auto p = list_bases;* p!=nullptr; p++) evacuate(**p);
//~     THREADID;
//~     for (LispObject* sp=stack;
//~          sp>reinterpret_cast<LispObject*>(stackBase); sp--) evacuate(*sp);
//~ // When running the deserialization code I keep references to multiply-
//~ // used items in repeat_heap, and if garbage collection occurs they must be
//~ // updated.
//~     if (repeat_heap != nullptr)
//~     {   for (size_t i=1; i<=repeat_count; i++)
//~             evacuate(repeat_heap[i]);
//~     }
//~ }
//~
//~ // Evacuate every pinned item in the Chunk. Hah my first version of this
//~ // had performed a linear scan noting where pin-bits identified the head
//~ // of special items. However a better scheme can be based on the fact
//~ // that findHeadersOfPinnedItems() has alread done that scan and has
//~ // set up a list of the items that have to be processed. There is a
//~ // slight pain in that the list gives untagged addresses, so I need to
//~ // do a bit of inspection to understand the types of the objects concerned.
//~
//~ void evacuatePinnedInChunk(Chunk* c)
//~ {   c->evacuated = true;
//~     for (LispObject ch=c->pinnedObjects;
//~                        ch!=TAG_FIXNUM;
//~                        ch=cdr(ch&~TAG_BITS))
//~     {   LispObject p = car(ch&~TAG_BITS)&~TAG_BITS;
//~         Header h = *reinterpret_cast<Header*>(p);
//~         size_t len, len1;
//~ // Now based on the low 6 bits of the first word of the object I sort
//~ // out whether it is a vector containing Lisp data, a vector containing
//~ // binary data (including strings and bignums) or a symbol. If none of
//~ // those then it will be a CONS cell.
//~         switch (h & 0x1f)
//~         {
//~         case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
//~                                  // Note TYPE_STREAM etc is in with this.
//~             len = length_of_header(h);
//~             if (is_mixed_header(h))
//~                 len1 = 4*CELL;
//~             else len1 = len;
//~             my_assert(len != 0, "lisp vector size zero");
//~             for (size_t i = CELL; i<len1; i += CELL)
//~                 evacuate(*reinterpret_cast<LispObject*>(p+i));
//~             continue;
//~
//~         case 0x12: // 0b10010:   // Header for bit-vector
//~         case 0x1a: // 0b11010:   // Header for vector holding binary data
//~             continue;
//~
//~         case 0x02: // 0b00010:   // Symbol headers plus char literals etc
//~             if (is_symbol_header(h))
//~             {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(p);
//~                 evacuate(s->value);
//~                 evacuate(s->env);
//~                 evacuate(s->plist);
//~                 evacuate(s->fastgets);
//~                 evacuate(s->package);
//~                 evacuate(s->pname);
//~                 continue;
//~             }
//~             // drop through on character literals etc.
//~         default:                 // None of the above cases...
//~             evacuate(car(p));
//~             evacuate(cdr(p));
//~             continue;
//~         }
//~     }
//~ }
//~
//~ void evacuateFromPinnedItems(bool major)
//~ {   //# if (gcTrace) zprintf("evacuateFromPinnedItems\n");
//~     for (Page* p=pagesPinChain; p!=nullptr; p=p->pagePinChain)
//~     {   static int count = 0;
//~         if (count++ > 1000000) my_abort("too many pinned pages");
//~         for (Chunk* c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~         {   //# if (gcTrace) zprintf("Pinned items in %a to evacuate\n", c);;
//~             evacuatePinnedInChunk(c);
//~         }
//~     }
//~ }
//~
//~ // This next will be relevant with a generational GC. It needs to deal with
//~ // up-pointers that have been introduced by RPLACx style operations.
//~
//~ void evacuateFromDirty()
//~ {   zprintf("evacuateFromDirty\n");
//~     Lstop(nil);
//~ }
//~
//~ // Here are the states that a Chunk can be in:
//~ //
//~ // (1) | header | raw data                       | waste |
//~ // (2) | header | evacuated data | raw data      | waste |
//~ // (3) | header | evacuated data                 | waste |
//~ // (4) | header | raw data | free space                  |
//~ // (5) | header | evacuated data | raw data | free space |
//~ // (6) | header | evacuated data | free space            |
//~ //
//~
//~ //
//~ // There can be multiple GC threads. Overall coordination is through
//~ // an atomic uintptr_t where its value is treated with the low few bits
//~ // being a count of the number of GC threads that are still busy and bits
//~ // above that a count of the un-processed Chunks on the Chunk Queue
//~ // waiting to be scanned. This value is used with a condition variable
//~ // such that threads can wait until EITHER another Chunk is placed on
//~ // the queue OR until the magic counter is zero.
//~ // All threads are signalled either when a Chunk is queued or when a
//~ // thread becomes idle and decreases the count such that it ends up zero.
//~ //
//~ // The early stages of GC run using just one thread and that evacuates
//~ // from list bases. If while doing so it fills one or nor chunks those
//~ // are queued for later processing and the count is suitably updated.
//~ // Meanwhile all other threads are waiting for such a Chunk to scan.
//~ //
//~ // The general policy then is that each thread starts by trying to tidy up
//~ // everything in the Chunk it is currently writing to. If it "catches up"
//~ // there it will grab further Chunks from the queue for as long as it can and
//~ // scan each of those. In general that will copy more information into its
//~ // own space, and it may or may not cause allocation of further Chunks.
//~ // If the queue appears to be empty (which may be a transient situation if
//~ // other threads happen to be busy scanning blocks that are in fact mostly
//~ // full of immediate data or material that has already been coped) the thread
//~ // returns to work on whatever is had been its own output Chunk, and after
//~ // that whatever has become that.
//~
//~
//~ extern void gcHelper();
//~
//~ void evacuateFromCopiedData(bool major)
//~ {   //# if (gcTrace) zprintf("evacuateFromCopiedData\n");
//~ // This is gcHelper being called from the GC driver thread.
//~     gcHelper();
//~ }
//~
//~ void evacuateOneChunk(Chunk* c)
//~ {   c->evacuated = true;
//~     uintptr_t p = c->dataStart();
//~     while (p < c->chunkFringe)
//~     {   LispObject* pp = reinterpret_cast<LispObject*>(p);
//~ // The first word of an object may be one of several possibilities:
//~ //    Header for vector holding binary data;
//~ //    Header for vector holding Lisp data;
//~ //    Header for object with 3 lisp items then binary stuff;
//~ //    Header for symbol;
//~ //    anything else (item is a cons cell).
//~         LispObject a = *pp;
//~         size_t len, len1;
//~         switch (a & 0x1f) // tag bits plus 2 more
//~         {
//~ // binary literals are C++14, so just for now I will use hex, but I will
//~ // write what the binary literal would be...
//~         case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
//~                                  // Note TYPE_STREAM etc is in with this.
//~             len = doubleword_align_up(length_of_header(a));
//~             if (is_mixed_header(a)) len1 = 4*CELL;
//~             else len1 = len;
//~             for (size_t i = CELL; i<len1; i += CELL)
//~                 evacuate(*reinterpret_cast<LispObject*>(p+i));
//~             p += len;
//~             continue;
//~
//~         case 0x12: // 0b10010:   // Header for bit-vector
//~             len = doubleword_align_up(length_of_header(a));
//~             p += len;
//~             continue;
//~
//~         case 0x1a: // 0b11010:   // Header for vector holding binary data
//~             len = doubleword_align_up(length_of_header(a));
//~             p += len;
//~             continue;
//~         case 0x02: // 0b00010:   // Symbol headers plus char literals etc
//~             if (is_symbol_header(a))
//~             {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(p);
//~                 evacuate(s->value);
//~                 evacuate(s->env);
//~ //#             zprintf("%a has plist %a\n", s, s->plist); // @@@
//~                 evacuate(s->plist);
//~                 evacuate(s->fastgets);
//~                 evacuate(s->package);
//~                 evacuate(s->pname);
//~                 p += symhdr_length;
//~                 continue;
//~             }
//~             // drop through.
//~         default:                 // None of the above cases...
//~                                  // ... must be a CONS cell.
//~             evacuate(pp[0]);
//~             evacuate(pp[1]);
//~             p += 2*CELL;
//~             continue;
//~         }
//~     }
//~ }
//~
//~ void evacuatePartOfMyOwnChunk()
//~ {
//~ // This is the core of the copying GC. It starts by identifying the Chunk
//~ // that its thread is allocating within.
//~ // The steps are:
//~ // (1) The "busy Chunk" will start off in state (4) - ie it will have some
//~ // data within it (well a degenerate case is that there is in fact no data,
//~ // but that is not a problem) and it also has some free space at the end. I
//~ // know the latter because it is the Chunk I am allocating into and if it
//~ // was full I would have moved on. I guess that a further minor special case
//~ // is if there is no such Chunk yet - in which case I just allocate one and
//~ // it will start off empty.
//~ // (2) The code here points myBusyChunk at that Chunk. That is needed
//~ // so that when (and if!) allocation fills up that Chunk it will not be
//~ // enqueued for other threads to scan. It also sets a pointer to the start
//~ // of data within the Chunk.
//~ // (3) Data within the Chunk is scanned. Where there are old pointers in it
//~ // those are "evacuated". Doing this may involve creating copies of lists.
//~ // These copies may (or may not) fill up the Chunk - when it is filled a
//~ // new one gets allocated. If scanning leads to creation of second or
//~ // subsequent Chunks then the full ones get enqueued. The scan can terminate
//~ // in one of two manners. (a) the Chunk may not become full but all data in
//~ // it has been inspected or (b) the Chunk may have become full in which
//~ // case scanning terminates at its end.
//~ // (4) In a non-blocking mode the code attempts to obtain a Chunk to work on.
//~ // While that succeeds it scans/evacuates contents. It only continues from
//~ // this step if there seems to be no data available.
//~ // (5) If more copying had occured then return to step (3), resetting
//~ // myActiveChunk to wherever allocation is now active. This will commonly
//~ // happen if (4) had found more Chunks to scan, and it is easily noticed
//~ // by checking if fringe has changed.
//~ // (6) If scanning stopped for lack of data (local or from the queue) the
//~ // thread must make a blocking request from the Chunk queue (well in fact
//~ // it is run as a stack). This can either return more memory to be scanned
//~ // and this is treated as if it had been found at step (4). Or it can
//~ // report that no more will ever become available, in which case we are
//~ // finished.
//~     THREADID;
//~     for (;;)
//~     {
//~ // myBusyChunk is set here so because the Chunk being worked on is
//~ // simultaneously one that has some copied but not cleaned up material in
//~ // it AND the one in which this thread will be placing any further
//~ // copied material.
//~         myBusyChunk = currentChunk;
//~         myBusyChunk->evacuated = true;
//~         uintptr_t p = myBusyChunk->dataStart();
//~         if (gcTrace) zprintf("Start of data in my Chunk is at %a\n", p);
//~         if (gcTrace) zprintf("fringe = %a\n", fringe);
//~         for (;;)
//~         {
//~             if (evaccount > 4970) zprintf("p=%a\n", p);
//~ // The start of this loop is what I describe as "step (3)" in the
//~ // above commentary.
//~             if (p == fringe)
//~             {   Chunk* c1;
//~                 for (;;)
//~                 {   while ((c1 = nonblockingPopChunk()) != nullptr)
//~                     {   if (gcTrace) zprintf("another chunk at %a from queue\n", c1);
//~                         evacuateOneChunk(c1);
//~                     }
//~                     if (fringe == p)
//~                     {   c1 = popChunk(); // blocking
//~                         if (c1 == nullptr) return;
//~ //#                     if (gcTrace) zprintf("!Another chunk at %a from queue\n", c1);
//~                         evacuateOneChunk(c1);
//~                         continue;
//~                     }
//~                     else break;
//~                 }
//~                 if (myBusyChunk != currentChunk)
//~                 {   myBusyChunk = currentChunk;
//~                     p = myBusyChunk->dataStart();
//~                     zprintf("Resetting p = %a\n", p);
//~                 }
//~                 continue;
//~             }
//~             else if (p >= myBusyChunk->dataEnd())
//~             {
//~ // The test here is based on scanning right up to the very end of the Chunk,
//~ // so it will be important that when a Chunk overflows that a padder object
//~ // is inserted to fill any gap at the end. There is then a jolly edge case.
//~ // If the most recent call to gc_n_bytes() allocated memory that just
//~ // filled up the Chunk and that was used such that evacuating it did not need
//~ // and more memory. Then this thread will not have been allocated its
//~ // next Chunk. However in that case fringe would be set to the same value
//~ // as dataEnd() and I always check for p==fringe before p>=dataEnd() so this
//~ // odd case will never lead to trouble here. Phew! Relief!! The fact that
//~ // I do not hit fringe but do reach dataEnd() must be because a new Chunk
//~ // had been set up for allocation and fringe points within it, and in that
//~ // situation currentChunk[] will have been updated.
//~                 my_assert(myBusyChunk != currentChunk,
//~                           "current chunk not busy one");
//~                 myBusyChunk = currentChunk;
//~                 p = myBusyChunk->dataStart();
//~                 zprintf("Resetting p = %a\n", p);
//~                 continue;
//~             }
//~ //#         if (gcTrace) zprintf("scanning (1) at %a\n", p);
//~
//~             LispObject* pp = reinterpret_cast<LispObject*>(p);
//~ // The first word of an object may be one of several possibilities:
//~ //    Header for vector holding binary data;
//~ //    Header for vector holding Lisp data;
//~ //    Header for object with 3 lisp items then binary stuff;
//~ //    Header for symbol;
//~ //    anything else (item is a cons cell).
//~             LispObject a = *pp;
//~             size_t len, len1;
//~ #ifdef DEBUG
//~ //# if (gcTrace) zprintf("First word of %a = %a %x\n", pp, a, a&0x1f);
//~ //# if (gcTrace)
//~ //# {   if (is_cons(a))         zprintf("a cons pointer\n");
//~ //#     else if (is_vector(a))  zprintf("pointer to a vector of some sort\n");
//~ //#     else if (is_forward(a)) zprintf("forwarding pointer ILLEGAL HERE\n");
//~ //#     else if (is_symbol(a))  zprintf("pointer to a symbol\n");
//~ //#     else if (is_numbers(a)) zprintf("pointer to a symbol\n");
//~ //#     else if (is_bfloat(a))  zprintf("pointer to a boxfloat\n");
//~ //#     else if (is_fixnum(a))  zprintf("item is a fixnum\n");
//~ //#     else if (is_odds(a))
//~ //#     {   if (is_header(a))
//~ //#             zprintf("header found %a  %d:%x:%x\n", a,
//~ //#                     length_of_header(a), (a & header_mask)>>Tw, a&TAG_BITS);
//~ //#         else zprintf("immed %a = %x\n", a, a);
//~ //#     }
//~ //#     else zprintf("??? %s\n", Addr(a));
//~ //# }
//~ #endif
//~             if (is_forward(a))
//~             {   zprintf("Forwarding pointer %a found at %a\n", a, p);
//~             }
//~             my_assert(!is_forward(a), "forwarding pointer not expected");
//~             switch (a & 0x1f) // tag bits plus 2 more
//~             {
//~ // binary literals are C++14, so just for now I will use hex, but I will
//~ // write what the binary literal would be...
//~             case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
//~                                      // Note TYPE_STREAM etc is in with this.
//~                 len = length_of_header(a);
//~                 if (is_mixed_header(a)) len1 = 4*CELL;
//~                 else len1 = len;
//~ // Remember that on a 32-bit machine the final doubleword of a vector
//~ // could be padded with junk.
//~                 for (size_t i = CELL; i<len1; i += CELL)
//~                     evacuate(*reinterpret_cast<LispObject*>(p+i));
//~                 p += doubleword_align_up(len);
//~                 continue;
//~
//~             case 0x12: // 0b10010:   // Header for bit-vector
//~                 len = doubleword_align_up(length_of_header(a));
//~                 p += len;
//~                 continue;
//~
//~             case 0x1a: // 0b11010:   // Header for vector holding binary data
//~                 len = doubleword_align_up(length_of_header(a));
//~                 p += len;
//~                 continue;
//~             case 0x02: // 0b00010:   // Symbol headers plus char literals etc
//~                 if (is_symbol_header(a))
//~                 {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(p);
//~                     evacuate(s->value);
//~                     evacuate(s->env);
//~                     evacuate(s->plist);
//~                     evacuate(s->fastgets);
//~                     evacuate(s->package);
//~                     evacuate(s->pname);
//~                     p += symhdr_length;
//~                     continue;
//~                 }
//~                 // drop through.
//~             default:                 // None of the above cases...
//~                                      // ... must be a CONS cell.
//~                 evacuate(pp[0]);
//~                 evacuate(pp[1]);
//~                 p += 2*CELL;
//~                 continue;
//~             }
//~         }
//~     }
//~ }
//~
//~ void gcHelper()
//~ {
//~ // gcHelper is called to evacuate data from Chunks that have already been
//~ // copied. If none are available and if all GC copying threads agree that
//~ // they have no work to do then just terminate.
//~     evacuatePartOfMyOwnChunk();
//~ }
//~
//~ void appendMostlyFree(Page* p)
//~ {   if (mostlyFreeTail == nullptr) mostlyFreePages = p;
//~     else mostlyFreeTail->chain = p;
//~     mostlyFreeTail = p;
//~     p->chain = nullptr;
//~     p->type = mostlyFreePage;
//~     mostlyFreePagesCount++;
//~ }
//~
//~ void endOfGarbageCollection(bool major)
//~ {   //# if (gcTrace) zprintf("endOfGarbageCollection\n");
//~ // At this stage I have copied all live data into the new half-space.
//~ // There can be some data that had been pinned at the time of a previous
//~ // GC, and which may now be dead, still pinned or alive but evacuated
//~ // to a new location. Where a Chunk does not contain any old pinned data
//~ // that was re-pinned its isPinned flag will be clear, but the Chunk
//~ // will still be on the chunkPinChain of its Page and the Page will be
//~ // on the pagePinChain. I now need to tidy that up.
//~     Page* prev = nullptr;
//~     for (Page* p = pagesPinChain; p!=nullptr; p=p->pagePinChain)
//~     {   Chunk* prevC = nullptr;
//~         static int count = 0;
//~         if (count++ > 1000000) my_abort("too many pinned pages");
//~         for (Chunk* c = p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~         {   if (!c->isPinned)
//~             {   if (prevC==nullptr) p->chunkPinChain = c->chunkPinChain;
//~                 else prevC->chunkPinChain = c->chunkPinChain;
//~                 zprintf("edit out chunk %a on page %a\n", c, p);
//~             }
//~             else prevC = c;
//~         }
//~         if (p->chunkPinChain == nullptr)
//~         {   if (prev==nullptr) pagesPinChain = p->pagePinChain;
//~             else prev->pagePinChain = p->pagePinChain;
//~             p->hasPinned = false;
//~             p->pagePinChain = nullptr;
//~             zprintf("edit out page %a\n", p);
//~         }
//~         else prev = p;
//~     }
//~     dumpHeap("Debug Point A", "move pages to freePages etc");
//~ // Here all non-pinned live data has been copied to fresh space, so all
//~ // the pages chained up in oldPages can be grabbed and recycled. If such
//~ // a page has no pinned material in it goes in freePages and freePagesCount
//~ // gets incremented. If it has pinned stuff then it needs a sort of free
//~ // chain set up within it to allow for allocation around that, and it then
//~ // goes in mostlyFreePages.
//~     int count = 0;
//~     while (oldPages!=nullptr)
//~     {   Page* p = oldPages;
//~ //#     zprintf("Finished with page %a, hasPinned=%s\n", p, p->hasPinned);
//~         oldPages = oldPages->chain;
//~         if (p->hasPinned)
//~         {   setupMostlyFreePage(p);
//~             appendMostlyFree(p);
//~             zprintf("Page %a is mostlyFree\n", p);
//~         }
//~         else
//~         {   p->chunkCount = 0;
//~             p->chain = freePages;
//~             freePages = p;
//~             p->type = freePage;
//~             freePagesCount++;
//~             zprintf("Page %a is totally Free\n", p);
//~         }
//~         count++;
//~     }
//~ }
//~
//~ void tellTime(const char* s,
//~               std::chrono::high_resolution_clock::time_point start,
//~               std::chrono::high_resolution_clock::time_point finish)
//~ {   std::chrono::duration<double, std::micro> elapsed = finish-start;
//~     std::chrono::nanoseconds t =
//~         std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
//~     zprintf("%s: %.3f usec\n", s, t.count()/1000.0);
//~ }
//~
//~ void validatePointers();
//~
//~ void garbageCollect(bool major)
//~ {
//~     static unsigned int newGCcount = 0;
//~ #ifdef DEBUG
//~     gcTrace = true;
//~ #endif // DEBUG
//~     newGCcount++;
//~     if (gcTrace) zprintf("\n+++++ Start of %s GC %d +++++\n",
//~                          major ? "major" : "minor", newGCcount);
//~     dumpHeap("start of GC", "call prepareForGC");
//~ //    auto gcTime1 = std::chrono::high_resolution_clock::now();
//~     prepareForGarbageCollection(major);
//~     dumpHeap("prepareForGC done", "call clearPinnedInfo");
//~ //    auto gcTime2 = std::chrono::high_resolution_clock::now();
//~     clearPinnedInformation(major);
//~     dumpHeap("clearPinnedInfo done", "call identifyPinnedItems");
//~ //    auto gcTime3 = std::chrono::high_resolution_clock::now();
//~     identifyPinnedItems(major);
//~     dumpHeap("identifyPinnedItems done", "next setupNewHalfSpace");
//~ //    auto gcTime4 = std::chrono::high_resolution_clock::now();
//~ // I delay setting up the new currentPage until after I have tagged
//~ // pinned items. That is because otherwise the new region would count
//~ // as active and so ambiguous pointers there would be investigated, but the
//~ // chunk information and fringe pointer may be in global variables rather
//~ // then stored in the page itself. This may be especially delicate if the
//~ // page that will be used next is a partly free one with some chunks that
//~ // contain genuine pinned data. But I must set up the new half-space before
//~ // scanning to find the heads of pinned items, because I need to build
//~ // a list recording that information.
//~     setupNewHalfspace();
//~     dumpHeap("setupNewHalfspace done", "now call findHeadersOfPinnedItems");
//~     findHeadersOfPinnedItems();
//~     dumpHeap("findHeadersOfPinnedItems done", "now evacuate contents of pinned");
//~ //    auto gcTime5 = std::chrono::high_resolution_clock::now();
//~ // Report on pinning.
//~ //# if (gcTrace) zprintf("%d pinned Chunks\n", pinnedChunkCount);
//~ //# if (gcTrace) zprintf("%d pinned Pages\n", pinnedPageCount);
//~ // At this point I am ready to start! I have a fresh part of the heap set
//~ // up so that get_n_bytes() can grab memory from it. I will have
//~ // a number of GC threads all waiting for Chunks to scan.
//~ // I can start the GC by putting all pinned Chunks on the queue of Chunks
//~ // to be processed. Doing so can release some of the worker threads to
//~ // start evacuating their contents.
//~     evacuateFromPinnedItems(major);
//~     dumpHeap("evacFromPinned done", "deal with unambiguous list bases");
//~ //    auto gcTime6 = std::chrono::high_resolution_clock::now();
//~ // Next, and running as the main thread, I evacuate everything that
//~ // is referenced from a precise list-base. These list-bases are the
//~ // fixed variables used by the Lisp system and all items on the Lisp stack.
//~ // In due course I am liable to have to worry about making some of those
//~ // fixed variables thread-local and having one stack per thread, but for now
//~ // I do not!
//~     evacuateFromUnambiguousBases(major);
//~     dumpHeap("evacFromUnambig done", "evacuateFromCopiedData");
//~ //    auto gcTime7 = std::chrono::high_resolution_clock::now();
//~ // If I am running a minor GC I will need to deal with "up-pointers" where
//~ // a RPLACx style operation updated old data so that it now points at
//~ // something new enough that the GC may move it.
//~     if (!major) evacuateFromDirty();
//~ //    auto gcTime8 = std::chrono::high_resolution_clock::now();
//~ // Having got everything started I can let the main thread join in with the
//~ // sort of processing that all the worker threads are involved in. This
//~ // scans data that has just been copied and processes anything that it refers
//~ // to. In many respects the hardest part of designing how this works is
//~ // getting a proper termination condition.
//~     evacuateFromCopiedData(major);
//~     dumpHeap("evacFromCopied done", "just tidying up to do");
//~ //    auto gcTime9 = std::chrono::high_resolution_clock::now();
//~ // Now all relevant data has been copied from old to new space. I need to
//~ // tidy up by releasing the old space so it becomes available for re-use.
//~ // I also need to ensure that the fringe and limit pointers used by the
//~ // GC helper threads are transferred so that they become usable by ordinary
//~ // worker threads.
//~     endOfGarbageCollection(major);
//~ //    auto gcTime10 = std::chrono::high_resolution_clock::now();
//~ //// The timings reported here will at present be deeply misleading because
//~ //// they include the time taken by all the debug printing. But at a later
//~ //// stage when I disable that the display from here may help me judge
//~ //// which parts of the GC deserve the greatest attention by way of tuning.
//~ //    tellTime("prepare               ", gcTime1, gcTime2);
//~ //    tellTime("clear pins            ", gcTime2, gcTime3);
//~ //    tellTime("identify pinned       ", gcTime3, gcTime4);
//~ //    tellTime("get headers of pinned ", gcTime4, gcTime5);
//~ //    tellTime("evac from pinned      ", gcTime5, gcTime6);
//~ //    tellTime("evac from precise     ", gcTime6, gcTime7);
//~ //    tellTime("evac from dirty       ", gcTime7, gcTime8);
//~ //    tellTime("evac from copied      ", gcTime8, gcTime9);
//~ //    tellTime("tidy up               ", gcTime9, gcTime10);
//~     dumpHeap("end of GC", "GC complete", newGCcount);
//~ #ifdef DEBUG
//~ // Just to test things!
//~     testLayout();
//~     validatePointers();
//~ #endif // DEBUG
//~ }
//~
//~ // This flag generally controls whether a generational collector will be
//~ // used, however an explicit call (reclaim nil) will try a generational
//~ // collection regardless of its setting. It is really just here to help me
//~ // keep control of things until the generation collector has been implemented
//~ // and for switching it on and off for testing and debugging purposes.
//~
//~ bool generationalGarbageCollection = false;
//~
//~ void generationalGarbageCollect()
//~ {   garbageCollect(false);
//~ }
//~
//~ void fullGarbageCollect()
//~ {   garbageCollect(true);
//~ }
//~
//~
//~ //==================
//~
//~ #ifdef DEBUG
//~
//~ static const size_t hashSize = 0x100000;
//~ static LispObject visitedHash[hashSize];
//~
//~ bool inActivePage(LispObject a)
//~ {   if (a==0 || a==nil || is_immediate(a)) return true;
//~     Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~     return p->chunkCount != 0;
//~ }
//~
//~ void clearRepeats()
//~ {   memset(visitedHash, 0, sizeof(visitedHash));
//~ }
//~
//~ // This now needs to check the Chunk that a is within. If it is
//~ // a pinned Chunk then a must me mentioned in its list of pinned
//~ // objects, otherwise it must be before the fringe.
//~
//~ uintptr_t why = 0;
//~ enum Why
//~ {   whyNil       = 1,
//~     whyCStack    = 2,
//~     whyLispStack = 3,
//~     whyListBase  = 4,
//~     whyRepeats   = 5,
//~     whyPinned    = 6
//~ };
//~
//~ const char* decodeWhy(uintptr_t d)
//~ {   static char b[64];
//~     const char* fmt="??";
//~     switch (d & 0xf)
//~     {
//~     case whyNil:
//~         fmt = "Nil %" PRIdPTR;
//~         break;
//~     case whyCStack:
//~         fmt = "CStack %" PRIxPTR;
//~         break;
//~     case whyLispStack:
//~         fmt = "LispStack %" PRIdPTR;
//~         break;
//~     case whyListBase:
//~         fmt = "LispBase %" PRIdPTR;
//~         break;
//~     case whyRepeats:
//~         fmt = "Repeats %" PRIxPTR;
//~         break;
//~     case whyPinned:
//~         fmt = "Pinned %" PRIxPTR;
//~         break;
//~     default:
//~         fmt = "Unknown %" PRIxPTR;
//~         break;
//~     }
//~     std::sprintf(b, fmt, d/16);
//~     return b;
//~ }
//~
//~ void validateAsLive(LispObject a)
//~ {   a &= ~TAG_BITS;
//~     Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~     if (p->chunkCount == 0 || p->type==freePage)
//~     {   zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~         my_abort("pointer into a page with no chunks");
//~     }
//~     if (!p->chunkMapSorted)
//~     {   std::qsort(p->chunkMap, p->chunkCount, sizeof(p->chunkMap[0]),
//~                    chunkOrder);
//~         p->chunkMapSorted = true;
//~     }
//~     size_t low = 0, high = p->chunkCount-1;
//~     while (low < high)
//~     {   size_t middle = (low + high + 1)/2;
//~         if (static_cast<uintptr_t>(a) <
//~             reinterpret_cast<uintptr_t>(
//~                 static_cast<Chunk*>(p->chunkMap[middle])))
//~             high = middle-1;
//~         else low = middle;
//~     }
//~     Chunk* c = p->chunkMap[low];
//~ // Now when a pointer is into a mostlyFreePage it can only be valid if
//~ // it points to something pinned. Well that is not quite true. It must
//~ // point either to something that is now pinned or to something that
//~ // was pinned last time. In the latter case the Chunk may still contain
//~ // some items that are still pinned and hence may have a pinnedObjects chain,
//~ // but this item may not be on it.
//~     if (p->type==mostlyFreePage)
//~     {   // bool valid = false;
//~         unsigned int count = 0;
//~         for (LispObject ch=c->pinnedObjects&~TAG_BITS;
//~                         ch!=0;
//~                         ch=cdr(ch)&~TAG_BITS)
//~         {   if (withinObject(
//~                 reinterpret_cast<LispObject*>(car(ch)&~TAG_BITS), a))
//~             {   // valid = true;
//~                 break;
//~             }
//~             else if (++count > 1000000)
//~             {   count = 0;
//~                 for (LispObject ch=c->pinnedObjects&~TAG_BITS;
//~                                 ch!=0;
//~                                 ch=cdr(ch)&~TAG_BITS)
//~                 {   zprintf("PIN %a car=%a cdr=%a\n",
//~                             ch, car(ch), cdr(ch));
//~                     if (count++ > 5) break;
//~                 }
//~                 zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~                 my_abort("pinned object list messed up");
//~             }
//~         }
//~ /* This moan could be over pessimistic, and I observe cases where it is!
//~  *      if (!valid)
//~  *      {   zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~  *          zprintf("Pointer %a is invalid\n", a);
//~  *          my_abort("invalid pointer to unpinned object in pinned chunk");
//~  *      }
//~  */
//~     }
//~     else
//~     {
//~ /*
//~ // In busyPages and oldPages a pointer is OK if its is between the
//~ // dataStart and fringe of the Chunk.
//~         if (!c->pointsWithinChunk(a))
//~         {   zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~             zprintf("Pointer %a is invalid\n", a);
//~             zprintf("Chunk is %a to %a\n", c, c->chunkFringe);
//~             my_abort("invalid pointer to object within a live chunk");
//~         }
//~ */
//~     }
//~ }
//~
//~ void validateForGC(LispObject a)
//~ {   if (a == nil || is_immediate(a)) return;
//~     if (!inActivePage(a))
//~     {   Page* p = reinterpret_cast<Page*>(a & -pageSize);
//~         zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~         zprintf("Item %a is in free page %a (chunk-count=%d)\n", a, p, p->chunkCount);
//~         simple_print(a);
//~         zprintf("Quitting\n");
//~         my_abort("Item is in free page");
//~     }
//~     if (is_forward(a))
//~     {   zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~         zprintf("illegal forwarding pointer %a\n", a);
//~         zprintf("points to item with first word %a\n", car(a&~TAG_BITS));
//~         zprintf("Quitting\n");
//~         my_abort("forwarding pointer where one should not be");
//~     }
//~     my_assert(!is_forward(a), "forwarding pointer in validateForGC");
//~ // The multiplier I use to prepare a hash value here is not very carefully
//~ // selected. Its value is mostly there to suggest I have not picked something
//~ // that will have cunning interaction with all else that I do.
//~     size_t h = ((a*3141592653589793237u) >> 40) & (hashSize-1);
//~     for (;;)
//~     {   if (visitedHash[h] == a) return;
//~         else if (visitedHash[h] == 0)
//~         {   visitedHash[h] = a;
//~             break;
//~         }
//~         h = (h + 1) & (hashSize-1);
//~     }
//~     if (is_cons(a))
//~     {   validateAsLive(a);
//~         validateForGC(car(a));
//~         validateForGC(cdr(a));
//~         return;
//~     }
//~     else if (is_symbol(a))
//~     {   validateAsLive(a);
//~         validateForGC(qvalue(a));
//~         validateForGC(qenv(a));
//~         validateForGC(qplist(a));
//~         validateForGC(qfastgets(a));
//~         validateForGC(qpackage(a));
//~         validateForGC(qpname(a));
//~         return;
//~     }
//~     else if (is_vector(a))
//~     {   validateAsLive(a);
//~     }
//~ }
//~
//~ void validateUnambiguousBases(bool major)
//~ {   //# if (gcTrace) zprintf("validateFromUnambiguousBases\n");
//~ // This code has to know where ALL the definitive references to LispObjects
//~ // are in the C++ code. The main way it achieves this is through a vector
//~ // "list_bases" that holds the address of every static location involved.
//~ // That vector is about 200 items long. In addition the dedicated Lisp
//~ // stack has to be processed.
//~     why = whyNil;
//~     validateForGC(qvalue(nil));
//~     why = whyNil + 1*16;
//~     validateForGC(qenv(nil));
//~     why = whyNil + 2*16;
//~     validateForGC(qplist(nil));
//~     why = whyNil + 3*16;
//~     validateForGC(qpname(nil));
//~     why = whyNil + 4*16;
//~     validateForGC(qfastgets(nil));
//~     why = whyNil + 5*16;
//~     validateForGC(qpackage(nil));
//~     if (gcTrace) zprintf("validate regular list bases\n");
//~     for (auto p = list_bases;* p!=nullptr; p++)
//~     {   //# zprintf("{%s}", list_names[p-list_bases]);
//~         why = whyListBase + (p-list_bases)*16;
//~         validateForGC(**p);
//~     }
//~ //# zprintf("\n");
//~ //# if (gcTrace) zprintf("validate lisp stack\n");
//~     for (LispObject* sp=stack;
//~          sp>reinterpret_cast<LispObject*>(stackBase); sp--)
//~     {   why = whyLispStack + 16*(sp-stack);
//~         validateForGC(*sp);
//~     }
//~ // When running the deserialization code I keep references to multiply-
//~ // used items in repeat_heap, and if garbage collection occurs they must be
//~ // updated.
//~ //# if (gcTrace) zprintf("validate repeat heap\n");
//~     if (repeat_heap != nullptr)
//~     {   for (size_t i=1; i<=repeat_count; i++)
//~         {   why = whyRepeats + 16*i;
//~             validateForGC(repeat_heap[i]);
//~         }
//~     }
//~ }
//~
//~ void validatePinnedInChunk(Chunk* c)
//~ {   uintptr_t p = c->dataStart();
//~ //# if (gcTrace) zprintf("Pinned chunk has data %a to %a end %a\n",
//~ //#                      c->dataStart(), c->chunkFringe, c->dataEnd());
//~     while (p < c->chunkFringe)
//~     {
//~ // I could skip up to 512 bytes at a time by using word operations on the
//~ // bitmap, and if I did then the fact that there are only 32 (64-bit) words
//~ // in the bitmap makes this whole scan feel not too bad.
//~         if (!isPinned(p))
//~         {   p += 8;
//~             continue;
//~         }
//~         LispObject* pp = reinterpret_cast<LispObject*>(p);
//~ //#     if (gcTrace) zprintf("Scanning pinned item at %a\n", p);
//~         LispObject a = *pp;
//~ //#     if (gcTrace) zprintf("Item at %a = %x = %a\n", pp, a, a);
//~         my_assert(a != 0, "zero item in heap");
//~         if (is_forward(a))
//~         {   zprintf("why=%s a=%a\n", decodeWhy(why), a);
//~         }
//~         my_assert(!is_forward(a), "forwarding pointer found");
//~         size_t len, len1;
//~         switch (a & 0x1f) // tag bits plus 2 more
//~         {
//~ // binary literals are C++14, so just for now I will use hex, but I will
//~ // write what the binary literal would be...
//~         case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
//~                                  // Note TYPE_STREAM etc is in with this.
//~             len = doubleword_align_up(length_of_header(a));
//~             if (is_mixed_header(a)) len1 = 4*CELL;
//~             else len1 = len;
//~ //#         if (gcTrace) zprintf("vector (%x) uses %d bytes\n", a, len);
//~             if (len == 0) if (gcTrace) zprintf("At %a up to %a\n", pp, c->chunkFringe);
//~             for (size_t i = CELL; i<len1; i += CELL)
//~                 validateForGC(*reinterpret_cast<LispObject*>(p+i));
//~             my_assert(len != 0, "lisp vector size zero");
//~             p += len;
//~             continue;
//~
//~         case 0x12: // 0b10010:   // Header for bit-vector
//~             len = doubleword_align_up(length_of_header(a));
//~             my_assert(len != 0, "bit vector size zero");
//~ //#         if (gcTrace) zprintf("bit-vector uses %d bytes\n", len);
//~             p += len;
//~             continue;
//~
//~         case 0x1a: // 0b11010:   // Header for vector holding binary data
//~             len = doubleword_align_up(length_of_header(a));
//~             my_assert(len != 0, "binary vector size zero");
//~ //#         if (gcTrace) zprintf("binary-vector uses %d bytes\n", len);
//~             p += len;
//~             continue;
//~
//~         case 0x02: // 0b00010:   // Symbol headers plus char literals etc
//~             if (is_symbol_header(a))
//~             {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(p);
//~                 validateForGC(s->value);
//~                 validateForGC(s->env);
//~                 validateForGC(s->plist);
//~                 validateForGC(s->fastgets);
//~                 validateForGC(s->package);
//~                 validateForGC(s->pname);
//~ //#             if (gcTrace) zprintf("symbol uses %d bytes\n", symhdr_length);
//~ //#             if (gcTrace) zprintf("inc from %a to %a\n", p, Addr(p+symhdr_length));
//~                 p += symhdr_length;
//~                 continue;
//~             }
//~             // drop through.
//~         default:                 // None of the above cases...
//~                                  // ... must be a CONS cell.
//~             validateForGC(pp[0]);
//~             validateForGC(pp[1]);
//~ //#         if (gcTrace) zprintf("cons cell uses %d bytes\n", 2*CELL);
//~             p += 2*CELL;
//~             continue;
//~         }
//~     }
//~ }
//~
//~ void validatePinnedItems(bool major)
//~ {   //# if (gcTrace) zprintf("validate Pinned Items\n");
//~     for (Page* p=pagesPinChain; p!=nullptr; p=p->pagePinChain)
//~     {   static int count = 0;
//~         if (count++ > 1000000) my_abort("too many pinned pages");
//~         for (Chunk* c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~         {   //# if (gcTrace) zprintf("Pinned items in %s to check\n", Addr(c));
//~             why = whyPinned;
//~             validatePinnedInChunk(c);
//~         }
//~     }
//~ }
//~
//~ void validatePointers()
//~ {   clearRepeats();
//~     validateUnambiguousBases(true);
//~     validatePinnedItems(true);
//~ //# if (gcTrace) zprintf("Validation complete\n");
//~ }
//~
//~ #endif // DEBUG
//~
//~ // These functions whose initial letter is "F" are ones that give me
//~ // access to the value of atomic items in Chunk, Page and globally. I have
//~ // these because gdb (at least on some platforms) will not let me go (eg)
//~ // "print gFringe" because it has inlined the load function. So I
//~ // use "print FgFringe()" instead. Well if FgFringe() is defined in a header
//~ // as an inline function and then never referenced in the code it is omitted
//~ // totally and so is not available for debugging. So this function is here
//~ // to contain rather stupid references to all these "F" functions. I disable
//~ // optimisation when I compile it to try to ensure that it serves the purpose
//~ // of making external references to all the functions. It would not be a very
//~ // good idea to call this!
//~
//~ #if defined __clang__
//~ #pragma clang optimize off
//~ #elif defined __GNUC__ // __clang__
//~ #pragma GCC optimize("0")
//~ #endif //__clang__ or __GNUC__
//~
//~ void getInlineFunctionsDefined()
//~ {   Chunk c;
//~     (void)c.Flength();
//~     (void)c.FchunkFringe();
//~     (void)c.FpinnedObjects();
//~     (void)c.FisPinned();
//~     (void)c.FpendingChunks();
//~     Page p;
//~     (void)p.Ffringe();
//~     (void)p.Flimit();
//~     (void)p.FhasPinned();
//~     (void)p.FpagePinChain();
//~     (void)p.FchunkPinChain();
//~     (void)p.FchunkCount();
//~     (void)p.FchunkMap(0);
//~     (void)Flimit();
//~     (void)FgFringe();
//~     (void)FactiveThreads();
//~ }
//~
//~ // This is intended to display all more or less live parts of memory.
//~ // I can call it at the start and end of garbage collection to help me
//~ // understand what goes on.
//~
//~ void dumpChunk(Chunk* c)
//~ {   if (c->isPinned || c->pinnedObjects!=TAG_FIXNUM)
//~     {   zprintf("Chunk %s%a is pinned\n", (c->isPinned?"||":""), c);
//~ // The pin-list should have been displayed earlier - but here because I
//~ // am having some trouble I will try displaying everything I can
//~         zprintf("length = %d = %x\n", c->length, c->length);
//~         zprintf("end = %a\n", c->dataEnd());
//~         zprintf("chunkFringe = %a\n", c->chunkFringe);
//~         zprintf("pinned = %s evacuated = %s pinnedObjects=%a\n",
//~                 c->isPinned, c->evacuated, c->pinnedObjects);
//~         zprintf("chunkPinChain = %a pendingChunks=%a\n",
//~                 c->chunkPinChain, c->pendingChunks);
//~         // Also display contents.
//~     }
//~     if (c->chunkFringe != 0)
//~         zprintf("%a: fringe = %a length = %d end=%a evacuated = %s\n",
//~                 c, c->chunkFringe, c->length, c->dataEnd(), c->evacuated);
//~     uintptr_t p = c->dataStart();
//~     if (c->evacuated)
//~     {   while (p < c->chunkFringe)
//~         {   LispObject* pp = reinterpret_cast<LispObject*>(p);
//~             zprintf("%a: %a\n", p, *pp);
//~             p += CELL;
//~         }
//~     }
//~ // If the Chunk does not contain any forwarding pointers it should be
//~ // easy to perform a linear scan inspecting it. If it DOES contain forwarding
//~ // pointers I will pretend that a cell containing one contains the first
//~ // word of the addresses data.
//~     else while (p < c->chunkFringe)
//~     {   LispObject* pp = reinterpret_cast<LispObject*>(p);
//~         LispObject a = *pp;
//~         if (is_forward(a))
//~         {   zprintf("->");
//~             a = *reinterpret_cast<LispObject*>(a&~TAG_BITS);
//~             if (is_forward(a))
//~             {   zprintf("Double forwarding %a %a %a\n", p, *pp, a);
//~                 my_abort("double forward");
//~             }
//~         }
//~         size_t len;
//~         switch (a & 0x1f) // tag bits plus 2 more
//~         {
//~         case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
//~                                  // Note TYPE_STREAM etc is in with this.
//~         case 0x12: // 0b10010:   // Header for bit-vector
//~         case 0x1a: // 0b11010:   // Header for vector holding binary data
//~             len = length_of_header(a);
//~             zprintf("At %s%a vector of length %d/%x %s",
//~                     isPinned(p)?"|":"", p, len, len, decodeObject(a));
//~             if (is_string_header(a) && len <= 10+CELL)
//~                 zprintf(" \"%s\"", reinterpret_cast<char*>(p)+CELL);
//~             zprintf("\n");
//~             p += doubleword_align_up(len);
//~             continue;
//~
//~         case 0x02: // 0b00010:   // Symbol headers plus char literals etc
//~             if (is_symbol_header(a))
//~             {   zprintf("Symbol header at %s%a\n", isPinned(p)?"|":"", p);
//~                 zprintf("  val: %s\n", decodeObject(qvalue(p+TAG_SYMBOL)));
//~                 zprintf("  pname: %s\n", decodeObject(qpname(p+TAG_SYMBOL)));
//~                 zprintf("  plist: %s\n", decodeObject(qplist(p+TAG_SYMBOL)));
//~                 p += symhdr_length;
//~                 continue;
//~             }
//~             // drop through.
//~         default:                 // None of the above cases...
//~                                  // ... must be a CONS cell.
//~             zprintf("Cons cell at %s%a: {%a . %a}\n",
//~                     isPinned(p)?"|":"", p, a, cdr(p));
//~             p += 2*CELL;
//~             continue;
//~         }
//~     }
//~ }
//~
//~ void dumpPage(Page* p, const char* pageSort)
//~ {   zprintf("Page %a is %s\n", p, pageSort);
//~     if (p->chunkCount != 0)
//~     {   zprintf("Chunks:");
//~         for (size_t i=0; i<p->chunkCount; i++)
//~             zprintf(" %d:%a", i, p->chunkMap[i]);
//~         zprintf("\n");
//~     }
//~     if (p->hasPinned) zprintf("Page has some pinned data\n");
//~     if (p->chunkPinChain != nullptr)
//~     {   zprintf("pinned Chunks: ");
//~         for (Chunk* c=p->chunkPinChain; c!=nullptr; c=c->chunkPinChain)
//~         {   zprintf(" %a:", c);
//~             for (LispObject ch = c->pinnedObjects;
//~                  ch!=TAG_FIXNUM;
//~                  ch=cdr(ch&~TAG_BITS))
//~             {   zprintf("  {%a}: %a",
//~                         ch&~TAG_BITS, car(ch&~TAG_BITS)&~TAG_BITS);
//~             }
//~             zprintf("\n");
//~         }
//~     }
//~     for (size_t i=0; i<p->chunkCount; i++)
//~         dumpChunk(p->chunkMap[i]);
//~ }
//~
//~ void dumpHeap(const char* msg)
//~ {   zprintf("\ndumpHeap(\"%s\");\n", msg);
//~     if (currentChunk != nullptr) currentChunk->chunkFringe = fringe;
//~     for (Page* p = busyPages; p!=nullptr; p=p->chain)
//~         dumpPage(p, "busy");
//~     for (Page* p = oldPages; p!=nullptr; p=p->chain)
//~         dumpPage(p, "old");
//~     for (Page* p = mostlyFreePages; p!=nullptr; p=p->chain)
//~         dumpPage(p, "mostlyFree");
//~ // I will only mention the first few pages in the freePages list. These
//~ // will be the most recent ones that the GC has put there and so the most
//~ // interesting! Ones beond that may well have been free for all time and
//~ // are unutterably boring.
//~ //# int count = 0;
//~ //# for (Page* p = freePages; p!=nullptr && ++count<3; p=p->chain)
//~ //# {   dumpPage(p, "free");
//~ //# }
//~     zprintf("End of dump\n");
//~ }
//~
//~ void dumpHeap(const char* msg, unsigned int n)
//~ {   static char m[256];
//~     sprintf(m, "%s [%u]", msg, n);
//~     dumpHeap(m);
//~ }
//~
//~ void dumpHeap(const char* msg, const char* msg1)
//~ {   dumpHeap(msg);
//~     zprintf("%s\n", msg1);
//~ }
//~
//~ void dumpHeap(const char* msg, const char* msg1, unsigned int n)
//~ {   dumpHeap(msg, n);
//~     zprintf("%s\n", msg1);
//~ }
//~
//~ void rawChunk(Chunk* c)
//~ {
//~     zprintf("CHUNK %a: length = %d = %x\n", c, c->length, c->length);
//~     zprintf("end = %a\n", c->dataEnd());
//~     zprintf("chunkFringe = %a evacuated = %s\n", c->chunkFringe, c->evacuated);
//~     zprintf("pinned = %s pinnedObjects=%a\n",
//~             c->isPinned, c->pinnedObjects);
//~     zprintf("chunkPinChain = %a pendingChunks=%a\n",
//~             c->chunkPinChain, c->pendingChunks);
//~     if (c->chunkFringe != 0)
//~         zprintf("fringe = %a length = %d end=%a\n",
//~                 c->chunkFringe, c->length, c->dataEnd());
//~     uintptr_t p = c->dataStart();
//~     while (p < c->chunkFringe)
//~     {   LispObject* pp = reinterpret_cast<LispObject*>(p);
//~         zprintf("%a: %a\n", p, *pp);
//~         p += CELL;
//~     }
//~ }
//~
//~ void rawPage(Page* p, const char* pageSort)
//~ {   zprintf("Page %a is %s\n", p, pageSort);
//~     if (p->chunkCount != 0)
//~     {   zprintf("Chunks:");
//~         for (size_t i=0; i<p->chunkCount; i++)
//~             zprintf(" %d:%a", i, p->chunkMap[i]);
//~         zprintf("\n");
//~     }
//~     if (p->hasPinned) zprintf("Page has some pinned data\n");
//~     for (size_t i=0; i<p->chunkCount; i++)
//~         rawChunk(p->chunkMap[i]);
//~ }
//~
//~ void rawHeap(const char* msg)
//~ {   zprintf("\nrawHeap(\"%s\");\n", msg);
//~     if (currentChunk != nullptr) currentChunk->chunkFringe = fringe;
//~     for (Page* p = busyPages; p!=nullptr; p=p->chain)
//~         rawPage(p, "busy");
//~     for (Page* p = oldPages; p!=nullptr; p=p->chain)
//~         rawPage(p, "old");
//~     for (Page* p = mostlyFreePages; p!=nullptr; p=p->chain)
//~         rawPage(p, "mostlyFree");
//~ // I will only mention the first few pages in the freePages list. These
//~ // will be the most recent ones that the GC has put there and so the most
//~ // interesting! Ones beond that may well have been free for all time and
//~ // are unutterably boring.
//~ //# int count = 0;
//~ //# for (Page* p = freePages; p!=nullptr && ++count<3; p=p->chain)
//~ //# {   rawPage(p, "free");
//~ //# }
//~     zprintf("End of raw\n");
//~ }
//~
//~ void rawHeap(const char* msg, unsigned int n)
//~ {   static char m[256];
//~     sprintf(m, "%s [%u]", msg, n);
//~     rawHeap(m);
//~ }
//~
//~ void rawHeap(const char* msg, const char* msg1)
//~ {   rawHeap(msg);
//~     zprintf("%s\n", msg1);
//~ }
//~
//~ void rawHeap(const char* msg, const char* msg1, unsigned int n)
//~ {   rawHeap(msg, n);
//~     zprintf("%s\n", msg1);
//~ }

#endif // REWORKED

// end of file newcslgc.cpp
