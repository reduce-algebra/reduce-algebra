// File newcslgc.cpp                      Copyright (c) Codemist, 2018-2025


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

// Things I need to worry about...
// (.) All global variables that can hold references to list structures
//     (at the time of  a GC) must be mentioned in list_bases[] as defined
//     in externs.h. I do not have a mechanical way of checking that that
//     is the case which is a worry. Well the following crudely written
//     command executed in a directory where there is an executable for
//     csl lists all data symbols of length 8. On a Linux system in
//     early 2025 there were 452 symbols listed and I have gone through
//     that list removing ones that I am certain are not list-bases -
//     for instance "stdout" and a number that I know hold counts rather
//     then references. That leaves a list that should be a superset of
//     my needs. OF course the worry then is that some may be symbols
//     that only arise for Linux, but such cases get filtered out when I
//     try building on other platforms! All the ones in package "FX" are
//     from the FOX toolkit and will not hold Lisp pointers.
// nm -C -S --size-sort --defined-only csl | grep 0000000000000008 |
//    grep -v " r " | grep -v " t " | grep -v " T " | grep -v " V " |
//    grep -v " u " | grep -v " R " > names
//     So I temporarily insert "extern LispObject" declarations for all
//     names identified that way then filter out ones where compilation
//     reveals that some other type was involved.
//
// (.) I have at least workbase[] as an array of static references which is
//     not picked up be the above.
//
// (.) If I have a statically allocated (class) object then any fields
//     within it would not show up in the scheme charted above. Objects
//     allocated on the stack are OK since I will scan all of that anyway.
//     But this means I need to be careful e.g. with arithlib.hpp. That has
//     some persistent state (eg the corrent modulus for mod-P arithmetic)
//     so it has to be coded for safety there.
//
// (.) Data within threads is not protected at all. At present the threads
//     used are for Karatsuba multiplication and so garbage collection must
//     probably not be triggered while that is active. Well happily it
//     will not be!
//
// (.) Aggregate classes such as std::vector will keep much of their
//     data in places I do not know about, so std::vector<LispObject> and
//     the like must be viewed as unacceptable.



#include "headers.h"
#ifdef EXTREME_DEBUG
#include "validate.h"
#endif // EXTREME_DEBUG

unsigned int gcNumber = 0;

// The default is gcTrace=0 which leads to no trace.
// If the user specified just "--gc-trace" then the value is set to 1 and
// tracing happens for all GCs. --gc-trace=N sets tracing for garbage
// collection N and beyond.

