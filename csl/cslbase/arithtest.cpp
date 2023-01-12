// Test code for Big-number arithmetic.                    A C Norman, 2020


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

// My bignum package is a header-only library, so to use it you arrange
// that the c++ compiler has a directive such as "-Idirectory_for_arithlib"
// so that it can be found and you then just include the one file that
// contains everything.

#include "arithlib.hpp"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cassert>

using namespace arithlib;

// The tests come in sections, and these preprocessor symbols can be used
// to select which sections get run. If you compile this code simply then
// all tests will be enabled. However if the C++ compiler is used to
// pre-define one or more of these symbols only that or those tests will
// be run. So for instance
//    g++ -DCOMPARE_GMP=1 arithtest.cpp -O3 -lgmp -o timinng_comparison
//    g++ -DTEST_DIVISION=1 -DTEST_GCD=1 ... -o test_divide_and_gcd
//    g++ arithtest.cpp -O3 -lgmp -o test_everything
// Nota that some of the individual test sections run for say 20 or 30
// minutes even on a fast computer, so sometimes (especially while
// debugging or optimising) limiting which sectio is tested can make
// sense. I would encourage anybody who is at all keen to look at the
// tests here and consider additional edge cases that ought to be
// covered - and then submit updates (for instance through the mailing
// list on sourceforge - or at least making an enquiry there first to
// set up a more private discussion.

#if !defined COMPARE_GMP && \
    !defined TEST_SOME_BASICS && \
    !defined TEST_RANDOM && \
    !defined TEST_BITWISE && \
    !defined TEST_SHIFTS && \
    !defined TEST_PLUS_AND_TIMES && \
    !defined TEST_DIVISION && \
    !defined TEST_GCD && \
    !defined TEST_ISQRT && \
    !defined TEST_FLOAT

#define COMPARE_GMP 1
#define TEST_SOME_BASICS 1
#define TEST_RANDOM 1
#define TEST_BITWISE 1
#define TEST_SHIFTS 1
#define TEST_PLUS_AND_TIMES 1
#define TEST_DIVISION 1
#define TEST_GCD 1
#define TEST_ISQRT 1
#define TEST_FLOAT 1

#endif // Some case predefined

#ifdef COMPARE_GMP
#include "gmp.h"
#endif // COMPARE_GMP


// This function is to test if the least significant bit in the representation
// of a floating point value is zero. It is used when verifying the correct
// rounding of cases that fall exactly half way between two representable
// floating point numbers.

bool evenfloat(double d)
{   int x;
    d = std::frexp(d, &x);
    d = std::ldexp(d, 53);
    std::int64_t i = static_cast<std::int64_t>(d);
    return (i&1) == 0;
}

// This is extracted from a slightly old arithlib.hpp and is a direct
// classical implementation of multiplication that I have tested reasonably
// thoroughly. It is used so that its results can be compared against the
// ones that my more complicated code produce. Note that this does signed
// multiplication and it trims its output to "proper" length.

