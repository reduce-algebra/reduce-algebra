#define DEBUG 1 /* regardless of overall build mode! */

//
// "wxterminal.cpp"                           Copyright A C Norman 2012-14
//
//
// Window interface for old-fashioned C applications. Intended to
// be better than just running them within rxvt/xterm, but some people will
// always believe that running them under emacs is best!
//


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

/* $Id$ */

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/caret.h>
#include <wx/display.h>
#include <wx/settings.h>
#include <wx/print.h>
#include <wx/printdlg.h>

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


#include "termed.h"
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
HANDLE pipedes;
int event_code = -1;
#else // WIN32
int pipedes[2];
#endif // WIN32

#include "wxfwin.h"

int showmathInitialised = 1; // At present lie that it has been initialised!

static int returncode = 0;

// See cmtt_coverage lower down in this code

extern uint32_t cmtt_coverage[];
extern uint32_t deja_coverage[];

#define CMTT_AVAIL(ch)    \
    ((ch) <= 0xffff &&    \
     ((cmtt_coverage[((ch)>>5) & 0x7ff] >> (31-((ch) & 0x1f))) & 1) != 0)

#define DEJA_AVAIL(ch)    \
    ((ch) <= 0x2fff &&    \
     ((deja_coverage[((ch)>>5) & 0x7ff] >> (31-((ch) & 0x1f))) & 1) != 0)


#if !defined __WXMSW__ && !defined __WXPM__
// I include several icons here, and will select which one to use dynamically
// based on the programName.
#include "fwin.xpm"
#include "csl.xpm"
#include "reduce.xpm"
#endif

static fwin_entrypoint *fwin_main_entry;
static int fwin_argc;
static char **fwin_argv;

int windowed_worker(int argc, char *argv[], fwin_entrypoint *fwin_main1)
{
    fwin_main_entry = fwin_main1;
    fwin_argc = argc;
    fwin_argv = argv;

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

// Before I set up the main text display class I will declare the events
// I use to commumicate with it.

// The events declared here are used to send data from the worker thread
// to the GUI thread.

enum
{
    FILE_QUIT = wxID_EXIT,     // I give these two standard...
    HELP_ABOUT = wxID_ABOUT,   // identities. Most other things are custom.
    TO_SCREEN = wxID_HIGHEST+1,
    SET_PROMPT,
    SET_MENUS,
    REFRESH_SWITCHES,
    SET_LEFT,
    SET_MID,
    SET_RIGHT,
    FLUSH_BUFFER1,
    FLUSH_BUFFER2,
    REQUEST_INPUT,
    MINIMISE_WINDOW,
    RESTORE_WINDOW,
    WORKER_FINISHED,

    FILE_READ,
    FILE_SAVE,
    FILE_SAVE_SELECTION,
    FILE_PAGE_SETUP,
    FILE_PRINT,
    FILE_PRINT_PREVIEW,

    EDIT_CUT,
    EDIT_COPY,
    EDIT_COPY_TEXT,
    EDIT_PASTE,
    EDIT_REINPUT,
    EDIT_SELECT_ALL,
    EDIT_CLEAR,
    EDIT_REDRAW,
    EDIT_HOME,
    EDIT_END,

    FONT_DUMMY,   // Used with menu items added and then instantly removed!
    FONT_CMTT,
    FONT_DEJA,
    FONT_SAZANAMI,
    FONT_FIREFLY,
    FONT_POINT10,
    FONT_POINT12,
    FONT_POINT14,
    FONT_POINT17,
    FONT_POINT20,
    FONT_POINT24,
    FONT_POINT28,
    FONT_POINT34,
    FONT_POINT40,

    BREAK_BREAK,
    BREAK_BACKTRACE,
    BREAK_PAUSE,
    BREAK_RESUME,
    BREAK_STOP_GO,
    BREAK_DISCARD_OUTPUT,

    HELP_HELP
};


class fwinText : public wxScrolledCanvas
{
public:
    fwinText(class fwinFrame *parent);
    wxCriticalSection work;    // for interaction with worker thread

    void OnDraw(wxDC &dc);
    void SetupFonts(wxDC &dc);
    void MainDraw(wxDC &dc, int from, int to);

    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    bool processChar(int c, int r, int m);  // returns true if Skip needed
    void OnMouse(wxMouseEvent &event);
    void OnSetFocus(wxFocusEvent &event);
    void OnKillFocus(wxFocusEvent &event);
    void OnToScreen(wxThreadEvent& event);
    void OnSetPrompt(wxThreadEvent& event);
    void OnSetMenus(wxThreadEvent& event);
    void OnRefreshSwitches(wxThreadEvent& event);
    void OnSetLeft(wxThreadEvent& event);
    void OnSetMid(wxThreadEvent& event);
    void OnSetRight(wxThreadEvent& event);
    void OnFlushBuffer(const char *fwin_buffer);
    void OnFlushBuffer1(wxThreadEvent& event);
    void OnFlushBuffer2(wxThreadEvent& event);
    void OnRequestInput(wxThreadEvent& event);
    void OnMinimiseWindow(wxThreadEvent& event);
    void OnRestoreWindow(wxThreadEvent& event);
    void OnWorkerFinished(wxThreadEvent& event);

// Both these will be initialised with a count of zero and no limit.
    wxSemaphore writing;  // Used when writing to the screen
    wxSemaphore reading;  // used when reading from the screen

    void OnFileRead();
    void OnFileSave();
    void OnFileSaveSelection();
    void OnFilePageSetup();
    void OnFilePrint();
    void OnFilePrintPreview();
    void OnEditCut();
    void OnEditCopy();
    void OnEditCopyText();
    void OnEditPaste();
    void OnEditReinput();
    void OnEditSelectAll();
    void OnEditClear();
    void OnEditRedraw();
    void OnEditHome();
    void OnEditEnd();
    void OnFontCMTT();
    void OnFontDeja();
    void OnFontSazanami();
    void OnFontFirefly();
    void OnFontPoint10();
    void OnFontPoint12();
    void OnFontPoint14();
    void OnFontPoint17();
    void OnFontPoint20();
    void OnFontPoint24();
    void OnFontPoint28();
    void OnFontPoint34();
    void OnFontPoint40();
    void OnBreakBreak();
    void OnBreakBacktrace();
    void OnBreakPause();
    void OnBreakResume();
    void OnBreakStopGo();
    void OnBreakDiscardOutput();
    void OnHelpHelp();

// I will have a buffer for transfer of characters from the application
// to the user-interface.
// The buffer holds 8-bit bytes. I will expect these to represent an UTF-8
// encoding, so that the application code will tend to use UTF-8 internally.
// The consequence will be that just the characters in the range 0x00 to 0x7f
// are unconditionally simple here!

#define FWIN_BUFFER_SIZE  1000
// If I have vsnprintf I can be fully safe, and most modern C libraries
// will provide this. If that is NOT available I will fall back on
// vsprintf, and hope that all strings printed will end up less than
// 200 bytes long.
#define SPARE_FOR_VFPRINTF 200

    char fwin_buffer1[FWIN_BUFFER_SIZE];
    char fwin_buffer2[FWIN_BUFFER_SIZE];

    int use_buffer1, fwin_in, fwin_out;

// While the program is not asking for input any characters from the keyboard
// will be stashed in a type-ahead buffer, But when input is asked for a
// line will be accepted and echoed on the screen, and when ENTER is pressed
// it will be passed on for use.
#define INITIAL_INPUT_BUFFER_SIZE 100
    int inputBufferSize;
    int inputBufferLen;
    int inputBufferP;
    unsigned char *inputBuffer;
    int awaiting;
    uint32_t unicodePrompt[MAX_PROMPT_LENGTH];
    int unicodePromptLength;
    int promptEnd;

    int recently_flushed;

    FILE *logfile;

// I make these two public because the surrounding fwinFrame touches them.
    bool firstPaint;
    int columnPos[81];

    int pauseFlags;
#define PAUSE_PAUSE      1
#define PAUSE_STOP       2
#define PAUSE_DISCARD    4

    class fwinFrame *frame;
    bool fontPriorityCMTT;
    int sbWidth;
    int windowWidth, windowHeight;
    int rowHeight, rowCount, virtualRowCount;
    wxFont *fixedPitch, *fixedAlternate, *fixedCJK;
private:
    wxString cjkFontName;
    int currentFont;
    const wxColour *textColour;

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
// textEnd points at the position in textBuffer one beyond the final
// character stored. Ie it is zero if the buffer is empty.
// caretPos is between zero and textEnd (inclusive) and denotes a position
// between two characters where insertion might happen.
    uint32_t *textBuffer;
// Only the bottom 21 bits are genuine character data...
#define TXT(n) (textBuffer[n] & 0x001fffff)
    int textBufferSize;
    void enlargeTextBuffer();
//
// caretPos indicates a cell within textBuffer, but it represents the gap
// between the previous character and the one stored at that position. So
// when you insert a character it goes into that gap. And delete-forwards and
// delete-backwards remove the characters after or before that gap.
// caretPos=0 puts the caret before any character in the buffer.
// caretPos=endText puts the caret after the final character in the text.
// (note that if the buffer is empty both those case apply at the same time).
//
    wxCaret *caret;
    int caretPos;
    void repositionCaret(int w=0, int r=0, int c=0);
    int32_t locateChar(int p, int w=0, int r=0, int c=0);
// The result handed back by locateChar is a packed (row,column) pair.
// It indicates the location the character would start on the screen apart
// from any line-wrap it might trigger.
#define PACK(r, c) ((r)<<16 | (c))
#define ROW(n)     (((n) >> 16) & 0xffff)
#define COL(n)     ((n) & 0xffff)

    int DrawTextRow(wxDC &dc, int y, int pos);
    int SkipTextRow(int pos);
    int textEnd;
    int historyNumber;

    int options;
#define READONLY     1

    int keyFlags;
#define ANY_KEYS     1
#define ESC_PENDING  2

    int flags;
#define FLAG_CHANGED 1
#define FLAG_TIP     2

#define TYPEAHEAD_SIZE 100
    uint32_t ahead_buffer[TYPEAHEAD_SIZE];
    int type_in, type_out;

    void type_ahead(uint32_t c);
    int searchFlags;
#define SEARCH_LENGTH    (searchFlags & 0xff)
#define SEARCH_FORWARD   0x100
#define SEARCH_BACKWARD  0x200
    uint32_t searchString[256];
    int searchStack[256];
    int startMatch;

    void beep();
    void insertChar(uint32_t ch);
    void insertString(wxString s);
    void insertChars(uint32_t *s, int len);
    void replaceChars(uint32_t *s, int len);
    void deleteChars(int len);
    void insertNewline();
    void deleteForwards(int n);
    void deleteBackwards(int n);
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
    void unicodeInput();
    void ctrlXcommand();
    void paste();
    void killSelection();
    void deleteCurrentLine();
    int setInputText(const unsigned char *s);
    void transpose();
    void capitalize();
    void lowerCase();
    void upperCase();
    void escapePressed();
    void makePositionVisible(int p);
    int editable;
    int trySearch();
    void historyNext();
    void historyPrev();
    void searchHistoryNext();
    void searchHistoryPrev();
    unsigned char *input_history[INPUT_HISTORY_SIZE];
    int historyNextEntry,
        historyCurrent,
        longestHistoryLine;
    int historyFirst, historyLast;


    void historyInit();
    void historyEnd();
    void historyAdd(unsigned char *s, int n);
    unsigned char *historyGet(int n);
    int matchString(const char *pat, int n, const char *text);
    int isEditable();
    int isEditableForBackspace();
    void rotateClipboard();
    void reinput();
    void setCaretPos(int n);
    void interrupt();
    void displayBacktrace();

    int unpackUTF8chars(uint32_t *u, const char *s, int n);

    int MapChar(int c);      // map from TeX character code to BaKoMa+ one

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fwinText, wxScrolledCanvas)
    EVT_CHAR(                     fwinText::OnChar)
    EVT_KEY_DOWN(                 fwinText::OnKeyDown)
    EVT_LEFT_UP(                  fwinText::OnMouse)
    EVT_SET_FOCUS(                fwinText::OnSetFocus)
    EVT_KILL_FOCUS(               fwinText::OnKillFocus)
    EVT_THREAD(TO_SCREEN,         fwinText::OnToScreen)
    EVT_THREAD(SET_PROMPT,        fwinText::OnSetPrompt)
    EVT_THREAD(SET_MENUS,         fwinText::OnSetMenus)
    EVT_THREAD(REFRESH_SWITCHES,  fwinText::OnRefreshSwitches)
    EVT_THREAD(SET_LEFT,          fwinText::OnSetLeft)
    EVT_THREAD(SET_MID,           fwinText::OnSetMid)
    EVT_THREAD(SET_RIGHT,         fwinText::OnSetRight)
    EVT_THREAD(FLUSH_BUFFER1,     fwinText::OnFlushBuffer1)
    EVT_THREAD(FLUSH_BUFFER2,     fwinText::OnFlushBuffer2)
    EVT_THREAD(REQUEST_INPUT,     fwinText::OnRequestInput)
    EVT_THREAD(MINIMISE_WINDOW,   fwinText::OnMinimiseWindow)
    EVT_THREAD(RESTORE_WINDOW,    fwinText::OnRestoreWindow)
    EVT_THREAD(WORKER_FINISHED,   fwinText::OnWorkerFinished)
END_EVENT_TABLE()

fwinText *panel = NULL;

class fwinFrame : public wxFrame
{
public:
    fwinFrame();

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);
    void OnClose(wxCloseEvent &event);
// The various menu items are delegated to handlers in the text pane.
    void OnFileRead(wxCommandEvent &event)
    {   panel->OnFileRead(); };
    void OnFileSave(wxCommandEvent &event)
    {   panel->OnFileSave(); };
    void OnFileSaveSelection(wxCommandEvent &event)
    {   panel->OnFileSaveSelection(); };
    void OnFilePageSetup(wxCommandEvent &event)
    {   panel->OnFilePageSetup(); };
    void OnFilePrint(wxCommandEvent &event)
    {   panel->OnFilePrint(); };
    void OnFilePrintPreview(wxCommandEvent &event)
    {   panel->OnFilePrintPreview(); };
    void OnEditCut(wxCommandEvent &event)
    {   panel->OnEditCut(); };
    void OnEditCopy(wxCommandEvent &event)
    {   panel->OnEditCopy(); };
    void OnEditCopyText(wxCommandEvent &event)
    {   panel->OnEditCopyText(); };
    void OnEditPaste(wxCommandEvent &event)
    {   panel->OnEditPaste(); };
    void OnEditReinput(wxCommandEvent &event)
    {   panel->OnEditReinput(); };
    void OnEditSelectAll(wxCommandEvent &event)
    {   panel->OnEditSelectAll(); };
    void OnEditClear(wxCommandEvent &event)
    {   panel->OnEditClear(); };
    void OnEditRedraw(wxCommandEvent &event)
    {   panel->OnEditRedraw(); };
    void OnEditHome(wxCommandEvent &event)
    {   panel->OnEditHome(); };
    void OnEditEnd(wxCommandEvent &event)
    {   panel->OnEditEnd(); };
    void OnFontCMTT(wxCommandEvent &event)
    {   panel->OnFontCMTT(); };
    void OnFontDeja(wxCommandEvent &event)
    {   panel->OnFontDeja(); };
    void OnFontSazanami(wxCommandEvent &event)
    {   panel->OnFontSazanami(); };
    void OnFontFirefly(wxCommandEvent &event)
    {   panel->OnFontFirefly(); };
    void OnFontPoint10(wxCommandEvent &event)
    {   panel->OnFontPoint10(); };
    void OnFontPoint12(wxCommandEvent &event)
    {   panel->OnFontPoint12(); };
    void OnFontPoint14(wxCommandEvent &event)
    {   panel->OnFontPoint14(); };
    void OnFontPoint17(wxCommandEvent &event)
    {   panel->OnFontPoint17(); };
    void OnFontPoint20(wxCommandEvent &event)
    {   panel->OnFontPoint20(); };
    void OnFontPoint24(wxCommandEvent &event)
    {   panel->OnFontPoint24(); };
    void OnFontPoint28(wxCommandEvent &event)
    {   panel->OnFontPoint28(); };
    void OnFontPoint34(wxCommandEvent &event)
    {   panel->OnFontPoint34(); };
    void OnFontPoint40(wxCommandEvent &event)
    {   panel->OnFontPoint40(); };
    void OnBreakBreak(wxCommandEvent &event)
    {   panel->OnBreakBreak(); };
    void OnBreakBacktrace(wxCommandEvent &event)
    {   panel->OnBreakBacktrace(); };
    void OnBreakPause(wxCommandEvent &event)
    {   panel->OnBreakPause(); };
    void OnBreakResume(wxCommandEvent &event)
    {   panel->OnBreakResume(); };
    void OnBreakStopGo(wxCommandEvent &event)
    {   panel->OnBreakStopGo(); };
    void OnBreakDiscardOutput(wxCommandEvent &event)
    {   panel->OnBreakDiscardOutput(); };
    void OnHelpHelp(wxCommandEvent &event)
    {   panel->OnHelpHelp(); };

    class fwinWorker *worker;
    void CloseAction();

private:
    int screenWidth, screenHeight;

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(fwinFrame, wxFrame)
    EVT_CLOSE(                     fwinFrame::OnClose)
    EVT_MENU(wxID_EXIT,            fwinFrame::OnExit)
    EVT_MENU(wxID_ABOUT,           fwinFrame::OnAbout)
    EVT_SIZE(                      fwinFrame::OnSize)
    EVT_MENU(FILE_READ,            fwinFrame::OnFileRead)
    EVT_MENU(FILE_SAVE,            fwinFrame::OnFileSave)
    EVT_MENU(FILE_SAVE_SELECTION,  fwinFrame::OnFileSaveSelection)
    EVT_MENU(FILE_PAGE_SETUP,      fwinFrame::OnFilePageSetup)
    EVT_MENU(FILE_PRINT,           fwinFrame::OnFilePrint)
    EVT_MENU(FILE_PRINT_PREVIEW,   fwinFrame::OnFilePrintPreview)
    EVT_MENU(EDIT_CUT,             fwinFrame::OnEditCut)
    EVT_MENU(EDIT_COPY,            fwinFrame::OnEditCopy)
    EVT_MENU(EDIT_COPY_TEXT,       fwinFrame::OnEditCopyText)
    EVT_MENU(EDIT_PASTE,           fwinFrame::OnEditPaste)
    EVT_MENU(EDIT_REINPUT,         fwinFrame::OnEditReinput)
    EVT_MENU(EDIT_SELECT_ALL,      fwinFrame::OnEditSelectAll)
    EVT_MENU(EDIT_CLEAR,           fwinFrame::OnEditClear)
    EVT_MENU(EDIT_REDRAW,          fwinFrame::OnEditRedraw)
    EVT_MENU(EDIT_HOME,            fwinFrame::OnEditHome)
    EVT_MENU(EDIT_END,             fwinFrame::OnEditEnd)
    EVT_MENU(FONT_CMTT,            fwinFrame::OnFontCMTT)
    EVT_MENU(FONT_DEJA,            fwinFrame::OnFontDeja)
    EVT_MENU(FONT_SAZANAMI,        fwinFrame::OnFontSazanami)
    EVT_MENU(FONT_FIREFLY,         fwinFrame::OnFontFirefly)
    EVT_MENU(FONT_POINT10,         fwinFrame::OnFontPoint10)
    EVT_MENU(FONT_POINT12,         fwinFrame::OnFontPoint12)
    EVT_MENU(FONT_POINT14,         fwinFrame::OnFontPoint14)
    EVT_MENU(FONT_POINT17,         fwinFrame::OnFontPoint17)
    EVT_MENU(FONT_POINT20,         fwinFrame::OnFontPoint20)
    EVT_MENU(FONT_POINT24,         fwinFrame::OnFontPoint24)
    EVT_MENU(FONT_POINT28,         fwinFrame::OnFontPoint28)
    EVT_MENU(FONT_POINT34,         fwinFrame::OnFontPoint34)
    EVT_MENU(FONT_POINT40,         fwinFrame::OnFontPoint40)
    EVT_MENU(BREAK_BREAK,          fwinFrame::OnBreakBreak)
    EVT_MENU(BREAK_BACKTRACE,      fwinFrame::OnBreakBacktrace)
    EVT_MENU(BREAK_PAUSE,          fwinFrame::OnBreakPause)
    EVT_MENU(BREAK_RESUME,         fwinFrame::OnBreakResume)
    EVT_MENU(BREAK_STOP_GO,        fwinFrame::OnBreakStopGo)
    EVT_MENU(BREAK_DISCARD_OUTPUT, fwinFrame::OnBreakDiscardOutput)
    EVT_MENU(HELP_HELP,            fwinFrame::OnHelpHelp)
END_EVENT_TABLE()

static bool shouldExit;

class fwinWorker : public wxThread
{
public:
    fwinWorker(fwinText *p)
        : wxThread(wxTHREAD_DETACHED)
        {   parent = p;
            shouldExit = false;
        };
   ~fwinWorker();
    void DoExit()
    {   Exit(NULL);
    };
    void sendToScreen(wxString s); // for debugging
private:
    fwinText *parent;
protected:
    virtual wxThread::ExitCode Entry();
};

class fwinPrintout: public wxPrintout
{
public:
    fwinPrintout(fwinText* p, const wxString &title = "wxfwin printout")
        : wxPrintout(title) { parent = p; }

    void GetPageInfo(int *minPage, int *maxPage, int *from, int *to);
    bool HasPage(int page);
    bool OnPrintPage(int page);

private:
    fwinText *parent;
};


fwinWorker::~fwinWorker()
{
    wxCriticalSectionLocker lock(panel->work);
    panel->frame->worker = NULL;
}

void fwinText::OnWorkerFinished(wxThreadEvent& event)
{
    FWIN_LOG(("worker thread terminated\n"));
// In which case quit!
    Destroy();
    exit(returncode);
}



wxThread::ExitCode fwinWorker::Entry()
{
    int rc = (*fwin_main_entry)(fwin_argc, fwin_argv);
    fwin_ensure_screen();
#define pause_on_exit 0
    FWIN_LOG(("return from fwin_main_entry is %d pause_on_exit=%d\n",
             rc, pause_on_exit));
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, WORKER_FINISHED);
    wxQueueEvent(panel, event);
    return (wxThread::ExitCode)rc;
}

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
    memset(uppercasename, 0, sizeof(uppercasename));
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

