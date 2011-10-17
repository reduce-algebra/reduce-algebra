/* imulvc.c                   Copyright (C) 1993-1996 Codemist Ltd */

/* Signature: 60c250ae 23-Apr-1996 */

/*
 * This code implements Imultiply and Idivide in 80386 (and up) assembly
 * code.  I use the __stdcall calling convention.
 */


#include "machine.h"

#include "tags.h"
#include "externs.h"
#include "cslerror.h"
#include "sys.h"

/*
 * Get rid of unwanted warnings about lack of return values...
 */

#pragma warning (disable : 4035)


unsigned32 __stdcall Imultiply(unsigned32 *rlow,
                             unsigned32 a, unsigned32 b, unsigned32 c)
{
/*
 *     uns64 r = (uns64)a*(uns64)b + (uns64)c;
 *     *rlow = (unsigned32)(r & 0x7fffffff);
 *     return (unsigned32)(r >> 31);
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



unsigned32 __stdcall Idiv10_9(unsigned32 *qp, unsigned32 high31, unsigned32 low31)
{
/*
 *      uns64 p = ((uns64)high31 << 31) | (uns64)low31;
 *     *qp = (unsigned32)(p / (uns64)1000000000U);
 *     return (unsigned32)(p % (uns64)1000000000U);
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


unsigned32 __stdcall Idivide(unsigned32 *qp, unsigned32 a,
                           unsigned32 b, unsigned32 c)
{
/*
 *     uns64 p = ((uns64)a << 31) | (uns64)b;
 *     *qp = (unsigned32)(p / (uns64)c);
 *     return (unsigned32)(p % (uns64)c);
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