inline void referencemultiply(const std::uint64_t *a, std::size_t lena,
                              const std::uint64_t *b, std::size_t lenb,
                              std::uint64_t *c, std::size_t &lenc)
{   for (std::size_t i=0; i<lena+lenb; i++) c[i] = 0;
// If a and/or be are negative then I can treat their true values as
//    a = sa + va      b = sb + vb
// where sa and sb and the signs - represented here as 0 for a positive
// number and -2^(64*len) for a negative one. va and vb are then the simple
// bit-patterns for a and b but now interpreted as unsigned values. So if
// instead of using 64-bit digits I was using 8 bit ones, the value -3
// would be stored as 0xfd and that would be spit up as -128 + 253.
// Then a*b = sa*sb + sa*vb + sb*va + va*vb.
// The last item there is just the product of a and b when treated as
// unsigned values, and so is what I compute first here rather simply.
// If sa and/or sb is non-zero it is just the negative of a power of 2^64,
// and so I can correct the unsigned product into a signed one by (sometimes)
// subtracting a shifted version of a or b from it.
    for (std::size_t i=0; i<lena; i++)
    {   std::uint64_t hi = 0;
        for (std::size_t j=0; j<lenb; j++)
        {   std::uint64_t lo;
// The largest possible value if (hi,lo) here is (0xffffffffffffffff, 0)
// which arises if a[1], b[i] and prev_hi are all at their maximum. That
// means that in all other cases (and in particular unless lo==0) hi ends
// up LESS than the maximum, and so adding one to it can happen without
// overflow.
            arithlib_implementation::multiply64(a[i], b[j], hi, hi, lo);
            hi += arithlib_implementation::addWithCarry(lo, c[i+j], c[i+j]);
        }
        c[i+lenb] = hi;
    }
    if (arithlib_implementation::negative(a[lena-1]))
    {   std::uint64_t carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = arithlib_implementation::addWithCarry(
                        c[i+lena], ~b[i], carry, c[i+lena]);
    }
    if (arithlib_implementation::negative(b[lenb-1]))
    {   std::uint64_t carry = 1;
        for (std::size_t i=0; i<lena; i++)
            carry = arithlib_implementation::addWithCarry(
                        c[i+lenb], ~a[i], carry, c[i+lenb]);
    }
    lenc = lena + lenb;
// The actual value may be shorter than this.
//  test top digit or c and if necessary reduce lenc.
    arithlib_implementation::truncatePositive(c, lenc);
    arithlib_implementation::truncateNegative(c, lenc);
}


int main(int argc, char *argv[])
{
// If I invoke this without command line arguments it will run with
// a decent randomized sequence. If I give it a command line argument
// that is an integer it will use that to see its random number generator
// and so it will behave deterministically. This is really useful if an
// error is detected.

    std::uint64_t seed;
    if (argc <= 1 || (seed = std::atoi(argv[1])) == 0)
        seed = mersenne_twister() & 0xffff;
    std::cout << "seed = " << seed << "\n";
    reseed(seed);

    int maxbits, ntries;
    std::chrono::high_resolution_clock::time_point clk, clk2;
    std::chrono::duration<double, std::micro> elapsed;
    std::chrono::nanoseconds timing;
    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);

    const int MILLION = 1000000;

// The following are parameters for a plausible linear congruential generator.
    const std::uint64_t MULT = 6364136223846793005U;
    const std::uint64_t ADD  = 1442695040888963407U;

