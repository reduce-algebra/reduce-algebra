// allocate.cpp                            Copyright (C) 1989-2018 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//

/**************************************************************************
 * Copyright (C) 2018, Codemist.                         A C Norman       *
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

#ifdef WIN32
#include <windows.h>
#else // !WIN32
#include <unistd.h>
#include <sys/mman.h>
#endif // !WIN32

#ifdef CONSERVATIVE
//@@@@ FUDGES

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

#else // !CONSERVATIVE

LispObject fringe, heaplimit;

#endif // !CONSERVATIVE             @@@@ END OF FUDGES

// The work discussed here is to arrange that CSL uses a mostly-copying
// conservative collector. The details are substantially tuned to the expected
// patterns of memory usage. Although the initial implementation will be
// single threaded the intent is to allow for a threaded system in the future.
// Following CST project work by Jamie Davenport I now intend to try for a
// design that is conservative, generational and somewhat threaded.
//
// Memory is used in pages (of size CSL_PAGE_SIZE). Given an arbitrary
// bit-pattern it will be possible to tell if it refers to an address
// within an object in one of these pages.
//
// All pages are the same and can contain a mix of CONS cells and vectors.
// The associated penalty as against having one sort of page for cons cells
// and another for vectors will be that every CONS cell needs to be identified
// in a bitmap being at the start of an object.
// Well because the majority of allocations will be of these, I will take
// the view that rather than marking the first word of every object I will
// mark bits on every word that is NOT the start of an object. For
// vectors this means every word of their content. When a large vector is
// allocated this can feel like a lot of mark bits to set - but I have three
// responses to that:
// (1) For vectors that hold list pointers I will need to initialize all the
//     cells of the vector anyway, so I already have a cost that is linear
//     in the vector-size and adjusting mark bits is thus maybe not too bad.
// (2) For large vectors I will be able to set the bits up to 64 at a time
//     by using word operations, so the total overhead should be modest.
// (3) I can still leave a "1" bit in the bitmap as indicating the start of
//     an object and a "0" the interior. And when I look at the first word of
//     an object I can distinguish a CONS because it does not have a word
//     tagged as a header in what is its CAR field.
//
// With each page I will have a bitmap that is used to record a concept "pinned"
// that can be associated with any object in the page. An item will be marked
// pinned if an ambiguous pointer refers to it, and hence it may not be moved.
// I will have an array of size half a page for each thread and will bse that
// to collect a list of all the pinned items in a single page of memory that
// I am evacuating. The size here is only half a page because the smallest items
// ever allocated within the heap are 2 pointers large. I rather expect that
// the full capacity of this will never be approached.
//
// Pages of memory are classified as
//   Current (C). These are the pages within which the mutator allocates
//      new material. There may be several such if allocation of CONS cells
//      and vectors use different dedicated current pages and in a multi-thread
//      world each thread would have its own current page or pages.
//   Recent (R). When a current page becomes full it is replaced with a new
//      empty page, and the full page that had been current is re-badged as
//      "recent". When that happens the previous recent page will have its
//      content evacuated - that process representing a minor garbage
//      collection.
//   Stable (S). When live material is moved out of an "old recent" page it is
//      copied into the stable region. This will come to be the bulk of the
//      active heap and uses as many pages as are called for. At any one time
//      one of these pages will be the "stable fringe" where new material is
//      added. In a multi-thread world there is just a single pool of stable
//      heap.
//   Free (F). Pages that are not in use are in this group. When a minor
//      garbage collection places in a fresh stable page such that |S| > |F|
//      then a full garbage collection is triggered. At that stage R is empty.
//      The stable fringe page is then deemed part of what will become the
//      new heap, and all material apart from that is copied into that and
//      subsequent pages taken from free. The vacated pages are then
//      re-labelled to form the new free region. While doing this the current
//      page does not have its content relocated.
//
// Within the heap I can maintain "dirty bits" that mark parts of pages where
// data has been updated. I will arrange that as the start of a minor garbage
// collection I will have two maps of dirty memory, one corresponding to the
// time period while R was being filled and a second to the time that C was
// filled. Clearly at the end of a minor collection the old C becomes the new
// R and a fresh C is allocated, so the previous C-map becomes the new R-map
// and the new C-map starts off fresh and clean. These maps will not be needed
// or used during a major collection.
//
// Now I will be explicit about the expectations that I have that lead to this
// plan. They are
// (1) Much material that is allocated will only remain active for a short
// while. The time that it takes to fill up the C page will be long enough that
// when C becomes full everything in R will have had time for this infant
// mortality to take effect, and so on a minor garbage collection a substantial
// fraction of R will be garbage and hence does not get copied into S.
// (2) In CSL the only place the ambiguous pointers reside is on the stack.
// An especially large number of entries towards the top of the stack will
// refer to data that is just in the process of being worked on, and this will
// mean that most ambiguous pointers that refer to anything at all will refer
// to locations within C. In particular I hope that there will be few ambiguous
// references into R. Neither minor nor major garbage collection will relocate
// data that is in C, so my expectation and hope is that there will be only
// minor disruption to storage elsewhere because of conservatism.
// (3) The schemes I have for identifying dirty regions of memory are based on
// storage protection and accepting an exception when a region is first written
// to. Because subsequent memory access is unimpeded I expect this will have
// low overhead. Memory protection is performed at a granularity substantially
// smaller then the size of whole pages. My expectation is that almost all
// writes to memory will be in either C or in symbol headers. Symbol headers
// will be distributed across S, but I can imagine arranging that the major
// garbage collection would copy all symbol headers from the oblist in such
// a way as to leave them as a compact block (along with the vectors that
// represent the object list itself). The hope is that the amount of memory
// identified as dirty will be a rather small fraction of the full size of the
// heap.
// (4) Given an arbitrary bit pattern it will first be possible to tell if it
// could be an address within any active page of the heap, and if it is then
// the starting address and Lisp type of any item it points within can be
// discerned reasonably efficiently.
// (5) Given a region of memory within a page it will be possible to identify all
// Lisp objects that overlap it, and on that basis scan all pointers that flow
// out from it. Maybe the key issue here is when the region covers the end but
// not the start of some Lisp vector and it is thus necessary to search back
// through lower-address parts of a page to find the start and hence the length
// of the vector. The assumption here requires consideration of any cases where
// objects in memory are not strictly laid out one after the other but where
// there are gaps between them.
// (6) With a conservative collector it is necessary to leave some items
// unrelocated in a manner that leaves the free space at the end of garbage
// collection fragmented. In pathological cases this could lead to major
// inefficient in  attempots to allocate vectors, and premature failure to
// allocate. This may include failure to allocate while performing the
// copying operstions of a major garbage collection! Perhaps I can manage a
// temporary recovery if I find myself gummed up during garbage collection by
// just giving up and not evacuating some data. That way I can at least get
// back to normal operation, albeit without enough memory freed up to be
// able to start any subsequent garbage collection with any confidence at all.
// But that may be sufficient to allow be to display a disgnostic about
// running out of memory and then close down. Note that within CSL I allocate
// vectors of size up to (1/4) of the page size, and allowing for the fact
// that pages contain headers and bitmaps this means that (only) up to 3
// maximum size vector chunks can fit on one page, and a wasted gap can be left.
// I need to consider whether vector allocation should have two strands: the
// simple one being linear allocation at the end of the current page, but
// building any space that has to be skipped either because of pinned data or
// the granularity of the pages into a free-chain, and then an alternative
// scheme that allocates from within this free-chain so that smaller
// allocations can be used to fill in the gaps. I think that sort of plan
// may be especially useful for the allocations that are performed for
// material that is being copied during a major garbage collection, so my
// my current plan is that the mutator uses simple allocation that may leave
// significant gets adjacent to where large vectors are allocated, but that
// the collector, when copying live data to the new half-space, tries a bit
// harder to fill in those gaps.
//
//
// The overall pattern for a minor garbage collection will be
// (1) Clear the pinned map for R
// (2) Scan all ambiguous bases (ie the stack) and if any item there could
//     be a pointer into R then set the pinned bit against the head of the
//     relevant object. Keep a list of all those objects in the "pinned table".
// (3) Scan all unambiguous bases, all locations within objects that are
//     in regions of memory dirty since R was set up and all locations within
//     the pinned items in R. In each case if the reference is to a non-pinned
//     item in R then on the first visit evacuate that item into S, and on
//     a subsequent visit just use the forwarding pointer set up on the first
//     visit. Update the base. Note that I expect all of C to be dirty, and
//     so scanning it may perhaps be done more elegantly than checking every
//     part of it for dirty bits.
// (4) Scan the material newly places in S. If references into R are found
//     then evacuate more or follow the forwarding address. This may expand
//     the region in S that is used - grab further pages for it as needed.
//     Stop when the scan has covered everything moved into S.
// (5) Now the only live data in R should be the things that are pinned.
//     Use the pinned table to build the structures within it that support
//     allocation. [Note: after this step the pin map and table are both no
//     longer needed].
// (6) Check if S is now over-full and if so trigger a major garbage collection.
// (7) Swap the interpretation of C and R, and update the dirty maps to match.
//     Well the dirty map issue is maybe ugly. Any part of S that has been
//     updated such that it refers into C must now be tagged in the map, and
//     all of what used to be R but is now C can have map info cleared.
//
//
// A major garbage collection has a slightly simpler structure because while it
// must cope with ambiguous pointers it processes all data apart from C.
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
//

// Let me start to talk about the arrangement within a "page" (which
// is a region of memory of size CSL_PAGE_SIZE, maybe 8 Mbytes).
// Pages can be in a number of states. One obvious one is "unused". Others
// involved whether they are in the "new" or "old" region of the heap (as
// regards the copying nature of garbage collection), whether they are a
// "nursery page" (as regards a generational collection strategy) and so on.
// The first word of a page will contain information about that sort of thing!
// The second word is available for forming chains of pages.
// There are then two words that are available to hold information about how
// full the page is.
// After are some bitmaps and then data..
//
// The first sort of page to be discussed is used to store large vectors.
// The format is as follows:
//     type info      )
//     chaining word  )
//     fringe, vfringe and a bunch of other values that characterize the
//     arrangement of free and pinned areas within the page. See lower down
//     for details.
//     [object start bitmap]
//     [pin bitmap]
//     start of used data
//     ... used for vectors
//     end of used data <----------- vfringe
//     ... free
//     end of available space <----- vheaplimit, vheaptop
//     ... pinned data (must be a multiple of 2*CELL long)
//     the exclusive OR of the addresses just beyond surrounding two
//        pinned blocks.
//     the length of the pinned block here
//     ... free
//     ... <------------------------ fringe
//     ... used for cons cslls (and 2-CELL vectors)
//     ... <------------------------ heapstart
//     <end of page>
//
// The idea is that the whole page can be interrupted if "pinned" items
// are present within it. These are items that were referenced from an
// ambiguous base during a previous garbage collection and so which can not
// be moved - fresh allocation has to work around them. So the space available
// in the page is made up of a series of chunks. During allocation chunks
// are used from the low address upwards, and fringe/heaplimit show where
// allocation can happen and its limit. The chunks will be kept in a free
// chain: the first two words of each chunk hold first the end-point of that
// chunk and then the start of the next one. If the chunnk is the last one of
// the poge then its successor can be given as NULL.
// While CSL is running the chaining from the current chunk will have been
// overwritten when the first vector is allocated in that chunk. So it
// will be necessary (and indeed reasonable) to store fringe, heaplimit and
// next_fringe in (static or extern) variables. Now supposing there are
// multiple threads active the garbage collector would need to access and
// update each thread's versions of these variables. So at the start of
// garbage collection the values of these variables will be dumped at the
// start of the page.
// During normal CSL processing if an attempt is made to allocate a vector
// and it will not fit into the current chunk then the end of the current
// chunk can be left in whatever (potentially messy) state that it is. But
// during the copying part of garbage collection the newly copied data will
// be scanned linearly. This scan will include processing pinned as well as
// newly allocated items. To allow for this the copying code can insert
// dummy binary vectors to fill up any gaps.

// The bitmap covers the "used data" region. For each location that could
// possibly be the start of an item (ie evenr other word, where a word is
// the size of a machine pointer) there are two bits. The first marks when
// words are headers of objects. By having that bit present it becomes
// possible to take an arbitrary bit-pattern and identify an object that
// it points within: first the segment associated with the pointer is
// identified. Then the page (by rounding down addresses within segments so
// that the offset within the segment is a multiple of the page size).
// Then the address at or before the pointer that has its "object start"
// bit set is the object of interest. Finally the offset of the pointer from
// the object header can be compared against the length of the object (which
// can be deduced from the header).
// The second bit is set when an item that starts at a given address is
// pinned. So the generally valid combinations of bits are
//    not-start, not-pinned
//    start, not pinned,
//    start, pinned.
// That leaves the combination (not-start,pinned) available for use during
// garbage collection if having an additional state is useful.
//

// A bitmap that covers a page has to have a size (in bytes) that allows for
// 8 bits in each byte and that covers the page at a granularity of 8 bytes.
// The granularity of 8 is because on both 32 and 64-bit systems objects
// are allocated on 8-byte boundaries.

#define PAGE_BITMAP_SIZE (CSL_PAGE_SIZE/(8*8))

// These structures show how a page is laid out. Every so often I will
// cast a reference to a page to be a reference to this structure.

typedef struct page_header_
{   uintptr_t page_type;
    struct page_header_ *page_chain;
// The following fields get set either at system initialization time or
// by the end of garbage collection. They describe how the free space
// within this page might be interrupted by little regions of pinned data.
// When a page becomes active (ie the one that the allocation process is
// actually using) values are copied from here into global variables. An
// explanation of the purpose of each of these is given where those
// global variables are defined.
    uintptr_t vheapstart;
    uintptr_t vfringe;
    uintptr_t vheaplimit;
    uintptr_t vheaptop;
    uintptr_t vlen;
    uintptr_t vxor_chain;
    uintptr_t heapstart;
    uintptr_t fringe;
    uintptr_t heaplimit;
    uintptr_t len;
    uintptr_t xor_chain;
    uintptr_t padder_item_1;
    uintptr_t padder_item_2;
    uintptr_t padder_item_3;
// Note that the fields thus far in this page header will use up
// a multiple of 16 bytes, so doubleword alignment is assured for
// the main data region. Guaranteeing that is what the padder items are
// there for.

// Ha ha. The bitmap as implemented here has bits in it that cover
// all the page header (including itself) and that is a waste. But it is
// such a small one that I propose not to worry myself!

    uint64_t objectstart_bitmap[PAGE_BITMAP_SIZE/sizeof(uint64_t)];
    uint64_t pinned_bitmap[PAGE_BITMAP_SIZE/sizeof(uint64_t)];

    LispObject data[1];
} page_header;

// At any stage I will have one page that is "active", ie that I am
// allocating structures within.

page_header *free_pages;
page_header *used_pages;
size_t free_pages_count;
size_t active_pages_count;
page_header *previous_active_page;
page_header *active_page;

// Test if a pointer (p) points at an object header. This interacts
// with the details of memory allocation in a pretty delicate manner!

static inline bool is_header_address(Header *p, page_header *page)
{   uintptr_t offset = (char *)p - (char *)page;
// If the putative pointer refers to parts of the header that are before
// any useful data (for instance it refers into the bitmap) or if it points
// beyond the end of the page it is not valid.
    if (offset < offsetof(page_header, data) ||
        (offset >= page->vfringe &&
         offset <= page->fringe)) return false;
// The bitmap will have one bit for every 8 bytes...
    offset /= 8;
// ... and it stores 64 bits of information in each uint64_t entry.
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
// A header is signified by having a 1 in the bitmap. When a page starts off
// empty it then on a 32-bit system every bit will be set, while on a 64-bit
// one every other bit will start of set. That will mean that references
// into the region that contains CONS cells and 2-rord items will automatically
// be OK. Items that are allocated in the vector-region will need to set the
// header bit for their first word and clear it for everything else.
    return (page->objectstart_bitmap[n] & bit) == 1;

}

// When I set or clear bits that mark an object header I will only do so
// with addresses that are validly in-range.

static inline void set_header_bit(LispObject p, page_header *page)
{   size_t offset = ((uintptr_t)p - (uintptr_t)page)/8;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->objectstart_bitmap[n] |= bit;
}

static inline void clear_header_bit(LispObject p, page_header *page)
{   size_t offset = ((uintptr_t)p - (uintptr_t)page)/8;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->objectstart_bitmap[n] &= ~bit;
}

//## The commented out version here was a model implementation to show the
//## intended behaviour of the function that clears a succession of bits.

//## static inline void clear_header_bits(LispObject p, size_t n, page_header *page)
//## {   while (n != 0)
//##     {   clear_header_bit(p, page);
//##         p += 8;
//##         n -= 8;
//##     }
//## }

static inline void clear_header_bits(LispObject p, size_t n, page_header *page)
{   if (n == 0) return; // degenerate simple case.
// I sort out the first bit that needs clearing.
    size_t first_offset = (p - (LispObject)page)/8;
    size_t first_n = first_offset/64;
    uint64_t first_bit = ((uint64_t)1)<<(first_offset%64);
// Now the last bit that needs clearing.
    size_t last_offset = (p + n - 1 - (LispObject)page)/8;
    size_t last_n = last_offset/64;
    uint64_t last_bit = ((uint64_t)1)<<(last_offset%64);
// I will want to clear from the first bit onwards, so I will want to AND
// with a value that has 1 bits up to but not including the bit.
    uint64_t first_mask = first_bit - 1;
// I will want to clear all bits beyond the last one, so the value to AND
// with must have bits beyond last_bit all set and lower ones all clear.
    uint64_t last_mask = -2*last_bit;
// If start and finish points are both within the same 64-bit word I
// need to merge my two masks.
    if (first_n == last_n)
        page->objectstart_bitmap[first_n] &= first_mask & last_mask;
    else
    {   page->objectstart_bitmap[first_n++] &= first_mask;
// All words apart from the first and last simply get set to zero. This
// inner loop is where there may be a big speedup here in the case of
// large vectors.
        while (first_n != last_n)
            page->objectstart_bitmap[first_n++] = 0;
// The final 64-bit word is special too.
        page->objectstart_bitmap[first_n++] &= last_mask;
    }
}

static inline bool is_pinned(LispObject p, page_header *page)
{   size_t offset = p - (LispObject)page;
// If the putative pointer refers to parts of the header that are before
// any useful data (for instance it refers into the bitmap) or if it points
// beyond the end of the page it is not valid.
    if (offset < offsetof(page_header, data) ||
        offset >= page->fringe) return false;
    offset /= 8;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    return (page->pinned_bitmap[n] & bit) != 0;
}

static inline void set_pinned(LispObject p, page_header *page)
{   size_t offset = (uintptr_t)p - (uintptr_t)page;
    offset /= 8;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->pinned_bitmap[n] |= bit;
}

static inline void clear_pinned(LispObject p, page_header *page)
{   size_t offset = (uintptr_t)p - (uintptr_t)page;
    offset /= 8;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->pinned_bitmap[n] &= ~bit;
}

#ifdef USE_SIGALTSTACK

static unsigned char signal_stack_block[SIGSTKSZ];
stack_t signal_stack;

#endif

// On POSIX systems sigaction() is now preferred to the older signal()
// function, and to implement the write barrier for my garbage collector
// I need its extra functionality. However on Windows the write barrier can
// be implemented in a rather different way, and as of the time of writing
// the mingw compilers/libraries do not support sigaction (one might
// reasonably believe that simulating it when running on Windows might be
// pretty horrid!), so on Windows I will still use just signal().

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
        heap_segment[i] = (void *)UINTPTR_MAX;
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
    if (sigaction(SIGSEGV, &sa, NULL) == -1)
        /* I can not thing of anything useful to do if I fail here! */;
