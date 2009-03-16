/*
 * Display all characters in a (simple) font. This is a naive program
 * using FOX but is going to help me understand font management. In
 * particular at the very start it makes assumptions about glyph sizes
 * that are not going to be really proper...
 *
 *  Usage, eg
 *      fontdemo cmr10
 * fonts that are supposed to be available are
 *    Windows           X11
 *     cmr10       csl-reduce-cmr10
 *     cmmi10      ...
 *     cmsy10
 *     cmex10
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


/* Signature: 144b5cfd 16-Mar-2009 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#define HAVE_LIBFOX 1
#endif

#ifndef HAVE_LIBFOX

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("FOX library not detected and so this demo is unavailable\n");
    return 0;
}

#else

#include "fx.h"	
#include "fwin.h"

#ifndef fontsdir
#define fontsdir reduce.fonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

/*
 * It appears that MacOSX sometimes leaves me with a "struct Cursor" that
 * I really did not want, so this #define is to hide it away.
 */

// However doing this can cause pain elsewhere, so it is temporarily disabled
// #define Cursor AvoidClashWithQuickdrawCursor

#ifdef WIN32

#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <wingdi.h>

#else
#ifdef HAVE_LIBXFT

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

static Display *dpy;
static XftDraw *ftDraw = NULL;
static Visual *ftVisual = NULL;
static Colormap ftColorMap;
static XRenderColor ftRenderBlack = {0,0,0,0xffff};
static XRenderColor ftRenderWhite = {0xffff,0xffff,0xffff,0xffff};
static XftColor ftBlack, ftWhite;
static XftFont *ftFont = NULL;

#else   // No Xft

#error Other than on Windows you must have Xft installed.

#endif
#endif
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

namespace FX {

extern "C" {

extern int main(int argc,char *argv[]);

}

static FXFont *ff = NULL;

static const char *fontname = NULL;

class FontWindow : public FXMainWindow 
{

