//
// "FXShowMath.cpp"                       Copyright A C Norman 2004-2007
//
//
// Code to layout mathematical formulae for display. Formulae are
// described in a TeX-like style. This REQUIRES some Computer Modern
// typefaces to be available.
//

/******************************************************************************
* Copyright (C) 2004-8 by Arthur Norman, Codemist Ltd.   All Rights Reserved. *
*******************************************************************************
* This library is free software; you can redistribute it and/or               *
* modify it under the terms of the GNU Lesser General Public                  *
* License as published by the Free Software Foundation;                       *
* version 2.1 of the License.                                                 *
*                                                                             *
* This library is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU           *
* Lesser General Public License for more details.                             *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public            *
* License along with this library; if not, write to the Free Software         *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.  *
*                                                                             *
* I had intended to permit this code to be used subject to the FOX addendum   *
* that permits static linking, but that is not feasible given the non-        *
* transitive nature of that addendum, hence this has to be under just LGPL.   *
******************************************************************************/

// However as a special exception to LGPL 2.1 I grant permission for my code
// to be merged or linked with other code that is subject to LGPL version 3
// or GPL version 3. This provision does not represent permission to alter the
// license of my code to be that of LGPL 3 or GPL 3 - of itself and when
// removed from any LGPL 3 context it remains LGPL 2.1 and the freedom
// enshrined by that can not be reduced by adding in the additional
// constraints that LGPL 3 views as protections. However clearly the combined
// work that then includes my work would be subject to "3". But as per LGPL
// 2.1 (and the same would be true if I had used a BSD-style license here)
// notices explaining the license terms related to my code should not be
// removed. Anybody who changes or extends my code is permitted but not
// obliged to apply this exception, and perhaps by doing do they do not lock
// out (L)GPL 3 users but guarantee continued support for (L)GPL 2.1 in a way
// that the "or later" clause does not (since that permits anybody to
// unilaterally select just one version of the library to use, to the
// potential detriment of those whose choice differs).


/* Signature: 0fc4b886 04-May-2009 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#define WINVER 0x0500
#define _WIN32_WINNT 0x0500
#endif

#ifdef WIN32
#include <windows.h>
#else
#ifdef HAVE_XFT_H
#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>
#else
#error On non-Windows systems I need Xft.
#endif
#endif

#include "fwin.h"
#include <fx.h>

#if FOX_MAJOR==1 && FOX_MINOR==0
#  define FXSEL(a,b) MKUINT(a,b)
#endif

#include <fxkeys.h>          // not included by <fx.h>

#include "FXTerminal.h"
#include "FXShowMath.h"
#include "FXDCNativePrinter.h"

#include <stdlib.h>

extern "C" {
extern int directoryp(char *a, char *b, size_t n);
extern int file_readable(char *a, char *b, size_t n);
}

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include "fwin.h"

namespace FX {

static int DEBUGFONT = 0;

// I make the size of my memory pool depend on the size of a pointer
// because the size of box components depends on that. The setting here
// will use 128K on a 32-bit machine or 256K on a 64-bit one and will
// cache around say 80 full lines of maths display. Beyond that the
// system would need to re-parse for redisplay.

#define memoryPoolSize (0x4000*sizeof(void *))

static void *memoryPool = NULL;
static unsigned int memoryPoolIn, memoryPoolOut;

int handleFromPoolPointer(Box *p)
{
    return (int)((char *)p - (char *)memoryPool);
}

Box *poolPointerFromHandle(int i)
{
    return (Box *)((char *)memoryPool + i);
}

static void setupMemoryPool()
{
    memoryPool = (void *)new char[memoryPoolSize];
    if (memoryPool == NULL)
    {   printf("Failed to allocate memory\n");
        exit(1);
    }
    memoryPoolIn = memoryPoolOut = 0;
}

static void poolDestroyChunk();

static void *poolAllocate(unsigned int n)
{
    if (n >= memoryPoolSize) return NULL;
    for (;;)
    {   int spare = memoryPoolOut - memoryPoolIn;
        if (spare <= 0) spare += memoryPoolSize;
        if (n < (unsigned int)spare) break;
        poolDestroyChunk();
    }
    unsigned int next = memoryPoolIn + n;
    if (next > memoryPoolSize)
    {   while (memoryPoolOut > memoryPoolIn) poolDestroyChunk();
        memoryPoolIn = 0;
        while (memoryPoolOut <= n) poolDestroyChunk();
        next = n;
    }
    void *r = (void *)((char *)memoryPool + memoryPoolIn);
    memoryPoolIn = next;
    return r;
}

struct IntVoidStar
{
    void *v;
    int i;
};

static void *chunkStart;

// Memory for a single formula will live in a "chunk", and chunks run
// cyclically around a region of memory. If at any stage I try to make a
// new chunk grow so that it would wrap round and overlap an earlier-allocated
// one I will discard that earlier chunk. When I do so I notify its "owner"
// so that they will not rely on it after its demise.

static void *poolStartChunk(int owner)
{
    chunkStart = poolAllocate(sizeof(struct IntVoidStar));
    IntVoidStar *rp = (IntVoidStar *)chunkStart;
    rp->i = owner;
    rp->v = NULL;
    return chunkStart;
}

static void poolEndChunk()
{
    IntVoidStar *rp = (IntVoidStar *)chunkStart;
    rp->v = (void *)((char *)memoryPool + memoryPoolIn);
}

static void poolDestroyChunk()
{
    if ((void *)((char *)memoryPool + memoryPoolOut) == chunkStart)
    {   printf("Attempt to create over-large chunk\n");
        exit(1);
    }
    IntVoidStar *rp = (IntVoidStar *)((char *)memoryPool + memoryPoolOut);
    reportDestroy(rp->i); // inform owner
    memoryPoolOut = (int)((char *)rp->v - (char *)memoryPool);
}

typedef struct TexState
{
    unsigned char currentFont;
    unsigned char insideFrac;
} TeXState;

TeXState currentState;

#define currentSize (currentState.currentFont & FontSizeMask)


// Some types. I have capacity in my encoding for up to 16 types of box.

#define BoxText        0x00
#define BoxNest        0x01
#define BoxNest3       0x02
#define BoxSym         0x03
#define BoxBracket     0x04
#define BoxMatrix      0x05
#define BoxFrame       0x06
#define BoxTop         0x07

#define NestMask       0xf0  // I use 0x0c bits for size information...
#define BoxTower       0x00  // one item over another, does not centre items
#define BoxStack       0x10  // one item over another, centred
#define BoxFraction    0x20  // one item over another, centred & with f-bar
#define BoxBeside      0x30
#define BoxAdjacent    0x40  // just like Beside, but moves boxes closer
#define BoxSubscript   0x50
#define BoxSuperscript 0x60
#define BoxBothScripts 0x70
#define BoxOverstrike  0x80
#define BoxPadSpace    0x90

#define SymTypeMask    0xf0
#define SymStar        0x00
#define SymComma       0x10
#define SymExclam      0x20
#define SymColon       0x30
#define SymSemiColon   0x40
#define SymBlank       0x50
#define SymNothing     0x60
#define SymUnderscore  0x70
#define SymRule        0x80

static Box *makeSymBox(int type)
{
    Box *b = (Box *)poolAllocate(sizeof(SymBox));
    b->text.type = BoxSym;
    b->text.flags = type + currentSize;
    b->text.height = 0;
    b->text.depth = 0;
    b->text.width = 0;
    return b;
}

Box *makeTextBox(const char *s, int n, int fontStyle)
{
    char *ss = (char *)poolAllocate(n+1);
    Box *b = (Box *)poolAllocate(sizeof(TextBox));
    memcpy(ss, s, n+1);
    b->text.type = BoxText;
    b->text.flags = fontStyle;
    b->text.height = 0;
    b->text.depth = 0;
    b->text.width = 0;
    b->text.n = n;
    b->text.text = ss;
    return b;
}

static Box *makeBracketBox(Box *b1, char left, char right)
{
    Box *b = (Box *)poolAllocate(sizeof(BracketBox));
    b->bracket.type = BoxBracket;
    b->bracket.flags = currentSize;
    b->bracket.height = 0;
    b->bracket.depth = 0;
    b->bracket.width = 0;
    b->bracket.sub = b1;
    b->bracket.leftBracket = left;
    b->bracket.rightBracket = right;
    b->bracket.dx = 0;
// \sqrt[n] will fill in any extra by hand...
    b->bracket.dx1 = 0;
    b->bracket.dy1 = 0;
    b->bracket.sub1 = NULL;
    return b;
}

static Box *makeMatrixBox(Box *b1)
{
    Box *b = (Box *)poolAllocate(sizeof(MatrixBox));
    b->matrix.type = BoxMatrix;
    b->matrix.flags = currentSize;
    b->matrix.height = 0;
    b->matrix.depth = 0;
    b->matrix.width = 0;
    b->matrix.sub = b1;
    b->matrix.dy = 0;
    return b;
}

static Box *makeNestBox(int style, Box *b1, Box *b2)
{
    Box *b = (Box *)poolAllocate(sizeof(NestBox));
    b->nest.type = BoxNest;
    b->nest.flags = style + currentSize;
    b->nest.height = 0;
    b->nest.depth = 0;
    b->nest.width = 0;
    b->nest.sub1 = b1;
    b->nest.sub2 = b2;
    b->nest.dx1 = b->nest.dy1 = 0;
    b->nest.dx2 = b->nest.dy2 = 0;
    return b;
}

static Box *makeNest3Box(int style, Box *b1, Box *b2, Box *b3)
{
    Box *b = (Box *)poolAllocate(sizeof(NestBox3));
    b->nest3.type = BoxNest3;
    b->nest3.flags = style + currentSize;
    b->nest3.height = 0;
    b->nest3.depth = 0;
    b->nest3.width = 0;
    b->nest3.sub1 = b1;
    b->nest3.sub2 = b2;
    b->nest3.sub3 = b3;
    b->nest3.dx1 = b->nest3.dy1 = 0;
    b->nest3.dx2 = b->nest3.dy2 = 0;
    b->nest3.dx3 = b->nest3.dy3 = 0;
    return b;
}

static Box *makeFrameBox(Box *b0)
{
    Box *b = (Box *)poolAllocate(sizeof(FrameBox));
    b->frame.type = BoxFrame;
    b->frame.flags = currentSize;
    b->frame.height = 0;
    b->frame.depth = 0;
    b->frame.width = 0;
    b->frame.sub = b0;
    return b;
}

static Box *makeTopBox(Box *b0)
{
    Box *b = (Box *)poolAllocate(sizeof(TopBox));
    b->top.type = BoxTop;
    b->top.flags = currentSize;
    b->top.height = 0;
    b->top.depth = 0;
    b->top.width = 0;
    b->top.sub = b0;
    b->top.chunk = chunkStart;
    b->top.measuredSize = -1;
    return b;
}

///////////////////////////////////////////////////////////////////////////

// I will use (up to) 36 fonts here:
//               Roman, Maths-italic, Symbol, Extra
// with each in main, subscript and sub-subscript sizes, but with
// a range of possible scales

// I have a set of metrics for the Computer Modern fonts that I use. They
// were extracted from the associated "AFM" files, but converted into
// static C tables for quick access. The table does not provide full
// information - it gives bounding boxes for the font as a whole together
// with widths of individual characters. At least at present I do not record
// individual character heights or kerning information there.

#include "cmfont-info.c"

static cm_font_info *findFont(const char *name)
{
    char ss[32];
    strcpy(ss, name);
// The info in the table has names in upper case. So I will force the
// name in my request to be in upper case to match.
    for (char *p=ss; *p!=0; p++) *p = toupper(*p);
    for (unsigned int i=0; i<sizeof(cm_font_widths)/sizeof(cm_font_info); i++)
    {   if (strcmp(ss, cm_font_widths[i].name) == 0)
            return &cm_font_widths[i];
    }
    return NULL;
}


// The master set of fonts, covering all scales. I extract relevant
// into into mathFont etc as necessary. If printDC is not NULL I will
// suppose I am in the middle of printing something and will use it, rather
// then the screen-access procedures that I normally use. In the printDC
// case I will use real local fonts in a Windows case when I am printing
// to a windows printing device context, but when using ANY sort of system
// if I am trying to generate Postscript I will use AFM metrics for the
// mathematical fonts that I want. In such case I will want the "font" to
// be a reference to the metric tables together with some scale information.

// @@@@ I will work on WINDOWS printing first... and assume that under Windows
// I am necessarily using a direct printer device context...

FXDCNativePrinter *printDC = NULL;

int mathFontSize = -1;
void       *masterFont[36];
static int masterFontHeight[36];
static int masterFontDepth[36];
static int masterFontWidth[36];
static cm_font_info *masterFontFontInfo[36];

// At one stage I took the view that if Xft was available and detected by
// the autoconf stuff I would allow the user to choose whether to take
// advantage of it. Now instead I will take the view that on non-Windows
// platforms I REALLY want it to be available and if it is I will always
// use it.

// The array "font" will either hold FXFont or XftFont references
// depending on whether autoconf detected Xft as present. The arrays and
// variables here relate to the fonts in use at the current scale.

void       *mathFont[12];
int mathWidth;
static int mathFontHeight[12];
static int mathFontDepth[12];
static int mathFontWidth[12];
static cm_font_info *mathFontFontInfo[12];

// Short-hand to reference individual fonts.

#define frm   mathFont[FntRoman+FntRegular]
#define fmi   mathFont[FntItalic+FntRegular]
#define fsy   mathFont[FntSymbol+FntRegular]
#define fex   mathFont[FntExtension+FntRegular]
#define fsrm  mathFont[FntRoman+FntScript]
#define fsmi  mathFont[FntItalic+FntScript]
#define fssy  mathFont[FntSymbol+FntScript]
#define fsex  mathFont[FntExtension+FntScript]
#define fssrm mathFont[FntRoman+FntScrScr]
#define fssmi mathFont[FntItalic+FntScrScr]
#define fsssy mathFont[FntSymbol+FntScrScr]
#define fssex mathFont[FntExtension+FntScrScr]

///////////////////////////////////////////////////////////////////////////

// When I select a font I want the version from that family that
// has design-size best matched to the size that it will appear.
// The scheme here recognises the variants made available with the
// Computer Modern set and selects what to use. I do things in an
// elaborate manner on Windows, but elsewhere I will just use the
// standard size versions of the fonts (which are scalable)

#ifdef WIN32

static const char *cmrSizesTable[] =
{   NULL, NULL, NULL, NULL, NULL,                    // for sizes 0,1,2,3,4
    "cmr5", "cmr6", "cmr7", "cmr8", "cmr9",          // 5, 6, 7, 8, 9
    "cmr10", "cmr10", "cmr12", "cmr12",              // 10, 11, 12, 13
    "cmr12", "cmr12"                                 // 14, 15
};

#define cmrSize(n) ((n)<5 ? "cmr5" : \
                    (n) > 15 ? "cmr17" : cmrSizesTable[n])

static const char *cmmiSizesTable[] =
{   NULL, NULL, NULL, NULL, NULL,                    // for sizes 0,1,2,3,4
    "cmmi5", "cmmi6", "cmmi7", "cmmi8", "cmmi9",     // 5, 6, 7, 8, 9
    "cmmi10", "cmmi10"                               // 10, 11
};

#define cmmiSize(n) ((n)<5 ? "cmmi5" : \
                     (n) > 11 ? "cmmi12" : cmmiSizesTable[n])

static const char *cmsySizesTable[] =
{   NULL, NULL, NULL, NULL, NULL,                    // for sizes 0,1,2,3,4
    "cmsy5", "cmsy6", "cmsy7", "cmsy8", "cmsy9"      // 5, 6, 7, 8, 9
};

#define cmsySize(n) ((n)<5 ? "cmsy5" : \
                     (n) > 9 ? "cmsy10" : cmsySizesTable[n])

#define cmexSize(n) "cmex10"

#else

#define cmrSize(n) "cmr10"
#define cmmiSize(n) "cmmi10"
#define cmsySize(n) "cmsy10"
#define cmexSize(n) "cmex10"

#endif

#ifndef WIN32

// At some stage I may well move all of these to be fields within a
// suitable object, but while I only have ONE window on which I will
// display things using Xft I can make them simple static varaible and hence
// fairly local to this file. But I will give them C linkage to make
// access from code outside easier.

extern "C" {

extern Display      *dpy;
extern int          screen;
extern XftDraw      *ftDraw;
extern Visual       *ftVisual;
extern Colormap     ftColormap;
extern XRenderColor ftRenderBlack;
extern XRenderColor ftRenderWhite;
extern XftColor     ftBlack, ftWhite;
extern XftFont      *ftFont;

Display      *dpy = NULL;
int          screen;
XftDraw      *ftDraw = NULL;
Visual       *ftVisual = NULL;
Colormap     ftColormap;
XRenderColor ftRenderBlack = {0x0000, 0x0000, 0x0000, 0xffff};
XRenderColor ftRenderWhite = {0xffff, 0xffff, 0xffff, 0xffff};
XftColor     ftBlack, ftWhite;
XftFont      *ftFont = NULL;

}

#endif

static void *getMathsFont(FXApp *app,
                          const char *name, const char *fallback,
                          int size)
{
#ifdef WIN32
    FXFontDesc fd;
    FXFont *f;
    FXString an;
    for (int i=0;i<2;i++)
    {
// If I do not have Xft I am probably on Windows. In that case I will
// first try to access a font such as cmr7 or cmr12 that has exactly the
// design size I want, and if that fails I will fall back to scaling
// based on cmr10. That could allow me to have a full range of high quality
// bitmapped fonts.
        strcpy(fd.face, i==0 ? name : fallback);
        fd.size = size;                    // NB size is in DECIPOINTS here
        fd.weight = 0;
        fd.slant = 0;
        fd.setwidth = 0;
        fd.encoding = FONTENCODING_DEFAULT;
        fd.flags = 0;
        f = new FXFont(app, fd);
        f->create();
// Now I check that the "actual name" bears at least some resemblence
// to the name asked for... and if not I ask the user to install
// fonts properly. Note that there is a fallback font-name to use.
        char ucname[32], ucactual[32];
        strcpy(ucname, fd.face);
        an = f->getActualName();
        strcpy(ucactual, an.text());
        char *p;
        for (p=ucname; *p!=0; p++) *p = toupper(*p);
        for (p=ucactual; *p!=0; p++) *p = toupper(*p);
        if (strncmp(ucname, ucactual, strlen(ucname)) == 0) return f;
        delete f;
    }
// This is an error exit and ought never to occur!
    return NULL;
#else
// With Xft I do not seem to have a good way to check exactly what
// font gets found, and so to try to guarantee the best sanity I can I have
// only got here if I was able to add the custom fonts that I wanted. And
// I then use my "fallback" font name here, which is the one that the
// custom fonts were intended to provide. Thus with Xft I will use exactly
// cmr10, cmmi10, cmsy10 and cmex10 and NEVER Computer Modern fonts at any
// other size.
    char xname[32];
// As part of trying to ensure that MY version of the fonts get used I have
// renamed them as eg csl-reduce-cmmi10.
    sprintf(xname, "csl-reduce-%s", fallback);
    return XftFontOpen(dpy, screen,
                       XFT_FAMILY, XftTypeString, xname,
                       XFT_SIZE,   XftTypeDouble, 0.1*(double)size,
                       (const char *)0);
#endif
}

#if 0

static void showMetrics(int ch, void *ff)
{
// This uses  FOX calls to measure characters. The results come back in
// screen coordinates, which are typically pixels. At present this is ONLY
// used for debugging!
    char b[2];
    b[0] = ch;
#ifdef WIN32
// NB this does not cope with char codes > 0x7f at present...
    if (printDC==NULL)
    {   printf("Char %.2x font %p height = %d depth = %d width = %d\n",
             ch, ff,
             ((FXFont *)ff)->getTextHeight(b, 1),
             ((FXFont *)ff)->getFontDescent(),
             ((FXFont *)ff)->getTextWidth(b, 1));
    }
    else
    {   printDC->setFont((FXFont *)ff);
        printf("Char %.2x font %p height = %d depth = %d width = %d\n",
             ch, ff,
             (int)printDC->fntGetTextHeight(b, 1),
             (int)printDC->fntGetFontDescent(),
             (int)printDC->fntGetTextWidth(b, 1));
    }
#else
    if (printDC==NULL)
    {   printf("showMetric not done for Xft yet\n");
        return;
    }
#endif
    fflush(stdout);
}

#endif

#if 0

// The next function may not be used right now, but when I start
// developing the Postscript printer support I will need it to help me
// debug things...

static void showAFMMetrics(int ch, int fn)
{
// This used the AFM data to try to compute sizes. The results are returned
// in points not pixels, and so are NOT compatible with the ones above. In
// particular scaling by a "pixels per point for this screen" would be
// needed to make them agree. At present if I apply such a scaling (by hand)
// I think that widths then match, but I am still confused about heights and
// depths. Only used for debugging at present.
    cm_font_info *fi = masterFontFontInfo[fn];
    int cap=fi->capheight, x=fi->xheight,
        asc=fi->ascent, desc=fi->descent;
    int w = fi->charwidth[ch & 0xff];
    printf("Char %.2x font %x2 capH=%d xH=%d ascent=%d descent=%d width=%d\n",
         ch, fn, cap, x, asc, desc, w);
    fflush(stdout);
}

#endif

// LONGEST_LEGAL_FILENAME is a distinct HACK, and although on early versions
// of Windows there was a limit, with XP at least very long file paths are
// possible - and by exceeding this limit they could cause crashes. Tough
// Luck for now!

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

typedef struct localFonts
{
    const char *name;
    char *path;
} localFonts;

static localFonts fontNames[] =
{
    {"cmex10", NULL},
    {"cmmi10", NULL},
    {"cmr10",  NULL},
    {"cmsy10", NULL}
};

#ifdef WIN32
// The next two flags instruct AddFontResourceEx that a font should be
// available only to this application and that other application should
// not even be able to see that it exists. I provide definitions here
// in case MinGW32 does not have them in its header files.

#ifndef FR_PRIVATE
#define FR_PRIVATE   0x10
#endif

#ifndef FR_NOT_ENUM
#define FR_NOT_ENUM  0x20
#endif

#define PRIVATE_FONT (FR_PRIVATE | FR_NOT_ENUM)

static int fontNeeded = 0;

// This callback is used so that I can detect if a font is already
// available.

static int CALLBACK fontEnumProc(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
    fontNeeded = 0;
    return 0;
}

#else

// On non-Windows platforms and for murky reasons I need to use an
// adjusted character encoding. Well part of the murk is that there is
// a problem over the character with code 0, which some X11 systems seem
// unwilling to display.

static FT_UInt glyphs[100];

static int unmap(int ch);

static int convertGlyphs(const char *s, int len)
{
    if (len > 100) len = 100;
    for (int i=0; i<len; i++)
        glyphs[i] = (unmap(s[i]) & 0xff) + 1;
    return len;
}

static int xfWidth(void *ff, const char *s, int len)
{
    XGlyphInfo w;
    len = convertGlyphs(s, len);
    XftGlyphExtents(dpy, (XftFont *)ff, glyphs, len, &w);
// Observe that I believe that I want xOff, the "advance" figure, rather
// than width here.
    return w.xOff;
}

#endif

/*
 * The macro fontdsir must be the name of the fonts directory, and it
 * will typically be "reduce.fonts" but is is passed down by the
 * Makefile.
 */

