// mrN.c                                                   A C Norman, 2017

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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

#define __STDC_CONSTANT_MACROS 1
#define __STDC_FORMAT_MACROS   1
#define __STDC_LIMIT_MACROS    1
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

#ifndef BITS
#define BITS 32
#endif

#define LIMIT (((uint64_t)1)<<BITS)


#if defined _WIN32 && !defined WIN32
#define WIN32 1
#endif

#ifdef WIN32
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif


// I now try to encapsulate the variations between thread support across
// Windows and the rest of the world... I will set a limit on the total
// number of processes I will support.

#define MAX_CPU_COUNT 32

// The macros here are not very syntactically safe, but I will be using
// them in very stylised manners so I am not too worried.

#ifdef WIN32

// On Windows I can use CRITICAL_SECTIONs rather than real mutexes, and the
// performance difference is quite substantial when contention is reasonably
// low.

static CRITICAL_SECTION critical_section;
// in Windows the initialization of a CriticalSection can never fail
#define CREATEMUTEX_FAILED InitializeCriticalSection(&critical_section), 0
#define LOCKMUTEX          EnterCriticalSection(&critical_section)
#define UNLOCKMUTEX        LeaveCriticalSection(&critical_section)
#define DESTROYMUTEX       DeleteCriticalSection(&critical_section)

static int number_of_processors()
{   SYSTEM_INFO si;
    GetSystemInfo(&si);
    return (int)si.dwNumberOfProcessors;
}

// The function that implements a thread will return a value THREADRESULT
// of type THREADRESULT_T.

#define THREADRESULT_T DWORD __stdcall
#define THREADRESULT   0

static HANDLE thread[MAX_CPU_COUNT];
#define CREATETHREAD_FAILED(i, p) \
    (thread[i] = CreateThread(NULL, 0, &p, NULL, 0, NULL)) == NULL
#define JOINTHREAD_FAILED(i) \
    WaitForSingleObject(thread[i], INFINITE) != WAIT_OBJECT_0 || \
    CloseHandle(thread[i]) == 0

#else // Now for the pthreads version for Linux, Unix, BSD, OS/X etc.

static pthread_mutex_t mutex;
#define CREATEMUTEX_FAILED pthread_mutex_init(&mutex, NULL)
#define LOCKMUTEX          pthread_mutex_lock(&mutex)
#define UNLOCKMUTEX        pthread_mutex_unlock(&mutex)
#define DESTROYMUTEX       pthread_mutex_destroy(&mutex)

#ifdef _SC_NPROCESSORS_ONLN
// _SC_NPROCESSORS_ONLN is not a proper POSIX enquiry to send to sysconf,
// but it is available on Linux, cygwin and OS/X and so is worth using here,
// perhaps especially since an #ifdef can easily check for it. I use ONLN
// not CONF because some processors may have many cores but leave some of
// then disabled - I see reports that in particular big/little ARM chips
// do this. Note that for hyperthreaded CPUs this returns the number of
// threads I can run in parallel, not the number of raw cores. I also ignore
// issues of load and permit my code to use all available resources.

static int number_of_processors()
{   return sysconf(_SC_NPROCESSORS_ONLN);
}

#else // sysconf option to check CPU count

static int number_of_processors()
{   printf("_SC_NPROCESSORS_CONF not defined\n");
    return 1;
}

#endif // sysconf option to check CPU count

#define THREADRESULT_T void *
#define THREADRESULT   NULL

static pthread_t thread[MAX_CPU_COUNT];
#define CREATETHREAD_FAILED(i, p) pthread_create(&thread[i], NULL, &p, NULL)
#define JOINTHREAD_FAILED(i)     pthread_join(thread[i], NULL)

#endif // Windows vs pthreads.

static inline uint64_t gcd(uint64_t a, uint64_t b)
{   while (b != 0)
    {   uint64_t c = a % b;
        a = b;
        b = c;
    }
    return a;
}

static inline uint64_t exptmod(uint64_t x, uint64_t n, uint64_t p)
{
    uint64_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = (x * y) % p;
        x = (x * x) % p;
        n = n / 2;
    }
    return (x * y) % p;
}

static inline int miller_rabin(uint64_t a, uint64_t n)
{
    if (n == 1) return 0;
    else if (n <= 3) return 1;
    else if ((n % 2) == 0) return 0;
    uint64_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)
    {   d = d/2;
        ++s;
    }
    uint64_t x = exptmod(a, d, n);
    if (x == 1 || x == n-1) return 1;
    while (s > 1)
    {   x = (x * x) % n;
        if (x == 1) return 0;
        else if (x == n-1) return 1;
        --s;
    }
    return 0;
}

