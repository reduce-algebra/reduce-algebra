// allocate.h                             Copyright (C) Codemist, 1990-2018


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

#ifndef header_allocate_h
#define header_allocate_h 1

// For memory protection purposes the granularity of pages will vary from
// system to system, but I want to have a range of sizes that I view as
// acceptable. Well here it is - pages can be as amall as 4096 bytes
// or as large as 64K.

#define MIN_PAGE_SIZE 0x01000
#define MAX_PAGE_SIZE 0x10000

extern void get_page_size();
extern size_t page_size;

// alloc_segment grabs a chunk of memory of the given size, which must
// be a multiple of CSL_PAGE_SIZE. It also allocated an associated bitmap
// to record "dirty pages". The memory block is recorded in a table that
// can hold up to 32 segments. Note that both get_page_size() and
// set_up_signal_handlers() must be called first.

extern void set_up_signal_handlers();
extern void *allocate_segment(size_t);

// These arrays record information about allocated segments. heap_segment[i]
// is the base address of a segment. (heap_segment_count keeps track of
// how many have been allocated). and heap_segment_size[i] records the
// amount of user data in it. There may have been additional space allocated
// at the end of the segment for bitmaps.

extern size_t heap_segment_count;
extern void *heap_segment[32];
extern size_t heap_segment_size[32];

// Associated with each segment there is a bitmap that has one bit for
// each system page within it (ie using the operating system's concept of
// memory allocation granularity, which is typically 0x1000 but may be
// 0x10000 on some platforms).

extern uint64_t *heap_dirty_pages_bitmap_1[32];
extern uint64_t *heap_dirty_pages_bitmap_2[32];

extern size_t free_pages_count, active_pages_count;

// I only export the next few for debugging purposes. When a bitmap is small
// it gets allocated within a pre-allocated fixed bit-array. If it needed
// to be large then the segment requested from the operating system would
// be large enough to hold it.

#define SMALL_BITMAP_SIZE (MAX_PAGE_SIZE/sizeof(uint64_t)/2)
extern uint64_t heap_small_bitmaps_1[SMALL_BITMAP_SIZE+1];
extern uint64_t *heap_small_bitmaps_1_ptr;
extern uint64_t heap_small_bitmaps_2[SMALL_BITMAP_SIZE+1];
extern uint64_t *heap_small_bitmaps_2_ptr;

// Given an arbitrary bit-pattern the find_heap_segment() function tests
// if it could be an address within one of the allocated segments, and if so
// it returns the index into heap_segments[] that is relevant. If it is not
// a valid address the value -1 is returned.

int find_heap_segment(uintptr_t p);

// Each system-page within an allocated segment has a bitmap entry showing
// whether it has been written to. The following two functions provide
// key operations on those bitmaps.

extern bool clear_bitmap(size_t h);
extern bool refresh_bitmap(size_t h);

// Low level functions for allocating objects.

// Entry to a garbage collector.

extern void garbage_collect();

#endif // header_allocate_h

// end of allocate.h

