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
//      content evacuated - that process representing a minor garbage collection.
//   Stable (S). When live material is moved out of an "old recent" page it is
//      copied into the stable region. This will come to be the bulk of the
//      active heap and uses as many pages as are called for. At any one time
//      one of these pages will be the "stable fringe" where new material is
//      added. In a multi-thread world there is just a single pool of stable
//      heap.
//   Free (F). Pages that are not in use are in this group. When a minor garbage
//      collection places in a fresh stable page such that |S| > |F| then a full
//      garbage collection is triggered. At that stage R is empty. The stable
//      fringe page is then deemed part of what will become the new heap, and
//      all material apart from that is copied into that and subsequent pages
//      taken from free. The vacated pages are then re-labelled to form the
//      new free region. While doing this the current page does not have
//      its content relocated.
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
// to. Because subsequent memory access is unimpeded I expect this will have low
// overhead. Memory protection is performed at a granularity substantially
// smaller then the size of whole pages. My expectation is that almost all
// writes to memory will be in either C or in symbol headers. Symbol headers will
// be distributed across S, but I can imagine arranging that the major
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
// I will arrange my bitmap in 64-bit words - expecting that memory access
// to 64-bits when I update an entry ias as cheap as anything else, but then
// scanning for nonzero bits can go 64-bits as a time.
uint64_t *heap_dirty_pages_bitmap_1[32];
uint64_t *heap_dirty_pages_bitmap_2[32];
int heap_segment_count = 0;
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

// THis code allocates a segment by asking the operating system. On
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
    heap_segment_count++;
// Now I need to arrange that the segments are sorted in the tables
// that record them.
    for (int i=heap_segment_count-1; i!=0; i--)
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
    return r;
}

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

// Now let me start to talk about the arrangement within a "page" (which
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
//     fringe               )
//     heaplimit            )
//     next-fringe    )
//     -              )
//     [object start bitmap]
//     [pin bitmap]
//     start of used data
//     ... used
//     end of used data <----------- fringe
//     ... free
//     end of available space <----- heaplimit
//     ... pinned data
//     next-heaplimit
//     next'-fringe  <-------------- next' fringe
//     ... free
//     ... <------------------------ next heaplimit
//     <end of page>
//
// The idea is that the whole page can be interrupted if "pinned" items
// are present within it. These are items that were referenced from an
// ambiguous base during a previous garbage collection and so which can not
// be moved - fresh allocation has to work around them. So the space available
// in the page is made up of a series of chunks. During allocation chunks
// are used from the low address upwards, and vfringe/vheaplimit show where
// allocation can happen and its limit. The chunks will be kept in a free
// chain: the first two words of each chunk hold first the end-point of that
// chunk and then the start of the next one. If the chunnk is the last one of
// the poge then its successor can be given as NULL.
// While CSL is running the chaining from the current chunk will have been
// overwritten when the first vector is allocated in that chunk. So it
// will be necessary (and indeed reasonable) to store vfringe, vheaplimit and
// next_vfringe in (static or extern) variables. Now supposing there are
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
// The second sort of page is used for storage of "small" items. When I
// started planning this scheme I had first intended to arrange that the
// "small" page would hold 2-word items at one end and 4-word ones at the
// other. The reasoning was that 2-word items would cover CONS cells and
// at least on a 64-bit system boxed double-floats and strings with up to 8
// characters, while 4-word items would be good for somewhat longer strings
// and fairly significan bignums. But having instrumented CSL and checked
// what happened when the full set of Reduce tests were run I saw there
// that allocating 4-word items was happening around 0.5% as frequently as
// 2-word ones (on a 64-bit platform). In a 32-bit world the ratio was a
// little over 1%. So if making special privision for 4-word items could have
// any impact at all on the cost of CONS it would be a bad idea. I then
// looked at the allocation of vectors. On the 32-bit system about 37% of
// allocations were for items of size 4 words, but on a 64-bit system this
// dropped to only 14%. I attribute this difference to the fact that on a
// 64-bit system floats and strings of length up to 8 end up in the
// 2-word region. Especially if I view 64-bits as much more important for the
// future than 32-bits this suggests that special treatment of 4-word items is
// not worthwhile.
// The layout for such a page is just the same as that for vector pages
// except that the "object start" bitmap is not needed and so not present,
// and so a few more bytes of memory are available for storing data.

LispObject fringe, next_fringe;
LispObject heaplimit;
LispObject vfringe, next_vfringe;
LispObject vheaplimit;

// A bitmap that covers a page has to have a size (in bytes) that allows for
// 8 bits in each byte and that covers the page at a granularity of 2*CELL.

#define PAGE_BITMAP_SIZE (CSL_PAGE_SIZE/(2*CELL)/8)

