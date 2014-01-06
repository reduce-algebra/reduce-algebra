#define DEBUG 1   /* regardless of build mode for now! */

/*
 * "wxfwin.c"                                    Copyright A C Norman 2013
 *
 *
 * Window interface for old-fashioned C applications. Intended to
 * be better than just running them within rxvt/xterm, but some people will
 * always believe that running them under emacs is best!
 *
 * Note that although the graphical bits of wxfwin and coded in C++ the
 * parts needed for a text-only interface are in just C. This is so that
 * on limited platforms where graphics are not relevant the C++ libraries
 * do not have to be used.
 *
 * This starts off identical to an older version, fwin.c, but is kept
 * separate so that if I make changes during my wxWidgets project I will
 * not hurt things so badly. Well after not very long it has already diverged
 * a fair amount!
 */

/**************************************************************************
 * Copyright (C) 2013, Codemist Ltd.                     A C Norman       *
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

#include "config.h"




#ifdef WIN32
/* Indicate that I expect to be using a RECENT version of Windows */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#include <windows.h>
#include <io.h>
#include <wchar.h>
#endif /* WIN32 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
#ifndef _MSC_VER
extern char *getcwd(char *s, size_t n);
#endif
#endif /* HAVE_UNISTD_H */

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifndef WIN32
#include <glob.h>
#endif

#ifndef EMBEDDED
#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#ifndef WIN32
#include <sys/dir.h>
#else
#include <direct.h>
#endif
#endif /* HAVE_DIRENT_H */
#endif

#if defined MACINTOSH && defined MAC_FRAMEWORK
/*
 * The extent to which any code here pays attention to Mac-specific
 * features is and should probably remain minimal! However some may be
 * used here.
 */
#include <Carbon/Carbon.h>
#include <CoreServices/CoreServices.h>
#endif /* MAC stuff */

#ifdef _MSC_VER
#define MS_CDECL __cdecl
#else
#define MS_CDECL
#endif /* Microsoft C */

#include "wxfwin.h"
#include "termed.h"

/*
 * The value LONGEST_LEGAL_FILENAME should be seen as a problem wrt
 * buffer overflow! I will just blandly assume throughout all my code that
 * no string that denotes a full file-name (including its path) is ever
 * longer than this.
 */
#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

#ifdef DEBUG

/*
 * This will be used as in FWIN_LOG((format,arg,...))
 * *NOT* using a variadic macro, hence doubled parentheses.
 * If DEBUG was enabled it send log information
 * to a file with the name fwin-debug.log: I hope that will not (often)
 * clash with any file the user has or requires. if programDir has been
 * set when you first generate log output then the log file will be put
 * there (ie alongside the executable). If not it will go in /tmp. So
 * if debugging you might want to ensure that such a directory exists!
 */

static FILE *fwin_logfile = NULL;

#define LOGFILE_NAME "fwin-debug.log"

void fwin_write_log(const char *s, ...)
{
/*
 * I expect vfprintf and fflush to be thread-safe, however the test
 * on fwin_logfile and the code that creates it could lead to a race
 * if two threads both tried to open the log file at the same time. I
 * believe that since this is JUST to be used for debugging everything can
 * be made safe by insisting that any code that uses threads must execute
 * FWIN_LOG() before it starts any thread, so that the log file will get
 * created when there is not concurrency to cause confusion. That seems
 * lighter weight than messing with a further critical section here.
 */
    int create = (fwin_logfile == NULL);
    va_list x;
/*
 * Note that I create this file in "a" (append) mode so that previous
 * information there is not lost.
 */
    if (create)
    {   char logfile_name[LONGEST_LEGAL_FILENAME];
        memset(logfile_name, 0, sizeof(logfile_name));
        if (strcmp(programDir, ".") == 0)
            sprintf(logfile_name, "/tmp/%s", LOGFILE_NAME);
#ifdef MACINTOSH
/*
 * If the executable I am running exists as
 *    ...../something.app/Contents/MacOS/something
 * then I will place the log file adjacant to the .app directory rather
 * than in the MacOS directory next to the actual raw executable.
 */
        else if (sprintf(logfile_name, "%s.app/Contents/MacOS", programName),
                 strlen(programDir) >= strlen(logfile_name) &&
                 strcmp(programDir+strlen(programDir)-strlen(logfile_name),
                        logfile_name) == 0)
        {   sprintf(logfile_name, "%.*s/%s",
                    (int)(strlen(programDir)-strlen(programName)-19),
                    programDir, LOGFILE_NAME);
        }
#endif
        else sprintf(logfile_name, "%s/%s", programDir, LOGFILE_NAME);
        fwin_logfile = fopen(logfile_name, "a");
    }
    if (fwin_logfile == NULL) return; /* the file can not be used */
    if (create)
    {   time_t tt = time(NULL);
        struct tm *tt1 = localtime(&tt);
        fprintf(fwin_logfile, "Log segment starting: %s\n", asctime(tt1));
    }
    va_start(x, s);
    vfprintf(fwin_logfile, s, x);
    va_end(x);
    va_start(x, s);
    vfprintf(stderr, s, x);
    va_end(x);
    fflush(fwin_logfile);
}

#endif


#if defined WIN32
/*
 * wxWidgets in Windows uses UTF-16 (wchar_t stuff) for all its characters
 * and strings. So I will put start using wide character varients on some of
 * the Windows functions as a matter of proper caution. But the BULK of my
 * code will remain committed to 8-bit chars for some while, so even when that
 * move to unicode it will be via UTF-8.
 *
 * Here I wrap up the Microsoft code that converts between UTF-8 and UTF-16
 * so I can coexist better.
 *
 * I am rather crudely not going to concern myself with buffer overflow issues
 * here. The Microsoft conversion functions do but I will tell them that
 * the strings I handle will be at most 1000 characters or bytes long. Any
 * case that goes beyond that will lead to trouble.
 */

typedef wchar_t Uchar;

void unicodeToUtf8(char *dest, const wchar_t *src)
{  
    int w = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, 1000, NULL, NULL);
    dest[w] = 0;
}

void utf8ToUnicode(wchar_t *dest, const char *src)
{
    int w = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, 1000);
    dest[w] = 0;
}

int lenAsUtf8(const wchar_t *s)
{
    return (int)WideCharToMultiByte(CP_UTF8, 0, s, -1, NULL, 0, NULL, NULL);
}

#else

/*
 * On all platforms except Windows the representation that wxWidgets uses
 * for Unicode strings is just UTF8, so the "conversions" indicated here
 * become simple data-copies.
 */

typedef char Uchar;

void unicodeToUtf8(char *dest, const char *src)
{
    strcpy(dest, src);
}

void utf8ToUnicode(char *dest, const char *src)
{
    strcpy(dest, src);
}

int lenAsUtf8(const char *s)
{
    return strlen(s) + 1;
}

#endif

char about_box_title[40]       = "About XXX";
char about_box_description[40] = "XXX version 1.1";
                              // <icon appears here>
char about_box_rights_1[40]    = "Author info";
char about_box_rights_2[40]    = "Additional author";
char about_box_rights_3[40]    = "This software uses wxWidgets";
char about_box_rights_4[40]    = "(http://www.wxwidgets.org)";

const char *colour_spec = "-";

char fwin_prompt_string[MAX_PROMPT_LENGTH] = "> ";

int fwin_linelength = 80;

delay_callback_t *delay_callback;
interrupt_callback_t *interrupt_callback;

extern const char *my_getenv(const char *s);

#ifdef WIN32
static int programNameDotCom;
#endif
#ifdef MACINTOSH
static int macApp = 0;
#endif

int windowed = 0;

int texmacs_mode = 0;

int fwin_pause_at_end = 0;

#ifdef WIN32

void consoleWait()
{
/*
 * If the console had to be created specially to view this information
 * it is probable that it will close as soon as the program closes, and so
 * to give at least a minimal chance for the user to inspect it I will
 * put in a delay here.
 */
    int i = 5;
    clock_t c0;
    while (i > 0)
    {   char title[30];
        sprintf(title, "Exiting after %d seconds", i);
        SetConsoleTitle(title);
        c0 = clock() + CLOCKS_PER_SEC;
        while (clock() < c0);
        i--;
    }
}

#endif

#ifndef EMBEDDED

#ifdef WIN32

BOOL CtrlHandler(DWORD x)
{
    switch (x)
    {
/*
 * This seems to be needed to ensure that if a windows console is closed
 * and you launched your program from a cygwin shell (via the cygwin
 * execv(e) family) it exists nicely. Otherwise it can be retried several
 * times.
 */
case CTRL_CLOSE_EVENT:
case CTRL_LOGOFF_EVENT:
case CTRL_SHUTDOWN_EVENT:
case CTRL_BREAK_EVENT:
/*
 * I had tried the ise of ExitProcess(1) here and that was not strong enough
 * to avoid program-restart! So I take drastic action with TerminateProcess.
 */
        TerminateProcess(GetCurrentProcess(), 1);
default:
        return 0;
    }
}

