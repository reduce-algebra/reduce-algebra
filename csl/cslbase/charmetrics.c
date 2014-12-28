// charmetrics.c                           Copyright (C) 2014 Codemist Ltd


// $Id: charmetrics.c 2688 2014-09-20 16:52:18Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2014, Codemist Ltd.                     A C Norman       *
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


// This takes a bunch of font information files and creates some C
// tables that can be used to access the information rapidly.

// Well if I compile this with -DCREATE=1 it makes a program that
// inspects the raw font metric and kerning files and creates a file
// called charmetrics.h containing a packed version of it. Otherwise it
// makes the code that inspects those tables and retrieves information.


// I have inspected the fonts that concern me and the sizes
// shown here will suffice. There are less than 32000 characters in
// total defined in all of the fonts I have (fireflysung is by far
// the biggest with over 17K characters defined). There are also less
// then 5000 kerning pairs listed. I will in fact have 31 distinct fonts.

// "wx -L" tells me that all my font-metric files have lines that are
// less than 750 characters long. The worst case is for the cmuntt font
// where thare are a large number of ligatures specified for "space"
// followed by various characters (that I believe are probably all the
// combining characters present, so that putting a space ahead of any of then
// can lead to a comversion to a non-combining variant.

// Having statically fixed limits here simplifies my coding.

#define MAXFONTS 32
#define MAXCHARS 32000
#define MAXKERNS 5000
#define MAXLIGATURES 100
#define MAXLINE  750

#ifdef CREATE
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#else // CREATE
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#else // TEST
#include "headers.h"
#endif // TEST

#include "charmetrics.h"  // A file I must have created earlier
#endif // CREATE

// The list of font codes here must be kept in step with the list
// of names in the table.

#define F_cmuntt                      0
#define F_General_Bold                1
#define F_General_BoldItalic          2
#define F_General_Italic              3
#define F_General                     4
#define F_IntegralsD_Bold             5
#define F_IntegralsD                  6
#define F_IntegralsSm_Bold            7
#define F_IntegralsSm                 8
#define F_IntegralsUp_Bold            9
#define F_IntegralsUpD_Bold           10
#define F_IntegralsUpD                11
#define F_IntegralsUp                 12
#define F_IntegralsUpSm_Bold          13
#define F_IntegralsUpSm               14
#define F_NonUnicode_Bold             15
#define F_NonUnicode_BoldItalic       16
#define F_NonUnicode_Italic           17
#define F_NonUnicode                  18
#define F_SizeFiveSym                 19
#define F_SizeFourSym_Bold            20
#define F_SizeFourSym                 21
#define F_SizeOneSym_Bold             22
#define F_SizeOneSym                  23
#define F_SizeThreeSym_Bold           24
#define F_SizeThreeSym                25
#define F_SizeTwoSym_Bold             26
#define F_SizeTwoSym                  27
#define F_Variants_Bold               28
#define F_Variants                    29
#define F_fireflysung                 30
#define F_end                         31

static const char *fontnames[] =
{
    "cmuntt",
    "STIXGeneral-Bold",
    "STIXGeneral-BoldItalic",
    "STIXGeneral-Italic",
    "STIXGeneral-Regular",
    "STIXIntegralsD-Bold",
    "STIXIntegralsD-Regular",
    "STIXIntegralsSm-Bold",
    "STIXIntegralsSm-Regular",
    "STIXIntegralsUp-Bold",
    "STIXIntegralsUpD-Bold",
    "STIXIntegralsUpD-Regular",
    "STIXIntegralsUp-Regular",
    "STIXIntegralsUpSm-Bold",
    "STIXIntegralsUpSm-Regular",
    "STIXNonUnicode-Bold",
    "STIXNonUnicode-BoldItalic",
    "STIXNonUnicode-Italic",
    "STIXNonUnicode-Regular",
    "STIXSizeFiveSym-Regular",
    "STIXSizeFourSym-Bold",
    "STIXSizeFourSym-Regular",
    "STIXSizeOneSym-Bold",
    "STIXSizeOneSym-Regular",
    "STIXSizeThreeSym-Bold",
    "STIXSizeThreeSym-Regular",
    "STIXSizeTwoSym-Bold",
    "STIXSizeTwoSym-Regular",
    "STIXVariants-Bold",
    "STIXVariants-Regular",
    "fireflysung",
    NULL
};

