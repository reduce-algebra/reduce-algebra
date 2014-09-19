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
% Copyright (c) 1984 Hewlett-Packard Company, all rights reserved.
% Copyright (c) 1984 University of Utah
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
 
/* There is an assumption here that coercing addresses into ints is OK */
/*
asm("   alias   _unixstdin,unixstdin");
asm("   alias   _unixstdout,unixstdout");
asm("   alias   _unixstderr,unixstderr");
asm("   alias   _unixnull,unixnull");
asm("   alias   _unixeof,unixeof");
asm("   alias   _unixtty,unixtty");
*/
/* Initialize some PSL external variables with FileDescriptors for SysClearIO.
 */
extern FILE * unixstdin, * unixstdout, * unixstderr, * unixtty;
 
/* Import NULL and EOF constants for error returns from stdio fns.
 */
extern long long unixnull, unixeof;
 
/* Tag( unixinitio )
 */
unixinitio()
{
    unixstdin = stdin;
    unixstdout = stdout;
    unixstderr = stderr;
    unixnull = NULL;
    unixeof = EOF;
    unixtty = fopen("/dev/tty", "r");
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
    fprintf(stdout, "%l016x", n);
}

long long xgetw (FILE *stream)

{ long aa,bb;
  long long hilf;
  aa = getw(stream) ;
  bb = getw (stream);
  hilf = aa;
  hilf =  ((hilf << 32) | bb);
/* unixputn (hilf);
printf("\n");a*/
  return (hilf);
  }
 
/* Tag( unixcleario )
 */
unixcleario()
{
    unixinitio();
    /* set the stdin, stdout and stderr buffers to be empty */
   /* stdin->_cnt = 0;
    stdin->_ptr = stdin->_base;
    stdout->_cnt = 0;
    stdout->_ptr = stdout->_base;
    stderr->_cnt = 0;
    stderr->_ptr = stderr->_base;
   */
    setvbuf(stdout,NULL,_IOLBF,BUFSIZ);
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
  while (*c++ = *s++);
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
          if (tilde) { t = ((getpwuid(getuid())) -> pw_dir);
                       if (t == NULL) return(fname); }
        }
          else
            {
          save = *e;
              *e = '\0';
              if (tilde)
                {
          if (p = getpwnam(s))  t = (p -> pw_dir);
        }
              else
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
 

extern int errno;
 
/* Tag( unixopen )
 */
FILE* unixopen(filename, type)
     char *filename, *type;
{
  FILE* fptr;
 
  fptr =  fopen(expand_file_name(filename), type);
  return(fptr);
}
 
/* Tag( unixcd )
 */
unixcd(filename)
     char *filename;
{
  return(chdir(expand_file_name(filename)));
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
 
/* Tag( external_exit )
 */
external_exit(status)
     int status;
{
  exit(status);
}
 
char *static_argv[20];  /* static place to hold argv so it doesn't get gc'd */
 
char ** copy_argv(argc,argv)    /* copy argv into static space. */
int argc;
char *argv[];
{
  int i;
 
  for (i=0; i < argc; i++)
     static_argv[i]=argv[i];
 
  return(static_argv);
}
