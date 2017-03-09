// sysfwin.cpp                             Copyright (C) 1989-2017 Codemist    

//
// System-specific code for use with the "fwin" window interface code.
// The system will also build as a terminal-mode program as well as
// a windowed one.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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


// $Id$

#ifdef __CYGWIN__
//
// If I am under Cygwin and I will need to use some Windows calls it
// appears best to include this file very early - otherwise I have found
// some confusion between cygwin and mingw entrypoints hurting me.
//
#include <windows.h>
#include <sys/cygwin.h>
#endif

#include "headers.h"

//
// WIN32                     all Windows platforms that I support
// <else>                    Unix-like
//
//    popen(cmd, dir)  vs   _popen(cms, dir)
//    pclose(stream)   vs   _pclose(stream)
//    fileno(file)     vs   _fileno(file)
//    struct stat      vs   struct _stat
//    stat             vs   _stat
//    ftruncate(file)  vs   chsize(file)
//    S_IFMT __S_IFMT       to go with stat
//    S_IFDIR __S_IFDIR
//    DO_NOT_USE_GETUID     is getuid available
//    UNIX_TIMES            how can I read the clock
//    UTIME_TIME_T          struct utimbuf
//


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

//
// At present CSL is single threaded - at least as regards file IO - and
// using the unlocked versions of putc and getc can be a MAJOR saving.
// I put these macros here not in soem header to try to keep me reminded
// that if threads ever happened I would need to do my own buffering.
//

#ifdef HAVE_PUTC_UNLOCKED
#define PUTC(x, y) putc_unlocked((x), (y))
#else
#ifdef HAVE__PUTC_NOLOCK
#define PUTC(x, y) _putc_nolock((x), (y))
#else
#define PUTC(x, y) putc((x), (y))
#endif
#endif

//
// Jollies re GC statistics...
//

static char time_string[32], space_string[32];

void report_time(int32_t t, int32_t gct)
{
#ifndef EMBEDDED
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
            t/100L, t%100L, gct/100L, gct%100L);
    if ((window_heading & 1) == 0) fwin_report_left(time_string);
#endif
}

void report_space(uint64_t n, double percent)
{
#ifndef EMBEDDED
    sprintf(space_string, "[GC %" PRIu64 "]:%.2f%%", n, percent);
    if ((window_heading & 4) == 0) fwin_report_right(space_string);
#endif
}

void flush_screen()
{   fwin_ensure_screen();
}

void pause_for_user()
{
}

int terminal_eof_seen = 0;

