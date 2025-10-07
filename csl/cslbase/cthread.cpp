// cthread.cpp                                  Copyright (C) 2025 Codemist

// $Id$


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

// Here I provide an abstraction for running several tasks in
// parallel.
//    runInThreads(fn, N)
// will obey fn(0), fn(1), ..., fn(N-1) in N separate threads (one of
// those will be the thread of the caller. If this call is made and there
// are not enough available threads to service all N tasks then it will
// drop back to executing things sequentially.

// If USE_EXECUTION is defined this uses some C++17 functionality that
// makes this rather easy to express. However as of late 2025 use of
// the <execution> header and std::execution::par requires an extra
// library (-ltbb) to be loaded. I also suspect it of being general
// enough that for small tasks it will impose costs that I would like
// to avoid. To cope with those two issues I also provide my own
// implementation that allows for a somewhat limited number of worker
// tasks but which may be lighter weight.

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#ifdef USE_EXECUTION
#pragma message "You may need to link in libtbb"
#include <execution>
#endif

void (*workerTask)(unsigned int);

#ifdef USE_EXECUTION

void runInThreads(void (*fn)(unsigned int), unsigned int n)
{
    vector <int> counter;
    for (int i=0; i<n; i++) counter.push_back(i);;
    std::for_each(std::execution::par,
                  std::begin(counter),
                  std::end(counter),
                  fn);
}

#else // USE_EXECUTION

inline const size_t POOLSIZE = 16;
std::atomic<uint32_t> activeThreads(0);

// There are 4 mutexes for each worker thread, but each synchronization step
// just involves a single mutex, transferring ownership between main and worker
// thread. Here is the patter of transfer and subsequent ownership, with "?"
// marking a muxex that has been waiting and the ">n" or <n" in the middle
// also showing which muxex has just been activated:
//       X  X  .  .         ?  .  X  X    Idle state. Worker waiting on mutex 0
// To start a transaction the main thread sets up data and unlocks mutex 0.
// That allows the worker to proceed and pick up the data.
//       .  X  .  .   >0    ?X .  X  X    first transaction
// The main thread must not alter data until the worker is finished. It waits
// on mutex 1 until the worker tells it that a result is available.
//       .  X ?X  .   <2    X  .  .  X
// The main thread is now entitles to start using the results of the activity
// just completed and setting up data for the next one. It can not release
// mutex 0 to restart the worker because the worker alread owns that. And even
// though it owns mutex 2 it had better not release that, because for that
// to make sense the worker would need to be waiting on it, and that would mean
// the worker had just done m3.unlock(); m3.lock() in quick succesion, which
// might have led it to grab m3 rather than the main program managing to. So
// use the third mutex, which the worker must be waiting on.
//       .  .  X  .   >1    X ?X  .  X    second transaction
// When it has finished its task the worker now unlocks mutex 3. This leaves
// a situation symmetric with the initial one
//       .  .  X ?X   <3    X  X  .  .
//       .  .  .  X   >2    X  X  ?X .    third transaction
//       ?X .  .  X   <0    .  X  X  .
//       X  .  .  .   >3    .  X  X ?X    fourth transaction
//       X ?X  .  .   <1    .  .  X  X    back in initial configuration!
//
// The pattern is thus that the master goes
//  [initially lock 0 and 1]
//  unlock 0  wait 2
//  unlock 1  wait 3
//  unlock 2  wait 0
//  unlock 3  wait 1
// while the worker goes
//  [initially lock 2 and 3]
//  wait 0    unlock 2
//  wait 1    unlock 3
//  wait 2    unlock 0
//  wait 3    unlock 1
// Observe that I can use (n^2) [note that ^ here is an exclusive OR and
// not exponentiation, because I am in C++) to map between the mutex number
// in the first and second columns here. That counting is what sendCount and
// receiveCount are doing.

// In a nice world I would use just the C++ std::mutex scheme for
// synchronization, however here I am performance critical and to save
// a bit when performing medium-sized multiplications I will use the
// Microsoft version of mutexes directly on that platform. Worse then that
// there is a Microsoft option known as "SRW" (Slim Reader/Writer locks)
// that may be good to use.

#if defined __CYGWIN__ || defined __MINGW32__

