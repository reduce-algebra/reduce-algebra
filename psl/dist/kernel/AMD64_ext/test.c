/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Description:  Miscellaneous floating point support routines.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