int wimpget(char *buf)
{   int c, n=0;
    ensure_screen();
    while (n < 255)
    {   if (terminal_eof_seen) c = EOF;
        else
        {   c = fwin_getchar();
            if (c == EOF || c == (0x1f & 'D')) terminal_eof_seen = 1;
        }
        if (c == (0x1f & 'C') ||           // ^C - quiet : quit
            c == (0x1f & 'G')) return 0;   // ^G - noisy : interrupt
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
{   TerminateProcess(gnuplot_process, 0);
}

BOOL CALLBACK find_text(HWND h, LPARAM)
{   char buffer[24];
    GetClassName(h, buffer, 20);
    if (strcmp(buffer, "wgnuplot_text") != 0) return TRUE;
    gnuplot_handle = h;
    return FALSE;
}

#endif

FILE *my_popen(const char *command, const char *direction)
{
//
// Here I have something that might count as an ugliness. If I am on
// Windows and am using a console-mode binary then in fact I am using a
// cygwin-built version of Reduce. That means that WIN32 will not be
// defined and this special magic will not be activated - I will end up
// requiring that /usr/bin/gnuplot exists in the cygwin sense of the
// meaning of that path-name, and that X11 and DISPLAY are available. This
// may mildly astonish some people. However when I tried to use the
// Windows-specific code in my Cygwin build I found problems to do with
// (perhaps) collision between Cygwin and Windows libraries, or to do with
// availablity of the relevant Windows system-calls under cygwin. So for
// now that somewhat unsatisfactory arrangement will persist.
//
#ifdef WIN32
//
// Here I take a pretty shameless direction and spot the special case of
// opening an output pipe to gnuplot... and hook in a behind-the-scenes
// way.
//
    int i = 0;
//
// The following test would trigger if the string "wgnuplot.exe" was present
// within the path even if it was not the final component. I think that at
// present I will take the view that anybody who finds themselves hurt because
// of that has only themselves to blame.
//
    if (strstr(command, "wgnuplot.exe") != NULL)
    {   HWND parent = 0;
//
// Win32 would rather I used the following long-winded version, which provides
// a pile of generality that is irrelevant here!
//
        STARTUPINFO startup;
        PROCESS_INFORMATION process;
        char c1[LONGEST_LEGAL_FILENAME];
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
        strncpy(c1, command, sizeof(c1));
        c1[sizeof(c1)-1] = 0;
        if (!CreateProcess(NULL, c1, NULL, NULL, FALSE,
                           0, NULL, NULL, &startup, &process)) return 0;
        gnuplot_process = process.hProcess;
        atexit(kill_gnuplot);
        gnuplot_handle = 0;
        t0 = clock();
        for (i=0; i<25; i++)  // Give it 5 seconds to appear
        {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                (LPSTR)"gnuplot");
            if (parent != 0) break;
            t0 += CLOCKS_PER_SEC/5;
            while ((t1 = clock()) < t0) ; // a busy-wait here
            t0 = t1;
        }
        if (parent != 0)
        {   for (i=0; i<10; i++)   // 2 more seconds for the child
            {   EnumChildWindows(parent, find_text, 0);
                if (gnuplot_handle != 0) break;
                t0 += CLOCKS_PER_SEC/5;
                while ((t1 = clock()) < t0) ; // busy-wait
                t0 = t1;
            }
        }
        return (FILE *)-1;  // special handle for the gnuplot pipe
    }
#ifdef __CYGWIN__
    return popen(command, direction);
#else
    return _popen(command, direction);
#endif
#else
//
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
//
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
        return PUTC(c, f);
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


//
// Map file-names to expand references to shell variables etc.
// and to provide portability of names across operating systems.
//


char *look_in_lisp_variable(char *o, int prefix)
{   LispObject var;
//
// I will start by tagging a '$' (or whatever) on in front of the
// parameter name.
//
    o[0] = (char)prefix;
    var = make_undefined_symbol(o);
//
// make_undefined_symbol() could fail either if we had utterly run out
// of memory or if somebody generated an interrupt (eg ^C) around now. Ugh.
//
// If the variable $name was undefined then I use an empty replacement
// text for it. Otherwise I need to look harder at its value.
//
    if (qvalue(var) == unset_var) return o;
    else
    {   intptr_t len;
        var = qvalue(var);
//
// Mostly I expect that the value will be a string or symbol.
//
#ifdef COMMON
        if (complex_stringp(var)) var = simplify_string(var);
#endif // COMMON
        if (symbolp(var)) var = get_pname(var);
        else if (!is_vector(var) || !is_string(var)) return NULL;
        len = length_of_byteheader(vechdr(var)) - CELL;
//
// Copy the characters from the string or from the name of the variable
// into the file-name buffer. There could at present be a crash here
// if the expansion was very very long and overflowed my buffer. Tough
// luck for now - people doing that (maybe) get what they (maybe) deserve.
//
        memcpy(o, (char *)var + (CELL - TAG_VECTOR), (size_t)len);
        o = o + len;
        return o;
    }
}


#if defined HAVE_CLOCK_GETTIME && defined HAVE_DECL_CLOCK_THREAD_CPUTIME_ID

//
// Where possible I read the time used by the current thread...
//

clock_t read_clock(void)
{   struct timespec tt;
    double w1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &tt);
    w1 = (double)tt.tv_sec + (double)tt.tv_nsec/1000000000.0;
    return (clock_t)(w1 * (double)CLOCKS_PER_SEC);
}


#elif defined HAVE_SYS_TIME_H && defined HAVE_TIMES && !defined WIN32 && !defined EMBEDDED

//
// This is a BSD-style clock facility, possibly giving a resolution of
// only 1/100 second.  I believe that Portable Standard Lisp typically
// reports user time, which is why I do this.
//

int unix_ticks = 0;

clock_t read_clock(void)
{   struct tms tmsbuf;
    clock_t w1, w2, w3;
    times(&tmsbuf);
    w1 = tmsbuf.tms_utime;   // User time in UNIX_TIMES ticks
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
{   return clock();
}

#endif

int batchp()
{   return !isatty(fileno(stdin));
}

//
// The next procedure is responsible for establishing information about
// where the main checkpoint image should be recovered from, and where
// and fasl files should come from.
//
// On the Macintosh if the path to my executable indicated that I am
// within an "Application Bundle" I will look for the image file there.
//
// Otherwise I will look in two places! If the path to the executable ends
// up rather like BINDIR then I will check PKGDATADIR. The idea behind this
// is that if the files have been put in place using "make install" then
// the executable may be in say "...../bin/reduce" and the corresponding
// image would the be "..../share/reduce/reduce.img". I accept this if there
// is an image file in the location so suggested.
//
// Finally I look for an image file adjacent to the executable.
//

#ifndef BINDIR
#define BINDIR /usr/local/bin
#endif

#ifndef PKGDATADIR
#define PKGDATADIR /usr/local/share/reduce
#endif

#define stringify(s) stringify_sub(s)
#define stringify_sub(s) #s

const char *find_image_directory(int argc, const char *argv[])
{
    int n;
    char *w;
    char xname[LONGEST_LEGAL_FILENAME];
    memset(xname, 0, sizeof(xname));
#ifdef MACINTOSH
//
// There is a special oddity on the Macintosh (with the wxWidgets version
// where windowed versions are set up as "applications" in a directory that
// forms an "application bundle". The programDir here can then refer to
// ./reduce.app/Contents/MacOS/reduce (or whatever) and it is probably good
// to make the default image location be reduce.app/Contents/MacOS too.
// But then the vanilla console mode version is liable to
// be just ./reduce, and I want one image file to be used for both versions.
// Furthermore some kind person may have launched the executable that is
// within the application bundle directly from a console so that it is not
// really an application after all. I will do a load of rather curious
// tests here that are intended to detect the above cases and do special
// things! My tests will be based on file names and paths.
//
    sprintf(xname, "/%s.app/Contents/MacOS", programName);
    n = strlen(programDir) - strlen(xname);
    if (n>=0 && strcmp(programDir+n, xname) == 0)
    {   // Seem to be being executed from within application bundle.
// This dates from when I thought I would put the image in merely Contents not
// in Contents/MacOS.
        sprintf(xname, "%.*s/%s.img",
            (int)strlen(programDir), programDir, programName);
    }
    else
    {   struct stat buf;
//
// If I am NOT within an application bundle but there is one next to me I
// will put the image file in the application directory. Of there is no
// such bundle I will put the image file in the location I would have used
// with Windows of X11.
//
        sprintf(xname, "%s/%s.app/Contents/MacOS", programDir, programName);
        if (stat(xname, &buf) == 0 &&
            (buf.st_mode & S_IFDIR) != 0)
        {   sprintf(xname, "%s/%s.app/Contents/MacOS/%s.img",
                programDir, programName, programName);
        }
        else sprintf(xname, "%s/%s.img", programDir, programName);

    }
#else
    {   const char *bin  = stringify(BINDIR);
        const char *data = stringify(PKGDATADIR);
//
// I will strip initial directory names from bin and pkgdatadir so long as
// they match. So if they start off as (eg) /usr/local/bin and
// /usr/local/share/reduce I will remove "/usr/local" from each leaving just
// "/bin" and "/share/reduce". The purpose of this is so that if (despite the
// use of "make install") somebody has copied the tree that contains Reduce
// to somewhere else I might still find my resources.
//
        int i, j;
        struct stat buf;
        const char *pn = programName;
#if defined WIN32 || defined __CYGWIN__
//
// On Windows I can have reduce.exe, cygwin-reduce.exe and cygwin64-reduce.exe
// all present, and for immediate purposes I want them all to be treated as
// if merely called "reduce".
//
        if (strncmp(pn, "cygwin-", 7) == 0) pn += 7;
        else if (strncmp(pn, "cygwin64-", 9) == 0) pn += 9;
#endif // WIN32
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

//
// If the name I just created does not correspond to a file I will fall
// back and use the older location, adjacent to my binary. Hmmm this is
// all interesting as regards building an image file for the first time.
// I think it tells us that you had better not try doing that using the
// installed version - do that with a copy that sits in your own private
// writable are of disc.
//
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


//
// When Reduce wants to invoke gnuplot it needs a command-line to pass to
// "pipe-open". This procedure creates on (if it can), The idea is
// to try three possibilities in turn:
// (1) If an environment variable GNUPLOT is set then that should be set to
//     a path within which the gnuplot executable exists. So eg if the
//     value of GNUPLOT is "/usr/extras/gnuplotfiles" then the result
//     here is liable to be "/usr/extras/gnuplotfiles/gnuplot".
// (2) If a file called "gnuplot" (or "wgnuplot.exe in the windows case) is
//     present in the directory where the Reduce executable was found then
//     it will be used.
// (3) If a file called "gnuplot" (or "wgnuplot.exe in the windows case) is
//     present in the directory where the Reduce image would (by default)
//     be found then it will be used.  In some cases this is actually the
//     same as (2) above, but it can differ if the executable is in
//     .../bin and the image in .../share/reduce or some such.
// (4) A search will be made in the "standard place". For Windows this will
//     involve scanning the registry to seek an installation of gnuplot,
//     while otherwise it will be expected that the ordinary PATH will
//     provide access.
// (5) Failing all else I will just hand back the name of the executable and
//     hope that it is on a PATH.
//

int executable_file(const char *name)
{   struct stat buf;
    if (stat(name, &buf) == -1) return 0;
#ifndef S_ISUSR
    return 1;
#else
    return (buf.st_mode & S_IXUSR);
#endif
}

int find_gnuplot(char *name)
{   const char *w = getenv("GNUPLOT");
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
//
// As usual Cygwin is an odd case. If DISPLAY is set and /usr/bin/gnuplot
// exists then I will try for an X11 usage of gnuplot. That should be
// the "natural" case!
//
    w = getenv("DISPLAY");
    if (w!=NULL && *w!=0 &&
        executable_file("/usr/bin/gnuplot.exe"))
    {   strcpy(name, "/usr/bin/gnuplot.exe");
        return 1;
    }
//
// ... well actually people may be using the cygwin version of Reduce because
// they ran the console mode version of Reduce under Cygwin's mintty. But
// they may not have X11 available. In the case perhaps I should try for
// a native Windows version of gnuplot for them... I look for gnuplot.exe here
// rather than wgnuplot.exe and will use it via a pipe rather than using
// the windows-special interface method.
//
    {   HKEY keyhandle;
//
// I need to use RegQueryValueEx here rather than RegGetValue if I am to
// support 32-bit Windows XP. Note that buffer overflow in the path to
// gnuplot could leave an unterminated string, but that should not happen
// here.
//
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
                                (LPBYTE)name,
                                (LPDWORD)&length);
            name[LONGEST_LEGAL_FILENAME-1] = 0;
            if (r == ERROR_SUCCESS)
            {
//
// Now I have a further delight. The path I have just identified is a
// Windows one, but I need to convert it into a Cygwin-style one. It
// should start "x:\" with a drive name so I map that onto "/cygdrive/x/"
// and convert every "\" to a "/". The code here is rather grotty with the
// numeric "magic offsets" and the use of sprintf followed by patching
// up after the terminating null from that, but it is at least concise.
//
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
//
// I need to use RegQueryValueEx here rather than RegGetValue if I am to
// support 32-bit Windows XP. Note that buffer overflow in the path to
// gnuplot could leave an unterminated string, but that should not happen
// here.
//
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
                                (LPBYTE)name,
                                (LPDWORD)&length);
            name[LONGEST_LEGAL_FILENAME-1] = 0;
            if (r == ERROR_SUCCESS) return 1;
        }
    }
//
// If wgnuplot.exe is not installed then I will drop through and a last
// resort just hand back "wgnuplot.exe" as a string and hope it is on a PATH.
//
#endif
    strcpy(name, GPNAME);
    return 1;
}

//
// The following function controls memory allocation policy
//

int32_t ok_to_grab_memory(int32_t current)
{   return 3*current + 2;
}

//
// I will provide a function that reports how many processors are
// available. This may be of importance for multi-core systems where I
// could exploit around that many threads to especial benefit. In cases when
// I can not obtain the information I will merely report "1" which should
// be a fail-safe fallback. Issues such as the user setting processor
// affinities etc may make the information obtained indicative rather than
// definitive!
//

#ifdef WIN32

int number_of_processors()
{   SYSTEM_INFO si;
    GetSystemInfo(&si);  // Not supported by Windowes 95/98!
    return (int)si.dwNumberOfProcessors;
}

#else
#ifdef __SC_NPROCESSORS_CONF

//
// If I am using gcc/libc then this easy way out should be available
//

int number_of_processors()
{   return sysconf(_SC_NPROCESSORS_CONF);
}

#else

//
// The above two rather simple fragments seem to work on Windows, Linux
// and OSX, so the older options below remain as mere fallbacks.
//

#if defined HAVE_SYS_SYSCTL_H && defined HAVE_SYSCTLBYNAME

//
// This is expected to cope with both BSD and Macintosh-X.
//

int number_of_processors()
{   int n;
    size_t len=4;
    if (sysctlbyname("hw.ncpu", &n, &len, NULL, 0) != 0) return 1;
    return n;
}

#else
#if defined HAVE_SYSCALL_H && \
    defined HAVE_SCHED_H && \
    defined SYS_sched_getaffinity && \
    defined HAVE_CPU_SET_T

//
// This should cope with Linux
//

int number_of_processors()
{   cpu_set_t cs;
    int n, len;
    unsigned char *p = (unsigned char *)&cs;
    memset(p, 0, sizeof(cs));
//
// The library calls to sched_getaffinity have changed several times with
// various releases of glibc, and so I use the raw syscall. This has the
// extra feature that it can tell me how many bytes are used by the
// kernel-level CPU map, which may be way smaller than the size of the
// cpu_set_t data type.
//
    len = syscall(SYS_sched_getaffinity, 0, sizeof(cs), &cs);
    if (len == -1) n = 1;    // Report just 1 CPU if syscall fails
    else
    {   int i;
        n = 0;
        for (i=0; i<len; i++)
        {   int b = p[i];
            while (b != 0)   // Count bits
            {   n++;
                b -= b & -b;
            }
        }
    }
    return n;
}

#else

int number_of_processors()
{   return 1;  // Have not detected a way that I can tell better
}

#endif
#endif
#endif
#endif

static int tmpSerial = 0;

static char tempname[LONGEST_LEGAL_FILENAME];

const char *CSLtmpdir()
{
#ifdef __CYGWIN__
// First try the Windows path to "/tmp"
    char *p;
    if (cygwin_conv_path(CCP_POSIX_TO_WIN_A,
                         "/tmp", tempname, sizeof(tempname)) != 0)
    {   DWORD n = GetTempPath(sizeof(tempname), tempname);
        if (n == 0 || n > sizeof(tempname)) return ".";
        tempname[n-1] = 0; // Remove trailing "\"
    }
    for (p=tempname; *p!=0; p++)
        if (*p == '\\') *p = '/';
    return tempname;
#else
#if defined WIN32
    DWORD n = GetTempPath(sizeof(tempname), tempname);
    if (n == 0 || n > sizeof(tempname)) return ".";
    tempname[n-1] = 0; // Remove trailing "\"
    return tempname;
#else
    return "/tmp";
#endif
#endif
}

const char *CSLtmpnam(const char *suffix, int32_t suffixlen)
{   time_t t0 = time(NULL);
    clock_t c0 = clock();
    unsigned long taskid;
    char fname[LONGEST_LEGAL_FILENAME];
    char tt[32];
    char *s;
#ifdef WIN32
    DWORD len;
    memset(fname, 0, sizeof(fname));
    len = GetTempPath(LONGEST_LEGAL_FILENAME, tempname);
    if (len <= 0) return NULL;
//
// I want to avoid name clashes fairly often, so I will use the current
// time of day and information about the current process as a seed for the
// generated file-name so that (with luck) clashes are at least not
// incredibly probable. I will also use my source of random numbers, which
// adds variation that changes each time I call this function.
//
    taskid = (unsigned long)GetCurrentThreadId()*169 +
             (unsigned long)GetCurrentProcessId();
#else
    memset(fname, 0, sizeof(fname));
    strcpy(tempname, "/tmp/");
    taskid = (unsigned long)getpid()*169 + (unsigned long)getuid();
#endif
    taskid = 169*taskid + (unsigned long)t0;
    taskid = 169*taskid + (unsigned long)c0;
    taskid = 169 * taskid + tmpSerial++;
//
// The information I have gathered thus far may not change terribly rapidly,
// since the process id is static form any one instance of my code and the
// clock may tick very slowly compared with the CPU's activity.
//
    for (;;)
    {   unsigned long n;
        int i;
//
// The next line reduces taskid modulo the largest prime under 2^32, which
// may be a sensible thing to do of "unsigned long" had been a 64-bit
// data type.
//
        n = taskid % 0xfffffffbUL;
//
// At this stage I have at most 32-bits of information, derived from the
// clock and process identification. I will combine in info from the
// random number generator I have elsewhere in this code, and do that in
// such a way that I can generate 8 characters of file-name.
//
        s = tempname + strlen(tempname);
        for (i=0; i<7; i++)
        {   int d = (int)(n % 36);
            n = n / 36;
            if (i == 1) n ^= (unsigned long)Crand();
            if (d < 10) d += '0';
            else d += ('a' - 10);   // now 0-9 or 1-z
            *s++ = d;
        }
        n = n % 36;
        if (n < 10) *s++ = '0' + (int)n;
        else *s++ = 'a' + (int)(n - 10);
        if (suffix != NULL)
        {   sprintf(s, ".%.*s", (int)suffixlen, suffix);
        }
        else *s = 0;
//
// If the file whose name I have just invented already exists I need to
// try again. I will count of the "random" sequence from Crand to propose
// an alternative name for me.
//
        if (file_exists(fname, tempname, strlen(tempname), tt))
        {   taskid ^= n;
            continue;
        }
        break;
    }
    return tempname;
}

// The following functions are best described as delicate, and they are only
// present for debugging purposes. It is not clear to me how much performance
// penalty they introduce, and certainly in a multi-threaded context the
// state of availabaility of memory to one thraed can be changed by a
// different thread, leaving any result found here out of date. The Windows
// code also hints at issues where pages are marked in a special manner to
// let them act as guard pages - and potential consequences of that (eg
// wrt stack extension) are not handled carefully here.

#if defined __CYGWIN__ || defined __unix__ || defined MACINTOSH

// This code is intended to discover whether the pointer that is passed
// is a valid address.
// Writing to /dev/rand is certainly harmless. Any bytes written merely
// get merged in with other entropy that influences future random numbers.
// The write() function never causes an exception, but instead returns
// -1 if it fails, and sets errno to EFAULT if the buffer address that it
// is passed offends it.

#include <unistd.h>
#include <fcntl.h>

static int devrand = 0;
static bool devrand_set = false;

bool valid_address(void *pointer)
{   if (!devrand_set)
    {   devrand = open("/dev/random", O_WRONLY);
        devrand_set = true;   // I will open the fd just once.
    }
// I will not bother to check errno, and just take any failure as
// indicating a bad memory address in the pointer.
    return (write(devrand, pointer, 1) >= 0);
}

#elif defined WIN32

// On Windows I can query the page that the address is within, and accept
// it if there is read/write access and if it is not a guard page.

bool valid_address(void *pointer)
{   MEMORY_BASIC_INFORMATION mbi = {0};
    if (::VirtualQuery(pointer, &mbi, sizeof(mbi)))
    {   // check the page is not a guard page
        if (mbi.Protect & (PAGE_GUARD|PAGE_NOACCESS)) return false;
        return ((mbi.Protect & (PAGE_READWRITE|PAGE_EXECUTE_READWRITE)) != 0);
    }
    return false;  // ::VirtualQuery failed.
}

#else

bool valid_address(void *pointer)
{   return true;
}

#endif

bool valid_address(uintptr_t pointer)  // an overload to accept integer types
{   return valid_address((void *)pointer);
}

// end of sysfwin.cpp
