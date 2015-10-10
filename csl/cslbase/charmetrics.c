// charmetrics.c                           Copyright (C) 2015 Codemist Ltd

//=======================================================================//
//                                                                       //
//  WARNING. In "-DCREATE=1" mode this program takes about 40 minutes    //
//  of CPU time on a computer that in 2015 counts as fairly fast. So     //
//  when you run it be prepared to be reasonably patient. The slow run   //
//  really only needed to be done once to extract font information from  //
//  a collection of ".afm" files and form it into a compact table, so it //
//  should only need to be run if the fonts being used change.           //
//                                                                       //
//=======================================================================//


// $Id$


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


#ifdef CREATE
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

// This takes a bunch of font information files and creates some C
// tables that can be used to access the information rapidly.

// Well if I compile this with -DCREATE=1 it makes a program that
// inspects the raw font metric and kerning files and creates a file
// called charmetrics.h containing a packed version of it. Otherwise it
// makes the code that inspects those tables and retrieves information.
// The "raw" input files are in ".afm" (Adobe Font Metric) format and
// the ones I use here were created from some .otf and .ttf font files
// using fontforge. The fonts I start from have generous licenses that
// permit re-distribution and so even more so I will hold that the
// file generated here that contains metrics is not subject to any
// severe limits on its use.

// I need my cuckoo-hashing library. One sane thing to do would be to
// link to that as a separately compiled component, but here I will just
// include its source! See cuckoo.h and cuckoo.c for commantary and
// explanation.

#include "cuckoo.c"

// I also generate a charmetrics.red that can give access to the same
// information from within Reduce... I am considering use from Java as well
// but somewhat amazingly Java deals with statically initialised arrays
// in a way that puts limits on their size such as to BREAK this - and
// so with a naive conversion I get both a "code too large" and a
// "too many constants" error from the Java compiler. The first of these
// persists even if I split the main hash table to give just one
// column at a time - so an initialised array of 10000 simple long values
// more than Java is willing to support. Thus any Java code will need to
// load metric information from a resource, and I think that C code that
// uses the charmetrics.h file as created here can be used to create the
// data that will be loaded. Ugh.

// I have inspected the fonts that concern me and the sizes
// shown here will suffice. There are less than 32000 characters in
// total defined in all of the fonts I have (odokai is by far
// the biggest with over 17K characters defined). There are also less
// then 5000 kerning pairs listed. I will in fact have 7 distinct fonts.

// The code to create the font data tables is very careless and would
// be thoroughly succeptible to all sorts of bad effects from buffer overflow
// if it were ever to be fed font files other than the ones distributed with
// it. Here I follow a path of fixed and unchecked size limits in a search
// for code simplicity in a utility I only intend for use in a single
// context. But anybody minded to add extra fonts MUST be aware and should
// check all the limits before running anything.

// My code here is also not especially tidy, and it uses C-99 style "//"
// comments (as here!) and <stdint.h> with uint64_t, UINT64_C() and their
// friends. In fact gcc has supported both of these for some time now and
// since this is a run-once sort of program I feel I can rely on using
// either a tolerably recent gcc or some other C compiler that supports
// C-99.

// The slowest part of the code here is finding a good hawsh regime
// to obtain good occupancy for the main character metrics table.
// Telling the code where to look can help speed it up. But of you
// have changed things then please predefine CONSERVATIVE to do a
// broad search.

#ifdef CONSERVATIVE
#define MAIN_LOW        (mainkeycount-1)
#define MAIN_HIGH       (sizeof(hashtable)/sizeof(hashtable[0]))
#else
// The values here are tolerably close to the expected best answer!
#define MAIN_LOW        10056
#define MAIN_HIGH       10173
#endif


// "wc -L" tells me that all my font-metric files have lines that are
// less than 1750 characters long. The worst case is for the cmuntt font
// where thare are a large number of ligatures specified for "space"
// followed by various characters (that I believe are probably all the
// combining characters present, so that putting a space ahead of any of them
// can lead to a comversion to a non-combining variant.

// Having statically fixed limits here simplifies my coding.

#define MAXFONTS 16
#define MAXCHARS 50000
#define MAXKERNS 10000
#define MAXLIGATURES 1000
#define MAXLINE  2000
#define MAXMATHSYMS 200

#else // CREATE
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "cuckoo.h"
#else // TEST
#include "headers.h"
#include "cuckoo.h"
#endif // TEST

#include "charmetrics.h"  // A file I must have created earlier
#endif // CREATE

#define IS_LIGATURE 0x00200000
#define IS_BLOCKEND 0x00400000

// The list of font codes here must be kept in step with the list
// of names in the table.

#define F_cmuntt                      0
#define F_odokai                      1
#define F_Regular                     2
#define F_Bold                        3
#define F_Italic                      4
#define F_BoldItalic                  5
#define F_Math                        6
#define F_end                         7

// In the ".afm" files and hence the main metrics I work with each
// character is measured and positioned relative to a base-line. However
// when wxWidgets draws things it uses the top left corner of a bounding
// box for text as its reference point. However the "bounding box" used
// does not seem to be related to any information I can find in the .afm
// file so I file values by running a wxWidgets program and seeing what
// it reports and put in a table of values here...

// To re-calculate these values you could check out a current of
// Reduce, configure "--with-csl --with-wx", make wxshowmath and run
// wxshowmath on wxdata/fontsizes.dat. The trace output should include
//....        Need to process CMU Typewriter Text
//....        Gives CMU Typewriter Text with flags 0
//....        font[0] = "CMU Typewriter Text" size 10000
//....        ( CMU Typewriter Text/10000: 12597.7 2330 [10267.7]
//....            1027,           // cmuntt
//....        from table baseline offset = 10270
//....        convert odokai
//....        Need to process AR PL New Kai
//....        Gives AR PL New Kai with flags 10000
//....        font[1] = "AR PL New Kai" size 10000
//....        ( AR Pl New Kai/10000: 10693.4 1210.94 [9482.42]
//....            1055,           // odokai
// and I extracted the information I need here using
//    grep "    // " wxshowmath.log > DESTINATION
// I edited the file to remove a comma after the final entry...
// (revisions much before then may not display the relevant
// information - ones significantly after may have removed the trace
// output...).


// I note with some distress that the adjustments needed here differ
// across operating systems. That backs up the fact that this data can not
// be deduced from a set of Adobe Font Metrics.
//
// So I provide three versions of this table (it is not very large) and
// a tolerably cheap run-time test can pick which one to use. I feel it is
// nicer for my runtime code to check no more than 3 cases to choose between
// these tables rather than getting it to measure all the fonts.
//
// With cslSTIX it seems that the X11 and OS/X measurements match - but
// I will nevertheless provide three versions here just in a spirit of
// caution. 

const uint16_t *chardepth = NULL;

const uint16_t chardepth_WIN32[] =
{
    1027,           // cmuntt
    948,            // odokai
    1023,           // Regular
    1023,           // Bold
    1023,           // Italic
    1023,           // BoldItalic
    2566            // Math
};

const uint16_t chardepth_X11[] =
{
    1027,           // cmuntt
    885,            // odokai
    1023,           // Regular
    1055,           // Bold
    1023,           // Italic
    1004,           // BoldItalic
    2566            // Math
};

const uint16_t chardepth_OSX[] =
{
    1027,           // cmuntt
    885,            // odokai
    1023,           // Regular
    1055,           // Bold
    1023,           // Italic
    1004,           // BoldItalic
    2566,           // Math
};

const char *fontnames[31] =
{
    "cmuntt",
    "odokai",
    "cslSTIX-Regular",
    "cslSTIX-Bold",
    "cslSTIX-Italic",
    "cslSTIX-BoldItalic",
    "cslSTIXMath-Regular"
};

// The font metric information I use will be quite bulky, so I will be
// trying to balance speed, compactness and simplicity here.
// I will only need to support the fonts listed above, so I will
// exploit some observed features. The first is that cmuntt and odokai
// (almost)  only use the Basic Multilingual Plane (ie U+0000 to U+FFFF).
// The STIX fonts use nothing in the range U+4000 to U+A000. But then
// STIXMath uses code in the range U+1D400 to U+1D800 and U+108000 to
// U+108400.
// The other STIX fonts have subsets of the same use. So there I will map
// U+1Dxxx to U+4xxx and U+108xxx to U+5xxx, having mapped anthing in either
// of those ranges to the illegal code U+FFFF. That leaves all codes as
// just 16 bits.
// Since I have under than 8 fonts I can use 3 bits to indicate a font.
// and the squashed 16-bit "remapped codepoint" plus 3 bits of font leaves
// me needing 19 bits in all.
// My hash table format could cope even if I needed up to 21-bits of
// full key... so I have some slack available if needed (eg if I wanted to
// support more fonts).

