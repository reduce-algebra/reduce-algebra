//
// "FXTerminal.cpp"                         Copyright A C Norman 2003-2008
//
//
// Window interface for old-fashioned C applications. Intended to
// be better than just running them within rxvt/xterm, but some people will
// always believe that running them under emacs is best!
//

/******************************************************************************
* Copyright (C) 2003-8 by Arthur Norman, Codemist Ltd.   All Rights Reserved. *
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
* I had intended to release this under the FOX addendum to its license that   *
* permits static linking, but the non-transitive nature of the terms there    *
* makes that infeasible hence this is just under LGPL.                        *
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


/* Signature: 2015cdb8 13-Jul-2009 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "fwin.h"
#include <fx.h>

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

#if FOX_MAJOR==1 && FOX_MINOR==0
#  define FXSEL(a,b) MKUINT(a,b)
#  define minimize() iconify()
#  define restore()  deiconify()
#endif

#include <fxkeys.h>          // not included by <fx.h>

#include "FXShowMath.h"

#include "FXTerminal.h"      // my own header file.

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include <sys/stat.h>

#ifndef S_IXUSR
#ifdef __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif
#endif

// The next is for pipes and threads
#ifdef WIN32

#include <windows.h>


namespace FX {

#include "termed.h"

HANDLE pipedes;
int event_code = -1;

#else

#include <unistd.h>

namespace FX {

int pipedes[2];

#endif /* WIN32 */

static FXPrinter printer;

// I need an event table of things that the user interface must respond to.
//
// I have to implement local editing and history stuff for the FOX-based
// version of the code here, and a parallel implementation is in the
// file "termed.c" to cope with cursor-addressible terminals (rather than
// real windows). It is perhaps unfortunate to have two parallel versions,
// but in various detailed ways it does not make sense for the treatment of
// keystrokes to match exactly in windowed and non-windowed mode (I thing!)
// and the code here has to be event driven, while the terminal version
// pulls characters from the terminal driver. At least by having both
// versions of the code my own and under my own control I can keep some sort
// of a handle on compatibility.
// Two examples of marginal oddities: the windowed version will very clearly
// have menu short-cut keys and they are processed by FOX rather directly.
// The terminal one does not need a menu to change its font, and any menu
// short-cut keys have to be handled directly by me.
// On the other hand while a terminal is in "cooked" mode various characters
// such as ^S, ^Q, ^C and ^Z are liable to be handled for me automatically,
// while in the FOX/Window version I need to intercept and deal with those
// for myself.


FXDEFMAP(FXTerminal) FXTerminalMap[] =
{
// User types some character. I override the FXMathText behaviour here
    FXMAPFUNC(SEL_KEYPRESS,     0, FXTerminal::onKeyPress),

// User types a newline. This overrides the behaviour that FXMathText had
    FXMAPFUNC(SEL_COMMAND,      FXMathText::ID_INSERT_NEWLINE,
                                FXTerminal::onCmdInsertNewline),

// Several events that can be generated by the worker thread.
    FXMAPFUNC(SEL_IO_READ,      FXTerminal::ID_IPC, FXTerminal::onIPC),

// Regular timer ticks from a timer thread.
    FXMAPFUNC(SEL_TIMEOUT,      FXTerminal::ID_TIMEOUT, FXTerminal::onTimeout),

// ... and now all the menu items that the user can provoke. The three cases
// above are given first as a (minor) efficiency issue.

// The next 2 may not be especially useful to people other than me...
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_LOAD_MODULE, FXTerminal::onCmdLoadModule),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_FLIP_SWITCH, FXTerminal::onCmdFlipSwitch),

    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_READ, FXTerminal::onCmdRead),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_SAVE, FXTerminal::onCmdSave),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_SAVE_SELECTION, FXTerminal::onCmdSaveSelection),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_TO_FILE, FXTerminal::onCmdToFile),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_PRINT, FXTerminal::onCmdPrint),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_PRINT_SELECTION, FXTerminal::onCmdPrintSelection),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_CUT_SEL_X, FXTerminal::onCmdCutSel),
    FXMAPFUNC(SEL_COMMAND,      FXMathText::ID_CUT_SEL, FXTerminal::onCmdCutSel),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_PASTE_SEL_X, FXTerminal::onCmdPasteSel),
    FXMAPFUNC(SEL_COMMAND,      FXMathText::ID_PASTE_SEL, FXTerminal::onCmdPasteSel),
    FXMAPFUNC(SEL_COMMAND,      FXMathText::ID_PASTE_MIDDLE, FXTerminal::onCmdPasteMiddle),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_COPY_SEL_X, FXTerminal::onCmdCopySel),
    FXMAPFUNC(SEL_COMMAND,      FXMathText::ID_COPY_SEL, FXTerminal::onCmdCopySel),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_REINPUT, FXTerminal::onCmdReinput),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_CLEAR, FXTerminal::onCmdClear),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_REDRAW, FXTerminal::onCmdRedraw),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_HOME, FXTerminal::onCmdHome),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_END, FXTerminal::onCmdEnd),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_FONT, FXTerminal::onCmdFont),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_RESET_FONT, FXTerminal::onCmdResetFont),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_RESET_WINDOW, FXTerminal::onCmdResetWindow),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_BREAK, FXTerminal::onCmdBreak),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_BACKTRACE, FXTerminal::onCmdBacktrace),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_PAUSE, FXTerminal::onCmdPause),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_RESUME, FXTerminal::onCmdResume),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_STOP, FXTerminal::onCmdStop),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_DISCARD, FXTerminal::onCmdDiscard),
#ifndef WIN32
#if !defined MACINTOSH || !defined MAC_FRAMEWORK
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_BROWSER, FXTerminal::onCmdSelectBrowser),
#endif
#endif
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_HELP, FXTerminal::onCmdHelp),
    FXMAPFUNC(SEL_COMMAND,      FXTerminal::ID_ABOUT, FXTerminal::onCmdAbout)

};

#define TYPEAHEAD_SIZE 200

static int type_in = 0, type_out = 0;
static char ahead_buffer[TYPEAHEAD_SIZE];

static char *paste_buffer;
static int paste_flags, paste_n, paste_p, paste_is_html;

FXIMPLEMENT(FXTerminal, FXMathText, FXTerminalMap, ARRAYNUMBER(FXTerminalMap))

FXTerminal::FXTerminal(FXComposite *p,FXObject* tgt,FXSelector sel,
                       FXuint opts,
                       FXint x,FXint y,FXint w,FXint h) :
    FXMathText(p, tgt, sel, opts, x, y, w, h)
{
    lineSpacing = 1;
    setWrapColumns(80);
    delay_callback = NULL;

    FXPrintDialog dummyPrintDialog(this, "");
    dummyPrintDialog.getPrinter(printer);  // do not show - just get defaults.

// It is of course well within the bounds of imagination that users would
// like to be able to specify these colours, and that of output text,
// for themselves.
    promptColor = FXRGB(0, 64, 200);
    inputColor = FXRGB(200, 64, 128);

    fwin_in = fwin_out = 0;
    inputBufferLen = inputBufferP = 0;
    logfile = NULL;

    type_in = type_out = 0;
    paste_buffer = NULL;
    paste_flags = paste_n = paste_p = paste_is_html = 0;

    input_history_init();
    historyFirst = 0;
    historyLast = -1; // flag to say history is empty.
    pauseFlags = keyFlags = historyNumber = searchFlags = 0;
    promptEnd = length;
    InitMutex(pauseMutex);

    InitMutex(mutex1);
    InitMutex(mutex2);
    InitMutex(mutex3);
    InitMutex(mutex4);

    LockMutex(mutex3);
    LockMutex(mutex4);
    sync_even = 1;

#ifdef WIN32
    pipedes = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (pipedes == 0)
    {   fprintf(stderr,
            "Failed to create an event object for internal communication\n");
        application_object->exit(1);
        exit(1);
    }
    application_object->addInput(pipedes,
                                 INPUT_READ, this, ID_IPC);
#else
    if (pipe(pipedes) != 0)
    {   fprintf(stderr,
            "Failed to create a pipe for internal communication\n");
        application_object->exit(1);
        exit(1);
    }
    application_object->addInput(pipedes[PIPE_READ_PORT],
                                 INPUT_READ, this, ID_IPC);
#endif

    setFocus();    // select this window for input

//- #if FOX_MAJOR==1 && FOX_MINOR==0
//-     timer = application_object->addTimeout(1000, this, ID_TIMEOUT);
//- #else
//- #if FOX_MAJOR==1 && (FOX_MINOR==1 || FOX_MINOR==2)
//-     timer = application_object->addTimeout(this, ID_TIMEOUT, 1000, NULL);
//- #else
//-     application_object->addTimeout(this, ID_TIMEOUT, 1000, NULL);
//- #endif
//- #endif
    matchtime = 800; // causes parens to flash as they match (800 milliseconds)
}

FXTerminal::FXTerminal()
{
    fprintf(stderr,
        "I hope this never happens: report \"@FXT@\" to Codemist please\n");
    fflush(stderr);
}

FXTerminal::~FXTerminal()
{
    input_history_end();
#if FOX_MAJOR==1 && FOX_MINOR<=2
    application_object->removeTimeout(timer); // cancel ticks
#else
    application_object->removeTimeout(this,
                            (FXSelector)ID_TIMEOUT); // cancel ticks
#endif
#ifdef WIN32
    application_object->removeInput(pipedes, ID_IPC);
    CloseHandle(pipedes);
#else
    application_object->removeInput(pipedes[PIPE_READ_PORT], ID_IPC);
    close(pipedes[0]);
    close(pipedes[1]);
#endif
    DestroyMutex(mutex1);
    DestroyMutex(mutex2);
    DestroyMutex(mutex3);
    DestroyMutex(mutex4);
}

void FXTerminal::create()
{
    FXMathText::create();
    setFocus();    // select this window for input

}

extern "C"
{
int showmathInitialised = 0;
}

void FXTerminal::setupShowMath()
{
// Note that the terminal must have been created before I set up the
// FXShowMath stuff since at least on X I need to access the window
// identifier that it uses.
//
// I can give the second arg to setupShowMath, which controls font size, in
// two manners:
// (a) A positive value denotes a font size in decipoints. Well it is actually
//     a bit more ugly than that since on some platforms the size gets
//     adjusted to allow for (notional) screen pixels per inch and sometimes
//     not, and so I do not find this able to give me a totally consistent
//     control;
// (b) A negative value is the width of my root window, and I select my
//     font so that 80 "m" characters in the "subscript" size fit across
//     it. This provides some attempt at an automatic way to let the font
//     scale with window size.
//
// I set showmathInitialised if I set things up successfully
//
// I believe that this is the only place in the code where I link down to
// a module that uses Xft. That matters to me because at one stage I had a
// platform that failed when I tried to use Xft...
    showmathInitialised =
        ::setupShowMath(application_object, -getDefaultWidth(), this);
    return;
}

void FXTerminal::setEditable(FXbool fg)
{
    FXMathText::setEditable(fg);
}


void FXTerminal::setVisibleRows(FXint rows)
{
#if FOX_MAJOR==1 && FOX_MINOR==0
    FXMathText::setVisRows(rows);
#else
    FXMathText::setVisibleRows(rows);
#endif
}

void FXTerminal::setVisibleColumns(FXint cols)
{
#if FOX_MAJOR==1 && FOX_MINOR==0
    FXMathText::setVisCols(cols);
#else
    FXMathText::setVisibleColumns(cols);
#endif
}

#define UNUSED_ARG(x) ((x) = (x))

