// "wxfwin.h"                           Copyright (C) 2003-2022, A C Norman
//
// This defines the public interface supported by the "wxfwin" window
// interface. Note that this should be functionally very similar to
// the arrangements I had with "fwin".
//


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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



//
// The code here is provides a windowed framework in which reasonably
// ordinary C code can run.  The functions described here are the
// interface.  In GUI mode it is built on and relies upon wxWidgets
// and an associated threads package: by virtue of that it is expected
// to be reasonably cross-platform portable, and in particular it supports
// Linux, Windows and MacOSX. It is closely based on an earlier
// windowed framework that I had (fwin) that used the FOX Gui toolkit.
// That in turn was (somewhat) modelled on an even earlier version that
// I called "cwin".
//

// $Id$

#ifndef header_wxfwin_h
#define header_wxfwin_h 1

#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <csignal>

//
// Logging support, only enabled in debug mode.
//
// Usage (eg):  FWIN_LOG("I reached %d of %s\n", __LINE__, __FILE__);
//

#ifdef DEBUG
extern void fwin_write_log(const char *s, ...);
#define FWIN_LOG(...) fwin_write_log(__VA_ARGS__)
#else
#define FWIN_LOG(...)  ((void)0)
#endif


//
// The "C" code will eventually be entered at fwin_main() in what looks like a
// normal way. This is a type for it.
//
typedef int fwin_entrypoint(int argc, const char *argv[]);

//
// To start things going you call the following. It sets up the windowed-style
// environment and eventually invoked fwin_main as the entrypoint of the
// main application.
//

extern int fwin_startup(int argc, const char *argv[],
                        fwin_entrypoint *fwin_main);

//
// fullProgramName is a string like "d:\xxx\yyy\something.exe"
// This is made available so that applications can edit it to generate
// names of resource files (eg by just altering the ".exe" bit on the end
// into some other suffix. I will try to find a full path for the executable
// on Unix too, in which it may come out as eg "/home/user/dir/something".
//
// Note that I will be moving to using UFT8 for these strings so that
// if path-names include extended characters the path is still captured
// accurately. With wxWidgets on Windows the native Unicode representation
// is UTF16 and so conversion will be called for. But on X11 and Mac
// wxWidgets uses UTF8 and things feel simpler.
//
extern const char *fullProgramName;

//
// programName holds just the "something" out of fullProgramName.
// Note that I impose an arbitrary limit on the length of the name of the
// executable. I do not support wide characters here.
//
extern const char *programName;

//
// programDir gives the directory from which this application was launched.
// If you try to put your executables in a directory with a very long path,
// or possibly in a path that has really funny characters in in, you do so
// at your own risk!
//
extern const char *programDir;

//
// This returns bits that indicates what options wxfwin is running with:
//
//    0   A plain command-line system in circumstances where I do not do any
//        local editing or special trapping of ^C. I just leave the
//        underlying operating system to do all that, to the extent that it
//        will. This is used if stdin/stdout are not directly connected to
//        a terminal or if the terminal does not seem to support cursor
//        addressability.
//    1   A command-line version, but where I use raw keyboard access and
//        cursor-addressible terminal output to support local editing and
//        a simple history mechanism styled after the GNU readline model,
//        but entirely implemented by me and hence bot subject to the
//        license constraints that readline itself brings to the table.
//    2   Running in a window with character input via window events and
//        again a readline-like set of local editing facilities. Note that
//        the bindings of control characters in this version needs to reserve
//        some as keyboard shortcuts for menus, and that means that 100%
//        compatibility with readline or emacs is not a sane objective.
//

#define FWIN_WITH_TERMED  1
#define FWIN_IN_WINDOW    2

extern int fwin_windowmode();

//
// To finish off you can either return from fwin_main(), or you can go
//        fwin_exit(n);
// The system will forcibly close down for you if the EXIT item on
// the FILE menu or the CLOSE item on the SYSTEM menu gets selected.  But
// direct use of the C function "exit()" is not considered proper (even
// if it probably works!).
//

extern void fwin_exit(int return_code);

