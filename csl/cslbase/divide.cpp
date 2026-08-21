// divide.cpp                                     Copyright A C Norman 2026

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

#include "headers.h"

//
// Division with the main number representation being 2s complement
// turns out to have many messy special cases! Here are some of the
// underlying issues:
// . Inputs may have had initial 0 or -1 digits pre-pended to allow
//   for positive values with their top bit set and negative ones with
//   it clear. So if I had 8-bit words the number 128 would have an
//   unsigned representation of [0x80], but it has to be stored as a
//   two digit number [0x00,0x80]. Similarly some negative numbers
//   need an initial 0xff attached just so that it can be seen that they
//   are negative.
// . If a result (quotient or remainder) is as above then space can be
//   needed for the prefix digit.
// . Long division needs to have a dividend with at least 3 digits
//   (after scaling) and a divisor with at least 2. That means that various
//   small cases have to be treated specially.
// . An operation as basic as taking the absolute value of an integer
//   generally involves allocating memory, and I would like to avoid that
//   as much as I can.
// . quotient and remainder operations are very similar indeed, but I ought
//   to be able to safe memory allocation in one or the other. Specifically
//   if I am computing a remainder I can discard quotient digits as I go
//   rather than having anywhere to put them.
// . On many useful platforms I will have an integer type that is 128 bits
//   wide and I can use that for a 128-by-64 division operation that is
//   really helpful when working with 64-bit digits. It is possible that
//   if I do not have 128-bit arithmetic available it would be best to
//   treat my numbers as being in base 2^32 so that 64-by-32 division is
//   the order of the day as a basic primitive.
// . For Lisp purposes I will have "fixnums" as well as "bignums" so special
//   paths for arithmetic that involves values -2^59 to 2^59-1 will be
//   required.
//
// Well perhaps I am fussing about all the above. But my first drafts of this
// code has not thought through all the cases carefully enough!


// Divide the bignum a by the b, returning a quotient or a remainder or
// both. Note that at this stage a may still be negative! The value b is
// passed in sign and magnitide form as {b, bNegative}

void unsigned_short_division(std::uint64_t* a,
                                    std::size_t lena,
                                    Digit b, bool bNegative,
                                    bool want_q, std::uint64_t*& q,
                                    std::size_t &olenq, std::size_t &lenq,
                                    bool want_r, std::uint64_t*& r,
                                    std::size_t &olenr, std::size_t &lenr)
{   Digit hi = 0;
    bool aNegative = false;
    std::uint64_t* aa;
    if (negative(a[lena-1]))
    {   aNegative = true;
// Take absolute value of a if necessary.
        aa = reserve(lena);
            internalNegate(a, lena, aa);
        a = aa;
    }
// Now both a and b are positive so I can do the division fairly simply.
// Allocate space for the quotient if I need that, and then do standard
// short division.
    std::size_t i=lena-1;
    if (want_q)
    {   olenq = lena;
        q = reserve(olenq);
        }
    for (;;)
    {   Digit d;
        divide64(hi, a[i], b, d, hi);
        if (want_q) q[i] = d;
        if (i == 0) break;
        i--;
    }
// If the original a had been negative I allocated space to store its
// absolute value, and I can discard that now.
    if (aNegative) abandon(aa);
    if (want_q)
    {   lenq = lena;
// The quotient will be negative if divisor and dividend had different signs.
        if (aNegative != bNegative) internalNegate(q, lenq, q);
// Things here are sort of amazing in that eg if internalNegate is called
// on the previous line then q can still end up positive and so need
// a call to truncatePositive. That happens if it is zero. So I call BOTH
// truncatePositive and truncateNegative to ensure I cover all situations.
        truncateNegative(q, lenq);
        truncatePositive(q, lenq);
    }
    if (want_r)
    {
// The remainder is now present as an unsigned value in hi. The sign it
// must end up having must match the sign of a (the dividend). Furthermore
// the remainder will be strictly smaller then b, and the largest possible
// value for b is 0xffffffffffffffff. The remainder may need to be returned
// as a 2-digit bignum.
        if (aNegative)
        {   hi = -hi;
            if (positive(hi) && hi!=0)
            {   olenr = lenr = 2;
                r = reserve(olenr);
                r[0] = hi;
                r[1] = -1;
            }
            else
            {   olenr = lenr = 1;
                r = reserve(olenr);
                r[0] = hi;
            }
        }
        else
        {   if (negative(hi))
            {   olenr = lenr = 2;
                r = reserve(olenr);
                r[0] = hi;
                r[1] = 0;
            }
            else
            {   olenr = lenr = 1;
                r = reserve(olenr);
                r[0] = hi;
            }
        }
    }
}

void signed_short_division(std::uint64_t* a, std::size_t lena,
                                  SignedDigit b,
                                  bool want_q, std::uint64_t*& q,
                                  std::size_t &olenq, std::size_t &lenq,
                                  bool want_r, std::uint64_t*& r,
                                  std::size_t &olenr, std::size_t &lenr)
{   if (b > 0) unsigned_short_division(a, lena,
                                       static_cast<Digit>(b),
                                       false,
                                       want_q, q, olenq, lenq,
                                       want_r, r, olenr, lenr);
    else unsigned_short_division(a, lena, -static_cast<Digit>(b),
                                 true,
                                 want_q, q, olenq, lenq,
                                 want_r, r, olenr, lenr);
}

void unsigned_long_division(std::uint64_t* a,
                                   std::size_t &lena,
                                   std::uint64_t* b, std::size_t &lenb,
                                   bool want_q, std::uint64_t* q,
                                   std::size_t &olenq, std::size_t &lenq);

#ifdef FASTDIVISION
void fastDivision(std::uint64_t* a,
                         std::size_t &lena,
                         std::uint64_t* b, std::size_t &lenb,
                         bool want_q, std::uint64_t* q,
                         std::size_t &olenq, std::size_t &lenq);
#endif // FASTDIVISION

// The following is a major entrypoint to the division code. (a) and (b) are
// vectors of digits such that the top digit of a number is treated as signed
// and the lower ones as unsigned. To cope with this there will sometimes
// be a sort of initial padder digit. The two boolean values indicate whether
// either or both of quotient and remainder are required. if want_q is set
// then this creates a new vector for q and return it via q/lenq. Similarly
// for want_r. The inputs a and b can be bignums of any size and are allowed
// to be positive or negative - this sorts everything out.

// Divide a by b to obtain a quotient q and a remainder r.

void division(std::uint64_t* a, std::size_t lena,
                     std::uint64_t* b, std::size_t lenb,
                     bool want_q, std::uint64_t*& q, std::size_t &olenq, std::size_t &lenq,
                     bool want_r, std::uint64_t*& r, std::size_t &olenr, std::size_t &lenr)
