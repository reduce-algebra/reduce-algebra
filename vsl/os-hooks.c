/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
* Author:       RAM, HP/FSD
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
* Status:       Open Source: BSD License
*
*  (c) Copyright 1983, Hewlett-Packard Company, see the file
*             HP_disclaimer at the root of the PSL file tree
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
*/

/*
 * There used to be a collection of comments here describing revisions
 * made from about 1982 to 1989. I think those are by now of interest
 * to archaeologists! So anybody who wants to see them can consult older
 * copies of this file in the repositories. It is neverthless proper to
 * record the names of those who (in addition to the original author)
 * have contributed:
 *     Chris Burdorf, Tsuyoshi Yamamoto, Leight Stoller
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#include "psl.h"

#if defined __linux__ || defined __CYGWIN__
#define _(x) _ ## x
#else
#define _(x) x
#endif


jmp_buf mainenv;
char *abs_execfilepath;

void clear_iob(), clear_dtabsize();

void _(psl_main)(int argc, char *argv[]);

char **_(copy_argv)();

int Debug = 0;

int main(int argc, char *argv[])
{   TR1("main");
    int val;

    clear_iob();             /* clear garbage pointer in _iob[]    */
    clear_dtabsize();
    /* fpsetround(FP_RZ);  */
    /*  init_malloc_param(); */       /* reset malloc parameters.        */
    setvbuf(stdout,NULL,_IOLBF,BUFSIZ);
    /* Record path to exec file */
    if (argc > 0)
        abs_execfilepath = realpath(argv[0],NULL);

    if (getenv("BPSL_DEBUG") != NULL)
        Debug = 1;

    val=setjmp(mainenv);        /* set non-local return point for exit    */

    if (val == 0)
        _(psl_main)(argc,_(copy_argv)(argc, argv));

    exit(0);

}


int setupbpsandheap(int argc, char *argv[]);

void _(os_startup_hook)(int argc, char *argv[])
{   TR1("os_startup_hook");
    setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}

void _(os_cleanup_hook)()
{   TR1("os_cleanup_hook");
    longjmp(mainenv,1);
}

char *_(get_execfilepath)()
{   TR1("get_execfilepath");
    return abs_execfilepath;
}

void clear_iob()
{   TR1("clear_iob");
 
}

/*
 *    Some static area must be initialized on hot start.
 *    There may be other area to be initialized but we have no idea
 *    to know them.
 *
 *    _dtabsize ----_end
 */

extern char *end;

/*
 *     Size of dtabsize is 0x34c bytes.
 */
void clear_dtabsize()
{   TR1("clear_dtabsize");
}

/* end of os-hooks.c */
