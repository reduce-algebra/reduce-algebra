// newallocate.cpp                         Copyright (C) 1989-2019 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//


// Development game-plan for this stuff - showing the steps or stages
// to go through:
// (1) Work towards being able to allocate vectors and lists and
//     set up an initial large chunk of memory. Hope that the code in
//     restart.cpp for a cost start can be got working again.
// (2) Test a bit of execution that can happen eithout garbage collection.
//     I rather hope that PRESERVE will then "just work", and that will
//     let me build a csl.img
// (3) Arrange that every garbage collection will be a major one and
//     re-work the allocation and re-allocation of memory blocks for that.
//     By keeping the code with precise list-bases for everything that
//     matters the ambiguous pointers should never be the only reason
//     for saving any data - they just pin things and hance mess up memory
//     layout. Get that version of GC working. Note that write barriers
//     may collect information but it is never used!
// (4) Make some collections minor ones, thus needing to cope with the
//     consequences of the write barrier.
// (5) Put in explicit test cases for data that is only preserved via an
//     ambiguous list-base.
// (6) Thread-synchronization for GC entry.
// (7) Thread-local support for fluid bindings, and simple code in the Lisp
//     for creating threads, even though almost everything is not thread-safe.
// (8) [in various orders] get rid of push/pop stuff if the main code in
//     favour of just letting conservative memory management cope. And
//     migrate more status to thread-local and/or protect it with critical
//     regions.
// (9) Fix ccomp.red and bytes2.cpp regarding new treatment of fluids and
//     for thread safety.
// (10)Protection of blocking calls so that GC can still happen.


// Well by the time I have got started at all on that list the issue of
// the exact sequence towards the end will become clearer! Really it is the
// first 3 that are my initial plan.


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

/*!!! csl
*/

#include "headers.h"



//
// This is a place for my latest round of thinking about a new storage
// management scheme. The ideal I set now is that garbage collection should
// be both conservative and generational and that it should be able to
// support multiple mutator threads. I am NOT intending either to run
// garbage collection concurrently with the mutator (so the GC is a "stop
// the world" one, although most garbage collections should be "minor" ones
// and hence not too disruptive). I am also not at present planning on having
// garbage collection use more than one thread to do its work, although that
// might be seriously easier to retrofit later then having the GC and the
// mutator concurrent.

// In previous sketches relating to this I was considering using memory
// protection and thus exceptions to implement a write barrier that is needed
// to make the collector ephemeral/generational. My thoughts are now moving
// to accepting that having the operating system handle exceptions is liable
// to be unpleasantly expensive and that a software scheme can in fact have
// almost modest overhead.

// The design here has to mingle plans for global storage allocation,
// the CONS operation as well as operations involving Lisp atoms, the
// way that Lisp threads can access the values of variables, synchronization
// matters and so on. In general it seems that almost all aspects from the
// lowest to the most global level interact. So some of what I have here
// are my CURRENT notes on how I think I will make it all work. The code
// in this file is at present generall the OLD code and much of it will be
// thrown away and replaced!


#if 0

#include <cinttypes>  // automatically include <cstdint>
#include <atomic>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <cassert>



// The pointer-tagging scheme used here is exactly as in CSL so that
// transfer of code ideas will be especially easy.

constexpr unsigned int TAG_BITS      = 7;
constexpr unsigned int TAG_CONS      = 0;
constexpr unsigned int TAG_VECTOR    = 1;
constexpr unsigned int TAG_HDR_IMMED = 2;
constexpr unsigned int TAG_FORWARD   = 3;
constexpr unsigned int TAG_SYMBOL    = 4;
constexpr unsigned int TAG_NUMBERS   = 5;
constexpr unsigned int TAG_BOXFLOAT  = 6;
constexpr unsigned int TAG_FIXNUM    = 7;


typedef intptr_t LispObject;


