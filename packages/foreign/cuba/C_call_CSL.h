// C_call_CSL.h                           Copyright 2014 Kostas N. Oikonomou



/*
  This is not so much an interface from C to Reduce/CSL, but more of a way for
  C to *control* Reduce via a set of procedure calls.  See csl/cslbase/proc.h.

  Example: call f(x,y) from C, where "f" is defined in Reduce.

double nlopt_tst_f(double x, double y, char *f) {
    PROC_handle w;
    PROC_clear_stack();
    PROC_push_floating(x);
    PROC_push_floating(y);                
    PROC_make_function_call(f, 2);
    // Understand why these are needed!
    PROC_lisp_eval();
    w = PROC_get_value();
    double z = PROC_floating_value(w);
    return z;
}

There are two main reasons why this stack-oriented way of doing things is
used.  The first is that it leads to a situation where only a medium number
of calls into the CSL Lisp system have to be provided - and sometimes
managing to link to things that are within the main Reduce/Lisp executable
may be a challenge.  But perhaps the more important matter is that all data
within the Lisp/Reduce world is subject to a garbage collector that both
needs to be able to find everything, and that will achieve its purpose by
copying live data to new space.  Thus if the C code has a raw pointer to
Lisp-level data, then any time any other Lisp code was run, that address
could become out-of-date. The stack-based "arm's length" interface here
allows Lisp to keep track of everything nicely.

*/

/**************************************************************************
 * Copyright (C) 2014.                             Kostas Oikonomou       *
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

static void *callbacks[33];

typedef void *PROC_handle;

#define execute_lisp_function             ((int (*)(char *, void *, void *))callbacks[0])
#define PROC_set_callbacks                ((int (*)(void *, void *))callbacks[1])
#define PROC_load_package                 ((int (*)(char *))callbacks[2])
#define PROC_set_switch                   ((int (*)(char *))callbacks[3])
#define PROC_gc_messages                  ((int (*)(char *,int))callbacks[4])
#define PROC_clear_stack                  ((int (*)())callbacks[5])
#define PROC_push_symbol                  ((int (*)(char *))callbacks[6])
#define PROC_push_string                  ((int (*)(char *))callbacks[7])
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
#define PROC_string_data                  ((cinst char *(*)(PROC_handle))callbacks[30])
#define PROC_lisp_eval                    ((int (*)())callbacks[31])
#define PROC_get_raw_value                ((PROC_handle (*)())callbacks[32])


// This function is supposed to be called as
//     register_callback(i, get-callback(i))
// Seems like a contortion, 1.  register_callback *cannot* be called from C, say
// from the glue library librednlopt.so, because get-callback is only known to
// Reduce.  There is no shared library that defines get-callback!  This is
// contortion 2.  
// So it needs to be called from Reduce as
//  for i := 0:32 do
//    call-foreign-function(register_entrypoint, "int", i, "int64", get-callback(i))
void register_callback(int32_t i, int64_t value) {
    if (0 <= i && i <= 32) callbacks[i] = (void *)(intptr_t) value;
}

// end of C_call_CSL.h
