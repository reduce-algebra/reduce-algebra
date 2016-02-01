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

#define SER_OPBITS   0xe0     // top 3 bits of byte are major opcode

#define SER_VARIOUS  0x00     // a bunch of 32 "miscellaneous" codes
#define   SER_RAWSYMBOL   0x00    // a symbol
#define   SER_SYMBOL      0x01    // a symbol, but intern it as you read
#define   SER_BIGBACKREF  0x02    // reference more than 64 items ago
#define   SER_POSFIXNUM   0x03    // positive (or unsigned) 64-bit integer
#define   SER_NEGFIXNUM   0x04    // negative integer up to 64 bits
#define   SER_FLOAT28     0x05    // short float
#define   SER_FLOAT32     0x06    // single float
#define   SER_FLOAT64     0x07    // double float
#define   SER_FLOAT128    0x08    // long float
#define   SER_CHAR        0x09    // character object
#define   SER_SPID        0x0a    // "special identifier"
#define   SER_CONS        0x0b    // cons cell
#define   SER_DUPCONS     0x0c    // cons cell that is referred to multiple times
#define   SER_DUP         0x0d    // used with items that have multiple references
#define   SER_BITVEC      0x0e    // bit-vector
#define   SER_XXX0f       0xf0    // unused at present

// The ones from here on have not yet been allocated
#define   SER_XXX10       0x10
#define   SER_XXX11       0x11
#define   SER_XXX12       0x12
#define   SER_XXX13       0x13
#define   SER_XXX14       0x14
#define   SER_XXX15       0x15
#define   SER_XXX16       0x16
#define   SER_XXX17       0x17
#define   SER_XXX18       0x18
#define   SER_XXX19       0x19
#define   SER_XXX1a       0x1a
#define   SER_XXX1b       0xab
#define   SER_XXX1c       0x1c
#define   SER_XXX1d       0x1d
#define   SER_XXX1e       0x1e
#define   SER_XXX1f       0x1f

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


typedef struct _repeated_object
{
    LispObject x;
    int32_t index;
} repeated_object;

#define INITIAL_REPEAT_HEAP_SIZE (3000)
#define INITIAL_REPEAT_HASH_SIZE (4507)

repeated_object *repeat_hash = NULL;
int repeat_hash_size = 0;

// While writing the repeat_heap in fact holds integers that are
// references back into the repeat hash table. I can use the type
// LispObject for that without trouble. During writing it does not
// need to be garbage collector safe, however for simplicity I will
// make it a root for the garbage collector and then to keep things
// secure I will package up the integers I put in it as fixnums.
//
// During reading it is a genuine array of Lisp values and garbage
// collector interaction will be important.

LispObject *repeat_heap
int repeat_heap_size = 0, repeat_count = 0;


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

void writer_setup_repeats()
{
    if (repeat_heap_size != 0 ||
        repeat_heap != NULL ||
        repeat_hash != NULL)
    {   printf("\n+++ repeat heap processing error\n");
        abort();
    }
    repeat_heap_size = INITIAL_REPEAT_HEAP_SIZE;
    repeat_heap =
        (LispObject *)malloc(repeat_heap_size*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   printf("\n+++ unable to allocate repeat heap\n");
        abort();
    }
// The initial size given here is a prime judged so that when the repeat
// heap is full the hash table occupancy will be around 67%, which with a
// reasonable hash distribution keeps access costs modest.
    reepeat_hash_size = INITIAL_REPEAT_HASH_SIZE;
    repeat_hash =
        (LispObject *)malloc(repeat_hash_size*sizeof(repeated_object));
    if (repeat_hash == NULL)
    {   printf("\n+++ unable to allocate repeat hash\n");
        abort();
    }
// If the key field contains 0 that means the entry is not in use.
    repeat_count = repeat_hash_size;
    do
    {   repeat_hash[--repeat_count].x = fixnum_of_int(0);
        repeat_hash[repeat_count].index = 0;
    } while (repeat_count != 0);
}

