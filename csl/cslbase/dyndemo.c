/*
 * dyndemo.c
 *
 * This is a test and demonstration of run-time loading of a module
 * of code.
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

/* Signature: 6cfc8de7 24-May-2008 */

#include "config.h"

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

extern int variable_in_base;
extern int function_in_base(int x);

/*
 * I will make the compiled version of this file big to show that
 * it does not get copied into the sub-function in any way... So the
 * next new lines just ensure that function_in_base has a very long and
 * messy definition. I want to do this so that one can then inspect the
 * size of the dyndemo executable and the dynmodule DLL and observe that
 * the DLL is small enough that it really can not possibly contain the
 * body of "function_in_base".
 */

int p(int x)
{
   return 3*x-1;
}

#define q x = p(x);
#define r q q q q q q q q q q
#define s r r r r r r r r r r
#define t s s s s s s s s s s

int function_in_base(int x)
{
    t
    return 7*x-3;
}

int variable_in_base = 0x12345678;

/*
 * So that I can check results I have a copy here of the function
 * I put in the loadable module...
 */

int clone(int x)
{
    return 3*function_in_base(x) + 1;
}

typedef int onearg(int a);

int main(int argc, char *argv[])
{
    onearg *b = NULL;
#ifdef WIN32
    HANDLE a = LoadLibrary(".\\dynmodule.dll");
    printf("Dynamic loading of test code\na = %p\n", (void *)a);
    fflush(stdout);
    if (a == 0)
    {   DWORD err = GetLastError();
        char errbuf[80];
        printf("Error code %ld = %lx\n", (long)err, (long)err);
        err = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
                            NULL, err, 0, errbuf, 80, NULL);
        if (err != 0) printf("%s", errbuf);
        return 0;
    }
    b = (onearg *)GetProcAddress(a, "callme");
#else
    void *a;
    printf("Dynamic loading test code\n");
    fflush(stdout);
    a = dlopen("./dynmodule.so", RTLD_NOW | RTLD_GLOBAL);
    printf("a = %p\n", a);
    fflush(stdout);
    if (a == NULL)
    {   printf("Err = <%s>\n", dlerror()); fflush(stdout);
        return 0;
    }
    b = dlsym(a, "callme");
#endif
    printf("b = %p\n", b);
    fflush(stdout);
    if (b == NULL) return 0;
    printf("variable as printed from base = %.8x @ %p\n",
        variable_in_base, &variable_in_base);
    printf("function as printed from base = %p\n",
        function_in_base);
/*
 * The next 2 lines are expected to display the same numeric value.
 */
    printf("b(7) = %x\n", ((onearg *)b)(7));
    printf("clone(7) = %x\n", clone(7));
    fflush(stdout);
#ifdef WIN32
    FreeLibrary(a);   
#else
    dlclose(a);
#endif
    return 0;
}

/* end of dyndemo.c */