// First I will filter out a number of cases where the divisor is "small".
// I only want to proceed into the general case code if it is a "genuine"
// big number with at least two digits. This bit of the code is messier
// than one might have imagined because of the 2s complement representation
// I use and the fact that extreme values that almost fit in a single
// digit can ends up as 2-digit values with a degenerate top digit.
//
// The first case is when the single digit if b is a signed value in the
// range -2^63 to 2^63-1.
{   if (lenb == 1)
    {
// At present I cause an attempt to divide by zero to crash with an
// arithlib_assert failure if I have build in debug mode or to do who
// knows what (possibly raise an exception) otherwise. This maybe needs
// review. I wonder if I should throw a "division by zero" exception?
        arithlib_assert(b[0] != 0); // would be division by zero
        signed_short_division(a, lena, static_cast<SignedDigit>(b[0]),
                              want_q, q, olenq, lenq,
                              want_r, r, olenr, lenr);
        return;
    }
// Next I have b in the range 2^63 to 2^64-1. Such values can be represented
// in uint64_t. These values have had to have a leading zero in the bignum
// representation so that the value as a whold is not interpreted as being
// negative and although they are stored using 2 Digits they are "really"
// just 1-Digit values.
    else if (lenb == 2 && b[1]==0)
    {   unsigned_short_division(a, lena, b[0], false,
                                want_q, q, olenq, lenq,
                                want_r, r, olenr, lenr);
        return;
    }
// Now for b in -2^64 to -2^63-1. The 2s complement representetation will be
// of the form (-1,nnn) with nnn an unsigned 64-bit value. It is ALMOST the
// case that this can be handled using a short division by -nnn, but there
// is a special case where the value stored in the Digit there is zero and
// the value represented is exactly -2^64. I handle that individually!
    else if (lenb == 2 && b[1]==static_cast<Digit>(-1))
    {   if (b[0] == 0)
        {   if (want_q)
            {   lenq = lena;
                olenq = lena;
                q = reserve(lena);
            // I will now take cases based on the sign of a.
                if (negative(a[lena-1]))
                {
// Here I have a<0 being divided by -2^64. I will compute (-a)>>64 and
// in the worst case that can use as many Digits as a originally did.
                    [[maybe_unused]] Digit notUsed;
                    Digit carry = addWithCarry(~a[0], 1, notUsed);
                    for (std::size_t i=1; i<lena; i++)
                        carry = addWithCarry(~a[i], carry, q[i-1]);
                    q[lena-1] = carry;
                    lenq = lena;
                    truncatePositive(q, lenq);
                }
                else
                {
// With a>=0 I want to compute -(a>>64) and this will always be shorter
// than a.
                    Digit carry = 1;
                    q[0] = 0; // in case lena==1!
                    for (std::size_t i=1; i<lena; i++)
                        carry = addWithCarry(~a[i], carry, q[i-1]);
                    addWithCarry(-1, carry, q[lena-1]);
                    lenq = lena;
                    truncateNegative(q, lenq);
                    truncatePositive(q, lenq);
                }
            }
            if (want_r)
            {
// The remainder will be essentially the bottom digit of a. But sometimes
// an additional digit that will be either 0 or -1 must be placed ahead of
// it.
                Digit rr = a[0], padr = 0;
                lenr = 1;
                if (negative(a[lena-1]) && strictlyPositive(rr))
                {   padr = -1;
                    lenr++;
                }
                else if (positive(a[lena-1]) && negative(rr))
                {   padr = 0;
                    lenr++;
                }
                r = reserve(lenr);
                olenr = lenr;
                r[0] = rr;
                if (lenr != 1) r[1] = padr;
            }
            return;
        }
        unsigned_short_division(a, lena, -b[0], true,
                                want_q, q, olenq, lenq,
                                want_r, r, olenr, lenr);
        return;
    }
// Now the absolute value of b will be at least 2 digits of 64-bits with the
// high digit non-zero. I need to make a copy of it because I will scale
// it during long division.
    std::uint64_t* bb = nullptr;
    std::size_t lenbb = lenb;
    bool bNegative = negative(b[lenb-1]);
    if (bNegative)
    {
// In the case that b is negative I will want its absolute value. Especially
// in a multi-thread world I must not disturb or overwrite the input vector,
// so a create a temporary copy of b to negate. In my full 2s complement
// representation negating -2^(64*n-1) would lead to what was supposed to be
// a positive value but it would have its top bit set so it would require
// and extra leading 0. Because the value I generate here is to be treated
// as unsigned this leading top bit does not matter and so the absolute value
// of b fits in the same amount of space that b did with no risk of overflow.
        bb = reserve(lenb);
        olenr = lenb;
        internalNegate(b, lenb, bb);
        if (bb[lenbb-1] == 0) lenbb--;
    }
    else if (b[lenb-1] == 0) lenbb--;
// Now I should look at the dividend. If it is shorter than the divisor
// then I know that the quotient will be zero and the dividend will be the
// remainder. If I had made this test before normalizing the divisor I could
// have needed to worry about the case of (-2^(64n-1))/(2^(64n-1)) where the
// divisor would have had an initial padding zero so would have shown up
// as longer than the dividend but the quotient would have needed to come out
// as 1. But here with the divisor made tidy this test is safe!
    if (lena < lenbb)
    {   if (want_q)
        {   q = reserve(1);
            olenq = 1;
            q[0] = 0;
            lenq = 1;
        }
        if (want_r)
        {   r = reserve(lena);
                    olenr = lena;
            internalCopy(a, lena, r);
            lenr = lena;
        }
        if (bNegative) abandon(bb);
        return;
    }
// Now lena >= lenb >= 2 and I will need to do a genuine long division. This
// will need me to allocate some workspace.
//
// Because I will scale the divisor I need that to be a copy of the
// original data even if that has been positive and so I had not copied
// it yet. I delay creation of that copy until now because that lets my
// avoid a spurious allocation in the various small cases.
    if (!bNegative)
    {   bb = reserve(lenb);
        olenr = lenb;
        internalCopy(b, lenbb, bb);
    }
// If I actually return the quotient I may need to add a leading 0 or -1 to
// make its 2s complement representation valid. Hence the "+2" rather than
// the more obvious "+1" here.
    if (want_q)
    {   lenq = lena - lenb + 2;
        q = reserve(lenq);
        olenq = lenq;
    }
// I will need space where I store something that starts off as a scaled
// copy of the dividend and gradually have values subtracted from it until
// it ends up as the remainder.
    lenr = lena;
    r = reserve(lenr+1);
    bool aNegative = negative(a[lena-1]);
    if (aNegative) internalNegate(a, lena, r);
    else internalCopy(a, lena, r);
#ifdef FASTDIVISION
// Only for an experinment at present!
    fastDivision(r, lenr, bb, lenbb, want_q, q, olenq, lenq);
#else // FASTDIVISION
    unsigned_long_division(r, lenr, bb, lenbb, want_q, q, olenq, lenq);
#endif // FASTDIVISION
// While performing the long division I will have had three vectors that
// were newly allocated. r starts off containing a copy of a but ends up
// holding the remainder. It is rather probable that this remainder will
// often be a distinctly shorter vector than a was. The vector q is only
// created and used if want_q was set, and it ends up holding the quotient.
// finally bb holds the absolute value of the divisor but scaled up by a
// power of 2 so that its leading digit has its top bit set. Well the actual
// remainder is smaller than the divisor and so it will be a closer fit into
// bb than r. So copy it into there so that the allocate/abandon and
// size confirmation code is given less extreme things to cope with.
    if (want_r) internalCopy(r, lenr, bb);
    abandon(r);
    if (want_q)
    {   if (negative(q[lenq-1]))
            q[lenq++] = 0;
        if (aNegative != bNegative) internalNegate(q, lenq, q);
        truncateNegative(q, lenq);
        truncatePositive(q, lenq);
    }
//  else abandon(q);
    if (want_r)
    {   r = bb;
        if (negative(r[lenr-1]))
            r[lenr++] = 0;
        if (aNegative) internalNegate(r, lenr, r);
        truncateNegative(r, lenr);
        truncatePositive(r, lenr);
    }
    else abandon(bb);
}

// During long division I will scale my numbers by shifting left by an
// amount s. I do that in place. The shift amount will be such that
// the divisor ends up with the top bit of its top digit set. The
// dividend will need to extend into an extra digit, and I deal with that
// by returning the overflow word as a result of the scaling function. Note
// that the shift amount will be in the range 0-63.


Digit scale_for_division(std::uint64_t* r,
                                        std::size_t lenr,
                                        int s)
{
// There are two reasons for me to treat a shift by zero specially. The
// first is that it is cheap because no data needs moving at all. But the
// more subtle reason is that if I tried using the general code as below
// that would execute a right shift by 64, which is out of the proper range
// for C++ right shifts. But NOTE that if I shift by zero (which happens if
// my divisor already has the top bit of its top word set) I do not alter
// any memory.
    if (s == 0) return 0;
    Digit carry = 0;
    for (std::size_t i=0; i<lenr; i++)
    {   Digit w = r[i];
        r[i] = (w << s) | carry;
        carry = w >> (64-s);
    }
    return carry;
}

// r = r - b*q*base^(lena-lenb-1).

void multiply_and_subtract(std::uint64_t* r, std::size_t lenr,
                                  Digit q0,
                                  std::uint64_t* b, std::size_t lenb)
{   Digit hi = 0, lo, carry = 1;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q0, hi, hi, lo);
// lo is now the next digit of b*q, and hi needs to be carried up to the
// next one.
        carry = addWithCarry(r[i+lenr-lenb-1], ~lo, carry,
                               r[i+lenr-lenb-1]);
    }
    r[lenr-1] = r[lenr-1] + ~hi + carry;
}

// addBackCorrection() is used when a quotient digit was mis-predicted by
// 1 and I detect that when I calculate r = r - b*q and end up with r negative
// result. I fix things up by decrementing q and going
//         r = r + (b<<(lenr-lenb-1))

void addBackCorrection(std::uint64_t* r, std::size_t lenr,
                              std::uint64_t* b, std::size_t lenb)
{   Digit carry = 0;
    for (std::size_t i=0; i<lenb; i++)
        carry = addWithCarry(r[i+lenr-lenb-1], b[i], carry,
                             r[i+lenr-lenb-1]);
    r[lenr-1] += carry;
}

