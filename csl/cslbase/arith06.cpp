//  arith06.cpp                           Copyright (C) 1990-2017 Codemist

//
// Arithmetic functions... lots of Lisp entrypoints.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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



/*****************************************************************************/
//**              Lisp-callable versions of arithmetic functions           **
/*****************************************************************************/



LispObject Ladd1(LispObject env, LispObject a)
{   if (is_fixnum(a))
    {   // fixnums have data shifted left 4 bits
        if (a == MOST_POSITIVE_FIXNUM) // ONLY possible overflow case here
            a = make_lisp_integerptr_fn(MOST_POSITIVE_FIXVAL+1);
        else return onevalue((LispObject)(a + 0x10));   // the cheap case
    }
    else a = plus2(a, fixnum_of_int(1));
    return onevalue(a);
}

LispObject Lsub1(LispObject env, LispObject a)
{   if (is_fixnum(a))
    {   if (a == MOST_NEGATIVE_FIXNUM)
            return make_lisp_integerptr_fn(MOST_NEGATIVE_FIXVAL - 1);
        else return onevalue((LispObject)(a - 0x10));
    }
    else a = plus2(a, fixnum_of_int(-1));
    return onevalue(a);
}

LispObject Lfloat_2(LispObject env, LispObject a, LispObject b)
{   if (is_sfloat(b))
    {   double d = float_of_number(a);
        return onevalue(pack_immediate_float(d, b));
    }
    else if (!is_bfloat(b)) aerror1("bad arg for float",  b);
    else if (type_of_header(flthdr(b)) == TYPE_LONG_FLOAT)
    {   float128_t dd = float128_of_number(a);
        return onevalue(make_boxfloat128(dd));
    }
    else
    {   double d = float_of_number(a);
        return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
    }
}

LispObject Lfloat(LispObject env, LispObject a)
{   double d;
    if (!is_number(a)) aerror1("bad arg for float", a);
    else if (is_bfloat(a) || is_sfloat(a)) return onevalue(a);
    d = float_of_number(a);
#ifdef COMMON
// Do we REALLY want single precision by default here?
// I count that as a stupid decision!
    return onevalue(pack_single_float(d));
#else
    return onevalue(make_boxfloat(d, TYPE_DOUBLE_FLOAT));
#endif
}

LispObject Llognot(LispObject env, LispObject a)
{   return onevalue(lognot(a));
}

LispObject Lash(LispObject env, LispObject a, LispObject b)
{   return onevalue(ash(a, b));
}

LispObject Lash1(LispObject env, LispObject a, LispObject b)
//
// This function multiplies or divides by a power of two. Note that
// this corresponds to natural shifts on a sign-and-magnitude machine,
// but is not an "arithmetic" shift as that term is understood on
// 2's complement machines.
//
{   bool negative = false;
    if (!is_fixnum(b)) aerror("ash1");
    if (minusp(a))
    {   negative = true;
        a = negate(a);
    }
    a = ash(a, b);
    if (negative) a = negate(a);
    return onevalue(a);
}

int msd_table[256] =
{   0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};

LispObject Lmsd(LispObject, LispObject a)
{   intptr_t top;
    intptr_t r = 0;
    if (is_fixnum(a)) top = int_of_fixnum(a);
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        if (!is_bignum_header(h)) aerror1("bad arg for msd", a);
        r = (length_of_header(h)-CELL)/4 - 1;
        top = (int32_t)bignum_digits(a)[r];
        r = 31*r;
    }
    else aerror1("bad arg for msd", a);
    if (top < 0) aerror1("negative arg for msd", a);   // -ve arg
//
// Note that top may be zero here, but in that case the next word down of
// the bignum involved MUST be fully normalised with its top bit set.
// The effect of this code is that I return (msd 0) => 0.
//
// If sizeof(intptr_t)==4 most of the next statement becomes silly, but
// if test on SIXTY_FOUR_BIT would ensure it did not get executed and the
// slightly odd casts should render it valid.
    if (SIXTY_FOUR_BIT &&
        top >= (intptr_t)INT64_C(0x100000000))
        r += 32, top = (intptr_t)((int64_t)top >> 32);
    if (top >= 0x10000) r += 16, top >>= 16;
    if (top >= 0x100)   r += 8,  top >>= 8;
    return onevalue(fixnum_of_int(r + msd_table[top]));
}

int lsd_table[256] =
{   8, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

LispObject Llsd(LispObject, LispObject a)
{   intptr_t top;
    intptr_t r = 0;
    if (is_fixnum(a))
    {   top = int_of_fixnum(a);
// lsd(0) is taken to have the value 0 here - it is a bit of an odd case
        if (top == 0) return onevalue(a);
    }
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        if (!is_bignum_header(h)) aerror1("bad arg for lsd", a);
        while ((top = (int32_t)bignum_digits(a)[r]) == 0) r++;
        r = 31*r;
    }
    else aerror1("bad arg for lsd", a);
    if (top < 0) aerror1("negative arg for lsd", a);   // -ve arg
// top is non-zero here. See code in msd re the sixty four bit support.
    if (SIXTY_FOUR_BIT &&
        (top & (uintptr_t)UINT64_C(0xffffffff)) == 0)
        r += 32, top = (intptr_t)((int64_t)top >> 32);
    if ((top & 0xffffu) == 0) r += 16, top >>= 16;
    if ((top & 0xff) == 0)    r += 8,  top >>= 8;
    return onevalue(fixnum_of_int(r + lsd_table[top & 0xff]));
}

