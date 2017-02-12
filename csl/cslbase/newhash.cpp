// newhash.cpp                                             A C Norman, 2017

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

#include "headers.h"

// This fragment takes a 64-bit number that is a power of 2 and
// finds its logarithm, ie the number of bits that 1 needs to be shifted
// left to yield it. The function will return garbage if its input is
// not a power of 2.
//
// This table works because it is of length 67 and that is a prime, so
// the sequence 2^i mod 67 cycles through 1 .. 66 as I runs from 0 to 65,
// and 2^66 = 2^0 (mod 67). To help show this I have annotated the items at
// offsets 1, 2, 4, 8, 16, 32 and 64.

static unsigned char intlog2_table[] =
{
    0,      0,/*1*/ 1,/*2*/ 39,     2,/*4*/ 15,     40,     23,
    3,/*8*/ 12,     16,     59,     41,     19,     24,     54,
    4,/*16*/0,      13,     10,     17,     62,     60,     28,
    42,     30,     20,     51,     25,     44,     55,     47,
    5,/*32*/32,     0,      38,     14,     22,     11,     58,
    18,     53,     63,     9,      61,     27,     29,     50,
    43,     46,     31,     37,     21,     57,     52,     8,
    26,     49,     45,     36,     56,     7,      48,     35,
    6,/*64*/34,     33
};

static inline int intlog2(uint64_t n)
{
    return intlog2_table[n % (sizeof(intlog2_table)/sizeof(intlog2_table[0]))];
}

static inline bool is_power_of_two(uint64_t n)
{    return (n == (n & (-n)));
}

// Various internal functions that work on hash tables return either an
// index into a table or the marker value NOT_PRESENT.

#define NOT_PRESENT (SIZE_MAX)

// I make hash tables out of chunks each of which are vectors with
// (up to) 128K elements. This means that on a 64-bit machine each
// chunk occupies a megabyte. I can have two levels of structure, and
// by the time the index level is that size I will be have a table
// with 16G slots in it and occupying 256 Gbytes of memory. At present
// (2016) I view the limits there are such that they will not embarass
// me for some while. My belief is that allocating space in chunks like this
// is going to be more friendly as regards memory fragmentation than just
// using huge contiguous blocks.

//#define LOG2_VECTOR_CHUNK_WORDS 17     // in externs.h ...
//#define VECTOR_CHUNK_WORDS  ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) // 0x20000

// I use zero to mark entries here that are not in use.  As far as a
// LispObject is concerned that is a pointer to a CONS cell but at
// address zero, which should not arise. And anyway I am only going
// to put references to vectors here and this array will be cleared by the
// garbage collector rather than being scanned.

LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1] = {0};

// This will recover a saved vector if one is available.

static LispObject gvector(size_t n, LispObject initval)
{   size_t n1 = n/CELL - 1;    // size in words.
    if (is_power_of_two(n1))   // special if size is a power of 2.
    {   int i = intlog2(n1);   // identify what power of 2 we have.
        LispObject r;
        if (i <= LOG2_VECTOR_CHUNK_WORDS &&
            (r = free_vectors[i]) != 0)
        {   free_vectors[i] = elt(r, 0);
            for (size_t j=0; j<n1; j++) elt(r, j) = initval;
            return r;
        }
    }
// If there is no saved vector then allocate a new one.
    return getvector_init(n, initval);
}

static LispObject get_large_vector(size_t n, LispObject initval)
{   LispObject v;
//
// A major ugliness here is that I need to support hash tables that are
// larger than the largest simple vector I view as reasonable.  To achieve
// this I will handle such huge tables using a vector of vectors, with
// the higher level vector tagged as a INDEXVEC and the lower level vectors
// each modestly sized. For hash tables this will only ever be used for
// vectors whose total size is a power of 2, but looking forward to uses
// elsewhere I will make this general.
// So:
//   A vector of size up to VECTOR_CHUNK_WORDS will be represented
//     naturally as a single block of memory.
//   Larger vectors will have an INDEXVEC most of whose contents are
//     vectors of size VECTOR_CHUNK_WORDS but where the final item
//     may be smaller.
//
// As coded here I can only only create "general" vectors that contain Lisp
// objects - so variants such as strings, bignums and vectors that hold
// bytes, various fixed width integers or floats would need this code
// replicated.
    if (n > VECTOR_CHUNK_WORDS)
    {
// If the number size is exactly a multiple of the chunk size I will not
// need a special shorter final vector.
        size_t chunks = (n + VECTOR_CHUNK_WORDS - 1)/VECTOR_CHUNK_WORDS;
        size_t i;
// The final chunk will be full size if I have a neat multiple of
// VECTOR_CHUNK_WORDS, oterwise smaller.
        size_t last_size = n % VECTOR_CHUNK_WORDS;
        if (last_size == 0) last_size = VECTOR_CHUNK_WORDS;
        v = gvector(CELL*(chunks+1), nil);
// The next line re-tags the top level vector as an index.
        vechdr(v) ^= (TYPE_SIMPLE_VEC ^ TYPE_INDEXVEC);
        for (i=0; i<chunks; i++)
        {   LispObject v1;
            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_WORDS;
            push(v);
            v1 = gvector(CELL*(k+1), initval);
            pop(v);
            elt(v, i) = v1;
        }
    }
    else v = gvector(CELL*(n+1), initval);
    return v;
}

static inline size_t words_in_large_vector(LispObject v)
{   if (type_of_header(vechdr(v)) == TYPE_INDEXVEC)
    {   size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// See that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
        return VECTOR_CHUNK_WORDS*(n-1) +
            (length_of_header(vechdr(elt(v, n-1))) - CELL)/CELL;
    }
    else return (length_of_header(vechdr(v)) - CELL)/CELL;
}

static inline void discard_raw_vector(LispObject v)
{   size_t n1 = length_of_header(vechdr(v))/CELL - 1; // length in words
    if (is_power_of_two(n1))   // only save vectors whose size if a power of 2
    {   int i = intlog2(n1);   // identify what power of 2 we have
        if (i <= LOG2_VECTOR_CHUNK_WORDS)
        {   elt(v, 0) = free_vectors[i];
            free_vectors[i] = v;
        }
    }
}

static void discard_large_vector(LispObject v)
{   Header h = vechdr(v);
    if (type_of_header(h) == TYPE_INDEXVEC)
    {   size_t n1 = length_of_header(h)/CELL - 1;
        for (size_t i=0; i<n1; i++) discard_raw_vector(elt(v, i));
    }
    discard_raw_vector(v);   
}

static inline LispObject getv_large_vector(LispObject v, size_t n)
{
    if (type_of_header(vechdr(v)) == TYPE_INDEXVEC)
        return elt(elt((v), (n)/VECTOR_CHUNK_WORDS), (n)%VECTOR_CHUNK_WORDS);
    else return elt(v, n);
}

static inline void putv_large_vector(LispObject v, size_t n, LispObject val)
{
    if (type_of_header(vechdr(v)) == TYPE_INDEXVEC)
        elt(elt((v), (n)/VECTOR_CHUNK_WORDS), (n)%VECTOR_CHUNK_WORDS) = val;
    else elt(v, n) = val;
}



//
// This is an implementation of hash tables intended to be used when the
// keys in the table are structures of some sort. It might be useful for
// strings or structures representing symbols, or for more general large
// objects. There are two points to the issue of what the hashed items will
// be. The first is that the table will contain references to objects not
// the objects themselves - and this means that checking objects will
// access memory in ways that could involve cache misses. This is a different
// scenario from the one where keys are integers or other immediate data.
// The second issue is that both computing hash values and comparing keys
// may have significant cost, and in particular the costs there may be
// higher than general administration activity on the table itself.
//
// The response I have to the above is to use a variety of Cuckoo hashing
// where each key can be places in one of only three locations. Thus the
// worst-case lookup cost involved 3 probes. I compute a single initial
// 64-bit hash function on a key and derive the three probe positions from
// it: for tables holding up to a couple of million entries those three
// positions could be independent (because in effect they pick out different
// subsets of the full 64-bit value).
// I arrange that if, as I inspect the table, I encounter an empty slot
// that means that the key I was looking for is not present. Thus in some
// cases I can verify that a key is not in the table by computing one hash
// function and inspecting the table but not performing any key comparisons
// at all. Similarly when I insert data into a fairly empty table I will
// (reasonably often) not need key comparison operations, because if
// when I probe in the sequence I would as for a lookup I happen on
// and EMPTY slot I know the key is not present and I have just found where
// I should insert it.
// Note that the decision just described means that deletion must
// insert tombstone values, and if too many of those are present it can
// degrade lookup time (but pretty well at worst to an average of two probes
// for a successful lookup and three for an unsuccessful one). I arrange
// that rehashing always gets rid of tombstones, and garbage collection is
// liable to mark all tables for rehashing, and so this issue will tend to
// be a transient one.
//
// As with any general hash table implementation I occasionally need to
// expand or contract the table and re-hash. For cuckoo hashing I sometimes
// need to alter my hash function parameter and rehash to avoid a cluster
// of hash conflicts. While those two have significant cost they should
// both be uncommon and their amortised cost modest.
//
// I write HASH() for the code that will compute a hash function, and
// COMPARE() for key comparison. COMPARE should never be called with an
// EMPTY or HASHTOMB value, and that may at times allow a minor optimisation
// in its implementation.

//
// The following are the components that make up a hash table...
//

#define HASH_FLAVOUR    0  // EQ, EQL, ... and a rehash counter
#define HASH_COUNT      1  // number of active keys
#define HASH_SHIFT      2  // gives the total table size
#define HASH_KEYS       3  // vector of keys
#define HASH_VALUES     4  // vector of values
#define HASH_MULTIPLIER 5  // a 64-bit multiplier

