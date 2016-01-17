/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXCC:UNIX-IO.C
% Description:  Unix PSL FileDescriptors are implemented as stdio streams
%                 ("FILE *".)
% Author:       Russell D. Fish
% Created:      Thu Feb 16 1984
% Modified:     17-Jul-84 22:49:12 (RAM)
% Mode:         Text
% Package:
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 15-Sep-88 (T. Yamamoto and C. Burdorf)
%  Moved collect out of expand_file_name so it won't be overwritten as a
%  local before it is referenced.
% 20-Sep-86 (Leigh Stoller)
%  Removed assembler alias statements because they are not portable. Instead,
%  a sed script will be used to convert the _variables of C to VARIABLES of
%  PSL.
% 17-Jul-84 22:48:32 (RAM)
%  Added unixcd, a routine that calls expand_file_name before calling chdir.
% 3-Jul-84 10:45:57 (RAM)
%  Added expand_file_name (called from unixopen) to expand shell variable
%  references and ~ home directory syntax.
% 29-Jun-84 14:21:21 (RAM)
%  Added unixputs and unixopen.
% 21-May-84 17:41:41 (Vicki O'Day)
%  Added unixcleario.  It is called by syscleario.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 
/* There is an assumption here that coercing addresses into ints is OK */
/*
asm("   alias   _unix_stdin,UNIXSTDIN");
asm("   alias   _unix_stdout,UNIXSTDOUT");
asm("   alias   _unix_stderr,UNIXSTDERR");
asm("   alias   _unix_null,UNIXNULL");
asm("   alias   _unix_eof,UNIXEOF");
asm("   alias   _unix_tty,UNIXTTY");
*/
/* Initialize some PSL external variables with FileDescriptors for SysClearIO.
 */

extern FILE * unixstdin, * unixstdout, * unixstderr, * unixtty;

/* Import NULL and EOF constants for error returns from stdio fns.
 */
extern int unixnull[2], unixeof[2];

/* Tag( unixinitio )
 */
void
unixinitio()
{
    unixstdin = stdin;
    unixstdout = stdout;
    unixstderr = stderr;
    unixnull[0] = (long) NULL;
    unixnull[1] = (long) NULL;
    unixeof[0] = EOF;
    unixeof[1] = EOF;
    unixtty = fopen("/dev/tty", "r");
}
 
/* Tag( unixputc )
 * Used by kernel routines that write to the console
 */
void
unixputc(c)
char c;
{
    fputc(c, stdout);
}
 
/* Tag( unixputs )
 */
void
unixputs(str)
char *str;
{
    fputs(str, stdout);
}
 
/* Tag( unixputn )
 */
void
unixputn(n)
long long n;
{
    fprintf(stdout, "%llx", n);
}
 
/* Tag( unixcleario )
 */
void
unixcleario()
{
    unixinitio();

#ifndef LINUX
    /* set the stdin, stdout and stderr buffers to be empty */
    stdin->_cnt = 0;
    stdin->_ptr = stdin->_base;
    stdout->_cnt = 0;
    stdout->_ptr = stdout->_base;
    stderr->_cnt = 0;
    stderr->_ptr = stderr->_base;
#endif

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
 
#include <pwd.h>
struct passwd *getpwuid();
struct passwd *getpwnam();
char *getenv();
char collect[255], copy[255];  /* Made global so it won't be overwritten
                  Used to be local to expand_file_name */
 
/* Tag( expand_file_name )
 */
char *expand_file_name(fname)
char *fname;
{
  register char *c, *t, *e, *s, save;
  struct passwd *p;
  register int tilde;
  c = copy;
  s = fname;
  while ((*c++ = *s++));
  s = copy;
  c = collect;
  *c = '\0';
  while (*s)
    {
      if ((tilde = (*s == '~')) || (*s == '$'))
        {
      for (e = ++s; (*e != '/' && *e != '\0' && *e != '$'); e++)
        ;
          t = 0;                        /* default initialization */
          if (e == s)
            {
          if (tilde) t = ((getpwuid(getuid())) -> pw_dir);
        }
          else
            {
          save = *e;
              *e = '\0';
              if (tilde)
                {
          if ((p = getpwnam(s)))  t = (p -> pw_dir);
        }
              else
                t = getenv(s);
              *e = save;
              s = e;
            }
          if (t)
        while ((*c++ = *t++))
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
 
extern int errno;
 

FILE* unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
 
  fptr = fopen(expand_file_name(filename), type);
  return(fptr);
}

/*
FILE* unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
 
  //  printf("open %s %s ",filename,type);    
  fptr = fopen(expand_file_name(filename), type);
  if(fptr==(int)NULL)
  { // try file name in dos syntax * /
    char c,nfname[255];
    int i,j,k,kmax;
    //  printf("open failed %s %s ",filename,type); 
    k=0;kmax=8;j=0;
    for(i=0;filename[i];i++)
    { c=filename[i]; nfname[j++]=c; k++; 
      if(c == '\\')     {k=0; kmax=8;}
      else if(c == '.') {k=0; kmax=3;}
      else if(k > kmax) j--;
    };
    nfname[j]='\0';
    //   printf(" reformatted  %s  ",nfname);
    fptr = (int) fopen(expand_file_name(nfname), type);
    //   printf(" --> %x\n",fptr);
  };
  return(fptr);
}
*/


void
unixcd(filename)
     char *filename;
{
  chdir(expand_file_name(filename));
}
 
int
unixfclose (ix)
FILE* ix;

{ return fclose (ix); }

int
external_system(command)
     char *command;
{
  int value;
  value = system(command);
  return(value);
}
 
/* Tag( external_exit )
 */
int
external_exit(status)
     int status;
{
  exit(status);
}
 
char *static_argv[20];  /* static place to hold argv so it doesn't get gc'd */
 
long long int copy_argv(argc,argv)    /* copy argv into static space. */
int argc;
char *argv[];
{
  int i;
 
  for (i=0; i < argc; i++)
     static_argv[i]=argv[i];
 
  return((long long int)static_argv);
}

/* convert a pathname to canonical form */
char *
external_fullpath(relpath)
     char * relpath;
{
  return realpath(relpath,NULL);
}

long long xgetw (f)
FILE* f;
{ long long a1,a2;

  a1 = (long long) getw(f);
  a2 = (long long) getw(f);
  return (a2 << 32 | a1);
}


