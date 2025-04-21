// jit.cpp                                      Copyright (C) 2025 Codemist

//
// Just-in-time compiler framework
//

// Parts of the code here have been developed by and with Miriam Brody
// and Ella Zhu while they were visiting the University of Cambridge as
// part of their studies at Pomona College, Claremont in the first half
// of 2025.

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

#ifdef __x86_64__
#include <asmjit/x86.h>
#endif
#ifdef __aarch64__
#include <asmjit/a64.h>
#endif

#ifdef __linux__
#include <execinfo.h>
#include <cstdio>
#include <cstdlib>
#endif // __linux__

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
// been going to have essentially two copies. Also loadreg and storereg
// are a level of abstraction above the machine architecture so that I
// can use those when I need to generate something thart on ARM is
// LDR or STR but on Intel is simply MOV.

#if defined __x86_64__
#define ARCH "x86_64"
typedef x86::Gp Register;
typedef x86::Compiler LocalCompiler;
#elif defined __aarch64__
#define ARCH "aarch64"
typedef a64::Gp Register;
typedef a64::Compiler LocalCompiler;
#else
#define ARCH "unknown"
#error unrecognised architecture for JIT
#endif

#ifdef __linux__

// The GNU library on Linux provides functions that make it possible
// to display a backtrace. While I am not certain that this information
// will be useful I will use it for when asmjit needs to report issue
// regarding the way I use it.

void print_trace()
{   void* array[10];
    int size = backtrace(array, 10);
    char** strings = backtrace_symbols(array, size);
    if (strings != NULL)
    {   printf("Obtained %d stack frames.\n", size);
        for (int i = 0; i<size; i++)
            printf ("%s\n", strings[i]);
    }
    free(strings);
}

#endif // __linux__

// This class will be used if the way I try to call asmjit is bad.

class JitError : public ErrorHandler
{
public:
    void handleError(Error err, const char* msg, BaseEmitter* origin) override
    {   stdout_printf("+++ AsmJit error: %s\n", msg);
#ifdef __linux__
        print_trace();
#endif // __linux__
        throw JitFailed("asmjit reported trouble");
    }
};

JitError jitError;
FileLogger myFileLogger(stdout);


intptr_t savePPC, saveA, saveB, saveSP, saveSPentry;

void JITdebugprint(void)
{   std::cout << "\n";
    std::cout << "ppc     = " << savePPC << std::hex << " : " << savePPC << "\n";
    std::cout << "nil     = " << nil << " = "; dpr(nil);
    std::cout << "A_reg   = " << saveA << " = "; dpr(saveA);
    std::cout << "B_reg   = " << saveB << " = "; dpr(saveB);
    for (intptr_t p=saveSP; p>=saveSPentry; p-=sizeof(intptr_t))
    {   std::cout << std::dec << ((saveSP-p)/sizeof(intptr_t))
                  << ":  " << std::hex
                  << *reinterpret_cast<intptr_t*>(p) << " = ";
        dpr(*reinterpret_cast<intptr_t*>(p));
    }
    std::cout << std::dec;
}

// My class JITcompile extends x86::Compiler or a64::Compiler and as such
// all the assembly code opcodes like "mov" and so on are directly available.
// So eg code within it can go just
//     mov(B_reg, A_reg);
// rather than
//     cc.mov(B_reg, A_reg);
// For this to be useful I also want A_reg and its friends and all the
// labels I need to use to be fields within the class so that accessing
// them is utterly straightforward.


JitRuntime rt;

class JITCompile : public LocalCompiler 
{
public:

    JITCompile(CodeHolder* ch) : LocalCompiler(ch)
    {}

    Register A_reg, B_reg, litvec, nilreg, spreg, spentry, w, w1, w2, w3, w4;
    Register argregs[16];

    size_t ppc;
    bool freebind_used;

