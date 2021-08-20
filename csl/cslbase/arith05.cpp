//  arith05.cpp                            Copyright (C) 1990-2021 Codemist

//
// Arithmetic functions.
//    low-level 64/32 bit arithmetic, print_bignum
//

/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

#include "headers.h"



uint32_t Idiv10_9(uint32_t *qp, uint32_t high, uint32_t low)
//
// Same behaviour as Idivide(qp, high, low, 1000000000U).
// Used for printing only - i.e. only in this file
//
{   uint64_t p = ((uint64_t)high << 31) | (uint64_t)low;
    *qp = (uint32_t)(p / (uint64_t)1000000000U);
    return (uint32_t)(p % (uint64_t)1000000000U);
}

void print_bignum(LispObject u, bool blankp, int nobreak)
{   size_t len = length_of_header(numhdr(u))-CELL;
    size_t i, len1;
    LispObject w;
    char my_buff[24];    // Big enough for 2-word bignum value
    unsigned int line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    unsigned int column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, active_stream);
#ifdef DEBUG
// The next few lines are to help me track down bugs...
    {   int32_t d1 = bignum_digits(u)[(len-4)/4];
        if (!SIXTY_FOUR_BIT && len == 4)
        {   if (valid_as_fixnum(d1))
                std::printf("[%.8lx should be fixnum]", static_cast<long>(d1));
            if (signed_overflow(d1))
                std::printf("[%.8lx needs 2 words]", static_cast<long>(d1));
        }
        else if (SIXTY_FOUR_BIT && len == 4)
            std::printf("[%.8lx should be a fixnum]",
                        static_cast<long>(bignum_digits(u)[0]));
        if (SIXTY_FOUR_BIT && len == 8)
        {   int64_t v = ASL(bignum_digits64(u, 1), 31) +
                        bignum_digits(u)[0];
            if (valid_as_fixnum(v))
                std::printf("[%.8lx should be fixnum]", static_cast<long>(d1));
            if (signed_overflow(bignum_digits(u)[1]))
                std::printf("[%.8lx:%.8lx needs 3 words]",
                            static_cast<long>(d1), static_cast<long>(bignum_digits(u)[0]));
        }
        else
        {   int32_t d0 = bignum_digits(u)[(len-8)/4];
            if (signed_overflow(d1)) std::printf("[needs more words]");
            else if (d1 == 0 && (d0 & 0x40000000) == 0) std::printf("[shrink]");
            else if (d1 == -1 &&(d0 & 0x40000000) != 0) std::printf("[shrink]");
        }
    }
