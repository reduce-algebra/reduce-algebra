// termed.cpp                              Copyright (C) 2004-2015 Codemist

/**************************************************************************
 * Copyright (C) 2015, Codemist.                         A C Norman       *
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
// Note that the above apply even when part of this code is used within
// an LGPL library such as FOX, even though binaries built from the
// complete work are subject to the LGPL.
//

// $Id$

//
// This supports modest line-editing and history for terminal-mode
// use of "fwin" applications.
//
// Major amounts of mess here are to try to keep things supported in both
// a Windows and a Unix-like world. For Windows I use the Console API to
// get direct contol of a screen. For Unix-like systems I demand that
// a "curses" package be available. But rather than using the high-level
// parts of "curses" I only use the low level functions - that is because the
// high level ones are generlly based on needing to clear the screen at
// that start and I do not want that. Also my cursor activity is really pretty
// simple and clever optimisation for it seems unnecessary.
//


//
// I need to think properly about characters outside the simple ASCII
// character set. There are (at least) four places where there is
// a chance for representations to apply:
// (1) When communicating with lower level code to read characters.
//     The Windows API that I use can return either an ASCII or a
//     Unicode representation of whatever character it reads, and
//     whatever else it hands back each keystroke that denotes a
//     characters as a single entity. Linux (and cygwin) seems to pass
//     back characters in Unicode encoded using UTF8, so that simple
//     ASCII characters with codes in the range 0x00 to 0x7f come back as
//     just one octet, but other characters are handed to me as a
//     sequence of octets.
// (2) When buffering material here (eg in the history record) I will
//     want to have some representation that will support recording and
//     searching. The partially complete input-line will need to
//     be stored so that I can perform local editing, and that will mean
//     I need to be able to check if characters in it are letters etc,
//     and I will need to be able to move backwards and forwards in the
//     buffer. Having one storage unit per character will probably make the
//     input line buffer easier to cope with.
// (3) Communication with the application that uses this interface (ie
//     CSL and Reduce!). This will be via the call "term_getline" which
//     returns a buffer full of characters. Existing code in CSL expects this
//     to be a buffer filled with 8-bit bytes of ASCII, so in the short
//     term at least that must be maintained. I think that there are two
//     plausible ways to go in the short term. One is to pack that buffer
//     using UTF8 and then all possible input characters can be handled, but
//     CSL will have trouble with ones whose code is 0x80 or higher. The
//     other is to return a truncated 8-bit Unicode value (and possibly to
//     map all Unicode chars from 0x100 upwards onto say "?"). I may
//     also want to provide a "term_wgetline" to get a line of wide characters
//     for a future when or if the application code can cope with that.
//     Returning input in UTF8 seems best if only because input from
//     files will often use that too.
// (4) Displaying characters on the terminal, both as genuine output from
//     (console-mode) CSL/Reduce and during line-editing. It seems that
//     under Windows I may need to use WriteConsoleW to write Unicode stuff
//     to the console. With Linux etc I will need to use UTF8.
//
// Throughout this there is an extra layer of murk that Windows uses UTF16
// and codes in the range d800 to dbff and dc00 to dfff are used when a code
// over ffff, with the high 10 bits in the d8xx surrogate coming first and
// then the low 10 in the dcxx unit. Code values that are in the surrogate
// range are not valid on their own. An effect of that is that on Windows
// the type wchar_t can not store all possible characters, so I need to
// decide if that worries me and if so what I can do. My plan at present
// is that on Linux (etc) where sizeof(wchar_t)==4 nothing special is
// needed. But when sizeof(wchar_t)==2 I will need to accept that some
// segments in a wide string are surrogate pairs. I think that the main
// things that this will involve me in will be:
// (1) the number of code units and the numbber of characters in a string
//     may differ.
// (2) moving one place backwards or forwards and deleting a single character
//     may involve two addressable units.
// (3) conversion to utf-8 may involve consolidating a surrogate pair
//     before expansion. Similarly utf-8 to wchar_t may involve creation of
//     surrogate pairs.
// (4) Any case folding must keep its hands off surrogate pairs. It would
//     be especially calamitous is folding a character changed how many units
//     it used!
// (5) Some character replacements that used to be trivial in-place may now
//     change the length of a string's representation.
// (6) By and large cursor editing and the evaluation of where on the screen
//     things need to appear is made messier!
//

//
// The next few #define statements are a clear indication of just how
// unpleasantly system-dependent this code has become. Eg _DARWIN_C_SOURCE
// must be defined ona Mac so that cfmakeraw gets properly defined by
// termios.h and _XOPEN_SOURCE and _BSD_SOURCE are similarly needed on Linux
// and/or Cygwin to allow access to low level terminal handling functions.
//
// However if I defined _XOPEN_SOURCE on a FreeBSD system that least to
// the declaration of cfmakeraw being HIDDEN rather than exposed.
//
// So I try to define the various special markers only on the platforms that
// they relate to.

#if defined __CYGWIN__ || defined __linux__
#define _XOPEN_SOURCE 500
#define _BSD_SOURCE 1
#endif
#if defined __APPLE__
#define _DARWIN_C_SOURCE 1
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//
// The following variables must hold arrays of strings to be used in
// the completion of various items... For CSL they are provided with
// useful values - for free-standing use they can be defined with
// the value NULL.
//

extern char **loadable_packages, **switches;


#ifdef WIN32

#include <windows.h>

#else // WIN32

#ifdef HAVE_NCURSES_H
#include <ncurses.h>
#else
#ifdef HAVE_CURSES_H
#include <curses.h>
#else
#define DISABLE 1
#if defined __GNUC__ || defined __clang__
#warning termed capabilites unavailable because neither ncurses.h nor curses.h were found.
#endif
#endif
#endif

#if defined HAVE_NCURSES_H && defined HAVE_NCURSES_TERM_H
#include <ncurses/term.h>
#else
#ifdef HAVE_TERM_H
#include <term.h>
#else
#ifdef HAVE_TGETENT
#define SIMULATE_TERM_H 1
#else
#ifndef DISABLE
#define DISABLE 1
#endif
#if defined __GNUC__ || defined __clang__
#warning termed capabilites unavailable because term.h (etc) was not found.
#endif
#endif
#endif
#endif

#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif

#endif // WIN32

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <string.h>
#ifndef UNDER_CE
#include <signal.h>
#endif

#include "termed.h"

//
// These are colors used when in curses/term/termcap mode
//

static const char *term_colour;

//
// The following are the colour codes supported by curses/term.
//
//   0  black     B, K, k
//   1  red       R, r
//   2  green     G, g
//   3  yellow    Y, y
//   4  blue      b         n.b. only lower case here!
//   5  magenta   M, m
//   6  cyan      C, c
//   7  white     W, w
//

#ifndef WIN32

static int map_colour(int ch)
{   switch (ch)
    {   case 'k': case 'K':
        case 'B':           return 0;
        case 'r': case 'R': return 1;
        case 'g': case 'G': return 2;
        case 'y': case 'Y': return 3;
        case 'b':           return 4;
        case 'm': case 'M': return 5;
        case 'c': case 'C': return 6;
        case 'w': case 'W': return 7;
        default:            return -1;
    }
}

#endif // WIN32

//
// The default values set here can be changed as a result of the colour
// option passed to term_setup.
//
static int promptColour = 4;   // Blue
static int inputColour  = 1;   // Red
#ifndef WIN32
static int outputColour = -1;  // whatever user had been using
#endif // WIN32

#ifndef DEBUG

#define LOG(...)

#else

#include <stdarg.h>

static FILE *termed_logfile = NULL;

static void write_log(char *s, ...)
{   va_list x;
    if (termed_logfile == NULL) termed_logfile = fopen("termed.log", "w");
    if (termed_logfile == NULL) termed_logfile = fopen("/tmp/termed.log", "w");
    va_start(x, s);
    vfprintf(termed_logfile, s, x);
    va_end(x);
}

#define LOG(...) \
    do { write_log("%d: ", __LINE__); write_log(__VA_ARGS__); } while (0)

#endif


//
// My support for a history mechanism here is really primitive and simple.
// I have a fixed size history buffer and just dump strings into it.
//

wchar_t *input_history[INPUT_HISTORY_SIZE];
wchar_t *pending_history_line = NULL;
int input_history_next = 0,
    input_history_current = 0,
    longest_history_line = 0;


void input_history_init(void)
{   int i;
    input_history_next = longest_history_line = 0;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
        input_history[i] = NULL;
    pending_history_line = NULL;
}

void input_history_end(void)
{   int i;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
    {   if (input_history[i] != NULL) free(input_history[i]);
    }
    if (pending_history_line != NULL) free(pending_history_line);
}


void input_history_stage(const wchar_t *s)
{   size_t n;
    if (s == NULL) return;
//
// The first line after a new prompt just simply forms the pending input
// line.
//
    if (pending_history_line == NULL)
    {   pending_history_line = (wchar_t *)
                               malloc((wcslen(s)+1)*sizeof(wchar_t));
        if (pending_history_line != NULL) // in case malloc fails
            wcscpy(pending_history_line, s);
        return;
    }
//
// Second and sunsequent lines get added to the end of the stored line, with
// "\n" characters to mark the line-breaks. This means that when I retrieve
// something from the history I will need to worry about those newlines
// and potentially how they display with or without associated prompts.
//
    n = wcslen(pending_history_line);
    pending_history_line = (wchar_t *)
                           realloc(pending_history_line, (wcslen(s) + n + 2)*sizeof(wchar_t));
    if (pending_history_line == NULL) return; // make be space leak here!
    pending_history_line[n] = '\n';
    wcscpy(pending_history_line+n+1, s);
}

void input_history_add(const wchar_t *s)
{   wchar_t *scopy;
    int p;
//
// If the line I am attempting to add is empty or is identical to the
// most recently added entry that is already present I will do nothing.
//
    if (s==NULL || *s==0) return;
    p = input_history_next;
    if (p > 0 &&
        (scopy = input_history[(p-1)%INPUT_HISTORY_SIZE]) != NULL &&
        wcscmp(s, scopy) == 0) return;
// Make a copy of the input string...
    scopy = (wchar_t *)malloc((wcslen(s) + 1)*sizeof(wchar_t));
    p = input_history_next % INPUT_HISTORY_SIZE;
// If malloc returns NULL I just store an empty history entry.
    if (scopy != NULL) wcscpy(scopy, s);
    LOG("History entry has %d characters in it\n", wcslen(s));
//
// I can overwrite an old history item here... I will keep INPUT_HISTORY_SIZE
// entries.
//
    if (input_history[p] != NULL) free(input_history[p]);
    input_history[p] = scopy;
    input_history_next++;
    if (scopy != NULL)
    {   p = wcslen(scopy);
        if (p > longest_history_line) longest_history_line = p;
    }
}

const wchar_t *input_history_get(int n)
{   const wchar_t *s;
//
// Filter our values that are out of range and in those cases return NULL
// as a flag to report the error.
//
    if (n == input_history_next) return L"";
    if (n < 0 ||
        n >= input_history_next ||
        n < input_history_next-INPUT_HISTORY_SIZE) return NULL;
    s = input_history[n % INPUT_HISTORY_SIZE];
// The NULL here would be if malloc had failed earlier.
    if (s == NULL) return L"";
    else return s;
}

//
// Sort of beware! I have fields in the class FXTerminal with the same
// names as these (static) variables and serving the same purpose (but for
// windowed applications). Do not get confused please. The two sets of
// values should never be active at the same time. If I were cleverer I
// would have found a good way to share more of the code and avoid
// this potential muddle.
//
static int historyFirst, historyNumber, historyLast;
static int searchFlags;


#define MAX_PROMPT_LENGTH 80

static wchar_t prompt_string[MAX_PROMPT_LENGTH+1] = L">";

wchar_t *input_line;
static wchar_t *display_line;
int prompt_length = 1, prompt_width = 1;
static int input_line_size;

//
// term_wide_plain_getline() can be called when cursor addressing is not
// available. It just reads characters into a line-buffer (which it
// extends as necessary). The data returned includes the newline
// that terminated the line. If an error is detected (and in particular
// at end of file) the value NULL is returned rather than a pointer to
// an array of characters.
//
// Nothing at all is done here to fuss about special characters, so
// things like ^C, backspace, ^Q etc etc etc are handled, if at all, by
// the system that underpins "getchar".
//

static void term_putchar(int c);

static wchar_t *term_wide_plain_getline(void)
{   int n, ch;
    int i;
#ifdef TERMED_TEST
    fprintf(stderr, "plain_getline:");
    fflush(stderr);
#endif
    for (i=0; i<prompt_length; i++) term_putchar(prompt_string[i]);
    fflush(stdout);
    if (input_line_size == 0) return NULL;
    input_line[0] = 0;
    n = 0;
    for (ch=getwchar(); ch!=WEOF && ch!=L'\n'; ch=getwchar())
    {
//
// I will expand the buffer so that if sizeof(wchar_t)==2 I have 1.5 times
// as many bytes as there are wchar_t items in use. This is so that when and
// if I convert to utf-8 format there will still be enough space. The most
// dangerous case would arise if the buffer contained a sequence of codes all
// in the range u+800 to u+ffff since each of those could fit in a 2 byte
// wchar_t but needs 3 bytes in utf-8.
//
        if ((n+20)*(5-sizeof(wchar_t)) >=
            input_line_size*(4/sizeof(wchar_t)))
        {   input_line =
                (wchar_t *)realloc(input_line, 2*input_line_size*sizeof(wchar_t));
            if (input_line == NULL)
            {   input_line_size = 0;
                return NULL;
            }
            else input_line_size = 2*input_line_size;
        }
        input_line[n++] = ch;
        input_line[n] = 0;
    }
    if (ch==WEOF)
    {   if (n == 0) return NULL;
    }
    else
    {   input_line[n++] = '\n';
        input_line[n] = 0;
    }
    return input_line;
}

//
// Before calling term_getline() or its variants use this to set the
// prompt string that will be displayed.
// A prompt string longer than the width of the terminal is liable to lead
// to bad confusion, and anyway prompts as passed are truncated. The
// character set used with this is 8-bit Unicode... but the stored prompt
// is in a wide string.
//

void term_setprompt(const char *s)
{   int i;
    prompt_length = prompt_width = strlen(s);
    LOG("prompt = %s len %d\n", s, prompt_length);
//
// I truncate prompts if they are really ridiculous in length since otherwise
// it may look silly.
//
    if (prompt_length > MAX_PROMPT_LENGTH) prompt_length = MAX_PROMPT_LENGTH;
//
// Here I widen the characters in the prompt by merely using the passed
// characters as the low 8-bits of each desired character. That is fine
// for 7-bit ASCII characters but not if the 8-bit values depend on some
// particular code page... I should probably (these days) allow the
// passed prompt to be an utf8 string and decode/convert it here. Note that
// dealing with characters beyond the basic multilingual plane will
// involve unpacking to utf16!
//
    for (i=0; i<prompt_length; i++)
    {   wint_t c = *s++ & 0xff;
        prompt_string[i] = c;
    }
    prompt_string[i] = 0;
//
// Now when I set a prompt I need to add the previous bunch of lines
// to the history.
//
    if (pending_history_line != NULL)
    {   input_history_add(pending_history_line);
//
// Adding an entry could cause an old one to be discarded. So I now ensure
// that I know what the first and last recorded numbers are.
//
        historyLast = input_history_next - 1;
        historyFirst = input_history_next - INPUT_HISTORY_SIZE;
        if (historyFirst < 0) historyFirst = 0;
        historyNumber = historyLast + 1; // so that ALT-P moves to first entry
        free(pending_history_line);
        pending_history_line = NULL;
    }
}

//
// Now a version that takes a wide string so that it is possible to
// set prompts that include characters with codes over 0xff, and at least
// up to 0xffff. On Windows there is a special nuisance if the truncation
// at MAX_PROMPT_LENGTH tries to truncate half way through a surrogate
// pair. In that case I will truncate one code earlier.
//

void term_wide_setprompt(const wchar_t *s)
{   prompt_length = wcslen(s);
// I truncate the prompt if it seems too long
    if (prompt_length > MAX_PROMPT_LENGTH) prompt_length = MAX_PROMPT_LENGTH;
//
// If I truncate it part way through a surrogate pair I need to lose
// both parts of the pair.
//
    if (prompt_length > 0 &&
        is_high_surrogate(prompt_string[prompt_length-1])) prompt_length--;
    wcsncpy(prompt_string, s, prompt_length);
    prompt_string[prompt_length] = 0;
//
// Now in the face of possible surrogate pairs the width in columns of the
// prompt may not be the same as the number of wchar_t items that make it
// up, so I will sort that out by counting units ignoring any high surrogates.
//
    prompt_width = 0;
    for (s=prompt_string; *s!=0; s++)
        if (!is_high_surrogate(*s)) prompt_width++;
}

#ifdef DISABLE
//
// In some cases this code can not be activated because not enough
// libraries are available. In that case I will provide stubs that do
// non-clever input. It may be that an external package or body of code
// will still be providing a good environment for the user.
//

//
// Start up input through this package. Returns 1 in this case because
// local editing is not supported on this platform. Hence the colour
// option is ignored.
//

int term_setup(int flag, const char *colour)
{
#ifdef TERMED_TEST
    fprintf(stderr,
            "term_setup in the DISABLE (no cursor addressability) case\n");
#endif
    input_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    if (input_line == NULL) input_line_size = 0;
    else input_line_size = 200;
    return 1;
}

//
// Before returning from your code it would be a really good idea to
// call "term_close" since that can re-set all sorts of terminal
// characteristics. In some cases use of "atexit" to ensure this will
// make sense.
//
void term_close(void)
{   if (input_line != NULL)
    {   free(input_line);
        input_line = NULL;
    }
}

static const int term_enabled = 0;

static wchar_t *term_wide_fancy_getline(void)
{   return NULL; // Should never be called
}

static void term_putchar(int c)
{
//
// The character passed here will actually be an wchar_t and probably if I
// was being truly proper the argument type would need to be wint_t not int.
// However I am going to be sloppy and assume that int is good enough. Well
// things are worse than that. I probably want the argument to be a 20-bit
// Unicode character and in some cases that will turn into a surrogate pair
// under Windows. But then I will need to be careful when writing from a
// (wchar_t *) style wide string where surrogates can already exist.
//
#ifdef WIN32
    DWORD nwritten;
    wchar_t buffer[4];
    if (c <= 0xffff)
    {   buffer[0] = c;
        WriteConsole(stdout_handle, buffer, 1, &nwritten, NULL);
    }
    else
    {   buffer[0] = 0xd800 + (((c - 0x10000) >> 10) & 0x3ff);
        buffer[1] = 0xdc00 + (c & 0x3ff);
        WriteConsole(stdout_handle, buffer, 2, &nwritten, NULL);
    }
#else
//
// Other than on Windows I will encode things using UTF-8
//
    unsigned char buffer[8];
    int i, n = utf_encode(buffer, c);
    for (i=0; i<n; i++)
    {   c = buffer[i];
#ifdef __CYGWIN__
//
// On Cygwin at the stage I am printing my terminal may be in RAW mode
// and so I need to send CR/LF for a newline. This seems to be the case
// just on Cygwin: on a typical Linux/Unix/BSD system I do not need this.
//
        if (c == '\n') putchar('\r');
#endif
        putchar(c);
    }
#endif
}

#else // DISABLE

#ifndef WIN32

static int stdin_handle, stdout_handle;

#endif

#ifdef SIMULATE_TERM_H
//
// if "term.h" is not available but the tgetent() function is then I will
// provide my own private term.h simulation here - just including the small
// number of features that I actually use.
//

static int columns = 80;
static int lines = 25;
static char *cursor_up = NULL;
static char *cursor_down = NULL;
static char *cursor_left = NULL;
static char *cursor_right = NULL;
static char *carriage_return = NULL;
static char *enter_reverse_mode = NULL;
static char *exit_attribute_mode = NULL;
static char *bell = NULL;
static char *clear_screen = NULL;
static char *set_a_foregound = NULL;
static char *set_foreground = NULL;
static char *orig_pair = NULL;
static char *orig_colors = NULL;

static char termcap_entry[1024];
static char my_entries[1024];

static int setupterm(char *s, int h, int *errval)
{   char *tt = getenv("TERM");
    char *p = my_entries;
    columns = 80;
    lines = 25;
//
// Just to feel tidy I will explicitly set all these to NULL as
// I start up.
//
    cursor_up = NULL;
    cursor_down = NULL;
    cursor_left = NULL;
    cursor_right = NULL;
    carriage_return = NULL;
    enter_reverse_mode = NULL;
    exit_attribute_mode = NULL;
    bell = NULL;
    clear_screen = NULL;
    if (tt == NULL) *errval = 0;
    else *errval = tgetent(termcap_entry, tt);
    if (*errval <= 0) return 0;
    cursor_up = tgetstr("up", &p);
    cursor_down = tgetstr("do", &p);
    cursor_left = tgetstr("le", &p);
    cursor_right = tgetstr("nd", &p);
    carriage_return = tgetstr("cr", &p);
    enter_reverse_mode = tgetstr("mr", &p);
    exit_attribute_mode = tgetstr("me", &p);
    bell = tgetstr("bl", &p);
    clear_screen = tgetstr("cl", &p);
    set_a_foregound = tgetstr("AF", &p);
    set_foregound = tgetstr("Sf", &p);
    orig_pair = tgetstr("op", &p);
    orig_colors = tgetstr("oc", &p);
    return OK;
}

static void putpc(int c)
{
//
// Here I will rely on being able to output a single octet without that
// messing up any UTF8ness etc. I will also not be sending '\n' this way.
//
    putchar(c);
}

static void putp(char *s)
{   tputs(s, 1, putpc);
}


#endif

#ifndef WIN32

static struct termios shell_term, prog_term, shell_term_o, prog_term_o;

static void my_def_shell_mode(void)
{   fflush(stdout);
    tcgetattr(stdin_handle, &shell_term);
    tcgetattr(stdout_handle, &shell_term_o);
}

static void my_reset_shell_mode(void)
{   fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &shell_term);
    tcsetattr(stdout_handle, TCSADRAIN, &shell_term_o);
    fflush(stdout);
}

static void my_def_prog_mode(void)
{   fflush(stdout);
    tcgetattr(stdin_handle, &prog_term);
    tcgetattr(stdout_handle, &prog_term_o);
}

static void my_reset_prog_mode(void)
{   fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &prog_term);
    tcsetattr(stdout_handle, TCSADRAIN, &prog_term_o);
}

#endif

//
// In case the system did not provide this I will supply the ANSI
// escape code and I will use that regardless...
//
#ifndef set_a_foreground
#define set_a_foreground "\e[3%dm"
#endif

#ifndef set_foreground
#define set_foreground NULL
#endif

//
// When the code is built it can still determine (dynamically) that it
// should not intervene, Eg when stdin/stdout have been redirected. When
// it is not enabled it can do simple getchar/putchar IO.
//

static int term_enabled = 0;

static int cursorx, cursory, final_cursorx, final_cursory, max_cursory;
int insert_point;

static int term_can_invert, invert_start, invert_end;

#ifdef WIN32
//
// The term/termios model provides "lines" and "columns" as macros.
// For Windows I manage them myself. By and large I will just not worry
// about "lines". The only case it ought to matter to me is if a user
// tries to enter a line of input that is so long that when wrapped
// it uses more lines of the screen than there are.
//
// To start with I will leave the behaviour in this case as a bug in my
// code. If I get keen I will revisit the situation later on.
//
static int lines, columns;

static HANDLE stdin_handle, stdout_handle;

static WORD plainAttributes, revAttributes, promptAttributes, inputAttributes;
static DWORD stdin_attributes, stdout_attributes;

#endif

extern int utf_encode(unsigned char *b, int c);

static void term_putchar(int c)
{
//
// The character passed here will be a Unicode character using up to 20
// bits...
// was being truly proper the argument type would need to be wint_t not int.
// However I am going to be sloppy and assume that int is good enough.
//
#ifdef WIN32
    DWORD nwritten;
    wchar_t buffer[4];
    if (c <= 0xffff)
    {   buffer[0] = c;
        WriteConsole(stdout_handle, buffer, 1, &nwritten, NULL);
    }
    else
    {   buffer[0] = 0xd800 + (((c - 0x10000) >> 10) & 0x3ff);
        buffer[1] = 0xdc00 + (c & 0x3ff);
        WriteConsole(stdout_handle, buffer, 2, &nwritten, NULL);
    }
#else
//
// Other than on Windows I will encode things using UTF-8
//
    unsigned char buffer[8];
    int i, n = utf_encode(buffer, c);
    for (i=0; i<n; i++)
    {   c = buffer[i];
#ifdef __CYGWIN__
        if (c == '\n') putchar('\r');
#endif
        putchar(c);
    }
#endif
}

//
// If possible I would like to be able to retrieve the actual size of
// the current screen, rather than relying on shell variables, like COLUMNS,
// that could possibly get out of step with reality.
//

static void measure_screen(void)
{
//
// I try to measure the size of the current window or terminal.
// on some systems I may not be able to!
//
#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO csb;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    columns = csb.srWindow.Right - csb.srWindow.Left + 1;
    lines = csb.srWindow.Bottom - csb.srWindow.Top + 1;
#else
#ifdef HAVE_SYS_IOCTL_H
#ifdef TIOCGWINSZ
    struct winsize ws;
    if (ioctl(stdin_handle, TIOCGWINSZ, &ws) != -1)
    {   if (ws.ws_col) columns = ws.ws_col;
        if (ws.ws_row) lines = ws.ws_row;
    }
#else
#ifdef TIOCGSIZE
    struct ttysize ws;
    if (ioctl(stdin_handle, TIOCGSIZE, &ws) != -1)
    {   if (ws.ts_cols) columns = ws.ts_cols;
        if (ws.ts_lines) lines = ws.ts_lines;
    }
#endif // TIOCGSIZE
#endif // TIOCGWINSZ
#endif // HAVE_SYS_IOCTL_H
#endif // WIN32
//
//  LOG("[screen:%dx%d]\n", columns, lines);
//
}

#ifdef WIN32
static INPUT_RECORD keyboard_buffer[1];

static UINT originalCodePage = 0;

static void resetCP()
{   SetConsoleOutputCP(originalCodePage);
}

#endif

int term_setup(int flag, const char *colour)
{
#ifdef WIN32
    DWORD w;
    CONSOLE_SCREEN_BUFFER_INFO csb;
#ifdef TERMED_TEST
    fprintf(stderr, "term_setup in the WIN32 case\n");
#endif
//
// It is VITAL to use "w+" as the access mode here for otherwise
// it is not possible to access the Console Output Buffer sufficiently.
//
    freopen("CONOUT$", "w+", stdout);
    term_enabled = 0;
    keyboard_buffer[0].Event.KeyEvent.wRepeatCount = 0;
    term_colour = (colour == NULL ? "-" : colour);
    input_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    display_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    if (input_line == NULL || display_line == NULL)
    {   input_line_size = 0;
#ifdef TERMED_TEST
        fprintf(stderr, "unable to allocate buffers\n");
#endif
        return 1;
    }
    else input_line_size = 200;
    if (!flag)
    {
#ifdef TERMED_TEST
        fprintf(stderr, "user asked for no local editing\n");
#endif
        return 1;
    }
//
// Standard input must be from a character device and must be accepted
// by the GetConsoleMode function
//
    stdin_handle = GetStdHandle(STD_INPUT_HANDLE);
    if (GetFileType(stdin_handle) != FILE_TYPE_CHAR)
    {
#ifdef TERMED_TEST
        fprintf(stderr, "stdin not CHAR type\n");
#endif
        return 1;
    }
    if (!GetConsoleMode(stdin_handle, &w))
    {
#ifdef TERMED_TEST
        fprintf(stderr, "could not get stdin console mode \n");
#endif
        return 1;
    }
//
// Standard output must be a character device and a ConsoleScreenBuffer
//
    stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#ifdef TERMED_TEST
    fprintf(stderr, "stdin handle = %p, stdout handle = %p\n", stdin_handle, stdout_handle);
#endif
    if (GetFileType(stdout_handle) != FILE_TYPE_CHAR)
    {
#ifdef TERMED_TEST
        fprintf(stderr, "stdout not CHAR type\n");
#endif
        return 1;
    }
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb))
    {
#ifdef TERMED_TEST
//
// This was here stdout_handled needed READ access as well as WRITE access.
// All the extra printing was useful while I was tracking that problem down!
//
        DWORD e = GetLastError();
        char *msg;
        fprintf(stderr, "trouble with GetConsoleScreenBufferInfo(stdout)\n");
        fprintf(stderr, "Error code = %d\n", (int)e);
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                      NULL,
                      e,
                      0,
                      (LPSTR)&msg,
                      0,
                      NULL);
        fprintf(stderr, "msg = %s\n", msg);
#endif
        return 1;
    }
    if (!GetConsoleMode(stdin_handle, &stdin_attributes) ||
        !GetConsoleMode(stdout_handle, &stdout_attributes))
    {
#ifdef TERMED_TEST
        fprintf(stderr, "trouble GetConsoleMode\n");
#endif
        return 1;
    }
    plainAttributes = csb.wAttributes;
    revAttributes = plainAttributes ^
                    (FOREGROUND_RED | BACKGROUND_RED |
                     FOREGROUND_GREEN | BACKGROUND_GREEN |
                     FOREGROUND_BLUE | BACKGROUND_BLUE |
                     FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
    promptAttributes = plainAttributes ^ FOREGROUND_BLUE;
    inputAttributes = plainAttributes ^ FOREGROUND_RED;
    if (!SetConsoleMode(stdout_handle, 0))
    {
#ifdef TERMED_TEST
        fprintf(stderr, "trouble setting stdout attributes\n");
#endif
        return 1;
    }
    if (!SetConsoleMode(stdin_handle,
                        ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
    {
#ifdef TERMED_TEST
        fprintf(stderr, "trouble setting stdin attributes\n");
#endif
        return 1;
    }
    columns = csb.srWindow.Right - csb.srWindow.Left + 1;
    lines = csb.srWindow.Bottom - csb.srWindow.Top + 1;
    SetConsoleMode(stdout_handle, stdout_attributes);
    term_can_invert = 1;
//
// If I am using the Unicode functions to write to the console then
// the issue of a code page for it becomes somewhat irrelevant!
//
    originalCodePage = GetConsoleOutputCP();
    atexit(resetCP);
    SetConsoleOutputCP(CP_UTF8);
#ifdef TERMED_TEST
    printf("Original page = %d.  \xc3\xbc\n", originalCodePage);
#endif
#else // WIN32
    int errval, errcode;
    char *s;
    struct termios my_term;
#ifdef TERMED_TEST
    fprintf(stderr, "term_setup in the non-Windows case\n");
#endif
    term_enabled = 0;
    term_colour = (colour == NULL ? "-" : colour);
    {   const char *s = term_colour;
        if (*s)
        {   int c = map_colour(*s++);
            if (c < 0) c = -1;
            outputColour = c;
        }
        if (*s)
        {   int c = map_colour(*s++);
            if (c < 0) c = 1;
            inputColour = c;
        }
        if (*s)
        {   int c = map_colour(*s++);
            if (c < 0) c = 4;
            promptColour = c;
        }
    }
    if (!flag) return 1;
    input_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    display_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    if (input_line == NULL || display_line == NULL)
    {   input_line_size = 0;
        return 1;
    }
    else input_line_size = 200;
    stdin_handle = fileno(stdin);
    stdout_handle = fileno(stdout);
//
// Check for redirected stdin/stdout.
//
    if (!isatty(stdin_handle) || !isatty(stdout_handle)) return 1;
//
// Next check if the terminal is one that we know about...
//
    s = getenv("TERM");
    if (s == NULL) s = "dumb";
    errcode = setupterm(s,               // terminal type
                        stdout_handle,   // ie to stdout
                        &errval);
    if (errcode != OK || errval != 1) return 1;

//
// I really want the very basic units of cursor movement to be available,
// and if they are not I will just give up.
//
    if (cursor_up == NULL ||
        cursor_down == NULL ||
        cursor_left == NULL ||
        cursor_right == NULL ||
        carriage_return == NULL) return 1;
    if (enter_reverse_mode != NULL &&
        exit_attribute_mode != NULL) term_can_invert = 1;
    else term_can_invert = 0;
//
// def_shell_mode() remembers the configuration of my terminal in the
// state before I alter any parameters. It saves information so that
// reset_shell_mode() can put things back the way they were. However
// with (at least) Ubuntu 9.10 these functions fail for me. Perhaps because
// they want me to be using a full "curses" window, not merely low-level
// access. So I provide my own versions with prefix "my_".
//
    my_def_shell_mode();
//
// I guess I am going to suppose here that stdin and stdout are both
// associated with the SAME terminal. If the computer had two (or more)
// terminals and stdin/stdout were attached to different ones then
// the use of tcgetattr/tcsetattr would only do things to the stdin
// one here.
//
    tcgetattr(stdin_handle, &my_term);
#ifdef HAVE_CFMAKERAW
//
// If I have cfmakeraw that is liable to be a definitive way of setting
// raw mode. Otherwise I will set the flags that I expect cfmakeraw to set.
// The one that it took be a while to spot was c_cc[VMIN] to ensure that
// reading characters still waits for at least one...
//
    cfmakeraw(&my_term);
#else
    my_term.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
                         INLCR | IGNCR | ICRNL | IXON);
    my_term.c_oflag &= ~OPOST;
    my_term.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    my_term.c_cflag &= ~(CSIZE | PARENB);
    my_term.c_cflag |= CS8;
    my_term.c_cc[VMIN] = 1;
    my_term.c_cc[VTIME] = 0;
#endif
//
// The tcsetattr HANGS if the console is detached/backgrounded when
// it is  performed, As in
//    ./reduce -v .... &
// unless SIGTTOU is blocked or ignored...
//
    signal(SIGTTOU, SIG_IGN);
    tcsetattr(stdin_handle, TCSADRAIN, &my_term);
    my_def_prog_mode();
    my_reset_shell_mode();
#endif // WIN32
    term_enabled = 1;
    input_history_init();
    historyFirst = historyNumber = 0;
    historyLast = -1;
    searchFlags = 0;
    invert_start = invert_end = -1;
    return 0;
}

void term_close(void)
{
//
// Note here and elsewhere in this file that I go "fflush(stdout)" before
// doing anything that may change styles or options for stream handling.
//
    fflush(stdout);
#ifdef WIN32
    if (term_enabled)
    {   SetConsoleMode(stdin_handle, stdin_attributes);
        SetConsoleMode(stdout_handle, stdout_attributes);
    }
#else
    if (term_enabled)
    {   my_reset_shell_mode();
    }
#endif
    term_enabled = 0;
    if (input_line != NULL)
    {   free(input_line);
        input_line = NULL;
    }
    if (display_line != NULL)
    {   free(display_line);
        display_line = NULL;
    }
}

//
// term_getchar() will block until the user has typed something. I will use
// this place as where I unravel various funny escape sequences that
// stand for uses of control keys. For all cases I will hand back a
// "basic character", but I will then OR in bits if ALT was pressed with it
// and others if it is not a simple key but a value returned to indicate a
// function key, arrow key etc etc. Regardless of the meaning of bits
// ORd in I will hand back EOF in some boundary cases. When using a Unix-
// style terminal (rather than Windows) I will just ignore invalid or
// unrecognized escape systems sent by the lower level terminal drivers.
//

#define TERM_UP     'A'
#define TERM_DOWN   'B'
#define TERM_RIGHT  'C'
#define TERM_LEFT   'D'
#define TERM_DELETE 'x'
#define TERM_HOME   '1'
#define TERM_END    '2'
#define TERM_INSERT 'y'

#define ALT_BIT    0x20000000
#define ARROW_BIT  0x40000000

static int term_getchar(void)
{
#ifdef WIN32
    DWORD n;
    int down, key, ascii, unicode, ctrl;
    for (;;)
    {
//
// I need to bother myself with repeat-counts. So in general there
// has been a call to inspect the keyboard before. If, after processing that
// I has a keyboard event with a residual repeat-count left over I will
// just have to handle that. Otherwise I need to call ReadConsoleInput to
// get some more. If that call fails I will return EOF as an error indication.
//
        if ((keyboard_buffer[0].EventType != KEY_EVENT ||
             keyboard_buffer[0].Event.KeyEvent.wRepeatCount == 0) &&
            !ReadConsoleInput(stdin_handle, keyboard_buffer, 1, &n))
        {   return EOF;
        }
//
// By the time I get here keyboard_buffer will hold an event. It might be
// one of a range of sorts! At present I only do anything at all with KEY
// events, but I could potentially look for mouse activity.
//
        switch (keyboard_buffer[0].EventType)
    {       default:              // Ignore non-keyboard event
                continue;
            case KEY_EVENT:
                keyboard_buffer[0].Event.KeyEvent.wRepeatCount--;
                down = keyboard_buffer[0].Event.KeyEvent.bKeyDown;
                if (!down) continue; // discard KEY-UP events
                key = keyboard_buffer[0].Event.KeyEvent.wVirtualKeyCode;
                ascii = keyboard_buffer[0].Event.KeyEvent.uChar.AsciiChar;
                unicode = keyboard_buffer[0].Event.KeyEvent.uChar.UnicodeChar;
                ctrl = keyboard_buffer[0].Event.KeyEvent.dwControlKeyState;
//
// If Windows thinks that the key that has been hit corresponded to an
// ordinary character than I will just return it. No hassle here! Well
// not quite so easy after all. If ALT is held down at the same time as
// the character I will or in the ALT_BIT bit.
//
// Ha Ha! "unicode==0" would apply in the case of "^@". By experiment the
// notionally system independent key-code for "@" is 0xc0 (well I can worry
// in case that is really for "'") do I test for that. Anyway at least
// with my keyboard this lets "^@" get through!
//
                if (key != 0x11) LOG("\nunicode=%x VK=%x ctrl=%x\n", unicode, key, ctrl);
                if (unicode != 0 || key == 0xc0)
                {   if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED))
                        unicode |= ALT_BIT;
                    return unicode;
                }
//
// Now use the variable "unicode" to record the state of the ALT key.
//
                if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED)) unicode = ALT_BIT;
                else unicode = 0;
//
// I map the Microsoft Key-Codes onto codes of my own. Observe that I do not
// support anything like all of the possible keys here, and that I do not
// detect SHIFT or CONTROL pressed in association with a function key. I will
// extend the tables here later if I feel moved to, but getting compatibility
// with the Unix-like case means I am unlikely to want to support every
// possible feature.
//
                switch (key)
            {       default:    continue;     // Ignore unknown keys
                    case VK_LEFT:
                        return unicode | TERM_LEFT | ARROW_BIT;
                    case VK_RIGHT:
                        return unicode | TERM_RIGHT | ARROW_BIT;
                    case VK_UP:
                        return unicode | TERM_UP | ARROW_BIT;
                    case VK_DOWN:
                        return unicode | TERM_DOWN | ARROW_BIT;
                    case VK_HOME:
                        return unicode | TERM_HOME | ARROW_BIT;
                    case VK_END:
                        return unicode | TERM_END | ARROW_BIT;
                    case VK_DELETE:
                        return unicode | TERM_DELETE | ARROW_BIT;
                }
        }
    }
#else
//
// In the Unix-like case I run a state-machine to grab sequences of
// characters by way of escape codes. One consequence of this is that
// a single ESC character is generally not passed through to the user.
// So far as I can discover at present I can not guarantee to detect
// "^@" here even though I am in raw mode. I fear that to handle that I
// may need yet lower levels of protocol...
//
#define BASE_STATE   0
#define ESC_STATE    1
#define ESC_BR_STATE 2

//
// What I should almost certainly be doing here involves the following
// variables that I have either set up for myself or that setupterm()
// established for me.
//
//  key_up = tgetstr("ku", &p);
//  key_down = tgetstr("kd", &p);
//  key_left = tgetstr("kl", &p);
//  key_right = tgetstr("kr", &p);
//  key_dc = tgetstr("kD", &p);
//  key_home = tgetstr("kh", &p);
//  key_end = tgetstr("@7", &p);
//
// So rather than trying to have a general state machine to parse things
// perhaps I could just check against the above strings (when they are
// non-NULL).
// HOWEVER when I look at the results from the above I find that in
// too many cases my HOME and END keys are not reported back to me, so I will
// go with ad-hoc decoding.
//
//    BASE --esc--> ESC --[--> ESC_BR --0/9--> DIG --other--> done
//                   |                          |
//              second ESC counted         digits and ";" absorbed
//


    int state = BASE_STATE, esc_esc = 0, ch, numval1=0, numval2=0;
    for (;;)
    {   int c1, c2, c3;
        ch = getchar();
        if (ch == EOF) return EOF;
        ch &= 0xff;
//
// Here I will swallow extra octets if the leading one seems to introduce
// an UTF multi-octet sequence
//
        switch (ch & 0xf0)
        {
//
//  case 0x00:
//  case 0x10:
//  case 0x20:
//  case 0x30:
//  case 0x40:
//  case 0x50:
//  case 0x60:
//  case 0x70:
//
            default:
                break;
            case 0x80:
            case 0x90:
            case 0xa0:
            case 0xb0:
// I map invalid UTF8 sequences onto question marks
                ch = L'?';
                break;  // out of place continuation marker
            case 0xc0:
            case 0xd0:
                c1 = getchar();
                if (c1 == EOF) return EOF;
                c1 &= 0xff;
                if ((c1 & 0xc0) != 0x80)
                {   ch = L'?';
                    break; // not continuation
                }
                ch = ((ch & 0x1f) << 6) | (c1 & 0x3f);
                break;
            case 0xe0:
                c1 = getchar();
                if (c1 == EOF) return EOF;
                c1 &= 0xff;
                if ((c1 & 0xc0) != 0x80)
                {   ch = L'?'; // not continuation
                    break;
                }
                c2 = getchar();
                if (c2 == EOF) return EOF;
                c1 &= 0xff;
                if ((c2 & 0xc0) != 0x80)
                {   ch = L'?'; // not continuation
                    break;
                }
                ch = ((ch & 0x0f) << 12) | ((c1 & 0x3f) << 6) | (c2 & 0x3f);
                break;
            case 0xf0:
                if ((ch & 0x08) != 0)
                {   ch = L'?';
                    break;
                }
                c1 = getchar();
                if (c1 == EOF) return EOF;
                c1 &= 0xff;
                if ((c1 & 0xc0) != 0x80)
                {   ch = L'?';
                    break;
                } // not continuation
                c2 = getchar();
                if (c2 == EOF) return EOF;
                c2 &= 0xff;
                if ((c2 & 0xc0) != 0x80)
                {   ch = L'?';
                    break;
                } // not continuation
                c3 = getchar();
                if (c3 == EOF) return EOF;
                c3 &= 0xff;
                if ((c3 & 0xc0) != 0x80)
                {   ch = L'?';
                    break;
                } // not continuation
                ch = ((ch & 0x07) << 18) | ((c1 & 0x3f) << 12) |
                     ((c2 & 0x3f) << 6) | (c3 & 0x3f);
                break;
        }
        LOG("RAW ch=%.2x : <%c>\n", ch, ch | 0x40);
        switch (state)
    {       default:
            case BASE_STATE:
//
// This is where I start. If I get anything other than ESC I just return
// it, but if I get ESC I progress a state.
//
                if (ch == 0x1b)
                {   state = ESC_STATE;
                    continue;
                }
                else return ch;
            case ESC_STATE:
//
// After ESC if the next character is another ESC I just count it, if
// the next character is [ (so I have had "ESC [" or "ESC ESC [") I
// progress, otherwise I treat the character as "escaped" and or in the
// "meta" bit ALT_BIT.
//
                if (ch == 0x1b)
                {   esc_esc ^= ALT_BIT;
                    continue;
                }
                else if (ch == '[')
                {   state = ESC_BR_STATE;
                    continue;
                }
                else return ch | ALT_BIT;
            case ESC_BR_STATE:
//
// After "ESC [" I absorb digits and semicolons.
//
                if (isdigit((unsigned char)ch))
                {   numval1 = 10*numval1 + ch - '0';
                    continue;
                }
                else if (ch == ';')
                {   numval2 = numval1;
                    numval1 = 0;
                    continue;
                }
//
// Now the whole code can be put together as one item... I will
// only look at the low 8 bits of any character that is just after an
// ESC.
//
                ch = (ch & 0xff) | (numval2 << 16) | (numval1 << 8);
//
// The table here represents the codes that I have come across thus far:
//
                esc_esc |= ARROW_BIT;
                switch (ch)
                {   case 0x010500+'A':
                    case 0x000000+'A': return esc_esc | TERM_UP;
                    case 0x010500+'b':
                    case 0x000000+'B': return esc_esc | TERM_DOWN;
                    case 0x010500+'C':
                    case 0x000000+'C': return esc_esc | TERM_RIGHT;
                    case 0x010500+'D':
                    case 0x000000+'D': return esc_esc | TERM_LEFT;
                    case 0x030500+'~':
                    case 0x000300+'~': return esc_esc | TERM_DELETE;
                    case 0x000100+'~':
                    case 0x010500+'H':
                    case 0x000000+'H': return esc_esc | TERM_HOME;
                    case 0x000400+'~':
                    case 0x010500+'F':
                    case 0x000000+'F': return esc_esc | TERM_END;
                    case 0x020500+'~':
                    case 0x000200+'~': return esc_esc | TERM_INSERT;
                    case 0x010300+'A': return (ALT_BIT|ARROW_BIT) | TERM_UP;
                    case 0x010300+'B': return (ALT_BIT|ARROW_BIT) | TERM_DOWN;
                    case 0x010300+'C': return (ALT_BIT|ARROW_BIT) | TERM_RIGHT;
                    case 0x010300+'D': return (ALT_BIT|ARROW_BIT) | TERM_LEFT;
                    case 0x030300+'~': return (ALT_BIT|ARROW_BIT) | TERM_DELETE;
                    case 0x010300+'H': return (ALT_BIT|ARROW_BIT) | TERM_HOME;
                    case 0x010300+'F': return (ALT_BIT|ARROW_BIT) | TERM_END;
                    case 0x020300+'~': return (ALT_BIT|ARROW_BIT) | TERM_INSERT;
                    default:           return ALT_BIT | ch;
                }
        }
    }
#endif
}




//
// Cursor movement functions are only wanted within this file and
// should only actually be called in the "enabled" case.
//

static void term_move_down(int del)
{
#ifdef WIN32
//
// Since the screen is on the same machine as the rest of my process, and
// I am in general interacting with a (slow) user here I will not try ANY
// optimisations at all!
//
    CONSOLE_SCREEN_BUFFER_INFO csb;
    if (del == 0) return;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    csb.dwCursorPosition.Y += del;
    SetConsoleCursorPosition(stdout_handle, csb.dwCursorPosition);
//
// I do not quite know if the above is always what I want! When I move down
// and I start on the line that is the lowest one on the screen I do really
// want a new line to appear for me to move onto.
//
    cursory += del;
    if (cursory > max_cursory) max_cursory = cursory;
#else
    cursory += del;
    if (cursory > max_cursory) max_cursory = cursory;
    fflush(stdout);
    while (del > 0)
    {   putp(cursor_down);
        del--;
    }
    while (del < 0)
    {   putp(cursor_up);
        del++;
    }
#endif
}


static void term_move_right(int del)
{
#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO csb;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    csb.dwCursorPosition.X += del;
    SetConsoleCursorPosition(stdout_handle, csb.dwCursorPosition);
//
// The above would be unsatisfactory if it ever happened that the
// movement was liable to take me beyond the width of the terminal, and
// there is a special worry about the bottom rightmost position on the
// screen, since it is not well supported by some terminals.
//
    cursorx += del;
    return;
#else
//
// As a small optimisation here if the target location is closer to the
// left margin than to the currect position (by at least 3) then
// issue a CR to move rapidly to the left margin and then sort out what
// else is needed.
//
    fflush(stdout);
    if (del<0 && (cursorx+del+3) < (-del))
    {   putp(carriage_return);
        del = cursorx + del;
        cursorx = 0;
    }
    cursorx += del;
//
// ... otherwise I position the cursor by doing dull sequences that move the
// cursor one position at a time.
//
    while (del > 0)
    {   putp(cursor_right);
        del--;
    }
    while (del < 0)
    {   putp(cursor_left);
        del++;
    }
#endif
}

static void term_move_first_column(void)
{
#ifdef WIN32 // OK
    CONSOLE_SCREEN_BUFFER_INFO csb;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    csb.dwCursorPosition.X = 0;
    SetConsoleCursorPosition(stdout_handle, csb.dwCursorPosition);
    cursorx = 0;
    return;
#else
    fflush(stdout);
    putp(carriage_return);
    cursorx = 0;
#endif
}

static void term_bell(void)
{
#ifdef WIN32
    Beep(1000, 100);
#else
    if (term_enabled && bell) putp(bell);
    else putchar(0x07);
#endif
}

//
// I call refresh_display() to get the screen up to date with what my
// internal model expects.  The data I base this on will be:
//     input_line      a string showing what I want displayed
//    !display_line    the string I had last displayed
//     insert_point    the offset in input_line that I want the cursor
//                     to end up at
//    !cursorx         the current X coordinate on the cursor on the scren,
//                     where 0 indicated the leftmost column
//    !cursory         the current Y coordinate, where 0 is the line that
//                     the active input line's display starts (and positive
//                     coordinates indicated lines below that)
//    !final_cursorx   x-coordinate of rightmost visible character on the
//                     screen at present.
//    !final_cursory   y-coordinate ditto
//    !max_cursory     largest value of cursory used thus far
//     columns         width of the screen
//     lines           height of the screen
//     term_can_invert display is capable of inverse video
//     invert_start,
//     invert_end      region (if any) to highlight.
//
// [I have annotated items that are updated here with (!)]
//
// The main complications that arise are
// (a) input_line may contain characters that should be rendered across
//     several columns. The key case that forces this is TAB, but once
//     that has been conceded it may make sense to render control characters
//     so that eg '\04' is dispalyed as "^D" and so that other unprintable
//     characters that may get into the buffer by accident are handled
//     kindly.
//     [as a late bit of imagination I might like to render an embedded
//     newline character ('\n') as a line-break]
// (b) input_line (with or without TABs!) can stand for a line that is
//     longer than the line-length shown by "columns". In that case the
//     expected representation on the screen will involve wrapping it.
//     proper treatment of wrapping and scrolling and the final character
//     position on the screen all need attention.
//
// (c) In extreme cases wrapping could lead to a display using too many
//     lines, and in that case further truncation is needed.
// (d) After a case where the user re-sizes the screen the issue of what is
//     visible on the screen, where the cursor is and in general what to do
//     to regain sanity seems pretty delicate!
//

//
// With my first version of the code here I will not handle either (c) or (d)
// a lot. Well maybe in fact (d) gets coped with by virtue of the total
// screen re-write..., and I check screen size (if I can) whenever I am
// about to refresh.
//
// The code here updates from the first changed position of a line right to
// the end. If the user has re-positioned the cursor so they are making edits
// towards the start of a long line this can lead to excessive screen
// update actvity. If this ever became a worry there are two things I could
// do:
//  (1) check for and exploit delete and insert modes for my screen and use
//      them where helpful
//  (2) notice when the tail of a line does not need change and avoid
//      re-writing in in that case.
// Actually I do not count these as high priority - mostly because screens
// etc etc are now usually very fast. Also inserts mid-line will be less
// common than just adding characters at the end.
//

//
// line_wrap() is a part of refresh_display(), and it prints a character
// taking care of line-wrapping. The character passed will be of flavour
// wchar_t. The character may be a value over 0xffff and in the Windows case
// that will need to end up in the buffer as a surrogate pair. I also note
// that the existing buffer may contain such pairs...
//

static int line_wrap(int ch, int tab_offset)
{
//  LOG("wrap_line ch=%#x tab_offset=%d cursorx=%d\n", ch, tab_offset, cursorx);
    cursorx++;
    if (cursorx >= columns)
    {   tab_offset += cursorx;
//
// When the line I am wrapping is the final one of my stuff I will be super
// careful and not write the character until it will no longer be at the
// final position on the screen. I do this because some (but perhaps not
// all) terminals force a scroll when that final character is filled in,
// and for that to happen and for me to be not quite certain just what the
// situation was would be terrible.
//
//
// I could imagine that if cursory==max_cursory here I could need to do
// something special to move down a row to ensure that if I am on the bottom
// row of the screen I scroll properly... What I do here with a hope that it
// counts as "on the safe side" is to switch back to cooked mode before
// outputting a newline character.
//
        if (cursory == max_cursory)
        {   term_move_first_column();
            LOG("need to scroll page\n");
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, stdout_attributes);
#else
            my_reset_shell_mode();
#endif
            term_putchar('\n');
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, 0);
#else
            my_reset_prog_mode();
#endif
            cursory++;
            max_cursory = cursory;
//
// Now I have performed the scroll, so I will go back and insert the
// character. I very much hope that this time writing to the last position on
// a row does not do anything special at all about the cursor or scrolling.
//
            term_move_down(-1);
            term_move_right(columns-1);
            term_putchar(ch);
            term_move_first_column();
            term_move_down(1);
        }
        else
        {   term_putchar(ch);
            term_move_first_column();
            term_move_down(1);
        }
    }
    else term_putchar(ch);
    return tab_offset;
}

static void refresh_display(void)
{
//
// The version here right now is done as directly as I can without
// thought for optimisation. That is in the hope that I can get it
// right, and then put in performance upgrades later on.
//
    int i, ch, inverse = 0,
               tab_offset = 0,
               curx=columns, cury=lines,
               finx, finy, window_size_changed;
//
//  LOG("refresh_display cx=%d cy=%d\n", cursorx, cursory);
//  LOG("il:<%ls>\ndl:<%ls>\n", input_line, display_line);
//
//
// Rather than believing in any SIGWINCH signal (or some such!) to alert
// me to screen size changes, I will (on systems that give me a way to)
// check the screen size every time I am about to do a screen update. This
// may feel like a cost, but it is incurred when the user has hit a key
// so may not be noticed too much. Well I can see that it can call for
// a handshake between the terminal and this program so on systems with
// remote access and slow lines it may well put in a noticable screen-update
// delay - if that proves the case I will need to review what I do.
//
    measure_screen();
//
// Check if the screen-size has changed since last time.
// At present since I re-draw the whole input line every time changes
// in screen size make no difference to me and so I just ignore the
// information I collect here, but as I start to optimise my screen
// update I will need to look at it more carefully.
//
    window_size_changed = (curx!=columns || cury!=lines);
    if (window_size_changed)
    {
//
// I want to force a fairly complete re-write here, so I explain that
// the screen now holds stuff that is totally different to what is
// desired, and that there may be residual stuff on the screen down as far
// as the almost-rightmost column of the bottom line that I have ever put
// anything on.
//
        LOG("Window size has changed\n");
        display_line[0] = input_line[0] + 1;
        display_line[1] = 0;
        final_cursory = max_cursory;
        final_cursorx = columns-1;
        term_move_first_column();
    }
    finx = finy = 0;
    i = 0;
    while ((ch = input_line[i]) != 0 &&
           display_line[i] == ch &&
           (!term_can_invert || i!=invert_start))
    {   if (i == insert_point)
        {   curx = finx;
            cury = finy;
        }
        if (ch == L'\t')
        {   do
            {   finx++;
                if (finx >= columns)
                {   tab_offset += finx;
                    finx -= columns;
                    finy++;
                }
            }
            while ((tab_offset + finx)%8 != 0);
        }
        else if (ch == L'\n')
        {   tab_offset = 0;
            finx = 0;
            finy++;
        }
//
// I am going to display characters whose code is in the range 0x00 to
// 0x1f with a "^", as in "^C" will denote character 3. I am not certain that
// this is a good idea!!! But I rather hope that such characters will
// not get into the buffer, and at least this makes them visible if they do.
//
        else if (ch < 0x20) finx += 2;
        else if (!is_low_surrogate(ch)) finx += 1;
        if (finx >= columns)
        {   tab_offset += finx;
            finx -= columns;
            finy++;
        }
        i++;
    }
//
// Start my moving to the beginning of the where I must write stuff...
//
    term_move_right(finx - cursorx);
    term_move_down(finy - cursory);
//
// Re-display all of the current input line. In may cases this
// will do all the re-drawing needed, but beware if the existing displayed
// line is longer (because I have just deleted something). While drawing
// the current line when I reach the insert_point I will record the cursor
// position.
//
    for (; (ch = input_line[i])!=0; i++)
    {   if (i == insert_point)
        {   curx = cursorx;
            cury = cursory;
        }
        if (term_can_invert && invert_start<invert_end && i==invert_start)
        {   fflush(stdout);
#ifdef WIN32
            SetConsoleTextAttribute(stdout_handle, revAttributes);
#else
            putp(enter_reverse_mode);
#endif
            inverse = 1;
        }
        if (term_can_invert && invert_start<invert_end && i==invert_end)
        {   fflush(stdout);
#ifdef WIN32
            SetConsoleTextAttribute(stdout_handle, plainAttributes);
#else
            putp(exit_attribute_mode);
#endif
            inverse = 0;
        }
//
// A horrid case arises here. If the cursor starts off close to the right
// hand side of the window and a TAB is issued than it might wrap. Well
// that in itself is OK. However if the screen width is not a multiple of
// the tab spacing then in effect tab-stops on the second and subsequent
// lines of the display of the wrapped line will need to allow for this.
// The variable "tab_offset" is allowing for the characters on previous as
// well as this line.
// I am also ignoring all possibility that Unicode code points other
// than TAB and NEWLINE have other than regular width, so for instance
// zero-width spaces will not be handled well.
//
        if (ch == L'\t')
        {   do
            {   tab_offset = line_wrap(L' ', tab_offset);
            }
            while ((tab_offset + cursorx)%8 != 0);
        }
        else if (ch == L'\n')
        {
//
// Here I want a line-break in the "single line" I am displaying. I achieve
// the effect I want by writing blanks until cursorx gets back to zero by
// virtue of line-wrapping!
//
            while (cursorx !=  0) line_wrap(L' ', 0);
//
// Tabs should now be relative to the new line-start.
//
            tab_offset = 0;
        }
        else if (ch < 0x20)
        {   tab_offset = line_wrap(L'^', tab_offset);
            // Turn into @, A, B etc
            tab_offset = line_wrap(ch | 0x40, tab_offset);
        }
        else if (is_high_surrogate(ch))
        {   int ch1 = input_line[++i];
            ch = 0x10000 + ((ch & 0x3ff) << 10) + (ch1 & 0x3ff);
            tab_offset = line_wrap(ch, tab_offset);
        }
        else tab_offset = line_wrap(ch, tab_offset);
    }
//
// Clear inverse video mode.
//
    if (inverse)
    {   fflush(stdout);
#ifdef WIN32
        SetConsoleTextAttribute(stdout_handle, plainAttributes);
#else
        putp(exit_attribute_mode);
#endif
    }
    if (invert_start >= invert_end) invert_start = invert_end = -1;
    if (i == insert_point)
    {   curx = cursorx;
        cury = cursory;
    }
//
// Now the input line may have shrunk because of a deletion so there may be
// bits of the display line remaining. I need to replace them with blanks.
// Because I expect to be filling neatly up to the right hand end of the
// line and I will never be creating an extra row here I do not need to
// use line_wrap.
//
    finx = cursorx;
    finy = cursory;
//
// If the cursor is now positioned below where the previously-displayed line
// finished there is no joy at all in doing any padding to try to overwrite
// left-over bits of that previous line.
//
    if (cursory <= final_cursory)
    {   while (cursory < final_cursory)
        {   while (cursorx < columns)
            {   term_putchar(' ');
                cursorx++;
            }
            term_move_first_column();
            term_move_down(1);
        }
        while (cursorx < final_cursorx)
        {   term_putchar(' ');
            cursorx++;
        }
    }
//
// record where real output finished this time
//
    final_cursorx = finx;
    final_cursory = finy;
//
// Move the cursor to where it needs to appear.
//
    if (cury != cursory) term_move_down(cury-cursory);
    if (curx != cursorx) term_move_right(curx-cursorx);
    fflush(stdout);
//
// Now the display should be up to date, so record that situation.
//
    wcscpy(display_line, input_line);
}

static void term_set_mark(void)
{
//
// Actually I will not (at present) do anything here! And furthermore I
// have a degree of pain. When I try running on a Unix-like system even
// after setting "raw" mode I do not get all the chars that I want...
//
    term_bell();
    refresh_display();
}


static void term_to_start(void)
{   insert_point = prompt_length;
    refresh_display();
}


static void term_to_end(void)
{   while (input_line[insert_point] != 0) insert_point++;
    refresh_display();
}


//
// The next two just find where the position to left or right is, searching
// by words, with a FOX-like interpretation of the term "word", which I
// hope will also be an emacs-like interpretation.
//

static int term_find_next_word_forwards(void)
{   int n = insert_point;
    if (input_line[n] == 0) return n;
    do
    {   n++;
    }
    while (input_line[n] != 0 &&
           ((!is_surrogate(input_line[n]) && iswalnum(input_line[n])) ||
            input_line[n] == L'_'));
    if (is_high_surrogate(input_line[n])) n++; // avoid middle of surrogate
    while (!is_surrogate(input_line[n]) && iswspace(input_line[n])) n++;
    return n;
}

static int term_find_next_word_backwards(void)
{   int n = insert_point;
    if (n == prompt_length) return n;
    do
    {   n--;
    }
    while (n != prompt_length &&
           ((!is_surrogate(input_line[n]) && iswalnum(input_line[n])) ||
            input_line[n] == '_'));
    if (n != prompt_length &&
        is_high_surrogate(input_line[n])) n--;
    while (n != prompt_length &&
           !is_surrogate(input_line[n]) &&
           iswspace(input_line[n])) n--;
    if (n == prompt_length || n == insert_point-1) return n;
    else return n+1;
}

static void term_forwards_char(void)
{   if (input_line[insert_point] == 0) term_bell();
    else insert_point++;
    if (is_high_surrogate(input_line[insert_point])) insert_point++;
    refresh_display();
}


static void term_forwards_word(void)
{   if (input_line[insert_point] == 0) term_bell();
    else
    {   insert_point = term_find_next_word_forwards();
        refresh_display();
    }
}


static void term_back_char(void)
{   if (insert_point == prompt_length) term_bell();
    else insert_point--;
    if (insert_point != prompt_length &&
        is_high_surrogate(input_line[insert_point])) insert_point--;
    refresh_display();
}

static void term_back_word(void)
{   if (insert_point == prompt_length) term_bell();
    else
    {   insert_point = term_find_next_word_backwards();
        refresh_display();
    }
}


static void term_delete_forwards(void)
{   int i = insert_point;
//
// If the unit at the insertion point is a high surrogate I must delete
// two units not just one - ie the high and then the low surrogate.
//
    if (is_high_surrogate(input_line[i]))
    {   input_line[i] = ' ';
        term_delete_forwards();
    }
    if (input_line[i] == 0) term_bell();
    else for (;;)
        {   input_line[i] = input_line[i+1];
            if (input_line[i] == 0) break;
            i++;
        }
    refresh_display();
}


static void term_delete_backwards(void)
{   if (insert_point == prompt_length) term_bell();
    else
    {   int i = insert_point - 1;
        insert_point = i;
        for (;;)
        {   input_line[i] = input_line[i+1];
            if (input_line[i] == 0) break;
            i++;
        }
    }
//
// If I just deleted a low surrogate so that there is now a high one left
// then I need to delete that too.
//
    if (insert_point != prompt_length &&
        is_high_surrogate(input_line[insert_point-1]))
        term_delete_backwards();
    refresh_display();
}


static void term_delete_word_forwards(void)
{   if (input_line[insert_point] == 0) term_bell();
    else
    {   int i = insert_point;
        int n = term_find_next_word_forwards() - insert_point;
        for (;;)
        {   input_line[i] = input_line[i+n];
            if (input_line[i] == 0) break;
            i++;
        }
        refresh_display();
    }
}


static void term_delete_word_backwards(void)
{   if (insert_point == prompt_length) term_bell();
    else
    {   int i = term_find_next_word_backwards();
        int n = insert_point - i;
        insert_point = i;
        for (;;)
        {   input_line[i] = input_line[i+n];
            if (input_line[i] == 0) break;
            i++;
        }
    }
    refresh_display();
}


static void term_kill_line(void)
{   insert_point = prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static void term_history_next(void)
{   const wchar_t *history_string;
    if (historyLast == -1)
    {   term_bell();
        return;
    }
    if (historyNumber < historyLast) historyNumber++;
    if ((history_string = input_history_get(historyNumber)) == NULL)
    {   term_bell();
        return;
    }
    insert_point = wcslen(history_string);
    wcsncpy(input_line+prompt_length, history_string, insert_point);
    insert_point += prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static void term_previous_history(void)
{   const wchar_t *history_string;
    if (historyLast == -1) // no previous lines to retrieve
    {   term_bell();
        return;
    }
//
// If I have not moved the history pointer at all yet move it into the
// range of valid history entries.
//
    if (historyNumber > historyFirst) historyNumber--;
    history_string = input_history_get(historyNumber);
    if (history_string == NULL)
    {   term_bell();
        return;
    }
    insert_point = wcslen(history_string);
    wcsncpy(input_line+prompt_length, history_string, insert_point);
    insert_point += prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static int regular_line_end = 0;
static int search_saved_point = 0;
static int search_found = 0;
static wchar_t searchBuff[100];
static int searchStack[100];
static int searchLen;

static void term_search_next(void)
{
//
// I remember where I was on the input line but then move to the end and
// append a message that indicates to the user that a search is in progress.
//
    search_found = search_saved_point = insert_point;
    regular_line_end = wcslen(input_line);
    wcscpy(&input_line[regular_line_end], L"\nN-search: ");
    insert_point = regular_line_end + 11;
    searchLen = 0;
    searchBuff[0] = 0;
    searchFlags = 1;
    refresh_display();
}


static void term_search_previous(void)
{   search_found = search_saved_point = insert_point;
    regular_line_end = wcslen(input_line);
    wcscpy(&input_line[regular_line_end], L"\nP-search: ");
    insert_point = regular_line_end + 11;
    searchLen = 0;
    searchBuff[0] = 0;
    searchFlags = -1;
    refresh_display();
}

static int matchString(const wchar_t *pat, int n, const wchar_t *text)
{
//
// This is a crude and not especially efficient pattern match. I think
// it should be good enough for use here! I make it return the offset where
// a match first occurred (if one does) in case that will be useful to me
// later. I could put the cursor there, perhaps?
//
    int offset;
    for (offset=0; *(text+offset)!=0; offset++)
    {   const wchar_t *p = pat, *q = text+offset;
        int i;
        for (i=0; i<n; i++)
        {   if (p[i] != q[i]) break;
        }
        if (i == n) return offset;
    }
    return -1;
}


static int trySearch(void)
{   int r = -1;
    const wchar_t *history_string = input_history_get(historyNumber);
    if (history_string == NULL) return -1;
    while ((r = matchString(searchBuff, searchLen, history_string)) < 0)
    {   if (searchFlags > 0)
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

//
// After a success in a search this sets the input line to the given
// text. The real mess here is that it has to stick the search text
// on the end. And a further worry might be buffer overflow... Suppose that
// the lines searched so far have all been just the same length as the search
// string, and that this is quite long. Now we have searched and found a
// line that is much longer. The line itself just about filled the
// input line buffer, and when the search string is stuck on its end it
// overflows. Oh woe.  Well look later on and you will see that I keep track
// of the longest line I have stuck into the history and I measure against
// that when accepting search characters. So do not worry after all!!
//
static void set_input(const wchar_t *s)
{   wcscpy(&input_line[prompt_length], s);
    insert_point = prompt_length + wcslen(s);
    regular_line_end = insert_point;
    input_line[insert_point++] = L'\n';
    input_line[insert_point++] = searchFlags > 0 ? L'N' : L'P';
    wcscpy(&input_line[insert_point], L"-search: ");
    insert_point += 9;
    wcscpy(&input_line[insert_point], searchBuff);
    insert_point += searchLen;
}

#ifdef CTRL
#undef CTRL
#endif
#define CTRL(n) ((n) & 0x1f)

//
// This is called when I am in the process of searching and a character is
// typed.
// Returns true if searching must continue, or false if searchMode has been
// left. While in search mode I will keep insert_point at the end of the
// buffer.
//

static int term_search_char(int ch)
{   switch (ch)
    {
//
// ALT-N and ALT-Down continue the search using the current search string
// but searching through the Next history item
//
        case CTRL(L'N') + ALT_BIT: case L'N' + ALT_BIT: case L'n' + ALT_BIT:
        case ARROW_BIT + TERM_DOWN + ALT_BIT:
            searchFlags = 1;    // search downwards
            if (historyNumber >= historyLast) term_bell();
            else
            {   int r;
                int save = historyNumber;
                historyNumber++;
                r = trySearch();
                if (r == -1)
                {   historyNumber = save;
                    term_bell();
                    return -1;
                }
                search_found = r;
                set_input(input_history_get(historyNumber));
                invert_start = prompt_length + search_found;
                invert_end = invert_start + searchLen;
                refresh_display();
            }
            return 1;
//
// ALT-P and ALT-Up continue the search using the current search string
// but searching through the Previous history item
//
        case CTRL(L'P') + ALT_BIT: case L'P' + ALT_BIT: case L'p' + ALT_BIT:
        case ARROW_BIT + TERM_UP + ALT_BIT:
            searchFlags = -1;    // search upwards
            if (historyNumber <= historyFirst) term_bell();
            else
            {   int r;
                int save = historyNumber;
                historyNumber--;
                r = trySearch();
                if (r == -1)
                {   historyNumber = save;
                    term_bell();
                    return 1;
                }
                search_found = r;
                set_input(input_history_get(historyNumber));
                invert_start = prompt_length + search_found;
                invert_end = invert_start + searchLen;
                refresh_display();
            }
            return 1;

//
// Ctrl-H deletes exist search mode if the search string is empty, otherwise
// it deletes a char from the search string and pops back to wherever the
// shorter string had matched.
//
        case CTRL(L'H'):                   // Backspace
        case 0x7f:                         // Delete
            if (searchLen != 0)
            {   input_line[--insert_point] = 0;
                searchBuff[--searchLen] = 0;
                historyNumber = searchStack[searchLen];
                search_found = trySearch();   // ought to succeed
                set_input(input_history_get(historyNumber));
                invert_start = prompt_length + search_found;
                invert_end = invert_start + searchLen;
                refresh_display();
                return 1;
            }
            else
            {   term_bell();
                ch = CTRL('U');  // Drop through to exit search mode
            }
//
// Control characters (except TAB) and things tagged with ESC cause an exit
// from search mode.
//
        default:
            if ((ch & (ALT_BIT|ARROW_BIT)) != 0 ||
                (ch != L'\t' && ch<0x20))
            {
//
// Exit search mode
//
                searchFlags = 0;
//
// The approved means of switching some highlights off is as follows. This
// leads the next refresh_display to re-write the bit that had previously
// been in inverse video... ie leave invert_start at the start of where
// inverting had started, but set invert_end to the same value.
//
                invert_end = invert_start;
                input_line[regular_line_end] = 0;
                insert_point = prompt_length + search_found + searchLen;
                refresh_display();
//
// "^U" will exit search mode, and when it does that it does not do anything
// else. Even if there were ever a time that I had implemented an UNDO
// facility, which I think I am not about to.
//
                return (ch & (~(ALT_BIT|ARROW_BIT))) == CTRL(L'U');
            }

    }
//
// So not accept search characters beyond some limit since I have a fixed-
// size buffer for the search string. Just beep and ignore the chararcter.
//
    if (searchLen > 98)
    {   term_bell();
        return 1;
    }
    searchStack[searchLen] = historyNumber;
    searchBuff[searchLen++] = ch;
    searchBuff[searchLen] = 0;
//
// Now perform a search...
//
    {   int r;
        int save = historyNumber;
        if ((r = trySearch()) == -1)
        {   historyNumber = save;         // search failed this time
            searchBuff[--searchLen] = 0;
            term_bell();
            return 1;
        }
        search_found = r;
        set_input(input_history_get(historyNumber));
        invert_start = prompt_length + search_found;
        invert_end = invert_start + searchLen;
    }
    refresh_display();
    return 1;
}

static int term_find_word_start(void)
{
//
// If the insert point points at an alphemumeric character this ends up
// returning the address of the first letter of the "word". If the
// initial point is not on an alphanumeric it returns a pointer one to the
// right of the insert point.
// /* surrogate pairs
//
    int n = insert_point;
    while (n>=prompt_length &&
           (iswalnum(input_line[n]) || input_line[n]==L'_')) n--;
    return n+1;
}

static int term_find_word_end(void)
{
//
// returns the address of the first character beyond the end of a current
// word. If the character at the insert point is not alphanumeric then its
// address is returned.
// /* surrogate pairs
//
    int n = insert_point;
    while (input_line[n]!=0 &&
           (iswalnum(input_line[n]) || input_line[n]==L'_')) n++;
    return n;
}

static void term_capitalize_word(void)
{   int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
//
// towupper and towlower are only guaranteed valid if the code-point passed
// represents a valid character in the current locale. That is, I think,
// something I do not know how to test for! So here I will at least filter
// out surrogate values and I will hope that (eg) non-characters do not lead
// to crashes.
//
    if (a < b && !is_surrogate(input_line[a]))
        input_line[a] = towupper(input_line[a]);
    for (i=a+1; i<b; i++)
        if (!is_surrogate(input_line[i]))
            input_line[i] = towlower(input_line[i]);
    refresh_display();
}


static void term_lowercase_word(void)
{   int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++)
        if (!is_surrogate(input_line[i]))
            input_line[i] = towlower(input_line[i]);
    refresh_display();
}


static void term_uppercase_word(void)
{   int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++)
        if (!is_surrogate(input_line[i]))
            input_line[i] = towupper(input_line[i]);
    refresh_display();
}


static void term_transpose_chars(void)
{   int c, d;
//
// I fear there are 4 cases here in the windows world...
//     x, y    =>    y, x
//     Xx, y   =>    x, Xx
//     x, Yy   =>    Yy, x
//     Xx, Yy  =>    Yy, Xx
// where Xy and Yy stand for pairs of surrogates. If sizeof(wchar_t)==4
// things are a lot simpler!
//
    if (sizeof(wchar_t) == 4)
    {   if (((c = input_line[insert_point]) == 0) ||
            ((d = input_line[insert_point+1]) == 0)) term_bell();
        else
        {   input_line[insert_point] = d;
            input_line[insert_point+1] = c;
            refresh_display();
        }
    }
    else if (input_line[insert_point] == 0) term_bell();
    else if (is_high_surrogate(input_line[insert_point]))
    {   if (input_line[insert_point+2] == 0) term_bell();
        else if (is_high_surrogate(input_line[insert_point+2]))
        {   c = input_line[insert_point+2];
            d = input_line[insert_point+3];
            input_line[insert_point+2] = input_line[insert_point];
            input_line[insert_point+3] = input_line[insert_point+1];
            input_line[insert_point] = c;
            input_line[insert_point+1] = d;
            refresh_display();
        }
        else
        {   c = input_line[insert_point+2];
            input_line[insert_point+2] = input_line[insert_point+1];
            input_line[insert_point+1] = input_line[insert_point];
            input_line[insert_point] = c;
            refresh_display();
        }
    }
    else if (input_line[insert_point+1] == 0) term_bell();
    else if (is_high_surrogate(input_line[insert_point+1]))
    {   c = input_line[insert_point+1];
        d = input_line[insert_point+2];
        input_line[insert_point+2] = input_line[insert_point];
        input_line[insert_point] = c;
        input_line[insert_point+1] = d;
        refresh_display();
    }
    else
    {   c = input_line[insert_point];
        input_line[insert_point] = input_line[insert_point+1];
        input_line[insert_point+1] = c;
        refresh_display();
    }
}


static void term_undo(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^U>");
    term_bell();
}


static void term_quoted_insert(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^V>");
    term_bell();
}


static void term_copy_previous_word(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^W>");
    term_bell();
}


static void term_copy_region(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&W>");
    term_bell();
}


static void term_yank(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^Y>");
    term_bell();
}


static void term_reinput(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^R>");
    term_bell();
}


static void term_redisplay(void)
{
//
// To get as much of the active area redrawn as I can I will reset the
// record of what is visible to suggest that everything is totally out of
// date.
//
    display_line[0] = input_line[0] + 1;
    display_line[1] = 0;
    refresh_display();
}


static void term_clear_screen(void)
{
//
// This will then leave the input-line displayed at the top of your window...
//
#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO csb;
    DWORD size, nbytes;
    COORD topleft = {0, 0};
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    size = csb.dwSize.X * csb.dwSize.Y;
    if (!FillConsoleOutputCharacter(stdout_handle,
                                    (TCHAR)' ', size, topleft, &nbytes)) return;
    if (!FillConsoleOutputAttribute(stdout_handle,
                                    csb.wAttributes, size, topleft, &nbytes)) return;
    SetConsoleCursorPosition(stdout_handle, topleft);
#else
    if (clear_screen != NULL) putp(clear_screen);
#endif
    display_line[0] = input_line[0] + 1;
    display_line[1] = 0;
    term_redisplay();
}


static void term_pause_output(void)
{
// @@@@@
}


static void term_resume_output(void)
{
// @@@@@
}


static void term_discard_output(void)
{
// @@@@@
}


static int hexval(int c)
{
//
// Regardless of the fact that in general I am working in Unicode, here
// I am only interested in the digits 0-9 and the letters a-f and A-F and
// if I only accept ones in the most basic form I can use 7-bit codes.
//
    if (c < 0 || c >= 0x7f) return -1;
    if (isdigit((unsigned char)c)) return c - '0';
    else if (isupper((unsigned char)c)) return c + (10 - 'A');
    else return c + (10 - 'a');
}

//
// The table here is the set of names used in HTML to denote characters
// and so I hope that many of the names will be familiar to many people.
// They are sorted into a collating order based on their names so I
// can look up names using binary search. Note that the longest name
// seems to be of length 31 ("CounterClockwiseContourIntegral"), and the
// shortest are of length 2 ("mu", "pi" and the quite a few others).
//
//
// The data here is derived from the HTML Living Standard at
// http://whatwg.org which notes on its contents page
// "Copyright 2004-2011 Apple Computer, Inc., Mozilla Foundation,
//  and Opera Software ASA. You are granted a license to use, reproduce
//  and create derivative works of this document."
//
// Some of the character names are shown as mapping onto pairs of Unicode
// symbols (&acE; is the first such: I might try to render it here as
// "~=", an &ac; sign (alternating current?) followed by a lowered equals
// sign). I have commented out all such cases in that it seems bad enough
// feel like worrying about things like &Afr; (Capital letter A rendered
// in a Fractur font at codepoint U+1d504) but support for Unicode
// combining marks and composites is a step too far for me at present!
//
// I have added a special extra &hash; to stand for "#" just for the
// convenience of Reduce. There are also a few other additions that
// are to assist my conversions to and from HEX. E.g. there is a name
// &frac12; where the suffix "ac12" could be seen as 4 hex digits. For
// reasons that apply within my code it is usefil to arrange that the
// name &ac12; will ba mapped onto U+ac12.
//
// Just so you know, there are somewhat over 2000 names here.
//

uniname unicode_names[] =
{
//
// It is really part of the purpose of this table that the names are all in
// the most basic character set, and so I keep the table using "char *" and
// regular narrow strings.
//
    {"AElig",                           198},
    {"AMP",                             38},
    {"Aacute",                          193},
    {"Abreve",                          258},
    {"Acirc",                           194},
    {"Acy",                             1040},
    {"Afr",                             120068},
    {"Agrave",                          192},
    {"Alpha",                           913},
    {"Amacr",                           256},
    {"And",                             10835},
    {"Aogon",                           260},
    {"Aopf",                            120120},
    {"ApplyFunction",                   8289},
    {"Aring",                           197},
    {"Ascr",                            119964},
    {"Assign",                          8788},
    {"Atilde",                          195},
    {"Auml",                            196},
    {"Backslash",                       8726},
    {"Barv",                            10983},
    {"Barwed",                          8966},
    {"Bcy",                             1041},
    {"Because",                         8757},
    {"Bernoullis",                      8492},
    {"Beta",                            914},
    {"Bfr",                             120069},
    {"Bopf",                            120121},
    {"Breve",                           728},
    {"Bscr",                            8492},
    {"Bumpeq",                          8782},
    {"CHcy",                            1063},
    {"COPY",                            169},
    {"Cacute",                          262},
    {"Cap",                             8914},
    {"CapitalDifferentialD",            8517},
    {"Cayleys",                         8493},
    {"Ccaron",                          268},
    {"Ccedil",                          199},
    {"Ccirc",                           264},
    {"Cconint",                         8752},
    {"Cdot",                            266},
    {"Cedilla",                         184},
    {"CenterDot",                       183},
    {"Cfr",                             8493},
    {"Chi",                             935},
    {"CircleDot",                       8857},
    {"CircleMinus",                     8854},
    {"CirclePlus",                      8853},
    {"CircleTimes",                     8855},
    {"ClockwiseContourIntegral",        8754},
    {"CloseCurlyDoubleQuote",           8221},
    {"CloseCurlyQuote",                 8217},
    {"Colon",                           8759},
    {"Colone",                          10868},
    {"Congruent",                       8801},
    {"Conint",                          8751},
    {"ContourIntegral",                 8750},
    {"Copf",                            8450},
    {"Coproduct",                       8720},
    {"CounterClockwiseContourIntegral", 8755},
    {"Cross",                           10799},
    {"Cscr",                            119966},
    {"Cup",                             8915},
    {"CupCap",                          8781},
    {"DD",                              8517}, // Beware hex vs name
    {"DDotrahd",                        10513},
    {"DJcy",                            1026},
    {"DScy",                            1029},
    {"DZcy",                            1039},
    {"Dagger",                          8225},
    {"Darr",                            8609},
    {"Dashv",                           10980},
    {"Dcaron",                          270},
    {"Dcy",                             1044},
    {"Del",                             8711},
    {"Delta",                           916},
    {"Dfr",                             120071},
    {"DiacriticalAcute",                180},
    {"DiacriticalDot",                  729},
    {"DiacriticalDoubleAcute",          733},
    {"DiacriticalGrave",                96},
    {"DiacriticalTilde",                732},
    {"Diamond",                         8900},
    {"DifferentialD",                   8518},
    {"Dopf",                            120123},
    {"Dot",                             168},
    {"DotDot",                          8412},
    {"DotEqual",                        8784},
    {"DoubleContourIntegral",           8751},
    {"DoubleDot",                       168},
    {"DoubleDownArrow",                 8659},
    {"DoubleLeftArrow",                 8656},
    {"DoubleLeftRightArrow",            8660},
    {"DoubleLeftTee",                   10980},
    {"DoubleLongLeftArrow",             10232},
    {"DoubleLongLeftRightArrow",        10234},
    {"DoubleLongRightArrow",            10233},
    {"DoubleRightArrow",                8658},
    {"DoubleRightTee",                  8872},
    {"DoubleUpArrow",                   8657},
    {"DoubleUpDownArrow",               8661},
    {"DoubleVerticalBar",               8741},
    {"DownArrow",                       8595},
    {"DownArrowBar",                    10515},
    {"DownArrowUpArrow",                8693},
    {"DownBreve",                       785},
    {"DownLeftRightVector",             10576},
    {"DownLeftTeeVector",               10590},
    {"DownLeftVector",                  8637},
    {"DownLeftVectorBar",               10582},
    {"DownRightTeeVector",              10591},
    {"DownRightVector",                 8641},
    {"DownRightVectorBar",              10583},
    {"DownTee",                         8868},
    {"DownTeeArrow",                    8615},
    {"Downarrow",                       8659},
    {"Dscr",                            119967},
    {"Dstrok",                          272},
    {"ENG",                             330},
    {"ETH",                             208},
    {"Eacute",                          201},
    {"Ecaron",                          282},
    {"Ecirc",                           202},
    {"Ecy",                             1069},
    {"Edot",                            278},
    {"Efr",                             120072},
    {"Egrave",                          200},
    {"Element",                         8712},
    {"Emacr",                           274},
    {"EmptySmallSquare",                9723},
    {"EmptyVerySmallSquare",            9643},
    {"Eogon",                           280},
    {"Eopf",                            120124},
    {"Epsilon",                         917},
    {"Equal",                           10869},
    {"EqualTilde",                      8770},
    {"Equilibrium",                     8652},
    {"Escr",                            8496},
    {"Esim",                            10867},
    {"Eta",                             919},
    {"Euml",                            203},
    {"Exists",                          8707},
    {"ExponentialE",                    8519},
    {"Fcy",                             1060},
    {"Ffr",                             120073},
    {"FilledSmallSquare",               9724},
    {"FilledVerySmallSquare",           9642},
    {"Fopf",                            120125},
    {"ForAll",                          8704},
    {"Fouriertrf",                      8497},
    {"Fscr",                            8497},
    {"GJcy",                            1027},
    {"GT",                              62},
    {"Gamma",                           915},
    {"Gammad",                          988},
    {"Gbreve",                          286},
    {"Gcedil",                          290},
    {"Gcirc",                           284},
    {"Gcy",                             1043},
    {"Gdot",                            288},
    {"Gfr",                             120074},
    {"Gg",                              8921},
    {"Gopf",                            120126},
    {"GreaterEqual",                    8805},
    {"GreaterEqualLess",                8923},
    {"GreaterFullEqual",                8807},
    {"GreaterGreater",                  10914},
    {"GreaterLess",                     8823},
    {"GreaterSlantEqual",               10878},
    {"GreaterTilde",                    8819},
    {"Gscr",                            119970},
    {"Gt",                              8811},
    {"HARDcy",                          1066},
    {"Hacek",                           711},
    {"Hat",                             94},
    {"Hcirc",                           292},
    {"Hfr",                             8460},
    {"HilbertSpace",                    8459},
    {"Hopf",                            8461},
    {"HorizontalLine",                  9472},
    {"Hscr",                            8459},
    {"Hstrok",                          294},
    {"HumpDownHump",                    8782},
    {"HumpEqual",                       8783},
    {"IEcy",                            1045},
    {"IJlig",                           306},
    {"IOcy",                            1025},
    {"Iacute",                          205},
    {"Icirc",                           206},
    {"Icy",                             1048},
    {"Idot",                            304},
    {"Ifr",                             8465},
    {"Igrave",                          204},
    {"Im",                              8465},
    {"Imacr",                           298},
    {"ImaginaryI",                      8520},
    {"Implies",                         8658},
    {"Int",                             8748},
    {"Integral",                        8747},
    {"Intersection",                    8898},
    {"InvisibleComma",                  8291},
    {"InvisibleTimes",                  8290},
    {"Iogon",                           302},
    {"Iopf",                            120128},
    {"Iota",                            921},
    {"Iscr",                            8464},
    {"Itilde",                          296},
    {"Iukcy",                           1030},
    {"Iuml",                            207},
    {"Jcirc",                           308},
    {"Jcy",                             1049},
    {"Jfr",                             120077},
    {"Jopf",                            120129},
    {"Jscr",                            119973},
    {"Jsercy",                          1032},
    {"Jukcy",                           1028},
    {"KHcy",                            1061},
    {"KJcy",                            1036},
    {"Kappa",                           922},
    {"Kcedil",                          310},
    {"Kcy",                             1050},
    {"Kfr",                             120078},
    {"Kopf",                            120130},
    {"Kscr",                            119974},
    {"LJcy",                            1033},
    {"LT",                              60},
    {"Lacute",                          313},
    {"Lambda",                          923},
    {"Lang",                            10218},
    {"Laplacetrf",                      8466},
    {"Larr",                            8606},
    {"Lcaron",                          317},
    {"Lcedil",                          315},
    {"Lcy",                             1051},
    {"LeftAngleBracket",                10216},
    {"LeftArrow",                       8592},
    {"LeftArrowBar",                    8676},
    {"LeftArrowRightArrow",             8646},
    {"LeftCeiling",                     8968},
    {"LeftDoubleBracket",               10214},
    {"LeftDownTeeVector",               10593},
    {"LeftDownVector",                  8643},
    {"LeftDownVectorBar",               10585},
    {"LeftFloor",                       8970},
    {"LeftRightArrow",                  8596},
    {"LeftRightVector",                 10574},
    {"LeftTee",                         8867},
    {"LeftTeeArrow",                    8612},
    {"LeftTeeVector",                   10586},
    {"LeftTriangle",                    8882},
    {"LeftTriangleBar",                 10703},
    {"LeftTriangleEqual",               8884},
    {"LeftUpDownVector",                10577},
    {"LeftUpTeeVector",                 10592},
    {"LeftUpVector",                    8639},
    {"LeftUpVectorBar",                 10584},
    {"LeftVector",                      8636},
    {"LeftVectorBar",                   10578},
    {"Leftarrow",                       8656},
    {"Leftrightarrow",                  8660},
    {"LessEqualGreater",                8922},
    {"LessFullEqual",                   8806},
    {"LessGreater",                     8822},
    {"LessLess",                        10913},
    {"LessSlantEqual",                  10877},
    {"LessTilde",                       8818},
    {"Lfr",                             120079},
    {"Ll",                              8920},
    {"Lleftarrow",                      8666},
    {"Lmidot",                          319},
    {"LongLeftArrow",                   10229},
    {"LongLeftRightArrow",              10231},
    {"LongRightArrow",                  10230},
    {"Longleftarrow",                   10232},
    {"Longleftrightarrow",              10234},
    {"Longrightarrow",                  10233},
    {"Lopf",                            120131},
    {"LowerLeftArrow",                  8601},
    {"LowerRightArrow",                 8600},
    {"Lscr",                            8466},
    {"Lsh",                             8624},
    {"Lstrok",                          321},
    {"Lt",                              8810},
    {"Map",                             10501},
    {"Mcy",                             1052},
    {"MediumSpace",                     8287},
    {"Mellintrf",                       8499},
    {"Mfr",                             120080},
    {"MinusPlus",                       8723},
    {"Mopf",                            120132},
    {"Mscr",                            8499},
    {"Mu",                              924},
    {"NJcy",                            1034},
    {"Nacute",                          323},
    {"Ncaron",                          327},
    {"Ncedil",                          325},
    {"Ncy",                             1053},
    {"NegativeMediumSpace",             8203},
    {"NegativeThickSpace",              8203},
    {"NegativeThinSpace",               8203},
    {"NegativeVeryThinSpace",           8203},
    {"NestedGreaterGreater",            8811},
    {"NestedLessLess",                  8810},
    {"NewLine",                         10},
    {"Nfr",                             120081},
    {"NoBreak",                         8288},
    {"NonBreakingSpace",                160},
    {"Nopf",                            8469},
    {"Not",                             10988},
    {"NotCongruent",                    8802},
    {"NotCupCap",                       8813},
    {"NotDoubleVerticalBar",            8742},
    {"NotElement",                      8713},
    {"NotEqual",                        8800},
    {"NotExists",                       8708},
    {"NotGreater",                      8815},
    {"NotGreaterEqual",                 8817},
    {"NotGreaterLess",                  8825},
    {"NotGreaterTilde",                 8821},
    {"NotLeftTriangle",                 8938},
    {"NotLeftTriangleEqual",            8940},
    {"NotLess",                         8814},
    {"NotLessEqual",                    8816},
    {"NotLessGreater",                  8824},
    {"NotLessTilde",                    8820},
    {"NotPrecedes",                     8832},
    {"NotPrecedesSlantEqual",           8928},
    {"NotReverseElement",               8716},
    {"NotRightTriangle",                8939},
    {"NotRightTriangleEqual",           8941},
    {"NotSquareSubsetEqual",            8930},
    {"NotSquareSupersetEqual",          8931},
    {"NotSubsetEqual",                  8840},
    {"NotSucceeds",                     8833},
    {"NotSucceedsSlantEqual",           8929},
    {"NotSupersetEqual",                8841},
    {"NotTilde",                        8769},
    {"NotTildeEqual",                   8772},
    {"NotTildeFullEqual",               8775},
    {"NotTildeTilde",                   8777},
    {"NotVerticalBar",                  8740},
    {"Nscr",                            119977},
    {"Ntilde",                          209},
    {"Nu",                              925},
    {"OElig",                           338},
    {"Oacute",                          211},
    {"Ocirc",                           212},
    {"Ocy",                             1054},
    {"Odblac",                          336},
    {"Ofr",                             120082},
    {"Ograve",                          210},
    {"Omacr",                           332},
    {"Omega",                           937},
    {"Omicron",                         927},
    {"Oopf",                            120134},
    {"OpenCurlyDoubleQuote",            8220},
    {"OpenCurlyQuote",                  8216},
    {"Or",                              10836},
    {"Oscr",                            119978},
    {"Oslash",                          216},
    {"Otilde",                          213},
    {"Otimes",                          10807},
    {"Ouml",                            214},
    {"OverBar",                         8254},
    {"OverBrace",                       9182},
    {"OverBracket",                     9140},
    {"OverParenthesis",                 9180},
    {"PartialD",                        8706},
    {"Pcy",                             1055},
    {"Pfr",                             120083},
    {"Phi",                             934},
    {"Pi",                              928},
    {"PlusMinus",                       177},
    {"Poincareplane",                   8460},
    {"Popf",                            8473},
    {"Pr",                              10939},
    {"Precedes",                        8826},
    {"PrecedesEqual",                   10927},
    {"PrecedesSlantEqual",              8828},
    {"PrecedesTilde",                   8830},
    {"Prime",                           8243},
    {"Product",                         8719},
    {"Proportion",                      8759},
    {"Proportional",                    8733},
    {"Pscr",                            119979},
    {"Psi",                             936},
    {"QUOT",                            34},
    {"Qfr",                             120084},
    {"Qopf",                            8474},
    {"Qscr",                            119980},
    {"RBarr",                           10512},
    {"REG",                             174},
    {"Racute",                          340},
    {"Rang",                            10219},
    {"Rarr",                            8608},
    {"Rarrtl",                          10518},
    {"Rcaron",                          344},
    {"Rcedil",                          342},
    {"Rcy",                             1056},
    {"Re",                              8476},
    {"ReverseElement",                  8715},
    {"ReverseEquilibrium",              8651},
    {"ReverseUpEquilibrium",            10607},
    {"Rfr",                             8476},
    {"Rho",                             929},
    {"RightAngleBracket",               10217},
    {"RightArrow",                      8594},
    {"RightArrowBar",                   8677},
    {"RightArrowLeftArrow",             8644},
    {"RightCeiling",                    8969},
    {"RightDoubleBracket",              10215},
    {"RightDownTeeVector",              10589},
    {"RightDownVector",                 8642},
    {"RightDownVectorBar",              10581},
    {"RightFloor",                      8971},
    {"RightTee",                        8866},
    {"RightTeeArrow",                   8614},
    {"RightTeeVector",                  10587},
    {"RightTriangle",                   8883},
    {"RightTriangleBar",                10704},
    {"RightTriangleEqual",              8885},
    {"RightUpDownVector",               10575},
    {"RightUpTeeVector",                10588},
    {"RightUpVector",                   8638},
    {"RightUpVectorBar",                10580},
    {"RightVector",                     8640},
    {"RightVectorBar",                  10579},
    {"Rightarrow",                      8658},
    {"Ropf",                            8477},
    {"RoundImplies",                    10608},
    {"Rrightarrow",                     8667},
    {"Rscr",                            8475},
    {"Rsh",                             8625},
    {"RuleDelayed",                     10740},
    {"SHCHcy",                          1065},
    {"SHcy",                            1064},
    {"SOFTcy",                          1068},
    {"Sacute",                          346},
    {"Sc",                              10940},
    {"Scaron",                          352},
    {"Scedil",                          350},
    {"Scirc",                           348},
    {"Scy",                             1057},
    {"Sfr",                             120086},
    {"ShortDownArrow",                  8595},
    {"ShortLeftArrow",                  8592},
    {"ShortRightArrow",                 8594},
    {"ShortUpArrow",                    8593},
    {"Sigma",                           931},
    {"SmallCircle",                     8728},
    {"Sopf",                            120138},
    {"Sqrt",                            8730},
    {"Square",                          9633},
    {"SquareIntersection",              8851},
    {"SquareSubset",                    8847},
    {"SquareSubsetEqual",               8849},
    {"SquareSuperset",                  8848},
    {"SquareSupersetEqual",             8850},
    {"SquareUnion",                     8852},
    {"Sscr",                            119982},
    {"Star",                            8902},
    {"Sub",                             8912},
    {"Subset",                          8912},
    {"SubsetEqual",                     8838},
    {"Succeeds",                        8827},
    {"SucceedsEqual",                   10928},
    {"SucceedsSlantEqual",              8829},
    {"SucceedsTilde",                   8831},
    {"SuchThat",                        8715},
    {"Sum",                             8721},
    {"Sup",                             8913},
    {"Superset",                        8835},
    {"SupersetEqual",                   8839},
    {"Supset",                          8913},
    {"THORN",                           222},
    {"TRADE",                           8482},
    {"TSHcy",                           1035},
    {"TScy",                            1062},
    {"Tab",                             9},
    {"Tau",                             932},
    {"Tcaron",                          356},
    {"Tcedil",                          354},
    {"Tcy",                             1058},
    {"Tfr",                             120087},
    {"Therefore",                       8756},
    {"Theta",                           920},
    {"ThinSpace",                       8201},
    {"Tilde",                           8764},
    {"TildeEqual",                      8771},
    {"TildeFullEqual",                  8773},
    {"TildeTilde",                      8776},
    {"Topf",                            120139},
    {"TripleDot",                       8411},
    {"Tscr",                            119983},
    {"Tstrok",                          358},
    {"Uacute",                          218},
    {"Uarr",                            8607},
    {"Uarrocir",                        10569},
    {"Ubrcy",                           1038},
    {"Ubreve",                          364},
    {"Ucirc",                           219},
    {"Ucy",                             1059},
    {"Udblac",                          368},
    {"Ufr",                             120088},
    {"Ugrave",                          217},
    {"Umacr",                           362},
    {"UnderBar",                        95},
    {"UnderBrace",                      9183},
    {"UnderBracket",                    9141},
    {"UnderParenthesis",                9181},
    {"Union",                           8899},
    {"UnionPlus",                       8846},
    {"Uogon",                           370},
    {"Uopf",                            120140},
    {"UpArrow",                         8593},
    {"UpArrowBar",                      10514},
    {"UpArrowDownArrow",                8645},
    {"UpDownArrow",                     8597},
    {"UpEquilibrium",                   10606},
    {"UpTee",                           8869},
    {"UpTeeArrow",                      8613},
    {"Uparrow",                         8657},
    {"Updownarrow",                     8661},
    {"UpperLeftArrow",                  8598},
    {"UpperRightArrow",                 8599},
    {"Upsi",                            978},
    {"Upsilon",                         933},
    {"Uring",                           366},
    {"Uscr",                            119984},
    {"Utilde",                          360},
    {"Uuml",                            220},
    {"VDash",                           8875},
    {"Vbar",                            10987},
    {"Vcy",                             1042},
    {"Vdash",                           8873},
    {"Vdashl",                          10982},
    {"Vee",                             8897},
    {"Verbar",                          8214},
    {"Vert",                            8214},
    {"VerticalBar",                     8739},
    {"VerticalLine",                    124},
    {"VerticalSeparator",               10072},
    {"VerticalTilde",                   8768},
    {"VeryThinSpace",                   8202},
    {"Vfr",                             120089},
    {"Vopf",                            120141},
    {"Vscr",                            119985},
    {"Vvdash",                          8874},
    {"Wcirc",                           372},
    {"Wedge",                           8896},
    {"Wfr",                             120090},
    {"Wopf",                            120142},
    {"Wscr",                            119986},
    {"Xfr",                             120091},
    {"Xi",                              926},
    {"Xopf",                            120143},
    {"Xscr",                            119987},
    {"YAcy",                            1071},
    {"YIcy",                            1031},
    {"YUcy",                            1070},
    {"Yacute",                          221},
    {"Ycirc",                           374},
    {"Ycy",                             1067},
    {"Yfr",                             120092},
    {"Yopf",                            120144},
    {"Yscr",                            119988},
    {"Yuml",                            376},
    {"ZHcy",                            1046},
    {"Zacute",                          377},
    {"Zcaron",                          381},
    {"Zcy",                             1047},
    {"Zdot",                            379},
    {"ZeroWidthSpace",                  8203},
    {"Zeta",                            918},
    {"Zfr",                             8488},
    {"Zopf",                            8484},
    {"Zscr",                            119989},
    {"aacute",                          225},
    {"abreve",                          259},
    {"ac",                              8766}, // Beware hex vs name
    {"ac12",                            0xac12}, // ACN special
    {"ac13",                            0xac13}, // ACN special
    {"ac14",                            0xac14}, // ACN special
    {"ac15",                            0xac15}, // ACN special
    {"ac16",                            0xac16}, // ACN special
    {"ac18",                            0xac18}, // ACN special
    {"ac23",                            0xac23}, // ACN special
    {"ac25",                            0xac25}, // ACN special
    {"ac34",                            0xac34}, // ACN special
    {"ac35",                            0xac35}, // ACN special
    {"ac38",                            0xac38}, // ACN special
    {"ac45",                            0xac45}, // ACN special
    {"ac56",                            0xac56}, // ACN special
    {"ac58",                            0xac58}, // ACN special
    {"ac78",                            0xac78}, // ACN special
    {"acd",                             8767}, // Beware hex vs name
    {"acirc",                           226},
    {"acute",                           180},
    {"acy",                             1072},
    {"aelig",                           230},
    {"af",                              8289}, // Beware hex vs name
    {"afr",                             120094},
    {"agrave",                          224},
    {"alefsym",                         8501},
    {"aleph",                           8501},
    {"alpha",                           945},
    {"amacr",                           257},
    {"amalg",                           10815},
    {"amp",                             38},
    {"and",                             8743},
    {"andand",                          10837},
    {"andd",                            10844},
    {"andslope",                        10840},
    {"andv",                            10842},
    {"ang",                             8736},
    {"ange",                            10660},
    {"angle",                           8736},
    {"angmsd",                          8737},
    {"angmsdaa",                        10664},
    {"angmsdab",                        10665},
    {"angmsdac",                        10666},
    {"angmsdad",                        10667},
    {"angmsdae",                        10668},
    {"angmsdaf",                        10669},
    {"angmsdag",                        10670},
    {"angmsdah",                        10671},
    {"angrt",                           8735},
    {"angrtvb",                         8894},
    {"angrtvbd",                        10653},
    {"angsph",                          8738},
    {"angst",                           197},
    {"angzarr",                         9084},
    {"aogon",                           261},
    {"aopf",                            120146},
    {"ap",                              8776},
    {"apE",                             10864},
    {"apacir",                          10863},
    {"ape",                             8778},
    {"apid",                            8779},
    {"apos",                            39},
    {"approx",                          8776},
    {"approxeq",                        8778},
    {"aring",                           229},
    {"ascr",                            119990},
    {"ast",                             42},
    {"asymp",                           8776},
    {"asympeq",                         8781},
    {"atilde",                          227},
    {"auml",                            228},
    {"awconint",                        8755},
    {"awint",                           10769},
    {"bNot",                            10989},
    {"backcong",                        8780},
    {"backepsilon",                     1014},
    {"backprime",                       8245},
    {"backsim",                         8765},
    {"backsimeq",                       8909},
    {"barvee",                          8893},
    {"barwed",                          8965},
    {"barwedge",                        8965},
    {"bbrk",                            9141},
    {"bbrktbrk",                        9142},
    {"bcong",                           8780},
    {"bcy",                             1073},
    {"bdquo",                           8222},
    {"becaus",                          8757},
    {"because",                         8757},
    {"bemptyv",                         10672},
    {"bepsi",                           1014},
    {"bernou",                          8492},
    {"beta",                            946},
    {"beth",                            8502},
    {"between",                         8812},
    {"bfr",                             120095},
    {"bigcap",                          8898},
    {"bigcirc",                         9711},
    {"bigcup",                          8899},
    {"bigodot",                         10752},
    {"bigoplus",                        10753},
    {"bigotimes",                       10754},
    {"bigsqcup",                        10758},
    {"bigstar",                         9733},
    {"bigtriangledown",                 9661},
    {"bigtriangleup",                   9651},
    {"biguplus",                        10756},
    {"bigvee",                          8897},
    {"bigwedge",                        8896},
    {"bkarow",                          10509},
    {"blacklozenge",                    10731},
    {"blacksquare",                     9642},
    {"blacktriangle",                   9652},
    {"blacktriangledown",               9662},
    {"blacktriangleleft",               9666},
    {"blacktriangleright",              9656},
    {"blank",                           9251},
    {"blk12",                           9618},
    {"blk14",                           9617},
    {"blk34",                           9619},
    {"block",                           9608},
    {"bnot",                            8976},
    {"bopf",                            120147},
    {"bot",                             8869},
    {"bottom",                          8869},
    {"bowtie",                          8904},
    {"boxDL",                           9559},
    {"boxDR",                           9556},
    {"boxDl",                           9558},
    {"boxDr",                           9555},
    {"boxH",                            9552},
    {"boxHD",                           9574},
    {"boxHU",                           9577},
    {"boxHd",                           9572},
    {"boxHu",                           9575},
    {"boxUL",                           9565},
    {"boxUR",                           9562},
    {"boxUl",                           9564},
    {"boxUr",                           9561},
    {"boxV",                            9553},
    {"boxVH",                           9580},
    {"boxVL",                           9571},
    {"boxVR",                           9568},
    {"boxVh",                           9579},
    {"boxVl",                           9570},
    {"boxVr",                           9567},
    {"boxbox",                          10697},
    {"boxdL",                           9557},
    {"boxdR",                           9554},
    {"boxdl",                           9488},
    {"boxdr",                           9484},
    {"boxh",                            9472},
    {"boxhD",                           9573},
    {"boxhU",                           9576},
    {"boxhd",                           9516},
    {"boxhu",                           9524},
    {"boxminus",                        8863},
    {"boxplus",                         8862},
    {"boxtimes",                        8864},
    {"boxuL",                           9563},
    {"boxuR",                           9560},
    {"boxul",                           9496},
    {"boxur",                           9492},
    {"boxv",                            9474},
    {"boxvH",                           9578},
    {"boxvL",                           9569},
    {"boxvR",                           9566},
    {"boxvh",                           9532},
    {"boxvl",                           9508},
    {"boxvr",                           9500},
    {"bprime",                          8245},
    {"breve",                           728},
    {"brvbar",                          166},
    {"bscr",                            119991},
    {"bsemi",                           8271},
    {"bsim",                            8765},
    {"bsime",                           8909},
    {"bsol",                            92},
    {"bsolb",                           10693},
    {"bsolhsub",                        10184},
    {"bull",                            8226},
    {"bullet",                          8226},
    {"bump",                            8782},
    {"bumpE",                           10926},
    {"bumpe",                           8783},
    {"bumpeq",                          8783},
    {"cacute",                          263},
    {"cap",                             8745},
    {"capand",                          10820},
    {"capbrcup",                        10825},
    {"capcap",                          10827},
    {"capcup",                          10823},
    {"capdot",                          10816},
    {"caret",                           8257},
    {"caron",                           711},
    {"ccaps",                           10829},
    {"ccaron",                          269},
    {"ccedil",                          231},
    {"ccirc",                           265},
    {"ccups",                           10828},
    {"ccupssm",                         10832},
    {"cdot",                            267},
    {"cedil",                           184},
    {"cemptyv",                         10674},
    {"cent",                            162},
    {"centerdot",                       183},
    {"cfr",                             120096},
    {"chcy",                            1095},
    {"check",                           10003},
    {"checkmark",                       10003},
    {"chi",                             967},
    {"cir",                             9675},
    {"cirE",                            10691},
    {"circ",                            710},
    {"circeq",                          8791},
    {"circlearrowleft",                 8634},
    {"circlearrowright",                8635},
    {"circledR",                        174},
    {"circledS",                        9416},
    {"circledast",                      8859},
    {"circledcirc",                     8858},
    {"circleddash",                     8861},
    {"cire",                            8791},
    {"cirfnint",                        10768},
    {"cirmid",                          10991},
    {"cirscir",                         10690},
    {"clubs",                           9827},
    {"clubsuit",                        9827},
    {"colon",                           58},
    {"colone",                          8788},
    {"coloneq",                         8788},
    {"comma",                           44},
    {"commat",                          64},
    {"comp",                            8705},
    {"compfn",                          8728},
    {"complement",                      8705},
    {"complexes",                       8450},
    {"cong",                            8773},
    {"congdot",                         10861},
    {"conint",                          8750},
    {"copf",                            120148},
    {"coprod",                          8720},
    {"copy",                            169},
    {"copysr",                          8471},
    {"crarr",                           8629},
    {"cross",                           10007},
    {"cscr",                            119992},
    {"csub",                            10959},
    {"csube",                           10961},
    {"csup",                            10960},
    {"csupe",                           10962},
    {"ctdot",                           8943},
    {"cudarrl",                         10552},
    {"cudarrr",                         10549},
    {"cuepr",                           8926},
    {"cuesc",                           8927},
    {"cularr",                          8630},
    {"cularrp",                         10557},
    {"cup",                             8746},
    {"cupbrcap",                        10824},
    {"cupcap",                          10822},
    {"cupcup",                          10826},
    {"cupdot",                          8845},
    {"cupor",                           10821},
    {"curarr",                          8631},
    {"curarrm",                         10556},
    {"curlyeqprec",                     8926},
    {"curlyeqsucc",                     8927},
    {"curlyvee",                        8910},
    {"curlywedge",                      8911},
    {"curren",                          164},
    {"curvearrowleft",                  8630},
    {"curvearrowright",                 8631},
    {"cuvee",                           8910},
    {"cuwed",                           8911},
    {"cwconint",                        8754},
    {"cwint",                           8753},
    {"cylcty",                          9005},
    {"dArr",                            8659},
    {"dHar",                            10597},
    {"dagger",                          8224},
    {"daleth",                          8504},
    {"darr",                            8595},
    {"dash",                            8208},
    {"dashv",                           8867},
    {"dbkarow",                         10511},
    {"dblac",                           733},
    {"dcaron",                          271},
    {"dcy",                             1076},
    {"dd",                              8518}, // Beware hex vs name
    {"ddagger",                         8225},
    {"ddarr",                           8650},
    {"ddotseq",                         10871},
    {"deg",                             176},
    {"delta",                           948},
    {"demptyv",                         10673},
    {"dfisht",                          10623},
    {"dfr",                             120097},
    {"dharl",                           8643},
    {"dharr",                           8642},
    {"diam",                            8900},
    {"diamond",                         8900},
    {"diamondsuit",                     9830},
    {"diams",                           9830},
    {"die",                             168},
    {"digamma",                         989},
    {"disin",                           8946},
    {"div",                             247},
    {"divide",                          247},
    {"divideontimes",                   8903},
    {"divonx",                          8903},
    {"djcy",                            1106},
    {"dlcorn",                          8990},
    {"dlcrop",                          8973},
    {"dollar",                          36},
    {"dopf",                            120149},
    {"dot",                             729},
    {"doteq",                           8784},
    {"doteqdot",                        8785},
    {"dotminus",                        8760},
    {"dotplus",                         8724},
    {"dotsquare",                       8865},
    {"doublebarwedge",                  8966},
    {"downarrow",                       8595},
    {"downdownarrows",                  8650},
    {"downharpoonleft",                 8643},
    {"downharpoonright",                8642},
    {"drbkarow",                        10512},
    {"drcorn",                          8991},
    {"drcrop",                          8972},
    {"dscr",                            119993},
    {"dscy",                            1109},
    {"dsol",                            10742},
    {"dstrok",                          273},
    {"dtdot",                           8945},
    {"dtri",                            9663},
    {"dtrif",                           9662},
    {"duarr",                           8693},
    {"duhar",                           10607},
    {"dwangle",                         10662},
    {"dzcy",                            1119},
    {"dzigrarr",                        10239},
    {"eDDot",                           10871},
    {"eDot",                            8785},
    {"eacute",                          233},
    {"easter",                          10862},
    {"ecaron",                          283},
    {"ecir",                            8790},
    {"ecirc",                           234},
    {"ecolon",                          8789},
    {"ecy",                             1101},
    {"edot",                            279},
    {"ee",                              8519}, // Beware hex vs name
    {"efDot",                           8786},
    {"efr",                             120098},
    {"eg",                              10906},
    {"egrave",                          232},
    {"egs",                             10902},
    {"egsdot",                          10904},
    {"el",                              10905},
    {"elinters",                        9191},
    {"ell",                             8467},
    {"els",                             10901},
    {"elsdot",                          10903},
    {"emacr",                           275},
    {"empty",                           8709},
    {"emptyset",                        8709},
    {"emptyv",                          8709},
    {"emsp",                            8195},
    {"emsp13",                          8196},
    {"emsp14",                          8197},
    {"eng",                             331},
    {"ensp",                            8194},
    {"eogon",                           281},
    {"eopf",                            120150},
    {"epar",                            8917},
    {"eparsl",                          10723},
    {"eplus",                           10865},
    {"epsi",                            949},
    {"epsilon",                         949},
    {"epsiv",                           1013},
    {"eqcirc",                          8790},
    {"eqcolon",                         8789},
    {"eqsim",                           8770},
    {"eqslantgtr",                      10902},
    {"eqslantless",                     10901},
    {"equals",                          61},
    {"equest",                          8799},
    {"equiv",                           8801},
    {"equivDD",                         10872},
    {"eqvparsl",                        10725},
    {"erDot",                           8787},
    {"erarr",                           10609},
    {"escr",                            8495},
    {"esdot",                           8784},
    {"esim",                            8770},
    {"eta",                             951},
    {"eth",                             240},
    {"euml",                            235},
    {"euro",                            8364},
    {"excl",                            33},
    {"exist",                           8707},
    {"expectation",                     8496},
    {"exponentiale",                    8519},
    {"fallingdotseq",                   8786},
    {"fcy",                             1092},
    {"female",                          9792},
    {"ffilig",                          64259},
    {"fflig",                           64256},
    {"ffllig",                          64260},
    {"ffr",                             120099},
    {"filig",                           64257},
    {"flat",                            9837},
    {"fllig",                           64258},
    {"fltns",                           9649},
    {"fnof",                            402},
    {"fopf",                            120151},
    {"forall",                          8704},
    {"fork",                            8916},
    {"forkv",                           10969},
    {"fpartint",                        10765},
    {"frac12",                          189},
    {"frac13",                          8531},
    {"frac14",                          188},
    {"frac15",                          8533},
    {"frac16",                          8537},
    {"frac18",                          8539},
    {"frac23",                          8532},
    {"frac25",                          8534},
    {"frac34",                          190},
    {"frac35",                          8535},
    {"frac38",                          8540},
    {"frac45",                          8536},
    {"frac56",                          8538},
    {"frac58",                          8541},
    {"frac78",                          8542},
    {"frasl",                           8260},
    {"frown",                           8994},
    {"fscr",                            119995},
    {"gE",                              8807},
    {"gEl",                             10892},
    {"gacute",                          501},
    {"gamma",                           947},
    {"gammad",                          989},
    {"gap",                             10886},
    {"gbreve",                          287},
    {"gcirc",                           285},
    {"gcy",                             1075},
    {"gdot",                            289},
    {"ge",                              8805},
    {"gel",                             8923},
    {"geq",                             8805},
    {"geqq",                            8807},
    {"geqslant",                        10878},
    {"ges",                             10878},
    {"gescc",                           10921},
    {"gesdot",                          10880},
    {"gesdoto",                         10882},
    {"gesdotol",                        10884},
    {"gesles",                          10900},
    {"gfr",                             120100},
    {"gg",                              8811},
    {"ggg",                             8921},
    {"gimel",                           8503},
    {"gjcy",                            1107},
    {"gl",                              8823},
    {"glE",                             10898},
    {"gla",                             10917},
    {"glj",                             10916},
    {"gnE",                             8809},
    {"gnap",                            10890},
    {"gnapprox",                        10890},
    {"gne",                             10888},
    {"gneq",                            10888},
    {"gneqq",                           8809},
    {"gnsim",                           8935},
    {"gopf",                            120152},
    {"grave",                           96},
    {"gscr",                            8458},
    {"gsim",                            8819},
    {"gsime",                           10894},
    {"gsiml",                           10896},
    {"gt",                              62},
    {"gtcc",                            10919},
    {"gtcir",                           10874},
    {"gtdot",                           8919},
    {"gtlPar",                          10645},
    {"gtquest",                         10876},
    {"gtrapprox",                       10886},
    {"gtrarr",                          10616},
    {"gtrdot",                          8919},
    {"gtreqless",                       8923},
    {"gtreqqless",                      10892},
    {"gtrless",                         8823},
    {"gtrsim",                          8819},
    {"hArr",                            8660},
    {"hairsp",                          8202},
    {"half",                            189},
    {"hamilt",                          8459},
    {"hardcy",                          1098},
    {"harr",                            8596},
    {"harrcir",                         10568},
    {"harrw",                           8621},
    {"hash",                            35}, // Added by ACN
    {"hbar",                            8463},
    {"hcirc",                           293},
    {"hearts",                          9829},
    {"heartsuit",                       9829},
    {"hellip",                          8230},
    {"hercon",                          8889},
    {"hfr",                             120101},
    {"hksearow",                        10533},
    {"hkswarow",                        10534},
    {"hoarr",                           8703},
    {"homtht",                          8763},
    {"hookleftarrow",                   8617},
    {"hookrightarrow",                  8618},
    {"hopf",                            120153},
    {"horbar",                          8213},
    {"hscr",                            119997},
    {"hslash",                          8463},
    {"hstrok",                          295},
    {"hybull",                          8259},
    {"hyphen",                          8208},
    {"iacute",                          237},
    {"ic",                              8291},
    {"icirc",                           238},
    {"icy",                             1080},
    {"iecy",                            1077},
    {"iexcl",                           161},
    {"iff",                             8660},
    {"ifr",                             120102},
    {"igrave",                          236},
    {"ii",                              8520},
    {"iiiint",                          10764},
    {"iiint",                           8749},
    {"iinfin",                          10716},
    {"iiota",                           8489},
    {"ijlig",                           307},
    {"imacr",                           299},
    {"image",                           8465},
    {"imagline",                        8464},
    {"imagpart",                        8465},
    {"imath",                           305},
    {"imof",                            8887},
    {"imped",                           437},
    {"in",                              8712},
    {"incare",                          8453},
    {"infin",                           8734},
    {"infintie",                        10717},
    {"inodot",                          305},
    {"int",                             8747},
    {"intcal",                          8890},
    {"integers",                        8484},
    {"intercal",                        8890},
    {"intlarhk",                        10775},
    {"intprod",                         10812},
    {"iocy",                            1105},
    {"iogon",                           303},
    {"iopf",                            120154},
    {"iota",                            953},
    {"iprod",                           10812},
    {"iquest",                          191},
    {"iscr",                            119998},
    {"isin",                            8712},
    {"isinE",                           8953},
    {"isindot",                         8949},
    {"isins",                           8948},
    {"isinsv",                          8947},
    {"isinv",                           8712},
    {"it",                              8290},
    {"itilde",                          297},
    {"iukcy",                           1110},
    {"iuml",                            239},
    {"jcirc",                           309},
    {"jcy",                             1081},
    {"jfr",                             120103},
    {"jmath",                           567},
    {"jopf",                            120155},
    {"jscr",                            119999},
    {"jsercy",                          1112},
    {"jukcy",                           1108},
    {"kappa",                           954},
    {"kappav",                          1008},
    {"kcedil",                          311},
    {"kcy",                             1082},
    {"kfr",                             120104},
    {"kgreen",                          312},
    {"khcy",                            1093},
    {"kjcy",                            1116},
    {"kopf",                            120156},
    {"kscr",                            120000},
    {"lAarr",                           8666},
    {"lArr",                            8656},
    {"lAtail",                          10523},
    {"lBarr",                           10510},
    {"lE",                              8806},
    {"lEg",                             10891},
    {"lHar",                            10594},
    {"lacute",                          314},
    {"laemptyv",                        10676},
    {"lagran",                          8466},
    {"lambda",                          955},
    {"lang",                            10216},
    {"langd",                           10641},
    {"langle",                          10216},
    {"lap",                             10885},
    {"laquo",                           171},
    {"larr",                            8592},
    {"larrb",                           8676},
    {"larrbfs",                         10527},
    {"larrfs",                          10525},
    {"larrhk",                          8617},
    {"larrlp",                          8619},
    {"larrpl",                          10553},
    {"larrsim",                         10611},
    {"larrtl",                          8610},
    {"lat",                             10923},
    {"latail",                          10521},
    {"late",                            10925},
    {"lbarr",                           10508},
    {"lbbrk",                           10098},
    {"lbrace",                          123},
    {"lbrack",                          91},
    {"lbrke",                           10635},
    {"lbrksld",                         10639},
    {"lbrkslu",                         10637},
    {"lcaron",                          318},
    {"lcedil",                          316},
    {"lceil",                           8968},
    {"lcub",                            123},
    {"lcy",                             1083},
    {"ldca",                            10550},
    {"ldquo",                           8220},
    {"ldquor",                          8222},
    {"ldrdhar",                         10599},
    {"ldrushar",                        10571},
    {"ldsh",                            8626},
    {"le",                              8804},
    {"leftarrow",                       8592},
    {"leftarrowtail",                   8610},
    {"leftharpoondown",                 8637},
    {"leftharpoonup",                   8636},
    {"leftleftarrows",                  8647},
    {"leftrightarrow",                  8596},
    {"leftrightarrows",                 8646},
    {"leftrightharpoons",               8651},
    {"leftrightsquigarrow",             8621},
    {"leftthreetimes",                  8907},
    {"leg",                             8922},
    {"leq",                             8804},
    {"leqq",                            8806},
    {"leqslant",                        10877},
    {"les",                             10877},
    {"lescc",                           10920},
    {"lesdot",                          10879},
    {"lesdoto",                         10881},
    {"lesdotor",                        10883},
    {"lesges",                          10899},
    {"lessapprox",                      10885},
    {"lessdot",                         8918},
    {"lesseqgtr",                       8922},
    {"lesseqqgtr",                      10891},
    {"lessgtr",                         8822},
    {"lesssim",                         8818},
    {"lfisht",                          10620},
    {"lfloor",                          8970},
    {"lfr",                             120105},
    {"lg",                              8822},
    {"lgE",                             10897},
    {"lhard",                           8637},
    {"lharu",                           8636},
    {"lharul",                          10602},
    {"lhblk",                           9604},
    {"ljcy",                            1113},
    {"ll",                              8810},
    {"llarr",                           8647},
    {"llcorner",                        8990},
    {"llhard",                          10603},
    {"lltri",                           9722},
    {"lmidot",                          320},
    {"lmoust",                          9136},
    {"lmoustache",                      9136},
    {"lnE",                             8808},
    {"lnap",                            10889},
    {"lnapprox",                        10889},
    {"lne",                             10887},
    {"lneq",                            10887},
    {"lneqq",                           8808},
    {"lnsim",                           8934},
    {"loang",                           10220},
    {"loarr",                           8701},
    {"lobrk",                           10214},
    {"longleftarrow",                   10229},
    {"longleftrightarrow",              10231},
    {"longmapsto",                      10236},
    {"longrightarrow",                  10230},
    {"looparrowleft",                   8619},
    {"looparrowright",                  8620},
    {"lopar",                           10629},
    {"lopf",                            120157},
    {"loplus",                          10797},
    {"lotimes",                         10804},
    {"lowast",                          8727},
    {"lowbar",                          95},
    {"loz",                             9674},
    {"lozenge",                         9674},
    {"lozf",                            10731},
    {"lpar",                            40},
    {"lparlt",                          10643},
    {"lrarr",                           8646},
    {"lrcorner",                        8991},
    {"lrhar",                           8651},
    {"lrhard",                          10605},
    {"lrm",                             8206},
    {"lrtri",                           8895},
    {"lsaquo",                          8249},
    {"lscr",                            120001},
    {"lsh",                             8624},
    {"lsim",                            8818},
    {"lsime",                           10893},
    {"lsimg",                           10895},
    {"lsqb",                            91},
    {"lsquo",                           8216},
    {"lsquor",                          8218},
    {"lstrok",                          322},
    {"lt",                              60},
    {"ltcc",                            10918},
    {"ltcir",                           10873},
    {"ltdot",                           8918},
    {"lthree",                          8907},
    {"ltimes",                          8905},
    {"ltlarr",                          10614},
    {"ltquest",                         10875},
    {"ltrPar",                          10646},
    {"ltri",                            9667},
    {"ltrie",                           8884},
    {"ltrif",                           9666},
    {"lurdshar",                        10570},
    {"luruhar",                         10598},
    {"mDDot",                           8762},
    {"macr",                            175},
    {"male",                            9794},
    {"malt",                            10016},
    {"maltese",                         10016},
    {"map",                             8614},
    {"mapsto",                          8614},
    {"mapstodown",                      8615},
    {"mapstoleft",                      8612},
    {"mapstoup",                        8613},
    {"marker",                          9646},
    {"mcomma",                          10793},
    {"mcy",                             1084},
    {"mdash",                           8212},
    {"measuredangle",                   8737},
    {"mfr",                             120106},
    {"mho",                             8487},
    {"micro",                           181},
    {"mid",                             8739},
    {"midast",                          42},
    {"midcir",                          10992},
    {"middot",                          183},
    {"minus",                           8722},
    {"minusb",                          8863},
    {"minusd",                          8760},
    {"minusdu",                         10794},
    {"mlcp",                            10971},
    {"mldr",                            8230},
    {"mnplus",                          8723},
    {"models",                          8871},
    {"mopf",                            120158},
    {"mp",                              8723},
    {"mscr",                            120002},
    {"mstpos",                          8766},
    {"mu",                              956},
    {"multimap",                        8888},
    {"mumap",                           8888},
    {"nLeftarrow",                      8653},
    {"nLeftrightarrow",                 8654},
    {"nRightarrow",                     8655},
    {"nVDash",                          8879},
    {"nVdash",                          8878},
    {"nabla",                           8711},
    {"nacute",                          324},
    {"nap",                             8777},
    {"napos",                           329},
    {"napprox",                         8777},
    {"natur",                           9838},
    {"natural",                         9838},
    {"naturals",                        8469},
    {"nbsp",                            160},
    {"ncap",                            10819},
    {"ncaron",                          328},
    {"ncedil",                          326},
    {"ncong",                           8775},
    {"ncup",                            10818},
    {"ncy",                             1085},
    {"ndash",                           8211},
    {"ne",                              8800},
    {"neArr",                           8663},
    {"nearhk",                          10532},
    {"nearr",                           8599},
    {"nearrow",                         8599},
    {"nequiv",                          8802},
    {"nesear",                          10536},
    {"nexist",                          8708},
    {"nexists",                         8708},
    {"nfr",                             120107},
    {"nge",                             8817},
    {"ngeq",                            8817},
    {"ngsim",                           8821},
    {"ngt",                             8815},
    {"ngtr",                            8815},
    {"nhArr",                           8654},
    {"nharr",                           8622},
    {"nhpar",                           10994},
    {"ni",                              8715},
    {"nis",                             8956},
    {"nisd",                            8954},
    {"niv",                             8715},
    {"njcy",                            1114},
    {"nlArr",                           8653},
    {"nlarr",                           8602},
    {"nldr",                            8229},
    {"nle",                             8816},
    {"nleftarrow",                      8602},
    {"nleftrightarrow",                 8622},
    {"nleq",                            8816},
    {"nless",                           8814},
    {"nlsim",                           8820},
    {"nlt",                             8814},
    {"nltri",                           8938},
    {"nltrie",                          8940},
    {"nmid",                            8740},
    {"nopf",                            120159},
    {"not",                             172},
    {"notin",                           8713},
    {"notinva",                         8713},
    {"notinvb",                         8951},
    {"notinvc",                         8950},
    {"notni",                           8716},
    {"notniva",                         8716},
    {"notnivb",                         8958},
    {"notnivc",                         8957},
    {"npar",                            8742},
    {"nparallel",                       8742},
    {"npolint",                         10772},
    {"npr",                             8832},
    {"nprcue",                          8928},
    {"nprec",                           8832},
    {"nrArr",                           8655},
    {"nrarr",                           8603},
    {"nrightarrow",                     8603},
    {"nrtri",                           8939},
    {"nrtrie",                          8941},
    {"nsc",                             8833},
    {"nsccue",                          8929},
    {"nscr",                            120003},
    {"nshortmid",                       8740},
    {"nshortparallel",                  8742},
    {"nsim",                            8769},
    {"nsime",                           8772},
    {"nsimeq",                          8772},
    {"nsmid",                           8740},
    {"nspar",                           8742},
    {"nsqsube",                         8930},
    {"nsqsupe",                         8931},
    {"nsub",                            8836},
    {"nsube",                           8840},
    {"nsubseteq",                       8840},
    {"nsucc",                           8833},
    {"nsup",                            8837},
    {"nsupe",                           8841},
    {"nsupseteq",                       8841},
    {"ntgl",                            8825},
    {"ntilde",                          241},
    {"ntlg",                            8824},
    {"ntriangleleft",                   8938},
    {"ntrianglelefteq",                 8940},
    {"ntriangleright",                  8939},
    {"ntrianglerighteq",                8941},
    {"nu",                              957},
    {"num",                             35},
    {"numero",                          8470},
    {"numsp",                           8199},
    {"nvDash",                          8877},
    {"nvHarr",                          10500},
    {"nvdash",                          8876},
    {"nvinfin",                         10718},
    {"nvlArr",                          10498},
    {"nvrArr",                          10499},
    {"nwArr",                           8662},
    {"nwarhk",                          10531},
    {"nwarr",                           8598},
    {"nwarrow",                         8598},
    {"nwnear",                          10535},
    {"oS",                              9416},
    {"oacute",                          243},
    {"oast",                            8859},
    {"ocir",                            8858},
    {"ocirc",                           244},
    {"ocy",                             1086},
    {"odash",                           8861},
    {"odblac",                          337},
    {"odiv",                            10808},
    {"odot",                            8857},
    {"odsold",                          10684},
    {"oelig",                           339},
    {"ofcir",                           10687},
    {"ofr",                             120108},
    {"ogon",                            731},
    {"ograve",                          242},
    {"ogt",                             10689},
    {"ohbar",                           10677},
    {"ohm",                             937},
    {"oint",                            8750},
    {"olarr",                           8634},
    {"olcir",                           10686},
    {"olcross",                         10683},
    {"oline",                           8254},
    {"olt",                             10688},
    {"omacr",                           333},
    {"omega",                           969},
    {"omicron",                         959},
    {"omid",                            10678},
    {"ominus",                          8854},
    {"oopf",                            120160},
    {"opar",                            10679},
    {"operp",                           10681},
    {"oplus",                           8853},
    {"or",                              8744},
    {"orarr",                           8635},
    {"ord",                             10845},
    {"order",                           8500},
    {"orderof",                         8500},
    {"ordf",                            170},
    {"ordm",                            186},
    {"origof",                          8886},
    {"oror",                            10838},
    {"orslope",                         10839},
    {"orv",                             10843},
    {"oscr",                            8500},
    {"oslash",                          248},
    {"osol",                            8856},
    {"otilde",                          245},
    {"otimes",                          8855},
    {"otimesas",                        10806},
    {"ouml",                            246},
    {"ovbar",                           9021},
    {"par",                             8741},
    {"para",                            182},
    {"parallel",                        8741},
    {"parsim",                          10995},
    {"parsl",                           11005},
    {"part",                            8706},
    {"pcy",                             1087},
    {"percnt",                          37},
    {"period",                          46},
    {"permil",                          8240},
    {"perp",                            8869},
    {"pertenk",                         8241},
    {"pfr",                             120109},
    {"phi",                             966},
    {"phiv",                            981},
    {"phmmat",                          8499},
    {"phone",                           9742},
    {"pi",                              960},
    {"pitchfork",                       8916},
    {"piv",                             982},
    {"planck",                          8463},
    {"planckh",                         8462},
    {"plankv",                          8463},
    {"plus",                            43},
    {"plusacir",                        10787},
    {"plusb",                           8862},
    {"pluscir",                         10786},
    {"plusdo",                          8724},
    {"plusdu",                          10789},
    {"pluse",                           10866},
    {"plusmn",                          177},
    {"plussim",                         10790},
    {"plustwo",                         10791},
    {"pm",                              177},
    {"pointint",                        10773},
    {"popf",                            120161},
    {"pound",                           163},
    {"pr",                              8826},
    {"prE",                             10931},
    {"prap",                            10935},
    {"prcue",                           8828},
    {"pre",                             10927},
    {"prec",                            8826},
    {"precapprox",                      10935},
    {"preccurlyeq",                     8828},
    {"preceq",                          10927},
    {"precnapprox",                     10937},
    {"precneqq",                        10933},
    {"precnsim",                        8936},
    {"precsim",                         8830},
    {"prime",                           8242},
    {"primes",                          8473},
    {"prnE",                            10933},
    {"prnap",                           10937},
    {"prnsim",                          8936},
    {"prod",                            8719},
    {"profalar",                        9006},
    {"profline",                        8978},
    {"profsurf",                        8979},
    {"prop",                            8733},
    {"propto",                          8733},
    {"prsim",                           8830},
    {"prurel",                          8880},
    {"pscr",                            120005},
    {"psi",                             968},
    {"puncsp",                          8200},
    {"qfr",                             120110},
    {"qint",                            10764},
    {"qopf",                            120162},
    {"qprime",                          8279},
    {"qscr",                            120006},
    {"quaternions",                     8461},
    {"quatint",                         10774},
    {"quest",                           63},
    {"questeq",                         8799},
    {"quot",                            34},
    {"rAarr",                           8667},
    {"rArr",                            8658},
    {"rAtail",                          10524},
    {"rBarr",                           10511},
    {"rHar",                            10596},
    {"racute",                          341},
    {"radic",                           8730},
    {"raemptyv",                        10675},
    {"rang",                            10217},
    {"rangd",                           10642},
    {"range",                           10661},
    {"rangle",                          10217},
    {"raquo",                           187},
    {"rarr",                            8594},
    {"rarrap",                          10613},
    {"rarrb",                           8677},
    {"rarrbfs",                         10528},
    {"rarrc",                           10547},
    {"rarrfs",                          10526},
    {"rarrhk",                          8618},
    {"rarrlp",                          8620},
    {"rarrpl",                          10565},
    {"rarrsim",                         10612},
    {"rarrtl",                          8611},
    {"rarrw",                           8605},
    {"ratail",                          10522},
    {"ratio",                           8758},
    {"rationals",                       8474},
    {"rbarr",                           10509},
    {"rbbrk",                           10099},
    {"rbrace",                          125},
    {"rbrack",                          93},
    {"rbrke",                           10636},
    {"rbrksld",                         10638},
    {"rbrkslu",                         10640},
    {"rcaron",                          345},
    {"rcedil",                          343},
    {"rceil",                           8969},
    {"rcub",                            125},
    {"rcy",                             1088},
    {"rdca",                            10551},
    {"rdldhar",                         10601},
    {"rdquo",                           8221},
    {"rdquor",                          8221},
    {"rdsh",                            8627},
    {"real",                            8476},
    {"realine",                         8475},
    {"realpart",                        8476},
    {"reals",                           8477},
    {"rect",                            9645},
    {"reg",                             174},
    {"rfisht",                          10621},
    {"rfloor",                          8971},
    {"rfr",                             120111},
    {"rhard",                           8641},
    {"rharu",                           8640},
    {"rharul",                          10604},
    {"rho",                             961},
    {"rhov",                            1009},
    {"rightarrow",                      8594},
    {"rightarrowtail",                  8611},
    {"rightharpoondown",                8641},
    {"rightharpoonup",                  8640},
    {"rightleftarrows",                 8644},
    {"rightleftharpoons",               8652},
    {"rightrightarrows",                8649},
    {"rightsquigarrow",                 8605},
    {"rightthreetimes",                 8908},
    {"ring",                            730},
    {"risingdotseq",                    8787},
    {"rlarr",                           8644},
    {"rlhar",                           8652},
    {"rlm",                             8207},
    {"rmoust",                          9137},
    {"rmoustache",                      9137},
    {"rnmid",                           10990},
    {"roang",                           10221},
    {"roarr",                           8702},
    {"robrk",                           10215},
    {"ropar",                           10630},
    {"ropf",                            120163},
    {"roplus",                          10798},
    {"rotimes",                         10805},
    {"rpar",                            41},
    {"rpargt",                          10644},
    {"rppolint",                        10770},
    {"rrarr",                           8649},
    {"rsaquo",                          8250},
    {"rscr",                            120007},
    {"rsh",                             8625},
    {"rsqb",                            93},
    {"rsquo",                           8217},
    {"rsquor",                          8217},
    {"rthree",                          8908},
    {"rtimes",                          8906},
    {"rtri",                            9657},
    {"rtrie",                           8885},
    {"rtrif",                           9656},
    {"rtriltri",                        10702},
    {"ruluhar",                         10600},
    {"rx",                              8478},
    {"sacute",                          347},
    {"sbquo",                           8218},
    {"sc",                              8827},
    {"scE",                             10932},
    {"scap",                            10936},
    {"scaron",                          353},
    {"sccue",                           8829},
    {"sce",                             10928},
    {"scedil",                          351},
    {"scirc",                           349},
    {"scnE",                            10934},
    {"scnap",                           10938},
    {"scnsim",                          8937},
    {"scpolint",                        10771},
    {"scsim",                           8831},
    {"scy",                             1089},
    {"sdot",                            8901},
    {"sdotb",                           8865},
    {"sdote",                           10854},
    {"seArr",                           8664},
    {"searhk",                          10533},
    {"searr",                           8600},
    {"searrow",                         8600},
    {"sect",                            167},
    {"semi",                            59},
    {"seswar",                          10537},
    {"setminus",                        8726},
    {"setmn",                           8726},
    {"sext",                            10038},
    {"sfr",                             120112},
    {"sfrown",                          8994},
    {"sharp",                           9839},
    {"shchcy",                          1097},
    {"shcy",                            1096},
    {"shortmid",                        8739},
    {"shortparallel",                   8741},
    {"shy",                             173},
    {"sigma",                           963},
    {"sigmaf",                          962},
    {"sigmav",                          962},
    {"sim",                             8764},
    {"simdot",                          10858},
    {"sime",                            8771},
    {"simeq",                           8771},
    {"simg",                            10910},
    {"simgE",                           10912},
    {"siml",                            10909},
    {"simlE",                           10911},
    {"simne",                           8774},
    {"simplus",                         10788},
    {"simrarr",                         10610},
    {"slarr",                           8592},
    {"smallsetminus",                   8726},
    {"smashp",                          10803},
    {"smeparsl",                        10724},
    {"smid",                            8739},
    {"smile",                           8995},
    {"smt",                             10922},
    {"smte",                            10924},
    {"softcy",                          1100},
    {"sol",                             47},
    {"solb",                            10692},
    {"solbar",                          9023},
    {"sopf",                            120164},
    {"spades",                          9824},
    {"spadesuit",                       9824},
    {"spar",                            8741},
    {"sqcap",                           8851},
    {"sqcup",                           8852},
    {"sqsub",                           8847},
    {"sqsube",                          8849},
    {"sqsubset",                        8847},
    {"sqsubseteq",                      8849},
    {"sqsup",                           8848},
    {"sqsupe",                          8850},
    {"sqsupset",                        8848},
    {"sqsupseteq",                      8850},
    {"squ",                             9633},
    {"square",                          9633},
    {"squarf",                          9642},
    {"squf",                            9642},
    {"srarr",                           8594},
    {"sscr",                            120008},
    {"ssetmn",                          8726},
    {"ssmile",                          8995},
    {"sstarf",                          8902},
    {"star",                            9734},
    {"starf",                           9733},
    {"straightepsilon",                 1013},
    {"straightphi",                     981},
    {"strns",                           175},
    {"sub",                             8834},
    {"subE",                            10949},
    {"subdot",                          10941},
    {"sube",                            8838},
    {"subedot",                         10947},
    {"submult",                         10945},
    {"subnE",                           10955},
    {"subne",                           8842},
    {"subplus",                         10943},
    {"subrarr",                         10617},
    {"subset",                          8834},
    {"subseteq",                        8838},
    {"subseteqq",                       10949},
    {"subsetneq",                       8842},
    {"subsetneqq",                      10955},
    {"subsim",                          10951},
    {"subsub",                          10965},
    {"subsup",                          10963},
    {"succ",                            8827},
    {"succapprox",                      10936},
    {"succcurlyeq",                     8829},
    {"succeq",                          10928},
    {"succnapprox",                     10938},
    {"succneqq",                        10934},
    {"succnsim",                        8937},
    {"succsim",                         8831},
    {"sum",                             8721},
    {"sung",                            9834},
    {"sup",                             8835},
    {"sup1",                            185},
    {"sup2",                            178},
    {"sup3",                            179},
    {"supE",                            10950},
    {"supdot",                          10942},
    {"supdsub",                         10968},
    {"supe",                            8839},
    {"supedot",                         10948},
    {"suphsol",                         10185},
    {"suphsub",                         10967},
    {"suplarr",                         10619},
    {"supmult",                         10946},
    {"supnE",                           10956},
    {"supne",                           8843},
    {"supplus",                         10944},
    {"supset",                          8835},
    {"supseteq",                        8839},
    {"supseteqq",                       10950},
    {"supsetneq",                       8843},
    {"supsetneqq",                      10956},
    {"supsim",                          10952},
    {"supsub",                          10964},
    {"supsup",                          10966},
    {"swArr",                           8665},
    {"swarhk",                          10534},
    {"swarr",                           8601},
    {"swarrow",                         8601},
    {"swnwar",                          10538},
    {"szlig",                           223},
    {"target",                          8982},
    {"tau",                             964},
    {"tbrk",                            9140},
    {"tcaron",                          357},
    {"tcedil",                          355},
    {"tcy",                             1090},
    {"tdot",                            8411},
    {"telrec",                          8981},
    {"tfr",                             120113},
    {"there4",                          8756},
    {"therefore",                       8756},
    {"theta",                           952},
    {"thetasym",                        977},
    {"thetav",                          977},
    {"thickapprox",                     8776},
    {"thicksim",                        8764},
    {"thinsp",                          8201},
    {"thkap",                           8776},
    {"thksim",                          8764},
    {"thorn",                           254},
    {"tilde",                           732},
    {"times",                           215},
    {"timesb",                          8864},
    {"timesbar",                        10801},
    {"timesd",                          10800},
    {"tint",                            8749},
    {"toea",                            10536},
    {"top",                             8868},
    {"topbot",                          9014},
    {"topcir",                          10993},
    {"topf",                            120165},
    {"topfork",                         10970},
    {"tosa",                            10537},
    {"tprime",                          8244},
    {"trade",                           8482},
    {"triangle",                        9653},
    {"triangledown",                    9663},
    {"triangleleft",                    9667},
    {"trianglelefteq",                  8884},
    {"triangleq",                       8796},
    {"triangleright",                   9657},
    {"trianglerighteq",                 8885},
    {"tridot",                          9708},
    {"trie",                            8796},
    {"triminus",                        10810},
    {"triplus",                         10809},
    {"trisb",                           10701},
    {"tritime",                         10811},
    {"trpezium",                        9186},
    {"tscr",                            120009},
    {"tscy",                            1094},
    {"tshcy",                           1115},
    {"tstrok",                          359},
    {"twixt",                           8812},
    {"twoheadleftarrow",                8606},
    {"twoheadrightarrow",               8608},
    {"uArr",                            8657},
    {"uHar",                            10595},
    {"uacute",                          250},
    {"uarr",                            8593},
    {"ubrcy",                           1118},
    {"ubreve",                          365},
    {"ucirc",                           251},
    {"ucy",                             1091},
    {"udarr",                           8645},
    {"udblac",                          369},
    {"udhar",                           10606},
    {"ufisht",                          10622},
    {"ufr",                             120114},
    {"ugrave",                          249},
    {"uharl",                           8639},
    {"uharr",                           8638},
    {"uhblk",                           9600},
    {"ulcorn",                          8988},
    {"ulcorner",                        8988},
    {"ulcrop",                          8975},
    {"ultri",                           9720},
    {"umacr",                           363},
    {"uml",                             168},
    {"uogon",                           371},
    {"uopf",                            120166},
    {"uparrow",                         8593},
    {"updownarrow",                     8597},
    {"upharpoonleft",                   8639},
    {"upharpoonright",                  8638},
    {"uplus",                           8846},
    {"upsi",                            965},
    {"upsih",                           978},
    {"upsilon",                         965},
    {"upuparrows",                      8648},
    {"urcorn",                          8989},
    {"urcorner",                        8989},
    {"urcrop",                          8974},
    {"uring",                           367},
    {"urtri",                           9721},
    {"uscr",                            120010},
    {"utdot",                           8944},
    {"utilde",                          361},
    {"utri",                            9653},
    {"utrif",                           9652},
    {"uuarr",                           8648},
    {"uuml",                            252},
    {"uwangle",                         10663},
    {"vArr",                            8661},
    {"vBar",                            10984},
    {"vBarv",                           10985},
    {"vDash",                           8872},
    {"vangrt",                          10652},
    {"varepsilon",                      1013},
    {"varkappa",                        1008},
    {"varnothing",                      8709},
    {"varphi",                          981},
    {"varpi",                           982},
    {"varpropto",                       8733},
    {"varr",                            8597},
    {"varrho",                          1009},
    {"varsigma",                        962},
    {"vartheta",                        977},
    {"vartriangleleft",                 8882},
    {"vartriangleright",                8883},
    {"vcy",                             1074},
    {"vdash",                           8866},
    {"vee",                             8744},
    {"veebar",                          8891},
    {"veeeq",                           8794},
    {"vellip",                          8942},
    {"verbar",                          124},
    {"vert",                            124},
    {"vfr",                             120115},
    {"vltri",                           8882},
    {"vopf",                            120167},
    {"vprop",                           8733},
    {"vrtri",                           8883},
    {"vscr",                            120011},
    {"vzigzag",                         10650},
    {"wcirc",                           373},
    {"wedbar",                          10847},
    {"wedge",                           8743},
    {"wedgeq",                          8793},
    {"weierp",                          8472},
    {"wfr",                             120116},
    {"wopf",                            120168},
    {"wp",                              8472},
    {"wr",                              8768},
    {"wreath",                          8768},
    {"wscr",                            120012},
    {"xcap",                            8898},
    {"xcirc",                           9711},
    {"xcup",                            8899},
    {"xdtri",                           9661},
    {"xfr",                             120117},
    {"xhArr",                           10234},
    {"xharr",                           10231},
    {"xi",                              958},
    {"xlArr",                           10232},
    {"xlarr",                           10229},
    {"xmap",                            10236},
    {"xnis",                            8955},
    {"xodot",                           10752},
    {"xopf",                            120169},
    {"xoplus",                          10753},
    {"xotime",                          10754},
    {"xrArr",                           10233},
    {"xrarr",                           10230},
    {"xscr",                            120013},
    {"xsqcup",                          10758},
    {"xuplus",                          10756},
    {"xutri",                           9651},
    {"xvee",                            8897},
    {"xwedge",                          8896},
    {"yacute",                          253},
    {"yacy",                            1103},
    {"ycirc",                           375},
    {"ycy",                             1099},
    {"yen",                             165},
    {"yfr",                             120118},
    {"yicy",                            1111},
    {"yopf",                            120170},
    {"yscr",                            120014},
    {"yucy",                            1102},
    {"yuml",                            255},
    {"zacute",                          378},
    {"zcaron",                          382},
    {"zcy",                             1079},
    {"zdot",                            380},
    {"zeetrf",                          8488},
    {"zeta",                            950},
    {"zfr",                             120119},
    {"zhcy",                            1078},
    {"zigrarr",                         8669},
    {"zopf",                            120171},
    {"zscr",                            120015},
    {"zwj",                             8205},
    {"zwnj",                            8204},
//
// The names from here down seem to map onto pairs of Unicode items. Eg
// 342 is "Combining not tilde above". I will not support these at least yet!
//
//  {"NotEqualTilde",                   8770, 824},
//  {"NotGreaterFullEqual",             8807, 824},
//  {"NotGreaterGreater",               8811, 824},
//  {"NotGreaterSlantEqual",            10878, 824},
//  {"NotHumpDownHump",                 8782, 824},
//  {"NotHumpEqual",                    8783, 824},
//  {"NotLeftTriangleBar",              10703, 824},
//  {"NotLessLess",                     8810, 824},
//  {"NotLessSlantEqual",               10877, 824},
//  {"NotNestedGreaterGreater",         10914, 824},
//  {"NotNestedLessLess",               10913, 824},
//  {"NotPrecedesEqual",                10927, 824},
//  {"NotRightTriangleBar",             10704, 824},
//  {"NotSquareSubset",                 8847, 824},
//  {"NotSquareSuperset",               8848, 824},
//  {"NotSubset",                       8834, 8402},
//  {"NotSucceedsEqual",                10928, 824},
//  {"NotSucceedsTilde",                8831, 824},
//  {"NotSuperset",                     8835, 8402},
//  {"ThickSpace",                      8287, 8202},
//  {"acE",                             8766, 819},  beware name vs hex
//  {"bne",                             61, 8421},
//  {"bnequiv",                         8801, 8421},
//  {"caps",                            8745, 65024}
//  {"cups",                            8746, 65024}
//  {"fjlig",                           102, 106},
//  {"gesl",                            8923, 65024}
//  {"gvertneqq",                       8809, 65024}
//  {"gvnE",                            8809, 65024}
//  {"lates",                           10925, 65024
//  {"lesg",                            8922, 65024}
//  {"lvertneqq",                       8808, 65024}
//  {"lvnE",                            8808, 65024}
//  {"nGg",                             8921, 824},
//  {"nGt",                             8811, 8402},
//  {"nGtv",                            8811, 824},
//  {"nLl",                             8920, 824},
//  {"nLt",                             8810, 8402},
//  {"nLtv",                            8810, 824},
//  {"nang",                            8736, 8402},
//  {"napE",                            10864, 824},
//  {"napid",                           8779, 824},
//  {"nbump",                           8782, 824},
//  {"nbumpe",                          8783, 824},
//  {"ncongdot",                        10861, 824},
//  {"nedot",                           8784, 824},
//  {"nesim",                           8770, 824},
//  {"ngE",                             8807, 824},
//  {"ngeqq",                           8807, 824},
//  {"ngeqslant",                       10878, 824},
//  {"nges",                            10878, 824},
//  {"nlE",                             8806, 824},
//  {"nleqq",                           8806, 824},
//  {"nleqslant",                       10877, 824},
//  {"nles",                            10877, 824},
//  {"notinE",                          8953, 824},
//  {"notindot",                        8949, 824},
//  {"nparsl",                          11005, 8421},
//  {"npart",                           8706, 824},
//  {"npre",                            10927, 824},
//  {"npreceq",                         10927, 824},
//  {"nrarrc",                          10547, 824},
//  {"nrarrw",                          8605, 824},
//  {"nsce",                            10928, 824},
//  {"nsubE",                           10949, 824},
//  {"nsubset",                         8834, 8402},
//  {"nsubseteqq",                      10949, 824},
//  {"nsucceq",                         10928, 824},
//  {"nsupE",                           10950, 824},
//  {"nsupset",                         8835, 8402},
//  {"nsupseteqq",                      10950, 824},
//  {"nvap",                            8781, 8402},
//  {"nvge",                            8805, 8402},
//  {"nvgt",                            62, 8402},
//  {"nvle",                            8804, 8402},
//  {"nvlt",                            60, 8402},
//  {"nvltrie",                         8884, 8402},
//  {"nvrtrie",                         8885, 8402},
//  {"nvsim",                           8764, 8402},
//  {"race",                            8765, 817},  beware suffix "ace"
//  {"smtes",                           10924, 65024},
//  {"sqcaps",                          8851, 65024},
//  {"sqcups",                          8852, 65024},
//  {"varsubsetneq",                    8842, 65024},
//  {"varsubsetneqq",                   10955, 65024},
//  {"varsupsetneq",                    8843, 65024},
//  {"varsupsetneqq",                   10956, 65024},
//  {"vnsub",                           8834, 8402},
//  {"vnsup",                           8835, 8402},
//  {"vsubnE",                          10955, 65024},
//  {"vsubne",                          8842, 65024},
//  {"vsupnE",                          10956, 65024},
//  {"vsupne",                          8843, 65024},
    {NULL,                              -1}
};

static int compare_strings(const void *a, const void *b)
{   const uniname *a1 = (uniname *)a;
    const uniname *b1 = (uniname *)b;
    return strcmp(a1->name, b1->name);
}

static int lookup_name(const char *s)
{   uniname k, *p;
    k.name = s;
    p = (uniname *)bsearch(&k, unicode_names,
                           sizeof(unicode_names)/sizeof(unicode_names[0]) -
                           sizeof(unicode_names[0]), // allow for the terminator
                           sizeof(unicode_names[0]),
                           compare_strings);
    if (p == NULL) return -1; // not found
    else return p->code;
}

static int lookup_wide_name(const wchar_t *s)
{   char narrow[20];
    int i;
    for (i=0; i<sizeof(narrow)-1; i++)
    {   if (s[i] == 0) break;
        if (s[i] >= 0x7f) return -1; // not a basic ASCII character
        narrow[i] = s[i];
    }
    narrow[i] = 0;
    return lookup_name(narrow);
}

const char *lookup_code(int c)
{   int i;
//
// I do a simple linear search here. It is cheap-enough given that it is
// only needed when the user types a special command, ALT-x. It does not
// matter here that I scan the very final NULL entry.
//
    for (i=0; i<sizeof(unicode_names)/sizeof(unicode_names[0]); i++)
    {   if (unicode_names[i].code == c) return unicode_names[i].name;
    }
    return NULL;
}

static wchar_t wide_char_name[20];

const wchar_t *wide_lookup_code(int c)
{   const char *s = lookup_code(c);
    wchar_t *p;
    if (s == NULL) return NULL;
    p = wide_char_name;
    while (*s != 0) *p++ = (*s++ & 0xff);
    *p = 0;
    return wide_char_name;
}

static void term_replace_chars_backwards(int n, const wchar_t *s)
{
//
// Replace n characters that are before the caret with bytes from the
// string s. The caret had better not be in the middle of a surrogate pair!
//
    int m = wcslen(s);
    if (n > m)        // Overall this deletes characters
    {   int i = insert_point - n;
        for (;;)
        {   input_line[i] = input_line[i+n-m];
            if (input_line[i] == 0) break;
            i++;
        }
        insert_point -= (n-m);
    }
    else if (m > n)   // Overall this inserts characters
    {   int i = insert_point;
        while (input_line[i] != 0) i++;
        while (i >= insert_point)
        {   input_line[i+m-n] = input_line[i];
            i--;
        }
        insert_point += (m-n);
    }
    m = insert_point - m;
    while (*s != 0) input_line[m++] = *s++;
}

static wchar_t input_word[40];
static wchar_t output_word[40];

static void make_wchar(wchar_t *s, int c)
{   c &= 0x001fffff;
    if (sizeof(wchar_t) == 4 || c <= 0xffff)
    {   s[0] = c;
        s[1] = 0;
    }
    else
    {   s[0] = 0xd800 + ((c >> 10) & 0x3ff);
        s[1] = 0xdc00 + (c & 0x3ff);
        s[2] = 0;
    }
}

static void term_ctrl_z_command(void)
{
//
// It is not yet clear that I have anything much to allocate this to. In
// emacs it would be "obey extended command".
//
    insert_point += swprintf(&input_line[insert_point], input_line_size-insert_point, L"<^X>");
    term_bell();
    term_redisplay();
}

void term_unicode_convert(void)
{
//
// If you position the caret to the right of (up to) 6 hex digits and
// go ALT-X then the digits are replaced by single Unicode character.
// This may (and indeed often will) be a multi-byte character stored in the
// input buffer in UTF-8 form.
// There will also be a selection of words so that if you type ALT-X with
// the caret to the right of the word you get a conversion to a single
// character. Eg think in terms of names such as "euro" and "alpha". The
// initial set of names I use is the list of HTML entities.
//
// If you are to the right of a character that is a genuine multi-byte
// UTF-8 sequence or that seems to be in windows-1252-1 (because it has a top
// bit set but the preceeding bytes would not parse properly for UTF-8) then
// that character is expanded to a name or to hex. If it is to be expanded to
// hex it is normally converted to exactly 4 digits - but if the code is
// too large for that (which is improbable, I believe) it expands to 6.
//
// The idea is that ALT-X will cycle between the possible meanings of the
// input.
//
// There are a rather small number of cases where there could be ambiguity.
// These are coped with by arranging that successive uses of ALT-X cycle
// through all possibilities.
// Here are some particular cases that are a nuisance:
//    "123456"   The issue here is how many hex digits are to be used. The
//               first choice here will be to use exactly 4, and the
//               second choice exactly 6. I will only ever process 4 or 6
//               digits, and I will not accept codes over 10ffff or in the
//               surrogate region d800-dfff.
//    "oline"    Choice one is to interpret this "oli" followed
//               by a "not equal to" symbol. Choice two will be to treat
//               it as a single name for a "spacing overscore".
//    "frac12"   Choice one "fr" followed by the Unicode character U+ac12
//               (a Hangul (Korean) syllable). Two will be to turn it
//               into a fraction (1/2) symbol.
// The policy I will attempt to arrange is that all possible interpretations
// are cycled through, with the original state eventually reinstated.
//
// Well let me consider the possible display options by showing illustrations
// of all the cases. I will write (u+nnnn) to denote a single character. I
// use "10" here the possible first 2 digits of a 6-digit hex value from
// 00 to 10, and X for any character that can not lead to special
// prefixing.
//
// X(u+nnnn) 10(u+nnnn) X(u+03b1) (u+00bd)    X(u+203e)    10(u+203e)
// Xnnnn     10nnnn     Xalpha    frac12      Xoline       10oline
//           (u+10nnnn) X03b1     fr(u+ac12)  Xoli(u+2260) 10oli(u+2260)
//                                00bd        Xoli2260     10oli2260
//                                            X203e        10203e
//                                                         (u+10203e)
//
// I judge that restricting support to only 4 hex digits would not simplify
// things enough to really transform matters, but I will rely on having
// all names denote symbols in the basic multilingual plane.
//
// The following transformation rules are designed to cause the code to
// cycle through all possibilities:
//                                                            example
// longest name that matches     -> character       10oline    -> 10(u+203e)
// 01 to 10 followed by 4 hex    -> character       102030     -> (u+102030)
// char with name NNNN
//    NNNN has a suffix          -> split suffix    (u+203e)   -> oli(u+2260)
//    NNNN has a prefix          -> hex             oli(u+2260)->oli2260
// char NNMMMM over 0xffff
//    MMMM has a name            -> NNname          (u+10203e) ->10oline
//    otherwise                  -> 6 hex           (u+102030) -> 102030
// char <= 0xffff                -> 4 hex           (i+1234)   -> 1234
// 4 hex of name with prefix     -> hex expanded    oli2260    -> 203e
// 4 hex of name                 -> name            203e       -> oline
// 4 hex of unnamed character    -> character       1234       -> (u+1234)
//
    int i, n, c;
    const wchar_t *p;
    if (insert_point == prompt_length)
    {   term_bell();
        return;
    }
//
// I will first see if I can find a name, and I will look for long ones first.
// The "32" here is the length of the longest word in my table of names, and
// I note that HTML 5 has "CounterClockwiseContourIntegral" has 31 characters.
//
    for (n=32; n>=2; n--) // word length to seek
    {   if (prompt_length+n>insert_point) continue; // not this many chars
        for (i=0; i<n; i++)
            input_word[i] = input_line[insert_point-n+i];
        input_word[n] = 0;           // extract the (potential) word
        c = lookup_wide_name(input_word);
        if (c == -1) continue;    // not a recognised name
// The code may be over u+ffff and so if sizeof(wchar_t)==2 it needs packing
        make_wchar(output_word, c);
        term_replace_chars_backwards(n, output_word);
        return;
    }
//
// Next check for a 6-digit hex value. Note that the first two digits
// must be 01, 02, ... 0f, 10. If you had "00" there then there was no
// point in using a 6-digit format. If you have any value beyond "10" you
// are outside the Unicode range.
//
    if (insert_point - prompt_length >= 6)
    {   p = &input_line[insert_point-6];
        if ((p[0] == '0' && iswxdigit(p[1]) && p[1] != '0') ||
            (p[0] == '1' && p[1] == '0'))
        {   c = (hexval(p[0]) << 4) | hexval(p[1]);
//
// By virtue of packing up digits here using OR it will be the case that
// if ANY of the calls to hexval return a negative value I can be certain
// that the overall result will be negative.
//
            for (i=2; i<6 && c > 0; i++)
            {   n = hexval(p[i]);
                c = (c << 4) | n;
            }
            if (c > 0)
            {   make_wchar(output_word, c);
                term_replace_chars_backwards(6, output_word);
                return;
            }
        }
    }
//
// In the next two cases the character before the caret has a name
// associated with it. Well first I will just extract a Unicode character
// from before the caret.
//
    if (insert_point - prompt_length >= 1)
    {   n = 1;
        c = input_line[insert_point-1];
        if (is_low_surrogate(c) &&
            insert_point - prompt_length >= 2 &&
            is_high_surrogate(input_line[insert_point-2]))
        {   n = 2;
            c = 0x10000 +
                ((input_line[insert_point-2] & 0x3ff) << 10) +
                (c & 0x3ff);
        }
    }
    else n = 0, c = -1;
//
// See if the character has a name.
//
    p = wide_lookup_code(c);
//
// Now I have two messy cases to detect. The first is if the name
// I have just found has a shorter name as a terminal sub-string. The second
// is if the name is a suffix of something longer and the prefix part happens
// to be in the buffer ahead of it. These two cases could both happen together
// if there were say names ABC, BC and just C in the list of entities, but
// I am glad to say that that is not the case. Beware if you ever add new
// entity-names! I will test for these cases in a pretty crude manner.
//
    if (p != NULL)
    {   int w = -1;
        const wchar_t *p1 = p+1;
        while (*p1 != 0)
        {   w = lookup_wide_name(p1);
            if (w != -1) break;    // Found a suffix
            p1++;
        }
//
// The code here will convert (u+203e) to oli(u+2260) via expanding to
// the name "oline" and then re-coding the last two letters "ne". And
// a whole pile of other similar cases such Eaccute, rang, Theta, lfloor,
// ntilde, otimes and Yuml. I count 57 cases in the HTML 4 entity table, and
// theer will be more now I have moved to use of the HTML 5 list.
//
        if (w != -1)
        {   wcscpy(output_word, p);
            make_wchar(&output_word[p1-p], w);
            term_replace_chars_backwards(n, output_word);
            return;
        }
//
// Now there is the possible conversion the other way, where (for example)
// oli(u+2260) is in the buffer. If I merely expanded the unicode character
// to its name here I would end up with "oline" and the next ALT-X would
// convert that to (u+203e) - I would never get to see thing in hex form.
// So in this case I merely expand the character to 4 hex digits.
//
        for (i=1; i+wcslen(p)<9; i++)
        {   // i is the number of prefix characters to test for
            if (insert_point - prompt_length >= i+n)
            {   memcpy(input_word, &input_line[insert_point-i-n],
                       i*sizeof(wchar_t));
                wcscpy(&input_word[i], p);
//
// I have now concatenated some stuff from the input buffer with the
// expanded character name and look it up. If I find a match I will
// convert the character to hex. Because the character itself was one
// with a name it will fit within 4 digits.
//
                if (lookup_wide_name(input_word) != -1)
                {   swprintf(output_word, 16, L"%.4x", c);
                    term_replace_chars_backwards(n, output_word);
                    return;
                }
            }
        }
    }
//
// Here I have a character with code c and I am not processing any
// name it might have just now. However maybe its low 16 bits is a named
// character. In which case turn the low 16 bits into that name, leaving
// two digits of hex code ahead of that.
//
    if (c > 0xffff && (p = wide_lookup_code(c & 0xffff)) != NULL)
    {   swprintf(output_word, 16, L"%.2x%ls", (c >> 16) & 0x3f, p);
        term_replace_chars_backwards(n, output_word);
        return;
    }
//
// Character up to u+ffff turns into hex (except that plain ASCII characters
// do not need that, and if I tried to convert them here that would conflict
// with their use in hex numeric representation.
//
    if (c > 0x7f && c <= 0xffff)
    {   swprintf(output_word, 16, L"%.4x", c);
        term_replace_chars_backwards(n, output_word);
        return;
    }
//
// The case I look at now all have 4 hex digits ahead of the insertion
// point.
//
    if (insert_point - prompt_length >= 4 &&
        iswxdigit(input_line[insert_point-4]) &&
        iswxdigit(input_line[insert_point-3]) &&
        iswxdigit(input_line[insert_point-3]) &&
        iswxdigit(input_line[insert_point-1]))
    {   c = hexval(input_line[insert_point-4]);
        c = (c << 4) | hexval(input_line[insert_point-3]);
        c = (c << 4) | hexval(input_line[insert_point-2]);
        c = (c << 4) | hexval(input_line[insert_point-1]);
//
// Now c is the integer corresponding to the 4 hex digits. If it is in the
// range 0xd800 to 0xdfff it would be a surrogate - in that case I will
// reject it. I need to see if the code has an associated name.
//
        if (c < 0 || c < 0xd800 || c > 0xdfff)
        {   if ((p = wide_lookup_code(c)) != NULL)  // yes it does!
            {
//
// Now if the buffer contains characters that would form a prefix to the
// name I just found I will convert to the hex representation of the
// character corresponding to the longer name.
// This prefix processing is rather similar to a case considered earlier.
//
                for (i=1; i+wcslen(p)<9; i++)
                {   // i is the number of prefix characters to test for
                    int c1;
                    if (insert_point - prompt_length >= i+4)
                    {   memcpy(input_word, &input_line[insert_point-i-4],
                               i*sizeof(wchar_t));
                        wcscpy(&input_word[i], p);
                        if ((c1 = lookup_wide_name(input_word)) != -1)
                        {   swprintf(output_word, 16, L"%.4x", c1);
                            term_replace_chars_backwards(i+4, output_word);
                            return;
                        }
                    }
                }
                term_replace_chars_backwards(4, p);
                return;
            }
            make_wchar(output_word, c);
            term_replace_chars_backwards(4, output_word);
            return;
        }
    }
//
// If I do not recognise any of the situations I will give an alert and
// not change the buffer at all.
//
    term_bell();
}


static void term_interrupt(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^C>");
    term_redisplay();
}


static void term_noisy_interrupt(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^G>");
    term_redisplay();
}


static void term_pause_execution(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<^Z>");
    term_redisplay();
}


static void term_exit_program(void)
{   exit(0);
}


static void term_edit_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&E>");
    term_redisplay();
}


static void term_file_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&I>");
    term_redisplay();
}


static void term_module_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&M>");
    term_redisplay();
}


static void term_font_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&O>");
    term_redisplay();
}


static void term_break_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&B>");
    term_redisplay();
}


static void term_switch_menu(void)
{
// @@@@@
    insert_point += swprintf(&input_line[insert_point],
                             input_line_size-insert_point, L"<&S>");
    term_redisplay();
}


/****************************************************************************/

