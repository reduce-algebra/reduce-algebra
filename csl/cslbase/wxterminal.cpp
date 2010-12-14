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

/* Signature: 09d75f2a 14-Dec-2010 */

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/caret.h>
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

// I *probably* want to use wxvscrolledwindow here not wxscrolledcanvas!

class fwinText : public wxScrolledCanvas
{
public:
    fwinText(class fwinFrame *parent);

    void OnDraw(wxDC &dc);

    void OnChar(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

// I make these two public because the surrounding fwinFrame touches them.
    bool firstPaint;
    int columnPos[81];

private:
    class fwinFrame *frame;
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
// lastVisibleRow is the final row displayed on the screen.
// textEnd points at the position in textBuffer one beyond the final
// character stored. Ie it is zero if the buffer is empty.
// caretPos is between zero and textEnd (inclusive) and denotes a position
// between two characters where insertion might happen.
    uint32_t *textBuffer;
    int textBufferSize;
    void enlargeTextBuffer();
    wxCaret *caret;
    int caretPos;
    int textEnd; 
    int rowHeight, rowCount;
    int firstVisibleRow, lastVisibleRow;
    int historyNumber;

    int options;
#define READONLY     1

    int keyFlags;
#define ESC_PENDING  1
#define ANY_KEYS     2

    int flags;
#define FLAG_CHANGED 1
#define FLAG_TIP     2

#define TYPEAHEAD_SIZE 100
    uint32_t ahead_buffer[TYPEAHEAD_SIZE];
    int type_in, type_out;

    void type_ahead(uint32_t c);

    int promptEnd;

    int searchFlags;
#define SEARCH_FORWARD   0x10000000
#define SEARCH_BACKWARD  0x20000000
#define SEARCH_LENGTH    (searchFlags & 0x00ffffff)
    uint32_t searchString[256];
    int searchStack[256];
    int startMatch;

    void beep();
    void insertChar(uint32_t ch);
    int32_t locateChar(int p, int w, int r, int c);
    void appendText(char *s, int len);
    void insertNewline();
    void deleteForwards();
    void deleteBackwards();
    void deleteWordForwards();
    void deleteWordBackwards();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveWordLeft();
    void moveWordRight();
    void moveLineStart();
    void moveLineEnd();
    void pageUp();
    void pageDown();
    void moveDocStart();
    void moveDocEnd();
    void undo();
    int charFromPosition(int x, int y);
    void setSelectionMark();
    void setSelectionEnd();
    void extendSelection();
    void cut();
    void copyRegion();
    void copyWordPrev();
    void command();
    void extendedCommand();
    void paste();
    void killSelection();
    void deleteCurrentLine();
    int setInputText(uint32_t *s, int n);
    void transpose();
    void capitalize();
    void lowerCase();
    void upperCase();
    void escapePressed();
    void makePositionVisible(int p);
    int editable;    
    int trySearch();
    int wordlen(uint32_t *s);
    void historyNext();
    void historyPrev();
    void searchHistoryNext();
    void searchHistoryPrev();
    uint32_t *input_history[INPUT_HISTORY_SIZE];
    int historyNextEntry,
        historyCurrent,
        longestHistoryLine;
    int historyFirst, historyLast;


    void historyInit();
    void historyEnd();
    void historyAdd(uint32_t *s, int n);
    uint32_t *historyGet(int n);
    int matchString(const char *pat, int n, const char *text);
    int isEditable();
    int isEditableForBackspace();
    void rotateClipboard();
    void reinput();    
    void setCaretPos(int n);
    void interrupt();
    void displayBacktrace();
    void requestFlushBuffer();

    int MapChar(int c);      // map from TeX character code to BaKoMa+ one

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fwinText, wxScrolledCanvas)
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


#ifndef MACINTOSH

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

#endif // MACINTOSH

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
    add_custom_fonts();
    fwinFrame *frame = new fwinFrame();
    frame->Show(true);
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
// I will want to end up saving screen size (and even position) between runs
// of this program.
    int width  = 900;      // default size.
    int height = 600;
// If the default size would fill over 90% of screen width or height I scale
// down to make it fit better.
    if (10*width > 9*screenWidth)
    {   height = height*9*screenWidth/(10*width);
        width = 9*screenWidth/10;
    }
    if (10*height > 9 * screenHeight)
    {   width = width*9*screenHeight/(10*height);
        height = 9*screenHeight/10;
    }
    panel = new fwinText(this);
    SetMinClientSize(wxSize(400, 100));
    SetSize(width, height);
    Centre();
}

fwinText::fwinText(fwinFrame *parent)
       : wxScrolled<wxWindow>(parent, wxID_ANY,
                    wxDefaultPosition, wxDefaultSize,
                    wxVSCROLL, "fwinText")
{
    frame = parent;
    fixedPitch = NULL;
    firstPaint = true;
    textBufferSize = 10000;
    textBuffer = (uint32_t *)malloc(textBufferSize*sizeof(uint32_t));
    textEnd = 0;
    searchFlags = 0;
    firstVisibleRow = 0;
    caret = NULL;
    caretPos = 0;
    options = 0;
    keyFlags = 0;
    flags = 0;
    type_in = type_out = 0;
    historyNumber = historyFirst = historyLast = 0;
    historyInit();

// Here I put some sample test in the buffer so I have something to draw.
    textBuffer[textEnd++] = 0x2554; // Draw a box to show those chars.
    textBuffer[textEnd++] = 0x2550;
    textBuffer[textEnd++] = 0x2555;
    textBuffer[textEnd++] = '\n';
    textBuffer[textEnd++] = 0x2560;
    textBuffer[textEnd++] = 0x2564;
    textBuffer[textEnd++] = 0x2561;
    textBuffer[textEnd++] = '\n';
    textBuffer[textEnd++] = 0x2559;
    textBuffer[textEnd++] = 0x2534;
    textBuffer[textEnd++] = 0x2518;
    textBuffer[textEnd++] = '\n';


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
}

//
// Here I have the procedures that implement each editing action.
//

//
// Something I have NOT fitted quite carefully enough to all this is
// arrangements that I ignore things if not waiting for input and force
// the cursor to the final line in relevant cases.
//

// ^@   set mark, ie start a selection

void fwinText::setSelectionMark()
{
//  return onCmdMark(this, 0, NULL);
}

// ^A   move to start of current line (after any prompt text!)

void fwinText::moveLineStart()
{
    while (textBuffer[caretPos] != '\n') caretPos--;
    makePositionVisible(caretPos);
    while (textBuffer[caretPos] & 0x03000000) caretPos++;
    makePositionVisible(caretPos);
// If the mark is set maybe I should extend the selection...
}

// ^B  move back a character

void fwinText::moveLeft()
{
#ifdef RECONSTRUCTED
// If the mark is set maybe I should extend the selection...?
// If I am accepting input I will not let the user move backwards into the
// prompt string.
    if ((options & READONLY) == 0 && caretPos == promptEnd)
    {   beep();
        return;
    }
    onCmdCursorLeft(this, 0, NULL);
#endif
}

// ALT-B move back a word

