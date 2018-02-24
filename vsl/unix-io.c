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
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *     T. Yamamoto, C. Burdorf, Leigh Stoller, RAM, Vicki O'Day
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <errno.h>

/*
 * The functions here are (just) called from compiled code. In the
 * assembly code for the kernel the code is written with the names
 * having a leading underscore. For Linux that underscore remains
 * visible here in the C code that is linked to, while under Cygwin
 * or on a Macintosh it is not. So here I define functions whose names
 * have leading underscores if I am on Linux but not otherwise. This is
 * a bit messy and ugly but is still about the neatest I can think of
 * at present if I want one body of code to apply everywhere.
 */

#if defined __linux__ || defined __CYGWIN__
#define _(x) _ ## x
#else
#define _(x) x
#endif



/* There is an assumption here that coercing addresses into ints is OK */

/* Initialize some PSL external variables with FileDescriptors for SysClearIO.
 */

extern FILE *_(unixstdin), *_(unixstdout), *_(unixstderr), *_(unixtty);

/* Import NULL and EOF constants for error returns from stdio fns.
 */
extern int _(unixnull)[2], _(unixeof)[2];

/* Tag( unixinitio )
 */
void _(unixinitio)()
{   _(unixstdin) = stdin;
    _(unixstdout) = stdout;
    _(unixstderr) = stderr;
    _(unixnull)[0] = (long) NULL;  /* Dodgy??? */
    _(unixnull)[1] = (long) NULL;
    _(unixeof)[0] = EOF;
    _(unixeof)[1] = EOF;
    _(unixtty) = fopen("/dev/tty", "r");
}

/* Tag( unixputc )
 * Used by kernel routines that write to the console
 */
void _(unixputc)(int c)
{   fputc(c, stdout);
}

/* Tag( unixputs )
 */
void _(unixputs)(const char *str)
{   fputs(str, stdout);
}

/* Tag( unixputn )
 */
void _(unixputn)(int64_t n)
{   fprintf(stdout, "%" PRId64, n);
}

/* Tag( unixcleario )
 */
void _(unixcleario)()
{   _(unixinitio)();

#if 0
    /* This is what the code use to do in non-Linux cases. For now I will
       comment it out but eventually I will need Windows and Macintosh
       code to tidy up...
     */
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
#define LONGEST_LEGAL_FILENAME 255
char collect[LONGEST_LEGAL_FILENAME], copy[LONGEST_LEGAL_FILENAME];
/* Made global so it won't be overwritten
   Used to be local to expand_file_name.
   Involves a buffer-overrun risk. */

/* Tag( expand_file_name )
 */
char *_(expand_file_name)(const char *fname)
{   char *c, *t, *e, *s, save;
    struct passwd *p;
    register int tilde;
    strcpy(copy, fname);
    s = copy;
    c = collect;
    *c = '\0';
    while (*s)
    {   if ((tilde = (*s == '~')) || (*s == '$'))
        {   for (e = ++s; (*e != '/' && *e != '\0' && *e != '$'); e++)
                ;
            t = 0;                        /* default initialization */
            if (e == s)
            {   if (tilde) t = ((getpwuid(getuid())) -> pw_dir);
            }
            else
            {   save = *e;
                *e = '\0';
                if (tilde)
                {   if ((p = getpwnam(s)) != NULL)  t = (p -> pw_dir);
                }
                else
                    t = getenv(s);
                *e = save;
                s = e;
            }
            if (t)
                while ((*c++ = *t++) != 0)
                    ;
            else
            {   strcpy(copy, fname);
                return(copy);   /* name not found, just return original fname */
            }
            c--;
        }
        for (; (*s != '\0' && *s != '$'); *c++ = *s++)
            ;
        *c = '\0';
    }
    return (collect);
}

extern int errno;

FILE *_(unixopen)(const char *filename, const char *type)
{   printf("\nunixopen \"%s\" \"%s\"\n", filename, type);
    return fopen(_(expand_file_name)(filename), type);
}

int _(unixcd)(const char *filename)
{   return chdir(_(expand_file_name)(filename));
}

int _(unixfclose)( FILE *ix)
{   return fclose(ix);
}

int _(external_system)(const char *command)
{   return system(command);
}

/* Tag( external_exit )
 */
int _(external_exit)(int status)
{   exit(status);
    return 0;
}

/* This allows for up to 20 entries and then overflows... */
char *static_argv[20];  /* static place to hold argv so it doesn't get gc'd */

char **_(copy_argv)(int argc, char *argv[]) /* copy argv into static space. */
{   int i;
    for (i=0; i < argc; i++)
        static_argv[i]=argv[i];
    return(static_argv);
}

/* convert a pathname to canonical form */
char *_(external_fullpath)(const char *relpath)
{   return realpath(relpath,NULL);
}

int64_t _(xgetw)(FILE *f)
{   int64_t a1,a2;

    a1 = (int64_t) getw(f);
    a2 = (int64_t) getw(f);
    return ((a2 << 32) | a1);
}

/* end of unix-io.c */