LispObject Linorm(LispObject env, LispObject a, LispObject k)
//
// This is a piece of magic especially designed to speed up the
// REDUCE big-float code.  It adjusts the integer a until it has
// just k bits, and returns a correction to the associated exponent.
// It combines aspects of msd, lsd, ash and a rounding operation. k must
// be positive.
//
{   uintptr_t kk;
    size_t bits;
    intptr_t top;
    uintptr_t bottom;
    size_t rtop = 0, rbottom = 0;
    bool was_fixnum = false, was_negative = false, round_up;
    if (is_fixnum(k) && (intptr_t)k >= 0) kk = int_of_fixnum(k);
    else aerror1("bad args for inorm", k);
    if (is_fixnum(a))
    {   top = int_of_fixnum(a);   // Beware - can now have up to 60 bits in it
        if (top == 0) aerror1("zero arg for inorm", a);
        was_negative = (top < 0);
        bottom = top;
        was_fixnum = true;
    }
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        if (!is_bignum_header(h)) aerror1("bad arg for inorm", a);
        rtop = (length_of_header(h)-CELL)/4 - 1;
        top = (int32_t)bignum_digits(a)[rtop];
        was_negative = (top < 0);
        rtop = 31*rtop;
        while ((bottom = bignum_digits(a)[rbottom]) == 0) rbottom++;
        rbottom = 31*rbottom;
    }
    else aerror1("bad arg for inorm", a);
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
//
    round_up = was_negative;
    if (rtop == rbottom) rtop++;
    bits = rtop - rbottom;             // bits used in the number
    if (bits <= kk) kk = rbottom;      // no rounding wanted
    else if (was_fixnum)
    {   intptr_t bit;
//
// If the input was a fixnum and I need to decrease its precision
// I will do it in-line here, mainly so that the bignum code that comes
// later will not have to worry so much about the possibility of having
// any fixnums around.
//
        kk = rtop - kk;
        bit = ((intptr_t)1) << (kk - 1);
        top = int_of_fixnum(a);
        if (top < 0)
        {   top = -top;
//
// It is almost the case that for negative values I should round if the
// bit I want to test is a zero (rather than a 1), but this is not true when
// the bit involved is the least significant set bit in the word.  So to
// keep it simple I negate, test, adjust and negate back when working with
// single precision numbers.  I also do the shifting right on the positive
// value to avoid problems with the bits that get shifted off, and with
// computers where right shifts are logical rather than arithmetic.
//
            if ((top & bit) != 0) top += bit;
            top = top >> kk;
            top = -top;
        }
        else
        {   if ((top & bit) != 0) top += bit;
            top = top >> kk;
        }
//
// All the shifts I do here move only zero bits off the bottom of the
// word, and so there are no issues about +ve vs -ve numbers to bother me.
//
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
//
// Here my input was a bignum and I have established that I not only need
// to shift it right but that I will need to lose some non-zero digits from
// the right hand end. To cope with this I need to decide whether it will
// round up or down, and then perform the appropriate shifts, including a
// post-normalisation to ensure that the mantissa of the number as returned
// is odd.
//
        kk = rtop - kk;
        if (rbottom == kk-1) round_up = true;
        else
        {   size_t wk1 = (kk-1) / 31, bk1 = (kk-1) % 31;
            intptr_t bit = ((intptr_t)1) << bk1;
            round_up = ((bit & bignum_digits(a)[wk1]) != 0);
            if (was_negative) round_up = !round_up;
        }
//
// Now I need to find out how much I will need to shift AFTER rounding
// and truncation to leave me with a properly normalised value.
//
        wk = kk / 31, bk = kk % 31;
//
// If I have a positive value that is not being rounded up I want to skip
// over 0 bits until I find a 1. Similarly for a negative value that is
// being rounded up.
//
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
//
// A positive value that is being rounded up or a negative one that is not
// should cause me to skip over 1 bits until I find a 0.  The 0 I find
// will be promoted into a 1 achieve the rounding I need.
//
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
//
// All the adjustment I now need to allow for right-shifting negative
// numbers and rounding off - at all reduces to just forcing the bottom bit
// of the result I compute here to be a 1!
//
        if (is_fixnum(a)) a |= 0x10;
        else bignum_digits(a)[0] |= 1;
    }
    a = cons(a, fixnum_of_int(kk));
    return onevalue(a);
}

//
// Was once implemented as a special form for Standard Lisp. Must be a regular
// function in Common Lisp. The performance gains I thought I might see by
// using a special form in Standard Lisp certainly only apply in interpreted
// code and so I will not view them as at all important now.
//

static LispObject Lplus(LispObject env, int nargs, ...)
//
// This adds up a whole bunch of numbers together.
//    (+ a1 a2 a3 a4 a5)                     is computed as
//    (+ a1 (+ a2 (+ a3 (+ a4 a5))))
//
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return fixnum_of_int(0);
    va_start(a, nargs);
    push_args(a, nargs);
//
// The actual args have been passed a C args - I can not afford to
// risk garbage collection until they have all been moved somewhere safe,
// and here that safe place is the Lisp stack.  I have to delay checking for
// overflow on same until all args have been pushed.
//
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        if (is_fixnum(r) && is_fixnum(w))
        {   intptr_t c = int_of_fixnum(r) + int_of_fixnum(w);
            if (intptr_valid_as_fixnum(c))
            {   r = fixnum_of_int(c);
                continue;
            }
        }
        r = plus2(r, w);
    }
    return onevalue(r);
}

static LispObject Ldifference(LispObject env, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    if (nargs == 1)
    {   pop(r);
        r = negate(r);
        return onevalue(r);
    }
    r = stack[1-nargs];
//
// (- a1 a2 a3 a4) is computed as
// (((a1 - a4) - a3) - a2) which does not seem too bad here.
//
    for (i=1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = difference2(r, w);
    }
    popv(1);
    return onevalue(r);
}

static LispObject Ltimes(LispObject env, int nargs, ...)
//
// This multiplies a whole bunch of numbers together.
//
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return fixnum_of_int(1);
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    pop(r);
    for (i=1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = times2(r, w);
    }
    return onevalue(r);
}

LispObject Lquotient_n(LispObject env, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    if (nargs == 1)
    {   pop(r);
        r = quot2(fixnum_of_int(1), r);
        return onevalue(r);
    }
    r = stack[1-nargs];
    for (i=1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = CLquot2(r, w);
    }
    popv(1);
    return onevalue(r);
}

LispObject LCLquotient_n(LispObject env, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    if (nargs == 1)
    {   pop(r);
        r = CLquot2(fixnum_of_int(1), r);
        return onevalue(r);
    }
    r = stack[1-nargs];
    for (i=1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = CLquot2(r, w);
    }
    popv(1);
    return onevalue(r);
}

LispObject LCLquotient(LispObject env, LispObject a, LispObject b)
{   return onevalue(CLquot2(a, b));
}

LispObject Lquotient(LispObject env, LispObject a, LispObject b)
{   return onevalue(quot2(a, b));
}

LispObject LCLquotient_1(LispObject env, LispObject b)
{   return onevalue(CLquot2(fixnum_of_int(1), b));
}

LispObject Lquotient_1(LispObject env, LispObject b)
{   return onevalue(quot2(fixnum_of_int(1), b));
}

LispObject Ldivide(LispObject env, LispObject a, LispObject b)
{   LispObject q;
    stackcheck2(0, a, b);
    mv_2 = SPID_NIL;
    q = quotrem2(a, b);
    if (is_spid(mv_2)) aerror2("divide", a, b);
    q = cons(q, mv_2);
    return onevalue(q);
}

LispObject Lrem(LispObject env, LispObject p, LispObject q)
{   return onevalue(Cremainder(p, q));
}

LispObject Lmod(LispObject env, LispObject p, LispObject q)
{   return onevalue(modulus(p, q));
}

LispObject Ltrap_floating_overflow(LispObject env, LispObject a)
{   bool o = trap_floating_overflow;
    trap_floating_overflow = (a != nil);
    return onevalue(Lispify_predicate(o));
}

LispObject Lplus2(LispObject env, LispObject p, LispObject q)
{   if (is_fixnum(p) && is_fixnum(q))
    {   intptr_t c = int_of_fixnum(p) + int_of_fixnum(q);
        if (intptr_valid_as_fixnum(c)) return onevalue(fixnum_of_int(c));
    }
    p = plus2(p, q);
    return onevalue(p);
}

