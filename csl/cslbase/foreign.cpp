//
// foreign.cpp                                  Copyright 2015  A C Norman
//

//
// This illustrates creating and in due couse calling code
// that is in a DLL from Lisp/Reduce, and also shows how the
// C code you call there can call back into the Lisp/Reduce
// world.
//

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
 * DAMAGE.                                                                *
 *************************************************************************/



// $Id$

//
// This will provide a range of functions with various signatures that
// can be tried.
//

static int32_t k = 12345;

//
// First a series of functions that illustrate support for the
// various possible return types. These are int32, in64, double and string.
//

void vff()
{   printf("void vff()\n");
}

int32_t i32ff()
{   printf("int32_t i32ff()\n");
    return k++;
}

int64_t i64ff()
{   printf("int64_t i64ff()\n");
    return (int64_t)k++ * (int64_t)100000000;
}

double dff()
{   printf("double dff()\n");
    return (double)k++ + 0.12345;
}

char buffer[100];

char *sff()
{   printf("double sff()\n");
    sprintf(buffer, "SFF%d!", (int)k++);
    return buffer;
}

//
// Now a series that illustrate passing various sorts of argument.
// Here I will make the function merely print its argument and so I
// can cope with not having any result.
//

void vffi32(int32_t a)
{   printf("vffi32(%d)\n", (int)a);
}

void vffi64(int64_t a)
{   printf("vffi64(%" PRId64 ")\n", a);
}

void vffd(double a)
{   printf("vffd(%18.12g)\n", a);
}

void vffs(char *a)
{   printf("vffs(\"%s\")\n", a);
}

//
// Now some code that supports the calls that go back in the other direction
//

static void *callbacks[33];

//
// I will end up with callback entrypoints back into Lisp saves in the
// callbacks array. Here I cast them to the proper function types so I
// can then use them almost naturally. Note that the "callbacks" in
// PROC_SET_CALLBACKS are ones that Lisp uses to call back into the C code
// to do I/O, while the ones here are where the C code is calling into Lisp.
//

typedef void *PROC_handle;

#define execute_lisp_function             ((int (*)(const char *, void *, void *))callbacks[0])
#define PROC_set_callbacks                ((int (*)(void *, void *))callbacks[1])
#define PROC_load_package                 ((int (*)(const char *))callbacks[2])
#define PROC_set_switch                   ((int (*)(const char *))callbacks[3])
#define PROC_gc_messages                  ((int (*)(const char *,int))callbacks[4])
#define PROC_clear_stack                  ((int (*)())callbacks[5])
#define PROC_push_symbol                  ((int (*)(const char *))callbacks[6])
#define PROC_push_string                  ((int (*)(const char *))callbacks[7])
#define PROC_push_small_integer           ((int (*)(int32_t))callbacks[8])
#define PROC_push_big_integer             ((int (*)(const char *))callbacks[9])
#define PROC_push_floating                ((int (*)(double))callbacks[10])
#define PROC_make_function_call           ((int (*)(const char *, int))callbacks[11])
#define PROC_save                         ((int (*)(int))callbacks[12])
#define PROC_load                         ((int (*)(int))callbacks[13])
#define PROC_dup                          ((int (*)())callbacks[14])
#define PROC_pop                          ((int (*)())callbacks[15])
#define PROC_simplify                     ((int (*)())callbacks[16])
#define PROC_make_printable               ((int (*)())callbacks[17])
#define PROC_get_value                    ((PROC_handle (*)())callbacks[18])
#define PROC_atom                         ((int (*)(PROC_handle)callbacks[19])
#define PROC_null                         ((int (*)(PROC_handle))callbacks[20])
#define PROC_fixnum                       ((int (*)(PROC_handle))callbacks[21])
#define PROC_floatnum                     ((int (*)(PROC_handle))callbacks[22])
#define PROC_string                       ((int (*)(PROC_handle))callbacks[23])
#define PROC_symbol                       ((int (*)(PROC_handle))callbacks[24])
#define PROC_first                        ((PROC_handle (*)(PROC_handle))callbacks[25])
#define PROC_rest                         ((PROC_handle (*)(PROC_handle))callbacks[26])
#define PROC_integer_value                ((int32_t (*)(PROC_handle))callbacks[27])
#define PROC_floating_value               ((double (*)(PROC_handle))callbacks[28])
#define PROC_symbol_name                  ((const char *(*)(PROC_handle))callbacks[29])
#define PROC_string_data                  ((cinst const char *(*)(PROC_handle))callbacks[30])
#define PROC_lisp_eval                    ((int (*)())callbacks[31])
#define PROC_get_raw_value                ((PROC_handle (*)())callbacks[32])


void register_callback(int32_t which, int64_t value)
{   if (0<=which && which<=32) callbacks[which] = (void *)(intptr_t)value;
    printf("Callback number %d registered as %p\n", which, callbacks[which]);
}

int32_t two_way(int32_t x)
{   PROC_handle w;
    printf("In foreign code. x = %d. Result will be %d^6 = %d\n",
           x, x, x*x*x*x*x*x);
//
// The PROC_xxx calls tend to return zero on success
//
    PROC_clear_stack();                         // |
    PROC_push_small_integer(x);                 // | x
    PROC_push_small_integer(6);                 // | x 6
    PROC_make_function_call("expt", 2);         // | (expt x 6)
    PROC_lisp_eval();                           // | value of above
    PROC_push_string("Try a message");          // | value "Try a message"
    PROC_make_function_call("print", 1);        // | value (print "...")
    PROC_lisp_eval();                           // | value "..."
    PROC_pop();                                 // | value
    w = PROC_get_value();                       // |
    x = PROC_integer_value(w);                  // should be x^6!
    return x;
}

// End of test loadable module, foreign.cpp