    Label tooFewArgs, tooManyArgs, callFailed,
          carError, cdrError, returnA, chainA;
    std::vector<Label> perInstruction;

// I am not going to indent the remainder of the code here but making the
// first bits of the definition of the class stress its structures should
// help readers...

#if defined __x86_64__

Error loadreg(Register& r, Register& base, intptr_t offset)
{   return mov(r, ptr(base, offset));
}

Error storereg(Register& r, Register& base, intptr_t offset)
{   return mov(ptr(base, offset), r);
}

Error loadreg_pre(Register& r, Register& base, intptr_t offset)
{   if (offset < 0) ASMJIT_PROPAGATE(sub(base, -offset));
    else ASMJIT_PROPAGATE(add(base, offset));
    return mov(r, ptr(base));
}

Error storereg_pre(Register& r, Register& base, intptr_t offset)
{   if (offset < 0) ASMJIT_PROPAGATE(sub(base, -offset));
    else ASMJIT_PROPAGATE(add(base, offset));
    return mov(ptr(base), r);
}

Error loadreg_post(Register& r, Register& base, intptr_t offset)
{   ASMJIT_PROPAGATE(mov(r, ptr(base)));
    if (offset < 0) return sub(base, -offset);
    else return add(base, offset);
}

Error storereg_post(Register& r, Register& base, intptr_t offset)
{   ASMJIT_PROPAGATE(mov(ptr(base), r));
    if (offset < 0) return sub(base, -offset);
    else return add(base, offset);
}

#elif defined __aarch64__

// The ARM has a smaller range of valid offsets when the offset is not
// a multiple of the word-size, so in cases that would overflow that I
// insert an extra add or subtract instruction. The code is ugly here and
// needs re-work, and then migration into all the other variants on
// load and store!

Error loadreg(Register& r, Register& base, intptr_t offset)
{   if ((offset & 7) != 0 && (offset < -256 || offset >= 256))
    {   Register b1 = newIntPtr("b1");
        int32_t n = offset & 0xfff;
        if (offset < 0)
        {   n |= 0xfffffffffffff000;
            ASMJIT_PROPAGATE(sub(b1, base, -n));
        }
        else ASMJIT_PROPAGATE(add(b1, base, n));
        offset -= n;
        return ldr(r, ptr(base, offset));
    }
    return ldr(r, ptr(base, offset));
}

Error storereg(Register& r, Register& base, intptr_t offset)
{   return str(r, ptr(base, offset));
}

Error loadreg_pre(Register& r, Register& base, intptr_t offset)
{   return ldr(r, ptr_pre(base, offset));
}

Error storereg_pre(Register& r, Register& base, intptr_t offset)
{   return str(r, ptr_pre(base, offset));
}

Error loadreg_post(Register& r, Register& base, intptr_t offset)
{   return ldr(r, ptr_post(base, offset));
}

Error storereg_post(Register& r, Register& base, intptr_t offset)
{   return str(r, ptr_post(base, offset));
}

#else
#define ARCH "unknown"
#error unrecognised architecture for JIT
#endif

// The next two can be used to load and store from locations identified
// by names like Olisp_true, Ostack, OJITshim5 and many others. The
// storage involved is addressed relative to a register that holds the
// nalue of nil.

Error loadstatic(Register& r, NilOffset n)
{   return loadreg(r, nilreg, n);
}

Error storestatic(Register& r, NilOffset n)
{   return storereg(r, nilreg, n);
}

// litvec holds a (tagged) pointer to a vector of the literals that the
// so this loads or stores a register using the nth item in the vector.
// Entry 0 must always be the name of the function (that is relied upon
// when generating diagnostics).

Error loadlit(Register& r, int n)
{   return loadreg(r, litvec, 8*n+CELL-TAG_VECTOR);
}

Error storelit(Register& r, int n)
{   return storereg(r, litvec, 8*n+CELL-TAG_VECTOR);
}

// Now functions that move values between the (Lisp) stack and registers.
// The stack grows upwards so the nth item is 8*n bytes down from its
// fringe.

Error loadloc(Register& r, int n)
{   return loadreg(r, spreg, -8*n);
}

Error storeloc(Register& r, int n)
{   return storereg(r, spreg, -8*n);
}

// The register sym points to a Lisp symbol, and these two access fields
// within it using Ovalue, Oenv, Ofunction0 etc to identify what needs
// to be worked upon.

Error loadfromsymbol(Register& r,  Register& sym, size_t n)
{   return loadreg(r, sym, n-TAG_SYMBOL);
}

Error storetosymbol(Register& r,  Register& sym, size_t n)
{   return storereg(r, sym, n-TAG_SYMBOL);
}

// Some overloads for setting up function calls with 0, 1,... args,
// where all the arguments are values to be passed in general purpose
// registers. This means that the arguments can be (u)intptr_t, T* or
// LispObject at the C++ level.

template <typename T>
Error JITcallVoid(T target)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(invoke(&in, target, FuncSignature::build<>()));
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result)
{   InvokeNode *in;
// I must bring the Lisp variable holding a stack pointer up to date.
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(invoke(&in, target,
        FuncSignature::build<LispObject>()));
    in->setRet(0, result);
// In general I do not restore spreg from the global variable here because
// the value in that register will have been preserved for me. If the
// function I am calling could legitimately alter the Lisp stack pointer I
// will need to deal with that explicitly.
    return kErrorOk;
}

#ifdef __aarch64__

// on the ARM I will usually not be able to address function entrypoints in
// "bl" instructions since the body of my regularly compiled code will live
// at memory addresses remote from the place where JIT-generated code is
// placed.