void fwinText::moveWordLeft()
{
#ifdef RECONSTRUCTED
// If the mark is set maybe I should extend the selection...?
// If I am accepting input I prevent the user from moving back past where the
// prompt string ends. I beep if I make no move at all.
    int w = caretPos;
    if ((options & READONLY) == 0 && w == promptEnd)
    {   beep();
        return;
    }
    onCmdCursorWordLeft(this, 0, NULL);
    if ((options && READONLY) == 0 &&
        w > promptEnd &&
        caretPos < promptEnd) setCaretPos(promptEnd);
#endif
}

// ^C  abandon input, returning an exception to user

void fwinText::interrupt()
{
#ifdef RECONSTRUCTED
// Note that ^C generates a break action whether I am waiting for input or not.
    onCmdBreak(this, 0, NULL);;
#endif
}

// ALT-c  capitalize a word

void fwinText::capitalize()
{
#ifdef RECONSTRUCTED
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   beep();
        return;
    }
    char wordbuffer[64];
    int cp = caretPos;
    int ws = wordStart(cp);
    int we = wordEnd(cp);
    if (ws < promptEnd) ws = promptEnd;
    if (we > ws + 63) we = ws + 63;
    extractText(wordbuffer, ws, we-ws);
    int i;
    wordbuffer[0] = toupper(wordbuffer[0]);
    for (i=1; i<we-ws; i++)
        wordbuffer[i] = tolower(wordbuffer[i]);
    replaceStyledText(ws, we-ws, wordbuffer, we-ws, STYLE_INPUT);
    setCaretPos(cp);
    makePositionVisible(cp);
#endif
}

// ^D  delete character under cursor (fowards)

void fwinText::deleteForwards()
{
#ifdef RECONSTRUCTED
    if (!isEditable())     // side effect is to move to last line if necessary
    {   beep();
        return;
    }
    onCmdDelete(this, 0, NULL);
#endif
}

// Should this do special things (a) if there is a selection or (b)
// if there is a selection and the cursor is within it?

// ALT-d  delete word forwards

void fwinText::deleteWordForwards()
{
#ifdef RECONSTRUCTED
    if (!isEditable())     // side effect is to move to last line if necessary
    {   beep();
        return;
    }
    onCmdDeleteWord(this, 0, NULL);
#endif
}

// ^E  move to end of current line

void fwinText::moveLineEnd()
{
#ifdef RECONSTRUCTED
// extend selection?
//    onCmdCursorEnd(this, 0, NULL);
#endif
}

// ^F  forward one character

void fwinText::moveRight()
{
#ifdef RECONSTRUCTED
// If the mark is set maybe I should extend the selection...
//    onCmdCursorRight(this, 0, NULL);
#endif
}

// ALT-F  forward one word

void fwinText::moveWordRight()
{
#ifdef RECONSTRUCTED
// If the mark is set maybe I should extend the selection...
//    onCmdCursorWordRight(this, 0, NULL);
#endif
}

// ^G   If it was the very very first character typed or if I am not
//      waiting for input, ^G raises an interrupt. If I am waiting for
//      input and have not typed anything much then it clears the current
//      input line leaving me back with a fresh start. I will make that so
//      fresh that ^G^G guarantees an interrupt!

void fwinText::displayBacktrace()
{
#ifdef RECONSTRUCTED
    if (!isEditable())
    {   onCmdBacktrace(this, 0, NULL);
    }
    killSelection();
    setInputText(NULL, 0);
    historyNumber = historyLast + 1;
    keyFlags &= ~ANY_KEYS;
#endif
}

// ^H  (backspace) delete char before cursor if that is reasonable.

void fwinText::deleteBackwards()
{
#ifdef RECONSTRUCTED
    switch (isEditableForBackspace())
    {
default:                // within the area for active editing.
        onCmdBackspace(this, 0, NULL);
        return;
case -1:                // current input line is empty.
case 0:                 // input is not active
        beep();
    }
#endif
}

// ALT-h  delete previous word

void fwinText::deleteWordBackwards()
{
#ifdef RECONSTRUCTED
    int pos;
    switch (isEditableForBackspace())
    {
default:                // within the area for active editing.
// I want to be confident that whatever prompt string has been set the
// following will never delete part of the prompt...
        pos = leftWord(caretPos);
        if (pos < promptEnd) pos = promptEnd;
        removeText(pos, caretPos-pos, TRUE);
        setCaretPos(caretPos, TRUE);
        makePositionVisible(caretPos);
        flags |= FLAG_CHANGED;
        modified = TRUE;
        return;
case -1:                // current input line is empty.
case 0:                 // input is not active
        beep();
    }
#endif
}

// ^I was just a TAB and has been handled elsewhere

// ^J (linefeed) accepts the current line of text

// ^K  kill current line
// Note that ^G and ^U are somewhat related, and that I do not
// do anything by way of putting cut text into a kill-buffer, or allowing the
// user to make selections using the keyboard...

void fwinText::deleteCurrentLine()
{
#ifdef RECONSTRUCTED
    killSelection();
    setInputText(NULL, 0);
#endif
}

// ^L    clear screen (handled as menu shortcut)

// ALT-L convert to lower case

void fwinText::lowerCase()
{
#ifdef RECONSTRUCTED
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   beep();
        return;
    }
    char wordbuffer[64];
    int cp = caretPos;
    int ws = wordStart(cp);
    if (ws < promptEnd) ws = promptEnd;
    int we = wordEnd(cp);
    if (we > ws + 63) we = ws + 63;
    extractText(wordbuffer, ws, we-ws);
    int i;
    for (i=0; i<we-ws; i++)
        wordbuffer[i] = tolower(wordbuffer[i]);
    replaceStyledText(ws, we-ws, wordbuffer, we-ws, STYLE_INPUT);
    setCaretPos(cp);
    makePositionVisible(cp);
#endif
}

// ^M  as ENTER, ^J

// ALT-M  a &Module menu

// ^N  history next if we are at present on the bottom line
//     otherwise move down a line
// (also down-arrow key)

// To replace the input line I can can use this... It returns the
// index of the first character of the inserted line.

int fwinText::setInputText(uint32_t *text, int n)
{
#ifdef RECONSTRUCTED
    int n2 = length;
    int n1 = lineStart(n2);
    while (n1 < n2 && (getStyle(n1) & STYLE_PROMPT)) n1++;
    replaceStyledText(n1, n2-n1, text, n, STYLE_INPUT);
//    changeStyle(n1, length-n1, STYLE_INPUT);  // paint it the right colour
    setCaretPos(length);
    makePositionVisible(length);
    return n1;
#else
    return n;
#endif
}


// The history routines here are never invoked unless we are awaiting input

int fwinText::wordlen(uint32_t *p)
{
    if (p == NULL) return 0;
    int r = 0;
    while (*p++ != 0) r++;
    return r;
}

void fwinText::historyNext()
{
#ifdef RECONSTRUCTED
    const uint32_t *history_string;
    if (historyLast == -1) // no history lines at all to retrieve!
    {   beep();
        return;
    }
    if (historyNumber < historyLast) historyNumber++;
    if ((history_string = historyGet(historyNumber)) == NULL)
    {   beep();
        return;
    }
    setInputText(history_string, wordlen(history_string));
#endif
}

