// fwin.cpp                                 Copyright A C Norman 2003-2022
//
//
// Window interface for old-fashioned C/C++ applications. Intended to
// be better than just running them within rxvt/xterm, but some people will
// always believe that running them under emacs is best!
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


// Note that the above terms apply and must persist regardless of where or how
// this code is used. A copy of this will be included within a modified
// version of the FOX library and in that context the whole work has to
// be treated subject to the constraints of the LGPL (and not the FOX
// license addendum that would have granted static linking rights, because
// that only applies to unmodified versions of FOX as sanctioned by its
// original author). But this code can also be compiled and used without
// the GUI components, in that case LGPL obligations do not apply but BSD
// ones do.

// $Id$

// The "#ifdef" mess here has been getting out of control. The major
// choice are:
//   Sometimes this file will live within my copy of the FOX library as
//   an extension. If however I am building a system without a GUI at all
//   I can use this file to link on to my own terminal handling code. This
//   is controlled by HAVE_CONFIG_H and through that PART_OF_FOX.
//
//   Then there are variations as between Windows, OX X and Linux. At
//   present systems other then Windows and OS X will use the Linux
//   parts, which really represents a UNix-family system using X11 and
//   so should cover BSD too. Because when this code is built within the
//   FOX library it has a different configure.ac file to configure it
//   I can not comfortably rely on the machine-selection abstractions I
//   use elsewhere in CSL. So I use __APPLE__ to detect the OSX case and
//   WIN32 for Windows - those are set automatically by the compilers that
//   I use. I do not believe thet I have any code here sensitive to the
//   distinction between 32 and 64-bit windows, but within the Linux
//   sections I will sometimes need to be conditional on __CYGWIN__.
//
//   If EMBEDDED is defined a somewhat abbreviated version will be built
//   since in that context simplicity trumps capability.

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
 // HAVE_CONFIG_H
#define PART_OF_FOX 1
extern void initThreadLocals();
#endif // HAVE_CONFIG_H

// For the bulk of CSL the tests on C++ dialect are done in "machine.h",
// but this file is shared with FOX and can not use that header, so it has
// its own copies of the tests.

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif // C++17 support

#if __has_cpp_attribute(maybe_unused)
// C++17 introduced [[maybe_unused]] to avoid warnings about unused variables
// and functions. Earlier versions of gcc and clang supported [[gnu::unused]]
// as a non-standard annotation with similar effect.
#define UNUSED_NAME [[maybe_unused]]
#elif defined __GNUC__
#define UNUSED_NAME [[gnu::unused]]
#else // [[maybe_unused]] or [[gnu::unused]] availability
// In any other case I just omit any annotation and if I get warnings about
// unused things then so be it.
#define UNUSED_NAME
#endif // annotation for unused things

// I am now insisting that CSL be built with C++17 and so the following
// paragraph should be fading in relevance!

// On some platforms it will APPEAR that <filesystem> and std::filesystem
// are available but they will not be. This can perhaps be a consequenec of
// transition arrangements in the C++ comnpiler, library and even the
// operating system being used. On sufficiently old platforms there will be
// no pretence of their availability so I will not have trouble, and on
// fully up to date ones this part of the C++17 standard should be properly
// supported, but somewher in between there can be "trouble"! So I have a
// configure time test that can set FILESYSTEM_NOT_USABLE in the case when
// the notionally standard-conforming test will not suffice.

// I am really sorry about the following test! It is because on a Mac
// one can have #include <filesystem> work and __cpp_lib_filesystem get
// defined for you but std::filesystem may still not be properly available
// because at least some parts of it were not supported until 10.15. I rather
// firmly believe that __cpp_lib_filesystem ought not to have ended up
// defined if the C++17 feature was not actually going to be available. But
// there we go!

//#define STR_HELPER(x) #x
//#define STR(x) STR_HELPER(x)
//#pragma message "MIN VER: " STR(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)

#if defined __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ && \
            __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 101500 && \
            !defined FILESYSTEM_NOT_USABLE

#pragma message "Disabling use of std::filesystem because of OS version min"
#define FILESYSTEM_NOT_USABLE 1

#endif // Hack for Macintosh.

#if !defined FILESYSTEM_NOT_USABLE

#ifndef __has_include
#define __has_include(name) 0
#endif

// I will allow config.h to define HAVE_FILESYSTEM as a promise thae this
// is all OK!
#if !defined HAVE_FILESYSTEM && __has_include(<filesystem>)
#define HAVE_FILESYSTEM 1
#endif // HAVE_FILESYSTEM

#ifdef HAVE_FILESYSTEM
#include <filesystem>
#endif // HAVE_FILESYSTEM

#endif

// Now I can test __cpp_lib_filesystem to see if std::filesystem is
// actually available. If I use it I may need to link -lstdc++fs in gcc
// or -lc++fs in clang!

#include "fwin.h"

extern int fwin_main(int argc, const char *argv[]);

#ifdef WIN32
#include <windows.h>
#include <io.h>
#endif // WIN32

#include <cstring>
#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <cwchar>
#include <cwctype>
#include <ctime>
#include <csignal>
#include <thread>
#include <chrono>
#include <atomic>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::atomic;

#if HAVE_UNISTD_H
#include <unistd.h>
#else // HAVE_UNISTD_H
// The declaration here is an expression of optimism!
extern "C" char *getcwd(const char *s, size_t n);
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>

#ifdef WIN32
#include <windows.h>
#else // WIN32
#include <glob.h>
#endif // WIN32

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#elif defined WIN32
#include <direct.h>
#else
#include <sys/dir.h>
#endif // HAVE_DIRENT_H

#ifdef __APPLE__

#include <Carbon/Carbon.h>
#include <CoreServices/CoreServices.h>

#endif // __APPLE__

#include "termed.h"

#include <cstdio>
#include <cstdlib>

using std::int32_t;
using std::int64_t;
using std::uint32_t;
using std::uint64_t;
using std::string;

// An "my_assert" scheme that lets me write in my own code to print the
// diagnostics. Included here because this files does not icnlude "fx.h".

[[noreturn]] inline void my_abort()
{   std::exit(EXIT_FAILURE);
}

[[noreturn]] inline void my_abort(const char *msg)
{   std::fprintf(stderr, "\n\n!!! Aborting: %s\n\n", msg);
    std::fflush(stderr);
    std::exit(EXIT_FAILURE);
}

template <typename F>
inline void my_assert(bool ok, F&& action)
{
#ifndef NDEBUG
// Use this as in
//     my_assert(predicate, [&]{...});
// where the "..." is an arbitrary sequence of actions to be taken
// if the assertion fails.
    if (!ok)
    {   action();
        my_abort();
    }
#endif //NDEBUG
}

// I have a bunch of macros that I use for desparation-mode debugging,
// and in particular when I have bugs that wriggle back into their lairs
// when I try running under "gdb" or whatever. These print dull messages
// to stderr. The "do..while" idiom is to keep C syntax safe with regard to
// semicolons.

#define D do {                                                         \
          const char *_f_ = std::strrchr(__FILE__, '/');               \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');      \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;              \
          std::fprintf(stderr, "Line %d File %s\n", __LINE__, _f_);    \
          std::fflush(stderr);                                         \
          } while (0)

#define DS(s) do {                                                           \
          const char *_f_ = std::strrchr(__FILE__, '/');                     \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');            \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;                    \
          std::fprintf(stderr, "Line %d File %s: %s\n", __LINE__, _f_, (s)); \
          std::fflush(stderr);                                               \
          } while (0)

#define DX(s) do {                                                          \
          const char *_f_ = std::strrchr(__FILE__, '/');                    \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');           \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;                   \
          std::fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, _f_,    \
                          (long long unsigned)(s));                         \
          std::fflush(stderr);                                              \
          } while (0)

#define DF(f,...) do {                                               \
          const char *_f_ = std::strrchr(__FILE__, '/');             \
          if (_f_ == nullptr) _f_ = std::strrchr(__FILE__, '\\');    \
          if (_f_ == nullptr) _f_ = __FILE__; else _f_++;            \
          std::fprintf(stderr, "Line %d File %s: ", __LINE__, _f_);  \
          std::fprintf(stderr, f, __VA_ARGS__);                      \
          std::fprintf(stderr, "\n");                                \
          std::fflush(stderr);                                       \
          } while (0)


// The value LONGEST_LEGAL_FILENAME should be seen as a problem wrt
// buffer overflow! I will just blandly assume throughout all my code that
// no string that denotes a full file-name (including its path) is ever
// longer than this.
#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif // LONGEST_LEGAL_FILENAME

#ifdef DEBUG

// This will be used as in FWIN_LOG(format,arg,...)
// If DEBUG was enabled it send log information
// to a file with the name fwin-debug.log: I hope that will not (often)
// clash with any file the user has or requires. if programDir has been
// set when you first generate log output then the log file will be put
// there (ie alongside the executable). If not it will go in /tmp. So
// if debugging you might want to ensure that such a directory exists!

static std::FILE *fwin_logfile = nullptr;

#define LOGFILE_NAME "fwin-debug.log"

void fwin_write_log(const char *s, ...)
{
// I expect vfprintf and fflush to be thread-safe, however the test
// on fwin_logfile and the code that creates it could lead to a race
// if two threads both tried to open the log file at the same time. I
// believe that since this is JUST to be used for debugging everything can
// be made safe by insisting that any code that uses threads must execute
// FWIN_LOG() before it starts any thread, so that the log file will get
// created when there is not concurrency to cause confusion. That seems
// lighter weight than messing with a further critical section here.
    int create = (fwin_logfile == nullptr);
    std::va_list x;
// Note that I create this file in "a" (append) mode so that previous
// information there is not lost.
    if (create)
    {   char logfile_name[LONGEST_LEGAL_FILENAME];
        std::memset(logfile_name, 0, sizeof(logfile_name));
        if (std::strcmp(programDir, ".") == 0)
            std::snprintf(logfile_name, sizeof(logfile_name),
                "/tmp/%s", LOGFILE_NAME);
#ifdef __APPLE__
// If the executable I am running exists as
//    ...../something.app/Contents/MacOS/something
// then I will place the log file adjacant to the .app directory rather
// than in the MacOS directory next to the actual raw executable.
        else if (std::snprintf(logfile_name, sizeof(logfile_name),
                               "%s.app/Contents/MacOS",
                               programName),
                 std::strlen(programDir) >= std::strlen(logfile_name) &&
                 std::strcmp(programDir+std::strlen(programDir)-std::strlen(
                                 logfile_name),
                             logfile_name) == 0)
        {   std::snprintf(logfile_name, sizeof(logfile_name), "%.*s/%s",
                         static_cast<int>(std::strlen(programDir)-std::strlen(programName)-19),
                         programDir, LOGFILE_NAME);
        }
#endif // __APPLE__
        else std::snprintf(logfile_name, sizeof(logfile_name),
                           "%s/%s", programDir, LOGFILE_NAME);
        fwin_logfile = std::fopen(logfile_name, "a");
// I provide a fallback in case (perhaps) permissions fail me.
        if (fwin_logfile == nullptr) fwin_logfile =
                std::fopen("/tmp/fwin.log", "w");
    }
    if (fwin_logfile == nullptr) return; // the file can not be used
    if (create)
    {   std::time_t tt = std::time(nullptr);
        struct std::tm *tt1 = std::localtime(&tt);
        std::fprintf(fwin_logfile, "Log segment starting: %s\n",
                     std::asctime(tt1));
    }
    va_start(x, s);
    std::vfprintf(fwin_logfile, s, x);
    va_end(x);
    va_start(x, s);
    std::vfprintf(stderr, s, x);
    va_end(x);
    std::fflush(fwin_logfile);
}

#endif // DEBUG

// The next few are not exactly useful if FOX is not available
// and hence this code will run in line-mode only. However it is
// convenient to leave them available.
//
// Note that FOX as used here is licensed under the LGPL. Its terms
// require that if the work displays a copyright notice during execution
// than the FOX copyright notice and a reference directing users to
// a copy of the LGPL must be displayed too. Thus my suggestion is that the
// about-box information here should not purport to be a copyright notice,
// merely a reminder of who the key authors are. However despite not
// then being obliged to say anything at all about FOX I will put in the
// URL of its web-site, and of course that is a place where the LGPL can
// be found. Anything beyond that would make the size of the about box
// grow in a way I view as clumsy. The wording I use is as requested (but
// under LGPL not actually required!) by the FOX authors.

char about_box_title[40]       = "About XXX";
char about_box_description[40] = "XXX version 1.1";
//                               <icon appears here>
char about_box_rights_1[40]    = "Author info";
char about_box_rights_2[40]    = "Additional author";
char about_box_rights_3[40]    = "This software uses the FOX Toolkit";
char about_box_rights_4[40]    = "(http://www.fox-toolkit.org)";

const char *colour_spec = "-";

char fwin_prompt_string[MAX_PROMPT_LENGTH] = "> ";

int fwin_linelength = 80;

delay_callback_t *delay_callback;

