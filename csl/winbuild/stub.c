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

// $Id$



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

#elif defined FAT64

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
// and GetProcAddress to get a pointer to the function if available.
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

int RunResource(int index, int forcegui)
{
    FILE *src, *dest;
    int i;
    uint64_t hdr;
#ifdef DEBUG
    printf("RunFromResource %d %d\n", index, forcegui);
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
    if ((hdr = read8(src)) != 0x1234567887654321LL)
    {   printf("\n++++ leader read at %" PRIx64 "\n", hdr);
        return ERROR_BAD_LEADER;
    }
    for (i=0; i<NUMBER_OF_MODULES; i++)
    {   address[i] = read8(src);
        length[i] = read8(src);
#ifdef DEBUG
        printf("Module %d at %" PRIx64 " has length %"
               PRId64 " = %#" PRIx64 "\n",
               i, address[i], length[i], length[i]);
        fflush(stdout);
#endif
    }
    if ((hdr = read8(src)) != 0x8765432112345678LL)
    {   printf("\n++++ trailer read as %" PRIx64 "\n", hdr);
        return ERROR_BAD_TRAILER;
    }
    strcpy(pPath, ".\\acntmp.exe");
    dest = fopen(pPath, "wb");
    if (dest == NULL)
    {   printf("Failed to open %s for writing\n", pPath);
        return ERROR_UNABLE_TO_WRITE;
    }
    fseek(src, address[index], SEEK_SET);
    inf(src, dest, length[index]);
    fclose(src);
    fclose(dest);
    chmod(pPath, 0755);

    const char *cmd = GetCommandLine();
    char *cmd1 = (char *)malloc(strlen(cmd) + 12);
    if (cmd1 == NULL)
    {   printf("No memory for new command line\n"); fflush(stdout);
        return ERROR_NO_MEMORY;
    }
    strcpy(cmd1, cmd);
    if (forcegui) strcat(cmd1, " --gui");
    printf("About to run %s with args\n%s\n", pPath, cmd);
    STARTUPINFO peStartUpInformation;
    PROCESS_INFORMATION peProcessInformation;
    memset(&peStartUpInformation, 0, sizeof(STARTUPINFO));
    peStartUpInformation.cb = sizeof(STARTUPINFO);
    memset(&peProcessInformation, 0, sizeof(PROCESS_INFORMATION));
    printf("Launch <%s> cmd line <%s>\n", pPath, cmd1); fflush(stdout);
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
        printf("CreateProcess happened, rc reported as %d = %#x\n", rc, rc);
        fflush(stdout);
        CloseHandle(peProcessInformation.hProcess);
        CloseHandle(peProcessInformation.hThread);
        return rc;
    }
    else
    {   printf("CreateProcess failed\n"); fflush(stdout);
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
        return ERROR_CREATEPROCESS;
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

    int possibly_under_cygwin = 1;
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
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h0 = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
    int t0 = GetFileType(h0),
        t1 = GetFileType(h1);
    int gcsbi = GetConsoleScreenBufferInfo(h1, &csbi);
    int dashdash = 0, i;
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "--") == 0)
        {   dashdash = 1;
            break;
        }
    }
    if (gcsbi ||              // console available: can use Windows API
        dashdash ||           // "--" seen: no console API needed
        t0==FILE_TYPE_DISK || // stdin or stdout disk: no console API needed
        t1==FILE_TYPE_DISK) possibly_under_cygwin = 0;

    printf("possibly_under_cygwin = %d\n", possibly_under_cygwin); fflush(stdout);

//
// This stub runs as 32-bit code, but if it is on a 64-bit version of
// windows it will be running under "wow64". Checking for that should allow
// me to know if there is any prospect of running a 64-bit version of the
// application - and if I can then I should!
//
#ifdef FAT32
// I find it easier to have these variables present even when they are
// then not used. I rather expect that the C ocmpiler will optimise away
// any potential code clumsiness.
    int wow64 = 0;
#else // FAT32
    int wow64 = IsWow64();
    printf("wow64 = %d\n", wow64); fflush(stdout);

// While debugging this code a "-32" on the command line disables 64 bit use
// I will REMOVE this hack later on @@@@@@@@@@@@@@@@@@@@@@@
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "-32") == 0)
        {   wow64 = 0;
            printf("Disabling wow64 flag\n"); fflush(stdout);
        }
    }
#endif // FAT32

    int forcegui = 0;

#ifndef FATWIN
// The FATWIN case does not support cygwin at all...
    if (possibly_under_cygwin)
    {
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
#ifdef FAT64
        if (wow64)
        {   rc = RunResource(MODULE_ISATTY64, 0);
            printf("trying cygwin64_isatty yields %d = %#x\n", rc, rc); fflush(stdout);
        }
#endif // FAT64
        if (rc != 1)
        {   rc = RunResource(MODULE_ISATTY32, 0);
            printf("trying cygwin32_isatty yields %d = %#x\n", rc, rc); fflush(stdout);
#ifdef FAT64
            if (rc == 1) wow64 = 0;
#endif // FAT64
        }
        printf("cygwin_isatty(64/32) says %d = %.8x\n", rc, rc); fflush(stdout);
        switch (rc)
        {
        case 0:
            forcegui = 1;
        default:
            possibly_under_cygwin = 0;
        case 1:
            break;
        }
    }
#else
    possibly_under_cygwin = 0;
#endif // FATWIN

//
// Now I will run the version of Reduce that I have picked. All the #ifdef
// stuff is to allow for smaller binaries that support only a subset of the
// cases.
//
    switch ((wow64<<4) | possibly_under_cygwin)
    {
    case 0x00:
        printf("Attempt to use win32 version\n"); fflush(stdout);
        return RunResource(MODULE_WIN32, forcegui);
#ifndef FAT32
    case 0x10:
        printf("Attempt to use win64 version\n"); fflush(stdout);
        return RunResource(MODULE_WIN64, forcegui);
#endif
#ifndef FATWIN
    case 0x01:
        printf("Attempt to use cyg32 version\n"); fflush(stdout);
        return RunResource(MODULE_CYG32, forcegui);
#ifndef FAT32
    case 0x11:
        printf("Attempt to use cyg64 version\n"); fflush(stdout);
        return RunResource(MODULE_CYG64, forcegui);
#endif // FAT32
#endif // FATWIN
    default:
        printf("wow64=%d possibly_under_cygwin=%d forcegui=%d\n",
                wow64, possibly_under_cygwin, forcegui); fflush(stdout);
        return 1;
    }
}

// End of stub.c
