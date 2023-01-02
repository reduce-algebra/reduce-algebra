// showhdr.cpp                             Copyright (C) Codemist 2022-2023

//
// Decode a LispObject, in particular in the case it is actually
// a Header.

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

// $Id$


#include "headers.h"

const char *decodeObject(LispObject a)
{   static char r[40];
    switch (a & TAG_BITS)
    {
    case TAG_CONS:
        std::snprintf(r, sizeof(r), "cons at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_VECTOR:
        if (is_string_header(vechdr(a)))
        {   size_t len = length_of_byteheader(vechdr(a)) - CELL;
            const char *s = &basic_celt(a, 0);
            if (len < 10) std::snprintf(r, sizeof(r), "str %s \"%s\"", Addr(a&~TAG_BITS), s);
            else std::snprintf(r, sizeof(r), "str %s \"%.10s...\"", Addr(a&~TAG_BITS), s);
        }
        else if (is_forward(vechdr(a)))
        {   decodeObject(TAG_VECTOR+(vechdr(a)&~TAG_BITS));
            std::strcat(r, " forwarded");
            return r;
        }
        else std::snprintf(r, sizeof(r), "vector at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_HDR_IMMED:
        break;
    case TAG_FORWARD:
        std::snprintf(r, sizeof(r), "forward to %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_SYMBOL:
        std::snprintf(r, sizeof(r), "symbol at %s", Addr(a));
        return r;
    case TAG_NUMBERS:
        std::snprintf(r, sizeof(r), "bignum etc at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_BOXFLOAT:
        std::snprintf(r, sizeof(r), "boxfloat at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_FIXNUM:
        if ((a & TAG_XBIT) != 0)
        {   double f;
            a &= ~XTAG_SFLOAT;
            std::memcpy(&f, &a, sizeof(double));
            std::snprintf(r, sizeof(r), "short float %g", f);
        }
        else std::snprintf(r, sizeof(r), "fixnum %" PRIdPTR, a>>4);
        return r;
    }
    switch ((a>>3) & 0x3)
    {
    case 0x0: // symbol head, char, spid
        switch ((a>>5) & 0x3)
        {
        case 0x0: // symbol head
            std::snprintf(r, sizeof(r), "symbol head %" PRIxPTR, a);
            return r;
        case 0x1: // char literal
            std::snprintf(r, sizeof(r), "character U+%" PRIxPTR, (a>>5));
            return r;
        case 0x2: // unused
            std::snprintf(r, sizeof(r), "Unknown %" PRIxPTR, a>>5);
            return r;
        case 0x3: // "spid"
            std::snprintf(r, sizeof(r), "SPID %" PRIxPTR, (a>>5));
            return r;
        }
    case 0x1: // vector of lisp pointers (including stream objects)
        std::snprintf(r, sizeof(r), "Lisp vector length %" PRIdPTR, length_of_header(a));
        return r;
    case 0x2: // bit-vector
        std::snprintf(r, sizeof(r), "Bit vector length %" PRIdPTR, length_of_bitheader(a));
        return r;
    case 0x3: // vector of binary stuff (including strings)
//      std::snprintf(r, sizeof(r), "Binary vector length %" PRIdPTR, length_of_header(a));
//      return r;
        break;
    }
    switch (a)
    {
    case SINGLE_FLOAT_HEADER:
        std::snprintf(r, sizeof(r), "SINGLE_FLOAT length %" PRIdPTR, length_of_header(a));
        return r;
    case DOUBLE_FLOAT_HEADER:
        std::snprintf(r, sizeof(r), "DOUBLE_FLOAT length %" PRIdPTR, length_of_header(a));
        return r;
    case LONG_FLOAT_HEADER:
        std::snprintf(r, sizeof(r), "LONG_FLOAT length %" PRIdPTR, length_of_header(a));
        return r;
    }
    switch (a & header_mask)
    {
    case TYPE_STRING_1:
        std::snprintf(r, sizeof(r), "STRING_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_2:
        std::snprintf(r, sizeof(r), "STRING_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_3:
        std::snprintf(r, sizeof(r), "STRING_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_4:
        std::snprintf(r, sizeof(r), "STRING_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_1:
        std::snprintf(r, sizeof(r), "VEC8_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_2:
        std::snprintf(r, sizeof(r), "VEC8_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_3:
        std::snprintf(r, sizeof(r), "VEC8_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_4:
        std::snprintf(r, sizeof(r), "VEC8_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_1:
        std::snprintf(r, sizeof(r), "BPS_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_2:
        std::snprintf(r, sizeof(r), "BPS_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_3:
        std::snprintf(r, sizeof(r), "BPS_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_4:
        std::snprintf(r, sizeof(r), "BPS_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC16_1:
        std::snprintf(r, sizeof(r), "VEC16_1 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC16_2:
        std::snprintf(r, sizeof(r), "VEC16_2 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_FOREIGN:
        std::snprintf(r, sizeof(r), "FOREIGN length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_SP:
        std::snprintf(r, sizeof(r), "SP length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_ENCAPSULATE:
        std::snprintf(r, sizeof(r), "ENCAPSULATE length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_PADDER:
        std::snprintf(r, sizeof(r), "PADDER length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_SIMPLE_VEC:
        std::snprintf(r, sizeof(r), "SIMPLE_VEC length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_INDEXVEC:
        std::snprintf(r, sizeof(r), "INDEXVEC length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_HASH:
        std::snprintf(r, sizeof(r), "HASH length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_HASHX:
        std::snprintf(r, sizeof(r), "HASHX length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_ARRAY:
        std::snprintf(r, sizeof(r), "ARRAY length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_STRUCTURE:
        std::snprintf(r, sizeof(r), "STRUCTURE length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_OBJECT:
        std::snprintf(r, sizeof(r), "OBJECT length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC32:
        std::snprintf(r, sizeof(r), "VEC32 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC64:
        std::snprintf(r, sizeof(r), "VEC64 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC128:
        std::snprintf(r, sizeof(r), "VEC128 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT32:
        std::snprintf(r, sizeof(r), "VECFLOAT32 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT64:
        std::snprintf(r, sizeof(r), "VECFLOAT64 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT128:
        std::snprintf(r, sizeof(r), "VECFLOAT128 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED1:
        std::snprintf(r, sizeof(r), "MIXED1 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED2:
        std::snprintf(r, sizeof(r), "MIXED2 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED3:
        std::snprintf(r, sizeof(r), "MIXED3 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_STREAM:
        std::snprintf(r, sizeof(r), "STREAM length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_BIGNUM:
        std::snprintf(r, sizeof(r), "BIGNUM length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_NEW_BIGNUM:
        std::snprintf(r, sizeof(r), "NEW_BIGNUM length %" PRIdPTR, length_of_header(a));
        return r;
    default:
        std::snprintf(r, sizeof(r), "Unknown %" PRIxPTR, a);
        return r;
    }
}

// end of showhdr.cpp