extern const char *my_getenv(const char *s);

#ifdef WIN32
bool programNameDotCom = false;
#endif // WIN32

#ifdef __APPLE__
static int macApp = 0;
#endif // __APPLE__

int windowed = 0;
bool fwin_pause_at_end = false;
bool texmacs_mode = false;

#ifdef HAVE_LIBXFT
bool fwin_use_xft = true;
#else // HAVE_LIBXFT
bool fwin_use_xft = false;
#endif // HAVE_LIBXFT

#ifdef __APPLE__

void mac_deal_with_application_bundle(int argc, const char *argv[])
{
// If I will be wanting to use a GUI and if I have just loaded an
// executable that is not within an application bundle then I will
// use "open" to launch the corresponding application bundle. Doing this
// makes resources (eg fonts) that are within the bundle available and
// it also seems to cause things to terminate more neatly.
    if (!macApp)
    {   char xname[LONGEST_LEGAL_FILENAME];
// Here the binary I launched was NOT being from an application bundle.
// I will try to re-launch it so it is.
        struct stat buf;
        std::memset(xname, 0, sizeof(xname));
        std::snprintf(xname, sizeof(xname), "%s.app", fullProgramName);
        if (stat(xname, &buf) == 0 &&
            (buf.st_mode & S_IFDIR) != 0)
        {
// Well foo.app exists and is a directory, so I will try to use it. Here
// I will let "new" throw an exception if it fails!
            const char **nargs = new const char *[argc+3];
            int i;
#ifdef DEBUG
// Since I am about to restart the program I do not want the new version to
// find that the log file is open and hence not accessible.
            if (fwin_logfile != nullptr)
            {   std::fclose(fwin_logfile);
                fwin_logfile = nullptr;
            }
#endif // DEBUG
            nargs[0] = "/usr/bin/open";
            nargs[1] = xname;
            nargs[2] = "--args";
            for (i=1; i<argc; i++)
                nargs[i+2] = argv[i];
            nargs[argc+2] = nullptr;
// /usr/bin/open foo.app --args [any original arguments]
            execv("/usr/bin/open", const_cast<char * const *>(nargs));
// execv should NEVER return, but if it does I might like to at least
// attempt to display a report including the error code.
            std::fprintf(stderr,
                         "Returned from execv with error code %d\n", errno);
// These days I can not even be certain that calling std::exit() will cause
// and application to terminate (I think) but the use here should NEVER get
// called and so just what happens here is not that important! However if
// execv does return I really want to see any output that may shed light on
// the cause, so flushing the output streams feels like good policy. Even
// if I expect std::exit to flush things too.
            std::fflush(stdout);
            std::fflush(stderr);
            std::exit(1);
        }
    }
}

#endif // __APPLE__

#ifdef PART_OF_FOX

#ifdef WIN32

// This seems to be needed to ensure that if a windows console is closed
// and you launched your program from a cygwin shell (via the cygwin
// execv(e) family) it exits nicely. Otherwise it can be retried several
// times. When that happens it looks really weird!
BOOL CtrlHandler(DWORD x)
{   switch (x)
    {   case CTRL_CLOSE_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
        case CTRL_BREAK_EVENT:
// I had tried the use of ExitProcess(1) here and that was not strong enough
// to avoid program-restart! So I take drastic action with TerminateProcess.
            TerminateProcess(GetCurrentProcess(), 1);
        default:
            return 0;
    }
}

void consoleWait()
{
// If the console had to be created specially to view this information
// it is probable that it will close as soon as the program closes, and so
// to give at least a minimal chance for the user to inspect it I will
// put in a delay here. I will still use atexit() with this because I feel
// reasonably confident that it does not interact with any CSL data at all
// and so the order of invocatio nof it and any other termination processes
// should be unimportant.
    for (int i=5; i!=0; i--)
    {   char title[32];
        std::snprintf(title, sizeof(title), "Exiting after %d seconds", i);
        SetConsoleTitle(title);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

static int ssh_client = 0;

int windows_checks(int is_windowed)
{
// I have tried various messy Windows API calls here to get this right.
// But so far I find that the cases that apply to me are
//    (a) windows command prompt : normal case
//    (b) windows command prompt : stdin redirected via "<" on command line
//                                 or application invoked via a pipe
//    (c) windows, but launched by a double-click, .com version
//    (d) windows, but launched by a double-click, .exe version
//    (e) old (cmd based) cygwin shell : normal case
//    (f) old (cmd based) cygwin shell : stdin redirected via "<"
//    (g) mintty or via ssh : normal case
//    (h) mintty or via ssh : stdin redirected
//
// For each of the above I now document what the windows API tells
// me about my situation...
//    (a) stdin exists and is a tty, a char device and a Console
//    (b) stdin exists and is a pipe or a file NOT a tty
//        (is "< /dev/null" a special case here?)
//    (c) as (a)
//    (d) stdin seems to exist but is not a tty
//    (e) as (a)
//    (f) as (b)
//    (g) stdin exists and is a pipe
//    (h) as (g)
//
// I want (b), (c) and (f) to force a non-windowed treatment.
// I also want (g) to force a non-windowed treatment, but when that
// happens it needs to use curses rather than the Windows Console API to
// cope with local editing and prompt colouring, because there is no
// (visible) Windows console available. So far as I can see there is no
// way for an application not linked against cygwin1.dll to distinguish
// between cases (g) and (h), and no way for it then switch its input
// into raw mode, however a cygwin application can use its version of
// isatty to make this test...
//
// So I will need to make some decisions before actually starting this
// code, and the file "gui-or-not.txt" in the source tree discusses just
// what I do.
    if (programNameDotCom && is_windowed == 2)
    {
// The program was named "xxx.com". I will assume that that means it was
// a console-mode application and it is being launched directly from a
// Windows console.  Why do I feel these are plausible:
//  . The Makefile.in & configure.ac stuff arranges to build xxx.com as
//    console mode and xxx.exe as subsystem:windows
//  . A Windows command prompt will launch xxx.com in preference to xxx.exe
//    if both are present
//  . xxx.com is not given an icon, while xxx.exe is - people should not
//    double-click on the .com version (please)
// Obviously users can subvert this by copying xxx.exe to yyy.com, by
// double clicking where I did not want or by specifying an explicit
// extension when they launch a command from a console prompt. But in such
// cases I will take the view that they will get what they deserve!
        HANDLE h;
        DWORD w;
        CONSOLE_SCREEN_BUFFER_INFO csb;
// If either standard input or output has been redirected I will force use
// of console rather than windowed mode. Thus
//         xxx             launch in a window
//         xxx --nogui     run as console application
//         xxx -w          run as console application
//         xxx < yyy       run as console application
//         xxx > yyy       run as console application
// My hope is that the detection of redirected stdin/stdout will help
// when the application is used in a script. There may remain a dodgy case!
// if xxx is run under a debugger at least some debuggers intercept standard
// input & output so debugging the windowed mode may be harded here. But I
// will defer that worry since the ".exe" not the ".com" file is the version
// with windowed use its prime interface.
//
// New versions of cygwin install a terminal that is not just a regular
// DOS window running bash, but is closer to everything a Unix user might
// expect - however this possibly messes up the tests I make to see if I
// want to run a terminal or a windowed version of everything.
        const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != nullptr && *ssh != 0)
        {   FWIN_LOG("SSH_CLIENT set on Windows, so treat as console app\n");
            ssh_client = 1;
            is_windowed = 0;
        }
        else
        {   h = GetStdHandle(STD_INPUT_HANDLE);
            if (GetFileType(h) != FILE_TYPE_CHAR) is_windowed = 0;
            else if (!GetConsoleMode(h, &w)) is_windowed = 0;
            else
            {   h = GetStdHandle(STD_OUTPUT_HANDLE);
                if (GetFileType(h) != FILE_TYPE_CHAR) is_windowed = 0;
                else if (!GetConsoleScreenBufferInfo(h, &csb)) is_windowed = 0;
            }
        }
    }
    else if (is_windowed == 2)
    {
// The program was named "xxx.exe". I am going to suppose that this has NOT
// been launched from a normal Windows command prompt (since xxx.com would
// have been preferred). I am left with two scenarios. One is that the
// program was launched by double-clicking, and in that case it detached
// from its console as it started. The other is that it was launched from
// a cygwin prompt (which looks for xxx.exe but not xxx.com when you type
// just xxx).
//
        HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
// The discrimination I make here is based on an empirical check of what
// seems to happen under Windows XP with the version of cygwin current as
// of September 2004. What I find is that when stdin has been redirected by
// a shell (either the Windows command shell or cygwin, and in the cygwin
// case either with "<file" or "<<TAG") my standard input handle exists
// and identifies itself as type DISK. The the case of launching the code
// by double-clicking on the .exe file the handle is probably invalid, but
// GetFileType returns FILE_TYPE_UNKNOWN. The end effect is that I can
// detect cases where input has been redirected in a way that appears to
// work in both cases.  Note that if a user wants to launch an application
// via a pipe then they should EITHER launch the ".com" version or (better)
// explictly provide a "-w" flag to indicate that the application should
// work in stream/console mode.
        const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != nullptr && *ssh != 0)
        {   FWIN_LOG("SSH_CLIENT set\n");
            ssh_client = 1;
            is_windowed = 0;
        }
        else if (GetFileType(h) == FILE_TYPE_DISK) is_windowed = 0;
    }
    return is_windowed;
}

void sort_out_windows_console(int is_windowed)
{
// If I am running under Windows and I have set command line options
// that tell me to run in a console then I will create one if one does
// not already exist.
    if (is_windowed == 0)
    {   int consoleCreated = AllocConsole();
        if (consoleCreated)
        {   if (ssh_client)
            {
// This situation seems totally odd to me. I just launched a Windowed-mode
// application and normally when I do that it detaches from the console.
// however rather than having a proper console here I am connected over
// ssh (I am testing this using the cygwin openssh server on Windows 7).
// It appears to be the case that I *DO* have stdin and stdout available to
// me in this case even though I think that when I launch exactly the same
// binary from a directly attached console it detaches and I need to use
// the newly created console....
// The code I have here is based on empirical observation in cases that
// most people will probably not trigger!
                FWIN_LOG("Running windowed mode application via ssh.\n");
            }
            else
            {
#ifdef __CYGWIN__
                std::freopen("/dev/conin", "r+", stdin);
                std::freopen("/dev/conout", "w+", stdout);
                std::freopen("/dev/conout", "w+", stderr);
#else // __CYGWIN__
// I try rather hard here to leave things properly connected to
// the new console. Note opening CONOUT in "w+" mode so it has
// GENERIC_READ_ACCESS.
                HANDLE h;
                std::freopen("CONIN$", "r+", stdin);
                std::freopen("CONOUT$", "w+", stdout);
                std::freopen("CONOUT$", "w+", stderr);
                SetStdHandle(STD_INPUT_HANDLE,
                             CreateFile("CONIN$",
                                        GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, nullptr,
                                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr));
                SetStdHandle(STD_OUTPUT_HANDLE,
                             h = CreateFile("CONOUT$",
                                            GENERIC_READ|GENERIC_WRITE, FILE_SHARE_WRITE, nullptr,
                                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr));
                SetStdHandle(STD_ERROR_HANDLE, h);
#endif // __CYGWIN__
// I will also pause for 5 seconds at the end...
                std::atexit(consoleWait);
            }
        }
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
    }
}

#else // WIN32

#ifdef __APPLE__

static int unix_and_osx_checks(int xwindowed)
{   const char *disp;
// If stdin or stdout is not from a "tty" I will run in non-windowed mode.
// This may help when the system is used in scripts. I worry a bit about
// what the status of stdin/stdout are when launched not from a command line
// but by clicking on an icon...
    if (xwindowed != 0)
    {
// On Unix-like systems I will check the DISPLAY variable, and if it is not
// set I will suppose that I can not create a window. That case will normally
// arise when you have gained remote access to the system eg via telnet or
// ssh without X forwarding. I will also insist that if set it has a ":" in
// its value... that is to avoid trouble with it getting set to an empty
// string. Note that on a Macintosh when I am using the FOX GUI toolkit (as
// is the case here) I need X11 and hence DISPLAY. If I was using the Mac
// native display I would merely omit this test.
        disp = my_getenv("DISPLAY");
        if (disp == nullptr || std::strchr(disp, ':')==nullptr) xwindowed = 0;
    }
// This may be a proper way to test if I am really running in an application
// bundle.
    {   CFBundleRef mainBundle = CFBundleGetMainBundle();
        if (mainBundle == nullptr) macApp = 0;
        else
        {   CFDictionaryRef d = CFBundleGetInfoDictionary(mainBundle);
            if (d == nullptr) macApp = 0;
            else
            {   CFStringRef s =
                    (CFStringRef)CFDictionaryGetValue(d,
                                                      CFSTR("ATSApplicationFontsPath"));
                macApp = (s != nullptr);
            }
        }
    }
// If stdin or stdout is not from a "tty" I will run in non-windowed mode.
// This may help when the system is used in scripts. I worry a bit about
// what the status of stdin/stdout are when launched not from a command line
// but by clicking on an icon...
    if (!macApp &&
        (!isatty(fileno(stdin)) || !isatty(fileno(stdout)))) xwindowed = 0;
// If I am using X11 as my GUI then I am happy to use remote access via
// SSH since I can be using X forwarding - provided DISPLAY is set all can
// be well. However on a Macintosh I do NOT want to launch a window if I
// have connected via ssh since I will not have the desktop forwarded.
    {   const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != nullptr && *ssh != 0)
        {   FWIN_LOG("SSH_CLIENT set on MacOSX\n");
//          ssh_client = 1;
            xwindowed = 0;
        }
    }
    return xwindowed;
}

