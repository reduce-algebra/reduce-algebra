/* cygwin-isatty.c                       Copyright (C) 2014 Codemist Ltd */


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
 * 64-bit cygwin will will tend to fail to launch and vice versa.
 */

/*
 * ./cygwin-isatty.exe
 * case $? in
 * 0)
 *   echo stdio is from console and stdout is not redirected.
 *   ;;
 * 1)
 *   echo at least one of the stdio streams has been redirected or
 *   echo comes via a pipe, so I will not be running in interactive
 *   echo mode.
 *   ;;
 * *)
 *   echo other non-zero code mean that the code here failed to run -
 *   echo for instance the 32-bit version was tried in a 64-bit cygwin
 *   echo context or vice versa, or cygwin1.dll was not available.
 *   ;;
 * esac
 *
 */

int main(int argc, char *argv[])
{
/*
 * Note that I do not investigate stderr, only stdin and stdout. Thus
 * when invoking this code I can go "2>/dev/null" without upsetting anything.
 */
    return (isatty(0) && isatty(1) ? 0 : 1);
}

