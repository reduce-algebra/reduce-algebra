// flatten.cpp                                Copyright (C) A C Norman 2025

/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

// arithlib.cpp is to be a header-only library and because of that
// I want it to be a single file that can be #included. However
// for development purposes I want to keep some sections of code that
// it must incorporate in separate files. This will sometimes be just
// a matter of wanting to structure the code while I work on it and
// sometimes because the other code fragments could be useful of themselves
// not just within arithlib. So I have a file called arithlib.base.hpp that
// uses "#include" directives to incorporate those sub-libraries. This
// tool merges things to make the single-file version. Its use is:
//    flatten arithlib.base.cpp  arithlib.cpp
// The reads arithlib.base.cpp and if it finds a line of the form
//    #include "filename"
// and the named file is present in the current directory then the
// contents of the file are inserted in place of the #include directive.
// This process applies recursively. 


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <unordered_set>

using namespace std;

FILE* source;
FILE* destination;
FILE* includeFile;

const int maxLineLength = 2000;
char lineBuffer[maxLineLength];
unordered_set<string> included;

void process(FILE* from)
{   for (;;)
    {   int c;
        for (int i=0; i<maxLineLength; i++)
        {   c = getc(from);
            if (c == EOF) return;
            else if (c == '\n')
            {   lineBuffer[i] = 0;
                break;
            }
            else lineBuffer[i] = c;
        }
        if (c != '\n')
        {   fprintf(stderr, "Overlong line\n");
            exit(1);
        }
        if (strncmp(lineBuffer, "#include \"", 10) != 0)
        {   fprintf(destination, "%s\n", lineBuffer);
            continue;
        }
        char fname[100];
        for (int i=0; i<90; i++)
        {   if ((c = lineBuffer[i+10]) == '"')
            {   fname[i] = 0;
                break;
            }
            else fname[i] = c;
        }
        string s(fname);
        if (included.count(s) != 0) continue;
// fftkernel.cpp is very special and needs to be included several times!
        if (s.compare("fftkernel.cpp") != 0) included.insert(s);
        FILE* incFile = fopen(fname, "r");
        if (incFile == nullptr)
        {   fprintf(destination, "%s\n", lineBuffer);
            continue;
        }
        printf("Inserting from file %s\n", fname);
        process(incFile);
        fclose(incFile);
    }
}

int main(int argc, char *argv[])
{   if (argc < 3)
    {   fprintf(stderr, "Usage: flatten source_file destination_file\n");
        return 0;
    }
    const char* src = argv[1];
    const char* dest = argv[2];
    if ((source = fopen(src, "r")) == nullptr)
    {   fprintf(stderr, "File %s can not be read\n", src);
        return 1;
    }
    if ((destination = fopen(dest, "w")) == nullptr)
    {   fprintf(stderr, "File %s can not be written\n", dest);
        return 1;
    }
    process(source);
    printf("Completed\n");
    return 0;
}

// end of flatten.cpp

