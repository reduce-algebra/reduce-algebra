/* termed.c                          Copyright (C) 2004-2008 Codemist Ltd */

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
 * Note that the above apply even when part of this code is used within
 * an LGPL library such as FOX, even though binaries built from the
 * complete work are subject to the LGPL.
 */


/* Signature: 2fb781ef 24-May-2008 */

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

#ifdef HAVE_NCURSES_TERM_H
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
#include <ctype.h>
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

/*
 * The default values set here can be changed as a result of the colour
 * option passed to term_setup.
 */
static int promptColour = 4;   /* Blue */
static int inputColour  = 1;   /* Red */
static int outputColour = -1;  /* whatever user had been using */

#ifndef DEBUG

#define LOG(a)

#else

#include <stdarg.h>

static FILE *logfile = NULL;

static void write_log(char *s, ...)
{
    va_list x;
    if (logfile == NULL) logfile = fopen("log.log", "w");
    va_start(x, s);
    vfprintf(logfile, s, x);
    va_end(x);
}

#define LOG(a) write_log a;

#endif


/*
 * My support for a history mechanism here is really primitive and simple.
 * I have a fixed size history buffer and just dump strings into it.
 */

char *input_history[INPUT_HISTORY_SIZE];
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

void input_history_add(const char *s)
{
/* Make a copy of the input string... */
    char *scopy = (char *)malloc(strlen(s) + 1);
    int p = input_history_next % INPUT_HISTORY_SIZE;
/* If malloc returns NULL I just store an empty history entry. */
    if (scopy != NULL) strcpy(scopy, s);
/*
 * I can overwrite an old history item here... I will keep INPUT_HISTORY_SIZE
 * entries.
 */
    if (input_history[p] != NULL) free(input_history[p]);
    input_history[p] = scopy;
    input_history_next++;
    if (scopy != NULL)
    {   p = strlen(scopy);
        if (p > longest_history_line) longest_history_line = p;
    }
}

const char *input_history_get(int n)
{
    const char *s;
/*
 * Filter our values that are out of range and in those cases return NULL
 * as a flag to report the error.
 */
    if (n == input_history_next) return "";
    if (n < 0 ||
        n >= input_history_next ||
        n < input_history_next-INPUT_HISTORY_SIZE) return NULL;
    s = input_history[n % INPUT_HISTORY_SIZE];
/* The NULL here would be if malloc had failed earlier. */
    if (s == NULL) return "";
    else return s;
}

/*
 * Sort of beware! I have fields in the class FXTerminal with the same
 * names as these (static) variables and serving the same purpose (but for
 * windowed applications). Do not get confused please. The two sets of
 * values should never be active at the same time. Itf I were cleverer I
 * would have found a good way to share more of the code and avoid
 * this potential muddle.
 */
static int historyFirst, historyNumber, historyLast;
static int searchFlags; 


static const char *prompt_string = ">";
static char *input_line, *display_line;
static int prompt_length = 1, input_line_size;

/*
 * term_plain_getline() can be called when cursor addressing is not
 * available. It just reads characters into a line-buffer (which it
 * extends as necessary). The data returned includes the newline
 * that terminated the line. If an error is detected (and in particular
 * at end of file) the value NULL is raturned rather than a pointer to
 * an array of characters.
 *
 * Nothing at all is done here to fuss about special characters, so
 * things like ^C, backspace, ^Q etc etc etc are handled, if at all, by
 * the system that underpins "getchar".
 */

static char *term_plain_getline(void)
{
    int n, ch;
#ifdef TEST
    fprintf(stderr, "plain_getline:");
    fflush(stderr);
#endif
    printf("%.*s", prompt_length, prompt_string);
    fflush(stdout);
    if (input_line_size == 0) return NULL;
    input_line[0] = 0;
    for (n=0, ch=getchar(); ch!=EOF && ch!='\n'; n++, ch=getchar())
    {   if (n >= input_line_size-20)
        {  input_line = (char *)realloc(input_line, 2*input_line_size);
           if (input_line == NULL)
           {   input_line_size = 0;
               return NULL;
           }
           else input_line_size = 2*input_line_size;
        }
        input_line[n] = ch;
        input_line[n+1] = 0;
    }
    if (n==0 && ch==EOF) return NULL;
    input_line[n++] = ch;
    input_line[n] = 0;
    return input_line;
}