//
// If, when the program is stopping, fwin_pause_at_end has been set to
// be non-zero (by default it will be zero) then an alert box is displayed
// forcing the user to give positive confirmation before the main window
// is closed.  This does not give an opportunity to cancel the exit, just to
// read the final state of the screen...   This effect does not occur if
// program exit is caused by selecting EXIT from the FILE menu or CLOSE
// from the system menu. That is (deliberate in my code) because in those
// cases the user has taken explicit interactive action to terminate the
// program so an extra prompt seems unnecessary. This behaviour provides
// at least one reason to use fwin_exit() rather than just exit().
//
extern bool fwin_pause_at_end;


//
// I will use some application-specific fonts with my code, and this is
// a function that arranges to make them evailable.

extern void add_custom_fonts();

//
// When debugging fint-related stuff it may be useful to see a full list
// of the fonts that are available. This function dumps that information
// to the standard output.

extern void display_font_information();

//
// fwin_minimize() indicates that the window should be shrunk to be just
// an icon.
// NOTE that if the command-line arguments to an application include
// "--", "-f" or "-F" then the application will be started off minimised.
// this is ugly and represents ways that options I want for *MY* application
// have crept in where things ought to be generic. My reasoning at one
// stage was that I wanted the window to be minimised right from the start
// so letting my code begin and then calling fwin_minimize would not be
// so good.
//
extern void fwin_minimize(void);

//
// fwin_restore() indicates that the window should be restored to
// regular size.
//
extern void fwin_restore(void);

//
// Rather than using putchar() and printf(), here are the calls
// the can be made to get output onto the screen.  NOTE that fwin_puts()
// is more like fputs than puts in that it just dumps the characters in its
// string to the screen [it does not add an extra newline in the way that
// puts does].
//
// fwin_putchar(c) treats c as a byte and puts exactly one byte into the
// UTS-8 stream of output. This is fully comfortable if the byte is in the
// range 0x00 to 0x7f and it represents a simple ASCII character. If the
// byte is in the range 0x80 to 0x7f it will generally represent one of the
// bytes that make up a multi-byte character. So if you use fwin_putchar and
// your internal data is in UTF-8 form everything behaves as you might expect.
// If you use it to send individual characters you must be careful with the
// ones that have codes over 0x7f. And if your internal data is in some
// 8-bit character set you may be in trouble.
//
extern void fwin_putchar(int c);

//
// fwin_putcode(n) lets n be an arbitrary integer character code and
// it dumps however many bytes are needed to represent this in UTF-8
// form. This means that eg fwin_putcode(0x269c) might transmit a
// fleur-de-lys, while to send that useing fwin_putchar would need
// use of the sequence 0xe2,0x9a,0x9c.
//

extern void fwin_putcode(int c);

//
// fwin_puts uses pwin_putchar on each byte in the string.
//
extern void fwin_puts(const char *s);

//
// The "showmath" capability is not yet developed here.
//
extern void fwin_showmath(const char *s);

extern void fwin_printf(const char *fmt, ...);
extern void fwin_vfprintf(const char *fmt, std::va_list a);

//
// fwin_linelength holds the number of normal-sized (ie the basic
// fixed-pitch font being used) characters that fit across the screen.
// My implementation of a window arranges to scale text so that this value
// is in fact ALWAYS just 80.
//
extern int fwin_linelength;

//
// fwin_ensure_screen() causes the display to catch up with whatever
// else has been going on. Thing "fflush(stdout)".
//
extern void fwin_ensure_screen(void);

//
// fwin_getchar() behaves rather as one might expect getchar() to - it
// grabs a character from the keyboard input buffer.
//
extern int fwin_getchar(void);

//
// fwin_set_prompt() tells wxfwin what string (of up to some limited
// number of characters) should be used as a prompt.
//

#define MAX_PROMPT_LENGTH 80

extern void fwin_set_prompt(const char *s);

//
// Clears screen.
//
extern void fwin_clear_screen();

//
// Returns window size (measured in character positions) packed as
//    (width << 16) + height
// Note that the width is always liable to be just 80.
//
extern int fwin_screen_size();

//
// The following function can be used to register a callback that is
// used to help expand file-names of the form "$xxx/yyy". It is given the
// "xxx" part and a character (which will be '$' or '@' - the two cases
// give two chances for lookup, one used ahead of checking system environment
// variables and the other after. If returns either a string that is the
// expansion or nullptr if there is none.
// If you do not register anything then no custom lookup is performed.
//
typedef char *lookup_function(char *s, int ch);