LispObject Ltimes2(LispObject env, LispObject p, LispObject q)
{   return onevalue(times2(p, q));
}

LispObject Ldifference2(LispObject env, LispObject a, LispObject b)
{   return onevalue(difference2(a, b));
}

LispObject Lminus(LispObject env, LispObject a)
{   return onevalue(negate(a));
}

typedef LispObject boolopfn(LispObject, LispObject);

static struct bfz
{   boolopfn *fn;
    LispObject base;
} boolop_array[] =
{   {0,         0},
    {logand2,   fixnum_of_int(-1)},
    {0,         0},
    {0,         0},
    {0,         0},
    {0,         0},
    {logxor2,   fixnum_of_int(0)},
    {logior2,   fixnum_of_int(0)},
    {0,         0},
    {logeqv2,   fixnum_of_int(-1)},
    {0,         0},
    {0,         0},
    {0,         0},
    {0,         0},
    {0,         0},
    {0,         0}
};


static LispObject Lboolfn(LispObject env, int nargs, ...)
{   va_list a;
    LispObject r;
    int i;
    int32_t what = int_of_fixnum(qenv(env));
    if (nargs == 0) return onevalue(boolop_array[what].base);
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    pop(r);
    for (i=1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = (*boolop_array[what].fn)(r, w);
    }
    return onevalue(r);
}

LispObject Lzerop(LispObject env, LispObject a)
{   bool fg;
    fg = zerop(a);
    return onevalue(Lispify_predicate(fg));
}

LispObject Lonep(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(onep(a)));
}

LispObject Levenp(LispObject env, LispObject a)
{   if (is_fixnum(a))
        return onevalue(((int32_t)a & 0x10) == 0 ? lisp_true : nil);
    else if (is_numbers(a) && is_bignum(a))
        return onevalue((bignum_digits(a)[0] & 1) == 0 ? lisp_true : nil);
    aerror1("bad arg for evenp", a);
}

LispObject Loddp(LispObject env, LispObject a)
{   if (is_fixnum(a))
        return onevalue(((int32_t)a & 0x10) != 0 ? lisp_true : nil);
    else if (is_numbers(a) && is_bignum(a))
        return onevalue((bignum_digits(a)[0] & 1) != 0 ? lisp_true : nil);
    aerror1("bad arg for oddp", a);
}

LispObject Lminusp(LispObject env, LispObject a)
{
//
// For CSL I demand (minusp <non-number>) = nil.  Note that this ensures
// that minusp will not fail... so nil wil be intact on the way out.
//
    return onevalue(is_number(a) && minusp(a) ? lisp_true : nil);
}

LispObject Lplusp(LispObject env, LispObject a)
{   return onevalue(is_number(a) && plusp(a) ? lisp_true : nil);
}

//
// The next few functions take an arbitrary number of args in Common
// Lisp mode but just 2 args in CSL.
//

LispObject Leqn_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF) aerror("too many args for =");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool w = numeq2(r, s);
        if (!w)
        {   popv(nargs);
            return onevalue(nil);
        }
        r = s;
    }
    popv(nargs);
    return onevalue(lisp_true);
}

LispObject Leqn(LispObject env, LispObject a, LispObject b)
{   return onevalue(numeq2(a, b) ? lisp_true : nil);
}

LispObject Leqn_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

LispObject Llessp_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF) aerror("too many args for <");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool w = lessp2(r, s);
        if (!w)
        {   popv(nargs);
            return onevalue(nil);
        }
        r = s;
    }
    popv(nargs);
    return onevalue(lisp_true);
}

LispObject Llessp(LispObject env, LispObject a, LispObject b)
{   return onevalue(lessp2(a, b) ? lisp_true : nil);
}

LispObject Llessp_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

LispObject Lgreaterp_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF) aerror("too many args for >");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool w = lessp2(s, r);
        if (!w)
        {   popv(nargs);
            return onevalue(nil);
        }
        r = s;
    }
    popv(nargs);
    return onevalue(lisp_true);
}

LispObject Lgreaterp(LispObject env, LispObject a, LispObject b)
{   return onevalue(lessp2(b, a) ? lisp_true : nil);
}

LispObject Lgreaterp_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

static LispObject Lneqn(LispObject env, int nargs, ...)
//
// /= is supposed to check that no pair of args match.
//
{   int i, j;
    LispObject *r;
    va_list a;
    if (nargs < 2) return onevalue(lisp_true);
    r = (LispObject *)&work_1;
    if (nargs > ARG_CUT_OFF) aerror("too many args for /=");
    va_start(a, nargs);
    for (i=0; i<nargs; i++) r[i] = va_arg(a, LispObject);
    va_end(a);
//
// This bit is OK provided numeq2 does not mess with work_1, ...
// and I think that unless funny tracing or errors occur that should
// be OK.
//
    for (i = 1; i<nargs; i++)
    {   LispObject n1 = r[i];
        for (j=0; j<i; j++)
        {   LispObject n2 = r[j];
            if (numeq2(n1, n2)) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

LispObject Lneq_2(LispObject env, LispObject a, LispObject b)
{   bool w = numeq2(a, b);
    return onevalue(w ? nil : lisp_true);
}

LispObject Lneq_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

LispObject Lgeq_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF) aerror("too many args for >=");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool w = lesseq2(s, r);
        if (!w)
        {   popv(nargs);
            return onevalue(nil);
        }
        r = s;
    }
    popv(nargs);
    return onevalue(lisp_true);
}

LispObject Lgeq(LispObject env, LispObject a, LispObject b)
{   bool w = lesseq2(b, a);
    return onevalue(w ? lisp_true : nil);
}

LispObject Lgeq_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

LispObject Lleq_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 2) return onevalue(lisp_true);
    if (nargs > ARG_CUT_OFF) aerror("too many args for <=");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool fg = lesseq2(r, s);
        if (!fg)
        {   popv(nargs);
            return onevalue(nil);
        }
        r = s;
    }
    popv(nargs);
    return onevalue(lisp_true);
}

LispObject Lleq(LispObject env, LispObject a, LispObject b)
{   bool w = lesseq2(a, b);
    return onevalue(w ? lisp_true : nil);
}

LispObject Lleq_1(LispObject, LispObject)
{   return onevalue(lisp_true);
}

LispObject Lmax2(LispObject env, LispObject a, LispObject b)
{   bool w;
    push2(a, b);
    w = lessp2(a, b);
    pop2(b, a);
    if (w) return onevalue(b);
    else return onevalue(a);
}

LispObject Lmin2(LispObject env, LispObject a, LispObject b)
{   bool w;
    push2(a, b);
    w = lessp2(b, a);
    pop2(b, a);
    if (w) return onevalue(b);
    else return onevalue(a);
}