#endif

int fwin_startup(int argc, char *argv[], fwin_entrypoint *fwin_main)
{
    int i, ssh_client = 0;
#ifndef WIN32
    const char *disp;
#endif
/*
 * I want to know the path to the directory from which this 
 * code was launched. Note that in some cases the prints to stderr
 * shown here will be totally ineffective and the code will just seem
 * to exit abruptlt. Eg that can be the situation if the version being run
 * has been linked on Windows as a window-mode (as distinct from console-mode)
 * binary, or if it is on a Macintosh not associated with a console.
 */
    if (argc == 0)
    {   fprintf(stderr,
            "argc == 0. You tried to launch the code in a funny way?\n");
        return 1;
    }
    if (find_program_directory(argv[0]))
    {   fprintf(stderr, "Unable to identify program name and directory\n");
        return 1;
    }
    texmacs_mode = 0;
/*
 * An option "--my-path" just prints the path to the executable
 * and stops. An option "--args" indicates that I should not look at any
 * more arguments - they may be used by the program that is to be run.
 */
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "--args") == 0) break;
/*
 * The "--my-path" option may be useful for debugging, but probably does
 * not mak emuch sense otherwise!
 */
        else if (strcmp(argv[i], "--my-path") == 0)
        {   printf("%s\n", programDir);
            exit(0);
        }
    }

    windowed = 1;
#ifdef WIN32
/* I have tried various messy Windows API calls here to get this right.
 * But so far I find that the cases that apply to me are
 *    (a) windows command prompt : normal case
 *    (b) windows command prompt : stdin redirected via "<" on command line
 *    (c) windows, but launched by a double-click, .com version
 *    (d) windows, but launched by a double-click, .exe version
 *    (e) cygwin shell : normal case
 *    (f) cygwin shell : stdin redirected via "<"
 *    (g) reached the shell via SSH
 * leave me in a state
 *    (a) stdin exists and is a tty, a char device and a Console
 *    (b) stdin exists and is a pipe or a file not a tty
 *    (c) as (a)
 *    (d) stdin seems to exist but is not a tty
 *    (e) stdin exists and is a pipe
 *    (f) as (e)
 *    (g) $SSH_CLIENT is set
 * I want (b), (c), (f) and (g) to force a non-windowed treatment.  But
 * you may see that various cases are not readily properly distinguished...
 *
 */

    if (programNameDotCom)
    {
/* The program was named "xxx.com". I will assume that that means it was
 * a console-mode application and it is being launched directly from a
 * Windows console.  Why do I feel these are plausible:
 *  . The Makefile.in & configure.ac stuff arranges to build xxx.com as
 *    console mode and xxx.exe as subsystem:windows
 *  . A Windows command prompt will launch xxx.com in preference to xxx.exe
 *    if both are present
 *  . xxx.com is not given an icon, while xxx.exe is - people should not
 *    double-click on the .com version (please)
 * Obviously users can subvert this by copying xxx.exe to yyy.com, by
 * double clicking where I did not want or by specifying an explicit
 * extension when they launch a command from a console prompt. But in such
 * cases I will take the view that they will get what they deserve!
 */
        HANDLE h;
        DWORD w;
        CONSOLE_SCREEN_BUFFER_INFO csb;
/* If either standard input or output has been redirected I will force use
 * of console rather than windowed mode. Thus
 *         xxx             launch in a window
 *         xxx -w          run as console application
 *         xxx < yyy       run as console application
 *         xxx > yyy       run as console application
 * My hope is that the detection of redirected stdin/stdout will help
 * when the application is used in a script. There may remain a dodgy case!
 * if xxx is run under a debugger at least some debuggers intercept standard
 * input & output so debugging the windowed mode may be harded here. But I
 * will defer that worry since the ".exe" not the ".com" file is the version
 * with windowed use its prime interface.
 */
        const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != NULL && *ssh != 0)
        {   FWIN_LOG(("SSH_CLIENT set on Windows, so treat as console app\n"));
            ssh_client = 1;
            windowed = 0;
        }
        else
        {   h = GetStdHandle(STD_INPUT_HANDLE);
            if (GetFileType(h) != FILE_TYPE_CHAR)
            {   FWIN_LOG(("STD_INPUT_HANDLE not FILE_TYPE_CHAR\n"));
                windowed = 0;
            }
            else if (!GetConsoleMode(h, &w))
            {   FWIN_LOG(("!GetConsoleMode(STD_INPUT_HANDLE)\n"));
                windowed = 0;
            }
            else
            {   h = GetStdHandle(STD_OUTPUT_HANDLE);
                if (GetFileType(h) != FILE_TYPE_CHAR)
                {   FWIN_LOG(("STD_OUTPUT_HANDLE not FILE_TYPE_CHAR\n"));
                    windowed = 0;
                }
                else if (!GetConsoleScreenBufferInfo(h, &csb))
                {   FWIN_LOG(("!GetConsoleMode(STD_OUTPUT_HANDLE)\n"));
                    windowed = 0;
                }
            }
        }
    }
    else
    {
/* The program was named "xxx.exe". I am going to suppose that this has NOT
 * been launched from a normal Windows command prompt (since xxx.com would
 * have been preferred). I am left with two scenarios. One is that the
 * program was launched by double-clicking, and in that case it detached
 * from its console as it started. The other is that it was launched from
 * a cygwin prompt (which looks for xxx.exe but not xxx.com when you type
 * just xxx).
 */
        HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
/* The discrimination I make here is based on an empirical check of what
 * seems to happen under Windows XP with the version of cygwin current as
 * of September 2004. What I find is that when stdin has been redirected by
 * a shell (either the Windows command shell or cygwin, and in the cygwin
 * case either with "<file" or "<<TAG") my standard input handle exists
 * and identifies itself as type DISK. The the case of launching the code
 * by double-clicking on the .exe file the handle is probably invalid, but
 * GetFileType returns FILE_TYPE_UNKNOWN. The end effect is that I can
 * detect cases where input has been redirected in a way that appears to
 * work in both cases.  Note that if a user wants to launch an application
 * via a pipe then they should EITHER launch the ".com" version or (better)
 * explictly provide a "-w" flag to indicate that the application should
 * work in stream/console mode. Well it is now 2010 and I am using Windows 7,
 * and I *hope* this still behaves the same.
 */
        const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != NULL && *ssh != 0)
        {   FWIN_LOG(("SSH_CLIENT set\n"));
            ssh_client = 1;
            windowed = 0;
        }
        else if (GetFileType(h) == FILE_TYPE_DISK)
        {   FWIN_LOG(("STD_INPUT_HANDLE is FILE_TYPE_DISK\n"));
            windowed = 0;
        }
    }
#else  /* WIN32 */
#ifdef MACINTOSH
/*
 * This may be a proper way to test if I am really running in an application
 * bundle.
 */
    {   CFBundleRef mainBundle = CFBundleGetMainBundle();
        FWIN_LOG(("mainBundle = %p\n", mainBundle));
        if (mainBundle == NULL) macApp = 0;
        else
        {   CFDictionaryRef d = CFBundleGetInfoDictionary(mainBundle);
            FWIN_LOG(("d=%p\n", d));
            if (d == NULL) macApp = 0;
            else
            {   CFStringRef s = CFDictionaryGetValue(d,
                    CFSTR("ATSApplicationFontsPath"));
                FWIN_LOG(("s=%p\n", s));
                macApp = (s != NULL);
            }
        }
    }
#endif /* MACINTOSH */
/* If stdin or stdout is not from a "tty" I will run in non-windowed mode.
 * This may help when the system is used in scripts. I worry a bit about
 * what the status of stdin/stdout are when launched not from a command line
 * but by clicking on an icon...
 */
    if (
#ifdef MACINTOSH
        !macApp &&
#endif
        (!isatty(fileno(stdin)) || !isatty(fileno(stdout))))
    {   FWIN_LOG(("stdin or stdout is not a tty\n"));
        windowed = 0;
    }

#ifdef MACINTOSH
/*
 * If I am using X11 as my GUI then I am happy to use remote access via
 * SSH since I can be using X forwarding - provided DISPLAY is set all can
 * be well. However on a Macintosh I do NOT want to launch a window if I
 * have connected via ssh since I will not have the desktop forwarded.
 */
    {   const char *ssh = my_getenv("SSH_CLIENT");
        if (ssh != NULL && *ssh != 0)
        {   FWIN_LOG(("SSH_CLIENT set on MacOSX\n"));
            ssh_client = 1;
            windowed = 0;
        }
    }
#else /* MACINTOSH */
/* On Unix-like systems I will check the DISPLAY variable, and if it is not
 * set I will suppose that I can not create a window. That case will normally
 * arise when you have gained remote access to the system eg via telnet or
 * ssh without X forwarding. I will also insist that if set it has a ":" in
 * its value... that is to avoid trouble with it getting set to an empty
 * string.
 */
    disp = my_getenv("DISPLAY");
    if (disp == NULL || strchr(disp, ':')==NULL)
    {   FWIN_LOG(("DISPLAY not set for an X11 version\n"));
        windowed = 0;
    }