static int cpu_count;
static char *primes;

static int threadnumber = 0;

static clock_t c0;

#define MAXPSEUDO 200000
static __thread uint64_t pseudo[MAXPSEUDO];
static __thread int npseudo;

THREADRESULT_T threadcode(void *arg)
{
    LOCKMUTEX;
    int myself = threadnumber++;
    UNLOCKMUTEX;
// First report on progress will be after about 10 minutes
    time_t baset = time(NULL) + 600;
    for (uint64_t b1 = myself; b1<LIMIT; b1+=cpu_count)
    {   npseudo = 0;
// I am going to collect all the pseudo-primes when I use a witness of b1.
// Some values could not count as valid witnesses!
        if (b1 == 0 || b1 == 1 || b1 == LIMIT-1) continue;
        for (uint64_t n=3; n<LIMIT; n += 2)
        {   if (primes[(n-1)/2])
            {   if (gcd(n, b1) != 1) continue;
                if (!miller_rabin(b1, n))
                {   printf("test using %" PRIu64 " failed on %" PRIu64 "\n", b1, n);
                    exit(1);
                }
                continue; // truly a prime!
            }
// I will filter out multiples of 2, 3, 5 and 7 first because that is cheap
// and it reduces the number of cases I have to deal with somewhat.
            if (n%3 == 0 || n%5 == 0 || n%7 == 0) continue;
            time_t now = time(NULL);
// I will display a message that reminds me that progress is being made
// every so often - roughly every 2 hours.
            if (myself == 0 && now > baset)
            {   baset = now + 7200;
                printf("Time is:  %.19s  Checking %" PRIu64 " (%" PRIx64 ")\n",
                    ctime(&now), b1, b1);
                fflush(stdout);
            }
            if (!miller_rabin(b1, n)) continue;
            if (npseudo >= MAXPSEUDO)
            {   printf("Too many pseudo-primes using base %" PRIu64 "\n", b1);
                exit(1);
            }
            else pseudo[npseudo++] = n;
        }
        LOCKMUTEX;
        printf("Pseudoprimes using witness %" PRIu64 " (%" PRIx64 ")"
               "  count=%d", b1, b1, (int)npseudo);
        for (int i=0; i<npseudo; i++)
        {   if (i % 8 == 0) printf("\n");
            printf("%.8x ", (unsigned int)pseudo[i]);
        }
        printf("\n");
        UNLOCKMUTEX;
    }
    return THREADRESULT;
}

int main(int argc, char *argv[])
{
    printf("%s starting\n", argv[0]);
    fflush(stdout);
    c0 = clock();
    primes = (char *)malloc(LIMIT/2);
    if (primes == NULL)
    {   printf("Unable to allocate space\n");
        exit(1);
    }
// Sieve method
    for (uint64_t i=0; i<LIMIT/2; i++) primes[i] = 1; // provisionally prime
    primes[0] = 0;
    {   uint64_t p = 1;
        while (p*p < LIMIT)
        {   while (primes[p/2] == 0) p+=2; // find next prime
            uint64_t np = (3*p-1)/2;
            while (np < LIMIT/2)
            {   primes[np] = 0;
                np += p;
            }
            p += 2;
        }
    }
    printf("primes table set up... (%.2f secs)\n",
           (clock()-c0)/(double)CLOCKS_PER_SEC);
    fflush(stdout);
    c0 = clock();

    cpu_count = number_of_processors();
    printf("I seem to have %d processors\n", cpu_count);
    fflush(stdout);
    if (cpu_count > MAX_CPU_COUNT) cpu_count = MAX_CPU_COUNT;
    if (cpu_count > 3) --cpu_count; // leave a CPU free for other tasks!

    if (CREATEMUTEX_FAILED)
    {   fprintf(stderr, "Unable to create mutex\n");
        exit(1);
    }
    for (int k=0; k<cpu_count; k++)
        if (CREATETHREAD_FAILED(k, threadcode))
        {   printf("Failed to create at %d\n", k);
            exit(1);
        }
    for (int k=0; k<cpu_count; k++)
        if (JOINTHREAD_FAILED(k))
        {   printf("Failed to join at %d\n", k);
            exit(1);
        }

    DESTROYMUTEX;
    return 0;
}

// end of file.
