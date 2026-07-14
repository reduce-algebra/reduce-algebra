// bigprint.cpp                                   Copyright A C Norman 2026


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

#include "arithlib.h"

namespace arithlib_implementation
{

std::intptr_t stringToBignum(const char* s)
{   bool sign = false;
    if (*s == '-')
    {   sign = true;
        s++;
    }
    std::size_t chars = std::strlen(s);
    std::size_t words = 1 + (108853*static_cast<Digit>
                             (chars))/0x200000;
// I have predicted the number of 64-bit digits that will be needed to
// represent an s-digit (decimal) number based an approximation
// 108853/2^21 for log(10)/log(2^64). In 64-bit arithmetic the numerator
// here will not overflow until you have an improbable string of length
// 2^47 as input! The division by a power of 2 should be done very
// rapidly as a shift. I rather expect this calculation to give a rather
// good measure of how many 64-bit words will be needed! It must never be an
// overestimate so that the vector that I allocate never overflows. Somewhat
// rarely it will be and overestimate and it will be necessary to trim the
// vector at the end.
    std::uint64_t* r = reserve(words);
    for (std::size_t i=0; i<words; i++) r[i] = 0;
// Now for each chunk of digits NNNN in the input I want to go in effect
//     r = 10^19*r + NNNN;
// where the number 19 is used because 10^19 is the largest power of 10
// that fits in a 64-bit word.
    std::size_t next = 19*((chars-1)/19);
    while (chars != 0)
    {   Digit d = 0;
// assemble 19 digit blocks from the input into a value (d).
        while (chars != next)
        {   d = 10*d + (*s++ - '0');
            chars--;
        }
        next -= 19;
// now perform r = 10^19*r + d to consolidate into the eventual result.
        for (std::size_t i=0; i<words; i++)
            multiply64(r[i], ten19, d, d, r[i]);
    }
    std::size_t n1 = words;
// Here I may be negating a positive number, and in 2s complement that
// can never lead to a number growing in length.
    if (sign)
    {   internalNegate(r, words, r);
        truncateNegative(r, n1);
    }
// However I could not have been precisely certain how many 64-bit words were
// needed and I arranged that any error was conservative - ie allocating
// more that would eventually be used.
    else truncatePositive(r, n1);
    return confirmSize(r, words, n1);
}
// The next functions are a key one for printing values. They convert a
// bignum so that it is still stored as a sequence of digits each within
// a 64-bit work, but now each digit will be be in the range 0 - (10^19-1)
// so that the value is in effect represented base 10^19. From that state
// printing it in decimal becomes easy!


// This first one takes a number represented base 2^64 with digits
// 0 to n-1 and divides it by 10^19, returning the remainder and
// setting both the digits and its length suitably to be the quotient.
// The number is POSITIVE here. Note that the function overwrites its input
// with the quotient.

Digit short_divide_ten_19(std::uint64_t* r,
                                         std::size_t &n)
{   Digit hi = 0;
    std::size_t i=n-1;
    for (;;)
    {   divide64(hi, r[i], ten19, r[i], hi);
        if (i == 0) break;
        i--;
    }
    if (r[n-1] == 0) n--;
    return hi;
}

// I want an estimate of the number of bytes that it will take to
// represent a number when I convert it to a string.
//
// I will work through an example. Consider the input 12024932 = 0xb77c64.
// [I use this value because at one time it revealed a mistake I had made!]
// This value uses 24 bits, ie its value is at least 2^23 (8388608) and
// it is less than 2^26 (16777216). log10(2^24) is 7.2247... so in decimal
// the number will use 7.2 digits, well that must be rounded up to 8.
// log10(2^24) = 24*log10(2) = 24*0.301030.. < 24*(617/2048) [because that
// fraction = 0.30127.. > log10(2)]. So if one the number of decimal digits
// that can be generated will be ceil(24*617/2048). I will compute that by
// forming a quotient that is truncated towards zero and then adding 1, and
// in this case this yields 8 as required. For negative numbers I will add 1
// to allow for a "-" sign.
std::size_t predictSize_in_bytes(const std::uint64_t* a,
                                        std::size_t lena)
{
// I am first going to estimate the size in BITS and then I will
// see how that maps onto bytes.
    std::size_t r = bignumBits(a, lena);
    r = 1 + static_cast<std::size_t>(
            (617*static_cast<Digit>(r))/2048);
    if (negative(a[lena-1])) r += 2; // allow space for a "-" sign.
    return r;
}
std::size_t bignumToStringLength(std::uint64_t* a, std::size_t lena)
{   if (lena == 1)
    {   SignedDigit v = a[0];
// Note that the negative numbers checked against are 1 digit shorter so as
// to allow space for the "-" sign.
        if (v <= 9999999 && v >= -999999) return 7;
        else if (v <= 999999999999999 && v >= -99999999999999) return 15;
        else return 23;
    }
    else return predictSize_in_bytes(a, lena);
}

// The "asUnsigned" option here is not for general use - it is JUST for
// internal debugging because at times I work with values that are known
// to be positive and so where the top digit must be treated as unsigned...
std::size_t bignumToString(char* result, std::size_t m,
                                  std::uint64_t* a, std::size_t lena,
                                  bool asUnsigned)
{
// Making one-word numbers a special case simplifies things later on! It may
// also make this case go just slightly faster.
    if (lena == 1)
    {   Digit v = a[0];
        bool sign;
        if (negative(v) && !asUnsigned)
        {   sign = true;
            v = -v;
        }
        else sign = false;
        char buffer[24];
        std::size_t len = 0;
        while (v != 0)
        {   buffer[len++] = '0' + v%10;
            v = v/10;
        }
// Now I have the decimal digits on the number in my buffer, with the
// least significant first and the most significant last. Insert the sign bit
// if needed (and deal with the special case of zero).
        if (sign) buffer[len++] = '-';
        else if (len == 0) buffer[len++] = '0';
        for (std::size_t i=0; i<len; i++) result[i] = buffer[len-i-1];
        return len;
    }
// The size (m) for the block of memory that I put my result in is
// such that it could hold the string representation of my input, and
// I estimate that via predictSize_in_bytes(). Well the smallest bignum
// that will need 2 words will be {0,0x8000000000000000}, ie 2^63. That
// will need 19 decimal digits plus space for a sign bit, so there will be
// at least 20 bytes allocated for the printed representation of any 2-word
// bignum, and at least 40 for a 3-word value, at least 59 for a 4-word one
// etc. This means that the space I will allocate here for the result
// leaves me with plenty of workspace to use while constructing the
// output string. The case liable to be tightest will be that of the
// smallest 2-woed bignum, so if I ensure that is OK all the rest will
// certainly be safe.
//
// I am going to build up (decimal) digits of the converted number by
// repeatedly dividing by 10^19. Each time I do that the remainder I
// amd left with is the next low 19 decimal digits of my number. Doing the
// divisions needs a vector to store the number I am dividing by 10^19 and
// to put the quotient, and I do not want to corrupt my original input, so
// I will copy my input into a fresh vector. And I will force it to be
// positive. The made-positive version might have a leading digit with
// its top bit set - that will not worry me because I view it as unsigned.
//
// I have allocated the space that will be needed for the eventual string of
// characters. I will use that space to save numeric values along the way, so
// here I cast so I can use that same memory as a vector of 64-bit integers.
// I will only ever access data in the format that it was placed into memory!
// Note that this will assume that the string data was allocated so as to
// be aligned suitably for uint64_t values.
    std::uint64_t* r = reinterpret_cast<std::uint64_t*>(result);
    std::size_t i;
// For the edge case lena==2 and m==20. I copy 2 words across. That will leave
// 4 bytes unused.
    for (i=0; i<lena; i++) r[i] = a[i];
    for (; i<m/sizeof(Digit); i++) r[i] = 0;
// Make the number positive
    bool sign = false;
    if (negative(r[lena-1]) && !asUnsigned)
    {   sign = true;
        internalNegate(r, lena, r);
    }
// Now my number is positive and is of length lena, but the vector it is
// stored in is length m with m usefully larger than lena. I will repeatedly
// divide by 10^19 and each time I do that I can store the remainder working
// down from the top of the vector. That should JUST keep up so that I
// never overwrite digits of the reducing part! I will stop when the
// number I have been working with end up < 10^19.
    std::size_t p = m/sizeof(Digit)
                    -1; // where to put next output digit
// Each value written into the vector here will stand for 19 decimal
// digits, and will use 8 bytes. So here the nastiest case will be when the
// number of decimal digits to end up with is 7 mod 8 (so that I lose as
// much space as possible) and the number is as large as possible. My
// belief is that numbers from 10^16 upwards will lead to there being enough
// space.
    while (lena > 1 || r[0] > ten19)
    {   Digit d = short_divide_ten_19(r, lena);
        r[p--] = d;
    }
    r[p] = r[0];
// Now I have the data that has to go into my result as a sequence of
// digits base 10^19, with the most significant one first. Convert
// to character data. I write in the string data just over what has been
// digits data, and I have arranged to position everything to (just)
// avoid overwriting myself.
    Digit top = r[p++];
    if (top == 0) top = r[p++]; // discard potential leading zero!
// Get a pointer into the buffer as character data...
    char* p1 = reinterpret_cast<char*>(result);
    std::size_t len = 0;
    if (sign)
    {  * p1++ = '-';
        len = 1;
    }
// I am going to convert my numbers to decimal using explicit code here.
// in an earlier draft I used sprintf(), however that adds unnecessary
// overhead.
    char buffer[24];
    int bp = 0;
// The first part of the number is printed naturally so that it only
// uses as many bytes of output as it needs.
    do
    {   buffer[bp++] = '0' + top%10;
        top = top/10;
    }
    while (top != 0);
    do
    {  * p1++ = buffer[--bp];
        len++;
    }
    while (bp != 0);
    while (p < m/sizeof(Digit))
    {
// I will always pick up the number I am going to expand before writing any
// digits into the buffer.
        top = r[p++];
// For subsequent chunks I want to print exactly 19 decimal digits.
        for (std::size_t i=0; i<18; i++)
        {   p1[18-i] = '0' + top%10;
            top = top/10;
        }
       * p1 = '0' + static_cast<int>(top);
        p1 += 19;
        len += 19;
    }
// To convince myself that this is safe consider when I pick up the final
// chunk. It will turn into 19 bytes of output, so where it comes from must
// be no more than 19 bytes before the length (m) of the final string, because
// otherwise it would have got clobbered when I unpacked the previous chunk.
// But this final chunk is itself 8 bytes wide and there can be up to 7 bytes
// beyond it that are there to support proper alignment - so that last chunk
// lives within the final 15 bytes of the buffer and that is a fortiori within
// the last 19 as required.
    return len;
}
string_handle bignumToString(std::uint64_t* a,
                                    std::size_t lena,
                                    bool asUnsigned)
{   std::size_t len = bignumToStringLength(a, lena);
    char* s = reserveString(len);
    std::size_t final_len = bignumToString(s, len, a, lena,
                            asUnsigned);
    return confirmSizeString(s, len, final_len);
}
string_handle bignumToString(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t lena;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);   // This is sort of faking a 1-digit bignum
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        lena = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        lena = numberSize(a);
    }
    return bignumToString(a, lena);
}