Digit nextQuotientDigit(std::uint64_t* r,
                               std::size_t &lenr,
                               std::uint64_t* b, std::size_t lenb)
{   Digit q0, r0;
    if (r[lenr-1] == b[lenb-1])
    {   q0 = static_cast<Digit>(-1);
        r0 = r[lenr-2] + b[lenb-1];
// Here perhaps q0 is still an over-estimate by 1?
    }
    else
    {   divide64(r[lenr-1], r[lenr-2], b[lenb-1], q0, r0);
// At this stage q0 may be correct or it may be an over-estimate by 1 or 2,
// but never any worse than that.
//
// The tests on the next lines should detect all case where q0 was in error
// by 2 and most when it was in error by 1.
        Digit hi, lo;
        multiply64(q0, b[lenb-2], hi, lo);
        if (hi > r0 ||
            (hi == r0 && lo > r[lenr-3])) q0--;
    }
//
// Now I want to go "r = r - b*q0*2^(64*(lenr-lenb));" so that r
// is set to an accurate remainder after using q0 as (part of) the
// quotient. This may carry an overshoot into atop and if so I will need
// to reduce q0 again and compensate.
//
    multiply_and_subtract(r, lenr, q0, b, lenb);
    if (negative(r[lenr-1]))
    {   q0--;
        addBackCorrection(r, lenr, b, lenb);
    }
    lenr--;  // a is now one digit shorter.
    return q0;
}

// r is an unsigned number. Shift right (in place) by s bits, where s
// is in the range 0 - 63. The bits shifted out to the right should all
// be zero.

void unscale_for_division(std::uint64_t* r, std::size_t &lenr, int s)
{   if (s != 0)
    {   Digit carry = 0;
        std::size_t i = lenr-1;
        for (;;)
        {   Digit w = r[i];
            r[i] = (w >> s) | carry;
            carry = w << (64-s);
            if (i == 0) break;
            i--;
        }
    }
    truncateUnsigned(r, lenr);
}

// This function does long division on unsigned values, computing the
// quotient (a/b). In doing so it updates (a) so that at the end it holds
// the remainder. It only fills in a value for the quotient q if want_q is
// true. Note also that this code will scale (b) so that the top bit of its
// highest digit is a "1", so b must be an array that can be overwritten
// without disturbing code elsewhere. Well if the top bit is already set
// I promise I will not corrupt it, so in that case b still has to be
// uint64_t* not const uint64_t* but it will not be overwritten.

void unsigned_long_division(std::uint64_t* a,
                                   std::size_t &lena,
                                   std::uint64_t* b, std::size_t &lenb,
                                   bool want_q, std::uint64_t* q,
                                   std::size_t &olenq, std::size_t &lenq)
{
// I will multiply a and b by a scale factor that gets the top digit of "b"
// reasonably large. The value stored in "a" can become one digit longer,
// but there is space to store that.
//
// The scaling is done here using a shift, which seems cheaper to sort out
// then multiplication by a single-digit value.
    int ss = nlz(b[lenb-1]);
// When I scale the dividend expands into an extra digit but the scale
// factor has been chosen so that the divisor does not.
    a[lena] = scale_for_division(a, lena, ss);
    lena++;
    uint64_t w = scale_for_division(b, lenb, ss);
    arithlib_assert(w == 0);
    lenq = lena-lenb; // potential length of quotient.
    std::size_t m = lenq-1;
    for (;;)
    {   Digit qd = nextQuotientDigit(a, lena, b, lenb);
// If I am only computing the remainder I do not need to store the quotient
// digit that I have just found.
        if (want_q) q[m] = qd;
        if (m == 0) break;
        m--;
    }
    unscale_for_division(a, lena, ss);
// The quotient is OK correct now but has been computed as an unsigned value
// so if its top digit has its top bit set I need to prepend a zero;
    if (want_q)
    {   if (negative(q[lenq-1])) q[lenq++] = 0;
        else truncateUnsigned(q, lenq);
    }
    if (negative(a[lena-1])) a[lena++] = 0;
    else truncateUnsigned(a, lena);
}

// Use unsigned_long_division when all that is required is the remainder.
// Here a>b and b is at least 2 words. The code corrupts b and replaces
// a with remainder(a, b).

void unsigned_long_remainder(std::uint64_t* a,
                                    std::size_t &lena,
                                    std::uint64_t* b, std::size_t &lenb)
{   std::size_t w;
    unsigned_long_division(a, lena, b, lenb,
                           false, nullptr, w, w);
}

std::intptr_t Quotient::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirmSize(q, olenq, lenq);
}

std::intptr_t Quotient::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
// Making division by 1 a special case is merely optimisation. However
// I have to copy the bignum (because I do not keep reference counts).
    {   std::size_t n = numberSize(a);
        std::uint64_t* p = reserve(n);
        std::memcpy(p, a, n*sizeof(Digit));
        return confirmSize(p, n, n);
    }
    case -1:
// Making division by -1 a special case tidies up the code within
// the function division() because when -2^(64*K) is divided by -1 the
// resulting bignum needs to be one word longer than the input. That is the
// only case where division causes a number to grow, so disposing of it
// early makes storage allocation for all the other cases just a little
// easier.
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             false, r, olenr, lenr);
    return confirmSize(q, olenq, lenq);
}

// A fixnum divided by a bignum ought always to yield 0, except that
// maybe -0x8000000000000000} / {0,0x8000000000000000) => -1

std::intptr_t Quotient::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b)==1 &&
        b[0]==-static_cast<Digit>(a))
        UNLIKELY
        return intToHandle(-1);
    return intToHandle(0);
}

// unpleasantly -0x8000000000000000 / -1 => a bignum

std::intptr_t Quotient::op(SignedDigit a, SignedDigit b)
{   if (b==-1 && a == MIN_FIXNUM) UNLIKELY return intToBignum(-a);
    else return intToHandle(a / b);
}

std::intptr_t Remainder::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirmSize(r, olenr, lenr);
}

std::intptr_t Remainder::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
    case -1:   // avoid calling division() in this case.
        return intToHandle(0);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    return confirmSize(r, olenr, lenr);
}

std::intptr_t Remainder::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b)==1 &&
        b[0]==-static_cast<Digit>(a)) return intToHandle(0);
    return intToHandle(a);
}

std::intptr_t Remainder::op(SignedDigit a, SignedDigit b)
{   return intToHandle(a % b);
}

std::intptr_t Mod::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w = confirmSize(r, olenr, lenr);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    if (w != intToHandle(0) &&
        ((a_neg && !b_neg) || (!a_neg && b_neg)))
    {   if (storedAsFixnum(w)) return Plus::op(intOfHandle(w), b);
        else return Plus::op(vectorOfHandle(w), b);
    }
    else return w;
}

// When b is positive Mod uses directed rounding as for Floor, while if
// b is negative it is as for Ceiling, so that the sign of (P mod Q) always
// matches that of Q.

std::intptr_t Mod::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
    case -1:
        return intToHandle(0);
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             false, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w = confirmSize(r, olenr, lenr);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = (b < 0);
    if (w != intToHandle(0) &&
        ((a_neg && !b_neg) || (!a_neg && b_neg)))
    {   if (storedAsFixnum(w)) return Plus::op(intOfHandle(w), b);
        else return Plus::op(vectorOfHandle(w), b);
    }
    else return w;
}

std::intptr_t Mod::op(SignedDigit a, std::uint64_t* b)
{   if (a==0 ||
        (numberSize(b)==1 &&
         b[0]==-static_cast<Digit>(a))) return intToHandle(0);
    bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if ((a_neg && !b_neg) || (!a_neg && b_neg))
        return Plus::op(a, b);
    else return intToHandle(a);
}

std::intptr_t Mod::op(SignedDigit a, SignedDigit b)
{   int64_t r = a%b;
    if (r!=0 &&((a<0 && b>0) || (a>0 && b<0))) r += b;
    return intToHandle(r);
}

// Here if division is not exact the quotient is rounded towards -infinity. 

std::intptr_t Floor::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && a_neg != b_neg) return Sub1::op(w1);
    else return w1;
}

std::intptr_t Floor::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
        return vectorToHandle(a);
    case -1:
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = b < 0;
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && a_neg != b_neg) return Sub1::op(w1);
    else return w1;
}

// An edge case here is a-=2^63 and b=+2^63 where the exact quotient
// is -1. In all other cases the absolute value of a is less than that
// of be and the truncated quotient is zero. Then if a and b have the
// same signs the required result is zero, otherwise it will be -1.
// Hah - happily the edge case comes out right in the wash!

std::intptr_t Floor::op(SignedDigit a, std::uint64_t* b)
{   bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if (a_neg == b_neg) return intToHandle(0);
    else return intToHandle(-1);
}