#ifdef SOLARIS
//
// the tparm function on Solaris bites me, as it has bitten many people
// before. On a 64-bit machine the prototype requires a load of arguments,
// most of which will often be ignored. On a 32-bit system it can cope with
// only the args that are needed. At one time I had two calls one with
// all the extra args and one not, with "if (sizeof(void *)==8)" to select
// which to use, but a recent test has shown a compiler on Solaris treating
// the odd number of args (even in code that could never be executed) as
// an ERROR not just a WARNING. So for now I will try passing the junk
// extra args and keeping fingers crossed.
//

static void solaris_foreground(int n)
{   if (set_a_foreground)
        putp(tparm(set_a_foreground, n,0,0,0,0,0,0,0,0));
    else if (set_foreground)
        putp(tparm(set_foreground, n,0,0,0,0,0,0,0,0));
}

#endif

static void set_fg(int n)
{
#ifdef WIN32
    int k;
    if (*term_colour == 0) return;
    if (n == inputColour) k = inputAttributes;
    else if (n == promptColour) k = promptAttributes;
    else k = plainAttributes;
    fflush(stdout);
    SetConsoleTextAttribute(stdout_handle, k);
#else
    if (*term_colour == 0) return;
    fflush(stdout);
#ifdef SOLARIS
    solaris_foreground(n);
#else
    if (set_a_foreground) putp(tparm(set_a_foreground, n));
    else if (set_foreground) putp(tparm(set_foreground, n));
#endif
#endif
}

