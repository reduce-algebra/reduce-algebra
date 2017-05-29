// hash.cpp                                   Copyright (C) A C Norman 2017

// This code anaylses the output from mr2a.c, which is table showing for
// each potential witness what the pseudoprimes up to 2^32 are using that
// value as a base. Its purpose is to find a hash-based scheme that will
// make it possible to check 32-bit numbers for primality with one use of
// Miller-Rabin and the the witness selected using a hash function applied
// to the input.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

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

// I will run my search using multiple threads, which can speed things
// up usefully.
// I try to encapsulate the variations between thread support across
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

// Now code that implements Miller-Rabin.

// The function mulmod(a, b, n) computes a*b mod n where a, b and n are
// all unsigned 32-bit integers. As coded here it does the multiplication
// and remainder steps using 64-bit arithmetic so as to avoid overflow.
// With a good compiler this is expected to generate code that would be
// hard to improve on. The function is "inline" to avoid call overhead
// while preserving a tidy abstract presentation.

static inline uint32_t mulmod(uint32_t a, uint32_t b, uint32_t n)
{   return (uint32_t)(((uint64_t)a*(uint64_t)b) % n);
}

// Compute x^n mod p

static inline uint32_t exptmod(uint32_t x, uint32_t n, uint32_t p)
{   uint32_t y = 1;
    while (n > 1)
    {   if (n%2 != 0) y = mulmod(x, y, p);
        x = mulmod(x, x, p);
        n = n / 2;
    }
    return mulmod(x, y, p);
}

// Use Miller-Rabin with base a to check whether n is a (pseudo-)prime. The
// way this is used here should ensure that it is in fact 100% reliable in
// identifying primes. If this was used in a probabilistic context then this
// function would be called repeatedly with random first arguments. In my
// use if is called with carefully selected first arguments so as to avoid
// strong pseudo-primes.

static inline bool miller_rabin_isprime(uint32_t a, uint32_t n)
{   uint32_t d = n-1;
    int s = 0;
    while ((d % 2) == 0)  // Find largest power of 2 dividing n-1
    {   d = d/2;
        ++s;
    }
    uint32_t x = exptmod(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s > 1)
    {   x = mulmod(x, x, n);
        if (x == 1) return false;
        else if (x == n-1) return true;
        --s;
    }
    return false;
}

// Hashing from inputs to a base will use this many buckets.

#define WITNESS_COUNT 0x10000
#define MAX_NUMBER_OF_BUCKETS 1024

unsigned int number_of_buckets;
unsigned number_to_fill;

// The value hash_multiplier will be used as part of the hashing.
static __thread uint64_t local_hash_multiplier;
static uint64_t hash_multiplier;

static inline unsigned int hash_function(uint32_t p)
{   return (unsigned int)
        ((hash_multiplier*(uint64_t)p)>>31) % number_of_buckets;
}

static inline unsigned int local_hash_function(uint32_t p)
{   return (unsigned int)
        ((local_hash_multiplier*(uint64_t)p)>>31) % number_of_buckets;
}

// This table of witnesses needs to be filled in before the isprime
// function will behave. Its size can be number_of_buckets.

static __thread uint16_t local_witness[MAX_NUMBER_OF_BUCKETS];
static uint16_t witness[MAX_NUMBER_OF_BUCKETS];

// This is the function that a user might call to test for primality.

bool isprime(uint32_t n)
{
// I will start by filtering out potential very small factors. This
// detects a significant fraction of composites cheaply, and is expected to
// be overall good for average efficiency.
// The next line checks for divisibility by 2, 3 and 7...
    if ((UINT64_C(0x000001df5d75d7dd) & (UINT64_C(1)<<(n%42U))) != 0)
        return (n==2) || (n==3) || (n==7);
// ... and this one copes with 5 and 11.
    if ((UINT64_C(0x0004310a42508c21) & (UINT64_C(1)<<(n%55U))) != 0)
        return (n==5) || (n==11);
// If there are no factors of 2,3,5,7 or 11 then any number left (apart from
// the special case 1) up to 13*13 must be a prime.
    if (n < 169) return (n!=1);
// Now I use hashing and my table to select a witness that will cause
// Miller-Rabin to deliver a fully reliable result.
    return miller_rabin_isprime(witness[hash_function(n)], n);
}