// Strategy:
//
// The plan is to support mutator threads but garbage collection will run
// in just one thread and will be a "stop the world" activity. Furthermore
// the intent is to have a (mostly-) copying collector so that live data is
// collected intop a compact region and free-space comes in contiguous blocks.
//
// At any moment the memory will be considered partitioned into these
// regions:
// (1) Nursery: the region within which allocations are being made. All
//     data in the nursery is treated as live during a minor GC.
// (2) Pending: After a while material graduates from the nursery to this
//     region. It is still treated as live during a minor GC, but the
//     purpose of this state is to allow data to mature, so that although
//     some material may be re-classified from Nursery to Pending while it
//     is still very young anything that graduates out from Pending must
//     have some age.
// (3) Scavangable: When memory moved out of Pending it becomes Scavengable,
//     and a minor GC will then scan it and evacuate live data into the
//     Stable region. A minor GC will use Nursery and Pending as roots
//     and must also mark from global list-bases, ambiguous locations on the
//     stack and places in the Stable region where a write-barrier has
//     recorded a change. Well while any memory is classified as Scavangable
//     a garbage collection process will run to migrate data into the Stable
//     region, and when that is complete the Scavangable region becomes part
//     of Free!
//     Note that if Garbage Collection was concurrent with other processing
//     then there would be an active Scavengable region while programs were
//     running. CAR and CDR (etc) might need to be equiped with read barriers
//     so that they accessed the correct copy of data, and EQ would probably
//     have to check if either of its arguments were references into the
//     Scavengable region and if so if the item concerned had been relocated.
//     The issue of CAR/CDR might be addressed by leaving the region untouched
//     until the end of a scavanging scan, but in that case some scheme other
//     that in-place forwarding addresses would be needed to track which
//     items had been evecuated and where they ended up. But avoiding serious
//     overhead in EQ tests at present looks intractable to me. I will not be
//     developing fully concurrent collection! Thus this region has a purely
//     transient existence!
// (4) Stable: Minor GCs will assume that all data here will have remained
//     alive, and will not relocate any of it. A Major GC just treats all
//     data (Nursery, Pending and Stable) as part of Scavangable so that
//     everything is considered for reclamation.
// (5) Free: Memory currently not in use and so available for future
//     reallocation to the Nursery or Stable regions.
//
// Each of regions (1) to (4) will have a component that only holds items
// of size up to that of a CONS cell (so I could put very short strings and
// bignums there if that was going to help, but doing so would probably add
// to complication and overhead without enough compensating benefit). The
// second is for all other sizes of object. The reasoning behind having this
// partition will emerge in the discussion of pinned items.
//
// So now let's consider the key events that can arise:
//
// The Nursary becomes full: Re-badge Pending as Scavengable, re-badge
// Nursery as Pending and grab fresh space from Free to be the new Nursery.
// As a scavangable region comes into existance a sweep of evacuation is
// triggered and live data there is moved into to Stable region, and that
// may need to grab extra space from Free as it grows. When Stable has grown
// to an extent that is starting to look embarassing the system sets a tag
// so that the next garbage collection will be a full one. 
//
// Some other thread fills the Nursery: when they do fringe will be above
// limit - of if they just tried to allocated a vector vfringe will be
// above vlimit. They must then set limit as well. The current thread will
// then attempt an allocation or perform a poll() operation, and it then
// enters the garbage collector. When a thread is going to perform an
// operation that can block it must first set flags that indicate that it will
// be quiescent, and so other threads garbage collecting will be safe. As it
// becomes ready to proceed it must poll to ensure that nobody else has
// initiated garbage collection.
//
// I will now try to document the evacuation process from the Scavengable
// region - and this will have a range of sub-tasks several of which I will
// just assume to start with and come back to the details of later.
//
// I take all ambiguous pointers. Those that are pointing anywhere into the
// heap are candidate genuine pointers - I tag the items pointed to that are
// in the Scavangable region as "pinned".
//
// I need to unpack the above. Firstly some people would tend to pin chunks
// of memory (perhaps referred to as "cards") rather than just single items.
// There may be some performance balances to be struck there. There are at
// least two potential areas for "ambiguous pointers" too, also with issues
// of balancing one performance issue agsinst another. So I will decribe two
// extreme strategies here to show what I need to decide between:
// (a) The only ambigious pointers are the values on the stack of each
//     thread. All other pointers that will be considered during garbage
//     collection will be precise. But an ambiguous pointer may point within
//     an object not to its head. To pin that object the location of the
//     object head must be deduced from the crude address that one starts from
//     an a bit in a bitmap set to tag it as pinned. Because during a full
//     garbage collection all of Nursery, Pending and Stable are viewed
//     as scavengable the bitmap must cover all of the heap that may be in
//     use - ie the "old" half-space.
//     All memory will lie within up to 16 big blocks that get grabbed from
//     the operating system, and about 4 comparisons make it possible to
//     identify which. Within each big block thare needs to be information
//     about memory class. For references into scavangable CONS space the
//     object starts at an address got by rounding down to a multiple of
//     sizeof(ConsCell). *UH-OH* that seemed good when I first wrote it,
//     but the cons-space may have embedded within it basically arbitrary
//     vectors that has been pinned during an earlier garbage collection
//     and that new CONSES have to allocate around. Well some scheme to
//     map those will be required so I can allocate around them, and that
//     will need to be kept so that they can be identified properly when
//     ambiguous pointers are processed. I have not thought through the
//     details yet!
//     As GC starts I will do a linear scan of scavangable memory that can
//     hold vectors setting up a bitmap that identified object starts.
//     While setting that up I can also build a table such that for any
//     address that is a multiple of (say) 4K it identifies the start of
//     the last object whose start address is no higher. This latter is
//     to make identifying the start of large objects cheaper.
//     Now given an ambiguous pointer known to be in a vector region start
//     with its address to resolution 1K and the address of an object that
//     that identifies. Starting from there check the bitmap to find the
//     last object start that is at or before the given address.
//     How much space does this all use? Well the bitmap can use one bit for
//     every 8 bytes, i.e. (1/64) of the heap size. The table of pointers
//     will use an 8-byte pointer for every 1K chunk, ie (1/128) of the
//     space. The table identifies a valid object that is within 1K of the
//     item, and that is 128 8-byte units. So using 64 bit integers in the
//     bitmap, searching for it involved looking at just 2 words.
//     All this is mildly messy but tolerably fast!
// (b) An alternative suggestion pins not merely single objects but chunks
//     of memory that contain those objects and a range of other objects that
//     happen to be their neighbours. A key motivation for this is to replace
//     the detailed bitmap in (a) with a coarser grain record of pinned
//     regions. This could be a particular saving if many ambiguous pointers
//     tended to be to objects that were fairly close to each other in memory.
//     It could also seen attractive if the total number of pinned items was
//     kept small: perhaps a hash table could record pinning rather than a
//     bitmap, and during a major GC this might save significant memory.
//     The biggest issue I see here arises if I want a pointer anyhere within
//     an object to be able to pin that object, and the key argument for that
//     is low level code with a pointer traversing a vector. Even if source
//     for was written as "for (i=0; i<len; i++) { ... a[i] ... }" one can
//     imagine a compiler mapping that onto code that sets up a pointer into
//     the array a[] and steps it along sequantially, rather as if it had
//     been "for (p=&a[0]; p<&a[len]; p++) { ... *p ... }". To avoid trouble
//     with that it is vital that the pointer p (stored on the stack) is
//     identified as something that must pin a[]. The hard part of that is
//     that a[] may be a large vector, and to identify a chunk of memory
//     containing it either one needs to pin a blick that is larger than the
//     largest legal vector or to identify the start of a[] precisely, and
//     the table/bitmap scheme shown in (a) is about as good as I can imagine
//     for that. And having done that recording the single precise item that
//     is pinned seems sensible!
// (c) In a different direction there is an issue of what values are to be
//     treated as ambigious pointers. In a minor GC I need to mark from
//     all of the Nursery, all the Pending region and from locations
//     in Stable that have been written to (and that contain "up-pointers").
//     As in (b) above I might identify these dirty parts of the Stable area
//     either precisely by the exact cell that was updated, or in a block.
//     If I identify dirty cells precisely then they will hold unambiguous
//     values, and though I must mark from them there is no special trouble.
//     However in an implemention of a write barrier keeping exact information
//     will be hard (I will explain a proposed mechanism in a while) and it
//     will probably be more feasible to tag segments of memory as having been
//     written to. The alignment between these regions and the starts and ends
//     of binary and list-containing vectors may not be tidy. So it seems
//     simplest to treat all the contents of a dirty region as ambiguous
//     pointers.
//
// To back up (c) I need to consider the need for an implemention of write
// barriers. For a conservative GC any time a part of the Stable heap is
// changed this information must be known to the GC so that if the update
// leads to the stable region containing a reference to something in the
// Scavangable area it gets brought up to date as scavenging happend. Well
// ons case is simple - when a major GC happens none of the heap is considered
// Stable and everything is Scavengable so this issue does not arise.
// But ahead of a minor GC the mutator must arrange that when any update
// to the Stable heap is made the GC will be able to track it. The cases
// that arise seem to be:
// (1) The value cells associated with symbols;
// (2) Property list cells associated with symbols;
// (3) Property-vectors associated with Symbols;
// (4) function definitions and associated data (the "env" call of symbols)
// (5) print-names if there are operations that can reset a print-name to
//     refer to newly allocated memory.
// To cope with all of these I think that all symbols will be collected on
// a chain of weak pointers (weak so that in the case that the symbol ceases
// to be needed it can be discarded). The main cells in every symbol will
// always be scanned from in even minor GCs. For reference I note that in
// REDUCE with everything loaded thera are around 44K symbols present, of
// which under 9K are present when basic algebra is being performed.
// (6) Vector and hash-table updates;
// I expect that multiple updates to the same object will generally cluster,
// so for these having a record of the "most recently updated object" and
// only storing an update to something that differs may be a good
// optimization. Parhaps any code that uses vector will be complicated enough
// that adding a bit of overhead to vector writes will not hurt a lot?
// (7) RPLACA and RPLACD (and RPLACW); Perhaps these are not used TOO much so
// adding cost will not hurt.
// (8) NREVERSE; A particular use of RPLAC operations is when a list is
// created using CONS and then at the end of that it is reversed in place.
// That idiom arises in transformed versions of what would otherwise be
// recursive list-building operations. If it can be established that ALL the
// new CONS cells are still in the Nursery then no write barrier activity
// would be needed at all. I think that is probably not a helpful direction
// to look for optimization.
//
// [Note that all items in a cons segment of the heap will be a reliable
// pointer not an ambiguous one. It will just be items in the vector region
// that can cause trouble!]
//
// It could be tempting to look for a precise write barrier that tags exactly
// the cell that is updated, perhaps using a bitmap. In a multi-threaded world
// the bitmap can be updates using std::atomic::fetch_or and that then lets
// one use a bitmap that consumes (1/64) of the memory used by the Stable heap.
// If one was happy to marks (say) 256 byte blocks as dirty then either
// it would still be OK to use a bitmap, or with a little less overheap a
// map with flag of type std::atomic<unsigned char> for each block (ie (1/256)
// of the memory capacity) could be used.
// When the write barrier is used the address involved is known to be a valid
// Lisp address, and it is know whether it is a CONS or a vector. So for the
// CONS case I will propose that cons cells are always allocated within
// blocks of memory that are say 1 Mbyte large and that always have a 16 Kbyte
// chunk at their start for use as a "dirty" bitmap and a second 16K as a
// pinned bitmap. Then we can have something like:


// First a version that uses a bitmap and gives precise info about the
// updated pair of cells. I have these two versions so I can compile
// thos cide into assembly code and check how the two versions compare
// at that level.

LispObject rplaca1(LispObject a, LispObject b)
{   uintptr_t aa = static_cast<uintptr_t>(a);
    uintptr_t base = aa & ~UINT64_C(0xfffff); // round down to 1M boundary
    std::atomic<uint64_t> *bitmap =
        reinterpret_cast<std::atomic<uint64_t> *>(base);
    size_t offset = (aa - base)/(2*sizeof(LispObject));
    bitmap[offset/64] |= UINT64_C(1) << (offset%64);
    (reinterpret_cast<LispObject *>(a))[0] = b;
    return a;
}

// Now a version that uses a byte-map and coarser granularity records.

LispObject rplaca2(LispObject a, LispObject b)
{   uintptr_t aa = static_cast<uintptr_t>(a);
    uintptr_t base = aa & ~UINT64_C(0xfffff); // round down to 1M boundary
    std::atomic<uint8_t> *bitmap =
        reinterpret_cast<std::atomic<uint8_t> *>(base);
// I want to record that this megabyte segmnent contains at last one
// dirty fragment.
    bitmap[0].store(1);
    size_t offset = (aa - base);
// This is a flag for every 64 bytes, ie 8 LispObjects on a 64-bit
// platform.
    bitmap[offset/64].store(1);
    (reinterpret_cast<LispObject *>(a))[0] = b;
    return a;
}

