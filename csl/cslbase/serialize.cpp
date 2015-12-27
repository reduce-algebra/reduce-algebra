// serialize.cpp                      Copyright (C) 1990-2015 Codemist Ltd


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
// desribe Lisp data and generating or accepting such a stream. Dumping an
// image this way involves setting up tables to record which bits of data
// have been seen before. Reading the stream involves constructing each
// item individually. I will take a position that one can only dump a heap
// image when memory is not seriously full, and I will HOPE that the new
// reading code will not be over-expensive. There are potential worries
// about recursion depth in all this.

#include "headers.h"

#ifdef EXPERIMENT

// Codes for use in my (custom) serialisation format.

// I make special provision for references to 64 things. I will use
// this for the first 48 things used at all and the 16 most recent ones.

#define X_REFn      0x00

#define X_BREAK1    0x40

// The next bunch are optimisations for common cases when the
// length code is short. The length code is folded into the main byte. Thus
// (eg) symbols whose name is from 0 to 15 characters long are dealt with
// especially neatly.

#define X_SYMn      0x40    // symbol with 0 to 15 chars
#define X_UNDEFn    0x50    // symbol (0-15), not a function
#define X_GENSYMn   0x60    // gensym with 0 to 15 bytes
#define X_LIST      0x70    // list with 0 to 15 items: (LIST)  NIL
#define X_LISTX     0x80    // like (LIST* ..) with 1-16 items then tail
#define X_INTn      0x90    // integer with 0 to 15 bytes
#define X_STRn      0xa0    // string, 0 to 15 chars

#define X_BREAK2    0xb0

#define X_REF       0xb0    // refer to a previously mentioned item
#define X_REFBACK   0xb4    // (only 1 and 2 byte versions used)
#define X_INT       0xb8    // LispBigInteger represented by an array
#define X_STR       0xbc    // Strings
#define X_SYM       0xc0    // Symbol with given name
#define X_UNDEF     0xc4    // Symbol (not a function)
#define X_UNDEF1    0xc8    // disembodied undefined function
#define X_GENSYM    0xcc    // a gensym or other uninterned name
#define X_BPS       0xd0    // "binary code" ha ha ha.
#define X_VEC       0xd4    // a Lisp vector
// perhaps X_INT with a short-enough operand could be used for X_FIXNUM
// as a rationalisation here.
#define X_FIXNUM    0xd8    // 1, 2, 3 or 4-byte small integer

//  0xdc spare at present

#define X_BREAK3    0xe0

// The final collection of codes are all one-byte incidental ones and
// the amount of any associated data is implicit in them. Eg X_DOUBLE will
// be followed by 8 bytes that represent a double-precision floating point
// value. X_FNAME is followed by a single length byte (n) then n characters.

#define X_NULL      0xe0    // empty cell
#define X_DOUBLE    0xe1    // double-precision number
#define X_STREAM    0xe2    // an open file (not dumpable)
#define X_FNAME     0xe3    // built-in function
#define X_SPECFN    0xe4    // built-in special form
#define X_STORE     0xe5    // the next item will be re-used
#define X_HASH      0xe6    // EQ hash
#define X_HASH1     0xe7    // EQL hash (not used)
#define X_HASH2     0xe8    // EQUAL hash
#define X_HASH3     0xe9    // EQUALS hash (not used)
#define X_HASH4     0xea    // EQUALP hash (not used)
#define X_ENDHASH   0xeb    // end of data for hash table
#define X_AUTOLOAD  0xec    // autoloading fn def
#define X_SPID      0xed    // internal marker
#define X_DEFINMOD  0xee    // "define-in-module" in fasl files
#define X_INTERP    0xef    // interpreted code
#define X_MACRO     0xf0    // interpreted macro
#define X_CALLAS    0xf1    // simple tail-call object
#define X_RECENT    0xf2    // used in FASL but not checkpoints
#define X_RECENT1   0xf3    // used in FASL but not checkpoints
#define X_OBLIST    0xf4    // oblist vector
#define X_VECxx     0xf5    // vector of 8, 16 or 32-bit integers

#define     XX_VEC8    0    // tag after X_VECxx for VEC8
#define     XX_VEC16   1    // for VEC16
#define     XX_VE32    2    // for VEC32
#define     XX_VEC64   3    // for VEC64
#define     XX_VECF    4    // for VEC of floats
#define     XX_VECD    5    // for VEC of doubles
#define     XX_VECs1   6    // (spare)
#define     XX_VECs2   7    // (spare)

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
// all. It seems tidiest to just retain the general code.

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
    void *p = malloc(512*sizeof(void *));
    if (p == NULL)
    {   fprintf(stderr, "\nFatal error - no memory\n");
        exit(1);
    }     
    memset(p, 0, 512*sizeof(void *));
    return p;
}

static uint8_t *new_final_map_block()
{
    void *p = malloc(4096);
    if (p == NULL)
    {   fprintf(stderr, "\nFatal error - no memory\n");
        exit(1);
    }
    memset(p, 0, 4096);
    return (uint8_t *)p;
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

static void release_map()
{
    for (int i=0; i<1024; i++)
    {   release_map_1(used_map[i]);
        used_map[i] = NULL;
    }
}

// The code here is NOT AT ALL WORKING YET.

static void mark_used_cells(LispObject a)
{
    LispObject b = (LispObject)NULL;
    LispObject p = a, w;
descend:
    switch (p & TAG_BITS)
    {
    default:
    case TAG_CONS:
        if (address_used((int64_t)p)) goto ascend2;
        mark_address_as_used((int64_t)p);
        w = qcar(p);
        qcar(p) = b;   // put backpointer in CAR field
        b = p;
        p = w;
        goto descend;

    case TAG_FIXNUM:   // immediate data
        goto ascend;

    case TAG_HDR_IMMED:// immediate data
        goto ascend;

#ifndef EXPERIMENT
    case TAG_SFLOAT:   // immediate data
        goto ascend;
#endif

    case TAG_SYMBOL:
        if (address_used((int64_t)p)) goto ascend2;
        mark_address_as_used((int64_t)p);
// I may need extra cleverness here to control which field of the
// symbol I am descending through. I need a few spare bits!
        qvalue(p) = b; // put backpointer in VALUE field
        b = p;
        p = w;
        goto descend;

    case TAG_NUMBERS:
        if (address_used((int64_t)p)) goto ascend2;
        mark_address_as_used((int64_t)p);
// For bignums I can just ascend here. For rationals and complex values I
// must descend through the two components.
        numerator(p) = b;
        b = p;
        p = w;
        goto descend;

    case TAG_VECTOR:
        if (address_used((int64_t)p)) goto ascend2;
        mark_address_as_used((int64_t)p);
// For vectors with binary content I just ascend. For ones with pointers
// I will need to arrange to be able to track how far I have got!
        elt(p, 0) = b;
        b = p;
        p = w;
        goto descend;

    case TAG_BOXFLOAT:
        if (address_used((int64_t)p)) goto ascend2;
        mark_address_as_used((int64_t)p);
        goto ascend;
    }
ascend2:
    // put p in the "used at least twice" table if it is not already there.

ascend:
    if (b == (LispObject)NULL) return;
// climb back up the backpointer chain.
 
}

#endif    //EXPERIMENT

// end of serialize.cpp
