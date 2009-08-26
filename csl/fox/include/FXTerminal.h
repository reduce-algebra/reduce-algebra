/******************************************************************************
*                                                                             *
*   T e x t   w i n d o w   t h a t   a l l o w s   s i m p l e   I / O       *
*                                                                             *
*******************************************************************************
* Copyright (C) 2003-8 by Arthur Norman, Codemist Ltd.  All Rights Reserved.  *
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
* I would have granted rights similar to those in the FOX addendum to the     *
* LGPL, but since this code requires modifications to the body of FOX I am    *
* not able to to do that and this is hence only available under LGPL 2.1      *
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


#ifndef FXTERMINAL_H
#define FXTERMINAL_H

/* Signature: 729d7fff 13-Jul-2009 */

#include "FXMathText.h"

#include "FXDCNativePrinter.h"


// Include header files that give access to thread primitives.

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

#ifndef WIN64
#include <unistd.h>
#endif


namespace FX {

// Firstly I will define a Mutex. This is something made pretty directly
// available in both Windows and Posix threads. Because of this I will
// just map names using some C macros.

// Mutex m;
// InitMutex(m);
// ... LockMutex(m) ... UnlockMutex(m) ...
// DestroyMutex(m);

// It will often make sense to put calls to DestroyMutex in the destuctor
// for a class where its constructor did the InitMutex.


#ifdef WIN32
typedef CRITICAL_SECTION Mutex;
#define InitMutex(m)    InitializeCriticalSection(&m)
#define DestroyMutex(m) DeleteCriticalSection(&m)
#define LockMutex(m)    EnterCriticalSection(&m)
#define UnlockMutex(m)  LeaveCriticalSection(&m)
#else
typedef pthread_mutex_t Mutex;
#define InitMutex(m)    pthread_mutex_init(&m, NULL)
#define DestroyMutex(m) pthread_mutex_destroy(&m)
#define LockMutex(m)    pthread_mutex_lock(&m)
#define UnlockMutex(m)  pthread_mutex_unlock(&m)
#endif


// signalling from one task to another

#ifdef WIN32
extern HANDLE pipedes;
extern int event_code;
#else
extern int pipedes[2];
#endif
#define PIPE_READ_PORT 0
#define PIPE_WRITE_PORT 1

#if INT_VERSION(FOX_MAJOR,FOX_MINOR,0) == INT_VERSION(1,0,0)
#define FXMenuBar FXMenubar
#endif
extern FXMenuBar *main_menu_bar;

extern char **modules_list, **switches_list;

extern const char *fwin_maths;
extern "C" 
{
extern int showmathInitialised;
}

//
// I derive a sub-class from MainWindow just so I can notice when the
// window is re-sized and record information in the registry.
//

class FXAPI FXMainWindow1 : public FXMainWindow
{
    FXDECLARE(FXMainWindow1)
public:
    FXMainWindow1(FXApp *, const FXString &, FXIcon *, FXIcon *, FXuint,
        FXint,FXint,FXint,FXint,FXint,FXint,FXint,FXint,FXint,FXint);
    FXMainWindow1();
    virtual void create();
    long onConfigure(FXObject *,FXSelector,void *);
};


extern "C" {
extern int windowed;
}
extern const char *colour_spec;
extern FXApp *application_object;
extern FXMainWindow1 *main_window;
extern "C" {
#ifdef WIN32
extern DWORD __stdcall worker_thread(void *);
#else
extern void *worker_thread(void *);
#endif
}
extern FXTimer *timer;
extern char mid_stuff[32], full_title[90];

extern FXFont *selectFont(const char *name, int size,
    int weight, int slant, int encoding, int setwidth, int hints);

#ifdef WIN32
extern HANDLE thread1;
#else
extern pthread_t thread1;
#endif

extern int rootWidth, rootHeight;

/// Multiline text widget supporting use as a terminal-window style
/// interface to other worker code. 

class FXAPI FXTerminal : FXMathText {
  FXDECLARE(FXTerminal)

public:
  enum {
    STYLE_UNDERLINE = 0x0001,   /// Underline text
    STYLE_STRIKEOUT = 0x0002,   /// Strike out text
    STYLE_BOLD      = 0x0004,   /// bold text
    STYLE_PROMPT    = 0x0008,   /// displayed in alternate colour
    STYLE_INPUT     = 0x0010,   /// displayed in yet another colour
    STYLE_MATH      = 0x0020,   /// mathematics in TeX internal style
    STYLE_GREEK     = 0x0040    /// displayed in alternate font (sometime?)
    };

  long onTimeout(FXObject*,FXSelector,void*);
  long onCmdInsertNewline(FXObject*,FXSelector,void*);
  long onIPC(FXObject*,FXSelector,void*);

  long requestFlushBuffer();
  long requestSetPrompt();
  long requestRequestInput();
  long requestWorkerExiting();
  long requestRefreshTitle();
  long requestShowMath();
  long requestSetMenus();
  long requestRefreshSwitches();

