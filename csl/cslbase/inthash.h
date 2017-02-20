// inthash.h                                      Copyright A C Norman 2017

// The code here provides an implementation of hash tables that use
// integer keys (uintptr_t) and can optionally associate similar width
// integer values. Because the integers are uintptr_t it can also naturally
// support the use of memory addresses as keys - that is hash tables based
// on the Lisp "eq" test. And the values could be treated as pointers.
// At present it does not provide any way of using keys of other
// types (eg strings). The particular value 0 is not valid for use as
// a key, and is used internally to indicate an empty location in the
// table.

// The strategy used is a variation of cuckoo hashing using two
// hash functions and where each position in the table is arranged as
// a bucket of size 2. The result is that lookup can involve evaluating
// the two hash functions and then checking four locations in the table.
// This gives bounded cost lookup for both successful and unsuccessful
// searches, and pairs of table accesses are ad adjacent memory addresses
// and so will be cache friendly. The table will (almost always) not
// overflow until it is somewhat over 80% full. When it does its size
// is doubled and so throught its use (except when it is empty because
// it has just been created or because many hash_delete operations have
// been performed) it will fluctuate between around 40% and 80% full.
// Insert operations will almost always be cheap, and it is expected that
// in the amortised sense the cost of insertion is constant. Empirically
// this cost is such that insertion costs around 5 times as much as
// lookup. Because of the way that the table size is doubled as it
// grows this is roughly twice the cost you would onserve if you had
// known how much data would be used early and allocated a big enough
// table to start with. For inserting around 1.7 million keys into a
// table set to have initial size 2 million (with no table doubling
// steps required) the total cost of insertion was around 2.7 times the
// total cost of lookup.




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

#ifndef __inthash_h
#define __inthash_h 1

#include <stdlib.h>

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
#include <assert.h>


// The structure "inthash" is used to encapsulate a table. In almost
// all cases I hope that people will neither need nor want to inspect the
// fields within it. However such operations as iterating over keys or
// key-value pairs may perhaps most easily done by looking within the
// structure. Perhaps the key thing to note is that empty entries in the
// main table are recorded with the numeric value 0 in them, because 0
// will not be a valid key.

#ifdef CHECK_INTHASH

typedef struct _hash_alist
{
    uintptr_t key;
    uintptr_t value;
    struct _hash_alist *next;
} hash_alist;

#endif

typedef struct _inthash
{
    size_t size;
    size_t count;
    uintptr_t *keys;
    uintptr_t *values;
    int shift;
    size_t mult1;
    size_t mult2;
#ifdef CHECK_INTHASH
// If I am debugging I will run a simple association-list style table
// alongside the hash table and compare results. This will be really bad
// for performance but should allow me to verify proper behaviour of
// everything.
    hash_alist *chain;
#endif
} inthash;

// Before any use the hash one must initialize the structure. The argument
// bits indicates how large the table should be to start with (2^bits), but
// it will expand as necessary. Keys are going to be non-zero uintptr_t
// values, so I fill the initial table with 0 to show it is empty.
// I expect bits to be in the range 4-29 where there is no very special
// reason for either limit.

extern void hash_init(inthash *h, int bits=8);

// I can indicate that I am finished with a table. The important thing
// that this does is to free the big vectors. It sets the various other
// fields to dummy values just in a spirit of tidying up. 

extern void hash_finalize(inthash *h);

// When merely created using hash_init the table will act as a hash-set
// without storing any data alongside keys. If associated data is required
// then also call hash_init_values. The table of values is initialized to
// zero here more for tidiness than for other good reasons, but this means
// that if you create a table and add a number of entries and then later
// on call hash_init_values then lookup on existing keys will return 0.

extern void hash_init_values(inthash *h);

// accessor and mutator functions for the values associated with a
// hash entry at offset hx.I try to make these "kind" in the case that
// the values part of the table has not yet been allocated.

extern uintptr_t hash_get_value(inthash *h, size_t hx);

extern void hash_set_value(inthash *h, size_t hx, uintptr_t v);

// The lookup code takes a key k and return either an index into
// the table where the key is present or the special value (-1) which
// indicates that the key was not found. Note that since the type of the
// result is size_t that "-1" is not a negative number. Indeed it is probably
// officially undefined!
// Looking up a key using this function always has constant cost.

extern size_t hash_lookup(inthash *h, uintptr_t k);

// One can delete a key from the table in constant cost. The function
// here returns true if the item had in fact been present to start with.

extern bool hash_delete(inthash *h, uintptr_t k);

// The function that inserts into a table returns the location where the
// item was placed, much like hash_lookup. To enter a key/value pair
// in the table you need
//    hash_set_value(h, hash_insert(h, KEY), VALUE)
// doing things in two steps.

extern size_t hash_insert(inthash *h, uintptr_t k);

#endif // __inthash_h

// end of inthash.h
