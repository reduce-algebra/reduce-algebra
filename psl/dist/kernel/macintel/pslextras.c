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
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
 
int external_alarm(sec)
unsigned long sec;
{
  alarm(sec);
}
 
int external_ualarm(usec,repeat)
unsigned long usec,repeat;
{
  ualarm(usec,repeat);
}
 
char *expand_file_name();    /* from unix-io.c */
long time();        /* from kernel */
 
/* Tag( external_time )
 */
long external_time(tloc)
long *tloc;
{
  return (time(tloc));
}
 
/* Tag( external_timc )
 */
external_timc(buffer)
     struct tms *buffer;
{
  return(times(buffer));
}
 
/* Tag( external_stat )
 */
int external_stat(path, buf)
char *path;
struct stat *buf;
{
    return stat(expand_file_name(path), buf);
}
 
/* Tag( external_link )
 */
int external_link (path1, path2)
char *path1, *path2;
{
    return link(expand_file_name(path1), expand_file_name(path2));
}
 
/* Tag( external_unlink )
 */
int external_unlink (path)
char *path;
{
    return unlink(expand_file_name(path));
}
 
/* Tag( external_strlen )
 */
int external_strlen (s)
     char *s;
{
    return strlen(s);
}

char *getenv(const char *name);
 
/* Tag( external_getenv )
 */
char *external_getenv (name)
     char *name;
{
    return getenv(name);
}
 
 
int external_setenv (var, val)
    char *var, *val;
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
 
  block_copy((char *)environ, (char *)envnew, i * sizeof(char *));
  environ = envnew;
  strcpy(var_plus_equal_sign, var);
  strcat(var_plus_equal_sign, "=");
  return(setenv (var_plus_equal_sign, val));
}
 
/*
 * sets the value of var to be arg in the Unix environment env.
 * Var should end with '=' (bindings are of the form "var=value").
 * This procedure assumes the memory for the first level of environ
 * was allocated using calloc, with enough extra room at the end so not
 * to have to do a realloc().
 */
setenv (var, value)
     char *var, *value;
{
    extern char **environ;
    int index = 0;
    int len = strlen(var);
 
    while (environ [index] != NULL) {
        if (strncmp (environ [index], var, len) == 0) {
        /* found it */
        environ[index] = (char *)malloc (len + strlen (value) + 1);
        strcpy (environ [index], var);
        strcat (environ [index], value);
        return;
        }
        index ++;
    }
 
    environ [index] = (char *) malloc (len + strlen (value) + 1);
    strcpy (environ [index], var);
    strcat (environ [index], value);
    environ [++index] = NULL;
}
 
block_copy (b1, b2, length)
     char *b1, *b2;
     int length;
{
  while (length-- > 0)
    *b2++ = *b1++;
}
 
#define LISPEOF  4      /* Lisp uses ctrl-D for end of file */
 
/* Tag( unixreadrecord )
 */
int unixreadrecord(fp, buf)
     FILE *fp;
     char *buf;
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
int unixwriterecord(fp, buf, count)
     FILE *fp;
     char *buf;
int  count;
{
  int i;
  for (i=0; i<count; i++, buf++)
    fputc(*buf, fp);
}
 
 
 
 
 
