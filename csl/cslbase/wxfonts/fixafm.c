// fixafm.c

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


// This is an utterly specialised progrem for making adjustments to
// Adobe Font Metrics in a way specifically wanted when I am trying to
// create them for the STIX fonts (which have codepoints outside the
// basic multilingual plane and where I have remapped some glyphs from
// outside the Unicode range to be at U+108xxx).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../uninames.c"

static int isSTIX = 0;

#define NMOVED 10000
#define MAXNEWNAME 20

static int nmoved = 0;
char movedname[NMOVED][MAXNEWNAME];
int movedwidth[NMOVED];

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w"); // No check for errors here!
    char linebuffer[1000];            // Fixed buffer with no overflow checks!
    if (strstr(argv[1], "STIX") != NULL) isSTIX = 1;
    if (isSTIX)
    {    int private_area = 0;
         char name[MAXNEWNAME];
         nmoved = 0;
         for (;;)
         {   int c, i = 0, width;
             while ((c = getc(src)) != EOF && c != '\n')
                 linebuffer[i++] = c;
             linebuffer[i] = 0;
             if (i == 0 && c == EOF) break;
// For the STIX fonts that I am using the glyph that fontforge displays as
// if it had been at U+110000 is named ".notdef". Here I collect the
// names that have been provided for all those out-of-range glyphs.
             if (sscanf(linebuffer, "C -1 ; WX %d ; N ",
                            &width) == 1)
             {   char *p = linebuffer + 9;
                 int j = 0;
                 while (*p != ';') p++;
                 p = p + 4;
                 while (*p != ' ') name[j++] = *p++;
                 name[j] = 0;
                 if (strcmp(name, ".notdef") == 0) private_area = 1;
                 if (private_area)
                 {   strcpy(movedname[nmoved], name);
                     movedwidth[nmoved] = width;
                     nmoved++;
                 }
             }
         }
         fseek(src, (off_t)0, SEEK_SET);
    }

    for (;;)
    {   int c, i = 0;
        while ((c = getc(src)) != EOF && c != '\n')
            linebuffer[i++] = c;
        linebuffer[i] = 0;
        if (i == 0 && c == EOF) break;
        if (strncmp(linebuffer, "C -1 ; ", 7) == 0)
        {   int width, code;
            if (sscanf(linebuffer, "C -1 ; WX %d ; N u%x ;",
                       &width, &code) == 2)
            {   char *p = linebuffer + 10;
                while (*p != ';') p++;
                p++;
                while (*p == ' ') p++;
                if (*p != 'N')
                {   printf("Formatting failure\n");
                    exit(1);
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
                if (r == NULL)
                {    if  (code >= 0x108000 &&
                          code-0x108000 < nmoved &&
                          width == movedwidth[code-0x108000])
                         r = movedname[code-0x108000];
                     else r = p;
                }
                fprintf(dest, "C %d ; WX %d ; N %s ;%s\n",
                    code, width, r, q+1);
            }
        }
        else fprintf(dest, "%s\n", linebuffer);
    }
    fclose(src);
    fclose(dest);
    return 0;
}

// end of fixafm.c
