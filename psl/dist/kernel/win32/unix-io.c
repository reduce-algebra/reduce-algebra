/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:UNIX-IO.C
% Description:  Unix PSL FileDescriptors are implemented as stdio streams
%                 ("FILE *".)
% Author:       Russell D. Fish
% Created:      Thu Feb 16 1984
% Modified:     17-Jul-84 22:49:12 (RAM)
% Mode:         Text
% Package:
% Status:       Experimental (Do Not Distribute)
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
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
%
% Revisions:
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#ifndef __GNUC__
#include <direct.h>
#endif
/*#include <excpt.h>*/

#define TOGGLE 26   
#define ACKCHAR 5 

#ifdef ALPHA
#define LONG __int64
#define ADDRESSINGUNITSPERITEM 8
typedef LONG FPTYPE;
#else
#define LONG long
#define ADDRESSINGUNITSPERITEM 4
typedef FILE * FPTYPE;
#endif

/* Initialize some PSL external variables with FileDescriptors */

extern FPTYPE  unixstdin, unixstdout, unixstderr, unixtty;

#define MAXPIPE 5

extern FILE * scriptin, * scriptout; 


extern long hpipe[];

extern jmp_buf mainenv;
extern int script_mode;
extern int pipe_mode;

/* Import NULL and EOF constants for error returns from stdio fns.
 */
extern LONG unixnull, unixeof;
 
extern my_pwrite(char *buf, int len);
extern my_pread(char *buf, int len);
extern long pipe_write(HANDLE, LPSTR, long);

unixinitio()
{
#ifdef ALPHA
    unixstdin = (LONG) stdin;
    unixstdout = (LONG) stdout;
    unixstderr = (LONG) stderr;
    unixnull = (LONG)NULL;
    unixeof = (LONG)EOF;
    unixtty = (LONG)stdin; 
#else
    unixstdin = stdin;
    unixstdout = stdout;
    unixstderr = stderr;
    unixnull = (int)NULL;
    unixeof = EOF;
    unixtty = stdin; /* fopen("/dev/tty", "r"); */

// set two digit exponent like in unix
   _set_output_format(_TWO_DIGIT_EXPONENT);
#endif
}

wputs(char * s,LONG n) 
  {
    int i;
    if(pipe_mode)
	my_pwrite(s,n);
    else
	for(i=0;i<n;i++) fputc(*s++,stdout);
  }


char * my_gets(char * s)
  {
    if(pipe_mode)
	return(my_pread(s,255),s);
    else
	return(fgets(s,255,stdin));
  }


my_puts(char *s)
  {
    if(pipe_mode)
	my_pwrite(s,strlen(s));
    else
	while (*s) fputc(*s++,stdout);
  }


unixputc(c)
char c;
{
   if(scriptout) fputc(c,scriptout);
   if(!script_mode) wputs(&c,1L);
}
 

unixputs(str)
char *str;
{  
    if(!script_mode) wputs(str,(LONG)strlen(str));
    if(scriptout) fputs(str, scriptout);
}
 

unixputn(n)
LONG n;
{
    char buf[10];
#ifdef ALPHA
    sprintf(buf, "%Lx", n);
#else
    sprintf(buf, "%lx",n);
#endif
    unixputs(buf);
}
 
extern char bps[];

unixfread(char*buf, LONG size,LONG count, FILE*fp)
   { 
     if((FPTYPE)fp == unixstdin)   
     {
       if(scriptin) return(fread(buf,size,count,scriptin));
	else return((LONG)my_gets(buf));
     }
     { long l;
       l = fread(buf,size,count,fp);
       if(l != count)
       {  printf("fread %lx %lx\n",size,count);
	  unixputs("#### error fread: instead of ");
	  unixputn(count);
	  unixputs(" words only ");
	  unixputn(l);
	  unixputs("transmitted\n"); 
       };
     /* */
       return(l);
      }
   }

isapipe(FILE*fp)
   {
     unsigned long ifp; int i;
 
     ifp = (unsigned long)fp;
     for (i=0;i<MAXPIPE; i++) 
	if (hpipe[i]==ifp) return(i+1);
     return(0);
   }

