/* sysfwin. c                      Copyright (C) 1989-2008 Codemist Ltd */

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
 * but mingw-under-cygwin provides that for Windows.
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


/* Signature: 692ad8fe 19-Jul-2009 */

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

#ifdef HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif

#ifdef HAVE_SYSCALL_H
#include <syscall.h>
#endif

#ifdef HAVE_SCHED_H
#include <sched.h>
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

int terminal_eof_seen = 0;

int wimpget(char *buf)
{
    int c, n=0;
    ensure_screen();
    while (n < 255)
    {   if (terminal_eof_seen) c = EOF;
        else
        {   c = fwin_getchar();
            if (c == EOF || c == (0x1f & 'D')) terminal_eof_seen = 1;
        }
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
// The following use of "signal" is so that pipe failure does not raise
// an exception and blow everything out of the water. I might have expected
// that "popen(command-that-does-not-exist, "w")" would return NULL, but it
// seems that sometimes it returns a pipe handle, and puts works on that
// without visible pain and only when one does an fflush does a SIGPIPE get
// raised. This hurts when gnuplot has not been installed on a Unix-like host.
// The new arrangement leads to somewhat silent failure to plot in that
// case, but is probably better than having an abrupt exit from the system.
// I know that these days I am asked to use sigaction rather than signal, but
// even on recent Linux variants that seems only just available...
    signal(SIGPIPE, SIG_IGN);
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

/*
 * I will provide a function that reports how many processors are
 * available. This may be of importance for multi-core systems where I
 * could exploit around that many threads to especial benefit. In cases when
 * I can not obtain the information I will merely report "1" which should
 * be a fail-safe fallback. Issues such as the user setting processor
 * affinities etc may make the information obtained indicative rather than
 * definitive!
 */

#ifdef WIN32

/*
 * The GetSystemInfo call in Windows is available on Windows 2000,
 * XP and Vista (together with corresponding server varients of the
 * system), so by including the following lines I am cutting myself
 * off from Windows 98 and ME. I find it hard (in September 2008) to believe
 * that this will be a serious limitation in the use of this code. But if it
 * was essential to handle them it would be possible to do a dynamic search
 * for the GetSystemInfo entry in the DLLs and only use if when present.
 */

int number_of_processors()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return (int)si.dwNumberOfProcessors;
}

#else
#if defined HAVE_SYS_SYSCTL_H && defined HAVE_SYSCTLBYNAME

/*
 * This is expected to cope with both BSD and Macintosh-X.
 */

int number_of_processors()
{
    int n;
    size_t len=4;
    if (sysctlbyname("hw.ncpu", &n, &len, NULL, 0) != 0) return 1;
    return n;
}


#else
#if defined HAVE_SYSCALL_H && \
    defined HAVE_SCHED_H && \
    defined SYS_sched_getaffinity && \
    defined HAVE_CPU_SET_T

/*
 * This should cope with Linux
 */

int number_of_processors()
{
    cpu_set_t cs;
    int n, len;
    unsigned char *p = (unsigned char *)&cs;
    memset(p, 0, sizeof(cs));
/*
 * The library calls to sched_getaffinity have changed several times with
 * various releases of glibc, and so I use the raw syscall. This has the
 * extra feature that it can tell me how many bytes are used by the
 * kernel-level CPU map, which may be way smaller than the size of the
 * cpu_set_t data type.
 */
    len = syscall(SYS_sched_getaffinity, 0, sizeof(cs), &cs);
    if (len == -1) n = 1;    /* Report just 1 CPU if syscall fails */
    else
    {   int i;
        n = 0;
        for (i=0; i<len; i++)
        {   int b = p[i];
            while (b != 0)   /* Count bits */
            {   n++;
                b -= b & -b;
            }
        }
    }
    return n;
}

#else

int number_of_processors()
{
    return 1;  /* Have not detected a way that I can tell better */
}

#endif
#endif
#endif


/* end of sysfwin.c */
