/*
 * Display all characters in a (simple) font. This is a naive program
 * using FOX but is going to help me understand font management. In
 * particular at the very start it makes assumptions about glyph sizes
 * that are not going to be really proper...
 *
 *  Usage, eg
 *      fontdemo cmr10
 * fonts that are supposed to be available are
 *     cmr10
 *     cmmi10
 *     cmsy10
 *     cmex10
 */


/* Signature: 7bca60b8 04-Jan-2008 */

#ifdef HAVE_CONFIG_H
#include "config.h"
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

#define MINIMAL_SUPPORT 1

#include "fwin.c"

/*
 * It appears that MacOSX sometimes leaves me with a "struct Cursor" that
 * I really did not want, so this #define is to hide it away.
 */
#define Cursor AvoidClashWithQuickdrawCursor

#ifdef HAVE_XFT

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

static int use_xft = 1;

#else   // No Xft

#ifdef WIN32
#include <windows.h>
#else   // No XFt and not under Windows - assume raw X11
#include <X11/Xlib.h>
#endif

static int use_xft = 0;

#endif
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

//static void unloadFonts();

FontWindow::~FontWindow()
{
#ifdef HAVE_XFT
    if (ftDraw == NULL) return;
    XftColorFree(dpy, ftVisual, ftColorMap, &ftBlack);
    XftColorFree(dpy, ftVisual, ftColorMap, &ftWhite);
// As best I can see I do not need to close the font.
    XftDrawDestroy(ftDraw);
#endif
//#ifdef WIN32
//    unloadFonts();
//#endif
}

void FontWindow::create()
{
    FXMainWindow::create();
    show(PLACEMENT_SCREEN);
}

static FXApp *appl = NULL;

