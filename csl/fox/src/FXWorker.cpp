//
// "FXWorker.cpp"                          Copyright A C Norman 2003-2008
//
//
// Window interface for old-fashioned C applications. Intended to
// be better than just running them within rxvt/xterm, but some people will
// always believe that running them under emacs is best!

/******************************************************************************
* Copyright (C) 2003-8 by Arthur Norman, Codemist Ltd.   All Rights Reserved.   *
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
* I had intended to release this under the FOX addendum to the LGPL that      *
* permits static linking, however the non-transitive nature of the terms      *
* there make that infeasible, hence this is just under LGPL.                  *
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

/* Signature: 7dced379 26-Jan-2009 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <ctype.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

#include <fx.h>

#include "FXTerminal.h"

#include "termed.h"        // for command line case

namespace FX {

#include "fwin.h"

#ifdef WIN32
HANDLE thread1;
#else
pthread_t thread1;
#endif

extern const char *colour_spec;

FXMenuBar *main_menu_bar;

FXMenuPane *fileMenu, *editMenu, *fontMenu,
           *breakMenu, *helpMenu;

int rootWidth, rootHeight;

#include "fox-icons.c"

//
// I derive a sub-class from MainWindow just so I can notice when the
// window is re-sized and record information in the registry.
//

FXDEFMAP(FXMainWindow1) FXMainWindow1Map[] =
{
    FXMAPFUNC(SEL_CONFIGURE,    0, FXMainWindow1::onConfigure)
};

FXIMPLEMENT(FXMainWindow1, FXMainWindow, FXMainWindow1Map, ARRAYNUMBER(FXMainWindow1Map))

FXMainWindow1::FXMainWindow1(FXApp *a, const FXString &b, FXIcon *c=NULL,
    FXIcon *d=NULL, FXuint opt=DECOR_ALL,
    FXint x=0, FXint y=0, FXint w=0, FXint h=0,
    FXint pl=0, FXint pr=0, FXint pt=0, FXint pb=0,
    FXint hs=0, FXint vs=0) :
    FXMainWindow(a, b, c, d, opt,
                 x, y, w, h,
                 pl, pr, pt, pb,
                 hs, vs)
{
}

FXMainWindow1::FXMainWindow1(): FXMainWindow()
{
}

void FXMainWindow1::create()
{
    FXMainWindow::create();
}


// This next gets called whenever the window changes size or position.
// The purpose of handing this event is twofold.
// (a) I want to record [in the registry] the place where my screen
//     is positioned, so that next time I start up it appears in the
//     same place;
// (b) I want to force the width of the screen to remain constant at
//     80 columns.

FXApp *application_object;
FXMainWindow1 *main_window;

extern "C"
{

extern int windowed;

FXTerminal *text = NULL;

}

long FXMainWindow1::onConfigure(FXObject *c, FXSelector s, void *ptr)
{
    FXEvent *e = (FXEvent *)ptr;
    FXRegistry *reg = &(application_object->reg());
    reg->writeIntEntry("screen", "screenx", e->rect.x);
    reg->writeIntEntry("screen", "screeny", e->rect.y);
    reg->writeIntEntry("screen", "screenw", e->rect.w);
    reg->writeIntEntry("screen", "screenh", e->rect.h);
    int r = FXMainWindow::onConfigure(c, s, ptr);
    if (text != NULL) e->rect.w = text->forceWidth();
    return r;
}

static int debug_option = 0;

#ifndef WIN32
static int IgnoreXError(Display *d, XErrorEvent *e)
{
    d = d;
    e = e;
    return 0;
}
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
#endif

#endif

#define COMPANY_NAME  "Codemist-Ltd"
#define PRODUCT_NAME  programName

#define WINDOW_NAME   programName

// registry entries will be filed under Codemist-Ltd/<something>.
    application_object = new FXApp(PRODUCT_NAME,
                                   COMPANY_NAME);
// args can be sent in via command-line args, if that is any help.
// Just at present I do not fully understand what FOX does with these
// arguments but it MAY be that it expects to allow "-geometry" or "-fn"
// etc arguments as per standard for X11 applications.
    application_object->init(argc, argv, TRUE);
#ifndef WIN32
    debug_option = 0;
    for (int i=1; i<argc; i++)
    {   if (strcmp(argv[i], "-g") == 0 ||
                 strcmp(argv[i], "-G") == 0) debug_option = 1;
    }
/*
 * By default if there are any X protocol error (eg relating to missing
 * fonts) X send a message to stdout reporting. Unless I am in debug mode
 * there can be an unwanted distraction so I will hide them. If however
 * I am in debug mode I will set the X protocol to run in synchronous
 * mode, which will slow it down but make debugging easier. I believe I have
 * to set these options after X has been initialised and I want to do it as
 * soon as possible after that, hence this bit of decoding of command-line
 * options is separated from the main chunk.
 */
    if (debug_option) _Xdebug = 1;
    else XSetErrorHandler(IgnoreXError);
