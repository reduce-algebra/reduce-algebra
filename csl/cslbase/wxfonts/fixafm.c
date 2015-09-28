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

// For cslSTIXMath-Regular this also scans the ouput from a program that
// displays the opentype tables, and extracts some of the MATHS tables.
// Specifically three sorts of information are grabbed:
// (1) information about the horizontal position to be used for an
//     accent placed above a character.
// (2) variant glyphs that can be used to display a variety of sizes
//     of the base character. Eg "(" is associated with a number of
//     glyphs that each represent gradually larger left parentheses.
// (3) up to five glyphs that can be used (sometimes horizontally, sometimes
//     vertically) to build up even larger versions of the symbol. For
//     instance "{" comes with a top-hook, an extension piece, a middle
//     unit, a lower extension and a botto, hook.
// The information about these is written in a style somewhat similar
// to that used for the standard information in an ".afm" file, but is
// custom and private for my own use.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../uninames.c"

static int isSTIX = 0, isMath = 0;

#define NMOVED 10000
#define MAXNEWNAME 120

static int nmoved = 0;
char movedname[NMOVED][MAXNEWNAME];
int movedwidth[NMOVED];

// If the any strings of the form "unixxxx" for hex digits xxxx are present
// and if I know a name for U+xxxx then I will re-write the input in
// linebuffer. Note that this can lead to long names and in cmuntt the line
// giving ligatures with SPACE ends up almost 2000 characters long. Ugh!

char newlinebuffer[2000];

static void adjustuninames(char *linebuffer, int full)
{
    char *p, *q;
    const char *r;
    int code;
    p = linebuffer;
    q = newlinebuffer;
    while (*p != 0)
    {   if (p[0] == 'u' &&
            p[1] == 'n' &&
            p[2] == 'i' &&
            isxdigit(p[3]) &&
            isxdigit(p[4]) &&
            isxdigit(p[5]) &&
            isxdigit(p[6]) &&
            !isxdigit(p[7]) &&
            sscanf(p, "uni%x", &code) == 1 &&
            (r = uniname(code)) != NULL)
        {   strcpy(q, r);
            p += 7;
            q += strlen(r);
        }
        else if (full &&
            p[0] == 'u' &&
            isxdigit(p[1]) &&
            isxdigit(p[2]) &&
            isxdigit(p[3]) &&
            isxdigit(p[4]) &&
            isxdigit(p[5]) &&
            !isxdigit(p[6]) &&
            sscanf(p, "u%x", &code) == 1 &&
            (r = uniname(code)) != NULL)
        {   strcpy(q, r);
            p += 6;
            q += strlen(r);
        }

        else *q++ = *p++;
    }
    *q = 0; 
    strcpy(linebuffer, newlinebuffer);
}

static void variation(FILE *dest, char *tag, char *name)
{
    char *p = strchr(name, ':');
    if (p != NULL) *p = 0;
    fprintf(dest, " %s %s ;", tag, name);
}

static void variation1(FILE *dest, char *tag, char *name,
                       int nstart, int nend, int nfull, int nflags)
{
    char *p = strchr(name, ':');
    if (p != NULL) *p = 0;
    fprintf(dest, " %s %s %d %d %d %d;", tag, name, nstart, nend, nfull, nflags);
}

int xstart[5], xend[5], xfull[5], xflags[5];

static void variations(FILE *dest, int num,
                       char *n1, char *n2, char *n3, char *n4, char *n5,
                       char *p1, char *p2, char *p3, char *p4, char *p5)
{
    switch (num)
    {
case 1: variation(dest, "V1", n1);
        break;
case 2: variation(dest, "V1", n1);
        variation(dest, "V2", n2);
        break;
case 3: variation(dest, "V1", n1);
        variation(dest, "V2", n2);
        variation(dest, "V3", n3);
        break;
case 4: variation(dest, "V1", n1);
        variation(dest, "V2", n2);
        variation(dest, "V3", n3);
        variation(dest, "V4", n4);
        break;
case 5: variation(dest, "V1", n1);
        variation(dest, "V2", n2);
        variation(dest, "V3", n3);
        variation(dest, "V4", n4);
        variation(dest, "V5", n5);
        break;
    }
    if (*p1 != 0) variation1(dest, "P1", p1, xstart[0], xend[0], xfull[0], xflags[0]);
    if (*p2 != 0) variation1(dest, "P2", p2, xstart[1], xend[1], xfull[1], xflags[1]);
    if (*p3 != 0) variation1(dest, "P3", p3, xstart[2], xend[2], xfull[2], xflags[2]);
    if (*p4 != 0) variation1(dest, "P4", p4, xstart[3], xend[3], xfull[3], xflags[3]);
    if (*p5 != 0) variation1(dest, "P5", p5, xstart[4], xend[4], xfull[4], xflags[4]);
}

char name[MAXNEWNAME];
char n1[MAXNEWNAME], n2[MAXNEWNAME], n3[MAXNEWNAME],
     n4[MAXNEWNAME], n5[MAXNEWNAME];
char partname[MAXNEWNAME], junk[MAXNEWNAME];
char p1[MAXNEWNAME], p2[MAXNEWNAME], p3[MAXNEWNAME],
     p4[MAXNEWNAME], p5[MAXNEWNAME];
