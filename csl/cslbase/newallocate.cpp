// newallocate.cpp                         Copyright (C) 1989-2019 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
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

extern std::atomic<LispObject *> fringe;
extern std::atomic<LispObject *> limit;

extern std::atomic<LispObject *> vfringe;
extern std::atomic<LispObject *> vlimit;

std::mutex gc_mutex;
extern LispObject *gc_and_allocate(LispObject *r, size_t n);
extern void gc_elsewhere();

LispObject cons(LispObject a, LispObject b)
{   LispObject *result = fringe.fetch_add(2);
    if (fringe.load() >= limit.load())
        result = gc_and_allocate(result, 2);
    result[0] = a;
    result[1] = b;
    return TAG_CONS+reinterpret_cast<LispObject>(result);
}

// In the fullness of time I will need to arrange for both vectors
// containing Lisp object-references and ones that hold raw binary data:
// for now I will not deal with that!

LispObject getvec(size_t n)
{   LispObject *result = fringe.fetch_add(n);
    if (fringe.load() >= limit.load())
        result = gc_and_allocate(result, n);
    result[0] = TAG_HDR_IMMED + (n<<4); // size packed into header word
// Only the header word is filled in here.
    return TAG_VECTOR+reinterpret_cast<LispObject>(result);
}

// It will be important to call this frequently because when one thread
// observes that it needs to garbage collect all other threads must be
// paused. Any other that calls cons() or getvec() will pause there, but
// code in a loop that did not allocate memory could cause an unbounded
// delay unless this is called such that the loop can be interrupred.
// Extra steps will be needed when library calls that might block are
// made, but details of that belong elsewhere.

void poll()
{   if (fringe.load() >= limit.load()) gc_elsewhere();
}


#endif // 0














// The definitions here are ones that will eventually not be needed with
// the conservative model - or will be re-introduced with quite different
// implementation or impact. But they are defined here to allow me to
// build a version so that I can test it incrementally.

void **pages, **heap_pages, **vheap_pages;
size_t pages_count, heap_pages_count, vheap_pages_count;
void **new_pages, **new_heap_pages, **new_vheap_pages;
size_t new_pages_count, new_heap_pages_count, new_vheap_pages_count;

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
        heap_segment[i] = reinterpret_cast<void *>(UINTPTR_MAX);
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
// use, but then use static_assert to confirm them or to cause CSL to
// fail to compile. I believe that my assumptions have a good chance of being
// satisfied on almost all machines, even though I can imagine architectures
// where there may be trouble. But what matters most to me will be x86,
// x86_64 and both 32 and 64-bit ARM when using g++ or clang, and those will
// get checked the first time I compile this code on each.

static_assert(sizeof(std::atomic<uint8_t>) == 1,
              "Atomics bytes are too large");
static assert(std::atomic<uint8_t>().is_lock_free(),
              "Atomic<uint8_t> not lock-free");
static assert(std::atomic<uintptr_t>().is_lock_free(),
              "Atomic<uintptr_t> not lock-free");

// I am going to require Pages to be aligned at nice neat boundaries
// because then if I have an arbitrary address within one I will be able to
// find the page header using a simple AND operation.

union alignas(pageSize) Page
{   struct
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
        uintpt_t fringe;
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
        bool dirtypage;
// During garbage collection I need a map showing where each object on a
// page starts. This boolean is set when that map is set up and available
// for use. Because the map shares space with the "dirty[]" map it will
// be invalidated whenever the mutator runs, and so the information will
// have to be regenerated at the start of each garbage collection.
        bool onstarts_present;
    };
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
    struct
    {   union
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
            struct
            {   uint64_t objstart[qwordsForMap];
                uint64_t pinned[qwordsForMap];
            }
        }
        LispObject data[(pageSize - spareBytes)/sizeof(LispObject)];
    };
};

std::atomic<uintptr_t> fringe;
std::atomic<uintptr_t> limit;

// Sometimes when I have a pointer to a page I will be thinking of it as
// just that single place, while at other times I will be viewing that as
// the head of a chain of pages. I will try to use PageList* in the latter
// case.

typedef Page PageList;

Page *nurseryPage;       // where allocation is happening
Page *pendingPage;
Page *scavengablePage;
PageList *stablePages;
PageList *mostlyFreePages;
PageList *freePages;

// For up to 32 segments I have...
//   heap_segment_count   number of allocated segments
//   heap_segment[i]      base address of a segment of memory
//   heap_segment_size[i] size of useful part of that segment, in bytes
//   heap_segment_total_size[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

void *heap_segment[32];
size_t heap_segment_size[32];
size_t heap_segment_total_size[32];
size_t heap_segment_count = 0;

// find_heap_segment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it, or -1 if the
// bit-pattern could not be interpreted as a pointer to within the
// memory I have allocated.

extern int find_heap_segment(uintptr_t p);

// Given a value I want to see if it could be a pointer into one of the
// allocated segments. Because there are only 32 of them and if I keep my
// table of segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

inline int find_segment2(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heap_segment[n+1])) return n;
    else return n+1;
}

inline int find_segment4(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heap_segment[n+2]))
        return find_segment2(p, n);
    else return find_segment2(p, n+2);
}

inline int find_segment8(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heap_segment[n+4]))
        return find_segment4(p, n);
    else return find_segment4(p, n+4);
}

inline int find_segment16(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heap_segment[n+8]))
        return find_segment8(p, n);
    else return find_segment8(p, n+8);
}

inline int find_segment32(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heap_segment[n+16]))
        return find_segment8(p, n);
    else return find_segment16(p, n+16);
}

int find_heap_segment(uintptr_t p)
{   int n = find_segment32(p, 0);
    if (p < reinterpret_cast<uintptr_t>(heap_segment[n]) ||
        p >= reinterpret_cast<uintptr_t>(heap_segment[n]) +
             heap_segment_size[n]) return -1;
    return n;
}

// This finds a page that a potential pointer p is within, or returns NULL
// if there is not one