Error JITinvoke(InvokeNode** out, const Imm& target, const FuncSignature& sig)
{   Register tt = newIntPtr("tt");
    ASMJIT_PROPAGATE(mov(tt, target));
    return invoke(out, tt, sig);
}

Error JITinvoke(InvokeNode** out, uint64_t target, const FuncSignature& sig)
{   Register tt = newIntPtr("tt");
    ASMJIT_PROPAGATE(mov(tt, target));
    return invoke(out, tt, sig);
}

Error JITinvoke(InvokeNode** out, Register& target, const FuncSignature& sig)
{   return invoke(out, target, sig);
}

#else // __aarch64__

Error JITinvoke(InvokeNode** out, const Imm& target, const FuncSignature& sig)
{   return invoke(out, target, sig);
}

Error JITinvoke(InvokeNode** out, uint64_t target, const FuncSignature& sig)
{   return invoke(out, target, sig);
}

Error JITinvoke(InvokeNode** out, Register& target, const FuncSignature& sig)
{   return invoke(out, target, sig);
}

#endif // __aarch64__

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject>()));
    in->setArg(0, a1);
    in->setRet(0, result);
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1, Register& a2)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject, LispObject>()));
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setRet(0, result);
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1, Register& a2, Register& a3)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject, LispObject, LispObject>()));
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setRet(0, result);
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1, Register& a2, Register& a3, Register& a4)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject, LispObject,
                             LispObject, LispObject>()));
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setArg(3, a4);
    in->setRet(0, result);
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1, Register& a2,
              Register& a3, Register& a4,
              Register& a5)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject, LispObject, LispObject,
                             LispObject, LispObject>()));
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setArg(3, a4);
    in->setArg(4, a5);
    in->setRet(0, result);
    return kErrorOk;
}

template <typename T>
Error JITcall(T target, Register& result,
              Register& a1, Register& a2,
              Register& a3, Register& a4,
              Register& a5, Register& a6)
{   InvokeNode *in;
    ASMJIT_PROPAGATE(storestatic(spreg, Ostack));
    ASMJIT_PROPAGATE(JITinvoke(&in, target,
        FuncSignature::build<LispObject,
                             LispObject, LispObject, LispObject,
                             LispObject, LispObject, LispObject>()));
    in->setArg(0, a1);
    in->setArg(1, a2);
    in->setArg(2, a3);
    in->setArg(3, a4);
    in->setArg(4, a5);
    in->setArg(5, a6);
    in->setRet(0, result);
    return kErrorOk;
}

#ifdef __aarch64__

// To make cross-platform coding easier I define functions named for
// all the x86_64 jump instructions such that they expand into and
// generate the equivalent aarch64 variant of branch. Then I can use
// just one name for a jump whichever architecture is involved.

Error ja(Label& lab)          // above            >U
{   return b_hi(lab);
}

Error jae(Label& lab)         // above or equal   >=U
{   return b_hs(lab);
}

Error jb(Label& lab)          // below            <U
{   return b_lo(lab);
}

Error jbe(Label& lab)         // below or equal   <=U
{   return b_ls(lab);
}

Error jc(Label& lab)          // (unsigned) carry
{   return b_lo(lab);
}

Error je(Label& lab)          // equal            ==
{   return b_eq(lab);
}

//Error jecxz(Label& lab)     // 64-bit register ecx==0
//{   return b(lab);
//}

Error jg(Label& lab)          // greater           >
{   return b_gt(lab);
}

Error jge(Label& lab)         // greater or equal  >=
{   return b_ge(lab);
}

Error jl(Label& lab)          // less              <
{   return b_lt(lab);
}

Error jle(Label& lab)         // less or equal     <=
{   return b_le(lab);
}

Error jmp(Label& lab)         // unconditional
{   return b(lab);
}

Error jna(Label& lab)         // not above         <=U
{   return b_ls(lab);
}

Error jnae(Label& lab)        // not above or equal <U
{   return b_lo(lab);
}

Error jnb(Label& lab)         // not below          >=U
{   return b_hs(lab);
}

Error jnbe(Label& lab)        // not below or equal >U
{   return b_hi(lab);
}

Error jnc(Label& lab)         // (unsigned) carry clear
{   return b_hs(lab);
}

Error jne(Label& lab)         // not equal           !=
{   return b_ne(lab);
}

Error jng(Label& lab)         // not greater         <=
{   return b_le(lab);
}

Error jnge(Label& lab)        // not greater or equal <
{   return b_lt(lab);
}

Error jnl(Label& lab)         // not less             >=
{   return b_ge(lab);
}

Error jnle(Label& lab)        // not less or equal    >
{   return b_gt(lab);
}

Error jno(Label& lab)         // no overflow
{   return b_vc(lab);
}

