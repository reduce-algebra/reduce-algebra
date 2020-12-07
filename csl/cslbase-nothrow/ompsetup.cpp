// This file was contributed to CSL by NAG Ltd.     Copyright (C) 2016-2020

/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
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

// $Id: ompsetup.cpp 5433 2020-10-15 21:09:02Z arthurcnorman $

#include "headers.h"


extern LispObject om_read(LispObject, LispObject);
extern LispObject om_supportsCD(LispObject, LispObject);
extern LispObject om_supportsSymbol(LispObject, LispObject,
                                    LispObject);
extern LispObject om_listCDs(LispObject, int, ...);
extern LispObject om_listSymbols(LispObject, LispObject);
extern LispObject om_whichCDs(LispObject, LispObject);

// The setup here is OUT OF DATE and WILL NOT WORK because for some years
// CSL has used 5 not 3 function cslls per symbol to cover 0, 1, 2 3 and 4+
// arguments, while this setup is from the old scheme that just dealt
// with 1, 2, 0&3+. So the om_* functions would need adjustment and rework
// before they coudl be used again. It would not be terribly hard but I
// have not yet done it.

setup_type const om_parse_setup[] =
{   /* LISP Name */        /* Unary */      /* Binary */        /* Nary */
    {"om-read",            om_read,         too_many_1,         wrong_no_1},
    {"om-supportsCD",      om_supportsCD,   too_many_1,         wrong_no_1},
    {"om-supportsSymbol",  too_few_2,       om_supportsSymbol,  wrong_no_2},
    {"om-listCDs",         wrong_no_0a,     wrong_no_0b,        om_listCDs},
    {"om-listSymbols",     om_listSymbols,  too_many_1,         wrong_no_1},
    {"om-whichCDs",        om_whichCDs,     too_many_1,         wrong_no_1},
    {nullptr,              nullptr,         nullptr,            nullptr}
};

// end of ompsetup.cpp