static void set_normal(void)
{
#ifdef WIN32
    fflush(stdout);
    if (*term_colour != 0)
        SetConsoleTextAttribute(stdout_handle, plainAttributes);
    SetConsoleMode(stdout_handle, stdout_attributes);
#else
    fflush(stdout);
    if (*term_colour == 0) /* nothing */;
    else if (orig_pair) putp(orig_pair);
    else if (orig_colors) putp(orig_colors);
    else if (set_a_foreground)
    {
#ifdef SOLARIS
        solaris_foreground(0);
#else
        putp(tparm(set_a_foreground, 0));
#endif
    }
    fflush(stdout);
    my_reset_shell_mode();
#endif
}

static void set_shell(void)
{
#ifdef WIN32
    fflush(stdout);
    if (*term_colour != 0)
        SetConsoleTextAttribute(stdout_handle, plainAttributes);
    SetConsoleMode(stdout_handle, stdout_attributes);
#else
    fflush(stdout);
    if (*term_colour == 0) /* nothing */;
    else if (orig_pair) putp(orig_pair);
    else if (orig_colors) putp(orig_colors);
    else if (set_a_foreground)
    {
#ifdef SOLARIS
        solaris_foreground(0);
#else
        putp(tparm(set_a_foreground, 0));
#endif
    }
    fflush(stdout);
    my_reset_shell_mode();
#endif
}

