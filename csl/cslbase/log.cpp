// "log.cpp"                                               2021, A C Norman


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
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

// $Id: log.cpp 6188 2021-12-04 17:25:29Z arthurcnorman $

// This is a test and demonstration file for zprintf. If compiled with
// -DERRORS it includes a collection of cases that are supposed to be
// reported. Ideally they will end up reported at compile-time, but at
// at present I am having difficulty coaxing C++ into arranging that!

#include "log.h"

int main()
{
    zprintf("Simple string\n");
    zprintf("String %% with percents%%\n");
    zprintf("decimal   %d\n", 123);
    zprintf("hex       %x\n", 123);
    zprintf("hex       %#x\n", 123);
    zprintf("e format  %e\n", 123.4567);
    zprintf("f format  %f\n", 123.4567);
    zprintf("g format  %g\n", 123.4567);
    zprintf("s format  %s\n", "A string");
    zprintf("hex       %X\n", 123);
    zprintf("hex       %#X\n", 123);
    zprintf("e format  %E\n", 123.4567e20);
    zprintf("f format  %F\n", 123.4567e20);
    zprintf("g format  %G\n", 123.4567e20);
    std::atomic<int> a(123);
    zprintf("atomic    %d %x\n", a, a);
    zprintf("now with width\n");
    zprintf("decimal   |%10d|\n", 123);
    zprintf("hex       |%10x|\n", 123);
    zprintf("e format  |%10e|\n", 123.4567);
    zprintf("f format  |%10f|\n", 123.4567);
    zprintf("g format  |%10g|\n", 123.4567);
    zprintf("s format  |%10s|\n", "A string");
    zprintf("now with precision\n");
    zprintf("e format  |%10.2e|\n", 123.4567);
    zprintf("f format  |%10.2f|\n", 123.4567);
    zprintf("g format  |%10.2g|\n", 123.4567);
#ifdef ERRORS
// Cases where the number of arguments seems wrong.
    zprintf("percent at end%");
    zprintf("args and percent at end%", 1, 2);
    zprintf("no specifier\n", 1, 2, 3);
    zprintf("unknown specifier %Q\n", 1, 2, 3);
    zprintf("not enough %d %x\n", 1, 2, 3);
    zprintf("too many %d %x %d\n %x", 1, 2, 3);
// Cases where an actual argument is not the correct type.
    zprintf("decimal   %d\n", 123.0);
    zprintf("hex       %x\n", 123.0);
    zprintf("e format  %e\n", 123);
    zprintf("f format  %f\n", 123);
    zprintf("g format  %g\n", 123);
// Malformed specifier
    zprintf("precision %1.Qf\n", 1.0);
#endif
    return 0;
}
