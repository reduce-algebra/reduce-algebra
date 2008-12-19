/*  pro.c                            Copyright (C) 1989-2008 Codemist Ltd */

/* Watcom C stack checking code */

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



/* Signature: 221026ad 24-May-2008 */

#include "headers.h"

#include "version.h"


static int spset = 0;
static int32_t spbase = 0, spmin;

static FILE *stack_log = NULL;

#pragma aux __PRO modify [];

#pragma aux __PRO "__PRO";

extern int pusha(void);
#pragma aux pusha = "push eax" "push ecx" "push edx" value [eax] modify [];
extern int popa(void);
#pragma aux popa = "pop edx" "pop ecx" "pop eax" value [eax] modify [eax ecx edx];

void __PRO()
{
    int32_t temp;
    pusha();
    temp = (int32_t)&temp;
    if (!spset)
    {   spbase = spmin = temp;
        spset = 1;
    }
    if (stack_log == NULL) stack_log = fopen("stack.log", "w");
    if (temp <= spmin-64)  /* Only check at granularity of 64 bytes */
    {
        fprintf(stack_log, "Stack depth %d\n", spbase-temp);
        spmin = temp;
    }
    popa();
    return;
}

/* End of pro.c */