static int pack_character(int font, int codepoint)
{
// The cases that apply here are
//    cmuntt    U+10144 - U+10147
//              The above are the only characters present in
//              cmuntt that have codes over U+ffff.
//    cslSTIX*  U+1d4xxx to U+4xxx
//              U+108xxx to U+5xxx
    if (font < 2)
    {   if ((codepoint & 0xd800) == 0xd800) codepoint = 0xffff;
        else if (codepoint >= 0x10000)
        {   if (codepoint <= 0x107ff) codepoint = 0xd800 + (codepoint & 0x7ff);
            else codepoint = 0xffff;
        }
    }
    else if (codepoint >= 0x4000 && codepoint < 0x8000) codepoint = 0xffff;
    else if (codepoint >= 0x1d000 && codepoint <= 0x1dfff)
        codepoint = 0x4000 + (codepoint & 0xfff);
    else if (codepoint >= 0x108000 && codepoint <= 0x108fff)
        codepoint = 0x5000 + (codepoint & 0xfff);
    else if (codepoint >= 0x10000) codepoint = 0xffff;
// I need the bottom two bits of this packed code to be the bottom
// two bits of the codepoint because my hash table will be using
// buckets of four adjacent codepoints.
    return (font << 16) | codepoint;
}

// I will store information in a hash table that puts four codepoints per
// "hash table line". Each hash table entry will involve five 64-bit words.
// The first will contain the key and some information to help with kerning
// and ligatures. Because I will have a line size of 4 I only need to use 19
// bits of key. That leaves me with space to put four 11-bit kern entries
// in, one for each of the 4 codepoints covered. There will be a 16-entry
// table indexed by font that gives a value to be added to one of these
// offsets. That allows for up to 2048 kern entries per font. I count 1016
// kern declarations and 16 ligature declarations for STIX-Regular
// and those together add up to 1032 which fits reasonably.
//
// I assessed having individual entries is the hash table and line sizes
// of 2 and 8 as well as 4. A line size of 8 saves a small amount of space
// but at the cost of seeming noticably messier. A line size of only 2
// consumes distinctly more memory.
//
// The other four 64-bit values each hold four 13-bit fields and one 12
// bit one. These store the character width and its bounding box. For my
// fonts I observe
//     0   <=   width   <=  3238        use 13 bits unsigned
//    -998 <=   llx     <=  929         use 13 bits unsigned offset by -3000
//    -524 <=   lly     <=  843         use *12* bits unsigned offset by -1000
//    -234 <=   urx     <=  3238        use 13 bits unsigned offset by -500
//    -141 <=   ury     <=  1055        use 13 bits unsigned offset by -1000
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
// The kern index values atart at 1 so that a kern index of zero can
// indicate no kerning is needed. The range of kern adjustment I see in my
// fonts is -149 to 87, and so the 9-bit field I have (coping with -256 to
// +255) will suffice comfortably.
//

#ifdef CREATE

// In the official full list of Unicode names there are some remarkably
// long names used, of which maybe the worst is
//    "CLOCKWISE RIGHTWARDS AND LEFTWARDS OPEN CIRCLE ARROWS WITH
//     CIRCLED ONE OVERLAY"
// however the fonts I use here all have embedded names that are reasonably
// short. I would detect it if any were longer than 120 characters and stop.
// If that happened I would merely increase MAXUNILEN here. The names present
// while processing fonts here are purely local to the treatment here (they
// are used to link kerning tables).

#define MAXUNILEN 120

static int       charcount = 0;
static int       fontkey[MAXCHARS];
static int32_t   codepoint[MAXCHARS];
static int       mainkeycount;
static uint32_t  mainkey[MAXCHARS];
static int32_t   width[MAXCHARS];
static int32_t   llx[MAXCHARS];
static int32_t   lly[MAXCHARS];
static int32_t   urx[MAXCHARS];
static int32_t   ury[MAXCHARS];
static char      uninames[MAXCHARS][MAXUNILEN];
static int       kernreference[MAXCHARS];

// For ligature information I will store the identity of the
// start character and then the names of the follower and the
// replacement.

static int       nligatures = 0;
static int       ligfont[MAXLIGATURES];
static int32_t   ligstart[MAXLIGATURES];
static char      ligfollow[MAXLIGATURES][MAXUNILEN];
static char      ligreplacement[MAXLIGATURES][MAXUNILEN];
static int32_t   ligfollowcode[MAXLIGATURES];
static int32_t   ligreplacementcode[MAXLIGATURES];

// For kerning information I will store the identity of the
// start and follow characters and the integer adjustment to be made.

static int       nkerns = 0;
static int       kernfont[MAXKERNS];
static char      kernstart[MAXKERNS][MAXUNILEN];
static char      kernfollow[MAXKERNS][MAXUNILEN];
static int       kernadjustment[MAXKERNS];
static int32_t   kernstartcode[MAXKERNS];
static int32_t   kernfollowcode[MAXKERNS];

static int kernp = 0;
static int16_t  fontkern[F_end];
static uint32_t kerntable[MAXKERNS];
static char     ktstart[MAXKERNS][MAXUNILEN];
static char     ktfollow[MAXKERNS][MAXUNILEN];
static int      ktadjustment[MAXKERNS];
static char     ktfont[MAXKERNS][32];
static int      ktfontn[MAXKERNS];

static int ligp = 0;
static uint32_t ligtable[MAXLIGATURES];
static char ltfirst[MAXLIGATURES][MAXUNILEN],
            ltfollow[MAXLIGATURES][MAXUNILEN],
            ltname[MAXLIGATURES][MAXUNILEN],
            ltfont[MAXLIGATURES][32];

static int accentp = 0;
static char accentname[MAXMATHSYMS][MAXUNILEN];
static uint32_t accentnum[MAXMATHSYMS];
static int32_t  accentval[MAXMATHSYMS];

static int variantp = 0;
static int variantdirection[MAXMATHSYMS];
static char variantname[MAXMATHSYMS][MAXUNILEN];
static char v1[MAXMATHSYMS][MAXUNILEN]; // size 1 (just bigger than basic)
static char v2[MAXMATHSYMS][MAXUNILEN]; // size 2
static char v3[MAXMATHSYMS][MAXUNILEN]; // size 3
static char v4[MAXMATHSYMS][MAXUNILEN]; // size 4
static char v5[MAXMATHSYMS][MAXUNILEN]; // size 5 (biggest)
static char P1[MAXMATHSYMS][MAXUNILEN]; // top        top        top
static char P2[MAXMATHSYMS][MAXUNILEN]; // extension  extension  extension
static char P3[MAXMATHSYMS][MAXUNILEN]; // middle     bottom
static char P4[MAXMATHSYMS][MAXUNILEN]; // extension
static char P5[MAXMATHSYMS][MAXUNILEN]; // bottom
// Now the same converted to codepoints rather than names.
static int32_t variantcode[MAXMATHSYMS];
static int32_t nv1[MAXMATHSYMS]; // size 1 (just bigger than basic)
static int32_t nv2[MAXMATHSYMS]; // size 2
static int32_t nv3[MAXMATHSYMS]; // size 3
static int32_t nv4[MAXMATHSYMS]; // size 4
static int32_t nv5[MAXMATHSYMS]; // size 5 (biggest)
static int32_t np1[MAXMATHSYMS]; // top        top        top
static int32_t np2[MAXMATHSYMS]; // extension  extension  extension
static int32_t np3[MAXMATHSYMS]; // middle     bottom
static int32_t np4[MAXMATHSYMS]; // extension
static int32_t np5[MAXMATHSYMS]; // bottom
static int vdata1[MAXMATHSYMS][4];   // start end full flag
static int vdata2[MAXMATHSYMS][4];
static int vdata3[MAXMATHSYMS][4];
static int vdata4[MAXMATHSYMS][4];
static int vdata5[MAXMATHSYMS][4];


// It will be necessary at times to look up a name given its name. I will do
// that with a crude linear search because I do not expect this to be a
// performance-limiting part of this whole program.

int32_t decodename(int fontnum, const char *name)
{
    int i;
    for (i=0; i<charcount; i++)
        if (fontnum == fontkey[i] &&
            strcmp(name, uninames[i]) == 0)
        return codepoint[i];
    printf("Character called %s not found in font %d\n", name, fontnum);
    exit(EXIT_FAILURE);
}

// The hash table will end up holding information about around 32000
// characters. It is arranged in lines each of which store data on
// four characters, so assuming few isolated character codes that
// means it will use around 8000 entries. I make its size a prime.
// If I make it 10091 then my tables are fairly full - around 99.5%.
// The hashing scheme I use will guarantee that not many probes are
// needed even at this high loading level!!!

#define MAXCHAR_METRICS_TABLE_SIZE 20000

// This is around 400 Kbytes... I tend to count that as quite large.
// By far the largest contribution to it is data from odokai.afm.
// Although almost all characters there are specified with a width of 1000
// the character bounding boxes are all individual and varied, and so trying
// to save space by having an index of bounding boxes does not appear to be
// useful.

static uint64_t hashtable[MAXCHAR_METRICS_TABLE_SIZE][5];

