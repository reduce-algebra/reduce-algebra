// jit-aarch64.cpp                              Copyright (C) 2025 Codemist

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

// See comments in jit-x86-64.cpp for an explanation of what this is
// all about.

#ifdef APPLE_MACINTOSH

__asm__ (
   ".global _CSLasmtest_0\n"
   "_CSLasmtest_0:\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_1\n"
   "_CSLasmtest_1:\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_2\n"
   "_CSLasmtest_2:\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_3\n"
   "_CSLasmtest_3:\n"
   "	ret\n"
    );

__asm__ (
   ".global _CSLasmtest_4up\n"
   "_CSLasmtest_4up:\n"
   "	ret\n"
    );

#else // APPLE_MACINTOSH

__asm__ (
   ".global CSLasmtest_0\n"
   "CSLasmtest_0:\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_1\n"
   "CSLasmtest_1:\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_2\n"
   "CSLasmtest_2:\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_3\n"
   "CSLasmtest_3:\n"
   "	ret\n"
    );

__asm__ (
   ".global CSLasmtest_4up\n"
   "CSLasmtest_4up:\n"
   "	ret\n"
    );

#endif // APPLE_MACINTOSH

void plant(const char* bytes, size_t len, LispObject env, int nargs)
{
    jit_word32(0xd65f03c0); // "ret" instruction on aarch64
}

// end of jit-aarch64.cpp

