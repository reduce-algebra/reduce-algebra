/* jit1.c                      Copyright (C) 2006-2008, Codemist Ltd */
/*                                                and J O'Connell    */

/*
 * Just in time compiler interfaces. The ideal is that this file does not
 * depend on the architecture of the machine being compiled for. At present
 * there is a bit of system-specific stuff here about allocating memory that
 * can be written to and then executed. But mostly what happens here is an
 * interface between the main CSL interpreter and the JIT system.
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




/* Signature: 63f63240 24-May-2008 */

#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif

#ifdef X86
#include "distorm.h"
#endif

extern int codep;
extern void *jit_space_p, *jit_space;

#define name_from(def) elt(qcdr(def), 0)

int set_jit_mem(char *jitcode)
{
#ifndef WIN32
    /* Check if mmap worked ok */
    if (jit_space==(caddr_t)-1) 
    {   printf("dead");
        return -1;
    }
#endif
    /* Check if enough space, if not try to get more or die nicely */
    while (codep >
           (jit_size - ((unsigned long)jit_space_p-(unsigned long)jit_space))) 
    {   err_printf("\nJIT SPACE IS FULL.  TRYING TO ALLOC MORE...\n");
        jit_size *= 2;
#ifndef WIN32
        jit_space = mremap(jit_space, jit_size/2, jit_size, 0);
        if (jit_space==(caddr_t)-1) 
        {
/*
 * I probably want to use strerror not perror here so that I can then
 * direct the diagnostic to the CSL error destination, which may sometimes
 * be a window rather than "stdout". 
 */
            perror("mmap failed");
            return -1;
        }
       err_printf("SUCCESSFUL. ALLOCATED %d\n", jit_size);
#endif
    }
    /* copy over jit compiled function */
    memcpy(jit_space_p, jitcode, codep);
    return 0;
}                                    

Lisp_Object MS_CDECL jitcompileme0(Lisp_Object def, int nargs, ...)
{
    Lisp_Object name = name_from(def);
    char *jitcode;
    if (nargs != 0) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32)nargs));
    jitcode = Jcompile(def, 0);
    if (jitcode != NULL) 
    {   if (set_jit_mem(jitcode)==0)
        {   ifnn(name) = (intptr_t)jit_space_p;
            jit_space_p += codep;
        }
        else ifnn(name) = (intptr_t)bytecoded0;
    }
    else ifnn(name) = (intptr_t)bytecoded0;

    return qfnn(name)(qenv(name), 0);
}

Lisp_Object jitcompileme1(Lisp_Object def, Lisp_Object a)
{
    Lisp_Object name = name_from(def);
/*
 * Jcompile does not have to do anything that could provoke a garbage
 * collection, so I am in the happy position that I do not need to
 * stack anything here or fuss in any way about the Lisp-ness of my
 * environment.
 */
    char *jitcode = Jcompile(def, 1);
/*
 * At present Jcompile builds its generated code in a private buffer
 * (probably of limited length) and I copy if to executable memory here.
 * The "copy" operation would have bad consequences for any code that
 * was location sensitive!
 */
    if (jitcode != NULL) 
    {   if (set_jit_mem(jitcode)==0)
        {   ifn1(name) = (intptr_t)jit_space_p;
            jit_space_p += codep;
        }
        else ifn1(name) = (intptr_t)bytecoded1;
    }
    else ifn1(name) = (intptr_t)bytecoded1;
/*
 * remember to pass the compiled code its "environment" of literals.
 */
    return qfn1(name)(qenv(name), a);
}

Lisp_Object jitcompileme2(Lisp_Object def, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object name = name_from(def);
    char *jitcode = Jcompile(def, 2);

    if (jitcode != NULL) 
    {   if (set_jit_mem(jitcode)==0)
        {   ifn2(name) = (intptr_t)jit_space_p;
            jit_space_p += codep;
        }
        else ifn2(name) = (intptr_t)bytecoded2;
    }
    else ifn2(name) = (intptr_t)bytecoded2;
    return qfn2(name)(qenv(name), a, b);
}

Lisp_Object MS_CDECL jitcompileme3(Lisp_Object def, int nargs, ...)
{
    Lisp_Object name = name_from(def); 
    char *jitcode;
    va_list aa;
    Lisp_Object a, b, c;
    if (nargs != 3) return error(2, err_wrong_no_args, name_from(def),
                                    fixnum_of_int((int32)nargs));
    jitcode = Jcompile(def, 3);

    if (jitcode != NULL) 
    {   if (set_jit_mem(jitcode)==0) 
        {   ifnn(name) = (intptr_t)jit_space_p;
            jit_space_p += codep;
        }
        else ifnn(name) = (intptr_t)bytecoded3;
    }
    else ifnn(name) = (intptr_t)bytecoded3;

    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    return qfnn(name)(qenv(name), 3, a, b, c);
}

Lisp_Object MS_CDECL jitcompilemen(Lisp_Object def, int nargs, ...)
{
    Lisp_Object name = name_from(def);
    va_list a;
/*
 * Ought I to check the number of args here? Quite probably!!!!
 */
    char *jitcode = Jcompile(def, nargs);

    if (jitcode != NULL) 
    {   if (set_jit_mem(jitcode)==0) 
        {   ifnn(name) = (intptr_t)jit_space_p;
            jit_space_p += codep;
        }
        else ifnn(name) = (intptr_t)bytecodedn;
    }
    else ifnn(name) = (intptr_t)bytecodedn;
/*
 * I have a feeling that nargs should never be zero here....
 */
    if (nargs != 0)
    {   va_start(a, nargs);
        push_args(a, nargs); /* FIXME stack ok? or pushed too much */
    }
    return apply(name, nargs, qenv(name), name);
}



/* end of jit1.c */