// Looking at the machine code generated for each of the above two (on
// x86_64 and using "g++ -O3" it looks to me as if the byte-map version is
// sufficiently more concise that I wish to use it, and the larger size
// of pinned regions that it introduces does not feel like a severe problem.
//
// However that part of the evaluation just looks at the cost of the write
// barrier for the mutator. The other component of cost is in the garbage
// collector where even for a minor garbage collection all dirty fragments
// of memory need to be identified. If there are N bytes of memory in use
// in all then as I have things coded above that involves checking N/64
// bytes in all. Well I have two optimizations. The first is that if a
// megabyte block of cons space is totally clean I can observe that from
// a 1-byte flag. Then when that does not apply but if I expect that only
// a small fraction of memory will be dirty I can scan 8 bytes at a time by
// fetching 64-bit words, so the number of read operations needed to scan
// all memory is more like N/512. For multi-gigabyte memory this is still
// not good. This can be (slightly) softened by using the bytemap scheme with
// a coarser granularity. Having /256 rather than /64 would reduce the bitmap
// sized by 4, and using /1024 by 16. Maybe my current GUESS will be that
// "/512" will give an acceptable balance. With a 32GB heap to cover
// that leaves each minor GC checking up to 8M words (but the actual cost
// will be a lot less because of fully clean pages) and when a region is
// tagged as dirty it will be 512 bytes = 64 words that are tagged.
//
// Of course the right things to do will be to make all the parameters
// adjustable so that behaviour can be tuned over time. 
//
// So now I can come back to garbage collection!
// After a major garbage collection set all the up-pointer maps to zero
// and clear all the pinned maps.
// During computation arrange that when any RPLACx or PUTV (or PUTHASH)
// operation is performed update the "dirty" maps.
// At the start of any garbage collection clear that pinned bits for the
// Scavengable region. Scan all C stacks and all dirty regions in the
// stable heap and mark each location that is (potentially) addressed via
// an ambiguous pointer as pinned.
//
// Now for all unambiguous roots and all field within pinned items evacuate
// data into the Free region leaving a forwarding pointer. The presence of the
// forwarding pointer identifies items that have already been processed.
//
// Scan the new material just moved into a Free region evacuating its
// contents where relevant, until everything is done.
//
// Take the block that was scavengable and identify all the pinned
// regions within it. Built a sort of free-list showing the blocks that
// are actually free and re-classify the region as Free.


#endif // 0














// The definitions here are ones that will eventually not be needed with
// the conservative model - or will be re-introduced with quite different
// implementation or impact. But they are defined here to allow me to
// build a version so that I can test it incrementally.

void **pages, **heap_pages, **vheap_pages;
size_t pagesCount, heap_pagesCount, vheap_pagesCount;
void **new_pages, **new_heap_pages, **new_vheap_pages;
size_t new_pagesCount, new_heap_pagesCount, new_vheap_pagesCount;

void *allocate_page(const char *why)
{   printf("allocate_page called\n");
    my_abort();
}


#ifdef USE_SIGALTSTACK

static unsigned char signal_stack_block[SIGSTKSZ];
stack_t signal_stack;

#endif

// All the heap memory I use here will be allocated within (up to) 32
// segments that are grabbed using either malloc or VirtualAlloc. Each
// segment of memory will start aligned at a multiple of CSL_PAGE_SIZE
// which is (at present) 8 Mbytes. The idea here is that I grab seriously
// large chunks of memory from the system and these chunks may not be
// contiguous. But with at most 32 of them I can take any bit-pattern and
// with around 5 comparisons I can identify which (if any!) of these
// chunks it points within. Then division by 8M can get me to the start of
// the 8 Mbyte segment that is involved. That bit of search will be heavily
// used when processing ambiguous pointers.
//
// I will arrange for bitmaps covering a resolution of 1 bit per 8 bytes,
// and note that this will use (1/64) times the space that is in "proper"
// use. These bitmaps will be used for recording pinned items. Another way of
// putting that is that it represents 128 Kbytes of bitmap for each 8M page.
//
// Once C++17 is always available I will be able to use std::aligned_alloc
// but until then the best way of grabbing aligned memory is liable to
// be system-dependent.


#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *t, void *v);
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo);
#endif // !HAVE_SIGACTION