static void report_time(const char *msg); 
static void initialize_everything(int argc, char *argv[]);
static void read_pseudoprime_data();
static THREADRESULT_T search_for_good_parameters(void *arg);
static void display_results();
static void verify_results();

unsigned int cpu_count;
static bool good_parameters_found = false;

int main(int argc, char *argv[])
{   initialize_everything(argc, argv);
    report_time("About to read in pseudoprime data");
    read_pseudoprime_data();
    report_time("Data read in");
// Now I will start a parallel search...
    cpu_count = number_of_processors();
    printf("I seem to have %d processors\n", cpu_count);
    fflush(stdout);
    if (cpu_count > MAX_CPU_COUNT) cpu_count = MAX_CPU_COUNT;
    if (cpu_count > 3) --cpu_count; // leave a CPU free for other tasks!

    if (CREATEMUTEX_FAILED)
    {   fprintf(stderr, "Unable to create mutex\n");
        exit(1);
    }
    good_parameters_found = false;
    for (int k=0; k<cpu_count; k++)
        if (CREATETHREAD_FAILED(k, search_for_good_parameters))
        {   printf("Failed to create at %d\n", k);
            exit(1);
        }
    for (int k=0; k<cpu_count; k++)
        if (JOINTHREAD_FAILED(k))
        {   printf("Failed to join at %d\n", k);
            exit(1);
        }
    DESTROYMUTEX;
    if (!good_parameters_found)
    {   report_time("Failed to find solution");
        exit(1);
    }
    report_time("Solution found");
    display_results();
    if (number_of_buckets == number_to_fill) verify_results();
    report_time("Finished");
    return 0;
}

clock_t c0, c1;

static void report_time(const char *msg)
{   clock_t c2 = clock();
    printf("%s after %.1f [%.1f] seconds\n", msg,
           (double)(c2-c0)/CLOCKS_PER_SEC,
           (double)(c2-c1)/CLOCKS_PER_SEC);
    c1 = c2;
    fflush(stdout);
}

typedef struct __hash_entry
{   uint32_t key;
    uint16_t *val;
} hash_entry;

uint32_t hashsize;
static hash_entry *hashtable;

unsigned int max_tries;
uint64_t malloc_use = 0;

static inline void check_malloc(void *p)
{   if (p == NULL)
    {   printf("malloc or realloc failed\n");
        exit(1);
    }
}

static void initialize_everything(int argc, char *argv[])
{
// Read the clock so I can report how long everything takes.
    c0 = c1 = clock();
// Sort out how many buckets to go for.
    if (argc <= 1) number_of_buckets = 256;
    else if (sscanf(argv[1], "%u", &number_of_buckets) != 1)
    {   printf("Argument '%s' seems invalid\n", argv[1]);
        exit(1);
    }
    if (number_of_buckets < 4 || number_of_buckets > MAX_NUMBER_OF_BUCKETS)
    {   printf("Argument '%u' seems out of range\n", number_of_buckets);
        exit(1);
    }
    if (argc <= 2) number_to_fill = number_of_buckets;
    else if (sscanf(argv[2], "%u", &number_to_fill) != 1)
    {   printf("Argument '%s' seems invalid\n", argv[2]);
        exit(1);
    }
    if (number_to_fill < 1 || number_to_fill > number_of_buckets)
    {   printf("Argument '%u' seems out of range\n", number_to_fill);
        exit(1);
    }
    if (argc <= 3) max_tries = 1200;
    else if (sscanf(argv[3], "%u", &max_tries) != 1)
    {   printf("Argument '%s' seems invalid\n", argv[3]);
        exit(1);
    }
    if (max_tries < 1 || max_tries > 0x01000000)
    {   printf("Argument '%u' seems out of range\n", max_tries);
        exit(1);
    }
    

// I will use a hash table to record data about pseudo primes. I know
// by having inspected the data already that there will be about 8 million
// entries in it, so I will use a fixed size table allocated right
// at the start. The size used here is a prime and is such that that
// table will be around 2/3 full. I view that as a decent balance on
// space used, the cost of a linear scan and keeping hash access fast enough.
    hashsize = 12000017;
    hashtable = (hash_entry *)malloc(hashsize*sizeof(hash_entry));
    check_malloc(hashtable);
    malloc_use += hashsize*sizeof(hash_entry);
    memset(hashtable, 0, hashsize*sizeof(hash_entry));
}

#define POOL_SIZE 10000000
static char *pool = NULL;
static size_t pool_pointer = 0;

