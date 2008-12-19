/*
 * get-adobe-metrics.c
 *
 * This extracts just enough font information from a bunch of *.afm
 * files that I can render Postscript properly from FXDCPostscriptPrinter.cpp
 *
 * The font metrics it works can be found on many sites - they can be
 * downloaded directly from Adobe's ftp site but also they are included
 * with many existing software packages in forms that clearly state that
 * they are available for redistribution and that the authors of those
 * packages have checked license conditions carefully. The set of files
 * I use here came with "teTeX 2" where these terms are carefully set
 * out and where the package is very well established and widely used so
 * there would have been plenty of opportunity for concerns about rights
 * to be aired. I have not altered the metric files at all.
 *
 * Note that the file-names I expect to be used for fonts follow the
 * "Berry" naming convention used within the TeX community, and the
 * directory organisation is as in teTeX.
 *
 *                                      A C Norman.  November 2003
 */


/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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




/* Signature: 080ff265 24-May-2008 */

#include <stdio.h>
#include <stdlib.h>

#define FONT_PATH "./tetex/fonts/afm/adobe"


/*
 * From the .afm file I will extract lines
 *   FontName name                 eg FontName Times-Italic
 *   IsFixedPitch fg               eg fg=true or false
 *   Ascender n
 *   Descender n
 *   XHeight n
 *   CapHeight n
 *   FontBBox n n n n              bounding box for entire font
 *   C nn ; WX mm ; N name ; B n n n n   code, width, name, char bounding box
 * other lines will be ignored
 */

static FILE *out = NULL;

static int process(char *d, char *s)
{
    char line[1000], junk[1000], name[1000];
    int charwidth[256];
    int isFixed = -1;
    int bb1=-1, bb2=-1, bb3=-1, bb4=-1;  /* font bounding box */
    int bc1, bc2, bc3, bc4;
    int ascender=-1, descender=-1, xheight=-1, capheight=-1;
    int maxleftbearing = 0, maxrightbearing = 0i, maxwidth = 0;
    int charNo, charWidth;
    FILE *f;
    int c, p, n;
    int headershown = 0;
    sprintf(line, "%s/%s/%s", FONT_PATH, d, s);
    f = fopen(line, "r");
    if (f == NULL)
    {   fprintf(stderr, "Failed to read \"%s\"\n", line);
        exit(1);
    }
    name[0] = 0;
    for (c=0; c<256; c++) charwidth[c] = -1;
    for (;;)
    {   p = 0;
        for (c=getc(f); c!='\n' && c!=EOF; c=getc(f))
        {   if (p < sizeof(line)-2) line[p++] = c;
        }
        line[p] = 0;
        charNo = charWidth = -1;
        if (sscanf(line, "FontName %s", name) == 1);
        else if (sscanf(line, "IsFixedPitch fals%s", junk) == 1)
            isFixed = 0;
        else if (sscanf(line, "IsFixedPitch tru%s", junk) == 1)
            isFixed = 1;
        else if (sscanf(line, "FontBBox %d %d %d %d",
                              &bb1, &bb2, &bb3, &bb4) == 4);
        else if (sscanf(line, "CapHeight %d", &capheight) == 1);
        else if (sscanf(line, "XHeight %d", &xheight) == 1);
        else if (sscanf(line, "Ascender %d", &ascender) == 1);
        else if (sscanf(line, "Descender %d", &descender) == 1);
        else if (sscanf(line, "C %d ; WX %d ; N %*s ; B %d %d %d %d",
                              &charNo, &charWidth,
                              &bc1, &bc2, &bc3, &bc4) == 6)
        {   if (charNo >= 0 && charNo < 256 &&
                charWidth >= 0)
            {   int rightbearing, leftbearing;
                charwidth[charNo] = charWidth;
                if (charWidth > maxwidth) maxwidth = charWidth;
                if (bc1!=0 || bc2!=0 || bc3!=0 || bc4!=0)
                {   leftbearing = bc1;
                    rightbearing = charWidth - bc3;
                    if (leftbearing > maxleftbearing)
                        maxleftbearing = leftbearing;
                    if (rightbearing > maxrightbearing)
                        maxrightbearing = rightbearing;
                }
            }
        }
        if (c == EOF) break;
    }
    fclose(f);
    if (name[0] == 0) return;  /* no font name */
    fprintf(out, "{\"%s\", %d, %d, %d, %d, %d, %d, %d, %d, {\n",
        name, isFixed, maxwidth, maxleftbearing, maxrightbearing,
        capheight, xheight, ascender, descender);
    for (c=0; c<255; c++)
    {   fprintf(out, "%6d,", charwidth[c]);
        if ((c % 8) == 7) fprintf(out, "\n");
    }
    fprintf(out, "%6d }},\n", charwidth[255]); 
}