//
// Following on from selection of some history I might have accumulated a
// multi-line chunk of input here. In such a case the first line of the
// chunk will be returned by an initial call to term_wide_fancy_getline(),
// which will have displayed a prompt (and the user will have typed some keys
// that provoke history activity and then hit ENTER). When the left-over
// is to be returned the prompt must not be re-displayed...
//

static int left_over = 0;

static wchar_t *term_wide_fancy_getline(void)
{   int ch, any_keys = 0, i;
    if (left_over != 0)
    {
    }
#ifdef WIN32
    SetConsoleMode(stdout_handle, 0);
#else
    my_reset_prog_mode();
#endif
//
// I am going to take strong action to ensure that the prompt appears
// at the left-hand side of the screen.
//
    term_move_first_column();
    set_fg(promptColour);
    for (i=0; i<prompt_length; i++) term_putchar(prompt_string[i]);
    fflush(stdout);
    if (input_line_size == 0)
    {   set_normal();
        return NULL;
    }
    set_fg(inputColour);
    wcsncpy(input_line, prompt_string, prompt_length);
    wcsncpy(display_line, prompt_string, prompt_length);
    input_line[prompt_length] = 0;
    display_line[prompt_length] = 0;
    insert_point = final_cursorx = cursorx = prompt_length;
    final_cursory = max_cursory = cursory = 0;
    for (;;)
    {   int n;
        ch = term_getchar();
        if (ch == EOF || (ch == CTRL('D') && !any_keys))
        {   set_normal();
            return NULL;
        }
        any_keys = 1;
//
// First ensure there is space in the buffer. In some cases maybe putting
// the test here is marginally over-keen, since the keystroke entered
// might not be one that was going to add a character. But it is harmless
// to be safe! If I need to extend the buffer and I fail then I just
// give up and return an error marker. Note that the insert_point may not
// be at the end of the line, so I use wcslen() to find out how long the
// line actually is.
//
        n = wcslen(input_line);
//
// The curious activity here is to ensure that the buffer would not overflow
// even if the "regular" part of it was replaced by the longest line
// that can possibly get into the history-record.
//
        if (n > longest_history_line) longest_history_line = n;
        if (searchFlags != 0)
            n = n - regular_line_end + longest_history_line;
//
// Again allow extra space in case of a need to convert to utf-8.
//
        if ((n+20)*(5-sizeof(wchar_t)) >=
            input_line_size*(4/sizeof(wchar_t)))
        {   input_line = (wchar_t *)realloc(input_line, 2*input_line_size*sizeof(wchar_t));
            display_line = (wchar_t *)realloc(display_line, 2*input_line_size*sizeof(wchar_t));
            if (input_line == NULL || display_line == NULL)
            {   input_line_size = 0;
                set_normal();
                return NULL;
            }
            else input_line_size = 2*input_line_size;
        }
//
// There are cases where I need to treat characters specially:
//   (1) I am in the middle of a history search, and the
//       character is thus to be treated as part of the incremental
//       string, unless it terminates the search;
//
        if (searchFlags != 0 &&
            term_search_char(ch)) continue;
//
// term_search_char will return true if it has handled the character and thus
// searching continues. It returns false if it has exited search mode and the
// key must now be treated as if it was a "normal" non-search one.
//
#ifdef TERMED_TEST
//
//      fprintf(stderr, "process character %#x\n", ch);
//      fflush(stderr);
//
#endif
        switch (ch)
        {   case EOF:
                break;
            case CTRL('@'):
                term_set_mark();
                continue;
            case CTRL('A'):
            case ARROW_BIT + TERM_HOME:
            case ARROW_BIT + TERM_HOME + ALT_BIT:
                term_to_start();
                continue;
            case CTRL('B'):
            case ARROW_BIT+TERM_LEFT:
                term_back_char();
                continue;
            case CTRL('C'):
                term_interrupt();
                continue;
            case CTRL('D'):
            case ARROW_BIT+TERM_DELETE:
                term_delete_forwards();
                continue;
            case CTRL('E'):
            case ARROW_BIT + TERM_END:
            case ARROW_BIT + TERM_END + ALT_BIT:
                term_to_end();
                continue;
            case CTRL('F'):
            case ARROW_BIT+TERM_RIGHT:
                term_forwards_char();
                continue;
            case CTRL('G'):
                term_noisy_interrupt();
                continue;
            case CTRL('H'):
            case 0x7f:     // The "delete backwards" key, I hope
                term_delete_backwards();
                continue;
//
// I treat tab as an "ordinary" character here, so it just gets inserted
// into the input line. This is achieved by letting it hit the "default" case
// in this switch block! Ah well, soon I may be expecting to handle tab to
// provide some form of completion.
//
//  case CTRL('I'):
//          goto default;
//
            case CTRL('J'):                     // line-feed
                break;
            case CTRL('K'):
                term_kill_line();
                continue;
            case CTRL('L'):
                term_clear_screen();
                continue;
            case CTRL('M'):                     // carriage return, ENTER
                break;
            case CTRL('N'):
            case ARROW_BIT+TERM_DOWN:
                term_history_next();
                continue;
            case CTRL('O'):
                term_discard_output();
                continue;
            case CTRL('P'):
            case ARROW_BIT+TERM_UP:
                term_previous_history();
                continue;
            case CTRL('Q'):
                term_resume_output();
                continue;
            case CTRL('R'):
                term_redisplay();
                continue;
            case CTRL('S'):
                term_pause_output();
                continue;
            case CTRL('T'):
                term_transpose_chars();
                continue;
            case CTRL('U'):
                term_undo();
                continue;
            case CTRL('V'):
                term_quoted_insert();
                continue;
            case CTRL('W'):
                term_delete_word_backwards();
                continue;
            case CTRL('X'):
                term_ctrl_z_command();
                continue;
            case CTRL('Y'):
                term_yank();
                continue;
            case CTRL('Z'):
                term_pause_execution();
                continue;
//
// (already dealt with)
//  case CTRL('['):          ESC
//
            case CTRL('\\'):
                set_shell();
                term_exit_program();
            // No return
            case CTRL(']'):
                continue;        // Ignored
            case CTRL('_'):
                continue;        // Ignored
            case CTRL('^'):
                term_reinput();
                continue;
            case CTRL('@') + ALT_BIT:
                term_set_mark();
                continue;
//
// When a character is combined with ALT (or prefixed with ESC) I will in
// at least very nearly every case ignore whether it is upper or lower case
// or whether CTRL is pressed too. In a rather few cases I will let CTRL
// take precedence over ALT...
//
            case CTRL('A') + ALT_BIT: case 'A' + ALT_BIT: case 'a' + ALT_BIT:
                term_to_start();
                continue;
            case CTRL('B') + ALT_BIT: case 'B' + ALT_BIT: case 'b' + ALT_BIT:
            case ARROW_BIT + TERM_LEFT + ALT_BIT:
                term_back_word();
                continue;
            case CTRL('C') + ALT_BIT: case 'C' + ALT_BIT: case 'c' + ALT_BIT:
                term_capitalize_word();
                continue;
            case CTRL('D') + ALT_BIT: case 'D' + ALT_BIT: case 'd' + ALT_BIT:
            case ARROW_BIT + TERM_DELETE + ALT_BIT:
                term_delete_word_forwards();
                continue;
            case CTRL('E') + ALT_BIT: case 'E' + ALT_BIT: case 'e' + ALT_BIT:
                term_edit_menu();
                continue;
            case CTRL('F') + ALT_BIT: case 'F' + ALT_BIT: case 'f' + ALT_BIT:
            case ARROW_BIT + TERM_RIGHT + ALT_BIT:
                term_forwards_word();
                continue;
            case CTRL('G') + ALT_BIT: case 'G' + ALT_BIT: case 'g' + ALT_BIT:
                term_noisy_interrupt();
                continue;
            case CTRL('H') + ALT_BIT: case 'H' + ALT_BIT: case 'h' + ALT_BIT:
            case 0x7f+ALT_BIT:   // Under X maybe the key above ENTER that I use to ..
            case 0xff+ALT_BIT:   // delete things will return 0x7f.
                term_delete_word_backwards();
                continue;
            case CTRL('I') + ALT_BIT: case 'I' + ALT_BIT: case 'i' + ALT_BIT:
                term_file_menu();
                continue;
            case CTRL('J') + ALT_BIT: case 'J' + ALT_BIT: case 'j' + ALT_BIT:  // line-feed
// ALT-Enter inserts a newline without terminating the block
                break;
            case CTRL('K') + ALT_BIT: case 'K' + ALT_BIT: case 'k' + ALT_BIT:
                term_kill_line();
                continue;
            case CTRL('L') + ALT_BIT: case 'L' + ALT_BIT: case 'l' + ALT_BIT:
                term_lowercase_word();
                continue;
            case CTRL('M') + ALT_BIT:              // carriage return, ENTER
                break;
            case 'M' + ALT_BIT: case 'm' + ALT_BIT:  // ALT-^M differs from ALT-M, ALT-m
                term_module_menu();
                continue;
            case CTRL('N') + ALT_BIT: case 'N' + ALT_BIT: case 'n' + ALT_BIT:
            case ARROW_BIT + TERM_DOWN + ALT_BIT:
                term_search_next();
                continue;
            case CTRL('O') + ALT_BIT: case 'O' + ALT_BIT: case 'o' + ALT_BIT:
                term_font_menu();
                continue;
            case CTRL('P') + ALT_BIT: case 'P' + ALT_BIT: case 'p' + ALT_BIT:
            case ARROW_BIT + TERM_UP + ALT_BIT:
                term_search_previous();
                continue;
            case CTRL('Q') + ALT_BIT: case 'Q' + ALT_BIT: case 'q' + ALT_BIT:
                continue;   // Ignored
            case CTRL('R') + ALT_BIT: case 'R' + ALT_BIT: case 'r' + ALT_BIT:
                term_break_menu();
                continue;
            case CTRL('S') + ALT_BIT: case 'S' + ALT_BIT: case 's' + ALT_BIT:
                term_switch_menu();
                continue;
            case CTRL('T') + ALT_BIT: case 'T' + ALT_BIT: case 't' + ALT_BIT:
                term_transpose_chars();
                continue;
            case CTRL('U') + ALT_BIT: case 'U' + ALT_BIT: case 'u' + ALT_BIT:
                term_uppercase_word();
                continue;
            case CTRL('V') + ALT_BIT: case 'V' + ALT_BIT: case 'v' + ALT_BIT:
                term_quoted_insert();
                continue;
            case CTRL('W') + ALT_BIT: case 'W' + ALT_BIT: case 'w' + ALT_BIT:
                term_copy_region();
                continue;
            case CTRL('X') + ALT_BIT: case 'X' + ALT_BIT: case 'x' + ALT_BIT:
                term_unicode_convert();
                refresh_display();
                continue;
            case CTRL('Y') + ALT_BIT: case 'Y' + ALT_BIT: case 'y' + ALT_BIT:
                term_yank();
                continue;
            case CTRL('Z') + ALT_BIT: case 'Z' + ALT_BIT: case 'z' + ALT_BIT:
                term_pause_execution();
                continue;
//
// (already dealt with)
//  case CTRL('[') + ALT_BIT:               ESC
//
            case CTRL('\\') + ALT_BIT:
                continue;
            case CTRL(']') + ALT_BIT:
                continue;
            case CTRL('_') + ALT_BIT:
                term_copy_previous_word();
                continue;
            case '@' + ALT_BIT:
                term_set_mark();
                continue;
            case '[' + ALT_BIT:   // ESC-[
                // Should never be delivered here
                continue;
            case '\\' + ALT_BIT:
                term_exit_program();
            // no return
            case ']' + ALT_BIT:
                continue;
            case '_' + ALT_BIT:
                term_copy_previous_word();
                continue;
            case '{' + ALT_BIT:
                continue;  // Ignored
            case '^' + ALT_BIT:
                term_reinput();
                continue;
            case '}' + ALT_BIT:
                continue;  // Ignored
            default:
//
// Here I need to insert a character into the buffer. I may not be inserting
// at the end, so I perhaps have to shuffle existing stuff upwards.
//
            {   int n = insert_point;
                while (input_line[n] != 0) n++;
                while (n >= insert_point)
                {   input_line[n+1] = input_line[n];
                    n--;
                }
            }
            input_line[insert_point] = ch & (~(ALT_BIT|ARROW_BIT));
            insert_point++;
            refresh_display();
            continue;
        }
        break;
    }
//
// Put the cursor at the start of the final line of displayed (wrapped)
// input before moving back to normal screen mode.
//
    term_move_first_column();
    term_move_down(final_cursory-cursory);
    set_normal();
    term_putchar('\n');
    fflush(stdout);
    insert_point = wcslen(input_line);
    if (insert_point==prompt_length && ch==EOF) return NULL;
//
// Stick the line into my history record: WITHOUT any newline at its end.
//
    input_line[insert_point] = 0;
    input_history_stage(input_line+prompt_length);
//
// Whether the user terminated the line with CR or LF I will always
// return "\n" to the program.
//
    input_line[insert_point++] = L'\n';
    input_line[insert_point] = 0;
    return input_line + prompt_length;
}

