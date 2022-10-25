// arith-logops.cpp                        Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

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

// Logand, Logor etc. Also Shifts.

#include "headers.h"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;


LispObject Logand::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logand>("logand", a,
            b);
}
LispObject Logand::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a,
            b);
}
LispObject Logand::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a,
            b);
}
LispObject Logand::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a,
            b);
}

LispObject Logand::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a,
            b);
}
// fixnum & fixnum
LispObject Logand::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(a.intval(), b.intval());
}
// bignum & fixnum
LispObject Logand::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(a, b.intval());
}
// fixnum & bignum
LispObject Logand::op(Fixnum a, uint64_t *b)
{   return Logand::op(b, a);
}
// bignum & bignum
LispObject Logand::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logand::op(a, b);
}

LispObject Logor::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logor>("logor", a,
            b);
}
LispObject Logor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a,
            b);
}
LispObject Logor::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a,
            b);
}
LispObject Logor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a,
            b);
}

LispObject Logor::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a,
            b);
}
// fixnum | fixnum
LispObject Logor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(a.intval(), b.intval());
}
// bignum | fixnum
LispObject Logor::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(a, b.intval());
}
// fixnum | bignum
LispObject Logor::op(Fixnum a, uint64_t *b)
{   return Logor::op(b, a);
}
// bignum | bignum
LispObject Logor::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logor::op(a, b);
}

LispObject Logxor::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logxor>("logxor", a,
            b);
}
LispObject Logxor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a,
            b);
}
LispObject Logxor::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a,
            b);
}
LispObject Logxor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a,
            b);
}

LispObject Logxor::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a,
            b);
}
// fixnum ^ fixnum
LispObject Logxor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(a.intval(), b.intval());
}
// bignum ^ fixnum
LispObject Logxor::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(a, b.intval());
}
// fixnum ^ bignum
LispObject Logxor::op(Fixnum a, uint64_t *b)
{   return Logxor::op(b, a);
}
// bignum ^ bignum
LispObject Logxor::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logxor::op(a, b);
}

LispObject Logeqv::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,Logeqv>("logeqv", a,
            b);
}
LispObject Logeqv::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a,
            b);
}
LispObject Logeqv::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a,
            b);
}
LispObject Logeqv::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a,
            b);
}

LispObject Logeqv::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a,
            b);
}
// fixnum  eqv  fixnum
LispObject Logeqv::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(a.intval(), b.intval());
}
// bignum  eqv  fixnum
LispObject Logeqv::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(a, b.intval());
}
// fixnum  eqv  bignum
LispObject Logeqv::op(Fixnum a, uint64_t *b)
{   return Logeqv::op(b, a);
}
// bignum  eqv  bignum
LispObject Logeqv::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logeqv::op(a, b);
}
LispObject Lognot::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Lognot>("lognot", a);
}
LispObject Lognot::op(Fixnum a)
{   return arithlib_lowlevel::Lognot::op(a.intval());
}
LispObject Lognot::op(uint64_t *a)
{   return arithlib_lowlevel::Lognot::op(a);
}
LispObject Logcount::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Logcount>("logcount",
            a);
}
LispObject Logcount::op(Fixnum a)
{   return arithlib_lowlevel::Logcount::op(a.intval());
}
LispObject Logcount::op(uint64_t *a)
{   return arithlib_lowlevel::Logcount::op(a);
}

LispObject LeftShift::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,LeftShift>("lshift",
            a, b);
}
LispObject LeftShift::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift",
            a, b);
}
LispObject LeftShift::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift",
            a, b);
}
LispObject LeftShift::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift",
            a, b);
}

LispObject LeftShift::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift",
            a, b);
}
// fixnum << fixnum
LispObject LeftShift::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(a.intval(), b.intval());
}
// bignum << fixnum
LispObject LeftShift::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(a, b.intval());
}
LispObject bignum_value(uint64_t *a)
{   return number_dispatcher::bignum_value(a);
}
// fixnum << bignum
LispObject LeftShift::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else if (Zerop::op(a)) return fixnum_of_int(0);
    else return aerror1("left shift by value that is too large",
                     bignum_value(b));
}
// bignum << bignum
LispObject LeftShift::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else return aerror1("left shift by value that is too large",
                         bignum_value(b));

}

