// cuckoo.c                                        A C Norman, October 2015

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

// The code here is for the offline creation of a hash table that will
// follow in the spirit of cuckoo hashing using 1, 2 or 3 probes (but
// never more) to retrieve information. It tries a potentially large
// number of hash functions and picks one that optimises table occupancy.
// I use this for building a hash table that holds metrics for characters,
// and (to my amazement) acheive around 99% table occupancy with a worst
// case access cost of 3 probes.
//
// A central part of the process of setting up the hash table involves
// finding matchings in bipartite graphs. The Hopcroft-Karp algorithm is
// used for this.
//
// This version uses threads to do some of its searching in parallel, and
// should work on Linux, Windows and OS/X, checking for the number of
// CPUs and using them all.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif


// I now try to encapsulate the variations between thread support across
// Windows and the rest of the world...
// The macros here are not very syntactically safe, but I will be using
// them in very stylised manners so I am not too worried.

#ifdef WIN32

// On Windows I can use CRITICAL_SECTIONs rather than real mutexes, and the
// performance difference is quite substantial when contention is reasonably
// low. The key issue is that a CRITICAL_SECTION does its initial checks in
// user-mode and only upgrades to kernel mode in the complicated cases. A
// side effect of this is that all use of one of these locks must occur
// within a single process, while more general mutexes support use even
// when multiple processes are present.

static CRITICAL_SECTION critical_section, logmutex;
// in Windows the initialization of a CriticalSection can never fail
#define CREATEMUTEX_FAILED InitializeCriticalSection(&critical_section), 0
#define LOCKMUTEX          EnterCriticalSection(&critical_section)
#define UNLOCKMUTEX        LeaveCriticalSection(&critical_section)
#define DESTROYMUTEX       DeleteCriticalSection(&critical_section)

#define CREATELOGMUTEX        InitializeCriticalSection(&logmutex)
#define LOCKLOGMUTEX          EnterCriticalSection(&logmutex)
#define UNLOCKLOGMUTEX        LeaveCriticalSection(&logmutex)


static int number_of_processors()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return (int)si.dwNumberOfProcessors;
}

// In very old versions of Windows one needed to use _beingthreadx rather
// than CreateThread here, but that is no longer the case (as best I can
// discern!).

// The function that implements a thread will return a value THREAD_RESULT
// of type THREAD_RESULT_T.

#define THREAD_RESULT_T DWORD __stdcall 
#define THREAD_RESULT   0

// I will have a limit on the maximum number of threads I will ever
// create - and at present I am not expecting to find that I have
// a shared-memory cpu with more than 32 CPUs.

#define MAX_CPU_COUNT 32
static HANDLE thread[MAX_CPU_COUNT];

#define CREATETHREAD_FAILED(i, p) \
    (thread[i] = CreateThread(NULL, 0, &p, NULL, 0, NULL)) == NULL
#define SLEEP Sleep(5000)
#define JOINTHREAD_FAILED(i) \
    WaitForSingleObject(thread[i], INFINITE) != WAIT_OBJECT_0 || \
    CloseHandle(thread[i]) != 0

#else // Now for the pthreads version for Linux, Unix, BSD, OS/X etc.

static pthread_mutex_t mutex, logmutex;
#define CREATEMUTEX_FAILED pthread_mutex_init(&mutex, NULL)
#define LOCKMUTEX          pthread_mutex_lock(&mutex)
#define UNLOCKMUTEX        pthread_mutex_unlock(&mutex)
#define DESTROYMUTEX       pthread_mutex_destroy(&mutex)

#define CREATELOGMUTEX     pthread_mutex_init(&logmutex, NULL)
#define LOCKLOGMUTEX       pthread_mutex_lock(&logmutex)
#define UNLOCKLOGMUTEX     pthread_mutex_unlock(&logmutex)

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
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}

#else // sysconf option to check CPU count

static int number_of_processors()
{
    printf("_SC_NPROCESSORS_CONF not defined\n");
    return 1;
}