static const char*fontNames[] =
{
    "DejaVuSansMono",    // "DejaVu Sans Mono"                .otf
    "cmuntt",            // "CMU Typewriter Text (Regular)"   .ttf
    "fireflysung",       // "AR PL New Sung"                  .ttf
    "sazanami-gothic",   // "Sazanami Gothic (Regular)"       .ttf
    "sazanami-mincho",   // "Sazanami Mincho (Regular)"       .ttf



// For Windows I am rendering everything under gdiplus (which lets me scale
// things nicely) and it appears that some .otf fonts (including ones that
// contain embedded bitmaps) do not display that way. So I will use fonts
// downgraded to mere .ttf format.
// On Linux and Macintosh (and other Unix-like platforms) I will try using
// the original .otf versions of the fonts...

// Font containing characters from cmsy10, cmmi10, cmex10 etc etc.
    "latinmodern-math",            // Latin Modern Math

// ROMAN FACES

// Like cmr10 (etc) but with a wider range of characters.
    "lmroman5-regular",            // LM Roman Regular 5
    "lmroman6-regular",            // LM Roman Regular 6
    "lmroman7-regular",            // LM Roman Regular 7
    "lmroman8-regular",            // LM Roman Regular 8
    "lmroman9-regular",            // LM Roman Regular 9
    "lmroman10-regular",           // LM Roman Regular 10
    "lmroman12-regular",           // LM Roman Regular 12
    "lmroman17-regular",           // LM Roman Regular 17

// Bold variant on the above.
    "lmroman5-bold",             
    "lmroman6-bold",             
    "lmroman7-bold",             
    "lmroman8-bold",             
    "lmroman9-bold",             
    "lmroman10-bold",            
    "lmroman12-bold",            

// Italic
    "lmroman7-italic",           
    "lmroman8-italic",           
    "lmroman9-italic",           
    "lmroman10-italic",          
    "lmroman12-italic",          

// Bold Italic - but which stage only one size is provided.
    "lmroman10-bolditalic",      

// Roman Slanted (n.b. not Italic!)
    "lmromanslant8-regular",     
    "lmromanslant9-regular",     
    "lmromanslant10-regular",    
    "lmromanslant12-regular",    
    "lmromanslant17-regular",    

// Slanted Bold
    "lmromanslant10-bold",       

// Roman with small caps in place of lower case
    "lmromancaps10-regular",     
    "lmromancaps10-oblique",     

// Roman demi-condensed
    "lmromandemi10-regular",     
    "lmromandemi10-oblique",     

// Roman Dunhill (risers seem very tall)
    "lmromandunh10-regular",     
    "lmromandunh10-oblique",     

// Roman Unslanted (has very twisty serifs)
    "lmromanunsl10-regular",     

// SANS SERIF FACES

// Basic Sans Serif in various design-sizes
    "lmsans8-regular",           
    "lmsans9-regular",           
    "lmsans10-regular",          
    "lmsans12-regular",          
    "lmsans17-regular",          

// Bold variant
    "lmsans10-bold",             

// Oblique versions
    "lmsans8-oblique",           
    "lmsans9-oblique",           
    "lmsans10-oblique",          
    "lmsans12-oblique",          
    "lmsans17-oblique",          

// Bold Oblique
    "lmsans10-boldoblique",      

// Semi-condensed
    "lmsansdemicond10-regular",  
    "lmsansdemicond10-oblique",  

// Sans Quot (for use in quotations)
    "lmsansquot8-regular",
    "lmsansquot8-bold",          
    "lmsansquot8-oblique",       
    "lmsansquot8-boldoblique",   

// MONOSPACED FONTS

// Basic monospaced font in various design sizes
    "lmmono8-regular",           
    "lmmono9-regular",           
    "lmmono10-regular",          
    "lmmono12-regular",          

// Italic
    "lmmono10-italic",           

// With small caps instead of lower case
    "lmmonocaps10-regular",      
    "lmmonocaps10-oblique",      

// "Light"
    "lmmonolt10-regular",        
    "lmmonolt10-bold",           
    "lmmonolt10-oblique",        
    "lmmonolt10-boldoblique",    

// "Light Condensed"
    "lmmonoltcond10-regular",    
    "lmmonoltcond10-oblique",    

// Proportional
    "lmmonoprop10-regular",      
    "lmmonoprop10-oblique",      

// Proportional Light
    "lmmonoproplt10-regular",    
    "lmmonoproplt10-bold",       
    "lmmonoproplt10-oblique",    
    "lmmonoproplt10-boldoblique",

// Slanted
    "lmmonoslant10-regular"      
};

#endif // MACINTOSH

// Some characters map onto double-width symbols from the CJK fonts, while
// many come from either cmuntt or DejaVuSansMono and are single width.
// A VERY few characters are synthesised by drawing them since they are not
// available in either of the main fonts I am using! I expect any characters
// from the CJK fonts that have codes under 0x2000 to be "half width".

#define double_width(ch)                \
    (!CMTT_AVAIL((ch)) &&               \
     !DEJA_AVAIL((ch)) &&               \
     ((ch) >= 0x2000)  &&               \
     ((ch) != 0x2135)  && /* alefsym */ \
     ((ch) != 0x2118)  && /* weierp */  \
     ((ch) != 0x2111)  && /* imag */    \
     ((ch) != 0x211c))    /* real */

// The following table shows the character coverage provided by the
// cmuntt.otf font I use (that is Computer Modern Typewriter Unicode).
// I will use that font whenever the relevant bit here says it is
// appropriate, and will use my CJK font otherwise. This table was created
// using a jiffy Java program, and at present related to the 0.6.3a version
// of the font concerned.

uint32_t cmtt_coverage[2048] = {
    0x00640000, 0xffffffff, 0xffffffff, 0xfffffffe,
    0x00000000, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xcdfcfc66, 0x79bffcff, 0xfcffcfff,
    0x8283a472, 0xc5b58161, 0xfffff804, 0x33c0fccf,
    0xfffffff3, 0x470337c0, 0x0000ffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xf3fbffff, 0xffc00060,
    0x10474000, 0x62300538, 0x00040000, 0x60000c22,
    0x0febffff, 0xdfffffff, 0xfffe40fd, 0xc0000400,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xfeffffff, 0xffffffff, 0xfffeffff, 0xffffffcf,
    0x00003000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000001, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 1000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 1800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x813400c8, 0x00000000, 0x00000000, 0x00000000,
    0x0000f100, 0x00000000, 0x0cc00000, 0x00000000,
    0xfffff0f3, 0xff3cffff, 0xfff00fff, 0xf0ffff0f,
    0xffffffd0, 0xffffffff, 0xffffffff, 0xffffffc0,
    0xff00fc00, 0xff00ff00, 0xfc00ff00, 0xff00fffc,
    0xff00ff00, 0xff00fbdf, 0xfb5ff3d7, 0xffd73b5e,
    /* Code 2000 */
    0x518ffaff, 0xe2fec075, 0x8e002800, 0x003f0000,
    0x80000000, 0x4a582000, 0x00000000, 0x00000000,
    0x10000302, 0xa3020000, 0x00000000, 0x00000000,
    0x0000f180, 0x00000000, 0x00000000, 0x00000000,
    0x02002120, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x02000000, 0x00000000,
    0x00000000, 0x20600000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x30000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xa0088888, 0x08080808, 0x0000ffff, 0xfff00000,
    0x00000000, 0x00000000, 0x00100000, 0x02000000,
    0x00000000, 0x00040000, 0x80000000, 0x00200000,
    0x00000000, 0x00062000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 2800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00008000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000080, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 3000 */
    0x00000030, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 3800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 4000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 4800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 5000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 5800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 6000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 6800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 7000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 7800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 8000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 8800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 9000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 9800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code a000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000018, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code a800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code b000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code b800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code c000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code c800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code d000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code d800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code e000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code e800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00001400,
    /* Code f000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xffff7fff, 0xffffffff, 0xfffffff9, 0xffffffff,
    0xfdffffff, 0xfffffc00, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000e000f, 0xffffffff,
    0xf000000f, 0xffff0000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0xffbfe000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xffffbfff, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00438e02, 0x00000000,
    0x00000000, 0x0800ffc0, 0x00000000, 0x00000000,
    0x00000000, 0x20000000, 0x00000000, 0x00000000,
    /* Code f800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xff000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x02000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

uint32_t deja_coverage[384] =
{
    0x00640000, 0xffffffff, 0xffffffff, 0xfffffffe,
    0x00000000, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xf007ffff, 0xf3ff8ecf,
    0xffffffff, 0xcfffffff, 0xcc0cffff, 0xffffffff,
    0xffffffff, 0xffffffdf, 0xc3ccf3fe, 0xffc21000,
    0xffffffff, 0xffffffff, 0x10000080, 0x40000c22,
    0x0febffff, 0xdfffffff, 0xfffeffff, 0xc000ffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0x30003000,
    0x0000fff0, 0x3c3ff030, 0xf999ffff, 0xffffffc0,
    0x0000c03c, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x03680411, 0x7fffffe0, 0xfffffc20, 0xfffc0873,
    0x9b004080, 0x08410002, 0x00080000, 0x0000ffc0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x69a40f7f, 0x7537ffd8, 0x00fc0000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 1000 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000ffff, 0xfffffff8,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    /* Code 1800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x20c00b07, 0x000efffb, 0xfffffff0, 0x3c000190,
    0x0400001f, 0xffffff7f, 0x00000000, 0x00000000,
    0xfffff0ff, 0xfffcffff, 0xfffc0fff, 0xf0ffffcf,
    0xffffffd1, 0xc00cc3cc, 0x033c00fc, 0xfcf3fcc0,
    0xfffffcfc, 0xffffffff, 0xfcfcff55, 0xfffffffc,
    0xffffffff, 0xfffffbff, 0xfbfff3f7, 0xffff3bfe,
    /* Code 2000 */
    0xffeffdff, 0xf2ffff6e, 0x07c00001, 0x003fcfff,
    0xfffef800, 0xfffffcc0, 0x00000000, 0x00000000,
    0x24070764, 0x2a320000, 0x00001fff, 0x00000000,
    0x0000ffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xfffd75ff, 0x81fc0ffc, 0x7fffffff, 0xffc7ffff,
    0xfff1e7ff, 0xfc000000, 0x0604003f, 0xffc10000,
    0xfefffccf, 0xc79005fe, 0x79dcb9fb, 0x9cdf9fe4,
    0xf0f0041f, 0xfffe0000, 0x00030000, 0x00000000,
    0x00000000, 0x10000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffff00ff, 0xffffffff, 0xffffffff,
    0xfff0fff8, 0xc000c000, 0x00000000, 0x00000000,
    0x7bcfffff, 0xff7fffff, 0xfff5e2fe, 0x7ffffc00,
    0x000008ff, 0xffff7ffe, 0x06000000, 0x80c00000,
    /* Code 2800 */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00100030,
    0x00000000, 0x00010000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00003fe0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0807876f,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000080, 0x3c020000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
// I will not use any characters from this font beyond this point.
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

int add_custom_fonts() // return 0 on success.
{
#ifndef MACINTOSH
    int trouble = 0;
// Note that on a Mac I put the required fonts in the Application Bundle.
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   char nn[LONGEST_LEGAL_FILENAME];
// The font files I have come with a mix of .ttf and .otf suffixes. On
// windows because I use wxGraphicsContext I use GDI+ and that seems to be
// unable to cope with many .otf fonts, so in that case I use .ttf versions.
// On other platforms I will use the original versions...
        const char *suffix = i==0 ? "otf" : "ttf";
#ifndef WIN32
        if (i > 4) suffix = "otf";
#endif
        sprintf(nn, "%s/%s/%s.%s",
                    programDir, toString(fontsdir), fontNames[i], suffix);
        printf("Adding %s: ", nn); fflush(stdout);
        wxString widename(nn);
        if (wxFont::AddPrivateFont(widename))
            printf(" OK\n");
        else
        {   printf("Failed\n");
            trouble = 1;
        }
    }
    printf("About to activate\n"); fflush(stdout);
    if (wxFont::ActivatePrivateFonts())
        printf("Activated OK\n");
    else
    {   printf("Activation failed\n");
        trouble = 1;
    }
    fflush(stdout);
    return trouble;
#else  // MACINTOSH
    return 0;
#endif // MACINTOSH
}

