// bigvector.h                                    Copyright A C Norman 2017


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

#ifndef __bigvector_h
#define __bigvector_h 1

static inline bool is_power_of_two(uint64_t n)
{    return (n == (n & (-n)));
}

static inline int intlog2(uint64_t n)
{
// This fragment takes a 64-bit number that is a power of 2 and
// finds its logarithm, ie the number of bits that 1 needs to be shifted
// left to yield it. The function will return garbage if its input is
// not a power of 2.
//
// This table works because it is of length 67 and that is a prime, so
// the sequence 2^i mod 67 cycles through 1 .. 66 as I runs from 0 to 65,
// and 2^66 = 2^0 (mod 67). To help show this I have annotated the items at
// offsets 1, 2, 4, 8, 16, 32 and 64.
    static const unsigned char intlog2_table[] =
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
    return intlog2_table[n % (sizeof(intlog2_table)/sizeof(intlog2_table[0]))];
}


// In CSL the raw data only allows vectors of up to the size of a page.
// So to handle larger vectors I have a segmented representation with
// a top level "index vector" whose entries are all vectors that contain the
// actual data. The inline functions here provide access to these. Any
// vectors smaller than the chunk size will be represented directly, and
// operations on it will then only suffer the cost of an extra test on its
// header word.

static bool is_large_vector(LispObject v)
{   return type_of_header(vechdr(v)) == TYPE_INDEXVEC;
}

// This returns the number of bytes of DATA, and does not include the
// size of the header word(s).

static inline size_t bytes_in_large_vector(LispObject v)
{   if (is_large_vector(v))
    {   size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
// See that the final chunk has its length treated individually. This
// adds to the cost, but the extra cost only arises when the vector is
// rather large to start with, and so I am not going to worry.
        return VECTOR_CHUNK_BYTES*(n-1) +
               length_of_header(vechdr(elt(v, n-1))) - CELL;
    }
    else return length_of_header(vechdr(v)) - CELL;
}

static inline size_t cells_in_large_vector(LispObject v)
{   return bytes_in_large_vector(v)/CELL;
}

// the table of free vectors is not saved across checkpoint/restore operations,
// and so issues of 64- vs 32-bit sizing in that context do not arise.

static inline void discard_basic_vector(LispObject v)
{   size_t n = length_of_header(vechdr(v)) - CELL;
    if (is_power_of_two(n))    // save if this has byte-count 2^i
    {   int i = intlog2(n);    // identify what power of 2 we have
        if (i <= LOG2_VECTOR_CHUNK_BYTES)
        {   elt(v, 0) = free_vectors[i];
// I put the discarded vector in the free-chain as a "simple vector"
// regardless of what it used to be. If it has contained binary information
// its contents will not ce GC safe - but the GC should never encounter it
// so that should not matter.
            vechdr(v) = TYPE_SIMPLE_VEC +
                        ((n+CELL) << (Tw+5)) +
                        TAG_HDR_IMMED;
            v = (v & ~(uintptr_t)TAG_BITS) | TAG_VECTOR;
            free_vectors[i] = v;
        }
    }
}

static inline void discard_large_vector(LispObject v)
{   if (is_large_vector(v))
    {   size_t n1 = length_of_header(vechdr(v))/CELL - 1;
        for (size_t i=0; i<n1; i++)
            discard_basic_vector(elt(v, i));
    }
    discard_basic_vector(v);   
}

#define VECTOR_CHUNK_CELLS (VECTOR_CHUNK_BYTES/CELL)

static inline LispObject& large_elt(LispObject v, size_t n)
{   if (is_large_vector(v))
        return elt(elt(v, n/VECTOR_CHUNK_CELLS), n%VECTOR_CHUNK_CELLS);
    else return elt(v, n);
}

// At present I do not make large bignums or vectors of 32-bit integers,
// but this would provide access.

#define VECTOR_CHUNK_INT32S (VECTOR_CHUNK_BYTES/sizeof(int32_t))

static inline int32_t& large_ielt32(LispObject v, size_t n)
{   if (is_large_vector(v))
        return ielt32(elt(v, n/VECTOR_CHUNK_INT32S), n%VECTOR_CHUNK_INT32S);
    else return ielt32(v, n);
}

// At present I do not make large strings (or BPS or byte-vectors..),
// but if I ever did then this would provide access

static inline char& large_celt(LispObject v, size_t n)
{   if (is_large_vector(v))
        return celt(elt(v, n/VECTOR_CHUNK_BYTES), n%VECTOR_CHUNK_BYTES);
    else return celt(v, n);
}

// I could easily provide similar code for other flavours of vector. If I
// felt I really needed it! For 64-bit and 128-bit contents I would be
// relying on VECTOR_CHUNK_BYTES being a multiple of the data width so
// that each single item was fully within one chunk or another.

// Note that serialize.cpp treats vectors at a level of abstraction
// where the concept of large vectors being a single item with an
// index and a data layer is not helpful - the code there handles
// cases as just vectors of vectors. Thus there is no need for
// a "large_vselt" accessor.

#endif // __bigvector_h

// end of bigvector.h
