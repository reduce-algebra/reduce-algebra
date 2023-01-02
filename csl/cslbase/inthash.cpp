// inthash.cpp                                    Copyright A C Norman 2021

/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

#ifdef TEST
#include <cstdio>
#include <cstdlib>
#include "inthash.h"
#else
#include "headers.h"
#endif

// Before any use the hash one must initialize the structure. The argument
// bits indicates how large the table should be to start with (2^bits), but
// it will expand as necessary. Keys are going to be non-zero uintptr_t
// values, so I fill the initial table with 0 to show it is empty.

// Well C++ enthusiasts might suggest that I use std::unordered_map rather
// that all this and then memory management would be burried within the
// C++ library. But I do it myself with MY choice of exact hashing procedures
// and the like!

void hash_init(inthash *h, int bits)
{   assert(bits > 3 && bits < 30);
    h->size = ((size_t)1) << bits;
    h->count = 0;
    h->keys = new (std::nothrow) uintptr_t[h->size];
    if (h->keys == nullptr) my_abort(); // not enough memory
    assert(h->keys != nullptr);
    for (size_t i=0; i<h->size; i++) h->keys[i] = 0;
    h->values = nullptr;
    h->shift = 8*sizeof(uintptr_t) - bits + 2;
// The following initial value for mult1 fits in 64-bits, and is a prime
// that is roughly 0.618034*2^64. Furthermore if you are on a 32-bit
// system so that uintptr_t is narrowed the value ends up as around
// 0.618034*2^32 and it is still prime. Note that 0.618034 is (sqrt 5-1)/2,
// and there are plausible (if marginal) reasons for expecting that to yield
// good multipliers here.
// Since C++11 one can write an intger literal with many digits and it
// will be treated as an int. long or long long as necessary. Support for
// long long started in  gcc with release 4.3 which was released in 2008, but
// at least early versions of that did not allow long literals without
// explicit "LL" suffixes. However 4.3.0 seens to support UINT64_C() as a
// macro that allows one to write 64-bit integer literals, so I use that here.
// [Well as I write this addendum to the comment I am typically using g++
// version 10.2, so comments about 4.3 are "historical"!]
    h->mult1 = (uintptr_t)UINT64_C(0x9e3779b99e3779bd);
// The initial value for the second multiplier is somewhat similarly
// similarly derived from 0.381966 (the square of (sqrt 5-1)/2) except that
// the top half of the 64-bit value has been arbitrarily offset by about
// 0x6543 (not a very special number) so that the top and bottom 32-bits
// are more distinct.
    h->mult2 = (uintptr_t)UINT64_C(0x61c8eb8961c8865f);
#ifdef CHECK_INTHASH
    h->chain = nullptr;
#endif
}

// I can indicate that I am finished with a table. The important thing
// that this does is to free the big vectors. It sets the various other
// fields to dummy values just in a spirit of tidying up.
void hash_finalize(inthash *h)
{   delete [] h->keys;
    h->keys = nullptr;
    if (h->values != nullptr)
    {   delete [] h->values;
        h->values = nullptr;
    }
    h->size = h->count = 0;
    h->shift = 0;
    h->mult1 = h->mult2 = 1;
#ifdef CHECK_INTHASH
    hash_alist ch = h->chain;
    h->chain = nullptr;
    while (ch != nullptr)
    {   hash_alist *temp = ch;
        ch = ch->next;
        delete temp;
    }
#endif
}

// When merely created using hash_init the table will act as a hash-set
// without storing any data alongside keys. If associated data is required
// then also call hash_init_values. The table of values is initialized to
// zero here more for tidiness than for other good reasons, but this means
// that if you create a table and add a number of entries and then later
// on call hash_init_values then lookup on existing keys will return 0.

void hash_init_values(inthash *h)
{   h->values = new (std::nothrow) uintptr_t[h->size];
    if (h->values == nullptr) my_abort(); // not enough memory
    assert(h->values != nullptr);
    for (size_t i=0; i<h->size; i++) h->values[i] = 0;
}

// accessor and mutator functions for the values associated with a
// hash entry at offset hx. I try to make these "kind" in the case that
// the values part of the table has not yet been allocated.