// It is possible that SRW locks have lower overhead than Mutex. So I will
// use them, but have an "#ifdef" so I can revert if needbe.

#define USE_MICROSOFT_SRW 1

#ifndef USE_MICROSOFT_SRW
#define USE_MICROSOFT_MUTEX 1
#endif // USE_MICROSOFT_SRW

// Going "#include <windows.h>" pollutes the name-space rather heavily
// and so despite it being somewhat despicable I declare the rather small
// number of things I need by hand. Note that some of the issues are
// macros rather than extern definitions, so it is not obvious that
// C++ "namespace" treatment can make things nice for me.

extern "C"
{
struct SecApp
{   std::uintptr_t nLength;
    void* lpSecurityDescriptor;
    int bInheritHandle;
};

typedef struct _RTL_SRWLOCK { void* Ptr; } RTL_SRWLOCK,*PRTL_SRWLOCK;
#define RTL_SRWLOCK_INIT {0}
#define SRWLOCK_INIT RTL_SRWLOCK_INIT
typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;

extern __declspec(dllimport) void InitializeSRWLock (PSRWLOCK SRWLock);
extern __declspec(dllimport) void ReleaseSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) void ReleaseSRWLockShared (PSRWLOCK SRWLock);
extern __declspec(dllimport) void AcquireSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) void AcquireSRWLockShared (PSRWLOCK SRWLock);
extern __declspec(dllimport) bool TryAcquireSRWLockExclusive (PSRWLOCK SRWLock);
extern __declspec(dllimport) bool TryAcquireSRWLockShared (PSRWLOCK SRWLock);

extern __declspec(dllimport)  void* 
    CreateMutexA(SecApp* , std::uintptr_t, const char* );
extern __declspec(dllimport) int CloseHandle(void* h);
extern __declspec(dllimport) int ReleaseMutex(void* m);
extern __declspec(dllimport) void* 
    WaitForSingleObject(void* , std::uintptr_t);
inline const long unsigned int MICROSOFT_INFINITE = 0xffffffff;

};   // end of extern "C" scope.

#endif // __CYGWIN__ or __MINGW32__

class WorkerData
{
public:
    int which;                
    std::atomic<bool> ready;
#if defined USE_MICROSOFT_SRW
    SRWLOCK mutex[4];
#elif defined USE_MICROSOFT_MUTEX
    void* mutex[4];
#else // The final case is C++ std::mutex
    std::mutex mutex[4];
#endif // end of mutex selection
    int sendCount;
    bool quit_flag;

// When I construct an instance of Worker data I set its quit_flag to
// false and lock two of the mutexes. That sets things up so that when
// it is passed to a new worker thread that thread behaves in the way I
// want it to.
    WorkerData()
    {   ready = false;
        quit_flag = false;
#if defined USE_MICROSOFT_SRW
        InitializeSRWLock(&mutex[0]);
        InitializeSRWLock(&mutex[1]);
        AcquireSRWLockExclusive(&mutex[0]);
        AcquireSRWLockExclusive(&mutex[1]);
        InitializeSRWLock(&mutex[2]);
        InitializeSRWLock(&mutex[3]);
#elif defined USE_MICROSOFT_MUTEX
        mutex[0] = CreateMutexA(NULL, 1, NULL);
        mutex[1] = CreateMutexA(NULL, 1, NULL);
        mutex[2] = CreateMutexA(NULL, 0, NULL);
        mutex[3] = CreateMutexA(NULL, 0, NULL);
#else // use C++ std::mutex
// The next two must be locked by the main thread.
        mutex[0].lock();
        mutex[1].lock();
#endif // Mutexes now initialized and locked as needed
        sendCount = 0;
    }
    void setWhich(int n)
    {   which = n;
    }
#ifdef USE_MICROSOFT_MUTEX
    ~WorkerData()
    {   CloseHandle(mutex[0]);
        CloseHandle(mutex[1]);
        CloseHandle(mutex[2]);
        CloseHandle(mutex[3]);
    }
#endif // USE_MICROSOFT_MUTEX
};

// The main thread will have a structure that encapsulates the
// worker threads that it ends up with and the data it sets up for
// them and that they then access. When this structures is created it will
// cause the worker threads and the data block they need to be constructed.

