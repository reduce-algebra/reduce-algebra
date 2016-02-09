// serialize.cpp                      Copyright (C) 1990-2016 Codemist Ltd


// $Id: version.h 3297 2015-12-14 20:30:04Z arthurcnorman $


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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// This is code that serializes and deserializes Lisp data - up to and
// including a complete heap image. It may in due course become a
// replacement for the old code in preserve.cpp and restart.cpp. The old
// code mostly works by dumping a heap image as a direct copy of the
// bit-patterns in the regions of memory that form the heap. These are
// then restored by loading them back to a contiguous block of memory in
// a new system and scanning the data performing relocations. There are
// special pains there to do with converting between 32 and 64-bit images.
//
// The new version is based on having a byte-stream language that can
// describe Lisp data and generating or accepting such a stream. Dumping an
// image this way involves setting up tables to record which bits of data
// have been seen before. Reading the stream involves constructing each
// item individually.

#include "headers.h"

// While developing this code it will only get built if CSL had been
// configurued with the "--with-test" option to its configure script. That
// way I can keep this code in the main trunk sources but it should not
// hurt the existing system.

#ifdef EXPERIMENT

// Codes for use in my (custom) serialisation format.
//
// Here is a bit of raw information. I looked at the length of the names
// of symbols in a Reduce image, and I find
//  length  count
//   1 -  5: 2028
//   6 - 10: 2928
//  11 - 15:  932
//  16 - 20:  319
//  21 - 24:   87
//  25 - 30:   32
//  31 - 35:   15
//  36+        18
// 
// A different study looked at all the strings present at the end of a
// garbage collection where all Reduce code (from all packages) had been
// loaded. The strings there included many that are messages that are to be
// printed. The average string length in that situation was 22 bytes... but
// that will represent a somewhat bi-modat length distribution with short
// names for symbols and longh(ish) ones for messages that get printed.


// I will have a byte-coded instruction set that describes a structure that
// is to be constructed. It will be based on having a 3-bit opcode in each
// byte 

static bool descend_symbols = true;

#define SER_OPBITS   0xe0     // top 3 bits of byte are major opcode

#define SER_VARIOUS  0x00     // a bunch of 32 "miscellaneous" codes
#define   SER_RAWSYMBOL    0x00    // a symbol
#define   SER_DUPRAWSYMBOL 0x01    // a symbol
#define   SER_SYMBOL       0x02    // a symbol, but intern it as you read
#define   SER_DUPSYMBOL    0x03    // a symbol, but intern it as you read
#define   SER_GENSYM       0x04    // a gensym
#define   SER_DUPGENSYM    0x05    // a gensym
#define   SER_BIGBACKREF   0x06    // reference more than 64 items ago
#define   SER_POSFIXNUM    0x07    // positive (or unsigned) 64-bit integer
#define   SER_NEGFIXNUM    0x08    // negative integer up to 64 bits
#define   SER_FLOAT28      0x09    // short float
#define   SER_FLOAT32      0x0a    // single float
#define   SER_FLOAT64      0x0b    // double float
#define   SER_FLOAT128     0x0c    // long float
#define   SER_CHARSPID     0x0d    // character object, "special identifier" etc
#define   SER_CONS         0x0e    // cons cell
#define   SER_DUPCONS      0x0f    // cons cell that is referred to multiple times
#define   SER_DUP          0x10    // used with items that have multiple references
#define   SER_BITVEC       0x11    // bit-vector

// The ones from here on have not yet been allocated

#define   SER_XXX12        0x12
#define   SER_XXX13        0x13
#define   SER_XXX14        0x14
#define   SER_XXX15        0x15
#define   SER_XXX16        0x16
#define   SER_XXX17        0x17
#define   SER_XXX18        0x18
#define   SER_XXX19        0x19
#define   SER_XXX1a        0x1a
#define   SER_XXX1b        0xab
#define   SER_XXX1c        0x1c
#define   SER_XXX1d        0x1d
#define   SER_XXX1e        0x1e
#define   SER_XXX1f        0x1f

// The next two opcodes make it possible for me to re-use one of the
// 64 most recent shared items in a single byte. My bet is that NIL will
// almost always be coped with this way.
#define SER_BACKREF0 0x20     // reference to item 1 to 32 ago
#define SER_BACKREF1 0x40     // reference to item 33 to 64 ago
// I expect strings to be important enough that at least short ones have
// special treatment. The length-code here will stand for 1-32 not 0-31.
#define SER_STRING   0x60     // a string with 1-32 bytes
// very small integers perhaps also deserve help.
#define SER_FIXNUM   0x80     // integer -16 to +15
// In this Lisp header words have a 7-bit field that identifies the type
// of the object. Two bits there discriminate between bit-vectors, vectors
// holding lists, vectors holding binary data and anything else. I can fit in
// 5 bits here so to simplify coding I will use that as just a copy of the
// remaining 5 bits from the type field in the two important classes of
// vector.  Bit-vectors will need to be dealt with otherwise. These cases
// will deal with simple lisp vectors, with bignums and with strings that are
// too long for the special SER_STRING case.
#define SER_LVECTOR  0xa0     // vector holding lists
#define SER_BVECTOR  0xc0     // vector holding binary info

// At present I have an unallocated code that will be usable to cope with
// cases where I have not yet thought hard enought!
#define SER_SPARE    0xe0


// For a full Reduce image there are around 7000 items that have multiple
// references to the, but my code makes the tables that I use expand as
// necessary.
//
// I ought to think about garbage collection safety here. Well I will set
// a rule that garbage collection is not allowed to happen while a heap
// is being written, and only the writing thread is allowed to be active.
// That allows me to (temporarily) scramble data using pointer-reversal
// as I traverse the structures that I am dumping, and that in turn means I
// only use bounded stack space. I will have restored all structures by
// the end of writing an image.
//
// During reading I will allow garbage collection to happen even though I
// rather do not expect it to when re-loading a fresh heap-image. That is
// because at a later stage I may wish to re-use the reading code for
// reading other data: when I do that I will need a version of the code
// here that does not descend through symbols...
//

// I will need a hash table that records information about items in the
// heap that are visited several times. I build this using Cuckoo hashing
// where each key can end up in one of just two locations. This will
// manage to hold data with maximum hash occupancy approaching 50%. Since
// a Reduce image only ends up with around 7000 repeats the size here is not
// a terrible problem. With this scheme all hash lookups use just one or
// two probes, and especially usefully all unsuccessful probes use just
// two probes -- using fairly simple-to-compute hash functions.

static size_t hashsize = 0, hashshift = 0, hashcount = 0;
static bool rehashing = false;
static uintptr_t *hash = NULL;
static size_t *payload = NULL;

#define NULLKEY ((uintptr_t)NULL)

#define MULTIPLIER1  ((uintptr_t)UINT64_C(0x0101010101010101))
static uintptr_t MULTIPLIER2 =  (uintptr_t)UINT64_C(0x9e3779b99e377741);

#define H1(p) ((MULTIPLIER1*(uintptr_t)(p)) >> hashshift)
#define H2(p) ((MULTIPLIER2*(uintptr_t)(p)) >> hashshift)

// The lookup function is especially simple because it only has to
// check two locations in the table. This code return (size_t)(-1) if
// the key is not present, and otherwise the offset in the hash table
// where it was found. Pretty much the entire motivation of the code that
// inserts data into the table is to keep this lookup code simple and
// fast. Note that this is cheap to use even for unsuccessful lookups.

static inline size_t check_repeat_hash(uintptr_t p)
{
    size_t h = H1(p);
    if (hash[h] == p) return h;
    h = H2(p);
    if (hash[h] == p) return h;
    else return (size_t)(-1);
}

// Before using the hash table it is necessary to call inithash(), which
// sets up an initial table of size 16384 entries. On a 64-bit machine this
// occupies 128 Kbytes. It will suffice for up to around 8000 entries.
// The table is allocated using malloc(), and as necessary is expanded
// using realloc.

static int cascade_limit = 0;

void init_writer_hash()
{
    int hashbits = 14;  // start off table 16384 entries long
// For small tables I will allow up to 40 probes to insert data. Each
// time the table size is doubled I will increment this by 2. The value
// used is a trade-off between faster inserts and more need for increases
// in the table size.
    cascade_limit = 40;
    hashsize = 1 << hashbits;
    hashshift = 8*sizeof(uintptr_t) - hashbits;
    hash = (uintptr_t *)malloc(hashsize*sizeof(uintptr_t));
    for (size_t i=0; i<hashsize; i++) hash[i] = NULLKEY;    
// While the hash table is being created I merely add keys without any
// associated values. At a later stage I will allocate a parallel table
// to hold values.
    payload = NULL;
    hashcount = 0;
    rehashing = false;
}

