// get-computer-modern-metrics.cpp         Copyright (C) 2015-2022 Codemist

// This extracts just enough font information from a bunch of *.afm
// files that I can render Postscript properly from FXDCPostscriptPrinter.cpp
//
// The font metrics used here are a subset of the Computer Modern set
// and I use the AMS versions, which are freely available for all purposes.
// I have the fonts themselves and the explicit statement of their
// license terms elsewhere.
//
//                                      A C Norman.  September 2015
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
#include <cstdlib>

//
// This program is really just for MY use so I will build a fixed
// path in here and let anybody who disagrees with it change the source
// code and re-compile.
//
#define FONT_PATH "../fonts/cmpsfont-unix/afm"


//
// From the .afm file I will extract lines
//   FontName name                 eg FontName Times-Italic
//   IsFixedPitch fg               eg fg=true or false
//   Ascender n
//   Descender n
//   XHeight n
//   CapHeight n
//   FontBBox n n n n              bounding box for entire font
//   C nn ; WX mm ; N name ; B n n n n   code, width, name, char bounding box
// other lines will be ignored
//

static std::FILE *out = nullptr;

static int process(char *d, char *s)
{   char line[1000], junk[1000], name[1000];
    int charwidth[256];
    int isFixed = -1;
    int bb1=-1, bb2=-1, bb3=-1, bb4=-1;  // font bounding box
    int bc1, bc2, bc3, bc4;
    double dw, dc1, dc2, dc3, dc4;
    int ascender=-1, descender=-1, xheight=-1, capheight=-1;
    int maxleftbearing = 0, maxrightbearing = 0i, maxwidth = 0;
    int charNo, charWidth;
    std::FILE *f;
    int c, p, n;
    int headershown = 0;
    std::snprintf(line, sizeof(line), "%s/%s", FONT_PATH, s);
    f = std::fopen(line, "r");
    if (f == nullptr)
    {   std::fprintf(stderr, "Failed to read \"%s\"\n", line);
        std::exit(1);
    }
    name[0] = 0;
    for (c=0; c<256; c++) charwidth[c] = -1;
    for (;;)
    {   p = 0;
        for (c=std::getc(f); c!='\n' && c!=EOF; c=std::getc(f))
        {   if (p < sizeof(line)-2) line[p++] = c;
        }
        line[p] = 0;
        charNo = charWidth = -1;
        if (std::sscanf(line, "FontName %s", name) == 1);
        else if (std::sscanf(line, "IsFixedPitch fals%s", junk) == 1)
            isFixed = 0;
        else if (std::sscanf(line, "IsFixedPitch tru%s", junk) == 1)
            isFixed = 1;
        else if (std::sscanf(line, "Comment%s", junk) == 1);
        else if (std::sscanf(line, "KPX%s", junk) == 1);
        else if (std::sscanf(line, "FontBBox %d %d %d %d",
                             &bb1, &bb2, &bb3, &bb4) == 4);
        else if (std::sscanf(line, "CapHeight %d", &capheight) == 1);
        else if (std::sscanf(line, "XHeight %d", &xheight) == 1);
        else if (std::sscanf(line, "Ascender %d", &ascender) == 1);
        else if (std::sscanf(line, "Descender %d", &descender) == 1);
        else if (std::sscanf(line,
                             "C %d ; WX %lf ; N %*s ; B %lf %lf %lf %lf %s",
                             &charNo, &dw,
                             &dc1, &dc2, &dc3, &dc4, junk) == 7)
        {   if (charNo >= 0 && charNo < 256 &&
                dw >= 0.0)
            {   int rightbearing, leftbearing;
                charWidth = static_cast<int>(dw + 0.5);
                bc1 = static_cast<int>(dc1 + 0.5);
                bc2 = static_cast<int>(dc2 + 0.5);
                bc3 = static_cast<int>(dc3 + 0.5);
                bc4 = static_cast<int>(dc4 + 0.5);
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
        else if (std::sscanf(line, "Comment%s", junk) == 1);
        else if (std::sscanf(line, "EndKern%s", junk) == 1);
        else if (std::sscanf(line, "EndFont%s", junk) == 1);
        else if (std::sscanf(line, "StartFont%s", junk) == 1);
        else if (std::sscanf(line, "Encoding%s", junk) == 1);
        else if (std::sscanf(line, "Weight%s", junk) == 1);
        else if (std::sscanf(line, "Italic%s", junk) == 1);
        else if (std::sscanf(line, "Notice%s", junk) == 1);
        else if (std::sscanf(line, "EndChar%s", junk) == 1);
        else if (std::sscanf(line, "StartChar%s", junk) == 1);
        else if (std::sscanf(line, "Family%s", junk) == 1);
        else if (std::sscanf(line, "FullName%s", junk) == 1);
        else if (std::sscanf(line, "StartKern%s", junk) == 1);
        else if (std::sscanf(line, "Version%s", junk) == 1);
        else if (std::sscanf(line, "KPX%s", junk) == 1);
        else std::printf("  Unparsed \"%s\"\n", line);
        if (c == EOF) break;
    }
    std::fclose(f);
    if (name[0] == 0) return;  // no font name
    std::fprintf(out, "{\"%s\", %d, %d, %d, %d, %d, %d, %d, %d, {\n",
                 name, isFixed, maxwidth, maxleftbearing, maxrightbearing,
                 capheight, xheight, ascender, descender);
    for (c=0; c<255; c++)
    {   std::fprintf(out, "%6d,", charwidth[c]);
        if ((c % 8) == 7) std::fprintf(out, "\n");
    }
    std::fprintf(out, "%6d }},\n", charwidth[255]);
}

int main(int argc, char *argv[])
{   std::FILE *note;
    int ch;
    out = std::fopen("cmfont-info.cpp", "w");
    if (out == nullptr)
    {   std::printf("Failed to open cmfont-info.cpp\n");
        return 1;
    }
    std::fprintf(out, "/*\n * cmfont-info.cpp\n");
    std::fprintf(out,
                 " * Font metrics for Type1 Computer Modern Fonts\n *\n");
    std::fprintf(out, " * extracted from %s\n *\n", FONT_PATH);
    std::fprintf(out, " */\n");
    std::fprintf(out, "\n\n\n");
    std::fprintf(out, "typedef struct font_info {\n");
    std::fprintf(out, "   char *name;\n");
    std::fprintf(out,
                 "   short int isfixed, fontwidth, maxleftbearing, maxrightbearing;\n");
    std::fprintf(out,
                 "   short int capheight, xheight, ascent, descent;\n");
    std::fprintf(out, "   short int charwidth[256];\n");
    std::fprintf(out, "} font_info;\n\n");
    std::fprintf(out, "static font_info cm_font_widths[] = {\n");
//
// There are fonts that actually interest me...
//
    process("cmr5",     "cmr5.afm");
    process("cmr6",     "cmr6.afm");
    process("cmr7",     "cmr7.afm");
    process("cmr8",     "cmr8.afm");
    process("cmr9",     "cmr9.afm");
    process("cmr10",    "cmr10.afm");
    process("cmr12",    "cmr12.afm");
    process("cmr17",    "cmr17.afm");
    process("cmmi5",    "cmmi5.afm");
    process("cmmi6",    "cmmi6.afm");
    process("cmmi7",    "cmmi7.afm");
    process("cmmi8",    "cmmi8.afm");
    process("cmmi9",    "cmmi9.afm");
    process("cmmi10",   "cmmi10.afm");
    process("cmmi12",   "cmmi12.afm");
    process("cmsy5",    "cmsy5.afm");
    process("cmsy6",    "cmsy6.afm");
    process("cmsy7",    "cmsy7.afm");
    process("cmsy8",    "cmsy8.afm");
    process("cmsy9",    "cmsy9.afm");
    process("cmsy10",   "cmsy10.afm");
    process("cmex10",   "cmex10.afm");

    std::fprintf(out, "{(char *)0, 0,0,0,0,0,0,0,0, {0}}};\n\n\n");
    std::fprintf(out, "/* End of cmfont-info.cpp */\n");
    std::fclose(out);
    std::printf("File \"cmfont-info.cpp\" created\n");
    return 0;
}

// end of get-computer-modern-metrics.cpp
