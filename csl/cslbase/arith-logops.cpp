// arith-logops.cpp                        Copyright (C) 2022-2023 Codemist

#ifdef ARITHLIB

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
{   return number_dispatcher::ibinary<LispObject,Logand>("logand", a, b);
}

LispObject Logand::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a, b);
}

LispObject Logand::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logand>("logand", a, b);
}

LispObject Logand::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a, b);
}

LispObject Logand::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logand>("logand", a, b);
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
{   return number_dispatcher::ibinary<LispObject,Logor>("logor", a, b);
}

LispObject Logor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a, b);
}

LispObject Logor::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logor>("logor", a, b);
}

LispObject Logor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a, b);
}

LispObject Logor::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logor>("logor", a, b);
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
{   return number_dispatcher::ibinary<LispObject,Logxor>("logxor", a, b);
}

LispObject Logxor::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a, b);
}

LispObject Logxor::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logxor>("logxor", a, b);
}

LispObject Logxor::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a, b);
}

LispObject Logxor::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logxor>("logxor", a, b);
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
{   return number_dispatcher::ibinary<LispObject,Logeqv>("logeqv", a, b);
}

LispObject Logeqv::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a, b);
}

LispObject Logeqv::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,Logeqv>("logeqv", a, b);
}

LispObject Logeqv::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a, b);
}

LispObject Logeqv::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,Logeqv>("logeqv", a, b);
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
{   SingleValued fn;
    if (!is_fixnum(a1) || (intptr_t)a1 < 0)
        return aerror1("logbitp", a1);
    if (!is_fixnum(a2) && !is_new_bignum(a2))
        return aerror1("logbitp", a2);
    uintptr_t n = int_of_fixnum(a1);
    if (is_fixnum(a2)) return onebool(arithlib_lowlevel::Logbitp::op(
        arithlib_implementation::intOfHandle(a2), n));
    else return onebool(arithlib_lowlevel::Logbitp::op(
        arithlib_implementation::vectorOfHandle(a2), n));
}

LispObject Nlogtest(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(Logand::op(a1, a2) != fixnum_of_int(0));
}

size_t Logcount::op(LispObject a)
{   return number_dispatcher::iunary<size_t,Logcount>("logcount", a);
}

size_t Logcount::op(Fixnum a)
{   return arithlib_lowlevel::Logcount::op(a.intval());
}

size_t Logcount::op(uint64_t *a)
{   return arithlib_lowlevel::Logcount::op(a);
}

LispObject LeftShift::op(LispObject a, LispObject b)
{   return number_dispatcher::ibinary<LispObject,LeftShift>("lshift", a, b);
}

LispObject LeftShift::op(LispObject a, Fixnum b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift", a, b);
}

LispObject LeftShift::op(LispObject a, uint64_t *b)
{   return number_dispatcher::ibinaryR<LispObject,LeftShift>("lshift", a, b);
}

LispObject LeftShift::op(Fixnum a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift", a, b);
}

