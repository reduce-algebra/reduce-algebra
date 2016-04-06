// cuckoo.h                                        A C Norman, October 2016

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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

#ifndef __cuckoo_h
#define __cuckoo_h

// While testing I will arrange to be ale to use either an original
// or a spare version of the Hungarian algorithm for best matchings in
// weighted bipartite graphs.

#ifdef SPARSE
#include "hunsparse.h"
#else
#include "hungarian.h"
#endif


#ifdef WIN32

#include <windows.h>

// On Windows I can use CRITICAL_SECTIONs rather than real mutexes, and the
// performance difference is quite substantial when contention is reasonably
// low. The key issue is that a CRITICAL_SECTION does its initial checks in
// user-mode and only upgrades to kernel mode in the complicated cases. A
// side effect of this is that all use of one of these locks must occur
// within a single process, while more general mutexes support use even
// when multiple processes are present.

// I will not destroy mutexes at the end of a run - they can be cleaned up
// as the application exits.

extern CRITICAL_SECTION critical_section, logmutex;

#define CREATEMUTEX        InitializeCriticalSection(&critical_section)
#define LOCKMUTEX          EnterCriticalSection(&critical_section)
#define UNLOCKMUTEX        LeaveCriticalSection(&critical_section)

#define CREATELOGMUTEX     InitializeCriticalSection(&logmutex)
#define LOCKLOGMUTEX       EnterCriticalSection(&logmutex)
#define UNLOCKLOGMUTEX     LeaveCriticalSection(&logmutex)

#else

#include <pthread.h>
#include <unistd.h>

extern pthread_mutex_t mutex, logmutex, condmutex;
extern pthread_cond_t  cond;

// Using Posix threads I initialise the mutexes statically.

#define CREATEMUTEX        // Nothing
#define LOCKMUTEX          pthread_mutex_lock(&mutex)
#define UNLOCKMUTEX        pthread_mutex_unlock(&mutex)

#define CREATELOGMUTEX     // Nothing
#define LOCKLOGMUTEX       if (pthread_mutex_lock(&logmutex) != 0) \
                           { fprintf(stderr, "locking failed\n"); exit(1); }
#define UNLOCKLOGMUTEX     if (pthread_mutex_unlock(&logmutex) != 0) \
                           { fprintf(stderr, "locking failed\n"); exit(1); }


#endif

// "Cuckoo hashing" is a scheme where each key has a small fixed number
// of locations in a hash table that it can occupy. Hash insertion works by
// trying to place an item in one of these, and if all of those are already
// in use it ejects one of the existing keys to make space, and then
// reinserts that ejected key in one of the other locations it could legally
// end up.
// There are two very nice features that can be achieved via this. The first
// is that lookups have O(1) cost. In the variant used here each lookup
// will inspect at most three locations in the hash table. The second is
// that amazingly high load factors can be achieved. With three probes it
// will normally be possible to fill a table around 91% full before an
// attempted insert fails.
//
// Ny code here merely positions keys in tha table. A subsequent pass
// should be used to insert any associated data.
//
// Here I am most interested in statically-created tables, and by trying to
// fit keys into the tables using a range of different (But all very simple)
// hash functions I find that for the data that interests me I can often end
// achieve a load-factor of 97% or 98%. This gives a good approximation to
// the effect of perfect hashing.
//
// The functions here (a) help pick paramaters and create a near-optimal
// table and (b) look items up in it fast. For larger tables the search
// for a good (ie small) table can be quite seriously time-consuming.
// See the code containing the implementation for further commentary on this.
//
// The hash tables I use here are required to have keys that fit within
// uint32_t.

// The hash table will be an array, but my code will not know
// exactly what its internal format is. In relevant places I will
// pass down the size of each item in the array. Here I have typedefs
// for functions to access the field within a table entry that is
// used as a hash key. You pass them a pointer to the relevant
// offset within the array...


// get_key will take a pointer to an entry in the hash table and
// retrieve the key stored there, which will be zero if the entry
// is not in use.

typedef uint32_t cuckoo_get_key(void *p);

// set_key takes a pointer into the hash table and a key value to
// record there. It does not do anything to the rest of the entry - it only
// updates the key field. Note that key values must never be 0 since that
// value is used to mark and empty slot in the hash table.

typedef void     cuckoo_set_key(void *p, uint32_t key);