    FXDECLARE(FontWindow)

public:
    FXCanvas *canvas;

protected:
    FontWindow() {}
    ~FontWindow();
public:
    long onPaint(FXObject *, FXSelector, void *);
    FontWindow(FXApp* a);
    virtual void create();
    enum
    {   ID_CANVAS = FXMainWindow::ID_LAST,
        ID_LAST
    };
};



FXDEFMAP(FontWindow) FontWindowMap[] =
{
    FXMAPFUNC(SEL_PAINT, FontWindow::ID_CANVAS, FontWindow::onPaint),
};

FXIMPLEMENT(FontWindow,FXMainWindow,FontWindowMap,ARRAYNUMBER(FontWindowMap))


FontWindow::FontWindow(FXApp *a)
          :FXMainWindow(a,"Font Application",NULL,NULL,DECOR_ALL,0,0,1100,800)
{
    canvas=new FXCanvas(this,this,ID_CANVAS,
        FRAME_SUNKEN|FRAME_THICK|LAYOUT_FILL_X|LAYOUT_FILL_Y|
        LAYOUT_FILL_ROW|LAYOUT_FILL_COLUMN);
}


FontWindow::~FontWindow()
{
// I find that attempts to unload windows fonts take me into a world
// of pain, so I leave them to be automatically discarded when the
// application closes. This is really rather grungy!
}

void FontWindow::create()
{
    FXMainWindow::create();
    show(PLACEMENT_SCREEN);
}

static FXApp *appl = NULL;

long FontWindow::onPaint(FXObject *, FXSelector, void *ptr)
{
    int i, j;
    FXEvent *ev = (FXEvent*)ptr;
    FXDCWindow dc(canvas, ev);
    dc.setForeground(FXRGB(230, 200, 255));  // violent purple background
    dc.fillRectangle(ev->rect.x, ev->rect.y, ev->rect.w, ev->rect.h);
    dc.setForeground(FXRGB(100, 220, 120));
    for (i=0; i<256; i+=32)
    {   for (j=0; j<32; j++)
        {   if ((((i/32) + j) & 1) == 0) continue;
            dc.fillRectangle(32*j+5, 3*i+40, 32, 96);
        }
    }
    dc.setForeground(FXRGB(90, 20, 70));
#ifdef WIN32
    if (ff != NULL) dc.setFont(ff);
#endif
    for (i=0; i<256; i+=32)
    {   char bb[4];
        for (j=0; j<32; j++)
        {   int c = i + j;
#ifdef WIN32
            int n = 1;
            bb[0] = c;
            if (c >= 0x80)
            {   bb[0] = 0xc0 + (c >> 6);
                bb[1] = 0x80 | (c & 0x3f);
                n = 2;
            }
            if (ff->hasChar(i+j))
                dc.drawText(32*j+5, 3*i+40, &bb[0], n);
#else
/*          if (i+j >= 0x80) continue; */
            bb[0] = i+j;
            FT_UInt bbb[1];
            bbb[0] = i+j+1;
            XftDrawGlyphs(ftDraw, &ftBlack, ftFont,
                           32*j+5, 3*i+40, (FT_UInt *)&bbb, 1);
#endif
        }
    }
    return 1;
}

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

// With Windows 95 and 98 (and who can remember about ME) the
// AddFontResourceEx function I wanted was not available,
// Thus I could not sensibly link in calls to it in any hard way. To
// try to support old operating systems I loaded the gdi32 library
// and checked for this function using dynamic loading access methods.
// I could then fall back and use AddFontResource to add the fonts
// in a more global way of necessary.
// If I now take the view that only Windows XP and Vista matter
// I can do things the obvious manner and not worry.

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

static int CALLBACK fontEnumProc(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
    fontNeeded = 0;
    return 0;
}

static char faceName[200] = "";

static int CALLBACK fontEnumProc1(
    const LOGFONTA *lpelfe,     // logical-font data
    const TEXTMETRICA *lpntme,  // physical-font data
    DWORD FontType,             // type of font
    LPARAM lParam)              // application-defined data
{
// avoid duplicated reports
    if (strcmp(lpelfe->lfFaceName, faceName) == 0) return 1;
    strcpy(faceName, lpelfe->lfFaceName);
    printf("Font \"%s\" is available\n", lpelfe->lfFaceName);
    fflush(stdout);
    return 1;
}

#endif



int main(int argc,char *argv[])
{
    fontname = "cmr10";
    for (int i=1; i<argc; i++)
        fontname = argv[i];
#ifdef WIN32
    if (argc <= 1 ||
        (strcmp(fontname, "cmr10") != 0 &&
         strcmp(fontname, "cmmi10") != 0 &&
         strcmp(fontname, "cmsy10") != 0 &&
         strcmp(fontname, "cmex10") != 0))
    {   printf("Usage: fontdemo [fontname]\n");
        printf("The fontname should be cmr10, cmmi10, cmsy10 or cmex10\n");
        return 1;
    }
#else
// Note that under X11 I am using customised versions of the fonts and
// to avoid confusion with any copies already installed I use customised
// names.
    if (argc <= 1 ||
        (strcmp(fontname, "csl-reduce-cmr10") != 0 &&
         strcmp(fontname, "csl-reduce-cmmi10") != 0 &&
         strcmp(fontname, "csl-reduce-cmsy10") != 0 &&
         strcmp(fontname, "csl-reduce-cmex10") != 0))
    {   printf("Usage: fontdemo [fontname]\n");
        printf("The fontname should be csl-reduce-cmr10, csl-reduce-cmmi10, csl-reduce-cmsy10 or csl-reduce-cmex10\n");
        return 1;
    }
#endif
    printf("Will display \"%s\"\n", fontname);

    FXApp application("Font","FontDemo");
    appl = &application;

    application.init(argc, argv);
    find_program_directory(argv[0]);

    FontWindow *w = new FontWindow(&application);
    application.create();

#ifdef HAVE_LIBXFT
#endif

#ifdef WIN32
    HDC hDC = CreateCompatibleDC(NULL);
    LOGFONT lf;
// I check each of the fonts that this application wants to see if they
// are already installed. If they are then there is no merit in installing
// them for myself.
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   memset((void *)&lf, 0, sizeof(lf));
        strcpy(lf.lfFaceName, fontNames[i].name);
        lf.lfCharSet = DEFAULT_CHARSET;
        lf.lfPitchAndFamily = 0;
        fontNeeded = 1;
        fontNames[i].path = NULL;
        EnumFontFamiliesEx(hDC, &lf, fontEnumProc, 0, 0);
        if (!fontNeeded) continue;
        char *nn = new char [strlen(programDir) +
                             strlen(toString(fontsdir)) + 16];
        strcpy(nn, programDir);
        strcat(nn, "\\" toString(fontsdir) "\\");
        strcat(nn, fontNames[i].name); strcat(nn, ".ttf");
        fontNames[i].path = nn;
    }
// Now, for each font that was NOT already available I need to go
//       AddFontResource[Ex]("filename")
//       SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    int newFontAdded = 0;
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   if (fontNames[i].path == NULL) continue;
        if (AddFontResourceExA(fontNames[i].path, PRIVATE_FONT, 0) == 0)
        {   printf("Failed to add font %s\n", fontNames[i].path);
            fflush(stdout);
        }
        newFontAdded = 1;
        printf("AddFontResource %s\n", fontNames[i].path);
        fflush(stdout);
    }

    if (newFontAdded)
    {   // This call to SendMessage may sometimes cause a long delay.
        SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    }

