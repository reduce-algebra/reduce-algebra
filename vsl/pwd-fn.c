/*
 * pwd-fn.c - System-independent hack for returning current wrking directory.
 *
 * Author:  Russell D. Fish
 *      Computer Science Dept.
 *      University of Utah
 * Date:    Thu Jun 30 1983
 * Copyright (c) 1983 Russell D. Fish
 * Status:      Open Source: BSD License
 *
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the relevant copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
* CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
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

#include "psl.h"

#ifdef USE_GETWD
#define MAXPATHLEN 255

#include "sys/param.h"  /* For MAXPATHLEN, the longest path that can occur. */
char Name[MAXPATHLEN + 2];     /* Need space for '/' and a NULL at the end. */

char *_(external_pwd)()
{   TR;
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

#else                   /* Popen a pwd and read its output. */

#include "stdio.h"
char Name[BUFSIZ];

char *_(external_pwd)()
{   TR;
    FILE *popen();             /* May not be in some stdio.h files. */
    FILE * PwdStream;
    char * Where, *index();

    /* Simpleminded- Popen a "pwd" cmd and read a line into Name buffer. */
    PwdStream = popen( "pwd", "r" );
    if ( PwdStream == NULL ) perror( "Pwd popen" ), abort(); /* Break loop. */
    if (fgets(Name, BUFSIZ, PwdStream) == NULL)
        printf("fgets failed %d %s\n", __LINE__, __FILE__);;
    pclose( PwdStream );

    /* Trash the newline at the end of the string and follow the PSL
     * convention that directory strings are terminated with a slash.
     */
    if ((Where = index( Name, '\n' )) != NULL)
        *Where = '/';

    return( Name );    /* To be imported from static area to a heap string. */
}
#endif

/* end of pwd-fn.c */