// I can (optionally) pass a function of this type to the code that creates
// a table. It gets handed a key. If it returns CUCKOO_VITAL the table will
// be built such that that key is found on the first probe. If there are n
// keys in the table and no other special circumstances it is probably going
// to lead to trouble if more than around sqrt(n) keys are given this extreme
// priority.
// Keys that return CUCKOO_IMPORTANT will be found in one or two probes, and
// it may perhaps be acceptable to allow up to 20% or even 25% of the keys
// to specify this. Otherwise search can involve up to three probes. The
// lookup code does not need to be aware of any of this, just the code that
// creates the hash table.

// Note of course that without this everything would have an expected cost
// of only 2 probes, so VITAL reduces that to 1 and IMPORTANT to 1.5.
// Thus savings from use of the scheme can never be huge. But this gives
// you an opportunity to experiment! I found in one test that tagging every
// key as IMPORTANT (which reduces behaviour to 2-place cuckoo hashing, which
// expects to fail when the table becomes over 50% full) allowed me to find
// parameters giving a table-occupancy of better than 80% and an average
// access in around 1.3 probes. That convinces me that careful tuning of
// what is "important" can lead to good balances between compact tables and
// access speed. My current suggestion is that around 10% items being
// IMPORTANT and a really small number VITAL may be about right.


#define CUCKOO_STANDARD  0
#define CUCKOO_IMPORTANT 1
#define CUCKOO_VITAL     2

typedef int      cuckoo_importance(uint32_t key);

// Now the generic function for retrieving information from a hash table.
// It is passed a key and a table. It then needs a load more arguments that
// characterize the table! It returns the offset in the table where the
// key is present, or (uint32_t)(-1) if it is not present. Thus the user then
// needs to understand the format of table entries and take responsibiliry
// for unpacking whatever data is required.

// It is possible that if all this was implemented in C++ rather than C
// that templates and classes could wrap up all the information passed
// here as explicit extra arguments, but at present I believe that the
// complication and overhead would mean that things ended up almost as
// bad.

// If I am using gcc I can use inline functions here for improved
// performance. You can predefine FORCE_INLINE to enable this, NEVER_INLINE
// to disable it. The default behaviour is to check if we are using gcc
// with inline capability available.

#if defined FORCE_INLINE
#define cuckoo_inline inline
#elif !defined NEVER_INLINE && \
      (defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__)
#define cuckoo_inline inline
#else
#define cuckoo_inline
#endif

// Because the table was passed as a "void *" and we do not have
// a single type that maps the entries it is not feasible to use direct
// array access (as in "table[n]") to retrieve and update items in it.
// So here I have two macros that use the explicitly passed item size
// and accress arithmetic to create a pointer to the nth item in the
// table, and then the user-supplied functions to deal with just the
// part of the thing there that represents the key. These are macros
// not functions because they use a number of values not explicitly passed
// to them as arguments.

// The three access macros are not inline functions because they need to
// reference the (local) variables table and hash_item_size that their
// user has.

#define cuckoo_item(n) \
    ((char *)table + hash_item_size*(n))

#define cuckoo_key(n) \
    ((*get_key)(cuckoo_item(n)))

#define cuckoo_set_key(n, v) \
    ((*set_key)(cuckoo_item(n), v))

// Im any concrete instance it may be sensible to transcribe this
// into the code that uses it, putting in direct code in place of the
// access function "get_key" and writing in the constant values for
// hash_item_size, table_size, modulus2 and offset2. If a (probably
// small) table had been set up with everything IMPORTANT then the
// third probe can be removed.

static cuckoo_inline uint32_t cuckoo_lookup(
    uint32_t key,             // integer key to look up
    void *table,              // base of the hash table
    size_t hash_item_size,    // size of each item in the table,
    // must be <= MAX_CUCKOO_ITEM_SIZE
    uint32_t table_size,      // number of entries in the hash table
    cuckoo_get_key *get_key,  // function to retrieve keys from table
    uint32_t modulus2,        // used to give a secondary hash function
    uint32_t offset2)         // used to give a secondary hash function
{
// My initial hash value is merely the key reduced modulo the size of
// the table.
    uint32_t hash1 = key % table_size;
    uint32_t hash2;
    if (cuckoo_key(hash1) == key) return hash1;
// I have a secondary hash function that will not map onto the whole
// of the table - it uses a second smaller modulus and an offset. The
// sum of these must not exceed the table size (so as to avoid running
// over the end) but should probably be an appreciable fraction of it.
    hash2 = (key % modulus2) + offset2;
    if (cuckoo_key(hash2) == key) return hash2;
// The third and final place I look is found by adding the two previous
// hash values (and reducing modulo the table size). If the modulus operation
// was expensive but conditional branches were cheap then
//       if ((hash1 += hash2) >= table_size) hash1 -= table_size;
// could be used here.
    hash1 = (hash1 + hash2) % table_size;
    if (cuckoo_key(hash1) == key) return hash1;
// If the key is not found in any of those three locations I just return -1.
    return (uint32_t)(-1);
}