long FontWindow::onPaint(FXObject *, FXSelector, void *ptr)
{
    FXEvent *ev = (FXEvent*)ptr;
    FXDCWindow dc(canvas, ev);
    dc.setForeground(FXRGB(230, 200, 255));  // violent purple background
    dc.fillRectangle(ev->rect.x, ev->rect.y, ev->rect.w, ev->rect.h);
    dc.setForeground(FXRGB(90, 20, 70));
    if (ff != NULL) dc.setFont(ff);
#ifdef HAVE_XFT
    if (use_xft)
// New scheme using client-side rendering
    {   int i, j;
        for (i=0; i<256; i+=32)
        {   char bb[4];
            for (j=0; j<32; j++)
            {   if (i+j >= 0x80) continue;
                bb[0] = i+j;
                FT_UInt bbb[1];
                bbb[0] = i+j+1;
// When NOT using Xft I did a "hasChar()" test and just avoided drawing
// glyphs that were not available. Here WITH Xft I just plough on regardless.
                XftDrawGlyphs(ftDraw, &ftBlack, ftFont,
                               32*j+5, 3*i+40, (FT_UInt *)&bbb, 1);
            }
        }
        return 1;
    }
#endif
    {   int i, j;
        for (i=0; i<256; i+=32)
        {   char bb[4];
            for (j=0; j<32; j++)
            {   bb[0] = i+j;
                if (ff->hasChar(i+j))
                    dc.drawText(32*j+5, 3*i+40, &bb[0], 1);
            }
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

static HMODULE gdi32 = NULL;

typedef int AddFontResourceExType(
    LPCTSTR lpszFilename, // font file name
    DWORD fl,             // font characteristics
    PVOID pdv);           // reserved

typedef BOOL RemoveFontResourceExType(
    LPCTSTR lpFileName,   // font file name
    DWORD fl,             // font characteristics
    PVOID pd);            // reserved

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

AddFontResourceExType *addFontEx = NULL;
//RemoveFontResourceExType *removeFontEx = NULL;

//static void unloadFonts()
//{
//    if (gdi32 == NULL) return;
//    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
//    {   if (fontNames[i].path == NULL) continue;
//        printf("Unloading %s\n", fontNames[i].path); fflush(stdout);
//// I will not check the success-code from this! If the attempt to
//// unload the font fails I will just accept that fact.
//        if (removeFontEx != NULL)
//            (*removeFontEx)(fontNames[i].path, PRIVATE_FONT, 0);
//        else RemoveFontResource(fontNames[i].path);
//        free(fontNames[i].path);
//        fontNames[i].path = NULL;
//    }
//    printf("About to tell everybody that fonts have changed\n");
//    fflush(stdout);
//    SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
//    printf("About to free gdi32\n");
//    fflush(stdout);
//    FreeLibrary(gdi32);
//    gdi32 = NULL;
//    printf("Tidying up complete\n");
//    fflush(stdout);
//}

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
// Any argument starting with "-" disables use of Xft.
    fontname = "cmr10";
    for (int i=1; i<argc; i++)
    {   if (argv[i][0] == '-') use_xft = 0;
        else fontname = argv[i];
    }
    if (argc <= 1)
    {   printf("Usage: fontdemo [-] [fontname]\n");
        printf("The \"-\" flag disables use of Xft on Linux/Unix\n");
        printf("The fontname should be cmr10, cmmi10, cmsy10 or cmex10\n");
    }
    printf("Will display \"%s\"\n", fontname);

    FXApp application("Font","FoxFontDemo");
    appl = &application;

    application.init(argc,argv);
    find_program_directory(argv[0]);

    FontWindow *w = new FontWindow(&application);
    application.create();

#ifdef HAVE_XFT
    int screen = 0;
    FcConfig *config = NULL;
    XftFontSet *fs = NULL;
    if (use_xft)
    {   ftDraw = NULL;
#ifdef USE_FCINIT
// This seems to me to be the obvious thing to do! But at least on
// MacOS 10.4 (Tiger) on at least a couple of machines it seems to involve
// a 15-25 second delay that is CPU-intensive. So for now I will see if I 
// can avoid it and never touch any "default" configuration!
        //FcInit();
#endif
        dpy = (Display *)appl->getDisplay();
        screen = DefaultScreen(dpy);

        config = FcConfigCreate();
// I will add exactly and only the fonts that I will be using.
        char ff[256];
        for (int i=0; i<4; i++)
        {   sprintf(ff, "%s/r38.fonts/%s.pfb", programDir, fontNames[i].name);
            FcConfigAppFontAddFile(config, (const FcChar8 *)ff);
        }
        FcConfigSetCurrent(config);
        XftInit("");
#ifndef USE_FCINIT
        // FcInit(); // This may be safe now since there is a configuration
                     // now loaded?
#endif
        fs = XftListFonts(dpy, screen,
//                        XFT_FAMILY, XftTypeString, fontname,
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
        FcConfigDestroy(config);
        printf("font = %p\n", ftFont);
        fflush(stdout);
    }
#endif

    if (!use_xft)
    {
#ifdef WIN32
        addFontEx = NULL;
//      removeFontEx = NULL;
        gdi32 = LoadLibrary("Gdi32.dll");
        if (gdi32 != NULL)
        {   addFontEx = (AddFontResourceExType *)
                GetProcAddress(gdi32, "AddFontResourceExA");
// NB the "A" on the end of the name selects the ANSI rather than the Unicode
// variant.
//          if (addFontEx != NULL)   // I want both if I am to use either.
//          {   removeFontEx = (RemoveFontResourceExType *)
//                  GetProcAddress(gdi32, "RemoveFontResourceExA");
//              if (removeFontEx == NULL) addFontEx = NULL;
//          }
            if (addFontEx == NULL)   // Sorry not available
            {   FreeLibrary(gdi32);
                gdi32 = NULL;
            }
        }

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
            char *nn =
                (char *)malloc(strlen(programDir) +
                               strlen(fontNames[i].name) + 16);
            strcpy(nn, programDir);
            strcat(nn, "\\r38.fonts\\");
            strcat(nn, fontNames[i].name); strcat(nn, ".ttf");
            fontNames[i].path = nn;
        }
// Now, for each font that was NOT already available I need to go
//       AddFontResource[Ex]("filename")
//       SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
        int newFontAdded = 0;
        for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
        {   if (fontNames[i].path == NULL) continue;
            if (addFontEx != NULL)
            {   if ((*addFontEx)(fontNames[i].path, PRIVATE_FONT, 0) == 0)
                {   printf("Failed to add font %s\n", fontNames[i].path);
                    fflush(stdout);
                }
            }
            else if (AddFontResource(fontNames[i].path) == 0)
            {   printf("Failed to add font %s\n", fontNames[i].path);
                fflush(stdout);
            }
            newFontAdded = 1;
            printf("AddFontResource %s\n", fontNames[i].path);
            fflush(stdout);
        }

        if (newFontAdded)
        {   SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
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
        int npaths;
        char **existingPaths = NULL;
        char **localPathP = NULL;
// On traditional X11 I will always just append my own font directory at the
// end of the existing font search path. The means that fonts already
// installed on the system will take precedence (I will suppose that they
// had been installed properly!). This lets anybody who has better-hinted
// versions of the CM fonts use them.
        existingPaths = XGetFontPath((Display *)appl->getDisplay(), &npaths);
        char localPath[LONGEST_LEGAL_FILENAME];
        sprintf(localPath, "%s/r38.fonts/", programDir);
        localPathP = (char **)malloc((npaths+1)*sizeof(char *));
        for (int j=0; j<npaths; j++)
            localPathP[j] = existingPaths[j];
        localPathP[npaths] = &localPath[0];
printf("XsetFontPath about to be called\n"); fflush(stdout);
printf("XsetFontPath returns %d\n",
        XSetFontPath((Display *)appl->getDisplay(), localPathP, npaths+1)); fflush(stdout);
#endif // WIN32

        FXFontDesc fd;
        strcpy(fd.face, fontname);
        fd.size = 240;               // NB size is in DECIPOINTS here
#if (FOX_MINOR<=4)
        fd.weight = FONTWEIGHT_DONTCARE;
        fd.slant = FONTSLANT_DONTCARE;
        fd.setwidth = FONTSETWIDTH_DONTCARE;
        fd.encoding = FONTENCODING_DEFAULT;
        fd.flags = FONTPITCH_DEFAULT;
#else
        fd.weight = 0;
        fd.slant = 0;
        fd.setwidth = 0;
        fd.encoding = FONTENCODING_DEFAULT;
        fd.flags = 0;
#endif
        ff = new FXFont(appl, fd);
printf("fontname = \"%s\"\n", fontname); fflush(stdout);
//        ff = new FXFont(appl, fontname, 24);
        ff->create();

// Now tidy up.
#ifdef WIN32
// It appears (empirically!) that I must not remove the font resources
// yet. If I do then the fonts that I have just opened do not appear to
// work properly. So I tried arranging to unload fonts when the window
// close (see comments out code for unloadFonts) but that seems to lead to
// crashes too. Well Windows should clear away local fonts for me when the
// application closes anyway.
#else
// I can re-set the paths normally in use so that I do not upset or
// confuse other users too much.
        XSetFontPath((Display *)appl->getDisplay(), existingPaths, npaths);
        XFreeFontPath(existingPaths);
        free(localPathP);
#endif
    }

    return application.run();
}

#endif /* HAVE_LIBFOX */

// end of fontdemo.cpp