// The font metric information I use will be quite bulky, so I will be
// trying to balance speed, compactness and simplicity here.
// I will only need to support the 31 fonts listed above, so I will
// exploit some observed features. The first is that I only need to
// map U+000000 to U+01ffff and hence I can use just 17 bits to specify
// a code-point. Since I have (just) under than 32 fonts I can use 5 bits
// to indicate a font.
// However I only use a modest range of codes over 0xffff so I will map them
// onto otherwise unused codes (in these fonts) for the purposes of my
// tables. Because I am always carrying my font identifier it is only
// necessary to arrange to be clash-free within a single font. Whew.
// A conseqence will be that I can use just 16-bit "adjusted
// codepoints" and that plus 5 bits of font leaves me needed 21 bits.

static int pack_character(int font, int codepoint)
{
// The cases that apply here are
//    cmuntt    U+10144 - U+10147    map to U+d144 - U+d147
//              these would be Hangul syllables but same are not present
//              in cmuntt. The above are the only characters present in
//              cmuntt that have codes over U+ffff.
//    STIXGeneral-Regular and -Bold   U+1d400 - U+1d7ff to U+d400 - U+d7ff 
//              The first character present above U+ffff is U+1d400 and the
//              last is U+1d7f5. The region U+d400 to U+dfff  is not
//              populated.
//   All the other fints here seem to stick to the basic multilingual plane.
// If at any stage I added more fonts I would need to review this!
    if (codepoint >= 0x10000)
        codepoint = 0xd000 + (codepoint & 0xfff);
    return (font<<16) | codepoint; // A 21-bit code.
}

// I will store information in a hash table that puts four codepoints per
// "hash table line". Each hash table entry will involve five 64-bit words.
// The first will contain the key and some information to help with kerning
// and ligatures. Because I will have a line size of 4 I only need to use 19
// bits of key. That leaves me with space to put four 11-bit kern entries
// in, one for each of the 4 codepoints covered. There will be a 31-entry
// table indexed by font that gives a value to be added to one of these
// offsets. That allows for up to 1024 kern entried per font. I count 1016
// kern declarations and 16 ligature declarations for STIXGeneral-Regular
// and those together add up to 1032 which is over 1024. However I believe
// that the index I need just has to be to the first of a run of kerning
// information so I may JUST survice. Or JUST miss! However in desparation
// I can squeeze one extra bit of offset for every fourth codepoint, and if
// I arrange that that falls on the one that will end up last in the kern
// table I should end up OK!
//
// I assessed having individual entries is the hash table and line sizes
// of 2 and 8 as well as 4. A line size of 8 saves a small emount of space
// but at the cost of seeming noticably messier. A line size of only 2
// consumes distinctly more memory. //
// The other four 64-bit values each hold four 13-bit fields and one 12
// bit one. These store the character width and its bounding box. For my
// fonts I observe
//     0   <=   width   <=  3238        use 13 bits unsigned
//   -3000 <=   llx     <=  930         use 13 bits unsigned offset by -3000
//    -522 <=   lly     <=  820         use 12 bits unsigned offset by -1000
//    -234 <=   urx     <=  3472        use 13 bits unsigned offset by -500
//    -166 <=   ury     <=  2604        use 13 bits unsigned offset by -1000
// that packing is a bit ugly but ends up using exactly 64 bits which is
// really convenient.

