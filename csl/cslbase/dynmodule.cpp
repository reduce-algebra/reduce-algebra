//
// dynmodule.cpp
//
// This goes with dyndemo.c to form a demonstration of dynamic loading
// of code. This file must be compiled as a DLL (or whatever it takes
// to make it a candidate for dynamic loading).
//

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

#include <stdio.h>

extern "C"
{
extern int variable_in_base;
extern int function_in_base(int x);
};

extern "C" int callme(int x)
{
//
// This test code references a variable in the base code here, and on Linux
// and similar systems the linking makes the access behave "as expected".
// However on Windows the nature of DLLs seems to mean that the address
// used here for "variable_in_base" is in fact an address of some sort of
// thunk and NOT of the actual variable. So:
//  It is not valid to access data from the base in a DLL
//  It is not valid to test or rely on the address of a function.
//
//
    printf("variable in base = %.8x @ %p\n",
           variable_in_base, &variable_in_base);
    printf("function in base = %p\n",
           function_in_base);
    return 3*function_in_base(x) + 1;
}

// end of dynmodule.cpp
