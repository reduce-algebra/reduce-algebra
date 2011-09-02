/* sysfwin. c                      Copyright (C) 1989-2007 Codemist Ltd */

/*
 * System specific code. My objective is that this will subsume and replace
 * all the other files that I have or had called sysxxx.c, sysyyy.c etc.
 *
 * System-specific code for use with the "fwin" window interface code.
 * This is expected to be buildable on Windows via mingw32, on
 * both 32 and 64-bit variants of Linux, and (I hope) on Macintosh
 * system X (at least if an X server is made available to it). I thus
 * at least hope that I can use it as a generic uniform body of code.
 * The system will also build as a terminal-mode program as well as
 * a windowed one.
 *
 * I will use "autoconf" and all that stuff with a view to making
 * this code build on a wide range of systems via the usual
 *    ./configure ; make
 * sequence. This (obviously) involves a Unix-like build environment
 * but mingw/msys provides that for Windows.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */

/* Signature: 48f0c070 18-Jan-2007 */

#include "headers.h"

/*
 * WIN32                     all Windows platforms that I support
 * <else>                    Unix-like
 *
 *    popen(cmd, dir)  vs   _popen(cms, dir)
 *    pclose(stream)   vs   _pclose(stream)
 *    fileno(file)     vs   _fileno(file)
 *    struct stat      vs   struct _stat
 *    stat             vs   _stat
 *    ftruncate(file)  vs   chsize(file)
 *    S_IFMT __S_IFMT       to go with stat
 *    S_IFDIR __S_IFDIR
 *    DO_NOT_USE_GETUID     is getuid available
 *    UNIX_TIMES            how can I read the clock
 *    UTIME_TIME_T          struct utimbuf
 */


#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_SYS_TIMES_H
#include <sys/times.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

/*
 * Jollies re GC statistics...
 */
 
static char time_string[32], space_string[32];

void report_time(int32_t t, int32_t gct)
{
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    if ((window_heading & 1) == 0) fwin_report_left(time_string);
}

void report_space(int n, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    if ((window_heading & 4) == 0) fwin_report_right(space_string);
}

void flush_screen()
{
    fwin_ensure_screen();
}

void pause_for_user()
{
}

int wimpget(char *buf)
{
    int c, n=0;
    ensure_screen();
    while (n < 255)
    {   c = fwin_getchar();
        if (c == (0x1f & 'C') ||           /* ^C - quiet : quit      */
            c == (0x1f & 'G')) return 0;   /* ^G - noisy : interrupt */
        if (c == EOF) c = 0x1f & 'D';
        buf[n++] = (char)c;
        if (c == '\n' || c == (0x1f & 'D')) break;
    };
    return n;
}

#ifdef WIN32

HWND gnuplot_handle = 0;

BOOL CALLBACK find_text(HWND h, LPARAM x)
{
    char buffer[24];
    CSL_IGNORE(x);
    GetClassName(h, buffer, 20);
    if (strcmp(buffer, "wgnuplot_text") != 0) return TRUE;
    gnuplot_handle = h;
    return FALSE;
}

#endif

FILE *my_popen(char *command, char *direction)
{
#ifdef WIN32
/*
 * Here I take a pretty shameless direction and spot the special case of
 * opening an output pipe to gnuplot... and hook in a behind-the-scenes
 * way.
 */
    int i = 0, j;
    for (;;)
    {   char *name = "gnuplot";
        j = i;
        while (*name && tolower(command[j++]) == *name) name++;
        if (*name == 0)
        {   HWND parent = 0;
/*
 * Win32 would rather I used the following long-winded version, which provides
 * a pile of generality that is irrelevant here!
 */
            STARTUPINFO startup;
            PROCESS_INFORMATION process;
            clock_t t0, t1;
            memset(&startup, 0, sizeof(STARTUPINFO));
            startup.cb = sizeof(startup);
            startup.lpReserved = NULL;
            startup.lpDesktop = NULL;
            startup.lpTitle = NULL;
            startup.dwFlags = STARTF_USESHOWWINDOW;
            startup.wShowWindow = SW_SHOWMINIMIZED;
            startup.cbReserved2 = 0;
            startup.lpReserved2 = NULL;
            if (!CreateProcess(NULL, command, NULL, NULL, FALSE,
                               0, NULL, NULL, &startup, &process)) return 0;
            gnuplot_handle = 0;
            t0 = clock();
            for (i=0; i<25; i++)  /* Give it 5 seconds to appear */
            {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                    (LPSTR)"gnuplot");
                if (parent != 0) break;
                t0 += CLOCKS_PER_SEC/5;
                while ((t1 = clock()) < t0) ; // a busy-wait here
                t0 = t1;
            }
            if (parent != 0)
            {   for (i=0; i<10; i++)   /* 2 more seconds for the child */
                {   EnumChildWindows(parent, find_text, 0);
                    if (gnuplot_handle != 0) break;
                    t0 += CLOCKS_PER_SEC/5;
                    while ((t1 = clock()) < t0) ; /* busy-wait */
                    t0 = t1;
                }
            }
            return (FILE *)-1;  // special handle for the gnuplot pipe
        }
        i++;
        if (command[i] == 0) break;
    }
