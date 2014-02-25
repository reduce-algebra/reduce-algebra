/* termed.c                          Copyright (C) 2004-2014 Codemist Ltd */

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

/*
 * Note that the above apply even when part of this code is used within
 * an LGPL library such as FOX, even though binaries built from the
 * complete work are subject to the LGPL.
 */

/* $Id$ */

/*
 * This supports modest line-editing and history for terminal-mode
 * use of "fwin" applications.
 *
 * Major amounts of mess here are to try to keep things supported in both
 * a Windows and a Unix-like world. For Windows I use the Console API to
 * get direct contol of a screen. For Unix-like systems I demand that
 * a "curses" package be available. But rather than using the high-level
 * parts of "curses" I only use the low level functions - that is because the
 * high level ones are generlly based on needing to clear the screen at
 * that start and I do not want that. Also my cursor activity is really pretty
 * simple and clever optimisation for it seems unnecessary.
 */


/*
 * I need to think properly about characters outside the simple ASCII
 * character set. There are (at least) four places where there is
 * a chance for representations to apply:
 * (1) When communicating with lower level code to read characters.
 *     The Windows API that I use can return either an ASCII or a
 *     Unicode representation of whatever character it reads, and
 *     whatever else it hands back each keystroke that denotes a
 *     characters as a single entity. Linux (and cygwin) seems to pass
 *     back characters in Unicode encoded using UTF8, so that simple
 *     ASCII characters with codes in the range 0x00 to 0x7f come back as
 *     just one octet, but other characters are handed to me as a
 *     sequence of octets.
 * (2) When buffering material here (eg in the history record) I will
 *     want to have some representation that will support recording and
 *     searching. The partially complete input-line will need to
 *     be stored so that I can perform local editing, and that will mean
 *     I need to be able to check if characters in it are letters etc,
 *     and I will need to be able to move backwards and forwards in the
 *     buffer. Having one storage unit per character will probably make the
 *     input line buffer easier to cope with.
 * (3) Communication with the application that uses this interface (ie
 *     CSL and Reduce!). This will be via the call "term_getline" which
 *     returns a buffer full of characters. Existing code in CSL expects this
 *     to be a buffer filled with 8-bit bytes of ASCII, so in the short
 *     term at least that must be maintained. I think that there are two
 *     plausible ways to go in the short term. One is to pack that buffer
 *     using UTF8 and then all possible input characters can be handled, but
 *     CSL will have trouble with ones whos ecode is 0x80 or higher. The
 *     other is to return a truncated 8-bit Unicode value (and possibly to
 *     map all Unicode chars from 0x100 upwards onto say "?"). I will
 *     also want to provide a "term_wgetline" to get a line of wide characters
 *     for a future when or if the application code can cope with that.
 * (4) Displaying characters on the terminal, both as genuine output from
 *     (console-mode) CSL/Reduce and during line-editing. It seems that
 *     under Windows I may need to use WriteConsoleW to write Unicode stuff
 *     to the console. With Linux etc I will need to use UTF8.
 *
 * Throughout this there is an extra layer of murk that Windows uses UTF16
 * and codes in the range d800 to dbff and dc00 to dfff are used when a code
 * over ffff, with the high 10 bits in the d8xx surrogate coming first and
 * then the low 10 in the dcxx unit. Code values that are in the surrogate
 * range are not valid on their own. An effect of that is that on Windows
 * the type wchar_t can not store all possible characters, so I need to
 * decide if that worries me and if so what I can do. For now my plan is
 * to use wchar_t here to hold characters and in the Windows case to treat
 * all surrogates (and hence all codepoints over ffff that they might denote)
 * as invalid.
 *
 */

/*
 * The next few #define statements are a clear indication of just how
 * unpleasantly system-dependent this code has become. Eg _DARWIN_C_SOURCE
 * must be defined ona Mac so that cfmakeraw gets properly defined by
 * termios.h and _XOPEN_SOURCE and _BSD_SOURCE are similarly needed on Linux
 * and/or Cygwin to allow access to low level terminal handling functions.
 */
#define _XOPEN_SOURCE 500
#define _BSD_SOURCE 1
#define _DARWIN_C_SOURCE 1

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32

#include <windows.h>

#else /* WIN32 */

#ifdef HAVE_NCURSES_H
#include <ncurses.h>
#else
#ifdef HAVE_CURSES_H
#include <curses.h>
#else
#define DISABLE 1
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
#endif
#endif
#endif

#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif


#endif /* WIN32 */

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

/*
 * These are colors used when in curses/term/termcap mode
 */

static const char *term_colour;

/*
 * The following are the colour codes supported by curses/term.
 *
 *   0  black     B, K, k
 *   1  red       R, r
 *   2  green     G, g
 *   3  yellow    Y, y
 *   4  blue      b         n.b. only lower case here!
 *   5  magenta   M, m
 *   6  cyan      C, c
 *   7  white     W, w
 */

#ifndef WIN32

static int map_colour(int ch)
{
    switch (ch)
    {
case 'k': case 'K':
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

#endif /* WIN32 */

/*
 * The default values set here can be changed as a result of the colour
 * option passed to term_setup.
 */
static int promptColour = 4;   /* Blue */
static int inputColour  = 1;   /* Red */
#ifndef WIN32
static int outputColour = -1;  /* whatever user had been using */
#endif /* WIN32 */

#ifndef DEBUG

#define LOG(...)

#else

#include <stdarg.h>

static FILE *termed_logfile = NULL;

static void write_log(char *s, ...)
{
    va_list x;
    if (termed_logfile == NULL) termed_logfile = fopen("termed.log", "w");
    va_start(x, s);
    vfprintf(termed_logfile, s, x);
    va_end(x);
}

#define LOG(...) \
    do { write_log("%d: ", __LINE__); write_log(__VA_ARGS__); } while (0)

#endif


/*
 * My support for a history mechanism here is really primitive and simple.
 * I have a fixed size history buffer and just dump strings into it.
 */

wchar_t *input_history[INPUT_HISTORY_SIZE];
int input_history_next = 0,
    input_history_current = 0,
    longest_history_line = 0;


void input_history_init(void)
{
    int i;
    input_history_next = longest_history_line = 0;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
        input_history[i] = NULL;
}

void input_history_end(void)
{
    int i;
    for (i=0; i<INPUT_HISTORY_SIZE; i++)
    {   if (input_history[i] != NULL) free(input_history[i]);
    }
}

void input_history_add(const wchar_t *s)
{
/* Make a copy of the input string... */
    wchar_t *scopy = (wchar_t *)malloc((wcslen(s) + 1)*sizeof(wchar_t));
    int p = input_history_next % INPUT_HISTORY_SIZE;
/* If malloc returns NULL I just store an empty history entry. */
    if (scopy != NULL) wcscpy(scopy, s);
    LOG("History entry has %d characters in it\n", wcslen(s));
/*
 * I can overwrite an old history item here... I will keep INPUT_HISTORY_SIZE
 * entries.
 */
    if (input_history[p] != NULL) free(input_history[p]);
    input_history[p] = scopy;
    input_history_next++;
    if (scopy != NULL)
    {   p = wcslen(scopy);
        if (p > longest_history_line) longest_history_line = p;
    }
}

const wchar_t *input_history_get(int n)
{
    const wchar_t *s;
/*
 * Filter our values that are out of range and in those cases return NULL
 * as a flag to report the error.
 */
    if (n == input_history_next) return L"";
    if (n < 0 ||
        n >= input_history_next ||
        n < input_history_next-INPUT_HISTORY_SIZE) return NULL;
    s = input_history[n % INPUT_HISTORY_SIZE];
/* The NULL here would be if malloc had failed earlier. */
    if (s == NULL) return L"";
    else return s;
}

/*
 * Sort of beware! I have fields in the class FXTerminal with the same
 * names as these (static) variables and serving the same purpose (but for
 * windowed applications). Do not get confused please. The two sets of
 * values should never be active at the same time. If I were cleverer I
 * would have found a good way to share more of the code and avoid
 * this potential muddle.
 */
static int historyFirst, historyNumber, historyLast;
static int searchFlags; 


#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 80
#endif

static wchar_t prompt_string[MAX_PROMPT_LENGTH+1] = L">";

wchar_t *input_line;
static wchar_t *display_line;
int prompt_length = 1, prompt_width = 1;
static int input_line_size;

/*
 * term_wide_plain_getline() can be called when cursor addressing is not
 * available. It just reads characters into a line-buffer (which it
 * extends as necessary). The data returned includes the newline
 * that terminated the line. If an error is detected (and in particular
 * at end of file) the value NULL is returned rather than a pointer to
 * an array of characters.
 *
 * Nothing at all is done here to fuss about special characters, so
 * things like ^C, backspace, ^Q etc etc etc are handled, if at all, by
 * the system that underpins "getchar".
 *
 * Note that even though I work internally with wide chars this will
 * return something where all the characters are limited to 8 bits. These
 * will be the 8 low bits of the Unicode representation of what was read,
 * with invalid inputs mapped onto "?". Well at least that will be what
 * happens when I can achieve it, and it will assume that input can
 * be read using getwchar().
 */

static void term_putchar(int c);

static wchar_t *term_wide_plain_getline(void)
{
    wint_t n, ch;
    int i;
#ifdef TEST
    fprintf(stderr, "plain_getline:");
    fflush(stderr);
#endif
    for (i=0; i<prompt_length; i++) term_putchar(prompt_string[i]);
    fflush(stdout);
    if (input_line_size == 0) return NULL;
    input_line[0] = 0;
    for (n=0, ch=getwchar(); ch!=WEOF && ch!=L'\n'; n++, ch=getwchar())
    {   if (n >= input_line_size-20)
        {  input_line =
             (wchar_t *)realloc(input_line, 2*input_line_size*sizeof(wchar_t));
           if (input_line == NULL)
           {   input_line_size = 0;
               return NULL;
           }
           else input_line_size = 2*input_line_size;
        }
        input_line[n] = ch;
        input_line[n+1] = 0;
    }
    if (n==0 && ch==WEOF) return NULL;
    input_line[n++] = ch;
    input_line[n] = 0;
    return input_line;
}

/*
 * Before calling term_getline() or its variants use this to set the
 * prompt string that will be displayed.
 * A prompt string longer than the width of the terminal is liable to lead
 * to bad confusion, and anyway prompts as passed are truncated. The
 * character set used with this is 8-bit Unicode... but the stored prompt
 * is in a wide string.
 */

void term_setprompt(const char *s)
{
    int i;
    prompt_length = prompt_width = strlen(s);
    LOG("prompt = %s len %d\n", s, prompt_length);
/*
 * I truncate prompts if they are really ridiculous in length since otherwise
 * it may look silly.
 */
    if (prompt_length > MAX_PROMPT_LENGTH) prompt_length = MAX_PROMPT_LENGTH;
/*
 * Here I winden the characters in the prompt by merely using the passsed
 * characters as the low 8-bits of each desired character. That is fine
 * for 7-bit ASCII characters but not if the 8-bit values depend on some
 * particular code page...
 */
    for (i=0; i<prompt_length; i++)
    {   wint_t c = *s++ & 0xff;
        prompt_string[i] = c;
    }
    prompt_string[i] = 0;
}

/*
 * Now a version that takes a wide string so that it is possible to
 * set prompts that include characters with codes over 0xff, and at least
 * up to 0xffff. On Windows there is a special nuisance if the truncation
 * at MAX_PROMPT_LENGTH tries to truncate half way through a surrogate
 * pair. In that case I will truncate one code earlier.
 */

void term_wide_setprompt(const wchar_t *s)
{
    prompt_length = wcslen(s);
    if (prompt_length > MAX_PROMPT_LENGTH) prompt_length = MAX_PROMPT_LENGTH;
    if ((s[prompt_length] & 0x1ffc00) == 0xdc00) prompt_length--;
    wcsncpy(prompt_string, s, prompt_length);
    prompt_string[prompt_length] = 0;
/*
 * Now in the face of possible surrogate pairs the width in columns of the
 * prompt may not be the same as the number of wchar_t items that make it
 * up, so I will note here the calculation needed to sort that out...
 */
    prompt_width = 0;
    for (s=prompt_string; *s!=0; s++)
        if ((*s & 0x1ffc00) != 0xdc00) prompt_width++;
}

#ifdef DISABLE
/*
 * In some cases this code can not be activated because not enough
 * libraries are available. In that case I will provide stubs that do
 * non-clever input. It may be that an external package or body of code
 * will still be providing a good environment for the user.
 */

/*
 * Start up input through this package. Returns 1 in this case because
 * local editing is not supported on this platform. Hence the colour
 * option is ignored.
 */

int term_setup(int flag, const char *colour)
{
#ifdef TEST
    fprintf(stderr,
        "term_setup in the DISABLE (no cursor addressability) case\n");
#endif
    input_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    if (input_line == NULL) input_line_size = 0;
    else input_line_size = 200;
    return 1;
}

/*
 * Before returning from your code it would be a really good idea to
 * call "term_close" since that can re-set all sorts of terminal
 * characteristics. In some cases use of "atexit" to ensure this will
 * make sense.
 */
void term_close(void)
{
    if (input_line != NULL)
    {   free(input_line);
        input_line = NULL;
    }
}

static const int term_enabled = 0;

static wchar_t *term_wide_fancy_getline(void)
{
    return NULL; /* Should never be called */
}

#else /* DISABLE */

#ifndef WIN32

static int stdin_handle, stdout_handle;

#endif

#ifdef SIMULATE_TERM_H
/*
 * if "term.h" is not available but the tgetent() function is then I will
 * provide my own private term.h simulation here - just including the small
 * number of features that I actually use.
 */

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
{
    char *tt = getenv("TERM");
    char *p = my_entries;
    columns = 80;
    lines = 25;
/*
 * Just to feel tidy I will explicitly set all these to NULL as
 * I start up.
 */
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
/*
 * Here I will rely on being able to output a single octet without that
 * messing up any UTF8ness etc.
 */
    putchar(c);
}

static void putp(char *s)
{
    tputs(s, 1, putpc);
}


#endif

#ifndef WIN32

static struct termios shell_term, prog_term, shell_term_o, prog_term_o;

static void my_def_shell_mode(void)
{
    fflush(stdout);
    tcgetattr(stdin_handle, &shell_term);
    tcgetattr(stdout_handle, &shell_term_o);
}

static void my_reset_shell_mode(void)
{
    fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &shell_term);
    tcsetattr(stdout_handle, TCSADRAIN, &shell_term_o);
    fflush(stdout);
}

static void my_def_prog_mode(void)
{
    fflush(stdout);
    tcgetattr(stdin_handle, &prog_term);
    tcgetattr(stdout_handle, &prog_term_o);
}

static void my_reset_prog_mode(void)
{
    fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &prog_term);
    tcsetattr(stdout_handle, TCSADRAIN, &prog_term_o);
}