#endif /* MACINTOSH */
#endif  /* WIN32 */
/*
 * REGARDLESS of any decisions about windowing made so for things can be
 * forced by command line options.
 *    -w+ forces an attempt to run in a window even if it looks as if that
 *        would not make sense or would fail. It is mainly for debugging.
 *    -w. forces use of a window, but starts it minimised.
 *    -w  forces command-line rather than windowed use (can also write
 *        "-w-" for this case).
 * I also look for some other CSL-specific options that make me feel I
 * should adjust behaviour:
 *    --  All output will be going to a file. So if the program is to run in
 *        windowed mode I will start it off minimised.
 *    --texmacs   force the run NOT to try to create its own window,
 *        because it is being invoked via a pipe from TeXmacs,
 */
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "--args") == 0) break;
        if (strcmp(argv[i], "--texmacs") == 0) texmacs_mode = 1;
        else if (strncmp(argv[i], "-w", 2) == 0)
        {   if (argv[i][2] == '+') windowed = 1;
            else if (argv[i][2] == '.') windowed = -1;
            else windowed = 0;
            break;
        }
/*
 * Note well that I detect just "--" as an entire argument here, so that
 * extended options "--option" do not interfere.
 */
        else if ((strcmp(argv[i], "--") == 0 
#if 0
/* The "-f" option to provide a socket-service is withdrawn */
                  || strcmp(argv[i], "-f") == 0
                  || strcmp(argv[i], "-F") == 0
#endif
                 ) &&
                 windowed != 0) windowed = -1;
    }
    if (texmacs_mode) windowed = 0;
#ifdef WIN32
/*
 * If I am running under Windows and I have set command line options
 * that tell me to run in a console then I will create one if one does
 * not already exist.
 */
    if (windowed == 0)
    {   int consoleCreated;
        consoleCreated = AllocConsole();
        if (consoleCreated)
        {   if (ssh_client)
            {
/*
 * This situation seems totally odd to me. I just launched a Windowed-mode
 * application and normally when I do that it detaches from the console.
 * however rather than having a proper console here I am connected over
 * ssh (I am testing this using the cygwin openssh server on Windows 7).
 * It appears to be the case that I *DO* have stdin and stdout available to
 * me in this case even though I think that when I launch exactly the same
 * binary from a directly attached console it detaches and I need to use
 * the newly created console....
 * The code I have here is based on empirical observation in cases that
 * most people will probably not trigger!
 */
                FWIN_LOG(("Running windowed mode application via ssh.\n"));
            }
            else
            {
#ifdef __CYGWIN__
                freopen("/dev/conin", "r+", stdin);
                freopen("/dev/conout", "w+", stdout);
                freopen("/dev/conout", "w+", stderr);
#else
/*
 * I try rather hard here to leave things properly connected to
 * the new console. Note opening CONOUT in "w+" mode so it has
 * GENERIC_READ_ACCESS.
 */
                HANDLE h;
                freopen("CONIN$", "r+", stdin);
                freopen("CONOUT$", "w+", stdout);
                freopen("CONOUT$", "w+", stderr);
                SetStdHandle(STD_INPUT_HANDLE,
                    CreateFile("CONIN$",
                        GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL,
                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL));
                SetStdHandle(STD_OUTPUT_HANDLE,
                    h = CreateFile("CONOUT$",
                        GENERIC_READ|GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL));
                SetStdHandle(STD_ERROR_HANDLE, h);
#endif
/* I will also pause for 5 seconds at the end... */
                atexit(consoleWait);
            }
        }
    }
/*
 * To cope with somebody forcibly closing a console on me I need
 * to trap some console events.
 */
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
#endif /* WIN32 */

/* Windowed or not, if there is an argument "-b" or "-bxxxx" then the
 * string xxx will do something about screen colours. An empty string
 * will suggest no colouring, the string "-" (as in -b-) whatever default
 * I choose.
 */
    colour_spec = "-";
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "--args") == 0) break;
        if (strncmp(argv[i], "-b", 2) == 0)
        {   colour_spec = argv[i]+2;
            break;
        }
    }

    if (windowed==0) return plain_worker(argc, argv, fwin_main);

#ifdef MACINTOSH
/*
 * If I will be wanting to use a GUI and if I have just loaded an
 * executable that is not within an application bundle then I will
 * use "open" to launch the corresponding application bundle. Doing this
 * makes resources (eg fonts) that are within the bundle available and
 * it also seems to cause things to terminate more neatly.
 */
        if (!macApp)
        {   char xname[LONGEST_LEGAL_FILENAME];

/*
 * Here the binary I launched was NOT being from an application bundle.
 * I will try to re-launch it so it is.
 */
            struct stat buf;
            memset(xname, 0, sizeof(xname));
            sprintf(xname, "%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
/* Well foo.app exists and is a directory, so I will try to use it */
                char **nargs = (char **)malloc(sizeof(char *)*(argc+3));
                int i;
                FWIN_LOG(("About to restart Mac from an application bundle\n"));
#ifdef DEBUG
/*
 * Since I am about to restart the program I do not want the new version to
 * find that the log file is open and hence not accessible.
 */
                if (fwin_logfile != NULL)
                {   fclose(fwin_logfile);
                    fwin_logfile = NULL;
                }
#endif
                nargs[0] = "/usr/bin/open";
                nargs[1] = xname;
                nargs[2] = "--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
/* /usr/bin/open foo.app --args [any original arguments] */
                execv(nargs[0], nargs);
/*
 * execv should NEVER return, but if it does I might like to at least
 * attempt to display a report including the error code.
 */
                fprintf(stderr,
                        "Returned from execv with error code %d\n", errno);
                exit(1);
            }
        }
#endif

    return windowed_worker(argc, argv, fwin_main);
}

void MS_CDECL sigint_handler(int code)
{
/* For debugging I may want to see when signals get caught... */
    FWIN_LOG(("sigint_handler called %d %#x\n", code, code));
    signal(SIGINT, sigint_handler);
    if (interrupt_callback != NULL) (*interrupt_callback)(QUIET_INTERRUPT);
    return;
}

#endif /* EMBEDDED */

/*
 * I will only try to use my own local editing and history package
 * if both stdin and stdout are routed directly to a "tty" or "console".
 * The test I apply can probably never be 100% satisfactory, but if I
 * catch all the most common cases I will feel reasonably relaxed!
 */
int using_termed = 0;

static int direct_to_terminal(int argc, char *argv[])
{
#ifdef WIN32
    HANDLE h;
    DWORD w;
    CONSOLE_SCREEN_BUFFER_INFO csb;
/*
 * Standard input must be from a character device and must be accepted
 * by the GetConsoleMode function
 */
    h = GetStdHandle(STD_INPUT_HANDLE);
    if (GetFileType(h) != FILE_TYPE_CHAR) return 0;
    if (!GetConsoleMode(h, &w)) return 0;
/*
 * Standard output must be a character device and a ConsoleScreenBuffer
 */
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetFileType(h) != FILE_TYPE_CHAR) return 0;
    if (!GetConsoleScreenBufferInfo(h, &csb)) return 0;
/*
 * Note that I will allow stderr to have been redirected as much
 * as you like without that having an effect here.
 */
    return 1;
#else
    return isatty(fileno(stdin)) && isatty(fileno(stdout));
#endif /* WIN32 */
}

int plain_worker(int argc, char *argv[], fwin_entrypoint *main)
{
    int r;
    signal(SIGINT, sigint_handler);
/*
 * At one time I trapped SIGBREAK. These days I just let it terminate
 * my program if I am on Linux, Unix or BSD (inc Mac), and under Windows
 * I sometimes trap it using alternative system-specific code,
 */
    if (!texmacs_mode && direct_to_terminal(argc, argv))
    {   input_history_init();
        term_setup(1, colour_spec);
        atexit(term_close);
        using_termed = 1;
    }
    else using_termed = 0;
    strcpy(fwin_prompt_string, "> ");
    r = (*main)(argc, argv);
    input_history_end();
    term_close();
    return r;
}


#define INPUT_BUFFER_SIZE 100

static const char *current_line;
static char input_buffer[INPUT_BUFFER_SIZE];
static int chars_left = 0;
static int prompt_needed = 1;

int fwin_plain_getchar()
{
    int ch;
    if (using_termed)
    {   while (chars_left == 0)
        {   term_setprompt(fwin_prompt_string);
            current_line = term_getline();
            if (current_line == NULL) return EOF;  // failed or EOF
            chars_left = strlen(current_line);
            input_history_add(current_line);
        }
    }
    else if (chars_left == 0)
    {   if (prompt_needed) 
        {   printf("%s", fwin_prompt_string);
            prompt_needed = 0;
        }
        fflush(stdout);
        for (chars_left=0; chars_left<INPUT_BUFFER_SIZE;)
        {   int c = getchar();
            if (c == EOF) c = (0x1f & 'D');
            input_buffer[chars_left++] = c;
            if (c == '\n' || c == (0x1f & 'D'))
            {   prompt_needed = 1;
                break;
            }
        }
        if (chars_left == 0) return EOF;
        current_line = input_buffer;
    }
    chars_left--;
    ch = *current_line++;
    if (ch == (0x1f & 'D')) ch = EOF;
    return ch;
}