uintptr_t hash_get_value(inthash *h, size_t hx)
{   assert(hx < h->size);
    if (h->values == nullptr)
    {
#ifdef CHECK_INTHASH
        hash_alist *p = h->chain;
        while (p != nullptr && p->key != h->keys[hx]) p = p->next;
        assert(p == nullptr || p->value == 0);
#endif
        return 0;
    }
    else
    {
#ifdef CHECK_INTHASH
        hash_alist *p = h->chain;
        while (p != nullptr && p->key != h->keys[hx]) p = p->next;
        assert((p==nullptr ? 0 : p->value) == h->values[hx]);
#endif
        return h->values[hx];
    }
}

void hash_set_value(inthash *h, size_t hx, uintptr_t v)
{   assert(hx < h->size);
    if (h->values == nullptr) hash_init_values(h);
    h->values[hx] = v;
#ifdef CHECK_INTHASH
    hash_alist *p = h->chain;
    while (p != nullptr && p->key != h->keys[hx]) p = p->next;
    assert(p != nullptr);
    p->value = v;
#endif
}

#ifdef VALIDATE

static int validate_count = 0;

void hash_validate(inthash *h)
{   if ((++validate_count % 587) != 0)
        return; // Only check every so often
    // because checking is expensive
    for (size_t i = 0; i<h->size; i++)
    {   uintptr_t k = h->keys[i];
        if (k == 0) continue;
#ifdef CHECK_INTHASH
        hash_alist *p = h->chain;
        while (p != nullptr && p->key != k) p = p->next;
        assert(p != nullptr);
#endif
        size_t hx = ((h->mult1*k)>>h->shift)*4;
        assert(hx < h->size);
        size_t hx2 = 2 + ((h->mult2*k)>>h->shift)*4;
        assert(hx2 < h->size);
        uintptr_t k1 = h->keys[hx];
        uintptr_t k2 = h->keys[hx+1];
        uintptr_t k3 = h->keys[hx2];
        uintptr_t k4 = h->keys[hx2+1];
        if (hx != i && k1 == k)
        {   std::printf("key duplicated..\n");
            my_abort("hash table problem");
        }
        if (hx+1 != i && k2 == k)
        {   std::printf("key duplicated..\n");
            my_abort("hash table problem");
        }
        if (hx2 != i && k3 == k)
        {   std::printf("key duplicated..\n");
            my_abort("hash table problem");
        }
        if (hx2+1 != i && k4 == k)
        {   std::printf("key duplicated..\n");
            my_abort("hash table problem");
        }
    }
#ifdef CHECK_INTHASH
    for (hash_alist *p=h->chain; p!=nullptr; p=p->next)
    {   uintptr_t k = p->key;
        for (size_t i=0; i<h->size; i++)
            if (h->keys[i] == k) goto found;
        std::printf("Key that was in alist not in table\n");
        my_abort("hash table problem");
    found:
        continue;
    }
#endif
}

#endif // VALIDATE

// The lookup code tells us almost everything about how the table is
// internally arranged! It takes a key k and return either an index into
// the table where the key is present or the special value (-1) which
// indicates that the key was not found. Note that since the type of the
// result is size_t that "-1" is not a negative number. Indeed it is probably
// officially undefined!
//
// Each of the two hash functions is used to generate a number that is a
// multiple of 4. If these values are h1 and h2 then items at h1, h1+1,
// h2+2 and h2+3 are inspected. This in effect splits the table into
// halves with the first hash function using the 0,1 entries and the second
// just the 2,3 ones. It is predicted that with two independent hash
// functions and two possible locations for use (ie 0/1 or 2/3) that the
// table can get about 86% full before insertion becomes impossible.
//
// As is very clear from the code here, lookup cost is O(1) and it is
// anticipated that two probes in consecutive locations will be very cache-
// friendly and so looking in 4 places will be almost as fast as if only
// 2 had been checked.... and this thought is part of the motive for
// implementing the table the way that I have.

