// stub2020.c                                 Copyright (C) A C Norman 2020


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

// $Id: newstub.c 2462 2014-03-26 20:48:39Z arthurcnorman $




//
// The purpose of this program is to decide whether CSL/Reduce should
// run as a Cygwin or a Native Windows program. It also wants to help
// me sort out as between 32- and 64-bit variants of each.
//
// When compiling it you must define NAME to be the name of the eventual
// target.
//
// So some fundamentals first:
// This must be compiled using
//    i686-w64-mingw32-gcc -static -DNAME=xxx ...
// where the "-static" is needed so that this is sufficiently self contained,
// and it is a 32-bit executable so it will run on both 32 and 64-bit versions
// of Windows. I had tried a version of this built using g++ not gcc but the
// C++ libraries that got sucked in made the executable unreasonably large.
//
// If compiled with NO_32_BIT defined it will only support 64-bit cases
// and should be built using x86_64-w64-mingw32-gcc
// With NO_CYGWIN it will not support the Cygwin variants. If you defined
// both at once you would get something that was pretty pointless because
// it would always just chain to the 64-bit Windows binary!


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ERROR_NO_MEMORY            84
#define ERROR_PROCESS_INFO         85
#define ERROR_CREATEPROCESS        86

#define str(x) stringify(x)
#define stringify(x) #x

// runResource executes a program from the reduce.resources directory
// and gives back its return code. It sticks "extra" as an additional forced
// first argument on the command line (if extra!=NULL).

int runResource(const char *modulename, const char *extra)
{
#ifdef DEBUG
    printf("runResource %s %s\n", modulename, extra==NULL ? "" : extra);
#endif
// If this program is $P/XXX.exe then I want to look in the directory
// $P/reduce.resources for the program I am to run. So first I need to
// find out what $P is.
    char pPath[MAX_PATH];
    GetModuleFileName(NULL, pPath, sizeof(pPath));
#ifdef DEBUG
    printf("my name is %s\n", pPath);
#endif
    char modPath[MAX_PATH];
    strcpy(modPath, pPath);
    char *lastsep = strrchr(modPath, '\\');
    sprintf(lastsep, "\\reduce.resources\\%s.exe", modulename);
#ifdef DEBUG
    printf("Code to run %s\n", modPath);
#endif
// I will pass my own command line down to the program that I execute.
    const char *cmd = GetCommandLine();
#ifdef DEBUG
    printf("GetCommandLine returns <%s>\n", cmd);
#endif
    char *cmd1 = (char *)malloc(strlen(cmd) + strlen(pPath) + 12);
    if (cmd1 == NULL)
    {   printf("No memory for new command line\n"); fflush(stdout);
        return ERROR_NO_MEMORY;
    }
// I am going to put my own fully-rooted path at the start of the command-
// line. I enclose it in quotes in case it might have embedded white-space.
// First strip off the existing start...
    if (*cmd == '"')
    {   cmd++;
        while (cmd!=0 && *cmd!='"') cmd++;
        if (*cmd!=0) cmd++;
    }
    else
    {   while (*cmd!=0 && *cmd!=' ') cmd++;
    }
    if (extra == NULL) extra = "";
    if (pPath[0] == '"') sprintf(cmd1, "%s %s %s", pPath, extra, cmd);
    else sprintf(cmd1, "\"%s\" %s %s", pPath, extra, cmd);
    STARTUPINFO peStartUpInformation;
    PROCESS_INFORMATION peProcessInformation;
    memset(&peStartUpInformation, 0, sizeof(STARTUPINFO));
    peStartUpInformation.cb = sizeof(STARTUPINFO);
    memset(&peProcessInformation, 0, sizeof(PROCESS_INFORMATION));
#ifdef DEBUG
    printf("Launch <%s> cmd line <%s>\n", modPath, cmd1); fflush(stdout);
#endif
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
//  _set_abort_behavior(0,_WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    if (CreateProcessA(modPath,          // appname to launch
                       cmd1,             // command line
                       NULL,             // process attributes
                       NULL,             // thread attributes
                       1,                // inherits handles
                       0,                // allow it to run now
                       NULL,             // environment
                       NULL,             // current directory
                       &peStartUpInformation,
                       &peProcessInformation))
    {
// If the sub-task is successfully started I will want to wait until it
// terminates and then recover its exit code.
        WaitForSingleObject(peProcessInformation.hProcess, INFINITE);
        DWORD rc;
        if (GetExitCodeProcess(peProcessInformation.hProcess, &rc) == 0)
            rc = ERROR_PROCESS_INFO; // Getting the return code failed!
#ifdef DEBUG
        printf("CreateProcess happened, rc reported as %d = %#x\n", rc, rc);
#endif
        fflush(stdout);
        CloseHandle(peProcessInformation.hProcess);
        CloseHandle(peProcessInformation.hThread);
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
        return ERROR_CREATEPROCESS;
    }
}
    
#ifndef NO_CYGWIN

static const char *dll64[] =
{
// "dll64.c" has been created by a bit of script that starts
//    objdump -p reduce.exe | grep DLL | sed ...
// to build a list of all the DLLs mentioned by reduce.exe, each as
// a string with a comma at the end of the line. I need the NULL here to
// follow on from the final comma.
#include "dll64.c"
    NULL
};

#ifndef NO_32_BIT

