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

#if true // New idea...

#include <unordered_set>
#include <vector>

std::unordered_set<LispObject> visited;
std::vector<LispObject> objects;
std::vector<uint64_t> checksums;

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

// This function is just used for checking to depth 4.

static uint64_t local_checksum(LispObject a, size_t depth)
{   if (depth==0) return 100+(a & TAG_BITS);
    if (is_cons(a)) return CC (local_checksum(car(a), depth-1),
                              local_checksum(cdr(a), depth-1));
    if (is_symbol(a))
    {   uint64_t r = 1234567;
        r = CC(local_checksum(qvalue(a), depth-1), r);
        r = CC(local_checksum(qenv(a), depth-1), r);
        r = CC(local_checksum(qplist(a), depth-1), r);
        r = CC(local_checksum(qfastgets(a), depth-1), r);
        r = CC(local_checksum(qpname(a), depth-1), r);
        return r;
    }
    if (is_simple_string(a))
    {   size_t len = length_of_byteheader(vechdr(a)) - sizeof(LispObject);
        uint64_t h = 1;
        for (size_t i=0; i<len; i++) h = CC(h, basic_ucelt(a, i)  & 0xff);
        return h;
    }
    if (a == lisp_package) return 11111111;
    if (is_vector(a) && !vector_header_of_binary(vechdr(a)))
    {   size_t len = length_of_header(vechdr(a))/sizeof(LispObject)-1;
        if (is_mixed_header(vechdr(a))) len = 3;
        uint64_t h = 1;
        for (size_t i=0; i<len; i++)
            h = CC(h, local_checksum(basic_elt(a, i), depth-1));
        return h;
    }
    if (is_fixnum(a)) return a;
// I have not handled BIGNUMS or rational/complex numbers or floats here yet.
    return 101+(a&TAG_BITS);
}         

void findChecksum(LispObject p)
{   if (visited.count(p) != 0) return;
    visited.insert(p);
    objects.push_back(p);
    checksums.push_back(local_checksum(p, 4));
}

void scanEverything()
{
    visited.clear();
    objects.clear();
    checksums.clear();
    for (LispObject* v:list_bases)
        findChecksum(*v);
    for (LispObject* s=reinterpret_cast<LispObject*>(stackBase); s<=stack; s++)
        findChecksum(*s);
}

#endif // true

std::ofstream dest;

static constexpr size_t list_bases_size =
    sizeof(list_bases)/sizeof(LispObject);

static LispObject save_bases[list_bases_size];
static uint64_t checksum_bases[list_bases_size];

// Using a depth limit here is simpler than trying to detect loops but
// means that data nested deeply within lists may not be checked.
// I will use a form of cacheing to reduce the waste of repeating
// checksum calculation.

static const size_t cacheSize = 50*1000000;

static size_t checksumCacheDepth[cacheSize];
static LispObject checksumCacheKey[cacheSize];
static uint64_t checksumCache[cacheSize] = {0};

static uint64_t gc_checksub(LispObject a, size_t depth);

// If I use a high value of depth then each check becomes really time
// consuming. If I use one that is too low I may miss corruption in
// remote parts of the heap. A problem associated with this is the case
// of a cyclic structure with two or more entrypoints. If I wanted to
// have a concept of "infinite depth recursion" here then what hash
// values should I return when this cycle is entered from each entrypoint,
// and how should those values be related? Hmmm that almost sounds like
// an interesting question!