#endif // sysconf option to check CPU count

#define THREAD_RESULT_T void *
#define THREAD_RESULT   NULL

#define MAX_CPU_COUNT 32
static pthread_t thread[MAX_CPU_COUNT];

#define CREATETHREAD_FAILED(i, p) pthread_create(&thread[i], NULL, &p, NULL)
#define SLEEP sleep(5)
#define JOINTHREAD_FAILED(i)      pthread_join(thread[i], NULL)

#endif // Windows vs pthreads.


// logging in a way that is thread-safe

static int logmutex_created = 0;

void logprintf(const char *s, ...)
{
    va_list a;
// I will never destroy the mutex used here - I will let it get cancelled
// when the program terminates.
    if (!logmutex_created) CREATELOGMUTEX;
    va_start(a, s);
    LOCKLOGMUTEX;
    vfprintf(stdout, s, a);
    va_end(a);
    fflush(stdout);
    UNLOCKLOGMUTEX;
}


// See workfarm.c for a small program illustrating use of threads to attack
// a problem exploiting concurrency.

#include "cuckoo.h"

// Because the table was passed as a "void *" and we do not have
// a single type that maps the entries it is not feasible to use direct
// array access (as in "table[n]") to retrieve and update items in it.
// So here I have two macros that use the explicitly passed item size
// and accress arithmetic to create a pointer to the nth item in the
// table, and then the user-supplied functions to deal with just the
// part of the thing there that represents the key. These are macros
// not functions because they use a number of values not explicitly passed
// to them as arguments.

// The following definitions are in the header file, but are repeated here
// as comment for (what I hope is) clarity.

//- #define cuckoo_item(n) \
//-     ((char *)table + hash_item_size*(n))
//-
//- #define cuckoo_key(n) \
//-     ((*get_key)(cuckoo_item(n)))
//-
//- #define cuckoo_set_key(n, v) \
//-     ((*set_key)(cuckoo_item(n), v))
//-
//- uint32_t cuckoo_lookup(
//-     uint32_t key,             // integer key to look up
//-     void *table,              // base of the hash table
//-     size_t hash_item_size,    // size of each item in the table,
//-                               // must be <= MAX_CUCKOO_ITEM_SIZE
//-     uint32_t table_size,      // number of entries in the hash table
//-     cuckoo_get_key *get_key,  // function to retrieve keys from table
//-     uint32_t modulus2,        // used to give a secondary hash function
//-     uint32_t offset2)         // used to give a secondary hash function
//- {
//- // My initial hash value is merely the key reduced modulo the size of
//- // the table.
//-     uint32_t hash1 = key % table_size;
//-     uint32_t hash2;
//-     if (cuckoo_key(hash1) == key) return hash1;
//- // I have a secondary hash function that will not map onto the whole
//- // of the table - it uses a second smaller modulus and an offset. The
//- // sum of these must not exceed the table size (so as to avoid running
//- // over the end) but should probably be an appreciable fraction of it.
//-     hash2 = (key % modulus2) + offset2;
//-     if (cuckoo_key(hash2) == key) return hash2;
//- // The third and final place I look is found by adding the two previous
//- // hash values (and reducing modulo the table size). If the modulus operation
//- // was expensive but conditional branches were cheap then
//- //       if ((hash1 += hash2) >= table_size) hash1 -= table_size;
//- // could be used here.
//-     hash1 = (hash1 + hash2) % table_size;
//-     if (cuckoo_key(hash1) == key) return hash1;
//- // If the key is not found in any of those three locations I just return -1.
//-     return (uint32_t)(-1);
//- }

// I am expecting that insertion in these tables will not be done at
// all often, so having a somewhat clumsy-looking interface here does
// not worry me too much, and I will even accept code that is not
// terribly neat!


// I use the Hopcroft-Karp maximum matching algorithm to determine if there
// is any way of using a particular size of hash table. Once I know how large
// a hash table to use I can use the Hungarian algorithm to find an assignment
// to favours placing keys in positions that minimise the average number
// of probes that lookup will need.