const char *dll32[] =
{
// "dll32.c" has been created by a bit of script that starts
//    objdump -p reduce.exe | grep DLL | sed ...
// to build a list of all the DLLs mentioned by reduce.exe, each as
// a string with a comma at the end of the line. I need the NULL here to
// follow on from the final comma.
#include "dll32.c"
    NULL
};

#endif // NO_32_BIT

// This reads a DLL and checks its headers to verify the architecture
// it had been created for.

int PEcheck(FILE *f, int width)
{   unsigned char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    size_t len = fread(buffer, 1, sizeof(buffer), f);
    if (len < sizeof(struct _IMAGE_DOS_HEADER)) return 0;
    LONG pe = ((struct _IMAGE_DOS_HEADER *)buffer)->e_lfanew;
#ifdef DEBUG
    printf("Offset of PE header is %d = %#x\n", pe, pe);
#endif
    if (len < pe+6) return 0;
    unsigned int mc = *(uint16_t *)&buffer[pe+4];
#ifdef DEBUG
    printf("Machine type given as %#x\n", mc);
#endif
    return width==32 ?
        (mc==IMAGE_FILE_MACHINE_I386) :
        (mc==IMAGE_FILE_MACHINE_AMD64);
}

const char *PATH=NULL;

int dllcheck(const char *name, int width)
{   if (PATH == NULL) PATH = getenv("PATH");
// D1 ; D2 ; ...
// where each directory D is given without a trailing "\"
    int i=0, j=0;
    for (;;)
    {   while (PATH[j] != 0 && PATH[j] != ';') j++;
        char location[MAX_PATH];
        sprintf(location, "%.*s\\%s", j-i, &PATH[i], name);
#ifdef DEBUG
        printf("Check |%s|\n", location);
#endif
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {   int res = PEcheck(f, width);
            fclose(f);
            return res;
        }
        if (PATH[j] == 0) return 0;
        i = j = j+1;
    }
}

int cygcheck(const char *dlls[], int width)
{   if (dllcheck("cygwin1.dll", width) == 0) return 0;
    for (int i=0; dlls[i] != 0; i++)
        if (strcmp(dlls[i], "cygwin1.dll") != 0 &&
            dllcheck(dlls[i], width) == 0) return 0;
    return 1;
}

#endif // NO_CYGWIN

#ifndef NO_32_BIT

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
        {   //handle error - well here I just return "no"
            return FALSE;
        }
    }
    return bIsWow64;
}

#endif // NO_32_BIT

// Run either the 32-bit Windows binary or the 64-bit one. If the regular
// name if the program is XXX then this launches wither XXXwin32 or
// XXXwin64. The names I will in fact use are "boot", "wboot, "red" and
// "wred" and I should probably include "csl" and "wcsl".

int runWindows(const char *extra)
{
#ifdef NO_32_BIT
    return runResource(str(NAME) "win64", extra);
#else // NO_32_BIT
// This stub runs as 32-bit code, but if it is on a 64-bit version of
// windows it will be running under "Wow64". Checking for that should allow
// me to know if there is any prospect of running a 64-bit version of the
// application - and if I can then I should!
//
    if (IsWow64()) return runResource(str(NAME) "win64", extra);
    else return runResource(str(NAME) "win32", extra);
#endif // NO_32_BIT
}

int main(int argc, char *argv[])
{
#ifndef NO_CYGWIN
// I expect that if I have been invoked from a Unix-like shell rather than
// either from a DOS prompt (including the Windows Powershell) that
// environment variables TERM and SHELL will both be set. So if either of
// those is NOT set I should just use a Native Windows version.
    if (getenv("TERM") == NULL ||
        getenv("SHELL") == NULL) return runWindows(NULL);
// Now (unless DISPLAY is set, in which case I might want to use X11) if
// I have not forced use of a console mode version using "-w, -w- or --nogui
// I will also use a Windows binary. This will include cases where there
// has been redirection of the standard input or output.
    if (getenv("DISPLAY") == NULL)
    {   int nogui = 0;
        for (int i=1; i<argc; i++)
        {   if (strcmp(argv[i], "-w") == 0 ||
                strcmp(argv[i], "-w-") == 0 ||
                strcmp(argv[i], "--nogui") == 0)
            {   nogui = 1;
                break;
            }
        }
// Well as an extra complication I will check if I am in a session that
// is running over ssh. The SSH_CLIENT environment variable is set up by
// openssh in such cases. Then rather than letting a lack of "-w" allow
// me to use a Windows GUI I am liable to want to use Cygwin, so I treat
// running under ssh but without DISPLAY set as much the same as having
// ased for --nogui.
        if (getenv("SSH_CLIENT") != 0) nogui = 1;
        if (nogui == 0) return runWindows(NULL);
    }
// Here I will use a Cygwin version if it is available.
#ifdef NO_32_BIT
    if (cygcheck(dll64, 64)) return runResource(str(NAME) "cyg64", NULL);
#else // NO_32_BIT
// This has to involve considering both 32 and 64-bit cygwin if I am
// on a 64-bit platform or just the 32-bit one if on a 32-bit machine.
    int cygwin;
    if (IsWow64() && cygcheck(dll64, 64))
        return runResource(str(NAME) "cyg64", NULL);
    else if (cygcheck(dll32, 32))
        return runResource(str(NAME) "cyg32", NULL);
#endif // NO_32_BIT
#endif // NO_CYGWIN
    return runWindows(NULL);
}

// end of stub2020.c