Page *findPage(uintptr_t p)
{   int n = find_heap_segment(p);
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
{   memset(x->objstart, 0, sizeof(x->objstart));
    LispObject *p = &x->data;
// @@ The version I have here does not yet allow fror the fact that the
// data region within the page will have some pinned objects in and they
// will all need object start tags set - and that fringe may be the
// current level of allocation but the way that interacts with interleaved
// pinned items is not really considered.
    while (reinterpret_cast<uintptr_t>(p) < x->fringe)
    {   size_t os = (reinterpret_cast<uintptr_t>(p) -
                     reinterpret_cast<uintptr_t>(x))/8;
        x->objstart[os/64] |= UINT64_C(1)<<(os%64);
        LispObject v = *p;
        if (!is_odds(v)) p += 2;
        else if (is_symbol_header(v)) p += symmhdr_length/sizeof(LispObject);
        else p += doubleword_align_up(length_of_header(v))/sizeof(LispObject);
    }
    x->onstarts_present = true;
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
    if (p < reinterpret_cast<uintptr_t>(&x->data) ||
        p >= reinterpret_cast<uintptr_t>x->fringe) return 0;
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
    if ((x->objstart[word] & (UINT64_C(1)<<bit)) != 0)
        return p & -(uintptr_t)8;
// The next case I will consider is if the object header is fairly close
// to p, and the word in the bitmap that covers p includes mention of it.
    if (bit != 0)
    {   uint64_t v = (UINT64_C(1)<<bit - 1) & x->objstart[word];
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
    while (x->objstart[word] == 0) word--;
// The loop must terminate because any page either has no data in it at all,
// and in that case an ambiguous pointer will be detected as invalid because
// it addresses above fringe, or it will have at least one item in it,
// including one right at its start.
// I will need to double-check this when I put in full support for items that
// where pinned by the last garbage collection, including the case where the
// very first item in the page has that status. Anyway when I find a nonzero
// entry in the map the top bit it identifies the highest-addressed object
// start, and that is what I want.
    int n = 63-nlz(x->objstart[word]);
    return reinterpret_cast<uintptr_t>(x) + 8*(word*64 + n);
}

// Here we have a function to call during a major garbage collection. It is
// given an (ambiguous) pointer. If necessary it established an objectt-start
// map for the page that addresses, and then it marks as pinned the object
// referenced.

void setPinnedMajor(uintptr_t p)
{   Page *x = findPage(p);
    if (x == NULL) return;
    if (!x->onstarts_present) recordObjectStarts(x);
    uintptr_t os = findObjectStart(p, x);
    if (os == NULL) return;
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// At the start of a minor garbage collection it it is necessary to call
// this so that the start-point of all objects in the scavengable region
// are known. This is done explicitly rather than having it done
// conditionally on each case where a pointer (seems to) refer to that region.

void recordObjectStartsMinor()
{   recordObjectStarts(scavengable);
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
    if (os == NULL) return;
// Now I set a bit in the pinned map.
    os = (os - reinterpret_cast<uintptr_t>(scavengablePage))/8;
    scavengablePage->pinned[os/64] |= UINT64_C(1)<<(os%64);
}

// Just to provide a level of abstraction I provide a function that clears
the pinned map in a page. At the start of a minor collection this should
// be called on the scavengable region. Before a major collection on all
// pages.

clearPinnedMap(Page *x)
{   memset(x->pinned_bitmap, 0, sizeof(x->pinned_bitmap));
}

//@@@@@@@@@@@@


A page starts with a header and one or two bitmaps and then its
// data region. I will just discuss the data region here.
// The data region may be disrupted with some pinned items within in, and
// those pinned items must be worked around during allocation. Each clump on
// pinned items will be padded (if necessary) so that the clump is an even
// number of cells long. If a clump lines within the data region it will
// be followed by two information words.

// vheapstart is the first address of the current free chunk of memory
// within which vectors will be allocated.
uintptr_t vheapstart;

// vfringe is the first address beyond vectors that have been allocated
// from vheapstart upwards.  So if a new vector is allocated (in a simple way)
// its existing value will be returned and it will be incremented to point
// beyond the newly allocated object.
uintptr_t vfringe;

// vheaplimit is the first address that must NOT be included in any new
// allocation. It will typically point to the start of a pinned region
// that represents the end of the current free vector chunk, and if there
// are no pinned regions it will point to the vect end of the page.
uintptr_t vheaplimit;


// vheaptop is the address above any pinned block that is at the end of
// the current vector allocation region. vheaptop-vheaplimit == vlen
// in easy circumstances, but by having these two variables separate I
// am free to alter vheaplimit any time I feel that I need to.
uintptr_t vheaptop;

// vlen is the length of the pinned block (if any) that lies just beyond
// the end of this allocation region.
uintptr_t vlen;

// vxor_chain is used to chain pinned regions together using the trick
// where if you have three addresses in a list that you want to be
// two-way linked you store the XOR of the first and last address in the
// middle location.
uintptr_t vxor_chain;

// Similar information is kept for the part of the page used to hold
// 2 word items:

// heapstart is the high address associated with this chunk. This points
// to the address above any pinned block that sits above this chunk.
uintptr_t heapstart;

// fringe points to the last 2-word item allocated, or just beyond the
// chunk if none has been allocated yet.
uintptr_t fringe;

// heaplimit is such that the test (heaplimit <= fringe) shows when allocation
// will be instantly valid. Thus it points to a free doubleword. In some
// cases this will be the first address after a pinned block that preceeds
// the chunk. But if the vector chunk and the cons chunk are the same
// then (heaplimit==vfringe). If this situation is true at the start of
// allocation of a vector it will be maintained at the end, so this
// test can always be applied to see if vector and 2-word allocations are
// at any risk of collision.
uintptr_t heaplimit;

// len is analagous to vlen, and gives the length of a pinned regsion at
// and address just below this chunk.
uintptr_t len;

// xor_chain is the same sort of value as vxor_chain, and helps chain
// pinned regions in a two-way style.
uintptr_t xor_chain;

// whenever there is a pinned region within a page (and recall that pinned
// blocks will be aligned at even addresses and will have even length), the
// two words immediately after the pinned material hold (len) and (xor_chain)
// information, where the (xor_chain) value is the exclusive or of the
// addresses of previous and following pinned regions, or to be more precise
// the exclusive or of the addresses of the (len) fields that follow these
// blocks.

// Here is a diagram showing the vector part of the heap...
//
//     vheapstart               vheaplimit      vheaptop
//         |                        |              |
//        ...  usable space       | XXXXXXXXXXXX | len | xor | ...
//                   |             (pinned stuff)
//                vfringe
//   len: length of the XXXX pinnedd region.
//   xor: exclusive OR of vheapstart and the LEN field of the next
//        region up beyond the ones shown.


// When (heaplimit==vfringe) the situation has resolved to a state where
// there are no further pinned regions to worry about, and then when either
// fringe meets heaplimit or vfringe meets vheaplimit the entire page will
// be considered full. This situation naturally gets set up when a vector
// allocation moves past a pinned regsion. When a 2-word allocation moves
// part a pinned regsion it will need to reset heaplimit to the low address
// in the next chunk down, but then if (heaplimit==vheapstart) it will need
// to reset it to be vfringe.

// The fact that there are ten variable involved gives a clue to the fact
// that designing this arrangement was stressful and went through several
// iterations and much uncertainty!

static void allocate_next_page(), gc_allocate_next_page();

inline Header make_padding_header(size_t n)
{   return TAG_HDR_IMMED+TYPE_PADDER+(n<<(Tw+7));
}

static void get_2_words_past_pin()
{   if (vheaptop == heapstart)
    {
// Vector and 2-word items have just collided, well ALMOST because the vector
// allocation may have used an odd number of words. To leave everything
// tidy in case I need to do a linear scan (eg as part of a generational
// collector) I fill in the 1-word gap with a nice padder. This issue can
// never arise on a 32-bit platform because there a CONS cell is 8 bytes wide
// and all vectors are allocated as a multiple of 8 bytes.
        if (SIXTY_FOUR_BIT && fringe == vfringe-CELL)
        {   *(Header *)vfringe = make_padding_header(CELL);
// Logically I want this padder not to be accepted by the conservative
// collector as the start of a real object, so I want its "object start" bit
// to be clear. Ha ha that will already be the case. So I show what the code
// would be but comment it out as unnecessary. This is just a 1-word padder.
//--        clear_header_bit(vfringe, active_page);
        }
        allocate_next_page();
// After allocating a new page (and sometimes that will involve garbage
// collection) there will always be room to set aside memory for a CONS.
// That is because the garbage collector must never set a new active page
// that is totally full. A page could hypothetically be totally full if
// every address within it was pinned, but that would be a really unusual
// pathological situation!
        return;
    }
    uintptr_t w = heaplimit;
    heaplimit = heapstart ^ xor_chain;
    heapstart = w;
    fringe = w - len;
// Now I may just have moved down onto the segment within which vector
// allocation is taking place...
    if (vheaptop == heapstart)
    {
// When vector and 2-word regions coalesce I will not subsequently have any
// more movement across pinned areas, and so I do not need heaplimit as a
// pointer to the base of the region.
        heaplimit = vfringe;
// It might be that the segment was in fact already totally full of vectors,
// in which case I must garbage collect. I need to allow for the possibility
// that vectors had filled all bar one word of the chunk. This can only
// arise on a 64-bit platform.
        if (SIXTY_FOUR_BIT && fringe == vfringe+CELL)
        {   *(Header *)vfringe = make_padding_header(CELL);
            vfringe += CELL;
            allocate_next_page();
        }
        else if (fringe == vfringe) allocate_next_page();
// Now I know that there is space for a 2-word item, either because there
// was genuine space in the region or because allocate_next_page will have
// left me in good shape.
        return;
    }
// Here I have moved to a new region which is not totally full, so I can
// just allocate within it, but I need to set some of my magic variables.
// One reason to read these values here is so that all the space in the
// segment becomes available for allocation... I do not need to worry about
// the mutator overwriting anthing with it.
    len = ((uintptr_t *)heaplimit)[0];
    xor_chain = ((uintptr_t *)heaplimit)[1];
}

// get_2_words() is the core of CONS and can also be used for allocating the
// space needed for a double-precision float on a 64-bit machine. The aim is
// therefore to make the common case in it as fast as feasible. This is
// the allocation of 2 consecutive words of memory until the current active
// block is full or until pinned data within it is reached.

inline LispObject get_2_words()
{
// If there is a free doubleword immediately available then use it. I very
// much hope that this will be the situation almost all of the time.
// This is "inline" because it is fairly short and it should represent
// by a large margin the most common case encountered when performing CONS
// operations.
    fringe -= 2*CELL;
    if (fringe < heaplimit) get_2_words_past_pin();
// There is an additional condiction that I am arranging will not need any
// code here by that does need commenting on. Within a page the first word
// of any object must be tagged in the "object start" bitmap. This bitmap
// covers the page at a resolution of 8 bytes. On a 64-bit machine a full
// cons cell is 16 bytes long, so its first word (the CAR field) needs tagging
// but the second does not. Well when I set up an empty page I will ensure
// that in this case the bitmap starts off with every other word tagged.
// On a 32-bit machine the initial state has to show every 64-bit word
// tagged, and this will be taken as marking the 32-bit part that falls as an
// even address.
// I should further note that object start bits must be correctly set for
// any items in pinned regions, but that if one has padding items (sometimes
// needed to help with alignment) their headers will not be tagged. That is
// so that ambiguous pointers to them will not keep them alive.
    return fringe;
}

static void get_n_bytes_past_pin()
{
// The vector I want to allocate will not fit at the next consecutive
// address. So to keep the heap tidy I will insert a padder record
// there.
    if (vfringe != vheaplimit)
    {   *(Header *)vfringe = make_padding_header(vheaplimit - vfringe);
        clear_header_bits(vfringe, vheaplimit - vfringe, active_page);
    }
// If 2-word and vector regions are one and the same that means that
// there is not enough space in the current page, so I need to allocate
// a new one. There is no guarantee that it will have a large enough
// uninterrupted block of free memory for my vector, but if it does not
// then this function will just get called again.
    if (vheaptop == heapstart)
    {   allocate_next_page();
        return;
    }
// Now I am in the situation where there was some pinned data that blocked
// the allocation I wanted to do. I skip to be beyond it.
    vfringe = vheaptop;
    vheaptop = vheapstart ^ vxor_chain;
    vlen = ((uintptr_t *)vheaptop)[0];
    vxor_chain = ((uintptr_t *)vheaptop)[1];
    vheaplimit = vheaptop - vlen;
    vheapstart = vfringe;
}

// The great majority of allocations are liable to be for CONS or for
// double floats, so modest extra burden when larger (or indeed smaller)
// vectors are allocated can be tolerated. The most obvious excess cost here
// is setting and clearing bitmap information for the identification of
// object start addresses.

inline LispObject get_n_bytes(size_t n)
{
// I may at some stage arrange that I always call this function asking for
// a multiple of 8 bytes, but for now and as a matter of caution I will
// round up.
    n = doubleword_align_up(n);
// If 2-word and vector items are allocated in the same chunk I must
// not allocate on to of the 2-word items. So in that case I will reset
// vheaplimit.
    if (vheaptop == heapstart) vheaplimit = fringe;
// Now check if there is enough space for the vector in the area up as far
// as the next limit. If not then put in a padder and move beyond the pinned
// items. It may be necessary to do this several times if there are pinned
// items with shortish free gaps between them, hence the WHILE loop.
    while (vfringe + n > vheaplimit) get_n_bytes_past_pin();
// Now I have a gap that is big enough. Hoorah!
    LispObject r = vfringe;
    vfringe += n;
// For vectors the bitmap that will record where objects start must be
// updated. The expensive-looking part of this is clearing all the
// bits associated with the interior of the new vector, but I hope that
// a careful implemention of clear_header_bits can do this using word-
// at-a-time operations on the bitmap and hence be respectably fast.
    set_header_bit(r, active_page);
    clear_header_bits(r+8, n-8, active_page);
// Now if 2-word and vector allocations could possibly collide soon set
// the limit register for 2-word allocation to prevent disaster.
    if (vheaptop == heapstart) heaplimit = vfringe;
    return r;
}

// For borrowing I only ever allocate vectors, never CONS cells, and there
// can never be a garbage collection while borrowed space is active,
// and so I do not need to mess with object header flag bits etc, or
// with the issue of pages of memory being split between CONS and vector
// regions. This all really simplifies matters.

static uintptr_t borrowing_vfringe, borrowing_vheaptop, borrowing_vlen,
                 borrowing_vxor_chain, borrowing_vheaplimit,
                 borrowing_vheapstart, borrowing_heapstart;

static void allocate_next_borrowed_page();

static void borrow_n_bytes_past_pin()
{   if (borrowing_vheaptop == borrowing_heapstart)
    {   allocate_next_borrowed_page();
        return;
    }
// Now I am in the situation where there was some pinned data that blocked
// the allocation I wanted to do. I skip to be beyond it.
    borrowing_vfringe = borrowing_vheaptop;
    borrowing_vheaptop = borrowing_vheapstart ^ borrowing_vxor_chain;
    borrowing_vlen = ((uintptr_t *)borrowing_vheaptop)[0];
    borrowing_vxor_chain = ((uintptr_t *)borrowing_vheaptop)[1];
    borrowing_vheaplimit = borrowing_vheaptop - vlen;
    borrowing_vheapstart = borrowing_vfringe;
// I will avoid overwriting the LEN and XOR data. This means that I do not
// use all the potentially available space, but it also means that I do not
// need to perform any reconstruction of free-space maps when I abandon
// the borrowed space.
    borrowing_vfringe += 2*sizeof(uintptr_t);
}

inline LispObject borrow_n_bytes(size_t n)
{   n = doubleword_align_up(n);
    if (borrowing_vheaptop == borrowing_heapstart)
        borrowing_vheaplimit = borrowing_vheapstart;
    while (borrowing_vfringe + n > borrowing_vheaplimit)
        borrow_n_bytes_past_pin();
    LispObject r = borrowing_vfringe;
    borrowing_vfringe += n;
// I do not set (or clear) header bits for borrowed vectors. That is because
// they should never participate in garbage collection, so the issues of
// ambiguous references to them do not arise.
    return r;
}

// Now I have versions of the allocation code that are used while I am in
// the garbage collector evacuating data from the old into the new space.
// I am making this a (modified) copy of the normal allocator for two reasons.
// The first is that for speed reasons I do not want ANY stray tests adding
// overhead to the normal allocator. The second is that this GC version may
// try harder to avoid introducing fragmentation, and that makes it
// deviate noticably from the simpler regular-use code.

static void gc_get_2_words_past_pin()
{   if (vheaptop == heapstart)
    {
        if (SIXTY_FOUR_BIT && fringe == vfringe-CELL)
        {   *(Header *)vfringe = make_padding_header(CELL);
        }
        gc_allocate_next_page();
        return;
    }
    uintptr_t w = heaplimit;
    heaplimit = heapstart ^ xor_chain;
    heapstart = w;
    fringe = w - len;
    if (vheaptop == heapstart)
    {
        heaplimit = vfringe;
        if (SIXTY_FOUR_BIT && fringe == vfringe+CELL)
        {   *(Header *)vfringe = make_padding_header(CELL);
            vfringe += CELL;
            gc_allocate_next_page();
        }
        else if (fringe == vfringe) gc_allocate_next_page();
        return;
    }
    len = ((uintptr_t *)heaplimit)[0];
    xor_chain = ((uintptr_t *)heaplimit)[1];
}

inline LispObject gc_get_2_words()
{
    fringe -= 2*CELL;
    if (fringe < heaplimit) gc_get_2_words_past_pin();
    return fringe;
}

static uintptr_t padders = 0;
static uintptr_t *padders_tail = &padders;

static void gc_get_n_bytes_past_pin()
{
    if (vfringe != vheaplimit)
    {   *(Header *)vfringe = make_padding_header(vheaplimit - vfringe);
// I will collect a chain of all the padders that I create. This will be
// built in historical order. 
        if ((vheaplimit - vfringe) != CELL)
        {    *padders_tail = vfringe;
             padders_tail = &((uintptr_t *)vfringe)[1];
             *padders_tail = 0;
        }
        clear_header_bits(vfringe, vheaplimit - vfringe, active_page);
    }
    if (vheaptop == heapstart)
    {   gc_allocate_next_page();
        return;
    }
    vfringe = vheaptop;
    vheaptop = vheapstart ^ vxor_chain;
    vlen = ((uintptr_t *)vheaptop)[0];
    vxor_chain = ((uintptr_t *)vheaptop)[1];
    vheaplimit = vheaptop - vlen;
    vheapstart = vfringe;
}

inline LispObject gc_get_n_bytes(size_t n)
{
    n = doubleword_align_up(n);
    if (vheaptop == heapstart) vheaplimit = fringe;
    while (vfringe + n > vheaplimit) gc_get_n_bytes_past_pin();
    LispObject r = vfringe;
    vfringe += n;
    set_header_bit(r, active_page);
    clear_header_bits(r+8, n-8, active_page);
    if (vheaptop == heapstart) heaplimit = vfringe;
    return r;
}

// This code sets up an empty page - it is ONLY intended for use at the
// start of a run when there can not be any pinned items present anywhere.
// I put the code here adjacent to the code that allocates from pages so
// that the setup and use can be compared.

static void set_up_empty_page(page_header *p)
{   p->vheapstart = p->vfringe = (uintptr_t)&(p->data[0]);
    p->vheaptop = p->vheaplimit = (uintptr_t)p + CSL_PAGE_SIZE;
    p->len = p->vxor_chain = 0;
    p->heaplimit = p->vfringe;
    p->heapstart = p->fringe = p->vheaplimit;
    p->xor_chain = p->len = 0;
    memset(p->objstart,
        SIXTY_FOUR_BIT ? 0x55 : 0xff,
        PAGE_BITMAP_SIZE);
    memset(p->pinned_bitmap, 0, PAGE_BITMAP_SIZE);
}

void set_variables_from_page(page_header *p)
{
// Set the variable that are used when allocating within the active page.
    vheapstart = p->vheapstart;
    vfringe    = p->vfringe;
    vheaplimit = p->vheaplimit;
    vlen       = p->vlen;
    vheaptop   = p->vheaptop;
    vxor_chain = p->vxor_chain;
    heapstart  = p->heapstart;
    fringe     = p->fringe;
    heaplimit  = p->heaplimit;
    len        = p->len;
    xor_chain  = p->xor_chain;
}

void save_variables_to_page(page_header *p)
{
// Dump global variable values back into a page header.
    p->vheapstart   = vheapstart;
    p->vfringe      = vfringe;   
    p->vheaplimit   = vheaplimit;
    p->vlen         = vlen;      
    p->vheaptop     = vheaptop;  
    p->vxor_chain   = vxor_chain;
    p->heapstart    = heapstart; 
    p->fringe       = fringe;    
    p->heaplimit    = heaplimit; 
    p->len          = len;       
    p->xor_chain    = xor_chain; 
}

void set_next_active_page()
{   printf("set_next_active_page\n");
    if (previous_active_page != NULL)
    {   previous_active_page->page_chain = used_pages;
        used_pages = previous_active_page;
    }
    previous_active_page = active_page;
// Set a new active_page from the chain of free_pages. If that chain is
// empty we are in trouble!
    active_page = free_pages;
    free_pages = free_pages->page_chain;
    active_page->page_type = 0;
    active_page->page_chain = 0;
    set_variables_from_page(active_page);
    printf("Use page at %p: fringe = %p, heaplimit = %p\n",
        active_page, (void *)fringe, (void *)heaplimit);
    active_pages_count++;
    free_pages_count--;
}

static void allocate_next_page()
{   printf("allocate_next_page\n");
    fflush(stdout);
// Here I should often do a minor garbage collection in a generational
// sense. When I have the heap close to half full I should perform
// a full garbage collection.
// But until I have a generational collector in place I mostly just
// grab another page from the pool.
    if (active_pages_count > free_pages_count-1)
    {   printf("Probably need to garbage collect\n");
        my_abort();
    }
    set_next_active_page();
}

void gc_prepare_new_half_space()
{    
}

static void gc_allocate_next_page()
{   printf("GC allocate_next_page\n");
    fflush(stdout);
// This is called from within the garbage collector, so it will expect that
// there is available space. Hypothetically if it happened that the active
// space was all well packed and the free memory was subject to an undue
// number of pinned items and fragmentation one might run out here - that
// would be a fatal situation.
    if (free_pages_count == 0)
    {   printf("Fatal error: memory exhausted\n");
        my_abort();
    }
    set_next_active_page();
}

page_header *free_pages_for_borrowing;

void allocate_next_borrowed_page()
{   
// Borrow a page. If there are none available we are in trouble!
    page_header *p = free_pages_for_borrowing;
    if (p == NULL)
    {   fprintf(stderr, "Run out of space during borrowing\n");
        my_abort();
    }
    free_pages_for_borrowing = free_pages_for_borrowing->page_chain;
// Set the variable that are used when allocating within the active page.
    borrowing_vheapstart = p->vheapstart;
    borrowing_vfringe    = p->vfringe;
    borrowing_vheaplimit = p->vheaplimit;
    borrowing_vlen       = p->vlen;
    borrowing_vheaptop   = p->vheaptop;
    borrowing_vxor_chain = p->vxor_chain;
    borrowing_heapstart  = p->heapstart;
// I only allocate vectors in borrowed space, so the variables listed
// in the commented out lines here are not needed.
//@ borrowing_fringe     = p->fringe;
//@ borrowing_heaplimit  = p->heaplimit;
//@ borrowing_len        = p->len;
//@ borrowing_xor_chain  = p->xor_chain;
}



// This code allocates a segment by asking the operating system. On
// Windows it uses VirtualAlloc() and on other systems mmap().  It arranges
// that heap_segment[] gets updates and that bitmaps for "dirty" pages are
// established.  The collection of segments must be stored in heap_segments[]
// such that their addresses are in ascending order, and in consequence of
// that allocating a new segment may shuffle existing ones in the tables.
// So the index of a segment in the tables may not be viewed as permenant.

void *allocate_segment(size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// system page size. Well I expect that in any sensible calls to
// this function that requested size will already be nicely rounded,
// but this is cheap and adds to safety.
    n = (n + page_size - 1) & -page_size;
    size_t map_size = n/page_size; // number of bits of map needed
// Round up map_size to be a multiple of sizeof(unit64_t)
    map_size = (map_size + sizeof(uint64_t) - 1) / sizeof(uint64_t);
// Where possible I allocate map space within the small bitmap block, working
// down from the top. I leave map_ptr NULL if this is not possible, otherwise
// it identified the location within the block;
    size_t extra = 0;
    uint64_t *map_ptr_1, *map_ptr_2;
    if (map_size >= (size_t)((char *)heap_small_bitmaps_1_ptr -
                             (char *)heap_small_bitmaps_1))
    {   map_ptr_1 = map_ptr_2 = NULL;
// The map will need to go at the end of the newly allocated block... I
// sort out how much space that will use.
        extra = (2*map_size*sizeof(uint64_t) + page_size - 1) & -page_size;
    }
    else
    {   map_ptr_1 = (uint64_t *)((char *)heap_small_bitmaps_1_ptr - map_size);
        map_ptr_2 = (uint64_t *)((char *)heap_small_bitmaps_2_ptr - map_size);
    }
#ifdef WIN32
// This will allocate a block that is aligned at least at a page boundary
// well it will tends to be aligned even more than just that). The memory
// will be readable and writable, but has the Windows special attribute
// WRITE_WATCH that means that I can enquire about pages that have been
// written to. This does almost all of the work I need for my write barrier.
    void *r = VirtualAlloc(NULL, n+extra,
                           MEM_RESERVE|MEM_COMMIT|MEM_WRITE_WATCH,
                           PAGE_READWRITE);
    bool failed = (r == NULL);
#else // !WIN32
// On Linux, BSD, Macintosh, Unix etc I will use mmap. If MAP_ANONYMOUS
// is defined I will use it, in the fall-back case I will open /dev/zero
// every time. Well in the context I am imagining here I will at most
// call this function 32 times during a run, so that is not too bad.
// Observe that I map the memory read-only so that when anybody tries to
// write to it they get e SIGSEGV (or SIGBUS on some systems!). The
// handler for that will update the magic bitmap. In each case the new
// block of memory is initializer to zero - in particular this means that
// if the bitmap for it lies within it that will be zero.
#ifdef MAP_ANONYMOUS
    void *r = mmap(0, n+extra,
                   PROT_READ|PROT_WRITE,
                   MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    bool failed = (r == MAP_FAILED);
#else // !MAP_ANONYMOUS
    int fd = open("/dev/zero", O_RDWR);
    void *r = mmap(0, n+extra,
                   PROT_READ|PROT_WRITE,
                   MAP_PRIVATE, fd, 0);
    bool failed = (r == MAP_FAILED);
    close(fd);
#endif // !MAP_ANONYMOUS
#endif // !WIN32
    if (failed) return NULL;
    if (map_ptr_1 != NULL) heap_small_bitmaps_1_ptr = map_ptr_1;
    else map_ptr_1 = (uint64_t*)((char *)r + n);
    heap_segment[heap_segment_count] = r;
    heap_dirty_pages_bitmap_1[heap_segment_count] = map_ptr_1;
    if (map_ptr_2 != NULL) heap_small_bitmaps_2_ptr = map_ptr_2;
    else map_ptr_2 = (uint64_t*)((char *)r + n + extra/2);
    heap_dirty_pages_bitmap_2[heap_segment_count] = map_ptr_2;
// Note that the recorded size here does not include any appended bitmap.
    heap_segment_size[heap_segment_count] = n;
    heap_segment_total_size[heap_segment_count] = n + extra;
    heap_segment_count++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (size_t i=heap_segment_count-1; i!=0; i--)
    {   int j = i-1;
        void *h1 = heap_segment[i], *h2 = heap_segment[j];
        if ((uintptr_t)h2 < (uintptr_t)h1) break; // Ordering is OK
// The segment must sink a place in the tables.
        heap_segment[i] = h2; heap_segment[j] = h1;
        h1 = heap_dirty_pages_bitmap_1[i]; h2 = heap_dirty_pages_bitmap_1[j];
        heap_dirty_pages_bitmap_1[i] = (uint64_t *)h2;
        heap_dirty_pages_bitmap_1[j] = (uint64_t *)h1;
        h1 = heap_dirty_pages_bitmap_2[i]; h2 = heap_dirty_pages_bitmap_2[j];
        heap_dirty_pages_bitmap_2[i] = (uint64_t *)h2;
        heap_dirty_pages_bitmap_2[j] = (uint64_t *)h1;
        size_t w = heap_segment_size[i];
        heap_segment_size[i] = heap_segment_size[j];
        heap_segment_size[j] = w;
    }
// r now refers to a new segment of size n, I want to structure it into
// pages.
    free_pages_count = active_pages_count = 0;
    for (size_t k=0; k<n; k+=CSL_PAGE_SIZE)
    {   page_header *p = (page_header *)((char *)r + k);
// I do not even know if I really need a page_type field!
        p->page_type = 0; // ????
// Keep a chain of all the pages.
        p->page_chain = free_pages;
        free_pages = p;
        set_up_empty_page(p);
        free_pages_count++;
    }
    printf("%" PRIu64 " pages available\n", (uint64_t)free_pages_count);
    return r;
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

LispObject cons(LispObject a, LispObject b)
{   LispObject r = get_2_words() + TAG_CONS;
    qcar(r) = a;
    qcdr(r) = b;
    return r;
}

// With the conservative collector I maybe do not need to avoid garbage
// collection on any particular individual uses of cons().

LispObject cons_no_gc(LispObject a, LispObject b)
{   return cons(a, b);
}

LispObject cons_gc_test(LispObject p)
{   return p;
}

LispObject ncons(LispObject a)
{   LispObject r = get_2_words() + TAG_CONS;
    qcar(r) = a;
    qcdr(r) = nil;
    return r;
}

// Here I can wonder if there is a good way to save overhead by allocating
// both cells as one operation...

LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = nil;
    return r1;
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcdr(r1) = r2;
    qcdr(r2) = c;
    return r1;
}

LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    LispObject r3 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = d;
    return r1;
}

LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    LispObject r3 = get_2_words() + TAG_CONS;
    LispObject r4 = get_2_words() + TAG_CONS;
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



LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    qcar(r1) = r2;
    qcar(r2) = a;
    qcdr(r1) = c;
    qcdr(r2) = b;
    return r1;
}

LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   return acons(a, b, c);
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    LispObject r3 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get_2_words() + TAG_CONS;
    LispObject r2 = get_2_words() + TAG_CONS;
    LispObject r3 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcar(r2) = b;
    qcar(r3) = c;
    qcdr(r1) = r2;
    qcdr(r2) = r3;
    qcdr(r3) = nil;
    return r1;
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_2_words() + TAG_CONS;
    qcar(r1) = a;
    qcdr(r1) = b;
    return onevalue(r1);
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get_2_words() + TAG_CONS;
    qcar(r1) = b;
    qcdr(r1) = a;
    return onevalue(r1);
}

LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get_2_words() + TAG_CONS;
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
//@@    for (;;)
    {   size_t alloc_size = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
        if (alloc_size > (CSL_PAGE_SIZE - 32))
            aerror1("request for basic vector too big",
                    fixnum_of_int(alloc_size/CELL-1));
//@@        if (++reclaim_trigger_count == reclaim_trigger_target ||
//@@            alloc_size > free || vec_forced(alloc_size/CELL))
//@@        {   char msg[40];
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
//@@            switch (tag)
//@@            {   case TAG_SYMBOL:
//@@                    sprintf(msg, "symbol header");
//@@                    break;
//@@                case TAG_NUMBERS:
//@@                    switch (type)
//@@                    {   case TYPE_BIGNUM:
//@@                            sprintf(msg, "bignum(%ld)", (long)size);
//@@                            break;
//@@                        default:
//@@                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
//@@                            break;
//@@                    }
//@@                    break;
//@@                case TAG_VECTOR:
//@@                    switch (type)
//@@                    {
//@@                        case TYPE_STRING_1:
//@@                        case TYPE_STRING_2:
//@@                        case TYPE_STRING_3:
//@@                        case TYPE_STRING_4:
//@@                            sprintf(msg, "string(%ld)", (long)size);
//@@                            break;
//@@                        case TYPE_BPS_1:
//@@                        case TYPE_BPS_2:
//@@                        case TYPE_BPS_3:
//@@                        case TYPE_BPS_4:
//@@                            sprintf(msg, "BPS(%ld)", (long)size);
//@@                            break;
//@@                        case TYPE_SIMPLE_VEC:
//@@                            sprintf(msg, "simple vector(%ld)", (long)size);
//@@                            break;
//@@                        case TYPE_HASH:
//@@                            sprintf(msg, "hash table(%ld)", (long)size);
//@@                            break;
//@@                        default:
//@@                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
//@@                            break;
//@@                    }
//@@                    break;
//@@                case TAG_BOXFLOAT:
//@@                    sprintf(msg, "float(%ld)", (long)size);
//@@                    break;
//@@                default:
//@@                    sprintf(msg, "get_basic_vector(%lx,%ld)", (long)tag, (long)size);
//@@                    break;
//@@            }
//@@            reclaim(nil, msg, GC_VEC, alloc_size);
// Note the CONTINUE here so that I go and repeat the test. Consider the
// case where I have a page almost full but then garbage collection recovers
// a lot of space but still leaves the final used page almost full... I
// need the garbage collector to take care with its final argument to be
// certain that the loop here terminates!
//@@            continue;
//@@        }
        LispObject r = get_n_bytes(alloc_size);
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
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(r+alloc_size-CELL) = 0;
        return (LispObject)(r + tag);
    }
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors.

LispObject reduce_basic_vector_size(LispObject v, size_t len)
{   vechdr(v) = TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED;
    return v;
}

// The next functions (eg borrow_vector) are called just like the
// functions that allocate new vectors, but they use space in the part
// of memory space not at present in use by the garbage collector. If a
// copying garbage collection triggered "right now" were to be able to
// succeed there must be enough reserved space to make this possible provided
// I only borrow space sufficient to make copies of existing live data.
// One must NEVER garbage collect while space has been borrowed in this
// way. At present this scheme is only ever used while rehashing hash
// tables.
//
// This is implemented by saving the state of the current active page,
// starting allocation afresh in a new page, arranging that allocating more
// than kalf the available pages will not trigger a garbage collection, and
// in an ephemeral world arranging that filling each page just leads to
// allocation of a new one rather than a minor collection. Then the perfectly
// regular version of the allocation functions (eg get_n_bytes and hence
// get_basic_vector and get_vector) will allocate in these new temporary
// pages. At the end of "borrowing" the pages so allocated need to be
// returned to the pool of available pages. The messiest issue about that
// is that the internal maps showing where there are pinned items must be
// recreated. For this to be possible I am going to insist that where there
// are pinned blocks in the middle of pages that the bitmap entries that show
// where they are get retained. At one time I had thought I might tidy up the
// maps of pinned locations at the end of garbage collection - to support
// borrowing I have to do it at the start.


void prepare_for_borrowing()
{   free_pages_for_borrowing = free_pages;
    allocate_next_borrowed_page();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   size_t alloc_size = (size_t)doubleword_align_up(size);
    if (alloc_size > (CSL_PAGE_SIZE - 32))
        aerror1("request for basic vector too big",
                fixnum_of_int(alloc_size/CELL-1));
    LispObject r = borrow_n_bytes(alloc_size);
    *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
    if (!SIXTY_FOUR_BIT && alloc_size != size)
        *(LispObject *)(r+alloc_size-CELL) = 0;
    return (LispObject)(r + tag);
}

// This code is significantly simplified as compared with get_vector for
// at least two reasons. Firstly while borrowing I will NEVER garbage collect,
// and so I do not need to initialize the vector to safe values. Secondly
// I will not use the vector-cache scheme that the full version uses.

LispObject borrow_vector(int tag, int type, size_t n)
{   if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
        LispObject v =
            borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (size_t i=0; i<chunks; i++)
        {   size_t k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
            basic_elt(v, i) = borrow_basic_vector(tag, type, k+CELL);
        }
        return v;
    }
    else return borrow_basic_vector(tag, type, n);
}