#endif

#if INT_VERSION(FOX_MAJOR,FOX_MINOR,0)==INT_VERSION(1,0,0)
    FXRootWindow *r = application_object->getRoot();
#else
    FXRootWindow *r = application_object->getRootWindow();
#endif
    rootWidth = r->getDefaultWidth(),
    rootHeight = r->getDefaultHeight();

// Now I will decide how big the main window should be. If I have information
// in the registry left over from my last run I will use that.
    FXRegistry *reg = &application_object->reg();
    int screenx = reg->readIntEntry("screen", "screenx", -1);
    int screeny = reg->readIntEntry("screen", "screeny", -1);
    int screenw = reg->readIntEntry("screen", "screenw", -1);
    int screenh = reg->readIntEntry("screen", "screenh", -1);

    if (screenx < 0 || screeny < 0 || screenw <= 100 || screenh < 20)
    {   screenx = screeny = 50; // When I had 0 here that was off the screen!
        screenw = screenh = 0;
    }
    int fontsize =
        reg->readIntEntry("screen", "fontsize", -1);
#if (FOX_MINOR<=4)
    int fontweight =
        reg->readIntEntry("screen", "fontweight", FONTWEIGHT_BOLD);
    int fontslant =
        reg->readIntEntry("screen", "fontslant", FONTSLANT_REGULAR);
    int fontencoding =
        reg->readIntEntry("screen", "fontencoding", FONTENCODING_DEFAULT);
    int fontsetwidth =
        reg->readIntEntry("screen", "fontsetwidth", FONTSETWIDTH_DONTCARE);
    int fonthints =
        reg->readIntEntry("screen", "fonthints",
                          FONTPITCH_FIXED|FONTHINT_MODERN);
#else
    int fontweight =
        reg->readIntEntry("screen", "fontweight", FXFont::Bold);
    int fontslant =
        reg->readIntEntry("screen", "fontslant", FXFont::Straight);
    int fontencoding =
        reg->readIntEntry("screen", "fontencoding", FONTENCODING_DEFAULT);
    int fontsetwidth =
        reg->readIntEntry("screen", "fontsetwidth", FXFont::NonExpanded);
    int fonthints =
        reg->readIntEntry("screen", "fonthints",
                          FXFont::Fixed|FXFont::Modern);
#endif
    const char *fontname =
        reg->readStringEntry("screen", "fontname",  DEFAULT_FONT_NAME);
// I have a concern here about how long the string that is returned will
// remain valid. As a matter of caution I will not read other string values
// from the registry until I have used or copied this.

// The icon that I use here depends on the name that this program is
// launched with. This situation in perhaps not perfect but it seems the
// easiest route just for now.
    const unsigned char *icondata = fwin;

// This sets alternative custom icons based on the name of the executable
// and it clearly NOT portable... however I find it helpful, and it should
// not impact anybody who wants to make independent use of this library.
    if (strcmp(programName, "csl") == 0) icondata = csl;
    else if (strcmp(programName, "bootstrapreduce") == 0) icondata = csl;
    else if (strcmp(programName, "reduce") == 0) icondata = reduce;
    main_window = new FXMainWindow1(
        application_object,
        WINDOW_NAME,
        new FXICOIcon(application_object, icondata,
                      FXRGB(255,255,255), IMAGE_ALPHAGUESS),
        NULL,    // mini-icon
        DECOR_ALL,
        screenx, screeny,
        screenw, screenh);
    main_menu_bar = new FXMenuBar(main_window,
                                  LAYOUT_SIDE_TOP | LAYOUT_FILL_X);
