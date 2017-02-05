// utfcheck.cpp                            Copyright (C) 2016-2017 Codemist    

//
// This is a pretty silly program! It looks at Unicode characters and tests
// when case-folding can change the number of utf-8 bytes needed to encode
// them. At least in the default locales I have set up on my own Mac and
// Linux systems there is never a change of encoded length, but on Windows
// there sometimes is. For instance towlower when applied to a capital letter
// "I" with a dot over it gives back a simple lower case "i". A consequence
// of this is of course that folding case backwards and forwards can be
// lossy. The code here lists the cases I came across on my Windows
// system when running under cygwin. A windows version compiled using
// i686-w64-mingw32-gcc seems to behave like Linux with no discrepancies
// shown.
//
// There is a real prospect that the concept of "case" and folding will be
// locale sensitive and so running this in different loacles may be
// instructive.
//


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


#include <stdio.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>

int encode(char *s, int c)
{   char *s1 = s;
    if (c <= 0x7f) *s++ = c;
    else if (c <= 0x7ff)
    {   *s++ = 0xc0 + ((c>>6) & 0x1f);
        *s++ = 0x80 + (c & 0x3f);
    }
    else if (c <= 0xffff)
    {   *s++ = 0xe0 + ((c>>12) & 0x0f);
        *s++ = 0x80 + ((c>>6) & 0x3f);
        *s++ = 0x80 + (c & 0x3f);
    }
    else
    {   *s++ = 0xf0 + ((c>>16) & 0x07);
        *s++ = 0x80 + ((c>>12) & 0x3f);
        *s++ = 0x80 + ((c>>6) & 0x3f);
        *s++ = 0x80 + (c & 0x3f);
    }
    *s = 0;
    return (s - s1);
}

int main(int argc, char *argv[])
{   int c1, c2, c3, n1, n2, n3, status, flag;
    char s1[8], s2[8], s3[8];
    printf("  base     upper    lower\n");
    for (c1 = 0; c1<=0xffff; c1++)
    {
// Skip the surrogate range
        if (0xd800 <= c1 && c1 <= 0xdfff) continue;
        c2 = towupper(c1);
        c3 = towlower(c1);
        n1 = encode(s1, c1);
        n2 = encode(s2, c2);
        n3 = encode(s3, c3);
        flag = 1;
        switch (c1)
        {
// Here are cases I know are sometimes at issue...
// about them!
            case 0x0130:   // LATIN CAPITAL I WITH DOT
            case 0x0131:   // LATIN SMALL LETTER DOTLESS I
            case 0x017f:   // LATIN SMALL LETTER LONG S
            case 0x023a:   // LATIN CAPITAL A WITH STROKE
            case 0x023e:
            case 0x023f:
            case 0x0240:
            case 0x0250:
            case 0x0251:
            case 0x0252:
            case 0x026b:
            case 0x0271:
            case 0x027d:
            case 0x1e9e:
            case 0x1fbe:
            case 0x2126:
            case 0x212a:
            case 0x212b:
            case 0x2c62:
            case 0x2c64:
            case 0x2c65:
            case 0x2c66:
            case 0x2c6d:
            case 0x2c6e:
            case 0x2c6f:
            case 0x2c70:  // LATIN CAPITRAL LETTER TURNED ALPHA
            case 0x2c7e:  // LATIN CAPITAL S WITH SWASH TAIL
            case 0x2c7f:  // LATIN CAPITAL Z WITH SWASH TAIL
                flag = 0;
            default:
                break;
        }
        status = (n1 == n2 && n1 == n3); // are utf-8 lengths unchanged?
        if (status && flag) continue;
        printf("%#.4x(%d) %#.4x(%d) %#.4x(%d) %s  %s %s %s\n",
               c1, n1, c2, n2, c3, n3, (status ? "OK " : "bad"), s1, s2, s3);
    }
    return 0;
}

// end of utf8check.cpp