// Now I want to think about the implementation of the copying garbage
// collector. For that I will want to allocate copies of material in
// what might be called the "new space". Well in fact it is nothing very
// special in terms of half-spaces, it is just pages of memory not currently
// occupied. So the allocation can be just the usual version, save that
// it must arrange that it never triggers a further garbage collection even
// though it is using up memory pages right up to te wire.
// There is a potential for fragmentation, especially in the presence of
// pinned items. As a result the allocator will sometimes insert a padder
// vector so that memory can be scanned linearly in a neat way.
// I will chain those padder vectors together keeping them in sequential
// order. When I need to allocate I will sometimes take space from this
// padder chain.
// If I find space within a padder chunk I will use the memory at
// its low address and adjust things so that the padder shrinks upwards.
// There will be two circumstanmces when I remove a padder block from the
// chain of spare space: one is when allocation from within it reduces its
// size to just 1 word or fills it up completely. The other is when the
// linear scan part of the GC reaches it. The idea behind the second of those
// conditions is that I will need to visit all evacuated data so that I
// either deal with forwarding addresses associated with it or do further
// evacuation. Doing that in a single linear pass over the new heap is the
// sanest strategy.
// My current thought (but note that my ideas in this respect have been
// wavering rather a lot!) is that I will allocate vector blocks in a
// really simple way, but for allocating new CONS cells I will fill in parts
// of padder blocks in preference to allocating genuinly new memory. My
// expectation is that in most Lisp use-cases the number of CONS cells will
// greatly exceed the number of vectors and that this strategy will fill up
// otherwise wasted padder space pretty effectively. If it does not then I
// may need to use a first-fit strategy for vector allocation.