// My default multiplier is pretty arbitrary, but its value is around
// 2^64*0.6180 and when you truncate to 32-bits you get a value around
// 2^32*0.6180 (the multiplier there is the golden ratio). 
#define HASH_DEFAULT_MULTIPLIER UINT64_C(0x9e3779b99e3779bd)

// While performing operations on a table I will often load its components
// info some of the following static variables. When and if I move to
// a multi-threaded world I will need these to use thread local storage.

static LispObject h_table, v_table;
static int h_flavour, h_shift = 64-18;
static uint64_t h_multiplier = HASH_DEFAULT_MULTIPLIER;

static size_t h_table_size = ((size_t)(1<<(64-h_shift)));
static size_t occupancy = 0;

static inline void update_multiplier()
{
// The constants (28...57) and (30..93) here yield a linear congruential
// generator with full period when used with 64-bit integers. Here I
// use them on 63-bits of the multiplier. I update in such as way that
// my least significant bit remains as a "1". I want that so that
// if I compute a hash value using "h=((multiplier*key)>>shift)" then
// high bits in the key do not get multiplied out from where they can
// influence the result. To see how bad things could be imagine if the
// multipiler somehow ended up as having the value 2^62... then only
// the very bottom bits of the key could contribute to the hash value!
    h_multiplier = UINT64_C(2862933555777941757)*h_multiplier +
                 (2*UINT64_C(3037000493)-UINT64_C(2862933555777941757)+1);
}

static uint64_t hashcount=0, comparecount=0;

typedef uint64_t hash_function_t(LispObject key);
typedef bool hash_compare_t(LispObject key, LispObject hashentry);

static hash_function_t *hash_function;
static hash_compare_t  *hash_compare; 

// The primary hash key is computed in a way that has to depend on the
// hashing regime in use. If hashing is based on the EQ test then it
// can be just (key*multiplier), while for EQUAL and other more elaborate
// cases it will need to descend into the representation of its key.

static inline uint64_t HASH(LispObject key)
{   return (*hash_function)(key);
}

// REHASH generated a second hash value from the initial one. If the initial
// hash was perfect I could use its top few bits from the primary hash and
// then merely use the next few bits for a second probe location. However
// the simple scheme (sometimes) used for the primary hash risks not paying
// enough attention to high bits in the original key. So to get my secondary
// hash I shift data right 32 bits before multiplying by the number that I
// use to scramble things.

static inline uint64_t REHASH(uint64_t h)
{   return ((h ^ (h>>32)) + 0x1234567) * h_multiplier;
}

// The third hash value that I use will be got by multiplying the
// second one by my magic multiplier.

static inline uint64_t REHASH2(uint64_t h)
{   return h*h_multiplier;
}

static inline bool COMPARE(LispObject k1, LispObject k2)
{
// Here neither k1 not k2 will be SPID_HASHEMPTY or SPID_HASHTOMB.
    return (*hash_compare)(k1, k2);
}

static inline LispObject ht(size_t n)
{
    return getv_large_vector(h_table, n);
}

static inline void setht(size_t n, LispObject v)
{
    putv_large_vector(h_table, n, v);
}

static inline LispObject htv(size_t n)
{
    return getv_large_vector(v_table, n);
}

static inline void sethtv(size_t n, LispObject v)
{
    putv_large_vector(v_table, n, v);
}

// dumptable() displays the contants of the hash table (for debugging
// purposes), optionally checking to confirm that it seems to be
// properly configured.

static void set_hash_operations(LispObject tt);

void dumptable(LispObject tt, const char *s, bool checkdups)
{
    size_t i;
    bool bad = false;
    printf("%s\n", s);
    set_hash_operations(tt);
    for (i=0; i<h_table_size; i++)
    {   LispObject k = getv_large_vector(h_table, i);
        uint64_t h = HASH(k);
        size_t h1 = h >> h_shift;
        uint64_t hx = REHASH(h);
        size_t h2 = hx >> h_shift;
        size_t h3 = REHASH2(hx) >> h_shift;
        if (k == SPID_HASHEMPTY) printf("%3" PRIuMAX ": EMPTY\n", (uintmax_t)i);
        else if (k == SPID_HASHTOMB) printf("%3" PRIuMAX ": HASHTOMB\n", (uintmax_t)i);
        else
        {   const char *s1=" ", *s2 = " ", *s3 = " ", *s4 = "";
            uintptr_t vv = getv_large_vector(v_table, i);
            if (h1 == i)
            {   s1 = "=";
                if (h2 != i && ht(h2) == k) { s2 = "?"; bad = true; }
                if (h3 != i && ht(h3) == k) { s3 = "?"; bad = true; }
            }
            if (h2 == i)
            {   s2 = "=";
                if (h1 != i && ht(h1) == k) { s1 = "?"; bad = true; }
                if (h3 != i && ht(h3) == k) { s3 = "?"; bad = true; }
                if (ht(h1) == SPID_HASHEMPTY) s4 = " @@@";
            }
            if (h3 == i)
            {   s3 = "=";
                if (h1 != i && ht(h1) == k) { s1 = "?"; bad = true; }
                if (h2 != i && ht(h2) == k) { s2 = "?"; bad = true; }
                if (ht(h1) == SPID_HASHEMPTY) s4 = " @@@";
                if (ht(h2) == SPID_HASHEMPTY) s4 = " @@@";
            }
            if (h1 != i && h2 != i && h3 != i) s4 = "@@@";
            printf("%3" PRIu64 ": [%" PRIu64 "] %s%" PRIu64 " %s%" PRIu64
                   " %s%" PRIu64 "%s (%" PRIu64 ")\n",
                (uint64_t)i, (uint64_t)k,
                s1, (uint64_t)h1, s2, (uint64_t)h2, s3, (uint64_t)h3, s4,
                (uintmax_t)vv);
        }
    }
    if (bad && checkdups)
    {   printf("Exiting (checkdups=%d)\n", checkdups);
        exit(0);
    }
}

static void corrupted(LispObject tt, int fromline)
{
    printf("Table is corrupted (from line %d)\n", fromline);
    dumptable(tt, "Table is corrupted", true);
    fflush(stdout);
    abort();
}

void checktable(LispObject tt, int fromline)
{
    size_t i;
    for (i=0; i<h_table_size; i++)
    {   LispObject k = ht(i);
        uint64_t h = HASH(k);
        size_t h1 = h >> h_shift;
        uint64_t hx = REHASH(h);
        size_t h2 = hx >> h_shift;
        size_t h3 = REHASH2(hx) >> h_shift;
        if (k != SPID_HASHEMPTY && k != SPID_HASHTOMB)
        {   if (h1 == i)
            {   if (h2 != i && ht(h2) == k) corrupted(tt, fromline);
                if (h3 != i && ht(h3) == k) corrupted(tt, fromline);
            }
            if (h2 == i)
            {   if (h1 != i && ht(h1) == k) corrupted(tt, fromline);
                if (h3 != i && ht(h3) == k) corrupted(tt, fromline);
                if (h1 != i && ht(h1) == SPID_HASHEMPTY)
                    corrupted(tt, fromline);
            }
            if (h3 == i)
            {   if (h1 != i && ht(h1) == k) corrupted(tt, fromline);
                if (h2 != i && ht(h2) == k) corrupted(tt, fromline);
                if (h1 != i && h2 != i &&
                    (ht(h1) == SPID_HASHEMPTY || ht(h2) == SPID_HASHEMPTY))
                    corrupted(tt, fromline);
            }
            if (h1 != i && h2 != i && h3 != i) corrupted(tt, fromline);
        }
    }
}

// The main lookup function. In the worst case this can do three
// key comparisons. But it can be cheaper either on success if it
// finds a match on the first or second comparison, or on failure if
// it encounters an empty hash table slot in its probe sequence.
// Observe how very concise and fast this code is!

size_t hash_lookup(LispObject key)
{
    uint64_t h = HASH(key);
    LispObject v;
    size_t n;
// I probe the table. I will arrange that if I see an empty table slot then
// I can exit at once. The reason for making this extra test is that it
// may be that comparing keys is expensive (for instance it could be
// if they were long strings or complex structures) and this way I can
// report items not present in lightly loaded tables just a little bit
// sooner. A consequence of this is that when I wish to delete an item from
// the table I can not just mark its slot as empty, I will need to leave
// a "tombstone". I do not need to do anything special about tombstones
// during lookup (though the presence of large numbers of them will tend to
// hurt performance a little), but I will need to allow for them in the
// insertion code.
    if ((v = ht(n = (h>>h_shift))) == SPID_HASHEMPTY) return NOT_PRESENT;
    else if (v != SPID_HASHTOMB && COMPARE(v, key)) return n;
// The second hash table is derived from the first by multiplication,
// but before that by mixing in the effect of shifting right be 32 bits.
// This is so that if a collection of keys all differ in just the top
// bits of the 64-bits they involve that those bits get a chance to impact
// on rather more bits of the second and third hash values. The use-case
// that led me to worry about this was if character strings are hashed
// doubleword-by-doubleword (on a big-endian machine) then one character
// strings could all use an initial key of the form 0xNN00000000000000 and
// simple multiplication only ever propagates information leftwards, so
// if first choice hashes collide there is too high a prospect of second
// choice ones doing so too. The same issue could perhaps arise with
// floating point numbers where I can imagine use-cases where many values
// that are hashed differ only in bits at one extreme end of the data.
    h = REHASH(h);
    if ((v = ht(n = (h>>h_shift))) == SPID_HASHEMPTY) return NOT_PRESENT;
    else if (v != SPID_HASHTOMB && COMPARE(v, key)) return n;
// The third choice hash uses merely simple multiplication.
    h = REHASH2(h);
// Even in the worst case a lookup (sucessful or not) never takes more than
// three probes.
    if ((v = ht(n = (h>>h_shift))) == SPID_HASHEMPTY) return NOT_PRESENT;
    else if (v != SPID_HASHTOMB && COMPARE(v, key)) return n;
    else return NOT_PRESENT;
}