const char* getPageType(uintptr_t a)
{   Page* p = pageOf(a);
    const char* t;
    static char b[20];
    if (consPages.contains(p))             t = "C";
    else if (vecPages.contains(p))         t = "V";
    else if (consOldPages.contains(p))     t = "Co";
    else if (vecOldPages.contains(p))      t = "Vo";
    else if (consPinPages.contains(p))     t = "Cp";
    else if (vecPinPages.contains(p))      t = "Vp";
    else if (consCloggedPages.contains(p)) t = "Cx";
    else if (vecCloggedPages.contains(p))  t = "Vx";
    else if (emptyPages.contains(p))       return "E";
    else if (borrowPages.contains(p))      t = "B";
    else                                   return "Q";
    bool pin = p->type == consPageType ? consIsPinned(a, p) :
                                         vecIsPinned(a, p);
    bool newpin = p->type == consPageType ? consIsNewPinned(a, p) :
                                            vecIsNewPinned(a, p);
    std::snprintf(b, sizeof(b), "%s%s%s%s",t, pin?"!":"", newpin?"|":"",
                 (pin||newpin)?Addr(a):"");
    return b;
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
// the chunk from its (data) start to its fringe are valid. If pinnedObjects
// is set I need to check in great detail whether the address is within one
// of the objects in the chunk that had let to it being pinned. Well
// pinnedObjects is not a boolean, it is a list (albeit with its pointers
// tagged as TAG_FIXNUM!) of such items. The pointers are represented as
// fixnums because the list is ephemeral and I do not want this GC to view
// it as data to be traced through and preserved.

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

#ifdef EXTREME_DEBUG
std::unordered_set<uintptr_t> allPinned;
#endif // EXTREME_DEBUG

// The ambiguous value (a) seems to point within the page (p). I do
// different things based on the sort of page involved... pointers into
// CONS pages will be the simplest to handle.

void processAmbiguousInPage(Page* p, uintptr_t a)
{   uintptr_t dataStart;
    size_t chunkNo;
    switch (p->type)
    {
    case emptyPageType:
// A "pointer" into an empty page is of no concern to anybody.
        return;

    case consPageType:
// This is the simplest case, mainly because all objects in the page
// are neatly aligned on 2-cell boundaries.
        a = a & -sizeof(ConsCell);   // align the pointer.
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
// If I have a pointer into a consPinPage that may point at an entry
// with consIsPinned() set (ie pinned from last time) in which case the
// new pinning is valid. But otherwise it is BAD. And it could potentially
// cause trouble because the item referred to was almost certainly evacuated
// during the last GC so has a forward pointer om place, and if I pin it
// this time I will try to evacuate again with very bad consequences.
// Well a way to keep me safe is to set dataEnd to the start of the Page
// whenever I push anything onto consFreePages, condPinnedPages or
// consCloggedPages.
//
// At this stage the "new half space" will only contain some fragments of
// chains of newly pinned items. These should never need to get pinned, so
// I will just reject pointers into consCurrent. In extreme cases the
// chains of pinned items could lead to the allocation of further pages, but
// for those further pages I can check against dataEnd to avoid putting a
// pin on memory that is not in use.
        else if (((p!=consCurrent && a < p->dataEnd) ||
                  consIsPinned(a, p)) &&
                 !consIsNewPinned(a, p))   // detect first time noticed.
        {   my_assert(!consIsNewPinned(a, p), where("consIsNewPinned test bad"));
            consSetNewPinned(a, p);
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("set new cons pin %a\n", a);
#endif // EXTREME_DEBUG
// The first time I find an object pinned on a page I will put that page
// in a chain of ones containing pinned material. This chain will include
// pages with material pinned by previous GCs as well as by new activity.
            if (p->hasPinned == 0)
            {   p->hasPinned = 1;
                p->pinnedPages = pinnedPages;
                pinnedPages = p;
            }
#ifdef EXTREME_DEBUG
            my_assert(allPinned.count(a) == 0, where("double pinning"));
            allPinned.insert(a);
#endif // EXTREME_DEBUG
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
// not have a trivial way to tell where objects start and it is very common
// for there to me multiple ambiguous references to the same live item.
// So at this stage I will make simple checks so I ignore obviously
// irrelevent "pointers", but just set "new" vector-pin and chunk-pin
// information. Then after all ambiguous values have been inspected I
// will re-visit the pages that contain new "potentially pinned" stuff and
// put things in the state they need to be. The chain potentiallyPinned is
// one of pages I will need to re-visit.
        a = a & -8;   // align the pointer.
        dataStart = offsetToVec(0, p);
        if (a < dataStart) return;
        chunkNo = chunkNoFromAddress(p, a);
// The pointer may be valid either if it refers to an address below the
// fringe or if it is withing a chunk that had been pinned during an
// earlier GC. I need to make sure that I refer to the start of the chunk
// containing the address concerned.
        chunkNo -= p->chunkSeqNo[chunkNo];
// Now I am pointing at the start of the chunk. If it is ahead of
// dataEnd it contains live data and also if the chunk is pinned it might
// even if it is way beyond dataEnd. Note that "pinned" here has to mean
// "pinned by a previous GC" not this one. In each case I will mark it as
// potentially pinned.
        if (a < p->dataEnd || chunkNoIsPinned(p, chunkNo))
        {
// Now I tag the Chunk as (potentially) pinned. It will not actually be pinned
// if the dodgy address points within a padder item in it. Set a mark in
// the "new" chunk pinning map and on the first occasion that is done chain
// the page as having new pinned chunks - well only potentially because
// the address noticed may refer within a padder. A later pass will
// need to scan potentially pinned chunks and tidy things up.
            if (!chunkNoIsNewPinned(p, chunkNo))
            {   chunkNoSetNewPinned(p, chunkNo);
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
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("mark new vec pin %a potentially within object\n", a);
#endif // EXTREME_DEBUG
        }
        return;
    default:
        my_abort(where("page type not recognised"));
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

void processAmbiguousValue(uintptr_t a, const char* source="STACK")
{
// I find the Page (if any!) the value is in. That Page may be empty,
// one containing old pinned stuff or one full of live data.
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("%s %d: %a\n", source, stackCount++, a);
#endif // EXTREME_DEBUG
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
// triggered. Some careful C++ systems have a default behaviour that
// aborts if one accesses memory on the stack but outside the current
// proper stack frame and I need to disable that (very proper) caution.

NO_SANITIZE_ADDRESS
void identifyPinnedItems()
{
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
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("Scan C stack from %x to %x\n", C_stackFringe, C_stackBase);
#endif // EXTREME_DEBUG
    for (uintptr_t s=C_stackFringe; s<C_stackBase; s+=sizeof(uintptr_t))
        processAmbiguousValue(indirect(s));
}

// This not only ensures that the bitmap identifies the head of every
// pinned item, but it also arranges that no addresses within objects are
// marked.
// It completes the work that in some sense logically belonged when
// ambiguous pointers into vector pages were first spotted. Delaying until
// now means that just one scan of a potentially pinned chunk serves for
// all the ambiguous pointers into it.
// Note that chunks that has been pinned by a previous GC will have
// padders written into all unused space in them, so new references
// into them are only accepted it to existing pinned data.

void findHeadersInChunk(size_t firstChunk, size_t lastChunk, Page* p)
{   uintptr_t firstAddr = addressFromChunkNo(p, firstChunk);
//  zprintf("\n\n@@@@\n");
//  if (GCTRACE) displayAllPages(where("findHeadersInChunk"));
// lastAddr is just beyond the last data I need to scan here. Note that
// it can be just beyond the end of the page.
    uintptr_t lastAddr   = addressFromChunkNo(p, lastChunk);
// Now I have a chunk delimited, I will parse it so I can identify
// object start addresses.
    uintptr_t s = firstAddr;
    bool thisChunkHasPins = false;
    while (s < lastAddr)
    {   uintptr_t h = indirect(s);
        if (h == 0)
        {   zprintf("zero word at %a\n", s);
            my_abort(where("zero word in heap"));
        }
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
            if (len == 0 || len>=pageSize)
            {   zprintf("bad length of %x at %a (h=%a)\n", len, s, h);
                my_abort(where("len==0 or too big"));
            }
#ifdef EXTREME_DEBUG
            if (GCTRACE && testBits(p->newVecPins,
                                    vecToOffset(s, p),
                                    len/8))
            {   zprintf("Pinned vector head at %a: ", s);
                LispObject s1 = s;
                switch (type_of_header(h))
                {   case TYPE_FLOAT:
                        s1 += TAG_BOXFLOAT;
                        break;
                    case TYPE_BIGNUM: case TYPE_NEW_BIGNUM:
                        s1 += TAG_NUMBERS;
                        break;
                    default:
                        s1 += TAG_VECTOR;
                        break;
                }
                simple_print(s1);
            }
#endif // EXTREME_DEBUG
            break;
    case 0x02: // 0b00010: // Symbol headers, char literals etc.
// The code is either for the header of a symbol or for some sort
// of immediate data, and in the latter case the object must be
// h CONS cell.
            if (is_symbol_header(h))
            {   len = symhdr_length;
                if (GCTRACE && testBits(p->newVecPins,
                                        vecToOffset(s, p),
                                        len/8))
                {   zprintf("Pinned symbol head at %a: ", s);
                    simple_print(s+TAG_SYMBOL);
                }
                break;
            }
            FALLTHROUGH;
    default:                 // None of the above cases...
            len = 2*CELL;    // ... must be a CONS cell.
// Since this is a Page intended to contain vectors it would be wrong if it
// had any cons cells in it. However in case at some later stage I put
// some cons cells into vector pages I will allow for that case here!
            if (GCTRACE && testBits(p->newVecPins,
                                    vecToOffset(s, p),
                                    len/8))
            {   zprintf("Pinned cons head at %a: ", s);
                simple_print(s);
            }
            break;
        }
        size_t o1 = vecToOffset(s, p);
// I will take special action of the object found is a padder. In that
// case I will clear all the pin bits for addresses within the object,
// because padders can never be pinned. This tidies up in an ambiguous
// pointer refers into a block of memory pinned by a previous GC but
// does not identify live data within it.
        if (is_padder_header(h))
        {   clearBits(p->newVecPins, o1, len/8);
            s += len;
            continue;
        }
// For other objects I need to test if there are any pin bits at all within
// the object, and if so set one for the first bit while clearing all others.
        else if (testBits(p->newVecPins, o1, len/8))
        {   thisChunkHasPins = true;
// Move the pin bit so it is on the head of the item.
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("Move pin bit to head of %a\n", s); 
#endif // EXTREME_DEBUG
            clearBits(p->newVecPins, o1, len/8);
            setBit(p->newVecPins, o1);
            if (p->hasPinned == 0)
            {   p->hasPinned = 1;
#ifdef EXTREME_DEBUG
                if (GCTRACE) zprintf("set hasPinned and put %a on pinnedPages\n", p);
#endif // EXTREME_DEBUG
                p->pinnedPages = pinnedPages;
                pinnedPages = p;
            }
#ifdef EXTREME_DEBUG
            my_assert(allPinned.count(s) == 0, where("double pinning"));
            allPinned.insert(s);
#endif // EXTREME_DEBUG
// Record this pinned object in a list of same.
            LispObject z = get2Words();
            car(z) = s + TAG_FIXNUM;
            cdr(z) = p->pinnedObjects;
            p->pinnedObjects = z + TAG_FIXNUM;
        }
        s += len;
    }
    if (!thisChunkHasPins) chunkNoClearNewPinned(p, firstChunk);
//  zprintf("\n\n&&&&\n");
//  if (GCTRACE) displayAllPages(where("end findHeadersInChunk")); // DEBUG
}

// Here I identify each chunk that may contain pinned data and process it.
// By using ntz() on the words of the bitmap this should be respectably
// cheap. Note that this only scans chunks where there is a bit of pinning
// in the current GC, ie newVecPins[]. All things on vecPins[] left over
// from the previous GC will already just identify item heads. So this
// only needs to process pages and chunks with pinning in the most recent GC.
// It does fice things:
//   When a (new) pin is on the middle of an object it migrates it so
//     that it is on the header word of the object.
//   If a new pin is then on a padding object pin info is removed.
//   If no (new) pins remain in a chunk then the chunk is unpinned.
//   For items that are in fact pinned it sticks them on a "pinned object
//     chain" associated with the page they are in, that chain being
//     created in the new half-space.
//   If at least one new pin is set it ensures that the page is on pinnedPages.

void findHeadersOfPinnedItems()
{   while (potentiallyPinned != nullptr)
    {   size_t pinnedChunk = 0;
        while ((pinnedChunk = nextOneBit(potentiallyPinned->newChunkBitmap,
                                         chunkBitmapBits,
                                         pinnedChunk)) != SIZE_MAX)
        {   // Deal with a chunk that may still be pinned
            size_t pinEnd = pinnedChunk +
                            potentiallyPinned->chunkLength[pinnedChunk];
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("find headers in pinned chunk from %a to %a\n",
                addressFromChunkNo(potentiallyPinned, pinnedChunk),
                addressFromChunkNo(potentiallyPinned,  pinEnd));
#endif // EXTREME_DEBUG
            findHeadersInChunk(pinnedChunk, pinEnd, potentiallyPinned);
            pinnedChunk = pinEnd;
        }
        potentiallyPinned->potentiallyPinnedFlag = false;
        potentiallyPinned = potentiallyPinned->potentiallyPinnedChain;
    }
}

#ifdef EXTREME_DEBUG
std::unordered_set<LispObject*> evacuated;
#endif // EXTREME_DEBUG

void evacuate(LispObject &x)
{
#ifdef EXTREME_DEBUG
    if (evacuated.count(&x) == 0) evacuated.insert(&x);
    else my_abort(where("repeat evacuation"));
#endif // EXTREME_DEBUG
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
#ifdef DEBUG
    my_assert(x != 0, where("zero word in scanning"));
    my_assert(!is_forward(x), where("forwarding ptr in scanning"));
#endif // DEBUG
    if (is_immediate(x) || x == nil) return;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("evacuating %a %s\n", x, objectType(x));
#endif // EXTREME_DEBUG
// If something is not immediate it must be x pointer!
    LispObject* untagged_x = reinterpret_cast<LispObject*>(x & ~TAG_BITS);
    LispObject hdr = *untagged_x;
    LispObject cpy;
#ifdef EXTREME_DEBUG
    if (!consOldPages.contains(pageOf(x)) &&
        !vecOldPages.contains(pageOf(x)))
    {   if (pageOf(x)->type == consPageType && consIsPinned(x)) /*OK*/;
        else if (pageOf(x)->type == vecPageType  && vecIsPinned(x)) /*OK*/;
        else my_abort(where("evacuate something odd"));
    }
#endif // EXTREME_DEBUG
    if (is_forward(hdr))
    {   x = hdr - TAG_FORWARD + (x & TAG_BITS);
#ifdef DEBUG
        my_assert(!is_forward(x), where("forwarding ptr in scanning"));
#endif // DEBUG
        return;
    }
// Every hash table must have its type changed from TYPE_HASH to TYPE_HASHX
// to reflect the fact that the GC will move datya around and that can
// render hash functions out of date and hence the table as being is need
// of rehashing. Note that I do this for pinned and unpinned items since
// it is not the evacuation of the top-level part of the hash table that
// is important here!
    if (is_odds(hdr) && type_of_header(hdr) == TYPE_HASH)
        *untagged_x = hdr = hdr ^ (TYPE_HASHX^TYPE_HASH);
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
    else if (is_bfloat(x) && SIXTY_FOUR_BIT && hdr==DOUBLE_FLOAT_HEADER)
    {   if (consIsNewPinned(x)) return;
        len = 16;             // I know I am on a 64-bit system here
        cpy = get2Words();
    }
    else
    {   if (vecIsNewPinned(x)) return;
        len = doubleword_align_up(length_of_header(hdr));
        cpy = getNBytes(len);
    }
    std::memcpy(reinterpret_cast<void*>(cpy), untagged_x, len);
    *untagged_x = TAG_FORWARD + cpy;
    x = cpy + (x & TAG_BITS);
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("Evacuate %a to %a\n", untagged_x, x);
#endif // EXTREME_DEBUG
    my_assert(!is_forward(x), where("forwarding ptr in scanning"));
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
         sp>reinterpret_cast<LispObject*>(stackBase); sp--) evacuate(*sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != nullptr)
    {   for (size_t i=1; i<=repeat_count; i++)
            evacuate(repeat_heap[i]);
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
    {   while (pp->pinnedObjects != TAG_FIXNUM)
        {   LispObject c = pp->pinnedObjects-TAG_FIXNUM;
            LispObject next = car(c)-TAG_FIXNUM;
            pp->pinnedObjects = cdr(c);
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("About to evacuate contents of %a\n", next);
#endif // EXTREME_DEBUG
            Header a = *reinterpret_cast<Header*>(next);
            size_t len, len1;
// Now based on the low 6 bits of the first word of the object I sort
// out whether it is a vector containing Lisp data, a vector containing
// binary data (including strings and bignums) or a symbol. If none of
// those then it will be a CONS cell.
            switch (a & 0x1f)
            {
            case 0x0a: // 0b01010:   // Header for vector of Lisp pointers
                                     // Note TYPE_STREAM etc is in with this.
// If I am on a 32-bit system there are complications about the "length".
// There will be proper Lisp data up to length_of_header(a) but the
// object in memory will be that size but rounded up to a multiple of
// 8 bytes. That means there can be a padder word at the end. Either
// I must ensure it always contains valid Lisp data (such as a reference to
// nil) and that the garbage collector always updates it if needbe, or
// I must arrange that it is never inspected at all.
                len = doubleword_align_up(length_of_header(a));
                if (is_mixed_header(a)) len1 = 4*CELL;
                else len1 = len;
                my_assert(len != 0, "lisp vector size zero");
#ifdef EXTREME_DEBUG
                if (GCTRACE) zprintf("Evacuate contents of pinned vector of length %s\n", len1);
#endif // EXTREME_DEBUG
                for (size_t i = CELL; i<len1; i += CELL)
                    evacuate(*reinterpret_cast<LispObject*>(next+i));
                continue;

            case 0x12: // 0b10010:   // Header for bit-vector
                FALLTHROUGH;
            case 0x1a: // 0b11010:   // Header for vector holding binary data
                continue;

            case 0x02: // 0b00010:   // Symbol headers plus char literals etc
                if (is_symbol_header(a))
                {   Symbol_Head* s = reinterpret_cast<Symbol_Head*>(next);
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
#ifdef EXTREME_DEBUG
                    displayAllPages(where("zero work in heap")); // DEBUG
#endif // EXTREME_DEBUG
                    my_abort(where("zero word in evacuateFromPinnedItems"));
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
#ifdef EXTREME_DEBUG
    if (GCTRACE) displayConsPage(p);
#endif // EXTREME_DEBUG
    uintptr_t next = p->scanPoint;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("cons scanPoint = %a\n", next);
#endif // EXTREME_DEBUG
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
        {   LispObject* n = reinterpret_cast<LispObject*>(next);
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
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("end with cons scanPoint = %a\n", next);
    if (GCTRACE) displayConsPage(p);
#endif // EXTREME_DEBUG
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

bool evacuateChunk(Page* p, uintptr_t& next, size_t lastChunk)
{   bool didSomething = false;
    uintptr_t chunkEnd = addressFromChunkNo(p, lastChunk);
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("evacuateChunk from %a to %a or %a\n",
                         next, vecFringe, chunkEnd);
#endif // EXTREME_DEBUG
    while (next != chunkEnd && next != vecFringe)
    {   size_t len, len1;
        uintptr_t h = indirect(next);
        if (h == 0 || is_forward(h))
        {   zprintf("next = %a indirect(next+ = %a\n", next, h);
            zprintf("chunkEnd = %a\n", chunkEnd);
            zprintf("vecFringe = %a\n", vecFringe);
            zprintf("vecLimit = %a\n", vecLimit);
            my_abort(where("zero or forwarding addr vec page"));
        }
        switch (h & 0x1f)
        {
        case 0x0a: // 0b01010: // Header for vector of Lisp pointers
                               // Note TYPE_STREAM is in with this.
            len = doubleword_align_up(length_of_header(h));
            if (is_mixed_header(h)) len1 = 4*CELL;
            else len1 = len;
            my_assert(len != 0 && len<pageSize,
                      where("lisp vector size zero or too big"));
            for (size_t i=CELL; i<len1; i+=CELL)
                evacuate(*reinterpret_cast<LispObject*>(next+i));
            didSomething = true;
            break;

        case 0x12: // 0b10010: // Header for bit-vector
            FALLTHROUGH;
        case 0x1a: // 0b11010: // Header of vector holding binary data
            len = doubleword_align_up(length_of_header(h));
            my_assert(len != 0, where("lisp vector size zero"));
            break;

        case 0x02: // 0b00010: // Symbol headers, char literals etc.
            if (is_symbol_header(h))
            {   len = symhdr_length;
                Symbol_Head* s = reinterpret_cast<Symbol_Head*>(next);
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
            zprintf("next = %a\n", next);
            zprintf("chunkEnd = %a\n", chunkEnd);
            zprintf("vecFringe = %a\n", vecFringe);
            zprintf("vecLimit = %a\n", vecLimit);
            my_abort(where("cons cell in vec page"));
        }
        my_assert(len != 0, "something of size zero");
        next += len;
    }
    return didSomething;
}

bool evacuateVecPage(Page* p)
{   uintptr_t next = p->scanPoint;
#ifdef EXTREME_DEBUG
    if (GCTRACE) displayVecPage(p);
    if (GCTRACE) zprintf("~#evacVecPage %a, scanPoint=%a vecFringe=%a dataEnd=%a\n",
        p, next, vecFringe, p->dataEnd);
#endif // EXTREME_DEBUG
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
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("evacVecPage %a, scanPoint=%a vecFringe=%a dataEnd=%a\n",
        p, next, vecFringe, p->dataEnd);
#endif // EXTREME_DEBUG
// There is "special fun" when the page concerned is the current one. That has
// valid data up as far as vecFringe, but that is in general within a chunk
// rather than on a chunk boundary.
    while (next!=p->dataEnd && next!=vecFringe && next!=vecLimit)
    {
// Chunks that contain pinned material are an issue here. Well ones
// with chunkStatus as PinnedChunkStart can only have had that set by
// a previous GC, and so the only data within them will be pinned. That
// was evacuated by other code than this. The rest of this page should not
// have any pinned stuff in it at all.
        if (chunkNoIsPinned(p, firstChunk))
            next = addressFromChunkNo(p, lastChunk);
        else if (evacuateChunk(p, next, lastChunk)) didSomething = true;
// I get here at the end of the current chunk, so move on to the next one.
        firstChunk = lastChunk;
        lastChunk = firstChunk + p->chunkLength[firstChunk];
    }
    p->scanPoint = next;
#ifdef EXTREME_DEBUG
    if (GCTRACE) displayVecPage(p);
#endif // EXTREME_DEBUG
    return didSomething;
}

void evacuateFromCopiedData()
{   for (;;)
    {
// First I will deal with any pages that had become full. Those are easy!
        while (pendingPages != nullptr)
        {   Page* p = pendingPages;
            pendingPages = p->pendingPages;
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("Now evacuate contents of pending page %a\n", p);
#endif // EXTREME_DEBUG
            switch (p->type)
            {
            case consPageType:
                evacuateConsPage(p);
#ifdef EXTREME_DEBUG
                validateAll("evacConsPage done", true);
#endif // EXTREME_DEBUG
                break;
            case vecPageType:
                evacuateVecPage(p);
#ifdef EXTREME_DEBUG
                validateAll("evacVecPage done", true);
#endif // EXTREME_DEBUG
                break;
            default:
                my_abort(where("bad page type in evacuateFromCopiedData"));
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
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("Now evacuate current Cons page %a\n", consCurrent);
#endif // EXTREME_DEBUG
        bool didSomething = evacuateConsPage(consCurrent);
#ifdef EXTREME_DEBUG
        validateAll("evacConsPage", true);
// Now similarly for the vector page. Well the pain here is that scanning
// the vector page might put more info in the consCurrent page or even make
// it overflow, even if the vector page does not become full. So I must
// return false either if the vector page fills up or if any new conses are
// created.
        if (GCTRACE) zprintf("Now evacuate current Vec page %a\n", vecCurrent);
#endif // EXTREME_DEBUG
        if (evacuateVecPage(vecCurrent)) didSomething = true;
#ifdef EXTREME_DEBUG
        validateAll("evacVecPage", true);
#endif // EXTREME_DEBUG
// If neither scanning consCurrent nor vecCurrent did anything at all then
// pendingPages will still be left empty and there is nothing left to do.
// If either of them did do something then at least that one will have
// moved its scanPoint on, so when I re-try it will continue in a useful
// manner and eventually things will converge.
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("didSomething = %s\n", didSomething);
#endif // EXTREME_DEBUG
        if (!didSomething) break;
    }
    my_assert(pendingPages == nullptr, "pendingPages");
}

// Here I need to look at xPinPages because some of the pages may now
// have fewer pinned items and xPages because some of them may now
// have pinned items thet were not pinned before. I must create or re-create
// the layout needed for allocation based on the newer version of pin
// information that I have.
// As a reminder, in a cons page the structure for a page with some pinned
// stuff is as follows:
//   At the start there MAY be some pinned locatione that must not be used.
//   Beyond that the first cell of a usable block of memory must contain
//   either the address of the end of the page or the address of the next
//   pinned item.
// If there are cells that has been pinned by the previous GC but at not
// pinned now then they must be overwritten with padders. The value
// CONS_PADDER_HEADER put in the car() field achieves that. 
//
// The hasPinned field in the page must end up with a count of pinned
// items, and that must be zero if there are none.

// I have to do slightly different things on the current cons page.

void rePinConsCurrent(Page* p)
{   size_t loc=0;
    while ((loc = nextOneBit(p->consPins, consPinBits, loc)) != SIZE_MAX)
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
    size_t nPins = 0;
    while (consFringe != endOfConsPage(p) &&
           consIsPinned(consFringe, p))
    {   nPins++;
        consFringe += sizeof(ConsCell);
    }
// If that takes consFringe up to the end of the page then this page is
// full and the next allocation request will replace it.
    if (consFringe == endOfConsPage(p))
    {   consLimit = consFringe;
        p->hasPinned = nPins;
        return;
    }
// Now (whew) there is at least one non-pinned cell available still. The
// first block of such must be left delimited by consLimit.
    uintptr_t a = consFringe;
    while (a != endOfConsPage(p) &&
           !consIsPinned(a, p)) a += sizeof(ConsCell);
    consLimit = a;
    if (a == endOfConsPage(p))
    {   p->hasPinned = nPins;
        return;
    }
// Here I have found a relevant pinned item. Skip past pinnings..
    while (a != endOfConsPage(p) &&
           consIsPinned(a, p))
    {   a += sizeof(ConsCell);
        nPins++;
    }
// That may end up at the end of the page. Ugh.
    if (a == endOfConsPage(p))
    {   p->hasPinned = nPins;
        return;
    }
// Now a points to the start of a free region.
// I can fill in the rest of the page with pointers that chain such free
// regions together.
    uintptr_t base = a;            // base points at the first free cell
    size_t nextPin = consToOffset(a, p);
    while ((nextPin=nextOneBit(p->consPins,consPinBits,nextPin)) != SIZE_MAX)
    {
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("!!Pinned item at %a\n", offsetToCons(nextPin, p));
#endif // EXTREME_DEBUG
// I could use nextZeroBit() here but my expectation is that pinned cons
// cells will not come in long runs, so skipping them individually is going
// to be at least as sensible.
        a = offsetToCons(nextPin, p);
// The first free cell in a block points to the next non-free cell.
        indirect(base) = a;        // write in chaining
// Again I skip pinned cells one at a time.
        while (a != endOfConsPage(p) &&
               consIsPinned(a, p))
        {   a += sizeof(ConsCell);
            nPins++;               // Count the pinned cells
        }
// ... and if I reach the end of the page I am done.
        if (a == endOfConsPage(p))
        {   p->hasPinned = nPins;
            return;
        }
// Now I have the next free block, so record its first location so
// that I can write a pointer into there.
        base = a;
        nextPin = consToOffset(a, p);;
    }
// If I exit here it is because there are no more pinned cells, so the
// end of the free block is the end of the page.
    indirect(base) = endOfConsPage(p);
    p->hasPinned = nPins;
}

void rePinConsPage(Page* p)
{   if (p == consCurrent)
    {   rePinConsCurrent(p);
        return;
    }
// Before I mess with the pin maps I want to arrange that every
// cell that has an old pin but not a new one gets a padder written in.
    size_t loc=0;
    while ((loc = nextOneBit(p->consPins, consPinBits, loc)) != SIZE_MAX)
    {   uintptr_t v = offsetToCons(loc, p);
        if (!consIsNewPinned(v, p)) car(v) = CONS_PADDER_HEADER;
        loc++;
    }
// Move the new pin map to the standard position and clear the "new" version
// ahead of a future GC.
    std::memcpy(p->consPins,
                p->newConsPins,
                consPinBytes);
    std::memset(p->newConsPins, 0, consPinBytes);
    uintptr_t a = offsetToCons(0, p);
    size_t nPins = 0;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("rePin from %a to %a\n", a, endOfConsPage(p));
#endif // EXTREME_DEBUG
// Now I need to scan the page. I will start by skipping past any
// initial pinned items. A pathological situation would be if every single
// cell was pinned, so I have to check for end of page!
    while (a != endOfConsPage(p) &&
           consIsPinned(a, p))
    {
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("!!beginPin %a %s\n", a, consIsPinned(a, p));
#endif // EXTREME_DEBUG
        a += sizeof(ConsCell);
        nPins++;
    }
// In the pathological case I am done, and the page will count as clogged.
    if (a == endOfConsPage(p))
    {   p->hasPinned = nPins;
        return;
    }
    uintptr_t base = a;            // base points at the first free cell
    size_t nextPin = consToOffset(a, p);
    while ((nextPin=nextOneBit(p->consPins,consPinBits,nextPin)) != SIZE_MAX)
    {
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("!!Pinned item at %a\n", offsetToCons(nextPin, p));
#endif // EXTREME_DEBUG
// I could use nextZeroBit() here but my expectation is that pinned cons
// cells will not come in long runs, so skipping them individually is going
// to be at least as sensible.
        a = offsetToCons(nextPin, p);
// The first free cell in a block points to the next non-free cell.
        if (!p->liveData) indirect(base) = a;        // write in chaining
// Again I skip pinned cells one at a time.
        while (a != endOfConsPage(p) &&
               consIsPinned(a, p))
        {   a += sizeof(ConsCell);
            nPins++;               // Count the pinned cells
        }
// And if I reach the end of the page I am done.
        if (a == endOfConsPage(p))
        {   p->hasPinned = nPins;
            return;
        }
// Now I have the next free block, so record its first location so
// that I can write a pointer into there.
        base = a;
        nextPin = consToOffset(a, p);;
    }
// If I exit here it is because there are no more pinned cells, so the
// end of the free block is the end of the page.
    if (!p->liveData) indirect(base) = endOfConsPage(p);
    p->hasPinned = nPins;
}

// There are two cases where vector pages need re-pinning. If the page is
// "old" then any live data in it that is not pinned has been copied away,
// and in that case any extended chunks that are not pinned need to be
// converted back into simple chunks by re-writing chunkSeqNo and chunkLength
// information. If however the page is "new" then space between pinned chunks
// is still important and so the sequence and length info must be preserved.
// For pages that are on vecPinned or vecClogged (or emptyPages) there is
// no live data between pinned chunks but everything should already be
// tidy. So here is a function that cleans up the vector pages that most
// live data has been copied out from.

void cleanUpOldVecPages()
{   for (Page* p:vecOldPages)
    {   size_t c = 0;
        while (c < chunkInfoSize)
        {   uint32_t len = p->chunkLength[c];
            bool pin = chunkNoIsNewPinned(p, c);
// If I find a non-pinned extended chunk I will chop it down into
// multiple simple chunks. For every non-pinned chunk I dump in a
// padder - which should not be necessary but feels both cheap and tidy.
            if (len!=1 && !pin)
            {   for (size_t c1=c+1; c1<c+len; c1++)
                {   p->chunkLength[c1] = 1;
                    p->chunkSeqNo[c1] = 0;
                    setHeaderWord(addressFromChunkNo(p, c1), chunkSize);
                }
                p->chunkLength[c] = 1;
            }
            if (!pin) setHeaderWord(addressFromChunkNo(p, c), chunkSize);
            c += len;
        }
    }
}

void rePinVecPage(Page* p)
{
#ifdef EXTREME_DEBUG
    if (GCTRACE) displayAllPages(where("start repin")); // DEBUG
// Here the page may have some pinned material. The "odd" cases are where
// it had pinned stuff during the previous GC but doesn't any more, and
// where potential pinning during this page turned out to refer into a
// padder.
// There can be more pins this GC than last or less, and I must put
// everything in a state that reflects the current state!
    if (GCTRACE) zprintf("rePinVecPage %a\n", p);
#endif // EXTREME_DEBUG
    std::memcpy(p->vecPins, p->newVecPins, vecPinBytes);
    std::memset(p->newVecPins, 0, vecPinBytes);
// Here if a chunk used to be pinned but is not any more then I need to
// clear it. All the data in it will have been evacuated. A situation where
// this matters when the old pinned chunk is in the middle of a currently
// live page and new data has been copied around it. In a subsequent GC
// since the chunk is not pinned the data in it will get scanned, and it is
// now old data probably containing forwarding pointers. If the chunk
// concerned is in a page that ends up free or is beyond the fringe of
// vecCurrent then there would not be any problem.
    size_t pinnedChunk = 0;
    while ((pinnedChunk = nextOneBit(p->chunkBitmap,
                                     chunkBitmapBits,
                                     pinnedChunk)) != SIZE_MAX)
    {   if (!chunkNoIsNewPinned(p, pinnedChunk))
        {   // Deal with a chunk that use to be pinned but is not any longer.
            uint32_t len = p->chunkLength[pinnedChunk];
            for (uint32_t i=0; i<len; i++)
            {   uintptr_t a = addressFromChunkNo(p, pinnedChunk+i);
                setHeaderWord(a, chunkSize);
                p->chunkSeqNo[pinnedChunk+i] = 0;
            }
            p->chunkLength[pinnedChunk] = 1;
            pinnedChunk =  pinnedChunk + len;
        }
        else pinnedChunk =  pinnedChunk + p->chunkLength[pinnedChunk];
    }
    std::memcpy(p->chunkBitmap, p->newChunkBitmap, sizeof(p->chunkBitmap));
    std::memset(p->newChunkBitmap, 0, sizeof(p->chunkBitmap));
    size_t pinnedChunkCount = 0;
    pinnedChunk = 0;
    while ((pinnedChunk = nextOneBit(p->chunkBitmap,
                                     chunkBitmapBits,
                                     pinnedChunk)) != SIZE_MAX)
    {   // Deal with a chunk that MAY be pinned
        bool anyPinned = false;
        size_t pinEnd = pinnedChunk + p->chunkLength[pinnedChunk];
// So here is a chunk. There may be some pinned material in it.
// I want to arrange that all regions in it apart from the pinned
// objects are padders.
        uintptr_t a = addressFromChunkNo(p, pinnedChunk);
        uintptr_t b = addressFromChunkNo(p, pinEnd);
// Now I have the addresses of the start and end of the chunk. Note that they
// will be 16K aligned. I need to process each pinned item in that range.
// Well that is going to involve looking in vecPins starting at the offset
// for a and ending at the one for b.
        size_t aOffset = vecToOffset(a, p);
        size_t bOffset = vecToOffset(b, p);
// I want to search the bitmap up as far as the end of this chunk, and that
// is not up to the very end of the whole bitmap...
// There is a step that I could take here where at present I do not, and
// which I do not intend to until I have everything else debugged.
// If the first pinned item in a chunk is more than 16K down from the
// front or if an extended chunk in fact has no items in it that are still
// pinned then I can turn at turn all of it into a sequence of basic
// chunks. Detecting and handling that case here will not be costly and it
// (slightly) improves the recycling of memory!
        while ((aOffset=nextOneBit(p->vecPins, bOffset, aOffset)) != SIZE_MAX)
        {   anyPinned = true;
            uintptr_t thePinnedItem = offsetToVec(aOffset, p);
            if (thePinnedItem != a) setHeaderWord(a, thePinnedItem-a);
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("Put padder at %a length %d\n", a, thePinnedItem-a);
#endif // EXTREME_DEBUG
            Header h = indirect(thePinnedItem);
#ifdef EXTREME_DEBUG
            if (GCTRACE) zprintf("Pinned item at %a length %d\n", thePinnedItem, length_of_any_header(h));
#endif // EXTREME_DEBUG
            a = thePinnedItem + doubleword_align_up(length_of_any_header(h));
            aOffset = vecToOffset(a, p);
        }
        if (a != b) setHeaderWord(a, b-a);
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("final padder at %a length %d\n", a, b-a);
#endif // EXTREME_DEBUG
        if (anyPinned) pinnedChunkCount++;
        else
        {
// I rather think that that this fragment of code ought not be to invoked
// ever - but I need to think a bit harder!
            my_abort(where("#### Should I be here? ####"));
            for (size_t i=pinnedChunk; i<pinEnd; i++)
            {   p->chunkSeqNo[i] = 0;
                p->chunkLength[i] = 1;
                chunkNoClearPinned(p, i);
            }
        }
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("pinned chunk from %d to %d\n", pinnedChunk, pinEnd);
#endif // EXTREME_DEBUG
        pinnedChunk = pinEnd;
    }
    p->hasPinned = pinnedChunkCount;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("pinnedChunkCount = %d\n", pinnedChunkCount);
    if (GCTRACE) displayAllPages(where("end repin")); // DEBUG
#endif // EXTREME_DEBUG
}

void tidyUpPinmaps()
{   cleanUpOldVecPages();
    Page* r = nullptr;
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("tidyUpPinmaps with pinnedPages = %a\n", pinnedPages);
#endif // EXTREME_DEBUG
    while (pinnedPages != nullptr)
    {   Page*p = pinnedPages;
        pinnedPages = p->pinnedPages;
        switch (p->type)
        {
        case consPageType:
            rePinConsPage(p);
            if (p->hasPinned != 0)
            {   p->pinnedPages = r;
                r = p;
            }
            continue;
        case vecPageType:
            rePinVecPage(p);
            if (p->hasPinned != 0)
            {   p->pinnedPages = r;
                r = p;
            }
            continue;
        default:
            my_abort(where("illegal page type"));
        }
    }
    pinnedPages = r;
}


// I have the following two threshold values which have not been selected
// based on measurement - they are guesses! If a page has more pinning in it
// than the limit set here I will not make it available for re-allocation.
// That is because allocation around many pinned items has a performance
// implication. However declaring too many pages as "clogged" could lead to
// memory becoming exhausted too soon.

const size_t consClogThreshold = 500;
const size_t vecClogThreshold  = 50;

// Here I need to review the pages in consPinPages etc as well as
// condOldPages, since I hope that the number of pins will have
// reduced and so the pages may even now end up empty.

void recycleOldSpace()
{   consOldPages += consPinPages;
    consOldPages += consCloggedPages;
    while (!consOldPages.isEmpty())
    {   Page* p = consOldPages.pop();
        p->dataEnd = offsetToCons(0, p);
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("cons Page %a has %d pins\n", p, p->hasPinned);
#endif // EXTREME_DEBUG
        if (p->hasPinned == 0) emptyPages.push(p);
        else if (p->hasPinned < consClogThreshold) consPinPages.push(p);
        else consCloggedPages.push(p);
    }
    vecOldPages += vecPinPages;
    vecOldPages += vecCloggedPages;
    while (!vecOldPages.isEmpty())
    {   Page* p = vecOldPages.pop();
        p->dataEnd = offsetToVec(0, p);
#ifdef EXTREME_DEBUG
        if (GCTRACE) zprintf("vec Page %a has %d pins\n", p, p->hasPinned);
#endif // EXTREME_DEBUG
        if (p->hasPinned == 0) emptyPages.push(p);
        else if (p->hasPinned < vecClogThreshold) vecPinPages.push(p);
        else vecCloggedPages.push(p);
    }

}

void reportOnConsPage(const char* s, Page* p)
{   int n = countBits(p->consPins, 0, 64*Page::consPinWords);
    uintptr_t top = p==consCurrent ? consFringe : p->dataEnd;
    zprintf("%s: Cons page %a has %d pins and %d cells in use\n",
            s, p, n, (top-offsetToCons(0, p))/sizeof(ConsCell));
}

void reportOnVecPage(const char* s, Page* p)
{   int n = countBits(p->chunkBitmap, 0, 64*Page::chunkBitmapWords);
    int m = countBits(p->vecPins, 0, 64*Page::vecPinWords);
    zprintf("%s: Vec page %a has %d pinned chunks and %d pinned objects\n",
            s, p, n, m);
    uintptr_t top = p==vecCurrent ? vecFringe : p->dataEnd;
    uintptr_t used = (top - addressFromChunkNo(p, 0))/sizeof(LispObject);
    zprintf("  with %d cells in use\n", used);
}

// I start garbage collection by  making the current allocation pages
// have the structure of ones that are full. The only thing that involves
// is storing fringe pointers in them.

bool withinGarbageCollector = false;

void inner_garbage_collect()
{
// The hash table support caches blocks of memory in a way intended to
// reduce allocation and re-allocation overhead when hash tables need to
// grow or shrink. The place where I keep the recycled memory contains
// references to abandoned data (in general things used as parts of
// hash tables) and none of the material there is in use. It exists so
// that re-use as between garbage collections can sometimes be cheaper.
// But when a GC starts I clear it away because the stuff in it can then be
// recycled in the normal manner. 
    for (size_t i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
        free_vectors[i] = nil;
    multiplication_buffer = nil;   // Treat this as a weak pointer.
    WithinGarbageCollector noted;
    if (gcNumber == gcError) aerror("garbage collector limit reached");
    if (gcNumber == gcStop) give_up("gcStop triggered");
#ifdef EXTREME_DEBUG
    if (GCTRACE) displayAllPages("Start of GC");
    validateAll("start GC", false, false);
    allPinned.clear();
    evacuated.clear();
#endif // EXTREME_DEBUG
// I start by setting the end-point information in the two current pages.
// That leaves them in the proprer state to count as "full", so that when
// the GC looks at ambiguous pointers it will be able to be aware when
// an apparent pointer is to a location above the fringe. Note that any
// final chunk in the vector page may need to have a padder inserted.
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("set %a dataEnd = %a\n", consCurrent, consFringe);
#endif // EXTREME_DEBUG
    consCurrent->dataEnd = consFringe;
    if (vecFringe != vecLimit) setHeaderWord(vecFringe, vecLimit-vecFringe);
#ifdef EXTREME_DEBUG
    if (GCTRACE) zprintf("set %a dataEnd = %a\n", vecCurrent, vecLimit);
#endif // EXTREME_DEBUG
    vecCurrent->dataEnd = vecLimit;
#ifdef DEBUG
    if (force_verbos)
    {  for (auto p:consPages) reportOnConsPage("start of GC", p);
       for (auto p:vecPages) reportOnVecPage("start of GC", p);
    }
#endif // DEBUG
// Next I move the currently used pages to an "old" chain.
    consOldPages = consPages;
    for (Page* p:consOldPages) p->liveData = false;
    vecOldPages = vecPages;
    for (Page* p:vecOldPages) p->liveData = false;
    potentiallyPinned = nullptr;
// ... and allocate what will be the start of the new half-space.
// Well here I will not want any ambiguous pointers into this new
// space to be deemed valid, and I will be putting stuff into the
// CONS region as a list of pinned objects - so on a temporary basis
// I will mark the pages as free!
    grabFreshPage(consPageType);
#ifdef EXTREME_DEBUG
    validateAll("GC setup");
#endif // EXTREME_DEBUG
// Now I can scan the stack and mark up pinned items. This will build
// up a chain of pages pinned this time.
// For each such page it will create a list of the pinned locations, where
// the "pointers" in that list are tagged so that the GC will view then as
// integers rather than references, and so not be tempted into following
// them. But the nodes that make up the list there could by some mischance
// now have their new pin bit set. I will tidy that up!
    identifyPinnedItems();
#ifdef EXTREME_DEBUG
    validateAll("identifyPinnedItems done");
#endif // EXTREME_DEBUG
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
#ifdef EXTREME_DEBUG
    validateAll("findHeadersOfPinnedItems done");
#endif // EXTREME_DEBUG
    pendingPages = nullptr;
#ifdef EXTREME_DEBUG
    if (GCTRACE)
    {   zprintf("Report on pinning...\n");
        for (Page* pp=pinnedPages; pp!=nullptr; pp=pp->pinnedPages)
        {   zprintf("Page %a contains some pinned material\n", pp);
            for (LispObject c=pp->pinnedObjects-TAG_FIXNUM;
                            c!=0;
                            c=cdr(c)-TAG_FIXNUM)
                zprintf("Pinned object at address %a\n", car(c)-TAG_FIXNUM);
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
#endif // EXTREME_DEBUG
// There is no need to set up a new vector current page until now.
    grabFreshPage(vecPageType);
#ifdef EXTREME_DEBUG
    validateAll("ready to start evacuating");
    if (GCTRACE) displayAllPages(where("findHeadersOfPinnedItems done"));
#endif // EXTREME_DEBUG
// I arrange that the very first vector item I copy is the vector that is
// the current "package", ie hash table of symbols. I do this because it
// is liable to be a large vector so putting it first avoids some padding
// waste (maybe!).
#ifdef EXTREME_DEBUG
    validateAll("just before evacuateFromPinnedItems", true);
#endif // EXTREME_DEBUG
    evacuateFromPinnedItems();
#ifdef EXTREME_DEBUG
    validateAll("evacuateFromPinnedItems done", true);
#endif // EXTREME_DEBUG
    evacuateFromUnambiguousBases();
#ifdef EXTREME_DEBUG
    validateAll("evacuateFromUnambiguousBases done", true);
    if (GCTRACE) displayAllPages(where("unambig bases evacuated"));
#endif // EXTREME_DEBUG
    evacuateFromCopiedData();
#ifdef EXTREME_DEBUG
    validateAll("evacuateFromCopiedDate done", false, false);
#endif // EXTREME_DEBUG
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
// consPinPages. And similarly for vector pages. Well only page on the list
// pinnedPages can have any set bits in their new pinmaps and so I do not
// need to worry about others!
    tidyUpPinmaps();
#ifdef EXTREME_DEBUG
    validateAll("tidyUpPinmaps done", false, false);
#endif // EXTREME_DEBUG
    recycleOldSpace();
#ifdef EXTREME_DEBUG
    validateAll("tidyUpPinmaps done", false, false);
    if (GCTRACE) displayAllPages("End of GC");
#endif // EXTREME_DEBUG
    if (force_verbos)
    {  for (auto p:consPages) reportOnConsPage("end of GC", p);
       for (auto p:vecPages) reportOnVecPage("end of GC", p);
    }
    consCounter = 0;
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

static volatile std::atomic<uint64_t> volatileVar = 0xf0f0f0f012345678u;

#if 0
// The following definition is what I mean if I follow "the Spirit of C"
// and the compiler does what I clearly intend. However C++ takes the
// view that returning the address of a local variable leads to undefined
// behaviour and on some compilers (I am observing g++ on 32 bit platforms)
// the function getStackFringe as defined here always returns zero. Leading
// to collapse! g++ is probably within its rights since using the address
// of a local item when its scope has been exited  will count as
// "undefined behaviour" and so the language specification allows utterly
// any consequences that the compiler writer settles on. Furthermore g++
// issues a warning message. But this all means that I go through a more
// complicated scheme that is intended to achieve exactly the effect I
// originally intended but that will bemuse compilers into not playing
// too many silly games.

NOINLINE uintptr_t getStackFringe(double x)
{   return reinterpret_cast<uintptr_t>(&x);
}
#else
// This attempts to guide g++ into doing what I want. The "NOINLINE" is
// to reduce its ability to compile code based on full analysis of the
// dodgy thing I am asking. getStackFringe now passes the address of
// its local variable to a called function which in fact will be
// getStackFringeHelper, but it should not be able to count on that.

NOINLINE uintptr_t getStackFringeHelper(double* dd)
{   return reinterpret_cast<uintptr_t>(dd);
}

NOINLINE uintptr_t getStackFringe(uintptr_t (*f)(double*), double x)
{   return (*f)(&x);

}
#endif

void use_gchook(LispObject arg)
{
    LispObject g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var && g != nil)
        {   class save_trapcount
            {   uint64_t count, target;
                LispObject* savedStack;
            public:
// Calling the hook must not disturm any list-bases and really ought not
// to be able to upset various other important static variables, so
// when I am going to use it I save a load of state.
                save_trapcount()
                {   count = reclaim_trigger_count;
                    target = reclaim_trigger_target;
                    reclaim_trigger_target = 0;
                    for (LispObject* p:list_bases) *++stack = *p;
                    savedStack = stack;
                }
                ~save_trapcount()
                {   reclaim_trigger_count = count;
                    reclaim_trigger_target = target;
                    stack = savedStack;
                    for (size_t i=sizeof(list_bases)/sizeof(list_bases[0]);
                         i>0;
                         i--) *list_bases[i-1] = *stack--;
                }
            } RAII_trapcount;
            RealSave save(B_reg, callStack);
            Lapply1(nil, g, arg);  // Call the hook
            save.restore(B_reg, callStack);
        }
    }
}

static void report_at_end(uint64_t t0)
{   int n = consPages.count + vecPages.count;
    int n1 = n + emptyPages.count + consPinPages.count + vecPinPages.count +
             consCloggedPages.count + vecCloggedPages.count +
             (pageEnd - pageFringe);
    double fn = static_cast<double>(n)*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double fn1 = static_cast<double>(n1)*(CSL_PAGE_SIZE/(1024.0*1024.0));
// I might want to adjust fn here for the extent to which consCurrent and
// vecCurrent are not at this stage totally full.
    double z = (100.0*n)/n1;
#ifdef WITH_GUI
    report_space(gcNumber, z, fn1);
#endif // WITH_GUI
    if (verbos_flag & 1 || force_verbos)
    {   trace_printf(
            "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
            fn, fn1, z);
    }
#ifndef GC_CHECK
// If the system was defined with GC_CHECK enables it will try to compare
// the state of the heap at the end of GC against that at the start and
// it will object if it sees ANY changes. In particular these benign and
// intended changes would confuse it... so in that case I do not
// record this information.
//
// This reports in Kbytes, and does not overflow until over 100 Gbytes
    qvalue(used_space) = fixnum_of_int(static_cast<int>(1024.0*fn));
    qvalue(avail_space) = fixnum_of_int(static_cast<int>(1024.0*fn1));
    qvalue(gccount_symbol) = fixnum_of_int(gcNumber);
#endif
    uint64_t t1 = read_clock();
    gc_time += (t1 - t0);
    base_time += (t1 - t0);
    stackcheck();
    gc_start();
    use_gchook(lisp_true);
}

NOINLINE void garbage_collect(const char* why)
{   gcNumber++;
////    gc_start();
    uint64_t t0 = read_clock();
#ifdef WITH_GUI
// If I have a window system I tell it the current time every so often
// just to keep things cheery... so in such cases I will read the time
// every time there is a garbage collection regardless of whether I am
// generating GC messages. If I am not on a GUI system then  I only
// report time if GC messages are enabled, so I will only read the clock
// in that situation.
    {   uint64_t t = (t0 - base_time)/10000; // in centiseconds
        uint64_t gct = gc_time/10000;
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
        report_time(t, gct);
        time_now = read_clock()/1000;
        if ((verbos_flag & 1) || force_verbos)
        {   freshline_trace();
            trace_printf(
                "+++ Garbage collection %d"
                " (%s) after %" PRIu64 ".%.2" PRIu64 "+"
                "%" PRIu64 ".%.2" PRIu64 " seconds\n",
                gcNumber, why, t/100, t%100, gct/100, gct%100);
        }
    }
#else // !WITH_GUI
    if ((verbos_flag & 1) || force_verbos)
    {   uint64_t t = (t0 - base_time)/10000;
        uint64_t gct = gc_time/10000;
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
        time_now = t0/1000;
        freshline_trace();
        trace_printf(
            "+++ Garbage collection %ld (%s) after %" PRIu64 ".%.2" PRIu64"+"
            "%" PRIu64 ".%.2" PRIu64 " seconds\n",
            static_cast<long>(gcNumber), why, t/100, t%100, gct/100, gct%100);
    }
#endif // !WITH_GUI
    std::jmp_buf buffer;
    buffer_pointer = &buffer;
// This is a silly hack! The idea is that as far as the compiler is
// allowed to assune, each reference to volatileVar might return a different
// value. So a1-a18 all hold notionally independent values. I rather hope
// that many of those will be placed in machine registers, flushing
// any values from the caller to the stack. And because thay are all
// independent each needs its own register! So the "volatile" qualification
// ensures that the compiler turns each use of the variable into a separate
// operation (rather than optimising some out). And use of std::atomic
// should reinforce that by further stressing that some independent action
// might change the value of the variable at any time. Well whole-program
// analysis might reveal that no such oddites actially arise here.
    uint64_t a1 = volatileVar; uint64_t a2 = volatileVar; uint64_t a3 = volatileVar;
    uint64_t a4 = volatileVar; uint64_t a5 = volatileVar; uint64_t a6 = volatileVar;
    uint64_t a7 = volatileVar; uint64_t a8 = volatileVar; uint64_t a9 = volatileVar;
    uint64_t a10 = volatileVar; uint64_t a11 = volatileVar; uint64_t a12 = volatileVar;
    uint64_t a13 = volatileVar; uint64_t a14 = volatileVar; uint64_t a15 = volatileVar;
    uint64_t a16 = volatileVar; uint64_t a17 = volatileVar; uint64_t a18 = volatileVar;
    for (int i=0; i<1000000; i++)
    {   if (setjmp(buffer) == 0)
        {
// See the comments by the definition of getStackFringe for comments on
// how a C++ compiler can react sharply to me trying to get the current
// C stack pointer.
            C_stackFringe = getStackFringe(getStackFringeHelper, 1.0);
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
// Of course all I do here is slightly ridiculous! And none of if really
// gives guarantees. Well the whole issue of there being a contiguous
// stack as the only place the compiler stashes things is very much an
// assumption! In many respects all I do here is an amazing waste of
// resources, but the cost will be minuscule measured against the total
// cost of garbage collection that it is seeking to protect.
        if (volatileVar == volatileVar) break;
    }
// End of garbage collection!
/////    gc_end(false);
/////    gc_start();
    report_at_end(t0);
    gc_end(true);
}

NOINLINE void garbage_collect()
{   garbage_collect("some reason");
}

#ifdef DEBUG

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

// This version only supports the first segment of pages... and it does not
// do any checking for the validity of either of its arguments. It is probably
// quite close to what unAddr() in newallocate.h ought to have been. I give
// it a very short name since I will be using it while debugging and typing
// in uses of it to gdb.

uintptr_t V(int pageNumber, size_t offset)
{   Page* p = reinterpret_cast<Page*>(heapSegment[0]) + pageNumber;
    if (p->type == consPageType)
        return offsetToCons(offset/sizeof(ConsCell), p);
    else return offsetToVec(offset/8, p);
}

// This does a displayAllPages but redirects the output so it gets
// put in a named file.

void dumpToFile(const char* filename)
{   std::ofstream out(filename);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    displayAllPages("dumpToFile");
    std::cout.rdbuf(coutbuf); //reset to standard output again
}

#endif // DEBUG