int fwinText::MapChar(int c)
{
// This function maps between a TeX character encoding and the one that is
// used by the fonts and rendering engine that I use. This is about
// to be utterly redundant since it related to TeX-emcoded fonts.
    if (c < 0xa) return 0xa1 + c;
    else if (c == 0xa) return 0xc5;
    else if (c == 0x14) return 0x2219;
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
       : wxFrame(NULL, wxID_ANY, "wxfwin")
{
    SetIcon(wxICON(fwin));
// I will set up some menus here
    wxMenu *fileMenu = new wxMenu;
    wxMenu *editMenu = new wxMenu;
    wxMenu *fontMenu = new wxMenu;
    wxMenu *breakMenu = new wxMenu;
    wxMenu *loadPackageMenu = new wxMenu;
    wxMenu *switchMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;

    fileMenu->Append(FILE_READ, "&Read...", "Read a file");
    fileMenu->Append(FILE_SAVE, "&Save...", "Save to a file");
    fileMenu->Append(FILE_SAVE_SELECTION, "Save Se&lection", "Save selection");
    fileMenu->Append(FILE_PAGE_SETUP, "Page Se&tup", "Page setup");
    fileMenu->Append(FILE_PRINT, "&Print", "Print");
    fileMenu->Append(FILE_PRINT_PREVIEW, "Pri&nt Preview", "Print Preview");
    fileMenu->Append(FILE_QUIT, "&Quit\tCtrl+\\", "Quit");

    editMenu->Append(EDIT_CUT, "&Cut", "Cut");
    editMenu->Append(EDIT_COPY, "C&opy", "Copy");
    editMenu->Append(EDIT_COPY_TEXT, "Copy &Text", "Copy as text");
    editMenu->Append(EDIT_PASTE, "&Paste\tCtrl+V", "Paste");
    editMenu->Append(EDIT_REINPUT, "&Reinput\tCtrl+^", "Reinput");
    editMenu->Append(EDIT_SELECT_ALL, "Select &All", "Select All");
    editMenu->Append(EDIT_CLEAR, "C&lear\tCtrl+L", "Clear");
    editMenu->Append(EDIT_REDRAW, "Re&draw\tCtrl+R", "Redraw");
    editMenu->Append(EDIT_HOME, "&Home", "Home");
    editMenu->Append(EDIT_END, "&End", "End");

    fontMenu->AppendRadioItem(FONT_CMTT, "Computer &Modern", "Prefer Computer Modern (cmtt) Font");
    fontMenu->AppendRadioItem(FONT_DEJA, "&DejaVu", "Prefer DejaVu Typewriter Text Font");
    fontMenu->AppendSeparator();
// The next line is a hack that keeps the two sets of radio buttons separate.
    fontMenu->Remove(fontMenu->Append(FONT_DUMMY, "dummy"));
    fontMenu->AppendRadioItem(FONT_SAZANAMI, "&Sazanami", "Use Sazanami CJK Font");
    fontMenu->AppendRadioItem(FONT_FIREFLY, "&Firefly Sung", "Use Firefly Sung CJK Font");
    fontMenu->AppendSeparator();
// The next line is a hack that keeps the two sets of radio buttons separate.
    fontMenu->Remove(fontMenu->Append(FONT_DUMMY, "dummy"));
    fontMenu->AppendRadioItem(FONT_POINT10, "&10 points", "Use nominally 10 point font");
    fontMenu->AppendRadioItem(FONT_POINT12, "1&2 points", "Use nominally 12 point font");
    fontMenu->AppendRadioItem(FONT_POINT14, "1&4 points", "Use nominally 14 point font");
    fontMenu->AppendRadioItem(FONT_POINT17, "1&7 points", "Use nominally 17 point font");
    fontMenu->AppendRadioItem(FONT_POINT20, "20 &points", "Use nominally 20 point font");
    fontMenu->AppendRadioItem(FONT_POINT24, "24 p&oints", "Use nominally 24 point font");
    fontMenu->AppendRadioItem(FONT_POINT28, "28 po&ints", "Use nominally 28 point font");
    fontMenu->AppendRadioItem(FONT_POINT34, "34 poi&nts", "Use nominally 34 point font");
    fontMenu->AppendRadioItem(FONT_POINT40, "40 poin&ts", "Use nominally 40 point font");

    breakMenu->Append(BREAK_BREAK, "&Break", "Break");
    breakMenu->Append(BREAK_BACKTRACE, "Bac&ktrace", "Backtrace");
    breakMenu->Append(BREAK_PAUSE, "&Pause", "Pause");
    breakMenu->Append(BREAK_RESUME, "&Resume", "Resume");
    breakMenu->Append(BREAK_STOP_GO, "&Stop/Go", "Stop/Go");
    breakMenu->Append(BREAK_DISCARD_OUTPUT, "&Discard Output", "Discard Output");

// The "Load Package" and "Switch" menus get populated dynamically later on.

    helpMenu->Append(HELP_HELP, "&Help\tF1", "display Help in a browser");
    helpMenu->Append(HELP_ABOUT, "&About\tF2", "Show the About dialog");

// The keyboard shortcuts indicated here are not always going to be the
// ones you would have first expeced. This is because all sorts of combinations
// are used for keyboard-driven editing. A good example is ALT-F which moves
// forward one word, and so can not (also) be used to open the File menu.

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "F&ile");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(fontMenu, "F&ont");
    menuBar->Append(breakMenu, "B&reak");
    menuBar->Append(loadPackageMenu, "Load Packa&ge");
    menuBar->Append(switchMenu, "&Switch");
    menuBar->Append(helpMenu, "Help&?");
    SetMenuBar(menuBar);

    CreateStatusBar(3);
    SetStatusText("Left stuff", 0);
    SetStatusText("Middle", 1);
    SetStatusText("Right", 2);

    wxToolBar *toolBar = CreateToolBar();

    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   FWIN_LOG(("There seem to be %d displays\n", numDisplays));
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
    worker = new fwinWorker(panel);
    FWIN_LOG(("worker = %p\n", worker));
    int rc = worker->Create(512*1024);  // Argument is stack size
    if (rc != wxTHREAD_NO_ERROR) FWIN_LOG(("Thread creation error = %d\n", rc));
    rc = worker->Run();
    if (rc != wxTHREAD_NO_ERROR) FWIN_LOG(("Thread run error = %d\n", rc));
// Note horribly well that the pointer "worker" may become invalid at any
// stage from here on. I have a wxCriticalSection called "work" that I can use
// to avoid trouble with that.
    SetMinClientSize(wxSize(400, 100));
    SetSize(width, height);
    Centre();
}

static wxPrintData *printData = NULL;
static wxPageSetupDialogData* pageSetupData = NULL;

fwinText::fwinText(fwinFrame *parent)
       : wxScrolled<wxWindow>(parent, wxID_ANY,
                    wxDefaultPosition, wxDefaultSize,
                    wxVSCROLL, "fwinText")
{
    frame = parent;
    sbWidth = wxSystemSettings::GetMetric(wxSYS_VSCROLL_X, this);
    fixedPitch = fixedAlternate = fixedCJK = NULL;
    fontPriorityCMTT = false;
// The available CJK fonts here are
//     Windows & Unix            Macintosh
//     Sazanami Mincho           Sazanami Mincho Regular
//     Sazanami Gothic           Sazanami Gothic Regular
//     AR PL New Sung            AR PL New Sung
// Right at present I will make a selection, but in due course I will
// provide a menu-driven option to let the user select.
#ifdef MACINTOSH
    cjkFontName = "Sazanami Mincho Regular";
#else
    cjkFontName = "Sazanami Mincho";
#endif
    wxColour c1(230, 200, 255);
    SetBackgroundColour(c1);
// These will be reviewed when I first paint the screen
    SetScrollRate(0, 10);
    virtualRowCount = 5;
    SetVirtualSize(wxDefaultCoord, 100);
    ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_ALWAYS);
    firstPaint = true;
// I start off with a 40K character buffer, which seems reasonably
// generous to me. The plan is that the buffer will automatically expand
// as needed.
    textBufferSize = 40000;
    textBuffer = (uint32_t *)malloc(textBufferSize*sizeof(uint32_t));
    textEnd = 0;
    searchFlags = 0;
    caret = NULL;
    caretPos = 0;
    promptEnd = -1;
    options = 0;
    keyFlags = 0;
    flags = 0;
    type_in = type_out = 0;
    historyNumber = historyFirst = historyLast = 0;
    historyInit();

    fwin_in = 0;
    use_buffer1 = 1;

    inputBufferSize = INITIAL_INPUT_BUFFER_SIZE;
    inputBuffer = (unsigned char *)malloc(inputBufferSize);
    inputBufferP = inputBufferLen = 0;
    awaiting = 0;
    unicodePrompt[0] = '>' | 0x02000000;
    unicodePromptLength = 1;

    printData = new wxPrintData();
    printData->SetPaperId(wxPAPER_A4); // or wxPAPER_ID_LETTER, say
    pageSetupData = new wxPageSetupDialogData();
    pageSetupData->SetMarginTopLeft(wxPoint(20, 20));
    pageSetupData->SetMarginBottomRight(wxPoint(20, 20));

    logfile = NULL; // a menu option will establish this to keep a log.

    writing.Post(); // enable output!
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
    if (caretPos==textEnd && caretPos!=0) caretPos--;
    if (caretPos==0 || TXT(caretPos) == '\n')  // already at start of line
    {   beep();
        return;
    }
    while (caretPos>=0 && TXT(caretPos) != '\n') caretPos--;
    caretPos++;
    repositionCaret();
}


// ^B  move back a character

void fwinText::moveLeft()
{
// If the mark is set maybe I should extend the selection...?
    if (caretPos==0)
    {   beep();
        return;
    }
// This moves from the start of any line to the end of the previous.
    caretPos--;
    repositionCaret();
}

// ALT-B move back a word