LispObject Lmax(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 1) aerror("max");
    if (nargs > ARG_CUT_OFF) aerror("too many args for max");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool fg;
        push2(r, s);
        fg = lessp2(r, s);
        pop2(s, r);
        if (fg) r = s;
    }
    popv(nargs);
    return onevalue(r);
}

LispObject Lmin(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs < 1) aerror("min");
    if (nargs > ARG_CUT_OFF) aerror("too many args for min");
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    r = stack[1-nargs];
    for (i = 1; i<nargs; i++)
    {   LispObject s = stack[1+i-nargs];
        bool fg;
        push2(r, s);
        fg = lessp2(s, r);
        pop2(s, r);
        if (fg) r = s;
    }
    popv(nargs);
    return onevalue(r);
}

LispObject Lrational(LispObject env, LispObject a)
{   return onevalue(rational(a));
}

static LispObject Lmanexp(LispObject env, LispObject a)
{   int x;
    double f;
// AT present I do not support 128-bit floats here @@@
    if (!is_float(a))  aerror1("arg is not a floating-point number", a);
    f = float_of_number(a);
    f = frexp(f, &x);
    return onevalue(cons(make_boxfloat(f, TYPE_DOUBLE_FLOAT),
                         fixnum_of_int(x)));
}

static LispObject Lrationalize(LispObject env, LispObject a)
{   a = rationalize(a);
    return onevalue(a);
}

//
// The following random number generator is taken from the Norcroft
// C library, but is included here so that random sequences will be
// identical across all implementations of CSL, and because I have bad
// and pessimistic expectations about the quality of random number
// generators built into typical C libraries. That is not to say that
// I ought not to be somewhat cynical about the code I have implemented
// here! But it is tolerably fast and less dreadful than those old
// 32-bit linear congruential mistakes. The initial values here
// are a repeatable set of initial "random" values.
//
// Well this was now implemented quite a long while ago and the standards
// for pseudo-random sequences have probably moved on substantially. So this
// probably really deserves review!
//

static uint32_t random_number_seed[55] =
{   0x0d649239,    0x7c09f002,    0x6da2cd88,    0x969df534,
    0xfd7aca32,    0x16d89669,    0xc334a2fc,    0x0aba529c,
    0xdea5e90d,    0xdf06db3b,    0xf07d65eb,    0x74a5bf84,
    0x81e0b59e,    0xf2ac7c6c,    0x14339237,    0xb6b89675,
    0x61a66ca1,    0xa3fd9c3c,    0xed3ed908,    0xb4ffaf68,
    0xe43adf58,    0x6c108373,    0x14bbefe5,    0x20045563,
    0x8c54d44e,    0xd3470877,    0x5a8ae401,    0xa38c47fd,
    0x70ec616e,    0x3a8e3c82,    0x5bf48b37,    0x98d07ad8,
    0x6753e8c1,    0xc120d571,    0x7d308c18,    0x014ef96d,
    0x7aae7f25,    0x817e97c8,    0x8127a883,    0x1f88de19,
    0x68c2f294,    0x394ea2dd,    0x2f475077,    0x1fbea2a6,
    0x6e943040,    0xfa736fbb,    0x89e5fc31,    0xca16186e,
    0x720e8da7,    0xd8c0b092,    0xb340e967,    0x6e0ba043,
    0x1250d232,    0x061a9e86,    0xaa710c75
};

static int random_j = 23, random_k = 54;

static bool randomization_request = false;

//
// If the user specifies a random number seed of zero I will try to
// start things in as unpredictable a state as I reasonably can. To
// achieve this I will update a block of unpredictable data at a
// number of points during a CSL run, garnering incremental amounts
// of fairly low grade "randomness" from timing information and the
// memory addresses that get allocated to CSL. Because it will take
// a while for such information to build up I arrange that specifying
// a random seed of zero does not do anything at once (and in particular
// the implicit call of this nature when CSL starts does not do much),
// but the unpredictable mess I accumulate is inspected the first time
// any user actually asks for a random value. Since user keyboard input
// contributes to the clutter it could be that a cautious user will ask the
// user to type in a long string of gibberish before asking for any
// random numbers, and the gibberish typed will then in fact form part
// of the seed that will be used.  On Windows I can hook in and make
// mouse activity etc contribute to the seed too.
//

static void randomize(void)
{   int i;
    random_j = 23;
    random_k = 54;
    for (i=20; i<48; i+=4)
    {   CSL_MD5_Init();
        CSL_MD5_Update(unpredictable, sizeof(unpredictable));
        CSL_MD5_Final((unsigned char *)&random_number_seed[i]);
        inject_randomness((int)time(NULL));
    }
//
// Note that I do not initialise the whole array of seed values here.
// Leaving something over can count as part of the unpredictability! But I
// do try to put in mess through the parts of the seed that will be used
// first so that any obvious patterns will get clobbered.
//
    random_number_seed[0] |= 1;
    randomization_request = false;
}

uint32_t Crand(void)
{
//
// See Knuth vol 2 section 3.2.2 for a discussion of this random
// number generator.
//
    uint32_t temp;
    if (randomization_request) randomize();
    temp = (random_number_seed[random_k] += random_number_seed[random_j]);
    if (--random_j < 0) random_j = 54, --random_k;
    else if (--random_k < 0) random_k = 54;
    return temp;
}