size_t hash_lookup(inthash *h, uintptr_t k)
{   assert(k != 0);
#ifdef VALIDATE
    hash_validate(h);
#endif
#ifdef CHECK_INTHASH
    hash_alist *p = h->chain;
    while (p != nullptr && p->key != k) p = p->next;
#endif
    size_t hx = ((h->mult1*k)>>h->shift)*4;
    assert(hx < h->size);
    if (h->keys[hx] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx;
    }
    if (h->keys[hx+1] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx+1;
    }
    size_t hx2 = 2 + ((h->mult2*k)>>h->shift)*4;
    assert(hx2 < h->size);
    if (h->keys[hx2] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx2;
    }
    if (h->keys[hx2+1] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx2+1;
    }
#ifdef CHECK_INTHASH
    assert(p == nullptr);
#endif
    return (size_t)(-1);
}




// Deleting items from a hash table that is arranged like this one
// is amazingly easy! Just find where the item is and empty out the
// table entry.

bool hash_delete(inthash *h, uintptr_t k)
{   size_t hx = hash_lookup(h, k);
    if (hx == (size_t)(-1)) return false; // not present
#ifdef CHECK_INTHASH
// I am not implementing delete on the chained storage scheme which is only
// present to help me debug. Well I COULD...
#endif
    h->keys[hx] = 0;
    if (h->values != nullptr) h->values[hx] = 0;
    return true;
}

// In a trivial case when one tries to insert a new item in the table
// an empty slot will be immediately present. Three layers of recovery
// apply when that is not so!
// (1) The item in the desired location can be ejected and re-inserted
//     elsewhere. This can lead to a cascade of relocation and some
//     threshold as to the amount of work done has to be set.
// (2) If (1) fails then the hash multiplier or multipliers can be
//     changed. and the table re-hashed with the new hash functions that
//     this leads to. Since it is predicted that the table should be able
//     to get 86% full before clogging up I will only perform this action
//     if (1) fails and the table is less than 75% full. This should keep
//     the table occupancy in the range 0.375 - 0.86.
// (3) When (2) fails or when the table is getting full then I double the
//     size of the table and rehash everything.
// I will keep a count of how often these operations apply and the
// table occupancy when each happen.

static int multiplier_change = 0,
           size_double = 0;
static size_t size_multiplier_change = 0,
              count_multiplier_change = 0;
static size_t size_size_double = 0,
              count_size_double = 0;

static void hash_change_multiplier(inthash *h)
{   multiplier_change++;
    size_multiplier_change += h->size;
    count_multiplier_change += h->count;
// The change made here uses a linear congruential generator such that
// if size_t is a 64-bit type the period is 2^64. On a 32-bit machine the
// sequence will clearly be less respectable but it should have period 2^32.
    h->mult2 = ((size_t)UINT64_C(2862933555777941757))*h->mult2 +
               (size_t)UINT64_C(3037000493);
}

static uintptr_t *doubleSizeCopy(uintptr_t *h, size_t size)
{   uintptr_t *hh = new (std::nothrow) uintptr_t[2*size];
    if (hh == nullptr) my_abort(); // not enough memory
    for (size_t i=0; i<size; i++)
    {   hh[i] = h[i];
        hh[i+size] = 0;
    }
    return hh;
}

static void hash_double_size(inthash *h)
{   size_double++;
    size_size_double += h->size;
    count_size_double += h->count;
// I double the size of the table. Existing data is left in there but
// will now not be in the right place. I reset the second multiplier
// back to its default value since this value has not failed with this
// larger table.
    uintptr_t *bigger = doubleSizeCopy(h->keys, h->size);
    if (h->keys != nullptr) delete [] h->keys;
    h->keys = bigger;
    if (h->values != nullptr)
        h->values = doubleSizeCopy(h->values, h->size);
    h->size *= 2;
    h->shift--;
    h->mult2 = (uintptr_t)UINT64_C(0x61c8eb8961c8865f);
}

// When the table needs rehashing I can just remove items one at a time and
// re-insert them. Well it is not quite as nice as that because in
// pathological cases the re-insertion might fail. I will allow for that by
// letting hash_rehash return true if it succeeds. If it fails then I will
// ensure that all the data is still in it, but a further recovery step will
// be called for. I expect that to be a very rare occurrence.

