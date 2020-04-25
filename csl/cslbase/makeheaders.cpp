// makeheaders.cpp                         Copyright (C) 2005-2017 Codemist


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


//
// Transcribes some header files, stripping comments etc
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdio>
#include <cstring>
#include <cstdlib>

//
// The conversion here needs to do some minimal lexical analysis of the code
// it is transcribing. The special cases it needs to allow for are
// (1)    /* ... */              skipped
// (2)    // ... <end-of-line>   skipped
// (3)    "..."                  a string, so "//" and "/*" are not special
// (4)    '...'                  character literal, ditto
// (5)    \x within a string or char literal
//                               treat as generic character, not as any of
//                               the above specials
// (6) when OUTPUTTING characters, and ', " or \ must have an extra \ char
//     put before it. Newlines should be rendered as "\n"
//
// To achieve all this a finite state machine will be used, with the
// following states:

#define BASE        0     // base state
#define SLASH       1     // after a "/"
#define SLASHSLASH  2     // after "//"
#define SLASHSTAR   3     // after "/*"
#define STAR        4     // after "/* ... *"
#define STRING      5     // after '"'
#define STRINGESC   6     // after '" ... \'
#define CHAR        7     // after "'"
#define CHARESC     8     // after "' ... \"

//
// In some cases I may end up passing a file-name of the form
//     /cygdrive/d/path.../leaf
// here. For things to behave I need to map that onto
//     d:/...path/leaf
//

static std::FILE *myfopen(const char *name, const char *mode)
{   char newname[256];
    if (std::strncmp(name, "/cygdrive/", 10) != 0)
        return std::fopen(name, mode);
    newname[0] = name[10];
    newname[1] = ':';
    std::strcpy(&newname[2], &name[11]);
    return std::fopen(newname, mode);
}

static int get_without_cr(std::FILE *f)
{
// This mess is here in case an input file has carriage returns in.
// An isolated CR is turned into '\n', while the sequence turns into
// a single '\n'. Other more complicated sequences of CR and LF may end up
// delivering multiple newlines to downstream.
    int c = std::getc(f);
    if (c == '\r')
    {   int c1 = std::getc(f);
        if (c1 != '\n') std::ungetc(c1, f);
        c = '\n';
    }
    return c;
}

void transcribe(const char *fname)
{   std::FILE *f = myfopen(fname, "r");
    int ch = '\n', state = BASE, linechars = 0;
    if (f == nullptr)
    {   std::fprintf(stderr, "unable to read \"%s\"\n", fname);
        std::exit(1);
    }
    for (;;)
    {
// I will consolidate multiple spaces into just one if I am not in
// a string or a character literal.
        if (ch == ' ' &&
            state != STRING &&
            state != STRINGESC &&
            state != CHAR &&
            state != CHARESC)
        {   while (ch == ' ') ch = get_without_cr(f);
        }
        else if (ch != EOF) ch = get_without_cr(f);  // next character
        if (ch == EOF) break;
        switch (state)
    {       default:
            case BASE:
                if (ch == '/')
                {   state = SLASH;
                    continue;
                }
                else if (ch == '\"')
                {   state = STRING;
                    break;
                }
                else if (ch == '\'')
                {   state = CHAR;
                    break;
                }
                else if (ch == '\n')
                {   if (linechars != 0) std::printf("\",\n    \"");
                    linechars = 0;
                    continue;
                }
                else break;
            case SLASH:
                if (ch == '/')
                {   state = SLASHSLASH;
                    continue;
                }
                else if (ch == '*')
                {   state = SLASHSTAR;
                    continue;
                }
                else if (ch == '\"')
                {   state = STRING;
                    std::printf("/");
                    linechars++;
                    break;
                }
                else if (ch == '\'')
                {   state = CHAR;
                    std::printf("/");
                    linechars++;
                    break;
                }
                else if (ch == '\n')
                {   std::printf("/\",\n    \"");
                    continue;
                }
                else
                {   std::printf("/");
                    state = BASE;
                    break;
                }
            case SLASHSLASH:
                if (ch != '\n' && ch != EOF) continue;
                state = BASE;
                if (ch == '\n')
                {   if (linechars != 0) std::printf("\",\n    \"");
                    linechars = 0;
                    continue;
                }
                else continue;
            case SLASHSTAR:
                if (ch != '*') continue;
                state = STAR;
                continue;
            case STAR:
                if (ch == '/') state = BASE;
                else state = SLASHSTAR;
                continue;
            case STRING:
                if (ch == '\"') state = BASE;
                else if (ch == '\\') state = STRINGESC;
                break;
            case STRINGESC:
                state = STRING;
                break;
            case CHAR:
                if (ch == '\'') state = BASE;
                else if (ch == '\\') state = CHARESC;
                break;
            case CHARESC:
                state = CHAR;
                break;
        }
        linechars++;
        if (ch == '\n')
        {   std::putchar('\\');
            std::putchar('n');
            continue;
        }
        if (ch == '\"' || ch == '\'' || ch == '\\') std::putchar('\\');
        std::putchar(ch);
        continue;
    }
    std::fclose(f);
}

const char *adapt(const char *base, const char *leaf)
{   static char fname[1024];
    const char *slash = std::strrchr(base, '/');
    std::strcpy(fname, base);
    std::strcpy(fname+(slash-base+1), leaf);
    return fname;
}

int main(int argc, const char *argv[])
{   int i;
    std::printf("const char *config_header[] =\n{\n    \"");
    for (i=1; i<argc; i++)
    {   transcribe(argv[i]);
        if (i == 1)
        {   std::printf("\",\n    nullptr\n};\n\nconst char *csl_headers[] =\n{\n    \"");
        }
    }
    std::printf("#ifdef CONSERVATIVE\",\n    \"");
    transcribe(adapt(argv[2], "newallocate.h"));
    std::printf("#else // CONSERVATIVE\",\n    \"");
    transcribe(adapt(argv[2], "allocate.h"));
    std::printf("#endif // CONSERVATIVE");
    std::printf("\",\n    nullptr\n};\n\n// end of machineid.cpp\n\n");
    return 0;
}

// end of makeheaders.cpp