static int main_importance(uint32_t key)
{
    int font = key >> 16;
    if (font != F_cmuntt && font != F_Math) return CUCKOO_STANDARD;
    key &= 0xffff;
// codepoints U+0000 to U+007f have a very special status, and
// I will insist that they are always processed in one probe.
    if ((key & 0xffff) < 0x80/4) return CUCKOO_VITAL;
// The fixed pitch font used for most input and the Maths font used for
// most output will be encouraged to use at most two probes.
    if (font == F_cmuntt)
    {   if (key < 0x0600/4 ||
            (0x2000/4 <= key && key < 0x3000/4) ||
            (0xfb00/4 <= key && key < 0xfc00/4))  return CUCKOO_IMPORTANT;
    }   
    else if (font == F_Math)
    {   if (key < 0x0600/4 ||
            (0x2000/4 <= key && key < 0x2400/4) ||
            (0x2900/4 <= key && key < 0x2c00/4) ||
            (0x4000/4 <= key && key < 0x6000/4) ||
            (0xfb00/4 <= key && key < 0xfc00/4))  return CUCKOO_IMPORTANT;
    }   
// Other characters get standard treatment and are allowed up to three probes.
    return CUCKOO_STANDARD;
}

static uint32_t main_get(void *p)
{
// The FULL key may be up to 21-bits but because I then have hash-table lines
// with 4 items in I only use 19-bit keys here. In reality with the packing
// scheme used at present I only ise 19-bit full keys and hence 17 bits here,
// so there are two bits available for future expansion if necessary.
    return *(uint32_t *)p & 0x0007ffff;
}
static void main_set(void *p, uint32_t key)
{
    *(uint32_t *)p = (*(uint32_t *)p & 0xfff80000) | (key & 0x0007ffff);
}


// I will have a separate hash table to map cslSTIXMath-Regular characters
// onto signed 10-bit values that give information about the horizontal
// placement for accents to be places above characters. This is just for
// cstSTIXMath-Regular because that is the only font that I am using that
// has this information embedded within it. Both key and value can pack
// into a 32-bit integere here.

#define MAXTOPCENTRESIZE 500
static int32_t topcentre[MAXTOPCENTRESIZE];


static int accent_importance(uint32_t key)
{
    return CUCKOO_IMPORTANT;
}


static uint32_t accent_get(void *p)
{
    return *(uint32_t *)p;
}
static void accent_set(void *p, uint32_t key)
{
    *(uint32_t *)p = key;
}


// Another table will take characters to "larger variants". So for instance
// a left parenthesis will have five gradually larger versions.


static int variantsize = MAXMATHSYMS;
static int64_t variant_table[MAXMATHSYMS][2];


static int variant_importance(uint32_t key)
{
    return CUCKOO_IMPORTANT;
}


static uint32_t variant_get(void *p)
{
    return (uint32_t)(*(uint64_t *)p & 0x001fffff);
}
static void variant_set(void *p, uint32_t key)
{
    *(uint64_t *)p = (*(uint64_t *)p & ~(uint64_t)0x001fffff) | key;
}


static char      line[MAXLINE];
static char      saveline[MAXLINE];
static char      segment[MAXLINE];

int maxw=-10000, maxllx=-10000, maxlly=-10000, maxurx=-10000, maxury=-10000;
int minw=10000, minllx=10000, minlly=10000, minurx=10000, minury=10000;

int main(int argc, char *argv[])
{
    const char *f;
    int pass, fontnum, best;
    char *p, *q;
    int relevant = 0;
    int kerndata = 0;
    int topaccent = 0;
    int variant = 0;
    FILE *src;
    time_t ttt;
    char filename[100];
    int i, probes  = 0, p1 = 0, p2 = 0, n1 = 0, n2 = 0,
        occupancy = 0, fail, qq;
    setvbuf(stdout, NULL, _IONBF, 1);
//==========================================================================
// (1) Read in all the metrics
//==========================================================================
    nkerns = charcount = 0;
// I will map characters from u+000000 to u+01ffff but not beyond - that
// way I will only need 17 bits to specify a codepoint.
    for (fontnum=0; fontnum<F_end; fontnum++)
    {   f = fontnames[fontnum];
        printf("Process font %s\n", f);
        relevant = kerndata = topaccent = variant = 0;
        sprintf(filename, "wxfonts/metrics/%s.afm", f);
        if ((src = fopen(filename, "r")) == NULL)
        {   printf("Unable to access %s\n", filename);
            exit(EXIT_FAILURE);
        }
        for (;;)
        {   int ia, ib, ic, id;
            int32_t cp, wid, bb1, bb2, bb3, bb4;
            char unn[MAXLINE], lig1[MAXLINE], lig2[MAXLINE];
            cp = -1;
            wid = bb1 = bb2 = bb3 = bb4 = 0;
            unn[0] = lig1[0] = lig2[0] = 0;
            ia = ib = ic = id = 0;
            if (fgets(line, sizeof(line)-1, src) == NULL) break;
            if (strncmp(line, "EndFontMetrics", 14) == 0) break;
            ia = (int)strlen(line);
            while (ia >= 0 &&
                   (line[ia] == 0 || line[ia] == '\n' || line[ia] == '\r'))
                ia--;
            line[ia+1] = 0; // discard final newline
            if (ia == 0) break;
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
            if (strncmp(line, "StartTopAccent", 14) == 0)
            {   topaccent = 1;
                continue;
            }
            if (strncmp(line, "EndTopAccent", 12) == 0)
            {   topaccent = 0;
                continue;
            }
            if (strncmp(line, "StartVariations", 15) == 0)
            {   variant = 1;
                continue;
            }
            if (strncmp(line, "EndVariations", 13) == 0)
            {   variant = 0;
                continue;
            }
            if (kerndata)
            {   if (sscanf(line, "KPX %s %s %d", lig1, lig2, &ia) == 3)
                {   kernfont[nkerns] = fontnum;
                    strcpy(kernstart[nkerns], lig1);
                    strcpy(kernfollow[nkerns], lig2);
                    kernadjustment[nkerns] = ia;
#if 0
                    printf("[%d] %s + %s => %d\n", nkerns, lig1, lig2, ia);
#endif
                    nkerns++;
                }
                else
                {   printf("Dubious kerning data %s\n", line);
                    continue;
                }
                continue;
            }
            if (topaccent)
            {   if (sscanf(line, "N %s ; DX %d", accentname[accentp], &accentval[accentp]) == 2)
                    accentp++;
                printf("%d: %s\n", accentp, line);
                continue;
            }
            if (variant)
            {   int some = 0;
// Variant lines can be horribly long! They start VX or HX for vertical
// or horizontal variations.
                if (sscanf(line, "VX %s ;", variantname[variantp]) == 1)
                    variantdirection[variantp] = 1;
                if (sscanf(line, "HX %s ;", variantname[variantp]) == 1)
                    variantdirection[variantp] = 0;
                else continue;
// before collecting data I zero out all the relevant fields so that
// when data is not present I end up in a sane state.
                v1[variantp][0] = 0;
                v2[variantp][0] = 0;
                v3[variantp][0] = 0;
                v4[variantp][0] = 0;
                v5[variantp][0] = 0;
                P1[variantp][0] = 0;
                P2[variantp][0] = 0;
                P3[variantp][0] = 0;
                P4[variantp][0] = 0;
                P5[variantp][0] = 0;
                for (i=0; i<4; i++) vdata1[variantp][i] = 0;
                for (i=0; i<4; i++) vdata2[variantp][i] = 0;
                for (i=0; i<4; i++) vdata3[variantp][i] = 0;
                for (i=0; i<4; i++) vdata4[variantp][i] = 0;
                for (i=0; i<4; i++) vdata5[variantp][i] = 0;
                p = strchr(line, ';');
                if (p!=NULL & sscanf(p, "; V1 %s ;", v1[variantp]) == 1)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; V2 %s ;", v2[variantp]) == 1)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; V3 %s ;", v3[variantp]) == 1)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; V4 %s ;", v4[variantp]) == 1)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; V5 %s ;", v5[variantp]) == 1)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; P1 %s %d %d %d %d ;",
                           P1[variantp],
                           &vdata1[variantp][0], &vdata1[variantp][1],
                           &vdata1[variantp][2], &vdata1[variantp][3]) == 5)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; P2 %s %d %d %d %d ;",
                           P2[variantp],
                           &vdata2[variantp][0], &vdata2[variantp][1],
                           &vdata2[variantp][2], &vdata2[variantp][3]) == 5)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; P3 %s %d %d %d %d ;",
                           P3[variantp],
                           &vdata3[variantp][0], &vdata3[variantp][1],
                           &vdata3[variantp][2], &vdata3[variantp][3]) == 5)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; P4 %s %d %d %d %d ;",
                           P4[variantp],
                           &vdata4[variantp][0], &vdata4[variantp][1],
                           &vdata4[variantp][2], &vdata4[variantp][3]) == 5)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (p!=NULL & sscanf(p, "; P5 %s %d %d %d %d ;",
                           P5[variantp],
                           &vdata4[variantp][0], &vdata4[variantp][1],
                           &vdata4[variantp][2], &vdata4[variantp][3]) == 5)
                {   p = strchr(p+1, ';');
                    some = 1;
                }
                if (some)
                {   printf("%d: (%d) %s\n", variantp,
                            variantdirection[variantp], variantname[variantp]);
                    printf(" sizes: %s %s %s %s %s\n",
                           v1[variantp], v2[variantp],
                           v3[variantp], v4[variantp],
                           v5[variantp]);
                    if (P1[0] != 0) printf(" huge1: %s %d %d %d %d\n",
                       P1[variantp], vdata1[variantp][0],
                       vdata1[variantp][1], vdata1[variantp][2],
                       vdata1[variantp][3]);
                    if (P2[0] != 0) printf(" huge2: %s %d %d %d %d\n",
                       P2[variantp], vdata2[variantp][0],
                       vdata2[variantp][1], vdata2[variantp][2],
                       vdata2[variantp][3]);
                    if (P3[0] != 0) printf(" huge3: %s %d %d %d %d\n",
                       P3[variantp], vdata3[variantp][0],
                       vdata3[variantp][1], vdata3[variantp][2],
                       vdata3[variantp][3]);
                    if (P4[0] != 0) printf(" huge4: %s %d %d %d %d\n",
                       P4[variantp], vdata4[variantp][0],
                       vdata4[variantp][1], vdata4[variantp][2],
                       vdata4[variantp][3]);
                    if (P5[0] != 0) printf(" huge5: %s %d %d %d %d\n",
                       P5[variantp], vdata5[variantp][0],
                       vdata5[variantp][1], vdata5[variantp][2],
                       vdata5[variantp][3]);
                    variantp++;
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
                        printf("%d: %s\n", (int)strlen(unn), unn);
                        exit(EXIT_FAILURE);
                    }
                    if (cp == -1)
                    {   if (sscanf(unn, "u%x", &ia) == 1) cp = ia;
                        else if (sscanf(unn, "uni%x", &ia) == 1) cp = ia;
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
// I observe some redundant ligature statements in the font metrics I use,
// so that the same information appears twice in a row. I filter that
// case out here.
                    if (nligatures == 0 ||
                        fontnum != ligfont[nligatures-1] ||
                        cp != ligstart[nligatures-1] ||
                        strcmp(lig1, ligfollow[nligatures-1]) != 0)
                    {   ligfont[nligatures] = fontnum;
                        ligstart[nligatures] = cp;
                        strcpy(ligfollow[nligatures], lig1);
                        strcpy(ligreplacement[nligatures], lig2);
                        nligatures++;
                    }
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
            if (cp < 0 || cp > 0x10ffff)
            {   if (strcmp(unn, ".notdef") != 0)
                    printf("Discarding character <%s>"
                           " with codepoint %#x = %d\n",
                           unn, cp, cp);
                continue;
            }
            if (cp >= 0xd000 && cp < 0xe000)
                printf("Codepoint %d U+%x noted : probably invalid in %s\n",
                       cp, cp, f);
// Note that cmuntt has 4 characters beyond the basic multilingual pane -
// for GREEK ACROPHONIC ATTIC FIFTY etc at U+10144. They look like capitals
// Delta, H, X and M each with a border to left, right and top. I will
// detect these here but then not support their use!
            if (cp > 0xffff &&
                !(cp >= 0x1d000 && cp < 0x1e000) &&
                !(cp >= 0x108000 && cp < 0x109000))
                printf("Codepoint %d U+%x noted : probably invalid in %s\n",
                       cp, cp, f);
            fontkey[charcount] = fontnum;
            codepoint[charcount] = cp;
            width[charcount] = wid;
            strcpy(uninames[charcount], unn);
            llx[charcount] = bb1;
            lly[charcount] = bb2;
            urx[charcount] = bb3;
            ury[charcount] = bb4;
            charcount++;
        }
        fclose(src);
    }
    printf("About to resolve kern and ligature names\n");
    printf("nkerns = %d nligatures = %d\n", nkerns, nligatures);
    for (i=0; i<nkerns; i++)
        kernstartcode[i] = decodename(kernfont[i], kernstart[i]);
    for (i=0; i<nkerns; i++)
        kernfollowcode[i] = decodename(kernfont[i], kernfollow[i]);
    for (i=0; i<nligatures; i++)
        ligfollowcode[i] = decodename(ligfont[i], ligfollow[i]);
    for (i=0; i<nligatures; i++)
        ligreplacementcode[i] = decodename(ligfont[i], ligreplacement[i]);