static bool hash_reinsert(inthash *h, uintptr_t k, uintptr_t v,
                          uintptr_t &k1, uintptr_t &v1)
{   assert(k != 0);
// I will allow myself 100 probes while trying to insert. There is nothing
// terribly magic about this number. Making it smaller would lead to
// more frequent table expnsion, while making it larger would slow down
// worst-case searches here but not impact amortised time.
// On even tries I use hash function 1, while on odd ones I use hash function
// number 2.
    for (int tries=0; tries<100; tries++)
    {   size_t hx = (tries&1)==0 ? ((h->mult1*k)>>h->shift)*4 :
                    2 + ((h->mult2*k)>>h->shift)*4;
        assert(hx < h->size);
        uintptr_t kx = h->keys[hx];
        if (kx == 0)
        {   h->keys[hx] = k;
            if (h->values != nullptr) h->values[hx] = v;
            return true;
        }
// Here the first choice location is busy, so shuffle things to make space.
        assert(hx+1 < h->size);
        uintptr_t k2 = h->keys[hx+1];
        h->keys[hx] = k;
        h->keys[hx+1] = kx;
        k = k2;
        if (h->values != nullptr)
        {   uintptr_t vx = h->values[hx];
            uintptr_t vx2 = h->values[hx+1];
            h->values[hx] = v;
            h->values[hx+1] = vx;
            v = vx2;
        }
// I leave (k,v) as the item just ejected, so that as I go round the
// loop an attempt will be made to insert it in the other half of the
// table (using the other hash function).
        if (k == 0) return true;
    }
// Here (re-)insertion failed. k1 and v1 are ref-style arguments so I can pass
// information back to the caller.
    k1 = k;
    v1 = v;
    return false;
}

// If rehashing works then I return true. Otherwise a further stage of
// recovery is needed.

static bool hash_rehash(inthash *h)
{   for (size_t i=0; i<h->size; i++)
    {   uintptr_t k = h->keys[i]; // the key I am moving
        if (k == 0) continue;
        uintptr_t v = h->values==nullptr ? 0 : h->values[i]; // value
        uintptr_t k1, v1;
        h->keys[i] = 0;           // empty the slot
        if (hash_reinsert(h, k, v, k1, v1)) continue;
// hash_reinsert failed, and it will have left the item that it had been
// unable to reinsert in (k1,v1). Note that very probably (k,v) had been
// inserted safely, but doing to led to a chain of evictions of other
// keys terminating in (k1,v1). I know that there is at least one empty
// location in the table, so I will find it and place the pending data
// there. The search has linear cost, which is sad, but does not worry me
// over-much since rehashing overall already has linear cost.
        i = 0;
        while (h->keys[i] != 0)
        {   i++;
            assert(i < h->size);
        }
        h->keys[i] = k1;
        if (h->values != nullptr) h->values[i] = v1;
        return false;
    }
    return true;
}

// The function that inserts into a table returns the location where the
// item was placed, much like hash_lookup.