// I provide instrumented lookup and insert functions that count the
// number of hash evaluations and key comparisons used.

uint64_t found_n=0, found_h=0, found_c=0;
uint64_t notfound_n=0, notfound_h=0, notfound_c=0;

size_t instrumented_lookup(LispObject key)
{
    size_t r;
    hashcount = comparecount = 0;
    r = hash_lookup(key);
    if (r == NOT_PRESENT)
    {   notfound_n++;
        notfound_h += hashcount;
        notfound_c += comparecount;
    }
    else
    {   found_n++;
        found_h += hashcount;
        found_c += comparecount;
    }
    return r;
}

// Deleting things from the table is really rather easy, apart from the
// fact that I should shrink the table it it has become too empty. However
// note that performing many deletions can leave the table cluttered with
// HASHTOMB values and that can prevent the lookup code being able to exit
// early when a key is not present and it encouters an EMPTY slot.

// I need to track table occupancy and shrink the table if it becomes
// too empty. I have not implemented this yet and I will not want to be
// to quick to shrink things.

bool hash_remove(LispObject key)
{
    size_t n = hash_lookup(key);
    if (n == NOT_PRESENT) return false; // Item had not been present.
    setht(n, SPID_HASHTOMB);
    occupancy--;
    if (occupancy < h_table_size/5)
    {   //shrink_table();
    }
    return true;             // Item had been present. Now removed.
}


// When I insert an item I will always insert in one of the first two choice
// locations. If neither of them is empty I will need to move away a value
// presently stored, and it is these relocations that can move keys into
// their third-choice place.
// This scheme makes insertion just slightly more expensive but should tend
// to keep more items in first or second choice locations and so slightly
// speed up (successful) lookup.
//
// When I need to relocate items I will use a breadth-first search. this
// will use a queue that holds the locations where items could be stored.
//
// This queue can start off with two entries for the two locations that
// the key to be inserted might be placed:
//  2:  h1(k)
//  3:  h2(k)
// [remember I am not going to insert the new item in h3(k), its third choice
// location]. If h1(k)==h2(k) then I put a NOT_PRESENT in entry 2 rather
// then this duplicated value. That is to avoid wasteful repeated searches.
// When processing the queue let h=q[n] be the entry recovered. Then let
// k=table[h] - the item in the hash table that would need to be relocated
// to free up that location. So I evaluate h1(k), h2(k) and h3(k). At least
// one of these values must be h (because the key k was found at location h)
// so discard that value. Also discard duplicates. You are left with 0, 1 or
// hwo values. Pad that up to two values using NOT_PRESENT to fill in gaps
// and store what you have at locations 2n and 2n+1.
//
// Well the above is explained from a perspective of pre-actively searching
// alead. What I will actually do is to wait until I need an item from
// queue position 2n and use that to trigger the processing of the item at
// position n. I put my initial two seeds at queue locations 2 and 3 because
// that leads to the simple arithmetic where the two offspring of entry n
// are entries 2n and 2n+1.
//
// As I scan the table if I find table[q[n]]==SPID_HASHEMPTY or SPID_HASHTOMB then I have
// found a way to complete the insertion, and the data left in the queue
// is sufficient to let me perform the necessary rearrangement. This
// need to go
//      table[q[n]] = table[q[n/2]]
//      n = n/2
// to move the previously considered key to its new location. This step
// is repeated until n < 4. Because then n should be either 2 or 3 and
//      table[q[n]] = key_being_inserted;
// can put the original key in a good place. Well I will not actually put the
// new key in within this code - I will just return information about where it
// should go. That (slightly) gains flexibility I think.
//
// If while performing this search the queue is about to overflow it is
// necessary to report failure. When that happens no changes have been made
// to the table, and the item being inserted has not been inserted.
// The hashing scheme used here where each item has three potential homes
// has the property that for hash table occupancies up to around 90% there is
// a high probability that sufficiently exhaustive search will find a way to
// fit keys in the table, while for occupancies over that threshold it
// rapidly becomes very unlikely that insertion can succeed. If I set the
// maximum size of my search queue to modest values failure to insert will
// happen sooner. Depending on the precise interaction between the set of
// kets used and the hash function adopted it is possible for there to be
// an insert failure for even a very lightly loaded table.

// QSIZE is the size of the queue used in the breadth-first search. Higher
// values make a few insert operations more expensive but lead to better
// ability to fit keys in. For most key inserts (even as you get towards
// the highest table occupancy I support) the amount of queue used will be
// trivial.

#define QSIZE 100

size_t hash_insert_if_possible(LispObject key)
{
    size_t Qn;
    size_t Q[QSIZE];
    uint64_t h = HASH(key);
    LispObject v1, v2, v3;
    size_t n, n1, n2, n3;
#ifdef TRACE
    uint64_t hx = REHASH(h);
    printf("Insert %" PRIx64 " %d %d %d\n",
        key,
        (int)(h >> h_shift),
        (int)(hx >> h_shift),
        (int)(REHASH2(hx) >> h_shift));
#endif
// I have what seems a rather long-winded prelude to the general insert code.
// If the key presented hashed to h1, h2 and h3 then I first check if h1 is
// empty (if so the key is not present). Then I check if h1 contains the
// key already. Next I check h2 and h3 similarly. If none of these
// tests resolve the matter I check whether there are tombstones at h1 or h2
// and I can insert into the first space shown available that way.
// If this does not resolve matters then I know that the key I am inserting
// is not already present in the table, and so I will never need any more
// key comparisons. But I do have to perform a breadth-first search to seek
// a way to rearrange data to fit the new key in. This can fail, in which
// case I will return -1 leaving the table unchanged.
    if ((v1 = ht(n1 = (h>>h_shift))) == SPID_HASHEMPTY)   // Gap found.
        return n1;   // Can put in first choice location
    if (v1 != SPID_HASHTOMB && COMPARE(v1, key)) return n1; // Already present
    h = REHASH(h);
    if ((v2 = ht(n2 = (h>>h_shift))) == SPID_HASHEMPTY)
        return n2;   // Can put in second choice location
    if (v2 != SPID_HASHTOMB && COMPARE(v2, key)) return n2; // Already present
    h = REHASH2(h);
    v3 = ht(n3 = (h>>h_shift));
    if (v3 != SPID_HASHEMPTY && v3 != SPID_HASHTOMB && COMPARE(v3, key))
         return n3; // Already present
// Here I have checked all three possible locations and the key is not
// already present.
    occupancy++;
// If in the investigation to date I have seen a HASHTOMB I may re-use that
// entry.
    if (v1 == SPID_HASHTOMB) return n1;
    if (v2 == SPID_HASHTOMB) return n2;
// Now I have checked the first three locations. I hope that a significant
// proportion of cases will not get any further! But for when it does I
// will move on to a breadth-first search of ways to rearrange items currently
// in the table to make everything fit. At this stage since I KNOW that the
// item I am inserting is not in the table already I do not need to do any
// comparisons against key values - all I need to do is to watch out for
// EMPTY or HASHTOMB values in the table.
    Q[2] = n1;
    Q[3] = (n1==n2) ? NOT_PRESENT : n2;
    Qn = 4;
    for (;;)
    {   LispObject newkey;
// If insertion fails I will not have changed the table at all.
        if (Qn > QSIZE-2) return NOT_PRESENT; // Nothing left in queue. Failed.
        n = Q[Qn/2];                // A currently occupied location.
// The queue may have some entries in it that are "not present" and those are
// to be ignored in the search.
        if (n == NOT_PRESENT)
        {   Q[Qn++] = n;
            Q[Qn++] = n;
            continue;
        }
        newkey = ht(n);          // The key stored there.
        h = HASH(newkey);
#ifdef TRACE
        printf("Consider moving %d [%" PRIx64 "] to %d %d %d\n",
           n, (uint64_t)newkey,
           (int)(h>>h_shift),
           (int)(REHASH(h)>>h_shift),
           (int)((REHASH2(REHASH(h)))>>h_shift));
#endif
        if ((v1 = ht(n1 = (h>>h_shift))) == SPID_HASHEMPTY ||
            v1 == SPID_HASHTOMB)  // Success - have found a gap!
        {   setht(n1, newkey);
            sethtv(n1, htv(n));
#ifdef TRACE
            printf("Put in %d\n", n1);
#endif
            break;
        }
        h = REHASH(h);
        if ((v2 = ht(n2 = (h>>h_shift))) == SPID_HASHEMPTY ||
            v2 == SPID_HASHTOMB)
        {   setht(n2, newkey);
            sethtv(n2, htv(n));
#ifdef TRACE
            printf("Put in %d\n", n2);
#endif
            break;
        }
        h = REHASH2(h);
        if ((v3 = ht(n3 = (h>>h_shift))) == SPID_HASHEMPTY ||
            v3 == SPID_HASHTOMB)
        {   setht(n3, newkey);
            sethtv(n3, htv(n));
#ifdef TRACE
            printf("Put in %d\n", n3);
#endif
            break;
        }
// Now I have three probe locations n1, n2 and n3. One will be the same as
// n, and I want to discard that and then also discard any duplicates. This
// feels like a rather messy sequence of tests!
        if (n1 == n)
        {   n1 = n3;    // Now I have (n1,n2) to look at
            if (n1 == n) n1 = NOT_PRESENT;
            if (n2 == n || n2 == n1) n2 = NOT_PRESENT;
        }
        else
        {   if (n2 == n || n2 == n1) n2 = NOT_PRESENT;
            if (n3 == n || n3 == n1 || n3 == n2) n3 = NOT_PRESENT;
            if (n2 == NOT_PRESENT) n2 = n3;
        }
        Q[Qn++] = n1;
        Q[Qn++] = n2;
    }
#ifdef TRACE
    printf("Have found a gap and moved something to it (%" PRIx64 ")\n",
           (uint64_t)key);
    printf("before unwind Qn=%d\n", Qn);
    dumptable(tt, "Before", false);
    {   size_t j;
        for (j=0; j<Qn; j++) printf("%d: %d\n", j, Q[j]);
    }
#endif
// I have now just moved a key into a gap. I will make a chain of moves so
// as to leave a place available where the key I wish to insert can go.
    Qn = Qn/2;
    while (Qn > 3)
    {  size_t j = Qn/2;   // parent
#ifdef TRACE
       printf("move %" PRIx64 " from %d to %d\n", ht(Q[j]), Q[j], Q[Qout]);
#endif
       setht(Q[Qn], ht(Q[j]));
       sethtv(Q[Qn], htv(Q[j]));
       Qn = j;
    }
#ifdef TRACE
    dumptable("After", true);
#endif
// I return the table offset where I can put the new key. If the given key
// had already been present in the table this will contain data. So if
// the key was new I will empty the slot so that the caller can tell that
// this is the situation. So note that this insert function does not
// guarantee to succeed! It can return NOT_PRESENT to report that the table
// did not have space for the new key, and in that case nothing has been
// changed. In such cases rehashing may be required. And if it does return
// a table offset H it will usually be essential to go setht(H,...) and
// sethtv(H,...) promptly to put the data in there. If you do NOT put proper
// data there promptly the table could be left in an invalid state.
    setht(Q[Qn], SPID_HASHEMPTY);
    return Q[Qn];
}