void Csrand(uint32_t seed, uint32_t seed2)
{
//
// This allows you to put 64 bits of seed into the random sequence,
// but it is very improbable that you have any good source of randomness
// that good to start with! The input seeds are scrambled using md5
// and then rather crudely widened to fill the whole array of seed data.
// If the seed is specified as (0,0) then I will initialise things using
// information from the time of day and the clock. This is NOT very
// good, especially since I only use portable C-library ways of reading
// the time. But it will at least not repeat for any single user and
// since the clock information is then scrambled via md5 it will APPEAR
// fairly unpredictable.
//
    int i;
    unsigned char seedv[16], *p;
    random_j = 23;
    random_k = 54;
    i = 0;
    if (seed == 0 && seed2 == 0)
    {   randomization_request = true;
        return;
    }
    randomization_request = false;
//
// This version was byte-order sensitive, but documents the idea
// that I first had.
//    random_number_seed[0] = seed;
//    random_number_seed[1] = 0x12345678;
//    random_number_seed[2] = 0xa7086dee;
//    random_number_seed[3] = seed2;
// then I used the first 16 bytes of random_number_seed as input to md5.
//
    seedv[0] = (seed & 0xff);
    seedv[1] = ((seed >> 8) & 0xff);
    seedv[2] = ((seed >> 16) & 0xff);
    seedv[3] = ((seed >> 24) & 0xff);
    seedv[4] = 0x78;
    seedv[5] = 0x56;
    seedv[6] = 0x34;
    seedv[7] = 0x12;
    seedv[8] = 0xee;
    seedv[9] = 0x6d;
    seedv[10] = 0x08;
    seedv[11] = 0xa7;
    seedv[12] = (seed2 & 0xff);
    seedv[13] = ((seed2 >> 8) & 0xff);
    seedv[14] = ((seed2 >> 16) & 0xff);
    seedv[15] = ((seed2 >> 24) & 0xff);
#ifdef TRACE_RANDOM
    for (i=0; i<16; i++) term_printf("%.2x ", seedv[i]);
    term_printf("\n");
#endif
//
// Next I will scramble the seed data that I have been given using md5
// and place the resulting 128 bits of digested stuff in the start of
// the seed vector.
//
    CSL_MD5_Init();
    CSL_MD5_Update(seedv, 16);
    CSL_MD5_Final((unsigned char *)&random_number_seed[0]);
//
// The remainder of the vector gets filled using a simple linear
// congruential scheme. Note that MD5 filled in BYTES and what I need next
// is an INTEGER, so to be byte-order insensitive I need to do things
// the long way.
//
    i = 4;
//
// Does anybody want to think about "strict alisasing" and the next little
// fragment of code? Ha Ha.
//
    p = (unsigned char *)random_number_seed;
    seed = p[0] | (p[1]<<8) | (p[2]<<16) | (p[3]<<24);
    random_number_seed[0] = seed;
    random_number_seed[1] = p[4] | (p[5]<<8) | (p[6]<<16) | (p[7]<<24);
    random_number_seed[2] = p[8] | (p[9]<<8) | (p[10]<<16) | (p[11]<<24);
    random_number_seed[3] = p[12] | (p[13]<<8) | (p[14]<<16) | (p[15]<<24);
    while (i<55)
    {   seed = 69069*seed + 1725307361;  // computed modulo 2^32
        random_number_seed[i++] = seed;
    }
//
// I would like to make the least significant bits a little less
// regular even to start with, so I xor in from one of the words that
// md5 gave me.
//
    seed = random_number_seed[1];
    i = 55-30;
    while (i<55)
    {   random_number_seed[i++] ^= seed & 1;
        seed = seed >> 1;
    }
//
// If all the least significant bits were zero to start with they would
// always stay that way, so I force one of them to be 1.
//
    random_number_seed[21] |= 1;
#ifdef TRACE_RANDOM
    for (i=0; i<55; i++) term_printf("%2d %.8x\n", i, random_number_seed[i]);
#endif
}

LispObject Lrandom_2(LispObject env, LispObject a, LispObject bb)
{
#ifdef COMMON
    LispObject b;
//
// Common Lisp expects an optional second arg to be used for the random
// state - at present I do not support that, but it will not be too hard
// when I get around to it...
//
    b = bb;
#endif // COMMON
    if (is_fixnum(a))
    {   size_t v = int_of_fixnum(a), p, q;
        if (v <= 0) aerror1("random-number", a);
// (random 1) always returns zero - a rather silly case!
        else if (v == 1) return onevalue(fixnum_of_int(0));
//
// I generate a value that is an exact multiple of my range (v) and
// pick random bitpatterns until I find one less than that.  On average
// I will have only VERY slightly more than one draw needed, and doing things
// this way ought to ensure that my pseudo random numbers are uniformly
// distributed provided that the underlying generator is well behaved.
//
        if (SIXTY_FOUR_BIT)
        {   p = v*(INT64_C(0x7fffffffffffffff)/v);
            do
            {   q = (int64_t)Crand()<<31 ^ Crand();
            } while (q > p);
            return onevalue(fixnum_of_int(q % v));
        }
        else
        {   p = v*(0x7fffffff/v);
            do q = ((uint32_t)Crand()) >> 1; while (q > p);
            return onevalue(fixnum_of_int(q % v));
        }
    }
    if (is_numbers(a))
    {   int32_t len, len1, msd;
        uint32_t w, w1;
        LispObject r;
        if (!is_bignum(a)) aerror1("random-number", a);
        len = bignum_length(a);
        push(a);
        r = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
        pop(a);
        len1 = (len-CELL)/4-1;
    restart:
        len = len1;
        msd = bignum_digits(a)[len];
        if (msd < 0) aerror("negative arg for random"); // -ve arg
        if (msd == 0)
        {   bignum_digits(r)[len] = 0;
            len--;
            msd = bignum_digits(a)[len];
        }
        for (;;)
        {   w = (0xffffffffU/((uint32_t)msd+1U))*((uint32_t)msd+1U);
            do w1 = (uint32_t)Crand(); while (w1 >= w);
            w1 = w1%((uint32_t)msd+1U);
            bignum_digits(r)[len] = w1;
            if ((int32_t)w1 != msd) break;
//
// The loop to restart on the next line is when the random value I
// have built up word by word ends up being equal to the input number - I
// will discard it and start again in that case.
//
            if (len == 0) goto restart;
            len--;
            msd = bignum_digits(a)[len];
        }
//
// having got some leading digits properly set up I can fill in the rest
// as totally independent bit-patterns.
//
        for (len--; len>=0; len--)
            bignum_digits(r)[len] = ((uint32_t)Crand())>>1;
        a = shrink_bignum(r, len1);
        return onevalue(a);
    }
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        double d = float_of_number(a), v;
//
// The calculation here turns 62 bits of integer data into a floating
// point number in the range 0.0 (inclusive) to 1.0 (exclusive).  Well,
// to be more precise, rounding the value to the machine's floating point
// format may round it up to be exactly 1.0, so I discard and cases where
// that happens (once in several blue moons...).  If I wrote code that
// knew exactly how many bits my floating point format had I could avoid
// the need for that extra test, but it does not seem very painful to me
// and I prefer the more portable code.
//
        do
        {   v = ((double)(int32_t)(Crand() & 0x7fffffff)) / TWO_31;
            v += (double)(int32_t)(Crand() & 0x7fffffff);
            v /= TWO_31;
            v *= d;
        }
        while (v == d);
        a = make_boxfloat(v, type_of_header(h));
        return onevalue(a);
    }
    if (is_sfloat(a))
    {   Float_union d;
        Float_union v;
        d.f = value_of_immediate_float(a);
        do
        {   v.f = (float)(int32_t)(Crand() & 0x7fffffff)/(float)TWO_31;
            v.f = v.f*d.f;
        }
        while ((v.i & ~0xf) == (d.i & ~0xf));
        d.f = v.f;
        return onevalue(pack_immediate_float(v.f, a));
    }
    aerror1("random-number", a);
}

