// allocate_test.cpp                       Copyright (C) 1989-2022 Codemist

//
// Code for testing storage allocation
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

// The code in allocate.cpp involves an experimental change in how storage
// management is done in CSL. The code here is a TEMPORARY framework of
// test code to activate and exercise it. When (and if) everything stablizes
// the new code will be used by the main system and this file will be
// removed. I will have stubs here for all sorts of bits of CSL that are
// referenced from allocate.cpp - only s few of them will be truly relevant
// for the testing.


#include "headers.h"

void term_printf(const char *fm, ...)
{   my_abort();
}

LispObject **get_stack_addr()
{   return nullptr;
}

const volatile char *errorset_msg;

std::intptr_t miscflags;


void garbage_collect()
{
}

void my_abort()
{   my_abort();
}

//
// I use a Mersenne Twister pseudo-random generator from the C++11 library.
// For seeding it there is a severe misery in that the most obvious source
// of unpredictability, ie std::random_devivce, is deterministic on some
// platforms (including mingw32). So I seed my mersenene twister with
// something based on what it returns AND on the time of day (and on the
// identity of the current thread).
//

static std::random_device hopefully_random;

static std::seed_seq initial_random_seed
{   hopefully_random(),
    static_cast<unsigned int>()
    std::hash<std::thread::id>()(std::this_thread::get_id()),
    static_cast<unsigned int>(std)::time(nullptr),
    static_cast<unsigned int>()
    std::chrono::high_resolution_clock::now().time_since_epoch().count()
};
static std::mt19937 mersenne_twister(initial_random_seed);

// Stuff above here is basically providing enough stubs for other parts of
// CSL that I can compile allocate.cpp happily...

int main(int argc, char *argv[])
{   std::printf("Allocate test code\n");
    get_page_size();
    std::printf("page_size = %x\n", static_cast<int>(page_size));
    set_up_signal_handlers();
    LispObject *m1 = reinterpret_cast<LispObject *>(allocate_segment(
                         4*1024*1024));
    LispObject *m2 = reinterpret_cast<LispObject *>(allocate_segment(
                         4*1024*1024));
    std::printf("segments at %p %p\n", m1, m2);
    for (int i=0; i<heap_segment_count; i++)
    {   std::printf("%d) %p %" PRIx64 "  %p\n", i,
                    heap_segment[i],
                    static_cast<std::uint64_t>(heap_segment_size[i]),
                    heap_dirty_pages_bitmap[i]);
    }
    clear_bitmap(0);
    clear_bitmap(1);
    for (int i=0; i<20; i++)
    {   std::uintptr_t b = reinterpret_cast<std::uintptr_t>
                           (heap_segment[0]);
        std::uintptr_t n = (reinterpret_cast<std::uintptr_t>
                            (mersenne_twister())) % heap_segment_size[0];
        std::printf("Access at offset %.10" PRIx64 " = %d\n",
                    static_cast<std::uint64_t>(n), static_cast<int>(n/page_size));
        *reinterpret_cast<char *>(b + n) = 1;
    }
    refresh_bitmap(0);
    std::uint64_t *w = heap_dirty_pages_bitmap[0];
    std::size_t nb = heap_segment_size[0]/page_size/64;
    for (std::size_t i=0; i<nb; i++)
    {   std::uint64_t k = w[i];
        for (int j=0; j<64; j++)
        {   std::putchar('0' + static_cast<int>(k & 1));
            k = k >> 1;
        }
    }
    std::printf("\n");
    return 0;
}



// end of allocate_test.cpp
