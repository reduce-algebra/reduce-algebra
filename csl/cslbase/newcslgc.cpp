// File cslgc.cpp                         Copyright (c) Codemist, 1990-2019

//
// Garbage collection.
//

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

#include "headers.h"


// This may end up as a command-line option or it may end up always
// enabled, but for now there is no code for generational garbage
// collection so it needs to be false!

bool generationalGarbageCollection = false;

void generationalGarbageCollect()
{   std::cout << "\n+++++ Attempt to perform a generational GC\n";
    my_abort();
}

// Overview of procedure for full garbage collection:
//
// For garbage collection I will refer to the full half-space as "A"
// for Active, the empty one as "C" for Clear. At the entry to GC I will
// expect that all pages in C have chaining set up in them in the form
//
//   |.....................XXXXXpq.........XXXXXrs.........XXXXXt0......|
//    ^                    ^    ^          ^    ^          ^    ^       ^
//  gFringe             gLimit gNext       p    q          r    s       t
// where XXXX denote items pinned by a previous GC, p is a subsequent limit
// and q a subsequent next (and similarly for r,s,t) with the follow-on next
// value zero at the end of the page.
// Within the active part of the heap there will be a list pinsC that has
// pointers to each pinned item in C. This is not a Lisp standard list - it
// will be chained in the CAR field with pointers tagged as FORWARD while the
// CDR field of each entry refers to the pinned item. I may later arrange that
// this list is sorted, but at the current stage of my design and coding I will
// just describe it as a list with the contents as explained here.
// I should note that at the start of a GC the object-start and pinned bitmaps
// for each page contain junk - that is because those two bitmaps share space
// with maps used for write barriers. During a global GC write barrier data
// is not used.
//
// When I say that all pages in C have freespace mapping in them I will in
// fact in due course arrange that on a "lazy" basis so that from when the
// program starts up I only initialize a page when I am first about to use
// it.

// (1) Clear the "pinned" maps for pages in A.
//     Initialize pinsA list to be empty.
//
// (2) For each ambiguous value (ie value on the stack associated with
//     any thread) do:
//   If value could not be a pointer into A then ignore it.
//   Ensure that object-starts bitmap in relevant page of A is set up.
//   Identify the start of the object in A that the value might refer to.
//   If that item is already pinned then no need to do more.
//   If that object is part of pinsC (because the CAR field contains
//     something tagged as FORWARD) do no more.
//   Set pinned bit for the location concerned. Mark page as one that
//     contains pinned items.
//   Add the pinned item to the list pinsA, which is built in space C.
//
// (3) Evacuate each of the following locations:
//   (a) Every precise pointer.
//   (b) Every pointer field in any object in list pinsC.
//   (c) Every pointer field in any object copies into C in via the
//       evacuation process.
//   See later for explanation of "evacuate".
//
// (4) Set up A with the structure needed to be an empty page, ie
//   a gFringe/gLimit/gNext chain that works around pinned items. To do this
//   a sorted version of pinsA is liable to be useful, especially if while
//   doing this I can have all pages making up A in a sorted list.
//
// (5) Flip status and interpretation of A and C.
//
//
// Evacution:
//   If the location to be evacuated holds immediate data do nothing,
//     otherwise it holds a pointer to some object.
//   If that object is not in A or it is in A but is pinned then do nothing.
//   If the CAR field of the object holds a forwarding address use that to
//     update the location to be a proper pointer to relocated data. Done!
//   Make a (binary) copy of the object in the next free space within C.
//   Set the CAR field to be a forwarding address to the copy.
// Note that the copy will then (in due course) be scanned under (3.c).


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
// C++ array ,use std::sort to get it in the right order and then patch
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
    Concrete r, rp;
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

// Pages are chained via a "pageHeader.chain" field. I will want to
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
    {   return p->pageHeader.chain;
    }
    static void rplacd(Page *p, Page *x)
    {   p->pageHeader.chain = x;
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
    static std::uintptr_t nil()
    {   return TAG_FORWARD;
    }
    static bool isNil(std::uintptr_t p)
    {   return p == TAG_FORWARD;
    }
    static std::uintptr_t cdr(std::uintptr_t p)
    {   return ((std::uintptr_t *)(p-TAG_FORWARD))[0];
    }
    static void rplacd(std::uintptr_t p, std::uintptr_t x)
    {   ((std::uintptr_t *)(p-TAG_FORWARD))[0] = x;
    }
    static bool before(std::uintptr_t x, std::uintptr_t y)
    {   return ((std::uintptr_t *)(x-TAG_FORWARD))[1] <
               ((std::uintptr_t *)(y-TAG_FORWARD))[1];
    }
};

std::uintptr_t sortPinList(std::uintptr_t l)
{   return sortList<std::uintptr_t, PinChainClass>(l);
}


void fullGarbageCollect()
{   std::cout << "\n+++++ Start of a full GC\n";
    my_abort();
}

// end of file cslgc.cpp