// As well as converting to decimal I can do hex, octal or binary!
std::size_t bignumToStringHexLength(std::intptr_t aa)
{   std::size_t n = IntegerLength::op(aa);
    return (n+3)/4;
}
string_handle bignumToStringHex(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char* r = reserveString(1);
        std::strcpy(r, "0");
        return confirmSizeString(r, 1, 1);
    }
// printing in hexadecimal should be way easier!
    std::size_t m = 16*n;
    Digit top = a[n-1];
    bool sign = negative(top);
    if (sign)
    {   m += 2; // for "~f"
        while ((top>>60) == 0xf)
        {   top = top << 4;
            m--;
        }
    }
    else
    {   while (top == 0)
        {   n--;
            top = a[n-1];
        }
        while ((top>>60) == 0)
        {   top = top << 4;
            m--;
        }
    }
    char* r = reserveString(m);
    char* p = reinterpret_cast<char*>(r);
    top = a[n-1];
    if (sign)
    {  * p++ = '~';
       * p++ = 'f';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   Digit v = a[n-i-1];
        for (int j=0; j<16; j++)
        {   int d = static_cast<int>(v >> (60-4*j)) & 0xf;
            if (!started)
            {   if ((sign && d==0xf) ||
                    (!sign && d==0)) continue;
                started = true;
            }
           * p++ = "0123456789abcdef"[d];
        }
    }
    return confirmSizeString(r, m, p-reinterpret_cast<char*>(r));
}
std::size_t bignumToStringOctalLength(std::intptr_t aa)
{   std::size_t n = IntegerLength::op(aa);
    return (n+2)/3;
}
string_handle bignumToStringOctal(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
    std::size_t width = (64*n +
                         2)/3; // raw number of octal digits needed.
    Digit top = a[n-1];
    bool sign = negative(top);
// There is a slight misery in that 64 is not a multiple of 3 (!) and so
// the octal representation of a value has some digits that depend on a pair
// of adjacent words from the bignum.
    std::size_t
    nn;  // will be the number of characters used in the output
    if (sign)
    {   while (readU3(a, n, width-1) == 7 && width > 1) width--;
        nn = width+2;
    }
    else
    {   while (readU3(a, n, width-1) == 0 && width > 1) width--;
        nn = width;
    }
    char* r = reserveString(nn);
    char* p = reinterpret_cast<char*>(r);
    if (sign)
    {  * p++ = '~';
       * p++ = '7';
    }
    for (std::size_t i=0; i<width; i++)
       * p++ = '0' + readU3(a, n, width-i-1);
    return confirmSizeString(r, nn, p-reinterpret_cast<char*>(r));
}
std::size_t bignumToStringBinaryLength(std::intptr_t aa)
{   return IntegerLength::op(aa);
}
string_handle bignumToStringBinary(std::intptr_t aa)
{   std::uint64_t* a;
    Digit v[1];
    std::size_t n;
    if (storedAsFixnum(aa))
    {   v[0] = intOfHandle(aa);
        a = reinterpret_cast<std::uint64_t*>(&v[0]);
        n = 1;
    }
    else
    {   a = vectorOfHandle(aa);
        n = numberSize(a);
    }
// Making the value zero a special case simplifies things later on!
    if (n == 1 && a[0] == 0)
    {   char* r = reserveString(1);
        std::strcpy(r, "0");
        return confirmSizeString(r, 1, 1);
    }
    std::size_t m = 64*n;
    Digit top = a[n-1];
    bool sign = negative(top);
    if (sign)
    {   m += 2; // for "~1"
        while ((top>>63) == 1)
        {   top = top << 1;
            m--;
        }
    }
    else
    {   if (top == 0) m -= 64;
        else while ((top>>63) == 0)
        {   top = top << 1;
            m--;
        }
    }
    char* r = reserveString(m);
    char* p = r;
    top = a[n-1];
    if (sign)
    {  * p++ = '~';
       * p++ = '1';
    }
    bool started = false;
    for (std::size_t i=0; i<n; i++)
    {   Digit v = a[n-i-1];
        for (int j=0; j<64; j++)
        {   int d = static_cast<int>(v >> (63-j)) & 0x1;
            if (!started)
            {   if ((sign && d==1) ||
                    (!sign && d==0)) continue;
                started = true;
            }
           * p++ = '0' + d;
        }
    }
    return confirmSizeString(r, m, p-reinterpret_cast<char*>(r));
}

}; // end of namespace

// end of bigprint.cpp
