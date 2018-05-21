/*
 * sigs.c - External routines to deal with signals
 *
 * Author:    Leigh Stoller
 *         Computer Science Dept.
 *         University of Utah
 * Date:    18-Aug-1986
 *
 *           Modified by Chris Burdorf (2/17/89)
 *           renamed sigset to sun3_sigset for sun os 4.
 */
 
#include <stdio.h>
#include <signal.h>
#include <fenv.h>

#ifndef LINUX
#include <ieeefp.h>
fp_rnd fp_round;
fp_except fp_mask,fp_stick;
int      fp_first=0;
#endif

fenv_t envp;

sun3_sigset( sig, action )
void (*action)();
int sig;
{ 
  struct sigaction actio;

  if (sig == 500) { fegetenv(&envp); return(0);}
  if (sig == 501) { fesetenv(&envp); return(0);}

  actio.sa_flags = SA_SIGINFO;
  actio.sa_sigaction = action;
  sigaction(sig, &actio, NULL);

 /*  if (signal(sig, SIG_IGN) != SIG_IGN) 
    signal(sig, action);
 */

#ifndef LINUX
   if(sig == SIGFPE && fp_first == 0)
   { 
     fp_first=1;
     fp_round = fpgetround(); 
     fp_mask = fpgetmask(); 
     fp_stick = fpgetsticky();
    }
#endif
     
 
}
 
sun3_sigrelse(sig, action)
void (*action)();
int sig;
{
 sigset_t set;
 if (sig==2){ 
 sigemptyset(&set);
 sigaddset(&set,2);
 sigprocmask(SIG_UNBLOCK,&set,NULL);
	   } 

#ifndef LINUX
   if(sig == SIGFPE)
     { fpsetsticky(0);
       fpsetround(FP_RN); 
       fpsetmask(fp_mask);
     }
   signal(sig, action); 
#endif

}
 

 
 
ieee_handler()
{
}
ualarm()

{
}

ieee_flags()
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
