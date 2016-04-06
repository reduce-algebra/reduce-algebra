// glyphtable.cpp                          Copyright (C) 2016 Codemist    

#error DEFUNCT

// THis code using glyphIgo etc is now supplanted by use of fontforge
// to create .afm files for the relevant fonts. Hence its output file,
// coverage.c is also no longer relevant.

// Build bitmap tables relating to characters present in fonts

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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
// Usage:
//    g++ glyphtable.cpp -o glyphtable
//    ./glyphtable wxfonts/*.glyphs
//    [admire the file coverage.cpp]
//
// This is achieved my going "make coverage.cpp" here...
//

//
// To sort out coverage maps for the fonts that I may use I use a
// sequence of steps.
// First I use glyphIgo (https://code.google.com/p/glyphigo/) to scan
// the .ttf or .oft file for the font so as to list the codes of all the
// glyphs defined. This relies on having the python-fontforge module
// installed. That gives me plain text lists of codepoints. This program
// then packs them to provide bitmaps.
// I pack a range of fonts, but information about each ends up in the
// table that is generated tagged with its name.
// Several special issues arise:
// (1) directly coded old-style TeX fonts do not need coverage maps because
//     they use just the codes in the range 0-127 (well at least logically...)
//     so going to this trouble for cmr10, cmmi10 etc is not necessary.
// (2) I choose to ignore any codes that are not in the Basic Multilingual
//     Plane. It appears that latinmodern-math defined a bunch of glyphs
//     with codes have large codes. Eg "mathematical" letters (including
//     math italic) starts at U+1d400 (to U+1d7ff) and will be needed. But
//     I will take special action on them!
// (3) Codes in the range U+d800 to U+f8ff are either surrogates or private
//     and so at one stage I planned to omit them from the maps to save
//     a little space. I now view that is a micro-optimisation that means that
//     when symbols I really want exist in the private range I am in trouble,
//     so I have backed off and just map the whole range.
// (4) By comparing the glyph-lists I observe (with some relief) that all
//     the different variations on Latin Modern Roman provide the same
//     set of glyphs so I only need a single map to describe multiple fonts.
// (5) The Latin Modern Fonts are covered by an instance of the LaTeX
//     Project Public License. That insists that any derived works provide
//     information on just how the derivation was conducted and how to
//     obtain the original files packed in the original manner. Their
//     terms are clearly envisaging alteration of the actual fonts, but
//     they insist that even re-packing fonts, using only a subset or
//     extracting information from the fonts leads to a derived work. So
//     the file that will be created by this is subject to limitations, and
//     I generate a comment in it that is intended to fulfill my obligations.
//     Note that this all means that anybody redistributing the font
//     coverage file other than in the context of the whole of CSL or Reduce
//     needs to check the license to bve certain that their usage is
//     permitted. I am perhaps sad about this extra complication, but believe
//     that in context it is acceptable.
// (6) The font "CMU Typewriter Text" is subject to an X11 license, and the
//     directory that contains the font includes a copy of the formal
//     statement of that and copyright attribution to Andrey V. Panov.
// (7) The Deja Vu font is subject to a permissive license also included
//     alongside the font itself. The key limitation is that modifications
//     of the font may not be made without altering the font name.
//     I am taking a view that for the fully permissive licenses that mere
//     coverage bitmaps do not need very much by way of embedded comment
//     and that they will only make sense when distributed alongside the
//     relevant fonts (which should always be accompanied by their
//     associated licenses).
//
// I want this table because I have not (yet?) found a way in wxWidgets where
// I can test if a codepoint is properly supported in the selected fond, but
// then when I render text I sometimes get a character from some quite
// different font appearing. With these tables I can take control of
// character/font substitution for myself.
//


