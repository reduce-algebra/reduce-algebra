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
 *
 *           Modified by Chris Burdorf (2/17/89)
 *           renamed sigset to sun3_sigset for sun os 4.
 */
 
#include <stdio.h>
#include <signal.h>
#include <fenv.h>

#ifndef LINUX
#include <ieeefp.h>
int      fp_first=0;
#endif

#ifndef ALTSIGSTACKSIZE
#define ALTSIGSTACKSIZE (16*SIGSTKSZ)
#endif

static char alternate_signalstack[ALTSIGSTACKSIZE];
static stack_t stackinfo = { (void *) alternate_signalstack, sizeof(alternate_signalstack), 0 };
static stack_t *stackinfo_ptr = NULL;

void
sun3_sigset( sig, action )
void (*action)();
int sig;
{
   struct sigaction act = {0};
   
   if (signal(sig, SIG_IGN) != SIG_IGN) {
     act.sa_sigaction = action;
     act.sa_flags = SA_SIGINFO | SA_RESTART;

     // set up alternate signal stack for SIGSEGV
     if (sig == 11) {
       if (stackinfo_ptr == NULL) {
           stackinfo_ptr = &stackinfo;
           sigaltstack(stackinfo_ptr,NULL);
        }
        act.sa_flags |= SA_ONSTACK;
     }
     sigaction(sig, &act, NULL);
   } 
}

void
sun3_sigrelse(sig, action)
void (*action)();
int sig;
{
}
 

void ieee_handler()
{
}

void ieee_flags()
{
}

/*
 * block / unblock a specific signal
 */
void mask_signal(int signo, int block)
{
    sigset_t sigset;

    sigemptyset(&sigset);
    sigaddset(&sigset,signo);
    sigprocmask(block != 0 ? SIG_BLOCK : SIG_UNBLOCK, &sigset, NULL);
}