#endif

/*
 * In case the system did not provide this I will supply the ANSI
 * escape code and I will use that regardless...
 */
#ifndef set_a_foreground
#define set_a_foreground "\e[3%dm"
#endif

#ifndef set_foreground
#define set_foreground NULL
#endif

/*
 * When the code is built it can still determine (dynamically) that it
 * should not intervene, Eg when stdin/stdout have been redirected. When
 * it is not enabled it can do simple getchar/putchar IO.
 */

static int term_enabled = 0;

static int cursorx, cursory, final_cursorx, final_cursory, max_cursory;
int insert_point;

static int term_can_invert, invert_start, invert_end;

#ifdef WIN32
/*
 * The term/termios model provides "lines" and "columns" as macros.
 * For Windows I manage them myself. By and large I will just not worry
 * about "lines". The only case it ought to matter to me is if a user
 * tries to enter a line of input that is so long that when wrapped
 * it uses more lines of the screen than there are.
 *
 * To start with I will leave the behaviour in this case as a bug in my
 * code. If I get keen I will revisit the situation later on.
 */
static int lines, columns;

static HANDLE stdin_handle, stdout_handle;

static WORD plainAttributes, revAttributes, promptAttributes, inputAttributes;
static DWORD stdin_attributes, stdout_attributes;

#endif

extern int utf_encode(unsigned char *b, int c);

static void term_putchar(int c)
{
/*
 * The character passed here will actually be an wchar_t and probably if I
 * was being truly proper the argument type would need to be wint_t not int.
 * However I am going to be sloppy and assume that int is good enough.
 */
#ifdef WIN32
    DWORD nwritten = 1;
    wchar_t buffer[4];
    buffer[0] = c;
    WriteConsole(stdout_handle, buffer, 1, &nwritten, NULL);
#else
/*
 * Other than on Windows I will encode things using UTF-8
 */
    unsigned char buffer[8];
    int i, n = utf_encode(buffer, c);
    for (i=0; i<n; i++) putchar(buffer[i]);
#endif
}

/*
 * If possible I would like to be able to retrieve the actual size of
 * the current screen, rather than relying on shell variables, like COLUMNS,
 * that could possibly get out of step with reality.
 */

static void measure_screen(void)
{
/*
 * I try to measure the size of the current window or terminal.
 * on some systems I may not be able to!
 */
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
#endif /* TIOCGSIZE */
#endif /* TIOCGWINSZ */
#endif /* HAVE_SYS_IOCTL_H */
#endif /* WIN32 */
/*
 *  LOG("[screen:%dx%d]\n", columns, lines);
 */
}

#ifdef WIN32
static INPUT_RECORD keyboard_buffer[1];

static UINT originalCodePage = 0;

static void resetCP()
{
    SetConsoleOutputCP(originalCodePage);
}

#endif

int term_setup(int flag, const char *colour)
{
#ifdef WIN32
    DWORD w;
    CONSOLE_SCREEN_BUFFER_INFO csb;
#ifdef TEST
    fprintf(stderr, "term_setup in the WIN32 case\n");
#endif
/*
 * It is VITAL to use "w+" as the access mode here for otherwise
 * it is not possible to access the Console Output Buffer sufficiently.
 */
    freopen("CONOUT$", "w+", stdout);
    term_enabled = 0;
    keyboard_buffer[0].Event.KeyEvent.wRepeatCount = 0;
    term_colour = (colour == NULL ? "-" : colour);
    input_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    display_line = (wchar_t *)malloc(200*sizeof(wchar_t));
    if (input_line == NULL || display_line == NULL)
    {   input_line_size = 0;
#ifdef TEST
        fprintf(stderr, "unable to allocate buffers\n");
#endif
        return 1;
    }
    else input_line_size = 200;
    if (!flag)
    {
#ifdef TEST
        fprintf(stderr, "user asked for no local editing\n");
#endif
        return 1;
    }
/*
 * Standard input must be from a character device and must be accepted
 * by the GetConsoleMode function
 */
    stdin_handle = GetStdHandle(STD_INPUT_HANDLE);
    if (GetFileType(stdin_handle) != FILE_TYPE_CHAR)
    {
#ifdef TEST
        fprintf(stderr, "stdin not CHAR type\n");
#endif
        return 1;
    }
    if (!GetConsoleMode(stdin_handle, &w))
    {
#ifdef TEST
        fprintf(stderr, "could not get stdin console mode \n");
#endif
        return 1;
    }
/*
 * Standard output must be a character device and a ConsoleScreenBuffer
 */
    stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#ifdef TEST
    fprintf(stderr, "stdin handle = %p, stdout handle = %p\n", stdin_handle, stdout_handle);
#endif
    if (GetFileType(stdout_handle) != FILE_TYPE_CHAR)
    {
#ifdef TEST
        fprintf(stderr, "stdout not CHAR type\n");
#endif
        return 1;
    }
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb))
    {
#ifdef TEST
/*
 * This was here stdout_handled needed READ access as well as WRITE access.
 * All the extra printing was useful while I was tracking that problem down!
 */
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
#ifdef TEST
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
#ifdef TEST
        fprintf(stderr, "trouble setting stdout attributes\n");
#endif
        return 1;
    }
    if (!SetConsoleMode(stdin_handle,
        ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
    {
#ifdef TEST
        fprintf(stderr, "trouble setting stdin attributes\n");
#endif
        return 1;
    }
    columns = csb.srWindow.Right - csb.srWindow.Left + 1;
    lines = csb.srWindow.Bottom - csb.srWindow.Top + 1;
    SetConsoleMode(stdout_handle, stdout_attributes);
    term_can_invert = 1;
/*
 * If I am using the Unicode functions to write to the console then
 * the issue of a code page for it becomes somewhat irrelevant!
 */
    originalCodePage = GetConsoleOutputCP();
    atexit(resetCP);
    SetConsoleOutputCP(CP_UTF8);
#ifdef TEST
    printf("Original page = %d.  \xc3\xbc\n", originalCodePage);
#endif
#else /* WIN32 */
    int errval, errcode;
    char *s;
    struct termios my_term;
#ifdef TEST
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
/*
 * Check for redirected stdin/stdout.
 */
    if (!isatty(stdin_handle) || !isatty(stdout_handle)) return 1;
/*
 * Next check if the terminal is one that we know about...
 */
    s = getenv("TERM");
    if (s == NULL) s = "dumb";
    errcode = setupterm(s,               /* terminal type */
                        stdout_handle,   /* ie to stdout */
                        &errval);
    if (errcode != OK || errval != 1) return 1;

/*
 * I really want the very basic units of cursor movement to be available,
 * and if they are not I will just give up.
 */
    if (cursor_up == NULL ||
        cursor_down == NULL ||
        cursor_left == NULL ||
        cursor_right == NULL ||
        carriage_return == NULL) return 1;
    if (enter_reverse_mode != NULL &&
        exit_attribute_mode != NULL) term_can_invert = 1;
    else term_can_invert = 0;
/*
 * def_shell_mode() remembers the configuration of my terminal in the
 * state before I alter any parameters. It saves information so that
 * reset_shell_mode() can put things back the way they were. However
 * with (at least) Ubuntu 9.10 these functions fail for me. Perhaps because
 * they want me to be using a full "curses" window, not merely low-level
 * access. So I provide my own versions with prefix "my_".
 */
    my_def_shell_mode();
/*
 * I guess I am going to suppose here that stdin and stdout are both
 * associated with the SAME terminal. If the computer had two (or more)
 * terminals and stdin/stdout were attached to different ones then
 * the use of tcgetattr/tcsetattr would only do things to the stdin
 * one here.
 */
    tcgetattr(stdin_handle, &my_term);
#ifdef HAVE_CFMAKERAW
/*
 * If I have cfmakeraw that is liable to be a definitive way of setting
 * raw mode. Otherwise I will set the flags that I expect cfmakeraw to set.
 * The one that it took be a while to spot was c_cc[VMIN] to ensure that
 * reading characters still waits for at least one...
 */
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
    tcsetattr(stdin_handle, TCSADRAIN, &my_term);
    my_def_prog_mode();
    my_reset_shell_mode();
#endif /* WIN32 */
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
/*
 * Note here and elsewhere in this file that I go "fflush(stdout)" before
 * doing anything that may change styles or options for stream handling.
 */
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

/*
 * term_getchar() will block until the user has typed something. I will use
 * this place as where I unravel various funny escape sequences that
 * stand for uses of control keys. For all cases I will hand back a
 * "basic character", but I will then OR in bits if ALT was pressed with it
 * and others if it is not a simple key but a value returned to indicate a
 * function key, arrow key etc etc. Regardless of the meaning of bits
 * ORd in I will hand back EOF in some boundary cases. When using a Unix-
 * style terminal (rather than Windows) I will just ignore invalid or
 * unrecognized escape systems sent by the lower level terminal drivers.
 */

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
/*
 * I need to bother myself with repeat-counts. So in general there
 * has been a call to inspect the keyboard before. If, after processing that
 * I has a keyboard event with a residual repeat-count left over I will
 * just have to handle that. Otherwise I need to call ReadConsoleInput to
 * get some more. If that call fails I will return EOF as an error indication.
 */
        if ((keyboard_buffer[0].EventType != KEY_EVENT ||
             keyboard_buffer[0].Event.KeyEvent.wRepeatCount == 0) &&
            !ReadConsoleInput(stdin_handle, keyboard_buffer, 1, &n))
        {   return EOF;
        }
/*
 * By the time I get here keyboard_buffer will hold an event. It might be
 * one of a range of sorts! At present I only do anything at all with KEY
 * events, but I could potentially look for mouse activity.
 */
        switch (keyboard_buffer[0].EventType)
        {
    default:              /* Ignore non-keyboard event */
            continue;
    case KEY_EVENT:
    	    keyboard_buffer[0].Event.KeyEvent.wRepeatCount--;
    	    down = keyboard_buffer[0].Event.KeyEvent.bKeyDown;
            if (!down) continue; /* discard KEY-UP events */
    	    key = keyboard_buffer[0].Event.KeyEvent.wVirtualKeyCode;
    	    ascii = keyboard_buffer[0].Event.KeyEvent.uChar.AsciiChar;
            unicode = keyboard_buffer[0].Event.KeyEvent.uChar.UnicodeChar;
    	    ctrl = keyboard_buffer[0].Event.KeyEvent.dwControlKeyState;
/*
 * If Windows thinks that the key that has been hit corresponded to an
 * ordinary character than I will just return it. No hassle here! Well
 * not quite so easy after all. If ALT is held down at the same time as
 * the character I will or in the ALT_BIT bit.
 *
 * Ha Ha! "unicode==0" would apply in the case of "^@". By experiment the
 * notionally system independent key-code for "@" is 0xc0 (well I can worry
 * in case that is really for "'") do I test for that. Anyway at least
 * with my keyboard this lets "^@" get through!
 */
            if (key != 0x11) LOG("\nunicode=%x VK=%x ctrl=%x\n", unicode, key, ctrl);
            if (unicode != 0 || key == 0xc0)
            {   if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED))
                    unicode |= ALT_BIT;
                return unicode;
            }
/*
 * Now use the variable "unicode" to record the state of the ALT key.
 */
            if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED)) unicode = ALT_BIT;
            else unicode = 0;
