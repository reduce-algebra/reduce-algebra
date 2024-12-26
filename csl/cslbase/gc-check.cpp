// gc-checker.cpp                               Copyright (C) 2024 Codemist


/**************************************************************************
 * Copyright (C) 2024, Codemist.                         A C Norman       *
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

// $Id: gc-checker.cpp 6911 2024-12-21 22:59:22Z arthurcnorman $


// The code here will be for checking garbage collection - because
// bug-hunting in that area is particularly challenging.
//
// The strategy is that this allocates a load of private memory for its
// own use. At the start of a GC it makes copies of all of the heap
// (and as a matter of caution this will include pages not believed to be
// in use) and all the standard list bases plus all the pointer fields
// from symbols on the object list.
//
// At the end of GC it can then perform a compare operation between the
// contents of the original list bases and the state they have been updated
// to. This needs to be recursive traversal of the old and new versions
// of the data. It can terminate at symbols but it recurses through
// vectors. It checks the contents of binary vectors (eg strings and
// bignums). I may be able to do at least some checking on the GC fringe
// and limit pointers, but the emphasis will be on validating the main
// contents of the heap.
//
// I do not mind much if this code is not especially efficient either
// in space or time, because it will only be activated when either
// performing regression tests following changes to storage management
// or when hunting bugs. The key idea is that if the GC damages anthing
// this should be able to report promptly while in all normal usage any
// corruption by the GC will have delayed consequences. And I hope this
// will be able to highlight the precise before and after locations of
// any trouble.
//
// It is probable that this will be used alongside the command line
// options "--gc-every NNN" and "--gc-stop N" which respectively cause
// a garbage collection (about) every NNN uses of CONS and then stops
// after GC number N.

#include "headers.h"

#ifdef GC_CHECK

static constexpr size_t list_bases_size =
    sizeof(list_bases)/sizeof(LispObject);

static LispObject save_bases[list_bases_size];
static uint64_t checksum_bases[list_bases_size];

static uint64_t gc_checksum(LispObject a, size_t depth=10)
{   if (!is_cons(a) || depth==0) return a & TAG_BITS;
    uint64_t c = gc_checksum(car(a), depth-1);
    uint64_t d = gc_checksum(cdr(a), depth-1);
    return 19937*c + d;
}

void gc_start()
{   cout << "\n@@@ Start of garbage collection\n";
    for (size_t i=0; i<list_bases_size; i++)
    {   save_bases[i] = *list_bases[i];
        checksum_bases[i] = gc_checksum(*list_bases[i]);
    }
}

void gc_end()
{
    cout << "\n@@@ End of garbage collection\n";
    for (size_t i=0; i<list_bases_size; i++)
        if (checksum_bases[i] != gc_checksum(*list_bases[i]))
        {   std::cout << list_names[i]
                      << " " << checksum_bases[i]
                      << " " << gc_checksum(*list_bases[i])
                      << "\n";
        }
}

#else // GC_CHECK

void gc_start()
{
}

void gc_end()
{
}

#endif // GC_CHECK


// end of gc-checker.cpp