// I will call malloc() for big blocks, and allocate within each
// using my own simple linear allocation code. This should reduce
// overheap in any case where malloc is expensive.

static inline void *my_malloc(size_t n)
{   if (pool == NULL ||
        pool_pointer+n > POOL_SIZE)
    {   pool = (char *)malloc(POOL_SIZE); // Grab in 10 Mbyte chunks
        check_malloc(pool);
        pool_pointer = 0;
    }
    char *r = &pool[pool_pointer];
    pool_pointer += n;
    return r;
}

// Here I have a witness and a pseudoprime. Record the pair.

static void insertpseudo(uint32_t pseudoprime, int witness)
{
// I have a hash table for all the pseudoprimes (to any base). I use
// rather a simple hash function.
     if (pseudoprime < 4096) return; // I will handle small numbers specially.
    if (pseudoprime % 2 == 0 ||
        pseudoprime % 3 == 0 ||
        pseudoprime % 5 == 0 ||
        pseudoprime % 7 == 0 ||
        pseudoprime % 11 == 0) return;
// I use two simple multiplicative hash functions in a double hashing
// scheme here, so I hope not to get too much clustering.
    int h = (0x12345678*pseudoprime) % hashsize;
    while (hashtable[h].key != 0 &&
           hashtable[h].key != pseudoprime)
        h = (h + 1 + ((0x31415926*pseudoprime) % (hashsize-2))) % hashsize;
    if (hashtable[h].key == 0)
    {   hashtable[h].key = pseudoprime;
        hashtable[h].val = (uint16_t *)my_malloc(16*sizeof(uint16_t));
        malloc_use += 16*sizeof(uint16_t);
        memset(hashtable[h].val, 0, 16*sizeof(uint16_t));
        hashtable[h].val[0] = 16;
    }
    int n = hashtable[h].val[1] + 1;
    if (n == hashtable[h].val[0]-1)
    {   size_t newsize = 2*hashtable[h].val[0];
// I used to use realloc here, but now I just call malloc again. Because I
// double sizes on each expansion the eventual overhead here is at worst
// a factor of 2 in memory occupancy.
        uint16_t *w = (uint16_t *)my_malloc(newsize*sizeof(uint16_t));
        memcpy(w, hashtable[h].val, hashtable[h].val[0]*sizeof(uint16_t));
        hashtable[h].val = w;
        malloc_use += newsize*sizeof(uint16_t);
        hashtable[h].val[0] = newsize;
    }
    hashtable[h].val[n+1] = witness;
    hashtable[h].val[1] = n;
}

static int compare_function(const void *va, const void *vb)
{   hash_entry *a = (hash_entry *)va;
    hash_entry *b = (hash_entry *)vb;
    if (a->key == b->key) return 0;
    else if (a->key == 0) return 1;
    else if (b->key == 0) return -1;
// That will have arranged that all entries with zero keys (ie empty hash
// slots) end up at one end of the table. In what follows I have a non-
// empty slot and hence the val field will contain genuine data.
// I will sort such that numbers that are pseudo-primes to many bases
// and up at the start of the table. I expect that to help to speed
// up detecting infeasible configurations.
    return b->val[1] - a->val[1];
}

static int witness_pseudo_pairs = 0;

static void printcounts(int i)
{   if (i < hashsize && hashtable[i].val != NULL)
        printf("%d:  %.8x fails for %d bases\n",
            i, hashtable[i].key, hashtable[i].val[1]);
}