  long onCmdRead(FXObject *c, FXSelector s, void *ptr);
  long onCmdSave(FXObject *c, FXSelector s, void *ptr);
  long onCmdSaveSelection(FXObject *c, FXSelector s, void *ptr);
  long onCmdToFile(FXObject *c, FXSelector s, void *ptr);
  long onCmdPrint(FXObject *c, FXSelector s, void *ptr);
  long onCmdPrintSelection(FXObject *c, FXSelector s, void *ptr);
  long doPrinting(int startp, int endp);
  long onCmdCutSel(FXObject *c, FXSelector s, void *ptr);
  long onCmdPasteSel(FXObject *c, FXSelector s, void *ptr);
  long onCmdPasteMiddle(FXObject *c, FXSelector s, void *ptr);
  long onCmdCopySel(FXObject *c, FXSelector s, void *ptr);
  long onCmdReinput(FXObject *c, FXSelector s, void *ptr);
  long onCmdClear(FXObject *c, FXSelector s, void *ptr);
  long onCmdRedraw(FXObject *c, FXSelector s, void *ptr);
  long onCmdHome(FXObject *c, FXSelector s, void *ptr);
  long onCmdEnd(FXObject *c, FXSelector s, void *ptr);
  long onCmdFont(FXObject *c, FXSelector s, void *ptr);
  long onCmdResetFont(FXObject *c, FXSelector s, void *ptr);
  long onCmdResetWindow(FXObject *c, FXSelector s, void *ptr);
  long onCmdBreak(FXObject *c, FXSelector s, void *ptr);
  long onCmdBacktrace(FXObject *c, FXSelector s, void *ptr);
  long onCmdPause(FXObject *c, FXSelector s, void *ptr);
  long onCmdResume(FXObject *c, FXSelector s, void *ptr);
  long onCmdStop(FXObject *c, FXSelector s, void *ptr);
  long onCmdDiscard(FXObject *c, FXSelector s, void *ptr);
  long onCmdLoadModule(FXObject *c, FXSelector s, void *ptr);
  long onCmdFlipSwitch(FXObject *c, FXSelector s, void *ptr);
  long onCmdSelectBrowser(FXObject *c, FXSelector s, void *ptr);
  long onCmdHelp(FXObject *c, FXSelector s, void *ptr);
  long onCmdAbout(FXObject *c, FXSelector s, void *ptr);

  void setEditable(FXbool st = TRUE);
  void performPaste(FXchar *, FXint);
  int insertFromPaste();
  int isStartPrompt(const char *s);
  int isStyle(const char *s);

// The next batch are for the "readline-like" input interface
  int keyFlags, searchFlags, startMatch, pauseFlags,
      historyFirst, historyLast, historyNumber, promptEnd;
  unsigned short int searchStack[256];
  char searchString[256];
  Mutex pauseMutex;
#define ANY_KEYS       1
#define ESC_PENDING    2
#define SEARCH_LENGTH   (searchFlags & 0xff)
#define SEARCH_FORWARD  0x100
#define SEARCH_BACKWARD 0x200
#define PAUSE_PAUSE    1
#define PAUSE_STOP     2
#define PAUSE_DISCARD  4
  int getHistoryEvent();
  int trySearch();
  int matchString(const char *p, int n, const char *t);

  int editBacktrace();
  int editRedisplay();
  int editUppercase();
  int editCopyRegion();
  int editExtendedCommand();
  int editObeyCommand();
  int editSetMark();
  int editMoveLineStart();
  int editPrevChar();
  int editPrevWord();
  int editBreak();
  int editCapitalize();
  int editDeleteForward();
  int editDeleteForwardWord();
  int editMoveLineEnd();
  int editNextChar();
  int editNextWord();
  int editStartAgain();
  int editDeleteBackward();
  int editDeleteBackwardWord();
  int editNewline();
  int editCutLine();
  int editLowercase();
  int editHistoryNext();
  int editHistoryPrev();
  int editSearchHistoryNext();
  int editSearchHistoryPrev();
  int editUpLine();
  int editTranspose();
  int editDeleteLastWord();
  int editPaste();
  int editRotateClipboard();
  int editEscape();
  int editReinput();
  int editUndo();
  int editCopyPreviousWord();

  int setInputText(const FXchar *text, int n);

  int charForShowMath();
  void insertMathsLines();
  void recordBoxAddress(int n, union Box *b);
  union Box *getBoxAddress(int n) const;

  enum {  // used with signalling
    FLUSH_BUFFER,
    SET_PROMPT,
    REQUEST_INPUT,
    MINIMIZE_MAIN,
    RESTORE_MAIN,
    WORKER_EXITING,
    REFRESH_TITLE,
    SHOW_MATH,
    SET_MENUS,
    REFRESH_SWITCHES,
    DUMMY_MESSAGE
    };


