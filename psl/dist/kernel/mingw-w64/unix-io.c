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

#ifndef EOF
# define EOF (-1)
#endif
#ifndef NUL
# define NUL (0)
#endif

/* Tag( unixinitio )
 */
unixinitio()
{
    unixstdin = stdin;
    unixstdout = stdout;
    unixstderr = stderr;
    unixnull[0] = NUL;
    unixnull[1] = NUL;
    unixeof[0] = EOF;
    unixeof[1] = EOF;
    unixtty = stdin;
}
 
/* Tag( unixputc )
 * Used by kernel routines that write to the console
 */
unixputc(c)
char c;
{
    fputc(c, stdout);
}
 
/* Tag( unixputs )
 */
unixputs(str)
char *str;
{
    fputs(str, stdout);
}
 
/* Tag( unixputn )
 */
unixputn(n)
long long n;
{
    fprintf(stdout, "%llx", n);
}
 
/* Tag( unixcleario )
 */
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

FILE* unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
 
  fptr = fopen(expand_file_name(filename), type);
  return(fptr);
}

unixcd(filename)
     char *filename;
{
  chdir(expand_file_name(filename));
}
 
unixfclose (ix)
FILE* ix;

{ fclose (ix); }

int
unixfflush (FILE *stream)
{
  return fflush (stream);
}

long long
unixfread (void *buffer, long long size, long long count, FILE *stream)
{
  return fread (buffer, size, count, stream);
}

int
unixfputc(int c, FILE *stream)
{
  return fputc(c, stream);
}

int
unixfgetc(FILE *stream)
{
  return fgetc (stream);
}

int
unixfputs(const char *string, FILE *stream)
{
  return fputs(string, stream);
}

char *
unixfgets(char *string, int n, FILE *stream)
{
  return fgets(string, n, stream);
}

long long
unixfwrite(const void *buffer, long long size, long long count, FILE *stream)
{
  return fwrite(buffer, size, count, stream);
}

int
unixfseek(FILE *stream, long offset, int origin)
{
  return fseek(stream, offset, origin);
}

void
unixclearerr(FILE *stream)
{
  return clearerr(stream);
}

int
unixputw(int binint, FILE *stream)
{
  return _putw(binint, stream);
}

external_system(command)
     char *command;
{
  int value;
  value = system(command);
  return(value);
}
 
/* Tag( external_exit )
 */
extern void gcleanup ();

external_exit(status)
     int status;
{
  gcleanup ();
  exit(status);
}
 
char *static_argv[20];  /* static place to hold argv so it doesn't get gc'd */
 
char **copy_argv(argc,argv)    /* copy argv into static space. */
int argc;
char *argv[];
{
  int i;
 
  for (i=0; i < argc; i++)
     static_argv[i]=argv[i];
 
  return(static_argv);
}

long long xgetw (f)
FILE* f;
{ long long a1,a2;

  a1 = (long long) getw(f);
  a2 = (long long) getw(f);
  return (a2 << 32 | a1);
}