// Instrumented variant.

uint64_t already_n=0, already_h=0, already_c=0;
uint64_t inserted_n=0, inserted_h=0, inserted_c=0;

size_t instrumented_insert_if_possible(LispObject key)
{
    size_t r;
    hashcount = comparecount = 0;
    r = hash_insert_if_possible(key);
    if (r == NOT_PRESENT) return r;
    else if (ht(r) != SPID_HASHEMPTY && ht(r) != SPID_HASHTOMB)
    {   already_n++;
        already_h += hashcount;
        already_c += comparecount;
        return r;
    }
    else
    {   setht(r, key);
        inserted_n++;
        inserted_h += hashcount;
        inserted_c += comparecount;
        return r;
    }
}


static void newhash_rehash(LispObject tab, bool after_gc)
{ 
// The next line sets h_shift, h_table_size, h_table, v_table and h_multiplier
    set_hash_operations(tab);
    size_t old_table_size = h_table_size;
    int flavour = int_of_fixnum(elt(tab, HASH_FLAVOUR));
    size_t count = int_of_fixnum(elt(tab, HASH_COUNT));
#ifdef DEBUG
    printf("call rehash with after_gc = %s, "
           "size=%" PRId64 " and occupancy %.3f%%\n",
           (after_gc ? "true" : "false"), (int64_t)h_table_size,
           (100.0*count)/(double)h_table_size);
#endif
    int rehash_count = (flavour >> 8) & 0xff;
    LispObject keyvec = h_table;  // The original data...
    LispObject valvec = v_table;
//  checktable(tab, __LINE__);
    h_table = v_table = nil;
    for (;;)
    {
// Now I apply a rather guessed and made-up rule about when to increase the
// size of a table. The rule as coded here is:
//    If I am rehashing because a GC just happened I will not double
//        size and will not increment the rehash count (on my first try);
//    If the table is over 80% full then double its size;
//    If it is over 66% full and has needed more than 3 rehashes to date then
//        double its size;
//    If it is less full than that but has needed more than 6 rehashes then
//        double its size.
        if (!after_gc) update_multiplier();
        if (after_gc) after_gc = false;
        else if (count >= 4*(h_table_size/5) ||
            (count >= 2*(h_table_size/3) && rehash_count > 3) ||
            rehash_count > 6)
        {   h_shift--;
            h_table = v_table = nil;
            rehash_count = 0;
        }
        else rehash_count++;
        h_table_size = ((size_t)1) << (64-h_shift);
        if (h_table == nil)
        {   push(tab);
            h_table = get_large_vector(h_table_size, SPID_HASHEMPTY);
            push(h_table);
            v_table = get_large_vector(h_table_size, SPID_HASHEMPTY);
            pop2(h_table, tab);
            keyvec = elt(tab, HASH_KEYS);
            valvec = elt(tab, HASH_VALUES);
        }
// I now have a fresh table in h_table, v_table etc, while the old
// information is in keyvec and valvec.
        size_t i;
// Clean out the new table...
        for (i=0; i<h_table_size; i++)
        {   setht(i, SPID_HASHEMPTY);
            sethtv(i, SPID_HASHEMPTY);
        }
//      checktable(tab, __LINE__);
// Now try inserting everything that was in the old one...
        for (i=0; i<old_table_size; i++)
        {   LispObject k = getv_large_vector(keyvec, i);
            if (k == SPID_HASHEMPTY || k == SPID_HASHTOMB) continue;
            size_t n = hash_insert_if_possible(k);
            if (n == NOT_PRESENT) break; // failed!
            setht(n, k);
            sethtv(n, getv_large_vector(valvec, i));
//          checktable(tab, __LINE__);
        }
        if (i>=old_table_size) break; // Managed to insert everything
        // Here I failed and must try again.
    }
// I must move the new information back into the original table.
    push2(h_table, v_table);
    LispObject w = make_lisp_unsigned64(h_multiplier);
    pop2(v_table, h_table);
// At this stage keyvec and valvec are no longer needed and so I can
// recycle them.
    discard_large_vector(elt(tab, HASH_KEYS));
    discard_large_vector(elt(tab, HASH_VALUES));
    elt(tab, HASH_MULTIPLIER) = w;
    elt(tab, HASH_SHIFT) = fixnum_of_int(h_shift);
    elt(tab, HASH_KEYS) = h_table;
    elt(tab, HASH_VALUES) = v_table;
    elt(tab, HASH_FLAVOUR) =
        fixnum_of_int((flavour & 0xff) | (rehash_count<<8));
//  checktable(tab, __LINE__);
}

/////////////////////////////////////////////////////////////////////

// This is simplified printing and sends its output to stderr. It is ONLY
// intended for use while debugging. I will use if when printing trace
// and backtrace output.. that gives up on having flexible control over
// diagnostic output or redirecting it to somewhere other than stderr
// (in non-windowed mode) or the screen (in windowed mode).
// I want it to be able to cope with looped up structures so I will use
// and EQ-keyed hash table to detect places where the structure is
// reentrant.
// I will also implement a scheme that lets me limit the output from each
// printed expression to a certain number of lines of output...

static int simple_column = 0;

void simple_lineend(int n)
{   if (simple_column + n > 70)
    {   fprintf(stderr, "\n");
        simple_column = n;
    }
    else simple_column += n;
}

void simple_print1(LispObject x)
{   char buffer[40];
    if (x == nil)
    {   simple_lineend(3);
        fprintf(stderr, "nil");
        return;
    }
    if (x == 0)
    {   simple_lineend(3);
        fprintf(stderr, "@0@");
        return;
    }
    if (is_cons(x))
    {   const char *sep = "(";
        while (consp(x))
        {   simple_lineend(1);
            fprintf(stderr, "%s", sep);
            sep = " ";
            simple_print1(qcar(x));
            x = qcdr(x);
        }
        if (x != nil)
        {   simple_lineend(3);
            fprintf(stderr, " . ");
            simple_print1(x);
        }
        simple_lineend(3);
        fprintf(stderr, ")");
        return;
    }
    else if (is_fixnum(x))
    {   int k = sprintf(buffer, "%" PRId64, (int64_t)int_of_fixnum(x));
        simple_lineend(k);
        fprintf(stderr, "%s", buffer);
        return;
    }
    else if (is_symbol(x))
    {   size_t len;
        x = qpname(x);
        len = length_of_byteheader(vechdr(x)) - CELL;
        simple_lineend(len);
        fprintf(stderr, "%.*s", (int)len, &celt(x, 0));
    }
    else if (is_vector(x))
    {   size_t i, len;
        if (is_string(x))
        {   len = length_of_byteheader(vechdr(x)) - CELL;
            simple_lineend(len+2);
            fprintf(stderr, "\"%.*s\"", (int)len, &celt(x, 0));
            return;
        }
        else if (vector_holds_binary(vechdr(x)) &&
                 vector_i8(vechdr(x)))
        {   len = length_of_byteheader(vechdr(x)) - CELL;
            fprintf(stderr, "<Header is %" PRIxPTR ">", vechdr(x));
            simple_lineend(2*len+3);
            fprintf(stderr, "#8[");
            for (size_t i=0; i<len; i++)
            {   simple_lineend(2);
                fprintf(stderr, "%.2x", celt(x, i) & 0xff);
            }
            fprintf(stderr, "]");
            return;
        }
        len = (int64_t)(length_of_header(vechdr(x))/CELL - 1);
        int nn = sprintf(buffer, "[%" PRId64 ":", (int64_t)len);
        simple_lineend(nn);
        fprintf(stderr, "%s", buffer);
        for (i=0; i<len; i++)
        {   simple_lineend(1);
            fprintf(stderr, " ");
            if (i > 2 && is_mixed_header(vechdr(x)))
            {   nn = sprintf(buffer, "%" PRIx64, (uint64_t)elt(x, i));
                simple_lineend(nn);
                fprintf(stderr, "%s", buffer);
            }
            else simple_print1(elt(x, i));
        }
        simple_lineend(1);
        fprintf(stderr, "]");
        return;
    }
    else if (is_numbers(x) && is_bignum(x))
    {   size_t len = (length_of_header(numhdr(x))-CELL)/4;
        size_t i;
        int clen;
        for (i=len; i>0; i--)
        {   int32_t d = bignum_digits(x)[i-1];
// I will print bignums in a manner that shows the 31-bit digits that they
// are made up from.
            if (i == len) clen = sprintf(buffer, "@#%d", d);
            else clen = sprintf(buffer, ":%u", d);
            simple_lineend(clen);
            fprintf(stderr, "%s", buffer);
        }
        return;
    }
    else
    {   char buffer[32];
// This default case includes bignums, and I am not keen on needing
// to render them here! But it certainly looks ugly when they get
// displayed as @xxxxx@ with the xxxxx being a bunch of hex digits giving
// the memory address the data lies at!
        int clen = sprintf(buffer, "@%" PRIx64 "@", (int64_t)x);
        simple_lineend(clen);
        fprintf(stderr, "%s", buffer);
        return;
    }
}

