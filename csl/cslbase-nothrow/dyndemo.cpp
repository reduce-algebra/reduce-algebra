// dyndemo.cpp                            Copyright (C) 2016-2020, Codemist
//
// This is a test and demonstration of run-time loading of a module
// of code. This is an idea I was pursuing at one stage but am not now!
//

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

// $Id: dyndemo.cpp 5433 2020-10-15 21:09:02Z arthurcnorman $

#include <cstdio>

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

extern "C"
{   extern int variable_in_base;
    extern int function_in_base(int x);
};

int function_in_base(int x)
{   return 314159265*x + 271828459;
}

int variable_in_base = 0x12345678;

//
// So that I can check results I have a copy here of the function
// I put in the loadable module...
//

int clone(int x)
{   return 3*function_in_base(x) + 1;
}

typedef int onearg(int a);

int main(int argc, char *argv[])
{   onearg *b = nullptr;
#ifdef WIN32
    HMODULE a = LoadLibrary(".\\dynmodule.dll");
    std::printf("Dynamic loading of test code for Windows\na = %p\n",
                reinterpret_cast<void *>(a));
    std::fflush(stdout);
    if (a == 0)
    {   DWORD err = GetLastError();
        char errbuf[80];
        std::printf("Error code %ld = %lx\n", static_cast<long>(err),
                    static_cast<long>(err));
        err = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                            FORMAT_MESSAGE_IGNORE_INSERTS,
                            nullptr, err, 0, errbuf, 80, nullptr);
        if (err != 0) std::printf("%s", errbuf);
        return 0;
    }
    b = (onearg *)GetProcAddress(a, "callme");
#else
    void *a;
    std::printf("Dynamic loading test code for *ix, BSD, MacOSX etc\n");
    std::fflush(stdout);
    a = dlopen("./dynmodule.so", RTLD_NOW | RTLD_GLOBAL);
    std::printf("Result of call to dlopen is in 'a'\n");
    std::printf("a = %p\n", a);
    std::fflush(stdout);
    if (a == nullptr)
    {   std::printf("Err = <%s>\n", dlerror()); std::fflush(stdout);
        return 0;
    }
    b = (onearg *)dlsym(a, "callme");
#endif
    std::printf("The 'callme' entrypoint should now be in b\n");
    std::printf("b = %p\n", b);
    std::fflush(stdout);
    if (b == nullptr) return 0;
    std::printf("variable as printed from base = %.8x @ %p\n",
                variable_in_base, &variable_in_base);
    std::printf("function as printed from base = %p\n",
                function_in_base);
//
// The next 2 lines are expected to display the same numeric value.
//
    std::printf("b(7) = %x\n", ((onearg *)b)(7));
    std::printf("clone(7) = %x\n", clone(7));
    std::fflush(stdout);
#ifdef WIN32
    FreeLibrary(a);
#else
    dlclose(a);
#endif
    return 0;
}

// end of dyndemo.cpp