void fwinText::moveWordLeft()
{
    if (caretPos == 0)
    {   beep();
        return;
    }
    for (;;)  // back at least one char and over any whitespace
    {   caretPos--;
        if (caretPos < 0) break;
        wxUniChar ch = TXT(caretPos);
        if (!wxIsspace(ch)) break;
    }
    for (;;)
    {   if (caretPos < 0) break;
        wxUniChar ch = TXT(caretPos);
        if (wxIsspace(ch)) break;
        caretPos--;
    }
    caretPos++;
    repositionCaret();
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

// ^D  delete n characters under cursor (fowards)

void fwinText::deleteForwards(int n)
{
    deleteChars(n);
    repositionCaret();
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
    if (caretPos == textEnd)
    {   beep();
        return;
    }
    caretPos++;
    repositionCaret();
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
    setInputText((const unsigned char *)"");
    historyNumber = historyLast + 1;
    keyFlags &= ~ANY_KEYS;
#endif
}

// ^H  (backspace) delete char before cursor if that is reasonable.

void fwinText::deleteBackwards(int n)
{
    caretPos -= n;
    deleteChars(n);
    repositionCaret();
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
    killSelection();
    setInputText((const unsigned char *)"");
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

int fwinText::setInputText(const unsigned char *text)
{
    caretPos = promptEnd;
    deleteChars(textEnd - promptEnd);
    makePositionVisible(caretPos);
    return caretPos;
}


// The history routines here are never invoked unless we are awaiting input

void fwinText::historyNext()
{
#ifdef RECONSTRUCTED
    const unsigned char *history_string;
    if (historyLast == -1) // no history lines at all to retrieve!
    {   beep();
        return;
    }
    if (historyNumber < historyLast) historyNumber++;
    if ((history_string = historyGet(historyNumber)) == NULL)
    {   beep();
        return;
    }
    setInputText(history_string);
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
    const unsigned char *history_string = historyGet(historyNumber);
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
    const unsigned char *history_string;
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
    setInputText(history_string);
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
    caretPos = textEnd;
    insertChar('\n');
// stuff from promptEnd to textEnd should now be moved to inputBuffer.
    int n = 0;
    FWIN_LOG(("promptEnd = %d textEnd = %d\n", promptEnd, textEnd));
    for (int i=promptEnd; i<textEnd; i++)
    {   int c = TXT(i);    // Just the character - no colour etc info
        FWIN_LOG(("Move char %x (%c) to posn %d in inputBuffer\n", c, c, n));
        if (n > inputBufferSize - 5)
        {   inputBufferSize = (4*inputBufferSize)/3;
            inputBuffer = (unsigned char *)realloc(inputBuffer, inputBufferSize);
        }
        n += utf_encode(&inputBuffer[n], c);
    }
// I enter the line that has just been collected into the history
// record.
    historyAdd(inputBuffer, n-1);  // I omit the NEWLINE from the history
// Adding an entry could cause an old one to be discarded. So I now ensure
// that I know what the first and last recorded numbers are.
    historyLast = historyNextEntry - 1;
    historyFirst = historyNextEntry - INPUT_HISTORY_SIZE;
    if (historyFirst < 0) historyFirst = 0;
    historyNumber = historyLast + 1; // so that ALT-P moves to first entry
    inputBufferLen = n;
    inputBufferP = 0;
    recently_flushed = 0;
// stuff user typed is now in buffer... I should never have got here unless
// the user thread was waiting, so here I unlock it, to tell it that
// the input buffer is ready.
    awaiting = 0;
    reading.Post();
}


int32_t fwinText::locateChar(int p, int w, int r, int c)
{
// Normally call as locateChar(p, 0, 0, 0) but the final 3
// args are to allow resumption after a previous call.
// Return the row/column of the character cell corresponding to address
// p in the buffer. The pointer p may be equal to textEnd, ie one beyond
// the actual text in the buffer.
// This needs to take a little care with line-wrapping. It can return
// column numbers 0 to 79 in general, but if p is textEnd or the character
// there is a newline it can return a column number of 80.
// tabs are expanded with tab-stops every 8 columns. The code here exploits
// the fact that the width (80 columns) is a multiple of the tab width, so
// while a tab may take one up to column 80 it can not go beyond without the
// whole tab effect occurring on the next row. It further allows that some
// characters are double-width (a few special symbols and all CJK ideograms).
// Fortunately the treatment of tabs gives a start to how I handle such.

// Well at one stage I tried to restrict my search to the section of text
// actually visible on the screen. However the proper model now is that the
/// text is a single huge buffer and scrolling causes just a bit of it to
// be displayed but coordinates here should relate to the full buffer. So it
// USED to be the case that I started w off as firstVisibleRow. But now I
// start off at the start of the buffer. At some stage if I am keen I will
// arrange an index that lets me skip lines or rows fast.
    if (w == -1) w = 0;
    while (w != p)
    {   uint32_t ch = TXT(w);
        int wide = double_width(ch);
// The characters processed within this loop are all BEFORE the one I am
// interested in, and so I process tabs, newlines and line-wrap.
        if (ch == '\n')
        {   c = 0;
            r++;
        }
        else if (c == 79 && wide)
        {   c = 2;
            r++;
        }
        else if (c == 80)
        {   if (ch == '\t') c = 8;       // tab in column 80
            else c = 1;
            r++;
        }
        else if (ch == '\t') c += 8 - (c & 7); // tab
        else if (wide) c += 2;
        else c++;
        w++;
    }
// What I have done now is to find the end position of the character
// before position p. This is the start position for the character at
// position p unless there is a line-wrap to perform. That could be the
// case if r=80 and the character concerned is not a newline.
    return PACK(r, c);
}

void fwinText::insertChar(uint32_t ch)
{
    insertChars(&ch, 1);
}

void fwinText::insertString(wxString s)
{
    size_t n = s.Len();
// insertString has a LIMITED capability as regarsd the string length.
// it is probably onnly really intended for debugging use.
    if (n > 100)
    {   FWIN_LOG(("Truncating in insertString\n"));
        n = 100;
    }
    uint32_t b[100];
    for (size_t i=0; i<n; i++) b[i] = s.GetChar(i);
    insertChars(b, (int)n);
}

// I rather believe that all edits can be brought down to combinations
// of three fundamental ways to update the screen - so if I implement those
// and get the corresponding screen update arrangements correct I should
// be in good shape:
//   insertChars(characters, n)  insert n characters just after the caret
//   deleteChars(n)              delete n characters after the caret
//   replaceChars(characters, n) replace characters just after the caret.
// both insert and replace will move the caret to a position after the
// new material.

void fwinText::insertChars(uint32_t *pch, int n)
{
    int32_t loc1 = locateChar(caretPos);
    int r1 = ROW(loc1), c1 = COL(loc1);
// I find the location of the end of the line that the character I am
// about to insert will be on.
    int lineEnd = caretPos;
    while (lineEnd < textEnd && TXT(lineEnd) != '\n')
        lineEnd++;
    int32_t loc2 = locateChar(lineEnd, caretPos, r1, c1);
    int r2 = ROW(loc2);
    int p = textEnd+n;
    if (p >= textBufferSize) enlargeTextBuffer();
// In my terminal I will only ever be inserting within a "single line", and
// even though that may consist of several rows it is liable to be only
// a modest distance from the end of my text buffer. And in many cases the
// user will be typing in characters right at the very end. Thus the loop
// here copying characters to make space for the newly inserted one is liable
// to be much less of a performance bottleneck than it could become if I
// permitted inserts towards the start of a lengthy document.
    while (p != caretPos)
    {   textBuffer[p] = textBuffer[p-n];
        p--;
    }
    for (int i=0; i<n; i++) textBuffer[caretPos+i] = pch[i];
// After inserting the character I look to find where the end of the
// line that it is on has moved to.
    int32_t loc3 = locateChar(lineEnd+n, caretPos, r1, c1);
    int r3 = ROW(loc3), c3 = COL(loc3);;
    caretPos += n;
    textEnd += n;
    if (r3 > virtualRowCount)
    {   virtualRowCount = r3;
        SetVirtualSize(wxDefaultCoord, rowHeight*(virtualRowCount+1));
    }
    if (caret != NULL && caret->IsVisible()) repositionCaret();
// When I end up with coordinated I need them to reflect scrolling.
    int x = 0, y = 0;
    CalcScrolledPosition(0, r1*rowHeight, &x, &y);
// Now I certainly need to refresh from loc1 to loc3, but if
// ROW(loc2) != ROW(loc3) then my insert caused a change in the number of
// rows to be displayed so I should refresh all the way down to the bottom
// of the screen.
    if (r1 == r3)             // everything is on one line
    {   RefreshRect(wxRect(columnPos[c1], y,
                           columnPos[c3], rowHeight));
    }
    else if (r2 == r3)        // several rows involved, but row count unchanged
    {   RefreshRect(wxRect(columnPos[c1], y,
                           columnPos[80], rowHeight));
// Here I will refresh the first row from caretPos up until its end,
// and the whole of all other rows that might be involved.
        RefreshRect(wxRect(columnPos[0], y+rowHeight,
                           columnPos[80], (r2-r1)*rowHeight));
    }
    else                             // lower bits of screen must scroll
    {   RefreshRect(wxRect(columnPos[c1], y,
                           columnPos[80], rowHeight));
// In inserting this character inserted a newline or caused extra wrapping
// I will refresh all the way down to the bottom of the screen.
        if (windowHeight > y+rowHeight)
            RefreshRect(wxRect(columnPos[0], y+rowHeight,
                               columnPos[80], windowHeight-y-rowHeight));
    }
}

void fwinText::replaceChars(uint32_t *pch, int n)
{
}

void fwinText::deleteChars(int n)
{
    int32_t loc1 = locateChar(caretPos);
    int r1 = ROW(loc1), c1 = COL(loc1);
    int eol = caretPos+n;
// Find the line-end just beyond all the deleted characters.
// to the end of the line that the caret is on fall.
    while (eol < textEnd && TXT(eol) != '\n') eol++;
    int32_t loc2 = locateChar(eol, caretPos, r1, c1);
    int r2 = ROW(loc2), c2 = COL(loc2);
    int w = caretPos;
    while (w <= textEnd-n)
    {   textBuffer[w] = textBuffer[w+n];
        w++;
    }
    textEnd -= n;
    eol -= n;
    int32_t loc3 = locateChar(eol, caretPos, r1, c1);
    int r3 = ROW(loc3);
// Apply scroll adjustment. Since I never scroll horizontally the x coordinate
// is not an issue.
    int x = 0, y = 0;
    CalcScrolledPosition(0, rowHeight*r1, &x, &y);
// If r2==r3 then the total number of rows in the display has not changed and
// so I just need to refresh from r1 to r2. If in that case r1=r2 I can do
// a refresh of just the end of the line that changed.
// Otherwise it has changed and I must refresh down to the bottom on the
// screen.
// This can still refresh a larger region than is necessary. Two examples:
// (a) Suppose the text is a long string of identical characters - then
//     when a few are deleted the data that moves into the vacated space does
//     not in fact alter anything.
// (b) If you have say 4 characters then a tab, and delete two of those
//     four characters then everythikng beyond the tab remains in the position
//     it started in.
    if (r2 == r3 && r1 == r2)
    {   RefreshRect(wxRect(columnPos[c1], y,
                           columnPos[c2]-columnPos[c1], rowHeight));
    }
    else if (r2 == r3)
    {   RefreshRect(wxRect(columnPos[c1], y,
                           columnPos[80]-columnPos[c1], rowHeight));
        RefreshRect(wxRect(columnPos[0], y+rowHeight,
                           columnPos[80], (r2-r1)*rowHeight));
    }
    else if (windowHeight > y)
    {   RefreshRect(wxRect(columnPos[0], y,
                           columnPos[80], windowHeight-y));
    }
}


void fwinText::makePositionVisible(int p)
{
    int32_t loc = locateChar(p);
    int r = ROW(loc);
    int x, y;
    CalcScrolledPosition(0, r*rowHeight, &x, &y);
    if (y >= 0 && y <= windowHeight-rowHeight) return;
// Getting this right took more careful thought about counting lines vs.
// counting the gaps between lines and worrying about counts that start at
// zero rather than 1 than I had at first expected!
    int n = r + 1 - rowCount;
    if (n < 0) n = 0;
    FWIN_LOG(("Scroll to offset %d r=%d rowCount=%d\n", n, r, rowCount));
    Scroll(0, n);
}


void fwinText::setCaretPos(int n)
{

#ifdef RECONSTRUCTED
#endif
}


void fwinText::unicodeInput()
{
// This will take the text just in front of the caret and if it is a
// string of up to 4 hex digits or if it is the name that I have set up
// for a special character (and e.g. I will will set up name such as
// "alpha" for the first Greek letter, and TeX-like names for many
// mathematical symbols) I will treat the data as describing a single
// Unicode character. If the symbol ahead of the caret has a name in this
// manner I will expand it to the name. Otherwise it it is outside the
// range 0x20 to 0x7e but is at most 0xffff I will convert it to a string
// of 4 hex digits. In the unusual case that it is a Unicode character
// whose code is 0x10000 or higher I will expand it to 6 hex digits. Things
// are in fact more complicated than that, and the file termed.c has
// the implementation and a rather fuller commentary. It also comtains the
// table of character names that are recognised - it is set of entity
// names from HTML.
    wchar_t buffer[64];
    uint32_t replacement[16];
    if (caretPos == 0)
    {   beep();
        return;
    }
    int j, k = 0;
    int n = caretPos - 1;
// I want to re-use the code in termed.c, but it works on the basis of
// a buffer holding wchar_t stuff. So I translate into that format,
// call the code and translate back.
// So first find the position that is on the same line and as the caret
// but is up to 10 chars before it.
    while (n >= 0 &&
           k < 10 &&
           TXT(n) != '\n' &&
           (textBuffer[n] & 0x03000000) == 0x01000000) k++, n--;
    n++;
    insert_point = 0;
// Translate the stuff so identified into wchar_t form. For now I am just
// going to ignore the Windows mess of surrogates and pretend that I am
// only interested in the basic code page. I may need to review that
// later on.
    k = n;
    while (k < caretPos)
        buffer[insert_point++]= textBuffer[k++] & 0xffff;
    buffer[insert_point] = 0;
    input_line = &buffer[0];
    prompt_length = 0;
// Do the hard work.
    term_unicode_convert();
// Now map the adjusted characters back into 32-bit unicode, adding back the
// 0x01000000 bit that indicates colour.
    j = k = 0;
    while (buffer[k] != 0)
    {   int c = buffer[k];
        replacement[j++] = 0x01000000 | (c & 0x001fffff);
        k++;
    }
// Here I do a delete and then an insert - that is perhaps clumsier than
// if I could do a since combined "replace" operation.
    deleteBackwards(caretPos - n);
    insertChars(replacement, j);
}


void fwinText::ctrlXcommand()
{
    uniname *p = unicode_names;
    int i = 0;
    const char *s;
    insertString("\n");
    uint32_t buffer[100];
    while ((s = p->name) != NULL)
    {   int j = 0;
        char h[8];
//        if (CMTT_AVAIL(p->code))
//        {   p++;
//            continue;
//        }
        while (*s != 0) buffer[i++] = *s++, j++;
        while (j < 8) buffer[i++] = ' ', j++;
        buffer[i++] = p->code | 0x01000000;
        buffer[i++] = ' ';
        sprintf(h, "%.4x", p->code);
        buffer[i++] = h[0];
        buffer[i++] = h[1];
        buffer[i++] = h[2];
        buffer[i++] = h[3];
        buffer[i++] = '\t';
        // 16 positions per symbol
        if (i >= 68)
        {   buffer[i++] = '\n';
            insertChars(buffer, i);
            i = 0;
        }
        p++;
    }
    if (i != 0)
    {   buffer[i++] = '\n';
        insertChars(buffer, i);
    }
    makePositionVisible(textEnd);
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
    FWIN_LOG(("Use Windows Beep\n"));
    ::Beep(900, 60);
#else
    FWIN_LOG(("Play wxBell\n"));
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

void fwinFrame::CloseAction()
{
// I will ask the worker thread (most politely!) to terminate. It might
// at present be waiting on a semaphore, so I Post() to all the possibilities,
// having set a flag that will be polled after any Wait().
    bool closedDown = false;
    shouldExit = true;
    panel->reading.Post();
    panel->writing.Post();
    FWIN_LOG(("Have just set shouldExit and done some Posts\n"));
    wxMilliSleep(1); // give worker a chance to respond.
// The worker might not close down utterly instantly, and it might have
// been in the middle of a computation, so I set more flags that ask it
// to close down. It SEEMS that the call to Delete() here will not
// actually return to me until it has been processed.
    {   wxCriticalSectionLocker lock(panel->work);
        if (panel->frame->worker != NULL)
        {   FWIN_LOG(("About to ask the worker to stop\n"));
            FWIN_LOG(("%p %p %p\n", panel, panel->frame, panel->frame->worker));
            panel->frame->worker->Delete();
            FWIN_LOG(("Delete() called on worker\n"));
        }
        else
        {   closedDown = true;
            FWIN_LOG(("worker already terminated\n"));
        }
    }
// I will then give it 100ms to do so. Within that time it will need to
// call TestDestroy() in order to notice my request.
    if (!closedDown) for (int i=0; i<10; i++)
    {   FWIN_LOG(("Poll %d for worker finished\n", i));
        {   wxCriticalSectionLocker lock(panel->work);
            if (panel->frame->worker == NULL)
            {   closedDown = true;
                break;
            }
        }
        wxMilliSleep(10);
    }
// If it is still alive after that (rather brief) chance to clean up
// tidily I will apply extreme prejudice and dispose of the worker
// forcibly.
    if (!closedDown)
    {   FWIN_LOG(("worker did not close down by itself\n"));
        wxCriticalSectionLocker lock(panel->work);
// the wxWidgets documentation suggests that Kill is a BAD thing to
// do. It will not let any onexit() functions registered by the worker
// happen and it does not clean up memory. However when I do it here I am
// just about to exit from my entire application, so I think I do not mind
// very much. But using Delete() first might be kind...
        if (panel->frame->worker != NULL)
        {   FWIN_LOG(("About to kill the worker\n"));
            panel->frame->worker->Kill();
        }
        else FWIN_LOG(("worker had closed down nicely after all\n"));
    }
// Now I can close myself down too.
    Destroy();
    exit(0);
}

void fwinFrame::OnClose(wxCloseEvent &event)
{
    CloseAction();
}

void fwinFrame::OnExit(wxCommandEvent &event)
{
    CloseAction();
}

void fwinFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(
       wxString::Format(
           "wxfwin (A C Norman 2010-11)\n"
           "wxWidgets version: %s\n"
           "Operating system: %s",
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxfwin",
       wxOK | wxICON_INFORMATION,
       this);
}


void fwinFrame::OnSize(wxSizeEvent &event)
{
    int i;
    double w;
    FWIN_LOG(("OnSize\n"));
    if (panel == NULL) return; // too early!
    wxSize client(GetClientSize());
    w = ((double)(client.GetWidth() - panel->sbWidth))/80.0;
    panel->SetSize(client);
    panel->firstPaint = true;
    for (i=0; i<81; i++)
        panel->columnPos[i] = (int)((double)i*w);
// When I resize the window I will refresh EVERYTHING, because the font
// size may change.
    panel->Refresh();
}

void fwinText::enlargeTextBuffer()
{
    textBufferSize *= 2;
    textBuffer =
        (uint32_t *)realloc(textBuffer, textBufferSize*sizeof(uint32_t));
    if (textBuffer == NULL) exit(1); // Abrupt collapse on no memory.
}

// Now I have handlers for the menu items used here...

void fwinText::OnFileRead()
{
    FWIN_LOG(("READ\n"));
}

void fwinText::OnFileSave()
{
    FWIN_LOG(("SAVE\n"));
}

void fwinText::OnFileSaveSelection()
{
    FWIN_LOG(("SAVE SELECTION\n"));
}

void fwinText::OnFilePageSetup()
{
    FWIN_LOG(("PAGESETUP\n"));
// The wxWidgets "printing" sample shows how to arrange these calls.
    *pageSetupData = *printData;
    wxPageSetupDialog pageSetupDialog(this, pageSetupData);
    pageSetupDialog.ShowModal();
    *pageSetupData = pageSetupDialog.GetPageSetupDialogData();
    *printData = pageSetupData->GetPrintData();
}

void fwinText::OnFilePrint()
{
    wxPrintDialogData printDialogData(*printData);
    wxPrinter printer(&printDialogData);
    fwinPrintout printout(this, "wxfwin");
    if (!printer.Print(this, &printout, true))
    {   if (wxPrinter::GetLastError() == wxPRINTER_ERROR)
            wxLogError("Printer error\n");
        else FWIN_LOG(("Printing cancelled"));
    }
    else *printData = printer.GetPrintDialogData().GetPrintData();
}

void fwinText::OnFilePrintPreview()
{
    FWIN_LOG(("PRINT PREVIEW\n"));
    wxPrintDialogData printDialogData(*printData);
    wxPrintPreview *preview =
        new wxPrintPreview(new fwinPrintout(this),
                           new fwinPrintout(this), &printDialogData);
    if (!preview->IsOk())
    {   delete preview;
        FWIN_LOG(("Problem with print preview\n"));
        return;
    }
    wxPreviewFrame *frame =
        new wxPreviewFrame(preview, this, "Print Preview",
                           wxPoint(100, 100), wxSize(600, 650));
    frame->Centre(wxBOTH);
    frame->Initialize();
    frame->Show();
}

// Now the implementation of print support

void fwinPrintout::GetPageInfo(int *minPage, int *maxPage, int *from, int *to)
{
    *minPage = 1;
    *maxPage = 2;
    *from = *minPage;
    *to = *maxPage;
}

bool fwinPrintout::HasPage(int page)
{
    return (page == 1);
}

bool fwinPrintout::OnPrintPage(int page)
{
    FWIN_LOG(("Print page %d\n", page));
    if (!HasPage(page)) return false;
    wxDC *dc = GetDC();
    FitThisSizeToPageMargins(
        wxSize(parent->windowWidth, parent->windowHeight),
        *pageSetupData);
    wxRect fit = GetLogicalPageMarginsRect(*pageSetupData);
    FWIN_LOG(("Print about to OnDraw\n"));
// In the window size had changed recently and I have not yet redrawn it
// the fonts and measurements may be out of date. So here I create a
// clientDC that would let me draw on the screen - but I only use it to
// measure fonts.
    if (parent->firstPaint)
    {   wxClientDC dc1(parent);
        FWIN_LOG(("SetupFonts in print framework\n"));
        parent->SetupFonts(dc1);
    }
// MainDraw always displays the first row it is asked to draw at y=0.
    FWIN_LOG(("MainDraw from OnPrintPage\n"));
    parent->MainDraw(*dc, 0, parent->virtualRowCount);
    dc->SetFont(*(parent->fixedPitch));
    dc->SetTextForeground(*wxBLACK);
    dc->DrawText(wxString::Format("Page %d", page),
                 -parent->rowHeight, -(3*parent->rowHeight)/2);
    return true;
}



// end of print support



void fwinText::OnEditCut()
{
    FWIN_LOG(("CUT\n"));
}

void fwinText::OnEditCopy()
{
    FWIN_LOG(("COPY\n"));
}

void fwinText::OnEditCopyText()
{
    FWIN_LOG(("COPY TEXT\n"));
}

void fwinText::OnEditPaste()
{
    FWIN_LOG(("PASTE\n"));
}

void fwinText::OnEditReinput()
{
    FWIN_LOG(("REINPUT\n"));
}

void fwinText::OnEditSelectAll()
{
    FWIN_LOG(("SELECTALL\n"));
}

void fwinText::OnEditClear()
{
    FWIN_LOG(("CLEAR\n"));
}

void fwinText::OnEditRedraw()
{
    FWIN_LOG(("REDRAW\n"));
}

void fwinText::OnEditHome()
{
    FWIN_LOG(("HOME\n"));
}

void fwinText::OnEditEnd()
{
    FWIN_LOG(("END\n"));
}

void fwinText::OnFontCMTT()
{
    FWIN_LOG(("OnFontCMTT"));
}

void fwinText::OnFontDeja()
{
    FWIN_LOG(("OnFontDeja"));
}

void fwinText::OnFontSazanami()
{
    FWIN_LOG(("OnFontSazanami"));
}

void fwinText::OnFontFirefly()
{
    FWIN_LOG(("OnFontFirefly"));
}

void fwinText::OnFontPoint10()
{
    FWIN_LOG(("OnFontPoint10"));
}

void fwinText::OnFontPoint12()
{
    FWIN_LOG(("OnFontPoint12"));
}

void fwinText::OnFontPoint14()
{
    FWIN_LOG(("OnFontPoint14"));
}

void fwinText::OnFontPoint17()
{
    FWIN_LOG(("OnFontPoint17"));
}

void fwinText::OnFontPoint20()
{
    FWIN_LOG(("OnFontPoint20"));
}

void fwinText::OnFontPoint24()
{
    FWIN_LOG(("OnFontPoint24"));
}

void fwinText::OnFontPoint28()
{
    FWIN_LOG(("OnFontPoint28"));
}

void fwinText::OnFontPoint34()
{
    FWIN_LOG(("OnFontPoint34"));
}

void fwinText::OnFontPoint40()
{
    FWIN_LOG(("OnFontPoint40"));
}



void fwinText::OnBreakBreak()
{
    FWIN_LOG(("BREAK\n"));
}

void fwinText::OnBreakBacktrace()
{
    FWIN_LOG(("BACKTRACE\n"));
}

void fwinText::OnBreakPause()
{
    FWIN_LOG(("PAUSE\n"));
}

void fwinText::OnBreakResume()
{
    FWIN_LOG(("RESUME\n"));
}

void fwinText::OnBreakStopGo()
{
    FWIN_LOG(("STOP_GO\n"));
}

void fwinText::OnBreakDiscardOutput()
{
    FWIN_LOG(("DISCARDOUTPUT\n"));
}

void fwinText::OnHelpHelp()
{
    FWIN_LOG(("HELP\n"));
}


// Hmmm - on the Macintosh I find that the arrow keys and regular keys
// with ALT or CTRL set do not generate an OnChar event, only a KeyDown one.
// Or when they do the purported Unicode value is not hat I want.
// On Windows and Linux I can do everything via OnChar, but here I patch
// things up for "the awkward platform".

void fwinText::OnKeyDown(wxKeyEvent &event)
{
    uint32_t c = event.GetUnicodeKey();
    uint32_t r = event.GetKeyCode();
    uint32_t m = event.GetModifiers();
//-    FWIN_LOG(("SHIFT=%x ALT=%x META=%x CONTROL=%x\n",
//-       wxMOD_SHIFT, wxMOD_ALT, wxMOD_META, wxMOD_CONTROL));
//-    FWIN_LOG(("KeyDown raw:%x unicode:%x modifiers:%x\n", r, c, m));
// I appear to get streams of OnKeyDown(0) messages that do not seem
// helpful to me. So I will just ignore them.
    if (r == 0)
    {   event.Skip();
        return;
    }
// Codes from 1 to 255 should be ordinary plain genuine ASCII (or extended
// ASCII) characters and if they are presented without ALT or CTRL I will
// leave them to be sorted out by OnChar.
    if (r < 256 && (m & (wxMOD_ALT|wxMOD_CMD)) == 0)
    {   event.Skip();
//-        FWIN_LOG(("leave for OnChar since real key with no modifiers\n"));
        return;
    }
// Next I will try to cope with ordinary characters but with ALT or CTRL.
// In the ALT case the Unicode entry is probably already correct, so all I
// need to do is to delegate to OnChar. Well actually I will go direct to
// processChar.
    if (r < 256 && (m & wxMOD_ALT) != 0)
    {
//-        FWIN_LOG(("Char with ALT pressed\n"));
        if (processChar(c, r, m)) event.Skip();
        return;
    }
// If I had a normal key plus CMD I will map the unicode value to just the
// low 5 bits.
    if (r < 256)
    {
//-        FWIN_LOG(("Char with CMD pressed\n"));
        if (processChar(r & 0x1f, r, m)) event.Skip();
        return;
    }
// Now finally I have something where the key pressed seems to be a "special"
// one (eg function key, numeric key-pad, arrow key etc etc.
//-    FWIN_LOG(("make unicode WXK_NONE=%x\n", WXK_NONE));
    if (processChar(WXK_NONE, r, m)) event.Skip();
// because I do nothing special here this has accepted and processed the
// key event and it will not re-appear later on via OnChar.
}

void fwinText::OnChar(wxKeyEvent &event)
{
    uint32_t c = event.GetUnicodeKey();
    uint32_t r = event.GetKeyCode();
    int m = event.GetModifiers(); // wxMOD_ALT, wxMOD_SHIFT, wxMOD_CMD
                                  // Also ALTGR, META, WIN, CONTROL that
                                  // I will not use.
    if (processChar(c, r, m)) event.Skip();
}

bool fwinText::processChar(int c, int r, int m)
{
//-    FWIN_LOG(("process: Raw key:%x Unicode:%x modifiers:%x\n", r, c, m));
    unsigned char *history_string = NULL;
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
    case WXK_HELP:
    case WXK_F1:  case WXK_F2:  case WXK_F3:  case WXK_F4:  case WXK_F5:
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
            return true;

    case WXK_DELETE:
    case WXK_NUMPAD_DELETE:
            c = WXK_DELETE;
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
//  FWIN_LOG(("Character %#x modifiers %x\n", c, m));
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
                return false;
            }
            searchFlags--;
            if (SEARCH_LENGTH == 0)
            {   searchFlags = 0;   // delete the one char in the search string
                killSelection();
                setInputText((const unsigned char *)"");
                return false;
            }
            historyNumber = searchStack[SEARCH_LENGTH];
// The "trySearch" here really really ought to succeed since I have reverted
// to a history line where it succeeded before. I do it again here so I can
// find out where, on that line, the match was so I can establish it as a
// selection.
            startMatch = trySearch();
            history_string = historyGet(historyNumber);
// ought not to return NULL here!
            ls = setInputText(history_string);
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return false;
// ALT-P and ALT-p and UP all search backwards
    case 'P': case 'p':
            if (!(m & wxMOD_ALT)) goto defaultlabelsearch;
    case WXK_UP|NON_UNICODE:
            searchFlags &= ~SEARCH_FORWARD;
            searchFlags |= SEARCH_BACKWARD;
            if (historyNumber <= historyFirst)
            {   beep();  // already on last possible place
                return false;
            }
            save = historyNumber;
            historyNumber--;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                beep();
                return false;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string);
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return false;
// ALT-N and ALT-n and DOWN all search forwards
    case 'N': case 'n':
            if (!(m & wxMOD_ALT)) goto defaultlabelsearch;
    case WXK_DOWN|NON_UNICODE:
            searchFlags |= SEARCH_FORWARD;
            searchFlags &= ~SEARCH_BACKWARD;
            if (historyNumber >= historyLast)
            {   beep();
                return false;
            }
            save = historyNumber;
            historyNumber++;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                beep();
                return false;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string);
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return false;
// I detect ^U here and cause it to exit search mode.
    case ('U' & 0x15):
            searchFlags = 0;
            killSelection();
            return false;
    case WXK_ESCAPE:       // ctl-[
            keyFlags ^= ESC_PENDING;
            return false;
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
                return false;
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
                return false;
            }
            startMatch = r;
            history_string = historyGet(historyNumber);
            ls = setInputText(history_string);
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection();
#ifdef RECONSTRUCTED
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCaretPos(ls+startMatch+SEARCH_LENGTH, TRUE);
#endif
            return false;
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
        return false;
    }
