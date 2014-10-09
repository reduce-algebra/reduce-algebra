/* sysfwin. c                      Copyright (C) 1989-2014 Codemist Ltd */

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
 * but cygwin provides that for Windows.
 */

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


/* $Id$ */

#ifdef __CYGWIN__
/*
 * If I am under Cygwin and I will need to use some Windows calls it
 * appears best to include this file very early - otherwise I have found
 * some confusion between cygwin and mingw entrypoints hurting me.
 */
#include <windows.h>
#endif

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
#ifndef EMBEDDED
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    if ((window_heading & 1) == 0) fwin_report_left(time_string);
#endif
}

void report_space(int n, double percent)
{
#ifndef EMBEDDED
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    if ((window_heading & 4) == 0) fwin_report_right(space_string);
#endif
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

HANDLE gnuplot_process = 0;
HWND gnuplot_handle = 0;

void kill_gnuplot()
{
    TerminateProcess(gnuplot_process, 0);
}

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
/*
 * Here I have something that might count as an ugliness. If I am on
 * Windows and am using a console-mode binary then in fact I am using a
 * cygwin-built version of Reduce. That means that WIN32 will not be
 * defined and this special magic will not be activated - I will end up
 * requiring that /usr/bin/gnuplot exists in the cygwin sense of the
 * meaning of that path-name, and that X11 and DISPLAY are available. This
 * may mildly astonish some people. However when I tried to use the
 * Windows-specific code in my Cygwin build I found problems to do with
 * (perhaps) collision between Cygwin and Windows libraries, or to do with
 * availablity of the relevant Windows system-calls under cygwin. So for
 * now that somewhat unsatisfactory arrangement will persist.
 */
#ifdef WIN32
/*
 * Here I take a pretty shameless direction and spot the special case of
 * opening an output pipe to gnuplot... and hook in a behind-the-scenes
 * way.
 */
    int i = 0;
/*
 * The following test would trigger if the string "wgnuplot.exe" was present
 * within the path even if it was not the final component. I think that at
 * present I will take the view that anybody who finds themselves hurt because
 * of that has only themselves to blame.
 */
    if (strstr(command, "wgnuplot.exe") != NULL)
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
        gnuplot_process = process.hProcess;
        atexit(kill_gnuplot);
        gnuplot_handle = 0;
        t0 = clock();
        for (i=0; i<25; i++)  /* Give it 5 seconds to appear */
        {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                (LPSTR)"gnuplot");
            if (parent != 0) break;
            t0 += CLOCKS_PER_SEC/5;
            while ((t1 = clock()) < t0) ; /* a busy-wait here */
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
        return (FILE *)-1;  /* special handle for the gnuplot pipe */
    }
#ifdef __CYGWIN__
    return popen(command, direction);
#else
    return _popen(command, direction);
#endif
#else 
/*
 * The following use of "signal" is so that pipe failure does not raise
 * an exception and blow everything out of the water. I might have expected
 * that "popen(command-that-does-not-exist, "w")" would return NULL, but it
 * seems that sometimes it returns a pipe handle, and puts works on that
 * without visible pain and only when one does an fflush does a SIGPIPE get
 * raised. This hurts when gnuplot has not been installed on a Unix-like host.
 * The new arrangement leads to somewhat silent failure to plot in that
 * case, but is probably better than having an abrupt exit from the system.
 * I know that these days I am asked to use sigaction rather than signal, but
 * even on recent Linux variants that seems only just available...
 */
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


#if defined HAVE_CLOCK_GETTIME && defined HAVE_DECL_CLOCK_THREAD_CPUTIME_ID

/*
 * Where possible I read the time used by the current thread...
 */

clock_t read_clock(void)
{
    struct timespec tt;
    double w1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &tt);
    w1 = (double)tt.tv_sec + (double)tt.tv_nsec/1000000000.0; 
    return (clock_t)(w1 * (double)CLOCKS_PER_SEC);
}


#elif defined HAVE_SYS_TIME_H && defined HAVE_TIMES && !defined WIN32 && !defined EMBEDDED

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
 *
 * On the Macintosh if the path to my executable indicated that I am
 * within an "Application Bundle" I will look for the image file there.
 *
 * Otherwise I will look in two places! If the path to the executable ends
 * up rather like BINDIR then I will check PKGDATADIR. The idea behind this
 * is that if the files have been put in place using "make install" then
 * the executable may be in say "...../bin/reduce" and the corresponding
 * image would the be "..../share/reduce/reduce.img". I accept this if there
 * is an image file in the location so suggested.
 *
 * Finally I look for an image file adjacent to the executable.
 */

#ifndef BINDIR
#define BINDIR /usr/local/bin
#endif

#ifndef PKGDATADIR
#define PKGDATADIR /usr/local/share/reduce
#endif

#define stringify(s) stringify_sub(s)
#define stringify_sub(s) #s

