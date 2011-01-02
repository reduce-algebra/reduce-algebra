/* 
 * pwd-fn.c - System-independent hack for returning current wrking directory.
 * 
 * Author:	Russell D. Fish
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Thu Jun 30 1983
 * Copyright (c) 1983 Russell D. Fish
 *
 * Wed Mar 13 15:17:12 1985,  Robert Virding
 *  Modified to use getwd(3). This might be more 4.2BSD specific.
 */

/* getwd(3) should be defined on all 4.2bsd or compatible Unices.  If
 * it is not present and you comment out USE_GETWD, do check that popen
 * uses vfork instead of fork!  It is not going to work at all on small
 * machines, and will be very slow on big machines, to allocate a PSL
 * worth of swap space (potentially many megabytes) just to exec "pwd".
 */

#include "direct.h"  

#define MAXPATHLEN 255

char Name[MAXPATHLEN + 2];     /* Need space for '/' and a NULL at the end. */

char *
external_pwd()
{
  char *p = getcwd(Name, MAXPATHLEN);

    if (p)
	/* PSL convention, terminate directory strings with a slash. */
	strcat(Name, "\\");
    else
	/* An error occurred, just return NULL string. */
	Name[0] = 0;
    return Name;
} 