// If the very first key I see is "^G" I will raise an exception
// for the user.
    if (c == ('C' & 0x1f) &&
        !(keyFlags & ANY_KEYS))
    {   displayBacktrace();
        return false;
    }
    keyFlags |= ANY_KEYS;
    switch (c)
    {
case WXK_BACK:  // = Ctrl-H
// ALT backspace does a delete-backwards-word, while just backspace
// deletes a single character. I find that CTRL-backspace (at least on
// on Windows) is mapped to ctrl-DELETE so that will delete forwards.
        if ((m & wxMOD_ALT) != 0) deleteWordBackwards();
        else deleteBackwards(1);
        return false;
case WXK_END|NON_UNICODE:
// Hmmm - still should I extend a selection if an anchor is set?
// END should probably go to the end of the current line, with ALT-END
// going to the end of the last line.
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveDocEnd();
        else moveLineEnd();
        return false;
case WXK_HOME|NON_UNICODE:
// HOME should probably go to the start of the current active line, with
// ALT-HOME being the thing that goes to top of the screen-buffer.
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveDocStart();
        else moveLineStart();
        return false;
case WXK_LEFT|NON_UNICODE:
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveWordLeft();
        else moveLeft();
        return false;
case WXK_RIGHT|NON_UNICODE:
        if ((m & (wxMOD_CMD|wxMOD_ALT)) != 0) moveWordRight();
        else moveRight();
        return false;
case WXK_UP|NON_UNICODE:
// UP      go to previous item in history
// ALT-UP  search backwards in history
// CTRL-UP or action in read-only region: merely move up a line
        if ((m & wxMOD_CMD) || (options & READONLY)) moveUp();
        else if (m & wxMOD_ALT) searchHistoryPrev();
        else historyPrev();
        return false;
case WXK_DOWN|NON_UNICODE:
// If you are not waiting for input then cursor up and down just move you up
// and down! If you are waiting for input then Control can be used to break
// you out from the input-line...
        if ((m & wxMOD_CMD) || (options & READONLY)) moveDown();
        else if (m & wxMOD_ALT) searchHistoryNext();
        else historyNext();
        return false;
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
// As a default sort of behaviour I somehow need to resolve what happens in
// case CTRL and ALT are both pressed.
        if (m & wxMOD_ALT)
        {   setSelectionMark();
            return false;
        }
        else goto defaultlabel;
case '@' & 0x1f:
        setSelectionMark();
        return false;
case 'A': case 'a':
        if (m & wxMOD_ALT)
        {   moveLineStart();
            return false;
        }
        else goto defaultlabel;
case 'A' & 0x1f:
        if (m & wxMOD_ALT)
        {   moveLineStart();
            return false;
        }
        moveLineStart();
        return false;
case 'B' & 0x1f:
        if (m & wxMOD_ALT)
        {   moveWordLeft();
            return false;
        }
        moveLeft();
        return false;
case 'B': case 'b':
        if (m & wxMOD_ALT)
        {   moveWordLeft();
            return false;
        }
        else goto defaultlabel;
case 'C' & 0x1f:
        if (m & wxMOD_ALT)
        {   capitalize();
            return false;
        }
        interrupt();
        return false;
case 'C': case 'c':
        if (m & wxMOD_ALT)
        {   capitalize();
            return false;
        }
        goto defaultlabel;
case WXK_DELETE:
// On Windows (at least) I find that Ctrl-backspace gets returned
// as Ctrl-DELETE and I want it to delete a single character not a word.
// I think. Hence I let Ctrl-DEL delete a character, while ALT-DEL deletes
// a word.
        if (m & wxMOD_ALT) deleteWordForwards();
        else deleteForwards(1);
        return false;
case 'D' & 0x1f:
        if (m & wxMOD_ALT)
        {   deleteWordForwards();
            return false;
        }
// Here I may want to arrange that if the current input-buffer is empty
// then ^D causes and EOF to be returned. Well yes, I have arranged that
// elsewhere so I only get here if the user has typed some chars already.
        goto defaultlabel;
case 'D': case 'd':
        if (m & wxMOD_ALT)
        {   deleteWordForwards();
            return false;
        }
        goto defaultlabel;
case 'E' & 0x1f:
        if (m & wxMOD_ALT) return 1;
        moveLineEnd();
        return false;
case 'E': case 'e':
// ALT-e enters the EDIT menu: this is handled by having the menu
// registered elsewhere.
        if (m & wxMOD_ALT) return 1;
        goto defaultlabel;
case 'F' & 0x1f:
        if (m & wxMOD_ALT)
        {   moveWordRight();
            return false;
        }
        moveRight();
        return false;
case 'F': case 'f':
        if (m & wxMOD_ALT)
        {   moveWordRight();
            return false;
        }
        goto defaultlabel;
case 'G' & 0x1f:
        if (m & wxMOD_ALT) return true;
        displayBacktrace();
        return false;
case 'G': case 'g':
// ALT-G will be for "Load Packa&ge"
        if (m & wxMOD_ALT) return true;
        goto defaultlabel;
// case 'H' & 0x1f: // = WXK_BACK
case 'H': case 'h':
        if (m & wxMOD_ALT)
        {   deleteWordBackwards();
            return false;
        }
        goto defaultlabel;
// case 'I' & 0x1f: // == WXK_TAB
case 'I': case 'i':
// ALT-i enters the FILE menu
        if (m & wxMOD_ALT) return true;
        goto defaultlabel;
case 'J' & 0x1f:
        if (m & wxMOD_ALT)  // Could ALT-J be for something more interesting?
        {   insertNewline();
            return false;
        }
         c = '\n';
         goto defaultlabel;
case 'J': case 'j':
        if (m & wxMOD_ALT)  // Could ALT-J be for something more interesting?
        {   insertNewline();
            return false;
        }
        goto defaultlabel;
case 'K' & 0x1f:
        deleteCurrentLine();
        return false;
case 'K': case 'k':
        if (m & wxMOD_ALT)
        {   deleteCurrentLine();
            return false;
        }
        goto defaultlabel;
// ^L will be a shortcut for clear-screen
case 'L': case 'l':
        if (m & wxMOD_ALT)
        {   lowerCase();
            return false;
        }
        goto defaultlabel;
// case 'M' & 0x1f: // = WXK_RETURN
case 'M': case 'm':
// ALT-m enters the MODULE menu
        goto defaultlabel;
case 'N' & 0x1f:
        if (options & READONLY) moveDown();
        if (m & wxMOD_ALT)
        {   searchHistoryNext();
            return false;
        }
        else historyNext();
        return false;
case 'N': case 'n':
        if (options & READONLY) goto defaultlabel;
        else if (m & wxMOD_ALT)
        {   searchHistoryNext();
            return false;
        }
        goto defaultlabel;
// case 'O' & 0x1f: // menu shortcut to lose output
case 'O': case 'o':
// ^O will be purge output.
//    I hope that by making ^O, ^S and ^Q menu shortcuts they will get
//    acted upon whether I am waiting for input or not.
// ALT-O enters the FONT menu
        if (m & wxMOD_ALT) return 1;
        goto defaultlabel;
case 'P' & 0x1f:
        if (options & READONLY) moveUp();
        if (m & wxMOD_ALT)
        {   searchHistoryPrev();
            return false;
        }
        else historyPrev();
        return false;
case 'P': case 'p':
        if (options & READONLY) goto defaultlabel;
        else if (m & wxMOD_ALT)
        {   searchHistoryPrev();
            return false;
        }
        goto defaultlabel;
case 'Q': case 'q':
// ^Q will be RESUME OUTPUT
        if (m & wxMOD_ALT) return true; // Ignore ALT-Q
        goto defaultlabel;
case 'R' & 0x1f:
        if (m & wxMOD_ALT) return 1;
        Refresh();
        return false;
case 'R': case 'r':
// ALT-r will be the B&reak menu
        if (m & wxMOD_ALT) return 1;
        goto defaultlabel;
// case 'S' & 0x1f: // menu shortcut
case 'S': case 's':
// ^S should pause output
// ALT-s enters the SWITCH menu
        if (m & wxMOD_ALT) return 1;
        goto defaultlabel;
case 'T' & 0x1f:
        transpose();
        return false;
case 'T': case 't':
        if (m & wxMOD_ALT)
        {   transpose();
            return false;
        }
        goto defaultlabel;
case 'U' & 0x1f:
        if (m & wxMOD_ALT)
        {   upperCase();
            return false;
        }
        undo();
        return false;
case 'U': case 'u':
        if (m & wxMOD_ALT)
        {   upperCase();
            return false;
        }
        goto defaultlabel;
case 'V': case 'v':
// ^V will be PASTE and is handled as a shortcut
        goto defaultlabel;
case 'W' & 0x1f:
// ^W behaviour is just like ALT-H
        if (m & wxMOD_ALT)
        {   copyRegion();
            return false;
        }
        deleteWordBackwards();
        return false;
case 'W': case 'w':
        if (m & wxMOD_ALT)
        {   copyRegion();
            return false;
        }
        goto defaultlabel;
case 'X' & 0x1f:
        if (m & wxMOD_ALT)    // if CTRL and ALT both in use ALT wins here
        {   unicodeInput();   // Unicode conversion
            return false;
        }
        ctrlXcommand();
        return false;
case 'X': case 'x':
        if (m & wxMOD_ALT)
        {   unicodeInput();   // Unicode conversion
            return false;
        }
        goto defaultlabel;
case 'Y' & 0x1f:
// ^Y is short for YANK, otherwise known as PASTE
        if (m & wxMOD_ALT)
        {   rotateClipboard();
            return false;
        }
        paste();
        return false;
case 'Y': case 'y':
        if (m & wxMOD_ALT)
        {   rotateClipboard();
            return false;
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
        escapePressed();
        return false;
case '\\' & 0x1f:
        frame->CloseAction();
        return false;
case '\\':
        goto defaultlabel;
case ']':
        goto defaultlabel;
case '^' & 0x1f:
        reinput();
        return false;
case '^':
        goto defaultlabel;
case '_':
        if (m & wxMOD_ALT)
        {   copyWordPrev();
            return false;
        }
        goto defaultlabel;
case '/': case '?':
        if (m & wxMOD_ALT) return true;
        goto defaultlabel;

default:
defaultlabel:


        if (awaiting)
        {   if (c == '\n')
            {   insertNewline();
                return false;
            }
            insertChar(c | 0x01000000);
            return false;
        }
        beep();
        return false;

#ifdef RECONSTRUCTED
        insertChar(c); // @@@@
        if (c == 'X' && frame->worker != NULL)
        {   FWIN_LOG(("X test case\n"));
            frame->worker->sendToScreen("Hi there @\n"); // @@@@
        }
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
#endif // RECONSTRUCTED
    }


#ifdef RECONSTRUCTED

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


#endif // RECONSTRUCTED

    return false;
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

void fwinText::historyAdd(unsigned char *s, int n)
{
/* Make a copy of the input string... */
    size_t size = sizeof(char)*(n + 1);
    unsigned char *scopy = (unsigned char *)malloc(size);
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

unsigned char *fwinText::historyGet(int n)
{
    static unsigned char nullString[] = {0};
    unsigned char *s;
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
    FWIN_LOG(("Mouse event\n"));
    event.Skip();
}

void fwinText::OnSetFocus(wxFocusEvent &event)
{
    if (caret!=NULL) repositionCaret();
}

void fwinText::repositionCaret(int w, int r, int c)
{
    int32_t caretCell = locateChar(caretPos, w, r, c);
    if (caretCell < 0) while (caret->IsVisible()) caret->Hide();
    else
    {   int r = ROW(caretCell), c = COL(caretCell);
        int x = columnPos[c], y = rowHeight*r;
        if (c == 80) x -= 2;
        CalcScrolledPosition(x, y, &x, &y);
        caret->Move(x, y);
        while (!caret->IsVisible()) caret->Show();
    }
}

void fwinText::OnKillFocus(wxFocusEvent &event)
{
    if (caret != NULL)
        while (caret->IsVisible()) caret->Hide();
}

// sendToScreen will in general NOT be used - instead I will put
// material in fwin_buffer and then call ensure_screen().

void fwinWorker::sendToScreen(wxString s)
{
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, TO_SCREEN);
    event->SetString(s.c_str());  // careful to copy the string
    wxQueueEvent(panel, event);
    FWIN_LOG(("sendToScreen \"%s\"\n", (const char *)s.c_str()));
}

void fwinText::OnToScreen(wxThreadEvent& event)
{
    wxString text = event.GetString();
    FWIN_LOG(("receive in OnToScreen \"%s\"\n", (const char *)text.ToAscii()));
    insertString(text);
}

int fwinText::unpackUTF8chars(uint32_t *u, const char *s, int ends)
{
    int k = 0;
    int n = 0, state = 0;
    uint32_t uc;    // Unicode char that is being reconstructed.
    while (k != ends)
    {   uint32_t c = s[k] & 0xff;
        k++;
        switch (state)
        {
    case 3: if ((c & 0xc0) != 0x80) FWIN_LOG(("Malformed UTF-8 sequence\n"));
            uc |= ((c & 0x3f) << 12);
            state = 2;
            break;
    case 2: if ((c & 0xc0) != 0x80) FWIN_LOG(("Malformed UTF-8 sequence\n"));
            uc |= ((c & 0x3f) << 6);
            state = 1;
            break;
    case 1: if ((c & 0xc0) != 0x80) FWIN_LOG(("Malformed UTF-8 sequence\n"));
            uc |= (c & 0x3f);
            u[n++] = uc;
            uc = 0;
            state = 0;
            break;
    case 0: if ((c & 0x80) == 0) u[n++] = c;
            else if ((c & 0xe0) == 0xc0)
            {   uc = (c & 0x1f) << 6;
                state = 1;
            }
            else if ((c & 0xf0) == 0xe0)
            {   uc = (c & 0x0f) << 12;
                state = 2;
            }
            else if ((c & 0xf8) == 0xf0)
            {   uc = (c & 0x07) << 18;
                state = 3;
            }
            else FWIN_LOG(("Malformed UTF-8 sequence\n"));
            break;
        }
    }
    return n;
}

void fwinText::OnSetPrompt(wxThreadEvent& event)
{
    wxString text = event.GetString();
    FWIN_LOG(("OnSetPrompt %s\n", fwin_prompt_string));
    unicodePromptLength = unpackUTF8chars(&unicodePrompt[0],
                                          &fwin_prompt_string[0],
                                          strlen(fwin_prompt_string));
    for (int i=0; i<unicodePromptLength; i++)
        unicodePrompt[i] |= 0x02000000;   // force prompt into BLUE
    writing.Post();
}

void fwinText::OnSetMenus(wxThreadEvent& event)
{
    FWIN_LOG(("OnSetMenus\n"));
    writing.Post();
}

void fwinText::OnRefreshSwitches(wxThreadEvent& event)
{
    FWIN_LOG(("OnRefreshSwitches\n"));
    writing.Post();
}


void fwinText::OnSetLeft(wxThreadEvent& event)
{
    wxString text = event.GetString();
    FWIN_LOG(("OnSetLeft %s\n", (const char *)text.ToAscii()));
    writing.Post();
}

void fwinText::OnSetMid(wxThreadEvent& event)
{
    wxString text = event.GetString();
    FWIN_LOG(("OnSetMid %s\n", (const char *)text.ToAscii()));
    writing.Post();
}

void fwinText::OnSetRight(wxThreadEvent& event)
{
    wxString text = event.GetString();
    FWIN_LOG(("OnSetRight %s\n", (const char *)text.ToAscii()));
    writing.Post();
}

void fwinText::OnFlushBuffer1(wxThreadEvent& event)
{
    OnFlushBuffer(&fwin_buffer1[0]);
}

void fwinText::OnFlushBuffer2(wxThreadEvent& event)
{
    OnFlushBuffer(&fwin_buffer2[0]);
}

void fwinText::OnFlushBuffer(const char *fwin_buffer)
{
    recently_flushed = 0;
    uint32_t wideBuffer[FWIN_BUFFER_SIZE];
    int n = unpackUTF8chars(&wideBuffer[0], fwin_buffer, fwin_out);
    insertChars(&wideBuffer[0], n);
    int p = textEnd;
    while (p > 0 && textBuffer[--p] != '\n');
    if (p < textEnd) p++;
    makePositionVisible(p);
// Tell the worker thread that the GUI is now ready to be sent another request.
    writing.Post();
}


void fwinText::OnRequestInput(wxThreadEvent& event)
{
// At this point the worker thread is halted waiting on the "reading"
// semaphore. Just before that the worker thread had called
// fwin_ensure_screen and had delayed until that action had completed, and so
// I know that the screen is in an up to date state and that the worker is
// at present suspended. I first display the prompt. Then if there are
// any type-ahead characters I process them one at a time putting them
// into inputBuffer. If I reach an ENTER I will have done and can signal
// the worker thread. If even after processing any type-ahead material I only
// have a part-line in inputBuffer I will set a flag (awaiting) which will
// cause OnChar to put anything it receives into inputBuffer not the
// type-ahead buffer. When OnChar sees an ENTER it can clear the awaiting
// flag and signal the worker thread.
    FWIN_LOG(("OnRequestInput\n"));
    caretPos = textEnd;
    insertChars(unicodePrompt, unicodePromptLength);
    promptEnd = textEnd;
    makePositionVisible(caretPos);
    writing.Post();

    awaiting = 1;
    return;  // no type-ahead for now. If I had type-ahead I would
             // unload from the type-ahead buffer here and if I got as far
             // as a newline do a reading.Post();

}


void fwinText::OnMinimiseWindow(wxThreadEvent& event)
{
    FWIN_LOG(("OnMinimiseWindow\n"));
    Hide();
    writing.Post();
}

void fwinText::OnRestoreWindow(wxThreadEvent& event)
{
    FWIN_LOG(("OnRestoreWindow\n"));
    Show();
    writing.Post();
}

void fwinText::SetupFonts(wxDC &dc)
{
    FWIN_LOG(("SetupFonts called, fixedPitch = %p\n", fixedPitch));
    wxSize window(GetClientSize());
    windowWidth = window.GetWidth();
    windowHeight = window.GetHeight();
    if (fixedPitch == NULL)
    {   fixedPitch = new wxFont();
        fixedAlternate = new wxFont();
        fixedCJK   = new wxFont();
// It worries me that exactly the same OpenType font needs to be
// called for using slighly different names on different platforms.
#ifdef MACINTOSH
        fixedPitch->SetFaceName("CMU Typewriter Text Regular");
#else
        fixedPitch->SetFaceName("CMU Typewriter Text");
#endif
        fixedAlternate->SetFaceName("DejaVu Sans Mono");
        fixedCJK->SetFaceName(cjkFontName);
        fixedPitch->SetPointSize(1000);
        fixedAlternate->SetPointSize(1000);
        fixedCJK->SetPointSize(1000);
        font_width *p = cm_font_width;
        while (p->name != NULL &&
               strcmp(p->name, "cmtt10") != 0) p++;
        if (p->name == NULL)
        {   FWIN_LOG(("Oops - font data not found\n"));
            exit(1);
        }
        wxCoord width, height, depth, leading;
        dc.GetTextExtent("M", &width, &height, &depth, &leading, fixedPitch);
        FWIN_LOG(("width=%d height=%d depth=%d leading=%d\n", width, height, depth, leading));
        em = (double)width/100.0;
        double fmEm = (double)p->charwidth[(int)'M']*10.0/1048576.0;
        pixelsPerPoint = em/fmEm;
        fixedPitch->SetPointSize(10);
        dc.GetTextExtent((wchar_t)0x21d0, &width, &height, &depth, &leading, fixedAlternate);
        FWIN_LOG(("Alternate width=%d height=%d depth=%d leading=%d\n", width, height, depth, leading));
        dc.GetTextExtent((wchar_t)0x4e00, &width, &height, &depth, &leading, fixedCJK);
        FWIN_LOG(("CJK width=%d height=%d depth=%d leading=%d\n", width, height, depth, leading));
    }
    int spacePerChar = windowWidth/80;
    scaleAdjustment = (double)spacePerChar/em;
    FWIN_LOG(("windowWidth = %d scaleAdjustment = %.3g\n", windowWidth, scaleAdjustment));
    fixedPitch->SetPointSize(10);
    fixedPitch->Scale(scaleAdjustment);
    fixedAlternate->SetPointSize(10);
    fixedAlternate->Scale(scaleAdjustment);
    fixedCJK->SetPointSize(10);
    fixedCJK->Scale(scaleAdjustment);
    dc.SetFont(*fixedPitch);
    rowHeight = dc.GetCharHeight();
    FWIN_LOG(("Setting rowHeight = %d\n", rowHeight));
    spacePerChar = dc.GetCharWidth();
// rowCount is the number of full rows that will fit on the screen. If the
// window depth is not a multiple of rowHeight there could be a further
// part-row.
    rowCount = windowHeight/rowHeight - 1;

#if 0
// Now I need to re-size any fonts that have already been created
    for (int i=0; i<MAX_FONTS; i++)
    {   wxFont *ff = font[i];
        if (ff == NULL) continue;
        ff->SetPointSize(fontWidth[i]->designsize/1048576);
        ff->Scale(scaleAdjustment*fontScale[i]);
    }
#endif
// Create or re-size the caret, and position it where it needs to be on the
// screen. It seems a little odd to do these steps if I happen to invoke
// thi sfrom within the prointing framework but I believe it should not hurt.
    SetFocus();
    if (caret == NULL) caret = new wxCaret(this, 2, rowHeight);
    else caret->SetSize(2, rowHeight);
    repositionCaret();
    SetScrollRate(0, rowHeight);
    SetVirtualSize(wxDefaultCoord, rowHeight*(virtualRowCount+1));
    firstPaint = false;
}

void fwinText::MainDraw(wxDC &dc,
                        int firstUpdateRow, int lastUpdateRow)
{
    wxColour c1(GetBackgroundColour());
    wxPen p1(c1), p2(c1);
    dc.SetPen(p1);
    wxBrush b1(c1);
    dc.SetBrush(b1);
    dc.SetBackground(b1);
    dc.SetTextBackground(c1);
    textColour = wxBLACK;
    dc.SetTextForeground(*textColour);
    dc.SetFont(*fixedPitch);
#define FONT_CMTT  0
#define FONT_DEJA  1
#define FONT_CJK   2
    currentFont = FONT_CMTT;
    int p = 0;
    int y = 0;
    int linecount = 0;
    while (p<textEnd && linecount <= lastUpdateRow)
    {   if (linecount < firstUpdateRow) p = SkipTextRow(p);
        else p = DrawTextRow(dc, y, p);
        y += rowHeight;
        linecount++;
    }
}


void fwinText::OnDraw(wxDC &dc)
{
    if (firstPaint)
    {   FWIN_LOG(("SetupFonts fronm OnDraw\n"));
        SetupFonts(dc);
    }
    wxRect updateRegion = GetUpdateRegion().GetBox();
    CalcUnscrolledPosition(updateRegion.x, updateRegion.y,
                           &updateRegion.x, &updateRegion.y);
    int firstUpdateRow = updateRegion.y/rowHeight;
    int lastUpdateRow = updateRegion.GetBottom()/rowHeight;
    FWIN_LOG(("update height = %d rowHeight = %d\n", updateRegion.GetBottom(), rowHeight));
    FWIN_LOG(("Update rows %d to %d\n", firstUpdateRow, lastUpdateRow));
    MainDraw(dc, firstUpdateRow, lastUpdateRow);
}


int fwinText::SkipTextRow(int p)
{
    int col = 0;
    while (p < textEnd)
    {   uint32_t ch = TXT(p++);
        if (ch == '\n') return p;
// a TAB can take you exactly up to column 80 but never over it. But a wide
// character in column 79 could trigger a wrap.
        if (col == 80 ||
            (col == 79 && double_width(ch))) return p-1;
// I convert TAB into a suitable sequence of spaces.
        if (ch == '\t')
        {   col = (col + 8) & ~7 ;
            continue;
        }
        if (double_width(ch)) col += 2;
        else col++;
    }
    return p;
}

int fwinText::DrawTextRow(wxDC &dc, int y, int p)
{
    int col = 0;
    while (p < textEnd)
    {   uint32_t ch = textBuffer[p++];
        uint32_t flags = ch & ~0x001fffff;
        ch &= 0x001fffff;
        if (ch == '\n') return p;
// a TAB can take you exactly up to column 80 but never over it. But a wide
// character in column 79 could trigger a wrap.
        if (col == 80 ||
            (col == 79 && double_width(ch))) return p-1;
        if (flags & 0x01000000)
        {   if (textColour != wxRED)
                dc.SetTextForeground(*(textColour = wxRED));
        }
        else if (flags & 0x02000000)
        {   if (textColour != wxBLUE)
                dc.SetTextForeground(*(textColour = wxBLUE));
        }
        else if (textColour != wxBLACK)
            dc.SetTextForeground(*(textColour = wxBLACK));
        wxString cs;
// There are a few characters that take special action on. I will comment
// by each about what I am doing and why.
        switch (ch)
        {
    case 0x03d2:  // upsih
// Code 0x3d2 is not available in cmutt, but it is in DejaVu. However in
// cmuntt the normal capital Upsilon comes out curly, so I merely map the
// code onto that.
            if (fontPriorityCMTT) ch = 0x03a5;
            break;
    case 0x03a5:  // upsilon
// Well as explained above, the cmuntt capital Upsilon is a curly one, and
// I want a non-curly version here. A capital Y provides the correct shape.
            if (fontPriorityCMTT) ch = 'Y';
            break;
    case 0x2118:  // weierp
// There is no script capital P in any of the fonts I am using at present,
// however a glyph described as "plhook" in the Private/Corporate range
// from cmuntt looks a bit like a curly P and is perhaps better than nothing.
            ch = 0xf189;
            if (currentFont != FONT_CMTT)
            {   dc.SetFont(*fixedPitch);
                currentFont = FONT_CMTT;
            }
            cs = (wchar_t)ch;
            dc.DrawText(cs, columnPos[col], y);
            col++;
            continue;
    case 0x2111:  // image
// This is supposed toi be a Black Letter Capital I. I use a small capital
// which is at least different from a regular "I". But this is not very good.
            ch = 0x026a;
            break;
    case 0x211c:  // real
// A similar problem to "image" above, with a similar fallback
            ch = 0x0280;
            break;
    case 0x2135:  // alefsym
            {   int x = columnPos[col];
                int w = columnPos[col+1]-x, h = rowHeight;
                wxPen p1 = dc.GetPen();
                wxPen p2;
                p2.SetColour(*textColour);
                p2.SetWidth((7*rowHeight+80)/100);
                dc.SetPen(p2);
                dc.DrawLine(x+w/6, y+(2*h)/10,
                            x+w-w/6, y+(8*h)/10);
                dc.DrawLine(x+w/2, y+(2*h)/10,
                            x+w-w/6, y+(5*h)/10);
                dc.DrawLine(x+w/6, y+(8*h)/10,
                            x+w/2, y+(8*h)/10);
                p2.SetWidth((3*rowHeight+50)/100);
                dc.SetPen(p2);
                dc.DrawLine(x+w/2, y+h/2,
                            x+(3*w)/4, y+h/4);
                dc.DrawLine(x+w/3, y+h/3,
                            x+w/2, y+(8*h)/10);
                dc.SetPen(p1);
                col++;
                continue;
            }
    default:
            break;
        }
// I convert TAB into a suitable sequence of spaces.
        if (ch == '\t')
        {   col = (col + 8) & ~7 ;
            continue;
        }
        else if (ch == 0x20)
        {   col++;
            continue;
        }
// I will not even try to display characters whose code is over 0xffff here.
// I will map any such onto a display of a question mark.
        else if (ch > 0xffff) cs = "?";
        else cs = (wchar_t)ch;
        if (fontPriorityCMTT && CMTT_AVAIL(ch))
        {   if (currentFont != FONT_CMTT)
            {   dc.SetFont(*fixedPitch);
                currentFont = FONT_CMTT;
            }
        }
        else if (DEJA_AVAIL(ch))
        {   if (currentFont != FONT_DEJA)
            {   dc.SetFont(*fixedAlternate);
                currentFont = FONT_DEJA;
            }
        }
        else if (!fontPriorityCMTT && CMTT_AVAIL(ch))
        {   if (currentFont != FONT_CMTT)
            {   dc.SetFont(*fixedPitch);
                currentFont = FONT_CMTT;
            }
        }
        else if (currentFont != FONT_CJK)
        {   dc.SetFont(*fixedCJK);
            currentFont = FONT_CJK;
        }
        dc.DrawText(cs, columnPos[col], y);
        if (currentFont == FONT_CJK &&
            ch >= 0x2000) col++;
        col++;
    }
    return p;
}


static char **modules_list=NULL, **switches_list=NULL;


void fwin_callback_on_delay(delay_callback_t *f)
{
    delay_callback = f;
}

void fwin_callback_to_interrupt(interrupt_callback_t *f)
{
    interrupt_callback = f;
}


int fwin_windowmode()
{
    int r = 0;
    r |= FWIN_WITH_TERMED;
    if (windowed) r |= FWIN_IN_WINDOW;
    return r;
}

void fwin_exit(int return_code)
{
    fwin_ensure_screen();
    FWIN_LOG(("fwin_exit(%d)\n", return_code));
    if (windowed)
    {   returncode = return_code;
        panel->frame->worker->DoExit();
    }
    else exit(return_code);
}

void fwin_abrupt_exit()
{
// This is used e.g. when the user closes the window that you are running
// in.
    FWIN_LOG(("fwin_abrupt_exit\n"));
    if (windowed)
    {   returncode = 0;
        panel->frame->worker->DoExit();
    }
    else exit(0);
}


void fwin_minimize()
{
    if (!windowed) return;
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, MINIMISE_WINDOW);
    panel->GetEventHandler()->QueueEvent(event);
}


