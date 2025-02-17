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

#elif defined NATIVE_WINDOWS

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

#else // Unknown x86_64

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



#endif // unknown x86_64

void jit_procedure_head()
{
}

void jit_procedure_tail()
{
}

// end of jit-x86-64.cpp