// Now I will try to do something about the topcentre table...
    for (i=0; i<accentp; i++)
        accentnum[i] = decodename(F_Math, accentname[i]);
    printf("Accent position tables processed\n");
    for (i=0; i<variantp; i++)
    {   variantcode[i] = decodename(F_Math, variantname[i]);
        if (v1[i][0] != 0) nv1[i] = decodename(F_Math, v1[i]);
        else nv1[i] = 0;
        if (v2[i][0] != 0) nv2[i] = decodename(F_Math, v2[i]);
        else nv2[i] = 0;
        if (v3[i][0] != 0) nv3[i] = decodename(F_Math, v3[i]);
        else nv3[i] = 0;
        if (v4[i][0] != 0) nv4[i] = decodename(F_Math, v4[i]);
        else nv4[i] = 0;
        if (v5[i][0] != 0) nv5[i] = decodename(F_Math, v5[i]);
        else nv5[i] = 0;
        if (P1[i][0] != 0) np1[i] = decodename(F_Math, P1[i]);
        else np1[i] = 0;
        if (P2[i][0] != 0) np2[i] = decodename(F_Math, P2[i]);
        else np2[i] = 0;
        if (P3[i][0] != 0) np3[i] = decodename(F_Math, P3[i]);
        else np3[i] = 0;
        if (P4[i][0] != 0) np4[i] = decodename(F_Math, P4[i]);
        else np4[i] = 0;
        if (P5[i][0] != 0) np5[i] = decodename(F_Math, P5[i]);
        else np5[i] = 0;
    }
    printf("Larger symbols tables processed\n");

// Now I have read everything.
//
// Before I fill in the main hash table I need to collect kern and ligature
// information.
    kernp = ligp = 0;
    for (fontnum=0; fontnum<F_end; fontnum++)
    {   fontkern[fontnum] = kernp-1;
        for (i=0; i<charcount; i++)
        {   int j, v = 0, kkk = 0;
// I wish to process all chars from each font in order. In fact they will
// be in my table that way, but I still code things to scan once for each font.
            if (fontkey[i] != fontnum) continue;
// Now I will transfer any ligature and kern info about this character
// into kerntable & ligtable.
            for (j=0; j<nkerns; j++)
            {   if (kernfont[j] == fontnum &&
                    kernstartcode[j] == codepoint[i])
                {   strcpy(ktstart[kernp], kernstart[j]);
                    strcpy(ktfollow[kernp], kernfollow[j]);
                    ktadjustment[kernp] = kernadjustment[j];
                    strcpy(ktfont[kernp], fontnames[fontnum]);
                    ktfontn[kernp] = fontnum;
// kkk will be the index in the kernel tables of the FIRST item
// relating to this start character. It has 0x80000000 forced in so
// that it is a nonzero value even if the kernel table index is zero.
                    if (kkk == 0) kkk = kernp | 0x80000000;
                    kerntable[kernp++] =
                        (kernadjustment[j]<<23) | kernfollowcode[j];
                    v = 1;
                }
            }
            for (j=0; j<nligatures; j++)
            {   if (ligfont[j] == fontnum &&
                    ligstart[j] == codepoint[i])
                {   strcpy(ktstart[kernp], uninames[i]);
                    strcpy(ktfollow[kernp], ligfollow[j]);
                    ktadjustment[kernp] = 9999;
                    strcpy(ktfont[kernp], fontnames[fontnum]);
                    ktfontn[kernp] = fontnum;
                    if (kkk == 0) kkk = kernp | 0x80000000;
                    kerntable[kernp++] =
                        (ligp<<23) | IS_LIGATURE | ligfollowcode[j];
                    strcpy(ltfirst[ligp], uninames[i]);
                    strcpy(ltfollow[ligp], ligfollow[j]);
                    strcpy(ltname[ligp], ligreplacement[j]);
                    strcpy(ltfont[ligp], fontnames[fontnum]);
                    ligtable[ligp++] = ligreplacementcode[j];
                    v = 1;
                }
            }
// v was set if I found at least one kern or ligature entry starting
// with this character. Noticing that here means I can look back and
// be certain that the previous block just ended.
            if (v && kernp!=0) kerntable[kernp-1] |= IS_BLOCKEND;
            kernreference[i] = kkk;
        }
    }
// Make really certain that the table is terminated.
    if (kernp!=0) kerntable[kernp-1] |= IS_BLOCKEND;

    printf("charcount = %d\n", charcount);