void fwin_restore()
{
    if (!windowed) return;
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, RESTORE_WINDOW);
    panel->GetEventHandler()->QueueEvent(event);
}

#ifdef WIN32
// In a manner that soewhhat astonished me under Windows I find that
// putchar('a'); putchar('b'); differs in behaviour from fputs("ab", stdout)
// when the characters and and b are replaced by values in the range
// 128 - 255. Even if I have a terminal set with an utf-8 code page the
// display following individual uses of putchar() are a mess, while if I
// output all the bytes of a multi-byte character at once it is able to
// display (subject to my terminal having a suitable font installed).
// I am observing this on a Windows 7 system using "gcc-3 -mno-cygwin" and
// am not certain exactly what other cases it will apply in. However buffering
// a few terminal-output characters will not be a huge burden, so I will do it.

#define LINE_BUFFER_SIZE 80
static char line_buffer[LINE_BUFFER_SIZE];
static int line_buffer_p = 0;

static void flush_line_buffer()
{
    if (line_buffer_p != 0)
    {   line_buffer[line_buffer_p] = 0;
        fputs(line_buffer, stdout);
        line_buffer_p = 0;
    }
}

#endif

void fwin_putchar(int c)
{
    if (!windowed)
    {
#ifdef __CYGWIN__
        if (c == '\n') fwin_putchar('\r');
#endif
#ifdef WIN32
        if ((c & 0xc0) != 0x80 && line_buffer_p > LINE_BUFFER_SIZE-5)
            flush_line_buffer();
        line_buffer[line_buffer_p++] = c;
#else
        putchar(c);
#endif
        return;
    }
// I arrange to do any buffer flushing just before I will send out a
// byte that starts a character. An effect is that I should NEVER flush
// the buffer part way through a multi-byte character.
    if ((c & 0xc0) != 0x80 &&
        panel->fwin_in >= FWIN_BUFFER_SIZE-4) fwin_ensure_screen();
    int in = panel->fwin_in;
    if (panel->use_buffer1)
        panel->fwin_buffer1[in] = c;
    else panel->fwin_buffer2[in] = c;
    panel->fwin_in = in+1;
    FILE *f = panel->logfile;
    if (f != NULL) putc(c, f);
}

