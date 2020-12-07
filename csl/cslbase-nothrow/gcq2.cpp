// gcq2.cpp                                               A C Norman 2020

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

// This is an attempt at a "mostly lock-free" queue. Well actually it
// is a LIFO queue (is a stack!) but the intended use is as a queue.
// A limitation on its use is that if an item is removed from it then
// that item must not be put back.
//
// The two operations supported and pushChunk and popChunk. The latter
// in general blocks until pushChunk has provided some data that it
// can retrieve. If a flag gcComplete is set it returns nullptr instead
// when no data is available, and popChunk1 is always available as a
// non-blocking variant.
// pushChunk is lock-free when adding an extra item to a non-empty queue.
// When it adds an item to a queue that is empty it performs some
// traditional synchronization involving a mutex and a condition variable.
// If there is data available popStack will be lock-free - but when the
// queue is empty it blocks in a condition variable.
//
// This file contains test code that I have been using to reassure myself
// that I do not have data races that could lead to deadlock. I am for
// instance running some tests using "rr -h" to give myself a greater
// chance of onserving and problems. However the termination condition
// implemented here is not quite the one I will want in the real application
// of this within my garbage collector!

// $Id: gcq2.cpp 5409 2020-09-27 15:56:21Z arthurcnorman $


#include <iostream>
#include <atomic>
#include <mutex>
#include <cstdint>
#include <cinttypes>
#include <condition_variable>
#include <thread>
#include <random>
#include <chrono>
#include <fstream>

using std::atomic;
using std::cout;
using std::endl;
using std::int32_t;
using std::int64_t;
using std::uint32_t;
using std::uint64_t;
using std::size_t;


typedef intptr_t LispObject;

#if 0
// It seems that using std::random_device really upsets "rr", leading
// to the program just stalling during startup! I have not investigated
// in detail. This MAY be https://github.com/mozilla/rr/issues/2459 with
// a fix due to be available in a newer version of rr...

static std::random_device hopefully_random;
#else

// Cygwin and Linux and MacOS all provide /dev/urandom, so I will
// use that instead of std::random_device.

unsigned int hopefully_random()
{   std::ifstream randomData("/dev/urandom", std::ios::binary);
    char b[4];
    randomData.read(b, 4);
    unsigned int r = 0;
    for (int i=0; i<4; i++)
        r = (r<<8) | (b[i] & 0xff);
    return r;
}

#endif

static std::seed_seq initial_random_seed
{
    hopefully_random(),
    static_cast<unsigned int>(
        std::hash<std::thread::id>()(std::this_thread::get_id())),
    static_cast<unsigned int>(std::time(nullptr)),
    static_cast<unsigned int>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count())
};
static std::mt19937 mersenne_twister(initial_random_seed);

uint32_t rand32()
{   return mersenne_twister();
}

//=======================================================================

class Chunk
{
public:
    atomic<uintptr_t> length;
    atomic<uintptr_t> chunkFringe;
    atomic<bool> isPinned;
    atomic<Chunk *>chunkStack;
// At the start of garbage collection as I collect a chain of pinned chunks
// those chunks may appear on the list in arbitrary order, but at the end
// of garbage collection if a Page has a number of pinned Chunks within it
// they must be sorted into ascending order. Arranging that will mean that
// I can release the gaps between chunks for allocation easily.
// So within a chunk I start off with gFringe pointing at usableSpace and
// gLimit at either the start of the first pinned chunk or at the end of
// the whole page. When that region gets full the gLimit pointer either
// tells me that I have used up the entire page, or the pinned chunk it
// points at lets me find the new gFringe (using the length field) and the
// end of the next free block (using pinChain - and if that is nullptr the
// relevant limit is the end of the page.
    atomic<Chunk *>pinChain;
// The rest of the chunk is the region within which data is kept.
// Its size will be such that the entire Chunk has length a specified by
// its first word.
    atomic<LispObject>usableSpace[1];

// Now I can have some accessor (etc) methods:
//
    uintptr_t dataStart()
    {   return reinterpret_cast<uintptr_t>(&usableSpace);
    }
    uintptr_t dataEnd()
    {   return reinterpret_cast<uintptr_t>(this) + length;
    }
    bool pointsWithin(uintptr_t p)
    {   return p >= dataStart() && p < chunkFringe;
    }
};

atomic<Chunk *> chunkStack;

std::mutex mutexForChunkStack;
bool gcComplete;
std::condition_variable cvForChunkStack;

// The lock-free stack as implemented here could fail if the "ABA"
// scanario arose - but that involved popping an item and later
// pushing it back. If that will never happen there should not be
// any trouble.

inline void pushChunk(Chunk *c)
{   Chunk *old = chunkStack.load();
    do
    {   c->chunkStack.store(old);
    } while (!chunkStack.compare_exchange_weak(old, c));
    if (old == nullptr)
    {
// The critical regiion with no code within it looks really odd! But it
// is necessary to avoid a race condition in popChunk.
        {   std::lock_guard<std::mutex> lock(mutexForChunkStack);
        }
        cvForChunkStack.notify_all();
    }
}

