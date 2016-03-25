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

sun3_sigset( sig, action )
void (*action)();
int sig;
{
   if (signal(sig, SIG_IGN) != SIG_IGN) 
    signal(sig, action);
}
 
sun3_sigrelse(sig, action)
void (*action)();
int sig;
{
   sun3_sigset(sig,action);
}
 
setlinebuf()
{
}
 
ieee_handler()
{
  _clearfp();
}

ualarm()
{
}

ieee_flags()
{
}