// end of temp code
#endif
// The code I have here looks DREADFUL and I believe I should be able to
// shrink it a lot - especially if I believe that int64_t is available
// as a 64-bit integer type. But despite being ugly and the case of one
// word bignums not being possible in a 64-bit world this should still work
// and so I will leave it alone for now...
    switch (len)
    {   case 4:         // one word bignum - especially easy!
        {   int32_t dig0 = bignum_digits(u)[0];
            uint32_t dig = dig0;
            int i = 0;
            if (dig0 < 0) dig = -dig0;
//
// I do all my conversion from binary to decimal by hand in this code,
// where once I used sprintf - but sprintf is somewhat more powerful
// than I need, and thus I expect it to be somewhat more costly.
//
            do
            {   int32_t nxt = dig % 10;
                dig = dig / 10;
                my_buff[i++] = static_cast<char>(nxt + '0');
            }
            while (dig != 0);
            if (dig0 < 0) my_buff[i++] = '-';
            if (blankp)
            {   if (nobreak==0 && column+i >= line_length)
                {   if (column != 0) putc_stream('\n', active_stream);
                }
                else putc_stream(' ', active_stream);
            }
            else if (nobreak==0 && column != 0 && column+i > line_length)
                putc_stream('\n', active_stream);
            while (--i >= 0) putc_stream(my_buff[i], active_stream);
        }
        return;
        case 8:        // two word bignum
        {
// I could (and probably should) re-work this to use int64_t... but I have
// other priorities for now!
            uint32_t d0 = bignum_digits(u)[0], d1 = bignum_digits(u)[1];
            uint32_t d0high, d0low, w;
            uint32_t p0, p1, p2;
            bool negativep = false;
            int i, j;
            if (((int32_t)d1) < 0)
            {   negativep = true;
                d0 = clear_top_bit(-(uint32_t)d0);
                if (d0 == 0) d1 = -(uint32_t)d1;
                else d1 = ~d1;
            }
            d0high = ((uint32_t)d0)>>16;
            d0low = d0 - (d0high << 16);
// Adjust for the fact that I packed just 31 bits into each word..
            if ((d1 & 1) != 0) d0high |= 0x8000U;
            w = d1 >> 1;
// d1 is at most 0x40000000 here, so no problem wrt sign
            d1 = w / 10000;
            w = d0high + ((w % 10000) << 16);
            d0high = w / 10000;
            w = d0low + ((w % 10000) << 16);
            d0low = w / 10000;
            p0 = w % 10000;        // last 4 digits of value

            w = d1;
            d1 = w / 10000;
            w = d0high + ((w % 10000) << 16);
            d0high = w / 10000;
            w = d0low + ((w % 10000) << 16);
            d0low = w / 10000;
            p1 = w % 10000;        // 4 more digits of value

// By now d1 is certainly less then 10000
            w = d0high + (d1 << 16);
            d0high = w / 10000;
            w = d0low + ((w % 10000) << 16);
            d0 = (w / 10000) + (d0high << 16);
            p2 = w % 10000;
            i = 0;
            for (j=0; j<4; j++)
                my_buff[i++] = static_cast<char>((p0 % 10) + '0'), p0 = p0/10;
            for (j=0; j<4; j++)
                my_buff[i++] = static_cast<char>((p1 % 10) + '0'), p1 = p1/10;
//
// Because the value used 2 words it must have more than 8 digits in it,
// but it may not have more than 12.  Therefore I am not certain whether
// all 4 digits of p2 are needed.
//
            if (d0 == 0)
            {   while (p2 != 0)
                    my_buff[i++] = static_cast<char>((p2 % 10) + '0'), p2 = p2/10;
            }
            else
            {   for (j=0; j<4; j++)
                    my_buff[i++] = static_cast<char>((p2 % 10) + '0'), p2 = p2/10;
                while (d0 != 0)
                    my_buff[i++] = static_cast<char>((d0 % 10) + '0'), d0 = d0/10;
            }
            if (negativep) my_buff[i++] = '-';
            if (blankp)
            {   if (nobreak==0 && column+i >= line_length)
                {   if (column != 0) putc_stream('\n', active_stream);
                }
                else putc_stream(' ', active_stream);
            }
            else if (nobreak==0 && column != 0 && column+i > line_length)
                putc_stream('\n', active_stream);
            while (--i >= 0) putc_stream(my_buff[i], active_stream);
            return;
        }
        default:
            break;  // general big case
    }
    {   Save save(u);
        len1 = CELL+4+(11*len)/10;
//
// To print a general big number I will convert it from radix 2^31 to
// radix 10^9.  This can involve increasing the number of digits by a factor
// of about 1.037, so the 10% expansion I allow for in len1 above should
// keep me safe.
//
        len1 = (size_t)doubleword_align_up((uintptr_t)len1);
        w = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, len1);
        save.restore(u);
    }
    bool sign = false;
    size_t len2;
    len = len/4;
    len1 = (len1-CELL)/4;
    if (((int32_t)bignum_digits(u)[len-1]) >= 0)
        for (i=0; i<len; i++) bignum_digits(w)[i] = vbignum_digits(u)[i];
    else
    {   int32_t carry = -1;
        sign = true;
        for (i=0; i<len; i++)
            // negate the number so I am working with a +ve value
        {   carry = ADD32(clear_top_bit(~bignum_digits(u)[i]),
                          top_bit(carry));
            bignum_digits(w)[i] = clear_top_bit(carry);
        }
    }
    len2 = len1;
    while (len > 1)
    {   int32_t k;
        int32_t carry = 0;
// This stack-check is so that I can respond to interrupts while I am part
// way through printing a bignum. In particular it will make it possible for
// the printing to be interrupted.
        if ((uintptr_t)stack >=
            ((uintptr_t)stackLimit | event_flag))
            respond_to_stack_event();
        // divide by 10^9 to obtain remainder
        for (k=len-1; k>=0; k--)
            Ddiv10_9(carry, bignum_digits(w)[k],
                     carry, bignum_digits(w)[k]);
        if (bignum_digits(w)[len-1] == 0) len--;
        bignum_digits(w)[--len2] = carry; // 9 digits in decimal format
    }
    {   Save save(w);
        uint32_t dig;
        int i;
        size_t len;
        if (bignum_digits(w)[0] == 0) dig = bignum_digits(w)[len2++];
        else dig = bignum_digits(w)[0];
        i = 0;
        do
        {   int32_t nxt = dig % 10;
            dig = dig / 10;
            my_buff[i++] = static_cast<char>(nxt + '0');
        }
        while (dig != 0);
        if (sign) my_buff[i++] = '-';
        len = i + 9*(len1-len2);
        if (blankp)
        {   if (nobreak==0 && column+len >= line_length)
            {   if (column != 0) putc_stream('\n', active_stream);
            }
            else putc_stream(' ', active_stream);
        }
        else if (nobreak==0 && column != 0 && column+len > line_length)
            putc_stream('\n', active_stream);
        while (--i >= 0) putc_stream(my_buff[i], active_stream);
        save.restore(w);
    }
    while (len2 < len1)
    {   uint32_t dig = bignum_digits(w)[len2++];
        int i;
        Save save(w);
        for (i=8; i>=0; i--)
        {   int32_t nxt = dig % 10;
            dig = dig / 10;
            my_buff[i] = static_cast<char>(nxt + '0');
        }
        for (i=0; i<=8; i++) putc_stream(my_buff[i], active_stream);
        save.restore(w);
        if ((uintptr_t)stack >=
            ((uintptr_t)stackLimit | event_flag))
            respond_to_stack_event();
    }
}