extern void fwin_set_lookup(lookup_function *f);


//
// wxfwin will call the function passed here before (with an arg of 1)
// and after (with an arg of 0) any time it is liable to delay. In
// particular when it might be about to block waiting for keyboard
// input. The idea is that this can be used to help the caller discount
// time spent in such cases.
//
typedef void delay_callback_t(int);

extern void fwin_callback_on_delay(delay_callback_t *f);

//
// wxfwin will call the function passed here to try to signal an
// exception to the worker thread. The idea is that the user-passed
// function can then do whatever it takes to synchronise with the
// worker. It can either signal the worker thread (but note that you need
// to do a bit of background reading before you try to mix exceptions
// and threads), or it can set a simple flag and the worker can poll.
//
// The intent is that if it passes QUIET_INTERRUPT or NOISY_INTERRUPT the
// worker is interrupted without or with it giving messages (eg a
// backtrace). If QUERY_INTERRUPT is passed no exception is raised, but
// the expectation is that 0 is returned if the previous exception has
// now been accepted and processed.
// The case TICK_INTERRUPT is to be triggered reasonably regularly to
// give the worker thread a chance to do any chores. It is NOT intended
// to disrupt the main thread of the computation.
//
// If wxfwin detects an interrupt condition while it is waiting for keyboard
// input or if it has generated an interrupt just before the start of
// such a wait and a QUERY_INTERRUPT call indicates that its interrupt
// request is still pending then as well as the activation of the callback
// function wxfwin_getchar returns promptly, discarding any typed-ahead
// stuff and returning character code 3 ("^C").
//
// If the callback function tries to raise exceptions etc then great care
// may be needed to ensure it can not abort the worker in the middle of
// a handshake where it synchronizes with the GUI thread.  Hmm yet more
// thought is called for here!
//

#define QUERY_INTERRUPT 0
#define TICK_INTERRUPT  1
#define QUIET_INTERRUPT 2
#define NOISY_INTERRUPT 3
#define QUIT_PROGRAM    4

// When a TICK is handed to the user the following should be called
// to confirm that it has been seen.
//
extern void fwin_acknowledge_tick();


//
// The following is just for use by REDUCE. It adjusts menu entries
// to support loading packages and setting/clearing REDUCE switches.
// The callback function will be invoked from time to time to keep the
// information up to date
//
typedef void review_switch_settings_function();

extern void fwin_menus(char **modules, char **switches,
                       review_switch_settings_function *f);

//
// The next is used when the application has re-set some switches without the
// GUI's help, and it updates the menu
//
extern void fwin_refresh_switches(char **switches, char **packages);


//
// Short messages can be displayed at the left middle and right of the
// main title-ribbon of your window.  These functions set the text to be
// displayed there.  If there is not much room then only the middle one
// will remain visible.  Each message should be limited to around 30 chars
// (and will be best if kept shorter than that).  The default position was
// once that the left position displayed the time & date (but it is
// now left blank), the middle one the name of the program being run and
// the right one is blank. fwin_report_left(nullptr) or fwin_report_mid(nullptr)
// re-instate the default display. Use fwin_report_left("") is a yet clearer
// way of indicating that blank info to the left is required.
//
extern void fwin_report_left(const char *msg);
extern void fwin_report_mid(const char *msg);
extern void fwin_report_right(const char *msg);

//
// The following four strings may be updated (but PLEASE keep within the
// length limit) to make the display in the "ABOUT" box reflect your
// particular application. Note that to avoid triggering additional LGPL
// requirements (that are akin to the original BSD "advertising clause")
// you should never make the strings here appear to be copyright notices,
// since if you do you are then obliged to extent them to include full
// copyright notices for any LGPL code you use anywhere. Well I may hope
// that the wxWidgets license avoid this pitfall via its exception to the
// LGPL, but to be on the safe side I suggest you still do not make these
// into "copyright notices".
//
extern char about_box_title[40];       // "About XXX";
extern char about_box_description[40]; // "XXX version 1.1";
// <icon appears here>
extern char about_box_rights_1[40];    // "Author";
extern char about_box_rights_2[40];    // "additional author";
//
// The next 2 lines will contain the text
//    "This software uses wxWidgets"
//    "(http://www.wxwidgets.org)"
// so as to give polite recognition to the wxWidgets team.
//

