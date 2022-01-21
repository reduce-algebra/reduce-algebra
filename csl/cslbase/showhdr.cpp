// showhdr.cpp                                  Copyright (C) Codemist 2022

//
// Decode a LispObject, in particular in the case it is actually
// a Header.

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

// $Id$


#include "headers.h"

const char *decodeObject(LispObject a)
{   static char r[40];
    switch (a & TAG_BITS)
    {
    case TAG_CONS:
        sprintf(r, "cons at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_VECTOR:
        if (is_string_header(vechdr(a)))
        {   size_t len = length_of_byteheader(vechdr(a)) - CELL;
            const char *s = &basic_celt(a, 0);
            if (len < 10) sprintf(r, "str %s \"%s\"", Addr(a&~TAG_BITS), s);
            else sprintf(r, "str %s \"%.10s...\"", Addr(a&~TAG_BITS), s);
        }
        else sprintf(r, "vector at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_HDR_IMMED:
        break;
    case TAG_FORWARD:
        sprintf(r, "forward to %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_SYMBOL:
        sprintf(r, "symbol at %s", Addr(a));
        return r;
    case TAG_NUMBERS:
        sprintf(r, "bignum etc at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_BOXFLOAT:
        sprintf(r, "boxfloat at %s", Addr(a&~TAG_BITS));
        return r;
    case TAG_FIXNUM:
        if ((a & TAG_XBIT) != 0)
        {   double f;
            a &= ~XTAG_SFLOAT;
            std::memcpy(&f, &a, sizeof(double));
            sprintf(r, "short float %g", f);
        }
        else sprintf(r, "fixnum %" PRIdPTR, a>>4);
        return r;
    }
    switch ((a>>3) & 0x3)
    {
    case 0x0: // symbol head, char, spid
        switch ((a>>5) & 0x3)
        {
        case 0x0: // symbol head
            sprintf(r, "symbol head %" PRIxPTR, a);
            return r;
        case 0x1: // char literal
            sprintf(r, "character U+%" PRIxPTR, (a>>5));
            return r;
        case 0x2: // unused
            sprintf(r, "Unknown %" PRIxPTR, a>>5);
            return r;
        case 0x3: // "spid"
            sprintf(r, "SPID %" PRIxPTR, (a>>5));
            return r;
        }
    case 0x1: // vector of lisp pointers (including stream objects)
        sprintf(r, "Lisp vector length %" PRIdPTR, length_of_header(a));
        return r;
    case 0x2: // bit-vector
        sprintf(r, "Bit vector length %" PRIdPTR, length_of_bitheader(a));
        return r;
    case 0x3: // vector of binary stuff (including strings)
        sprintf(r, "Binary vector length %" PRIdPTR, length_of_header(a));
        return r;
        break;
    }
    switch (a & header_mask)
    {
    case TYPE_STRING_1:
        sprintf(r, "STRING_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_2:
        sprintf(r, "STRING_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_3:
        sprintf(r, "STRING_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_STRING_4:
        sprintf(r, "STRING_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_1:
        sprintf(r, "VEC8_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_2:
        sprintf(r, "VEC8_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_3:
        sprintf(r, "VEC8_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC8_4:
        sprintf(r, "VEC8_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_1:
        sprintf(r, "BPS_1 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_2:
        sprintf(r, "BPS_2 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_3:
        sprintf(r, "BPS_3 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_BPS_4:
        sprintf(r, "BPS_4 length %" PRIdPTR, length_of_byteheader(a));
        return r;
    case TYPE_VEC16_1:
        sprintf(r, "VEC16_1 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC16_2:
        sprintf(r, "VEC16_2 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_FOREIGN:
        sprintf(r, "FOREIGN length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_SP:
        sprintf(r, "SP length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_ENCAPSULATE:
        sprintf(r, "ENCAPSULATE length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_PADDER:
        sprintf(r, "PADDER length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_SIMPLE_VEC:
        sprintf(r, "SIMPLE_VEC length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_INDEXVEC:
        sprintf(r, "INDEXVEC length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_HASH:
        sprintf(r, "HASH length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_HASHX:
        sprintf(r, "HASHX length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_ARRAY:
        sprintf(r, "ARRAY length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_STRUCTURE:
        sprintf(r, "STRUCTURE length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_OBJECT:
        sprintf(r, "OBJECT length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC32:
        sprintf(r, "VEC32 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC64:
        sprintf(r, "VEC64 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VEC128:
        sprintf(r, "VEC128 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT32:
        sprintf(r, "VECFLOAT32 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT64:
        sprintf(r, "VECFLOAT64 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_VECFLOAT128:
        sprintf(r, "VECFLOAT128 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED1:
        sprintf(r, "MIXED1 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED2:
        sprintf(r, "MIXED2 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_MIXED3:
        sprintf(r, "MIXED3 length %" PRIdPTR, length_of_header(a));
        return r;
    case TYPE_STREAM:
        sprintf(r, "STREAM length %" PRIdPTR, length_of_header(a));
        return r;
    default:
        sprintf(r, "Unknown %" PRIxPTR, a);
        return r;
    }
}

// end of showhdr.cpp

