#define DEBUG 1 /* regardless of overall build mode! */

//
// "wxterminal.cpp"                              Copyright A C Norman 2010
//
//
// Window interface for old-fashioned C applications. Intended to
// be better than just running them within rxvt/xterm, but some people will
// always believe that running them under emacs is best!
//


/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
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

/* Signature: 15b21bf7 09-Dec-2010 */

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/display.h>

#include "config.h"

#ifdef WIN32
// I will need windows-specific functions so I can set up private fonts
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <wingdi.h>
#include <io.h>
#else
#ifdef MACINTOSH

// If I need Mac-specific includes here is where to set them up!
// So far I do not seem to need anything.

#else // MACINTOSH
#ifdef HAVE_LIBXFT

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

static Display *dpy;

#else   // HAVE_LIBXFT
#error Other than on Windows you must have Xft installed.
#endif  // HAVE_LIBXFT
#endif  // MACINTOSH
#endif  // WIN32


#include "wxterminal.h"      // my own header file.


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
#ifndef _MSC_VER
extern char *getcwd(char *s, size_t n);
#endif // _MSC_VER
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#ifndef WIN32
#include <sys/dir.h>
#else // WIN32
#include <direct.h>
#endif // WIN32
#endif // HAVE_DIRENT_H

#if !defined S_IXUSR && defined __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif

#ifdef WIN32
#include "termed.h"
HANDLE pipedes;
int event_code = -1;
#else // WIN32
int pipedes[2];
#endif // WIN32

#include "wxfwin.h"

#if !defined __WXMSW__ && !defined __WXPM__
// I include several icons here, and will select which one to use dynamically
// based on the programName.
#include "fwin.xpm"
#include "csl.xpm"
#include "reduce.xpm"
#endif

static fwin_entrypoint *fwin_main1;

int windowed_worker(int argc, char *argv[], fwin_entrypoint *fwin_main)
{
    fwin_main1 = fwin_main;
#ifdef WIN32
// The following is somewhat unsatisfactory so I will explain my options and
// what is happening.
// On Unix/Linux/Darwin etc I have here a single executable that, depending
// on a command-line flag, runs either as a windowed or a command-line
// program. All is pretty neat and convenient for me!  However...
//
// On Windows when I link code I can link it either as subsystem:windows or
// as subsystem:console. If I use the windows case then it detaches from
// its console when started. The effect I have is that when launched from
// a Windows command prompt asking to be run in console mode it can not
// access the console. Windows XP provides an AttachConsole API that might
// let me re-attach to the console but (a) that is not available with
// earlier versions of Windows and (b) my experimenst with it have not been
// great successes and others report delicacies! However note that even if
// the code is linked as a windows binary it can be launched from the cygwin
// shell and inherits standard input and output very happily! But from a
// regular Windows command shell it does not.
// If, on the other hand I link my code as a console application then when
// launched from a command prompt or a script things work as I might like
// and expect. When launched by double-clicking on an icon, Windows says to
// itself "aha - a console application" and rapidly creates a console for it.
//  This pops up on your screen. But here (in the case I wanted a Windowed
// interface) I just free that console, which then has no other users and
// which therefore gets destroyed. So there is a visual glitch of an unwanted
// console window popping up and instantly vanishing.
//
// The best solution that appears to be open to me under Windows is to
// have two executable versions for each application. They would only need
// to differ in the way they were linked (and hence, possibly, by one bit in
// a header record in them!). One for console and one for windowed use.
// That feels clumsy too.
//
// Web searches show that others have found the same sort of pain when they
// have wanted to create applications that are both console and window
// mode. Ah well. One final suggestion for the two-executable scheme is
// to creats two executables, say cslw.exe and cslc.exe where cslw.exe is
// linked in windows mode and cslc.exe in console mode. cslc.exe just
// creates a process to run cslw.exe. When you do this the handles on
// standard input and output can be inherited by the child process, which
// can therefore read and write characters. However because it still does not
// really have a CONSOLE it can not do the res of what one might like by way
// of supporting curses-like screen updates. A final trick on this is to
// rename those two programs as csl.exe (windowed) and csl.com (console).
// The Windows command processor will use the ".com" extension before the
// ".exe" one, but of course the executable is really in ".exe" format...
// this trick maybe reduces the confusion over file-names! Or maybe it
// makes it worse.

#ifdef KEEP_CONSOLE_OPEN
// I sometimes find a console REALLY useful for debugging.... but when you
// launch by double-clicking on an icon it is truly ugly to have one around.
// So I will allow myself to leave an "#ifdef" here in case that helps me make
// a trick version for debugging...
    FreeConsole();
#endif // KEEP_CONSOLE_OPEN
#endif // WIN32
    wxDISABLE_DEBUG_SUPPORT();
    return wxEntry(argc, argv);
}

