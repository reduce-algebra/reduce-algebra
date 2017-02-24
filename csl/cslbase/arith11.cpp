// arith11.cpp                             Copyright (C) 1990-2017 Codemist

//
// Arithmetic functions.
//    remainder, =,
//    minusp, plusp
//
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



LispObject rembi(LispObject a, LispObject b)
{   if (b == fixnum_of_int(0)) aerror2("bad arg for remainder", a, b);
    else if (b == fixnum_of_int(1) ||
             b == fixnum_of_int(-1)) return fixnum_of_int(0);
    intptr_t n = int_of_fixnum(b);
    if (signed31_in_ptr(n))
    {   quotbn1(a, n);
        return fixnum_of_int(nwork);
    }
    quotbb(a, make_fake_bignum(n), QUOTBB_REMAINDER_NEEDED);
    return mv_2;
}

LispObject rembb(LispObject a, LispObject b)
{   quotbb(a, b, QUOTBB_REMAINDER_NEEDED);
    return mv_2;
}

static LispObject remis(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remir(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remif(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remsi(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remsb(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remsr(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remsf(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject rembs(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject rembr(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject rembf(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remri(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remrs(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remrb(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remrr(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remrf(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remfi(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remfs(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remfb(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remfr(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

static LispObject remff(LispObject a, LispObject b)
{   aerror2("bad arg for remainder", a, b);
}

LispObject Cremainder(LispObject a, LispObject b)
{   intptr_t c;
    switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum % fixnum arithmetic happens - the case I most want to
// make efficient.
//
                    if (b == fixnum_of_int(0))
                        aerror2("bad arg for remainder", a, b);
                    // No overflow is possible in a remaindering operation
                    {   intptr_t aa = int_of_fixnum(a);
                        intptr_t bb = int_of_fixnum(b);
                        c = aa % bb;
//
// C does not specify just what happens when % is used with negative
// operands (except maybe if the division went exactly), so here I do
// some adjusting, assuming that the quotient returned was one of the
// integral values surrounding the exact result.
//
                        if (aa < 0)
                        {   if (c > 0) c -= bb;
                        }
                        else if (c < 0) c += bb;
                        return fixnum_of_int(c);
                    }
//
// Common Lisp defines a meaning for the remainder function when applied
// to floating point values - so there is a whole pile of mess here to
// support that.  Standard Lisp is only concerned with fixnums and
// bignums, but can tolerate the extra generality.
//
                case XTAG_SFLOAT:
                    return remis(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
//
// When I divide a fixnum a by a bignum b the remainder is a except in
// the case that a = 0xf8000000 and b = 0x08000000 (for 28-bit fixnums)
// or a = -2^59 and b = 2^59 on a 64-bit system, in which case the answer
// is zero. This is all because the most negative fixnum has magnitude
// such that when you negated it you ended up with a bignum.
//
                            if (a == MOST_NEGATIVE_FIXNUM &&
                                ((SIXTY_FOUR_BIT &&
                                  bignum_length(b) == CELL+8 &&
                                  bignum_digits(b)[0] == 0 &&
                                  bignum_digits(b)[1] == (1<<(59-31))) ||
                                (!SIXTY_FOUR_BIT &&
                                  bignum_length(b) == CELL+4 &&
                                  bignum_digits(b)[0] == (1<<27))))
                                return fixnum_of_int(0);
                            else return a;
                        case TYPE_RATNUM:
                            return remir(a, b);
                        default:
                            aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return remif(a, b);
                default:
                    aerror1("Bad arg for remainder",  b);
            }
        case XTAG_SFLOAT:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return remsi(a, b);
                case XTAG_SFLOAT:
                {   LispObject q = pack_immediate_float(
                        value_of_immediate_float(a) /
                        value_of_immediate_float(b), a, b);
                    return pack_immediate_float(
                        value_of_immediate_float(a) -
                        (value_of_immediate_float(b) *
                         value_of_immediate_float(q)), a, b);
                }
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return remsb(a, b);
                        case TYPE_RATNUM:
                            return remsr(a, b);
                        default:
                            aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return remsf(a, b);
                default:
                    aerror1("Bad arg for remainder",  b);
            }
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return rembi(a, b);
                        case XTAG_SFLOAT:
                            return rembs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return rembb(a, b);
                                case TYPE_RATNUM:
                                    return rembr(a, b);
                                default:
                                    aerror1("Bad arg for remainder",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return rembf(a, b);
                        default:
                            aerror1("Bad arg for remainder",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return remri(a, b);
                        case XTAG_SFLOAT:
                            return remrs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return remrb(a, b);
                                case TYPE_RATNUM:
                                    return remrr(a, b);
                                default:
                                    aerror1("Bad arg for remainder",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return remrf(a, b);
                        default:
                            aerror1("Bad arg for remainder",  b);
                    }
                default:    aerror1("Bad arg for remainder",  a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch ((int)b & TAG_BITS)
            {
                case TAG_FIXNUM:
                    return remfi(a, b);
                case XTAG_SFLOAT:
                    return remfs(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return remfb(a, b);
                        case TYPE_RATNUM:
                            return remfr(a, b);
                        default:
                            aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return remff(a, b);
                default:
                    aerror1("Bad arg for remainder",  b);
            }
        default:
            aerror1("Bad arg for remainder",  a);
    }
}

//
// In the cases that I expect to be most speed-critical I will
// implement "mod" directly. But in a load of other cases I will just
// activate the existing "remainder" code and then make a few final
// adjustments.  This MAY lead to error messages (on modulus by zero)
// mentioning remainder rather than mod....
// I will leave in the whole structure of separate functions for each
// case since that will be useful if I ever need to come back here and
// fine-tune more of the type-combinations. As a first pass I give
// special treatment to (fixnum,fixnum) and (bignum,fixnum)
//

static LispObject mod_by_rem(LispObject a, LispObject b)
{   bool sb = minusp(b);
    a = Cremainder(a, b);   // Repeats dispatch on argument type. Sorry
    if (sb)
    {   if (plusp(a)) a = plus2(a, b);
    }
    else if (minusp(a)) a = plus2(a, b);
    return a;
}

static LispObject modib(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbi(LispObject a, LispObject b)
{   if (b == fixnum_of_int(0)) aerror2("bad arg for mod", a, b);
    if (b == fixnum_of_int(1) || b == fixnum_of_int(-1))
        return fixnum_of_int(0);
    intptr_t n = int_of_fixnum(b);
    if (signed31_in_ptr(n))
    {   quotbn1(a, n);
// The modulus must have the same sign as b (ie as n).
        if (n < 0)
        {   if (nwork > 0) nwork += n;
        }
        else if (nwork < 0) nwork += n;
        return fixnum_of_int(nwork);
    }
    quotbb(a, make_fake_bignum(n), QUOTBB_REMAINDER_NEEDED);
// here b had been a fixnum and the absolute value of the remainder in mv_2
// must be strictly smaller than |b|. And if I need to do and adjustment to
// turn remainder into modulus that will still leave a value that will be
// smaller that b was, and hence it must be a fixnum. That means I can do
// the adjustment arithmetic cheaply!
    if (n < 0)
    {   if (plusp(mv_2)) mv_2 = mv_2 + b - TAG_FIXNUM;
    }
    else if (minusp(mv_2)) mv_2 = mv_2 + b - TAG_FIXNUM;
    return mv_2;
}

static LispObject modbb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modis(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modir(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modif(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsi(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modri(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfi(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject ccl_modff(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

LispObject modulus(LispObject a, LispObject b)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum % fixnum arithmetic happens - the case I most want to
// make efficient.
//
                {   intptr_t p = int_of_fixnum(a);
                    intptr_t q = int_of_fixnum(b);
                    if (q == 0) aerror2("bad arg for mod", a, b);
                    p = p % q;
                    if (q < 0)
                    {   if (p > 0) p += q;
                    }
                    else if (p < 0) p += q;
                    // No overflow is possible in a modulus operation
                    return fixnum_of_int(p);
                }
//
// Common Lisp defines a meaning for the modulus function when applied
// to floating point values - so there is a whole pile of mess here to
// support that.  Standard Lisp is only concerned with fixnums and
// bignums.
//
                case XTAG_SFLOAT:
                    return modis(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modib(a, b);
                        case TYPE_RATNUM:
                            return modir(a, b);
                        default:
                            aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return modif(a, b);
                default:
                    aerror1("Bad arg for mod",  b);
            }
        case XTAG_SFLOAT:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return modsi(a, b);
                case XTAG_SFLOAT:
                {   LispObject q = pack_immediate_float(
                        value_of_immediate_float(a) /
                        value_of_immediate_float(b), a, b);
// What I have here is a remainder rather than a modulus. I ought to adjust
// this code in a spirit of directed rounding.
                    double r = value_of_immediate_float(a) -
                        value_of_immediate_float(b) *
                        value_of_immediate_float(q);
                    return pack_immediate_float(r, a, b);
                }
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modsb(a, b);
                        case TYPE_RATNUM:
                            return modsr(a, b);
                        default:
                            aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return modsf(a, b);
                default:
                    aerror1("Bad arg for mod",  b);
            }
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return modbi(a, b);
                        case XTAG_SFLOAT:
                            return modbs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return modbb(a, b);
                                case TYPE_RATNUM:
                                    return modbr(a, b);
                                default:
                                    aerror1("Bad arg for mod",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return modbf(a, b);
                        default:
                            aerror1("Bad arg for mod",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return modri(a, b);
                        case XTAG_SFLOAT:
                            return modrs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return modrb(a, b);
                                case TYPE_RATNUM:
                                    return modrr(a, b);
                                default:
                                    aerror1("Bad arg for mod",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return modrf(a, b);
                        default:
                            aerror1("Bad arg for mod",  b);
                    }
                default:    aerror1("Bad arg for mod",  a);
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return modfi(a, b);
                case XTAG_SFLOAT:
                    return modfs(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modfb(a, b);
                        case TYPE_RATNUM:
                            return modfr(a, b);
                        default:
                            aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return ccl_modff(a, b);
                default:
                    aerror1("Bad arg for mod",  b);
            }
        default:
            aerror1("Bad arg for mod",  a);
    }
}

bool zerop(LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return (a == fixnum_of_int(0));
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            // #C(r i) must satisfy zerop is r and i both do
            if (is_complex(a) && zerop(real_part(a)))
                return zerop(imag_part(a));
            else return false;
        case XTAG_SFLOAT:
            return value_of_immediate_float(a) == 0.0;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            return float_of_number(a) == 0.0;
        default:
            return false;
    }
}

bool onep(LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return (a == fixnum_of_int(1));
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
            // #C(r i) must satisfy onep(r) and zerop(i)
            if (is_complex(a) && onep(real_part(a)))
                return zerop(imag_part(a));
            else return false;
        case XTAG_SFLOAT:
            return value_of_immediate_float(a) == 1.0;
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            return (float_of_number(a) == 1.0);
        default:
            return false;
    }
}

//
// sign testing
//

bool minusp(LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return (intptr_t)a < 0;
        case XTAG_SFLOAT:
            return value_of_immediate_float(a) < 0.0;
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                {   size_t l = (bignum_length(a)-CELL-4)/4;
                    return ((int32_t)bignum_digits(a)[l] < 0);
                }
                case TYPE_RATNUM:
                    return minusp(numerator(a));
                default:
                    aerror1("Bad arg for minusp",  a);
                    return 0;
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            return float_of_number(a) < 0.0;
        default:
            aerror1("Bad arg for minusp",  a);
            return 0;
    }
}


bool plusp(LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            return (intptr_t)a > fixnum_of_int(0);
        case XTAG_SFLOAT:
            return value_of_immediate_float(a) > 0.0;
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                {   size_t l = (bignum_length(a)-CELL-4)/4;
// This is OK because a bignum can never have the value zero
                    return ((int32_t)bignum_digits(a)[l] >= 0);
                }
                case TYPE_RATNUM:
                    return plusp(numerator(a));
                default:
                    aerror1("Bad arg for plusp",  a);
                    return 0;
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            return float_of_number(a) > 0.0;
        default:
            aerror1("Bad arg for plusp",  a);
            return 0;
    }
}


//
// Numeric equality - note that comparisons involving non-numbers
// are errors here (unlike the position in eql, equal, equalp).  Also
// this must be coded so that it never provokes garbage collection.
//

static bool numeqis(LispObject a, LispObject b)
{   return eq_i64d(int_of_fixnum(a), value_of_immediate_float(b));
}

static bool numeqic(LispObject a, LispObject b)
{   if (!zerop(imag_part(b))) return false;
    else return numeq2(a, real_part(b));
}

#define numeqif(a,b) eq_i64d(int_of_fixnum(a), float_of_number(b))

#define numeqsi(a, b) numeqis(b, a)

static bool numeqsb(LispObject a, LispObject b)
//
// This is coded to allow comparison of any floating type
// with a bignum. Well when I say "any floating type" I think that the
// 128 bit one will need further work!
//
{   double d = float_of_number(a), d1;
    int x;
    int32_t w;
    size_t len;
    uint32_t u;
    if (-1.0e8 < d && d < 1.0e8) return false; // fixnum range (approx)
    len = (bignum_length(b)-CELL-4)/4;
    if (len == 0)   // One word bignums can be treated specially
    {   int32_t v = bignum_digits(b)[0];
        return (d == (double)v);
    }
    d1 = frexp(d, &x);  // separate exponent from mantissa
    if (d1 == 1.0) d1 = 0.5, x++;  // For Zortech
// The exponent x must be positive here, hence the % operation is defined
    d1 = ldexp(d1, x % 31);
//
// At most 3 words in the bignum may contain nonzero data - I subtract
// the (double) value of those bits off and check that (a) the floating
// result left is zero and (b) there are no more bits left.
//
    x = x / 31;
    if (x < 0 || (size_t)x != len) return false;
    w = bignum_digits(b)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(b)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(b)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return false;
    while (--len >= 0)
        if (bignum_digits(b)[len] != 0) return false;
    return true;
}

static bool numeqsr(LispObject a, LispObject b)
//
// Here I will rely somewhat on the use of IEEE floating point values
// (an in particular the weaker supposition that I have floating point
// with a binary radix).  Then for equality the denominator of b must
// be a power of 2, which I can test for and then account for.
//
{   LispObject nb = numerator(b), db = denominator(b);
    double d = float_of_number(a), d1;
    int x;
    int32_t dx, w, len;
    uint32_t u, bit;
//
// first I will check that db (which will be positive) is a power of 2,
// and set dx to indicate what power of two it is.
// Note that db != 0 and that one of the top two words of a bignum
// must be nonzero (for normalisation) so I end up with a nonzero
// value in the variable 'bit'
//
    if (is_fixnum(db))
    {   bit = int_of_fixnum(db);
        w = bit;
        if (w != (w & (-w))) return false;   // not a power of 2
        dx = 0;
    }
    else if (is_numbers(db) && is_bignum(db))
    {   int32_t lenb = (bignum_length(db)-CELL-4)/4;
        bit = bignum_digits(db)[lenb];
//
// I need to cope with bignums where the leading digits is zero because
// the 0x80000000 bit of the next word down is 1.  To do this I treat
// the number as having one fewer digits.
//
        if (bit == 0) bit = bignum_digits(db)[--lenb];
        w = bit;
        if (w != (w & (-w))) return false;   // not a power of 2
        dx = 31*lenb;
        while (--lenb >= 0)     // check that the rest of db is zero
            if (bignum_digits(db)[lenb] != 0) return false;
    }
    else return false; // Odd - what type IS db here?  Maybe error.
    if ((bit & 0xffffU) == 0) dx += 16, bit = bit >> 16;
    if ((bit & 0xff) == 0) dx += 8, bit = bit >> 8;
    if ((bit & 0xf) == 0) dx += 4, bit = bit >> 4;
    if ((bit & 0x3) == 0) dx += 2, bit = bit >> 2;
    if ((bit & 0x1) == 0) dx += 1;
    if (is_fixnum(nb))
    {   double d1 = (double)int_of_fixnum(nb);
//
// The ldexp on the next line could potentially underflow.  In that case C
// defines that the result 0.0 be returned.  To avoid trouble I put in a
// special test the relies on that fact that a value represented as a rational
// would not have been zero.
//
        if (dx > 10000) return false;  // Avoid gross underflow
        d1 = ldexp(d1, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    len = (bignum_length(nb)-CELL-4)/4;
    if (len == 0)   // One word bignums can be treated specially
    {   int32_t v = bignum_digits(nb)[0];
        double d1;
        if (dx > 10000) return false;  // Avoid gross underflow
        d1 = ldexp((double)v, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    d1 = frexp(d, &x);    // separate exponent from mantissa
    if (d1 == 1.0) d1 = 0.5, x++; // For Zortech
    dx += x;              // adjust to allow for the denominator
    d1 = ldexp(d1, (int)(dx % 31));
    // can neither underflow nor overflow here
//
// At most 3 words in the bignum may contain nonzero data - I subtract
// the (double) value of those bits off and check that (a) the floating
// result left is zero and (b) there are no more bits left.
//
    dx = dx / 31;
    if (dx != len) return false;
    w = bignum_digits(nb)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(nb)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(nb)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return false;
    while (--len >= 0)
        if (bignum_digits(nb)[len] != 0) return false;
    return true;
}

#define numeqsc(a, b) numeqic(a, b)

static bool numeqsf(LispObject a, LispObject b)
{
    return value_of_immediate_float(a) == float_of_number(b);
}

#define numeqbs(a, b) numeqsb(b, a)

static bool numeqbb(LispObject a, LispObject b)
{   int32_t la = bignum_length(a);
    if (la != (int32_t)bignum_length(b)) return false;
    la = (la-CELL-4)/4;
    while (la >= 0)
    {   if (bignum_digits(a)[la] != bignum_digits(b)[la]) return false;
        else la--;
    }
    return true;
}

#define numeqbc(a, b) numeqic(a, b)

#define numeqbf(a, b) numeqsb(b, a)

#define numeqrs(a, b) numeqsr(b, a)

static bool numeqrr(LispObject a, LispObject b)
{   return numeq2(numerator(a), numerator(b)) &&
           numeq2(denominator(a), denominator(b));
}

#define numeqrc(a, b) numeqic(a, b)

#define numeqrf(a, b) numeqsr(b, a)

#define numeqci(a, b) numeqic(b, a)

#define numeqcs(a, b) numeqic(b, a)

#define numeqcb(a, b) numeqic(b, a)

#define numeqcr(a, b) numeqic(b, a)

static bool numeqcc(LispObject a, LispObject b)
{   return numeq2(real_part(a), real_part(b)) &&
           numeq2(imag_part(a), imag_part(b));
}

#define numeqcf(a, b) numeqic(b, a)

#define numeqfi(a, b) numeqif(b, a)

#define numeqfs(a, b) numeqsf(b, a)

#define numeqfb(a, b) numeqbf(b, a)

#define numeqfr(a, b) numeqrf(b, a)

#define numeqfc(a, b) numeqic(a, b)

static bool numeqff(LispObject a, LispObject b)
{   return (float_of_number(a) == float_of_number(b));
}

//
// This comparison must signal an error on non-numeric operands in
// Common Lisp mode, but behave as EQ in CSL mode.
//

#ifdef COMMON
#  define differenta aerror1("Bad arg for =",  a); return false
#  define differentb aerror1("Bad arg for =",  b); return false
#else
#  define differenta return false
#  define differentb return false
#endif

bool numeq2(LispObject a, LispObject b)
{   switch ((int)a & XTAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return (a == b);
                case XTAG_SFLOAT:
                    return numeqis(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return 0; // fixnum can not be equal to a bignum
                        case TYPE_RATNUM:
                            return 0;
                        case TYPE_COMPLEX_NUM:
                            return numeqic(a, b);   // (= 2 #C(2.0 0.0))?  Yuk
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return numeqif(a, b);
                default:
                    differentb;
            }
        case XTAG_SFLOAT:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return numeqsi(a, b);
                case XTAG_SFLOAT:
                    return value_of_immediate_float(a) ==
                           value_of_immediate_float(b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return numeqsb(a, b);
                        case TYPE_RATNUM:
                            return numeqsr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return numeqsc(a, b);
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return numeqsf(a, b);
                default:
                    differentb;
            }
        case TAG_NUMBERS:
        case TAG_NUMBERS+TAG_XBIT:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return 0;
                        case XTAG_SFLOAT:
                            return numeqbs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return numeqbb(a, b);
                                case TYPE_RATNUM:
                                    return 0;
                                case TYPE_COMPLEX_NUM:
                                    return numeqbc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return numeqbf(a, b);
                        default:
                            differentb;
                    }
                case TYPE_RATNUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return 0;
                        case XTAG_SFLOAT:
                            return numeqrs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return 0;
                                case TYPE_RATNUM:
                                    return numeqrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return numeqrc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return numeqrf(a, b);
                        default:
                            differentb;
                    }
                case TYPE_COMPLEX_NUM:
                    switch ((int)b & XTAG_BITS)
                    {   case TAG_FIXNUM:
                            return numeqci(a, b);
                        case XTAG_SFLOAT:
                            return numeqcs(a, b);
                        case TAG_NUMBERS:
                        case TAG_NUMBERS+TAG_XBIT:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return numeqcb(a, b);
                                case TYPE_RATNUM:
                                    return numeqcr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return numeqcc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                        case TAG_BOXFLOAT+TAG_XBIT:
                            return numeqcf(a, b);
                        default:
                            differentb;
                    }
                default:    differenta;
            }
        }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch ((int)b & XTAG_BITS)
            {   case TAG_FIXNUM:
                    return numeqfi(a, b);
                case XTAG_SFLOAT:
                    return numeqfs(a, b);
                case TAG_NUMBERS:
                case TAG_NUMBERS+TAG_XBIT:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return numeqfb(a, b);
                        case TYPE_RATNUM:
                            return numeqfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return numeqfc(a, b);
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                case TAG_BOXFLOAT+TAG_XBIT:
                    return numeqff(a, b);
                default:
                    differentb;
            }
        default:
            differenta;
    }
}

// end of arith11.cpp