LispObject LeftShift::op(uint64_t *a, LispObject b)
{   return number_dispatcher::ibinaryL<LispObject,LeftShift>("lshift", a, b);
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
{   return number_dispatcher::ibinary<LispObject,RightShift>("rshift", a, b);
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

uint64_t Low64Bits::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Low64Bits>("lowbits", a);
}
uint64_t Low64Bits::op(Fixnum a)
{   return arithlib_lowlevel::Low64Bits::op(a.intval());
}
uint64_t Low64Bits::op(uint64_t *a)
{   return arithlib_lowlevel::Low64Bits::op(a);
}

uint64_t Top64Bits::op(LispObject a)
{   return number_dispatcher::iunary<LispObject,Top64Bits>("lowbits", a);
}
uint64_t Top64Bits::op(Fixnum a)
{   return arithlib_lowlevel::Top64Bits::op(a.intval());
}
uint64_t Top64Bits::op(uint64_t *a)
{   return arithlib_lowlevel::Top64Bits::op(a);
}

size_t LowBit::op(LispObject a)
{   return number_dispatcher::iunary<size_t,LowBit>("lsd", a);
}

size_t LowBit::op(Fixnum a)
{   return arithlib_lowlevel::LowBit::op(a.intval());
}

size_t LowBit::op(uint64_t *a)
{   return arithlib_lowlevel::LowBit::op(a);
}

size_t IntegerLength::op(LispObject a)
{   return number_dispatcher::iunary<size_t,IntegerLength>("msd", a);
}

size_t IntegerLength::op(Fixnum a)
{   return arithlib_lowlevel::IntegerLength::op(a.intval());
}

size_t IntegerLength::op(uint64_t *a)
{   return arithlib_lowlevel::IntegerLength::op(a);
}

// inorm works as follows...
// It will mostly work on the absolute value of a and make it negative
// again at the end.
//
// Now if the top bit of a is at position m the idea is to end up with a
// k-bit result. If m > k then some rounding will be required. Achieve
// this bu adding (1<<(m-k-1)) to a and masking with ~((1<<(m-k))-1). This
// should leave a value that has a bit-width at most k.
//
// Let t be the number of trailing zero bits in the computed a then
// return (a>>t, t) [subject to restoring the sign].


LispObject Ninorm(LispObject env, LispObject a, LispObject kk)
// This is a piece of magic especially designed to speed up the
// REDUCE big-float code.  It adjusts the integer a until it has
// just k bits, and returns a correction to the associated exponent.
// It combines aspects of msd, lsd, ash and a rounding operation. k must
// be positive.
{   SingleValued fn;
    if (!is_fixnum(kk) || (intptr_t)kk < 0)
        return aerror1("bad args for inorm", kk);
    if (a == fixnum_of_int(0)) return aerror("zero is an illegal arg to inorm");
    int k = int_of_fixnum(kk);
// If a is a fixnum all the computations can be done using direct integer
// arithmetic... That makes it a lot easier to code in a way that makes
// it clear what is happening.
    if (is_fixnum(a))
    {   uintptr_t v = int_of_fixnum(a);
        bool negative = false;
        if (a < 0)
        {   v = -v;
            negative = true;
        }
        int highPos = 63 - nlz(v);
        if (highPos >= k)
        {   int roundBit = 1<<(highPos-k);
            int mask = 2*roundBit - 1;
            v = (v + roundBit) & ~mask;
        }
        int lowBit = ntz(v);
        v >>= lowBit;
        if (negative) v = -v;
        return cons(fixnum_of_int(v), fixnum_of_int(lowBit));
    }
    else if (is_new_bignum(a))
    {   bool negative = Minusp::op(a);
        if (negative) a = Minus::op(a);
        int highPos = IntegerLength::op(a);
// The way this is coded will mean that bignum-storage will be allocate
// for all sorts of intermediate results, and also that some needless
// dispatch will be performed when values are already known to be
// large or small. However it makes the code a LOT tidier than the
// previous version!
        if (highPos > k)
        {   LispObject roundBit = LeftShift::op(fixnum_of_int(1),
                                                fixnum_of_int(highPos-k-1));
            LispObject mask = Sub1::op(
                LeftShift::op(roundBit, fixnum_of_int(1)));
            a = Logand::op(Plus::op(a, roundBit), Lognot::op(mask));
        }
        size_t lowBit = LowBit::op(a) - 1;
        a = RightShift::op(a, fixnum_of_int(lowBit));
        if (negative) a = Minus::op(a);
        return cons(a, fixnum_of_int(lowBit));
    }
    else return aerror1("bad arg for inorm", a);
}

LispObject Nboole(LispObject env, LispObject op, LispObject a1, LispObject a2)
{   SingleValued fn;
    LispObject r;
    THREADID;
    switch (is_fixnum(op) ? int_of_fixnum(op) : -1)
    {   case boole_clr:
            return fixnum_of_int(0);
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
            return a1;
        case boole_andc1:
            {   Save save(THREADARG a2);
                a1 = Lognot::op(a1);
                errexit();
                save.restore(a2);
            }
            r = Logand::op(a1, a2);
            break;
        case boole_2:
            return a2;
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
            return fixnum_of_int(-1);
        default:
            return aerror1("bad arg for boole",  op);
    }
    return r;
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
{   SingleValued fn;
    if (!is_fixnum(size) || !is_fixnum(position) ||
        size <= 0 || position < 0 ||
        size >= SIZE_LIMIT || position >= POSITION_LIMIT)
        return aerror2("bytes", size, position);
    return fixnum_of_int(
        (int_of_fixnum(size)<<SIZE_SHIFT) | int_of_fixnum(position));
}

LispObject Nbyte_size(LispObject env, LispObject a)
{   SingleValued fn;
    if (!is_fixnum(a)) return aerror1("byte-size", a);
    else return
        fixnum_of_int((int_of_fixnum(a)>>SIZE_SHIFT) & (SIZE_LIMIT-1));
}

LispObject Nbyte_position(LispObject env, LispObject a)
{   SingleValued fn;
    if (!is_fixnum(a)) return aerror1("byte-position", a);
    else return
        fixnum_of_int(int_of_fixnum(a) & (POSITION_LIMIT-1));
}

// Since I do not expect these to be used I will implement them using
// simple generic arithmetic. Well I expect that for fixnum sized
// input integers that will in fact not be too bad!

LispObject Nldb(LispObject env, LispObject bytespec, LispObject n)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(n) && !is_new_bignum(n)))
        return aerror2("ldb", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    return Logand::op(
        RightShift::op(n, fixnum_of_int(position)),
        mask);
}