class fwinApp : public wxApp
{
public:
    virtual bool OnInit();
};

IMPLEMENT_APP_NO_MAIN(fwinApp)


// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include "cmfont-widths.c"


// I had HOPED I might use a variant on wxTextCtrl here and let it cope
// with all the keyboard handling, Unicode fun, local editing, scrolling -
// in general most of the effort. However I can not find how to subvert
// a Text Control into using a fixed pitch font and spacing it nicely to
// make exactly 80 chars fit across the screen. And also I have real problems
// with the deeply eccentric coding scheme used by the TeX fonts that I want
// to use.

// Musing - would a graphicscontext rather than an wxDC give me finer control
// over font sizes and character placement?

// I *probably* want to use wxvscrolledwindow here not wxscrolledcanvas!

class fwinText : public wxScrolledCanvas
{
public:
    fwinText(class fwinFrame *parent);

    void OnDraw(wxDC &dc);

    void OnChar(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

    bool firstPaint;

private:
    wxFont *fixedPitch;
    double em;
    double pixelsPerPoint;    // conversion from TeX to screen coordinates
    double scaleAdjustment;

// The text buffer will be arrange in lines, where each line may require
// more than one row to display it. The layout will be
//        C1 C2 ... '\n'
// for a line. If the number of characters is over 80 the line will be
// displayed wrapped onto several rows. The '\n' character must not be present
// in the text buffer other than as a line separator.
//
// firstVisibleRow points to the first character of the first row being
// displayed on the screen. Note that this is a ROW not a LINE.
// textEnd points at the position in textBuffer one beyond the final
// character stored. Ie it is zero if the buffer is empty.
// caretPos is between zero and textEnd (inclusive) and denotes a position
// between two characters where insertion might happen.
    int32_t *textBuffer;
    int textBufferSize;
    void enlargeTextBuffer();
    int caretPos;
    int textEnd; 
    int firstVisibleRow;

    int MapChar(int c);      // map from TeX character code to BaKoMa+ one

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fwinText, wxScrolledCanvas)
//  EVT_PAINT(           fwinText::OnPaint)
    EVT_CHAR(            fwinText::OnChar)
    EVT_LEFT_UP(         fwinText::OnMouse)
END_EVENT_TABLE()

class fwinFrame : public wxFrame
{
public:
    fwinFrame();

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);

    fwinText *panel;

private:
    int screenWidth, screenHeight;

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fwinFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  fwinFrame::OnExit)
    EVT_MENU(wxID_ABOUT, fwinFrame::OnAbout)
    EVT_SIZE(            fwinFrame::OnSize)
END_EVENT_TABLE()

int get_current_directory(char *s, int n)
{
    if (getcwd(s, n) == 0)
    {   switch(errno)
        {
    case ERANGE: return -2; // negative return value flags an error.
    case EACCES: return -3;
    default:     return -4;
        }
    }
    else return strlen(s);
}