void simple_print(LispObject x)
{   simple_column = 0;
    simple_print1(x);
}

void simple_msg(const char *s, LispObject x)
{   fprintf(stderr, "%s", s);
    simple_print(x);
    fprintf(stderr, "\n");
}

// A version of Lmkhash with just 2 arguments so you to not supply the
// (unused and hence irrelevant) third argument.

extern LispObject Lmknewhash(LispObject env, int nargs, ...);

LispObject Lmknewhash2(LispObject env, LispObject a, LispObject b)
{   return Lmknewhash(nil, 3, a, b, nil);
}

LispObject Lmknewhash(LispObject env, int nargs, ...)
//
// (mkhash size flavour growth)
//
// size suggests how many items can be inserted before re-hashing
// occurs. flavour is 0, 1, 2, 3 or 4 corresponding to hash tables
// that use EQ, EQL, EQUAL, EQUALS or EQUALP.  growth is a floating point
// value suggesting how much to grow by when rehashing is needed. In
// this implementation the table size will be doubled when it needs
// to grow, and so the "growth" argument will be ignored!
//
// If flavour is not a number it might be a dotted pair (hashfn . eqfn)
// where hashfn is a user-provided function to compute hash values (which
// will actually be permitted to be anything at all, since I will then
// hash the output again as if hashing under EQL - but I expect that really
// I expect numeric hash values), and eqfn is a function used to compare
// items. [this facility may not be implemented at first]
//
{   va_list a;
    int32_t shift, size1, size2;
    LispObject v, v1, v2, size, flavour;
    argcheck(nargs, 3, "mkhash");
    va_start(a, nargs);
    size = va_arg(a, LispObject);
    flavour = va_arg(a, LispObject);
    va_end(a);
// I allow fixnums or bignums as size spacifiers.
    if (is_fixnum(size)) size1 = int_of_fixnum(size);
    else if (is_numbers(size) && is_bignum(size)) size1 = 1000000;
    else aerror1("mkhash", size);
// I treat clip the size range to [4 .. 1000000]. Table that end up larger
// can grow on need.
    if (size1 > 1000000) size = 1000000;
    else if (size1 < 4) size1 = 4;
    if (!is_fixnum(flavour) && !consp(flavour))
        aerror1("mkhash", flavour);
// I will make the initial size a power of 2 such that wiith "size"
// entries present the table will be about between 30% and 60% full.
    size1 = 5*((size1+1)/3);
// The smallest hash table I will ever create will have 8 slots in the
// table. The space saving for anything smaller will be rather modest,
// especially given that there is a hash table header record. You will
// only get this tiny table if you indicate an target size of 4 or less.
    size2 = 8;
    shift = 64-3;
    while (size2 < size1)
    {   size2 *= 2;
        shift--;
    }
    v1 = get_large_vector(size2, SPID_HASHEMPTY);
    push(v1);
    v2 = get_large_vector(size2, nil);
    push(v2);
    v = getvector_init(7*CELL, nil);
    pop2(v2, v1);
    elt(v, HASH_FLAVOUR) = flavour;         // comparison method1;5n
    elt(v, HASH_COUNT) = fixnum_of_int(0);  // current number of items stored.
    elt(v, HASH_SHIFT) = fixnum_of_int(shift);  // 64-log2(table size)
    elt(v, HASH_KEYS) = v1;                 // key table.
    elt(v, HASH_VALUES) = v2;               // value table.
    elt(v, HASH_MULTIPLIER) = nil;          // current multiplier
// If the "multiplier" is stored as NIL then a default value will be used.
// Otherwise there will be a 64-bit integer stored in this location, and
// extracting it for use will be an unwelcome extra cost.
    vechdr(v) ^= (TYPE_SIMPLE_VEC ^ TYPE_NEWHASH);
    return onevalue(v);
}

static uint64_t newhash_eq(LispObject key);
static uint64_t newhash_eql(LispObject key);
static uint64_t newhash_cl_equal(LispObject key);
static uint64_t newhash_equal(LispObject key);
static uint64_t newhash_equalp(LispObject key);
static uint64_t newhash_binary_vector(LispObject key);

static bool newhash_compare_eq(LispObject key, LispObject hashentry);
static bool newhash_compare_eql(LispObject key, LispObject hashentry);
static bool newhash_compare_cl_equal(LispObject key, LispObject hashentry);
static bool newhash_compare_equal(LispObject key, LispObject hashentry);
static bool newhash_compare_equalp(LispObject key, LispObject hashentry);
static bool newhash_compare_symtab(LispObject key, LispObject hashentry);

// The "flavour" field in a hash table will be a fixnum. It will have its
// bottom 8 bits (that is amazingly more than I need!) to say what hash
// regime will be in use. The next 8 bits are used to track whether the
// table has needed to change its hash function and re-hash recently.

static void set_hash_operations(LispObject tab)
{
    switch ((h_flavour = int_of_fixnum(elt(tab, HASH_FLAVOUR))) & 0xff)
    {
    default:
    case 0:
        hash_function = newhash_eq;
        hash_compare = newhash_compare_eq;
        break;
    case 1:
        hash_function = newhash_eql;
        hash_compare = newhash_compare_eql;
        break;
    case 2:
        hash_function = newhash_cl_equal;
        hash_compare = newhash_compare_cl_equal;
        break;
    case 3:
        hash_function = newhash_equal;
        hash_compare = newhash_compare_equal;
        break;
    case 4:
        hash_function = newhash_equalp;
        hash_compare = newhash_compare_equalp;
        break;
    case 5:
        hash_function = newhash_binary_vector;
        hash_compare = newhash_compare_symtab;
        break;
    }
    h_shift = int_of_fixnum(elt(tab, HASH_SHIFT));
    h_table_size = ((size_t)(1<<(64-h_shift)));
    h_table = elt(tab, HASH_KEYS);
    v_table = elt(tab, HASH_VALUES);
    if (elt(tab, HASH_MULTIPLIER) == nil)
        h_multiplier = HASH_DEFAULT_MULTIPLIER;
    else h_multiplier = (uint64_t)sixty_four_bits(elt(tab, HASH_MULTIPLIER));
}

// Hashing under EQ is the easiest case, since I will just use the bitwise
// representation of the object as basis for its hash value.

static uint64_t newhash_eq(LispObject key)
{
    return h_multiplier*(uint64_t)key;
}

// For the symbol table I will pass a string to the hashing code, but
// what will end up in the table will be a symbol.
// I obviously need to write a short essay here to cheer up everybody who
// is a big fan of the strict aliasing rules. The string-shaped key that
// is being hashed here will (probably!) have had data written into it
// one character at a time. Information is read and processed here in
// uintptr_t sized chunks. Well regardless of aliasing issues this leads
// to undefined behaviour. Under an old-style traditional "Spirit of C"
// understanding it makes good sense and what you get if a sequence of
// char units assembled either right to left or left to right depending on
// whether you are on a big-endian or little-endian machine. But it seems
// probable that if your C compiler did a sufficiently agressive global
// investigation of your code and managed to spot some symbol that got
// created and possibly used rather a lot but which was never printed
// then it could observe that the print-name was never inspected other than
// (sort of) by the code here. But the code here reads words, and strict
// aliasing rules perhaps say that this can not possibly be reading anything
// that was written in as bytes. [Well I still have trouble with the
// assymetry of the strict aliasing rules there...]. Thus perhaps a
// sufficiently clever compiler could discard the byte-writes that filled in
// the contents of the string. This would still leave this code behaving
// in an undefined manner (no change there really?) but it would be reading
// uninitialised memory. If one had several such symbols it would now
// become undefined as to whether they would hash together and be captured
// as a single or as separate symbols. This could have an impact on global
// behaviour.
//
// I find it hard to believe that this will actually hurt, since at present
// the levels of cross-procedure global optimisation needed to make things
// fail seems extreme. Perhaps a smaller bad case would be
//      make string structure
//      copy characters into string
//      call hash_symtab on this string
// where a very enthusiastic compiler could perhaps permute the order of
// the copying and the hashing. Well in this code the hash function is called
// indirectly via a pointer and that makes it even harder for a compiler
// to tell that it may be permitted to do such things. Anyway the code
// here leads to UNDEFINED behaviour because it access a row of characters as
// a sequence of integers. Since it is computing a hash function I am not at
// all worried by the byte-order uncertainty and results are fully entitled
// to vary from machine to machine based on word-width as well as byte order.

// This function is generically suitable for hashing any sort of Lisp vector
// that contains binary data. It requires that the data is padded up to
// a number of uintptr_t cells, which should be reasonable. On a 32-bit
// machine it works 32 bits at a time, on a 64-bit one it works 64 bits
// at a time. The header word of the vector is involved in the hash
// calculation and that means that vectors of different types are distinguished
// and the leading or trailing zeros in the raw data will not cause any
// confusion. I can not use if for numbers because it used "vechdr" rather
// then flthdr or numhdr to access the header word. I need to worry a bit
// about its use for strings and bit-vectors because I will need to arrange
// that non-simple strings and non-simple bit-vectors end up delivering the
// same hash values as this version that has been optimised for use in the
// simple case.