// The function cuckoo_insert inserts a single item into a table and returns
// the location where it was placed. It does not fill in any associated
// data - just the key. If it fails after a large number of operations that
// shuffle the table it returns (uint32_t)(-1). If it does that then it will
// leave a hash-table entry in cuckoo_pending_item. Note verey well that in
// general that will be one of they keys that had previously been inserted
// rather than the new one. One possible use for this would be to fix a table
// size and insert all your keys - some may fail so you collect them so they
// can be handled by some secondary process.
//
// For cuckoo hashing one used three hash functions. The ones used here
// are
//     h1 = key % table_size
//     h2 = key % modulus2 + offset2
//     h3 = (h1 + h2) % table_size

extern char cuckoo_pending_item[];

extern uint32_t cuckoo_insert(
    uint32_t key,             // integer key to look up
    cuckoo_importance *importance, // how important are various keys?
    void *table,              // base of the hash table
    size_t hash_item_size,    // size of each item in the table,
    // must be <= MAX_CUCKOO_ITEM_SIZE
    uint32_t table_size,      // number of entries in the hash table
    cuckoo_get_key *get_key,  // function to retrieve keys from table
    cuckoo_set_key *set_key,  // function to set a key in the table
    uint32_t modulus2,        // used to give a secondary hash function
    uint32_t offset2);        // used to give a secondary hash function

// Some functions return a "cuckoo_parameters" value. This gives the
// size of the hash table in use, values for modulus2 and offset2 (ie
// details of the hash function selected) and, in some cases, a figure
// of merit that is best if it is a low value, and that represents an
// estimate for the number of probes needed to look things up, with
// higher importance given to IMPORTANT cases. It should always be
// between 1.0 and 3.0, where 1.0 would indicate that all keys
// had been so positioned that they were accessed in only one probe, while
// 3.0 would suggest that every key needed 3 probes. If all keys where
// tagged as IMPORTANT than a merit of 1.5 would be the target to be beaten,
// while if many of STANDARD anything better than 2.0 counts as good.
//
// If table_size is set to (uint32_t)(-1) in a cuckoo_parameters that marks
// failure to set up the table.

typedef struct __cuckoo_parameters
{   uint32_t table_size;
    uint32_t modulus2;
    uint32_t offset2;
    double   merit;
} cuckoo_parameters;

// cuckoo_optimise seeks a near-optimal hash table by picking values for
// modulus2 and offset2. It does this by a brute-force search starting at
// initial_table_size and keeping going up to max_table_size. If it fails
// it will return a record with the table_size entry (uint32_t)(-1).
//

// If the associated file cuckoo.c is compiled with default options it uses
// "fork" to set up 8 sub-tasks that run parts of the seatch. Synchromisation
// between them is light and this could mean that two consecutive runs with
// exactly the same data yield different results. amounts up data up to say
// a couple of thousand keys the time all this takes is not too painful. In
// my application I have around 10000 keys. So (at least notionally) I run
// the parallel seach once with an initial table size equal to the number of
// keys I have (i.e. just checking that I can not achieve the utter perfection
// of no wasted space at all). Having done that I then know (well certainly
// very closely) how large a table will be needed, so I re-run the scan with
// initial_table_size just below that and with cuckoo.c compiled with
// "-DSEQUENTIAL" which disables the parallel search and guarantees consistent
// results.
// In practise a more realistic scheme is to start a try with a large
// table and observe success, then START a try with a small one, but interrupt
// it as soon as it reports no solutions for that size table, and perform
// a binary chop from there. Hmmm see later for cuckoo_binary_optimise that
// does just that. But this entrypoint is useful either as a sub-function
// called by the binary chop code or if there is any external reason to
// want to do a crude linear search.
// I might also note that the parallel search can represent something
// of a CPU stress test - at one stage it crashed my computer and I needed
// to adjust BIOS settings to be more conservative!
// It mey be reasonable to set max_table_size so that if that table were to
// grow to that size it would only be say 85% full. Given that with cuckoo
// hashing with 3 probes one expects to achieve better than 90% occupancy
// failure to achieve 85% might signal either overenthusiastic use of
// the "importance" function or a pathological interaction between you set of
// keys and the very simple hash functions used here. I think in that case
// I will leave you to find your own resolution!