/*
 * The next procedure is responsible for establishing information about
 * both the "short-form" name of the program launched and the directory
 * it was found in. This latter directory may be a good place to keep
 * associated resources. Well many conventions would NOT view it as a
 * good place, but it is how I organise things!
 *
 * The way of finding the information concerned differs between Windows and
 * Unix/Linux, as one might expect.
 *
 * return non-zero value if failure.
 */

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

/*
 * getenv() is a mild pain: Windows seems
 * to have a strong preference for upper case names.  To allow for
 * all this I do not call getenv() directly but go via the following
 * code that can patch things up.
 */

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    while ((c = *s++) != 0) *p++ = toupper(c);
    *p = 0;
    return getenv(uppercasename);
#else
    return getenv(s);
#endif
}



/*
 * Different systems put or do not put underscores in front of these
 * names. My adaptation here should give me a chance to work whichever
 * way round it goes.
 */

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif


typedef struct localFonts
{
    const char *name;
    char *path;
} localFonts;

static localFonts fontNames[] =
{
// Some of the key Computer Modern Unicode fonts
    {"cmunrm",       NULL},  // "CMU Serif"
    {"cmunti",       NULL},  // "CMU Serif Italic"
    {"cmuntt",       NULL},  // "CMU Typewriter Text"
// Right now I will add in ALL the fonts from the BaKoMa collection.
// This can make sense in a font demo program but in a more serious
// application I should be a little more selective!
#if 0
    {"csl-cmb10",    NULL},        {"csl-cmbsy10",  NULL},
    {"csl-cmbsy6",   NULL},        {"csl-cmbsy7",   NULL},
    {"csl-cmbsy8",   NULL},        {"csl-cmbsy9",   NULL},
    {"csl-cmbx10",   NULL},        {"csl-cmbx12",   NULL},
    {"csl-cmbx5",    NULL},        {"csl-cmbx6",    NULL},
    {"csl-cmbx7",    NULL},        {"csl-cmbx8",    NULL},
    {"csl-cmbx9",    NULL},        {"csl-cmbxsl10", NULL},
    {"csl-cmbxti10", NULL},        {"csl-cmcsc10",  NULL},
    {"csl-cmcsc8",   NULL},        {"csl-cmcsc9",   NULL},
    {"csl-cmdunh10", NULL},        {"csl-cmex10",   NULL},
    {"csl-cmex7",    NULL},        {"csl-cmex8",    NULL},
    {"csl-cmex9",    NULL},        {"csl-cmff10",   NULL},
    {"csl-cmfi10",   NULL},        {"csl-cmfib8",   NULL},
    {"csl-cminch",   NULL},        {"csl-cmitt10",  NULL},
    {"csl-cmmi10",   NULL},        {"csl-cmmi12",   NULL},
    {"csl-cmmi5",    NULL},        {"csl-cmmi6",    NULL},
    {"csl-cmmi7",    NULL},        {"csl-cmmi8",    NULL},
    {"csl-cmmi9",    NULL},        {"csl-cmmib10",  NULL},
    {"csl-cmmib6",   NULL},        {"csl-cmmib7",   NULL},
    {"csl-cmmib8",   NULL},        {"csl-cmmib9",   NULL},
    {"csl-cmr10",    NULL},        {"csl-cmr12",    NULL},
    {"csl-cmr17",    NULL},        {"csl-cmr5",     NULL},
    {"csl-cmr6",     NULL},        {"csl-cmr7",     NULL},
    {"csl-cmr8",     NULL},        {"csl-cmr9",     NULL},
    {"csl-cmsl10",   NULL},        {"csl-cmsl12",   NULL},
    {"csl-cmsl8",    NULL},        {"csl-cmsl9",    NULL},
    {"csl-cmsltt10", NULL},        {"csl-cmss10",   NULL},
    {"csl-cmss12",   NULL},        {"csl-cmss17",   NULL},
    {"csl-cmss8",    NULL},        {"csl-cmss9",    NULL},
    {"csl-cmssbx10", NULL},        {"csl-cmssdc10", NULL},
    {"csl-cmssi10",  NULL},        {"csl-cmssi12",  NULL},
    {"csl-cmssi17",  NULL},        {"csl-cmssi8",   NULL},
    {"csl-cmssi9",   NULL},        {"csl-cmssq8",   NULL},
    {"csl-cmssqi8",  NULL},        {"csl-cmsy10",   NULL},
    {"csl-cmsy5",    NULL},        {"csl-cmsy6",    NULL},
    {"csl-cmsy7",    NULL},        {"csl-cmsy8",    NULL},
    {"csl-cmsy9",    NULL},        {"csl-cmtcsc10", NULL},
    {"csl-cmtex10",  NULL},        {"csl-cmtex8",   NULL},
    {"csl-cmtex9",   NULL},        {"csl-cmti10",   NULL},
    {"csl-cmti12",   NULL},        {"csl-cmti7",    NULL},
    {"csl-cmti8",    NULL},        {"csl-cmti9",    NULL},
#endif
    {"csl-cmtt10",   NULL},        {"csl-cmtt12",   NULL},
    {"csl-cmtt8",    NULL},        {"csl-cmtt9",    NULL},
#if 0
    {"csl-cmu10",    NULL},        {"csl-cmvtt10",  NULL},
    {"csl-euex10",   NULL},        {"csl-euex7",    NULL},
    {"csl-euex8",    NULL},        {"csl-euex9",    NULL},
    {"csl-eufb10",   NULL},        {"csl-eufb5",    NULL},
    {"csl-eufb6",    NULL},        {"csl-eufb7",    NULL},
    {"csl-eufb8",    NULL},        {"csl-eufb9",    NULL},
    {"csl-eufm10",   NULL},        {"csl-eufm5",    NULL},
    {"csl-eufm6",    NULL},        {"csl-eufm7",    NULL},
    {"csl-eufm8",    NULL},        {"csl-eufm9",    NULL},
    {"csl-eurb10",   NULL},        {"csl-eurb5",    NULL},
    {"csl-eurb6",    NULL},        {"csl-eurb7",    NULL},
    {"csl-eurb8",    NULL},        {"csl-eurb9",    NULL},
    {"csl-eurm10",   NULL},        {"csl-eurm5",    NULL},
    {"csl-eurm6",    NULL},        {"csl-eurm7",    NULL},
    {"csl-eurm8",    NULL},        {"csl-eurm9",    NULL},
    {"csl-eusb10",   NULL},        {"csl-eusb5",    NULL},
    {"csl-eusb6",    NULL},        {"csl-eusb7",    NULL},
    {"csl-eusb8",    NULL},        {"csl-eusb9",    NULL},
    {"csl-eusm10",   NULL},        {"csl-eusm5",    NULL},
    {"csl-eusm6",    NULL},        {"csl-eusm7",    NULL},
    {"csl-eusm8",    NULL},        {"csl-eusm9",    NULL},
    {"csl-msam10",   NULL},        {"csl-msam5",    NULL},
    {"csl-msam6",    NULL},        {"csl-msam7",    NULL},
    {"csl-msam8",    NULL},        {"csl-msam9",    NULL},
    {"csl-msbm10",   NULL},        {"csl-msbm5",    NULL},
    {"csl-msbm6",    NULL},        {"csl-msbm7",    NULL},
#endif
    {"csl-msbm8",    NULL},        {"csl-msbm9",    NULL}
};