Error jnp(Label& lab)         // not positive         <0
{   return b_mi(lab);
}

Error jns(Label& lab)         // not same             !=
{   return b_ne(lab);
}

Error jnz(Label& lab)         // not zero             !=0
{   return b_ne(lab);
}

Error jo(Label& lab)          // (signed) overflow
{   return b_vs(lab);
}

Error jp(Label& lab)          // positive             >0
{   return b_pl(lab);
}

// Note that aarch64 provides a "cnt" instruction that counts the 1-bits
// in a register and that makes finding parity easy.

//Error jpe(Label& lab)       // parity even
//{   return b_pl(lab);          not available on ARM
//}

//Error jpo(Label& lab)       // parity odd
//{   return b(lab);             not available on ARM
//}

Error js(Label& lab)          // sign bit set         <0
{   return b_mi(lab);
}

Error jz(Label& lab)          // zero                 =0
{   return b_eq(lab);
}

// Also test vs tst and a few others

Error test(Register& r, Imm n)
{   return tst(r, n);
}

Error sar(Register& r, Imm n)
{   return asr(r, r, n);
}

Error add2(Register& r1, Imm n)
{   if (n.value() < 0) return sub(r1, r1, -n.value());
    return add(r1, r1, n);
}

Error add2(Register& r1, Register& r2)
{   return add(r1, r1, r2);
}

Error sub2(Register& r1, Imm n)
{   if (n.value() < 0) return add(r1, r1, -n.value());
    return sub(r1, r1, n);
}

Error sub2(Register& r1, Register& r2)
{   return sub(r1, r1, r2);
}

Error and2(Register& r1, Imm n)
{   return and_(r1, r1, n);
}

Error and2(Register& r1, Register& r2)
{   return and_(r1, r1, r2);
}

Error add3(Register& r1, Register& r2, Imm n)
{   return add(r1, r2, n);
}

Error add3(Register& r1, Register& r2, Register& r3)
{   return add(r1, r2, r3);
}

Error and3(Register& r1, Register& r2, Imm n)
{   return and_(r1, r2, n);
}

Error and3(Register& r1, Register& r2, Register& r3)
{   return and_(r1, r2, r3);
}

#endif // __aarch64__

#ifdef __x86_64__

// These let me write 3-arg versions of these functions even in x86_64 mode
// eg in cases where that would be better on ARM.

Error add2(Register& r1, Imm n)
{   return add(r1, n);
}

Error add2(Register& r1, Register& r2)
{   return add(r1, r2);
}

Error sub2(Register& r1, Imm n)
{   return sub(r1, n);
}

Error sub2(Register& r1, Register& r2)
{   return sub(r1, r2);
}

Error and2(Register& r1, Imm n)
{   return and_(r1, n);
}

Error and2(Register& r1, Register& r2)
{   return and_(r1, r2);
}

Error add3(Register& r1, Register& r2, Imm n)
{   if (r1 != r2) ASMJIT_PROPAGATE(mov(r1, r2));
    return add(r1, n);
}

Error add3(Register& r1, Register& r2, Register& r3)
{   if (r1 == r2) return add(r1, r3);
    if (r2 == r3) return add(r1, r2);
    ASMJIT_PROPAGATE(mov(r1, r2));
    return add(r1, r3);
}

Error sub3(Register& r1, Register& r2, Imm n)
{   if (r1 != r2) ASMJIT_PROPAGATE(mov(r1, r2));
    return sub(r1, n);
}

Error sub3(Register& r1, Register& r2, Register& r3)
{   if (r1 == r2) return sub(r1, r3);
    if (r2 == r3) return sub(r1, r2);
    ASMJIT_PROPAGATE(mov(r1, r2));
    return sub(r1, r3);
}

Error and3(Register& r1, Register& r2, Imm n)
{   if (r1 != r2) ASMJIT_PROPAGATE(mov(r1, r2));
    return and_(r1, n);
}

Error and3(Register& r1, Register& r2, Register& r3)
{   if (r1 == r2) return and_(r1, r3);
    if (r2 == r3) return and_(r1, r2);
    ASMJIT_PROPAGATE(mov(r1, r2));
    return and_(r1, r3);
}

#endif // _x86_64__

// After many (but not all!) calls it is necessary to check for any
// reported error state:

Error JITerrorcheck()
{
// This checks if the bottom byte of JITerrflag is zero.
#if defined __x86_64__
    ASMJIT_PROPAGATE(cmp(ptr(nilreg, OJITerrflag, 1), 0));
#elif defined __aarch64__
    ASMJIT_PROPAGATE(ldursb(w, ptr(nilreg, OJITerrflag)));
    ASMJIT_PROPAGATE(cmp(w, 0));
#endif
    return jne(callFailed);
}

