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

typedef void (*sig_t) (int);

// extern sig_t inthand;

sun3_sigset( sig, action )
void (*action)();
int sig;
{
//   if (sig == 2) { signal(2,inthand); printf("%lx sig 2", &inthand); }  else
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
 
ieee_handler()
{
}
ualarm()

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
if (a1 == 5) { return( read(a2,a3,a4));}; 
if (a1 == 6) { return( write(a2,a3,a4));}; 
if (a1 == 7) { return( lseek(a2,a3,a4));}; 
}