// Here are the allocation functions implementing the above.


inline LispObject packed_get_2_words()
{
// No use of padder space yet!
    return gc_get_2_words();
}

inline LispObject packed_get_n_bytes(size_t n)
{
// No use of padder space yet!
    return gc_get_n_bytes(n);
}

void major_garbage_collect()
{
// (1) Clear pinned map for R and S.


// (2) Scan ambiguous bases, marking items referred to in R or S as pinned.
//     Build a table of the pinned items first using the pinned-table and if
//     that overflows building a linked list in pages from F.
//     If there had been a list of pinned items left in S by the previous
//     collection then scan down it clearing any pinned bits on its entries,
//     because that data is now not needed.


// (3) Scan unambiguous bases and pointers out of C relocating anything except
//     references into C or to things that are pinned. This copies material to
//     new pages in F.


// (4) Scan the new material in F much as step (4) in the minor case.


// (5) Using information about pinned data in the table and any overflow list
//     build up freespace tables/maps/chains in all the blocks from S.
// (6) Swap interpretation of S and F, and allocate a new empty block for R
//     (which in step 7 of the minor GC will then instantly become the new C).
// (7) Consider dirty bits. What is needed is to mark any segment of memory
//     containing a reference to C as dirty, and all others as clean. I rather
//     hope to be able to build up that information as part of steps (3) and
//     (4) since they already need to test for references into C.

}


