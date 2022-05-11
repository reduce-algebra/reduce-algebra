/*
 * sigs.c - External routines to deal with signals
 *
 * Author:    Leigh Stoller
 *         Computer Science Dept.
 *         University of Utah
 * Date:    18-Aug-1986
 *
 *           Modified by Chris Burdorf (2/17/89)
 *          
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 */

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <signal.h>
#include <fptrap.h>

#include "pslkernel.h"

struct rlimit rlp;
double mysigstack[500];

extern int  SYMVAL[];

int lisprpv;

signalhandler(num,dum,scp)

int num,dum;
int * scp;

{ SYMVAL[ibmrssignumber] = num;
  SYMVAL[ibmrssigcp]     = scp;
  SYMVAL[ibmrssigpc]     = scp[10];
  if ((SYMVAL[kernelmode] & 255) != 0x80) { SYMVAL[bruch]   = -17;
					   return (0);}

  if (num == 2) if (SYMVAL[bruch] != 0) {SYMVAL[bruch]     = -17;
					 return (0); }

  scp[10]   = lisprpv;
  clearerr (stdin);
  return (0);
  };

/* Tag( sigset )
 */

psl_sigset( sig, action )
int action; /*void (*action)();
*/
int sig;
{ /*if (sig == 8) setupoverflow(action); */
  lisprpv = action;
  if (signal(sig, SIG_IGN) != SIG_IGN)
               signal(sig, signalhandler  );
  if (sig == 8) fp_swap_flag(0);

}
setupoverflow(action)
void (*action)();
{
    /* this sets the stack overflow limit to be less than
       the initial limit by 8000 bytes
     */
    struct sigstack ss;
    struct sigvec sv;

    /* set up to catch stack overflows */
    getrlimit(RLIMIT_STACK,&rlp);

    /*  we will allocate StackPreserve bytes for overflow purposes */
    rlp.rlim_cur -= 4000;
     printf (" rlimit = %x \n",rlp.rlim_cur);
    /*setrlimit(RLIMIT_STACK,&rlp); */

    ss.ss_sp = (char *) &mysigstack[450];
    ss.ss_onstack = 0;
    printf (" errorstatus from sigstack %d \n",sigstack(&ss,0));

    sv.sv_handler = action;
    printf (" action = %x \n",action);
    sv.sv_mask = 0;
    sv.sv_onstack = 1;
    printf (" errorstatus from sigvec %d %x \n",sigvec(8,&sv,0),17);
}
