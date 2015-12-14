// cyg64.cpp                                Copyright (C) A C Norman  2014

//
// This program is to be run from a DOS command prompt or any cygwin
// shell, and it "changes gear" so that the command that it is
// given as its arguments is run in a full cygwin context. Depending on
// how it is compiled that may be either a 32-bit or 64-bit cygwin world.
// A special use of this is that it makes it possible to run 64 bit
// cygwin applications from a 32-bit world or vice versa. Note that for
// good behaviour in such usage that mixes 32 and 64-bit cygwin working
// it will be important that file systems map so that relevant files appear
// in consistent places from both 32 and 64-bit worlds. This may be easiest
// if paths are fully rooted and so always start /cygdrive/x/...
//
// You must compile this with i686-w64-mingw32-gcc and should provide
// a command line option -Dcygwin=c:/cygwin64 (or whatever path is
// relevent) to identify where on your own computer the 32 or 64-bit
// version of cygwin that you want used has been installed.
//


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
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#ifdef cygwin
#  define stringify(x) #x
#  define stringify1(x) stringify(x)
#  define scygwin stringify1(cygwin)
#else
#  define scygwin "c:\\cygwin"
#endif

#define LONGEST_COMMAND 4096

static char command[LONGEST_COMMAND];

// I keep this as a separate function in case I need to insert extra
// escape characters at any stage...
void append_command(char *s)
{   strcat(command, s);
}

int main(int argc, char *argv[])
{   STARTUPINFO startup;
    PROCESS_INFORMATION process;
    char *current;
    const char *user;
    char newenv[64];
    int dirsize, i, rc;
    memset((void *)&startup, 0, sizeof(startup));
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
// out the problems described here!
    startup.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    startup.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    startup.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    startup.wShowWindow = SW_HIDE;
    startup.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    memset((void *)&process, 0, sizeof(process));
// Now set up a command line
    dirsize = GetCurrentDirectory(0, NULL);
    current = (char *)malloc(dirsize);
    rc = GetCurrentDirectory(dirsize, current);
    if (rc > dirsize)
    {   printf("Getting directory failed\n");
        return;
    }
// Under cygwin the shell variable USER gives the effective user name. A
// second variable USERNAME holds the name of the user that Windows believes
// is active: eg when I am linked in over ssh that may be "cyg_server".
// If I fail to read USER I will default to the name "unknown".
    user = getenv("USER");
    if (user == NULL) user = "unknown";
    memset(newenv, 0, sizeof(newenv));
    sprintf(newenv, "USER=%s", user);
    for (i=0; i<dirsize; i++)
        if (current[i] == '\\') current[i] = '/';
    sprintf(command, "%s\\bin\\bash --login -c \"cd ", scygwin);
    append_command(current);
    strcat(command, " ; ");
    for (i=1; i<argc; i++)
    {   append_command(argv[i]);
        strcat(command, " ");
    }
    strcat(command, "\"");
//  printf("Command is <%s>", command);
    rc = CreateProcess(
             NULL,                       // ApplicationName
             command,                    // Command line
             NULL,                       // Process attributes
             NULL,                       // Security attributes
             1,                          // Inherit handles?
             CREATE_NEW_CONSOLE,         // Process creation flags
             newenv,                     // environment
             scygwin "\\bin",            // Current Directory
             &startup,                   // Startup Info
             &process);                  // process info
    if (rc == 0)
    {   printf("Process creation failed\n");
        return;
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