uintptr_t *C_stackbase;

extern void middle_reclaim();
extern void inner_reclaim(uintptr_t *sp);

// The next section of code represents an attempt to coax "reasonable"
// compilers into arranging that all registers that had been in use when
// reclaim() is called end up somewhere on the stack by the time that
// inner_reclaim() is entered. It is pretty clear that this is not the
// sort of thing that fully guaranteed portable code can achieve! I apply
// two ideas. The first is to have a function that is liable to want to
// keep a dozen value in its registers - and to do that it is liable to
// flush calee-save ones to the stack. I use the "register" qualifier
// to try to advise the compiler to do what I want, but modern compilers
// probably ignore me, so may not. As a secoondary attempt I use setjmp()
// which I hope and expect dumps a copy of all useful machine registers into
// the given jmp_buf. Again this is not guaranteed!
// The use of volatile_variable is a further attempt to prevent any
// clever compiler frm observing that all that I do is frivolous and
// then discarding it.

volatile int volatile_variable = 12345;

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
    register int a1 = volatile_variable;
// The declarations here go one at a time to stress the sequential nature
// of the references to volatile_variable.
    register int a2 = volatile_variable;
    register int a3 = volatile_variable;
    register int a4 = volatile_variable;
    register int a5 = volatile_variable;
    register int a6 = volatile_variable;
    register int a7 = volatile_variable;
    register int a8 = volatile_variable;
    register int a9 = volatile_variable;
    register int a10 = volatile_variable;
    register int a11 = volatile_variable;
    register int a12 = volatile_variable;
// Even with a heavily optimising compiler the above ought to generate
// 12 loads from the volatile_variable because in principle the values so
// loaded could all be different.
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
        if (volatile_variable == volatile_variable) return;
// The longjmp here will never be taken, but the compiler is not allowed to
// assume that! Therefore it must keep jb on alive on the stack during the
// call to middle_reclaim().
        if (volatile_variable != volatile_variable) longjmp(jb, 1);
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

// It gives me a certain amount of pause when I wonder what types the
// arguments to some of these functions should have. Here I have an
// "ambiguous pointer" v, and I will pass that as a uintptr_t, but if I
// find that it can be interpreted as a reference within the body of a
// valid Lisp Object I will return a tagged pointer if the form of a
// LispObject. I will return zero if the address passed is not satisfactory.

inline LispObject find_object_start(uintptr_t v, page_header *p)
{
// v is expected to be double-CELL aligned on entry, and what is returned
// will be a proper tagged object.
// I will code this CRUDELY to start with.
    uintptr_t v1 = v;
// I will scan downwards in memory until I find a doubleword that is
// marked as being the start of an object. If the page is not empty then
// there will always be an object present at its start, and so this
// loop will terminate. If the page was empty then the putative pointer
// into it would have been rejected. So the loop here is safe.
// At present I have coded this scanning down one unit at a time, but I
// will be able to scan down through the bitmap up to 64 steps per go by
// using word-at-a-time operations and probably a "find first set bit"
// operation. That would speed this up in an interesting manner.
    v1 &= -(uintptr_t)(2*CELL);
    while (!is_header_address((Header *)v1, p)) v1 -= 2*CELL;
    Header h = *(Header *)v1;
// Now the item referenced is one of the following:
//  A CONS, with a non-header value in h
//  A padder vector.
//  A symbol
//  A genuine vector
    if (is_symbol_header_full_test(h))
    {   if (v1 > v+symhdr_length) return 0;
        return (LispObject)(TAG_SYMBOL+v);
    }
    else if (is_vector_header_full_test(h))
    {
// This requires that a pointer to be within the active data region of a
// vector to be accepted, except that for bit-vectors, byte and halfword
// vectors pointers within the final 32-bit word of useful data will
// be treated as pointing "within" the vector. I also deem the pointer
// invalid if it is to within a padder object.
        if (v1 > v+length_of_header(h) ||
            type_of_header(h) == TYPE_PADDER) return 0;

// Both vectors and those numeric types that are stored with a header
// will be returned as with TAG_VECTOR here. So for instance double-floats
// and bignums are returned with dodgy tags, but for the purposes here that
// really does not matter!
        return (LispObject)(TAG_VECTOR+v);
    }
    else
    {   if (v1 > v+2*CELL) return 0;
        return (LispObject)(TAG_CONS+v);
    }
}


