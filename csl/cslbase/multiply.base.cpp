
// integers.

// Overall plan:
//    (1) Cases from 1x1 to 7x7 are dealt with using special code
//        in the hope that those small cases can be handled really
//        fast. I unroll and inline everything. Also cases of Nx1 to
//        Nx7 have their inner x1 to x7 loops unrolled.
//    (2) min(N,M)<=threshold. Use simple long multiplication because
//        anything like Karatsuba will not pay off.
//    (3) N>1.5*M or M>1.5*N and the smaller is >7. Do a sequence of
//        MxM multiplications until the residual N is small enough
//        that a different case applies.
//    (5) If N,M and less than another threshold do Karatsuba.
//    (6) Use 3-thread Karatsuba or 4-thread Toom32.
//

// So here is a more detailed commentary talking about the thresholds in
// the treatment of large cases in extra detail.
//
// Suppose I am multiplying an N digit number by an M digit one with N>=M.
// I can go classical which is straightforward and for small cases that is
// good. But for the rest there are two other base schemes:
//
// I can go Karatsuba. That will use sub-digits of size D=ceiling(N/2) and
// will demand that M>D at least since otherwise the high sub-digit of M
// will be zero and by then use of Karatsuba is surely silly.
// The calculation forms two products on D*D and one on (N-D)*(M-D). If
// things start off even slightly unbalanced this last one is more so and
// so eventually you should not use Karatsuba for it even N it is big.
// But for reasonably balanced cases it is good. My estimates are that
// I should use it up as far as N=1.25*M.
//
// Then I have Toom32 that multiplies a 3-digit number by a 2 digit one via
// evaluation at 0, +1, -1 and infinity. The sub-digit size D must be
// max((N+2)/3, (M+1)/2) to keep top sub-digits both in existence. So
// the cost is then three products D*D and one of (N-2D)*(M-D).
// That final product may be noticably out of balance if N is not very close
// to 1.5M and I will discuss that later, it being a close relative of the
// similar situation that arises in Karatsuba.
//
// So given arbitrary N,M where they are not the same value but are tolerably
// close do I use Karatsuba or Toom32? And what do I do when N and M are
// more widely different?
//
// My plan for a ramge of values of alpha=N/M (where wlog N>=M) will be
//    1 <= alpha < 1.25      Karatsuba. 1 is the best case here
//    1.25 <= alpha < 1.85    Toom32 where 1.5 is the best case
//
// So now I need to consider alpha >= 1.85.
// I will split off the low 3M/2 digits and use Toom32 to form that
/// part of the result - I am then left with the case (N-3M/2)*M. That
// can be continued until N<3M/2, which I will write as alpha<1.5.
// If alpha > 1.25 I will use a sub-optimal Toom32. For 0.85<alpha<1.25
// I will use Karatsuba (with reversed arguments in the alpha<1 case).
// Then if akpha > 0.54 (=1/1.85) I will use Toom32 with reversed arguments.
// So we are left with alpha<0.54, otherwise M>1.85*N. I reverse the
// arguments and continue until the I drop down to use of classical
// methods. 
//
// In all this there is an issue of workspace allocation. And a top-level
// use of either Toom32 or Karatsuba needs extra space because the recursive
// calls that are made run concurrently so each need separate space.
// But for all the recursive calls things are nicer and I can use and
// re-use space.
// I have made several attempts to chart how much will be used but the
// interaction between levels of call and the fact that when I "halve" the
// size of a number there has to be rounding when that number is of odd
// length make that messy enough that anything I come up with using
// calculation will not be a sharp bound and will be very fragile against
// small changes in the code.

inline std::size_t worstN = 0;
inline std::size_t worstM = 0;
inline std::size_t thisN = 0;
inline std::size_t thisM = 0;
inline double worstRatio = 0.0;

#include <atomic>

// When I get to big-integer multiplication I will use two or three
// worker threads so that elapsed times for really large multiplications
// are reduced somewhat. Well ideally by a factor approaching 3. I set up
// a framework of support for the threads here. A main program thread will
// want its own worker threads here. Each worker thread gets passed a
// nice object called "worker_data" that encapsulates the way it receives
// data from the caller and passes results back.

// Each worker thread needs some data that it shares with the main thread.
// this structure encapsulates that.

// Probably the most "official" way to coordinate threads would be to use
// condition variables, but doing so involves several synchronization
// primitives for each step of the transaction. For the simple level of
// coordination I need here it would be more costly that necessary. I can
// manage here with a scheme that when thread A want to allow thread B to
// proceed it unlocks a mutex that thread B was waiting on. There is some
// mess associated with ensuring that the main thread waits for results and
// that there are no race situations where all threads compete for a single
// mutex.
//
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
// Observe that I can use (n^2) to map between the mutex number in the first
// and second columns here. That counting is what send_count and
// receive_count are doing.

// In a nice world I would use just the C++ std::mutex scheme for
// synchronization, however here I am performance critical and to save
// a bit when performing medium-sized multiplications I will use the
// Microsoft version of mutexes directly on that platform.

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
    bool quit_flag;

    ConstDigitPtr a;   std::size_t lena;
    ConstDigitPtr b;   std::size_t lenb;
    DigitPtr c;
    DigitPtr w;

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

// Then each main thread will have a structure that encapsulated the
// worker threads that it ends up with and the data it sets up for
// them and that they then access. When this structures is created it will
// cause the worker threads and the data block they need to be constructed.

inline void workerThread(WorkerData* wd);

class DriverData
{
public:
    int        send_count = 0;
    int        send_count2 = 0;
    WorkerData wd_0,
               wd_1,
               wd_2;
// When the instance of DriverData is created the three sets of WorkerData
// get constructed with two of their mutexes locked. This will mean that when
// worker threads are created and start running they will politely wait for
// work.

