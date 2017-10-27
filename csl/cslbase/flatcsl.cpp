// flatcsl.h                               Copyright (C) 2016-2017 Codemist

// The idea of this file is that it uses #include to gather ALL the source
// files for CSL so they get compiled as a single program unit. This will
// perhaps be a long compilation that needs much memory, but it could give
// extra opportunities for function inlining and other inter-procedural
// optimisations, as well as bein in some respects a "simpler" build process.


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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


#include "csl.cpp"
#include "fasl.cpp"
#include "cslgc.cpp"
#include "preserve.cpp"
#include "arith01.cpp"
#include "arith02.cpp"
#include "arith03.cpp"
#include "arith04.cpp"
#include "arith05.cpp"
#include "arith06.cpp"
#include "arith07.cpp"
#include "arith08.cpp"
#include "arith09.cpp"
#include "arith10.cpp"
#include "arith11.cpp"
#include "arith12.cpp"
#include "arith13.cpp"
#include "arith14.cpp"
#include "bytes1.cpp"
#include "char.cpp"
#include "cslmpi.cpp"
#include "eval1.cpp"
#include "eval2.cpp"
#include "eval3.cpp"
#include "eval4.cpp"
#include "fns1.cpp"
#include "fns2.cpp"
#include "fns3.cpp"
#include "inthash.cpp"
#include "print.cpp"
#include "cslread.cpp"
#include "restart.cpp"
#include "lisphash.cpp"
#include "serialize.cpp"
#include "sysfwin.cpp"
#include "stubs.cpp"
#ifndef HAVE_LIBFOX
#ifdef HAVE_LIBWX
#include "wxfwin.cpp"
#else
#include "fwin.cpp"
#endif
#include "termed.cpp"
#endif


// end of flatcsl.cpp