void init_writer_payload()
{
    payload = (size_t *)malloc(hashcount*sizeof(size_t *));
    for (size_t i=0; i<hashcount; i++) payload[i] = 0;
}

void release_writer_hash()
{
    free(hash);
    hash = NULL;
    free(payload);
    payload = NULL;
}

// This inserts an item in the table. On success this returns NULLKEY,
// while on failure it returns a key (not necessarily the one you had
// originally been trying to insert) that should be but is not now in
// the table. This whole scheme makes the table suitable for use as a
// representation of a hash-set.

static uintptr_t add_to_repeat_hash(uintptr_t p)
{
    int tries = 0;
    size_t h = 0;
    do
    {   size_t h1 = H1(p), h2 = H2(p);
        uintptr_t w1, w2;
// If the first choice location for this key is available for use then
// insert the key there. For lightly loaded tables this will happen quite
// a lot of the time so I make it the first case checked and hence the
// fastest path through the code. Note that if the item is in the table
// already in its second choice place and the first choice location is
// empty this would end up leaving the item in there twice. To keep myself
// fully safe I will check for that case and not insert.
        if ((w1 = hash[h1]) == NULLKEY)
        {   if (hash[h2] != p)  // Key may already be present in other slot.
            {   hash[h1] = p;
                hashcount++;
            }
            return NULLKEY;
        }
        else if (w1 == p) return NULLKEY; // Already present in slot 1.
        else if ((w2 = hash[h2]) == NULLKEY)
        {   hash[h2] = p;
            hashcount++;
            return NULLKEY;
        }
        else if (w2 == p) return NULLKEY; // Already present in slot 2.
// Both the locations I would like to go in are busy. I need to apply
// the "cuckoo" strategy and move something that is already in the table.
//
// On the first move of an insert I will always try putting the new key
// in its first choice position. When I move something I record where it
// had just been ejected from. That must have been one of the places it
// hashed to so I try to move it to the other location. Of course in some
// cases these will be the same place, and in others one can end up with
// a cycle of ejections, but in happy cases this will take me for an
// almost random walk through the table, and that will then end at an empty
// cell.
        if (h1 == h)
        {   hash[h2] = p;
            p = w2;
            h = h2;
        }
        else
        {   hash[h1] = p;
            p = w1;
            h = h1;
        }
// Sometimes there will be a cycle in the cascade or ejections, so I
// will give up if I end up trying too hard. If I set a large value for
// cascade_limit I will sometimes achieve a slighly higher table occupancy
// before I need to expand the table, but at the cost of more work inserting
// items. So the limit to use is a compromise, but not one where the
// effects either way are terribly serious.
    } while (++tries < cascade_limit);
//
// Here I have failed to insert my new key in the existing table. If this
// happens during the rehashing phase I should report it as a failure.
// Note that the key p is at present still pending and not inserted, but that
// this p may not be the one you were originally inserting but instead
// something that has been displaced.
//
    if (rehashing) return p; // Return the unplaced key.
// I need to recover from a failed insert. I will try several
// options. If the table is less than 1/3 full then up to 4 times
// I will change the multiplier that determines my second hash function.
// If either I have already used up those tries or if the table
// is at least 1/3 full I will double the table size. 
    int multiplier_changes = 0;
    for (;;)  // a big outer loop that keeps on until I have managed to fix
    {         // everything up.
        if (hashcount < hashsize/3 && multiplier_changes < 4)
        {   h = 0;
// Here the table is less than 1/3 full but I failed to insert. Well
// the fact that it is that empty means I know I can find somewhere to
// place the new key.
            while (hash[h] != NULLKEY) h++;
            hash[h] = p;
            hashcount++;
// Change the second hash function. The sequence of multipliers used are
// generated using a linear congruential generator known to behave well
// for 64-bit arithmetic, so its low 32-bits should work reasonably well
// on a 32-bit system as well.
            MULTIPLIER2 =  (uintptr_t)
                (UINT64_C(2862933555777941757)*MULTIPLIER2 +
                 UINT64_C(3037000493));
            multiplier_changes++;
        }
        else
        {   size_t new_hashsize = 2*hashsize;
            uintptr_t *new_hash =
                (uintptr_t *)realloc(hash, new_hashsize*sizeof(uintptr_t));
            if (new_hash == NULL)
            {   printf("\n+++ Run out of memory\n");
                abort();
            }
// realloc does not initialise the expanded part of the vector, so I will
// need to fill it with NULLs before I progress further.
            for (size_t i=hashsize+1; i<new_hashsize; i++)
                new_hash[i] = NULLKEY;
// Now the table has been expanded I know I have a spare place to put the
// item I was trying to insert. And because I am about to rehash everything
// it does not matter that it gets put somewhere rather arbitrary.
            hash = new_hash;
            hash[hashsize] = p;
            hashcount++;
            hashsize = new_hashsize;
            hashshift--;
            cascade_limit += 2;
// After expanding the hash table I will allow myself another 4 different
// hash functions before I feel obliged to try to expand the table some more.
            multiplier_changes = 0;
        }
// The rehashing here scans the whole table. This may re-hash some keys
// several times - I might have expected that I would find all old keys in
// the first half of the table so I could only scan that. But because of
// the remote possibility of insertion failure here I scan everything, as
// is necessary after my recovery from that. Note that this can leave some
// keys in their second choice slot with the first choice location empty.
// The rest of my code here means that this is not a problem.
        rehashing = true;
        bool rehashing_success = true;
        for (size_t i=0; i<hashsize; i++)
        {   p = hash[i];
            if (p == NULLKEY) continue; // empty slot.
// Remove and then (re-)insert the item.
            hash[i] = NULLKEY;
            hashcount--;
            if ((p = add_to_repeat_hash(p)) == NULLKEY) continue;
// p is now a key that us is not in the table. There is no point
// continuing this pass of re-hashing.
            rehashing_success = false;
            break;
        }
        if (rehashing_success) break;
// Once again here p is a key that still needs to be inserted.
    }
    rehashing = false;
    return NULLKEY;
}


LispObject *repeat_heap;
size_t repeat_heap_size = 0, repeat_count = 0;


void reader_setup_repeats(int n)
{
    if (repeat_heap_size != 0 ||
        repeat_heap != NULL)
    {   printf("\n+++ repeat heap processing error\n");
        abort();
    }
    repeat_heap_size = n;
    repeat_heap = (LispObject *)malloc(n*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   printf("\n+++ unable to allocate repeat heap\n");
        abort();
    }
// I fill the vector with fixnum_of_int(0) so it is GC safe.
    do
    {   repeat_heap[--n] = fixnum_of_int(0);
    } while (n != 0);
}

void writer_setup_repeats(size_t n)
{
    repeat_heap_size = n;
    repeat_heap =
        (LispObject *)malloc(repeat_heap_size*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   printf("\n+++ unable to allocate repeat heap\n");
        abort();
    }
}

// Given an index 1, 2, ... find the item that was referred to recently
// that is identified by that index, and apply a move to the front
// process that should lead to a significant proportion of these accesses
// being in the range 1..64.
// NOTE that index value zero is not used.

LispObject reader_repeat_old(size_t n)
{
    if (n <= 64) return repeat_heap[n];
    for (;;)
    {   size_t n2 = n/2;           // parent in binary heap
        LispObject w = repeat_heap[n];
        repeat_heap[n] = repeat_heap[n2];
        repeat_heap[n2] = w;
        if (n2 == 1) return w;  // item has been moved to front
        n = n2;
    }
}

// Given an item that is now seen for the first time but that it is known
// will be referenced again later, add it to the repeat table and if
// it falls beyond the first 64 bring it to the first position.

LispObject reader_repeat_new(LispObject x)
{
    repeat_heap[++repeat_count] = x;
    return reader_repeat_old(repeat_count);
}

// There are two phases involved when writing out data. One merely
// inserts items into the hash table of repeats and makes it possible
// to check for this. This is needed because until all data h
// a beenscanned one can not tell if there will be a second reference to
// an object that is processed early, but when it actually comes
// ro writing out data that early mention must arrange to remember
// the item for its later re-use.

