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
%
% Revisions:
%
% 05-Apr-88 (Julian Padget)
%  Reinstated alarm and ualarm (again)
% 29-May-87 (Leigh Stoller & Harold Carr)
%  Added external_setenv and friends.
% 21-Mar-85 11:09:00 (Scott Marovich)
%  Rewrite "timc()" to return time since 1st call, and never cream LISP tag.
% 21-Feb-85 09:02:49 (Vicki O'Day)
%  Fixed bug in uxwritefloat - it was setting the length field of the printable
%  string incorrectly.
% 18-Jul-84 11:14:24 (RAM)
%  Added external_time.  Put call to expand_file_name in external_stat,
%  external_link, and external_unlink.
% 10-Jul-84 (Vicki O'Day)
%  Added external_stat, external_link and external_unlink.
% 29-Jun-84 14:15:53 (RAM)
%  Removed hp_quit (obsolete).
% 27-Jun-84 (Vicki O'Day)
%  Added external_strlen and external_getenv.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id: pslextras.c 6307 2022-05-11 15:35:54Z schoepf $
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
 
int external_alarm(unsigned long sec)
{
  return alarm(sec);
}
 
int external_ualarm(unsigned long usec,unsigned long repeat)
{
  return( ualarm(usec,repeat));
}
 
char *expand_file_name(char *);    /* from unix-io.c */
 
/* Tag( external_time )
 */
long external_time(time_t *tloc)
{
  return (time(tloc));
}
 
/* Tag( external_timc )
 */
long
external_timc(struct tms *buffer)
{
  return(times(buffer));
}
 
/* Tag( external_stat )
 */
int external_stat(char *path, struct stat *buf)
{
    return stat(expand_file_name(path), buf);
}
 

int external_mkdir (char *name, int mode)
 { return mkdir (name, mode); }

int external_rmdir (char *name)
{ return rmdir (name); }

/* Tag( external_link )
 */
int external_link (char *path1, char *path2)
{
    return link(expand_file_name(path1), expand_file_name(path2));
}
 
/* Tag( external_unlink )
 */
int external_unlink (char *path)
{
    return unlink(expand_file_name(path));
}
 
/* Tag( external_strlen )
 */
int external_strlen (char *s)
{
    return strlen(s);
}

char *getenv(const char *name);
 
/* Tag( external_getenv )
 */
char *external_getenv (char *name)
{
    return getenv(name);
}
 
 
int external_setenv (char *var, char *val, int ov)
{
  int i;
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
  strncpy(var_plus_equal_sign, var, 99);
  strncat(var_plus_equal_sign, "=", 1);
  return(setenv (var_plus_equal_sign, val,ov));
}
 
/*
 * sets the value of var to be arg in the Unix environment env.
 * Var should end with '=' (bindings are of the form "var=value").
 * This procedure assumes the memory for the first level of environ
 * was allocated using calloc, with enough extra room at the end so not
 * to have to do a realloc().
 */
int
setenv (const char *var, const char *value, int ov)
{
    extern char **environ;
    int index = 0;
    int len = strlen(var);
 
    while (environ [index] != NULL) {
        if (strncmp (environ [index], var, len) == 0) {
        /* found it */
        environ[index] = (void *)malloc (len + strlen (value) + 1);
        strncpy (environ [index], var, len + strlen (value) + 1);
        strncat (environ [index], value, strlen(value));
        return (ov);
        }
        index ++;
    }
 
    environ [index] = (void *) malloc (len + strlen (value) + 1);
    strncpy (environ [index], var, len + strlen (value) + 1);
    strncat (environ [index], value, strlen(value));
    environ [++index] = NULL;
    return 0;
}

void
block_copy (char *b1, char *b2, int length)
{
  while (length-- > 0)
    *b2++ = *b1++;
}
 
#define LISPEOF  4      /* Lisp uses ctrl-D for end of file */
 
/* Tag( unixreadrecord )
 */
int unixreadrecord(FILE *fp, char *buf)
{
  int i;
  char c;
  for (i=0, c=' '; ((c != LISPEOF) && (c != '\n')); i++)
    {
      c = fgetc(fp);
      if (c == EOF )
    c = LISPEOF;
      *buf++ = c;
    }
  return i;
}
 
/* Tag( unixwriterecord )
 */
void unixwriterecord(FILE *fp, char *buf, int count)
{
  int i;
  for (i=0; i<count; i++, buf++)
    fputc(*buf, fp);
}
 
 
 
 
 
