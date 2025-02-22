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

using namespace asmjit;

struct JitFailed : public std::exception
{   const char* msg;
    JitFailed()
    {   msg = "JIT compiler found unsupported bytecode";;
    }
    JitFailed(const char* why)
    {   msg = why;
    }
    virtual const char *what() const throw()
    {   return msg;
    }
};

void unfinished(const char* msg)
{   while (*msg != 0 &&
           strncmp(msg, "op/op", 5)!=0) msg++;
    stdout_printf("+++ %s\n", msg+3);
    THROW(JitFailed);
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

class JitError : public ErrorHandler
{
public:
    void handleError(Error err, const char* msg, BaseEmitter* origin) override
    {   stdout_printf("+++ AsmJit error: %s\n", msg);
        throw JitFailed("asmjit reported trouble");
    }
};

JitRuntime rt;

uintptr_t demovar = 99;

void* jitcompile(const unsigned char* bytes, size_t len,
                 LispObject env, int nargs)
{
// I am going to start by printing the byte-stream
    stdout_printf("\nCalling jitcompile on ");
    simple_print(basic_elt(env, 0));
// Note that when a byte-code takes a follow-on byte as an operand that
// the "opname" I display here will be garbage. I may want to rearrange the
// codes so that I have an easy way to tell when thet is going to be the
// case.
    stdout_printf("Bytecodes...\n");
    for (size_t i=0; i<len; i++)
        stdout_printf("%3u:  %02x  %s\n", i, bytes[i], opnames[bytes[i]]);
// The literal at offset zero is the name of the function, and the
// final entry is an integer checksum 
    stdout_printf("Vector of literals...\n");
    for (size_t i=0; i<(length_of_header(vechdr(env))-CELL)/CELL; i++)
    {   stdout_printf("%3d: ", i);
        simple_print(basic_elt(env, i));
    }

// I am going to support functions with up to 15 arguments - anything
// beyond that I will declare unsuitable to mapping into hard code.
// Well the function in the Reduce sources with most arguments is
// add3sint() in fide and that has 14, so this is not a limit that
// with restrict me.
    if (nargs > 15) return nullptr;
//
// Set up to use asmjit. The code here just creates and initialises
// various things that it needs.
    CodeHolder code;
    Environment localEnv = rt.environment();;
#ifdef __CYGWIN__
    localEnv._platformABI = PlatformABI::kMSVC;
#endif
    code.init(localEnv, rt.cpuFeatures());
    JitError jitError;
    code.setErrorHandler(&jitError);
    Section* text = code.textSection();
    Section* data;
    if (code.newSection(&data,
                        ".data",
                        SIZE_MAX,
                        SectionFlags::kNone,
                        16) != ErrorCode::kErrorOk)
        throw JitFailed("attempt to create data section failed");
// I believe that the next two lines will lead to the generated assembly
// code being displayed on the standard output. This is going to be
// really useful while developing, but it obviously gets switched off for
// most production use.
    FileLogger logger(stdout);
    code.setLogger(&logger);

#if defined __x86_64__
    auto cc = x86::Compiler(&code);
// Here I need to specify the type signature of the function that I am
// creating and associate some names with the arguments it will receive.
// The function I am defining will have min(nargs+1, 5) arguments
// each of which is a LispObject. It is going to have to start by
// pushing all these onto the (Lisp) stack. So for instance if this
// is going to be a function that expects (in the Lisp sense!) 2 arguments
// its signature in C++ and first few lines would have been
//    LispObject foo(LispObject litvec, LispObject a1, LispObject a2)
//    {   RealSave save(litvec, a1, a2);
// where the ReadSave obect's constructor has gone in effect
//       *stack++ = litvec;
//       *stack++ = a1;
//       *stack++ = a2;
// and then set things up so that when the function terminates that
// stack is set back to its initial value.
    FuncNode* funcNode;
// I will set up enough registers for up to 10 arguments but in most cases
// almost all of those will not be used.
    x86::Gp litvec = cc.newIntPtr("litvec");
    x86::Gp argregs[16];
    for (size_t i=1; i<=15; i++)
        argregs[i] = cc.newIntPtr("a1");
    x86::Gp w      = cc.newIntPtr("w");
    x86::Gp w1     = cc.newIntPtr("w1");
// I also need to registers for the things that the JITed code will do
    x86::Gp A_reg  = cc.newIntPtr("A_reg");
    x86::Gp B_reg  = cc.newIntPtr("B_reg");
// Througout the JIT body I will keep a copy of the C++ variable "stack"
// in a register. But I will write it back before calling a function from
// the JIT code.
    x86::Gp spaddr = cc.newIntPtr("spaddr");
    x86::Gp spreg  = cc.newIntPtr("spreg");
    x86::Gp spentry= cc.newIntPtr("spentry");
    x86::Gp fptr   = cc.newIntPtr("fptr");
// The chack for the right number of arguments when there are more than
// 3 has to be dynamic, so I must be ready to return with a failure response.
// Ditto cases where I call a sub-function which may fail, and so I need
// to propagate the failure. I also have a single label for use returning
// the value in the A register, and a vector of labels where I set one
// on the expansion of each bytecode so that if there is a branch to
// it I can handle that.
    Label tooFewArgs  = cc.newLabel();
    Label tooManyArgs = cc.newLabel();
    Label callFailed  = cc.newLabel();
    Label returnA     = cc.newLabel();
// I am going to set a label on the code that corresponds to each bytecode
// so that I can handle the jumps there.
    std::vector<Label> perInstruction;
    for (size_t i=0; i<len; i++)
        perInstruction.push_back(cc.newLabel());
// I will be compiling functions with various numbers of arguments. Here I
// need to set up a suitable function signature and associate asmjit registers
// with all of the arguments.
    switch (nargs)
    {
    case 0:
        funcNode = cc.newFunc(
            FuncSignature::build<LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        break;
    case 1:
        funcNode = cc.newFunc(
            FuncSignature::build<LispObject, LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        break;
    case 2:
        funcNode = cc.newFunc(
            FuncSignature::build<LispObject, LispObject,
                                 LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        funcNode->setArg(2, argregs[2]);
        break;
    case 3:
        funcNode = cc.newFunc(
            FuncSignature::build<LispObject, LispObject,
                                 LispObject, LispObject,
                                 LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        funcNode->setArg(2, argregs[2]);
        funcNode->setArg(3, argregs[3]);
        break;
    default:          // 4 or more
        funcNode = cc.newFunc(
            FuncSignature::build<LispObject, LispObject,
                                 LispObject, LispObject,
                                 LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        funcNode->setArg(2, argregs[2]);
        funcNode->setArg(3, argregs[3]);
        funcNode->setArg(4, w);
        break;
    }
    cc.addFunc(funcNode);
// Load the register "spaddr" to be the address of the C++ variable
// "stack", and spreg to hold its value.
    cc.mov(spaddr, reinterpret_cast<uintptr_t>(&stack));
    cc.mov(spreg, ptr(spaddr));
    cc.mov(spentry, spreg);
// In CSL if a Lisp/Reduce-level function has 4 or more arguments it in fact
// passes just the first 3 separately - all the rest are passed in a list.
// Here I need to disentangle that. I push all the arguments onto the Lisp
// stack at spreg. Note that this does noy update the C++ variable, and if
// at any time I do a function call I will need to bring that up to date.
// If I do change the C++ version I will need to restore it from spentry
// before I exit.
    for (int i=1; i<nargs&&i<4; i++)
    {   cc.mov(argregs[i], ptr(spreg));
        cc.add(spreg, 8);
    }
    if (nargs>=4)
    {   cc.mov(w1, w);
        for (int i=4; i<=nargs; i++)
        {
// Here I need to unpack arg4 and up. This has to go sort of
//          if atom w1 then return "called with too few arguments"
//          aX = car(w1); w1 = cdr(w1)   // until X=nargs
// Now in lower-level language that is
//          if ((w1 & 0x7) != 0) goto tooFewArgs;
//          aX = w1[0];
//          w1 = w1[1];
            stdout_printf("test/jne/mov/mov\n");
            cc.test(w1, 7);
            cc.jne(tooFewArgs);
            cc.mov(argregs[i], ptr(w1));
            if (i!=nargs) cc.mov(w1, ptr(w1, 8));
            cc.mov(argregs[i], ptr(spreg));
            cc.add(spreg, 8);
        }
    }
    
#elif defined aarch64
    auto cc = a64::Compiler(&code);
#pragma message "Much not done here yet"
#else
#error unrecognised platform
#endif


// The part from here on will be to a large extent platform independent
// in this file, but the #included files all discrimate on x86_64 vs aarch64.

    len = 0; // To avoid even glancing at the bytecode stream, since to
             // date nothing is supported!
    TRY
    {   size_t ppc = 0;
        while (ppc<len)
        {
// Set a label on the code that derives from each opcode. Note that
// because the "case" code for some opcode will increment ppc there will
// be some of the labels that are neither defined nor used.
            cc.bind(perInstruction[ppc]);
            switch (bytes[ppc])
            {
#include "ops/bytes_include.cpp"
            }
        }
    }
    CATCH (JitFailed)
    {   stdout_printf("Caught %s\n", e.what());
        return nullptr;
    }
    END_CATCH;

    stdout_printf("Set the labels that I ought to\n");
    cc.bind(tooFewArgs);
// Not implemented yet!
    cc.bind(tooManyArgs);
// Not implemented yet!
    cc.bind(callFailed);
// Not implemented yet!
    cc.bind(returnA);
    cc.ret(argregs[4]);

    cc.endFunc();
    cc.finalize();
    void* func = nullptr;
    if (rt.add(&func, &code) != ErrorCode::kErrorOk)
        throw JitFailed("rt.add failed");
    size_t size = code.codeSize();
    stdout_printf("size=%d code at %p\n", size, func);
    if (func != nullptr)
    {   FILE* hex = fopen("hex", "w");
        for (int i=0; i<(int)size; i++)
        {   fprintf(hex, "0x%.2x", reinterpret_cast<unsigned char*>(func)[i]);
            if ((i%8) == 7) fprintf(hex, "\n");
            else fprintf(hex, " ");
        }
        if ((size%8) != 0) fprintf(hex, "\n");
        fclose(hex);
    }
    return func;
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