#ifdef COMPARE_GMP

    {   const std::size_t table_size = 300;

        const int N = 30;
        const int LEN = 1600;

        std::uint64_t a[2000], b[2000], c[5000], c1[5000];
        std::size_t lena, lenb, lenc1;

        std::size_t size[table_size];
        std::size_t testcount[table_size];
        std::chrono::nanoseconds mine[table_size];
        std::chrono::nanoseconds gmp[table_size];

        std::uint64_t my_check = 1;
        std::uint64_t gmp_check = 1;

        for (int method=0; method<3; method++)
        {   reseed(seed);
            lena = 1;
            for (std::size_t trial=0; trial<table_size; trial++)
            {   lena = (21*lena+19)/20;
                size[trial] = 0;
                if (lena >= LEN) break;
                lenb = lena;
// I start by filling my input vectors with random data. I set the same
// seed before trying my code and before trying gmp so that each get the
// same set of test cases.
                for (std::size_t i=0; i<lena; i++)
                {   a[i] = mersenne_twister();
                    b[i] = mersenne_twister();
                }
                clk = std::chrono::high_resolution_clock::now();
// When using Karatsuba the cost of a multiplication is expected to
// grow as n^1.585, and so to arrange that I tke roughly the same
// absolute time on each number-length I perform my tests a number of
// times scaled inversely by that.
                std::size_t tests = 2+(10000*N)/static_cast<int>(std::pow(
                                        static_cast<double>(lena), 1.585));
                for (std::size_t n = 0; n<tests; n++)
                {
// The gpm function mpn_mul multiplies UNSIGNED integers, while my
// bigmultiply is at a slightly higher level and deals with signed values.
// I want to compare their results, and so forcing all inputs to be positive
// (in my representation) by clearing most significant bits is necessary.
// Note that this will almost always lead to numbers that have bits all the
// way up to the limit and hence where the product is as long as it can be.
// cases where multiplying m*n leads to a result of length 1 less will not
// be exercised.
                    a[lena-1] &= 0x7fffffff7fffffffU;
                    b[lenb-1] &= 0x7fffffff7fffffffU;
// For the benefit of gmp on 32-bit platforms I will ensure that the numbers
// always have at least one bit set within the top 32-bits. For the beneit of
// my code I will arrange that the most significant bit of the top digit is 0
// so that the value is treated as positive.
                    a[lena-1] |= 0x0010000000000000U;
                    b[lenb-1] |= 0x0000001000000000U;
// So that all the administration here does not corrupt my measurement
// I do the actual multiplication of each test case 500 times.
                    bool ok;
                    switch (method)
                    {   case 0:

                            c[lena+lenb-1] = 0;
                            mpn_mul((mp_ptr)c,
                                    (mp_srcptr)a,
                                    sizeof(std::uint64_t)/
                                       sizeof(mp_limb_t)*lena,
                                    (mp_srcptr)b,
                                    sizeof(std::uint64_t)/
                                       sizeof(mp_limb_t)*lenb);

                            arithlib_implementation::bigmultiply(
                                a, lena, b, lenb, c1, lenc1);

                            ok = true;
                            for (std::size_t i=0; i<lena+lenb; i++)
                            {   if (c[i] != c1[i])
                                {   ok = false;
                                    std::cout << "Failed at " << std::dec
                                              << i << "\n";
                                }
                            }
                            if (!ok)
                            {   display("a  ", a, lena);
                                display("b  ", b, lenb);
                                display("me ", c1, lenc1);
                                display("gmp", c, lena+lenb);
                                rdisplay("a  ", a, lena);
                                rdisplay("b  ", b, lenb);
                                rdisplay("me ", c1, lenc1);
                                rdisplay("gmp", c, lena+lenb);
                                abort();
                            }
                            break;
                        case 1:
                            for (std::size_t m=0; m<500; m++)
                                arithlib_implementation::bigmultiply(
                                    a, lena, b, lenb, c1, lenc1);
// By accumulating a sort of checksum on all the products that I compute
// I will be able to reassure myself that the output from gmp and from my
// own code agrees.
                            for (std::size_t i=0; i<lena+lenb; i++)
                                my_check = my_check*MULT + c1[i];
                            break;
                        case 2:
                            for (std::size_t m=0; m<500; m++)
                                mpn_mul((mp_ptr)c,
                                        (mp_srcptr)a, lena,
                                        (mp_srcptr)b, lenb);
                            for (std::size_t i=0; i<lena+lenb; i++)
                                gmp_check = gmp_check*MULT + c[i];
                            break;
                    }
// I alter the inputs using a linear congruential scheme (which is cheap)
// so that for any length inputs I am doing test multiplications of a
// range of varied cases. This is so that stray special cases are less liable
// to corrupt my results.
                    for (std::size_t i=0; i<lena; i++)
                        a[i] = MULT*a[i] + ADD;
                    for (std::size_t i=0; i<lenb; i++)
                        b[i] = MULT*b[i] + ADD;
                }
                clk2 = std::chrono::high_resolution_clock::now();
                elapsed = clk2 - clk;
                timing =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
// I store details of this test run in an array for display later on.
                size[trial] = lena;
                testcount[trial] = 500*tests;
                switch (method)
                {   case 0:
                        std::cout << ".";
                        break;
                    case 1:
                        mine[trial] = timing;
                        std::cout << ":";
                        break;
                    case 2:
                        gmp[trial] = timing;
                        std::cout << "|";
                        break;
                }
                std::cout.flush();
            }
            std::cout << "\n";
        }
// Display the checksum output. Note that this also ensures that the
// result of the multiplication (well more pedantically the result of
// the last of 500 multiplications!) is used so clever optimizing
// compilers are not allowed to avoid computing it!
        std::cout << "\n";
        std::cout << (my_check == gmp_check ? "checksums match" :
                      "checksums disagree")
                  << "\n";
        std::cout << std::hex << "my checksum:  " << my_check << "\n";
        std::cout             << "gmp checksum: " << gmp_check << "\n";
        std::cout << std::dec;
        std::cout << "Times are reported in seconds per multiplication"
                  << "\n";
        std::cout << std::setw(10) << "length"
                  << std::setw(10) << "my time"
                  << std::setw(10) << "gmp time"
                  << std::setw(10) << "  ratio mine/gmp"
                  << std::fixed << std::setprecision(3)
                  << "\n";
// In the following table times are reported in seconds per
// multiplication. The ratio is > 1.0 when my code is slower than gmp.
        for (std::size_t i=0; i<table_size; i++)
        {   if (size[i] == 0) break;
            std::cout << std::setw(10) << size[i]
                      << std::setw(10) << (1.0e-3*static_cast<double>
                                           (mine[i].count())/testcount[i])
                      << std::setw(10) << (1.0e-3*static_cast<double>
                                           (gmp[i].count())/testcount[i])
                      << std::setw(10) << (static_cast<double>
                                           (mine[i].count())/gmp[i].count())
                      << "\n";
        }
    }
