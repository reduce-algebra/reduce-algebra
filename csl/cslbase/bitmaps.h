// bitmaps.h                                    Copyright (C) 2023 Codemist

#ifndef header_bitmaps_h
#define header_bitmaps_h 1

// $Id$


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

// Some support for bitmaps that us uint64_t as their base. This is in
// a separate file since it may be useful elsewhere. I also include
// support for finding the first and last bits within a 64-bit word, since
// those are operations used to speed up some of the searches here.

// I should cross reference std::bitset which provides packed bit arrays,
// but my version here provides setting, clearing and testing of ranges
// of bits not just individual ones, and it gives me functions that search
// for the previous or next set or clear bit.
// I should possibly (probably!) bring my naming into step with std::bitset
// for the operations that are supported there.

#include <cstdint>
#include <cstdio>

#ifndef __has_include
#define __has_include(name) 0
#endif // __has_include

#if __has_include(<bit>)
#include <bit>
#endif // <bit> header
#if __has_include(<bitset>)
#include <bitset>
#endif // <bitset> header

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

inline int countBits(uint64_t x)
{   return std::popcount(x);
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

inline int countBits(uint64_t x)
{   return __builtin_popcount(x);
}

#else // __GNUC__

// A generic implementation just in case that is needed!

inline int nlz(uint64_t x)
{   x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x |= x>>32;
// Now x is a number with all bits up as far as its highest one set, and I
// have achieved that without performing any tests.
// 2 is a primitive root mod 67, so all the values of 2^k (0<=k<64) are
// distinct mod 67. So the same will apply for (2^k-1) which are the
// values I have here. So a simple lookup in a table of size 67 does the
// job for me. I will fill the table using code here that computes the
// relevant values since that feels safer than having a table of "magic
// numbers".
    auto nlzf = [](int n)
    {   if (n==0) return 64;
        uint64_t v = 0;
        int r = -1;
        for (int k=0; k<64; k++)
        {   v = 2*v + 1;
            if (v%67 == n) r = 63-k;
        }
        return r;
    };
// The way this is written out is tolerable because 6y is a reasonably
// small number, but it would have been neater if C++ provided a way to
// initialize arrays a bit like this. It does if one uses std::vector
// rather than a plain array.
    constexpr static int8_t nlzTable[67] =
    {   nlzf( 0), nlzf( 1), nlzf( 2), nlzf( 3), nlzf( 4),
        nlzf( 5), nlzf( 6), nlzf( 7), nlzf( 8), nlzf( 9),
        nlzf(10), nlzf(11), nlzf(12), nlzf(13), nlzf(14),
        nlzf(15), nlzf(16), nlzf(17), nlzf(18), nlzf(19),
        nlzf(20), nlzf(21), nlzf(22), nlzf(23), nlzf(24),
        nlzf(25), nlzf(26), nlzf(27), nlzf(28), nlzf(29),
        nlzf(30), nlzf(31), nlzf(32), nlzf(33), nlzf(34),
        nlzf(35), nlzf(36), nlzf(37), nlzf(38), nlzf(39),
        nlzf(40), nlzf(41), nlzf(42), nlzf(43), nlzf(44),
        nlzf(45), nlzf(46), nlzf(47), nlzf(48), nlzf(49),
        nlzf(50), nlzf(51), nlzf(52), nlzf(53), nlzf(54),
        nlzf(55), nlzf(56), nlzf(57), nlzf(58), nlzf(59),
        nlzf(60), nlzf(61), nlzf(62), nlzf(63), nlzf(64),
        nlzf(65), nlzf(66)
    };
    return nlzTable[x % 67];
}

// This code is to identify the least significant bit in a 64-bit
// value. The function leastBit() just removes all other bits.

inline uint64_t leastBit(uint64_t n)
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

inline int ntz(uint64_t n)
{   auto ntzf = [](int n)
    {   if (n==0) return 64;
        uint64_t v=0;
        int r = -1;
        for (int k=0; k<64; k++)
        {   v = 1ULL<<k;
            if (v%67 == n) r = k;
        }
        return r;
    };
    constexpr static int8_t ntzTable[67] =
    {   ntzf( 0), ntzf( 1), ntzf( 2), ntzf( 3), ntzf( 4),
        ntzf( 5), ntzf( 6), ntzf( 7), ntzf( 8), ntzf( 9),
        ntzf(10), ntzf(11), ntzf(12), ntzf(13), ntzf(14),
        ntzf(15), ntzf(16), ntzf(17), ntzf(18), ntzf(19),
        ntzf(20), ntzf(21), ntzf(22), ntzf(23), ntzf(24),
        ntzf(25), ntzf(26), ntzf(27), ntzf(28), ntzf(29),
        ntzf(30), ntzf(31), ntzf(32), ntzf(33), ntzf(34),
        ntzf(35), ntzf(36), ntzf(37), ntzf(38), ntzf(39),
        ntzf(40), ntzf(41), ntzf(42), ntzf(43), ntzf(44),
        ntzf(45), ntzf(46), ntzf(47), ntzf(48), ntzf(49),
        ntzf(50), ntzf(51), ntzf(52), ntzf(53), ntzf(54),
        ntzf(55), ntzf(56), ntzf(57), ntzf(58), ntzf(59),
        ntzf(60), ntzf(61), ntzf(62), ntzf(63), ntzf(64),
        ntzf(65), ntzf(66)
    };
    return ntzTable[leastBit(n) % 67];
}

// The version here is expected to be a good one when the expected number
// of set bits is small.

inline int countBits(uint64_t x)
{   int r = 0;
    while (x != 0)
    {   r++;
        x -= x & (-x);
    }
    return r;
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
// size (measured in bits) of the map because there may not be a further
// bit to report. In that case they return SIZE_MAX.

// Everything here assumes that n is such that the nth bit is within the
// map array. No overflow checks are made.

inline void setBit(uint64_t map[], size_t n)
{   map[n/64] |= 1ULL << (n%64);
}

inline void clearBit(uint64_t map[], size_t n)
{   map[n/64] &= ~(1ULL << (n%64));
}

inline void flipBit(uint64_t map[], size_t n)
{   map[n/64] ^= 1ULL << (n%64);
}

inline bool testBit(uint64_t map[], size_t n)
{   return ((map[n/64] >> (n%64)) & 1) != 0;
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

inline void flipBits(uint64_t map[], size_t m, size_t length)
{   static const uint64_t ones = static_cast<uint64_t>(-1);
    size_t n = m + length - 1;
    size_t word1 = m/64;
    size_t word2 = n/64;
    size_t bitpos1 = m%64;
    size_t bitpos2 = n%64;
    uint64_t mask1 = ones << bitpos1;
    uint64_t mask2 = ones >> (63-bitpos2);
    if (word1 == word2) map[word1] ^= (mask1 & mask2);
    else
    {   map[word1] ^= mask1;
        for (size_t k=word1+1; k<word2; k++) map[k] ^= ones;
        map[word2] ^= mask2;
    }
}

// Count the number of 1 bits in the specified range.

inline int countBits(uint64_t map[], size_t m, size_t length)
{   static const uint64_t ones = static_cast<uint64_t>(-1);
    size_t n = m + length - 1;
    size_t word1 = m/64;
    size_t word2 = n/64;
    size_t bitpos1 = m%64;
    size_t bitpos2 = n%64;
    uint64_t mask1 = ones << bitpos1;
    uint64_t mask2 = ones >> (63-bitpos2);
    if (word1 == word2) return countBits(map[word1] & mask1 & mask2);
    else
    {   int r = countBits(map[word1] & mask1);
        for (size_t k=word1+1; k<word2; k++)
            r += countBits(map[k]);
        return r + countBits(map[word2] & mask2);
    }
}

// testBits(map, start, length) == (countBits(map, start, length) != 0)

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
// one present in the map. If not it returns SIZE_MAX. Note that the
// mapSize is counting in bits.

inline size_t nextOneBit(uint64_t map[], size_t mapSize, size_t n)
{   if (n >= mapSize) return SIZE_MAX;
// The first test has to allow for the possibility that it is within a
// single word of the map.
    size_t word = n/64;
    size_t bitpos = n%64;
    n -= bitpos;          // now n refers to a word boundary.
    uint64_t bits;
    static const uint64_t ones = static_cast<uint64_t>(-1);
    if ((bits = map[word] & (ones<<bitpos)) != 0)
        return n + ntz(bits);
// Skip past any words that are all zero in the map.
    do
    {   word++;
        n += 64;
        if (n >= mapSize) return SIZE_MAX;
    } while ((bits = map[word]) == 0);
    n += ntz(bits);
    if (n >= mapSize) return SIZE_MAX;
    else return n;
}

// Note that in these search functions mapSize does not need to be
// a multiple of 64. The size is specified in bits not bytes or words.

inline size_t nextZeroBit(uint64_t map[], size_t mapSize, size_t n)
{   if (n >= mapSize) return SIZE_MAX;
// The first test has to allow for the possibility that it is within a
// single word of the map.
    size_t word = n/64;
    size_t bitpos = n%64;
    n -= bitpos;          // now n refers to a word boundary.
    static const uint64_t ones = static_cast<uint64_t>(-1);
    uint64_t bits;
    if ((bits = ~map[word] & (ones<<bitpos)) != 0)
        return n + ntz(bits);
// Skip past any words that are all ones in the map.
    do
    {   word++;
        n += 64;
        if (n >= mapSize) return SIZE_MAX;
    } while ((bits = ~map[word]) == 0);
    n += ntz(bits);
    if (n >= mapSize) return SIZE_MAX;
    else return n;
}

// When I look for a previous 1 or 0 bit I will search all the way
// to the start of the array. I could provide a further overload that
// searched backwards down as far as a specified limit, but at present
// I do not need that...

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

