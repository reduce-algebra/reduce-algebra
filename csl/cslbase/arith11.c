/*  arith11.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.
 *    remainder, =,
 *    minusp, plusp
 *
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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




/* Signature: 7dd82714 24-May-2008 */


#include "headers.h"



Lisp_Object rembi(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil;
    if (b == fixnum_of_int(0)) return aerror2("bad arg for remainder", a, b);
    else if (b == fixnum_of_int(1) ||
             b == fixnum_of_int(-1)) return fixnum_of_int(0);
    quotbn1(a, int_of_fixnum(b));
/*
 * If the divisor was a fixnum then the remainder will be a fixnum too.
 */
    errexit();
    return fixnum_of_int(nwork);
}

Lisp_Object rembb(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil;
    quotbb(a, b);
    errexit();
    return mv_2;
}

#ifdef COMMON

static Lisp_Object remis(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remir(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remif(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remsi(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remsb(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remsr(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remsf(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object rembs(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object rembr(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object rembf(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remri(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remrs(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remrb(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remrr(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remrf(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remfi(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remfs(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remfb(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remfr(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

static Lisp_Object remff(Lisp_Object a, Lisp_Object b)
{
    return aerror2("bad arg for remainder", a, b);
}

#endif /* COMMON */

Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b)
{
    int32_t c;
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/*
 * This is where fixnum % fixnum arithmetic happens - the case I most want to
 * make efficient.
 */
            if (b == fixnum_of_int(0))
                return aerror2("bad arg for remainder", a, b);
            /* No overflow is possible in a remaindering operation */
            {   int32_t aa = int_of_fixnum(a);
                int32_t bb = int_of_fixnum(b);
                c = aa % bb;
/*
 * C does not specify just what happens when % is used with negative
 * operands (except maybe if the division went exactly), so here I do
 * some adjusting, assuming that the quotient returned was one of the
 * integral values surrounding the exact result.
 */
                if (aa < 0)
                {   if (c > 0) c -= bb;
                }
                else if (c < 0) c += bb;
                return fixnum_of_int(c);
            }
#ifdef COMMON
/*
 * Common Lisp defines a meaning for the remainder function when applied
 * to floating point values - so there is a whole pile of mess here to
 * support that.  Standard Lisp is only concerned with fixnums and
 * bignums.
 */
    case TAG_SFLOAT:
            return remis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
/*
 * When I divide a fixnum a by a bignum b the remainder is a except in
 * the case that a = 0xf8000000 and b = 0x08000000 in which case the
 * answer is zero.
 */
                if (int_of_fixnum(a) == fix_mask &&
                    bignum_length(b) == 8 &&
                    bignum_digits(b)[0] == 0x08000000)
                        return fixnum_of_int(0);
                else return a;
#ifdef COMMON
        case TYPE_RATNUM:
                return remir(a, b);
#endif
        default:
                return aerror1("Bad arg for remainder",  b);
                }
            }
#ifdef COMMON
    case TAG_BOXFLOAT:
            return remif(a, b);
#else
    case TAG_BOXFLOAT:
        {   double v = (double) int_of_fixnum(a);
            double u = float_of_number(b);
            v = v - (v/u)*u;
            return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
        }
#endif
    default:
            return aerror1("Bad arg for remainder",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return remsi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float) (aa.f + bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return remsb(a, b);
        case TYPE_RATNUM:
                return remsr(a, b);
        default:
                return aerror1("Bad arg for remainder",  b);
                }
            }
    case TAG_BOXFLOAT:
            return remsf(a, b);
    default:
            return aerror1("Bad arg for remainder",  b);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return rembi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return rembs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return rembb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return rembr(a, b);
#endif
                default:
                        return aerror1("Bad arg for remainder",  b);
                        }
                    }
#ifdef COMMON
            case TAG_BOXFLOAT:
                    return rembf(a, b);
#endif
            default:
                    return aerror1("Bad arg for remainder",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return remri(a, b);
            case TAG_SFLOAT:
                    return remrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return remrb(a, b);
                case TYPE_RATNUM:
                        return remrr(a, b);
                default:
                        return aerror1("Bad arg for remainder",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return remrf(a, b);
            default:
                    return aerror1("Bad arg for remainder",  b);
                }
#endif
    default:    return aerror1("Bad arg for remainder",  a);
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
#ifndef COMMON
    case TAG_FIXNUM:
            {   double u = (double) int_of_fixnum(b);
                double v = float_of_number(a);
                v = v - (v/u)*u;
                return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
            }
    case TAG_BOXFLOAT:
            {   double u = float_of_number(b);
                double v = float_of_number(a);
                v = v - (v/u)*u;
                return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
            }
    default:
            return aerror1("Bad arg for remainder",  b);
#else
    case TAG_FIXNUM:
            return remfi(a, b);
    case TAG_SFLOAT:
            return remfs(a, b);
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return remfb(a, b);
        case TYPE_RATNUM:
                return remfr(a, b);
        default:
                return aerror1("Bad arg for remainder",  b);
                }
            }
    case TAG_BOXFLOAT:
            return remff(a, b);
    default:
            return aerror1("Bad arg for remainder",  b);
#endif
        }
default:
        return aerror1("Bad arg for remainder",  a);
    }
}

/*
 * In the cases that I expect to be most speed-critical I will
 * implement "mod" directly. But in a load of other cases I will just
 * activate the existing "remainder" code and then make a few final
 * adjustments.  This MAY lead to error messages (on modulus by zero)
 * mentioning remainder rather than mod....
 * I will leave in the whole structure of separate functions for each
 * case since that will be useful if I ever need to come back here and
 * fine-tune more of the type-combinations. As a first pass I give
 * special treatment to (fixnum,fixnum) and (bignum,fixnum)
 */

static Lisp_Object mod_by_rem(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil;
    CSLbool sb = minusp(b);
    errexit();
    a = Cremainder(a, b);   /* Repeats dispatch on argument type. Sorry */
    errexit();
    if (sb)
    {   if (plusp(a))
        {   errexit();
            a = plus2(a, b);
        }
    }
    else if (minusp(a))
    {   errexit();
        a = plus2(a, b);
    }
    return a;
}

static Lisp_Object modib(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modbi(Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    int32_t bb = int_of_fixnum(b);
    if (b == fixnum_of_int(0)) return aerror2("bad arg for mod", a, b);
    if (bb == 1 || bb == -1) nwork = 0;
    else quotbn1(a, bb);
/*
 * If the divisor was a fixnum then the remainder will be a fixnum too.
 */
    errexit();
    if (bb < 0)
    {   if (nwork > 0) nwork += bb;
    }
    else if (nwork < 0) nwork += bb;
    return fixnum_of_int(nwork);
}

static Lisp_Object modbb(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

#ifdef COMMON

static Lisp_Object modis(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modir(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modif(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modsi(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modsb(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modsr(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modsf(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modbs(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modbr(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modbf(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modri(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modrs(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modrb(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modrr(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modrf(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modfi(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modfs(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modfb(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object modfr(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

static Lisp_Object ccl_modff(Lisp_Object a, Lisp_Object b)
{
    return mod_by_rem(a, b);
}

#endif /* COMMON */

Lisp_Object modulus(Lisp_Object a, Lisp_Object b)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
/*
 * This is where fixnum % fixnum arithmetic happens - the case I most want to
 * make efficient.
 */
            {   int32_t p = int_of_fixnum(a);
                int32_t q = int_of_fixnum(b);
                if (q == 0) return aerror2("bad arg for mod", a, b);
                p = p % q;
                if (q < 0)
                {   if (p > 0) p += q;
                }
                else if (p < 0) p += q;
                /* No overflow is possible in a modulus operation */
                return fixnum_of_int(p);
            }
#ifdef COMMON
/*
 * Common Lisp defines a meaning for the modulus function when applied
 * to floating point values - so there is a whole pile of mess here to
 * support that.  Standard Lisp is only concerned with fixnums and
 * bignums.
 */
    case TAG_SFLOAT:
            return modis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return modib(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return modir(a, b);
#endif
        default:
                return aerror1("Bad arg for mod",  b);
                }
            }
#ifdef COMMON
    case TAG_BOXFLOAT:
            return modif(a, b);
#endif
    default:
            return aerror1("Bad arg for mod",  b);
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return modsi(a, b);
    case TAG_SFLOAT:
            {   Float_union aa, bb;
                aa.i = a - TAG_SFLOAT;
                bb.i = b - TAG_SFLOAT;
                aa.f = (float) (aa.f + bb.f);
                return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
            }
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return modsb(a, b);
        case TYPE_RATNUM:
                return modsr(a, b);
        default:
                return aerror1("Bad arg for mod",  b);
                }
            }
    case TAG_BOXFLOAT:
            return modsf(a, b);
    default:
            return aerror1("Bad arg for mod",  b);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return modbi(a, b);
#ifdef COMMON
            case TAG_SFLOAT:
                    return modbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return modbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return modbr(a, b);
#endif
                default:
                        return aerror1("Bad arg for mod",  b);
                        }
                    }
#ifdef COMMON
            case TAG_BOXFLOAT:
                    return modbf(a, b);
#endif
            default:
                    return aerror1("Bad arg for mod",  b);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return modri(a, b);
            case TAG_SFLOAT:
                    return modrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return modrb(a, b);
                case TYPE_RATNUM:
                        return modrr(a, b);
                default:
                        return aerror1("Bad arg for mod",  b);
                        }
                    }
            case TAG_BOXFLOAT:
                    return modrf(a, b);
            default:
                    return aerror1("Bad arg for mod",  b);
                }
#endif
    default:    return aerror1("Bad arg for mod",  a);
            }
        }
#ifdef COMMON
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return modfi(a, b);
    case TAG_SFLOAT:
            return modfs(a, b);
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return modfb(a, b);
        case TYPE_RATNUM:
                return modfr(a, b);
        default:
                return aerror1("Bad arg for mod",  b);
                }
            }
    case TAG_BOXFLOAT:
            return ccl_modff(a, b);
    default:
            return aerror1("Bad arg for mod",  b);
        }
#endif
default:
        return aerror1("Bad arg for mod",  a);
    }
}

CSLbool zerop(Lisp_Object a)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return (a == fixnum_of_int(0));
#ifdef COMMON
case TAG_NUMBERS:
        /* #C(r i) must satisfy zerop is r and i both do */
        if (is_complex(a) && zerop(real_part(a)))
            return zerop(imag_part(a));
        else return NO;
case TAG_SFLOAT:
/*
 * The code here assumes that the the floating point number zero
 * is represented by a zero bit-pattern... see onep() for a more
 * cautious way of coding things.
 */
        return ((a & 0x7ffffff8) == 0); /* Strip sign bit as well as tags */
#endif
case TAG_BOXFLOAT:
        return (float_of_number(a) == 0.0);
default:
        return NO;
    }
}

CSLbool onep(Lisp_Object a)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return (a == fixnum_of_int(1));
#ifdef COMMON
case TAG_NUMBERS:
        /* #C(r i) must satisfy onep(r) and zerop(i) */
        if (is_complex(a) && onep(real_part(a)))
            return zerop(imag_part(a));
        else return NO;
case TAG_SFLOAT:
        {   Float_union w;
            w.f = (float)1.0;
            return (a == (w.i & ~(int32_t)0xf) + TAG_SFLOAT);
        }
#endif
case TAG_BOXFLOAT:
        return (float_of_number(a) == 1.0);
default:
        return NO;
    }
}

/*
 * sign testing
 */

CSLbool minusp(Lisp_Object a)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return ((int32_t)a < 0);
#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return (aa.f < 0.0);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                {   int32_t l = (bignum_length(a)-CELL-4)/4;
                    return ((int32_t)bignum_digits(a)[l] < (int32_t)0);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                return minusp(numerator(a));
#endif
    default:
                aerror1("Bad arg for minusp",  a);
                return 0;
            }
        }
case TAG_BOXFLOAT:
        {   double d = float_of_number(a);
            return (d < 0.0);
        }
default:
        aerror1("Bad arg for minusp",  a);
        return 0;
    }
}


CSLbool plusp(Lisp_Object a)
{
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        return (a > fixnum_of_int(0));
#ifdef COMMON
case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return (aa.f > 0.0);
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                {   int32_t l = (bignum_length(a)-CELL-4)/4;
/* This is OK because a bignum can never have the value zero */
                    return ((int32_t)bignum_digits(a)[l] >= (int32_t)0);
                }
#ifdef COMMON
    case TYPE_RATNUM:
                return plusp(numerator(a));
#endif
    default:
                aerror1("Bad arg for plusp",  a);
                return 0;
            }
        }
case TAG_BOXFLOAT:
        {   double d = float_of_number(a);
            return (d > 0.0);
        }
default:
        aerror1("Bad arg for plusp",  a);
        return 0;
    }
}


/*
 * Numeric equality - note that comparisons involving non-numbers
 * are errors here (unlike the position in eql, equal, equalp).  Also
 * this must be coded so that it never provokes garbage collection.
 */

#ifdef COMMON
static CSLbool numeqis(Lisp_Object a, Lisp_Object b)
{
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    return ((double)int_of_fixnum(a) == (double)bb.f);
}

static CSLbool numeqic(Lisp_Object a, Lisp_Object b)
{
    if (!zerop(imag_part(b))) return NO;
    else return numeq2(a, real_part(b));
}
#endif

#define numeqif(a,b) ((double)int_of_fixnum(a) == float_of_number(b))

#ifdef COMMON
#define numeqsi(a, b) numeqis(b, a)
#endif

static CSLbool numeqsb(Lisp_Object a, Lisp_Object b)
/*
 * This is coded to allow comparison of any floating type
 * with a bignum
 */
{
    double d = float_of_number(a), d1;
    int x;
    int32_t w, len;
    uint32_t u;
    if (-1.0e8 < d && d < 1.0e8) return NO; /* fixnum range (approx) */
    len = (bignum_length(b)-CELL-4)/4;
    if (len == 0)   /* One word bignums can be treated specially */
    {   int32_t v = bignum_digits(b)[0];
        return (d == (double)v);
    }
    d1 = frexp(d, &x);  /* separate exponent from mantissa */
    if (d1 == 1.0) d1 = 0.5, x++;  /* For Zortech */
/* The exponent x must be positive here, hence the % operation is defined */
    d1 = ldexp(d1, x % 31);
/*
 * At most 3 words in the bignum may contain nonzero data - I subtract
 * the (double) value of those bits off and check that (a) the floating
 * result left is zero and (b) there are no more bits left.
 */
    x = x / 31;
    if (x != len) return NO;
    w = bignum_digits(b)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(b)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(b)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return NO;
    while (--len >= 0)
        if (bignum_digits(b)[len] != 0) return NO;
    return YES;
}

#ifdef COMMON
static CSLbool numeqsr(Lisp_Object a, Lisp_Object b)
/*
 * Here I will rely somewhat on the use of IEEE floating point values
 * (an in particular the weaker supposition that I have floating point
 * with a binary radix).  Then for equality the denominator of b must
 * be a power of 2, which I can test for and then account for.
 */
{
    Lisp_Object nb = numerator(b), db = denominator(b);
    double d = float_of_number(a), d1;
    int x;
    int32_t dx, w, len;
    uint32_t u, bit;
/*
 * first I will check that db (which will be positive) is a power of 2,
 * and set dx to indicate what power of two it is.
 * Note that db != 0 and that one of the top two words of a bignum
 * must be nonzero (for normalisation) so I end up with a nonzero
 * value in the variable 'bit'
 */
    if (is_fixnum(db))
    {   bit = int_of_fixnum(db);
        w = bit;
        if (w != (w & (-w))) return NO;   /* not a power of 2 */
        dx = 0;
    }
    else if (is_numbers(db) && is_bignum(db))
    {   int32_t lenb = (bignum_length(db)-CELL-4)/4;
        bit = bignum_digits(db)[lenb];
/*
 * I need to cope with bignums where the leading digits is zero because
 * the 0x80000000 bit of the next word down is 1.  To do this I treat
 * the number as having one fewer digits.
 */
        if (bit == 0) bit = bignum_digits(db)[--lenb];
        w = bit;
        if (w != (w & (-w))) return NO;   /* not a power of 2 */
        dx = 31*lenb;
        while (--lenb >= 0)     /* check that the rest of db is zero */
            if (bignum_digits(db)[lenb] != 0) return NO;
    }
    else return NO; /* Odd - what type IS db here?  Maybe error. */
    if ((bit & 0xffffU) == 0) dx += 16, bit = bit >> 16;
    if ((bit & 0xff) == 0) dx += 8, bit = bit >> 8;
    if ((bit & 0xf) == 0) dx += 4, bit = bit >> 4;
    if ((bit & 0x3) == 0) dx += 2, bit = bit >> 2;
    if ((bit & 0x1) == 0) dx += 1;
    if (is_fixnum(nb))
    {   double d1 = (double)int_of_fixnum(nb);
/*
 * The ldexp on the next line could potentially underflow.  In that case C
 * defines that the result 0.0 be returned.  To avoid trouble I put in a
 * special test the relies on that fact that a value represented as a rational
 * would not have been zero.
 */
        if (dx > 10000) return NO;  /* Avoid gross underflow */
        d1 = ldexp(d1, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    len = (bignum_length(nb)-CELL-4)/4;
    if (len == 0)   /* One word bignums can be treated specially */
    {   int32_t v = bignum_digits(nb)[0];
        double d1;
        if (dx > 10000) return NO;  /* Avoid gross underflow */
        d1 = ldexp((double)v, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    d1 = frexp(d, &x);    /* separate exponent from mantissa */
    if (d1 == 1.0) d1 = 0.5, x++; /* For Zortech */
    dx += x;              /* adjust to allow for the denominator */
    d1 = ldexp(d1, (int)(dx % 31));
                          /* can neither underflow nor overflow here */
/*
 * At most 3 words in the bignum may contain nonzero data - I subtract
 * the (double) value of those bits off and check that (a) the floating
 * result left is zero and (b) there are no more bits left.
 */
    dx = dx / 31;
    if (dx != len) return NO;
    w = bignum_digits(nb)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(nb)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(nb)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return NO;
    while (--len >= 0)
        if (bignum_digits(nb)[len] != 0) return NO;
    return YES;
}

#define numeqsc(a, b) numeqic(a, b)

static CSLbool numeqsf(Lisp_Object a, Lisp_Object b)
{
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return ((double)aa.f == float_of_number(b));
}

#define numeqbs(a, b) numeqsb(b, a)
#endif

static CSLbool numeqbb(Lisp_Object a, Lisp_Object b)
{
    int32_t la = bignum_length(a);
    if (la != (int32_t)bignum_length(b)) return NO;
    la = (la-CELL-4)/4;
    while (la >= 0)
    {   if (bignum_digits(a)[la] != bignum_digits(b)[la]) return NO;
        else la--;
    }
    return YES;
}

#ifdef COMMON
#define numeqbc(a, b) numeqic(a, b)
#endif

#define numeqbf(a, b) numeqsb(b, a)

#ifdef COMMON
#define numeqrs(a, b) numeqsr(b, a)

static CSLbool numeqrr(Lisp_Object a, Lisp_Object b)
{
    return numeq2(numerator(a), numerator(b)) &&
           numeq2(denominator(a), denominator(b));
}

#define numeqrc(a, b) numeqic(a, b)

#define numeqrf(a, b) numeqsr(b, a)

#define numeqci(a, b) numeqic(b, a)

#define numeqcs(a, b) numeqic(b, a)

#define numeqcb(a, b) numeqic(b, a)

#define numeqcr(a, b) numeqic(b, a)

static CSLbool numeqcc(Lisp_Object a, Lisp_Object b)
{
    return numeq2(real_part(a), real_part(b)) &&
           numeq2(imag_part(a), imag_part(b));
}

#define numeqcf(a, b) numeqic(b, a)
#endif

#define numeqfi(a, b) numeqif(b, a)

#ifdef COMMON
#define numeqfs(a, b) numeqsf(b, a)
#endif

#define numeqfb(a, b) numeqbf(b, a)

#ifdef COMMON
#define numeqfr(a, b) numeqrf(b, a)

#define numeqfc(a, b) numeqic(a, b)
#endif

static CSLbool numeqff(Lisp_Object a, Lisp_Object b)
{
    return (float_of_number(a) == float_of_number(b));
}

/*
 * This comparison must signal an error on non-numeric operands in
 * Common Lisp mode, but behave as EQ in CSL mode.
 */

#ifdef COMMON
#  define differenta aerror1("Bad arg for =",  a); return 0
#  define differentb aerror1("Bad arg for =",  b); return 0
#else
#  define differenta return NO
#  define differentb return NO
#endif

CSLbool numeq2(Lisp_Object a, Lisp_Object b)
{
#ifndef COMMON
    if (a == b) return YES;
#endif
    switch ((int)a & TAG_BITS)
    {
case TAG_FIXNUM:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
#ifdef COMMON
            return (a == b);
#else
            return NO;
#endif
#ifdef COMMON
    case TAG_SFLOAT:
            return numeqis(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return 0;
#ifdef COMMON
        case TYPE_RATNUM:
                return 0;
        case TYPE_COMPLEX_NUM:
                return numeqic(a, b);   /* (= 2 #C(2.0 0.0))?  Yuk */
#endif
        default:
                differentb;
                }
            }
    case TAG_BOXFLOAT:
            return numeqif(a, b);
    default:
            differentb;
        }
#ifdef COMMON
case TAG_SFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return numeqsi(a, b);
    case TAG_SFLOAT:
            return (a == b) ||
            (a == TAG_SFLOAT && b == TAG_SFLOAT|0x80000000) ||
            (a == TAG_SFLOAT|0x80000000 && b == TAG_SFLOAT); /* !!! */
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
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
            return numeqsf(a, b);
    default:
            differentb;
        }
#endif
case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {
    case TYPE_BIGNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return 0;
#ifdef COMMON
            case TAG_SFLOAT:
                    return numeqbs(a, b);
#endif
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
                        return numeqbb(a, b);
#ifdef COMMON
                case TYPE_RATNUM:
                        return 0;
                case TYPE_COMPLEX_NUM:
                        return numeqbc(a, b);
#endif
                default:
                        differentb;
                        }
                    }
            case TAG_BOXFLOAT:
                    return numeqbf(a, b);
            default:
                    differentb;
                }
#ifdef COMMON
    case TYPE_RATNUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return 0;
            case TAG_SFLOAT:
                    return numeqrs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
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
                    return numeqrf(a, b);
            default:
                    differentb;
                }
    case TYPE_COMPLEX_NUM:
                switch ((int)b & TAG_BITS)
                {
            case TAG_FIXNUM:
                    return numeqci(a, b);
            case TAG_SFLOAT:
                    return numeqcs(a, b);
            case TAG_NUMBERS:
                    {   int32_t hb = type_of_header(numhdr(b));
                        switch (hb)
                        {
                case TYPE_BIGNUM:
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
                    return numeqcf(a, b);
            default:
                    differentb;
                }
#endif
    default:    differenta;
            }
        }
case TAG_BOXFLOAT:
        switch ((int)b & TAG_BITS)
        {
    case TAG_FIXNUM:
            return numeqfi(a, b);
#ifdef COMMON
    case TAG_SFLOAT:
            return numeqfs(a, b);
#endif
    case TAG_NUMBERS:
            {   int32_t hb = type_of_header(numhdr(b));
                switch (hb)
                {
        case TYPE_BIGNUM:
                return numeqfb(a, b);
#ifdef COMMON
        case TYPE_RATNUM:
                return numeqfr(a, b);
        case TYPE_COMPLEX_NUM:
                return numeqfc(a, b);
#endif
        default:
                differentb;
                }
            }
    case TAG_BOXFLOAT:
            return numeqff(a, b);
    default:
            differentb;
        }
default:
        differenta;
    }
}

/* end of arith11.c */