/*
 * Before calling term_getline() or its variants use this to set the
 * prompt string that will be displayed. You should leave the string that
 * is passed unchanged until after input that uses it has been grabbed.
 * A prompt string longer than the width of the terminal is liable to lead
 * to bad confusion.
 */

#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 80
#endif

void term_setprompt(const char *s)
{
    prompt_string = s;
    prompt_length = strlen(s);
/*
 * I truncate prompts if they are really ridiculous in length since otherwise
 * it may look silly.
 */
    if (prompt_length > MAX_PROMPT_LENGTH) prompt_length = MAX_PROMPT_LENGTH;
}

#ifdef DISABLE
/*
 * In some cases this code can not be activated because not enough
 * libraries are available. In that case I will provide stubs that do
 * non-clever input. It may be that an external package or body of code
 * will still be providing a good environment for the user.
 */

/*
 * Start up input through this package. Returns 0 in this case because
 * local editing is not supported on this platform. Hence the colour
 * option is ignored.
 */

int term_setup(int flag, const char *colour)
{
    input_line = (char *)malloc(200);
    if (input_line == NULL) input_line_size = 0;
    else input_line_size = 200;
    return 0;
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

char *term_getline(void)
{
    return term_plain_getline();
}

#else /* DISABLED */

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
    putchar(c);
}

static void putp(char *s)
{
   tputs(s, 1, putpc);
}

static struct termios shell_term, prog_term, shell_term_o, prog_term_o;

static void def_shell_mode(void)
{
    fflush(stdout);
    tcgetattr(stdin_handle, &shell_term);
    tcgetattr(stdout_handle, &shell_term_o);
}

static void reset_shell_mode(void)
{
    fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &shell_term);
    tcsetattr(stdout_handle, TCSADRAIN, &shell_term_o);
    fflush(stdout);
}

static void def_prog_mode(void)
{
    fflush(stdout);
    tcgetattr(stdin_handle, &prog_term);
    tcgetattr(stdout_handle, &prog_term_o);
}

static void reset_prog_mode(void)
{
    fflush(stdout);
    tcsetattr(stdin_handle, TCSADRAIN, &prog_term);
    tcsetattr(stdout_handle, TCSADRAIN, &prog_term_o);
}


#endif

#ifdef RAW_CYGWIN
static void reset_shell(void)
{
/* This still does not seem to do what I want... */
    struct termios w;
    reset_shell_mode();
    tcgetattr(stdin_handle, &w);
    w.c_oflag |= OPOST | ONLCR;
    tcsetattr(stdin_handle, TCSADRAIN, &w);
    tcgetattr(stdout_handle, &w);
    w.c_oflag |= OPOST | ONLCR;
    tcsetattr(stdout_handle, TCSADRAIN, &w);
}
#else
#define reset_shell() reset_shell_mode();
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

static int term_enabled;

static int cursorx, cursory, final_cursorx, final_cursory, max_cursory;
static int insert_point;

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

static void term_putchar(int c)
{
#ifdef WIN32
    DWORD nbytes;
    char buffer[1];
    buffer[0] = c;
    WriteFile(stdout_handle, buffer, 1, &nbytes, NULL);
#else
    putchar(c);
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
    LOG(("[screen:%dx%d]", columns, lines));
}

#ifdef WIN32
static const char *expanded_char_sequence = NULL;
#else
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

#endif
#endif /* WIN32 */