#ifdef WIN32

// The next flag instruct AddFontResourceEx that a font should be
// available only to this application. I provide a definition here
// in case MinGW32 does not have them in its header files.

#ifndef FR_PRIVATE
#define FR_PRIVATE   0x10
#endif

#endif


#ifndef fontsdir
#define fontsdir reduce.wxfonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

// I will want to change this so that it adds the fonts only on need.

int add_custom_fonts() // return 0 on success.
{
#ifdef WIN32
    int newFontAdded = 0;
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   char nn[LONGEST_LEGAL_FILENAME];
        strcpy(nn, programDir);
        strcat(nn, "\\" toString(fontsdir) "\\");
        strcat(nn, fontNames[i].name);
        if (i < 3) strcat(nn, ".otf");
        else strcat(nn, ".ttf");
        if (AddFontResourceExA(nn, FR_PRIVATE, 0) == 0)
            FWIN_LOG("Failed to add font %s\n", nn);
        else newFontAdded = 1;
    }
    if (newFontAdded)
    {   // This call to SendMessage may sometimes cause a long delay.
        SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
    }
    return 0;
#else // WIN32
#ifdef MACINTOSH

// Custom fonts are supported by including them in the Application Bundle
// and mentioning them in a Plist there, so I do not need and code here to
// deal with anything!
    return 1;