static uint64_t newhash_binary_vector(LispObject key)
{   uint64_t r;
    size_t n;
    uintptr_t *p;
// Find number of bytes in use, and start the hash code off with the
// header word (which involves the length).
    r = (uint64_t)vechdr(key);
    n = length_of_byteheader(vechdr(key));
    p = (uintptr_t *)&celt(key, 0);
// Hash the string 32 or 64-bits at a time depending on word-length.
    while (n >= sizeof(uintptr_t))
    {   r = h_multiplier*r + *p++;
        n -= sizeof(uintptr_t);
    }
// Any part-filled word at the end MUST be zero-padded.
    if (n != 0) r = h_multiplier*r + *p;
    return r;
}
    
static uint64_t newhash_eql(LispObject key)
//
// Must return same code for two eql numbers. This regime views
// numbers as equal if they have the same type aned the same value, so
// apatr from an ugly dispatch to cope with all the different sorts of
// number this is not too bad. Well it is NASTY because Common Lisp would
// insist that (eql +0.0 -0.0) => nil, and only (= +0.0 -0.0) or
// (equal +0.0 -0.0) should give t. Standard Lisp will view this as
// silly and will want eql to treat positive and negative zeros as the
// same.
//
{   uint64_t r;
    if (is_bfloat(key))
    {   Header h = flthdr(key);
        r = h_multiplier*(uint64_t)h;
        switch (type_of_header(h))
        {   case TYPE_SINGLE_FLOAT:
// There is a nasty here. I want +0.0f and -0.0f to hash to the same
// value becase the two values will compare as equal.
                if (single_float_val(key) == 0.0) return r*h_multiplier;
                else return (r+intfloat32_t_val(key))*h_multiplier;
                break;
            default:
            case TYPE_DOUBLE_FLOAT:
                if (double_float_val(key) == 0.0) return r*h_multiplier;
                else return (r+intfloat64_t_val(key))*h_multiplier;
            case TYPE_LONG_FLOAT:
// Here I will leave +0.0 and -0.0 hashing differently! That is just
// laziness and needs fixing.
                r = (r + intfloat128_t_val0(key))*h_multiplier;
                return (r + intfloat128_t_val1(key))*h_multiplier;
        }
    }
    else if (is_numbers(key))
    {   Header h = numhdr(key);
        size_t n;
        r = h_multiplier*(uint64_t)h;
        switch (type_of_header(h))
        {   case TYPE_BIGNUM:
                n = length_of_header(h);
                n = (n-CELL-4)/4;  // last index into the data
                for (;;)
                {   r = (r + (uint64_t)bignum_digits(key)[n])*h_multiplier;
                    if (n == 0) break;
                    n--;
                }
                return r;
            case TYPE_RATNUM:
            case TYPE_COMPLEX_NUM:
                r = (r + newhash_eql(numerator(key)))*h_multiplier;
                return (r + newhash_eql(denominator(key)))*h_multiplier;
            default:
                return (r + key)*h_multiplier;  // unknown type of number?
        }
    }
// For non-numbers I hash as for EQ.
    else return h_multiplier*(uint64_t)key;
}

// There are a range of EQUAL-like functions used for hashing.
// CL_EQUAL
//   Traverses lists and inspects the contents of strings and bit-vectors,
//   but does not in general descend through vectors. There are supposed to
//   be special cases for non-simple arrays (especially including non-simple
//   strings and bitvectors) and structures that are "path-names". Common
//   Lisp also demands that +0.0 and -0.0 be reported as different. I will
//   not implement all these refinements on the YAGNI (You Ain'y Gonna Need It)
//   principle.
// EQUAL
//   The Standard Lisp understanding where vectors are descended through.
// EQUALP
//   A further Common Lisp oddity, where notably strings are compared in a
//   case insensitive manner! This is also expected to allow you to compute
//   hash values for hash tables based on their content, and that seems a
//   messy thing to support.
//   I should view numbers of different types but similar values (eg 1 and
//   1.0) as EQUALP. This issue is rather horrid. So for instance
//   1152921504606846976 is a bignum  and has the value 2^60. Then since
//   1152921504606846976.0 happens to be exactly a power of 2 its
//   representation in floating point is exact, and it has therefore to hash
//   to the same code as the integer version. This sort of thing has to
//   happen for values up to the largest floating point value. In Common Lisp
//   there are also rational values, and it looks probable that hashing the
//   result of the calculation 1.0/3.0 must yield the same value as that for
//   the rational number 6004799503160661/18014398509481984.
//   So hashing here may be unexpectedly expensive, and it can certainly
//   risk memory allocation and hence garbage collection. Oh dear. Perhaps I
//   need a special variation on multiple-precision arithmetic just for use
//   when converting floating point numbers so that garbage collection can be
//   avoided. It I allow for long floats with a 16-bit exponent I believe
//   that will mean dealing with integers of up to almost 10000 decimal
//   digits, or around 1000 31-bit units.
//
// Well such a lot of the Common Lisp specification seems utterly over the
// top to me that I am not goiing to implement it! The result will be that
// my code will be shorter, simpler and faster, and I find it hard to
// believe that SANE code can rely on the special-case pedantry mentioned
// above. If somebody gets VERY keen at a later stage they can degrade the code
// to. I observe that "clisp" (by Haible, Stoll, Steingold and others) does
// make their EQUALP function do some of these ridiculous things... so perhaps
// I ought to even though I view it as majorly silly.

//
// I will have one generic function with an extra argument that is used to
// control its behaviour in the cases where these three regimes differ in
// behaviour.


#define HASH_AS_CL_EQUAL  0
#define HASH_AS_EQUAL     1
#define HASH_AS_EQUALP    2

static uint64_t newhash_generic_equal(LispObject key, int mode);

static uint64_t newhash_cl_equal(LispObject key)
{   return newhash_generic_equal(key, HASH_AS_CL_EQUAL);
}

static uint64_t newhash_equal(LispObject key)
{   return newhash_generic_equal(key, HASH_AS_EQUAL);
}

static uint64_t newhash_equalp(LispObject key)
{   return newhash_generic_equal(key, HASH_AS_EQUALP);
}

static uint64_t newhash_nonsimple_string(LispObject key)
{
    printf("\nNon-simple-string\n");
    return 0;
}

static uint64_t newhash_nonsimple_bitvector(LispObject key)
{
    printf("\nNon-simple-bitvector\n");
    return 0;
}

// This function has not yet been fully implemented but is intended to let
// me support EQUALP. If the input is a number that can be converted to
// a float WITH NO LOSS OF ACCURACY then set bigfloat_result to the
// converted value and return true. Otherwise return false.
// Anything that is a float already can be converted. short, single and
// double floats need widening. Integers can be converted if the value has
// new enough leading bits nonzero and if the value will lead to no exponent
// overflow. Ratios are OK if the numerator has limited nonzero leading bits
// and if the denominator is a power of 2 so that there is no underflow.
// Sub-normal numbers represent a special edge case for this.

static float128_t bigfloat_result;

static bool float_if_exact(LispObject x)
{   if (is_fixnum(x))
    {   i32_to_f128M(int_of_fixnum(x), &bigfloat_result);
        return true;
    }
    else if (is_numbers(x))
    {   if (is_bignum(x)) return false;       // @@@ More work
        else if (is_ratio(x)) return false;   // @@@ More work
// Do I need to spot the case of a complex number with zero complex
// component?
        else if (is_complex(x)) return false; // @@@@ More work
        else return false;
    }
    else if (is_bfloat(x))
    {   switch (type_of_header(flthdr(x)))
        {
        case TYPE_SINGLE_FLOAT:
            f32_to_f128M(float32_t_val(x), &bigfloat_result);
            return true;
        case TYPE_DOUBLE_FLOAT:
            f64_to_f128M(float64_t_val(x), &bigfloat_result);
            return true;
        case TYPE_LONG_FLOAT:
            bigfloat_result = long_float_val(x);
            return true;
        default:
            return false;
        }
    }
    else if (is_sfloat(x)) return false;      // @@@ More work
    else return false;
}

static uint64_t newhash_generic_equal(LispObject key, int mode)
{   size_t len;
    unsigned char *data;
    Header h;
    uint64_t r = 0;
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   err_printf("Stack too deep in hash calculation\n");
        my_exit(EXIT_FAILURE);
    }