unixfputc(char ch,FILE*fp)
   {
     
     if(isapipe(fp)) pipe_write(fp,&ch,1L); else
     if((FPTYPE)fp == unixstdout)
       { 
	 if(!script_mode) wputs(&ch,1L); 
	 if(scriptout) fputc(ch,scriptout);
       }
     else fputc(ch,fp);
   }

unixfgetc(FILE*fp)
   {
     if((FPTYPE)fp == unixstdin) unixputc(TOGGLE);  
     return(fgetc(fp));
   }

LONG unixfgets(char*buf,LONG count,FILE*fp)
   {
     if((FPTYPE)fp == unixstdin) 
     { 
       if(scriptin) return((LONG)fgets(buf,count,scriptin));
       return((LONG)my_gets(buf));
     }
     return((LONG)fgets(buf,(size_t)count,fp));
   }

unixfwrite(char*buf,int len,int count,FILE*fp)
   {
     if(isapipe(fp)) pipe_write(fp,buf,(LONG)(len*count)); 
      else
     if((FPTYPE)fp == unixstdout)
       { 
	 if(!script_mode) wputs(buf,(LONG)(len*count)); 
	 if(scriptout) fwrite(buf,len,count,scriptout);
       }
     else fwrite(buf,len,count,fp);
   }

unixfflush(FILE*fp)
   {
     if(isapipe(fp)) return 0; else
     if((FPTYPE)fp == unixstdout)
       {
	 if (scriptout) return(fflush(scriptout));
         return(fflush(fp));
       }
       else
     return(fflush(fp));
   }



unixcleario()
{
    unixinitio();
}
 
/* The function expand_file_name is used to expand shell variable references
   and ~ notation for directories in file names before calling fopen.
   This eliminates the need for the HPUX-PATH and VAX-PATH kludges that were
   once required, however, such a mechanism may still be used to override the
   values supplied by the shell environment.  The file name is first copied
   to a temporary copy because the parsing algorithm must write into the
   string (this may change).  For now, the maximum string length supported
   is 255 characters, but no checking is done to see if this is exceeded.
   $ and ~ variables are expanded in one pass by calling the functions getenv,
   getuid, getpwuid, and getpwnam.  If any expansion fails, the original
   string is returned.
*/
 
#include <stdlib.h>

char collect[255], copy[255];  /* Made global so it won't be overwritten 
				  Used to be local to expand_file_name */

/* Tag( expand_file_name )
 */
char *expand_file_name(fname)
char *fname;
{
  char *c, *t, *e, *s, save;
  c = copy;
  s = fname;
  while (*c++ = *s++);
  s = copy;
  c = collect;
  *c = '\0';
  while (*s)
    {
      if (*s == '$')
	{
	  for (e = ++s; (*e != '/' && *e != '\\'  && *e != '.'
			  && *e != '\0' && *e != '$'); e++)
	    ;
	  t = 0;                        /* default initialization */
	    {
	      save = *e;
	      *e = '\0';
	      t = getenv(s);
	      *e = save;
	      s = e;
	    }
	  if (t)
	    while (*c++ = *t++)
	      ;
	  else
	    return(fname);   /* name not found, just return original fname */
	  c--;
	}
    for (; (*s != '\0' && *s != '$'); *c++ = *s++)
      ;
      *c = '\0';
  }
  return (collect);
}

FILE * unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;

  fptr = fopen(expand_file_name(filename), type);
  return fptr;
}

