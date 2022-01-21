// "log.cpp"                                            2021-22, A C Norman


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

// This is a test and demonstration file for zprintf.
// Ideally errors end up reported at compile-time, but note
// that for that to be the case you need to compile in C++20 mode with
// the "consteval" keyword available. With earlier C++ standards in use
// the diagnostics will be raised at run-time.

#include "log.h"

#include <string>
#include <climits>

int main(int argc, char *argv[])
{
// The tests that I run can be limited in two ways:
// (a) g++ ... -DSTART=nn -DEND=mm
// should only compile tests within the specified range. The range defaults
// to being 1..MAX_INT. It may be especially useful to use this when testing
// with compile-time validation of format strings is active, because this
// only passes a limited range of cases through compilation - thus it can
// arrange either not to build cases that illustrate failures ot it can focus
// in on just one such.
// If you just define START then END defaults to the same value so you just
// get a single test case build.
//
// (b) if command-line arguments are provided then these limit the testing
// at run-time. If one argument N is provided that test all cases from N
// upwards, if two N and M are give the case from N to M (inclusive) get
// tested.
//
// I am setting this up such that cases 1...100 are ones where the format
// directives should be valid, and 101... ones where there is some problem
// that ought to be detected and rejected.

#ifndef START
#define START 1
#else // START
#ifndef END
#define END START
#endif // END
#endif // START
#ifndef END
#define END INT_MAX
#endif // END

// The next two are just so my lines of code are a little shorter.
#define P START
#define Q END

    int N = argc<2 ? 1 : std::stoi(argv[1]);
    int M = argc<3 ? INT_MAX : std::stoi(argv[2]);

    std::cout << "zprintf tests enabled from case " << P;
    if (Q != INT_MAX) std::cout << " to " << Q;
    else std::cout << " upwards";
    std::cout << "\n";

#if (1>=P && 1<=Q)
    if (1>=N&&1<=M) std::cout <<1<<": ",
        zprintf("Simple string\n");
#endif
#if (2>=P && 2<=Q)
    if (2>=N&&2<=M) std::cout <<2<<": ",
        zprintf("String %% with percents%%\n");
#endif
#if (3>=P && 3<=Q)
    if (3>=N&&3<=M) std::cout <<3<<": ",
        zprintf("|%5%|%#5%|%+5%|%-5%|% 5%|%05%|\n");
#endif
#if (4>=P && 4<=Q)
    if (4>=N&&4<=M) std::cout <<4<<": ",
        zprintf("decimal   %d\n", 123);
#endif
#if (5>=P && 5<=Q)
    if (5>=N&&5<=M) std::cout <<5<<": ",
        zprintf("hex       %x\n", 123);
#endif
#if (6>=P && 6<=Q)
    if (6>=N&&6<=M) std::cout <<6<<": ",
        zprintf("hex  %%%% %#X\n", 123);
#endif
#if (7>=P && 7<=Q)
    if (7>=N&&7<=M) std::cout <<7<<": ",
        zprintf("e format  %e\n", 123.4567);
#endif
#if (8>=P && 8<=Q)
    if (8>=N&&8<=M) std::cout <<8<<": ",
        zprintf("f format  %f\n", 123.4567);
#endif
#if (9>=P && 9<=Q)
    if (9>=N&&9<=M) std::cout <<9<<": ",
        zprintf("g format  %g\n", 123.4567);
#endif
#if (10>=P && 10<=Q)
    if (10>=N&&10<=M) std::cout <<10<<": ",
        zprintf("s format  %s\n", "A string");
#endif
#if (11>=P && 11<=Q)
    if (11>=N&&11<=M) std::cout <<11<<": ",
        zprintf("hex       %X\n", 123);
#endif
#if (12>=P && 12<=Q)
    if (12>=N&&12<=M) std::cout <<12<<": ",
        zprintf("hex       %#X\n", 123);
#endif
#if (13>=P && 13<=Q)
    if (13>=N&&13<=M) std::cout <<13<<": ",
        zprintf("e format  %E\n", 123.4567e20);
#endif
#if (14>=P && 14<=Q)
    if (14>=N&&14<=M) std::cout <<14<<": ",
        zprintf("f format  %F\n", 123.4567e20);
#endif
#if (15>=P && 15<=Q)
    if (15>=N&&15<=M) std::cout <<15<<": ",
        zprintf("g format  %G\n", 123.4567e20);
#endif
#if (16>=P && 16<=Q)
    if (16>=N&&16<=M) std::cout <<16<<": ",
        zprintf("# flag & x vs. X %x %X %#x %#X\n", 199, 299, 399, 499);
#endif
    std::atomic<int> a(123);
#if (17>=P && 17<=Q)
    if (17>=N&&17<=M) std::cout <<17<<": ",
        zprintf("atomic    %d %x\n", a, a);
#endif
#if (18>=P && 18<=Q)
    if (18>=N&&18<=M) std::cout <<18<<": ",
        zprintf("now with width\n");
#endif
#if (19>=P && 19<=Q)
    if (19>=N&&19<=M) std::cout <<19<<": ",
        zprintf("decimal   |%10d|\n", 123);
#endif
#if (20>=P && 20<=Q)
    if (20>=N&&20<=M) std::cout <<20<<": ",
        zprintf("hex       |%10x|\n", 123);
#endif
#if (21>=P && 21<=Q)
    if (21>=N&&21<=M) std::cout <<21<<": ",
        zprintf("e format  |%10e|\n", 123.4567);
#endif
#if (22>=P && 22<=Q)
    if (22>=N&&22<=M) std::cout <<22<<": ",
        zprintf("f format  |%10f|\n", 123.4567);
#endif
#if (23>=P && 23<=Q)
    if (23>=N&&23<=M) std::cout <<23<<": ",
        zprintf("g format  |%10g|\n", 123.4567);
#endif
#if (24>=P && 24<=Q)
    if (24>=N&&24<=M) std::cout <<24<<": ",
        zprintf("s format  |%10s|\n", "A string");
#endif
#if (25>=P && 25<=Q)
    if (25>=N&&25<=M) std::cout <<25<<": ",
        zprintf("now with precision\n");
#endif
#if (26>=P && 26<=Q)
    if (26>=N&&26<=M) std::cout <<26<<": ",
        zprintf("e format  |%10.2e|\n", 123.4567);
#endif
#if (27>=P && 27<=Q)
    if (27>=N&&27<=M) std::cout <<27<<": ",
        zprintf("f format  |%10.2f|\n", 123.4567);
#endif
#if (28>=P && 28<=Q)
    if (28>=N&&28<=M) std::cout <<28<<": ",
        zprintf("g format  |%10.2g|\n", 123.4567);
#endif
#if (29>=P && 29<=Q)
    if (29>=N&&29<=M) std::cout <<29<<": ",
        zprintf("g format  |%*.2g|\n", 10, 123.4567);
#endif
#if (30>=P && 30<=Q)
    if (30>=N&&30<=M) std::cout <<30<<": ",
        zprintf("g format  |%10.*g|\n", 2, 123.4567);
#endif
#if (31>=P && 31<=Q)
    if (31>=N&&31<=M) std::cout <<31<<": ",
        zprintf("g format  |%*.*g|\n", 10, 2123.4567);
#endif
#if (32>=P && 32<=Q)
    if (32>=N&&32<=M) std::cout <<32<<": ",
        zprintf("2 values %d %d\n", 101, 102);
#endif
#if (33>=P && 33<=Q)
    if (33>=N&&33<=M) std::cout <<33<<": ",
        zprintf("3 values %d %d %d\n", 101, 102, 103);
#endif
#if (34>=P && 34<=Q)
    if (34>=N&&34<=M) std::cout <<34<<": ",
        zprintf("3 values %d %g %d\n", 101, 102.102, 103);
#endif

// The cases from here down are intended to illustrate errors. With compile
// time checking if ANY of these are enabled (via -DSTART and -DEND) the
// code should not build so run-time behaviour of good cases can not be
// performed. However when only run-time checking is present the first of
// these that fails will prevent attempts to run the follwing ones.
//
#if (101>=P && 101<=Q)
    if (101>=N&&101<=M) std::cout <<101<<": ",
        zprintf("percent at end%");
#endif
#if (102>=P && 102<=Q)
    if (102>=N&&102<=M) std::cout <<102<<": ",
        zprintf("args and percent at end%", 1, 2);
#endif
#if (103>=P && 103<=Q)
    if (103>=N&&103<=M) std::cout <<103<<": ",
        zprintf("no specifier\n", 1, 2, 3);
#endif
#if (104>=P && 104<=Q)
    if (104>=N&&104<=M) std::cout <<104<<": ",
        zprintf("unknown specifier %Q\n", 1, 2, 3);
#endif
#if (105>=P && 105<=Q)
    if (105>=N&&105<=M) std::cout <<105<<": ",
        zprintf("not enough %d %x\n", 1, 2, 3);
#endif
#if (106>=P && 106<=Q)
    if (106>=N&&106<=M) std::cout <<106<<": ",
        zprintf("too many %d %x %d\n %x", 1, 2, 3);
#endif
// Cases where an actual argument is not the correct type.
#if (107>=P && 107<=Q)
    if (107>=N&&107<=M) std::cout <<107<<": ",
        zprintf("decimal   %d\n", 123.0);
#endif
#if (108>=P && 108<=Q)
    if (108>=N&&108<=M) std::cout <<108<<": ",
        zprintf("hex       %x\n", 123.0);
#endif
#if (109>=P && 109<=Q)
    if (109>=N&&109<=M) std::cout <<109<<": ",
        zprintf("e format  %e\n", 123);
#endif
#if (110>=P && 110<=Q)
    if (110>=N&&110<=M) std::cout <<110<<": ",
        zprintf("f format  %f\n", 123);
#endif
#if (111>=P && 111<=Q)
    if (111>=N&&111<=M) std::cout <<111<<": ",
        zprintf("g format  %g\n", 123);
#endif
// Malformed specifier
#if (112>=P && 112<=Q)
    if (112>=N&&112<=M) std::cout <<112<<": ",
        zprintf("precision %1.Qf\n", 1.0);
    return 0;
#endif
}

// end of log.cpp
