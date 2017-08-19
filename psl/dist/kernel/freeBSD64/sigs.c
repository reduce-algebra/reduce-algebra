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

void 
sun3_sigset( sig, action )
void (*action)();
int sig;
{
  struct sigaction actio;

  actio.sa_flags = SA_SIGINFO | SA_RESTART;
  actio.sa_sigaction = action;
  sigaction(sig, &actio, NULL);

  /*
  if (signal(sig, SIG_IGN) != SIG_IGN) 
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
 
void sun3_sigrelse(sig, action)
void (*action)();
int sig;
{

#ifndef LINUX
   if(sig == SIGFPE)
     { fpsetsticky(0);
       fpsetround(FP_RN); 
       fpsetmask(fp_mask);
     }
   signal(sig, action); 
#endif

}
 

void ieee_handler()
{
}

void
ualarm()

{
}

void ieee_flags()
{
}
