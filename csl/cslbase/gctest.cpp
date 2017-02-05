// gctest.cpp                        Copyright (C) Arthur Norman, 2016-2017

// This is a little program that I am using to investigate the behaviour of
// the Boehm conservative garbage collector. The code in here will change
// radically from time to time as I explore different aspects of its
// behaviour.

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// The very first challenge is just to get it built and in basic working
// order!

// I will put a general commentary about how far I have got here:
//
// I am using a snapshot of the gc from the developers' git repository,
// rather than any tidily presented release.
//
// If you configure using --with-csl --with-boehm the system should
//   build and use the gc. Building fails for cygwin64: the resulting library
//   will not link for lack of some symbols that should define storage regions.
//   configuration on FreeBSD is an issue if pkg.m4 is missing on your
//   system, as it may very well be. On FreeBSD the configure step notes
//   that thread support is incomplete there.
//   The xxx-w64-mingw32 builds for Windows build but fails the "make check"
//   test of use under C++.
//
// Note that I build gc-7 with DONT_ADD_BYTE_AT_END predefined. That is NOT
// the default state, so a ready-build system-installed copy of the library
// is not going to suit you. The effect of not having that option set is
// that allocation is 8-byte units on a 32-bit machine or 16-byte ones on
// a 64-bit machine get padded to double their size.
//
// I have patched gc.h to fix the cygwin64 issue. Perhaps some time the
// upstream suppliers will adopt this.
//
// I now do not go "--enable-cplusplus" when I build the GC. It looks to me
// as if the only effect of doing so would be to override new and free so that
// memory allocated by them is treated as part of the root set (but is not
// itself collectable). So if I try storing references to anything in memory
// allocated that way I will need to ensure that there is a reference
// somewhere else too - for instance in a static variable. I miss this out
// for now because the mingw build report trouble with the C++ test.

#include <stdio.h>
#include <stdint.h>

// I am putting comments here noting functions that might feel useful. I
// will then try to set up some test cases involving them.

#if defined __WIN32__
#include <windows.h>
#endif

// I may well want to use threads, so I have to define GC_THREADS before
// including the header file
#define GC_THREADS 1
#include "gc.h"

void finf1(void *obj, void *client)
{
    void **p = (void **)obj;
    printf("final %d: %p (%p %p %p %p)\n", *(int *)obj, obj, p[0], p[1], p[2], p[3]);
}

int main(int argc, char *argv[])
{
    printf("gctest\n");
    fflush(stdout);
// By default all_interior_pointers is set and this means that a pointer to
// any byte within an allocated object will keep that object safe. I
// just check that this is indeed the initial state and force it in case.
// IN die coulse I can merely delete these 3 lines!
    printf("initially: GC_all_interior_pointers = %d\n", GC_get_all_interior_pointers());
    GC_set_all_interior_pointers(1);
    printf("after resetting: GC_all_interior_pointers = %d\n", GC_get_all_interior_pointers());
// Part of a reason for liking the idea of a conservative GC is that it
// will make compilation fron Lisp into native code easier. When I do that
// I will want to be able to put code into the heap, and modern operating
// systems seem to be fussy about dynamically created code. So since gc-7
// gives me a way of supporting it I will use their scheme. A consequence
// may be that the whole heap becomes executable. If I was writing code with
// security implications I might worry about that.
    GC_set_pages_executable(1); // To support executable code in heap.
// Some platforms need GC_INIT() and I must have set major options before
// calling it. On some other platforms it is a no-op.
    GC_INIT();
// My first test tries to see how memory allocation rounds up block
// sizes. This appears to show that on a 32-bit platform every block is
// rounded up to a multiple of 8 bytes, and on a 64-bit onr to a multiple
// of 16 bytes. Given that I defined DONT_ADD_BYTE_AT_END when building
// the library I find that if I ask for 8 bytes that is what I get.
    int size = 2;
    intptr_t prev = (intptr_t)GC_MALLOC(1);
    for (int i=0; i<18; i++)
    {   intptr_t next = (intptr_t)GC_MALLOC(size);
        printf("size = %d delta = %d\n", size, (int)(prev - next));
        if ((i & 1) == 0) size += 2;
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

// Now I will create some stuff, discard some, force a GC and see what I
// can discern about when it lives and when it dies...
    {   volatile intptr_t root[16];
        for (int i=0; i<16; i++)
        {   root[i] = 0;
            volatile intptr_t a = (intptr_t)GC_MALLOC(4*sizeof(intptr_t));
            *(int *)a = i;
            GC_register_finalizer((void *)a, finf1, NULL, NULL, NULL);
            printf("Object %d at %p\n", i, (void *)a);
            switch (i)
            {
            case 0:
// Point at the first item of the object
                root[0] = a;
                break;
            case 1:
// point 3 bytes in. This is within the first word on both 32 and 64-bit
// machines.
                root[1] = a+3;
                break;
            case 2:
// point 11 bytes in. Badly aligned and not within the first word.
                root[2] = a+11;
                break;
            case 3:
// point at the very last byte of the object.
                root[3] = a+4*sizeof(intptr_t)-1;
                break;
            case 4:
// put a reference to this new object within another block.
                ((intptr_t *)(root[0]-0))[0] = a;
                break;
            case 5:
// put it within a block one more word on.
                ((intptr_t *)(root[1]-3))[1] = a;
                break;
            case 6:
// put it at the last place within the block.
                ((intptr_t *)(root[2]-11))[3] = a;
                break;
            case 7:
// Make a cyclic reference to self.
                ((intptr_t *)a)[2] = a;
                break;
            case 8:
// Make a small chain hangin off root[4]
                root[4] = a;
                break;
            case 9:
            case 10: 
            case 11: 
            case 12: 
            case 13: 
// This appears to be to show that when I have a chain of length n
// and I discard the pointer to its head that it takes n garbage
// collection passes before the final cell in the chain gets recycled.
// I can see how this can arise, but it is a fact I wish to be aware of
// when using the collector in a Lisp context where lists may
// sometimes be very long.
                ((intptr_t *)a)[2] = root[4];
                root[4] = a;
                break;
// Note that blocks 14 and 15 are not preserved at all. But traces
// of 15 may exist in working registers etc.
            }
            a = 0;
        }
        printf("About to do first collect\n");
        GC_gcollect();
        root[4] = 0;
        printf("Have set root[4], so do second collect\n");
        GC_gcollect();
        for (int i=0; i<12; i++) root[i] = 0;
        printf("Have set all roots to 0, so do second collect\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
        printf("Do one more collection to see what happens\n");
        GC_gcollect();
    }
    return 0;
}


// end of gctest.cpp
