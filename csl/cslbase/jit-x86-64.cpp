// jit-x86-64.cpp                               Copyright (C) 2025 Codemist

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


// I may need to split this into three files, but I hope that the
// different register and calling conventions will in fact prove
// reasonable to handle by having just one bost of mildly parameterised
// code.

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

void plant(const char* bytes, size_t len, LispObject env, int nargs)
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


void plant(const char* bytes, size_t len, LispObject env, int nargs)
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

void plant(const char* bytes, size_t len, LispObject env, int nargs)
{   jit_word32(0xfa1e0ff3);                         // endbr64
    jit_byte(0x48); jit_byte(0x89); jit_byte(0xf0); // mov %rsi,%rax
    jit_byte(0xc3);                                 // ret
}

#endif

// end of jit-x86-64.cpp

