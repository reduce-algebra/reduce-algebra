package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
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


import java.io.*;

class LispCounter extends LispStream
{

    boolean utf8;

    LispCounter(boolean utf8)
    {
        super("<character counter>");
        column = 0;
        this.utf8 = utf8;
    }

    void flush()
    {
    }

    void close()
    {
    }

    void print(String s)
    {
        if (utf8)
        {   for (char c : s.toCharArray())
            {   if (c <= 0x7f) column += 1;
                else if (c <= 0x7ff) column += 2;
// Java uses UTF-16 so here I deal with the surrogates. If I count
// 2 bytes for either high or low surrogates then proper pairs will
// give me a total of 4 which is what I need.
                else if ((c & 0xf800) == 0xd800) column += 2;
                else column += 3;
            }
        }
        else
// Wben counting "characters" rather than "bytes" I should ignore UTF-16 low
// surrogates so that charaters with a codepoint over U+ffff still end up
// counted as 1 rather than 2 units.
        {   for (char c : s.toCharArray())
            {   if ((c & 0xfc00) != 0xdc00) column++;
            }
        }
    }

    void println(String s)
    {
        print(s);
        column++;
    }

}

// end of LispCounter.java