extern char about_box_rights_3[40];    // "Credit to wxWidgets";
extern char about_box_rights_4[40];    // "ditto";

//
// The HELP drop-down menu in wxfwin always has some basic items on it, but
// the user can add more by calling fwin_setHelpFile() where arg 1 is the
// text to appear on the menu and arg 2 identifies the help file that will be
// opened if the menu item is selected. Specifying nullptr as the second item
// removes the key. The information about help keys is kept in the registry
// not in any file that CSL has direct access to, and the new help items may
// not be visible until the user exits from CSL and re-starts it.
//
extern void fwin_set_help_file(const char *key, const char *path);

//
// The declarations below here are to be treated as private and should
// not be touched by users.
//
extern int plain_worker(int argc, const char *argv[],
                        fwin_entrypoint *fwin_main);
extern delay_callback_t *delay_callback;
extern interrupt_callback_t *interrupt_callback;

//
// The following three functions (putchar_overwrite, move_cursor_vertically
// and move_to_column) are not intended for use by end-users, and they
// only apply when fwin is running in windowed mode. They are used internally
// to support local editing and history.
//

//
// like fwin_putchar(), but overwrites what exists on the screen rather
// than inserting.
//
extern void fwin_putchar_overwrite(int c);

//
// Move the cursor up or down n lines. n is positive for movement
// down the screen.
//
extern void fwin_move_cursor_vertically(int n);

//
// Move the cursor directly to the indicated column. "0" indicates
// the first position in the row.
//
extern void fwin_move_to_column(int column);

//
// What follows is to do with a history mechanism... and again is not
// intended for public export.
//

#define INPUT_HISTORY_SIZE 100

extern wchar_t *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next;

extern void input_history_init();

extern void input_history_end();

extern void input_history_add(const wchar_t *s);

extern const wchar_t *input_history_get(int n);

//
// This is for version-specific control
//

#ifndef INT_VERSION
#define INT_VERSION(a,b,c) (((a*1000) + b)*1000 + c)
#endif

//
// By passing argv[0] to the following you can find the fully rooted
// name of the application that you are running. This may be useful if
// you want to put some resources (eg fonts) in the same directory as the
// executable. If the profram was launched by quoting the name of a symbolic
// link then that will be followed so that the path delivered is that of the
// true file.
//
extern int find_program_directory(const char *argv0);
extern const char *fullProgramName;        // eg "./fwin.exe"
extern const char *programName;            // eg "fwin.exe"
extern const char *programDir;             // eg "."

// Support for file date manipulation

typedef struct date_and_type_
{   unsigned long int date;
    unsigned long int type;
} date_and_type;

// Reinstate date and filetype...

extern void set_filedate(const char *name,
                         unsigned long int datestamp,
                         unsigned long int ftype);

extern void put_fileinfo(date_and_type *p, const char *name);

//
// Some things that are really intended to be private to the implementation
// but at present it seems easiest to mention them in this header rather
// than inventing a new header file.
//

extern int windowed;

extern int windowed_worker(int argc, const char *argv[],
                           fwin_entrypoint *fwin_main);

extern bool directoryp(char *f, const char *o, std::size_t n);

extern bool using_termed;

extern int fwin_plain_getchar();

extern int texmacs_mode;

#ifdef HAVE_SIGACTION
extern void sigint_handler(int signo, siginfo_t *t, void *v);
extern void sigbreak_handler(int signo, siginfo_t *t, void *v);
#else // !HAVE_SIGACTION
extern void sigint_handler(int signo);
extern void sigbreak_handler(int signo);
#endif // !HAVE_SIGACTION

extern int plain_worker(int argc, const char *argv[],
                        fwin_entrypoint *fwin_main);
extern char fwin_prompt_string[MAX_PROMPT_LENGTH];

extern int my_system(const char *cmd);
extern bool file_writeable(char *filename, const char *old,
                           std::size_t n);
extern bool file_readable(char *f, const char *o, std::size_t n);
extern int rename_file(char *from_name, const char *from_old,
                       std::size_t from_size,
                       char *to_name, const char *to_old, std::size_t to_size);
extern int truncate_file(std::FILE *f, long int where);
extern int get_current_directory(char *s, std::size_t n);

#endif // header_wxfwin_h

// end of "wxfwin.h"