// NB. NB. NB.
// *NB*  the TEXT_COLUMNWRAP flag is my own PATCH to FOX, and when I build
// FOX I change the files FXText.h and FXText.cpp to implement it. It
// lets me wrap lines at exactly 80 columns, regardless of how whitespace
// happens to lie.
    text = new FXTerminal(main_window, NULL, 0,
        HSCROLLER_NEVER | TEXT_FIXEDWRAP | TEXT_WORDWRAP | TEXT_COLUMNWRAP |
        TEXT_SHOWACTIVE | LAYOUT_FILL_X | LAYOUT_FILL_Y);

// I am really supposed to destroy menus as I exit. So somewhere I need to
// arrange that - or maybe I can hope that my application only closes its
// window when finally terminating, and somebody will tidy up at a system
// level for me.
    fileMenu = new FXMenuPane(main_window);
    new FXMenuCommand(fileMenu, "&Read...", NULL,
                                (FXObject *)text, FXTerminal::ID_READ);
    new FXMenuCommand(fileMenu, "&Save...", NULL,
                                (FXObject *)text, FXTerminal::ID_SAVE);
    new FXMenuCommand(fileMenu, "Save Se&lection...", NULL,
                                (FXObject *)text, FXTerminal::ID_SAVE_SELECTION);
    new FXMenuCommand(fileMenu, "&Print...", NULL,
                                (FXObject *)text, FXTerminal::ID_PRINT);
    new FXMenuCommand(fileMenu, "Pri&nt Selection...", NULL,
                                (FXObject *)text, FXTerminal::ID_PRINT_SELECTION);
    new FXMenuCommand(fileMenu, "&Quit\tCtl-\\\tQuit the application.", NULL,
                                application_object, FXApp::ID_QUIT);
// I make this F&ile not &File since alt-F will be for "move forward one
// word" using emacs-like key bindings.
    new FXMenuTitle(main_menu_bar, "F&ile", NULL, fileMenu);

    editMenu = new FXMenuPane(main_window);
    new FXMenuCommand(editMenu, "&Cut", NULL,
                                (FXObject *)text, FXTerminal::ID_CUT_SEL_X);
    new FXMenuCommand(editMenu, "C&opy", NULL,
                                (FXObject *)text, FXTerminal::ID_COPY_SEL_X);
    new FXMenuCommand(editMenu, "&Paste\tCtl-V", NULL,
                                (FXObject *)text, FXTerminal::ID_PASTE_SEL_X);
    new FXMenuCommand(editMenu, "&Reinput\tCtl-^\tReinput", NULL,
                                (FXObject *)text, FXTerminal::ID_REINPUT);
    new FXMenuCommand(editMenu, "Select &All", NULL,
                                (FXObject *)text, FXText::ID_SELECT_ALL);
    new FXMenuCommand(editMenu, "C&lear\tCtl-L", NULL,
                                (FXObject *)text, FXTerminal::ID_CLEAR);
    new FXMenuCommand(editMenu, "Re&draw\tCtl-R", NULL,
                                (FXObject *)text, FXTerminal::ID_REDRAW);
    new FXMenuCommand(editMenu, "&Home", NULL,
                                (FXObject *)text, FXTerminal::ID_HOME);
    new FXMenuCommand(editMenu, "&End", NULL,
                                (FXObject *)text, FXTerminal::ID_END);

    new FXMenuTitle(main_menu_bar, "&Edit", NULL, editMenu);

    fontMenu = new FXMenuPane(main_window);
    new FXMenuCommand(fontMenu, "&Font...", NULL,
                                (FXObject *)text, FXTerminal::ID_FONT);
    new FXMenuCommand(fontMenu, "&Reset Font", NULL,
                                (FXObject *)text, FXTerminal::ID_RESET_FONT);
    new FXMenuCommand(fontMenu, "Reset &Window", NULL,
                                (FXObject *)text, FXTerminal::ID_RESET_WINDOW);
    new FXMenuTitle(main_menu_bar, "F&ont", NULL, fontMenu);

    breakMenu = new FXMenuPane(main_window);
    new FXMenuCommand(breakMenu, "&Break\tCtl-C\tInterrupt", NULL,
                                (FXObject *)text, FXTerminal::ID_BREAK);
    new FXMenuCommand(breakMenu, "Bac&ktrace\tCtl-G\tInterrupt/backtrace", NULL,
                                (FXObject *)text, FXTerminal::ID_BACKTRACE);
    new FXMenuCommand(breakMenu, "&Pause\tCtl-S", NULL,
                                (FXObject *)text, FXTerminal::ID_PAUSE);
    new FXMenuCommand(breakMenu, "&Resume\tCtl-Q", NULL,
                                (FXObject *)text, FXTerminal::ID_RESUME);
    new FXMenuCommand(breakMenu, "&Stop/Go\tCtl-Z", NULL,
                                (FXObject *)text, FXTerminal::ID_STOP);
    new FXMenuCommand(breakMenu, "&Discard Output\tCtl-O", NULL,
                                (FXObject *)text, FXTerminal::ID_DISCARD);

    new FXMenuTitle(main_menu_bar, "B&reak", NULL, breakMenu);

    helpMenu = new FXMenuPane(main_window);
    new FXMenuCommand(helpMenu, "&Help\tF1\tHelp", NULL,
                                (FXObject *)text, FXTerminal::ID_HELP);