void set_up_signal_handlers()
{
//
#ifdef USE_SIGALTSTACK
// If I get a SIGSEGV that is caused by a stack overflow then I am in
// a world of pain because the regular stack does not have space to run my
// exception handler. So where I can I will arrange that the exception
// handler runs in its own small stack. This may itself lead to pain,
// but perhaps less?
    signal_stack.ss_sp = (void *)signal_stack_block;
    signal_stack.ss_size = SIGSTKSZ;
    signal_stack.ss_flags = 0;
    sigaltstack(&signal_stack, (stack_t *)0);
#endif
    for (int i=0; i<32; i++)
        heapSegment[i] = reinterpret_cast<void *>(UINTPTR_MAX);
#ifdef HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_sigaction = low_level_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO; //???@@@ | SA_ONSTACK | SA_NODEFER;
// (a) restart system calls after signal (if possible),
// (b) use handler that gets more information,
// (c) use alternative stack for the handler,
// (d) leave the exception unmasked while the handler is active. This
//     will be vital if then handler "exits" using longjmp, because as
//     far as the exception system is concerned that leaves us within the
//     handler. But after the  exit is caught by setjmp I want the
//     exception to remain trapped.
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#ifdef SIGBUS
    if (sigaction(SIGBUS, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#endif
#ifdef SIGILL
    if (sigaction(SIGILL, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#endif
    if (sigaction(SIGFPE, &sa, NULL) == -1) {}
        /* I can not thing of anything useful to do if I fail here! */
#else // !HAVE_SIGACTION
#ifndef WIN32
#error All platforms other than Windows are expected to support sigaction.
#endif // !WIN32
    signal(SIGSEGV, low_level_signal_handler);
#ifdef SIGBUS
    signal(SIGBUS, low_level_signal_handler);
#endif
#ifdef SIGILL
    signal(SIGILL, low_level_signal_handler);
#endif
    signal(SIGFPE, low_level_signal_handler);
#endif // !HAVE_SIGACTION
}

// Elsewhere I worry about thread_local performance but here in the code that
// recovers after an exception I am not worried about that.

static volatile thread_local char signal_msg[32];

static volatile char *int2str(volatile char *s, int n)
{   unsigned int n1;
// Even though I really only expect this to be called with small positive
// arguments I will code it so it should support ANY integer value, including
// the most negative one.
    if (n >= 0) n1 = (unsigned int)n;
    {   *s++ = '-';
        n1 = -(unsigned int)n;
    }
    if (n1 >= 10)
    {   s = int2str(s, n1/10);
        n1 = n1 % 10;
    }
    *s++ = '0' + n1;
    return s;
}

#ifdef HAVE_SIGACTION
static void low_level_signal_handler(int signo, siginfo_t *si, void *v)
#else // !HAVE_SIGACTION
static void low_level_signal_handler(int signo)
#endif // !HAVE_SIGACTION
{
// There are really very restrictive rules about what I can do in a
// signal handler and remain safe. For a start I should only reference
// variables that are of type atomic_t (or its friends) and that are
// volatile, and there are fairly few system functions that are
// "async signal safe" and generally permitted. However I am going to
// stray well beyond the rules here! Well in most cases I will view this
// as acceptable, because in most cases these low level signals will only
// arise in case of a system-level bug, and so ANY recovery or diagnostic
// I can produce will be better than nothing, and if things get confused
// or crash again then that is not much worse than the exception having
// arisen in the first case!
    if (miscflags & HEADLINE_FLAG)
    {   switch (signo)
        {   default:
                {   volatile char *p = signal_msg; // NB thread-local memory
                    const char *m1 = "Signal (signo=";
                    while (*m1) *p++ = *m1++;
                    p = int2str(p, signo);
                    *p++ = ')';
                    *p = 0;
                }
                errorset_msg = signal_msg;
                break;
#ifdef SIGFPE
            case SIGFPE:
                errorset_msg = "Arithmetic exception";
                break;
#endif
#ifdef SIGSEGV
            case SIGSEGV:
                errorset_msg = "Memory access violation";
                break;
#endif
#ifdef SIGBUS
            case SIGBUS:
                errorset_msg = "Bus error";
                break;
#endif
#ifdef SIGILL
            case SIGILL:
                errorset_msg = "Illegal instruction";
                break;
#endif
        }
    }
// I am NOT ALLOWED TO USE THROW to exit from a signal handler in C++. I
// can at best try use of longjmp, and that is not really legal
// This has the malign consequence that destructors
// associated with stack frames passed through will not be activated. And
// I use destructors in a RAII style to tidy up bindings at times, so I
// hope I never do a really long longjmp, because that would bypass things!
    global_longjmp();
}

// Provide the kernel of the allocation code...

// This is an updated and fuller explanation of memory layout on each
// page.
// A page may either be one where allopcation is currently happening within
// it or one that is full of data, or it may be one that is currently
// free. A messy complication is that in each situation its general pattern
// of use can be disrupted by virtue of it having some data within it that
// was pinned during a previous garbage collection and so had to be left
// in place. That means my idea of having separate pages for cons cells and
// for vectors seems to fail.

// A page will have as its layout:
// (1) A smallish header that contains its fringe, arrangements so it can
//     be chained along with other pages etc. Details will emerge as I code
//     all this and discover what I need!
// (2) A region that acts as a "dirty map". This region will be present in
//     every page and is an array of atomic<uint8_t>, where each byte maps
//     a 64-byte block within the page and will get set non-zero if a RPLAC
//     or PUTV (style) operation updates anything within that small block.
//     for 8 Mbyte pages this map will be 128 Kbytes large. It only gets
//     written to when Lisp performs a valid RPLAC/PUTV and so addresses
//     such as those in the bitmap itself will never become dirty. So if
//     this map is aliased to start at the beginning of the page the first
//     2 Kbytes may be used (eg for the header) without risk.
// (3) A bitmap that can be used to tag "pinned" objects. To have one bit for
//     each 8-byte item in the heap (and every valid LispObject will be
//     positioned so as to be 8-byte aligned, whether on a 32 or 64-bit
//     platform) will require 128 Kbytes, and this will be set up as an
//     array of uint64_t values which will mean that any linear scan of it
//     only has 16 K words to check. Pinned status is established for memory
//     in the scavengable region as a first step in garbage collection. Two
//     cases arise. In Minor garbage collection pinning only happens in the
//     single page of scavengable material, and all of that will be processed
//     so issues as to whether there are up-pointers present in it do not
//     arise. Pinned bits are not set in the Stable part of the heap so
//     dirty bits there are unaffected. On the other hand during a Major
//     garbage collection all memory is Scavangable and will need pin
//     information, but dirty bits are not relevant. So provided pinned bits
//     are ONLY used or inspected during garbage collection the bitmap here
//     can overlay the dirty map.
//     If at the end of garbage collection there had been pinned items in the
//     Scavengable region and if the contents of any of those are up-pointers
//     then they must be marked as dirty when the page is put in the Free area.
// (4) A further 128 Kbyte bitmap that can mark which addresses within a page
//     are at the start of a LispObject. These get set in the Scavengable
//     region as a prelude and prerequisite for setting pinned bits. Well to
//     be more careful about that statement, when an ambiguous address is
//     inspected to use it for pinning the page it refers into will need its
//     object-start map set up. So pages that contain no pinned items at all
//     avoid this. So during a minor GC only the scavengable region gets
//     scanned to identify object starts, while during a major GC only pages
//     that are the targets of ambiguous pointers will.
//

// Here is a layout for an 8 Mbyte page, specifying the various
// ways in which data can be accessed. This uses a union so that the page
// header will overlap the beginning of the objstart[] bitmap, but because
// objects only reside in the data[] part the first couple of kilobytes
// of objstart[] will never be used.
// In my first sketch here I have not put in all the data I expect to need
// to put into the header - eg I will need more to let me allocate around
// pinned items.

static const size_t pageSize = 8*1024*1024; // Use 8 Mbyte pages
static const size_t bytesForMap = pageSize/64;
static const size_t qwordsForMap = bytesForMap/8;
static const size_t spareBytes = 2*bytesForMap;

// I make some assumptions about the variations on std::atomic<> that I
// use, but then would like to use static_assert to confirm them or to
// cause CSL to fail to compile. However the test has to be dynamic, so I can
// at best cause things to fail at system startup. Boo Hiss!
// I believe that my assumptions have a good chance of being satisfied
// on almost all machines, even though I can imagine architectures
// where there may be trouble. But what matters most to me will be x86,
// x86_64 and both 32 and 64-bit ARM when using g++ or clang, and those will
// get checked the first time I compile this code on each.
//
// Note that the C++ standard explictly says that there is no guarantee that
// the sizes of atomic specializations match those of the underlying raw
// types, but that implementations are encouraged to make that the situation
// where they can.
// Well std::atomic_flag is guaranteed lock-free and to my mind that would
// suggest it had no need for extra memory and I might hope it was thus
// of size 1, but this is not guaranteed either. So my code is not guaranteed
// portable! What an amazing situation (ha ha).

class MakeAssertions
{
public:
    MakeAssertions()
    {   if (sizeof(std::atomic<uint8_t>) != 1)
        {   std::cout << "Atomics bytes are too large" << std::endl;
            std::abort();
        }
        if (!std::atomic<uint8_t>().is_lock_free())
        {   std::cout << "Atomic<uint8_t> not lock-free" << std::endl;
            std::abort();
        }
        if (!std::atomic<uintptr_t>().is_lock_free())
        {   std::cout << "Atomic<uintptr_t> not lock-free" << std::endl;
            std::abort();
        }
    }
};

static MakeAssertions test_for_lockfree;

// I am going to require Pages to be aligned at nice neat boundaries
// because then if I have an arbitrary address within one I will be able to
// find the page header using a simple AND operation.

union alignas(pageSize) Page
{   struct PageHeader
    {
// Pages can be chained through this field, so e.g. there will be a
// chain of all the pages that are not currently full but that (may)
// have pinned live data within them.
        union Page *chain;
// When a page is the Nursery or the I keep fringe and limit pointers
// showing how the next allocation must happen. There will be further
// variables related to mapping pinned items within the page where it
// is necessary to allocate around them. When a page ceases being the
// Nursery it may still have some free space at its end (for instance
// when it overflowed due to an attempt to allocate a vector). So the
// fringe and limit values are saved in it so that if an ambiguous
// pointer refers into the page but indicates an address beyond the fringe
// it can be ignored.
        uintptr_t fringe;
// To follow on from the above, when a page has been evacuated by the
// garbage collector fresh values of fringe and limit can be set into it.
// When the page is selected as a new Nursery these values can be transferred
// into the global locations.
// Neither of these fields is used other than during garbage collection and
// so neither needs a std::atomic<> wrapping.
        uintptr_t limit;
// I use a software write-barrier that sets bytes in the dirty[] array
// when something is referenced. There are then times when I need to
// process every dirty region. Well I hope that many pages will not have any
// dirty segments, and in that case processing the entire page reduces to
// checking this simple flag. Otherwise I need to scan the entire dirty[]
// array.
        std::atomic<bool> dirtypage;
// During garbage collection I need a map showing where each object on a
// page starts. This boolean is set when that map is set up and available
// for use. Because the map shares space with the "dirty[]" map it will
// be invalidated whenever the mutator runs, and so the information will
// have to be regenerated at the start of each garbage collection.
        bool onstarts_present;
    } pageHeader;
// Here I need to explain the bit and byte-maps I use and when I use them,
// and in particular how uses could conflict.
// To cope with the generational nature of the GC I have a software
// write barrier such that every use of RPLACx or PUTV sets a byte in
// the addressed page. This byte specifies a small block of words within which
// the update occured. The RPLACx etc operations are always precise - ie they
// will update a valid live Lisp object, and so I do not need to validate
// the address concerned. But this means that any time the mutator is active
// entried in the dirty[] map can get set. I use a map made out of
// std::atomic<uint8_t> rather than a bitmap to keep the overhead in the
// write barrier as low as I can while also keeping it thread-safe.
//
// At the start of a minor GC I will need to identify all pinned items in the
// scavengable region. I only need to do that for the scavengable page because
// only items inside that could be subject to evacuation. For this I can
// have two maps, one of which lets me identify the starts of all objects
// in the scavengable page and making use of that a second that marks the
// pinned items there. Each of these need to be bitmaps that cover the page
// to a resolution of 8 bytes. Since they are only used by the garbage
// collector they do not need to be atomic or thread-local or any such.
// Ambiguous pointers arise on the (C++) stack but also in segments of
// heap that may be in the stable region or within pages that are mostly
// free but contain some data that was pinned during a previous garbage
// collection, when these regions either contained pointers to nursery or
// pending at the end of a previous minor collection or have been updates
// by RPLACx etc. since then. During a minor GC I will need dirty bits on
// just stable and mostly-free pages, and object-start and pinned bits on
// just the scavengable page, so I can overlap the maps.
// For a major garbage collection the concept of "dirty" does not arise,
// because I will be inspecting every live object everywhere. However I
// will need to end up setting up pinned bits within all regions where
// currently live data exists. While setting up those pinned bits I will need
// object-start information.
    struct PageBody
    {   union PageBitmaps
        {
// Whenever I process an ambiguous pointer I need to identify the
// start address of the object (if any!) that it refers to an address
// within. Notionally I do that by performing a linear scan of the data
// region in the Page. However I can speed things up very usefully by
// first setting up a bitmap that records where each object in the page
// starts and then scanning that bitmap 64-bits at a time. Given 8 Mbyte
// pages there are 1 million potential object start locations (because
// everything gets aligned at 8-byte boundaries). That translates into
// 16K quadwords in the bitmap, and I can skip zero words rapidly and
// easily and then use "find-first-bit" operations when I get close to
// where I need to be.
            std::atomic<uint8_t> dirty[2*bytesForMap];
            uint64_t qwordsDirty[2*qwordsForMap];
            struct Maps
            {   uint64_t objstart[qwordsForMap];
                uint64_t pinned[qwordsForMap];
            } maps;
        } pageBitmaps;
        LispObject data[(pageSize - spareBytes)/sizeof(LispObject)];
    } pageBody;
};

// First I will give code that implements the write-barrier. It is passed
// the address of a valid Lisp location - that can be one of &qcar(x),
// &qcdr(x) or &elt(v, n). It records the fact that an update has
// been made to memory in that region by setting a byte in dirty[]. Because
// the address it is given will always be a VALID address of some location
// in the Lisp heap it can easily find the relevant page...

void write_barrier(LispObject *p)
{   uintptr_t a = reinterpret_cast<uintptr_t>(p);
 // round down to 8M boundary
    Page *x = reinterpret_cast<Page *>(a & -UINT64_C(0x800000));
// I mark the page as a whole as containing some regions that are dirty...
    x->pageHeader.dirtypage.store(true);
// and then use the offset within the page to mark a 32-byte region as
// dirty. The map used here is std::atomic<uint8_t>
    uintptr_t offset = a & 0x7fffffU;
    x->pageBody.pageBitmaps.dirty[offset/32].store(1);
}

// I make the fringe and limit pointers uintptr_t types because that
// way I can be certain how arithmetic baheves. I will need to cast to
// pointer types when I want to read or write the memory that they address.
// Obviously!

std::atomic<uintptr_t> Afringe;
std::atomic<uintptr_t> Alimit;

// Sometimes when I have a pointer to a page I will be thinking of it as
// just that single place, while at other times I will be viewing that as
// the head of a chain of pages. I will try to use PageList* in the latter
// case.

typedef Page PageList;

Page *nurseryPage = NULL;       // where allocation is happening
Page *pendingPage = NULL;
Page *scavengablePage = NULL;
PageList *stablePages = NULL;
PageList *mostlyFreePages = NULL;
PageList *freePages = NULL;
size_t freePagesCount = 0;


// For up to 32 segments I have...
//   heapSegmentCount   number of allocated segments
//   heapSegment[i]      base address of a segment of memory
//   heapSegmentSize[i] size of useful part of that segment, in bytes
//   heapSegmentTotalSize[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

void *heapSegment[32];
void *heapSegmentBase[32];
size_t heapSegmentSize[32];
size_t heapSegmentCount = 0;

// find_heapSegment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it, or -1 if the
// bit-pattern could not be interpreted as a pointer to within the
// memory I have allocated.

extern int find_heapSegment(uintptr_t p);

// Given a value I want to see if it could be a pointer into one of the
// allocated segments. Because there are only 32 of them and if I keep my
// table of segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

inline int find_segment2(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int find_segment4(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+2]))
        return find_segment2(p, n);
    else return find_segment2(p, n+2);
}

inline int find_segment8(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+4]))
        return find_segment4(p, n);
    else return find_segment4(p, n+4);
}