#ifndef fontsdir
#define fontsdir reduce.fonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

// Returns NULL if all is well, else it may return an error string.

static char *loadPrivateFonts(FXApp *appl, FXWindow *w)
{
    for (int i=0; i<12; i++) mathFont[i] = NULL;
    for (int i=0; i<36; i++) masterFont[i] = NULL;
// I want to ensure that the fonts needed will be available. On both
// Windows and X11 there are awkwardnesses about this:
// [Windows] AddFontResourceEx is only available on NT, 2000, XP, not
//           on earlier systems.
//           AddMemFontResource can only add TrueType fonts, and also
//           does not support older systems.
//           Two nuisances emerge from this. (a) the font resources
//           have to be in the form of a set of file on disc; (b) the
//           fonts that I temporarily install will be visible to and
//           enumerable by all other applications.
//           I will no longer worry about versions of Windows before XP so
//           I will not count this as a worry.
// [X11]     A really very much want to have some of the Computer Modern
//           maths fonts available to me. Because with X there is a logical
//           distinction between the X server and client, using traditional
//           X would mean that I would HAVE To have those fonts installed on
//           the server - which is remote from the client upon which my code
//           runs. So I will use Xft and the Render extension to do client-
//           side rendering. This is a fairly recent development in X and
//           so may not always be available. Also it puts extra communication
//           load on the client-server link so may not be nice when using
//           a slow network. Font naming under Xft/fontconfig is very
//           different from the older model, and my code here only attempts
//           to access my own private Truetype/Type1 version of the CM fonts,
//           where I have taken trouble to ensure that their Truetype names
//           are set in the way I want them to be.
//           I seem to be having some delicacies about character encoding
//           and Xft. I work around this by assuming that the fonts I will
//           use with Xft are JUST the ones that I supply, and I then use
//           Glyph rather than Text access. BEWARE that trying to use
//           fonts other than the ones I supply will cause trouble.
//
// My private font directory contains just 4 fonts
//    cmr10   cmmi10   cmsy10   cmex10
// BUT when I am going to display things on the screen and unless I am
// using Xft I will try to use any from
//      cmr5, 6, 7, 8, 9, 10, 12, 17
//      cmmi5, 6, 7, 8, 9, 10, 12
//      cmsy5, 6, 7, 8, 9, 10
//      cmex10
// which come in the AMS set of Computer Modern Fonts, which can be
// downloaded freely either directly from AMS or from any major TeX
// archive. So if those extended fonts are installed you may get slightly
// more refined presentation on some platforms.
//
#ifdef WIN32
    HDC hDC = CreateCompatibleDC(NULL);
    LOGFONT lf;
// I check each of the fonts that this application wants to see if they
// are already installed. If they are then there is no merit in installing
// them for myself.
    int newFontAdded = 0;
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   strcpy(lf.lfFaceName, fontNames[i].name);
        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = 0;
        fontNeeded = 1;
        fontNames[i].path = NULL;
        EnumFontFamiliesEx(hDC, &lf, fontEnumProc, 0, 0);
        if (!fontNeeded) continue;
        char *ff = new char [strlen(programDir) +
                             strlen(fontNames[i].name) +
                             strlen(toString(fontsdir)) + 8];
        strcpy(ff, programDir);
        strcat(ff, "\\" toString(fontsdir) "\\");
        strcat(ff, fontNames[i].name);
        strcat(ff, ".ttf");
        DWORD attributes = GetFileAttributes(ff);
        if (attributes != INVALID_FILE_ATTRIBUTES &&
            (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
        {   fontNames[i].path = ff;
            if (AddFontResourceExA(ff, PRIVATE_FONT, 0) == 0)
            {   continue;
            }
            newFontAdded = 1;
        }
    }
    DeleteDC(hDC);
// Broadcasting the presense of new fonts cam sometimes cause a delay
// that is longer than I really like. If I am the only person who is
// going to use the new fonts do I need it? Possibly not!
#if 0
    if (newFontAdded) SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
#endif
    return NULL;
#else // WIN32
    ftDraw = NULL;
// I have a real worry about FcInit because at least on some systems
// it appears to cause big delays - eg on a (not especially fast) Mac running
// Tiger this led to a pause of around 15 seconds, all of which was CPU
// intensive. My hypothesis is that this was because the machine had many
// many fonts to scan, but perhaps I have something plain wrong...
// Further experiment shows at least on one machine a delay of several minutes
// (all eating CPU time) when I FIRST tried to run my code, but startup being
// faster on subsequent occasions. I need to ask people who use Macintosh
// machines (and perhaps others) to be really patient! And while they are
// waiting to work out what the hang-up is and how it can be cured.
    FcInit();
    XftInit("");
    dpy = (Display *)appl->getDisplay();
    screen = DefaultScreen(dpy);

// I will add in the four font files that I want to use here. Note that
// with Xft I will force use of the ".pfb" versions. These are close to
// BUT NOT IDENTICAL TO the original AMS Type1 Computer Modern fonts.
// It is important to use MY versions of the fonts here.
    int someAdded = 0;
    for (int i=0; i<4; i++)
    {   char *fff = (char *)
            new char[20+strlen(programDir)+strlen(fontNames[i].name)];
        char ff1[LONGEST_LEGAL_FILENAME];
        if (fff == NULL) return "failed to allocate space";
        sprintf(fff, "%s/" toString(fontsdir) "/%s.pfb",
                programDir, fontNames[i].name);
// For Xft I will insist that ALL the fonts that I try to add have
// readable font file and are accepted by AppFontAdd, otherwise I will
// suppose that Xft is not usable.
//
// Now there is an oddity here. The FontConfig documentation says that I should
// be able to pass zero anywhere where I use a Configuration, but when I tried
// that on a Mac (with maybe an old version of fontconfig?) it seemed to crash
// and passing the current configuration explicitly seemed to make things
// better.
        if (!file_readable(ff1, fff, strlen(fff)) ||
            !FcConfigAppFontAddFile(FcConfigGetCurrent(),
                                    (const FcChar8 *)fff))
            return " not readable or FcConfigAppFontAddfile failed";
        else someAdded = 1;
    }
// ensure that fonts are really available. If I do not actually add any
// I will not fuss about this!
//
// Well with the attempts at maths display behaviour if I do not manage
// to add my custom fonts is liable to be a disaster!
    if (someAdded && !FcConfigBuildFonts(FcConfigGetCurrent()))
        return "FcConfigBuildFonds failed";
// I now have some confidence that the fonts that I want will be available
// to me. Well at least if the local font files existed!

#ifdef DEBUG_LIST_AVAILABLE_FONTS
    for (int i=0; i<4; i++)
    {   XftFontSet *fs = XftListFonts(dpy, screen,
//               XFT_FAMILY,  XftTypeString, fontNames[i].name,
                 (const char *)0, 
                 XFT_STYLE, XFT_FILE, XFT_ENCODING,
                 (const char *)0);
        if (fs->nfont == 0)
        {   XftFontSetDestroy(fs);
// Here at least one of the fonts that I ought to have in the reduce.fonts
// directory does not seem to be available.
            return "desired font not found";
        }
        for (int j=0; j<fs->nfont; j++)
            FcPatternPrint(fs->fonts[j]);  // To help me debug
        XftFontSetDestroy(fs);
    }
#endif // DEBUG_LIST_AVAILABLE_FONTS

    ftVisual = DefaultVisual(dpy, screen);
    ftColormap = DefaultColormap(dpy, screen);
// I really want the id() of the things that actually gets drawn on...
    Drawable draw = (Drawable)(w->id());
    ftDraw = XftDrawCreate(dpy, draw, ftVisual, ftColormap);
    XftColorAllocValue(dpy, ftVisual, ftColormap, &ftRenderBlack, &ftBlack);
    XftColorAllocValue(dpy, ftVisual, ftColormap, &ftRenderWhite, &ftWhite);
    return NULL;
#endif // WIN32
}

static double scaleTable[9] =
{
    1.0,
    1.1892,
    1.4142,
    1.6818,
    2.0,
    2.3784,
    2.8282,
    3.3636,
    4.0
};

// this returns 0 if it fails.

int changeMathFontSize(FXApp *appl, int mainSize)
{
    void *previousFont[36];
// I keep the current fonts until I have managed to open a new set, This
// may use up extra memory etc but is done so I can fall-back to retaining
// the existing set if something fails.
    for (int i=0; i<36; i++)
        previousFont[i] = masterFont[i];
// The user can pass a "main size" explicitly (in decipoints), but a negative
// argument instead specifies the width of the window, and I try to match
// that against 80 "M" in a half-sized font. The effect should be that SMALL
// mathematical formulae get displayed using a font that would fit around
// 40 of its widest characters across the screen, and around 60 or so
// "average width" chars. I think that seems reasonably visually pleasing...
    if (mainSize < 0)  // select font size based on screen width
    {   int sw = -mainSize;
#define probeSize 400
// I do things in two stages here, so I need to explain why!
// I first work in terms of a main font at 40 points and hence a "subscript"
// one at 28 points. I argue that at most plausible screen resolutions the
// width of an "M" here will be enough pixels that measurements will not be
// too badly corrupted by discretisation issues, and so I will end up with
// a prediction of the correct font size that will be accurate to within a
// reasonably small error. However if the user had a full set of CM fonts
// installed when I scale down and use a 7 or 10 point (say) script font then
// the version at small visual size is liable to have been designed to be
// thicker, so metrics got be just linear scaling from a 28-point version
// cen not be treated as reliable. However those simple measurements will
// still get me reasonably close. So I will measure again at that scale and
// make a final adjustment. I will NOT bother to iterate this procedure to
// convergence!
        mainSize = probeSize;
        int smallSize = (mainSize+1)/2;
        int smallWidth = 0;
        fsmi = getMathsFont(appl, cmmiSize(smallSize), "cmmi10", smallSize);
// At this stage all the existing fonts remain untouched.
        if (fsmi == NULL) return 0; // FAIL
#ifdef WIN32
        smallWidth = ((FXFont *)fsmi)->getTextWidth("MMMMMMMMMM", 10);
#else
        smallWidth = xfWidth(fsmi, "MMMMMMMMMM", 10);
#endif
        smallWidth *= 8; // width of 80 "M" in small font
        mainSize = (probeSize*sw)/smallWidth;
#ifdef WIN32
        delete (FXFont *)fsmi; // may leave bad font in printDC
#else
        XftFontClose(dpy, (XftFont *)fsmi);
#endif
        fsmi = NULL;
        smallSize = (mainSize+1)/2;
        fsmi = getMathsFont(appl, cmmiSize(smallSize), "cmmi10", smallSize);
// At this stage all the existing fonts remain untouched.
        if (fsmi == NULL) return 0;   // FAIL
#ifdef WIN32
        smallWidth = ((FXFont *)fsmi)->getTextWidth("MMMMMMMMMM", 10);
#else
        smallWidth = xfWidth(fsmi, "MMMMMMMMMM", 10);
#endif
        smallWidth *= 8; // width of 80 "M" in small font
        mainSize = (mainSize*sw)/smallWidth;
#ifdef WIN32
        delete (FXFont *)fsmi;
#else
        XftFontClose(dpy, (XftFont *)fsmi);
#endif
        fsmi = NULL;
    }
// I will insist that the main font be at least 10 point. Then at smallest
// scale I will have a regular size of 5pt. That would lead to
// scripts at 4pt and scripted scripts at 2.5pt. This is a pretty grossly
// tiny lower limit and if the smallest variation involved ever gets used
// it will not be readable. However I find that on a typical screen the
// size I need is around 13 points, not too far from this limit.
// NOTE that I work in decipoints here.

    if (mainSize < 100) mainSize = 100;

// Under Windows 2000/XP I make the maths fonts that I want available as
// private ones for this application. All existing fonts remain available at
// all times.
// Under Xft I have set up a special FontConfig context that has my
// custom fonts available in it.
//


// Having ensured that the fonts that I need are available I create
// the 36 maths fonts that I can possibly use. I provide a font name
// that would be my first choice, tuned to the visual size that is to be
// used (eg cmr7), and a fall-back name (always 10-point visual size)
// that I guarantee by providing it in my own font directory. Under Xft I
// do NOT try the perfection-size since I do not know a way to check how well
// it works: I always go straight for the 10-point versions that I explicitly
// added as application-specific things.

    int p = 0;
    for (int i=0; i<9; i++)
    {   int size = (int)(0.25*(double)mainSize*scaleTable[i] + 0.5);
        int height=0, depth=0, width=0;
        for (int j=0; j<4; j++)
        {   const char *targetName, *fallbackName;
            switch(j)
            {
        default:
        case 0: targetName = cmmiSize(size/10); fallbackName = "cmmi10"; break;
        case 1: targetName = cmrSize(size/10);  fallbackName = "cmr10";  break;
        case 2: targetName = cmsySize(size/10); fallbackName = "cmsy10"; break;
        case 3: targetName = cmexSize(size/10); fallbackName = "cmex10"; break;
            }
            masterFont[p] = getMathsFont(appl, targetName, fallbackName, size);
            if (masterFont[p] == NULL)
            {   while (--p >= 0)
                {   void *ff = masterFont[p];
#ifdef WIN32
                    delete (FXFont *)ff;
#else
                    XftFontClose(dpy, (XftFont *)ff);
#endif
                }
// Since opening fonts here failed I will restore the existing fonts, so that
// at least I have SOMETHING available to draw with.
                for (int i=0; i<36; i++)
                    masterFont[i] = previousFont[i];
                return 0;      // FAIL
            }
            masterFontFontInfo[p] = findFont(targetName);
// There will be places where I want to position items based on the
// general size of the fonts that are in use rather than the size of the
// particular glyphs involved. So I record an "X" height and an "M" width
// for my Italic font in each of the sizes that I use.
// For cmr, rmmi and cmsy this seems to give a reasonably consistent
// idea of sizes. I find the metric returned for cmex somewhat strange!
//
// The way that I want to measure things is with "height" measuring up from
// the baseline and "depth" measuring down from it. The metrics that FXFont
// gives me record overall height, so I adjust for that here.
// Observe I set up the "cmmi" font first so I can measure it and record
// its general metrics for all the other fonts.
            if (j==0)
            {
#ifdef WIN32
                depth = ((FXFont *)masterFont[p])->getFontDescent();
                height = ((FXFont *)masterFont[p])->getTextHeight("X", 1) - depth;
                width = ((FXFont *)masterFont[p])->getTextWidth("M", 1);
#else
                height = ((XftFont *)masterFont[p])->ascent;
                depth = ((XftFont *)masterFont[p])->descent;
                width = xfWidth(masterFont[p], "M", 1);
#endif
            }
            masterFontHeight[p] = height;
            masterFontDepth[p] = depth;
            masterFontWidth[p] = width;
            p++;
        }
    }
    setMathsFontScale(4);
    mathFontSize = mainSize;
// Since I have managed to open the new fonts I can discard the old ones.
    for (int i=0; i<36; i++)
    {
#ifdef WIN32
        delete (FXFont *)previousFont[i];
#else
// I will do some very magic things about font selection when I print to avoid
// problems here when Xft is around and I might otherwise get muddled between
// printer and screen font technology!
        if (previousFont[i] != NULL)
            XftFontClose(dpy, (XftFont *)previousFont[i]);
#endif
        previousFont[i] = NULL;
    }
    return 1;                       // OK!
}

// I have two interlocking ideas about font sizes. One is that for any
// formula I display I will have a Regular, Script and ScriptScript size
// of font, spanning a range of 2 in size. But as well as that I will want to
// be able to scale formulae to fit across the screen. If I always use a font
// that guarantees that even the largest formula would fit then generally
// everything looks cramped and tiny. So each set of 3 fonts will be made
// available in 5 scales: (1, 1.2, 1.4, 1.7, 2) where these will be selected
// so that "1.2" version expects 80 "M" to match my screen's width.
// changeMathsFontSize will set up the 9 fonts needed in each face
// (ie 1, 1.2, 1.4, 1.7, 2, 2.4, 2.8, 3.4, 4), while setMathsFontScale
// selects out the three that are to be used next. The argument to it
// should be 0, 1, 2, 3 or 4. Of these 4 is the default or preferred size and
// the smaller numbers are only used when formulae start to look too wide.

void setMathsFontScale(int scale)
{
    if (scale < 0) scale = 0;
    else if (scale > 4) scale = 4;
// In the master tables the arrangement is
//   cmmi, cmr, cmsy, cmex   0.5 (ie script-script)   0,1,2,3
//   cmmi, cmr, cmsy, cmex                            4,5,6,7
//   cmmi, cmr, cmsy, cmex   0.7 (ie script)          8,9,10,11
//   cmmi, cmr, cmsy, cmex                            12,13,14,15
//   cmmi, cmr, cmsy, cmex   1.0 (ie regular)         16,17,18,19
// in sizes tiny and so on upwards.
    int base = 4*scale;
    for (int i=0; i<3; i++)     // sizes
    {   for (int j=0; j<4; j++) // faces
        {   int x, y;
// Now I have the mess of mapping master to local font index info!
            x = j+4*i;
            y = (j==0?1: j==1?0 : j); // flip cmr and cmmi index values!
            y = base + 16 - 8*i + y;  // in mathFont biggest comes first!
            mathFont[x] = masterFont[y];
            mathFontHeight[x] = masterFontHeight[y];
            mathFontDepth[x] = masterFontDepth[y];
            mathFontWidth[x] = masterFontWidth[y];
            mathFontFontInfo[x] = masterFontFontInfo[y];
        }
    }
    mathWidth = mathFontWidth[FntItalic+FntRegular];
}

///////////////////////////////////////////////////////////////////////////

// This section measures boxes and thereby establish a layout.

static int intmax(int a, int b)
{
    return (a > b) ? a : b;
}

static int remap(int);

// This is intended to select a "bracket" (in other words "big delimiter")
// size measured in units of 0.5 the height of the smallest such delimiter
// in the cmex font. However there is a special case! For modest size
// formulae the code returns 1 which indicates "use a glyph from cmr or
// cmsy, rather than the one from cmex".

static int bracketCount(int flags, int height, int depth)
{
    int size = flags & FontSizeMask;
    int h = mathFontHeight[size], d = mathFontDepth[size];
    if (height<=h && depth<=d) return 1; // use simple cmsy or cmr glyph
    height += depth;
    h = (9*(h + d) + 4);   // 8 * total height of the cmex glyph
// I round up to ensure that the delimiter can totally enclose the contents
    return (16*height + h - 1)/h;
}

static int bracketWidth(char type, int flags, int height, int depth)
{
    int n = bracketCount(flags, height, depth);
// n is the size of bracket needed, measured in units of 0.5 times the
// normal cmex font height
    int fnt = FntExtension, ch = 0x00;
    if (n == 1)
    {   fnt = FntSymbol;
        switch(type)
        {
    case '.':
            return 0;
    case '(':
            fnt = FntRoman;
            ch = 0x28;
            break;
    case ')':
            fnt = FntRoman;
            ch = 0x29;
            break;
    case '[':
            fnt = FntRoman;
            ch = 0x5b;
            break;
    case ']':
            fnt = FntRoman;
            ch = 0x5d;
            break;
    case '{':
            ch = 0x66;
            break;
    case '}':
            ch = 0x67;
            break;
    case '|':                 // LEFT vertical bar
            ch = 0x6a;
            break;
    case '!':                 // RIGHT vertical bar
            ch = 0x6a;
            break;
    case 'Q':                 // square root marker
            ch = 0x70;        // NB this is a descender
            break;
    case '/':                 // slash
            ch = 0x36;
            break;
    case '\\':                // backslash
            ch = 0x6e;
            break;
    case 'L':                 // lfloor
            ch = 0x62;
            break;
    case 'G':                 // lceil (like Gamma)
            ch = 0x64;
            break;
    case 'J':                 // rfloor
            ch = 0x63;
            break;
    case '7':                 // rceil
            ch = 0x65;
            break;
    case '<':                 // langle
            ch = 0x68;
            break;
    case '>':                 // rangle
            ch = 0x69;
            break;
    case '#':                 // \|    (double vertical bar)
            ch = 0x6b;
            break;
    case '^':                 // uparrow
            ch = 0x22;
            break;
    case 'v':                 // downarrow
            ch = 0x23;
            break;
    case 'A':                 // Uparrow
            ch = 0x2a;
            break;
    case 'V':                 // Downarrow
            ch = 0x2b;
            break;
    case 'b':                 // updownarrow
            ch = 0x6c;
            break;
    case 'B':                 // Updownarrow
            ch = 0x6d;
            break;
    default:
            printf("Attempt to measure unknown delimiter \"%c\"\n", type);
            return 0;
        }
    }
    else
    {
        if (n > 6) n = 6;
        const char *s;
// All of this is amazingly tightly tied to the "cmex" font and the
// encoding it has for glyphs used to build up tall characters.
        switch(type)
        {
    case '.':
            return 0;
    case '(':
            s = "\x00\x10\x12\x20\x30";
            break;
    case ')':
            s = "\x01\x11\x13\x21\x31";
            break;
    case '[':
            s = "\x02\x68\x15\x22\x32";
            break;
    case ']':
            s = "\x03\x69\x16\x23\x33";
            break;
    case '{':
            s = "\x08\x6e\x1a\x28\x38";
            break;
    case '}':
            s = "\x09\x6f\x1b\x29\x39";
            break;
    case '|':                 // LEFT vertical bar
            s = "\x0c\x0c\x42\x42\x42";
            break;
    case '!':                 // RIGHT vertical bar
            s = "\x0c\x0c\x43\x43\x43";
            break;
    case 'Q':                 // square root marker
            s = "\x70\x71\x72\x73\x74";
            break;
    case 'L':           // lfloor
            s = "\x04\x6a\x16\x24\x36";
            break;
    case 'G':           // lceil
            s = "\x06\x6c\x18\x22\x32";
            break;
    case 'J':           // rfloor
            s = "\x05\x6b\x17\x25\x37";
            break;
    case '7':           // rceil
            s = "\x07\x6d\x19\x23\x33";
            break;
    case '^':           // uparrow
            s = "\x88\x78\x78\x78\x78";
            break;
    case 'v':           // downarrow
            s = "\x0c\x0c\x0c\x0c\x0c";
            break;
    case 'b':           // updownarrow
            s = "\x78\x78\x78\x78\x78";
            break;
    case 'A':           // Uparrow
            s = "\x7e\x7e\x7e\x7e\x7e";
            break;
    case 'V':           // Downarrow
            s = "\x77\x77\x77\x77\x77";
            break;
    case 'B':           // Updownarrow
            s = "\x7e\x7e\x7e\x7e\x7e";
            break;
    case '#':           // \| double vertical line
            s = "\x77\x77\x77\x77\x77";
            break;
    case '<':           // langle
    case '>':           // rangle
    case '\\':          // backslash
    case '/':           // slash
    default:
            printf("Attempt to measure unknown delimiter \"%c\"\n", type);
            return 0;
        }
        ch = s[n-2];
    }
    char ss[4];
    ss[0] = remap(ch);
    void *ff = mathFont[fnt + (flags & FontSizeMask)];
#ifdef WIN32
    int nn = 1;
    if ((ss[0] & 0xff) >= 0x80)
    {   ss[1] = 0x80 | (ss[0] & 0x3f);
        ss[0] = 0xc0 | ((ss[0] & 0xff) >> 6);
        nn = 2;
    }
    return ((FXFont *)ff)->getTextWidth(ss, nn);
#else
    return xfWidth(ff, ss, 1);
#endif
}

static int bracketHeightDepth(char type, int flags, int height, int depth)
{
    if (type == '.') return 0;
// the calculations here had better match the corresponding logic in
// paintBracket.
    int size = flags & FontSizeMask;
    int h = mathFontHeight[size], d = mathFontDepth[size];
    int n = bracketCount(flags, height, depth);
// n is the size of bracket needed, measured in units of 0.5 times the
// normal cmex font height
// If I use a cmsy or cmr glyph its height is easy to work out!
    if (n == 1)
    {   if (type == 'Q') h += (h + d + 12)/25;
        return (h<<16) | d;
    }
    int height1 = height + depth;
// the cmex glyphs seem to be (9/8) times as high as the cmr, cmmi
// and cmsy ones! So I scale here by that amount!
    int height2 = (9*n*(h + d) + 8)/16;
// height2 will be the actual total height of the bracket that I draw.
    int extra = (height2 - height1 + 1)/2;
    if (extra > 0)
    {   height += extra;
        depth += extra;
    }
    if (type == 'Q') height += (h + d + 12)/25; // rule width.
    return (height<<16) | depth;
}


// return width of column col in a BoxBeside row, or a negative
// value if there is not one.

static int widthOfColumn(Box *b, int col)
{
    while (col != 0)
    {   if (b->nest.type != BoxNest ||
            b->nest.flags != BoxBeside) return -1;
        b = b->nest.sub1;
        col--;
    }
    if (b->nest.type != BoxNest ||
        b->nest.flags != BoxBeside) return -1;
    b = b->nest.sub2;
    return b->text.width;
}

// return max width of any column with the given index, or a negative
// value if all rows in the matrix are shorter than that.

static int maxWidthInColumn(Box *b, int col)
{
    int r = -1;
    if (DEBUGFONT & 2) printf("find max width in column %d\n", col);
    while (b->nest.type == BoxNest &&
           b->nest.flags == BoxTower)
    {   int w = widthOfColumn(b->nest.sub2, col);
        if (DEBUGFONT & 2) printf("width in column %d is %d\n", col, w);
        if (w > r) r = w;
        if (DEBUGFONT & 2) printf("max now %d\n", r);
        b = b->nest.sub1;
    }
    return r;
}

// Here b is a set of BoxBesides and I want to widen one of the
// ones within it.

static void setOneWidth(Box *b, int col, int w, int xgap)
{
    int c0 = col;
    Box *b0 = b;
    if (DEBUGFONT & 2) printf("force width of column %d to %d in one row\n", col, w);
    while (col != 0)
    {   if (b->nest.type != BoxNest ||
            b->nest.flags != BoxBeside) return;
        b = b->nest.sub1;
        col--;
    }
    if (b->nest.type != BoxNest ||
        b->nest.flags != BoxBeside) return;
// Now b is a BoxBeside that represents the required cell of the
// matrix.
    int w0 = b->nest.sub2->text.width;  // current width of cell
    int extra = w - w0;
    if (DEBUGFONT & 2) printf("extra width needed = %d\n", extra);
    b->nest.dx2 += extra/2;             // centre the item
// Now all the enclosing boxes have got wider, so I need to adjust their
// record of their width.
    if (c0 == 0)
    {   b0->nest.width += extra;
        return;
    }
    if (DEBUGFONT & 2) printf("Now need to insert intercolumn gap\n");
    while (c0 > 0)
    {   b0->nest.width += extra + xgap;
        b0->nest.dx2 += extra + xgap;
        b0 = b0->nest.sub1;
        c0--;
    }
    b0->nest.width += extra + xgap;
    return;
}

static void setWidthsAndCentre(Box *b, int col, int w, int xgap, int ygap)
{
    Box *b0 = b;
    int n = 0;
    while (b0->nest.type == BoxNest &&
           b0->nest.flags == BoxTower)
    {   n++;
        b0 = b0->nest.sub1;
    }
    int dy = ygap*(n-1);
    if (DEBUGFONT & 2) printf("force width of column %d to %d\n", col, w);
    while (b->nest.type == BoxNest &&
           b->nest.flags == BoxTower)
    {   setOneWidth(b->nest.sub2, col, w, xgap);
// I have meddled with the width of an item in one row so the node here needs
// its width changed to match.
        b->nest.width = b->nest.sub2->nest.width;
        if (DEBUGFONT & 2) printf("Width of row is now %d\n", b->nest.width);
        b->nest.depth += dy;
        b->nest.dy2 += dy;
        dy -= ygap;
        b = b->nest.sub1;
    }
    return;
}

// return 0 if column col (starting with 0) does not exist. Otherwise
// change widths etc in all relevant BoxBeside entries. Note that the
// code I have here will scan the matrix repeatedly to find columns.
// I view the costs as OK since for display I never expect to have
// seriously large matrices.

static int balanceColumns(Box *b, int col, int xgap, int ygap)
{
    if (DEBUGFONT & 2) printf("balance column %d\n", col);
    int w = maxWidthInColumn(b, col);
    if (DEBUGFONT & 2) printf("column %d width = %d\n", col, w);
    if (w < 0) return 0;
    setWidthsAndCentre(b, col, w, xgap, ygap);
    if (DEBUGFONT & 2) printf("column %d balanced\n", col);
    return 1;
}

void measureBox(Box *b)
{
    b->top.measuredSize = -1;
    measureBox1(b);
}

int italicAdjust(int ch, int font)
{
//                        n
// In something like     X
// I need to space the superscript across by a bit when the base ends in
// a character that is tall and leans across to the right. The amount of
// adjustment is produced here and is really a bit of a fudge!
    int w = mathFontWidth[font];
    switch (font & FontFamilyMask)
    {
case FntItalic:
        switch (ch)
        {
    case 0x00: case 0x04: case 0x06: case 0x07: // Gamma etc!
    case 'f': case 'l':
    case 'B': case 'C': case 'E': case 'F':
    case 'H': case 'I': case 'J': case 'K':
    case 'M': case 'N': case 'P': case 'S':
    case 'T': case 'U': case 'V': case 'W':
    case 'X': case 'Y': case 'Z':
            return (w+6)/8;
    case 'O': case 'Q':
            return (w+8)/16;
    default:
            return 0;
        }
default:
        return 0;
    }
}

#ifdef WIN32
static char utfchars[256];
#endif

void measureBox1(Box *b)
{
    int f, h, w, d, dy, d1, h1;
    int sqrtcount=0, sqrtunit=0;
    void *ff;
    TextBox *t;
    SymBox *s;
    NestBox *n;
    NestBox3 *n3;
    MatrixBox *m;
    BracketBox *bb;
    TopBox *tt;
    char utflength;
    int l;
    char *ss;
    if (DEBUGFONT & 4)
    {   printf("measureBox1(%p)\n", b); fflush(stdout);
        printf("type = %d\n", b->text.type); fflush(stdout);
    }
    switch (b->text.type)
    {
case BoxSym:
        s = &(b->sym);
        if ((s->flags & SymTypeMask) == SymRule) return; // measurements fixed
        s->height = 0;
        s->depth = 0;
        switch (s->flags & SymTypeMask)
        {
    case SymStar:   // used as space between items that are multiplied
            s->width = mathFontWidth[s->flags & FontSizeMask]/6;
            return;
    case SymComma:  // narrow space
            s->width = mathFontWidth[s->flags & FontSizeMask]/4;
            return;
    case SymExclam: // narrow negative space
            s->width = -mathFontWidth[s->flags & FontSizeMask]/4;
            return;
    case SymColon:  // medium space
            s->width = mathFontWidth[s->flags & FontSizeMask]/2;
            return;
    case SymSemiColon: // wide space
            s->width = mathFontWidth[s->flags & FontSizeMask];
            return;
    case SymBlank:  // used by tmprint, it seems. Intent unclear to me!
            s->width = mathFontWidth[s->flags & FontSizeMask]/3;
            return;
    case SymNothing: // used when I want an empty box as a placeholder
            s->height = s->depth = s->width = 0;
            return;
    case SymUnderscore: // not a glyph in any font! So draw as a rule.
            s->width = mathFontWidth[s->flags & FontSizeMask]/2;
            return;
    default:
            printf("Unknown SymBox type %.2x to measure\n", s->flags);
            return;
        }
case BoxText:
        t = &(b->text);
        if (DEBUGFONT & 4)
        {   printf("text = <%s>\n", t->text);
            fflush(stdout);
        }
        ff = mathFont[t->flags & FontMask];
        if (DEBUGFONT & 4)
        {   printf("fontid = %.2x font = %p\n", t->flags, ff);
            fflush(stdout);
        }
        h = mathFontHeight[t->flags & FontSizeMask];
        d = mathFontDepth[t->flags & FontSizeMask];
#ifdef WIN32
        utflength = 0;
        l = t->n;
        ss = t->text;
        while (l > 0)
        {   int c = *ss++ & 0xff;
            l--;
            if (c < 0x80) utfchars[utflength++] = c;
            else
            {   utfchars[utflength++] = 0xc0 | (c >> 6);
                utfchars[utflength++] = 0x80 | (c & 0x3f);
            }
        }
        w = ((FXFont *)ff)->getTextWidth(utfchars, utflength);
#else
        w = xfWidth(ff, t->text, t->n);
#endif
// Here I have a bit of shameless fudge. The "cmex" glyph for \int seems to
// record as its width a value that makes it finish just about at a point on
// its stem. I unilaterally add a little extra width here to get spacing that
// I like better! Furthermore I will position all "big" operators based on
// their mid-line
        if (t->flags & FntBig)
        {   int bigH = 0, hd = h+d;
// I know the heights of the "big" operators in the cmex font, so
// compute them here in terms of the height of my normal font. The
// numbers seem a little odd but are what I appear to observe from
// inspecting the font.
            if (t->text[0] == 0x5a)   // \int
            {   w += mathFontWidth[t->flags & FontSizeMask]/3;
                bigH = (2222*hd + 450)/900;
            }
            else bigH = (1400*hd + 450)/900;
            hd = h - d;
            h = (bigH + hd)/2;
            d = (bigH - hd)/2;
        }
        if (DEBUGFONT & 4)
        {   printf("text \"%s\" is size h=%d d=%d w=%d\n", t->text, h, d, w);
            fflush(stdout);
        }
        t->height = h;
        t->depth = d;
        t->width = w;
        return;
case BoxBracket:   // This is for big brackets
        bb = &(b->bracket);
// I have leftBracket, rightBracket and sub components here.
// The characters involved can be "(", "[", "{", "|" "." "}", "]", ")".
// "Q" (sqrt), "/", "\", "L", "G" (lceil), "J", "7" (rceil), "<", ">",
// "#" (double vertical bar), "^" (uparrow), "v" (downarrow), "A" (Uparrow)
// "V" (Downarrow), "b" (updownarrow), "B" (Updownarrow)
        measureBox1(bb->sub);
        bb->width = bb->sub->text.width;
        h1 = bb->height = bb->sub->text.height;
        d1 = bb->depth = bb->sub->text.depth;
        f = bb->flags & FontSizeMask;
        if (bb->leftBracket == 'Q')
        {   h = mathFontHeight[f];
            d = mathFontDepth[f];
            h1 += (h + d + 12)/25; // make contents seem taller
                                   // to leave gap before overbar
            sqrtcount = bracketCount(f, h1, d1);
            sqrtunit = h + d;
        }
        w = bracketWidth(bb->leftBracket, f, h1, d1);
        bb->width += w;
        bb->dx = w;
        w = bracketWidth(bb->rightBracket, f, h1, d1);
        bb->width += w;
        h = bracketHeightDepth(bb->leftBracket, f, h1, d1);
        d = (h & 0xffff);
        h = (h >> 16) & 0xffff;
        w = bracketHeightDepth(bb->rightBracket, f, h1, d1);
        bb->height = intmax(bb->height, h);
        bb->depth = intmax(bb->depth, d);
        d = (w & 0xffff);
        h = (w >> 16) & 0xffff;
        bb->height = intmax(bb->height, h);
        bb->depth = intmax(bb->depth, d);
        if (bb->sub1 != NULL)
        {   measureBox1(bb->sub1);
// OK, if I have a "sub1" box I had a radical sign that needs an explicit
// index give, as in for cube- or nth roots. I want to position the
// index just above the left end of the hook in the radical sign.
            int downby = 0;
            switch (sqrtcount)
            {
        case 1: downby = sqrtunit/2;       break;
        case 2: downby = (6*sqrtunit)/10;  break;
        case 3: downby = (15*sqrtunit)/16; break;
        case 4: downby = (5*sqrtunit)/4;   break;
        case 5: downby = (8*sqrtunit)/5;   break;
        default:downby = bb->height + bb->depth - (10*sqrtunit)/5; break;
            }
            bb->dy1 = -(bb->height + bb->sub1->text.depth - downby);
            h = bb->dy1 + bb->sub1->text.height;
            bb->height = intmax(bb->height, h);
        }
        return;
case BoxMatrix:
        m = &(b->matrix);
// I do an initial measure operation on the contents not paying any attention
// to the fact that the contents is in a matrix context. This will give me
// the "natural" size of each enclosed sub-box.
        measureBox1(m->sub);
// Now I expect the contents to be (eg)
//    ABOVE(ABOVE(row1,row2),row3)
// with each row a structure like BESIDE(BESIDE(col1, col2),col3).
// I need to scan this to find the greatest width in each column, and then
// re-work the BESIDE widths and offsets to centre each item in a field that
// width. I also need to ensure suitable gaps between rows and columns.
// And finally I will need to set the "dy" field to get the base-line where
// it neeeds to be.

        {   int interColumnGap = mathFontWidth[m->flags & FontSizeMask];
            int interRowGap = mathFontHeight[m->flags & FontSizeMask]/2;
            for (int col=0;;col++)
            {   if (!balanceColumns(m->sub, col,
                       interColumnGap, interRowGap)) break;
            }
            m->width = m->sub->text.width;
            int mmh = m->sub->text.height + m->sub->text.depth;
            m->depth = mmh/2;
            m->height = mmh - m->depth;
            m->dy = m->depth - m->sub->text.depth;
        }
        return;
case BoxNest:
        n = &(b->nest);
        switch (n->flags & NestMask)
        {
    case BoxFraction:  //     Aaaaaaaa
                       // --> --------
                       //        Bb
            {   measureBox1(n->sub1);
                measureBox1(n->sub2);
                n->width = intmax(n->sub1->text.width, n->sub2->text.width);
                int rh = mathFontHeight[n->flags & FontSizeMask]/4;
                int delta = (mathFontHeight[n->flags & FontSizeMask] -
                             mathFontDepth[n->flags & FontSizeMask])/2;
                n->height = n->sub1->text.height +
                            n->sub1->text.depth + rh + delta;
                n->depth = n->sub2->text.height +
                            n->sub2->text.depth + rh - delta;
                n->dx1 = (n->width - n->sub1->text.width)/2;
                n->dy1 = -(n->sub1->text.depth + rh + delta);
                n->dx2 = (n->width - n->sub2->text.width)/2;
                n->dy2 = n->sub2->text.height + rh - delta;
            }
            if (DEBUGFONT & 4)
            {   printf("Above h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxStack:     //     Aaaaaaaa
                       // -->    Bb
            {   measureBox1(n->sub1);
                measureBox1(n->sub2);
                n->width = intmax(n->sub1->text.width, n->sub2->text.width);
                n->height = n->sub1->text.height + n->sub1->text.depth +
                            n->sub2->text.height;
                n->depth = n->sub2->text.depth;
                n->dx1 = (n->width - n->sub1->text.width)/2;
                n->dy1 = -(n->sub1->text.depth + n->sub2->text.height);
                n->dx2 = (n->width - n->sub2->text.width)/2;
                n->dy2 = 0;
            }
            if (DEBUGFONT & 4)
            {   printf("Above h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
   case BoxTower:      //     Aaaaaa
                       // --> Bbb
            measureBox1(n->sub1);
            measureBox1(n->sub2);
            n->width = intmax(n->sub1->text.width, n->sub2->text.width);
            n->height = n->sub1->text.height + n->sub1->text.depth + n->sub2->text.height;
            n->depth = n->sub2->text.depth;
            n->dx1 = 0;
            n->dy1 = -(n->sub1->text.depth + n->sub2->text.height);
            n->dx2 = 0;
            n->dy2 = 0;
            if (DEBUGFONT & 4)
            {   printf("Above h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxBeside:    // --> A B
            measureBox1(n->sub1);
            measureBox1(n->sub2);
            n->width = n->sub1->text.width + n->sub2->text.width;
            n->height = intmax(n->sub1->text.height, n->sub2->text.height);
            n->depth = intmax(n->sub1->text.depth, n->sub2->text.depth);
            n->dx1 = 0;
            n->dy1 = 0;
            n->dx2 = n->sub1->text.width;
            n->dy2 = 0;
            if (DEBUGFONT & 4)
            {   printf("Beside h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxAdjacent:    // --> A B
            measureBox1(n->sub1);
            measureBox1(n->sub2);
            w = n->sub1->text.width/4;  // amount to fudge by!
            n->width = n->sub1->text.width + n->sub2->text.width - w;
            n->height = intmax(n->sub1->text.height, n->sub2->text.height);
            n->depth = intmax(n->sub1->text.depth, n->sub2->text.depth);
            n->dx1 = 0;
            n->dy1 = 0;
            n->dx2 = n->sub1->text.width - w;
            n->dy2 = 0;
            if (DEBUGFONT & 4)
            {   printf("Adjacent h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxSubscript:   //   A    or in special cases    A
                         //    B                          B
            measureBox1(n->sub1);
            measureBox1(n->sub2);
// I will want to apply a special treatment here for "big" operators:
// subscripts and superscripts will be treated as forming a tower rather
// then the "usual" positioning.
            if (n->sub1->text.type==BoxText && n->sub1->text.flags & FntBig)
            {   n->width = intmax(n->sub1->text.width, n->sub2->text.width);
                n->height = n->sub1->text.height;
                n->depth = n->sub1->text.depth +
                           n->sub2->text.height + n->sub2->text.depth;
                n->dx1 = (n->width - n->sub1->text.width)/2;
                n->dy1 = 0;
                n->dx2 = (n->width - n->sub2->text.width)/2;
                n->dy2 = n->sub1->text.depth + n->sub2->text.height;
                if (DEBUGFONT & 4)
                {   printf("Special subscript h=%d d=%d w=%d\n",
                           n->height, n->depth, n->width);
                    printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                           n->dx1, n->dy1, n->dx2, n->dy2);
                    fflush(stdout);
                }
                return;
            }
            n->width = n->sub1->text.width + n->sub2->text.width;
            n->dx1 = 0;
            n->dy1 = 0;
            n->dx2 = n->sub1->text.width;
            dy = mathFontHeight[n->flags & FontSizeMask]/2;
            {   int tt = n->sub1->text.depth - n->sub2->text.depth;
                if (tt > dy) dy = tt;
            }
            n->dy2 = dy;
            n->height = intmax(n->sub1->text.height, n->sub2->text.height - dy);
            n->depth = intmax(n->sub1->text.depth, n->sub2->text.depth + dy);
            if (DEBUGFONT & 4)
            {   printf("Subscript h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxSuperscript:    //    B                          B
                            //   A     or in special cases   A
            measureBox1(n->sub1);
            measureBox1(n->sub2);
            if (n->sub1->text.type==BoxText && n->sub1->text.flags & FntBig)
            {   n->width = intmax(n->sub1->text.width, n->sub2->text.width);
                n->height = n->sub1->text.height +
                           n->sub2->text.height + n->sub2->text.depth;
                n->depth = n->sub1->text.depth;
                n->dx1 = (n->width - n->sub1->text.width)/2;
                n->dy1 = 0;
                n->dx2 = (n->width - n->sub2->text.width)/2;
                n->dy2 = -(n->sub1->text.height + n->sub2->text.depth);
                if (DEBUGFONT & 4)
                {   printf("Special superscript h=%d d=%d w=%d\n",
                           n->height, n->depth, n->width);
                    printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                           n->dx1, n->dy1, n->dx2, n->dy2);
                    fflush(stdout);
                }
                return;
            }
            n->width = n->sub1->text.width + n->sub2->text.width;
            n->dx1 = 0;
            n->dy1 = 0;
            n->dx2 = n->sub1->text.width;
// Now an utter hack! But it is here in part to alert me to the fact that
// similar tuning may be called for in other places. If I have "f^n" then the
// fact that "f" is tall and it slopes forward means that I want to put a tiny
// amount of extra space in. I will add some space for various cases here,
// but can imagine that further tuning could be applied!
//
            if (n->sub1->text.type==BoxText)
            {   const char *s = n->sub1->text.text;
                int len =  n->sub1->text.n;
                int w = italicAdjust(s[len-1], n->sub1->text.flags & FontMask);
                n->width += w;
                n->dx2 += w;
            }
// Superscripts are raised by at least half the height of the main font,
// but if the things that is being scripted is tall enough they line up with
// its top.
            dy = mathFontHeight[n->flags & FontSizeMask]/2;
            {   int tt = n->sub1->text.height - n->sub2->text.height;
                if (tt > dy) dy = tt;
            }
            n->dy2 = -dy;
            n->height = intmax(n->sub1->text.height, n->sub2->text.height + dy);
            n->depth = intmax(n->sub1->text.depth, n->sub2->text.depth - dy);
            if (DEBUGFONT & 4)
            {   printf("Superscript h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxOverstrike:    // --> A on top of B
            measureBox1(n->sub1);
            measureBox1(n->sub2);
            n->width = intmax(n->sub1->text.width, n->sub2->text.width);
            n->height = intmax(n->sub1->text.height, n->sub2->text.height);
            n->depth = intmax(n->sub1->text.depth, n->sub2->text.depth);
// I centre the items horizontally wrt each other
            n->dx1 = (n->width - n->sub1->text.width)/2;
            n->dy1 = 0;
            n->dx2 = (n->width - n->sub2->text.width)/2;
            n->dy2 = 0;
            if (DEBUGFONT & 4)
            {   printf("Overstrike h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    case BoxPadSpace:    // --> A    but with extra space around A
            measureBox1(n->sub1);
            w = mathFontWidth[n->flags & FontSizeMask]/4;
            n->width = n->sub1->text.width + 2*w;
            n->height = n->sub1->text.height;
            n->depth = n->sub1->text.depth;
            n->dx1 = w;
            n->dy1 = 0;
            if (DEBUGFONT & 4)
            {   printf("PadSpace h=%d d=%d w=%d\n",
                       n->height, n->depth, n->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n->dx1, n->dy1, n->dx2, n->dy2);
                fflush(stdout);
            }
            return;
    default:
            printf("Unknown nest style %d: failing\n", n->flags);
            return;
        }
        return;
case BoxNest3:
        n3 = &(b->nest3);
        switch (n3->flags & NestMask)
        {
    case BoxBothScripts:  //    C                           C
                          //   A       or in special cases  A
                          //    B                           B
// I will want to apply a special treatment here for "big" operators:
// subscripts and superscripts will be treated as forming a tower rather
// then the "usual" positioning.
            measureBox1(n3->sub1);
            measureBox1(n3->sub2);
            measureBox1(n3->sub3);
            if (n3->sub1->text.type==BoxText && n3->sub1->text.flags & FntBig)
            {   n3->width = 
                   intmax(n3->sub1->text.width, 
                      intmax(n3->sub2->text.width, n3->sub3->text.width));
                n3->height = n3->sub1->text.height +
                             n3->sub3->text.height + n3->sub3->text.depth;
                n3->depth = n3->sub1->text.depth +
                            n3->sub2->text.height + n3->sub2->text.depth;
                n3->dx1 = (n3->width - n3->sub1->text.width)/2;
                n3->dy1 = 0;
                n3->dx2 = (n3->width - n3->sub2->text.width)/2;
                n3->dy2 = n3->sub1->text.depth + n3->sub2->text.height;
                n3->dx3 = (n3->width - n3->sub3->text.width)/2;
                n3->dy3 = -(n3->sub1->text.height + n3->sub3->text.depth);
                if (DEBUGFONT & 4)
                {   printf("Special Bothscripts h=%d d=%d w=%d\n",
                           n3->height, n3->depth, n3->width);
                    printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                           n3->dx1, n3->dy1, n3->dx2, n3->dy2);
                    fflush(stdout);
                }
                return;
            }
            n3->width = n3->sub1->text.width +
                        intmax(n3->sub2->text.width, n3->sub3->text.width);
            n3->dx1 = 0;
            n3->dy1 = 0;
            n3->dx2 = n3->sub1->text.width;
            dy = mathFontHeight[n3->flags & FontSizeMask]/2;
            {   int tt = n3->sub1->text.depth - n3->sub2->text.depth;
                if (tt > dy) dy = tt;
            }
            n3->dy2 = dy;
            n3->dx3 = n3->sub1->text.width;
// Now an "italic correction" for "f^n". See the BoxSuperscript case for
// more explanation.
            if (n3->sub1->text.type==BoxText)
            {   const char *s = n3->sub1->text.text;
                int len =  n3->sub1->text.n;
                int w = italicAdjust(s[len-1], n3->sub1->text.flags & FontMask);
                n3->width += w;
                n3->dx2 += w;
            }
            dy = mathFontHeight[n3->flags & FontSizeMask]/2;
            {   int tt = n3->sub1->text.height - n3->sub3->text.height;
                if (tt > dy) dy = tt;
            }
            n3->dy3 = -dy;
            n3->height =
               intmax(n3->sub1->text.height,
                  intmax(n3->sub2->text.height - dy, n3->sub3->text.height + dy));
            n3->depth =
               intmax(n3->sub1->text.depth,
                  intmax(n3->sub2->text.depth + dy, n3->sub3->text.depth - dy));
            if (DEBUGFONT & 4)
            {   printf("Bothscripts h=%d d=%d w=%d\n",
                       n3->height, n3->depth, n3->width);
                printf("dx1=%d dy1=%d dx2=%d dy2=%d\n",
                       n3->dx1, n3->dy1, n3->dx2, n3->dy2);
                fflush(stdout);
            }
            return;
    default:
            printf("Unknown nest3 style %d: failing\n", n3->flags);
            return;
        }
        return;
case BoxFrame:
        measureBox1(b->frame.sub);
        b->frame.width = b->frame.sub->text.width;
        b->frame.height = b->frame.sub->text.height;
        b->frame.depth = b->frame.sub->text.depth;
        return;
case BoxTop:               // top-level wrapper for boxes.
        tt = &(b->top);
// If I have measured before while the main maths font was the same
// size that it is now I will not do anything.
        if (tt->measuredSize == mathFontSize) return;
        measureBox1(tt->sub);
        tt->width = tt->sub->text.width;
        tt->height = tt->sub->text.height;
        tt->depth = tt->sub->text.depth;
        tt->measuredSize = mathFontSize;
        return;
default:
        printf("Measure unknown box type %d: failing\n", b->text.type);
        fflush(stdout);
        return;
    }
}

///////////////////////////////////////////////////////////////////////////

// Input will be presented in a LaTeX-like form so I will want to parse that
// so I can build my box-structure. To do that I will want a way of
// recognizing LaTeX keywords.

typedef struct Keyword
{
    const char *name;
    unsigned char type;
    unsigned char font; // includes size info
    int charCode;       // sometimes holds additional information!
    void *ptr;
} Keyword;

typedef Box *blockHandlerFunction(int l, int r, Box *b);
typedef Box *oneArgHandlerFunction(Box *b, Box *opt);
typedef Box *twoArgsHandlerFunction(Box *b1, Box *b2);
typedef Box *keywordHandlerFunction(int w);

// single character glyph
#define TeXSymbol    0x00
// single character glyph, but subscripts and superscripts form tower
#define TeXVSymbol   0x01
// single character glyph, but allow extra space on either ide
#define TeXWSymbol   0x02
// word to be set in Roman font (eg function name like "sin")
#define TeXRoman     0x03
// keyword not taking an argument, eg \longleftarrow, \not
#define TeX0Arg      0x04
// keyword taking one arg, eg \sqrt
#define TeX1Arg      0x05
// keyword taking 2 args, eg \frac
#define TeX2Arg      0x06
// the \rule keyword
#define TeXRule      0x07
// the \begin keyword
#define TeXBeginWord 0x08
// keyword that forms a sort of "open bracket"
#define TeXBegin     0x09
// "close bracket" to match TeXBegin
#define TeXEnd       0x0a
// "^" or "_".
#define TeXScript    0x0b

#define TeXFlag      0x80

#define matchCenter    1
#define matchMatrix    2
#define matchLeftRight 3
#define matchBrace     4
#define matchParen     5
#define matchBracket   6
#define matchDollar    7


int insideDollars;

static Box *doDisplayStyle(int w)
{
    return NULL;  // always does displaystyle!
}

static Box *doDollar(int l, int r, Box *b1)
{
    if (b1 == NULL)
    {   insideDollars = 1;
        currentState.currentFont = FntItalic + currentSize;
    }
    else insideDollars = 0;
    return b1;
}

static Box *doMathBrace(int l, int r, Box *b1)
{
    currentState.currentFont = FntItalic + currentSize;
    return b1;
}

static Box *doMathRm(Box *b1, Box *opt)
{
    if (b1 == NULL) currentState.currentFont = FntRoman + currentSize;
    return b1;
}

static Box *doMathIt(Box *b1, Box *opt)
{
    if (b1 == NULL) currentState.currentFont = FntItalic + currentSize;
    return b1;
}

static Box *doSpaceCommand(int w)
{
    switch (w)
    {
default:
case ' ': return makeSymBox(SymBlank); 
case '*': return makeSymBox(SymStar);
case ',': return makeSymBox(SymComma); 
case '!': return makeSymBox(SymExclam); 
case ':': return makeSymBox(SymColon);
case ';': return makeSymBox(SymSemiColon); 
case '_': return makeSymBox(SymUnderscore); 
    }
}

static Box *doAdjacent(int w)
{
// This builds a composite character by putting two glyphs together.
// The glyphs are passed in a 32-bit (or wider) packed integer argument.
    int f1, c1, f2, c2;
    f1 = (w >> 24) & 0xff;
    c1 = (w >> 16) & 0xff;
    f2 = (w >> 8) & 0xff;
    c2 = w & 0xff;
    char s1[1], s2[1];
    s1[0] = remap(c1);
    s2[0] = remap(c2);
    return makeNestBox(BoxAdjacent,
        makeTextBox(s1, 1, f1 + currentSize),
        makeTextBox(s2, 1, f2 + currentSize));
}

static Box *doLeftRight(int l, int r, Box *b)
{
    if (b == NULL) return NULL;
    return makeBracketBox(b, l, r);
}

static Box *doNeq(int w)
{
    Box *b1 = makeTextBox("\x3d", 1, FntRoman + currentSize);
    Box *b2 = makeTextBox("\x3d", 1, FntItalic + currentSize);
    return makeNestBox(BoxOverstrike, b1, b2);
}

static Box *readP();

static Box *doNot(int w)
{
// Overstrike anthing (much) with a "/". Hence "\not \equiv" etc.
    Box *b1 = readP();
    if (b1 == NULL) return NULL;
    Box *b2 = makeTextBox("\x3d", 1, FntItalic + currentSize);
    return makeNestBox(BoxOverstrike, b1, b2);
}

static Box *doPmod(Box *b, Box *opt)
{
    printf("pmod not handed yet");
    return b;
}

static Box *doSqrt(Box *b, Box *opt)
{
    if (b == NULL) return NULL;
// Note that sqrt will need to draw a rule above the item it encloses.
    Box *r = makeBracketBox(b, 'Q', '.');
    r->bracket.sub1 = opt;
    return r;
}

static Box *doFbox(Box *b, Box *opt)
{
    if (b == NULL) return NULL;
    return makeFrameBox(b);
}

static Box *doSymb(Box *b, Box *opt)
{
    if (b == NULL) return NULL;
    return makeFrameBox(b);      // At PRESENT I maye symb just a boxed number
}

static Box *doFrac(Box *b1, Box *b2)
{
    if (b1 == NULL) return b2;
    else if (b2 == NULL) return b1;
    return makeNestBox(BoxFraction, b1, b2);
}

static Box *doLarge(int w)
{
    if (currentSize != 0) currentState.currentFont-=FntScript;
    return NULL;
}

static Box *doStackrel(Box *b1, Box *b2)
{
    if (b1 == NULL) return b2;
    else if (b2 == NULL) return b1;
    return makeNestBox(BoxStack, b1, b2);
}

#if 0
// To assist debugging while I develop this code I want to be able to
// display information about a keyword.

static void printKeyword(Keyword *k)
{
    if (k == NULL) printf("NULL keyword\n");
    else printf("Keyword \"%s\" type %.2x font %.2x code %.2x ptr %p\n",
                k->name, k->type, k->font, k->charCode, k->ptr);
}

#endif // 0

// The table that follows is initially set up in an order designed to
// have some degree of coherence of presentation, but as soon as the code
// starts to run it gers rearranged as a hash table.

#define texWordBits 9


static Keyword texWords[1<<texWordBits] =
{
// Some important control words
//    name          type       font       charCode  ptr
// The next two NEVER get out from the lexer.
    {"begin",      TeXBeginWord,  1,         0,    NULL},
    {"end",        TeXBeginWord,  0,         0,    NULL},
// My lexer will map "\begin{center}" onto a single token "(center"
// and similarly for other uses of \begin and \end. In fact with the
// current REDUCE "tmprint" module the only brackets of this sort that
// are used are "center" and "matrix". Also in the CSL driver I will not
// actually generate the "center" case...
    {"(center",    TeXBegin,  matchCenter,    'c',  NULL},
    {")center",    TeXEnd,    matchCenter,    'c',  NULL},
    {"(matrix",    TeXBegin,  matchMatrix,    'm',  NULL},
    {")matrix",    TeXEnd,    matchMatrix,    'm',  NULL},

// Special-case bracket-like items (delimiters that get displayed
// at a size the cover the item on one size of them). The case "\right("
// is probably never used, but I include all cases here for consistency.
// A "\left" must match with a "\right", but the associated delimiter
// does not have to match.
    {"left:(",     TeXBegin,  matchLeftRight, '(',  (void *)doLeftRight},
    {"right:(",    TeXEnd,    matchLeftRight, '(',  (void *)doLeftRight},
    {"left:)",     TeXBegin,  matchLeftRight, ')',  (void *)doLeftRight},
    {"right:)",    TeXEnd,    matchLeftRight, ')',  (void *)doLeftRight},
    {"left:[",     TeXBegin,  matchLeftRight, '[',  (void *)doLeftRight},
    {"right:[",    TeXEnd,    matchLeftRight, '[',  (void *)doLeftRight},
    {"left:]",     TeXBegin,  matchLeftRight, ']',  (void *)doLeftRight},
    {"right:]",    TeXEnd,    matchLeftRight, ']',  (void *)doLeftRight},
    {"left:\\{",   TeXBegin,  matchLeftRight, '{',  (void *)doLeftRight},
    {"right:\\{",  TeXEnd,    matchLeftRight, '{',  (void *)doLeftRight},
    {"left:\\}",   TeXBegin,  matchLeftRight, '}',  (void *)doLeftRight},
    {"right:\\}",  TeXEnd,    matchLeftRight, '}',  (void *)doLeftRight},
    {"left:|",     TeXBegin,  matchLeftRight, '|',  (void *)doLeftRight},
// Note that I map left and right vertical bars onto different things (I
// abuse an exclamation mark to stand for the right one) since they may
// call for different spacings.
    {"right:|",    TeXEnd,    matchLeftRight, '!',  (void *)doLeftRight},
// "\left." and "\right." are invisible!
    {"left:.",     TeXBegin,  matchLeftRight, '.',  (void *)doLeftRight},
    {"right:.",    TeXEnd,    matchLeftRight, '.',  (void *)doLeftRight},
// "/", "\", "L", "G" (lceil), "J", "7" (rceil), "<", ">",
// "#" (double vertical bar), "^" (uparrow), "v" (downarrow), "A" (Uparrow)
// "V" (Downarrow), "b" (updownarrow), "B" (Updownarrow)
    {"left:/",        TeXBegin,     matchLeftRight, '/',  (void *)doLeftRight},
    {"right:/",       TeXEnd,       matchLeftRight, '/',  (void *)doLeftRight},
    {"left:\\|",      TeXBegin,     matchLeftRight, '#',  (void *)doLeftRight},
    {"right:\\|",     TeXEnd,       matchLeftRight, '#',  (void *)doLeftRight},
    {"left:\\langle", TeXBegin,     matchLeftRight, '<',  (void *)doLeftRight},
    {"right:\\langle",TeXEnd,       matchLeftRight, '<',  (void *)doLeftRight},
    {"left:\\rangle", TeXBegin,     matchLeftRight, '>',  (void *)doLeftRight},
    {"right:\\rangle",TeXEnd,       matchLeftRight, '>',  (void *)doLeftRight},
    {"left:\\backslash", TeXBegin,  matchLeftRight, '\\',  (void *)doLeftRight},
    {"right:\\backslash",TeXEnd,    matchLeftRight, '\\',  (void *)doLeftRight},
    {"left:\\lfloor", TeXBegin,     matchLeftRight, 'L',  (void *)doLeftRight},
    {"right:\\lfloor",TeXEnd,       matchLeftRight, 'L',  (void *)doLeftRight},
    {"left:\\rfloor", TeXBegin,     matchLeftRight, 'J',  (void *)doLeftRight},
    {"right:\\rfloor",TeXEnd,       matchLeftRight, 'J',  (void *)doLeftRight},
    {"left:\\lceil",  TeXBegin,     matchLeftRight, 'G',  (void *)doLeftRight},
    {"right:\\lceil", TeXEnd,       matchLeftRight, 'G',  (void *)doLeftRight},
    {"left:\\rceil",  TeXBegin,     matchLeftRight, '7',  (void *)doLeftRight},
    {"right:\\rceil", TeXEnd,       matchLeftRight, '7',  (void *)doLeftRight},
    {"left:\\uparrow", TeXBegin,    matchLeftRight, '^',  (void *)doLeftRight},
    {"right:\\uparrow",TeXEnd,      matchLeftRight, '^',  (void *)doLeftRight},
    {"left:\\downarrow", TeXBegin,  matchLeftRight, 'v',  (void *)doLeftRight},
    {"right:\\downarrow",TeXEnd,    matchLeftRight, 'v',  (void *)doLeftRight},
    {"left:\\updownarrow", TeXBegin,matchLeftRight, 'b',  (void *)doLeftRight},
    {"right:\\updownarrow",TeXEnd,  matchLeftRight, 'b',  (void *)doLeftRight},
    {"left:\\Uparrow", TeXBegin,    matchLeftRight, 'A',  (void *)doLeftRight},
    {"right:\\Uparrow",TeXEnd,      matchLeftRight, 'A',  (void *)doLeftRight},
    {"left:\\Downarrow", TeXBegin,  matchLeftRight, 'V',  (void *)doLeftRight},
    {"right:\\Downarrow",TeXEnd,    matchLeftRight, 'V',  (void *)doLeftRight},
    {"left:\\Updownarrow", TeXBegin,matchLeftRight, 'B',  (void *)doLeftRight},
    {"right:\\Updownarrow",TeXEnd,  matchLeftRight, 'B',  (void *)doLeftRight},
// Some other things that generate enclosing contexts
    {"{",          TeXBegin,  matchBrace,     '{',  NULL},
    {"}",          TeXEnd,    matchBrace,     '{',  NULL},
// "[" and "]" are fairly ordinary characters when they just happen in
// random places. But after "\sqrt" (and possibly other things) they
// enclose an optional argument.
    {"[",          TeXSymbol, FntRoman,  0x5b, NULL},
    {"]",          TeXSymbol, FntRoman,  0x5d, NULL},
// At present I will treate "\(" and "\[" as synonyms - both just
// enter maths mode.
    {"\\(",        TeXBegin,  matchParen,     '(',  (void *)doMathBrace},
    {"\\)",        TeXEnd,    matchParen,     '(',  (void *)doMathBrace},
    {"\\[",        TeXBegin,  matchBracket,   '[',  (void *)doMathBrace},
    {"\\]",        TeXEnd,    matchBracket,   '[',  (void *)doMathBrace},
    {"$",          TeXBegin,  matchDollar,    '$',  (void *)doDollar},

// Treatment for "\&" etc that just generate literal characters.
// Note and be warned - the TeX fonts that are going to be used
// here have their own special encoding schemes so the numeric values
// that stand for even ordinary-seeming glyphs need careful attention.
    {"\\{",        TeXSymbol, FntSymbol, 0x66, NULL},
    {"\\}",        TeXSymbol, FntSymbol, 0x67, NULL},
    {"\\$",        TeXSymbol, FntRoman,  0x24, NULL},
    {"\\&",        TeXWSymbol,FntRoman,  0x26, NULL},
    {"\\%",        TeXSymbol, FntRoman,  0x25, NULL},

// subscripts and superscripts involve some parsing magic
    {"^",          TeXScript, 0,         0,    NULL},
    {"_",          TeXScript, 1,         0,    NULL},

// Simple symbols that need some care because the normal code used
// here may not match TeX font encodings.
    {"+",          TeXWSymbol,FntRoman,  0x2b, NULL},
    {"-",          TeXWSymbol,FntSymbol, 0x00, NULL}, // Roman 0x2d is hyphen
    {"=",          TeXWSymbol,FntRoman,  0x3d, NULL},
    {"*",          TeXSymbol, FntRoman,  0x2a, NULL},
    {"/",          TeXSymbol, FntRoman,  0x2f, NULL},
    {":",          TeXSymbol, FntRoman,  0x3a, NULL},
    {";",          TeXSymbol, FntRoman,  0x3b, NULL},
    {"@",          TeXSymbol, FntRoman,  0x40, NULL},
    {",",          TeXSymbol, FntRoman,  0x2c, NULL},
    {".",          TeXSymbol, FntRoman,  0x2e, NULL},
    {"?",          TeXSymbol, FntRoman,  0x3f, NULL},
    {"!",          TeXSymbol, FntRoman,  0x21, NULL},
    {"|",          TeXSymbol, FntSymbol, 0x6a, NULL},
    {"`",          TeXSymbol, FntRoman,  0x12, NULL},
//  {"NOTSIGN",    TeXSymbol, FntSymbol, 0x3a, NULL},
    {"#",          TeXSymbol, FntRoman,  0x23, NULL},
    {"~",          TeXSymbol, FntRoman,  0x7f, NULL},
    {"(",          TeXSymbol, FntRoman,  0x28, NULL},
    {")",          TeXSymbol, FntRoman,  0x29, NULL},
    {"<",          TeXSymbol, FntItalic, 0x3c, NULL},
    {">",          TeXSymbol, FntItalic, 0x3e, NULL},

// Lower case Greek

    {"alpha",      TeXSymbol, FntItalic, 0x0b, NULL},
    {"beta",       TeXSymbol, FntItalic, 0x0c, NULL},
    {"gamma",      TeXSymbol, FntItalic, 0x0d, NULL},
    {"delta",      TeXSymbol, FntItalic, 0x0e, NULL},
    {"epsilon",    TeXSymbol, FntItalic, 0x0f, NULL},
    {"varepsilon", TeXSymbol, FntItalic, 0x22, NULL},
    {"zeta",       TeXSymbol, FntItalic, 0x10, NULL},
    {"eta",        TeXSymbol, FntItalic, 0x11, NULL},
    {"theta",      TeXSymbol, FntItalic, 0x12, NULL},
    {"vartheta",   TeXSymbol, FntItalic, 0x23, NULL},
    {"iota",       TeXSymbol, FntItalic, 0x13, NULL},
    {"kappa",      TeXSymbol, FntItalic, 0x14, NULL},
    {"lambda",     TeXSymbol, FntItalic, 0x15, NULL},
    {"mu",         TeXSymbol, FntItalic, 0x16, NULL},
    {"nu",         TeXSymbol, FntItalic, 0x17, NULL},
    {"xi",         TeXSymbol, FntItalic, 0x18, NULL},
    {"omicron",    TeXSymbol, FntItalic, 'o',  NULL},
    {"pi",         TeXSymbol, FntItalic, 0x19, NULL},
    {"varpi",      TeXSymbol, FntItalic, 0x24, NULL},
    {"rho",        TeXSymbol, FntItalic, 0x1a, NULL},
    {"varrho",     TeXSymbol, FntItalic, 0x25, NULL},
    {"sigma",      TeXSymbol, FntItalic, 0x1b, NULL},
    {"varsigma",   TeXSymbol, FntItalic, 0x26, NULL},
    {"tau",        TeXSymbol, FntItalic, 0x1c, NULL},
    {"upsilon",    TeXSymbol, FntItalic, 0x1d, NULL},
    {"phi",        TeXSymbol, FntItalic, 0x1e, NULL},
    {"varphi",     TeXSymbol, FntItalic, 0x27, NULL},
    {"chi",        TeXSymbol, FntItalic, 0x1f, NULL},
    {"psi",        TeXSymbol, FntItalic, 0x20, NULL},
    {"omega",      TeXSymbol, FntItalic, 0x21, NULL},
//
// Upper case Greek (using Maths Italic for A, B etc where shapes are
// the same).

    {"Alpha",      TeXSymbol, FntItalic, 'A',  NULL},
    {"Beta",       TeXSymbol, FntItalic, 'B',  NULL},
    {"Gamma",      TeXSymbol, FntItalic, 0x00, NULL},
    {"Delta",      TeXSymbol, FntItalic, 0x01, NULL},
    {"Epsilon",    TeXSymbol, FntItalic, 'E',  NULL},
    {"Zeta",       TeXSymbol, FntItalic, 'Z',  NULL},
    {"Eta",        TeXSymbol, FntItalic, 'H',  NULL},
    {"Theta",      TeXSymbol, FntItalic, 0x02, NULL},
    {"Iota",       TeXSymbol, FntItalic, 'I',  NULL},
    {"Kappa",      TeXSymbol, FntItalic, 'K',  NULL},
    {"Lambda",     TeXSymbol, FntItalic, 0x03, NULL},
    {"Mu",         TeXSymbol, FntItalic, 'M',  NULL},
    {"Nu",         TeXSymbol, FntItalic, 'N',  NULL},
    {"Xi",         TeXSymbol, FntItalic, 0x04, NULL},
    {"Omicron",    TeXSymbol, FntItalic, 'O',  NULL},
    {"Pi",         TeXSymbol, FntItalic, 0x05, NULL},
    {"Rho",        TeXSymbol, FntItalic, 'R',  NULL},
    {"Sigma",      TeXSymbol, FntItalic, 0x06, NULL},
    {"Tau",        TeXSymbol, FntItalic, 'T',  NULL},
    {"Upsilon",    TeXSymbol, FntItalic, 0x07, NULL},
    {"Phi",        TeXSymbol, FntItalic, 0x08, NULL},
    {"Chi",        TeXSymbol, FntItalic, 'X',  NULL},
    {"Psi",        TeXSymbol, FntItalic, 0x09, NULL},
    {"Omega",      TeXSymbol, FntItalic, 0x0a, NULL},
//
// More mathematical symbols. I have copied all the names from my LaTeX
// book and identified available characters in the cmmi or cmsy fonts where
// I can. I have at present commented out all characters for which I do not
// have a glyph. The effect will be that the TeX symbol that names them will
// be rejected. In some cases I note another font that could help.

    {"pm",               TeXWSymbol,FntSymbol, 0x06, NULL},
    {"mp",               TeXWSymbol,FntSymbol, 0x07, NULL},
    {"times",            TeXSymbol, FntSymbol, 0x02, NULL},
    {"div",              TeXSymbol, FntSymbol, 0x04, NULL},
    {"ast",              TeXSymbol, FntSymbol, 0x03, NULL},
    {"star",             TeXSymbol, FntItalic, 0x3f, NULL},
    {"circ",             TeXSymbol, FntSymbol, 0x0e, NULL},
    {"bullet",           TeXSymbol, FntSymbol, 0x0f, NULL},
    {"cdot",             TeXSymbol, FntSymbol, 0x01, NULL},
    {"cap",              TeXSymbol, FntSymbol, 0x5c, NULL},
    {"cup",              TeXSymbol, FntSymbol, 0x5b, NULL},
    {"uplus",            TeXSymbol, FntSymbol, 0x5d, NULL},
    {"sqcap",            TeXSymbol, FntSymbol, 0x75, NULL},
    {"sqcup",            TeXSymbol, FntSymbol, 0x74, NULL},
    {"vee",              TeXSymbol, FntSymbol, 0x5f, NULL},
    {"wedge",            TeXSymbol, FntSymbol, 0x5e, NULL},
// The Variable-sized symbols tend to come in two sizes, and although TeX
// only used one name (eg \int) and selects which to use based on whether
// one is in displaymath or ordinary (in-line) mode. Here I am "always" in
// displaymath mode so I always want the larger versions. But I provide
// alternative names starting "small" to keep the others available.
    {"smallsum",         TeXVSymbol, FntExtension, 0x50, NULL},
    {"sum",              TeXVSymbol, FntExtension, 0x58, NULL},
    {"smallprod",        TeXVSymbol, FntExtension, 0x51, NULL},
    {"prod",             TeXVSymbol, FntExtension, 0x59, NULL},
    {"smallcoprod",      TeXVSymbol, FntExtension, 0x60, NULL},
    {"coprod",           TeXVSymbol, FntExtension, 0x61, NULL},
    {"smallint",         TeXVSymbol, FntExtension, 0x52, NULL},
    {"int",              TeXVSymbol, FntExtension, 0x5a, NULL},
// It looks to me as if tmprint.red can generate either \int or \Int
// and maybe it expects one to be smaller than the other...???
    {"Int",              TeXVSymbol, FntExtension, 0x5a, NULL},
    {"smalloint",        TeXVSymbol, FntExtension, 0x48, NULL},
    {"oint",             TeXVSymbol, FntExtension, 0x49, NULL},
    {"smallbigcup",      TeXVSymbol, FntExtension, 0x53, NULL},
    {"nigcup",           TeXVSymbol, FntExtension, 0x5b, NULL},
    {"smallbigcap",      TeXVSymbol, FntExtension, 0x54, NULL},
    {"bigcap",           TeXVSymbol, FntExtension, 0x5c, NULL},
    {"smallbiguplus",    TeXVSymbol, FntExtension, 0x55, NULL},
    {"biguplus",         TeXVSymbol, FntExtension, 0x5d, NULL},
    {"smallbigodot",     TeXVSymbol, FntExtension, 0x4a, NULL},
    {"bigodot",          TeXVSymbol, FntExtension, 0x4b, NULL},
    {"smallbigotimes",   TeXVSymbol, FntExtension, 0x4e, NULL},
    {"bigotimes",        TeXVSymbol, FntExtension, 0x4f, NULL},
    {"smallbigoplus",    TeXVSymbol, FntExtension, 0x4c, NULL},
    {"bigoplus",         TeXVSymbol, FntExtension, 0x4d, NULL},
    {"smallbigsqcup",    TeXVSymbol, FntExtension, 0x46, NULL},
    {"bigsqcup",         TeXVSymbol, FntExtension, 0x47, NULL},
    {"smallbigwedge",    TeXVSymbol, FntExtension, 0x56, NULL},
    {"bigwedge",         TeXVSymbol, FntExtension, 0x5e, NULL},
    {"smallbigvee",      TeXVSymbol, FntExtension, 0x57, NULL},
    {"bigvee",           TeXVSymbol, FntExtension, 0x5f, NULL},
// end of variable sized things
    {"setminus",         TeXSymbol, FntSymbol, 0x6e, NULL},
    {"wr",               TeXSymbol, FntSymbol, 0x6f, NULL},
    {"diamond",          TeXSymbol, FntSymbol, 0x05, NULL},
    {"bigtriangleup",    TeXSymbol, FntSymbol, 0x35, NULL},
    {"bigtriangledown",  TeXSymbol, FntSymbol, 0x36, NULL},
    {"triangleleft",     TeXSymbol, FntItalic, 0x2f, NULL},
    {"triangleright",    TeXSymbol, FntItalic, 0x2e, NULL},
//  {"lhd",              TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x43
//  {"rhd",              TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x42
//  {"unlhd",            TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x45
//  {"unrhd",            TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x44
    {"oplus",            TeXSymbol, FntSymbol, 0x08, NULL},
    {"ominus",           TeXSymbol, FntSymbol, 0x09, NULL},
    {"otimes",           TeXSymbol, FntSymbol, 0x0a, NULL},
    {"oslash",           TeXSymbol, FntSymbol, 0x0b, NULL},
    {"odot",             TeXSymbol, FntSymbol, 0x0c, NULL},
    {"bigcirc",          TeXSymbol, FntSymbol, 0x0d, NULL},
    {"dagger",           TeXSymbol, FntSymbol, 0x79, NULL},
    {"ddagger",          TeXSymbol, FntSymbol, 0x7a, NULL},
    {"amalg",            TeXSymbol, FntSymbol, 0x71, NULL},
    {"leq",              TeXSymbol, FntSymbol, 0x14, NULL},
    {"prec",             TeXSymbol, FntSymbol, 0x1e, NULL},
    {"preceq",           TeXSymbol, FntSymbol, 0x16, NULL},
    {"ll",               TeXSymbol, FntSymbol, 0x1c, NULL},
    {"subset",           TeXSymbol, FntSymbol, 0x1a, NULL},
    {"subseteq",         TeXSymbol, FntSymbol, 0x12, NULL},
//  {"sqsubset",         TeXSymbol, FntSymbol, 0x00, NULL},  // lasy 0x3c
    {"sqsubseteq",       TeXSymbol, FntSymbol, 0x75, NULL},
    {"in",               TeXSymbol, FntSymbol, 0x32, NULL},
    {"vdash",            TeXSymbol, FntSymbol, 0x60, NULL},
    {"geq",              TeXSymbol, FntSymbol, 0x15, NULL},
    {"succ",             TeXSymbol, FntSymbol, 0x1f, NULL},
    {"succeq",           TeXSymbol, FntSymbol, 0x17, NULL},
    {"gg",               TeXSymbol, FntSymbol, 0x1d, NULL},
    {"supset",           TeXSymbol, FntSymbol, 0x1b, NULL},
    {"supseteq",         TeXSymbol, FntSymbol, 0x13, NULL},
//  {"sqsupset",         TeXSymbol, FntSymbol, 0x00, NULL},  // lasy 0x3d
    {"sqsupseteq",       TeXSymbol, FntSymbol, 0x77, NULL},
    {"ni",               TeXSymbol, FntSymbol, 0x33, NULL},
    {"dashv",            TeXSymbol, FntSymbol, 0x61, NULL},
    {"equiv",            TeXSymbol, FntSymbol, 0x11, NULL},
    {"sim",              TeXSymbol, FntSymbol, 0x18, NULL},
    {"simeq",            TeXSymbol, FntSymbol, 0x27, NULL},
    {"asymp",            TeXSymbol, FntSymbol, 0x10, NULL},
    {"approx",           TeXSymbol, FntSymbol, 0x19, NULL},
    {"cong",             TeXSymbol, FntSymbol, 0x00, NULL},  // msbm 0x74
//  {"doteq",            TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"propto",           TeXSymbol, FntSymbol, 0x2f, NULL},
    {"models",           TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x0f
//  {"perp",             TeXSymbol, FntSymbol, 0x3f, NULL},
    {"mid",              TeXSymbol, FntSymbol, 0x6a, NULL},
    {"parallel",         TeXSymbol, FntSymbol, 0x6b, NULL},
//  {"bowtie",           TeXSymbol, FntSymbol, 0x00, NULL},  // lasy 0x31
//  {"join",             TeXSymbol, FntSymbol, 0x00, NULL},  // ?
    {"smile",            TeXSymbol, FntItalic, 0x5e, NULL},
    {"frown",            TeXSymbol, FntItalic, 0x5f, NULL},
    {"leftarrow",        TeXSymbol, FntSymbol, 0x20, NULL},
    {"Leftarrow",        TeXSymbol, FntSymbol, 0x28, NULL},
    {"rightarrow",       TeXSymbol, FntSymbol, 0x21, NULL},
    {"Rightarrow",       TeXSymbol, FntSymbol, 0x29, NULL},
    {"leftrightarrow",   TeXSymbol, FntSymbol, 0x24, NULL},
    {"Leftrightarrow",   TeXSymbol, FntSymbol, 0x2c, NULL},
//  {"mapsto",           TeXSymbol, FntSymbol, 0x00, NULL},  // ?msam 0x110
//  {"hookleftarrow",    TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"leftharpoonup",    TeXSymbol, FntSymbol, 0x00, NULL},  // euex 0x18
//  {"leftharpoondown",  TeXSymbol, FntSymbol, 0x00, NULL},  // euex 0x19
//  {"rightleftharpoons",TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"longmapsto",       TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"hookrightarrow",   TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"rightharpoonup",   TeXSymbol, FntSymbol, 0x00, NULL},  // euex 0x1a
//  {"rightharpoondown", TeXSymbol, FntSymbol, 0x00, NULL},  // euex 0x1b
//  {"leadsto",          TeXSymbol, FntSymbol, 0x00, NULL},  // lasy 0x3a
    {"uparrow",          TeXSymbol, FntSymbol, 0x22, NULL},
    {"Uparrow",          TeXSymbol, FntSymbol, 0x2a, NULL},
    {"downarrow",        TeXSymbol, FntSymbol, 0x23, NULL},
    {"Downarrow",        TeXSymbol, FntSymbol, 0x2b, NULL},
    {"updownarrow",      TeXSymbol, FntSymbol, 0x6c, NULL},
    {"Updownarrow",      TeXSymbol, FntSymbol, 0x6d, NULL},
    {"nearrow",          TeXSymbol, FntSymbol, 0x25, NULL},
    {"searrow",          TeXSymbol, FntSymbol, 0x26, NULL},
    {"swarrow",          TeXSymbol, FntSymbol, 0x2e, NULL},
    {"nwarrow",          TeXSymbol, FntSymbol, 0x2d, NULL},
    {"aleph",            TeXSymbol, FntSymbol, 0x40, NULL},
//  {"hbar",             TeXSymbol, FntSymbol, 0x00, NULL},  // msbm 0x7e
    {"imath",            TeXSymbol, FntItalic, 0x7b, NULL},
    {"jmath",            TeXSymbol, FntItalic, 0x7c, NULL},
//  {"ell",              TeXSymbol, FntSymbol, 0x00, NULL},  // ?
//  {"wp",               TeXSymbol, FntSymbol, 0x00, NULL},  // eufb 0x50
    {"Re",               TeXSymbol, FntSymbol, 0x3c, NULL},
    {"Im",               TeXSymbol, FntSymbol, 0x3d, NULL},
//  {"mho",              TeXSymbol, FntSymbol, 0x00, NULL},  // lasy 0x30
    {"prime",            TeXSymbol, FntSymbol, 0x30, NULL},
    {"emptyset",         TeXSymbol, FntSymbol, 0x3b, NULL},
    {"nabla",            TeXSymbol, FntSymbol, 0x35, NULL},
    {"surd",             TeXSymbol, FntSymbol, 0x72, NULL},
    {"top",              TeXSymbol, FntSymbol, 0x3e, NULL},
    {"bot",              TeXSymbol, FntSymbol, 0x3f, NULL},
    {"|",                TeXSymbol, FntSymbol, 0x6b, NULL},
//  {"angle",            TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x5c
    {"forall",           TeXSymbol, FntSymbol, 0x38, NULL},
    {"exists",           TeXSymbol, FntSymbol, 0x39, NULL},
    {"neg",              TeXSymbol, FntSymbol, 0x3a, NULL},
    {"flat",             TeXSymbol, FntItalic, 0x5d, NULL},
    {"natural",          TeXSymbol, FntItalic, 0x5c, NULL},
    {"sharp",            TeXSymbol, FntItalic, 0x5b, NULL},
    {"backslash",        TeXSymbol, FntSymbol, 0x6e, NULL},
    {"partial",          TeXSymbol, FntItalic, 0x40, NULL},
    {"infty",            TeXSymbol, FntSymbol, 0x31, NULL},
//  {"Box",              TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x04
//  {"Diamond",          TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x07
//  {"Triangle",         TeXSymbol, FntSymbol, 0x00, NULL},  // msam 0x4d
    {"clubsuit",         TeXSymbol, FntSymbol, 0x7c, NULL},
    {"diamondsuit",      TeXSymbol, FntSymbol, 0x7d, NULL},
    {"heartsuit",        TeXSymbol, FntSymbol, 0x7e, NULL},
    {"spadesuit",        TeXSymbol, FntSymbol, 0x7f, NULL},

 //
 // Things to be rendered in Roman since they are function names

    {"arccos",     TeXRoman,  0,         0,    (void *)"arccos"},
    {"arcsin",     TeXRoman,  0,         0,    (void *)"arcsin"},
    {"arctan",     TeXRoman,  0,         0,    (void *)"arctan"},
    {"arg",        TeXRoman,  0,         0,    (void *)"arg"},
    {"cos",        TeXRoman,  0,         0,    (void *)"cos"},
    {"cosh",       TeXRoman,  0,         0,    (void *)"cosh"},
    {"cot",        TeXRoman,  0,         0,    (void *)"cot"},
    {"coth",       TeXRoman,  0,         0,    (void *)"coth"},
    {"csc",        TeXRoman,  0,         0,    (void *)"csc"},
    {"deg",        TeXRoman,  0,         0,    (void *)"deg"},
    {"det",        TeXRoman,  0,         0,    (void *)"det"},
    {"dim",        TeXRoman,  0,         0,    (void *)"dim"},
    {"exp",        TeXRoman,  0,         0,    (void *)"exp"},
    {"gcd",        TeXRoman,  0,         0,    (void *)"gcd"},
    {"hom",        TeXRoman,  0,         0,    (void *)"hom"},
    {"inf",        TeXRoman,  0,         0,    (void *)"inf"},
    {"ker",        TeXRoman,  0,         0,    (void *)"ker"},
    {"lg",         TeXRoman,  0,         0,    (void *)"lg"},
    {"lim",        TeXRoman,  0,         0,    (void *)"lim"},
    {"liminf",     TeXRoman,  0,         0,    (void *)"liminf"},
    {"limsup",     TeXRoman,  0,         0,    (void *)"limsup"},
    {"ln",         TeXRoman,  0,         0,    (void *)"ln"},
    {"log",        TeXRoman,  0,         0,    (void *)"log"},
    {"max",        TeXRoman,  0,         0,    (void *)"max"},
    {"min",        TeXRoman,  0,         0,    (void *)"min"},
    {"Pr",         TeXRoman,  0,         0,    (void *)"Pr"},
    {"sec",        TeXRoman,  0,         0,    (void *)"sec"},
    {"sin",        TeXRoman,  0,         0,    (void *)"sin"},
    {"sinh",       TeXRoman,  0,         0,    (void *)"sinh"},
    {"sup",        TeXRoman,  0,         0,    (void *)"sup"},
    {"tan",        TeXRoman,  0,         0,    (void *)"tan"},
    {"tanh",       TeXRoman,  0,         0,    (void *)"tanh"},


//
// TeX things that take do not take an argument, as in
//              \word
// eg \displaystyle

    {"displaystyle", TeX0Arg, 0,         0,    (void *)doDisplayStyle},
// I only intend (at least to start with!) to support the \large
// directive in the context of \stackrel{\large A}{B} where it defeats
// the way that stackrel would otherwise shrink its first argument.
    {"large",        TeX0Arg, 0,         0,    (void *)doLarge},
// \neq seems to be a unique horrid case for me. I can not see a glyph for
// it in the Computer Modern set and so will end up synthesizing it as
// an overstrike of "=" and "/".
    {"neq",          TeX0Arg, 0,         0,    (void *)doNeq},
    {"not",          TeX0Arg, 0,         0,    (void *)doNot},

// The next two are needed for matrix layout. Maybe and with luck they
// will not occur freestanding.
    {"&",            TeX0Arg, 0,         0,    NULL},
    {"\\\\",         TeX0Arg, 0,         0,    NULL},
// The next bunch insert spacing manually
    {"\\*",          TeX0Arg, 0,         '*',  (void *)doSpaceCommand},
    {"\\ ",          TeX0Arg, 0,         ' ',  (void *)doSpaceCommand},
    {"\\,",          TeX0Arg, 0,         ',',  (void *)doSpaceCommand},
    {"\\!",          TeX0Arg, 0,         '!',  (void *)doSpaceCommand},
    {"\\:",          TeX0Arg, 0,         ':',  (void *)doSpaceCommand},
    {"\\;",          TeX0Arg, 0,         ';',  (void *)doSpaceCommand},
    {"\\_",          TeX0Arg, 0,         '_',  (void *)doSpaceCommand},

#define pack4ints(a,b,c,d) (((a)<<24) + ((b)<<16) + ((c)<<8) + (d))

    {"longleftarrow",      TeX0Arg, 0,
                           pack4ints(FntSymbol, 0x20, FntSymbol, 0x00), 
                           (void *)doAdjacent},
    {"Longleftarrow",      TeX0Arg, 0,
                           pack4ints(FntSymbol, 0x28, FntRoman, 0x3d),
                           (void *)doAdjacent},
    {"longrightarrow",     TeX0Arg, 0,
                           pack4ints(FntSymbol, 0x00, FntSymbol, 0x21), 
                           (void *)doAdjacent},
    {"Longrightarrow",     TeX0Arg, 0,
                           pack4ints(FntRoman, 0x3d, FntSymbol, 0x29), 
                           (void *)doAdjacent},
    {"longleftrightarrow", TeX0Arg, 0,
                           pack4ints(FntSymbol, 0x20, FntSymbol, 0x21), 
                           (void *)doAdjacent},
    {"Longleftrightarrow", TeX0Arg, 0,
                           pack4ints(FntSymbol, 0x28, FntSymbol, 0x29), 
                           (void *)doAdjacent},


//
// TeX things that take one argument, as in
//              \word {arg}
// eg \pmod{whatever}

    {"pmod",       TeX1Arg,   0,         0,    (void *)doPmod},
    {"mathrm",     TeX1Arg,   0,         0,    (void *)doMathRm},
    {"mathit",     TeX1Arg,   0,         0,    (void *)doMathIt},
    {"sqrt",       TeX1Arg,   0,         0,    (void *)doSqrt},
    {"fbox",       TeX1Arg,   0,         0,    (void *)doFbox},
    {"symb",       TeX1Arg,   0,         0,    (void *)doSymb},
//
// TeX things that take two arguments, as in
//              \word {arg1} {arg2}
// eg \frac{numerator}{denominator}
// Note that both frac and stackrel both make adjustments to the
// size of the naterial set as their arguments... but in eccentric
// and one-off ways!
    {"frac",       TeX2Arg,   '/',       0,    (void *)doFrac},
    {"stackrel",   TeX2Arg,   'S',       0,    (void *)doStackrel},

    {"rule",       TeXRule,   0,         0,    NULL},
    {NULL,         0,         0,         0,    NULL}
};


#define hashTableSize ((unsigned int)(sizeof(texWords)/sizeof(Keyword)))

// The hash function here is not especially clever or fast! But it should
// suffice. It looks at the first 4 characters of the string and returns
// a result in the range 0 to 511.

static unsigned int texHash(const char *s)
{
    unsigned int h = 0x123456;
    if (*s != 0)
    {   h = 169*h + *s++;
        if (*s != 0)
        {   h = 169*h + *s++;
            if (*s != 0)
            {   h = 169*h + *s++;
                h = 169*h + *s;
            }
        }
    }
    return (h ^ (h>>11)) % hashTableSize;
}

// returns either a reference to a Keyword record, or NULL if the word
// is not found.

static Keyword *lookupHash(const char *s)
{
    unsigned int h = texHash(s);
    for (;;)
    {   if (texWords[h].name == NULL) return NULL;
        else if (strcmp(s, texWords[h].name) == 0) return &texWords[h];
        else h = (h + 1) % hashTableSize;
    }
}

// On system-startup this code converts the initial neat array/table
// of keywords into a hash table.

static void rehashKeywordTable()
{
    unsigned int i = 0;
// First set a flag on every item that has not yet been re-hashed.
    while (texWords[i].name != NULL) texWords[i++].type |= TeXFlag;
#if 0
// I want my hash-table of LaTeX keywords to have a comfortable loading
// to balance lookup cost against the amount of waste space. The
// current state uses a little under 300 of the 512 entries, which
// seems satisfactory to me at present.
    printf("%d out of %d loading in hash table\n", i, hashTableSize);
#endif
    while (i < hashTableSize)
    {   texWords[i].name = NULL;
        texWords[i++].type = 0;
    }
    Keyword insert, pend;
    for (i=0; i<hashTableSize; i++)
    {   if ((texWords[i].type & TeXFlag) == 0) continue;
        pend = texWords[i];
        texWords[i].name = NULL;
        texWords[i].type = 0;
        while ((pend.type & TeXFlag) != 0)
        {   pend.type &= ~TeXFlag;
            insert = pend;
            unsigned int h = texHash(insert.name);
            for (;;)
            {   if (texWords[h].name == NULL)   // empty space to insert into
                {   texWords[h] = insert;
                    break;
                }
// I might come across a place where some not-yet-relocated entry lives. As
// far as the NEW hash table is concerned this represents empty space, so I
// insert there, moving the displaced data to a "pending" status.
                else if ((texWords[h].type & TeXFlag) != 0)
                {   pend = texWords[h];
                    texWords[h] = insert;
                    break;
                }
// If I find a hash table position that is already in use it can never be
// a match, so I just view it as a clash.
// I use a simple linear scan after clashes. This can lead to clustering
// but I am not that worried!
                h = (h + 1) % hashTableSize;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////

// I want to be able to parse LaTeX-like stuff so that I can display it.
// I will use a pretty naive parser! It will look for the special
// characters
//     # $ % & ~ _ ^ \ { and }
// It also has to treat some other individual characters individually
//     + = | < > ` '
// and any item of the form "\" followed either by a single punctuation
// mark or by a (case-sensitive) word.

// There is a "current state" and nesting constructs save and restore it.
// Eg if there are any instances of
//    { ... \em ... }
// then the "\em" sets a state for the materiual after it but until the
// end of the brace-enclosed block.
//
// Key bits of syntax are
//    \begin{word} ... \end{word}
//    \word-not-needing-args
//    \word-needing-arg { ... }
//    \word-needing-2-args { ... } { ... }
//    \word[ ... , ... ] { ... }           if cases with options are needed
//    { ... }
//    $ ... $
//    \leftX ... \rightX
//    item item item ...
//

// The stream of characters that I parse are returned by a procedure that
// is passed down to my code...

static getTeXchar *nextChar;

static int curChar;

// I had better make the size of my lexer buffer at last as wide as the
// longest item I ever expect to see on a line. Well I hope that any code
// that drives this splits lines well before 256 characters...

#define maxLexLength 256
static char lexerBuffer[maxLexLength+1];
static int lexType, lexLength;
static Keyword *lexKey;

#define lexError     0x00
#define lexEOF       0x01
#define lexSpecial   0x02
#define lexWord      0x03
#define lexNumber    0x04
#define lexBegin     0x05
#define lexEnd       0x06
#define lexSuper     0x07
#define lexSub       0x08

// More careful syntax, since this is what I will implement
//
// The category "P" is for complete items, either single words
// or things where their end is clear-cut because of bracketing rules.
//    P ::=  begin(word) E end(word)
//                         // I treat eg \begin{centre} s one lexical symbol
//                         // and need a bracketing rule for each such.
//      |    { E }
//      |    \( E \)
//      |    \[ E \]
//      |    $ E $
//      |    \leftX E \rightX
//      |    \begin{matrix} rows \end{matrix}
//      |    one-arg-word opts { E }
//      |    two-arg-word opts { E } { E }
//      |    word
//      |    punctuation-mark
//      ;
// The category "S" allows a "P" to be given optional sub- or super-scripts.
// It permits at most one of each. One can of course write something like
//    "{a^b}^c"
// if you really want, but "a^b^c" will not be valid in proper TeX. However
// as a matter of generosity I will allow it here via the code going a bit
// beyond the syntax written out here
//    S ::=  P
//      |    P ^ P
//      |    P _ P
//      |    P ^ P _ P
//      |    P _ P ^ P
// The category "E" is for a possibly empty list of "S" forms. I will in fact
// parameterise my code to read an "E" so that in one variant it stops only
// at a close bracket or end-of-file and in the other it also stops at
// a comma.
//    E ::=
//      |   S
//      |   E S
//      ;
// "opts" and "ol" provide for optional parameters marked out using square
// brackets and with commas to separate off separate parts. Note that I have
// a formal ambiguity here over the syntax "a,b" where the comma could be a
// punctuation mark as a P or separator between arguments. Actually inspection
// of the code that generated TeX for me shows that \sqrt is the only thing
// where an optional argument gets used, so I will handle the case specially
// for there and NOT use this general rule!
//    opts ::=
//         | []
//         | [ ol ]
//         ;
//    ol ::= E
//       | ol , E
//       ;
// I deal specially with matrices by recognising & and \\ as delimiters.
// I view an empty matrix as an error and have an extra constraint that things
// should be rectangular, ie each row should have the same number of items
// in it.
//    rows ::= matrow
//         | rows \\ matrow
//         ;
//    matrow ::= E
//         | matrow & E
//         ;
// QUESTION: Do I need to take special account of things that are to be
//           thought of as binary operators, such as +, - etc?
//           I may want to if I want the tree that I produce to be a
//           semantic model of the material being displayed and if I then
//           want selection to respect this structure. But to start with
//           I intend to try without.

// To do line-breaking here I will need to extend the syntax for E to be
// more like:
//
//    E ::=
//      |   S1
//      |   E S1
//      ;
// QUERY: especially in the light of REDLOG I may need precedence-related
// rules here for AND and OR and EQUALS. How pressing is that?
//    S1 := S2
//       | S1 + S2
//       | S1 - S2
//       | + S1
//       | - S1
//       ;
//    S2 ::= S3
//       | S2 \times S3
//       | \frac{E}{E}
//       ;
//    S3 ::= item LPAR ARGLIST RPAR
// etc.
// I am not yet really certain just how much I need to do here but my current
// thoughts are that for line-breaking I will need to be able to notice the
// cases for
//    A + B + C + D +
//    E + F + G                 break at a + or - rather than within a term
//                              and similarly for lists {A,B,C} and (A,B,C)
//
//    (... ... ...          vs    ... ... ...
//    ... ...) / (...)            -----------    for displayed fractions
//                                ... ... ...
//
//    matrix display where possible
//
//    Some uncomfortable fall-back for cases with huge expressions as
//    exponents, subscripts, single args for functions etc
//
//    Treatement of numbers that have huge numbers of digits (and I guess
//    words that are very very long too)
//
//    sqrt(... ... ...      vs   /---------------
//    ... ... ...)              v ... ... ... ...
//
//    Groupings implied by all sorts of brackets, also by the prefix
//    items \int, \sum (etc). This last one is NASTY since it is not clear
//    that there is any way to tell when the guarded expression ends!

static void nextSymbol();

static Box *readE(int stopAt);
#define stopComma 0x01
#define stopTab   0x02
#define stopNL    0x04
#define stopKet   0x08
static Box *readS();

// Some systems have problems with characters that have a numeric code
// less than (or possibly even equal to) 0x20. Although many modern systems
// can cope the Postscript fonts that I use provide re-mapped glyphs with
// code values in the 0x80 to 0xff range that may be safer to use.

// With some X servers I still have trouble with character 0xa1, which is
// where 0x00 gets mapped to. Actually it seems worse than that: I can
// re-map the font to change the code to yet something different and still
// sometimes the character does not appear. I reserve code 0xc5 for such
// and extra remapping, but the tables here do not touch it at present!

static char remapTable[33] =
{
    0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8,
    0xa9, 0xaa, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2,
    0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba,
    0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2,
    0xc3
};

static int remap(int ch)
{
#ifndef WIN32
// If I use Xft to render things I can afford to (and indeed had better)
// use glyph positions in ther original locations. Also if I am printing
// I will avoid remapping.
    return (char)ch;
#else
    int ch1;
    ch &= 0xff;       // in case chars are signed.
    if (ch <= 0x20) ch1 = remapTable[ch];
    else if (ch == 0x7f) ch1 = 0xc4;
    else ch1 = ch;
#ifdef TEST
    if ((char)ch != (char)ch1) printf("Char %x mapped to %x\n", ch, ch1 & 0xff);
#endif
    return (char)ch1;
#endif
}

#ifndef WIN32

// I will also set myself up so that I can restore the original encoding.

static char unmapTable[38] =
{
// Characters codes 0xa0 to 0xc5 are used where perhaps naturally you would
// have used 0x00 - 0x1f, 0x20 and 0x7f. This is because the non-printable
// and control characters might be intercepted somewhere and cause pain, but
// the Computer Modern Fonts tend to use all these codes as if they were
// perfectly ordinary.
    0x20, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0xab, 0xac, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c,
    0x1d, 0x1e, 0x1f, 0x20, 0x7f, 0xc5
};

static int unmap(int ch)
{
    ch &= 0xff;
    if (ch < 0xa0 || ch > 0xc5) return (char)ch;
    return unmapTable[ch - 0xa0];
}

#endif

static Box *readRow()
{
    Box *result = makeSymBox(SymNothing);
    Box *n = readE(stopTab + stopNL);
    if (n != NULL) result = makeNestBox(BoxBeside, result, n);
    while (lexType == lexSpecial &&
            strcmp(lexKey->name, "&") == 0)
    {   nextSymbol();
        n = readE(stopTab + stopNL);
        if (n != NULL) result = makeNestBox(BoxBeside, result, n);
    }
    return result;
}

static Box *readRows()
{
    Box *result = makeSymBox(SymNothing);
    Box *n = readRow();
    if (n != NULL) result = makeNestBox(BoxTower, result, n);
    while (lexType == lexSpecial &&
            strcmp(lexKey->name, "\\\\") == 0)
    {   nextSymbol();
        Box *n = readRow();
        if (n != NULL) result = makeNestBox(BoxTower, result, n);
    }
    return result;
}

static Box *readMatrix()
{
    Box *contents = NULL;
    TeXState saveState = currentState;
    nextSymbol();
    contents = readRows();
    if (lexType == lexError) return NULL;
    else if (lexType != lexEnd || matchMatrix != lexKey->font)
    {   printf("end does not match begin properly\n");
        printf("Want \\end{matrix} got %d/%d\n", lexType, lexKey->font);
        lexType = lexError;
        return NULL;
    }
    currentState = saveState;
    contents = makeMatrixBox(contents);
    nextSymbol();
    return contents;
}

static void skipUnit()
{
    if (lexType != lexWord) return;
    if (strcmp(lexerBuffer, "pt") == 0) nextSymbol();
}

static int readNumber()
{
    int r;
    if (lexType == lexNumber)
    {   sscanf(lexerBuffer, "%d", &r);
        nextSymbol();
        skipUnit();
        return r;
    }
    else if (lexType == lexSpecial && strcmp(lexerBuffer, "-") == 0)
    {   nextSymbol();
        if (lexType == lexNumber)
        {   sscanf(lexerBuffer, "%d", &r);
            nextSymbol();
            skipUnit();
            return -r;
        }
    }
    return 0;
}

static Box *readP()
{   switch (lexType)
    {
case lexBegin:
        {   int w = lexKey->font; // used to say which sort of "begin"
            if (w == matchMatrix) return readMatrix();
            int chL = lexKey->charCode;
            Box *contents = NULL;
            TeXState saveState = currentState;
            blockHandlerFunction *fn = (blockHandlerFunction *)lexKey->ptr;
            if (fn != NULL) fn(chL, ' ', NULL);
            nextSymbol();
            contents = readE(0);
            if (lexType == lexError) return NULL;
            else if (lexType == lexEOF)
            {
// Here if I find an EOF when I was expecting a close bracket of some sort
// I just treat it as if the close bracket had been found, an in the case
// of \left..\right I treat it as if I had seen "\right .".
                if (fn != NULL) contents = fn(chL, '.', contents);
                return contents;
            }
            else if (lexType != lexEnd || w != lexKey->font)
            {   printf("end does not match begin properly\n");
                printf("Want %d/%d got %d/%d\n",
                       lexEnd, w, lexType, lexKey->font);
                lexType = lexError;
// In this case I will not perform any side-effects that calling the handler
// function normally would at the end of a block. That certainly means,
// for instance, that I lose track of whether I am inside or outside "$"
// markers. But since I have reported an error and the parse is getting
// nowhere this does not worry me.
                return NULL;
            }
            currentState = saveState;
            if (fn != NULL) contents = fn(chL, lexKey->charCode, contents);
            nextSymbol();
            return contents;
        }
case lexWord:
        {   Box *b = makeTextBox(lexerBuffer, lexLength,
                         currentState.currentFont); // includes currentSize
            nextSymbol();
            return b;
        }
case lexNumber:
        {   Box *b = makeTextBox(lexerBuffer, lexLength,
                         FntRoman + currentSize);
            nextSymbol();
            return b;
        }
case lexSpecial:   // in this case lexKey tells me which keyword it is.
        switch (lexKey->type)
        {
    case TeXSymbol:
            {   char s[2];
                s[0] = remap(lexKey->charCode);
                s[1] = 0;
                Box *b = makeTextBox(s, 1, lexKey->font + currentSize);
                nextSymbol();
                return b;
            }
    case TeXWSymbol:
            {   char s[2];
                s[0] = remap(lexKey->charCode);
                s[1] = 0;
                Box *b = makeTextBox(s, 1, lexKey->font + currentSize);
                nextSymbol();
                return makeNestBox(BoxPadSpace, b, NULL);
            }
    case TeXVSymbol:
// This case will need MORE WORK in a couple of ways:
//   (a) the symbol used is from the cmex font and so is positioned as
//       a descender. It will need moving to put it where it wants to go!
//   (b) subscripts and superscripts for these objects get put in special
//       places. Eg consider \sum{i=0}^{n}.
// I mark for these by setting the "FntBig" bit in the byte that gives font
// and size. That then mostly has to adjust the code that lays out subscripts.
            {   char s[2];
                s[0] = remap(lexKey->charCode);
                s[1] = 0;
                Box *b = makeTextBox(s, 1, lexKey->font + FntBig + currentSize);
                nextSymbol();
                return b;
            }
    case TeXRoman:
            {   Box *b = makeTextBox((const char *)lexKey->ptr,
                                     strlen((const char *)lexKey->ptr),
                                     FntRoman + currentSize);
                nextSymbol();
                return b;
            }
    case TeXScript:
            printf("TeX script-marker found but not handled (%s)\n", lexKey->name);
            nextSymbol();
            return NULL;
    case TeX0Arg:
            if (lexKey->ptr != NULL)
            {   Box *b = ((keywordHandlerFunction *)(lexKey->ptr))(lexKey->charCode);
                nextSymbol();
                return b;
            }
            printf("TeX keyword 0 found but not handled (%s)\n", lexKey->name);
            nextSymbol();
            return NULL;
    case TeX1Arg:
// One-arg things can include cases such as "\sqrt" which need to support
// optional args as well as the mandatory one. As best I can see in the
// current tmprint code "\sqrt" is the only such case used! Furthermore
// I think it only ever puts ONE item within the "[]", as in
//           \sqrt[3]{1+x}      or    \sqrt[p]{A}
// but it does put a "\," within the square brackets to adjust spacing.
            {   Keyword *key = lexKey;   // remember what introduced this
                Box *contents = NULL, *optarg = NULL;
                TeXState saveState = currentState;
                oneArgHandlerFunction *fn = (oneArgHandlerFunction *)key->ptr;
                nextSymbol();
// Check here for a "["
                if (lexType == lexSpecial &&
                    strcmp(lexKey->name, "[") == 0)
                {   nextSymbol();
                    if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
                    optarg = readE(stopKet);
                    if (lexType != lexSpecial ||
                        strcmp(lexKey->name, "]") != 0)
                    {   printf("\"]\" not found\n");
                        lexType = lexError;
                        currentState = saveState;
                        return NULL;
                    }
                    currentState = saveState;
                    nextSymbol();
                }
// The state I use when parsing the argument may be changed by this where I
// call the handler with NULL arguments.
                if (fn != NULL) fn(NULL, NULL);
                if (lexType != lexBegin ||
                    lexKey->font != matchBrace)
                {   printf("\"{\" expected after keyword \"\\%s\"\n",
                        lexKey->name);
                    lexType = lexError;
                    currentState = saveState;
                    return NULL;
                }
                else nextSymbol();
                contents = readE(0);
                if (lexType == lexError)
                {   currentState = saveState;
                    return NULL;
                }
                else if (lexType != lexEnd || lexKey->font != matchBrace)
                {
// While I am lenient about SOME forms of bracketing, the "{}" surrounding
// arguments must be complete in one section of TeX input.
                    printf("\"}\" not found\n");
                    lexType = lexError;
                    currentState = saveState;
                    return NULL;
                }
                nextSymbol();
                currentState = saveState;
                if (fn != NULL) contents = fn(contents, optarg);
                return contents;
            }
    case TeX2Arg:
            {   Keyword *key = lexKey;
                Box *b1, *b2;
                TeXState saveState = currentState;
                twoArgsHandlerFunction *fn = (twoArgsHandlerFunction *)key->ptr;
                if (fn == NULL)
                {   printf("incomplete implementation for \"\\%s\"\n", lexKey->name);
                    return NULL;
                }
                nextSymbol();
                if (lexType != lexBegin ||
                    lexKey->font != matchBrace)
                {   printf("\"{\" expected after keyword \"\\%s\"\n",
                        lexKey->name);
                    lexType = lexError;
                    return NULL;
                }
                else nextSymbol();
// The SECOND (and deeper) depth of \frac causes its contents
// to be set in a smaller font, as for subscripts.
                if (key->font == '/')
                {   if (currentState.insideFrac)
                    {   if (currentSize < FntScrScr)
                            currentState.currentFont+=FntScript;
                    }
                    else currentState.insideFrac = 1;
                }
                if (key->font == 'S' &&
                    currentSize < FntScrScr)
                    currentState.currentFont+=FntScript;
                b1 = readE(0);
                if (lexType == lexError)
                {   currentState = saveState;
                    return NULL;
                }
                else if (lexType != lexEnd || lexKey->font != matchBrace)
                {   printf("\"}\" not found\n");
                    lexType = lexError;
                    currentState = saveState;
                    return NULL;
                }
                nextSymbol();
                currentState = saveState;
                if (key->font == '/')
                {   if (currentState.insideFrac)
                    {   if (currentSize < FntScrScr)
                            currentState.currentFont+=FntScript;
                    }
                    else currentState.insideFrac = 1;
                }
// The second arg can be any sort of block, but it could
// also be a simple atom. Thus "\frac{1}2" will be accepted
                b2 = readP();
                currentState = saveState;
                return fn(b1, b2);
            }
    case TeXRule:  // I want to support \rule[offset]{height}{width}
            {   Box *b1;
                int depth=0, height=0, width=0;
                TeXState saveState = currentState;
                nextSymbol();
                if (lexType == lexSpecial &&
                    strcmp(lexKey->name, "[") == 0)
                {   nextSymbol();
                    depth = readNumber();
                    if (lexType != lexSpecial ||
                        strcmp(lexKey->name, "]") != 0)
                    {   printf("\"]\" not found\n");
                        lexType = lexError;
                        currentState = saveState;
                        return NULL;
                    }
                    currentState = saveState;
                    nextSymbol();
                }
                currentState = saveState;
                if (lexType != lexBegin ||
                    lexKey->font != matchBrace)
                {   printf("\"{\" expected after keyword \"\\%s\"\n",
                        lexKey->name);
                    lexType = lexError;
                    currentState = saveState;
                    return NULL;
                }
                else nextSymbol();
                width = readNumber();
                if (lexType == lexError)
                {   currentState = saveState;
                    return NULL;
                }
                else if (lexType != lexEnd || lexKey->font != matchBrace)
                {   printf("\"}\" not found\n");
                    lexType = lexError;
                    currentState = saveState;
                    return NULL;
                }
                nextSymbol();
                currentState = saveState;
// The second arg can be any sort of block, but it could
// also be a simple atom. Thus "\rule{1}2" will be accepted.
                if (lexType == lexBegin &&
                    lexKey->font == matchBrace)
                {   nextSymbol();
                    height = readNumber();
                    if (lexType == lexError) return NULL;
                    else if (lexType != lexEnd || lexKey->font != matchBrace)
                    {   printf("\"}\" not found\n");
                        lexType = lexError;
                        return NULL;
                    }
                    nextSymbol();
                }
                else height = readNumber();
                currentState = saveState;
                b1 = makeSymBox(SymRule);
                b1->sym.height = height+depth;
                b1->sym.depth = -depth;
                b1->sym.width = width;
                return b1;
            }
    default:
            printf("TeX keyword found but not handled (%s)\n", lexKey->name);
            nextSymbol();
            return NULL;
        }
default:
        printf("TeX syntax problem\n");
        lexType = lexError;
case lexError:     // if the token is lexError a diagnostic has already
                   // been printed.
        return NULL;
    }
    return NULL;
}

static Box *readS()
{
    Box *base, *super=NULL, *sub=NULL;
    base = readP();
    for (;;)
    {   if (lexType == lexSuper)
        {   nextSymbol();
            TeXState saveState = currentState;
            if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
            super = readP();
            currentState = saveState;
            if (lexType == lexSub)
            {   nextSymbol();
                saveState = currentState;
                if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
                sub = readP();
                currentState = saveState;
            }
        }
        else if (lexType == lexSub)
        {   nextSymbol();
            TeXState saveState = currentState;
            if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
            sub = readP();
            currentState = saveState;
            if (lexType == lexSuper)
            {   nextSymbol();
                saveState = currentState;
                if (currentSize < FntScrScr) currentState.currentFont+=FntScript;
                super = readP();
                currentState = saveState;
            }
        }
// Now I have parsed a bit: glue the boxes together...
        if (sub == NULL)
        {   if (super != NULL)
                base = makeNestBox(BoxSuperscript, base, super);
        }
        else if (super == NULL) base = makeNestBox(BoxSubscript, base, sub);
        else base = makeNest3Box(BoxBothScripts, base, sub, super);
// Going beyond what TeX supports I will permit things like
// x^y^z and x_y_z. I group sub- and superscripts so that at each level
// I support one of each in either order. The resulting layout may be
// less then perfect but should be what you would have got with
// {x^y}^z etc so is not outrageous. 
        if (lexType != lexSuper &&
            lexType != lexSub) break;
    }
    return base;
}

static Box *readE(int stopAt)
{
// I ALWAYS stop if I see a "}" or an "\end{xxx}". I can optionally
// stop on ",", "&" or "\\" (the first of these is used in optional argument
// lists and the second two in matrixes.
    Box *result = NULL;
// This ALWAYS stops as a lexEnd (or error or eof). Depending on the
// bitmask given as an argument it may stop at "\\", "&", "," or "]" too
    while (lexType != lexEnd &&
           lexType != lexError &&
           lexType != lexEOF &&
           (!(stopAt & stopTab) ||
            lexType != lexSpecial ||
            strcmp(lexKey->name, "&") != 0) &&
           (!(stopAt & stopNL) ||
            lexType != lexSpecial ||
            strcmp(lexKey->name, "\\\\") != 0) &&
           (!(stopAt & stopKet) ||
            lexType != lexSpecial ||
            strcmp(lexKey->name, "]") != 0) &&
           (!(stopAt & stopComma) ||
            lexType != lexSpecial ||
            strcmp(lexKey->name, ",") != 0))
    {   Box *n = readS();
        if (result == NULL) result = n;
        else if (n != NULL)
            result = makeNestBox(BoxBeside, result, n);
    }
    return result;
}

static Box *readE1()
{
// Read stuff until EOF.
    Box *result = NULL;
    while (lexType != lexError &&
           lexType != lexEOF)
    {
// Here if I get an "unexpected" close bracket I will in effect insert a
// "\left ." at the start of my input to match it.
        if (lexType == lexEnd)
        {   blockHandlerFunction *fn = (blockHandlerFunction *)lexKey->ptr;
            if (result == NULL) result = makeSymBox(SymNothing);
            if (fn != NULL) result = fn('.', lexKey->charCode, result);
            nextSymbol();
            continue;
        }
        Box *n = readS();
        if (result == NULL) result = n;
        else if (n != NULL)
            result = makeNestBox(BoxBeside, result, n);
    }
    return result;
}

static void nextSymbol()
{
// Discard whitespace
    while (curChar != 0 && isspace(curChar)) curChar = (*nextChar)();
// Detect end of input
    if (curChar == 0)
    {   lexType = lexEOF;
        return;
    }
// OK, now we have the start of a new symbol.
    switch (curChar)
    {
case '%':               // discard comments
        while ((curChar = (*nextChar)()) != 0 && curChar != '\n');
        nextSymbol();
        return;
case '^':
        lexType = lexSuper;
        curChar = (*nextChar)();
        return;
case '_':
        lexType = lexSub;
        curChar = (*nextChar)();
        return;
case '{':
case '}':
case '&':
        lexerBuffer[0] = curChar;
        lexerBuffer[1] = 0;
        lexLength = 1;
        lexKey = lookupHash(lexerBuffer);
        if (curChar == '{') lexType = lexBegin;
        else if (curChar == '}') lexType = lexEnd;
        else lexType = lexSpecial;
        curChar = (*nextChar)();
        return;
case '$':
        lexerBuffer[0] = curChar;
        lexerBuffer[1] = 0;
        lexLength = 1;
        lexKey = lookupHash(lexerBuffer);
// "$" will be a BEGIN if you are not in math mode, or an END if you are!
// This is yet another curious hack to cope with the syntax of LaTeX, which
// appears somewhat curious in places.
        lexType = insideDollars ? lexEnd : lexBegin;
        curChar = (*nextChar)();
        return;
// A bunch of characters are handled in a magic way here because they
// might map onto some specific font or character coding.
case '+':   case '-':   case '*':   case '/':
case ':':   case ';':   case '@':   case ',':
case '.':   case '?':   case '!':   case '|':
case '`':   case '#':   case '~':   case '=':
case '(':   case ')':   case '<':   case '>':
case '[':   case ']':
// "NOTSIGN" ??
        lexerBuffer[0] = curChar;
        lexerBuffer[1] = 0;
        lexLength = 1;
        if (DEBUGFONT & 8) printf("lexer special char %s\n", lexerBuffer);
        lexKey = lookupHash(lexerBuffer);
        lexType = lexSpecial;
        curChar = (*nextChar)();
        return;
case '\\':
        lexLength = 0;
        curChar = (*nextChar)();
        if (curChar == 0)             //  Treat "\<eof>" as just <eof>
        {   lexType = lexEOF;
            return;
        }
        while (isalnum(curChar))
        {   if (lexLength < maxLexLength)
                lexerBuffer[lexLength++] = curChar;
            curChar = (*nextChar)();
        }
// I assemble EITHER "\word" or "\delim"
        if (lexLength == 0)
        {   lexerBuffer[lexLength++] = '\\';   // put the "\" explicitly there
            lexerBuffer[lexLength++] = curChar;
            curChar = (*nextChar)();
        }
        lexerBuffer[lexLength] = 0;
// There is an UTTERLY odd bit of lexical treatment here that
// makes "\left(" one token. What I do is to take "\left" and "\right"
// and treat the token after it as part of a single token.
// Thus I have in effect "\left (" as just one token.
// The item following one of the words \left or \right must be a TeX
// "delimiter" and they can be in one of 3 forms:
//     character            (,),[,],/,|
//     escaped character    \{, \}, \|
//     escaped word         \lfloor, \Uparrow etc etc
// I will pack things in being a bit generous in what I allow, but bad cases
// will then get spotted because they will count as unknown TeX keywords.
        if ((strcmp(lexerBuffer, "left") == 0 ||
             strcmp(lexerBuffer, "right") == 0) &&
            curChar != 0)
        {   while (curChar != 0 && isspace(curChar)) curChar = (*nextChar)();
            lexerBuffer[lexLength++] = ':';
            if (curChar == '\\')
            {   lexerBuffer[lexLength++] = curChar;  // insert the backslash
                curChar = (*nextChar)();
                if (curChar != 0 && isalnum(curChar))
                {   while (isalnum(curChar))         // \word
                    {   if (lexLength < maxLexLength)
                            lexerBuffer[lexLength++] = curChar;
                        curChar = (*nextChar)();
                    }
                }
                else if (curChar != 0)               // \delim
                {   lexerBuffer[lexLength++] = curChar;
                    curChar = (*nextChar)();
                }
            }
            else if (curChar != 0)                   // just a delim
            {   lexerBuffer[lexLength++] = curChar;
                curChar = (*nextChar)();
            }
            lexerBuffer[lexLength] = 0;
        }
        lexKey = lookupHash(lexerBuffer);
        if (lexKey == NULL)
        {   printf("Unrecognised keyword \"\\%s\"\n", lexerBuffer);
            lexType = lexError;
            return;
        }
        if (lexKey->type == TeXBeginWord) // "\begin" or "\end"
        {   int beginFlag = lexKey->font;
            while (curChar != 0 && isspace(curChar)) curChar = (*nextChar)();
            if (curChar != '{')
            {   printf("Brace expected after \\begin or \\end\n");
                lexType = lexError;
                return;
            }
            else curChar = (*nextChar)();
            while (curChar != 0 && isspace(curChar)) curChar = (*nextChar)();
            lexLength = 0;
            lexerBuffer[lexLength++] = beginFlag ? '(' : ')';
            while (isalnum(curChar))
            {   if (lexLength < maxLexLength)
                    lexerBuffer[lexLength++] = curChar;
                curChar = (*nextChar)();
            }
            while (curChar != 0 && isspace(curChar)) curChar = (*nextChar)();
            if (curChar != '}')
            {   printf("Closing brace expected after \\begin or \\end\n");
                lexType = lexError;
                return;
            }
            else curChar = (*nextChar)();
            lexerBuffer[lexLength] = 0;
            lexKey = lookupHash(lexerBuffer);
            if (lexKey == NULL)
            {   printf("Unrecognised \\begin or \\end \"\\%s\"\n",
                       &lexerBuffer[1]);
                lexType = lexError;
                return;
            }
            lexType = beginFlag ? lexBegin : lexEnd;
            return;
        }
// I now need to cope with "\left(", "\(" and the like which are "begin/end"
// style items.
        if (lexKey->type == TeXBegin) lexType = lexBegin;
        else if (lexKey->type == TeXEnd) lexType = lexEnd;
        else lexType = lexSpecial;
        return;
default:
        lexLength = 0;
// Anything that starts with a digit will be taken to be a number. I permit
// digits then possibly "." followewd by more digits and possibly an exponent
// introduced by "e" or "E".
        if (isdigit(curChar))   // handle as a number
        {   while (isdigit(curChar))
            {   if (lexLength < maxLexLength)
                    lexerBuffer[lexLength++] = curChar;
                curChar = (*nextChar)();
            }
            if (curChar == '.')
            {   if (lexLength < maxLexLength)
                    lexerBuffer[lexLength++] = curChar;
                curChar = (*nextChar)();
                while (isdigit(curChar))
                {   if (lexLength < maxLexLength)
                        lexerBuffer[lexLength++] = curChar;
                    curChar = (*nextChar)();
                }
            }
            if (curChar == 'e' || curChar == 'E')
            {   if (lexLength < maxLexLength)
                    lexerBuffer[lexLength++] = curChar;
                curChar = (*nextChar)();
                if (curChar == '+' || curChar == '-')
                {   if (lexLength < maxLexLength)
                        lexerBuffer[lexLength++] = curChar;
                    curChar = (*nextChar)();
                }
                while (isdigit(curChar))
                {   if (lexLength < maxLexLength)
                        lexerBuffer[lexLength++] = curChar;
                    curChar = (*nextChar)();
                }
            }
            lexerBuffer[lexLength] = 0;
            lexType = lexNumber;
            return;
        }
        while (isalnum(curChar))
        {   if (lexLength < maxLexLength)
                lexerBuffer[lexLength++] = curChar;
            curChar = (*nextChar)();
        }
        if (lexLength == 0)
        {   lexerBuffer[lexLength++] = curChar;
            curChar = (*nextChar)();
        }
        lexerBuffer[lexLength] = 0;
        lexType = lexWord;
        return;
    }
}

Box *parseTeX(getTeXchar *fn, int owner)
{
    nextChar = fn;
    poolStartChunk(owner);
    curChar = (*nextChar)();
    nextSymbol();
    if (DEBUGFONT & 8) printf("lexType = %d\n", lexType);
// That has got the lexer ready - now I can do the REAL parsing!
// I do my parsing here in \displaymath mode, so the font I will use
// by default will be an italic one.
    insideDollars = 0;
    currentState.currentFont = FntItalic + FntRegular;
    currentState.insideFrac = 0;
// now the paser is initialised...
    Box *r = readE1();
    if (r != NULL) r = makeTopBox(r); // hook on a handle to the chunk start.
    poolEndChunk();
    return r;
}

void updateOwner(Box *b, int p)
{
    IntVoidStar *chunk = (IntVoidStar *)(b->top.chunk);
    chunk->i = p;
}

///////////////////////////////////////////////////////////////////////////

#ifdef WIN32

#define setFont1(dc, ff) dc->setFont((FXFont *)ff)

static void drawText1(FXDC *dc, int x, int y, const char *ss, int l)
{
    int utflength = 0;
    while (l > 0)
    {   int c = *ss++ & 0xff;
        l--;
        if (c < 0x80) utfchars[utflength++] = c;
        else
        {   utfchars[utflength++] = 0xc0 | (c >> 6);
            utfchars[utflength++] = 0x80 | (c & 0x3f);
        }
    }
    dc->drawText(x, y, utfchars, utflength);
}




#else

static void setFont1(FXDC *dc, void *ff)
{
    ftFont = (XftFont *)ff;
}

static void drawText1(FXDC *dc, int x, int y, const char *ss, int l)
{
    l = convertGlyphs(ss, l);
    XftDrawGlyphs(ftDraw, &ftBlack, ftFont,
                  x, y, glyphs, l);
}

#endif

///////////////////////////////////////////////////////////////////////////


static void paintBracket(FXDC *dc, int type, int flags,
                         int x, int y, int height, int depth)
{
// See the LaTeX manual for a list of "delimiters", and note that I encode
// each as a single character here, with a maybe curious encoding. Also I
// draw square root signs here since they are also variable height items
// manufactured (sometimes) out of multiple glyphs in a tower.
//
// Maybe the case that concerns me most here will be \langle and \rangle since
// they need horizontal offsets for glyphs. At least to start with I will not
// support them!!
    int size = flags & FontSizeMask;
    int n = bracketCount(flags, height, depth);
// n is the size of bracket needed, measured in units of 0.5 times the
// normal cmex font height
    if (n == 1)
    {   int fnt = FntSymbol, ch = 0x00;
        switch(type)
        {
    case '.':
            return;
    case '(':
            fnt = FntRoman;
            ch = 0x28;
            break;
    case ')':
            fnt = FntRoman;
            ch = 0x29;
            break;
    case '[':
            fnt = FntRoman;
            ch = 0x5b;
            break;
    case ']':
            fnt = FntRoman;
            ch = 0x5d;
            break;
    case '{':
            ch = 0x66;
            break;
    case '}':
            ch = 0x67;
            break;
    case '|':                 // LEFT vertical bar
            ch = 0x6a;
            break;
    case '!':                 // RIGHT vertical bar
            ch = 0x6a;
            break;
    case 'Q':                 // square root marker
            ch = 0x70;        // NB this is a descender
            y -= mathFontHeight[size];
            break;
    case '/':                 // slash
            ch = 0x36;
            break;
    case '\\':                // backslash
            ch = 0x6e;
            break;
    case 'L':                 // lfloor
            ch = 0x62;
            break;
    case 'G':                 // lceil (like Gamma)
            ch = 0x64;
            break;
    case 'J':                 // rfloor
            ch = 0x63;
            break;
    case '7':                 // rceil
            ch = 0x65;
            break;
    case '<':                 // langle
            ch = 0x68;
            break;
    case '>':                 // rangle
            ch = 0x69;
            break;
    case '#':                 // \|    (double vertical bar)
            ch = 0x6b;
            break;
    case '^':                 // uparrow
            ch = 0x22;
            break;
    case 'v':                 // downarrow
            ch = 0x23;
            break;
    case 'A':                 // Uparrow
            ch = 0x2a;
            break;
    case 'V':                 // Downarrow
            ch = 0x2b;
            break;
    case 'b':                 // updownarrow
            ch = 0x6c;
            break;
    case 'B':                 // Updownarrow
            ch = 0x6d;
            break;
    default:
            printf("Attempt to paint unknown delimiter \"%c\"\n", type);
            return;
        }
        char cc[1];
        cc[0] = remap(ch);
        setFont1(dc, mathFont[fnt + size]);
        drawText1(dc, x, y, cc, 1);
        return;
    }
    void *ff = mathFont[FntExtension + size];
    int h = mathFontHeight[size], d = mathFontDepth[size];
    int height1 = height + depth;
    int h1 = h + d;
    int height2 =(9*n*(h + d) + 8)/16;
// height2 will be the actual total height of the bracket that I draw.
    if (height2 < height1) height2 = height1; // top align always
    y = y - height - (height2 - height1 + 1)/2;
// The big delimiters are present in the font as "descenders" and so the
// place I must paint them is referenced to their top. y is now the
// coordinate to paint the top glyph.
    int n1 = n;
    if (n1 > 6) n1 = 6;
    const char *topp;
    int top, tower, mid = 0x00, bottom;
    int toph = 0;
    int ntower = -1;
    switch (type)
    {
case '.':
        return;
case '(':
        topp = "\x00\x10\x12\x20\x30";
        toph = 3;
        tower = 0x42;
        if (n >= 6) ntower = n - 6;
        bottom = 0x40;
        break;
case ')':
        topp = "\x01\x11\x13\x21\x31";
        toph = 3;
        tower = 0x43;
        if (n >= 6) ntower = n - 6;
        bottom = 0x41;
        break;
case '[':
        topp = "\x02\x68\x15\x22\x32";
        toph = 3;
        tower = 0x36;
        if (n >= 6) ntower = n - 6;
        bottom = 0x34;
        break;
case ']':
        topp = "\x03\x69\x16\x23\x33";
        toph = 3;
        tower = 0x37;
        if (n >= 6) ntower = n - 6;
        bottom = 0x35;
        break;
case '{':
        topp = "\x08\x6e\x1a\x28\x38";
        toph = 3;
        tower =  0x3e;
        if (n >= 6) ntower = n - 6;
        mid = 0x3c;
        bottom = 0x3a;
        break;
case '}':
        topp = "\x09\x6f\x1b\x29\x39";
        toph = 3;
        tower =  0x3e;
        if (n >= 6) ntower = n - 6;
        mid = 0x3d;
        bottom = 0x3b;
        break;
case '|':           // LEFT vertical bar
        topp = "\x0c\x0c\x42\x42\x42";
// Note that vertical bars have to use a tower of glyphs right from
// the very start, while all the other cases can use a single glyph for
// heights 2,3,4 and 5.
        toph = 1;
        tower =  0x0c;
        if (n >= 2) ntower = n - 2;
        bottom = 0x0a;
        break;
case '!':           // RIGHT vertical bar
        topp = "\x0c\x0c\x43\x43\x43";
        toph = 1;
        tower =  0x0c;
        if (n >= 2) ntower = n - 2;
        bottom = 0x0a;
        break;
case 'Q':
        topp = "\x70\x71\x72\x73\x76";
        toph = 1;
        tower = 0x75;
        if (n > 5) ntower = n - 4;
        bottom = 0x74;
        break;
case 'L':           // lfloor
        topp = "\x04\x6a\x16\x24\x36";
        toph = 1;
        tower = 0x36;
        if (n > 5) ntower = n - 4;
        bottom = 0x34;
        break;
case 'G':           // lceil
        topp = "\x06\x6c\x18\x22\x32";
        toph = 3;
        tower = 0x36;
        if (n > 5) ntower = n - 4;
        bottom = 0x36;
        break;
case 'J':           // rfloor
        topp = "\x05\x6b\x17\x25\x37";
        toph = 1;
        tower = 0x37;
        if (n > 5) ntower = n - 4;
        bottom = 0x35;
        break;
case '7':           // rceil
        topp = "\x07\x6d\x19\x23\x33";
        toph = 3;
        tower = 0x37;
        if (n > 5) ntower = n - 4;
        bottom = 0x37;
        break;
case '^':           // uparrow
// ALL cases are built up as towers, not just especially big ones
        topp = "\xff\xff\xff\xff\x78";
        toph = 1;
        tower = 0x3f;
        ntower = n - 2;
        bottom = 0x3f;
        break;
case 'v':           // downarrow
        topp = "\xff\xff\xff\xff\x3f";
        toph = 1;
        tower = 0x3f;
        ntower = n - 2;
        bottom = 0x79;
        break;
case 'b':           // updownarrow
        topp = "\xff\xff\xff\xff\x78";
        toph = 1;
        tower = 0x3f;
        ntower = n - 2;
        bottom = 0x79;
        break;
case 'A':           // Uparrow
        topp = "\xff\xff\xff\xff\x7e";
        toph = 1;
        tower = 0x77;
        ntower = n - 2;
        bottom = 0x77;
        break;
case 'V':           // Downarrow
        topp = "\xff\xff\xff\xff\x77";
        toph = 1;
        tower = 0x77;
        ntower = n - 2;
        bottom = 0x7f;
        break;
case 'B':           // Updownarrow
        topp = "\xff\xff\xff\xff\x7e";
        toph = 1;
        tower = 0x77;
        ntower = n - 2;
        bottom = 0x7f;
        break;
case '#':           // \| double vertical line
        topp = "\xff\xff\xff\xff\x77";
        toph = 1;
        tower = 0x77;
        ntower = n - 2;
        bottom = 0x77;
        break;
case '<':           // langle
case '>':           // rangle
case '\\':          // backslash
case '/':           // slash
default:
        printf("Attempt to paint unknown delimiter \"%c\"\n", type);
        return;
    }
    top = topp[n1-2];
    if ((top & 0xff) == 0xff) top = topp[4];
// I general here I need to display in one of several patterns based on
// midflag and ntower. I use ntower=-1 for the case where a single
// glyph pains the entire bracket, otherwise ntower is a repeat
// count.  mid is non-zero only in the "{}" case where everything is
// messier... In the easy case I go:
//
//     top                            height is toph
//     tower    done ntower times     height is 1
//     bottom                         height is toph (except sqrt!)
//
// If mid is non-zero I use:
//
//     top                            height is 1.5
//     tower    done ntower times     height is 0.5
//     mid                            height is 3
//     tower    done ntower times     height is 0.5
//     bottom                         height is 1.5
//

    char ss[1];
    setFont1(dc, ff);
// Draw the top glyph
    ss[0] = remap(top);
    drawText1(dc, x, y, ss, 1);
    if (ntower < 0) return;   // all done in just one glyph
    if (mid == 0x00)
    {   int delta2y = toph*h1; // twice the y delta needed for next glyph
        while (ntower > 1)
        {   ss[0] = remap(tower);
            drawText1(dc, x, y+(9*delta2y)/16, ss, 1);
            delta2y += h1;
            ntower--;
        }
        ss[0] = remap(bottom);
        drawText1(dc, x, y+(9*delta2y)/16, ss, 1);
        return;
    }
// Now I have a continuation of a { or }.
    int delta4y = toph*h1;
    for (n=1; n<ntower; n++)
    {   ss[0] = remap(tower);
        drawText1(dc, x, y+(9*delta4y)/32, ss, 1);
        delta4y += h1;
    }
    ss[0] = remap(mid);
    drawText1(dc, x, y+(9*delta4y)/32, ss, 1);
    delta4y += 6*h1;
    for (n=1; n<ntower; n++)
    {   ss[0] = remap(tower);
        drawText1(dc, x, y+(9*delta4y)/32, ss, 1);
        delta4y += h1;
    }
    ss[0] = remap(bottom);
    drawText1(dc, x, y+(9*delta4y)/32, ss, 1);
    return;
}

void paintBox(FXDC *dc, Box *b, int x, int y)
{
    void *ff;
    TextBox *t;
    SymBox *s;
    BracketBox *bb;
    int h1, d1;
    switch (b->text.type)
    {
case BoxSym:
        s = &(b->sym);
        switch (s->flags & SymTypeMask)
        {
    case SymStar:
    case SymComma:
    case SymExclam:
    case SymColon:
    case SymSemiColon:
    case SymBlank:
    case SymNothing:
    case SymRule:     // this is a rule with either height or width zero
            return;
    case SymUnderscore:
            {   int h = (mathFontHeight[b->nest.flags & FontSizeMask]+12)/25;
                if (h <= 0) h = 1;  // ensure bar is at least 1 pixel tall
                dc->fillRectangle(x, y, s->width, h);
                return;
            }
    default:
            printf("SymBox type %.2x not handled in paintBox\n", s->flags);
            return;
        }
case BoxText:
// Here (and in measureBox1) I have a WORRY. The material that ends up in a
// text box can be pretty-well arbitrary strings of ascii characters, but the
// font I am using may very well not cope with things beyond letters and
// numbers. And some glyphs that I might like (such as space and underline)
// are not even present in the Computer Modern fonts that I have available.
// so if I want to be REALLY picky I will need to scan character by character
// and take special action on characters that need it. While I am doing that
// I might take the view that in the Roman font I should convert things to
// use ligatures (eg ff, fi, fl, ffi, ffl) when relevant, and do kerning
// for myself...
//
// It may well be that via tmprint the only things that get into a BoxText
// directly involve simple alphanumerics. So otherwise I get BoxTexts that I
// myself have created in the clear knowledge of font-related complexity. So
// perhaps this is less of a worry than I had at one time feared! But I should
// try to ensure that I do not put blanks etc in these boxes.
//
// If the "FntBig" flag is set I will shift the material printed by
// my nominal character-cell height...  This shift seems a little delicate to
// me in that I ought to position the "big" symbol (eg \sum, \int, \bigvee)
// with regard to the base-line of normal symbols.
        t = &(b->text);
        if (t->flags & FntBig)
        {   int h = mathFontHeight[t->flags & FontSizeMask];
            int d = mathFontDepth[t->flags & FontSizeMask];
// The calculations here had better match those performed when I measured
// the symbol.
            int bigH = 0, hd = h+d;
            if (t->text[0] == 0x5a)   // \int
                 bigH = (2222*hd + 450)/900;
            else bigH = (1400*hd + 450)/900;
            hd = h - d;
            y -= (bigH + hd)/2;;
        }
        ff = mathFont[t->flags & FontMask];
        setFont1(dc, ff);
        drawText1(dc, x, y, t->text, t->n);
        if (DEBUGFONT & 1)
        {   dc->drawRectangle(x, y, t->width, t->depth);
            dc->drawRectangle(x, y - t->height, t->width, t->height);
        }
        return;
case BoxBracket:
        bb = (BracketBox *)b;
        h1 = bb->sub->text.height;
        d1 = bb->sub->text.depth;
        if (bb->leftBracket == 'Q')
        {   int f = bb->flags & FontSizeMask;
            int h = mathFontHeight[f];
            int d = mathFontDepth[f];
            h1 += (h + d + 12)/25; // make contents seem taller
                                   // to leave gap before overbar
        }
        if (DEBUGFONT & 1)
        {   dc->drawRectangle(x, y, bb->width, bb->depth);
            dc->drawRectangle(x, y - bb->height, bb->width, bb->height);
        }
        paintBox(dc, bb->sub, x + bb->dx, y);
        paintBracket(dc, bb->leftBracket, bb->flags,
                     x, y, h1, d1);
        paintBracket(dc, bb->rightBracket, bb->flags,
                     x + bb->dx + bb->sub->text.width, y, h1, d1);
        if (bb->leftBracket == 'Q')    // need rule above the contents
        {   int h = (mathFontHeight[bb->flags & FontSizeMask] +
                     mathFontDepth[bb->flags & FontSizeMask] + 12) /25;
// I want the rule here to be the same width as the stem that the "cmex" font
// gives the top-part of a huge sqrt sign. Measuring that seems to reveal that
// the rule thickness used is 40 units when the height of the whole font is
// 1000 - ie it is 1/25th of the whole height. So that is what I will use
// here.
            if (h <= 0) h = 1;  // ensure bar is at least 1 pixel tall
            dc->fillRectangle(x+bb->dx, y-bb->height-h, bb->sub->text.width, h);
        }
        if (bb->sub1 != NULL)
            paintBox(dc, bb->sub1, x+bb->dx1, y+bb->dy1);
        return;
case BoxMatrix:
        if (DEBUGFONT & 1)
        {   dc->drawRectangle(x,
                  y-b->matrix.height,
                  b->matrix.width,
                  b->matrix.depth + b->matrix.height);
        }
        paintBox(dc, b->matrix.sub, x, y + b->matrix.dy);
        return;
case BoxNest:
        if (DEBUGFONT & 1)
        {   dc->drawRectangle(x,
                  y-b->nest.height,
                  b->nest.width,
                  b->nest.depth + b->nest.height);
        }
        paintBox(dc, b->nest.sub1, x + b->nest.dx1, y + b->nest.dy1);
        if (b->nest.sub2 != NULL) // in case of PadSpace
            paintBox(dc, b->nest.sub2, x + b->nest.dx2, y + b->nest.dy2);
// I may need to tune the thickness of the rule that I use here
        if ((b->nest.flags & NestMask) == BoxFraction)
        {   int h = (mathFontHeight[b->nest.flags & FontSizeMask] +
                     mathFontDepth[b->nest.flags & FontSizeMask] + 12)/25;
            int dy = (mathFontHeight[b->nest.flags & FontSizeMask] -
                      mathFontDepth[b->nest.flags & FontSizeMask])/2;
            if (h <= 0) h = 1;  // ensure bar is at least 1 pixel tall
            dc->fillRectangle(x, y-h/2-dy, b->nest.width, h);
        }
        return;
case BoxNest3:
        paintBox(dc, b->nest3.sub1, x + b->nest3.dx1, y + b->nest3.dy1);
        paintBox(dc, b->nest3.sub2, x + b->nest3.dx2, y + b->nest3.dy2);
        paintBox(dc, b->nest3.sub3, x + b->nest3.dx3, y + b->nest3.dy3);
        return;
case BoxFrame:
        paintBox(dc, b->frame.sub, x, y);
        dc->drawRectangle(x,
              y-b->frame.height,
              b->frame.width,
              b->frame.depth + b->frame.height);
        return;
case BoxTop:
        paintBox(dc, b->top.sub, x, y);
        return;
default:
        printf("Paint unknown box type %d: failing\n", b->text.type);
        fflush(stdout);
        return;
    }
}



///////////////////////////////////////////////////////////////////////////


int setupShowMath(FXApp *app, int mainSize, FXWindow *w)
{
    setupMemoryPool();
    rehashKeywordTable();            // names in the table of TeX keywords
    char *message = loadPrivateFonts(app, w);
    if (message != NULL)
    {   printf("Failed to set up fonts: %s\n", message);
        exit(1);
    }
    return changeMathFontSize(app, mainSize);
}

void closeShowMath(FXApp *app)
{
// I have had really uncomfortable trouble trying to close down the various
// font systems, so for now I just give up and hop that the application
// fonts I added here will not persist beyond exit from the application.
}

///////////////////////////////////////////////////////////////////////////

} // namespace

// End of FXShowMath.cpp

