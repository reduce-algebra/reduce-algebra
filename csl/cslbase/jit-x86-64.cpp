// jit-x86-64.cpp                               Copyright (C) 2025 Codemist

//
// Just-in-time compiler framework - this version for x86_64
//
// I will initially work on the Linux version of this...

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


// I may need to split this into three files, but I hope that the
// different register and calling conventions will in fact prove
// reasonable to handle by having just one bost of mildly parameterised
// code.

#include "bytes.h"

#if defined CYGWIN

// I will put my explanation here. First I use the gcc inline-assembler
// to create 5 little functions called CSLasmtest_N. A call to the function
// showasm() will display the initial bytes of each in binary. And
// calls asmtest0(), asmtest1(1), asmtest2(1,2) etc try them out. The idea
// is that these can be a base for hand-crafting assembly code and testing
// it a bit.

__asm__ (
   ".global CSLasmtest_0\n"
   "CSLasmtest_0:\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_1\n"
   "CSLasmtest_1:\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_2\n"
   "CSLasmtest_2:\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_3\n"
   "CSLasmtest_3:\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_4up\n"
   "CSLasmtest_4up:\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

// Now plant() is given a vector of CSL bytecodes (and its length) and
// information about how many arguments the function should expect. It
// is intended that it generate machine code that does what the code in
// bytes2.cpp would have done by using jit_byte() etc to emit bytes or
// words. The initial version emite what is expected to match the
// code in asmtest_1. 

void plant(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{   jit_byte(0x48); jit_byte(0x89); jit_byte(0xf0); // mov %rsi,%rax
    jit_byte(0xc3);                                 // ret
}

#elif defined NATIVE_WINDOWS

// There are three copies of all this here because Cygwin, Windows and
// Linux can have slighly different conventions regarding use of registers
// etc. I hope that in plant() these changes can be abstracted out so that
// really only one version of that code will be required.

__asm__ (
   ".global CSLasmtest_0\n"
   "CSLasmtest_0:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_1\n"
   "CSLasmtest_1:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_2\n"
   "CSLasmtest_2:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_3\n"
   "CSLasmtest_3:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_4up\n"
   "CSLasmtest_4up:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );


void plant(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{   jit_byte(0x48); jit_byte(0x89); jit_byte(0xd0); // mov %rdx,%rax
    jit_byte(0xc3);                                 // ret
}

#elif defined APPLE_MACINTOSH


__asm__ (
   ".global _CSLasmtest_0\n"
   "_CSLasmtest_0:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_1\n"
   "_CSLasmtest_1:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_2\n"
   "_CSLasmtest_2:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_3\n"
   "_CSLasmtest_3:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_4up\n"
   "_CSLasmtest_4up:\n"
   "	mov %rdx,%rax\n"
   "	ret\n"
    );

void plant(const unsigned char* bytes, size_t len, LispObject env, int nargs)
{   jit_byte(0x48); jit_byte(0x89); jit_byte(0xd0); // mov %rdx,%rax
    jit_byte(0xc3);                                 // ret
}

#else

__asm__ (
   ".global CSLasmtest_0\n"
   "CSLasmtest_0:\n"
   "	endbr64\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_1\n"
   "CSLasmtest_1:\n"
   "	endbr64\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_2\n"
   "CSLasmtest_2:\n"
   "	endbr64\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_3\n"
   "CSLasmtest_3:\n"
   "	endbr64\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_4up\n"
   "CSLasmtest_4up:\n"
   "	endbr64\n"
   "	mov %rsi,%rax\n"
   "	ret\n"
    );


// The top level of this is modelled on code in bytes2.cpp where there is
// code that scans the bytecode stream and performs the operations as
// indicated (ie it is an interpreter for it). Here codevec is the bytecode
// vector and ppc is the one currently being processed.

#define current_byte         (codevec[ppc])
#define next_byte            (codevec[ppc++])
#define previous_byte        (codevec[ppc-1])

// Note that the file csl/cslbase/bytes.h contains a list of all the
// bytecodes along with the names I refer to them by. So if you see
// messages from here that give a hex number that is where you can
// look up what it refers to.

void plant(const unsigned char* codevec, size_t len, LispObject env, int nargs)
{
    printf("Calling plant on ");
    simple_print(basic_elt(env, 0));
    for (unsigned int i=0; static_cast<size_t>(i)<len; i++)
        printf("%3u:  %02x\n", i, codevec[i]&0xff);

    int ppc = 0;

// next_opcode: [label not used!]
#if 0
    try { ([&]()->LispObject {
// AAArgh! This "try" is to do with exception handling. Let's ignore that
// for the moment.
#endif
    while (ppc<len)
    {
        switch (next_byte)
        {
//
// I give labels for all 256 possible cases here so that a sufficiently
// clever compiler can understand that there is no "default" that can possibly
// be activated.
//
            case OP_SPARE:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                continue;

            default:
// Here I have an unrecognised opcode.
                err_printf("\nUnrecognized opcode byte %x\n", codevec[ppc-1]);
                abort();

            case OP_ONEVALUE:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
// ONEVALUE is here to support a proposed re-write of the multiple values
// handling scheme.
//@@@                exit_count = 1;
                continue;

            case OP_LOC0EXIT:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                A_reg = stack[0];
//@@@                stack = entry_stack;

//@@@                return nil;


            case OP_LOC1EXIT:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                A_reg = stack[-1];
//@@@                stack = entry_stack;
//@@@                return nil;

            case OP_NILEXIT:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// On Linux there is a security-measure that imagines that bad people
// might do indirect jumps into the middle of code to achieve behaviour
// that they should not ba able to. So it is arranged that the instruction
// at the destination of any indirect jump must be this "endbr64" or else
// the program blows up. So I need this as the first instruction of any
// procedure. So generating it HERE is silly!!!
                jit_word32(0xfa1e0ff3);
// Here I have an instrunction to load a 64-bit literal into register %eax.
// The value I load is that of NIL, and that does not change during any one
// run. I dump the 64-bit operand in two 32-bit chunks.
                jit_byte(0x48); jit_byte(0xb8);
                jit_word32(static_cast<uint32_t>(nil));
                jit_word32(static_cast<uint32_t>(nil>>32));
// Now a simple return instruction.
                jit_byte(0xc3);
                continue;
//@@@                stack = entry_stack;    ???
//@@@                A_reg = nil;            ???
//@@@                return nil;

            case OP_FREEBIND:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                do_freebind(basic_elt(litvec, next_byte));
//@@@                continue;

            case OP_FREERSTR:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                do_freerstr();
//@@@                continue;

            case OP_PVBIND:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                do_pvbind(A_reg, B_reg);
//@@@                continue;

            case OP_PVRESTORE:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                do_pvrestore();
//@@@                continue;

            case OP_STOREFREE:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
//@@@                {   print_traceset(current_byte, A_reg, litvec);
//@@@                    errexit();
//@@@                }
//@@@                qvalue(basic_elt(litvec, next_byte)) =
//@@@                         A_reg;  // store into special var
//@@@                continue;

            case OP_STOREFREE1:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
//@@@                {   print_traceset(1, A_reg, litvec);
//@@@                    errexit();
//@@@                }
//@@@                qvalue(basic_elt(litvec, 1)) = A_reg;
//@@@                continue;

            case OP_STOREFREE2:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
//@@@                {   print_traceset(2, A_reg, litvec);
//@@@                    errexit();
//@@@                }
//@@@                qvalue(basic_elt(litvec, 2)) = A_reg;
//@@@                continue;

            case OP_STOREFREE3:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
//@@@                {   print_traceset(3, A_reg, litvec);
//@@@                    errexit();
//@@@                }
//@@@                qvalue(basic_elt(litvec, 3)) = A_reg;
//@@@                continue;

            case OP_PUSHNILS:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                n = next_byte;
//@@@                for (k=0; k<n; k++) *++stack = nil;
//@@@                continue;

            case OP_VNIL:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                B_reg = A_reg;
//@@@                A_reg = nil;
//@@@                continue;

            case OP_SWOP:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                r1 = B_reg;
//@@@                B_reg = A_reg;
//@@@                A_reg = r1;
//@@@                continue;

            case OP_NCONS:                          // A_reg = cons(A_reg, nil);
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                {   A_reg = ncons(A_reg);
//@@@                    errexit();
//@@@                }
//@@@                continue;

            case OP_XCONS:                          // A_reg = cons(A_reg, B_reg);
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                A_reg = cons(A_reg, B_reg);
//@@@                errexit();
//@@@                continue;

            case OP_LIST2:                  // A_reg = cons(B_reg, cons(A_reg, nil));
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                A_reg = list2(B_reg, A_reg);
//@@@                errexit();
//@@@                continue;

            case OP_ACONS:                  // A_reg = acons(pop(), B_reg, A_reg);
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                // = (pop() . B) . A
//@@@                r1 = *stack--;
//@@@                A_reg = acons(r1, B_reg, A_reg);
//@@@                errexit();
//@@@                continue;

            case OP_LOADLEX:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                r1 = elt(stack[1-static_cast<int>(next_byte)], 0);
//@@@                B_reg = A_reg;
//@@@                w = next_byte;             // Number of levels to chain
//@@@                while (w != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], w--;
//@@@                A_reg = (reinterpret_cast<LispObject *>(r1))[next_byte];
//@@@                continue;

            case OP_STORELEX:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                r1 = elt(stack[1-static_cast<int>(next_byte)], 0);
//@@@                w = next_byte;             // Number of levels to chain
//@@@                while (w != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], w--;
//@@@                (reinterpret_cast<LispObject *>(r1))[next_byte] = A_reg;
//@@@                continue;

            case OP_CLOSURE:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                *++stack = B_reg; *++stack = A_reg;
//@@@                w = next_byte;
//@@@                A_reg = encapsulate_sp(&stack[-2-static_cast<int>(w)]);
//@@@                errexit();
//@@@                B_reg = *stack--;
//@@@                A_reg = list2star(cfunarg, B_reg, A_reg);
//@@@                errexit();
//@@@                B_reg = *stack--;
//@@@                continue;

            case OP_BIGSTACK:               // LOADLOC, STORELOC, CLOSURE etc
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                w = next_byte;             // contains sub-opcode
//@@@                switch (w & 0xc0)
//@@@                {   case 0x00:                  // LOADLOC extended
//@@@                        B_reg = A_reg;
//@@@                        w = (w & 0x3f) << 8;
//@@@                        A_reg = stack[-static_cast<int>(w + next_byte)];
//@@@                        continue;
//@@@                    case 0x40:                  // STORELOC extended
//@@@                        w = (w & 0x3f) << 8;
//@@@                        stack[-static_cast<int>(w + next_byte)] = A_reg;
//@@@                        continue;
//@@@                    case 0x80:                  // CLOSURE extended
//@@@                        *++stack = B_reg; *++stack = A_reg;
//@@@                        w = ((w & 0x3f) << 8) + next_byte;
//@@@                        A_reg = encapsulate_sp(&stack[-2-static_cast<int>(w)]);
//@@@                        errexit();
//@@@                        B_reg = *stack--;
//@@@                        A_reg = list2star(cfunarg, B_reg, A_reg);
//@@@                        errexit();
//@@@                        B_reg = *stack--;
//@@@                        continue;
//@@@                    case 0xc0:                  // LOADLEX, STORELEX extended
//@@@                        n = next_byte;
//@@@                        k = next_byte;
//@@@                        n = (n << 4) | (k >> 4);
//@@@                        k = ((k & 0xf) << 8) | next_byte;
//@@@                        r1 = elt(stack[1-n], 0);
//@@@                        B_reg = A_reg;
//@@@                        n = w & 0x1f;
//@@@                        while (n != 0) r1 = (reinterpret_cast<LispObject *>(r1))[1], n--;
//@@@                        if ((w & 0x20) == 0) A_reg = (reinterpret_cast<LispObject *>(r1))[k];
//@@@                        else (reinterpret_cast<LispObject *>(r1))[k] = A_reg;
//@@@                        continue;
//@@@                }

            case OP_LIST2STAR:              // A_reg = list2!*(pop(), B_reg, A_reg);
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                // = pop() . (B . A)
//@@@                r1 = *stack--;
//@@@                A_reg = list2star(r1, B_reg, A_reg);
//@@@                errexit();
//@@@                continue;

            case OP_LIST3:                  // A_reg = list3(pop(), B_reg, A_reg);
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                // = pop() . (B . (A . nil))
//@@@                r1 = *stack--;
//@@@                A_reg = list3(r1, B_reg, A_reg);
//@@@                errexit();
//@@@                continue;

            case OP_ADD1:
                printf("Byte %.2x encountered at offset %d\n",
                       previous_byte, ppc-1);
// THIS is where I should emit some machine instructions for it!
                continue;
//@@@                if (is_fixnum(A_reg) && A_reg != MOST_POSITIVE_FIXNUM)
//@@@                {   A_reg += 0x10;
//@@@                    continue;
//@@@                }
#ifdef ARITHLIB
//@@@                A_reg = Add1::op(A_reg);
#else // ARITHLIB
//@@@                A_reg = plus2(A_reg, fixnum_of_int(1));
#endif
//@@@                errexit();
//@@@                continue;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@
// This is as far as I have got adjusting things!


#ifdef MORE_STUFF_DONE  // Ha ha ha
            case OP_PLUS2:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(A_reg) + int_of_fixnum(B_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Plus::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = plus2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

            case OP_SUB1:
                if (is_fixnum(A_reg) && A_reg != MOST_NEGATIVE_FIXNUM)
                {   A_reg -= 0x10;
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Sub1::op(A_reg);
#else // ARITHLIB
                A_reg = plus2(A_reg, fixnum_of_int(-1));
#endif // ARITHLIB
                errexit();
                continue;

            case OP_DIFFERENCE:
                if (is_fixnum(A_reg) && is_fixnum(B_reg))
                {   intptr_t nn = int_of_fixnum(B_reg) - int_of_fixnum(A_reg);
                    A_reg = make_lisp_integerptr(nn);
                    continue;
                }
#ifdef ARITHLIB
                A_reg = Difference::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = difference2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

            case OP_TIMES2:
// I do not in-line even the integer case here, since overflow checking
// is a slight mess.
#ifdef ARITHLIB
                A_reg = Times::op(B_reg, A_reg);
#else // ARITHLIB
                A_reg = times2(B_reg, A_reg);
#endif // ARITHLIB
                errexit();
                continue;

            case OP_LESSP:
#ifdef ARITHLIB
                w = Lessp::op(B_reg, A_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg < A_reg;
                else
                {   w = lessp2(B_reg, A_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

            case OP_GREATERP:
#ifdef ARITHLIB
                w = Lessp::op(A_reg, B_reg);
#else // ARITHLIB
                if (is_fixnum(B_reg) && is_fixnum(A_reg)) w = B_reg > A_reg;
                else
                {   w = lessp2(A_reg, B_reg);
                    errexit();
                }
#endif // ARITHLIB
                A_reg = Lispify_predicate(w);
                continue;

            case OP_FLAGP:                                  // A = flagp(B, A)
#ifdef COMMON
                A_reg = get(B_reg, A_reg, unset_var);
                if (A_reg == unset_var) A_reg = nil;
                else A_reg = lisp_true;
                errexit();
                continue;
#else
                A_reg = Lflagp(nil, B_reg, A_reg);
                errexit();
                continue;
#endif

            case OP_APPLY1:
                if (is_symbol(B_reg))   // can optimise this case, I guess
                {   f1 = qfn1(B_reg);
                    RECORD_CALL(list2(B_reg, A_reg));
                    *++stack = B_reg;
                    if ((qheader(B_reg) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, B_reg, A_reg);
                    else A_reg = f1(B_reg, A_reg);
                    errexit();
                    stack--;
                    continue;
                }
                A_reg = ncons(A_reg);
                errexit();
                A_reg = apply(B_reg, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

            case OP_APPLY2:
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f2 = qfn2(r2);
                    stack--;
                    RECORD_CALL(list3(r2, B_reg, A_reg));
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r2, B_reg, A_reg);
                    else A_reg = f2(r2, B_reg, A_reg);
                    errexit();
                    continue;
                }
// Here the stack has fn on the top and the 2 args are in B_reg, A_reg
                A_reg = list2(B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

            case OP_APPLY3:
// Somewhat beware here - This is (apply3 F a1 a2 a3) or
// (funcall F a1 a2 a3) and a3 will be passed directly as is in the stack.
// In particular a general call to an "apply3" function would have passed in
// effect (apply3' F a1 a2 [a3]) with the fourth argument passed as a list.
// When I use the bytecode op I do not do that.
                r1 = *stack--;
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   f3 = qfn3(r2);
                    RECORD_CALL(list4(r2, r1, B_reg, A_reg));
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r2, r1, B_reg, A_reg);
                    else A_reg = f3(r2, r1, B_reg, A_reg);
                    stack--;
                    errexit();
                    continue;
                }
                A_reg = list3(stack[-1], B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

            case OP_APPLY4:
                r1 = *stack--;
                r3 = *stack--;
// The 4 arguments are now r3, r1, B_reg, A_reg in that order, and as with
// APPLY3 I do not wrap the final two arguments up in a list but instead pass
// them individually.
                r2 = *stack;
                if (is_symbol(r2))   // can optimise this case, I guess
                {   A_reg = ncons(A_reg);    // Make 4th arg a list!
                    RECORD_CALL(list4star(r2, r3, r1, B_reg, A_reg));
                    errexit();
                    f4up = qfn4up(r2);
                    if ((qheader(r2) & SYM_TRACED) != 0)
                        A_reg = traced_call4up(basic_elt(litvec, 0), f4up, r2, r3, r1, B_reg,
                                               A_reg);
                    else A_reg = f4up(r2, r3, r1, B_reg, A_reg);
                    stack--;
                    errexit();
                    continue;
                }
                A_reg = list4(r3, r1, B_reg, A_reg);
                r2 = *stack--;
                errexit();
                A_reg = apply(r2, A_reg, nil, basic_elt(litvec, 0));
                errexit();
                continue;

#ifdef COMMON
#define SL_OR_CL_EQUAL cl_equal
#else
#define SL_OR_CL_EQUAL equal
#endif

            case OP_EQUAL:                                  // A = equal(B, A)
                A_reg = SL_OR_CL_EQUAL(B_reg, A_reg) ? lisp_true : nil;
                errexit();
                continue;

            case OP_EQ:                                     // A = eq(B, A)
                if (A_reg == B_reg) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_NUMBERP:                                // A = numberp(A)
                A_reg = Lispify_predicate(is_number(A_reg));
                continue;

            case OP_QGETV:                          // A_reg = getv(B_reg, A_reg)
//
// Note - this is an UNCHECKED vector access, used when carcheck(nil) has
// been selected because the user prefers speed to security.  This is in
// here because the Reduce factoriser test uses getv VERY heavily indeed
// and both use of a special opcode here and removal of the checking make
// noticable differences to performance.
//
                A_reg = *reinterpret_cast<LispObject *>(
                            reinterpret_cast<char *>(B_reg) +
                            (CELL - TAG_VECTOR) +
                            (CELL*int_of_fixnum(A_reg)));
                continue;

            case OP_GETV:                           // A_reg = getv(B_reg, A_reg)
                A_reg = Lgetv(nil, B_reg, A_reg);
                errexit();
                continue;

            case OP_QGETVN:                         // A_reg = getv(A_reg, n)
//
// Note - this is an UNCHECKED vector access, and only applicable to simple
// vectors that hold general Lisp data.  The offset is passed in the
// byte stream.  It is expected that it will help with code that passes
// around vectors of guff and use (getv vvv 0) etc (aka svref) to
// grab stuff out.
//
                A_reg = *reinterpret_cast<LispObject *>(
                            reinterpret_cast<char *>(A_reg) + (CELL - TAG_VECTOR) + (CELL*
                                    (next_byte)));
                continue;

            case OP_EQCAR:
                if (car_legal(B_reg) && A_reg == car(B_reg)) A_reg = lisp_true;
                else A_reg = nil;
                continue;

            case OP_LENGTH:
                A_reg = Llength(nil, A_reg);
                errexit();
                continue;

//
// The following combinations feel a little odd, but ONE of them showed up
// very clearly in REDUCE tests, and adding the other few seems liable
// (on sentiment, not measurement!) to make reasonable sense.
//
            case OP_LOC0LOC1:
                B_reg = stack[-0];
                A_reg = stack[-1];
                continue;

            case OP_LOC1LOC2:
                B_reg = stack[-1];
                A_reg = stack[-2];
                continue;

            case OP_LOC2LOC3:
                B_reg = stack[-2];
                A_reg = stack[-3];
                continue;

            case OP_LOC1LOC0:
                B_reg = stack[-1];
                A_reg = stack[-0];
                continue;

            case OP_LOC2LOC1:
                B_reg = stack[-2];
                A_reg = stack[-1];
                continue;

            case OP_LOC3LOC2:
                B_reg = stack[-3];
                A_reg = stack[-2];
                continue;

            case OP_CDRLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDRLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDRLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDRLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDRLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDRLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CAARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                goto caar;

            case OP_CAARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                goto caar;

            case OP_CAARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                goto caar;

            case OP_CAARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                goto caar;

            case OP_CAAR:
            caar:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CADR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDAR:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDDR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;


//
// The ICASE opcode is followed by a byte (n say) that indicates the number
// of cases that follow, followed by n+1 double-byte label values.
// If these addresses are called L<dflt>, L<0>, L<1>, ... L<n-1> then if the
// A register contains an integer in the range 0 <= k < n then control is
// transferred to L<k>, while if the A register does not hold an integer or
// if its value is out of range then control goes to L<dflt>.
//
            case OP_ICASE:
                w = next_byte;
                if (is_fixnum(A_reg) &&
                    (n = int_of_fixnum(A_reg)) >= 0 &&
                    n < static_cast<int>(w)) ppc += 2*n + 2;
                w = next_byte;
//
// I support backwards jumps here by setting their top bit. At present I do
// poll for interrupts on a backwards case-branch. And the encoding used means
// that case branches can not reach quite as far as regular jumps.
//
                if (w & 0x80) ppc = ppc - (((w & 0x7f) << 8) +
                                               (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                else ppc = ppc + (w << 8) + (reinterpret_cast<unsigned char *>
                                                 (codevec))[ppc];
                continue;

//
// There are a bunch of special-case jumps here - they are only
// provided with the variants that jump forwards by small offsets,
// but are expected to pick up a useful number of cases (for both speed and
// compactness) all the same.
//
            case OP_JUMPL0NIL:
                xppc = ppc;
                ppc++;
                if (stack[0] == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL0T:
                xppc = ppc;
                ppc++;
                if (stack[0] != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL1NIL:
                xppc = ppc;
                ppc++;
                if (stack[-1] == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL1T:
                xppc = ppc;
                ppc++;
                if (stack[-1] != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL2NIL:
                xppc = ppc;
                ppc++;
                if (stack[-2] == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL2T:
                xppc = ppc;
                ppc++;
                if (stack[-2] != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL3NIL:
                xppc = ppc;
                ppc++;
                if (stack[-3] == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL3T:
                xppc = ppc;
                ppc++;
                if (stack[-3] != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL4NIL:
                xppc = ppc;
                ppc++;
                if (stack[-4] == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL4T:
                xppc = ppc;
                ppc++;
                if (stack[-4] != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL0ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[0])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL0NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[0])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL1ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-1])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL1NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-1])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL2ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-2])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL2NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-2])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL3ATOM:
                xppc = ppc;
                ppc++;
                if (!consp(stack[-3])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPL3NATOM:
                xppc = ppc;
                ppc++;
                if (consp(stack[-3])) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST0NIL:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST0T:
                xppc = ppc;
                ppc++;
                if ((stack[0] = A_reg) != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST1NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST1T:
                xppc = ppc;
                ppc++;
                if ((stack[-1] = A_reg) != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST2NIL:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPST2T:
                xppc = ppc;
                ppc++;
                if ((stack[-2] = A_reg) != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE1NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE1T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 1)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE2NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE2T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 2)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE3NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 3)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE3T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 3)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE4NIL:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 4)) == nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREE4T:
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, 4)) != nil)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT1EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 1)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT1NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 1)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT2EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 2)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT2NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 2)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT3EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 3)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT3NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 3)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT4EQ:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 4)) == A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLIT4NE:
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec, 4)) != A_reg)
                    short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREENIL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFREET:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (qvalue(basic_elt(litvec, w)) != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLITEQ:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(
                    basic_elt(litvec, w)) == A_reg) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPLITNE:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (static_cast<LispObject>(basic_elt(litvec,
                                                      w)) != A_reg) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPB1NIL:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPB1T:
                f1 = one_arg_functions[next_byte];
                A_reg = f1(nil, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPB2NIL:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPB2T:
                f2 = two_arg_functions[next_byte];
                A_reg = f2(nil, B_reg, A_reg);
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPEQCAR:     // jump if eqcar(A, <some literal>)
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (car_legal(A_reg) &&
                    static_cast<LispObject>(basic_elt(litvec,
                                                      w)) == car(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPNEQCAR:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!car_legal(A_reg) ||
                    static_cast<LispObject>(basic_elt(litvec,
                                                      w)) != car(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg)) continue;
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    errexit();
                    if (r1 != unset_var) short_jump(ppc, xppc, codevec);
                    continue;
                }
#else
                {   r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                    errexit();
                }
                if (r1 != nil) short_jump(ppc, xppc, codevec);
                continue;
#endif

            case OP_JUMPNFLAGP:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!symbolp(A_reg))
                {   short_jump(ppc, xppc, codevec);
                    continue;
                }
                else
#ifdef COMMON
                {   r1 = get(A_reg, basic_elt(litvec, w), unset_var);
                    errexit();
                    if (r1 == unset_var) short_jump(ppc, xppc, codevec);
                    continue;
                }
#else
                {   r1 = Lflagp(nil, A_reg, basic_elt(litvec, w));
                    errexit();
                }
                if (r1 == nil) short_jump(ppc, xppc, codevec);
                continue;
#endif

//
// Now the general jumps.  Each has four variants - forwards and backwards
// and long and short offsets.  Backwards jumps poll for interrupts so that
// all loops will be interruptible.
//

            case OP_JUMPATOM:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPATOM_B:
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNATOM:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPNATOM_B:
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPEQ:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPEQ_B:
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNE:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPNE_B:
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPEQUAL:
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc, codevec);
                errexit();
                continue;

            case OP_JUMPEQUAL_B:
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                errexit();
                continue;

            case OP_JUMPNEQUAL:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump(ppc, xppc, codevec);
                errexit();
                continue;

            case OP_JUMPNEQUAL_B:
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) short_jump_back(ppc, xppc, A_reg, codevec);
                errexit();
                continue;

            case OP_JUMP:
                ppc++;
                short_jump(ppc, ppc-1, codevec);
                continue;

            case OP_JUMP_B:
                ppc++;
                short_jump_back(ppc, ppc-1, A_reg, codevec);
                continue;

            case OP_JUMPATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNATOM_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPNATOM_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (consp(A_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPEQ_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPEQ_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == B_reg) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNE_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPNE_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != B_reg) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump_back(w, ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNEQUAL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump(w, ppc, xppc, codevec);
                continue;

            case OP_JUMPNEQUAL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (!SL_OR_CL_EQUAL(A_reg, B_reg)) long_jump_back(w, ppc, xppc,
                            A_reg, codevec);
                continue;

            case OP_JUMP_L:
                w = next_byte;
                ppc++;
                long_jump(w, ppc, ppc-1, codevec);
                continue;

            case OP_JUMP_BL:
                w = next_byte;
                ppc++;
                long_jump_back(w, ppc, ppc-1, A_reg, codevec);
                continue;

            case OP_CATCH:
                w = static_cast<unsigned int>(ppc +
                                              (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_B:
                w = static_cast<unsigned int>(ppc -
                                              (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_L:
                w = next_byte;
                w = static_cast<unsigned int>(ppc + (w << 8) +
                                              (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                ppc++;
                goto catcher;

            case OP_CATCH_BL:
                w = next_byte;
                w = static_cast<unsigned int>(ppc - ((w << 8) +
                                                     (reinterpret_cast<unsigned char *>(codevec))[ppc]));
                ppc++;
            catcher:
                *++stack = fixnum_of_int(w+1);
                *++stack = catch_tags = cons(A_reg, catch_tags);
                *++stack = SPID_CATCH;
                continue;

            case OP_UNCATCH:
                stack--;                // SPID_CATCH
                r1 = *stack--;          // catch_tags while this one active
                stack--;                // destination address if throw used
                catch_tags = cdr(r1);   // this tag no longer in use
                continue;

            case OP_PROTECT:
// This is used to support UNWIND-PROTECT.
// This needs to save A_reg, all the multiple-result registers,
// and the exit_count. Also something to indicate that there had not been
// an error.
                stack--; r1 = *stack--; stack--;
                catch_tags = cdr(r1);
                car(r1) = r1; cdr(r1) = nil;
                A_reg = Lmv_list(nil, A_reg);
                *++stack = nil;
                *++stack = fixnum_of_int(UNWIND_NULL);
                *++stack = A_reg;
                continue;

            case OP_UNPROTECT:
// This must restore all the results (including exit_count). If the
// PROTECT had been done by an unwinding then exit_reason and exit_tag
// must also be restored, and the unwind condition must be re-instated.
                A_reg = *stack--; B_reg = *stack--; exit_tag = *stack--;
                exit_reason = int_of_fixnum(B_reg);
// Here I have multiple values to restore.
                exit_count = 0;
                B_reg = A_reg;
                A_reg = nil;
                if (consp(B_reg))
                {   A_reg = car(B_reg);
                    B_reg = cdr(B_reg);
                    exit_count++;
                    while (consp(B_reg))
                    {   (&mv_1)[exit_count++] = car(B_reg);
                        B_reg = cdr(B_reg);
                    }
                }
                exit_value = A_reg;
// Here after performing the unwind-protect code I must restore a throw
// action that was the same sort as the one that caused me to arrive. I
// think that will involve switching on exit_reason and trying to re-create
// the correct state. In native C++ situations I would be able to go just
// "throw;" without an operand except that in this code I am now outside
// the block that was the signal handler.
                switch (exit_reason)
                {   case UNWIND_NULL:      continue;
                    case UNWIND_GO:        THROW(LispGo);
                    case UNWIND_RETURN:    THROW(LispReturnFrom);
                    case UNWIND_THROW:     THROW(LispThrow);
                    case UNWIND_RESTART:   THROW(LispRestart);
                    case UNWIND_RESOURCE:  THROW(LispResource);
                    case UNWIND_ERROR:     THROW(LispSimpleError);
                    case UNWIND_FNAME:     THROW(LispSimpleError);
                    case UNWIND_UNWIND:    THROW(LispSimpleError);
                    default:               THROW(LispSimpleError);
                }

            case OP_THROW:
                r1 = *stack--;       // The tag to throw to.
// Check if tag is one we will handle.
                for (r2 = catch_tags; r2!=nil; r2=cdr(r2))
                    if (r1 == car(r2)) break;
                if (r2==nil) return aerror1("throw: tag not found", r1);
                catch_tags = cdr(r2);
                exit_tag = r2;       // cdr() will go back in catch_tags
                exit_value = A_reg;
                exit_reason = UNWIND_THROW;
                THROW(LispThrow);

// I expect that calling functions with 0, 1, 2 or 3 arguments will
// be enormously important for Lisp, and so separate opcodes are provided
// for these cases.  The operand in each case selects the function to be
// called, which MUST be a symbol (loaded from the literal vector),
// and arguments are taken from A and B as necessary.  If several
// arguments are needed the first argument will be loaded first, and thus
// it is the LAST argument that end up in the A register.

            case OP_CALL0_0:      // Calling myself...
                fname = 0;
                goto call0;

            case OP_CALL0_1:
                fname = 1;
                goto call0;

            case OP_CALL0_2:
                fname = 2;
                goto call0;

            case OP_CALL0_3:
                fname = 3;
                goto call0;

            case OP_CALL0:
                fname = next_byte;
            call0:
                r1 = basic_elt(litvec, fname);
                {   debug_record_symbol(r1);
//
// NB I set fname to be the literal-vector offset in the line above so that
// it will be possible to find the name of the function that was called
// if I have to display a backtrace.
//
                    RECORD_CALL(ncons(r1));
                    f0 = qfn0(r1);
// CALL0:  A=fn()
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                    else A_reg = f0(r1);
                }
                errexit();
                continue;


            case OP_JCALL:
// This version has the number of args and the target packed into a
// single operand byte.  Cases where the offset does not fit into this
// will go via BIGCALL.
// Note that the argument count can only ever be 0, 1, 2, 3 or 4, so
// codes 5, 6 and 7 are not used. Hmmm I could provide a JCALL2R option
// if I wanted!
                w = next_byte;
                fname = w & 0x1f;
                w = (w >> 5) & 0x7;
                switch (w)
                {   case 0: goto jcall0;
                    case 1: goto jcall1;
                    case 2: goto jcall2;
                    case 3: goto jcall3;
                    default:goto jcall4;
                }

            jcall0: r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f0 = qfn0(r1);
                errexit();
// The issue here is cases such as
//    (de f1 (x) (f2 x))
//    (de f2 (x) (f1 x))
// where the bodies of the functions so not do enough work that polling
// for interrupts or for window-system updates will happen. Thus it seems
// I need to perform a polling operation as part of the tail-call sequence.
                poll_jump_back(A_reg);
// If I have an (untraced) tailcall to a bytecoded function I can just reset
// some pointers and go back to the top of the code of the bytecode
// interpreter.
                if (f0 == bytecoded_0 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(ncons(r1));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    ppc = BPS_DATA_OFFSET;
                    continue;
                }
                stack = entry_stack;
                {   RECORD_CALL(ncons(r1));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call0(basic_elt(litvec, 0), f0, r1);
                    else A_reg = f0(r1);
                }
                return nil;

            jcall1:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
                poll_jump_back(A_reg);
                if (f1 == bytecoded_1 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list2(r1, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
                    continue;
                }
                stack = entry_stack;
                {   RECORD_CALL(list2(r1, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                    else A_reg = f1(r1, A_reg);
                }
                return nil;


            jcall2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
                poll_jump_back(A_reg);
                if (f2 == bytecoded_2 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list3(r1, B_reg, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = B_reg; *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
                    continue;
                }
                stack = entry_stack;
                {   RECORD_CALL(list3(r1, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                    else A_reg = f2(r1, B_reg, A_reg);
                }
                return nil;

            jcall3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
                poll_jump_back(A_reg);
                r2 = *stack--;
                if (f3 == bytecoded_3 &&
                    (qheader(r1) & SYM_TRACED) == 0)
                {   RECORD_TAILCALL(list4(r1, r2, B_reg, A_reg));
                    lit = qenv(r1);
                    codevec = car(lit);
                    litvec = cdr(lit);
                    ffpname = qpname(basic_elt(litvec, 0));
                    fflength =
                        (size_t)(length_of_byteheader(vechdr(ffpname)) - CELL);
                    if (fflength >= sizeof(ffname)) fflength = sizeof(ffname)-1;
                    std::memcpy(reinterpret_cast<void *>(&ffname[0]), &celt(ffpname, 0),
                                fflength);
                    ffname[fflength] = 0;
                    stack = entry_stack;
                    *++stack = r2; *++stack = B_reg; *++stack = A_reg;
                    ppc = BPS_DATA_OFFSET;
                    continue;
                }
                stack = entry_stack;
                {   RECORD_CALL(list4(r1, r2, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                return nil;

            jcall4:
// fname is the offset in the literal vector of the function to call.
// The args are in stack[-1], stack[0], B_reg, A_reg
// In some other JCALL cases I optimise if the called function is
// bytecoded. I have not done that here (yet?).
                r2 = *stack--; r1 = *stack--;
                B_reg = list3star(r1, r2, B_reg, A_reg);
                A_reg = basic_elt(litvec, fname);
                debug_record_symbol(A_reg);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                stack = entry_stack;
//              return A_reg;
                return nil;

            case OP_BIGCALL:
//
// This provides for calls (and a few other operations!) where the literal
// to be referenced is beyond position 256 in the literal vector. The
// encoding is that BIGCALL is followed by two bytes. The top half of the
// first of these is a sub opcode, while the remaining 12 bits provide
// support for literal vectors with up to 4096 elements. At present I
// will just not support code bigger than that. Note that if I were feeling
// keen here I could easily arrange that the 12-bit offset here started at
// 256 and went on upwards. But for simplicity in a first version I will
// leave a bit of redundancy.
//
                w = next_byte;
                fname = next_byte + ((w & 0xf) << 8);
                switch (w >> 4)
                {   case 0: goto call0;
                    case 1: goto call1;
                    case 2: goto call2;
                    case 3: goto call3;
                    case 4:
// Here I write out a variant on the CALL4 code.
                        {   LispObject a3 = *stack--;
                            LispObject a4 = *stack--;
                            B_reg = list3star(a4, a3, B_reg, A_reg);
                        }
                        errexit();
                        A_reg = basic_elt(litvec, fname);
                        A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                        errexit();
                        ppc++;
                        continue;

                    case 5: goto call2r;
// sub-opcodes 6 and 7 are use for LOADFREE and STOREFREE - this is a bit
// odd but fits the required operations tightly into the opcode map.
                    case 6:
                        B_reg = A_reg;
                        A_reg = qvalue(basic_elt(litvec, fname));
                        continue;
                    case 7:
                        if ((qheader(basic_elt(litvec, 0)) & SYM_TRACESET) != 0)
                        {   print_traceset(fname, A_reg, litvec);
                            errexit();
                        }
                        qvalue(basic_elt(litvec, fname)) = A_reg;  // store into special var
                        continue;
// Now tailcalls.
                    case 8: goto jcall0;
                    case 9: goto jcall1;
                    case 10:goto jcall2;
                    case 11:goto jcall3;
                    case 12:goto jcall4;
// Codes 13 and 14 do FREEBIND and LITGET, which completes the list of
// byte operations that access big literals.
                    case 13:do_freebind(basic_elt(litvec, fname));
                        continue;
                    case 14:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        A_reg = get(B_reg, A_reg, nil);
                        continue;
// Code 15 is LOADLIT with a long offset, which may be used as an alternative
// to the LOADLIT/QGETVN mechanism that I otherwise support.
                    case 15:B_reg = A_reg;
                        A_reg = basic_elt(litvec, fname);
                        continue;
                }

            case OP_CALL1_0:
//
// Note that this is spotted and treated as a direct call to the
// current function (because offset zero in the literal vector is reserved
// for the name of the function).  I can NOT avoid the overhead of stacking
// and restoring codevec and litvec here, even the values used in the called
// function are the same as the present ones, because the lower level call
// might itself do a JCALL and corrupt them!  Also I know that the current
// function is bytecoded, so I avoid the overhead of (re-)discovering that.
//
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACED) != 0)
                {   fname = 0;
                    goto call1;
                }
                {   stack_restorer saver;
                    STACK_SANITY;
                    *++stack = A_reg; // the argument
                    RECORD_CALL(list2(basic_elt(litvec, 0), A_reg));
                    if (reinterpret_cast<uintptr_t>(stack) >= stackLimit)
                        respond_to_stack_event();
                    A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0),
                                                 stack-1);
                    errexit();
                }
                continue;

            case OP_CALL1_1:
                fname = 1;
                goto call1;

            case OP_CALL1_2:
                fname = 2;
                goto call1;

            case OP_CALL1_3:
                fname = 3;
                goto call1;

            case OP_CALL1_4:
                fname = 4;
                goto call1;

            case OP_CALL1_5:
                fname = 5;
                goto call1;

            case OP_CALL1:
                fname = next_byte;
            call1:  r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f1 = qfn1(r1);
// CALL1:   A=fn(A);
                {   RECORD_CALL(list2(r1, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call1(basic_elt(litvec, 0), f1, r1, A_reg);
                    else A_reg = f1(r1, A_reg);
                }
                errexit();
                continue;

            case OP_CALL2_0:
                if ((qheader(basic_elt(litvec, 0)) & SYM_TRACED) != 0)
                {   fname = 0;
                    goto call2;
                }
                {   stack_restorer saver;
                    STACK_SANITY;
                    *++stack = B_reg; *++stack = A_reg;
                    RECORD_CALL(list3(basic_elt(litvec, 0), B_reg, A_reg));
                    if (reinterpret_cast<uintptr_t>(stack) >= stackLimit)
                        respond_to_stack_event();
                    A_reg = bytestream_interpret(CELL-TAG_VECTOR, basic_elt(litvec, 0),
                                                 stack-2);
                }
                errexit();
                continue;

            case OP_CALL2_1:
                fname = 1;
                goto call2;

            case OP_CALL2_2:
                fname = 2;
                goto call2;

            case OP_CALL2_3:
                fname = 3;
                goto call2;

            case OP_CALL2_4:
                fname = 4;
                goto call2;

            case OP_CALL2:
                fname = next_byte;
            call2:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2:   A=fn(B,A);
                {
                    RECORD_CALL(list3(r1, B_reg, A_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, B_reg, A_reg);
                    else A_reg = f2(r1, B_reg, A_reg);
                }
                errexit();
                continue;

            case OP_CALL2R:
                fname = next_byte;
            call2r:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f2 = qfn2(r1);
// CALL2R:   A=fn(A,B); NOTE arg order reversed
                {   RECORD_CALL(list3(r1, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call2(basic_elt(litvec, 0), f2, r1, A_reg, B_reg);
                    else A_reg = f2(r1, A_reg, B_reg);
                }
                errexit();
                continue;

            case OP_CALL3:
                fname = next_byte;
            call3:
                r1 = basic_elt(litvec, fname);
                debug_record_symbol(r1);
                f3 = qfn3(r1);
// CALL3:   A=fn(pop(),B,A);
                r2 = *stack--;
                {   RECORD_CALL(list4(r1, r2, A_reg, B_reg));
                    if ((qheader(r1) & SYM_TRACED) != 0)
                        A_reg = traced_call3(basic_elt(litvec, 0), f3, r1, r2, B_reg, A_reg);
                    else A_reg = f3(r1, r2, B_reg, A_reg);
                }
                errexit();
                continue;

            case OP_CALL4:
// All but the last two args have been pushed onto the stack already.
// The last two are in A and B.
                r2 = *stack--; r1 = *stack--;
                B_reg = list3star(r1, r2, B_reg, A_reg);
                errexit();
// Here the post-byte indicates the function to be called.
                A_reg = basic_elt(litvec,
                                  (reinterpret_cast<unsigned char *>(codevec))[ppc]);
                A_reg = apply(A_reg, B_reg, nil, basic_elt(litvec, 0));
                ppc++;
                errexit();
                continue;

            case OP_BUILTIN0:
// At present this uses the "old" scheme for functions that do not take
// arguments that passes the integer 0 to tell them of the lack of args
// actually passed.
                f0 = no_arg_functions[next_byte];
                debug_record_int("BUILTIN0", previous_byte);
// BUILTIN0:  A=fn()
                {
                    if (no_arg_traceflags[previous_byte])
                        A_reg = traced_call0(basic_elt(litvec, 0), f0,
                                             make_undefined_symbol(no_arg_names[previous_byte]));
                    else A_reg = f0(nil);
                }
                errexit();
                continue;

            case OP_BUILTIN1:
                f1 = one_arg_functions[next_byte];
                debug_record_int("BUILTIN1", previous_byte);
// BUILTIN1:   A=fn(A);
                if (one_arg_traceflags[previous_byte])
                    A_reg = traced_call1(basic_elt(litvec, 0), f1,
                                         make_undefined_symbol(one_arg_names[previous_byte]),
                                         A_reg);
                A_reg = f1(nil, A_reg);
                errexit();
                continue;

            case OP_BUILTIN2:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2", previous_byte);
// BUILTIN2:   A=fn(B,A);
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                                         make_undefined_symbol(two_arg_names[previous_byte]),
                                         B_reg, A_reg);
                A_reg = f2(nil, B_reg, A_reg);
                errexit();
                continue;

            case OP_BUILTIN2R:
                f2 = two_arg_functions[next_byte];
                debug_record_int("BUILTIN2R", previous_byte);
// BUILTIN2R:   A=fn(A,B); NOTE arg order reversed
                if (two_arg_traceflags[previous_byte])
                    A_reg = traced_call2(basic_elt(litvec, 0), f2,
                                         make_undefined_symbol(two_arg_names[previous_byte]),
                                         A_reg, B_reg);
                else A_reg = f2(nil, A_reg, B_reg);
                errexit();
                continue;

            case OP_BUILTIN3:
                f3 = three_arg_functions[next_byte];
                debug_record_int("BUILTIN3", previous_byte);
// CALL3:   A=fn(pop(),B,A);
                r1 = *stack--;
                if (three_arg_traceflags[previous_byte])
                    A_reg = traced_call3(basic_elt(litvec, 0), f3,
                                         make_undefined_symbol(three_arg_names[previous_byte]),
                                         r1, B_reg, A_reg);
                else A_reg = f3(nil, r1, B_reg, A_reg);
                errexit();
                continue;

//
// Now here in a neat block I will have the cases that seem to occur most
// frequently, at least when I tested things running REDUCE. By collecting
// these together I hope to (slightly) improve the cache locality behaviour
// for this code - maybe...
//
            case OP_LOADLOC:
                B_reg = A_reg;
                A_reg = stack[-static_cast<int>(next_byte)];
                continue;

            case OP_LOADLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                continue;

            case OP_LOADLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                continue;

            case OP_LOADLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                continue;

            case OP_LOADLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                continue;

            case OP_LOADLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                continue;

            case OP_LOADLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                continue;

            case OP_LOADLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                continue;

            case OP_LOADLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                continue;

            case OP_LOADLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                continue;

            case OP_LOADLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                continue;

            case OP_LOADLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                continue;

            case OP_LOADLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                continue;

            case OP_CAR:
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC0:
                B_reg = A_reg;
                A_reg = stack[-0];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC1:
                B_reg = A_reg;
                A_reg = stack[-1];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC2:
                B_reg = A_reg;
                A_reg = stack[-2];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC3:
                B_reg = A_reg;
                A_reg = stack[-3];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC4:
                B_reg = A_reg;
                A_reg = stack[-4];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC5:
                B_reg = A_reg;
                A_reg = stack[-5];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC6:
                B_reg = A_reg;
                A_reg = stack[-6];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC7:
                B_reg = A_reg;
                A_reg = stack[-7];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC8:
                B_reg = A_reg;
                A_reg = stack[-8];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC9:
                B_reg = A_reg;
                A_reg = stack[-9];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC10:
                B_reg = A_reg;
                A_reg = stack[-10];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CARLOC11:
                B_reg = A_reg;
                A_reg = stack[-11];
                if (car_legal(A_reg)) A_reg = car(A_reg);
                else 
                {   A_reg = carerror(A_reg);
                    errexit();
                }
                continue;

            case OP_CDR:
                if (car_legal(A_reg)) A_reg = cdr(A_reg);
                else
                {   A_reg = cdrerror(A_reg);
                    errexit();
                }
                continue;

            case OP_STORELOC:
                stack[-static_cast<int>(next_byte)] = A_reg;
// NB this opcode does not pop the A/B stack
                continue;

            case OP_STORELOC0:
                stack[-0] = A_reg;
                continue;

            case OP_STORELOC1:
                stack[-1] = A_reg;
                continue;

            case OP_STORELOC2:
                stack[-2] = A_reg;
                continue;

            case OP_STORELOC3:
                stack[-3] = A_reg;
                continue;

            case OP_STORELOC4:
                stack[-4] = A_reg;
                continue;

            case OP_STORELOC5:
                stack[-5] = A_reg;
                continue;

            case OP_STORELOC6:
                stack[-6] = A_reg;
                continue;

            case OP_STORELOC7:
                stack[-7] = A_reg;
                continue;

            case OP_LOADLIT:
//
// Associated with each body of byte-codes there is a literal vector,
// and this opcode loads values from same.  The literal vector has a
// header word and is tagged as a Lisp vector.
//
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                continue;

            case OP_LOADLIT1:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 1);
                continue;

            case OP_LOADLIT2:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 2);
                continue;

            case OP_LOADLIT3:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 3);
                continue;

            case OP_LOADLIT4:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 4);
                continue;

            case OP_LOADLIT5:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 5);
                continue;

            case OP_LOADLIT6:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 6);
                continue;

            case OP_LOADLIT7:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, 7);
                continue;

            case OP_LOADFREE:
//
// Load the value of a free (GLOBAL, SPECIAL, FLUID) variable
//
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, next_byte));
                continue;

            case OP_LOADFREE1:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 1));
                continue;

            case OP_LOADFREE2:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 2));
                continue;

            case OP_LOADFREE3:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 3));
                continue;

            case OP_LOADFREE4:
                B_reg = A_reg;
                A_reg = qvalue(basic_elt(litvec, 4));
                continue;

            case OP_JUMPNIL:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPNIL_B:
                xppc = ppc;
                ppc++;
                if (A_reg == nil) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPT:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump(ppc, xppc, codevec);
                continue;

            case OP_JUMPT_B:
                xppc = ppc;
                ppc++;
                if (A_reg != nil) short_jump_back(ppc, xppc, A_reg, codevec);
                continue;

            case OP_JUMPNIL_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil) ppc = ppc + ((w << 8) +
                                                   (reinterpret_cast<unsigned char *>(codevec))[xppc]);
                continue;

            case OP_JUMPNIL_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg == nil)
                {   ppc = ppc - ((w << 8) + (reinterpret_cast<unsigned char *>
                                             (codevec))[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

            case OP_JUMPT_L:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil) ppc = ppc + ((w << 8) +
                                                   (reinterpret_cast<unsigned char *>(codevec))[xppc]);
                continue;

            case OP_JUMPT_BL:
                w = next_byte;
                xppc = ppc;
                ppc++;
                if (A_reg != nil)
                {   ppc = ppc - ((w << 8) + (reinterpret_cast<unsigned char *>
                                             (codevec))[xppc]);
                    poll_jump_back(A_reg);
                }
                continue;

            case OP_EXIT:
//
// Here I assume that exit_count has been set up already. Note also that
// there is no need to do any LOSE operations just before an EXIT since the
// stack gets reset automatically here.
//
                stack = entry_stack;
//              return A_reg;
                return nil;

            case OP_PUSH:
                *++stack = A_reg;
                continue;

            case OP_PUSHNIL:
                *++stack = nil;
                continue;

            case OP_PUSHNIL2:
                *++stack = nil;
                *++stack = nil;
                continue;

            case OP_PUSHNIL3:
                *++stack = nil;
                *++stack = nil;
                *++stack = nil;
                continue;

            case OP_POP:
                B_reg = A_reg;
                A_reg = *stack--;
                continue;

            case OP_LOSE:
                stack--;
                continue;

            case OP_LOSE2:
                stack -= 2;
                continue;

            case OP_LOSE3:
                stack -= 3;
                continue;

            case OP_LOSES:
                stack -= next_byte;
                continue;

            case OP_CONS:                           // A_reg = cons(B_reg, A_reg);
                A_reg = cons(B_reg, A_reg);
                errexit();
                continue;

//
// FASTGET n
//     0 <= n < 64       (GET A_reg property_n)
//    64 <= n < 128      (GET A_reg property_n B_reg)
//   128 <= n < 192      (FLAGP A_reg property_n)
//   192 <= n < 256      not used at present.
//
            case OP_FASTGET:
                w = next_byte;
#ifdef RECORD_GET
                n = 0;
#endif
                if (symbolp(A_reg))
                {   r1 = qfastgets(A_reg);
                    if (r1 == nil)
                    {   if (w & 0x40) A_reg = B_reg;
                        else A_reg = nil;
                    }
                    else
                    {   A_reg = basic_elt(r1, w & 0x3f);
                        if (A_reg == SPID_NOPROP)
                        {   if (w & 0x40) A_reg = B_reg;
                            else A_reg = nil;
#ifdef RECORD_GET
                            n = 1;
#endif
                        }
                        else if (w & 0x80) A_reg = lisp_true;
                    }
                }
                else A_reg = nil;
#ifdef RECORD_GET
                record_get(basic_elt(fastget_names, w & 0x7f), n);
#endif
                continue;

            case OP_LITGET:
                B_reg = A_reg;
                A_reg = basic_elt(litvec, next_byte);
                A_reg = get(B_reg, A_reg, nil);
                errexit();
                continue;

            case OP_GET:                                    // A = get(B, A)
                A_reg = get(B_reg, A_reg, nil);
                errexit();


#endif  // MORE_STUFF_DONE

        }

//*****************************************************************************
// End of the main block of opcodes.
//*****************************************************************************
    } // end of switch block

}

#endif

// end of jit-x86-64.cpp

