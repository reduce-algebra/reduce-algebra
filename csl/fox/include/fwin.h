/*
 * "fwin.h"                                       2003-2008, A C Norman
 *
 * This defines the public interface supported by the "fwin" window
 * interface.
 *
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



/*
 * The code here is provides a windowed framework in which reasonably
 * ordinary C code can run.  The functions described here are the
 * interface.  In GUI mode it is built on and relies upon the Fox Toolkit
 * and an associated threads package: by virtue of that it is expected
 * to be reasonably cross-platform portable, and in particular it supports
 * Linux and Windows (via MinGW32). It is (somewhat) modelled on an earlier
 * windowed framework that I had that I called "cwin". Cwin was built using
 * the Microsoft Foundation Classes and only ran on Windows.
 *
 * When used anywhere (including within FOX) this code is licensed as above
 * and not under any more restrictice license.
 */

/* Signature: 5d903886 14-Jul-2009 */

#ifndef header_fwin_h
#define header_fwin_h 1

#include <stdarg.h>
#include <stdlib.h>

/*
 * I use 'extern "C"' for the entrypoints here so that even though the
 * code for fwin itself is all in C++ it is callable without any fuss
 * from plain old-fashioned C code.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MS_CDECL
#ifdef _MSC_VER
/*
 * With the Microsoft Compilers I may have set some other calling convention
 * as default, and then for these I must explicitly use the ordinary one.
 */
#define MS_CDECL __cdecl
#else
#define MS_CDECL
#endif
#endif

/*
 * The "C" code will eventually be entered at fwin_main() in what looks like a
 * normal way. This is a type for it.
 */
typedef int fwin_entrypoint(int argc, char *argv[]);

/*
 * To start things going you call the following. It sets up the windowed-style
 * environment and eventually invoked fwin_main as the entrypoint of the
 * main application.
 */

extern int fwin_startup(int argc, char *argv[], fwin_entrypoint *fwin_main);

/*
 * fwin_full_program_name is a string like "d:\xxx\yyy\something.exe"  This is
 * made available so that applications can edit it to generate names of
 * resource files (eg by just altering the ".exe" bit on the end into some
 * other suffix. I will try to find a full path for the executable on
 * Unix too.
 */
extern const char *fwin_full_program_name;

/*
 * programName holds just the "something" out of fwin_full_program_name.
 * Note that I impose an arbitrary limit on the length of the name of the
 * executable.
 */
extern const char *programName;

/*
 * programDir gives the directory from which this application was launched.
 * If you try to put your executables in a directory with a very long path,
 * or possibly in a path that has really funny characters in in, you do so
 * at your own risk!
 */
extern const char *programDir;

/*
 * This returns bits that indicates what options fwin is running with:
 *
 *    0   A plain command-line system in circumstances where I do not do any
 *        local editing or special trapping of ^C. I just leave the 
 *        underlying operating system to do all that, to the extent that it
 *        will. This is used if stdin/stdout are not directly connected to
 *        a terminal or if the terminal does not seem to support cursor
 *        addressability.
 *    1   A command-line version, but where I use raw keyboard access and
 *        cursor-addressible terminal output to support local editing and
 *        a simple history mechanism styles after the GNU readline model.
 *    2   Running in a window with character input via window events and a
 *        GNU readline-like set of local editing facilities.
 */

#define FWIN_WITH_TERMED  1
#define FWIN_IN_WINDOW    2

extern int fwin_windowmode();

/*
 * To finish off you can either return from fwin_main(), or you can go
 *        fwin_exit(n);
 * The system will forcibly close down for you if the EXIT item on
 * the FILE menu or the CLOSE item on the SYSTEM menu gets selected.  But
 * direct use of the C function "exit()" is not considered proper.
 */

extern void fwin_exit(int return_code);

/*
 * If, when the program is stopping, fwin_pause_at_end has been set to
 * be non-zero (by default it will be zero) then an alert box is displayed
 * forcing the user to give positive confirmation before the main window
 * is closed.  This does not give an opportunity to cancel the exit, just to
 * read the final state of the screen...   This effect does not occur if
 * program exit is caused by selecting EXIT from the FILE menu or CLOSE
 * from the system menu. That is (deliberate in my code) because in those
 * cases the user has taken explicit interactive action to terminate the
 * program so an extra prompt seems unnecessary.
 */
extern int fwin_pause_at_end;


/*
 * fwin_minimize() indicates that the window should be shrunk to be just
 * an icon.
 * NOTE that if the command-line arguments to an application include
 * "--", "-f" or "-F" then the application will be started off minimised.
 * this is ugly and represents ways that options I want for *MY* application
 * have crept in where things ought to be generic. My reasoning at one
 * stage was that I wanted the window to eb minimised right from the start
 * so letting my code begin and then calling fwin_minimize would not be
 * so good.
 */
extern void fwin_minimize(void);

/*
 * fwin_restore() indicates that the window should be restored to
 * regular size.
 */
extern void fwin_restore(void);