// The Hopcroft-Karp code I use is imported, but had been been placed under
// very flexible license terms. See the top of the source code for details.

#include "hopkar.c"

// Now an adapter that takes my hashing problem and maps it onto the
// an instance of a matching problem. The input is a set of keys, a table
// size and two parameters that control details of the hashing. It then has
// the hash table it is tryng to create, which it fills in if it can find
// a perfect way to do so. Here the table is whatevver final native-shape
// hash table will be required, and the procedures get_key and set_key
// access the keys in it.

// This tries to insert all the keys in "items" into the hash-table "table"
// and it returns 0 if it fails. Because it is just finding a matching (ANY
// matching) it will be useful for discovering what the smallest possible
// table size is. But it will not take any steps at all to pick a matching
// that prefers first choice placements for keys over the other two
// possibilities. For that see the Hungarian algorith below which will be
// able to perform further optimisation but which is expected to be slower.

int find_any_assignment(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    void *table,
    int hash_item_size,
    int table_size,
    cuckoo_get_key *get_key,
    cuckoo_set_key *set_key,
    uint32_t modulus2,
    uint32_t offset2)
{   int i;
    init(item_count, table_size);
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    default:
            addEdge(i, (int)h3);
            // drop through
    case CUCKOO_IMPORTANT:
            addEdge(i, (int)h2);
            // drop through
    case CUCKOO_VITAL:
            addEdge(i, (int)h1);
            break;
        }
    }
logprintf("in find_any_matching\n");
    i = maxMatching();
logprintf("maxMatching returns %d/%d, need = %d\n", i, table_size, item_count);
    if (i != item_count) return 0;
    return 1;
}

// Once a table has been set up this function checks that each key is properly
// present and it computes a figure of merit for it... This code may in
// fact not be used!

double cuckoo_merit(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    void *table,
    int hash_item_size,
    int table_size,
    cuckoo_get_key *get_key,
    uint32_t modulus2,
    uint32_t offset2)
{
    int i;
    int nvital = 0;
    int nimportant = 0, nimp1 = 0, nimp2 = 0;
    int nstandard = 0, nstand1 = 0, nstand2 = 0, nstand3 = 0;
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    default:
            nstandard++;
            if (key == (*get_key)(h1*hash_item_size+(char *)table))
            {   nstand1++;
                break;
            }
            else if (key == (*get_key)(h2*hash_item_size+(char *)table))
            {   nstand2++;
                break;
            }
            else if (key == (*get_key)(h3*hash_item_size+(char *)table))
            {   nstand3++;
                break;
            }
            else
            {   printf("Failed to find item %d (%u/%x)\n", i, key, key);
                exit(1);
            }
    case CUCKOO_IMPORTANT:
            nimportant++;
            if (key == (*get_key)(h1*hash_item_size+(char *)table))
            {   nimp1++;
                break;
            }
            else if (key == (*get_key)(h2*hash_item_size+(char *)table))
            {   nimp2++;
                break;
            }
            else
            {   printf("Failed to find item %d (%u/%x)\n", i, key, key);
                exit(1);
            }
    case CUCKOO_VITAL:
            nvital++;
            if (key == (*get_key)(h1*hash_item_size+(char *)table))
                break;
            else
            {   printf("Failed to find item %d (%u/%x)\n", i, key, key);
                exit(1);
            }
        }
    }
// The "figure of merit" is a weighted average that scores each VITAL key
// as worth 10, each IMPORTANT ones as 4 and the rest as worth 1 each. Smaller
// values are better.
    return (10.0*nvital +
            4.0*(nimp1 + 2.0*nimp2) +
            (nstand1 + 2.0*nstand2 + 3.0*nstand3)) /
           (10.0*nvital + 4.0*nimportant + nstandard);
}

