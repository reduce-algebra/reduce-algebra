// testf128.cpp                                Copyright Arthur Norman 2022

// $Id$


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


// This is a jiffy program to demonstrate and test the "float128_t.h"
// scheme that makes 129-bit floating point easier to work with than
// the previous state where everything had to be done using visible
// function calls.

#include <iostream>
#include <iomanip>

#include "float128_t.h"


int main()
{
    QuadFloat a("1");            // I can create QuadFloat variables...
    QuadFloat b("1e10");
    QuadFloat c("460551");

    std::cout << "a (1) " << a << "\n";
    std::cout << "b (1e10) " << b << "\n";
    std::cout << "c (460551) " << c << "\n";

// I can also use literals written with suffix "_Q".

    std::cout << "1_Q " << 1_Q << "\n";
    std::cout << "1.000_Q " << 1.000_Q << "\n";
    std::cout << "3.141592653_Q " << 3.141592653_Q << "\n";

// Simple arithmetic should be supported.

    c = a + 17_Q;
    std::cout << "a + 17_Q = " << c << "  (" << 18_Q << ")\n";

// Literals can be presented in hexadecimal using a suffix "_QX".

    std::cout << 0x3fff'171717171717'1717171717171717_QX << "\n";
    return 0;
}

// end of testf128.cpp

