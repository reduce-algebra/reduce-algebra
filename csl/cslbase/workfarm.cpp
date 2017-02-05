// workfarm.cpp                         Copyright (C) A C Norman, 2015-2017

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

// This is sample code to create threads and run a bunch of calculations
// in each...


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>

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

// Now for the application-level code

static int counter, result1, result2;

int get_next_instance()
{   int n;
    LOCKMUTEX;
    n = counter++;
    UNLOCKMUTEX;
    if (n > 10000000) return -1;
    else return n;
}

void set_result_if_better(int n, int r)
{   LOCKMUTEX;
    if (r > result2)
    {   printf("New record of %d : %d found\n", n, r);
        fflush(stdout);
        result1 = n;
        result2 = r;
    }
    UNLOCKMUTEX;
}

// Although for the calculation I do here there is no real need for it,
// I will use thread-local storage for some of the state held in each
// thread, just so I can show how that is done.

static __thread int my_n, my_result;

// This code retrieves a seed amd sorts out how many steps the "3n+1"
// iteration takes to reach the value 1.

THREADRESULT_T threadwork(void *arg)
{   while ((my_n = get_next_instance()) > 0)
    {   int starting_n = my_n;
        my_result = 0;
        while (my_n > 1)
        {   if ((my_n % 2) == 0) my_n /= 2;
            else if (my_n >= 0x7fffffff/3-1) // trap overflow case
            {   my_result = 0x7fffffff;      // pretend it was a huge loop
                my_n = 1;                    // force early exit
            }
            else my_n = 3*my_n + 1;
            my_result++;
        }
        set_result_if_better(starting_n, my_result);
    }
    return THREADRESULT;
}

THREADRESULT_T threadnowork(void *arg)
{   char *w = (char *)malloc(10000);
    if (w == NULL)
    {   printf("Disaster\n");
        exit(1);
    }
    free(w);
    return THREADRESULT;
}


int main(int argc, char *argv[])
{   int i;
    int cpu_count = number_of_processors();
    printf("I seem to have %d processors\n", cpu_count);
    if (cpu_count > MAX_CPU_COUNT) cpu_count = MAX_CPU_COUNT;

    for (i=0; i<1000000; i++)
    {   if (i % 100000 == 0) printf("i = %d\n", i), fflush(stdout);
        if (CREATETHREAD_FAILED(1, threadnowork))
        {   printf("Failed to create at %d\n", i);
            exit(1);
        }
        if (JOINTHREAD_FAILED(1))
        {   printf("Failed to join at %d\n", i);
            exit(1);
        }
    }

    counter = 1;
    result1 = result2 = 0;
    if (CREATEMUTEX_FAILED)
    {   fprintf(stderr, "Unable to create mutex\n");
        exit(1);
    }
    for (i=0; i<cpu_count-1; i++)
    {   if (CREATETHREAD_FAILED(i, threadwork))
        {   fprintf(stderr, "Unable to create thread\n");
            exit(1);
        }
    }
    threadwork(NULL);   // do some work even in the main thread
    for (i=0; i<cpu_count-1; i++)
    {   if (JOINTHREAD_FAILED(i))
        {   fprintf(stderr, "Unable to join thread\n");
            exit(1);
        }
    }
    DESTROYMUTEX;
    printf("finished: final result is %d : %d\n", result1, result2);
    return 0;
}

// end of workfarm.cpp
