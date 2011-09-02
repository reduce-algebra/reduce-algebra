/*  stubs.c                         Copyright (C) 1990-2002 Codemist Ltd */

/*
 * Placeholder for compiler-generated C code.
 * This module is linked in in place of the machine-generated files
 * "u01.c" to "u10.c" to create a cold-start, unspecialised version of CSL
 */

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


/* Signature: 0638a0fd 08-Apr-2002 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "entries.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif



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