// Well because it will be a cheaper process I will set up the small hash-
// tables for accent placement and large-characters first...
    for (i=0; i<accentp; i++)
        printf("    %#.8x,\n", accentnum[i]);

    cuckoo_parameters topcentre_r =
        cuckoo_binary_optimise(
            accentnum,
            accentp,
            accent_importance,
            topcentre,
            sizeof(topcentre[0]),
            accentp-1,
            sizeof(topcentre)/sizeof(topcentre[0]),
            accent_get,
            accent_set);
    printf("Table size = %d (%d %d)\n", topcentre_r.table_size,
            topcentre_r.modulus2, topcentre_r.offset2);
    printf("Now put in accent positions\n");
    for (i=0; i<accentp; i++)
    {   int w = cuckoo_lookup(
            accentnum[i],
            topcentre,
            sizeof(topcentre[0]),
            topcentre_r.table_size,
            accent_get,
            topcentre_r.modulus2,
            topcentre_r.offset2);
        if (w == -1)
        {   printf("failure of lookup in topaccent table!\n");
            printf("%d: %d/%x\n", i, accentnum[i], accentnum[i]);
            for (i=0; i<topcentre_r.table_size; i++)
                printf("%4d: %x\n", i, topcentre[i]);
            exit(1);
        }
        topcentre[w] |= accentval[i] << 21;
    }
    printf("top-centre table set up with %d words for %d chars (%.2f)\n",
        topcentre_r.table_size, accentp,
        (100.0*accentp)/topcentre_r.table_size);
                
    cuckoo_parameters variant_r =
        cuckoo_binary_optimise(
            variantcode,
            variantp,
            variant_importance,
            variant_table,
            sizeof(variant_table[0]),
            variantp-1,
            sizeof(variant_table)/sizeof(variant_table[0]),
            variant_get,
            variant_set);
    printf("Table size = %d (%d %d)\n", variant_r.table_size,
            variant_r.modulus2, variant_r.offset2);
    printf("Now put in variant info for (, ), [, ] etc.\n");
    for (i=0; i<variantp; i++)
    {   int w = cuckoo_lookup(
            variantcode[i],
            variant_table,
            sizeof(variant_table[0]),
            variant_r.table_size,
            variant_get,
            variant_r.modulus2,
            variant_r.offset2);
        if (w == -1)
        {   printf("failure of lookup in varinat table!\n");
            printf("%d: %d/%x\n", i, variantcode[i], variantcode[i]);
            for (i=0; i<variant_r.table_size; i++)
                printf("%4d: %" PRIx64 "\n", i, variant_table[i][0]);
            exit(1);
        }
// @@@@@@@@
        variant_table[w][0] |= 0x10000000;
        variant_table[w][1] |= 0x20000000;
    }
    printf("variant table set up with %d entries for %d chars (%.2f)\n",
        variant_r.table_size, variantp,
        (100.0*variantp)/variant_r.table_size);
                

//==========================================================================
// (2) Try inserting everything in to the hash table
//==========================================================================

// I will remove duplicate keys here first... I will cheerfully use
// a quadratic cost filtering process here because other things are so much
// more expensive.
    mainkeycount = 0;
    for (i=0; i<charcount; i++)
    {   int j;
        uint32_t k = pack_character(fontkey[i], codepoint[i]) >> 2;
        if (k == 0) continue;
        for (j=0; j<mainkeycount; j++)
            if (k == mainkey[j]) break;
        if (j<mainkeycount) continue;   // discard repeat key.
        mainkey[mainkeycount++] = k;
    }

    printf("About to try to optimise for %d entries\n", mainkeycount);
// In my case there are 10019 keys to consider, If I do a proper search
// that can take quite a while - say 45 minutes on a reasonably fast desktop
// system. So as I cunning ploy I will first try the parameters that
// are a known solution, and if nothing has changed at all that will
// succeed (very rapidly) and I can use it. If that fails I will drop back
// to the more expensive search

#define EXPECTED_TABLESIZE   10057
#define EXPECTED_MODULUS2     8729
#define EXPECTED_OFFSET2      1108

    cuckoo_parameters main_r;

    if (cuckoo_insert_all(
        mainkey,
        mainkeycount,
        main_importance,
        hashtable,
        sizeof(hashtable[0]),
        EXPECTED_TABLESIZE,
        main_get,
        main_set,
        EXPECTED_MODULUS2,
        EXPECTED_OFFSET2))
    {   main_r.table_size = EXPECTED_TABLESIZE;
        main_r.modulus2 = EXPECTED_MODULUS2;
        main_r.offset2 = EXPECTED_OFFSET2;
        printf("Built-in table parameters successfully used\n");
    }
    else main_r = cuckoo_binary_optimise(
        mainkey,
        mainkeycount,
        main_importance,
        hashtable,
        sizeof(hashtable[0]),
        MAIN_LOW,
        MAIN_HIGH,
        main_get,
        main_set);
    printf("Whooeeee! %d %d %d %.2f\n",
        main_r.table_size, main_r.modulus2, main_r.offset2,
        (100.0*mainkeycount)/main_r.table_size);

