/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PIPE-S.C
% Description:  pipe, slave mode
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

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef ALPHA
#define LONG __int64
#else
#define LONG long
#endif


#ifdef TEST
#define TEST_PRINT(fmt,p1,p2) pmelden(fmt,p1,p2)
#else
#define TEST_PRINT(fmt,p1,p2)
#endif

HANDLE fe2lisp_read,fe2lisp_write, lisp2fe_read, lisp2fe_write; 
static int slave_mode = 1;

void my_popen_slave(int n);

extern void my_puts(char *);
extern int my_psend(char,char *,int);
extern int my_preceive(char,char *,int);
extern int myWriteToNamedPipe(char *,int);
extern int myReadFromNamedPipe(char *,int);
extern void local_puts(char *);
extern int my_plocalcall(char *,int);

extern LONG bruch_bruch;


//protocol:
//     c:   remote procedure call
//     a:   answer to rpc
//     r:   read request
//     d:   data reply to 'r'
//     b:   break
//     x:   exit
//     w:   write (data)
//     k:   ack to w

void my_peek();

char * who()
   {
      if(slave_mode) return("slave"); else return("master");
   }

pmelden(char * fmt,char * p1, char * p2)
   {
      char str[100];
      sprintf(str,fmt,who(),p1,p2);
      if(slave_mode) puts(str); else my_puts(str);
   } 
      
my_rpc(char * buf, int len)
   {
         TEST_PRINT("%s RPC call\n %s\n",buf,"");
      my_psend('c',buf,len);
      return(my_preceive('a',buf,len));
   }

void my_popen_slave(int n)
   {
     char lbuf[10];
       // transfer address of break control to master
     sprintf(lbuf,"%lx",&bruch_bruch);
printf("adr bruch %s\n",lbuf);
     my_psend('b',lbuf,strlen(lbuf));      
  }

my_pexit()
   {
      char lbuf[8];
      my_psend('x',lbuf,0);
      //myDeleteNamedPipe();
   }

my_pwrite(char * buf, int len)
   {
      int i,j; char lbuf[100];

      if((int)strlen(buf) > len) buf[len] = '\0';
      printf("%s",buf); 
      j = my_psend('w',buf,len);
      i = my_preceive('k',lbuf,100);
      return(j);
   }

my_pread(char * buf, int len)
   {
       int i;
       my_psend('r',"",0);
       i = my_preceive('d',buf, len);
       buf[i] = '\0';
       printf("%s\n",buf);
       return(i);
   }

my_psend(char type, char * buf, int len)
   {
       int ret;
       char lbuf[600];

       strncpy(lbuf,buf,len);

       lbuf[len] = type;
          TEST_PRINT("%s sends: %s\n",lbuf,"");
       ret=myWriteToNamedPipe(lbuf,len+1);
       my_peek();
       return(ret);
   }

my_preceive(char type, char * buf, int len)
   {
     int ret,t,llen;
     char lbuf[600]; 

         TEST_PRINT("%s waits for %s\n",(char*)&type,"");
     next:
       llen = myReadFromNamedPipe(lbuf, 600);
       llen -- ; t = lbuf[llen]; lbuf[llen] = '\0'; 

       if (t == type)
         {
           strncpy(buf,lbuf,llen); 
             TEST_PRINT("%s received %s\n",&type,"");
           return(llen);
         };

             TEST_PRINT("%s received %s\n",(char*)&t,""); 
       if(t == 'x')  // exit
          exit(0);
       else if(t == 'w')
         {
           local_puts(lbuf);
         }    
       else if(t == 'c')  // remote procedure call
         { 
              ////printf("%s received RPC %s\n",lbuf,"");
              TEST_PRINT("%s received RPC %s\n",lbuf,"");
           ret=my_plocalcall(lbuf,llen);    // call local procedure
              ////printf("%s returns from RPC %d\n","",ret);
              TEST_PRINT("%s returns from RPC\n","","");
           my_psend('a',lbuf,ret);    // result return
         }
       else
        { 
          sprintf(lbuf," error: unexpected message >%c< instead of >%c<\n",t,type);
          pmelden("%s %s\n",lbuf,"");
        }
      goto next;
   }

void my_peek()
   {
       // handle messages with may come asynchronously

     int ret,t,llen;
     char lbuf[600]; 

       if   (1) // (!PeekNamedPipe(the_named_pipe,lbuf,600,&llen,&l1,&l2)
                //|| llen<1)
          {
             TEST_PRINT("%s peek empty\n","","");
             return;
          }

       llen -- ; t = lbuf[llen]; lbuf[llen] = '\0'; 
           
           TEST_PRINT("%s peek sees message %s\n",(char*)&t, "");

       if (!(t == 'x' || t == 'c' || t == 'b' || (t == 'w' && ! slave_mode))) return;

           TEST_PRINT("%s peek processes message %s\n",(char*)&t, "");

       llen = myReadFromNamedPipe(lbuf, 600);
      
       if(t == 'x')  // exit
          exit(0);
       else if(t == 'c')  // remote procedure call
         { 
           ret=my_plocalcall(lbuf,llen);    // call local procedure
           my_psend('a',lbuf,ret);          // result return
         }
       else if(t == 'b') 
           bruch_bruch--;
       else if(t == 'w')
         {
           local_puts(lbuf);
         }    
    }


myWriteToNamedPipe(char * buf, int bytes)
  {
      DWORD  retCode;
      DWORD bytesWritten;

      retCode = WriteFile (lisp2fe_write, buf, bytes,
                     &bytesWritten, (LPOVERLAPPED)NULL);
      FlushFileBuffers(lisp2fe_write);

      return((int)bytesWritten);
 }

myReadFromNamedPipe(char * buf, int bytes)
  {
 
      DWORD  retCode;
      DWORD bytesRead;

      while(!(retCode = ReadFile (fe2lisp_read, buf, bytes, 
                      &bytesRead, (LPOVERLAPPED)NULL))) Sleep(500);

      return((int) bytesRead);
  }