#ifdef SIGBUS
    if (sigaction(SIGBUS, &sa, NULL) == -1)
        /* I can not thing of anything useful to do if I fail here! */;
#endif
#ifdef SIGILL
    if (sigaction(SIGILL, &sa, NULL) == -1)
        /* I can not thing of anything useful to do if I fail here! */;
#endif
    if (sigaction(SIGFPE, &sa, NULL) == -1)
        /* I can not thing of anything useful to do if I fail here! */;
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

// All the heap memory I use here will be allocated within (up to) 32
// segments that are grabbed using either malloc or VirtualAlloc. Each
// segment of memory will start aligned at a multiple of 0x10000 and
// will come with an associated bitmap that is used to record which pages
// within it have been written to. The concept of "page" here will be keyed
// to the operating system in use and the mechanism used to detect which
// parts of memory have been updated. And I use the same word (ie "page")
// later on for the way that CSL divides segments into chunks for its own
// purposes... if I was being pedantic I would use the term "system pages"
// around here, but I hope there will - in the end - not be much confusion.
// I try to pack the bitmaps for small(ish) pages into a single vector
// heap_small_bitmaps. Once the bitmaps get to be at least 0x10000 byte in
// size they just get added to the size of memory block allocated for a
// segment (and that has to happen once heap_small_bitmaps is full).