Error JITatomic(Register& r, Label& l)
{   ASMJIT_PROPAGATE(test(r, TAG_BITS));
    return jne(l);
}

Error JITnotatomic(Register& r, Label& l)
{   ASMJIT_PROPAGATE(test(r, TAG_BITS));
    return je(l);
}

Error JITcarvalid(Register& r)
{   return JITatomic(r, carError);
}

Error JITcdrvalid(Register& r)
{   return JITatomic(r, cdrError);
}

void debugHere(intptr_t ppc)
{
// I generate a spurius "mov" instruction that loads a register not relevent
// between bytes with a value that has the address within the bytecode stream
// in its low 3 digits. This is arranged so that the information there will
// be readily visible whether I display the operand of the "mov" in decimal
// or hex.
    mov(w2, 1024000+ppc);
#if defined __x86_64__
// Here I have a way of printing the state of the machine (A and B registers
// and stack)... At present I have just set it up for x86_64.
    if (mov(x86::Mem((uint64_t)&savePPC, 8), w2)) std::cout << "Line" << __LINE__ << "\n";
    if (mov(x86::Mem((uint64_t)&saveA, 8), A_reg)) std::cout << "Line" << __LINE__ << "\n";
    if (mov(x86::Mem((uint64_t)&saveB, 8), B_reg)) std::cout << "Line" << __LINE__ << "\n";
    if (mov(x86::Mem((uint64_t)&saveSP, 8), spreg)) std::cout << "Line" << __LINE__ << "\n";
    if( mov(x86::Mem((uint64_t)&saveSPentry, 8), spentry)) std::cout << "Line" << __LINE__ << "\n";
    if (JITcallVoid(JITdebugprint)) std::cout << "Line" << __LINE__ << "\n";
#endif
}

static LispObject displayreg(LispObject u)
{   std::cout << u << " " << std::hex << u << std::dec << "\n";
    return nil;
}

void switchBlock(const unsigned char* bytes)
{   intptr_t next;
    switch (bytes[ppc++])
    {
#include "ops/bytes_include.cpp"
    }
}

// When a function is potentially going to be JIT compiled it will
// have one of jitcoded_0 to jitcoded_4up in a function call where otherwise
// it would have had bytecoded_0 etc. At present I an not considering
// byteopt_0... , hardopt_0... byteoptrest_0... or hardoptrest_0...
// because they are not used by Reduce and I will be pleased if I can get the
// simpler cases with a known number of arguments dealt with nicely.

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

