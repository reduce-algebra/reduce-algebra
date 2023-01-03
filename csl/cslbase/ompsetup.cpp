// This file was contributed to CSL by NAG Ltd.     Copyright (C) 2016-2023

/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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


extern LispObject om_read(LispObject, LispObject);
extern LispObject om_supportsCD(LispObject, LispObject);
extern LispObject om_supportsSymbol(LispObject, LispObject, LispObject);
extern LispObject om_listCDs(LispObject);
extern LispObject om_listSymbols(LispObject, LispObject);
extern LispObject om_whichCDs(LispObject, LispObject);

setup_type const om_parse_setup[] =
{
    DEF_1("om-read",            om_read),
    DEF_1("om-supportsCD",      om_supportsCD),
    DEF_2("om-supportsSymbol",  om_supportsSymbol),
    DEF_0("om-listCDs",         om_listCDs),
    DEF_1("om-listSymbols",     om_listSymbols),
    DEF_1("om-whichCDs",        om_whichCDs),
    {nullptr,                   nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of ompsetup.cpp