void inner_reclaim(uintptr_t *sp)
{
// (1) Clear pinned map for R and S.
//     [Well I am at least for now going to suppose that that had been
//     done as part of the final stage of the previous garbage collection,
//     so I do not have anything to do here.]
// (2) Scan ambiguous bases, marking items referred to in R or S as pinned.
//     Build a table of the pinned items first using the pinned-table and if
//     that overflows building a linked list in pages from F.
//     If there had been a list of pinned items left in S by the previous
//     collection then scan down it clearing any pinned bits on its entries,
//     because that data is now not needed.
    for (uintptr_t *s=sp; s<C_stackbase; s++)
    {   uintptr_t v = *s;   // Possibly a valid pointer!
        int h = find_heap_segment((uintptr_t)v);
        if (h < 0) continue;
// Here the ambiguous pointer at least lies within one of the regions of
// memory that I had set aside for the heap.
        void *seg = heap_segment[h];
// Now I know which memory segment the potential pointer was within. The
// segment was divided up into pages each of size CSL_PAGE_SIZE so I can now
// sort out which of those is involved.
        uintptr_t off = (char *)v - (char *)seg;
        uintptr_t pagenum = off/CSL_PAGE_SIZE;
        page_header *p = (page_header *)((char *)seg + CSL_PAGE_SIZE*pagenum);
// Now p points to the start of a page that the pointer seems to address.
// References into the "current" page will not be treated as cause for
// pinning. That is because I expect that there will be quite a few references
// into that page on the stack and that would lead to many pinned items.
//
        if (p == active_page) continue;
// Reject it if the "pointer" is into the page header...
        if ((char *)v < (char *)&p->data) continue;
// ... and also if it is beyond all live data in the page.
        if ((char *)v >= (char *)p->fringe) continue;
// Now my potential pointer is to within a region that holds live data. If it
// points within a Lisp value then find a tagged pointer to that as a more
// or less valid LispObject.
        v = find_object_start(v, p);
// In unusual cases the pointer might not actually point within valid data.
// This can only arise if there are gaps in the data.
        if (v == 0) continue;
// Now v is a sort of honest reference to an item that must be pinned.

// <PIN IT HERE>

    }
// (3) Scan unambiguous bases and pointers out of C relocating anything except
//     references into C or to things that are pinned. This copies material to
//     new pages in F.
// (4) Scan the new material in F much as step (4) in the minor case.
// (5) Using information about pinned data in the table and any overflow list
//     build up freespace tables/maps/chains in all the blocks from S.
// (6) Swap interpretation of S and F, and allocate a new empty block for R
//     (which in step 7 of the minor GC will then instantly become the new C).
// (7) Consider dirty bits. What is needed is to mark any segment of memory
//     containing a reference to C as dirty, and all others as clean. I rather
//     hope to be able to build up that information as part of steps (3) and
//     (4) since they already need to test for references into C.




}

void garbage_collect()
{   printf("NOT IMPLEMENTED YET\n");
    abort();
}

void init_heap_segments(double store_size)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
//
{   get_page_size();
// I will make the default initial store size around 64M on a 64-bit
// machine and 512M on a 64-bit system. If the user specified a "-K" option
// they can override this, and also the system will tend to allocate more
// space (if it can) when its memory starts to get full.
    size_t free_space = (SIXTY_FOUR_BIT ? 512 : 64)*1024*1024;
    size_t request = (size_t)store_size;
    if (request != 0) free_space = 1024*request;
// Now free_space is the amount I want to allocate. I will explicitly
// set the variables that are associated with tracking memory allocation
// to keep everything as clear as I can.
    heap_segment_count = 0;
    heap_small_bitmaps_1_ptr = &heap_small_bitmaps_1[SMALL_BITMAP_SIZE];
    heap_small_bitmaps_2_ptr = &heap_small_bitmaps_2[SMALL_BITMAP_SIZE];
    spin_lock.clear(); //"spin_lock=ATOMIC_FLAG_INIT;" only for initialization.
    free_pages = used_pages = active_page = previous_active_page = NULL;
    printf("Allocate %" PRIu64 " Kbytes\n", (uint64_t)free_space/1024);
    allocate_segment(free_space);
    set_next_active_page();

// There are other bits of memory that I will grab manually for now...
    nilsegment = (LispObject *)aligned_malloc(NIL_SEGMENT_SIZE+16);
#ifdef COMMON
    nil = (LispObject)((uintptr_t)nilsegment + TAG_CONS + 8);
#else
    nil = (LispObject)((uintptr_t)nilsegment + TAG_SYMBOL);
#endif
    stacksegment = (LispObject *)alligned_malloc(CSL_PAGE_SIZE);
    if (stacksegment == NULL) fatal_error(err_no_store);
    stackbase = (LispObject *)stacksegment;
}

void drop_heap_segments(void)
{   for (size_t i=0; i<heap_segment_count; i++)
    {   void *p = heap_segment[i];
#ifdef WIN32
        if (VirtualFree(p, heap_segment_total_size[i], MEM_RELEASE) == 0)
        {   // Failed to release the memory. Ignore the error!!!
        }
#else
        if (munmap(p, heap_segment_total_size[i]) != 0)
        {   // Failed to release the memory. Ignore the error!!!
        }
#endif
    }
    aligned_free(nilsegment);
    aligned_free(stacksegment);
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
    {   pages[pages_count++] = page;
        return true;
    }
}

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
    {   size_t ideal = ok_to_grab_memory(heap_pages_count + vheap_pages_count);
        size_t more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (max_store_size != 0.0)
        {   double page_limit = max_store_size*1024*1024/(double)CSL_PAGE_SIZE;
// Limit memory to (about) the amount the user indicated with --max-mem
            size_t plim = (size_t)page_limit;
            if (ideal > plim) ideal = plim;
        }
        if (ideal > pages_count)
        {   more = ideal - pages_count;
            while (more > 0)
            {   if (!allocate_more_memory()) break;
                more--;
            }
        }
    }
}


// @@@@@

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
    return reclaim(nil, "user request",
                   a != nil ? GC_USER_HARD : GC_USER_SOFT, 0);
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

static size_t trailing_heap_pages_count,
              trailing_vheap_pages_count;

// copy_one_object() takes the address of a location that contains a
// LispObject. If that LispObject is immediate data it leaves it alone.
// Otherwise it must be a reference to an object in memory. If that object
// is being visited for the first time a copy is made of it

static void copy_one_object(LispObject *p)
{   LispObject a = *p;
    LispObject fr;
// "nil" is never relocated and it is referenced often enough that making it
// a special case here seems reasonable.
    if (a == nil) return;
    else if (is_immed_or_cons(a))
    {   if (is_cons(a))
        {   LispObject w = qcar(a);
            if (is_forward(w)) *p = w - TAG_FORWARD + TAG_CONS;
            else
            {   fr = packed_get_2_words() + TAG_CONS;
                cons_cells += 2*CELL;
                qcar(fr) = w;
                qcdr(fr) = qcdr(a);
                *p = w = (LispObject)fr;
                qcar(a) = w + TAG_FORWARD;
            }
        }
    }
    else                    // Here I have a symbol or vector
    {   int tag = ((int)a) & TAG_BITS;
        a = (LispObject)((char *)a - tag);
        Header h = *(Header *)a;
        size_t len;
// If the symbol/number/vector has already been copied then its header
// word contains a forwarding address. Re-tag it.
        if (is_forward(h)) *p = h - TAG_FORWARD + tag;
        else
        {   if (tag == TAG_SYMBOL)
            {   len = symhdr_length;
                symbol_heads += symhdr_length;
            }
            else
            {
// length_of_header gives me the length in bytes, including the length
// of the header word and of any padding. Hmmm bit-vectors, byte-vectors
// (eg strings) and halfword vectors have a bit of a fudge in the way that
// their length is encoded, and so I will need to review that and confirm
// that all is safe! Yes - if you go length_of_header() on a string (or one
// of the other cases where tha actual data is short) then the result you
// get is the length in bytes of the data padded out to be a multiple of 4
// bytes long.
                len = doubleword_align_up(length_of_header(h));
                my_assert(len >= CELL,
                    [&]{ trace_printf("\nlen = %" PRIx64 " < CELL\n", len);
                         for (int i=-30; i<=30; i++)
                         { LispObject q = ((LispObject *)a)[i];
                           trace_printf("%3d: %" PRIx64, i, q);
                           if (is_odds(q) && is_header(q))
                              trace_printf(" len=%" PRId64, length_of_header(q));
                           trace_printf("\n");
                         }
                       });
// When the garbage collector copies a hash table it changes the type from
// HASH to HASHX. That signals that the table may now be in need of re-hashing.
// That re-hashing is not actually done until or unless somebody makes use
// of the table, and when it is complete the table is reset to type HASH.
                if (type_of_header(h) == TYPE_HASH)
                    h = h ^ (TYPE_HASH ^ TYPE_HASHX);
// Collect some statistics about the amounts of space consumed by various
// sorts of data.
                switch (type_of_header(h))
                {
                    case TYPE_STRING_1:
                    case TYPE_STRING_2:
                    case TYPE_STRING_3:
                    case TYPE_STRING_4:
                        strings += len; break;
                    case TYPE_BIGNUM:
                        big_numbers += len; break;
                    case TYPE_SINGLE_FLOAT:
                    case TYPE_LONG_FLOAT:
                    case TYPE_DOUBLE_FLOAT:
                        box_floats += len; break;
                    case TYPE_SIMPLE_VEC:
                        user_vectors += len; break;
                    default:
                        other_mem += len; break;
                }
            }
            uintptr_t vfr = packed_get_n_bytes(len);
            *p = (LispObject)(vfr + tag);
            *(LispObject *)a = (LispObject)(vfr + TAG_FORWARD);
            *(Header *)vfr = h;
// I copy EVERYTHING from the old vector to the new one. By using memcpy
// I can do so with no worry about strict aliasing or the exact type of
// data present. So this will copy across any padder words.
            memcpy((char *)vfr+CELL, (char *)a+CELL, len-CELL);
        }
    }
}

