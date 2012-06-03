/* not-under-cygwin.c                   Copyright (C) 2012 Codemist Ltd */


/**************************************************************************
 * Copyright (C) 2012, Codemist Ltd.                     A C Norman       *
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

/* Signature: 6d218672 03-Jun-2012 */

#include <windows.h>

/*
 * The purpose of this tiny program is to return (as an error-code)
 * information as to whether it is being run in a context where things
 * have access to a console. This will NOT be the case if the coded is
 * run from mintty (the current cygwin terminal), a cygwin X terminal or
 * via ssh into a cygwin version of sshd. It also returns "true" if either
 * input or output is connected to a disc file, since in that case the
 * run is (probably) non-interactive and so terminal handling is not
 * an issue. Finally it also reports on the presence of a command-line
 * option "--", which is used here to redirect the standard output.
 * It is used from shell scripts (only under Windows) to decide which
 * version of Reduce should be
 * launched.
 */

int main(int argc, char *argv[])
{
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
/*
 * Here I need to return 0 for "true" and non-zero for "false", since
 * a return code of zero stands for "success".
 */
    return (gcsbi ||              /* console available: can use Windows API */
            dashdash ||           /* stdout redirected: no API needed */
            t0==FILE_TYPE_DISK || /* stdin or stdout disk: no API needed */
            t1==FILE_TYPE_DISK) ? 0 : 1;
}