// As well as being able to find assignments I need to be able to find the
// BEST assignments, and the following imported code that implements the
// Hungarian algorith sorts that out. It uses a quite different interface
// from the Hopcroft-Karp code - which is reasonable since its source was
// different. I then need to write code to link it to the problems that I
// wish to solve.

// The code I have imported deals with general matchings and represents the
// bipartite graph as a full matrix. In my case the graph that I wish to
// process is spares - it has at most three edges for each vertex in the
// set A. I MAY at some stage rework the code to use ajcacency lists to
// represent the sparse array. If I do so it will certainly save a lot of
// space and may speed things up too. But that is for the future!

#include "hungarian.h"
#include "hungarian.c"

// Now an adapter that takes my hashing problem and maps it onto the
// calls to the hungarian problem solver. The input is a set of keys,
// a table size and two parameters that control details of the hashing.
// It then has the hash table it is trying to create, which it fills in
// if it can find a perfect way to do so. For the code here the hash table
// is merely an array of uint32_t values.
//
// The target merit passed here only has an effect on printing. If an
// assigment is found that beats it a trace message is displayed.

// This tries to insert all the keys in "items" into the hash-table "table"
// and it returns a positive "merit" value on success, or -1.0 on failure
//

static __thread int **adjacency_matrix = NULL;

double find_best_assignment(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    uint32_t *table,
    int table_size,
    uint32_t modulus2,
    uint32_t offset2)
{
    int i, j;
    hungarian_problem_t p;
logprintf("starting find_best_assignment %d %d\n", item_count, table_size);
logprintf("m2=%d o2=%d\n", modulus2, offset2);
    adjacency_matrix = (int **)calloc(table_size, sizeof(int *));
    hungarian_test_alloc(adjacency_matrix);
    for (i=0; i<table_size; i++)
    {   adjacency_matrix[i] = (int *)calloc(item_count, sizeof(int));
        hungarian_test_alloc(adjacency_matrix[i]);
// I put in a value that is not "infinite" but is such that any assignment
// that uses an edge of this length will be pretty bad.
        for (j=0; j<item_count; j++)
          adjacency_matrix[i][j] = 0x00010000;
    }
logprintf("about to put in weights %p\n", items);
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
logprintf("Ok at %d\n", i);
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
logprintf("hashes are %d %d %d\n", h1, h2, h3);
        int imp = (*importance)(key);
// I have thought a bit about the weights I use here, but to a large extent
// they are a bit of an arbitrary choice.
        switch (imp)
        {
    default:
            adjacency_matrix[h1][i] = 0;
            adjacency_matrix[h2][i] = 1;
            adjacency_matrix[h3][i] = 2;
            break;
    case CUCKOO_IMPORTANT:
            adjacency_matrix[h1][i] = 0;
            adjacency_matrix[h2][i] = 10;
            break;
    case CUCKOO_VITAL:
            adjacency_matrix[h1][i] = 0;
            break;
        }
    }
logprintf("call hungarian_init\n");
    hungarian_init(&p,
                   adjacency_matrix,
                   table_size,
                   item_count,
                   HUNGARIAN_MODE_MINIMIZE_COST);
logprintf("call hungarian_solve\n");
    hungarian_solve(&p);
logprintf("hungarian_solve returned\n");
// Next I will extract the assignment found and put it in my hash table.
// While I am about it I will collect some statistics.
    int nvital = 0;
    int nimportant = 0, nimportant1 = 0, nimportant2 = 0;
    int nstandard = 0, nstandard1 = 0, nstandard2 = 0, nstandard3 = 0;
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    case CUCKOO_VITAL:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nvital++;
                break;
            }
            else
            {   hungarian_free(&p);
                for (i=0; i<table_size; i++)
                    free(adjacency_matrix[i]);
                free(adjacency_matrix);
                return -1.0;
            }
    case CUCKOO_IMPORTANT:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nimportant++;
                nimportant1++;
                break;
            }
            else if (p.assignment[h2][i])
            {   table[h2] = key;
                nimportant++;
                nimportant2++;
                break;
            }
            else
            {   hungarian_free(&p);
                for (i=0; i<table_size; i++)
                    free(adjacency_matrix[i]);
                free(adjacency_matrix);
                return -1.0;
            }
    case CUCKOO_STANDARD:
            if (p.assignment[h1][i])
            {   table[h1] = key;
                nstandard++;
                nstandard1++;
                break;
            }
            else if (p.assignment[h2][i])
            {   table[h2] = key;
                nstandard++;
                nstandard2++;
                break;
            }
            else if (p.assignment[h3][i])
            {   table[h3] = key;
                nstandard++;
                nstandard3++;
                break;
            }
            else
            {   hungarian_free(&p);
                for (i=0; i<table_size; i++)
                    free(adjacency_matrix[i]);
                free(adjacency_matrix);
                return -1.0;
            }
        }
    }