// I can not be certain at the start how many repeated objects will be
// found, so I may need to expand my hash table and heap while I am
// getting ready to write a heap image. This procedure (roughly) doubles
// the size of the tables and re-hashes data.
// I might comment on my expectation re performance here. Let me start by
// assuming that the (very crude) hash function works well enough - and
// because the items being hashed are basically memory addresses with
// it being improbable that there are heavy patterns to them.
// Suppose (unreasonably pessimistically) that I allowed the table to get
// totally full before I re-hashed it:
// Inserting k items into a new hash table of size 2k has a predicted cost
// of around 1.7 probes per insertion - the early ones only ever need 1
// probe because the table starts off empty, so my cost ends up as
// 1 - log(1/2). But here the table will always be exactly half full, and
// that means I predict that I would need 3 probes per insert. Two for the
// (failing) lookup to see it the item was already present and a final one
// that achieves the insertion. That seems acceptable to me, especially
// since this only happens during the process or writing a heap image.

void writer_expand_repeats()
{
    int o = repeat_heap_size;
    repeat_heap_size *= 2;
    repeat_heap =
        (LispObject *)realloc(repeat_heap_size*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   printf("\n+++ unable to expand repeat heap\n");
        abort();
    }
    while (o < repeat_heap_size) repeat_heap[o++] = fixnum_of_int(0);
// Now double the size of the hash table, rounding up to a number without
// any tiny factors. I am not going to the trouble to make it a prime, but I
// do go as far as avoiding factors of 13 because symbol headers may be 13 words
// long and that seems the largest chunk liable to be really common.
    o = repeat_hash_size;
    repeat_hash_size = (2*repeat_heap_size) | 1;
    while (repeat_hash_size % 3 == 0 ||
           repeat_hash_size % 5 == 0 ||
           repeat_hash+size % 7 == 0 ||
           repeat_hash_size % 11 == 0 ||
           repeat_hash_size % 13 == 0) repeat_hash_size += 2;
    repeat_hash =
        (LispObject *)realloc(repeat_hash_size*sizeof(repeated_object));
    if (repeat_hash == NULL)
    {   printf("\n+++ unable to allocate repeat hash\n");
        abort();
    }
// If the key field contains 0 that means the entry is not in use.
    repeat_count = repeat_hash_size;
    while (o < repeat_hash_size)
    {   repeat_hash[o].x = fixnum_of_int(0);
        repeat_hash[o].index = 0;
        o++;
    }
// Now I need to re-hash stuff. This code can leave tombstones in the table.
    for (o=0; o<repeat_hash_size; o++)
    {   LispObject x = repeat_hash[o].x, y;
        int h;
        if (is_fixnum(x)) continue; // an unused slot
        h = (int)((uintptr_t)x % (uintptr_t)repeat_hash_size);
        while ((y = repeat_hash[h].x) != x &&
               !is_fixnum(y)) h = (h + 1) % repeat_hash_size;
        repeat_hash[o].x = fixnum_of_int(1); // tombstone.
        repeat_hash[h].x = x;
    }
}

// Given an index 1, 2, ... find the item that was referred to recently
// that is identified by that index, and apply a move to the front
// process that should lead to a significant proportion of these accesses
// being in the range 1..64.
// NOTE that index value zero is not used.

