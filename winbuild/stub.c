// stub.c                                      Copyright A C Norman 2014
//

// The object of this code is to have several binaries embedded in it and
// it picks one, copies it to disc on a temporary file and from there
// it can execute it. It decides which to use based on whether it finds
// that the system being run on is 64-bit capable and whether it ought to
// use a cygwin version to interact with a cygwin console using unix-style
// calls to set raw mode and ncurses to move around the screen. It also
// takes a view as to when it should use a cygwin version so that although
// it is running on windows it can use an X11 display: it may do that
// if it finds the environment variable DISPLAY set or it discovers that it
// is being run on a windows host that is being accessed over ssh. When these
// special cases do not apply it will run a native windows version,
//
// An accompanying program "addresource.c" is used to add extra bodies
// of code to a compiled version of this.


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

// $Id: stub.c 2462 2014-03-26 20:48:39Z arthurcnorman $


// This should be compiled with one of the following symbols predefined:
//   FAT32    isatty32 w32 cyg32
//   FAT64    isatty32 isatty64 w32 w64 cyg32 cyg64
//   FATGUIDEMO  as FAT64 for now, but should only launch in gui mode
//   FATWIN   win32 win64


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <zlib.h>


//
// The compression parts of this code are modelled on.......
//
// zpipe.c: example of proper use of zlib's inflate() and deflate()
// Not copyrighted -- provided to the public domain
// Version 1.4  11 December 2005  Mark Adler
//

// Using a large buffer for decompression is expected to speed things
// up, so here I use 256 Kbytes.

#define CHUNK 0x40000

//
// Decompress from file source to file dest until stream ends or EOF.
// inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
// allocated for processing, Z_DATA_ERROR if the deflate data is
// invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
// the version of the library linked do not match, or Z_ERRNO if there
// is an error reading or writing the files.
//

int inf(FILE *source, FILE *dest, int length)
{
    int ret;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    // allocate inflate state
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK)
        return ret;

    // decompress until deflate stream ends or end of file or given
    // number of bytes have been written.
    do {
        strm.avail_in = fread(in, 1, CHUNK, source);
        if (ferror(source))
        {   (void)inflateEnd(&strm);
            return Z_ERRNO;
        }
        if (strm.avail_in == 0) break;
        strm.next_in = in;

        // run inflate() on input until output buffer not full
        do
        {   strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);
            assert(ret != Z_STREAM_ERROR);  // state not clobbered
            switch (ret)
            {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;     // and fall through
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                return ret;
            }
            have = CHUNK - strm.avail_out;
            if (have > length) have = length;
            if (fwrite(out, 1, have, dest) != have || ferror(dest))
            {   (void)inflateEnd(&strm);
                return Z_ERRNO;
            }
            length -= have;
            if (length == 0) break;
        } while (strm.avail_out == 0);

        // done when inflate() says it's done
    } while ((length != 0) && (ret != Z_STREAM_END));

    // clean up and return 
    (void)inflateEnd(&strm);
    return ret == (Z_STREAM_END && length == 0) ? Z_OK : Z_DATA_ERROR;
}


#if defined FAT32

// A fat 32 bit binary can be run under either native windows or
// 32-bit cygwin. Since it is a linked as a console mode application
// it is not suitable for launching by double-clicking. This is
// going to be usefully smaller than the FAT64 binary, but whether the
// space saving makes the extra complication of having this one available
// is yet to be determined!

#define NUMBER_OF_MODULES  3
#define MODULE_ISATTY32    0
#define MODULE_WIN32       1
#define MODULE_CYG32       2

#elif defined FAT64 || defined FATGUIDEMO

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
// is not useful for launching from a console - but it is good for
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
{
    BOOL bIsWow64 = FALSE;
// IsWow64Process is not available on all supported versions of Windows.
// Use GetModuleHandle to get a handle to the DLL that contains the function
// and GetProcAddress to get a pointer to the function if available. Well
// probably these days it is always available on operating systems that matter,
// but the hack here is fairly simple and local so to be kind to the
// historical world I will preserve it for a while!
    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");
    if(NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {   //handle error - well heer I just return "no"
            return FALSE;
        }
    }
    return bIsWow64;
}

#endif // FAT32

