/*
 * Code to assist in making CSL startable from within Maple. This
 * version of the code is customised to assist with the "tay" package...
 * but variations on this code to support interfacing from Maple to
 * REDUCE or other Lisp packages could follow the same pattern.
 */

#include <stdio.h>
#include <stdarg.h>

/* Signature: 0def4e10 27-Sep-2001 */


/*
 * As of 17 Sept 2001 when I try to build a DLL for CSL for use with
 * Maple I find a moan about atexit() being undefined. Since I do not
 * really need a working version of it when CSL is called as a foreign
 * function I find the easiest fix is to provide the dummy version here.
 * But when the underlying issue is resolved this silly definition will
 * need to be removed again.
 */
int atexit(void (*fn)())
{
}
 
/*
 * The sizes of the buffers here are arbitrary and a trap for
 * the over-enthusiastic!
 */

static char ibuff[1000], obuff[100000];
static int ibufp = 0, obufp = 0;

static int iget()
{
    int c = ibuff[ibufp++];
    if (c == 0) return EOF;
    else return c;
}
 
static int iput(int c)
{
    if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
    return 0;
}


void start_csl()
{
    char *argv[5];
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
{
    Lisp_Object nil;
    Lisp_Object ff = make_undefined_symbol(fname);
    nil = C_nil;
    if (exception_pending()) return 1;  /* Failed to make the symbol */
    procedural_input = r;
    procedural_output = w;
    Lapply0(nil, ff);
    procedural_input = NULL;
    procedural_output = NULL;
    nil = C_nil;
    if (exception_pending()) return 2;  /* Failure during evaluation */
    return 0;
}

void use_csl(char *s)
{
    fprintf(stderr, "calling CSL : <%s>\n", s);
    if (strlen(s) >= sizeof(ibuff))
    {   fprintf(stderr, "Input string is too long\n");
        return;
    }
    strcpy(ibuff, s);
    ibufp = obufp = 0;
    execute_lisp_function("read_tay", iget, NULL /*iput*/);
/*  fprintf(stderr, "%s\n", obuff); */
}

int execute_lisp_function1(char *fname, Lisp_Object arg,
    character_reader *r, character_writer *w)
{
    Lisp_Object nil;
    Lisp_Object ff = make_undefined_symbol(fname);
    nil = C_nil;
    if (exception_pending()) return 1;  /* Failed to make the symbol */
    procedural_input = r;
    procedural_output = w;
    Lapply1(nil, ff, arg);
    procedural_input = NULL;
    procedural_output = NULL;
    nil = C_nil;
    if (exception_pending()) return 2;  /* Failure during evaluation */
    return 0;
}

void use_csl1(unsigned int s)
{
    ibufp = obufp = 0;
    execute_lisp_function1("maple_tay", encapsulate_pointer((void *)s),
                           iget, iput);
    fprintf(stderr, "%s\n", obuff);
    fflush(stderr);
}


/* end of maple_interface.c */


