/* imulvc.c                   Copyright (C) 1993-2008 Codemist Ltd */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 35639bed 24-May-2008 */

/*
 * This code implements Imultiply and Idivide in 80386 (and up) assembly
 * code.  I use the __stdcall calling convention.
 */


#include "headers.h"



/*
 * Get rid of unwanted warnings about lack of return values...
 */

#pragma warning (disable : 4035)


uint32_t __stdcall Imultiply(uint32_t *rlow,
                             uint32_t a, uint32_t b, uint32_t c)
{
/*
 *     uns64 r = (uns64)a*(uns64)b + (uns64)c;
 *     *rlow = (uint32_t)(r & 0x7fffffff);
 *     return (uint32_t)(r >> 31);
 */
    __asm
    {
        mov        eax, b
        mul        a
        mov        ecx, rlow
        add        eax, c
        adc        edx, 0                ; carry into top half
        add        eax, eax
        adc        edx, edx
        shr        eax, 1
        mov        DWORD PTR [ecx], eax
        mov        eax, edx
    }
}



uint32_t __stdcall Idiv10_9(uint32_t *qp, uint32_t high31, uint32_t low31)
{
/*
 *      uns64 p = ((uns64)high31 << 31) | (uns64)low31;
 *     *qp = (uint32_t)(p / (uns64)1000000000U);
 *     return (uint32_t)(p % (uns64)1000000000U);
 */
    __asm {
        mov        edx, high31
        mov        eax, low31
        shl        eax, 1
        shr        edx, 1
        rcr        eax, 1            ; That glued together 31+31 bits
        mov        ecx, 1000000000
        div        ecx
        mov        ecx, qp
        mov        DWORD PTR [ecx], eax
        mov        eax, edx
    }
}


uint32_t __stdcall Idivide(uint32_t *qp, uint32_t a,
                           uint32_t b, uint32_t c)
{
/*
 *     uns64 p = ((uns64)a << 31) | (uns64)b;
 *     *qp = (uint32_t)(p / (uns64)c);
 *     return (uint32_t)(p % (uns64)c);
 */
    __asm {
        mov        edx, a
        mov        eax, b
        shl        eax, 1
        shr        edx, 1
        rcr        eax, 1          ; That glued together 31+31 bits
        mov        ecx, c
        div        ecx
        mov        ecx, qp
        mov        DWORD PTR [ecx], eax
        mov        eax, edx
    }
}


/* end of imulvc.c */
