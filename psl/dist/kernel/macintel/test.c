/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PB:FLOAT.C
% Description:  Miscellaneous floating point support routines.
% Author:       Leigh Stoller
% Created:      29-Oct-86 
% Modified:     
% Mode:         Text
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1986, University of Utah, all rights reserved.
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
siginfo_t* a2;
long long int * a3;
{   printf("%d,%lx,%lx %lx raus \n",a1,a2,a3,&krach);
 printf("%lx\n",a2->si_addr);
 printf("pid %x\n",a2->si_pid);
// a3 = a2->si_addr;
 printf("%lx\n",a3);

    printf("%x\n",*(int*)(a3+0));
    printf("%x\n",*(int*)(a3+4));
    printf("%x\n",*(int*)(a3+8));
    printf("%x\n",*(int*)(a3+12));
    printf("%x\n",*(int*)(a3+16));
    printf("%x\n",*(int*)(a3+20));
    printf("%x\n",*(int*)(a2+24));
    printf("28 %x\n",*(int*)(a2+28));
    printf("%x\n",*(int*)(a2+32));
    printf("%x\n",*(int*)(a2+36));
    printf("%x\n",*(int*)(a2+208));
    printf("%x\n",*(int*)(a2+108));
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
// printf("%lx\n",a2->si_code);
// printf("%lx\n",a2->si_pid );
// printf("%lx\n",a2->si_uid );
// printf("%lx\n",a2->si_status);
// printf("%lx\n",a2->si_utime);
// printf("%lx\n",a2->si_stime);
// printf("%lx\n",a2->si_value);
// printf("%lx\n",a2->si_int);
// printf("%lx\n",a2->si_ptr);
// printf("%lx\n",a2->si_addr);
// printf("%lx\n",a2->si_band);
 //printf("%lx\n",a2->si_fd);
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