static uint64_t gc_checksum(LispObject a, size_t depth=10)
{
// I will treat all small positive integers as if they were the same! This
// is because crack sets up a gc hook that increments a variable my_gc_counter
// so the value of that variable will change before the end of GC and I
// do not want that reported as failure. Here I allow for up to 1000
// garbage collections and if I survive that one (a) I am rather happy and
// (b) the testing has just had to run overnight!
    if (is_fixnum(a) &&
        int_of_fixnum(a)>=0 &&
        int_of_fixnum(a)<1000) return 9999;
    size_t ha = (6364136223846793005U*a + 314159*depth) % cacheSize;
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
// current_package has a value that is a vector containing references to
// (almost) all symbols. Since I will detect and scan them otherwise I do
// not want to do that here.
    if (a == current_package) return
       CC(gc_checksum(qvalue(a), 1),
          CC(gc_checksum(qenv(a), depth-1),
             CC(gc_checksum(qplist(a), depth-1),
                CC(gc_checksum(qfastgets(a), depth-1),
                   gc_checksum(qpname(a), depth-1)))));
    if (is_symbol(a))
    {   uint64_t r = 1234567;
        r = CC(gc_checksum(qvalue(a), depth-1), r);
        r = CC(gc_checksum(qenv(a), depth-1), r);
        r = CC(gc_checksum(qplist(a), depth-1), r);
        r = CC(gc_checksum(qfastgets(a), depth-1), r);
        r = CC(gc_checksum(qpname(a), depth-1), r);
        return r;
    }
    if (is_simple_string(a))
    {   size_t len = length_of_byteheader(vechdr(a)) - sizeof(LispObject);
        uint64_t h = 1;
        for (size_t i=0; i<len; i++) h = CC(h, basic_ucelt(a, i)  & 0xff);
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

#define WIN32 1

#ifndef WIN32
// Native Windows does not support fork() so this part of the checking
// infrastructure can not be used there.

int gc_pipes_to[2] = {0,0};
int gc_pipes_from[2] = {0,0};
static constexpr int read_end = 0; 
static constexpr int write_end = 1; 

void take_snapshot()
{
// I am going to suppose that I only ever take a single snapshot (at a time)
// and that if several will be used over the course of a run that the earlier
// ones will have been tidily disposed of before that next it started. So here
// I create two new pipes. If the attempt to create them fails I will set things
// up so that other snapshot-related activity just does not do anything
// interesting.
    if (pipe(gc_pipes_to) == -1 ||
        pipe(gc_pipes_from) == -1)
        gc_pipes_from[0] = gc_pipes_from[1] =
        gc_pipes_to[0] = gc_pipes_to[1] = 0;
// fork() is the key step here. The child process will then act as a server
// able to return memory data based on an image from now (ie when the fork
// is executed).
    pid_t pid = fork();
    if (pid == 0)
    {
// Here is the child process.
// If the pipes had not been set up it should just exit instantly because
// there is nothing it can do.
        if (gc_pipes_from[write_end] == 0 ||
            gc_pipes_to[read_end] == 0) quick_exit(1);
// If it is OK it can close the pipe-ends that are not relevant to it.
        close(gc_pipes_from[read_end]);
        close(gc_pipes_to[write_end]);
// Now a loop providing service...
        for (;;)
        {   void* addr;
// Wait for a request from the parent process. This is an address to inspect
// in the saved image. If a nullprt is passed or if the pipe read fails
// then exit.
            if (read(gc_pipes_to[read_end], &addr, sizeof(addr)) != sizeof(addr) ||
                addr == nullptr) break;
// Here I read the data byte by byte. The data returned will always be 64-bits
// but if an 8, 16 or 32-bit value is what is needed the relevant data will
// be returned in the low bits of the result. One can nervously look over
// a shoulder re strict aliasing and in case 7-bytes beyond a byte-address
// that is passed might be an illegal address, but since this is a debugging
// aid I am going to relax a bit.
            char* p = reinterpret_cast<char*>(addr);
            uint64_t d = 0;
            for (int i=0; i<8; i++)
                d = d<<8 | (p[7-i] & 0xff);
            write(gc_pipes_from[write_end], &d, sizeof(d));
        }
        close(gc_pipes_from[write_end]);
        close(gc_pipes_to[read_end]);
// When there is no more to do I use quick_exit because by doing that I
// do not need to worry about tidying up anything, and I really would hate
// it if some destructor in the child process performed file operations in
// the name of clean termination and messed things up for the parent.
        quick_exit(0);
    }
    else if (pid < 0)
    {
// This is the case if fork() fails - I close pipes and set things so
// that attempts to use them become boring.
        close(gc_pipes_from[read_end]);
        close(gc_pipes_from[write_end]);
        close(gc_pipes_to[read_end]);
        close(gc_pipes_to[write_end]);
        gc_pipes_from[0] = gc_pipes_from[1] =
            gc_pipes_to[0] = gc_pipes_to[1] = 0;
    }
// Here is where the parent process has successfully forked, so it closes
// the pipe-ends that it will not be using. And then it can use oldMem()
// to retrieve data from the saved state.
    close(gc_pipes_from[write_end]);
    close(gc_pipes_to[read_end]);
// From here onward until I close down the pipes one can use oldMem() to
// inspect the state of memory from the time that the fork() was performed.
}

// oldMem() reads 64-bits from a snapshot of memory set up by take_snapshot().
// The address does not need to be aligned, so to read a byte one can use
//    static_cast<char>(oldMem(addr))
// and similarly for other data narrower than 64-bits. Pass nullptr as an
// address to discard the snapshot.
//
// On any sort of failure to retrieve proper data this returns zero with
// no special warning. I could have made it throw an exception but view that
// as more heavyweight than my needs call for.

uint64_t oldMem(void* addr)
{   if (gc_pipes_to[write_end] == 0 ||
        gc_pipes_from[read_end] == 0) return 0; // service not available.
    if (write(gc_pipes_to[write_end], &addr, sizeof(addr)) != sizeof(addr))
        return 0;
    uint64_t data;
    if (read(gc_pipes_from[read_end], &data, sizeof(data)) != sizeof(data))
        return 0;
    return data;
}

#else

uint64_t oldMem(void* addr)
{   return 0;
}

#endif // WIN32

LispObject badaccess(const char* s, LispObject u)
{
    dest << "\n!!! Bad access as if " << s << " to item with tag "
         << (u & XTAG_BITS) << " = "
         << tagName(u) << std::endl;
    quick_exit(99);
    return fixnum_of_int(999);
}

LispObject zvalue(LispObject u)
{   if (!is_symbol(u)) return badaccess("symbol value", u);
    else return qvalue(u);
}

LispObject zenv(LispObject u)
{   if (!is_symbol(u)) return badaccess("symbol env", u);
    else return qenv(u);
}

LispObject zfastgets(LispObject u)
{   if (!is_symbol(u)) return badaccess("symbol fastgets", u);
    else return qfastgets(u);
}

LispObject zcar(LispObject u)
{   if (!is_cons(u)) return badaccess("car", u);
    else return car(u);
}

LispObject zcdr(LispObject u)
{   if (!is_cons(u)) return badaccess("cdr", u);
    else return cdr(u);
}

LispObject zelt(LispObject u, int n)
{   if (!is_vector(u)) return badaccess("elt", u);
    else return basic_elt(u, n);
}

size_t zlength(LispObject u)
{   int n=0;
    while (is_cons(u))
    {   n++;
        u = cdr(u);
    }
    if (u == nil) return n;
    else return n+1;
}

LispObject znth(LispObject u, size_t n)
{   if (!is_cons(u)) return u;
    else if (n==1) return car(u);
    else return znth(cdr(u), n-1); 
}

void showparts(LispObject u, size_t depth=10)
{   dest << depth << " " << "u = " << std::hex << std::setw(16) << u << std::dec << std::endl;
    simple_print_extras =  false;
    dest << depth << " " << "inspecting: " << std::hex << std::setw(16) << gc_checksum(u, depth) << std::dec << " ";
    simple_print(dest, u);
    if (is_cons(u))
    {   size_t len = zlength(u);
        for (size_t i=1; i<=len; i++)
        {   dest << depth << " " << "  checkList[" << i << "]: "
                 << std::hex << std::setw(16) << gc_checksum(znth(u, i), depth) << std::dec << " ";
            simple_print(dest, znth(u, i));
        }
    }
    else if (is_symbol(u))
    {   dest << depth << " " << "  checksum value: " << std::hex << std::setw(16) << gc_checksum(qvalue(u), depth) << std::dec << " ";
        simple_print(dest, qvalue(u));
        dest << depth << " " << "  checksum env: " << std::hex << std::setw(16) << gc_checksum(qenv(u), depth) << std::dec << " ";
        simple_print(dest, qenv(u));
        dest << depth << " " << "  checksum plist: " << std::hex << std::setw(16) << gc_checksum(qplist(u), depth) << std::dec << " ";
        simple_print(dest, qplist(u));
        dest << depth << " " << "  checksum fastgets: " << std::hex << std::setw(16) << gc_checksum(qfastgets(u), depth) << std::dec << " ";
        simple_print(dest, qfastgets(u));
        dest << depth << " " << "  checksum pname: " << std::hex << std::setw(16) << gc_checksum(qpname(u), depth) << std::dec << " ";
        simple_print(dest, qpname(u));
    }
    else if (is_vector(u) && !vector_header_of_binary(vechdr(u)))
    {   size_t len = length_of_header(vechdr(u))/sizeof(LispObject)-1;
        if (is_mixed_header(vechdr(u))) len = 3;
        for (size_t i=0; i<len; i++)
        {   dest << depth << " " << "  checksum[" << i << "]: "
                 << std::hex << std::setw(16) << gc_checksum(basic_elt(u, i), depth) << std::dec << " ";
            simple_print(dest, basic_elt(u, i));
        }
    }
    else dest << depth << " " << "some not cons, symbol or list\n";
    dest << " " << "^^^^^^^^Item has tag " << (u & 0x7) << " " << tagName(u) << "\n\n";
}


void both()
{
// This is a sample of the sort of code that can be used if some particular
// list base refers to something that has changes when the checksumming depth
// is set to some given limit. Here it has the list-base compiler_symbol
// and initial depth 25... The material that follows gets added in
// incrementally.
    return;

// SAMPLE CODE LEFT HERE AS A MODEL

    LispObject w;
    size_t depth=25;
    w = compiler_symbol;
//    showparts(w, depth);
    depth--;
    w = zenv(w);
//    showparts(w, depth);
    depth--;
    w = zcdr(w);
//    showparts(w, depth);
    depth--;
    w = zcar(w);
//    showparts(w, depth);
    depth--;
    w = zcar(w);
//    showparts(w, depth);
    depth--;
    w = zenv(w);
//    showparts(w, depth);
    depth--;
    w = zcdr(w);
//    showparts(w, depth);
    depth--;
    w = zelt(w, 2);  // item 0 goes back to just where we started!
//    showparts(w, depth);
    depth--;
    w = zenv(w);
//    showsparts(w, depth);
    depth--;
    w = zcdr(w);
    showparts(w, depth);
    depth--;
    w = zelt(w, 1);
    showparts(w, depth);
    depth--;
    w = zvalue(w);
    showparts(w, depth);
    depth--;
    w = zcar(w);
    showparts(w, depth);
    depth--;
    w = zenv(w);
    showparts(w, depth);
    depth--;
    w = zcdr(w);
    showparts(w, depth);
    depth--;
    w = zelt(w, 149);
    showparts(w, depth);
    depth--;
    w = zfastgets(w);
    showparts(w, depth);
    depth--;
    w = zelt(w, 45);
    showparts(w, depth);
    depth--;
    w = zenv(w);
    showparts(w, depth);
    depth--;
    w = zcdr(w);
    showparts(w, depth);
    dest << "Point A\n";
    depth--;
    w = zelt(w, 28);
    showparts(w, depth);
    dest << "Point B\n";
    depth--;
    w = zenv(w);
    showparts(w, depth);
    dest << "Point C\n";
    depth--;
    w = zcdr(w);
    showparts(w, depth);
    dest << "Point D\n";
    depth--;
    w = zelt(w, 26);
    showparts(w, depth);
    dest << "Point e\n";

}

#include <sys/wait.h>

void gc_start()
{   dest.open("gc_start.log");
    dest << "\n@@@ Start of garbage collection\n";
    memset(checksumCacheKey, 0, sizeof(checksumCacheKey));
    memset(checksumCacheDepth, 0xff, sizeof(checksumCacheDepth));
    memset(checksumCache, 0, sizeof(checksumCache));
    both();
// I am going to take checksums of all sorts of list date that I can
// find starting from list bases. The idea is that I can then take
// checksums after the GC and see what might have changed.
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
    dest.close();
#ifndef WIN32
    take_snapshot();
#endif // WIN32
}

static size_t nSymbolsAfter = 0;
static LispObject* vecOfSymbolsAfter = nullptr;
static uint64_t*   sigOfSymbolsAfter = nullptr;

void gc_end(bool final)
{   dest.open("gc_end.log");
    if (final) dest << "\n@@@ about to check at end of garbage collection\n";
    else dest << "\n@@@ about to check just before GC hook\n";
    memset(checksumCacheKey, 0, sizeof(checksumCacheKey));
    memset(checksumCacheDepth, 0xff, sizeof(checksumCacheDepth));
    memset(checksumCache, 0, sizeof(checksumCache));
    both();
    for (size_t i=0; i<list_bases_size; i++)
    {   if (checksum_bases[i] != gc_checksum(*list_bases[i]))
        {   dest << "@@@@ " << list_names[i]
                 << " " << checksum_bases[i]
                 << " " << gc_checksum(*list_bases[i])
                 << std::endl;
            char buffer[80];
            simple_string(buffer, 72, *list_bases[i]);
            dest << "new: " << (char *)&buffer << std::endl;
            simple_old_string(buffer, 72, oldMem(list_bases[i]));
            dest << "old: " << (char *)&buffer << std::endl;
#ifndef WIN32
            void* addr = nullptr;
            if (gc_pipes_to[write_end] != 0 &&
                gc_pipes_from[read_end] != 0)
                write(gc_pipes_to[write_end], &addr, sizeof(addr));
            close(gc_pipes_from[read_end]);
            close(gc_pipes_to[write_end]);
            wait(nullptr);
#endif // WIN32
            std::quick_exit(999);
        }
    }
    if (nStack != 0)
    {   if (nStack != static_cast<size_t>(
                stack - reinterpret_cast<LispObject*>(stackBase)))
            dest << "@@@@ stack size changed\n";
        dest <<"@@@ reviewing " << nStack << " stack locations\n";
        for (size_t i=0; i<nStack; i++)
            if (sigOfStack[i] != gc_checksum(reinterpret_cast<LispObject*>(stackBase)[i+1]))
            {   dest << "@@@@ stack item " << i << " changed at "
                        << &(reinterpret_cast<LispObject*>(stackBase)[i+1]) << std::endl;
                char buffer[80];
                simple_string(buffer, 72,
                    reinterpret_cast<LispObject*>(stackBase)[i+1]);
                dest << "new: " << (char *)&buffer << std::endl;
                simple_old_string(buffer, 72,
                    oldMem(reinterpret_cast<LispObject*>(stackBase)+i+1));
                dest << "old: " << (char *)&buffer << std::endl;
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
                    sigOfSymbolsAfter[i++] = gc_checksum(w);
                }
            }
        }
    }
    if (nSymbols != nSymbolsAfter)
    {   dest << "symbol count has changed from"
             << nSymbols << " to " << nSymbolsAfter << std::endl;
        my_abort();
    }
    dest << "@@@ reviewing " << nSymbols << " symbols\n";
    for (size_t i=0; i<nSymbols; i++)
    {   if (sigOfSymbols[i]!=sigOfSymbolsAfter[i])
        {   dest << "@@@@ Symbol " << i << " bad at "
                      << vecOfSymbolsAfter[i] << std::endl;
            LispObject name = qpname(vecOfSymbolsAfter[i]);
            if (is_vector(name))
            {   size_t len =
                    length_of_byteheader(vechdr(name)) - sizeof(LispObject);
                string sname =
                    string(sizeof(LispObject)+(char *)name-TAG_VECTOR, len);
                dest << "@@@@ Name is: " << sname << std::endl;
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
    {   dest << "\n@@@ End of garbage collection\n";
#ifndef WIN32
        void* addr = nullptr;
        if (gc_pipes_to[write_end] != 0 &&
            gc_pipes_from[read_end] != 0)
            write(gc_pipes_to[write_end], &addr, sizeof(addr));
        close(gc_pipes_from[read_end]);
        close(gc_pipes_to[write_end]);
        gc_pipes_from[0] = gc_pipes_from[1] =
            gc_pipes_to[0] = gc_pipes_to[1] = 0;
        wait(nullptr);
#endif // WIN32
    }
    else dest << "\n@@@ Just before GC hook\n";
    dest.close();
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