inline int find_segment16(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+8]))
        return find_segment8(p, n);
    else return find_segment8(p, n+8);
}

inline int find_segment32(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+16]))
        return find_segment8(p, n);
    else return find_segment16(p, n+16);
}

int find_heapSegment(uintptr_t p)
{   int n = find_segment32(p, 0);
    if (p < reinterpret_cast<uintptr_t>(heapSegment[n]) ||
        p >= reinterpret_cast<uintptr_t>(heapSegment[n]) +
             heapSegmentSize[n]) return -1;
    return n;
}

// This finds a page that a potential pointer p is within, or returns NULL
// if there is not one

Page *findPage(uintptr_t p)
{   int n = find_heapSegment(p);
    if (n < 0) return NULL;
    return reinterpret_cast<Page *>(p & -pageSize);
}

// I can do cheaper tests if I only concerned with one of the special pages.

bool inNurseryPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(nurseryPage);
    return (p >= n &&
            p < (n + pageSize));
}

bool inPendingPage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(pendingPage);
    return (p >= n &&
            p < (n + pageSize));
}

bool inScavengablePage(uintptr_t p)
{   uintptr_t n = reinterpret_cast<uintptr_t>(scavengablePage);
    return (p >= n &&
            p < (n + pageSize));
}

// Before checking an ambiguous pointer I need to set up the bitmap that
// notes the start-point of objects. This function does that for one page.

void recordObjectStarts(Page *x)
{   memset(x->pageBody.pageBitmaps.maps.objstart, 0,
           sizeof(x->pageBody.pageBitmaps.maps.objstart));
    LispObject *p = x->pageBody.data;
// @@ The version I have here does not yet allow fror the fact that the
// data region within the page will have some pinned objects in and they
// will all need object start tags set - and that fringe may be the
// current level of allocation but the way that interacts with interleaved
// pinned items is not really considered.
    while (reinterpret_cast<uintptr_t>(p) < x->pageHeader.fringe)
    {   size_t os = (reinterpret_cast<uintptr_t>(p) -
                     reinterpret_cast<uintptr_t>(x))/8;
        x->pageBody.pageBitmaps.maps.objstart[os/64] |= UINT64_C(1)<<(os%64);
        LispObject v = *p;
        if (!is_odds(v)) p += 2;
        else if (is_symbol_header(v)) p += symhdr_length/sizeof(LispObject);
        else p += doubleword_align_up(length_of_header(v))/sizeof(LispObject);
    }
    x->pageHeader.onstarts_present = true;
}

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. This must NEVER be called
// with a zero argument. Also note that this function is also defined
// in arithlib.hpp, but since it is "inline" there is not need to worry
// about clashing multiple definitions.

// Count the leading zeros in a 64-bit word.

inline int nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU) {n = n +32; x = x <<32;}
    if (x <= 0x0000FFFFFFFFFFFFU) {n = n +16; x = x <<16;}
    if (x <= 0x00FFFFFFFFFFFFFFU) {n = n + 8; x = x << 8;}
    if (x <= 0x0FFFFFFFFFFFFFFFU) {n = n + 4; x = x << 4;}
    if (x <= 0x3FFFFFFFFFFFFFFFU) {n = n + 2; x = x << 2;}
    if (x <= 0x7FFFFFFFFFFFFFFFU) {n = n + 1;}
    return n;
}

#endif // __GNUC__

// For findObjectStart() the objectstart bitmap is set in the relevant page
// and I must return the untagged address of the item containing the address
// p, or NULL if there is none such. This is used when an ambiguous pointer
// is processed and it maps from the random address-like value to either 0
// which is taken to indicate that the value is not a valid pointer, or
// to the 8-byte aligned address of the start of an object that the
// address lies within. This is perhaps the part of dealing with ambiguous
// pointers that I view as having required most thought!

uintptr_t findObjectStart(uintptr_t p, Page *x)
{
// First check if p is actually within the (active) data region in the page.
    if (p < reinterpret_cast<uintptr_t>(x->pageBody.data) ||
        p >= reinterpret_cast<uintptr_t>(x->pageHeader.fringe)) return 0;
// Now, and I have NOT done this yet, I shoule cope with the case where p
// points within an item that had been pinned within page x by an earlier
// GC.
//  @@ unfinished work here
// Next search for the nearest object start at a lower address than p,
// using the objectstart bitmap to help.
    size_t os = (p - reinterpret_cast<uintptr_t>(x))/8;
    size_t word = os/64;
    int bit = os%64;
// I am going to expect that an especially common case will be when the
// pointer p is just to the start of an object with at most a tag value
// added. My division by 8 a few lines above disarded those low bits, so
// I will see if what I end up with is in fact a proper object start.
    if ((x->pageBody.pageBitmaps.maps.objstart[word] & (UINT64_C(1)<<bit)) != 0)
        return p & -(uintptr_t)8;
// The next case I will consider is if the object header is fairly close
// to p, and the word in the bitmap that covers p includes mention of it.
    if (bit != 0)
    {   uint64_t v = ((UINT64_C(1)<<bit) - 1) &
                     x->pageBody.pageBitmaps.maps.objstart[word];
// Now v records any headers just before p.
        if (v != 0)
        {   int n = 63-nlz(v);
// Convert back from an address in the bitmap to the location in memory.
            return reinterpret_cast<uintptr_t>(x) + 8*(word*64 + n);
        }
    }
// Now I can scan down 64 8-byte locations at a time, ie 512 bytes at a go.
// The distance I may need to go is certainly bounded by the possible size
// of an object that I seem to point within, but for any pointer that is
// really valid it is related to how far down that object I am pointing,
// and so to have a really bad cost here I would have to have a (probable)
// pointer referring to almost the end of a huge object. Because of the
// finite size of a page the very worst cost could be going round the
// simple loop 16K times. Well in fact it is better than that. These days
// the largest basic Lisp object I ever create is of size maybe pageSize/4
// (specifically VECTOR_CHUNK_BYTES), and this sets the worst case distance
// that it can ever be necessary to scan to find an object start.
    word--;
    while (x->pageBody.pageBitmaps.maps.objstart[word] == 0) word--;
// The loop must terminate because any page either has no data in it at all,
// and in that case an ambiguous pointer will be detected as invalid because
// it addresses above fringe, or it will have at least one item in it,
// including one right at its start.
// I will need to double-check this when I put in full support for items that
// where pinned by the last garbage collection, including the case where the
// very first item in the page has that status. Anyway when I find a nonzero
// entry in the map the top bit it identifies the highest-addressed object
// start, and that is what I want.
    int n = 63-nlz(x->pageBody.pageBitmaps.maps.objstart[word]);
    return reinterpret_cast<uintptr_t>(x) + 8*(word*64 + n);
}