#endif // DISABLE

//
// Encode into buffer b as up to 4 characters (plus a nul). Because I
// am only concerned with Unicode I only need encode values in the
// range 0 to 0x10ffff. Returns the number of chars packed (not counting
// the terminating '\0').
//

int utf_encode(unsigned char *b, int c)
{   unsigned char *p = b;
    c &= 0x1fffff;   // limit myself to 21-bit values here
    if (c <= 0x7f) *p++ = c;
    else if (c <= 0x7ff)
    {   *p++ = 0xc0 | (c >> 6);
        *p++ = 0x80 | (c & 0x3f);
    }
    else if (c <= 0xffff)
    {   *p++ = 0xe0 | (c >> 12);
        *p++ = 0x80 | ((c >> 6) & 0x3f);
        *p++ = 0x80 | (c & 0x3f);
    }
    else
    {   *p++ = 0xf0 | (c >> 18);
        *p++ = 0x80 | ((c >> 12) & 0x3f);
        *p++ = 0x80 | ((c >> 6) & 0x3f);
        *p++ = 0x80 | (c & 0x3f);
    }
    *p = 0;
    return (int)(p - b);
}

//
// Decode utf-8 or return -1 if invalid.
//

int utf_bytes = 0;

int utf_decode(const unsigned char *b)
{   int c = *b++, c1, c2, c3;
    utf_bytes = 1;
    switch (c & 0xf0)
    {
//
//  case 0x00:
//  case 0x10:
//  case 0x20:
//  case 0x30:
//  case 0x40:
//  case 0x50:
//  case 0x60:
//  case 0x70:
//
        default:
            return c;
        case 0x80:
        case 0x90:
        case 0xa0:
        case 0xb0:
            return -1;  // out of place continuation marker
        case 0xc0:
        case 0xd0:
            c1 = *b;
            if ((c1 & 0xc0) != 0x80) return -1; // not continuation
            utf_bytes += 1;
            return ((c & 0x1f) << 6) | (c1 & 0x3f);
        case 0xe0:
            c1 = *b++;
            if ((c1 & 0xc0) != 0x80) return -1; // not continuation
            c2 = *b;
            if ((c2 & 0xc0) != 0x80) return -1; // not continuation
            utf_bytes += 2;
            return ((c & 0x0f) << 12) | ((c1 & 0x3f) << 6) | (c2 & 0x3f);
        case 0xf0:
            if ((c & 0x08) != 0) return -1;
            c1 = *b++;
            if ((c1 & 0xc0) != 0x80) return -1; // not continuation
            c2 = *b++;
            if ((c2 & 0xc0) != 0x80) return -1; // not continuation
            c3 = *b;
            if ((c3 & 0xc0) != 0x80) return -1; // not continuation
            utf_bytes += 3;
            return ((c & 0x07) << 18) | ((c1 & 0x3f) << 12) |
                   ((c2 & 0x3f) << 6) | (c3 & 0x3f);
    }
}