//=====================================================================
// Now the table should have everything in it and so I can merely fill
// in the actual metric information
//=====================================================================
    printf("\nNow I want to put data into the hash table.\n");
    for (i=0; i<charcount; i++)
    {   int fullkey = pack_character(fontkey[i], codepoint[i]); // 20-bit key
        int key = fullkey >> 2; // because my hash table has line-size 4
        if (codepoint[i] == 0) continue;
        int h1;
        uint64_t w;
        h1 = cuckoo_lookup(
            key,
            hashtable,
            sizeof(hashtable[0]),
            main_r.table_size,
            main_get,
            main_r.modulus2,
            main_r.offset2);
        if (h1 == -1)
        {   int j;
            printf("failure at line %d!\n", __LINE__);
            printf("Problem with character %d font %d codepoint %d/%x\n",
                   i, fontkey[i], codepoint[i], codepoint[i]);
            printf("Full key = %d/%x key = %d/%x\n",
                    fullkey, fullkey, key, key);
            for (j=0; j<main_r.table_size; j++)
                printf("%7d: %" PRIx64 "\n", j, hashtable[j][0]);

            exit(1);
        }

// Pack and write in the messy information about width and bounding boxes.
        w = ((uint64_t)width[i] & 0x1fff) << 51 |
            ((uint64_t)(llx[i]+3000) & 0x1fff) << 38 |
            ((uint64_t)(lly[i]+1000) & 0x0fff) << 26 |
            ((uint64_t)(urx[i]+500) & 0x1fff) << 13 |
            ((uint64_t)(ury[i]+1000) & 0x1fff);
        hashtable[h1][1+(fullkey&3)] = w;
// Finally merge in an offset to any kern info that might be available
        if (kernreference[i] != 0)
        {   int64_t q = (kernreference[i] & 0x7fffffff)-fontkern[fontkey[i]];
#if 0
            printf("Fill in kern ref %d as %d\n",
                   kernreference[i] & 0x7fffffff, (int)q);
#endif
            hashtable[h1][0] |= q << (19+11*(fullkey&3));
        }
    }

    printf("Done after %d characters, %d ligatures, %d kerns\n",
           charcount, nligatures, nkerns);
    printf("width %d %d (%d)\n", minw, maxw, maxw-minw);
    printf("llx %d %d (%d)\n", minllx, maxllx, maxllx-minllx);
    printf("lly %d %d (%d)\n", minlly, maxlly, maxlly-minlly);
    printf("urx %d %d (%d)\n", minurx, maxurx, maxurx-minurx);
    printf("ury %d %d (%d)\n", minury, maxury, maxury-minury);

    printf("Total space = %d\n", main_r.table_size*(5*8));
    p1 = 0;
    for (i=0; i<main_r.table_size; i++)
    {   if (hashtable[i][0] != 0) p1++;
    }
    printf("%d of %d entries (%d of %d bytes) used: %.4f\n",
        p1, main_r.table_size, 40*p1, 40*main_r.table_size,
        (double)p1/(double)main_r.table_size);


    {   FILE *dest = fopen("charmetrics.h", "w");
        FILE *rdest = fopen("charmetrics.red", "w");
fprintf(dest, "// charmetrics.h                           Copyright (C) 2015 Codemist Ltd\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "// $Id$\n");
fprintf(dest, "\n");
fprintf(dest, "\n");
fprintf(dest, "/**************************************************************************\n");
fprintf(dest, " * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *\n");
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
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "#define __STDC_CONSTANT_MACROS 1\n");
fprintf(dest, "#endif\n");
fprintf(dest, "\n#include <stdint.h>\n\n");
fprintf(dest, "// Character metric hash table created using the program charmetrics.c\n");
fprintf(dest, "// sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/cslbase/wxfontxs\n");
fprintf(dest, "// contains README files with full credits to the fonts this is used with\n");
fprintf(dest, "\n\n");
fprintf(dest, "// The list of font codes here must be kept in step with the list\n");
fprintf(dest, "// of names in the table.\n");
fprintf(dest, "\n");
fprintf(dest, "#define F_cmuntt                      0\n");
fprintf(dest, "#define F_odokai                      1\n");
fprintf(dest, "#define F_Regular                     2\n");
fprintf(dest, "#define F_Bold                        3\n");
fprintf(dest, "#define F_Italic                      4\n");
fprintf(dest, "#define F_BoldItalic                  5\n");
fprintf(dest, "#define F_Math                        6\n");
fprintf(dest, "#define F_end                         7\n");
fprintf(dest, "\n");
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "extern \"C\" {\n");
fprintf(dest, "#endif // __cplusplus\n\n");
fprintf(dest, "extern int c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo;\n");
fprintf(dest, "extern int lookupchar(int fontnum, int codepoint);\n");
fprintf(dest, "extern int32_t lookupkernandligature(int codepoint);\n");
fprintf(dest, "extern int32_t lookupkernadjustment(int codepoint);\n");
fprintf(dest, "extern int32_t lookupligature(int codepoint);\n");
fprintf(dest, "extern int accentposition(int codepoint);\n\n");
fprintf(dest, "extern const uint16_t chardepth_WIN32[31];\n");
fprintf(dest, "extern const uint16_t chardepth_X11[31];\n");
fprintf(dest, "extern const uint16_t chardepth_OSX[31];\n");
fprintf(dest, "extern const uint16_t *chardepth;\n");
fprintf(dest, "extern const char *fontnames[31];\n\n");
fprintf(dest, "#ifdef __cplusplus\n");
fprintf(dest, "}\n");
fprintf(dest, "#endif // __cplusplus\n\n");
fprintf(rdest, "%% Character metrics for the STIX (and some other) fonts...\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Character metric hash table created using the program charmetrics.c\n");
fprintf(rdest, "%% sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/cslbase/wxfonts\n");
fprintf(rdest, "%% contains README files with full credits to the fonts this is used with\n");
fprintf(rdest, "%% Author: Arthur Norman\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Redistribution and use in source and binary forms, with or without\n");
fprintf(rdest, "%% modification, are permitted provided that the following conditions are met:\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "%%    * Redistributions of source code must retain the relevant copyright\n");
fprintf(rdest, "%%      notice, this list of conditions and the following disclaimer.\n");
fprintf(rdest, "%%    * Redistributions in binary form must reproduce the above copyright\n");
fprintf(rdest, "%%      notice, this list of conditions and the following disclaimer in the\n");
fprintf(rdest, "%%      documentation and/or other materials provided with the distribution.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n");
fprintf(rdest, "%% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,\n");
fprintf(rdest, "%% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n");
fprintf(rdest, "%% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR\n");
fprintf(rdest, "%% CONTRIBUTORS\n");
fprintf(rdest, "%% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n");
fprintf(rdest, "%% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF\n");
fprintf(rdest, "%% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n");
fprintf(rdest, "%% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n");
fprintf(rdest, "%% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n");
fprintf(rdest, "%% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n");
fprintf(rdest, "%% POSSIBILITY OF SUCH DAMAGE.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% Also be aware of the (generally permissive) licenses associated with the\n");
fprintf(rdest, "%% fonts. Fill README files and license terms for the fonts themselves\n");
fprintf(rdest, "%% are in csl/cslbase/wxfonts.\n");
fprintf(rdest, "\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% $Id$\n");
fprintf(rdest, "\n");
fprintf(rdest, "#if (or (memq 'psl lispsystem!*) (memq 'jlisp lispsystem!*))\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% CSL has special vectors that hold just 16-bit integers and 32-bit\n");
fprintf(rdest, "%% integers and use of those will decrease the amount of memory consumed\n");
fprintf(rdest, "%% here. However if PSL does not have these it does not matter much since I\n");
fprintf(rdest, "%% can just use ordinary Lisp vectors...\n");
fprintf(rdest, "%% I set initial contents as all 0 rather than all nil since these are\n");
fprintf(rdest, "%% supposed to contain (small) integer values.\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure mkvect32 n;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r;\n");
fprintf(rdest, "    r := mkvect n;\n");
fprintf(rdest, "    for i := 0:n do putv(r, i, 0);\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure putv32(v, n, x); putv(v, n, x);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure getv32(v, n); getv(v, n);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure mkvect16 n;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r;\n");
fprintf(rdest, "    r := mkvect n;\n");
fprintf(rdest, "    for i := 0:n do putv(r, i, 0);\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure putv16(v, n, x); putv(v, n, x);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic inline procedure getv16(v, n); getv(v, n);\n");
fprintf(rdest, "\n");
fprintf(rdest, "#endif\n");
fprintf(rdest, "\n");
fprintf(rdest, "put('cmuntt, 'font_number,                      0)$\n");
fprintf(rdest, "put('odokai, 'font_number,                      1)$\n");
fprintf(rdest, "put('Regular, 'font_number,                     2)$\n");
fprintf(rdest, "put('Bold, 'font_number,                        3)$\n");
fprintf(rdest, "put('Italic, 'font_number,                      4)$\n");
fprintf(rdest, "put('BoldItalic, 'font_number,                  5)$\n");
fprintf(rdest, "put('Math, 'font_number,                        6)$\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure list_to_vec16 l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect16 (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv16(r, i, car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic procedure list_to_vec32 l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect32 (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv32(r, i, car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "%% This one will take a list whose elements are thenselves 10-element lists\n");
fprintf(rdest, "%% of 32-bit integers.\n");
fprintf(rdest, "%%\n");
fprintf(rdest, "symbolic procedure list_to_metric_table l;\n");
fprintf(rdest, "  begin\n");
fprintf(rdest, "    scalar r, n;\n");
fprintf(rdest, "    r := mkvect (n := sub1 length l);\n");
fprintf(rdest, "    for i := 0:n do <<\n");
fprintf(rdest, "       putv(r, i, list_to_vec32 car l);\n");
fprintf(rdest, "       l := cdr l >>;\n");
fprintf(rdest, "    return r\n");
fprintf(rdest, "  end;\n");
fprintf(rdest, "\n");
fprintf(rdest, "fluid '(hashsize!* metrics_hash!* topcentre_hash!* fontkern!* kerntable!* ligaturetable!*);\n");
fprintf(rdest, "\n");
fprintf(rdest, "symbolic (hashsize!* := %d);\n", main_r.table_size);
fprintf(rdest, "\n");
        fprintf(dest, "const uint64_t charmetrics[%d][5] = \n{",
            main_r.table_size);
        fprintf(rdest, "#eval (setq metrics_hash!* (list_to_metric_table '\n    (");
        for (i=0; i<main_r.table_size; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest,
                "\n    {UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 "),"
                "\n                                   UINT64_C(0x%.16" PRIx64 "), UINT64_C(0x%.16" PRIx64 ")}",
                hashtable[i][0],
                hashtable[i][1], hashtable[i][2],
                hashtable[i][3], hashtable[i][4]);
            fprintf(rdest, "\n     (0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32,
                (int)hashtable[i][0], (int)(hashtable[i][0]>>32),
                (int)hashtable[i][1], (int)(hashtable[i][1]>>32),
                (int)hashtable[i][2]);
            fprintf(rdest, "\n      0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 " 0x%.8" PRIx32 ")",
                                      (int)(hashtable[i][2]>>32),
                (int)hashtable[i][3], (int)(hashtable[i][3]>>32),
                (int)hashtable[i][4], (int)(hashtable[i][4]>>32));
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "#define CHAR_METRICS_MODULUS %d\n", main_r.modulus2);
        fprintf(dest, "#define CHAR_METRICS_OFFSET %d\n\n", main_r.offset2);
        fprintf(dest, "const uint32_t topcentre[%d] = \n{",
            topcentre_r.table_size);
        fprintf(rdest, "#eval (setq topcentre_hash!* (list_to_vec32 '\n    (");
        for (i=0; i<topcentre_r.table_size; i++)
        {   if (i != 0) fprintf(dest, ",");
            fprintf(dest, "\n    UINT32_C(0x%.8" PRIx32 ")", topcentre[i]);
            fprintf(rdest, "\n     0x%.8" PRIx32, topcentre[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(dest, "#define TOPCENTRE_MODULUS %d\n", topcentre_r.modulus2);
        fprintf(dest, "#define TOPCENTRE_OFFSET %d\n\n", topcentre_r.offset2);
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const int16_t fontkern[] = \n{");
        fprintf(rdest, "#eval (setq fontkern!* (list_to_vec16 '\n    (");
        for (i=0; i<F_end; i++)
        {   int w = fprintf(dest, "\n    %d", fontkern[i]);
            if (i != F_end-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            while (++w < 16) fprintf(dest, " ");
            w = fprintf(rdest, "\n    %d ", fontkern[i]);
            while (++w < 16) fprintf(rdest, " ");
            fprintf(dest, "// %s", fontnames[i]);
            if (i != F_end-2 &&
                fontkern[i+1] != fontkern[i])
                fprintf(dest, " [%d items]", fontkern[i+1]-fontkern[i]);
            fprintf(rdest, "%% %s", fontnames[i]);
            if (i != F_end-2 &&
                fontkern[i+1] != fontkern[i])
                fprintf(rdest, " [%d items]", fontkern[i+1]-fontkern[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const uint32_t kerntable[] = \n{");
        fprintf(rdest, "#eval (setq kerntable!* (list_to_vec32 '\n    (");
        for (i=0; i<kernp; i++)
        {   fprintf(dest, "\n    0x%.8" PRIx32, kerntable[i]);
            if (i != kernp-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            fprintf(rdest, "\n    0x%.8" PRIx32 " ", kerntable[i]);
            if ((kerntable[i] & IS_LIGATURE) != 0)
                fprintf(dest, "   // [%d:%d] %s + %s ligature #%d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               kerntable[i]>>23, ktfont[i]);
            else
                fprintf(dest, "   // [%d:%d] %s + %s : %d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               ktadjustment[i], ktfont[i]);
            if ((kerntable[i] & IS_BLOCKEND) != 0) fprintf(dest, " ;;");
            if ((kerntable[i] & IS_LIGATURE) != 0)
                fprintf(rdest, "   %% [%d:%d] %s + %s ligature #%d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               kerntable[i]>>23, ktfont[i]);
            else
                fprintf(rdest, "   %% [%d:%d] %s + %s : %d (%s)",
                               i, i-fontkern[ktfontn[i]],
                               ktstart[i], ktfollow[i],
                               ktadjustment[i], ktfont[i]);
            if ((kerntable[i] & IS_BLOCKEND) != 0) fprintf(rdest, " ;;");
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "const uint32_t ligaturetable[] = \n{");
        fprintf(rdest, "#eval (setq ligaturetable!* (list_to_vec32 '\n    (");
        for (i=0; i<ligp; i++)
        {   int l = fprintf(dest, "\n    %" PRId32, ligtable[i]);
            if (i != ligp-1) fprintf(dest, ",");
            else fprintf(dest, " ");
            while (++l < 12) fprintf(dest, " ");
            l = fprintf(rdest, "\n    %" PRId32 " ", ligtable[i]);
            while (++l < 12) fprintf(rdest, " ");
            fprintf(dest, "   // [%d] %s + %s => %s (%s)",
                          i, ltfirst[i], ltfollow[i], ltname[i], ltfont[i]);
            fprintf(rdest, "   %% [%d] %s + %s => %s (%s)",
                          i, ltfirst[i], ltfollow[i], ltname[i], ltfont[i]);
        }
        fprintf(dest, "\n};\n\n");
        fprintf(rdest, "\n    )))\n\n");
        fprintf(dest, "// end of charmetrics.h\n");
        fprintf(rdest, "%% The use of #eval means that the metrics above have been defined at\n");
        fprintf(rdest, "%% parse time. I now need to ensure that they will be available even\n");
        fprintf(rdest, "%% when this code is passed through the compiler and hence everything\n");
        fprintf(rdest, "%% goes via a FASL file. The slighly curious macro here should achieve\n");
        fprintf(rdest, "%% that.\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic macro procedure get_character_metrics !*unused!*;\n");
        fprintf(rdest, "  list('progn,\n");
        fprintf(rdest, "    list('setq, 'metrics_hash!*, mkquote metrics_hash!*),\n");
        fprintf(rdest, "    list('setq, 'fontkern!*, mkquote fontkern!*),\n");
        fprintf(rdest, "    list('setq, 'kerntable!*, mkquote kerntable!*),\n");
        fprintf(rdest, "    list('setq, 'ligaturetable!*, mkquote ligaturetable!*),\n");
        fprintf(rdest, "    \"character metrics established\");\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "%% The call to the macro here expands into four simple assignments.\n");
        fprintf(rdest, "symbolic get_character_metrics();\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "fluid '(c_width c_llx c_lly c_urx c_ury c_kerninfo);\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "%% This code looks up a font/codepoint pair in the tables and returns\n");
        fprintf(rdest, "%% a character width (escapement) and a bounding box. It leaves behind\n");
        fprintf(rdest, "%% c_kerninfo - and index into a kern and ligature table.\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupchar(fontnum, codepoint);\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar v, h1, h2, w, whi, wlo, fullkey, key;\n");
        fprintf(rdest, "%% pack codes into fewer bits\n");
        fprintf(rdest, "    if fontnum < 2 then <<\n");
        fprintf(rdest, "      if land(codepoint, 0xd800) = 0xd800 then codepoint := 0xffff\n");
        fprintf(rdest, "      else if codepoint >= 0x10000 then <<\n");
        fprintf(rdest, "        if codepoint < 0x10800 then codepoint := 0xd800 + land(codepoint, 0xfff)\n");
        fprintf(rdest, "        else codepoint := 0xffff >> >>\n");
        fprintf(rdest, "    else if codepoint >= 0x4000 and codepoint < 0x8000 then codepoint := 0xffff\n");
        fprintf(rdest, "    else if codepoint >= 0x1d000 and codepoint < 0x1e000 then\n");
        fprintf(rdest, "      codepoint = 0x4000 + land(codepoint, 0xfff)\n");
        fprintf(rdest, "    else if codepoint >= 0x108000 and codepoint < 0x109000 then\n");
        fprintf(rdest, "      codepoint = 0x5000 + land(codepoint, 0xfff)\n");
        fprintf(rdest, "    else if codepoint >= 0x10000 then codepoint := 0xffff;\n");
        fprintf(rdest, "    fullkey := lshift(fontnum, 16) + codepoint\n");
        fprintf(rdest, "    key := lshift(fullkey, -2);\n");
// I REALLY want the key to be positive here!
        fprintf(rdest, "    h1 := remainder(key, %d);\n", main_r.table_size);
        fprintf(rdest, "    %% Hash table probe 1.\n");
        fprintf(rdest, "    v := land(getv32(w := getv(metrics_hash!*, h1), 0), 0x7ffff);\n");
        fprintf(rdest, "    if not (v = key) then <<\n");
        fprintf(rdest, "      h2 := remainder(key, %d) + %d;\n", main_r.modulus2, main_r.offset2);
        fprintf(rdest, "      %% Hash table probe 2.\n");
        fprintf(rdest, "      v := land(getv32(w := getv(metrics_hash!*, h2), 0), 0x7ffff);\n");
        fprintf(rdest, "      if not (v = key) then <<\n");
        fprintf(rdest, "        h1 := h1 + h2;\n");
        fprintf(rdest, "        if h1 >= %d then h1 := h1 - %d;\n", main_r.table_size, main_r.table_size);
        fprintf(rdest, "        %% Hash table probe 3.\n");
        fprintf(rdest, "        v := land(getv32(w := getv(metrics_hash!*, h1), 0), 0x7ffff);\n");
        fprintf(rdest, "        if not (v = key) then return nil >> >>;\n");
        fprintf(rdest, "    v := 2*land(fullkey, 3);\n");
        fprintf(rdest, "    wlo := getv32(w, v+2);\n");
        fprintf(rdest, "    if wlo = 0 then return nil; %% in hash table but no character here.\n");
        fprintf(rdest, "    whi := getv32(w, v+3);\n");
        fprintf(rdest, "    c_width := land(lshift(whi, -19), 0x1fff);\n");
        fprintf(rdest, "    c_llx := land(lshift(whi, -6), 0x1fff) - 3000;\n");
        fprintf(rdest, "    c_lly := land(lshift(wlo, -26), 0x3f) +\n");
        fprintf(rdest, "             land(lshift(whi, 6), 0xfc0) - 1000;\n");
        fprintf(rdest, "    c_urx := land(lshift(wlo, -13), 0x1fff) - 500;\n");
        fprintf(rdest, "    c_ury := land(wlo, 0x1fff) - 1000;\n");
        fprintf(rdest, "    if v = 0 then c_kerninfo := land(lshift(getv32(w, 0), -19), 0x7ff)\n");
        fprintf(rdest, "    else if v = 2 then c_kerninfo := land(lshift(getv32(w, 0), -30), 0x3) +\n");
        fprintf(rdest, "                                     land(lshift(getv32(w, 1), 2), 0x7fc)\n");
        fprintf(rdest, "    else if v = 4 then c_kerninfo := land(lshift(getv32(w, 1), -9), 0x7ff)\n");
        fprintf(rdest, "    else c_kerninfo := land(lshift(getv32(w, 1), -20), 0x7ff);\n");
        fprintf(rdest, "    if not zerop c_kerninfo then\n");
        fprintf(rdest, "      c_kerninfo := c_kerninfo + getv16(fontkern!*, fontnum);\n");
        fprintf(rdest, "    return t\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupkernadjustment codepoint;\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar i, w;\n");
        fprintf(rdest, "    if zerop (i := c_kerninfo) then return 0;\n");
        fprintf(rdest, " a: w := getv32(kerntable!*, i);\n");
        fprintf(rdest, "    if land(w, 0x001fffff) = codepoint and\n");
        fprintf(rdest, "      zerop land(w, 0x00200000) then <<\n");
        fprintf(rdest, "        w := land(lshift(w, -23), 0x1ff);\n");
        fprintf(rdest, "        if not zerop land(w, 0x100) then w := w - 0x200;\n");
        fprintf(rdest, "        return w >>\n");
        fprintf(rdest, "    else if not zerop land(w, 0x00400000) then return 0;\n");
        fprintf(rdest, "    i := add1 i;\n");
        fprintf(rdest, "    go to a\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure lookupligature codepoint;\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar i, w;\n");
        fprintf(rdest, "    if zerop (i := c_kerninfo) then return nil;\n");
        fprintf(rdest, " a: w := getv32(kerntable!*, i);\n");
        fprintf(rdest, "    if land(w, 0x001fffff) = codepoint and\n");
        fprintf(rdest, "      not zerop land(w, 0x00200000) then\n");
        fprintf(rdest, "        return getv32(ligaturetable!*, land(lshift(w, -23), 0x1ff))\n");
        fprintf(rdest, "    else if not zerop land(w, 0x00400000) then return nil;\n");
        fprintf(rdest, "    i := add1 i;\n");
        fprintf(rdest, "    go to a\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "symbolic procedure accentposition codepoint;\n");
        fprintf(rdest, "  begin\n");
        fprintf(rdest, "    scalar v, h1, h2, w, whi, wlo, fullkey, key;\n");
        fprintf(rdest, "    h1 := remainder(codepoint, %d);\n", topcentre_r.table_size);
        fprintf(rdest, "    %% Hash table probe 1.\n");
        fprintf(rdest, "    v := land(w := getv32(topcentre_hash!*, h1), 0x1fffff);\n");
        fprintf(rdest, "    if not (v = key) then <<\n");
        fprintf(rdest, "      h2 := remainder(key, %d) + %d;\n", topcentre_r.modulus2, topcentre_r.offset2);
        fprintf(rdest, "      %% Hash table probe 2.\n");
        fprintf(rdest, "      v := land(w := getv32(topcentre_hash!*, h2), 0x7ffff);\n");
        fprintf(rdest, "      if not (v = key) then return 0 >>;\n");
        fprintf(rdest, "    return lshift(w, -21)\n");
        fprintf(rdest, "  end;\n");
        fprintf(rdest, "\n");
        fprintf(rdest, "end;\n\n");
        fprintf(rdest, "%% end of charmetrics.red\n");
        fclose(dest);
        fclose(rdest);
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

#define CHAR_METRICS_TABLE_SIZE (sizeof(charmetrics)/sizeof(charmetrics[0]))

int c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo;

int lookupchar(int fontnum, int codepoint)
{
    int fullkey = pack_character(fontnum, codepoint); // 21-bit key
    int key = fullkey >> 2; // because my hash table has line-size 4
    int v, h1, h2;
    uint64_t w;
    h1 = key % CHAR_METRICS_TABLE_SIZE;
    v = (int)charmetrics[h1][0] & 0x7ffff;
    if (v != key)
    {   h2 = (key % CHAR_METRICS_MODULUS) + CHAR_METRICS_OFFSET;
        v = (int)charmetrics[h2][0] & 0x7ffff;
        if (v != key)
        {   h1 += h2;
            if (h1 >= CHAR_METRICS_TABLE_SIZE) h1 -= CHAR_METRICS_TABLE_SIZE;
            v = (int)charmetrics[h1][0] & 0x7ffff;
            if (v != key) return 0;
        }
    }
    w = charmetrics[h1][1+(fullkey&3)];
// Even though the hash line exists this entry in it may be unused.
    if (w == 0) return 0;
    c_width = (int)(w >> 51) & 0x1fff;
    c_llx = ((int)(w >> 38) & 0x1fff) - 3000;
    c_lly = ((int)(w >> 26) & 0x0fff) - 1000;
    c_urx = ((int)(w >> 13) & 0x1fff) - 500;
    c_ury = ((int)w & 0x1fff) - 1000;
// Based on the font and 11 bits of information from the hash table I will
// set up a pointer into kerntable. The interpretation of that will be
// considered in the function lookupkernandligature. If the 11 bit field
// contains zero then there is neither kern nor ligature information
// associated with this character.
    v = (int)(charmetrics[h1][0] >> (19+11*(fullkey&3))) & 0x7ff;
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
//      lookupkernandligature(codepoint_for_second_character);
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
//
// I provide variants that collect just kern or just ligature information.

int32_t lookupkernandligature(int codepoint)
{
    int32_t r = 0;
    uint32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
// The worst cases I can see in my fonts is the kern information for "W"
// in STIX-Regular where around 50 characters following "W" get their spacing
// adjusted. That gives some impression of the most extreme number of
// times this loop will be traversed. For many characters there will be no
// kern information at all, and when there is any it will usually be
// pretty limited so average costs here should end up low.
    do
    {   w = kerntable[i++];
// The kern table contains a sequence of 32-bit words. The low 21 bits of
// each is a codepoint being the second character of a pair. The next two
// bits are flags. One indicates whether the word is documenting kern or
// ligature information. The other marks the final word of information
// relating to a lead character. That leaves 9 bits. For kern information
// that is a 9-bit signed spacing adjustment. For ligatures it is a
// 9 bit unsigned index into a table of codepoints giving the single
// character to be used to replace the initial pair. Note that one pair
// of characters can (and often well!) have both kern and ligature information
// which is why the return value here can hand back both and why searching
// continues through all information about the relevant pair. It would be a
// MESS if the tables included two entries for the same character pair but
// yielding different results! I ought to police that while creating the
// tables.
// Because w is an unsigned value I do not need to mask the result of the
// right shift.
        if ((w & 0x001fffff) == codepoint)
        {   if ((w & IS_LIGATURE) != 0) r |= ligaturetable[w >> 23];
            else r |= (w & 0xff800000);
        }
    } while ((w & IS_BLOCKEND) == 0);
    return r;
}

// Much the same as the above but ONLY looks for kern information and returns
// its result as a simple integer. In case kern information is found this
// is just slightly faster than using the more general method.

int32_t lookupkernadjustment(int codepoint)
{
    int32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
    do
    {   w = kerntable[i++];
// The shift right in the return statement relies on w being a signed
// value and on signed shifts being arithmetic.
        if ((w & 0x001fffff) == codepoint &&
            (w & IS_LIGATURE) == 0) return (w >> 23);
    } while ((w & IS_BLOCKEND) == 0);
    return 0;
}

// Much the same as the above but ONLY looks for ligature information.

int32_t lookupligature(int codepoint)
{
    uint32_t w;
    int i;
    if ((i = c_kerninfo) == 0) return 0;  // No info based on current start.
    do
    {   w = kerntable[i++];
// I made w unsigned so that the shift right returned an unsigned index.
        if ((w & 0x001fffff) == codepoint &&
            (w & IS_LIGATURE) != 0) return ligaturetable[w >> 23];
    } while ((w & IS_BLOCKEND) == 0);
    return 0;
}

#define TOPCENTRE_TABLE_SIZE (sizeof(topcentre)/sizeof(topcentre[0]))

int accentposition(int code)
{
    int hash1 = code % TOPCENTRE_TABLE_SIZE, hash2;
    int32_t r;
    if (((r = topcentre[hash1]) & 0x001fffff) == code) return ((int32_t)r)>>21;
    hash2 = (code % TOPCENTRE_MODULUS) + TOPCENTRE_OFFSET;    
    if (((r = topcentre[hash2]) & 0x001fffff) == code) return ((int32_t)r)>>21;
    else return 0;
}

#ifdef TEST
// If TEST is defined then this code will try some very minimal tests.
// Expected output is
//
//    Hash table size was 10xxx
//    "e": width 444   BB 25 -10 424 460  (xxx)
//    "f": width 333   BB 20 0 383 683  (xxx)
//    "g": width 500   BB 28 -218 470 460  (xxx)
//    "h": width 500   BB 9 0 487 683  (xxx)
//    "i": width 278   BB 16 0 253 683  (xxx)
//    "j": width 278   BB -70 -218 194 683  (0)
//    "k": width 500   BB 7 0 505 683  (xxx)
//    "l": width 278   BB 19 0 257 683  (xxx)
//    "m": width 778   BB 16 0 775 460  (xxx)
//    Kern/ligature data for sequence f-i is 14 64257
//    Kern/ligature data for sequence f-l is 44 64258
//
// The last two lines say that if in font STIX-Regular an "f" is
// followed by an "i" then either the two may have their spacing adjusted
// by 14 units or the pair may be replaced by the character at codepoint
// 64257 (which is "fi")... and similarly for "f" followed by "l". The output
// higher up tells us that in this font there are no kerning involving
// a "j" followed by something else, while the (xxx) values are offsets
// into a table of kerning information. "BB" is for "Bounding Box" and the
// four numbers are for lower-left-x, lower-left-y, upper-right-x and
// upper-right-y in that order.
// Where the above sample output shows "xxx" that stands for numeric values
// that depend in delicate ways on everything but should not influence eventual
// useful output.

int main(int argc, char *argv[])
{
    int i, r;
    printf("====== Test program starting ======\n");
    printf("Hash table size was %d\n", (int)CHAR_METRICS_TABLE_SIZE);
    printf("Second modulus, offset %d (%d)\n", (int)CHAR_METRICS_MODULUS,
                                               (int)CHAR_METRICS_OFFSET);
    for (i='e'; i<'n'; i++)
    {   r = lookupchar(F_Regular, i);
        if (r) printf("\"%c\": width %d   BB %d %d %d %d  (%d)\n",
                      i, c_width, c_llx, c_lly, c_urx, c_ury, c_kerninfo);
        else printf("\"%c\" char not found\n", i);
        fflush(stdout);
    }
    if (!lookupchar(F_Regular, 'f')) printf("Character \"f\" not found\n");
    else
    {   int32_t k = lookupkernandligature('i');
        printf("Kern/ligature data for sequence f-i is %d %d\n",
               (int)(k >> 23), (int)(k & 0x001fffff));
        fflush(stdout);
        k = lookupkernandligature('l');
        printf("Kern/ligature data for sequence f-l is %d %d\n",
               (int)(k >> 23), (int)(k & 0x001fffff));
        fflush(stdout);
    }
    return 0;
}


#endif // TEST
#endif // CREATE

// end of charmetrics.c
