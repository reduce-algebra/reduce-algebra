//  arith-print.cpp                             Copyright (C) 2019 Codemist    


/**************************************************************************
 * Copyright (C) 20179, Codemist.                         A C Norman       *
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
#include "dispatch.h"


static thread_local std::vector<char> print_buffer;

void print_newbignum(LispObject u, bool blankp, int nobreak)
{   size_t approx_length =
        arithlib_lowlevel::bignum_to_string_length(
            (uint64_t *)(u - TAG_NUMBERS + 8),
            (length_of_header(numhdr(u)) - 8)/8);
    if (print_buffer.size() < approx_length)
        print_buffer.resize(approx_length);
    char *b = print_buffer.data();
// I now have a buffer long enough to put my digits in.
    size_t len =
        arithlib_lowlevel::bignum_to_string(
            b, approx_length,
            (uint64_t *)(u - TAG_NUMBERS + 8),
            (length_of_header(numhdr(u)) - 8)/8);
// Now len is the actual length of the output and the buffer b contains
// that many characters. I will need to cope with line breaks and the
// like...
    unsigned int line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    unsigned int column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, active_stream);
    if (blankp)
    {   if (nobreak==0 && column+len >= line_length)
        {   if (column != 0) putc_stream('\n', active_stream);
        }
        else putc_stream(' ', active_stream);
    }
    else if (nobreak==0 && column != 0 && column+len > line_length)
        putc_stream('\n', active_stream);
    for (size_t i=0; i<len; i++) putc_stream(b[i], active_stream);
// Printing was potentially a fairly expensive step. So I will check to
// see if an interrupt was posted during it.
    if ((uintptr_t)stack >=
        ((uintptr_t)stacklimit | event_flag.load()))
        respond_to_stack_event();
}

void print_newbighexoctbin(LispObject u, int radix, int width,
                        bool blankp, int nobreak)
//
// This prints a bignum in base 16, 8 or 2.
//
{   unsigned int line_length =
        other_write_action(WRITE_GET_INFO+WRITE_GET_LINE_LENGTH,
                           active_stream);
    unsigned int column =
        other_write_action(WRITE_GET_INFO+WRITE_GET_COLUMN, active_stream);

/*
        if (blankp)
        {   if (nobreak==0 && column+len >= line_length)
            {   if (column != 0) putc_stream('\n', active_stream);
            }
            else putc_stream(' ', active_stream);
        }
        else if (nobreak==0 && column != 0 && column+len > line_length)
            putc_stream('\n', active_stream);
        while (--i >= 0) putc_stream(my_buff[i], active_stream);

        if ((uintptr_t)stack >=
            ((uintptr_t)stacklimit | event_flag.load()))
            respond_to_stack_event();
    }

*/
}

// end of arith-print.cpp
