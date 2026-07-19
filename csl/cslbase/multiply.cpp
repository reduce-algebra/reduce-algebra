// multiply.cpp                                   Copyright A C Norman 2926

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

//=========================================================================
//=========================================================================
// multiplication, squaring and exponentiation.
//=========================================================================
//=========================================================================


#include "arithlib.h"

namespace arithlib_implementation
{

// I need some sub-functions that add and subtract N-digit numbers.

// increment the N-digit number x by n.

void increment(std::uint64_t* x, std::size_t N, Digit n=1)
{   if ((x[0] += n) >= n) return;
    for (std::size_t i=1; i<N; i++)
    {   if (++x[i] != 0) return;
    }
}

// z = x + y and return a carry, where x, y and z are N digit numbers.

Digit addWithCarry(const std::uint64_t* x,
                                  const std::uint64_t* y,
                                  std::uint64_t* z, std::size_t N)
{   Digit c = addWithCarry(x[0], y[0], z[0]);
    for (std::size_t i=1; i<N; i++)
        c = addWithCarry(x[i], y[i], c, z[i]);
    return c;
}

// As above except that c is a "carry in".

Digit addWithCarry(const std::uint64_t* x,
                                  const std::uint64_t* y,
                                  Digit c,
                                  std::uint64_t* z, std::size_t N)
{   for (std::size_t i=0; i<N; i++)
        c = addWithCarry(x[i], y[i], c, z[i]);
    return c;
}
// z = x - y and return a borrow.

Digit subtractWithBorrow(const std::uint64_t* x,
                                        const std::uint64_t* y,
                                        std::uint64_t* z, std::size_t N)
{   Digit b = subtractWithBorrow(x[0], y[0], z[0]);
    for (std::size_t i=1; i<N; i++)
        b = subtractWithBorrow(x[i], y[i], b, z[i]);
    return b;
}


// integers.

// Overall plan:
//    (1) Cases from 1x1 to 7x7 are dealt with using special code
//        in the hope that those small cases can be handled really
//        fast. I unroll and inline everything. Also cases of Nx1 to
//        Nx7 have their inner x1 to x7 loops unrolled.
//    (2) min(N,M)<=threshold. Use simple long multiplication because
//        anything like Karatsuba will not pay off.
//    (3) N>1.5*M or M>1.5*N and the smaller is >7. Do a sequence of
//        MxM multiplications until the residual N is small enough
//        that a different case applies.
//    (5) If N,M and less than another threshold do Karatsuba.
//    (6) Use 3-thread Karatsuba or 4-thread Toom32.
//    (7) FFT-based scheme.

// So here is a more detailed commentary talking about the thresholds in
// the treatment of large cases in extra detail.
//
// Suppose I am multiplying an N digit number by an M digit one with N>=M.
// I can go classical which is straightforward and for small cases that is
// good. But for the rest there are two other base schemes:
//
// I can go Karatsuba. That will use sub-digits of size D=ceiling(N/2) and
// will demand that M>D at least since otherwise the high sub-digit of M
// will be zero and by then use of Karatsuba is surely silly.
// The calculation forms two products on D*D and one on (N-D)*(M-D). If
// things start off even slightly unbalanced this last one is more so and
// so eventually you should not use Karatsuba for it even N it is big.
// But for reasonably balanced cases it is good. My estimates are that
// I should use it up as far as N=1.25*M.
//
// Then I have Toom32 that multiplies a 3-digit number by a 2 digit one via
// evaluation at 0, +1, -1 and infinity. The sub-digit size D must be
// max((N+2)/3, (M+1)/2) to keep top sub-digits both in existence. So
// the cost is then three products D*D and one of (N-2D)*(M-D).
// That final product may be noticably out of balance if N is not very close
// to 1.5M and I will discuss that later, it being a close relative of the
// similar situation that arises in Karatsuba.
//
// So given arbitrary N,M where they are not the same value but are tolerably
// close do I use Karatsuba or Toom32? And what do I do when N and M are
// more widely different?
//
// My plan for a ramge of values of alpha=N/M (where wlog N>=M) will be
//    1 <= alpha < 1.25      Karatsuba. 1 is the best case here
//    1.25 <= alpha < 1.85    Toom32 where 1.5 is the best case
//
// So now I need to consider alpha >= 1.85.
// I will split off the low 3M/2 digits and use Toom32 to form that
/// part of the result - I am then left with the case (N-3M/2)*M. That
// can be continued until N<3M/2, which I will write as alpha<1.5.
// If alpha > 1.25 I will use a sub-optimal Toom32. For 0.85<alpha<1.25
// I will use Karatsuba (with reversed arguments in the alpha<1 case).
// Then if akpha > 0.54 (=1/1.85) I will use Toom32 with reversed arguments.
// So we are left with alpha<0.54, otherwise M>1.85*N. I reverse the
// arguments and continue until the I drop down to use of classical
// methods. 
//
// In all this there is an issue of workspace allocation. And a top-level
// use of either Toom32 or Karatsuba needs extra space because the recursive
// calls that are made run concurrently so each need separate space.
// But for all the recursive calls things are nicer and I can use and
// re-use space.
// I have made several attempts to chart how much will be used but the
// interaction between levels of call and the fact that when I "halve" the
// size of a number there has to be rounding when that number is of odd
// length make that messy enough that anything I come up with using
// calculation will not be a sharp bound and will be very fragile against
// small changes in the code.

#include <atomic>

// I am trying to round lengths up to multiples of 16 to gete my data
// really well aligned...

static constexpr std::size_t workspaceSize(std::size_t M)
{   return (6*M+15)&(-16);
}

// At the top level toom32<true>() can use a little over 7*L workspace for
// itself, where L=max(N/3,M/2). But N<=1.85*M and M is large enough that
// I will ignore rounding. Then plus the need for four parallel
// sub-multiplications. I will use a rounded up 2M/3 as my bound on L.

static constexpr std::size_t topWorkspaceSize(std::size_t M)
{   size_t toomLen = ((2*M+2)/3 + 15)&(-16);
    return 7*toomLen + 4*workspaceSize(toomLen);
}

// Unless I make this thread local the code as a whole is not thread safe.
// However if I were to make it thread local I would be liable to end up
// with (unused) versions of it associated with all worker threads and
// possibly all GUI threads etc in a way that would be really clumsy.
// So if I ever move to making this thread local I will have the repeated
// object a mere pointer to the workspace and arrange that when user-level
// threads that may need it are created that they allocate the memory
// that is required.

static thread_local Digit* TLworkspace = nullptr;

class MultiplicationTask
{
public:
    ConstDigitPtr a;
    size_t lena;
    ConstDigitPtr b;
    size_t lenb;
    DigitPtr c;
    DigitPtr ws;
    MultiplicationTask()
    {}
    MultiplicationTask(ConstDigitPtr a, size_t lena,
             ConstDigitPtr b, size_t lenb,
             DigitPtr c, DigitPtr ws)
    {   this->a = a;
        this->lena = lena;
        this->b = b;
        this->lenb = lenb;
        this->c = c;
        this->ws = ws;
    }
};

class BigMultiplication
{

public:

// verySimpleMul exists ONLY for testing - specifically to generate
// reference products that the output from other more complicated code
// can be compared against.

static void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   Digit carry = 0, lo = 0, hi = 0;
    for (std::size_t k=0; k<N+M-1; k++)
    {   for (std::size_t i=0; i<N; i++)
        {   if (k < i) continue;
            if (k-i >= M) continue;
            Digit hi1;
            multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    result[N+M-1] = lo;
}

// I have a general idiom I intend to use for loops where the
// body of the iteration is small. If one has
//     for (i=A; i<B; i++) { X(i); }
// I will unroll the loop, writing
//     for (i=A; i<B-1; i+=2)
//     {   X(i);
//         X(i+1);
//     }
//     if (i<B) { X(i); i++; }
// This adds to the cost if the loop is traversed only once, is broadly
// cost neutral if it is traversed twice and from there up it saves tests
// and control-flow. Of course it increases code bulk. 

// Here I have classical multiplication for the case N>=M and as
// used here M>7. This is written out as succession of 3 loops since
// that leads to each having simpler start and end conditions, and I
// hope that reduces overhead.

static void simpleMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// For this I will require N>=M
    Digit carry = 0, lo, hi = 0, hi1;
// The lowest Digit can be handled specially to get things going.
    multiply64(a[0], b[0], lo, result[0]);
    std::size_t k=1;
    for (; k<M; k++)
    {   std::size_t i;
// Here I want k<M<=N so certainly if i<k then i<N
//@@ The code shown with "//@@" here is the simple presentation of this
//@@ loop, but the actual code unrolls the loop so that two steps are
//@@ taken in each iteration (and potentially a final one is needed at
//@@ the end. This is done to reduce loop overhead. Possibly clever compilers
//@@ would do that for me anyway?
//@@    for (i=0; i<=k; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        for (i=0; i<=k-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<=k)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Now k>=M, I want i<=k to imply i<N so go as far as k<N
    for (; k<N; k++)
    {
//@@    for (std::size_t j=0; j<M; j++)
//@@    {
//@@ // Ha ha in this loop I iterate on j=k-i which makes the loop
//@@ // just a little nicer to express.
//@@        multiply64(a[k-j], b[j], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t j;
        for (j=0; j<M-1; j+=2)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[k-j-1], b[j+1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (j<M)
        {   multiply64(a[k-j], b[j], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// Finally k>=N so i<N will imply i<=k
    for (; k<N+M-1; k++)
    {
//@@    for (std::size_t i=k+1-M; i<N; i++)
//@@    {   multiply64(a[i], b[k-i], lo, hi1, lo);
//@@        carry += addWithCarry(hi, hi1, hi);
//@@    }
        std::size_t i;
        for (i=k+1-M; i<N-1; i+=2)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
            multiply64(a[i+1], b[k-i-1], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        if (i<N)
        {   multiply64(a[i], b[k-i], lo, hi1, lo);
            carry += addWithCarry(hi, hi1, hi);
        }
        result[k] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
// The very final digit of the result drops out here.
    result[k] = lo;
}

private:

// inline1.cpp is a generated file that provides multiplication of
// various fairly small bignums in the form of straight-line code.
// The idea is that multiplication of rather small bignums will be
// especially common and also particularly liable to be sensitive to
// overheads of various sorts. If it is rendered as straight-line code
// that perhaps gives an optimising compiler the best possible chance to
// do a good job with it.

#include "inlinemul.cpp"


// The vector a has M digits and result has N (with N>=M). Add the
// value in a into result and return any carry.

static Digit addMdigits(ConstDigitPtr a, std::size_t M, DigitPtr result, std::size_t N)
{   Digit carry = addWithCarry(a[0], result[0], result[0]);
    std::size_t i=1;
//@@for (; i<M; i++)
//@@    carry = addWithCarry(a[i], result[i], carry, result[i]);
    for (; i<M-1; i+=2)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        carry = addWithCarry(a[i+1], result[i+1], carry, result[i+1]);
    }
    if (i<M)
    {   carry = addWithCarry(a[i], result[i], carry, result[i]);
        i++;
    }
    while (carry != 0 && i<N)
    {   carry = addWithCarry(result[i], 1, result[i]);
        i++;
    }
    return carry;
}

// result = a + b with a carry-in

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     Digit carry,
                     DigitPtr result)
{   std::size_t i;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    for (i=0; i<lenB-1; i+=2)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        carry = addWithCarry(a[i+1], b[i+1], carry, result[i+1]);
    }
    if (i<lenB)
    {   carry = addWithCarry(a[i], b[i], carry, result[i]);
        i++;
    }
    while (i<lenA && i<0x100000000)
    {   carry = addWithCarry(a[i], carry, result[i]);
        i++;
    }
    return carry;
}

// result = a + b

[[gnu::always_inline]]
static Digit karaAdd(ConstDigitPtr a, std::size_t lenA,
                     ConstDigitPtr b, std::size_t lenB,
                     DigitPtr result)
{   return karaAdd(a, lenA, b, lenB, 0, result);
}

// result = a - b

[[gnu::always_inline]]
static Digit karaSubtract(ConstDigitPtr a, std::size_t lenA,
                          ConstDigitPtr b, std::size_t lenB,
                          DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        borrow = subtractWithBorrow(a[i+1], b[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(a[i], b[i], borrow, result[i]);
        i++;
    }
    while (i<lenA && i < 0x100000000)
    {   borrow = subtractWithBorrow(a[i], 0, borrow, result[i]);
        i++;
    }
    return borrow;
}

// result = b - a;

[[gnu::always_inline]]
static Digit karaRevSubtract(ConstDigitPtr a, std::size_t lenA,
                             ConstDigitPtr b, std::size_t lenB,
                             DigitPtr result)
{   Digit borrow = 0;
#ifdef DEBUG
    assert(lenA >= lenB);
#endif
    std::size_t i;
    for (i=0; i<lenB-1; i+=2)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        borrow = subtractWithBorrow(b[i+1], a[i+1], borrow, result[i+1]);
    }
    if (i<lenB)
    {   borrow = subtractWithBorrow(b[i], a[i], borrow, result[i]);
        i++;
    }
// The extra check "i<0x10000000" is to avoid triggering a warninng about
// undefined behaviour that certain versions of g++ generate and that
// while probably spurious they are most alarming. The same hack is
// applied in two further places...
    while (i<lenA && i<0x10000000)
    {   borrow = subtractWithBorrow(0, a[i], borrow, result[i]);
        i++;
    }
    return borrow;
}

// Replace a and b with a-b and a+b.

[[gnu::always_inline]]
static void karaDifferenceAndSum(DigitPtr a, DigitPtr b,
                                 std::size_t len,
                                 Digit& carry,
                                 Digit& borrow)
{   carry = borrow = 0;
    for (std::size_t i=0; i<len; i++)
    {   Digit aa = a[i], bb = b[i];
        borrow = subtractWithBorrow(aa, bb, borrow, a[i]);
        carry = addWithCarry(aa, bb, carry, b[i]);
    }
}

// Propogate a carry.

[[gnu::always_inline]]
static void karaCarry(Digit carry, DigitPtr v)
{   size_t i = 0;
    while (carry != 0)
    {   carry = addWithCarry(v[i], carry, v[i]);
        i++;
    }
}

// Propogate a borrow.

[[gnu::always_inline]]
static void karaBorrow(Digit borrow, DigitPtr v)
{   size_t i = 0;
    while (borrow != 0)
    {   borrow = subtractWithBorrow(v[i], borrow, v[i]);
        i++;
    }
}

// This divides a value by 2, where the value has a signed top digit
// and a vector of unsigned additional digits.

static SignedDigit karaHalve(SignedDigit top, DigitPtr a, std::size_t len)
{   Digit carry = top & 1;
    top = top - carry;
    for (size_t i=len-1; i!=0; i--)
    {   Digit w = a[i];
        a[i] = (w>>1) | (carry<<63);
        carry = w & 1;
    }
    a[0] = (a[0]>>1) | (carry<<63);
    return top/2;
}

[[gnu::always_inline]]
static void differenceLengthsMatch(ConstDigitPtr low, std::size_t length,
                                   ConstDigitPtr high, DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
//@@for (std::size_t i=1; i<length; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    std::size_t i;
    for (i=1; i<length-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<length)
        borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
}

[[gnu::always_inline]]
static bool differenceLengthsDiffer(ConstDigitPtr low, std::size_t lenLow,
                                    ConstDigitPtr high, std::size_t lenHigh,
                                    DigitPtr result)
{   Digit borrow = subtractWithBorrow(low[0], high[0], result[0]);
    std::size_t i=1;
//@@for (; i<lenHigh; i++)
//@@    borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
    for (; i<lenHigh-1; i+=2)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        borrow = subtractWithBorrow(low[i+1], high[i+1], borrow, result[i+1]);
    }
    if (i<lenHigh)
    {   borrow = subtractWithBorrow(low[i], high[i], borrow, result[i]);
        i++;
    }
// I will not unwind this loop because I expect that lenHigh will usually
// be very close to lenLow so there will be little to save.
    for (; i<lenLow; i++)
        borrow = subtractWithBorrow(low[i], borrow, result[i]);
    if (borrow == 0) return false;
// If necessary negate the result. This case arises if low has at least one
// zero leading digit and is less that high in magnitide.
    borrow = 0;
    for (i=0; i<lenLow; i++)
        borrow = subtractWithBorrow(0, result[i], borrow, result[i]);
    return true;
}

// set result = |low-high| and return true if high>low.
// A special feature here is that the "low" values here can have
// leading zeros - for instance consider the partitioned form of
// the number 1234_5678:0000_0234_5678 where I have used ":" to mark
// where the whole number is split into high and low parts. The high
// part has 2 digits and the low has 3, however the low part has the
// smaller value. So in that case the correct absolute value of
// the differenfce will be 0000_1000_0000

[[gnu::always_inline]]
static bool absDifference(ConstDigitPtr low, std::size_t lenLow,
                          ConstDigitPtr high, std::size_t lenHigh,
                          DigitPtr result)
{   if (lenHigh != lenLow)
        return differenceLengthsDiffer(low, lenLow, high, lenHigh, result);
// Here the two numbers both have the same number of digits. I need to
// work out which is the larger. Usually I will only need to look at
// the top digit. On that basis I make the code capable of scanning all
// the way down the number.
// An alternative stretegy would be do compute (low-high) always, detect
// a borrow at the end (ie that the difference was negative) and in that
// case negate the answer. That might do a full linear-cost negation about
// half the time where what I do here frequently only tests one digit.
    std::size_t i = lenLow-1; 
    for (;;)
    {   if (high[i] < low[i])
        {   differenceLengthsMatch(low, lenLow, high, result);
            return false;
        }
        else if (high[i] > low[i])
        {   differenceLengthsMatch(high, lenLow, low, result);
            return true;
        }
        if (i == 0)   // Here the two numbers are equal.
        {   std::memset(result, 0, lenLow*sizeof(Digit));
            return false;
        }
        i--;
    }
}

//=========================================================================

// Some of the functions here have are templated with a boolean
// called "thread". When this is true the code is entitled to cause
// worker threads to be launched to perform subsidiary multiplications.
// The multi-thread decomposition may only happen once, and that is enforced
// by making thread=false for all the lower level calls.

// Now the main entrypoint to my new code for multiplying
// unsigned values. It tries to put simple cheap tests to spot
// cheap cases inline and then dispatch to the separate procedures
// that apply in each case.
//
// I make this function "always-inline" and what it expands to is
// really just
//     check for 1*1
//     check for up to 7*7
//     get args in correct order and check for 7*N
//     check for cases where Karatsuba will not be needed
//         special on N*N up to 14*14
//         OR general case of classical numtiplication
//     go to general harder case
// where each of the above is a fairly simple test on the
// size of the inputs and in each case the behaviour triggered is
// to call a function that is not tagged as always-inline.

public:

[[gnu::always_inline]]
static void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{
// I take a view that case of single word multiplication as both so
// special and so important that I do that in-line here.
    if ((N|M) == 1)
    {   multiply64(a[0], b[0], 0, result[1], result[0]);
        return;
    }
// I next have special treatment for all the cases where both M and N are
// at most 7. I make the cut off there because I can test if either N
// or M exceeds the bound using a bitwide OR here which I expect to be
// nice and cheap! Also because I expect small cases like this to be
// especially commonly used, and to be ones where loop overheads might
// intrude.
    if ((N|M) <= 7)
    {   LIKELY
        smallCaseMul(a, N, b, M, result);
        return;
    }
    if (N < M)
    {   std::swap(a, b);
        std::swap(N, M);
    }
// If the smaller number is fairly small I again use classical long
// multiplication, but with the inner loop unrolled.
    if (M <= 7)
    {   bigBySmallMul(a, N, b, M, result);
        return;
    }
    if (M < KARASTART)    // Too small for Karatsuba.
    {   if (N==M) balancedMul(a, b, N, result);
        else simpleMul(a, N, b, M, result);
    }
    else biggerMul(a, N, b, M, result);
}

static void biggerMul(ConstDigitPtr a, std::size_t N,
                      ConstDigitPtr b, std::size_t M,
                      DigitPtr result)
{
// Look at out-of balance cases. Here I take the view that if N>1.5M
// I will hive off toom32 multiplications as much as I can. They will each
// be (3*M)/2 by M and I need M space to keep some digits already computed
// that I will need to combine with the output from the next square multiply.
#ifdef TRACE_TIMES
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
// The variable TLworkspace starts off with a null pointer, but the first
// time I do a biggerMul() in a thread that thread is given a vector
// of digits big enough for it and any sunsequent use there. On all but the
// first big multiplication this costs just one read from a thread local
// variable, which is about as modest an overhead as I can imagine.
    Digit* workspace = TLworkspace;
    if (workspace == nullptr)
        TLworkspace = workspace = new Digit[topWorkspaceSize(FFT_THRESHOLD)];
    if (4*N <= 5*M)
    {   if (N < KARABIG) kara(a, N, b, M, result, workspace);
        else kara<true>(a, N, b, M, result, workspace);
    }
    else if (20*N <= 37*M)
    {   if (N < KARABIG) toom32(a, N, b, M, result, workspace);
        else toom32<true>(a, N, b, M, result, workspace);
#ifdef TRACE_TIMES
        display("toom32res", result, N+M);
#endif // TRACE_TIMES
    }
    else 
    {   innerGeneralMul<true>(a, N, b, M, result, workspace);
#ifdef TRACE_TIMES
        display("unbalancedres", result, N+M);
#endif // TRACE_TIMES
    }
}

private:

// When thread is false this is being used when Kara or Toom32
// recurses and so most of the time we will have M==N>KARASTART/2. With
// thread true it is from the top-level and may fire up some workers.

template <bool thread=false>
static void innerGeneralMul(ConstDigitPtr a, std::size_t N,
                            ConstDigitPtr b, std::size_t M,
                            DigitPtr result,
                            DigitPtr workspace)
{
#ifdef TRACE_TIMES
    displayIndent += 2;
    display("innergenerala", a, N);
    display("innergeneralb", b, M);
    displayIndent -= 2;
#endif // TRACE_TIMES
    if constexpr (!thread)
    {   if ((N|M) <= 7)
        {   smallCaseMul(a, N, b, M, result);
            return;
        }
        if (N < M)
        {   std::swap(a, b);
            std::swap(N, M);
        }
        if (M <= 7)
        {   bigBySmallMul(a, N, b, M, result);
            return;
        }
        if (M < KARASTART)    // Too small for Karatsuba.
        {   if (N==M) balancedMul(a, b, N, result);
            else simpleMul(a, N, b, M, result);
            return;
        }
    }
#ifdef TRACE_TIMES
    displayIndent += 2;
    display("a", a, N);
    display("b", b, M);
#endif // TRACE_TIMES
// Here I will call Kara if N <= 1.25*M.
    if (4*N <= 5*M)
    {   if (N > FFT_THRESHOLD) fftmul(a, N, b, M, result);
        else kara<thread>(a, N, b, M, result, workspace);
    }
// If N <= 1.85*M I will use toom32.
    else if (20*N <= 37*M)
    {   if (N > FFT_THRESHOLD) fftmul(a, N, b, M, result);
        else toom32<thread>(a, N, b, M, result, workspace);
    }
// If M and N are significantly different I will split the product
// into two or more components, all better balanced.
    else innerBigMul<thread>(a, N, b, M, result, workspace);
    displayIndent -= 2;
}

// This version is just for N*N products - a case which arises in recursive
// calls from Karatsuba and Toom32. These are never top level!

static void innerGeneralMul(ConstDigitPtr a, std::size_t N,
                            ConstDigitPtr b,
                            DigitPtr result,
                            DigitPtr workspace)
{   if (N < KARASTART) balancedMul(a, b, N, result);
    else kara(a, N, b, N, result, workspace);
}

template <bool thread=false>
static void innerBigMul(ConstDigitPtr a, std::size_t N,
                        ConstDigitPtr b, std::size_t M,
                        DigitPtr result,
                        DigitPtr workspace)
{
#ifdef TRACE_TIMES
    display2("% innerBigMul", N, M);
    DigitPtr fullResult = result;
    size_t fullSize = M+N;
#endif // TRACE_TIMES
    DigitPtr save = setSize(workspace, M);
    workspace += M;
    size_t step = (3*M)/2;
#ifdef TRACE_TIMES
    display2("innerBig starting toom of", step, M);
#endif // TRACE_TIMES
    toom32<thread>(a, step, b, M, result, workspace);
#ifdef TRACE_TIMES
    display("firsttoom32res", result, step+M);
#endif // TRACE_TIMES
    a += step;
    N -= step;
    result += step;
#ifdef TRACE_TIMES
    display("topoftoom32res", result, M);
#endif // TRACE_TIMES
    for (;;)
    {   while (N >= step)
        {   std::memcpy(save, result, M*sizeof(Digit));
#ifdef TRACE_TIMES
            display("save", save, M);
            display2("% Another ", step, M);
#endif // TRACE_TIMES
            toom32<thread>(a, step, b, M, result, workspace);
            addMdigits(save, M, result, step+M);
#ifdef TRACE_TIMES
            display("partial", result, step+M);
#endif // TRACE_TIMES
            a += step;
            N -= step;
            result += step;
        }
        if (N == 0) return;
// Here N < 1.5*M. If N>=M I can finish the job using a single step that
// is either Toom32 or Karatsuba. And I should also take this case
// if N<KARASTART. Also if N>=M/1.25 I can finish with Karatsuba. This
// set of end conditions is more complicated than I had originally thought!
#ifdef TRACE_TIMES
        display2("% End bit ", N, M);
#endif // TRACE_TIMES
        std::memcpy(save, result, M*sizeof(Digit));
#ifdef TRACE_TIMES
        display("save", save, M);
#endif // TRACE_TIMES
        if (4*N > 5*M) toom32<thread>(a, N, b, M, result, workspace);
        else if (N >= M) kara<thread>(a, N, b, M, result, workspace);
// Now N < M so I need to flip order for the calls...
        else if (N < KARASTART) simpleMul(b, M, a, N, result);
        else if (5*N >= 4*M) kara<thread>(b, M, a, N, result, workspace);
// Should I worry about the potential recursion depth here?
// I will consider how the product M*N decreases rather than how either
// separately changes. One limiting case is if a single Karatsuba has
// been done so far. Then what remains must have N>M/2 because otherwise
// a Toom32 step would have been taken. The result is that M*N is reduced
// to less than 1/3 of its initial value. Now suppose that the first step
// had been toom32 and what is left is not enough for a Karatsuba. We have
// less then M*M left where initially there was (5/2)*M*M so we have at
// worst 2/5 of the original size: this case is worse than the one that
// started with Karatsuba. In each situation the fact that I will be willing
// to perform a final Karatsuba even if its slightly unbalanced makes
// this analysis conservative. Furthermore if at one step I approach the
// limit that I identify here it means that the next step is "almost square"
// and the next one can not be as bad! So analyzing a worst case through
// layers of recursion seems hard. So instead I ran code that tried
// comprehensive ranges of M and N and that showed that for large inputs the
// worst depth observed was 1.5*log2(min(N,M)) for cases where M and N
// would possibly reach here.
        else innerGeneralMul<thread>(b, M, a, N, result, workspace);
#ifdef TRACE_TIMES
        display("addin", result, N+M);
#endif // TRACE_TIMES
        addMdigits(save, M, result, N+M);
#ifdef TRACE_TIMES
        display("resulthere", result, N+M);
        display("full result", fullResult, fullSize);
        display("innerBigMul done");
#endif // TRACE_TIMES
        return;
    }
}

// I have code for multiplying N*M numbers when N is about
// 1.5 times M. This splits the big number into 3 chunks and the
// smaller into two.
//
// Here is a description of the procedure in a somewhat readable compact form.
//
// a := ahigh*x^2 + amid*x + alow;
// b :=            bhigh*x + blow;      
//
// x^3 * (ahigh*bhigh) +
// x^2 * (ahigh*blow + amid*bhigh) +
// x   * (alow*bhigh + amid*blow) +
//       (alow*blow)
//
// asum := ahigh+amid+alow;    preserve carry
// bsum := bhigh+blow;         preserve carry
// adiff := ahigh-amid+alow;   preserve carry or borrow
// bdiff := blow-bhigh;        preserve borrow
// d0 := alow*blow;
// d1 := asum*bsum;            adjust for carries, borrows in asum, bsum,
// d2 := adiff*bdiff;          adiff, bdiff and generate carries or borrows.
// d3 := ahigh*bhigh;
//
// d0                                alow*blow
// (d1,d2) = (d1-d2,d1+d2)           record carries
// d1 := d1/2 - p3;                  alow*bhigh + amid*blow   record carry etc
// d2 := d2/2 - p0;                  ahigh*blow + amid*bhigh  record carry etc
// d3                                ahigh*bhigh
//
// merge d1, d2 in accounting for how they overlap each other and d0, d3.

static void useMultiplicationTask(MultiplicationTask d)
{   innerGeneralMul(d.a, d.lena, d.b, d.lenb, d.c, d.ws);
}

template <bool thread=false>
static void toom32(ConstDigitPtr a, std::size_t N,
                   ConstDigitPtr b, std::size_t M,
                   DigitPtr res,
                   DigitPtr workspace)
{
// I will start by viewing a as (ahigh, amid, alow) and b as (bhigh, blow)
// where amid, alow, blow all have the same size (toomLen). Then
// ahigh and bhigh need to have at least some digits but may not have more
// then toomLen.
// I let a(t) = ahigh*t^2 + amid*t + alow and b(t) = bhigh*t + blow.
// then I evaluate a() and b() at 0, +1, -1 and infinity - then I can
// interpolate through products of those values to get digits for my result.
// A classical 3x2 multiplication would use 6 partial products - this uses
// just 4 but obviously a bunch of extra additions and subtractions together
// with some general overhead. 
    size_t toomLen = std::max((N+2)/3, (M+1)/2);
#ifdef DEBUG
    assert(3*toomLen >= N && N > 2*toomLen);
    assert(2*toomLen >= M && M > toomLen);
    assert(N > 2*toomLen);
#endif // DEBUG
    size_t aHighLen = N-2*toomLen;
    size_t bHighLen = M-toomLen;
#ifdef DEBUG
    assert(aHighLen <= toomLen);
#endif // DEBUG
#ifdef TRACE_TIMES
    if constexpr (thread)
        display2("start parallel toom32", N, M);
    else display2("start toom32", N, M);
    display2("toomlen, aHighen", toomLen, aHighLen);
    display2("toomlen, bHighen", toomLen, bHighLen);
    display("tooma", a, N);
    display("toomb", b, M);
//@ display("ahigh", a+2*toomLen, aHighLen);
//@ display("amid",  a+toomLen,   toomLen);
//@ display("alow",  a,           toomLen);
//@ display("bhigh", b+toomLen,   bHighLen);
//@ display("blow",  b,           toomLen);
#endif // TRACE_TIMES
    ConstDigitPtr aLow = a;
    ConstDigitPtr aMid = a + toomLen;
    ConstDigitPtr aHigh = aMid + toomLen;
    ConstDigitPtr bLow = b;
    ConstDigitPtr bHigh = b + toomLen;

    DigitPtr aSum, aDiff, bSum, bDiff, D0, D1, D2, D3;
    Digit aSumTop, bSumTop;
    SignedDigit aDiffTop, bDiffTop, D1Top, D2Top;
    if constexpr (thread)
    {   aSum = setSize(workspace+4*toomLen, toomLen);
        aDiff = setSize(workspace+5*toomLen, toomLen);
        bSum = setSize(workspace+6*toomLen, toomLen);
        bDiff = setSize(res+2*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 7*toomLen, 4*workspaceSize(toomLen));
    }
    else
    {   aSum = setSize(res, toomLen);
        aDiff = setSize(res+toomLen, toomLen);
        bSum = setSize(res+2*toomLen, toomLen);
        bDiff = setSize(res+3*toomLen, toomLen);
        D0 = setSize(res, 2*toomLen);
        D1 = setSize(workspace, 2*toomLen);
        D2 = setSize(workspace + 2*toomLen, 2*toomLen);
        D3 = setSize(res + 3*toomLen, N+M-3*toomLen);
        workspace = setSize(workspace + 4*toomLen, workspaceSize(toomLen));
    }
    aSumTop = karaAdd(aLow, toomLen, aHigh, aHighLen, aSum);
    aDiffTop = aSumTop - karaSubtract(aSum, toomLen, aMid, toomLen, aDiff);
    aSumTop += karaAdd(aMid, toomLen, aSum, toomLen, aSum);
    bSumTop = karaAdd(bLow, toomLen, bHigh, bHighLen, bSum);
    bDiffTop = -karaSubtract(bLow, toomLen, bHigh, bHighLen, bDiff);
#ifdef TRACE_TIMES
//@ display("asum", aSumTop, aSum, toomLen);
//@ display("adiff", aDiffTop, aDiff, toomLen);
//@ display("bsum", bSumTop, bSum, toomLen);
//@ display("bdiff", bDiffTop, bDiff, toomLen);
#endif // TRACE_TIMES
    if constexpr (thread)
    {   std::size_t wsize = workspaceSize(toomLen);
        std::vector<MultiplicationTask> subtasks =
        {   MultiplicationTask(aLow, toomLen, bLow, toomLen,
                     D0, workspace),
            MultiplicationTask(aHigh, aHighLen, bHigh, bHighLen,
                     D3, workspace+3*wsize),
            MultiplicationTask(aSum, toomLen, bSum, toomLen,
                     D1, workspace+wsize),
            MultiplicationTask(aDiff, toomLen, bDiff, toomLen,
                     D2, workspace+2*wsize)
        };
        runInThreads(subtasks, useMultiplicationTask);
#ifdef CHECK_TIMES
// Here I will repeat each of the thread-run multiplications to check them.
        stkvector<Digit> TD0(2*toomLen);
        stkvector<Digit> TD1(2*toomLen);
        stkvector<Digit> TD2(2*toomLen);
        stkvector<Digit> TD3(2*toomLen);
        simpleMul(aLow, toomLen, bLow, toomLen, TD0);
        simpleMul(aSum, toomLen, bSum, toomLen, TD1);
        simpleMul(aDiff, toomLen, bDiff, toomLen, TD2);
        simpleMul(aHigh, aHighLen, bHigh, bHighLen, TD3);
        int errcount = 0;
        for (size_t i=0; i<2*toomLen;i++)
        {   if (D0[i] != TD0[i])
            {   if (errcount < 5) std::printf("lowprod digit %d\n", (int)i);
                errcount++;
            }
            if (D1[i] != TD1[i])
            {   if (errcount < 5) std::printf("D1 digit %d\n", (int)i);
                errcount++;
            }
            if (D2[i] != TD2[i])
            {   if (errcount < 5) std::printf("D2 digit %d\n", (int)i);
                errcount++;
            }
            if (i < aHighLen+bHighLen && D3[i] != TD3[i])
            {   if (errcount < 5) std::printf("highprod digit %d\n", (int)i);
                errcount++;
            }
        }
        if (errcount != 0)
        {   std::printf("\n%%%%@@@ %d FAILURES\n", errcount);
            display("a", a, N);
            display("b", b, M);
            display("alow", a, toomLen);
            display("amid", aMid, toomLen);
            display("ahigh", aHigh, aHighLen);
            display("asum", aSum, toomLen);
            display("adiff", aDiff, toomLen);
            display("blow", b, toomLen);
            display("bhigh", bHigh, bHighLen);
            display("bsum", bSum, toomLen);
            display("bdiff", bDiff, toomLen);
            display("D0", D0, 2*toomLen);
            display("D1", D1, 2*toomLen);
            display("D2", D2, 2*toomLen);
            display("D3",  D3, aHighLen+bHighLen);
            display("TD0", TD0, 2*toomLen);
            display("TD1", TD1, 2*toomLen);
            display("TD2", TD2, 2*toomLen);
            display("TD3", TD3, aHighLen+bHighLen);
// Copy the "slow" data in place of the bad "fast" stuff.
            std::memcpy(D0, TD0, 2*toomLen*sizeof(D0[0]));
            std::memcpy(D1, TD1, 2*toomLen*sizeof(D1[0]));
            std::memcpy(D2, TD2, 2*toomLen*sizeof(D2[0]));
            std::memcpy(D3, TD3, (aHighLen+bHighLen)*sizeof(D3[0]));
//@@@       std::abort();
        }
#endif // CHECK_TIMES
    }
    else
    {   innerGeneralMul(aSum, toomLen, bSum, D1, workspace);
//      + aSumTop*bSum + bSumTop*aSum + aSumTop*bSumTop
        innerGeneralMul(aDiff, toomLen, bDiff, D2, workspace);
//      + aDiffTop*bDiff + bDiffTop*aDiff + aDiffTop*bDiffTop
// noting that aDiffTop and bDiffTop are signed values.
    }
#ifdef TRACE_TIMES
//@ display("sumprod", D1, 2*toomLen);
//@ display("diffprod", D2, 2*toomLen);
#endif // TRACE_TIMES
    D1Top = 0;
    switch (aSumTop)
    {   case 2:
            D1Top = karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            [[fallthrough]];
        case 1:
            D1Top += karaAdd(bSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
            break;
        case 0:
            break;
    }
    if (bSumTop != 0)
        D1Top += karaAdd(aSum, toomLen, D1+toomLen, toomLen, D1+toomLen);
    D1Top += aSumTop*bSumTop;   
    D2Top = 0;
    switch (aDiffTop)
    {   case 1:
            D2Top = karaAdd(bDiff, toomLen, D2+toomLen, toomLen, D2+toomLen);
            break;
        case -1:
            D2Top = -karaSubtract(D2+toomLen, toomLen,
                                  bDiff, toomLen, D2+toomLen);
            break;
        case 0:
            break;
    }        
    switch (bDiffTop)
    {   case -1:
            D2Top -= karaSubtract(D2+toomLen, toomLen,
                                  aDiff, toomLen, D2+toomLen);
        break;
    }
    D2Top += aDiffTop*bDiffTop;   
#ifdef TRACE_TIMES
//@ display("sumprod1", D1Top, D1, 2*toomLen);
//@ display("diffprod1", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
// Now set D1 = D1-D2, D2=D1+D2
    Digit carry, borrow;
    karaDifferenceAndSum(D1, D2, 2*toomLen, carry, borrow);
    SignedDigit tempD1Top = D1Top - D2Top - borrow;
    D2Top = D1Top + D2Top + carry;
    D1Top = tempD1Top;
#ifdef TRACE_TIMES
//@ display("diff", D1Top, D1, 2*toomLen);
//@ display("sum", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
// Halve both of these
    D1Top = karaHalve(D1Top, D1, 2*toomLen);
    D2Top = karaHalve(D2Top, D2, 2*toomLen);
#ifdef TRACE_TIMES
//@ display("halfdiff", D1Top, D1, 2*toomLen);
//@ display("halfsum", D2Top, D2, 2*toomLen);
#endif // TRACE_TIMES
    if constexpr (!thread) // These already computed in the threaded version
    {   innerGeneralMul(aLow, toomLen, bLow, D0, workspace);
        innerGeneralMul(aHigh, aHighLen, bHigh, bHighLen, D3, workspace);
    }
#ifdef TRACE_TIMES
//@ display("D0", D0, 2*toomLen);
//@ display("D3", D3, aHighLen+bHighLen);
#endif // TRACE_TIMES
// I need to D1 -= D3; D2 -= D0;
    D1Top -= karaSubtract(D1, 2*toomLen, D3, aHighLen+bHighLen, D1);
    D2Top -= karaSubtract(D2, 2*toomLen, D0, 2*toomLen, D2);
#ifdef TRACE_TIMES
//@ display("fixedD1", D1, 2*toomLen);
//@ display("fixedD2", D2, 2*toomLen);
#endif // TRACE_TIMES
// Now to assemble the final result I just need to cope with the fact
// the the partial products P0, D1, D1 and P3 overlap.
// So now I have
//   res:   D3hi  D3lo   xxx   D0Hi D0Lo
//                D1Top  D1Hi  D1Lo
//          D2Top D2Hi   D2Low
    carry = karaAdd(D1, toomLen,                    // D1Lo
                    res+toomLen, toomLen,           // D0Hi
                    res+toomLen);
    carry = karaAdd(D1+toomLen, toomLen,            // D1Hi
                    D2, toomLen, carry,             // D2Lo
                    res+2*toomLen);
    carry = karaAdd(D2+toomLen, toomLen,            // D2Hi
                    res+3*toomLen, toomLen, carry,  // D3Lo
                    res+3*toomLen);
    // karaCarry(carry, res+4*toomLen); by adding carry into D2Top I do this
    D2Top += carry;
// I need to merge in D1Top and D2TOP. Note that either could be positive
// or negative, and that is part of why I did not merge them in earlier.
    if (D1Top > 0)      karaCarry(D1Top, res+3*toomLen);
    else if (D1Top < 0) karaBorrow(-D1Top, res+3*toomLen);
    if (D2Top > 0)      karaCarry(D2Top, res+4*toomLen);
    else if (D2Top < 0) karaBorrow(-D2Top, res+4*toomLen);
#ifdef TRACE_TIMES
    display("result", res, M+N);
    display("toom32 finishing");
#endif // TRACE_TIMES
}

// This is the entrypoint for Karatsuba multiplication, and it
// will be called with N>=M amd with a workspace vector big enough for
// its needs.

// a := ahigh*x + alow;
// b := bhigh*x + blow;
//
// x^2 * (ahigh*bhigh) +
// x   * (alow*bhigh + ahigh*blow) +
//       (alow*blow)
//
// adiff := alow-ahigh;
// bdiff := blow-bhigh;
// p0 := alow*blow;
// p1 := adiff*bdiff;       ahigh*bhigh + alow*blow - alow*bhigh - ahigh*blow
// p2 := ahigh*bhigh;
//
// d0 := p0;                alow*blow
// d1 := p0 + p2 - p1;      alow*bhigh + amid*blow
// d2 := p2;                ahigh*bhigh
//
// Well sometimes adiff and/or bdiff are computed with the subtraction
// the other way round so as to leave a positive value there. In which
// case we need
// d1 := p1 - p0 - p2;      alow*bhigh + amid*blow

template <bool thread=false>
static void kara(ConstDigitPtr a, std::size_t N,
                 ConstDigitPtr b, std::size_t M,
                 DigitPtr result,
                 DigitPtr workspace)
{   std::size_t lowSize = (N+1)/2;
    std::size_t aHighLen = N-lowSize;
    std::size_t bHighLen = M-lowSize;
    ConstDigitPtr aHigh = a+lowSize;
    ConstDigitPtr bHigh = b+lowSize;
#ifdef TRACE_TIMES
    if constexpr (thread)
        display2("start parallel kara", N, M);
    else display2("start kara", N, M);
    display("ahigh", aHigh, aHighLen);
    display("alow", a, lowSize);
    display("bhigh", bHigh, bHighLen);
    display("blow", b, lowSize);
#endif // TRACE_TIMES
// I have now split a and b into low and and high parts where the two
// low parts are half the size of the larger input (rounded up if that
// was odd). I now want to form |aHigh - aLow| and similarly for b
// keeping track of whether taking the absolute values involved a sign flip.
    DigitPtr aDiff, bDiff;
    DigitPtr ws;
    std::size_t wsize = workspaceSize(lowSize);
    if constexpr (thread)
    {   aDiff = workspace+2*lowSize;
        bDiff = workspace+3*lowSize;
        ws = workspace+4*lowSize;
    }
    else
    {   aDiff = result;
        bDiff = result+lowSize;
        ws = workspace+2*lowSize;
    }
    bool sign = absDifference(a, lowSize, aHigh, aHighLen, aDiff);
    if (absDifference(b, lowSize, bHigh, bHighLen, bDiff)) sign = !sign;
#ifdef TRACE_TIMES
    display("adiff", aDiff, lowSize);
    display("bdiff", bDiff, lowSize);
    std::cout << "% sign = " << sign << "\n";
#endif // TRACE_TIMES
    if constexpr (thread)
    {   std::vector<MultiplicationTask> subtasks =
        {   MultiplicationTask(aDiff, lowSize, bDiff, lowSize,
                     workspace, ws),
            MultiplicationTask(aHigh, aHighLen, bHigh, bHighLen,
                     result+2*lowSize, ws+2*wsize),
            MultiplicationTask(a, lowSize, b, lowSize,
                     result, ws+wsize)
        };
        runInThreads(subtasks, useMultiplicationTask);
    }
    else
    {   innerGeneralMul(aDiff, lowSize,
                        bDiff, workspace, ws);
        innerGeneralMul(a, lowSize,
                        b, result, ws);
        innerGeneralMul(aHigh, aHighLen,
                        bHigh, bHighLen, result+2*lowSize, ws);
    }
#ifdef TRACE_TIMES
    display("lowprod", result, 2*lowSize);
    display("midprod", workspace, 2*lowSize);
    display("highprod", result+2*lowSize, aHighLen+bHighLen);
#endif // TRACE_TIMES
// At this stage result has aHigh*bHigh in its top half and aLow*bLow
// in its bottom half. Then workspace hold aDiff*bDiff. I now need to
// combine these to get my final result. 
// If sign is false workspace holds aHigh*bHigh+aLow*bLow-middleTerms
// so I want to go
// 1.    workspace = aHigh*bHigh - workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// Step 1 can generate a borrow and step 2 a carry, so on input to step 3
// there is an extra -1, 0 or +1 to deal with.
// If sign is true I want
// 1.    workspace = aHigh*bHigh + workspace
// 2.    workspace = aLow*bLow + workspace
// 3.    result[middle] += workspace --- carry up into high part if needed.
// and now each of steps 1 and 2 may generate a carry, so step 3 starts
// with an extra 0, +1 or +2.
    int extra = 0;
    if (sign) extra =
        karaAdd(workspace, 2*lowSize,
                result+2*lowSize, aHighLen+bHighLen,
                workspace);
    else extra =
        -karaRevSubtract(workspace, 2*lowSize,
                         result+2*lowSize, aHighLen+bHighLen,
                         workspace);
    extra += karaAdd(result, 2*lowSize,
                     workspace, 2*lowSize, workspace);
// extra can now be -1, 0, 1 or 2
    Digit carry = karaAdd(workspace, 2*lowSize,
                          result+lowSize, 2*lowSize, result+lowSize);
    karaCarry(carry, result+3*lowSize);
    if (extra > 0) karaCarry(extra, result+3*lowSize);
    else if (extra < 0) karaBorrow(-extra, result+3*lowSize);
#ifdef TRACE_TIMES
    display("result", result, M+N);
    display("end of kara");
#endif // TRACE_TIMES
}  

}; // end of BigMultiplication class

// Now the external world needs access to the entrypoint "generalMul"
// so I provide a shim that calls it so that others do not need to
// fuss about the class name.

[[gnu::always_inline]]
void generalMul(ConstDigitPtr a, std::size_t N,
                       ConstDigitPtr b, std::size_t M,
                       DigitPtr result)
{   BigMultiplication::generalMul(a, N, b, M, result);
}

// verySimpleMul is intended to deliver the same results as generalMul
// but using clear (if less efficient code) so it can be use as a
// reference implementation during testing.

void verySimpleMul(ConstDigitPtr a, std::size_t N,
                          ConstDigitPtr b, std::size_t M,
                          DigitPtr result)
{   BigMultiplication::verySimpleMul(a, N, b, M, result);
}

// End of integer multiplication code.
//=========================================================================


// Now some code that delivers just some of the digits from a product.

// Return (in w) the digits from "from" to "to" (inclusive) from
// the product of u by v. "from" defaults to zero and "to" to a high
// value - the product runs from 0 (inclusive) to N+M (exclusive)
// and if "to" is overlarge no output data beyond the real digits of
// the product are put into w.
// When "from" is non-zero the lowest result in w may be incorrect by
// being low by up to [maybe] min(N,M). That is because in the perfect
// result there may have been carries passed on up from lower partial
// products.

// Note that the digit correspoding to "from" is put in the first
// location in the output vector, and that vector should be
// (min(N+M-1, to)-from) in length.

// The "reference" version does a full multiplication (which may use
// Karatsuba) and then keeps just some of the digits. If only a small
// slice of the result is needed the full multiplication will generate
// many unnecessary digits. But the code here is very simple and
// can be used to document the intent of everything else. I will also use
// it when the sizes M and N are very different.

void referencePartMul(const std::uint64_t* u, size_t N,
                             const std::uint64_t* v, size_t M,
                             std::uint64_t* w,
                             size_t from=0, size_t to=SIZE_MAX)
{   stkvector<Digit> temp(N+M);
// This reference implementation just forms the full product and then
// copies the words [from..to] to where they are needed. It needs
// workspace for the full product to calculated, and
// stkvector<Digit> temp(N+M) arranges for that one way or another.
    generalMul(u, N, v, M, temp);
    to = std::min(to, N+M-1);
    for (size_t i=from; i<=to; i++) w[i-from] = temp[i];
}

// The "classical" version is what will be used for multiplications
// involving not too many digits, and is pretty straightforward.

void classicalPartMul(const std::uint64_t* u, size_t N,
                             const std::uint64_t* v, size_t M,
                             std::uint64_t* w,
                             size_t from=0, size_t to=SIZE_MAX)
{   Digit lo=0, hi=0, carry=0, hi1;
    to = std::min(to, N+M-1);
// The curious expression here is intended to lead to branch-free code
// that sets the range of digits to be combined forming partial
// products. The idea is that ((-boolVal) & X will) yield the
// same result as (boolVal ? X : 0). So here we have
//     k < M :    imin = 0
//     k >= M :   imin = k - kenv + 1
//     k < N :    imax = k
//     k >= N :   imax = N - 1
    if (from != 0)
    {
        size_t imin = (-(from>=M+1)) & (from - M);
        size_t imax = N - 1 - ((-(from<N+1)) & (N - from));
        for (size_t i=imin; i<=imax; i++)
        {   arithlib_assert(from>=i+1);
            multiply64(u[i], v[from-i-1], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
// I form the partial products for one earlier row because the high
// parts of them contribute fully to the digits that I want. But I discard
// the result apart from keeping anything that has carried out from it.
        // w[-1] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
    for (size_t k=from; k<=to; k++)
    {   size_t imin = (-(k>=M)) & (k - M + 1);
        size_t imax = N - 1 - ((-(k<N)) & (N - 1 - k));
        for (size_t i=imin; i<=imax; i++)
        {   multiply64(u[i], v[k-i], lo, hi1, lo);
            carry += ((hi += hi1) < hi1);
        }
        w[k-from] = lo;
        lo = hi;
        hi = carry;
        carry = 0;
    }
}

// A "fast" multiply decomposes the calculation in a way based on
// work by Mulder.
//
// See Mulder, T. "On Short Multiplications and Divisions." AAECC 11,
// 6988 (2000). https://doi.org/10.1007/s002000000037
// and also see
// G Henriot and P Zimmermanm, "A long note on Mulder's Short Product"
// Journal of Symbolic Computation Volume 37, 3, March 2004, Pages 391-401

Digit fastPartMulAdd(const std::uint64_t* u, size_t N,
                            const std::uint64_t* v, size_t M,
                            std::uint64_t* w,
                            size_t from, size_t to);

// This forms a sub-product and adds it in. This is made into
// a separate function allowing for a shift by uShift, vShift
// because from, to and w need adjustment and the calculations that
// set their values seemed most easily expressed here.

Digit shiftedFastPartMulAdd(const std::uint64_t* u, size_t N,
                                   const std::uint64_t* v, size_t M,
                                   std::uint64_t* w,
                                   size_t from, size_t to,
                                   size_t uShift, size_t vShift)
{   size_t h = uShift + vShift;
    if (to <= h) return 0;
    to -= h;
    if (from < h)
    {   w = w + (h-from);
        from = 0;
    }
    else
    {   from -= h;
    }
    return fastPartMulAdd(u+uShift, N,
                          v+vShift, M,
                          w,
                          from, to);
}

// This computes the product of two numbers each of which are N digits long
// and where "to" is such that quite a lot of the high digits of the
// result are not wanted.

void lowPartMul(const std::uint64_t* u,
                       const std::uint64_t* v, size_t N,
                       std::uint64_t*  w,
                       size_t from, size_t to)
{   size_t split = std::min(N, ((7*to)/10 + 1) & ~1);
    size_t gap = N-split;
    if (gap <= 3) split = N;
    referencePartMul(u, split,
                     v, split,
                     w,
                     from, to);
    if (split == N) return;
    shiftedFastPartMulAdd(u, N,
                          v, gap,
                          w,
                          from, to,
                          0, split);
    shiftedFastPartMulAdd(u, split,
                          v, gap,
                          w,
                          from, to,
                          split, 0);
}

// I code this so that w does not overshoot the end of the vector w,
// even though in C++ it is legal to have a pointer to the location
// one beyond a vector.

Digit propagateCarry(Digit carry, std::uint64_t* w, size_t len)
{   if (carry==0 || len==0) return carry;
    for (;;)
    {   carry = addWithCarry(*w, carry, *w);
        if (carry==0) return 0;
        len--;
        if (len==0) return carry;
        w++;
    }
}

const size_t midmul_threshold = 20;

void fastPartMul(const std::uint64_t* u, size_t N,
                        const std::uint64_t* v, size_t M,
                        std::uint64_t* w,
                        size_t from=0, size_t to=SIZE_MAX)
{
// Any digits in either u or v beyond "to" can be discarded since they can
// not contribute to the desired part of the result.
    if (to<N-1) N = to+1;
    if (to<M-1) M = to+1;
    if (N > M)          // ensure that u is the shorter argument
    {   std::swap(u, v);
        std::swap(N, M);
    }
    if (from>N-1)
    {   size_t shift = from-(N-1);
        if (M-shift >= N)
        {   v += shift;
            M -= shift;
            to -= shift;
            from -= shift;
        }
    }
    to = std::min(to, N+M-1);
// If either the smaller operand is small or if the slice of the result
// I want is narrow I fall back to classical long multiplication.
    if ((to-from) < midmul_threshold || N < midmul_threshold)
    {   classicalPartMul(u, N, v, M, w, from, to);
        return;
    }
    if (3*N < M)
    {
// This special case will apply if the two input integers are very
// different in size. It is here because a previous revision of this
// code could end up recursing ridiculously deeply in such cases when
// in fact almost all of the product needed computing so calculating
// it all as is done here was not a severe overhead.
        referencePartMul(u, N, v, M, w, from, to);
        return;
    }
// The following rather strange calculation decide how to split the
// full product calculation into parts. The ideas built into it
// are:
// . We can never split off a balanced multiplication larger than NxN.
// . When we split one off it should have an even size since we hope
//   to be able to use Karatsuba on it.
// . The size should be such that the split-off square multiplication
//   uses input data beyond the "from" threshold. Here I set things
//   such that if I will want K high digits in my result I form the
//   product of two 0.7K digit numbers for form a 1.4K digit intermediate
//   result and then ignore the low 0.4K digits of that. The fraction 0.7
//   is not going to be optimal - even more in the case of unbalanced
//   lengths of inputs, but is probably a reasonable approximation to the
//   best and so is what I use. If one was in a situation where both
//   arguments were the same fixed size and the fraction of the output
//   needed was fixed it would be proper to tune this carefully.
    size_t split = std::min(N, ((7*(N+M-from))/10 + 1) & ~1);
// Do the first square multiplication... This is always done as by forming a
// full 2*split digit product and the intent is that it always uses
// Karatsuba.
// Well if "to" is a significant limit on how many digits are required
// this might be improved upon by doing Mulder-like decompostion upwards
// towards "to" as well as downwards towards "from".
    size_t shift = N+M-2*split;
// I will generally need to add in components of the final result, and
// so I zero out parts of w that will not be set by filling in the first
// product.
    for (size_t i=from; i<shift && i<=to; i++) w[i-from] = 0;
    lowPartMul(u+(N-split), v+(M-split), split,
               from>shift ? w : w + (shift-from),
               from>shift ? from-shift : 0,
               to-shift);
    size_t P = N+M-1-split;     // higest digit from lower parts
    if (from > P) return;
    Digit carry;
    if (split == N)
    {   if (N == M) return;
        carry = fastPartMulAdd(u, N, v, M-split, w, from, to);
    }
    else
    {   shift = M-split;
// This can recurse and as such is ugly - but at an earlier stage I have
// ensured that M can only be a modest multiple of N so the recursion
// depth here can never be deep enough to worry me.
        carry = fastPartMulAdd(u, N,
                               v, shift,
                               w,
                               from, to);
        carry += shiftedFastPartMulAdd(u, N-split,
                                       v, split,
                                       w,
                                       from, to,
                                       0, shift);
    }
    if (to > P) propagateCarry(carry, w+(P-from+1), to-P);
}

// Note that default values for from and to were set up in the declaration
// and must not be repeated here.

Digit fastPartMulAdd(const std::uint64_t* u, size_t N,
                            const std::uint64_t* v, size_t M,
                            std::uint64_t* w,
                            size_t from, size_t to)
{   to = std::min(to, N+M-1);
// A special case here is when M is much larger then N, since with
// naive code this can end up allocating a really big temporary vector
// and calling fastMul to fill it in - and that will hive of a chunk
// of size N at the top and then recurse to get here again. The effect
// can be both very deep recursion and use of a quite unreasonable
// amount of working space. But I avoid getting here in that case!
    stkvector<Digit> temp(to-from+1);
    fastPartMul(u, N, v, M, temp, from, to);
    Digit carry = 0;
    for (size_t i=0; i<N+M-from+1 && i<=to-from; i++)
        carry = addWithCarry(w[i], temp[i], carry, w[i]);
    return carry;
}

// Returns the digit at position "from:bits" from the product of u by v.
// Some low bits of the result may be incorrect with the result being
// potentially less than the ideal result by at most min(M,N).
// This is because in the perfect result there may have been carries
// passed on up from lower partial products.

Digit fastSlice(const std::uint64_t* u, size_t N,
                       const std::uint64_t* v, size_t M,
                       size_t from=0, size_t bits = 0)
{   stkvector<Digit> shiftedU(N+1);
    if (bits != 0)
    {   Digit carry = 0;
        for (size_t i=N; i!=0; i--)
        {   Digit d = u[i-1];
            shiftedU[i] = (d>>bits) | (carry<<(64-bits));
            carry = d;
        }
// The "0u" on the next line is to avoid a C++ ambiguity that arises
// at least on 32-bit platforms where int and size_t are the same
// width.
        shiftedU[0u] = carry<<(64-bits);
        u = shiftedU;
        N++;
        from++;
    }
    Digit lo=0, hi=0, hi1;
// The curious expression here is intended to lead to branch-free code
// that sets the range of digits to be combined forming partial
// products. The idea is that ((-boolVal) & X will) yield the
// same result as (boolVal ? X : 0). So here we have
//     k < M :    imin = 0
//     k >= M :   imin = k - kenv + 1
//     k < N :    imax = k
//     k >= N :   imax = N - 1
//
// First generate high parts of the partial products from the row
// below "from" and leave that in hi.
    size_t imin = (-(from>=M+1)) & (from - M);
    size_t imax = N - 1 - ((-(from<N+1)) & (N - from));
    for (size_t i=imin; i<=imax; i++)
    {   multiply64(u[i], v[from-i-1], lo, hi1, lo);
        hi += hi1;
    }
// Now add in the low parts of the partial products in row "from".
    imin = (-(from>=M)) & (from - M + 1);
    imax = N - 1 - ((-(from<N)) & (N - 1 - from));
    for (size_t i=imin; i<=imax; i++)
        multiply64(u[i], v[from-i], hi, hi1, hi);
    return hi;
}

// This is the main entrypoint to the (big) integer multiplication code. It
// takes two signed numbers and forms their product.

void bigmultiply(
        const std::uint64_t* a, std::size_t lena,
        const std::uint64_t* b, std::size_t lenb,
        std::uint64_t* c, std::size_t &lenc)
{
// For this a and b must be treated as 2s complement signed numbers,
// and the length lenc returned but ensure that the top digit of the
// product is not a redundant zero or -1.
    generalMul(a, lena, b, lenb, c);
#ifdef CHECK_TIMES
    {   stkvector<Digit> c1(lena+lenb);
        verySimpleMul(a, lena, b, lenb, c1);
        for (size_t i=0; i<lena+lenb; i++)
        {   if (c[i] != c1[i])
            {   std::cout << "\n% CHECK_TIMES\n";
                display("a", a, lena);
                display("b", b, lenb);
                display("true", c1, lena+lenb);
                display("mine", c, lena+lenb);
                arithlib_abort("failure in multiplication");
            }
        }
    }
#endif // CHECK_TIMES
    if (negative(a[lena-1])) subtractWithBorrow(c+lena, b, c+lena, lenb);
    if (negative(b[lenb-1])) subtractWithBorrow(c+lenb, a, c+lenb, lena);
    lena += lenb;
// A case like {0,0x80000...} times the same leads at this stage to
// {0, 0, 0x40000...} and the length needs to be shrunk by two words. The
// way I code this is intended to have a chance of compiling into branch-
// free code and execute faster than "if (shrinkable(..)) lena--;".
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lenc = lena;
}

void classicalbigmultiply(
        const std::uint64_t* a, std::size_t lena,
        const std::uint64_t* b, std::size_t lenb,
        std::uint64_t* c, std::size_t &lenc)
{
// For this a and b must be treated as 2s complement signed numbers,
// and the length lenc returned but ensure that the top digit of the
// product is not a redundant zero or -1.
    if (lena < lenb)
    {   std::swap(a, b);
        std::swap(lena, lenb);
    }
    verySimpleMul(a, lena, b, lenb, c);
    if (negative(a[lena-1])) subtractWithBorrow(c+lena, b, c+lena, lenb);
    if (negative(b[lenb-1])) subtractWithBorrow(c+lenb, a, c+lenb, lena);
    lena += lenb;
// A case like {0,0x80000...} times the same leads at this stage to
// {0, 0, 0x40000...} and the length needs to be shrunk by two words. The
// way I code this is intended to have a chance of compiling into branch-
// free code and execute faster than "if (shrinkable(..)) lena--;".
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lena -= shrinkable(c[lena-1], c[lena-2]);
    lenc = lena;
}

//===========================================================================
//===========================================================================

std::intptr_t Times::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n = lena+lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
// bigmultiply already tries to detect and handle small cases specially,
// but it could be that detecting some very small cases here - ie even
// earlier - would be worthwhile.
    bigmultiply(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

std::intptr_t Times::op(SignedDigit a, SignedDigit b)
{   SignedDigit hi;
    Digit lo;
    signedMultiply64(a, b, hi, lo);
    if ((hi==0 && positive(lo)) ||
        (hi==-1 && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        std::uint64_t* r = reserve(1);
        r[0] = lo;
        return confirmSize(r, 1, 1);
    }
    std::uint64_t* r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirmSize(r, 2, 2);
}

std::intptr_t Times::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* c = reserve(lenb+1);
    Digit hi = 0;
    for (std::size_t i=0; i<lenb; i++)
        multiply64(a, b[i], hi, hi, c[i]);
    c[lenb] = hi;
    if (negative(a))
    {   Digit carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = addWithCarry(c[i+1], ~b[i], carry, c[i+1]);
    }
    if (negative(b[lenb-1])) c[lenb] -= a;
    std::size_t lenc = lenb+1;
    truncatePositive(c, lenc);
    truncateNegative(c, lenc);
    return confirmSize(c, lenb+1, lenc);
}

std::intptr_t Times::op(std::uint64_t* a, SignedDigit b)
{   return Times::op(b, a);
}

std::intptr_t ClassicalTimes::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::size_t n = lena+lenb;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
// bigmultiply already tries to detect and handle small cases specially,
// but it could be that detecting some very small cases here - ie even
// earlier - would be worthwhile.
    classicalbigmultiply(a, lena, b, lenb, p, final_n);
    return confirmSize(p, n, final_n);
}

std::intptr_t ClassicalTimes::op(SignedDigit a, SignedDigit b)
{   SignedDigit hi;
    Digit lo;
    signedMultiply64(a, b, hi, lo);
    if ((hi==0 && positive(lo)) ||
        (hi==-1 && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        std::uint64_t* r = reserve(1);
        r[0] = lo;
        return confirmSize(r, 1, 1);
    }
    std::uint64_t* r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirmSize(r, 2, 2);
}

std::intptr_t ClassicalTimes::op(SignedDigit a, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* c = reserve(lenb+1);
    Digit hi = 0;
    for (std::size_t i=0; i<lenb; i++)
        multiply64(a, b[i], hi, hi, c[i]);
    c[lenb] = hi;
    if (negative(a))
    {   Digit carry = 1;
        for (std::size_t i=0; i<lenb; i++)
            carry = addWithCarry(c[i+1], ~b[i], carry, c[i+1]);
    }
    if (negative(b[lenb-1])) c[lenb] -= a;
    std::size_t lenc = lenb+1;
    truncatePositive(c, lenc);
    truncateNegative(c, lenc);
    return confirmSize(c, lenb+1, lenc);
}

std::intptr_t ClassicalTimes::op(std::uint64_t* a, SignedDigit b)
{   return ClassicalTimes::op(b, a);
}

// For big multi-digit numbers squaring can be done almost twice as fast
// as general multiplication.
// eg (a0,a1,a2,a3)^2 can be expressed as
// a0^2+a1^2+a2^2+a3^2 + 2*(a0*a1+a0*a2+a0*a3+a1*a2+a1*a3+a2*a3)
// where the part that has been doubled uses symmetry to reduce the work.
//
// For negative inputs I can form the product first treating the inputs
// as if they had been unsigned, and then subtract 2*2^w*a from the result.
//
// I think my view here is that I should still be willing to move across
// to Karatsuba, but only at a distinctly larger threshold than for
// simple multiplication. Just where that threshold should be is not really
// clear to me, but for now I am setting it as 3 times the point at which
// ordinary multiplications moves on from classical methods.

void bigsquare(std::uint64_t* a, std::size_t lena,
                      std::uint64_t* r, std::size_t &lenr)
{   if (lena > 24)
    {   bigmultiply(a, lena, a, lena, r, lenr);
        return;
    }
    for (std::size_t i=0; i<2*lena; i++) r[i] = 0;
    Digit carry;
    lenr = 2*lena;
    for (std::size_t i=0; i<lena; i++)
    {   Digit hi = 0;
// Note that all the terms I add in here will need to be doubled in the
// final accounting.
        for (std::size_t j=i+1; j<lena; j++)
        {   Digit lo;
            multiply64(a[i], a[j], hi, hi, lo);
            hi += addWithCarry(lo, r[i+j], r[i+j]);
        }
        r[i+lena] = hi;
    }
// Double the part that has been computed so far.
    carry = 0;
    for (std::size_t i=0; i<2*lena; i++)
    {   Digit w = r[i];
        r[i] = (w << 1) | carry;
        carry = w >> 63;
    }
// Now add in the bits that do not get doubled.
    carry = 0;
    Digit hi = 0;
    for (std::size_t i=0; i<lena; i++)
    {   Digit lo;
        multiply64(a[i], a[i], r[2*i], hi, lo);
        carry = addWithCarry(lo, carry, r[2*i]);
        carry = addWithCarry(hi, r[2*i+1], carry, r[2*i+1]);
    }
// Now if the input had been negative I have a correction to apply...
// I subtract 2a from the top half of the result.
    if (negative(a[lena-1]))
    {   Digit carry = 1;
        int fromprev = 0;
        for (std::size_t i=0; i<lena; i++)
        {   Digit d = a[i];
            Digit w = (d<<1) | fromprev;
            fromprev = static_cast<int>(d>>63);
            carry = addWithCarry(r[lena+i], ~w, carry, r[lena+i]);
        }
    }
// The actual value may be 1 word shorter than this.
//  test top digit or r and if necessary reduce lenr.
    truncatePositive(r, lenr);
    truncateNegative(r, lenr);
}

std::intptr_t Square::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    std::size_t n = 2*lena;
    std::uint64_t* p = reserve(n);
    std::size_t final_n;
    bigsquare(a, lena, p, final_n);
    return confirmSize(p, n, final_n);
}

std::intptr_t Square::op(SignedDigit a)
{   Digit hi, lo;
    multiply64(a, a, hi, lo);
    if (a < 0) hi -= 2u*static_cast<Digit>(a);
// Now I have a 128-bit product of the inputs
    if ((hi == 0 && positive(lo)) ||
        (hi == static_cast<Digit>(-1) && negative(lo)))
    {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
            LIKELY
            return intToHandle(static_cast<SignedDigit>(lo));
        else
        {   std::uint64_t* p = reserve(1);
            p[0] = lo;
            return confirmSize(p, 1, 1);
        }
    }
    std::uint64_t* p = reserve(2);
    p[0] = lo;
    p[1] = hi;
    return confirmSize(p, 2, 2);
}

std::intptr_t Isqrt::op(std::uint64_t* a)
{   std::size_t lena = numberSize(a);
    if (lena == 1) return Isqrt::op(static_cast<SignedDigit>(a[0]));
    std::size_t lenx = (lena+1)/2;
    std::uint64_t* x = reserve(lenx);
    for (std::size_t i=0; i<lenx; i++) x[i] = 0;
    std::size_t bitstop = a[lena-1]==0 ? 0 : 64 - CSL_LISP::nlz(a[lena-1]);
    bitstop /= 2;
    if ((lena%2) == 0) bitstop += 32;
    x[lenx-1] = 1ULL << bitstop;
    if (bitstop == 63) x[lenx-1]--; // ensure it is still positive!
// I now have a first approximation to the square root as a number that is
// a power of 2 with about half the bit-length of a. I will degenerate into
// using generic arithmetic here even though that may have extra costs.
//
// I could perhaps reasonably use uint64_t arithmetic for a first few
// iterations, only looking at the most significant digit of the input.
// That would save time, however at present I do not expect this function
// to be time critical in any plausible application, and so I will keep
// things simple(er).
    Bignum biga(true, vectorToHandle(a));
    Bignum bigx(true, confirmSize(x, lenx, lenx));
// I will do the first step outside the loop to guarantee that my
// approximation is an over-estimate before I try the end-test.
//         bigx = (bigx + biga/bigx) >> 1;
// The push/pop mess here feels extreme and I should probably re-code this
// using lower level interfaces.
    Bignum w1 = biga/bigx;
    w1 = bigx + w1;
    bigx = w1 >> 1;
    for (;;)
    {   w1 = biga/bigx;
        w1 = bigx + w1;
        Bignum y = w1 >> 1;
        if (y >= bigx) break;
        bigx = y;
    }
// The Bignum "biga" encapsulated my argument: when its destructor is called
// I do not want the input vector "a" to be clobbered, so I clobber the
// bignum first to break the link. Ditto bigx.
    biga.val = 0;
    std::intptr_t r = bigx.val;
    bigx.val = 0;
    return r;
}

std::intptr_t Isqrt::op(SignedDigit aa)
{   if (aa <= 0) return intToBignum(0);
    Digit a = static_cast<Digit>(aa);
    std::size_t w = 64 - CSL_LISP::nlz(a);
    Digit x0 = a >> (w/2);
// The iteration here converges to sqrt(a) from above, but I believe that
// when the value stops changing it will be at floor(sqrt(a)). There are
// some cases where the sequence ends up alternating between two adjacent
// values. Because my input is at most 2^63-1 the number of iterations
// written here will always suffice.
    Digit x1 = (x0 + a/x0)/2;
    Digit x2 = (x1 + a/x1)/2;
    if (x2 >= x1) return unsignedIntToBignum(x1);
    Digit x3 = (x2 + a/x2)/2;
    if (x3 >= x2) return unsignedIntToBignum(x2);
    Digit x4 = (x3 + a/x3)/2;
    if (x4 >= x3) return unsignedIntToBignum(x3);
    Digit x5 = (x4 + a/x4)/2;
    if (x5 >= x4) return unsignedIntToBignum(x4);
    return unsignedIntToBignum(x5);
}

// This raises a bignum to a positive integer power. If the power is n then
// the size of the output may be n*lena. The two vectors v and w are workspace
// and must both be of size (at least) the size that the result could end
// up as. Well with greater subtlty we can see that the sum of their sizes
// must be at least the size of the result, but it is not clear that any
// useful saving spece saving can be found down that path.

void bigpow(std::uint64_t* a, std::size_t lena,
                   Digit n,
                   std::uint64_t* v,
                   std::uint64_t* w,
                   std::uint64_t* r, std::size_t &lenr, std::size_t maxlenr)
{   if (n == 0)
    {   r[0] = 0;
        lenr = 1;
        return;
    }
//  LispObject r = fixnum_of_int(1);
//  while (n != 1)
//  {   if ((n & 1) != 0) r = Times::op(r, a);
//      a = Square::op(a);
//      n = n/2;
//  }
//  return Times::op(r, a);
    internalCopy(a, lena, v);
    std::size_t lenv = lena, lenw;
    r[0] = 1;
    lenr = 1;
    while (n != 1)
    {   if ((n & 1) != 0)
        {   bigmultiply(r, lenr, v, lenv, w, lenw);
            internalCopy(w, lenr=lenw, r);
        }
        bigsquare(v, lenv, w, lenw);
        internalCopy(w, lenv=lenw, v);
        n = n/2;
    }
    bigmultiply(r, lenr, v, lenv, w, lenw);
    internalCopy(w, lenr=lenw, r);
}

// In cases where n is too large this can fail. At present I deal with that
// with arithlib_assert() statements rather than any comfortable scheme for
// reporting the trouble.

// The code that dispatches into here should have filtered cases such that
// the exponent n is not 0, 1 or 2 here.

std::intptr_t Pow::op(std::uint64_t* a, SignedDigit n)
{   std::size_t lena = numberSize(a);
//  1^(-n) == 1,
//  (-1)^(-n) == 1 if n is even or -1 if n is odd.
//  a^(-n) == 0 when a is not -1, 0 or 1.
    if (n < 0)
    {   int z = 0;
        if (lena == 0)
        {   if (static_cast<SignedDigit>(a[0]) == 1) z = 1;
            else if (static_cast<SignedDigit>(a[0]) == -1)
                z = (n%1==0 ? 1 : -1);
            else arithlib_assert(a[0] != 0u);
        }
// 0^(-n) is an error
// 1^(-n) = 1
// (-1)^(-n) = +1 or -1 depending on whether n is odd or even
// x^(-n) = 0 otherwise.
        return intToBignum(z);
    }
// 6^n = 0
    std::size_t bitsa = bignumBits(a, lena);
    Digit hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    arithlib_assert(hi==0); // Check that size is at least somewhat sane!
// I estimate the largest size that my result could be, but then add
// an extra word because the internal working of multiplication can
// write a zero beyond its true result - eg if you are multiplying a pair
// of 1-word numbers together it will believe that the result could be 2
// words wide even if in fact you know it will not be.
    Digit lenr1 = 2 + bitsr/64;
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    Digit olenr = lenr;
    std::uint64_t* r = reserve(lenr);
    std::uint64_t* v = reserve(lenr);
    std::uint64_t* w = reserve(lenr);
    bigpow(a, lena, static_cast<Digit>(n), v, w, r, lenr, lenr);
    abandon(w);
    abandon(v);
    return confirmSize(r, olenr, lenr);
}

// Again the cases n = 0, 1 and 2 have been filtered out

std::intptr_t Pow::op(SignedDigit a, SignedDigit n)
{   if (n < 0)
    {   int z = 0;
        if (a == 1) z = 1;
        else if (a == -1) z = (n%1==0);
        else arithlib_assert(a != 0);
        return intToHandle(z);
    }
    if (a == 0) return intToHandle(0);
    else if (a == 1) return intToHandle(a);
    else if (n == 0) return intToHandle(1);
    Digit absa = (a < 0 ? -static_cast<Digit>
                          (a) : static_cast<Digit>(a));
    std::size_t bitsa = 64 - CSL_LISP::nlz(absa);
    Digit hi, bitsr;
    multiply64(n, bitsa, hi, bitsr);
    Digit lenr1 = 2 + bitsr/64;
    if (bitsr < 64) // Can do all the work as machine integers.
    {   SignedDigit result = 1;
        for (;;)
        {   if (n%2 != 0) result *= a;
            if ((n = n/2) == 0) break;
            a *= a;
        }
        return intToBignum(result);
    }
    std::size_t lenr = static_cast<std::size_t>(lenr1);
// if size_t was more narrow than 64-bits I could lose information in
// truncating from uint64_t to size_t.
    Digit olenr = lenr;
    std::uint64_t* r = reserve(lenr);
    std::uint64_t* v = reserve(lenr);
    std::uint64_t* w = reserve(lenr);
    Digit aa[1] = {static_cast<Digit>(a)};
    bigpow(aa, 1, static_cast<Digit>(n), v, w, r, lenr, lenr);
    abandon(w);
    abandon(v);
    return confirmSize(r, olenr, lenr);
}

double Pow::op(std::uint64_t* a, double n)
{   return std::pow(Double::op(a), n);
}

double Pow::op(SignedDigit a, double n)
{   return std::pow(Double::op(a), n);
}

}; // end of namespace


// end of multiply.cpp