#else // __APPLE__

static int unix_and_osx_checks(int is_windowed)
{   const char *disp;
// If stdin or stdout is not from a "tty" I will run in non-windowed mode.
// This may help when the system is used in scripts. I worry a bit about
// what the status of stdin/stdout are when launched not from a command line
// but by clicking on an icon...
    if (is_windowed != 0)
    {   if (!isatty(fileno(stdin)) ||
            !isatty(fileno(stdout))) is_windowed = 0;
// On Unix-like systems I will check the DISPLAY variable, and if it is not
// set I will suppose that I can not create a window. That case will normally
// arise when you have gained remote access to the system eg via telnet or
// ssh without X forwarding. I will also insist that if set it has a ":" in
// its value... that is to avoid trouble with it getting set to an empty
// string. Note that on a Macintosh when I am using the FOX GUI toolkit (as
// is the case here) I need X11 and hence DISPLAY. If I was using the Mac
// native display I would merely omit this test.
        disp = my_getenv("DISPLAY");
        if (disp == nullptr ||
            std::strchr(disp, ':')==nullptr) is_windowed = 0;
    }
// If stdin or stdout is not from a "tty" I will run in non-windowed mode.
// This may help when the system is used in scripts. I worry a bit about
// what the status of stdin/stdout are when launched not from a command line
// but by clicking on an icon...
    if ((!isatty(fileno(stdin)) ||
         !isatty(fileno(stdout)))) is_windowed = 0;
// On Unix-like systems I will check the DISPLAY variable, and if it is not
// set I will suppose that I can not create a window. That case will normally
// arise when you have gained remote access to the system eg via telnet or
// ssh without X forwarding. I will also insist that if set it has a ":" in
// its value... that is to avoid trouble with it getting set to an empty
// string.
    disp = my_getenv("DISPLAY");
    if (disp == nullptr ||
        std::strchr(disp, ':')==nullptr) is_windowed = 0;
    return is_windowed;
}

#endif // __APPLE__
#endif // WIN32
#endif // PART_OF_FOX

#ifndef EMBEDDED

// The condition here is so that I can use fwin as a stand-alone interface
// other than as part of CSL/Reduce. This could be useful to somebody wanting
// to use it outside the CSL project
#if defined PART_OF_FOX || defined CSL
int fwin_startup(int argc, const char *argv[],
                 fwin_entrypoint *fwin_main)
{
#else // defined PART_OF_FOX || defined CSL
int main(int argc, const char *argv[])
{   init_thread_locals();
#endif // defined PART_OF_FOX || defined CSL
    int i;
// I want to know the path to the directory from which this
// code was launched. Note that in some cases the prints to stderr
// shown here will be totally ineffective and the code will just seem
// to exit abruptly. Eg that can be the situation if the version being run
// has been linked on Windows as a window-mode (as distinct from console-mode)
// binary, or if it is on a Macintosh not associated with a console. In such
// cases you will just need to debug the code even without a clue!
    if (argc == 0)
    {   std::fprintf(stderr,
                     "argc == 0. You tried to launch the code in a funny way?\n");
        return 1;
    }
    if ((i = find_program_directory(argv[0])) != 0)
    {   std::fprintf(stderr,
                     "Unable to identify program name and directory (%d)\n", i);
        return 1;
    }
    texmacs_mode = false;
// An option "--my-path" just prints the path to the executable
// and stops. An option "--args" indicates that I should not look at any
// more arguments - they may be used by the program that is to be run.
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--my-path") == 0)
        {   std::printf("%s\n", programDir);
            std::exit(0);  // Such a special case that I will exit this way.
        }
        else if (std::strcmp(argv[i], "--args") == 0) break;
    }

#ifdef PART_OF_FOX
// As the very first thing I will do, I will seek an argument
// that is just "-w", and if it is present record that I will want to
// run in text mode, not windowed mode. I also detected "--"
// and use it to flag up a request to run minimised.
// Note that "-w" takes precedence over "--" here...
//
// Well the fuller explanation of the options goes:
//     (none)               run in gui mode in "sensible" cases
//     -w   -w-   --nogui   run in console mode
//     -w+  --gui           run in gui mode if at all possible, fail otherwise.
//     -w.  --guimin        run in guie mode but start minimised.
//
// I run as a minimise window (by default) in the "--" case since I can use
// the window title-bar to report progress even when all output is directed to
// file.
    windowed = 2;
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--args") == 0) break;
        else if (std::strcmp(argv[i], "--texmacs") == 0) texmacs_mode = true;
        else if (std::strncmp(argv[i], "-w", 2) == 0)
        {   if (argv[i][2] == '+') windowed = 1;
            else if (argv[i][2] == '.') windowed = -1;
            else windowed = 0;
            break;
        }
        else if (std::strcmp(argv[i], "--gui") == 0) windowed  = 1;
        else if (std::strcmp(argv[i], "--nogui") == 0) windowed  = 0;
        else if (std::strcmp(argv[i], "--guimin") == 0) windowed  = -1;
        else if (std::strcmp(argv[i], "-h") == 0 ||
                 std::strcmp(argv[i], "-H") == 0)
#ifdef HAVE_LIBXFT
            fwin_use_xft = 0;
#else // HAVE_LIBXFT
            ; // Ignore "-h" option if Xft not available
#endif // HAVE_LIBXFT
// Note well that I detect just "--" as an entire argument here, so that
// extended options "--option" do not interfere.
        else if (std::strcmp(argv[i], "--") == 0 &&
                 windowed != 0) windowed = -1;
    }
    if (texmacs_mode) windowed = 0;
// If there had not been any command-line option to give direction
// about whether to run in a window I will use system-dependent
// schemes to try to decide what to do. The overall policy I want to
// follow is that if I have a graphical environment available I should
// use it. On an X11-based system this can usually be judged by
// looking for a DISPLAY environment variable. On both Windows and
// other systems if the application has been invoked from a pipe
// or using input (or output) redirection then that signals that it
// is expected to use stdin/stdout rather than a GUI.
#ifdef WIN32
    windowed = windows_checks(windowed);
#else // WIN32
    windowed = unix_and_osx_checks(windowed);
#endif // WIN32
#endif // PART_OF_FOX

// REGARDLESS of any decisions about windowing made so for things can be
// forced by command line options.
//    -w+ forces an attempt to run in a window even if it looks as if that
//        would not make sense or would fail. It is mainly for debugging.
//    -w. forces use of a window, but starts it minimised.
//    -w  forces command-line rather than windowed use (can also write
//        "-w-" for this case).
// I also look for some other CSL-specific options that make me feel I
// should adjust behaviour:
//    --  All output will be going to a file. So if the program is to run in
//        windowed mode I will start it off minimised.
//    --texmacs   force the run NOT to try to create its own window,
//        because it is being invoked via a pipe from TeXmacs,
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--args") == 0) break;
        else if (std::strcmp(argv[i], "--texmacs") == 0) texmacs_mode = true;
        else if (std::strncmp(argv[i], "-w", 2) == 0)
        {   if (argv[i][2] == '+') windowed = 1;
            else if (argv[i][2] == '.') windowed = -1;
            else windowed = 0;
            break;
        }
// Note well that I detect just "--" as an entire argument here, so that
// extended options "--option" do not interfere.
        else if (std::strcmp(argv[i], "--") == 0 &&
                 windowed != 0) windowed = -1;
    }
    if (texmacs_mode) windowed = 0;
#if defined PART_OF_FOX && defined WIN32
    sort_out_windows_console(windowed);
#endif // PART_OF_FOX && WIN32

// Windowed or not, if there is an argument "-b" or "-bxxxx" then the
// string xxx will do something about screen colours. An empty string
// will suggest no colouring, the string "-" (as in -b-) whatever default
// I choose.
    colour_spec = "-";
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--args") == 0) break;
        else if (std::strncmp(argv[i], "-b", 2) == 0)
        {   colour_spec = argv[i]+2;
            break;
        }
    }

#ifdef __APPLE__
    if (windowed != 0) mac_deal_with_application_bundle(argc, argv);
#endif // __APPLE__

#ifdef PART_OF_FOX
    if (windowed == 0) return plain_worker(argc, argv, fwin_main);
    else return windowed_worker(argc, argv, fwin_main);
#else // PART_OF_FOX
    return plain_worker(argc, argv, fwin_main);
#endif // PART_OF_FOX
}

// SIGINT really ought not to happen, because when I am using a terminal
// I set it into raw mode, so ^C is treated as input not a request for an
// exception. However some external source could still signal me, so I will
// do what ^C would have.

#ifdef HAVE_SIGACTION
void sigint_handler(int signo, siginfo_t *t, void *v)
#else // !HAVE_SIGACTION
void sigint_handler(int signo)
#endif // !HAVE_SIGACTION
{   if (async_interrupt_callback != nullptr) (
            *async_interrupt_callback)(QUIET_INTERRUPT);
}

#endif // !EMBEDDED

int plain_worker(int argc, const char *argv[],
                 fwin_entrypoint *fwin_main)
{
#ifndef EMBEDDED
// Even though these days I mostly intend ^C to be detected by observing
// it as a character read in raw mode, I probably need to support some
// external task explictly raising the signal. So I trap it here.
#ifdef HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_sigaction = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK | SA_NODEFER;
// (a) restart system calls after signal (if possible),
// (b) use handler that gets more information,
// (c) use alternative stack for the handler,
// (d) leave the SIGINT unmasked while the handler is active.
    if (sigaction(SIGINT, &sa, nullptr) == -1)
        /* I can not thing of anything useful to do if I fail here! */;
#else // !HAVE_SIGACTION
    std::signal(SIGINT, sigint_handler);
#endif // !HAVE_SIGACTION
#endif // !EMBEDDED
    TermSetup ts(argv[0], colour_spec);
    std::strcpy(fwin_prompt_string, "> ");
    return (*fwin_main)(argc, argv);
}


#define INPUT_BUFFER_SIZE 100

static const char *current_line;
UNUSED_NAME static char input_buffer[INPUT_BUFFER_SIZE];
static int chars_left = 0;
UNUSED_NAME static int prompt_needed = 1;

int fwin_plain_getchar()
{   int ch;
    {   while (chars_left == 0)
        {   term_setprompt(fwin_prompt_string);
            current_line = term_getline();
            if (current_line == nullptr) return EOF;  // failed or EOF
            chars_left = std::strlen(current_line);
        }
    }
    chars_left--;
    ch = *current_line++;
    if (ch == (0x1f & 'D')) ch = EOF;
    return ch;
}

#ifndef PART_OF_FOX

void fwin_restore()
{
}

void fwin_putchar(int c)
{
// Despite using termed during keyboard input I will just use the
// ordinary C stream functions for normal output. Provided I do an
// fflush(stdout) before requesting input I should be OK.
#ifdef __CYGWIN__
// If I have built the system under Cygwin then we are running under
// Windows. To keep files tidy I will (mostly) insert CRs at line-end
// in case Cygwin does not...
    if (c == '\n') std::putchar('\r');
#endif // __CYGWIN__
    std::putchar(c);
}

void fwin_puts(const char *s)
{
// See comment above where putchar() is used...
#ifdef __CYGWIN__
    while (*s != 0) fwin_putchar(*s++);
#else // __CYGWIN__
    std::puts(s);
#endif // __CYGWIN__
}


void fwin_printf(const char *fmt, ...)
{   std::va_list a;
    va_start(a, fmt);
// See comment above where putchar() is used...
#ifdef __CYGWIN__
// NOT reconstructed yet @@@
    std::vfprintf(stdout, fmt, a);
#else // __CYGWIN__
    std::vfprintf(stdout, fmt, a);
#endif // __CYGWIN__
    va_end(a);
}

void fwin_vfprintf(const char *fmt, std::va_list a)
{
// See comment above where putchar() is used...
#ifdef __CYGWIN__
// Not reconstructed yet @@@
    std::vfprintf(stdout, fmt, a);
#else // __CYGWIN__
    std::vfprintf(stdout, fmt, a);
#endif // __CYGWIN__
}

void fwin_ensure_screen()
{   std::fflush(stdout);
}

void fwin_report_left(const char *s)
{
}

void fwin_report_mid(const char *s)
{
}

void fwin_report_right(const char *s)
{
}

