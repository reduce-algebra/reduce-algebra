// arith-logops.cpp                        Copyright (C) 2022-2026 Codemist

#ifdef ARITHLIB

// $Id$


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

// Logand, Logor etc. Also Shifts.

#include "headers.h"

namespace CSL_LISP
{

// fixnum & fixnum
LispObject Logand::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum & fixnum
LispObject Logand::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logand::op(a, int_of_fixnum(b));
}
// fixnum & bignum
LispObject Logand::op(Fixnum a, uint64_t *b)
{   return Logand::op(b, int_of_fixnum(a));
}
// bignum & bignum
LispObject Logand::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logand::op(a, b);
}

// fixnum | fixnum
LispObject Logor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum | fixnum
LispObject Logor::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logor::op(a, int_of_fixnum(b));
}
// fixnum | bignum
LispObject Logor::op(Fixnum a, uint64_t *b)
{   return Logor::op(b, a);
}
// bignum | bignum
LispObject Logor::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logor::op(a, b);
}

// fixnum ^ fixnum
LispObject Logxor::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum ^ fixnum
LispObject Logxor::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logxor::op(a, int_of_fixnum(b));
}
// fixnum ^ bignum
LispObject Logxor::op(Fixnum a, uint64_t *b)
{   return Logxor::op(b, a);
}
// bignum ^ bignum
LispObject Logxor::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logxor::op(a, b);
}

// fixnum  eqv  fixnum
LispObject Logeqv::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum  eqv  fixnum
LispObject Logeqv::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Logeqv::op(a, int_of_fixnum(b));
}
// fixnum  eqv  bignum
LispObject Logeqv::op(Fixnum a, uint64_t *b)
{   return Logeqv::op(b, a);
}
// bignum  eqv  bignum
LispObject Logeqv::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Logeqv::op(a, b);
}

LispObject Lognot::op(Fixnum a)
{   return arithlib_lowlevel::Lognot::op(int_of_fixnum(a));
}

LispObject Lognot::op(uint64_t *a)
{   return arithlib_lowlevel::Lognot::op(a);
}

LispObject Nlogbitp(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    if (!is_fixnum(a1) || (intptr_t)a1 < 0)
        return aerror("logbitp", a1);
    if (!is_fixnum(a2) && !is_new_bignum(a2))
        return aerror("logbitp", a2);
    uintptr_t n = int_of_fixnum(a1);
    if (is_fixnum(a2)) return onebool(arithlib_lowlevel::Logbitp::op(
        arithlib_implementation::intOfHandle(a2), n));
    else return onebool(arithlib_lowlevel::Logbitp::op(
        arithlib_implementation::vectorOfHandle(a2), n));
}

LispObject Nlogtest(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(IBinary(Logand, a1, a2) != fixnum_of_int(0));
}

size_t Logcount::op(Fixnum a)
{   return arithlib_lowlevel::Logcount::op(int_of_fixnum(a));
}

size_t Logcount::op(uint64_t *a)
{   return arithlib_lowlevel::Logcount::op(a);
}

// fixnum << fixnum
LispObject LeftShift::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum << fixnum
LispObject LeftShift::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::LeftShift::op(a, int_of_fixnum(b));
}

// fixnum << bignum
LispObject LeftShift::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else if (Zerop::op(a)) return fixnum_of_int(0);
    else return aerror("left shift by value that is too large",
                        bignum_value(b));
}
// bignum << bignum
LispObject LeftShift::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Minusp::op(a)) return fixnum_of_int(-1);
        else return fixnum_of_int(0);
    }
    else return aerror("left shift by value that is too large",
                        bignum_value(b));
}