int term_setup(int flag, const char *colour)
{
#ifdef WIN32
    DWORD w;
    CONSOLE_SCREEN_BUFFER_INFO csb;
    term_enabled = 0;
    term_colour = (colour == NULL ? "-" : colour);
    expanded_char_sequence = NULL;
    input_line = (char *)malloc(200);
    display_line = (char *)malloc(200);
    if (input_line == NULL || display_line == NULL)
    {   input_line_size = 0;
        return 1;
    }
    else input_line_size = 200;
    if (!flag) return 1;
/*
 * Standard input must be from a character device and must be accepted
 * by the GetConsoleMode function
 */
    stdin_handle = GetStdHandle(STD_INPUT_HANDLE);
    if (GetFileType(stdin_handle) != FILE_TYPE_CHAR) return 1;
    if (!GetConsoleMode(stdin_handle, &w)) return 1;
/*
 * Standard output must be a character device and a ConsoleScreenBuffer
 */
    stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetFileType(stdout_handle) != FILE_TYPE_CHAR) return 1;
    if (!GetConsoleScreenBufferInfo(stdout_handle, &csb) ||
        !GetConsoleMode(stdin_handle, &stdin_attributes) ||
        !GetConsoleMode(stdout_handle, &stdout_attributes)) return 1;
    plainAttributes = csb.wAttributes;
    revAttributes = plainAttributes ^
      (FOREGROUND_RED | BACKGROUND_RED |
       FOREGROUND_GREEN | BACKGROUND_GREEN |
       FOREGROUND_BLUE | BACKGROUND_BLUE |
       FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
    promptAttributes = plainAttributes ^ FOREGROUND_BLUE;
    inputAttributes = plainAttributes ^ FOREGROUND_RED;
    if (!SetConsoleMode(stdout_handle, 0)) return 1;
    if (!SetConsoleMode(stdin_handle,
        ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT)) return 1;
    columns = csb.srWindow.Right - csb.srWindow.Left + 1;
    lines = csb.srWindow.Bottom - csb.srWindow.Top + 1;
    SetConsoleMode(stdout_handle, stdout_attributes);
    term_can_invert = 1;
#else /* WIN32 */
    int errval, errcode;
    char *s;
    struct termios my_term;
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
    input_line = (char *)malloc(200);
    display_line = (char *)malloc(200);
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
 * reset_shell_mode() can put things back the way they were.
 */
    def_shell_mode();
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
    def_prog_mode();
#ifdef RECORD_KEYS
    record_keys();
#endif
    reset_shell();
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
    {   reset_shell();
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

#ifdef WIN32
static INPUT_RECORD keyboard_buffer[1] = {{0}};
#endif

/*
 * term_getchar() will block until the user has typed something. I will use
 * this place as where I unravel various funny escape sequences that
 * stand for uses of control keys. For all cases I will hand back an 8-bit
 * "basic character", but I will then OR in 0x100 if ALT was pressed with it
 * and 0x200 if it is not a simple key but a value returned to indicate a
 * function key, arrow key etc etc. Regardless of the meaning of bits
 * ORd in I will hand back EOF in some boundary cases. When using a Unix-
 * style terminal (rather than Windows) I will just ignore invalid or
 * unrecognized escape systems sent by the lowever level terminal drivers.
 */

#define TERM_UP     'A'
#define TERM_DOWN   'B'
#define TERM_RIGHT  'C'
#define TERM_LEFT   'D'
#define TERM_DELETE 'x'
#define TERM_HOME   '1'
#define TERM_END    '2'
#define TERM_INSERT 'y'

static int term_getchar(void)
{
#ifdef WIN32
    DWORD n;
    int down, key, ascii, ctrl;
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
    	    ctrl = keyboard_buffer[0].Event.KeyEvent.dwControlKeyState;
/*
 * If Windows thinks that the key that has been hit corresponded to an
 * ordinary character than I will just return it. No hassle here! Well
 * not quite so easy after all. If ALT is held down at the same time as
 * the character I will or in the 0x100 bit.
 *
 * Ha Ha! "ascii==0" would apply in the case of "^@". By experiment the
 * notionally system independent key-code for "@" is 0xc0 (well I can worry
 * in case that is really for "'") do I test for that. Anyway at least
 * with my keyboard this lets "^@" get through!
 */
            if (key != 0x11) LOG(("\nascii=%x VK=%x ctrl=%x\n", ascii, key, ctrl));
            if (ascii != 0 || key == 0xc0)
            {   if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED))
                    ascii |= 0x100;
                return ascii;
            }
/*
 * Now use the variable "ascii" to record the state of the ALT key.
 */
            if (ctrl & (LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED)) ascii = 0x100;
            else ascii = 0;
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
                return ascii | TERM_LEFT | 0x200;
    case VK_RIGHT:
                return ascii | TERM_RIGHT | 0x200;
    case VK_UP:
                return ascii | TERM_UP | 0x200;
    case VK_DOWN:
                return ascii | TERM_DOWN | 0x200;
    case VK_HOME:
                return ascii | TERM_HOME | 0x200;
    case VK_END:
                return ascii | TERM_END | 0x200;
    case VK_DELETE:
                return ascii | TERM_DELETE | 0x200;
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
    {   ch = getchar();
        LOG(("RAW ch=%.2x : <%c>\n", ch, ch | 0x40));
        if (ch == EOF) return EOF;
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
 * "meta" bit 0x100.
 */
            if (ch == 0x1b)
            {   esc_esc ^= 0x100;
                continue;
            }
            else if (ch == '[')
            {   state = ESC_BR_STATE;
                continue;
            }
            else return ch | 0x100;
    case ESC_BR_STATE:
/*
 * After "ESC [" I absorb digits and semicolons.
 */
            if (isdigit(ch))
            {   numval1 = 10*numval1 + ch - '0';
                continue;
            }
            else if (ch == ';')
            {   numval2 = numval1;
                numval1 = 0;
                continue;
            }
/*
 * Now the whole code can be put together as one item...
 */
            ch = ch | (numval2 << 16) | (numval1 << 8);
/*
 * The table here represents the codes that I have come across thus far:
 */
            esc_esc |= 0x200;
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
        case 0x010300+'A': return 0x300 | TERM_UP;
        case 0x010300+'B': return 0x300 | TERM_DOWN;
        case 0x010300+'C': return 0x300 | TERM_RIGHT;
        case 0x010300+'D': return 0x300 | TERM_LEFT;
        case 0x030300+'~': return 0x300 | TERM_DELETE;
        case 0x010300+'H': return 0x300 | TERM_HOME;
        case 0x010300+'F': return 0x300 | TERM_END;
        case 0x020300+'~': return 0x300 | TERM_INSERT;
        default:           return 0x100 | ch;
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
#ifdef WIN32 /* OK */
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
 * ... otherwise I position the cursor by doing dull sequences trhat move the
 * cursor one positiomn at a time.
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
 * The main complications thar arise are
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
 * taking care of line-wrapping.
 */

static int line_wrap(int ch, int tab_offset)
{
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
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, stdout_attributes);
#else
            reset_shell();
#endif
            term_putchar('\n');
            fflush(stdout);
#ifdef WIN32
            SetConsoleMode(stdout_handle, 0);
#else
            reset_prog_mode();
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
        if (ch == '\t')
        {   do
            {   finx++;
                if (finx >= columns)
                {   tab_offset += finx;
                    finx -= columns;
                    finy++;
                }
            } while ((tab_offset + finx)%8 != 0);
        }
        else if (ch == '\n')
        {   tab_offset = 0;
            finx = 0;
            finy++;
        }
        else if (ch < 0x20) finx += 2;
        else if (ch < 0x7f) finx += 1;
        else finx += 4;
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
 */
        if (ch == '\t')
        {   do
            {   tab_offset = line_wrap(' ', tab_offset);
            } while ((tab_offset + cursorx)%8 != 0);
        }
        else if (ch == '\n')
        {
/*
 * Here I want a line-break in the "single line" I am displaying. I achieve
 * the effect I want by writing blanks until cursorx gets back to zero by
 * virtue of line-wrapping!
 */
            while (cursorx !=  0) line_wrap(' ', 0);
/*
 * Tabs should now be relative to the new line-start.
 */
            tab_offset = 0;
        }
        else if (ch < 0x20)
        {   tab_offset = line_wrap('^', tab_offset);
            /* Turn into @, A, B etc */
            tab_offset = line_wrap(ch | 0x40, tab_offset);
        }
        else if (ch <= 0x7f) tab_offset = line_wrap(ch, tab_offset);
        else
        {   char b[5];
/*
 * Characters from 0x7f to 0xff are displayed as "[dd]" with 2 hex digits.
 * This may not be a universal standard notation and it does mean that any
 * characters in that range that are desirable (eg maybe some accented
 * letters) do not get displayed. But it avoids risk of
 */
            int j;
            sprintf(b, "[%.2x]", ch);
            for (j=0; j<4; j++) tab_offset = line_wrap(b[j], tab_offset);
        }
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
/*
 * record where real output finished this time
 */
    final_cursorx = finx;
    final_cursory = finy;
/*
 * Move the cursor to where it needs to appear.
 */
    term_move_down(cury-cursory);
    term_move_right(curx-cursorx);
    fflush(stdout);
/*
 * Now the display should be up to date, so record that situation.
 */
    strcpy(display_line, input_line);
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
             (isalnum(input_line[n]) || input_line[n] == '_'));
    while (input_line[n] != 0 && isspace(input_line[n])) n++;
    return n;
}