LispObject Lrandom(LispObject env, LispObject a)
{   if (is_fixnum(a))
    {   intptr_t v = int_of_fixnum(a), p, q;
        if (v <= 0) aerror1("random-number -ve argument", a);
// (random 1) always returns zero - a rather silly case!
        else if (v == 1) return onevalue(fixnum_of_int(0));
//
// I generate a value that is an exact multiple of my range (v) and
// pick random bitpatterns until I find one less than that.  On average
// I will have only VERY slightly less than one draw needed, and doing things
// this way ought to ensure that my pseudo random numbers are uniformly
// distributed provided that the underlying generator is well behaved.
//
        if (SIXTY_FOUR_BIT)
        {   p = v*(INT64_C(0x7fffffffffffffff)/v);
            do
            {   q = (int64_t)Crand()<<31 ^ Crand();
            } while (q > p);
            return onevalue(fixnum_of_int(q % v));
        }
        else
        {   p = v*(0x7fffffff/v);
            do q = ((uint32_t)Crand()) >> 1; while (q > p);
            return onevalue(fixnum_of_int(q % v));
        }
    }
    if (is_numbers(a))
    {   int32_t len, len1, msd;
        uint32_t w, w1;
        LispObject r;
        if (!is_bignum(a)) aerror1("random-number", a);
        len = bignum_length(a);
        push(a);
        r = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
        pop(a);
        len1 = (len-CELL)/4-1;
    restart:
        len = len1;
        msd = bignum_digits(a)[len];
        if (msd < 0) aerror("negative arg for random"); // -ve arg
        if (msd == 0)
        {   bignum_digits(r)[len] = 0;
            len--;
            msd = bignum_digits(a)[len];
        }
        for (;;)
        {   w = (0xffffffffU/((uint32_t)msd+1U))*((uint32_t)msd+1U);
            do w1 = (uint32_t)Crand(); while (w1 >= w);
            w1 = w1%((uint32_t)msd+1U);
            bignum_digits(r)[len] = w1;
            if ((int32_t)w1 != msd) break;
//
// The loop to restart on the next line is when the random value I
// have built up word by word ends up being equal to the input number - I
// will discard it and start again in that case.
//
            if (len == 0) goto restart;
            len--;
            msd = bignum_digits(a)[len];
        }
//
// having got some leading digits properly set up I can fill in the rest
// as totally independent bit-patterns.
//
        for (len--; len>=0; len--)
            bignum_digits(r)[len] = ((uint32_t)Crand())>>1;
        return onevalue(shrink_bignum(r, len1));
    }
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        double d = float_of_number(a), v;
//
// The calculation here turns 62 bits of integer data into a floating
// point number in the range 0.0 (inclusive) to 1.0 (exclusive).  Well,
// to be more precise, rounding the value to the machine's floating point
// format may round it up to be exactly 1.0, so I discard and cases where
// that happens (once in several blue moons...).  If I wrote code that
// knew exactly how many bits my floating point format had I could avoid
// the need for that extra test, but it does not seem very painful to me
// and I prefer the more portable code.
//
        do
        {   v = ((double)(int32_t)(Crand() & 0x7fffffff)) / TWO_31;
            v += (double)(int32_t)(Crand() & 0x7fffffff);
            v /= TWO_31;
            v *= d;
        }
        while (v == d);
        a = make_boxfloat(v, type_of_header(h));
        return onevalue(a);
    }
    if (is_sfloat(a))
    {   Float_union d;
        Float_union v;
        d.i = a - XTAG_SFLOAT;
        do
        {   v.f = (float)(int32_t)(Crand() & 0x7fffffff)/(float)TWO_31;
            v.f = v.f*d.f;
        }
        while ((v.i & ~0xf) == (d.i & ~0xf));
        d.f = v.f;
        return onevalue(low32((d.i & ~0xf) + XTAG_SFLOAT));
    }
    aerror1("random-number", a);
}

LispObject Lnext_random(LispObject, int nargs, ...)
//
// Returns a random positive fixnum.  27 bits in this Lisp! At present this
// returns 27 bits whether on a 32 or 64-bit machine...
//
{   int32_t r;
    argcheck(nargs, 0, "next-random");
    r = Crand();
    return onevalue((LispObject)((r & 0x7ffffff0) + TAG_FIXNUM));
}

LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b)
{
//
// Nasty temporary hack here to allow me to set the seed for the
// random number generator in Standard Lisp mode.  I need to re-think
// this soon before it feels frozen in! Oops - too late!!!
//
    if (!is_fixnum(a)) aerror1("make-random-state", a);
    Csrand(int_of_fixnum(a),
           is_fixnum(b) ? int_of_fixnum(b) : 0);
    return onevalue(nil);
}

LispObject Lmake_random_state1(LispObject env, LispObject a)
{   if (!is_fixnum(a)) aerror1("make-random-state", a);
    Csrand(int_of_fixnum(a), 0);
    return onevalue(nil);
}

//
// The function md5() can be given a number or a string as an argument,
// and it uses the md5 message digest algorithm to reduce it to a
// numeric value in the range 0 to 2^128.
// Well actually I will also allow an arbitrary expression, which I
// will often treat as if it has to be printed... Note that these days
// md5 is not considered secure, and sha1 that followed it is also not
// considered secure, so anybody worried by security needs at least sha2!
//

LispObject Lmd5(LispObject env, LispObject a)
{   LispObject r;
    unsigned char md[16];
    uint32_t v0, v1, v2, v3, v4;
    int32_t len, i;
    if (is_fixnum(a))
    {   sprintf((char *)md, "%.7lx  ", (unsigned long)(a>>4)&0x0fffffff);
        CSL_MD5_Init();
        CSL_MD5_Update(md, 8);
    }
    else if (is_numbers(a) && is_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
        for (i=CELL; i<len; i+=4)
        {   sprintf((char *)md, "%.8x", bignum_digits(a)[(i-CELL)/4]);
            CSL_MD5_Update(md, 8);
        }
    }
    else if (is_vector(a) && is_string(a))
    {   len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update((const unsigned char *)"\"", 1);
        CSL_MD5_Update((unsigned char *)(a + CELL - TAG_VECTOR), len-CELL);
    }
    else checksum(a);
    CSL_MD5_Final(md);
//    for (i=0; i<16; i++) printf("%x ", md[i] & 0xff);
//   printf("\n");
//
    v0 = md[0] + (md[1]<<8) + (md[2]<<16) + (md[3]<<24);
    v1 = md[4] + (md[5]<<8) + (md[6]<<16) + (md[7]<<24);
    v2 = md[8] + (md[9]<<8) + (md[10]<<16) + (md[11]<<24);
    v3 = md[12] + (md[13]<<8) + (md[14]<<16) + (md[15]<<24);
// I will deal with caes where the top 64 bits are all zero first - very
// uncommon I know, but disposoing of that case here will simplify the code
// that follows!
    if (v3 == 0 && v2 == 0)
    {   r = make_lisp_unsigned64((uint64_t)v1<<32 | v0);
        return onevalue(r);
    }
    v4 = v3 >> 28;
    v3 = ((v3 << 3) | (v2 >> 29)) & 0x7fffffff;
    v2 = ((v2 << 2) | (v1 >> 30)) & 0x7fffffff;
    v1 = ((v1 << 1) | (v0 >> 31)) & 0x7fffffff;
    v0 &= 0x7fffffff;
//
// Note the funny tests. This is because in my representation the
// top word of a bignum is a 2s complement signed value and to keep clear
// of overflow that means I use an extra digit slightly before one might
// imagine it is necessary!
//
    if (v4 != 0 || (v3 & 0x40000000) != 0) len = CELL+20;
    else if (v3 != 0 || (v2 & 0x40000000) != 0) len = CELL+16;
    else if (v2 != 0 || (v1 & 0x40000000) != 0) len = CELL+12;
    else abort();  // All smaller cases were filtered earlier!
    r = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
    if (SIXTY_FOUR_BIT)
    {   switch (len)
        {   case CELL+20:
                bignum_digits(r)[5] = 0;  // zeros out padding word as necessary
                bignum_digits(r)[4] = v4;
            case CELL+16:
            case CELL+12:
                bignum_digits(r)[3] = v3;
                bignum_digits(r)[2] = v2;
                bignum_digits(r)[1] = v1;
                bignum_digits(r)[0] = v0;
        }
    }
    else
    {   switch (len)
        {   case CELL+20:
            case CELL+16:
                bignum_digits(r)[4] = v4; // zeros out padding word as necessary
                bignum_digits(r)[3] = v3;
            case CELL+12:
                bignum_digits(r)[2] = v2;
                bignum_digits(r)[1] = v1;
                bignum_digits(r)[0] = v0;
        }
    }
//  validate_number("MD5", r, r, r);
    return onevalue(r);
}