// fixnum >> fixnum
LispObject RightShift::op(Fixnum a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(int_of_fixnum(a), -int_of_fixnum(b));
    else return arithlib_lowlevel::RightShift::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum >> fixnum
LispObject RightShift::op(uint64_t *a, Fixnum b)
{   if (Minusp::op(b))
        return arithlib_lowlevel::LeftShift::op(a, -int_of_fixnum(b));
    else return arithlib_lowlevel::RightShift::op(a, int_of_fixnum(b));

}
// fixnum >> bignum
LispObject RightShift::op(Fixnum a, uint64_t *b)
{   if (Minusp::op(b))
    {   if (Zerop::op(a)) return fixnum_of_int(0);
        else return aerror("right shift by value that is too negative",
                            bignum_value(b));
    }
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}
// bignum >> bignum
LispObject RightShift::op(uint64_t *a, uint64_t *b)
{   if (Minusp::op(b))
        return aerror("right shift by value that is too negative", bignum_value(b));
    else if (Minusp::op(a)) return fixnum_of_int(-1);
    else return fixnum_of_int(0);
}

// Return some low bits of an integer - up to 64 of them.

uint64_t Low64Bits::op(Fixnum a)
{   return arithlib_lowlevel::Low64Bits::op(int_of_fixnum(a));
}
uint64_t Low64Bits::op(uint64_t *a)
{   return arithlib_lowlevel::Low64Bits::op(a);
}

uint64_t Top64Bits::op(Fixnum a)
{   return arithlib_lowlevel::Top64Bits::op(int_of_fixnum(a));
}
uint64_t Top64Bits::op(uint64_t *a)
{   return arithlib_lowlevel::Top64Bits::op(a);
}

size_t LowBit::op(Fixnum a)
{   return arithlib_lowlevel::LowBit::op(int_of_fixnum(a));
}

size_t LowBit::op(uint64_t *a)
{   return arithlib_lowlevel::LowBit::op(a);
}

size_t IntegerLength::op(Fixnum a)
{   return arithlib_lowlevel::IntegerLength::op(int_of_fixnum(a));
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
        return aerror("bad args for inorm", kk);
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
    {   bool negative = BoolUnary(Minusp, a);
        if (negative) a = Unary(Minus, a);
        int highPos = IUnary(IntegerLength, a);
// The way this is coded will mean that bignum-storage will be allocate
// for all sorts of intermediate results, and also that some needless
// dispatch will be performed when values are already known to be
// large or small. However it makes the code a LOT tidier than the
// previous version!
        if (highPos > k)
        {   LispObject roundBit = IBinary(LeftShift,
                                          fixnum_of_int(1),
                                          fixnum_of_int(highPos-k-1));
            LispObject mask = Unary(Sub1,
                IBinary(LeftShift, roundBit, fixnum_of_int(1)));
            a = IBinary(Logand, Binary(Plus, a, roundBit),
                                IUnary(Lognot, mask));
        }
        size_t lowBit = IUnary(LowBit, a) - 1;
        a = IBinary(RightShift, a, fixnum_of_int(lowBit));
        if (negative) a = Unary(Minus, a);
        return cons(a, fixnum_of_int(lowBit));
    }
    else return aerror("bad arg for inorm", a);
}

LispObject Nboole(LispObject env, LispObject op, LispObject a1, LispObject a2)
{   SingleValued fn;
    LispObject r;
    switch (is_fixnum(op) ? int_of_fixnum(op) : -1)
    {   case boole_clr:
            return fixnum_of_int(0);
        case boole_and:
            r = IBinary(Logand, a1, a2);
            break;
        case boole_andc2:
            {   a2 = IUnary(Lognot, a2);
                errexit();
            }
            r = IBinary(Logand, a1, a2);
            break;
        case boole_1:
            return a1;
        case boole_andc1:
            {   a1 = IUnary(Lognot, a1);
                errexit();
            }
            r = IBinary(Logand, a1, a2);
            break;
        case boole_2:
            return a2;
        case boole_xor:
            r = IBinary(Logxor, a1, a2);
            break;
        case boole_ior:
            r = IBinary(Logor, a1, a2);
            break;
        case boole_nor:
            a1 = IBinary(Logor, a1, a2);
            errexit();
            r = IUnary(Lognot, a1);
            break;
        case boole_eqv:
            r = IBinary(Logeqv, a1, a2);
            break;
        case boole_c2:
            r = IUnary(Lognot, a2);
            break;
        case boole_orc2:
            {   a2 = IUnary(Lognot, a2);
                errexit();
            }
            r = IBinary(Logor, a1, a2);
            break;
        case boole_c1:
            r = IUnary(Lognot, a1);
            break;
        case boole_orc1:
            {   a1 = IUnary(Lognot, a1);
                errexit();
            }
            r = IBinary(Logor, a1, a2);
            break;
        case boole_nand:
            a1 = IBinary(Logand, a1, a2);
            errexit();
            r = IUnary(Lognot, a1);
            break;
        case boole_set:
            return fixnum_of_int(-1);
        default:
            return aerror("bad arg for boole",  op);
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
        return aerror("bytes", size, position);
    return fixnum_of_int(
        (int_of_fixnum(size)<<SIZE_SHIFT) | int_of_fixnum(position));
}

LispObject Nbyte_size(LispObject env, LispObject a)
{   SingleValued fn;
    if (!is_fixnum(a)) return aerror("byte-size", a);
    else return
        fixnum_of_int((int_of_fixnum(a)>>SIZE_SHIFT) & (SIZE_LIMIT-1));
}

LispObject Nbyte_position(LispObject env, LispObject a)
{   SingleValued fn;
    if (!is_fixnum(a)) return aerror("byte-position", a);
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
        return aerror("ldb", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Unary(Sub1, IBinary(LeftShift, fixnum_of_int(1),
                                                     fixnum_of_int(size)));
    return IBinary(Logand, 
        IBinary(RightShift, n, fixnum_of_int(position)),
        mask);
}

LispObject Nmask_field(LispObject env, LispObject bytespec, LispObject n)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(n) && !is_new_bignum(n)))
        return aerror("mask_field", bytespec, n);
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Unary(Sub1, IBinary(LeftShift, fixnum_of_int(1),
                                                     fixnum_of_int(size)));
    return IBinary(Logand, n,
        IBinary(LeftShift, mask, fixnum_of_int(position)));
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
        return aerror("mask_field", bytespec, old);
// mask = (1<<width - 1)<<position
// (old & ~mask) | ((new<<position) & mask)
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Unary(Sub1, IBinary(LeftShift, fixnum_of_int(1),
                                                     fixnum_of_int(size)));
    mask = IBinary(LeftShift, mask, fixnum_of_int(position));
    old = IBinary(Logand, old, IUnary(Lognot, mask));
    old = IBinary(Logor, old,
        IBinary(Logand, mask, IBinary(LeftShift, newData, fixnum_of_int(position))));
    return old;
}