#ifndef WIN32
#if !defined MACINTOSH || !defined MAC_FRAMEWORK
    new FXMenuCommand(helpMenu, "&Select Browser\t\tSelect Browser", NULL,
                                (FXObject *)text, FXTerminal::ID_BROWSER);
#endif
#endif
    new FXMenuCommand(helpMenu, "&About\t\tAbout", NULL,
                                (FXObject *)text, FXTerminal::ID_ABOUT);

    new FXMenuTitle(main_menu_bar, "Help", NULL, helpMenu, LAYOUT_RIGHT);

    text->setEditable(FALSE);
    text->setStyled(TRUE);

    text->argc = argc;
    text->argv = argv;

    strcpy(mid_stuff, programName);
    main_window->setTitle(programName);

    application_object->create();

// Selecting the font may involve measuring font sizes etc which may
// need the font creating...

    FXFont *font1 = selectFont(fontname, fontsize,
        fontweight, fontslant, fontencoding, fontsetwidth, fonthints);
    font1->create();
    text->setFont(font1);

    if (screenw == 0) text->onCmdResetWindow(NULL, 0, NULL);

    text->onCmdHome(NULL, 0, NULL); // actually just to grab the focus!
//
// I will iconify the window AFTER I have adjusted its size since I do not
// want to end up with a size that is silly and based on just an icon!
// Also somewhere (and I now do not remember where) I picked up the idea
// that minimizing twice over was a good idea...
//
#if INT_VERSION(FOX_MAJOR,FOX_MINOR,0)==INT_VERSION(1,0,0)
    if (windowed < 0) 
    {   main_window->iconify();
        main_window->iconify();
    }
#else
    if (windowed < 0)
    {   main_window->minimize();
        main_window->minimize();
    }
#endif

    text->setupShowMath();

    main_window->show();
#ifdef WIN32
    DWORD threadId;
    thread1 = CreateThread(NULL,  // security attributes
                           0,     // stack size
                           worker_thread,
                           (void *)text,
                           0,     // flags
                           &threadId); // Essential for Me/98/95
    if (thread1 == NULL)
    {   fprintf(stderr, "Fatal error attempting to create a thread\n");
        application_object->exit(1);
        exit(1);
    }
#else
    if (pthread_create(&thread1, NULL, worker_thread, (void *)text))
    {   fprintf(stderr, "Fatal error attempting to create a thread\n");
        application_object->exit(1);
        exit(1);
    }
#endif

// Once a second I will try to flush any output buffers. But do not start
// that until everything else is more or less going!
#if FOX_MAJOR==1 && FOX_MINOR==0
    timer = application_object->addTimeout(1000,
               (FXObject *)text, FXTerminal::ID_TIMEOUT);
#else
#if FOX_MAJOR==1 && (FOX_MINOR==1 || FOX_MINOR==2)
    timer = application_object->addTimeout((FXObject *)text,
                FXTerminal::ID_TIMEOUT, 1000, NULL);
#else
    application_object->addTimeout((FXObject *)text,
                FXTerminal::ID_TIMEOUT, 1000, NULL);
#endif
#endif

    return application_object->run();
}