// These structures show how a page is laid out. Every so often I will
// cast a reference to a page to be a reference to this structure.

typedef struct page_header_
{   uintptr_t page_type;
    uintptr_t page_chain;

    uintptr_t fringe;
    uintptr_t heaplimit;

    uintptr_t next_fringe;
    uintptr_t padding;

// Ha ha. The bitmap as impleme4nted here has bits in it that cover
// all the page header (including itself) and that is a waste. But it is
// such a small one that I propose not to worry myself!

    uint64_t objectstart_bitmap[PAGE_BITMAP_SIZE/sizeof(uint64_t)];
    uint64_t pinned_bitmap[PAGE_BITMAP_SIZE/sizeof(uint64_t)];

    LispObject data[1];
} page_header;

// Test if a pointer (p) points at an object header.

static inline bool is_header_address(Header *p, page_header *page)
{   uintptr_t offset = (char *)p - (char *)page;
// If the putative pointer refers to parts of the header that are before
// any useful data (for instance it refers into the bitmap) or if it points
// beyond the end of the page it is not valid.
    if (offset < offsetof(page_header, data) ||
        offset >= page->fringe) return false;
// The bitmap will have one bit for every 2 CELLS...
    offset /= 2*CELL;
// ... and it stores 64 bits of information in each uint64_t entry.
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
// A header is signified by having a 1 in the bitmap.
    return (page->objectstart_bitmap[n] & bit) == 1;
}

// When I set or clear bits that mark an object header I will only do so
// with addresses that are validly in-range.

static inline void set_header_bit(LispObject p, page_header *page)
{   size_t offset = (p - (LispObject)page)/(2*CELL);
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->objectstart_bitmap[n] |= bit;
}

static inline void clear_header_bit(LispObject p, page_header *page)
{   size_t offset = (p - (LispObject)page)/(2*CELL);
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->objectstart_bitmap[n] &= ~bit;
}

static inline void clear_header_bits(LispObject p, size_t n, page_header *page)
{
// This is not yet coded properly! I want to use word-at-a-time operations to
// clear multiple bits. But working one entry at a time should yield correct
// results, just not the best possible performance.
    while (n != 0)
    {   clear_header_bit(p, page);
        p += 2*CELL;
        n -= 2*CELL;
    }
//  size_t offset = (p - (LispObject)page)/(2*CELL);
//  size_t n = offset/64;
//  uint64_t bit = ((uint64_t)1)<<(offset%64);
//  page->objectstart_bitmap[n] &= ~bit;
}

static inline bool is_pinned(LispObject p, page_header *page)
{   size_t offset = p - (LispObject)page;
// If the putative pointer refers to parts of the header that are before
// any useful data (for instance it refers into the bitmap) or if it points
// beyond the end of the page it is not valid.
    if (offset < offsetof(page_header, data) ||
        offset >= page->fringe) return false;
    offset /= 2*CELL;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    return (page->pinned_bitmap[n] & bit) != 0;
}

static inline void set_pinned(LispObject p, page_header *page)
{   size_t offset = p - (LispObject)page;
    offset /= 2*CELL;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->pinned_bitmap[n] |= bit;
}

static inline void clear_pinned(LispObject p, page_header *page)
{   size_t offset = p - (LispObject)page;
    offset /= 2*CELL;
    size_t n = offset/64;
    uint64_t bit = ((uint64_t)1)<<(offset%64);
    page->pinned_bitmap[n] &= ~bit;
}

// Provide the kernel of the allocation code...

LispObject get_2_words()
{
// If there is a free doubleword immediatly available then use it. I very
// much hope that this will be the situation almost all of the time.
    if (fringe < heaplimit)
    {   LispObject r = fringe;
        fringe += 2*CELL;
        return r;
    }
// If I am at the end of one segment of free space but there is another
// in the current page then merely move on to the next segment. Because
// it will be non-empry (otherwise it would not have been a "free segment"!)
// I do not need to check further, but can just use the first doubeword in
// it.
    if (next_fringe != 0)
    {   LispObject r = next_fringe;
        heaplimit = ((LispObject *)r)[0];
        next_fringe = ((LispObject *)r)[1];
        fringe = r + 2*CELL;
        return r;
    }
// Now I have the more complex situation where the current page is full.
// I need to garbage collect. In the code I am writing here I am assuming
// a conservative garbage collector, so I do not need to do anything special
// here about preserving values. After garbage collection it will be certain
// that memory is available.
    garbage_collect();
    LispObject r = fringe;
    fringe += 2*CELL;
    return r;
}