void fwin_putcode(int c)
{
// This expands a character code into an UTF sequence for transmission to
// the GUI and for inclusion in any log file.
    FWIN_LOG(("fwin_putcode %#x\n", c));
    if (c < 0x80) fwin_putchar(c);
    else if (c <= 0x800)
    {   fwin_putchar(0xc0 | ((c>>6) & 0x1f));
        fwin_putchar(0x80 | (c & 0x3f));
    }
    else if (c <= 0x10000)
    {   fwin_putchar(0xe0 | ((c>>12) & 0x0f));
        fwin_putchar(0x80 | ((c>>6) & 0x3f));
        fwin_putchar(0x80 | (c & 0x3f));
    }
    else if (c <= 0x200000)
    {   fwin_putchar(0xf0 | ((c>>18) & 0x07));
        fwin_putchar(0x80 | ((c>>12) & 0x3f));
        fwin_putchar(0x80 | ((c>>6) & 0x3f));
        fwin_putchar(0x80 | (c & 0x3f));
    }
    else FWIN_LOG(("Illegal character code %#x\n", c));
}

void fwin_puts(const char *s)
{
    if (!windowed)
    {
#ifdef WIN32
        flush_line_buffer();
#endif
#ifdef RAW_CYGWIN
        while (*s != 0) fwin_putchar(*s++);
#else
        puts(s);
#endif
        return;
    }
    int len = strlen(s);
    FWIN_LOG(("fwin_puts(\"%s\")\n", s));
    char *b = panel->use_buffer1 ? panel->fwin_buffer1 : panel->fwin_buffer2;
    int in = panel->fwin_in;
    while (len > 0)
    {   int n = len;
// If the string being displayed here will not fit in the current buffer
// I have two possible things that I could do. The first is to flush the
// buffer so I have a totally empty buffer to store the string in. The
// other is to split the string into several parts. If the buffer is
// already at least half full I will flush it and try again. If the buffer
// is at least half empty (including the case when I had just flushed it) I
// will need to split the string.
        if (in + n > FWIN_BUFFER_SIZE)
        {   if (in > FWIN_BUFFER_SIZE/2)
            {   fwin_ensure_screen();
// flushing the buffer changes which buffer I am using.
                b = panel->use_buffer1 ? panel->fwin_buffer1 :
                                         panel->fwin_buffer2;
                in = panel->fwin_in;
                continue;
            }
            n = FWIN_BUFFER_SIZE - in;
// I search for a byte that is not of the form 10xxxxxx since those are
// continuation bytes in a multi-byte character. I have at least half a
// buffer to search in, and valid data can only have a maximum of 3
// continuation bytes to skip back past. Well I say 3 because I am
// only using UTF-8 up as far as being able to cope with 21-bit codes.
            while ((s[n] & 0xc0) == 0x80) n--;
        }
        memcpy(&b[panel->fwin_in], s, n);
        FILE *f = panel->logfile;
        if (f != NULL) fwrite(s, 1, n, f);
        panel->fwin_in += n;
        s += n;
        len -= n;
    }
}


