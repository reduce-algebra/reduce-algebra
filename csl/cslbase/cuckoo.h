// cuckoo.h                                      A C Norman, September 2015

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

// set_data is given a reference into the hash table together with the index
// number of an item in the table of data used to create it. It should be used
// where the entry pointed at is the one that the creation data hashed to. It
// then merges in the payload data there - ie everything beyond the mere hash
// key.

typedef void     cuckoo_set_data(void *p, int n);




// Now the generic function for retrieving data from a hash table.
// It is passed a key and a table. It then needs a load more arguments that
// characterize the table! It returns the offset in the table where the
// key is present, or -1 if it is not present.

// It is possible that if all this was implemented in C++ rather than C
// that templates and classes could wrap up all the information passed
// here as explicit extra arguments, but at present I believe that the
// complication and overhead would mean that things ended up almost as
// bad.

extern uint32_t cuckoo_lookup(
    uint32_t key,             // integer key to look up
    void *table,              // base of the hash table
    size_t hash_item_size,    // size of each item in the table,
                              // must be <= MAX_CUCKOO_ITEM_SIZE
    uint32_t table_size,      // number of entries in the hash table
    cuckoo_get_key *get_key,  // function to retrieve keys from table
    uint32_t modulus2,        // used to give a secondary hash function
    uint32_t offset2);        // used to give a secondary hash function

// The function cuckoo_insert inserts a single item into a table and returns
// the location where it was placed. It does not fill in any associated
// data - just the key. If it fails after a large number of operations that
// shuffle the table it returns (uint32_t)(-1).
//
// For cuckoo hashing one used three hash functions. The ones used here
// are
//     h1 = key % table_size
//     h2 = key % modulus2 + offset2
//     h3 = (h1 + h2) % table_size

extern uint32_t cuckoo_insert(
    uint32_t key,             // integer key to look up
    void *table,              // base of the hash table
    size_t hash_item_size,    // size of each item in the table,
                              // must be <= MAX_CUCKOO_ITEM_SIZE
    uint32_t table_size,      // number of entries in the hash table
    cuckoo_get_key *get_key,  // function to retrieve keys from table
    cuckoo_set_key *set_key,  // function to set a key in the table
    uint32_t modulus2,        // used to give a secondary hash function
    uint32_t offset2);        // used to give a secondary hash function

typedef struct __cuckoo_parameters
{
    uint32_t table_size;
    uint32_t modulus2;
    uint32_t offset2;
} cuckoo_parameters;

// cuckoo_optimise seeks a near-optimal hash table by picking values for
// modulus2 and offset2. It does this by a brute-force search starting at
// initial_table_size and keeping going up to max_table_size. If it fails
// it will return a record with the table_size entry (uint32_t)(-1).

extern cuckoo_parameters cuckoo_optimise(
    uint32_t *items,
    int item_count,
    void *table,
    int hash_item_size,
    int initial_table_size,
    int max_table_size,
    cuckoo_get_key *get_key,
    cuckoo_set_key *set_key,
    cuckoo_set_data *set_data);

// End of cuckoo.h