LispObject Nmask_field(LispObject env, LispObject bytespec, LispObject n)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(n) && !is_new_bignum(n)))
        return aerror2("mask_field", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Sub1::op(LeftShift::op(fixnum_of_int(1),
                                             fixnum_of_int(size)));
    return Logand::op(n,
        LeftShift::op(mask, fixnum_of_int(position)));
}

LispObject Nldb_test(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    if (Nldb(env, a1, a2) == fixnum_of_int(0)) return nil;
    else return lisp_true;
}

LispObject Ndpb(LispObject env, LispObject newData,
                                LispObject bytespec, LispObject old)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(old) && !is_new_bignum(old)))
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
    return old;
}

LispObject Ndeposit_field(LispObject env, LispObject newData,
                          LispObject bytespec, LispObject old)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(old) && !is_new_bignum(old)))
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
    return old;
}

LispObject Nlogand(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(-1);
}

LispObject Nlogand(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nlogand(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Logand::op(a1, a2);
}

LispObject Nlogand(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return Logand::op(Logand::op(a1, a2), a3);
}

LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                          LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlogor(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nlogor(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return Logor::op(a1, a2);
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   SingleValued fn;
    return Logor::op(Logor::op(a1, a2), a3);
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlogxor(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nlogxor(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2)
{   SingleValued fn;
    return Logxor::op(a1, a2);
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   SingleValued fn;
    return Logxor::op(Logxor::op(a1, a2), a3);
}

LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlogeqv(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(-1);
}

LispObject Nlogeqv(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2)
{   SingleValued fn;
    return Logeqv::op(a1, a2);
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   SingleValued fn;
    return Logeqv::op(Logeqv::op(a1, a2), a3);
}

LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlognot(LispObject env, LispObject a1)
{   SingleValued fn;
    return Lognot::op(a1);
}

LispObject Nlsd(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(LowBit::op(a1));
}

LispObject Nmsd(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(IntegerLength::op(a1));
}

LispObject Nlogcount(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(Logcount::op(a1));
}

LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return LeftShift::op(a1, a2);
}

// The following divides by a power of 2 when shifting right so is not
// a natural arithmetic shift on negative numbers.

LispObject Nash1(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    bool neg = Minusp::op(a1);
    if (neg) a1 = Minus::op(a1);   // Is this needed? @@@@@
    a1 = LeftShift::op(a1, a2);
    if (neg) a1 = Minus::op(a1);
    return a1;
}

LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return RightShift::op(a1, a2);
}

LispObject Nilogand(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(-1);
}

LispObject Nilogand(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2)
{   SingleValued fn;
    return Logand::op(a1, a2);
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   SingleValued fn;
    return Logand::op(Logand::op(a1, a2), a3);
}

LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilogor(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nilogor(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2)
{   SingleValued fn;
    return Logor::op(a1, a2);
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   SingleValued fn;
    return Logor::op(Logor::op(a1, a2), a3);
}

LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilogxor(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nilogxor(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2)
{   SingleValued fn;
    return Logxor::op(a1, a2);
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   SingleValued fn;
    return Logxor::op(Logxor::op(a1, a2), a3);
}

LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilogeqv(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(-1);
}

LispObject Nilogeqv(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2)
{   SingleValued fn;
    return Logeqv::op(a1, a2);
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   SingleValued fn;
    return Logeqv::op(Logeqv::op(a1, a2), a3);
}

LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilognot(LispObject env, LispObject a1)
{   SingleValued fn;
    return Lognot::op(a1);
}

LispObject Nileftshift(LispObject env, LispObject a1,
                              LispObject a2)
{   SingleValued fn;
    return LeftShift::op(a1, a2);
}

LispObject Nirightshift(LispObject env, LispObject a1,
                               LispObject a2)
{   SingleValued fn;
    return RightShift::op(a1, a2);
}

#endif // ARITHLIB

// end of arith-logops.cpp