#else // Assume all that is left is X11, and that Xft/fontconfig are available
    int screen = 0;
    FcConfig *config = FcConfigCreate();
    dpy = XOpenDisplay(NULL);
    if (dpy == NULL)
    {   printf("Unable to access the display\n");
        exit(1);
    }
    screen = DefaultScreen(dpy);

// It might make sense to add just the fonts that I will be using rather than
// use extra resources adding all that are available. But for now I prefer
// simplicity.
    char fff[LONGEST_LEGAL_FILENAME];
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   if (i < 3) sprintf(fff, "%s/" toString(fontsdir) "/%s.otf",
                           programDir, fontNames[i].name);
        else sprintf(fff, "%s/" toString(fontsdir) "/%s.ttf",
                     programDir, fontNames[i].name);
        FcConfigAppFontAddFile(config, (const FcChar8 *)fff);
    }
    FcConfigSetCurrent(config);
    return 0;
#endif // MACINTOSH
#endif // WIN32
}




int fwinText::MapChar(int c)
{
// This function maps between a TeX character encoding and the one that is
// used by the fonts and rendering engine that I use.
    if (c < 0xa) return 0xa1 + c;
    else if (c == 0xa) return 0xc5;
#ifdef UNICODE
// In Unicode mode I have access to the character at code point 0x2219. If
// not I must insist on using my private version of the fonts where it is
// at 0xb7.
    else if (c == 0x14) return 0x2219;
#endif
    else if (c < 0x20) return 0xa3 + c;
    else if (c == 0x20) return 0xc3;
    else if (c == 0x7f) return 0xc4;
    else if (c >= 0x80) return 0xa0;
    else return c;
}





bool fwinApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
//  char **myargv = (char **)argv;

    FWIN_LOG("in fwinApp::OnInit\n");
    add_custom_fonts();
    FWIN_LOG("fonts added\n");
    fwinFrame *frame = new fwinFrame();
    FWIN_LOG("frame created but not shown\n");
    frame->Show(true);
    FWIN_LOG("Frame shown\n");
    return true;
}

fwinFrame::fwinFrame()
       : wxFrame(NULL, wxID_ANY, "wxterminal")
{
    SetIcon(wxICON(fwin));
    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   FWIN_LOG("There seem to be %d displays\n", numDisplays);
    }
    wxDisplay d0(0);                         // just look at display 0
    wxRect screenArea(d0.GetClientArea());   // omitting task bar
    screenWidth = screenArea.GetWidth();
    screenHeight = screenArea.GetHeight();
    FWIN_LOG("Usable area of screen is %d by %d\n", screenWidth, screenHeight);
// I will want to end up saving screen size (and even position) between runs
// of this program.
    int width  = 900;      // default size.
    int height = 600;
