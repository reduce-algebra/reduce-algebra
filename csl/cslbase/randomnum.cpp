// randomnum.cpp                              Copyright 2026  Arthur Norman

//=========================================================================
//=========================================================================
// Random number support
//=========================================================================
//=========================================================================

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


// It is useful to be able to generate random values. C++11 is simultaneously
// very helpful and rather unhelpful. The class std::random_device is
// expected to yield genuine unpredictable values, but it is not guaranteed
// to and it fails to on some platforms, so despite the fact that when it
// works it is a really good thing I can not rely solely on it. Each time I
// use a random_device it gives me just 32 bits. For my real generator that
// is not really enough.
// Even worse, in extreme case its use can raise a sts::runtime_exception!
// So here I create 3 notionally unpredictable units and then merge in the
// identity of the current thread and two measurements related to time.
// To avoid thread safety issues with random_device I make calls to it
// global, and then the thread identifier and time of day information stands
// a prospect of arranging that each thread gets its own mersenne-twister
// with its own seeding.
// Note that Wikipedia explains "Multiple instances that differ only in
// seed value (but not other parameters) are not generally appropriate
// for Monte-Carlo simulations that require independent random number
// generators".

// The code here is explicitly aware of the prospect of threading, and
// should lead to different pseudo-random sequences in each thread.

// Note that the thread local status information for a random number
// generator will be initialized in EVERY thread that is created. This
// includes the worker threads for Karatsuba multiplication and in a
// broader context where I use this library it will include threads that
// are used for GUI or other I/O purposes. So there is a benefit if C++
// delays initialization of any of the variables within the following
// function until the function is first used!

#include "arithlib.h"

namespace arithlib_implementation
{

unsigned int system_randomness()
{   std::random_device basic_randomness;
    static unsigned int r = 1234567;
// In pathological cases trying to get data from a random_device can fail
// and raise an error, which I catch here so that I can return a rather
// arbitrary value in that case. I add in basic_randomness() in to r
// so that this function is yet more likely to return different values
// if called several times.
    try
    {   r += basic_randomness();
    }
    catch (const std::exception &e)
    {   r++;
    }
// If the value was properly random  almost anything lossless that I
// do to it can not change that fact. But in case std::random failed
// I merge in the address of what may be a stack allocated and what should
// be a static variable in case address-space-randomisation manages
// to feed some entropy into those.
    r = r ^ (intptr_t)&r ^ 139*(intptr_t)&basic_randomness;
    return r;
}

std::mt19937_64 mersenne_twister(*(([]()->std::seed_seq*
{   unsigned int seed_component_1 = system_randomness();
    unsigned int seed_component_2 = system_randomness();
    unsigned int seed_component_3 = system_randomness();
    Digit threadid =
        static_cast<Digit>(std::hash<std::thread::id>()(
                                       std::this_thread::get_id()));
    Digit time_now =
        static_cast<Digit>
        (std::time(nullptr));
    Digit chrono_now =
        static_cast<Digit>(
            std::chrono::steady_clock::now().
                time_since_epoch().count());
// In my first draft of this library I had made the random seed directly
// from uint64_t values. However when testing on a Raspberry Pi that
// triggered a messages about bugs in gcc before gcc7 (relating to the
// alignment of some values passed as arguments in obscure cases). Building
// the seed sequence using 32-bit values avoids that issue, and since this
// is only done during initialization it is not time-critical.
    static std::seed_seq random_seed
    {   static_cast<std::uint32_t>(threadid),
        static_cast<std::uint32_t>(seed_component_1),
        static_cast<std::uint32_t>(seed_component_2),
        static_cast<std::uint32_t>(seed_component_3),
        static_cast<std::uint32_t>(time_now),
        static_cast<std::uint32_t>(chrono_now),
        static_cast<std::uint32_t>(threadid>>32),
        static_cast<std::uint32_t>(time_now>>32),
        static_cast<std::uint32_t>(chrono_now>>32),
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&seed_component_1)),
        static_cast<std::uint32_t>(
            static_cast<Digit>(
                reinterpret_cast<std::uintptr_t>(&seed_component_1))>>32)
    };
    return &random_seed;
  })()));

// To re-seed I can just call this. I think that when I re-seed it will
// often be to gain repeatable behaviour, and so I am fairly happy about
// limiting the amount of input entropy here to 64-bits.
// However I arrange that a new seed that is zero tries to lead to
// unpredictable and ideally genuine random behaviour.
// Note that this will reseed the random number generator associated with
// the thread it is called from. Specifically there is one generator per
// thread, so if you have multiple threads and you reseed to obtain
// determininistic "random" values you are liable to want to reseed each
// of threads.
//

