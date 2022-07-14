// bitmaps.h                                    Copyright (C) 2022 Codemist

#ifndef header_bitmaps_h
#define header_bitmaps_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

// Some support for bitmaps that us uint64_t as their base. This is in
// a separate file since it may be useful elsewhere. I also include
// support for finding the first and last bits within a 64-bit word, since
// those are operations used to speed up some of the searches here.

#include <cstdint>
#include <cstdio>

#ifndef __has_include
#define __has_include(name) 0
#endif // __has_include
#if __has_include(<bit>)
#include <bit>
#endif // <bit> header

using std::uint64_t;
using std::size_t;

#if defined _cpp_lib_bitops

// C++20 provides functions for counting zeros. Unlike the GNU intrinsics
// they have defined behaviour when presented with a zero word.

inline int nlz(uint64_t x)
{   return countl_zero(x);
}

inline int ntz(uint64_t x)
{   return countr_zero(x);
}

#elif defined __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. The intrinsic must never be
// called with a zero argument, so I filter that case.

// Count the leading zeros in a 64-bit word.

inline int nlz(uint64_t x)
{   return x==0 ? 64 : __builtin_clzll(x);
}

// Count the trailing zeros in a 64-bit word.

inline int ntz(uint64_t x)
{   return x==0 ? 64 : __builtin_ctzll(x);
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x |= x>>32;
// Now x is a number with all bits up as far as its highest one set, and I
// have achieved that without performing any tests. Now I can use a lookup
// table in much the same wau as I do for trailing zero bits.
    static int8_t nlzTable[67] =
    {   64,  63,  25,  62,  49,  24,  41,  61,  52,  48,
         5,  23,  45,  40,  10,  60,   0,  51,  54,  47,
         2,   4,  36,  22,  34,  44,  13,  39,  20,   9,
        17,  59,  32,  -1,  26,  50,  42,  53,   6,  46,
        11,   1,  55,   3,  37,  35,  14,  21,  18,  33,
        27,  43,   7,  12,  56,  38,  15,  19,  28,   8,
        57,  16,  29,  58,  30,  31,  -1
    };
    return nlzTable[x % 67];
}

// This code is to identify the least significant bit in a 64-bit
// value. The function leastBit() just removes all other bits. It is probably
// not going to be used a lot.

uint64_t leastBit(uint64_t n)
{   return n & (-n);
}

// ntz find the bit-number of the least significant bit, So here are some
// values it will return:
//    1      0
//    2      1
//    4      2
//    8      3
//   16      4
// etc. The name is for "Number of Trailing Zeros".
// If the input value is zero it returns 64, but the GNU builtin does not
// guarantee any such behaviour, so zero input should be considered illegal.

// This is related to the function intlog2() in tags.h, but that function
// is only to be applied on inputs that are a power of 2.

int ntz(uint64_t n)
{   static int8_t lsbTable[67] =
    {  64,   0,   1,  39,   2,  15,  40,  23,   3,  12,
       16,  59,  41,  19,  24,  54,   4,  -1,  13,  10,
       17,  62,  60,  28,  42,  30,  20,  51,  25,  44,
       55,  47,   5,  32,  -1,  38,  14,  22,  11,  58,
       18,  53,  63,   9,  61,  27,  29,  50,  43,  46,
       31,  37,  21,  57,  52,   8,  26,  49,  45,  36,
       56,   7,  48,  35,   6,  34,  33,  -1
    };
    else return lsbTable[leastBit(n) % 67];
}

#endif // __GNUC__

#define NLZ_DEFINED 1
#define NTZ_DEFINED 1


// These functions view map[] as an array of 64-bit values with bits counted
// least significant first. They set, clear or test bits. The ones that work
// on ranges handle bits from m up with a given length and the test returns
// true if any of the bits in the range are set.
// nextOneBit() and friends return the index of the next relevant set or
// cleared bit at or beyond the location specified, and need to know the
// size (measured in 64-bit words) of the map because there may not be a
// further bit to report. In that case they return SIZE_MAX.

// Everything here assumes that n is such that the nth bit is within the
// map array. Not overflow checks are made.

inline void setBit(uint64_t map[], size_t n)
{   size_t word = n/64;
    map[word] |= static_cast<uint64_t>(1) << (n%64);
}

inline void clearBit(uint64_t map[], size_t n)
{   size_t word = n/64;
    map[word] &= ~(static_cast<uint64_t>(1) << (n%64));
}

inline bool testBit(uint64_t map[], size_t n)
{   size_t word = n/64;
    return ((map[word] >> (n%64)) & 1) != 0;
}

// These work on the bits from m to m+length-1 inclusive.

