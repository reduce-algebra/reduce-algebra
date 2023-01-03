// mathtables.cpp                          Copyright (C) 2016-2023 Codemist

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


// This is an utterly specialised progrem for extracting bits of maths
// tables from cslSTIXMath.tables

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "../uninames.cpp"


#define NMOVED 10000
#define MAXNEWNAME 120

static int nmoved = 0;
char movedname[NMOVED][MAXNEWNAME];
int movedwidth[NMOVED];

// If the any strings of the form "unixxxx" for hex digits xxxx are present
// and if I know a name for U+xxxx then I will re-write the input in
// linebuffer. Note that this can lead to long names and in cmuntt the line
// giving ligatures with SPACE ends up almost 2000 characters long. Ugh!

static void adjustuninames(char *linebuffer)
{   char newlinebuffer[2000], *p, *q;
    const char *r;
    int code;
    p = linebuffer;
    q = newlinebuffer;
    while (*p != 0)
    {   if (p[0] == 'u' &&
            p[1] == 'n' &&
            p[2] == 'i' &&
            std::isxdigit(p[3]) &&
            std::isxdigit(p[4]) &&
            std::isxdigit(p[5]) &&
            std::isxdigit(p[6]) &&
            !std::isxdigit(p[7]) &&
            std::sscanf(p, "uni%x", &code) == 1 &&
            (r = uniname(code)) != nullptr)
        {   std::strcpy(q, r);
            p += 7;
            q += std::strlen(r);
        }
        else *q++ = *p++;
    }
    *q = 0;
    std::strcpy(linebuffer, newlinebuffer);
}

int main(int argc, char *argv[])
{   std::exit(0);
    std::FILE *src = std::fopen("mathtables.tmp", "r");
    std::FILE *dest = std::fopen("metrics/cslSTIXMath.tables", "w");
    // No check for errors here!
    char linebuffer[2000];            // Fixed buffer with no overflow checks!

    for (;;)
    {   int c, i = 0;
        while ((c = std::getc(src)) != EOF && c != '\n')
            linebuffer[i++] = c;
        linebuffer[i] = 0;
        if (i == 0 && c == EOF) break;
        adjustuninames(linebuffer);
        if (std::strncmp(linebuffer, "C -1 ; ", 7) == 0)
        {   int width, code;
            if (std::sscanf(linebuffer, "C -1 ; WX %d ; N u%x ;",
                            &width, &code) == 2)
            {   char *p = linebuffer + 10;
                while (*p != ';') p++;
                p++;
                while (*p == ' ') p++;
                if (*p != 'N')
                {   std::printf("Formatting failure\n");
                    std::exit(1);
                }
                p++;
                while (*p == ' ') p++;
                char *q = p;
                while (*q != ' ') q++;
                *q = 0;
                while (*q != ';') q++;
                *q = 0;
                const char *r = uniname(code);
// If there is an official unicode name for the codepoint I will insert
// it. If the codepoint was a copy of one of the STIX glyphs not previously
// within the Unicode range I will transfer the name it originally had to the
// new position at 0x108xxx.
                if (r == nullptr)
                {   if  (code >= 0x108000 &&
                         code-0x108000 < nmoved &&
                         width == movedwidth[code-0x108000])
                        r = movedname[code-0x108000];
                    else r = p;
                }
                std::fprintf(dest, "C %d ; WX %d ; N %s ;%s\n",
                             code, width, r, q+1);
            }
        }
        else std::fprintf(dest, "%s\n", linebuffer);
    }
    std::fclose(src);
    std::fclose(dest);
    return 0;
}

// end of mathtables.cpp
