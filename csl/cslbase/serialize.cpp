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

// This is code that serilaises and deserialises Lisp data - up to and
// including a complete heap image. It may in duie course become a
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
// item individually. I will take a position that one can only dump a heap
// image when memory is not seriously full, and I will HOPE that the new
// reading code will not be over-expensive. There are potential worries
// about recursion depth in all this.

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
// printed. The average string length in that situation was 22 bytes.

// I will have a byte-coded instruction set that describes a structure that
// is to be constructed. It will be based on having a 3-bit opcode in each
// byte 

#define SER_OPBITS   0xe0     // top 3 bits of byte are major opcode

#define SER_VARIOUS  0x00     // a bunch of 32 "miscellaneous" codes
#define   SER_RAWSYMBOL   0x00    // a symbol
#define   SER_SYMBOL      0x01    // a symbol, but intern it as you read
#define   SER_BIGBACKREF  0x02    // reference more than 64 items ago
#define   SER_BIGFIXNUM   0x03    // smallish integer but outside -16..+15
#define   SER_FLOAT28     0x04    // short float
#define   SER_FLOAT32     0x05    // single float
#define   SER_FLOAT64     0x06    // double float
#define   SER_FLOAT128    0x07    // long float
#define   SER_CHAR        0x08    // character object
#define   SER_SPID        0x09    // "special identifier"
#define   SER_CONS        0x0a    // cons cell
#define   SER_RECORD      0x0b    // current item will have multiple references

// The ones from here on have not yet been allocated
#define   SER_XXX1        0x0c
#define   SER_XXX2        0x0d
#define   SER_XXX3        0x0e
#define   SER_XXX4        0x0f
#define   SER_XXX5        0x10
#define   SER_XXX6        0x11
#define   SER_XXX7        0x12
#define   SER_XXX8        0x13
#define   SER_XXX9        0x14
#define   SER_XXX10       0x15
#define   SER_XXX11       0x16
#define   SER_XXX12       0x17
#define   SER_XXX13       0x18
#define   SER_XXX14       0x19
#define   SER_XXX15       0x1a
#define   SER_XXX16       0xab
#define   SER_XXX17       0x1c
#define   SER_XXX18       0x1d
#define   SER_XXX19       0x1e
#define   SER_XXX20       0x1f

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
#define SER_XXXX     0xe0


// For a full Reduce image there are around 7000 items that have multiple
// references to the. I will allow for that many initially but arrange that
// I could expand the tables that I use if somebody ended up with a messier
// heap image. I ought to think about garbage collection safety here, even
// though I expect that during heap dumping and restoring I do not want that
// to intrude.
// Well my initial version of the code will use fixed sizes and will not be
// GC safe.

typedef struct _repeated_object
{
    LispObject x;
    int32_t index;
} repeated_object;

#define REPEAT_HASH_SIZE 15013    // This is a prime
#define REPEAT_HEAP_SIZE 10000

repeated_object repeat_hash[REPEAT_HASH_SIZE];


LispObject repeat_heap[REPEAT_HEAP_SIZE];
int repeat_count = 0;

// Given an index 1, 2, ... find the item that was referred to recently
// that is identified by that index, and apply a move to the front
// process that should lead to a significant proportion of these accesses
// being in the range 1..64.
// NOTE here that index value zero is use dto indicate "not present".

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
// But if I take the remainder by the size of my hash table and that is
// prime (or at least not a multiple of 16?) I can hope to get acceptable
// distribution. I do the remainder operation using unsigned arithmetic
// so I can guarantee that the hash value I end up with is positive.
    int h = (int)((uintptr_t)x % REPEAT_HASH_SIZE);
// Only sharable items can appear as repeats, so fixnum_of_int(0) can be
// used to indicate empty shots.
    for (;;)
    {   LispObject w;
        if ((w = repeat_hash[h].x) == x) return; // already present
        else if (w == fixnum_of_int(0))
        {   repeat_hash[h].x = x;
            repeat_hash[h].index = 0; // not yet in use
            return;
        }
        h++;
        if (h == REPEAT_HASH_SIZE) h = 0;
    }
}

