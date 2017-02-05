//
// Code to assist in making CSL startable from within Maple. This
// version of the code is customised to assist with the "tay" package...
// but variations on this code to support interfacing from Maple to
// REDUCE or other Lisp packages could follow the same pattern.
//
// This is NOT production code - it is part of an experiment that
// Codemist was at one stage making.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdarg.h>


//
// As of 17 Sept 2001 when I try to build a DLL for CSL for use with
// Maple I find a moan about atexit() being undefined. Since I do not
// really need a working version of it when CSL is called as a foreign
// function I find the easiest fix is to provide the dummy version here.
// But when the underlying issue is resolved this silly definition will
// need to be removed again.
//
int atexit(void (*fn)())
{
}

//
// The sizes of the buffers here are arbitrary and a trap for
// the over-enthusiastic!
//

static char ibuff[1000], obuff[100000];
static int ibufp = 0, obufp = 0;

static int iget()
{   int c = ibuff[ibufp++];
    if (c == 0) return EOF;
    else return c;
}

static int iput(int c)
{   if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
    return 0;
}


void start_csl()
{   char *argv[5];
    int argc = 0;
    argv[argc++] = "/scl/people/guests/norman/rtaylor/tay";
    argv[argc++] = "-v";
    argv[argc++] = "--";
    argv[argc++] = "/scl/people/guests/norman/rtaylor/tay.out";
    obufp = 0;
    cslstart(argc, argv, iput);
    fprintf(stderr, "%s\n", obuff);
}

#include "machine.h"
#include "tags.h"
#include "externs.h"
#include "stream.h"
#include "entries.h"



int execute_lisp_function(char *fname,
                          character_reader *r, character_writer *w)
{   try
    {   START)_TRY_BLOCK;
        LispObject ff = make_undefined_symbol(fname);
        procedural_input = r;
        procedural_output = w;
        Lapply0(nil, ff);
    }
    catch (LispException e)
    {   procedural_input = NULL;
        procedural_output = NULL;
        return 1;
    }
    procedural_input = NULL;
    procedural_output = NULL;
    return 0;
}

void use_csl(char *s)
{   fprintf(stderr, "calling CSL : <%s>\n", s);
    if (strlen(s) >= sizeof(ibuff))
    {   fprintf(stderr, "Input string is too long\n");
        return;
    }
    strcpy(ibuff, s);
    ibufp = obufp = 0;
    execute_lisp_function("read_tay", iget, NULL /*iput*/);
//  fprintf(stderr, "%s\n", obuff);
}

int execute_lisp_function1(char *fname, LispObject arg,
                           character_reader *r, character_writer *w)
{   LispObject ff;
    if_error(ff = make_undefined_symbol(fname),
             return 1);  // Failed to make the symbol
    procedural_input = r;
    procedural_output = w;
    if_error(Lapply1(nil, ff, arg),
             procedural_input = NULL;
             procedural_output = NULL;
             return 2);
    procedural_input = NULL;
    procedural_output = NULL;
    return 0;
}

void use_csl1(unsigned int s)
{   ibufp = obufp = 0;
    execute_lisp_function1("maple_tay", encapsulate_pointer((void *)s),
                           iget, iput);
    fprintf(stderr, "%s\n", obuff);
    fflush(stderr);
}


// end of maple_interface.cpp