// Here we have a function to call during a major garbage collection. It is
// given an (ambiguous) pointer. If necessary it established an objectt-start
// map for the page that addresses, and then it marks as pinned the object
// referenced.

void setPinnedMajor(uintptr_t p)
{   Page *x = findPage(p);
    if (x == NULL) return;
    if (!x->pageHeader.onstarts_present) recordObjectStarts(x);
    uintptr_t os = findObjectStart(p, x);
    if (os == 0) return;
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// At the start of a minor garbage collection it it is necessary to call
// this so that the start-point of all objects in the scavengable region
// are known. This is done explicitly rather than having it done
// conditionally on each case where a pointer (seems to) refer to that region.

void recordObjectStartsMinor()
{   recordObjectStarts(scavengablePage);
}

// Set a pinned bit for an address if it lies within the single scavengable
// page that exists during a minor collection.

void setPinnedMinor(uintptr_t p)
{
// If the address is not in the scavengable page I can ignore it.
    if (!inScavengablePage(p)) return;
// Find the object within the page that it is within, or return NULL if none.
// This will always return a value that is an address aligned zero mod 8.
    uintptr_t os = findObjectStart(p, scavengablePage);
    if (os == 0) return;
// Now I set a bit in the pinned map.
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pageBody.pageBitmaps.maps.pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// Just to provide a level of abstraction I provide a function that clears
// the pinned map in a page. At the start of a minor collection this should
// be called on the scavengable region. Before a major collection on all
// pages.

void clearPinnedMap(Page *x)
{   memset(x->pageBody.pageBitmaps.maps.pinned, 0,
           sizeof(x->pageBody.pageBitmaps.maps.pinned));
}

std::mutex gc_mutex;
extern uintptr_t gc_and_allocate(uintptr_t r, size_t n);

inline LispObject get_n_bytes(size_t n)
{   size_t n1 = doubleword_align_up(n);
// The next two lines will need lengthy discussion if only so I understand
// what I need to do after them.
    uintptr_t limit = Alimit.load();
    uintptr_t result = Afringe.fetch_add(n1);
// The above updated Afringe in an atomic manner, so that if multiple
// threads perform this operation concurrently each will get a result
// corresponding to a distinct chunk of memory. The worry at this stage
// is that Afringe and Alimit might be changed by some other thread after
// Alimit was loaded. Well if the other thread takes its simple path
// all will be well, because all that can happen is that the other thread
// increments Afringe so the space that gets allocated here is at a higher
// address. The messy situation would be if the other thread called
// gc_and_allocate() and that led to Afringe being set to be within a
// different page that happened to be at an address lower than the current
// one. Then the value of result would be based on that that new fringe
// but an old limit...
// However all is not totally lost! If ANY thread sets fringe>=limit then
// until fringe and thread are reset all other threads will come to the
// "need to GC" state, and none will complete a successful allocation.
// However all threads can reset fringe, incrementing it by almost arbitrarily
// large amounts before before the threads synchronize! 
    if (result+n1 >= limit)
        result = gc_and_allocate(result, n);
    return static_cast<LispObject>(result);
}

// It will be important to poll frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupted.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

void poll()
{   if (Afringe.load() >= Alimit.load()) (void)gc_and_allocate(0, 0);
}

// Here we will have:
//    fringe a pointer to where one would next try to allocate;
//    limit an address such that only memory below it may be allocated;
//    r the start of a block that allocation had attempted at;
//    n the size of the block being allocated;
//    fringe >= limit.
// Several threads can be allocating at about the same time, so one will
// be the first to use fetch_add() in a way that makes fringe >= limit.
// But then others can follow on and increment fringe further, but all but
// the first such will deliver r >= limit, and unless recovery action
// resets fringe and/or limit for them to soon all will call gc_and_allocate().
// Well this is an issue, because if gc_and_allocate running in some thread
// can reset things such that fringe < limit before a different thread tests
// for that we can have a memory overflow event undetected.
// As a special case this may be called with r = n = 0 as a way for a
// thread not actually needing memory at the moment to synchronize.

// Now a HORRID feature of the scheme I have here is that I need to keep
// track of how many threads exist and how many are currently running. A
// thread will contribute to the count in "activeThreads" if its is in a
// state where it will poll or allocate memory soon.

std::atomic<int> activeThreads;
std::atomic<bool> gc_complete;
std::mutex mutex_for_gc;
std::condition_variable cv_for_gc;

uintptr_t gc_and_allocate(uintptr_t r, size_t n)
{   int a = (activeThreads -= 1);
    if (a == 0)
    {   gc_complete.store(false);
// Do the stuff.
        std::lock_guard<std::mutex> guard(mutex_for_gc);
        gc_complete.store(true);
        cv_for_gc.notify_all();
    }
    else
    {   std::unique_lock<std::mutex> lock(mutex_for_gc);
        cv_for_gc.wait(lock, []{ return gc_complete.load(); });
    }
    return 0000000;
}


inline LispObject cons(LispObject a, LispObject b)
{   LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r) = a;
    qcdr(r) = b;
    return r;
}

// With the conservative collector I maybe do not need to avoid garbage
// collection on any particular individual uses of cons().

inline LispObject cons_no_gc(LispObject a, LispObject b)
{   return cons(a, b);
}

inline LispObject cons_gc_test(LispObject p)
{   return p;
}

inline LispObject ncons(LispObject a)
{   LispObject r = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r) = a;
    qcdr(r) = nil;
    return r;
}

// Here I can wonder if there is a good way to save overhead by allocating
// both cells as one operation...

inline LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = nil;
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = d;
    return r1;
}

inline LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_n_bytes(8*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    LispObject r4 = r3 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcar(r4) = d;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = r4;
    qcdr(r4) = nil;
    return r1;
}



inline LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(4*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    qcar(r1) = r2;
    qcar(r2) = a;
    qcdr(r1) = c;
    qcdr(r2) = b;
    return r1;
}

inline LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   return acons(a, b, c);
}

inline LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_n_bytes(6*sizeof(LispObject)) + TAG_CONS;
    LispObject r2 = r1 + 2*sizeof(LispObject);
    LispObject r3 = r2 + 2*sizeof(LispObject);
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcdr(r1) = b;
    return onevalue(r1);
}

inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = b;
    qcdr(r1) = a;
    return onevalue(r1);
}

inline LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

