// newstub.cpp                                    Copyright A C Norman 2020
//

// The object of this code is to be able to launch one of several binaries
// that are places in a directory adjacent to it. The one it picks
// should suit the context within which this program is run - 32 or 64 bit,
// Cygwin or native Windows.


/**************************************************************************
 * Copyright (C) 2020, Codemist Ltd.                     A C Norman       *
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


// This should be compiled with one of the following symbols predefined:
//   FAT32    isatty32 w32 cyg32
//   FAT64    isatty64 w64 cyg64
//   FAT3264  isatty32 isatty64 w32 w64 cyg32 cyg64
//   FATWIN   win32 win64


#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cstring>
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <zlib.h>


#if defined FAT32

// A fat 32 bit binary can be run under either native windows or
// 32-bit cygwin. Since it is a linked as a console mode application
// it is not suitable for launching by double-clicking. This is
// going to be usefully smaller than the FAT3264 binary, but whether the
// space saving makes the extra complication of having this one available
// is yet to be determined!

#define NUMBER_OF_MODULES  3
#define MODULE_ISATTY32    0
#define MODULE_WIN32       1
#define MODULE_CYG32       2

#elif defined FAT64

// A fat 64 bit binary can be run under either native windows or
// 64-bit cygwin. Since it is a linked as a console mode application
// it is not suitable for launching by double-clicking. This is
// going to be usefully smaller than the FAT3264 binary, but whether the
// space saving makes the extra complication of having this one available
// is yet to be determined!

#define NUMBER_OF_MODULES  3
#define MODULE_ISATTY64    0
#define MODULE_WIN64       1
#define MODULE_CYG64       2

#elif defined FAT3264

// A fat 64 bit binary is the full works, supporting either 32 or 64-bit
// usage either under native windows or either 32 or 64-bit cygwin, To
// cope with all of this makes if the biggest of all the binaries established
// here.

#define NUMBER_OF_MODULES  6
#define MODULE_ISATTY32    0
#define MODULE_ISATTY64    1
#define MODULE_WIN32       2
#define MODULE_WIN64       3
#define MODULE_CYG32       4
#define MODULE_CYG64       5

#elif defined FATWIN

// A fat windows binary is linked as a windows application and as such
// is not useful for launching from a console or cygwin - but it is good for
// double-clicking on. The version here will take advantage of 64-bit
// windows if run in that context.

#define NUMBER_OF_MODULES  2
#define MODULE_WIN32       0
#define MODULE_WIN64       1

#else

#error Unknown version of stub code

#endif

#ifndef FAT32
// FAT32 only support 32-bit versions (windows or cygwin) so does
// not need this.

// The next function is as shown at
// msdn.microsoft.com/en-us/library/windows/desktop/ms684139%28v=vs.85%29.aspx
// as the proper way to detect when the current 32-bit program is in fact
// running under Wow64 (ie with a 64-bit version of Windows beneath its feet).

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{   BOOL bIsWow64 = FALSE;
// IsWow64Process is not available on all supported versions of Windows.
// Use GetModuleHandle to get a handle to the DLL that contains the function
// and GetProcAddress to get a pointer to the function if available. Well
// probably these days it is always available on operating systems that matter,
// but the hack here is fairly simple and local so to be kind to the
// historical world I will preserve it for a while!
    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
                           GetModuleHandle(TEXT("kernel32")),"IsWow64Process");
    if(nullptr != fnIsWow64Process)
    {   if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {   //handle error - well heer I just return "no"
            return FALSE;
        }
    }
    return bIsWow64;
}

#endif // FAT32

static int64_t read8(std::FILE *f)
{   int64_t r = 0;
    int i;
    for (i=0; i<8; i++)
    {   int w = std::getc(f) & 0xff;
        r |= ((int64_t)w) << (8*i);
    }
    return r;
}

static char pPath[MAX_PATH];
static int64_t address[NUMBER_OF_MODULES];
static int64_t length[NUMBER_OF_MODULES];

//
// Run the program stored with this code and kept as a resource with
// the specified index.
//

#define ERROR_UNABLE_TO_OPEN_SELF  81
#define ERROR_BAD_LEADER           82
#define ERROR_BAD_TRAILER          83
#define ERROR_NO_MEMORY            84
#define ERROR_PROCESS_INFO         85
#define ERROR_CREATEPROCESS        86
#define ERROR_UNABLE_TO_WRITE      87
#define ERROR_NO_TEMP_FILE         88

int RunResource(int index, int forcegui, const char *modulename)
{   std::FILE *src, *dest;
    int i;
    uint64_t hdr;
#ifdef DEBUG
    std::printf("RunResource %s: %d %d\n", modulename, index, forcegui);
    std::fflush(stdout);
#endif
    GetModuleFileName(nullptr, pPath, sizeof(pPath));
#ifdef DEBUG
    std::printf("my name is %s\n", pPath);
    std::fflush(stdout);
#endif
    char *lastsep = std::strrchr(pPath, '\\');
    std::sprintf(lastsep, "\\reduce.dir\\%s", modulename);
#ifdef DEBUG
    std::printf("Code to run %s\n", pPath);
    std::fflush(stdout);
#endif
    const char *cmd = GetCommandLine();
    char *cmd1 = new (std::nothrow) char[std::strlen(cmd) + 12];
    if (cmd1 == nullptr)
    {   std::printf("No memory for new command line\n");
        std::fflush(stdout);
        return ERROR_NO_MEMORY;
    }
    std::strcpy(cmd1, cmd);
// Now a rather horrible mess. I will have several versions of Reduce
// created here
//     reduce.exe       the general one
//     reduce32.exe     only supports 32-bit systems
//     winreduce.exe    for double-clicking - does not support cygwin
//    [winreduce32.exe] double-clickable and 32-bit only
// The last of these does not go through this packing process.
// To cope with all of those the code inside Reduce will strin "win" from
// the front of an application and "32" from the end before using it
// to decide where to look for an image file. That way all the above
// will be able to use a single file "reduce.img". Further it will be
// essential that this name be picked up from argv[0] not from the
// name of the file that the application was actually launches from since
// the latter is the weird temporary file I just created.
// [Hmm - the naming conventions here need review...]
    if (forcegui) std::strcat(cmd1, " --gui");

    STARTUPINFO peStartUpInformation;
    PROCESS_INFORMATION peProcessInformation;
    std::memset(&peStartUpInformation, 0, sizeof(STARTUPINFO));
    peStartUpInformation.cb = sizeof(STARTUPINFO);
    std::memset(&peProcessInformation, 0, sizeof(PROCESS_INFORMATION));
#ifdef DEBUG
    std::printf("Launch <%s> cmd line <%s>\n", pPath, cmd1);
    std::fflush(stdout);
#endif
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
//  _set_abort_behavior(0,_WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    if (CreateProcessA(pPath,            // appname
                       cmd1,             // command line
                       nullptr,          // process attributes
                       nullptr,          // thread attributes
                       1,                // inherits handles
                       0,                // allow it to run now
                       nullptr,          // environment
                       nullptr,          // current directory
                       &peStartUpInformation,
                       &peProcessInformation))
    {   WaitForSingleObject(peProcessInformation.hProcess, INFINITE);
        DWORD rc;
        if (GetExitCodeProcess(peProcessInformation.hProcess, &rc) == 0)
            rc = ERROR_PROCESS_INFO; // Getting the return code failed!
#ifdef DEBUG
        std::printf("CreateProcess happened, rc reported as %d = %#x\n", rc,
                    rc);
#endif
        std::fflush(stdout);
        CloseHandle(peProcessInformation.hProcess);
        CloseHandle(peProcessInformation.hThread);
        return rc;
    }
    else
    {
#ifdef DEBUG
        std::printf("CreateProcess failed\n"); std::fflush(stdout);
        DWORD dw = GetLastError();
        LPVOID lpMsgBuf;
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                      FORMAT_MESSAGE_FROM_SYSTEM |
                      FORMAT_MESSAGE_IGNORE_INSERTS,
                      nullptr,
                      dw,
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      (LPSTR)&lpMsgBuf,
                      0,
                      nullptr);
        std::printf("CreateProcess failed (%d): %s\n", dw, lpMsgBuf);
        std::fflush(stdout);
#endif
        return ERROR_CREATEPROCESS;
    }
}

static const char *dll32[] =
{
#include "dll32.cpp"
    nullptr
};

static const char *dll64[] =
{
#include "dll64.cpp"
    nullptr
};

#include <windows.h>
#include <cstdio>

void dllcheck(const char **table)
{   int i, messaged = 0;
    for (i=0; table[i]!=nullptr; i++)
    {   HMODULE h = LoadLibraryEx(table[i], nullptr,
                                  DONT_RESOLVE_DLL_REFERENCES);
        if (h == nullptr)
        {   if (!messaged)
            {   std::printf("\nCygwin needs at least %s", table[i]);
                messaged = 3;
            }
            else if (messaged >= 5)
            {   std::printf(",\n  %s", table[1]);
                messaged = 1;
            }
            else
            {   std::printf(", %s", table[i]);
                messaged++;
            }
        }
        else FreeLibrary(h);
    }
    if (messaged)
    {   std::printf("\n");
        std::printf("Please run cygwin setup and install packages that will\n");
        std::printf("provide these. Then try again.\n\n");
        std::fflush(stdout);
    }
}


int main(int argc, char* argv[])
{
// The logic here starts by collecting information as to whether I am being
// run in a context where things have access to a console.
// This will NOT be the case if the code is run from mintty (the current
// cygwin terminal), a cygwin X terminal or via ssh into a cygwin version
// of sshd.  However if either input or output is connected to a disc file
// I will act the same way that I would have if there had been direct
// contact to a Windows console since in that case the run is (probably)
// non-interactive and so terminal handling is not an issue.
// Furthermore the command-line option "--", (which is used here to redirect
// the standard output) is detected and is similarly viewed as a signature
// of non-interactive use.
//
// What this is really about is deciding if there is a risk that I need to
// use the Cygwin console API.
//
// There are times in this code where I may try to launch other programs
// in ways that could potentially pop up unwanted and ugly error boxes. I
// try to disable that here.
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);

    int possibly_under_cygwin = 1, rc;
//
// I will start by detecting a number of cases where I will NOT want to
// use the cygwin version of the code. So
// (a) If I am attached to a regular Windows console then I am certainly
//     not under a cygwin mintty style console (or linked in over ssh),
//     and I am very liable to have a Windows display available. So there is
//     no point in using cygwin even if it is available.
// (b) If the user has put "-- file" on the command line then that redirects
//     the output to a file. In that case again there is no point in trying
//     to use cygwin console management and I feel happier defaulting to
//     use of the native windows version.
// (c) If either stdin or stdout is attached to a "disk" file then as in case
//     (b) I am not interactive enough to need cygwin console handling. Note
//     that if I was under mintty (etc) stdin and stdout would appear to
//     be attached to pipes rather than to a disk file.
//
// However if a command line flag "--cygwin" is provided I will make that
// force use of Cygwin. That use-case is required for people to use the
// "cuba" package on Windows because the Cuba-4.1 library is not available
// for and will not build for native Windows. If "--cygwin" is specified
// the code will only even attempt to run a GUI if DISPLAY is set, and in
// that case it will expect an X-windows server to be available for use.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h0 = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
    int t0 = GetFileType(h0),
        t1 = GetFileType(h1);
    int gcsbi = GetConsoleScreenBufferInfo(h1, &csbi);
    int force_cygwin = 0, dashdash = 0, i;
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--") == 0) dashdash = 1;
        else if (std::strcmp(argv[i], "--cygwin") == 0) force_cygwin = 1;
    }
    if (!force_cygwin &&
        (gcsbi ||              // console available: can use Windows API
         dashdash ||           // "--" seen: no console API needed
         t0==FILE_TYPE_DISK || // stdin or stdout disk: no console API needed
         t1==FILE_TYPE_DISK)) possibly_under_cygwin = 0;
//
// This stub runs as 32-bit code, but if it is on a 64-bit version of
// windows it will be running under "wow64". Checking for that should allow
// me to know if there is any prospect of running a 64-bit version of the
// application - and if I can then I should!
//
#ifdef FAT32
// I find it easier to have these variables present even when they are
// then not used. I rather expect that the C compiler will optimise away
// any potential code clumsiness.
    int wow64 = 0;
#else // FAT32
    int wow64 = IsWow64();

#ifdef DEBUG
// While debugging this code a "--32" on the command line disables 64 bit use.
// The only need for that that I can really see is when checking the code
// to verify that it works. But if somebody found a situation where it was
// valuable I could reinstate and publicise it.
    for (i=1; i<argc; i++)
    {   if (std::strcmp(argv[i], "--32") == 0)
        {   wow64 = 0;
        }
    }
#endif // DEBUG
#endif // FAT32

    int forcegui = 0;

#ifndef FATWIN
// The FATWIN case does not support cygwin at all...
    if (possibly_under_cygwin)
    {   int cygwin32 = 0;
// Here I want to execute cygwin_isatty.exe (and/or cygwin64_isatty.exe).
// There can not merely have their code incorporated here directly
// because they are cygwin programs and so their startup is rather
// different from this native windows code. I had at one stage tried
// loading the cygwin dlls by hand to start simulating the cygwin startup
// but I failed to make that work!
//
// The logic here is that cygwin_isatty checks if stdin and stdout (as seen in
// a cygwin context) are direct from the terminal. It appears hard to
// tell if this would be the case without running cygwin code. It will also
// test if cygwin is availlable at all (in that the helper program launched
// here will fail utterly if not - and that can sort out whether 32 or
// 64-bit cygwin is available).
// If stdin and stdout are attached to the tty and if also the environment
// variables DISPLAY and SSH_HOST are unset and the user did not put
// "--nogui" on the command line then even though I am under a cygwin console
// it looks as if I might run a windows GUI. I force that by adding "--gui"
// to the command line and run a windows (rather than cygwin) version.
// If stdin and stdout where attached to the tty otherwise I will use cygwin.
// If DISPLAY is set and "--nogui" is not present it will launch an X11
// windowed GUI, otherwise it will run in console mode.
// Finally either stdin or stdout has been redirected in the cygwin world,
// and since I will in effect be in batch mode I can drop back and use the
// windows binaries.
//
        int rc = -1;
#if defined FAT64 || defined FAT3264
        if (wow64) rc = RunResource(MODULE_ISATTY64, 0, "isatty64");
#endif // FAT64
#ifndef FAT64
        if (rc != 0)
        {   rc = RunResource(MODULE_ISATTY32, 0, "isatty32");
#if defined FAT3264
            if (rc == 0) cygwin32 = 1;
#endif // FAT3264
        }
#endif // FAT64
// If one of stdin or stdout is not connected to a cygwin console there is
// no point in trying to use cygwin at all. That is unless the user is
// explicitly forcing things. If the user specified "--cygwin" and does
// not launch from a context where cygwin1.dll and so on are available
// they need to expect failure.
        if (!force_cygwin && rc != 0) possibly_under_cygwin = 0;
// If DISPLAY and SSH_ENV are both null then I will look at the command
// line options... "--cygwin" trumps most other options.
        else if (std::getenv("DISPLAY") == nullptr &&
                 std::getenv("SSH_HOST") == nullptr &&
                 !force_cygwin)
        {   int nogui = 0;
// ... I look for "--nogui" (or the abbreviations "-w" or "-w-") ...
            for (i=1; i<argc; i++)
            {   if (std::strcmp(argv[i], "--nogui") == 0 ||
                    std::strcmp(argv[i], "-w") == 0 ||
                    std::strcmp(argv[i], "-w-") == 0)
                {   nogui = 1;
                    break;
                }
            }
// If there was NOT a "--nogui" then I will run a native windows
// version.
            if (nogui == 0)
            {   possibly_under_cygwin = 0;
                forcegui = 1;
            }
// Otherwise if I found cygwin32 rather than cygwin64 I must use that version.
            else if (cygwin32) wow64 = 0;
        }
// Here DISPLAY or SSH_HOST was set so I just have to choose which cygwin
// version to use.
        else if (cygwin32) wow64 = 0;
    }
#else
    possibly_under_cygwin = 0;
#endif // FATWIN
#ifdef DEBUG
    std::printf("Analysis yields wow64=%d cygwin=%d forcegui=%d\n",
                wow64, possibly_under_cygwin, forcegui);
#endif
//
// Now I will run the version of Reduce that I have picked. All the #ifdef
// stuff is to allow for smaller binaries that support only a subset of the
// cases.
//
    switch ((wow64<<4) | possibly_under_cygwin)
    {
#ifndef FAT64
        case 0x00:
            return RunResource(MODULE_WIN32, forcegui, "win32");
#endif
#ifndef FAT32
        case 0x10:
            return RunResource(MODULE_WIN64, forcegui, "win64");
#endif
#ifndef FATWIN
#ifndef FAT64
        case 0x01:
            rc = RunResource(MODULE_CYG32, forcegui, "cyg32");
            if (rc != 0)
            {   dllcheck(dll32);
            }
            return rc;
#endif
#ifndef FAT32
        case 0x11:
            rc = RunResource(MODULE_CYG64, forcegui, "cyg64");
            if (rc != 0)
            {   dllcheck(dll64);
            }
            return rc;
#endif // FAT32
#endif // FATWIN
        default:
            return 1;
    }
}

// End of newstub.cpp