char linebuffer[2000];

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");
    isSTIX = isMath = 0;
    if (src == NULL)
    {   fprintf(stderr, "Need %s\n", argv[1]);
        exit(1);
    }
    if (dest == NULL)
    {   fprintf(stderr, "Need to write to %s\n", argv[2]);
        exit(1);
    }
    if (strstr(argv[1], "STIX") != NULL) isSTIX = 1;
    if (strstr(argv[1], "Math") != NULL) isMath = 1;
    if (isSTIX)
    {   int private_area = 0;
        nmoved = 0;
        for (;;)
        {   int c, i = 0, width;
            while ((c = getc(src)) != EOF && c != '\n')
                linebuffer[i++] = c;
            linebuffer[i] = 0;
            if (i == 0 && c == EOF) break;
            adjustuninames(linebuffer, 0);
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
        if (strcmp(linebuffer, "EndFontMetrics") == 0) continue;
        adjustuninames(linebuffer, 0);
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
    if (isMath)
    {   src = fopen("STIXMath.tables", "r");
        int topAccent = 0, Variants = 0, offset;
        int anything = 0, num = 0;
        int partcount=0, partnumber=0;
        int start, end, full, flags;
        if (src == NULL)
        {   fprintf(stderr, "Need STIXMath.tables\n");
            exit(1);
        }
        for (;;)
        {   int c, i = 0;
            char *p;
// I rather arbitrarily truncate the input lines at 400 characters. Something
// like that is needed here because some lines in the "tables" are utterly
// and ridiculously long. Specifically the longest line is has almost 28000
// characters on it! That one starts with
// "char strings 1476: 597 -273 21 232 20 656 20 176 22 hstemhm 0 60 0 60 0..."
//
            while ((c = getc(src)) != EOF && c != '\n')
                if (i < 400) linebuffer[i++] = c;
            linebuffer[i] = 0;
            if (i == 0 && c == EOF) break;
            adjustuninames(linebuffer, 1);
            if (strncmp(linebuffer, "  MATH Top Accent", 17) == 0)
                topAccent = 1;
            else if (strncmp(linebuffer, " MATH Variants", 14) == 0)
            {   topAccent = 0;
                Variants = 1;
                if (anything) fprintf(dest, "EndTopAccent\n");
                anything = 0;
            }
            if (topAccent &&
                sscanf(linebuffer, " Glyph %s %d", name, &offset) == 2)
            {   if (!anything)
                {   fprintf(dest, "StartTopAccent\n");
                    anything = 1;
                }
                p = strchr(name, '(');
                if (p != NULL) *p = 0;
                fprintf(dest, "N %s ; DX %d ;\n", name, offset);
            }
            if (Variants)
            {   if (sscanf(linebuffer, " V Glyph %s", name) == 1)
                {   variations(dest, num, n1, n2, n3, n4, n5, p1, p2, p3, p4, p5);
                    num = 0;
                    if (!anything)
                    {   fprintf(dest, "StartVariations\n");
                        anything = 1;
                    }
                    else fprintf(dest, "\n");
                    p = strchr(name, '(');
                    if (p != NULL) *p = 0;
                    fprintf(dest, "VX %s ;" , name);
                    continue;
                }
                if (sscanf(linebuffer, " H Glyph %s", name) == 1)
                {   variations(dest, num, n1, n2, n3, n4, n5, p1, p2, p3, p4, p5);
                    num = 0;
                    if (!anything)
                    {   fprintf(dest, "StartVariations\n");
                        anything = 1;
                    }
                    else fprintf(dest, "\n");
                    p = strchr(name, '(');
                    if (p != NULL) *p = 0;
                    fprintf(dest, "HX %s ;", name);
                    continue;
                }
                if (sscanf(linebuffer, " Variant Count = %d", &num) == 1)
                    continue;
                switch (num)
                {
            case 1: if (sscanf(linebuffer, " Variants: %s",
                               n1) == 1) continue;
            case 2: if (sscanf(linebuffer, " Variants: %s %s",
                               n1, n2) == 1) continue;
            case 3: if (sscanf(linebuffer, " Variants: %s %s %s",
                               n1, n2, n3) == 1) continue;
            case 4: if (sscanf(linebuffer, " Variants: %s %s %s %s",
                               n1, n2, n3, n4) == 1) continue;
            case 5: if (sscanf(linebuffer, " Variants: %s %s %s %s %s",
                               n1, n2, n3, n4, n5) == 1) continue;
                }
                if (sscanf(linebuffer, " Part Count=%d", &partcount) == 1)
                {   partnumber = 0;
                    continue;
                }
                if (sscanf(linebuffer, " %s start=%d end=%d full=%d flags=%d(%s",
                    partname, &start, &end, &full, &flags, junk) == 6)
                {   switch (partnumber)
                    {
                case 0: strcpy(p1, partname);
                        xstart[0] = start;
                        xend[0]   = end;
                        xfull[0]  = full;
                        xflags[0] = flags;
                        break;
                case 1: strcpy(p2, partname);
                        xstart[1] = start;
                        xend[1]   = end;
                        xfull[1]  = full;
                        xflags[1] = flags;
                        break;
                case 2: strcpy(p3, partname);
                        xstart[2] = start;
                        xend[2]   = end;
                        xfull[2]  = full;
                        xflags[2] = flags;
                        break;
                case 3: strcpy(p4, partname);
                        xstart[3] = start;
                        xend[3]   = end;
                        xfull[3]  = full;
                        xflags[3] = flags;
                        break;
                case 4: strcpy(p5, partname);
                        xstart[4] = start;
                        xend[4]   = end;
                        xfull[4]  = full;
                        xflags[4] = flags;
                        break;
                    }
                    printf("Part %4d (%4d %4d %4d %4d %s has name %s \n",
                           ++partnumber,
                           start, end, full, flags, junk, partname);
                }
            }
        }
        variations(dest, num, n1, n2, n3, n4, n5, p1, p2, p3, p4, p5);
        if (anything) fprintf(dest, "\nEndVariations\n");
        fclose(src);
    }
    fprintf(dest, "EndFontMetrics\n");
    fclose(dest);
    return 0;
}

// end of fixafm.c
