// alloctest.cpp                                Copyright (C) 2019 Codemist

// This is going to be so I can have a simple test harness for
// newalloc.cpp and its friends.


// $Id$


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

#include "config.h"
#include "headers.h"
#include "arithlib.hpp"

// I will need to provide definitions of a number of things that the main
// parts of CSL use, even if I will not actually make use of them here.

void fwin_report_left(const char *s)
{}

void fwin_report_right(const char *s)
{}

int window_heading;

void fwin_ensure_screen()
{
}

void ensure_screen()
{
}

volatile std::atomic<std::uintptr_t> event_flag;

int fwin_getchar()
{   return EOF;
}

LispObject make_undefined_symbol(const char *name)
{   return nil;
}

LispObject get_pname(LispObject a)
{   return a;
}

LispObject nil, lisp_true, unset_var;
LispObject *nilsegment, *stacksegment, *stack, *stackBase,
           *stackLimit;
std::uintptr_t *C_stackbase, C_stacklimit;

[[noreturn]] void fatal_error(int code, ...)
{   my_abort();
}
void trace_printf(const char *fmt, ...)
{
}

void global_longjmp()
{   my_abort();
}

void respond_to_stack_event()
{
}

int init_flags;
double maxStoreSize;
unsigned int exit_count;
std::intptr_t miscflags;

const char *programDir;
const char *programName;
const char *standard_directory;

LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1] = {0};

std::uint32_t Crand()
{   return 0;
}

bool file_exists(char*, char const*, unsigned long, char*)
{   return false;
}

const volatile char *errorset_msg;

[[noreturn]] LispObject aerror(const char *msg)
{   my_abort();
}

[[noreturn]] LispObject aerror1(const char *msg, LispObject a)
{   my_abort();
}

std::int64_t sixty_four_bits(LispObject a)
{   return 0;
}

//=======================================================================
// Everything above this is just so that I can compile my code.

std::mutex print_mutex;

LispObject zcons(LispObject a, LispObject b)
{   char *r = new char[2*sizeof(LispObject)];
    LispObject r1 = TAG_CONS + reinterpret_cast<LispObject>(r);
    car(r1) = a;
    cdr(r1) = b;
    return r1;
}

thread_local std::uint64_t treehash;

LispObject make_n_tree1(int n)
{   if (n == 0)
    {   std::uint64_t r = arithlib_implementation::mersenne_twister();
        r &= UINT64_C(0x0000ffffffffffff);
        treehash = 1234567*treehash + r;
        treehash -= (treehash >> 32);
        return fixnum_of_int(r);
    }
    int n1 = (n-1)/2;
    LispObject left = make_n_tree1(n1);
    if ((arithlib_implementation::mersenne_twister() % 1000) == 0)
    {   may_block([&]
        {   std::this_thread::sleep_for(std::chrono::seconds(1));
        });
        LispObject right = make_n_tree1(n-n1-1);
        return cons(left, right);
    }

    LispObject make_n_tree(int n)
    {   treehash = 0;
        LispObject r = make_n_tree1(n);
        return r;
    }

    int treesize1(LispObject a)
    {   if (is_fixnum(a))
        {   std::uint64_t r = int_of_fixnum(a);
            treehash = 1234567*treehash + r;
            treehash -= (treehash >> 32);
            return 0;
        }
        if (!is_cons(a)) my_abort();
        int left = treesize1(car(a));
        int right = treesize1(cdr(a));
        return left+right+1;
    }

    void treesize(LispObject a, int expected_size,
                  std::uint64_t expected_hash)
    {   treehash = 0;
        int n = treesize1(a);
        my_assert(n == expected_size);
        my_assert(treehash == expected_hash);
    }

// Threads are created using this function, and its argument cen be passed
// to identify the activity with a thread number.

    int thread_function(int id)
    {   thread_id = id;
// The next 2 lines may need to be in a critical region? And/or
// threadcount might need to be atomic. And the issue of creating
// a new thread while another is involved in garbage collection might be
// a hideous mess.
        activeThreads.fetch_add(1);
        threadcount++;
        stack_bases[id].store(reinterpret_cast<void *>(&id));
        int size = 3;
        LispObject a = fixnum_of_int(0), b = fixnum_of_int(0);
        {   std::lock_guard<std::mutex> lock(print_mutex);
            std::printf("Starting thread %d\n", id);
            std::fflush(stdout);
        }
        int sizeA = 0, sizeB = 0;
        std::uint64_t checkA = 0, checkB = 0;
        while (size < 400)
        {   a = b;
            sizeA = sizeB;
            checkA = checkB;
            sizeB = arithlib_implementation::mersenne_twister() % size;
            {   std::lock_guard<std::mutex> lock(print_mutex);
                std::printf("Thread %d, next size will be %d [%d]\n", id, sizeB,
                            size);
                std::fflush(stdout);
            }
            b = make_n_tree(sizeB);
            {   std::lock_guard<std::mutex> lock(print_mutex);
                std::printf("Thread %d, tree made\n", id);
                std::fflush(stdout);
            }
            checkB = treehash;
            treesize(a, sizeA, checkA);
            treesize(b, sizeB, checkB);
            size = size + (size+9)/10;
        }
        return 0;
    }

    int main(int argc, char *argv[])
    {   std::printf("alloctest starting\n");
        std::fflush(stdout);
        for (int i=0; i<max_threads; i++)
        {   stack_bases[i] = nullptr;
            stack_fringes[i] = nullptr;
        }
        heapSegmentCount = 0;
        freePages = nullptr;
        freePagesCount = activePagesCount = 0;
        initHeapSegments(64.0*1024.0);
        nurseryPage = freePages;
        freePages = freePages->pageHeader.chain;
        set_variables_from_page(nurseryPage);
// If I leave the opage empty to start with I will have to do rather a lot of
// work before it is full enough to trigger GC, so here I will just do a bulk
// allocation that uses up all but a little bit of the space.
        get_n_bytes(pageSize - spareBytes - 1000);
// Each thread MUST be given a (distinct) thraed_id in the range from 0
/// to max_threads-1.
        std::thread t1(thread_function, 1);
        std::thread t2(thread_function, 2);
        thread_function(0);
// all threads are done. I will run the mutatuor task in this the main
// thread as well as the subsidiary ones just in case that makes a difference.
        t1.join();
        t2.join();
        std::printf("Memory left = %" PRId64 "\n",
                    static_cast<std::int64_t>(Alimit.load() - Afringe.load()));
        return 0;
    }

// end of alloctest.cpp
