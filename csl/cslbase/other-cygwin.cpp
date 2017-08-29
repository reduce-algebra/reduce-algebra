// other-cygwin.cpp                     Copyright (C) A C Norman  2014-2017

//
// This program is to be run from a DOS command prompt or any cygwin
// shell, and it "changes gear" so that the command that it is
// given as its arguments is run in a full cygwin context.
// It should always run its target in the version of cygwin it is
// nor run from - ie if launched from a 32-bit terminal it will
// run a 64-bit application and vice versa.
// Note that for good behaviour in such usage that mixes 32 and 64-bit
// cygwin working it will be important that file systems map so that
// relevant files appear in consistent places from both 32 and 64-bit
// worlds. This may be easiest if paths are fully rooted and so always
// start /cygdrive/x/...
// In particular BEWARE of home directories!
//
// You must compile this with i686-w64-mingw32-gc++. This now requires that
// the 32 and 64-bit versions of cygwin have been installed in c:\cygwin and
// c:\cygwin64.
//
// If compiled with "-DFORCE32" or "-DFORCE64" it will only change gear
// if not in the context suggested...


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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <tlhelp32.h>
#include <unistd.h>
#include <process.h>

static bool run64;

#define scygwin (run64 ? "c:\\cygwin64" : "c:\\cygwin")

#define LONGEST_COMMAND 4096

static char command[LONGEST_COMMAND];

// I keep this as a separate function in case I need to insert extra
// escape characters at any stage...
void append_command(char *s)
{   strcat(command, s);
}

// The following code was found in newsgroup postings, and I believe it was
// intended to be available for re-use.

// Find a process with a given id in a snapshot
BOOL FindProcessID(HANDLE snap, DWORD id, LPPROCESSENTRY32 ppe)
{
  BOOL res;
  ppe->dwSize = sizeof(PROCESSENTRY32); // (mandatory)
  res = Process32First(snap, ppe);
  while (res) {
    if (ppe->th32ProcessID == id) {
      return TRUE;
    }
    res = Process32Next(snap, ppe);
  }
  return FALSE;
}

// Get the parent process id of the current process
BOOL GetParentProcessId(DWORD* parent_process_id)
{
  HANDLE hSnap;
  PROCESSENTRY32 pe;
  DWORD current_pid = GetCurrentProcessId();

  // Take a snapshot of all Windows processes
  hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (INVALID_HANDLE_VALUE == hSnap) {
    return FALSE;
  }

  // Find the current process in the snapshot
  if (!FindProcessID(hSnap, current_pid, &pe)) {
    return FALSE;
  }

  // Close the snapshot
  if (!CloseHandle(hSnap)) {
    return FALSE;
  }

  *parent_process_id = pe.th32ParentProcessID;
  return TRUE;
}

int main(int argc, char *argv[])
{
    run64 = false;
    DWORD parent;
    if (!GetParentProcessId(&parent))
    {   printf("Parent process not found\n");
        return 1;
    }
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION|
                           PROCESS_QUERY_LIMITED_INFORMATION,
                           TRUE,
                           parent);
    BOOL b;
    if (IsWow64Process(h, &b) == 0)
    {   printf("isWow64Process() failed\n");
        return 1;
    }
    if (b)
    {   // printf("parent is a 32-bit application via Wow64\n");
        run64 = true;
    }
    else
    {   SYSTEM_INFO s;
        GetNativeSystemInfo(&s);
        switch (s.wProcessorArchitecture)
        {
        case PROCESSOR_ARCHITECTURE_AMD64:
            // printf("parent is a 64-bit process\n");
            run64 = false;
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
#ifndef FORCE32
            printf("You seem to be running 32-bit operating system\n");
            printf("This utility can not work. Exiting\n");
            return 1;
#else
            break;
#endif
        default:
            printf("Unknown platform: exiting.\n");
            return 1;
        }
    }

// At this stage run64 is set to indicate the opposite of the shell currently
// in use.