// When a character starts a kern I have a 11 bit index value that gets added
// to a further value that depends on the font to give an offset into a table
// of 32-bit words. Each word contains
//    last item mark      1 bit set if this is the last item of
//                        kern information associated with the current
//                        lead character.
//    kern-or-ligature    1 bit flag set if this is ligature not kern data.
//    successor char      21-bit codepoint for a successor character. Note
//                        that this will always be in the same font. The
//                        codepoint is stored plain here with no compression
//                        or adjustment.
//    offset              for kerning this is a 9-bit signed adjustment
//                        to make the spacing. For a ligature it is a
//                        9 bit offset into a table of 21-bit codepoints
//                        for replacement characters. I only seem to see
//                        77 cases of ligatures in all so this final
//                        table is not too bulky.
// The kern information starts at offset 1 so that a kern index of zero can
// indicate no kerning is needed. If two leading characters had identical
// kerning information this would allow that to be shared. The range of
// kern adjustment I see in my fonts is -149 to 87, and so the 9-bit
// field I have (coping with -256 to +255) will suffice.
//
// For successful lookups the cost is best for items that were inserted
// into the table first. In this case I view it as an optimisation to put
// the large CJK font (fireflysung) in last. This should arrange that
// successful lookup of cmuntt and all the STIX fonts happens really
// rapidly - say in around 1.2 probes.


#ifdef CREATE

// In the official full list of Unicode names there are some remarkably
// long names used, of which maybe the worst is
//    "CLOCKWISE RIGHTWARDS AND LEFTWARDS OPEN CIRCLE ARROWS WITH
//     CIRCLED ONE OVERLAY"
// however the fonts I use here all have embedded names that are reasonably
// short. I would detect it if any were longer than 31 characters and stop.
// If that happened I would merely increase MAXUNILEN here. The names present
// while processing fonts here are purely local to the treatment here (they
// are used to link kerning tables).

#define MAXUNILEN 32

static int       charcount = 0;
static int       fontkey[MAXCHARS];
static int32_t   codepoint[MAXCHARS];
static int32_t   width[MAXCHARS];
static int32_t   llx[MAXCHARS];
static int32_t   lly[MAXCHARS];
static int32_t   urx[MAXCHARS];
static int32_t   ury[MAXCHARS];
static char      uninames[MAXCHARS][MAXUNILEN];

// For ligature information I will store the identity of the
// start character and then the names of the follower and the
// replacement.

static int       nligatures = 0;
static int       ligfont[MAXLIGATURES];
static int32_t   ligstart[MAXLIGATURES];
static char      ligfollow[MAXLIGATURES][MAXUNILEN];
static char      ligreplacement[MAXLIGATURES][MAXUNILEN];

// For kerning information I will store the identity of the
// start and follow characters and the integer adjustment to be made.

static int       nkerns = 0;
static int       kernfont[MAXKERNS];
static char      kernstart[MAXKERNS][MAXUNILEN];
static char      kernfollow[MAXKERNS][MAXUNILEN];
static int       kernadjustment[MAXKERNS];

static int kernp = 0;
static uint16_t fontkern[F_end];
static uint32_t kerntable[MAXKERNS];

// The hash table will end up holding information about around 32000
// characters. It is arranged in lines each of which store data on
// four characters, so assuming few isolated character codes that
// means it will use around 8000 entries. I make its size a prime.
// If I make it 10883 then my tables are fairly full so an unsuccessful
// lookup may involve a dozen probes, but each successful probe will
// cost an avarage of under 3 probes.
//

#define HASHTABLESIZE 10883

// This is around 400 Kbytes... I tend to count that as quite large.
// By far the largest contribution to it is data from fireflysung.afm.
// Although almost all characters there are specified with a width of 1000
// the character bounding boxes are all individual and varied, and so trying
// to save space by having an index of bounding boxes does not appear to be
// useful.

static uint64_t hashtable[HASHTABLESIZE][5];

static char      line[MAXLINE];
static char      saveline[MAXLINE];
static char      segment[MAXLINE];

int maxw=-10000, maxllx=-10000, maxlly=-10000, maxurx=-10000, maxury=-10000;
int minw=10000, minllx=10000, minlly=10000, minurx=10000, minury=10000;