LispObject Ndeposit_field(LispObject env, LispObject newData,
                          LispObject bytespec, LispObject old)
{   SingleValued fn;
    if (!is_fixnum(bytespec) ||
        (!is_fixnum(old) && !is_new_bignum(old)))
        return aerror("mask_field", bytespec, old);
// mask = (1<<width - 1)<<position
// (old & ~mask) | ((new<<position) & mask)
    int size = (int_of_fixnum(bytespec)>>SIZE_SHIFT) & (SIZE_LIMIT-1);
    if (size == 0) return aerror("zero width field in ldb");
    int position = int_of_fixnum(bytespec) & (POSITION_LIMIT-1);
    LispObject mask = Unary(Sub1, IBinary(LeftShift, fixnum_of_int(1),
                                                     fixnum_of_int(size)));
    mask = IBinary(LeftShift, mask, fixnum_of_int(position));
    old = IBinary(Logand, old, IUnary(Lognot, mask));
    old = IBinary(Logor, old, IBinary(Logand, mask, newData));
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
    return IBinary(Logand, a1, a2);
}

LispObject Nlogand(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logand, IBinary(Logand, a1, a2), a3);
}

LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logand, IBinary(Logand, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logand, w, car(a4plus));
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
    return IBinary(Logor, a1, a2);
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logor, IBinary(Logor, a1, a2), a3);
}

LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logor, IBinary(Logor, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logor, w, car(a4plus));
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
    return IBinary(Logxor, a1, a2);
}

LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logxor, IBinary(Logxor, a1, a2), a3);
}

LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logxor, IBinary(Logxor, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logxor, w, car(a4plus));
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
    return IBinary(Logeqv, a1, a2);
}

LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logeqv, IBinary(Logeqv, a1, a2), a3);
}

LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logeqv, IBinary(Logeqv, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logeqv, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nlognot(LispObject env, LispObject a1)
{   SingleValued fn;
    return IUnary(Lognot, a1);
}

LispObject Nlsd(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(IUnary(LowBit, a1));
}

LispObject Nmsd(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(IUnary(IntegerLength, a1));
}

LispObject Nlogcount(LispObject env, LispObject a1)
{   SingleValued fn;
    return make_lisp_unsigned64(IUnary(Logcount, a1));
}

LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(LeftShift, a1, a2);
}

// The following divides by a power of 2 when shifting right so is not
// a natural arithmetic shift on negative numbers.

LispObject Nash1(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    bool neg = BoolUnary(Minusp, a1);
    if (neg) a1 = Unary(Minus, a1);   // Is this needed? @@@@@
    a1 = IBinary(LeftShift, a1, a2);
    if (neg) a1 = Unary(Minus, a1);
    return a1;
}

LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(RightShift, a1, a2);
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
    return IBinary(Logand, a1, a2);
}

LispObject Nilogand(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logand, IBinary(Logand, a1, a2), a3);
}

LispObject Nilogand(LispObject env, LispObject a1, LispObject a2,
                                    LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logand, IBinary(Logand, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logand, w, car(a4plus));
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
    return IBinary(Logor, a1, a2);
}

LispObject Nilogor(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logor, IBinary(Logor, a1, a2), a3);
}

LispObject Nilogor(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logor, IBinary(Logor, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logor, w, car(a4plus));
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
    return IBinary(Logxor, a1, a2);
}

LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logxor, IBinary(Logxor, a1, a2), a3);
}

LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2,
                                    LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logxor, IBinary(Logxor, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logxor, w, car(a4plus));
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
    return IBinary(Logeqv, a1, a2);
}

LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return IBinary(Logeqv, IBinary(Logeqv, a1, a2), a3);
}

LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2,
                                    LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = IBinary(Logeqv, IBinary(Logeqv, a1, a2), a3);
    while (is_cons(a4plus))
    {   w = IBinary(Logeqv, w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nilognot(LispObject env, LispObject a1)
{   SingleValued fn;
    return IUnary(Lognot, a1);
}

LispObject Nileftshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(LeftShift, a1, a2);
}

LispObject Nirightshift(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return IBinary(RightShift, a1, a2);
}

} // end of namespace

#endif // ARITHLIB

// end of arith-logops.cpp
