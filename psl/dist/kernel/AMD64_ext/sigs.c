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
 
#include <signal.h>

#ifndef LINUX
#include <ieeefp.h>
fp_rnd fp_round;
fp_except fp_mask,fp_stick;
int      fp_first=0;
#endif


sun3_sigset( sig, action )
void (*action)();
int sig;
{
   if (signal(sig, SIG_IGN) != SIG_IGN) 
    signal(sig, action);

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

#ifndef LINUX
   if(sig == SIGFPE)
     { fpsetsticky(0);
       fpsetround(FP_RN); 
       fpsetmask(fp_mask);
     }
   signal(sig, action); 
#endif

}
 

 
setlinebuf()
{
}
 
ieee_handler(x,y)
char * x; int y;
{
  mkfifo(x,y);
}

ualarm()

{
}

ieee_flags(long long x1,long long x2,long long x3,long long x4)
{
 if(x1 == 10)  forminit(x2,x3);
}