#endif
// I will iterate along any chain of CONS cells, and put a sort of virtual
// header word on the front of each cell to keep the calculation robust.
    while (is_cons(key) && key != nil)
    {   r = (r + (VIRTUAL_TYPE_CONS | TAG_HDR_IMMED))*h_multiplier;
        r = (r + newhash_generic_equal(qcar(key), mode))*h_multiplier;
        key = qcdr(key);
    }
    switch (TAG_BITS & (int32_t)key)
    {   case TAG_CONS:      // Arises because NIL is tagged as a CONS for CL!
        case TAG_SYMBOL:
            return (r + (uint64_t)key)*h_multiplier;
        case TAG_VECTOR:
            {   h = vechdr(key);
//
// I need to treat strings and bitvectors here specially since in those
// cases (and for pathnames, if they existed as a separate data type here!)
// I must inspect the vector contents, while in other cases I must not.
//
                if (is_string_header(h))
                {   switch (mode)
                    {   case HASH_AS_CL_EQUAL:
                            // drop through. Note that for non-simple
                            // strings I am going to need to arrange to
                            // compute the value as used here. Ugh Ugh!
                        case HASH_AS_EQUAL:
                            r = (r + (uint64_t)h)*h_multiplier;
                            return r + newhash_binary_vector(key);
                        case HASH_AS_EQUALP:
// Here I must compute a case-insensitive hash value. Ugh this means I work
// character by character and so slow things down.
                            r = (r + (uint64_t)h)*h_multiplier;
                            data = &ucelt(key, 0);
                            len = length_of_byteheader(h) - CELL;
                            while (len != 0)
                            {   int c = *data++;
// The string will be stored in UTF8. A consequence is that any bytes forming
// part of a character beyond Basic Latin will have their top bit set. I will
// case-convert Basic Latin characters (only).
                                if ((c & 0x80) == 0) c = tolower(c);
                                r = (r + (uint64_t)c)*h_multiplier;
                            }
                            return r;
                    }
                }
                if (is_bitvec_header(h))
                {   r = r*h_multiplier + (uint64_t)h;
                    return r + newhash_binary_vector(key);
                }
// I will allow for non-simple vectors in whatever style I am in, including
// allowing non-simple strings and bit-vectors to be handled in special ways.
                if (is_array_header(h))
                {   LispObject arraytype = elt(key, 0);
                    if (arraytype == string_char_sym)
                        return r + newhash_nonsimple_string(key);
                    if (arraytype == bit_symbol)
                        return r + newhash_nonsimple_bitvector(key);
                    LispObject dims = elt(key, 1);
                    LispObject vec = elt(key, 2);
                    LispObject displace = elt(key, 3);
                    LispObject adjustable = elt(key, 4);
                    LispObject fill = elt(key, 5);
                    dims = dims;
                    vec = vec;
                    displace = displace;
                    adjustable = adjustable;
                    fill = fill;
// And hash using EQ!!!!
                    return (r + (uint64_t)key)*h_multiplier;
                }
// here in the case of EQUAL and EQUALP I must descend vectors. Well EQUALP
// is an especially jolly case in that a general vector that happens to
// hold characters must compare as EQUALP to a string that agrees in a
// case-insenstive manner, with offsets and fill-pointers all dealt with.
// @@@@
                else return (r + (uint64_t)key)*h_multiplier;
            }
// Here I should POSSIBLY look at non-simple strings and bitvectors and at
// pathnames. For now I intend to follw the principle of "You Ain't Gonna
// Need It" and just ignore the issues.
        case TAG_BOXFLOAT:
        case TAG_NUMBERS:
// For EQUALP I am supposed to hash things such that numbers that differ in
// type but have the same value will agree. I think that the most plausible
// way to achieve that would be that if a number can be converted to a long
// float without any rounding arising I should do that. For instance for
// bignums that involves checking if the number of trailing zero bits is
// big enough, and for ratios it involves verifying that the denominator is
// a power of 2. I will not do that at present, but I could if I felt like
// indulging myself with what is basically a waste of time. I have put in
// functions that are placeholders for a conversion that would be needed.
            return r + newhash_eql(key);
        default:
            return (r + (uint64_t)key)*h_multiplier;
    }
}

static bool newhash_compare_eq(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

// The following are all deficient at present, but are here to allow me to
// test things @@@.

static bool newhash_compare_eql(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

static bool newhash_compare_cl_equal(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

static bool newhash_compare_equal(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

// Beware implementation of comparisons between floats and other numeric
// types, that characters must be compared in a case-insenstive manner,
// and that atrings must match other sorts of arrays that happen to have
// characters in them.

static bool newhash_compare_equalp(LispObject key, LispObject hashentry)
{   return (key == hashentry);
}

// For hash_compare_symtab key will be a string and hashentry will be
// a symbol here... I compare strings word at a time not byte at a time,
// and this is liable to count as undefined behaviour in C and C++ and
// may run risks of breacing strict aliasing rules.

static bool newhash_compare_symtab(LispObject key, LispObject hashentry)
{   size_t n;
    uintptr_t *p1, *p2;
    hashentry = qpname(hashentry); // allow for entry in table being a symbol.  
    if (vechdr(key) != vechdr(hashentry)) return false; // lengths differ.
    n = length_of_byteheader(vechdr(key));
    p1 = (uintptr_t *)&celt(key, 0);
    p2 = (uintptr_t *)&celt(hashentry, 0);
// Compare the string 32 or 64-bits at a time depending on word-length.
    while (n >= sizeof(uintptr_t))
    {   if (*p1++ != *p2++) return false;
        n -= sizeof(uintptr_t);
    }
// There may be a partly-filled word to check at the end.
    if (n != 0 && *p1 != *p2) return false;
    return true;
}

//==========================================================================

LispObject Lget_newhash(LispObject env, int nargs, ...)
{   va_list a;
    LispObject key, tab, dflt;
    size_t pos;
    argcheck(nargs, 3, "getnewhash");
    va_start(a, nargs);
    key = va_arg(a, LispObject);
    tab = va_arg(a, LispObject);
    dflt = va_arg(a, LispObject);
    va_end(a);
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_NEWHASH)
    {   if (type_of_header(vechdr(tab)) != TYPE_NEWHASHX)
            aerror1("getnewhash", tab);
        vechdr(tab) ^= (TYPE_NEWHASH ^ TYPE_NEWHASHX);
        push3(key, tab, dflt);
// Here I have a table that at some stage had all fitted into the table, and
// I am not adding new data. I need to rehash it because garbage collection
// may have shuffled memory and so hash values that are based on memory
// addresses can be out of date. But I really expect that I will be able
// to find a hash-multiplier that will let me fit all the data back in.
// Well I suppose that may not be 100% guaranteed possible! It could be
// that the table was just on the cusp of needing to be expanded and with
// previous memory layout it had been truly lucky in terms of all fitting in.
// Now garbage collection has messed things up it might be in a much nastier
// state and expansion may be the only realistic option. OK I will allow
// for that!
printf("rehash from get_newhash in NEWHASHX case\n");
        newhash_rehash(tab, true);
        pop3(dflt, tab, key);
    }
// Extract details of the (possibly updated) hash table. This will leave
// hash calculation and value checking set up nicely.
    set_hash_operations(tab);
    pos = hash_lookup(key);
    if (pos == NOT_PRESENT)
    {   mv_2 = nil;
        return nvalues(dflt, 2);
    }
    mv_2 = lisp_true;
    return nvalues(getv_large_vector(elt(tab, HASH_VALUES), pos), 2);
}

LispObject Lmapnewhash(LispObject env, LispObject fn, LispObject tab)
//
// I should consider what happens if there is a garbage collection while
// I am performing this scan of the hash table. Well the table contents are
// not rearranged by garbage collection - the main thing that happens is that
// the table is re-tagged from TYPE_NEWHASH to TYPE_NEWHASHX. So I believe
// that provided nobody tries either lookup or set operations on the table I
// will be OK.
//
{   int32_t size, i;
    LispObject v, v1;
    if (!is_vector(tab) || type_of_header(vechdr(tab)) != TYPE_NEWHASH)
        aerror1("maphash", tab);
    v = elt(tab, HASH_KEYS);
    v1 = elt(tab, HASH_VALUES);
    size = words_in_large_vector(v);
    for (i=0; i<size; i++)
    {   LispObject key = getv_large_vector(v, i),
                   val = getv_large_vector(v1, i);
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        push3(v, v1, fn);
        Lapply2(nil, 3, fn, key, val);
        pop3(fn, v1, v);
    }
    return onevalue(nil);
}

LispObject Lnewhashcontents(LispObject env, LispObject tab)
//
// As for maphash I believe that garbage collection is pretty benign here.
//
{   size_t size, i;
    LispObject v, v1, r;
    if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_NEWHASH &&
         type_of_header(vechdr(tab)) != TYPE_NEWHASHX))
        aerror1("hashcontents", tab);
    v = elt(tab, HASH_KEYS);
    v1 = elt(tab, HASH_VALUES);
    size = words_in_large_vector(v);
    r = nil;
    for (i=0; i<size; i++)
    {   LispObject key = getv_large_vector(v, i),
                   val = getv_large_vector(v1, i);
        if (key == SPID_HASHEMPTY || key == SPID_HASHTOMB) continue;
        push2(v, v1);
        r = acons(key, val, r);
        pop2(v1, v);
    }
// The ordering of items in the result a-list is unpredictable.
// That is probably quite reasonable.
    return onevalue(r);
}

LispObject Lget_newhash_1(LispObject env, LispObject key)
{
#ifdef COMMON
    return Lget_newhash(nil, 3, key, sys_hash_table, nil);
#else
//
// The definition implemented here is as required by Reduce in
// the file matrix.red...  In the long term this is unsatisfactory.
//
    LispObject r;
    push(key);
    r = Lget_newhash(nil, 3, key, sys_hash_table, nil);
    pop(key);
    if (mv_2 != nil)
    {   r = cons(key, r);
    }
    return onevalue(r);
#endif
}

LispObject Lget_newhash_2(LispObject env, LispObject key, LispObject tab)
{   return Lget_newhash(nil, 3, key, tab, nil);
}

#ifdef DEBUG
static int biggest_hash = 0;
#endif

LispObject Lput_newhash(LispObject env, int nargs, ...)
{   va_list a;
    LispObject key, tab, val, k1;
    size_t pos;
    bool after_gc = false;
    va_start(a, nargs);
    key = va_arg(a, LispObject);
    tab = va_arg(a, LispObject);
    val = va_arg(a, LispObject);
    va_end(a);
    argcheck(nargs, 3, "putnewhash");
    if (!is_vector(tab)) aerror1("putnewhash", tab);
    if (type_of_header(vechdr(tab)) != TYPE_NEWHASH)
    {   if (type_of_header(vechdr(tab)) == TYPE_NEWHASHX)
        {   after_gc = true;
printf("HASHX found so setting after_gc\n");
            vechdr(tab) ^= (TYPE_NEWHASH ^ TYPE_NEWHASHX);
        }
        else aerror1("putnewhash", tab);
    }
// after_gc indicates if the hash table needs rehashing before it is valid...
// the FOR loop here is because it may be necessary to rehash or expand the
// table before it can be used.
    for (;;)
    {   push3(key, tab, val);
        set_hash_operations(tab);
// If there is a rehash pending I will just declare the insert attempt to
// have failed without acually trying it.
        if (after_gc) pos = NOT_PRESENT;
        else pos = hash_insert_if_possible(key);
        pop3(val, tab, key);
        if (pos != NOT_PRESENT) break;  // success!
        push3(key, tab, val);
        newhash_rehash(tab, after_gc);
        pop3(val, tab, key);
        after_gc = false;
    }
    h_table = elt(tab, HASH_KEYS);
    k1 = getv_large_vector(h_table, pos);
// The code here constrains the maximum number of items in a hash table to
// the size of a fixnum. On a 32-bit machine that will remain at 2^27-1, ie
// around 134 million. with reasonable hash table loading this will involve
// a table that fills up around a gigabyte of your memory even before you
// consider the space used to represent keys and values, so this is not a
// significant problem. (An entry uses 4 bytes for the slot where the key
// lives and 4 for where the associated value lives, so if you have 27-bits
// worth of keys you have 27+3=30 bits of space all in, even assuming there
// are no empty slots left in the table).
    if (k1 == SPID_HASHEMPTY || k1 == SPID_HASHTOMB)
        elt(tab, HASH_COUNT) += 0x10; // Increment count.
    putv_large_vector(h_table, pos, key);
    putv_large_vector(elt(tab, HASH_VALUES), pos, val);
    return onevalue(val);
}

LispObject Lput_newhash_2(LispObject env, LispObject a, LispObject b)
{   return Lput_hash(nil, 3, a, sys_hash_table, b);
}

LispObject Lrem_newhash(LispObject env, LispObject key, LispObject tab)
{   set_hash_operations(tab);
    size_t pos = hash_lookup(key);
    if (pos == NOT_PRESENT) return onevalue(nil);
    putv_large_vector(elt(tab, HASH_KEYS), pos, SPID_HASHTOMB);
    putv_large_vector(elt(tab, HASH_VALUES), pos, nil);
    return onevalue(lisp_true);
}

LispObject Lrem_newhash_1(LispObject env, LispObject a)
{   return Lrem_newhash(nil, a, sys_hash_table);
}

LispObject Lclr_newhash(LispObject env, LispObject tab)
{   LispObject v;
    size_t size, i;
    if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_NEWHASH &&
         type_of_header(vechdr(tab)) != TYPE_NEWHASHX))
        aerror1("clrnewhash", tab);
    elt(tab, 1) = fixnum_of_int(0);
    v = elt(tab, HASH_KEYS);
    size = words_in_large_vector(v);
    for (i=0; i<size; i++) putv_large_vector(v, i, SPID_HASHEMPTY);
    v = elt(tab, HASH_VALUES);
    size = words_in_large_vector(v);
    for (i=0; i<size; i++) putv_large_vector(v, i, nil);
    return tab;
}

