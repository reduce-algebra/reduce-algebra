/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
* Author:       RAM, HP/FSD
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
* Status:       Open Source: BSD License
*
* (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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
*
* Revisions:
*
* 23-Feb-89 (Chris Burdorf)
*  Made  call to psl_main in main call copy_argv to pass the static
*  copy of argv to get around unexec problems.
* 15-Jun-88, (Tsuyoshi Yamamoto)
*  Added init-malloc-param(), _iob[] initializer, _dtabsize for SUN4 PORT.
* 21-Sep-86 (Leigh Stoller)
*  Removed calls to the io-map functions. None of this was needed for the Sun.
*  Removed the 68020_advise function.
* 07-Jul-86 (Leigh Stoller)
*  Removed Calls to echooff and echoon since they are not needed for the top
*   loop, only for Nmode. Who knows why HP used them in the first place.
* 30-Apr-86 (Leigh Stoller)
* Copied this file from gator kernel directory and changed calls to terminal-
*  state to echooff and echoon, which are contained in echo.c
*
******************************************************************************
*
*  $Id$
*
******************************************************************************
*/

#include <stdio.h>
#include <setjmp.h>
 
jmp_buf mainenv;
 
main(argc,argv)
int argc;
char *argv[];
{
  int val;
 
/*  clear_iob();             /* clear garbage pointer in _iob[]    */
/*  clear_dtabsize();
/*  init_malloc_param();        /* reset malloc parameters.        */
 
/*   val=setjmp(mainenv);        /* set non-local return point for exit    */
 
     psl_main(argc,copy_argv(argc,argv));
 
exit(0);
 
}
 
 
os_startup_hook(argc, argv)
     int argc;
     char *argv[];
{
  setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}
 
os_cleanup_hook()
{
/* longjmp(mainenv,1);  */
}
 
#define IOBUFN FOPEN_MAX   /* I guess it is 30 */
clear_iob()
{
 int i;
 
 for(i=3;i<IOBUFN;i++){
    bzero(&_iob[i],sizeof(_iob[i]));
    };
}
 
/*
 *    Some static area must be initialized on hot start.
 *    There may be other area to be initialized but we have no idea
 *    to know them.
 *
 *    _dtabsize ----_end
 */
 
 
extern char *end;
/*
 *     Size of dtabsize is 0x34c bytes.
 */
clear_dtabsize()
{
 int i;
 bzero((int)(&end)-0x34c, 0x34c);
 }
 
