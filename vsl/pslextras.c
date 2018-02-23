/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:PSLEXTRAS.C
% Description:  Miscellaneous support routines.
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:     21-Mar-85 11:25:52
% Mode:         Text
% Package:
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
 *     Julian Padget, Leigh Stoller, Harold Carr, Scott Marovich,
 *     Vicki O'Day
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>

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

#ifdef __linux__
#define _(x) _ ## x
#else
#define _(x) x
#endif

/*
 * "This interface is made obsolete by setitimer(2)"
 */

unsigned int _(external_alarm)(unsigned long int sec)
{   return alarm(sec);
}

int _(external_ualarm)(unsigned long int usec, unsigned long int repeat)
{   return( ualarm(usec,repeat));
}

char *_(expand_file_name)();    /* from unix-io.c */

/* Tag( external_time )
 */
time_t _(external_time)(time_t *tloc)
{   return (time(tloc));
}

/* Tag( external_timc )
 */
long _(external_timc)(struct tms *buffer)
{   return(times(buffer));
}

/* Tag( external_stat )
 */
int _(external_stat)(const char *path, struct stat *buf)
{   return stat(_(expand_file_name)(path), buf);
}


int _(external_mkdir)(const char *name, int mode)
{   return mkdir(name, mode);
}

int _(external_rmdir)(const char *name)
{   return rmdir(name);
}

/* Tag( external_link )
 */
int _(external_link)(const char *path1, const char *path2)
{   return link(_(expand_file_name)(path1), _(expand_file_name)(path2));
}

/* Tag( external_unlink )
 */
int _(external_unlink)(const char *path)
{   return unlink(_(expand_file_name)(path));
}

/* Tag( external_strlen )
 */
int _(external_strlen)(const char *s)
{   return strlen(s);
}

char *getenv(const char *name);

/* Tag( external_getenv )
 */
char *_(external_getenv)(const char *name)
{   return getenv(name);
}


int _(external_setenv)(const char *var, const char *val, int ov)
{   int i;
    extern char **environ;
    char **envnew;
    char var_plus_equal_sign[100];

    /* Look for first empty slot to find number of existing env variables. */
    for (i = 0 ; environ [i] != NULL ; i++) ;

    /* Make a new environment array with 2 new slots - 1 for var being set,
       and 1 extra empty slot. */
    envnew = (char **) calloc ((i + 2), sizeof(char *));

    bcopy((char *)environ, (char *)envnew, i * sizeof(char *));
    environ = envnew;
    strcpy(var_plus_equal_sign, var);
    strcat(var_plus_equal_sign, "=");
    return(setenv (var_plus_equal_sign, val,ov));
}

/*
 * sets the value of var to be arg in the Unix environment env.
 * Var should end with '=' (bindings are of the form "var=value").
 * This procedure assumes the memory for the first level of environ
 * was allocated using calloc, with enough extra room at the end so not
 * to have to do a realloc().
 */
int setenv(const char *var, const char *value, int ov)
{   extern char **environ;
    int index = 0;
    int len = strlen(var);

    while (environ [index] != NULL)
    {   if (strncmp (environ [index], var, len) == 0)
        {   /* found it */
            environ[index] = (void *)malloc (len + strlen (value) + 1);
            strcpy (environ [index], var);
            strcat (environ [index], value);
            return (ov);
        }
        index ++;
    }

    environ [index] = (void *) malloc (len + strlen (value) + 1);
    strcpy (environ [index], var);
    strcat (environ [index], value);
    environ [++index] = NULL;
    return 0;
}

void _(block_copy)(const char *b1, char *b2, int length)
{   while (length-- > 0)
        *b2++ = *b1++;
}

#define LISPEOF  4      /* Lisp uses ctrl-D for end of file */

/* Tag( unixreadrecord )
 */
int _(unixreadrecord)(FILE *fp, char *buf)
{   int i;
    char c;
    for (i=0, c=' '; ((c != LISPEOF) && (c != '\n')); i++)
    {   c = fgetc(fp);
        if (c == EOF )
            c = LISPEOF;
        *buf++ = c;
    }
    return i;
}

/* Tag( unixwriterecord )
 */
int _(unixwriterecord)(FILE *fp, char *buf, int count)
{   int i;
    for (i=0; i<count; i++, buf++)
        fputc(*buf, fp);
    return 0;
}


/* end of pslextras.c */



