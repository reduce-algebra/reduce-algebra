/*
* sigs.c - External routines to deal with signals
*
* Status:    Open Source: BSD License
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the relevant copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
* CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
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