#endif // COMPARE_GMP

#ifdef TEST_SOME_BASICS

// Do some very simple operations that just verify that printing and
// basic arithmetic is in order.

    std::cout << "Some simple tests involving powers of 10" << "\n";
// Observe the custom integer format with suffix "_Z" so that bit integers
// can be input easily. At present I have not put in code to support other
// than decimal notation in this style.
    Bignum a = 10000000000000000000000000_Z;
    std::cout << "a = " << a << "\n";
    std::cout << "a*a = " << (a*a) << "\n";
    std::cout << "a*100 = " << (a*100_Z) << "\n";
    std::cout << "100*a = " << (100_Z*a) << "\n";
    std::cout << "100*100 = " << (100_Z*100_Z) << "\n";
    std::cout << "End of simple tests" << "\n" << "\n";

#endif


#ifdef TEST_RANDOM

// For many of my later tests I use random inputs, but the random distribution
// used is a really odd one! It starts by having a uniform distribution over
// the number of bits in the number. It then takes raw random numbers ("a"
// here) generated that way and takes "a" and round down to "x", the largest
// power of 2 less than or equalt to x. It then returns one of
//    a, x-1, x, x+1, -(x-1), -x, -(x+1)
// with the generically random first case (just "a") happening most often.
// The reasoning behind this choice for test cases is that the internal
// representation used here involves a radix of 2^64, and so numbers close
// to powers of 2 (and their negatives) are potential special cases and
// deserve extra testing.
//
// This section of the test code just displays 10 random values each with
// no more than 160 bits and it illustrates printing in both decimal and
// hexadecimal.

    maxbits = 80;
    ntries = 10;

    std::cout << "Print some random numbers in decimal and hex" <<
              "\n";
    for (int i=1; i<=ntries; i++)
    {   Bignum a = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        Bignum b = fudgeDistributionBignum(a, static_cast<int>(r) & 0xf);
//      std::cout << a << "\n";
        std::cout << b << " "
                  << std::hex << b << std::dec
                  << "\n";
    }
    std::cout << "end of display of random values" << "\n" <<
              "\n";