LispObject get_n_words(size_t n)
{   LispObject r = fringe;
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


uintptr_t *C_stackbase, *C_stacktop;

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
#ifdef SOMETIME
// References into the "current" page will not be treated as cause for
// pinning. That is because I expect that there will be quite a few references
// into that page on the stack and that would lead to many pinned items.
// 
        if (seg == C) continue;
#endif
// Now I know which memory segment the potential pointer was within. The
// segment was divided up into pages each of size CSL_PAGE_SIZE so I can now
// sort out which of those is involved.
        uintptr_t off = (char *)v - (char *)seg;
        uintptr_t pagenum = off/CSL_PAGE_SIZE;
        page_header *p = (page_header *)((char *)seg + CSL_PAGE_SIZE*pagenum);
// Now p points to the start of a page that the pointer seems to address.
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


#ifndef ALLOCTEST

void garbage_collect()
{   term_printf("\nGarbage collect here. Not yet implemented\n");
    my_abort();
}

char *big_chunk_start, *big_chunk_end;

// the "pages" considered here are of size CSL_PAGE_SIZE

void **pages,
     **heap_pages,
     **vheap_pages;
void **new_heap_pages,
     **new_vheap_pages;

size_t pages_count,
       heap_pages_count,
       vheap_pages_count,
       new_heap_pages_count,
       new_vheap_pages_count;

void *allocate_page(const char *why)
{   if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

void init_heap_segments(double store_size)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
//
{   const char *memfile = "memory.use"; // For memory statistics etc
    pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    if (pages == NULL ||
        new_heap_pages == NULL ||
        new_vheap_pages == NULL ||
        heap_pages == NULL ||
        vheap_pages == NULL)
    {   fatal_error(err_no_store);
    }

    {   size_t free_space = SIXTY_FOUR_BIT ? 128000000 : 32000000;
        size_t request = (size_t)store_size;
// By doing this in size_t I should avoid overflow
        if (request != 0) free_space = 1024*request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count = 0;
        nilsegment = NULL;
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*CSL_PAGE_SIZE);
//
// I try to get the whole of the initial hunk of memory that I need in
// one gulp since that (maybe) gives me the best chance to obtain all
// the memory in just one half of my address space.
//
            char *pool = (char *)malloc(n);
            if (pool != NULL)
            {   big_chunk_start = (char *)pool;
                big_chunk_end = big_chunk_start + (n-1);
                nilsegment = (LispObject *)pool;
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
// NB here that NIL is tagged as a CONS not as a symbol
                nil = (LispObject)(
                    doubleword_align_up((uintptr_t)nilsegment) + TAG_CONS + 8);
#else
                nil = (LispObject)(
                    doubleword_align_up((uintptr_t)nilsegment) + TAG_SYMBOL);
#endif
// If at the end of the run I am going to free some space I had better not
// free these pages. When I free the nilsegment they all get discarded at
// once.
                while (pages_count < free_space)
                {   void *page =
// Ha Ha - for some long while I had a bug whereby I missed out the cast
// to size_t here and as a result if you asked for over 4G of memory
// there was an integer overflow in the subscript calculation leading to
// reasonably obscure disaster.
                        (void *)&pool[pages_count*
                                      (size_t)CSL_PAGE_SIZE];
                    pages[pages_count++] = page;
                }
            }
        }
    }

// If the user had asked for an oversize stack it has to be allocated
// independently here anyway.
    if (nilsegment != NULL && pages_count > 0)
    {   if (stack_segsize != 1)
        {   stacksegment =
                (LispObject *)malloc(stack_segsize*CSL_PAGE_SIZE);
            if (stacksegment == NULL) fatal_error(err_no_store);
        }
        else stacksegment = (LispObject *)pages[--pages_count];
    }
    else
    {   printf("pages_count <= 0 = %d\n", (int)pages_count);
        fatal_error(err_no_store);
    }
    CSL_MD5_Update((unsigned char *)memfile, 8);
    stackbase = (LispObject *)stacksegment;
}

static inline bool is_in_big_chunk(void *p)
{   return ((char *)p >= big_chunk_start &&
            (char *)p <= big_chunk_end);
}

static void abandon(void *p[], int32_t n)
{   while (n != 0)
    {   void *w = p[--n];
// The test here that avoids calling free on a NULL pointer is
// certainly not needed with an ANSI compliant library - but
// rumour has it that many Unix libraries are unkind in this
// respect, and the test is pretty cheap... Also pages within the
// "big chunk" should not be released this way because they will
// all be recycled in one go when the whole chunk is freed. Note that
// the whole of the "big chunk" tends to get allocated as part of the
// segment that contans nil.
        if (w != NULL && !is_in_big_chunk(w)) free(w);
    }
}

