

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



//register, eg EAX
#define EAX 0x0
#define ECX 0x1
#define EDX 0x2
#define EBX 0x3
#define ESP 0x4
#define EBP 0x5
#define ESI 0x6
#define EDI 0x7

//memory indirection, eg [EAX]
#define EAXM 0x8
#define ECXM 0x9
#define EDXM 0xa
#define EBXM 0xb
#define ESPM 0xc
#define EBPM 0xd
#define ESIM 0xe
#define EDIM 0xf

//memory offset
#define DISP32 0x10

//Conditional branches with rel8 offset
#define JA 0x77
#define JAE 0x73
#define JB 0x72
#define JBE 0x76
#define JC 0x72
#define JCXZ 0xe3
#define JECXZ 0xe3
#define JRCXZ 0xe3
#define JE 0x74
#define JG 0x7f
#define JGE 0x7d
#define JL 0x7c
#define JLE 0x7e
#define JNA 0x76
#define JNAE 0x72
#define JNB 0x73
#define JNBE 0x77
#define JNC 0x73
#define JNE 0x75
#define JNG 0x7e
#define JNGE 0x7c
#define JNL 0x7d
#define JNLE 0x7f
#define JNO 0x71
#define JNP 0x7b
#define JNS 0x79
#define JNZ 0x75
#define JO 0x70
#define JP 0x7a
#define JPE 0x7a
#define JPO 0x7b
#define JS 0x78
#define JZ 0x74