atomic<bool> mustQuit(false);

int fwin_getchar()
{   return fwin_plain_getchar();
}


void fwin_set_prompt(const char *s)
{   std::strncpy(fwin_prompt_string, s, sizeof(fwin_prompt_string));
    fwin_prompt_string[sizeof(fwin_prompt_string)-1] = 0;
    term_setprompt(fwin_prompt_string);
}

void fwin_menus(char **modules, char **switches,
                review_switch_settings_function *f)
{
}

void fwin_refresh_switches(char **switches, char **packages)
{
}

void fwin_set_help_file(const char *key, const char *path)
{
}

void fwin_acknowledge_tick()
{
}

int fwin_windowmode()
{   return 0;
}

#endif // PART_OF_FOX

int get_current_directory(char *s, size_t n)
{   if (getcwd(s, n) == 0)
    {   switch(errno)
        {   case ERANGE: return -2; // negative return value flags an error.
            case EACCES: return -3;
            default:     return -4;
        }
    }
    else return std::strlen(s);
}

// The next procedure is responsible for establishing information about
// both the "short-form" name of the program launched and the directory
// it was found in. This latter directory may be a good place to keep
// associated resources.
//
// The way of finding the information concerned differs between Windows and
// Unix/Linux, as one might expect.
//
// return non-zero value if failure.

const char *fullProgramName        = "./fwin.exe";
const char *programName            = "fwin.exe";
const char *programDir             = ".";

#ifdef WIN32

static char this_executable[LONGEST_LEGAL_FILENAME];