int get_current_directory(char *s, int n)
{
    if (getcwd(s, n) == 0)
    {   switch(errno)
        {
    case ERANGE: return -2; /* negative return value flags an error. */
    case EACCES: return -3;
    default:     return -4;
        }
    }
    else return strlen(s);
}

/*
 * The next procedure is responsible for establishing information about
 * both the "short-form" name of the program launched and the directory
 * it was found in. This latter directory may be a good place to keep
 * associated resources.
 *
 * The way of finding the information concerned differs between Windows and
 * Unix/Linux, as one might expect.
 *
 * return non-zero value if failure.
 */

const char *fullProgramName    = "./wxfwin.exe";
const char *programName        = "wxfwin.exe";
const char *programDir         = ".";

#ifdef WIN32

/*
 * I am moving towards support for Unicode here! It may take me some
 * while to finish the conversion, especially since many C-level functions
 * are pretty much tied to the notion of strings being "char *" and char being
 * and 8-bit datatype.
 */
static wchar_t this_executable[LONGEST_LEGAL_FILENAME];
static wchar_t temp_buffer[LONGEST_LEGAL_FILENAME];
static char forFullProgramName[LONGEST_LEGAL_FILENAME];
static char forProgramName[LONGEST_LEGAL_FILENAME];
static char forProgramDir[LONGEST_LEGAL_FILENAME];

