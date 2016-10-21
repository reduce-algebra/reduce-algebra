// serialize.cpp                                Copyright (C) 2016 Codemist


// $Id$


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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

//=========================================================================
//=========================================================================
//
// This is code that serializes and deserializes Lisp data - up to and
// including a complete heap image.
// It represents the new code that supports preserve/restart and checkpoint
// facilities in Lisp, and I may in the future use it as a replacement
// for the current "fasl" scheme, so that a common serialised representation
// is used everywhere. It could then also provide users who wanted it with
// a way to write Lisp structures to disc (or transmit them across a
// network) such that structure sharing and cyclic structures were supported.

// There are a collection of things in this code that represent various
// levels of planning and thought, so I will try to summarize them here
// so that one can then look to see how they interweave and one part of the
// code depends on another.
//
// I will serialize data into a bytestream that essentially describes it
// in prefix form. Thus a list (a b) will be treated as (a . (b . nil)) and
// sent as "CONS SYM 'a' CONS SYM 'b' SYM 'nil'". In the bytestream
// some codes are used with 3-bits of opcode and 5 of embedded data. For
// instance integers in the range -16 to +15 can be handled that way in
// a single byte. Looped and shared structures are handled by allowing the
// seruialised form to keep a record of selected items as they are read and
// then refer back to them. References to the most recent 32 such items can
// be done especially efficiently. A form of "move to front" buffering is
// used in the table of re-used items. This is organised as a binary heap
// (as in heapsort). When any entry is is accessed it is moved to the top
//  of the heap (taking log(n) steps if there are n items in the table of
// old objects).
//
// When integers or offsets or length information is required in the byte
// stream it is coded in a variable length format, where each byte holds
// 7 bits from the number, and the final one has its top bit set. As a
// special case if there have been 8 non-final bytes the one after that is
// assumed to be final and all 8 of its bits can be used. This scheme
// allows full 64-bit values to be encoded in at most 9 bytes.
//
// There could be problems if either reader or writer was written using
// C++ recursion, because stack use could become unreasonable. To cope with
// this they both use pointer-reversing schemes so that almost all of
// the information needed to cope with nesting is stored within the data
// structure that is being traversed. For vectors that hold references to
// Lisp data some extra space is required while reading, and this is
// provided using fresh cons cells. They could be collected onto a freelist
// for use when they were no longer needed, but at present I do not do that.
// The writing code can be certain that garbage collection could not happen
// in the middle of its work, so it can afford to leave pointers into the
// middle of vectors as it goes, so it does not need any extra space at all.
//
// The writer works in two passes. The first pass just has to identify and
// record where there are objects referenced multiple times. It uses a sparse
// bitmap to record which objects it has visited. When it finds that it is
// re-visiting an address it enters that in a hash table which in due course
// arranges the back-reference scheme mentioned earlier.
// The second pass then does not need the bitmap - it can be aware of and
// avoid cycles by inspecting the hash table of multiply-referenced iteme.
// This means it checks this table for every object it visits, and almost
// always the lookup will fail. This is kept fast by using Cuckoo hashing
// where each item in the table has only a few locations where it could live.
// So lookup in the table, successful or unsuccessful, only costs four
// probes, with these being in two pairs of consecutive words (which is
// a fairly cache-friendly way or arranging the search).
//
// Everything has to be written in a byte-order neutral format and re-read
// so that if the machine receiving the data uses a different byte order
// from the one creating it all is well. That is perhaps especially
// messy for floating point values, and it is not clear that there is a
// sane reliable interchange format for floats that are wider then 64 bits,
// so at present "long double" is not really supported. If I did not care
// about reading in serialized data on a machine different from the one it
// was written on there would not be an issue!
//
// I provide two rather different schemes for serializing symbols. The first
// is for user-level code and it treats a symbol pretty much as just its
// name. When the data is read back the string forming the name is looked
// up in the object list. Attributes (property list, value, function
// definition etc) are not considered. The only special case there is that
// of gensyms. In CSL a gensym that has not printed has just a stub as
// its name (often just "G"). When a gensym is first printed it gets
// allocated a sequence number and its name is expanded to something like
// "G0751". In the serialization code the stub of the name is recovered and
// included in the bye-stream along with a marker indicating that the
// symbol is a gensym. The effect is then the version that is read back has
// "not yet printed" status.
//
// The other treatment of symbols is for use when this code is checkpointing
// a running system. It treats symbols as merely a variation on vector or
// record style data. That means that all the componenent fields used
// in their implementation get serialized. A special challenge there is
// the function cells. For all built-in functions that is handled via
// a table that tabulates all their addresses.
//
// Lisp hash tables represent a jolly special case! After they have been
// passed to a different system the hash values of many objects may have
// changed. This can arise if, for instance, hash codes are based on
// a memory address or are sensitive to byte-order. I have two schemes
// that can help here.
// The existing old one was that after a new heap-image was re-loaded
// all hash tables got rehashed. To help with this the system maintains
// lists eq_hash_tables and equal_hash_tables.
// The new scheme is that during garbage collection and when re-read from a
// serialised form ant object that might have a header saying TYPE_NEWHASH
// has that updates to be TYPE_NEWHASHX where this new marker indicates a
// hash table whos eelements may not be in the correct locations. Then any
// operation on the hash table can check for TYPE_NEWHASHX and if it sees
// it re-hash and reset the table to TYPE_NEWHASH. If that strategy is
// followed it becomes unnecessary to keep any global list of hash tables.
// Note that the object list is a sort of hash table but its implementation
// may be separate from that for the more user-accessible ones - but the
// issues here neverthless apply. I intend to merge object list (ie package
// system) table maintenance with more general hash table support soon.
//
// There are a few types where I feel that serialization is probably never
// going to make sense. For instance open streams, references to foreign
// functions, ... and if at some stage a native compiler is created then
// native compiled code could transfer to machines of just the same
// flavour but not to others - but issues of position independence or
// code relocation tables would apply. To leave an opportunity to
// address some of those issues in the future, the serialization byte
// code has a number of unallocated codes left available for extension.

//=========================================================================
//=========================================================================

#include "headers.h"

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
// that will represent a somewhat bi-modal length distribution with short
// names for symbols and long(ish) ones for messages that get printed.


// I will have a byte-coded instruction set that describes a structure that
// is to be constructed. It will be based on having a 3-bit opcode in each
// byte

static bool descend_symbols = true;

#define SER_OPBITS   0xe0     // top 3 bits of byte are major opcode

#define SER_VARIOUS  0x00     // a bunch of 32 "miscellaneous" codes
#define   SER_RAWSYMBOL    0x00    // a symbol
#define   SER_DUPRAWSYMBOL 0x01    // a symbol, but will be referenced again
#define   SER_SYMBOL       0x02    // a symbol, but intern it as you read
#define   SER_DUPSYMBOL    0x03    // as above, but will be referenced again
#define   SER_GENSYM       0x04    // a gensym
#define   SER_DUPGENSYM    0x05    // a gensym that will be referenced again
#define   SER_BIGBACKREF   0x06    // reference more than 64 items ago
#define   SER_POSFIXNUM    0x07    // positive (or unsigned) 64-bit integer
#define   SER_NEGFIXNUM    0x08    // negative integer up to 63 bits
#define   SER_FLOAT28      0x09    // short float
#define   SER_FLOAT32      0x0a    // single float
#define   SER_FLOAT64      0x0b    // double float
#define   SER_FLOAT128     0x0c    // long float
#define   SER_CHARSPID     0x0d    // char object, "special identifier" etc
#define   SER_CONS         0x0e    // cons cell
#define   SER_DUPCONS      0x0f    // cons cell that is referred to multiple times
#define   SER_DUP          0x10    // used with items that have multiple references
#define   SER_BITVEC       0x11    // bit-vector
#define   SER_NIL          0x12    // the very special case of NIL
#define   SER_END          0x13    // a redundant marker for end of heap dump

#ifdef DEBUG_SERIALIZE
#define   SER_OPNEXT      0x14    // for debugging

static const char *ser_various_names[] =
{   "RAWSYMBOL",
    "DUPRAWSYMBOL",
    "SYMBOL",
    "DUPSYMBOL",
    "GENSYM",
    "DUPGENSYM",
    "BIGBACKREF",
    "POSFIXNUM",
    "NEGFIXNUM",
    "FLOAT28",
    "FLOAT32",
    "FLOAT64",
    "FLOAT128",
    "CHARSPID",
    "CONS",
    "DUPCONS",
    "DUP",
    "BITVEC",
    "NIL",
    "END",
    "op14",   // OPNEXT
    "op15"
    "op16",
    "op17",
    "op18",
    "op19",
    "op1a",
    "op1b",
    "op1c",
    "op1d",
    "op1e",
    "op1f"
};

#endif

// The ones from here on have not yet been allocated

// Ideas:   SER_SYMBOL_CONS        for     "sym "
//          SER_SYMBOL_NIL                 "sym)"
//          SER_CONS_SYMBOL_CONS           "(sym "
//          SER_DUPSYMBOL_CONS
//          SER_DUPSYMBOL_NIL
//          SER_CONS_DUPSYMBOL_CONS
//          SER_CONSCONS                   "(("
//          SER_CONS_CONS_CONS             "((("

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
// 64 most recent shared items in a single byte.
#define SER_BACKREF0 0x20     // reference to item 1 to 32 ago
#define SER_BACKREF1 0x40     // reference to item 33 to 64 ago
// I expect strings to be important enough that at least short ones have
// special treatment. The length-code here will stand for 1-32 not 0-31.
#define SER_STRING   0x60     // a string with 1-32 bytes
// very small integers perhaps also deserve help.
#define SER_FIXNUM   0x80     // integer -16 to +15
// In CSL header words have a 7-bit field that identifies the type
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
// cases where I have not yet thought hard enought! At present the only idea
// I have for this is "SER_CONS_BACKREF" to correspond to the sequence
// of SER_CONS followed by a backref to one of the last 32 items. This
// is not terribly compelling! So I will not use this code for now in case a
// more pressing use emerges leter on.
#define SER_SPARE    0xe0

#ifdef DEBUG_SERIALIZE

static const char *ser_opnames[] =
{   "misc",
    "BACKREF0",
    "BACKREF1",
    "STRING",
    "FIXNUM",
    "LVECTOR",
    "BVECTOR",
    "SPARE"
};

static void ser_print_opname(int n)
{   int top = (n >> 5) & 0x7;
    if (top == 0) fprintf(stderr, "%s", ser_various_names[n & 0x1f]);
    else fprintf(stderr, "%s %d", ser_opnames[top], n & 0x1f);
}

#endif

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
// During reading I will allow garbage collection to happen.
// I rather do not expect it to when re-loading a fresh heap-image,
// but the code here can also be used in the middle of running
// perfectly ordinary code to serialize data so it is stored compactly
// on disc. Indeed this may end up replacing the previous "fasl" format
// that I had.
//
// WARNING. I have not put in the extra lines of code needed to make
// everything garbage collector safe - sometime I need to review this
// code and do that.

// I will need a hash table that records information about items in the
// heap that are visited several times. I use the one from inthash.cpp.

static inthash repeat_hash;
LispObject *repeat_heap = NULL;
size_t repeat_heap_size = 0, repeat_count = 0;

// This tiny function exists just so that I can set a breakpoint on it.
void myabort()
{   fflush(stdout);
    fflush(stderr);
    abort();
}

void reader_setup_repeats(size_t n)
{   if (repeat_heap_size != 0 ||
        repeat_heap != NULL)
    {   fprintf(stderr, "\n+++ repeat heap processing error\n");
        myabort();
    }
    repeat_heap_size = n;
    repeat_count = 0;
    if (n == 0) return; // No repeats present, so not table needed.
    repeat_heap = (LispObject *)malloc((n+1)*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   fprintf(stderr, "\n+++ unable to allocate repeat heap\n");
        myabort();
    }
// I fill the vector with fixnum_of_int(0) so it is GC safe.
    for (size_t i=0; i<n; i++)
        repeat_heap[--n] = fixnum_of_int(0);
}

void writer_setup_repeats()
{   repeat_heap_size = repeat_hash.count;
    repeat_count = 0;
    repeat_heap =
        (LispObject *)malloc((repeat_heap_size+1)*sizeof(LispObject));
    if (repeat_heap == NULL)
    {   fprintf(stderr, "\n+++ unable to allocate repeat heap\n");
        myabort();
    }
}

// Given an index 1, 2, ... find the item that was referred to recently
// that is identified by that index, and apply a move to the front
// process that should lead to a significant proportion of these accesses
// being in the range 1..64.
// NOTE that index value zero is not used.
//
// The implementation here uses a binary heap as a priority queue
// so that in there are N items in it bringing something to the top
// costs log(n) steps. This is intended to be a compromise between
// a scheme that brings each referenced item to the front demoting
// all other items one place (and having linear cost per access) and
// not using move-to-front at all.

LispObject reader_repeat_old(size_t n)
{   if (n == 1) return repeat_heap[1];
    LispObject w;
    for (;;)
    {   size_t n2 = n/2;           // parent in binary heap
        w = repeat_heap[n];
        repeat_heap[n] = repeat_heap[n2];
        repeat_heap[n2] = w;
        if (n2 == 1) break;  // item has been moved to front
        n = n2;
    }
    return w;
}

