/*
 * sigs.c - External routines to deal with signals
 *
 */
 

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <excpt.h>

extern long bruch_bruch;

void c_terminal_interrupt(int n)
{
    printf("Terminal Interrupt registered\n");
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
void (*action)(int); 
int sig;
{
    if(sig == SIGINT || sig == SIGBREAK) {
		signal(SIGINT,c_terminal_interrupt);
	} else
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
  _clearfp();
  return(0);
}

ualarm()

{
  return(0);
}

// abuse ieee_flags to return a pointer to the EXCEPTION_POINTERS structure
void * ieee_flags()
{
  return _pxcptinfoptrs;
}