#endif // TEST_RANDOM


#ifdef TEST_BITWISE

// I test the bitwise operations by performing two comparisons:
//       ~(a & b) == ~a | ~b
// and   a ^ b == ~a^b | ~b^a
//
// Note that negative numbers are stored in 2s complement and should be
// treated as if they have an infinite number of leading 1 bits beyond the
// most significant bit that they store.
//
// If I observe a discrepancy here (and in later tests) I will display the
// inputs that led to it so that those can be checked further for debugging.

    maxbits = 400;
    ntries = 50*MILLION;

    std::cout << "Start of bitwise operation testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a = randomUptoBitsBignum(maxbits);
        Bignum b = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        a = fudgeDistributionBignum(a, static_cast<int>(r) & 0xf);
        b = fudgeDistributionBignum(b, static_cast<int>(r>>4) & 0xf);
        Bignum c1 = ~(a & b);
        Bignum c2 = (~a) | (~b);
        Bignum c3 = a ^ b;
        Bignum c4 = (a&(~b)) | (b&(~a));
        if (c1==c2 && c3==c4) continue;
        std::cout << "FAILED on test " << i << std::hex << "\n";
        std::cout << "a            " << a << "\n";
        std::cout << "b            " << b << "\n";
        std::cout << "c1 ~(a&b)    " << c1 << "\n";
        std::cout << "c2 ~a|~b     " << c2 << "\n";
        std::cout << "c3 a^b       " << c3 << "\n";
        Bignum nota = ~a;
        Bignum notb = ~b;
        std::cout << "   ~a        " << nota << "\n";
        std::cout << "   ~b        " << notb << "\n";
// Sending something to std::cout is the normal way of observing values
// in the code here, but the function display() as used in the diagnostic
// being printed at present shows the internal representation of the
// numbers.
        display("b", b);
        display("nota", nota);
        std::cout << "   a&~b      " << (a&~b) << "\n";
        Bignum bnota = b & (~a);
        std::cout << "   b&~a      " << bnota << "\n";
        display("bnota", bnota);
        std::cout << "c4 a&~b|b&~a "  << c4 << "\n";
        std::cout << "Failed " << std::dec << "\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Bitwise operation tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_BITWISE


#ifdef TEST_SHIFTS

// For testing shifts I will compare the result of a<<n with a*pow(2,n)
// and a>>n with a/pow(2^n) but with the division actually of
// (a & ~(pow(2,n)-1)) rather than just a so that the division is exact
// and the treatment of negative inputs is as desired. I will include cases
// where the shift amount is greater than the bit-length of the input.

    maxbits = 800;
    ntries = 50*MILLION;

    std::cout << "Start of shift testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        a = fudgeDistributionBignum(a, static_cast<int>(r) & 0xf);
        r = (r >> 4)%800;
        Bignum c1 = a << r;
        Bignum p = pow(Bignum(2), static_cast<std::int64_t>(r));
        Bignum c2 = a * p;
        Bignum c3 = a >> r;
        Bignum w = a & ~(p-1_Z);
        Bignum c4 = (a & ~(p-1_Z))/p;
        if (c1==c2 && c3==c4) continue;
        std::cout << "FAILED on test " << i << "\n";
        display("c1", c1);
        display("c2", c2);
        display("c3", c3);
        display("c4", c4);
        std::cout << "c1-c2 = " << (c1-c2) << "\n"; 
        std::cout << "c3-c4 = " << (c3-c4) << "\n"; 
        
        std::cout << "a            " << a << "\n";
        std::cout << "a            " << std::hex << a << std::dec << "\n";
        std::cout << "r            " << r << "\n";
        std::cout << "r            " << std::hex << r << std::dec << "\n";
                  "\n";
        std::cout << "divide "  << w << "\n";
        display("div", w);
        std::cout << "by " << p << "\n";
        display(" by", p);
        std::cout << "p            " << p << "\n";
        std::cout << "a&~(p-1)     " << (a&~(p-1_Z)) << "\n";
        std::cout << "c1 a<<r      " << c1 << "\n";
        std::cout << "c2 a*2^r     " << c2 << "\n";
        std::cout << "c3 a>>r      " << c3 << "\n";
        std::cout << "c4 a/2^r     " << c4 << "\n";
        std::cout << "Failed " << "\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Shift tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_SHIFTS