// Now list all the fonts that are available...
    memset((void *)&lf, 0, sizeof(lf));
    lf.lfFaceName[0] = '\0';
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfPitchAndFamily = 0;
    printf("About to list all fonts that are now available\n");
    fflush(stdout);
    EnumFontFamiliesEx(hDC, &lf, fontEnumProc1, 0, 0);
    printf("Listing complete\n");
    fflush(stdout);
    DeleteDC(hDC);

#else // WIN32

    int screen = 0;
    XftFontSet *fs = NULL;
    ftDraw = NULL;
    FcConfig *config = FcConfigCreate();
    dpy = (Display *)appl->getDisplay();
    screen = DefaultScreen(dpy);

// I will add exactly and only the fonts that I will be using.
    char fff[256];
    for (int i=0; i<4; i++)
    {   sprintf(fff,
            "%s/" toString(fontsdir) "/%s.pfb",
            programDir, fontNames[i].name);
        FcConfigAppFontAddFile(config, (const FcChar8 *)fff);
    }
    FcConfigSetCurrent(config);
    XftInit("");
    fs = XftListFonts(dpy, screen,
//                    XFT_FAMILY, XftTypeString, fontname,
                      NULL,
// I will ask XftListFonts to return all available information about the
// fonts that are found.
                      XFT_FAMILY, XFT_STYLE, XFT_SLANT, XFT_WEIGHT,
                      XFT_SIZE, XFT_PIXEL_SIZE, XFT_ENCODING,
                      XFT_SPACING, XFT_FOUNDRY, XFT_CORE, XFT_ANTIALIAS,
                      XFT_XLFD, XFT_FILE, XFT_INDEX, XFT_RASTERIZER,
                      XFT_OUTLINE, XFT_SCALABLE, XFT_RGBA,
                      XFT_SCALE, XFT_RENDER, XFT_MINSPACE,
                      NULL);
    printf("fontset has %d distinct fonts out of %d total\n",
           fs->nfont, fs->sfont);
    char buffer[200];
// Having obtained all the fonts I will print out all the information about
// them that Xft is prepared to give me. Note that this seems not to include
// either the "true" or the "Postscript" name that I might previously have
// thought was important to me. I think that this is because all the
// information here comes directly from the font-files rather than from any
// mapping tables. The key items here are thus probably
//    family
//    style
//    slant
//    weight
    if (fs->nfont == 0)
    {   XftFontSetDestroy(fs);
        printf("Desired font not found\n");
        return 1;
    }
// Note that an XftPattern is just an Fcpattern, so either set of functions
// can be used to create or manipulate one.
    XftPattern *ftPattern = NULL;
    for (int k=0; k<fs->nfont; k++)
    {   ftPattern = fs->fonts[k];
// NameUnparse converts the name to something printable
// But BOO HISS the version of Xft shipped with openSuSE 10.2 and with some
// other versions of Linux missed it out, so just for now I will comment that
// bit out. Oh dear! A web search finds patches to gentoo to fix this for
// builds involving qt3 so it really is not just me! But I BELIEVE it will be
// a transient bug so I will not put it in the autoconf stuff just at present.
#if 0
        XftNameUnparse(ftPattern, buffer, sizeof(buffer));
        printf("%s\n", buffer); fflush(stdout);
#endif
// FcPatternPrint displays info over several lines - valuable for debugging!
        FcPatternPrint(ftPattern); printf("\n"); fflush(stdout);
    }

    ftVisual = DefaultVisual(dpy, screen);
    ftColorMap =  DefaultColormap(dpy, screen);
    ftDraw = XftDrawCreate(dpy, w->canvas->id(), ftVisual, ftColorMap);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderBlack, &ftBlack);
    XftColorAllocValue(dpy, ftVisual, ftColorMap, &ftRenderWhite, &ftWhite);
// I had identified the font that I wanted earlier so now I can open it
// by just using the information collected then.
    ftFont = XftFontOpen(dpy, screen,
                         XFT_FAMILY, XftTypeString, fontname,
                         XFT_SIZE, XftTypeDouble, 24.0,
                         NULL);
    XftFontSetDestroy(fs); // Now I am done with the list of fonts.

#endif // WIN32

    FXFontDesc fd;
    memset(&fd, 0, sizeof(fd));
    strcpy(fd.face, fontname);
    printf("Will try to view %s\n", fontname);
    fd.size = 240;               // NB size is in DECIPOINTS here
    fd.weight = 0;
    fd.slant = 0;
    fd.setwidth = 0;
    fd.encoding = FONTENCODING_DEFAULT;
    fd.flags = 0;
    ff = new FXFont(appl, fd);
    if (ff == NULL) printf("Font could not be created\n");
    else ff->create();

    return application.run();
}

}

#endif /* HAVE_LIBFOX */

// end of fontdemo.cpp