LispObject RightShift::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,RightShift>("rshift",
            a, b);
}
LispObject RightShift::op(LispObject a, Fixnum b)
{   return
        number_dispatcher::ibinaryR<LispObject,RightShift>("rshift", a, b);
}
LispObject RightShift::op(LispObject a, uint64_t *b)
{   return
        number_dispatcher::ibinaryR<LispObject,RightShift>("rshift", a, b);
}
LispObject RightShift::op(Fixnum a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,RightShift>("rshift", a, b);
}

LispObject RightShift::op(uint64_t *a, LispObject b)
{   return
        number_dispatcher::ibinaryL<LispObject,RightShift>("rshift", a, b);
}
// fixnum >> fixnum
LispObject RightShift::op(Fixnum a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(a.intval(), -b.intval());
    else return arithlib_lowlevel::RightShift::op(a.intval(), b.intval());
}
// bignum >> fixnum
LispObject RightShift::op(uint64_t *a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(a, -b.intval());
    else return arithlib_lowlevel::RightShift::op(a, b.intval());

}
// fixnum >> bignum
LispObject RightShift::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Zerop::op(a)) return fixnum_of_int(0);
        else return aerror1("right shift by value that is too negative",
                            bignum_value(b));
    }
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}
// bignum >> bignum
LispObject RightShift::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b))
        return aerror1("right shift by value that is too negative", bignum_value(b));
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}


LispObject IntegerLength::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,IntegerLength>("msd", a);
}
LispObject IntegerLength::op(Fixnum a)
{   return arithlib_lowlevel::IntegerLength::op(a.intval());
}
LispObject IntegerLength::op(uint64_t *a)
{   return arithlib_lowlevel::IntegerLength::op(a);
}

LispObject LowBit::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,LowBit>("lsd", a);
}
LispObject LowBit::op(Fixnum a)
{   return arithlib_lowlevel::LowBit::op(a.intval());
}
LispObject LowBit::op(uint64_t *a)
{   return arithlib_lowlevel::LowBit::op(a);
}

LispObject Ninorm(LispObject env, LispObject a, LispObject k)
// This is a piece of magic especially designed to speed up the
// REDUCE big-float code.  It adjusts the integer a until it has
// just k bits, and returns a correction to the associated exponent.
// It combines aspects of msd, lsd, ash and a rounding operation. k must
// be positive.
{
#if 0
    uintptr_t kk;
    size_t bits;
    intptr_t top;
    uintptr_t bottom;
    size_t rtop = 0, rbottom = 0;
    bool was_fixnum = false, was_negative = false, round_up;
    if (is_fixnum(k) && (intptr_t)k >= 0) kk = int_of_fixnum(k);
    else return aerror1("bad args for inorm", k);
    if (is_fixnum(a))
    {   top = int_of_fixnum(
                  a);   // Beware - can now have up to 60 bits in it
        if (top == 0) return aerror1("zero arg for inorm", a);
        was_negative = (top < 0);
        bottom = top;
        was_fixnum = true;
    }
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        if (!is_bignum_header(h)) return aerror1("bad arg for inorm", a);
        rtop = (length_of_header(h)-CELL)/4 - 1;
        top = (int32_t)bignum_digits(a)[rtop];
        was_negative = (top < 0);
        rtop = 31*rtop;
        while ((bottom = bignum_digits(a)[rbottom]) == 0) rbottom++;
        rbottom = 31*rbottom;
    }
    else return aerror1("bad arg for inorm", a);
    if (top < 0) top = ~top;  // Now top is guaranteed positive
// In the 64-bit case with a fixnum input the value in top may be
// over 2^32...
    if (SIXTY_FOUR_BIT &&
        top >= (intptr_t)INT64_C(0x100000000))
        rtop += 32, top = (intptr_t)((int64_t)top >> 32);
    if (top >= 0x10000) rtop += 16, top >>= 16;
    if (top >= 0x100)   rtop += 8,  top >>= 8;
    assert(top >= 0 && top <= 0xff);
    rtop = rtop + msd_table[top];
// now rtop identifies the top bit
    if (SIXTY_FOUR_BIT &&
        (bottom & (uintptr_t)UINT64_C(0xffffffff)) == 0)
        rbottom += 32, bottom = (intptr_t)((int64_t)bottom >> 32);
    if ((bottom & 0xffffu) == 0) rbottom += 16, bottom >>= 16;
    if ((bottom & 0xff) == 0)    rbottom += 8,  bottom >>= 8;
    rbottom = rbottom + lsd_table[bottom & 0xff];
