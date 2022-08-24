// tagifs.cpp                           Copyright (C) A C Norman, 2008-2022
//

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

// Re-words C/C++ code to add comments to #else and #endif lines to show
// the #if/#ifdef that they refer to. The idea here is that
//   #ifdef XXX
//   ...
//   #else
//   ...
//   #endif
// will be turned into
//   #ifdef XXX
//   ...                   /*XXX*/
//   #else
//   ...                   /*!XXX*/
//   #endif
// and where nested #ifdefs are used there will be multiple comments. The
// comments will start at the next multiple of 9 from 72 on such that
// they are beyond the end of the input line.

// I will assume that any preprocessor directives start at the first
// character of the line and that there is not extraneous whitespace. So a
// line that reads "   #   if   XXX" will not be treated kindly.


// $Id$

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXDEPTH 30
#define MAXLINE 2048

int depth;
char *pending[MAXDEPTH];
int elseseen[MAXDEPTH];

char curline[MAXLINE];

static void stripcomments(char *p)
{   char *q = p;
    while (*q != 0)
    {   if (*q == '\'')
        {   q++;
            for (;;)
            {   if (*q == '\\') q += 2;
                else if (*q++ == '\'') break;
            }
            continue;
        }
        else if (*q == '"')
        {   q++;
            for (;;)
            {   if (*q == '\\') q += 2;
                else if (*q++ == '"') break;
            }
            continue;
        }
        else if (q[0] == '/' && q[1] == '/')
        {   q[0] = 0;
            while (q != p && q[-1] == ' ')
            {   q--;
                *q = 0;
            }
            return;
        }
        else if (q[0] == '/' && q[1] == '*')
        {   char *r = q+2;
            while (*r != 0)
            {   if (r[0] == '*' && r[1] == '/')
                {   char *s = q;
                    r = r + 2;
                    while (*r != 0) *s++ = *r++;
                    r = q;
                    break;
                }
            }
            if (*q == 0 || *r != 0)
            {   q[0] = 0;
                while (q != p && q[-1] == ' ')
                {   q--;
                    *q = 0;
                }
                return;
            }
        }
        q++;
    }
    while (q != p && q[-1] == ' ')
    {   q--;
        *q = 0;
    }
}

int main(int argc, char *argv[])
{   std::FILE *in, *out;
    int i, c;
    char outname[256];
    if (argc != 2)
    {   std::fprintf(stderr, "Usage: tagifs xxx.cpp\n");
        return 1;
    }
    for (i=0; i<MAXDEPTH; i++)
    {   pending[i] = new char[MAXLINE];
        elseseen[i] = 0;
    }
    in = std::fopen(argv[1], "r");
    if (in == nullptr)
    {   std::fprintf(stderr, "Failed to access \"%s\"\n", argv[1]);
        return 1;
    }
    std::sprintf(outname, "%s.new", argv[1]);
    out = std::fopen(outname, "w");
    if (out == nullptr)
    {   std::fprintf(stderr, "Failed to access \"%s\"\n", outname);
        std::fclose(in);
        return 1;
    }
    depth = 0;
    for (;;)
    {   i = 0;
        while ((c = std::getc(in)) != EOF && c != '\n' && c != '\r')
        {   curline[i++] = c;
        }
        curline[i] = 0;
        if (i == 0 && c == EOF) break;
        if (std::strncmp(curline, "#if", 3) == 0) // #if OR #ifdef
        {   int j;
            i = 3;
// After "#ifdef XXX" I will have "XXX" as my tag
// After "#ifndef XXX" I will have "XXX as my tag
// After "#if XXX" I will also have XXX as my tag
//
            while (curline[i] != 0 && curline[i] != ' ') i++;
            while (curline[i] == ' ') i++;
            std::strcpy(pending[depth], &curline[i]);
// I now rather want to remove comments from the pending material.
// In particular there is a case that could have pathological consequences:
//   #if defined XXX // Comment with */ in it.
            stripcomments(pending[depth]);
            elseseen[depth] = (curline[3] == 'n') ? 1 : 0;
            depth++;
        }
        else if (std::strncmp(curline, "#else", 5) == 0)
        {   i = 5;
            while (curline[i] != 0 && curline[i] != ' ') i++;
            if (depth == 0) std::sprintf(&curline[i], " /* ERROR */");
            else
            {   std::sprintf(&curline[i], " /* %s */", pending[depth-1]);
                elseseen[depth-1] =
                    elseseen[depth-1] == 0 ? 3 :
                    elseseen[depth-1] == 1 ? 2 : 4;
            }
        }
        else if (std::strncmp(curline, "#endif", 6) == 0)
        {   i = 6;
            while (curline[i] != 0 && curline[i] != ' ') i++;
            if (depth == 0) std::sprintf(&curline[i], " /* ERROR */");
            else std::sprintf(&curline[i], " /* %s */", pending[depth-1]);
            depth--;
        }
        i = std::fprintf(out, "%s", curline);
// I had better not tag a comment on to the end of a line that itself ends
// in a backslash since line continuation happens before comment-removal
// when C++ source code is being processed. There should be very few places
// outside of preprocessor directives where line-continuation via a final
// "\" is needed or used. I will also not mess with lines that start
// with a "#". The odd case left over is that the final line of a multi-line
// preprocessor directive is liable to be tagged, so
//   #define SOMETHING part1 \
//                     part2 \
//                     part3
// can end up with a /*XXX*/ comment after "part3". I do not believe that
// this can ever hurt.
        if (depth != 0 && curline[0] != '#' &&
            curline[0] != 0 && curline[std::strlen(curline)-1] != '\\')
        {   int j;
            while (i < 72 || (i%8) != 0)
            {   std::putc(' ', out);
                i++;
            }
            std::fprintf(out, "/*");
            for (j=0; j<depth; j++)
            {   if (j != 0) std::putc(',', out);
// The "?" will mark places where an improper extra #else has bene present.
                if (elseseen[j] == 4) std::putc('?', out);
                else if ((elseseen[j] & 1) != 0) std::putc('!', out);
                std::fprintf(out, "%s", pending[j]);
            }
            std::fprintf(out, "*/");
        }
        std::fprintf(out, "\n");
        if (c == EOF) break;
    }
    std::fclose(in);
    std::fclose(out);
    while (depth != 0)
    {   std::fprintf(stderr, "ERROR: \"%s\" not closed\n",
                     pending[depth]);
        depth--;
    }
    return 0;

}

// end of tagifs1.cpp
