/* cygwin-isatty.c                       Copyright (C) 2012 Codemist Ltd */


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

/* Signature: 7a0a7e17 03-Jun-2012 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * The purpose of this tiny program is to return (as an error-code)
 * information as to whether stdin and stdout satisy the "isatty" test.
 */

int main(int argc, char *argv[])
{
    int n = isatty(0) && isatty(1);
    const char *display = getenv("DISPLAY");
    const char *ssh_host = getenv("SSH_HOST");
    int nogui = 0;
    int i;
    for (i=1; i<argc; i++)
    {   if (strcmp(argv[1], "--nogui") == 0 ||
            strcmp(argv[1], "-w") == 0 ||
            strcmp(argv[1], "-w-") == 0)
        {   nogui = 1;
            break;
        }
    }
    return (n && display==NULL && ssh_host==NULL && !nogui) ?
               0 :   /* reduce.com --gui ... */
           n ? 1 :   /* cygwin-reduce.exe */
               2;    /* reduce.com */
}