FXFont *selectFont(const char *name, int size,
    int weight, int slant, int encoding, int setwidth, int hints)
{
// I start with a simplistic hypothesis that the width if characters in
// fonts here will scale linearly with their point size.
    int pointSize = 200;
    if (size > 0) pointSize = size;
    FXFontDesc fd;
    strncpy(fd.face, name, sizeof(fd.face));
    fd.size = pointSize;    // NB decipoints not points
    fd.weight = weight;
    fd.slant = slant;
    fd.encoding = encoding;
    fd.setwidth = setwidth;
    fd.flags = hints;
    FXFont *f = new FXFont(application_object, fd);
// I really hope that I have a fixed-with font here!
    f->create();
// If the registry had told me what size font to use then I will just
// stick with that. If not then I will have been hended in a negative
// size specifier and I will need to make a guess here.
   if (size > 0) return f;
// My font-size selection will be based in font and screen widths.
    int w = f->getFontWidth();
// Work out what proportion of my screen's width would be filled by
// 80 characters in this font.
    double fill = (80.0*(double)w)/(double)rootWidth;
    f->getFontDesc(fd);
    pointSize = fd.size;   // in deci-points for the one actually found
// I am now going to suggest a font size based on what I will count as
// a half-sensible way to place a window on the screen... Well my idea
// here is that on larger screens you will use a larger font but still fill up
// less of the total screen. On screens down at 800*600 and below I will
// want to use almost all of the screen, while for 1280*1024, 1600*1200 etc
// I will only use half the available width. This must be a matter where
// taste comes in, so others may have different views.
    double bestSize;
    if (rootWidth > 1100)     // try to 60% fill the root width
        bestSize = (double)pointSize*0.6/fill;
    else if (rootWidth > 900) // try to fill 0.75 the root width
        bestSize = (double)pointSize*0.75/fill;
                                // finally on small roots use almost all.
    else bestSize = (double)pointSize*0.9/fill;
    pointSize = (int)(0.5 + bestSize);
// I think that I will avoid over-teeny fonts come what may. So I will
// increate the selected size so that I always use at least 8pt.
    if (pointSize < 80) pointSize = 80;
    fd.size = pointSize;
    delete f;
// Finally create a fond that is the size that may make sense!
    f = new FXFont(application_object, fd);
    f->create();
    return f;
}


void fwin_callback_on_delay(delay_callback_t *f)
{
    delay_callback = f;
}

void fwin_callback_to_interrupt(interrupt_callback_t *f)
{
    interrupt_callback = f;
}


#ifndef WIN32
#include <pthread.h>
#endif

extern "C" {

//
// The "curses" header is a very fine example of the trouble that can be
// generated by mixing up name-spaces. And the way that C code can be
// less than perfect for use from C++.  On my system at least a header
// file here goes
//   #define clear() wclear(stdsrc)
// but now consider a class that has a class-scope method called clear -
// calls to it get mapped onto wclear in a way that is utterly horrid.
// 
// I include the curses headers AFTER all other headers to avoid mixups
// in declarations, and sit and hope! If I get very worried I will just
// migrate all uses of curses into a separate file where I will provide
// myself with C++ wrappers...
//

#ifdef MOUSE_MOVED
#undef MOUSE_MOVED
#endif

#ifdef HAVE_LIBCURSES
#include <curses.h>
#define HAVE_CURSES 1
#else
#ifdef HAVE_LIBNCURSES
#include <ncurses.h>
#define HAVE_CURSES 2
#endif
#endif

}

static int returncode = 0;


// Here is the worker thread.

static FXTerminal *term;

#ifdef WIN32
DWORD __stdcall worker_thread(void *arg)
#else
void *worker_thread(void *arg)
#endif
{
// The curious-looking delegation here is to ensure that the signature
// of the thread is a simple C-style one rather than a C++ member
// function. That is what is required for thread creation.
    return ((FXTerminal *)arg)->worker_thread(arg);
}

// I can signal the GUI thread by writing a byte to a pipe that it
// watches. The byte that I write can be an indication of what
// event I wanted to report

void wake_up_terminal(int n)
{
#ifdef WIN32
    event_code = n;
    SetEvent(pipedes);
#else
    char pipe_data[1];
    pipe_data[0] = n;
    if (write(pipedes[PIPE_WRITE_PORT], pipe_data, 1) != 1)
    {   fprintf(stdout, "Fatal error attempting to write to a pipe\n");
        application_object->exit(1);
        exit(1);
    }
#endif
}

