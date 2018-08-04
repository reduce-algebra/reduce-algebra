/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
* Author:       RAM, HP/FSD
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
*
* (c) Copyright 1983, Hewlett-Packard Company, see the file
*            HP_disclaimer at the root of the PSL file tree
*
*
******************************************************************************
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
*/
#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#ifndef LINUX
#include <ieeefp.h> 
#endif
 
jmp_buf mainenv;
char *abs_execfilepath;
 
void clear_iob(), clear_dtabsize();

void psl_main(int argc, char *argv[], int *symvalptr);

char ** copy_argv();

int Debug = 0;

extern int symval;

main(argc,argv)
int argc;
char *argv[];
{ 
  int val;
 
  clear_iob();             /* clear garbage pointer in _iob[]    */
  clear_dtabsize();
  /* fpsetround(FP_RZ);  */
/*  init_malloc_param();        /* reset malloc parameters.        */
    setvbuf(stdout,NULL,_IOLBF,BUFSIZ);
   /* Record path to exec file */
  if (argc > 0)
    abs_execfilepath = realpath(argv[0],NULL);
 
  val=setjmp(mainenv);        /* set non-local return point for exit    */
 
  if (val == 0)
    _psl_main(argc,copy_argv(argc,argv),&symval);
 
exit(0);
 
}
 
 
os_startup_hook(argc, argv)
     int argc;
     char *argv[];
{
  setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}
 
os_cleanup_hook(x)
int x;

{ if(x==17) longjmp(mainenv,17);
    else  if(x==3)  longjmp(mainenv,3); else longjmp(mainenv,1);
}
 
char * get_execfilepath ()
{
  return abs_execfilepath;
}

clear_iob()
{
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
 }
 
#ifndef LINUX

   /* look for the last occurrence of character c in string s;
      if found, return pointer to string part, NULL otherwise */
char * rindex(s,c)
        char * s; char c;
        { int i,l; char x;
          for (i=0; s[i]!='\000'; i++);
          for (i=i-1; (s[i] !=c) && (i>=0) ; i--);
          if (i<0) return(NULL); else return(& s[i]);
        } 

   /* look for the first occurrence of character c in string s;
      if found, return pointer to string part, NULL otherwise */ 

char * index(s,c) 
        char * s; char c; 
        { int i,l; char x;
          for (i=0; (s[i] !=c) && (s[i]!='\000') ; i++);
          if (s[i]=='\000') return(NULL); else return(& s[i]); 
        } 

bzero (b,length) 
char * b; int length; 
{ int i;
  for (i=0; i<length; i++) b[i]='\000' ; } 

#endif