#ifdef TEST_PLUS_AND_TIMES

// To check that + and - and * behave on the Bignum type I
// generate random numbers a and b and then compute first (a+b)*(a-b)
// and then a*a-b*b. If these match I feel happy - while if I find a case
// where the two values differ I have uncovered a bug. I also check that the
// square() function [which should be a bit faster than doing a simple
// multiplication] yields the same results.

    maxbits = 600;
    ntries = 50*MILLION;

    std::cout << "Start of Plus and Times testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a = randomUptoBitsBignum(maxbits);
        Bignum b = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        a = fudgeDistributionBignum(a, static_cast<int>(r) & 0xf);
        b = fudgeDistributionBignum(b, static_cast<int>(r>>4) & 0xf);
        Bignum c1 = (a + b)*(a - b);
        Bignum c2 = a*a - b*b;
        Bignum c3 = square(a) - square(b);
        if (c1 == c2 && c2 == c3) continue;
        std::cout << "FAILED on test " << i << "\n";
        std::cout << "a  = " << a << "\n";
        std::cout << "b  = " << b << "\n";
        std::cout << "a+b         = " << a+b << "\n";
        std::cout << "a-b         = " << a-b << "\n";
        std::cout << "a*a         = " << a*a << "\n";
        std::cout << "b*b         = " << b*b << "\n";
        std::cout << "(a+b)*(a-b) = " << c1 << "\n";
        std::cout << "(a+b)*(b-a) = " << (a+b)*(b-a) << "\n";
        std::cout << "a*a-b*b     = " << c2 << "\n";
        std::cout << "square(a)   = " << square(a) << "\n";
        std::cout << "square(b)   = " << square(b) << "\n";
        std::cout << "square(-a)  = " << square(-a) << "\n";
        std::cout << "square(-b)  = " << square(-b) << "\n";
        std::cout << "Failed" << "\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Plus and Times tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_PLUS_AND_TIMES


#ifdef TEST_DIVISION

// For division testing I start by generating random numbers that will
// be my divisor, quotient and remainder. I derive a dividend from them
// and then combine those values to get a dividend. I then check that
// the division and remainder operations recover my original values.
// I have a function that returns both quotient and remainder, but I do not
// have an extra test of that here (yet).

    maxbits = 400;
    ntries = 50*MILLION;

    std::cout << "Start of division testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum divisor, remainder, quotient;
        do
        {   divisor = randomUptoBitsBignum(maxbits) + 1;
            remainder = uniformUptoBignum(divisor);
            quotient = randomUptoBitsBignum(maxbits);
            std::uint64_t rr = mersenne_twister();
            divisor = fudgeDistributionBignum(divisor,
                                                static_cast<int>(rr & 0xf));
            remainder = fudgeDistributionBignum(remainder,
                                                  static_cast<int>((rr>>4) & 0xf));
            quotient = fudgeDistributionBignum(quotient,
                                                 static_cast<int>((rr>>8) & 0xf));
// While I still want my strange distribution of numbers for testing, I
// need the sign of my target remainder to be proper, so I will generate
// random inputs until that is so. Also when I adjust the numbers I could
// reduce the divisor more than the remainder so that the remainder was
// invalid in magnitude... so I need to discard those cases too. It is
// plausible that this means I will discard around 75% of the sets of random
// numberfs that I initially generate.
        }
        while (((quotient ^ remainder ^ divisor) < Bignum(0)) ||
               (abs(remainder) >= abs(divisor)));

        Bignum dividend = quotient*divisor + remainder;
        Bignum q1 = dividend / divisor;
        Bignum r1 = 999999;