void drop_heap_segments(void)
{   abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
    if (!is_in_big_chunk(stacksegment)) free(stacksegment);
    free(nilsegment);
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

#endif // !ALLOCTEST

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


#ifndef ALLOCTEST

/*****************************************************************************/
//      Storage allocation.
/*****************************************************************************/

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
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal cons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject cons_no_gc(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.

LispObject cons_gc_test(LispObject p)
{   if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)fringe <= (char *)heaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal ncons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2(LispObject a, LispObject b)
{
// Note that building two cons cells at once saves some overhead here
    LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = d;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 4*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 3*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r +3*sizeof(Cons_Cell)) = d;
    qcdr((char *)r + 3*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(4))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list4", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}



LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal acons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "cons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = b;
    qcdr(r) = a;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "xcons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

LispObject Lncons(LispObject env, LispObject a)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "ncons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
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
    for (;;)
    {   char *r = (char *)vfringe;
        size_t free = (size_t)((char *)vheaplimit - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
        if (alloc_size > (CSL_PAGE_SIZE - 32))
            aerror1("request for basic vector too big",
                    fixnum_of_int(alloc_size/CELL-1));
        if (++reclaim_trigger_count == reclaim_trigger_target ||
            alloc_size > free || vec_forced(alloc_size/CELL))
        {   char msg[40];
//
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
//
            switch (tag)
            {   case TAG_SYMBOL:
                    sprintf(msg, "symbol header");
                    break;
                case TAG_NUMBERS:
                    switch (type)
                    {   case TYPE_BIGNUM:
                            sprintf(msg, "bignum(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_VECTOR:
                    switch (type)
                    {
                        case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
                            sprintf(msg, "string(%ld)", (long)size);
                            break;
                        case TYPE_BPS_1:
                        case TYPE_BPS_2:
                        case TYPE_BPS_3:
                        case TYPE_BPS_4:
                            sprintf(msg, "BPS(%ld)", (long)size);
                            break;
                        case TYPE_SIMPLE_VEC:
                            sprintf(msg, "simple vector(%ld)", (long)size);
                            break;
                        case TYPE_HASH:
                            sprintf(msg, "hash table(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_BOXFLOAT:
                    sprintf(msg, "float(%ld)", (long)size);
                    break;
                default:
                    sprintf(msg, "get_basic_vector(%lx,%ld)", (long)tag, (long)size);
                    break;
            }
            reclaim(nil, msg, GC_VEC, alloc_size);
// Note the CONTINUE here so that I go and repeat the test. Consider the
// case where I have a page almost full but then garbage collection recovers
// a lof of space but still leaves the final used page almost full... I
// need the garbage collector to take care with its final argument to be
// certain that the loop here terminates!
            continue;
        }
        vfringe = (LispObject)(r + alloc_size);
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multipe of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(vfringe-CELL) = 0;
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

static size_t borrowed_pages_count;
static LispObject borrowed_vfringe, borrowed_vheaplimit;

static void get_borrowed_page()
{   if (borrowed_pages_count == 0)
    {   trace_printf("\nRun out of memory (for rehashing)\n");
#ifdef DEBUG
        my_abort();
#endif
        Lstop1(nil, fixnum_of_int(1));
    }
    void *p = pages[--borrowed_pages_count];
    zero_out(p);
    borrowed_vfringe =
        (LispObject)((char *)doubleword_align_up((intptr_t)p) + 8);
    borrowed_vheaplimit =
        (LispObject)((char *)borrowed_vfringe + (CSL_PAGE_SIZE-16));    
}

void prepare_for_borrowing()
{   borrowed_pages_count = pages_count; 
    get_borrowed_page();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   for (;;)
    {   char *r = (char *)borrowed_vfringe;
        size_t free = (size_t)((char *)borrowed_vheaplimit - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
        if (alloc_size > free)
        {   get_borrowed_page();
            continue;
        }
        borrowed_vfringe = (LispObject)(r + alloc_size);
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(borrowed_vfringe-CELL) = 0;
        return (LispObject)(r + tag);
    }
}

LispObject borrow_vector(int tag, int type, size_t n)
{   LispObject v;
    if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        size_t i;
        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
        v = borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (i=0; i<chunks; i++)
            basic_elt(v, i) = nil;
        for (i=0; i<chunks; i++)
        {   LispObject v1;
            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
            push(v);
            v1 = borrow_basic_vector(tag, type, k+CELL);
            pop(v);
            size_t k1 = k/CELL;
            for (size_t j=0; j<k1; j++)
                basic_elt(v1, j) = nil;
            basic_elt(v, i) = v1;
        }
    }
    else v = borrow_basic_vector(tag, type, n);
    return v;
}

#endif // !ALLOCTEST

// end of allocate.cpp