inline void workerThread(WorkerData* wd);

class DriverData
{
public:
    WorkerData wd[POOLSIZE];
// When the instance of DriverData is created the WorkerData instances
// get constructed with two of their mutexes locked. This will mean that when
// worker threads are created and start running they will politely wait for
// things to do.
    std::thread w[POOLSIZE];

    DriverData()
    {   for (int i=0; i<POOLSIZE; i++)
        {   wd[i].setWhich(i+1);
            w[i] = std::thread(workerThread, &wd[i]);
        }
// I busy-wait until all the threads have both claimed the mutexes that they
// need to own at the start! Without this the main thread may post a
// multiplication, so its part of the work and try to check that the worker
// has finished (by claiming one of these mutexes) before the worker thread
// has got started up and has claimed them. This feels clumsy, but it only
// happens at system-startup.
        for (int i=0; i<POOLSIZE; i++)
        {   if (!wd[i].ready.load())
            {   std::this_thread::sleep_for(std::chrono::microseconds(1));
                i--;  // I only proceed once the thread is ready.
            }
        }
    }

// When the DriverData object is to be destroyed it must arrange to
// stop and then join the two threads that it set up. This code that sends
// a "quit" message to each thread will be executed before the thread object
// is deleted, and the destructor of the thread object should be activated
// before that of the WorkerData and the mutexes within that.

// The expectation here is that this termination will happen at a time
// when none of the worker threads are doing anything, and thus they are
// all sitting ready to accept this request. Abrupt (ie error) termination
// of the program might not manage that!
    ~DriverData()
    {   for (int i=0; i<POOLSIZE; i++)
        {   wd[i].quit_flag = true;
            releaseWorker(i);
            w[i].join();
        }
    }

// Using the worker threads is then rather easy: one sets up data in
// the WorkerData structures and then call releaseWorker() for each
// one that must start. Then the driver program can do whatever it
// wishes to while the workers just started do what they are set up for.
// When you are ready you call waitForWorker() on each sub-process,
// which does what one might imagine.

    void releaseWorker(int i)
    {
#if defined USE_MICROSOFT_SRW
        ReleaseSRWLockExclusive(&wd[i].mutex[wd[i].sendCount]);
#elif defined USE_MICROSOFT_MUTEX
        ReleaseMutex(wd[i].mutex[wd[i].sendCount]);
#else // use std::mutex
        wd[i].mutex[wd[i].sendCount].unlock();
#endif // mutexed unlocked
    }

    void waitForWorker(int i)
    {
#if defined USE_MICROSOFT_SRW
        AcquireSRWLockExclusive(&wd[i].mutex[wd[i].sendCount^2]);
#elif defined USE_MICROSOFT_MUTEX
        WaitForSingleObject(wd[i].mutex[wd[i].sendCount^2], MICROSOFT_INFINITE);
#else // use std::mutex
        wd[i].mutex[wd[i].sendCount^2].lock();
#endif // synchronized
        wd[i].sendCount = (wd[i].sendCount+1)&3;
    }
};

static DriverData driverData;

#if defined USE_MICROSOFT_SRW

void workerThread(WorkerData* wd)
{   ThreadLocal::initialize();
    AcquireSRWLockExclusive(&wd->mutex[2]);
    AcquireSRWLockExclusive(&wd->mutex[3]);
    wd->ready = true;
    int receiveCount = 0;
    for (;;)
    {   AcquireSRWLockExclusive(&wd->mutex[receiveCount]);
        if (wd->quit_flag) return;
        (*workerTask)(which);
        ReleaseSRWLockExclusive(&wd->mutex[receiveCount^2]);
        receiveCount = (receiveCount + 1) & 3;
    }
}

#elif defined USE_MICROSOFT_MUTEX

void workerThread(WorkerData* wd)
{   WaitForSingleObject(wd->mutex[2], MICROSOFT_INFINITE);
    WaitForSingleObject(wd->mutex[3], MICROSOFT_INFINITE);
    wd->ready = true;
    int receiveCount = 0;
    for (;;)
    {
// This WaitFor could wait for the entire Reduce run any only be signalled
// during close-down, so putting a timeout on it would nor make sense.
        WaitForSingleObject(wd->mutex[receiveCount], MICROSOFT_INFINITE);
        if (wd->quit_flag) return;
        (*workerTask)(which);
        ReleaseMutex(wd->mutex[receiveCount^2]);
        receiveCount = (receiveCount + 1) & 3;
    }
}

