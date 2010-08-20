/*  embedcsl.c                         Copyright (C) 2010 Codemist Ltd */


/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
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



/* Signature: 0b57f866 20-Aug-2010 */

/*
 * This is just the same as csl.c with som estartup code removed so that
 * a separate file (eg driver.c) can use it.
 */

#include <stdio.h>
#include <setjmp.h>

#include "proc.h"


static char ibuff[100], obuff[100];
static int ibufp = 0, obufp = 0;

static int iget(void)
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


static void display(PROC_handle p)
{
    int ch;
    if (PROC_atom(p))
    {   if (PROC_null(p))
        {   printf("<null>");
        }
        else if (PROC_symbol(p))
        {   printf("%s", PROC_symbol_name(p));
        }
        else if (PROC_fixnum(p))
        {   printf("%d", PROC_integer_value(p));
        }
        else printf("<Unknown:%p>", p);
        return;
    }
    ch = '(';
    while (!PROC_atom(p))
    {   putchar(ch);
        ch = ' ';
        display(PROC_first(p));
        p = PROC_rest(p);
    }
    if (!PROC_null(p))
    {   printf(" . ");
        display(p);
    }
    putchar(')');
    return;
}
    

extern const char *programDir;

static int submain(int argc, char *argv[])
{
    char imageName[256], *nargv[4];
    PROC_handle p;

    sprintf(imageName, "%s/reduce.img", programDir);
    nargv[0] = argv[0];
    nargv[1] = "-i";
    nargv[2] = imageName;
    nargv[3] = NULL;
    cslstart(3, nargv, NULL);
    strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    printf("Buffered output is <%s>\n", obuff);

    PROC_clear_stack();

    PROC_push_small_integer(1);               /* 1 */
    PROC_push_symbol("x");                    /* x */
    PROC_push_small_integer(6);               /* 6 */
    PROC_make_function_call("expt",2);        /* x^6 */
    PROC_push_small_integer(1);               /* 1 */
    PROC_make_function_call("difference",2);  /* x^6-1 */
    PROC_make_function_call("quotient",2);    /* 1/(x^6-1) */

    PROC_push_symbol("x");
    PROC_make_function_call("int",2);

    PROC_simplify();

    PROC_dup();
    PROC_save(1); /* note that SAVE pops the item off the stack */

    PROC_make_printable();

    p = PROC_get_value();
    display(p);

    my_exit(cslfinish(NULL));
    return 0;
}


int main(int argc, char *argv[])
{
    int res;
    if (find_program_directory(argv[0]))
    {   fprintf(stderr, "Unable to identify program name and directory\n");
        return 1;
    }

    if (!setjmp(my_exit_buffer)) res = submain(argc, argv);
    else res = my_return_code;
    return res;
}


/* End of embedcsl.c */