    std::thread w_0, w_1, w_2;
    DriverData()
    {   wd_0.setWhich(0);
        wd_1.setWhich(1);
        wd_2.setWhich(2);
        w_0 = std::thread(workerThread, &wd_0),
        w_1 = std::thread(workerThread, &wd_1);
        w_2 = std::thread(workerThread, &wd_2);
// I busy-wait until all the threads have both claimed the mutexes that they
// need to own at the start! Without this the main thread may post a
// multiplication, so its part of the work and try to check that the worker
// has finished (by claiming one of these mutexes) before the worker thread
// has got started up and has claimed them. This feels clumsy, but it only
// happens at system-startup.
        while (!wd_0.ready.load() &&
               !wd_1.ready.load() &&
               !wd_2.ready.load())
            std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

// When the DriverData object is to be destroyed it must arrange to
// stop and then join the two threads that it set up. This code that sends
// a "quit" message to each thread will be executed before the thread object
// is deleted, and the destructor of the thread object should be activated
// before that of the WorkerData and the mutexes within that.

    ~DriverData()
    {   wd_0.quit_flag = wd_1.quit_flag = wd_2.quit_flag = true;
        releaseWorkers(true);
        w_0.join();
        w_1.join(); // Wait for the threads to shut down.
        w_2.join();
    }

// Using the worker threads is then rather easy: one sets up data in
// the WorkerData structures and then call releaseWorkers(). Then
// you can do your own thing in parallel with the two workers picking up
// the tasks that they had been given. When you are ready you call
// wait_for_workers() which does what one might imagine, and the workers
// are expected to have left their results in the WorkerData object so
// you can find it.

    void releaseWorkers(bool third)
    {
#if defined USE_MICROSOFT_SRW
        ReleaseSRWLockExclusive(&wd_0.mutex[send_count]);
        ReleaseSRWLockExclusive(&wd_1.mutex[send_count]);
        if (third) ReleaseSRWLockExclusive(&wd_2.mutex[send_count2]);
#elif defined USE_MICROSOFT_MUTEX
        ReleaseMutex(wd_0.mutex[send_count]);
        ReleaseMutex(wd_1.mutex[send_count]);
        if (third) ReleaseMutex(wd_2.mutex[send_count2]);
#else // use std::mutex
        wd_0.mutex[send_count].unlock();
        wd_1.mutex[send_count].unlock();
        if (third) wd_2.mutex[send_count2].unlock();
#endif // mutexed unlocked
    }

    void wait_for_workers(bool third)
    {
#if defined USE_MICROSOFT_SRW
        AcquireSRWLockExclusive(&wd_0.mutex[send_count^2]);
        AcquireSRWLockExclusive(&wd_1.mutex[send_count^2]);
        if (third) AcquireSRWLockExclusive(&wd_2.mutex[send_count2^2]);
#elif defined USE_MICROSOFT_MUTEX
// WaitForSingleObject takes a timeout limit measured in milliseconds as
// its second argument. I will allow waits of up to 2 seconds. There
// should be a response by then since the workere are just performing a
// multiplication and at all plausible number-sizes 2 seconds is plenty
// even on slow computers. The main case where there could be
// failure here would be when running under a debugger and with one
// of the worker threads being subject to breaks or single stepping.
        WaitForSingleObject(wd_0.mutex[send_count^2], MICROSOFT_INFINITE);
        WaitForSingleObject(wd_1.mutex[send_count^2], MICROSOFT_INFINITE);
        if (third) WaitForSingleObject(wd_2.mutex[send_count2^2], MICROSOFT_INFINITE);
#else // use std::mutex
        wd_0.mutex[send_count^2].lock();
        wd_1.mutex[send_count^2].lock();
        if (third) wd_2.mutex[send_count2^2].lock();
#endif // synchronized
        send_count = (send_count+1)&3;
        if (third) send_count2 = (send_count2+1)&3;
    }
};

// Even if there are multiple user threads I will only have a single
// instance of DriverData and hence I will always have just three
// worker threads. If multiple threads all call generalMul at (almost) the
// same time a compare-and-exchange operation arranges that only one of
// them gets to offload parts of the multiplication work to those worker
// threads and the others work sequentially. This allows me to have a fixed
// number of worker threads.

static DriverData driverData;

class ManageWorkers
{
public:
    static std::atomic<bool> threadsInUse;
    bool mayUseThreads;
    [[gnu::always_inline]]
    ManageWorkers()
    {   bool expected = false;
        mayUseThreads = threadsInUse.compare_exchange_weak(expected, true);
    }
    [[gnu::always_inline]]
    ~ManageWorkers()
    {   if (mayUseThreads) threadsInUse.store(false);
    }
};

class BigMultiplication
{

// I need some commentary about this! I have three worker threads
// available and a multiplication can decompose either a 2N by 2N
// multiplication into 3 tasks or a 3N by 2N one into 4 tasks.
// If the caller is a multi-threaded program then several of those
// threads might each start to perform a multiplication, but I need to
// ensure that only one of them gets to use the worker threads.
// To achieve this I have an atomic variable threadsInUse and I
// use a compare_exchange operation that will always end up with it
// having the value true, but that leaves mayUseThreads true if it had
// initially been false. The class destructor for ManageWorkers ensures
// that when a scope where use of the worker threads exits the access
// control flag is reset. Using compare_exchange_weak means that requests
// for access to the workers may spuriously fail (!) but the _strong
// version may have higher overheads. On architectures where there is
// a genuine compare-exchange function the spurious failure will not arise,
// but on machines where atomic access is supported using load-locked
// and store-conditional combinations (eg arm processors, including code
// compiled for aarch64 before version 8.1) the store conditional can be
// rejected because some other activity has touched the memory - even if
// the value in the memory is the "expected" one. This can lead the
// compare_exchange to report failure even in a case that could have been
// deemed a success. With low contention this will hardly ever happen!
// But here the worst possible consquence is that the code will drop back
// to do sub-multiplcations sequentially and quite possibly one of those
// will succeed in the compare_exchange and use concurrency only starting
// at its level.

public:

// Multiplications where M and N are both no more than than 7
// are done by unrolled and inlined special code.
// From when the larger is at least KARASTART I will use Karatsuba,
// and from KARABIG on it will not be just Karatsuba but the top
// level decomosition will be run using three threads. Also up as
// far as KARABIG I will use some stack allocated space while from
// there up I will use my "stkvector" scheme so that there is no
// serious limit to the amount that can be used.

static const std::size_t MUL_INLINE_LIMIT = 7;

// The thresholds at which I transition from classical multiplication
// to use of Karatsuba (and Toom-3-2) and the one where I activate
// multiple thhreads may want to differ on different machines. I have
// a range of settings with values based on measurements on machines I
// have access to, but the values may well not be quite optimal even there
// and my machines may not yield the experience that others will have!

// By predefining preprocessor symbols KARASTART and KARABIG I can
// override my defaults here.

#ifndef KARASTART

#if defined WIN32                             // Windows (x86_64)
// Tested using x86_64-w64-mingw-g++ on an Intel i7-8086K. 
static const std::size_t KARASTART = 16;

#elif defined __CYGWIN__                      // Windows (x86_64)
// Tested using Cygwin g++ on an Intel i7-8086K. 
static const std::size_t KARASTART = 16;

#elif defined __APPLE__ && defined __arm64__  // Mac m1, m2, ...
// Tested on Macbook m1.
static const std::size_t KARASTART = 25;

#elif defined __ARM_ARCH_8A                   // Raspberry Pi 5
// Measured in a Raspberry Pi 5 running Raspberry Pi OS in 64-bit mode.
static const std::size_t KARASTART = 16;

#elif defined __ARM_ARCH                      // Other Raspberry Pi etc
// Measured on a Raspberry Pi 5 with its 64-but CPU but using 32-bit
// userland. The use of Karatsuba at 22+ words is not really clear-cut
// but at least it is competitive by then.
static const std::size_t KARASTART = 22;

#else                                         // other (eg generic Linux)
// Figure rather guessed from all the above, but applicable in a Linux
// vm running on the Windows machine I test on!
static const std::size_t KARASTART = 16;
#endif

#endif // KARASTART

#ifndef KARABIG

#if defined WIN32                             // Windows (x86_64)
static const std::size_t KARABIG = 60;
#elif defined __CYGWIN__                      // Cygwin/Windows (x86_64)
static const std::size_t KARABIG = 65;
#elif defined __APPLE__ && defined __arm64__  // Mac m1, m2, ...
static const std::size_t KARABIG = 352;
#elif defined __ARM_ARCH_8A                   // Raspberry p 5
static const std::size_t KARABIG = 72;
#elif defined __ARM_ARCH                      // Other Raspberry pi etc
static const std::size_t KARABIG = 50;
#else                                         // other (eg generic Linux)
static const std::size_t KARABIG = 144;
#endif

#endif // KARABIG

private:

[[gnu::always_inline]]
static std::size_t workspaceSize(std::size_t M)
{   return 6*M;
}

// At the top level toom32<true>() can use a little over 7*L workspace for
// itself, where L=max(N/3,M/2). But N<=1.85*M and M is large enough that
// I will ignore rounding. Then plus the need for four parallel
// sub-multiplications. I will use a rounded up 2M/3 as my bound on L.

[[gnu::always_inline]]
static std::size_t topWorkspaceSize(std::size_t M)
{   size_t toomLen = (2*M+2)/3;
    return 7*toomLen + 4*workspaceSize(toomLen);
}

public:

// verySimpleMul exists ONLY for testing - specifically to generate
// reference products that the output from other more complicated code
// can be compared against.

static void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   Digit carry = 0, lo = 0, hi = 0;
    for (std::size_t k=0; k<N+M-1; k++)
    {   for (std::size_t i=0; i<N; i++)
        {   if (k < i) continue;
            if (k-i >= M) continue;
            Digit hi1;
            multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+M-1] = lo;
}

private:

// I have a general idiom I intend to use for loops where the
// body of the iteration is small. If one has
//     for (i=A; i<B; i++) { X(i); }
// I will unroll the loop, writing
//     for (i=A; i<B-1; i+=2)
//     {   X(i);
//         X(i+1);
//     }
//     if (i<B) { X(i); i++; }
// This adds to the cost if the loop is traversed only once, is broadly
// cost neutral if it is traversed twice and from there up it saves tests
// and control-flow. Of course it increases code bulk. 

// Here I have classical multiplication for the case N>=M and as
// used here M>7. This is written out as succession of 3 loops since
// that leads to each having simpler start and end conditions, and I
// hope that reduces overhead.

static void simpleMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// For this I will require N>=M
    Digit carry = 0, lo, hi = 0, hi1;
// The lowest Digit can be handled specially to get things going.
    multiply64(a[0], b[0], lo, result[0]);
    std::size_t k=1;
    for (; k<M; k++)
    {   std::size_t i;
// Here I want k<M<=N so certainly if i<k then i<N
//@@ The code shown with "//@@" here is the simple presentation of this
//@@ loop, but the actual code unrolls the loop so that two steps are
//@@ taken in each iteration (and potentially a final one is needed at
//@@ the end. This is done to reduce loop overhead.
//@@    for (i=0; i<=k; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        for (i=0; i<=k-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<=k)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Now k>=M, I want i<=k to imply i<N so go as far as k<N
    for (; k<N; k++)
    {
//@@    for (std::size_t j=0; j<M; j++)
//@@    {
//@@ // Ha ha in this loop I iterate on j=k-i which makes the loop
//@@ // just a little nicer to express.
//@@        multiply64(a[k-j], b[j], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t j;
        for (j=0; j<M-1; j+=2)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[k-j-1], b[j+1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (j<M)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Finally k>=N so i<N will imply i<=k
    for (; k<N+M-1; k++)
    {
//@@    for (std::size_t i=k+1-M; i<N; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t i;
        for (i=k+1-M; i<N-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<N)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// The very final digit of the result drops out here.
    result[k] = lo;
}


private:

// Now I want code for multiplying N*M digit numbers with N up to some
// small limit as fast as I can. Here I have all the cases with both
// N and M up to 7 covered. Also cases where N=M<=14 and ones where
// M<=7 but N can be arbitrary. These cases represent bulky and perhaps
// ugly in-line code but I expect them to be the most performance
// critical parts of the base for multiplication.

#include "inlinemul.cpp"

// The vector a has M digits and result has N (with N>=M). Add the
// value in a into result and return any carry.

static Digit addMdigits(ConstDigitPtr a, std::size_t M, DigitPtr result, std::size_t N)
{   Digit carry = addWithCarry(a[0], result[0], result[0]);
    std::size_t i=1;
//@@for (; i<M; i++)
//@@    carry = addWithCarry(a[i], result[i], carry, result[i]);
    for (; i<M-1; i+=2)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        carry = addWithCarry(a[i+1], result[i+1], carry, result[i+1]);
    }
    if (i<M)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        i++;
    }
    while (carry != 0 && i<N)
    {   carry = addWithCarry(result[i], 1, result[i]);
        i++;
    }
    return carry;
}

// result = a + b with a carry-in

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     Digit carry,
                     DigitPtr result)
{   std::size_t i;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    for (i=0; i<lenB-1; i+=2)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        carry = addWithCarry(a[i+1], b[i+1], carry, result[i+1]);
    }
    if (i<lenB)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        carry = addWithCarry(a[i], carry, result[i]);
    return carry;
}

// result = a + b

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     DigitPtr result)
{   return karaAdd(a, lenA, b, lenB, 0, result);
}

