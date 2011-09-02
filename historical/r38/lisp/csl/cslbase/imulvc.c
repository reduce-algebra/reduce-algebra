/* imulvc.c                   Copyright (C) 1993-2007 Codemist Ltd */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 76dee3e1 18-Jan-2007 */

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