// Given an item that is now seen for the first time but that it is known
// will be referenced again later, add it to the repeat table and if
// it falls beyond the first 64 bring it to the first position.

LispObject reader_repeat_new(LispObject x)
{   repeat_heap[++repeat_count] = x;
    return reader_repeat_old(repeat_count);
}

// There are two phases involved when writing out data. One merely
// inserts items into the hash table of repeats and makes it possible
// to check for this. This is needed because until all data has
// been scanned one can not tell if there will be a second reference to
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
{   size_t n = hash_get_value(&repeat_hash, h);
// if n == 0 then this is the first time we have seen this item. So it
// needs to be inserted into repeat_hash.
    if (n == 0)
    {   n = ++repeat_count;
        repeat_heap[n] = h;
        hash_set_value(&repeat_hash, h, n);
    }
    if (n == 1) return 1;
// I now need to perform the same move-to-top operation that will be performed
// during reading. But as I do so I will need to update values in the
// repeat_hash so that I can still find the moved items.
    h = n;
    for (;;)
    {   size_t n2 = n/2;           // parent in binary heap
        LispObject w = repeat_heap[n];
        repeat_heap[n] = repeat_heap[n2];
        hash_set_value(&repeat_hash, repeat_heap[n2],  n);
        repeat_heap[n2] = w;
        hash_set_value(&repeat_hash, w, n2);
        if (n2 == 1) break;  // item has been moved to front
        n = n2;
    }
    return h;
}

// For testing I will put serialized data into a buffer... This is
// just a test harness and does not reflect what I will eventually need
// to do!

#define SERSIZE 4000000
int sercounter = 0;
int serincount = 0;
unsigned char serbuffer[SERSIZE];


int read_opcode_byte()
{   int r;
#ifdef DEBUG_SERIALIZE
// In this case each serialization opcode is prceeded by SER_OPNEXT. This
// should mean that if anything gets out of step because seruialzation
// data is malformed that this is noticed and reported promptly. Such failures
// either reflext internal inconsistency between the serialization read and
// write code or some corruption of data after writing but before reading.
    if (binary_read_file != NULL) r = Igetc();
    else
    {   if (serincount > sercounter)
        {   fprintf(stderr, "\nRead too much\n");
            myabort();
        }
        r = serbuffer[serincount++];
    }
    r &= 0xff;
    fprintf(stderr, "Read %d = %.2x ", r, r);
    if (r != SER_OPNEXT)
    {   fprintf(stderr, "\nExpected OPNEXT but did not find it\n");
        myabort();
    }
    else fprintf(stderr, "SER_OPNEXT\n");
#endif
    if (binary_read_file != NULL) r = Igetc();
    else
    {   if (serincount > sercounter)
        {   fprintf(stderr, "\nRead too much\n");
            myabort();
        }
        r = serbuffer[serincount++];
    }
    r &= 0xff;
#ifdef DEBUG_SERIALIZE
    fprintf(stderr, "Read %d = %.2x ", r, r);
    ser_print_opname(r);
    fprintf(stderr, "\n");
#endif
    return r;
}

int read_data_byte()
{   int r;
    if (binary_read_file != NULL) r = Igetc();
    else
    {   if (serincount > sercounter)
        {   fprintf(stderr, "\nRead too much\n");
            myabort();
        }
        r = serbuffer[serincount++];
    }
    r &= 0xff;
#ifdef DEBUG_SERIALIZE
    fprintf(stderr, "Read %d = %.2x\n", r, r);
#endif
    return r;
}

int read_string_byte()
{   int r;
    if (binary_read_file != NULL) r = Igetc();
    else
    {   if (serincount > sercounter)
        {   fprintf(stderr, "\nRead too much\n");
            myabort();
        }
        r = serbuffer[serincount++];
    }
    r &= 0xff;
#ifdef DEBUG_SERIALIZE
    fprintf(stderr, "Read %d = %.2x ", r, r);
    if (0x20 <= r && r <= 0x7f) fprintf(stderr, " = '%c'", r);
    fprintf(stderr, "\n");
#endif
    return r;
}


// I will arrange that the dumping code mostly prints out a human-readable
// transcript of what there is... That will not be useful for much more
// the debugging!

void write_opcode(int byte, const char *msg, ...)
{
#ifdef DEBUG_SERIALIZE
    va_list a;
    fprintf(stderr, "<opcode prefix> %.2x\n", SER_OPNEXT);
    if (binary_write_file != NULL) Iputc(SER_OPNEXT);
    else if (sercounter < SERSIZE) serbuffer[sercounter++] = SER_OPNEXT;
    fprintf(stderr, "%.2x: ", byte & 0xff);
    va_start(a, msg);
    vfprintf(stderr, msg, a);
    fprintf(stderr, "\n");
    va_end(a);
#endif
    if (binary_write_file != NULL) Iputc(byte);
    else if (sercounter < SERSIZE) serbuffer[sercounter++] = byte;
}

void write_byte(int byte, const char *msg, ...)
{
#ifdef DEBUG_SERIALIZE
    va_list a;
    fprintf(stderr, "%.2x: ", byte & 0xff);
    va_start(a, msg);
    vfprintf(stderr, msg, a);
    printf("\n");
    va_end(a);
#endif
    if (binary_write_file != NULL) Iputc(byte);
    else if (sercounter < SERSIZE) serbuffer[sercounter++] = byte;
}

// This reads from 1 to 9 bytes in a variable length encoding to make up an
// unsigned 64-bit value. The bytes represent the number most significant bits
// first, and if there are 1-8 of them the last one has its top bit set, but
// all the leading ones have their top bits clear. If there are 8 bytes all
// of which have their top bit zero then the final byte is treated as a full
// 8 bits.

uint64_t read_u64()
{   uint64_t r = 0;
    int b, i;
    for (i=0; i<8; i++)
    {   if (((b = read_data_byte()) & 0x80) != 0)
            return (r << 7)  | (b & 0x7f);
        r = (r << 7) | b;
    }
    return (r << 8) | read_data_byte();
}

// Write a 64-bit unsigned value in a format compatible with read_u64()