logprintf("transferred to hash table\n");
    double merit = (10.0*nvital +
            4.0*(nimportant1 + 2.0*nimportant2) +
            (nstandard1 + 2.0*nstandard2 + 3.0*nstandard3)) /
           (10.0*nvital + 4.0*nimportant + nstandard);
#define VERBOSE
#ifdef VERBOSE
    double avimportant = 
       (nimportant1+2.0*nimportant2)/nimportant;
    double avstandard =
       (nstandard1+2.0*nstandard2+3.0*nstandard3)/nstandard;
// But I will also compute an average that shows the expected number of
// probes if all keys are accessed with equal probability.
    double average =
       (nvital + nimportant1 + 2.0*nimportant2 +
        nstandard1 + 2.0*nstandard2 + 3.0*nstandard3) / item_count;
    {   logprintf("\ntable_size = %u modulus2 = %u offset2 = %u occupancy %.2f\n",
               table_size, modulus2, offset2,
               (100.0*item_count)/table_size);
        if (nvital != 0)
            logprintf("VITAL:     %u      1.0 average probes\n", nvital);
        if (nimportant1!=0 || nimportant2 != 0)
            logprintf("IMPORTANT: %u %u   %.3f average probes\n",
                nimportant1, nimportant2, avimportant);
        if (nstandard1!=0 || nstandard2 != 0)
            logprintf("STANDARD:  %u %u %u  %.3f average probes\n",
                nstandard1, nstandard2, nstandard3, avstandard);
        logprintf("Figure of merit = %.3f flat average = %.3f\n", merit, average);
    }
#endif
    hungarian_free(&p);
    for (i=0; i<table_size; i++)
        free(adjacency_matrix[i]);
    free(adjacency_matrix);
    return merit;
}

uint32_t int32_get_key(void *p)
{
    return *(uint32_t *)p;
}

void int32_set_key(void *p, uint32_t v)
{
    *(uint32_t *)p = v;
}

// To perform a parallel search I need to be able to distribute cases
// that need analysis to the various threads. A test case is a pair
// of a value for modulus2 and one for offset2.

typedef struct __mod_and_off
{
    uint32_t modulus2;
    uint32_t offset2;
} mod_and_off;


// I have some data that is common to all the threads....

static int       shared_use_hungarian;
static uint32_t *shared_keys;
static int       shared_key_count;
static uint32_t *shared_table;
static int       shared_table_size;
static cuckoo_importance *shared_importance;
static uint32_t  shared_modulus2;
static uint32_t  shared_offset2;
static uint32_t  best_modulus2;
static uint32_t  best_offset2;
static double    best_merit;
static int       tries;
static int       successes;

// This should return the next mod_and_off, or one with values (0,0)
// when there are no more left.
 
mod_and_off hungarian_next_case()
{
    mod_and_off r;
    LOCKMUTEX;
    tries++;
    r.modulus2 = shared_modulus2;
    r.offset2 = shared_offset2;
    if (shared_modulus2 != (uint32_t)(-1))
    {   if (shared_modulus2 != 0 &&
            shared_modulus2 + shared_offset2 < shared_table_size)
            shared_offset2++;
        else
        {   shared_modulus2++;
            shared_offset2 = 0;
            if (shared_modulus2 >= shared_table_size) shared_modulus2 = 0;
        }
    }
    UNLOCKMUTEX;
    return r;
}