// If the quotient is incorrect I will not compute the remainder.
        if (q1 == quotient)
        {   r1 = dividend % divisor;
            if (r1 == remainder) continue;
        }
        std::cout << "FAILED on test " << i << "\n";
        std::cout << "divisor   " << divisor << "\n";
        std::cout << "remainder " << remainder << "\n";
        std::cout << "quotient  " << quotient << "\n";
        std::cout << "dividend  " << dividend << "\n";
        std::cout << "q1        " << q1 << "\n";
        std::cout << "r1        " << r1 << "\n";
        display("dividend ", dividend);
        display("divisor  ", divisor);
        display("remainder", remainder);
        display("quotient ", quotient);
        display("q1       ", q1);
        display("r1       ", r1);
        std::cout << "Failed " << "\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Division tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_DIVISION

#ifdef TEST_GCD

// Set up three values a, b and g. Let g'=gcd(a,b), g''=gcd(a*g,b*g) and
// check if g''=g*g', and if g'' divides evenly into both a*g and b*g.

    maxbits = 300;
    ntries = 20*MILLION;

    std::cout << "Start of GCD testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a, b, g;
        do
        {   a = randomUptoBitsBignum(maxbits);
            b = randomUptoBitsBignum(maxbits);
            g = randomUptoBitsBignum(maxbits);
            std::uint64_t rr = mersenne_twister();
            a = fudgeDistributionBignum(a, static_cast<int>(rr & 0xf));
            b = fudgeDistributionBignum(b, static_cast<int>((rr>>4) & 0xf));
            g = fudgeDistributionBignum(g, static_cast<int>((rr>>8) & 0xf));
        }
        while (a<=0 || b<=0 || g<=0);
        Bignum g1 = gcd(a, b);
        Bignum A = a*g;
        Bignum B = b*g;
        Bignum g2 = gcd(A, B);
        if (g2 == g1*abs(g) &&
            A%g2 == 0 &&
            B%g2 == 0) continue;
        std::cout << "FAILED on test " << i << "\n";
        if (g2 != g1*abs(g)) std::cout << "g2 is wrong\n";
        if (A%g2 != 0) std::cout << "g2 remainder with A\n";
        if (B%g2 != 0) std::cout << "g2 remainder with B\n";
        std::cout << "a  " << a << "\n";
        std::cout << "b  " << b << "\n";
        std::cout << "g  " << g << "\n";
        std::cout << "A  " << A << "\n";
        std::cout << "B  " << B << "\n";
        std::cout << "g1 " << g1 << "\n";
        std::cout << "g2 " << g2 << "\n";
        display("a  ", a);
        display("b  ", b);
        display("g  ", g);
        display("A  ", A);
        display("B  ", B);
        display("g1 ", g1);
        display("g2 ", g2);
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "GCD tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_GCD

#ifdef TEST_ISQRT

// For various inputs I compute isqrt() and verify that the square of
// that value is no greater than my original input, while if I add one
// and square I get something larger.

    maxbits = 900;
    ntries = 50*MILLION;

    std::cout << "Start of isqrt testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a, b;
        a = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        a = fudgeDistributionBignum(a, static_cast<int>(r) & 7);
        b = isqrt(a);
        if (square(b) <= a && square(b+1) > a) continue;
        std::cout << "FAILED on test " << i << "\n";
        std::cout << "a         " << a << "\n";
        std::cout << "b         " << b << "\n";
        std::cout << "b^2       " << square(b) << "\n";
        std::cout << "(b+1)^2   " << square(b+1) << "\n";
        display("a", a);
        display("b", b);
        std::cout << "Failed " << "\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);

    std::cout << "Isqrt tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_ISQRT