// This function exists just for testing and development - it takes a
// hash table and forces re-hashing.

LispObject Lnewhash_rehash(LispObject env, LispObject tab)
{   if (!is_vector(tab) ||
        type_of_header(vechdr(tab)) != TYPE_NEWHASH)
        aerror1("newhash-rehash", tab);
    vechdr(tab) ^= (TYPE_NEWHASH ^ TYPE_NEWHASHX);
    return tab;
}

LispObject Lclr_newhash_0(LispObject env, int nargs, ...)
{   argcheck(nargs, 0, "clrnewhash");
    return Lclr_newhash(nil, sys_hash_table);
}

// (sxhash key) is supposed to return a positive fixnum such that any
// two items that are EQUAL in the Common Lisp sense will yield the same
// result. It has further constraints that seem to suggest that the
// values must be consistent from run to run and across a range of
// changes to the environment. I believe that I can get away with
// hashing numbers based on their values, strings on the characters that
// make them up, symbols on their print-name (but I am NOT allowed to
// pay attention to package information) and almost everything else can
// just return a code based on the type of the object. The result is
// obliged to be a positive fixnum. All this means that it is going to be
// only slightly related to the hash functions used with the main hashing
// scheme here -- where cooperation with the garbage collector can trigger
// rehashing when items move in memory. SO THIS VERSION IS WRONG BECAUSE
// IT JUST USES INTERNAL HASHING METHODS AND THEY ARE NOT STABLE. @@@@ 

LispObject Lsxnewhash(LispObject env, LispObject key)
{   uint64_t h = newhash_generic_equal(key, HASH_AS_EQUAL);
    h = h ^ (h >> 32);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

// The values returned here will also become out of date when garbage
// collection moves things around. Of hear.

LispObject Leqlnewhash(LispObject env, LispObject key)
{   uint64_t h = newhash_eql(key);
    h = h ^ (h >> 32);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

// The values returned here will also become out of date when garbage
// collection moves things around. Of hear.

LispObject Lequalnewhash(LispObject env, LispObject key)
{
//
// Descends vectors as the Standard Lisp EQUAL function does.
//
    uint64_t h = newhash_equal(key);
    h = h ^ (h >> 32);
    h = (h ^ (h >> 16)) & 0x03ffffff; // ensure it will be a positive fixnum
    return onevalue(fixnum_of_int(h));
}

LispObject Lnewhash_flavour(LispObject env, LispObject tab)
{   LispObject v,flavour = fixnum_of_int(-1);

    if (!is_vector(tab) ||
        (type_of_header(vechdr(tab)) != TYPE_NEWHASH &&
         type_of_header(vechdr(tab)) != TYPE_NEWHASHX))
        aerror1("hashtable-flavour", tab);
    v = elt(tab, 0);
// The code here needs to allow for user-specified hash functions. Well the
// word "needs" there depends on the level of enthusiasm you have for the
// dark corners of the Common Lisp specification!
    if (is_fixnum(v)) flavour = v;
    return onevalue(flavour);
}

// Now some support code for displaying statistics.

// I wanted to use the function lrand48() which is in SVID and POSIX - but
// is nevetheless not available everywhere. Well I see that this was declared
// obsolete by SVID 3. Anyway is intended to be my own implementation
// that should (if I have got it correct) be compatible. It is ONLY used
// for testing.

#define lrand_a UINT64_C(0x5DEECE66D)
#define lrand_b UINT64_C(0xB)

static uint64_t lrand_seed = UINT64_C(0x1234ABCD330E);

static long my_lrand48()
{   lrand_seed = lrand_a*lrand_seed + lrand_b;
    return (long)((lrand_seed >> 17) & UINT64_C(0x7FFFFFFF));
}

void showstats(size_t n)
{
    size_t i;
    found_n=0, found_h=0, found_c=0;
    notfound_n=0, notfound_h=0, notfound_c=0;
// To get an idea of the status of the table at this level of fullness
// I will look up all the keys that are stored in it and an equal number
// of random keys (that are not liable to be present).
    for (i=0; i<h_table_size; i++)
    {   if (ht(i) != SPID_HASHEMPTY && ht(i) != SPID_HASHTOMB)
        {   size_t j = instrumented_lookup(ht(i)); // should be there
            if (i != j) printf("??? i=%" PRIuMAX " j=%" PRIuMAX "(%" PRIxMAX ")\n",
                               (uintmax_t)i, (uintmax_t)j, (uintmax_t)j);
            instrumented_lookup(my_lrand48());      // probably not there
        }
    }
    printf("Table occupancy %" PRIuMAX "/%" PRIuMAX " = %.2f\n",
        (uintmax_t)n, (uintmax_t)h_table_size, n/(double)h_table_size);
    if (found_n != 0)
    printf("lookup=yes %10" PRIu64 "  hash=%10" PRIu64 "  cmp=%10" PRIu64 " average cmp=%.2f\n",
        found_n, found_h, found_c, found_c/(double)found_n);
    if (notfound_n != 0)
    printf("lookup=no  %10" PRIu64 "  hash=%10" PRIu64 "  cmp=%10" PRIu64 " average cmp=%.2f\n",
        notfound_n, notfound_h, notfound_c, notfound_c/(double)notfound_n);
    if (already_n != 0)
    printf("insert=no  %10" PRIu64 "  hash=%10" PRIu64 "  cmp=%10" PRIu64 " average cmp=%.2f\n",
        already_n, already_h, already_c, already_c/(double)already_n);
    if (inserted_n != 0)
    printf("insert=yes %10" PRIu64 "  hash=%10" PRIu64 "  cmp=%10" PRIu64 " average cmp=%.2f\n",
        inserted_n, inserted_h, inserted_c, inserted_c/(double)inserted_n);
}

setup_type const newhash_setup[] =
{   {"mknewhash",               WRONG_NO_3A, Lmknewhash2, Lmknewhash},
    {"getnewhash",              Lget_newhash_1, Lget_newhash_2, Lget_newhash},
    {"putnewhash",              WRONG_NO_3A, Lput_newhash_2, Lput_newhash},
    {"remnewhash",              Lrem_newhash_1, Lrem_newhash, WRONG_NO_2},
    {"clrnewhash",              Lclr_newhash, TOO_MANY_1, Lclr_newhash_0},
    {"sxnewhash",               Lsxnewhash, TOO_MANY_1, WRONG_NO_1},
    {"eqlnewhash",              Leqlnewhash, TOO_MANY_1, WRONG_NO_1},
    {"equalnewhash",            Lequalnewhash, TOO_MANY_1, WRONG_NO_1},
    {"mapnewhash",              TOO_FEW_2, Lmapnewhash, WRONG_NO_2},
    {"newhashcontents",         Lnewhashcontents, TOO_MANY_1, WRONG_NO_1},
    {"newhashtable-flavour",    Lnewhash_flavour, TOO_MANY_1, WRONG_NO_1},
    {"newhashrehash",           Lnewhash_rehash, TOO_MANY_1, WRONG_NO_1},
    {NULL,                      0, 0, 0}
};

// end of newhash.cpp