int main(int argc, char *argv[])
{
    const char *f;
    int fontnum;
    char *p, *q;
    int relevant = 0;
    int kerndata = 0;
    FILE *src;
    char filename[100];
    int i, probes = 0, p1 = 0, p2 = 0, n1 = 0, n2 = 0, occupancy = 0;
    charcount = 0;
// I will map characters from u+000000 to u+01ffff but not beyond - that
// way I will only need 17 bits to specify a codepoint.
    for (fontnum=0; fontnum<F_end; fontnum++)
    {   f = fontnames[fontnum];
        printf("Process font %s\n", f);
        relevant = kerndata = 0;
        sprintf(filename, "wxfonts/metrics/%s.afm", f);
        if ((src = fopen(filename, "r")) == NULL)
        {   printf("Unable to access %s\n", filename);
            exit(EXIT_FAILURE);
        }
        nkerns = 0; // count kern info just within this font
        for (;;)
        {   int ia, ib, ic, id;
            int32_t cp, wid, bb1, bb2, bb3, bb4;
            char unn[MAXLINE], lig1[MAXLINE], lig2[MAXLINE];
            if (fgets(line, sizeof(line)-1, src) == NULL) break;
            ia = (int)strlen(line);
            if (ia > 0) line[ia-1] = 0; // discard final newline
            strcpy(saveline, line);
            if (strncmp(line, "StartCharMetrics", 16) == 0)
            {   relevant = 1;
                continue;
            }
            if (strncmp(line, "EndCharMetrics", 14) == 0)
            {   relevant = 0;
                continue;
            }
            if (strncmp(line, "StartKernPairs", 14) == 0)
            {   kerndata = 1;
                continue;
            }
            if (strncmp(line, "EndKernPairs", 12) == 0)
            {   kerndata = 0;
                continue;
            }
            if (kerndata)
            {   if (sscanf(line, "KPX %s %s %d", lig1, lig2, &ia) == 3)
                {   kernfont[nkerns] = fontnum;
                    strcpy(kernstart[nkerns], lig1);
                    strcpy(kernfollow[nkerns], lig2);
                    kernadjustment[nkerns] = ia;
                    nkerns++;
                }
                else
                {   printf("Dubious kerning data %s\n", line);
                    continue;
                }
                continue;
            }
            if (relevant == 0) continue;
// Now line contains character information. This may include
//     C nnn            decimal code point
//     WX xxx           hexacedimal width
//     N word           unicode character name, needed for kern tables
//     B nn nn nn nn    character bounding box
//     L word word      ligature specification
// with each of these separated by a semicolon.
            p = line;
            while (p != NULL)
            {   q = strchr(p, ';');
                if (q != NULL) *q = 0;
// Process segment starting at p
                while (*p == ' ' || *p == '\n' || *p == '\r') p++;
                if (*p == 0) break; // empty segment
                switch (*p)
                {
                case 'C':
                    if (sscanf(p, "C %d", &ia) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    cp = ia;
                    break;
                case 'W':
                    if (sscanf(p, "WX %d", &ia) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    wid = ia;
                    if (wid > maxw) maxw = wid;
                    if (wid < minw) minw = wid;
                    break;
                case 'N':
                    if (sscanf(p, "N %s", unn) != 1)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    if (strlen(unn) >= MAXUNILEN)
                    {   printf("Unicode name length = %d\n", (int)strlen(unn));
                        exit(EXIT_FAILURE);
                    }
                    if (cp == -1)
                    {   if (sscanf(unn, "u%x", &ia) == 1) cp = ia;
                        else if (strcmp(unn, ".notdef") != 0)
                            printf("Dodgy character: %s\n", saveline);
                    }
                    break;
                case 'B':
                    if (sscanf(p, "B %d %d %d %d", &ia, &ib, &ic, &id) != 4)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    bb1 = ia; bb2 = ib; bb3 = ic; bb4 = id;
                    if (bb1 > maxllx) maxllx = bb1;
                    if (bb1 < minllx) minllx = bb1;
                    if (bb2 > maxlly) maxlly = bb2;
                    if (bb2 < minlly) minlly = bb2;
                    if (bb3 > maxurx) maxurx = bb3;
                    if (bb3 < minurx) minurx = bb3;
                    if (bb4 > maxury) maxury = bb4;
                    if (bb4 < minury) minury = bb4;
                    break;
                case 'L':
// All I can do with ligature information on a first pass is to record
// it rather literally. That is because it may contain forward references
// to character names.
                    if (sscanf(p, "L %s %s", lig1, lig2) != 2)
                    {   printf("Bad segment \"%s\" in .afm file\n", p);
                        exit(EXIT_FAILURE);
                    }
                    ligfont[nligatures] = fontnum;
                    ligstart[nligatures] = cp;
                    strcpy(ligfollow[nligatures], lig1);
                    strcpy(ligreplacement[nligatures], lig2);
                    nligatures++;
                    break;
                case 0:
                    break;
                default:
                    printf("Unknown segment \"%s\" in .afm file\n", p);
                    printf("Input line: \"%s\"\n", saveline);
                    exit(EXIT_FAILURE);
                }
                if (q == NULL) break;
                else p = q+1;
            }
// The information I now have is
// fontnum, cp                          key
// wid, bb1, bb2, bb3, bb4, unn         data
            if (cp == -1) continue;
            if (cp < 0 || cp > 0x01ffff)
            {   printf("Discarding character with codepoint %d\n", cp);
                continue;
            }
            if (cp >= 0xd000 && cp < 0xe000)
                printf("Codepoint %d %x noted\n", cp, cp);
            if (cp > 0xffff &&
                !(cp >= 0x1d000 && cp < 0x1e000))
                printf("Codepoint %d %x noted\n", cp, cp);
            fontkey[charcount] = fontnum;
            codepoint[charcount] = cp;
            width[charcount] = wid;
            llx[charcount] = bb1;
            lly[charcount] = bb2;
            urx[charcount] = bb3;
            ury[charcount] = bb4;
            charcount++;
        }
        fclose(src);
    }
// Start to move kern information...
    fontkern[fontnum] = kernp;
// Now I have read everything. I should now transfer information from the
// raw tables it is in at present into the hash table I want it to end up in.
    for (i=0; i<HASHTABLESIZE; i++)
    {   int j;
        for (j=0; j<10; j++) hashtable[i][j] = 0;
    }
    for (i=0; i<charcount; i++)
    {   int fullkey = pack_character(fontkey[i], codepoint[i]); // 21-bit key
        int key = fullkey >> 2; // because my hash table has line-size 4
// I compute two hash values - one for the initial probe position and
// the second to give an stride,
        int j, v, h1, h2;
        uint64_t w;
        h1 = (uint32_t)(1103515245*key) % (uint32_t)HASHTABLESIZE;
        h2 = 1+(uint32_t)(169*key) % (uint32_t)(HASHTABLESIZE-1);
        if (h1 < 0 || h1 >= HASHTABLESIZE ||
            h2 <= 0 || h2 >= HASHTABLESIZE)
        {   printf("Hash calculation failed %d %d\n", h1, h2);
            exit(1);
        }
        for (;;)
        {   v = (int)hashtable[h1][0] & 0x7ffff;
            probes++;
            if (probes > 1000000)
            {   printf("Excessive probe count %d %d\n", h1, h2);
                printf("i = %d\n", i);
                exit(1);
            }
            if (v == 0 || v == key) break;
            h1 += h2;
            if (h1 >= HASHTABLESIZE) h1 -= HASHTABLESIZE;
        }
        if (v == 0)
        {   occupancy++;
            if (occupancy > HASHTABLESIZE-10)
            {   printf("Excessive occupancy %d %d\n", h1, h2);
                printf("i = %d\n", i);
                printf("%d of %d lines used\n", occupancy, HASHTABLESIZE);
                exit(1);
            }
            hashtable[h1][0] = key;
        }
// Pack and write in the messy information about width and bounding boxes.
        w = ((uint64_t)width[i] & 0x1fff) << 51 |
            ((uint64_t)(llx[i]+3000) & 0x1fff) << 38 |
            ((uint64_t)(lly[i]+1000) & 0x0fff) << 26 |
            ((uint64_t)(urx[i]+500) & 0x1fff) << 13 |
            ((uint64_t)(ury[i]+1000) & 0x1fff);
        hashtable[h1][1+(fullkey&3)] = w;
// Here I must put the kern and ligature table offsets. I need to scan the
// kern table for ones that match the current startchar...
        for (j=0; j<nkerns; j++)
        {   if (strcmp(kernstart[j], uninames[i]) == 0)
            {   int k;
                printf("Found kern info following %d\n", codepoint[i]);
                for (k=0; k<charcount; k++)
                {   if (fontkey[k] == fontnum &&
                        strcmp(kernfollow[j], uninames[k]) == 0)
                    {   printf("Found complete kern\n");
// Must patch hash0[h1] here...
                        kerntable[kernp++] =
                              codepoint[k] | (kernadjustment[j]<<21);
                    }
                }
            }
        }
    }

    printf("Done after %d characters, %d ligatures, %d kerns\n",
           charcount, nligatures, nkerns);
    printf("width %d %d (%d)\n", minw, maxw, maxw-minw);
    printf("llx %d %d (%d)\n", minllx, maxllx, maxllx-minllx);
    printf("lly %d %d (%d)\n", minlly, maxlly, maxlly-minlly);
    printf("urx %d %d (%d)\n", minurx, maxurx, maxurx-minurx);
    printf("ury %d %d (%d)\n", minury, maxury, maxury-minury);
    printf("Hash probes = %d [occupancy = %d, average = %.2f]\n", probes,
           occupancy, (double)probes/(double)charcount);

// Assess hash table performance
    probes = 0;
    for (i=0; i<=0x7ffff; i++)
    {   int v;
        int h1 = (uint32_t)(1103515245*i) % (uint32_t)HASHTABLESIZE;
        int h2 = 1+(uint32_t)(169*i) % (uint32_t)(HASHTABLESIZE-1);
        if (h1 < 0 || h1 >= HASHTABLESIZE ||
            h2 <= 0 || h2 >= HASHTABLESIZE)
        {   printf("Hash calculation failed %d %d\n", h1, h2);
            exit(1);
        }
        probes = 0;
        for (;;)
        {   v = (int)hashtable[h1][0] & 0x7ffff;
            probes++;
            if (probes > 1000)
            {   printf("Excessive probe count %d %d\n", h1, h2);
                printf("i = %d\n", i);
                exit(1);
            }
            if (v == 0 || v == i) break;
            h1 = (h1 + h2) % HASHTABLESIZE;
        }
        if (v == 0)
        {   p1 += probes;
            n1++;
        }
        else
        {   p2 += probes;
            n2++;
        }
    }
    printf("Average unsucessful probe count overall = %.2f\n",
           (double)p1/(double)n1);
    printf("Average sucessful probe count overall = %.2f\n",
           (double)p2/(double)n2);
    printf("Total space = %d\n", HASHTABLESIZE*(5*8));
    {   FILE *dest = fopen("charmetrics.h", "w");
fprintf(dest, "// charmetrics.h                           Copyright (C) 2014 Codemist Ltd\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "// $ Id: $\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "/**************************************************************************\n");
fprintf(dest, " * Copyright (C) 2014, Codemist Ltd.                     A C Norman       *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " * Redistribution and use in source and binary forms, with or without     *\n");
fprintf(dest, " * modification, are permitted provided that the following conditions are *\n");
fprintf(dest, " * met:                                                                   *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " *     * Redistributions of source code must retain the relevant          *\n");
fprintf(dest, " *       copyright notice, this list of conditions and the following      *\n");
fprintf(dest, " *       disclaimer.                                                      *\n");
fprintf(dest, " *     * Redistributions in binary form must reproduce the above          *\n");
fprintf(dest, " *       copyright notice, this list of conditions and the following      *\n");
fprintf(dest, " *       disclaimer in the documentation and/or other materials provided  *\n");
fprintf(dest, " *       with the distribution.                                           *\n");
fprintf(dest, " *                                                                        *\n");
fprintf(dest, " * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *\n");
fprintf(dest, " * \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *\n");
fprintf(dest, " * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *\n");
fprintf(dest, " * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *\n");
fprintf(dest, " * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *\n");
fprintf(dest, " * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *\n");
fprintf(dest, " * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *\n");
fprintf(dest, " * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *\n");
fprintf(dest, " * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *\n");
fprintf(dest, " * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *\n");
fprintf(dest, " * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *\n");
fprintf(dest, " * DAMAGE.                                                                *\n");
fprintf(dest, " *************************************************************************/\n");
fprintf(dest, "\n");
fprintf(dest, "// Character metric hash table created using the program charmetrics.c\n");
fprintf(dest, "\n");
        fprintf(dest, "const uint64_t charmetrics[%d][5] = \n{", HASHTABLESIZE);
        for (i=0; i<HASHTABLESIZE; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest,
                "\n    {0x%.16" PRIx64 ", 0x%.16" PRIx64 ", 0x%.16" PRIx64 ","
                "\n                         0x%.16" PRIx64 ", 0x%.16" PRIx64 "}",
                hashtable[i][0],
                hashtable[i][1], hashtable[i][2],
                hashtable[i][3], hashtable[i][4]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "const uint16_t fontkern[] = \n{");
        for (i=0; i<F_end; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest, "\n    0x%.4x", fontkern[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "const uint32_t kerntable[] = \n{");
        for (i=0; i<kernp; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest, "\n    0x%.8" PRIx32, kerntable[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "const uint32_t ligaturetable[] = \n{");
        for (i=0; i<kernp; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest, "\n    0x%.8" PRIx32, kerntable[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "// end of charmetrics.h\n");
        fclose(dest);
    }
    return 0;
}

#else // CREATE
//
// I am putting the code that decodes and accesses metric information
// in the same file as the program that reads raw ".afm" files and
// packs the information for me. I hope that this keeps coding and decoding
// together so they will remian in step.
//

// lookupchar takes a font and a codepoint and returns true if there is
// information about the character and false if not. If it returns true
// it will have left information about the character in a number of
// variables that can then be inspected.

#define HASHTABLESIZE (sizeof(charmetrics)/sizeof(charmetrics[0]))

int c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo;

int lookupchar(int fontnum, int codepoint)
{
    int fullkey = pack_character(fontnum, codepoint); // 21-bit key
    int key = fullkey >> 2; // because my hash table has line-size 4
// I compute two hash values - one for the initial probe position and
// the second to give an stride,
    int v, h1, h2;
    uint64_t w;
    h1 = (uint32_t)(1103515245*key) % (uint32_t)HASHTABLESIZE;
    h2 = 1+(uint32_t)(169*key) % (uint32_t)(HASHTABLESIZE-1);
// On a successful search this will take an average of around 1.2 probes for
// the Western fonts and maybe 2.5 probes for the CJK font. Unsuccessful
// searches will need on average around 12 probes.
    for (;;)
    {   v = (int)charmetrics[h1][0] & 0x7ffff;
        if (v == key) break;
        if (v == 0) return 0; // Not found
// Here I judge that modern high performance computers will use branch
// prediction to arrange that the conditional here is almost free, while
// older ones would have had slow division/remainder hardware, and so
// the alternative code     h1 = (h1 + h2) % HASHTABLESIZE;    is pretty
// well never to be preferred.
        h1 += h2;
        if (h1 >= HASHTABLESIZE) h1 -= HASHTABLESIZE;
    }
    w = charmetrics[h1][1+(fullkey&3)];
    c_width = (int)(w >> 51) & 0x1fff;
    c_llx = ((int)(w >> 38) & 0x1fff) - 3000;
    c_lly = ((int)(w >> 26) & 0x0fff) - 1000;
    c_urx = ((int)(w >> 13) & 0x1fff) - 500;
    c_ury = ((int)w & 0x1fff) - 1000;
// Based on the font and 11 bits of information from the hash table I will
// set up a pointer into kerntable. The interpretation of that will be
// considered in the function lookupkerninfo. If the 11 bit field contains
// zero then there is neither kern nor ligature information associated
// with this character.
    v = (int)(w >> (19+11*(fullkey&3))) & 0x7ff;
    if (v != 0) v += fontkern[fontnum];
// c_kerninfo will be left zero if there is no information, otherwise an
// index into a table.
    c_kerninfo = v;
    return 1;
}

// Having looked up a single character I may now need to check for
// ligature or kerning information. I will do that by passing the
// codepoint of the successor character (which must be in the same
// font). Thus the complete sequence will be
//      lookupchar(font_number, codepoint_for_first_character);
//      lookupkerninfo)codepoint_for_second_character);
// This returns an int32_t where the bottom 21 bits are a codepoint for
// a character that can replace the two that were specified. For instance
// this can return a single ligature "fi" is the two input codepoints are
// for "f" and "i", or it could return first "ff" for two "f" characters
// that are adjacent, and then "ffi" for the resulting "ff" if followed
// by "i". Those bits will be returned as zero if no ligature is available
// (and that will almost always be the case).
// The top 9 bits of the 32-bit word will be a signed value for a
// kerning adjustment to the spacing between a pair of characters, relative
// to 1000 as the notional height of the character cell. This is again
// 0 if no adjustment is called for. As one of the more extreme examples,
// in one font if an "A" is followed by a "V" the space between them can be
// decreased by 109 units, while when a "T" is followed by a "W" an extra
// 41 units (and perhaps less obviously an "L" followd by "-" (hyphen)
// calls for even more extra space than that.

#define IS_LIGATURE 0x00200000
#define IS_BLOCKEND 0x00400000

int32_t lookupkerninfo(int codepoint)
{
    int32_t r = 0;
    uint32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
// The worst cases I can see in my fonts is the kern information for "W"
// in STIXGeneral where around 50 characters following "W" get their spacing
// adjusted. That gives some impression of the most extreme number of
// times this loop will be traversed. For many characters there will be no
// kern information at all, and when there is any it will usually be
// pretty limited so average costs here should end up low.
    do
    {   w = kerntable[i];
// The kern table contains a sequence of 32-bit words. The low 21 bits of
// each is a codepoint being the second character of a pair. The next two
// bits are flags. One indicates whether the word is documenting kern or
// ligature information. The other marks the final word of information
// relating to a lead character. That leaves 9 bits. For kern information
// that is a 9-bit signed spacing adjustment. For ligatures it is a
// 9 bit unsigned index into a table of codepoints giving the single
// character to be used to replace the initial pair.
        if ((w & 0x001fffff) == codepoint)
        {   if ((w & IS_LIGATURE) != 0) r |= ligaturetable[w >> 23];
            else r |= (w & 0xff800000);
        }
    } while ((w & IS_BLOCKEND) == 0);
    return r;
}

#ifdef TEST
// If TEST is defined then this code will try some very minimal tests.
// Expected output is
//
//   Hash table size was 10883
//   "e": width 444   BB 25 -10 424 460
//   "f": width 333   BB 20 0 383 683
//   "g": width 500   BB 28 -218 470 460
//   "h": width 500   BB 9 0 487 683
//   "i": width 278   BB 16 0 253 683
//   "j": width 278   BB -70 -218 194 683
//   "k": width 500   BB 7 0 505 683
//   "l": width 278   BB 19 0 257 683
//   "m": width 778   BB 16 0 775 460
//

int main(int argc, char *argv[])
{
    int i;
    printf("Hash table size was %d\n", HASHTABLESIZE);
    for (i='e'; i<'n'; i++)
    {   lookupchar(F_General, i);
        printf("\"%c\": width %d   BB %d %d %d %d\n",
               i, c_width, c_llx, c_lly, c_urx, c_ury);
    }
    return 0;
}


#endif // TEST
#endif // CREATE

// end of charmetrics.c