char *find_image_directory(int argc, char *argv[])
{
    int n;
    char *w;
    char xname[LONGEST_LEGAL_FILENAME];
    memset(xname, 0, sizeof(xname));
#ifdef MACINTOSH
/*
 * There is a special oddity on the Macintosh (with the wxWidgets version
 * where windowed versions are set up as "applications" in a directory that
 * forms an "application bundle". The programDir here can then refer to
 * ./reduce.app/Contents/MacOS/reduce (or whatever) and it is probably good
 * to make the default image location be reduce.app/Contents, ie a little
 * above where I am. But then the vanilla console mode version is liable to
 * be just ./reduce, and I want one image file to be used for both versions.
 * Furthermore some kind person may have launched the executable that is
 * within the application bundle directly from a console so that it is not
 * really an application after all. I will do a load of rather curious
 * tests here that are intended to detect the above cases and do special
 * things! My tests will be based on file names and paths.
 */
    sprintf(xname, "/%s.app/Contents/MacOS", programName);
    n = strlen(programDir) - strlen(xname);
    if (n>=0 && strcmp(programDir+n, xname) == 0)
    {   /* Seem to be being executed from within application bundle. */
        sprintf(xname, "%.*s/%s.img",
            (int)strlen(programDir)-6, programDir, programName);
    }
    else
    {   struct stat buf;
/*
 * If I am NOT within an application bundle but there is one next to me I
 * will put the image file in the application directory. Of there is no
 * such bundle I will put the image file in the location I would have used
 * with Windows of X11.
 */
        sprintf(xname, "%s/%s.app/Contents", programDir, programName);
        if (stat(xname, &buf) == 0 &&
            (buf.st_mode & S_IFDIR) != 0)
        {   sprintf(xname, "%s/%s.app/Contents/%s.img",
                programDir, programName, programName);
        }
        else sprintf(xname, "%s/%s.img", programDir, programName);

    }
#else
    {   const char *bin  = stringify(BINDIR);
        const char *data = stringify(PKGDATADIR);
/*
 * I will strip initial directory names from bin and pkgdatadir so long as
 * they match. So if they start off as (eg) /usr/local/bin and
 * /usr/local/share/reduce I will remove "/usr/local" from each leaving just
 * "/bin" and "/share/reduce". The purpose of this is so that if (despite the
 * use of "make install") somebody has copied the tree that contains Reduce
 * to somewhere else I might still find my resources.
 */
        int i, j;
        struct stat buf;
        const char *pn = programName;
#if defined WIN32 || defined __CYGWIN__
/*
 * On Windows I can have reduce.exe, cygwin-reduce.exe and cygwin64-reduce.exe
 * all present, and for immediate purposes I want them all to be treated as
 * if merely called "reduce".
 */
        if (strncmp(pn, "cygwin-", 7) == 0) pn += 7; 
        else if (strncmp(pn, "cygwin64-", 9) == 0) pn += 9;
#endif /* WIN32 */
        for (;;)
        {   i = j = 0;
            if (*bin == '/') while (bin[++i] != 0 && bin[i] != '/');
            if (*data == '/') while (data[++j] != 0 && data[j] != '/');
            if (i != 0 && i == j && strncmp(bin, data, i) == 0)
            {   bin += i;
                data += i;
            }
            else break;
        }
        i = strlen(bin);
        j = strlen(programDir);
        if (strcmp(programDir+j-i, bin) == 0)
        {   sprintf(xname, "%.*s%s/%s.img", j-i, programDir, data, pn);
        }

/*
 * If the name I just created does not correspond to a file I will fall
 * back and use the older location, adjacent to my binary. Hmmm this is
 * all interesting as regards building an image file for the first time.
 * I think it tells us that you had better not try doing that using the
 * installed version - do that with a copy that sits in your own private
 * writable are of disc.
 */
        if (stat(xname, &buf) != 0)
            sprintf(xname, "%s/%s.img", programDir, pn);
    }
#endif
    n = strlen(xname)+1;
    w = (char *)(*malloc_hook)(n);
    strcpy(w, xname);
    return w;
}

#ifdef WIN32
#define GPNAME  "wgnuplot.exe"
#define DIRCHAR '\\'
#else
#define GPNAME  "gnuplot"
#define DIRCHAR '/'
#endif


/*
 * When Reduce wants to invoke gnuplot it needs a command-line to pass to
 * "pipe-open". This procedure creates on (if it can), The idea is
 * to try three possibilities in turn:
 * (1) If an environment variable GNUPLOT is set then that should be set to
 *     a path within which the gnuplot executable exists. So eg if the
 *     value of GNUPLOT is "/usr/extras/gnuplotfiles" then the result
 *     here is liable to be "/usr/extras/gnuplotfiles/gnuplot".
 * (2) If a file called "gnuplot" (or "wgnuplot.exe in the windows case) is
 *     present in the directory where the Reduce executable was found then
 *     it will be used. 
 * (3) If a file called "gnuplot" (or "wgnuplot.exe in the windows case) is
 *     present in the directory where the Reduce image would (by default)
 *     be found then it will be used.  In some cases this is actually the
 *     same as (2) above, but it can differ if the executable is in
 *     .../bin and the image in .../share/reduce or some such.
 * (4) A search will be made in the "standard place". For Windows this will
 *     involve scanning the registry to seek an installation of gnuplot,
 *     while otherwise it will be expected that the ordinary PATH will
 *     provide access.
 * (5) Failing all else I will just hand back the name of the executable and
 *     hope that it is on a PATH.
 */