#ifdef TEST_FLOAT

// To test FLOAT and FIX I will generate a random integer and convert to
// floating point. I then look at floating point values just larger and
// just smaller than the one that I obtained, and verify that my result
// is closer to the original input than the other two. If there is a tie
// I will expect my value to have its least significant bit zero.

    maxbits = 500;
    ntries = 50*MILLION;

// On some systems (notable 32-bit cygwin and at least some older
// 32-bit Linux systems running on x86) floating point arithmetic is
// performed in 80-bit working precision, so some of my attempts here
// to check results are thwarted. I cope with that by forcing important
// values through the following volatile variable.
    volatile double fp_forcer;

    std::cout << "Start of float testing" << "\n";
    clk = std::chrono::high_resolution_clock::now();

    for (int i=1; i<=ntries; i++)
    {   Bignum a, b;
        a = randomUptoBitsBignum(maxbits);
        std::uint64_t r = mersenne_twister();
        a = fudgeDistributionBignum(a, static_cast<int>(r) & 15);

        double d = doubleBignum(a);
        Bignum n = fixBignum(d);
        if (a == n) continue; // round trip was exact!

        fp_forcer = d + 1.0;
        double dplus = fp_forcer;
        if (dplus == d) dplus = std::nextafter(d, 1.0e300);
        assert(dplus != d);
        fp_forcer = d - 1.0;
        double dminus = fp_forcer;
        if (dminus == d) dminus = std::nextafter(d, -1.0e300);
        assert(dminus != d);
        Bignum nplus = fixBignum(dplus);
        Bignum nminus = fixBignum(dminus);
        Bignum err = a-n;
        Bignum errplus = a-nplus;
        Bignum errminus = a-nminus;

        if (nplus != n && nminus != n)
        {   if (abs(err) < abs(errplus) &&
                abs(err) < abs(errminus)) continue;
            if (abs(err) == abs(errplus) &&
                abs(err) < abs(errminus) && evenfloat(d)) continue;
            if (abs(err) < abs(errplus) &&
                abs(err) == abs(errminus) && evenfloat(d)) continue;
        }

        std::cout << "FAILED on test " << i << "\n";
        std::cout << "a       " << a << "\n";
        std::cout << "a       " << std::hex << a << std::dec << "\n";
        std::cout << "d       " << std::setprecision(19) << d << "\n";
        std::cout << "d-      " << dminus << "\n";
        std::cout << "d+      " << dplus << "\n";
        std::cout << "nminus  " << nminus << "\n";
        std::cout << "n       " << n << "\n";
        std::cout << "nplus   " << nplus << "\n";
        std::cout << "err-    " << errminus << "\n";
        std::cout << "err     " << err << "\n";
        std::cout << "err+    " << errplus << "\n";
        display("a", a);
        display("n", n);
        std::cout << "Failed " << "\n";
        if (nplus == n) std::cout << "nplus == n\n";
        if (nminus == n) std::cout << "nminus == n\n";
        if (abs(err) >= abs(errplus)) std::cout << "abs(err) >= abs(errplus)\n";
        if (abs(err) >= abs(errminus)) std::cout << "abs(err) >= abs(errminus)\n";
        if (abs(err) == abs(errplus)) std::cout << "abs(err) == abs(errplus)\n";
        if (abs(err) == abs(errminus)) std::cout << "abs(err) == abs(errplus)\n";
        if (evenfloat(d)) std::cout << "evenfloat(d)\n";
        else std::cout << "oddfloat(d)\n";
        abort();
        return 1;
    }

    clk2 = std::chrono::high_resolution_clock::now();
    elapsed = clk2 - clk;
    timing =
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Float tests completed in "
              << (timing.count()/1.0e9) << " sec" << "\n";

#endif // TEST_FLOAT

    std::cout << "About to exit" << "\n";
    return 0;
}

// end of arithtest.cpp
