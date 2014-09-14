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

#include <stdlib.h>

#ifdef USE_GETWD
#define MAXPATHLEN 255

#include "sys/param.h"	/* For MAXPATHLEN, the longest path that can occur. */
char Name[MAXPATHLEN + 2];     /* Need space for '/' and a NULL at the end. */

char *
external_pwd()
{
    char *getwd();
    char *p = getwd(Name);

    if (p)
	/* PSL convention, terminate directory strings with a slash. */
	strcat(Name, "/");
    else
	/* An error occurred, just return NULL string. */
	Name[0] = 0;
    return Name;
} 

#else					/* Popen a pwd and read its output. */

#include "stdio.h"
char Name[BUFSIZ];

char *
external_pwd()
{
    FILE *popen();		       /* May not be in some stdio.h files. */
    FILE * PwdStream;
    char * Where, *index();

    /* Simpleminded- Popen a "pwd" cmd and read a line into Name buffer. */
    PwdStream = popen( "pwd", "r" );
    if ( PwdStream == NULL ) perror( "Pwd popen" ), abort(); /* Break loop. */
    fgets( Name, BUFSIZ, PwdStream );
    pclose( PwdStream );

    /* Trash the newline at the end of the string and follow the PSL
     * convention that directory strings are terminated with a slash.
     */
    if ( (Where = index( Name, '\n' ) ) )
	*Where = '/';

    return( Name );    /* To be imported from static area to a heap string. */
}
#endif