// Commentary on the search mechanism:
//   If not at present engaged in a search the search key
//   enters search mode with an empty search string and a given
//   direction, and the empty string will match against the current
//   (usually empty) input line so nothing much visible will happen.
//
//   A further use of the search key will move one line in the given
//   direction and search again until the pattern matches. If the alternate
//   direction search key is pressed the line is moved one line in the
//   new direction before scanning that way.
//
//   ENTER or an arrow key, or DEL or ESC (in general most things that
//   and not printing characters and not otherwise listed here) exits
//   search mode with the new current line.
//
//   BACKSPACE (^H) removes a character from the search pattern. If there
//   that leaves none it exits search mode. It pops back to the line you
//   had before the character it removed was inserted.
//
//   typical printing characters add that character to the pattern. If the
//   pattern is not a valid Regular Expression at the time concerned it is
//   treated as if completed in the most generous manner possible? Or maybe
//   the match fails so you get a beep and no movement?
//   [Gosh what do I mean by that? Do I *REALLY* want regexp matches here?]
//   Searching continues in the most recently selected direction. If no match
//   is found the line does not move and the system beeps.
//

// ALT-n  forward search

void fwinText::searchHistoryNext()
{
#ifdef RECONSTRUCTED
    if (historyLast == -1) // no history to search
    {   beep();
        return;
    }
// If I am not in a search at present then set the flag for a search
// with an empty search string and a mark that the direction is forwards.
// Well if I not only am not in a search but I had not previously scrolled
// back in the history so I have nowhere to search then I might as well
// beep and give up.
    if (historyNumber > historyLast)
    {   beep();
        return;
    }
    searchFlags = SEARCH_FORWARD;
#endif
}


int fwinText::trySearch()
{
    int r = -1;
#ifdef RECONSTRUCTED
    const char *history_string = historyGet(historyNumber);
    if (history_string == NULL) return -1;
    while ((r = matchString(searchString, SEARCH_LENGTH, history_string)) < 0)
    {   if (searchFlags & SEARCH_FORWARD)
        {   if (historyNumber == historyLast) return -1;
            historyNumber++;
        }
        else
        {   if (historyNumber == historyFirst) return -1;
            historyNumber--;
        }
        history_string = historyGet(historyNumber);
        if (history_string == NULL) return -1;
    }
#endif
    return r;
}

int fwinText::matchString(const char *pat, int n, const char *text)
{
// This is a crude and not especially efficient pattern match. I think
// it should be good enough for use here! I make it return the offset where
// a match first occurred (if one does) in case that will be useful to me
// later. I could put the cursor there, perhaps?
    int offset;
    for (offset=0;*(text+offset)!=0;offset++)
    {   const char *p = pat, *q = text+offset;
        int i;
        for (i=0; i<n; i++)
        {   if (p[i] != q[i]) break;
        }
        if (i == n) return offset;
    }
    return -1;
}

void fwinText::historyPrev()
{
#ifdef RECONSTRUCTED
    const char *history_string;
    if (historyLast == -1) // no previous lines to retrieve
    {   beep();
        return;
    }
// If I have not moved the history pointer at all yet move it into the
// range of valid history entries.
    if (historyNumber > historyFirst) historyNumber--;
    history_string = historyGet(historyNumber);
    if (history_string == NULL)
    {   beep();
        return;
    }
    setInputText(history_string, wordlen(history_string));
#endif
}

// ALT-P  reverse search

void fwinText::searchHistoryPrev()
{
#ifdef RECONSTRUCTED
    if (historyLast == -1) // no history to search
    {   beep();
        return;
    }
    if (historyNumber == historyLast + 1) historyNumber--;
    searchFlags = SEARCH_BACKWARD;
#endif
}

// ^S as pause output is handled as a shortcut so that it can be
// accepted whether or not I am awaiting input.

// ^T  transpose

void fwinText::transpose()
{
#ifdef RECONSTRUCTED
    if (!isEditable())
    {   beep();
        return;
    }
    char buff[2];
    int cp = caretPos;
    if (cp > length-2)
    {   beep();
        return;
    }
    extractText(buff, cp, 2);
    int ch;
    ch = buff[0];
    buff[0] = buff[1];
    buff[1] = ch;
    replaceStyledText(cp, 2, buff, 2, STYLE_INPUT);
    setCaretPos(cp);
    makePositionVisible(cp);
#endif
}

// ALT-U convert to upper case

void fwinText::upperCase()
{
#ifdef RECONSTRUCTED
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   beep();
        return;
    }
    char wordbuffer[64];
    int cp = caretPos;
    int ws = wordStart(cp);
    if (ws < promptEnd) ws = promptEnd;
    int we = wordEnd(cp);
    if (we > ws + 63) we = ws + 63;
    extractText(wordbuffer, ws, we-ws);
    int i;
    for (i=0; i<we-ws; i++)
        wordbuffer[i] = toupper(wordbuffer[i]);
    replaceStyledText(ws, we-ws, wordbuffer, we-ws, STYLE_INPUT);
    setCaretPos(cp);
    makePositionVisible(cp);
#endif
}

// ^Y  paste

void fwinText::paste()
{
#ifdef RECONSTRUCTED
    if (!isEditable())
    {   beep();
        return;
    }
    onCmdPasteSel(this, 0, NULL);
#endif
}

// ALT-y rotate killbuffer/clipboard

void fwinText::rotateClipboard()
{
#ifdef RECONSTRUCTED
// @@@@@
#endif
}

// ^Z is a keyboard shortcut to pause execution

// ALT-[, ESCAPE

void fwinText::escapePressed()
{
    keyFlags ^= ESC_PENDING; // so that ESC ESC cancels the effect.
}

void fwinText::reinput()
{
#ifdef RECONSTRUCTED
    if (!isEditable())
    {   beep();
        return;
    }
    onCmdReinput(this, 0, NULL);
#endif
}

// Return true if editable, which here is used as
// a mark of whether the user has requested input.

int fwinText::isEditable()
{
#ifdef RECONSTRUCTED
    if ((options&READONLY)!=0) return FALSE;
// If we are asking if the fwinText is editable that is because we
// are trying to insert something. Here it is editable, so the user is
// waiting for input. I will make the very query force the final line
// to be visible and ensure that the cursor is within it. This should prevent
// anybody from every clobbering anything other than the active input line.
// Note that key-presses while the program is NOT ready to accept them
// will not cause cursor movement until the program requests input.
    int n = lineStart(length);
    makePositionVisible(n);
    while (n < length && (getStyle(n) & STYLE_PROMPT)) n++;
    makePositionVisible(length);
    if (caretPos < n) setCaretPos(length);
// Furthermore if I am about to change thing I will ensure that any
// selection lies within the active line.
    if (selstartpos < n) selstartpos = n;
    if (selendpos < selstartpos) selendpos = selstartpos;
#endif
    return TRUE;
}

// Return true if editable, to be used when the next operation would
// be a BACKSPACE (delete-previous). It must thus shift the cursor to
// avoid deleting the final character of the prompt string.

int fwinText::isEditableForBackspace()
{
#ifdef RECONSTRUCTED
    if ((options&READONLY)!=0) return 0;  // must buffer the action
    int n = lineStart(length);
    makePositionVisible(n);
    while (n < length && (getStyle(n) & STYLE_PROMPT)) n++;
    makePositionVisible(length);
// The next line has "<=" where the previous function has just "<"
    if (caretPos <= n) setCaretPos(length);
// Furthermore if I am about to change thing I will ensure that any
// selection lies within the active line.
    if (selstartpos < n) selstartpos = n;
    if (selendpos < selstartpos) selendpos = selstartpos;
    if (n == length) return -1; // nothing that I am allowed to delete
#endif
    return 1;
}