static void read_pseudoprime_data()
{
// This code finds its input data in a fixed place.
    witness_pseudo_pairs = 0;
    FILE *data = fopen("mr2a.log", "r");
    setvbuf(data, NULL, _IOFBF, 8*1024*1024);
    int c2=0, c3=0, c5=0, c7=0, c11=0, c13=0, c17=0, c19=0;
    for (;;)
    {   int witness, witnessx, count;
        while (fscanf(data, "Pseudoprimes using witness %d (%x)  count=%d",
                      &witness, &witnessx, &count) != 3)
        {   if (feof(data))
            {   witness = witnessx = count = 0;
                break;
            }
            getc(data);
        }
        if (count == 0) break;
        if (witness%5000 == 0)
        {   printf("%5d of 65536\n", witness);
            fflush(stdout);
        }
        if (witness >= WITNESS_COUNT || witness <= 1) continue;
        for (int i=0; i<count; i++)
        {   unsigned pseudoprime;
            if (fscanf(data, "%x", &pseudoprime) != 1)
            {   printf("Malformed data file for witness %u/%#x\n",
                       witness, witness);
                exit(1);
            }
            if (pseudoprime%2 == 0) c2++;
            if (pseudoprime%3 == 0) c3++;
            if (pseudoprime%5 == 0) c5++;
            if (pseudoprime%7 == 0) c7++;
            if (pseudoprime%11 == 0) c11++;
            if (pseudoprime%13 == 0) c13++;
            if (pseudoprime%17 == 0) c17++;
            if (pseudoprime%19 == 0) c19++;
            insertpseudo(pseudoprime, witness);
            witness_pseudo_pairs++;
        }
    }
    fclose(data);
    qsort(hashtable, hashsize, sizeof(hash_entry), compare_function);
    printf("c2=%d c3=%d c5=%d c7=%d c11=%d c13=%d c17=%d c19=%d\n",
        c2, c3, c5, c7, c11, c13, c17, c19);
    for (int i=0; i<10; i++) printcounts(i);
    for (int i=10; i<100; i+=5) printcounts(i);
    for (int i=100; i<1000; i+=50) printcounts(i);
    for (int i=1000; i<10000; i+=500) printcounts(i);
    for (int i=10000; i<100000; i+=5000) printcounts(i);
    for (int i=100000; i<1000000; i+=50000) printcounts(i);
}

static __thread bool *validwitness[WITNESS_COUNT];
static __thread int validcount[MAX_NUMBER_OF_BUCKETS];

// Here is a generated table showing prime factors of small integers.
// The table is "int16_t *small_factors[65536];" where each entry points
// to a zero-terminated vector holding primes that divide into a potential
// witness. Primes 2, 3, 5, 7 and 11 are not included in the list since they
// have been sorted out otherwise.

#include "smallfac.cpp"

unsigned int trial = 1;
double s0 = 0.0;
double s1 = 0.0;
double s2 = 0.0;
double best = 0.0;
unsigned int bestat = 0;

bool mode_found = false;
#define NSAMPLES 1000
#define HISTSIZE 75
int histogram[HISTSIZE];
int nsamples = 0;
double samples[NSAMPLES];
double mode = 0.0;