// Here is a function that implements what a thread should do. I have just one
// variable called thread_finished and if a thread is ending it will set it
// to 1. I will not worry about locks since this only needs to notice if at
// least one thread is done.
//
// If shared_use_hungarian is true this considers ALL the possible values for
// modulus2 and offset2 and constructs a proper hash-table allocation for the
// configuration that delivers the best figure of merit. Otherwise it merely
// seeks a valid assigment and arranges that all threads stop once one of
// them has found one. It does not return a figure of merit and does not
// fill in a detailed hash assignment (even though it could).

static int thread_finished;

THREAD_RESULT_T hungarian_thread(void *arg)
{
    mod_and_off mo;
    uint32_t *table = (uint32_t *)calloc(shared_table_size, sizeof(uint32_t));
    logprintf("Thread starting\n");
    while ((mo = hungarian_next_case()).modulus2 != 0)
    {   double merit;
        logprintf("Thread considering %d:%d\n", mo.modulus2, mo.offset2);
// Before I try the (possibly expensive) Hungarian method I will filter
// by using Hopcroft-Karp so that I at least know that there is some feasible
// allocation.
        if (find_any_assignment(
            shared_keys,
            shared_key_count,
            shared_importance,
            table,
            sizeof(uint32_t),
            shared_table_size,
            int32_get_key,
            int32_set_key,
            mo.modulus2,
            mo.offset2))
        {   logprintf("Found assignment for %d : %d\n", mo.modulus2, mo.offset2);
            logprintf("shared_use_hungarian = %d\n", shared_use_hungarian);
            if (!shared_use_hungarian)
            {   logprintf("Report back to owner and set quit flag\n");
                LOCKMUTEX;
                successes++;
                best_modulus2 = mo.modulus2;
                best_offset2 = mo.offset2;
                best_merit = 0.0;
// Arrange that the next use of hungarian_next_case reports no more cases
// need investigation, and so all other threads will soon terminate too.
                shared_modulus2 = 0;
                shared_offset2 = 0;
                UNLOCKMUTEX;
                break;
            }
            else if ((merit = find_best_assignment(
                shared_keys,
                shared_key_count,
                shared_importance,
                table,
                shared_table_size,
                mo.modulus2,
                mo.offset2)) >= 0.0)
            {   LOCKMUTEX;
                successes++;
                logprintf("successes=%d: M=%d O=%d => %.4f%%\n", successes,
                        mo.modulus2, mo.offset2, merit);
                if (merit < best_merit)
                {   int i;
                    logprintf("+++ New best\n");
                    best_modulus2 = mo.modulus2;
                    best_offset2 = mo.offset2;
                    best_merit = merit;
// Each time I get a new best assignment I transcribe it into the main
// official hash-table.
                    for (i=0; i<shared_table_size; i++)
                        shared_table[i] = table[i];
                }
                UNLOCKMUTEX;
            }
        }
    }
    free(table);
    logprintf("Thread finishing\n");
    thread_finished = 1;
    return THREAD_RESULT;
}

// This routine is used to analyse tables of some specified size. If its
// last argument is false it merely checks if an assignment to a table
// of that size is possible, and returns if it manages to find one. If
// on the other hand the final argument is true then it will run the
// Hungarian algorithm on ALL possible hash functions at that size and
// return information about the one that gives the best packing. It
// does all this using multiple threads so that the often-expensive
// search takes less real time than might otherwise have been the case
// when you have a multi-core computer.
//

