// tagifs.cpp                           Copyright (C) A C Norman, 2015-2022

//
// Re-works C/C++ code to add comments to #else and #endif lines to show
// the #if/#ifdef that they refer to.
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

// $Id$

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXDEPTH 30
#define MAXLINE 256

int depth;
char *pending[MAXDEPTH];

char curline[MAXLINE];

int main(int argc, char *argv[])
{   std::FILE *in, *out;
    int i, c;
    char outname[256];
    if (argc != 2)
    {   std::fprintf(stderr, "Usage: tagifs xxx.cpp\n");
        return 1;
    }
    for (i=0; i<MAXDEPTH; i++)
        pending[i] = new char[MAXLINE];
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
        {   i = 3;
            while (curline[i] != 0 && curline[i] != ' ') i++;
            while (curline[i] == ' ') i++;
            std::strcpy(pending[depth], &curline[i]);
            depth++;
        }
        else if (std::strncmp(curline, "#else", 5) == 0)
        {   i = 5;
            while (curline[i] != 0 && curline[i] != ' ') i++;
            if (depth == 0) std::sprintf(&curline[i], " // ERROR");
            else std::sprintf(&curline[i], " // %s", pending[depth-1]);
        }
        else if (std::strncmp(curline, "#endif", 6) == 0)
        {   i = 6;
            while (curline[i] != 0 && curline[i] != ' ') i++;
            if (depth == 0) std::sprintf(&curline[i], " // ERROR");
            else std::sprintf(&curline[i], " // %s", pending[depth-1]);
            depth--;
        }
        std::fprintf(out, "%s\n", curline);
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

// end of tagifs.cpp