size_t hash_insert(inthash *h, uintptr_t key)
{   assert(key != 0);
#ifdef VALIDATE
    hash_validate(h);
#endif
#ifdef CHECK_INTHASH
    hash_alist *p = h->chain;
    while (p != nullptr && p->key != key) p = p->next;
#endif
// I will start by reproducing the lookup code. This means that if you try
// to insert something and it is already present nothing will change and you
// just get handed back the index of where the existing entry is.
    uintptr_t k = key;
    size_t hxx = ((h->mult1*k)>>h->shift)*4;
    assert(hxx < h->size);
    if (h->keys[hxx] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hxx;
    }
    if (h->keys[hxx+1] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hxx+1;
    }
    size_t hx2 = 2 + ((h->mult2*k)>>h->shift)*4;
    assert(hx2 < h->size);
    if (h->keys[hx2] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx2;
    }
    if (h->keys[hx2+1] == k)
    {
#ifdef CHECK_INTHASH
        assert(p != nullptr);
#endif
        return hx2+1;
    }
// Now I need to insert, so I will increment the count.
    h->count++;
#ifdef CHECK_INTHASH
    assert(p == nullptr);
    p = new (std::nothrow) hash_alist;
    assert(p != nullptr);
    p->key = k;
    p->value = 0;
    p->next = h->chain;
    h->chain = p;
#endif
// Even though I will not specify a value to go with the key I need to
// act a bit as if I was, because the shuffling of data to make room for
// the new key needs to preserve existing stored values.
    uintptr_t v = 0;
// The code to insert is modelled on the code to re-insert, but wrapped in
// loop that organises recovery after any failure.
// As before the threshold of 100 probes before declaring failure is
// arbitrary and should not be very important for performance.
    for (;;)
    {   for (int tries=0; tries<100; tries++)
        {   size_t hx = (tries&1)==0 ? ((h->mult1*k)>>h->shift)*4 :
                        2 + ((h->mult2*k)>>h->shift)*4;
            assert(hx < h->size);
            uintptr_t kx = h->keys[hx];
            if (kx == 0)
            {   h->keys[hx] = k;
                if (h->values != nullptr) h->values[hx] = v;
                goto done;
            }
// Here the first choice location is busy, so shuffle things to make space.
            assert(hx+1 < h->size);
            uintptr_t k2 = h->keys[hx+1];
            h->keys[hx] = k;
            h->keys[hx+1] = kx;
            k = k2;
            if (h->values != nullptr)
            {   uintptr_t vx = h->values[hx];
                uintptr_t vx2 = h->values[hx+1];
                h->values[hx] = v;
                h->values[hx+1] = vx;
                v = vx2;
            }
// I leave (k,v) as the item just ejected, so that as I go round the
// loop an attempt will be made to insert it in the other half of the
// table (using the other hash function).
            if (k == 0) goto done;
        }
// Here I need to recover somehow. The key/value pair (k, v) is at present
// pending (ie not yet in the table).
// I will try changing the multipliers a limited number of times if the
// hash table is rather empty. Failing that I will double the size of
// the table. I note that although this generally avoids having more
// than a few changes of multiplier that if following a rehash on a
// reasonably empty table the follow up attempt to insert the original
// key fails again that can provoke a further re-hash, and that could
// lead to multiple tries with a sequence of multipliers. But that can
// only happen when inserts fail on a table that is less that 75% full
// and that should be quite rare.
        for (int n=0;; n++)
        {   if (h->count < (h->size - h->size/4) &&
                n < 4) hash_change_multiplier(h);
            else
            {   hash_double_size(h);
                n = 0;
            }
            if (hash_rehash(h)) break;
        }
    }
done:
#ifdef VALIDATE
    hash_validate(h);
#endif
// When I exit I want to return the table offset where the key got inserted.
// Because of all the shuffling that goes on it is hard to be certain where
// that will be, and that is doubly so if I have re-hashed everything in the
// process. So I take the crude way out and merely check the four possible
// locations.
    hxx = ((h->mult1*key)>>h->shift)*4;
    assert(hxx < h->size);
    if (h->keys[hxx] == key) return hxx;
    if (h->keys[hxx+1] == key) return hxx+1;
    hx2 = 2 + ((h->mult2*key)>>h->shift)*4;
    assert(hx2 < h->size);
    if (h->keys[hx2] == key) return hx2;
// I have just inserted the given key so if it is not present in any of the
// first three possible places it MUST be in the final one.
    assert(h->keys[hx2+1] == key);
    return hx2+1;
}

#ifdef TEST

// If you predefine TEST when compiling this code you will get a
// small test program

#include <cstdio>
#include <ctime>

#ifndef TESTSIZE
#define TESTSIZE 1700000
#endif

#ifndef TESTCOUNT
#define TESTCOUNT 500
#endif

#ifndef TESTBITS
#define TESTBITS 8
#endif

static uintptr_t data[TESTSIZE];

