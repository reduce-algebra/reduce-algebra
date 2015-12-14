// makeheaders.cpp                     Copyright (C) 2005-2015 Codemist Ltd


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

static FILE *myfopen(const char *name, const char *mode)
{   char newname[256];
    if (strncmp(name, "/cygdrive/", 10) != 0)
        return fopen(name, mode);
    newname[0] = name[10];
    newname[1] = ':';
    strcpy(&newname[2], &name[11]);
    return fopen(newname, mode);
}

int main(int argc, const char *argv[])
{   int i;
    printf("const char *config_header[] =\n{\n    \"");
    for (i=1; i<argc; i++)
    {   FILE *f = myfopen(argv[i], "r");
        int ch = '\n', state = BASE, linechars = 0;
        if (f == NULL)
        {   fprintf(stderr, "unable to read \"%s\"\n", argv[i]);
            exit(1);
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
            {   while (ch == ' ') ch = getc(f);
            }
            else if (ch != EOF) ch = getc(f);  // next character
            if (ch == EOF) break;
            switch (state)
            {
        default:
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
                {   if (linechars != 0) printf("\",\n    \"");
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
                    printf("/");
                    linechars++;
                    break;
                }
                else if (ch == '\'')
                {   state = CHAR;
                    printf("/");
                    linechars++;
                    break;
                }
                else if (ch == '\n')
                {   printf("/\",\n    \"");
                    continue;
                }
                else
                {   printf("/");
                    state = BASE;
                    break;
                }
        case SLASHSLASH:
                if (ch != '\n' && ch != EOF) continue;
                state = BASE;
                if (ch == '\n')
                {   if (linechars != 0) printf("\",\n    \"");
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
            {   putchar('\\');
                putchar('n');
                continue;
            }
            if (ch == '\"' || ch == '\'' || ch == '\\') putchar('\\');
            putchar(ch);
            continue;
        }
        fclose(f);
        if (i == 1)
        {   printf("\",\n    NULL\n};\n\nconst char *csl_headers[] =\n{\n    \"");
        }
    }
    printf("\",\n    NULL\n};\n\n// end of machineid.cpp\n\n");
    return 0;
}

// end of makeheaders.cpp
