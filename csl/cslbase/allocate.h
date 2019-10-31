// allocate.h                             Copyright (C) Codemist, 1990-2019


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

#ifndef header_allocate_h
#define header_allocate_h 1

// The variations guarded by "#if defined" here represent an experiment so
// that I can assess the level of extra costs that various ways of supporting
// CONS in a threaded world might incur. By dafault one gets the original
// simple version.
//
// The options are:
//  (1) Make fringe and limit registers thread_local. Then each thread would
//      have its own "nursery" area. The code as inserted here does not have
//      and extra support for the inter-thread synchronization that would
//      be needed when a nursery area became full.
//  (2) On Windows using gcc the costs of thread_local access are severe when
//      using C++ facilities. So there us code that uses the Windows native
//      thread local support API. To help speed yet further the key access
//      functions are re-implemented with a line or two of assembly code and
//      inline functions. This version also uses std::atomic<T> access for
//      the limit registers which would make it possible to have officially
//      correct inter-thread communication via them.
//  (3) Use of a std::atomic<T> value for the fringe so that a fetch_add()
//      operation on it can allocate store within a single heap segment in
//      such a way that if multiple theads all try to allocate at once
//      all remains safe. As coded here this is not actually safe because
//      I write data into the supposedly allocated region of memory before
//      checking if it overflowed the heap region. With just one thread this
//      is OK provided I ensure I have a few words spare, but with multiple
//      threads it would be a problem! In the code here I also use
//      std::atomic<T> for the limit register and so communication between
//      threads using it will be safe.
//  (4) Baseline code - which is what will apply unless some special pre-
//      processor symbol is defined - that uses simple C++ variables. This is
//      a very small modification and clean-up of the code used in CSL at
//      earlier times and provides something to compare the other varients
//      against.
//
// I have tried Reduce built with each of these options. In each case I ran
// the test script "susy2.tst". That test was selected because it runs for
// a noticable amount of time and turns over a fair amount of memory.
// The results I way on Windows 10 using cygwin where
//       baseline:            4.982      -
//       simple C++ threads: 13.625      THREAD_LOCAL
//       win32 thread API:    5.015      WINDOWS_THREADS
//       atomic fetch_add:    5.515      ATOMIC
// Then a similar test using defint.tst
//       baseline:           15.688
//       simple C++ threads: 33.906
//       win32 thread API:   15.704 
//       atomic fetch_add:   16.469
// These figures are intended to show the overheads of the various options
// in context. On Linux the cost of C++ thread-local is minimal and on the
// Macintosh it is modest. 
//
// The message I take from this is that on a x86_64 (and I believe that
// aarch64 figures are in line) use of C++ thread-local on Linus but the
// uglier Windows-special code on Cygwin/Mingw32 has really low overhead,
// but would demand multiple nursery regions. Use of std::atomic::fetch_add
// looks attractive but has a high local cost leading to a system-wide
// slow-down by around 10%. The naive use of C++ thread-local is obviously
// unacceptable, and I think I feel that if a change in CONS just to use
// std::atomic::fetch_add slows the whole system down by enough to measure
// easily in these tests I should avoid it.... it is very probable that
// in pathological cases it could lead to really dramatic slow-down.

#if defined THREAD_LOCAL

inline thread_local std::uintptr_t fringe;
inline thread_local std::uintptr_t heaplimit;
inline thread_local std::uintptr_t vfringe;
inline thread_local std::uintptr_t vheaplimit;

#elif defined WINDOWS_THREADS && defined WIN32

const inline int fringe_slot = TlsAlloc();
const inline int heaplimit_slot = TlsAlloc();
const inline int vfringe_slot = TlsAlloc();
const inline int vheaplimit_slot = TlsAlloc();
inline thread_local std::atomic<std::uintptr_t> real_heaplimit;
inline thread_local std::atomic<std::uintptr_t> real_vheaplimit;

class ForFringe
{
public:
    operator std::uintptr_t()
    {   return (std::uintptr_t)TlsGetValue(fringe_slot);
    };
    ForFringe& operator= (const std::uintptr_t a)
    {    TlsSetValue(fringe_slot, (void *)a);
         return *this;
    };
    ForFringe& operator+= (const std::size_t a)
    {    std::uintptr_t v = (std::uintptr_t)TlsGetValue(fringe_slot) + a;
         TlsSetValue(fringe_slot, (void *)v);
         return *this;
    };
};

inline ForFringe fringe;

class ForHeapLimit
{
public:
    operator std::uintptr_t()
    {   return *(std::atomic<std::uintptr_t> *)TlsGetValue(heaplimit_slot);
    };
    ForHeapLimit& operator= (const std::uintptr_t a)
    {    TlsSetValue(heaplimit_slot, (void *)a);
         return *this;
    };
    ForHeapLimit()
    {   TlsSetValue(heaplimit_slot, (void *)&real_heaplimit);
    };
};