cuckoo_parameters try_all_hash_functions(
    uint32_t *keys,
    int key_count,
    cuckoo_importance *importance,
    void *hash,
    int hash_item_size,
    int hashsize,
    cuckoo_set_key *set_key,
    int use_hungarian)
{
    int cpu_count, i;
    cuckoo_parameters r;
    uint32_t *table = (uint32_t *)calloc(hashsize, sizeof(uint32_t));
    hungarian_test_alloc(table);
    shared_use_hungarian = use_hungarian;
    shared_keys = keys;
    shared_key_count = key_count;
    shared_importance = importance;
    shared_table = table;
    shared_table_size = hashsize;
    shared_modulus2 = 1;
    shared_offset2 = 0;
    best_modulus2 = 0;
    best_offset2 = 0;
    best_merit = 4.0;
    tries = successes = 0;

    logprintf("try_all with table size %d and use_h=%d\n", hashsize, use_hungarian);

    cpu_count = number_of_processors();
cpu_count = 1; // to run sequentially!
    logprintf("I seem to have %d processors\n", cpu_count);
    if (cpu_count > MAX_CPU_COUNT) cpu_count = MAX_CPU_COUNT;
    if (CREATEMUTEX_FAILED)
    {   fprintf(stderr, "Unable to create mutex\n");
        exit(1);
    }
    thread_finished = 0;
    for (i=0; i<cpu_count; i++)
    {   if (CREATETHREAD_FAILED(i, hungarian_thread))
        {   fprintf(stderr, "Unable to create thread\n");
            exit(1);
        }
    }
    logprintf("All threads created\n");
// I will do a wait loop here that arranges that once every 5 seconds
// it checks whether at least one thread has finished and displays a
// message that tries to give some idea of how far it has got through the
// search. My ESTIMATE is that for a full search the code may run for
// around 9 hours on an 8-core machine and so there would be of the order
// of 6000 lines of trace output - rather a lot but not enough to be
// a complete embarassment. Perhaps.
    while (!thread_finished)
    {   SLEEP;
        LOCKMUTEX;
        logprintf("%d:%d => %.4f now at %d:%d\n",
            best_modulus2, best_offset2, best_merit,
            shared_modulus2, shared_offset2);
        UNLOCKMUTEX;
    }
    logprintf("At least one thread complete\n");
    for (i=0; i<cpu_count-1; i++)
    {   if (JOINTHREAD_FAILED(i))
        {   fprintf(stderr, "Unable to join thread\n");
            exit(1);
        }
    }
    logprintf("All threads now finished\n");
    DESTROYMUTEX;
    logprintf("finished: final result is %d : %d   %.4f\n",
        best_modulus2, best_offset2, best_merit);
    if (successes == 0) // Failure!
    {   r.table_size = (uint32_t)(-1);
        r.modulus2 = r.offset2 = 4;
        r.merit = 4.0;
        free(table);
        return r;
    }
    logprintf("%d assignments for %d tries (%.3f%%)\n",
        successes, tries, (100.0*successes)/tries);
    r.table_size = hashsize;
    r.modulus2 = best_modulus2;
    r.offset2 = best_offset2;
    r.merit = best_merit;
    if (use_hungarian)
        for (i=0; i<r.table_size; i++)
            (*set_key)(hash_item_size*i+(char *)hash, shared_table[i]);
    free(table);
    return r;
}



// This tries all table sized starting from initial_table_size up to
// max_table_size and returns information about the first one for which
// a valid assignment is possible. I provide this because the subsequent
// faster version that uses binary search is based on an expectation that
// there will be assignments usable for every hash table size larger than
// the smallest one where there is any assignment at all. That is plausible
// but not guaranteed! Having a larger hash table should reduce pressure
// and increase flexibility so in general it ought never to make life harder,
// but it is imaginable that the very smallest usable hash table has an
// assignment that is basically an accident...
//
static cuckoo_parameters cuckoo_simple_search(
    int myid,
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    void *table,
    int hash_item_size,
    int initial_table_size,
    int max_table_size,
    cuckoo_get_key *get_key,
    cuckoo_set_key *set_key)
{
    cuckoo_parameters r = {(uint32_t)(-1), 0, 0, 4.0};
    int i, probe_count;
    uint32_t table_size, modulus2, offset2;
    for (table_size = initial_table_size; table_size<max_table_size; table_size++)
    {   logprintf("Trial with table_size = %d\n", table_size);
        r = try_all_hash_functions(
            items,
            item_count,
            importance,
            table,
            hash_item_size,
            table_size,
            set_key,
            0);        // Merely check if there is an allocation
        if (r.table_size != (uint32_t)(-1))
        {   logprintf("Success for %d items and table_size %d (%.2f%%)\n",
                item_count, r.table_size, (100.0*item_count)/table_size);
            logprintf("modulus2 = %d, offset2 = %d\n", r.modulus2, r.offset2);
            break;
        }
    }
    return r;
}