int find_program_directory(const char *argv0)
{   char *w, *w1;
    char ww[LONGEST_LEGAL_FILENAME];
    int len, ndir, npgm;
// In older code I believed that I could rely on Windows giving me
// the full path of my executable in argv[0]. With bits of mingw/cygwin
// anywhere near me that may not be so, so I grab the information directly
// from the Windows APIs. Except that that turns out to be no good for
// a scheme I have that chains to an executable so it can pick which
// variant to use, so if argv0 looks like a fully rooted windows path
// I will use it!
    std::strcpy(this_executable, argv0);
// In argv0 was enclosed in single or double quotes then remove them.
    if (this_executable[0]=='\'')
    {   for (unsigned int i=0;; i++)
        {   int c = this_executable[i+1];
            if (c == '\'') c = 0;
            this_executable[i] = c;
            if (c == 0) break;
        }
    }
    if (this_executable[0]=='"')
    {   for (unsigned int i=0;; i++)
        {   int c = this_executable[i+1];
            if (c == '"') c = 0;
            this_executable[i] = c;
            if (c == 0) break;
        }
    }
     if (!(std::isalpha(this_executable[0]) &&
          this_executable[1] == ':' &&
          this_executable[2] == '\\'))
    {   GetModuleFileName(nullptr, this_executable,
                          LONGEST_LEGAL_FILENAME-2);
        argv0 = this_executable;
    }
    std::strncpy(ww, this_executable, sizeof(ww));
    ww[sizeof(ww)-1] = 0;
    w = ww;
// I turn every "\" into a "/". This make for better uniformity with other
// platforms.
    while (*w != 0)
    {   if (*w == '\\') *w = '/';
        w++;
    }
    programNameDotCom = false;
    if (ww[0] == 0)      // should never happen - name is empty string!
    {   programDir = ".";
        programName = "fwin";  // nothing really known!
        fullProgramName = "./fwin.exe";
        return 0;
    }

    w = new (std::nothrow) char[1+std::strlen(ww)];
    if (w == nullptr) return 5;           // 5 = new fails
    std::strcpy(w, ww);
    fullProgramName = w;
    len = std::strlen(ww);
// If the current program is called c:/aaa/xxx.exe, then the directory
// is just c:/aaa and the simplified program name is just xxx
// Similarly if the name is xxx.js I want to strip off the ".js".
    if (len > 3 &&
        w[len-3] == '.' &&
        (std::tolower(w[len-2]) == 'j' &&
         std::tolower(w[len-1]) == 's'))
    {   programNameDotCom = false;
        len -= 3;
        w[len] = 0;
    }
    else if (len > 4 &&
        w[len-4] == '.' &&
        ((std::tolower(w[len-3]) == 'e' &&
          std::tolower(w[len-2]) == 'x' &&
          std::tolower(w[len-1]) == 'e') ||
         (std::tolower(w[len-3]) == 'c' &&
          std::tolower(w[len-2]) == 'o' &&
          std::tolower(w[len-1]) == 'm')))
    {   programNameDotCom = (std::tolower(w[len-3]) == 'c');
        len -= 4;
        w[len] = 0;
    }
// I will strip any "win" prefix from the application name and also any
// "32" suffix.
    w1 = w;
    if (std::strlen(w) > 2)
    {   w += std::strlen(w) - 2;
        if (w[0] == '3' && w[1] == '2') w[0] = 0;
    }
    w = w1;
    while (*w != 0) w++;
    while (w != w1 && *w != '/'  && *w != '\\') w--;
    if (*w == '/' || *w == '\\') w++;
    if (std::strncmp(w, "win", 3) == 0)
    {   char *w2 = w + 3;
        while (*w2 != 0) *w++ = *w2++;
        *w = 0;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = fullProgramName[len-npgm-1];
        if (c == '/') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir = ".";  // none really visible
    else
    {   if ((w = new (std::nothrow) char[ndir+1]) == nullptr) return 1;
        std::strncpy(w, fullProgramName, ndir);
        w[ndir] = 0;
        programDir = w;
    }
    if ((w = new (std::nothrow) char[npgm+1]) == nullptr) return 1;
    std::strncpy(w, fullProgramName + len - npgm, npgm);
    w[npgm] = 0;
    programName = w;
    return 0;
}

#else // WIN32

// Different systems put or do not put underscores in front of these
// names. My adaptation here should give me a chance to work whichever
// way round it goes.

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif // S_IFMT

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif // S_IFDIR

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif // S_IFREG

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif // S_ISLNK

// I will not take any action at all to deal with UTF-8 or Unicode issues
// in filenames or paths. Indeed most of Linux and certainly most of my
// code will risk terribly confusion with various perfectly ordinary
// 7-bit characters such as blank (' ') within filenames, so the issue
// of international alphabets there is something I will not really fuss
// about yet.

int find_program_directory(const char *argv0)
{   char pgmname[LONGEST_LEGAL_FILENAME];
    const char *w;
    char *w1;
    int n, n1;
    std::memset(pgmname, 0, sizeof(pgmname));
// If the main reduce executable is has a full path-name /xxx/yyy/zzz then
// I will use /xxx/yyy as its directory To find this I need to find the full
// path for the executable. I ATTEMPT to follow the behaviour of "sh",
// "bash" and "csh".  But NOTE WELL that if anybody launches this code in
// an unusual manner (eg using an "exec" style function) that could confuse
// me substantially. What comes in via argv[0] is typically just the final
// component of the program name - what I am doing here is scanning to
// see what path it might have corresponded to.
//
// If the name of the executable starts with a "/" it is already an
// absolute path name. I believe that if the user types (to the shell)
// something like $DIR/bin/$PGMNAME or ~user/subdir/pgmname then the
// environment variables and user-name get expanded out by the shell before
// the command is actually launched.
    if (argv0 == nullptr ||
        argv0[0] == 0) // Information not there - return
    {   programDir = (const char *)"."; // some sort of default.
        programName = (const char *)"fwin";
        fullProgramName = (const char *)"./fwin";
        return 0;
    }
// I will treat 3 cases here
// (a)   /abc/def/ghi      fully rooted: already an absolute name;
// (b)   abc/def/ghi       treat as ./abc/def/ghi;
// (c)   ghi               scan $PATH to see where it may have come from.
    else if (argv0[0] == '/') fullProgramName = argv0;
    else
    {   for (w=argv0; *w!=0 && *w!='/'; w++) {}   // seek a "/"
        if (*w == '/')      // treat as if relative to current dir
        {   // If the thing is actually written as "./abc/..." then
            // strip of the initial "./" here just to be tidy.
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    // fail! 1=current directory failure
            if (n + std::strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; // Current dir unavailable or full name too long
            else
            {   pgmname[n] = '/';
                std::strcpy(&pgmname[n+1], argv0);
                fullProgramName = pgmname;
            }
        }
        else
        {   const char *path = my_getenv("PATH");
// I omit checks for names of shell built-in functions, since my code is
// actually being executed by here. So I get my search path and look
// for an executable file somewhere on it. I note that the shells back this
// up with hash tables, and so in cases where "rehash" might be needed this
// code may become confused.
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
// I expect $PATH to be a sequence of directories with ":" characters to
// separate them. I suppose it COULD be that somebody used directory names
// that had embedded colons, and quote marks or escapes in $PATH to allow
// for that. In such case this code will just fail to cope.
            if (path != nullptr)
            {   while (*path != 0)
                {   while (*path == ':') path++; // skip over ":"
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > static_cast<int>(sizeof(pgmname)-3-std::strlen(argv0)))
                            return 3; // fail! 3=$PATH element overlong
                    }
// Here I have separated off the next segment of my $PATH and put it at
// the start of pgmname. Observe that to avoid buffer overflow I
// exit abruptly if the entry on $PATH is itself too big for my buffer.
                    pgmname[n++] = '/';
                    std::strcpy(&pgmname[n], argv0);
// see if the file whose name I have just built up exists at all.
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode; // info about the file found
// I now want to check if there is a file of the right name that is
// executable by the current (effective) user.
                    if (protection & S_IXOTH ||
                        (mygid == hisgid && protection & S_IXGRP) ||
                        (myuid == hisuid && protection & S_IXUSR))
                    {   ok = 1;   // Haha - I have found the one we ...
                        break;    // are presumably executing!
                    }
                }
            }
            if (!ok) return 4;    // executable not found via $PATH
// Life is not yet quite easy! $PATH may contain some items that do not
// start with "/", ie that are still local paths relative to the
// current directory. I want to be able to return an absolute fully
// rooted path name! So unless the item we have at present starts with "/"
// I will stick the current directory's location in front.
            if (pgmname[0] != '/')
            {   char temp[LONGEST_LEGAL_FILENAME];
                std::memset(temp, 0, sizeof(temp));
                std::strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    // fail! 1=current directory failure
                if ((n + std::strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                std::strcpy(&pgmname[n], temp);
            }
            fullProgramName = pgmname;
        }
    }
// Now if I have a program name I will try to see if it is a symbolic link
// and if so I will follow it.
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        std::memset(temp, 0, sizeof(temp));
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            std::strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
// Now fullProgramName is set up, but may refer to an array that
// is stack allocated. I need to make it proper!
    w1 = new (std::nothrow) char[1+std::strlen(fullProgramName)];
    if (w1 == nullptr) return 5;           // 5 = new fails
    std::strcpy(w1, fullProgramName);
    fullProgramName = w1;
    size_t len = std::strlen(w1);
    if (len > 3 &&
        w1[len-3] == '.' &&
        (std::tolower(w1[len-2]) == 'j' &&
         std::tolower(w1[len-1]) == 's'))
    {
#ifdef WIN32
        programNameDotCom = false;
#endif
        len -= 3;
        w1[len] = 0;
    }
#ifdef __CYGWIN__
// Now if I built on raw cygwin I may have an unwanted ".com" or ".exe"
// suffix, so I will purge that! This code exists here because the raw
// cygwin build has a somewhat schitzo view as to whether it is a Windows
// or a Unix-like system. When I am using raw cygwin I am really not
// living in a Windows world.
    else if (len > 4)
    {   char *w2 = w1 + len - 4;
        if (w2[0] == '.' &&
            ((std::tolower(static_cast<unsigned char>(w2[1])) == 'e' &&
              std::tolower(static_cast<unsigned char>(w2[2])) == 'x' &&
              std::tolower(static_cast<unsigned char>(w2[3])) == 'e') ||
             (std::tolower(static_cast<unsigned char>(w2[1])) == 'c' &&
              std::tolower(static_cast<unsigned char>(w2[2])) == 'o' &&
              std::tolower(static_cast<unsigned char>(w2[3])) == 'm'))) w2[0] = 0;
    }
    if (len > 2)
    {   char *w2 = w1 + len - 2;
        if (w2[0] == '3' && w2[1] == '2') w2[0] = 0;
    }
// If I am building a cygwin version I will remove any prefix
// "cygwin-", "cygwin64-" or "win" from the front of the name of the
// executable and also any "32" suffix.
    while (*w1 != 0) w1++;
    while (w1 != fullProgramName && *w1 != '/'  && *w1 != '\\') w1--;
    if (*w1 == '/' || *w1 == '\\') w1++;
    if (std::strncmp(w1, "cygwin-", 7) == 0)
    {   char *w2 = w1 + 7;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
    else if (std::strncmp(w1, "cygwin64-", 9) == 0)
    {   char *w2 = w1 + 9;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
    if (std::strncmp(w1, "win", 3) == 0)
    {   char *w2 = w1 + 3;
        while (*w2 != 0) *w1++ = *w2++;
        *w1 = 0;
    }
#endif // __CYGWIN__
// OK now I have the full name, which is of the form
//   abc/def/fgi/xyz
// and I need to split it at the final "/" (and by now I very fully expect
// there to be at least one "/".
    for (n=std::strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               // 6 = no "/" in full file path
    w1 = new (std::nothrow) char[n+1];
    if (w1 == nullptr) return 7;           // 7 = new fails
    std::strncpy(w1, fullProgramName, n);
    w1[n] = 0;
// Note that if the executable was "/foo" then programDir will end up as ""
// so that programDir + "/" + programName works out properly.
    programDir = w1;
    n1 = std::strlen(fullProgramName) - n;
    w1 = new (std::nothrow) char[n1];
    if (w1 == nullptr) return 8;           // 8 = new fails
    std::strncpy(w1, fullProgramName+n+1, n1-1);
    w1[n1-1] = 0;
    programName = w1;
    return 0;                          // whew!
}

#endif // WIN32


#ifndef S_IRUSR
#ifdef __S_IRUSR
#define S_IRUSR __S_IRUSR
#endif // __S_IRUSR
#endif // S_IRUSR

#ifndef S_IWUSR
#ifdef __S_IWUSR
#define S_IWUSR __S_IWUSR
#endif // __S_IWUSR
#endif // S_IWUSR

#ifndef S_IXUSR
#ifdef __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif // __S_IXUSR
#endif // S_IXUSR

extern int get_home_directory(char *b, size_t len);
extern int get_users_home_directory(char *b, size_t len);

static lookup_function *look_in_variable = nullptr;

void fwin_set_lookup(lookup_function *f)
{   look_in_variable = f;
}

void process_file_name(char *filename, const char *old, size_t n)
// This procedure maps filenames by expanding some environment
// variables.  It is very thoroughly system specific, which is why it
// is in this file.  See also LONGEST_LEGAL_FILENAME in "tags.h" for a
// limit on the permitted size of an expanded filename.
// The input (old) is not necessarily properly terminated as a C string,
// so n says how many characters to inspect.  Build a converted name
// in filename.
// At present the expansions I allow are:
//
//    $xxx   (terminated by '.', '/' or '\' with at least one char x)
//    ${xxx} (self-terminating)
//           First check for a Lisp variable @xxx. If this is set (and is
//           a string or a symbol) then its value is used. If not then
//           next inspect the environment variable xxx and dump its
//           value into the output.  If the variable is unset then a check
//           is made for the value of a global lisp variable called $xxx,
//           and if that exists and is a string or symbol it is used.
//           If $xxx is undefined a null string is inserted.
//           If one of the variables is defined but has an improper value
//           then the whole file-translation fails.
//           The use of two Lisp variables makes it possible to control
//           precedence between these and shell variables.
//           At one stage I make the search order $xxx, env, @xxx, but then
//           in shell scripts it is easier to go "-D@xxx=..." because
//           "-D$xxx=..." tends to get subject to shell expansion. So now
//           I give priority to the version I use most, to avoid being bitten
//           when somebody has a stray shell variable set.
//
//    ~      ) followed by '.', '/' or '\'
//    ~xxx   )
//           On Unix these try to find home directories using
//           getpwuid(getuid()) for '~' and getpwnam() for ~xxx.
//           If that fails ~ expands into nothing at all.
//           This syntax is only recognised at the very start of a file-name.
//           For systems other than Unix this syntax will not be useful and
//           should be avoided, however as an experimental place-holder I
//           may do things with environment variables called HOME etc.
//
// I convert file-names of the form aaa/bbb/ccc.ddd into something
// acceptable to the system being used, even though this may result in
// some native file titles that include '/' characters becoming unavailable.
// The reasoning here is that scripts and programs can then use Unix-like
// names and non-Unix hosts will treat them forgivingly.
//
{   int i;
    int c;
    char *o;
    if (n == 0)
    {   *filename = 0;
        return;    // deem zero-length name to be illegal
    }
    o = filename;
    c = *old;
// First I deal with a leading "~"
    if (c == '~')
    {   old++;
        n--;
        while (n != 0)
        {   c = *old;
            if (c == '.' || c == '/' || c == '\\') break;
            old++;
            n--;
            *o++ = static_cast<char>(c);
        }
        *o = 0;
// actually deciding what the home directory is is passed down to a
// system-specific call, but it is not to be relied upon especially
// on personal computers.
        if (o == filename)  // '~' on its own
        {   get_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + std::strlen(filename);
        }
        else
        {   get_users_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + std::strlen(filename);
        }
    }
// Having copies a user-name across (if there was one) I now copy the
// rest of the file-name, expanding $xxx and ${xxx} as necessary.
    while (n != 0)
    {   c = *old++;
        n--;
// If I find a "$" that is either at the end of the file-name or that is
// immediately followed by ".", "/" or "\" then I will not use it for
// parameter expansion. This at least gives me some help with the RISCOS
// file-name $.abc.def where the "$" is used to indicate the root of the
// current disc. Well RISCOS is no longer supported here so this does
// not worry me a lot!
        if (c == '$' && n != 0 &&
            (c = *old) != '.' && c != '/' && c != '\\')
        {   char *p = o;
            const char *w;
// I collect the name of the parameter at the end of my file-name buffer,
// but will over-write it later on when I actually do the expansion.
            if (c == '{')
            {   old++;
                n--;
                while (n != 0)
                {   c = *old++;
                    n--;
                    if (c == '}') break;
                    *p++ = static_cast<char>(c);
                }
            }
            else
            {   while (n != 0)
                {   c = *old;
                    if (c == '.' || c == '/' || c == '\\') break;
                    old++;
                    n--;
                    *p++ = static_cast<char>(c);
                }
            }
            *p = 0;
            i = std::strlen(o) + 2;
            while (i-- != 0) o[i] = o[i-1];
            if (look_in_variable != nullptr &&
                (p = (*look_in_variable)(o, '@')) != nullptr &&
                p != o) o = p;
            else if ((w = my_getenv(o+1)) != nullptr)   // Shell variable?
            {   std::strcpy(o, w);
                o = o + std::strlen(o);
            }
            else if (look_in_variable != nullptr &&
                     (p = (*look_in_variable)(o, '$')) != nullptr)
                o = p;
            else
            {   *filename = 0;  // return reporting failure
                return;
            }
        }
        else *o++ = static_cast<char>(c);
    }
    *o = 0;
#ifdef WIN32
// Now the filename has had $ and ~ prefix things expanded - I "just"
// need to deal with sub-directory representation issues. Specifically I need
// to map "/" separators into "\" so that if a user presents a file
// name such as aaa/bbb/ccc.d it gets passed to the operating system
// as aaa\bbb\ccc.d
// Note that I enable this code under the heading MS_DOS but really it
// means any file-system (eg Windows too) that uses "\" as its main
// directory separator character.
// As of September 2004 I will also map an intial sequence
//         /cygdrive/x/
// onto    x:\ (ie the Windows style path)

    if (std::strncmp(filename, "/cygdrive/", 10) == 0 &&
        filename[11] == '/')
    {   char *p = filename+2, *tail = filename+11;
        filename[0] = filename[10];
        filename[1] = ':';
        while (*tail != 0) *p++ = *tail++;
        *p = 0;
    }
// I map "/" characters in MSDOS filenames into "\" so that users
// can give file names with Unix-like slashes as separators if they want.
// People who WANT to use filenames with '/' in them will be hurt.
    {   int j;
        char *tail = filename;
        while ((j = *tail) != 0)
        {   if (j == '/') *tail = '\\';
            tail++;
        }
// stat and friends do not like directories referred to as "\foo\", so check
// for a trailing slash, being careful to respect directories with names
// like "\" and "a:\".
        j = std::strlen(filename);
        if (j > 0 && j != 1 && !(j == 3 && *(filename+1) == ':'))
        {   if ( (*(tail - 1) == '\\')) *(tail - 1) = 0;
        }
    }
#else // WIN32
#if defined __APPLE__ && !defined EMBEDDED
// For MacOS the issue of "aliases" arises. The "preferred" file system
// is HFS+ and that supports both links and aliases, but at the very least
// some old users and legacy applications will certainly continue to use
// links. However the Posix-style APIs do not provide any way to deal with
// them! So here I used to have some Carbon calls to map a path to an
// alias into a path to the file it refers to. This code was requested by
// Thomas Sturm who provided a skeleton chunk of code showing what APIs
// needed to be used and references to the documentation to them, so thanks
// are due.
// Unfortunately Apple have now deprecated the APIs used here, and because
// they now did that quite a long while ago I have removed the code - which
// when present led to compile-time warnings about its status.
// So now Mac aliases are not supported and symbolic or hard links should
// be used instead!
// In a further while I intend to remove this comment as well as the code
// that used to come with it.
#endif // __APPLE__
#endif // WIN32
}

// datestamps that I store away have given me significant
// trouble with regard to portability - so now I deal with times by
// talking to the system in terms of broken down local time (struct tm).
// I then pack things up for myself to get 32-bit timestamps. The
// encoding I use aims at simplicity - it treats all months as 31 days
// and thus does not have to worry about leap years etc.  The effect will be
// rather as if dates were stored as strings. And MAYBE I thereby avoid
// some of the oddities that arise when data files containing packed dates
// are transported across time-zones.
//
// NOTE: dates here are based from 1970, and this will lead to overflow
// beyond 32-bit signed offsets in January 2038. At the time of writing that
// is around some years ahead, and I intend not to worry. Note it is important here to
// us an unsigned number or else the overflow is sooner and might even cause
// genuine pain! But by using unsigned values I put myself in a situation
// where I can not talk about dates earlier then 1970, but I can look
// forward to around 2099 and that does seem far enough ahead to be not much
// of a problem.
//
// ANOTHER NOTE: I only allow the "seconds" field to run from 0 to 59.
// In consequence I am quite possibly going to mess up when there are
// leap seconds, and this confusion could make times processed here
// disagree across systems by up to the number of leap seconds that
// have been used to date. Well I have quite severe doubts about time
// agreement closer than a few seconds anyway and so again I am going to
// ignore this oddity! But those who keep systems synchronised at a
// millisecond or microsecond resolution (GPS anybody?) might need to
// know I have been sloppy.

void unpack_date(unsigned long int r,
                 int *year, int *mon, int *day,
                 int *hour, int *min, int *sec)
{   *sec  = r%60; r = r/60;
    *min  = r%60; r = r/60;
    *hour = r%24; r = r/24;
    *day  = r%32; r = r/32;
    *mon  = r%12; r = r/12;
// Please note that the Standard C "struct tm" structure specifies dates
// in terms of years since 1900. Thus from the year 2000 on the year will
// be a value of at least 100, but that is not supposed to be any special
// cause of disaster. In particular the calculation involving "+70"
// rather than "+1970" is NOT a bug here!
    *year = 70+r;
}

unsigned long int pack_date(int year, int mon, int day,
                            int hour, int min, int sec)
{   unsigned long int r = (year-70)*12 + mon;
    r = r*32 + day;
    r = r*24 + hour;
    r = r*60 + min;
    return r*60 + sec;
}

// getenv() is a mild pain: Windows seems
// to have a strong preference for upper case names.  To allow for
// all this I do not call getenv() directly but go via the following
// code that can patch things up.

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    std::memset(uppercasename, 0, sizeof(uppercasename));
    while ((c = *s++) != 0) *p++ = std::toupper(c);
    *p = 0;
    return std::getenv(uppercasename);
#else // WIN32
    return std::getenv(s);
#endif // WIN32
}


int my_system(const char *s)
{   return std::system(s);
}

#define DO_NOT_USE_GETUID 1   // For MinGW

#ifndef DO_NOT_USE_GETUID
// "machine.h" should set DO_NOT_USE_GETUID if that function is not
// properly available. Not having it will make the treatment of
// (eg) "~xxx/..." in filenames less satisfactory.

#include <pwd.h>

int get_home_directory(char *b, size_t len)
{   int i;
    struct passwd *pw = getpwuid(getuid());
    std::strcpy(b, pw->pw_dir);
    i = std::strlen(b);
// Here the directory handed back has "/" forced in as its final character
    if (b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, size_t len)
{   struct passwd *pw = getpwnam(b);
    if (pw != nullptr) std::strcpy(b, pw->pw_dir);
    else std::strcpy(b,
                         ".");    // use current directory if getpwnam() fails
    return std::strlen(b);
}

#else // DO_NOT_USE_GETUID

int get_home_directory(char *b, size_t len)
{   size_t i;
    const char *s =
        std::getenv("HOME"); // Probably works with most shells
    if ((i = std::strlen(s)) > len) s = "~";
    std::strcpy(b, s);
    if ( b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, size_t len)
{   static_cast<void>(len);
    std::strcpy(b,
                ".");    // use current directory if getpwnam() no available
    return 1;
}

#endif // DO_NOT_USE_GUID

typedef void filescan_function(string name, string leafname,
                               int why, long int size);

// On a Macintosh it seems that __cpp_lib_filesystem can be defined without
// needing to #include <filesystem> and in cases when code that uses
// std::filesystem will then not even compile!

#if defined __cpp_lib_filesystem && !defined FILESYSTEM_NOT_USABLE

// Here is some code thar uses std::filesystem, or that might be able to!
// If there are functions here that could not exploit the C++17 facilities
// then they can be moved outside the scope of the #ifdef.

#ifdef WIN32

#include "windows.h"

int Cmkdir(const char *name)
{   SECURITY_ATTRIBUTES s;
    s.nLength = sizeof(s);
    s.lpSecurityDescriptor = nullptr;
    s.bInheritHandle = FALSE;
    return CreateDirectory(name, &s);
}

int truncate_file(std::FILE *f, long int where)
{   if (std::fflush(f) != 0) return 1;
#ifdef __CYGWIN__
    if (std::fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  // Returns zero if success
#else // __CYGWIN__
    return chsize(fileno(f), where);    // Returns zero if success
#endif // __CYGWIN__
}

void set_filedate(char *name, unsigned long int datestamp,
                  unsigned long int filetype)
{   HANDLE h = CreateFile(name, GENERIC_WRITE, 0, nullptr,
                          OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    SYSTEMTIME st;
    FILETIME ft;
    int yr, mon, day, hr, min, sec;
// Here datestamp is a time expressed (sort of) in seconds since the start
// of 1970. * I need to convert it into a broken-down SYSTEMTIME so that I
// can then re-pack it as a Windows-NT FILETIME....
    unpack_date(datestamp, &yr, &mon, &day, &hr, &min, &sec);
    st.wMilliseconds = 0;
    st.wYear = yr + 1900;  // Windows NT uses full dates since the year 0
    st.wMonth = mon + 1;
    st.wDay = day;
    st.wHour = hr;
    st.wMinute = min;
    st.wSecond = sec;
    SystemTimeToFileTime(&st, &ft);
    SetFileTime(h, nullptr, nullptr, &ft);
    CloseHandle(h);
}

void put_fileinfo(date_and_type *p, char *name)
{   unsigned long int datestamp, filetype;
    struct stat file_info;
    struct std::tm *st;
    stat(name, &file_info);
    st = std::localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;
    p->date = datestamp;
    p->type = filetype;
}

#else // WIN32

// On some Unix variants I may want this declaration inserted and on others
// it would clash with a system-provided header file. Ugh! With luck the C
// compiler will invent a suitable calling convention even if a declaration
// is not present.
// extern ftruncate(int, int);

int truncate_file(std::FILE *f, long int where)
{   if (std::fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  // Returns zero if success
}

// extern void mkdir(const char *, unsigned short int);

int Cmkdir(const char *s)
{   mkdir(s, 0775);
    return 1;
}

#include <utime.h>

#if defined EMBEDDED && defined __ARM_EABI__ && !defined __linux__

void utime(const char *s, struct utimbuf *t);

#endif // EMBEDDED etc

void set_filedate(char *name, unsigned long int datestamp,
                  unsigned long int filetype)
{
#ifndef EMBEDDED
#ifdef UTIME_TIME_T
    std::time_t tt[2];
#else // UTIME_TIME_T
    struct utimbuf tt;
#endif // UTIME_TIME_T
    std::time_t t0;
    struct std::tm st;
    unpack_date(datestamp, &st.tm_year, &st.tm_mon, &st.tm_mday,
                &st.tm_hour, &st.tm_min, &st.tm_sec);
    st.tm_isdst = -1;
    t0 = std::mktime(&st);
#ifdef UTIME_TIME_T
    tt[0] = tt[1] = t0;
#else // UTIME_TIME_T
    tt.actime = tt.modtime = t0;
#endif // UTIME_TIME_T
    utime(name, &tt);
#endif // EMBEDDED
}

void put_fileinfo(date_and_type *p, char *name)
{   unsigned long int datestamp, filetype;
    struct stat file_info;
    struct std::tm *st;
// Read file parameters...
    stat(name, &file_info);
    st = std::localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;  // should get access status here?
    p->date = datestamp;
    p->type = filetype;
}

#endif // WIN32

// If I am to process directories I need a set of routines that will
// scan sub-directories for me.  This is necessarily dependent on
// the operating system I am running under, hence the conditional compilation
// here.  The specification I want is:
//       void scan_directory(string dir,
//                    void (*proc)(string name, string leafname,
//                                 int why, long int size));
//
// This is called with a directory-name as its first argument
// and a function as its second.
// It calls the function for every directory and every file that can be found
// rooted from the given place.  
// When a simple file is found the procedure is called with the name of the
// file, why=0, and the length (in bytes) of the file.  For a directory
// the function is called with why=1, then the contents of the directory are
// processed. Files are returned in alphabetic order. There is no
// guarantee of useful behaviour if some of the files to be scanned are
// flagged as  "invisible" or "not readable" or if they are otherwise special.
//
// I also provide a similar function scan_files() with the same arguments that
// does just the same except that it does not recurse into sub-directories,

// For CSL's purposes the following 3 are in syscsl.h, but in general I do not
// want to use that header with random fwin applications...
#define SCAN_FILE       0
#define SCAN_DIR        1

// If I am using C++17 it has std::filesystem and that provides pretty well
// exactly the facilities that I want. Because at the time of writing this I
// can not guarantee that C++17 will always be available I will also provide
// some system-specific fallback code, but I look forward to the time that
// it feels safe to discard that!


void scan_directory(string dir, filescan_function *proc)
{   const std::filesystem::path pathToShow{dir};
    if (!std::filesystem::is_directory(pathToShow)) return;
    std::vector<std::filesystem::directory_entry> res;
    for (const auto& entry :
             std::filesystem::recursive_directory_iterator(pathToShow))
    {   res.push_back(entry);
    }
    std::sort(res.begin(), res.end(),
        [](std::filesystem::directory_entry &a,
           std::filesystem::directory_entry &b) -> bool
        {  return a.path().string().compare(b.path().string()) < 0;
        });
    for (auto entry : res)
    {   const auto filenameStr = entry.path().filename().string();
        const auto fullnameStr = entry.path().string();
        if (entry.is_directory())
            proc(fullnameStr, filenameStr, SCAN_DIR, 0);
        else if (entry.is_regular_file())
            proc(fullnameStr, filenameStr, SCAN_FILE,
                 std::filesystem::file_size(fullnameStr));
    }
}

void scan_files(string dir, filescan_function *proc)
{   const std::filesystem::path pathToShow{dir};
    if (!std::filesystem::is_directory(pathToShow)) return;
    std::vector<std::filesystem::directory_entry> res;
    for (const auto& entry : std::filesystem::directory_iterator(pathToShow))
    {   res.push_back(entry);
    }
    std::sort(res.begin(), res.end(),
        [](std::filesystem::directory_entry &a,
           std::filesystem::directory_entry &b) -> bool
        {  return a.path().string().compare(b.path().string()) < 0;
        });
    for (auto entry : res)
    {   const auto filenameStr = entry.path().filename().string();
        const auto fullnameStr = entry.path().string();
        if (entry.is_directory())
            proc(fullnameStr, filenameStr, SCAN_DIR, 0);
        else if (entry.is_regular_file())
            proc(fullnameStr, filenameStr, SCAN_FILE,
                 std::filesystem::file_size(fullnameStr));
    }
}


std::FILE *open_file(char *filename, const char *old, size_t n,
                     const char *mode, std::FILE *old_file)
{
// mode is something like "r" or "w" or "rb", as needed by fopen(),
// and old_file is nullptr normally, but can be a (FILE *) to indicate
// the use of freopen rather than fopen.
    std::FILE *ff;
    process_file_name(filename, old, n);
    if (*filename == 0) return nullptr;
    if (old_file == nullptr) ff = std::fopen(filename, mode);
    else ff = std::freopen(filename, mode, old_file);
// In suitable cases when the first attempt to open the file fails I
// will try creating any necessary directories and then try again.
    if (ff==nullptr && *mode=='w')
    {   char *p = filename;
        while (*p != 0)
        {   int ch = *p;
            if (ch == '/' || ch == '\\')
            {   *p = 0;
                Cmkdir(filename);
                *p = ch;
            }
            p++;
        }
        if (old_file == nullptr) ff = std::fopen(filename, mode);
        else ff = std::freopen(filename, mode, old_file);
    }
    if (ff != nullptr) std::setvbuf(ff, nullptr, _IOFBF, 0x10000);
    return ff;
}


static char err_buf[LONGEST_LEGAL_FILENAME+100];

char *change_directory(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0)
    {   std::snprintf(err_buf, sizeof(err_buf),
            "Filename \"%s\" invalid.", old);
        return err_buf;
    }
    std::error_code ec;
    std::filesystem::current_path(
        std::filesystem::path(filename), ec);
    if (ec)
    {   std::strncpy(err_buf, ec.message().c_str(), sizeof(err_buf)-1);
        return err_buf;
    }
    return nullptr;
}

int create_directory(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    std::error_code ec;
    std::filesystem::create_directory(
        std::filesystem::path(filename), ec);
    if (ec) return 1;
    return 0;
}


int delete_file(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename != 0)
    {   std::error_code ec;
        std::filesystem::remove_all(std::filesystem::path(filename), ec);
        if (ec) return 1;
    }
    return 0;
}

int delete_wildcard(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    {
#ifdef WIN32
        HANDLE h;
        WIN32_FIND_DATA gg;
        h = FindFirstFile(filename, &gg);
        if (h != INVALID_HANDLE_VALUE)
        {   for (;;)
            {   std::error_code ec;
                std::filesystem::remove_all(
                    std::filesystem::path(gg.cFileName), ec);
                if (!FindNextFile(h, &gg)) break;
            }
            FindClose(h);
        }
#else // WIN32
        glob_t gg;
        size_t i;
        if (glob(filename, GLOB_NOSORT, nullptr, &gg) == 0)
        {   std::error_code ec;
             for (i=0; i<gg.gl_pathc; i++)
                std::filesystem::remove_all(
                    std::filesystem::path(gg.gl_pathv[i]), ec);
            globfree(&gg);
        }
#endif // WIN32
    }
    return 0;
}

int64_t file_length(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    std::filesystem::path p(filename);
    if (!std::filesystem::exists(p)) return -1;
    std::error_code ec;
    std::uintmax_t len = std::filesystem::file_size(p, ec);
    if (ec) return 0;
    return static_cast<int64_t>(len);
}

void list_directory_members(char *filename, const char *old,
                            size_t n,
                            filescan_function *fn)
{   process_file_name(filename, old, n);
    scan_files(filename, fn);
}

// The next function is provided because C++17 and gcc-9 have some issues
// about more direct conversion from file_time_type to time_t. This is
// a stackoverflow response to the issue, based on the expectation that
// subtracting time values to obtain a duration is liable to be easy.

template <typename TP>
std::time_t to_time_t(TP tp)
{   using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

bool file_exists(char *filename, const char *old, size_t n, char *tt)
// This returns YES if the file exists, and as a side-effect copies a
// textual form of the last-changed-time of the file into the buffer tt.
{   process_file_name(filename, old, n);
    if (*filename == 0) return false;
    std::error_code ec;
    if (!std::filesystem::exists(std::filesystem::path(filename), ec) || ec)
        return false;
    std::filesystem::file_time_type datestamp =
        std::filesystem::last_write_time(std::filesystem::path(filename), ec);
    std::time_t cftime = to_time_t(datestamp);
//      decltype(datestamp)::clock::to_time_t(datestamp); // a more proper way!
    std::strcpy(tt, std::ctime(&cftime));
    return true;
}

bool directoryp(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (!std::filesystem::exists(std::filesystem::path(filename)))
        return false;
    std::error_code ec;
    return std::filesystem::is_directory(
        std::filesystem::path(filename), ec) && !ec;
}


char *get_truename(char *filename, const char *old, size_t n)
{   struct stat buf;
    char *temp, *fn, *dir;
    char pwd[LONGEST_LEGAL_FILENAME];
    std::memset(pwd, 0, sizeof(pwd));

    process_file_name(filename, old, n);
    if (*filename == 0)
    {   std::strcpy(filename, "truename");
        return nullptr;
    }

    // Find out whether we have a file or a directory
    if (stat(filename,&buf) == -1)
    {   std::strcpy(filename, "truename: cannot stat file");
        return nullptr;
    }

    // Store current directory
    if (get_current_directory(pwd, LONGEST_LEGAL_FILENAME) < 0)
    {   std::strcpy(filename,
                    "truename: cannot get current working directory");
        return nullptr;
    }

    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   // We have a directory
        char *dir1;
        if (chdir(filename) != 0)
        {   std::strcpy(filename, "truename: cannot change directory");
            return nullptr;
        }
        dir1 = new (std::nothrow) char[LONGEST_LEGAL_FILENAME];
        if (dir1 == nullptr)
        {   std::strcpy(filename, "truename: run out of memory");
            return nullptr;
        }
        if (getcwd(dir1,LONGEST_LEGAL_FILENAME) == nullptr)
        {   std::strcpy(filename,
                        "truename: cannot get current working directory");
            delete [] dir1;
            return nullptr;
        }
        if (chdir(pwd) != 0)
        {   std::strcpy(filename, "truename: cannot change directory");
            delete [] dir1;
            return nullptr;
        }
// Axiom-specific hack: truename preserves '/' at the end of
// a path
        if (old[n-1] == '/' && dir1[std::strlen(dir1)-1] != '/')
        {   n = std::strlen(dir1);
            dir1[n]   = '/';
            dir1[n+1] = '\0';
        }
        return dir1;
    }
    else
    {   // Assume we have some kind of file
        temp = std::strrchr(filename,'/');
        if (temp)
        {   // Found a directory component
            char theDir[LONGEST_LEGAL_FILENAME];
            std::memset(theDir, 0, sizeof(theDir));
            fn = new (std::nothrow) char[1+std::strlen(temp)];
            if (fn == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                return nullptr;
            }
            std::strcpy(fn, temp);
            *temp = '\0';
// fn is now "/file" and filename is the directory
            if (chdir(filename) != 0)
            {   std::strcpy(filename, "truename: cannot change directory");
                delete [] fn;
                return nullptr;
            }
            if (get_current_directory(theDir, LONGEST_LEGAL_FILENAME) < 0)
            {   std::strcpy(filename,
                            "truename: cannot get current working directory");
                delete [] fn;
                return nullptr;
            }
            temp = theDir;
            if (chdir(pwd) != 0)
            {   std::strcpy(filename, "truename: cannot change directory");
                delete [] fn;
                return nullptr;
            }
            dir = new (std::nothrow)
                char[std::strlen(temp) + std::strlen(fn) + 1];
            if (dir == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                delete [] fn;
                return nullptr;
            }
            std::strcpy(dir, temp);
            std::strcat(dir, fn);
            delete [] fn;
            return dir;
        }
        else
        {   dir = new (std::nothrow)
                char[std::strlen(pwd) + std::strlen(filename) + 2];
            if (dir == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                return nullptr;
            }
            std::strcpy(dir, pwd);
            std::strcat(dir, "/");
            std::strcat(dir, filename);
            return dir;
        }
    }
}

// The tests here are probably rather WRONG_MINDED in that they check the
// status of the file and report whether its OWNER could read, write or
// execute it, rather than whether the current user could. However what
// I do here will hold the fort for now.


bool file_readable(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return false;
    std::error_code ec;
    auto s = std::filesystem::status(std::filesystem::path(filename), ec);
    if (ec) return false;
    return (s.permissions() & std::filesystem::perms::owner_read) !=
           std::filesystem::perms::none;
}


bool file_writeable(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return false;
    std::error_code ec;
    auto s = std::filesystem::status(std::filesystem::path(filename));
    if (ec) return false;
    return (s.permissions() & std::filesystem::perms::owner_write) !=
           std::filesystem::perms::none;
}


bool file_executable(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return false;
    std::error_code ec;
    auto s = std::filesystem::status(std::filesystem::path(filename));
    if (ec) return false;
    return (s.permissions() & std::filesystem::perms::owner_exec) !=
           std::filesystem::perms::none;
}


int rename_file(char *from_name, const char *from_old,
                size_t from_size,
                char *to_name, const char *to_old, size_t to_size)
{   process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return std::rename(from_name,to_name);
}

#else // __cpp_lib_filesystem

#ifdef WIN32

#include "windows.h"

int Cmkdir(const char *name)
{   SECURITY_ATTRIBUTES s;
    s.nLength = sizeof(s);
    s.lpSecurityDescriptor = nullptr;
    s.bInheritHandle = FALSE;
    return CreateDirectory(name, &s);
}

int truncate_file(std::FILE *f, long int where)
{   if (std::fflush(f) != 0) return 1;
#ifdef __CYGWIN__
    if (std::fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  // Returns zero if success
#else // __CYGWIN__
    return chsize(fileno(f), where);    // Returns zero if success
#endif // __CYGWIN__
}

void set_filedate(char *name, unsigned long int datestamp,
                  unsigned long int filetype)
{   HANDLE h = CreateFile(name, GENERIC_WRITE, 0, nullptr,
                          OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    SYSTEMTIME st;
    FILETIME ft;
    int yr, mon, day, hr, min, sec;
// Here datestamp is a time expressed (sort of) in seconds since the start
// of 1970. * I need to convert it into a broken-down SYSTEMTIME so that I
// can then re-pack it as a Windows-NT FILETIME....
    unpack_date(datestamp, &yr, &mon, &day, &hr, &min, &sec);
    st.wMilliseconds = 0;
    st.wYear = yr + 1900;  // Windows NT uses full dates since the year 0
    st.wMonth = mon + 1;
    st.wDay = day;
    st.wHour = hr;
    st.wMinute = min;
    st.wSecond = sec;
    SystemTimeToFileTime(&st, &ft);
    SetFileTime(h, nullptr, nullptr, &ft);
    CloseHandle(h);
}

void put_fileinfo(date_and_type *p, char *name)
{   unsigned long int datestamp, filetype;
    struct stat file_info;
    struct std::tm *st;
    stat(name, &file_info);
    st = std::localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;
    p->date = datestamp;
    p->type = filetype;
}

#else // WIN32

// On some Unix variants I may want this declaration inserted and on others
// it would clash with a system-provided header file. Ugh! With luck the C
// compiler will invent a suitable calling convention even if a declaration
// is not present.
// extern ftruncate(int, int);

int truncate_file(std::FILE *f, long int where)
{   if (std::fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  // Returns zero if success
}

// extern void mkdir(const char *, unsigned short int);

int Cmkdir(const char *s)
{   mkdir(s, 0775);
    return 1;
}

#include <utime.h>

#if defined EMBEDDED && defined __ARM_EABI__ && !defined __linux__

void utime(const char *s, struct utimbuf *t);

#endif // EMBEDDED etc

void set_filedate(char *name, unsigned long int datestamp,
                  unsigned long int filetype)
{
#ifndef EMBEDDED
#ifdef UTIME_TIME_T
    std::time_t tt[2];
#else // UTIME_TIME_T
    struct utimbuf tt;
#endif // UTIME_TIME_T
    std::time_t t0;
    struct std::tm st;
    unpack_date(datestamp, &st.tm_year, &st.tm_mon, &st.tm_mday,
                &st.tm_hour, &st.tm_min, &st.tm_sec);
    st.tm_isdst = -1;
    t0 = std::mktime(&st);
#ifdef UTIME_TIME_T
    tt[0] = tt[1] = t0;
#else // UTIME_TIME_T
    tt.actime = tt.modtime = t0;
#endif // UTIME_TIME_T
    utime(name, &tt);
#endif // EMBEDDED
}

void put_fileinfo(date_and_type *p, char *name)
{   unsigned long int datestamp, filetype;
    struct stat file_info;
    struct std::tm *st;
// Read file parameters...
    stat(name, &file_info);
    st = std::localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;  // should get access status here?
    p->date = datestamp;
    p->type = filetype;
}

#endif // WIN32

// If I am to process directories I need a set of routines that will
// scan sub-directories for me.  This is necessarily dependent on
// the operating system I am running under, hence the conditional compilation
// here.  The specification I want is:
//       void scan_directory(string dir,
//                    void (*proc)(string name, string leafname,
//                                 int why, long int size));
//
// This is called with a directory-name as its first argument
// and a function as its second.
// It calls the function for every directory and every file that can be found
// rooted from the given place.  
// When a simple file is found the procedure is called with the name of the
// file, why=0, and the length (in bytes) of the file.  For a directory
// the function is called with why=1, then the contents of the directory are
// processed. Files are returned in alphabetic order. There is no
// guarantee of useful behaviour if some of the files to be scanned are
// flagged as  "invisible" or "not readable" or if they are otherwise special.
//
// I also provide a similar function scan_files() with the same arguments that
// does just the same except that it does not recurse into sub-directories,

// For CSL's purposes the following 3 are in syscsl.h, but in general I do not
// want to use that header with random fwin applications...
#define SCAN_FILE       0
#define SCAN_DIR        1


// I use a (static) flag to indicate how sub-directories should be
// handled, and what to do about case. By default I fold to lower case
// on windows. setting hostcase non-zero causes case to be preserved.

static int recursive_scan, hostcase = 0;

void set_hostcase(int fg)
{   hostcase = fg;
}

#ifdef WIN32

// Hmm - buffer overflow worry with the next line!
static char win_filename[LONGEST_LEGAL_FILENAME];
int scan_leafstart;

static WIN32_FIND_DATA *found_files = nullptr;
static int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{   if (n_found_files > max_found_files - 5)
    {   WIN32_FIND_DATA *fnew =
            new (std::nothrow) WIN32_FIND_DATA[max_found_files+TABLE_INCREMENT];
        if (fnew == nullptr) return 1;  // failure flag
        std::memcpy(fnew, found_files,
            sizeof(WIN32_FIND_DATA)*max_found_files);
        delete [] found_files;
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{   const WIN32_FIND_DATA *fa = (const WIN32_FIND_DATA *)a,
                               *fb = (const WIN32_FIND_DATA *)b;
    return std::strncmp(fb->cFileName, fa->cFileName,
                        sizeof(fa->cFileName));
}

static void exall(int namelength, filescan_function *proc)
// This procedure scans a directory-full of files, calling the given procedure
// to process each one it finds.
{
#ifdef EMBEDDED
    std::printf("exall function called - but not implemented here\n");
    return; // Dummy version here
#else // EMBEDDED
    WIN32_FIND_DATA found;
    int rootlen = namelength, first = n_found_files;
    HANDLE hSearch = FindFirstFile(win_filename, &found);
    if (hSearch == INVALID_HANDLE_VALUE) return;  // No files found at all
    for (;;)
    {   if (more_files()) break;
        found_files[n_found_files++] = found;
        if (!FindNextFile(hSearch, &found)) break;
    }
    FindClose(hSearch);
    std::qsort(reinterpret_cast<void *>(&found_files[first]),
               n_found_files-first,
               sizeof(WIN32_FIND_DATA),
               alphasort_files);
    while (rootlen>=0 && win_filename[rootlen]!='\\' &&
           win_filename[rootlen]!='/')
        rootlen--;
    while (n_found_files != first)
    {   char *p = reinterpret_cast<char *>(
                  &found_files[--n_found_files].cFileName);
        int c;
// Fill out filename with the actual name I grabbed, i.e. with
// wild-cards expanded.
        namelength = rootlen+1;
// I fold DOS filenames into lower case because it does not matter much
// to DOS and I think it looks better - furthermore it helps when I move
// archives to other systems.  So I do the same on NT.
        while ((c = *p++) != 0)
        {   if (!hostcase) if (std::isupper(c)) c = std::tolower(c);
            win_filename[namelength++] = static_cast<char>(c);
        }
        win_filename[namelength] = 0;
        if (found_files[n_found_files].dwFileAttributes &
            FILE_ATTRIBUTE_DIRECTORY)
        {   if (found_files[n_found_files].cFileName[0] != '.')
// I filter out directory names that start with '.'.
// This is to avoid calamity with recursion though chains such as .\.\.\.....
            {   proc(string(win_filename),
                     string(win_filename+scan_leafstart),
                     SCAN_DIR, 0);
                if (!recursive_scan) continue;
                std::strcpy(&win_filename[namelength], "\\*.*");
// Append "\*.*" to the directory-name and try again, thereby scanning
// its contents.
                exall(namelength+4, proc);
                win_filename[namelength] = 0;
            }
        }
        else proc(string(win_filename),
                  string(win_filename+scan_leafstart),
                  SCAN_FILE,
                  found_files[n_found_files].nFileSizeLow);
    }
    return;
#endif // EMBEDDED
}

void scan_directory(string Cdir, filescan_function *proc)
{   recursive_scan = 1;
    const char *dir = Cdir.c_str();
    if (std::strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = std::strlen(dir)+1;
    std::strcpy(win_filename, dir);
    exall(std::strlen(win_filename), proc);
}

void scan_files(string Cdir, filescan_function *proc)
{   recursive_scan = 0;
    const char *dir = Cdir.c_str();
    if (std::strcmp(dir,".")==0)
    {   std::strcpy(win_filename, "*.*");
        scan_leafstart = 0;
    }
    else
    {   scan_leafstart = std::strlen(dir);    // +1 ??????
        std::strcpy(win_filename, dir);
        if (win_filename[scan_leafstart-1] == '\\')
        {   // Root directory
            std::strcpy(win_filename+scan_leafstart, "*.*");
            --scan_leafstart;
        }
        else std::strcpy(win_filename+scan_leafstart, "\\*.*");
        scan_leafstart++;
    }
    exall(std::strlen(win_filename), proc);
}

#else // WIN32

static char posix_filename[LONGEST_LEGAL_FILENAME];
static int scan_leafstart = 0;

// The code here uses opendir, readdir and closedir and as such ought to
// be Posix compatible. The macro USE_DIRECT_H can cause an older variant
// on this idea to be used. BUt it may need adjustment for different
// systems.

static char **found_files = nullptr;

int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{   if (n_found_files > max_found_files - 5)
    {   char **fnew =
            new (std::nothrow) char *[max_found_files + TABLE_INCREMENT];
        if (fnew == nullptr) return 1;  // failure flag
        std::memcpy(fnew, found_files, sizeof(char *)*max_found_files);
        delete [] found_files;
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{   const char *fa = *(const char **)a,
               *fb = *(const char **)b;
    return std::strcmp(fb, fa);
}

static void scan_file(int namelength, filescan_function *proc);

static void exall(int namelength, filescan_function *proc)
{
#ifdef EMBEDDED
    std::printf("exall function called - but not implemented here\n");
    return; // Dummy version here
#else // EMBEDDED
    DIR *d;
#ifdef USE_DIRECT_H
    struct direct *dd;
#else // USE_DIRECT_H
    struct dirent *dd;
#endif // USE_DIRECT_H
    int rootlen = namelength, first = n_found_files;
    proc(string(posix_filename),
         string(posix_filename+scan_leafstart),
         SCAN_DIR, 0);
    d = opendir(posix_filename);
    if (d != nullptr)
    {   while ((dd = readdir(d)) != nullptr)
        {   char *leafname = dd->d_name;
            char *copyname;
// readdir hands back both "." and ".." but I had better not recurse
// into either!
            if (std::strcmp(leafname, ".") == 0 ||
                std::strcmp(leafname, "..") == 0) continue;
            if (more_files()) break;
            copyname = new (std::nothrow) char[1+std::strlen(leafname)];
            if (copyname == nullptr) break;
            std::strcpy(copyname, leafname);
            found_files[n_found_files++] = copyname;
        }
        closedir(d);
    }

    std::qsort(reinterpret_cast<void *>(&found_files[first]),
               n_found_files-first,
               sizeof(char *),
               alphasort_files);
    posix_filename[rootlen] = '/';
    while (n_found_files != first)
    {   char *p = found_files[--n_found_files];
        int c;
        namelength = rootlen+1;
        while ((c = *p++) != 0) posix_filename[namelength++] =
                static_cast<char>(c);
        delete [] found_files[n_found_files];
        posix_filename[namelength] = 0;
        scan_file(namelength, proc);
    }
    posix_filename[rootlen] = 0;
#endif // EMBEDDED
}

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif // S_IFMT

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif // S_IFDIR

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif // S_IFREG

static void scan_file(int namelength, filescan_function *proc)
{   struct stat buf;
    stat(posix_filename, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   if (!recursive_scan) proc(string(posix_filename),
                                  string(posix_filename+scan_leafstart),
                                  SCAN_DIR, 0);
        else exall(namelength, proc);
    }
    else if ((buf.st_mode & S_IFMT) == S_IFREG)
        proc(string(posix_filename),
             string(posix_filename+scan_leafstart),
             SCAN_FILE, buf.st_size);
//  else fprintf(stderr, "Mode of %s is %o\n", posix_filename, buf.st_mode);
}

void scan_directory(string Cdir, filescan_function *proc)
{   recursive_scan = 1;
    const char *dir = Cdir.c_str();
    scan_leafstart = std::strlen(dir)+1;
    std::strcpy(posix_filename, dir);
    scan_file(scan_leafstart-1, proc);
}

void scan_files(string Cdir, filescan_function *proc)
{   recursive_scan = 0;
    const char *dir = Cdir.c_str();
    scan_leafstart = std::strlen(dir)+1;
    std::strcpy(posix_filename, dir);
    exall(scan_leafstart-1, proc);
}

#endif // WIN32

// Maybe the above shows how helpful the C++ std::filesystem stuff is here!


std::FILE *open_file(char *filename, const char *old, size_t n,
                     const char *mode, std::FILE *old_file)
{
// mode is something like "r" or "w" or "rb", as needed by fopen(),
// and old_file is nullptr normally, but can be a (FILE *) to indicate
// the use of freopen rather than fopen.
    std::FILE *ff;
    process_file_name(filename, old, n);
    if (*filename == 0) return nullptr;
    if (old_file == nullptr) ff = std::fopen(filename, mode);
    else ff = std::freopen(filename, mode, old_file);
// In suitable cases when the first attempt to open the file fails I
// will try creating any necessary directories and then try again.
    if (ff==nullptr && *mode=='w')
    {   char *p = filename;
        while (*p != 0)
        {   int ch = *p;
            if (ch == '/' || ch == '\\')
            {   *p = 0;
                Cmkdir(filename);
                *p = ch;
            }
            p++;
        }
        if (old_file == nullptr) ff = std::fopen(filename, mode);
        else ff = std::freopen(filename, mode, old_file);
    }
    if (ff != nullptr) std::setvbuf(ff, nullptr, _IOFBF, 0x10000);
    return ff;
}


static char err_buf[LONGEST_LEGAL_FILENAME+100];

char *change_directory(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0)
    {   std::snprintf(err_buf, sizeof(err_buf),
            "Filename \"%s\" invalid.", old);
        return err_buf;
    }
    if (chdir(filename))
    {   const char *msg;
        switch (errno)
        {   case ENOTDIR:
                msg = "A component of %s is not a directory.";
                break;
            case ENOENT:
                msg = "The directory %s does not exist.";
                break;
            case EACCES:
                msg = "Insufficient permission for %s.";
                break;
            case ENAMETOOLONG:
                msg = "The pathname %s is too long.";
                break;
            default:
                msg = "Cannot change directory to %s.";
                break;
        }
        std::snprintf(err_buf, sizeof(err_buf), msg, filename);
        return err_buf;
    }
    else return nullptr;
}

int create_directory(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    return Cmkdir(filename);
}


static void remove_files(string name, string leafname, int dirp, long int size)
// Remove a file, or a directory and all its contents
{   switch (dirp)
    {   case 0:               // SCAN_FILE
            std::remove(name.c_str());
            return;
        case 2:               // SCAN_ENDDIR
            rmdir(name.c_str());
            return;
        default:              // 1 == SCAN_STARTDIR
            return;
    }
}

int delete_file(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    //
    // We cannot simply use remove here, since this will not
    // work with directories and their contents.  Hence the
    // use of scan_directory.
    //
    string dir = filename;
    scan_directory(dir, remove_files);
    return 0;
}

int delete_wildcard(char *filename, const char *old, size_t n)
{   process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    {
#ifdef WIN32
        HANDLE h;
        WIN32_FIND_DATA gg;
        h = FindFirstFile(filename, &gg);
        if (h != INVALID_HANDLE_VALUE)
        {   for (;;)
            {   scan_directory(gg.cFileName, remove_files);
                if (!FindNextFile(h, &gg)) break;
            }
            FindClose(h);
        }
#else // WIN32
        glob_t gg;
        size_t i;
        if (glob(filename, GLOB_NOSORT, nullptr, &gg) == 0)
        {   for (i=0; i<gg.gl_pathc; i++)
                scan_directory(gg.gl_pathv[i], remove_files);
            globfree(&gg);
        }
#endif // WIN32
    }
    return 0;
}

int64_t file_length(char *filename, const char *old, size_t n)
{   struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) return -1;
    return (int64_t)(buf.st_size);
}

void list_directory_members(char *filename, const char *old,
                            size_t n,
                            filescan_function *fn)
{   process_file_name(filename, old, n);
    scan_files(filename, fn);
}

bool file_exists(char *filename, const char *old, size_t n, char *tt)
// This returns YES if the file exists, and as a side-effect copies a
// textual form of the last-changed-time of the file into the buffer tt.
{   struct stat statbuff;
    process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (stat(filename, &statbuff) != 0) return false;
    std::strcpy(tt, std::ctime(&(statbuff.st_mtime)));
    return true;
}

bool directoryp(char *filename, const char *old, size_t n)
{   struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (stat(filename,&buf) == -1) return false;
    return ((buf.st_mode & S_IFMT) == S_IFDIR);
}


char *get_truename(char *filename, const char *old, size_t n)
{   struct stat buf;
    char *temp, *fn, *dir;
    char pwd[LONGEST_LEGAL_FILENAME];
    std::memset(pwd, 0, sizeof(pwd));

    process_file_name(filename, old, n);
    if (*filename == 0)
    {   std::strcpy(filename, "truename");
        return nullptr;
    }

    // Find out whether we have a file or a directory
    if (stat(filename,&buf) == -1)
    {   std::strcpy(filename, "truename: cannot stat file");
        return nullptr;
    }

    // Store current directory
    if (get_current_directory(pwd, LONGEST_LEGAL_FILENAME) < 0)
    {   std::strcpy(filename,
                    "truename: cannot get current working directory");
        return nullptr;
    }

    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   // We have a directory
        char *dir1;
        if (chdir(filename) != 0)
        {   std::strcpy(filename, "truename: cannot change directory");
            return nullptr;
        }
        dir1 = new (std::nothrow) char[LONGEST_LEGAL_FILENAME];
        if (dir1==nullptr)
        {   std::strcpy(filename, "truename: run out of memory");
            return nullptr;
        }
        if (getcwd(dir1,LONGEST_LEGAL_FILENAME) == nullptr)
        {   std::strcpy(filename,
                        "truename: cannot get current working directory");
            delete [] dir1;
            return nullptr;
        }
        if (chdir(pwd) != 0)
        {   std::strcpy(filename, "truename: cannot change directory");
            delete [] dir1;
            return nullptr;
        }
// Axiom-specific hack: truename preserves '/' at the end of
// a path
        if (old[n-1] == '/' && dir1[std::strlen(dir1)-1] != '/')
        {   n = std::strlen(dir1);
            dir1[n]   = '/';
            dir1[n+1] = '\0';
        }
        return dir1;
    }
    else
    {   // Assume we have some kind of file
        temp = std::strrchr(filename,'/');
        if (temp)
        {   // Found a directory component
            char theDir[LONGEST_LEGAL_FILENAME];
            std::memset(theDir, 0, sizeof(theDir));
            fn = new (std::nothrow) char[1+std::strlen(temp)];
            if (fn == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                return nullptr;
            }
            std::strcpy(fn, temp);
            *temp = '\0';
// fn is now "/file" and filename is the directory
            if (chdir(filename) != 0)
            {   std::strcpy(filename, "truename: cannot change directory");
                delete [] fn;
                return nullptr;
            }
            if (get_current_directory(theDir, LONGEST_LEGAL_FILENAME) < 0)
            {   std::strcpy(filename,
                            "truename: cannot get current working directory");
                delete [] fn;
                return nullptr;
            }
            temp = theDir;
            if (chdir(pwd) != 0)
            {   std::strcpy(filename, "truename: cannot change directory");
                delete [] fn;
                return nullptr;
            }
            dir = new (std::nothrow)
                char[std::strlen(temp) + std::strlen(fn) + 1];
            if (dir == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                return nullptr;
            }
            std::strcpy(dir, temp);
            std::strcat(dir, fn);
            delete [] fn;
            return dir;
        }
        else
        {   dir = new (std::nothrow)
                char[std::strlen(pwd) + std::strlen(filename) + 2];
            if (dir == nullptr)
            {   std::strcpy(filename, "truename: run out of memory");
                return nullptr;
            }
            std::strcpy(dir, pwd);
            std::strcat(dir, "/");
            std::strcat(dir, filename);
            return dir;
        }
    }
}

// The tests here are probably rather WRONG_MINDED in that they check the
// status of the file and report whether its OWNER could read, write or
// execute it, rather than whether the current user could. However what
// I do here will hold the fort for now.


bool file_readable(char *filename, const char *old, size_t n)
{   struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (stat(filename,&buf) == -1)
        return false; // File probably does not exist
#ifndef S_IRUSR
    return true;
#else // S_IRUSR
    return (buf.st_mode & S_IRUSR);
#endif // S_IRUSR
}


bool file_writeable(char *filename, const char *old, size_t n)
{   struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (stat(filename,&buf) == -1)
        return false; // Should we check to see if the directory is writeable?
#ifndef S_IWUSR
    return true;
#else // S_IWUSR
    return (buf.st_mode & S_IWUSR);
#endif // S_IWUSR
}


bool file_executable(char *filename, const char *old, size_t n)
{   struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return false;
    if (stat(filename,&buf) == -1)
        return false; // Should we check to see if the directory is writeable?
#ifndef S_IXUSR
    return true;
#else // S_IXUSR
    return (buf.st_mode & S_IXUSR);
#endif // S_IXUSR
}


int rename_file(char *from_name, const char *from_old,
                size_t from_size,
                char *to_name, const char *to_old, size_t to_size)
{   process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return std::rename(from_name,to_name);
}

#endif // __cpp_lib_filesystem


// end of fwin.cpp