/*
 * I map the Microsoft Key-Codes onto codes of my own. Observe that I do not
 * support anything like all of the possible keys here, and that I do not
 * detect SHIFT or CONTROL pressed in association with a function key. I will
 * extend the tables here later if I feel moved to, but getting compatibility
 * with the Unix-like case means I am unlikely to want to support every
 * possible feature.
 */
            switch (key) 
            {
    default:    continue;     /* Ignore unknown keys */
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
/*
 * In the Unix-like case I run a state-machine to grab sequences of
 * characters by way of escape codes. One consequence of this is that
 * a single ESC character is generally not passed through to the user.
 * So far as I can discover at present I can not guarantee to detect
 * "^@" here even though I am in raw mode. I fear that to handle that I
 * may need yet lower levels of protocol...
 */
#define BASE_STATE   0
#define ESC_STATE    1
#define ESC_BR_STATE 2

/*
 * What I should almost certainly be doing here involves the following
 * variables that I have either set up for myself or that setupterm()
 * established for me.
 *
 *  key_up = tgetstr("ku", &p);
 *  key_down = tgetstr("kd", &p);
 *  key_left = tgetstr("kl", &p);
 *  key_right = tgetstr("kr", &p);
 *  key_dc = tgetstr("kD", &p);
 *  key_home = tgetstr("kh", &p);
 *  key_end = tgetstr("@7", &p);
 *
 * So rather than trying to have a general state machine to parse things
 * perhaps I could just check against the above strings (when they are
 * non-NULL).
 * HOWEVER when I look at the results from the above I find that in
 * too many cases my HOME and END keys are not reported back to me, so I will
 * go with ad-hoc decoding.
 *
 *    BASE --esc--> ESC --[--> ESC_BR --0/9--> DIG --other--> done
 *                   |                          |
 *              second ESC counted         digits and ";" absorbed
 */


    int state = BASE_STATE, esc_esc = 0, ch, numval1=0, numval2=0;
    for (;;)
    {   int c1, c2, c3;
        ch = getchar();
        if (ch == EOF) return EOF;
        ch &= 0xff;
/*
 * Here I will swallow extra octets if the leading one seems to introduce
 * an UTF multi-octet sequence 
 */
        switch (ch & 0xf0)
        {
/*
 *  case 0x00:
 *  case 0x10:
 *  case 0x20:
 *  case 0x30:
 *  case 0x40:
 *  case 0x50:
 *  case 0x60:
 *  case 0x70:
 */
    default:
            break;
    case 0x80:
    case 0x90:
    case 0xa0:
    case 0xb0:
/* I map invalid UTF8 sequences onto question marks */
            ch = L'?';
            break;  /* out of place continuation marker */
    case 0xc0:
    case 0xd0:
            c1 = getchar();
            if (c1 == EOF) return EOF;
            c1 &= 0xff;
            if ((c1 & 0xc0) != 0x80)
            {   ch = L'?';
                break; /* not continuation */
            }
            ch = ((ch & 0x1f) << 6) | (c1 & 0x3f);
            break;
    case 0xe0:
            c1 = getchar();
            if (c1 == EOF) return EOF;
            c1 &= 0xff;
            if ((c1 & 0xc0) != 0x80)
            {   ch = L'?'; /* not continuation */
                break;
            }
            c2 = getchar();
            if (c2 == EOF) return EOF;
            c1 &= 0xff;
            if ((c2 & 0xc0) != 0x80)
            {   ch = L'?'; /* not continuation */
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
            } /* not continuation */
            c2 = getchar();
            if (c2 == EOF) return EOF;
            c2 &= 0xff;
            if ((c2 & 0xc0) != 0x80)
            {   ch = L'?';
                break;
            } /* not continuation */
            c3 = getchar();
            if (c3 == EOF) return EOF;
            c3 &= 0xff;
            if ((c3 & 0xc0) != 0x80)
            {   ch = L'?';
                break;
            } /* not continuation */
            ch = ((ch & 0x07) << 18) | ((c1 & 0x3f) << 12) |
                  ((c2 & 0x3f) << 6) | (c3 & 0x3f);
            break;
        }
        LOG("RAW ch=%.2x : <%c>\n", ch, ch | 0x40);
        switch (state)
        {
    default:
    case BASE_STATE:
/*
 * This is where I start. If I get anything other than ESC I just return
 * it, but if I get ESC I progress a state.
 */
            if (ch == 0x1b)
            {   state = ESC_STATE;
                continue;
            }
            else return ch;
    case ESC_STATE:
/*
 * After ESC if the next character is another ESC I just count it, if
 * the next character is [ (so I have had "ESC [" or "ESC ESC [") I
 * progress, otherwise I treat the character as "escaped" and or in the
 * "meta" bit ALT_BIT.
 */
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
/*
 * After "ESC [" I absorb digits and semicolons.
 */
            if (isdigit((unsigned char)ch))
            {   numval1 = 10*numval1 + ch - '0';
                continue;
            }
            else if (ch == ';')
            {   numval2 = numval1;
                numval1 = 0;
                continue;
            }
/*
 * Now the whole code can be put together as one item... I will
 * only look at the low 8 bits of any character that is just after an
 * ESC.
 */
            ch = (ch & 0xff) | (numval2 << 16) | (numval1 << 8);
/*
 * The table here represents the codes that I have come across thus far:
 */
            esc_esc |= ARROW_BIT;
            switch (ch)
            {
        case 0x010500+'A':
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




/*
 * Cursor movement functions are only wanted within this file and
 * should only actually be called in the "enabled" case.
 */

static void term_move_down(int del)
{
#ifdef WIN32
/*
 * Since the screen is on the same machine as the rest of my process, and
 * I am in general interacting with a (slow) user here I will not try ANY
 * optimisations at all!
 */
    CONSOLE_SCREEN_BUFFER_INFO csb;
    if (del == 0) return;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb)) return;
    csb.dwCursorPosition.Y += del;
    SetConsoleCursorPosition(stdout_handle, csb.dwCursorPosition);
/*
 * I do not quite know if the above is always what I want! When I move down
 * and I start on the line that is the lowest one on the screen I do really
 * want a new line to appear for me to move onto.
 */
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
/*
 * The above would be unsatisfactory if it ever happened that the
 * movement was liable to take me beyond the width of the terminal, and
 * there is a special worry about the bottom rightmost position on the
 * screen, since it is not well supported by some terminals.
 */
    cursorx += del;
    return;
#else
/*
 * As a small optimisation here if the target location is closer to the
 * left margin than to the currect position (by at least 3) then
 * issue a CR to move rapidly to the left margin and then sort out what
 * else is needed.
 */
    fflush(stdout);
    if (del<0 && (cursorx+del+3) < (-del))
    {   putp(carriage_return);
        del = cursorx + del;
        cursorx = 0;
    }
    cursorx += del;
/*
 * ... otherwise I position the cursor by doing dull sequences that move the
 * cursor one position at a time.
 */
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
#ifdef WIN32 /* OK */
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

/*
 * I call refresh_display() to get the screen up to date with what my
 * internal model expects.  The data I base this on will be:
 *     input_line      a string showing what I want displayed
 *    !display_line    the string I had last displayed
 *     insert_point    the offset in input_line that I want the cursor
 *                     to end up at
 *    !cursorx         the current X coordinate on the cursor on the scren,
 *                     where 0 indicated the leftmost column
 *    !cursory         the current Y coordinate, where 0 is the line that
 *                     the active input line's display starts (and positive
 *                     coordinates indicated lines below that)
 *    !final_cursorx   x-coordinate of rightmost visible character on the
 *                     screen at present.
 *    !final_cursory   y-coordinate ditto
 *    !max_cursory     largest value of cursory used thus far
 *     columns         width of the screen
 *     lines           height of the screen
 *     term_can_invert display is capable of inverse video
 *     invert_start,
 *     invert_end      region (if any) to highlight.
 *
 * [I have annotated items that are updated here with (!)]
 *
 * The main complications that arise are
 * (a) input_line may contain characters that should be rendered across
 *     several columns. The key case that forces this is TAB, but once
 *     that has been conceded it may make sense to render control characters
 *     so that eg '\04' is dispalyed as "^D" and so that other unprintable
 *     characters that may get into the buffer by accident are handled
 *     kindly.
 *     [as a late bit of imagination I might like to render an embedded
 *     newline character ('\n') as a line-break]
 * (b) input_line (with or without TABs!) can stand for a line that is
 *     longer than the line-length shown by "columns". In that case the
 *     expected representation on the screen will involve wrapping it.
 *     proper treatment of wrapping and scrolling and the final character
 *     position on the screen all need attention.
 *
 * (c) In extreme cases wrapping could lead to a display using too many
 *     lines, and in that case further truncation is needed.
 * (d) After a case where the user re-sizes the screen the issue of what is
 *     visible on the screen, where the cursor is and in general what to do
 *     to regain sanity seems pretty delicate!
 */

/*
 * With my first version of the code here I will not handle either (c) or (d)
 * a lot. Well maybe in fact (d) gets coped with by virtue of the total
 * screen re-write..., and I check screen size (if I can) whenever I am
 * about to refresh.
 *
 * The code here updates from the first changed position of a line right to
 * the end. If the user has re-positioned the cursor so they are making edits
 * towards the start of a long line this can lead to excessive screen
 * update actvity. If this ever became a worry there are two things I could
 * do:
 *  (1) check for and exploit delete and insert modes for my screen and use
 *      them where helpful
 *  (2) notice when the tail of a line does not need change and avoid
 *      re-writing in in that case.
 * Actually I do not count these as high priority - mostly because screens
 * etc etc are now usually very fast. Also inserts mid-line will be less
 * common than just adding characters at the end.
 */

/*
 * line_wrap() is a part of refresh_display(), and it prints a character
 * taking care of line-wrapping. The character passed will be of flavour
 * wchar_t. I am not (at least for now) going to worry about Windows and
 * surrogate characters.
 */

static int line_wrap(int ch, int tab_offset)
{
/*  LOG("wrap_line ch=%#x tab_offset=%d cursorx=%d\n", ch, tab_offset, cursorx);*/
    cursorx++;
    if (cursorx >= columns)
    {   tab_offset += cursorx;
/*
 * When the line I am wrapping is the final one of my stuff I will be super
 * careful and not write the character until it will no longer be at the
 * final position on the screen. I do this because some (but perhaps not
 * all) terminals force a scroll when that final character is filled in,
 * and for that to happen and for me to be not quite certain just what the
 * situation was would be terrible.
 */
/*
 * I could imagine that if cursory==max_cursory here I could need to do
 * something special to move down a row to ensure that if I am on the bottom
 * row of the screen I scroll properly... What I do here with a hope that it
 * counts as "on the safe side" is to switch back to cooked mode before
 * outputting a newline character. 
 */
        if (cursory == max_cursory)
        {   term_move_first_column();
            LOG("need to scroll page\n");
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, stdout_attributes);
#else
            my_reset_shell_mode();
#endif
            term_putchar(L'\n');
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, 0);
#else
            my_reset_prog_mode();
#endif
            cursory++;
            max_cursory = cursory;
/*
 * Now I have performed the scroll, so I will go back and insert the
 * character. I very much hope that this time writing to the last position on
 * a row does not do anything special at all about the cursor or scrolling.
 */
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
/*
 * The version here right now is done as directly as I can without
 * thought for optimisation. That is in the hope that I can get it
 * right, and then put in performance upgrades later on.
 */
    int i, ch, inverse = 0,
        tab_offset = 0,
        curx=columns, cury=lines,
        finx, finy, window_size_changed;
/*
 *  LOG("refresh_display cx=%d cy=%d\n", cursorx, cursory);
 *  LOG("il:<%ls>\ndl:<%ls>\n", input_line, display_line);
 */
/*
 * Rather than believing in any SIGWINCH signal (or some such!) to alert
 * me to screen size changes, I will (on systems that give me a way to)
 * check the screen size every time I am about to do a screen update. This
 * may feel like a cost, but it is incurred when the user has hit a key
 * so may not be noticed too much. Well I can see that it can call for
 * a handshake between the terminal and this program so on systems with
 * remote access and slow lines it may well put in a noticable screen-update
 * delay - if that proves the case I will need to review what I do.
 */
    measure_screen();
/*
 * Check if the screen-size has changed since last time.
 * At present since I re-draw the whole input line every time changes
 * in screen size make no difference to me and so I just ignore the
 * information I collect here, but as I start to optimise my screen
 * update I will need to look at it more carefully.
 */
    window_size_changed = (curx!=columns || cury!=lines);
    if (window_size_changed)
    {
/*
 * I want to force a fairly complete re-write here, so I explain that
 * the screen now holds stuff that is totally different to what is
 * desired, and that there may be residual stuff on the screen down as far
 * as the almost-rightmost column of the bottom line that I have ever put
 * anything on.
 */
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
            } while ((tab_offset + finx)%8 != 0);
        }
        else if (ch == L'\n')
        {   tab_offset = 0;
            finx = 0;
            finy++;
        }
/*
 * I am going to display characters whose code is in the range 0x00 to
 * 0x1f with a "^", as in "^C" will denote character 3.
 */
        else if (ch < 0x20) finx += 2;
        else finx += 1;
        if (finx >= columns)
        {   tab_offset += finx;
            finx -= columns;
            finy++;
        }
        i++;
    }
/*
 * Start my moving to the beginning of the where I must write stuff...
 */
    term_move_right(finx - cursorx);
    term_move_down(finy - cursory);
/*
 * Re-display all of the current input line. In may cases this
 * will do all the re-drawing needed, but beware if the existing displayed
 * line is longer (because I have just deleted something). While drawing
 * the current line when I reach the insert_point I will record the cursor
 * position.
 */
    for (; (ch = input_line[i])!=0; i++)
    {   if (i == insert_point)
        {   curx = cursorx;
            cury = cursory;
        }
        if (term_can_invert && invert_start<invert_end && i==invert_start)
        {
            fflush(stdout);
#ifdef WIN32
            SetConsoleTextAttribute(stdout_handle, revAttributes);
#else
            putp(enter_reverse_mode);
#endif
            inverse = 1;
        }
        if (term_can_invert && invert_start<invert_end && i==invert_end)
        {
            fflush(stdout);
#ifdef WIN32
            SetConsoleTextAttribute(stdout_handle, plainAttributes);
#else
            putp(exit_attribute_mode);
#endif
            inverse = 0;
        }
/*
 * A horrid case arises here. If the cursor starts off close to the right
 * hand side of the window and a TAB is issued than it might wrap. Well
 * that in itself is OK. However if the screen width is not a multiple of
 * the tab spacing then in effect tab-stops on the second and subsequent
 * lines of the display of the wrapped line will need to allow for this.
 * The variable "tab_offset" is allowing for the characters on previous as
 * well as this line.
 * I am also ignoring all possibility that Unicode code points other
 * than TAB and NEWLINE have other than regular width, so for instance
 * zero-width spaces will not be handled well.
 */
        if (ch == L'\t')
        {   do
            {   tab_offset = line_wrap(L' ', tab_offset);
            } while ((tab_offset + cursorx)%8 != 0);
        }
        else if (ch == L'\n')
        {
/*
 * Here I want a line-break in the "single line" I am displaying. I achieve
 * the effect I want by writing blanks until cursorx gets back to zero by
 * virtue of line-wrapping!
 */
            while (cursorx !=  0) line_wrap(L' ', 0);
/*
 * Tabs should now be relative to the new line-start.
 */
            tab_offset = 0;
        }
        else if (ch < 0x20)
        {   tab_offset = line_wrap(L'^', tab_offset);
            /* Turn into @, A, B etc */
            tab_offset = line_wrap(ch | 0x40, tab_offset);
        }
        else tab_offset = line_wrap(ch, tab_offset);
    }
/*
 * Clear inverse video mode.
 */
    if (inverse)
    {
        fflush(stdout);
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
/*
 * Now the input line may have shrunk because of a deletion so there may be
 * bits of the display line remaining. I need to replace them with blanks.
 * Because I expect to be filling neatly up to the right hand end of the
 * line and I will never be creating an extra row here I do not need to
 * use line_wrap.
 */
    finx = cursorx;
    finy = cursory;
/*
 * If the cursor is now positioned below where the previously-displayed line
 * finished there is no joy at all in doing any padding to try to overwrite
 * left-over bits of that previous line.
 */
    if (cursory <= final_cursory)
    {   while (cursory < final_cursory)
        {   while (cursorx < columns)
            {   term_putchar(L' ');
                cursorx++;
            }
            term_move_first_column();
            term_move_down(1);
        }
        while (cursorx < final_cursorx)
        {   term_putchar(L' ');
            cursorx++;
        }
    }
/*
 * record where real output finished this time
 */
    final_cursorx = finx;
    final_cursory = finy;
/*
 * Move the cursor to where it needs to appear.
 */
    if (cury != cursory) term_move_down(cury-cursory);
    if (curx != cursorx) term_move_right(curx-cursorx);
    fflush(stdout);
/*
 * Now the display should be up to date, so record that situation.
 */
    wcscpy(display_line, input_line);
}

static void term_set_mark(void)
{
/*
 * Actually I will not (at present) do anything here! And furthermore I
 * have a degree of pain. When I try running on a Unix-like system even
 * after setting "raw" mode I do not get all the chars that I want...
 */
    term_bell();
    refresh_display();
}


static void term_to_start(void)
{
    insert_point = prompt_length;
    refresh_display();
}


static void term_to_end(void)
{
    while (input_line[insert_point] != 0) insert_point++;
    refresh_display();
}


/*
 * The next two just find where the position to left or right is, searching
 * by words, with a FOX-like interpretation of the term "word", which I
 * hope will also be an emacs-like interpretation.
 */

static int term_find_next_word_forwards(void)
{
    int n = insert_point;
    if (input_line[n] == 0) return n;
    do
    {   n++;
    } while (input_line[n] != 0 &&
             (iswalnum(input_line[n]) || input_line[n] == L'_'));
    while (input_line[n] != 0 && iswspace(input_line[n])) n++;
    return n;
}

static int term_find_next_word_backwards(void)
{
    int n = insert_point;
    if (n == prompt_length) return n;
    do
    {   n--;
    } while (n != prompt_length &&
             (iswalnum(input_line[n]) || input_line[n] == '_'));
    while (n != prompt_length && iswspace(input_line[n])) n--;
    if (n == prompt_length || n == insert_point-1) return n;
    else return n+1; 
}

static void term_forwards_char(void)
{
    if (input_line[insert_point] == 0) term_bell();
    else insert_point++;
    refresh_display();
}


static void term_forwards_word(void)
{
    if (input_line[insert_point] == 0) term_bell();
    else
    {   insert_point = term_find_next_word_forwards();
        refresh_display();
    }
}


static void term_back_char(void)
{
    if (insert_point == prompt_length) term_bell();
    else insert_point--;
    refresh_display();
}

static void term_back_word(void)
{
    if (insert_point == prompt_length) term_bell();
    else
    {   insert_point = term_find_next_word_backwards();
        refresh_display();
    }
}


static void term_delete_forwards(void)
{
    int i = insert_point;
    if (input_line[i] == 0) term_bell();
    else for (;;)
    {   input_line[i] = input_line[i+1];
        if (input_line[i] == 0) break;
        i++;
    }
    refresh_display();
}


static void term_delete_backwards(void)
{
    if (insert_point == prompt_length) term_bell();
    else 
    {   int i = insert_point - 1;
        insert_point = i;
        for (;;)
        {   input_line[i] = input_line[i+1];
            if (input_line[i] == 0) break;
            i++;
        }
    }
    refresh_display();
}


static void term_delete_word_forwards(void)
{
    if (input_line[insert_point] == 0) term_bell();
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
{
    if (insert_point == prompt_length) term_bell();
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
{
    insert_point = prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static void term_history_next(void)
{
    const wchar_t *history_string;
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
{
    const wchar_t *history_string;
    if (historyLast == -1) /* no previous lines to retrieve */
    {   term_bell();
        return;
    }
/*
 * If I have not moved the history pointer at all yet move it into the
 * range of valid history entries.
 */
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
/*
 * I remember where I was on the input line but then move to the end and
 * append a message that indicates to the user that a search is in progress.
 */
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
{
    search_found = search_saved_point = insert_point;
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
/*
 * This is a crude and not especially efficient pattern match. I think
 * it should be good enough for use here! I make it return the offset where
 * a match first occurred (if one does) in case that will be useful to me
 * later. I could put the cursor there, perhaps?
 */
    int offset;
    for (offset=0;*(text+offset)!=0;offset++)
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
{
    int r = -1;
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

/*
 * After a success in a search this sets the input line to the given
 * text. The real mess here is that it has to stick the search text
 * on the end. And a further worry might be buffer overflow... Suppose that
 * the lines searched so far have all been just the same length as the search
 * string, and that this is quite long. Now we have searched and found a
 * line that is much longer. The line itself just about filled the
 * input line buffer, and when the search string is stuck on its end it
 * overflows. Oh woe.  Well look later on and you will see that I keep track
 * of the longest line I have stuck into the history and I measure against
 * that when accepting search characters. So do not worry after all!!
 */
static void set_input(const wchar_t *s)
{
    wcscpy(&input_line[prompt_length], s);
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

/*
 * This is called when I am in the process of searching and a character is
 * typed.
 * Returns true if searching must continue, or false if searchMode has been
 * left. While in search mode I will keep insert_point at the end of the
 * buffer.
 */

static int term_search_char(int ch)
{
    switch (ch)
    {
/*
 * ALT-N and ALT-Down continue the search using the current search string
 * but searching through the Next history item
 */
case CTRL(L'N') + ALT_BIT: case L'N' + ALT_BIT: case L'n' + ALT_BIT:
case ARROW_BIT + TERM_DOWN + ALT_BIT:
        searchFlags = 1;    /* search downwards */
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
/*
 * ALT-P and ALT-Up continue the search using the current search string
 * but searching through the Previous history item
 */
case CTRL(L'P') + ALT_BIT: case L'P' + ALT_BIT: case L'p' + ALT_BIT:
case ARROW_BIT + TERM_UP + ALT_BIT:
        searchFlags = -1;    /* search upwards */
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

/*
 * Ctrl-H deletes exist search mode if the search string is empty, otherwise
 * it deletes a char from the search string and pops back to wherever the
 * shorter string had matched.
 */
case CTRL(L'H'):                   /* Backspace */
case 0x7f:                         /* Delete */
        if (searchLen != 0)
        {   input_line[--insert_point] = 0;
            searchBuff[--searchLen] = 0;
            historyNumber = searchStack[searchLen];
            search_found = trySearch();   /* ought to succeed */
            set_input(input_history_get(historyNumber));
            invert_start = prompt_length + search_found;
            invert_end = invert_start + searchLen;
            refresh_display();
            return 1;
        }
        else
        {   term_bell();
            ch = CTRL('U');  /* Drop through to exit search mode */
        }
/*
 * Control characters (except TAB) and things tagged with ESC cause an exit
 * from search mode.
 */
default:
        if ((ch & (ALT_BIT|ARROW_BIT)) != 0 ||
            (ch != L'\t' && ch<0x20))
        {
/*
 * Exit search mode
 */
            searchFlags = 0;
/*
 * The approved means of switching some highlights off is as follows. This
 * leads the next refresh_display to re-write the bit that had previously
 * been in inverse video... ie leave invert_start at the start of where
 * inverting had started, but set invert_end to the same value.
 */
            invert_end = invert_start;
            input_line[regular_line_end] = 0;
            insert_point = prompt_length + search_found + searchLen;
            refresh_display();
/*
 * "^U" will exit search mode, and when it does that it does not do anything
 * else. Even if there were ever a time that I had implemented an UNDO
 * facility, which I think I am not about to.
 */
            return (ch & (~(ALT_BIT|ARROW_BIT))) == CTRL(L'U');
        }

    }
/*
 * So not accept search characters beyond some limit since I have a fixed-
 * size buffer for the search string. Just beep and ignore the chararcter.
 */
    if (searchLen > 98)
    {   term_bell();
        return 1;
    }
    searchStack[searchLen] = historyNumber;
    searchBuff[searchLen++] = ch;
    searchBuff[searchLen] = 0;
/*
 * Now perform a search...
 */
    {   int r;
        int save = historyNumber;
        if ((r = trySearch()) == -1)
        {   historyNumber = save;         /* search failed this time */
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
/*
 * If the insert point points at an alphemumeric character this ends up
 * returning the address of the first letter of the "word". If the
 * initial point is not on an alphanumeric it returns a pointer one to the
 * right of the insert point.
 */
    int n = insert_point;
    while (n>=prompt_length &&
           (iswalnum(input_line[n]) || input_line[n]==L'_')) n--;
    return n+1;
}

static int term_find_word_end(void)
{
/*
 * returns the address of the first character beyond the end of a current
 * word. If the character at the insert point is not alphanumeric then its
 * address is returned.
 */
    int n = insert_point;
    while (input_line[n]!=0 &&
           (iswalnum(input_line[n]) || input_line[n]==L'_')) n++;
    return n;
}

static void term_capitalize_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    if (a < b) input_line[a] = towupper(input_line[a]);
    for (i=a+1; i<b; i++) input_line[i] = towlower(input_line[i]);
    refresh_display();
}


static void term_lowercase_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++) input_line[i] = (char)towlower(input_line[i]);
    refresh_display();
}


static void term_uppercase_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++) input_line[i] = towupper(input_line[i]);
    refresh_display();
}


static void term_transpose_chars(void)
{
    int c, d;
    if (((c = input_line[insert_point]) == 0) ||
        ((d = input_line[insert_point+1]) == 0)) term_bell();
    else
    {   input_line[insert_point] = d;
        input_line[insert_point+1] = c;
        refresh_display();
    }
}


static void term_undo(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^U>");
    term_bell();
}


static void term_quoted_insert(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^V>");
    term_bell();
}


static void term_copy_previous_word(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^W>");
    term_bell();
}


static void term_copy_region(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&W>");
    term_bell();
}


static void term_yank(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^Y>");
    term_bell();
}


static void term_reinput(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^R>");
    term_bell();
}


static void term_redisplay(void)
{
/*
 * To get as much of the active area redrawn as I can I will reset the
 * record of what is visible to suggest that everything is totally out of
 * date.
 */
    display_line[0] = input_line[0] + 1;
    display_line[1] = 0;
    refresh_display();
}


static void term_clear_screen(void)
{
/*
 * This will then leave the input-line displayed at the top of your window...
 */
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
/* @@@@@ */
}


static void term_resume_output(void)
{
/* @@@@@ */
}


static void term_discard_output(void)
{
/* @@@@@ */
}


static int hexval(int c)
{
/*
 * Regardless of the fact that in general I am working in Unicode, here
 * I am only interested in the digits 0-9 and the letters a-f and A-F and
 * if I only accept ones in the most basic form I can use 7-bit codes.
 */
    if (c < 0 || c >= 0x7f) return -1;
    if (isdigit((unsigned char)c)) return c - '0';
    else if (isupper((unsigned char)c)) return c + (10 - 'A');
    else return c + (10 - 'a');
}

/*
 * The table here is the set of names used in HTML to denote characters
 * and so I hope that many of the names will be familiar to many people.
 * They are sorted into a collating order based on their ASCII code so I
 * can look up names using binary search. Note that the longest name is
 * of length 8 ("thetasym"), and the shortest is of length 2 ("mu", "pi"
 * and the quite a few others).
 */

uniname unicode_names[] =
{
/*
 * It is really part of the purpose of this table that the names are all in
 * the most basic character set, and so I keep the table using "char *" and
 * regular narrow strings.
 */
    {"AElig",   198},    /* latin capital letter AE = latin capital ligature AE */
    {"Aacute",  193},    /* latin capital letter A with acute */
    {"Acirc",   194},    /* latin capital letter A with circumflex */
    {"Agrave",  192},    /* latin capital letter A with grave = latin capital letter A grave */
    {"Alpha",   913},    /* greek capital letter alpha */
    {"Aring",   197},    /* latin capital letter A with ring above = latin capital letter A ring */
    {"Atilde",  195},    /* latin capital letter A with tilde */
    {"Auml",    196},    /* latin capital letter A with diaeresis */
    {"Beta",    914},    /* greek capital letter beta */
    {"Ccedil",  199},    /* latin capital letter C with cedilla */
    {"Chi",     935},    /* greek capital letter chi */
    {"Dagger",  8225},   /* double dagger */
    {"Delta",   916},    /* greek capital letter delta */
    {"ETH",     208},    /* latin capital letter ETH */
    {"Eacute",  201},    /* latin capital letter E with acute */
    {"Ecirc",   202},    /* latin capital letter E with circumflex */
    {"Egrave",  200},    /* latin capital letter E with grave */
    {"Epsilon", 917},    /* greek capital letter epsilon */
    {"Eta",     919},    /* greek capital letter eta */
    {"Euml",    203},    /* latin capital letter E with diaeresis */
    {"Gamma",   915},    /* greek capital letter gamma */
    {"Iacute",  205},    /* latin capital letter I with acute */
    {"Icirc",   206},    /* latin capital letter I with circumflex */
    {"Igrave",  204},    /* latin capital letter I with grave */
    {"Iota",    921},    /* greek capital letter iota */
    {"Iuml",    207},    /* latin capital letter I with diaeresis */
    {"Kappa",   922},    /* greek capital letter kappa */
    {"Lambda",  923},    /* greek capital letter lambda */
    {"Mu",      924},    /* greek capital letter mu */
    {"Ntilde",  209},    /* latin capital letter N with tilde */
    {"Nu",      925},    /* greek capital letter nu */
    {"OElig",   338},    /* latin capital ligature OE */
    {"Oacute",  211},    /* latin capital letter O with acute */
    {"Ocirc",   212},    /* latin capital letter O with circumflex */
    {"Ograve",  210},    /* latin capital letter O with grave */
    {"Omega",   937},    /* greek capital letter omega */
    {"Omicron", 927},    /* greek capital letter omicron */
    {"Oslash",  216},    /* latin capital letter O with stroke = latin capital letter O slash */
    {"Otilde",  213},    /* latin capital letter O with tilde */
    {"Ouml",    214},    /* latin capital letter O with diaeresis */
    {"Phi",     934},    /* greek capital letter phi */
    {"Pi",      928},    /* greek capital letter pi */
    {"Prime",   8243},   /* double prime = seconds = inches */
    {"Psi",     936},    /* greek capital letter psi */
    {"Rho",     929},    /* greek capital letter rho */
    {"Scaron",  352},    /* latin capital letter S with caron */
    {"Sigma",   931},    /* greek capital letter sigma */
    {"THORN",   222},    /* latin capital letter THORN */
    {"Tau",     932},    /* greek capital letter tau */
    {"Theta",   920},    /* greek capital letter theta */
    {"Uacute",  218},    /* latin capital letter U with acute */
    {"Ucirc",   219},    /* latin capital letter U with circumflex */
    {"Ugrave",  217},    /* latin capital letter U with grave */
    {"Upsilon", 933},    /* greek capital letter upsilon */
    {"Uuml",    220},    /* latin capital letter U with diaeresis */
    {"Xi",      926},    /* greek capital letter xi */
    {"Yacute",  221},    /* latin capital letter Y with acute */
    {"Yuml",    376},    /* latin capital letter Y with diaeresis */
    {"Zeta",    918},    /* greek capital letter zeta */
    {"aacute",  225},    /* latin small letter a with acute */
    {"ac12",    0xac12}, /* so that frac12 gets handled smoothly */
    {"ac14",    0xac14}, /* ditto frac14 */
    {"ac34",    0xac34}, /* ditto frac34 */
    {"acirc",   226},    /* latin small letter a with circumflex */
    {"acute",   180},    /* acute accent = spacing acute */
    {"aelig",   230},    /* latin small letter ae = latin small ligature ae */
    {"agrave",  224},    /* latin small letter a with grave = latin small letter a grave */
    {"alefsym", 8501},   /* alef symbol = first transfinite cardinal (note) */
    {"alpha",   945},    /* greek small letter alpha */
    {"amp",     38},     /* ampersand */
    {"and",     8743},   /* logical and = wedge */
    {"ang",     8736},   /* angle */
    {"aring",   229},    /* latin small letter a with ring above = latin small letter a ring */
    {"asymp",   8776},   /* almost equal to = asymptotic to */
    {"atilde",  227},    /* latin small letter a with tilde */
    {"auml",    228},    /* latin small letter a with diaeresis */
    {"bdquo",   8222},   /* double low-9 quotation mark */
    {"beta",    946},    /* greek small letter beta */
    {"brvbar",  166},    /* broken bar = broken vertical bar */
    {"bull",    8226},   /* bullet = black small circle (note) */
    {"cap",     8745},   /* intersection = cap */
    {"ccedil",  231},    /* latin small letter c with cedilla */
    {"cedil",   184},    /* cedilla = spacing cedilla */
    {"cent",    162},    /* cent sign */
    {"chi",     967},    /* greek small letter chi */
    {"circ",    710},    /* modifier letter circumflex accent */
    {"clubs",   9827},   /* black club suit = shamrock */
    {"cong",    8773},   /* approximately equal to */
    {"copy",    169},    /* copyright sign */
    {"crarr",   8629},   /* downwards arrow with corner leftwards = carriage return */
    {"cup",     8746},   /* union = cup */
    {"curren",  164},    /* currency sign */
    {"dArr",    8659},   /* downwards double arrow */
    {"dagger",  8224},   /* dagger */
    {"darr",    8595},   /* downwards arrow */
    {"deg",     176},    /* degree sign */
    {"delta",   948},    /* greek small letter delta */
    {"diams",   9830},   /* black diamond suit */
    {"divide",  247},    /* division sign */
    {"eacute",  233},    /* latin small letter e with acute */
    {"ecirc",   234},    /* latin small letter e with circumflex */
    {"egrave",  232},    /* latin small letter e with grave */
    {"empty",   8709},   /* empty set = null set = diameter */
    {"emsp",    8195},   /* em space */
    {"ensp",    8194},   /* en space */
    {"epsilon", 949},    /* greek small letter epsilon */
    {"equiv",   8801},   /* identical to */
    {"eta",     951},    /* greek small letter eta */
    {"eth",     240},    /* latin small letter eth */
    {"euml",    235},    /* latin small letter e with diaeresis */
    {"euro",    8364},   /* euro sign */
    {"exist",   8707},   /* there exists */
    {"fnof",    402},    /* latin small f with hook = function = florin */
    {"forall",  8704},   /* for all */
    {"frac12",  189},    /* vulgar fraction one half = fraction one half */
    {"frac14",  188},    /* vulgar fraction one quarter = fraction one quarter */
    {"frac34",  190},    /* vulgar fraction three quarters = fraction three quarters */
    {"frasl",   8260},   /* fraction slash */
    {"gamma",   947},    /* greek small letter gamma */
    {"ge",      8805},   /* greater-than or equal to */
    {"gt",      62},     /* greater-than sign */
    {"hArr",    8660},   /* left right double arrow */
    {"hearts",  9829},   /* black heart suit = valentine */
    {"hellip",  8230},   /* horizontal ellipsis = three dot leader */
    {"iacute",  237},    /* latin small letter i with acute */
    {"icirc",   238},    /* latin small letter i with circumflex */
    {"iexcl",   161},    /* inverted exclamation mark */
    {"igrave",  236},    /* latin small letter i with grave */
    {"image",   8465},   /* blackletter capital I = imaginary part */
    {"infin",   8734},   /* infinity */
    {"int",     8747},   /* integral */
    {"iota",    953},    /* greek small letter iota */
    {"iquest",  191},    /* inverted question mark = turned question mark */
    {"isin",    8712},   /* element of */
    {"iuml",    239},    /* latin small letter i with diaeresis */
    {"kappa",   954},    /* greek small letter kappa */
    {"lArr",    8656},   /* leftwards double arrow (note) */
    {"lambda",  955},    /* greek small letter lambda */
    {"lang",    9001},   /* left-pointing angle bracket = bra (note) */
    {"laquo",   171},    /* left-pointing double angle quotation mark = left pointing guillemet */
    {"larr",    8592},   /* leftwards arrow */
    {"lceil",   8968},   /* left ceiling = apl upstile */
    {"ldquo",   8220},   /* left double quotation mark */
    {"le",      8804},   /* less-than or equal to */
    {"lfloor",  8970},   /* left floor = apl downstile */
    {"lowast",  8727},   /* asterisk operator */
    {"loz",     9674},   /* lozenge */
    {"lrm",     8206},   /* left-to-right mark (for formatting only) */
    {"lsaquo",  8249},   /* single left-pointing angle quotation mark (note) */
    {"lsquo",   8216},   /* left single quotation mark */
    {"lt",      60},     /* less-than sign */
    {"macr",    175},    /* macron = spacing macron = overline = APL overbar */
    {"mdash",   8212},   /* em dash */
    {"micro",   181},    /* micro sign */
    {"middot",  183},    /* middle dot = Georgian comma = Greek middle dot */
    {"minus",   8722},   /* minus sign */
    {"mu",      956},    /* greek small letter mu */
    {"nabla",   8711},   /* nabla = backward difference */
    {"nbsp",    160},    /* no-break space = non-breaking space */
    {"ndash",   8211},   /* en dash */
    {"ne",      8800},   /* not equal to */
    {"ni",      8715},   /* contains as member (note) */
    {"not",     172},    /* not sign */
    {"notin",   8713},   /* not an element of */
    {"nsub",    8836},   /* not a subset of */
    {"ntilde",  241},    /* latin small letter n with tilde */
    {"nu",      957},    /* greek small letter nu */
    {"oacute",  243},    /* latin small letter o with acute */
    {"ocirc",   244},    /* latin small letter o with circumflex */
    {"oelig",   339},    /* latin small ligature oe (note) */
    {"ograve",  242},    /* latin small letter o with grave */
    {"oline",   8254},   /* overline = spacing overscore */
    {"omega",   969},    /* greek small letter omega */
    {"omicron", 959},    /* greek small letter omicron */
    {"oplus",   8853},   /* circled plus = direct sum */
    {"or",      8744},   /* logical or = vee */
    {"ordf",    170},    /* feminine ordinal indicator */
    {"ordm",    186},    /* masculine ordinal indicator */
    {"oslash",  248},    /* latin small letter o with stroke, = latin small letter o slash */
    {"otilde",  245},    /* latin small letter o with tilde */
    {"otimes",  8855},   /* circled times = vector product */
    {"ouml",    246},    /* latin small letter o with diaeresis */
    {"para",    182},    /* pilcrow sign = paragraph sign */
    {"part",    8706},   /* partial differential */
    {"permil",  8240},   /* per mille sign */
    {"perp",    8869},   /* up tack = orthogonal to = perpendicular */
    {"phi",     966},    /* greek small letter phi */
    {"pi",      960},    /* greek small letter pi */
    {"piv",     982},    /* greek pi symbol */
    {"plusmn",  177},    /* plus-minus sign = plus-or-minus sign */
    {"pound",   163},    /* pound sign */
    {"prime",   8242},   /* prime = minutes = feet */
    {"prod",    8719},   /* n-ary product = product sign (note) */
    {"prop",    8733},   /* proportional to */
    {"psi",     968},    /* greek small letter psi */
    {"quot",    34},     /* quotation mark = APL quote */
    {"rArr",    8658},   /* rightwards double arrow (note) */
    {"radic",   8730},   /* square root = radical sign */
    {"rang",    9002},   /* right-pointing angle bracket = ket (note) */
    {"raquo",   187},    /* right-pointing double angle quotation mark = right pointing guillemet */
    {"rarr",    8594},   /* rightwards arrow */
    {"rceil",   8969},   /* right ceiling */
    {"rdquo",   8221},   /* right double quotation mark */
    {"real",    8476},   /* blackletter capital R = real part symbol */
    {"reg",     174},    /* registered sign = registered trade mark sign */
    {"rfloor",  8971},   /* right floor */
    {"rho",     961},    /* greek small letter rho */
    {"rlm",     8207},   /* right-to-left mark (for formatting only) */
    {"rsaquo",  8250},   /* single right-pointing angle quotation mark (note) */
    {"rsquo",   8217},   /* right single quotation mark */
    {"sbquo",   8218},   /* single low-9 quotation mark */
    {"scaron",  353},    /* latin small letter s with caron */
    {"sdot",    8901},   /* dot operator (note) */
    {"sect",    167},    /* section sign */
    {"shy",     173},    /* soft hyphen = discretionary hyphen (displays incorrectly on Mac) */
    {"sigma",   963},    /* greek small letter sigma */
    {"sigmaf",  962},    /* greek small letter final sigma (note) */
    {"sim",     8764},   /* tilde operator = varies with = similar to (note) */
    {"spades",  9824},   /* black spade suit (note) */
    {"sub",     8834},   /* subset of */
    {"sube",    8838},   /* subset of or equal to */
    {"sum",     8721},   /* n-ary sumation (note) */
    {"sup",     8835},   /* superset of (note) */
    {"sup1",    185},    /* superscript one = superscript digit one */
    {"sup2",    178},    /* superscript two = superscript digit two = squared */
    {"sup3",    179},    /* superscript three = superscript digit three = cubed */
    {"supe",    8839},   /* superset of or equal to */
    {"szlig",   223},    /* latin small letter sharp s = ess-zed */
    {"tau",     964},    /* greek small letter tau */
    {"there4",  8756},   /* therefore */
    {"theta",   952},    /* greek small letter theta */
    {"thetasym",977},    /* greek small letter theta symbol */
    {"thinsp",  8201},   /* thin space */
    {"thorn",   254},    /* latin small letter thorn */
    {"tilde",   732},    /* small tilde */
    {"times",   215},    /* multiplication sign */
    {"trade",   8482},   /* trade mark sign */
    {"uArr",    8657},   /* upwards double arrow */
    {"uacute",  250},    /* latin small letter u with acute */
    {"uarr",    8593},   /* upwards arrow */
    {"ucirc",   251},    /* latin small letter u with circumflex */
    {"ugrave",  249},    /* latin small letter u with grave */
    {"uml",     168},    /* diaeresis = spacing diaeresis */
    {"upsih",   978},    /* greek upsilon with hook symbol */
    {"upsilon", 965},    /* greek small letter upsilon */
    {"uuml",    252},    /* latin small letter u with diaeresis */
    {"weierp",  8472},   /* script capital P = power set = Weierstrass p */
    {"xi",      958},    /* greek small letter xi */
    {"yacute",  253},    /* latin small letter y with acute */
    {"yen",     165},    /* yen sign = yuan sign */
    {"yuml",    255},    /* latin small letter y with diaeresis */
    {"zeta",    950},    /* greek small letter zeta */
    {"zwj",     8205},   /* zero width joiner */
    {"zwnj",    8204},   /* zero width non-joiner */
    {NULL,      -1}      /* dummy entry so end of table is easy to detect */ 
};

static int compare_strings(const void *a, const void *b)
{
    const uniname *a1 = (uniname *)a;
    const uniname *b1 = (uniname *)b;
    return strcmp(a1->name, b1->name);
}

static int lookup_name(const char *s)
{
    uniname k, *p;
    k.name = s;
    p = bsearch(&k, unicode_names,
                sizeof(unicode_names)/sizeof(unicode_names[0]) -
                    sizeof(unicode_names[0]), /* allow for the terminator */
                sizeof(unicode_names[0]),
                compare_strings);
    if (p == NULL) return -1; /* not found */
    else return p->code;
}

static int lookup_wide_name(const wchar_t *s)
{
    char narrow[20];
    int i;
    for (i=0; i<sizeof(narrow)-1; i++)
    {   if (s[i] == 0) break;
        if (s[i] >= 0x7f) return -1; /* not a basic ASCII character */
        narrow[i] = s[i];
    }
    narrow[i] = 0;
    return lookup_name(narrow);
}

const char *lookup_code(int c)
{
    int i;
/*
 * I do a simple linear search here. It is cheap-enough given that it is
 * only needed when the user types a special command, ALT-x. It does not
 * matter here that I scan the very final NULL entry.
 */
    for (i=0; i<sizeof(unicode_names)/sizeof(unicode_names[0]); i++)
    {   if (unicode_names[i].code == c) return unicode_names[i].name;
    }
    return NULL;
}

static wchar_t wide_char_name[20];

const wchar_t *wide_lookup_code(int c)
{
    const char *s = lookup_code(c);
    wchar_t *p;
    if (s == NULL) return NULL;
    p = wide_char_name;
    while (*s != 0) *p++ = (*s++ & 0xff);
    *p = 0;
    return wide_char_name;
}

static void term_replace_chars_backwards(int n, const wchar_t *s)
{
/*
 * Replace n characters that are before the caret with bytes from the
 * string s.
 */
    int m = wcslen(s);
    if (n > m)        /* Overall this deletes characters */
    {   int i = insert_point - n;
        for (;;)
        {   input_line[i] = input_line[i+n-m];
            if (input_line[i] == 0) break;
            i++;
        }
        insert_point -= (n-m);
    }
    else if (m > n)   /* Overall this inserts characters */
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

static wchar_t input_word[16];
static wchar_t output_word[16];

static void term_ctrl_z_command(void)
{
/*
 * It is not yet clear that I have anything much to allocate this to. In
 * emacs it would be "obey extended command".
 */
    insert_point += swprintf(&input_line[insert_point], input_line_size-insert_point, L"<^X>");
    term_bell();
    term_redisplay();
}

/*
 * Encode into buffer b as up to 4 characters (plus a nul). Because I
 * am only concerned with Unicode I only need encode values in the
 * range 0 to 0x10ffff. Returns the number of chars packed (not counting
 * the terminating '\0').
 */

int utf_encode(unsigned char *b, int c)
{
    unsigned char *p = b;
    c &= 0x1fffff;   /* limit myself to 21-bit values here */
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

/*
 * Decode utf-8 or return -1 if invalid.
 */

int utf_decode(unsigned char *b)
{
    int c = *b++, c1, c2, c3;
    switch (c & 0xf0)
    {
/*
 *  case 0x00:
 *  case 0x10:
 *  case 0x20:
 *  case 0x30:
 *  case 0x40:
 *  case 0x50:
 *  case 0x60:
 *  case 0x70:
 */
default:
        return c;
case 0x80:
case 0x90:
case 0xa0:
case 0xb0:
        return -1;  /* out of place continuation marker */
case 0xc0:
case 0xd0:
        c1 = *b;
        if ((c1 & 0xc0) != 0x80) return -1; /* not continuation */
        return ((c & 0x1f) << 6) | (c1 & 0x3f);
case 0xe0:
        c1 = *b++;
        if ((c1 & 0xc0) != 0x80) return -1; /* not continuation */
        c2 = *b;
        if ((c2 & 0xc0) != 0x80) return -1; /* not continuation */
        return ((c & 0x0f) << 12) | ((c1 & 0x3f) << 6) | (c2 & 0x3f);
case 0xf0:
        if ((c & 0x08) != 0) return -1;
        c1 = *b++;
        if ((c1 & 0xc0) != 0x80) return -1; /* not continuation */
        c2 = *b++;
        if ((c2 & 0xc0) != 0x80) return -1; /* not continuation */
        c3 = *b;
        if ((c3 & 0xc0) != 0x80) return -1; /* not continuation */
        return ((c & 0x07) << 18) | ((c1 & 0x3f) << 12) |
               ((c2 & 0x3f) << 6) | (c3 & 0x3f);
    }
}

void term_unicode_convert(void)
{
/*
 * If you position the caret to the right of (up to) 6 hex digits and
 * go ALT-X then the digits are replaced by single Unicode character.
 * This may (and indeed often will) be a multi-byte character stored in the
 * input buffer in UTF-8 form.
 * There will also be a selection of words so that if you type ALT-X with
 * the caret to the right of the word you get a conversion to a single
 * character. Eg think in terms of names such as "euro" and "alpha". The
 * initial set of names I use is the list of HTML entities.
 *
 * If you are to the right of a character that is a genuine multi-byte
 * UTF-8 sequence or that seems to be in windows-1252-1 (because it has a top
 * bit set but the preceeding bytes would not parse properly for UTF-8) then
 * that character is expanded to a name or to hex. If it is to be expanded to
 * hex it is normally converted to exactly 4 digits - but if the code is
 * too large for that (which is improbable, I believe) it expands to 6.
 *
 * The idea is that ALT-X will cycle between the possible meanings of the
 * input.
 *
 * There are a rather small number of cases where there could be ambiguity.
 * These are coped with by arranging that successive uses of ALT-X cycle
 * through all possibilities.
 * Here are some particular cases that are a nuisance:
 *    "123456"   The issue here is how many hex digits are to be used. The
 *               first choice here will be to use exactly 4, and the
 *               second choice exactly 6. I will only ever process 4 or 6
 *               digits, and I will not accept codes over 10ffff or in the
 *               surrogate region d800-dfff.
 *    "oline"    Choice one is to interpret this "oli" followed
 *               by a "not equal to" symbol. Choice two will be to treat
 *               it as a single name for a "spacing overscore".
 *    "frac12"   Choice one "fr" followed by the Unicode character U+ac12
 *               (a Hangul (Korean) syllable). Two will be to turn it
 *               into a fraction (1/2) symbol.
 * The policy I will attempt to arrange is that all possible interpretations
 * are cycled through, with the original state eventually reinstated.
 *
 * Well let me consider the possible display options by showing illustrations
 * of all the cases. I will write (u+nnnn) to denote a single character. I
 * use "10" here the possible first 2 digits of a 6-digit hex value from
 * 00 to 10, and X for any character that can not lead to special
 * prefixing.
 *
 * X(u+nnnn) 10(u+nnnn) X(u+03b1) (u+00bd)    X(u+203e)    10(u+203e)
 * Xnnnn     10nnnn     Xalpha    frac12      Xoline       10oline
 *           (u+10nnnn) X03b1     fr(u+ac12)  Xoli(u+2260) 10oli(u+2260)
 *                                00bd        Xoli2260     10oli2260
 *                                            X203e        10203e
 *                                                         (u+10203e)
 *
 * I judge that restricting support to only 4 hex digits would not simplify
 * things enough to really transform matters, but I will rely on having
 * all names denote symbolc in the basic multilingual plane.
 *
 * The following transformation rules are designed to cause the code to
 * cycle through all possibilities:
 *                                                            example
 * longest name that matches     -> character       10oline    -> 10(u+203e)
 * 01 to 10 followed by 4 hex    -> character       102030     -> (u+102030)
 * char with name NNNN
 *    NNNN has a suffix          -> split suffix    (u+203e)   -> oli(u+2260)
 *    NNNN has a prefix          -> hex             oli(u+2260)->oli2260
 * char NNMMMM over 0xffff
 *    MMMM has a name            -> NNname          (u+10203e) ->10oline
 *    otherwise                  -> 6 hex           (u+102030) -> 102030
 * char <= 0xffff                -> 4 hex           (i+1234)   -> 1234
 * 4 hex of name with prefix     -> hex expanded    oli2260    -> 203e
 * 4 hex of name                 -> name            203e       -> oline
 * 4 hex of unnamed character    -> character       1234       -> (u+1234)
 */
    int i, n, c;
    const wchar_t *p;
    if (insert_point == prompt_length)
    {   term_bell();
        return;
    }
/*
 * I will first see if I can find a name, and I will look for long ones first.
 */
    for (n=8; n>=2; n--) /* word length to seek */
    {   if (prompt_length+n>insert_point) continue; /* not this many chars */
        for (i=0; i<n; i++)
            input_word[i] = input_line[insert_point-n+i];
        input_word[n] = 0;           /* extract the (potential) word */
        c = lookup_wide_name(input_word);
        if (c == -1) continue;    /* not a recognised name */
        output_word[0] = c;   /* replace word by a single character */
        output_word[1] = 0;
        term_replace_chars_backwards(n, output_word);
        return;
    }
/*
 * Next check for a 6-digit hex value. Note that the first two digits
 * must be 01, 02, ... 0f, 10. If you had "00" there then there was no
 * point in using a 6-digit format. If you have any value beyond "10" you
 * are outside the Unicode range.
 */
    if (insert_point - prompt_length >= 6)
    {   p = &input_line[insert_point-6];
        if ((p[0] == '0' && iswxdigit(p[1]) && p[1] != '0') ||
            (p[0] == '1' && p[1] == '0'))
        {   c = (hexval(p[0]) << 4) | hexval(p[1]);
/*
 * By virtue of packing up digits here using OR it will be the case that
 * if ANY of the calls to hexval return a negative value I can be certain
 * that the overall result will be negative.
 */
            for (i=2; i<6 && c > 0; i++)
            {   n = hexval(p[i]);
                c = (c << 4) | n;
            }
            if (c > 0)
            {   output_word[0] = c;
                output_word[1] = 0;
                term_replace_chars_backwards(6, output_word);
                return;
            }
        }
    }   
/*
 * In the next two cases the character before the caret has a name
 * associated with it. Well first I will just extract a Unicode character
 * from before the caret.
 */
    if (insert_point - prompt_length >= 1)
        n = 1,
        c = input_line[insert_point-1];
    else n = 0, c = -1;
/*
 * See if the character has a name.
 */
    p = wide_lookup_code(c);
/*
 * Now I have two messy cases to detect. The first is if the name
 * I have just found has a shorter name as a terminal sub-string. The second
 * is if the name is a suffix of something longer and the prefix part happens
 * to be in the buffer ahead of it. These two cases could both happen together
 * if there were say names ABC, BC and just C in the list of entities, but
 * I am glad to say that that is not the case. Beware if you ever add new
 * entity-names! I will test for these cases in a pretty crude manner.
 */
    if (p != NULL)
    {   int w = -1;
        const wchar_t *p1 = p+1;
        while (*p1 != 0)
        {   w = lookup_wide_name(p1);
            if (w != -1) break;    /* Found a suffix */
            p1++;
        }
/*
 * The code here will convert (u+203e) to oli(u+2260) via expanding to
 * the name "oline" and then re-coding the last two letters "ne". And
 * a whole pile of other similar cases such Eaccute, rang, Theta, lfloor,
 * ntilde, otimes and Yuml. I count 57 cases in the HTML 4 entity table.
 */
        if (w != -1)
        {   wcscpy(output_word, p);
            output_word[p1-p] = w;
            output_word[p1-p+1] = 0;
            term_replace_chars_backwards(n, output_word);
            return;
        }
/*
 * Now there is the possible conversion the other way, where (for example)
 * oli(u+2260) is in the buffer. If I merely expanded the unicode character
 * to its name here I would end up with "oline" and the next ALT-X would
 * convert that to (u+203e) - I would never get to see thing in hex form.
 * So in this case I merely expand the character to 4 hex digits.
 */
        for (i=1; i+wcslen(p)<9; i++)
        {   /* i is the number of prefix characters to test for */
            if (insert_point - prompt_length >= i+n)
            {   memcpy(input_word, &input_line[insert_point-i-n], i*sizeof(wchar_t));
                wcscpy(&input_word[i], p);
/*
 * I have now concatenated some stuff from the input buffer with the
 * expanded character name and look it up. If I find a match I will
 * convert the character to hex. Because the character itself was one
 * with a name it will fit within 4 digits.
 */
                if (lookup_wide_name(input_word) != -1)
                {   swprintf(output_word, 16, L"%.4x", c);
                    term_replace_chars_backwards(n, output_word);
                    return;
                }
            }
        }
    }
/*
 * Here I have a character with code c and I am not processing any
 * name it might have just now. However maybe its low 16 bits is a named
 * character. In which case turn the low 16 bits into that name, leaving
 * two digits of hex code ahead of that.
 */
    if (c > 0xffff && (p = wide_lookup_code(c & 0xffff)) != NULL)
    {   swprintf(output_word, 16, L"%.2x%ls", (c >> 16) & 0x3f, p);
        term_replace_chars_backwards(n, output_word);
        return;
    }
/*
 * Character up to u+ffff turns into hex (except that plain ASCII characters
 * do not need that, and if I tried to convert them here that would conflict
 * with their use in hex numeric representation.
 */
    if (c > 0x7f && c <= 0xffff)
    {   swprintf(output_word, 16, L"%.4x", c);
        term_replace_chars_backwards(n, output_word);
        return;
    }
/*
 * The case I look at now all have 4 hex digits ahead of the insertion
 * point.
 */
    if (insert_point - prompt_length >= 4 &&
        iswxdigit(input_line[insert_point-4]) &&
        iswxdigit(input_line[insert_point-3]) &&
        iswxdigit(input_line[insert_point-3]) &&
        iswxdigit(input_line[insert_point-1]))
    {   c = hexval(input_line[insert_point-4]);
        c = (c << 4) | hexval(input_line[insert_point-3]);
        c = (c << 4) | hexval(input_line[insert_point-2]);
        c = (c << 4) | hexval(input_line[insert_point-1]);
/*
 * Now c is the integer corresponding to the 4 hex digits. If it is in the
 * range 0xd800 to 0xdfff it would be a surrogate - in that case I will
 * reject it. I need to see if the code has an associated name.
 */
        if (c < 0 || c < 0xd800 || c > 0xdfff)
        {   if ((p = wide_lookup_code(c)) != NULL)  /* yes it does! */
            {
/*
 * Now if the buffer contains characters that would form a prefix to the
 * name I just found I will convert to the hex representation of the
 * character corresponding to the longer name.
 * This prefix processing is rather similar to a case considered earlier.
 */
                for (i=1; i+wcslen(p)<9; i++)
                {   /* i is the number of prefix characters to test for */
                    int c1;
                    if (insert_point - prompt_length >= i+4)
                    {   memcpy(input_word, &input_line[insert_point-i-4], i*sizeof(wchar_t));
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
            output_word[0] = c;
            output_word[1] = 0;
            term_replace_chars_backwards(4, output_word);
            return;
        }
    }
/*
 * If I do not recognise any of the situations I will give an alert and
 * not change the buffer at all.
 */
    term_bell();
}


static void term_interrupt(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^C>");
    term_redisplay();
}


static void term_noisy_interrupt(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^G>");
    term_redisplay();
}


static void term_pause_execution(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<^Z>");
    term_redisplay();
}


static void term_exit_program(void)
{
    exit(0);
}


static void term_edit_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&E>");
    term_redisplay();
}


static void term_file_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&I>");
    term_redisplay();
}


static void term_module_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&M>");
    term_redisplay();
}


static void term_font_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&O>");
    term_redisplay();
}


static void term_break_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&B>");
    term_redisplay();
}


static void term_switch_menu(void)
{
/* @@@@@ */
    insert_point += swprintf(&input_line[insert_point],
        input_line_size-insert_point, L"<&S>");
    term_redisplay();
}


/****************************************************************************/

#ifdef SOLARIS
/*
 * the tparm function on Solaris bites me, as it has bitten many people
 * before. On a 64-bit machine the prototype requires a load of arguments,
 * most of which will often be ignored. On a 32-bit system it can cope with
 * only the args that are needed. At one time I had two calls one with
 * all the extra args and one not, with "if (sizeof(void *)==8)" to select
 * which to use, but a recent test has shown a compiler on Solaris treating
 * the odd number of args (even in code that could never be executed) as
 * an ERROR not just a WARNING. So for now I will try passing the junk
 * extra args and keeping fingers crossed.
 */

static void solaris_foreground(int n)
{
    if (set_a_foreground)
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

/*
 * This will need a wide-character variant...
 */

static wchar_t *term_wide_fancy_getline(void)
{
    int ch, any_keys = 0, i;
#ifdef WIN32
    SetConsoleMode(stdout_handle, 0);
#else
    my_reset_prog_mode();
#endif
/*
 * I am going to take strong action to ensure that the prompt appears
 * at the left-hand side of the screen.
 */
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
/*
 * First ensure there is space in the buffer. In some cases maybe putting
 * the test here is marginally over-keen, since the keystroke entered
 * might not be one that was going to add a character. But it is harmless
 * to be safe! If I need to extend the buffer and I fail then I just
 * give up and return an error marker. Note that the insert_point may not
 * be at the end of the line, so I use wcslen() to find out how long the
 * line actually is.
 */
        n = wcslen(input_line);
/*
 * The curious activity here is to ensure that the buffer would not overflow
 * even if the "regular" part of it was replaced by the longest line
 * that can possibly get into the history-record.
 */
        if (n > longest_history_line) longest_history_line = n;
        if (searchFlags != 0)
            n = n - regular_line_end + longest_history_line;
        if (n >= input_line_size-20)
        {   input_line = (wchar_t *)realloc(input_line, 2*input_line_size*sizeof(wchar_t));
            display_line = (wchar_t *)realloc(display_line, 2*input_line_size*sizeof(wchar_t));
            if (input_line == NULL || display_line == NULL)
            {   input_line_size = 0;
                set_normal();
                return NULL;
            }
            else input_line_size = 2*input_line_size;
        }
/*
 * There are cases where I need to treat characters specially:
 *   (1) I am in the middle of a history search, and the
 *       character is thus to be treated as part of the incremental
 *       string, unless it terminates the search;
 */
        if (searchFlags != 0 &&
            term_search_char(ch)) continue;
/*
 * term_search_char will return true if it has handled the character and thus
 * searching continues. It returns false if it has exited search mode and the
 * key must now be treated as if it was a "normal" non-search one.
 */
#ifdef TEST
/*
        fprintf(stderr, "process character %#x\n", ch);
        fflush(stderr);
*/
#endif
        switch (ch)
        {
    case EOF:
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
    case 0x7f:     /* The "delete backwards" key, I hope */
            term_delete_backwards();
            continue;
/*
 * I treat tab as an "ordinary" character here, so it just gets inserted
 * into the input line. This is achieved by letting it hit the "default" case
 * in this switch block!
 *
 *  case CTRL('I'):
 *          goto default;
 */
    case CTRL('J'):                     /* line-feed */
            break;
    case CTRL('K'):
            term_kill_line();
            continue;
    case CTRL('L'):
            term_clear_screen();
            continue;
    case CTRL('M'):                     /* carriage return, ENTER */
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
/*
 * (already dealt with)
 *  case CTRL('['):          ESC
 */
    case CTRL('\\'):
            set_shell();
            term_exit_program();
            /* No return */
    case CTRL(']'):
            continue;        /* Ignored */
    case CTRL('_'):
            continue;        /* Ignored */
    case CTRL('^'):
            term_reinput();
            continue;
    case CTRL('@') + ALT_BIT:
            term_set_mark();
            continue;
/*
 * When a character is combined with ALT (or prefixed with ESC) I will in
 * at least very nearly every case ignore whether it is upper or lower case
 * or whether CTRL is pressed too. In a rather few cases I will let CTRL
 * take precedence over ALT...
 */
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
    case 0x7f+ALT_BIT:   /* Under X maybe the key above ENTER that I use to .. */
    case 0xff+ALT_BIT:   /* delete things will return 0x7f. */
            term_delete_word_backwards();
            continue;
    case CTRL('I') + ALT_BIT: case 'I' + ALT_BIT: case 'i' + ALT_BIT:
            term_file_menu();
            continue;
    case CTRL('J') + ALT_BIT: case 'J' + ALT_BIT: case 'j' + ALT_BIT:  /* line-feed */
            break;
    case CTRL('K') + ALT_BIT: case 'K' + ALT_BIT: case 'k' + ALT_BIT:
            term_kill_line();
            continue;
    case CTRL('L') + ALT_BIT: case 'L' + ALT_BIT: case 'l' + ALT_BIT:
            term_lowercase_word();
            continue;
    case CTRL('M') + ALT_BIT:              /* carriage return, ENTER */
            break;
    case 'M' + ALT_BIT: case 'm' + ALT_BIT:  /* ALT-^M differs from ALT-M, ALT-m */
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
            continue;   /* Ignored */
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
/*
 * (already dealt with)
 *  case CTRL('[') + ALT_BIT:               ESC
 */
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
    case '[' + ALT_BIT:   /* ESC-[ */
            /* Should never be delivered here */
            continue;
    case '\\' + ALT_BIT:
            term_exit_program();
            /* no return */
    case ']' + ALT_BIT:
            continue;
    case '_' + ALT_BIT:
            term_copy_previous_word();
            continue;
    case '{' + ALT_BIT:
            continue;  /* Ignored */
    case '^' + ALT_BIT:
            term_reinput();
            continue;
    case '}' + ALT_BIT:
            continue;  /* Ignored */
    default:
/*
 * Here I need to insert a character into the buffer. I may not be inserting
 * at the end, so I perhaps have to shuffle existing stuff upwards.
 */
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
/*
 * Put the cursor at the start of the final line of displayed (wrapped)
 * input before moving back to normal screen mode.
 */
    term_move_first_column();
    term_move_down(final_cursory-cursory);
    set_normal();
    term_putchar(L'\n');
    fflush(stdout);
    insert_point = wcslen(input_line);
    if (insert_point==prompt_length && ch==EOF) return NULL;
/*
 * Stick the line into my history record: WITHOUT any newline at its end.
 */
    input_line[insert_point] = 0;
    input_history_add(input_line+prompt_length);
/*
 * Adding an entry could cause an old one to be discarded. So I now ensure
 * that I know what the first and last recorded numbers are.
 */
    historyLast = input_history_next - 1;
    historyFirst = input_history_next - INPUT_HISTORY_SIZE;
    if (historyFirst < 0) historyFirst = 0;
    historyNumber = historyLast + 1; /* so that ALT-P moves to first entry */
/*
 * Whether the user terminated the line with CR or LF I will always
 * return "\n" to the program.
 */
    input_line[insert_point++] = L'\n';
    input_line[insert_point] = 0;
    return input_line + prompt_length;
}

#endif /* DISABLE */

wchar_t *term_wide_getline(void)
{
    if (!term_enabled) return term_wide_plain_getline();
    else return term_wide_fancy_getline();
}

char *term_getline(void)
{
    wchar_t *r = term_wide_getline();
    if (r == NULL) return NULL;
/*
 * To get a "narrow char" line I read a wide char line and then preserve
 * all characters whose codepoints are in the range 0x00 to 0xff and
 * replace all others with a question mark. This leaves me the first 256
 * codepoints of Unicode and that covers ordinary ASCII plus a bunch of
 * diacriticals. Consider how the code here fits in with struct aliasing
 * rules. It may sail a little close to the edge but I think it may be legal!
 */
    char *p = (char *)r;
    wchar_t *q = r;
    int c;
    while ((c = *q++) != 0)
    {   if (c > 0xff) c = '?';
        *p++ = c;
    }
    *p = 0;
    return (char *)r;
}

#ifdef RECORD_KEYS
/*
 * This abomination is here to permit me to collect the key-sequences
 * that a whole bunch of things generate for me. I do not guarantee that
 * it will always work, but when it does it may be useful!
 */

static void record_keys(void)
{
    static char *keys[] =
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
{
    term_setup(1, NULL);
//    def_prog_mode();
    record_keys();
//    reset_shell_mode();
    term_close();
    return 0;
}

#endif

/* end of file termed.c */