static int term_find_next_word_backwards(void)
{
    int n = insert_point;
    if (n == prompt_length) return n;
    do
    {   n--;
    } while (n != prompt_length &&
             (isalnum(input_line[n]) || input_line[n] == '_'));
    while (n != prompt_length && isspace(input_line[n])) n--;
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
    else while (input_line[i] != 0)
    {   input_line[i] = input_line[i+1];
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
        while (input_line[i] != 0)
        {   input_line[i] = input_line[i+1];
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
        while (input_line[i] != 0)
        {   input_line[i] = input_line[i+n];
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
        while (input_line[i] != 0)
        {   input_line[i] = input_line[i+n];
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
    const char *history_string;
    if (historyLast == -1)
    {   term_bell();
        return;
    }
    if (historyNumber < historyLast) historyNumber++;
    if ((history_string = input_history_get(historyNumber)) == NULL)
    {   term_bell();
        return;
    }
    insert_point = strlen(history_string);
    strncpy(input_line+prompt_length, history_string, insert_point);
    insert_point += prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static void term_previous_history(void)
{
    const char *history_string;
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
    insert_point = strlen(history_string);
    strncpy(input_line+prompt_length, history_string, insert_point);
    insert_point += prompt_length;
    input_line[insert_point] = 0;
    refresh_display();
}


static int regular_line_end = 0;
static int search_saved_point = 0;
static int search_found = 0;
static char searchBuff[100];
static int searchStack[100];
static int searchLen;

static void term_search_next(void)
{
/*
 * I remember where I was on the input line but then move to the end and
 * append a message that indicates to the user that a search is in progress.
 */
    search_found = search_saved_point = insert_point;
    regular_line_end = strlen(input_line);
    strcpy(&input_line[regular_line_end], "\nN-search: ");
    insert_point = regular_line_end + 11;
    searchLen = 0;
    searchBuff[0] = 0;
    searchFlags = 1;
    refresh_display();
}


static void term_search_previous(void)
{
    search_found = search_saved_point = insert_point;
    regular_line_end = strlen(input_line);
    strcpy(&input_line[regular_line_end], "\nP-search: ");
    insert_point = regular_line_end + 11;
    searchLen = 0;
    searchBuff[0] = 0;
    searchFlags = -1;
    refresh_display();
}

static int matchString(const char *pat, int n, const char *text)
{
/*
 * This is a crude and not especially efficient pattern match. I think
 * it should be good enough for use here! I make it return the offset where
 * a match first occurred (if one does) in case that will be useful to me
 * later. I could put the cursor there, perhaps?
 */
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


static int trySearch(void)
{
    int r = -1;
    const char *history_string = input_history_get(historyNumber);
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
static void set_input(const char *s)
{
    strcpy(&input_line[prompt_length], s);
    insert_point = prompt_length + strlen(s);
    regular_line_end = insert_point;
    input_line[insert_point++] = '\n';
    input_line[insert_point++] = searchFlags > 0 ? 'N' : 'P';
    strcpy(&input_line[insert_point], "-search: ");
    insert_point += 9;
    strcpy(&input_line[insert_point], searchBuff);
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
case CTRL('N') + 0x100: case 'N' + 0x100: case 'n' + 0x100:
case 0x200 + TERM_DOWN + 0x100:
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
 * ALT-P and ALT-Up continue the search using the current search string
 * but searching through the Previous history item
 */
case CTRL('P') + 0x100: case 'P' + 0x100: case 'p' + 0x100:
case 0x200 + TERM_UP + 0x100:
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
case CTRL('H'):
case 0x7f:
case 0xff:
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
        if ((ch & 0x300) != 0 ||
            (ch != '\t' && ch<0x20) ||
            ch > 0x7f)
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
 * facility, which I think I am not abou to.
 */
            return (ch & 0x7f) == CTRL('U');
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
           (isalnum(input_line[n]) || input_line[n]=='_')) n--;
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
           (isalnum(input_line[n]) || input_line[n]=='_')) n++;
    return n;
}

static void term_capitalize_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    if (a < b) input_line[a] = toupper(input_line[a]);
    for (i=a+1; i<b; i++) input_line[i] = tolower(input_line[i]);
    refresh_display();
}


static void term_lowercase_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++) input_line[i] = tolower(input_line[i]);
    refresh_display();
}


static void term_uppercase_word(void)
{
    int a = term_find_word_start();
    int b = term_find_word_end();
    int i;
    for (i=a; i<b; i++) input_line[i] = toupper(input_line[i]);
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
    insert_point += sprintf(&input_line[insert_point], "<^U>");
    term_bell();
}


static void term_quoted_insert(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^V>");
    term_bell();
}


static void term_copy_previous_word(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^W>");
    term_bell();
}


static void term_copy_region(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&W>");
    term_bell();
}


static void term_yank(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^Y>");
    term_bell();
}


static void term_reinput(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^R>");
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


static void term_extended_command(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^X>");
    term_bell();
    term_redisplay();
}


static void term_obey_command(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&X>");
    term_bell();
    term_redisplay();
}


static void term_interrupt(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^C>");
    term_redisplay();
}


static void term_noisy_interrupt(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^G>");
    term_redisplay();
}


static void term_pause_execution(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<^Z>");
    term_redisplay();
}


static void term_exit_program(void)
{
    exit(0);
}


static void term_edit_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&E>");
    term_redisplay();
}


static void term_file_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&I>");
    term_redisplay();
}


static void term_module_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&M>");
    term_redisplay();
}


