/*
 * dynmodule.c
 *
 * This goes with dyndemo.c to form a demonstration of dynamic loading
 * of code. This file must be compiled as a DLL (or whatever it takes
 * to make it a candidate for dynamic loading).
 */

/**************************************************************************
 * Copyright (C) 2013, Codemist Ltd.                     A C Norman       *
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

/* Signature: 023eb297 02-May-2013 */

#include <stdio.h>

extern int variable_in_base;
extern int function_in_base(int x);

int callme(int x)
{
/*
 * On Windows it seems that with the build scheme I am using that the
 * address of the variable from the base ends up the same when looked
 * at from the loaded module and from the base, but the address of the
 * function entrypoint differs.
 */
    printf("variable in base = %.8x @ %p\n",
        variable_in_base, &variable_in_base);
    printf("function in base = %p\n",
        function_in_base);
    return 3*function_in_base(x) + 1;
}

/* end of dynmodule.c */