#else // Here I use C++ std::mutex

void workerThread(WorkerData* wd)
{   wd->mutex[2].lock();
    wd->mutex[3].lock();
    wd->ready = true;
    int receiveCount = 0;
    for (;;)
    {   wd->mutex[receiveCount].lock();
        if (wd->quit_flag) return;
        (*workerTask)(wd->which);
        wd->mutex[receiveCount^2].unlock();
        receiveCount = (receiveCount + 1) & 3;
    }
}

#endif // definition of workerThread

void runInThreads(void (*fn)(unsigned int), unsigned int n)
{   if (n > POOLSIZE) abort();  // Too many!
// Here I want to see if there are any worker threads available to
// dedicate to this task.
    uint32_t active = activeThreads.exchange((1<<POOLSIZE)-1);
// Now I have set things as if all the threads are active. If I find
// that all were active when I first look I will just run my tasks
// sequentially and there is no need to change the activity map. This
// simple scheme means that if two threads each call runInThreads at
// almost the same time then the second one may end up dropping back to
// sequential work even though the first was not going to use up many
// workers. That issue could be avoided by wrapping some mutexes around
// all of the decision-making steps here, but I prefer to make what I expect
// to be the common case (of no contention) as fast as possible.
// So the next line detects and responds either to the case that others
// are all making active use of ALL available workers or the awkward case
// that I am part way through the few lines of code that temporarily
// pretend that while working out what can be done.
    if (active == (1<<POOLSIZE-1))
    {   for (int i=0; i<n; i++)
            (*fn)(i);
        return;
    }
// See if I can find n-1 threads that are not in use at present. I look for
// just n-1 because the current thread will participate in the work too and
// thereby make up the total of n.
    int threadIds[POOLSIZE];
    int w = 0;
    uint32_t claimed = 0;
    for (int i=0; i<POOLSIZE && w<n-1; i++)
    {   if ((active & (1<<i)) == 0)
        {   threadIds[w++] = i;
            claimed |= 1<<i;
        }
    }
    if (w < n-1)
    {
// If there are not enough threads to satisfy this request I will
// reset the map to the state it had been when I started. Note that
// nobody can have started more threads since the exchange() that I did
// earlier so this should alwaye be proper. Then I work sequentially.
        activeThreads = active;   
        for (int i=0; i<n; i++)
            (*fn)(i);
        return;
    }
// Now there are enough threads left, and threadIds[] tabulates the
// identifiers that they have and claimed is a bitmap. I can reset
// activeThreads allowing for what I am now grabbing.
    activeThreads.store(active | claimed);
// From now anybody else can start trying to grab workers and be in with
// a chance.
// 
    workerTask = fn;
// Release (ie start up) all the worker threads I have picked.
    for (int i=0; i<n-1; i++)
        driverData.releaseWorker(threadIds[i]);
// Use this main thread to do work, calling itself "task 0".
    (*fn)(0);
// Wait until everybody has completed their job.
    for (int i=0; i<n-1; i++)
        driverData.waitForWorker(threadIds[i]);
// Tell the system that the threads I had just been using are now free for
// others to use.
    activeThreads &= ~claimed;
}

#endif // USE_EXECUTION

#ifdef TEST_CODE

std::mutex g;

void task(unsigned int n)
{   {   std::lock_guard<std::mutex> guard(g);
        std::cout << "Running with n = " << n << "\n";
    }

    {   std::lock_guard<std::mutex> guard(g);
        uint64_t w = 1;
        for (std::uint64_t i=0; i<10000000*((123456*n)%97); i++)
            w = 139*w + 11213;
        std::cout << "Ending task " << n << " with value " << w << "\n";
    }
}

int main()
{
    runInThreads(task, 7);
    std::cout << "finished\n";
    return 0;
}

#endif // TEST_CODE

// end of cthread.cpp