// For memory protection purposes the granularity of pages will vary from
// system to system, but I want to have a range of sizes that I view as
// acceptable. Well here it is - pages can be as amall as 4096 bytes
// or as large as 64K.

// #define MIN_PAGE_SIZE 0x01000
// #define MAX_PAGE_SIZE 0x10000

size_t page_size;


// For up to 32 segments I have...
//   heap_segment_count   number of allocated segments
//   heap_segment[i]      base address of a segment of memory
//   heap_segment_size[i] size of useful part of that segment, in bytes
//   heap_segment_total_size[i] total size
//   heap_dirty_pages_bitmap_1[i] a bitmap used to track which block
//                        have been written to, information that can
//                        help with garbage collection. The "block"
//                        granularity here is determined by the operating
//                        system and is probably 0x1000 or 0x10000.
//   heap_dirty_pages_bitmap_2[i] a second such bitmap, used to record
//                        pages updated during a recent previous era.
//
// Within each segment the memory is arranged in pages each of size
// CSL_PAGE_SIZE, which may be 8 Mbytes. The arrangement of information
// within pages is documented lower down this file.

void *heap_segment[32];
size_t heap_segment_size[32];
size_t heap_segment_total_size[32];
// I will arrange my bitmap in 64-bit words - expecting that memory access
// to 64-bits when I update an entry ias as cheap as anything else, but then
// scanning for nonzero bits can go 64-bits as a time.
uint64_t *heap_dirty_pages_bitmap_1[32];
uint64_t *heap_dirty_pages_bitmap_2[32];
size_t heap_segment_count = 0;
// I have a simple fixed bitmap region of size MAX_PAGE_SIZE bytes (ie 64K)
// here.
// [defined in allocate.h] SMALL_BITMAP_SIZE=(MAX_PAGE_SIZE/sizeof(uint64_t)/2)
uint64_t heap_small_bitmaps_1[SMALL_BITMAP_SIZE+1];
uint64_t heap_small_bitmaps_2[SMALL_BITMAP_SIZE+1];
uint64_t *heap_small_bitmaps_1_ptr = &heap_small_bitmaps_1[SMALL_BITMAP_SIZE];
uint64_t *heap_small_bitmaps_2_ptr = &heap_small_bitmaps_2[SMALL_BITMAP_SIZE];

std::atomic_flag spin_lock = ATOMIC_FLAG_INIT;

void get_page_size()
{
#ifdef WIN32
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    page_size = si.dwPageSize;
#else
    page_size = sysconf(_SC_PAGE_SIZE);
#endif
    if (page_size == (size_t)(-1))
    {   fprintf(stderr, "unable to get page size\n");
        exit(1);
    }
    printf("page_size = %d = %#x\n", (int)page_size, (int)page_size);
    if (page_size < MIN_PAGE_SIZE ||
        page_size > MAX_PAGE_SIZE) my_abort();
}

// I can set mprotect_valid false if I want to avoid the code here
// calling mprotect. This is done because mprotect, while thread-safe, is
// not async signal safe.

bool mprotect_valid = true;

// The bitmap associated with each big segment of memory can be
// set to zero using clear_bitmap() and on Windows it is necessary to
// call refresh_bitmap to fill it in before interrogating it. The
// clear_bitmap function will leave things so that any subsequent writes
// to the memory concerned will be collected for use following the
// next refresh_bitmap().
// Returns true on success.

bool clear_bitmap(size_t h)
{   size_t n = heap_segment_size[h]/page_size; // measured in bits
    n = (n + 7) & -(size_t)8;                  // now in bytes
    memset(heap_dirty_pages_bitmap_1[h], 0, n);  // clear the map
#ifdef WIN32
    if (ResetWriteWatch(heap_segment[h], heap_segment_size[h]) != 0)
        return false;
#else // !WIN32
    mprotect_valid = false;
    if (mprotect(heap_segment[h], heap_segment_size[h],
                 PROT_READ) == -1)
    {   mprotect_valid = true;
        return false;
    }
    mprotect_valid = true;
#endif // !Win32
    return true;
}

static inline void atomic_set_bit(uint64_t *base, size_t offset)
{   uint64_t *addr = &base[offset/(8*sizeof(uint64_t))];
    uint64_t bit = ((uint64_t)1) << (offset%(8*sizeof(uint64_t)));
    while (spin_lock.test_and_set(std::memory_order_acquire)) {}
    *addr |= bit;
    spin_lock.clear();
}

static inline void non_atomic_set_bit(uint64_t *base, size_t offset)
{   uint64_t *addr = &base[offset/(8*sizeof(uint64_t))];
    uint64_t bit = ((uint64_t)1) << (offset%(8*sizeof(uint64_t)));
    *addr |= bit;
}

// This takes the sigment of memory identified by handle h and extracts
// writewatch information from it, collecting the information in the
// associated bitmap. This is only needed for Windows because the POSIX
// systems collect information directly in the bitmaps. This returns true
// on success.

bool refresh_bitmap(size_t h)
{
#ifdef WIN32
#define BUFSIZE 1000
    void *buffer[BUFSIZE];
    ULONG_PTR buffsize = BUFSIZE;
    ULONG page_size_here;
    char *base = (char *)heap_segment[h];
    size_t n = heap_segment_size[h];
    char *top = base + n;
// I may need to interrogate the memory segment using multiple calls
// if there is a chance that there may be more then BUFSIZE touched
// pages present.
    while (base < top)
    {   size_t amount_to_scan = top - base;
        size_t pages_to_scan = amount_to_scan/page_size;
        if (pages_to_scan > BUFSIZE)
        {   pages_to_scan = BUFSIZE;
            amount_to_scan = pages_to_scan*page_size;
        }
        buffsize = BUFSIZE;
        if (GetWriteWatch(0,              // do not reset flags
                          base,           // region to get info about
                          amount_to_scan, // length of monitored region
                          buffer,         // place to put output
                          &buffsize,      // space in output buffer
                          &page_size_here) != 0) return false;
        if (page_size_here != page_size) return false;
// Now move info from what Windows has returned into my bitmap
        for (ULONG i=0; i<buffsize; i++)
        {   char *page = (char *)buffer[i];
            size_t page_offset =
                ((size_t)(page - (char *)heap_segment[h])) / page_size;
            non_atomic_set_bit(heap_dirty_pages_bitmap_1[h], page_offset);
        }
        base += amount_to_scan;
    }
#endif // !WIN32
    return true;
}