static void copy(LispObject *p)
// This copies the object pointed at by p from the old to the new semi-space,
// and returns a copy to the pointer.  If scans the copied material to copy
// all relevent sub-structures to the new semi-space.
{   void *p1;
// I will need to scan the material that has been evacuated so as to
// update its contents. I have not got that side of things implemented yet!
#define CONT           0
#define DONE_CAR      -1
#define DONE_VALUE    -2
#define DONE_ENV      -3
#define DONE_PNAME    -4
#define DONE_PLIST    -5
#define DONE_FASTGETS -6
    int next = CONT;
    char *tr=NULL;
// The code here is a simulation of multiple procedure calls to the
// code that copies a single object.  What might otherwise have been
// a "return address" in the calls is handled by the variable "next" which
// takes positive values while copying vectors, and negative ones in
// the more common cases. I use "for (;;)" blocks a lot so that I can
// use "break" and "continue" to leap around in the code - maybe I
// would do better to be honest and use regular labels and "goto"
// statements.
    for (;;)
    {
// Copy one object, pointed at by p, from the old semi-space into the new
// one.
        copy_one_object(p);
// Now I have copied one object - the next thing to do is to scan to see
// if any further items are in the new space, and if so I will copy
// their offspring.
        for (;;)
        {   switch (next)
            {   case CONT:
                    if (tr_fr != fr)
                    {   tr_fr = tr_fr - sizeof(Cons_Cell);
                        if (qcar(tr_fr) == SPID_GCMARK)
                        {   char *w;
                            p1 = new_heap_pages[trailing_heap_pages_count++];
                            w = (char *)p1;
                            tr_fr = w + (CSL_PAGE_SIZE - sizeof(Cons_Cell));
                        }
                        next = DONE_CAR;
                        p = &qcar(tr_fr);
                        break;              // Takes me to the outer loop
                    }
                    else if (tr_vfr != vfr)
                    {   Header h;
                        h = *(Header *)tr_vfr;
                        if (h == 0)
                        {   char *w;
// The next word in the vector heap being a zero where a header was expected
// marks the end of data in this page of heap, so I will move on to the next
// one.
                            p1 = new_vheap_pages[trailing_vheap_pages_count++];
                            w = (char *)p1;
                            tr_vfr = w + 8;
                            h = *(Header *)tr_vfr;
                        }
                        if (is_symbol_header(h))
                        {   next = DONE_VALUE;
                            p = &(((Symbol_Head *)tr_vfr)->value);
                            break;
                        }
                        else
                        {   size_t len = length_of_header(h);
                            tr = tr_vfr;
                            tr_vfr = tr_vfr + doubleword_align_up(len);
                            if (len == CELL)
                            {
// Empty vectors should be treated as if they contained binary, because they
// certainly do not contain any pointers.
                                continue;
                            }
                            switch (type_of_header(h))
                            {   case TYPE_SINGLE_FLOAT:
                                case TYPE_LONG_FLOAT:
                                case TYPE_DOUBLE_FLOAT:
                                case TYPE_BIGNUM:
                                    continue;
                                case TYPE_MIXED1: case TYPE_MIXED2:
                                case TYPE_MIXED3: case TYPE_STREAM:
                                    next = 2*CELL;
                                    break;
// There is a slight delight here. The test "vector_holds_binary" is only
// applicable if the header to be checked is a header of a genuine vector,
// ie something that would have TAG_VECTOR in the pointer to it. But here
// various numeric data types also live in the vector heap, so I need to
// separate them out explicitly. The switch block here does slightly more than
// it actually HAS to, since the vector_holds_binary test would happen to
// deal with several of the numeric types "by accident", but I feel that
// the security of listing them as separate cases is more important than the
// minor speed-up that might come from exploiting such marginal behaviour.
                                default:
                                    if (vector_holds_binary(h)) continue;
                                    // drop through on simple vectors, hash
                                    // tables etc etc. In general anything
                                    // that contains Lisp pointers.
                                case TYPE_RATNUM:
                                case TYPE_COMPLEX_NUM:
// Here I have a vector containing Lisp pointers. len gives its length
// including its header, so the final active data is at tr+len-CELL.
// I want to set next to indicate the offset of the item to be processed
// after I have dealt with that one, and that is len-2*CELL. Note that if
// the vector only held one pointer then len would have been just 2*CELL
// and this would ends up as zero - the correct value to indicate the
// end of processing a vector.
                                    next = len - 2*CELL;
                                    break;
                            }
                            p = (LispObject *)(tr + next + CELL);
                            break;
                        }
                    }
                    else
                    {   fringe = (LispObject)fr;
                        vfringe = (LispObject)vfr;
                        return;        // Final exit when all has been copied
                    }
                case DONE_CAR:
                    next = CONT;
                    p = &qcdr(tr_fr);
                    break;
                case DONE_VALUE:
                    next = DONE_ENV;
                    p = &(((Symbol_Head *)tr_vfr)->env);
                    break;
                case DONE_ENV:
                    next = DONE_FASTGETS;
                    p = &(((Symbol_Head *)tr_vfr)->fastgets);
                    break;
                case DONE_FASTGETS:
                    next = DONE_PNAME;
                    p = &(((Symbol_Head *)tr_vfr)->pname);
                    break;
                case DONE_PNAME:
                    next = DONE_PLIST;
                    p = &(((Symbol_Head *)tr_vfr)->plist);
                    break;
                case DONE_PLIST:
                    next = CONT;
                    p = &(((Symbol_Head *)tr_vfr)->package);
                    tr_vfr = tr_vfr + symhdr_length;
                    break;
                default:
// This will be the case when next is positive, in which case it is an
// offser from tr into a vector. It gets decreased as one goes and
// eventually ends up at zero (which is otherwise known as CONT) at
// which stage the vector has been fully processed and the next item
// to be scanned will be identified.
                    p = (LispObject *)(tr + next);
                    next -= CELL;
                    break;
            }
            break;
        }
    }
}

static bool reset_limit_registers(size_t vheap_need, bool stack_flag)
// returns true if after resetting the limit registers there was
// enough space left for me to proceed. Return false on failure, ie
// need for a more genuine GC.
{   void *p;
    bool full = false;
// I wonder about the next test - memory would only really be full
// if there was enough LIVE data to fill all the available free pages,
// but what is tested here is based on the possibility that all the
// active pages are totally full. I scale up the vector page counts by
// a factor of 1.5 because fragmentation might behave differently in the
// old and new spaces so if there are some large vectors they may leave
// nasty gaps at the end of a page.
//
    size_t len = (char *)vheaplimit - (char *)vfringe;
// If I get here during system start-up I will try to give myself some
// more memory. I expect that will usually be possible!
    if (!garbage_collection_permitted)
    {   if (fringe <= heaplimit && pages_count == 0)
            full = !allocate_more_memory();
        if (vheap_need > len && pages_count == 0)
        {   if (!allocate_more_memory()) full = true;
        }
    }
    else full = (pages_count <=
        heap_pages_count + (3*vheap_pages_count + 1)/2);
    if (fringe <= heaplimit)
    {   if (full) return false;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        heap_pages[heap_pages_count++] = p;
        heaplimit = (intptr_t)p;
        fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
        heaplimit = (LispObject)((char *)heaplimit + SPARE);
    }
    if (vheap_need > len)
    {   char *vf, *vh;
        if (full) return false;
        p = pages[--pages_count];
        space_now++;
        zero_out(p);
        vheap_pages[vheap_pages_count++] = p;
        vf = (char *)p + 8;
        vfringe = (LispObject)vf;
        vh = vf + (CSL_PAGE_SIZE - 16);
        vheaplimit = (LispObject)vh;
    }
    if (stack_flag) return (stack < stacklimit);
    else return true;
}

bool force_verbos = false;

static void report_at_end()
{   int n = heap_pages_count + vheap_pages_count;
    int n1 = n + pages_count;
    double fn = (double)n*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double fn1 = (double)n1*(CSL_PAGE_SIZE/(1024.0*1024.0));
    double z = (100.0*n)/n1;
#ifdef WINDOW_SYSTEM
    {   report_space(gc_number, z, fn1);
        if (verbos_flag & 1 || force_verbos) trace_printf(
                "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
                fn, fn1, z);
    }
#else // WINDOW_SYSTEM
    if (verbos_flag & 1 || force_verbos)
    {   trace_printf(
            "At gc end about %.1f Mbytes of %.1f (%.1f%%) of heap is in use\n",
            fn, fn1, z);
    }
#endif // WINDOW_SYSTEM
// This reports in Kbytes, and does not overflow until over 100 Gbytes
    qvalue(used_space) = fixnum_of_int((int)(1024.0*fn));
    qvalue(avail_space) = fixnum_of_int((int)(1024.0*fn1));
}

LispObject use_gchook(LispObject p, LispObject arg)
{   LispObject g = gchook;
    if (symbolp(g) && g != unset_var)
    {   g = qvalue(g);
        if (symbolp(g) && g != unset_var && g != nil)
        {   class save_trapcount
            {   uint64_t count, target;
                public:
                save_trapcount()
                {   count = reclaim_trigger_count;
                    target = reclaim_trigger_target;
                    reclaim_trigger_target = 0;
                }
                ~save_trapcount()
                {   reclaim_trigger_count = count;
                    reclaim_trigger_target = target;
                }
            } RAII_trapcount;
            push(p);
            Lapply1(nil, g, arg);  // Call the hook
            pop(p);
        }
    }
    return onevalue(p);
}

static double prev_consolidated = 0.0;
static int prev_consolidated_set = 1;

bool garbage_collection_permitted = false;