// Given the location in the repeats hash table of an item that I want to
// dump, work out where it will live. Note that repeat_count will be zero
// at the start of dumping an image, and that the updating of repeat_heap
// here must match that done in the reading code. I return the location that
// the item was before the move-to-front operation. I can use this when a
// new item is to be entered in the repeat heap.

size_t find_index_in_repeats(size_t h)
{
    size_t n = payload[h];
// if n == 0 then this is the first time we have seen this item. So it
// needs to be inserted into repeat_hash.
    if (n == 0)
    {   n = ++repeat_count;
        payload[n] = h;
    }
// I now need to perform the same move-to-top operation that will be performed
// during reading. But as I do so I will need to update values in the repeat_heap
// so it can point to where any particulat item will be.
    if (n <= 64) return n;
    h = n;
    for (;;)
    {   size_t n2 = n/2;           // parent in binary heap
        LispObject w = repeat_heap[n];
        repeat_heap[n] = repeat_heap[n2];
        payload[repeat_heap[n2]] = n;
        repeat_heap[n2] = w;
        payload[w] = n2;
        if (n2 == 1) return h;  // item has been moved to front
        n = n2;
    }
}


// For testing I will put serialized data into a buffer...

#define SERSIZE 10000
int sercounter = 0;
int serincount = 0;
unsigned char serbuffer[SERSIZE];


int nextByte()
{
    if (serincount > sercounter)
    {   printf("\nRead too much\n");
        abort();
    }
    printf("Input byte %.2x\n", serbuffer[serincount]);
    return serbuffer[serincount++];
}


// This reads from 1 to 9 bytes in a variable length encoding to make up an
// unsigned 64-bit value. The bytes represent the number most significant bits
// first, and if there are 1-8 of them the last one has its top bit set, but
// all the leading ones have their top bits clear. If there are 8 bytes all
// of which have their top bit zero then the final byte is treated as a full
// 8 bits.

uint64_t readPacked()
{
    uint64_t r = 0;
    int b, i;
    for (i=0; i<8; i++)
    {   if (((b = nextByte()) & 0x80) != 0)
            return (r << 7)  | (b & 0x7f);
        r = (r << 7) | b;
    }
    return (r << 8) | nextByte();
}

// For the transport of floating point values I will suppose that for
// floats the only problem is that for some machines the byte order
// may be backwards. For doubles I will allow for both the possibility
// of ordering within each 32-bit word and ordering of the low and high
// order word of the whole number.
// I will evaluation the situation on the machine I am running on and
// act accordingly. This should already have been done, and current_fp_rep
// should give information!

typedef union _float32u
{   char i[4];
    float f;
} float32u;

typedef union _float64u
{   char i[8];
    double f;
} float64u;

// At present I am not supporting long doubles. There are multiple issues,
// including a strong lack of consistency and compatibility across machines,
// and pain trying to provide portable and fully accurate elementary
// functions.

typedef union _float128u
{   char i[16];
    long double f;
} float128u;