// This seeks a (near) optimal hash table using binary search to sort out the
// size. Note again that this does not guarantee to find the best solution
// because the mapping table_size -> number of assignments is not guaranteed
// to be monotonic. However if you do not know what size is going to be best
// this can be MUCH faster than a simple linear search, and it is really
// improbable that it will get a very wrong answer!

// Note that the search will be from [min..max), ie the minimum size quoted
// will be tested by the largest acceptable size will be one lower than the
// one given. This is so that the max can be passed as the size of the
// hash table (and is because of zero-based array addresses).
//
// It will report failure if either the minimum specified table size has
// a succesfull allocation or the maximum one does not.


cuckoo_parameters cuckoo_binary_optimise(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    void *table,
    int hash_item_size,
    int min_table_size,
    int max_table_size,
    cuckoo_get_key *get_key,
    cuckoo_set_key *set_key,
    double merit_target)
{
    cuckoo_parameters r, rhi;
    if (min_table_size >= max_table_size)
    {   r.table_size = (uint32_t)(-1);
        r.modulus2 = r.offset2 = 3;
        r.merit = 3.0;
        return r;
    }
// First verify that the low limit does not lead to success. Doing this
// is pretty cautious! I am going to ASSUME that the table of keys to be
// inserted has no duplicates, and hence if there is more data than could
// fit into the table there is no chance of success.
    if (min_table_size >= item_count)
    {   r = try_all_hash_functions(
            items,
            item_count,
            importance,
            table,
            hash_item_size,
            min_table_size,
            set_key,
            0);        // Merely check if there is an allocation
        if (r.table_size != (uint32_t)(-1))
        {   r.table_size = (uint32_t)(-1);
            logprintf("Minimum size passed to binary search is too large\n");
            r.modulus2 = r.offset2 = 0;
            r.merit = 4.0;
            return r;
        }
    }
    else logprintf("Low limit on table size smaller than item count\n");
// Next confirm that the high limit does lead to success.
    rhi = try_all_hash_functions(
        items,
        item_count,
        importance,
        table,
        hash_item_size,
        max_table_size-1,
        set_key,
        0);        // Merely check if there is an allocation
logprintf("rhi: %d %d %d\n", rhi.table_size, rhi.modulus2, rhi.offset2);
    if (rhi.table_size == (uint32_t)(-1))
    {   logprintf("Failed to fit into largest table size\n");
        return r;
    }
    while (max_table_size > min_table_size+1)
    {   int mid = (min_table_size + max_table_size)/2;
        r = try_all_hash_functions(
            items,
            item_count,
            importance,
            table,
            hash_item_size,
            mid,
            set_key,
            0);        // Merely check if there is an allocation
        if (r.table_size == (uint32_t)(-1)) min_table_size = mid;
        else
        {   max_table_size = mid;
            rhi = r;
        }
    }
// So far I have just identified the best size table to use, but I
// have neither optimised moduls2/offset2 nor recorded a particular
// allocation of keys. So here I use a more expensive search.
    logprintf("Table will be of size %d\n", rhi.table_size);
    return try_all_hash_functions(
        items,
        item_count,
        importance,
        table,
        hash_item_size,
        rhi.table_size,
        set_key,
        1);        // Now do the full job!
}

// end of cuckoo.c