// Now rbottom identifies the bottom bit.
// Well rtop is the highest 1-bit in either the number or (if the number
// started off negative) ~number, while rbottom is the lowest bit in the
// original 2s complement value as presented.
//
// The next line adjusts for the odd case where the input number is
// minus an exact power of 2, in which case finding its most significant bit
// involved just a little correction.
    round_up = was_negative;
    if (rtop == rbottom) rtop++;
    bits = rtop - rbottom;             // bits used in the number
    if (bits <= kk) kk = rbottom;      // no rounding wanted
    else if (was_fixnum)
    {   intptr_t bit;
// If the input was a fixnum and I need to decrease its precision
// I will do it in-line here, mainly so that the bignum code that comes
// later will not have to worry so much about the possibility of having
// any fixnums around.
        kk = rtop - kk;
        bit = ((intptr_t)1) << (kk - 1);
        top = int_of_fixnum(a);
        if (top < 0)
        {   top = -top;
// It is almost the case that for negative values I should round if the
// bit I want to test is a zero (rather than a 1), but this is not true when
// the bit involved is the least significant set bit in the word.  So to
// keep it simple I negate, test, adjust and negate back when working with
// single precision numbers.  I also do the shifting right on the positive
// value to avoid problems with the bits that get shifted off, and with
// computers where right shifts are logical rather than arithmetic.
            if ((top & bit) != 0) top += bit;
            top = top >> kk;
            top = -top;
        }
        else
        {   if ((top & bit) != 0) top += bit;
            top = top >> kk;
        }
// All the shifts I do here move only zero bits off the bottom of the
// word, and so there are no issues about +ve vs -ve numbers to bother me.
        while ((top & 0xf) == 0)
        {   top = top/16;
            kk += 4;
        }
        while ((top & 0x1) == 0)
        {   top = top/2;
            kk += 1;
        }
        a = cons(fixnum_of_int(top), fixnum_of_int(kk));
        return onevalue(a);
    }
    else
    {   size_t wk, bk;
// Here my input was a bignum and I have established that I not only need
// to shift it right but that I will need to lose some non-zero digits from
// the right hand end. To cope with this I need to decide whether it will
// round up or down, and then perform the appropriate shifts, including a
// post-normalisation to ensure that the mantissa of the number as returned
// is odd.
        kk = rtop - kk;
        if (rbottom == kk-1) round_up = true;
        else
        {   size_t wk1 = (kk-1) / 31, bk1 = (kk-1) % 31;
            intptr_t bit = ((intptr_t)1) << bk1;
            round_up = ((bit & bignum_digits(a)[wk1]) != 0);
            if (was_negative) round_up = !round_up;
        }
// Now I need to find out how much I will need to shift AFTER rounding
// and truncation to leave me with a properly normalised value.
        wk = kk / 31, bk = kk % 31;
// If I have a positive value that is not being rounded up I want to skip
// over 0 bits until I find a 1. Similarly for a negative value that is
// being rounded up.
        if (was_negative == round_up)
        {   for (;;)
            {   intptr_t bit = ((int32_t)1) << bk;
                if ((bignum_digits(a)[wk] & bit) != 0) break;
                kk++;
                bk++;
                if (bk == 31) bk = 0, wk++;
            }
        }
        else
// A positive value that is being rounded up or a negative one that is not
// should cause me to skip over 1 bits until I find a 0.  The 0 I find
// will be promoted into a 1 achieve the rounding I need.
        {   for (;;)
            {   intptr_t bit = ((intptr_t)1) << bk;
                if ((bignum_digits(a)[wk] & bit) == 0) break;
                kk++;
                bk++;
                if (bk == 31) bk = 0, wk++;
            }
        }
    }
    if (kk != 0)
    {   a = ash(a, fixnum_of_int(-kk));
// All the adjustment I now need to allow for right-shifting negative
// numbers and rounding off - at all reduces to just forcing the bottom bit
// of the result I compute here to be a 1!
        if (is_fixnum(a)) a |= 0x10;
        else bignum_digits(a)[0] |= 1;
    }
    a = cons(a, fixnum_of_int(kk));
    return onevalue(a);
#endif // 0
}

#endif // ARITHLIB

// end of arith-logops.cpp