void* jitcompile(const unsigned char* bytes, size_t len,
                 LispObject env, int nargs,
                 CodeHolder& myCodeHolder)
{
    if (qvalue(jit_noisy) != nil)
    {
// I am going to start by printing the byte-stream
        stdout_printf("\n=== jitcompile on ");
        dpr(basic_elt(env, 0));
        stdout_printf("Bytecodes...\n");
        for (size_t i=0; i<len; i++)
        {   int op = bytes[i];
            int len = oparginfo[op] & 3;
            stdout_printf("%3u:  %02x", i, op);
            for (int k=2; k<=3; k++)
                if (k<=len) stdout_printf(" %02x", bytes[++i]);
                else stdout_printf("   ");
            stdout_printf(" %s\n", opnames[op]);
        }
// The literal at offset zero is the name of the function, and the
// final entry is an integer checksum
        stdout_printf("Vector of literals...\n");
        for (size_t i=0; i<(length_of_header(vechdr(env))-CELL)/CELL; i++)
        {   stdout_printf("%3d: ", i);
            dpr(basic_elt(env, i));
        }
    }
// I am going to support functions with up to 15 arguments - anything
// beyond that I will declare unsuitable to mapping into hard code.
// Well the function in the Reduce sources with most arguments is
// add3sint() in fide and that has 14, so this is not a limit that
// with restrict me.
    if (nargs > 15) return nullptr;
//
// Set up to use asmjit. The code here just creates and initialises
// various things that it needs. I arrange that the CodeHolder is
// amd object that remains in place throughout the run.

// Here I need to specify the type signature of the function that I am
// creating and associate some names with the arguments it will receive.
// The function I am defining will have min(nargs+1, 5) arguments
// each of which is a LispObject. It is going to have to start by
// pushing all these onto the (Lisp) stack. So for instance if this
// is going to be a function that expects (in the Lisp sense!) 2 arguments
// its signature in C++ and first few lines would have been
//    LispObject foo(LispObject litvec, LispObject a1, LispObject a2)
//    {   RealSave save(litvec, a1, a2);
// where the RealSave obect's constructor has gone in effect
//       *stack++ = litvec;
//       *stack++ = a1;
//       *stack++ = a2;
// and then set things up so that when the function terminates that
// stack is set back to its initial value.
// Througout the JIT body I will keep a copy of the C++ value of nil
// and of the variable "stack" in registers. I will also store the value
// that stack has on entry to the function. I will write stack back
// before calling a function from the JIT code. The stack pointer (and a
// number of other things) can be accessed using indexed addressing from
// nilreg.
    nilreg  = newIntPtr("nilreg");
    spreg   = newIntPtr("spreg");
    A_reg  = newIntPtr("A_reg");
    B_reg  = newIntPtr("B_reg");
    litvec = newIntPtr("litvec");
// I would really like some of these to end up in registers! I hope
// that use of setWeight will coax asmjit into achieving that. However
// what I have here in the commente dout code does not work!
//@@    nilreg.setWeight(255);
//@@    spreg.setWeight(255);
//@@    A_reg.setWeight(255);
//@@    B_reg.setWeight(128);
//@@    litvec.setWeight(128);
    spentry = newIntPtr("spentry");
    w      = newIntPtr("w");
    w1     = newIntPtr("w1");
    w2     = newIntPtr("w2");
    w3     = newIntPtr("w3");
    w4     = newIntPtr("w4");
// I will set up enough registers for up to 15 arguments but in most cases
// almost all of those will not be used.
    for (size_t i=1; i<=15; i++)
        argregs[i] = newIntPtr("a1");

// The check for the right number of arguments when there are more than
// 3 has to be dynamic, so I must be ready to return with a failure response.
// Ditto cases where I call a sub-function which may fail, and so I need
// to propagate the failure. I also have a single label for use returning
// the value in the A register, and a vector of labels where I set one
// on the expansion of each bytecode so that if there is a branch to
// it I can handle that.
    tooFewArgs  = newLabel();
    tooManyArgs = newLabel();
    callFailed  = newLabel();
    carError    = newLabel();
    cdrError    = newLabel();
    returnA     = newLabel();
    chainA      = newLabel();
// I am going to set a label on the code that corresponds to each bytecode
// so that I can handle the jumps there.
    for (size_t i=0; i<len; i++)
        perInstruction.push_back(newLabel());
// I will be compiling functions with various numbers of arguments. Here I
// need to set up a suitable function signature and associate asmjit registers
// with all of the arguments.
    FuncNode* funcNode;
    switch (nargs)
    {
    case 0:
        funcNode = newFunc(
            FuncSignature::build<LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        break;
    case 1:
        funcNode = newFunc(
            FuncSignature::build<LispObject, LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        break;
    case 2:
        funcNode = newFunc(
            FuncSignature::build<LispObject, LispObject,
                                 LispObject, LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        funcNode->setArg(2, argregs[2]);
        break;
    case 3:
        funcNode = newFunc(
            FuncSignature::build<LispObject, LispObject,
                                 LispObject, LispObject,
                                 LispObject>());
        funcNode->setArg(0, litvec);
        funcNode->setArg(1, argregs[1]);
        funcNode->setArg(2, argregs[2]);
        funcNode->setArg(3, argregs[3]);
        break;
    default:          // 4 or more
        funcNode = newFunc(
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
    addFunc(funcNode);
#ifdef __x86__
// On x86_64 processors there is a security concern about wild branch
// instructions that enter code other that at official entrypoints. So
// in some cases there will be an insistence that the target for an
// indirect jump should be the instruction "endbr64" and jumps that do not
// find that at their destination may be though of as improper and may
// raise an exception. The instruction here is a no-op and at some level
// its presence merely wastes time and space, but it is safest to put it
// against a future where its presence is enforced.
    endbr64();
#endif // __x86_64
// Now I initialise some registers and put arguments on the Lisp stack. The
// logic is the same on all platforms, but the instructions available to
// do things differ.
#ifdef __x86_64
    mov(nilreg, nil);
    mov(A_reg, nilreg);
#ifdef DEBUG
// Initialize if in debugging mode.
    mov(B_reg, nilreg);
#endif
// Load spreg to hold the stack pointer.
    loadstatic(spreg, Ostack);
    mov(spentry, spreg);
// In CSL if a Lisp/Reduce-level function has 4 or more arguments it in fact
// passes just the first 3 separately - all the rest are passed in a list.
// Here I need to disentangle that. I push all the arguments onto the Lisp
// stack at spreg. Note that this does noy update the C++ variable, and if
// at any time I do a function call I will need to bring that up to date.
// If I do change the C++ version I will need to restore it from spentry
// before I exit.
    for (int i=1; i<=nargs&&i<4; i++)
        storereg_pre(argregs[i], spreg, 8);
    if (nargs>=4)
    {   mov(w1, w);
        for (int i=4; i<=nargs; i++)
        {
// Here I need to unpack arg4 and up. This has to go sort of
//          if atom w1 then return "called with too few arguments"
//          aX = car(w1); w1 = cdr(w1)   // until X=nargs
// Now in lower-level language that is
//          if ((w1 & TAG_BITS) != TAG_CONS) goto tooFewArgs;
//          aX = w1[0];
//          w1 = w1[1];
            JITatomic(w1, tooFewArgs);
            loadreg(argregs[i], w1, 0);
            loadreg(w1, w1, 8);
            storereg_pre(argregs[i], spreg, 8);
        }
        cmp(w1, nilreg);
        jne(tooManyArgs);
    }
#elif defined __aarch64__
    mov(nilreg, nil);
    loadstatic(spreg, Ostack);
    mov(spentry, spreg);
    mov(A_reg, nilreg);
// On the arm I can use an addressing node that offsets from the
// base register that is used and then updates the register. So I do not
// need the "add" that you saw in the x86_64 version.
    for (int i=1; i<=nargs&&i<4; i++)
    {   storereg_pre(argregs[i], spreg, 8);
    }
    if (nargs>=4)
    {   mov(w1, w);
        for (int i=4; i<=nargs; i++)
        {   JITatomic(w1, tooFewArgs);
            ldr(argregs[i], ptr(w1));
            ldr(w1, ptr(w1, 8));
            storereg_pre(argregs[i], spreg, 8);
        }
        cmp(w1, nilreg);
        jne(tooManyArgs);
    }
#else
#error unrecognised architecture for JIT
#endif

// The part from HERE will be to a large extent platform independent
// in this file, but the #included files all discriminate on x86_64 vs
// aarch64.

// On entry to the function the "env" argument held the name of the
// function being called. As this code executes what I need is its
// vector of literals, which lives in the env field of the Symbol Head.
    loadfromsymbol(litvec, litvec, Oenv);
    TRY
    {   ppc = 0;
        freebind_used = false;
        while (ppc<len)
        {
// Set a label on the code that derives from each opcode. Note that
// because the "case" code for some opcode will increment ppc there will
// be some of the labels that are neither defined nor used.
            bind(perInstruction[ppc]);
            if (qvalue(jit_noisy) != nil)
                stdout_printf("Byte %.2x : %s\n",
                              bytes[ppc], opnames[bytes[ppc]]);
#if 0
// While I am debugging it will sometimes be nice to be able to navigate the
// generated assembly code relating what is there to the bytes it came from.
// However what I have here is rather heavyweight!
            debugHere(ppc);
#endif
            switchBlock(bytes);
        }
    }
    CATCH (JitFailed)
    {   stdout_printf("Caught %s\n", e.what());
        return nullptr;
    }
    END_CATCH;

// There are labels here for error exits.
    bind(tooFewArgs);
// At this stage litvec holds the name of the function involved... So that
// can be left where it can be picked up for inclusion in a disgnostic message.
        loadlit(A_reg, 0);
        storestatic(A_reg, OJITarg1);
        mov(A_reg, (uintptr_t)toofew);
        jmp(chainA); 
    bind(tooManyArgs);
        loadlit(A_reg, 0);
        storestatic(A_reg, OJITarg1);
        mov(A_reg, (uintptr_t)toomany);
        jmp(chainA);
// This is to do with the asmjit-generated code not being able to participate
// fully in C++ exception handling. After any call from the JIT code into
// a function via a "shim" an error flag is checked and if it is set the
// code end up here where it chains to JITthrow which reinstates a C++
// style unwind state. Well when I enter JITthrow I will have the C++
// variable stack set to the stack where the issue arose and JITarg1 to
// where it must end up at. In simple cases the code could merely copy
// from one to the other. However by scanning the stack locations involved
// it will be possible to unwind and fluid bindings that need to be sorted
// out.
    bind(callFailed);
        storestatic(spentry, OJITarg1);
        mov(A_reg, (uintptr_t)jitthrow);
        jmp(chainA);
// Error exits from some basic low level operations.
    bind(carError);
        storestatic(spentry, Ostack);
        storestatic(A_reg, OJITarg1);
        mov(A_reg, (uintptr_t)(func0)car_fails);
        jmp(chainA);
    bind(cdrError);
        storestatic(spentry, Ostack);
        storestatic(A_reg, OJITarg1);
        mov(A_reg, (uintptr_t)(func0)cdr_fails);
    bind(chainA);
// When I handle a case where a procedure call reported failure it is
// important that I do not reset the (Lisp) stack pointer here because the
// code that I chain to will unwrap it word by word and restore such
// fluid bindings as it needs to.
        mov(w, (intptr_t)&chainTarget);
        storereg(A_reg, w, 0);
        chain(A_reg);
// The jump here should never be obeyed but is here in case I have not got
// asmjit to handle its flow analysis for "chain()" in a way that understands
// that it never returns. This will make the dataflow analysis see that
// no (virtual) registers have their values used after it.
        jmp(chainA);

    bind(returnA);
// Ensure that the Lisp stack pointer is in a good state.
    storestatic(spentry, Ostack);
    ret(A_reg);

    endFunc();
    finalize();
    void* func = nullptr;
    if (rt.add(&func, &myCodeHolder) != ErrorCode::kErrorOk)
        throw JitFailed("rt.add failed");
    if (qvalue(jit_noisy) != nil)
    {   size_t size = myCodeHolder.codeSize();
        stdout_printf("size=%d code at %p\n", size, func);
        if (func != nullptr)
        {   FILE* hex = fopen("hex", "w");
            for (int i=0; i<(int)size; i++)
            {   fprintf(hex, "0x%.2x",
                        reinterpret_cast<unsigned char*>(func)[i]);
                if ((i%8) == 7) fprintf(hex, "\n");
                else fprintf(hex, " ");
            }
            if ((size%8) != 0) fprintf(hex, "\n");
            fclose(hex);
        }
    }
    return func;
}

// This is to report on the bytecodes that are not at present implemented
// in the JIT. It does this by passing each opcode byte in turn through the
// generation process and trapping if the "unsupported" exception is
// raising. While it is doing this it will emit some utter junk by way of
// generated code - but to do that it needs registers etc set up as if it
// was being used sensibly.

void Ljit_unfinished()
{   int numberUnfinished = 0;
    int online = 0;
    for (size_t i=1; i<=15; i++)
        argregs[i] = newIntPtr("a1");
    for (size_t i=0; i<256; i++)
        perInstruction.push_back(newLabel());
    unsigned char bytes[512];
    for (size_t i=0; i<sizeof(bytes); i++) bytes[i] = 0;
    ppc = 0;
    freebind_used = false;
    testingForUnfinished = true;
    stdout_printf("\nThe following opcodes are not yet coded for %s\n", ARCH);
    for (unsigned int code=0; code<256; code++)
    {   TRY
        {   switchBlock(bytes);
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
        {   switchBlock(bytes);
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
}

}; // end of JITCompile class

// Now the simple entrypoint...

void* jitcompile(const unsigned char* bytes, size_t len,
                 LispObject env, int nargs)
{
    CodeHolder myCodeHolder;
    Environment localEnv = rt.environment();;
#ifdef __CYGWIN__
    localEnv._platformABI = PlatformABI::kMSVC;
#endif
    myCodeHolder.init(localEnv, rt.cpuFeatures());
    myCodeHolder.setErrorHandler(&jitError);
// The next line will lead to the generated assembly
// code being displayed on the standard output. This is going to be
// really useful while developing, but it obviously gets switched off for
// most production use.
    myFileLogger.addFlags(FormatFlags::kMachineCode);
    if (qvalue(jit_noisy) != nil)
       myCodeHolder.setLogger(&myFileLogger);
    JITCompile cc(&myCodeHolder);
    return cc.jitcompile(bytes, len, env, nargs, myCodeHolder);
}

LispObject Ljit_unfinished(LispObject env)
{   CodeHolder scrap;
    Environment localEnv;
    scrap.init(localEnv);
    scrap.setErrorHandler(&jitError);
    JITCompile cc(&scrap);
    cc.Ljit_unfinished();
    return nil;
}

#else // ENABLE_JIT

// The functions here are no use, but are provided so that image files
// are compatible across architectures. By always returning nullptr this
// reports that it is unable to map from bytemyCodeHolders to native instructions.

void* jitcompile(const unsigned char* bytes, size_t len,
                 LispObject env, int nargs)
{   return nullptr;
}

LispObject Ljit_unfinished(LispObject env)
{   return nil;
}

#endif // ENABLE_JIT

static void show(int count, const unsigned char* code)
{   printf("For %d args at %p...\n", count, code);
    for (int i=0; i<20; i++)
        stdout_printf("%02x ", code[i]);
    stdout_printf("\n");
}

LispObject Lop_bytes(LispObject env, LispObject ff)
{   if (!is_symbol(ff)) return nil;
    show(0, reinterpret_cast<const unsigned char*>(qfn0(ff)));
    show(1, reinterpret_cast<const unsigned char*>(qfn1(ff)));
    show(2, reinterpret_cast<const unsigned char*>(qfn2(ff)));
    show(3, reinterpret_cast<const unsigned char*>(qfn3(ff)));
    show(4, reinterpret_cast<const unsigned char*>(qfn4up(ff)));
    return nil;
}

// end of jit.cpp
