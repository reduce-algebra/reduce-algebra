/*
 * sigs.c - External routines to deal with signals
 *
 */
 

#include <signal.h>

extern long bruch_bruch;

void c_terminal_interrupt(int n)
{
    printf("terminal Interrupt registered\n");
    bruch_bruch--;
    signal(SIGINT,c_terminal_interrupt);
    if (bruch_bruch <= -5)
    {
       printf("terminating after 5th unhandled terminal interrupt\n");
       exit(0);
    }
}

void c_signal()
{
#ifndef WINPSL
   signal(SIGINT,c_terminal_interrupt);
#endif
}

void sun3_sigset( sig, action )
void (*action)(); 
int sig;
{
    // if(sig == SIGINT) signal(SIGINT,term_interrupt); else
         signal(sig,action);
}
 
void sigrelse(sig, action)
void (*action)();
int sig;
{
   sun3_sigset(sig,action);
}  
 
ieee_handler()
{
  return(0);
}

ualarm()

{
  return(0);
}

ieee_flags()
{
  return(0);
}
