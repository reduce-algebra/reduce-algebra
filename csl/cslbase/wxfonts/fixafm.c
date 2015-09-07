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
// Adobe Font Metrics in a way specificall wanted when I am trying to
// vreate them for the STIX fonts (which have codepoints outside the
// basic multilingual plane).

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w"); // No check for errors here!
    char linebuffer[1000];            // Fixed buffer with no overflow checks!
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
                fprintf(dest, "C %d ; WX %d %s\n", code, width, p);
            }
        }
        else fprintf(dest, "%s\n", linebuffer);
    }
    fclose(src);
    fclose(dest);
    return 0;
}

// end of fixafm.c