#ifdef WIN32
DWORD FXTerminal::worker_thread(void *arg)
#else
void *FXTerminal::worker_thread(void *arg)
#endif
{
    signal(SIGINT, sigint_handler);
#ifdef SIGBREAK
    signal(SIGBREAK, sigbreak_handler);
#endif
    term = (FXTerminal *)arg;

// set proper initial state for all the locks.
    LockMutex(term->mutex1);
    LockMutex(term->mutex2);
    term->sync_even = 1;

// run the application code.
    returncode = (*fwin_main1)(term->argc, term->argv);
    wake_up_terminal(WORKER_EXITING);
#ifdef WIN32
    ExitThread(returncode);
    return returncode;
#else
    pthread_exit(&returncode);      // between these two lines I think
    return &returncode;             // I must certainly exit!
#endif
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
    if (windowed)
    {   wake_up_terminal(FXTerminal::WORKER_EXITING);
        returncode = return_code;
#ifdef WIN32
        ExitThread(returncode);
#else
        pthread_exit(&returncode);
#endif
    }
    if (using_termed)
    {   input_history_end();
        term_close();
    }
    exit(return_code);
}


void fwin_minimize()
{
    if (!windowed) return;
    fflush(stdout);
    wake_up_terminal(FXTerminal::MINIMIZE_MAIN);
// I do not feel any need to get the threads into lockstep here.
}


void fwin_restore()
{
    if (!windowed) return;
    fflush(stdout);
    wake_up_terminal(FXTerminal::RESTORE_MAIN);
}

void fwin_putchar(int c)
{
    if (!windowed)
    {
#ifdef RAW_CYGWIN
        if (c == '\n') putchar('\r');
#endif
        putchar(c);
        return;
    }
// Observe that since I am concerned (at least a bit) with performance
// I buffer characters here so that the cost of inter-thread communication
// is not suffered. But every other second (or so) the user-interface thread
// will be worken up and will flush the buffer for me, so the user ought to
// be given a tolerable experience/
    int nxt = term->fwin_in + 1;
    if (nxt == FWIN_BUFFER_SIZE) nxt = 0;
    if (nxt == term->fwin_out ||
        term->pauseFlags & PAUSE_PAUSE) fwin_ensure_screen();
// Note and BEWARE here that fwin_ensure_screen() can synchronize the
// worker and interface threads and update fwin_in. Observe also that I
// can generate a screen update if ^S has been hit.
    term->fwin_buffer[term->fwin_in] = c;
    nxt = term->fwin_in + 1;
    if (nxt == FWIN_BUFFER_SIZE) nxt = 0;
    term->fwin_in = nxt;
    FILE *f = term->logfile;
    if (f != NULL) putc(c, f);
}

static void fwin_ensure_buffer_space();

void fwin_puts(const char *s)
{
    if (!windowed)
    {
#ifdef RAW_CYGWIN
        while (*s != 0) fwin_putchar(*s++);
#else
        puts(s);
#endif
        return;
    }
    int len = strlen(s);
    while (len > 0)
    {   int n = len;
        if (n > SPARE_FOR_VFPRINTF) n = SPARE_FOR_VFPRINTF;
        if (term->fwin_in+SPARE_FOR_VFPRINTF >= FWIN_BUFFER_SIZE ||
            term->pauseFlags & PAUSE_PAUSE)
            fwin_ensure_buffer_space();
        memcpy(&term->fwin_buffer[term->fwin_in], s, n);
        FILE *f = term->logfile;
        if (f != NULL) fwrite(s, 1, n, f);
        term->fwin_in += n;
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
#ifdef RAW_CYGWIN
/* NOT reconstructed yet @@@ */
        vfprintf(stdout, fmt, a);
        va_end(a);
#else
        vfprintf(stdout, fmt, a);
        va_end(a);
#endif
        return;
    }
    if (term->fwin_in+SPARE_FOR_VFPRINTF >= FWIN_BUFFER_SIZE ||
        term->pauseFlags & PAUSE_PAUSE)
        fwin_ensure_buffer_space();
// The code here is inherently UNSAFE since vsprintf does not give
// any protection against buffer overflow and there is no universally
// available equivalent that is safe. I arrange that if the printf call
// generates at most SPARE_FOR_VFPRINTF characters I am OK.
//
// Well C99 provides vsnprintf so if that is available I ought to use it...
//
#ifdef HAVE_VSNPRINTF
    vsnprintf(&term->fwin_buffer[term->fwin_in], SPARE_FOR_VFPRINTF, fmt, a);
#else
    vsprintf(&term->fwin_buffer[term->fwin_in], fmt, a);
#endif
// Cautious about portability and old libraries, and aware of values that
// vsnprintf may return when the data does not fit, I ignore the values
// of the above functions and adjust the data pointers by hand.
    int n = strlen(&term->fwin_buffer[term->fwin_in]);
    FILE *f = term->logfile;
    if (f != NULL) fwrite(&term->fwin_buffer[term->fwin_in], 1, n, f);
    term->fwin_in += n;
    va_end(a);
}

