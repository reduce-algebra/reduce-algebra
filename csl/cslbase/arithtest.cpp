// Test code for Big-number arithmetic.                    A C Norman, 2019


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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


// My bignum package is a header-only library, so to use it you arrange
// that the c++ compiler has a directive such as "-Idirectory_for_arithlib"
// so that it can be found and you then just include the one file that
// contains everything.

#include "arithlib.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace arithlib;

// The tests come in sections, and these preprocessor symbols can be used
// to select which sections get run.

//#define TUNE_KARATSUBA 1
#define COMPARE_GMP 1
#define TEST_SOME_BASICS 1
#define TEST_RANDOM 1
#define TEST_BITWISE 1
#define TEST_SHIFTS 1
#define TEST_PLUS_AND_TIMES 1
#define TEST_DIVISION 1
#define TEST_GCD 1
#define TEST_ISQRT 1
#define TEST_FLOAT

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
    int64_t i = (int64_t)d;
    return (i&1) == 0;
}

// This is extracted from a slightly old arithlib.hpp and is a direct
// classical implementation of multiplication that I have tested reasonably
// thoroughly. It is used so that its results can be compared against the
// ones that my more complicated code produce. Note that this does signed
// multiplication and it trims its output to "proper" length.

inline void referencemultiply(const uint64_t *a, size_t lena,
                             const uint64_t *b, size_t lenb,
                             uint64_t *c, size_t &lenc)
{   for (size_t i=0; i<lena+lenb; i++) c[i] = 0;
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
    for (size_t i=0; i<lena; i++)
    {   uint64_t hi = 0;
        for (size_t j=0; j<lenb; j++)
        {   uint64_t lo;
// The largest possible value if (hi,lo) here is (0xffffffffffffffff, 0)
// which arises if a[1], b[i] and prev_hi are all at their maximum. That
// means that in all other cases (and in particular unless lo==0) hi ends
// up LESS than the maximum, and so adding one to it can happen without
// overflow.
            multiply64(a[i], b[j], hi, hi, lo);
            hi += add_with_carry(lo, c[i+j], c[i+j]);
        }
        c[i+lenb] = hi;
    }
    if (negative(a[lena-1]))
    {   uint64_t carry = 1;
        for (size_t i=0; i<lenb; i++)
            carry = add_with_carry(c[i+lena], ~b[i], carry, c[i+lena]);
    }
    if (negative(b[lenb-1]))
    {   uint64_t carry = 1;
        for (size_t i=0; i<lena; i++)
            carry = add_with_carry(c[i+lenb], ~a[i], carry, c[i+lenb]);
    }
    lenc = lena + lenb;
// The actual value may be shorter than this.
//  test top digit or c and if necessary reduce lenc.
    truncate_positive(c, lenc);
    truncate_negative(c, lenc);
}


