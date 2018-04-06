/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLLCALL.C
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

/****************************************************************************

***************************************************************************/

#include "psllw.h"
#include "psllcall.h"
#include "winext.h"

extern int     wColumns;
extern HWND    hWnd;
extern int     storedir;
extern char    FileName[];
extern HANDLE  hPageCurs;

HWND pipe_open(LPSTR name);
pipe_write(HANDLE ,LPSTR ,long);     


long psll_call(p1,p2,p3,p4)
    long p1,p2,p3,p4;
   { DWORD ptr16;
     LPSTR sptr;
     int k; long l;
     char c;

    switch((unsigned int) p4){
    
     case YESP:                             /* 18 yesp  */
        return((long)yesp((char*)p1));
     
     case LINELENGTH:
       return((long) local_linelength());    /* get window linelength */
    
     case ASKUSER:                             /* ask user */
        if(askUser0((char*)p1))
        return((long)FileName);
        else return((long)0);

     case HELP:                             /* help entry */
        l= psl_help((int)p1,(char*)p2);
        return(l);


     case PIPE_OPEN:
        return((long)pipe_open((char*)p1));
        break;

     case PIPE_CLOSE: 
        return(pipe_close((int)p1));

     case MENU:                             /* menu service */
        return((long)psl_menu((long)p1,(char*)p2,(long)p3));

     case WIN_PAR:
         {
           long q;
           q = win_params[p1];
           win_params[p1] = p2;
           return (q);
         }

     case FILE_TREE:       
        file_tree();
        return((long)FileName);

     default:
        my_puts("psll_call unknown mode:"); my_newline();
        melden("p1:",(long) p1);
        melden("p2:",(long) p2); 
        melden("p3:",(long) p3); 
        melden("p4:",(long) p4); 
        break; 
     }

     return((long)0);
   }

melden(char * txt, long i)
   { my_puts(txt);
     my_putint(i);
     my_newline();
   }

#include "winpipes.c"
