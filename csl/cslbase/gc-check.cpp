// gc-check.cpp                                 Copyright (C) 2025 Codemist


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

// $Id: gc-check.cpp 6911 2024-12-21 22:59:22Z arthurcnorman $


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

// Here I use a plausible 64-bit multiplier but what happens there only
// migrates information upwards within the row of 64 bits, so I xor back
// the top 11 bits to mix them in just a little more. This is frivolous and
// is done without me being an expert on any of this. I also arrange that the
// result is never zero.

uint64_t CC(uint64_t a, uint64_t b)
{   a = a + 6364136223846793005U*b;
    a = a ^ (a >> 53);
    if (a==0) return 1;
    else return a;
}

// Using a depth limit here is simpler than trying to detect loops but
// means that data nested deeply within lists may not be checked.
// I will use a form of cacheing to reduce the waste of repeating
// checksum calculation.

static const size_t cacheSize = 1000000;

static size_t checksumCacheDepth[cacheSize];
static LispObject checksumCacheKey[cacheSize];
static uint64_t checksumCache[cacheSize] = {0};

static uint64_t gc_checksub(LispObject a, size_t depth);

static uint64_t gc_checksum(LispObject a, size_t depth=30)
{   size_t ha = (6364136223846793005U*a + 314159*depth) % cacheSize;
    LispObject k = checksumCacheKey[ha];
    uint64_t v = checksumCache[ha];
    if (k == a && checksumCacheDepth[ha]==depth && v != 0) return v;
    v = gc_checksub(a, depth);
    checksumCacheKey[ha] = a;
    checksumCacheDepth[ha] = depth;
    checksumCache[ha] = v;
    return v;
}

static uint64_t gc_checksub(LispObject a, size_t depth)
{   if (depth==0) return 100+(a & TAG_BITS);
    if (is_cons(a)) return CC(gc_checksum(car(a), depth-1),
                              gc_checksum(cdr(a), depth-1));
// current_package has a value which is a vector of all symbols. I will
// scan the symbols a 
    if (a == current_package) return
       CC(gc_checksum(qenv(a), depth-1),
          CC(gc_checksum(qplist(a), depth-1),
             CC(gc_checksum(qfastgets(a), depth-1),
                gc_checksum(qpname(a), depth-1))));
// current_package has a value that is a vector containing references to
// (almost) all symbols. Since I will detect and scan them otherwise I do
// not want to do that here.
    if (a == current_package) return
       CC(gc_checksum(qvalue(a), 1),
          CC(gc_checksum(qenv(a), depth-1),
             CC(gc_checksum(qplist(a), depth-1),
                CC(gc_checksum(qfastgets(a), depth-1),
                   gc_checksum(qpname(a), depth-1)))));
    if (is_symbol(a)) return
       CC(gc_checksum(qvalue(a), depth-1),
          CC(gc_checksum(qenv(a), depth-1),
             CC(gc_checksum(qplist(a), depth-1),
                CC(gc_checksum(qfastgets(a), depth-1),
                   gc_checksum(qpname(a), depth-1)))));
    if (is_simple_string(a))
    {   size_t len = length_of_byteheader(vechdr(a)) - sizeof(LispObject);
        uint64_t h = 1;
        if (len > 2) len = 2; //@@@
        for (size_t i=0; i<len; i++) h = CC(h, basic_ucelt(a, i));
        return h;
    }
    if (a == lisp_package) return 11111111;
    if (is_vector(a) && !vector_header_of_binary(vechdr(a)))
    {   size_t len = length_of_header(vechdr(a))/sizeof(LispObject)-1;
        if (is_mixed_header(vechdr(a))) len = 3;
        uint64_t h = 1;
        for (size_t i=0; i<len; i++)
            h = CC(h, gc_checksum(basic_elt(a, i), depth-1));
        return h;
    }
    if (is_fixnum(a)) return a;
// I have not handled BIGNUMS or rational/complex numbers or floats here yet.
    return 101+(a&TAG_BITS);
}         

static size_t nSymbols = 0;
static LispObject* vecOfSymbols = nullptr;
static uint64_t*   sigOfSymbols = nullptr;

static size_t nStack = 0;
static uint64_t*   sigOfStack = nullptr;

int gc_pipes[2];

// This is the concept for the code that retrieves stuff.
// template <typename T>
// T oldMem(T* addr)
// {   if (gc_pipes[1] == 0) return 0;
//     if (write(gc_pipes[1], addr, sizeof(addr)) != sizeof(addr)) return 0;
//     T data;
//     if (read(gc_pipes[0], data, sizeof(data)) != sizeof(data)) return 0;
//     return (T)data;
// }

