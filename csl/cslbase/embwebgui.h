// embwebgui.h                         Copyright (C) 2022-2026 E. Schruefer

#ifndef EMBWEBGUI
#define EMBWEBGUI

// $Id$

/**************************************************************************
 * Copyright (C) 2026, Codemist.                         E. Schruefer     *
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


#include <string>
#include "headers.h"

namespace CSL_LISP
{
        void setup_web_reduce(void);

        std::string passToReduce(std::string arguments);
        
        std::string loadReducePackage(std::string arguments);
        
        std::string setReduceSwitch(std::string arguments);
        
        std::string queryReduceSwitches(std::string arguments);
        
        std::string redBanner(std::string arguments);
        
        std::string openDocuBrowser(std::string arguments);
        
        std::string passKeyCodeToReduce(std::string arguments);
        
        LispObject Lexec_JS_in_webv(LispObject, LispObject);
       
} // end namespace

#endif

// end of embwebgui.h