static int64_t read8(FILE *f)
{
    int64_t r = 0;
    int i;
    for (i=0; i<8; i++)
    {   int w = getc(f) & 0xff;
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
{
    FILE *src, *dest;
    int i;
    uint64_t hdr;
#ifdef DEBUG
    printf("RunResource %s: %d %d\n", modulename, index, forcegui);
    fflush(stdout);
#endif
    GetModuleFileName(NULL, pPath, sizeof(pPath));
#ifdef DEBUG
    printf("my name is %s\n", pPath);
    fflush(stdout);
#endif
    src = fopen(pPath, "rb");
    if (src == NULL) return ERROR_UNABLE_TO_OPEN_SELF;
    fseek(src, -16*(NUMBER_OF_MODULES+1), SEEK_END);
// The way I put "resources" in a file puts a header word before
// a table and a trailer word after it. These form some sort of
// signature to confirm that the file is in a good state. If either
// is not found I exit.
    if ((hdr = read8(src)) != 0x1234567887654321LL)
        return ERROR_BAD_LEADER;
    for (i=0; i<NUMBER_OF_MODULES; i++)
    {   address[i] = read8(src);
        length[i] = read8(src);
#ifdef DEBUG_SHOW_MODULES
        printf("Module %d at %" PRIx64 " has length %"
               PRId64 " = %#" PRIx64 "\n",
               i, address[i], length[i], length[i]);
        fflush(stdout);
#endif
    }
    if ((hdr = read8(src)) != 0x8765432112345678LL)
        return ERROR_BAD_TRAILER;
// Now I want a temporary file that I can put the unpacked executable
// into. Note that GetTempPath() will not guarantee that the directory
// it points me to is writable! In case of trouble I fall back to creating
// the temporary files that I need in whatever is the current directory.
//
// One thing that concerns me here is the possibility that some antivirus
// programs might object to attempts to launch executables out of a
// temporary directory... sufficiently agressive behaviour of that kind
// could cause real misery to me here. I have McAfee running on my
// Windows machine and seem to be OK...
//
    DWORD path = GetTempPath(sizeof(pPath), pPath);
    if (path ==0 || path > sizeof(pPath)-14)
        strcpy(pPath, ".\\"); // Try to use currect directory
// Now pPath holds a directory, with a "\" character at the end...
//
// I can not use most of the functions I would like to to create the
// file name because most do not allow me to specify a suffix, and I
// would like the name to be "something.exe". So I do it all myself.
    DWORD myid = GetProcessId(GetCurrentProcess());
    SYSTEMTIME t0;
    GetSystemTime(&t0);
// Here I create a number that depends on the date and time of day as
// well as on my process number. Using this in the generated file name
// can not guarantee to avoid clashes. but it will at least help.
    int k = (t0.wMilliseconds + 1000*t0.wSecond) +
            314159*(int)time(NULL) +
            2718281*(int)myid;
    char *fname = pPath + strlen(pPath);
// I will try ten times in the temporary directory found above, and if
// all those attempts fail I will try another 10 times in the current
// directory. If all those fail I will give up.
    int tries = 0;
    for (;;k=69069*k+1, tries++)
    {   if (tries == 10)
        {   strcpy(pPath, ".\\");
            fname = pPath + strlen(pPath);
        }
        else if (tries == 20) return ERROR_NO_TEMP_FILE;
// The file-name I create is in the form "Txxxxxxx.exe" with 7 hex digits
// in place of the "x" characters. If my first attempt fails I will
// make my next probe increases the hex constant in the spirit of a 32-bit
// linear congruential pseudo-random sequence in the expectation that that
// would tend to reduce clustering. That really ought not to matter!
        sprintf(fname, "T%.7x.exe", k & 0xfffffff);
// This use of CreateFile arranges that the file opened is guaranteed
// to be new. This is just what I want.
        HANDLE h = CreateFile(
            pPath,                 // name
            GENERIC_WRITE,         // access
            0,                     // shared
            NULL,                  // security attributes
            CREATE_NEW,            // creation disposition
            FILE_ATTRIBUTE_NORMAL, // flags & attributes
            NULL);                 // template file
        if (h == INVALID_HANDLE_VALUE) continue;
// I want to write to the file using a C style FILE object so I convert
// from a Windows handle to one of those - in two steps.
        int ch = _open_osfhandle((intptr_t)h, 0);
        if (ch == -1)
        {   CloseHandle(h);
            DeleteFile(pPath);
            continue;
        }
        dest = fdopen(ch, "wb");
        if (dest == NULL)
        {   close(ch);
            DeleteFile(pPath);
            continue;
        }
        break;
    }
#ifdef DEBUG
    printf("File will be <%s>\n", pPath);
#endif
    fseek(src, address[index], SEEK_SET);
// Decompress the relevant resource into the new file.
    inf(src, dest, length[index]);
    fclose(src);
    fclose(dest);
    chmod(pPath, 0755); // Make executable

    const char *cmd = GetCommandLine();
    char *cmd1 = (char *)malloc(strlen(cmd) + 12);
    if (cmd1 == NULL)
    {   printf("No memory for new command line\n"); fflush(stdout);
        DeleteFile(pPath);
        return ERROR_NO_MEMORY;
    }
    strcpy(cmd1, cmd);
//
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
//
    if (forcegui) strcat(cmd1, " --gui");

    STARTUPINFO peStartUpInformation;
    PROCESS_INFORMATION peProcessInformation;
    memset(&peStartUpInformation, 0, sizeof(STARTUPINFO));
    peStartUpInformation.cb = sizeof(STARTUPINFO);
    memset(&peProcessInformation, 0, sizeof(PROCESS_INFORMATION));
#ifdef DEBUG
    printf("Launch <%s> cmd line <%s>\n", pPath, cmd1); fflush(stdout);
#endif
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
//  _set_abort_behavior(0,_WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    if (CreateProcessA(pPath,            // appname
                       cmd1,             // command line
                       NULL,             // process attributes
                       NULL,             // thread attributes
                       1,                // inherits handles
                       0,                // allow it to run now
                       NULL,             // environment
                       NULL,             // current directory
                       &peStartUpInformation,
                       &peProcessInformation))
    {   WaitForSingleObject(peProcessInformation.hProcess, INFINITE);
        DWORD rc;
        if (GetExitCodeProcess(peProcessInformation.hProcess, &rc) == 0)
            rc = ERROR_PROCESS_INFO; // Getting the return code failed!
#ifdef DEBUG
        printf("CreateProcess happened, rc reported as %d = %#x\n", rc, rc);
#endif
        fflush(stdout);
        CloseHandle(peProcessInformation.hProcess);
        CloseHandle(peProcessInformation.hThread);
        DeleteFile(pPath);
        return rc;
    }
    else
    {
#ifdef DEBUG
        printf("CreateProcess failed\n"); fflush(stdout);
        DWORD dw = GetLastError();
        LPVOID lpMsgBuf;
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                      FORMAT_MESSAGE_FROM_SYSTEM |
                      FORMAT_MESSAGE_IGNORE_INSERTS,
                      NULL,
                      dw,
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      (LPSTR)&lpMsgBuf,
                      0,
                      NULL);
        printf("CreateProcess failed (%d): %s\n", dw, lpMsgBuf);
        fflush(stdout);
#endif
        DeleteFile(pPath);
        return ERROR_CREATEPROCESS;
    }
}
    