// If the default size would fill over 90% of screen width or height I scale
// down to make it fit better.
    if (10*width > 9*screenWidth)
    {   height = height*9*screenWidth/(10*width);
        width = 9*screenWidth/10;
        FWIN_LOG("reset to %d by %d to fix width\n", width, height);
    }
    if (10*height > 9 * screenHeight)
    {   width = width*9*screenHeight/(10*height);
        height = 9*screenHeight/10;
        FWIN_LOG("reset to %d by %d to fix height\n", width, height);
    }
    panel = new fwinText(this);
    FWIN_LOG("firstPaint = %d after creation\n", panel->firstPaint);
    SetMinClientSize(wxSize(400, 100));
    FWIN_LOG("About to setsize %d %d\n", width, height);
    SetSize(width, height);
    Centre();
}


fwinText::fwinText(fwinFrame *parent)
       : wxScrolled<wxWindow>(parent, wxID_ANY,
                    wxDefaultPosition, wxDefaultSize,
                    wxVSCROLL, "fwinText")
{
    fixedPitch = NULL;
    firstPaint = true;
    FWIN_LOG("Creating fwinText\n");
    textBufferSize = 10000;
    textBuffer = (int32_t *)malloc(textBufferSize*sizeof(int32_t));
    textEnd = 0;
    firstVisibleRow = 0;
    for (int i=0; i<384; i++)
    {   textBuffer[textEnd++] = i;
        if ((i & 0x1f) == 0x1f) textBuffer[textEnd++] = '\n';
    }
    for (int i=0; i<256; i++)
    {   textBuffer[textEnd++] = (0x1000000+i);
        if ((i & 0x1f) == 0x1f) textBuffer[textEnd++] = '\n';
    }
    for (int i=0; i<256; i++)
    {   textBuffer[textEnd++] = (0xe2000000+i);
        if ((i & 0x1f) == 0x1f) textBuffer[textEnd++] = '\n';
    }
    caretPos = 0; // textEnd;
}


void fwinFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
    exit(0);    // I want the whole application to terminate here!
}

void fwinFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
// At present this never gets activated!
    wxMessageBox(
       wxString::Format(
           "wxterminal (A C Norman 2010)\n"
           "wxWidgets version: %s\n"
           "Operating system: %s",
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxterminal",
       wxOK | wxICON_INFORMATION,
       this);
}

static int columnPos[81];
static int rowHeight, rowCount;

void fwinFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{
    int i;
    double w;
    wxSize client(GetClientSize());
    w = (double)client.GetWidth()/80.0;
    panel->SetSize(client);
    panel->firstPaint = true;
    for (i=0; i<81; i++)
        columnPos[i] = (int)((double)i*w);
    panel->Refresh();
}

void fwinText::enlargeTextBuffer()
{
    textBufferSize *= 2;
    textBuffer =
        (int32_t *)realloc(textBuffer, textBufferSize*sizeof(int32_t));
    if (textBuffer == NULL) exit(1); // Abrupt collapse on no memory.
}

void fwinText::OnChar(wxKeyEvent &event)
{
    const char *msg = "OnChar", *raw = "";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw = "Raw ";
    else
    {   textBuffer[caretPos] = c;
//        int left = columnPos[caretPos%80];
//        int right = columnPos[caretPos%80+1];
//        int top = rowHeight*(caretPos/80);
//        RefreshRect(wxRect(left, top, right-left, rowHeight));
        Refresh();
        caretPos++;
    }
    if (0x20 < c && c < 0x7f) FWIN_LOG("%s%s %x (%c)\n", msg, raw, c, c);
    else FWIN_LOG("%s%s %x\n", msg, raw, c);
    if (*raw != 0) event.Skip();
}

void fwinText::OnMouse(wxMouseEvent &event)
{
    FWIN_LOG("Mouse event\n");
    event.Skip();
}