void
#ifdef _MSC_VER
            __cdecl
#endif
            fwin_printf(const char *fmt, ...)
{
    va_list a;
    va_start(a, fmt);
    if (!windowed)
    {
#ifdef WIN32
        flush_line_buffer();
#endif
#ifdef RAW_CYGWIN
// NOT reconstructed yet: in the raw cygwin you may get line-ends that
// are mere LF where I possibly really wanted CR-LF combinations.
        vfprintf(stdout, fmt, a);
        va_end(a);
#else
        vfprintf(stdout, fmt, a);
        va_end(a);
#endif
        return;
    }
// If the buffer is getting full I will flush it. In earlier code I checked
// for a PAUSE state here... I may need to reinstate that behaviour later.
    if (panel->fwin_in+SPARE_FOR_VFPRINTF >= FWIN_BUFFER_SIZE)
        fwin_ensure_screen();
    char *b = panel->use_buffer1 ? panel->fwin_buffer1 : panel->fwin_buffer2;
    int in = panel->fwin_in;
#ifdef HAVE_VSNPRINTF
    vsnprintf(&b[in], SPARE_FOR_VFPRINTF, fmt, a);
#else
// In this case I have no protection againt buffer overflow. However I
// now really expect most C/C++ implementations to provide vsnprintf.
    vsprintf(&b[in], fmt, a);
#endif
// Cautious about portability and old libraries, and aware of values that
// vsnprintf may return when the data does not fit, I ignore the values
// of the above functions and adjust the data pointers by hand.
    int n = strlen(&b[in]);
    FILE *f = panel->logfile;
    if (f != NULL) fwrite(&b[in], 1, n, f);
    panel->fwin_in = in + n;
    va_end(a);
}

void fwin_vfprintf(const char *fmt, va_list a)
{
    if (!windowed)
    {
#ifdef WIN32
        flush_line_buffer();
#endif
#ifdef RAW_CYGWIN
// See comments aboove re CR-LF vs '\n'. I do not expect raw cygwin builds
// to be terribly useful (since that will represent and X11 GUI running on
// Windows rather than the native one) so I do not treat this as high
// priority.
        vfprintf(stdout, fmt, a);
#else
        vfprintf(stdout, fmt, a);
#endif
        return;
    }
    FWIN_LOG(("fwin_vfprintf(\"%s\",...)\n", fmt));
// see comments above.
    if (panel->fwin_in+SPARE_FOR_VFPRINTF >= FWIN_BUFFER_SIZE)
        fwin_ensure_screen();
    char *b = panel->use_buffer1 ? panel->fwin_buffer1 : panel->fwin_buffer2;
    int in = panel->fwin_in;
#ifdef HAVE_VSNPRINTF
    vsnprintf(&b[in], SPARE_FOR_VFPRINTF, fmt, a);
#else
    vsprintf(&b[in], fmt, a);
#endif
    int n = strlen(&b[in]);
    FILE *f = panel->logfile;
    if (f != NULL) fwrite(&b[in], 1, n, f);
    panel->fwin_in += n;
}

const char *fwin_maths = NULL;

void fwin_showmath(const char *s)
{
    if (!windowed) return;
    FWIN_LOG(("fwin_showmath called\n"));
// The current version of this is going to be pretty outrageous!
// It will suppose you have latex installed on your computer and will
// invoke it to convert the formula you just created into .dvi format.
    char tempd[LONGEST_LEGAL_FILENAME];
#ifdef WIN32
    int rc;
    memset(tempd, 0, sizeof(tempd));
    rc = GetTempPathA(LONGEST_LEGAL_FILENAME, tempd);
    if (rc == 0 || rc >= LONGEST_LEGAL_FILENAME) strcpy(tempd, "C:");
    DWORD procid = GetCurrentProcessId();
    char *ww;
    for (ww=tempd; *ww!=0; ww++) if (*ww == '\\') *ww = '/';
#else
    const char *tt = my_getenv("TMPDIR");
    memset(tempd, 0, sizeof(tempd));
    if (tt == NULL) strcpy(tempd, "/tmp");
    else strcpy(tempd, tt);
    pid_t procid = getpid();
#endif
    int dirlen = strlen(tempd);
    if (tempd[dirlen-1] == '/') dirlen--;
    FWIN_LOG(("temp = \"%s\" length %d\n", tempd, dirlen));
    sprintf(&tempd[dirlen], "/reduce-%d.tex", (int)procid);
    FWIN_LOG(("TeX file will be in \"%s\"\n", tempd));
    FILE *f = fopen(tempd, "w");
    fprintf(f, "\\documentclass{article}\n");
    fprintf(f, "\\pagestyle{empty}\n");
    fprintf(f, "\\setlength{\\oddsidemargin}{0in}\n");
    fprintf(f, "\\setlength{\\evensidemargin}{0in}\n");
    fprintf(f, "\\setlength{\\topmargin}{0in}\n");
    fprintf(f, "\\setlength{\\headheight}{0in}\n");
    fprintf(f, "\\setlength{\\headsep}{0in}\n");
// Actually I will be in a MESS if a single formula uses more than a page
// of output. I will worry about that later! Specifically I may need to ensure
// that my dvi-rendering code shows multiple pages neatly and worry about
// specing at the end of a page.
    fprintf(f, "\\setlength{\\textheight}{11in}\n");
    fprintf(f, "\\begin{document}\n");
    fprintf(f, "%s\n", s);
    fprintf(f, "\\end{document}\n");
    fclose(f);
    char cmd[LONGEST_LEGAL_FILENAME];
    memset(cmd, 0, sizeof(cmd));
//
// Under Windows I want to have cygwin installed and on your "PATH", with
// tex included. However the command "latex" in that case is a cygwin-style
// symbolic link, and the "system()" function does not accept it. To work
// around that I explicitly invoke the bash shell. For this to behave you MUST
// have c:\cygwin\bin (or wherever you have put things) on your PATH so that
// bash and cygwin1.dll can be found. I really rather dislike this situation.
//
#ifdef WIN32
    sprintf(cmd, "bash -c \"latex --output-directory=%.*s reduce-%d.tex\"",
                 dirlen, tempd, (int)procid);
#else
    sprintf(cmd, "latex --output-directory=%.*s reduce-%d.tex",
                 dirlen, tempd, procid);
#endif
    FWIN_LOG(("TeX is: \"%s\"\n", s));
    FWIN_LOG(("Command: \"%s\"\n", cmd));
    int src = system(cmd);
    FWIN_LOG(("system returns %d\n", src));
#ifdef WIN32
    sprintf(cmd, ".\\wxdvi %.*s/reduce-%d.dvi", dirlen, tempd, (int)procid);
#else
    sprintf(cmd, "./wxdvi %.*s/reduce-%d.dvi", dirlen, tempd, (int)procid);
#endif
    FWIN_LOG(("Cmd: \"%s\"\n", cmd));
    system(cmd);
#ifdef WIN32
#define delfile DeleteFileA
#else
#define delfile remove
#endif
//  delfile(tempd);     // Preserve the TeX file...
    sprintf(&tempd[dirlen], "/reduce-%d.aux", (int)procid);
    delfile(tempd);
    sprintf(&tempd[dirlen], "/reduce-%d.log", (int)procid);
    delfile(tempd);
    sprintf(&tempd[dirlen], "/reduce-%d.dvi", (int)procid);
// Just for now I will leave the .dvi file around...
//  delfile(tempd);
}


void fwin_ensure_screen()
{
    if (!windowed)
    {
#ifdef WIN32
        flush_line_buffer();
#endif
        fflush(stdout);
        return;
    }
    if (panel->fwin_in == 0) return;
    FWIN_LOG(("fwin_ensure_screen\n"));
    if (panel->use_buffer1)
        FWIN_LOG(("B1: <%.*s>\n", (int)panel->fwin_in, &(panel->fwin_buffer1[0])));
    else FWIN_LOG(("B2: <%.*s>\n", (int)panel->fwin_in, &(panel->fwin_buffer2[0])));
// Wait until GUI thread is ready, ie has finshed emptying the other
// buffer.
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
// The next few lines are a SAFE region. The GUI thread had completed
// processing the previous request that had been sent to it, but it has
// not yet been told to start on the new buffer.
    panel->fwin_out = panel->fwin_in;
// Create an event to ask the GUI thread to empty the buffer.
    wxThreadEvent *event =
        new wxThreadEvent(wxEVT_COMMAND_THREAD,
             panel->use_buffer1 ? FLUSH_BUFFER1 : FLUSH_BUFFER2);
// flip active buffer.
    panel->use_buffer1 = !panel->use_buffer1;
    panel->fwin_in = 0;
// Post event to get the other buffer emptied to the screen.
    panel->GetEventHandler()->QueueEvent(event);
}

extern "C"
{
static review_switch_settings_function *review_switch_settings = NULL;
}

static int update_next_time = 0;


int fwin_getchar()
{
    if (!windowed)
    {
#ifdef WIN32
        flush_line_buffer();
#endif
        return fwin_plain_getchar();
    }
// In general I have a line of stuff ready sitting in a buffer. So on
// most calls to here I can just return what is in it.
    if (panel->inputBufferP < panel->inputBufferLen)
        return panel->inputBuffer[panel->inputBufferP++];
// Now however a new line of input is needed, so I have to request it from
// the user-interface thread.
    if (update_next_time && review_switch_settings != NULL)
    {   (*review_switch_settings)();
        update_next_time = 0;
    }
    if (delay_callback != NULL) (*delay_callback)(1);
    fwin_ensure_screen();
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, REQUEST_INPUT);
    panel->GetEventHandler()->QueueEvent(event);
// OK - the screen is up to date as regards output and all other changes
// I may have made - and I have now asked for some input. This request will
// cause the GUI thread to to a Post() on the reading semaphore when it has
// put a line of valid data into inputBuffer.
    panel->reading.Wait(); // the genuine wait for input
    if (shouldExit) fwin_abrupt_exit();
    if (delay_callback != NULL) (*delay_callback)(0);
// I will try a convention that if inputBufferLen is zero that indicates
// a dodgy state. Eg the user is sending an EOF or interrupt.
    int n = panel->inputBufferLen;
    if (n == 0) return EOF;
    const unsigned char *p = &panel->inputBuffer[panel->inputBufferP];
// The next line is pretty shameless and is there to help REDUCE while not
// getting too much in the way of anybody else. If an input line is
// entered starting with the text "load_package" (possibly with some
// whitespace first) I make a callback to review_switch_settings fairly
// soon.
    while (n>0 && isspace(*p))
    {   n--;
        p++;
    }
    if (n>12 && strncmp((const char *)p, (const char *)"load_package", 12) == 0)
        update_next_time = 1;
    int ch = panel->inputBuffer[panel->inputBufferP++];
// Note that a Ctrl-D as the VERY FIRST character in the buffer is treated
// as signalling end-of-file. If the user hits Ctrl-D in any other position
// it would be treated as "delete one character forwards".
    if (ch == (0x1f & 'D')) return EOF;
    else return ch;
}


void fwin_set_prompt(const char *s)
{
    strncpy(fwin_prompt_string, s, sizeof(fwin_prompt_string));
    fwin_prompt_string[sizeof(fwin_prompt_string)-1] = 0;
    if (!windowed) return;
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, SET_PROMPT);
    panel->GetEventHandler()->QueueEvent(event);
}

void fwin_menus(char **modules, char **switches,
                review_switch_settings_function *f)
{
    if (!windowed) return;
    modules_list = modules;
    switches_list = switches;
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    review_switch_settings = f;
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, SET_MENUS);
    panel->GetEventHandler()->QueueEvent(event);
}

void fwin_refresh_switches(char **switches, char **packages)
{
    if (!windowed) return;
    switches_list = switches;
    modules_list = packages;
    panel->writing.Wait();
    if (shouldExit) fwin_abrupt_exit();
    wxThreadEvent *event = new wxThreadEvent(wxEVT_COMMAND_THREAD, REFRESH_SWITCHES);
    panel->GetEventHandler()->QueueEvent(event);
}

static char left_stuff[32] = "",
            right_stuff[32] = "";
char mid_stuff[32] = "", full_title[90] = "";

#ifdef USE_A0_SPACER
#define SPACER_CHAR 0xa0
#else
#define SPACER_CHAR 0x20
#endif

static void rewrite_title_bar()
{
// Just at present this does not cope with cases where the width of the window
// has been changed...
    int ll = strlen(left_stuff),
        lm = strlen(mid_stuff),
        lr = strlen(right_stuff);
    int i, j;
    for (i=0; i<80; i++) full_title[i] = SPACER_CHAR;
    strncpy(full_title, left_stuff, ll);
    j = 80 - strlen(right_stuff);
    strncpy(&full_title[j], right_stuff, lr);
    j = 40-(lm/2);
    strncpy(&full_title[j], mid_stuff, lm);
    full_title[80] = 0;
#ifdef RECONSTRUCTED
    wake_up_terminal(FXTerminal::REFRESH_TITLE);
    regain_lockstep();
#endif
}


void fwin_acknowledge_tick()
{
// This is to do with my handling of "^Z" to suspend the computation.
// If the user enters ^Z I lock the pause mutex and then send a "TICK".
// The user is expected to notice it and respond here - and hence get
// suspended. ????
    if (!windowed) return;
// To keep wxWidgets threads happy I must poll like this periodically.
    wxThread::This()->TestDestroy();
    if (shouldExit) fwin_abrupt_exit();
}



void fwin_report_left(const char *msg)
{
    if (!windowed) return;
    strncpy(left_stuff, msg, 31);
    left_stuff[31] = 0;
#ifdef RECONSTRUCTED
    rewrite_title_bar();
#endif
}

void fwin_report_mid(const char *msg)
{
    if (!windowed) return;
    strncpy(mid_stuff, msg, 31);
    mid_stuff[31] = 0;
#ifdef RECONSTRUCTED
    rewrite_title_bar();
#endif
}

void fwin_report_right(const char *msg)
{
    if (!windowed) return;
    strncpy(right_stuff, msg, 31);
    right_stuff[31] = 0;
#ifdef RECONSTRUCTED
    rewrite_title_bar();
#endif
}

void fwin_set_help_file(const char *key, const char *path)
{
    if (!windowed) return;
#ifdef RECONSTRUCTED
    printf("fwin_set_help_file called\n");
    fflush(stdout);
#endif
}

// End of wxterminal.cpp