// Check if an item is in the repeat-hash, and if so return the location
// in the table for it. Return -1 if it is not present

int check_repeat_hash(LispObject x)
{
    int h = (int)((uintptr_t)x % REPEAT_HASH_SIZE);
    for (;;)
    {   LispObject w;
        if ((w = repeat_hash[h].x) == x) return h; // present
        else if (w == fixnum_of_int(0)) return -1; // not present
        h++;
        if (h == REPEAT_HASH_SIZE) h = 0;
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


// Before final planning of the code that dumps structures I will set
// up the scheme that reads them.

#ifdef READER_READY_TO_TRY

int nextCommand()
{
    return X_LEAF;
}

LispObject serial_read()
{
    LispObject *p;    // a pointer to where to put the next item
    LispObject r,     // result of the entire reading process
               pbase, // needed to make the code GC safe
               w,     // working variable
               s,     // a (linked) stack used with vectors
               b;     // a back-pointer chain
    pbase = r = s = b = fixnum_of_int(0);
    p = &r;
down:
// nextCommand() needs to read from the stream representation of things
// and return a code... In this initial sketch I will only need to look
// at three cases. One is for CONS which is sort of obvious. The next is
// VECTOR. This covers all the cases where there are pointers within the
// object, including symbols and rational and complex numbers. The final
// case is LEAF which will include immediate data such as FIXNUMS, but
// alse big-numbers, strings and back-references to previously-read
// structures.
    switch (nextCommand())
    {
    case X_CONS:
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
    case X_VECTOR:
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
// nextCommand() must also deliver information on the type and the size
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
// vectors chain through the first entry. IF a vector was empty so it did not
// have a first entry to use here it would have needed to be dumped as a LEAF.
        elt(w, 0) = b;
        b = w;
        s = cons(fixnum_of_int(n), s);
        pbase = b;
        p = &elt(b, n);
        goto down;

    case X_LEAF:
// Note that if the leaf is a vector containing binary I may need
// to garbage collect here, so reasoning as for VECTOR applies.
        *p = leafValue;   // whatever the leaf is.
        goto up;
    default:
        ERROR;
    }

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

#endif // READER_READY_TO_TRY


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

void write_64u_sub(uint64_t n)
{
    if (n <= 0x7f)
    {   write_byte((int)n | 0x80, "most significant 7 bits");
        return;
    }
    write_64u_sub(n>>7);
    write_byte(((int)n & 0x7f) | 0x80, "intermediate 7 bits");
}

void write_64u(uint64_t n)
{
// Write an unsigned value that is up to 64-bite wide. Write out
// most significant bits first, because I feel that that makes the
// reading code easier, and it also makes the treatment of signed
// values (as in write_64) nicer.
    if (n <= 0x7f)
    {   write_byte((int)n, "7 bits unsigned value");
        return;
    }
    write_64u_sub(n>>7);
    write_byte((int)n & 0x7f, "low 7 bits");
}

void write_64_sub(int64_t n)
{
    if (-0x40 <= n && n <= 0x3f)
    {   write_byte(((int)n & 0x7f) | 0x80, "most significant 7 (signed) bits");
        return;
    }
// For signed values I shift right by 7 places using an exact division
// so I keep clear of isses of C++ not defining the semantics of right shifts
// on unsigned values. But I REALLY expect to be using twos complement
// arithmetic here.
    write_64_sub((n - (n & 0x7f))/128);
    write_byte(((int)n & 0x7f) | 0x80, "intermediate 7 bits");
}

void write_64(int64_t n)
{
// Write an signed value that is up to 64-bite wide.
    if (-0x40 <= n && n <= 0x3f)
    {   write_byte((int)n & 0x7f, "7 bits signed value");
        return;
    }
    write_64_sub((n - (n & 0x7f))/128);
    write_byte((int)n & 0x7f, "low 7 bits");
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
        write_64u((uint64_t)qheader(p)>>(Tw+4));
        for (i=0; i<=4; i++)
            write_64u(code_up_codepointer(*(void **)&qfn0(p)[i]));
        write_64u(qcount(p));
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