// result = a - b

[[gnu::always_inline]]
static Digit karaSubtract(ConstDigitPtr a, std::size_t lenA,
                          ConstDigitPtr b, std::size_t lenB,
                          DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        borrow = subtractWithBorrow(a[i+1], b[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(a[i], 0, borrow, result[i]);
    return borrow;
}

// result = b - a;

[[gnu::always_inline]]
static Digit karaRevSubtract(ConstDigitPtr a, std::size_t lenA,
                             ConstDigitPtr b, std::size_t lenB,
                             DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        borrow = subtractWithBorrow(b[i+1], a[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        i++;
    }
    for (; i<lenA; i++)
        borrow = subtractWithBorrow(0, a[i], borrow, result[i]);
    return borrow;
}

// Replace a and b with a-b and a+b.

[[gnu::always_inline]]
static void karaDifferenceAndSum(DigitPtr a, DigitPtr b,
                                 std::size_t len,
                                 Digit& carry,
                                 Digit& borrow)
{   carry = borrow = 0;
    for (std::size_t i=0; i<len; i++)
    {   Digit aa = a[i], bb = b[i];
        borrow = subtractWithBorrow(aa, bb, borrow, a[i]);
        carry = addWithCarry(aa, bb, carry, b[i]);
    }
}

// Propogate a carry.

[[gnu::always_inline]]
static void karaCarry(Digit carry, DigitPtr v)
{   size_t i = 0;
    while (carry != 0)
    {   carry = addWithCarry(v[i], carry, v[i]);
        i++;
    }
}

// Propogate a borrow.

[[gnu::always_inline]]
static void karaBorrow(Digit borrow, DigitPtr v)
{   size_t i = 0;
    while (borrow != 0)
    {   borrow = subtractWithBorrow(v[i], borrow, v[i]);
        i++;
    }
}

// This divides a value by 2, where the value has a signed top digit
// and a vector of unsigned additional digits.

static SignedDigit karaHalve(SignedDigit top, DigitPtr a, std::size_t len)
{   Digit carry = top & 1;
    top = top - carry;
    for (size_t i=len-1; i!=0; i--)
    {   Digit w = a[i];
        a[i] = (w>>1) | (carry<<63);
        carry = w & 1;
    }
    a[0] = (a[0]>>1) | (carry<<63);
    return top/2;
}

[[gnu::always_inline]]
static void differenceLengthsMatch(ConstDigitPtr low, std::size_t length,
                                   ConstDigitPtr high, DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
//@@for (std::size_t i=1; i<length; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    std::size_t i;
    for (i=1; i<length-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<length)
        borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
}

[[gnu::always_inline]]
static bool differenceLengthsDiffer(ConstDigitPtr low, std::size_t lenLow,
                                    ConstDigitPtr high, std::size_t lenHigh,
                                    DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
    std::size_t i=1;
//@@for (; i<lenHigh; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    for (; i<lenHigh-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<lenHigh)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        i++;
    }
// I will not unwind this loop because I expect that lenHigh will usually
// be very close to lenLow so there will be little to save.
    for (; i<lenLow; i++)
        borrow = subtractWithBorrow(low[i], borrow, result[i]);
    if (borrow == 0) return false;
// If necessary negate the result. This case arises if low has at least one
// zero leading digit and is less that high in magnitide.
    borrow = 0;
    for (i=0; i<lenLow; i++)
        borrow = subtractWithBorrow(0, result[i], borrow, result[i]);
    return true;
}

// set result = |low-high| and return true if high>low.
// A special feature here is that the "low" values here can have
// leading zeros - for instance consider the partitioned form of
// the number 1234_5678:0000_0234_5678 where I have used ":" to mark
// where the whole number is split into high and low parts. The high
// part has 2 digits and the low has 3, however the low part has the
// smaller value. So in that case the correct absolute value of
// the differenfce will be 0000_1000_0000

[[gnu::always_inline]]
static bool absDifference(ConstDigitPtr low, std::size_t lenLow,
                          ConstDigitPtr high, std::size_t lenHigh,
                          DigitPtr result)
{   if (lenHigh != lenLow)
        return differenceLengthsDiffer(low, lenLow, high, lenHigh, result);
// Here the two numbers both have the same number of digits. I need to
// work out which is the larger. Usually I will only need to look at
// the top digit. On that basis I make the code capable of scanning all
// the way down the number.
// An alternative stretegy would be do compute (low-high) always, detect
// a borrow at the end (ie that the difference was negative) and in that
// case negate the answer. That might do a full linear-cost negation about
// half the time where what I do here frequently only tests one digit.
    std::size_t i = lenLow-1; 
    for (;;)
    {   if (high[i] < low[i])
        {   differenceLengthsMatch(low, lenLow, high, result);
            return false;
        }
        else if (high[i] > low[i])
        {   differenceLengthsMatch(high, lenLow, low, result);
            return true;
        }
        if (i == 0)   // Here the two numbers are equal.
        {   std::memset(result, 0, lenLow*sizeof(Digit));
            return false;
        }
        i--;
    }
}

//=========================================================================

// Some of the functions here have are templated with a boolean
// called "thread". When this is true the code is entitled to cause
// worker threads to be launched to perform subsidiary multiplications.
// The multi-thread decomposition may only happen once, and that is enforced
// by making thread=false for all the lower level calls.

// Now the main entrypoint to my new code for multiplying
// unsigned values. It tries to put simple cheap tests to spot
// cheap cases inline and then dispatch to the separate procedures
// that apply in each case.
//
// I make this function "always-inline" and what it expands to is
// really just
//     check for 1*1
//     check for up to 7*7
//     get args in correct order and check for 7*N
//     check for cases where Karatsuba will not be needed
//         special on N*N up to 14*14
//         OR general case of classical numtiplication
//     go to general harder case
// where each of the above is a fairly simple test on the
// size of the inputs and in each case the behaviour triggered is
// to call a function that is not tagged as always-inline.

public:

[[gnu::always_inline]]
static void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{
// I take a view that case of single word multiplication as both so
// special and so important that I do that in-line here.
    if ((N|M) == 1)
    {   multiply64(a[0], b[0], 0, result[1], result[0]);
        return;
    }
// I next have special treatment for all the cases where both M and N are
// at most 7. I make the cut off there because I can test if either N
// or M exceeds the bound using a bitwide OR here which I expect to be
// nice and cheap! Also because I expect small cases like this to be
// especially commonly used, and to be ones where loop overheads might
// intrude.
    if ((N|M) <= 7)
    {   LIKELY
        smallCaseMul(a, N, b, M, result);
        return;
    }
    if (N < M)
    {   std::swap(a, b);
        std::swap(N, M);
    }
// If the smaller number is fairly small I again use classical long
// multiplication, but with the inner loop unrolled.
    if (M <= 7)
    {   bigBySmallMul(a, N, b, M, result);
        return;
    }
    if (M < KARASTART)    // Too small for Karatsuba.
    {   if (N==M) balancedMul(a, b, N, result);
        else simpleMul(a, N, b, M, result);
    }
    else biggerMul(a, N, b, M, result);
}

private:

static void biggerMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// Now manager.mayUseThreads will be true if I am allowed to use the
// worker threads.
//
// Now look at out-of balance cases. Here I take the view that if N>1.5M
// I will hive off toom32 multiplications as much as I can. They will each
// be (3*M)/2xM and I need M space to keep some digits already computed that I
// will need to combine with the output from the next square multiply.
#ifdef TRACE_TIMES
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
    size_t w = topWorkspaceSize(M);
    stkvector<Digit> workspace(w);
    ManageWorkers manager;
    if (4*N <= 5*M)
    {
        if (N < KARABIG || !manager.mayUseThreads)
            kara(a, N, b, M, result, workspace);
        else kara<true>(a, N, b, M, result, workspace);
    }
    else if (20*N <= 37*M)
    {
        if (N < KARABIG || !manager.mayUseThreads)
            toom32(a, N, b, M, result, workspace);
        else toom32<true>(a, N, b, M, result, workspace);
#ifdef TRACE_TIMES
        display("toom32res", result, N+M);
#endif // TRACE_TIMES
    }
    else 
    {
        if (manager.mayUseThreads)
            innerGeneralMul<true>(a, N, b, M, result, workspace);
        else innerGeneralMul(a, N, b, M, result, workspace);
#ifdef TRACE_TIMES
        display("unbalancedres", result, N+M);
#endif // TRACE_TIMES
    }
}

// When thread is false this is being used when Kara or Toom32
// recurses and so most of the time we will have M==N>KARASTART/2. With
// thread true it is from the top-level and may fire up some workers.

template <bool thread=false>
[[gnu::always_inline]]
static void innerGeneralMul(ConstDigitPtr a, std::size_t N,
                            ConstDigitPtr b, std::size_t M,
                            DigitPtr result,
                            DigitPtr workspace)
{
#ifdef TRACE_TIMES
    displayIndent += 2;
    display("innergenerala", a, N);
    display("innergeneralb", b, M);
    displayIndent -= 2;
#endif // TRACE_TIMES
    if constexpr (!thread)
    {   if ((N|M) <= 7)
        {   smallCaseMul(a, N, b, M, result);
            return;
        }
        if (N < M)
        {   std::swap(a, b);
            std::swap(N, M);
        }
        if (M <= 7)
        {   bigBySmallMul(a, N, b, M, result);
            return;
        }
        if (M < KARASTART)    // Too small for Karatsuba.
        {   if (N==M) balancedMul(a, b, N, result);
            else simpleMul(a, N, b, M, result);
            return;
        }
    }
#ifdef TRACE_TIMES
    displayIndent += 2;
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
// Here I will call Kara if N <= 1.25*M.
    if (4*N <= 5*M) kara<thread>(a, N, b, M, result, workspace);
// If N <= 1.85*M I will use toom32.
    else if (20*N <= 37*M) toom32<thread>(a, N, b, M, result, workspace);
    else innerBigMul<thread>(a, N, b, M, result, workspace);
    displayIndent -= 2;
}

// This version is just for N*N products - a case which arises in recursive
// calls from Karatsuba and Toom32. These are never top level!

[[gnu::always_inline]]
static void innerGeneralMul(ConstDigitPtr a, std::size_t N,
                            ConstDigitPtr b,
                            DigitPtr result,
                            DigitPtr workspace)
{   if (N < KARASTART) balancedMul(a, b, N, result);
    else kara(a, N, b, N, result, workspace);
}

template <bool thread=false>
static void innerBigMul(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b, std::size_t M,
                        DigitPtr result,
                        DigitPtr workspace)
{
#ifdef TRACE_TIMES
    display2("% innerBigMul", N, M);
    DigitPtr fullResult = result;
    size_t fullSize = M+N;
#endif // TRACE_TIMES
    DigitPtr save = setSize(workspace, M);
    workspace += M;
    size_t step = (3*M)/2;
#ifdef TRACE_TIMES
    display2("innerBig starting toom of", step, M);
#endif // TRACE_TIMES
    toom32<thread>(a, step, b, M, result, workspace);
#ifdef TRACE_TIMES
    display("firsttoom32res", result, step+M);
#endif // TRACE_TIMES
    a += step;
    N -= step;
    result += step;
#ifdef TRACE_TIMES
    display("topoftoom32res", result, M);
#endif // TRACE_TIMES
    for (;;)
    {   while (N >= step)
        {   std::memcpy(save, result, M*sizeof(Digit));
#ifdef TRACE_TIMES
            display("save", save, M);
            display2("% Another ", step, M);
#endif // TRACE_TIMES
            toom32<thread>(a, step, b, M, result, workspace);
            addMdigits(save, M, result, step+M);
#ifdef TRACE_TIMES
            display("partial", result, step+M);
#endif // TRACE_TIMES
            a += step;
            N -= step;
            result += step;
        }
        if (N == 0) return;
// Here N < 1.5*M. If N>=M I can finish the job using a single step that
// is either Toom32 or Karatsuba. And I should also take this case
// if N<KARASTART. Also if N>=M/1.25 I can finish with Karatsuba. This
// set of end conditions is more complicated than I had originally thought!
#ifdef TRACE_TIMES
        display2("% End bit ", N, M);
#endif // TRACE_TIMES
        std::memcpy(save, result, M*sizeof(Digit));
#ifdef TRACE_TIMES
        display("save", save, M);
#endif // TRACE_TIMES
        if (4*N > 5*M) toom32<thread>(a, N, b, M, result, workspace);
        else if (N >= M) kara<thread>(a, N, b, M, result, workspace);
// Now N < M so I need to flip order for the calls...
        else if (N < KARASTART) simpleMul(b, M, a, N, result);
        else if (5*N >= 4*M) kara<thread>(b, M, a, N, result, workspace);
// Should I worry about the potential recursion depth here?
// I will consider how the product M*N decreases rather than how either
// separately changes. One limiting case is if a single Karatsuba has
// been done so far. Then what remains must have N>M/2 because otherwise
// a Toom32 step would have been taken. The result is that M*N is reduced
// to less than 1/3 of its initial value. Now suppose that the first step
// had been toom32 and what is left is not enough for a Karatsuba. We have
// less then M*M left where initially there was (5/2)*M*M so we have at
// worst 2/5 of the original size: this case is worse than the one that
// started with Karatsuba. In each situation the fact that I will be willing
// to perform a final Karatsuba even if its slightly unbalanced makes
// this analysis conservative. Furthermore if at one step I approach the
// limit that I identify here it means that the next step is "almost square"
// and the next one can not be as bad! So analyzing a worst case through
// layers of recursion seems hard. So instead I ran code that tried
// comprehensive ranges of M and N and that showed that for large inputs the
// worst depth observed was 1.5*log2(min(N,M)) for cases where M and N
// would possibly reach here.
        else innerGeneralMul<thread>(b, M, a, N, result, workspace);
#ifdef TRACE_TIMES
        display("addin", result, N+M);
#endif // TRACE_TIMES
        addMdigits(save, M, result, N+M);
#ifdef TRACE_TIMES
        display("resulthere", result, N+M);
        display("full result", fullResult, fullSize);
        display("innerBigMul done");
#endif // TRACE_TIMES
        return;
    }
}

// I have code for multiplying N*M numbers when N is about
// 1.5 times M. This splits the big number into 3 chunks and the
// smaller into two.
//
// Here is a description of the procedure in a somewhat readable compact form.
//
// a := ahigh*x^2 + amid*x + alow;
// b :=            bhigh*x + blow;      
//
// x^3 * (ahigh*bhigh) +
// x^2 * (ahigh*blow + amid*bhigh) +
// x   * (alow*bhigh + amid*blow) +
//       (alow*blow)
//
// asum := ahigh+amid+alow;    preserve carry
// bsum := bhigh+blow;         preserve carry
// adiff := ahigh-amid+alow;   preserve carry or borrow
// bdiff := blow-bhigh;        preserve borrow
// d0 := alow*blow;
// d1 := asum*bsum;            adjust for carries, borrows in asum, bsum,
// d2 := adiff*bdiff;          adiff, bdiff and generate carries or borrows.
// d3 := ahigh*bhigh;
//
// d0                                alow*blow
// (d1,d2) = (d1-d2,d1+d2)           record carries
// d1 := d1/2 - p3;                  alow*bhigh + amid*blow   record carry etc
// d2 := d2/2 - p0;                  ahigh*blow + amid*bhigh  record carry etc
// d3                                ahigh*bhigh
//
// merge d1, d2 in accounting for how they overlap each other and d0, d3.

template <bool thread=false>
static void toom32(ConstDigitPtr a, std::size_t N,
                   ConstDigitPtr b, std::size_t M,
                   DigitPtr res,
                   DigitPtr workspace)
{
// I will start by viewing a as (ahigh, amid, alow) and b as (bhigh, blow)
// where amid, alow, blow all have the same size (toomLen). Then
// ahigh and bhigh need to have at least some digits but may not have more
// then toomLen.
// I let a(t) = ahigh*t^2 + amid*t + alow and b(t) = bhigh*t + blow.
// then I evaluate a() and b() at 0, +1, -1 and infinity - then I can
// interpolate through products of those values to get digits for my result.
// A classical 3x2 multiplication would use 6 partial products - this uses
// just 4 but obviously a bunch of extra additions and subtractions together
// with some general overhead. 
    size_t toomLen = std::max((N+2)/3, (M+1)/2);
#ifdef DEBUG
    assert(3*toomLen >= N && N > 2*toomLen);
    assert(2*toomLen >= M && M > toomLen);
    assert(N > 2*toomLen);
#endif // DEBUG
    size_t aHighLen = N-2*toomLen;
    size_t bHighLen = M-toomLen;
#ifdef DEBUG
    assert(aHighLen <= toomLen);
#endif // DEBUG
#ifdef TRACE_TIMES
    if constexpr (thread)
        display2("start parallel toom32", N, M);
    else display2("start toom32", N, M);
    display2("toomlen, aHighen", toomLen, aHighLen);
    display2("toomlen, bHighen", toomLen, bHighLen);
    display("tooma", a, N);
    display("toomb", b, M);
//@ display("ahigh", a+2*toomLen, aHighLen);
//@ display("amid",  a+toomLen,   toomLen);
//@ display("alow",  a,           toomLen);
//@ display("bhigh", b+toomLen,   bHighLen);
//@ display("blow",  b,           toomLen);
#endif // TRACE_TIMES
    ConstDigitPtr aLow = a;
    ConstDigitPtr aMid = a + toomLen;
    ConstDigitPtr aHigh = aMid + toomLen;
    ConstDigitPtr bLow = b;
    ConstDigitPtr bHigh = b + toomLen;

    DigitPtr aSum, aDiff, bSum, bDiff, D0, D1, D2, D3;
    Digit aSumTop, bSumTop;
    SignedDigit aDiffTop, bDiffTop, D1Top, D2Top;
    if constexpr (thread)
    {   aSum = setSize(workspace+4*toomLen, toomLen);
        aDiff = setSize(workspace+5*toomLen, toomLen);
        bSum = setSize(workspace+6*toomLen, toomLen);
        bDiff = setSize(res+2*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 7*toomLen, 4*workspaceSize(toomLen));
    }
    else
    {   aSum = setSize(res, toomLen);
        aDiff = setSize(res+toomLen, toomLen);
        bSum = setSize(res+2*toomLen, toomLen);
        bDiff = setSize(res+3*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 4*toomLen, workspaceSize(toomLen));
    }
    aSumTop = karaAdd(aLow, toomLen, aHigh, aHighLen, aSum);
    aDiffTop = aSumTop - karaSubtract(aSum, toomLen, aMid, toomLen, aDiff);
    aSumTop += karaAdd(aMid, toomLen, aSum, toomLen, aSum);
    bSumTop = karaAdd(bLow, toomLen, bHigh, bHighLen, bSum);
    bDiffTop = -karaSubtract(bLow, toomLen, bHigh, bHighLen, bDiff);
#ifdef TRACE_TIMES
//@ display("asum", aSumTop, aSum, toomLen);
//@ display("adiff", aDiffTop, aDiff, toomLen);
//@ display("bsum", bSumTop, bSum, toomLen);
//@ display("bdiff", bDiffTop, bDiff, toomLen);
#endif // TRACE_TIMES
    if constexpr (thread)
    {   std::size_t wsize = workspaceSize(toomLen);
        setupKara(driverData.wd_2, aLow, toomLen, bLow, toomLen, D0,
                                   setSize(workspace, wsize));
        setupKara(driverData.wd_0, aSum, toomLen, bSum, toomLen, D1,
                                   setSize(workspace+wsize, wsize));
        setupKara(driverData.wd_1, aDiff, toomLen, bDiff, toomLen, D2,
                                   setSize(workspace+2*wsize, wsize));
        driverData.releaseWorkers(true);
        innerGeneralMul(aHigh, aHighLen, bHigh, bHighLen, D3,
                        setSize(workspace+3*wsize, wsize));
        driverData.wait_for_workers(true);
#ifdef CHECK_TIMES
// Here I will repeat each of the thread-run multiplications to check them.
        stkvector<Digit> TD0(2*toomLen);
        stkvector<Digit> TD1(2*toomLen);
        stkvector<Digit> TD2(2*toomLen);
        stkvector<Digit> TD3(2*toomLen);
        simpleMul(aLow, toomLen, bLow, toomLen, TD0);
        simpleMul(aSum, toomLen, bSum, toomLen, TD1);
        simpleMul(aDiff, toomLen, bDiff, toomLen, TD2);
        simpleMul(aHigh, aHighLen, bHigh, bHighLen, TD3);
        int errcount = 0;
        for (size_t i=0; i<2*toomLen;i++)
        {   if (D0[i] != TD0[i])
            {   if (errcount < 5) std::printf("lowprod digit %d\n", (int)i);
                errcount++;
            }
            if (D1[i] != TD1[i])
            {   if (errcount < 5) std::printf("D1 digit %d\n", (int)i);
                errcount++;
            }
            if (D2[i] != TD2[i])
            {   if (errcount < 5) std::printf("D2 digit %d\n", (int)i);
                errcount++;
            }
            if (i < aHighLen+bHighLen && D3[i] != TD3[i])
            {   if (errcount < 5) std::printf("highprod digit %d\n", (int)i);
                errcount++;
            }
        }
        if (errcount != 0)
        {   std::printf("\n%%%%@@@ %d FAILURES\n", errcount);
            display("a", a, N);
            display("b", b, M);
            display("alow", a, toomLen);
            display("amid", aMid, toomLen);
            display("ahigh", aHigh, aHighLen);
            display("asum", aSum, toomLen);
            display("adiff", aDiff, toomLen);
            display("blow", b, toomLen);
            display("bhigh", bHigh, bHighLen);
            display("bsum", bSum, toomLen);
            display("bdiff", bDiff, toomLen);
            display("D0", D0, 2*toomLen);
            display("D1", D1, 2*toomLen);
            display("D2", D2, 2*toomLen);
            display("D3",  D3, aHighLen+bHighLen);
            display("TD0", TD0, 2*toomLen);
            display("TD1", TD1, 2*toomLen);
            display("TD2", TD2, 2*toomLen);
            display("TD3", TD3, aHighLen+bHighLen);
            std::abort();
        }
#endif // CHECK_TIMES
    }
    else
    {   innerGeneralMul(aSum, toomLen, bSum, D1, workspace);
//      + aSumTop*bSum + bSumTop*aSum + aSumTop*bSumTop
        innerGeneralMul(aDiff, toomLen, bDiff, D2, workspace);
//      + aDiffTop*bDiff + bDiffTop*aDiff + aDiffTop*bDiffTop
// noting that aDiffTop and bDiffTop are signed values.
    }
#ifdef TRACE_TIMES
//@ display("sumprod", D1, 2*toomLen);
//@ display("diffprod", D2, 2*toomLen);
#endif // TRACE_TIMES
    D1Top = 0;
    switch (aSumTop)
    {   case 2:
            D1Top = karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            [[fallthrough]];
        case 1:
            D1Top += karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            break;
        case 0:
            break;
    }
    if (bSumTop != 0)
        D1Top += karaAdd(aSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
    D1Top += aSumTop*bSumTop;   
    D2Top = 0;
    switch (aDiffTop)
    {   case 1:
            D2Top = karaAdd(bDiff, toomLen, D2+toomLen, toomLen, D2+toomLen);
            break;
        case -1:
            D2Top = -karaSubtract(D2+toomLen, toomLen,
                                  bDiff, toomLen, D2+toomLen);
            break;
        case 0:
            break;
    }        
    switch (bDiffTop)
    {   case -1:
            D2Top -= karaSubtract(D2+toomLen, toomLen,
                                  aDiff, toomLen, D2+toomLen);
        break;
    }
    D2Top += aDiffTop*bDiffTop;   
#ifdef TRACE_TIMES
//@ display("sumprod1", D1Top, D1, 2*toomLen);
//@ display("diffprod1", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
// Now set D1 = D1-D2, D2=D1+D2
    Digit carry, borrow;
    karaDifferenceAndSum(D1, D2, 2*toomLen, carry, borrow);
    SignedDigit tempD1Top = D1Top - D2Top - borrow;
    D2Top = D1Top + D2Top + carry;
    D1Top = tempD1Top;
#ifdef TRACE_TIMES
//@ display("diff", D1Top, D1, 2*toomLen);
//@ display("sum", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
// Halve both of these
    D1Top = karaHalve(D1Top, D1, 2*toomLen);
    D2Top = karaHalve(D2Top, D2, 2*toomLen);
#ifdef TRACE_TIMES
//@ display("halfdiff", D1Top, D1, 2*toomLen);
//@ display("halfsum", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
    if constexpr (!thread) // These already computed in the threaded version
    {   innerGeneralMul(aLow, toomLen, bLow, D0, workspace);
        innerGeneralMul(aHigh, aHighLen, bHigh, bHighLen, D3, workspace);
    }
#ifdef TRACE_TIMES
//@ display("D0", D0, 2*toomLen);
//@ display("D3", D3, aHighLen+bHighLen);
#endif // TRACE_TIMES
// I need to D1 -= D3; D2 -= D0;
    D1Top -= karaSubtract(D1, 2*toomLen, D3, aHighLen+bHighLen, D1);
    D2Top -= karaSubtract(D2, 2*toomLen, D0, 2*toomLen, D2);
#ifdef TRACE_TIMES
//@ display("fixedD1", D1, 2*toomLen);
//@ display("fixedD2", D2, 2*toomLen);
#endif // TRACE_TIMES
// Now to assemble the final result I just need to cope with the fact
// the the partial products P0, D1, D1 and P3 overlap.
// So now I have
//   res:   D3hi  D3lo   xxx   D0Hi D0Lo
//                D1Top  D1Hi  D1Lo
//          D2Top D2Hi   D2Low
    carry = karaAdd(D1, toomLen,                    // D1Lo
                    res+toomLen, toomLen,           // D0Hi
                    res+toomLen);
    carry = karaAdd(D1+toomLen, toomLen,            // D1Hi
                    D2, toomLen, carry,             // D2Lo
                    res+2*toomLen);
    carry = karaAdd(D2+toomLen, toomLen,            // D2Hi
                    res+3*toomLen, toomLen, carry,  // D3Lo
                    res+3*toomLen);
    // karaCarry(carry, res+4*toomLen); by adding carry into D2Top I do this
    D2Top += carry;
// I need to merge in D1Top and D2TOP. Note that either could be positive
// or negative, and that is part of why I did not merge them in earlier.
    if (D1Top > 0)      karaCarry(D1Top, res+3*toomLen);
    else if (D1Top < 0) karaBorrow(-D1Top, res+3*toomLen);
    if (D2Top > 0)      karaCarry(D2Top, res+4*toomLen);
    else if (D2Top < 0) karaBorrow(-D2Top, res+4*toomLen);
#ifdef TRACE_TIMES
    display("result", res, M+N);
    display("toom32 finishing");
#endif // TRACE_TIMES
}

[[gnu::always_inline]]
static void setupKara(arithlib_implementation::WorkerData& wd,
                      ConstDigitPtr a, std::size_t lena,
                      ConstDigitPtr b, std::size_t lenb,
                      DigitPtr result,
                      DigitPtr workspace)
{   wd.a = a;
    wd.lena = lena;
    wd.b = b;
    wd.lenb = lenb;
    wd.c = result;
    wd.w = workspace;
}

// This is the entrypoint for Karatsuba multiplication, and it
// will be called with N>=M amd with a workspace vector big enough for
// its needs.

// a := ahigh*x + alow;
// b := bhigh*x + blow;
//
// x^2 * (ahigh*bhigh) +
// x   * (alow*bhigh + ahigh*blow) +
//       (alow*blow)
//
// adiff := alow-ahigh;
// bdiff := blow-bhigh;
// p0 := alow*blow;
// p1 := adiff*bdiff;       ahigh*bhigh + alow*blow - alow*bhigh - ahigh*blow
// p2 := ahigh*bhigh;
//
// d0 := p0;                alow*blow
// d1 := p0 + p2 - p1;      alow*bhigh + amid*blow
// d2 := p2;                ahigh*bhigh
//
// Well sometimes adiff and/or bdiff are computed with the subtraction
// the other way round so as to leave a positive value there. In which
// case we need
// d1 := p1 - p0 - p2;      alow*bhigh + amid*blow

template <bool thread=false>
static void kara(ConstDigitPtr a, std::size_t N,
                 ConstDigitPtr b, std::size_t M,
                 DigitPtr result,
                 DigitPtr workspace)
{   std::size_t lowSize = (N+1)/2;
    std::size_t aHighLen = N-lowSize;
    std::size_t bHighLen = M-lowSize;
    ConstDigitPtr aHigh = a+lowSize;
    ConstDigitPtr bHigh = b+lowSize;
#ifdef TRACE_TIMES
    if constexpr (thread)
        display2("start parallel kara", N, M);
    else display2("start kara", N, M);
    display("ahigh", aHigh, aHighLen);
    display("alow", a, lowSize);
    display("bhigh", bHigh, bHighLen);
    display("blow", b, lowSize);
#endif // TRACE_TIMES
// I have now split a and b into low and and high parts where the two
// low parts are half the size of the larger input (rounded up if that
// was odd). I now want to form |aHigh - aLow| and similarly for b
// keeping track of whether taking the absolute values involved a sign flip.
    DigitPtr aDiff, bDiff;
    DigitPtr ws;
    std::size_t wsize = workspaceSize(lowSize);
    if constexpr (thread)
    {   aDiff = workspace+2*lowSize;
        bDiff = workspace+3*lowSize;
        ws = workspace+4*lowSize;
    }
    else
    {   aDiff = result;
        bDiff = result+lowSize;
        ws = workspace+2*lowSize;
    }
    bool sign = absDifference(a, lowSize, aHigh, aHighLen, aDiff);
    if (absDifference(b, lowSize, bHigh, bHighLen, bDiff)) sign = !sign;
#ifdef TRACE_TIMES
    display("adiff", aDiff, lowSize);
    display("bdiff", bDiff, lowSize);
    std::cout << "% sign = " << sign << "\n";
#endif // TRACE_TIMES
    if constexpr (thread)
    {   setupKara(driverData.wd_0, aDiff, lowSize,
                                   bDiff, lowSize, workspace,
                                   setSize(ws, wsize));
        setupKara(driverData.wd_1, a, lowSize,
                                   b, lowSize, result,
                                   setSize(ws+wsize, wsize));
// Let the thread run while I do aHigh*bHigh. I expect that I will only
// launch threads when the inputs are rather large, and in particular large
// enough that the half-sized multiplications triggered here will be
// Karatsuba rather than classical.
        driverData.releaseWorkers(false);
        // Do this while worker threads do their stuff.
        innerGeneralMul(aHigh, aHighLen,
                        bHigh, bHighLen, result+2*lowSize,
                        setSize(ws+2*wsize, wsize));
        driverData.wait_for_workers(false);
    }
    else
    {   innerGeneralMul(aDiff, lowSize,
                        bDiff, workspace, ws);
        innerGeneralMul(a, lowSize,
                        b, result, ws);
        innerGeneralMul(aHigh, aHighLen,
                        bHigh, bHighLen, result+2*lowSize, ws);
    }
#ifdef TRACE_TIMES
    display("lowprod", result, 2*lowSize);
    display("midprod", workspace, 2*lowSize);
    display("highprod", result+2*lowSize, aHighLen+bHighLen);
#endif // TRACE_TIMES
// At this stage result has aHigh*bHigh in its top half and aLow*bLow
// in its bottom half. Then workspace hold aDiff*bDiff. I now need to
// combine these to get my final result. 
// If sign is false workspace holds aHigh*bHigh+aLow*bLow-middleTerms
// so I want to go
// 1.    workspace = aHigh*bHigh - workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// Step 1 can generate a borrow and step 2 a carry, so on input to step 3
// there is an extra -1, 0 or +1 to deal with.
// If sign is true I want
// 1.    workspace = aHigh*bHigh + workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// and now each of steps 1 and 2 may generate a carry, so step 3 starts
// with an extra 0, +1 or +2.
    int extra = 0;
    if (sign) extra =
        karaAdd(workspace, 2*lowSize,
                result+2*lowSize, aHighLen+bHighLen,
                workspace);
    else extra =
        -karaRevSubtract(workspace, 2*lowSize,
                         result+2*lowSize, aHighLen+bHighLen,
                         workspace);
    extra += karaAdd(result, 2*lowSize,
                     workspace, 2*lowSize, workspace);
// extra can now be -1, 0, 1 or 2
    Digit carry = karaAdd(workspace, 2*lowSize,
                          result+lowSize, 2*lowSize, result+lowSize);
    karaCarry(carry, result+3*lowSize);
    if (extra > 0) karaCarry(extra, result+3*lowSize);
    else if (extra < 0) karaBorrow(-extra, result+3*lowSize);
#ifdef TRACE_TIMES
    display("result", result, M+N);
    display("end of kara");
#endif // TRACE_TIMES
}  

public:

#if defined USE_MICROSOFT_SRW

static void workerThread(WorkerData* wd)
{   ThreadLocal::initialize();
    AcquireSRWLockExclusive(&wd->mutex[2]);
    AcquireSRWLockExclusive(&wd->mutex[3]);
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {   AcquireSRWLockExclusive(&wd->mutex[receive_count]);
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        ReleaseSRWLockExclusive(&wd->mutex[receive_count^2]);
        receive_count = (receive_count + 1) & 3;
    }
}

#elif defined USE_MICROSOFT_MUTEX

static void workerThread(WorkerData* wd)
{   WaitForSingleObject(wd->mutex[2], MICROSOFT_INFINITE);
    WaitForSingleObject(wd->mutex[3], MICROSOFT_INFINITE);
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {
// This WaitFor could wait for the entire Reduce run any only be signalled
// during close-down, so putting a timeout on it would nor make sense.
        WaitForSingleObject(wd->mutex[receive_count], MICROSOFT_INFINITE);
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        ReleaseMutex(wd->mutex[receive_count^2]);
        receive_count = (receive_count + 1) & 3;
    }
}

#else // Here I use C++ std::mutex

static void workerThread(WorkerData* wd)
{   wd->mutex[2].lock();
    wd->mutex[3].lock();
    wd->ready = true;
    int receive_count = 0;
    for (;;)
    {   wd->mutex[receive_count].lock();
        if (wd->quit_flag) return;
// This is where I do some work! I think it would in general have been
// silly to launch a thread if the sub-multiplication was small enough to
// call for classical multiplication... so I always use Karatsuba here.
        BigMultiplication::kara(wd->a, wd->lena,
                                wd->b, wd->lenb,
                                wd->c,
                                wd->w);
        wd->mutex[receive_count^2].unlock();
        receive_count = (receive_count + 1) & 3;
    }
}

#endif // definition of workerThread

}; // end of BigMultiplication class

inline void workerThread(WorkerData* wd)
{   BigMultiplication::workerThread(wd);
}

inline std::atomic<bool> ManageWorkers::threadsInUse(false);

// Now the external world needs access to the entrypoint "generalMul"
// so I provide a shim that calls it so that others do not need to
// fuss about the class name.

[[gnu::always_inline]]
inline void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{   BigMultiplication::generalMul(a, N, b, M, result);
}

// verySimpleMul is intended to deliver the same results as generalMul
// but using clear (if less efficient code) so it can be use as a
// reference implementation during testing.

inline void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   BigMultiplication::verySimpleMul(a, N, b, M, result);
}

// End of integer multiplication code.
//=========================================================================
