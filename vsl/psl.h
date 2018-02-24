/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         psl.h
% Description:  Common header for PSL kernel C code
% Author:       Arthur Norman
% Status:       Open Source: BSD License
%
% (c) Copyright 2018, Arthur Norman
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>

/*
 * The functions here are (just) called from compiled code. In the
 * assembly code for the kernel the code is written with the names
 * having a leading underscore. For Linux that underscore remains
 * visible here in the C code that is linked to, while under Cygwin
 * or on a Macintosh it is not. So here I define functions whose names
 * have leading underscores if I am on Linux but not otherwise. This is
 * a bit messy and ugly but is still about the neatest I can think of
 * at present if I want one body of code to apply everywhere.
 */

#if defined __linux__ || defined __CYGWIN__
#define _(x) _ ## x
#else
#define _(x) x
#endif

/*
 * NDEBUG can be used to disable checking of assertions. At least for
 * now I will arrange that when it is NOT defined that there is some
 * trace output generated almost every time that the C parts of the
 * PSL kernel get invoked.
 */

#ifdef NDEBUG

#define TR
#define TR1(name)

#else

#define TR TR_printer(__LINE__, __FILE__)

#define TR1(name) TR1_printer(name, __LINE__, __FILE__)

static inline void TR_printer(int line, const char *file)
{   fprintf(stderr, "Trace at line %d of file %s\n", line, file);
}

static inline void TR1_printer(const char *name, int line, const char *file)
{   fprintf(stderr, "Trace %s at line %d of file %s\n", name, line, file);
}

#endif

/*
 * The intent is to put declarations for all the various C functions used
 * within PSL here, so that (a) this represents collected documentation of
 * their names and arguments and (b) so that compilers can check for
 * consistent use.
 */


/* end of psl.h */