wchar_t *term_wide_getline(void)
{   if (!term_enabled) return term_wide_plain_getline();
    else return term_wide_fancy_getline();
}

char *term_getline(void)
{   wchar_t *r = term_wide_getline();
    if (r == NULL) return NULL;
//
// To get a "narrow char" line I read a wide char line and then expand
// it into utf-8 form.
//
    char *p = (char *)r;
    wchar_t *q = r;
    int c;
    unsigned char buffer[8];
    if (sizeof(wchar_t)==4)
    {   while ((c = *q++) != 0)
        {   int n = utf_encode(buffer, c), i;
            for (i=0; i<n; i++) *p++ = buffer[i];
        }
    }
    else
    {
//
// Expanding a code such as 0x1111 unto utf-8 will expand it from a 2-byte
// wchar_t to 3 bytes. This risks clobbering the input data. To avoid that
// I will move the raw input data up the buffer first.
//
        size_t n = wcslen(r);
        wchar_t *s = r + n;  // end of original data
        q = s + (n/2) + 2;   // safe place for end of copied version
        for (;;)
        {   *q = *s;
            if (s == r) break; // will leave q pointing at the copy
            s--;
            q--;
        }
        while ((c = *q++) != 0)
        {   int i, n;
//
// I assume that surrogate pairs are indeed properly paired: I consolidate
// them into single characters here.
//
            if (is_low_surrogate(c))
                c = 0x10000 + ((c & 0x3ff)<<10) + (*q++ & 0x3ff);
            n = utf_encode(buffer, c);
            for (i=0; i<n; i++) *p++ = buffer[i];
        }
    }
    *p = 0;
    return (char *)r;
}