#if defined FORCE64
    run64 = true;
#elif defined FORCE32
    run64 = false;
#endif

    STARTUPINFO startup;
    PROCESS_INFORMATION process;
    char *current;
    const char *user;
    char newenv[1024];
    int dirsize, i, rc;
    memset((void *)&startup, 0, sizeof(startup));
    memset((void *)&process, 0, sizeof(process));
    startup.cb = sizeof(startup);
// Passing STD_OUTPUT etc down seems to behave well when I am under mintty
// or an xterm, but if I am running in a Windows console (eg as in the
// earlier way that cygwin was set up) this is a mess in that output
// does not appear on my console. I can go
//    cyg64 "whoami > xxx"
// and the information ends up in the file xxx in the way it should, so
// this is perhaps a case where I need to create a pipe to pass down
// as each of stdout and stderr. Once I have launched the program I then need
// to read from both of those and transfer anything I get back to my own
// standard outputs. It also seems that STD_INPUT is passed OK here if it is
// a pipe, but not if it is interactive... Ah well maybe this is still good
// enough for IMMEDIATE purposes even without the upgrades needed to sort
// out the problems described here! But please be aware that some output can
// get misdirected along the way!
    startup.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    startup.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    startup.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    startup.wShowWindow = SW_HIDE;
    startup.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
// Now set up a command line
    dirsize = GetCurrentDirectory(0, NULL);
    current = (char *)malloc(dirsize+4);
    rc = GetCurrentDirectory(dirsize, current);
    if (rc > dirsize)
    {   printf("Getting directory failed\n");
        return 1;
    }
// Under cygwin the shell variable USER gives the effective user name. A
// second variable USERNAME holds the name of the user that Windows believes
// is active: eg when I am linked in over ssh that may be "cyg_server".
// If I fail to read USER I will default to the name "unknown".
    user = getenv("USER");
    if (user == NULL) user = "unknown";
    memset(newenv, 0, sizeof(newenv));
    if (run64)
        sprintf(newenv, "OTHER=yes%cUSER=%s%cPATH=/cygdrive/c/cygwin64/bin%c", 0, user, 0, 0);
    else
        sprintf(newenv, "OTHER=yes%cUSER=%s%cPATH=/cygdrive/c/cygwin/bin%c", 0, user, 0, 0);
    for (i=0; i<dirsize; i++)
        if (current[i] == '\\') current[i] = '/';
    sprintf(command,
        "%s\\%s\\cmd /c \"%s\\bin\\bash --login -c \'cd ",
        getenv("WINDIR"), run64 ? "sysnative" : "system32", scygwin);
    append_command(current);
    strcat(command, " ; ");
    for (i=1; i<argc; i++)
    {   append_command(argv[i]);
        strcat(command, " ");
    }
    strcat(command, "\'\"");
//  printf("Command is <%s>\n", command); fflush(stdout);
    char newdir[1024];
    sprintf(newdir, "%s\\bin", scygwin);
    rc = CreateProcess(
             NULL,                       // ApplicationName
             command,                    // Command line
             NULL,                       // Process attributes
             NULL,                       // Security attributes
             1,                          // Inherit handles?
             CREATE_NEW_CONSOLE,         // Process creation flags
             newenv,                     // environment
             newdir,                     // Current Directory
             &startup,                   // Startup Info
             &process);                  // process info
    if (rc == 0)
    {   printf("Process creation failed\n");
        return 1;
    }
    WaitForSingleObject(process.hThread, INFINITE);
    WaitForSingleObject(process.hProcess, INFINITE);
    FlushFileBuffers(startup.hStdOutput);
    FlushFileBuffers(startup.hStdError);
    CloseHandle(startup.hStdInput);
    CloseHandle(startup.hStdOutput);
    CloseHandle(startup.hStdError);
    CloseHandle(process.hProcess);
    CloseHandle(process.hThread);
    return 0;
}

// end of other-cygwin.cpp