static THREADRESULT_T search_for_good_parameters(void *arg)
{   for (int i=0; i<WITNESS_COUNT; i++)
    {   validwitness[i] = (bool *)malloc(number_of_buckets*sizeof(bool));
        check_malloc(validwitness[i]);
    }
    for (;;)
    {   LOCKMUTEX;
        if (good_parameters_found || trial++ >= max_tries)
        {   UNLOCKMUTEX;
            break;
        }
// Get a random multiplier to use, /dev/urandom should yield different
// values on every run.
        FILE *f = fopen("/dev/urandom", "rb");
        if (f == NULL)
        {   printf("Unable to access /dev/urandom\n");
            exit(1);
        }
        if (fread(&local_hash_multiplier, sizeof(local_hash_multiplier), 1, f) != 1)
        {   printf("Reading from /dev/urandom failed\n");
            exit(1);
        }
        fclose(f);
        if (trial%20 == 0)
        {   printf("Try %d for %d buckets: m = %.16" PRIx64 "\n",
                   trial, number_of_buckets, local_hash_multiplier);
            fflush(stdout);
        }
        UNLOCKMUTEX;
// In this count of the number of remaining valid witnesses I subtract 2
// because the values 0 and 1 are never valid.
        for (int i=0; i<number_of_buckets; i++)
            validcount[i] = WITNESS_COUNT-2;
        for (int b=0; b<number_of_buckets; b++)
        {   for (int i=0; i<WITNESS_COUNT; i++) validwitness[i][b] = true;
            validwitness[0][b] = false;
            validwitness[1][b] = false;
        }
// Here I can build a list of witness values that avoid any issues with
// strong pseudoprimes. There remains a further potential pain. If a
// witness has a prime factor that hashes to trigger its use then that
// prime would end up being reported as composite. So I need to disallow
// any such cases.
        for (int wit=2; wit<WITNESS_COUNT; wit++)
        {   uint16_t *p = small_factors[wit];
            while (*p != 0)
            {   unsigned int h = local_hash_function(*p++);
                if (validwitness[wit][h]) validcount[h]--;
                validwitness[wit][h] = false;
            }
        }
// I am going to want to collect information about how far through
// processing pseudo-primes I get. I am going to expect that the
// number of cases I inspect before running into difficulty is approximately
// an exponential distribution. This will not quite be the case! But based
// of that approximation I will be able to generate a prediction as to how
// many more trials are liable to be needed before I succeed in finding
// a solution.
        int b;
        unsigned int probes_this_time = 0;
        for (int i=0; i<hashsize; i++)
        {   uint32_t p = hashtable[i].key;
            if (p == 0) continue;
            int h = local_hash_function(p);
            uint16_t *w = hashtable[i].val;
            for (int j=2; j<=w[1]+1; j++)
            {   probes_this_time++;
                int wit = w[j];
                if (validwitness[wit][h])
                {   validwitness[wit][h] = false;
// If one of the first number_to_fill buckets ends up with no valid
// witnesses then I will give up.
                    if (--validcount[h] <= 0 &&
                        h<number_to_fill
                       ) goto failing;
                }
            }
        }
        for (b=0; b<number_to_fill; b++)
        {   int i;
            for (i=2; i<WITNESS_COUNT; i++)
            {  if (validwitness[i][b]) break;
            }
            if (i >= WITNESS_COUNT)
            {   printf("Unexpected failure (%d)\n", validcount[b]);
                for (int k=0; k<number_of_buckets; k++)
                {   if (k%16 == 0) printf("\n");
                    printf("%4d", validcount[k]);
                }
                printf("\n");
                break; // Should never happen, I think
            }
            local_witness[b] = i;
        }
        if (b>=number_of_buckets) break;
    failing:
        LOCKMUTEX;
        double ratio = probes_this_time/(double)witness_pseudo_pairs;
        if (ratio > best)
        {   best = ratio;
            bestat = trial;
        }
        char msg[40];
        sprintf(msg, "   Failed at %.1f%%", 100.0*ratio);
        if (trial%20 == 0) report_time(msg);
        double guess = 9999999.0;
// For the first NSAMPLES I will just store the information about how I
// got on. Just when I reach there I will first use the stored samples
// to estimate the mode of my distribution and retrospectivly process the
// data as if I had known that in advance. Beyond that I will only collect
// information about values above my mode, and I will treat them as if
// they come from a Normal distribution.
        if (nsamples < NSAMPLES) samples[nsamples++] = ratio;
        else if (nsamples == NSAMPLES)
        {   nsamples++;
            printf("Have taken %d samples\n",  NSAMPLES);
            for (int i=0; i<HISTSIZE; i++) histogram[i] = 0;
            for (int i=0; i<nsamples; i++)
            {   ratio = samples[i];
                int j = (int)(HISTSIZE*ratio);
                histogram[j]++;
            }
            int peak = 0, peakat = 0;
            for (int i=0; i<HISTSIZE; i++)
            {   //printf("histogram[%2d] = %d", i, histogram[i]);
                if (histogram[i] > peak)
                {   peak = histogram[i];
                    //printf(" <");
                    peakat = i;
                }
                //else printf(" >");
                //printf("\n");
            }
            for (int i=peakat-3; i<=peakat+3 && i<HISTSIZE; i++)
                printf("%s%d:  %d   (%.2f)\n",
                    (i==peakat ? "!" : " "), i,
                    histogram[i], i/(double)HISTSIZE);
            for (int y=0; y<20; y++)
            {   int yy = peak-peak*y/19.0;
                for (int i=0; i<HISTSIZE; i++)
                {   bool b = histogram[i] >= yy;
                    putchar(b ? '*' : y==19 ? '_' : ' ') ;
                }
                putchar('\n');
            }
            if (peakat == HISTSIZE) peakat = HISTSIZE-1;
            mode = ((1/150.0)*(histogram[peakat+1]-histogram[peakat-1])) /
                (2*histogram[peakat]-histogram[peakat-1]-histogram[peakat+1]);
            mode *= HISTSIZE;
            mode = (mode + 0.5 + peakat)/(double)HISTSIZE;
            printf("Estimated mode = %.2f\n", mode);
            fflush(stdout);
            for (int i=0; i<nsamples; i++)
            {   ratio = samples[i];   
                if (ratio > mode)
                {   s0 += 1.0;
                    s1 += ratio;
                    s2 += ratio*ratio;
                }
            }
        }
        else
        {   if (ratio > mode)
            {   s0 += 1.0;
                s1 += ratio;
                s2 += ratio*ratio;
            }
// Here I am modelling the probability distribution to the right of the
// (estimated) mode as the right half of a Normal distribution.
            double mean = mode;
            double sd = sqrt(s2/s0 - 2.0*mode*s1/s0 + mode*mode);
            double deviation = (1.0-mode)/sd;
            if (trial%20 == 0)
            {   printf("s0=%.1f s1=%.3f s2=%.3f\n", s0, s1, s2);
                printf("mode=%.3f, sd=%.4f, excursion=%.2f\n", mode, sd, deviation);
            }
            double prob = 1.0 - erf(deviation);
// In degenerate cases the above will yield a NaN, in which case the
// test here causes me to discard the bad guess.
            if (prob > 1.0/guess) guess = 1.0/prob;
        }
        if (trial%20 == 0)
        {   printf("   best so far was %.1f%%"
                   " at try %u (mode=%.3f%% guess %u tries needed)\n",
                   100.0*best, bestat, mode, (unsigned int)guess);
            fflush(stdout);
        }
        UNLOCKMUTEX;
    }
    if (trial<max_tries && !good_parameters_found)
    {   LOCKMUTEX;
        good_parameters_found = true;
        hash_multiplier = local_hash_multiplier;
        for (int i=0; i<number_of_buckets; i++)
            witness[i] = local_witness[i];
        UNLOCKMUTEX;
    }
    return THREADRESULT;
}