long FXTerminal::onCmdPause(FXObject *c, FXSelector sel, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(sel); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    if ((pauseFlags & PAUSE_PAUSE) == 0)
    {   LockMutex(pauseMutex);
        main_window->setTitle("Paused: Type ^Q to resume");
    }
    pauseFlags |= PAUSE_PAUSE;
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

static char window_full_title[90] = "";

long FXTerminal::onCmdResume(FXObject *c, FXSelector sel, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(sel); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    if (pauseFlags & PAUSE_PAUSE)
    {   pauseFlags &= ~(PAUSE_PAUSE | PAUSE_STOP);
        if (pauseFlags & PAUSE_DISCARD)
            main_window->setTitle("Discarding output...");
        else main_window->setTitle(window_full_title);
        UnlockMutex(pauseMutex);
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdStop(FXObject *c, FXSelector sel, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(sel); UNUSED_ARG(ptr);
// At present this is implemented just so it flips the state of the
// pause mutex and flag that ^S and ^Q use. Well I want it to do a bit more!
// I want it to force the worker thread to go into a suspended state. I think
// that for now I am going to allow ^S to halt output when some was due
// anyway, ^Z to pause the worker task soon even if it was not trying to
// generate output, and then when things are suspended either ^Q or another
// ^Z will release them.
    keyFlags &= ~ESC_PENDING;
    if (pauseFlags & PAUSE_PAUSE)
    {   pauseFlags &= ~(PAUSE_PAUSE | PAUSE_STOP);
        if (pauseFlags & PAUSE_DISCARD)
            main_window->setTitle("Discarding output...");
        else main_window->setTitle(window_full_title);
        UnlockMutex(pauseMutex);
    }
    else
    {   LockMutex(pauseMutex);
        main_window->setTitle("Stopped: press ^Z to resume");
        pauseFlags |= (PAUSE_PAUSE | PAUSE_STOP);
// Now to ensure that we hang up SOON I will take steps to provoke a soft
// interrupt. I want this to cause the worker to lock and then instantly
// unlock the pauseMutex...
        if (interrupt_callback != NULL)
        {   int r = (*interrupt_callback)(QUERY_INTERRUPT);
            if (r == 0) (*interrupt_callback)(TICK_INTERRUPT);
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdDiscard(FXObject *c, FXSelector sel, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(sel); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    pauseFlags |= PAUSE_DISCARD;
    main_window->setTitle("Discarding output...");
// I might hit ^O when the last line on the screen is not a complete
// one. I think it is neater to force in a newline here. The "..." is to
// remind the user I have chucked something away.
    FXMathText::appendText("\n...\n", 5);
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

void FXTerminal::appendText(const FXchar *text, FXint n, FXbool notify)
{
    FXMathText::appendText(text, n, notify);
}

void FXTerminal::appendStyledText(const FXchar *text, FXint n, FXint style, FXbool notify)
{
    FXMathText::appendStyledText(text, n, style, notify);
}

void FXTerminal::setStyled(FXbool st)
{
    FXMathText::setStyled(st);
}

// Responses to menu items (and corresponding keyboard shortcuts)

void FXTerminal::type_ahead(int ch)
{
    ahead_buffer[type_in] = ch;
    int p1 = type_in + 1;
    if (p1 == TYPEAHEAD_SIZE) p1 = 0;
    if (p1 == type_out) getApp()->beep();
    else type_in = p1;
}

void FXTerminal::string_ahead(const char *s)
{
    while (*s != 0) type_ahead(*s++);
}

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

static char most_recent_read_file[LONGEST_LEGAL_FILENAME] = ".";

long FXTerminal::onCmdRead(FXObject *c, FXSelector sel, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(sel); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    FXFileDialog opendialog(this, "Read File");
    opendialog.setSelectMode(SELECTFILE_EXISTING);
    opendialog.setFilename(most_recent_read_file);
// If this is not used for REDUCE the following line might well need adjusting
// in an application-sensitive manner.
    opendialog.setPatternList("Reduce Files (*.red,*.tst)\nAll Files (*)");
    const char *s = NULL;
    FXString filename;
    if (opendialog.execute())
    {   filename = opendialog.getFilename();
#if !(FOX_MINOR<=4)
/*
 * For versions before 1.6 I did not have the FXStat package to use. I could
 * re-code this to call ::stat directly but all it does is to filter cases
 * where the user exists the "Read File" dialog without a proper file name
 * in selected.
 */
        if (FXStat::isFile(filename)) 
#endif
            s = filename.text();
        strcpy(most_recent_read_file, s);
    }
    if (s != NULL && *s!=0)
    {   if (isEditable())
        {   killSelection();
            setInputText("", 0);
            appendStyledText("in \"", 4, STYLE_INPUT);
            appendStyledText(s, strlen(s), STYLE_INPUT);
            appendStyledText("\";", 2, STYLE_INPUT);
//
// Here I insert a command in to the input buffer, with a ";" on the end
// of it. I will then wait for the user to type ENTER to accept that, or
// maybe to delete the ";" and replace it with a "$" for silent reading.
//
//          onCmdInsertNewline(c, sel, ptr);
        }
        else
        {   string_ahead("in \"");
            string_ahead(s);
            string_ahead("\";");
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

static char most_recent_save_file[LONGEST_LEGAL_FILENAME] = ".";

long FXTerminal::onCmdSave(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
// Use FXFileDialog::getSaveFilename() here ???
    FXFileDialog d(this, "Save", DECOR_BORDER|DECOR_TITLE);
    d.setFilename(most_recent_save_file);
    d.setPatternList(
        "Log File (*.log)\nAll Files (*)");
    if (d.execute())
    {   FXString ss = d.getFilename();
        const char *s = ss.text();
// It seems plausible here that if I had not specified an explicit extension
// in my file-name that I should tag on ".log"
#define SAVE_BUFFER_SIZE 1024
        char buff[SAVE_BUFFER_SIZE], style[SAVE_BUFFER_SIZE];
        int i = strlen(s) - 1;
        while (i > 0 && s[i]!='.' && s[i]!='/' && s[i]!='\\') i--;
        if (s[i] == '.') strcpy(buff, s);
        else sprintf(buff, "%s.log", s);
        FILE *f = fopen(buff, "w");
        if (f == NULL)
        {   FXMessageBox::error(this, MBOX_OK, "Error",
                "Unable to write to \"%s\"", buff);
            setFocus();
            return 1;
        }
        else
        {   int i = 0;
            strcpy(most_recent_save_file, buff);
            while (i < length)
            {   int n = SAVE_BUFFER_SIZE;
                if (i + n > length) n = length - i;
                extractText(buff, i, n);
// Do I want to do something special with prompt strings? As it is
// I put the extractStyle call here so that I could identify them, but
// I just dump characters regardless.
                extractStyle(style, i, n);
                int n1 = fwrite(buff, 1, n, f);
// expect n1 == n here, unless there was an IO failure
                if (n != n1)
                {   FXMessageBox::error(this, MBOX_OK, "Error",
                        "Writing the file seems to have failed");
                    break;
                }
                i += n;
            }
            fclose(f);  // returns 0 if all is well
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdSaveSelection(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    FXFileDialog d(this, "Save Selection", DECOR_BORDER|DECOR_TITLE);
    d.setFilename(most_recent_save_file);
    d.setPatternList(
        "Log File (*.log)\nAll Files (*)");
    if (d.execute())
    {   FXString ss = d.getFilename();
        const char *s = ss.text();
// It seems plausible here that if I had not specified an explicit extension
// in my file-name that I should tag on ".log"
        char buff[SAVE_BUFFER_SIZE], style[SAVE_BUFFER_SIZE];
        int i = strlen(s) - 1;
        while (i > 0 && s[i]!='.' && s[i]!='/' && s[i]!='\\') i--;
        if (s[i] == '.') strcpy(buff, s);
        else sprintf(buff, "%s.log", s);
        FILE *f = fopen(buff, "w");
        if (f == NULL)
        {   FXMessageBox::error(this, MBOX_OK, "Error",
                "Unable to write to \"%s\"", buff);
            setFocus();
            return 1;
        }
        else
        {   int i = getSelStartPos();
            int len = getSelEndPos();
            strcpy(most_recent_save_file, buff);
            if (len <= i) return 1; // no selection
            while (i < len)
            {   int n = SAVE_BUFFER_SIZE;
                if (i + n > len) n = len - i;
                extractText(buff, i, n);
// Do I want to do something special with prompt strings? As it is
// I put the extractStyle call here so that I could identify them, but
// I just dump characters regardless.
                extractStyle(style, i, n);
                int n1 = fwrite(buff, 1, n, f);
// expect n1 == n here, unless there was an IO failure
                if (n != n1)
                {   FXMessageBox::error(this, MBOX_OK, "Error",
                        "Writing the file seems to have failed");
                    break;
                }
                i += n;
            }
            fclose(f);  // returns 0 if all is well
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

static char most_recent_log_file[LONGEST_LEGAL_FILENAME] = ".";

long FXTerminal::onCmdToFile(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    FILE *oldLogfile = logfile;
// There is a synchronisation issue here. My worker thread tends to
// go
//   FILE *f = logfile;
//   if (f != NULL) <write to it>
// so setting logfile to NULL here will switch logging off, however there
// could be one final write operation to be performed. So what if I do
// a close(logfile) too quickly. Well I think that the write will just fail
// an no desparate harm will ensue. Also I delay the close(logfile) until
// a dialog-box has run for teh user and that will with very very high
// probability leave me totally tidy.
    logfile = NULL;
    FXFileDialog d(this, "Log to File", DECOR_BORDER|DECOR_TITLE);
    d.setFilename(most_recent_log_file);
    d.setPatternList(
        "Log File (*.log)\nAll Files (*)");
    if (d.execute())
    {   fclose(oldLogfile);
        FXString ss = d.getFilename();
        const char *s = ss.text();
// It seems plausible here that if I had not specified an explicit extension
// in my file-name that I should tag on ".log"
        char buff[SAVE_BUFFER_SIZE];
        int i = strlen(s) - 1;
        while (i > 0 && s[i]!='.' && s[i]!='/' && s[i]!='\\') i--;
        if (s[i] == '.') strcpy(buff, s);
        else sprintf(buff, "%s.log", s);
        FILE *f = fopen(buff, "w");
        if (f == NULL)
        {   FXMessageBox::error(this, MBOX_OK, "Error",
                "Unable to write to \"%s\"", buff);
            setFocus();
            return 1;
        }
        strcpy(most_recent_log_file, buff);
        logfile = f;
    }
    else fclose(oldLogfile);
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

// I make my own somewhat arbitrary choice of page margins here.



#define leftmargin_inches    0.5
#define rightmargin_inches   0.5
#define topmargin_inches     0.75
#define bottommargin_inches  1.0

// This prints a section of a row of text, where all the section uses
// the same style. The styles supported here are
//    SELECTED )
//    HILITE   ) these result in colour-effects for the display
//    PROMPT   )
//    INPUT    )
//    CONTROL    this lets control characters print as ^x (and at present
//               it does not behave well wrt line-wrapping, so I hope
//               it never gets used!)

int FXTerminal::printBufferText(FXDCNativePrinter &dc, FXint x, FXint y,
                                 char *str, FXint n, FXuint style)
{
    FXuint index=(style&STYLE_MASK);
    FXColor color;
    color=0;
    if (hilitestyles && index) // Get colors from style table
    {   if (style&STYLE_SELECTED)
            color=hilitestyles[index-1].selectForeColor;
        else if (style&STYLE_HILITE)
            color=hilitestyles[index-1].hiliteForeColor;
        if (color==0)          // Fall back on normal foreground color
            color=hilitestyles[index-1].normalForeColor;
    }
    if (color==0)              // Fall back to default style
    {   if (style&STYLE_SELECTED) color=seltextColor;
        else if (style&STYLE_HILITE) color=hilitetextColor;
        if (color==0) color=textColor;   // Fall back to normal text color
    }
    if (style&FXTerminal::STYLE_PROMPT)
    {   color=promptColor;     // ACN special
    }
    else if (style&FXTerminal::STYLE_INPUT)
    {   color=inputColor;     // ACN special
    }
    dc.setForeground(color);
    if (style&STYLE_CONTROL)
    {   y += dc.fntGetFontAscent();
        FXchar str2[2];
        str2[0]='^';
        while (n!=0)
        {   str2[1]=*str++ | 0x40;
            dc.drawText(x, y, str2, 2);
            x += dc.fntGetTextWidth(str2, 2);
            n--;
        }
    }
    else
    {   y += dc.fntGetFontAscent();
        dc.drawText(x, y, str, n);
        x += dc.fntGetTextWidth(str, n);
    }
    return x;
}

// Here I print one line of text. I let it terminate either at the
// end of a line, or after 80 characters (where a line-wrap is called for)
// or at the end of the buffer. I hand back the index of the start of
// the next line to print after this one. To cope with "styles" this
// scans the buffer spotting runs of characters that agree in their
// style, and send such runs in blocks to printBufferText.


static int charPointer;

static int staticCharForShowMath();

int FXTerminal::printTextRow(FXDCNativePrinter &dc,
                             int p, int y, int left, int right)
{
    int firstThis = p < length ? getChar(p) : 'x';
    int lineend;
    int line = 0;
    if (firstThis == 0x02)
    {   lineend=lineEnd(p);  // I want the true end of the LINE not the end
                             // of the ROW here...
        int realbeg=lineStart(p);
// Now a bit of a messy issue. I may be drawing something that was passed as
// the second or third row of a single formula, but I want to display the
// whole thing. This can arise eg when a window has been scrolled so that
// the top of a formula will not be visible. I will therefore step
// back to the start of the line and adjust my y position accordingly.
        line-=(p-realbeg);
        charPointer = p+1;
// now I may be at something other than the final row of a formula, so I will
// need to skip over any extra 0x02 chars that there might be.
        while (charPointer<length && getChar(charPointer)==0x02) charPointer++;
        int extraLines=charPointer-realbeg-1;
        int h=dc.fntGetFontHeight();
        int extra=extraLines*h;
        int x=right;
        int edge=left;
// Recover the scale that is to be used.
        int scale = getChar(charPointer) & 0xff;
        setMathsFontScale(scale & 0x07);
// Get pointer to box structure for the formula, or NULL if it has been
// discarded because of space limitations.
        Box *b = getBoxAddress(charPointer+1);
        if (b == NULL)
        {   int p = charPointer;
            charPointer += 4;
// Parse again to re-create a box that had gone away. This time it happens
// that my variables are set up so (p+1) is the location for the reference to
// the box, ie the "owner" info.
            b = parseTeX(staticCharForShowMath, p+1);
            if (b == NULL) b = makeTextBox("malformed expression", 20, 0);
            else text->recordBoxAddress(p+1, b);
        }
        measureBox(b);
// I paint the background for math output in a different (a sort of pale
// green) colour to help it starnd out.
        dc.setForeground(FXRGB(230,255,242));
        dc.fillRectangle(edge,y,right-edge,h+extra);
        dc.setForeground(FXRGB(0,0,0));  // render maths in BLACK for now
// Try to centre the formula across the line and within its space
// (well if it was a multi-line formula I try to centre the longest line
// at least roughly, and align the left of all others with that)
        int fh=b->text.height, fd=b->text.depth;
        int delta = (h+extra+fh-fd)/2;
// the next bit is worrying wrt pixels vs print units.
        int xoff = (x - b->text.width)/2;  // This would centre it.
        if (scale >= 0x28)                 // Multi-line formula fun.
        {   scale = (scale - 0x28)/8;      // Space on line in units of
            scale *= mathWidth;            // mathWidth, and now in pixels
            scale /= 2;                    // Now I have indent to centre it.
// Because the recorded "spare" info is not quite reliable I will try to
// adjust it to avoid spilling over edges even in truly dire cases.
            if (scale+b->text.width >= x) scale = x-b->text.width-1;
            if (scale < 0) scale = 0;
            xoff = scale;
        }
// Now actually display the formula!
        paintBox(&dc, b,  xoff, y+delta);
        b->top.measuredSize = -1; // force re-measure when printing finished.
// Whew! Done.
        p = charPointer;
        for (;;)
        {   if (p == length) return p;           // end of buffer
            if (getChar(p) == '\n') return p+1;  // end of line
            p++;
        }
    }
    int column = 0;
    FXuint style = getStyle(p), st = 0;
    int ch = ' ', x = left;
    for (;;)               // collect one line of output, which may end up
    {   char buff[84];     // expressed as multiple segments
        int bp = 0;
        for (;;)           // accumulate a segment
        {   if (p == length) break;       // stop at end of text buffer
            ch = getChar(p);
            if (ch == '\n') break;        // stop at end of this line
            if (column >= 80) break;      // need to wrap the line
            st = getStyle(p);
            if (ch == '\t') break;        // stop before tab
            if (st != style || (st & STYLE_CONTROL)!=0) break;
                                          // stop on style change
            buff[bp++] = ch;
            column++;
            p++;
        }
        if (bp!=0)
        {   x = printBufferText(dc, x, y, buff, bp, style);
        }
        if (p == length) return p;        // end of buffer
        if (ch == '\n') return p+1;       // end of (ordinary) line
        if (column >= 80) return p;       // end of wrapped line
        if (ch == '\t')                   // I ignore styles on tabs!
        {   int blanks = 8 - (column%8);
            x += dc.fntGetTextWidth("        ", blanks);
// Note that since I put tab-stops every 8 positions and my line length
// is 80, a tab can bring me up to the position where a line is about to
// wrap, but it could not cause a wrap in any case where a simple blank
// would not. The long and short of this is that I do not have to do anything
// at all special about line-wrapping here.
            column += blanks;
        }
        else if ((st & STYLE_CONTROL) != 0)
        {   buff[0] = '^';
            buff[1] = ch | 0x40;
// Here I do have a worry about line-wrapping. If I have 79 chars on the line
// already and then I issue a STYLE_CONTROL character it will want to
// print as "^X" for some "X". The "^" can go on the current line but the
// "X" needs to wrap to the next.
//
// I will UNUSED_ARG this issue now (except that I have left room in my buffer
// for slightly overlong lines, and made my wrap-test as ">=80" rather
// then "==80"). Thus in such cases (which my programs will never exercise!)
// the printed output can have a few lines 81 chars long rather than 80.
            x = printBufferText(dc, x, y, buff, 2, st & (~STYLE_CONTROL));
            column += 2;
        }
        else style = st;
        bp = 0;
    }
}


// The next function prints from character startc to endc in the print
// buffer. This may use several pages, depending on the number of lines
// to be printed and the page size. Lines will be wrapped at 80 columns.

void FXTerminal::printContents(FXDCNativePrinter &dc,
    int startc, int endc,
    int left, int right, int top, int bottom)
{
// the size of paper to print on is measured in points, taken here to
// run at 72 points per inch.
    int p = lineStart(startc);
    int hh=dc.fntGetFontSpacing();
    for (int pageNo=1;;pageNo++)
    {   dc.beginPage(pageNo);
        FXint yy = top + hh;
        int inMath = 'S';        // see corresponding screen drawing code
                                 // for an explanation of the logic here.
        while (yy < bottom)
        {
            int c1 = p<length ? 
                     (getStyle(p) & STYLE_MATH ? getChar(p) : 'x') :
                     'x';
            int c2 = p+1<length ? getChar(p+1) : 'x';
            if (inMath == 'S') 
            {   if (c1 == 0x02 && c2 == 0x02)
                {   inMath = 'T';
// This is about to print the top row of a bit of maths. Check how
// many rows in all will be used and whether there is room for them, and if
// not try to insert a page break.
                    int p1 = p+2;
                    int yyy = yy;
                    while (p1 < length && getChar(p1) == 0x02)
                    {   yyy += hh;
                        p1++;
                    }
                    if (yyy >= bottom && yy != top+hh)
                    {   break;   // force this formula to a new page
                    }
                    p = printTextRow(dc, p, yy, left, right);
                }
                else p = printTextRow(dc, p, yy, left, right);
            }
            else
            {   if (c1 != 0x02) p = printTextRow(dc, p, yy, left, right);
                if (c1 != 0x02 || c2 != 0x02) inMath = 'S';
            }
            if (p >= endc) break;
            yy += hh;
        }
        dc.endPage();
        if (p >= endc) break;
    }
    dc.endPrint();
}

// I want to create a font that will be fixed pitch and such that 80
// columns of text go neatly across the width of my paper. This selects
// a plausible choice by first creating a font of almost arbitrary size,
// then measuring the width that it delivers, and on that basis choosing a
// larger or smaller size to use. I use an initial point size of 10
// since that is about the size I expect to end up with.

// Note that the implementation I have here is suitable for a case
// where I have only one font associated with printing.

static void setPrinterFont(FXDCNativePrinter &dc, int pageWidth, const char *font_name)
{
    FXFont *f = dc.fntGenerateFont(font_name, 10, FXFont::Bold);
    f->create();
    dc.setFont(f);
// I will get the width of a string of 10 "M" characters to assess the
// width of my font. On a really clever system if count be other than a
// whole number of points.
    int w = dc.fntGetTextWidth("MMMMMMMMMM", 10);
// The font I have just measured might not have been exactly the size
// font I originally asked for, so I will check what size it was and
// base calculations on that. Note that (ugh) getSize returns the size
// in deci-points not points, so I have a factor of 10 to fudge in
// somewhere. I use the length of my string of "M" characters...
    double bestSize = dc.fntDoubleSize()*(double)pageWidth/(80.0*w);
// Now I think I know the size of font that would suit me best. I
// rather expect it to be 8pt or 9pt, but if the font I was using was
// more expanded or condensed it could stray somewhat from that range.
//
// For a NativePrinter I can specify a font size as a double, so I do
// that here to get as good a fit as I can.
    delete f;
#if (FOX_MINOR<=4)
    f = dc.fntDoubleGenerateFont(font_name, bestSize, FONTWEIGHT_BOLD);
#else
    f = dc.fntDoubleGenerateFont(font_name, bestSize, FXFont::Bold);
#endif
    f->create();
#if FOX_MAJOR==1 && FOX_MINOR==0
    dc.setTextFont(f);
#else
    dc.setFont(f);
#endif
}

long FXTerminal::doPrinting(int startp, int endp)
{
    FXPrintDialog d(this, "Print");
    d.setPrinter(printer);    // carry forward state from previous usage
    if (d.execute())
    {   d.getPrinter(printer);
        FXDCNativePrinter dc(getApp());
        if (!dc.beginPrint(printer))
        {   FXMessageBox::error(this, MBOX_OK, "Printer Error",
                "Unable to print to %s", printer.name.text());
            setFocus();
            return 1;
        }
#define PER_INCH 3600
// For measuring and moving around the page (while I print) I will
// work in terms of units of 1/3600in. This number has been selected so that
// a point (1/72in) is a whole number of units, and so that typical
// real printer resolutions like 300, 600, 720dpi let me work in whole
// numbers of units per pixel. In terms of this resolution an A4 page of
// paper is around 40000 units high - I believe I am a long way from
// running into integer overflow issues. Note that even though I measure
// and specify X and Y coordinates in these units, when I select font
// sized I still need to work in points.
        dc.setHorzUnitsInch(PER_INCH);
        dc.setVertUnitsInch(PER_INCH);
        int pw = dc.getPageWidth();
        int ph = dc.getPageHeight();
#define leftmargin   ((int)(leftmargin_inches*(double)PER_INCH))
#define rightmargin  ((int)(rightmargin_inches*(double)PER_INCH))
#define topmargin    ((int)(topmargin_inches*(double)PER_INCH))
#define bottommargin ((int)(bottommargin_inches*(double)PER_INCH))

// Another delicacy here. On Windows I make my default font "Courier New"
// and if I am doing a windows-print I can and should use that. However
// if I print to file I must use one of the simple Adobe fonts, since
// otherwise the Postscript I generate would need to map font names
// and/or embed detailed font information, and I do not support that!
//
// Well actually setPrinterFont will probably map "Courier New" onto
// "courier" in the relevant case, but it still makes sense that at this
// point I alert the gentle reader to the fact that screen and printer
// fonts may differ.
//
// A yet further qualification to the above commentary is that if I have
// any mathematics displayed via SHOWMATH then I will need to Computer
// Modern fonts to print it (just as I do to display it) and so I WILL embed
// them. For a first version (at least) of this I will embed the whole of
// the three fonts (cmr10, cmmi10, cmsy10 and cmex10) that I use by just
// sending the "*.pfa" files to the printer at the start of the print job.
// If I wanted to be seriously more messy here I could work out just what
// subset of characters I was using and send only those. That seems like way
// too much work for now!
        int widthToUse = pw-leftmargin-rightmargin;
        if (printer.flags&PRINT_DEST_FILE)
            setPrinterFont(dc, widthToUse, "courier");
        else setPrinterFont(dc, widthToUse, DEFAULT_FONT_NAME);
        cmrFontsEmbedded = 0;             // embed at first use: not done yet.
// If I can not select the correct maths font for the printer I will
// suppress printing!
//
// There us a real "jolly" here in that I want the font sizes to be such
// that things fit across the printed page in a way that is roughly the same
// as the way I fit things across the screen. The Fox-level code here
// (and selecting the main printer font) works in scaled abstract units,
// but until and unless I adjust things if I use Xft I would work in
// pixels - whatever they are in the printer case! I think that my best
// resolution is to arrange that I do NOT use Xft when dealing with printer
// fonts. The effect will then be that I use the more ordinary Fox procedures
// to measure everything, and that should lead to some degree of consistency
// without me needing to retrofit Fox-style scaled coordinate systems to
// other stuff I do with FXShowMath.
        void *fontSave[36];
        for (int i=0; i<36; i++)
        {   fontSave[i] = masterFont[i];
            masterFont[i] = NULL;  // NECESSARY!
        }
        if (changeMathFontSize(application_object, -widthToUse))
            printContents(dc, startp, endp,   // which bit needs printing?
                          leftmargin, pw-rightmargin,
                          topmargin, ph-bottommargin);
#if FOX_MAJOR==1 && FOX_MINOR==0
        delete dc.getTextFont();
#else
        delete dc.getFont();
#endif
        for (int i=0; i<36; i++)
        {   masterFont[i] = fontSave[i];
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdPrint(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    return doPrinting(0, length);
}

long FXTerminal::onCmdPrintSelection(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
// This actually prints the lines containing the whole selection...
    return doPrinting(getSelStartPos(), getSelEndPos());
}


// Cut
long FXTerminal::onCmdCutSel(FXObject *, FXSelector, void *)
{
// I will not permit a CUT from anywhere other than part of the current
// input line. I delegate the messy but to COPY.
    if (selstartpos < selendpos &&
        promptEnd <= selstartpos &&
        (options & TEXT_READONLY) == 0)
    {   onCmdCopySel(this, 0, NULL);
// I will only delete the stuff if I managed to copy it to the clipboard,
// which I can tell here by virtue of clipbuffer being reasonable.
        if (clipbuffer)
        {   removeText(selstartpos, selendpos-selstartpos, TRUE);
            killSelection(TRUE);
            setCursorPos(cursorpos, TRUE);
            makePositionVisible(cursorpos);
            flags |= FLAG_CHANGED;
            modified = TRUE;
        }
    }
    else getApp()->beep();
    return 1;
}


// Copy
long FXTerminal::onCmdCopySel(FXObject *, FXSelector, void *)
{
    FXDragType types[2];
    if (selstartpos < selendpos)
    {   types[0]=stringType;
        types[1]=textType;
// I am going to put text onto the clipboard in HTML format - right now
// I am not quite certain how to make an Atom that declares that they is
// the mime type I will use...
        if (acquireClipboard(types, 2))
        {
// Now I am going to want to convert from what I find in the text buffer
// into what I want to place on the clipboard. What I will want to generate
// will be along the lines of
//  <   ->   &lt;    : -> 4
//  >   ->   &gt;    : -> 4
//  &   ->   &amp;   : -> 5
//  \n  ->   <br>    : -> 4+CRLF
//
// POSSIBLY   ' ' -> &nbsp;
//            '"' -> &quo;      but I do not do those transformations yet.
//  
//  <html><body><style>tt.prompt{color:rgb(0,64,128)}</style><tt>   : 61+CRLF
//  Line 1<br>                                                      : +4+CRLF
//  <tt class="prompt">PROMPT:</tt>Line 2<br>                       : +19+5+4
//  Line 3<br>
//  </tt></body></html>                                             : +19
            const char *clipStart   = "<html><body><style>tt.prompt"
                                      "{color:rgb(0,64,128)}"
                                      "</style><tt>\r\n";
            const char *clipEnd     = "</tt></body></html>\r\n";
            const char *prStart     = "<tt class=\"prompt\">";
            const char *prEnd       = "</tt>";
            int style = 0, i;
            cliplength = strlen(clipStart);
            for (i=selstartpos; i<selendpos; i++)
            {   char ch = getChar(i);
                int st = getStyle(i) & STYLE_PROMPT;
                if (st != style)
                {   if (st) cliplength += strlen(prStart);
                    else cliplength += strlen(prEnd);
                    style = st;
                }
                switch (ch)
                {
            case '<':
            case '>': cliplength += 4; break;
            case '&': cliplength += 5; break;
            case '\n':cliplength += 6; break;
            default:  cliplength++;    break;
                }
            }
            if (style) cliplength += strlen(prEnd);
            cliplength += strlen(clipEnd);
            FXFREE(&clipbuffer);
            FXCALLOC(&clipbuffer, FXchar, cliplength+1);
            if (!clipbuffer)
            {   fxwarning("%s::onCmdCopySel: out of memory\n",getClassName());
                cliplength=0;
            }
            else
            {   char *p = clipbuffer;
                strcpy(p, clipStart);
                style = 0;
                p += strlen(clipStart);
// Now I have to copy the selected region mapping it onto the HTML that I
// want it to be. Slightly messy!
                for (i=selstartpos; i<selendpos; i++)
                {   char ch = getChar(i);
                    int st = getStyle(i) & STYLE_PROMPT;
                    if (st != style)
                    {   if (st)
                        {   strcpy(p, prStart);
                            p += strlen(prStart);
                        }
                        else
                        {   strcpy(p, prEnd);
                            p += strlen(prEnd);
                        }
                        style = st;
                    }
                    switch (ch)
                    {
                case '<': strcpy(p, "&lt;");     p += 4; break;
                case '>': strcpy(p, "&gt;");     p += 4; break;
                case '&': strcpy(p, "&amp;");    p += 5; break;
                case '\n':strcpy(p, "<br>\r\n"); p += 6; break;
                default:  *p++ = ch;                     break;
                    }
                }
                if (style)
                {   strcpy(p, prEnd);
                    p += strlen(prEnd);
                }
                strcpy(p, clipEnd);
            }
        }
    }
    return 1;
}


// Paste clipboard

long FXTerminal::onCmdPasteSel(FXObject *, FXSelector, void *)
{
    if (!isEditable() || paste_buffer)
    {   getApp()->beep();
        return 1;
    }
    if (isPosSelected(cursorpos))
    {   removeText(selstartpos, selendpos-selstartpos, TRUE);
        killSelection(TRUE);
        setCursorPos(cursorpos, TRUE);
        makePositionVisible(cursorpos);
        flags |= FLAG_CHANGED;
        modified = TRUE;
    }
    FXchar *string;
    FXint len;
    if (getDNDData(FROM_CLIPBOARD, stringType,
                   (FXuchar*&)string, (FXuint&)len))
        performPaste(string, len);
    return 1;
}


// Paste selection (used for middle mouse button)

long FXTerminal::onCmdPasteMiddle(FXObject *, FXSelector, void *)
{
    if (!isEditable() || paste_buffer)
    {   getApp()->beep();
        return 1;
    }
    FXchar *string; FXint len;
    if (selstartpos==selendpos ||
        cursorpos<=selstartpos ||
        selendpos<=cursorpos)
    {   // Avoid paste inside selection
        if (getDNDData(FROM_SELECTION, stringType,
                       (FXuchar*&)string, (FXuint&)len))
            performPaste(string, len);
    }
    return 1;
}

void FXTerminal::performPaste(FXchar *string, FXint len)
{
    paste_buffer = string;
    paste_n = len;
    paste_p = 0;
    paste_flags = 0;
// Now decide if I think I have an HTML paste. First skip simple whitespace
    while (*string == ' ' || *string == '\r' || *string == '\n')
    {   paste_p++;
        string++;
    }
    if (string[0] == '<' &&
        tolower(string[1]) == 'h' &&
        tolower(string[2]) == 't' &&
        tolower(string[3]) == 'm' &&
        tolower(string[4]) == 'l' &&
        string[5] == '>')
    {   paste_is_html = 1;
        paste_p += 6;
// OK, so in the HTML case I now point at the body of the stuff. I will need
// to ignore HTML tags (both opening and closing) while I transfer stuff, and
// I will want to ignore prompts, which are marked as
//   <tt style="prompt"> ... </tt>
// and I will also want to ignore style declaractions as in
//   <style> ... </style>
// In each case I will suppose that I do not have other HTML blocks nested
// inside.
    }
    else
    {   paste_is_html = 0;
        paste_p = 0;
    }
    if (insertFromPaste()) onCmdInsertNewline(this, 0, NULL);
}

int FXTerminal::isStartPrompt(const char *s)
{
// This is crummy code! It looks for 'tt class="prompt"'
// and allows arbitrary case within "tt" and "class" and whitespace
// there too.
    while (*s!=0 && isspace(*s)) s++;
    if (tolower(*s) != 't') return 0;
    s++;
    if (tolower(*s) != 't') return 0;
    s++;
    while (*s!=0 && isspace(*s)) s++;
    if (tolower(*s) != 'c') return 0;
    s++;
    if (tolower(*s) != 'l') return 0;
    s++;
    if (tolower(*s) != 'a') return 0;
    s++;
    if (tolower(*s) != 's') return 0;
    s++;
    if (tolower(*s) != 's') return 0;
    s++;
    while (*s!=0 && isspace(*s)) s++;
    if (tolower(*s) != '=') return 0;
    s++;
    if (strncmp(s, "\"prompt\"", 8) != 0) return 0;
    return 1;
}

int FXTerminal::isStyle(const char *s)
{
    const char *s0 = s;
    while (*s!=0 && isspace(*s)) s++;
    if (tolower(*s) != 's') return 0;
    s++;
    if (tolower(*s) != 't') return 0;
    s++;
    if (tolower(*s) != 'y') return 0;
    s++;
    if (tolower(*s) != 'l') return 0;
    s++;
    if (tolower(*s) != 'e') return 0;
    s++;
    return (s - s0);
}

int FXTerminal::insertFromPaste()
{
// I will deal with the easy case of plain text pastes first
    if (!paste_is_html)
    {   for (;;)
        {   int ch;
            if (paste_p == paste_n || (ch = paste_buffer[paste_p++]) == 0)
            {   FXFREE(&paste_buffer);
                paste_n = paste_p = paste_is_html = 0;
                return 0;  // all done and finished.
            }
            if (ch == '\r') continue;
            else if (ch == '\n') return 1;
            else insertStyledText(cursorpos, &paste_buffer[paste_p-1], 1, STYLE_INPUT);
        } 
    }
// Inserting from HTML is really rather similar to plain inserting, except
// that I want to process items such as "&lt;", skip HTML tags such
// as </tt> and detect as a special case '<tt type="prompt">'.

    for (;;)
    {   int ch;
        if (paste_p >= paste_n || (ch = paste_buffer[paste_p++]) == 0)
        {   FXFREE(&paste_buffer);
            paste_n = paste_p = paste_is_html = 0;
            return 0;  // all done and finished.
        }
        if (ch == '\r' || ch == '\n') continue;
// Since I only worry about three "&" items here I will write out tests
// in-line. If I had more I ought to set up something table-driven. If I
// really want to handle HTML that comes from other applications I ought
// to think about a LOT more cases... but while my concentration is on
// cut-and-paste to my own code I can remain happy just like this.
        if (ch == '&' && !paste_flags)
        {   if (strncmp(&paste_buffer[paste_p], "lt;", 3)==0)
            {   paste_p += 3;
                if (paste_p > paste_n) continue; // ran over the end
                insertStyledText(cursorpos, "<", 1, STYLE_INPUT);
                continue;
            }
            if (strncmp(&paste_buffer[paste_p], "gt;", 3)==0)
            {   paste_p += 3;
                if (paste_p > paste_n) continue; // ran over the end
                insertStyledText(cursorpos, ">", 1, STYLE_INPUT);
                continue;
            }
            if (strncmp(&paste_buffer[paste_p], "amp;", 4)==0)
            {   paste_p += 4;
                if (paste_p > paste_n) continue; // ran over the end
                insertStyledText(cursorpos, "&", 1, STYLE_INPUT);
                continue;
            }
        }
// In handling HTML tags I will permit lower or upper case, however I
// will not allow extra whitespace. Thus "< br>" or "<br >" will not do!
        if (ch == '<')
        {   if (tolower(paste_buffer[paste_p]) == 'b' &&
                tolower(paste_buffer[paste_p+1]) == 'r' &&
                paste_buffer[paste_p+2] == '>')
            {   paste_p += 3;     // <br> encodes a newline
                paste_flags = 0;
                if (paste_p > paste_n) continue; // ran over the end
                return 1;
            }
            if (isStartPrompt(&paste_buffer[paste_p]) ||
                isStyle(&paste_buffer[paste_p])) paste_flags = 1;
            else paste_flags = 0;
            while (paste_p < paste_n &&
                   paste_buffer[paste_p] != '>') paste_p++;
            paste_p++;  // past the ">"
            continue;
        }
        if (!paste_flags) insertStyledText(cursorpos, &paste_buffer[paste_p-1], 1, STYLE_INPUT);
    } 
}


long FXTerminal::onCmdReinput(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
// "ReInput" acts as a copy, followed by cursor movement to the end of
// the input line, a cancelling of the selection and finally a paste.
    onCmdCopySel(c, s, ptr);
    killSelection(TRUE);  // "deselect all"
    onCmdEnd(c, s, ptr);
    long r = onCmdPasteSel(c, s, ptr);
    setFocus();
    return r;
}

long FXTerminal::onCmdClear(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
// Discard absolutely everything! Including any prompt or currently part-
// completed input-line.
    setText("", 0);
    promptEnd = 0;
    recalc();
    update();
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdRedraw(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
// This is intended for use when a bug or something has left the screen
// corrupted. I hope that what I do here will be enough to force a
// reasonably complete re-draw.
    recalc();
    update();
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdHome(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    makePositionVisible(0);
    setCursorPos(0);
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdEnd(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    int n = rowStart(length);
    makePositionVisible(n);
// The above two encourage the system to do any horizontal scrolls
// that it can to try to make the start of the final line visible
// as well as its end.  Well maybe I will be trying to prevent horizontal
// scrolling anyway, but I will leave this code here since it is
// fairly harmless.
    makePositionVisible(length);
    setCursorPos(length);
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdFont(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
    FXFontDialog d(this, "Font", DECOR_BORDER|DECOR_TITLE);
    FXFontDesc description;
    font->getFontDesc(description);    // information about the current font ..
    strcpy(description.face, font->getActualName().text());
    description.flags =
        (description.flags & ~FXFont::Variable) | FXFont::Fixed;
    d.setFontSelection(description);   // .. and make that default choice!
// I really want to adjust the font-selector dialog so that it only
// shows and accepts fixed-pitch fonts. I am not quite sure how to do
// this yet.
    if (d.execute())
    {   FXFont *o = font;
        d.getFontSelection(description);
        FXFont *newFont = new FXFont(application_object, description);
        newFont->create();
        if (!newFont->isFontMono())
        {   delete newFont;
            FXMessageBox::error(this, MBOX_OK, "Error",
                "You must select a fixed-pitch font");
            return 1;
        }
        setFont(newFont);
        delete o;                     // I must delete the old font.
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdResetFont(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    keyFlags &= ~ESC_PENDING;
// Resets the font (and thus window-width) to my default. This is to give
// some level of safety in case I feel messed up.
    FXFont *o = font;
#if (FOX_MINOR<=4)
    FXFont *f = selectFont(DEFAULT_FONT_NAME, 0,  // 0 means "choose for me"
        FONTWEIGHT_BOLD, FONTSLANT_REGULAR, FONTENCODING_DEFAULT,
        FONTSETWIDTH_DONTCARE, FONTPITCH_FIXED|FONTHINT_MODERN);
#else
    FXFont *f = selectFont(DEFAULT_FONT_NAME, 0,  // 0 means "choose for me"
        FXFont::Bold, FXFont::Straight, FONTENCODING_DEFAULT,
        0, FXFont::Fixed|FXFont::Modern);
#endif
    setFont(f);
    delete o;
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdResetWindow(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
// Put the whole window back in a tidy-ish state
    setVisibleRows(24);
    onCmdResetFont(c, s, ptr);
    int dx = getDefaultWidth()+FXScrollArea::vertical->getDefaultWidth();
    int dy = main_window->getDefaultHeight();
    main_window->getShell()->resize(dx, dy);
    update();     // major changes and so I should refresh everything
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdBreak(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
// I always call the interrupt callback procedure. If the user task was
// suspended waiting for input then I release it causing the fwin_getchar()
// call to return a control-C.
    if (pauseFlags & PAUSE_DISCARD) main_window->setTitle(window_full_title);
    pauseFlags &= ~PAUSE_DISCARD;
    if (interrupt_callback != NULL) (*interrupt_callback)(QUIET_INTERRUPT);
    if (isEditable()) // at present we are waiting for keyboard input.
    {   inputBuffer[0] = 0x1f & 'C';
        inputBuffer[1] = 0;
        inputBufferLen = 1;
        inputBufferP = 0;
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
        recently_flushed = 0;
        FXMathText::appendText("^C", 2);
        long r = FXMathText::onCmdInsertNewline(c, s, ptr);
        setEditable(FALSE);
        setFocus();   // I am uncertain, but without this I lose focus...
        return r;
    }
    type_in = type_out = 0;
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdBacktrace(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
    if (pauseFlags & PAUSE_DISCARD) main_window->setTitle(window_full_title);
    pauseFlags &= ~PAUSE_DISCARD;
    if (interrupt_callback != NULL) (*interrupt_callback)(NOISY_INTERRUPT);
    if (isEditable()) // at present we are waiting for keyboard input.
    {   inputBuffer[0] = 0x1f & 'G';
        inputBuffer[1] = 0;
        inputBufferLen = 1;
        inputBufferP = 0;
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
        recently_flushed = 0;
        FXMathText::appendText("^G", 2);
        long r = FXMathText::onCmdInsertNewline(c, s, ptr);
        setEditable(FALSE);
        setFocus();   // I am uncertain, but without this I lose focus...
        return r;
    }
    type_in = type_out = 0;
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}


// The following are concerned with a list of options and plugins that the
// application may have.

char **modules_list, **switches_list;

long FXTerminal::onCmdLoadModule(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
    FXString ss = ((FXMenuCommand *)c)->getText();
    const char *mtext = ss.text();
    if (isEditable())
    {   killSelection();
        setInputText("", 0);
        appendStyledText("load_package \"", 14, STYLE_INPUT);
        appendStyledText(mtext, strlen(mtext), STYLE_INPUT);
        appendStyledText("\";", 2, STYLE_INPUT);
        onCmdInsertNewline(c, s, ptr);
    }
    else
    {   string_ahead("load_package \"");
        string_ahead(mtext);
        string_ahead("\";\n");
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

long FXTerminal::onCmdFlipSwitch(FXObject *c, FXSelector s, void *ptr)
{
    keyFlags &= ~ESC_PENDING;
    FXMenuCheck *m = (FXMenuCheck *)c;
    FXString ss = m->getText();
    const char *mtext = ss.text();
    int state = m->getCheck();
    const char *cmd;
// The very act of selecting the menu item flipped its state, and so now
// I need to force the underlying system to reflect that by issuing a
// suitable command.
    if (state == TRUE) cmd = "on ";
    else cmd = "off ";
    if (isEditable())
    {   killSelection();
        setInputText("", 0);
        appendStyledText(cmd, strlen(cmd), STYLE_INPUT);
        appendStyledText(mtext, strlen(mtext), STYLE_INPUT);
        appendStyledText(";", 1, STYLE_INPUT);
        onCmdInsertNewline(c, s, ptr);
    }
    else
    {   string_ahead(cmd);
        string_ahead(mtext);
        string_ahead(";\n");
    }
// I also want to record in my table of switches the new state of this one.
    for (char **switches = switches_list; *switches!=NULL; switches++)
    {   char *p = *switches;
        if (strcmp(p+1, mtext) == 0)
        {   if (state == TRUE) *p = 'y';
            else *p = 'n';
            break;
        }
    }
    setFocus();   // I am uncertain, but without this I lose focus...
    return 1;
}

#ifndef WIN32
#if !defined MACINTOSH || !defined MAC_FRAMEWORK

// On Windows I can browse an HTML file using the user's default browser by
// invoking the "ShellExececute" function. On other systems I need to know
// what browser to use, and there is probably no global concept of the
// "preferred" one. So the first time a user tries to access help, or if they
// use a menu entry on the HELP menu, a dialog box for selecting between a
// number of browsers (plus an option for the user to type in a custom name)
// will appear, amd the information so gained gets recorded for future uses.
//

#define NBROWSERS 10

class FXAPI BrowserBox : public FXDialogBox
{
    FXDECLARE(BrowserBox)
public:
    BrowserBox(FXApp *, const char *p);
    BrowserBox();
    void addbutton(FXVerticalFrame *v, const char *name, const char *d);
    long onButton(FXObject *,FXSelector,void *);
    long onText(FXObject *,FXSelector,void *);
    int nbr;
    FXRadioButton *choices[NBROWSERS];
    FXTextField *text;
    char data[40];
    const char *path;
};

FXDEFMAP(BrowserBox) BrowserBoxMap[] =
{
    FXMAPFUNC(SEL_COMMAND,      FXDialogBox::ID_LAST, BrowserBox::onButton),
    FXMAPFUNC(SEL_COMMAND,      FXDialogBox::ID_LAST+1, BrowserBox::onText),
};

FXIMPLEMENT(BrowserBox, FXDialogBox, BrowserBoxMap, ARRAYNUMBER(BrowserBoxMap))

static int file_is_executable(char *filename)
{
    struct stat buf;
    if (*filename == 0) return 0;
    if (stat(filename, &buf) == -1) return 0;
#ifndef S_IXUSR
    return 1;
#else
    return (buf.st_mode & S_IXUSR);
#endif
}


void BrowserBox::addbutton(FXVerticalFrame *v, const char *name, const char *d)
{
    char menuname[256];
// I will start by seeing if I can find the named browser in my PATH
    const char *p = path;
    int found = 0;
    while (*p != 0)
    {   int j = 0;
        while (*p!=0 && *p!=':')
        {   if (j < 240) menuname[j++] = *p;
            p++;
        }
        menuname[j++] = '/';
        strcpy(&menuname[j], name);
        if (file_is_executable(menuname))
        {   found = 1;
            break;
        }
        if (*p!=0) p++;
    }
    if (!found) return;
    menuname[0] = '&';
    strcpy(menuname+1, name);
    menuname[1] = toupper(menuname[1]);
    choices[nbr & 0xff] =
        new FXRadioButton(v, menuname, this, FXDialogBox::ID_LAST);
    if (strcmp(name, d)==0) 
    {   choices[nbr & 0xff]->setCheck();
        nbr += 0x100;  /* flag to say that a default has been set */
    }
    nbr++;
}

BrowserBox::BrowserBox(FXApp *a, const char *p) :
            FXDialogBox(a, "Choose your browser")
{
    strcpy(data, p);
    FXVerticalFrame *v =
        new FXVerticalFrame(this, LAYOUT_FILL_X|LAYOUT_FILL_Y);
// Elsewhere in parts of my code I conditionalise getenv() to force the
// name to upper case when under Windows and to allow for some (ancient?)
// variants on Unix where it takes two arguments. I will not worry about
// either of those issues here.
    path = getenv("PATH");
    int i;
    for (i=0; i<NBROWSERS; i++)
        choices[i] = NULL;
    nbr = 0;
    addbutton(v, "firefox", p);
    addbutton(v, "galeon", p);
    addbutton(v, "konqueror", p);
    addbutton(v, "mozilla", p);
    addbutton(v, "netscape", p);
    addbutton(v, "opera", p);
    choices[nbr & 0xff] = new FXRadioButton(v, "&User:", this, FXDialogBox::ID_LAST);
    FXHorizontalFrame *h0 =
        new FXHorizontalFrame(v,
            LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH);
    new FXLabel(h0, "User command to launch browser:");
    text = new FXTextField(h0, 32, this, FXDialogBox::ID_LAST+1);
    if (nbr <= 0xff)
    {   choices[nbr]->setCheck();
        text->setText(p);
        strcpy(data, p);
    }
    nbr &= 0xff;
    FXHorizontalFrame *h1 =
        new FXHorizontalFrame(v,
            LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH);
    new FXButton(h1, "&OK", NULL, this, FXDialogBox::ID_ACCEPT,
        BUTTON_INITIAL|BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
        LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_CENTER_X);
    new FXButton(h1, "&Cancel", NULL, this, FXDialogBox::ID_CANCEL,
        BUTTON_INITIAL|BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
        LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_CENTER_X);
}

BrowserBox::BrowserBox() : FXDialogBox()
{
}

long BrowserBox::onButton(FXObject *a, FXSelector s, void *p)
{
    for (int i=0; i<NBROWSERS; i++)
    {   if (choices[i] == NULL) continue;
        if (a != choices[i]) choices[i]->setCheck(FALSE);
        else
        {   if (i == nbr)
            {   FXString s = text->getText();
                strcpy(data, s.text());
            }
            else
            {   FXString s = choices[i]->getText();
                strcpy(data, s.text());
                data[0] = tolower(data[0]);
            }
        }
    }
    return 1;
}

long BrowserBox::onText(FXObject *a, FXSelector s, void *p)
{
    for (int i=0; i<NBROWSERS; i++)
    {   if (choices[i] != NULL)
            choices[i]->setCheck(FALSE);
    }
    choices[nbr]->setCheck();
    FXString ss = text->getText();
    strcpy(data, ss.text());
    return 1;
}

static char preferred_browser[40];

static const char *selectBrowser(FXRegistry *reg, const char *preferred)
{
    BrowserBox box(application_object,  preferred);
    int rc = box.execute(PLACEMENT_OWNER);
    if (rc == 1)
    {   strncpy(preferred_browser, box.data, 40);
        preferred_browser[39] = 0;
        preferred = preferred_browser;
        reg->writeStringEntry("browser", "preferred", preferred);
    }
    return preferred;
}

long FXTerminal::onCmdSelectBrowser(FXObject *c, FXSelector s, void *ptr)
{
    FXRegistry *reg = &application_object->reg();
    const char *preferred = reg->readStringEntry("browser", "preferred");
    if (preferred == NULL || *preferred == 0) preferred = "mozilla";
    selectBrowser(reg, preferred);
    setFocus();
    return 1;
}

#endif
#endif

#if defined MACINTOSH && defined MAC_FRAMEWORK

// The code included here comes from an Apple library, and it has its
// redistribution rights listed in comments at its top.

#include "FinderLaunch.c"

#endif

long FXTerminal::onCmdHelp(FXObject *c, FXSelector s, void *ptr)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
// I expect to have a directory called appname.doc in the same place that the
// "appname" executable lives. The directory appname.doc
// should contain a file index.html and a help request will launch a browser
// to inspect that. The user's preferred browser will be recorded in the
// registry in the Unix case, but is dealt with by ShellExecute in the
// Windows case.
#if defined MACINTOSH && defined MAC_FRAMEWORK
    char helpFile[256];
    sprintf(helpFile, "%s.doc/index.html", fwin_full_program_name);
    if (CGDisplayIsActive(CGMainDisplayID()) != 1)
    {   FXMessageBox::error(this,
                MBOX_OK, "Manual Browser Launch Needed",
                "Please browser the file %s", helpFile);

    }
    else if (fork() == 0)
    {
// Attempting to launch a browser in this way seems to cause big trouble
// if you are connected to the Mac via a remote X session. As a really
// heavy-handed way to arrange that this trouble does not spill over and
// disrupt anything else that I am doing I will run the "delicate" procedure
// in a separate fork where ANYTHING that happens should be well isolated.
// The earlier check in CGDisplayIsActive() is supposed to have filtered
// trouble away, but I am going to try to be super careful!
        int n = FinderLaunch(helpFile);
        if (n != noErr)
        {   FXMessageBox::error(this,
                MBOX_OK, "Error",
                "Sorry - help file not available (%s:%d)", helpFile,n);
        }
        exit(0);
    }
#else
#ifdef WIN32
    char helpFile[256];
    GetModuleFileName(NULL, helpFile, 250);
    strcpy(helpFile+strlen(helpFile)-3, "doc");
    HINSTANCE n = ShellExecute(NULL,            // parent window for popup
                              "open",           // verb
                              "index.html",     // file to open
                              NULL,             // parameters to pass
                              helpFile,         // directory to run in
                              SW_SHOWNORMAL);
    if (n <= (HINSTANCE)32)
        FXMessageBox::error(this, MBOX_OK, "Error",
                            "Sorry - help file not available (%p)", n);

#else
    FXRegistry *reg = &application_object->reg();
    const char *preferred = reg->readStringEntry("browser", "preferred");
    if (preferred == NULL || *preferred == 0)
        preferred = selectBrowser(reg, "mozilla");
    char helpFile[256];
    sprintf(helpFile, "file://%s/%s.doc/index.html", programDir, programName);
// For non-windows the browsers I might imagine include
//      netscape, mozilla, opera, firebird, konqueror, galeon, ...
// I will try these in turn. It is probably a politically delicate issue
// which one I try first! If I do not find any then just nothing will
// happen.
    if (fork() == 0)
    {   const char *browsers[] = {
            NULL,
            "opera",
            "mozilla",
            "konqueror",
            "galeon",
            "netscape",
            NULL};
// I put the user's preferred browser as the first to try, but if that
// does not work I try a further bunch.
        browsers[0] = preferred;
        const char **b = browsers;
// As soon as one of these calls to execlp succeeds in launching a browser
// I lose all control, and in particular there is no risk of me ever launching
// two browsers.
        while (*b != NULL)
        {   execlp(*b, *b, helpFile, NULL);
            b++;
        }
// If NONE of the browsers manage to launch I get here. But note that I am in
// a fork, so if I just exit the attempt to browse help will terminate fairly
// cleanly. I might quite like to pop up a dialog box reporting failure but
// to feel save on that I feel I ought to agree with the main fork. Too much
// hassle!!
        fflush(stdout);
        exit(1);
    }
#endif
#endif
    setFocus();
    return 1;
}

long FXTerminal::onCmdAbout(FXObject *c, FXSelector s, void *ptr)
{
// each line of about_box information is limited to 40 chars.
    char msg[5*40+8];
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
    sprintf(msg, 
        "%s\n%s\n%s\n%s\n%s",
        about_box_description,
        about_box_rights_1,
        about_box_rights_2,
        about_box_rights_3,
        about_box_rights_4);
    FXMessageBox about(this, 
        about_box_title,
        msg,
        main_window->getIcon(),
        MBOX_OK|DECOR_TITLE|DECOR_BORDER);
    about.execute(PLACEMENT_OWNER);
    setFocus();
    return 1;
}

int FXTerminal::forceWidth()
{
    int dx = getDefaultWidth()+FXScrollArea::vertical->getDefaultWidth();
    if (dx != main_window->getWidth())
    {   int dy = main_window->getHeight();
        main_window->getShell()->resize(dx, dy);
    }
    return dx;
}

void FXTerminal::setFont(FXFont *font0)
{
    FXMathText::setFont(font0);
    lineSpacing = font0->getFontSpacing();
    setVisibleColumns(80);  // but do not change rows..
    recalc();
    int dx = getDefaultWidth()+FXScrollArea::vertical->getDefaultWidth();
    int dy = main_window->getHeight();
    main_window->getShell()->resize(dx, dy);
// I will force at least the top left of my window to be visible, and if I can
// I will make it all visible.
    int x = main_window->getX(), y = main_window->getY();
    if (x < 0) dx = -x;       // need to move right
    else if (x+dx>rootWidth)  // need to move left
    {   dx = rootWidth - x - dx;
        if (x + dx < 0) dx = -x; // but try to leave left edge visible still
    }
    else dx = 0;
// The next line used to say (y<0) but so that if the window started strictly
// above the screen it got moved down. I now ensure that after the reset the
// window is at least 4 pixels down from the top of the screen. I do this
// because on Linux at least the "main_window" here does not include the
// title bar and other decorations and I need at least a small amount of
// title bar visible if I am to be able to drag the window to re-position it.
// But I am happy to guarantee just 4 pixels not the whole lot...
#define TOPGAP 5
    if (y < TOPGAP) dy = TOPGAP - y;
    else if (y+dy>rootHeight)
    {   dy = rootHeight - y - dy;
        if (y + dy < 0) dy = -y;
    }
    else dy = 0;
    if (dx != 0 || dy != 0) main_window->move(x+dx, y+dy);
// Since the window width has probably changed I should adjust the size of my
// maths font so that thing still fit neatly. However it happens that I
// will call setFont while creating an FXTerminal before the showMath module
// has been initialised, and so I must not try to meddle with it too
// early.
    if (showmathInitialised)
        changeMathFontSize(application_object, -getDefaultWidth());
// The above line has some depths! I insist that if the new set of
// fonts that I want can not be opened that the old lot remain available,
// because otherwise attempts to update the display would crash horribly,
// and I do not have an easy recipe for switching off reliance on fancy
// fonts part way through a run! So failure to open a font when the main
// font size changes will be BAD but its badness will be limited to
// having formulae remain the same size, and future attempts to change font
// size will re-try.
    update();       // major changes and so I should refresh everything
    makePositionVisible(cursorpos);

// Now I update the registry so that when I next start this application
// the same font and screen configuration will apply
    FXRegistry *reg = &(application_object->reg());
    reg->writeStringEntry("screen", "fontname",  font0->getName().text());
    reg->writeIntEntry("screen", "fontsize",     font0->getSize());
    reg->writeIntEntry("screen", "fontweight",   font0->getWeight());
    reg->writeIntEntry("screen", "fontslant",    font0->getSlant());
    reg->writeIntEntry("screen", "fontencoding", font0->getEncoding());
    reg->writeIntEntry("screen", "fontsetwidth", font0->getSetWidth());
    reg->writeIntEntry("screen", "fonthints",    font0->getHints());
}

// Now handlers for the things that get signalled from my worker thread

long FXTerminal::onIPC(FXObject *c, FXSelector s, void *ptr)
{
    char pipe_data[1];
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(ptr);
#ifdef WIN32
    pipe_data[0] = event_code;
#else
    if (read(pipedes[PIPE_READ_PORT], pipe_data, 1) != 1)
    {   fprintf(stderr, "Fatal error attempting to read from pipe\n");
        application_object->exit(1);
        exit(1);
    }
#endif
    switch (pipe_data[0])
    {
default:
        fprintf(stderr, "Fatal error: unknown IPC code %d\n", pipe_data[0]);
        application_object->exit(1);
        exit(1);
case WORKER_EXITING:
        return requestWorkerExiting();
case FLUSH_BUFFER:
        return requestFlushBuffer();
case REQUEST_INPUT:
        return requestRequestInput();
case SET_PROMPT:
        return requestSetPrompt();
case REFRESH_TITLE:
        return requestRefreshTitle();
case SHOW_MATH:
        return requestShowMath();
case SET_MENUS:
        return requestSetMenus();
case REFRESH_SWITCHES:
        return requestRefreshSwitches();
case MINIMIZE_MAIN:
        main_window->minimize();
        return 1;
case RESTORE_MAIN:
        main_window->restore();
        return 1;
    }
}

long FXTerminal::requestWorkerExiting()
{
    if (fwin_pause_at_end)
        FXMessageBox::information(this, MBOX_OK, "Pause at End",
            "Application is exiting");
#ifdef WIN32
    DWORD retval;
    switch (WaitForSingleObject(thread1, 10000))
    {
case WAIT_OBJECT_0:
        if (!GetExitCodeThread(thread1, &retval)) retval = 1;
        CloseHandle(thread1);
        break;
default:
        retval = 1;
    }
#else
    void *p;
    int retval;
    if (!pthread_join(thread1, &p)) retval = *(int *)p;
    else retval = 1 /* joining failed - default to return code of 1 */;
#endif
// I am now ready to stop. By calling FXApp::exit I should get FOX closed
// down tidily, with the registry written back. There is some slight
// uncertainty as to whether FXApp::exit does or should actually quit
// the whole application or just the FOX activity, so I will arrange that
// if it does return then I will stop yet more enthusiastically. And
// to keep compilers from moaning I still make this procedure look as if
// it can return 1 as its result!
    application_object->exit(retval);
    exit(retval);
    return 1;
}

// Since I want to keep things consistent I think I might like to document
// what I expect key-strokes to do:

//============================================================================
//                         KEYBOARD HANDLING
//
//
// Key-bindings that I hope to make work in both terminal and windowed mode,
// on both Unix/Linux, Microsoft Windows and the Macintosh.
// 
// Note that ALT can be achieved either by holding the ALT key at the
// same time as the listed key, or by pressing ESC before the key.
// 
// ALT takes priority over SHIFT, and Control takes priority over ALT so
// that a character is only treated as having one attribute. If it has none
// it just inserts itself.
// 
// Where I put a "-" in this table it means that I do not define the meaning
// of the keystroke. In the short term at least that will either cause the
// keystroke to be ignored, inserted, or treated the same way as the
// corresponding character without Control or ALT. In the longer term I may
// assign behaviours to some of those keys. I also want to reserve the
// possibility of making keys with both Control and ALT have yet different
// effects.
//
//Key   Control              ALT
//
// @    Set Mark             -                    (note this key is not
//                                                 always detected!)
// A    To beginning         [Package load menu]  (also Home key)
// B    Back char            Back word            (also left arrow key)
// C    ^C interrupt         Capitalise word
// D    Delete forward       Delete word          (also the Delete key)
//      Also ^D before any other input on a line sends EOF
// E    To end               [Edit menu]          (also End key)
// F    Forward char         Foward word          (also right arrow key)
// G    ^G interrupt/cancel input         -       <<also escape search mode>>
//
// H    Delete back          Del word back
// I    TAB                  [File menu]          (also TAB key)
// J    Newline              -
// K    Kill line            -
// L    Clear screen         Lowercase word
// M    Newline              -
// N    Next history         Search history next  (also down arrow key)
// O    Discard output       [Font menu]
//
// P    Previous history     Search history prev  (also up arrow key)
// Q    Resume output        -
// R    Redisplay            [Break menu]
// S    Pause output         [Switch menu]
// T    Transpose chars      -
// U    <undo?/escape srch>  Uppercase word
// V    Quoted insert        -
// W    Del Word back        Copy region
//
// X    eXtended command     Obey command
// Y    Yank (=Paste)        -
// Z    Stop execution       -
// [    =ESC: Meta prefix    -
// \    Quit                 -
// ]    -                    -
// _    -                    Copy previous word
// ^    Reinput              -
//
//
// Arrow etc keys...
//
// ->   forward char/word
// <-   backwards char/word
// ^    history prev/search history prev
// v    history next/search history next
// home start line/start buffer
// end  end line/end buffer
//
//
// The items shown as menus behave as follows:
//
// ALT-E C cut
//       O copy
//       P paste
//       R reinput
//       A select all
//       L clear
//       D redraw
//       H home
//       E end
// ALT-I R read
//       S save
//       L save selected text
//       P print
//       N print selected text
//       X exit
// ALT-M   &Module menu shortcut - load a REDUCE module
// ALT-O F select new font
//       R reset to default font
//       W reset font and window to default
// Alt-R C as ^C, interrupt current computation
//       D as ^O, discard pending output
//       G as ^G, interrupt & backtrace current computation
//       P as ^S, pause output
//       R as ^Q, resume output
//       X as ^X, stop current computation
// ALT-S   &Switch menu shortcut - flip a REDUCE switch
//
//
//============================================================================


long FXTerminal::onKeyPress(FXObject *c, FXSelector s, void *ptr)
{
    int ch;
    FXEvent *event = (FXEvent *)ptr;
    const char *history_string = "";
    if (!isEnabled()) return 0;
    switch (event->code)
    {
// Here are some keys that  just want to ignore..
case KEY_Shift_L:
case KEY_Shift_R:
case KEY_Control_L:
case KEY_Control_R:
case KEY_Caps_Lock:
case KEY_Shift_Lock:
case KEY_Meta_L:
case KEY_Meta_R:
case KEY_Alt_L:
case KEY_Alt_R:
case KEY_Super_L:
case KEY_Super_R:
case KEY_Hyper_L:
case KEY_Hyper_R:
case KEY_VoidSymbol:  // used when just ALT (say) is pressed and a
                      // key-repetition event is generated.
        return 1;
    }
// If a previous keystroke had been ESC then I act as if this one
// had ALT combined with it. I will cancel the pending ESC on various
// menu things as well as here. Note that this conversion copes with
// local editing combinations such as ALT-D, but ESC-I does not activate
// a menu the way that ALT-I would have.
    if (keyFlags & ESC_PENDING)
    {   event->state |= ALTMASK;
        keyFlags &= ~ESC_PENDING;
    }
// I will let the Search Pending code drop through in cases where the
// keystroke should be treated as a return to "ordinary" processing. Also
// note that I only expect to find myself in search mode in cases where the
// system is waiting for input.
    if (searchFlags != 0)
    {   int save, r, ls;
        switch (event->code)
        {
    case KEY_h:
            if (!(event->state & CONTROLMASK)) goto defaultlabelsearch;
            if (event->state & ALTMASK) goto defaultlabelsearch;
            // drop through to BackSpace
    case KEY_BackSpace:
// When I delete a character from a search string I will pop the active
// history line back to the first one found when the remaining string
// was searched for. If I delete back to nothing I will leave the input
// line blank.
            if (SEARCH_LENGTH == 0)
            {   getApp()->beep();
                searchFlags = 0;   // cancel searching before it started!
                killSelection(TRUE);
                return 1;
            }
            searchFlags--;
            if (SEARCH_LENGTH == 0)
            {   searchFlags = 0;   // delete the one char in the search string
                killSelection(TRUE);
                setInputText("", 0);
                return 1;
            }
            historyNumber = searchStack[SEARCH_LENGTH];
// The "trySearch" here really really ought to succeed since I have reverted
// to a history line where it succeeded before. I do it again here so I can
// find out where, on that line, the match was so I can establish it as a
// selection.
            startMatch = trySearch();
            history_string = input_history_get(historyNumber);
// ought not to return NULL here!
            ls = setInputText(history_string, strlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection(TRUE);
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCursorPos(ls+startMatch+SEARCH_LENGTH, TRUE);
            return 1;
    case KEY_p:
            if (!(event->state & ALTMASK)) goto defaultlabelsearch;
    case KEY_Up:
            searchFlags &= ~SEARCH_FORWARD;
            searchFlags |= SEARCH_BACKWARD;
            if (historyNumber <= historyFirst)
            {   getApp()->beep();  // already on last possible place
                return 1;
            }
            save = historyNumber;
            historyNumber--;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                getApp()->beep();
                return 1;
            }
            startMatch = r;
            history_string = input_history_get(historyNumber);
            ls = setInputText(history_string, strlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection(TRUE);
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCursorPos(ls+startMatch+SEARCH_LENGTH, TRUE);
            return 1;
    case KEY_n:
            if (!(event->state & ALTMASK)) goto defaultlabelsearch;
    case KEY_Down:
            searchFlags |= SEARCH_FORWARD;
            searchFlags &= ~SEARCH_BACKWARD;
            if (historyNumber >= historyLast)
            {   getApp()->beep();
                return 1;
            }
            save = historyNumber;
            historyNumber++;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                getApp()->beep();
                return 1;
            }
            startMatch = r;
            history_string = input_history_get(historyNumber);
            ls = setInputText(history_string, strlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection(TRUE);
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCursorPos(ls+startMatch+SEARCH_LENGTH, TRUE);
            return 1;
// I detect ^U here and cause it to exit search mode.
    case KEY_u:
            if (!(event->state & CONTROLMASK)) goto defaultlabelsearch;
            searchFlags = 0;
            killSelection(TRUE);
            return 1;
    case KEY_bracketleft:
            if (!(event->state & CONTROLMASK)) goto defaultlabelsearch;
            if (event->state & ALTMASK) goto defaultlabelsearch;
            // drop through to Escape
    case KEY_Escape:       // ctl-[
            keyFlags ^= ESC_PENDING;
            return 1;
    default:
    defaultlabelsearch:
// I suggest "^@" as a sensible character to type to exit from searching.
// Acting on it just "sets the mark" which is typically harmless.
            if ((event->code & ~0xff) != 0 ||
                event->text[1] != 0 ||
                event->state & (CONTROLMASK | ALTMASK))
            {   searchFlags = 0;
                killSelection(TRUE);
                break;
            }
// here I should have a single simple character
            ch = event->text[0];
// and I will filter out control characters... except tab!
            if ((ch & 0xff) < 0x20 && (ch & 0xff) != '\t')
            {   searchFlags = 0;
                killSelection(TRUE);
                break;
            }
// Here I have a further printable character to add to the search
// pattern. If ignore it if the search string has become ridiculously long
// to avoid a buffer overflow.
            if (SEARCH_LENGTH > 250)
            {   getApp()->beep();
                return 1;
            }
            searchString[SEARCH_LENGTH] = ch;
            searchStack[SEARCH_LENGTH] = historyNumber;
            searchFlags++;
            save = historyNumber;
            r = trySearch();
            if (r == -1)
            {   historyNumber = save;
                getApp()->beep();
                searchFlags--;
                return 1;
            }
            startMatch = r;
            history_string = input_history_get(historyNumber);
            ls = setInputText(history_string, strlen(history_string));
// To give a visual indication of what I have found I will select the match,
// which will leave it highlighted on the display. I must remember to kill
// my selection every time I exit search mode!
            killSelection(TRUE);
            setAnchorPos(ls+startMatch);
            extendSelection(ls+startMatch+SEARCH_LENGTH, SELECT_CHARS, TRUE);
            setCursorPos(ls+startMatch+SEARCH_LENGTH, TRUE);
            return 1;
        }
    }
// If the very first character I see is a "^D" it is to be taken as EOF
// rather than as "delete next character".
    if (event->code == KEY_d &&
        event->state & CONTROLMASK &&
        !(keyFlags & ANY_KEYS))
    {   setCursorPos(length);
// I force a Control-D character into the buffer and then pretend that
// a newline had also been typed.
        FXMathText::appendText("\004", 1);
        return onCmdInsertNewline(this, 0, NULL);
    }
// If the very first key I see is "^G" I will raise an exception
// for the user.
    if (event->code == KEY_g &&
        event->state & CONTROLMASK &&
        !(keyFlags & ANY_KEYS)) return onCmdBacktrace(this, 0, NULL);
    keyFlags |= ANY_KEYS;
    ch = 0x00;
    switch (event->code)
    {
case KEY_BackSpace:
        if (event->state & (CONTROLMASK|ALTMASK))
            return editDeleteBackwardWord();
        else return editDeleteBackward();
case KEY_End:
case KEY_KP_End:
// Hmmm - still should I extend a selection if an anchor is set?
// END should probably go to the end of the current line, with ALT-END
// going to the end of the last line.
        if (event->state & (ALTMASK|CONTROLMASK)) return onCmdEnd(c, s, ptr);
        else return editMoveLineEnd();
case KEY_Home:
case KEY_KP_Home:
// OME should probably go to the start of the current active line, with
// ALT-HOME being the thing that goes to top of the screen-buffer.
        if (event->state & (ALTMASK|CONTROLMASK)) return onCmdHome(c, s, ptr);
        else return editMoveLineStart();
case KEY_Left:
        if (event->state & (CONTROLMASK|ALTMASK)) return editPrevWord();
        else return editPrevChar();
case KEY_Right:
        if (event->state & (CONTROLMASK|ALTMASK)) return editNextWord();
        else return editNextChar();
case KEY_Up:
        if (event->state & CONTROLMASK || (options & TEXT_READONLY))
            return onCmdCursorUp(this, 0, NULL);
        else if (event->state & ALTMASK)
            return editSearchHistoryPrev();
        else return editHistoryPrev();
case KEY_Down:
// If you are not waiting for input then cursor up and down just move you up
// and down! If you are waiting for input then Control can be used to break
// you out from the input-line...
        if (event->state & CONTROLMASK || (options & TEXT_READONLY))
            return onCmdCursorDown(this, 0, NULL);
        else if (event->state & ALTMASK)
            return editSearchHistoryNext();
        else return editHistoryNext();
case KEY_Return:
case KEY_Linefeed:
// I always act as if newlines were typed at the very end of the input.
        setCursorPos(length);
        ch = '\n';
        break;
case KEY_Tab:
case KEY_KP_Tab:
        ch = '\t';
        break;
case KEY_at:
// As a default sort of behaviour if my chart of actions shows a key doing
// something interesting with CONTROL but does not specify what happens
// with ALT, I think I will tend to make ALT-x behave like ^x.
        if (event->state & (CONTROLMASK|ALTMASK)) return editSetMark();
        else goto defaultlabel;
case KEY_a:
        if (event->state & (CONTROLMASK|ALTMASK)) return editMoveLineStart();
        else goto defaultlabel;
case KEY_b:
        if (event->state & CONTROLMASK) return editPrevChar();
        else if (event->state & ALTMASK) return editPrevWord();
        else goto defaultlabel;
case KEY_c:
        if (event->state & CONTROLMASK) return editBreak();
        else if (event->state & ALTMASK) return editCapitalize();
        else goto defaultlabel;
case KEY_Delete:
        if (event->state & (CONTROLMASK | ALTMASK)) return editDeleteForwardWord();
        break;
case KEY_d:
// Here I may want to arrange that if the current input-buffer is empty
// then ^D causes and EOF to be returned. Well yes, I have arranged that
// elsewhere so I only get here if the user has typed some chars already.
        if (event->state & CONTROLMASK) return editDeleteForward();
        else if (event->state & ALTMASK) return editDeleteForwardWord();
        else goto defaultlabel;
case KEY_e:
        if (event->state & CONTROLMASK) return editMoveLineEnd();
// ALT-e enters the EDIT menu: this is handled by having the menu
// registered elsewhere.
        else goto defaultlabel;
case KEY_f:
        if (event->state & CONTROLMASK) return editNextChar();
        else if (event->state & ALTMASK) return editNextWord();
        else goto defaultlabel;
case KEY_g:
        if (event->state & (CONTROLMASK | ALTMASK)) return editBacktrace();
        else goto defaultlabel;
case KEY_h:
        if (event->state & CONTROLMASK) return editDeleteBackward();
        else if (event->state & ALTMASK) return editDeleteBackwardWord();
        else goto defaultlabel;
case KEY_i:
// ^I is a TAB
// ALT-i enters the FILE menu
        if (event->state & CONTROLMASK) ch = '\t';
        else goto defaultlabel;
case KEY_j:
        if (event->state & (CONTROLMASK | ALTMASK)) return editNewline();
        else goto defaultlabel;
case KEY_k:
        if (event->state & (CONTROLMASK | ALTMASK)) return editCutLine();
        else goto defaultlabel;
case KEY_l:
// ^L will be CLEAR SCREEN
        if (event->state & ALTMASK) return editLowercase();
        else goto defaultlabel;
case KEY_m:
        if (event->state & CONTROLMASK) return editNewline();
// ALT-m enters the MODULE menu
        else goto defaultlabel;
case KEY_n:
        if (options & TEXT_READONLY)
        {   if (event->state & CONTROLMASK)
                return onCmdCursorDown(this, 0, NULL);
        }
        else
        {   if (event->state & CONTROLMASK) return editHistoryNext();
            else if (event->state & ALTMASK) return editSearchHistoryNext();
        }
        goto defaultlabel;
case KEY_o:
// ^O will be purge output.
//    I hope that by making ^O, ^S and ^Q menu shortcuts they will get
//    acted upon whether I am waiting for input or not.
// ALT-O enters the FONT menu
        goto defaultlabel;
case KEY_p:
        if (options & TEXT_READONLY)
        {   if (event->state & CONTROLMASK)
                return onCmdCursorUp(this, 0, NULL);
        }
        else
        {   if (event->state & CONTROLMASK) return editHistoryPrev();
            else if (event->state & ALTMASK) return editSearchHistoryPrev();
        }
        goto defaultlabel;
case KEY_q:
// ^Q will be RESUME OUTPUT
        if (event->state & ALTMASK) return 1; // Ignore ALT-Q
        goto defaultlabel;
case KEY_r:
        if (event->state & CONTROLMASK) return editRedisplay();
// ALT-r will be the B&reak menu
        goto defaultlabel;
case KEY_s:
// ^S should pause output
// ALT-s enters the SWITCH menu
        goto defaultlabel;
case KEY_t:
        if (event->state & (CONTROLMASK | ALTMASK)) return editTranspose();
        else goto defaultlabel;
case KEY_u:
        if (event->state & CONTROLMASK) return editUndo();
        else if (event->state & ALTMASK) return editUppercase();
        else goto defaultlabel;
case KEY_v:
// ^V will be PASTE and is handled as a shortcut
        goto defaultlabel;
case KEY_w:
// ^W behaviour is just like ALT-H
        if (event->state & CONTROLMASK) return editDeleteBackwardWord();
        else if (event->state & ALTMASK) return editCopyRegion();
        else goto defaultlabel;
case KEY_x:
// Just what these have to do is a mystery to me at present!
// Well that is an overstatement - what I mean is that I am not yet
// implementing anything!
        if (event->state & CONTROLMASK) return editExtendedCommand();
        else if (event->state & ALTMASK) return editObeyCommand();
        else goto defaultlabel;
case KEY_y:
// ^Y is short for YANK, otherwise known as PASTE
        if (event->state & CONTROLMASK) return editPaste();
        else if (event->state & ALTMASK) return editRotateClipboard();
        else goto defaultlabel;
case KEY_z:
// ^Z is short for SUSPEND
        goto defaultlabel;
case KEY_bracketleft:
        if (event->state & CONTROLMASK) return editEscape();
        else goto defaultlabel;
case KEY_Escape:       // ctl-[
// ESC must have the effect of simulating the ALT property for the following
// character.
        return editEscape();
case KEY_backslash:
// ^\ exits the application
        goto defaultlabel;
case KEY_bracketright:
        goto defaultlabel;
case KEY_asciicircum:
        if (event->state & CONTROLMASK) return editReinput();
        goto defaultlabel;
case KEY_underscore:
        if (event->state & ALTMASK) return editCopyPreviousWord();
        goto defaultlabel;

default:
defaultlabel:
        if ((event->code & ~0xff) != 0 ||
            event->text[1] != 0)
            return FXMathText::onKeyPress(c, s, ptr);
// here I should have a single simple character
        ch = event->text[0];
// and I will filter out control characters...
        if ((ch & 0xff) < 0x20) return FXMathText::onKeyPress(c, s, ptr);
        break;
    }
// Now I am left with printable characters plus TAB and NEWLINE. If the
// terminal is waiting for input or if CTRL or ALT was associated with
// the key I delegate.
// @@@ I should really try to check so that when I insert a ")", "]" or
// "}" I look for the corresponding opening bracket and flash it. FXMathText
// has some support for that!
    if (isEditable() ||
        (event->state & (CONTROLMASK|ALTMASK)))
    {   long rr = FXMathText::onKeyPress(c, s, ptr);
// I want the input line to be in a special colour.
        changeStyle(promptEnd, length-promptEnd, STYLE_INPUT);
        return rr;
    }
// I have now delegated everything except simple printable characters
// plus tab, backspace and newline without CTRL or ALT.
// I will interpret backspace as deleting the most recent character
// (if there is one, and not if we get back to a newline). Otherwise
// I just fill a (circular) buffer.
    flags&=~FLAG_TIP;
    if (ch == '\b')  // delete previous character in buffer if there is one
    {   int n = type_in;
        if (--n < 0) n = TYPEAHEAD_SIZE-1;
// I can not delete a character if there is not one there. I will not delete
// it if the previous character was a newline. In such cases I just beep.
        if (type_in == type_out ||
            ahead_buffer[n] == '\n')
        {   getApp()->beep();
            return 1;
        }
        type_in = n;
    }
    else type_ahead(ch);
    return 1;
}

//
// Here I have the procedures that implement each editing action. In
// quite a lot of cases they simply delegate to actions already supported
// by FXMathText, but I have a method for each here because I think it is
// slightly clearer to have all the entrypoints visible in one place.
//

//
// Something I have NOT fitted quite carefully enough to all this is
// arrangements that I ignore things if not waiting for input and force
// the cursor to the final line in relevant cases.
//

// ^@   set mark, ie start a selection

int FXTerminal::editSetMark()
{
// This is in fact just an operation that FXMathText already supports.
    return onCmdMark(this, 0, NULL);
}

// ^A   move to start of current line (after any prompt text!)

int FXTerminal::editMoveLineStart()
{
    int n = lineStart(cursorpos);
    makePositionVisible(n);
    while (n < length && (getStyle(n) & STYLE_PROMPT)) n++;
    makePositionVisible(n);
    setCursorPos(n);
// If the mark is set maybe I should extend the selection...
    return 1;
}

// ^B  move back a character

int FXTerminal::editPrevChar()
{
// If the mark is set maybe I should extend the selection...?
// If I am accepting input I will not let the user move backwards into the
// prompt string.
    if ((options && TEXT_READONLY) == 0 &&
        cursorpos == promptEnd)
    {   getApp()->beep();
        return 1;
    }
    return onCmdCursorLeft(this, 0, NULL);
}

// ALT-B move back a word

int FXTerminal::editPrevWord()
{
// If the mark is set maybe I should extend the selection...?
// If I am accepting input I prevent the user from moving back past where the
// prompt string ends. I beep if I make no move at all.
    int w = cursorpos;
    if ((options & TEXT_READONLY) == 0 && w == promptEnd)
    {   getApp()->beep();
        return 1;
    }
    onCmdCursorWordLeft(this, 0, NULL);
    if ((options && TEXT_READONLY) == 0 &&
        w > promptEnd &&
        cursorpos < promptEnd) setCursorPos(promptEnd);
    return 1;
}

// ^C  abandon input, returning an exception to user

int FXTerminal::editBreak()
{
// Note that ^C generates a break action whether I am waiting for input or not.
    return onCmdBreak(this, 0, NULL);;
}

// ALT-c  capitalize a word

int FXTerminal::editCapitalize()
{
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    char wordbuffer[64];
    int cp = cursorpos;
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
    setCursorPos(cp);
    makePositionVisible(cp);
    return 1;
}

// ^D  delete character under cursor (fowards)

int FXTerminal::editDeleteForward()
{
    if (!isEditable())     // side effect is to move to last line if necessary
    {   getApp()->beep();
        return 1;
    }
    return onCmdDelete(this, 0, NULL);
}

// Should this do special things (a) if there is a selection or (b)
// if there is a selection and the cursor is within it?

// ALT-d  delete word forwards

int FXTerminal::editDeleteForwardWord()
{
    if (!isEditable())     // side effect is to move to last line if necessary
    {   getApp()->beep();
        return 1;
    }
    return onCmdDeleteWord(this, 0, NULL);
}

// ^E  move to end of current line

int FXTerminal::editMoveLineEnd()
{
// extend selection?
    return onCmdCursorEnd(this, 0, NULL);
}

// ^F  forward one character

int FXTerminal::editNextChar()
{
// If the mark is set maybe I should extend the selection...
    return onCmdCursorRight(this, 0, NULL);
}

// ALT-F  forward one word

int FXTerminal::editNextWord()
{
// If the mark is set maybe I should extend the selection...
    return onCmdCursorWordRight(this, 0, NULL);
}

// ^G   If it was the very very first character typed or if I am not
//      waiting for input, ^G raises an interrupt. If I am waiting for
//      input and have not typed anything much then it clears the current
//      input line leaving me back with a fresh start. I will make that so
//      fresh that ^G^G guarantees an interrupt!

int FXTerminal::editBacktrace()
{
    if (!isEditable()) return onCmdBacktrace(this, 0, NULL);
    killSelection();
    setInputText("", 0);
    historyNumber = historyLast + 1;
    keyFlags &= ~ANY_KEYS;
    return 1;
}

// ^H  (backspace) delete char before cursor if that is reasonable.

int FXTerminal::editDeleteBackward()
{
    switch (isEditableForBackspace())
    {
default:                // within the area for active editing.
        return FXMathText::onCmdBackspace(this, 0, NULL);
case -1:                // current input line is empty.
case 0:                 // input is not active
        getApp()->beep();
        return 1;
    }
}

// ALT-h  delete previous word

int FXTerminal::editDeleteBackwardWord()
{
    int pos;
    switch (isEditableForBackspace())
    {
default:                // within the area for active editing.
// I want to be confident that whatever prompt string has been set the
// following will never delete part of the prompt...
        pos = leftWord(cursorpos);
        if (pos < promptEnd) pos = promptEnd;
        removeText(pos, cursorpos-pos, TRUE);
        setCursorPos(cursorpos, TRUE);
        makePositionVisible(cursorpos);
        flags |= FLAG_CHANGED;
        modified = TRUE;
        return 1;
case -1:                // current input line is empty.
case 0:                 // input is not active
        getApp()->beep();
        return 1;
    }
}

// ^I was just a TAB and has been handled elsewhere

// ^J (linefeed) accepts the current line of text

int FXTerminal::editNewline()
{
    setCursorPos(length);
    return onCmdInsertNewline(this, 0, NULL);
}

// ^K  kill current line
// Note that ^G and ^U are somewhat related, and that I do not
// do anything by way of putting cut text into a kill-buffer, or allowing the
// user to make selections using the keyboard...

int FXTerminal::editCutLine()
{
    killSelection();
    setInputText("", 0);
    return 1;
}

// ^L    clear screen (handled as menu shortcut)

// ALT-L convert to lower case

int FXTerminal::editLowercase()
{
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    char wordbuffer[64];
    int cp = cursorpos;
    int ws = wordStart(cp);
    if (ws < promptEnd) ws = promptEnd;
    int we = wordEnd(cp);
    if (we > ws + 63) we = ws + 63;
    extractText(wordbuffer, ws, we-ws);
    int i;
    for (i=0; i<we-ws; i++)
        wordbuffer[i] = tolower(wordbuffer[i]);
    replaceStyledText(ws, we-ws, wordbuffer, we-ws, STYLE_INPUT);
    setCursorPos(cp);
    makePositionVisible(cp);
    return 1;
}

// ^M  as ENTER, ^J

// ALT-M  a &Module menu

// ^N  history next if we are at present on the bottom line
//     otherwise move down a line
// (also down-arrow key)

// To replace the input line I can can use this... It returns the
// index of the first character of the inserted line.

int FXTerminal::setInputText(const FXchar *text, int n)
{
    int n2 = length;
    int n1 = lineStart(n2);
    while (n1 < n2 && (getStyle(n1) & STYLE_PROMPT)) n1++;
    replaceStyledText(n1, n2-n1, text, n, STYLE_INPUT);
//    changeStyle(n1, length-n1, STYLE_INPUT);  // paint it the right colour
    setCursorPos(length);
    makePositionVisible(length);
    return n1;
}


// The history routines here are never invoked unless we are awaiting input

int FXTerminal::editHistoryNext()
{
    const char *history_string;
    if (historyLast == -1) // no history lines at all to retrieve!
    {   getApp()->beep();
        return 1;
    }
    if (historyNumber < historyLast) historyNumber++;
    if ((history_string = input_history_get(historyNumber)) == NULL)
    {   getApp()->beep();
        return 1;
    }
    setInputText(history_string, strlen(history_string));
    return 1;
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

int FXTerminal::editSearchHistoryNext()
{
    if (historyLast == -1) // no history to search
    {   getApp()->beep();
        return 1;
    }
// If I am not in a search at present then set the flag for a search
// with an empty search string and a mark that the direction is forwards.
// Well if I not only am not in a search but I had not previously scrolled
// back in the history so I have nowhere to search then I might as well
// beep and give up.
    if (historyNumber > historyLast)
    {   getApp()->beep();
        return 1;
    }
    searchFlags = SEARCH_FORWARD;
    return 1;
}

int FXTerminal::trySearch()
{
    int r = -1;
    const char *history_string = input_history_get(historyNumber);
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
        history_string = input_history_get(historyNumber);
        if (history_string == NULL) return -1;
    }
    return r;
}

int FXTerminal::matchString(const char *pat, int n, const char *text)
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


// ^O  abandon pending output. Menu shortcut

// ^P  history previous if we are on bottom line
//     [else cursor up????]
// (also uparrow key)

int FXTerminal::editHistoryPrev()
{
    const char *history_string;
    if (historyLast == -1) // no previous lines to retrieve
    {   getApp()->beep();
        return 1;
    }
// If I have not moved the history pointer at all yet move it into the
// range of valid history entries.
    if (historyNumber > historyFirst) historyNumber--;
    history_string = input_history_get(historyNumber);
    if (history_string == NULL)
    {   getApp()->beep();
        return 1;
    }
    setInputText(history_string, strlen(history_string));
    return 1;
}

// ALT-P  reverse search

int FXTerminal::editSearchHistoryPrev()
{
    if (historyLast == -1) // no history to search
    {   getApp()->beep();
        return 1;
    }
    if (historyNumber == historyLast + 1) historyNumber--;
    searchFlags = SEARCH_BACKWARD;
    return 1;
}

// ^Q  unpause output (see ^Z, ^S) treated as menu shortcut


// ^R  Redisplay

int FXTerminal::editRedisplay()
{
    return onCmdRedraw(this, 0, NULL);
}

// ^S as pause output is handled as a shortcut so that it can be
// accepted whether or not I am awaiting input.

// ^T  transpose

int FXTerminal::editTranspose()
{
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    char buff[2];
    int cp = cursorpos;
    if (cp > length-2)
    {   getApp()->beep();
        return 1;
    }
    extractText(buff, cp, 2);
    int ch;
    ch = buff[0];
    buff[0] = buff[1];
    buff[1] = ch;
    replaceStyledText(cp, 2, buff, 2, STYLE_INPUT);
    setCursorPos(cp);
    makePositionVisible(cp);
    return 1;
}

// ^U  reserved for UNDO, and also exits search mode.

int FXTerminal::editUndo()
{
// @@@@@
    return 1;
}

// ALT-U convert to upper case

int FXTerminal::editUppercase()
{
// I arbitrarily limit the length of a word that I casefix to 63
// chars.
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    char wordbuffer[64];
    int cp = cursorpos;
    int ws = wordStart(cp);
    if (ws < promptEnd) ws = promptEnd;
    int we = wordEnd(cp);
    if (we > ws + 63) we = ws + 63;
    extractText(wordbuffer, ws, we-ws);
    int i;
    for (i=0; i<we-ws; i++)
        wordbuffer[i] = toupper(wordbuffer[i]);
    replaceStyledText(ws, we-ws, wordbuffer, we-ws, STYLE_INPUT);
    setCursorPos(cp);
    makePositionVisible(cp);
    return 1;
}

// ^V  shortcut for PASTE

// ^W  delete previous word just as ALT-H

// ALT-W  Copy region

int FXTerminal::editCopyRegion()
{
// @@@@@
    return 1;
}

// ^X  extended command

int FXTerminal::editExtendedCommand()
{
// @@@@@
    return 1;
}

// ALT-X  obey command

int FXTerminal::editObeyCommand()
{
// @@@@@
    return 1;
}


// ^Y  paste

int FXTerminal::editPaste()
{
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    return onCmdPasteSel(this, 0, NULL);
}

// ALT-y rotate killbuffer/clipboard

int FXTerminal::editRotateClipboard()
{
// @@@@@
    return 1;
}

// ^Z is a keyboard shortcut to pause execution

// ALT-[, ESCAPE

int FXTerminal::editEscape()
{
    keyFlags ^= ESC_PENDING; // so that ESC ESC cancels the effect.
    return 1;
}

// ^\   exit the application (menu shortcut)
// ^]   unused

// ^^   re-input (= COPY/PASTE)

int FXTerminal::editReinput()
{
    if (!isEditable())
    {   getApp()->beep();
        return 1;
    }
    return onCmdReinput(this, 0, NULL);
}

// ALT-_  copy previous word

int FXTerminal::editCopyPreviousWord()
{
// @@@@@
    return 1;
}


// Return true if editable, which here is used as
// a mark of whether the user has requested input.

FXbool FXTerminal::isEditable()
{
    if ((options&TEXT_READONLY)!=0) return FALSE;
// If we are asking if the FXTerminal is editable that is because we
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
    if (cursorpos < n) setCursorPos(length);
// Furthermore if I am about to change thing I will ensure that any
// selection lies within the active line.
    if (selstartpos < n) selstartpos = n;
    if (selendpos < selstartpos) selendpos = selstartpos;
    return TRUE;
}

// Return true if editable, to be used when the next operation would
// be a BACKSPACE (delete-previous). It must thus shift the cursor to
// avoid deleting the final character of the prompt string.

int FXTerminal::isEditableForBackspace()
{
    if ((options&TEXT_READONLY)!=0) return 0;  // must buffer the action
    int n = lineStart(length);
    makePositionVisible(n);
    while (n < length && (getStyle(n) & STYLE_PROMPT)) n++;
    makePositionVisible(length);
// The next line has "<=" where the previous function has just "<"
    if (cursorpos <= n) setCursorPos(length);
// Furthermore if I am about to change thing I will ensure that any
// selection lies within the active line.
    if (selstartpos < n) selstartpos = n;
    if (selendpos < selstartpos) selendpos = selstartpos;
    if (n == length) return -1; // nothing that I am allowed to delete
    return 1;
}

// #define INPUT_BUFFER_LENGTH 512   (in header file)
// int inputBufferLen = 0;
// int inputBufferP = 0;
// char inputBuffer[INPUT_BUFFER_LENGTH];

int recently_flushed = 0;

long FXTerminal::onCmdInsertNewline(FXObject *c, FXSelector s, void *ptr)
{
// Note that the 3 args to this procedure are never used!
    FXint p = length;
// I find the first "real" character of the input line by scanning back
// to (a) the start of the buffer (b) the end of a previous line or (c) the
// end of a prompt string.
    while (p>0 && getChar(p-1)!='\n' && (getStyle(p-1)&STYLE_PROMPT)==0) p--;
    FXint n = length-p;
    if (n > (int)sizeof(inputBuffer)-5) n = sizeof(inputBuffer)-5;
    extractText(inputBuffer, p, n);
// I enter the line that has just been collected into the history
// record.
    inputBuffer[n] = 0;
    input_history_add(inputBuffer);
// Adding an entry could cause an old one to be discarded. So I now ensure
// that I know what the first and last recorded numbers are.
    historyLast = input_history_next - 1;
    historyFirst = input_history_next - INPUT_HISTORY_SIZE;
    if (historyFirst < 0) historyFirst = 0;
    historyNumber = historyLast + 1; // so that ALT-P moves to first entry
// Now I add a newline to the text, since the user will expect to see that.
    inputBuffer[n] = '\n';
    inputBuffer[n+1] = 0;
    inputBufferLen = n+1;
    inputBufferP = 0;
// Stick a newline into the text buffer, and make the screen non-updatable.
    FXMathText::onCmdInsertNewline(c, s, ptr);
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
    return 1;
}

long FXTerminal::requestFlushBuffer()
{
    recently_flushed = 0;
// here the worker thread is locked waiting for mutex2, so I can afford to
// adjust fwin_in and fwin_out.
    if (sync_even)
    {   LockMutex(mutex1);
        if (fwin_in != fwin_out && (pauseFlags & PAUSE_DISCARD) == 0)
        {   if (fwin_in > fwin_out)
                FXMathText::appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out);
            else
            {   FXMathText::appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE-fwin_out);
                FXMathText::appendText(&fwin_buffer[0], fwin_in);
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
                FXMathText::appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out);
            else
            {   FXMathText::appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE-fwin_out);
                FXMathText::appendText(&fwin_buffer[0], fwin_in);
            }
            makePositionVisible(rowStart(length));
        }
        fwin_out = fwin_in = 0;
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}

static int staticCharForShowMath()
{
    return text->charForShowMath();
}

int FXTerminal::charForShowMath()
{
    if (charPointer >= length) return 0;
    int c = getChar(charPointer);
    if (c == '\n') return 0;
    charPointer++;
    return c;
}

void FXTerminal::insertMathsLines()
{
    const char *p = fwin_maths;
    int start = length;
    int linecount = 0;
    while (*p != 0)
    {   while (*p!=0 && *p!='\n') p++;
        if (*p=='\n') p++;
// 0x02  is a lead-in to introduce the maths data, and it exists because
//       at a higher level I want to map one line of maths onto several
//       rows. I will end up (later on) with one 0x02 for each row to be used.
//       HOWEVER for reasons that convince at least me I will start by
//       inserting 0x21 where (0x20+n) will be used to indicate a line of
//       maths that needs n rows...
// 0x24  is a scale marker. I use 0x20 to 0x24 for the 5 different scales at
//       which I can render mathematics.
//       In fact I will use the buttom 3 bits for a scale, and the
//       remaining 5 bits to help me position multi-line formulae neatly.
//       0x28 to 0xf8 can give an indent hint value in that case.
// 0,0,0 is a 3-byte gap that will be used to hold a handle to the box-
//       structure representing the given line of the mathematical formula.
//       The handle will use 7-bits per byte so I have 21-bits here.
// Note that when I parse a bit of TeX I may run out of memory in the
// area reserved for box structures, and in that case I will discard some
// old box. When I do so I want to be able to identify the reference to it
// so I can mark it as stale. That is achieved by having the maths display
// parsing code hold a reference back into my text buffer so it can clobber
// the reference. For this to work it is VITAL that the text buffer should not
// change under the feet of the box-management package. This is an ugly
// constraint and probably shows that the two chunks of code need a tighter
// interface...
        FXMathText::appendStyledText("\x21\x84\x00\x00\x00", 5, STYLE_MATH);
        FXMathText::appendStyledText(fwin_maths, p-fwin_maths, STYLE_MATH);
        linecount++;
        fwin_maths = p;
    }
    int scale = 4;
    int p1 = start;
    while (p1<length)
    {   charPointer = p1+5;
// First parse the line of stuff to get a box-structure. The parsed box gets
// a reference back to position p1+2 in the text buffer since that is where
// the reference will be put.
        Box *b = parseTeX(staticCharForShowMath, p1+2);
// Style 0 in makeTextBox gives Roman typeface at normal size.
// Note that the blank in this message will be displayed as a sort of "`".
// There is no blank in the Roman font that I use here!!!!!
        if (b == NULL) b = makeTextBox("malformed expression", 20, 0);
// Remember where the box is. Note that if it gets discarded as I parse
// another box later on this reference will be replaced with a zero.
        text->recordBoxAddress(p1+2, b);
// Measure it at the current scale
        setMathsFontScale(scale);
        measureBox(b);
// If it is too wide then I will try to scale it down until it looks as if it
// will fit. When I do that I will measure all subsequent lines at the new
// reduced scale. But previously-measured boxes may need revision in a later
// pass over the data.
        while (b->text.width > text->getDefaultWidth() && scale>0)
        {   setMathsFontScale(--scale);
            measureBox(b);
        }
// Move on to the next line. Note that I arrange that any special info I
// put in the buffer will NEVER include a newline character!
        while (p1<length && getChar(p1)!='\n') p1++;
        if (p1 < length) p1++;
    }
// Now I take a second pass, and in this second pass I will sort out just how
// many rows each line will need, and insert markers to record this. I can
// also find the greatest width present in a multi-line display.
    int maxWidth = 0;
    p1 = start;
    while (p1<length)
    {
// Recover the box so I can re-measure it.
        Box *b = getBoxAddress(p1+2);
// If it has been discarded then the recovered pointer will be NULL
// so I re-parse the LaTeX.
        if (b == NULL)
        {   charPointer = p1+5;
// Again I should tell the box that its "owner" is the place in the
// text buffer where the pointer to it lives. (p1+2) here.
            b = parseTeX(staticCharForShowMath, p1+2);
            if (b == NULL) b = makeTextBox("malformed expression", 20, 0);
        }
// Measure it (again) at the current scale. In simple cases the effect here
// is that the measureBox() call gets done twice in an unnecessary way. I
// will let that happen and count simplicity in this code more important that
// efficiency!
        setMathsFontScale(scale);
        measureBox(b);
// By now the line is expected to fit (horizontally). I arranged that on
// my first pass. However I will want to do a bit more magic on multi-line
// formulae.
// Record the scale that is to be used.
        replaceStyledText(p1+1, 1, "\x20\x21\x22\x23\x24"+scale,
            1, STYLE_MATH);
        if (b->text.width > maxWidth) maxWidth = b->text.width;
        int h = b->text.height + b->text.depth;  // height
        FXint hh=font->getFontHeight();         // row height
// Work out how many rows are needed to let this line of maths fit in. I will
// insist that I have at least 0.33 or the row height spare (I will distribute
// that evenly above and below the formula in the display).
        int nrows = (h+hh+hh/3)/hh;
// However as a SPECIAL CASE if the data forms part of a multi-line display
// and this line is just a single item consisting of a string of digits
// then I will force it to use up just one row. This is to try to make the
// display of very big numbers look more sensible.  The macro BoxText is
// defined in FXShowMath.cpp and is mostly private to there...
#define BoxText 0
        if (linecount!=1 && b->top.sub->text.type == BoxText)
        {   char *ss = b->top.sub->text.text;
            int nn = b->top.sub->text.n;
            while (--nn >= 0) if (!isdigit(ss[nn])) break;
            if (nn < 0) nrows = 1;
        }
// Right now I hold a row-count in a byte such that the largest count that
// can be stored is 223. I guess that a tall array could use more than this!
// But for a first stab at this code I will not treat that case too seriously 
// and I will arbitrarily limit row counts. I guess it would be easy to
// use 2 bytes here and end up with a limit at around 50000 that should deal
// with all even half sane cases. But that is for later on.
        if (nrows > 0xdf) nrows = 0xdf;
// Now record how many rows are needed. Note that I do this without
// disturbing the layout of the text buffer.
        char heightString[1];
        heightString[0] = 0x20 + nrows;
        replaceStyledText(p1, 1, heightString, 1, STYLE_MATH);
        while (p1<length && getChar(p1)!='\n') p1++;
        if (p1 < length) p1++;
    }
// A third pass turns the lead-in bytes that are at present in the form
// 0x20+rowCount into a sequence of 0x02 chars. The reason I need to
// encode the number of rows used by a formula in unary this way is that
// to fit in with the rest of FXMathText I need to view the display as
// composed of rows, and I need locations within the buffer that can
// stand for the start of each row.
// When I insert the extra characters here the result will be that
// back-pointers from boxes into the text buffer will become incorrect, so
// I need to correct them all. I do not do ANY operations that could
// involve allocating new boxes during this phase and so I will never follow
// a back-pointer while it is broken...
    int spare = (text->getDefaultWidth() - maxWidth)/mathWidth;
    if (spare < 0) spare = 0; // should never happen!
    spare = 8*spare + 0x28;
    if (spare > 0xf8) spare = 0xf8;
    if (linecount == 1) spare = 0x20;
// The above has set up spare to be a messy byte that is there to help with
// multi-line formulae. The bottom 3 bits are a scale to render at. The top
// 5 bits show 0x20 for a 1-line formula (which I will centre), or
// a value bigger than that for any multi-line formulae, and the value then
// gives info about how much spare space there should be on the longest
// line in the entire formula.
    char spareBytes[2];
    spareBytes[0] = 0x02;
    spareBytes[1] = spare;
    p1 = start;
    while (p1<length)
    {   int heightCode = (getChar(p1) & 0xff) - 0x20;
        spareBytes[1] = spare + (getChar(p1+1) & 0x07);
        replaceStyledText(p1, 2, spareBytes, 2, STYLE_MATH);
        while (heightCode > 1)
        {   insertStyledText(p1, "\x02", 1, STYLE_MATH);
            heightCode--;
            p1++;
        }
        Box *b = getBoxAddress(p1+2);
// If it has been discarded then the recovered pointer will be NULL
// and so there will be no need to reset a back pointer.
        if (b != NULL) updateOwner(b, p1+2);
        while (p1<length && getChar(p1)!='\n') p1++;
        if (p1 < length) p1++;
    }
// Now I think everything is in a consistent state ready for display!
}

Box *FXTerminal::getBoxAddress(int p) const
{
    int c1 = getChar(p),
        c2 = getChar(p+1),
        c3 = getChar(p+2);
    if (c1 == 0) return NULL;
    int n = (c1&0x7f) + ((c2&0x7f) << 7) + ((c3&0x7f) << 14);
    Box *b=(Box *)poolPointerFromHandle(n);
    return b;
}

void FXTerminal::recordBoxAddress(int p, Box *b)
{
    char s[3];
    int c1=0, c2=0, c3=0;
    if (b != NULL)
    {   int n = handleFromPoolPointer(b);
        c1 = (n & 0x7f) + 0x80,
        c2 = ((n>>7) & 0x7f) + 0x80;
        c3 = ((n>>14) & 0x7f) + 0x80;
    }
    s[0] = c1;
    s[1] = c2;
    s[2] = c3;
    replaceStyledText(p, 3, s, 3, STYLE_MATH);
}

// This curious function is a call-back from FXShowMath and is invoked
// when a box-structure gets destroyed (they get destroyed on a cyclic basis
// when memory starts to get full). It zeros out the record here of where the
// box structure is, and as a result any future attempt to re-pain that
// bit ofthe display will provoke a re-parse and thus a re-creation of
// the data (which will presumably displace some other boxes...). Also the
// call-back wants to be a simple C function but to update my buffer I need to
// regain class access...

void reportDestroy(int p)
{
    if (text != NULL) text->reportDestroy(p);
}

void FXTerminal::reportDestroy(int p)
{
    replaceStyledText(p, 3, "\x00\x00\x00", 3, STYLE_MATH);
}

long FXTerminal::requestShowMath()
{
    recently_flushed = 0;
    if (length != 0 && getChar(length-1) != '\n')
        FXMathText::appendText("\n", 1); // terminate any pending line
    if (sync_even)
    {   LockMutex(mutex1);
        insertMathsLines();
        makePositionVisible(rowStart(length));
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        insertMathsLines();
        makePositionVisible(rowStart(length));
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}


static char promptString[MAX_PROMPT_LENGTH] = "> ";
static int promptLength = 2;

long FXTerminal::requestSetPrompt()
{
    strncpy(promptString, fwin_prompt_string, MAX_PROMPT_LENGTH);
    promptString[MAX_PROMPT_LENGTH-1] = 0;
    promptLength = strlen(promptString);
    if (sync_even)
    {   LockMutex(mutex1);
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}

long FXTerminal::requestRefreshTitle()
{
    strcpy(window_full_title, full_title);
// I ought to make all actions on the window stuff happen in this thread.
    if (pauseFlags == 0) main_window->setTitle(window_full_title);
// Having done all that I can re-sync with the worker thread.
    if (sync_even)
    {   LockMutex(mutex1);
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}

long FXTerminal::requestSetMenus()
{
    char **modules = modules_list,
         **switches =  switches_list;
    FXMenuPane *loadMenu, *switchMenu, *tempMenu;
    int some = 0;
    if (modules != NULL && *modules!=NULL)
    {   loadMenu = new FXMenuPane(main_window);
// There is an amazing bit of messing about here! I accept a raw list of
// names, but if I just put them all as menu items directly that could lead
// to an objectionably long menu. So I bunch items alphabetically keeeping
// each block either starting with a single letter or no longer than 20
// items. These bunches then form sub-menus.
        int firstletter = 'a';
        int lastletter = 'a', nextletter;
        int count = 0, nextcount;
        char **p = modules;
        while (*p && (*p)[1] == lastletter) count++, p+=2;
        char **p1 = p;
        while (*modules)
        {   for (;;)
            {   nextcount = 0;
                nextletter = lastletter + 1;
                if (lastletter == 'z') break;
                while (*p && (*p)[1] == nextletter) nextcount++, p+=2;
                if (count + nextcount > 20) break;
                lastletter = nextletter;
                count += nextcount;
                p1 = p;
            }
            char subname[8];
            if (firstletter == lastletter) sprintf(subname, "%c", firstletter);
            else sprintf(subname, "%c-%c", firstletter, lastletter);
            tempMenu = new FXMenuPane(main_window);
            while (modules != p1)
            {   FXMenuCommand *m =
                    new FXMenuCommand(tempMenu, 1+*modules++, NULL,
                        (FXObject *)text, FXTerminal::ID_LOAD_MODULE);
                *modules++ = (char *)m;
            }
            new FXMenuCascade(loadMenu, subname, NULL, tempMenu);
            firstletter = lastletter = nextletter;
            count = nextcount;
            p1 = p;
        }
        FXMenuTitle *tt =
            new FXMenuTitle(main_menu_bar, "Load P&ackage", NULL, loadMenu);
        tt->create();
        some = 1;
    }
// Now do roughly the same with switches
    if (switches != NULL && *switches != NULL)
    {   switchMenu = new FXMenuPane(main_window);
        int firstletter = 'a';
        int lastletter = 'a', nextletter;
        int count = 0, nextcount;
        char **p = switches;
        p = switches;
        while (*p && (*p)[1] == lastletter) count++, p+=2;
        char **p1 = p;
        while (*switches)
        {   for (;;)
            {   nextcount = 0;
                nextletter = lastletter + 1;
                if (lastletter == 'z') break;
                while (*p && (*p)[1] == nextletter) nextcount++, p+=2;
                if (count + nextcount > 20) break;
                lastletter = nextletter;
                count += nextcount;
                p1 = p;
            }
            char subname[8];
            if (firstletter == lastletter) sprintf(subname, "%c", firstletter);
            else sprintf(subname, "%c-%c", firstletter, lastletter);
            if (count > 24)
            {   int chunks = count/18;
                if (chunks == 1) chunks = 2;
                int step = (count+chunks-1)/chunks;
                tempMenu = new FXMenuPane(main_window);
                for (int i=0; i<chunks; i++)
                {   FXMenuPane *sub = new FXMenuPane(main_window);
                    char partname[10];
                    sprintf(partname, "Part %d", i+1);
                    for (int j=0; j<step; j++)
                    {   if (*switches==NULL || switches==p1) break;
                        const char *name = *switches++;
                        FXMenuCheck *cc = new FXMenuCheck(sub, 1+name,
                            (FXObject *)text, FXTerminal::ID_FLIP_SWITCH);
                        *switches++ = (char *)cc;
                        cc->setCheck(*name=='y' ? TRUE : FALSE);
                        if (*name=='x') cc->disable();
                        else cc->enable();
                    }
                    new FXMenuCascade(tempMenu, partname, NULL, sub);
                }
            }
            else
            {   tempMenu = new FXMenuPane(main_window);
                while (*switches && switches != p1)
                {   const char *name = *switches++;
                    FXMenuCheck *cc = new FXMenuCheck(tempMenu, 1+name,
                        (FXObject *)text, FXTerminal::ID_FLIP_SWITCH);
                    *switches++ = (char *)cc;
                    cc->setCheck(*name=='y' ? TRUE : FALSE);
                    if (*name=='x') cc->disable();
                    else cc->enable();
                }
            }
            new FXMenuCascade(switchMenu, subname, NULL, tempMenu);

            firstletter = lastletter = nextletter;
            count = nextcount;
            p1 = p;
        }
        FXMenuTitle *tt =
            new FXMenuTitle(main_menu_bar, "&Switch", NULL, switchMenu);
        tt->create();
        some = 1;
    }
    main_menu_bar->recalc();
    main_menu_bar->update();
// Having done all that I can re-sync with the worker thread.
    if (sync_even)
    {   LockMutex(mutex1);
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}

long FXTerminal::requestRefreshSwitches()
{
    char **switches =  switches_list;
    char **modules = modules_list;
    while (switches != NULL && *switches != NULL)
    {   char *sw = *switches++;
        FXMenuCheck *m = (FXMenuCheck *)(*switches++);
        switch (*sw)
        {
    default:break;
    case 'X':
            m->setCheck(FALSE);
            m->disable();
            *sw = 'x';
            break;
    case 'Y':
            m->enable();
    case 0x3f&'Y':
            m->setCheck(TRUE);
            *sw = 'y';
            break;
    case 'N':
            m->enable();
    case 0x3f&'N':
            m->setCheck(FALSE);
            *sw = 'n';
            break;
        }
    }
    while (modules != NULL && *modules != NULL)
    {   char *sw = *modules++;
        FXMenuCommand *m = (FXMenuCommand *)(*modules++);
        switch (*sw)
        {
    default:break;          // a blank says "currently enabled"
    case 'X':               // the "X" said "disable now"
            m->disable();
            *sw = 'y';      // the "y" says "done that"
            break;
        }
    }
// Having done all that I can re-sync with the worker thread.
    if (sync_even)
    {   LockMutex(mutex1);
        sync_even = 0;
        UnlockMutex(mutex3);
        LockMutex(mutex2);
        UnlockMutex(mutex4);
    }
    else
    {   LockMutex(mutex3);
        sync_even = 1;
        UnlockMutex(mutex1);
        LockMutex(mutex4);
        UnlockMutex(mutex2);
    }
    return 1;
}


long FXTerminal::requestRequestInput()
{
// The sequence needs to be
//   worker requests another line of input.
//       GUI flushes all pending output to screen
//       GUI displays a prompt and enabled the keyboard
//   worker must remain suspended while GUI does its stuff
//       GUI eventually sees a CR from the user. Transfers data
//       to the worker and releases it to run.
    if (sync_even) LockMutex(mutex1);
    else LockMutex(mutex3);
    int x;
// When I get here I have just interlocked with the worker task. If an
// interrupt has been posted but not yet accepted I will return at once
// with a "^C" or "^G" as relevant, and hope that the worker then picks up
// the interrupt promptly.
    if (interrupt_callback != NULL &&
        (x = (*interrupt_callback)(QUERY_INTERRUPT)) != 0 &&
        x != TICK_INTERRUPT)
    {   inputBuffer[0] = x == QUIET_INTERRUPT ? 0x1f & 'C' : 0x1f & 'G';
        inputBuffer[1] = 0;
        inputBufferLen = 1;
        inputBufferP = 0;
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
        recently_flushed = 0;
        if (pauseFlags & PAUSE_DISCARD)
            main_window->setTitle(window_full_title);
        pauseFlags &= ~PAUSE_DISCARD;
        FXMathText::appendText(x == QUIET_INTERRUPT ? "^C" : "^G", 2);
        long r = FXMathText::onCmdInsertNewline(this, 0, NULL);
        setEditable(FALSE);
        setFocus();
        return r;
    }
    if (fwin_in != fwin_out && (pauseFlags & PAUSE_DISCARD) == 0)
    {   if (fwin_in > fwin_out)
            FXMathText::appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out);
        else
        {   FXMathText::appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE-fwin_out);
            FXMathText::appendText(&fwin_buffer[0], fwin_in);
        }
        fwin_out = fwin_in;
    }
    if (pauseFlags & PAUSE_DISCARD) main_window->setTitle(window_full_title);
    pauseFlags &= ~PAUSE_DISCARD;
    FXMathText::appendStyledText(promptString, promptLength, STYLE_PROMPT);
    promptEnd = length; // start of final line, list after the prompt
    makePositionVisible(rowStart(length));
    makePositionVisible(length);
    setCursorPos(length);
// Now having displayed the prompt, I leave the worker thread locked
// until the user types ENTER, at which stage I will complete the
// handshake. At this stage I "unlock the keyboard" by making the
// object editable.
    setEditable(TRUE);
// At this stage I will stact tracking whether keys have been pressed.
    keyFlags &= ~ANY_KEYS;
// Hah - before I return from this procedure and hence before allowing anything
// else to happen in this thread I will check the type-ahead buffer and move
// across characters from it as relevant. And I make any pending paste process
// take prioity even over typed-ahead stuff. insertFromPaste returns true if
// it inserts a segment that should end with a carriage return.
    if (paste_buffer && insertFromPaste())
    {   // I want the input line to be in a special colour
        changeStyle(promptEnd, length-promptEnd, STYLE_INPUT);
        return onCmdInsertNewline(this, 0, NULL);
    }
    while (type_out != type_in)
    {   int ch[4];
        keyFlags |= ANY_KEYS;
        ch[0] = ahead_buffer[type_out++];
        ch[1] = 0;
        if (type_out == TYPEAHEAD_SIZE) type_out = 0;
// The actions might be compared with what FXMathText does when a character
// is to be inserted. But here the type-ahead nature of things means that
// we can not possibly have a selection spanning the insert point. Also I
// do not support overstrike mode for type-ahead. So it ends up very simple!
        killSelection(TRUE);
        switch (ch[0])
        {
    case '\n':  // I want the input line to be in a special colour
            changeStyle(promptEnd, length-promptEnd, STYLE_INPUT);
            return onCmdInsertNewline(this, 0, NULL);
    case '\t':
            onCmdInsertTab(this, 0, NULL);
            break;
    default:
            onCmdInsertString(this, 0, (void *)ch);
            changeStyle(promptEnd, length-promptEnd, STYLE_INPUT);
            break; // out of the switch but not out of the while loop.
        }
    }
    return 1;
}

long FXTerminal::onTimeout(FXObject *c, FXSelector s, void *p)
{
    UNUSED_ARG(c); UNUSED_ARG(s); UNUSED_ARG(p);
// This is called (about) one per second. If within the last couple of
// second the worker thread flushed output buffers then nothing happens. If
// however the screen has not been updated for a couple of second and
// there is buffered output then the buffer is flushed. The idea is that
// I can do tolerably enthusiastic buffering of output so that I avoid
// as much synchronisation and GUI overhead, but still be assured that the
// screen remains silent for at worst a second or two.
//
// I will also want to update information on the title-bar here I suspect,
// but that is not implemented yet.
//
// Restart the timer so I get a continuing stream of ticks.
#if FOX_MAJOR==1 && FOX_MINOR==0
    timer = application_object->addTimeout(1000, this, ID_TIMEOUT);
#else
#if FOX_MAJOR==1 && (FOX_MINOR==1 || FOX_MINOR==2)
    timer = application_object->addTimeout(this, ID_TIMEOUT, 1000, NULL);
#else
    application_object->addTimeout(this, ID_TIMEOUT, 1000, NULL);
#endif
#endif
// I signal the user process with a "tick" around once per second. This can
// be used eg to cause it to update the time display at the top of the
// screen, or whatever... Note that if this happens just after somebody had
// tried to post a more genuine interrupt this might risk overriding that, so
// I only post a timer interrupt if no other one is pending.
    if (interrupt_callback != NULL)
    {   int r = (*interrupt_callback)(QUERY_INTERRUPT);
        if (r == 0) (*interrupt_callback)(TICK_INTERRUPT);
    }
//
    if (++recently_flushed < 2) return 0;
// When this handler is triggered it is in the interface thread and so
// no other interface code is running. This it may update fwin_out. However
// it is not interlocked with the worker thread so it MUST NOT allter fwin_in.
    if (fwin_in != fwin_out && (pauseFlags & PAUSE_DISCARD) == 0)
    {   if (fwin_in > fwin_out)
            FXMathText::appendText(&fwin_buffer[fwin_out], fwin_in-fwin_out);
        else
        {   FXMathText::appendText(&fwin_buffer[fwin_out], FWIN_BUFFER_SIZE-fwin_out);
            FXMathText::appendText(&fwin_buffer[0], fwin_in);
        }
        makePositionVisible(rowStart(length));
    }
    fwin_out = fwin_in;
    recently_flushed = 0;
    return 1;
}

// Repaint lines of text. Note that visrows MUST be arranged to
// reflect displayed maths so that one display expression is one "row".

void FXTerminal::drawContents(FXDCWindow& dc,FXint x,FXint y,FXint w,FXint h) const {
  register FXint hh=font->getFontHeight();
  register FXint yy=pos_y+margintop+toprow*hh;
  register FXint tl=(y-yy)/hh;
  register FXint bl=(y+h-yy)/hh;
  register FXint ln;
  if(tl<0) tl=0;
  if(bl>=nvisrows) bl=nvisrows-1;
// Now if I have any mathematical expression that is to be displayed I want to
// call drawTextRow exactly once. I will arrange drawTextRow so that it draws
// the whole formula whichever of the rows that make it up get passed (and I
// want that so I can cope with cases where the formula is only partly on the
// screen).
// To cope with all this I consider 3 sorts of rows
//   (A)  0x02 0x02 ...     maths but another part of same line is to come
//   (B)  0x02 <else>       final row of a maths line
//   (C)  <else>            non-maths
// and I can pretend that just before the top line to draw there had
// been a C. Here is a regular grammar to show what I do, with actions
// in parentheses and comments in brackets:
//            S -> A (drawmath) T [first sight of a maths row sequence]
//            S -> B (drawmath) S [maths formula on one row]
//            S -> C (draw) S     [ordinary line]
//            T -> A T            [follow on rows in one maths line]
//            T -> B S            [final row of a formula]
//            T -> C (draw) S     [can never arise]
  int inMath = 'S';
  for(ln=tl; ln<=bl; ln++){
    int linebeg=visrows[ln];
// Maths data has "0x02" bytes to introduce it, but it has to be in STYLE_MATH
// as well.
    int c1 = linebeg<length ? 
             (getStyle(linebeg) & STYLE_MATH ? getChar(linebeg) : 'x') :
             'x';
    int c2 = linebeg+1<length ? getChar(linebeg+1) : 'x';
    if (inMath == 'S') 
    {   if (c1 == 0x02 && c2 == 0x02)
        {   inMath = 'T';
            drawTextRow(dc,ln,x,x+w);
        }
        else drawTextRow(dc,ln,x,x+w);
    }
    else
    {   if (c1 != 0x02) drawTextRow(dc,ln,x,x+w);
        if (c1 != 0x02 || c2 != 0x02) inMath = 'S';
    }
  }
}


// Draw partial text line with correct style. The purpose of this
// over-ride ofthe FXMathText version is to support FXShowMath stuff, which
// is triggered by having a special marker character at the start and
// and of a line.

void FXTerminal::drawTextRow(FXDCWindow& dc,FXint line,FXint left,FXint right) const {
  register FXint x,y,w,h,linebeg,lineend,truelineend,cw,sp,ep,row,edge;
  register FXuint curstyle,newstyle;
  linebeg=visrows[line];
  lineend=truelineend=visrows[line+1];
  if(linebeg<lineend && isspace(getChar(lineend-1))) lineend--;         // Back off last space
  int firstThis = linebeg < length ? getChar(linebeg) : 'x';
  if (firstThis == 0x02)
  { lineend=lineEnd(linebeg);  // I want the true end of the LINE not the end
                                // of the ROW here...
    int realbeg=lineStart(linebeg);
// Now a bit of a messy issue. I may be drawing something that was passed as
// the second or third row of a single formula, but I want to display the
// whole thing. This can arise eg when a window has been scrolled so that
// the top of a formula will not be visible. I will therefore step
// back to the start of the line and adjust my y position accordingly.
    line-=(linebeg-realbeg);
    charPointer = linebeg+1;
// now I may be at something other than the final row of a formula, so I will
// need to skip over any extra 0x02 chars that there might be.
    while (charPointer<length && getChar(charPointer)==0x02) charPointer++;
    int extraLines=charPointer-realbeg-1;
    h=font->getFontHeight();
    int extra=extraLines*h;
// Oh how HATEFUL C++ is at times! This method is flagged as "const" and I can
// not change that because of the inheritance rules. But getDefaultWidth is
// not (even though it does not actually change anything!). However "text"
// is a reference to the FXTerminal (ie to "this") so I can go via that!
    x=text->getDefaultWidth();
    y=pos_y+margintop+(toprow+line)*h;
    edge=pos_x+marginleft+barwidth;
// Recover the scale that is to be used.
    int scale = getChar(charPointer) & 0xff;
    setMathsFontScale(scale & 0x07);
// Get pointer to box structure for the formula, or NULL if it has been
// discarded because of space limitations.
    Box *b = getBoxAddress(charPointer+1);
    if (b == NULL)
    {   int p = charPointer;
        charPointer += 4;
// Parse again to re-create a box that had gone away. This time it happens
// that my variables are set up so (p+1) is the location for the reference to
// the box, ie the "owner" info.
        b = parseTeX(staticCharForShowMath, p+1);
        if (b == NULL) b = makeTextBox("malformed expression", 20, 0);
        else text->recordBoxAddress(p+1, b);
//****************************************************************************
//** The above line has a side effect of marking the text buffer as "updated".
//** This is MESSY since it is liable to cause the screen to be redrawn
//** AGAIN. This double redraw happens when memory cycling causes a box to
//** need to be re-parsed. If I get very twitchy I will re-implement
//** recordBoxAddress so it does not flag the display as dirty, but for now
//** I will accept the slight performance hit in somewhat unusual cases.
//****************************************************************************
// If created again it needs measuring again.
        measureBox(b);
// If the box has been stored from before then it can have its measurements
// refreshed by measureBox1(). This leaves it alone if the font size has not
// changed since it was last measured, but otherwise re-assesses things.
    }
    else measureBox1(b);
// preserve font & colour across the drawing code.
    FXFont *ff = dc.getFont();
    FXColor fc = dc.getForeground();
// I paint the background for math output in a different (a sort of pale
// green) colour to help it starnd out.
    dc.setForeground(FXRGB(230,255,242));
    dc.fillRectangle(edge,y,right-edge,h+extra);
    dc.setForeground(FXRGB(0,0,0));  // render maths in BLACK for now
// Try to centre the formula across the line and within its space
// (well if it was a multi-line formula I try to centre the longest line
// at least roughly, and align the left of all others with that)
    int fh=b->text.height, fd=b->text.depth;
    int delta = (h+extra+fh-fd)/2;
    int xoff = (x - b->text.width)/2;  // This would centre it.
    if (scale >= 0x28)                 // Multi-line formula fun.
    {   scale = (scale - 0x28)/8;      // Space on line in units of
        scale *= mathWidth;            // mathWidth, and now in pixels
        scale /= 2;                    // Now I have indent to centre it.
// Because the recorded "spare" info is not quite reliable I will try to
// adjust it to avoid spilling over edges even in truly dire cases.
        if (scale+b->text.width >= x) scale = x-b->text.width-1;
        if (scale < 0) scale = 0;
        xoff = scale;
    }
// Now actually display the formula!
    paintBox(&dc, b,  xoff, y+delta);
// restore font and colour.
    dc.setForeground(fc);
    dc.setFont(ff);
// Whew! Done.
    return;
  }
  x=0;
  w=0;
  h=font->getFontHeight();
  y=pos_y+margintop+(toprow+line)*h;
  edge=pos_x+marginleft+barwidth;
  row=toprow+line;

  // Scan ahead till until we hit the end or the left edge
  for(sp=linebeg; sp<lineend; sp++){
    cw=charWidth(getChar(sp),x);
    if(x+edge+cw>=left) break;
    x+=cw;
    }

  // First style to display
  curstyle=style(row,linebeg,lineend,sp);

  // Draw until we hit the end or the right edge
  for(ep=sp; ep<lineend; ep++){
    newstyle=style(row,linebeg,truelineend,ep);
    if(newstyle!=curstyle){
      fillBufferRect(dc,edge+x,y,w,h,curstyle);
      if(curstyle&STYLE_TEXT) drawBufferText(dc,edge+x,y,w,h,sp,ep-sp,curstyle);
      curstyle=newstyle;
      sp=ep;
      x+=w;
      w=0;
      }
    cw=charWidth(getChar(ep),x+w);
    if(x+edge+w>=right) break;
    w+=cw;
    }

  // Draw unfinished fragment
  fillBufferRect(dc,edge+x,y,w,h,curstyle);
  if(curstyle&STYLE_TEXT) drawBufferText(dc,edge+x,y,w,h,sp,ep-sp,curstyle);
  x+=w;

  // Fill any left-overs outside of text
  if(x+edge<right){
    curstyle=style(row,linebeg,truelineend,ep);
    fillBufferRect(dc,edge+x,y,right-edge-x,h,curstyle);
    }
  }



// Draw fragment of text in given style
// This overrides the version in FXMathText.cpp adding around 1 extra line of code
// to handle the "PROMPT" style and put prompt & input text in different
// colours.

void FXTerminal::drawBufferText(FXDCWindow& dc,FXint x,FXint y,FXint,FXint,FXint pos,FXint n,FXuint style) const {
  register FXuint index=(style&STYLE_MASK);
  register FXColor color;
  FXchar str[2];
  color=0;
  if(hilitestyles && index){                                                    // Get colors from style table
    if(style&STYLE_SELECTED) color=hilitestyles[index-1].selectForeColor;
    else if(style&STYLE_HILITE) color=hilitestyles[index-1].hiliteForeColor;
    if(color==0) color=hilitestyles[index-1].normalForeColor;                   // Fall back on normal foreground color
    }
  if(color==0){                                                                 // Fall back to default style
    if(style&STYLE_SELECTED) color=seltextColor;
    else if(style&STYLE_HILITE) color=hilitetextColor;
    if(color==0) color=textColor;                                               // Fall back to normal text color
    }
  if (style&FXTerminal::STYLE_PROMPT)
  { color=promptColor; // ACN special
  }
  else if (style&FXTerminal::STYLE_INPUT)
  { color=inputColor; // ACN special
  }
  dc.setForeground(color);
  if(style&STYLE_CONTROL){
    y+=font->getFontAscent();
    str[0]='^';
    while(pos<gapstart && 0<n){
      str[1]=buffer[pos]|0x40;
      dc.drawText(x,y,str,2);
      x+=font->getTextWidth(str,2);
      pos++;
      n--;
      }
    while(0<n){
      str[1]=buffer[pos-gapstart+gapend]|0x40;
      dc.drawText(x,y,str,2);
      x+=font->getTextWidth(str,2);
      pos++;
      n--;
      }
    }
  else{
    y+=font->getFontAscent();
    if(pos+n<=gapstart){
      dc.drawText(x,y,&buffer[pos],n);
      }
    else if(pos>=gapstart){
      dc.drawText(x,y,&buffer[pos-gapstart+gapend],n);
      }
    else{
      dc.drawText(x,y,&buffer[pos],gapstart-pos);
      x+=font->getTextWidth(&buffer[pos],gapstart-pos);
      dc.drawText(x,y,&buffer[gapend],pos+n-gapstart);
      }
    }
  }


}

// End of FXTerminal.cpp