LispObject serial_read()
{
    LispObject *p;    // a pointer to where to put the next item
    LispObject r,     // result of the entire reading process
               pbase, // needed to make the code GC safe
               w,     // working variable
               s,     // a (linked) stack used with vectors
               b;     // a back-pointer chain
    int c;
    pbase = r = s = b = fixnum_of_int(0);
    p = &r;
down:
// nextByte() needs to read from the stream representation of things
// and return a code... In this initial sketch I will only need to look
// at three cases. One is for CONS which is sort of obvious. The next is
// VECTOR. This covers all the cases where there are pointers within the
// object, including symbols and rational and complex numbers. The final
// case is LEAF which will include immediate data such as FIXNUMS, but
// alse big-numbers, strings and back-references to previously-read
// structures.
    switch (c = nextByte())
    {
    case SER_CONS:
// I should protect pbase, b, r and s across this, and I need to worry about
// p because it could point within any previously allocated structure
// or it could point at r. To make that safe I believe I will need to
// write out cons in-line , because then I can manage to update *p before
// and garbage collection, and save r after that and before a garbage
// collection.
        b = *p = cons(fixnum_of_int(0), b);
        pbase = b;
        p = &qcar(b);
        goto down;
    case SER_DUPCONS:
// As SER_CONS but the item constructed will be referenced again so it need
// to be entered in the relevant table. Thie could have been rendered as
// SER_CONS; SER_DUP but I have chosen to provide a single opcode to handle it
// compactly.
        b = *p = cons(fixnum_of_int(0), b);
        pbase = b;
        p = &qcar(b);
        reader_repeat_new(b);
        goto down;

    case SER_BIGBACKREF:
// Back references with an offset from 1..64 are dealt with using special
// compact opcodes. Here I have something that reaches further back. The main
// opcode is followed by a sequence of bytes and if this represents the value
// n then the offset denotes is 65+n.
// The effect is that references 65 - 192 are represented as
//     BIGBACKREF 128+(n-65)
// then 193-16448 will be
//     BIGBACKREF (n-65)/128 (128+(n-65)%128)
// and so on using 7 bits per byte... up until I have used 8 bytes.
// If one is needed beyond that it can be a final 8-bit value.
// This allows for up to 2^64 back-references.
        *p = reader_repeat_old(1 + 64 + readPacked());
        goto up;

    case SER_DUP:
// This is issues just after a SER_VECTOR (etc) code that will
// have left pbase referring to the object just allocated.
        reader_repeat_new(pbase);
        goto down;

    case SER_POSFIXNUM:
// This case really needs to read the 64-bit value and construct either a
// fixnum or a boxnum as relevant. If it creates a boxnum then that could
// possibly be a shared object, and against the possibility of that I set
// pbase so that a SER_DUP opcode can behave meaningfully.
// @@@ At present I only ever re-create a fixnum.
        pbase = *p = fixnum_of_int(readPacked());
        goto up;

    case SER_NEGFIXNUM:
// Negative (small to medium-sized) integers are given a separate code here
// beause packing then using sign-and-magnitude seems easier. The extra "-1"
// here is both to avoid having the duplicated case of +0 and -0 and to
// arrange that the set of values that pack into a given number of bytes
// matches 2s complement. Eg with just 1 following byte the range goes from
// -128 to +127 (rather than -127 to +127).
// @@@ At present I only ever re-create a fixnum.
        pbase = *p = fixnum_of_int(-1-readPacked());
        goto up;

    case SER_RAWSYMBOL:
    case SER_DUPRAWSYMBOL:
        printf("SER_RAWSYMBOL not coded yet\n");
        abort();
// SER_RAWSYMBOL is used while dumping complete heap-images. The opcode here
// is followed by information to go into the header word of the symbol (various
// flag bits such as whether the symbol is global or fluid), then a dump of
// information about what goes in the function call and count components. After
// that all the list-like components will be transmitted (much as if they were
// elements in a vector).

    case SER_SYMBOL:
    case SER_DUPSYMBOL:
        printf("SER_SYMBOL not coded yet\n");
        abort();
// SER_SYMBOL is for when a single expression is being dumped. After this
// opcode comes information as to whether the symbol is a gensym or not, then the
// length of its name and a seqence of bytes giving its name. The reader will
// in general look that name up in the oblist. Such information as what is on the

    case SER_GENSYM:
    case SER_DUPGENSYM:
        printf("SER_GENSYN not coded yet\n");
        abort();
// SER_GENSYM does what it says on the tin! It needs to be followed by the
// base of the gensym name (often just "G"). It will be created in a state
// of not having been printed, so a numeric sequence number will be allocated
// to it later.

    case SER_FLOAT28:
// A 28-bit short float
        printf("SER_FLOAT28 not coded yet\n");
        abort();

    case SER_FLOAT32:
// a 32-bit single float
        printf("SER_FLOAT32 not coded yet\n");
        abort();

    case SER_FLOAT64:
// a 64-bit (long) float
        printf("SER_FLOAT64 not coded yet\n");
        abort();

    case SER_FLOAT128:
// a 128-bit (double-length) float. Note that this may not use all
// 128 bits and that cross-platform compatibility for floats of over 64
// bits is really very uncertain at present!
        printf("SER_FLOAT128 not coded yet\n");
        abort();

    case SER_CHARSPID:
// a packed characters literal. Characters that are Basic Latin can be coded
// here with just 2 bytes, so for instance 'A' is SER_CHAR/0x41. Codes up to
// U+3fff come in 3 bytes and so on. Note that the encoding is NOT utf8 - it is
// the variable length encoding.
// SPIDs are alse encoded here. In each case they are with the low bits
// shown here and I just send the rest of the data as a raw number. Note
// that bytecode handles can be dealt with here if I understand them -
// which for now I do not!
        pbase = *p = ((LispObject)readPacked()<<(Tw+2)) | TAG_HDR_IMMED;
        abort();

    case SER_BITVEC:
// This can be done very much the way that SER_STRING is. Right now I will
// just abort!
        printf("SER_BITVEC not coded yet\n");
        abort();

    case SER_STRING:
// String will be very much like BVECTOR except that because I expect it to be an
// espcially important case I pack a length code into the 5-bit field of the
// opcode byte and the type information is implicit. This code only copes
// with strings with length 1-32. The associated data is JUST the bytes
// making up the string, not any padding needed at the end.
        w = (c & 0x1f) + 1;
        pbase = *p = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+w);
        {   char *x = &celt(pbase, 0);
            for (size_t i=0; i<(size_t)w; i++) *x++ = nextByte();
            while (((int)x & 7) != 0) *x++ = 0;
        }
        goto up;

    case SER_XXX12:
    case SER_XXX13:
    case SER_XXX14:
    case SER_XXX15:
    case SER_XXX16:
    case SER_XXX17:
    case SER_XXX18:
    case SER_XXX19:
    case SER_XXX1a:
    case SER_XXX1b:
    case SER_XXX1c:
    case SER_XXX1d:
    case SER_XXX1e:
    case SER_XXX1f:
    default:
        printf("Unimplemented reader opcode\n");
        abort();
    }
    switch (c & 0xe0)
    {
    case SER_LVECTOR:
// The issue of protection of p against garbage collection is perhaps
// harder here, because if may not be possible to allocate a vector
// until garbage collection is over. But p does not point to the start
// of an item and is not tagged, so the garbage collector will not know
// what to do with it. Well for just system startup that is not really an
// issue in that garbage collection can not sanely arise until the heap has
// been restored.
// The scheme I can adopt is roughly:
//    {   intptr_t poff = p - pbase;
//        push(pbase, r, s, b);
//        reclaim();
//        pop(n, s, r, pbase);
//        if (pbase==fixnum_of_int(0)) p = &r;
//        else p = pbase + poff;
//    }
//
// nextByte() must also deliver information on the type and the size
// of the vector that I need to create.
//
// One thing to observe here. If I have a vector that is a hash table using
// EQ as its key then reading it in here will leave its entries all the right
// values but not in the right places. My proposed response to that is to
// arrange that a potentially messed up hash table has type code TYPE_HASHX
// rather than TYPE_HASH. The hash code accessing functions will check for
// that, and if they find it they re-hash before use, restoring the key to
// just TYPE_HASH. The consequence is that the rehashing work is not done
// until and unless it is actually needed.
        {   int type = ((c & 0x1f) << (Tw + 2)) | (0x01 << Tw) | TAG_HDR_IMMED,
                tag = is_number_header_full_test(type) ? TAG_NUMBERS :
                                                         TAG_VECTOR;
// The size here will be the number of Lisp items held in the vector, so
// what I need to pass to getvector scales that into bytes and allows for the
// header word as well.
            size_t n = readPacked();
            w = *p = getvector(tag, type, CELL*(n+1));
// Note that the "vector" just created may be tagged with TAG_NUMBERS
// rather than TAG_VECTOR 
            if (!SIXTY_FOUR_BIT && ((n & 1) != 0))
                *((LispObject *)(4*n+4+((uintptr_t)w)-tag)) = fixnum_of_int(0);
// In case there is a GC before I have finished filling in proper values
// in the vector I will out in values that are at least safe.
            for (size_t i=2; i<n; i++)
                *((LispObject *)(CELL*i+((uintptr_t)w)-tag)) =
                    fixnum_of_int(0);
// Vectors chain through the first entry. If a vector was empty so it did not
// have a first entry to use here it would have needed to be dumped as a LEAF.
            *((LispObject *)(CELL+((uintptr_t)w)-tag)) = b;
            b = w;
            s = cons(fixnum_of_int(n), s);
            pbase = b;
            p = &elt(b, n);
        }
        goto down;


    case SER_BACKREF0:
        *p = reader_repeat_old(1 + (c & 0x1f));
        goto up;
    case SER_BACKREF1:
        *p = reader_repeat_old(1 + 32 + (c & 0x1f));
        goto up;
    case SER_FIXNUM:
        c = c & 0x1f;
        if ((w & 0x10) != 0) c |= ~0x0f; // sign extend
        *p = fixnum_of_int(c);

// I had considered having a special opcode to deal with strings of length 0
// or longer than 33, but in fact the general SER_BVECTOR code does just that
// slighly more efficiently then I would otherwise manage. Observe that the
// a SER_BVECTOR followed by 1 byte of length code copes with any vector
// needing up to 127 words (ie 508 bytes) with just 2 bytes of control
// information.

    case SER_BVECTOR:
// The general case for vectors containing binary information takes a suffix-
// sequence showing how many 4-byte units follow. In the case of bit, byte and
// halfword vectors the tag bits contain information to show how much
// of the very last word will be in use. That has to be extracted so I know
// just how much to read. The length code that follows the SER_BVECTOR
// opcode measures in units of 4-byte words.
        w = 4*readPacked();
// Here I have assembled 7 bits of type information in c. CCCCC comes from the
// opcode. The header I want for my vector will be
//     wwwwwwww....wwww CCC CC 10 g100
        {   int type = ((c & 0x1f)<<(Tw+2)) | (0x2<<Tw) | TAG_HDR_IMMED,
                tag = is_number_header_full_test(type) ? TAG_NUMBERS :
                                                         TAG_VECTOR;
            pbase = *p = getvector(tag, type, CELL+w);

            if (vector_i8(type))
            {   char *x = (char *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
// Bytes (and that includes UTF-8 encoded strings) are sent padded out to
// a multiple of 4 bytes.
                for (size_t i=0; i<(size_t)w; i++)
                {   *x++ = nextByte();
                    *x++ = nextByte();
                    *x++ = nextByte();
                    *x++ = nextByte();
                }
            }
            else if (vector_i32(type))
            {   uint32_t *x = (uint32_t *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
// 32-bit integers are transmitted most significant byte first.
                for (size_t i=0; i<(size_t)w; i++)
                {   uint32_t q = nextByte() & 0xff;
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    *x++ = (q << 8) | (nextByte() & 0xff);
                }
            }
            else if (vector_f64(type))
            {   double *x = (double *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
                float64u u;
// Every vector of doubles must have a length that is an even number of
// 32-bit words.
                for (size_t i=0; i<(size_t)w/2; i++)
                {   for (int j=0; j<8; j++)
                    {   int q = nextByte();
                        int k;
                        switch (current_fp_rep)
                        {
                        default:
                        case 0:
// Data is transmitted in an order that matches Intel... Note that the
// writing code must convert to that if necessary.
                            k = j;
                            break;
                        case FP_WORD_ORDER:
                            k = j ^ 4;
                            break;
                        case FP_BYTE_ORDER:
                            k = j ^ 3;
                            break;
                        case FP_WORD_ORDER|FP_BYTE_ORDER:
                            k = j ^ 7;
                            break;
                        }
                        u.i[k] = q;
                    }
                    *x++ = u.f;
                }
            }
            else if (vector_i16(type))
            {   uint16_t *x = (uint16_t *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
// 16 bit values are transmitted more significant byte first, and even if
// only an odd number are needed the transmitted data pads out so that in
// all a multiple of 4 bytes gets sent.
            for (size_t i=0; i<(size_t)w; i++)
                {   uint32_t q = nextByte() & 0xff;
                    *x++ = (q << 8) | (nextByte() & 0xff);
                    q = nextByte() & 0xff;
                    *x++ = (q << 8) | (nextByte() & 0xff);
                }
            }
            else if (vector_i64(type))
            {   uint64_t *x = (uint64_t *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
// 64-bit integers are transmitted most significant byte first.
                for (size_t i=0; i<(size_t)w/2; i++)
                {   uint64_t q = nextByte() & 0xff;
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    q = (q << 8) | (nextByte() & 0xff);
                    *x++ = (q << 8) | (nextByte() & 0xff);
                }
            }
            else if (vector_f32(type))
            {   float *x = (float *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
                float32u u;
                for (size_t i=0; i<(size_t)w; i++)
                {   for (int j=0; j<4; j++)
                    {   int q = nextByte();
                        int k;
                        switch (current_fp_rep)
                        {
                        default:
                        case 0:
                        case FP_WORD_ORDER:
// Data is transmitted in an order that matches Intel... Note that the
// writing code must convert to that if necessary.
                            k = j;
                            break;
                        case FP_BYTE_ORDER:
                        case FP_WORD_ORDER|FP_BYTE_ORDER:
                            k = j ^ 3;
                            break;
                        }
                        u.i[k] = q;
                    }
                    *x++ = u.f;
                }
            }
            else if (vector_f128(type))
            {   printf("128-bit integer arrays not supported (yet?)\n");
                abort();
            }
            else if (vector_i128(type))
            {   printf("128-bit floats not supported (yet?)\n");
                abort();
            }
            else
            {   printf("Vector code is impossible\n");
                abort();
            }
        }
        goto up;

    case SER_SPARE:
    default:
        printf("Unimplemented reader opcode\n");
        abort();
    }

// The above deals with arriving at the description of an object. What follows
// copes with return to an object after having filled in one of its component
// fields.

up:
// If the back-pointer chain is empty then I am done and can return.
    if (b == fixnum_of_int(0)) return r;
// When I have done everything that fills in the CAR of a CONS cell I
// just need to go and deal with the CDR.
    if (consp(b))
    {   pbase = b;
        p = &qcdr(b);
        b = qcdr(b);
        goto down;
    }
// The remaining cases are when b points to a vector. I use the stack
// s to track how far along it I am, and need to do special things when
// I am almost complete
    intptr_t n = int_of_fixnum(qcar(s)) - 1;
    if (n == 0)
    {   w = b;
        pbase = w;
        p = &elt(w, 0);
        b = elt(w, 0);
// I could and possibly should push the released cell from s onto a local
// freelist and use that where I do a CONS if possible...
        s = qcdr(s);
        goto down;
    }
    qcar(s) = fixnum_of_int(n); // write back decreased index
    pbase = b;
    p = &elt(b, n);
    goto down;
}

//===============================================================================

// Now code to write out expressions in serialized form.


// The first thing I will need to do will be to traverse all the data that
// is to be dumped. When I first visit a location I want to mark it in a
// "used" table. If I then find I visit it again I need to create an entry
// for it in a "shared" table.
// The used table can be a spare bitmap with (at the lowest level) one
// bit for every 8-byte address. For a heap with M bytes in use this
// consumes M/64 bytes.
//
// I will use a multi-layer table based on 4096-byte chunks of memory. The
// lowest level such block will hold 32768 bits each referring to an 8-byte
// address. This covers the bottom 18 bits of the address space. On a 64-bit
// machine each higher level block will hold 512 entries - each is either NULL
// if no marks are present in an area or is a pointer to a lowest level
// block. This adds coverage of another 9 address bits. So the sequence goes
// 18, 27, 36, 45, 54. The very top block can be 8192 bytes and that gives
// coverage of a full 64-bit space. Any reasonable setup will only allocate
// a single block at each of the highest three levels!

// The sequence of indirections here looks painful, but this code
// is ONLY used while I am dumping an image file, and I am happt to take
// a view that thit is something where ultimate speed is not vital - and
// where costs such as the ones here are liable to be swamped by I/O
// overheads anyway. I will use this extreme multi-level map even on
// 32-bit machines where the first 3 levels of table are not needed at
// all. It seems tidiest to just retain the general code. Perhaps I will
// change that later, but then a speed penalty to 32-bit systems might be
// acceptable.

// Experiments (using Jlisp) show that when building the bootstrap version
// of Reduce (which includes a lot more than the final one) there are
// around 250000 objects, of which only 7000 have more than one reference
// to them. That is in the main (bootstrapreduce) initial image - when one
// loads more packages that can add extra data, but for the purposes of
// creaing the main Reduce checkpoint file the above numbers are what I
// will base my design on. Of this the key issue is that the suggestion that
// maybe 3% of items in a lisp heap might (in the case I have measured) be
// shared, so the table needed to record them does not need to be huge.

static uint8_t *****used_map[1024] = {NULL};

// Test if an address is marked as in use.

static int address_used(uint64_t addr)
{
    unsigned int i = (unsigned int)(addr >> 54);
    uint8_t *****m1 = used_map[i];
    if (m1 == NULL) return 0;
    addr -= ((uint64_t)i) << 54;   // offset in page
    i = (unsigned int)(addr >> 45);
    uint8_t ****m2 = m1[i];
    if (m2 == NULL) return 0;
    addr -= ((uint64_t)i) << 45;
    i = (unsigned int)(addr >> 36);
    uint8_t ***m3 = m2[i];
    if (m3 == NULL) return 0;
    addr -= ((uint64_t)i) << 36;
    i = (unsigned int)(addr >> 27);
    uint8_t **m4 = m3[i];
    if (m4 == NULL) return 0;
    addr -= ((uint64_t)i) << 27;
    i = (unsigned int)(addr >> 18);
    uint8_t *m5 = m4[i];
    if (m5 == NULL) return 0;
    addr -= ((uint64_t)i) << 18;
// Now addr is just an 18-bit number. Discard the low 3 bits
    addr >>= 3;
    return (m5[addr >> 3] & (1 << (addr & 7))) != 0;
} 

// Allocate memory for part of the map. if malloc can not allocate space
// it should be treated as a fatal error - the processing here is naive
// at present, since for instance with a GUI there is no guarantee that
// stderr exists.
//
// Furthermore rather than using malloc here (and free later) I should try
// to use some space that is allocated to me but not currently in use. If I
// have a 2-space copying collectior I have half my whole memory available!
// Even if I am using a non-copying collector I expect there to be LOTS of
// space available. So maybe what I need rather than malloc is a call that
// allocates a vector-like region in the heap, but falls back to malloc (eg
// to expand the heap) rather than garbage collecting?

static void *new_map_block()
{
    void *p = (void *)calloc(512, sizeof(void *));
    if (p == NULL)
    {   fprintf(stderr, "\nFatal error - no memory\n");
        exit(1);
    }     
    return p;
}

static uint8_t *new_final_map_block()
{
    uint8_t *p = (uint8_t *)calloc(4096, 1);
    if (p == NULL)
    {   fprintf(stderr, "\nFatal error - no memory\n");
        exit(1);
    }
    return p;
}

// Set a bit in the mark table, allocating extra block as needed. This
// is expected to end up using around 1.5% of the amount of memory that
// you have allocated. So for instance on a 32-bit computer the most space
// it should ever consume should be under 50 Mbytes and on a small machine
// such as a 512 Mbyte Raspberry pi it ought to use under 10 Mbytes.

static void mark_address_as_used(uint64_t addr)
{
    unsigned int i = (unsigned int)(addr >> 54);
    uint8_t *****m1 = used_map[i];
    if (m1 == NULL) used_map[i] = m1 = (uint8_t *****)new_map_block();
    addr -= ((uint64_t)i) << 54;   // offset in page
    i = (unsigned int)(addr >> 45);
    uint8_t ****m2 = m1[i];
    if (m2 == NULL) m1[i] = m2 = (uint8_t ****)new_map_block();
    addr -= ((uint64_t)i) << 45;
    i = (unsigned int)(addr >> 36);
    uint8_t ***m3 = m2[i];
    if (m3 == NULL) m2[i] = m3 = (uint8_t ***)new_map_block();
    addr -= ((uint64_t)i) << 36;
    i = (unsigned int)(addr >> 27);
    uint8_t **m4 = m3[i];
    if (m4 == NULL) m3[i] = m4 = (uint8_t **)new_map_block();
    addr -= ((uint64_t)i) << 27;
    i = (unsigned int)(addr >> 18);
    uint8_t *m5 = m4[i];
    if (m5 == NULL) m4[i] = m5 = new_final_map_block();
    addr -= ((uint64_t)i) << 18;
// Now addr is just an 18-bit number. Discard the low 3 bits
    addr >>= 3;
    m5[addr >> 3] |= (1 << (addr & 7));
} 

// Release all memory used by the bitmap.

static void release_map_5(uint8_t *m)
{
    if (m != NULL) free(m);
}

static void release_map_4(uint8_t **m)
{
    if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_5(m[i]);
        free(m);
    }
}

static void release_map_3(uint8_t ***m)
{
    if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_4(m[i]);
        free(m);
    }
}

static void release_map_2(uint8_t ****m)
{
    if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_3(m[i]);
        free(m);
    }
}

static void release_map_1(uint8_t *****m)
{
    if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_2(m[i]);
        free(m);
    }
}

void release_map()
{
    for (int i=0; i<1024; i++)
    {   release_map_1(used_map[i]);
        used_map[i] = NULL;
    }
}

#define BACKPOINTER_MASK   3
#define BACKPOINTER_CAR    0
#define BACKPOINTER_CDR    1
#define BACKPOINTER_SYMBOL 2
#define BACKPOINTER_VECTOR 3

// I will have two copies of the code that traverses everything. The first
// is just there to record which objects have multiple references to them.
// The second will dump the structure to a stream. The skeleton of the code
// is maybe 150 lines long and having it replicated is perhaps bad, but
// at present that seems the easiest way to cope with the different behaviour
// needed during each of the two passes.

void scan_data(LispObject p)
{
    LispObject b = 0 + BACKPOINTER_CDR, w;
    uintptr_t len;
    Header h;
down:
    if (p == 0)
    {   printf("Zero pointer found\n"); // An error - but I feel safest
                                        // if I detect it and do not crash.
        goto up;
    }
    switch (p & TAG_BITS)
    {
    default:
    case TAG_CONS:
        if (address_used(p - TAG_CONS))
        {   add_to_repeat_hash(p);
            goto up;
        }
        mark_address_as_used(p - TAG_CONS);
        w = p;
        p = qcar(p);
        qcar(w) = b;
        b = w - TAG_CONS + BACKPOINTER_CAR;
        goto down;

    case TAG_SYMBOL:
        if (address_used(p - TAG_SYMBOL))
        {   add_to_repeat_hash(p);
            goto up;
        }
        mark_address_as_used(p - TAG_SYMBOL);
// I have two modes if serialisation. One views symbols as "just other bits
// of data" and descendes through them so that the contents of their value
// cells, property lists and so on get inspected. That version is used
// when creating a full heap image. The other stops when it finda a symbol,
// and when writing data out just writes out its name (or somewhat more
// subtle information if it is a gensym). On reading things back in in this
// letter case the name as dumped is just looked up in the object list. This
// way of doing things may be useful for preserving data on disc or sending
// it to a separate process. It captures the information that "print" would
// except that it also understands about structure sharing within the object
// that is being written.
        if (!descend_symbols) goto up;
        w = p;
        p = qpackage(p);
        qpackage(w) = b;
        b = (LispObject)&qpackage(w) + BACKPOINTER_SYMBOL;
        goto down;

    case TAG_VECTOR:
        if (address_used(p - TAG_VECTOR))
        {   add_to_repeat_hash(p);
            goto up;
        }
        mark_address_as_used(p - TAG_VECTOR);
// Some vectors hold binary, some lists and a few have a small number of
// lists in their first few cells and binary data beyond that. It is
// necessary to decode the header to see which case applies. The same
// issue will arise for (boxed) numbers.
        h = vechdr(p);
        if (vector_holds_binary(h)) goto up;
        if (is_mixed_header(h)) len = 4*CELL;
        else len = length_of_header(h);
// len in the length in bytes including the size of the header. For "mixed"
// vectors (most notably stream objects) it represents one cell of header and
// three of lisp data.
        w = p + len - CELL - TAG_VECTOR;
        p = *(LispObject *)w;
        *(LispObject *)w = b;
        b = w + BACKPOINTER_VECTOR;
        goto down;

    case TAG_NUMBERS:
        if (address_used(p - TAG_NUMBERS))
        {   add_to_repeat_hash(p);
            goto up;
        }
        mark_address_as_used(p - TAG_NUMBERS);
        h = numhdr(p);
        if (vector_holds_binary(h)) goto up;
        len = length_of_header(h);
        w = p + len - CELL - TAG_NUMBERS;
        p = *(LispObject *)w;
        *(LispObject *)w = b;
        b = w + BACKPOINTER_VECTOR;
        goto down;

    case TAG_BOXFLOAT:
        if (address_used(p - TAG_BOXFLOAT))
        {   add_to_repeat_hash(p);
            goto up;
        }
        mark_address_as_used(p - TAG_BOXFLOAT);
// A boxed float never contains further pointers, so there is no more
// to do here.
        goto up;

    case TAG_FIXNUM:
    case TAG_HDR_IMMED:
// Immediate data (eg small integers, characters) ought not to need any more,
// however I may need to review this when I consider bytecode streams.
        goto up;

    case TAG_FORWARD:
// Forwarding addresses should only be present while the garbage collector
// is active, and so ought not to be found. I will print a message and
// basically ignore them.
        printf("\n+++ Forwarding address detected in heap scan\n");
        goto up;
    }

up:
    switch (b & BACKPOINTER_MASK)
    {
    default:
    case BACKPOINTER_CAR:
// This is where I had just finished scanning the CAR of a cell and now
// need to deal with the CDR.
        w = qcar(b - BACKPOINTER_CAR + TAG_CONS);
        qcar(b - BACKPOINTER_CAR + TAG_CONS) = p;
        p = qcdr(b - BACKPOINTER_CAR + TAG_CONS);
        qcdr(b - BACKPOINTER_CAR + TAG_CONS) = w;
        b = b + BACKPOINTER_CDR - BACKPOINTER_CAR;
        goto down;

    case BACKPOINTER_CDR:
// The termination of the back-pointer chain is to address zero as if one
// had come down the CDR side of it.
        if (b == 0 + BACKPOINTER_CDR) return; // finished!
// I have just finished the CDR, so now I can repair the structure and go
// up another level.
        w = b - BACKPOINTER_CDR + TAG_CONS;
        b = qcdr(w);
        qcdr(w) = p;
        p = w;
        goto up;

    case BACKPOINTER_SYMBOL:
// Here I am returning to a symbol. I keep this case separate from
// the more general VECTOR case both because symbols are common and
// because their headers are formatted differently to other vectors, so
// this simplifies the task of sorting out how to re-tag things.
        w = *(LispObject *)(b - BACKPOINTER_SYMBOL);
        *(LispObject *)(b - BACKPOINTER_SYMBOL) = p;
        b = b - CELL;
        p = *(LispObject *)(b - BACKPOINTER_SYMBOL);
        if (is_symbol_header_full_test(p))
        {   p = b - BACKPOINTER_SYMBOL + TAG_SYMBOL;
            b = w;
            goto up;
        }
        *(LispObject *)(b - BACKPOINTER_SYMBOL) = w;
        goto down;

    case BACKPOINTER_VECTOR:
// I have processed an item that was in a vector-like object and now need
// to scan back to the previous one. When one reaches the start and ascends
// the nature of the header that is found will determine whether the object
// had originally been tagged as SYMBOL, VECTOR or NUMBERS. Note that the
// fact that I am RETURNING to a vector means it must have been a vector
// that contained pointers...
        w = *(LispObject *)(b - BACKPOINTER_VECTOR);
        *(LispObject *)(b - BACKPOINTER_VECTOR) = p;
        b = b - CELL;
        p = *(LispObject *)(b - BACKPOINTER_VECTOR);
// The item I am scanning back over is either a number (in fact a ratio
// or a complex number) in which case it will need to be re-tagged with
// TAG_NUMBERS, and the test here detects its header...
        if (is_number_header_full_test(p))
        {   p = b - BACKPOINTER_VECTOR + TAG_NUMBERS;
            b = w;
            goto up;
        }
// .. or some other sort of vector, with the header here identified as
// not representing immediate user date nor being the header of a symbol.
// The numeric cases have already been filtered out.
        if (is_vector_header_full_test(p))
        {   p = b - BACKPOINTER_VECTOR + TAG_VECTOR;
            b = w;
            goto up;
        }
        *(LispObject *)(b - BACKPOINTER_VECTOR) = w;
        goto down;
    }
}

// Here is the second pass that writes out the data. While I develop this
// I will arrange that the dumping code mostly prints out a human-readable
// transcript of what there is... That will not be useful for much more
// the debugging!

void write_byte(int byte, const char *msg, ...)
{
    va_list a;
    if (sercounter < SERSIZE) serbuffer[sercounter++] = byte;
    printf("%.2x: ", byte & 0xff);
    va_start(a, msg);
    vprintf(msg, a);
    printf("\n");
    va_end(a);
}

// Write a 64-bit unsigned value in a format compatible with readPacked()

void write_64(uint64_t n)
{
    int i, any=0, final = 7;
    char msg[32];
    if (n == (n & 0x7f))
    {   sprintf(msg, "%#.2x = %d", (int)n, (int)n);
        write_byte(n | 0x80, msg);
        return;
    }
    if ((n & UINT64_C(0xff000000000000)) != 0) final = 8;
    for (i=8; i>0; i--)
    {   int b = (n >> (7*i+final)) & 0x7f;
        if (any || (b != 0))
        {   any = 1;
            sprintf(msg, "%#" PRIx64, ((uint64_t)b) << (7*i+final));
            write_byte(b, msg);
        }
    }
    if (final == 7)
    {   sprintf(msg, "%#.2x = %" PRIu64, (int)n & 0x7f, n);
        write_byte(0x80 | (n & 0x7f), msg);
    }
    else
    {   sprintf(msg, "%#.2x = %" PRIu64, (int)n & 0xff, n);
        write_byte(n & 0xff, msg);
    }
}

uintptr_t code_up_codepointer(void *p)
{
    return 0; // for now
}

// The code here requires that repeat_hash has been created by a previous
// use of scan_data. Every item that has multiple references to it will
// be in there. The first time an object is visited then hash table entry
// will exist but has zero in its data field.

void write_data(LispObject p)
{
    LispObject b = 0 + BACKPOINTER_CDR, w;
    uintptr_t len;
    int64_t w64;
    Header h;
    size_t i;
down:
    if (p == 0) p = SPID_NIL; // reload as a SPID.
    if ((i = check_repeat_hash(p)) != (size_t)(-1))
    {   if (payload[i] != 0)
        {   size_t n = find_index_in_repeats(i);
            char msg[20];
            sprintf(msg, "back %" PRIuPTR, (uintptr_t)n);
            if (n <= 32) write_byte(SER_BACKREF0 + n - 1, msg);
            else if (n <= 64) write_byte(SER_BACKREF0 + n - 33, msg);
            else
            {   write_byte(SER_BIGBACKREF, msg);
                write_64(n);
            }
            goto up;
        }
// If this is the first visit to an item that will be repeated then I
// need to record where it will live in the table of repeats.
        find_index_in_repeats(i);
    }
// Here we will have i==-1 if the object is not going to be referenced again.    
    switch (p & TAG_BITS)
    {
    default:

    case TAG_CONS:
// I have a separate opcode for a cons csll that is will have further
// references to it bacause there was easy space in my opcode map for that.
        if (i != (size_t)-1)
            write_byte(SER_DUPCONS, "cons that will be re-used");
        else write_byte(SER_CONS, "cons");
        w = p;
        p = qcar(p);
        qcar(w) = b;
// Reverse pointers with the back-pointer being tagged with 0
        b = w - TAG_CONS + BACKPOINTER_CAR;
        goto down;

    case TAG_SYMBOL:
        if (!descend_symbols)
        {   w = qpname(p);
            char msg[32];
            size_t n = length_of_byteheader(vechdr(w)) - CELL;
            if (i != (size_t)-1)
            {   sprintf(msg, "DUPSYMBOL (name %" PRIuPTR ")", (uintptr_t)n);
                write_byte(SER_DUPSYMBOL, msg);
            }
            else
            {   sprintf(msg, "SYMBOL (name %" PRIuPTR ")", (uintptr_t)n);
                write_byte(SER_SYMBOL, msg);
            }
// Note that for general vectors when I write out data I always pad the
// data as written to be a multiple of 4 bytes. I do not do that for
// symbols... I send out exactly the number of bytes that there are.
            write_64(n);
            for (size_t i=0; i<n; i++)
            {   int c = celt(w, i) & 0xff;
                char msg[8];
                if (0x20 < c && c <= 0x7e) sprintf(msg, "'%c'", c);
                else sprintf(msg, "%#.2x", c);
                write_byte(c, msg);
            }
            goto up;
        }
// I have not sorted out the bit that follows yet!
        write_byte(SER_RAWSYMBOL, "symbol header");
// Here I need to cope with the tagging bits and function cells, and
// the count field... Each of these uses a variable length coding scheme that
// will be 1 byte long in easy cases but can cope with 2^64 possibilities in
// all if necessary.
        write_64((uint64_t)qheader(p)>>(Tw+4));
        write_64(code_up_codepointer((void *)(qfn0(p))));
        write_64(code_up_codepointer((void *)(qfn1(p))));
        write_64(code_up_codepointer((void *)(qfn2(p))));
        write_64(code_up_codepointer((void *)(qfn3(p))));
        write_64(code_up_codepointer((void *)(qfn4(p))));
        write_64(qcount(p));
        w = p;
        p = qpackage(p);
        qpackage(w) = b;
        b = (LispObject)&qpackage(w) + BACKPOINTER_SYMBOL;
        goto down;

    case TAG_VECTOR:
// Some vectors hold binary, some lists and a few have a small number of
// lists in their first few cells and binary data beyond that. It is
// necessary to decode the header to see which case applies. The same
// issue will arise for (boxed) numbers.
        h = vechdr(p);
        if (vector_holds_binary(h)) goto write_binary_vector;
        write_byte(SER_LVECTOR | ((h>>(Tw+2)) & 0x1f), "lisp vector");
        write_64(length_of_header(h) - CELL);
        if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly referenced vector");
// Now now the data beyond the 3 list-holding items in a MIXED structure
// will not be dumped. I may need to review that later on.
        if (is_mixed_header(h)) len = 4*CELL;
        else len = length_of_header(h);
// len in the length in bytes including the size of the header. For "mixed"
// vectors (most notably stream objects) it represents one cell of header and
// three of lisp data.
        w = p + len - CELL - TAG_VECTOR;
        p = *(LispObject *)w;
        *(LispObject *)w = b;
        b = w + BACKPOINTER_VECTOR;
        goto down;

    write_binary_vector:
// I need to separate off bitvectors and short strings here since they
// get special treatment.
        if (is_string_header(h) &&
            (len = length_of_byteheader(h) - CELL) <= 32 &&
            len != 0)
        {   char msg[20];
            sprintf(msg, "string: %d", (int)len);
            write_byte(SER_STRING+len-1, msg);
            for (size_t i=0; i<len; i++)
            {   int c = ucelt(p, i);
                if (0x20 < c && c <= 0x7e) sprintf(msg, "'%c'", c);
                else sprintf(msg, "%#.2x", c);
                write_byte(c, msg);
            }
            goto up;
        }
        else if (is_bitvec_header(h))
        {   char msg[32];
            len = length_of_bitheader(h);
            sprintf(msg, "bitvec %" PRIuPTR, (intptr_t)len);
            write_byte(SER_BITVEC, msg);
            write_64(len);
            len = (len + 7)/8;
            for (size_t i=0; i<len; i++)
            {   int c = ucelt(p, i);
                for (int k=0; k<8; k++)
                    msg[k] = (c & (1<<k)) != 0 ? '1' : '0';
                msg[8] = 0;
                write_byte(c, msg);
            }
            goto up;
        }
//
// The general code here writes out a vector where its contents are
// binary data. This needs to use separate code for each sort of data
// so that the serialized version is transmitted using a standard order
// of bytes. Also for vectors that hold butes or halfwords the number
// of units to transmit has to be computed in the light of the full
// header word. 
        write_byte(SER_BVECTOR | ((h>>(Tw+2)) & 0x1f), "binary vector");
// The code that follows must match up with the code that reads vectors
// back in. It has to convert data to a portable form that is agnostic
// to little vs. big-endian architectures.
// Also note that the "vector" may be tagged as TAG_VECTOR or TAG_NUMBERS and
// so I need code that uses a mask operation to address its start.
        if (vector_i8(h))
        {   char *x = (char *)(((uintptr_t)p & ~(uintptr_t)7) + CELL);
            write_64(len = length_of_byteheader(h) - CELL);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
// I *could* detect strings etc here to display the comments more tidily,
// but since they are just for debugging that seems like too much work
// for today.
            for (size_t i=0; i<len; i++) write_byte(*x++, "part of vec8/string");
        }
        else if (vector_i32(h))
        {   uint32_t *x = (uint32_t *)(((uintptr_t)p & ~(uintptr_t)7) + CELL);
// The packed length is the length in words.
            write_64(len = (length_of_header(h) - CELL)/4);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
// 32-bit integers are transmitted most significant byte first.
            for (size_t i=0; i<len; i++)
            {   uint32_t q = *x++;
                write_byte((q>>24) & 0xff, "high byte");
                write_byte((q>>16) & 0xff, "3");
                write_byte((q>>8) & 0xff, "2");
                write_byte(q & 0xff, "low byte");
            }
        }
        else if (vector_f64(h))
        {   double *x = (double *)(((uintptr_t)p & ~(uintptr_t)7) + CELL);
            float64u u;
            write_64(len = (length_of_header(h) - CELL)/8);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
            for (size_t i=0; i<len; i++)
            {   u.f = *x++;
                for (int j=0; j<8; j++)
                {   int k;
                    switch (current_fp_rep)
                    {
                    default:
                    case 0:
                        k = j;
                        break;
                    case FP_WORD_ORDER:
                        k = j ^ 4;
                        break;
                    case FP_BYTE_ORDER:
                        k = j ^ 3;
                        break;
                    case FP_WORD_ORDER|FP_BYTE_ORDER:
                        k = j ^ 7;
                        break;
                    }
                    write_byte(u.i[k], "part of double");
                }
            }
        }
        else if (vector_i16(h))
        {   uint16_t *x = (uint16_t *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
            write_64(len = length_of_hwordheader(h) - CELL);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
            for (size_t i=0; i<len; i++)
            {   uint32_t q = *x++;
                write_byte((q>>8) & 0xff, "high byte");
                write_byte(q & 0xff, "low byte");
            }
        }
        else if (vector_i64(h))
        {   uint64_t *x = (uint64_t *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
            write_64(len = (length_of_header(h) - CELL)/8);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
// 64-bit integers are transmitted most significant byte first.
            for (size_t i=0; i<len; i++)
            {   uint64_t q = *x++;
                write_byte((q>>56) & 0xff, "high byte");
                write_byte((q>>48) & 0xff, "7");
                write_byte((q>>40) & 0xff, "6");
                write_byte((q>>32) & 0xff, "5");
                write_byte((q>>24) & 0xff, "4");
                write_byte((q>>16) & 0xff, "3");
                write_byte((q>>8) & 0xff, "2");
                write_byte(q & 0xff, "low byte");
            }
        }
        else if (vector_f32(h))
        {   float *x = (float *)(((uintptr_t)p & ~(uintptr_t)3) + CELL);
            write_64(len = (length_of_header(h) - CELL)/4);
            if (i != (size_t)-1) write_byte(SER_DUP, "repeatedly ref. vector");
            float32u u;
            for (size_t i=0; i<len; i++)
            {   u.f = *x++;
                for (int j=0; j<8; j++)
                {   int k;
                    switch (current_fp_rep)
                    {
                    default:
                    case 0:
                    case FP_WORD_ORDER:
                        k = j;
                        break;
                    case FP_BYTE_ORDER:
                    case FP_WORD_ORDER|FP_BYTE_ORDER:
                        k = j ^ 3;
                        break;
                    }
                    write_byte(u.i[k], "part of float");
                }
            }
        }
        else if (vector_f128(h))
        {   printf("128-bit integer arrays not supported (yet?)\n");
            abort();
        }
        else if (vector_i128(h))
        {   printf("128-bit floats not supported (yet?)\n");
            abort();
        }
        else
        {   printf("Vector code is impossible\n");
            abort();
        }



        goto up;

    case TAG_NUMBERS:
        h = numhdr(p);
        if (vector_holds_binary(h)) goto up;
        len = length_of_header(h);
        w = p + len - CELL - TAG_NUMBERS;
        p = *(LispObject *)w;
        *(LispObject *)w = b;
        b = w + BACKPOINTER_VECTOR;
        goto down;

    case TAG_BOXFLOAT:
// A boxed float never contains further pointers, so there is no more
// to do here.
        goto up;

    case TAG_FIXNUM:
        w64 = int_of_fixnum(p);
        if (-16 <= w64 && w64 < 15)
        {   char msg[8];
            sprintf(msg, "%d", (int)w64);
            write_byte(SER_FIXNUM | ((int)w64 & 0x1f), msg);
        }
        else
        {   char msg[32];
            sprintf(msg, "%" PRId64, w64);
            if (w64 < 0)
            {   write_byte(SER_NEGFIXNUM, msg);
                write_64(-w64-1);
            }
            else
            {   write_byte(SER_POSFIXNUM, msg);
                write_64(w64);
            }
        }
        goto up;

    case TAG_HDR_IMMED:
// Immediate data (eg characters and SPIDs).
        {   char msg[32];
            uint64_t nn = ((uint64_t)p) >> (Tw+2);
            sprintf(msg, "#%" PRIx64, nn);
            write_byte(SER_CHARSPID, msg);
            write_64(nn);
        }
        goto up;

    case TAG_FORWARD:
// Forwarding addresses should only be present while the garbage collector
// is active, and so ought not to be found. I will print a message and
// basically ignore them.
        printf("\n+++ Forwarding address detected in heap scan\n");
        goto up;
    }

up:
    switch (b & BACKPOINTER_MASK)
    {
    default:
    case BACKPOINTER_CAR:
// This is where I had just finished scanning the CAR of a cell and now
// need to deal with the CDR.
        w = qcar(b - BACKPOINTER_CAR + TAG_CONS);
        qcar(b - BACKPOINTER_CAR + TAG_CONS) = p;
        p = qcdr(b - BACKPOINTER_CAR + TAG_CONS);
        qcdr(b - BACKPOINTER_CAR + TAG_CONS) = w;
        b = b + BACKPOINTER_CDR - BACKPOINTER_CAR;
        goto down;

    case BACKPOINTER_CDR:
// The termination of the back-pointer chain is to address zero as if one
// had come down the CDR side of it.
        if (b == 0 + BACKPOINTER_CDR) return; // finished!
// I have just finished the CDR, so now I can repair the structure and go
// up another level.
        w = b - BACKPOINTER_CDR + TAG_CONS;
        b = qcdr(w);
        qcdr(w) = p;
        p = w;
        goto up;

    case BACKPOINTER_SYMBOL:
// Here I am returning to a symbol. I keep this case separate from
// the more general VECTOR case both because symbols are common and
// because their headers are formatted differently to other vectors, so
// this simplifies the task of sorting out how to re-tag things.
        w = *(LispObject *)(b - BACKPOINTER_SYMBOL);
        *(LispObject *)(b - BACKPOINTER_SYMBOL) = p;
        b = b - CELL;
        p = *(LispObject *)(b - BACKPOINTER_SYMBOL);
        if (is_symbol_header_full_test(p))
        {   p = b - BACKPOINTER_SYMBOL + TAG_SYMBOL;
            b = w;
            goto up;
        }
        *(LispObject *)(b - BACKPOINTER_SYMBOL) = w;
        goto down;

    case BACKPOINTER_VECTOR:
// I have processed an item that was in a vector-like object and now need
// to scan back to the previous one. When one reaches the start and ascends
// the nature of the header that is found will determine whether the object
// had originally been tagged as SYMBOL, VECTOR or NUMBERS. Note that the
// fact that I am RETURNING to a vector means it must have been a vector
// that contained pointers...
        w = *(LispObject *)(b - BACKPOINTER_VECTOR);
        *(LispObject *)(b - BACKPOINTER_VECTOR) = p;
        b = b - CELL;
        p = *(LispObject *)(b - BACKPOINTER_VECTOR);
// The item I am scanning back over is either a number (in fact a ratio
// or a complex number) in which case it will need to be re-tagged with
// TAG_NUMBERS, and the test here detects its header...
        if (is_number_header_full_test(p))
        {   p = b - BACKPOINTER_VECTOR + TAG_NUMBERS;
            b = w;
            goto up;
        }
// .. or some other sort of vector, with the header here identified as
// not representing immediate user date nor being the header of a symbol.
// The numeric cases have already been filtered out.
        if (is_vector_header_full_test(p))
        {   p = b - BACKPOINTER_VECTOR + TAG_VECTOR;
            b = w;
            goto up;
        }
        *(LispObject *)(b - BACKPOINTER_VECTOR) = w;
        goto down;
    }
}

LispObject Lserialize(LispObject nil, LispObject a)
{   descend_symbols = false;
    sercounter = 0;
    init_writer_hash();
    scan_data(a);
    release_map();
    init_writer_payload();
    write_data(a);
    release_writer_hash();
    return onevalue(nil);
}

LispObject Lunserialize(LispObject nil, int nargs, ...)
{
    serincount = 0;
    return onevalue(serial_read());
}

#endif    //EXPERIMENT

// end of serialize.cpp