#ifdef RECORD_KEYS
//
// This abomination is here to permit me to collect the key-sequences
// that a whole bunch of things generate for me. I do not guarantee that
// it will always work, but when it does it may be useful!
//

static void record_keys(void)
{   static char *keys[] =
    {   "left arrow",
        "right arrow",
        "up arrow",
        "down arrow",
        "delete",
        "backspace-style delete key",
        "home",
        "end",
        "insert",
        "enter",
        "ALT-left arrow",
        "ALT-right arrow",
        "ALT-up arrow",
        "ALT-down arrow",
        "ALT-delete",
        "ALT-backspace-style delete key",
        "ALT-home",
        "ALT-end",
        "ALT-insert",
        "ALT-enter",
        "Ctrl-left arrow",
        "Ctrl-right arrow",
        "Ctrl-up arrow",
        "Ctrl-down arrow",
        "Ctrl-delete",
        "Ctrl-backspace-style delete key",
        "Ctrl-home",
        "Ctrl-end",
        "Ctrl-insert",
        "Ctrl-enter",
        NULL
    };
    char **p = keys;
    printf("\r\nFor each key listed here press the key and then an \"x\"\r\n");
    while (*p != NULL)
    {   int ch;
        printf("%s: ", *p++);
        fflush(stdout);
        while ((ch = getchar()) != 'x')
        {   if (ch < 0x20) printf("^%c ", ch | 0x40);
            else if (0x20 < ch && ch < 0x7f) printf("%c ", ch);
            else printf("[%x] ", ch);
        }
        printf("\r\n");
    }
    printf("Thank you\r\n");
}

int main(int argc, char *argv[])
{   term_setup(1, NULL);
//    def_prog_mode();
    record_keys();
//    reset_shell_mode();
    term_close();
    return 0;
}

#endif

// end of file termed.cpp