int main(int argc, char *argv[])
{
// If I invoke this without command line arguments it will run with
// a decent randomized sequence. If I give it a command line argument
// that is an integer it will use that to see its random number generator
// and so it will behave deterministically. This is really useful if an
// error is detected.

    uint64_t seed;
    if (argc > 1) seed = atoi(argv[1]);
    else seed = mersenne_twister() & 0xffff;
    std::cout << "seed = " << seed << std::endl;
    reseed(seed);

    int maxbits, ntries;
    clock_t clk;
    int64_t clong;
    double timing;

    const int MILLION = 1000000;

// The following are parameters for a plausible linear congruential generator.
    const uint64_t MULT = 6364136223846793005U;
    const uint64_t ADD  = 1442695040888963407U;


#ifdef TUNE_KARATSUBA

// See the separate file kara2.cpp (which may not be available by now!) for
// code that runs timings for a range of values of KARATSUBA_CUTOFF so that
// it can suggest the best one to use.

#endif // TUNE_KARATSUBA

#ifdef COMPARE_GMP

    {   const size_t table_size = 300;

        const int N = 30;
        const int LEN = 1600;
 
        uint64_t a[2000], b[2000], c[5000], c1[5000];
        size_t lena, lenb, lenc1;

        size_t size[table_size];
        size_t testcount[table_size];
        double mine[table_size];
        double gmp[table_size];

        uint64_t my_check = 1;
        uint64_t gmp_check = 1;

        for (int method=0; method<3; method++)
        {   reseed(seed);
            lena = 1;
            for (size_t trial=0; trial<table_size; trial++)
            {   lena = (21*lena+19)/20;
                size[trial] = 0;
                if (lena >= LEN) break;
                lenb = lena;
// I start by filling my input vectors with random data. I set the same
// seed before trying my code and before trying gmp so that each get the
// same set of test cases.
                for (size_t i=0; i<lena; i++)
                {   a[i] = mersenne_twister();
                    b[i] = mersenne_twister();
                }
                clock_t cl0 = clock();
// When using Karatsuba the cost of a multiplication is expected to
// grow as n^1.585, and so to arrange that I tke roughly the same
// absolute time on each number-length I perform my tests a number of
// times scaled inversely by that.
                size_t tests = 2+(10000*N)/(int)std::pow((double)lena, 1.585);
                for (size_t n = 0; n<tests; n++)
                {
// The gpm function mpn_mul multiplies unsigned integers, while my
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
                    {
                    case 0:
                        bigmultiply(a, lena, b, lenb, c1, lenc1);
                        c[lena+lenb-1] = 0;
                        mpn_mul((mp_ptr)c,
                                (mp_srcptr)a,
                                sizeof(uint64_t)/sizeof(mp_limb_t)*lena,
                                (mp_srcptr)b,
                                sizeof(uint64_t)/sizeof(mp_limb_t)*lenb);
                        ok = true;
                        for (size_t i=0; i<lena+lenb; i++)
                        {   if (c[i] != c1[i])
                            {   ok = false;
                                std::cout << "Failed at " << std::dec << i << std::endl;
                            }
                        }
                        if (!ok)
                        {   display("a  ", a, lena);
                            display("b  ", b, lenb);
                            display("me ", c1, lenc1);
                            display("gmp", c, lena+lenb);
                            abort();
                        }
                        break;
                    case 1:
                        for (size_t m=0; m<500; m++)
                            bigmultiply(a, lena, b, lenb, c1, lenc1);
// By accumulating a sort of checksum on all the products that I compute
// I will be able to reassure myself that the output from gmp and from my
// own code agrees.
                        for (size_t i=0; i<lena+lenb; i++)
                            my_check = my_check*MULT + c1[i];
                        break;
                    case 2:
                        for (size_t m=0; m<500; m++)
                            mpn_mul((mp_ptr)c,
                                    (mp_srcptr)a, lena,
                                    (mp_srcptr)b, lenb);
                        for (size_t i=0; i<lena+lenb; i++)
                            gmp_check = gmp_check*MULT + c[i];
                        break;
                    }
// I alter the inputs using a linear congruential scheme (which is cheap)
// so that for any length inputs I am doing test multiplications of a
// range of varied cases. This is so that stray special cases are less liable
// to corrupt my results.
                    for (size_t i=0; i<lena; i++)
                        a[i] = MULT*a[i] + ADD;
                    for (size_t i=0; i<lenb; i++)
                        b[i] = MULT*b[i] + ADD;
                }
                clock_t cl1 = clock();
                double t = (cl1-cl0)/(double)CLOCKS_PER_SEC;
// I store details of this test run in an array for display later on.
                size[trial] = lena;
                testcount[trial] = 500*tests;
                switch (method)
                {
                case 0:
                    std::cout << ".";
                    break;
                case 1:
                    mine[trial] = t;
                    std::cout << ":";
                    break;
                case 2:
                    gmp[trial] = t;
                    std::cout << "|";
                    break;
                }
                std::cout.flush();
            }
            std::cout << std::endl;
        }
// Display the checksum output. Note that this also ensures that the
// result of the multiplication (well more pedantically the result of
// the last of 500 multiplications!) is used so clever optimizing
// compilers are not allowed to avoid computing it!
        std::cout << std::endl;
        std::cout << (my_check == gmp_check ? "checksums match" :
                                              "checksums disagree")
                  << std::endl;
        std::cout << std::hex << "my checksum:  " << my_check << std::endl;
        std::cout             << "gmp checksum: " << gmp_check << std::endl;
        std::cout << std::dec;
        std::cout << "Times are reported in microseconds per multiplication"
                  << std::endl;
        std::cout << std::setw(10) << "length"
                  << std::setw(10) << "my time"
                  << std::setw(10) << "gmp time"
                  << std::setw(10) << "  ratio mine/gmp"
                  << std::fixed << std::setprecision(3)
                   << std::endl;
// In the following table times are reported in microseconds per
// multiplication. The ratio is > 1.0 when my code is slower than gmp.
        for (size_t i=0; i<table_size; i++)
        {   if (size[i] == 0) break;
            std::cout << std::setw(10) << size[i]
                      << std::setw(10) << (1.0e6*mine[i]/testcount[i])
                      << std::setw(10) << (1.0e6*gmp[i]/testcount[i])
                      << std::setw(10) << (mine[i]/gmp[i])
                      << std::endl;
        }
    }
#endif // COMPARE_GMP

#ifdef TEST_SOME_BASICS

// Do some very simple operations that just verify that printing and
// basic arithmetic is in order.

    std::cout << "Some simple tests involving powers of 10" << std::endl;
// Observe the custom integer format with suffix "_Z" so that bit integers
// can be input easily. At present I have not put in code to support other
// than decimal notation in this style.
    Bignum a = 10000000000000000000000000_Z;
    std::cout << "a = " << a << std::endl;
    std::cout << "a*a = " << (a*a) << std::endl;
    std::cout << "a*100 = " << (a*100_Z) << std::endl;
    std::cout << "100*a = " << (100_Z*a) << std::endl;
    std::cout << "100*100 = " << (100_Z*100_Z) << std::endl;
    std::cout << "End of simple tests" << std::endl << std::endl;

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

    std::cout << "Print some random numbers in decimal and hex" << std::endl;
    for (int i=1; i<=ntries; i++)
    {   Bignum a = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        Bignum b = fudge_distribution_bignum(a, (int)r & 0xf);
//      std::cout << a << std::endl;
        std::cout << b << " "
                  << std::hex << b << std::dec
                  << std::endl;
    }
    std::cout << "end of display of random values" << std::endl << std::endl;

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

    std::cout << "Start of bitwise operation testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {
// On some 32-bit systems clock_t is a 32-bit type and CLOCKS_PER_SEC
// is 1000000. The consequence is that clock readings overflow after about
// half an hour of CPU time. The tests here can reasonably be configured
// such that on a slow machine this limit may be exceeded. To work around
// that I unload from clock() into an int64_t value every million times
// round my loop. On a sufficiently slow system this would not cure the
// problem, but in realistic cases it will and the overhead of the test
// here and the extra work every 2^20 iterations is not liable to be severe. 
        if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a = random_upto_bits_bignum(maxbits);
        Bignum b = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        a = fudge_distribution_bignum(a, (int)r & 0xf);
        b = fudge_distribution_bignum(b, (int)(r>>4) & 0xf);
        Bignum c1 = ~(a & b);
        Bignum c2 = (~a) | (~b);
        Bignum c3 = a ^ b;
        Bignum c4 = (a&(~b)) | (b&(~a));
        if (c1==c2 && c3==c4) continue;
        std::cout << "FAILED on test " << i << std::hex << std::endl;
        std::cout << "a            " << a << std::endl;
        std::cout << "b            " << b << std::endl;
        std::cout << "c1 ~(a&b)    " << c1 << std::endl;
        std::cout << "c2 ~a|~b     " << c2 << std::endl;
        std::cout << "c3 a^b       " << c3 << std::endl;
        Bignum nota = ~a;
        Bignum notb = ~b;
        std::cout << "   ~a        " << nota << std::endl;
        std::cout << "   ~b        " << notb << std::endl;
// Sending something to std::cout is the normal way of observing values
// in the code here, but the function display() as used in the diagnostic
// being printed at present shows the internal representation of the
// numbers.
        display("b", b);
        display("nota", nota);
        std::cout << "   a&~b      " << (a&~b) << std::endl;
        Bignum bnota = b & (~a);
        std::cout << "   b&~a      " << bnota << std::endl;
        display("bnota", bnota);
        std::cout << "c4 a&~b|b&~a "  << c4 << std::endl;
        std::cout << "Failed " << std::dec << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Bitwise operation tests completed in "
              << timing << " sec" << std::endl;

#endif // TEST_BITWISE


#ifdef TEST_SHIFTS

// For testing shifts I will compare the result of a<<n with a*pow(2,n)
// and a>>n with a/pow(2^n) but with the division actually of
// (a & ~(pow(2,n)-1)) rather than just a so that the division is exact
// and the treatment of negative inputs is as desired. I will include cases
// where the shift amount is greater than the bit-length of the input.

    maxbits = 800;
    ntries = 50*MILLION;

    std::cout << "Start of shift testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        a = fudge_distribution_bignum(a, (int)r & 0xf);
        r = (r >> 4)%800;
        Bignum c1 = a << r;
        Bignum p = pow(Bignum(2), (int)r);
        Bignum c2 = a * p;
        Bignum c3 = a >> r;
        Bignum w = a & ~(p-1_Z);
        Bignum c4 = (a & ~(p-1_Z))/p;
        if (c1==c2 && c3==c4) continue;
        std::cout << "FAILED on test " << i << std::hex << std::endl;
        std::cout << "a            " << a << std::endl;
        std::cout << "r            " << std::dec << r << std::hex << std::endl;
        std::cout << "divide " << std::dec << w << std::endl;
        display("div", w);
        std::cout << "by " << std::dec << p << std::hex << std::endl;
        display(" by", p);
        std::cout << "p            " << p << std::endl;
        std::cout << "a&~(p-1)     " << (a&~(p-1_Z)) << std::endl;
        std::cout << "c1 a<<r      " << c1 << std::endl;
        std::cout << "c2 a*2^r     " << c2 << std::endl;
        std::cout << "c3 a>>r      " << c3 << std::endl;
        std::cout << "c4 a/2^r     " << c4 << std::endl;
        display("c4", c4);
        std::cout << "Failed " << std::dec << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Shift tests completed in "
              << timing << " sec" << std::endl;

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

    std::cout << "Start of Plus and Times testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a = random_upto_bits_bignum(maxbits);
        Bignum b = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        a = fudge_distribution_bignum(a, (int)r & 0xf);
        b = fudge_distribution_bignum(b, (int)(r>>4) & 0xf);
        Bignum c1 = (a + b)*(a - b);
        Bignum c2 = a*a - b*b;
        Bignum c3 = square(a) - square(b);
        if (c1 == c2 && c2 == c3) continue;
        std::cout << "FAILED on test " << i << std::endl;
        std::cout << "a  = " << a << std::endl;
        std::cout << "b  = " << b << std::endl;
        std::cout << "a+b         = " << a+b << std::endl;
        std::cout << "a-b         = " << a-b << std::endl;
        std::cout << "a*a         = " << a*a << std::endl;
        std::cout << "b*b         = " << b*b << std::endl;
        std::cout << "(a+b)*(a-b) = " << c1 << std::endl;
        std::cout << "(a+b)*(b-a) = " << (a+b)*(b-a) << std::endl;
        std::cout << "a*a-b*b     = " << c2 << std::endl;
        std::cout << "square(a)   = " << square(a) << std::endl;
        std::cout << "square(b)   = " << square(b) << std::endl;
        std::cout << "square(-a)  = " << square(-a) << std::endl;
        std::cout << "square(-b)  = " << square(-b) << std::endl;
        std::cout << "Failed" << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Plus and Times tests completed in "
              << timing << " sec" << std::endl;

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

    std::cout << "Start of division testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum divisor, remainder, quotient;
        do
        {   divisor = random_upto_bits_bignum(maxbits) + 1;
            remainder = uniform_upto_bignum(divisor);
            quotient = random_upto_bits_bignum(maxbits);
            uint64_t rr = mersenne_twister();
            divisor = fudge_distribution_bignum(divisor, (int)(rr & 0xf));
            remainder = fudge_distribution_bignum(remainder, (int)((rr>>4) & 0xf));
            quotient = fudge_distribution_bignum(quotient, (int)((rr>>8) & 0xf));
// While I still want my strange distribution of numbers for testing, I
// need the sign of my target remainder to be proper, so I will generate
// random inputs until that is so. Also when I adjust the numbers I could
// reduce the divisor more than the remainder so that the remainder was
// invalid in magnitude... so I need to discard those cases too. It is
// plausible that this means I will discard around 75% of the sets of random
// numberfs that I initially generate.
        } while (((quotient ^ remainder ^ divisor) < Bignum(0)) ||
                 (abs(remainder) >= abs(divisor))); 

        Bignum dividend = quotient*divisor + remainder;
        Bignum q1 = dividend / divisor;
        Bignum r1 = 999999;
// If the quotient is incorrect I will not compute the remainder.
        if (q1 == quotient)
        {   r1 = dividend % divisor;
            if (r1 == remainder) continue;
        }
        std::cout << "FAILED on test " << i << std::endl;
        std::cout << "divisor   " << divisor << std::endl;
        std::cout << "remainder " << remainder << std::endl;
        std::cout << "quotient  " << quotient << std::endl;
        std::cout << "dividend  " << dividend << std::endl;
        std::cout << "q1        " << q1 << std::endl;
        std::cout << "r1        " << r1 << std::endl;
        display("dividend ", dividend);
        display("divisor  ", divisor);
        display("remainder", remainder);
        display("quotient ", quotient);
        display("q1       ", q1);
        display("r1       ", r1);
        std::cout << "Failed " << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Division tests completed in "
              << timing << " sec" << std::endl;

#endif // TEST_DIVISION

#ifdef TEST_GCD

// Set up three values a, b and g. Let g'=gcd(a,b), g''=gcd(a*g,b*g) and
// check if g''=g*g', and if g'' divides evenly into both a*g and b*g.

    maxbits = 300;
    ntries = 20*MILLION;

    std::cout << "Start of GCD testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a, b, g;
        do
        {   a = random_upto_bits_bignum(maxbits);
            b = random_upto_bits_bignum(maxbits);
            g = random_upto_bits_bignum(maxbits);
            uint64_t rr = mersenne_twister();
            a = fudge_distribution_bignum(a, (int)(rr & 0xf));
            b = fudge_distribution_bignum(b, (int)((rr>>4) & 0xf));
            g = fudge_distribution_bignum(g, (int)((rr>>8) & 0xf));
        } while (a<=0 || b<=0 || g<=0);
//        std::cout << i << " " << a << " " << b << " " << g << std::endl;
//        display("a", a);
//        display("a", b);
        Bignum g1 = gcd(a, b);
        Bignum A = a*g;
        Bignum B = b*g;
//        std::cout << i << " " << A << " " << B << std::endl;
//        display("A", A);
//        display("B", B);
        Bignum g2 = gcd(A, B);
        if (g2 == g1*abs(g) &&
            A%g2 == 0 &&
            B%g2 == 0) continue;
        std::cout << "FAILED on test " << i << std::endl;
        std::cout << "a  " << a << std::endl;
        std::cout << "b  " << b << std::endl;
        std::cout << "g  " << g << std::endl;
        std::cout << "A  " << A << std::endl;
        std::cout << "B  " << B << std::endl;
        std::cout << "g1 " << g1 << std::endl;
        std::cout << "g2 " << g2 << std::endl;
        abort("Failed");
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "GCD tests completed in "
              << timing << " sec" << std::endl;

#endif // TEST_GCD

#ifdef TEST_ISQRT

// For various inputs I compute isqrt() and verify that the square of
// that value is no greater than my original input, while if I add one
// and square I get something larger.

    maxbits = 900;
    ntries = 50*MILLION;

    std::cout << "Start of isqrt testing" << std::endl;
    clk = clock();

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a, b;
        a = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        a = fudge_distribution_bignum(a, (int)r & 7);
        b = isqrt(a);
        if (square(b) <= a && square(b+1) > a) continue;
        std::cout << "FAILED on test " << i << std::endl;
        std::cout << "a         " << a << std::endl;
        std::cout << "b         " << b << std::endl;
        std::cout << "b^2       " << square(b) << std::endl;
        std::cout << "(b+1)^2   " << square(b+1) << std::endl;
        display("a", a);
        display("b", b);
        std::cout << "Failed " << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Isqrt tests completed in "
              << timing << " sec" << std::endl;

#endif // TEST_ISQRT

#ifdef TEST_FLOAT

// To test FLOAT and FIX I will generate a random integer and convery to
// floating point. I then look at floating point values just larger and
// just smaller than the one that I obtained, and verify that my result
// is closer to the original input than the other wto. If there is a tie
// I will expect my value to have its least significant bit zero.

    maxbits = 500;
    ntries = 50*MILLION;

// On some systems (notable 32-bit cygwin and at least some older
// 32-bit Linux systems running on x86) floating point arithmetic is
// performed in 80-bit working precision, so some of my attempts here
// to check results are thwarted. I cope with that by forcing important
// values through the following volatile variable.
    volatile double fp_forcer;

    std::cout << "Start of float testing" << std::endl;
    clk = clock(); clong = 0;

    for (int i=1; i<=ntries; i++)
    {   if ((i & 0xfffff) == 0)
        {   clock_t now = clock();
            clong += now - clk;
            clk = now;
        }
        Bignum a, b;
        a = random_upto_bits_bignum(maxbits);
        uint64_t r = mersenne_twister();
        a = fudge_distribution_bignum(a, (int)r & 15);

        double d = double_bignum(a);
        Bignum n = fix_bignum(d);
        if (a == n) continue; // round trip was exact!

        fp_forcer = d + 1.0;
        double dplus = fp_forcer;
        if (dplus == d) dplus = std::nextafter(d, 1.0e300);
        assert(dplus != d);
        fp_forcer = d - 1.0;
        double dminus = fp_forcer;
        if (dminus == d) dminus = std::nextafter(d, -1.0e300);
        assert(dminus != d);
        Bignum nplus = fix_bignum(dplus);
        Bignum nminus = fix_bignum(dminus);
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

        std::cout << "FAILED on test " << i << std::endl;
        std::cout << "a       " << a << std::endl;
        std::cout << "d       " << std::setprecision(19) << d << std::endl;
        std::cout << "d-      " << dminus << std::endl;
        std::cout << "d+      " << dplus << std::endl;
        std::cout << "nminus  " << nminus << std::endl;
        std::cout << "n       " << n << std::endl;
        std::cout << "nplus   " << nplus << std::endl;
        std::cout << "err-    " << errminus << std::endl;
        std::cout << "err     " << err << std::endl;
        std::cout << "err+    " << errplus << std::endl;
        display("a", a);
        display("n", n);
        std::cout << "Failed " << std::endl;
        abort();
        return 1;
    }

    timing = (clong + clock() - clk)/(double)CLOCKS_PER_SEC;
    std::cout << "Float tests completed in "
              << timing << " sec" << std::endl;

#endif // TEST_FLOAT

    std::cout << "About to exit" << std::endl;
    return 0;    
}

// end of arithtest.cpp