static const char *dll32[] =
{
#include "dll32.c"
    NULL
};

static const char *dll64[] =
{
#include "dll64.c"
    NULL
};

#include <windows.h>
#include <stdio.h>

void dllcheck(const char **table)
{
    int i, messaged = 0;
    for (i=0; table[i]!=NULL; i++)
    {   HMODULE h = LoadLibraryEx(table[i], NULL, DONT_RESOLVE_DLL_REFERENCES);
        if (h == NULL)
        {   if (!messaged)
            {   printf("\nCygwin needs at least %s", table[i]);
                messaged = 3;
            }
            else if (messaged >= 5)
            {   printf(",\n  %s", table[1]);
                messaged = 1;
            }
            else
            {   printf(", %s", table[i]);
                messaged++;
            }
        }
        else FreeLibrary(h);
    }
    if (messaged)
    {   printf("\n");
        printf("Please run cygwin setup and install packages that will\n");
        printf("provide these. Then try again.\n\n");
        fflush(stdout);
    }
}

int main(int argc, char* argv[])
{
//
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
    {   if (strcmp(argv[i], "--") == 0) dashdash = 1;
        else if (strcmp(argv[i], "--cygwin") == 0) force_cygwin = 1;
    }
    if (!force_cywgin &&
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
    {   if (strcmp(argv[i], "--32") == 0)
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
#if defined FAT64 || defined FATGUIDEMO
        if (wow64) rc = RunResource(MODULE_ISATTY64, 0, "isatty64");
#endif // FAT64
        if (rc != 0)
        {   rc = RunResource(MODULE_ISATTY32, 0, "isatty32");
#if defined FAT64 || defined FATGUIDEMO
            if (rc == 0) cygwin32 = 1;
#endif // FAT64
        }
// If one of stdin or stdout is not connected to a cygwin console there is
// no point in trying to use cygwin at all. That is unless the user is
// explicitly forcing things. If the user specified "--cygwin" and does
// not launch from a context where cygwin1.dll and so on are available
// they need to expect failure.
        if (!force_cygwin && rc != 0) possibly_under_cygwin = 0;
// If DISPLAY and SSH_ENV are both null then I will look at the command
// line options... "--cygwin" trumps most other options.
        else if (getenv("DISPLAY") == NULL &&
                 getenv("SSH_HOST") == NULL &&
                 !force_cygwin)
        {   int nogui = 0;
// ... I look for "--nogui" (or the abbreviations "-w" or "-w-") ...
            for (i=1; i<argc; i++)
            {   if (strcmp(argv[i], "--nogui") == 0 ||
                    strcmp(argv[i], "-w") == 0 ||
                    strcmp(argv[i], "-w-") == 0)
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
    printf("Analysis yields wow64=%d cygwin=%d forcegui=%d\n",
           wow64, possibly_under_cygwin, forcegui);
#endif
//
// Now I will run the version of Reduce that I have picked. All the #ifdef
// stuff is to allow for smaller binaries that support only a subset of the
// cases.
//
    switch ((wow64<<4) | possibly_under_cygwin)
    {
    case 0x00:
        return RunResource(MODULE_WIN32, forcegui, "win32");
#ifndef FAT32
    case 0x10:
        return RunResource(MODULE_WIN64, forcegui, "win64");
#endif
#ifndef FATWIN
    case 0x01:
        rc = RunResource(MODULE_CYG32, forcegui, "cyg32");
        if (rc != 0)
        {   dllcheck(dll32);
        }
        return rc;
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

// End of stub.c