int main(int argc, char *argv[])
{   std::clock_t c0 = std::clock();
#ifdef DETERMINISTIC
    std::printf("Deterministic seeded with %d\n", DETERMINISTIC);
    std::srand(DETERMINISTIC);
#else
    std::srand(std::time(nullptr));
#endif
    for (int i=0; i<TESTSIZE; i++)
    {   intptr_t n;
    retry:
        n = 1 + (std::rand() % 100);
#ifdef EXPENSIVE
// A painfully expensive extra loop to ensure that there are no
// duplicate keys.
        for (int j=0; j<i; j++)
            if (n == data[j]) goto retry;
#endif // EXPENSIVE
        data[i] = n;
        std::printf("data[%d] = %d\n", i, static_cast<int>(n));
    }
    std::printf("Random data set up in %.1f seconds\n",
                static_cast<double>(std::clock()-c0)/CLOCKS_PER_SEC);

    inthash h;
    c0 = std::clock();
// Fill in data TESTCOUNT-1 times...
    for (int tries=0; tries<TESTCOUNT-1; tries++)
    {   hash_init(&h, TESTBITS);
        for (int i=0; i<TESTSIZE; i++)
        {   size_t hx = hash_insert(&h, data[i]);
            hash_set_value(&h, hx, 0x54321*data[i]);
        }
        hash_finalize(&h);
    }
// ... and then once more for the version that will be used for checking
// read access.
    hash_init(&h, TESTBITS);
    for (int i=0; i<TESTSIZE; i++)
    {   size_t hx = hash_insert(&h, data[i]);
        if (h.keys[hx] != data[i])
        {   std::printf("Insert returned a bad value %d\n",
                        static_cast<int>(hx));
            for (int i=0; i<h.size; i++)
            {   std::printf("%d   %6lld  %6lld\n", i,
                            (long long int)h.keys[i], (long long int)h.values[i]);
            }
            std::exit(1);
        }
        hash_set_value(&h, hx, data[i]);
    }
    std::printf("Hash table created in %.3f microseconds/call\n",
                1.0e6*static_cast<double>(std::clock()
                                          -c0)/CLOCKS_PER_SEC/TESTSIZE/TESTCOUNT);
    if (h.count != TESTSIZE)
        std::printf("hash table says it now has %d items in it\n",
                    static_cast<int>(h.count));
    std::printf("h.size = %d\n", static_cast<int>(h.size));
    for (int i=0; i<h.size; i++)
    {   std::printf("%d   %6lld  %6lld\n", i, (long long int)h.keys[i],
                    (long long int)h.values[i]);
    }
    c0 = std::clock();
    for (int tries=0; tries<TESTCOUNT; tries++)
        for (int i=0; i<TESTSIZE; i++)
        {   size_t hx;
            long long int r;
            if ((hx = hash_lookup(&h, data[i])) == (size_t)(-1))
                std::printf("Item number %d not found in table\n", i);
            if ((r = hash_get_value(&h, hx)) != data[i])
            {   std::printf("%llx at position %lld\n", (long long int)data[i],
                            (long long int)hx);
                std::printf("Got %llx should be %llx\n", r,
                            (long long int)0x54321*data[i]);
                std::exit(1);
            }
        }
    std::printf("Hash table lookup in %.3f microseconds/call\n",
                1.0e6*static_cast<double>(std::clock()
                                          -c0)/CLOCKS_PER_SEC/TESTSIZE/TESTCOUNT);
    std::printf("Average %.2f multiplier changes per %d inserts\n",
                static_cast<double>(multiplier_change)/TESTCOUNT, TESTSIZE);
    if (multiplier_change != 0)
    {   std::printf("Average occupancy = %.3f at change point\n",
                    static_cast<double>(count_multiplier_change)/static_cast<double>
                    (size_multiplier_change));
    }
    std::printf("Average %.2f size doublings per %d inserts\n",
                static_cast<double>(size_double)/TESTCOUNT, TESTSIZE);
    std::printf("Final table size = %d occupancy = %.3f%%\n",
                static_cast<int>(h.size),
                100.0*static_cast<double>(h.count)/static_cast<double>(h.size));
    std::printf("Average occupancy = %.2f%% at doubling point\n",
                100.0*static_cast<double>(count_size_double)/static_cast<double>
                (size_size_double));
    hash_finalize(&h);
    std::printf("End of tests\n");
    return 0;
}

#endif // TEST

// end of inthash.cpp