//
// For testing the MD5 code... processes a string "raw".
//

LispObject Lmd5string(LispObject env, LispObject a)
{   LispObject r;
    unsigned char md[16];
    uint32_t v0, v1, v2, v3, v4;
    int32_t len, i;
    if (is_vector(a) && is_string(a))
    {   len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update((unsigned char *)(a + CELL - TAG_VECTOR), len-CELL);
    }
    else return onevalue(nil);
    CSL_MD5_Final(md);
    for (i=0; i<16; i++) printf("%x ", md[i] & 0xff);
    printf("\n");
    v0 = md[0] + (md[1]<<8) + (md[2]<<16) + (md[3]<<24);
    v1 = md[4] + (md[5]<<8) + (md[6]<<16) + (md[7]<<24);
    v2 = md[8] + (md[9]<<8) + (md[10]<<16) + (md[11]<<24);
    v3 = md[12] + (md[13]<<8) + (md[14]<<16) + (md[15]<<24);
    if (v3 == 0 && v2 == 0)
    {   r = make_lisp_unsigned64((uint64_t)v1<<32 | v0);
        return onevalue(r);
    }
    v4 = v3 >> 28;
    v3 = ((v3 << 3) | (v2 >> 29)) & 0x7fffffff;
    v2 = ((v2 << 2) | (v1 >> 30)) & 0x7fffffff;
    v1 = ((v1 << 1) | (v0 >> 31)) & 0x7fffffff;
    v0 &= 0x7fffffff;
//
// Note the funny tests. This is because in my representation the
// top word of a bignum is a 2s complement signed value and to keep clear
// of overflow that means I use an extra digit slightly before one might
// imagine it is necessary!
//
    if (v4 != 0 || (v3 & 0x40000000) != 0) len = CELL+20;
    else if (v3 != 0 || (v2 & 0x40000000) != 0) len = CELL+16;
    else if (v2 != 0 || (v1 & 0x40000000) != 0) len = CELL+12;
    else abort();
    r = getvector(TAG_NUMBERS, TYPE_BIGNUM, len);
    if (SIXTY_FOUR_BIT)
    {   switch (len)
        {   case CELL+20:
                bignum_digits(r)[5] = 0;  // zeros out padding word as necessary
                bignum_digits(r)[4] = v4;
            case CELL+16:
            case CELL+12:
                bignum_digits(r)[3] = v3;
                bignum_digits(r)[2] = v2;
                bignum_digits(r)[1] = v1;
                bignum_digits(r)[0] = v0;
                break;
        }
    }
    else
    {   switch (len)
        {   case CELL+20:
            case CELL+16:
                bignum_digits(r)[4] = v4; // zeros out padding word as necessary
                bignum_digits(r)[3] = v3;
            case CELL+12:
                bignum_digits(r)[2] = v2;
                bignum_digits(r)[1] = v1;
                bignum_digits(r)[0] = v0;
                break;
        }
    }
//  validate_number("MD5", r, r, r);
    return onevalue(r);
}

//
// md60 is a function that uses MD5 but then returns just about 60 bits
// of number not 128. It is for use when the full 128 bits of checksum
// would be clumsy overkill.
//
// Note that this version really does compute md5 and then just return the
// low 60 bits. A previous implementation that I had went to some trouible
// to ensure that the value returned was always represented as a bignum,
// and specifically that the top 32 bits of that value were never all zero.
// I now forget my exact reasoning for doing that, and it was clerarly a
// rather odd thing to do! On a 64-bit machine a 60-bit value will be
// a fixnum half the time (ie when its most significant bit is zero).
//

LispObject Lmd60(LispObject env, LispObject a)
{   unsigned char md[16];
    uint32_t v0, v1;
    int32_t len, i;
    if (is_fixnum(a))
    {   sprintf((char *)md, "%.7lx  ", (unsigned long)(a>>4) & 0x0fffffff);
        CSL_MD5_Init();
        CSL_MD5_Update(md, 8);
    }
    else if (is_numbers(a) && is_bignum_header(numhdr(a)))
    {   len = length_of_header(numhdr(a));
        CSL_MD5_Init();
        for (i=CELL; i<len; i+=4)
        {   sprintf((char *)md, "%.8x", bignum_digits(a)[(i-CELL)/4]);
            CSL_MD5_Update(md, 8);
        }
    }
    else if (is_vector(a) && is_string(a))
    {   len = length_of_byteheader(vechdr(a));
        CSL_MD5_Init();
        CSL_MD5_Update((const unsigned char *)"\"", 1);
        CSL_MD5_Update((unsigned char *)(a + CELL - TAG_VECTOR), len-CELL);
    }
    else checksum(a);
    CSL_MD5_Final(md);
    v0 = md[0] + (md[1]<<8) + (md[2]<<16) + (md[3]<<24);
    v1 = md[4] + (md[5]<<8) + (md[6]<<16) + (md[7]<<24);
    a = make_lisp_unsigned64((uint64_t)v1<<32 | v0);
//  validate_number("MD60", a, a, a);
    return onevalue(a);
}

static LispObject Llogand2(LispObject env, LispObject a1, LispObject a2)
{   return Lboolfn(env, 2, a1, a2);
}

static LispObject Llogeqv2(LispObject env, LispObject a1, LispObject a2)
{   return Lboolfn(env, 2, a1, a2);
}

