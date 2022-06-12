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
// saturate. The page size is such that just two probes will be enough.
            if (w == ExtendedChunkMax) w = p->chunkStatus[chunkNo -= w-1];
            if (w > ExtendedChunkStart && w <= ExtendedChunkMax)
                w = p->chunkStatus[chunkNo -= w-1];
// Now I am pointing at the start of the chunk. If it is ahead of
// dataEnd it contains live data and also if the chunk is pinned it might
// even if it is way beyond dataEnd.
            if (a < p->dataEnd ||
                w == ExtendedPinnedChunk ||
                w == BasicPinnedChunk)
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

inline bool startOfChunk(unsigned int code)
{   switch (code)
    {
    default:
        return false;
    case BasicChunk:
    case ExtendedChunkStart:
    case ExtendedPinnedChunk:
    case BasicPinnedChunk:
        return true;
    }
}

void findHeadersInChunk(size_t firstChunk, Page* p)
{
// First I need to sort out the start and end addresses associated with
// what may be an extended Chunk. So I will arrange that lastChunk is
// either the number beyond that for the last chunk in the Page or
// is the number for the start of the next chunk.
    size_t lastChunk = firstChunk+1;
    while (lastChunk < sizeof(p->chunkStatus) &&
           !startOfChunk(p->chunkStatus[lastChunk])) lastChunk++;
    uintptr_t firstAddr = addressFromChunkNo(p, firstChunk);
// endAddr is just beyond the last data I need to scan here. Note that
// it can be just beyond the end of the page.
    uintptr_t endAddr   = addressFromChunkNo(p, lastChunk);
// Now I have a chunk delimited, I will parse it so I can identify
// object start addresses.
    uintptr_t s = firstAddr;
    while (s < endAddr)
    {   uintptr_t a = *reinterpret_cast<uintptr_t*>(s);
        size_t len;
// Based on its first word I need to decode the LispObject at address s.
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
// Since this is a Page intended to contain vectors it would be wrong if it
// had any cons cells in it. However in case at some later stage I put
// some cons cells into vector pages I will allow for that case here!
// Get the address of the last word of the object.
        uintptr_t final = s + len - sizeof(LispObject);
// I will sort out the bit-address in the bitmap for the first and last
// words of the object as w1:bit1 and w2:bit2.
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
// I will take special action of the object found is a padder. In that
// case I will clear all the pin bits for addresses within the object,
// because padders can never be pinned.
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
// For other objects I need to test if there are any pin bits at all within
// the object, and if so set one for the first bit while clearing all others.
        else if (w1 == w2)
        {   bool pinFound = (p->currentVecPins[w1] & mask1 & mask2) != 0;
            p->currentVecPins[w1] &= ~(mask1 & mask2);
            if (pinFound)
            {   p->currentVecPins[w1] |= static_cast<uint64_t>(-1) << bit1;
                if (p->pinnedObjects == TAG_FIXNUM)
                {   p->pinnedPages = pinnedPages;
                    pinnedPages = p;
                }
// Record this pinned object in a list of same.
                LispObject z = get2Words();
// The next line is to ensure that the CONS just allocated never gets pinned.
                consCurrent->type = emptyPageType;
                car(z) = s + TAG_FIXNUM;
                cdr(z) = p->pinnedObjects;
                p->pinnedObjects = z + TAG_FIXNUM;
            }
        }
        else
        {
// I need to check if any address in the range s <= x <= final has
// been marked as pinned, and if so clear internal pin bits and set one
// on the header word, and when the pinning bitmap region involves more
// than one word this is a bit more messy.
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

// Here I identify each chunk that may contain pinned data and process it.
// By using ntz() on the words of the bitmap this should be respectably
// cheap.

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

bool evacuateConsPage(Page* p)
{   bool didSomething = false;
    uintptr_t next = p->scanPoint;
// If some of the evacuation here fills up this page iy may cease being
// "current" and then consFringe is liable to get set pointing into
// the next allocated page. That is OK because then the loop here will
// terminate at dataEnd. Note that when I make a page current via
// initConsPage I set dataEnd to its very end, because the "real" end of
// data at that stage will be at fringe. 
    while (next != p->dataEnd && next != consFringe)
    {   if (!consIsPinned(next, p))
        {   LispObject* n = reinterpret_cast<LispObject*>(next);
            switch (*n & 0x1f)
            {
            case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                didSomething = true;
                evacuate(*(n+1));
                [[fallthrough]];
            case 0x12: // 0b10010: // Header for bit-vector
                [[fallthrough]];
            case 0x1a: // 0b11010: // Header for vector of binary data
                break;
            default:
                didSomething = true;
                evacuate(*n);      // must be a cons cell
                evacuate(*(n+1));
                break;
            }
        }
        next += 2*sizeof(LispObject);
    }
    p->scanPoint = next;
    return didSomething;
}

bool evacuateVecPage(Page* p)
{   uintptr_t next = p->scanPoint;
    bool didSomething = false;
// Ugh! Here it could be that this point is within a chunk (or extended
// chunk) because it was left over from a previous pass. So I need to
// identify the chubk that it is within. Well to be a little more pedantic
// I first need to find the start of the relevant chunk.
    size_t firstChunk;
    while (next != p->dataEnd && next != vecFringe)
    {   firstChunk = chunkNoFromAddress(p, next);
        int w = p->chunkStatus[firstChunk];
        if (w == ExtendedChunkMax) w = p->chunkStatus[firstChunk -= w-1];
        if (w > ExtendedChunkStart && w <= ExtendedChunkMax)
            w = p->chunkStatus[firstChunk -= w-1];
// Now firstChunk is set up OK.
        size_t lastChunk = firstChunk+1;
        while (lastChunk < sizeof(p->chunkStatus) &&
               !startOfChunk(p->chunkStatus[lastChunk])) lastChunk++;
        uintptr_t endAddress   = addressFromChunkNo(p, lastChunk);
        while (next != endAddress)     // scan this chunk
        {   if (next == p->dataEnd || next == vecFringe)
            {   p->scanPoint = next;
                return didSomething;
            }
// I will now identify the sort of item present at location *next.
            didSomething = true;
            uintptr_t a = *reinterpret_cast<uintptr_t*>(next);
            size_t len, len1;
            switch (a & 0x1f)
            {
            case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                                   // Note TYPE_STREAM is in with this.
                len = length_of_header(a);
                if (is_mixed_header(a)) len1 = 4*CELL;
                else len1 = len;
                my_assert(len != 0, "lisp vector size zero");
                for (size_t i = CELL; i<len1; i += CELL)
                    evacuate(*reinterpret_cast<LispObject*>(next+i));
                break;

            case 0x12: // 0b10010: // Header for bit-vector
                [[fallthrough]];
            case 0x1a: // 0b11010: // Header of vector holding binary data
                len = doubleword_align_up(length_of_header(a));
                break;

            case 0x02: // 0b00010: // Symbol headers, char literals etc.
                if (is_symbol_header(a))
                {   len = symhdr_length;
                    Symbol_Head* s = reinterpret_cast<Symbol_Head*>(next);
                    evacuate(s->value);
                    evacuate(s->env);
                    evacuate(s->plist);
                    evacuate(s->fastgets);
                    evacuate(s->package);
                    evacuate(s->pname);
                    break;
                }
                [[fallthrough]];
            default:               // None of the above cases...
                len = 2*CELL;      // ... must be a CONS cell.
                evacuate(car(next));
                evacuate(cdr(next));
                break;
            }
            next += len;
        }
// I get here at the end of the current chunk.
    }
    return didSomething;
}

void evacuateFromCopiedData()
{   for (;;)
    {
// First I will deal with any pages that had become full. Those are easy!
        while (pendingPages != nullptr)
        {   Page* p = pendingPages;
            pendingPages = p->pendingPages;
            switch (p->type)
            {
            case consPageType:
                evacuateConsPage(p);
                break;
            case vecPageType:
                evacuateVecPage(p);
                break;
            default:
                my_abort("bad page type in evacuateFromCopiedData");
            }
        }
// Now I have a current Cons and a current Vec one. I will scan the current
// Cons page. Doing so may cause it to become full. That puts it on the
// pending chain and allocates a fresh consCurrent. I continue scanning it
// and when I reach the end I will naturally set its scanPoint to the end of
// the page where I terminated. So when it is retrieved from the pending
// queue it will be found that nothing more has to happen.
// However the more interesting case is if scanning the consCurrent page
// terminates because all the cons style data in it has been processed
// but there is still space in the page.
// I will return true if the scan needed to evacuate anything even if
// the evacuation did not actually do anything, and so the whole function
// can return false if there was in fact no additional data in to be
// looked at.
        bool didSomething = evacuateConsPage(consCurrent);
// Now similarly for the vector page. Well the pain here is that scanning
// the vector page might put more info in the consCurrent page or even make
// it overflow, even if the vector page does not become full. So I must
// return false either if the vector page fills up or if any new conses are
// created.
        if (evacuateVecPage(vecCurrent)) didSomething = true;
// If neither scanning consCurrent nor vecCurrent did anything at all then
// pendingPages will still be left empty and there is nothing left to do.
// If either of them did do something then at least that one will have
// moved its scanPoint on, so when I re-try it will continue in a useful
// manner and eventually things will converge.
        if (!didSomething) break;
    }
}

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
    grabFreshPage(consPageType);
    consCurrent->type = emptyPageType;
    grabFreshPage(vecPageType);
// Now I can scan the stack and mark up pinned items. This will build
// up a chain of pages still 
    identifyPinnedItems();
    findHeadersOfPinnedItems();
// Now I have finished identifying all the pinned objects, so I can make
// pages that contain lists of them proper again.
    for (Page* p=consPages; p!=nullptr; p=p->chain)
        p->type = consPageType;
    pendingPages = nullptr;
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
            volatileVar = a1*volatileVar;   volatileVar = a2*volatileVar;
            volatileVar = a3*volatileVar;   volatileVar = a4*volatileVar;
            volatileVar = a5*volatileVar;   volatileVar = a6*volatileVar;
            volatileVar = a7*volatileVar;   volatileVar = a8*volatileVar;
            volatileVar = a9*volatileVar;   volatileVar = a10*volatileVar;
            volatileVar = a11*volatileVar;  volatileVar = a12*volatileVar;
            volatileVar = a13*volatileVar;  volatileVar = a14*volatileVar;
            volatileVar = a15*volatileVar;  volatileVar = a16*volatileVar;
            volatileVar = a17*volatileVar;  volatileVar = a18*volatileVar;
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

// end of file newcslgc.cpp
