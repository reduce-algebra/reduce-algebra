/* cygwin-isatty.c                       Copyright (C) 2015 Codemist Ltd */


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * The purpose of this tiny program is to return (as an error-code)
 * information as to whether stdin and stdout satisfy the "isatty" test.
 * This will be built as a cygwin application and so being a "tty" really
 * means that the cygwin calls the manage ttys (eg set raw mode etc) are
 * available. There is a complication in that as of mid 2013 there are
 * both 32 and 64-bit variants on cygwin and at least initially their
 * treatment of console streams differ, so a version of this built for
 * 64-bit cygwin will, when run under the 32-bit cygwin version of mintty,
 * return an error code 127. It is possible - even probable - that later
 * updates to the two varients of cygwin will make their stdio streams
 * more compatible with one another, and then it will be necessary to
 * review the tests here.
 */

/*
 * ./cygwin-isatty.exe
 * case $? in
 * 0)
 *   echo User did not specify "--nogui" and stdio is from console
 *   echo not redirected. We are also not under X11 or via SSH, so
 *   echo force use of a native Windows application running in GUI mode.
 *   ;;
 * 1)
 *   echo stdio streams are attached to console, and here either the
 *   echo user has requested no GUI or is liable to need an X11 one.
 *   ;;
 * 2)
 *   echo at least one of the stdio streams has been redirected or
 *   echo comes via a pipe, so I will not be running in interactive
 *   echo mode. Use a native Windows application, which will launch
 *   echo without a GUI in this case.
 *   ;;
 * *)
 *   echo a return code of 127 arises if you go "./no-file-here.exe; echo $?"
 *   echo and also if you run a 64-bit cygwin version of cygwin-isatty from
 *   echo a 32-bit cygwin shell.
 *   ;;
 * esac
 *
 * Note that since this is a cygwin program it can only be loaded if you are
 * running with the cygwin dll on your path, but that the related utility
 * "not-under-cygwin.exe" will have been used to filter some cases first.
 */

int main(int argc, char *argv[])
{
/*
 * Note that I do not investigate stderr, only stdin and stdout. Thus
 * when invoking this code I can go "2>/dev/null" without upsetting anything.
 */
    int n = isatty(0) && isatty(1);
    const char *display = getenv("DISPLAY");
    const char *ssh_host = getenv("SSH_HOST");
    int nogui = 0;
    int i;
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[i], "--nogui") == 0 ||
            strcmp(argv[i], "-w") == 0 ||
            strcmp(argv[i], "-w-") == 0)
        {   nogui = 1;
            break;
        }
    }
    return (n && display==NULL && ssh_host==NULL && !nogui) ?
               0 :   /* reduce.com --gui ... */
           n ? 1 :   /* cygwin-reduce.exe */
               2;    /* reduce.com */
}

/* end of cygwin-isatty.c */