void reseed(Digit n)
{   if (n == 0)
    {   Digit threadid =
            static_cast<Digit>(
                std::hash<std::thread::id>()(
                    std::this_thread::get_id()));
        Digit seed_component = system_randomness();
        Digit time_now =
            static_cast<Digit>(std::time(nullptr));
        Digit chrono_now =
            static_cast<Digit>(
                std::chrono::steady_clock::now().
                    time_since_epoch().count());
        n = threadid ^ seed_component ^ time_now ^ chrono_now ^
            reinterpret_cast<uint64_t>(&n);
    }
    mersenne_twister.seed(n);
}

// Now a number of functions for setting up random bignums. These may be
// useful for users, but they will also be very useful while testing this
// code.

// Return a random integer in the range 0 ... n-1.
// Given that the largest n that can be passed is UINT64_MAX the biggest
// rangs that can be generated here is 1 less than the full range of 64-bit
// values. To get a full 64-bit range merely call mersenne_twister()
// directly.

Digit uniformUint64(Digit n)
{   if (n <= 1) return 0;
// I I want the remainder operation on the last line of this function to
// return a uniformly distributed result. To ensure that I want r to be
// drawn uniformly from a range that is a multiple of n.
    Digit q = UINT64_MAX/n;
    Digit w = n*q;
    Digit r;
// In the worst case here n was just over UINT64_MAX/2 and q came out
// as 1. In that case on average I will need to call mersenne_twister
// twice. Either larger or smaller inputs will behave better, and rather
// small inputs will mean I hardly ever need to re-try.
    do
    {   r = mersenne_twister();
    }
    while (r >= w);
    return r%n;
}

// A uniform distribution across the range [0 .. (2^bits)-1], ie
// a bignum using (up to) the given number of bits. So eg uniformPositive(3)
// should return 0,1,2,3,4,5,6 or 7 each with equal probability.

void uniformPositive(std::uint64_t* r, std::size_t &lenr,
                            std::size_t bits)
{   if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
    }
    lenr = (bits+63)/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
    if (bits%64 == 0) r[lenr-1] = 0;
    else r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    while (lenr!=1 && shrinkable(r[lenr-1], r[lenr-2])) lenr--;
}

std::intptr_t uniformPositive(std::size_t n)
{   std::size_t lenr = (n + 63)/64;
    if (lenr == 0) lenr = 1; // special case!
    std::size_t save = lenr;
    std::uint64_t* r = reserve(lenr);
    uniformPositive(r, lenr, n);
    return confirmSize(r, save, lenr);
}

// As above but returning a value that may be negative. uniformSigned(3)
// could return -8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6 or 7.
// Note that while uniform_unsigned(0) can only return the value 0,
// uniformSigned(0) can return -1 or 0.

void uniformSigned(std::uint64_t* r, std::size_t &lenr,
                          std::size_t bits)
{   lenr = 1 + bits/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
// Now if the "extra" bit is zero my number will end up positive.
    if ((r[lenr-1] & (UINT64_C(1) << (bits%64))) == 0)
    {   r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (63-bits%64);
        while (lenr!=1 && r[lenr-1] == 0) lenr--;
    }
// Otherwise the result will end up negative.
    else
    {   r[lenr-1] |= UINT64_C(0xffffffffffffffff) << (bits%64);
        while (lenr!=1 && r[lenr-1] == UINT64_C(0xffffffffffffffff)) lenr--;
    }
}

std::intptr_t uniformSigned(std::size_t n)
{   std::size_t lenr = n/64+1;
    std::size_t save = lenr;
    std::uint64_t* r = reserve(lenr);
    uniformSigned(r, lenr, n);
    return confirmSize(r, save, lenr);
}

std::size_t bignumBits(const std::uint64_t* a, std::size_t lena);

// Generate a value in the range 0 .. a-1 using a uniform distribution

void uniformUpto(std::uint64_t* a, std::size_t lena,
                        std::uint64_t* r,
                        std::size_t &lenr)
{   std::size_t n = bignumBits(a, lena);
// I will repeatedly generate numbers that have as many bits as a until
// I get one that has a value less than a has. On average that should only
// take two tries.
    for (;;)
    {   uniformPositive(r, lenr, n);
        if (lena > lenr) return;
        for (std::size_t len=lena;;)
        {   len--;
            if (a[len] > r[len]) return;
            if (a[len] < r[len] || len == 0) break;
        }
    }
}

