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

static bool testingForUnfinished = false;

void unfinished(const char* msg)
{   if (!testingForUnfinished)
    {   while (*msg != 0 &&
               strncmp(msg, "ops/op", 6)!=0) msg++;
        stdout_printf("\n+++ %s\n", msg+4);
    }
    THROW(JitFailed);
}

// By introducing a type "Register" that is a general purpose register on
// my host machine I can keep one copy of code where at one stage I had
// been going to have essentially two copies.
#if defined __x86_64__
#define ARCH "x86_64"
typedef x86::Gp Register;
typedef x86::Compiler LocalCompiler;

void loadreg(LocalCompiler& cc, Register& r, Register& base, intptr_t offset)
{   cc.mov(r, ptr(base, offset));
}

void storereg(LocalCompiler& cc, Register& r, Register& base, intptr_t offset)
{   cc.mov(ptr(base, offset), r);
}

#elif defined __aarch64__
#define ARCH "aarch64"
typedef a64::Gp Register;
typedef a64::Compiler LocalCompiler;

void loadreg(LocalCompiler& cc, Register& r, Register& base, intptr_t offset)
{   cc.ldr(r, ptr(base, offset));
}

void storereg(LocalCompiler& cc, Register& r, Register& base, intptr_t offset)
{   cc.str(r, ptr(base, offset));
}

#else
#define ARCH "unknown"
#error unrecognised architecture for JIT
#endif

// Some overloads for setting up function calls with 0, 1,... args,
// all of which are LispObjects.

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result)
{   InvokeNode *in;
// I must bring the Lisp variable holding a stack pointer up to date.
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject>());
    in->setRet(0, result);
}

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result,
            Register& a1)
{   InvokeNode *in;
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject, LispObject>());
    in->setArg(0, a1);
    in->setRet(0, result);
}

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result,
            Register& a1, Register& a2)
{   InvokeNode *in;
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject, LispObject, LispObject>());
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setRet(0, result);
}

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result,
            Register& a1, Register& a2,
            Register& a3)
{   InvokeNode *in;
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject, LispObject,
                             LispObject, LispObject>());
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setRet(0, result);
}

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result,
            Register& a1, Register& a2,
            Register& a3, Register& a4)
{   InvokeNode *in;
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject, LispObject, LispObject,
                             LispObject, LispObject>());
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setArg(3, a4);
    in->setRet(0, result);
}