inline LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get_n_bytes(2*sizeof(LispObject)) + TAG_CONS;
    qcar(r1) = a;
    qcdr(r1) = nil;
    return onevalue(r1);
}

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
// tag is the value (e.g. TAG_VECTOR) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_STRING) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
    size_t allocSize = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
    if (allocSize > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = get_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multiple of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

inline Header make_padding_header(size_t n)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + TYPE_PADDER;
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors. This is ONLY used when a hash table
// finds that the number of items in it has decreased dramatically and it
// wants to shrink. For big tables the index vector will decrease in size
// but each sub-vector stored in it will remain as it is. For smaller tables
// it can be the table itself that shrinks. When a vector shrinks I should
// put a padder in the vacated space so that it will still be possible to
// do linear scans of memory.

LispObject reduce_basic_vector_size(LispObject v, size_t len)
{   size_t oldlen = doubleword_align_up(length_of_header(vechdr(v)));
    vechdr(v) = TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED;
    len = doubleword_align_up(len);
    if (len != oldlen) vechdr(v + len) = make_padding_header(oldlen-len);
    return v;
}

// As well as shrinking vectors the hash table code can want to "borrow"
// space by allocating vectors (never lists) from the half of memory that
// the copying garbage collector is not keeping live data in at present.
// The protocol I have is that it goes
//      prepare_for_borrowing();
//      ... get_vector() ... get_vector() ...
// and it MUST be coded so that it can not trigger garbage collection while
// the "borrowed" vectors are in use. It does not have any specific way of
// indicating when the space is no longer needed, save that a subsequent
// call to prepare_for_borrowing() must not happen while borrowed space is
// still needed. The key use for this is when a hash table needs to be
// re-hashed - the code borrows space and copies the existing table contents
// into it. It then re-hashes everything back into the existing vector.
// Doing things that way really simplifies the hash table code, and avoids
// having the temporary space anything other than rather temporary and
// transient. However the scheme is not very thread-friendly! My current
// plan is that only one thread may be re-hashing (and hence borrowing) at
// once, and while that is happening any other thread that needs to trigger
// garbage collection will have to wait. I am putting in stubs of code here
// but the code to borrow memory will in fact be very similar to that used
// during garbage collection to allocate space in the new half-space when
// a vector needs to be evacuated to there.

// Perhaps I could invent and then use an alternative protocol so that each
// thread could do its own borrowing without messy clashes. Perhaps the main
// issue there is recovering memory when a thread has finished. To think
// about how vital that might be I would need to consider whether hash tables
// might need rehashing multiple times between garbage collections - if the
// answer is "no" then each hash table could have its own associated
// borrowed shadow ... that starts to sound sensible to me! I will get a LOT
// more of this code working before I worry about that detail.

void prepare_for_borrowing()
{   my_abort();
}

// It would be a fatal error if there was not space for the borrow!

LispObject borrow_n_bytes(size_t n)
{   my_abort();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   size_t allocSize = (size_t)doubleword_align_up(size);
    if (allocSize > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(allocSize/CELL-1));
    LispObject r = borrow_n_bytes(allocSize);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && allocSize != size)
        *(LispObject *)(r+allocSize-CELL) = 0;
    return (LispObject)(r + tag);
}

LispObject borrow_vector(int tag, int type, size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        size_t lastSize = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (lastSize == 0) lastSize = VECTOR_CHUNK_BYTES;
        LispObject v =
            borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (size_t i=0; i<chunks; i++)
        {   size_t k = i==chunks-1 ? lastSize : VECTOR_CHUNK_BYTES;
            basic_elt(v, i) = borrow_basic_vector(tag, type, k+CELL);
        }
        return v;
    }
    else return borrow_basic_vector(tag, type, n);
}

// This code sets up an empty page - it is ONLY intended for use at the
// start of a run when there can not be any pinned items present anywhere.
// I put the code here adjacent to the code that allocates from pages so
// that the setup and use can be compared.


static void set_up_empty_page(Page *p)
{   p->pageHeader.fringe = reinterpret_cast<uintptr_t>(&p->pageBody.data);
    p->pageHeader.limit = reinterpret_cast<uintptr_t>(p) + sizeof(Page);
    p->pageHeader.dirtypage.store(false);
    p->pageHeader.onstarts_present = false;
// I would like to be able to set the dirty bitmap all zero other than by
// using the store() method one byte at a time. It is also possible that
// when I first allocate a page that page will not be put in the stable
// region of the heap so its dirty map will not be inspected - and if that is
// the case this initialization loop is not actually needed. I will put it
// in for now to be tidy!
    for (size_t i=0; i<2*bytesForMap; i++)
        p->pageBody.pageBitmaps.dirty[i].store(0);
}

void set_variables_from_page(Page *p)
{
// Set the variable that are used when allocating within the active page.
    Afringe = p->pageHeader.fringe;
    Alimit = p->pageHeader.limit;
}

void save_variables_to_page(Page *p)
{
// Dump global variable values back into a page header.
    p->pageHeader.fringe = Afringe;
    p->pageHeader.limit  = Alimit;
}

// This code allocates a segment by asking the operating system.
// It must return a block that is aligned to sizeof(Page).
// The collection of segments must be stored in heapSegments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.

void *allocate_segment(size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// page size. Note that this will be quite a large value!
    n = (n + pageSize - 1) & -pageSize;
    Page *r;
    void *rbase;
// If I have C++17 I can rely on alignment constraints and just allocate
// using new[]
#ifdef __cpp_aligned_new
    r = new Page[n/pageSize];
    my_assert(r != NULL);
    rbase = static_cast<void *>(r);
#else // !__cpp_aligned_new
// On older platforms I need to allocate extra memory and then use std::align
// to get the address within the bigger block that I want.
// In this case I will need to preserve the base of the full block because
// that will be what I will be able to free at the end.
    size_t N = n + pageSize - 1;
    rbase = static_cast<void *>(new char[N]);
    my_assert(rbase != NULL);
    void *work = rbase;
    work = std::align(pageSize, n, work, N);
    my_assert(work != NULL);
    r = static_cast<Page *>(work);
#endif // !__cpp_aligned_new
    heapSegment[heapSegmentCount] = r;
    heapSegmentBase[heapSegmentCount] = rbase;
    heapSegmentSize[heapSegmentCount] = n;
    heapSegmentCount++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (size_t i=heapSegmentCount-1; i!=0; i--)
    {   int j = i-1;
        void *h1 = heapSegment[i], *h2 = heapSegment[j];
        if (reinterpret_cast<uintptr_t>(h2) < reinterpret_cast<uintptr_t>(h1))
            break; // Ordering is OK
// The segment must sink a place in the tables.
        std::swap(heapSegment[i], heapSegment[j]);
        std::swap(heapSegmentBase[i], heapSegmentBase[j]);
        std::swap(heapSegmentSize[i], heapSegmentSize[j]);
    }
// r now refers to a new segment of size n, I want to structure it into
// pages.
    freePagesCount = 0;
    for (size_t k=0; k<n; k+=CSL_PAGE_SIZE)
    {   Page *p = reinterpret_cast<Page *>(reinterpret_cast<char *>(r) + k);
// Keep a chain of all the pages.
        p->pageHeader.chain = freePages;
        freePages = p;
        set_up_empty_page(p);
        freePagesCount++;
    }
    printf("%" PRIu64 " pages available\n", (uint64_t)freePagesCount);
    return static_cast<void *>(r);
}

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

bool next_gc_is_hard = false;
uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
            force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
}

extern void middle_reclaim();
extern void inner_reclaim(uintptr_t *sp);

// The next section of code represents an attempt to coax "reasonable"
// compilers into arranging that all registers that had been in use when
// reclaim() is called end up somewhere on the stack by the time that
// inner_reclaim() is entered. It is pretty clear that this is not the
// sort of thing that fully guaranteed portable code can achieve! I apply
// two ideas. The first is to have a function that is liable to want to
// keep a dozen value in its registers - and to do that it is liable to
// flush callee-save ones to the stack. I used to use the "register"
// qualifier to try to advise the compiler to do what I want, but modern
// compilers may now reject that. So I just use lots of registers and hope.
// As a secoondary attempt I use setjmp() which I hope and expect dumps
// a copy of all useful machine registers into the given jmp_buf. Again
// this is not guaranteed, but it is at least plausible!
// The use of volatile_variable is a further attempt to prevent any
// clever compiler frm observing that all that I do is frivolous and
// then discarding it. These days I use std::atomic rather than the volatile
// qualifier since I believe that volatile will soon be deprecated!

std::atomic<int> volatile_variable = 12345;

