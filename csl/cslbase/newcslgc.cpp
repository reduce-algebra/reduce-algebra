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

#define DEFINE_LIST_BASES 1

#include "headers.h"
#include "validate.h"

void check_standard_input(const char* msg="check_standard_input") // @@@@@@@@@@@@@@
{   zprintf("****** %s *****\n", msg);
    LispObject a = terminal_io;
    zprintf("terminal_io = %a(%a) = ", a, qheader(a)); simple_print(a);
    a = qvalue(a);
    zprintf("qvalue terminal_io = %a(%a) = ", a, vechdr(a)); simple_print(a);
    a = lisp_terminal_io;
    zprintf("lisp_terminal_io = %a(%a) = ", a, vechdr(a)); simple_print(a);
    a = standard_input;
    zprintf("standard_input = %a(%a) = ", a, qheader(a)); simple_print(a);
    a = qvalue(a);
    zprintf("qvalue standard_input = %a(%a) = ", a, vechdr(a)); simple_print(a);
    a = lisp_standard_input;
    zprintf("lisp_standard_input = %a(%a) = ", a, vechdr(a)); simple_print(a);
    LispObject b = stream_read_data(a);
    zprintf("read_data lisp_standard_input = %a(%a) = ", b, qheader(b)); simple_print(b);
    b = qvalue(b);
    zprintf("value read_data lisp_standard_input= %a(%a) = ", b, vechdr(b)); simple_print(b);
    visited.clear();
    validateObject(b, true);
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
    uintptr_t uv = csl_cast<uintptr_t>(v);
    LispObject h = *v;
    switch (h & 0x1f)
    {
// Here is is immaterial whether a vector holds binary or Lisp data.
        case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                               // Note TYPE_STREAM is in with this.
            FALLTHROUGH;
        case 0x12: // 0b10010: // Header for bit-vector
            FALLTHROUGH;
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

std::unordered_set<uintptr_t> allPinned;

// The ambiguous value (a) seems to point within the page (p). I do
// different things based on the sort of page involved... pointers into
// CONS pages will be the simplest to handle.

void blurp()
{   zprintf("\n\n\nblurp\n\n\n");
}

void processAmbiguousInPage(Page* p, uintptr_t a)
{   uintptr_t dataStart;
//    if ((a & ~TAG_BITS) == (lisp_standard_input & ~TAG_BITS))
//    {   blurp();
//    }
    size_t chunkNo;
    switch (p->type)
    {
    case emptyPageType:
// A "pointer" into an empty page is of no concern to anybody.
        return;
    case consPageType:
// This is the simplest case, mainly because all objects in the page
// are neatly aligned on 2-cell boundaries.
        a = a & -(2*sizeof(LispObject));   // align the pointer.
        dataStart = offsetToCons(0, p);
// If the ambigious pointer points before any real data in the page
// it is invalid. If it points before consDataEnd it is valid, but this
// needs a small extra bit of commentary. Either it is a pointer to
// recently allocated data in the page, or it is to some item previously
// pinned and which is still to be pinned. Finally if it is above
// consDataEnd then it is only valid if it refers to data that had
// previously been pinned. Well one more issue to discuss to show that
// it has been considered. A previous GC can have left padder items in the
// cons heap where cells had been pinned 2 GCs ago but were not at the last
// GC. Well they will not have consIsPinned set and so an (ambiguous)
// reference to them now is not about to pin them. So I do not need an
// explicit check for padders here.
        if (a < dataStart) return;
        else if ((a < p->dataEnd ||
                  consIsPinned(a, p)) &&
                 !consIsNewPinned(a, p))   // detect first time noticed.
        {   my_assert(!consIsNewPinned(a, p), __WHERE__);
            consSetNewPinned(a, p);
            zprintf("set new cons pin %a\n", a);
// The first time I find an object pinned on a page I will put that page
// in a chain of ones containing pinned material. 
            if (!p->hasPinned)
            {   p->hasPinned = true;
                p->pinnedPages = pinnedPages;
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
            my_assert(allPinned.count(a) == 0, "double pinning");
            allPinned.insert(a);
            LispObject z = get2Words();
            car(z) = a + TAG_FIXNUM;
            cdr(z) = p->pinnedObjects;
            p->pinnedObjects = z + TAG_FIXNUM;
        }
        return;
    case vecPageType:
// Pointers into vector pages can refer to any individual cell. The biggest
// cause of pain here is that the pointers may refer to addresses within
// objects (as distinct from just identifying the object header). I do
// not have a trivial way to tell where objects start, so I will set
// mark bits now even when they are not on object headers and correct
// in a later phase. This is where I rely on "chunks" and I will view
// an ambiguous pointer as "provisionally valid" either if it is at an
// address before vecDataEnd or if it is into a chunk beyond that where
// the chunkStatus entry indicates that it contains at least some old
// pinned material. When I set a mark bit I will tag the chunk as
// "of interest" in another little bitmap, and push the Page
// onto a chain of ones to deal with later.
        a = a & -(sizeof(LispObject));   // align the pointer.
        dataStart = offsetToVec(0, p);
        if (a < dataStart) return;
        chunkNo = chunkNoFromAddress(p, a);
// The pointer may be valid either if it refers to an address below the
// fringe or if it is withing a chunk that had been pinned during an
// earlier GC. I can use chunkSeqNo to adjust so I point at the start of
// and extended chunk.
        chunkNo -= p->chunkSeqNo[chunkNo];
// Now I am pointing at the start of the chunk. If it is ahead of
// dataEnd it contains live data and also if the chunk is pinned it might
// even if it is way beyond dataEnd. Note that "pinned" here has to mean
// "pinned by a previous GC" not this one.
        if (a < p->dataEnd ||
            chunkIsPinned(p, chunkNo))
        {
// Now I tag the Chunk as (potentially) pinned. It will not actually be pinned
// if the dodgy address points within a padder item in it. Set a mark in
// the "new" chunk pinning map and on the first occasion that is done chain
// the page as having new pinned chunks - well only potentially because
// the address noticed may refer within a padder. A later pass will
// need to scan potentially pinned chunks and tidy things up.
            if (!chunkIsNewPinned(p, chunkNo))
            {   chunkSetNewPinned(p, chunkNo);
// ... and note when Pages contain such material.
                if (!p->potentiallyPinnedFlag)
                {   p->potentiallyPinnedFlag = true;
                    p->potentiallyPinnedChain = potentiallyPinned;
                    potentiallyPinned = p;
                }
            }
// I set a mark on the address involved even though that may be within
// rather than at the head of an object.
            vecSetNewPinned(a, p);
            zprintf("mark new vec pin %a potentially within object\n", a);
        }
        return;
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

size_t stackCount = 0;

void processAmbiguousValue(uintptr_t a)
{
// I find the Page (if any!) the value is in. That Page may be empty,
// one containing old pinned stuff or one full of live data.
    zprintf("ON STACK %d: %a\n", stackCount++, a);
    Page* p = findPage(a);
    if (p!=nullptr) processAmbiguousInPage(p, a);
}

// The following function scans the stack for each thread. The address
// sanitizer gets upset at this when it looks at return addresses and
// the like, so I need to disable it here... After all looking at locations
// on the stack but between the proper stack frames is indeed a bit
// "dodgy"!
//
// A more agressive "conservative" regime could scan statically and
// dynamically allocated memory in general, and if multiple threads were
// present would look at the stacks used by each thread. A particular use
// case for additional generality would be to support more general use of
// Lisp pointers by "foreign" code. I am not moving in that direction (yet?).

// I need "NO_SANITIZE_ADDRESS" because when I scan the stack I will
// access return addresses, stack pointer chains and the like. Doing so
// would normally be a sign of buffer overflow or malice, and so helpful
// "sanitize" options that try to protect against suchlike would get
// triggered.

NO_SANITIZE_ADDRESS
void identifyPinnedItems()
{
#ifdef DEBUG
// Just while I develop the code I will have some extra "ambiguous" pointers
// that I have rather direct control over. They may help me to test things.
    for (int i=0; i<10; i++)
        processAmbiguousValue(ambiguous[i]);
#endif // DEBUG
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
    zprintf("Scan C stack from %x to %x\n", C_stackFringe, C_stackBase);
    for (uintptr_t s=C_stackFringe; s<C_stackBase; s+=sizeof(uintptr_t))
        processAmbiguousValue(*csl_cast<uintptr_t*>(s));
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
// newVecPins[] bitmap should identify where ambiguous pointers
// fall. So as I parse and identify an object I need to sort out the
// range of bits within that map and test them. If any are set then I
// clear any that are not to the header of the object and set one on
// the header (unless the object is a padder).

void findHeadersInChunk(size_t firstChunk, size_t lastChunk, Page* p)
{
    uintptr_t firstAddr = addressFromChunkNo(p, firstChunk);
// lastAddr is just beyond the last data I need to scan here. Note that
// it can be just beyond the end of the page.
    uintptr_t lastAddr   = addressFromChunkNo(p, lastChunk);
// Now I have a chunk delimited, I will parse it so I can identify
// object start addresses.
    uintptr_t s = firstAddr;
    while (s < lastAddr)
    {   uintptr_t h = indirect(s);
        size_t len;
// Based on its first word I need to decode the LispObject at address s.
// In many cases it will have an explicit header word that contains length
// information. Here I do not need to worry whether vectors contain
// binary data or more Lisp pointers - all I need to sort out is the
// length of the object concerned.
        switch (h & 0x1f)
        {
    case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                           // Note TYPE_STREAM is in with this.
            FALLTHROUGH;
    case 0x12: // 0b10010: // Header for bit-vector
            FALLTHROUGH;
    case 0x1a: // 0b11010: // Header for vector of binary data
            len = doubleword_align_up(length_of_header(h));
            my_assert(len > 0 && len<pageSize, __WHERE__);
            if (testBits(p->newVecPins,
                         vecToOffset(s, p),
                         len/sizeof(LispObject)))
            {   zprintf("Pinned item head at %a: ", s);
                simple_print(s+TAG_VECTOR);  // well floats & bignums may mess up printing here
            }
            break;
    case 0x02: // 0b00010: // Symbol headers, char literals etc.
// The code is either for the header of a symbol or for some sort
// of immediate data, and in the latter case the object must be
// h CONS cell.
            if (is_symbol_header(h)) len = symhdr_length;
            else len = 2*CELL;
            break;
    default:                 // None of the above cases...
// Since this is a Page intended to contain vectors it would be wrong if it
// had any cons cells in it. However in case at some later stage I put
// some cons cells into vector pages I will allow for that case here!
            if (testBits(p->newVecPins, vecToOffset(s, p), len/sizeof(LispObject)))
            {   zprintf("Pinned item head at %a: ", s);
                simple_print(is_symbol_header(h) ? s+TAG_SYMBOL:s);
            }
            len = 2*CELL;    // ... must be a CONS cell.
            break;
        }
        size_t o1 = vecToOffset(s, p);
        zprintf("o1 = %d\n", o1);
// I will take special action of the object found is a padder. In that
// case I will clear all the pin bits for addresses within the object,
// because padders can never be pinned.
        if (is_padder_header(h))
        {   clearBits(p->newVecPins, o1, len/sizeof(LispObject));
            s += len;
            continue;
        }
// For other objects I need to test if there are any pin bits at all within
// the object, and if so set one for the first bit while clearing all others.
        else if (testBits(p->newVecPins, o1, len/sizeof(LispObject)))
        {
// Move the pin bit so it is on the head of the item.
            clearBits(p->newVecPins, o1, len/sizeof(LispObject));
            setBit(p->newVecPins, o1);
            if (!p->hasPinned)
            {   p->hasPinned = true;
                p->pinnedPages = pinnedPages;
                pinnedPages = p;
            }
            my_assert(allPinned.count(s) == 0, "double pinning");
            allPinned.insert(s);
// Record this pinned object in a list of same.
            LispObject z = get2Words();
            car(z) = s + TAG_FIXNUM;
            cdr(z) = p->pinnedObjects;
            p->pinnedObjects = z + TAG_FIXNUM;
            if (!p->hasVecPins)
            {   p->hasVecPins = true;
                p->oldVecPinPages = oldVecPinPages;
                oldVecPinPages = p;
            }
        }
        zprintf("o1 bis = %d\n", o1);
        s += len;
    }
}

// Here I identify each chunk that may contain pinned data and process it.
// By using ntz() on the words of the bitmap this should be respectably
// cheap. Note that this only scans chunks where there is a bit of pinning
// in the current GC, ie newVecPins[]. All things on vecPins[] left over
// from the previous GC will already just identify item heads. So this
// only needs to process pages and chunks with pinning in the most recent GC.
// It does three things:
//   When a (new) pin is on the middle of an object it migrates it so
//     that it is on the header word of the object.
//   If a new pin is then on a padding object it is removed.
//   For items that are in fact pinned it sticks them on a "pinned object
//     chain" associated with the page they are in, that chain being
//     created in the new half-space.
//   If a genuine new pin is set it ensures that the page is on pinnedPages.

void findHeadersOfPinnedItems()
{   while (potentiallyPinned != nullptr)
    {   size_t pinnedChunk = 0;
        while ((pinnedChunk = nextOneBit(potentiallyPinned->chunkBitmap,
                                         chunkBitmapSize,
                                         pinnedChunk)) != SIZE_MAX)
        {   // Deal with a chunk that may still be pinned
            size_t pinEnd = pinnedChunk +
                            potentiallyPinned->chunkLength[pinnedChunk];
            zprintf("find headers in pinned chunk from %a to %a\n",
                addressFromChunkNo(potentiallyPinned, pinnedChunk),
                addressFromChunkNo(potentiallyPinned,  pinEnd));
            findHeadersInChunk(pinnedChunk, pinEnd, potentiallyPinned);
            pinnedChunk = pinEnd;
        }
        potentiallyPinned->potentiallyPinnedFlag = false;
        potentiallyPinned = potentiallyPinned->potentiallyPinnedChain;
    }
}

// This will turn back into std::memcpy when I have finished debugging, but
// is here now so that when watchpoints are triggered within it the gdb
// record is easier for me to traverse.

void csl_memcpy(void* vdest, void* vsrc, size_t len)
{   char* dest = (char*)vdest;
    char* src = (char*)vsrc;
    for (size_t i=0; i<len; i++)
        dest[i] = src[i];
}

void evacuate(LispObject &x)
{
// Here x refers to x location that is x list-base, ie it contains
// x valid Lisp object, but also the value of x is the LispObject
// held in that location. I want to arrange that the object and all its
// components are moved to the new half space, and (if necessary) the
// list base is updated to refer to the copy and x forwarding pointer is left
// where the original had been. The procedure is:
//   x is the object that may need to be copied.
//   If x is tagged as immediate data or is the special case NIL do nothing.
//   [now x is some sort of tagged pointer]
//   If *x is x forwarding pointer replace the list base with the
//      object referred to, reconstructing suitable tag bits.
//   If x refers to material that is pinned do nothing.
//   Determine the length, b, of the object that x refers to.
//   Allocate b byte in the new space and do x simple binary copy of all
//      of object x to there.
//   Write in x forwarding pointer.
//   Update the list-base to refer to the copy.
// Note that this is x shallow copy operation. A later stage must perform
// x linear scan of the newly copied material. That stage is not discussed
// here because this function does not directly cause it to happen.
    if ((x & ~TAG_BITS) == (lisp_standard_input & ~TAG_BITS))
    {   blurp();
    }
    my_assert(x != 0, "zero word in scanning");
    my_assert(!is_forward(x), "forwarding ptr in scanning");
    zprintf("evacuating %a %s\n", x, objectType(x));
    if (is_immediate(x) || x == nil) return;
// If something is not immediate it must be x pointer!
    LispObject* untagged_x = csl_cast<LispObject*>(x & ~TAG_BITS);
    LispObject hdr = *untagged_x;
    LispObject cpy;
    if (is_forward(hdr))
    {   x = hdr - TAG_FORWARD + (x & TAG_BITS);
        my_assert(!is_forward(x), "forwarding ptr in scanning");
        return;
    }
// Now I will need to make x copy of the item (unless it is pinned).
    size_t len;
    if (is_cons(x))
    {   if (consIsNewPinned(x)) return;
        len = 2*CELL;
        cpy = get2Words();
    }
    else if (is_symbol(x))
    {   if (vecIsNewPinned(x)) return;
        len = symhdr_length;
        cpy = getNBytes(len);
    }
    else if (SIXTY_FOUR_BIT && hdr == DOUBLE_FLOAT_HEADER)
    {   if (consIsPinned(x)) return;
        len = 16;
        cpy = get2Words();
    }
    else
    {   if (vecIsNewPinned(x)) return;
        len = doubleword_align_up(length_of_header(hdr));
        cpy = getNBytes(len);
    }
    csl_memcpy(csl_cast<void*>(cpy), untagged_x, len);
    *untagged_x = TAG_FORWARD + cpy;
    x = cpy + (x & TAG_BITS);
    zprintf("Evacuate %a to %a\n", untagged_x, x);
    my_assert(!is_forward(x), "forwarding ptr in scanning");
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
    for (LispObject* p:list_bases) evacuate(*p);
    for (LispObject* sp=stack;
         sp>csl_cast<LispObject*>(stackBase); sp--) evacuate(*sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != nullptr)
    {   for (size_t i=1; i<=repeat_count; i++)
            evacuate(repeat_heap[i]);
    }
}

void showPinnedItems()
{   for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
    {   for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                        c!=0;
                        c=cdr(c)-TAG_FIXNUM)
        {   LispObject next = car(c)-TAG_FIXNUM;
            zprintf("Pinned item at %a\n", next);
        }
    }
}

// There is a "jolly" issue here that it took me a while to spot. Let me
// first note that I should not evacuate any location twice.
// Well here I look at each pinned object. Although the pointer is
// ambiguous the object is well formed and it may be that the only
// reference to it is from an ambiguous pointer. So I need to evacuate
// and fields within it.

void evacuateFromPinnedItems()
{   for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
    {   for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                        c!=0;
                        c=cdr(c)-TAG_FIXNUM)
        {   LispObject next = car(c)-TAG_FIXNUM;
            Header a = *csl_cast<Header*>(next);
            size_t len, len1;
// Now based on the low 6 bits of the first word of the object I sort
// out whether it is a vector containing Lisp data, a vector containing
// binary data (including strings and bignums) or a symbol. If none of
// those then it will be a CONS cell.
            switch (a & 0x1f)
            {
            case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                     // Note TYPE_STREAM etc is in with this.
                len = length_of_header(a);
                if (is_mixed_header(a)) len1 = 4*CELL;
                else len1 = len;
                my_assert(len != 0, "lisp vector size zero");
                for (size_t i = CELL; i<len1; i += CELL)
                    evacuate(*csl_cast<LispObject*>(next+i));
                continue;

            case 0x12: // 0b10010:   // Header for bit-vector
                FALLTHROUGH;
            case 0x1a: // 0b11010:   // Header for vector holding binary data
                continue;

            case 0x02: // 0b00010:   // Symbol headers plus char literals etc
                if (is_symbol_header(a))
                {   Symbol_Head* s = csl_cast<Symbol_Head*>(next);
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
                if (car(next) == 0)
                {   zprintf("@@@Zero word at %a\n", next);
                    zprintf("@@@next=%a vecCurrent=%a\n", next, vecCurrent);
                    displayAllPages("Line 586 in newcslgc.cpp"); // DEBUG
                    my_abort("zero word in evacuateFromPinnedItems");
                }
                evacuate(car(next));
                evacuate(cdr(next));
                continue;
            }
        }
    }
}

// evacuateConsPage is only ever called on a page that is part of the
// "new half space" that the GC has been copying material into. When it
// was allocated that page might have had some pinned material in it, and
// at that time there was a chain of pointers to allow allocation around
// them. By now that chain has been overwritten by copied data. However the
// (old) pin bits will be set on relevant cells. If any of those are
// still pinned their contents get evacuated. If any are no longer pinned
// but remain alive then they get evacuated when a reference to them is
// processed. If they are not used they will need to be replaced by padders
// after all evacuation has happened.

bool evacuateConsPage(Page* p)
{   bool didSomething = false;
    displayConsPage(p);
    uintptr_t next = p->scanPoint;
    zprintf("cons scanPoint = %a\n", next);
// If some of the evacuation here fills up this page it may cease being
// "current" and then consFringe is liable to get set pointing into
// the next allocated page. That is OK because then the loop here will
// terminate at dataEnd. Note that when I make a page current via
// initConsPage I set dataEnd to its very end, because the "real" end of
// data at that stage will be at fringe. 
    while (next != p->dataEnd && next != consFringe)
    {
// NB test the OLD pin flag here. And I know which page I am in so I
// use the 2-argument version of consIsPinned().
        if (!consIsPinned(next, p))  // Pinned things evacuated elsewhere
        {   LispObject* n = csl_cast<LispObject*>(next);
            if (*n != DOUBLE_FLOAT_HEADER &&
                *n != CONS_PADDER_HEADER)  // Note special cases.
            {   didSomething = true;
                evacuate(*n);      // must be a cons cell
                evacuate(*(n+1));
            }
        }
        next += 2*sizeof(LispObject);
    }
    p->scanPoint = next;
    zprintf("end with cons scanPoint = %a\n", next);
    displayConsPage(p);
    return didSomething;
}

// Pages only become vector ones when made into vecCurrent. Well borrowed
// pages do not count. For vecCurrent there must be data contiguously filling
// all non-pinned chunks up as far as vecFringe. For all other pages
// there must be data filling all chunks up to dataEnd, which is the
// address just beyond the last chunk that was in use when the Page graduated
// from being vecCurrent. When vecCurrent is being scanned it is possible
// for evacuations to cause vecFringe to move and for the page to become
// stable rather than current. When and if that happens dataEnd gets set
// and so the scanning will stop there. To arrange that scanning is not
// terminated based on a check of dataEnd when it should not be, the
// vecCurrent page will have that field initialised to the end of the Page. 

// Observe that the way that a vector page is split into chunks and
// extended chunks makes the treatment here a lot messier than for cons
// pages even before one start to worry about the different sorts of
// vector where some have lisp and others binary content.

bool evacuateVecPage(Page* p)
{   uintptr_t next = p->scanPoint;
    displayVecPage(p);
    zprintf("~#evacVecPage %a, scanPoint=%a vecFringe=%a dataEnd=%a\n",
        p, next, vecFringe, p->dataEnd);
    if (next == p->dataEnd || next == vecFringe) return false;
    bool didSomething = false;
// Ugh! Here it could be that this point is within a chunk (or extended
// chunk) because it was left over from a previous pass. So I need to
// identify the chunk that it is within. Well to be a little more pedantic
// I first need to find the start of the relevant chunk.
    size_t firstChunk = chunkNoFromAddress(p, next);
    firstChunk -= p->chunkSeqNo[firstChunk];
// Now firstChunk is set up as the start of the chunk I am within.
// From now on the chunks and extended chunks all align nicely.
    size_t lastChunk = firstChunk + p->chunkLength[firstChunk];
    zprintf("evacVecPage %a, scanPoint=%a vecFringe=%a dataEnd=%a\n",
        p, next, vecFringe, p->dataEnd);
    while (next != p->dataEnd && next != vecFringe)
    {
// Chunks that contain pinned material are an issue here. Well ones
// with chunkStatus as PinnedChunkStart can only have had that set by
// a previous GC, and so the only data within them will be pinned. That
// was evacuated by other code than this. The rest of this page should not
// have any pinned stuff in it at all.
        if (chunkIsPinned(p, firstChunk))
            next = addressFromChunkNo(p, lastChunk);
        else
        {   uintptr_t chunkEnd = addressFromChunkNo(p, lastChunk);
            while (next != chunkEnd && next != vecFringe)
            {   size_t len, len1;
                uintptr_t h = *csl_cast<uintptr_t*>(next);
                switch (h & 0x1f)
                {
                case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                                       // Note TYPE_STREAM is in with this.
                    len = length_of_header(h);
                    if (is_mixed_header(h)) len1 = 4*CELL;
                    else len1 = len;
                    my_assert(len != 0, "lisp vector size zero");
                    for (size_t i=CELL; i<len1; i+=CELL)
                        evacuate(*csl_cast<LispObject*>(next+i));
                    didSomething = true;
                    break;

                case 0x12: // 0b10010: // Header for bit-vector
                    FALLTHROUGH;
                case 0x1a: // 0b11010: // Header of vector holding binary data
                    len = doubleword_align_up(length_of_header(h));
                    my_assert(len != 0, "lisp vector size zero");
                    break;

                case 0x02: // 0b00010: // Symbol headers, char literals etc.
                    if (is_symbol_header(h))
                    {   len = symhdr_length;
                        Symbol_Head* s = csl_cast<Symbol_Head*>(next);
                        evacuate(s->value);
                        evacuate(s->env);
                        evacuate(s->plist);
                        evacuate(s->fastgets);
                        evacuate(s->package);
                        evacuate(s->pname);
                        didSomething = true;
                        break;
                    }
                    FALLTHROUGH;
                default:               // None of the above cases...
                    my_abort("cons cell in vec page");
                }
                my_assert(len != 0, "something of size zero");
                next += len;
            }
        }
// I get here at the end of the current chunk, so move on to the next one.
        firstChunk = lastChunk;
        lastChunk = firstChunk + p->chunkLength[firstChunk];
    }
    p->scanPoint = next;
    displayVecPage(p);
    return didSomething;
}

void evacuateFromCopiedData()
{   for (;;)
    {
// First I will deal with any pages that had become full. Those are easy!
        while (pendingPages != nullptr)
        {   Page* p = pendingPages;
            pendingPages = p->pendingPages;
            zprintf("Now evacuate contents of pending page %a\n", p);
            switch (p->type)
            {
            case consPageType:
                evacuateConsPage(p);
                validateAll("evacConsPage done", true);
                break;
            case vecPageType:
                evacuateVecPage(p);
                validateAll("evacVecPage done", true);
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
        zprintf("Now evacuate current Cons page %a\n", consCurrent);
        bool didSomething = evacuateConsPage(consCurrent);
        validateAll("evacConsPage", true);
// Now similarly for the vector page. Well the pain here is that scanning
// the vector page might put more info in the consCurrent page or even make
// it overflow, even if the vector page does not become full. So I must
// return false either if the vector page fills up or if any new conses are
// created.
        zprintf("Now evacuate current Vec page %a\n", vecCurrent);
        if (evacuateVecPage(vecCurrent)) didSomething = true;
        validateAll("evacVecPage", true);
// If neither scanning consCurrent nor vecCurrent did anything at all then
// pendingPages will still be left empty and there is nothing left to do.
// If either of them did do something then at least that one will have
// moved its scanPoint on, so when I re-try it will continue in a useful
// manner and eventually things will converge.
        zprintf("didSomething = %s\n", didSomething);
        if (!didSomething) break;
    }
    my_assert(pendingPages == nullptr, "pendingPages");
}

// Iteration over a bitmap: I have bitmaps the record which items
// are pinned and I wish to process just the items as identified in the
// bitmaps. I can scan using the "number-of-trailing-zeros" function to
// identify the next such item. The code I have here returns a value
// static_cast<size_t>(-1) when there are no more pin bits present.

uint64_t* bitmapPointer;
size_t    bitmapSize;

size_t    bitmapWordPos;
uint64_t  bitmapWord;

// In fact the bitmaps that I use cover the whole of the Page, but the
// start of the page is filled up with for instance the bitmaps and so
// should never be tagged. I could therefore improve this a bit by
// starting my scan a little in to the start of the map. I avoid that for
// the present in the name of simplicity.

void startBitmapScan(uint64_t* p, size_t n)
{   bitmapPointer = p;
    my_assert(n > 0, "a bitmap must have at least one word in it");
    bitmapSize    = n;
    bitmapWordPos = 0;
    bitmapWord    = bitmapPointer[bitmapWordPos];
}

static const uint64_t one64 = 1;
static const size_t   badSize = -1;

size_t nextInBitmap()
{   if (bitmapWord != 0)             // One or more bits left in current word.
    {   int n = ntz(bitmapWord);     // ... use the lowest one.
        bitmapWord &= ~(one64 << n); // Clear it.
        return 64*bitmapWordPos + n; // Return an overall offset.
    }
    do                               // Find next non-zero word.
    {   if (bitmapWordPos == bitmapSize-1) return badSize;
        bitmapWordPos++;
        bitmapWord = bitmapPointer[bitmapWordPos];
    } while (bitmapWord == 0);
    int n = ntz(bitmapWord);         // Report the lowesxt bit in that word.
    bitmapWord &= ~(one64 << n);
    return 64*bitmapWordPos + n;
}

// These version convert from the index values reported by nextInBitmap()
// into addresses within a Page. I have to have different versions for
// Cons and Vec pages because the resolution used in the bitmaps
// are different in the two cases.

inline uintptr_t nextInConsBitmap(Page* p)
{   size_t o = nextInBitmap();
    if (o == badSize) return 0;
    return offsetToCons(o, p);
}

inline uintptr_t nextInVecBitmap(Page* p)
{   size_t o = nextInBitmap();
    if (o == badSize) return 0;
    return csl_cast<uintptr_t>(p) + sizeof(LispObject)*o;
}

// Here I need to look at xPinPages because some of the pages may now
// have fewer pinned items and xPages because some of them may now
// have pinned items. I must create or re-create the layout needed
// for allocatiion based on the newer version of pin information that
// I have.
// As a reminder, in a cons page the structure for a page with some pinned
// stuff is as follows:
//     (1) cells that are pinned must not be used.
//     (2) Thus the first location available for use will be the
//         first unpinned cell. Before use that contains the address
//         of the next pinned cell (or the end of the page if there is
//         no more pinning). This value can be moved to consLimit.
// For a vector page something of the same style applies but for chunks
// not cells and with the additional complication of extended chunks as
// identified using chunkStatus, and in vecPinPages there can be pages
// with chunks that used to contain pinned material but which now do not.
// If I was really keen I could note that an extended chunk might have
// a pinned item towards its end but the initial large vector that led it
// to being big is not (now) pinned, and in that case I could demote it
// to a sequence of basic chunks...

// The next two return a count of the number of pinned items present.

size_t rePinOneConsPage(Page* p)
{
// Before I mess with the pin maps I want to arrange that every
// cell that has an old pin but not a new one gets a padder written in.
    size_t loc=0;
    while ((loc = nextOneBit(p->consPins, consPinSize, loc)) != SIZE_MAX)
    {   uintptr_t v = offsetToCons(loc, p);
        if (!consIsNewPinned(v, p)) car(v) = CONS_PADDER_HEADER;
        loc++;
    }
    std::memcpy(p->consPins,
                p->newConsPins,
                consPinBytes);
    std::memset(p->newConsPins, 0, consPinBytes);
    uintptr_t a = offsetToCons(0, p);
    size_t nPins = 0;
    zprintf("rePin from %a to %a\n", a, csl_cast<uintptr_t>(p+1));
    while (a != offsetToCons(0, p+1) &&
           consIsPinned(a, p))
    {   zprintf("!!beginPin %a %s\n", a, consIsPinned(a, p));
        a += sizeof(ConsCell);
        nPins++;
    }
// I have now just scanned past any initial pinned items in the Page.
    if (a == csl_cast<uintptr_t>(p+1)) return nPins;
    uintptr_t base = a;
// At present this is coded by looking at each individual cons cell. Once
// I have debugged things using this version I can use ntz() to search for
// pinned items 64-cells at a time in the bitmap, thereby speeding this
// up quite a lot. But this version is simpler so I use it first.

    while (a != csl_cast<uintptr_t>(p+1))
    {   //-- if ((a & 0xffff) == 0) zprintf("check at %a\n", a);
        if (consIsPinned(a, p))
        {   car(base) = a;
            zprintf("!!startPin at %a\n", a);
            while (a != csl_cast<uintptr_t>(p+1) &&
                   consIsPinned(a, p))
            {   a += sizeof(ConsCell);
                nPins++;
            }
            base = a;
        }
        else a += sizeof(ConsCell);
    }
    car(base) = a;
// Well here is a loop using the bitmaps and displaying where pinned items are!
// It should notice just the same locations as are detected above!
    startBitmapScan(p->consPins, consPinSize);
    uintptr_t nextPin;
    while ((nextPin = nextInConsBitmap(p)) != 0)
    {   zprintf("!!Pinned item at %a\n", nextPin);
    }
    return nPins;
}

void rePinConsCurrent(Page* p)
{   size_t loc=0;
    while ((loc = nextOneBit(p->consPins, consPinSize, loc)) != SIZE_MAX)
    {   uintptr_t v = offsetToCons(loc, p);
        if (!consIsNewPinned(v, p)) car(v) = CONS_PADDER_HEADER;
        loc++;
    }
    std::memcpy(p->consPins,
                p->newConsPins,
                consPinBytes);
    std::memset(p->newConsPins, 0, consPinBytes);
// Space up as far as consFringe is in use, and any pinned items there
// should now be skipped.
    while (consFringe != csl_cast<uintptr_t>(p+1) &&
           consIsPinned(consFringe, p)) consFringe += sizeof(ConsCell);
// If that tkes consFringe up to the end of the page then this page is
// full and the next allocation request will replace it.
    if (consFringe == csl_cast<uintptr_t>(p+1))
    {   consLimit = consFringe;
        return;
    }
// Now (whew) there is at least one non-pinned cell available still. The
// first block of such must be left delimited by consLimit.
    uintptr_t a = consFringe;
    while (a != csl_cast<uintptr_t>(p+1) &&
           !consIsPinned(a, p)) a += sizeof(ConsCell);
    consLimit = a;
    if (a == csl_cast<uintptr_t>(p+1)) return;
// Here I have found a relevant pinned item. Skip past pinnings..
    while (a != csl_cast<uintptr_t>(p+1) &&
           consIsPinned(a, p)) a += sizeof(ConsCell);
// Now a points to the start of a free region (or at the end of the page).
// I can fill in the rest of the page with pointers that chain such free
// regions together.
    uintptr_t base = a;
// At present this is coded by looking at each individual cons cell. Once
// I have debugged things using this version I can use ntz() to search for
// pinned items 64-cells at a time in the bitmap, thereby speeding this
// up quite a lot. But this version is simpler so I use it first.
    while (a != csl_cast<uintptr_t>(p+1))
    {   if (consIsPinned(a, p))
        {   car(base) = a;
            base = a;
            while (a != csl_cast<uintptr_t>(p+1) &&
                   consIsPinned(a, p)) a += sizeof(ConsCell);
        }
        else a += sizeof(ConsCell);
    }
    car(base) = a;
}

size_t rePinOneVecPage(Page* p)
{
// Here the page has at least one chunk that was pinned (either in
// a previous GC or in this one). Info about that is in chunkStatus and
// chunkStatusMap. Current detailed pinning info is in newVecPins.
    zprintf("rePinOneVecPage %a\n", p);
    size_t pinnedChunkCount = 0;
    size_t pinnedChunk = 0;
    while ((pinnedChunk = nextOneBit(p->chunkBitmap,
                                     chunkBitmapSize,
                                     pinnedChunk)) != SIZE_MAX)
    {   // Deal with a chunk that may still be pinned
        bool anyPinned = false;
        size_t pinEnd = pinnedChunk + p->chunkLength[pinnedChunk];
// So here is a chunk. There may be some pinned material in it.
// I want to arrange that all regions in it apart from the pinned
// objects are padders.
        uintptr_t a = addressFromChunkNo(p, pinnedChunk);
        uintptr_t b = addressFromChunkNo(p, pinEnd);
// Now I have the addresses of the start and end of the chunk. Note that they
// will be 16K aligned. I need to process each pinned item in that range.
// Well that is going to be looking in newVecPins starting at the offset
// for a and ending at the one for b.
        size_t aOffset = vecToOffset(a, p);
        size_t bOffset = vecToOffset(b, p);
// Because the chunk is 16K aligned its end address comes at a neat multiple
// of 64-bits in the map, so the division here will be exact.
        size_t bitmapEndPos = bOffset/64;
// There is a step that I could take here where at prezsent I do not, and
// which I do not intend to until I have everything else debugged.
// If the first pinned item in a chunk is more than 16K down from the
// front or if am extended chunk in fact has no items in it that are still
// pinned then I can turn at turn all of it into a sequence of basic
// chunks. Detecting and handling that case here will not be costly and it
// (slightly) improves the recycling of memory!
        while ((aOffset = nextOneBit(p->newVecPins, bitmapEndPos, aOffset)) !=
               SIZE_MAX)
        {   anyPinned = true;
            uintptr_t thePinnedItem = offsetToVec(aOffset, p);
            if (thePinnedItem != a) setHeaderWord(a, thePinnedItem-a);
            zprintf("Put padder at %a length %d\n", a, thePinnedItem-a);
            Header h = *reinterpret_cast<Header*>(thePinnedItem);
            zprintf("Pinned item at %a length %d\n", thePinnedItem, length_of_any_header(h));
            a = thePinnedItem + length_of_any_header(h);
            aOffset = vecToOffset(a, p);
        }
        if (a != b) setHeaderWord(a, b-a);
        zprintf("final padder at %a length %d\n", a, b-a);
        if (anyPinned) pinnedChunkCount++;
        zprintf("pinned chunk from %d to %d\n", pinnedChunk, pinEnd);
        pinnedChunk = pinEnd;
    }
    std::memset(p->chunkBitmap, 0, sizeof(p->chunkBitmap));
    return pinnedChunkCount;
}

void setupPinmapsConsPages()
{
// This is called at the end of GC. At this stage I generally need to move
// pin information from newConsPins to Pins (and clear newConsPins ahead of
// any future GC). There are several "sorts" of pages:
// (1) consPinPages. Ones that contained some pinned data after the
//     previous GC but may or may not now. Apart from pinned items
//     and any pinned now will have been pinned last time, the page is
//     empty and available for allocation.
// (2) consOldPages. Ones that held live data at the start of the GC but
//     where all non-pinned data has now been moved to elsewhere. There can
//     be pinned items that were pinned last time and also ones newly pinned
//     this time, but all non-pinned space is available for re-use. These
//     pages are treated just as the ones in catergoty (1).
// (3) consPages except from consCurrent: now full of live data copied
//     by this GC. The pin-maps need updating but no freechains should be
//     created.
// (4) currentCons. The pinmap needs updating and free-chain information
//     must be set up from fringe to the end of the page, but space before
//     fringe must not be touched.
// (5) emptyPages. No action needed because there can neither be new nor old
//     pinned data.
// (6) consCloggedPages. Well with luck this GC has led to some of the
//     old pinning being released so the page morphs into a consPinPage
//     or exceptionally even into and emptyPage]
// I will start by moving consPinPages stuff onto consOldPages so that the
// two can be processed together.
    consOldPages += consPinPages;
    consOldPages += consCloggedPages;
    while (!consOldPages.isEmpty())
    {   Page* p = consOldPages.pop();
// rePinOneConsPage processes one page and returns a count of the pinned
// items present.
        size_t nPins = rePinOneConsPage(p);
        if (nPins == 0)
        {   zprintf("cons Page %a is now empty\n", p);
            emptyPages.push(p);
        }
// I set a rather arbitrary limit such that if (1/10) of a page is
// filled with pinned items I will avoid allocation within that page
// until subsequent garbage collections have (one hopes) observed the
// pinning evaporating.
        else if (nPins < pageSize/sizeof(ConsCell)/10)
        {   zprintf("cons Page %a has %d pins\n", p, nPins);
            consPinPages.push(p);
        }
        else
        {   zprintf("cons page %a hs clogged (%d)\n", p, nPins);
            consCloggedPages.push(p);
        }
    }
    for (auto p:consPages)
    {   std::memcpy(p->consPins,
                    p->newConsPins,
                    consPinBytes);
        std::memset(p->newConsPins, 0, consPinBytes);
        if (p == consCurrent) rePinConsCurrent(p);
    }
}

void moveNewPins(PageList& pl)
{   for (auto p:pl)
    {   std::memcpy(p->vecPins,
                    p->newVecPins,
                    vecPinBytes);
        std::memset(p->newVecPins, 0, vecPinBytes);
    }
}

void setupPinmapsVecPages()
{
// I will now set a flag on all vecPages so that when I have repinned
// I leave them there. I also need to get ready to reconstitute vecPinPages
// and vecCloggedPages;    
// Note that at this stage vecPages contain just the pages that form
// the vector component of the "new half space" that I have copied
// data into. I need to treat them differently from all other Pages.
    zprintf("setPinmapsVecPages\n");
    zprintf("vecPinPages:"); for (Page* p:vecPinPages) zprintf(" %a", p); zprintf("\n");
    zprintf("vecCloggedPages:"); for (Page* p:vecCloggedPages) zprintf(" %a", p); zprintf("\n");
    zprintf("vecOldPages:"); for (Page* p:vecOldPages) zprintf(" %a", p); zprintf("\n");
    zprintf("oldVecPinPages:");
    for (Page* p=oldVecPinPages; p!=nullptr; p=p->oldVecPinPages)
        zprintf(" %a", p);
    zprintf("\n");
    for (Page* p:vecPages) p->isInVecPages = true;
    vecOldPages += vecPinPages;
    vecOldPages += vecCloggedPages;  // This leaves vecPinPages etc empty.
    Page* old = oldVecPinPages;
    oldVecPinPages = nullptr;
    for (Page* p=old; p!=nullptr; p=p->oldVecPinPages)
    {   int nPins = rePinOneVecPage(p);
        if (!p->isInVecPages)
        {   if (nPins == 0)
            {   zprintf("Page %a is now empty\n", p);
                emptyPages.push(p);
            }
            else if (nPins < 10)
            {   zprintf("Page %a now has %d pins\n", p, nPins);
                vecPinPages.push(p);
            }
            else
            {   zprintf("Page %a is clogged (%d)\n", p, nPins);
                vecCloggedPages.push(p);
            }
            if (nPins == 0) p->hasVecPins = false;
            else
            {   p->oldVecPinPages = oldVecPinPages;
                oldVecPinPages = p;
                p->hasVecPins = true;
            }
        }
        // Otherwise the page remains on vecPages
    }
// Tidy up
    for (Page* p:vecPages) p->isInVecPages = false;
    moveNewPins(vecPages);
    moveNewPins(vecPinPages);
    moveNewPins(vecCloggedPages);
// Finally I must reset vecLimit to cope with the possibility that
// a pinned region within vecCurrent went away.
    size_t vChunk =
        (vecFringe - csl_cast<uintptr_t>(&vecCurrent->chunks[0]))/chunkSize;
    size_t nextPinnedChunk = nextOneBit(vecCurrent->chunkBitmap,
                                        chunkBitmapSize,
                                        vChunk);
    if (nextPinnedChunk == SIZE_MAX)
        vecLimit = csl_cast<uintptr_t>(vecCurrent+1);
    else vecLimit = csl_cast<uintptr_t>(&vecCurrent->chunks[0]) +
        chunkSize*nextPinnedChunk;
}

// I start garbage collection by  making the current allocation pages
// have the structure of ones that are full. The only thing that involves
// is storing fringe pointers in them.

bool withinGarbageCollector = false;

void inner_garbage_collect()
{   WithinGarbageCollector noted;
    displayAllPages("Start of GC");
    check_standard_input(__WHERE__);
    validateAll("start GC");
    allPinned.clear();
//    check_standard_input(__WHERE__);
// I start by setting the end-point information in the two current pages.
// That leaves them in the proprer state to count as "full", so that when
// the GC looks at ambiguous pointers it will be able to be aware when
// an apparent pointer is to a location above the fringe. Note that any
// final chunk in the vector page may need to have a padder inserted.
    consCurrent->dataEnd = consFringe;
    if (vecFringe != vecLimit)
        setHeaderWord(vecFringe, vecLimit-vecFringe);
    vecCurrent->dataEnd = vecLimit;
// Next I move the currently used pages to an "old" chain.
    consOldPages = consPages;
    vecOldPages = vecPages;
    pinnedPages = nullptr;
    potentiallyPinned = nullptr;
// ... and allocate what will be the start of the new half-space.
// Well here I will not want any ambiguous pointers into this new
// space to be deemed valid, and I will be putting stuff into the
// CONS region as a list of pinned objects - so on a temporary basis
// I will mark the pages as free!
    grabFreshPage(consPageType);
    validateAll("GC setup");
//    check_standard_input(__WHERE__);
// Now I can scan the stack and mark up pinned items. This will build
// up a chain of pages pinned this time.
// For each such page it will create a list of the pinned locations, where
// the "pointers" in that list are tagged so that the GC will view then as
// integers rather than references, and so not be tempted into following
// them. But the nodes that make up the list there could by some mischance
// now have their new pin bit set. I will tidy that up!
    identifyPinnedItems();
    validateAll("identifyPinnedItems done");
//    check_standard_input(__WHERE__);
// I need to give more explanation. consPages now will be JUST the
// pages allocated for the GC to use as its "new half space". That
// means that the only things that ought to get pinned in them will be
// items where an existing pin is confirmed. Any cases where a new pin has
// been set on something where there is not an existing one is liable to be
// an accidental pinning of part of the list of pinned items I have
// just been creating.
    for (auto p:consPages)
    {   for (uintptr_t v=p->pinnedObjects&~TAG_BITS;
             v!=0;
             v=cdr(v)&~TAG_BITS)
        {   uintptr_t pa = car(v)&~TAG_BITS;
            if (consIsNewPinned(pa, p) && !consIsPinned(pa, p))
                consClearNewPinned(pa, p);
        }
    }
    findHeadersOfPinnedItems();
    validateAll("findHeadersOfPinnedItems done");
//    check_standard_input(__WHERE__);
    pendingPages = nullptr;
    zprintf("Report on pinning...\n");
    {   for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
        {   zprintf("Page %a contains some pinned material\n", pp);
            for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                            c!=0;
                            c=cdr(c)-TAG_FIXNUM)
            {   zprintf("Pinned object at address %a\n", car(c)-TAG_FIXNUM);
            }
            if (pp->type == consPageType)
            {   int n = 0;
                zprintf("bitmaps for a cons page\n");
                for (auto v:pp->consPins)
                {   if (v != 0) zprintf("Map_% d: %16.16x\n", n, v);
                    n++;
                }
                n = 0;
                for (auto v:pp->newConsPins)
                {   if (v != 0) zprintf("newMap_% d: %16.16x\n", n, v);
                    n++;
                }
            }
        }
    }
// There is no need to set up a new vector current page until now.
    grabFreshPage(vecPageType);
    validateAll("ready to start evacuating");
//    check_standard_input(__WHERE__);
// I arrange that the very first vector item I copy is the vector that is
// the current "package", ie hash table of symbols. I do this because it
// is liable to be a large vector so putting it first avoids some padding
// waste (maybe!).
    evacuateFromPinnedItems();
    validateAll("evacuateFromPinnedItems done", true);
//    check_standard_input(__WHERE__);
    evacuateFromUnambiguousBases();
    validateAll("evacuateFromUnambiguousBases done", true);
//    check_standard_input(__WHERE__);
    if (gcTrace) displayAllPages("Line 1070 in newcslgc.cpp"); // DEBUG
    evacuateFromCopiedData();
    validateAll("evacuateFromCopiedDate done");
//    check_standard_input(__WHERE__);
// Well where we should be now is that all live data is either left in place
// if pinned or moved to new space if not. References to it should all be
// updated properly. Memory allocation should now be ready to continue on
// seamlessly from where stuff got copied to.
//
// Now vecOldPages and consOldPages have the pages that I have just copied
// material out from.
// vecPinPages and consPinPages are the ones that held some pinned material
// at the start of this GC but have not had anything fresh copied into them.
// It is possible - indeed I have high hopes - that some pages in
// consPinPages and vecPinPages now have fewer objects in them that are
// pinned, and I very much hope that eventually most of them will have
// NO pinned stuff left at all - at which stage they can be moved to
// emptyPages.
// So for everything in consOldPages and in consPinPages I will need to
// copy the new pin-map to the main one and rearrange free-space chaining.
// if such a page ends up empty it may be put in emptyPages otherwise on
// consPinPages. And similarly for vector pages.
    setupPinmapsConsPages();
    validateAll("setupPinmapsConsPages done");
    check_standard_input(__WHERE__);
// The following is messier than I has recognized. There can be existing
// pages containing items pinned for the first time during the GC in
// vecOldPages. They will also be in potentiallyPinned.
// There can then be items that had been pinned during the last GC but
// which may or may not be pinned still in VecOldPages, vecPages,
// vecPinPages and vecCloggedPages.
// I think I want to be able to identify these pages efficiently without
// needing to check everything in vecPages and vecOldPages (which I
// generally expect to be pretty clean). So I will have yet another
// chain of pages - oldVecPinPages - that at the end of a GC contains
// every vector page containing pinned chunks, and if a page is on that
// chain it has a flag - hasVecPins - set in it to note this fact.
// So I need to scan oldVecPinPages. There are then several cases:
// (1) pages in vecOldPages. These had been full of live data at the start
//     of the GC that is now ending, so there may be existing pinned stuff
//     from a previous GC and there can be new pinnings. But some existing
//     old pins may no longer be active. Inspect each Chunk that contains
//     or may contain pinned stuff. chunkStatusMap[] makes identifying these
//     quick. For each such chunk inspect newVecPins[] for all words within
//     the chunk (or extended chunk). If none then that Chunk becomes
//     plain and might usefully be filled with a single padder. If it is
//     an extended Chunk turn into a sequence of simple chunks each padded.
//     Adjust chunkStatus and chunkStatusMap[]. A special case is if a
//     pinned extended chunk now does not have the first vector in it
//     pinned. An extended chunk always contains one large vector that spans
//     at least 2 sub-chunks, but its final chunk can be filled out with
//     more small objects. It the large vector is now not pinned but one or
//     more of the small ones are then all but the final chunk can be
//     turned into unused simple chunks and that final chunk becomes a
//     simple pinned one.
//     If there are pinned items still then write in padders between
//     every pinned object, and leave chunkStatus and chunkStatusMap alone.
//     If no pinned checks remain move to emptyPages, otherwise based on
//     how much pinning is present move to vecPinPages or vecCloggedPages.
//     That is because all non-pinned stuff has been moved out from it.
//     Note that allocation just uses chunkStatus[] and not any information
//     written into the data region, so things here are simpler than in the
//     case of cons pages.
// (2) Things in vecPages [this in fact includes vecCurrent]. Such pages
//     can only contain pinned data if it has been pinned by a previous GC
//     and allocation as stuff was copied during this GC has moved material
//     into it, but some of the old pinned stuff may still be pinned. Treat
//     just as case (1) except that it stays on vecPages.
// (3) vecPinPages and vecCloggedPages. Treat as (1). The only possible live
//     material will be in pinned chunks and I rather hope or expect that
//     over a sequence of GCs the number of pinned chunks will decrease.
//     This can cause progression from Clogged to Pin to Empty.
// (4) vecCurrent. I think this gets handled as (2) except that at the end
//     it resets vecLimit because that might previously have been defined by
//     a chunk that used to be pinned but is not now.
// All this must leave the oldVecPinPages as a chain of pages with items
// pinned NOW, and it mist move pin maps from vecNewPins to vecPins.
    setupPinmapsVecPages();
    validateAll("setupPinmapsVecPages done: GC complete");

    zprintf("GC complete!\n");
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

// The value I put in volatileVar is fairly unimportant, however there
// is an expectation that the GC will observe multiple copies of it on the
// stack and I do not want it interpreted as a reference to some object in
// the heap, and so I will give it a value that I do not expect to be
// issues by "new" but which if printed while I am debugging will stand out.

static volatile uint64_t volatileVar = 0xf0f0f0f012345678u;

NOINLINE uintptr_t getStackFringe(double x)
{   return csl_cast<uintptr_t>(&x);
}

NOINLINE void garbage_collect()
{   std::jmp_buf buffer;
    check_standard_input(__WHERE__);
    buffer_pointer = &buffer;
// This is a silly hack! The idea is that as far as the compiler is
// allowed to assune, each reference to volatileVar might return a different
// value. So a1-a18 all hold notionally independent values. I rather hope
// that many of those will be placed in machine registers, flushing
// any values from the caller to the stack. And because thay are all
// independent each needs its own register!
    uint64_t a1 = volatileVar; uint64_t a2 = volatileVar; uint64_t a3 = volatileVar;
    uint64_t a4 = volatileVar; uint64_t a5 = volatileVar; uint64_t a6 = volatileVar;
    uint64_t a7 = volatileVar; uint64_t a8 = volatileVar; uint64_t a9 = volatileVar;
    uint64_t a10 = volatileVar; uint64_t a11 = volatileVar; uint64_t a12 = volatileVar;
    uint64_t a13 = volatileVar; uint64_t a14 = volatileVar; uint64_t a15 = volatileVar;
    uint64_t a16 = volatileVar; uint64_t a17 = volatileVar; uint64_t a18 = volatileVar;
    for (int i=0; i<1000000; i++)
    {   if (setjmp(buffer) == 0)
        {   C_stackFringe = getStackFringe(1.0);
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
// between any two sequence points. The other part of the idea here is
// that all these references and calculations must be performed because
// the resulting values go back in volatileVar and the setting of that
// location may not be optimised away.
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
// Of course all I do here is slihtly ridiculous! And none of if really
// gives guarantees. Well the whole issue of there being a contiguous
// stack as the only place the compiler stashes things is very much an
// assumption! In many respects all I do here is an amazing waste of
// resources, but the cost will be minuscule measured against the total
// cost of garbage collection that it is seeking to protect.
        if (volatileVar == volatileVar) break;
    }
// End of garbage collection!
    zprintf("@@@END OF GC@@@\n");
    check_standard_input(__WHERE__);
}

// The functions here are intended to be useful for calling from gdb

void aprint(uintptr_t x)
{
// Note that with zprintf() I do not need to mess around and use eg PRIx64.
    zprintf("x = %a %16.16x = %s\r\n",
        (uintptr_t)x, (uint64_t)x, objectType((uintptr_t)x));
}

void aprint(Page* x)
{   zprintf("x = %a %16.16x = %s\r\n",
        (uintptr_t)x, (uint64_t)x, objectType((uintptr_t)x));
}

void aprint(LispObject* x)
{   zprintf("x = %a %16.16x = %s\r\n",
        (uintptr_t)x, (uint64_t)x, objectType((uintptr_t)x));
}

// end of file newcslgc.cpp