void write_u64(uint64_t n)
{   char msg[32];
    if (n == (n & 0x7f))
    {   sprintf(msg, "small int %#.2x = %d", (int)n, (int)n);
        write_byte(n | 0x80, msg);
        return;
    }
    int final = 7;
    bool any = false;
// There is a case here that has caught me out.
// A number with 57 bits (eg 0x01aabbbbccccdddd) needs 9 bytes to encode it,
// and these will be used for 7+7+7+7+7+7+7+8 bits apiece. Thus the leading
// byte will be all zero (because the final byte will use all 8 of its bits).
// So schemes that otherwise discard leading zeros must not do so in this
// particular situation!
    if ((n & UINT64_C(0xff00000000000000)) != 0)
    {   final = 8;
        any = true;
    }
    for (int i=0; i<8; i++)
    {   int b = (n >> (7*(7-i)+final)) & 0x7f;
        if (any || (b != 0))
        {   any = true;
            sprintf(msg, "%#" PRIx64, ((uint64_t)b) << (7*(7-i)+final));
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

// For the transport of floating point values I will suppose that for
// floats the only problem is that for some machines the byte order
// may be backwards. For doubles I will allow for both the possibility
// of ordering within each 32-bit word and ordering of the low and high
// order word of the whole number.
// I will evaluation the situation on the machine I am running on and
// act accordingly. This should already have been done, and current_fp_rep
// should give information!

// Note that the type-punning used here (even as against an array of char)
// seems to go beyond what C++ guarantees to support. I believe that at
// least at present gcc guarantees to treat it in a way where those of an
// old-fashioned recollection of "the spirit of C" will not be upset. So
// I hope that this will work.

typedef union _float32u
{   char i[4];
    float f;
} float32u;

float read_f32()
{   float32u u;
    if ((current_fp_rep & FP_BYTE_ORDER) == 0)
    {   u.i[0] = read_data_byte();
        u.i[1] = read_data_byte();
        u.i[2] = read_data_byte();
        u.i[3] = read_data_byte();
    }
    else
    {   u.i[3] = read_data_byte();
        u.i[2] = read_data_byte();
        u.i[1] = read_data_byte();
        u.i[0] = read_data_byte();
    }
    return u.f;
}

void write_f32(double f)
{   float32u u;
    u.f = f;
    if ((current_fp_rep & FP_BYTE_ORDER) == 0)
    {   write_byte(u.i[0], "part of float");
        write_byte(u.i[1], "part of float");
        write_byte(u.i[2], "part of float");
        write_byte(u.i[3], "part of float");
    }
    else
    {   write_byte(u.i[3], "part of float");
        write_byte(u.i[2], "part of float");
        write_byte(u.i[1], "part of float");
        write_byte(u.i[0], "part of float");
    }
}

typedef union _float64u
{   char i[8];
    double f;
} float64u;

double read_f64()
{   float64u u;
    for (int i=0; i<8; i+=4)
    {   int j = i;
        if ((current_fp_rep & FP_WORD_ORDER) != 0) j = j ^ 4;
        if ((current_fp_rep & FP_BYTE_ORDER) == 0)
        {   u.i[j+0] = read_data_byte();
            u.i[j+1] = read_data_byte();
            u.i[j+2] = read_data_byte();
            u.i[j+3] = read_data_byte();
        }
        else
        {   u.i[j+3] = read_data_byte();
            u.i[j+2] = read_data_byte();
            u.i[j+1] = read_data_byte();
            u.i[j+0] = read_data_byte();
        }
    }
    return u.f;
}

void write_f64(double f)
{   float64u u;
    u.f = f;
    for (int i=0; i<8; i+=4)
    {   int j = i;
        if ((current_fp_rep & FP_WORD_ORDER) != 0) j = j ^ 4;
        if ((current_fp_rep & FP_BYTE_ORDER) == 0)
        {   write_byte(u.i[j+0] , "part of double");
            write_byte(u.i[j+1] , "part of double");
            write_byte(u.i[j+2] , "part of double");
            write_byte(u.i[j+3] , "part of double");
        }
        else
        {   write_byte(u.i[j+3] , "part of double");
            write_byte(u.i[j+2] , "part of double");
            write_byte(u.i[j+1] , "part of double");
            write_byte(u.i[j+0] , "part of double");
        }
    }
}


float128_t read_f128()
{   float128_t r;
#ifdef LITTLEENDIAN
    r.v[0] = read_u64();
    r.v[1] = read_u64();
#else
    r.v[1] = read_u64();
    r.v[0] = read_u64();
#endif
    return r;
}

void write_f128(float128_t f)
{
#ifdef LITTLEENDIAN
    write_u64(f.v[0]);
    write_u64(f.v[1]);
#else
    write_u64(f.v[1]);
    write_u64(f.v[0]);
#endif
}

// At times I need to read and write values that are the entrypoints of
// functions that are defined in the kernel. I do this by referring back to
// the tables that originally set them up. A bad feature of the scheme I use
// here is that it makes serialized files that refer to functions specific
// to the particular ordering etc in those tables. If changes have been
// bade since the data was written things could fail. I will deal with that
// by using a (simple) checksum on the tables and insisting it matches as
// between reader and writer. The checksum is a 64-bit CRC - here is some
// code that computes same, starting with its author and copyright
// information:

/* Redis uses the CRC64 variant with "Jones" coefficients and init value of 0.
 *
 * Specification of this CRC64 variant follows:
 * Name: crc-64-jones
 * Width: 64 bites
 * Poly: 0xad93d23594c935a9
 * Reflected In: True
 * Xor_In: 0xffffffffffffffff
 * Reflected_Out: True
 * Xor_Out: 0x0
 * Check("123456789"): 0xe9c6d914c4b8d9ca
 *
 * Copyright (c) 2012, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. */

// #define __STDC_CONSTANT_MACROS 1
// #define __STDC_FORMAT_MACROS
// #include <stdint.h>
// Code layout adjusted bc ACN (using astyle) plus adaptations to fit C++
// rather than C.

static const uint64_t crc64_tab[256] =
{   UINT64_C(0x0000000000000000), UINT64_C(0x7ad870c830358979),
    UINT64_C(0xf5b0e190606b12f2), UINT64_C(0x8f689158505e9b8b),
    UINT64_C(0xc038e5739841b68f), UINT64_C(0xbae095bba8743ff6),
    UINT64_C(0x358804e3f82aa47d), UINT64_C(0x4f50742bc81f2d04),
    UINT64_C(0xab28ecb46814fe75), UINT64_C(0xd1f09c7c5821770c),
    UINT64_C(0x5e980d24087fec87), UINT64_C(0x24407dec384a65fe),
    UINT64_C(0x6b1009c7f05548fa), UINT64_C(0x11c8790fc060c183),
    UINT64_C(0x9ea0e857903e5a08), UINT64_C(0xe478989fa00bd371),
    UINT64_C(0x7d08ff3b88be6f81), UINT64_C(0x07d08ff3b88be6f8),
    UINT64_C(0x88b81eabe8d57d73), UINT64_C(0xf2606e63d8e0f40a),
    UINT64_C(0xbd301a4810ffd90e), UINT64_C(0xc7e86a8020ca5077),
    UINT64_C(0x4880fbd87094cbfc), UINT64_C(0x32588b1040a14285),
    UINT64_C(0xd620138fe0aa91f4), UINT64_C(0xacf86347d09f188d),
    UINT64_C(0x2390f21f80c18306), UINT64_C(0x594882d7b0f40a7f),
    UINT64_C(0x1618f6fc78eb277b), UINT64_C(0x6cc0863448deae02),
    UINT64_C(0xe3a8176c18803589), UINT64_C(0x997067a428b5bcf0),
    UINT64_C(0xfa11fe77117cdf02), UINT64_C(0x80c98ebf2149567b),
    UINT64_C(0x0fa11fe77117cdf0), UINT64_C(0x75796f2f41224489),
    UINT64_C(0x3a291b04893d698d), UINT64_C(0x40f16bccb908e0f4),
    UINT64_C(0xcf99fa94e9567b7f), UINT64_C(0xb5418a5cd963f206),
    UINT64_C(0x513912c379682177), UINT64_C(0x2be1620b495da80e),
    UINT64_C(0xa489f35319033385), UINT64_C(0xde51839b2936bafc),
    UINT64_C(0x9101f7b0e12997f8), UINT64_C(0xebd98778d11c1e81),
    UINT64_C(0x64b116208142850a), UINT64_C(0x1e6966e8b1770c73),
    UINT64_C(0x8719014c99c2b083), UINT64_C(0xfdc17184a9f739fa),
    UINT64_C(0x72a9e0dcf9a9a271), UINT64_C(0x08719014c99c2b08),
    UINT64_C(0x4721e43f0183060c), UINT64_C(0x3df994f731b68f75),
    UINT64_C(0xb29105af61e814fe), UINT64_C(0xc849756751dd9d87),
    UINT64_C(0x2c31edf8f1d64ef6), UINT64_C(0x56e99d30c1e3c78f),
    UINT64_C(0xd9810c6891bd5c04), UINT64_C(0xa3597ca0a188d57d),
    UINT64_C(0xec09088b6997f879), UINT64_C(0x96d1784359a27100),
    UINT64_C(0x19b9e91b09fcea8b), UINT64_C(0x636199d339c963f2),
    UINT64_C(0xdf7adabd7a6e2d6f), UINT64_C(0xa5a2aa754a5ba416),
    UINT64_C(0x2aca3b2d1a053f9d), UINT64_C(0x50124be52a30b6e4),
    UINT64_C(0x1f423fcee22f9be0), UINT64_C(0x659a4f06d21a1299),
    UINT64_C(0xeaf2de5e82448912), UINT64_C(0x902aae96b271006b),
    UINT64_C(0x74523609127ad31a), UINT64_C(0x0e8a46c1224f5a63),
    UINT64_C(0x81e2d7997211c1e8), UINT64_C(0xfb3aa75142244891),
    UINT64_C(0xb46ad37a8a3b6595), UINT64_C(0xceb2a3b2ba0eecec),
    UINT64_C(0x41da32eaea507767), UINT64_C(0x3b024222da65fe1e),
    UINT64_C(0xa2722586f2d042ee), UINT64_C(0xd8aa554ec2e5cb97),
    UINT64_C(0x57c2c41692bb501c), UINT64_C(0x2d1ab4dea28ed965),
    UINT64_C(0x624ac0f56a91f461), UINT64_C(0x1892b03d5aa47d18),
    UINT64_C(0x97fa21650afae693), UINT64_C(0xed2251ad3acf6fea),
    UINT64_C(0x095ac9329ac4bc9b), UINT64_C(0x7382b9faaaf135e2),
    UINT64_C(0xfcea28a2faafae69), UINT64_C(0x8632586aca9a2710),
    UINT64_C(0xc9622c4102850a14), UINT64_C(0xb3ba5c8932b0836d),
    UINT64_C(0x3cd2cdd162ee18e6), UINT64_C(0x460abd1952db919f),
    UINT64_C(0x256b24ca6b12f26d), UINT64_C(0x5fb354025b277b14),
    UINT64_C(0xd0dbc55a0b79e09f), UINT64_C(0xaa03b5923b4c69e6),
    UINT64_C(0xe553c1b9f35344e2), UINT64_C(0x9f8bb171c366cd9b),
    UINT64_C(0x10e3202993385610), UINT64_C(0x6a3b50e1a30ddf69),
    UINT64_C(0x8e43c87e03060c18), UINT64_C(0xf49bb8b633338561),
    UINT64_C(0x7bf329ee636d1eea), UINT64_C(0x012b592653589793),
    UINT64_C(0x4e7b2d0d9b47ba97), UINT64_C(0x34a35dc5ab7233ee),
    UINT64_C(0xbbcbcc9dfb2ca865), UINT64_C(0xc113bc55cb19211c),
    UINT64_C(0x5863dbf1e3ac9dec), UINT64_C(0x22bbab39d3991495),
    UINT64_C(0xadd33a6183c78f1e), UINT64_C(0xd70b4aa9b3f20667),
    UINT64_C(0x985b3e827bed2b63), UINT64_C(0xe2834e4a4bd8a21a),
    UINT64_C(0x6debdf121b863991), UINT64_C(0x1733afda2bb3b0e8),
    UINT64_C(0xf34b37458bb86399), UINT64_C(0x8993478dbb8deae0),
    UINT64_C(0x06fbd6d5ebd3716b), UINT64_C(0x7c23a61ddbe6f812),
    UINT64_C(0x3373d23613f9d516), UINT64_C(0x49aba2fe23cc5c6f),
    UINT64_C(0xc6c333a67392c7e4), UINT64_C(0xbc1b436e43a74e9d),
    UINT64_C(0x95ac9329ac4bc9b5), UINT64_C(0xef74e3e19c7e40cc),
    UINT64_C(0x601c72b9cc20db47), UINT64_C(0x1ac40271fc15523e),
    UINT64_C(0x5594765a340a7f3a), UINT64_C(0x2f4c0692043ff643),
    UINT64_C(0xa02497ca54616dc8), UINT64_C(0xdafce7026454e4b1),
    UINT64_C(0x3e847f9dc45f37c0), UINT64_C(0x445c0f55f46abeb9),
    UINT64_C(0xcb349e0da4342532), UINT64_C(0xb1eceec59401ac4b),
    UINT64_C(0xfebc9aee5c1e814f), UINT64_C(0x8464ea266c2b0836),
    UINT64_C(0x0b0c7b7e3c7593bd), UINT64_C(0x71d40bb60c401ac4),
    UINT64_C(0xe8a46c1224f5a634), UINT64_C(0x927c1cda14c02f4d),
    UINT64_C(0x1d148d82449eb4c6), UINT64_C(0x67ccfd4a74ab3dbf),
    UINT64_C(0x289c8961bcb410bb), UINT64_C(0x5244f9a98c8199c2),
    UINT64_C(0xdd2c68f1dcdf0249), UINT64_C(0xa7f41839ecea8b30),
    UINT64_C(0x438c80a64ce15841), UINT64_C(0x3954f06e7cd4d138),
    UINT64_C(0xb63c61362c8a4ab3), UINT64_C(0xcce411fe1cbfc3ca),
    UINT64_C(0x83b465d5d4a0eece), UINT64_C(0xf96c151de49567b7),
    UINT64_C(0x76048445b4cbfc3c), UINT64_C(0x0cdcf48d84fe7545),
    UINT64_C(0x6fbd6d5ebd3716b7), UINT64_C(0x15651d968d029fce),
    UINT64_C(0x9a0d8ccedd5c0445), UINT64_C(0xe0d5fc06ed698d3c),
    UINT64_C(0xaf85882d2576a038), UINT64_C(0xd55df8e515432941),
    UINT64_C(0x5a3569bd451db2ca), UINT64_C(0x20ed197575283bb3),
    UINT64_C(0xc49581ead523e8c2), UINT64_C(0xbe4df122e51661bb),
    UINT64_C(0x3125607ab548fa30), UINT64_C(0x4bfd10b2857d7349),
    UINT64_C(0x04ad64994d625e4d), UINT64_C(0x7e7514517d57d734),
    UINT64_C(0xf11d85092d094cbf), UINT64_C(0x8bc5f5c11d3cc5c6),
    UINT64_C(0x12b5926535897936), UINT64_C(0x686de2ad05bcf04f),
    UINT64_C(0xe70573f555e26bc4), UINT64_C(0x9ddd033d65d7e2bd),
    UINT64_C(0xd28d7716adc8cfb9), UINT64_C(0xa85507de9dfd46c0),
    UINT64_C(0x273d9686cda3dd4b), UINT64_C(0x5de5e64efd965432),
    UINT64_C(0xb99d7ed15d9d8743), UINT64_C(0xc3450e196da80e3a),
    UINT64_C(0x4c2d9f413df695b1), UINT64_C(0x36f5ef890dc31cc8),
    UINT64_C(0x79a59ba2c5dc31cc), UINT64_C(0x037deb6af5e9b8b5),
    UINT64_C(0x8c157a32a5b7233e), UINT64_C(0xf6cd0afa9582aa47),
    UINT64_C(0x4ad64994d625e4da), UINT64_C(0x300e395ce6106da3),
    UINT64_C(0xbf66a804b64ef628), UINT64_C(0xc5bed8cc867b7f51),
    UINT64_C(0x8aeeace74e645255), UINT64_C(0xf036dc2f7e51db2c),
    UINT64_C(0x7f5e4d772e0f40a7), UINT64_C(0x05863dbf1e3ac9de),
    UINT64_C(0xe1fea520be311aaf), UINT64_C(0x9b26d5e88e0493d6),
    UINT64_C(0x144e44b0de5a085d), UINT64_C(0x6e963478ee6f8124),
    UINT64_C(0x21c640532670ac20), UINT64_C(0x5b1e309b16452559),
    UINT64_C(0xd476a1c3461bbed2), UINT64_C(0xaeaed10b762e37ab),
    UINT64_C(0x37deb6af5e9b8b5b), UINT64_C(0x4d06c6676eae0222),
    UINT64_C(0xc26e573f3ef099a9), UINT64_C(0xb8b627f70ec510d0),
    UINT64_C(0xf7e653dcc6da3dd4), UINT64_C(0x8d3e2314f6efb4ad),
    UINT64_C(0x0256b24ca6b12f26), UINT64_C(0x788ec2849684a65f),
    UINT64_C(0x9cf65a1b368f752e), UINT64_C(0xe62e2ad306bafc57),
    UINT64_C(0x6946bb8b56e467dc), UINT64_C(0x139ecb4366d1eea5),
    UINT64_C(0x5ccebf68aecec3a1), UINT64_C(0x2616cfa09efb4ad8),
    UINT64_C(0xa97e5ef8cea5d153), UINT64_C(0xd3a62e30fe90582a),
    UINT64_C(0xb0c7b7e3c7593bd8), UINT64_C(0xca1fc72bf76cb2a1),
    UINT64_C(0x45775673a732292a), UINT64_C(0x3faf26bb9707a053),
    UINT64_C(0x70ff52905f188d57), UINT64_C(0x0a2722586f2d042e),
    UINT64_C(0x854fb3003f739fa5), UINT64_C(0xff97c3c80f4616dc),
    UINT64_C(0x1bef5b57af4dc5ad), UINT64_C(0x61372b9f9f784cd4),
    UINT64_C(0xee5fbac7cf26d75f), UINT64_C(0x9487ca0fff135e26),
    UINT64_C(0xdbd7be24370c7322), UINT64_C(0xa10fceec0739fa5b),
    UINT64_C(0x2e675fb4576761d0), UINT64_C(0x54bf2f7c6752e8a9),
    UINT64_C(0xcdcf48d84fe75459), UINT64_C(0xb71738107fd2dd20),
    UINT64_C(0x387fa9482f8c46ab), UINT64_C(0x42a7d9801fb9cfd2),
    UINT64_C(0x0df7adabd7a6e2d6), UINT64_C(0x772fdd63e7936baf),
    UINT64_C(0xf8474c3bb7cdf024), UINT64_C(0x829f3cf387f8795d),
    UINT64_C(0x66e7a46c27f3aa2c), UINT64_C(0x1c3fd4a417c62355),
    UINT64_C(0x935745fc4798b8de), UINT64_C(0xe98f353477ad31a7),
    UINT64_C(0xa6df411fbfb21ca3), UINT64_C(0xdc0731d78f8795da),
    UINT64_C(0x536fa08fdfd90e51), UINT64_C(0x29b7d047efec8728),
};

uint64_t crc64(uint64_t crc, const void *buf, size_t size)
{   const uint8_t *p = (const uint8_t *)buf;
    while (size-- != 0)
        crc = crc64_tab[(uint8_t)crc ^ *p++] ^ (crc >> 8);
    return crc;
}

/* Test main */
#ifdef TEST_MAIN

#include <stdio.h>
int main(void)
{   printf("e9c6d914c4b8d9ca == %016" PRIx64 "\n",
           crc64(0,(const uint8_t *)"123456789",9));
    return 0;
}

#endif

// [End of crc64 source code]

// I will also include a 32-bit CRC implementation, also subject to
// the generous license terms shown in the code:

/*-
 *  COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or
 *  code or tables extracted from it, as desired without restriction.
 *
 *  First, the polynomial itself and its table of feedback terms.  The
 *  polynomial is
 *  X^32+X^26+X^23+X^22+X^16+X^12+X^11+X^10+X^8+X^7+X^5+X^4+X^2+X^1+X^0
 *
 *  Note that we take it "backwards" and put the highest-order term in
 *  the lowest-order bit.  The X^32 term is "implied"; the LSB is the
 *  X^31 term, etc.  The X^0 term (usually shown as "+1") results in
 *  the MSB being 1
 *
 *  Note that the usual hardware shift register implementation, which
 *  is what we're using (we're merely optimizing it by doing eight-bit
 *  chunks at a time) shifts bits into the lowest-order term.  In our
 *  implementation, that means shifting towards the right.  Why do we
 *  do it this way?  Because the calculated CRC must be transmitted in
 *  order from highest-order term to lowest-order term.  UARTs transmit
 *  characters in order from LSB to MSB.  By storing the CRC this way
 *  we hand it to the UART in the order low-byte to high-byte; the UART
 *  sends each low-bit to hight-bit; and the result is transmission bit
 *  by bit from highest- to lowest-order term without requiring any bit
 *  shuffling on our part.  Reception works similarly
 *
 *  The feedback terms table consists of 256, 32-bit entries.  Notes
 *
 *      The table can be generated at runtime if desired; code to do so
 *      is shown later.  It might not be obvious, but the feedback
 *      terms simply represent the results of eight shift/xor opera
 *      tions for all combinations of data and CRC register values
 *
 *      The values must be right-shifted by eight bits by the "updcrc
 *      logic; the shift must be unsigned (bring in zeroes).  On some
 *      hardware you could probably optimize the shift in assembler by
 *      using byte-swap instructions
 *      polynomial $edb88320
 *
 *
 * CRC32 code derived from work by Gary S. Brown.
 * Very minor changes by ACN to insert case so code compiled as C++ and
 * get layout consisten with other code via use of astyle.
 */

// #include <sys/param.h>
// #include <sys/systm.h>

static uint32_t crc32_tab[] =
{   0x00000000U,0x77073096U,0xee0e612cU,0x990951baU,0x076dc419U,0x706af48fU,
    0xe963a535U,0x9e6495a3U,0x0edb8832U,0x79dcb8a4U,0xe0d5e91eU,0x97d2d988U,
    0x09b64c2bU,0x7eb17cbdU,0xe7b82d07U,0x90bf1d91U,0x1db71064U,0x6ab020f2U,
    0xf3b97148U,0x84be41deU,0x1adad47dU,0x6ddde4ebU,0xf4d4b551U,0x83d385c7U,
    0x136c9856U,0x646ba8c0U,0xfd62f97aU,0x8a65c9ecU,0x14015c4fU,0x63066cd9U,
    0xfa0f3d63U,0x8d080df5U,0x3b6e20c8U,0x4c69105eU,0xd56041e4U,0xa2677172U,
    0x3c03e4d1U,0x4b04d447U,0xd20d85fdU,0xa50ab56bU,0x35b5a8faU,0x42b2986cU,
    0xdbbbc9d6U,0xacbcf940U,0x32d86ce3U,0x45df5c75U,0xdcd60dcfU,0xabd13d59U,
    0x26d930acU,0x51de003aU,0xc8d75180U,0xbfd06116U,0x21b4f4b5U,0x56b3c423U,
    0xcfba9599U,0xb8bda50fU,0x2802b89eU,0x5f058808U,0xc60cd9b2U,0xb10be924U,
    0x2f6f7c87U,0x58684c11U,0xc1611dabU,0xb6662d3dU,0x76dc4190U,0x01db7106U,
    0x98d220bcU,0xefd5102aU,0x71b18589U,0x06b6b51fU,0x9fbfe4a5U,0xe8b8d433U,
    0x7807c9a2U,0x0f00f934U,0x9609a88eU,0xe10e9818U,0x7f6a0dbbU,0x086d3d2dU,
    0x91646c97U,0xe6635c01U,0x6b6b51f4U,0x1c6c6162U,0x856530d8U,0xf262004eU,
    0x6c0695edU,0x1b01a57bU,0x8208f4c1U,0xf50fc457U,0x65b0d9c6U,0x12b7e950U,
    0x8bbeb8eaU,0xfcb9887cU,0x62dd1ddfU,0x15da2d49U,0x8cd37cf3U,0xfbd44c65U,
    0x4db26158U,0x3ab551ceU,0xa3bc0074U,0xd4bb30e2U,0x4adfa541U,0x3dd895d7U,
    0xa4d1c46dU,0xd3d6f4fbU,0x4369e96aU,0x346ed9fcU,0xad678846U,0xda60b8d0U,
    0x44042d73U,0x33031de5U,0xaa0a4c5fU,0xdd0d7cc9U,0x5005713cU,0x270241aaU,
    0xbe0b1010U,0xc90c2086U,0x5768b525U,0x206f85b3U,0xb966d409U,0xce61e49fU,
    0x5edef90eU,0x29d9c998U,0xb0d09822U,0xc7d7a8b4U,0x59b33d17U,0x2eb40d81U,
    0xb7bd5c3bU,0xc0ba6cadU,0xedb88320U,0x9abfb3b6U,0x03b6e20cU,0x74b1d29aU,
    0xead54739U,0x9dd277afU,0x04db2615U,0x73dc1683U,0xe3630b12U,0x94643b84U,
    0x0d6d6a3eU,0x7a6a5aa8U,0xe40ecf0bU,0x9309ff9dU,0x0a00ae27U,0x7d079eb1U,
    0xf00f9344U,0x8708a3d2U,0x1e01f268U,0x6906c2feU,0xf762575dU,0x806567cbU,
    0x196c3671U,0x6e6b06e7U,0xfed41b76U,0x89d32be0U,0x10da7a5aU,0x67dd4accU,
    0xf9b9df6fU,0x8ebeeff9U,0x17b7be43U,0x60b08ed5U,0xd6d6a3e8U,0xa1d1937eU,
    0x38d8c2c4U,0x4fdff252U,0xd1bb67f1U,0xa6bc5767U,0x3fb506ddU,0x48b2364bU,
    0xd80d2bdaU,0xaf0a1b4cU,0x36034af6U,0x41047a60U,0xdf60efc3U,0xa867df55U,
    0x316e8eefU,0x4669be79U,0xcb61b38cU,0xbc66831aU,0x256fd2a0U,0x5268e236U,
    0xcc0c7795U,0xbb0b4703U,0x220216b9U,0x5505262fU,0xc5ba3bbeU,0xb2bd0b28U,
    0x2bb45a92U,0x5cb36a04U,0xc2d7ffa7U,0xb5d0cf31U,0x2cd99e8bU,0x5bdeae1dU,
    0x9b64c2b0U,0xec63f226U,0x756aa39cU,0x026d930aU,0x9c0906a9U,0xeb0e363fU,
    0x72076785U,0x05005713U,0x95bf4a82U,0xe2b87a14U,0x7bb12baeU,0x0cb61b38U,
    0x92d28e9bU,0xe5d5be0dU,0x7cdcefb7U,0x0bdbdf21U,0x86d3d2d4U,0xf1d4e242U,
    0x68ddb3f8U,0x1fda836eU,0x81be16cdU,0xf6b9265bU,0x6fb077e1U,0x18b74777U,
    0x88085ae6U,0xff0f6a70U,0x66063bcaU,0x11010b5cU,0x8f659effU,0xf862ae69U,
    0x616bffd3U,0x166ccf45U,0xa00ae278U,0xd70dd2eeU,0x4e048354U,0x3903b3c2U,
    0xa7672661U,0xd06016f7U,0x4969474dU,0x3e6e77dbU,0xaed16a4aU,0xd9d65adcU,
    0x40df0b66U,0x37d83bf0U,0xa9bcae53U,0xdebb9ec5U,0x47b2cf7fU,0x30b5ffe9U,
    0xbdbdf21cU,0xcabac28aU,0x53b39330U,0x24b4a3a6U,0xbad03605U,0xcdd70693U,
    0x54de5729U,0x23d967bfU,0xb3667a2eU,0xc4614ab8U,0x5d681b02U,0x2a6f2b94U,
    0xb40bbe37U,0xc30c8ea1U,0x5a05df1bU,0x2d02ef8d
};

uint32_t crc32(uint32_t crc, const void *buf, size_t size)
{   uint8_t *p = (uint8_t *)buf;
    crc = crc ^ ~0U;
    while (size-- != 0)
        crc = crc32_tab[(uint8_t)crc ^ *p++] ^ (crc >> 8);
    return crc ^ ~0U;
}

// [End of crc32 source code]


// A raw CSL Lisp provides around 850 entrypounts, while a full copy of
// Reduce with all the files u01.cpp to u60.cpp populated ends up with
// somewhat under 4000 entrypoints. At present I am using fixed size
// tables here and fixed hash functions. This is in principle unsatisfactory
// because somebody could expand the number of entrypoints. I propose
// not to worry about that now.
//

#define NCODEPOINTERS 5000U

size_t ncodepointers = 0;
intptr_t codepointers[NCODEPOINTERS];

inthash codehash;

bool insert_codepointer(uintptr_t x, const char *s)
{
// If this codepointer is one I have seen before then do nothing and return
// false.
    if (hash_lookup(&codehash, x) != (size_t)(-1))
    {   //fprintf(stderr, "function %s seen before\n", s);
        return false;
    }
// Add to the table of code-pointers, recording where it goes.
    size_t pos = hash_insert(&codehash, x);
    hash_set_value(&codehash, pos, ncodepointers);
    if (ncodepointers >= NCODEPOINTERS)
    {   fprintf(stderr, "Too many built-in functions. Please increase NCODEPOINTERS\n");
        fprintf(stderr, "in serialize.cpp. Current value is %u\n", NCODEPOINTERS);
        myabort();
    }
    //fprintf(stderr, "function %s given code %d\n", s, (int)ncodepointers);
    codepointers[ncodepointers++] = x;
    return true;
}

uint64_t use_setup(uint64_t crc, const setup_type *p)
{   while (p->name != NULL)
    {   // fprintf(stderr, "[%d] Name: %s\n", ncodepointers, p->name);
        unsigned char n = 0;
        if (insert_codepointer((uintptr_t)(p->one), p->name)) n += 1;
        if (insert_codepointer((uintptr_t)(p->two), p->name)) n += 2;
        if (insert_codepointer((uintptr_t)(p->n), p->name)) n += 4;
        crc = crc64(crc, &n, 1);
        crc = crc64(crc, (const unsigned char *)p->name, strlen(p->name));
        p++;
    }
    return crc;
}

uint64_t function_crc = 0;

void set_up_function_tables()
{   uint64_t crc = 0;
    hash_init(&codehash);
    ncodepointers = 0;
// I put a value that I expect to be invalid at position zero in the table
// so that if by accident I retrieve it I will see a visible crash (I hope).
    codepointers[ncodepointers++] = (intptr_t)(-1);
// The code here must find all the function addresses that are built
// into CSL that might legitimately end up within a heap image. The
// code sets up a 64-bit CRC code this is intended to be a signature
// of just what is used, and so can help ensure that a heap image dumped
// buy one system does not get re-loaded by an incompatible one.
// Each entrypoint is allocated a sequence number and everything is
// collected both in a hash table (codehash) that can map code-pointers
// to index values, and a table (codepointers) that is a single
// indexable array of the entrypoints. For Reduce there are somewhat under
// 4000 pointers to handle here, so costs are not too severe.
    char b[32];
    for (entry_point0 *p = &entries_table0[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_point1 *p = &entries_table1[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_point2 *p = &entries_table2[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_point3 *p = &entries_table3[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_point4 *p = &entries_table4[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_pointn *p = &entries_tablen[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    for (entry_pointn *p = &entries_tableio[1]; p->p!=NULL; p++)
    {   insert_codepointer((uintptr_t)p->p, p->s);
        crc = crc64(crc, (const unsigned char *)p->s, strlen(p->s));
    }
    const setup_type **p = setup_tables;
    while (*p != NULL) crc = use_setup(crc, *p++);
    p++;  // setup_tables is in two parts, separated by a NULL.
    while (*p != NULL) crc = use_setup(crc, *p++);

    function_crc = crc;
}

void *read_function()
{   uint64_t handle = read_u64();
    if (handle == 0 || handle >= ncodepointers)
    {   fprintf(stderr, "Invalid code handle read (%" PRIu64 " / %" PRIx64 ")\n",
                handle, handle);
        myabort();
    }
    return (void *)codepointers[handle];
}

void write_function(void *p)
{   size_t h = hash_lookup(&codehash, (intptr_t)p);
    if (h == (size_t)(-1))
    {   fprintf(stderr, "Unknown item used as code pointer (%p)\n", p);
        myabort();
    }
    uint64_t handle = hash_get_value(&codehash, h);
    if (handle == 0 || handle >= ncodepointers)
    {   fprintf(stderr, "Invalid code handle recovered for writing codepointer\n");
        fprintf(stderr, "codehash hash-table presumed messed up!\n");
        myabort();
    }
    write_u64(handle);
}

// In places here I need to find the start of a tagged vector-like
// object which may be tagged with either TAG_VECTOR or TAG_NUMBERS
// or possibly even TAG_FLOAT. This messy macro masks off the tag bits
// and adjusts to allow for the header word at the start of the object.

#define start_contents(p) (((uintptr_t)(p) & ~(uintptr_t)7) + CELL)

// In places where the contents of an array will be 64-bit items and I
// am running on a 32-bit machine I need to pad by 32-bits so that the
// object starts | header32 | padding | 64-bit data ... |

#define start_contents64(p) (((uintptr_t)(p) & ~(uintptr_t)7) + 8)

// At present this code does not go push/pop around calls that allocate
// memory and hence might trigger garbage collection. It also doed not
// check for failure in allocation. If it is ONLY used during system start-up
// to read a heap image into an otherwise empty context then any garbage
// collection or allocation failure would amount to a fatal error. Well at
// a minimum my code does not at present detect and report that. I will
// probably only really think of updating it if (and when) I make serialisation
// and deserialisation generally available for use within a running system.

LispObject serial_read()
{   LispObject *p;    // a pointer to where to put the next item
    LispObject r,     // result of the entire reading process
               pbase, // needed to make the code GC safe
               prev,  // recent object read, for use with SER_DUP
               w,     // working variable
               s,     // a (linked) stack used with vectors (and symbols
                      // if the SER_RAWSYMBOL opcode is encountered).
               b;     // a back-pointer chain
    int c;
    prev = pbase = r = s = b = fixnum_of_int(0);
    p = &r;
down:
// read_byte() needs to read from the stream representation of things
// and return a code... In this initial sketch I will only need to look
// at three cases. One is for CONS which is sort of obvious. The next is
// VECTOR. This covers all the cases where there are pointers within the
// object, including symbols and rational and complex numbers. The final
// case is LEAF which will include immediate data such as FIXNUMS, but
// alse big-numbers, strings and back-references to previously-read
// structures.
    c = read_opcode_byte();
    switch (c & 0xe0)
    {   case SER_VARIOUS:
            switch (c)
            {   case SER_CONS:
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
                    reader_repeat_new(pbase);
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
                    *p = reader_repeat_old(w = (1 + 64 + read_u64()));
//           fprintf(stderr, "backref %" PRIuPTR " => %" PRIxPTR "\n",
//                  (uintptr_t)w, (uintptr_t)*p);
                    goto up;

                case SER_DUP:
// This is issued just after a SER_VECTOR (etc) code that will
// have left pbase referring to the object just allocated.
                    reader_repeat_new(prev);
                    goto down;

                case SER_POSFIXNUM:
// This case reads a 64-bit value and construct either a fixnum or a boxnum
// as relevant. If it creates a boxnum then that could possibly be a shared
// object, and against the possibility of that I set pbase so that a
// SER_DUP opcode can behave meaningfully. Note that this can make
// a full 64-bit positive integer because it reads and processes its input
// as an unsigned value.
                    prev = *p = make_lisp_unsigned64(read_u64());
                    goto up;

                case SER_NEGFIXNUM:
// Negative (small to medium-sized) integers are given a separate code here
// beause packing then using sign-and-magnitude seems easier. The extra "-1"
// here is both to avoid having the duplicated case of +0 and -0 and to
// arrange that the set of values that pack into a given number of bytes
// matches 2s complement. Eg with just 1 following byte the range goes from
// -128 to +127 (rather than -127 to +127).
// Note that the code that writes stuff out should only generate this
// when the value concerned will fit within a 64-bit signed value.
                    prev = *p = make_lisp_integer64(-1-read_u64());
                    goto up;

                case SER_DUPRAWSYMBOL:
                case SER_RAWSYMBOL:
// SER_RAWSYMBOL is used while dumping complete heap-images. The opcode here
// is followed by information to go into the header word of the symbol (various
// flag bits such as whether the symbol is global or fluid), then a dump of
// information about what goes in the function call and count components. After
// that all the list-like components will be transmitted (much as if they were
// elements in a vector). The key parts of this work using the same scheme as
// for SER_LVECTOR.
                    prev = w = *p = getvector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
                    if (c == SER_DUPRAWSYMBOL) reader_repeat_new(prev);
// Note that the vector as created will have its LENGTH encoded in the
// header, but for symbols that is incorrect so I need to re-write the
// header wholesale here. Note that a symbol header has the normal tag for
// headers in its low bits then two zero bits to indicate that it is
// a symbol.
                    qheader(w) = (Header)((read_u64()<<(Tw+4)) + TAG_HDR_IMMED);
// I will first fill in the fields that hold binary data or pointers to
// executable code.
                    qfn0(w) = (no_args *)read_function();
                    qfn1(w) = (one_args *)read_function();
                    qfn2(w) = (two_args *)read_function();
                    qfn3(w) = (three_args *)read_function();
// There is an issue of four_args vs n_args here that means that new and old
// versions of the code possibly clash. I hope that it just will not matter
// which I cast to and assign via here, even though strict aliasing rules
// say that it COULD.
                    qfn4(w) = (four_args *)read_function();
                    qcount(w) = read_u64();
// Now to allow me to feel safe I will put NIL in all the other fields
// on a provisional basis. They get their proper values later.
                    qvalue(w) = qenv(w) = qpname(w) = qplist(w) =
                        qfastgets(w) = qpackage(w) = C_nil;
                    qvalue(w) = b; // the back-pointer.
                    b = w;
#define PNAME_INDEX (&qpname(w) - &qvalue(w))
                    s = cons(fixnum_of_int(PNAME_INDEX), s);
                    prev = pbase = b;
                    p = &qpname(b);
                    goto down;


                case SER_SYMBOL:
                case SER_DUPSYMBOL:
                case SER_GENSYM:
                case SER_DUPGENSYM:
// All of these cases are followed by a length marker and the the octets
// making up the UTF-8 name of the symbol. If the "DUP" options is present
// then the symbol must be entered in the table of items that are referenced
// repeatedly. in the "GENSYM" case the name is the base-name of the gensym,
// pergaps very often just "G", and the name read in will be set up as
// if not yet printed, so a sequence number will be added leter.
                {   size_t len = read_u64();
                    boffop = 0;
// HAHAHA - if BOFFO does not exist properly at this stage then I am in
// deep trouble. But these opcodes will only be used at times I am
// serializing for re-loading into a working Lisp. Note that the whole
// issue of the interaction between serialization and a package system is
// not thought through at present - things will be read in in the
// current package (to the extent that such a concept exists or makes sense).
                    for (size_t i=0; i<len; i++) packbyte(read_string_byte());
                    if (c == SER_GENSYM || c == SER_DUPGENSYM)
                    {   w = copy_string(boffo, boffop);
                        w = Lgensym1(C_nil, w);
                    }
                    else w = iintern(boffo, (int32_t)boffop, CP, 0);
                    prev = *p = w;
                    if (c == SER_DUPSYMBOL || c == SER_DUPGENSYM)
                        reader_repeat_new(prev);
                    goto up;
                }

                case SER_FLOAT28:
// A 28-bit short float
                    fprintf(stderr, "SER_FLOAT28 not coded yet\n");
                    myabort();

                case SER_FLOAT32:
// a 32-bit single float
                    prev = *p = make_boxfloat(read_f32(), TYPE_SINGLE_FLOAT);
                    goto up;

                case SER_FLOAT64:
// a 64-bit (long) float
                    prev = *p = make_boxfloat(read_f64(), TYPE_DOUBLE_FLOAT);
                    goto up;

                case SER_FLOAT128:
// a 128-bit (double-length) float.
                    prev = *p = make_boxfloat(0.0, TYPE_LONG_FLOAT);
                    long_float_val(prev) = read_f128();
                    goto up;

                case SER_CHARSPID:
// a packed characters literal. Characters that are Basic Latin can be coded
// here with just 2 bytes, so for instance 'A' is SER_CHAR/0x41. Codes up to
// U+3fff come in 3 bytes and so on. Note that the encoding is NOT utf8 - it is
// the variable length encoding.
// SPIDs are alse encoded here. In each case they are with the low bits
// shown here and I just send the rest of the data as a raw number. Note
// that bytecode handles can be dealt with here if I understand them -
// which for now I do not!
                    {   uint64_t v = read_u64();
                        prev = *p = ((LispObject)v<<(Tw+2)) | TAG_HDR_IMMED;
                    }
                    goto up;

                case SER_BITVEC:
                    w = read_u64();
                    {   size_t len = CELL + (w + 7)/8; // length in bytes
                        prev = *p = getvector(TAG_VECTOR, bitvechdr_(w), len);
                        char *x = &celt(prev, 0);
                        for (size_t i=0; i<(size_t)w; i++) *x++ = read_data_byte();
                        while (((intptr_t)x & 7) != 0) *x++ = 0;
                    }
                    goto up;

                case SER_NIL:
                    prev = *p = C_nil;
                    goto up;

                case SER_END:
                    fprintf(stderr, "End of dump marker found - this is an error situation\n");
                    myabort();

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
                    fprintf(stderr, "Unimplemented reader opcode (a) %.2x\n", c);
                    myabort();
            }
            break;
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
// read_byte() must also deliver information on the type and the size
// of the vector that I need to create.
//
// One thing to observe here. If I have a vector that is a hash table using
// EQ as its key then reading it in here will leave its entries all the right
// values but not in the right places. My response to that is to
// arrange that a potentially messed up hash table has type code TYPE_NEWHASHX
// rather than TYPE_NEWHASH. The hash code accessing functions will check for
// that, and if they find it they re-hash before use, restoring the key to
// just TYPE_NEWHASH. The consequence is that the rehashing work is not done
// until and unless it is actually needed.
        {   int type = ((c & 0x1f) << (Tw + 2)) | (0x01 << Tw),
                tag = is_number_header_full_test(type) ? TAG_NUMBERS :
                                                         TAG_VECTOR;
            if (type == TYPE_NEWHASH) type = TYPE_NEWHASHX;
// The size here will be the number of Lisp items held in the vector, so
// what I need to pass to getvector makes that into a byte count and allows
// for the header word as well.
            size_t n = read_u64();
            prev = w = *p = getvector(tag, type, CELL*(n+1));
// Note that the "vector" just created may be tagged with TAG_NUMBERS
// rather than TAG_VECTOR, so I use the access macro "vselt" rather than
// "elt" - and that survives whichever case I am in.
// Now if I am on a 32-bit system and the vector uses a header word and then
// and even number of words of data it will use a padder word to bring its
// total size up to a 64-bit boundary. Tidy up that final word.
            if (!SIXTY_FOUR_BIT && ((n & 1) == 0))
                vselt(w, n) = fixnum_of_int(0);
// If the vector does not have any content at all then I am now done.
            if (n == 0) goto up;
// In case there is a GC before I have finished filling in proper values
// in the vector I will out in values that are at least safe.
            for (size_t i=0; i<n; i++) vselt(w, i) = fixnum_of_int(0);
            if (is_mixed_header(vechdr(w))) n = 2;  // Ie elements 0, 1 and 2
            else n--; // final element is at n-1
// Vectors chain through the first entry. If a vector was empty so it did not
// have a first entry to use here it would have needed to be dumped as a LEAF.
// But a special additional issue is that if the vector omly has one item in it
// then I must NOT set up back-pointers and the "s-stack" in quite the usual
// manner...
            if (n == 0)
            {   p = &vselt(w, 0);
                goto down;
            }
            vselt(w, 0) = b;
            b = w;
            s = cons(fixnum_of_int(n), s);
            prev = pbase = b;
            p = &vselt(b, n);
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
            if ((c & 0x10) != 0) c |= ~0x0f; // sign extend
            *p = fixnum_of_int(c);
            goto up;

        case SER_STRING:
// String will be very much like BVECTOR except that because I expect it to be
// an especially important case I pack a length code into the 5-bit field of
// the opcode byte and the type information is implicit. This code only copes
// with strings with length 1-32. The associated data is JUST the bytes
// making up the string, with padding at the end.
            w = (c & 0x1f) + 1;
            prev = *p = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+w);
            {   char *x = &celt(prev, 0);
                for (size_t i=0; i<(size_t)w; i++) *x++ = read_string_byte();
                while (((intptr_t)x & 7) != 0) *x++ = 0;
            }
            goto up;

// I had considered having a special opcode to deal with strings of length 0
// or longer than 33, but in fact the general SER_BVECTOR code does just that
// slighly more efficiently then I would otherwise manage. Observe that the
// a SER_BVECTOR followed by 1 byte of length code copes with any vector
// needing up to 127 words (ie 508 bytes) with just 2 bytes of control
// information.

        case SER_BVECTOR:
// The general case for vectors containing binary information is followed
// by a length code that shows how many items there are in the vector.
// This counts in the natural size for the vector.
            w = read_u64();
// Here I have assembled 7 bits of type information in c. CCCCC comes from the
// opcode. The header I want for my vector will be
//     wwwwwwww....wwww CCC CC 10 g100
            {   int type = ((c & 0x1f)<<(Tw+2)) | (0x3<<Tw),
                    tag = is_bignum_header(type) ? TAG_NUMBERS :
                                                   TAG_VECTOR;
                if (vector_i8(type))
                {   prev = *p = getvector(tag, type, CELL+w);
                    char *x = (char *)start_contents(prev);
                    if (is_string_header(type))
                        for (size_t i=0; i<(size_t)w; i++)
                            *x++ = read_string_byte();
                    else for (size_t i=0; i<(size_t)w; i++)
                        *x++ = read_data_byte();
                    while (((intptr_t)x & 7) != 0) *x++ = 0;
                }
                else if (vector_i32(type))
                {   prev = *p = getvector(tag, type, CELL+4*w);
                    uint32_t *x = (uint32_t *)start_contents(prev);
// 32-bit integers are transmitted most significant byte first.
                    for (size_t i=0; i<(size_t)w; i++)
                    {   uint32_t q = read_data_byte() & 0xff;
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        *x++ = (q << 8) | (read_data_byte() & 0xff);
                    }
                    while (((intptr_t)x & 7) != 0) *x++ = 0;
                }
                else if (vector_f64(type))
                {   prev = *p = getvector(tag, type, CELL+8*w);
                    double *x = (double *)start_contents64(prev);
// There has to be a padder word in these objects on a 32-bit machine so
// that the data is 64-bit aligned. Clean it up.
                    if (!SIXTY_FOUR_BIT) *(int32_t *)start_contents(prev) = 0;
                    for (size_t i=0; i<(size_t)w; i++) *x++ = read_f64();
                }
                else if (vector_i16(type))
                {   prev = *p = getvector(tag, type, CELL+2*w);
                    uint16_t *x = (uint16_t *)start_contents(prev);
                    for (size_t i=0; i<(size_t)w; i++)
                    {   uint32_t q = read_data_byte() & 0xff;
                        *x++ = (q << 8) | (read_data_byte() & 0xff);
                    }
                    while (((intptr_t)x & 7) != 0) *x++ = 0;
                }
                else if (vector_i64(type))
                {   prev = *p = getvector(tag, type, CELL+8*w);
                    uint64_t *x = (uint64_t *)start_contents64(prev);
                    if (!SIXTY_FOUR_BIT) *(int32_t *)start_contents(prev) = 0;
                    for (size_t i=0; i<(size_t)w; i++)
                    {   uint64_t q = read_data_byte() & 0xff;
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        q = (q << 8) | (read_data_byte() & 0xff);
                        *x++ = (q << 8) | (read_data_byte() & 0xff);
                    }
                }
                else if (vector_f32(type))
                {   prev = *p = getvector(tag, type, CELL+4*w);
                    float *x = (float *)start_contents(prev);
                    for (size_t i=0; i<(size_t)w; i++) *x++ = read_f32();
                    while (((intptr_t)x & 7) != 0) *x++ = 0;
                }
                else if (vector_f128(type))
                {   prev = *p = getvector(tag, type, CELL+16*w);
                    fprintf(stderr, "128-bit integer arrays not supported (yet?)\n");
                    myabort();
                }
                else if (vector_i128(type))
                {   prev = *p = getvector(tag, type, CELL+16*w);
                    fprintf(stderr, "128-bit floats not supported (yet?)\n");
                    myabort();
                }
                else
                {   fprintf(stderr, "Vector code is impossible\n");
                    myabort();
                }
            }
            goto up;

        case SER_SPARE:
        default:
            fprintf(stderr, "Unimplemented reader opcode (b) %.2x\n", c);
            myabort();
    }

// The above deals with arriving at the description of an object. What follows
// copes with return to an object after having filled in one of its component
// fields.

up:
// If the back-pointer chain is empty then I am done and can return.
    if (b == fixnum_of_int(0))
    {   if (r == 0)
        {   fprintf(stderr, "serial reader about to return zero\n");
            myabort();
        }
        return r;
    }
// When I have done everything that fills in the CAR of a CONS cell I
// just need to go and deal with the CDR.
    if (consp(b))
    {   pbase = b;
        p = &qcdr(b);
        b = qcdr(b);
        goto down;
    }
// The remaining cases are when b points to a vector or symbol. I use the
// stack s to track how far along it I am, and need to do special things when
// I am almost complete
    if (!is_cons(s))
    {   fprintf(stderr, "s bad at line %d in serialize.cpp\n", __LINE__);
        simple_print(s);
        myabort();
    }
    if (!is_fixnum(qcar(s)))
    {   fprintf(stderr, "car s bad at line %d in serialize.cpp\n", __LINE__);
        simple_print(qcar(s));
        myabort();
    }
    intptr_t n = int_of_fixnum(qcar(s)) - 1;
    if (n < 0)
    {   fprintf(stderr, "car s negative at line %d in serialize.cpp\n", __LINE__);
        fprintf(stderr, "qcar(s) = %" PRIx64 " in raw hex\n", (int64_t)qcar(s));
        fprintf(stderr, "value of qcar(s) as list: ");
        simple_print(qcar(s));
        myabort();
    }
    if (n == 0)
    {   w = b;
        pbase = w;
// vselt(v,n) accesses the nth item of the object v, whether v is a vector
// (including hash tables, structures, records, objects...) or a symbol.
// In the case of a symbol the index n selects as between qvalue, pname and
// the other fields making up a symbol.
        p = &vselt(w, 0);
        b = vselt(w, 0);
// I could and possibly should push the released cell from s onto a local
// freelist and use that where I do a CONS if possible...
//      qcar(s) = fr; fr = s; s = qcdr(s); qcdr(fr) = fixnum_of_int(0);
// might do the job, chaining the freelist through its CAR field.
        s = qcdr(s);
        goto down;
    }
    qcar(s) = fixnum_of_int(n); // write back decreased index
    pbase = b;
    p = &vselt(b, n);
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
{   unsigned int i = (unsigned int)(addr >> 54);
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
//  fprintf(stderr, "address-used %" PRIxPTR " = %d\n", (uintptr_t)addr,
//         m5[addr >> 3] & (1 << (addr & 7)));
    return (m5[addr >> 3] & (1 << (addr & 7))) != 0;
}

// Allocate memory for part of the map. if malloc can not allocate space
// it should be treated as a fatal error - the processing here is naive
// at present, since for instance with a GUI there is no guarantee that
// stderr exists.
//
// Furthermore rather than using malloc here (and free later) I should try
// to use some space that is allocated to me but not currently in use. If I
// have a 2-space copying collector I have half my whole memory available!
// Even if I am using a non-copying collector I expect there to be LOTS of
// space available. So maybe what I need rather than malloc is a call that
// allocates a vector-like region in the heap, but falls back to malloc (eg
// to expand the heap) rather than garbage collecting?

static void *new_map_block()
{   void *p = (void *)calloc(512, sizeof(void *));
    if (p == NULL)
    {   fprintf(stderr, "\nFatal error - no memory\n");
        exit(1);
    }
    return p;
}

static uint8_t *new_final_map_block()
{   uint8_t *p = (uint8_t *)calloc(4096, 1);
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
//  fprintf(stderr, "mark_address_as_used %" PRIxPTR "\n", (intptr_t)addr);
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
{   if (m != NULL) free(m);
}

static void release_map_4(uint8_t **m)
{   if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_5(m[i]);
        free(m);
    }
}

static void release_map_3(uint8_t ***m)
{   if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_4(m[i]);
        free(m);
    }
}

static void release_map_2(uint8_t ****m)
{   if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_3(m[i]);
        free(m);
    }
}

static void release_map_1(uint8_t *****m)
{   if (m != NULL)
    {   for (int i=0; i<512; i++) release_map_2(m[i]);
        free(m);
    }
}

void release_map()
{   for (int i=0; i<1024; i++)
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
{   LispObject b = 0 + BACKPOINTER_CDR, w;
    uintptr_t len;
    Header h;
down:
    if (p == 0)
    {   fprintf(stderr, "Zero pointer found\n"); // An error - but I feel safest
        // if I detect it and do not crash.
        goto up;
    }
    else if (p == C_nil) goto up;
    switch (p & TAG_BITS)
{       default:
        case TAG_CONS:
            if (address_used(p - TAG_CONS))
            {   hash_insert(&repeat_hash, p);
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
            {   hash_insert(&repeat_hash, p);
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
            p = qpname(p);
            qpname(w) = b;
            b = (LispObject)&qpname(w) + BACKPOINTER_SYMBOL;
            goto down;

        case TAG_VECTOR:
            if (address_used(p - TAG_VECTOR))
            {   hash_insert(&repeat_hash, p);
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
// three of lisp data, which are thought of as having indexes 0, 1 and 2.
            w = p + len - CELL - TAG_VECTOR;
            p = *(LispObject *)w;
            *(LispObject *)w = b;
            b = w + BACKPOINTER_VECTOR;
            goto down;

        case TAG_NUMBERS:
            if (address_used(p - TAG_NUMBERS))
            {   hash_insert(&repeat_hash, p);
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
            {   hash_insert(&repeat_hash, p);
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
            fprintf(stderr, "\n+++ Forwarding address detected in heap scan\n");
            goto up;
    }

up:
    switch (b & BACKPOINTER_MASK)
{       default:
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

// The code here requires that repeat_hash has been created by a previous
// use of scan_data. Every item that has multiple references to it will
// be in there. The first time an object is visited then hash table entry
// will exist but has zero in its data field.

void write_data(LispObject p)
{   LispObject b = 0 + BACKPOINTER_CDR, w;
    uintptr_t len;
    int64_t w64;
    Header h;
    size_t i;
down:
    if (p == 0) p = SPID_NIL; // reload as a SPID.
    else if (p == C_nil)
    {   write_opcode(SER_NIL, "nil");
        goto up;
    }
    if ((i = hash_lookup(&repeat_hash, p)) != (size_t)(-1))
    {   if (hash_get_value(&repeat_hash, i) != 0)
        {   size_t n = find_index_in_repeats(i);
            char msg[20];
            sprintf(msg, "back %" PRIuPTR, (uintptr_t)n);
            if (n <= 32) write_opcode(SER_BACKREF0 + n - 1, msg);
            else if (n <= 64) write_opcode(SER_BACKREF1 + n - 33, msg);
            else
            {   write_opcode(SER_BIGBACKREF, msg);
                write_u64(n - 65);
            }
            goto up;
        }
// If this is the first visit to an item that will be repeated then I
// need to record where it will live in the table of repeats.
        find_index_in_repeats(i);
    }
// Here we will have i==-1 if the object is not going to be referenced again.
    switch (p & TAG_BITS)
{       default:

        case TAG_CONS:
// I have a separate opcode for a cons csll that is will have further
// references to it bacause there was easy space in my opcode map for that.
            if (i != (size_t)-1)
                write_opcode(SER_DUPCONS, "cons that will be re-used");
            else write_opcode(SER_CONS, "cons");
            w = p;
            p = qcar(p);
            qcar(w) = b;
// Reverse pointers with the back-pointer being tagged with 0
            b = w - TAG_CONS + BACKPOINTER_CAR;
            goto down;

        case TAG_SYMBOL:
            if (!descend_symbols)
            {   w = qpname(p);
                char msg[40];
                bool isgensym = false;
                size_t n = length_of_byteheader(vechdr(w)) - CELL;
// If I have a gensym that has been printed then its pname field
// holds a string of the form
//      GGGnnnn_nnn_nnn_nnn
// with some number of groups of 3 digits on the end and then a group
// of 4. This code loses that part of the name.
                if ((isgensym = (qheader(p) & SYM_ANY_GENSYM) != 0) &&
                    (qheader(p) & SYM_UNPRINTED_GENSYM) == 0)
                {   while (celt(w, n-4) == '_') n -= 4;
                    n -= 4;
                }
                if (isgensym)
                {   if (i != (size_t)-1)
                    {   sprintf(msg, "dup-gensym, length=%" PRIuPTR, (uintptr_t)n);
                        write_opcode(SER_DUPGENSYM, msg);
                    }
                    else
                    {   sprintf(msg, "gensym, length=%" PRIuPTR, (uintptr_t)n);
                        write_opcode(SER_GENSYM, msg);
                    }
                }
                else
                {   if (i != (size_t)-1)
                    {   sprintf(msg, "dup-symbol, length=%" PRIuPTR, (uintptr_t)n);
                        write_opcode(SER_DUPSYMBOL, msg);
                    }
                    else
                    {   sprintf(msg, "symbol, length=%" PRIuPTR, (uintptr_t)n);
                        write_opcode(SER_SYMBOL, msg);
                    }
                }
                write_u64(n);  // number of bytes in the name
                for (size_t i=0; i<n; i++)
                {   int c = celt(w, i) & 0xff;
                    char msg[8];
                    if (0x20 < c && c <= 0x7e) sprintf(msg, "'%c'", c);
                    else sprintf(msg, "%#.2x", c);
                    write_byte(c, msg);
                }
                goto up;
            }
            if (i != (size_t)-1)
                write_opcode(SER_DUPRAWSYMBOL, "raw symbol header");
            else write_opcode(SER_RAWSYMBOL, "raw symbol header");
// Here I need to cope with the tagging bits and function cells, and
// the count field... Each of these uses a variable length coding scheme that
// will be 1 byte long in easy cases but can cope with 2^64 possibilities in
// all if necessary.
//@         {   LispObject name = qpname(p);
//@             if (is_vector(name) && is_string(name))
//@             {   fprintf(stderr, "Symbol (%p : %p) name: \"%.*s\"\n",
//@                     (void *)p, (void *)name,
//@                     (int)(length_of_byteheader(vechdr(name))-CELL),
//@                     &celt(name, 0));
//@             }
//@         }
            write_u64(((uint64_t)qheader(p))>>(Tw+4));
            write_function((void *)(qfn0(p)));
            write_function((void *)(qfn1(p)));
            write_function((void *)(qfn2(p)));
            write_function((void *)(qfn3(p)));
            write_function((void *)(qfn4(p)));
            write_u64(qcount(p));
            w = p;
            p = qpname(p);
            qpname(w) = b;
            b = (LispObject)&qpname(w) + BACKPOINTER_SYMBOL;
            goto down;

        case TAG_VECTOR:
// Some vectors hold binary, some lists and a few have a small number of
// lists in their first few cells and binary data beyond that. It is
// necessary to decode the header to see which case applies. The same
// issue will arise for (boxed) numbers.
            h = vechdr(p);
        writevector:
            if (vector_holds_binary(h)) goto write_binary_vector;
            write_opcode(SER_LVECTOR | ((h>>(Tw+2)) & 0x1f), "lisp vector");
// Length of a list-containing vector is given in CELLS.
            write_u64(length_of_header(h)/CELL - 1);
// Observe that for vectors containing List data the DUP comes after the
// SER_LVECTOR opcode but before the sequences that fill in vector contents.
            if (i != (size_t)-1)
                write_opcode(SER_DUP, "repeatedly referenced vector");
// For now the data beyond the 3 list-holding items in a MIXED structure
// will not be dumped. I may need to review that later on.
            if (is_mixed_header(h)) len = 3;
            else len = length_of_header(h)/CELL - 1;
// len in the length in bytes including the size of the header. For "mixed"
// vectors (most notably stream objects) it represents one cell of header and
// three of lisp data. The "-1" on the next line is because elements run from
// 0 to len-1 rather than from 1 to len.
            w = (LispObject)&elt(p, len-1);
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
            {   char msg[40];
                sprintf(msg, "string, length=%" PRIuPTR, (intptr_t)len);
                write_opcode(SER_STRING+len-1, msg);
                for (size_t j=0; j<len; j++)
                {   int c = ucelt(p, j);
                    if (0x20 < c && c <= 0x7e) sprintf(msg, "'%c'", c);
                    else sprintf(msg, "%#.2x", c);
                    write_byte(c, msg);
                }
                if (i != (size_t)-1) write_opcode(SER_DUP, "dup string");
                goto up;
            }
            else if (is_bitvec_header(h))
            {   char msg[40];
                len = length_of_bitheader(h);
                sprintf(msg, "bitvec, length=%" PRIuPTR, (intptr_t)len);
                write_opcode(SER_BITVEC, msg);
                write_u64(len);
                len = (len + 7)/8;
                for (size_t j=0; j<len; j++)
                {   int c = ucelt(p, j);
                    for (int k=0; k<8; k++)
                        msg[k] = (c & (1<<k)) != 0 ? '1' : '0';
                    msg[8] = 0;
                    write_byte(c, msg);
                }
                if (i != (size_t)-1) write_opcode(SER_DUP, "dup bitvector");
                goto up;
            }
// If I have a big-integer that uses at most two (32-bit) words then
// I can transmit it as a big fixnum. I know that a 3-word bignum can
// sometimes fit within 64-bits, but I do not detect and handle that
// case here. The main concern I have here is that if I move to making
// fixnums 60-bits wide in the future that the range that they cover is
// handled nicely, and here it is!
// Observe that the type returned by bignum_digits(p)[n] is uint32_t and
// that although most digits in a bignum are unsigned the most significant
// one must be treated as signed. So I cast to int32_t before casting to
// int64_t to ensure that the sign gets propagated the way I need it to.
            else if (is_bignum_header(h))
            {   if (length_of_header(h) == CELL+4)
                {   int64_t n = (int32_t)bignum_digits(p)[0];
                    char msg[16];
                    sprintf(msg, "int value=%" PRId64, n);
                    if (n < 0)
                    {   write_opcode(SER_NEGFIXNUM, msg);
                        write_u64(-n-1);
                    }
                    else
                    {   write_opcode(SER_POSFIXNUM, msg);
                        write_u64(n);
                    }
                    if (i != (size_t)-1) write_opcode(SER_DUP, "dup bignum");
                    goto up;
                }
                else if (length_of_header(h) == CELL+8)
                {   int64_t n = (int32_t)bignum_digits(p)[0] |
                                ((int64_t)(int32_t)bignum_digits(p)[1] << 31);
                    char msg[16];
                    sprintf(msg, "int value=%" PRId64, n);
// The value I have here fitted within two bignum digits and so is really at
// most 62 bits. A consequence of that is that negating it can not lead to
// arithmetic overflow within a signed 64-bit word. Whew!
                    if (n < 0)
                    {   write_opcode(SER_NEGFIXNUM, msg);
                        write_u64(-n-1);
                    }
                    else
                    {   write_opcode(SER_POSFIXNUM, msg);
                        write_u64(n);
                    }
                    if (i != (size_t)-1) write_opcode(SER_DUP, "dup bignum");
                    goto up;
                }
// I will treat bignums with 3 or more words using a general scheme
// and this will include cases like the values + and - 0x8000000000000000LL
// which I might otherwise need to think about carefully to ensure that
// processing with 64-bit integers did not cause trouble with overflow.
            }
//
// The general code here writes out a vector where its contents are
// binary data. This needs to use separate code for each sort of data
// so that the serialized version is transmitted using a standard order
// of bytes. Also for vectors that hold bytes or halfwords the number
// of units to transmit has to be computed in the light of the full
// header word.
// Hahaha there is a trap here. For vectors that hold bytes or halfword values
// part of the length ends up in the bits that otherwise specify the type
// of stuff in use. But the code that allocates a new vector thinks that
// it will insert this information too. Unless steps are taken to arrange
// that information is sent just once I can get into trouble. The way I will
// work around this is here in the writing-code. The "type" field will be
// forced to be (eg) TYPE_STRING_4 which should then make all behave OK.
            {   Header h1 = h;
                if (vector_i8(h1)) h1 |= (0x60 << Tw);
                else if (vector_i16(h1)) h1 |= (0x40 << Tw);
                write_opcode(SER_BVECTOR | ((h1>>(Tw+2)) & 0x1f), "binary vector");
            }
// The code that follows must match up with the code that reads vectors
// back in. It has to convert data to a portable form that is agnostic
// to little vs. big-endian architectures.
// Also note that the "vector" may be tagged as TAG_VECTOR or TAG_NUMBERS and
// so I need code that uses a mask operation to address its start.
            if (vector_i8(h))
            {   char *x = (char *)start_contents(p);
                write_u64(len = length_of_byteheader(h) - CELL);
// I *could* detect strings etc here to display the comments more tidily,
// but since they are just for debugging that seems like too much work
// for today.
                for (size_t i=0; i<len; i++) write_byte(*x++, "part of vec8/string");
            }
            else if (vector_i32(h))
            {   uint32_t *x = (uint32_t *)start_contents(p);
// The packed length is the length in words.
                write_u64(len = (length_of_header(h) - CELL)/4);
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
            {   double *x = (double *)start_contents64(p);
                write_u64(len = (length_of_header(h) - CELL)/8);
                for (size_t i=0; i<len; i++) write_f64(*x++);
            }
            else if (vector_i16(h))
            {   uint16_t *x = (uint16_t *)start_contents(p);
                write_u64(len = length_of_hwordheader(h) - CELL/2);
                for (size_t i=0; i<len; i++)
                {   uint32_t q = *x++;
                    write_byte((q>>8) & 0xff, "high byte");
                    write_byte(q & 0xff, "low byte");
                }
            }
            else if (vector_i64(h))
            {   uint64_t *x = (uint64_t *)start_contents64(p);
                write_u64(len = (length_of_header(h) - CELL)/8);
// 64-bit integers are transmitted most significant byte first.
                for (size_t i=0; i<len/8; i++)
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
            {   float *x = (float *)start_contents(p);
                write_u64(len = (length_of_header(h) - CELL)/4);
                for (size_t i=0; i<len/4; i++) write_f32(*x++);
            }
            else if (vector_f128(h))
            {   fprintf(stderr, "128-bit float arrays not supported (yet?)\n");
                myabort();
            }
            else if (vector_i128(h))
            {   fprintf(stderr, "128-bit integer arrays not supported (yet?)\n");
                myabort();
            }
            else
            {   fprintf(stderr, "Vector code is impossible\n");
                myabort();
            }
            if (i != (size_t)-1)
                write_opcode(SER_DUP, "repeatedly ref. vector");
            goto up;

        case TAG_NUMBERS:
            h = numhdr(p);
            goto writevector;

        case TAG_BOXFLOAT:
            switch (type_of_header(flthdr(p)))
            {   case TYPE_SINGLE_FLOAT:
                {   char msg[32];
                    sprintf(msg, "float %.7g", (double)single_float_val(p));
                    write_opcode(SER_FLOAT32, msg);
                    write_f32(single_float_val(p));
                }
                break;
                case TYPE_DOUBLE_FLOAT:
                {   char msg[32];
                    sprintf(msg, "double %.16g", double_float_val(p));
                    write_opcode(SER_FLOAT64, msg);
                    write_f64(double_float_val(p));
                }
                break;
                case TYPE_LONG_FLOAT:
                {   char msg[32];
// At present I do not have a good scheme to display the 128-bit float value.
                    sprintf(msg, "long double");
                    write_opcode(SER_FLOAT128, msg);
                    write_f128(long_float_val(p));
                }
                break;
                default:
                    fprintf(stderr, "floating point representation not recognized\n");
                    myabort();
            }
            if (i != (size_t)-1)
                write_opcode(SER_DUP, "repeatedly referenced vector");
// A boxed float never contains further pointers, so there is no more
// to do here.
            goto up;

        case TAG_FIXNUM:
            w64 = int_of_fixnum(p);
            if (-16 <= w64 && w64 < 15)
            {   char msg[8];
                sprintf(msg, "int, value=%d", (int)w64);
                write_opcode(SER_FIXNUM | ((int)w64 & 0x1f), msg);
            }
            else
            {   char msg[32];
                sprintf(msg, "int value=%" PRId64, w64);
                if (w64 < 0)
                {   write_opcode(SER_NEGFIXNUM, msg);
                    write_u64(-w64-1);
                }
                else
                {   write_opcode(SER_POSFIXNUM, msg);
                    write_u64(w64);
                }
            }
            goto up;

        case TAG_HDR_IMMED:
// Immediate data (eg characters and SPIDs).
        {   char msg[40];
            uint64_t nn = ((uint64_t)p) >> (Tw+2);
            sprintf(msg, "char/spid, value=%#" PRIx64, (uint64_t)p);
            write_opcode(SER_CHARSPID, msg);
            write_u64(nn);
        }
        goto up;

        case TAG_FORWARD:
// Forwarding addresses should only be present while the garbage collector
// is active, and so ought not to be found. I will print a message and
// basically ignore them.
            fprintf(stderr, "\n+++ Forwarding address detected in heap scan\n");
            goto up;
    }

up:
    switch (b & BACKPOINTER_MASK)
{       default:
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

bool setup_codepointers = false;

LispObject Lserialize(LispObject nil, LispObject a)
{   if (!setup_codepointers)
    {   set_up_function_tables();
        setup_codepointers = true;
    }
    descend_symbols = false;
    sercounter = 0;
    hash_init(&repeat_hash, 13); // allow 8K entries to start with.
    scan_data(a);
    release_map();
    writer_setup_repeats();
    write_u64(repeat_heap_size);
    write_data(a);
    hash_finalize(&repeat_hash);
    if (repeat_heap_size != 0)
    {   repeat_heap_size = 0;
        free(repeat_heap);
    }
    repeat_heap = NULL;
    return onevalue(nil);
}

LispObject Lserialize1(LispObject nil, LispObject a)
{   if (!setup_codepointers)
    {   set_up_function_tables();
        setup_codepointers = true;
    }
    descend_symbols = true;
    sercounter = 0;
    hash_init(&repeat_hash, 13); // allow 8K entries to start with.
    scan_data(a);
    release_map();
    writer_setup_repeats();
    write_u64(repeat_heap_size);
    write_data(a);
    hash_finalize(&repeat_hash);
    if (repeat_heap_size != 0)
    {   repeat_heap_size = 0;
        free(repeat_heap);
    }
    repeat_heap = NULL;
    return onevalue(nil);
}

LispObject Lunserialize(LispObject nil, int nargs, ...)
{   LispObject r;
    serincount = 0;
    reader_setup_repeats(read_u64());
    r = serial_read();
    if (repeat_heap_size != 0)
    {   repeat_heap_size = 0;
        free(repeat_heap);
    }
    repeat_heap = NULL;
    return onevalue(r);
}

// Here I will comments on how the previous version of warm_setup (and
// hence "preserve") worked, and how the new one does. The intent is that this
// will first help me know what I am doing as I code the new version, and
// document some of the design decisions. Both the old ones and their
// consequences and the new ones and why I wanted to change things.
//
// First an overview of the old code. I dumped a heap image by taking
// each page of the heap and writing it out almost unaltered but with its
// address in memory attached. Well that was the original ideal but because
// pages wre not going to be loaded back at the same addresses and I could
// only guarantee consistency of relative addresses within a block I needed
// to "unadjust" each pointer in the heap so it became encoded as a
// block-number together with an offset. So I had to have code that
// scanned the heap parsing it to identify every object, and I needed to
// detect where within objects there were pointers. I also run a simplified
// zip-like compression process to keep image files compact.
//
// To reload I could originally just read back blocks and "adjust" to put
// pointers back to their native state. However a few years later I needed
// to support both 32 and 64-bit architectures and I wanted to allow images
// made on one to load on the other. That involved parsing blocks of memory
// and halving or doubling the width of pointers.
//
// To cope with native code entrypoints I re-ran the normal heap
// initialization code on an image once it had been reloaded. That puts the
// entrypoint of CAR back as it should, and similarly for all other
// built in functions. Doing things that way makes it way harder to cope with
// cases where functions have been undefined, redefined or had their
// definitions copied.
//
// Overall although the old scheme worked it was complicated and somewhat ugly.
// I wanted to to introduce an option whereby 32-bit machines could have
// 28-bit fixnums but 64-bit machines bigger ones - adapting the conversion
// of images across dump/restart for that was going to be messy. Supporting
// dynamically-compiled native code seemed awkward. The possibility of a trail
// of residual bugs was a worry.
//
// So now I will describe the newer scheme. It dumps a heap starting from
// every unambiguous lisp-base. In effect it is a print procedure that
// does a pre-scan of all the data so as to detect where structures are
// shared or looped, but then writes out the data in a sequential form.
// I already have a "printl" that prints potentially cyclic lists in
// normal character form - but the version used here uses a more compressed
// bytecode notation, and tried to represent common things particularly
// efficiently. Lists are in general transmitted with one byte for each CONS
// cell, and strings often have a single prefix byte ahead of the bytes that
// make up the string content. Creating the linear representation of data
// is done using a pointer-reversal scheme that temporarily overwrites things
// while writing them out, but by its nature restores them when it is
// complete. This results in the code using only bounded stack space. The
// reading code also uses pointer reversal for almost all its recursion.
//
// I believe that the new code ends up shorter and neater, and my hope is
// that it will lead to a more compact representation of heap images and that
// it will be fast. The previous one expected to be fast since the writing
// and reading of images was basically simple block IO operations, but the
// scanning of the head to alter the representationof pointers was messy and
// poitentially costly (but was a cache-friendly linear scan of memory). Here
// there is a risk that writing images may be more expensive, but I am
// expecting that loading will be at least as fast as it used to be.
//
// My very first experiment has been to start a cold-start CSL and go
// "preserve". That seems to create a serialized form of everything that is
// around 24K bytes long, while the image using the previous version was
// of size 43K. Until I can reload images and verify that everything works
// this is very provisional and uncertain, but is feels encouraging to
// me.

//
// There is some need to be careful here. While serializing everything the
// code will traverse through all the data structures that represent open
// streams. Stream objects have three initial items in them - a type,
// "write_data" and "read_data". The type information may be used in
// printing diagnostics if something fails. The read and write_data are
// used by synomym and broadcast streams as well as by streams that read
// and write from lists of character objects. A consequence of this is
// that although simple direct file I/O can be performed even in the middle
// of preserving an image (well it has to be!) synomym streams may not be
// used. In normal circumstances this means that the standard default
// input and output streams have to be avoided. This issue bit me when I tried
// using the Lisp "print" function from within the checkpoint code to help
// be generate debug/trace information: all went well until the standard
// output stream had some pointers in it reversed, and then everything
// collapsed miserably. Hence this comment.

void write_everything()
{   LispObject nil = C_nil;
    set_up_function_tables();
    copy_into_nilseg(false);
    if (!setup_codepointers)
    {   set_up_function_tables();
        setup_codepointers = true;
    }
    descend_symbols = true;
    sercounter = 0;
    hash_init(&repeat_hash, 13); // allow 8K entries to start with.
// First scan the components of NIL. I have to do this because even with
// descend_symbols set to true the scanning code views NIL as such a special
// case that it does not descend through it or view multiple references to
// it as worth noting.
    scan_data(qvalue(nil));
    scan_data(qenv(nil));
    scan_data(qpname(nil));
    scan_data(qplist(nil));
    scan_data(qfastgets(nil));
    scan_data(qpackage(nil));
// Next the major list-bases.
   for (int i = first_nil_offset; i<last_nil_offset; i++) scan_data(BASE[i]);
// The following two are not full list bases - they are weak pointers. I hope
// that in a while I will re-work how I get hash tables rehashed following
// garbage collection and preserve/restart do I will not end up needing these
// lists at all.
    scan_data(eq_hash_tables);
    scan_data(equal_hash_tables);
// Now I should have identified all cyclic and shared data - including
// eveything in the object list/package structures.
    release_map();
    writer_setup_repeats();
// Before I get to messy things I will write out some integer values.

    write_u64(miscflags);
    write_u64(gensym_ser);
    write_u64(print_precision);
    write_u64(current_modulus);
    write_u64(fastget_size);
    write_u64(package_bits);
    write_u64(modulus_is_large);
    write_u64(trap_floating_overflow);

// At the start of a heap image I have a CRC for the tables of function
// entrypoints, then the number of repeated objects.
    write_u64(function_crc);
    write_u64(repeat_heap_size);
// Now inspect all structures again, this time writing a serialized form
// for everything.

    write_data(qvalue(nil));
    write_data(qenv(nil));
    write_data(qpname(nil));
    write_data(qplist(nil));
    write_data(qfastgets(nil));
    write_data(qpackage(nil));
// Next the major list-bases.
    for (int i = first_nil_offset; i<last_nil_offset; i++) write_data(BASE[i]);
// The following two are not full list bases - they are weak pointers. I hope
// that in a while I will re-work how I get hash tables rehashed following
// garbage collection and preserve/restart do I will not end up needing these
// lists at all.
    write_data(eq_hash_tables);
    write_data(equal_hash_tables);
// Tidy up at the end. I do not logically need an explicit end of data marker
// in the serialised form, but putting one there seems lile a way to make
// me feel more robust against corrupred image files.
    write_opcode(SER_END, "end of data");
    hash_finalize(&repeat_hash);
    if (repeat_heap_size != 0)
    {   repeat_heap_size = 0;
        free(repeat_heap);
    }
    repeat_heap = NULL;
}

void warm_setup()
{
// I must start by getting the heaps so that allocation etc is possible.
    void *p;
    size_t i;
    LispObject nil = C_nil;
    p = vheap_pages[vheap_pages_count++] = allocate_page("vheap warm setup");
    vfringe = (LispObject)(8 + (char *)doubleword_align_up((intptr_t)p));
    vheaplimit = (LispObject)((char *)vfringe + (CSL_PAGE_SIZE - 16));

    p = heap_pages[heap_pages_count++] = allocate_page("heap warm setup");
    heaplimit = quadword_align_up((intptr_t)p);
    fringe = (LispObject)((char *)heaplimit + CSL_PAGE_SIZE);
    heaplimit = (LispObject)((char *)heaplimit + SPARE);

    set_up_function_tables();

    qheader(nil) = TAG_HDR_IMMED+TYPE_SYMBOL+SYM_SPECIAL_VAR;
    for (i=first_nil_offset; i<last_nil_offset; i++) BASE[i] = nil;
    *stack = nil;
    eq_hash_tables = equal_hash_tables = nil;
    qcount(nil) = 0;
// Make things GC safe first...
    qvalue(nil) = nil;
    qenv(nil) = nil;
    qpname(nil) = nil;
    qplist(nil) = nil;
    qfastgets(nil) = nil;
    qpackage(nil) = nil;
    copy_out_of_nilseg(false);
#define boffo_size 256
    boffo = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+boffo_size);
    memset((void *)((char *)boffo + (CELL - TAG_VECTOR)), '@', boffo_size);
    BASE[60] = boffo;

    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;

    miscflags = read_u64();
    gensym_ser = read_u64();
    print_precision = read_u64();
    current_modulus = read_u64();
    fastget_size = read_u64();
    package_bits = read_u64();
    modulus_is_large = read_u64();
    trap_floating_overflow = read_u64();

    uint64_t entrypt_checksum = read_u64();
    size_t repeatsize = read_u64();
    reader_setup_repeats(repeatsize);

// Now I can use serial_read...

    qvalue(nil) = serial_read();
    qenv(nil) = serial_read();
    qpname(nil) = serial_read();
    qplist(nil) = serial_read();
    qfastgets(nil) = serial_read();

// This next one is a BIGGY because the package structure is liable to
// include all other symbols, and through them basically everything!
    qpackage(nil) = serial_read();

// I want to be able to call validate_all() while I am doing this
// reading - and that may copy stuff into the BASE locations from elsewhere,
// so I need to be a bit indirect about loading values into there. Apologies!
    for (int i=first_nil_offset; i<last_nil_offset; i++)
    {   // fprintf(stderr, "About to read value for BASE[%d]\n", i);
        // for (int j=0; j<5; j++)
        //     fprintf(stderr, "%" PRIxPTR " ", stackbase[j]);
        // fprintf(stderr, " [%d]\n", (int)(stack-stackbase));
        // fflush(stderr);
        // validate_all("serial reading", __LINE__, __FILE__);
        LispObject v = serial_read();
        // fprintf(stderr, " = "); simple_print(v); fprintf(stderr, "\n");
        push(v);
    }
    eq_hash_tables = serial_read();
    equal_hash_tables = serial_read();
    for (int i=last_nil_offset-1; i>=first_nil_offset; i--)
        pop(BASE[i])
    copy_out_of_nilseg(false);

    if (read_opcode_byte() != SER_END)
    {   fprintf(stderr, "Out of step\n");
        myabort();
    }
#ifdef DEBUG_VALIDATE
    validate_all("warm setup", __LINE__, __FILE__);
#endif

    {   char endmsg[32];
        Iread(endmsg, 24);  // the termination record
//
// Although I check here I will not make the system crash if I see an
// error - at least until I have tested things and found this test
// properly reliable.
//
#ifdef COMMON
        if (strncmp(endmsg, "\n\nEnd of CCL dump file\n\n", 24) != 0)
#else
        if (strncmp(endmsg, "\n\nEnd of CSL dump file\n\n", 24) != 0)
#endif
        {   fprintf(stderr, "\n+++ Bad end record |%s|\n", endmsg);
        }
    }
    {   LispObject w = error_output;
        error_output = 0;
        IcloseInput();
        error_output = w;
    }
    if (repeat_heap_size != 0)
    {   repeat_heap_size = 0;
        free(repeat_heap);
    }
    repeat_heap = NULL;

    inject_randomness((int)clock());

//
// An explanation is needed here. Hash tables can be really odd things in
// that if they are keyed on the EQ test they are based on memory addresses
// that objects lie at. So the garbage collector has to do magic things with
// them! I therefore keep a list of all hash tables, but it must not be
// processed in a naive way. I keep it in a variable that is NOT in the range
// of places where the garbage collector normally looks. But when it comes
// to preserve and restart I need to save the information, so I have the two
// lists I need saved in the nilseg under the alias eq_hash_table_list and
// equal_hash_table_list. As soon as I can I extract them and put them
// back in the magic special places they need to live.
//
    eq_hash_tables = eq_hash_table_list;
    equal_hash_tables = equal_hash_table_list;
    eq_hash_table_list = equal_hash_table_list = nil;
    {   LispObject qq;
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
        {   if (!is_vector(qcar(qq)))
            {   fprintf(stderr, "qq=%p should be a vector\n", (void *)qcar(qq));
                exit(4);
            }
            rehash_this_table(qcar(qq));
        }
        for (qq = equal_hash_tables; qq!=nil; qq=qcdr(qq))
        {   if (!is_vector(qcar(qq)))
            {   fprintf(stderr, "qq=%p should be a vector\n", (void *)qcar(qq));
                exit(4);
            }
            rehash_this_table(qcar(qq));
        }
    }
// There are various things such as lispsystem* and the various standard
// output streams that may depend on the particular system I am loading on
// and so have to be set up as if from cold...
    set_up_variables(true);
// I used to have an elaborate scheme for saving and re-loading native code,
// but now if I ever wish to re-instate that I will want to implement it
// afresh.  I can look in old subversion revisions to see what I did before
// if that will help.
}

// end of serialize.cpp