void fwinText::insertNewline()
{
#ifdef RECONSTRUCTED
    int p = length;
// I find the first "real" character of the input line by scanning back
// to (a) the start of the buffer (b) the end of a previous line or (c) the
// end of a prompt string.
    while (p>0 && getChar(p-1)!='\n' && (getStyle(p-1)&STYLE_PROMPT)==0) p--;
    int n = length-p;
    if (n > (int)sizeof(inputBuffer)-5) n = sizeof(inputBuffer)-5;
    extractText(inputBuffer, p, n);
// I enter the line that has just been collected into the history
// record.
    inputBuffer[n] = 0;
    historyAdd(inputBuffer, n);
// Adding an entry could cause an old one to be discarded. So I now ensure
// that I know what the first and last recorded numbers are.
    historyLast = historyNextEntry - 1;
    historyFirst = historyNextEntry - INPUT_HISTORY_SIZE;
    if (historyFirst < 0) historyFirst = 0;
    historyNumber = historyLast + 1; // so that ALT-P moves to first entry
// Now I add a newline to the text, since the user will expect to see that.
    inputBuffer[n] = '\n';
    inputBuffer[n+1] = 0;
    inputBufferLen = n+1;
    inputBufferP = 0;
// Stick a newline into the text buffer, and make the screen non-updatable.
    InsertNewline( );
    setEditable(FALSE);
    recently_flushed = 0;
// stuff user typed is now in buffer... I should never have got here unless
// the user thread was waiting, so here I unlock it, to tell it that
// the input buffer is ready.
    if (sync_even)
    {   sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
#endif
}


void fwinText::requestFlushBuffer()
{
#ifdef RECONSTRUCTED
    recently_flushed = 0;
// here the worker thread is locked waiting for mutex2, so I can afford to
// adjust fwin_in and fwin_out.
    if (sync_even)
    {   LockMutex(mutex1);
        if (fwin_in != fwin_out && (pauseFlags & PAUSE_DISCARD) == 0)
        {   if (fwin_in > fwin_out)
                appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out
            else
            {   appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE
                appendText(&fwin_buffer[0], fwin_in);
            }
            makePositionVisible(rowStart(length));
        }
// After this call fwin_in and fwin_out are always both zero.
        fwin_out = fwin_in = 0;
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        if (fwin_in != fwin_out && (pauseFlags & PAUSE_DISCARD) == 0)
        {   if (fwin_in > fwin_out)
                appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out
            else
            {   appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE
                appendText(&fwin_buffer[0], fwin_in);
            }
            makePositionVisible(rowStart(length));
        }
        fwin_out = fwin_in = 0;
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
#endif
}



//- void fwinText::refreshRange(int p, int q)
//- {
//- // Firstly at present this is WRONG in that when you have inserted
//- // a newline this refreshes and hence redraws all the characters that
//- // are present, but it does not write background in all the places that
//- // characters move out from.
//- //
//- // It is also inefficient in that it refreshes all the way down to the foot
//- // of the page even if rows there have not altered.
//- //
//- // Finally it should arrange to have a Blip operation performed on the
//- // screen to move whole rows up or down whenever that is feasible rather
//- // than just redrawing everything from scratch.
//- //
//- // Reminder:
//- //   wxPaintDC dc(this);
//- //   dc.Blit(xdest, ydest, width, height, dc, xsrc, ysrc);
//- // will do a simple copy.
//-
//-     if (p < firstVisibleRow) p = firstVisibleRow;
//-     while (p < q)                     // Crude version here!
//-     {   if (refreshChar(p++)) break;
//-     }
//- }

#define PACK(r, c) ((r)<<16 | (c))
#define ROW(n)     (((n) >> 16) & 0xffff)
#define COL(n)     ((n) & 0xffff)

int32_t fwinText::locateChar(int p, int w, int r, int c)
{
// Normally call as locateChar(p, firstVisibleRow, 0, 0) but the final 3
// args are to allow resumption after a previous call
// Return the row/column of the character cell corresponding to address
// p in the buffer. Return -1 if the character at position p is above the
// window, and -2 if it is below. The pointer p may be equal to textEnd, ie
// one beyond the actual text in the buffer.
// This needs to take a little care with line-wrapping. It can return
// column numbers 0 to 79 in general, but if p is textEnd or the character
// there is a newline it can return a column number of 80.
// tabs are expanded with tab-stops every 8 columns. The code here exploits
// the fact that the width (80 columns) is a multiple of the tab width, so
// while a tab may take one up to column 80 it can not go beyond without the
// whole tab effect occurring on the next row.
    //int w = firstVisibleRow;
    if (p < w) return -1; // above the visible screen.
    //int r = 0, c = 0;  // r will be a row count, c a column count;
    while (w != p)
    {   uint32_t ch = textBuffer[w];
        if (ch == '\n')
        {   c = 0;
            r++;
            if (r > rowCount) return -2; // below visible screen
        }
        else if (c == 80)
        {   if (ch == '\t') c = 8;       // tab in column 80
            else c = 1;
            r++;
            if (r > rowCount) return -2; // below visible after line-wrap
        }
        else if (ch == '\t') c += 8 - (c & 7); // tab
        else c++;
        w++;
    }
    if (c == 80 && w < textEnd && textBuffer[w] != '\n')
    {   c = 0;
        r++;
    }
    return PACK(r, c);
}

void fwinText::insertChar(uint32_t ch)
{
    int32_t loc1 = locateChar(caretPos, firstVisibleRow, 0, 0);
    int r1 = ROW(loc1), c1 = COL(loc1);
// I find the location of the end of the line that the character I am
// about to insert will be on.
    int lineEnd = caretPos;
    while (lineEnd < textEnd && textBuffer[lineEnd]!='\n') lineEnd++;
    int32_t loc2 = locateChar(lineEnd, caretPos, r1, c1);
    textEnd++;
    int p = textEnd;
    if (p >= textBufferSize) enlargeTextBuffer();
// In my terminal I will only ever be inserting within a "single line", and
// even though that may consist of several rows it is liable to be only
// a modest distance from the end of my text buffer. And in many cases the
// user will be typing in characters right at the very end. Thus the loop
// here copying characters to make space for the newly inserted one is liable
// to be much less of a performance bottleneck than it could become if I
// permitted inserts towards the start of a lengthy document.
    while (p != caretPos)
    {   textBuffer[p] = textBuffer[p-1];
        p--;
    }
    textBuffer[caretPos] = ch;
// After inserting the character I look to find where the end of the
// line that it is on has moved to.
    int32_t loc3 = locateChar(lineEnd+1, caretPos, r1, c1);
    caretPos++;
// Now I certainly need to refresh from loc1 to loc3, but if
// ROW(loc2) != ROW(loc3) then my insert caused a change in the number of
// rows to be displayed so I should refresh all the way down to the bottom
// of the screen.
    if (r1 == ROW(loc3))             // everything is on one line
    {   RefreshRect(wxRect(columnPos[c1], r1*rowHeight,
                           columnPos[COL(loc3)], rowHeight));
    }
    else if (loc2>0 &&               // loc2 is on the screen, several
             ROW(loc2) == ROW(loc3)) // rows involved, but row count unchanged
    {   RefreshRect(wxRect(columnPos[c1], r1*rowHeight,
                           columnPos[80], rowHeight));
// Here I will refresh the first row from caretPos up until its end,
// and the whole of all other rows that might be involved. 
        RefreshRect(wxRect(columnPos[0], (r1+1)*rowHeight,
                           columnPos[80], (ROW(loc2)-r1)*rowHeight));
    }
    else                             // lower bits of screen must scroll
    {   RefreshRect(wxRect(columnPos[c1], r1*rowHeight,
                           columnPos[80], rowHeight));
// In inserting this character inserted a newline or caused extra wrapping
// I will refresh all the way down to the bottom of the screen.
        RefreshRect(wxRect(columnPos[0], (r1+1)*rowHeight,
                           columnPos[80], (rowCount-r1-1)*rowHeight));
    }
// Finally I will re-position the caret. Well it could be that somehow
// somebody got to insert characters before the window has been painted,
// and in that case the caret might nmot have been created, so I filter
// that case out.
    if (caret != NULL)
    {   loc1 = locateChar(caretPos, caretPos-1, r1, c1);
        caret->Move(columnPos[COL(loc1)], ROW(loc1)*rowHeight);
    }
}



void fwinText::makePositionVisible(int p)
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::setCaretPos(int n)
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::command()
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::extendedCommand()
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::moveUp()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::moveDown()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::pageUp()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::pageDown()
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::undo()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::copyRegion()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::beep()
{
#ifdef WIN32
    FWIN_LOG("Use Windows Beep\n");
    ::Beep(900, 60);
#else
    FWIN_LOG("Play wxBell\n");
    ::wxBell();
#endif
}



void fwinText::killSelection()
{
#ifdef RECONSTRUCTED
#endif
}


void fwinText::copyWordPrev()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::type_ahead(uint32_t c)
{
#ifdef RECONSTRUCTED
#endif
}













void fwinText::moveDocStart()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::moveDocEnd()
{
#ifdef RECONSTRUCTED
#endif
}



int fwinText::charFromPosition(int x, int y)
{
#ifdef RECONSTRUCTED
#endif
    return 0;
}




void fwinText::setSelectionEnd()
{
#ifdef RECONSTRUCTED
#endif
}



void fwinText::cut()
{
#ifdef RECONSTRUCTED
#endif
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


void fwinFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{
    int i;
    double w;
    wxSize client(GetClientSize());
    w = (double)client.GetWidth()/80.0;
    panel->SetSize(client);
    panel->firstPaint = true;
    for (i=0; i<81; i++)
        panel->columnPos[i] = (int)((double)i*w);
// When I resize the window I will refresh EVERYTHING, and in doing so I
// will discover where the caret lies.
    panel->Refresh();
}

void fwinText::enlargeTextBuffer()
{
    textBufferSize *= 2;
    textBuffer =
        (uint32_t *)realloc(textBuffer, textBufferSize*sizeof(uint32_t));
    if (textBuffer == NULL) exit(1); // Abrupt collapse on no memory.
}

void fwinText::OnChar(wxKeyEvent &event)
{
    uint32_t c = event.GetUnicodeKey();
    uint32_t r = event.GetKeyCode();
    int m = event.GetModifiers(); // wxMOD_ALT, wxMOD_SHIFT, wxMOD_CMD
                                  // Also ALTGR, META, WIN, CONTROL
    uint32_t *history_string = NULL;
// If a previous keystroke had been ESC then I act as if this one
// had ALT combined with it. I will cancel the pending ESC on various
// menu things as well as here. Note that this conversion copes with
// local editing combinations such as ALT-D, but ESC-I does not activate
// a menu the way that ALT-I would have.
    if (keyFlags & ESC_PENDING)
    {   m |= wxMOD_ALT;  
        keyFlags &= ~ESC_PENDING;
    }
// Now I deal with keys that do not have a Unicode translation. I will
// map them onto codes that are distinguished by having bit 0x80000000 set.
#define NON_UNICODE 0x80000000U
    if (c == WXK_NONE)
    {   switch (r)
        {
// I will list all the WXK_ values that can arise from non-Unicode
// input here. In many cases I will merely ignore the key-press, but
// by having a full enumeration I remind myself of what I MIGHT want to do.
// Of course not every keyboard will have all of these, and what might
// be worse each operating system might intercept some of them
// before I have a chance to respond!
#if 0
    case WXK_START:
    case WXK_LBUTTON:
    case WXK_RBUTTON:
    case WXK_CANCEL:
    case WXK_MBUTTON:
    case WXK_SHIFT:
    case WXK_ALT:
    case WXK_CONTROL:
    case WXK_MENU:
    case WXK_PAUSE:
    case WXK_CAPITAL:
    case WXK_SELECT:
    case WXK_PRINT:
    case WXK_EXECUTE:
    case WXK_SNAPSHOT:
                  case WXK_F2:  case WXK_F3:  case WXK_F4:  case WXK_F5:
    case WXK_F6:  case WXK_F7:  case WXK_F8:  case WXK_F9:  case WXK_F10:
    case WXK_F11: case WXK_F12: case WXK_F13: case WXK_F14: case WXK_F15:
    case WXK_F16: case WXK_F17: case WXK_F18: case WXK_F19: case WXK_F20:
    case WXK_F21: case WXK_F22: case WXK_F23: case WXK_F24:
    case WXK_NUMLOCK:
    case WXK_SCROLL:
    case WXK_NUMPAD_F2: case WXK_NUMPAD_F3: case WXK_NUMPAD_F4:
    case WXK_NUMPAD_SEPARATOR:
    case WXK_WINDOWS_RIGHT:
    case WXK_WINDOWS_MENU:
    case WXK_COMMAND:
    case WXK_NUMPAD_BEGIN:
#endif
    default:
// All the above either will not arise as characters or if they do will be
// things I wish to ignore.
            return;

    case WXK_DELETE:
    case WXK_NUMPAD_DELETE:
            c = WXK_DELETE|NON_UNICODE;
            break;
    case WXK_INSERT:
    case WXK_NUMPAD_INSERT:
            c = WXK_INSERT|NON_UNICODE;
            break;
    case WXK_CLEAR:
            c = WXK_CLEAR|NON_UNICODE;
            break;
    case WXK_END:
    case WXK_NUMPAD_END:
            c = WXK_END|NON_UNICODE;
            break;
    case WXK_HOME:
    case WXK_NUMPAD_HOME:
            c = WXK_HOME|NON_UNICODE;
            break;
    case WXK_LEFT:
    case WXK_NUMPAD_LEFT:
            c = WXK_LEFT|NON_UNICODE;
            break;
    case WXK_UP:
    case WXK_NUMPAD_UP:
            c = WXK_UP|NON_UNICODE;
            break;
    case WXK_RIGHT:
    case WXK_NUMPAD_RIGHT:
            c = WXK_RIGHT|NON_UNICODE;
            break;
    case WXK_DOWN:
    case WXK_NUMPAD_DOWN:
            c = WXK_DOWN|NON_UNICODE;
            break;
    case WXK_PAGEUP:
    case WXK_NUMPAD_PAGEUP:
            c = WXK_PAGEUP|NON_UNICODE;
            break;
    case WXK_PAGEDOWN:
    case WXK_NUMPAD_PAGEDOWN:
            c = WXK_PAGEDOWN|NON_UNICODE;
            break;
    case WXK_HELP:
    case WXK_F1:
    case WXK_NUMPAD_F1:
            c = WXK_HELP|NON_UNICODE;
            break;

// Now I have some cases where there may be special dedicated keys on some
// models of keyboard, or where the numeric keypad might be in use. In the
// cases that follow I merely map the key concerned onto the regular
// character it equates to. So eg WXK_NUMPAD0 turns into merely '0'.
    case WXK_NUMPAD0: case WXK_NUMPAD1:
    case WXK_NUMPAD2: case WXK_NUMPAD3:
    case WXK_NUMPAD4: case WXK_NUMPAD5:
    case WXK_NUMPAD6: case WXK_NUMPAD7:
    case WXK_NUMPAD8: case WXK_NUMPAD9:
            c = r + '0' - WXK_NUMPAD0;
            break;
    case WXK_MULTIPLY:
            c = '*';
            break;
    case WXK_ADD:
            c = '+';
            break;
    case WXK_SEPARATOR:
            c = WXK_SPACE;
            break;
    case WXK_SUBTRACT:
            c = '-';
            break;
    case WXK_DECIMAL:
            c = '.';
            break;
    case WXK_DIVIDE:
            c = '/';
            break;
    case WXK_NUMPAD_SPACE:
            c = WXK_SPACE;
            break;
    case WXK_NUMPAD_TAB:
            c = WXK_TAB;
            break;
    case WXK_NUMPAD_ENTER:
            c = WXK_RETURN;
            break;
    case WXK_NUMPAD_EQUAL:
            c = '=';
            break;
    case WXK_NUMPAD_MULTIPLY:
            c = '*';
            break;
    case WXK_NUMPAD_ADD:
            c = '+';
            break;
    case WXK_NUMPAD_SUBTRACT:
            c = '-';
            break;
    case WXK_NUMPAD_DECIMAL:
            c = '.';
            break;
    case WXK_NUMPAD_DIVIDE:
            c = '/';
            break;
        }
// If I "break" from the above switch block it means I have translated
// the raw character into a Unicode on in C. 
    }
//  FWIN_LOG("Character %#x modifiers %x\n", c, m);
// I will let the Search Pending code drop through in cases where the
// keystroke should be treated as a return to "ordinary" processing. Also
// note that I only expect to find myself in search mode in cases where the
// system is waiting for input.
    if (searchFlags != 0)
    {   int save, r, ls;
        switch (c)
        {
// BACKSPACE removes a character from the search string
    case WXK_BACK:
// When I delete a character from a search string I will pop the active
// history line back to the first one found when the remaining string
// was searched for. If I delete back to nothing I will leave the input
// line blank.
            if (SEARCH_LENGTH == 0)
            {   beep();
                searchFlags = 0;   // cancel searching before it started!
                killSelection();
                return;
            }
            searchFlags--;
            if (SEARCH_LENGTH == 0)
            {   searchFlags = 0;   // delete the one char in the search string
                killSelection();
                setInputText(NULL, 0);
                return;
            }
            historyNumber = searchStack[SEARCH_LENGTH];
// The "trySearch" here really really ought to succeed since I have reverted
// to a history line where it succeeded before. I do it again here so I can
// find out where, on that line, the match was so I can establish it as a
// selection.
            startMatch = trySearch();
            history_string = historyGet(historyNumber);
// ought not to return NULL here!
            ls = setInputText(history_string, wordlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return;
// ALT-P and ALT-p and UP all search backwards
    case 'P': case 'p':
            if (!(m & wxMOD_ALT)) goto defaultlabelsearch;
    case WXK_UP|NON_UNICODE:
            searchFlags &= ~SEARCH_FORWARD;
            searchFlags |= SEARCH_BACKWARD;
            if (historyNumber <= historyFirst)
            {   beep();  // already on last possible place
                return;
            }
            save = historyNumber;
            historyNumber--;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                beep();
                return;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string, wordlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return;
// ALT-N and ALT-n and DOWN all search forwards
    case 'N': case 'n':
            if (!(m & wxMOD_ALT)) goto defaultlabelsearch;
    case WXK_DOWN|NON_UNICODE:
            searchFlags |= SEARCH_FORWARD;
            searchFlags &= ~SEARCH_BACKWARD;
            if (historyNumber >= historyLast)
            {   beep();
                return;
            }
            save = historyNumber;
            historyNumber++;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                beep();
                return;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string, wordlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return;
// I detect ^U here and cause it to exit search mode.
    case ('U' & 0x15):
            searchFlags = 0;
            killSelection();
            return;
    case WXK_ESCAPE:       // ctl-[
            keyFlags ^= ESC_PENDING;
            return;
    default:
    defaultlabelsearch:
// I suggest "^@" as a sensible character to type to exit from searching.
// Acting on it just "sets the mark" which is typically harmless. However
// I will exit search mode with any control or ALT combination too
            if (c == 0 ||
                (c & NON_UNICODE) != 0 ||
                (m & (wxMOD_ALT | wxMOD_CMD)) != 0)
            {   searchFlags = 0;
                killSelection();
                break;
            }
// here I should have a single simple character in c to search for
// and I will filter out control characters... except tab!
            if (c < 0x20 && c != '\t')
            {   searchFlags = 0;
                killSelection();
                break;
            }
// Here I have a further printable character to add to the search
// pattern. If ignore it if the search string has become ridiculously long
// to avoid a buffer overflow. Note that these days the text buffer (and hence
// the search string and history buffer) will be stored as 32-bit units
// each holding a Unicode char in the lower 24 bits.
            if (SEARCH_LENGTH > 250)
            {   beep();
                return;
            }
            searchString[SEARCH_LENGTH] = c;
            searchStack[SEARCH_LENGTH] = historyNumber;
            searchFlags++;
            save = historyNumber;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                beep();
                searchFlags--;
                return;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string, wordlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return;
        }
    }
// If the very first character I see is a "^D" it is to be taken as EOF
// rather than as "delete next character".
    if (c == ('D' & 0x1f) &&
        !(keyFlags & ANY_KEYS))
    {   setCaretPos(textEnd);
// I force a Control-D character into the buffer and then pretend that
// a newline had also been typed.
        insertChar(0x04);
        insertNewline();
        return;
    }
// If the very first key I see is "^G" I will raise an exception
// for the user.
    if (c == ('C' & 0x1f) &&
        !(keyFlags & ANY_KEYS))
    {   displayBacktrace();
        return;
    }
    keyFlags |= ANY_KEYS;
    switch (c)
    {
case WXK_BACK:  // = Ctrl-H
// ALT backspace does a delete-backwards-word, while just backspace
// deletes a single character. I find that CTRL-backspace (at least on
// on Windows) is mapped to ctrl-DELETE so that will delete forwards.
        beep(); // to test this @@@
        if ((m & wxMOD_ALT) != 0) deleteWordBackwards();
        else deleteBackwards();
        return;
case WXK_END|NON_UNICODE:
// Hmmm - still should I extend a selection if an anchor is set?
// END should probably go to the end of the current line, with ALT-END
// going to the end of the last line.
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveDocEnd();
        else moveLineEnd();
        return;
case WXK_HOME|NON_UNICODE:
// HOME should probably go to the start of the current active line, with
// ALT-HOME being the thing that goes to top of the screen-buffer.
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveDocStart();
        else moveLineStart();
        return;
case WXK_LEFT|NON_UNICODE:
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveWordLeft();
        else moveLeft();
        return;
case WXK_RIGHT|NON_UNICODE:
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveWordRight();
        else moveRight();
        return;
case WXK_UP|NON_UNICODE:
// UP      go to previous item in history
// ALT-UP  search backwards in history
// CTRL-UP or action in read-only region: merely move up a line
        if ((m & wxMOD_CMD) || (options & READONLY)) moveUp();
        else if (m & wxMOD_ALT) searchHistoryPrev();
        else historyPrev();
        return;
case WXK_DOWN|NON_UNICODE:
// If you are not waiting for input then cursor up and down just move you up
// and down! If you are waiting for input then Control can be used to break
// you out from the input-line...
        if ((m & wxMOD_CMD) || (options & READONLY)) moveDown();
        else if (m & wxMOD_ALT) searchHistoryNext();
        else historyNext();
        return;
case WXK_RETURN:
// case ('J' & 0x1f):
// I always act as if newlines were typed at the very end of the input.
// Right now I treat ENTER and ^J and ^M all the same, and ignore any
// ALT, SHIFT or CTRL. Some people might want to use modifiers on ENTER
// to signify some sort of soft newline?
        setCaretPos(textEnd);
        c = '\n';   // normalise to "newline"
        goto defaultlabel;
case WXK_TAB:
        c = '\t';
        goto defaultlabel;
case '@':
// As a default sort of behaviour if my chart of actions shows a key doing
// something interesting with CONTROL but does not specify what happens
// with ALT, I think I will tend to make ALT-x behave like ^x.
        if (m & wxMOD_ALT)
        {   setSelectionMark();
            return;
        }
        else goto defaultlabel;
case '@' & 0x1f:
        setSelectionMark();
        return;
case 'A': case 'a':
        if (m & wxMOD_ALT)
        {   moveLineStart();
            return;
        }
        else goto defaultlabel;
case 'A' & 0x1f:
        moveLineStart();
        return;
case 'B' & 0x1f:
        moveLeft();
        return;
case 'B': case 'b':
        if (m & wxMOD_ALT)
        {   moveWordLeft();
            return;
        }
        else goto defaultlabel;
case 'C' & 0x1f:
        interrupt();
        return;
case 'C': case 'c':
        if (m & wxMOD_ALT)
        {   capitalize();
            return;
        }
        goto defaultlabel;
case WXK_DELETE|NON_UNICODE:
        if (m & (wxMOD_CMD|wxMOD_ALT))
        {   deleteWordForwards();
            return;
        }
        c = WXK_DELETE; // to type-ahead buffer
        break;
case 'D' & 0x1f:
// Here I may want to arrange that if the current input-buffer is empty
// then ^D causes and EOF to be returned. Well yes, I have arranged that
// elsewhere so I only get here if the user has typed some chars already.
        goto defaultlabel;
case 'D': case 'd':
        if (m & wxMOD_ALT)
        {   deleteWordForwards();
            return;
        }
        goto defaultlabel;
case 'E' & 0x1f:
        moveLineEnd();
        return;
case 'E': case 'e':
// ALT-e enters the EDIT menu: this is handled by having the menu
// registered elsewhere.
        goto defaultlabel;
case 'F' & 0x1f:
        moveRight();
        return;
case 'F': case 'f':
        if (m & wxMOD_ALT)
        {   moveWordRight();
            return;
        }
        goto defaultlabel;
case 'G' & 0x1f:
        displayBacktrace();
        return;
case 'G': case 'g':
        if (m & wxMOD_ALT)
        {   displayBacktrace();
            return;
        }
        goto defaultlabel;
// case 'H' & 0x1f: // = WXK_BACK
case 'H': case 'h':
        if (m & wxMOD_ALT)
        {   deleteWordBackwards();
            return;
        }
         goto defaultlabel;
// case 'I' & 0x1f: // == WXK_TAB
case 'I': case 'i':
// ALT-i enters the FILE menu
        goto defaultlabel;
case 'J' & 0x1f:
         c = '\n';
         goto defaultlabel;
case 'J': case 'j':
        if (m & wxMOD_ALT)  // Could ALT-J be for something more interesting?
        {   insertNewline();
            return;
        }
        goto defaultlabel;
case 'K' & 0x1f:
        deleteCurrentLine();
        return;
case 'K': case 'k':
        if (m & wxMOD_ALT)
        {   deleteCurrentLine();
            return;
        }
        goto defaultlabel;
// ^L will be a shortcut for clear-screen
case 'L': case 'l':
        if (m & wxMOD_ALT)
        {   lowerCase();
            return;
        }
        goto defaultlabel;
// case 'M' & 0x1f: // = WXK_RETURN
case 'M': case 'm':
// ALT-m enters the MODULE menu
        goto defaultlabel;
case 'N' & 0x1f:
        if (options & READONLY) moveDown();
        else historyNext();
        return;
case 'N': case 'n':
        if (options & READONLY) goto defaultlabel;
        else if (m & wxMOD_ALT)
        {   searchHistoryNext();
            return;
        }
        goto defaultlabel;
// case 'O' & 0x1f: // menu shortcut to lose eoutput
case 'O': case 'o':
// ^O will be purge output.
//    I hope that by making ^O, ^S and ^Q menu shortcuts they will get
//    acted upon whether I am waiting for input or not.
// ALT-O enters the FONT menu
        goto defaultlabel;
case 'P' & 0x1f:
        if (options & READONLY) moveUp();
        else historyPrev();
        return;
case 'P': case 'p':
        if (options & READONLY) goto defaultlabel;
        else if (m & wxMOD_ALT)
        {   searchHistoryPrev();
            return;
        }
        goto defaultlabel;
case 'Q': case 'q':
// ^Q will be RESUME OUTPUT
        if (m & wxMOD_ALT) return; // Ignore ALT-Q
        goto defaultlabel;
case 'R' & 0x1f:
        Refresh();
        return;
case 'R': case 'r':
// ALT-r will be the B&reak menu
        goto defaultlabel;
// case 'S' & 0x1f: // menu shortcut
case 'S': case 's':
// ^S should pause output
// ALT-s enters the SWITCH menu
        goto defaultlabel;
case 'T' & 0x1f:
        transpose();
        return;
case 'T': case 't':
        if (m & wxMOD_ALT)
        {   transpose();
            return;
        }
        goto defaultlabel;
case 'U' & 0x1f:
        undo();
        return;
case 'U': case 'u':
        if (m & wxMOD_ALT)
        {   upperCase();
            return;
        }
        goto defaultlabel;
case 'V': case 'v':
// ^V will be PASTE and is handled as a shortcut
        goto defaultlabel;
case 'W' & 0x1f:
// ^W behaviour is just like ALT-H
        deleteWordBackwards();
        return;
case 'W': case 'w':
        if (m & wxMOD_ALT)
        {   copyRegion();
            return;
        }
        goto defaultlabel;
case 'X' & 0x1f:
// Just what these have to do is a mystery to me at present!
// Well that is an overstatement - what I mean is that I am not yet
// implementing anything!
        extendedCommand();
        return;
case 'X': case 'x':
        if (m & wxMOD_ALT)
        {   command();
            return;
        }
        goto defaultlabel;
case 'Y' & 0x1f:
// ^Y is short for YANK, otherwise known as PASTE
        paste();
        return;
case 'Y': case 'y':
        if (m & wxMOD_ALT)
        {   rotateClipboard();
            return;
        }
        goto defaultlabel;
// case 'Z' & 0x1f: // suspend
case 'Z': case 'z':
        goto defaultlabel;
// case '[' ^ 0x1f: // = WXK_ESCAPE
case '[':
        goto defaultlabel;
case WXK_ESCAPE:       // ctl-[
// ESC must have the effect of simulating the ALT property for the following
// character.
        return escapePressed();
case '\\' & 0x1f:
        return; // should exit the application???
case '\\':
        goto defaultlabel;
case ']':
        goto defaultlabel;
case '^' & 0x1f:
        reinput();
        return;
case '^':
        goto defaultlabel;
case '_':
        if (m & wxMOD_ALT)
        {   copyWordPrev();
            return;
        }
        goto defaultlabel;

default:
defaultlabel:
        insertChar(c); // @@@@
#ifdef XXXXXX
        if ((event->code & ~0xff) != 0 ||
            event->text[1] != 0)
            return onKeyPress();
#endif
// here I should have a single simple character
#ifdef XXXXXX
        ch = event->text[0];
// and I will filter out control characters...
        if ((ch & 0xff) < 0x20) return; //  onKeyPress();
#endif
        break;
    }
// Now I am left with printable characters plus TAB and NEWLINE. If the
// terminal is waiting for input or if CTRL or ALT was associated with
// the key I delegate.
// @@@ I should really try to check so that when I insert a ")", "]" or
// "}" I look for the corresponding opening bracket and flash it.
    if (isEditable() ||
        (m & wxMOD_ALT))
    {
// I want the input line to be in a special colour.
#ifdef XXXXXX
        long rr = onKeyPress();
        changeStyle(promptEnd, textEnd-promptEnd, STYLE_INPUT);
#endif
        return;
    }
// I have now delegated everything except simple printable characters
// plus tab, backspace and newline without CTRL or ALT.
// I will interpret backspace as deleting the most recent character
// (if there is one, and not if we get back to a newline). Otherwise
// I just fill a (circular) buffer.
    flags &= ~FLAG_TIP;
    if (c == '\b')  // delete previous character in buffer if there is one
    {   int n = type_in;
        if (--n < 0) n = TYPEAHEAD_SIZE-1;
// I can not delete a character if there is not one there. I will not delete
// it if the previous character was a newline. In such cases I just beep.
        if (type_in == type_out ||
            ahead_buffer[n] == '\n')
        {   beep();
            return;
        }
        type_in = n;
    }
    else type_ahead(c);
    return;
}





void fwinText::historyInit()
{
    int i;
    historyNextEntry = historyCurrent = longestHistoryLine = 0;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
        input_history[i] = NULL;
}

void fwinText::historyEnd()
{
    int i;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
    {   if (input_history[i] != NULL) free(input_history[i]);
    }
}

void fwinText::historyAdd(uint32_t *s, int n)
{
/* Make a copy of the input string... */
    size_t size = sizeof(uint32_t)*(n + 1);
    uint32_t *scopy = (uint32_t *)malloc(size);
    int p = historyNextEntry % INPUT_HISTORY_SIZE;
/* If malloc returns NULL I just store an empty history entry. */
    if (scopy != NULL) memcpy(scopy, s, size);
/*
 * I can overwrite an old history item here... I will keep INPUT_HISTORY_SIZE
 * entries.
 */
    if (input_history[p] != NULL) free(input_history[p]);
    input_history[p] = scopy;
    historyNextEntry++;
    if (scopy != NULL)
    {   
        if (n > longestHistoryLine) longestHistoryLine = n;
    }
}

uint32_t *fwinText::historyGet(int n)
{
    static uint32_t nullString[] = {0};
    uint32_t *s;
/*
 * Filter our values that are out of range and in those cases return NULL
 * as a flag to report the error.
 */
    if (n == historyNextEntry) return &nullString[0];
    if (n < 0 ||
        n >= historyNextEntry ||
        n < historyNextEntry-INPUT_HISTORY_SIZE) return NULL;
    s = input_history[n % INPUT_HISTORY_SIZE];
/* The NULL here would be if malloc had failed earlier. */
    if (s == NULL) return &nullString[0];
    else return s;
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
// It worries me that exactly the same OpenType font needs to be
// called for using slighly different names on different platforms.
#ifdef MACINTOSH
            fixedPitch->SetFaceName("CMU Typewriter Text Regular");
#else
            fixedPitch->SetFaceName("CMU Typewriter Text");
#endif
            fixedPitch->SetPointSize(1000);
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
            pixelsPerPoint = em/fmEm;
            fixedPitch->SetPointSize(10);
        }
        int spacePerChar = window.GetWidth()/80;
        scaleAdjustment = (double)spacePerChar/em;
        fixedPitch->SetPointSize(10);
        fixedPitch->Scale(scaleAdjustment);
        dc.SetFont(*fixedPitch);
        rowHeight = dc.GetCharHeight();
        spacePerChar = dc.GetCharWidth(); 
        rowCount = (window.GetHeight()+rowHeight-1)/rowHeight;
// Create or re-size the caret, and position it where it needs to be on the
// screen.
        if (caret == NULL) caret = new wxCaret::wxCaret(this, 2, rowHeight);
        else caret->SetSize(2, rowHeight);
        int32_t caretCell = locateChar(caretPos, firstVisibleRow, 0, 0);
        caret->Move(columnPos[COL(caretCell)], rowHeight*ROW(caretCell));
        caret->Show();


        SetVirtualSize(wxSize(window.GetWidth(), 1000)); // @@@
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
    lastVisibleRow = firstVisibleRow;
    while (p<textEnd)
    {   uint32_t ch = textBuffer[p++];
        if ((ch & 0xffffff) == '\n')
        {   dc.DrawRectangle(columnPos[col], row*rowHeight,
                             columnPos[80]-columnPos[col], rowHeight);
            col = 0;
            row++;
            if (row*rowHeight > window.GetHeight()) break;
            lastVisibleRow = p;
            continue;
        }
// a TAB can take you exactly up to column 80 but never over it.
        if (col == 80)
        {   col = 0;
            row++;
            if (row*rowHeight > window.GetHeight()) break;
            lastVisibleRow = p;
        }
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
        wxString cs;
        int extraCols = 0;
// I convert TAB into a suitable sequence of spaces.
        if ((ch & 0xffffff) == '\t')
        {   wxString spaces[8] =
            {   wxT(" "), wxT("  "), wxT("   "), wxT("    "), wxT("     "),
                wxT("      "), wxT("       "), wxT("        ")
            };
            extraCols = 7 - (col&7); 
            cs = spaces[extraCols];
        }
        else if ((ch & 0xffffff) == 0x20) cs = wxT(" ");
// Does the next fragment cope with Unicode points beyond 0xffff on Windows?
        else cs = (wchar_t)(ch & 0xffffff);
        dc.DrawText(cs, columnPos[col], rowHeight*row);
        col = col + extraCols + 1;
    }
}


// End of wxterminal.cpp