int main(int argc, char *argv[])
{
    FILE *note;
    int ch;
    if ((note = fopen(FONT_PATH "/../../../LICENSE.texmf", "r")) == NULL)
    {   fprintf(stderr, "+++ Failed to find proper fonts directory\n");
        exit(1);
    }
    printf("Here is the license notice from the fonts source directory:\n\n");
    for (ch=getc(note); ch!=EOF; ch=getc(note)) putchar(ch);
    printf("\n");
    out = fopen("font-info.c", "w");
    if (out == NULL)
    {   printf("Failed to open font-info.c\n");
        return 1;
    }
    fprintf(out, "/*\n * font-info.c\n");
    fprintf(out, " * Font metrics for Adobe Type1 Fonts\n *\n");
    fprintf(out, " * extracted from %s\n *\n", FONT_PATH);
    fprintf(out, " * see file LICENCE.texmf within that tree for a clear\n");
    fprintf(out, " * statement that the files may be distributed.\n");
    fprintf(out, " * Thank you to Adobe and to the teTeX people.\n");
    fprintf(out, " * ftp.adobe.com/pub/adobe/type/win/all/afmfiles/base35\n");
    fprintf(out, " * and www.tug.org/teTeX.\n");
    fprintf(out, " */\n");
    fprintf(out, "\n\n/* Signature: 2b9130e7 22-Nov-2003 */\n\n\n");
    fprintf(out, "typedef struct font_info {\n");
    fprintf(out, "   char *name;\n");
    fprintf(out, "   short int isfixed, fontwidth, maxleftbearing, maxrightbearing;\n");
    fprintf(out, "   short int capheight, xheight, ascent, descent;\n");
    fprintf(out, "   short int charwidth[256];\n");
    fprintf(out, "} font_info;\n\n");
    fprintf(out, "static font_info font_widths[] = {\n");
//
// There are 35 standard Postscript fonts that might be used with this
// print package. They are:
//
    process("avantgar", "pagd8a.afm");   // AvantGarde-Demi
    process("avantgar", "pagdo8a.afm");  // AvantGarde-DemiOblique
    process("avantgar", "pagk8a.afm");   // AvantGarde-Book
    process("avantgar", "pagko8a.afm");  // AvantGarde-BookOblique
    process("bookman",  "pbkd8a.afm");   // Bookman-Demi
    process("bookman",  "pbkdi8a.afm");  // Bookman-DemiItalic
    process("bookman",  "pbkl8a.afm");   // Bookman-Light
    process("bookman",  "pbkli8a.afm");  // Bookman-LightItalic
    process("courier",  "pcrb8a.afm");   // Courier-Bold                 *
    process("courier",  "pcrbo8a.afm");  // Courier-BoldOblique          *
    process("courier",  "pcrr8a.afm");   // Courier                      *
    process("courier",  "pcrro8a.afm");  // Courier-Oblique              *
    process("helvetic", "phvb8a.afm");   // Helvetica-Bolda              *
    process("helvetic", "phvb8an.afm");  // Helvetica-Narrow-Bold
    process("helvetic", "phvbo8a.afm");  // Helvertica-BoldOblique       *
    process("helvetic", "phvbo8an.afm"); // Helvetica-Narrow-BoldOblique
    process("helvetic", "phvr8a.afm");   // Helvetica                    *
    process("helvetic", "phvr8an.afm");  // Helvetica-Narrow
    process("helvetic", "phvro8a.afm");  // Helvetica-Oblique            *
    process("helvetic", "phvro8an.afm"); // Helvetica-NarrowOblique
    process("ncntrsbk", "pncb8a.afm");   // NewCenturySchlbk-Bold
    process("ncntrsbk", "pncbi8a.afm");  // NewCenturySchlbk-BoldItalic
    process("ncntrsbk", "pncr8a.afm");   // NewCenturySchlbk-Roman
    process("ncntrsbk", "pncri8a.afm");  // NewCenturySchlbk-Italic
    process("palatino", "pplb8a.afm");   // Palatino-Bold
    process("palatino", "pplbi8a.afm");  // Palatino-BoldItalic
    process("palatino", "pplr8a.afm");   // Palatino-Roman
    process("palatino", "pplri8a.afm");  // Palatino-Italic
    process("symbol",   "psyr.afm");     // Symbol                       *
    process("times",    "ptmb8a.afm");   // Times-Bold                   *
    process("times",    "ptmbi8a.afm");  // Times-BoldItalic             *
    process("times",    "ptmr8a.afm");   // Times-Roman                  *
    process("times",    "ptmri8a.afm");  // Times-Italic                 *
    process("zapfchan", "pzcmi8a.afm");  // ZapfChancery-MediumItalic
    process("zapfding", "pzdr.afm");     // ZapfDingbats
// Fonts with a "*" comment above are the ones that the early versions
// of Postscript supported.
    fprintf(out, "{(char *)0, 0,0,0,0,0,0,0,0, {0}}};\n\n\n");
    fprintf(out, "/* End of font-info.c */\n");
    fclose(out);
    printf("File \"font-info.c\" created\n");
    return 0;
}

/* end of get-adobe-metrics.c */