void fwin_vfprintf(const char *fmt, va_list a)
{
    if (!windowed)
    {
#ifdef RAW_CYGWIN
/* Not reconstructed yet @@@ */
        vfprintf(stdout, fmt, a);
#else
        vfprintf(stdout, fmt, a);
#endif
        return;
    }
// see comments above.
    if (term->fwin_in+SPARE_FOR_VFPRINTF >= FWIN_BUFFER_SIZE ||
        term->pauseFlags & PAUSE_PAUSE)
        fwin_ensure_buffer_space();
#ifdef HAVE_VSNPRINTF
    vsnprintf(&term->fwin_buffer[term->fwin_in], SPARE_FOR_VFPRINTF, fmt, a);
#else
    vsprintf(&term->fwin_buffer[term->fwin_in], fmt, a);
#endif
    int n = strlen(&term->fwin_buffer[term->fwin_in]);
    FILE *f = term->logfile;
    if (f != NULL) fwrite(&term->fwin_buffer[term->fwin_in], 1, n, f);
    term->fwin_in += n;
}

static void regain_lockstep()
{
// This looks jolly ugly to me - I need to talk to others who are more
// experienced in concurrency to see if I can improve it.
    if (term->sync_even)
    {   UnlockMutex(term->mutex1);
        LockMutex(term->mutex3);
        UnlockMutex(term->mutex2);
        LockMutex(term->mutex4);
    }
    else
    {   UnlockMutex(term->mutex3);
        LockMutex(term->mutex1);
        UnlockMutex(term->mutex4);
        LockMutex(term->mutex2);
    }
}

const char *fwin_maths = NULL;

void fwin_showmath(const char *s)
{
    if (!windowed) return;
    fwin_ensure_screen();   // get regular text up to date first.
    fwin_maths = s;
    LockMutex(term->pauseMutex);
// here I have to do real inter-thread communication.
    if (delay_callback != NULL) (*delay_callback)(1);
    wake_up_terminal(FXTerminal::SHOW_MATH);
// here I need to wait until the signal that I just sent has been received
// and processed.
    regain_lockstep();
    if (delay_callback != NULL) (*delay_callback)(0);
    UnlockMutex(term->pauseMutex);
}


void fwin_ensure_screen()
{
    if (!windowed)
    {   fflush(stdout);
        return;
    }
    if (term->fwin_in == term->fwin_out) return;
    LockMutex(term->pauseMutex);
// here I have to do real inter-thread communication.
    if (delay_callback != NULL) (*delay_callback)(1);
    wake_up_terminal(FXTerminal::FLUSH_BUFFER);
// here I need to wait until the signal that I just sent has been received
// and processed.
    regain_lockstep();
    if (delay_callback != NULL) (*delay_callback)(0);
    UnlockMutex(term->pauseMutex);
}

static void fwin_ensure_buffer_space()
{
    if (!windowed) return;
    if (term->fwin_in == term->fwin_out) return;
    LockMutex(term->pauseMutex);
    if (delay_callback != NULL) (*delay_callback)(1);
    wake_up_terminal(FXTerminal::FLUSH_BUFFER);
    if (term->sync_even)
    {   UnlockMutex(term->mutex1);
        LockMutex(term->mutex3);
        term->fwin_in = term->fwin_out = 0;
        UnlockMutex(term->mutex2);
        LockMutex(term->mutex4);
    }
    else
    {   UnlockMutex(term->mutex3);
        LockMutex(term->mutex1);
        term->fwin_in = term->fwin_out = 0;
        UnlockMutex(term->mutex4);
        LockMutex(term->mutex2);
    }
    if (delay_callback != NULL) (*delay_callback)(0);
    UnlockMutex(term->pauseMutex);
}

