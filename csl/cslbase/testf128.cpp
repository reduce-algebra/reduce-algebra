// testf128.cpp                                Copyright Arthur Norman 2023

// $Id$


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


// This is a jiffy program to demonstrate and test the "float128_t.h"
// scheme that makes 128-bit floating point easier to work with than
// the previous state where everything had to be done using visible
// function calls.

#include <iostream>
#include <iomanip>

#include "float128_t.h"

#include <iostream>

template<typename T>
T epsilon() {
    int pow = 0;
    T eps = 1;
    while (eps + 1.0_Q != 1.0_Q)
    {   eps = eps/2.0_Q;
        --pow;
    }
    return eps * 2.0_Q;
}

int main()
{
    std::cout << std::hex << QuadFloat(1) << " " << std::dec << QuadFloat(1) << "\n";
    std::cout << std::hex << QuadFloat(0.1) << " " << std::dec << QuadFloat(0.1) << "\n";
    std::cout << std::hex << QuadFloat(1000) << " " << std::dec << QuadFloat(1000) << "\n";
    std::cout << std::hex << (-0.166666666666666666666666666666666666666666666666666666_Q)
       << " " << std::dec << (-0.166666666666666666666666666666666666666666666666666666_Q)
       << "\n";

//  std::cout << std::setprecision(9);
//  std::cout << "Epsilon for float: " << epsilon<float>() << '\n';
//  std::cout << std::setprecision(17);
//  std::cout << "Epsilon for double: " << epsilon<double>() << '\n';
    std::cout << "Epsilon for QuadFloat: " << epsilon<QuadFloat>() << '\n';
    std::cout << "HalfEpsilon for QuadFloat: " << (epsilon<QuadFloat>() / 2.0_Q) << '\n';

    QuadFloat rfive = QuadFloat(1) / QuadFloat(5);
    QuadFloat rten = QuadFloat(1) / QuadFloat(10);
    std::cout << "\n1/5: " << rfive << " " << std::hex << "\n" << rfive << std::dec << "\n";
    std::cout << "\n1/10: " << rten << " " << std::hex << "\n" << rten << std::dec << "\n";

    std::cout << "hex 0.2_Q = " << std::hex << 0.2_Q << std::dec << "\n";
    std::cout << "0.2_Q = " << 0.2_Q << "\n";

    OctFloat rrfive = OctFloat(1) / OctFloat(5);
    OctFloat rrten = OctFloat(1) / OctFloat(10);
    std::cout << "\n1/5: " << rrfive << " " << std::hex << "\n" << rrfive << std::dec << "\n";
    std::cout << "\n1/10: " << rrten << " " << std::hex << "\n" << rrten << std::dec << "\n";

    OctFloat r5a(0.2_Q); // only top half
    std::cout << "\nr5a: " << r5a << " " << std::hex << "\n" << r5a << std::dec << "\n";
    

    std::cout << "f256_r5: " << OctFloat(f256_r5) << " " << std::hex << OctFloat(f256_r5) << std::dec << "\n";


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

    std::cout << std::hex;
    std::cout << 1.0e17_Q << "\n";
    std::cout << 1.0e18_Q << "\n";
    std::cout << 1.0e19_Q << "\n" << std::dec;

    OctFloat five = OctFloat(5);
    OctFloat fifth = OctFloat(1) / five;
    std::cout << five << "\n" << fifth << "\n";
    std::cout << std::hex << five << "\n" << fifth << std::dec << "\n";

    std::cout << "epsilon...\n" << std::hex;
    std::cout << "epsilon     " << QuadFloat(f128_epsilon) << "\n";
    std::cout << "half_epsilon" << QuadFloat(f128_half_epsilon) << "\n";
    std::cout << "max         " << QuadFloat(f128_max) << "\n";
    std::cout << "negmax      " << QuadFloat(f128_negmax) << "\n";
    std::cout << "min         " << QuadFloat(f128_min) << "\n";
    std::cout << "negmin      " << QuadFloat(f128_negmin) << "\n";
    std::cout << "normmin     " << QuadFloat(f128_normmin) << "\n";
    std::cout << "negnormmin  " << QuadFloat(f128_negnormmin) << "\n";

    std::cout << "epsilon...\n" << std::dec;
    std::cout << "epsilon     " << QuadFloat(f128_epsilon) << "\n";
    std::cout << "half_epsilon" << QuadFloat(f128_half_epsilon) << "\n";
    std::cout << "max         " << QuadFloat(f128_max) << "\n";
    std::cout << "negmax      " << QuadFloat(f128_negmax) << "\n";
    std::cout << "min         " << QuadFloat(f128_min) << "\n";
    std::cout << "negmin      " << QuadFloat(f128_negmin) << "\n";
    std::cout << "normmin     " << QuadFloat(f128_normmin) << "\n";
    std::cout << "negnormmin  " << QuadFloat(f128_negnormmin) << "\n";

    return 0;
}

// end of testf128.cpp