#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[])
{   FILE *in, *out;
    char outname[80];
    char inputline[256];
    int z, i, n;
    char *p;
    uint32_t map[65536/32];
    out = fopen("coverage.cpp", "w");
    fprintf(out, "/* coverage.cpp                                 Copyright A C Norman 2015 */\n");
    fprintf(out, "\n");
    fprintf(out, "\n");
    fprintf(out, "/*\n");
    fprintf(out, " * Because this file contains information derived from fonts that are\n");
    fprintf(out, " * licensed under the LaTeX Project Public License it needs to adhere\n");
    fprintf(out, " * to the obligations set by that. The way in which information here is\n");
    fprintf(out, " * \"derived\" is that there are bitmaps showing which glyphs are present\n");
    fprintf(out, " * in various of the Latin Modern fonts. This was gathered by using\n");
    fprintf(out, " * a perl script to drive fontforge to extract a list of glyph codes\n");
    fprintf(out, " * and then packing the information as shown here. Thus the information here\n");
    fprintf(out, " * is not in any sense a replacement for any component of an existing\n");
    fprintf(out, " * iplementation of TeX. The original form of the files containing the\n");
    fprintf(out, " * fonts used are available via the sunversion repository associated\n");
    fprintf(out, " * with the project at reduce-algebra.sf.net, are are in the directory\n");
    fprintf(out, " * [trunk]/csl/support-packages. Various copies of README files, detailed\n");
    fprintf(out, " * license information and the like are also in the Reduce source file-set\n");
    fprintf(out, " * in csl/cslbase/wxfonts and in a binary version of the system in\n");
    fprintf(out, " * a directory called reduce.wxfonts (Windows and Linux) and within the\n");
    fprintf(out, " * Application Folder where fonts live for Macintosh.\n");
    fprintf(out, " */\n");
    fprintf(out, "\n/*\n");
    fprintf(out, " * Apart from the LaTeX Project Public License obligations, which you should\n");
    fprintf(out, " * check carefully, this file may be used as if under the BSD License applied\n");
    fprintf(out, " * elsewhere in the Reduce project.\n");
    fprintf(out, " */\n\n");
    fprintf(out, "/* $Id$ */\n");
    fprintf(out, "\n#include <stdint.h>\n\n");
    fprintf(out, "typedef struct _fontmap\n");
    fprintf(out, "{\n");
    fprintf(out, "    const char *name;\n");
    fprintf(out, "    uint32_t map[65536/32]; /* 2048 words */\n");
    fprintf(out, "} fontmap;\n");
    fprintf(out, "\n");
    fprintf(out, "fontmap coverage[] =\n");
    fprintf(out, "{\n");
    for (z=1; z<argc; z++)
    {   const char *fontname = argv[z];
        int charcount = 0;
        int warnings = 0;
        memset(map, 0, sizeof(map));
        strcpy(outname, fontname);
        p = strchr(outname, '.');
        *p = 0;
        fprintf(out, "  {\"%s\", {", strchr(outname, '/')+1);
        in = fopen(fontname, "r");
        for (;;)
        {   int c;
            for (n=0; n<sizeof(inputline)-1; n++)
            {   c = getc(in);
                if (c == '\n' || c == EOF) break;
                inputline[n] = c;
            }
            inputline[n] = 0;
            if (n != 0 && sscanf(inputline, "%d", &n) == 1)
            {   if (n > 0xffff)
                {   if (warnings++ < 10)
                        printf("code over 0xffff present and ignored\n");
                    continue;
                }
                map[n/32] |= 1U<<(n%32);
                charcount++;
            }
            if (c == EOF) break;
        }
        printf("Font %s had %d characters\n", outname, charcount);
#define WORDS (0x10000/32)
        for (i=0; i<WORDS; i++)
        {   if ((i % 6) == 0)
                fprintf(out, "\n   ");
            fprintf(out, " 0x%.8x", map[i]);
            if (i != (WORDS-1)) fprintf(out, ",");
        }
        fprintf(out, "}}");
        if (z != argc-1) fprintf(out, ",");
        fprintf(out, "\n");
        fclose(in);
    }
    fprintf(out, "};\n\n/* End of coverage.cpp */\n");
    fclose(out);
}

// End of glyphtable.cpp