/*
 * Rather than using putchar() and printf(), here are the calls
 * the can be made to get output onto the screen.  NOTE that fwin_puts()
 * is more like fputs than puts in that it just dumps the characters in its
 * string to the screen [it does not add an extra newline in the way that
 * puts does].
 * These functions support printable ASCII characters.
 * I have not thought too hard about TAB and FormFeed here... yet.
 */
extern void fwin_putchar(int c);
extern void fwin_puts(const char *s);

extern void fwin_showmath(const char *s);

extern void MS_CDECL fwin_printf(const char *fmt, ...);
extern void fwin_vfprintf(const char *fmt, va_list a);

/*
 * fwin_linelength holds the number of normal-sized (ie the basic
 * fixed-pitch font being used) characters that fit across the screen.
 * Its value can change at any time if the user re-sizes the window.
 * When the screen is minimized its value will remain at the pre-minimized
 * value. An attempt is made to create the initial window to make this
 * have the value 80. Actually just at preesent fwin insists on keeping
 * its window at a width of 80 so this value will never change!
 */
extern int fwin_linelength;

/*
 * ensure_screen() causes the display to catch up with whatever else has
 * been going on.
 */
extern void fwin_ensure_screen(void);

/*
 * fwin_getchar() behaves rather as one might expect getchar() to - it
 * grabs a character from the keyboard input buffer.
 */
extern int fwin_getchar(void);

/*
 * fwin_set_prompt() tells fwin what string (of up to some limited
 * number of characters) should be used as a prompt.
 */

#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 80
#endif

extern void fwin_set_prompt(const char *s);

/*
 * Clears screen.
 */
extern void fwin_clear_screen();

/*
 * Returns window size (measured in character positions) packed as
 *    (width << 16) + height
 */
extern int fwin_screen_size();

/*
 * The following function can be used to register a callback that is
 * used to help expand file-names of the form "$xxx/yyy". It is given the
 * "xxx" part and a character (which will be '$' or '@' - the two cases
 * give two chances for lookup, one used ahead of checking system environment
 * variables and the other after. If returns either a string that is the
 * expansion or NULL if there is none.
 * If you do not register anything then no custom lookup is performed.
 */
typedef char *lookup_function(char *s, int ch);

extern void fwin_set_lookup(lookup_function *f);


/*
 * fwin will call the function passed here before (with an arg of 1)
 * and after (with an arg of 0) any time it is liable to delay. In
 * particular when it might be about to block waiting for keyboard
 * input. The idea is that this can be used to help the caller discount
 * time spent in such cases.
 */
typedef void delay_callback_t(int);

extern void fwin_callback_on_delay(delay_callback_t *f);

/*
 * fwin will call the function passed here to try to signal an
 * exception to the worker thread. The idea is that the user-passed
 * function can then do whatever it takes to synchronise with the
 * worker. It can either signal the worker thread (but note that you need
 * to do a bit of background reading before you try to mix exceptions
 * and threads), or it can set a simple flag and the worker can poll.
 *
 * The intent is that if it passes QUIET_INTERRUPT or NOISY_INTERRUPT the
 * worker is interrupted without or with it giving messages (eg a
 * backtrace). If QUERY_INTERRUPT is passed no exception is raised, but
 * the expectation is that 0 is returned if the previous exception has
 * now been accepted and processed.
 * The case TICK_INTERRUPT is to be triggered roughly every second to
 * give the worket thread a chance to do any chores. It is NOT intended
 * to disrupt the main thread of the computation.
 *
 * If fwin detects an interrupt condition while it is waiting for keyboard
 * input or if it has generated an interrupt just before the start of
 * such a wait and a QUERY_INTERRUPT call indicates that its interrupt
 * request is still pending then as well as the activation of the callback
 * function fwin_getchar returns promptly, discarding any typed-ahead
 * stuff and returning character code 3 ("^C").
 *
 * If the callback function tries to raise exceptions etc then great care
 * may be needed to ensure it can not abort the worker in the middle of
 * a handshake where it synchronizes with the GUI thread.  Hmm yet more
 * thought is called for here!
 */

#define QUERY_INTERRUPT 0
#define TICK_INTERRUPT  1
#define QUIET_INTERRUPT 2
#define NOISY_INTERRUPT 3

typedef int interrupt_callback_t(int);

extern void fwin_callback_to_interrupt(interrupt_callback_t *f);

/*
 * When a TICK is handed to the user the following should be called
 * to confirm that it has been seen.
 */
extern void fwin_acknowledge_tick();


/*
 * The following is just for use by REDUCE. It adjusts menu entries
 * to support loading packages and setting/clearing REDUCE switches.
 * The callback function will be invoked from time to time to keep the
 * information up to date
 */
typedef void review_switch_settings_function();

extern void fwin_menus(char **modules, char **switches,
                       review_switch_settings_function *f);

/*
 * The next is used when the application has re-set some switches without the
 * GUI's help, and it updates the menu
 */
extern void fwin_refresh_switches(char **switches, char **packages);