inline ForHeapLimit heaplimit;

class ForVFringe
{
public:
    operator std::uintptr_t()
    {   return (std::uintptr_t)TlsGetValue(vfringe_slot);
    };
    ForVFringe& operator= (const std::uintptr_t a)
    {    TlsSetValue(vfringe_slot, (void *)a);
         return *this;
    };
    ForVFringe& operator+= (const std::size_t a)
    {    std::uintptr_t v = (std::uintptr_t)TlsGetValue(vfringe_slot) + a;
         TlsSetValue(vfringe_slot, (void *)v);
         return *this;
    };
};

inline ForVFringe vfringe;

class ForVHeapLimit
{
public:
    operator std::uintptr_t()
    {   return *(std::atomic<std::uintptr_t> *)TlsGetValue(vheaplimit_slot);
    };
    ForVHeapLimit& operator= (const std::uintptr_t a)
    {    TlsSetValue(vheaplimit_slot, (void *)a);
         return *this;
    };
    ForVHeapLimit()
    {   TlsSetValue(vheaplimit_slot, (void *)&real_heaplimit);
    };
};

inline ForVHeapLimit vheaplimit;

#elif defined ATOMIC

inline std::atomic<std::uintptr_t> fringe;
inline std::atomic<std::uintptr_t> heaplimit;
inline std::atomic<std::uintptr_t> vfringe;
inline std::atomic<std::uintptr_t> vheaplimit;

#else

extern std::uintptr_t fringe;
extern std::uintptr_t heaplimit;
extern std::uintptr_t vfringe;
extern std::uintptr_t vheaplimit;

#endif

// For memory protection purposes the granularity of pages will vary from
// system to system, but I want to have a range of sizes that I view as
// acceptable. Well here it is - pages can be as amall as 4096 bytes
// or as large as 64K.

#define MIN_PAGE_SIZE 0x01000
#define MAX_PAGE_SIZE 0x10000

extern void get_page_size();
extern std::size_t page_size;

// alloc_segment grabs a chunk of memory of the given size, which must
// be a multiple of CSL_PAGE_SIZE. It also allocated an associated bitmap
// to record "dirty pages". The memory block is recorded in a table that
// can hold up to 32 segments. Note that both get_page_size() and
// set_up_signal_handlers() must be called first.

extern void set_up_signal_handlers();
extern void *allocate_segment(std::size_t);

// These arrays record information about allocated segments. heap_segment[i]
// is the base address of a segment. (heap_segment_count keeps track of
// how many have been allocated). and heap_segment_size[i] records the
// amount of user data in it. There may have been additional space allocated
// at the end of the segment for bitmaps.

extern std::size_t heap_segment_count;
extern void *heap_segment[32];
extern std::size_t heap_segment_size[32];

// Associated with each segment there is a bitmap that has one bit for
// each system page within it (ie using the operating system's concept of
// memory allocation granularity, which is typically 0x1000 but may be
// 0x10000 on some platforms).

extern std::uint64_t *heap_dirty_pages_bitmap_1[32];
extern std::uint64_t *heap_dirty_pages_bitmap_2[32];

extern std::size_t free_pages_count, active_pages_count;

// I only export the next few for debugging purposes. When a bitmap is small
// it gets allocated within a pre-allocated fixed bit-array. If it needed
// to be large then the segment requested from the operating system would
// be large enough to hold it.

#define SMALL_BITMAP_SIZE (MAX_PAGE_SIZE/sizeof(uint64_t)/2)
extern std::uint64_t heap_small_bitmaps_1[SMALL_BITMAP_SIZE+1];
extern std::uint64_t *heap_small_bitmaps_1_ptr;
extern std::uint64_t heap_small_bitmaps_2[SMALL_BITMAP_SIZE+1];
extern std::uint64_t *heap_small_bitmaps_2_ptr;

// Given an arbitrary bit-pattern the find_heap_segment() function tests
// if it could be an address within one of the allocated segments, and if so
// it returns the index into heap_segments[] that is relevant. If it is not
// a valid address the value -1 is returned.

int find_heap_segment(std::uintptr_t p);

// Each system-page within an allocated segment has a bitmap entry showing
// whether it has been written to. The following two functions provide
// key operations on those bitmaps.

extern bool clear_bitmap(std::size_t h);
extern bool refresh_bitmap(std::size_t h);

// Low level functions for allocating objects.

// Entry to a garbage collector.

extern void garbage_collect();

#endif // header_allocate_h

// end of allocate.h

