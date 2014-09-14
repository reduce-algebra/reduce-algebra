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
 
#include <unistd.h>
#include <signal.h>

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
   struct sigaction act = {0};

   if (signal(sig, SIG_IGN) != SIG_IGN)  {
     act.sa_sigaction = action;
     act.sa_flags = SA_SIGINFO;
     sigaction(sig, &act, (void*)0);
   }


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
 
void
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
 

 
void
setlinebuf()
{
}
 
void
ieee_handler()
{
}


#include <sys/file.h>
#include <fcntl.h>


int ieee_flags(a1, a2, a3, a4)
long long int a1,a2,a3,a4;
{
if (a1 == 1) { return( flock(a2,a3));};
if (a1 == 2) { return( fcntl(a2,a3,a4));};
if (a1 == 3) { return( open((char *)a2,a3,a4));};
if (a1 == 4) { return( close(a2));}; 
if (a1 == 5) { return( read(a2,(void *)a3,a4));}; 
if (a1 == 6) { return( write(a2,(void *)a3,a4));}; 
if (a1 == 7) { return( lseek(a2,a3,a4));}; 
return 0;	// keep compiler happy, cannot be reached since a1 is never <1 or >7
}

