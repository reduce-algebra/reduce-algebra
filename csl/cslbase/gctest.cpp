// gctest.cpp                                         Arthur Norman, 2015

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

// This is a little program that I am using to investigate the behaviour of
// the Boehm conservative garbage collector. The code in here will change
// radically from time to time as I explore different aspects of its
// behaviour.

// The very first challenge is just to get it built and in basic working
// order!


#include <stdio.h>
#include <stdint.h>

// #define DONT_ADD_BYTE_AT_END 1         seems not to exist any more?
//
// I see a remark somewhere that when it did the GC would not scan a pointer
// in the final word of an allocated chunk, which would be horrid! However
// without it blocks whose size are multiples of 8 are padded to the next
// multiple of 8 up...

#if defined __WIN32__ // || defined __CYGWIN__
#include <windows.h>
#endif
#define GC_THREADS
#include "gc.h"

int main(int argc, char *argv[])
{
    printf("GC_all_interior_pointers = %d\n", GC_get_all_interior_pointers());
//  printf("DONT_ADD_BYTE_AT_END = %d\n", DONT_ADD_BYTE_AT_END);
    GC_set_all_interior_pointers(0);
    GC_set_pages_executable(1); // To support executable code in heap.
    GC_INIT();
    int size = 1;
// Here I will allocate blocks of various small sizes and observe the
// differences between the addresses that they end up at. This can tell
// me something about the potential wastage due to padding.
    intptr_t prev = (intptr_t)GC_MALLOC(1);
    for (int i=0; i<35; i++)
    {   intptr_t next = (intptr_t)GC_MALLOC(size);
        printf("size = %d delta = %d\n", size, (int)(prev - next));
        if ((i & 1) == 0) size++;
        prev = next;
    }
// GC_MALLOC_ATOMIC(size) to be used if object will not contain pointers
// GC_malloc_ignore_off_page(size) guarantee ptr is to about the start
// GC_malloc_atomic_ignore_off_page(size) guarantee ptr is to about the start
// GC_BASE(void *) gives ptr to base of an object
// GC_is_heap_ptr(void *) true if ref points to heap allocated thing
// GC_size(void *) given pointer to base of object check allocated size
// GC_gcollect()   do a GC
// GC_get_heap_size() return heap size as a size_t
// GC_NEW(type)       ref to space for given type
// GC_NEW_ATOMIC(type) 
// GC_CreateThread()
// GC_beginthreadx()
    return 0;
}

// end of gctest.cpp