#if 0
FILE * unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
  char * line[100];
 
  /*  sprintf(line,"open %s %s ",filename,type); my_puts(line); /**/    
  fptr =  fopen(expand_file_name(filename), type);
  if(fptr==(FILE*)NULL)
  { /* try file name in dos syntax */
    char c,nfname[255];
    int i,j,k,kmax,l,dotpos;
    /*   sprintf(line,"\nopen failed %s %s\n",filename,type); my_puts(line); /**/
/*    k=0;kmax=8;j=0;
    for(i=0;filename[i];i++)
    { c=filename[i]; nfname[j++]=c; k++; 
      if((c == '\\') || ( c == '/'))    {k=0; kmax=8;}
      else if(c == '.') {if(kmax==3) {j--;k=4;} else k=0; kmax=3;}
      else if(k > kmax) j--;
    };
    nfname[j]='\0';
*/
  dotpos = -1;
  l = strlen(filename);  // points at trailing 0 and thus admits ""
  for (i = l;
       i != 0 && filename[i-1] != '\\' && filename[i-1] != '/';
       i--)
    if (filename[i] == '.')
      dotpos = i;
  // filename[i] is the first char of the filename
  // filename[dotpos] is the first dot in the filename (or still -1)
       for (j = 0; j < i; j++)
         nfname[j] = filename[j];
       for (j = 0; j < dotpos && j < 8; j++)
          nfname[i+j] = filename[i+j];
       if (dotpos == -1) for (j = 0; j < l && j < 8; j++)
          nfname[i+j] = filename[i+j];
       if (dotpos != -1) {
            i += j;
            nfname[i] = '.';
            for (j = 1; j <= 3 && dotpos + j < l; j++)
                      nfname[i+j] = filename[dotpos+j];
  }
       nfname[i+j] = (char)0;
  
 //  printf(" reformatted  %s \n",nfname); 
    fptr =  fopen(expand_file_name(nfname), type);
  };
    /*  sprintf(line," --> %x\n",fptr); my_puts(line); /**/
  return(fptr);
}

FILE * old_unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
  char * line[200];
 
  /*  sprintf(line,"open %s %s ",filename,type); my_puts(line); /**/    
  fptr =  fopen(expand_file_name(filename), type);
  if(fptr==(FILE*)NULL)
  { /* try file name in dos syntax */
    char c,nfname[255];
    int i,j,k,kmax;
    /*   sprintf(line,"\nopen failed %s %s\n",filename,type); my_puts(line); /**/
    k=0;kmax=8;j=0;
    for(i=0;filename[i];i++)
    { c=filename[i]; nfname[j++]=c; k++; 
      if((c == '\\') || ( c == '/'))    {k=0; kmax=8;}
      else if(c == '.') {if(kmax==3) {j--;k=4;} else k=0; kmax=3;}
      else if(k > kmax) j--;
    };
    nfname[j]='\0';
   /* sprintf(line," reformatted  %s \n",nfname); my_puts(line); */ 
    fptr =  fopen(expand_file_name(nfname), type);
  };
    /*  sprintf(line," --> %x\n",fptr); my_puts(line); /**/
  return(fptr);
}
#endif


unixcd(filename)
     char *filename;

{
#ifdef WINPSL
   my_cd(filename,1);
#else
   return(_chdir(filename));
#endif
}
 
/* Tag( external_system )
 */
external_system(command)
     char *command;
{
  int value;
  value = system(command);
  return(value);
}
 

external_exit(status)
     int status;
{
  if(status>=0) status=1+status; else status=1;
  longjmp(mainenv,status);
  exit(status);
}
 
char *static_argv[20];  /* static place to hold argv so it doesn't get gc'd */
 
copy_argv(argc,argv)    /* copy argv into static space. */
int argc;
char *argv[];
{
  int i;
 
  /*  KNALL(argc,NULL);  */

  for (i=0; i <= argc; i++)
     static_argv[i]=argv[i];
 
  return((int)static_argv);
}


/***************************

KNALL(argc,argv)   
int argc;
char *argv[];
{
  int i;
 
printf("jetzt knallts\n");
argv[-1][15] =0;

  for (i=0; i <= argc; i++)
     static_argv[i]=argv[i];
 
  return(static_argv);
}

********************************/

LONG unixgetw(FILE * f)
   { 
     LONG pu;
     size_t r;

     //    sprintf(line,"call unixgetw %lx\n",(long)f); my_puts(line); 
     r=(long)fread((char*)&pu,(size_t)ADDRESSINGUNITSPERITEM,(size_t)1,f);
     if (r<1)
     {
	 char line[100];
	 sprintf(line,"error binary read word length=%x, value=%x\n",r,pu);
	 my_puts(line);
      } 
     return(pu);
   }


unixputw(LONG w,FILE * f)
   { 
     fwrite((char*)&w,ADDRESSINGUNITSPERITEM,1,f);
     return(1);
   }


FILE *popen(const char *command, const char *type)
{
  return _popen(command,type);
}

int pclose(FILE *stream)
{
  return _pclose(stream);
}