static LispObject Llogxor2(LispObject env, LispObject a1, LispObject a2)
{   return Lboolfn(env, 2, a1, a2);
}

static LispObject Llogor2(LispObject env, LispObject a1, LispObject a2)
{   return Lboolfn(env, 2, a1, a2);
}

static LispObject Lvalidate(LispObject env, LispObject a)
{   validate_number("validate-number", a, fixnum_of_int(0), fixnum_of_int(0));
    return onevalue(a);
}

static LispObject Lvalidate2(LispObject env, LispObject a, LispObject b)
{   validate_number("validate-number", a, b, fixnum_of_int(0));
    return onevalue(a);
}

setup_type const arith06_setup[] =
{   {"ash",                     TOO_FEW_2, Lash, WRONG_NO_2},
    {"ash1",                    TOO_FEW_2, Lash1, WRONG_NO_2},
    {"lshift",                  TOO_FEW_2, Lash, WRONG_NO_2},
    {"ashift",                  TOO_FEW_2, Lash1, WRONG_NO_2},
    {"divide",                  TOO_FEW_2, Ldivide, WRONG_NO_2},
    {"evenp",                   Levenp, TOO_MANY_1, WRONG_NO_1},
    {"inorm",                   TOO_FEW_2, Linorm, WRONG_NO_2},
    {"logand",                  Lidentity, Llogand2, Lboolfn},
    {"land",                    Lidentity, Llogand2, Lboolfn},
    {"logeqv",                  Lidentity, Llogeqv2, Lboolfn},
    {"lognot",                  Llognot, TOO_MANY_1, WRONG_NO_1},
    {"lnot",                    Llognot, TOO_MANY_1, WRONG_NO_1},
    {"logxor",                  Lidentity, Llogxor2, Lboolfn},
    {"lxor",                    Lidentity, Llogxor2, Lboolfn},
    {"leqv",                    Lidentity, Llogeqv2, Lboolfn},
    {"lnot",                    Llognot, TOO_MANY_1, WRONG_NO_1},
    {"lsd",                     Llsd, TOO_MANY_1, WRONG_NO_1},
    {"make-random-state",       Lmake_random_state1, Lmake_random_state, WRONG_NO_2},
    {"manexp",                  Lmanexp, TOO_MANY_1, WRONG_NO_1},
    {"max",                     Lidentity, Lmax2, Lmax},
    {"max2",                    TOO_FEW_2, Lmax2, WRONG_NO_2},
    {"min",                     Lidentity, Lmin2, Lmin},
    {"min2",                    TOO_FEW_2, Lmin2, WRONG_NO_2},
    {"minus",                   Lminus, TOO_MANY_1, WRONG_NO_1},
    {"minusp",                  Lminusp, TOO_MANY_1, WRONG_NO_1},
    {"mod",                     TOO_FEW_2, Lmod, WRONG_NO_2},
    {"msd",                     Lmsd, TOO_MANY_1, WRONG_NO_1},
    {"oddp",                    Loddp, TOO_MANY_1, WRONG_NO_1},
    {"onep",                    Lonep, TOO_MANY_1, WRONG_NO_1},
    {"plusp",                   Lplusp, TOO_MANY_1, WRONG_NO_1},
    {"rational",                Lrational, TOO_MANY_1, WRONG_NO_1},
    {"rationalize",             Lrationalize, TOO_MANY_1, WRONG_NO_1},
    {"zerop",                   Lzerop, TOO_MANY_1, WRONG_NO_1},
    {"md5",                     Lmd5, TOO_MANY_1, WRONG_NO_1},
    {"md5string",               Lmd5string, TOO_MANY_1, WRONG_NO_1},
    {"md60",                    Lmd60, TOO_MANY_1, WRONG_NO_1},
    {"trap-floating-overflow",  Ltrap_floating_overflow, TOO_MANY_1, WRONG_NO_1},
    {"*",                       Lidentity, Ltimes2, Ltimes},
    {"+",                       Lidentity, Lplus2, Lplus},
    {"-",                       Lminus, Ldifference2, Ldifference},
    {"/",                       LCLquotient_1, LCLquotient, WRONG_NO_2}, //LCLquotient_n},
    {"/=",                      Lneq_1, Lneq_2, Lneqn},
    {"1+",                      Ladd1, TOO_MANY_1, WRONG_NO_1},
    {"1-",                      Lsub1, TOO_MANY_1, WRONG_NO_1},
    {"<",                       Llessp_1, Llessp, Llessp_n},
    {"<=",                      Lleq_1, Lleq, Lleq_n},
    {"=",                       Leqn_1, Leqn, Leqn_n},
    {">",                       Lgreaterp_1, Lgreaterp, Lgreaterp_n},
    {">=",                      Lgeq_1, Lgeq, Lgeq_n},
    {"logior",                  Lidentity, Llogor2, Lboolfn},
    {"rem",                     TOO_FEW_2, Lrem, WRONG_NO_2},
    {"random",                  Lrandom, Lrandom_2, WRONG_NO_1},
    {"next-random-number",      WRONG_NO_0A, WRONG_NO_0B, Lnext_random},
    {"random-number",           Lrandom, TOO_MANY_1, WRONG_NO_1},
    {"random-fixnum",           WRONG_NO_0A, WRONG_NO_0B, Lnext_random},
//
// I always provide the old style names to make porting code easier for me
//
    {"float",                   Lfloat, Lfloat_2, WRONG_NO_1},
    {"times",                   Lidentity, Ltimes2, Ltimes},
    {"plus",                    Lidentity, Lplus2, Lplus},
    {"times2",                  TOO_FEW_2, Ltimes2, WRONG_NO_2},
    {"plus2",                   TOO_FEW_2, Lplus2, WRONG_NO_2},
    {"difference",              Lminus, Ldifference2, Ldifference},
// I leave QUOTIENT as the integer-truncating form, while "/" gives ratios
    {"quotient",                Lquotient_1, Lquotient, Lquotient_n},
    {"remainder",               TOO_FEW_2, Lrem, WRONG_NO_2},
    {"add1",                    Ladd1, TOO_MANY_1, WRONG_NO_1},
    {"sub1",                    Lsub1, TOO_MANY_1, WRONG_NO_1},
    {"lessp",                   Llessp_1, Llessp, Llessp_n},
    {"leq",                     Lleq_1, Lleq, Lleq_n},
    {"eqn",                     Leqn_1, Leqn, Leqn_n},
    {"greaterp",                Lgreaterp_1, Lgreaterp, Lgreaterp_n},
    {"geq",                     Lgeq_1, Lgeq, Lgeq_n},
    {"logor",                   Lidentity, Llogor2, Lboolfn},
    {"lor",                     Lidentity, Llogor2, Lboolfn},
    {"validate-number",         Lvalidate, Lvalidate2, WRONG_NO_1},
    {NULL,                      0, 0, 0}
};

// end of arith06.cpp