void reclaim(int line)
{
// This function is not officially portable in any way.
//
// The purpose of this function is to force any even partially
// reasonable C compiler into putting all registers that contain
// values from the caller onto the stack. It assumes that there
// could not be more than 12 "callee saves" registers, that the
// "register" qualifier in the declaraion here will cause a1-a12 to
// take precedence when allocating same, and that the volatile
// qualifier on the variable that is repeatedly referenced is there
// to try to tell the compiler that it may not make any assumptions
// (eg that a1-a12 might not all have the same value), and the use
// of them again after the call to inner_reclaim() should force
// each of those values to be saved across that call. The work done
// is of course a waste (but assigning back to a volatile variable
// may force it to be done!) but is modest in the large scheme of
// things. On most machines I can think of there are a lot fewer
// than 12 callee-save registers and so this is overkill!
    int a1 = volatile_variable;
// The declarations here go one at a time to stress the sequential nature
// of the references to volatile_variable.
    int a2 = volatile_variable;
    int a3 = volatile_variable;
    int a4 = volatile_variable;
    int a5 = volatile_variable;
    int a6 = volatile_variable;
    int a7 = volatile_variable;
    int a8 = volatile_variable;
    int a9 = volatile_variable;
    int a10 = volatile_variable;
    int a11 = volatile_variable;
    int a12 = volatile_variable;
// Even with a heavily optimising compiler the above ought to generate
// 12 loads from the volatile_variable because in principle the values so
// loaded could all be different. Now is 12 enough? Well on the machines I
// know about it is plenty!
    jmp_buf jb;
    if (setjmp(jb) != 0) volatile_variable++;
// setjmp is expected to save all registers in jb.
    for (int i=0; i<1000000; i++)
    {   middle_reclaim();
// The loop is so that a compiler can believe that there is a chance that
// everything will be executed up to a million times, and that might encourage
// it to try quite hard to store the values of a1-a12 in registers (thus
// flushing any values from its caller to stack). But in fact the code will
// return after calling middle_reclaim() without doing anything else that
// might be costly. So my expectation is that the function here will consume
// some space in program memory but will represent really rather a small
// burden on CPU time.
//
// On the next line I believe that because volatile_var is an std::atomic<int>
// the compiler must assume that the two references might yield different
// values. I would rather like to instruct the compiler to assume that
// the values will almost always differ, because if it guesses that mostly
// they will match it may optimize on the basis of the loop not
// getting traversed a lot.
        if (volatile_variable == volatile_variable) return;
// The longjmp here will never be taken, but the compiler is not allowed to
// assume that! Therefore it must keep jb on alive on the stack during the
// call to middle_reclaim().
        if (volatile_variable != volatile_variable) longjmp(jb, 1);
// This now references a1-a12, which could all hold unrelated values so
// all need to be stored independently. I am hoping that many are kept in
// registers!
        volatile_variable += a1;
        volatile_variable += a2;
        volatile_variable += a3;
        volatile_variable += a4;
        volatile_variable += a5;
        volatile_variable += a6;
        volatile_variable += a7;
        volatile_variable += a8;
        volatile_variable += a9;
        volatile_variable += a10;
        volatile_variable += a11;
        volatile_variable += a12;
// The code above references each of a1 to a12 and combines their
// values with volatile_variable in a way intended to mean that they must
// all be saved across the call to middle_reclaim(). The code is written
// line by line to arrange that there are sequence points between each
// access to volatile_variable, and in the compiler's imagination some other
// part of the full world might inspect the value stored there at any of
// those points, so there should be no legitimate scope for any optimization
// that would avoid having all the 12 potentially distinct value in a1-a12
// safely kept available.
    }
}

#ifdef __GNUC__
[[gnu::noinline]]
#endif // __GNUC__
void middle_reclaim()
{
// This function is here to have a stack frame (containing w) that will
// lie between that of reclaim and inner_reclaim. The stupid-looking test
// on volatile_variable is intended to persuade clever compilers that they
// should not compile this procedure in-line or consolidate its stack
// frame with either its caller or callee by making it appear that it
// could be recursive. The address of the top of the stack is passed onwards,
// adjusted so as to be alined as for a LispObject.
    uintptr_t w = 0;
    if (volatile_variable != volatile_variable)
    {   inner_reclaim(NULL);  // never executed!
        middle_reclaim();     // never executed! But looks recursive.
    }
    inner_reclaim((uintptr_t *)((intptr_t)&w & -sizeof(LispObject)));
}

void inner_reclaim(uintptr_t *sp)
{
}

void garbage_collect()
{   printf("NOT IMPLEMENTED YET\n");
    abort();
}

void *nilsegmentBase, *stacksegmentBase;

void init_heapSegments(double storeSize)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
//
{
// I will make the default initial store size around 64M on a 64-bit
// machine and 512M on a 64-bit system. If the user specified a "-K" option
// they can override this, and also the system will tend to allocate more
// space (if it can) when its memory starts to get full.
    size_t freeSpace = (SIXTY_FOUR_BIT ? 512 : 64)*1024*1024;
    size_t request = (size_t)storeSize;
    if (request != 0) freeSpace = 1024*request;
// Now freeSpace is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heapSegmentCount = 0;
    freePages = NULL;
    printf("Allocate %" PRIu64 " Kbytes\n", (uint64_t)freeSpace/1024);
    allocate_segment(freeSpace);

// There are other bits of memory that I will grab manually for now...
    nilsegment = (LispObject *)aligned_malloc(NIL_SEGMENT_SIZE+16);
    nilsegmentBase = nilsegment;
#ifdef COMMON
    nil = (LispObject)((uintptr_t)nilsegment + TAG_CONS + 8);
#else
    nil = (LispObject)((uintptr_t)nilsegment + TAG_SYMBOL);
#endif
    stacksegment = (LispObject *)aligned_malloc(CSL_PAGE_SIZE);
    stacksegmentBase = stacksegment;
    if (stacksegment == NULL) fatal_error(err_no_store);
    stackbase = (LispObject *)stacksegment;
}

void drop_heapSegments(void)
{   for (size_t i=0; i<heapSegmentCount; i++)
        delete [] static_cast<Page *>(heapSegmentBase[i]);
    delete [] nilsegmentBase;
    delete [] stacksegmentBase;
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   if ((init_flags & INIT_EXPANDABLE) == 0) return false;
    void *page = (void *)aligned_malloc((size_t)CSL_PAGE_SIZE);
    if (page == NULL)
    {   init_flags &= ~INIT_EXPANDABLE;
        return false;
    }
    else
    {   pages[pagesCount++] = page;
        return true;
    }
}

extern double maxStoreSize;

void grab_more_memory(size_t npages)
{
// Here I grab more memory (if I am allowed to).
// An initial version here, and one still suitable on machines that will
// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
// 3*n + 2. This expands until the proportion of the heap active at the
// end of garbage collection is less than 1/4.
// If the attempt to grab more memory fails I clear the bit in init_flags
// that allows me to try to expand, so I will not waste time again.  If
// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
// available memory may cause a crash) I do not try this operation.  The
// aim of keeping the heap less than half full is an heuristic and could be
// adjusted on the basis of experience with this code.
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
    if (init_flags & INIT_EXPANDABLE)
    {   size_t ideal = ok_to_grab_memory(heap_pagesCount + vheap_pagesCount);
        size_t more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (maxStoreSize != 0.0)
        {   double pageLimit = maxStoreSize*1024*1024/(double)CSL_PAGE_SIZE;
// Limit memory to (about) the amount the user indicated with --max-mem
            size_t plim = (size_t)pageLimit;
            if (ideal > plim) ideal = plim;
        }
        if (ideal > pagesCount)
        {   more = ideal - pagesCount;
            while (more > 0)
            {   if (!allocate_more_memory()) break;
                more--;
            }
        }
    }
}


#ifdef WIN32
#include <conio.h>
#endif

int64_t gc_number = 0;
int64_t reclaim_trap_count = -1;
uintptr_t reclaim_stack_limit = 0;
uint64_t reclaim_trigger_count = 0, reclaim_trigger_target = 0;

static intptr_t cons_cells, symbol_heads, strings, user_vectors,
       big_numbers, box_floats, bytestreams, other_mem,
       litvecs, getvecs;

LispObject Lgc0(LispObject env)
{   return Lgc(env, lisp_true);
}

LispObject Lgc(LispObject env, LispObject a)
{
// If GC is called with a non-nil argument the garbage collection
// will be a full one - otherwise it will be soft and may do hardly
// anything.
#if 0
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
#endif
}

LispObject Lverbos(LispObject env, LispObject a)
// (verbos 0) or (verbos nil)       silent garbage collection
// (verbos 1) or (verbos t)         standard GC messages
// (verbos 2)                       messages when FASL module loaded
// (verbos 4)                       extra timing info for GC process
// These bits can be added to get combination effects, except that
// "4" has no effect unless "1" is present.
{   int code, old_code = verbos_flag;
    if (a == nil) code = 0;
    else if (is_fixnum(a)) code = (int)int_of_fixnum(a);
    else code = 1;
    miscflags = (miscflags & ~GC_MSG_BITS) | (code & GC_MSG_BITS);
    return onevalue(fixnum_of_int(old_code));
}

bool volatile already_in_gc;
bool volatile interrupt_pending;
LispObject volatile saveheaplimit;
LispObject volatile savevheaplimit;
LispObject * volatile savestacklimit;

static int stop_after_gc = 0;

bool force_verbos = false;

bool garbage_collection_permitted = false;

static void real_garbage_collector()
{
// I lift the real garbage collector to a separate function mainly
// so that I can set breakpoints on it!
    for (int i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
        free_vectors[i] = 0;

}

LispObject reclaim(LispObject p, const char *why, int stg_class, size_t size)
{
}

// end of newallocate.cpp