void gc_start()
{   cout << "\n@@@ Start of garbage collection\n";
    memset(checksumCacheKey, 0, sizeof(checksumCacheKey));
    memset(checksumCacheDepth, 0xff, sizeof(checksumCacheDepth));
    memset(checksumCache, 0, sizeof(checksumCache));
// First record the regular list bases.
    for (size_t i=0; i<list_bases_size; i++)
    {   save_bases[i] = *list_bases[i];
        checksum_bases[i] = gc_checksum(*list_bases[i]);
    }
// Next the Lisp stack
    nStack = stack - reinterpret_cast<LispObject*>(stackBase);
    sigOfStack = new (std::nothrow) uint64_t[nStack];
    if (sigOfStack==nullptr) nStack = 0;
    for (size_t i=0; i<nStack; i++)
        sigOfStack[i] = gc_checksum(reinterpret_cast<LispObject*>(stackBase)[i+1]);
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
                    sigOfSymbols[i++] = gc_checksum(w);
                }
            }
        }
    }
    pipe(gc_pipes);
    pid_t pid = fork();
    if (pid == 0)
    {
// The child process preserves the state that memory was in at this point
// and provides a service whereby it can return data from that saved
// state if given an address. If an address zero is passed (or if
// the pipe has been closed do that the attempt to read from it fails)
// the child process terminates.
        for (;;)
        {   uintptr_t addr;
// I am going to suppose that read() and write() do not run foul of strict
// aliasing and so I can pass them pointers to whatever sort of data I like
// and provided at the two ends of the pipe use the same datatype there
// that all will be well. Ha ha ha re the rules.
            if (read(gc_pipes[0], &addr, sizeof(addr)) != sizeof(addr) ||
                addr == 0) break;
// Here I read the data byte by byte so that if I am passed an unaligned
// address things behave the way I want. The key use case for this is when
// what I want to fetch is just a character and so I fetch 64-bits but
// just keep the lowest 8 of them.
            char* p = reinterpret_cast<char*>(&addr);
            uint64_t d = 0;
            for (int i=0; i<8; i++)
                d = d<<8 | (p[7-i] & 0xff);
            write(gc_pipes[1], &d, sizeof(d));
        }
        quick_exit(0);
    }
    else if (pid < 0)
    {   close(gc_pipes[0]);
        close(gc_pipes[1]);
        gc_pipes[0] = gc_pipes[1] = 0;
    }
}

static size_t nSymbolsAfter = 0;
static LispObject* vecOfSymbolsAfter = nullptr;
static uint64_t*   sigOfSymbolsAfter = nullptr;

void gc_end(bool final)
{
    if (final) cout << "\n@@@ about to check at end of garbage collection\n";
    else cout << "\n@@@ about to check just before GC hook\n";
    memset(checksumCacheKey, 0, sizeof(checksumCacheKey));
    memset(checksumCacheDepth, 0xff, sizeof(checksumCacheDepth));
    memset(checksumCache, 0, sizeof(checksumCache));
    for (size_t i=0; i<list_bases_size; i++)
    {   if (checksum_bases[i] != gc_checksum(*list_bases[i]))
        {   std::cout << "@@@@ " << list_names[i]
                      << " " << checksum_bases[i]
                      << " " << gc_checksum(*list_bases[i])
                      << "\n";
        }
    }
    if (nStack != 0)
    {   if (nStack != static_cast<size_t>(
                stack - reinterpret_cast<LispObject*>(stackBase)))
            cout << "@@@@ stack size changed\n";
        std::cout <<"@@@ reviewing " << nStack << " stack locations\n";
        for (size_t i=0; i<nStack; i++)
            if (sigOfStack[i] != gc_checksum(reinterpret_cast<LispObject*>(stackBase)[i+1]))
                cout << "@@@@ stack item " << i << " changed at "
                        << &(reinterpret_cast<LispObject*>(stackBase)[i+1]) << "\n";
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
                    sigOfSymbolsAfter[i++] = gc_checksum(w);
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
        {   std::cout << "@@@@ Symbol " << i << " bad at "
                      << vecOfSymbolsAfter[i] << "\n";
            LispObject name = qpname(vecOfSymbolsAfter[i]);
            if (is_vector(name))
            {   size_t len =
                    length_of_byteheader(vechdr(name)) - sizeof(LispObject);
                string sname =
                    string(sizeof(LispObject)+(char *)name-TAG_VECTOR, len);
                std::cout << "@@@@ Name is: " << sname << "\n";
            }
        }
    }
    if (final && nSymbols!=0)
    {   delete [] vecOfSymbols;
        delete [] sigOfSymbols;
        nSymbols=0;
    }
    if (final && nStack!=0)
    {   delete [] sigOfStack;
        nStack=0;
    }
    if (nSymbolsAfter!=0)
    {   delete [] vecOfSymbolsAfter;
        delete [] sigOfSymbolsAfter;
        nSymbolsAfter=0;
    }
    if (final)
    {   cout << "\n@@@ End of garbage collection\n";
        close(gc_pipes[0]);
        close(gc_pipes[1]);
    }
    else cout << "\n@@@ Just before GC hook\n";
}

#else // GC_CHECK

int gc_pipes[2];

void gc_start()
{
}

void gc_end(bool final)
{
}

#endif // GC_CHECK


// end of gc-check.cpp
