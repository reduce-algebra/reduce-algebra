/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLSOCKET.C
% Description:  Interface to *ix sockets
% Author:       
% Created:      
% Modified:     
% Mode:         Text
% Package:
% Status:       Open Source: BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include<windows.h>
#include <time.h>

#ifdef ALPHA
#define LONG __int64
#define ADDRESSINGUNITSPERITEM 8
#else
#define LONG long
#define ADDRESSINGUNITSPERITEM 4
#endif

unixsocketopen(name , number)

char * name;
int number;

{
}

getsocket (mail_fd , string , length)

int mail_fd,length;
char * string;

{
}

writesocket (mail_fd , string , length)

int mail_fd,length;
char * string;

{
}

unixclosesocket (conn_fd)
int conn_fd;

{
}


LONG getpid()
  { return((LONG)GetCurrentProcessId()); }
 
LONG external_timc(buffer)
     struct tms *buffer;
{
  //FILETIME a1,a2,a3,a4 , cl;
#ifdef WINPSL
   prio_loop();
#endif
  return(clock());  /* CLOCKS_PER_SEC is 1000 */
  //GetProcessTimes(GetCurrentProcess(),&a1,&a2,&a3,&a4);
  //printf("curget... %d\n",GetLastError());
  //return(a4.dwHighDateTime* 10000);
}
LONG whatsup(x)
DWORD * x;

{if ((int) x >1000) { *x = sizeof(OSVERSIONINFO);  
              return(GetVersionEx( (OSVERSIONINFO *) x)); }
else return (0);}

// for interrupts etc
