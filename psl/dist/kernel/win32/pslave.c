/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLAVE.C
% Description:  
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


#define _CRT_SECURE_NO_WARNINGS

#include "psllcall.h"
#include <stdio.h>
#include <string.h>

#define MAXPIPE 5

#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif

extern LONG psl_callback1;
extern LONG psl_callback2;
extern LONG psl_callback3; 
extern LONG psl_callback4;
extern LONG psl_callback5;   

extern int pipe_mode;

extern void psl_call(LONG,LONG,LONG,LONG);
extern int my_rpc(char *,int);
extern void my_puts(char *);
extern void my_psend(char,char *,int);
extern void my_preceive(char,char *,int);
extern int isapipe(LONG);

void notify_wpipe(LONG);
void delete_wpipe(LONG);

int my_plocalcall(char * buf, int len)
     { 
       LONG mode; LONG p1;
                          psl_callback2 = 0;
       psl_callback3 = 0; psl_callback4 = 0;
       sscanf(buf,"%d,%d,%d,%d,%d",&mode,&p1,&psl_callback2,
           &psl_callback3,&psl_callback4);
       psl_callback1 = psl_callback1 | p1; // accumulate
       printf("local: %s %d %d %d %d \n", buf,  psl_callback1,
        psl_callback2, psl_callback3, psl_callback4);
       psl_call(p1,psl_callback2,psl_callback3,psl_callback4);
       printf("return \n");
       return (0);
       /*
       {
          char z[100];
          sprintf(z,"calls: %s %x\n",buf);
          my_puts(z);
          sprintf(z,"calli: %x\n",psl_callback1);
          my_puts(z);
       }
*/
     }

stringp(LONG u)
    { return(u>10000);}

char * my_plocp(char * ptr, char * s, LONG * p)
   // decode one parameter
  {
    char t,c; char * ss; int i=0;
    ss=s;
    t = * ptr ++;
    *p = 0;
    while((c = *ptr++) != '|' && i++<200) *ss++ = c; 
    *ss = '\0';
    if (t == 's') *p = (LONG)s;
    else if (t == 'i') sscanf(s,"%d",p);
    else {printf("illegal argument type: %c\n",t); };
    return(ptr);
   }


psll_call1(LONG p1, LONG p2, LONG p3, LONG p4, int f)
    {
     char lbuf[512]; char sr[255];
     int r;  LONG pr;

     if (!pipe_mode) return(0);

     if (f<1 || !stringp(p1) && !stringp(p2) && !stringp(p3))
       sprintf(lbuf,"i%d|i%d|i%d|i%d|",p1,p2,p3,p4);
        else
     if (f<2 || stringp(p1) && !stringp(p2) && !stringp(p3))
       sprintf(lbuf,"s%s|i%d|i%d|i%d|",p1,p2,p3,p4);
        else
     if (f<3 || stringp(p1) && stringp(p2) && !stringp(p3))
       sprintf(lbuf,"s%s|s%s|i%d|i%d|",p1,p2,p3,p4);
         else
     if (stringp(p1) && stringp(p2) && stringp(p3))
       sprintf(lbuf,"s%s|s%s|s%s|i%d|",p1,p2,p3,p4);

     r= my_rpc(lbuf,strlen(lbuf));

     my_plocp((char*)lbuf,&sr[0],&pr);

     if (p4 == PIPE_OPEN && pr !=0) notify_wpipe(pr);
     if (p4 == PIPE_CLOSE) delete_wpipe(p1);
      
     return(pr);
    }

psll_call(LONG p1, LONG p2, LONG p3, LONG p4)
  { 
    int n=3;

    if(p4 == PIPE_CLOSE) n=0;
    return(psll_call1(p1, p2, p3, p4, n)); 
  }


LONG hpipe[MAXPIPE];

void notify_wpipe(LONG p)
   {
      int h;
      h=isapipe((LONG)NULL);
      hpipe[h-1] = p;
   }

void delete_wpipe(LONG p)
   {
      int h;
      h=isapipe((LONG)p);
      hpipe[h-1] = (LONG)NULL;
   }

pipe_write(LONG pipe, char * s,LONG n)
  {
      // warning: arg 1 and 2 interchanged!!!
     s[n] = '\0';
     psll_call1((LONG)s,pipe,n,(LONG)PIPE_WRITE,1);
     return(n);
  }

local_puts(char * lbuf)
    {
       printf("unexpected message: %s\n",lbuf);
    }
