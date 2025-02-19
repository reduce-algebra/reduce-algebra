// jit.cpp                                      Copyright (C) 2025 Codemist

//
// Just-in-time compiler framework
//

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

// $Id$

#include "headers.h"

#ifdef ENABLE_JIT

#include "bytes.h"

#include <asmjit/core.h>

#include <memory>
#include <vector>

#include <asmjit/x86.h>
#include <asmjit/a64.h>


extern void plant(const unsigned char* bytes, size_t len, LispObject env, int nargs);

struct JitFailed : public std::exception
{   virtual const char *what() const throw()
    {   return "JIT compiler found unsupported bytecode";
    }
};

void unfinished(const char* msg)
{   while (*msg != 0 &&
           strncmp(msg, "op/op", 5)!=0) msg++;
    stdout_printf("+++ %s\n", msg+3);
    THROW(JitFailed);
}

void plant(const unsigned char* codevec, size_t len, LispObject env, int nargs)
{
    stdout_printf("Calling plant on ");
    simple_print(basic_elt(env, 0));
    for (unsigned int i=0; static_cast<size_t>(i)<len; i++)
        stdout_printf("%3u:  %02x\n", i, codevec[i]);

    TRY
    {
// BEWARE - bytecoded functions with 4 or more arguments and ones with
// &optional or &rest arguments have some info bytes at the start of the
// vector that otherwise holds byte instructions, so in those cases starting
// at address zero is liable to be wrong!
        size_t ppc = 0;
        while (ppc<len)
        {   switch (codevec[ppc])
            {
#include "ops/bytes_include.cpp"
            }
        }
    }
    CATCH (JitFailed)
    {
    }
    END_CATCH;
}

// When a function is potentially going to be JIT compiled it will
// have one of jitcoded_0 to jitcoded_4up in a function call where otherwise
// it would have had bytecoded_0 etc. At present I an not considering
// byteopt_0... , hardopt_0... byteoptrest_0... or hardoptrest_0...
// because they are not used by Reduce and I will be pleased if I can get the
// simpler cases with a known number of arguments dealt with micely.

// When such a function is first called it will call jitcompile, passing
// the vector of byte instructions. If this returns nullptr that will
// indicate that the conversion to real machine code failed. That could
// be just because some byte-operator that has not yet been implemented
// was used. In that case the simple call to bytecoded_0 etc should be
// reinstated and the function executed from the bytecodes. But if
// something other than nullptr is returned that will be the entrypoint of
// some native code. That is both put back in the function cell for
// subsequent use and applied to handle the current call.

// At least while this is being developed the function "make-jit" can
// be given the name of a bytecoded function and it upgrades it to
// try for JIT compilation. I will need to sort out a good plan for
// making all this interact with saved heap images - but there is no
// need to worry about that until and unless the schere is working.

void* jitcompile(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{
// I am going to start by printing the byte-stream
    stdout_printf("Calling jitcompile on ");
    simple_print(basic_elt(env, 0));
    for (unsigned int i=0; static_cast<size_t>(i)<len; i++)
        stdout_printf("%3u:  %02x\n", i, bytes[i]);

    plant(bytes, len, env, nargs);
    stdout_printf("Sample code inserted into memory...\n");

    stdout_printf("About to return executable segment...\n");
    return nullptr;
}

#else // ENABLE_JIT

// The functions here are no use, but are provided so that image files
// are compatible across architectures. By always returning nullptr this
// reports that it is unable to map from bytecodes to native instructions.

void* jitcompile(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{   return nullptr;
}

#endif // ENABLE_JIT

// end of jit.cpp