void print_bighexoctbin(LispObject u, int radix, int width,
                        bool blankp, int nobreak)
//
// This prints a bignum in base 16, 8 or 2.  The main misery about this is
// that internally bignums are stored in chunks of 31 bits, so I have
// to collect digits for printing in a way that can span across word
// boundaries.  There is also potential fun with regard to the display
// of negative values - here I will print a "~" mark in front but will
// then show them revealing the 2s complement representation used.
// The width specifier is intended to specify a minimum width to be
// used in the sense that printf uses the word "precision", so numbers
// will be padded with leading zeros (of f/7/1 if negative) if necessary.
// Well actually I have not implemented support for width specification
// yet. It will be wanted so that (prinhex 1 8) comes out as 00000001,
// for instance. So at present some C compilers will give me a warning about
// width being ignored - they are RIGHT!
//
{   size_t n = (bignum_length(u)-CELL-4)/4;
    uint32_t a=0, b=0;
    size_t len = 31*(n+1);
    int flag = 0, bits;
    bool sign = false, started = false;
    unsigned int line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    unsigned int column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, active_stream);
    if (radix == 16)
    {   bits = len % 4;
        len = len / 4;
        if (bits != 0) len++, bits = 4 - bits;
    }
    else if (radix == 8)
    {   bits = len % 3;
        len = len / 3;
        if (bits != 0) len++, bits = 3 - bits;
    }
    else
    {   bits = 0;
    }
//
// As I work down the bignum, b holds the next chunk of digits to be printed,
// and bits tells me how many valid bits are present in it.  I start off
// with bits non-zero to (in effect) adjoin a few bits from an implicit
// extra leading digit so as to make up to an integral multiple of 3 or 4
// bits in all when I am printing base 8 or 16.  The variable (len) now tells
// me how many digits remain to be printed.
//
    Save save(u);
    if ((int32_t)bignum_digits(u)[n] < 0)
    {   sign = true;
        len+=2;    // Allow extra length for sign marker and initial f/7/1
        if (radix == 16) flag = 0xf;
        else if (radix == 8) flag = 0x7;
        else flag = 0x1;
//
// Set the buffer b to have a few '1' bits at its top.
//
        if (bits != 0) b = ((int32_t)-1) << (32-bits);
    }
//
// I kill leading zeros - and since this is a real bignum there MUST be
// at least one nonzero digit somewhere, so I do not have to worry about the
// total supression of the value 0.  I will do something with leading 'f' or
// '7' digits for negative numbers.
//
    while (n+1 > 0 || bits > 0)
    {   if (radix == 16)
        {   a = (b >> 28);    // Grab the next 4 bits of the number
            b = b << 4;       // shift buffer to position the next four
            bits -= 4;
        }
        else if (radix == 8)
        {   a = (b >> 29);    // 3 bits
            b = b << 3;
            bits -= 3;
        }
        else
        {   a = (b >> 31);    // just 1 bit
            b = b << 1;
            bits -= 1;
        }
        if (bits < 0)     // there had not been enough buffered bits
        {   save.restore(u);
            b = bignum_digits(u)[n] << 1;
            n--;
            a |= b >> (32+bits);
            b = b << (-bits);
            bits += 31;
        }
        if (static_cast<int>(a) !=
            flag)  // leading '0' or 'f' (or '7') supression code
        {   if (!started)
            {   if (blankp)
                {   if (nobreak==0 && column+len >= line_length)
                    {   if (column != 0) putc_stream('\n', active_stream);
                    }
                    else putc_stream(' ', active_stream);
                }
                else if (nobreak==0 && column != 0 && column+len > line_length)
                    putc_stream('\n', active_stream);
                if (sign) putc_stream('~', active_stream);
                started = true;
                if (flag > 0) putc_stream(radix == 16 ? 'f' :
                                              radix == 8  ? '7' : '1', active_stream);
                flag = -1;
            }
        }
        len--;
        if (flag >= 0) continue;        // lose leading zeros (or F digits)
        if (a < 10) a += '0';
        else a += ('a' - 10);
        putc_stream(static_cast<int>(a), active_stream);
    }
}

// end of arith05.cpp