static void display_results()
{   printf("%d Mbytes of memory used\n", (int)(malloc_use/(1024*1024)));
    printf("buckets: %d multiplier %.16" PRIx64 "\n\n",
           number_of_buckets, hash_multiplier);
// Print in a format that can be copied and pasted into the code.
    printf("static const uint64_t hash_multiplier = UINT64_C(0x%.16"
           PRIx64 ");\n\n", hash_multiplier); 
    printf("static uint16_t witness[%d] =", number_of_buckets);
    for (int b=0; b<number_of_buckets; b++)
    {   if (b == 0) printf("\n{   ");
        else if ((b % 10) == 0) printf("\n    ");
        printf("%5d", witness[b]);
        if (b != number_of_buckets-1) printf(", "); 
    }
    printf("\n};\n\n");
    fflush(stdout);
}

// When I have some results I should verify them just so I am sure...

static void verify_results()
{
// Set up a table of primes. I could use a bitmap here but I will take the
// view that the 2 Gbyte block I allocate here is tolerable on today's
// computers. But I could reduce it to 256 Mbytes if I wanted, and indeed
// see mr.cu for a version of the code that does that.
    char *primes = (char *)malloc(UINT64_C(0x80000000));
    if (primes == NULL)
    {   printf("Unable to allocate space\n");
        exit(1);
    }
// Sieve method. Note that I only use a bit for each odd number.
    printf("Now set up a table of primes\n");
    fflush(stdout);
    for (uint64_t i=0; i<UINT64_C(0x80000000); i++) primes[i] = 1; // provisionally prime
    primes[0] = 0;
    {   uint64_t p = 1;
        while (p*p < UINT64_C(0x100000000))
        {   while (primes[p/2] == 0) p+=2; // find next prime
            uint64_t np = (3*p-1)/2;
            while (np < UINT64_C(0x80000000))
            {   primes[np] = 0;
                np += p;
            }
            p += 2;
        }
    }
    report_time("Primes table set up");
    uint64_t trigger = 0x10000000;
    int p;
    if (isprime(p=0)  ||
        isprime(p=1)  ||
        !isprime(p=2))
    {   printf("incorrect result on small number %d\n", p);
        exit(1);
    }
    for (uint64_t i=3; i<UINT64_C(0x100000000); i++)
    {   if (i >= trigger)
        {   printf("Tested up to %" PRIx64 "\n", i);
            fflush(stdout);
            trigger += 0x10000000;
        }
        if (isprime(i))
        {   if ((i&1)==0 || !primes[(i-1)/2])
            {   printf("Incorrect result, %u reported as prime.\n",
                       (unsigned)i);
                exit(1);
            }
        }
        else
        {   if ((i&1)!=0 && primes[(i-1)/2])
            {   printf("Incorrect result, %u reported as composite.\n",
                       (unsigned)i);
                exit(1);
            }
        }
    }
    printf("Everything seems to be OK\n");
}

// end of hash.cpp