/*
 * The MESS of #ifdef stuff here and a fe wplaces lower down will in due
 * course (I hope) be rationalised by arranging that the autoconfigure tools
 * set flags saing what names for functions should be used. But at present
 * I want to retain support for non-autoconfigure building and I have an
 * ugly set of tests based on the identity of the compiler being used or
 * some similar predefined macro.
 *
 * The only macro I really want to see here is WIN32 to select between
 * Windows and Unix-like worlds.
 */
#ifdef __CYGWIN__
    return popen(command, direction);
#else
    return _popen(command, direction);
#endif
#else
    return popen(command, direction);
#endif
}

int my_pipe_putc(int c, FILE *f)
{
#ifdef WIN32
    if (f == (FILE *)(-1))
    {   if (gnuplot_handle == 0) return EOF;
        if (c == '\n') c = '\r';
        SendMessage(gnuplot_handle, WM_CHAR, c, 1L);
        return c;
    }
    else 
#endif
    return putc(c, f);
}

int my_pipe_flush(FILE *f)
{
#ifdef WIN32
    if (f == (FILE *)(-1)) return 0;
#endif
    return fflush(f);
}

void my_pclose(FILE *stream)
{
#ifdef WIN32
    if (stream == (FILE *)(-1))
    {   SendMessage(gnuplot_handle, WM_CHAR, 'q', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'u', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'i', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 't', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, '\r', 1L);
        return;
    }
#ifdef __CYGWIN__
    pclose(stream);
#else
    _pclose(stream);
#endif
#else
    pclose(stream);
#endif
}


/*
 * Map file-names to expand references to shell variables etc.
 * and to provide portability of names across operating systems.
 */


char *look_in_lisp_variable(char *o, int prefix)
{
    Lisp_Object nil, var;
/*
 * I will start by tagging a '$' (or whatever) on in front of the
 * parameter name.
 */
    o[0] = (char)prefix;
    var = make_undefined_symbol(o);
    nil = C_nil;
/*
 * make_undefined_symbol() could fail either if we had utterly run out
 * of memory or if somebody generated an interrupt (eg ^C) around now. Ugh.
 */
    if (exception_pending())
    {   flip_exception();
        return NULL;
    }
/*
 * If the variable $name was undefined then I use an empty replacement
 * text for it. Otherwise I need to look harder at its value.
 */
    if (qvalue(var) == unset_var) return o;
    else
    {   Header h;
        intptr_t len;
        var = qvalue(var);
/*
 * Mostly I expect that the value will be a string or symbol.
 */
#ifdef COMMON
        if (complex_stringp(var))
        {   var = simplify_string(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
        }
#endif /* COMMON */
        if (symbolp(var))
        {   var = get_pname(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
            h = vechdr(var);
        }
        else if (!is_vector(var) ||
                 type_of_header(h = vechdr(var)) != TYPE_STRING)
            return NULL;
        len = length_of_header(h) - CELL;
/*
 * Copy the characters from the string or from the name of the variable
 * into the file-name buffer. There could at present be a crash here
 * if the expansion was very very long and overflowed my buffer. Tough
 * luck for now - people doing that (maybe) get what they (maybe) deserve.
 */
        memcpy(o, (char *)var + (CELL - TAG_VECTOR), (size_t)len);
        o = o + len;
        return o;
    }
}


#if defined HAVE_SYS_TIME_H && !defined WIN32

/*
 * This is a BSD-style clock facility, possibly giving a resolution of
 * only 1/100 second.  I believe that Portable Standard Lisp typically
 * reports user time, which is why I do this.
 */

int unix_ticks = 0;

clock_t read_clock(void)
{
    struct tms tmsbuf;
    clock_t w1, w2, w3;
    times(&tmsbuf);
    w1 = tmsbuf.tms_utime;   /* User time in UNIX_TIMES ticks */
    w2 = CLOCKS_PER_SEC;
    if (unix_ticks == 0)
    {
#ifdef HAVE_UNISTD_H
        unix_ticks = sysconf(_SC_CLK_TCK);
#else
        unix_ticks = 100;
#endif
    }
    w3 = unix_ticks;
    return (clock_t)((double)w1 * ((double)w2/(double)w3));
}

#else

clock_t read_clock()
{
    return clock();
}

#endif

int batchp()
{
    return !isatty(fileno(stdin));
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    int n = strlen(programName) + strlen(programDir) + 6;
    char *w = (char *)(*malloc_hook)(n);
    strcpy(w, programDir);
    n = strlen(programDir);
    w[n] = '/';                 /* Should be '\\' for Windows? */
    strcpy(&w[n+1], programName);
    n += strlen(programName) + 1;
    strcpy(&w[n], ".img");
    return w;
}

/*
 * The following function controls memory allocation policy
 */

int32_t ok_to_grab_memory(int32_t current)
{
#ifdef COMMON
    return current;
#else
    return 3*current + 2;
#endif
}


/* end of sysfwin.c */