int executable_file(char *name)
{
    struct stat buf;
    if (stat(name, &buf) == -1) return 0;
#ifndef S_ISUSR
    return 1;
#else
    return (buf.st_mode & S_IXUSR);
#endif
}

int find_gnuplot(char *name)
{
    const char *w = getenv("GNUPLOT");
    size_t len;
    if (w != NULL && (len = strlen(w)) > 0)
    {   if (w[len-1] == '/' ||
            w[len-1] == '\\') len--;
        sprintf(name, "%.*s%c%s", (int)len, w, DIRCHAR, GPNAME);
        if (executable_file(name)) return 1;
    }
    strcpy(name, programDir);
    len = strlen(name);
    while (len-- > 0 &&
           name[len] != '/' &&
           name[len] != '\\');
    if (len != 0)
    {   strcpy(&name[len+1], GPNAME);
        if (executable_file(name)) return 1;
    }
    strcpy(name, standard_directory);
    len = strlen(name);
    while (len-- > 0 &&
           name[len] != '/' &&
           name[len] != '\\');
    if (len != 0)
    {   strcpy(&name[len+1], GPNAME);
        if (executable_file(name)) return 1;
    }
#ifdef __CYGWIN__
/*
 * As usual Cygwin is an odd case. If DISPLAY is set and /usr/bin/gnuplot
 * exists then I will try for an X11 usage of gnuplot. That should be
 * the "natural" case!
 */
    w = getenv("DISPLAY");
    if (w!=NULL && *w!=0 &&
        executable_file("/usr/bin/gnuplot.exe"))
    {   strcpy(name, "/usr/bin/gnuplot.exe");
        return 1;
    }
/*
 * ... well actually people may be using the cygwin version of Reduce because
 * they ran the console mode version of Reduce under Cygwin's mintty. But
 * they may not have X11 available. In the case perhaps I should try for
 * a native Windows version of gnuplot for them... I look for gnuplot.exe here
 * rather than wgnuplot.exe and will use it via a pipe rather than using
 * the windows-special interface method.
 */
    {   HKEY keyhandle;
/*
 * I need to use RegQueryValueEx here rather than RegGetValue if I am to
 * support 32-bit Windows XP. Note that buffer overflow in the path to
 * gnuplot could leave an unterminated string, but that should not happen
 * here.
 */
        DWORD length = LONGEST_LEGAL_FILENAME, type;
        int ll, i;
        LONG r = RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,
            "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\gnuplot.exe",
            0,
            KEY_QUERY_VALUE,
            &keyhandle);
        if (r == ERROR_SUCCESS) 
        {   r = RegQueryValueEx(keyhandle,
               NULL,
               NULL,
               (LPDWORD)&type,
               (PVOID)name,
               (LPDWORD)&length);
            name[LONGEST_LEGAL_FILENAME-1] = 0;
            if (r == ERROR_SUCCESS)
            {
/*
 * Now I have a further delight. The path I have just identified is a
 * Windows one, but I need to convert it into a Cygwin-style one. It
 * should start "x:\" with a drive name so I map that onto "/cygdrive/x/"
 * and convert every "\" to a "/". The code here is rather grotty with the
 * numeric "magic offsets" and the use of sprintf followed by patching
 * up after the terminating null from that, but it is at least concise.
 */
                ll = strlen(name);
                for (i=ll; i>=0; i--)
                    name[i+9] = name[i]=='\\' ? '/' : name[i];
                sprintf(name, "/cygdrive/%c", name[0]);
                name[11] = '/';
                return 1;
            }
        }
    }
#endif
#ifdef WIN32
    {   HKEY keyhandle;
/*
 * I need to use RegQueryValueEx here rather than RegGetValue if I am to
 * support 32-bit Windows XP. Note that buffer overflow in the path to
 * gnuplot could leave an unterminated string, but that should not happen
 * here.
 */
        DWORD length = LONGEST_LEGAL_FILENAME, type;
        LONG r = RegOpenKeyEx(
            HKEY_LOCAL_MACHINE,
            "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\wgnuplot.exe",
            0,
            KEY_QUERY_VALUE,
            &keyhandle);
        if (r == ERROR_SUCCESS)
        {   r = RegQueryValueEx(keyhandle,
               NULL,
               NULL,
               (LPDWORD)&type,
               (PVOID)name,
               (LPDWORD)&length);
            name[LONGEST_LEGAL_FILENAME-1] = 0;
            if (r == ERROR_SUCCESS) return 1;
        }
    }
/*
 * If wgnuplot.exe is not installed then I will drop through and a last
 * resort just hand back "wgnuplot.exe" as a string and hope it is on a PATH.
 */
#endif
    strcpy(name, GPNAME);
    return 1;
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
