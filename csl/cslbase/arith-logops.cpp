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

LispObject Nlogbitp(LispObject env, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || (intptr_t)a1 < 0)
        return aerror1("logbitp", a1);
    if (!is_fixnum(a2) && (!is_numbers(a2) || !is_new_bignum(a2)))
        return aerror1("logbitp", a2);
    uintptr_t n = int_of_fixnum(a1);
    return onebool(arithlib_lowlevel::Logbitp::op(a2, n));
}

LispObject Nlogtest(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Logand::op(a1, a2) != fixnum_of_int(0));
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

// Return some low bits of an integer - up to 64 of them.

uint64_t LowBits::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,LowBits>("lowbits", a);
}
uint64_t LowBits::op(Fixnum a)
{   return arithlib_lowlevel::LowBits::op(a.intval());
}
uint64_t LowBits::op(uint64_t *a)
{   return arithlib_lowlevel::LowBits::op(a);
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

LispObject IntegerLength::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,IntegerLength>("msd", a);
}

LispObject IntegerLength::op(Fixnum a)
{   return arithlib_lowlevel::IntegerLength::op(a.intval());
}

LispObject IntegerLength::op(uint64_t *a)
{   return arithlib_lowlevel::IntegerLength::op(a);
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

LispObject Nboole(LispObject env, LispObject op,
                  LispObject a1, LispObject a2)
{   LispObject r;
    THREADID;
    switch (is_fixnum(op) ? int_of_fixnum(op) : -1)
    {   case boole_clr:
            return onevalue(fixnum_of_int(0));
        case boole_and:
            r = Logand::op(a1, a2);
            break;
        case boole_andc2:
            {   Save save(THREADARG a1);
                a2 = Lognot::op(a2);
                errexit();
                save.restore(a1);
            }
            r = Logand::op(a1, a2);
            break;
        case boole_1:
            return onevalue(a1);
        case boole_andc1:
            {   Save save(THREADARG a2);
                a1 = Lognot::op(a1);
                errexit();
                save.restore(a2);
            }
            r = Logand::op(a1, a2);
            break;
        case boole_2:
            return onevalue(a2);
        case boole_xor:
            r = Logxor::op(a1, a2);
            break;
        case boole_ior:
            r = Logor::op(a1, a2);
            break;
        case boole_nor:
            a1 = Logor::op(a1, a2);
            errexit();
            r = Lognot::op(a1);
            break;
        case boole_eqv:
            r = Logeqv::op(a1, a2);
            break;
        case boole_c2:
            r = Lognot::op(a2);
            break;
        case boole_orc2:
            {   Save save(THREADARG a1);
                a2 = Lognot::op(a2);
                errexit();
                save.restore(a1);
            }
            r = Logor::op(a1, a2);
            break;
        case boole_c1:
            r = Lognot::op(a1);
            break;
        case boole_orc1:
            {   Save save(THREADARG a2);
                a1 = Lognot::op(a1);
                errexit();
                save.restore(a2);
            }
            r = Logor::op(a1, a2);
            break;
        case boole_nand:
            a1 = Logand::op(a1, a2);
            errexit();
            r = Lognot::op(a1);
            break;
        case boole_set:
            return onevalue(fixnum_of_int(-1));
        default:
            return aerror1("bad arg for boole",  op);
    }
    return onevalue(r);
}

// Common Lisp has a bunch of functions that treat integers are packed
// bit sequences. A "byte" within an integer is specified by a pair
// (size . position). My feeling is that this may have been a valuable
// scheme for system programming on machine-int width integers where the
// functions got open compiled but that it is not terribly sensible
// when the size and position mean that the underpinning integer has to
// be a bignum. So I will not demand that my support is super high-performance
// since I do not expect anybody to use it! But if somebody imports some
// Common Lisp code then having these here ready may assist them.

static const int SIZE_LIMIT = 1024;
static const int POSITION_LIMIT = 65536;
static const int SIZE_SHIFT = 16;

LispObject Nbyte(LispObject env, LispObject size, LispObject position)
{   if (!is_fixnum(size) || !is_fixnum(position) ||
        size <= 0 || position < 0 ||
        size >= SIZE_LIMIT || position >= POSITION_LIMIT)
        return aerror2("bytes", size, position);
    return onevalue(fixnum_of_int(
        (int_of_fixnum(size)<<SIZE_SHIFT) | int_of_fixnum(position)));
}

LispObject Nbyte_size(LispObject env, LispObject a)
{   if (!is_fixnum(a)) return aerror1("byte-size", a);
    else return onevalue(
        fixnum_of_int((int_of_fixnum(a)>>SIZE_SHIFT) & (SIZE_LIMIT-1)));
}

LispObject Nbyte_position(LispObject env, LispObject a)
{   if (!is_fixnum(a)) return aerror1("byte-position", a);
    else return onevalue(
        fixnum_of_int(int_of_fixnum(a) & (POSITION_LIMIT-1)));
}

// Since I do not expect these to be used I will implement them using
// simple generic arithmetic. Well I expect that for fixnum sized
// input integers that will in fact not be too bad!

LispObject Nldb(LispObject env, LispObject bytespec, LispObject n)
{   if (!is_fixnum(bytespec) ||
        (!is_fixnum(n) && (!is_numbers(n) || !is_new_bignum(n))))
        return aerror2("ldb", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    return onevalue(Logand::op(
        RightShift::op(n, fixnum_of_int(position)),
        mask));
}

LispObject Nmask_field(LispObject env, LispObject bytespec, LispObject n)
{   if (!is_fixnum(bytespec) ||
        (!is_fixnum(n) && (!is_numbers(n) || !is_new_bignum(n))))
        return aerror2("mask_field", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    return onevalue(Logand::op(n,
        LeftShift::op(mask, fixnum_of_int(position))));
}

LispObject Nldb_test(LispObject env, LispObject a1, LispObject a2)
{   if (Nldb(env, a1, a2) == fixnum_of_int(0)) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Ndpb(LispObject env, LispObject newData,
                                LispObject bytespec, LispObject old)
{   if (!is_fixnum(bytespec) ||
        (!is_fixnum(old) && (!is_numbers(old) || !is_new_bignum(old))))
        return aerror2("mask_field", bytespec, old);
// mask = (1<<width - 1)<<position
// (old & ~mask) | ((new<<position) & mask)
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    mask = LeftShift::op(mask, fixnum_of_int(position));
    old = Logand::op(old, Lognot::op(mask));
    old = Logor::op(old,
        Logand::op(mask, LeftShift::op(newData, fixnum_of_int(position))));
    return onevalue(old);
}

LispObject Ndeposit_field(LispObject env, LispObject newData,
                          LispObject bytespec, LispObject old)
{   if (!is_fixnum(bytespec) ||
        (!is_fixnum(old) && (!is_numbers(old) || !is_new_bignum(old))))
        return aerror2("mask_field", bytespec, old);
// mask = (1<<width - 1)<<position
// (old & ~mask) | ((new<<position) & mask)
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    mask = LeftShift::op(mask, fixnum_of_int(position));
    old = Logand::op(old, Lognot::op(mask));
    old = Logor::op(old, Logand::op(mask, newData));
    return onevalue(old);
}

#endif // ARITHLIB

// end of arith-logops.cpp