static void real_garbage_collector()
{
// I lift the real garbage collector to a separate function mainly
// so that I can set breakpoints on it!
    for (int i=0; i<=LOG2_VECTOR_CHUNK_BYTES; i++)
        free_vectors[i] = 0;

    cons_cells = symbol_heads = strings = user_vectors =
            big_numbers = box_floats = bytestreams = other_mem =
                                           litvecs = getvecs = 0;

// Set up the new half-space initially empty.
    new_heap_pages_count = 0;
    new_vheap_pages_count = 0;
    trailing_heap_pages_count = 1;
    trailing_vheap_pages_count = 1;
    assert(pages_count >= 2); // for the new half-space
    void *pp = pages[--pages_count];
    char *vf, *vl;
// A first page of (cons-)heap
    zero_out(pp);
    new_heap_pages[new_heap_pages_count++] = pp;
    heaplimit = (intptr_t)pp;
    vl = (char *)heaplimit;
    fringe = (LispObject)(vl + CSL_PAGE_SIZE);
    heaplimit = (LispObject)(vl + SPARE);
// A first page of vector heap.
    pp = pages[--pages_count];
    zero_out(pp);
    new_vheap_pages[new_vheap_pages_count++] = pp;
    vf = (char *)pp + 8;
    vfringe = (LispObject)vf;
    vl = vf + (CSL_PAGE_SIZE - 16);
    vheaplimit = (LispObject)vl;
// I should remind you, gentle reader, that the value cell
// and env cells of nil will always contain nil, which does not move,
// and so I do not need to copy them here provided that NIL itself
// never moves.
    copy(&(qplist(nil)));
    copy(&(qpname(nil)));
    copy(&(qfastgets(nil)));
    copy(&(qpackage(nil)));
// I dislike the special treatment of current_package that follows. Maybe
// I should arrange something totally different for copying the package
// structure...
    for (LispObject **p = list_bases; *p!=NULL; p++) copy(*p);
    for (LispObject *sp=stack; sp>(LispObject *)stackbase; sp--) copy(sp);
// When running the deserialization code I keep references to multiply-
// used items in repeat_heap, and if garbage collection occurs they must be
// updated.
    if (repeat_heap != NULL)
    {   for (size_t i=1; i<=repeat_count; i++)
            copy(&repeat_heap[i]);
    }
// Throw away the old semi-space - it is now junk.
    while (heap_pages_count!=0)
    {   void *spare = heap_pages[--heap_pages_count];
// I will fill the old space with explicit rubbish in the hope that that
// will generate failures as promptly as possible if it somehow gets
// referenced...
        memset(spare, 0x55, (size_t)CSL_PAGE_SIZE);
        pages[pages_count++] = spare;
    }
    while (vheap_pages_count!=0)
    {   void *spare = vheap_pages[--vheap_pages_count];
        memset(spare, 0xaa, (size_t)CSL_PAGE_SIZE);
        pages[pages_count++] = spare;
    }
// Flip the descriptors for the old and new semi-spaces.
    void **w = heap_pages;
    heap_pages = new_heap_pages;
    new_heap_pages = w;
    w = vheap_pages;
    vheap_pages = new_vheap_pages;
    new_vheap_pages = w;
    heap_pages_count = new_heap_pages_count;
    new_heap_pages_count = 0;
    vheap_pages_count = new_vheap_pages_count;
    new_vheap_pages_count = 0;
}

LispObject reclaim(LispObject p, const char *why, int stg_class, size_t size)
{   uint64_t t0, t1, t2;
    size_t vheap_need = 0;
// If the trigger is reached I will force a full GC. But only if I
// am allowed to!
    if (reclaim_trigger_count == reclaim_trigger_target &&
        garbage_collection_permitted)
        stg_class = GC_USER_HARD;
    stop_after_gc = 0;
    if (stg_class == GC_VEC || stg_class == GC_BPS) vheap_need = size;
    already_in_gc = true;
#if defined WIN32 && !defined __CYGWIN__
    _kbhit(); // Fairly harmless anyway, but is here to let ^c get noticed
//    printf("(*)"); fflush(stdout);  // while I debug!
#endif // WIN32
    t0 = read_clock();
    if (!next_gc_is_hard &&
        stg_class != GC_USER_HARD &&
        reset_limit_registers(vheap_need, true))
    {   already_in_gc = false;
        if (space_limit >= 0 && space_now > space_limit)
            resource_exceeded();
        return p;
    }
    if (stack >= stacklimit)
    {   if (stacklimit != stackbase)
        {   stacklimit = &stacklimit[50];  // Allow a bit of slack
            error(0, err_stack_overflow);
        }
    }

// There are parts of the code in setup/restart where perhaps things are not
// yet in a consistent state and so any attempt at garbage collection could
// cause chaos. So during them I set a flag that I test here! Since this
// should never be triggered I am happy to leave it in state where the only
// sane way to respond to it is to run under a debugger and set breakpoints.
    if (!garbage_collection_permitted)
    {   fprintf(stderr,
                "\n+++ Garbage collection attempt when not permitted\n");
        fflush(stderr);
        my_exit(EXIT_FAILURE);    // totally drastic...
    }

    push(p);

    gc_number++;
    next_gc_is_hard = false;
    if (!valid_as_fixnum(gc_number)) gc_number = 0; // wrap round on 32-bit
                                                    // machines if too big.
    qvalue(gcknt_symbol) = fixnum_of_int(gc_number);

#ifdef WINDOW_SYSTEM
// If I have a window system I tell it the current time every so often
// just to keep things cheery...
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
#ifndef EMBEDDED
        report_time(t, gct);
#endif
        time_now = (int)consolidated_time[0];
        if (verbos_flag & 1 || force_verbos)
        {   freshline_trace();
            trace_printf(
                "+++ Garbage collection %" PRId64
                " (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
                gc_number, why, t/100, t%100, gct/100, gct%100);
        }
    }
#else // WINDOW_SYSTEM
    if (verbos_flag & 1 || force_verbos)
    {   long int t = (long int)(100.0 * consolidated_time[0]);
        long int gct = (long int)(100.0 * gc_time);
// @@@@
// I guess that I want garbage collection messages, if any, to
// be sent to stderr rather than whatever output stream happens to
// be selected at the time of the garbage collection?
// At present messages go to the normal output stream, which only makes
// sense if GC messages are almost always disabled - maybe that will
// be the case!
        time_now = (int)consolidated_time[0];
        if ((time_limit >= 0 && time_now > time_limit) ||
            (io_limit >= 0 && io_now > io_limit))
            resource_exceeded();
        freshline_trace();
        trace_printf(
            "+++ Garbage collection %ld (%s) after %ld.%.2ld+%ld.%.2ld seconds\n",
            (long)gc_number, why, t/100, t%100, gct/100, gct%100);
    }
#endif // WINDOW_SYSTEM
    switch (pages_count)
    {
    case 0: allocate_more_memory(); // ...and drop through...
    case 1: allocate_more_memory();
    }
// If despite trying allocate_more_memory() I can not find a new pages to
// form that start of the new half-space I will have to give up.
    if (pages_count < 2)
    {   report_at_end();
        term_printf("\n+++ Run out of memory\n");
        ensure_screen();
        my_exit(EXIT_FAILURE);
    }
// If things crash really badly maybe I would rather have my output up
// to date.
    ensure_screen();
    if (spool_file != NULL) fflush(spool_file);
    if (gc_number == reclaim_trap_count)
    {   reclaim_trap_count = gc_number - 1;
        trace_printf("\nReclaim trap count reached...\n");
        aerror("reclaim-trap-count");
    }
    if (reclaim_stack_limit != 0 &&
        (uintptr_t)&t0 + reclaim_stack_limit < (uintptr_t)C_stackbase)
    {   reclaim_stack_limit = 0;
        trace_printf("\nReclaim stack limit reached...\n");
        aerror("reclaim-stack-limit");
    }

    t2 = t1 = t0;   // Time is not split down in this case
    if (reclaim_trigger_target != 0)
        trace_printf("+++ GC trigger = %" PRId64 "\n", reclaim_trigger_count);
    real_garbage_collector();

    t1 = read_clock();
    gc_time += t1 - t0;
    base_time += t1 - t0;
// (verbos 5) causes a display breaking down how space is used
    if ((verbos_flag & 5) == 5)
    {   trace_printf(
            "cons_cells=%" PRIdPTR ", symbol_heads=%" PRIdPTR ", strings=%" PRIdPTR ", user_vectors=%" PRIdPTR "\n",
            cons_cells, symbol_heads, strings, user_vectors-litvecs-getvecs);
        trace_printf(
            "bignums=%" PRIdPTR ", floats=%" PRIdPTR ", bytestreams=%" PRIdPTR ", other=%" PRIdPTR ", litvecs=%d\n",
            big_numbers, box_floats, bytestreams, other_mem, litvecs);
        trace_printf("getvecs=%" PRIdPTR " C-stacks=%" PRIdPTR "K Lisp-stack=%" PRIdPTR "K\n",
                     getvecs, (((char *)C_stackbase-(char *)&why)+1023)/1024,
                     (intptr_t)((stack-stackbase)+1023)/1024);
    }
    pop(p);

    grab_more_memory(heap_pages_count + vheap_pages_count);

    if (!reset_limit_registers(vheap_need, false))
    {   if (stack < stacklimit || stacklimit != stackbase)
        {   report_at_end();
            term_printf("\n+++ Run out of memory\n");
            ensure_screen();
            my_exit(EXIT_FAILURE);    // totally drastic...
        }
    }
    report_at_end();
    if (stop_after_gc) Lstop1(nil, fixnum_of_int(0));
    if (interrupt_pending)
    {   interrupt_pending = false;
        already_in_gc = false;
        return interrupted(p);
    }
    already_in_gc = false;
    if ((space_limit >= 0 && space_now > space_limit) ||
        (time_limit >= 0 && time_now > time_limit) ||
        (io_limit >= 0 && io_now > io_limit))
        resource_exceeded();
    prev_consolidated = consolidated_time[0];
    return use_gchook(p, lisp_true);
}


uintptr_t *C_stackbase;



// end of newallocate.cpp
