//  driver.cpp                                  Copyright (C) 2022 Codemist


/**************************************************************************
 * Copyright (C) 2022, Codemist                          A C Norman       *
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

//
// This is code that starts up Reduce and exercises it using a
// procedural rather than textual interface.
//

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

#include "proc.h"


static char ibuff[100], obuff[10000];
static int ibufp = 0, obufp = 0;

static int iget()
{   int c = ibuff[ibufp];
    if (c == 0) return EOF;
    ibufp++;
    return c;
}

static int iput(int c)
{   if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
    return 0;
}

static int iget1()
{   printf("Bad call to iget1()\n");
    return EOF;
}

static int iput1(int c)
{   putchar(c);
    return 0;
}

static void display(PROC_handle p)
{   int ch;
    if (PROC_atom(p))
    {   if (PROC_null(p))
        {   std::printf("<null>");
        }
        else if (PROC_symbol(p))
        {   std::printf("%s", PROC_symbol_name(p));
        }
        else if (PROC_string(p))
        {   std::printf("\"%s\"", PROC_string_data(p));
        }
        else if (PROC_fixnum(p))
        {   std::printf("%d", PROC_integer_value(p));
        }
        else std::printf("<Unknown:%p>", p);
        return;
    }
    ch = '(';
    while (!PROC_atom(p))
    {   std::putchar(ch);
        ch = ' ';
        display(PROC_first(p));
        p = PROC_rest(p);
    }
    if (!PROC_null(p))
    {   std::printf(" . ");
        display(p);
    }
    std::putchar(')');
    return;
}


//
// I check return codes and if one of the calls into Reduce reports
// trouble I pass the code back with the line number on which it was
// provoked packed in. You may have some better idea about what to do
// with any failures.
//

#define E(x) if (rc=(x)) return (rc*1000000 + __LINE__)

int obey_lisp_from_string(const char *s)
{   int rc;
    E(PROC_push_string(s));
// Turn the string into a list of characters (omitting the quote marks)
    E(PROC_make_function_call("explodec",1));
// In CSL "compress" is "read-from list"
    E(PROC_make_function_call("compress",1));
// The above is code that constructs something to evaluate, so I need
// double evaluation to get anything to happen!
    E(PROC_make_function_call("eval",1));
// Now evaluate the expression I have built.
    E(PROC_lisp_eval());
// EVAL leaves a result on the stack - I do not need it.
    E(PROC_pop());
    return 0; // success here
}

int testcase()
{   PROC_handle p;
    int rc;
//
// I enable GC messages here because I want there to be something
// sent back via the writer callback. Most people would probably
// explicitly switch gc messages off here!
//
    E(PROC_gc_messages(1));      // Messages from garbage collector etc
    E(PROC_set_switch("int",
                      0));// Running in "batch" mode, so do not even
    // attempt to make any interactive queries
    // about anything.
    //
    E(PROC_load_package("int")); // "int" would in fact autoload, but this
    // demonstrates how to load it manually.
    //

    E(PROC_clear_stack());

    E(PROC_push_small_integer(1));               // 1
    E(PROC_push_symbol("x"));                    // x
    E(PROC_push_small_integer(6));               // 6
    E(PROC_make_function_call("expt",2));        // x^6
    E(PROC_push_small_integer(1));               // 1
    E(PROC_make_function_call("difference",2));  // x^6-1
    E(PROC_make_function_call("quotient",2));    // 1/(x^6-1)

    E(PROC_push_symbol("x"));
    E(PROC_make_function_call("int",2));

    E(PROC_simplify());

    E(PROC_dup());
    E(PROC_save(1)); // note that SAVE pops the item off the stack

    E(PROC_make_printable());
    p = PROC_get_value();
    display(p);

    E(PROC_load(1));
    E(PROC_push_symbol("x"));
    E(PROC_make_function_call("df",2));  // To differentiate it
    E(PROC_simplify());
    E(PROC_make_printable());
    display(PROC_get_value());           // with luck this is 1/(x^6-1)

// Here is an illustration of passing a bit of Lisp in a string! The
// initial string contains pretty well arbitrary Lisp stoff. This represents
// a pretty-well absolute escape scheme and I hope it is not used at all
// often.
    E(obey_lisp_from_string("(dotimes (i 7) (print (times i i i i)))"));
    return 0;
}

extern const char *programDir;

static int submain(int argc, char *argv[])
{   char imageName[256];
    const char *nargv[5];
    int rc;

    std::printf("Start of demo of embedded driver\n");

    std::sprintf(imageName, "%s/reduce.img", programDir);
    nargv[0] = argv[0];
    nargv[1] = "-i";
    nargv[2] = imageName;
    nargv[3] = "-v";
    nargv[4] = nullptr;
    obufp = 0;
    cslstart(4, nargv, iput);
    std::printf("\nBuffered output is <%s>\n\n", obuff);

    std::strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    std::printf("\nBuffered output is <%s>\n\n", obuff);

    ibufp = obufp = 0;
    ibuff[0] = 0;
    PROC_set_callbacks(iget, iput);

    if ((rc = testcase()) != 0) std::printf("\n+++ Return code = %d\n",
                                                rc);

// Now another scheme...
    PROC_set_callbacks(iget1, iput1);
    PROC_prepare_for_top_level_loop();
    PROC_load_package("tmprint");
    PROC_set_switch("fancy", 1);
    PROC_process_one_reduce_statement("lisp linelength 60;");
    PROC_process_one_reduce_statement("algebraic;");
    PROC_process_one_reduce_statement("a := 1/(x^4+1);");
    PROC_process_one_reduce_statement("int(a, x);");
    PROC_process_one_reduce_statement("df(ws, x);");
    rc = cslfinish(iput);
    std::printf("\nBuffered output is <%s>\n\n", obuff);

    return rc;
}


int main(int argc, char *argv[])
{   volatile int res;
    if (find_program_directory(argv[0]))
    {   std::fprintf(stderr,
                     "Unable to identify program name and directory\n");
        return 1;
    }
    try
    {   res = submain(argc, argv);
    }
    catch (std::runtime_error &e)
    {   res = EXIT_FAILURE;
    }
    std::printf("Return code = %d\n", res);
    return res;
}


// End of driver.cpp