static void term_font_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&O>");
    term_redisplay();
}


static void term_break_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&B>");
    term_redisplay();
}


static void term_switch_menu(void)
{
/* @@@@@ */
    insert_point += sprintf(&input_line[insert_point], "<&S>");
    term_redisplay();
}


/****************************************************************************/

#if defined SOLARIS && SIZEOF_VOID_P==8
/* This is pretty horrible! Sorry. */
#define PAD_TPARM ,0,0,0,0,0,0,0,0
#else
#define PAD_TPARM
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
    if (set_a_foreground) putp(tparm(set_a_foreground, n PAD_TPARM));
    else if (set_foreground) putp(tparm(set_foreground, n PAD_TPARM));
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
    else if (set_a_foreground) putp(tparm(set_a_foreground, 0 PAD_TPARM));
    fflush(stdout);
    reset_shell();
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
    else if (set_a_foreground) putp(tparm(set_a_foreground, 0 PAD_TPARM));
    fflush(stdout);
    reset_shell();
#endif
}

static char *term_fancy_getline(void)
{
    int ch;
#ifdef TEST
    fprintf(stderr, "term_fancy_getline\n");
    fflush(stderr);
#endif
#ifdef WIN32
    SetConsoleMode(stdout_handle, 0);
#else
    reset_prog_mode();
#endif
/*
 * I am going to take strong action to ensure that the prompt appears
 * at the left-hand side of the screen.
 */
    term_move_first_column();
    set_fg(promptColour);
    printf("%.*s", prompt_length, prompt_string);
    fflush(stdout);
    if (input_line_size == 0)
    {   set_normal();
        return NULL;
    }
    set_fg(inputColour);
    strncpy(input_line, prompt_string, prompt_length);
    strncpy(display_line, prompt_string, prompt_length);
    input_line[prompt_length] = 0;
    display_line[prompt_length] = 0;
    insert_point = final_cursorx = cursorx = prompt_length;
    final_cursory = max_cursory = cursory = 0;
    for (;;)
    {   int n;
        ch = term_getchar();
        if (ch == EOF)
        {   set_normal();
            return NULL;
        }
/*
 * First ensure there is space in the buffer. In some cases maybe putting
 * the test here is marginally over-keen, since the keystroke entered
 * might not be one that was going to add a character. But it is harmless
 * to be safe! If I need to extend the buffer and I fail then I just
 * give up and return an error marker. Note that the insert_point may not
 * be at the end of the line, so I use strlen() to find out how long the
 * line actually is.
 */
        n = strlen(input_line);
/*
 * The curious activity here is to ensure that the buffer would not overflow
 * even if the "regular" part of it was replaced by the longest line
 * that can possibly get into the history-record.
 */
        if (n > longest_history_line) longest_history_line = n;
        if (searchFlags != 0)
            n = n - regular_line_end + longest_history_line;
        if (n >= input_line_size-20)
        {   input_line = (char *)realloc(input_line, 2*input_line_size);
            display_line = (char *)realloc(display_line, 2*input_line_size);
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
    fprintf(stderr, "process character %#x\n", ch);
    fflush(stderr);
#endif
        switch (ch)
        {
    case EOF:
            break;
    case CTRL('@'):
            term_set_mark();
            continue;
    case CTRL('A'):
    case 0x200 + TERM_HOME:
    case 0x200 + TERM_HOME + 0x100:
            term_to_start();
            continue;
    case CTRL('B'):
    case 0x200+TERM_LEFT:
            term_back_char();
            continue;
    case CTRL('C'):
          term_interrupt();
            continue;
    case CTRL('D'):
    case 0x200+TERM_DELETE:
            term_delete_forwards();
            continue;
    case CTRL('E'):
    case 0x200 + TERM_END:
    case 0x200 + TERM_END + 0x100:
            term_to_end();
            continue;
    case CTRL('F'):
    case 0x200+TERM_RIGHT:
            term_forwards_char();
            continue;
    case CTRL('G'):
            term_noisy_interrupt();
            continue;
    case CTRL('H'):
    case 0x7f:     /* The "delete backwards" key, I hope */
    case 0xff:
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
    case 0x200+TERM_DOWN:
            term_history_next();
            continue;
    case CTRL('O'):
            term_discard_output();
            continue;
    case CTRL('P'):
    case 0x200+TERM_UP:
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
            term_extended_command();
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
    case CTRL('@') + 0x100:
            term_set_mark();
            continue;
/*
 * When a character is combined with ALT (or prefixed with ESC) I will in
 * at least very nearly every case ignore whether it is upper or lower case
 * or whether CTRL is pressed too. In a rather few cases I will let CTRL
 * take precedence over ALT...
 */
    case CTRL('A') + 0x100: case 'A' + 0x100: case 'a' + 0x100:
            term_to_start();
            continue;
    case CTRL('B') + 0x100: case 'B' + 0x100: case 'b' + 0x100:
    case 0x200 + TERM_LEFT + 0x100:
            term_back_word();
            continue;
    case CTRL('C') + 0x100: case 'C' + 0x100: case 'c' + 0x100:
            term_capitalize_word();
            continue;
    case CTRL('D') + 0x100: case 'D' + 0x100: case 'd' + 0x100:
    case 0x200 + TERM_DELETE + 0x100:
            term_delete_word_forwards();
            continue;
    case CTRL('E') + 0x100: case 'E' + 0x100: case 'e' + 0x100:
            term_edit_menu();
            continue;
    case CTRL('F') + 0x100: case 'F' + 0x100: case 'f' + 0x100:
    case 0x200 + TERM_RIGHT + 0x100:
            term_forwards_word();
            continue;
    case CTRL('G') + 0x100: case 'G' + 0x100: case 'g' + 0x100:
            term_noisy_interrupt();
            continue;
    case CTRL('H') + 0x100: case 'H' + 0x100: case 'h' + 0x100:
    case 0x7f+0x100:   /* Under X maybe the key above ENTER that I use to .. */
    case 0xff+0x100:   /* delete things will return 0x7f. */
            term_delete_word_backwards();
            continue;
    case CTRL('I') + 0x100: case 'I' + 0x100: case 'i' + 0x100:
            term_file_menu();
            continue;
    case CTRL('J') + 0x100: case 'J' + 0x100: case 'j' + 0x100:  /* line-feed */
            break;
    case CTRL('K') + 0x100: case 'K' + 0x100: case 'k' + 0x100:
            term_kill_line();
            continue;
    case CTRL('L') + 0x100: case 'L' + 0x100: case 'l' + 0x100:
            term_lowercase_word();
            continue;
    case CTRL('M') + 0x100:              /* carriage return, ENTER */
            break;
    case 'M' + 0x100: case 'm' + 0x100:  /* ALT-^M differs from ALT-M, ALT-m */
            term_module_menu();
            continue;
    case CTRL('N') + 0x100: case 'N' + 0x100: case 'n' + 0x100:
    case 0x200 + TERM_DOWN + 0x100:
            term_search_next();
            continue;
    case CTRL('O') + 0x100: case 'O' + 0x100: case 'o' + 0x100:
            term_font_menu();
            continue;
    case CTRL('P') + 0x100: case 'P' + 0x100: case 'p' + 0x100:
    case 0x200 + TERM_UP + 0x100:
            term_search_previous();
            continue;
    case CTRL('Q') + 0x100: case 'Q' + 0x100: case 'q' + 0x100:
            continue;   /* Ignored */
    case CTRL('R') + 0x100: case 'R' + 0x100: case 'r' + 0x100:
            term_break_menu();
            continue;
    case CTRL('S') + 0x100: case 'S' + 0x100: case 's' + 0x100:
            term_switch_menu();
            continue;
    case CTRL('T') + 0x100: case 'T' + 0x100: case 't' + 0x100:
            term_transpose_chars();
            continue;
    case CTRL('U') + 0x100: case 'U' + 0x100: case 'u' + 0x100:
            term_uppercase_word();
            continue;
    case CTRL('V') + 0x100: case 'V' + 0x100: case 'v' + 0x100:
            term_quoted_insert();
            continue;
    case CTRL('W') + 0x100: case 'W' + 0x100: case 'w' + 0x100:
            term_copy_region();
            continue;
    case CTRL('X') + 0x100: case 'X' + 0x100: case 'x' + 0x100:
            term_obey_command();
            continue;
    case CTRL('Y') + 0x100: case 'Y' + 0x100: case 'y' + 0x100:
            term_yank();
            continue;
    case CTRL('Z') + 0x100: case 'Z' + 0x100: case 'z' + 0x100:
            term_pause_execution();
            continue;
/*
 * (already dealt with)
 *  case CTRL('[') + 0x100:               ESC
 */
    case CTRL('\\') + 0x100:
            continue;
    case CTRL(']') + 0x100:
            continue;
    case CTRL('_') + 0x100:
            term_copy_previous_word();
            continue;
    case '@' + 0x100:
            term_set_mark();
            continue;
    case '[' + 0x100:   /* ESC-[ */
            /* Should never be delivered here */
            continue;
    case '\\' + 0x100:
            term_exit_program();
            /* no return */
    case ']' + 0x100:
            continue;
    case '_' + 0x100:
            term_copy_previous_word();
            continue;
    case '{' + 0x100:
            continue;  /* Ignored */
    case '^' + 0x100:
            term_reinput();
            continue;
    case '}' + 0x100:
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
            input_line[insert_point] = ch;
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
    term_putchar('\n');
    fflush(stdout);
    insert_point = strlen(input_line);
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
    input_line[insert_point++] = '\n';
    input_line[insert_point] = 0;
    return input_line + prompt_length;
}

char *term_getline(void)
{
    if (!term_enabled) return term_plain_getline();
    else return term_fancy_getline();
}

#endif /* DISABLE */


/* end of file termed.c */
