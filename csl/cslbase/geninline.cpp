// geninline.cpp                           Copyright (C) Arthur Norman 2025


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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


#include <iostream>
#include <algorithm>

// I have some templated code as follows that I wanted to have generate
// in-line code for a range of smallish multiplications. When I look at
// assembly code I end up with (and review performance) things are not
// as had hoped. So here I have code that writes out the code I
// expected to get generated.

// This generated a rather chunky amount of code that could be viewed as
// ugly and bad. Well first I will note that it is basically the same
// code that my templated version would or should have expanded into, and
// then that the memory footprint is not seriously inconvenient with the
// amount of memory avalable in today's computers. And timing tests seem to
// show this agressive loop unrolling and inlining to have a positive
// speed impact.


// (1) Multiply an N digit number by an M digit number with the loops
//     all unrolled. There are two reasons for having code to expand
//     this into bulky in-line form. First the full optimisation of the
//     templated code may end up uncertain across the range of C++ compilers
//     potentially used - the fully written out code does not provide any
//     scope for ambiguity! And then as a particular instance of this I have
//     observed even a modern g++ compiling the template-driven static for
//     loop into sequences of procedure calls each representing one use
//     of a lambda-expression that it needs to use internally. And hence
//     ending up with generated code that I di dnot find satisfactory!

// template <size_t N, size_t M>
// [[gnu::always_inline]]
// inline void inlineMul(ConstDigitPtr a, ConstDigitPtr b, DigitPtr result)
// {
//     uint64_t dhi, dlo;
//     multiply64(a[0], b[0], dlo, result[0]);
//     if constexpr (N==1 && M==1)
//     {   result[1] = dlo;
//         return;
//     }
//     dhi = 0;
//     forloop<1, N+M-1> ([&] (auto k)
//     {   size_t carry = 0;
//         forloop<(k<M?0:k+1-M), std::min(N, k+1)>
//             ([&] (auto i)
//         {   uint64_t whi;
//             multiply64(a[i], b[k-i], dlo, whi, dlo);
//             carry += addWithCarry(dhi, whi, dhi);
//         });
//         result[k] = dlo;
//         dlo = dhi;
//         dhi = carry;
//     });
//     result[N+M-1] = dlo;
// }


void generate(std::size_t N, std::size_t M)
{   std::cout << "\n";
    std::cout << "[[gnu::always_inline]]\n";
    std::cout << "static void inlineMul_" << N << "_" << M
              << "(ConstDigitPtr a,\n";
    std::cout << "                          ConstDigitPtr b,\n";
    std::cout << "                          DigitPtr result)\n";
    if (N==1 && M==1)
    {   std::cout << "{   multiply64(a[0], b[0], result[1], result[0]);\n";
        std::cout << "}\n";
        return;
    }
    std::cout << "{   uint64_t dhi, dlo;\n";
    std::cout << "    multiply64(a[0], b[0], dlo, result[0]);\n";
    std::cout << "    dhi = 0;\n";
    std::cout << "    uint64_t whi, carry;\n";
    for (std::size_t k=1; k<N+M-1; k++)
    {   std::cout << "    carry = 0;\n";
        for (std::size_t i=(k<M?0:k+1-M); i<std::min(N, k+1); i++)
        {   std::cout << "    multiply64(a[" << i << "], b[" << (k-i) << "], dlo, whi, dlo);\n";
            std::cout << "    carry += addWithCarry(dhi, whi, dhi);\n";
        }
        std::cout << "    result[" << k << "] = dlo;\n";
        std::cout << "    dlo = dhi;\n";
        std::cout << "    dhi = carry;\n";
    }
    std::cout << "    result[" << (N+M-1) << "] = dlo;\n";
    std::cout << "}\n";
}

// Now one that multiplies by a number that has M digits for known M.
// The code generated here will only be valid if the dynamic size N
// is greater than the static one M.

// template <size_t M>
// [[gnu::always_inline]]
// inline void inlineMul(ConstDigitPtr a, std::size_t N,
//                       ConstDigitPtr b,
//                       DigitPtr result)
// {
// // For this I will require N>=M
//     Digit carry = 0, lo, hi = 0;
// // The lowest Digit can be handled specially to get things going.
//     multiply64(a[0], b[0], lo, result[0]);
//     std::size_t k=1;
//     for (; k<M; k++)
//     {
// // Here I want k<M<=N so certainly if i<k then i<N
//         for (std::size_t i=0; i<=k; i++)
//         {   Digit hi1;
//             multiply64(a[i], b[k-i], lo, hi1, lo);
//             carry += addWithCarry(hi, hi1, hi);
//         }
//         result[k] = lo;
//         lo = hi;
//         hi = carry;
//         carry = 0;
//     }
// // Now k>=M, I want i<=k to imply i<N so go as far as k<N
//     for (; k<N; k++)
//     {
// // This is the inner loop that is ripe for unrolling because M is
// // a known value.
//         for (std::size_t j=0; j<M; j++)
//         {   Digit hi1;
//             multiply64(a[k-j], b[j], lo, hi1, lo);
//             carry += addWithCarry(hi, hi1, hi);
//         }
//         result[k] = lo;
//         lo = hi;
//         hi = carry;
//         carry = 0;
//     }
// // Finally k>=N so i<N will imply i<=k
//     for (; k<N+M-1; k++)
//     {   for (std::size_t i=k+1-M; i<N; i++)
//         {   Digit hi1;
//             multiply64(a[i], b[k-i], lo, hi1, lo);
//             carry += addWithCarry(hi, hi1, hi)
//         }
//         result[k] = lo;
//         lo = hi;
//         hi = carry;
//         carry = 0;
//     }
// // The very final digit of the result drops out here.
//     result[k] = lo;
// }