extern "C"
{
static review_switch_settings_function *review_switch_settings = NULL;
}
static int update_next_time = 0;


int fwin_getchar()
{
    if (!windowed) return fwin_plain_getchar();
// In general I have a line of stuff ready sitting in a buffer. So on
// most calls to here I can just return what is in it.
    if (term->inputBufferP < term->inputBufferLen)
        return term->inputBuffer[term->inputBufferP++];
// Now however a new line of input is needed, so I have to request it from
// the user-interface thread.
    if (update_next_time && review_switch_settings != NULL)
    {   (*review_switch_settings)();
        update_next_time = 0;
    }
    if (delay_callback != NULL) (*delay_callback)(1);
    wake_up_terminal(FXTerminal::REQUEST_INPUT);
// Wait until the signal that I just sent has been received
// and processed.
    regain_lockstep();
    if (delay_callback != NULL) (*delay_callback)(0);
// I will try a convention that if inputBufferLen is zero that indicates
// a dodgy state. Eg the user is sending an EOF or interrupt.
    int n = term->inputBufferLen;
    if (n == 0) return EOF;
    const char *p = &term->inputBuffer[term->inputBufferP];
    while (n>0 && isspace(*p))
    {   n--;
        p++;
    }
// The next line is pretty shameless and is there to help REDUCE while not
// getting too much in the way of anybody else. If an input line is
// entered starting with the text "load_package" I make a callback to
// review_switch_settings fairly soon.
    if (n>12 && strncmp(p, "load_package", 12) == 0)
        update_next_time = 1;
    int ch = term->inputBuffer[term->inputBufferP++];
    if (ch == (0x1f & 'D')) return EOF;
    else return ch;
}


void fwin_set_prompt(const char *s)
{
    strncpy(fwin_prompt_string, s, sizeof(fwin_prompt_string));
    fwin_prompt_string[sizeof(fwin_prompt_string)-1] = 0;
    if (!windowed) return;
    wake_up_terminal(FXTerminal::SET_PROMPT);
    regain_lockstep();
}

void fwin_menus(char **modules, char **switches,
                review_switch_settings_function *f)
{
    if (!windowed) return;
    modules_list = modules;
    switches_list = switches;
    wake_up_terminal(FXTerminal::SET_MENUS);
    regain_lockstep();
    review_switch_settings = f;
}

void fwin_refresh_switches(char **switches, char **packages)
{
    if (!windowed) return;
    switches_list = switches;
    modules_list = packages;
    wake_up_terminal(FXTerminal::REFRESH_SWITCHES);
    regain_lockstep();
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
    wake_up_terminal(FXTerminal::REFRESH_TITLE);
    regain_lockstep();
}


void fwin_acknowledge_tick()
{
// This is to do with my handling of "^Z" to suspend the computation.
// If the user enters ^Z I lock the pause mutex and then send a "TICK".
// The user is expected to notice it and respond here - and hence get
// suspended.
    if (!windowed) return;
    LockMutex(term->pauseMutex);
    UnlockMutex(term->pauseMutex);
}


void fwin_report_left(const char *msg)
{
    if (!windowed) return;
    strncpy(left_stuff, msg, 31);
    left_stuff[31] = 0;
    rewrite_title_bar();
}

void fwin_report_mid(const char *msg)
{
    if (!windowed) return;
    strncpy(mid_stuff, msg, 31);
    mid_stuff[31] = 0;
    rewrite_title_bar();
}

void fwin_report_right(const char *msg)
{
    if (!windowed) return;
    strncpy(right_stuff, msg, 31);
    right_stuff[31] = 0;
    rewrite_title_bar();
}

void fwin_set_help_file(const char *key, const char *path)
{
    if (!windowed) return;
    printf("fwin_set_help_file called\n");
    fflush(stdout);
}


}

// end of FXWorker.cpp

