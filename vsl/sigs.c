/*
 * sigs.c - External routines to deal with signals
 *
 * Author:    Leigh Stoller
 *         Computer Science Dept.
 *         University of Utah
 * Date:    18-Aug-1986
 * Status:    Open Source: BSD License
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the relevant copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
* CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
 */
/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *     Chris Burdorf
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <inttypes.h>
#include <sys/stat.h>

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

#ifdef __linux__
#define _(x) _ ## x
#else
#define _(x) x
#endif

#ifndef LINUX
/* This bit will need review! */

#include <ieeefp.h>
fp_rnd fp_round;
fp_except fp_mask,fp_stick;
int      fp_first=0;
#endif

int forminit(FILE **, FILE **);

struct sigaction act;

void _(sun3_sigset)(int sig, void (*action)())
{   struct sigaction act = {0};
    if (signal(sig, SIG_IGN) != SIG_IGN)
    {   //#signal(sig, action);
        act.sa_sigaction = action;
        act.sa_flags = SA_SIGINFO | SA_RESTART;
        sigaction(sig, &act, (void*)0);
    }

#ifndef LINUX
    if (sig == SIGFPE && fp_first == 0)
    {   fp_first=1;
        fp_round = fpgetround();
        fp_mask = fpgetmask();
        fp_stick = fpgetsticky();
    }
#endif


}

void _(sun3_sigrelse)(int sig, void (*action)())
{

#ifndef LINUX
    if (sig == SIGFPE)
    {   fpsetsticky(0);
        fpsetround(FP_RN);
        fpsetmask(fp_mask);
    }
    signal(sig, action);
#endif

}


int _(ieee_handler)(char *x, int y)
{   return mkfifo(x, y);
}

int _(ieee_flags)(int64_t x1, intptr_t x2, intptr_t x3, int64_t x4)
{   if (x1 == 10) return forminit((FILE **)x2, (FILE **)x3);
    else return 0;
}

/* end of sigs.c */
