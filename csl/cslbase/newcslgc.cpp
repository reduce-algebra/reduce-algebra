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
    case consPageType:
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
// Ha ha there is a potential ugliness here in that the cons cell I am
// about to allocate could be at an address that an ambiguous pointer I have
// not yet got round to handling seems to refer to, but it would be silly
// to let it get pinned. To avoid that I arrange that during this early
// part of garbage collection any pages that I allocate within for just
// this purpose remain tagged with emptyPageType and so the pinning process
// will ignore references into them. I reset the page type as soon as I can.
// I also do not want this list to be subject to getting pinned during the
// next GC since that could preserve material it refers to in a really
// unhalpful way. I achieve that by making it a sort of fake list where
// all the pointers within it are tagged as if fixnums. That means that the
// objects it references do not have their type captured in a tagged pointer,
// so when I process them I will need to deduce type by inspecting them.
            LispObject z = get2Words();
            consCurrent->type = emptyPageType;
            car(z) = a + TAG_FIXNUM;
            cdr(z) = p->pinnedObjects;
            p->pinnedObjects = z + TAG_FIXNUM;
        }
        return;
    case vecPageType:
// Pointers into vector pages can refer to any individual cell. The biggest
// cause of pain here is that the pointers may refer to addresses within
// objects (as distinct from just identifying the object header). I do
// not have a trivial way to tell where objects start, so I will tend to
// set mark bits now even when they are not on object headers and correct
// in a later phase. This is where I rely on "chunks" and I will view
// an ambiguous pointer as "provisionally valid" either if it is at an
// address before vecDataEnd or if it is into a chunk beyond that where
// the chunkStatus entry indicates that it contains at least some old
// pinned material. When I set a mark bit I will tag the chunk as
// "of interest" in another little bitmap, and push the Page
// onto a chain of ones to deal with later.
        {   a = a & -(sizeof(LispObject));   // align the pointer (a).
            dataStart = reinterpret_cast<uintptr_t>(&p->chunks);
            if (a < dataStart) return;
            size_t chunkNo = chunkNoFromAddress(p, a);
// The pointer may be valid either if it refers to an address below the
// fringe or if it is withing a chunk that had been pinned during an
// earlier GC.
            int w = p->chunkStatus[chunkNo];
// Reset chunkNo to refer to the start of the chunk that this address
// lies within. Hah if the value seen is ExtendedChunkMax then I step
// back that far and check again. That is because chunk sequence values
// saturate, but the page size is such that just two probes will
// always suffice.
            if (w >= ExtendedChunkMax)
                w = p->chunkStatus[chunkNo -= w-1];
            if (w > ExtendedChunkStart && w <= ExtendedChunkMax)
                w = p->chunkStatus[chunkNo -= w-1];
            if (a < p->dataEnd ||
                w >= ExtendedPinnedChunk) // ExtendedPinned or BasicPinned
            {
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
                LispObject z = get2Words();
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

void evacuate(LispObject &a)
{
// Here a refers to a location that is a list-base, ie it contains
// a valid Lisp object, but also the value of a is the LispObject
// held in that location. I want to arrange that the object and all its
// components are moved to the new half space, and (if necessary) the
// list base is updated to refer to the copy and a forwarding pointer is left
// where the original had been. The procedure is:
//   a is the object that may need to be copied.
//   If a is tagged as immediate data do nothing.
//   [now a is some sort of tagged pointer]
//   If *a is a forwarding pointer replace the list base with the
//      object referred to, reconstructing suitable tag bits.
//   If a refers to material that is pinned do nothing.
//   Determine the length, b, of the object that a refers to.
//   Allocate b byte in the new space and do a simple binary copy of all
//      of object a to there.
//   Write in a forwarding pointer.
//   Update the list-base to refer to the copy.
// Note that this is a shallow copy operation. A later stage must perform
// a linear scan of the newly copied material. That stage is not discussed
// here because this function does not directly cause it to happen.
    my_assert(a != 0, "zero word in scanning");
    my_assert(!is_forward(a), "forwarding ptr in scanning");
    if (is_immediate(a) || a == nil) return;
    LispObject* ap = reinterpret_cast<LispObject*>(a & ~TAG_BITS);
    LispObject aa = *ap;
    if (is_forward(aa))
    {   a = aa - TAG_FORWARD + (a & TAG_BITS);
        return;
    }
// Now I will need to make a copy of the item.
    size_t len;
// Finding its length is not too hard here because I have a validly tagged
// pointer to it.
    if (is_cons(a)) len = 2*CELL;
    else if (is_symbol(a)) len = symhdr_length;
    else len = length_of_header(aa);
    if (len == 2*CELL) aa = get2Words();
    else aa = getNBytes(len);
// I will copy the full final doubleword of a vector, and in the case of
// a 32-bit machine or for vectors that contain components that are smaller
// than CELL this will include material beyond that which is meaningful.
// This at least keeps any zero-padding of the last word intact.
    std::memcpy(reinterpret_cast<void*>(aa), ap, doubleword_align_up(len));
    *ap = TAG_FORWARD + aa;
    a = aa + (a & TAG_BITS);
}

void evacuateFromUnambiguousBases()
{
// This code has to know where ALL the definitive references to LispObjects
// are in the C++ code. The main way it achieves this is through a vector
// "list_bases" that holds the address of every static location involved.
// That vector is about 200 items long. In addition the dedicated Lisp
// stack has to be processed.
    evacuate(qvalue(nil));
    evacuate(qenv(nil));
    evacuate(qplist(nil));
    evacuate(qpname(nil));
    evacuate(qfastgets(nil));
    evacuate(qpackage(nil));
    for (auto p = list_bases;* p!=nullptr; p++) evacuate(**p);
    for (LispObject* sp=stack;
         sp>reinterpret_cast<LispObject*>(stackBase); sp--) evacuate(*sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != nullptr)
    {   for (size_t i=1; i<=repeat_count; i++)
            evacuate(repeat_heap[i]);
    }
}

void evacuateFromPinnedItems()
{   for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
    {   for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                        c!=0;
                        c=cdr(c)-TAG_FIXNUM)
        {   LispObject p = car(c)-TAG_FIXNUM;
            Header h = *reinterpret_cast<Header*>(p);
            size_t len, len1;
// Now based on the low 6 bits of the first word of the object I sort
// out whether it is a vector containing Lisp data, a vector containing
// binary data (including strings and bignums) or a symbol. If none of
// those then it will be a CONS cell.
            switch (h & 0x1f)
            {
            case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                     // Note TYPE_STREAM etc is in with this.
                len = length_of_header(h);
                if (is_mixed_header(h))
                    len1 = 4*CELL;
                else len1 = len;
                my_assert(len != 0, "lisp vector size zero");
                for (size_t i = CELL; i<len1; i += CELL)
                    evacuate(*reinterpret_cast<LispObject*>(p+i));
                continue;

            case 0x12: // 0b10010:   // Header for bit-vector
            case 0x1a: // 0b11010:   // Header for vector holding binary data
                continue;

            case 0x02: // 0b00010:   // Symbol headers plus char literals etc
                if (is_symbol_header(h))
                {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(p);
                    evacuate(s->value);
                    evacuate(s->env);
                    evacuate(s->plist);
                    evacuate(s->fastgets);
                    evacuate(s->package);
                    evacuate(s->pname);
                    continue;
                }
                // drop through on character literals etc.
            default:                 // None of the above cases... so a CONS
                evacuate(car(p));
                evacuate(cdr(p));
                continue;
            }
        }
    }
}

void evacuateConsPage(Page* p)
{   uintptr_t next = reinterpret_cast<uintptr_t>(&p->consData);
    while (next != p->dataEnd)
    {   evacuate(*reinterpret_cast<LispObject*>(next));
        next += sizeof(LispObject);
    }
}

void evacuateVecPage(Page* p)
{   // Not coded yet
}

bool evacuateCurrentConsPage(Page*& p)
{   uintptr_t next = p->scanPoint;
    bool result = false;
    while (next != p->dataEnd && next != consFringe)
    {   evacuate(*reinterpret_cast<LispObject*>(next));
        result = true;
        next += sizeof(LispObject);
    }
    p->scanPoint = next;
    return result;
}

bool evacuateCurrentVecPage(Page*& p)
{   // Not coded yet
    uintptr_t vF = reinterpret_cast<uintptr_t>(&p->chunks);
    uintptr_t vE = p->dataEnd;
    return false;
}

void evacuateFromCopiedData()
{   Page* consP = consPages;
    Page* vecP = vecPages;
    for (;;)
    {
// Each of the functions here returns true if it found any data to
// evacuate, and so if all of them return false there will be nothing
// more to do. The final entry on the list consPages will always be
// consCurrent since when I allocate a new Page I put it on the end of
// the list, and furthermore I started the GC by setting up a consCurrent.
// And similarly for vector pages.
        if (consP != consCurrent)
        {   Page* p = consP;
            consP = p->chain;
            evacuateConsPage(p);
            continue;
        }
        if (vecP != vecCurrent)
        {   Page* p = vecP;
            vecP = p->chain;
            evacuateVecPage(p);
            continue;
        }
// Here consP == consCurrent and vecP == vecCurrent. Note that evacuating
// data from consCurrent can in general add more data to that Page and may
// well turn it into a full page. If it does that and has then evacuated
// everything in that page it must reset consP to the next Page so it does
// not get re-scanned. However if it runs out of work to do with the
// Page still not full it will get called again. So the more careful
// explanation is that it must start evacuating starting at the location
// given by scanPoint. Then if it has moved that as far as it can and it
// then gets called again it just returns false.
        if (evacuateCurrentConsPage(consP)) continue;
        if (evacuateCurrentVecPage(vecP)) continue;
        break;
    }
}

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

// I start garbage collection by  making the current allocation pages
// have the structure of ones that are full. The only thing that involves
// is storing fringe pointers in them.

bool withinGarbageCollector = false;

void inner_garbage_collect()
{   WithinGarbageCollector noted;
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
    consOldPages = consPages;
    vecOldPages = vecPages;
    consPages = vecPages =
        consPagesTail = vecPagesTail = nullptr;
    consPagesCount = vecPagesCount = 0;
    pinnedPages = nullptr;
// ... and allocate what will be the start of the new half-space.
// Well here I will not want any ambiguous pointers into this new
// space to be deemed valid, and I will be putting stuff into the
// CONS region as a list of pinned objects - so on a temporary basis
// I will mark the pages as free!
    consCurrent = grabFreshPage(consPageType);
    pageAppend(consCurrent,
               consPages, consPagesTail, consPagesCount);
    consCurrent->type = emptyPageType;
    vecCurrent = grabFreshPage(vecPageType);
    pageAppend(vecCurrent,
               vecPages, vecPagesTail, vecPagesCount);
// Now I can scan the stack and mark up pinned items. This will build
// up a chain of pages still 
    identifyPinnedItems();
    findHeadersOfPinnedItems();
// Now I have finished identifying all the pinned objects, so I can make
// pages that contain lists of them proper again.
    for (Page* p=consPages; p!=nullptr; p=p->chain)
        p->type = consPageType;
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
    evacuateFromPinnedItems();
    evacuateFromUnambiguousBases();
    evacuateFromCopiedData();
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
// inner_garbage_collect() to something far enough away that the compiler
// does not see it, and whole-program optimisation could defeat that!
// I alse want the jmp_buf to have been allocate on the stack at a lower
// address than any other values currently in use. The "NOINLINE" qualifier
// as provided by gcc is intended to help to enforce that by arranging that
// garbage_collect() has its own stack frame with almost nothing except
// inner_garbage_collect() and the jmp_buf in it. If inner_garbage_collect
// has its code lifted inline and some of then values used within it
// ended up on the stack above buffer that should not be a problem. It
// would merely lead to those being candidate ambiguous pointers.
//

std::jmp_buf* buffer_pointer;

static volatile int volatileVar = 0; 

NOINLINE void garbage_collect()
{   std::jmp_buf buffer;
    buffer_pointer = &buffer;
// This is a silly hack! The idea is that as far as the compiler is
// allowed to assune, each reference to volatileVar might return a different
// value. So a1-a18 all hold notionally independent values. I rather hope
// that many of those will be placed in machine registers, flushing
// any values from the caller to the stack. And because thay are all
// independent each needs its own register!
    int a1 = volatileVar; int a2 = volatileVar; int a3 = volatileVar;
    int a4 = volatileVar; int a5 = volatileVar; int a6 = volatileVar;
    int a7 = volatileVar; int a8 = volatileVar; int a9 = volatileVar;
    int a10 = volatileVar; int a11 = volatileVar; int a12 = volatileVar;
    int a13 = volatileVar; int a14 = volatileVar; int a15 = volatileVar;
    int a16 = volatileVar; int a17 = volatileVar; int a18 = volatileVar;
    for (int i=0; i<1000000; i++)
    {   if (setjmp(buffer) == 0)
        {   C_stackFringe = reinterpret_cast<uintptr_t>(&buffer);
            inner_garbage_collect();
// Now I reference all the variables a1-a18. Because I multiply each
// by a value that is notionally unpredictable I can not perform any
// of this sooner and I really need the value of each variable. So
// storing all of a1-a18 across the call to inner_garbage_collect is
// necessary. Note that what follows is NOT equivalent to
//    volatileVar = (a1*a2*a3*...*a18)*volatileVar;
// because in principle volatileVar might have its value changed by
// external magic between each line. All the code here needs to adhere
// to the rule that there is only one reference to a volatile value
// between any two sequence points. 
            volatileVar = a1*volatileVar;
            volatileVar = a2*volatileVar;
            volatileVar = a3*volatileVar;
            volatileVar = a4*volatileVar;
            volatileVar = a5*volatileVar;
            volatileVar = a6*volatileVar;
            volatileVar = a7*volatileVar;
            volatileVar = a8*volatileVar;
            volatileVar = a9*volatileVar;
            volatileVar = a10*volatileVar;
            volatileVar = a11*volatileVar;
            volatileVar = a12*volatileVar;
            volatileVar = a13*volatileVar;
            volatileVar = a14*volatileVar;
            volatileVar = a15*volatileVar;
            volatileVar = a16*volatileVar;
            volatileVar = a17*volatileVar;
            volatileVar = a18*volatileVar;
            std::longjmp(buffer, 1);
        }
// I "know" that the test on the next line is a tautology so that the
// "loop" here is traversed once not a million times, but the compiler is
// not allowed to be confident of that, so I think it decently ought to
// see a1-a18 as repeatedly used within the loop and hence important values
// to dedicate registers to!
// Of course all I do here is slihtly ridiculous!
        if (volatileVar == volatileVar) break;
    }
}


#ifdef REWORKED
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
//~

#endif // REWORKED

// end of file newcslgc.cpp
