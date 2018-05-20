// allocate.cpp                            Copyright (C) 1989-2018 Codemist    

//
// Code to do with storage allocation
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
#ifdef HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_sigaction = low_level_signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK | SA_NODEFER;
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
// parts of memory have been updated.
// I try to pack the bitsmaps for small(ish) pages into a single vector
// heap_small_bitmaps. Once the bitmaps get to be at least 0x10000 byte in
// size they just get added to the size of memory block allocated for a
// segment (and that has to happen once heap_small_bitmaps is full).

// For memory protection purposes the granularity of pages will vary from
// system to system, but I want to have a range of sizes that I view as
// acceptable. Well here it is - pages can be as amall as 4096 bytes
// or as large as 64K.

#define MIN_PAGE_SIZE 0x01000
#define MAX_PAGE_SIZE 0x10000

size_t page_size;

void *heap_segment[32];
uintptr_t heap_segment_size[32];
// I will arrange my bitmap in 64-bit words - expecting that memory access
// to 64-bits when I update an entry ias as cheap as anything else, but then
// scanning for nonzero bits can go 64-bits as a time.
uint64_t *heap_dirty_pages_bitmap[32];
int heap_segment_count = 0;
// I have a simple fixed bitmap region of size MAX_PAGE_SIZE bytes (ie 64K)
// here.
#define SMALL_BITMAP_SIZE (MAX_PAGE_SIZE/sizeof(uint64_t))
uint64_t heap_small_bitmaps[SMALL_BITMAP_SIZE+1];
uint64_t *heap_small_bitmaps_ptr = &heap_small_bitmaps[SMALL_BITMAP_SIZE];

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
// calling mprotect.

bool mprotect_valid = true;

void *allocate_segment(size_t n)
{
// I will round up the size to allocate so it is a multiple of the
// system page size. Well I expect that in any sensible calls to
// this function that requested size will already be nicely rounded,
// but this is cheap and adds to safety.
    n = (n + page_size - 1) & -page_size;
    size_t map_size = n/page_size; // number of bits of map needed
// Round up map_size to be a multiple of sizeof(unit64_t)
    map_size = (n + sizeof(uint64_t) - 1) / sizeof(uint64_t);
// Where possible I allocate map space within the small bitmap block, working
// down from the top. I leave map_ptr NULL if this is not possible, otherwise
// it identified the location within the block;
    size_t extra = 0;
    uint64_t *map_ptr;
    if (map_size >= (size_t)(heap_small_bitmaps_ptr - heap_small_bitmaps))
    {   map_ptr = NULL;
// The map will need to go at the end of the newly allocated block... I
// sort out how much space that will use.
        extra = (map_size*sizeof(uint64_t) + page_size - 1) & -page_size;
    }
    else map_ptr = heap_small_bitmaps_ptr - map_size;
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
    void *r = mmap(0, n+extra, PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    bool failed = (r = MAP_FAILED);
#else // !MAP_ANONYMOUS
    int fd = open("/dev/zero", O_RDWR);
    void *r = mmap(0, n+extra, PROT_READ, MAP_PRIVATE, fd, 0);
    bool failed = (r = MAP_FAILED);
    close(fd);
#endif // !MAP_ANONYMOUS
// If there was a chunk of the memory that was to be used for a bitmap then
// make that read-write now, because it is updated from within the exception
// handler for SIGSEGV and I really do not want it to trigger a further
// exception when touched. What is more the bitmap is large enough to cover
// the "real" memory allocated, but not itself, so an exception caused by
// accessing the bitmap could lead to a further memory access out of bounds.
    if (!failed && extra != 0)
    {   mprotect_valid = false;
        if (mprotect((void *)((char *)r + n), extra,
                     PROT_READ|PROT_WRITE) == -1) failed = true;
        mprotect_valid = true;
    }
#endif // !WIN32
    if (failed) return NULL;
    if (map_ptr != NULL) heap_small_bitmaps_ptr = map_ptr;
    else map_ptr = (uint64_t*)((char *)r + n);
    heap_segment[heap_segment_count] = r;
    heap_dirty_pages_bitmap[heap_segment_count] = map_ptr;
// Note that the recorded size here does not include any appended bitmap.
    heap_segment_size[heap_segment_count] = n;
    heap_segment_count++;
    return r;
}

// The bitmap associated with each big segment of memory can be
// set to zero using clear_bitmap() and on Windows it is necessary to
// call refresh_bitmap to fill it in before interrogating it. The
// clear_bitmap function will leave things so that any subsequent writes
// to the memory concerned will be collected for use following the
// next refresh_bitmap().
// Returns true on success.

bool clear_bitmap(int h)
{   size_t n = heap_segment_size[h]/page_size; // measured in bits
    n = (n + 7) & -(size_t)8;                  // now in bytes
    memset(heap_dirty_pages_bitmap[h], 0, n);  // clear the map
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
            non_atomic_set_bit(heap_dirty_pages_bitmap[h], page_offset);
        }
        base += amount_to_scan;
    }
#endif // !WIN32
    return true;
}

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
            while (spin_lock.test_and_set(std::memory_order_acquire)) {}
            int rc = mprotect(addr, CELL, PROT_READ | PROT_WRITE);
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
            atomic_set_bit(heap_dirty_pages_bitmap[h], page_offset);
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
#ifdef CONSERVATIVE
    page_map = (page_map_t *)malloc(MAX_PAGES*sizeof(page_map_t));
#endif
    heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    if (pages == NULL ||
#ifdef CONSERVATIVE
        page_map == NULL ||
#endif
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

LispObject get_basic_vector(int tag, int type, size_t size)
{
//
// tag is the value (e.g. TAG_SYMBOL) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_SYMBOL) that gets packed, together with
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


// end of allocate.cpp