void fwinText::OnDraw(wxDC &dc)
{
// The next could probably be done merely by setting a background colour
    wxColour c1(230, 200, 255);
    wxPen p1(c1);
    dc.SetPen(p1);
    wxBrush b1(c1);
    dc.SetBrush(b1);
    dc.SetBackground(b1);
    dc.SetTextBackground(c1);
    const wxColour *textColour = wxBLACK;
    dc.SetTextForeground(*textColour);
    dc.Clear(); // explicitly clear background

    wxSize window(dc.GetSize());

    if (firstPaint)
    {   if (fixedPitch == NULL)
        {   fixedPitch = new wxFont();
            fixedPitch->SetNativeFontInfoUserDesc("CMU Typewriter Text");
            fixedPitch->SetPointSize(1000);
            FWIN_LOG("fixed pitch font created\n");
            font_width *p = cm_font_width;
            while (p->name != NULL &&
                   strcmp(p->name, "cmtt10") != 0) p++;
            if (p->name == NULL)
            {   FWIN_LOG("Oops - font data not found\n");
                exit(1);
            }
            wxCoord width, height, depth, leading;
            dc.GetTextExtent("M", &width, &height, &depth, &leading, fixedPitch);
            em = (double)width/100.0;
            double fmEm = (double)p->charwidth[(int)'M']*10.0/1048576.0;
            FWIN_LOG("em=%#.3g fmEm = %#.3g\n", em, fmEm);
            FWIN_LOG("height = %#.3g total height = %#.3g leading = %#.3g\n",
                (double)(height-depth-leading)/100.0, (double)height/100.0,
                (double)leading/100.0);
            pixelsPerPoint = em/fmEm;
            FWIN_LOG("pixelsPerPoint = %#.5g\n", pixelsPerPoint);
            fixedPitch->SetPointSize(10);
        }
        int spacePerChar = window.GetWidth()/80;
        scaleAdjustment = (double)spacePerChar/em;
        fixedPitch->SetPointSize(10);
        fixedPitch->Scale(scaleAdjustment);
// For a 10 point font I would use a row-spacing of 13.
        rowHeight = (int)(13.0*scaleAdjustment + 0.9999); 
        rowCount = (window.GetHeight()+rowHeight-1)/rowHeight;
//???        SetVirtualSize(wxSize(window.GetWidth(), nRows*rowHeight));
#if 0
// Now I need to re-size any fonts that have already been created
        for (int i=0; i<MAX_FONTS; i++)
        {   wxFont *ff = font[i];
            if (ff == NULL) continue;
            ff->SetPointSize(fontWidth[i]->designsize/1048576);
            ff->Scale(scaleAdjustment*fontScale[i]);
        }
#endif
        firstPaint = false;
    }
    dc.SetFont(*fixedPitch);
    int p = firstVisibleRow;
    int row = 0, col = 0;
    while (p<textEnd)
    {   int32_t ch = textBuffer[p++];
        if ((ch & 0xffffff) == '\n')
        {   dc.DrawRectangle(columnPos[col], row*rowHeight,
                             columnPos[80]-columnPos[col], rowHeight);
            col = 0;
            row++;
            if (row*rowHeight > window.GetHeight()) break;
        }
        else if (col == 80)
        {   col = 0;
            row++;
            if (row*rowHeight > window.GetHeight()) break;
        }
        else
        {
// Now deal with color!
            if (ch & 0x1000000)
            {   if (textColour != wxRED)
                    dc.SetTextForeground(*(textColour = wxRED));
            }
            else if (ch & 0x2000000)
            {   if (textColour != wxBLUE)
                    dc.SetTextForeground(*(textColour = wxBLUE));
            }
            else if (textColour != wxBLACK)
                dc.SetTextForeground(*(textColour = wxBLACK));
// Does the next fragment cope with Unicode points beyond 0xffff on Windows?
            if ((ch & 0xffffff) <= 0x20)
                dc.DrawText(" ", columnPos[col], rowHeight*row);
            else
            {   wxString cs = (wchar_t)(ch & 0xffffff);
                dc.DrawText(cs, columnPos[col], rowHeight*row);
                col++;
            }
        }
    }
    return;
}


// End of wxterminal.cpp
