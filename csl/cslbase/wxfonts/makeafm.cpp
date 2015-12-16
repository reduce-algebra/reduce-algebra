// makeafm.cpp

// This is work in progress - I now believe that all I will put in here
// wil be stuff to extra just the maths tables...

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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

// This program scans the output from showttf.c and extracts from
// it stuff that I will put in a file called *.afm. This will not be a full
// Adobe Font Metric file - it contains just the stuff I want to then
// extract using further code that turns it into a more compact form that
// I use with Reduce. Specifically I want the CharMetrics and the KernPairs
// parts (and I will also in due couse extract some Maths tables)

// Usage:
//   makeafm filename.tables
// will create filename.afm

#include <cstdio>
// Right now g++ needs --std=c++11 to support <cstdint>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cctype>

static FILE *source_file, *dest_file;

static void close_files()
{   fclose(source_file);
    fclose(dest_file);
}

static void process_file();

int main(int argc, char *argv[])
{   if (argc != 2)
    {   fprintf(stderr, "Usage: makeafm filename.tables\n");
        exit(1);
    }
// I will allow myself to use the C99 ability to put declarations almost
// anywhere, as well as using "//" comments. So this will not compile with
// legacy compilers. Since it is only a small utility run basically once
// this does not worry me too much.
    char *source_name = argv[1];
    printf("Processing %s\n", source_name);
    const char *dot = strrchr(source_name, '.');
    if (dot == NULL)
    {   fprintf(stderr, "Argument needs a dot (.) in it\n");
        exit(1);
    }
    char *dest_name = (char *)malloc(strlen(source_name) - strlen(dot) + 8);
    if (dest_name == NULL)
    {   fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    sprintf(dest_name, "%.*s.afm", (int)(dot-source_name), source_name);
    printf("Destination will be %s\n", dest_name);

    source_file = fopen(source_name, "r");
    if (source_file == NULL)
    {   fprintf(stderr, "Failed to access \"%s\"\n", source_name);
        exit(1);
    }
    dest_file = fopen(dest_name, "w");
    if (dest_file == NULL)
    {   fprintf(stderr, "Failed to access \"%s\"\n", dest_name);
        fclose(source_file);
        exit(1);
    }
    process_file();
    atexit(close_files);
    return 0;
}

#define INPUTLINE  10000        // some lines in the tables file are
// astonishingly long. Typically in the "subrs"
// table, where I will not actually care
// about the information! I think I will
// will overflow.
#define MAXUNINAME 80           // longest character name is 80 characters.
#define MAXCHARS   20000        // at most 20K chars in any one font.


static int      nchars = 0;
static char     charname[MAXCHARS][MAXUNINAME];
static uint32_t codepoint[MAXCHARS];
static int      glyphnumber[MAXCHARS];

static int      glyphindex[MAXCHARS];

static char inputline[INPUTLINE];

// Read one line of input. Truncate in buffer if too long. Return true
// if terminated by EOF rather than a newline.

static int read_line()
{   int n = 0;
    int c;
    while ((c = getc(source_file)) != EOF &&
           c != '\n')
    {   if (n < sizeof(inputline)-1) inputline[n++] = c;
    }
    inputline[n] = 0;
    return (c == EOF);
}

enum
{   HEAD_table = 1,
    HHEAD_table,
    NAME_table,
    OS2_table,
    MAXP_table,
    POST_table,
    POSTSCRIPT_table,
    CHARSET_format,
    GSUB_table,
    KERN_table
};

static void generate_output();

static void process_file()
{   int i;
    for (i=0; i<MAXCHARS; i++)
    {   codepoint[i] = -1;
        glyphnumber[i] = 0;
        glyphindex[i] = 0;
        charname[i][0] = 0;
    }
    nchars = 0;
    int state = 0;
    int glyphnum, point;
    char name[MAXUNINAME];
// Read input file line by line until EOF
    while (!read_line())
    {   int oldstate = state;
        if (strncmp(inputline, "HEAD table", 10) == 0) state = HEAD_table;
        else if (strncmp(inputline, "HHEAD table", 11) == 0) state = HHEAD_table;
        else if (strncmp(inputline, "NAME table", 10) == 0) state = NAME_table;
        else if (strncmp(inputline, "OS/2 table", 10) == 0) state = OS2_table;
        else if (strncmp(inputline, "MAXP table", 10) == 0) state = MAXP_table;
        else if (strncmp(inputline, "post table", 10) == 0) state = POST_table;
        else if (strncmp(inputline, "Postscript CFF table", 20) == 0) state = POSTSCRIPT_table;
        else if (strncmp(inputline, "Charset format", 14) == 0) state = CHARSET_format;
        else if (strncmp(inputline, "GSUB table", 10) == 0) state = GSUB_table;
        else if (strncmp(inputline, "kern table", 10) == 0) state = KERN_table;

        if (state != oldstate) printf("%s\n", inputline);

        switch (state)
        {
// I want the MAXP table to be present before anything that gives names
// to glyphs or characters.
            case MAXP_table:
                if (sscanf(inputline, " Glyph %d -> U+%x", &glyphnum, &point) == 2)
                {   if (nchars >= MAXCHARS ||
                        glyphnum >= MAXCHARS)
                    {   printf("Glyph %d would be character number %d\n",
                               glyphnum, nchars);
                        exit(1);
                    }
                    codepoint[nchars] = point;
                    glyphnumber[nchars] = glyphnum;
                    glyphindex[glyphnum] = nchars;
                    nchars++;
                }
                break;
            case CHARSET_format:
                if (sscanf(inputline, " Glyph %d is named %d %s", &glyphnum, &point, name) == 3)
                {   int k = glyphindex[glyphnum];
                    if (k != 0 && k <nchars)
                        strcpy(charname[k], name);
                }
                break;
// By the time I have processed the above I should have enough to map
// between codepoints and names.
            case GSUB_table:
// The GSUB table seems to have information about ligatures
                break;
            case KERN_table:
// Much of this goes simply and directly into KPX records.
                break;
        }
    }
    generate_output();
}

static int tableindex[MAXCHARS];

static int indexcf(const void *a, const void *b)
{   return codepoint[*(int *)a] - codepoint[*(int *)b];
}

static void generate_output()
{   int i;
    for (i=0; i<nchars; i++) tableindex[i] = i;
    qsort(tableindex, nchars, sizeof(int), indexcf);
    printf("%d items found\n", nchars);
    int count = 0;
    for (i=0; i<nchars; i++)
    {   int j = tableindex[i];
        if (codepoint[j] != -1 & codepoint[j] != 0) count++;
    }
    fprintf(dest_file, "StartCharMetrics %d\n", count);
    for (i=0; i<nchars; i++)
    {   int j = tableindex[i];
        if (codepoint[j] != -1 & codepoint[j] != 0)
        {   fprintf(dest_file, "C %d ; WX %d ; N %s ;",
                    codepoint[j], 999, charname[j]);
            fprintf(dest_file, "\n");
        }
    }
    fprintf(dest_file, "EndCharMetrics\n");
}

// end of makeafm.cpp