// find_heap_segment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it.

extern int find_heap_segment(uintptr_t p);

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
#ifndef WIN32
// On non-Windows systems I set heap pages as read-only, and then the
// first time I perform a write to a page I set a bit in a map to record
// that it is dirty. This is to support a possible future development of
// a generational garbage collector, where this scheme will serve as part
// of the implementation of a write barrier.
    if ((signo == SIGSEGV
#ifdef SIGBUS
         || signo == SIGBUS
#endif
         ) && mprotect_valid)
    {   void *addr = si->si_addr;   // The address that was at fault
// See if the faulting address was within the memory that we had allocated
// for our heap. If so there is a real prospect that all I need to do is
// to record what has happened and re-flag the page as read-write.
        int h = find_heap_segment((uintptr_t)addr);
        if (h >= 0)
        {
// mprotect is not async signal safe, and I find uncertain explanations as
// to whether it is thread-safe  (I believe it is on Linux). To be safe
// I protect it with a spin-lock here. Well the spin lock could be expensive
// if mprotect takes long to execute! Also this is still not async signal
// safe, merely safe against page faults in different threads. If in the
// main body of some thread I perform an mprotect then I must not have a
// SIGSEGV within the inner execution of the mprotect, and nothing within
// the critical region guarded by the spinlock here may cause a SIGSEGV.
// Well all there is in the critical region is access to the spinlock
// itself and the mprotect call.
            addr = (void *)((uintptr_t)addr & -(uintptr_t)page_size);
            while (spin_lock.test_and_set(std::memory_order_acquire)) {}
            int rc = mprotect(addr, page_size, PROT_READ | PROT_WRITE);
            spin_lock.clear();
            if (rc == -1)
            {   errorset_msg = "Unable to restore R/W status of memory page";
                global_longjmp();
            }
// Now fill in a map!
            void *base = heap_segment[h];
            size_t page_offset = ((char *)addr - (char *)base)/page_size;
// I will re-acquire the spin lock to update the bitmap, but this time I
// know that the critical region is very short, so I am not concerned about
// performance here.
            atomic_set_bit(heap_dirty_pages_bitmap_1[h], page_offset);
// When the SIGSEGV or SIGBUS was activation of a wtite barrier I will
// exit from the signal handler when I have dealt with it. That should
// re-try the memory access, which ought now to succeed.
            return;
        }
    }
