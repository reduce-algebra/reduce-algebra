//  arith07.cpp                           Copyright (C) 1990-2026 Codemist

//
// Arithmetic functions.  negation plus a load of Common Lisp things
// for support of complex numbers.
//
//

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

#include "headers.h"

namespace CSL_LISP
{

#ifndef ARITHLIB

LispObject copyb(LispObject a)
//
// copy a bignum.
//
{   LispObject b;
    size_t len = bignum_length(a), i;
    b = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, len);
    len = (len-CELL)/4;
    for (i=0; i<len; i++)
        bignum_digits(b)[i] = vbignum_digits(a)[i];
    return b;
}

LispObject negateb(LispObject a)
//
// Negate a bignum.  Note that negating the 1-word bignum
// value of 0x08000000 will produce a fixnum as a result (for 32 bits),
// which might confuse the caller... in a similar way negating
// the value -0x40000000 will need to promote from a one-word
// bignum to a 2-word bignum.  How messy just for negation!
// And on 64 bit systems the same effect applies but with larger values!
// In an analogous manner negating the positive number of the style
// 0x40000000 can lead to a negative result that uses one less digit.
// Well on a 64-bit machine it is a 2-word bignum that can end up
// negated to get a fixnum result.
//
{   LispObject b;
    size_t len = bignum_length(a), i;
    int32_t carry;
// There are two messy special cases here. The first is that there is a
// positive value (2^27 or 2^59) which has to be represented as a bignum,
// but when you negate it you get a fixnum.
// Then there will be negative values (the smallest being -2^31 or -2^62)
// that fit in a certain number of words of bignum, but their absolute
// value needs one more word...
// Note that on a 64-bit machine there ought never to be any one-word
// bignums because all the values representable with just one 31-bit digit
// can be handled as fixnums instead.
    if (SIXTY_FOUR_BIT &&
        len == CELL+8)   // two-word bignum - do specially
    {   if (bignum_digits(a)[0] == 0 &&
            bignum_digits(a)[1] == (int32_t)0x10000000)
            return MOST_NEGATIVE_FIXNUM;
        else if (bignum_digits(a)[0] == 0 &&
                 (int32_t)bignum_digits(a)[1] == -(int32_t)(1<<30))
            return make_three_word_bignum(0, 1<<30, 0);
        uint32_t d0 = bignum_digits(a)[0];
        int32_t d1 = (int32_t)~bignum_digits(a)[1];
        if (d0 == 0) d1++;
        else return make_two_word_bignum(d1, (-d0) & 0x7fffffff);
    }
    if (!SIXTY_FOUR_BIT &&
        len == CELL+4)   // one-word bignum - do specially
    {   int32_t d0 = -(int32_t)bignum_digits(a)[0];
        if (d0 == MOST_NEGATIVE_FIXVAL) return MOST_NEGATIVE_FIXNUM;
        else if (d0 == 0x40000000) return make_two_word_bignum(0, d0);
        else return make_one_word_bignum(d0);
    }
    {   b = get_basic_vector(TAG_NUMBERS, TYPE_BIGNUM, len);
        errexit();
    }
    len = (len-CELL-4)/4;
    carry = -1;
    for (i=0; i<len; i++)
    {
// The next couple of lines really caught me out wrt compiler optimisation
// before I put in all the casts. I used to have what was in effect
//    carry = (signed_x ^ 0x7fffffff) + (int32_t)((uint32_t)carry>>31);
//      ... ((uint32_t)carry >> 31);
// and a compiler seems to have observed that the masking leaves the left
// operand of the addition positive, and that the unsigned shift right
// leaves the right operand positive too. So based on an assumption that
// signed integer overflow will not happen it deduces that the sum will also
// be positive, and hence that on the next line (carry>>31) will be zero.
// For the assumption to fail there will have had to be integer overflow, and
// the C/C++ standards say that the consequence of that are undefined - a term
// that can include behaviour as per the optimised code here.
//
// To avoid that I am working on the basis that casts between int32_t and
// uint32_t will leave bit representations unchanged and that arithmetic uses
// twos complement for signed values. Then by casting to unsigned at times
// I can allow a carry to propagate into the top bit of a word without that
// counting as an overflow, and that should force the compiler to do the
// arithmetic in full.
//
// Having spotted this particular case I now worry about how many related
// ones there may be hiding in the code!
//
        carry = ADD32(clear_top_bit(~bignum_digits(a)[i]),
                      top_bit(carry));
        bignum_digits(b)[i] = clear_top_bit(carry);
    }
// Handle the top digit separately since it is signed.
    carry = ADD32(~bignum_digits(a)[i], top_bit(carry));
    if (!signed_overflow(carry))
    {
// If the most significant word ends up as -1 then I just might
// have 0x40000000 in the next word down and so I may need to shrink
// the number.  Since I handled 1-word bignums specially I have at
// least two words to deal with here.
        if (carry == -1 && (bignum_digits(b)[i-1] & 0x40000000) != 0)
        {   bignum_digits(b)[i-1] |= ~0x7fffffff;
            numhdr(b) = numhdr(b) - pack_hdrlength(1);
            if (SIXTY_FOUR_BIT)
            {   if ((i & 1) != 0) bignum_digits(b)[i] = 0;
                else *reinterpret_cast<Header *>(&bignum_digits(b)[i]) =
                    make_bighdr(2);
            }
            else
            {   if ((i & 1) == 0) bignum_digits(b)[i] = 0;
                else *reinterpret_cast<Header *>(&bignum_digits(b)[i]) =
                    make_bighdr(2);
            }
        }
        else bignum_digits(b)[i] = carry;   // no shrinking needed
        return b;
    }
// Here I have overflow: this can only happen when I negate a number
// that started off with 0xc0000000 in the most significant digit,
// and I have to pad a zero word onto the front.
    bignum_digits(b)[i] = clear_top_bit(carry);
    return lengthen_by_one_bit(b, carry);
}

//
// generic negation
//

LispObject negate(LispObject a)
{   switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            if (!SIXTY_FOUR_BIT && is_sfloat(a))
                return a ^ 0x80000000U;
            if (SIXTY_FOUR_BIT && is_sfloat(a))
                return a ^ UINT64_C(0x8000000000000000);
            else return make_lisp_integer64(-int_of_fixnum(a));
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    return negateb(a);
                case TYPE_RATNUM:
                {   LispObject n = numerator(a),
                               d = denominator(a);
                    n = negate(n);
                    return make_ratio(n, d);
                }
                case TYPE_COMPLEX_NUM:
                {   LispObject r = real_part(a),
                               i = imag_part(a);
                    r = negate(r);
                    i = negate(i);
                    return make_complex(r, i);
                }
                default:
                    return aerror1("bad arg for minus",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return make_boxfloat(-single_float_val(a),
                                         WANT_SINGLE_FLOAT);
                case DOUBLE_FLOAT_HEADER:
                    return make_boxfloat(-double_float_val(a),
                                         WANT_DOUBLE_FLOAT);
                case LONG_FLOAT_HEADER:
                {   FLOAT128 aa = -long_float_val(a);
                    return make_boxfloat128(aa);
                }
            }
        default:
            return aerror1("bad arg for minus",  a);
    }
}

#endif // ARITHLIB


} // end of namespace

// end of arith07.cpp