  enum {
    ID_IPC=FXMathText::ID_LAST,
    ID_TIMEOUT,

    ID_READ,
    ID_SAVE,
    ID_SAVE_SELECTION,
    ID_TO_FILE,
    ID_PRINT,
    ID_PRINT_SELECTION,
    ID_CUT_SEL_X,     // NB exists in FXMathText but here I will want to...
    ID_PASTE_SEL_X,   // adjust the cursor position as I go.
    ID_COPY_SEL_X,
    ID_REINPUT,
//  ID_SELECT_ALL,    // done by the underlying FXMathText
    ID_CLEAR,
    ID_REDRAW,
    ID_HOME,
    ID_END,
    ID_FONT,
    ID_RESET_FONT,
    ID_RESET_WINDOW,
    ID_BREAK,
    ID_BACKTRACE,
    ID_PAUSE,
    ID_RESUME,
    ID_STOP,
    ID_DISCARD,
    ID_BROWSER,
    ID_HELP,
    ID_ABOUT,
    ID_LOAD_MODULE,
    ID_FLIP_SWITCH,
    ID_LAST
    };

  void calcVisRows(FXint startline,FXint endline);

  void drawContents(FXDCWindow& dc,FXint x,FXint y,FXint w,FXint h) const;

  void drawTextRow(FXDCWindow& dc,FXint line,FXint left,FXint right) const;

  void drawBufferText(FXDCWindow &dc, FXint x, FXint y,
                      FXint w, FXint h, FXint pos, FXint n,
                      FXuint style) const;

  int cmrFontsEmbedded;  // Used in ShowMath case

  int printBufferText(FXDCNativePrinter &dc, FXint x, FXint y,
                      char *str, FXint n,
                      FXuint style);

  int printTextRow(FXDCNativePrinter &dc, int p, int y, int left, int right);

  void printContents(FXDCNativePrinter &dc, int startpos, int endpos,
       int left, int right, int top, int bottom);

  /// Construct multi-line text widget
  FXTerminal(FXComposite *p, FXObject* tgt=NULL, FXSelector sel=0,
             FXuint opts=0, FXint x=0, FXint y=0, FXint w=0, FXint h=0);

  virtual void create();

  /// Change text font
  void setFont(FXFont* fnt);
  
  /// forces everything to 80 columns
  int forceWidth();

  /// enable or disable text styles
  void setStyled(FXbool st=TRUE);

  /// Change number of visible rows
  void setVisibleRows(FXint rows);

  /// Change number of visible columns
  void setVisibleColumns(FXint cols);

  /// Append n characters of text at the end of the buffer
  void appendText(const FXchar *text,FXint n,FXbool notify=FALSE);

  /// Append n characters of text at the end of the buffer
  void appendStyledText(const FXchar *text,FXint n,
                        FXint style=0,FXbool notify=FALSE);

  /// Handle keyboard input
  long onKeyPress(FXObject *,FXSelector, void *);

  /// Test if editable
  FXbool isEditable();
  int isEditableForBackspace();

  /// Destructor
  virtual ~FXTerminal();

  FXTimer *timer;

  void setupShowMath();
  void reportDestroy(int p);

  int sync_even;
  Mutex mutex1, mutex2, mutex3, mutex4;

  FILE *logfile;

  void type_ahead(int c);
  void string_ahead(const char *s);

// I will have a buffer for transfer of characters from the application
// to the user-interface. Use of printf-like things is a bit delicate
// because buffer overflow in vsprintf is a danger. I allow a margin
// of length (200).
// When I (eventually) gain confidence in C99 I will use vsnprintf and
// be safer.

#define FWIN_BUFFER_SIZE  1000
#define SPARE_FOR_VFPRINTF 200

  char fwin_buffer[FWIN_BUFFER_SIZE];

// The following two are used by both worker and interface tasks, and so
// over-clever compiler optimisation of them is undesirable.
//
// fwin_in belongs to the worker thread, while fwin_out is owned by the
// user interface. Each will use read-only access to the other (unless the
// two are synchronised, in which case full access is permitted). I will
// assume that my hardware makes simple reads and writes of these variables
// atomic.

  volatile int fwin_in, fwin_out;

#define INPUT_BUFFER_LENGTH 512

  int inputBufferLen;
  int inputBufferP;
  char inputBuffer[INPUT_BUFFER_LENGTH];

  int recently_flushed;

  int argc;
  char **argv;

#ifdef WIN32
  DWORD worker_thread(void *);
#else
  void *worker_thread(void *);
#endif

  int lineSpacing;
  FXColor  promptColor;         // prompt string colour
  FXColor  inputColor;          // input text colour
  FXTerminal();

  };


extern "C"
{
extern FXTerminal *text;
}

#ifdef WIN32
#define DEFAULT_FONT_NAME "Courier New"
#else
#define DEFAULT_FONT_NAME "courier"
#endif

} // namespace

#endif

// end of FXTerminal.h
