/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
*               Windows NT, DEC ALpha
* Author:     
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
* Status:       Experimental (Do Not Distribute)
*
*
******************************************************************************
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 
* Revisions:
*
*
******************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

//////#ifdef WINPSL
#include <windows.h>
//////#endif

#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <float.h>

#define _Far16 _far16
#define INCL_DOSEXCEPTIONS
#define INCL_BASE
#define ULONG DWORD

#define ENDCHAR 4

extern HANDLE fe2lisp_read,fe2lisp_write, lisp2fe_read, lisp2fe_write; 

FILE * scriptin; FILE * scriptout;
int script_mode=0;
int win_mode=0;
int pipe_mode=0;

extern int bruch_bruch,psl_callback1;

extern int firstkernel;
extern char bps[];

#ifndef WINPSL
//int hpipe = 0;
#endif

#include <excpt.h>


jmp_buf mainenv,signalenv;
char * abs_execfilepath = NULL;

int Debug = 0;
char * cygdrive_prefix = NULL;

void clear_dtabsize();
extern setupbpsandheap();
extern my_pexit();
extern psl_main(int, char **, int[]);
extern HANDLE my_popen_slave(int);
void c_signal();
void unixinitio();
void init_fp();

/****************** main ***********************/

extern int symms[];

main(argc,argv)

int argc;
char *argv[];
{
  int val; 
  char * renv;
  int i;

  for(i=1; i<argc; i++)
   { 
     if(0==strcmp(argv[i],"-p"))
     { sscanf(argv[i+1],"%d",&fe2lisp_read);
       sscanf(argv[i+2],"%d",&lisp2fe_write);
       my_popen_slave(0);
       win_mode = 1;
       pipe_mode = 1;
     }
   }  

  renv=getenv("reduce");
  if(renv ==(char*) NULL)
  {  // create path to %reduce%
       char env[200]="reduce=";

#ifdef WINPSL
       int l; char*s;
       char path[200];

       GetModuleFileName((HMODULE)NULL,path,100L);
       l=strlen(path);
       while(l>0 && path[l] != '\\') l--; path[l]='\0';
       if(s=strstr(path,"\\bin\\")) *s = '\0';
       strcat(env,path);
       _putenv(strdup(env));
#else
      // printf("\n+=+=+=+ WARNING: variable reduce not set\n");
#endif
  }
 
  scriptin = NULL; scriptout = NULL;
  psl_callback1 = 0;
  clear_dtabsize();
  unixinitio(); 
  bruch_bruch = 0;

  if (argc > 0)
    abs_execfilepath = _fullpath(NULL,argv[0],_MAX_PATH);

  cygdrive_prefix = getenv("BPSL_CYGDRIVE_PREFIX");
  if (getenv("BPSL_DEBUG") != NULL)
     Debug = 1;

  init_fp();	// initilialize floating point exception handling

  c_signal();   // initizlize Ctrl C

  val=setjmp(mainenv);        /* set non-local return point for exit    */

  if (val == 0)
/*    try{*/ psl_main(argc,argv,symms); /* }
         except(EXCEPTION_EXECUTE_HANDLER) 
          {printf("Error on PSL kernel level\n");};*/

  if (pipe_mode) my_pexit();

  if(scriptin != NULL) fclose(scriptin); 
  if(scriptout != NULL) fclose(scriptout);
  
  exit(val-1);
 
}
 
 
close_all()
{
   if(scriptout != NULL) fclose(scriptout);
   scriptout = NULL;
}

os_startup_hook(argc, argv)
     int argc;
     char *argv[];
{
  setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}
 
os_cleanup_hook()
{
longjmp(mainenv,1);
}
 
char * get_execfilepath ()
{
  return abs_execfilepath;
}

clear_iob()
{

}
 
char winpathbuffer[_MAX_PATH];

int
pathstringncompare(char *s1, char *s2, size_t len)
{
  while (*s1 !=0 && *s2 != 0 && len > 0 &&
	 ((*s1 == *s2) || (*s1 == '/' && *s2 == '\\') || (*s1 == '\\' && *s2 == '/')))  {
    s1++; s2++; len--;
  }
  if (len == 0) {
    return 0;
  } else if (*s1 > *s2) {
    return 1;
  } else if (*s2 > *s1) {    
    return -1;
  }
}

char *
cygpath2winpath(char * cygpath)
{
  if (Debug > 0) {
    fprintf(stderr,"input cygpath: %s\n",cygpath);
    fprintf(stderr,"prefix is %s\n",cygdrive_prefix == NULL ? "(NULL)" : cygdrive_prefix);
    fflush(stderr);
  }

  if (cygdrive_prefix != NULL && strlen(cygdrive_prefix) > 1 &&
      (cygpath[0] == '/' || cygpath[0] == '\\') &&
      pathstringncompare(cygpath,cygdrive_prefix,strlen(cygdrive_prefix))==0 &&
      (cygpath[strlen(cygdrive_prefix)] == '/' || cygpath[strlen(cygdrive_prefix)] == '\\')) {

    strcpy(winpathbuffer,cygpath + strlen(cygdrive_prefix));
    if (Debug > 0) {
      fprintf(stderr,"prefix found, rest is: %s\n",winpathbuffer);
      fflush(stderr);
    }
    
    if (winpathbuffer[1] != 0 && (winpathbuffer[2] == '/' || winpathbuffer[2] == '\\')) {
      winpathbuffer[0] = winpathbuffer[1];
      winpathbuffer[1] = ':';
      if (Debug > 0) {
	fprintf(stderr,"windows path is: %s\n",winpathbuffer);
	fflush(stderr);
      }
      return winpathbuffer;
    }
  }
  return cygpath;  
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
void clear_dtabsize()
{
 }
 
void init_fp()
{
	unsigned int cw, cwOriginal;

        _clearfp();	// always call _clearfp before setting the control word

	//cw = _controlfp(0, 0); //Get the default control word

	//	printf("Control word: %08x\n",cw);
	
	cw = ~(_EM_OVERFLOW|_EM_ZERODIVIDE|_EM_INVALID);

	//	printf("New mask: %08x\n",cw);

	cwOriginal = _controlfp(cw, _MCW_EM); //Set it.

	// cw = _controlfp(0, 0); //Get the default control word

        // printf("Control word: %08x\n",cw);
}

#if 0
char * rindex(s,c)
   /* look for the last occurrence of character c in string s;
      if found, return pointer to string part, NULL otherwise */
        char * s; char c;
        { int i,l; char x;
          for (i=0; s[i]!='\000'; i++);
          for (i=i-1; (s[i] !=c) && (i>=0) ; i--);
          if (i<0) return(NULL); else return(& s[i]);
        } 

char * index(s,c) 
   /* look for the first occurrence of character c in string s;
      if found, return pointer to string part, NULL otherwise */ 
        char * s; char c; 
        { int i,l; 
          for (i=0; (s[i] !=c) && (s[i]!='\000') ; i++);
          if (s[i]=='\000') return(NULL); else return(& s[i]); 
        } 
#endif

#if 0
#ifndef __GNUC__

bzero (b,length) 
char * b; int length; 
{ int i;
  for (i=0; i<length; i++) b[i]='\000' ; } 
 
#endif
#endif

