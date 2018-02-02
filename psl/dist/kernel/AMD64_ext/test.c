/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:test.c
% Description:  Miscellaneous floating point support routines.
% Author:       Leigh Stoller
% Created:      29-Oct-86 
% Modified:     
% Mode:         Text
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1986, University of Utah, all rights reserved.
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%  
% 05-May-87 (Leigh Stoller)
%  Added C defintions for external float routines used in fast-math.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
#include <signal.h>

int pace()
{ printf("friede auf Erden\n"); exit (0); }

int krach(int* x)
{ return (*x); }

int raus(a1,a2,a3)
int a1;
char * a2;
void* a3;
{   printf("%d,%lx,%lx raus \n",a1,a2,a3);
    printf("%lx\n",*(int*)(a2+108));
    printf("%lx\n",*(int*)(a2+112));
    printf("%lx\n",*(a2+116));
//signal(11,SIG_IGN);
*(int *)(a2+112)= &pace +4;
    printf("%lx\n",*(int*)(a2+112));
}

int raus1(a1,a2,a3)
int a1;
siginfo_t* a2;
void* a3;

{int i;
  printf("%d,%lx,%lx raus \n",a1,a2,a3); 
 printf("%lx\n",a2->si_signo);
 printf("%lx\n",a2->si_errno);
 printf("%lx\n",a2->si_code);
 printf("%lx\n",a2->si_pid );
 printf("%lx\n",a2->si_uid );
 printf("%lx\n",a2->si_status);
 printf("%lx\n",a2->si_utime);
 printf("%lx\n",a2->si_stime);
 printf("%lx\n",a2->si_value);
 printf("%lx\n",a2->si_int);
 printf("%lx\n",a2->si_ptr);
 printf("%lx\n",a2->si_addr);
 printf("%lx\n",a2->si_band);
 printf("%lx\n",a2->si_fd);
 exit (0);}

struct sigaction act;

int main()
{ double aa; int i;
  act.sa_sigaction=raus;
  act.sa_flags    =SA_SIGINFO;
//  sigaction(11,&act,NULL);
  signal(11,raus);
  krach (-300);
}