void invoke(LocalCompiler& cc, Register& nilreg, Register& spreg,
            Register& target, Register& result,
            Register& a1, Register& a2,
            Register& a3, Register& a4,
            Register& a5)
{   InvokeNode *in;
    storereg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.invoke(&in, target,
        FuncSignature::build<LispObject, LispObject, LispObject,
                             LispObject, LispObject, LispObject>());
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setArg(3, a4);
    in->setArg(4, a5);
    in->setRet(0, result);
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
// This is in case I want to set up a data section to put static
// material in.
    [[maybe_unused]] Section* text = code.textSection();
    [[maybe_unused]] Section* data;
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
    LocalCompiler cc = x86::Compiler(&code);
#elif defined __aarch64__
    LocalCompiler cc = a64::Compiler(&code);
#else
#error unrecognised architecture for JIT
#endif
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
// I will set up enough registers for up to 10 arguments but in most cases
// almost all of those will not be used.
    Register litvec = cc.newIntPtr("litvec");
    Register argregs[16];
    for (size_t i=1; i<=15; i++)
        argregs[i] = cc.newIntPtr("a1");
    Register w      = cc.newIntPtr("w");
    Register w1     = cc.newIntPtr("w1");
    Register w2     = cc.newIntPtr("w2");
// I also need to registers for the things that the JITed code will do
    Register A_reg  = cc.newIntPtr("A_reg");
    Register B_reg  = cc.newIntPtr("B_reg");
// Througout the JIT body I will keep a copy of the C++ value of nil
// and of the variable "stack" in registers. I will also store the value
// that stack has on entry to the function. I will write stack back
// before calling a function from the JIT code. The stack pointer (and a
// number of other things) can be accessed using indexed addressing from
// nilreg.
    Register nilreg  = cc.newIntPtr("nilreg");
    Register spreg   = cc.newIntPtr("spreg");
    Register spentry = cc.newIntPtr("spentry");

// The check for the right number of arguments when there are more than
// 3 has to be dynamic, so I must be ready to return with a failure response.
// Ditto cases where I call a sub-function which may fail, and so I need
// to propagate the failure. I also have a single label for use returning
// the value in the A register, and a vector of labels where I set one
// on the expansion of each bytecode so that if there is a branch to
// it I can handle that.
    Label tooFewArgs  = cc.newLabel();
    Label tooManyArgs = cc.newLabel();
    Label callFailed  = cc.newLabel();
    Label carError    = cc.newLabel();
    Label cdrError    = cc.newLabel();
    Label returnA     = cc.newLabel();
// I am going to set a label on the code that corresponds to each bytecode
// so that I can handle the jumps there.
    std::vector<Label> perInstruction;
    for (size_t i=0; i<len; i++)
        perInstruction.push_back(cc.newLabel());
// I will be compiling functions with various numbers of arguments. Here I
// need to set up a suitable function signature and associate asmjit registers
// with all of the arguments.
    FuncNode* funcNode;
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

// Now I initialise some registers and put arguments on the Lisp stack. The
// logic is the same on all platforms, but the instructions available to
// do things differ.
#ifdef __x86_64
    cc.mov(nilreg, nil);
    cc.mov(A_reg, nilreg);
// Load spreg to hold the stack pointer.
    cc.mov(spreg, ptr(nilreg, JIToffset(Ostack)));
    cc.mov(spentry, spreg);
// In CSL if a Lisp/Reduce-level function has 4 or more arguments it in fact
// passes just the first 3 separately - all the rest are passed in a list.
// Here I need to disentangle that. I push all the arguments onto the Lisp
// stack at spreg. Note that this does noy update the C++ variable, and if
// at any time I do a function call I will need to bring that up to date.
// If I do change the C++ version I will need to restore it from spentry
// before I exit.
    for (int i=1; i<=nargs&&i<4; i++)
    {   cc.add(spreg, 8);
        cc.mov(ptr(spreg), argregs[i]);
        stdout_printf("Just moved arg %d to stack\n", i);
    }
    if (nargs>=4)
    {   cc.mov(w1, w);
        for (int i=4; i<=nargs; i++)
        {
// Here I need to unpack arg4 and up. This has to go sort of
//          if atom w1 then return "called with too few arguments"
//          aX = car(w1); w1 = cdr(w1)   // until X=nargs
// Now in lower-level language that is
//          if ((w1 & TAG_BITS) != TAG_CONS) goto tooFewArgs;
//          aX = w1[0];
//          w1 = w1[1];
            cc.test(w1, TAG_BITS);
            cc.jne(tooFewArgs);
            cc.mov(argregs[i], ptr(w1));
            cc.mov(w1, ptr(w1, 8));
            cc.add(spreg, 8);
            cc.mov(ptr(spreg), argregs[i]);
        }
        cc.cmp(w1, nilreg);
        cc.jne(tooManyArgs);
    }
#elif defined __aarch64__
    cc.mov(nilreg, nil);
    loadreg(cc, spreg, nilreg, JIToffset(Ostack));
    cc.mov(spentry, spreg);
    cc.mov(A_reg, nilreg);
// On the arm I can use an addressing node that offsets from the
// base register that is used and then updates the register. So I do not
// need the "add" that you saw in the x86_64 version.
    for (int i=1; i<=nargs&&i<4; i++)
    {   cc.str(argregs[i], ptr_pre(spreg, 8));
        stdout_printf("Just moved arg %d to stack\n", i);
    }
    if (nargs>=4)
    {   cc.mov(w1, w);
        for (int i=4; i<=nargs; i++)
        {   cc.tst(w1, TAG_BITS);
            cc.b_ne(tooFewArgs);
            cc.ldr(argregs[i], ptr(w1));
            cc.ldr(w1, ptr(w1, 8));
            cc.str(argregs[i], ptr_pre(spreg));
        }
        cc.cmp(w1, nilreg);
        cc.b_ne(tooManyArgs);
    }
#else
#error unrecognised architecture for JIT
#endif

// The part from HERE will be to a large extent platform independent
// in this file, but the #included files all discrimate on x86_64 vs aarch64.

    TRY
    {   size_t ppc = 0;
        int next;
        while (ppc<len)
        {
// Set a label on the code that derives from each opcode. Note that
// because the "case" code for some opcode will increment ppc there will
// be some of the labels that are neither defined nor used.
            cc.bind(perInstruction[ppc]);
            stdout_printf("Byte %.2x : %s\n", bytes[ppc], opnames[bytes[ppc]]);
            switch (bytes[ppc++])
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
// There are labels here for error exits. At present I do not handle the
// errors!
    cc.bind(tooFewArgs);
        loadreg(cc, w, litvec, CELL-TAG_VECTOR);
        storereg(cc, w, nilreg, JIToffset(OJITarg1));
        loadreg(cc, w, nilreg, JIToffset(OJITtoofew));
        cc.chain(w);
    cc.bind(tooManyArgs);
        loadreg(cc, w, litvec, CELL-TAG_VECTOR);
        storereg(cc, w, nilreg, JIToffset(OJITarg1));
        loadreg(cc, w, nilreg, JIToffset(OJITtoomany));
        cc.chain(w);
    cc.bind(callFailed);
        storereg(cc, spentry, nilreg, JIToffset(Ostack));
        loadreg(cc, w, nilreg, JIToffset(OJITthrow));
        cc.chain(w);
    cc.bind(carError);
        storereg(cc, spentry, nilreg, JIToffset(Ostack));
        storereg(cc, w=A_reg, nilreg, JIToffset(OJITarg1));
        loadreg(cc, w, nilreg, JIToffset(OJITcar_fails));
        cc.chain(w);
    cc.bind(cdrError);
        storereg(cc, spentry, nilreg, JIToffset(Ostack));
        storereg(cc, w=A_reg, nilreg, JIToffset(OJITarg1));
        loadreg(cc, w, nilreg, JIToffset(OJITcdr_fails));
        cc.chain(w);

    cc.bind(returnA);
// Ensure that the Lisp stack pointer is in a good state.
    storereg(cc, spentry, nilreg, JIToffset(Ostack));
    cc.ret(A_reg);

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

    stdout_printf(" JITstring = %p\n",  JITstring);
    stdout_printf(" JITarg1 = %p\n",    JITarg1);
    stdout_printf(" JITarg2 = %p\n",    JITarg2);
    stdout_printf(" JITthrow = %p\n",   JITthrow);
    stdout_printf(" JITshim0 = %p\n",   JITshim0);
    stdout_printf(" JITshim1 = %p\n",   JITshim1);
    stdout_printf(" JITshim2 = %p\n",   JITshim2);
    stdout_printf(" JITshim3 = %p\n",   JITshim3);
    stdout_printf(" JITshim4 = %p\n",   JITshim4);
    stdout_printf(" JITshim1B = %p\n",  JITshim1B);
    stdout_printf(" JITshim2B = %p\n",  JITshim2B);
    stdout_printf(" JITlessp = %p\n",   JITlessp);
#ifdef ARITHLIB
    stdout_printf(" JITsub1op = %p\n",  JITsub1op);
#else // ARITHLIB
    stdout_printf(" JITplus2 = %p\n",   JITplus2);
#endif

    return func;
}

// This is to report on the bytecodes that are not at present implemented
// in the JIT. It does this by passing each opcode byte in turn through the
// generation process and trapping if the "unsupported" exception is
// raising. While it is doing this it will emit some utter junk by way of
// generated code - but to do that it needs registers etc set up as if it
// was being used sensibly.

LispObject Ljit_unfinished(LispObject env)
{   int numberUnfinished = 0;
    int online = 0;
    CodeHolder code;
    Environment localEnv = rt.environment();;
    code.init(localEnv, rt.cpuFeatures());
    JitError jitError;
    code.setErrorHandler(&jitError);
#if defined __x86_64__
typedef x86::Gp Register;
    LocalCompiler cc = x86::Compiler(&code);
#elif defined __aarch64__
typedef a64::Gp Register;
    LocalCompiler cc = a64::Compiler(&code);
#endif
    Register litvec = cc.newIntPtr("litvec");
    Register argregs[16];
    for (size_t i=1; i<=15; i++)
        argregs[i] = cc.newIntPtr("a1");
    Register w       = cc.newIntPtr("w");
    Register w1      = cc.newIntPtr("w1");
    Register w2      = cc.newIntPtr("w2");
    Register A_reg   = cc.newIntPtr("A_reg");
    Register B_reg   = cc.newIntPtr("B_reg");
    Register spreg   = cc.newIntPtr("spreg");
    Register nilreg  = cc.newIntPtr("nilreg");
    Label callFailed = cc.newLabel();
    Label carError   = cc.newLabel();
    Label cdrError   = cc.newLabel();
    Label returnA    = cc.newLabel();
    std::vector<Label> perInstruction;
    for (size_t i=0; i<256; i++)
        perInstruction.push_back(cc.newLabel());
    unsigned char bytes[512];
    for (size_t i=0; i<sizeof(bytes); i++) bytes[i] = 0;
    size_t ppc = 0;
    int next;
    testingForUnfinished = true;
    stdout_printf("\nThe following opcodes are not yet coded for %s\n", ARCH);
    for (unsigned int code=0; code<256; code++)
    {   TRY
        {   switch (code)
            {
#include "ops/bytes_include.cpp"
            }
        }
        CATCH (JitFailed)
        {   stdout_printf("%s", opnames[code]);
            for (size_t col=strlen(opnames[code]);col<15; col++)
                stdout_printf(" ");
            if (++online == 5)
            {   stdout_printf("\n");
                online = 0;
            }
            numberUnfinished++;
        }
        END_CATCH;
    }
    if (online != 0) stdout_printf("\n");
    stdout_printf("\nThere is support for the following...\n");
    ppc = 0;
    online = 0;
    for (unsigned int code=0; code<256; code++)
    {   bool failed = false;
        TRY
        {   switch (code)
            {
#include "ops/bytes_include.cpp"
            }
        }
        CATCH (JitFailed)
        {   failed = true;
        }
        END_CATCH;
        if (!failed)
        {   stdout_printf("%s", opnames[code]);
            for (size_t col=strlen(opnames[code]);col<15; col++)
                stdout_printf(" ");
            if (++online == 5)
            {   stdout_printf("\n");
                online = 0;
            }
        }
    }
    if (online != 0) stdout_printf("\n");
    testingForUnfinished = false;
// In reporting the number of cases I still have to do I will discount
// the 2 opcodes that are currently spare.
    stdout_printf("\n%d bytecodes handled so %d still need review\n",
                  256-numberUnfinished, numberUnfinished-2);
    return nil;
}

#else // ENABLE_JIT

// The functions here are no use, but are provided so that image files
// are compatible across architectures. By always returning nullptr this
// reports that it is unable to map from bytecodes to native instructions.

void* jitcompile(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{   return nullptr;
}

LispObject Ljit_unfinished(LispObject env)
{   return nil;
}

#endif // ENABLE_JIT

// end of jit.cpp