std::intptr_t Floor::op(SignedDigit a, SignedDigit b)
{   int64_t q = a/b;
    int64_t r = a%b;
    if (r == 0 ||
        (a < 0) == (b < 0)) return intToHandle(q);
// q-1 can not overflow here because the only way that q could have
// ended up as INT64_MIN would be for that to have been the value of
// a and b bad been +1. But then the remainder would have been zero
// so the easier exit would have been taken.
    else return intToHandle(q-1);
}

std::intptr_t Ceiling::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = negative(b[lenb-1]);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && (a_neg == b_neg)) return Add1::op(w1);
    else return w1;
}

std::intptr_t Ceiling::op(std::uint64_t* a, SignedDigit b)
{   switch (b)
    {
    case 1:
        return vectorToHandle(a);
    case -1:
        return Minus::op(a);
    }
    std::size_t lena = numberSize(a);
    bool a_neg = negative(a[lena-1]);
    bool b_neg = b < 0;
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit bb[1] = {static_cast<Digit>(b)};
    division(a, lena, bb, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    intptr_t w1 = confirmSize(q, olenq, lenq);
    intptr_t w2 = confirmSize(r, olenr, lenr);
    if (w2 != intToHandle(0) && (a_neg == b_neg)) return Add1::op(w1);
    else return w1;
}

std::intptr_t Ceiling::op(SignedDigit a, std::uint64_t* b)
{   if (numberSize(b) == 1 &&
        a == -static_cast<int64_t>(b[0])) return intToHandle(-1);
    bool a_neg = (a < 0);
    bool b_neg = negative(b[numberSize(b)-1]);
    if (a_neg == b_neg) return intToHandle(1);
    else return intToHandle(0);
}

std::intptr_t Ceiling::op(SignedDigit a, SignedDigit b)
{   int64_t q = a/b;
    int64_t r = a%b;
// if b=-1 or b=+1 then the remainder will be zero. In all other
// cases q will be small enough not to overflow when incremented.
    if (r!=0 && (a<0)==(b<0)) q++;
    return intToHandle(q);
}


#ifdef LISP

// In LISP mode I provide a function that returns both quotient and
// remainder. In the other two modes I support the same idea but
// as a function that delivers the quotient as its result and saves
// the remainder via an additional argument.

std::intptr_t Divide::op(std::uint64_t* a, std::uint64_t* b)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

std::intptr_t Divide::op(std::uint64_t* a, SignedDigit bb)
{   switch (bb)
    {
    case 1:
        return cons(vectorToHandle(a), intToHandle(0));
    case -1:
        return cons(Minus::op(a), intToHandle(0));
    }
    std::size_t lena = numberSize(a);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit b[1] = {static_cast<Digit>(bb)};
    division(a, lena, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

std::intptr_t Divide::op(SignedDigit aa, std::uint64_t* b)
{   std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit a[1] = {static_cast<Digit>(aa)};
    division(a, 1, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

std::intptr_t Divide::op(SignedDigit aa, SignedDigit bb)
{   std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    Digit a[1] = {static_cast<Digit>(aa)};
    Digit b[1] = {static_cast<Digit>(bb)};
    division(a, 1, b, 1,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    std::intptr_t rr = confirmSize(r, olenr, lenr);
    std::intptr_t qq = confirmSize_x(q, olenq, lenq);
    return cons(qq, rr);
}

#else // LISP

std::intptr_t Divide::op(std::uint64_t* a, std::uint64_t* b,
                                std::intptr_t &rem)
{   std::size_t lena = numberSize(a);
    std::size_t lenb = numberSize(b);
    std::uint64_t* q = nullptr;
    std::uint64_t* r = nullptr;
    std::size_t olenq, olenr, lenq, lenr;
    division(a, lena, b, lenb,
             true, q, olenq, lenq,
             true, r, olenr, lenr);
    rem = confirmSize(r, olenr, lenr);
    return confirmSize_x(q, olenq, lenq);
}

#endif // LISP

// a = a - b*q.

bool reduce_for_gcd(std::uint64_t* a, std::size_t lena,
                           Digit q,
                           std::uint64_t* b, std::size_t lenb)
{   Digit hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(b[i], q, hi1, lo);
        hi1 += subtractWithBorrow(a[i], hi, a[i]);
        borrow = subtractWithBorrow(a[i], lo, borrow, a[i]);
        hi = hi1;
    }
// In the cases where this is used the difference |a - q*b| should be
// less than a. Well if q was computed accurately then it will be less
// than b. And if q is large it will at least me much less than a. So I
// am confident that testing the top bit if a[lena-1] after the subtraction
// will be a reliable test for overshoot. I might want to formalize this
// argument a bit better!
    if (lena > lenb) a[lena-1] = a[lena-1] - hi - borrow;
    return negative(a[lena-1]);
}

// I provide a function that accesses (b<<shift)[n]. Note that the
// valid index values n will from from 0 up to and including lenb.

Digit shiftedDigit(std::uint64_t* b, std::size_t lenb,
                                  int shift, std::size_t n)
{   if (n == 0) return b[0]<<shift;
    else if (n == lenb) return b[lenb-1]>>(64-shift);
    else return (b[n]<<shift) | (b[n-1]>>(64-shift));
}

// The next function performs a = a = b*(q<<shift), but
// it computes it more as a = a - (b<<shift)*q.
// It will be used with 0 < shift < 64, ie only when a genuine shift
// between digits is required.
bool shifted_reduce_for_gcd(std::uint64_t* a, std::size_t lena,
                                   Digit q,
                                   std::uint64_t* b, std::size_t lenb,
                                   int shift)
{   Digit hi = 0, hi1, lo, borrow = 0;
    for (std::size_t i=0; i<=lenb; i++)
    {   multiply64(shiftedDigit(b, lenb, shift, i), q, hi1, lo);
        hi1 += subtractWithBorrow(a[i], hi, a[i]);
        borrow = subtractWithBorrow(a[i], lo, borrow, a[i]);
        hi = hi1;
    }
// In the cases where this is used the difference |a - q*b| should be
// less than a. Well if q was computed accurately then it will be less
// than b. And if q is large it will at least me much less than a. So I
// am confident that testing the top bit if a[lena-1] after the subtraction
// will be a reliable test for overshoot. I might want to formalize this
// argument a bit better!
    if (lena > lenb+1) a[lena-1] = a[lena-1] - hi - borrow;
    return negative(a[lena-1]);
}

// Here we compute r = u*a - v*b, where lenr >= min(lena, lenb). This
// is for use in Lehmer reductions.
// In general this will be used as in
//    ua_minus_vb(a, u1, b, v1, temp);
//    ua_minus_vb(a, u2, b, v2, a);
//    copy from temp to b
// so note that the destination may be the same vector as one of the inputs.
// This will only be used when a and b are almost the same length. I leave
// a result of length lena even though I very much expect that in at least
// almost all cases the result will be almost 128 bits smaller!

bool ua_minus_vb(std::uint64_t* a, std::size_t lena,
                        Digit u,
                        std::uint64_t* b, std::size_t lenb,
                        Digit v,
                        std::uint64_t* r, std::size_t &lenr)
{   Digit hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
// I wish to compute r = u A - v B where all values are treated as
// unsigned save that if the result underflows (ie would be negative if
// computed perfectly) I must return a "borrow" value.
//
// At one stage I called this going in effect
//   if (v < 0) ua_minus_vb(..., -v, ...);
// and in an extra case v started off as INT64_MIN. As an unsigned value
// (-v) is properly in range, but if I performed the negation as signed
// arithmetic it counted as an overflow since the result has just the
// top bit set and has value (INT64_MAX+1). In that case a "sufficiently
// clever" C++ compiler could and did argue that the value of v passed here
// would have its top bit zero (since the only way that might not be the
// case would involve overflow and hence represented undefined behavious).
// So in some sense V simultaneously had the value 0x8000000000000000 and
// also for the purposes of optimisation could be assumed to have its top
// bit zero. In a manner that at present I do not fully understand this
// could lead the code here to return a result that was not the one I
// wanted. Altering the call to read
//   if (v < 0) ua_minus_ub(..., -static_cast<uint64_t>(v), ...);
// so that the negation was performed on an unsigned value where C++
// does consider the result defined left my code behaving as it had
// with earlier released of the C++ compiler that were less clever.
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
// hia is the high part of a product so carrying 1 into it can not cause it
// to overflow. Just!
        hia += addWithCarry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += addWithCarry(lob, cb, lob);
        borrow = subtractWithBorrow(loa, lob, borrow, r[i]);
        ca = hia;
        cb = hib;
    }
    lenr = lenb;
// I want to report in whether u*a-v*b was negative. To do that I will
// first note that the result that I am computing should be less than the
// value of a, so I do not get too much messy overflow. I will look at the
// borrow out from the top word of the result.
    if (lena > lenb)
    {   multiply64(a[lena-1], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        borrow = subtractWithBorrow(loa, cb, borrow, r[lena-1]);
        lenr = lena;
        return negative(hia - borrow);
    }
    return negative(ca - cb - borrow);
}

// Since the code here is quite short I will also provide a version
// for r = -u*a + b*v;
// Again this supposes that a is at least as long as b.

bool minus_ua_plus_vb(std::uint64_t* a, std::size_t lena,
                             Digit u,
                             std::uint64_t* b, std::size_t lenb,
                             Digit v,
                             std::uint64_t* r, std::size_t &lenr)
{   Digit hia, loa, ca = 0, hib, lob, cb = 0, borrow = 0;
    for (std::size_t i=0; i<lenb; i++)
    {   multiply64(a[i], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        multiply64(b[i], v, hib, lob);
        hib += addWithCarry(lob, cb, lob);
        borrow = subtractWithBorrow(lob, loa, borrow, r[i]);
        ca = hia;
        cb = hib;
    }
    lenr = lenb;
    if (lena > lenb)
    {   multiply64(a[lena-1], u, hia, loa);
        hia += addWithCarry(loa, ca, loa);
        borrow = subtractWithBorrow(cb, loa, borrow, r[lena-1]);
        lenr = lena;
// It will be perfectly reasonable for hia to be zero and borrow to be zero
// and hence the overall result positive.
        return negative(- hia - borrow);
    }
    return negative(cb - ca - borrow);
}

// gcd_reduction starts with a > b and |b| >=2. It must reset a and
// b (and their lengths) to be smaller. The basic Euclidean algorithm
// would go
//    a = a % b;   // otherwise a = a-q*b; for some useful value of q
//                 // and then if q was "too large" go a = |a|;
//    swap(a, b);
// but a Lehmer-style scheme can go distinctly faster overall.

void gcd_reduction(std::uint64_t*& a, std::size_t &lena,
                          std::uint64_t*& b, std::size_t &lenb,
                          std::size_t &olena, std::size_t &olenb,
                          std::uint64_t*& temp, std::size_t &lentemp)
{
// I will start by collecting high bits from a and b. If I collect the
// contents of the top 3 words (ie 192 bits in all) then I will be able
// to normalize that to get 128 bits to work with however the top bits
// of a and b lie within the words.
    Digit a0=a[lena-1], a1=a[lena-2], a2=(lena>2 ? a[lena-3] : 0);
    int lza = nlz(a0);
    Digit b0=b[lenb-1], b1=b[lenb-2], b2=(lenb>2 ? b[lenb-3] : 0);
    int lzb = nlz(b0);
// I will sort out how many more bits are involved in a than in b. If
// this number is large I will invent a number q of the form q=q0*2^q1
// with q0 using almost all of 64 bits and go "a = a - q*b;". This
// will involve "virtually shifting" b left by q1 bits so what I actually
// do is "a = a = q0*(b<<q1);". It will be obvious that the idea is that
// q should be chosen so that the new value of a is as small as possible.
// Given that q will be an estimate for the correct quotient and so may
// occasionally be incorrect I will allow that it might in fact be
// too large. In such a case the value of a computed will end up negative,
// in which caseI do a final step that goes "a = -a;" to fix that. If I
// manage to make q a round-to-nearest approximation to the quotient this
// might happen a significant fraction of the time, ideally getting me
// 1 extra bit in reduction in the size of a for each step.
// If the estimated quotient is accurate enough the this will leave
// a < b and by swapping a and b we have a new pair ready to continue from.
    SignedDigit diff = 64*(lena-lenb) + lzb - lza;
// If however the length-difference between a and b is small a subtraction
// "a = a - q0*(b<<0);" would often find q0 rather small and completing
// the remainder sequence would take many steps. So in such cases I take
// the top 128 bits of a and (128-diff) bits from b and start forming
// a remainder sequence using 128-bit arithmetic until a term in it
// fits in 64-bits. If the last 2 terms in that remainder sequence are
// p and q (with p having >64 bits and q <= 64 bits) I can have
//    p = |Ua - Vb|,    q = |-Wa + Xb|.
// where U, V, W and X should all fit in 64-bits. That gives me a new
// pair of values - expected to be up to 128-bits shorter - to continue
// my remainder sequence. Because my stopping condition for the
// approximate remainder sequence is not guaranteed perfect I can not
// be certain that q < p, so I will need to compare the values and
// swap as appropriate.
//
    if (diff < 60)
    {
// Try for Lehmer. The pair of values that will be 2-word surrogates
// for a and b here will be the top 128 bits of a and however many bits of
// b align with that. However if a has only 2 digits then I must NOT shift it
// left, because that would make it seem to have a power of 2 as a factor
// beyond any real such factors.
// It could be that lenb < lena, but because a and b different in lengths
// by at most 60 bits in that case lenb==lena-1. So adjust values so as to
// align.
        if (lena != lenb)
        {   b2 = b1;
            b1 = b0;
            b0 = 0;
        }
        if (lena > 2)
        {   a0 = a0<<lza;
            if (lza!=0) a0 |= (a1>>(64-lza));
            a1 = a1<<lza;
            if (lza!=0) a1 |= (a2>>(64-lza));
            b0 = b0<<lza;
            if (lza!=0) b0 |= (b1>>(64-lza));
            b1 = b1<<lza;
            if (lza!=0) b1 |= (b2>>(64-lza));
        }
// I will maintain an identity
//          a = ua*A + va*B
//          b = ub*A + vb*B
// where A and B are the initial values in my remainder sequence and a and b
// are working ones calculated along the way. Note horribly well here that
// I am keeping these values as signed... but the code U have above that
// calculates u*a-b*v will take unsigned inputs!
        SignedDigit ua = 1, va = 0, ub = 0, vb = 1;
        while (b0!=0 || b1!=0)
        {   Digit q;
// Here I want to set q = {a0,a1}/{b0,b1}, and I expect that the answer
// is a reasonably small integer. But it could potentially be huge.
// At least I have filtered away the possibility {b0,b1}={0,0}.
// I will grab the top 64 bits of a and the top corresponding bits of b,
// because then I can do a (cheap) 64-by-64 division.
            int lza1 = a0==0 ? 64+nlz(a1) : nlz(a0);
            int lzb1 = b0==0 ? 64+nlz(b1) : nlz(b0);
            if (lzb1 > lza1+60) break; // quotient will be too big
            Digit ahi, bhi;
            if (lza1 == 0) ahi = a0;
            else if (lza1 < 64) ahi = (a0<<lza1) | (a1>>(64-lza1));
            else if (lza1 == 64) ahi = a1;
            else ahi = a1<<(lza1-64);
            if (lza1 == 0) bhi = b0;
            else if (lza1 < 64) bhi = (b0<<lza1) | (b1>>(64-lza1));
            else if (lza1 == 64) bhi = b1;
            else bhi = b1<<(lza1-64);
            if (bhi == 0) break;
// q could end up and over-estimate for the true quotient because bhi has
// been truncated and so under-represents b. If that happens then a-q*b will
// end up negative.
            q = ahi/bhi;
            if (negative(q)) break;
// Now I need to go
//              ua -= q*va;
//              ub -= q*vb;
//              {a0,a1} -= q*{b0,b1}
// Then if a is negative I will negate a and ua and ub.
// Finally, if (as I mostly expect) now a<b I swap a<=>b, ua<=>ub and va<=>vb
// If I would get an overflow in updating ua or ub I will break out of the
// loop.
            SignedDigit h;
            Digit l1, l2;
            signedMultiply64(q, va, h, l1);
            if (static_cast<Digit>(h) + (l1>>63) != 0) break;
// There could be overflow in the following subtraction... So I check
// if that was about to happen and break out of the loop if so.
            if (ua >= 0)
            {   if (ua - INT64_MAX >= static_cast<SignedDigit>(l1)) break;
            }
            else if (ua - INT64_MIN <= static_cast<SignedDigit>(l1)) break;
            signedMultiply64(q, vb, h, l2);
            if (static_cast<Digit>(h) + (l2>>63) != 0) break;
            if (ub >= 0)
            {   if (ub - INT64_MAX > static_cast<SignedDigit>(l2)) break;
            }
            else if (ub - INT64_MIN < static_cast<SignedDigit>(l2)) break;
// I must either update both or neither of ua, ub.
            ua -= l1;
            ub -= l2;
            Digit hi, lo;
            multiply64(q, b1, hi, lo);
            hi += subtractWithBorrow(a1, lo, a1);
            Digit borrow = subtractWithBorrow(a0, hi, a0);
            borrow += subtractWithBorrow(a0, q*b0, a0);
// Now borrow!=0 if a had become negative
            if (borrow != 0)
            {   if ((a1 = -a1) == 0) a0 = -a0;
                else a0 = ~a0;
                ua = -ua;
                ub = -ub;
            }
            if (b0 > a0 ||
                (b0 == a0 && b1 > a1))
            {   std::swap(a0, b0);
                std::swap(a1, b1);
                std::swap(ua, va);
                std::swap(ub, vb);
            }
        }
// Ahah now I am almost done. I want to go
//          a' = |ua*a + ub*b|;
//          b' = |va*a + vb*b|;
//          if (a' > b') [a, b] = [a', b'];
//          else [a, b] = [b', a'];
// and in the first two lines I need to be aware that one or the other
// (but not both) or ua and ub will be negative so I really have a subtraction,
// and similarly for v1, vb.
        if (temp == nullptr)
        {   temp = reserve(lena>lenb ? lena : lenb);
                        }
// The static cast here is in case ua (etc) have the negative value INT64_MIN
// because if I negate that before turning to an unsigned value to pass
// to the sub-function that would count as overflow and in consequence the
// behaviour of everthing here would become undefined.
        if (ub < 0)
        {   if (ua_minus_vb(a, lena, ua, b, lenb,
                            -static_cast<uint64_t>(ub), temp, lentemp))
                internalNegate(temp, lentemp, temp);
        }
        else
        {   if (minus_ua_plus_vb(a, lena, -static_cast<uint64_t>(ua),
                                 b, lenb, ub, temp, lentemp))
                internalNegate(temp, lentemp, temp);
        }
        truncateUnsigned(temp, lentemp);
        if (vb < 0)
        {   if (ua_minus_vb(a, lena, va, b, lenb,
                            -static_cast<uint64_t>(vb), a, lena))
                internalNegate(a, lena, a);
        }
        else
        {   if (minus_ua_plus_vb(a, lena, -static_cast<uint64_t>(va),
                                 b, lenb, vb, a, lena))
                internalNegate(a, lena, a);
        }
        truncateUnsigned(a, lena);
        internalCopy(temp, lentemp, b);
        lenb = lentemp;
        return;
    }
// If I drop through to here I will do a simple reduction. This happens
// either if the initial quotient a/b is huge (over 2^60) or if as I start
// setting up for the Lehmer step I find I can not make enough progress
// with that to be useful. For instance if the next two steps would have
// q=1 and then q=<huge> I can not combine in the huge step to make Lehmer
// style progress and I should drop down and do the "q=1" reduction first
// (followed by the next huge one).
//
// This is the "a = a - q*b;" case.
// Collect the top 128 bits of both a and b.
    b0 = b0<<lzb;
    if (lzb!=0) b0 |= (b1>>(64-lzb));
    b1 = b1<<lzb;
    if (lzb!=0) b1 |= (b2>>(64-lzb));
    a0 = a0<<lza;
    if (lza!=0) a0 |= (a1>>(64-lza));
    a1 = a1<<lza;
    if (lza!=0) a1 |= (a2>>(64-lza));
    a2 = a2<<lza;
// When I have done this b0 will have its top bit set and I will
// want to have a0<b0 because I will be dividing {a0,a1}/b0 and I want the
// quotient to fit within a single 64-bit word.
    if (a0 >= b0)
    {   a2 = (a2>>1) | (a1<<63);
        a1 = (a1>>1) | (a0<<63);
        a0 = a0>>1;
        lza = lza-1;
        diff = diff+1;
    }
    Digit q, r;
// I want to get as close an approximation to the full quotient as I can,
// and a "correction" of the form {a0,a1} -= a0*b1/b0 should do the trick.
    multiply64(a0, b1, q, r);
    divide64(q, r, b0, q, r);
    r = a1 - q;
    if (r > a1) a0--;
    a1 = r;
    divide64(a0, a1, b0, q, r);
// Now I want to go "a = a - q*b*2^(diff-64);". The "-64" there is because
// the quotient I computed in q is essentially to be viewed as a fraction.
// So if diff<=64 I will need to do something special.
    if (diff <= 64)
    {   std::size_t bitsTo_lose = 64 - diff;
// I will shift q right, but doing so in such a way that I try to round to
// nearest.
        if (bitsTo_lose != 0)
        {   q = q >> (bitsTo_lose-1);
            q = (q >> 1) + (q & 1);
        }
// Now just do "a = a-q*b;", then ensure that the result is positive
// and clear away any leading zeros left in its representation.
        if (reduce_for_gcd(a, lena, q, b, lenb))
            internalNegate(a, lena, a);
        truncateUnsigned(a, lena);
    }
    else
    {
// Here I need to do a reduction but the quotient in the step is very large
// so I will use the value of q I have as basically the top 60+ bits of the
// quotient I need but with "diff" bits stuck on the end. If diff is a
// multiple of 64 then this is merely a shift by some whole number of words.
        if ((diff%64) == 0)
        {   std::size_t diffw = diff/64;
            if (reduce_for_gcd(a+diffw-1, lena+1-diffw, q, b, lenb))
                internalNegate(a, lena, a);
            truncateUnsigned(a, lena);
        }
        else
        {   std::size_t diffw = diff/64;
            diff = diff%64;
            if (shifted_reduce_for_gcd(a+diffw-1, lena+1-diffw,
                                       q, b, lenb, diff))
                internalNegate(a, lena, a);
            truncateUnsigned(a, lena);
        }
    }
}

// A bit of stray commentary here:
// The simplest GCD scheme is direct Euclidean with the central loop
// being
//     q = a/b;
//     {a, b} = {b, a - q*b};
// There are those who observe that on average the quotient q will be
// small, so they replace this with
//     {a, b} = {a, a - b};
//     swap a and b if necessary so that a>=b.
// This takes more steps but each is a subtraction not a division/remainder
// operation and so might sometimes be a win.
// A "least-remainder" scheme is
//     q = (a + b/2)/b;
//     {a, b} = {b, |a - q*b|};
// where the calculation of q just means round the quotient to nearest
// rather than truncate it towards zero. At the cost of the extra absolute
// value calculation this will reduce the number of steps. I believe that
// using the Euclidean scheme each step shrinks the inputs by an average of
// about 1.7 bits, while the least remainder scheme shrinks values by
// 2.4 or 2.5 bits per step, ie it saves around 30% of the steps, albeit at
// the cost of some absolute value calculations, which could go some way to
// balance out the savings.
// The quotient q will in general be small. In the case where it is very large
// then calculating it becomes tedious. So in such cases it will make sense
// to calculate a leading-digit approximation to it and reduce using that. A
// step of that nature would be essentially what wa happening in long division
// anyway, but now if the guessed quotient is not perfect all will be well
// because subsequent reduction steps will correct for it automatically.
// A Lehmer-style scheme will be useful when the firts several quotients in a
// sequence will all be small - it consolidates big-number arithmetic over
// what are logically multiple individual reduction steps.


std::intptr_t Gcd::op(std::uint64_t* a, std::uint64_t* b)
{   if (numberSize(b) == 1)
        return Gcd::op(a, static_cast<SignedDigit>(b[0]));
// I will start by making copies of |a| and |b| that I can overwrite
// during the calculation and use part of in my result.
    std::size_t lena = numberSize(a), lenb = numberSize(b);
    std::size_t olena = lena, olenb = lenb;
    if (olena == olenb &&
        // See comments later for an explanation of this!
        negative(a[lena-1]) && negative(b[lenb-1]) &&
        a[lena-1] == b[lenb-1]) olena++;
    std::uint64_t* av = reserve(olena);
    if (negative(a[lena-1])) internalNegate(a, lena, av);
    else internalCopy(a, lena, av);
    std::uint64_t* bv = reserve(olenb);
    if (negative(b[lenb-1])) internalNegate(b, lenb, bv);
    else internalCopy(b, lenb, bv);
    a = av;
    b = bv;
    if (bigUnsignedGreaterp(b, lenb, a, lena))
    {   std::swap(a, b);
        std::swap(lena, lenb);
        std::swap(olena, olenb);
    }
// Now a >= b and both numbers are in freshly allocated memory. I will
// remember the sizes of these two arrays.
// Remove any leading zero digits, and if that reduces the situation to
// a 1-word case handle that specially..
    if (b[lenb-1] == 0) lenb--;
    if (a[lena-1] == 0) lena--;
    if (lenb == 1)
    {   Digit bb = b[0];
        Digit hi = 0, q;
        for (std::size_t i=lena-1;; i--)
        {   divide64(hi, a[i], bb, q, hi);
            if (i == 0) break;
        }
        while (hi != 0)
        {   Digit cc = bb % hi;
            bb = hi;
            hi = cc;
        }
        abandon(a);
        abandon(b);
        return unsignedIntToBignum(bb);
    }
// In some cases performing a reduction will require a workspace vector.
// I will only allocate this as and when first needed.
    std::uint64_t* temp = nullptr;
    std::size_t lentemp = lena;
// Now at last a and b and genuine unsigned vectors without leading digits
// and with a > b. The next line is the key iteration in this whole procedure.
    while (lenb != 1)
    {   gcd_reduction(a, lena, b, lenb, olena, olenb, temp, lentemp);
        if (bigUnsignedGreaterp(b, lenb, a, lena))
        {   std::swap(a, b);
            std::swap(lena, lenb);
            std::swap(olena, olenb);
        }
    }
    if (temp != nullptr) abandon(temp);
// One possibility is that b==0 and then a holds the GCD. There is a
// pathological case where an input was -2^(64*n-1), which fits within n
// words, and the GCD ends up as +2^(64*n-1) which needs an extra word.
// If the other input had been bigger I can copy my result into it and
// survive.. the very messy situation would be if both inputs were
// -2^(64*n-1) so had I worked in the obvious way I would not have enough
// space for the result. To allow for this I arrange that if both inputs
// start off the same size (and ideally I would check if both had a value
// of the form -2^(64*n-1), but doing that check is probably more expensive
// that occasionally over-allocating memory!) I enlarge one of the inputs by
// one word.
    if (b[0] == 0)
    {   if (negative(a[lena-1]))
        {   if (lena == olena)
            {   internalCopy(a, lena, b);
                abandon(a);
                a = b;
                olena = olenb;
            }
            else abandon(b);
            a[lena++] = 0;
        }
        else abandon(b);
        return confirmSize(a, olena, lena);
    }
// If b is not zero here then it represents a value up to 2^64-1, and I can
// complete the GCD by doing a long-by-short remainder and then a short-num
// GCD...
    Digit bb = b[0];
    abandon(b);
    Digit hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, a[i], bb, q, hi);
        if (i == 0) break;
    }
    abandon(a);
    while (hi != 0)
    {   Digit cc = bb % hi;
        bb = hi;
        hi = cc;
    }
    return unsignedIntToBignum(bb);
}

std::intptr_t Gcd::op(std::uint64_t* a, SignedDigit bb)
{
// This case involved doing a long-by-short remainder operation and then
// it reduces to the small-small case. The main problem is the handling of
// negative inputs.
    if (bb == 0)
    {   if (Minusp::op(a)) return Minus::op(a);
        else return vectorToHandle(a);
    }
    Digit b = bb < 0 ? -bb : bb;
    std::size_t lena = numberSize(a);
    bool signa = negative(a[lena-1]);
    Digit hi = 0, q;
    for (std::size_t i=lena-1;; i--)
    {   divide64(hi, (signa ? ~a[i] : a[i]), b, q, hi);
        if (i == 0) break;
    }
// Now if a had been positive we have hi=a%b. If a had been negative we
// have (~a)%b == (-a-1)%b which is about |a|%b -1
    if (signa) hi = (hi+1)%b;
    return Gcd::op(b, hi);
}

std::intptr_t Gcd::op(SignedDigit a, std::uint64_t* b)
{   return Gcd::op(b, a);
}

std::intptr_t Gcd::op(SignedDigit a, SignedDigit b)
{
// Take absolute values of both arguments.
    Digit aa = a < 0 ? -static_cast<Digit>(a) : a;
    Digit bb = b < 0 ? -static_cast<Digit>(b) : b;
// Ensure that aa >= bb
    if (bb > aa) std::swap(aa, bb);
// Do simple Euclidean algorithm
    while (bb != 0)
    {   Digit cc = aa % bb;
        aa = bb;
        bb = cc;
    }
// A messy case is gcd(-MIX_FIXNUM, MIN_FIXNUM) which yields -MIN_FIXNUM
// which is liable to be MAX_FIXNUM+1 and so has to be returned as a bignum.
    return unsignedIntToBignum(aa);
}

// I think I have space-leaks within my code for LCM. For use in
// a system with garbage collection that will not matter (hoorah) but at
// some stage I need to come back here and look harder and tidy things up.

std::intptr_t Lcm::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t g = Gcd::op(a, b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>
                      (vectorToHandle(b), g);
    q = op_dispatch2<Times,std::intptr_t>(vectorToHandle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

std::intptr_t Lcm::op(std::uint64_t* a, SignedDigit b)
{   std::intptr_t g = Gcd::op(a, b);
    std::intptr_t q = op_dispatch2<Quotient,std::intptr_t>(
                          intToHandle(b), g);
    q = op_dispatch2<Times,std::intptr_t>(vectorToHandle(a), q);
    return op_dispatch1<Abs,std::intptr_t>(q);
}

std::intptr_t Lcm::op(SignedDigit a, std::uint64_t* b)
{   return Lcm::op(b, a);
}

std::intptr_t Lcm::op(SignedDigit a, SignedDigit b)
{   std::intptr_t g = Gcd::op(a, b);
// The GCD can only be a bignum if a = b = MIN_FIXNUM.
    if (storedAsFixnum(g))
    {   b = b / intOfHandle(g);
        std::intptr_t q = Times::op(a, b); // possibly a bignum now
        return op_dispatch1<Abs,std::intptr_t>(q);
    }
    else return unsignedIntToBignum(-static_cast<Digit>(MIN_FIXNUM));
}

// Support for calculations modulo some integer value...

// Some of these NEED to be inline, so that they are shared across all
// uses...

const int modulus_32 = 0;
const int modulus_64 = 1;
const int modulus_big = 2;
// On Windows these thread-locals may introduce serious overhead. I
// will worry about that later if needbe.
thread_local inline int modulusSize = 0;
thread_local inline Digit smallModulus = 2;

// When I tried "thread_local inline std::vector<T> V;" I got complaints
// about the TLS init function being multiply defined at least on one of
// the platforms I was interested in, so I use a slightly more contorted
// code style that seems to survive better...

std::vector<Digit>& largeModulusVector()
{   static thread_local std::vector<Digit> v;
    return v;
}

std::uint64_t* largeModulus()
{   return 1 + reinterpret_cast<std::uint64_t*>(largeModulusVector().data());
}

std::intptr_t value_of_currentModulus()
{   if (modulusSize == modulus_big)
    {   std::size_t n = numberSize(largeModulus());
        std::uint64_t* r = reserve(n);
        std::memcpy(r, largeModulus(), n*sizeof(Digit));
        return confirmSize(r, n, n);
    }
    else return intToHandle(smallModulus);
}

std::intptr_t SetModulus::op(SignedDigit n)
{   if (n < 1)
        UNLIKELY
        return (std::intptr_t)aerror("Invalid arg to set-modulus",
                                      intToHandle(n));
    std::intptr_t r = value_of_currentModulus();
    smallModulus = n;
    if (n <= 0xffffffffU) modulusSize = modulus_32;
    else modulusSize = modulus_64;
    return r;
}

std::intptr_t SetModulus::op(std::uint64_t* n)
{   if (!Plusp::op(n))
        UNLIKELY
        return (std::intptr_t)aerror("Invalid arg to set-modulus",
                                      vectorToHandle(n));
    std::intptr_t r = value_of_currentModulus();
    std::size_t lenn = numberSize(n);
    std::size_t bytes = (lenn+1)*sizeof(Digit);
    if (bytes > largeModulusVector().size())
        largeModulusVector().resize(bytes);
    std::memcpy(largeModulusVector().data(), &n[-1], bytes);
    modulusSize = modulus_big;
    return r;
}

std::intptr_t ModularNumber::op(SignedDigit a)
{   if (a >= 0)
    {   if (modulusSize == modulus_big) return intToHandle(a);
        else return intToHandle(a % smallModulus);
    }
    if (modulusSize == modulus_big) return Plus::op(largeModulus(), a);
    else
    {   a = a % smallModulus;
        if (a < 0) a += smallModulus;
        return intToHandle(a);
    }
}

std::intptr_t ModularNumber::op(std::uint64_t* a)
{   if (Minusp::op(a))
    {   std::intptr_t r = Remainder::op(a, largeModulus());
        if (Minusp::op(r))
        {   std::intptr_t r1 =
                op_dispatch1<Plus,std::intptr_t>(r, largeModulus());
            abandon(r);
            return r1;
        }
        else return r;
    }
    else return Remainder::op(a, largeModulus());
}

std::intptr_t ModularPlus::op(SignedDigit a, SignedDigit b)
{   Digit ua = a, ub = b;
// Because a and b are 64-bit signed values and they should be positive,
// their sum will fit within a 64-bit unsigned integer, but if the modulus
// is large it could be just a 1-word bignum...
    if (modulusSize == modulus_big)
    {   Digit r = ua + ub;
        if (numberSize(largeModulus()) == 1 &&
            r >= largeModulus()[0]) r -= largeModulus()[0];
        return unsignedIntToBignum(r);
    }
    Digit r = ua + ub;
    if (r >= smallModulus) r -= smallModulus;
    return intToHandle(static_cast<SignedDigit>(r));
}

std::intptr_t ModularPlus::op(SignedDigit a, std::uint64_t* b)
{
// One of the inputs here is a bignum, and that can only be valid if we
// have a large modulus.
    if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad arg for modular-plus",
                                      vectorToHandle(b));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq,bool>(r, largeModulus()))
    {   std::intptr_t r1 =
            op_dispatch1<Difference,std::intptr_t>(r, largeModulus());
        abandon(r);
        return r1;
    }
    else return r;
}

std::intptr_t ModularPlus::op(std::uint64_t* a, SignedDigit b)
{   return ModularPlus::op(b, a);
}

std::intptr_t ModularPlus::op(std::uint64_t* a,
                                     std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad arg for modular-plus",
                                      vectorToHandle(a));
    std::intptr_t r = Plus::op(a, b);
    if (op_dispatch1<Geq, bool>(r, largeModulus()))
    {   std::intptr_t r1 =
            op_dispatch1<Difference,std::intptr_t>(r, largeModulus());
        abandon(r);
        return r1;
    }
    else return r;
}

std::intptr_t ModularDifference::op(SignedDigit a, SignedDigit b)
{   if (a >= b) return intToHandle(a - b);
    if (modulusSize == modulus_big) return Plus::op(largeModulus(), a - b);
    else return intToHandle(smallModulus - b + a);
}

std::intptr_t ModularDifference::op(SignedDigit a, std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad arg for modular-plus",
                                      vectorToHandle(b));
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 =
        op_dispatch1<RevDifference,std::intptr_t>(r, largeModulus());
    abandon(r);
    return r1;
}

std::intptr_t ModularDifference::op(std::uint64_t* a, SignedDigit b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad arg for modular-plus",
                                      vectorToHandle(a));
    return Difference::op(a, b);
}

std::intptr_t ModularDifference::op(std::uint64_t* a, std::uint64_t* b)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad arg for modular-plus",
                                      vectorToHandle(a));
    if (Geq::op(a, b)) return Difference::op(a, b);
    std::intptr_t r = Difference::op(b, a);
    std::intptr_t r1 =
        op_dispatch1<RevDifference,std::intptr_t>(r, largeModulus());
    abandon(r);
    return r1;
}


