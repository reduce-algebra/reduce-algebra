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

static size_t nSymbols = 0;
static LispObject* vecOfSymbols = nullptr;
static uint64_t*   sigOfSymbols = nullptr;

void gc_start()
{   cout << "\n@@@ Start of garbage collection\n";
// First record the regular list bases.
    for (size_t i=0; i<list_bases_size; i++)
    {   save_bases[i] = *list_bases[i];
        checksum_bases[i] = gc_checksum(*list_bases[i]);
    }
// Now find every symbol in the heap and record info about
// value, property list and environment components.
    LispObject* stacksave = stack;
    if (push_all_symbols(always))
    {   stack = stacksave;
        vecOfSymbols = nullptr;
        sigOfSymbols = nullptr;
        nSymbols = 0;
    }
    else
    {   nSymbols = stack-stacksave;
        vecOfSymbols = new (std::nothrow) LispObject[nSymbols];
        if (vecOfSymbols == nullptr) nSymbols = 0;
        else
        {   sigOfSymbols = new (std::nothrow) uint64_t[nSymbols];
            if (sigOfSymbols == nullptr)
            {   delete[] vecOfSymbols;
                vecOfSymbols = nullptr;
                nSymbols = 0;
            }
            else
            {   size_t i=0;
                while (stack != stacksave)
                {   LispObject w = *stack--;
                    vecOfSymbols[i] = w;
                    sigOfSymbols[i++] = 19937*gc_checksum(qvalue(w)) +
                                        11213*gc_checksum(qenv(w)) +
                                        gc_checksum(qplist(w));
                }
            }
        }
    }
}

static size_t nSymbolsAfter = 0;
static LispObject* vecOfSymbolsAfter = nullptr;
static uint64_t*   sigOfSymbolsAfter = nullptr;

void gc_end(bool final)
{
    if (final) cout << "\n@@@ about to check at end of garbage collection\n";
    else cout << "\n@@@ about to check just before GC hook\n";
    for (size_t i=0; i<list_bases_size; i++)
    {   if (checksum_bases[i] != gc_checksum(*list_bases[i]))
        {   std::cout << list_names[i]
                      << " " << checksum_bases[i]
                      << " " << gc_checksum(*list_bases[i])
                      << "\n";
        }
    }
// Find every symbol in the new version of the heap and check info about
// value, property list and environment components.
    LispObject* stacksave = stack;
    if (push_all_symbols(always))
    {   stack = stacksave;
        vecOfSymbolsAfter = nullptr;
        sigOfSymbolsAfter = nullptr;
        nSymbolsAfter = 0;
    }
    else
    {   nSymbolsAfter = stack-stacksave;
        vecOfSymbolsAfter = new (std::nothrow) LispObject[nSymbolsAfter];
        if (vecOfSymbolsAfter == nullptr) nSymbolsAfter = 0;
        else
        {   sigOfSymbolsAfter = new (std::nothrow) uint64_t[nSymbolsAfter];
            if (sigOfSymbolsAfter == nullptr)
            {   delete[] vecOfSymbolsAfter;
                vecOfSymbolsAfter = nullptr;
                nSymbolsAfter = 0;
            }
            else
            {   size_t i=0;
                while (stack != stacksave)
                {   LispObject w = *stack--;
                    vecOfSymbolsAfter[i] = w;
                    sigOfSymbolsAfter[i++] =
                        19937*gc_checksum(qvalue(w)) +
                        11213*gc_checksum(qenv(w)) +
                        gc_checksum(qplist(w));
                }
            }
        }
    }
    if (nSymbols != nSymbolsAfter)
    {   std::cout << "symbol count has changed from"
            << nSymbols << " to " << nSymbolsAfter << "\n";
        my_abort();
    }
    cout << "@@@ reviewing " << nSymbols << " symbols\n";
    for (size_t i=0; i<nSymbols; i++)
    {   if (sigOfSymbols[i]!=sigOfSymbolsAfter[i])
        {   std::cout << "Symbol " << i << " bad\n";
            LispObject name = qpname(vecOfSymbolsAfter[i]);
            if (is_vector(name))
            {   size_t len = length_of_byteheader(vechdr(name));
                string sname = string(sizeof(LispObject)+(char *)name, len);
                std::cout << "Name is: " << sname << "\n";
            }
        }
    }
    if (final && nSymbols!=0)
    {   delete [] vecOfSymbols;
        delete [] sigOfSymbols;
        nSymbols=0;
    }
    if (nSymbolsAfter!=0)
    {   delete [] vecOfSymbolsAfter;
        delete [] sigOfSymbolsAfter;
        nSymbolsAfter=0;
    }
    if (final) cout << "\n@@@ End of garbage collection\n";
    else cout << "\n@@@ Just before GC hook\n";
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