int find_program_directory(char *argv0)
{
    wchar_t *a0;
    int i, len, ndir, npgm, j;
/* In older code I believed that I could rely on Windows giving me
 * the full path of my executable in argv[0]. With bits of mingw/cygwin
 * anywhere near me that may not be so, so I grab the information directly
 * from the Windows APIs.
 * Explicitly use the Unicode version here just to be brave.
 */
    GetModuleFileNameW(NULL, this_executable, LONGEST_LEGAL_FILENAME-2);
    a0 = this_executable;
    programNameDotCom = 0;
    if (a0[0] == 0)      /* should never happen - name is empty string! */
    {   programDir = ".";
        programName = "wxfwin";  /* nothing really known! */
        fullProgramName = ".\\wxfwin.exe";
        return 0;
    }
    unicodeToUtf8(forFullProgramName, a0);
    fullProgramName = forFullProgramName;
    len = (int)wcslen(a0);
/*
 * If the current program is called c:\aaa\xxx.exe, then the directory
 * is just c:\aaa and the simplified program name is just xxx
 */
    j = len-1;
    if (len > 4 &&
        a0[len-4] == '.' &&
        ((towlower(a0[len-3]) == 'e' &&
          towlower(a0[len-2]) == 'x' &&
          towlower(a0[len-1]) == 'e') ||
         (towlower(a0[len-3]) == 'c' &&
          towlower(a0[len-2]) == 'o' &&
          towlower(a0[len-1]) == 'm')))
    {   programNameDotCom = (towlower(a0[len-3]) == 'c');
        len -= 4;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = a0[len-npgm-1];
        if (c == '\\') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir = ".";  /* none really visible */
    else
    {   for (i=0; i<ndir; i++) temp_buffer[i] = a0[i];
        temp_buffer[ndir] = 0;
        unicodeToUtf8(forProgramDir, temp_buffer);
        programDir = forProgramDir;
    }
    for (i=0; i<npgm; i++) temp_buffer[i] = a0[len - npgm + i];
    temp_buffer[npgm] = 0;
    unicodeToUtf8(forProgramName, temp_buffer);
    programName = forProgramName;
    return 0;
}

#else /* WIN32: now the Unix and Linux version */


/* Different systems put or do not put underscores in front of these
 * names. My adaptation here should give me a chance to work whichever
 * way round it goes.
 */

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif

/*
 * I will not take any action at all to deal with UTF-8 or Unicode issues
 * in filenames or paths. Indeed most of Linux and certainly most of my
 * code will risk terribly confusion with various perfectly ordinary
 * 7-bit characters such as blank (' ') within filenames, so the issue
 * of international alphabets there is something I will not really fuss
 * about yet.
 */

int find_program_directory(char *argv0)
{
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    int n, n1;
    memset(pgmname, 0, sizeof(pgmname));
/*
 * If the main reduce executable is has a full path-name /xxx/yyy/zzz then
 * I will use /xxx/yyy as its directory To find this I need to find the full
 * path for the executable. I ATTEMPT to follow the behaviour of "sh",
 * "bash" and "csh".  But NOTE WELL that if anybody launches this code in
 * an unusual manner (eg using an "exec" style function) that could confuse
 * me substantially. What comes in via argv[0] is typically just the final
 * component of the program name - what I am doing here is scanning to
 * see what path it might have corresponded to.
 *
 *
 * If the name of the executable starts with a "/" it is already an
 * absolute path name. I believe that if the user types (to the shell)
 * something like $DIR/bin/$PGMNAME or ~user/subdir/pgmname then the
 * environment variables and user-name get expanded out by the shell before
 * the command is actually launched.
 */
    if (argv0 == NULL || argv0[0] == 0) /* Information not there - return */
    {   programDir = (const char *)"."; /* some sort of default. */
        programName = (const char *)"wxfwin";
        fullProgramName = (const char *)"./wxfwin";
        return 0;
    }
/*
 * I will treat 3 cases here
 * (a)   /abc/def/ghi      fully rooted: already an absolute name;
 * (b)   abc/def/ghi       treat as ./abc/def/ghi;
 * (c)   ghi               scan $PATH to see where it may have come from.
 */
    else if (argv0[0] == '/') fullProgramName = argv0;
    else
    {   for (w=argv0; *w!=0 && *w!='/'; w++);   /* seek a "/" */
        if (*w == '/')      /* treat as if relative to current dir */
        {   /* If the thing is actually written as "./abc/..." then */
            /* strip of the initial "./" here just to be tidy. */
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    /* fail! 1=current directory failure */
            if (n + strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; /* Current dir unavailable or full name too long */
            else
            {   pgmname[n] = '/';
                strcpy(&pgmname[n+1], argv0);
                fullProgramName = pgmname;
            }
        }
        else
        {   const char *path = my_getenv("PATH");
/*
 * I omit checks for names of shell built-in functions, since my code is
 * actually being executed by here. So I get my search path and look
 * for an executable file somewhere on it. I note that the shells back this
 * up with hash tables, and so in cases where "rehash" might be needed this
 * code may become confused.
 */
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
/* I expect $PATH to be a sequence of directories with ":" characters to
 * separate them. I suppose it COULD be that somebody used directory names
 * that had embedded colons, and quote marks or escapes in $PATH to allow
 * for that. In such case this code will just fail to cope.
 */
            if (path != NULL)
            {   while (*path != 0)
                {   while (*path == ':') path++; /* skip over ":" */
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > (int)(sizeof(pgmname)-3-strlen(argv0)))
                            return 3; /* fail! 3=$PATH element overlong */
                    }
/* Here I have separated off the next segment of my $PATH and put it at
 * the start of pgmname. Observe that to avoid buffer overflow I
 * exit abruptly if the entry on $PATH is itself too big for my buffer.
 */
                    pgmname[n++] = '/';
                    strcpy(&pgmname[n], argv0);
/* see if the file whose name I have just built up exists at all. */
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode; /* info about the file found */
/*
 * I now want to check if there is a file of the right name that is
 * executable by the current (effective) user.
 */
                    if (protection & S_IXOTH ||
                        (mygid == hisgid && protection & S_IXGRP) ||
                        (myuid == hisuid && protection & S_IXUSR))
                    {   ok = 1;   /* Haha - I have found the one we ... */
                        break;    /* are presumably executing! */
                    }
                }
            }
            if (!ok) return 4;    /* executable not found via $PATH */
/* Life is not yet quite easy! $PATH may contain some items that do not
 * start with "/", ie that are still local paths relative to the
 * current directory. I want to be able to return an absolute fully
 * rooted path name! So unless the item we have at present starts with "/"
 * I will stick the current directory's location in front.
 */
            if (pgmname[0] != '/')
            {   char temp[LONGEST_LEGAL_FILENAME];
                memset(temp, 0, sizeof(temp));
                strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    /* fail! 1=current directory failure */
                if ((n + strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                strcpy(&pgmname[n], temp);
            }
            fullProgramName = pgmname;
        }
    }       
/*
 * Now if I have a program name I will try to see if it is a symbolic link
 * and if so I will follow it.
 */
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        memset(temp, 0, sizeof(temp));
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
/* Now fullProgramName is set up, but may refer to an array that
 * is stack allocated. I need to make it proper!
 */
    w = (char *)malloc(1+strlen(fullProgramName));
    if (w == NULL) return 5;           /* 5 = malloc fails */
    strcpy(w, fullProgramName);
    fullProgramName = w;
#ifdef RAW_CYGWIN
/*
 * Now if I built on raw cygwin I may have an unwanted ".com" or ".exe"
 * suffix, so I will purge that! This code exists here because the raw
 * cygwin build has a somewhat schitzo view as to whether it is a Windows
 * or a Unix-like system. When I am using raw cygwin I am really not
 * living in a Windows world (and I have not investigated whether I can
 * build wxWidgets in that case anyway).
 */
    if (strlen(w) > 4)
    {   w += strlen(w) - 4;
        if (w[0] == '.' &&
            ((tolower(w[1]) == 'e' &&
              tolower(w[2]) == 'x' &&
              tolower(w[3]) == 'e') ||
             (tolower(w[1]) == 'c' &&
              tolower(w[2]) == 'o' &&
              tolower(w[3]) == 'm'))) w[0] = 0;
    }
#endif
/* OK now I have the full name, which is of the form
 *   abc/def/fgi/xyz
 * and I need to split it at the final "/" (and by now I very fully expect
 * there to be at least one "/".
 */
    for (n=strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               /* 6 = no "/" in full file path */
    w = (char *)malloc(1+n);
    if (w == NULL) return 7;           /* 7 = malloc fails */
    strncpy(w, fullProgramName, n);
    w[n] = 0;
/* Note that if the executable was "/foo" then programDir will end up as ""
 * so that programDir + "/" + programName works out properly.
 */
    programDir = w;
    n1 = strlen(fullProgramName) - n;
    w = (char *)malloc(n1);
    if (w == NULL) return 8;           /* 8 = malloc fails */
    strncpy(w, fullProgramName+n+1, n1-1);
    w[n1-1] = 0;
    programName = w;
    return 0;                          /* whew! */
}

#endif /* WIN32: end of Unix/Linux name unpicking */


#ifndef S_IRUSR
#ifdef __S_IRUSR
#define S_IRUSR __S_IRUSR
#endif
#endif

#ifndef S_IWUSR
#ifdef __S_IWUSR
#define S_IWUSR __S_IWUSR
#endif
#endif

#ifndef S_IXUSR
#ifdef __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif
#endif

extern int get_home_directory(char *b, int len);
extern int get_users_home_directory(char *b, int len);

static lookup_function *look_in_variable = NULL;

void fwin_set_lookup(lookup_function *f)
{
    look_in_variable = f;
}

void process_file_name(char *filename, char *old, size_t n)
/*
 * This procedure maps filenames by expanding some environment
 * variables.  It is very thoroughly system specific, which is why it
 * is in this file.  See also LONGEST_LEGAL_FILENAME in "tags.h" for a
 * limit on the permitted size of an expanded filename.
 * The input (old) is not necessarily properly terminated as a C string,
 * so n says how many characters to inspect.  Build a converted name
 * in filename.
 * At present the expansions I allow are:
 *
 *    $xxx   (terminated by '.', '/' or '\' with at least one char x)
 *    ${xxx} (self-terminating)
 *           First check for a Lisp variable @xxx. If this is set (and is
 *           a string or a symbol) then its value is used. If not then
 *           next inspect the environment variable xxx and dump its
 *           value into the output.  If the variable is unset then a check
 *           is made for the value of a global lisp variable called $xxx,
 *           and if that exists and is a string or symbol it is used.
 *           If $xxx is undefined a null string is inserted.
 *           If one of the variables is defined but has an improper value
 *           then the whole file-translation fails.
 *           The use of two Lisp variables makes it possible to control
 *           precedence between these and shell variables.
 *           At one stage I make the search order $xxx, env, @xxx, but then
 *           in shell scripts it is easier to go "-D@xxx=..." because
 *           "-D$xxx=..." tends to get subject to shell expansion. So now
 *           I give priority to the version I use most, to avoid being bitten
 *           when somebody has a stray shell variable set.
 *
 *    ~      ) followed by '.', '/' or '\'
 *    ~xxx   )
 *           On Unix these try to find home directories using
 *           getpwuid(getuid()) for '~' and getpwnam() for ~xxx.
 *           If that fails ~ expands into nothing at all.
 *           This syntax is only recognised at the very start of a file-name.
 *           For systems other than Unix this syntax will not be useful and
 *           should be avoided, however as an experimental place-holder I
 *           may do things with environment variables called HOME etc.
 * 
 * 
 * I convert file-names of the form aaa/bbb/ccc.ddd into something
 * acceptable to the system being used, even though this may result in
 * some native file titles that include '/' characters becoming unavailable.
 * The reasoning here is that scripts and programs can then use Unix-like
 * names and non-Unix hosts will treat them forgivingly.
 *
 *
 */
{
    int i;
    int c;
    char *o;
    if (n == 0)
    {   *filename = 0;
        return;    /* deem zero-length name to be illegal */
    }
    o = filename;
    c = *old;
/*
 * First I deal with a leading "~"
 */
    if (c == '~')
    {   old++;
        n--;
        while (n != 0)
        {   c = *old;
            if (c == '.' || c == '/' || c == '\\') break;
            old++;
            n--;
            *o++ = (char)c;
        }
        *o = 0;
/*
 * actually deciding what the home directory is is passed down to a
 * system-specific call, but it is not to be relied upon especially
 * on personal computers.
 */
        if (o == filename)  /* '~' on its own */
        {   get_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
        else
        {   get_users_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
    }
/*
 * Having copies a user-name across (if there was one) I now copy the
 * rest of the file-name, expanding $xxx and ${xxx} as necessary.
 */
    while (n != 0)
    {   c = *old++;
        n--;
/*
 * If I find a "$" that is either at the end of the file-name or that is
 * immediately followed by ".", "/" or "\" then I will not use it for
 * parameter expansion. This at least gives me some help with the RISCOS
 * file-name $.abc.def where the "$" is used to indicate the root of the
 * current disc. Well RISCOS is no longer supported here so this does
 * not worry me a lot!
 */
        if (c == '$' && n != 0 &&
            (c = *old) != '.' && c != '/' && c != '\\')
        {   char *p = o;
            const char *w;
/*
 * I collect the name of the parameter at the end of my file-name buffer,
 * but will over-write it later on when I actually do the expansion.
 */
            if (c == '{')
            {   old++;
                n--;
                while (n != 0)
                {   c = *old++;
                    n--;
                    if (c == '}') break;
                    *p++ = (char)c;
                }
            }
            else
            {   while (n != 0)
                {   c = *old;
                    if (c == '.' || c == '/' || c == '\\') break;
                    old++;
                    n--;
                    *p++ = (char)c;
                }
            }
            *p = 0;
            i = strlen(o) + 2;
            while (i-- != 0) o[i] = o[i-1];
            if (look_in_variable != NULL &&
                (p = (*look_in_variable)(o, '@')) != NULL &&
                p != o) o = p;
            else 
            if ((w = my_getenv(o+1)) != NULL)    /* Shell variable? */
            {   strcpy(o, w);
                o = o + strlen(o);
            }
            else if (look_in_variable != NULL &&
                     (p = (*look_in_variable)(o, '$')) != NULL)
                o = p;
            else
            {   *filename = 0;  /* return reporting failure */
                return;
            }
        }
        else *o++ = (char)c;
    }
    *o = 0;


#ifdef WIN32
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues. Specifically I need
 * to map "/" separators into "\" so that if a user presents a file
 * name such as aaa/bbb/ccc.d it gets passed to the operating system
 * as aaa\bbb\ccc.d
 * Note that I enable this code under the heading MS_DOS but really it
 * means any file-system (eg Windows too) that uses "\" as its main
 * directory separator character.
 * As of September 2004 I will also map an intial sequence
 *         /cygdrive/x/
 * onto    x:\
 */

    if (strncmp(filename, "/cygdrive/", 10) == 0 &&
                filename[11] == '/')
    {   char *p = filename+2, *tail = filename+11;
        filename[0] = filename[10];
        filename[1] = ':';
        while (*tail != 0) *p++ = *tail++;
        *p = 0;
    }
/*
 * I map "/" characters in MSDOS filenames into "\" so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 */
    {   int j;
        char *tail = filename;
        while ((j = *tail) != 0)
        {   if (j == '/') *tail = '\\';
            tail++;
        }
/*
 * stat and friends do not like directories referred to as "\foo\", so check
 * for a trailing slash, being careful to respect directories with names
 * like "\" and "a:\".
 */
       j = strlen(filename);
       if (j > 0 && j != 1 && !(j == 3 && *(filename+1) == ':'))
       {
           if ( (*(tail - 1) == '\\')) *(tail - 1) = 0;
       }
    }
#endif /* WIN32 */
#if defined MACINTOSH && defined MAC_FRAMEWORK
/*
 * For MacOS the issue of "aliases" arises. The "preferred" file system
 * is HFS+ and that supports both links and aliases, but at the very least
 * some old users and legacy applications will certainly continue to use
 * links. However the Posix-style APIs do not provide any way to deal with
 * them! So here I use some Carbon calls to map a path to an alias into
 * a path to the file it refers to. Thise code was requested by Thomas
 * Sturm who provided a skeleton chunk of code showing what APIs needed to be
 * used and references to the documentation to them, so thanks are due.
 */
    {   char alias[LONGEST_LEGAL_FILENAME];
        FSRef ref;
        Boolean is_folder, is_alias;
        memset(alias, 0, sizeof(alias));
/*
 * This works by converting from a path to an FSRef object, which is the Mac
 * internal handle. It can then resolve the alias. I use the option that
 * will chain through sequences of aliases if necessary until a genuine
 * regular file is found. If no aliases has been involved I do nothing.
 * If any of the Mac system calls report errors of any sort I do
 * nothing.  In the end if all works I convert from an FSRef back to a path and
 * copy it to where I want it to be.
 */
        if (FSPathMakeRef((UInt8 *)filename, &ref, NULL) == noErr &&
            FSResolveAliasFile(&ref, TRUE, &is_folder, &is_alias) == noErr &&
            is_alias &&
            FSRefMakePath(&ref, (UInt8 *)alias, (UInt32)sizeof(alias)) == noErr)
        {   strcpy(filename, alias);
        }
    }
#endif /* MAC stuff */
}

/*
 * datestamps that I store away have given me significant
 * trouble with regard to portability - so now I deal with times by
 * talking to the system in terms of broken down local time (struct tm).
 * I then pack things up for myself to get 32-bit timestamps. The
 * encoding I use aims at simplicity - it treats all months as 31 days
 * and thus does not have to worry about leap years etc.  The effect will be
 * rather as if dates were stored as strings. And MAYBE I thereby avoid
 * some of the oddities that arise when data files containing packed dates
 * are transported across time-zones.
 *
 * NOTE: dates here are based from 1970, and this will lead to overflow
 * beyond 32-bit offsets in around 2099. At the time of writing that is around
 * 100 years ahead, and I intend not to worry. Note it is important here to
 * us an unsigned number or else the overflow is sooner and might even cause
 * genuine pain!
 *
 * ANOTHER NOTE: I only allow the "seconds" field to run from 0 to 59.
 * In consequence I am quite possibly going to mess up when there are
 * leap seconds, and this confusion could make times processed here
 * disagree across systems by up to the number of leap seconds that
 * have been used to date. Well I have quite severe doubts about time
 * agreement closer than a few seconds anyway and so again I am going to
 * ignore this oddity! But those who keep systems synchronised at a
 * millisecond or microsecond resolution (GPS anybody?) might need to
 * know I have been sloppy.
 */

void unpack_date(unsigned long int r,
                 int *year, int *mon, int *day,
                 int *hour, int *min, int *sec)
{
    *sec  = r%60; r = r/60;
    *min  = r%60; r = r/60;
    *hour = r%24; r = r/24;
    *day  = r%32; r = r/32;
    *mon  = r%12; r = r/12;
/*
 * Please note that the Standard C "struct tm" structure specifies dates
 * in terms of years since 1900. Thus from the year 2000 on the year will
 * be a value of at least 100, but that is not supposed to be any special
 * cause of disaster. In particular the calculation involving "+70"
 * rather than "+1970" is NOT a bug here!
 */
    *year = 70+r;
}

unsigned long int pack_date(int year, int mon, int day,
                            int hour, int min, int sec)
{
    unsigned long int r = (year-70)*12 + mon;
    r = r*32 + day;
    r = r*24 + hour;
    r = r*60 + min;
    return r*60 + sec;
}

typedef struct date_and_type
{
    unsigned long int date;
    unsigned long int type;
} date_and_type;


#ifdef WIN32
/*
 * This version is for Windows NT 3.1 with Microsoft VC++, Windows 95, 98,
 * NT 3.5, 4.0, 2000, XP etc etc, also with Watcom C, mingw32 and so on.
 * Note it uses the native Windows capabilities and so it is not intended
 * for use with cygwin and its Unix-portability layer.
 */

#include "windows.h"

int Cmkdir(char *name)
{
    SECURITY_ATTRIBUTES s;
    s.nLength = sizeof(s);
    s.lpSecurityDescriptor = NULL;
    s.bInheritHandle = FALSE;
    return CreateDirectory(name, &s);
}

int truncate_file(FILE *f, long int where)
{
    if (fflush(f) != 0) return 1;
#ifdef _MSC_VER
    return _chsize(_fileno(f), where);  /* Returns zero if success */
#else
#ifdef __CYGWIN__
    if (fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  /* Returns zero if success */
#else
    return chsize(fileno(f), where);    /* Returns zero if success */
#endif
#endif
}

void set_filedate(char *name, unsigned long int datestamp,
                              unsigned long int filetype)
{
    HANDLE h = CreateFile(name, GENERIC_WRITE, 0, NULL,
                          OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    SYSTEMTIME st;
    FILETIME ft;
    int yr, mon, day, hr, min, sec;
/*
 * Here datestamp is a time expressed (sort of) in seconds since the start
 * of 1970. * I need to convert it into a broken-down SYSTEMTIME so that I
 * can then re-pack it as a Windows-NT FILETIME....
 */
    unpack_date(datestamp, &yr, &mon, &day, &hr, &min, &sec);
    st.wMilliseconds = 0;
    st.wYear = yr + 1900;  /* Windows NT uses full dates since the year 0 */
    st.wMonth = mon + 1;
    st.wDay = day;
    st.wHour = hr;
    st.wMinute = min;
    st.wSecond = sec;
    SystemTimeToFileTime(&st, &ft);
    SetFileTime(h, NULL, NULL, &ft);
    CloseHandle(h);
}

void put_fileinfo(date_and_type *p, char *name)
{
    unsigned long int datestamp, filetype;
#ifdef _MSC_VER
    struct _stat file_info;
#else
    struct stat file_info;
#endif
    struct tm *st;
/*
 * Read file parameters...  Maybe I should use a Windows-style not a Unix-style
 * call here?
 */
#ifdef _MSC_VER
    _stat(name, &file_info);
#else
    stat(name, &file_info);
#endif
    st = localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;
    p->date = datestamp;
    p->type = filetype;
}

#else /* WIN32 */

/*
 * On some Unix variants I may want this declaration inserted and on others
 * it would clash with a system-provided header file. Ugh! With luck the C
 * compiler will invent a suitable calling convention even if a declaration
 * is not present.
 * extern ftruncate(int, int);
 */

int truncate_file(FILE *f, long int where)
{
    if (fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  /* Returns zero if success */
}

/* extern void mkdir(const char *, unsigned short int); */

int Cmkdir(char *s)
{
    mkdir(s, 0775);
    return 1;
}

#include <utime.h>

#ifdef EMBEDDED
#ifdef __ARM_EABI__

void utime(const char *s, struct utimbuf *t);

#endif
#endif

void set_filedate(char *name, unsigned long int datestamp,
                              unsigned long int filetype)
{
#ifdef UTIME_TIME_T
    time_t tt[2];
#else
    struct utimbuf tt;
#endif
    time_t t0;
    struct tm st;
    unpack_date(datestamp, &st.tm_year, &st.tm_mon, &st.tm_mday,
                           &st.tm_hour, &st.tm_min, &st.tm_sec);
    st.tm_isdst = -1;
    t0 = mktime(&st);
#ifdef UTIME_TIME_T
    tt[0] = tt[1] = t0;
#else
    tt.actime = tt.modtime = t0;
#endif
    utime(name, &tt);
}

void put_fileinfo(date_and_type *p, char *name)
{
    unsigned long int datestamp, filetype;
    struct stat file_info;
    struct tm *st;
/*
 * Read file parameters...
 */
    stat(name, &file_info);
    st = localtime(&(file_info.st_mtime));
    datestamp = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                          st->tm_hour, st->tm_min, st->tm_sec);
    filetype = 0xfff;  /* should get access status here? */
    p->date = datestamp;
    p->type = filetype;
}

#endif /* WIN32 */


/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me.  This is necessarily dependent on
 * the operating system I am running under, hence the conditional compilation
 * here.  The specification I want is:
 *       void scan_directory(const char *dir,
 *                    void (*proc)(char *name, int why, long int size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed. I also arrange that an input string
 * "." (on Windows, DOS and Unix) or "@" (Archimedes) is treated as a request
 * to scan the whole of the current directory.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 *
 * I also provide a similar function scan_files() with the same arguments that
 * does just the same except that it does not recurse into sub-directories,
 * but if the name originally passed is that of a directory then all the
 * files in it will be scanned.
 */

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts.
 */

int scan_leafstart = 0;

/*
 * For CSL's purposes the following 3 are in syscsl.h, but in general I do not
 * want to use that header with random wxfwin applications...
 */
#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

/*
 * I use a (static) flag to indicate how sub-directories should be
 * handled, and what to do about case. By default I fold to lower case
 * on windows. setting hostcase non-zero causes case to be preserved.
 */

static int recursive_scan, hostcase = 0;

void set_hostcase(int fg)
{
    hostcase = fg;
}

#ifdef WIN32

/* Hmm - buffer overflow worry with the next line! */
static char filename[LONGEST_LEGAL_FILENAME];

static WIN32_FIND_DATA *found_files = NULL;
static int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files(void)
{
    if (n_found_files > max_found_files - 5)
    {   WIN32_FIND_DATA *fnew = (WIN32_FIND_DATA *)
            realloc((void *)found_files,
                    sizeof(WIN32_FIND_DATA)*
                       (max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1;  /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

/*
 * Anybody compiling using Microsoft Visual C++ had better note that
 * the type declared in the Microsoft header files for qsort insists
 * on a __cdecl here. Ugh.
 */
int MS_CDECL alphasort_files(const void *a, const void *b)
{
    const WIN32_FIND_DATA *fa = (const WIN32_FIND_DATA *)a,
                          *fb = (const WIN32_FIND_DATA *)b;
    return strncmp(fb->cFileName, fa->cFileName, sizeof(fa->cFileName));
}

static void exall(int namelength,
                  void (*proc)(const char *name, int why, long int size))
/*
 * This procedure scans a directory-full of files, calling the given procedure
 * to process each one it finds.
 */
{
#ifdef EMBEDDED
    printf("exall function called - but not implemented here\n");
    return; /* Dummy version here */
#else
    WIN32_FIND_DATA found;
    int rootlen = namelength, first = n_found_files;
    HANDLE hSearch = FindFirstFile(filename, &found);
    if (hSearch == INVALID_HANDLE_VALUE) return;  /* No files found at all */
    for (;;)
    {   if (more_files()) break;
        found_files[n_found_files++] = found;
        if (!FindNextFile(hSearch, &found)) break;
    }
    FindClose(hSearch);
    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(WIN32_FIND_DATA),
          alphasort_files);
    while (rootlen>=0 && filename[rootlen]!='\\') rootlen--;
    while (n_found_files != first)
    {   char *p = (char *)&found_files[--n_found_files].cFileName;
        int c;
/*
 * Fill out filename with the actual name I grabbed, i.e. with
 * wild-cards expanded.
 */
        namelength = rootlen+1;
/*
 * I fold DOS filenames into lower case because it does not matter much
 * to DOS and I think it looks better - furthermore it helps when I move
 * archives to other systems.  So I do the same on NT.
 */
        while ((c = *p++) != 0)
        {   if (!hostcase) if (isupper(c)) c = tolower(c);
            filename[namelength++] = (char)c;
        }
        filename[namelength] = 0;
        if (found_files[n_found_files].dwFileAttributes &
            FILE_ATTRIBUTE_DIRECTORY)
        {   if (found_files[n_found_files].cFileName[0] != '.')
/*
 * I filter out directory names that start with '.'.
 * This is to avoid calamity with recursion though chains such as .\.\.\.....
 */
            {   proc(filename, SCAN_STARTDIR, 0);
                if (!recursive_scan) continue;

                strcpy(&filename[namelength], "\\*.*");
/*
 * Append "\*.*" to the directory-name and try again, thereby scanning
 * its contents.
 */
                exall(namelength+4, proc);
                filename[namelength] = 0;
                proc(filename, SCAN_ENDDIR, 0);
            }
        }
        else proc(filename, SCAN_FILE,
                  found_files[n_found_files].nFileSizeLow);
    }
    return;
#endif /* EMBEDDED */
}

void scan_directory(const char *dir,
                    void (*proc)(const char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(strlen(filename), proc);
}

void scan_files(const char *dir,
                void (*proc)(const char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir,".")==0)
    {   strcpy(filename, "*.*");
        scan_leafstart = 0;
    }
    else
    {   scan_leafstart = strlen(dir);
        strcpy(filename, dir);
        if (filename[scan_leafstart-1] == '\\')
        {   /* Root directory */
            strcpy(filename+scan_leafstart, "*.*");
            --scan_leafstart;
        }
        else strcpy(filename+scan_leafstart, "\\*.*");
        scan_leafstart++;
    }
    exall(strlen(filename), proc);
}

#else  /* WIN32 */

static char filename[LONGEST_LEGAL_FILENAME];

/*
 * The code here uses opendir, readdir and closedir and as such ought to
 * be Posix compatible. The macro USE_DIRECT_H can cause an older variant
 * on this idea to be used. BUt it may need adjustment for different
 * systems.
 */


static char **found_files = NULL;

int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files(void)
{
    if (n_found_files > max_found_files - 5)
    {   char **fnew = (char **)
            realloc((void *)found_files,
                    sizeof(char *) *
                       (max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1;  /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{
    const char *fa = *(const char **)a,
               *fb = *(const char **)b;
    return strcmp(fb, fa);
}

static void scan_file(int namelength,
                      void (*proc)(const char *name, int why, long int size));

static void exall(int namelength,
                  void (*proc)(const char *name, int why, long int size))
{
#ifdef EMBEDDED
    printf("exall function called - but not implemented here\n");
    return; /* Dummy version here */
#else
    DIR *d;
#ifdef USE_DIRECT_H
    struct direct *dd;
#else
    struct dirent *dd;
#endif
    int rootlen = namelength, first = n_found_files;
    proc(filename, SCAN_STARTDIR, 0);
    d = opendir(filename);
    if (d != NULL)
    {   while ((dd = readdir(d)) != NULL)
        {   char *leafname = dd->d_name;
            char *copyname;
/*
 * readdir hands back both "." and ".." but I had better not recurse
 * into either!
 */
            if (strcmp(leafname, ".") == 0 ||
                strcmp(leafname, "..") == 0) continue;
            if (more_files()) break;
            copyname = (char *)malloc(1+strlen(leafname));
            if (copyname == NULL) break;
            strcpy(copyname, leafname);
            found_files[n_found_files++] = copyname;
        }
        closedir(d);
    }

    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(char *),
          alphasort_files);

    filename[rootlen] = '/';
    while (n_found_files != first)
    {   char *p = found_files[--n_found_files];
        int c;
        namelength = rootlen+1;
        while ((c = *p++) != 0) filename[namelength++] = (char)c;
        free((void *)found_files[n_found_files]);
        filename[namelength] = 0;
        scan_file(namelength, proc);
    }

    filename[rootlen] = 0;
    proc(filename, SCAN_ENDDIR, 0);
#endif /* EMBEDDED */
}

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

static void scan_file(int namelength,
                      void (*proc)(const char *name, int why, long int size))
{
    struct stat buf;
    stat(filename, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   if (!recursive_scan) proc(filename, SCAN_STARTDIR, 0);
        else exall(namelength, proc);
    }
    else if ((buf.st_mode & S_IFMT) == S_IFREG)
        proc(filename, SCAN_FILE, buf.st_size);
/*  else fprintf(stderr, "Mode of %s is %o\n", filename, buf.st_mode); */
}

void scan_directory(const char *dir,
                    void (*proc)(const char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    scan_file(scan_leafstart-1, proc);
}

void scan_files(const char *dir,
                void (*proc)(const char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(scan_leafstart-1, proc);
}

#endif /* WIN32 */


FILE *open_file(char *filename, char *old, size_t n,
                char *mode, FILE *old_file)
{
/*
 * mode is something like "r" or "w" or "rb", as needed by fopen(),
 * and old_file is NULL normally, but can be a (FILE *) to indicate
 * the use of freopen rather than fopen.
 */
    FILE *ff;
    process_file_name(filename, old, n);
    if (*filename == 0) return NULL;
    if (old_file == NULL) ff = fopen(filename, mode);
    else ff = freopen(filename, mode, old_file);
/*
 * In suitable cases when the first attempt to open the file fails I
 * will try creating any necessary directories and then try again.
 */
    if (ff==NULL && *mode=='w')
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
        if (old_file == NULL) ff = fopen(filename, mode);
        else ff = freopen(filename, mode, old_file);
    }
    return ff;
}


static char err_buf[LONGEST_LEGAL_FILENAME+100];

char *change_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0)
    {   sprintf(err_buf, "Filename \"%s\" invalid.", old);
        return err_buf;
    }
    if (chdir(filename))
    {   const char *msg;
        switch (errno)
        {
    case ENOTDIR:
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
       sprintf(err_buf, msg, filename);
       return err_buf;
    }
    else return NULL;
}

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    return Cmkdir(filename);
}

static void remove_files(const char *name, int dirp, long int size)
/* Remove a file, or a directory and all its contents */
{
    switch (dirp)
    {
case 0:               /* SCAN_FILE */
      remove(name);
      return;
case 2:               /* SCAN_ENDDIR */
      rmdir(name);
      return;
default:              /* 1 == SCAN_STARTDIR */
      return;
    }
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /*
     * We cannot simply use remove here, since this will not
     * work with directories and their contents.  Hence the
     * use of scan_directory.
     */
    scan_directory(filename, remove_files);
    return 0;
}

int delete_wildcard(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
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
#else
        glob_t gg;
        int i, rc = glob(filename, GLOB_NOSORT, NULL, &gg);
        for (i=0; i<gg.gl_pathc; i++)
            scan_directory(gg.gl_pathv[i], remove_files);
        globfree(&gg);
#endif
    }
    return 0;
}

int64_t file_length(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) return -1;
    return (int64_t)(buf.st_size);
}

#ifdef NAG_VERSION

int list_directory_members(char *filename, char *old, char **filelist[],
                           size_t n)
{   struct dirent **namelist;
    int number_of_entries, i;
    char **files;

    process_file_name(filename, old, n);

    /* scandir expects "." for the current directory */
    if (*filename == 0) number_of_entries = scandir(".",&namelist,NULL,NULL);
    else number_of_entries = scandir(filename,&namelist,NULL,NULL);

    /*
     * If the scandir failed then return now, since we make an assumption later
     * that we found at least two entries: "." and "..".
     */
    if (number_of_entries == -1) return -1;

    files=(char **)malloc(number_of_entries*sizeof(char *));

    for (i=0;i<number_of_entries;++i) 
    {   files[i] = strdup(namelist[i]->d_name);
        free(namelist[i]);
    }

    free(namelist);

    *filelist = files;

    /*
     * When we return we will prepend the directory name to the files, so we
     * must make sure it is suitable for that.  This is done here since it is
     * platform dependent (i.e. in DOS we would need to ensure the last
     * character was "\").
     */
    /*
    i=strlen(filename);
    if (i > 0 && filename[i-1] != '/')
    {   filename[i]='/';
        filename[i+1]='\0';
    }
    */

    return number_of_entries;
}

#else


void list_directory_members(char *filename, char *old,
                            size_t n,
                            void (*fn)(const char *name, int why, long int size))
{
    process_file_name(filename, old, n);
    scan_files(filename, fn);
}

#endif


int file_exists(char *filename, char *old, size_t n, char *tt)
/*
 * This returns YES if the file exists, and as a side-effect copies a
 * textual form of the last-changed-time of the file into the buffer tt.
 */
{
    struct stat statbuff;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename, &statbuff) != 0) return 0;
    strcpy(tt, ctime(&(statbuff.st_mtime)));
    return 1;
}

int directoryp(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) return 0;
    return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

char *get_truename(char *filename, char *old, size_t n)
{
    struct stat buf;
    char *temp, *fn, *dir;
    char pwd[LONGEST_LEGAL_FILENAME];
    memset(pwd, 0, sizeof(pwd));

    process_file_name(filename, old, n);
    if (*filename == 0)
    {   strcpy(filename, "truename");
        return NULL;
    }

    /* Find out whether we have a file or a directory */
    if (stat(filename,&buf) == -1)
    {   strcpy(filename, "truename: cannot stat file");
        return NULL;
    }

    /* Store current directory */
    if (get_current_directory(pwd, LONGEST_LEGAL_FILENAME) < 0)
    {   strcpy(filename, "truename: cannot get current working directory");
        return NULL;
    }

    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   /* We have a directory */
        char *dir = (char*)malloc(LONGEST_LEGAL_FILENAME);
        if (chdir(filename) != 0) 
        {   strcpy(filename, "truename: cannot change directory");
            return NULL;
        }
        if (getcwd(dir,LONGEST_LEGAL_FILENAME) == NULL)
        {   strcpy(filename, "truename: cannot get current working directory");
            return NULL;
        }
        
        if (chdir(pwd) != 0)
        {   strcpy(filename, "truename: cannot change directory");
            return NULL;
        }
/*
 * Axiom-specific hack: truename preserves '/' at the end of 
 * a path
 */
        if (old[n-1] == '/' && dir[strlen(dir)-1] != '/')
        {   n = strlen(dir);
            dir[n]   = '/';
            dir[n+1] = '\0';
        }
        return dir;
    }
    else
    {   /* Assume we have some kind of file */
        temp = strrchr(filename,'/');
        if (temp) 
        {   /* Found a directory component */
            char theDir[LONGEST_LEGAL_FILENAME];
            memset(theDir, 0, sizeof(theDir));
            fn   = (char *)malloc(1+strlen(temp));
            strcpy(fn, temp);
            *temp = '\0';
            /* fn is now "/file" and filename is the directory */

            if (chdir(filename) != 0)
            {   strcpy(filename, "truename: cannot change directory");
                return NULL;
            }
            if (get_current_directory(theDir, LONGEST_LEGAL_FILENAME) < 0)
            {   strcpy(filename, "truename: cannot get current working directory");
                return NULL;
            }
            temp = theDir;
            if (chdir(pwd) != 0)
            {   strcpy(filename, "truename: cannot change directory");
                return NULL;
            }
            dir = (char *)malloc((strlen(temp) + strlen(fn) + 1)*sizeof(char));
            if (dir == NULL)
            {   strcpy(filename, "truename: run out of memory");
                return NULL;
            }
            strcpy(dir, temp);
            strcat(dir, fn);
            free(fn);
            return dir;
        }
        else
        {   dir = (char *)malloc((strlen(pwd) + strlen(filename) + 2)*sizeof(char));
            if (dir == NULL)
            {   strcpy(filename, "truename: run out of memory");
                return NULL;
            }
            strcpy(dir, pwd);
            strcat(dir, "/");
            strcat(dir, filename);
            return dir;
        }
    }
}

/*
 * The tests here are probably rather WRONG_MINDED in that they check the
 * status of the file and report whether its OWNER could read, write or
 * execute it, rather than whether the current user could. However what
 * I do here will hold the fort for now.
 */

int file_readable(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) 
      return 0; /* File probably does not exist */
/*
 * The #ifdef here is a cop-out and has surfaced while trying to build
 * using the Microsoft C compiler, where there will be a different API I
 * could use to get this information...
 */
#ifndef S_IRUSR
    return 1;
#else
    return (buf.st_mode & S_IRUSR);
#endif
}


int file_writeable(char *filename, char *old, size_t n)
{ 
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) 
      return 0; /* Should we check to see if the directory is writeable? */
#ifndef S_IWUSR
    return 1;
#else
    return (buf.st_mode & S_IWUSR);
#endif
}


int file_executable(char *filename, char *old, size_t n)
{ 
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) 
      return 0; /* Should we check to see if the directory is writeable? */
#ifndef S_IXUSR
    return 1;
#else
    return (buf.st_mode & S_IXUSR);
#endif
}


int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return rename(from_name,to_name);
}

/*
 * getenv() is a mild pain: Windows seems
 * to have a strong preference for upper case names.  To allow for
 * all this I do not call getenv() directly but go via the following
 * code that can patch things up.
 */

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    memset(uppercasename, 0, sizeof(uppercasename));
    while ((c = *s++) != 0) *p++ = toupper(c);
    *p = 0;
    return getenv(uppercasename);
#else
    return getenv(s);
#endif
}


int my_system(char *s)
{
    return system(s);
}

#define DO_NOT_USE_GETUID 1   /* For MinGW */

#ifndef DO_NOT_USE_GETUID
/*
 * "machine.h" should set DO_NOT_USE_GETUID if that function is not
 * properly available. Not having it will make the treatment of
 * (eg) "~xxx/..." in filenames less satisfactory.
 */

#include <pwd.h>

int get_home_directory(char *b, int len)
{
    int i;
    struct passwd *pw = getpwuid(getuid());
    strcpy(b, pw->pw_dir);
    i = strlen(b);
/* Here the directory handed back has "/" forced in as its final character */
    if ( b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, int len)
{
    struct passwd *pw = getpwnam(b);
    if (pw != NULL) strcpy(b, pw->pw_dir);
    else strcpy(b, ".");    /* use current directory if getpwnam() fails */
    return strlen(b);
}

#else /* USE_GETUID */

int get_home_directory(char *b, int len)
{
    int i;
    strcpy(b, getenv("HOME"));  /* Probably works with most shells */
    i = strlen(b);
    if ( b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, int len)
{
    strcpy(b, ".");    /* use current directory if getpwnam() no available */
    return 1;
}

#endif /* USE_GETUID */


#ifdef EMBEDDED
#ifdef __ARM_EABI__

int rmdir(const char *s)
{
    return 0;
}

char *getcwd(char *s, size_t n)
{
    return ".";
}

int chdir(const char *s)
{
    return 0;
}

uid_t getuid()
{
    return 100;
}

struct passwd *getpwuid(int x)
{
    return NULL;
}

void utime(const char *s, struct utimbuf *t)
{
}

int ftruncate(int a, long b)
{
    return 0;
}

int lstat(char *n, struct stat b)
{
    return 0;
}

uid_t geteuid()
{
    return 0;
}

gid_t getegid()
{
    return 0;
}

int mkdir(const char *d, mode_t m)
{
}

FILE *popen(const char *s, const char *d)
{
    return NULL;
}

int pclose(FILE *f)
{
    return 0;
}

int readlink(const char *name, char *b, size_t n)
{
    return 0;
}


#endif
#endif

/* end of wxfwin.c */