// With sample data and 1000 keys on a 4-core CPU that pretends to have 8
// cores using hyperthreading I observed a sequential search taking close to
// 2 minutes, and the parallel one 23 seconds.


extern cuckoo_parameters cuckoo_optimise(
    uint32_t *items,               // table of keys
    int item_count,                // number of keys
    cuckoo_importance *importance, // importance judgement on keys
    void *table,                   // hash table to create
    int hash_item_size,            // size of each entry in hash table
    int initial_table_size,        // initial number of entries in table ...
    int max_table_size,            // ... and limit on how large it may grow
    cuckoo_get_key *get_key,       // access functions for hash table.
    cuckoo_set_key *set_key);

// cuckoo_optimise as above increases the table-size that it tries linearly
// and can hence be very slow indeed. In cases other than rather small ones
// people should use cuckoo_binary_optimise. When it is called the value
// of min_table_size should be such that a solution can not be found. Using
// a value one less than the number of distinct keys should be reasonable!
// The value for max_table_size must be such that a solution is available
// by then - and perhaps twice min_table_size is a safe and conservative
// choice.
// I rather expect that if either of these are set to somewhat extreme values
// it will not hurt much, because for table sizes that are much too small
// the code should report failure rapidly, while for table sizes that are
// generous it will be able to report success equally rapidly. The high
// costs are most liable to arise once the search has narrowed close to the
// critical size. Well that is the ideal! For large tables it would be
// a good idea to have the min and max sizes as sharp as possible. The
// "ideal" case is when min indicates the largest table where the information
// can not be fitted and max is just one higher and is the smallest size
// where things do fit. Calling cuckoo_binary_optimise then merely verifies
// this.
// If one makes modest changes to the "importance" function or small changes
// to the data it may be possible to have good early estimates of suitable
// limits.
// I have a test case with around 10000 keys, and simple use of
// cuckoo_binary_optimise ran for a real time of 4.5 hours and a "user"
// time of 35 hours...
//
// Note that in this application binary search is not perfect. Eg it could
// be that if the table size was an exact power of 2 then the trivial hash
// scheme I use here might perform very badly. Hence if the search range
// included such a case (or other anomalous one) the attempt to pack that
// particular table might fail even though some smaller case might in fact
// have succeeded. Similarly there could be a small table with a very special
// size that would be usable even though all those close to it are not, and
// binary search may not find that. Use of the simpler but slower
// cuckoo_optimise avoids these risks. My guess is that in practical terms
// the search inadequacies here are not important, but those who are ultra
// cautious will run this binary search first, and then run the linear search
// as a low priority long-running background task just to verify that nothing
// better is available.

extern cuckoo_parameters cuckoo_binary_optimise(
    uint32_t *items,               // table of keys
    int item_count,                // number of keys
    cuckoo_importance *importance, // importance judgement on keys
    void *table,                   // hash table to create
    int hash_item_size,            // size of each entry in hash table
    int min_table_size,            // minimum table size
    int max_table_size,            // maximum table size
    cuckoo_get_key *get_key,       // access functions for hash table.
    cuckoo_set_key *set_key,
    double merit_target);          // target for table merit

// This function takes a size and values of modulus2 and offset2 and
// finds the best assignment corresponding to them. It returns a figure of
// merit in the range 1.0 to 3.0 on success, and -1.0 on failure. Note that
// low values of merit are good.
// If the merit found here is < target_merit it displays trace output.
// The hash table it builds up is a simple array of unsigned integers, so that
// the extra overhead of the getter and setter functions is avoided.

extern double hungarian_insert_all(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    uint32_t *table,
    int table_size,
    uint32_t modulus2,
    uint32_t offset2,
    double target_merit);

// For a given table size try all values of modulus2 and offset2 and
// return information about the best assignment found.

extern cuckoo_parameters hungarian_try_all_hash_functions(
    uint32_t *keys,
    int keycount,
    cuckoo_importance *importance,
    void *hash,
    int hash_item_size,
    int hashsize,
    cuckoo_set_key *set_key);


#endif // __cuckoo_h

// End of cuckoo.h