#endif
// For all exceptions that are not to do with a write barrier I will create
// a message string (which I put in threead local memory)
    if (miscflags & HEADLINE_FLAG)
    {   switch (signo)
        {   default:
                {   volatile char *p = signal_msg;
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

#ifdef CONSERVATIVE

// This is an updated and fuller explanation of memory layout on each
// page. A page starts with a header and teo bitmaps and then its data
// region. I will just discuss the data region here.
// The data region may be disrupted with some pinned items within in, and
// those pinned items must be worked around during allocation. Each clump on
// pinned items will be padded (if necessary) so that the clump is an even
// numver of cells long. If a clump lines within the data region it will
// be followed by two information words.
// Allocation of vectors will proceed at increasing addresses within the
// while CONS cells (and any other 2-CELL items) are allocated downwards
// from the top. Within a page the following variables are in play to control
// allocation:

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

static void allocate_next_page();

static inline Header make_padding_header(size_t n)
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

static inline LispObject get_2_words()
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
// needed to help with alignment) their headers will not be tagged.
    return fringe;
}

static uintptr_t small_padders = 0, large_padders = 0;
static uintptr_t *small_padders_tail = &small_padders,
                 *large_padders_tail = &large_padders;

static void get_n_bytes_past_pin()
{
// The vector I want to allocate will not fit at the next consecutive
// address. So to keep the heap tidy I will insert a padder record
// there.
    if (vfringe != vheaplimit)
    {   *(Header *)vfringe = make_padding_header(vheaplimit - vfringe);
// I will collect a chain of all the padders that I create. This will be
// built in historical order. I will do this even during ordinary allocation
// because the overhead is not huge, but it is required when I am
        if ((vheaplimit - vfringe) != CELL)
        {    if ((vheaplimit - vfringe) < symhdr_length)
             {   *small_padders_tail = vfringe;
                 small_padders_tail = &((uintptr_t *)vfringe)[1];
                 *small_padders_tail = 0;
             }
             else
             {   *large_padders_tail = vfringe;
                 large_padders_tail = &((uintptr_t *)vfringe)[1];
                 *large_padders_tail = 0;
             }
        }
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

static inline LispObject get_n_bytes(size_t n)
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
    memset(p->objectstart_bitmap,
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



// This code allocates a segment by asking the operating system. On
// Windows it uses VirtualAlloc() and on other systems mmap(). It arranges
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


page_header *save_active_page;
page_header *save_previous_active_page;
uintptr_t save_vheapstart;
uintptr_t save_vfringe;
uintptr_t save_vheaplimit;
uintptr_t save_vlen;
uintptr_t save_vheaptop;
uintptr_t save_vxor_chain;
uintptr_t save_heapstart;
uintptr_t save_fringe;
uintptr_t save_heaplimit;
uintptr_t save_len;
uintptr_t save_xor_chain;

void prepare_for_borrowing()
{   save_previous_active_page = previous_active_page;
    save_active_page = active_page;
    save_vheapstart  = vheapstart;
    save_vfringe     = vfringe;
    save_vheaplimit  = vheaplimit;
    save_vlen        = vlen;
    save_vheaptop    = vheaptop;
    save_vxor_chain  = vxor_chain;
    save_heapstart   = heapstart;
    save_fringe      = fringe;
    save_heaplimit   = heaplimit;
    save_len         = len;
    save_xor_chain   = xor_chain; 
    allocate_next_page();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   return get_basic_vector(tag, type, size);
}

LispObject borrow_vector(int tag, int type, size_t n)
{   return get_vector(tag, type, n);
}


// Now I want to think about the implementation of the copying garbage
// collector. For that I will want to allocate copies of material in
// what might be called the "new space". Well in fact it is nothing very
// special in terms of half-spaces, it is just pages of memory not currently
// occupied. So the allocation can be rather in the style of "borrowing", ie
// it disables further garbage collection and just allocated in fresh pages.
// However I will then want to perform a linear scan over these fresh pages,
// so when I chain them up I want to make the list so that the page that is
// allocated first comes on the front of the list and new ones get tagged
// on the end.
// There is a potential for fragmentation, especially in the presence of
// pinned items. As a result the allocator will sometimes insert a padder
// vector so that memory can be scanned linearly in a neat way.
// I will chain those padder vectors together keeping them in sequential
// order. When I need to allocate I will use a variant on first-fit to
// try allocating within one of them. If I find space within one I will
// use the meory at its low address and adjust thiungs so that the padder
// moved upwards. There will be two circumstanmces when I remove a padder
// block from the chain of spare space: one is when allocation from within
// it reduces its size to just 1 word or fills it up completely. The other
// is when the linear scan part of the GC reaches it. First fit can have a
// nasty cost associated with scanning over many initial small chunks until
// a large enough one is found. I will also want to fill up early chunks
// so that they are well occupied by the time linear scan reaches them.
// So my current and possibly over-complicated scheme would be to have
// separate chains for chunks of size 2-6 and 7+ cons cells. When allocating
// I do first fit on each of the chains, but limiting myself to a fixed
// maximum number of cases scanned. If I do not find space to re-use that
// way I will allocate in the normal sequential manner at the end of the
// growing new heap. The change-over point at 7+ is so that allocating a
// new symbol header only scans padder blocks that will have enough space, and
// is done on he hypothesis that this might be a fairly common case. The
// amounts of search involved are then:
//  1-quad:    No search, the first 2-6 free block will always have space!
//  2-6 quads: Check up to K blocks in the 2-6 freechain. Those might in fact
//             all be of size just 2.
//             But if allocation there fails then the first block on the
//             7+ chain is a guaranteed success.
//  7 quads:   The first 7+ block will be OK.
//  8+ quads:  Search the first K items in the 7+ chain.
// There is an issue of judgment as to a reasonable value for K, but I am
// going to start bt expecting that that will be of secondary importance and
// the balance between performance and fitting blocks in will not depend
// critically on it. But a fairly small value such as 4 is where I might
// start.
// Obviously when an allocation is taken from a block that block can need to
// be moved between the chains. There is a problem here in that when a
// large block is partly used up leaving another large one it can remain in
// its chain respecting age order. But when it is changed to become a
// small block all information about age will tend to be lost. So I will
// makebe keep a special list of unordered small chunks created as left-overs
// from using parts of large ones and allocate from that first. I hope that
// list will end up short all the time.

// Here are the allocation functions implementing the above.


static inline LispObject packed_get_2_words()
{
    fringe -= 2*CELL;
    if (fringe < heaplimit) get_2_words_past_pin();
    return fringe;
}

static inline LispObject packed_get_n_bytes(size_t n)
{
    n = doubleword_align_up(n);
    if (vheaptop == heapstart) vheaplimit = fringe;
    while (vfringe + n > vheaplimit) get_n_bytes_past_pin();
    LispObject r = vfringe;
    vfringe += n;
    set_header_bit(r, active_page);
    clear_header_bits(r+8, n-8, active_page);
    if (vheaptop == heapstart) heaplimit = vfringe;
    return r;
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

static inline LispObject find_object_start(uintptr_t v, page_header *p)
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
    nilsegment = (LispObject *)malloc(NIL_SEGMENT_SIZE+16);
#ifdef COMMON
    nil = (LispObject)(doubleword_align_up((uintptr_t)nilsegment) +
           TAG_CONS + 8);
#else
    nil = (LispObject)(doubleword_align_up((uintptr_t)nilsegment) +
           TAG_SYMBOL);
#endif
    stacksegment = (LispObject *)malloc(CSL_PAGE_SIZE);
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
    free(nilsegment);
    free(stacksegment);
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   if ((init_flags & INIT_EXPANDABLE) == 0) return false;
    void *page = (void *)malloc((size_t)CSL_PAGE_SIZE);
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

// Given a value I want to see if it could be a pointer into on eof the
// allocated segments. Because there are only 32 of them and if I keep my
// table og segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

static inline int find_segment2(uintptr_t p, int n)
{   if (p < (uintptr_t)heap_segment[n+1]) return n;
    else return n+1;
}

static inline int find_segment4(uintptr_t p, int n)
{   if (p < (uintptr_t)heap_segment[n+2]) return find_segment2(p, n);
    else return find_segment2(p, n+2);
}

static inline int find_segment8(uintptr_t p, int n)
{   if (p < (uintptr_t)heap_segment[n+4]) return find_segment4(p, n);
    else return find_segment4(p, n+4);
}

static inline int find_segment16(uintptr_t p, int n)
{   if (p < (uintptr_t)heap_segment[n+8]) return find_segment8(p, n);
    else return find_segment8(p, n+8);
}

static inline int find_segment32(uintptr_t p, int n)
{   if (p < (uintptr_t)heap_segment[n+16]) return find_segment8(p, n);
    else return find_segment16(p, n+16);
}

int find_heap_segment(uintptr_t p)
{   int n = find_segment32(p, 0);
    if (p < (uintptr_t)heap_segment[n] ||
        p >= (uintptr_t)heap_segment[n] + heap_segment_size[n]) return -1;
    return n;
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

bool volatile already_in_gc, tick_on_gc_exit;
bool volatile interrupt_pending, tick_pending;
LispObject volatile saveheaplimit;
LispObject volatile savevheaplimit;
LispObject * volatile savestacklimit;

static int stop_after_gc = 0;

static size_t trailing_heap_pages_count,
              trailing_vheap_pages_count;

static void copy(LispObject *p)
// This copies the object pointed at by p from the old to the new semi-space,
// and returns a copy to the pointer.  If scans the copied material to copy
// all relevent sub-structures to the new semi-space.
{   char *fr = (char *)fringe, *vfr = (char *)vfringe;
    char *tr_fr = fr, *tr_vfr = vfr;
    void *p1;
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
        LispObject a = *p;
        for (;;)
        {   if (a == nil) break;    // common and cheap enough to test here
            else if (is_immed_or_cons(a))
            {   if (is_cons(a))
                {   LispObject w;
                    w = qcar(a);
                    if (is_forward(w))
                    {   *p = w - TAG_FORWARD + TAG_CONS;
                        break;
                    }
                    fr = fr - sizeof(Cons_Cell);
                    cons_cells += 2*CELL;
// When I am doing regular calculation I leave myself a bunch of spare
// words (size SPARE bytes) so that I can afford to do several cons operations
// between tests.  Here I do careful tests on every step, and so I can
// sail much closer to the wind wrt filling up space.
                    if (fr <= (char *)heaplimit - SPARE + 32)
                    {   char *hl = (char *)heaplimit;
                        void *p;
                        qcar(fr) = SPID_GCMARK;
                        if (pages_count == 0) allocate_more_memory();
                        if (pages_count == 0)
                        {   term_printf("\n+++ Run out of memory\n");
                            ensure_screen();
                            my_exit(EXIT_FAILURE);
                        }
                        p = pages[--pages_count];
                        zero_out(p);
                        new_heap_pages[new_heap_pages_count++] = p;
                        heaplimit = (intptr_t)p;
                        hl = (char *)heaplimit;
                        fr = hl + CSL_PAGE_SIZE - sizeof(Cons_Cell);
                        heaplimit = (LispObject)(hl + SPARE);
                    }
                    qcar(fr) = w;
                    qcdr(fr) = qcdr(a);
                    *p = w = (LispObject)(fr + TAG_CONS);
                    qcar(a) = w + TAG_FORWARD;
                    break;
                }   // end of treatment of CONS
                else break;        // Immediate data drops out here
            }
            else                    // Here I have a symbol or vector
            {   Header h;
                int tag;
                size_t len;
                tag = ((int)a) & TAG_BITS;
                a = (LispObject)((char *)a - tag);
                h = *(Header *)a;
// If the symbol/number/vector has already been copied then its header
// word contains a forwarding address. Re-tag it.
                if (is_forward(h))
                {   *p = h - TAG_FORWARD + tag;
                    break;
                }
                if (tag == TAG_SYMBOL)
                    len = symhdr_length, symbol_heads += symhdr_length;
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
                    if (type_of_header(h) == TYPE_HASH)
                        h = h ^ (TYPE_HASH ^ TYPE_HASHX);
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
                for (;;)
                {   char *vl = (char *)vheaplimit;
                    size_t free = (size_t)(vl - vfr);
// len indicates the length of the block of memory that must now be
// allocated...
                    if (len > free)
                    {   qcar(vfr) = 0;          // sentinel value
                        if (pages_count == 0) allocate_more_memory();
                        if (pages_count == 0)
                        {   term_printf("\n+++ Run out of memory\n");
                            ensure_screen();
                            my_exit(EXIT_FAILURE);
                        }
                        p1 = pages[--pages_count];
                        zero_out(p1);
                        new_vheap_pages[new_vheap_pages_count++] = p1;
                        vfr = (char *)p1 + 8;
                        vl = vfr + (CSL_PAGE_SIZE - 16);
                        vheaplimit = (LispObject)vl;
                        continue;
                    }
                    *p = (LispObject)(vfr + tag);
                    *(LispObject *)a = (LispObject)(vfr + TAG_FORWARD);
                    *(Header *)vfr = h;
// I copy EVERYTHING from the old vector to the new one. By using memcpy
// I can do so with no worry about strict aliasing or the exact type of
// data present. So this will copy across any padder words.
                    memcpy((char *)vfr+CELL, (char *)a+CELL, len-CELL);
                    vfr += len;
                    break;
                }
                break;
            }
        }
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

// I need a way that a thread that is not synchronised with this one can
// generate a Lisp-level interrupt. I achieve that by
// letting that thread reset stacklimit. Then rather soon CSL will
// do a stackcheck() and will call reclaim with type GC_STACK.
//
// call this with
//    arg=0 to have no effect at all (!)   QUERY_INTERRUPT
//    arg=1 for a clock tick event         TICK_INTERRUPT
//    arg=2 for quiet unwind               QUIET_INTERRUPT
//    arg=3 for backtrace.                 NOISY_INTERRUPT
// in each case the previous value of the flag is returned. Note that
// I do not do a "test-and-set" here so do NOT treat this as a proper
// start at a mutex or semaphore! However if I apply a rule that the
// asynchronous (GUI) task only ever sets the flag to a non-zero value
// and only ever tests then to see if it has been reset to zero, while the
// main worker thread only reads it to check for non-zero and then
// resets it I have some degree of sanity.

static volatile int async_type = QUERY_INTERRUPT;

// The following fnction can be called from a signal handler. It just looks
// and and sets some volatile variables.

int async_interrupt(int type)
{   int prev = async_type;
    if (type != QUERY_INTERRUPT)
    {   async_type = type;
        stacklimit = stackbase;
    }
    return prev;
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
{   clock_t t0, t1, t2;
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
    push_clock(); t0 = base_time;
// Life is a bit horrid here. I can have two significantly different sorts of
// thing that cause this soft-GC to happen under FWIN. One is when I am in
// windowed mode and FWIN provokes an asynchronous event for me. The other is
// in non-windowed mode when my software_ticks counter overflows and does
// a somewhat similar job... but from within this worker thread. The really
// bad news is the thought of both of these active together, and so conflict
// and confusion. Fresh and careful thought about that is needed before I
// re-work this code.
//
// In non-windowed mode a problem I have is the detection of ^C interrupts.
// Under Windows I have used SetConsoleMode (and under Unix/Linux tcsetattr)
// to put the input into raw mode if it is direct from a keyboard. Thus
// the operating system will not process ^C for me.
    if (stg_class == GC_STACK && stacklimit == stackbase)
    {   stacklimit = savestacklimit;
        if (tick_pending)
        {   tick_pending = 0;
            heaplimit = saveheaplimit;
            vheaplimit = savevheaplimit;
            stacklimit = savestacklimit;
        }
        already_in_gc = false;
        pop_clock();
// There could, of course, be another async interrupt generated even during
// this processing and certainly by the time I get into interrupted(),
// and there could be "genuine" need for garbage collection or stack overflow
// processing at any stage.
        if (async_type == TICK_INTERRUPT)
        {   long int t = (long int)(100.0 * consolidated_time[0]);
            long int gct = (long int)(100.0 * gc_time);
            async_type = QUERY_INTERRUPT;     // accepted!
            fwin_acknowledge_tick();
#ifndef EMBEDDED
            report_time(t, gct);
#endif
            time_now = (int)consolidated_time[0];
            if ((time_limit >= 0 && time_now > time_limit) ||
                (io_limit >= 0 && io_now > io_limit))
                resource_exceeded();
            return onevalue(p);
        }
// If the user provokes a backtrace then at present I *ALWAYS* make it
// a 100% full one. At some stage I could provide a different menu item
// to deliver a semi-quiet interrupt...
        else if (async_type == NOISY_INTERRUPT)
            miscflags |= BACKTRACE_MSG_BITS;
        else miscflags &= ~BACKTRACE_MSG_BITS;
        async_type = QUERY_INTERRUPT;     // accepted!
        return interrupted(p);
    }
    else
    {   if ((!next_gc_is_hard || stg_class == GC_STACK) &&
            stg_class != GC_USER_HARD &&
            reset_limit_registers(vheap_need, true))
        {   already_in_gc = false;
            pop_clock();
            if (space_limit >= 0 && space_now > space_limit)
                resource_exceeded();
// I have "soft" garbage collections - perhaps fairly frequently. I will
// only call the GC hook function around once every 5 seconds to avoid undue
// overhead in it.
            if (!prev_consolidated_set)
            {   prev_consolidated = consolidated_time[0];
                prev_consolidated_set = 1;
            }
            if (consolidated_time[0] > prev_consolidated + 5.0)
            {   prev_consolidated = consolidated_time[0];
                return use_gchook(p, nil); // Soft GC
            }
            return onevalue(p);
        }
    }
    if (stack >= stacklimit)
    {   if (stacklimit != stackbase)
        {   stacklimit = &stacklimit[50];  // Allow a bit of slack
            pop_clock();
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

    gc_time += pop_clock();
    t2 = base_time;

    if ((verbos_flag & 5) == 5)
// (verbos 4) gets the system to tell me how long each phase of GC took,
// but (verbos 1) must be ORd in too.
    {   trace_printf("Copy %ld ms\n",
                     (long int)(1000.0 *
                                (double)(t2-t0)/(double)CLOCKS_PER_SEC));
    }
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
        tick_on_gc_exit = false;
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


#else // !CONSERVATIVE
LispObject vfringe, vheaplimit;
uintptr_t *C_stackbase;


/*@*/
/*@*///=========================================================================
/*@*///=========================================================================
/*@*/// The code from here down represents the OLD world with a precise garbage
/*@*/// collector. I will keep the code in until the newer conservative collector
/*@*/// is complete and working (or until it turns out that the conservative
/*@*/// version is a mistake and I need to wind back to the previous ideas!)
/*@*///=========================================================================
/*@*///=========================================================================
/*@*/
/*@*/
/*@*/
/*@*/void garbage_collect()
/*@*/{   term_printf("\nGarbage collect here. Not yet implemented\n");
/*@*/    my_abort();
/*@*/}
/*@*/
/*@*/char *big_chunk_start, *big_chunk_end;
/*@*/
/*@*/// the "pages" considered here are of size CSL_PAGE_SIZE
/*@*/
/*@*/void **pages,
/*@*/     **heap_pages,
/*@*/     **vheap_pages;
/*@*/void **new_heap_pages,
/*@*/     **new_vheap_pages;
/*@*/
/*@*/size_t pages_count,
/*@*/       heap_pages_count,
/*@*/       vheap_pages_count,
/*@*/       new_heap_pages_count,
/*@*/       new_vheap_pages_count;
/*@*/
/*@*/void *allocate_page(const char *why)
/*@*/{   if (pages_count == 0) fatal_error(err_no_store);
/*@*/    return pages[--pages_count];
/*@*/}
/*@*/
/*@*/void init_heap_segments(double store_size)
/*@*///
/*@*/// This function just makes nil and the pool of page-frames available.
/*@*/// The store-size is passed in units of Kilobyte, and as a double not
/*@*/// an integer so that overflow is not an issue.
/*@*///
/*@*/{   pages = (void **)malloc(MAX_PAGES*sizeof(void *));
/*@*/    heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
/*@*/    vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
/*@*/    new_heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
/*@*/    new_vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
/*@*/    if (pages == NULL ||
/*@*/        new_heap_pages == NULL ||
/*@*/        new_vheap_pages == NULL ||
/*@*/        heap_pages == NULL ||
/*@*/        vheap_pages == NULL)
/*@*/    {   fatal_error(err_no_store);
/*@*/    }
/*@*/
/*@*/    {   size_t free_space = SIXTY_FOUR_BIT ? 128000000 : 32000000;
/*@*/        size_t request = (size_t)store_size;
/*@*/// By doing this in size_t I should avoid overflow
/*@*/        if (request != 0) free_space = 1024*request;
/*@*/        free_space = free_space/(CSL_PAGE_SIZE+4);
/*@*/        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
/*@*/        pages_count = heap_pages_count = vheap_pages_count = 0;
/*@*/        nilsegment = NULL;
/*@*/        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*CSL_PAGE_SIZE);
/*@*///
/*@*/// I try to get the whole of the initial hunk of memory that I need in
/*@*/// one gulp since that (maybe) gives me the best chance to obtain all
/*@*/// the memory in just one half of my address space.
/*@*///
/*@*/            char *pool = (char *)malloc(n);
/*@*/            if (pool != NULL)
/*@*/            {   big_chunk_start = (char *)pool;
/*@*/                big_chunk_end = big_chunk_start + (n-1);
/*@*/                nilsegment = (LispObject *)pool;
/*@*/                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
/*@*/// NB here that NIL is tagged as a CONS not as a symbol
/*@*/                nil = (LispObject)(
/*@*/                    doubleword_align_up((uintptr_t)nilsegment) + TAG_CONS + 8);
#else
/*@*/                nil = (LispObject)(
/*@*/                    doubleword_align_up((uintptr_t)nilsegment) + TAG_SYMBOL);
#endif
/*@*/// If at the end of the run I am going to free some space I had better not
/*@*/// free these pages. When I free the nilsegment they all get discarded at
/*@*/// once.
/*@*/                while (pages_count < free_space)
/*@*/                {   void *page =
/*@*/// Ha Ha - for some long while I had a bug whereby I missed out the cast
/*@*/// to size_t here and as a result if you asked for over 4G of memory
/*@*/// there was an integer overflow in the subscript calculation leading to
/*@*/// reasonably obscure disaster.
/*@*/                        (void *)&pool[pages_count*
/*@*/                                      (size_t)CSL_PAGE_SIZE];
/*@*/                    pages[pages_count++] = page;
/*@*/                }
/*@*/            }
/*@*/        }
/*@*/    }
/*@*/
/*@*/// If the user had asked for an oversize stack it has to be allocated
/*@*/// independently here anyway.
/*@*/    if (nilsegment != NULL && pages_count > 0)
/*@*/    {   if (stack_segsize != 1)
/*@*/        {   stacksegment =
/*@*/                (LispObject *)malloc(stack_segsize*CSL_PAGE_SIZE);
/*@*/            if (stacksegment == NULL) fatal_error(err_no_store);
/*@*/        }
/*@*/        else stacksegment = (LispObject *)pages[--pages_count];
/*@*/    }
/*@*/    else
/*@*/    {   printf("pages_count <= 0 = %d\n", (int)pages_count);
/*@*/        fatal_error(err_no_store);
/*@*/    }
/*@*/    stackbase = (LispObject *)stacksegment;
/*@*/}
/*@*/
/*@*/static inline bool is_in_big_chunk(void *p)
/*@*/{   return ((char *)p >= big_chunk_start &&
/*@*/            (char *)p <= big_chunk_end);
/*@*/}
/*@*/
/*@*/static void abandon(void *p[], int32_t n)
/*@*/{   while (n != 0)
/*@*/    {   void *w = p[--n];
/*@*/// The test here that avoids calling free on a NULL pointer is
/*@*/// certainly not needed with an ANSI compliant library - but
/*@*/// rumour has it that many Unix libraries are unkind in this
/*@*/// respect, and the test is pretty cheap... Also pages within the
/*@*/// "big chunk" should not be released this way because they will
/*@*/// all be recycled in one go when the whole chunk is freed. Note that
/*@*/// the whole of the "big chunk" tends to get allocated as part of the
/*@*/// segment that contans nil.
/*@*/        if (w != NULL && !is_in_big_chunk(w)) free(w);
/*@*/    }
/*@*/}
/*@*/
/*@*/void drop_heap_segments(void)
/*@*/{   abandon(pages,           pages_count);
/*@*/    abandon(heap_pages,      heap_pages_count);
/*@*/    abandon(vheap_pages,     vheap_pages_count);
/*@*/    if (!is_in_big_chunk(stacksegment)) free(stacksegment);
/*@*/    free(nilsegment);
/*@*/}
/*@*/
/*@*/// This allocates another page of memory if that is allowed and if it is
/*@*/// possible. It returns true on success.
/*@*/
/*@*/bool allocate_more_memory()
/*@*/{   if ((init_flags & INIT_EXPANDABLE) == 0) return false;
/*@*/    void *page = (void *)malloc((size_t)CSL_PAGE_SIZE);
/*@*/    if (page == NULL)
/*@*/    {   init_flags &= ~INIT_EXPANDABLE;
/*@*/        return false;
/*@*/    }
/*@*/    else
/*@*/    {   pages[pages_count++] = page;
/*@*/        return true;
/*@*/    }
/*@*/}
/*@*/
/*@*/void grab_more_memory(size_t npages)
/*@*/{
/*@*/// Here I grab more memory (if I am allowed to).
/*@*/// An initial version here, and one still suitable on machines that will
/*@*/// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
/*@*/// 3*n + 2. This expands until the proportion of the heap active at the
/*@*/// end of garbage collection is less than 1/4.
/*@*/// If the attempt to grab more memory fails I clear the bit in init_flags
/*@*/// that allows me to try to expand, so I will not waste time again.  If
/*@*/// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
/*@*/// available memory may cause a crash) I do not try this operation.  The
/*@*/// aim of keeping the heap less than half full is an heuristic and could be
/*@*/// adjusted on the basis of experience with this code.
/*@*/// On systems where it is possible to measure the amount of available
/*@*/// real memory more sophisticated calculations may be possible.
/*@*/    if (init_flags & INIT_EXPANDABLE)
/*@*/    {   size_t ideal = ok_to_grab_memory(heap_pages_count + vheap_pages_count);
/*@*/        size_t more;
/*@*/        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
/*@*/        if (max_store_size != 0.0)
/*@*/        {   double page_limit = max_store_size*1024*1024/(double)CSL_PAGE_SIZE;
/*@*/// Limit memory to (about) the amount the user indicated with --max-mem
/*@*/            size_t plim = (size_t)page_limit;
/*@*/            if (ideal > plim) ideal = plim;
/*@*/        }
/*@*/        if (ideal > pages_count)
/*@*/        {   more = ideal - pages_count;
/*@*/            while (more > 0)
/*@*/            {   if (!allocate_more_memory()) break;
/*@*/                more--;
/*@*/            }
/*@*/        }
/*@*/    }
/*@*/}
/*@*/
/*@*/
/*@*/// Given a value I want to see if it could be a pointer into on eof the
/*@*/// allocated segments. Because there are only 32 of them and if I keep my
/*@*/// table og segments such that they are sorted on their start address
/*@*/// I can use a binary search which should be pretty fast, with the inline
/*@*/// functions here expected to expand into a direct search tree in the
/*@*/// generated code.
/*@*/
/*@*/static inline int find_segment2(uintptr_t p, int n)
/*@*/{   if (p < (uintptr_t)heap_segment[n+1]) return n;
/*@*/    else return n+1;
/*@*/}
/*@*/
/*@*/static inline int find_segment4(uintptr_t p, int n)
/*@*/{   if (p < (uintptr_t)heap_segment[n+2]) return find_segment2(p, n);
/*@*/    else return find_segment2(p, n+2);
/*@*/}
/*@*/
/*@*/static inline int find_segment8(uintptr_t p, int n)
/*@*/{   if (p < (uintptr_t)heap_segment[n+4]) return find_segment4(p, n);
/*@*/    else return find_segment4(p, n+4);
/*@*/}
/*@*/
/*@*/static inline int find_segment16(uintptr_t p, int n)
/*@*/{   if (p < (uintptr_t)heap_segment[n+8]) return find_segment8(p, n);
/*@*/    else return find_segment8(p, n+8);
/*@*/}
/*@*/
/*@*/static inline int find_segment32(uintptr_t p, int n)
/*@*/{   if (p < (uintptr_t)heap_segment[n+16]) return find_segment8(p, n);
/*@*/    else return find_segment16(p, n+16);
/*@*/}
/*@*/
/*@*/int find_heap_segment(uintptr_t p)
/*@*/{   int n = find_segment32(p, 0);
/*@*/    if (p < (uintptr_t)heap_segment[n] ||
/*@*/        p >= (uintptr_t)heap_segment[n] + heap_segment_size[n]) return -1;
/*@*/    return n;
/*@*/}
/*@*/
/*@*/
/*@*/
/*@*//*****************************************************************************/
/*@*///      Storage allocation.
/*@*//*****************************************************************************/
/*@*/
/*@*/// gc-forcer(a, b) should arrange that a garbage collection is triggered
/*@*/// when at most A cons-sized units of consing happens or when at most
/*@*/// B units of space is used for vectors (where vectors include bignums and
/*@*/// boxed floats). This is intended to be used to trigger garbage collection
/*@*/// with rather fine control over when it happens to help with debugging
/*@*/// storage management issues.
/*@*/
/*@*/bool next_gc_is_hard = false;
/*@*/uint64_t force_cons=0, force_vec = 0;
/*@*/
/*@*/LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
/*@*/{   if (force_cons != 0 || force_vec != 0)
/*@*/        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
/*@*/            force_cons, force_vec);
/*@*/// If you pass a non-fixnum then that leaves the trigger-point unchanged.
/*@*/    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
/*@*/    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
/*@*/    return onevalue(nil);
/*@*/}
/*@*/
/*@*/LispObject Lgc_forcer1(LispObject env, LispObject a)
/*@*/{   return Lgc_forcer(env, a, a);
/*@*/}
/*@*/
/*@*/LispObject cons(LispObject a, LispObject b)
/*@*/{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = b;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(1))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal cons", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject cons_no_gc(LispObject a, LispObject b)
/*@*/{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = b;
/*@*/    fringe = r;
/*@*/    return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.
/*@*/
/*@*/LispObject cons_gc_test(LispObject p)
/*@*/{   if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)fringe <= (char *)heaplimit)
/*@*/        return reclaim(p, "cons gc test", GC_CONS, 0);
/*@*/    else return p;
/*@*/}
/*@*/
/*@*/LispObject ncons(LispObject a)
/*@*/{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(1))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal ncons", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list2(LispObject a, LispObject b)
/*@*/{
/*@*/// Note that building two cons cells at once saves some overhead here
/*@*/    LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(2))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list2", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list2star(LispObject a, LispObject b, LispObject c)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) = c;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(2))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list2*", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list2starrev(LispObject c, LispObject b, LispObject a)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) = c;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(2))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list2*", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) =
/*@*/        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
/*@*/    qcdr((char *)r+2*sizeof(Cons_Cell)) = d;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(3))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list3*", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 4*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) =
/*@*/        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
/*@*/    qcdr((char *)r+2*sizeof(Cons_Cell)) =
/*@*/        (LispObject)((char *)r + 3*sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r +3*sizeof(Cons_Cell)) = d;
/*@*/    qcdr((char *)r + 3*sizeof(Cons_Cell)) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(4))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list4", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/
/*@*/
/*@*/LispObject acons(LispObject a, LispObject b, LispObject c)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
/*@*/    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcdr(r) = c;
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = a;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(2))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal acons", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
/*@*/    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcdr(r) = c;
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = a;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    fringe = r;
/*@*/    return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list3(LispObject a, LispObject b, LispObject c)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) =
/*@*/        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
/*@*/    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(3))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list3", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject list3rev(LispObject c, LispObject b, LispObject a)
/*@*/{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+sizeof(Cons_Cell)) = b;
/*@*/    qcdr((char *)r+sizeof(Cons_Cell)) =
/*@*/        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
/*@*/    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
/*@*/    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(3))
/*@*/        return reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                       "internal list3", GC_CONS, 0);
/*@*/    else return (LispObject)((char *)r + TAG_CONS);
/*@*/}
/*@*/
/*@*/LispObject Lcons(LispObject, LispObject a, LispObject b)
/*@*/{   LispObject r;
/*@*/    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = b;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(1))
/*@*/        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                                "cons", GC_CONS, 0));
/*@*/    else return onevalue((LispObject)((char *)r + TAG_CONS));
/*@*/}
/*@*/
/*@*/LispObject Lxcons(LispObject, LispObject a, LispObject b)
/*@*/{   LispObject r;
/*@*/    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = b;
/*@*/    qcdr(r) = a;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(1))
/*@*/        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                                "xcons", GC_CONS, 0));
/*@*/    else return onevalue((LispObject)((char *)r + TAG_CONS));
/*@*/}
/*@*/
/*@*/LispObject Lnilfn(LispObject)
/*@*/{   return onevalue(nil);
/*@*/}
/*@*/
/*@*/LispObject Lncons(LispObject env, LispObject a)
/*@*/{   LispObject r;
/*@*/    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
/*@*/    qcar(r) = a;
/*@*/    qcdr(r) = nil;
/*@*/    fringe = r;
/*@*/    if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/        (char *)r <= (char *)heaplimit || cons_forced(1))
/*@*/        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
/*@*/                                "ncons", GC_CONS, 0));
/*@*/    else return onevalue((LispObject)((char *)r + TAG_CONS));
/*@*/}
/*@*/
/*@*/LispObject get_symbol(bool gensymp)
/*@*/{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
/*@*/}
/*@*/
/*@*/LispObject get_basic_vector(int tag, int type, size_t size)
/*@*/{
/*@*/// tag is the value (e.g. TAG_VECTOR) that will go in the low order
/*@*/// 3 bits of the pointer result.
/*@*/// type is the code (e.g. TYPE_STRING) that gets packed, together with
/*@*/// the size, into a header word.
/*@*/// size is measured in bytes and must allow space for the header word.
/*@*/// [Note that this last issue - size including the header - was probably
/*@*/// a mistake since the header size depends on whether I am using a
/*@*/// 32-bit or 64-bit representation. However it would be hard to unwind
/*@*/// that now!]
/*@*///
/*@*/    for (;;)
/*@*/    {   char *r = (char *)vfringe;
/*@*/        size_t free = (size_t)((char *)vheaplimit - r);
/*@*/        size_t alloc_size = (size_t)doubleword_align_up(size);
/*@*/// Basic vectors must be smaller then the CSL page size.
/*@*/        if (alloc_size > (CSL_PAGE_SIZE - 32))
/*@*/            aerror1("request for basic vector too big",
/*@*/                    fixnum_of_int(alloc_size/CELL-1));
/*@*/        if (++reclaim_trigger_count == reclaim_trigger_target ||
/*@*/            alloc_size > free || vec_forced(alloc_size/CELL))
/*@*/        {   char msg[40];
/*@*///
/*@*/// I go to a whole load of trouble here to tell the user what sort of
/*@*/// vector request provoked this garbage collection.  I wonder if the user
/*@*/// really cares - but I do very much when I am chasing after GC bugs!
/*@*///
/*@*/            switch (tag)
/*@*/            {   case TAG_SYMBOL:
/*@*/                    sprintf(msg, "symbol header");
/*@*/                    break;
/*@*/                case TAG_NUMBERS:
/*@*/                    switch (type)
/*@*/                    {   case TYPE_BIGNUM:
/*@*/                            sprintf(msg, "bignum(%ld)", (long)size);
/*@*/                            break;
/*@*/                        default:
/*@*/                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
/*@*/                            break;
/*@*/                    }
/*@*/                    break;
/*@*/                case TAG_VECTOR:
/*@*/                    switch (type)
/*@*/                    {
/*@*/                        case TYPE_STRING_1:
/*@*/                        case TYPE_STRING_2:
/*@*/                        case TYPE_STRING_3:
/*@*/                        case TYPE_STRING_4:
/*@*/                            sprintf(msg, "string(%ld)", (long)size);
/*@*/                            break;
/*@*/                        case TYPE_BPS_1:
/*@*/                        case TYPE_BPS_2:
/*@*/                        case TYPE_BPS_3:
/*@*/                        case TYPE_BPS_4:
/*@*/                            sprintf(msg, "BPS(%ld)", (long)size);
/*@*/                            break;
/*@*/                        case TYPE_SIMPLE_VEC:
/*@*/                            sprintf(msg, "simple vector(%ld)", (long)size);
/*@*/                            break;
/*@*/                        case TYPE_HASH:
/*@*/                            sprintf(msg, "hash table(%ld)", (long)size);
/*@*/                            break;
/*@*/                        default:
/*@*/                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
/*@*/                            break;
/*@*/                    }
/*@*/                    break;
/*@*/                case TAG_BOXFLOAT:
/*@*/                    sprintf(msg, "float(%ld)", (long)size);
/*@*/                    break;
/*@*/                default:
/*@*/                    sprintf(msg, "get_basic_vector(%lx,%ld)", (long)tag, (long)size);
/*@*/                    break;
/*@*/            }
/*@*/            reclaim(nil, msg, GC_VEC, alloc_size);
/*@*/// Note the CONTINUE here so that I go and repeat the test. Consider the
/*@*/// case where I have a page almost full but then garbage collection recovers
/*@*/// a lof of space but still leaves the final used page almost full... I
/*@*/// need the garbage collector to take care with its final argument to be
/*@*/// certain that the loop here terminates!
/*@*/            continue;
/*@*/        }
/*@*/        vfringe = (LispObject)(r + alloc_size);
/*@*/        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
/*@*///
/*@*/// DANGER: the vector allocated here is left uninitialised at this stage.
/*@*/// This is OK if the vector will contain binary information, but if it
/*@*/// will hold any LispObjects it needs safe values put in PDQ.
/*@*///
/*@*/// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
/*@*/// a vector that will not end up being a multipe of 8 bytes long naturally
/*@*/// gets padded out. Here I arrange to zero out any such padder word. This
/*@*/// should not be very important since nobody should ever try to use that
/*@*/// word. When the garbage collector copies material around it transcribes
/*@*/// the whole vector (including the padder), but it should never try to trace
/*@*/// through it. By tidying this up here can feel that I do not have any
/*@*/// need to worry about it elsewhere.
/*@*/        if (!SIXTY_FOUR_BIT && alloc_size != size)
/*@*/            *(LispObject *)(vfringe-CELL) = 0;
/*@*/        return (LispObject)(r + tag);
/*@*/    }
/*@*/}
/*@*/
/*@*/// This takes a vector (which can be one represented using an INDEXVEC)
/*@*/// and reduces its size to a total value len. It returns the shorter
/*@*/// vector. Only used on simple vectors.
/*@*/
/*@*/LispObject reduce_basic_vector_size(LispObject v, size_t len)
/*@*/{   vechdr(v) = TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED;
/*@*/    return v;
/*@*/}
/*@*/
/*@*/// The next functions (eg borrow_vector) are called just like the
/*@*/// functions that allocate new vectors, but they use space in the part
/*@*/// of memory space not at present in use by the garbage collector. If a
/*@*/// copying garbage collection triggered "right now" were to be able to
/*@*/// succeed there must be enough reserved space to make this possible provided
/*@*/// I only borrow space sufficient to make copies of existing live data.
/*@*/// One must NEVER garbage collect while space has been borrowed in this
/*@*/// way. At present this scheme is only ever used while rehashing hash
/*@*/// tables.
/*@*/
/*@*/static size_t borrowed_pages_count;
/*@*/static LispObject borrowed_vfringe, borrowed_vheaplimit;
/*@*/
/*@*/static void get_borrowed_page()
/*@*/{   if (borrowed_pages_count == 0)
/*@*/    {   trace_printf("\nRun out of memory (for rehashing)\n");
/*@*/#ifdef DEBUG
/*@*/        my_abort();
/*@*/#endif
/*@*/        Lstop1(nil, fixnum_of_int(1));
/*@*/    }
/*@*/    void *p = pages[--borrowed_pages_count];
/*@*/    zero_out(p);
/*@*/    borrowed_vfringe =
/*@*/        (LispObject)((char *)doubleword_align_up((intptr_t)p) + 8);
/*@*/    borrowed_vheaplimit =
/*@*/        (LispObject)((char *)borrowed_vfringe + (CSL_PAGE_SIZE-16));
/*@*/}
/*@*/
/*@*/void prepare_for_borrowing()
/*@*/{   borrowed_pages_count = pages_count;
/*@*/    get_borrowed_page();
/*@*/}
/*@*/
/*@*/LispObject borrow_basic_vector(int tag, int type, size_t size)
/*@*/{   for (;;)
/*@*/    {   char *r = (char *)borrowed_vfringe;
/*@*/        size_t free = (size_t)((char *)borrowed_vheaplimit - r);
/*@*/        size_t alloc_size = (size_t)doubleword_align_up(size);
/*@*/        if (alloc_size > free)
/*@*/        {   get_borrowed_page();
/*@*/            continue;
/*@*/        }
/*@*/        borrowed_vfringe = (LispObject)(r + alloc_size);
/*@*/        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
/*@*/        if (!SIXTY_FOUR_BIT && alloc_size != size)
/*@*/            *(LispObject *)(borrowed_vfringe-CELL) = 0;
/*@*/        return (LispObject)(r + tag);
/*@*/    }
/*@*/}
/*@*/
/*@*/LispObject borrow_vector(int tag, int type, size_t n)
/*@*/{   LispObject v;
/*@*/    if (n-CELL > VECTOR_CHUNK_BYTES)
/*@*/    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
/*@*/        size_t i;
/*@*/        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
/*@*/        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
/*@*/        v = borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
/*@*/        for (i=0; i<chunks; i++)
/*@*/            basic_elt(v, i) = nil;
/*@*/        for (i=0; i<chunks; i++)
/*@*/        {   LispObject v1;
/*@*/            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
/*@*/            push(v);
/*@*/            v1 = borrow_basic_vector(tag, type, k+CELL);
/*@*/            pop(v);
/*@*/            size_t k1 = k/CELL;
/*@*/            for (size_t j=0; j<k1; j++)
/*@*/                basic_elt(v1, j) = nil;
/*@*/            basic_elt(v, i) = v1;
/*@*/        }
/*@*/    }
/*@*/    else v = borrow_basic_vector(tag, type, n);
/*@*/    return v;
/*@*/}
/*@*/
/*@*/
#endif // !CONSERVATIVE

// end of allocate.cpp