// This version is lock-free and it return nullptr if the stack is empty.

inline Chunk *popChunk1()
{   Chunk *old = chunkStack.load(), *c;
    do
    {   if (old == nullptr) return nullptr;
        c = old->chunkStack.load();
    } while (!chunkStack.compare_exchange_weak(old, c));
    return old;
}

// Here is the version for use. If called when the stack is empty it
// returns nullptr if gcComplete is set, or otherwise it waits.

inline Chunk *popChunk()
{
// First try in a lock-free manner.
    Chunk *c = popChunk1();
// ... if that succeds then I can return with only low overhead.
    if (c != nullptr) return c;
// ** Point A **
// Now my first lock-free try failed. Of course a pushChunk() may have
// happened in the meanwhile - trying again is not a problem! But this time
// I will lock the mutex first. That will allow any pushChunk that adds
// to a non-empty stack to complete in a lock-free manner, but a pushChunk
// on an empty stack will not be able to reach the notify_all step until the
// mutex is released.
    std::unique_lock<std::mutex> lock(mutexForChunkStack);
    while ((c = popChunk1()) == nullptr && !gcComplete)
    {
// ** Point B **
// Sometimes this pop will succeed, eg if pushChunk ran while this thread
// was at Point A. In such a case the push operation may have performed a
// notify_all but this thread will not be aware. That could have woken some
// other thread up and there could have been a whole sequence of pushes and
// pops around Point A!
// When popChunk1 fails here it will do so with the mutex locked. That means
// that any push that could install data will do so onto an empty stack and
// when it does that it will attempt to lock the mutex and will hence stall.
// It will first be able to make progress when the lock is released, which
// will be within the wait call here.
// Meanwhile other uses of push could have added more items to the
// stack without problems and other threads may have popped things,
// including the one set up by the stalled push thread.
        cvForChunkStack.wait(lock);
// When the condition variable unlocks the mutex (while it waits), the push
// can continue. It will perform a notify_all. Because of the activity of
// other threads the stack could be empty again! But that does not matter
// too much - the code here will check the stack again in popChunk1.
// The crucial issue here is the avoidance of a race condition that could
// lead to pushChunk performing its notify_all while this thread was
// as Point B. If that happened the wait could deadlock.
//
    }
    return c;
}

//=======================================================================

// For test code I have several threads each of which push N items.
// And then several threads that pop - between them they should consume
// everything thay was pushed but there is not guarantee that each will
// get the same number. Indeed one or more could be totally starved.

static uint64_t N = 3;

int makeChunks()
{   //cout << "Producer thread starting\n" << std::flush;
    for (auto i=0; i<N; i++)
    {   Chunk *c = new Chunk;
        pushChunk(c);
//      std::this_thread::sleep_for(
//          std::chrono::nanoseconds(rand32() % 250000U));
    }
    //cout << "Producer thread ending\n" << std::flush;
    return 0;
}

int grabChunks()
{   //cout << "Consumer thread starting\n" << std::flush;
    Chunk *c;
    while ((c = popChunk()) != nullptr)
    {   delete c;
//      std::this_thread::sleep_for(
//          std::chrono::nanoseconds(rand32() % 200000U));
    }
    //cout << "Consumer thread ending\n" << std::flush;
    return 0;
}

// My test runs the pushes and then declared gcComplete. That should
// cause each consumer thread to exit when it next finds no data available.

const size_t nTrials = 10000;
const size_t nThreads = 4;

int main(int argc, char *argv[])
{   cout << "Starting\n" << std::flush;
    std::thread *thr1[nThreads], *thr2[nThreads];
    for (auto trial=1; trial<=nTrials; trial++)
    {   if (trial%100 == 0) cout << "Trial number " << trial << endl;
        for (auto i=0; i<nThreads; i++)
            thr1[i] = new std::thread(makeChunks);
        for (auto i=0; i<nThreads; i++)
            thr2[i] = new std::thread(grabChunks);
//      cout << "About to join producer threads\n" << std::flush;
        for (auto i=0; i<nThreads; i++)
            thr1[i]->join();
//      cout << "All producer threads tidy\n" << std::flush;
// Because all the producers have now terminated all I need to do is to
// wait for consumers to finish their work. So I can set gcComplete, which
// arranges that when a consumer thread tries to pop from an empty
// stack it exits rather than hangs. However it CAN be that due to a race
// the stack has already been emptied by now.
        {   std::lock_guard<std::mutex> lock(mutexForChunkStack);
            gcComplete = true;
        }
        cvForChunkStack.notify_all();
//      cout << "All consumer threads should now be stopping\n" << std::flush;
        for (auto i=0; i<nThreads; i++)
            thr2[i]->join();
    }
    cout << "Finishing\n" << std::flush;
    return 0;
}

// end of gcq2.cpp