void generate(std::size_t M)
{   std::cout << "\n";
    std::cout << "[[gnu::always_inline]]\n";
    std::cout << "static void inlineMul_" << M
              << "(ConstDigitPtr a, std::size_t N,\n";
    std::cout << "                        ConstDigitPtr b,\n";
    std::cout << "                        DigitPtr result)\n";
    std::cout << "{   Digit carry = 0, lo, hi = 0, hi1;\n";
    std::cout << "    multiply64(a[0], b[0], lo, result[0]);\n";
    for (std::size_t k=1; k<M; k++)
    {   for (std::size_t i=0; i<=k; i++)
        {   std::cout << "    multiply64(a[" << i << "], b[" << (k-i) << "], lo, hi1, lo);\n";
            std::cout << "    carry += addWithCarry(hi, hi1, hi);\n";
        }
        std::cout << "    result[" << k << "] = lo;\n";
        std::cout << "    lo = hi;\n";
        std::cout << "    hi = carry;\n";
        std::cout << "    carry = 0;\n";
    }
    std::cout << "    for (std::size_t k=" << M << "; k<N; k++)\n";
    std::cout << "    {\n";
    for (std::size_t j=0; j<M; j++)
    {
        std::cout << "        multiply64(a[k-" << j << "], b[" << j << "], lo, hi1, lo);\n";
        std::cout << "        carry += addWithCarry(hi, hi1, hi);\n";
    }
    std::cout << "        result[k] = lo;\n";
    std::cout << "        lo = hi;\n";
    std::cout << "        hi = carry;\n";
    std::cout << "        carry = 0;\n";
    std::cout << "    }\n";

    for (std::size_t k1=0; k1<M-1; k1++)
    {   for (std::size_t i1=k1+1; i1<M; i1++)
        {   std::cout << "    multiply64(a[N-" << (i1-k1) << "], b[" << i1 << "], lo, hi1, lo);\n";
            std::cout << "    carry += addWithCarry(hi, hi1, hi);\n";
        }
        std::cout << "    result[N+" << k1 <<"] = lo;\n";
        std::cout << "    lo = hi;\n";
        std::cout << "    hi = carry;\n";
        std::cout << "    carry = 0;\n";
    }
    std::cout << "    result[N+" << (M-1) << "] = lo;\n";
    std::cout << "}\n";
}

int main()
{
    for (std::size_t N=1; N<=7; N++)
        for (std::size_t M=1; M<=N; M++)
            generate(N, M);
    for (std::size_t N=8; N<=15; N++)
        generate(N, N);
    for (std::size_t N=1; N<=7; N++)
        generate(N);

    std::cout << "\n";
    std::cout << "static void smallCaseMul(ConstDigitPtr a, std::size_t N,\n";
    std::cout << "                         ConstDigitPtr b, std::size_t M,\n";
    std::cout << "                         DigitPtr result)\n";
    std::cout << "{\n";
    std::cout << "// For this I will already have checked that both M and N are at most\n";
    std::cout << "// 7 and so that switch statement will cover all the possibilities and\n";
    std::cout << "// everything should then expand to inline code.\n";
    std::cout << "    switch (MUL_INLINE_LIMIT*N + M)\n";
    std::cout << "    {\n";
    for (std::size_t N=2; N<=7; N++)
    {   for (std::size_t M=1; M<N; M++)
        {   std::cout << "        case 7*" << M << "+" << N << ":\n";
            std::cout << "            std::swap(a, b);\n";
            std::cout << "        case 7*" << N << "+" << M << ":\n";
            std::cout << "            inlineMul_" << N << "_" << M
                      << "(a, b, result);\n";
            std::cout << "            return;\n";
        }
        std::cout << "        case 7*" << N << "+" << N << ":\n";
        std::cout << "            inlineMul_" << N << "_" << N
                  << "(a, b, result);\n";
        std::cout << "            return;\n";
    }
    std::cout << "        default: arithlib_abort(\"bad smallCaseMul\");\n";
    std::cout << "    }\n";
    std::cout << "}\n";
    std::cout << "\n";
    std::cout << "static void bigBySmallMul(ConstDigitPtr a, std::size_t N,\n";
    std::cout << "                          ConstDigitPtr b, std::size_t M,\n";
    std::cout << "                          DigitPtr result)\n";
    std::cout << "{   switch (M)\n";
    std::cout << "    {\n";
    for (std::size_t M=1; M<=7; M++)
    {   std::cout << "        case " << M << ":\n";
        std::cout << "            inlineMul_" << M
                  << "(a, N, b, result); return;\n";
    }
    std::cout << "        default: arithlib_abort(\"bad bigBySmallMul\");\n";
    std::cout << "    }\n";
    std::cout << "}\n";
    std::cout << "\n";
    std::cout << "static void balancedMul(ConstDigitPtr a, ConstDigitPtr b, std::size_t N,\n";
    std::cout << "                       DigitPtr result)\n";
    std::cout << "{   switch (N)\n";
    std::cout << "    {   default: simpleMul(a, N, b, N, result); return;\n";
    for (std::size_t N=1; N<=15; N++)
        std::cout << "        case " << N << ":  inlineMul_" << N
                  << "_" << N << "(a, b, result);   return;\n";
    std::cout << "    }\n";
    std::cout << "}\n";
    return 0;
}

// end of geninline.cpp