std::intptr_t ModularTimes::op(SignedDigit a, SignedDigit b)
{   switch (modulusSize)
    {   case modulus_32:
            return intToHandle((static_cast<Digit>(a)* 
                                  static_cast<Digit>(b)) %
                                 smallModulus);
        case modulus_64:
        {   Digit hi, lo, q, r;
            multiply64(static_cast<Digit>(a),
                       static_cast<Digit>(b),
                       hi, lo);
            divide64(hi, lo, smallModulus, q, r);
            return intToHandle(r);
        }
        default:
        case modulus_big:
        {   std::intptr_t w = Times::op(a, b);
            std::intptr_t r =
                op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
            abandon(w);
            return r;
        }
    }
}

std::intptr_t ModularTimes::op(SignedDigit a, std::uint64_t* b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r =
        op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
    abandon(w);
    return r;
}

std::intptr_t ModularTimes::op(std::uint64_t* a, SignedDigit b)
{   return ModularTimes::op(b, a);
}

std::intptr_t ModularTimes::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t w = Times::op(a, b);
    std::intptr_t r =
        op_dispatch1<Remainder,std::intptr_t>(w, largeModulus());
    abandon(w);
    return r;
}


std::intptr_t ModularExpt::op(SignedDigit a, SignedDigit b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

std::intptr_t ModularExpt::op(SignedDigit a, std::uint64_t* b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

std::intptr_t ModularExpt::op(std::uint64_t* a, SignedDigit b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}

std::intptr_t ModularExpt::op(std::uint64_t* a, std::uint64_t* b)
{   return (std::intptr_t)aerror("incomplete ModularExpt");
}


std::intptr_t ModularQuotient::op(SignedDigit a, SignedDigit b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

std::intptr_t ModularQuotient::op(SignedDigit a, std::uint64_t* b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

std::intptr_t ModularQuotient::op(std::uint64_t* a, SignedDigit b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}

std::intptr_t ModularQuotient::op(std::uint64_t* a, std::uint64_t* b)
{   std::intptr_t recip_b = ModularReciprocal::op(b);
    std::intptr_t r;
    if (storedAsFixnum(recip_b))
        r = ModularTimes::op(a, intOfHandle(recip_b));
    else r = ModularTimes::op(a, vectorOfHandle(recip_b));
    abandon(recip_b);
    return r;
}


std::intptr_t ModularMinus::op(SignedDigit a)
{   if (a == 0) return intToHandle(a);
    if (modulusSize == modulus_big)
        return Difference::op(largeModulus(), a);
    else return intToHandle(smallModulus - a);
}

std::intptr_t ModularMinus::op(std::uint64_t* a)
{   if (modulusSize != modulus_big)
        UNLIKELY
        return (std::intptr_t)aerror("bad argument for modular-minus",
                                      vectorToHandle(a));
    return Difference::op(largeModulus(), a);
}

std::intptr_t generalModularReciprocal(std::intptr_t aa,
                                              bool safe=false)
{
// I believe that this could be speeded up significantly in cases where
// the modulus is huge by using a Lehmer-style process as in the simpler
// GCD code. Also it could save memory turnover by re-using the space
// from intermediate results. At least for now I will be happy if I just
// implement a version that actually works!
    intptr_t a = vectorToHandle(largeModulus());
    intptr_t b = aa;
    intptr_t x = intToHandle(0);
    intptr_t y = intToHandle(1);
    while (b != intToHandle(1))
    {   intptr_t w, t;
        if (b == intToHandle(0))
        {   if (safe) return nil;
            else
                UNLIKELY
                return (std::intptr_t)aerror(
                    "non-prime modulus in modular-reciprocal");
        }
        w = Quotient::op(a, b);
        t = b;
        b = Difference::op(a, Times::op(a, w));
        a = t;
        t = y;
        y = Difference::op(x, Times::op(y, w));
        x = t;
    }
    if (Minusp::op(y)) y = Plus::op(y, vectorToHandle(largeModulus()));
    return y;
}

std::intptr_t ModularReciprocal::op(SignedDigit aa)
{   if (aa <= 0)
        UNLIKELY
        return (std::intptr_t)aerror("bad argument to modular-reciprocal",
                                      intToHandle(aa));
    else if (modulusSize == modulus_big)
        return generalModularReciprocal(intToHandle(aa));
    SignedDigit a = smallModulus,
                 b = aa,
                 x = 0,
                 y = 1;
    while (b != 1)
    {   Digit w, t;
        if (b == 0)
            UNLIKELY
            return (std::intptr_t)aerror(
                    "non-prime modulus in modular-reciprocal",
                    intToHandle(smallModulus),
                    intToHandle(aa));
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += smallModulus;
    return intToHandle(y);
}

std::intptr_t ModularReciprocal::op(std::uint64_t* a)
{   return generalModularReciprocal(vectorToHandle(a));
}

std::intptr_t SafeModularReciprocal::op(SignedDigit aa)
{   if (aa <= 0)
        UNLIKELY
        return (std::intptr_t)aerror(
            "bad argument to safe-modular-reciprocal",
            intToHandle(aa));
    else if (modulusSize == modulus_big)
        UNLIKELY
        return generalModularReciprocal(intToHandle(aa), true);
    SignedDigit a = smallModulus,
                 b = aa,
                 x = 0,
                 y = 1;
    while (b != 1)
    {   Digit w, t;
        if (b == 0) return nil;
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += smallModulus;
    return intToHandle(y);
}

std::intptr_t SafeModularReciprocal::op(std::uint64_t* a)
{   return generalModularReciprocal(vectorToHandle(a), true);
}


// end of division.cpp