std::intptr_t uniformUpto(std::intptr_t aa)
{   if (storedAsFixnum(aa))
    {   Digit r = uniformUint64(static_cast<Digit>
                                         (intOfHandle(
                                              aa)));
        return intToHandle(r);
    }
    std::uint64_t* a = vectorOfHandle(aa);
    std::size_t lena = numberSize(a);
    std::uint64_t* r = reserve(lena);
    std::size_t lenr;
    uniformUpto(a, lena, r, lenr);
    return confirmSize(r, lena, lenr);
}

// The following is a rather strange function. It looks at the 4 bit number n.
// It then processes its input a in accordance with the following table, where
// A is the (positive) input value and X is A rounded down to the nearest
// power of 2 less than it (ie keeping just the top bit of A):
//
//    0   X-1                     8   -(X-1)
//    1   X                       9   -X
//    2   X+1                    10   -(X+1)
//    3   A                      11   -A
//    4   A                      12   -A
//    5   A                      13   -A
//    6   A                      14   -A
//    7   A                      15   -A

// The idea behind this is that the input A will be a random value from a
// reasonably smooth distribution, and n will be a random 4 bit value. The
// output will still be random, but now half the time it will be negative.
// And a significant proportion of the time it will be a power of 2 (or one
// either side of being a power of 2). This last is something I want because
// with an internal representation that is based on 2s complement values
// close to powers of 2 can easily be "edge cases" that deserve extra attention
// during testing.

void fudgeDistribution(const std::uint64_t* a,
                              std::size_t lena,
                              std::uint64_t* r, std::size_t &lenr, int n)
{   lenr = lena;
    switch (n&7)
    {   case 0:
        case 1:
        case 2:
            for (std::size_t i=0; i<lena+1; i++) r[i] = 0;
            if (a[lena-1] == 0)
            {   if (lena>1) r[lena-2] = 1ULL<<63;
            }
            else r[lena-1] = 1ULL << (63-CSL_LISP::nlz(a[lena-1]));
            if ((n&7) == 0) // decrement it
            {   if (lena!=1 || a[0]!=0) // avoid decrementing zero.
                {   std::uint64_t* p = r;
                    while (*p == 0)* p++ = static_cast<Digit>(-1);
                    (*p)--;
                }
            }
            else if ((n&7) == 2) // increment it
            {   std::uint64_t* p = r;
                while (*p == static_cast<Digit>(-1))* p++ = 0;
                (*p)++;
            }
            break;
        default:
            for (std::size_t i=0; i<lena; i++) r[i] = a[i];
            break;
    }
    if ((n&8) != 0)
    {   Digit carry = 1;
        for (std::size_t i=0; i<lena+1; i++)
        {   carry = addWithCarry(~r[i], carry, r[i]);
        }
        truncateNegative(r, lenr);
    }
    else truncatePositive(r, lenr);
}

std::intptr_t fudgeDistribution(std::intptr_t aa, int n)
{   std::uint64_t* a;
    std::size_t lena;
    Digit w[2];
    if (storedAsFixnum(aa))
    {   w[1] = static_cast<Digit>(intOfHandle(aa));
        lena = 1;
        a = &w[1];
    }
    else
    {   a = vectorOfHandle(aa);
        lena = numberSize(a);
    }
    std::uint64_t* r = reserve(lena+1);
    std::size_t lenr;
    fudgeDistribution(a, lena, r, lenr, n);
    return confirmSize(r, lena+1, lenr);
}

// Generate a value in the range 0 .. 2^bits-1 using a distribution such
// numbers with each bit-length are equally probable. This works by
// selecting a big-length uniformly and then creating a number uniformly
// distributed across all those with that exact bit-width. This is perhaps
// not a very nice distribution from a mathematical perspective, but is is
// nevertheless a useful one to have in some test code.

void randomUptoBits(std::uint64_t* r, std::size_t &lenr,
                           std::size_t n)
{   std::size_t bits = static_cast<std::size_t>(uniformUint64(n));
    if (bits == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
// The number will have from 1 to 64 bits in its top digit.
    lenr = (bits+63)/64;
    for (std::size_t i=0; i<lenr; i++)
        r[i] = mersenne_twister();
    if (n%64 != 0)
        r[lenr-1] &= UINT64_C(0xffffffffffffffff) >> (64-bits%64);
    r[lenr-1] |= UINT64_C(1) << ((bits-1)%64);
    if (bits%64 == 0) r[lenr++] = 0;
}

std::intptr_t randomUptoBits(std::size_t bits)
{   std::size_t m = 1+bits/64;
    if (m == 0) m = 1;
    std::uint64_t* r = reserve(m);
    std::size_t lenr;
    randomUptoBits(r, lenr, bits);
    return confirmSize(r, m, lenr);
}

}; // end of namespace

// end of randomnum.cpp