LispObject reader_repeat_old(int n)
{
    if (n <= 64) return repeat_heap[n];
    for (;;)
    {   int n2 = n/2;           // parent in binary heap
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

void add_to_repeat_hash(LispObject x)
{
// The hash key is the raw representation of a LispObject. I expect its
// low 3 or 4 bits to be far from "random" - to be specific I expect that
// the bottom 4 bits of almost all repeated objects will be TAG_SYMBOL
// because I expect repeated references to symbols to be really common.
// But if I take the remainder by the size of my hash table and that does
// not have any small factors then I can hope to get acceptable distribution.
// I do the remainder operation using unsigned arithmetic so I can guarantee
// that the hash value I end up with is positive.
    int h = (int)((uintptr_t)x % repeat_hash_size);
    int firsth = -1;
// Only sharable items can appear as repeats, so fixnums can be used to
// indicate empty shots. I will use 0 for a truly empty slot and 1 for a
// tombstone where I deleted item had been. 
    for (;;)
    {   LispObject w;
        if ((w = repeat_hash[h].x) == x) return; // already present
// If I see a tombstone I remember the first such that I come across since if
// I end up inserting that is the location I should use.
        else if (w == fixnum_of_int(1) && firsth == -1) firsth = h;
        else if (w == fixnum_of_int(0))
        {   if (firsth != -1) h = firsth;
            repeat_hash[h].x = x;
// Count how many entries there are in the repeat table and as necessary expand
// the structures used to track data.
            repeat_count++;
            if (repeat_count == repeat_heap_size)
                writer_expand_repeats();
            return;
        }
        h = (h + 1) % repeat_hash_size;;
    }
}

// Check if an item is in the repeat-hash, and if so return the location
// in the table for it. Return -1 if it is not present

int check_repeat_hash(LispObject x)
{
    int h = (int)((uintptr_t)x % repeat_hash_size);
    for (;;)
    {   LispObject w;
        if ((w = repeat_hash[h].x) == x) return h; // present
        else if (w == fixnum_of_int(0)) return -1; // not present
        h = (h + 1) % repeat_hash_size;;
    }
}

// Given the location in the repeats hash table of an item that I want to
// dump, work out where it will live. Note that repeat_count will be zero
// at the start of dumping an image, and that the updating of repeat_heap
// here must match that done in the reading code. I return the location that
// the item was before the move-to-front operation. I can use this when a
// new item is to be entered in the repeat heap.

int find_index_in_repeats(int h)
{
    int n = repeat_hash[h].index;
// if n == 0 then this is the first time we have seen this item. So it
// needs to be inserted into repeat_hash.
    if (n == 0)
    {   n = ++repeat_count;
        repeat_hash[n].index = h;
    }
// I now need to perform the same move-to-top operation that will be performed
// during reading. But as I do so I will need to update values in the repeat_heap
// so it can point to where any particulat item will be.
    if (n <= 64) return n;
    h = n;
    for (;;)
    {   int n2 = n/2;           // parent in binary heap
        LispObject w = repeat_heap[n];
        repeat_heap[n] = repeat_heap[n2];
        repeat_hash[repeat_heap[n2]].index = n;
        repeat_heap[n2] = w;
        repeat_hash[w].index = n2;
        if (n2 == 1) return h;  // item has been moved to front
        n = n2;
    }
}


static uint8_t sample[] =
{
// This sequence should represent (1 . -2)
    1,                          // size of shared reference heap
    SER_CONS,                   // a cons cell
    SER_FIXNUM + 1,             // 1
    SER_FIXNUM + ((-2) & 0x1f)  // -2
};

static uint8_t *samplep = &sample[0];

int nextByte()
{
    return *samplep++;
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
// This is issues just after a SER_VECTOR or SER_SYMBOL (etc) code that will
// have left pbase referring to the object just allocated.
        reader_repeat_new(pbase);
        goto down;
    case SER_POSFIXNUM:
// This case really needs to read the 64-bit value and construct either a fixnum
// or a boxnum as relevant. If it creates a boxnum then that could possibly be
// a shared object, and against the possibility of that I set pbase so that a
// SER_DUP opcode can behave meaningfully.
        pbase = *p = fixnum_of_int(readPacked());
        goto up;
    case SER_NEGFIXNUM:
// Negative (small to medium-sized) integers are given a separate code here beause
// packing then using sign-and-magnitude seems easier. The extra "-1" here is both
// to avoid having the duplicated case of +0 and -0 and to arrange that the set of
// values that pack into a given number of bytes matches 2s complement. Eg with just
// 1 following byte the range goes from -128 to +127 (rather than -127 to +127).
        pbase = *p = fixnum_of_int(-1-readPacked());
        goto up;
    case SER_RAWSYMBOL:
// SER_RAWSYMBOL is used while dumping complete heap-images. The opcode here
// is followed by information to go into the header word of the symbol (various
// flag bits such as whether the symbol is global or fluid), then a dump of
// information about what goes in the function call and count components. After
// that all the list-like components will be transmitted (much as if they were
// elements in a vector).
    case SER_SYMBOL:
// SER_SYMBOL is for when a single expression is being dumped. After this
// opcode comes information as to whether the symbol is a gensym or not, then the
// length of its name and a seqence of bytes giving its name. The reader will
// in general look that name up in the oblist. Such information as what is on the
property list and what is in the value cell is not transmitted at all.
    case SER_FLOAT28:
// A 28-bit short float
    case SER_FLOAT32:
// a 32-bit sungle float
    case SER_FLOAT64:
// a 64-bit (long) float
    case SER_FLOAT128:
// a 128-bit (double-length) float. Note that this may not use all
// 128 bits and that cross-platform compatibility for floats of over 64
// bits is really very uncertain at present!
    case SER_CHAR:
// a packed characters literal. Characters that are Basic Latin can be coded
// here with just 2 bytes, so for instance 'A' is SER_CHAR/0x41. Codes up to
// U+3fff come in 3 bytes and so on. Note that the encoding is NOT utf8 - it is
// the variable length encoding
    case SER_SPID:
    case SER_BITVEC:

    case SER_XXX0f:
    case SER_XXX10:
    case SER_XXX11:
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
        w = *p = getvec(type, n);
// vectors chain through the first entry. If a vector was empty so it did not
// have a first entry to use here it would have needed to be dumped as a LEAF.
        elt(w, 0) = b;
        b = w;
        s = cons(fixnum_of_int(n), s);
        pbase = b;
        p = &elt(b, n);
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
    case SER_STRING:
// String will be very much like BVECTOR except that because I expect it to be an
// espcially important case I pack a length code into the 5-bit field of the
// opcode byte and the type information is implicit. This code only copes
// with strings with length 1-32.
        w = (c & 0x1f) + 1;
// The variable w holds the length in terms of 8-bit bytes. Within the Lisp
// system two bits of this need to end up being part of the type field of the
// header while the rest goes into the "length-in-32-bit-words" part. The
// adjustments here seem ugly and a real portability risk - but are the best I
// can see to use right at present.
        c = (TYPE_STRING1>>(Tw+2)) + (((w-1)&0x3) << 3);
        w = (w + 3)/4;
        goto bvecstring;
// I had considered having a special opcode to deal with strings of length 0
// or longer than 33, but in fact the general SER_BVECTOR code does just that
// slighly more efficiently then I would otherwise manage. Observe that the
// a SER_BVECTOR followed by 1 byte of length code copes with any vector needing
// up to 127 words (ie 508 bytes) with just 2 bytes of control information.
    case SER_BVECTOR:
// The general case for vectors containing binary information takes a suffix-
// sequence showing how many 4-byte units follow. Observe that this means that
// strings and vectors of 8 or 16-bit values have to be padded out to a 4-byte
// boundary in the dump sequence.
        c = c & 0x1f;
        w = readPacked();
    bvecstring:
// Here I have kept just the low 5 bits of the opcode c, and w is a length
// expressed in words. The header I want for my vector will be
//     wwwwwwww....wwww ccccc 01 g100
        Create space
        pbase = *p = ...
        read w 4-byte units into the array just allocated
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
    n = qcar(s) - 1;  // so to speak! qcar(s) will be tagged data!
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
    qcar(s) = n; // write back decreased index
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
// transcript of what there is...

void write_byte(int byte, const char *msg, ...)
{
    va_list a;
    printf("%.2x: ", byte);
    va_start(a, msg);
    vprintf(msg, a);
    printf("\n");
    va_end(a);
}

// write_64 needs to be compatible with readPacked.

void write_64_sub(uint64_t n)
{
    if (n <= 0x7f)
    {   write_byte((int)n, "7 bits unsigned value");
        return;
    }
    write_64_sub(n>>7);
    write_byte((int)n & 0x7f, "low 7 bits");
}

// Write a 64-bit unsigned value in a format compatible with readPacked()

void write_64(uint64_t n)
{
    int i, any=0, final = 7;
    if (n == (n & 0x7f))
    {   write_byte(n | 0x80, "7 bit integer");
        return;
    }
    if ((n & UINT64_C(0xff000000000000)) != 0) final = 8;
    for (i=8; i>0; i--)
    {   int b = (n >> (7*i+final)) & 0x7f;
        if (any || (b != 0))
        {   any = 1;
            write_byte(b, "7 bits of a big value");
        }
    }
    if (final == 7) write_byte(0x80 | (n & 0x7f), "least significant 7 bits");
    else write_byte(n & 0xff, "least significant 8 bits");
}

// The code here requires that repeat_hash has been created by a previous
// use of scan_data.

void write_data(LispObject p)
{
    LispObject b = 0 + BACKPOINTER_CDR, w;
    uintptr_t len;
    Header h;
    int i;
down:
    if (p == 0) p = SPID_NIL; // reload as a SPID.
    switch (p & TAG_BITS)
    {
    default:
    case TAG_CONS:
        if ((i = check_repeat_hash(p)) != -1)
        {   if (repeat_hash[i].index != 0)
            {   int n = find_index_in_repeats
                goto up;
            }
        }
        write_byte(SER_CONS, "cons");
        if (i == -1)
        {   write_byte(SER_RECORD, "Record item that will be re-used");
// This will see that this was the first visit to this item and insert
// it into the repeat heap at the top.
            find_index_in_repeats(i);
        }
        mark_address_as_used(p - TAG_CONS);
        w = p;
        p = qcar(p);
        qcar(w) = b;
// Reverse pointers with the back-pointer being tagged with 0
        b = w - TAG_CONS + BACKPOINTER_CAR;
        goto down;

    case TAG_SYMBOL:
        if (address_used(p - TAG_SYMBOL))
        {   write_repeat(p);
            goto up;
        }
        write_byte(SER_SYMBOL, "symbol header");
// Here I need to cope with the tagging bits and function cells, and
// the count field... Each of these uses a variable length coding scheme that
// will be 1 byte long in easy cases but can cope with 2^64 possibilities in
// all if necessary.
        write_64((uint64_t)qheader(p)>>(Tw+4));
        for (i=0; i<=4; i++)
            write_64(code_up_codepointer(*(void **)&qfn0(p)[i]));
        write_64(qcount(p));
        mark_address_as_used(p - TAG_SYMBOL);
        w = p;
        p = qpackage(p);
        qpackage(w) = b;
        b = (LispObject)&qpackage(w) + BACKPOINTER_SYMBOL;
        goto down;

    case TAG_VECTOR:
        if (address_used(p - TAG_VECTOR))
        {   write_repeat(p);
            goto up;
        }
        (*first_visit)(p);
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
        {   write_repeat(p);
            goto up;
        }
        (*first_visit)(p);
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
        {   write_repeat(p);
            goto up;
        }
        (*first_visit)(p);
        mark_address_as_used(p - TAG_BOXFLOAT);
// A boxed float never contains further pointers, so there is no more
// to do here.
        goto up;

    case TAG_FIXNUM:
    case TAG_HDR_IMMED:
// Immediate data (eg small integers, characters) will always be treated
// as if this is the first visit.
        (*first_visit)(p);
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

#endif    //EXPERIMENT

// end of serialize.cpp