inline void setBits(uint64_t map[], size_t m, size_t length)
{   static const uint64_t ones = static_cast<uint64_t>(-1);
    size_t n = m + length - 1;
    size_t word1 = m/64;
    size_t word2 = n/64;
    size_t bitpos1 = m%64;
    size_t bitpos2 = n%64;
    uint64_t mask1 = ones << bitpos1;
    uint64_t mask2 = ones >> (63-bitpos2);
    if (word1 == word2) map[word1] |= (mask1 & mask2);
    else
    {   map[word1] |= mask1;
        for (size_t k=word1+1; k<word2; k++) map[k] = ones;
        map[word2] |= mask2;
    }
}

inline void clearBits(uint64_t map[], size_t m, size_t length)
{   static const uint64_t ones = static_cast<uint64_t>(-1);
    size_t n = m + length - 1;
    size_t word1 = m/64;
    size_t word2 = n/64;
    size_t bitpos1 = m%64;
    size_t bitpos2 = n%64;
    uint64_t mask1 = ones << bitpos1;
    uint64_t mask2 = ones >> (63-bitpos2);
    if (word1 == word2) map[word1] &= ~(mask1 & mask2);
    else
    {   map[word1] &= ~mask1;
        for (size_t k=word1+1; k<word2; k++) map[k] = 0;
        map[word2] &= ~mask2;
    }
}

inline bool testBits(uint64_t map[], size_t m, size_t length)
{   static const uint64_t ones = static_cast<uint64_t>(-1);
    size_t n = m + length - 1;
    size_t word1 = m/64;
    size_t word2 = n/64;
    size_t bitpos1 = m%64;
    size_t bitpos2 = n%64;
    uint64_t mask1 = ones << bitpos1;
    uint64_t mask2 = ones >> (63-bitpos2);
    if (word1 == word2) return (map[word1] & mask1 & mask2) != 0;
    else
    {   if ((map[word1] & mask1) != 0) return true;
        for (size_t k=word1+1; k<word2; k++)
            if (map[k] != 0) return true;
        return (map[word2] & mask2) != 0;
    }
}

// This finds the next bit at or beyond n that is set supposing there is
// one present in the map. If not it returns SIZE_MAX.

inline size_t nextOneBit(uint64_t map[], size_t mapSize, size_t n)
{
// The first test has to allow for the possibility that it is within a
// single word of the map.
    size_t word = n/64;
    if (word >= mapSize) return SIZE_MAX;
    size_t bitpos = n%64;
    n -= bitpos;          // now n refers to a word boundary.
    uint64_t bits;
    static const uint64_t ones = static_cast<uint64_t>(-1);
    if ((bits = map[word] & (ones<<bitpos)) != 0)
        return n + ntz(bits);
// Skip past any words that are all zero in the map.
    do
    {   word++;
        if (word >= mapSize) return SIZE_MAX;
        n += 64;
    } while ((bits = map[word]) == 0);
    return n + ntz(bits);
}

inline size_t nextZeroBit(uint64_t map[], size_t mapSize, size_t n)
{
// The first test has to allow for the possibility that it is within a
// single word of the map.
    size_t word = n/64;
    if (word >= mapSize) return SIZE_MAX;
    size_t bitpos = n%64;
    n -= bitpos;          // now n refers to a word boundary.
    static const uint64_t ones = static_cast<uint64_t>(-1);
    uint64_t bits;
    if ((bits = ~map[word] & (ones<<bitpos)) != 0)
        return n + ntz(bits);
// Skip past any words that are all ones in the map.
    do
    {   word++;
        if (word >= mapSize) return SIZE_MAX;
        n += 64;
    } while ((bits = ~map[word]) == 0);
    return n + ntz(bits);
}

inline size_t previousOneBit(uint64_t map[], size_t n)
{   if (n == SIZE_MAX) return SIZE_MAX;
    size_t word = n/64;
    size_t bitpos = n%64;
    n -= bitpos;
    static const uint64_t ones = static_cast<uint64_t>(-1);
    uint64_t bits;
    if ((bits = map[word] & (ones >> (63-bitpos))) != 0)
        return n + 63 - nlz(bits);
    do
    {   if (word == 0) return SIZE_MAX;
        word--;
        n -= 64;
    } while ((bits = map[word]) == 0);
    return n + 63 - nlz(bits);
}

inline size_t previousZeroBit(uint64_t map[], size_t n)
{   if (n == SIZE_MAX) return SIZE_MAX;
    size_t word = n/64;
    size_t bitpos = n%64;
    n -= bitpos;
    static const uint64_t ones = static_cast<uint64_t>(-1);
    uint64_t bits;
    if ((bits = ~map[word] & (ones >> (63-bitpos))) != 0)
        return n + 63 - nlz(bits);
    do
    {   if (word == 0) return SIZE_MAX;
        word--;
        n -= 64;
    } while ((bits = ~map[word]) == 0);
    return n + 63 - nlz(bits);
}

#endif // header_bitmaps_h

// end of bitmaps.h