/*
 * Short messages can be displayed at the left middle and right of the
 * main title-ribbon of your window.  These functions set the text to be
 * displayed there.  If there is not much room then only the middle one
 * will remain visible.  Each message should be limited to around 30 chars
 * (and will be best if kept shorter than that).  The default position was
 * once that the left position displayed the time & date (but it is
 * now left blank), the middle one the name of the program being run and
 * the right one is blank. fwin_report_left(NULL) or fwin_report_mid(NULL)
 * re-instate the default display. Use fwin_report_left("") is a yet clearer
 * way of indicating that blank info to the left is required.
 */
extern void fwin_report_left(const char *msg);
extern void fwin_report_mid(const char *msg);
extern void fwin_report_right(const char *msg);

/*
 * The following four strings may be updated (but PLEASE keep within the
 * length limit) to make the display in the "ABOUT" box reflect your
 * particular application. Note that to avoid triggering additional LGPL
 * requirements (that are akin to the original BSD "advertising clause")
 * you should never make the strings here appear to be copyright notices,
 * since if you do you are then obliged to extent them to include full
 * copyright notices for any LGPL code you use anywhere.
 */
extern char about_box_title[40];       /* "About XXX";           */
extern char about_box_description[40]; /* "XXX version 1.1";     */
                                       /* <icon appears here>    */
extern char about_box_rights_1[40];    /* "Author";              */
extern char about_box_rights_2[40];    /* "additional author";   */
/*
 * The next 2 lines will contain the text
 *    "This software uses the FOX Toolkit"
 *    "(http://www.fox-toolkit.org)"
 * as requested by the authors of FOX
 */

extern char about_box_rights_3[40];    /* "Credit to FOX";       */
extern char about_box_rights_4[40];    /* "ditto";               */

/*
 * The HELP drop-down menu in fwin always has some basic items on it, but
 * the user can add more by calling fwin_setHelpFile() where arg 1 is the
 * text to appear on the menu and arg 2 identifies the help file that will be
 * opened if the menu item is selected. Specifying NULL as the second item
 * removes the key. The information about help keys is kept in the registry
 * not in any file that CSL has direct access to, and the new help items may
 * not be visible until the user exits from CSL and re-starts it.
 */
extern void fwin_set_help_file(const char *key, const char *path);

/*
 * The declarations below here are to be treated as private and should
 * not be touched by users.
 */
extern int plain_worker(int argc, char *argv[], fwin_entrypoint *fwin_main);
extern delay_callback_t *delay_callback;
extern interrupt_callback_t *interrupt_callback;

/*
 * The following three functions (putchar_overwrite, move_cursor_vertically
 * and move_to_column) are not intended for use by end-users, and they
 * only apply when fwin is running in windowed mode. They are used internally
 * to support local editing and history.
 */

/*
 * like fwin_putchar(), but overwrites what exists on the screen rather
 * than inserting.
 */
extern void fwin_putchar_overwrite(int c);

/*
 * Move the cursor up or down n lines. n is positive for movement
 * down the screen.
 */
extern void fwin_move_cursor_vertically(int n);

/*
 * Move the cursor directly to the indicated column. "0" indicates
 * the first position in the row.
 */
extern void fwin_move_to_column(int column);

/*
 * What follows is to do with a history mechanism... and again is not
 * intended for public export.
 */

#define INPUT_HISTORY_SIZE 100

extern char *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next, input_history_current;

extern void input_history_init();

extern void input_history_end();

extern void input_history_add(const char *s);

extern const char *input_history_get(int n);

/*
 * This is for version-specific control
 */

#ifndef INT_VERSION
#define INT_VERSION(a,b,c) (((a*1000) + b)*1000 + c)
#endif

/*
 * By passing argv[0] to the following you can find the fully rooted
 * name of the application that you are running. This may be useful if
 * you want to put some resources (eg fonts) in the same directory as the
 * executable. If the profram was launched by quoting the name of a symbolic
 * link then that will be followed so that the path delivered is that of the
 * true file.
 */
extern int find_program_directory(char *argv0);
extern const char *fwin_full_program_name; /* eg "./fwin.exe" */
extern const char *programName;            /* eg "fwin.exe"   */
extern const char *programDir;             /* eg "."          */

/*
 * Some things that are really intended to be private to the implementation
 * but at present it seems easiest to mention them in this header rather
 * than inventing a new header file.
 */

extern int windowed;

extern int windowed_worker(int argc, char *argv[], fwin_entrypoint *fwin_main);

extern int fwin_use_xft;

extern int directoryp(char *f, char *o, size_t n);

extern int file_readable(char *f, char *o, size_t n);

extern int using_termed;

extern int fwin_plain_getchar();

extern int texmacs_mode;

extern void MS_CDECL sigint_handler(int code);
extern void MS_CDECL sigbreak_handler(int code);

extern int plain_worker(int argc, char *argv[], fwin_entrypoint *fwin_main);
#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 80
#endif
extern char fwin_prompt_string[MAX_PROMPT_LENGTH];

#ifdef __cplusplus
}
#endif

#endif /* header_fwin_h */

/* end of "fwin.h" */
