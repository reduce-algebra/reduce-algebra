/*  stubs.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Placeholder for compiler-generated C code.
 * This module is linked in in place of the machine-generated files
 * "u01.c" to "u10.c" to create a cold-start, unspecialised version of CSL
 */

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



/* Signature: 6840aa4d 24-May-2008 */

#include "headers.h"



static Lisp_Object Lsample(Lisp_Object nil, Lisp_Object x)
{
    CSL_IGNORE(nil);
    return onevalue(x);
}

setup_type const u01_setup[] =
{
    {"sample",                Lsample,     too_many_1,   wrong_no_1},
    {NULL,                    0, 0, 0}
};

setup_type const u02_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u03_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u04_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u05_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u06_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u07_setup[] =
{
    {NULL,                      0, 0, 0}

};

setup_type const u08_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u09_setup[] =
{
    {NULL,                      0, 0, 0}
};

/*
 * A bit of a horrible fudge - but I will use u10_setup[0].name==NULL to
 * decide that I have these stubs loaded.
 */

setup_type const u10_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u11_setup[] =
{
    {NULL,                      0, 0, 0}
};

setup_type const u12_setup[] =
{
    {NULL,                      0, 0, 0}
};

/* end of stubs.c */

