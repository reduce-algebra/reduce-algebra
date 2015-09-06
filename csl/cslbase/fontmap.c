 /* fontmap.c                           Copyright (C) 2015 Codemist Ltd */

#error DEFUNCT

// This has in effect been replaces by charmetrics.c...

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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* $Id$ */

/*
 * The table here maps from the font name (as to be used with wxWidgets
 * when opening the font) to the name of the file that will contain the
 * font as used in the "coverage.c" tables.
 * When openning at least certain of the fonts it is legal to add a
 * "Bold" or "Italic" qualifier.
 *
 * Note that at least for some of the fonts the names that must be used
 * for them are different as between Macintosh and Linux and Windows.
 */

const char *fontfilename[][2] =
{
#ifdef MACINTOSH
    {"CMU Typewriter Text Regular",   "cmuntt"},
    {"DejaVu Sans Mono",              "DejaVuSansMono"},
    {"AR PL New Sung",                "fireflysung"}
#else /* MAC */
    {"CMU Typewriter Text",           "cmuntt"},
    {"DejaVu Sans Mono",              "DejaVuSansMono"},
    {"AR PL New Sung",                "fireflysung"}
#endif /* MAC */
};

/*
 * coverage.c is an automatically generated file that contains bitmaps
 * that show what characters in the Basic Multilingual Plane are
 * available in each of the above fonts. It gets created by using
 * fontIgo.py to extract a list of glyphs from each font file and then
 * my own program (glyphtable.c) to pack this into a map.
 */

#include "coverage.c"

uint32_t *find_glyphmap(const char *name)
{
    unsigned int i, j;
    for (i=0; i<sizeof(fontfilename)/sizeof(fontfilename[0]); i++)
        if (strcmp(name, fontfilename[i][0]) == 0) break;
    if (i>=sizeof(fontfilename)/sizeof(fontfilename[0])) return NULL;
    for (j=0; j<sizeof(coverage)/sizeof(coverage[0]); j++)
        if (strcmp(fontfilename[i][1], coverage[j].name) == 0)
            return coverage[j].map;
    return NULL;
}

int char_present(int c, uint32_t *map)
{
/*
 * The treatment here must match that in glyphtable.c I take the view that
 * if anybody asks for a glyph with code over 0xffff then I will let the
 * system try for it. Each of the fonts I am using define some characters
 * with code points fairly close to 0xffff and so merely truncating the
 * tables to try to save space does not help, and what I have here is both
 * simple and fast. 
 */
    if (c >= 0x10000) return 1;
    return (map[c/32] >> (c%32)) & 1;
}

/* end of fontmap.c */
