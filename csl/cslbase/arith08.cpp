//  arith08.cpp                            Copyright (C) 1990-2017 Codemist

//
// Arithmetic functions.
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


static LispObject Lboole(LispObject env, int nargs, ...)
{   LispObject r, op, a, b;
    va_list aa;
    argcheck(nargs, 3, "boole");
    va_start(aa, nargs);
    op = va_arg(aa, LispObject);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    va_end(aa);
    switch (op)
    {   case fixnum_of_int(boole_clr):
            return onevalue(fixnum_of_int(0));
        case fixnum_of_int(boole_and):
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_andc2):
            push(a);
            b = lognot(b);
            pop(a);
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_1):
            return onevalue(a);
        case fixnum_of_int(boole_andc1):
            push(b);
            a = lognot(a);
            pop(b);
            r = logand2(a, b);
            break;
        case fixnum_of_int(boole_2):
            return onevalue(b);
        case fixnum_of_int(boole_xor):
            r = logxor2(a, b);
            break;
        case fixnum_of_int(boole_ior):
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_nor):
            a = logior2(a, b);
            r = lognot(a);
            break;
        case fixnum_of_int(boole_eqv):
            r = logeqv2(a, b);
            break;
        case fixnum_of_int(boole_c2):
            r = lognot(b);
            break;
        case fixnum_of_int(boole_orc2):
            b = lognot(b);
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_c1):
            r = lognot(a);
            break;
        case fixnum_of_int(boole_orc1):
            push(b);
            a = lognot(a);
            pop(b);
            r = logior2(a, b);
            break;
        case fixnum_of_int(boole_nand):
            a = logand2(a, b);
            r = lognot(a);
            break;
        case fixnum_of_int(boole_set):
            return onevalue(fixnum_of_int(-1));
        default:
            aerror1("bad arg for boole",  op);
    }
    return onevalue(r);
}

static LispObject Lbyte(LispObject, LispObject a, LispObject b)
{   a = cons(a, b);
    return onevalue(a);
}

static LispObject Lbyte_position(LispObject, LispObject a)
{   if (!consp(a)) aerror1("byte-position", a);
    else return onevalue(qcdr(a));
}

static LispObject Lbyte_size(LispObject, LispObject a)
{   if (!consp(a)) aerror1("byte-size", a);
    else return onevalue(qcar(a));
}

static LispObject Lcomplex_2(LispObject, LispObject a, LispObject b)
{
// /* Need to coerce a and b to the same type here...
    a = make_complex(a, b);
    return onevalue(a);
}

static LispObject Lcomplex_1(LispObject, LispObject a)
{
// /* Need to make zero of same type as a
    a = make_complex(a, fixnum_of_int(0));
    return onevalue(a);
}

static LispObject Lconjugate(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("conjugate", a);
    if (is_numbers(a) && is_complex(a))
    {   LispObject r = real_part(a),
                       i = imag_part(a);
        push(r);
        i = negate(i);
        pop(r);
        a = make_complex(r, i);
        return onevalue(a);
    }
    else return onevalue(a);
}

static LispObject Ldenominator(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("denominator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(denominator(a));
    else return onevalue(fixnum_of_int(1));
}

static LispObject Ldeposit_field(LispObject, int nargs, ...)
{
//
// Not implemented yet!
//
    va_list aa;
    LispObject a, b, c;
    (void)nargs;   // should really check value
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    aerror("deposit-field");
}

static LispObject Ldpb(LispObject, int nargs, ...)
{
//
// Not implemented yet!
//
    va_list aa;
    LispObject a, b, c;
    (void)nargs;  // should really check value
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    aerror("dpb");
}

static LispObject Lffloor(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    aerror("ffloor");
}

LispObject Lgcd_n(LispObject env, int nargs, ...)
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
        if (r == fixnum_of_int(1))
        {   popv(nargs-i);
            break;
        }
        pop(w);
        r = gcd(r, w);
    }
    return onevalue(r);
}

LispObject Lgcd(LispObject env, LispObject a, LispObject b)
{   return onevalue(gcd(a, b));
}

LispObject Lgcd_1(LispObject, LispObject a)
{   return onevalue(a);
}

static LispObject Limagpart(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("imagpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(imag_part(a));
// /* the 0.0 returned here ought to be the same type as a has
    else return onevalue(fixnum_of_int(0));
}

static LispObject Lldb(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    aerror("ldb");
}

LispObject Llcm_n(LispObject env, int nargs, ...)
{   va_list a;
    int i;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   LispObject w;
        pop(w);
        r = lcm(r, w);
    }
    return onevalue(r);
}

LispObject Llcm(LispObject env, LispObject a, LispObject b)
{   return onevalue(lcm(a, b));
}

LispObject Llcm_1(LispObject, LispObject a)
{   return onevalue(a);
}

static LispObject Lldb_test(LispObject, LispObject, LispObject)
{
//
// Not implemented yet!
//
    aerror("ldb-test");
}

static LispObject Lnumerator(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("numerator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(numerator(a));
    else return onevalue(a);
}

static LispObject Lrealpart(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("realpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(real_part(a));
    else return onevalue(a);
}

static LispObject Ldecode_float(LispObject env, LispObject a)
{   double d, neg = 1.0;
    int x;
    LispObject sign;
// @@@ This does not deal with 128-bit floats yet.
    if (!is_float(a)) aerror("decode-float");
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) aerror("decode-float");
        else return onevalue(nil); // infinity or NaN
    }
// Ha ha ha - I detect -0.0 here.
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else if (1.0/d == 0.0)               // An infinity
    {   x = 1000000;                     // Extreme (arbitrary) value
    }
    else
    {   d = frexp(d, &x);
        if (d == 1.0) d = 0.5, x++;
    }
    if (is_sfloat(a)) sign = pack_immediate_float(neg, a);
    else sign = make_boxfloat(neg, type_of_header(flthdr(a)));
    push(sign);
    if (is_sfloat(a)) a = pack_immediate_float(d, a);
    else a = make_boxfloat(d, type_of_header(flthdr(a)));
    pop(sign);
#ifdef COMMON
//
// Until and unless Standard Lisp supports multiple values this has to
// return a list in standard lisp mode.
//
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
}

// If I have a number d then if (1.0/d)==0.0 I think that d must have been
// infinite and not a NaN. One needs to be confident that for a HUGE (but
// finite) d that the reciprocal will not underflow - but IEEE subnormal
// numbers extend the range to make that OK. Note that if d==0.0 then 1.0/d
// will come out as an infinity (not raising an exception) so all will be OK!


static LispObject Lfp_infinite(LispObject env, LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (1.0 / value_of_immediate_float(a) == 0.0)
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_LONG_FLOAT:
                    if (f128M_infinite(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case TYPE_SINGLE_FLOAT:
                case TYPE_DOUBLE_FLOAT:
                    if (1.0 / double_float_val(a) == 0.0)
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// A NaN is not equal to even itself....
//

static LispObject Lfp_nan(LispObject env, LispObject a)
{   switch ((int)a & XTAG_BITS)
    {
        case XTAG_SFLOAT:
            if (value_of_immediate_float(a) == value_of_immediate_float(a))
                return onevalue(nil);
            return onevalue(lisp_true);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a) == single_float_val(a))
                        return onevalue(nil);
                    return onevalue(lisp_true);
                case TYPE_LONG_FLOAT:
                    if (f128M_nan(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) == double_float_val(a))
                        return onevalue(nil);
                    return onevalue(lisp_true);
            }
        default:
            break;
    }
    return onevalue(nil);
}

static LispObject Lfp_finite(LispObject env, LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (value_of_immediate_float(a) -
                value_of_immediate_float(a) == 0.0)
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_LONG_FLOAT:
                    if (f128M_finite(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case TYPE_SINGLE_FLOAT:
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) -
                        double_float_val(a) == 0.0)
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

static LispObject Lfp_subnorm(LispObject env, LispObject a)
{   int32_t x = 0;
    switch ((int)a & XTAG_BITS)
    {   case XTAG_SFLOAT:
            {   Float_union ff;
                ff.f = value_of_immediate_float(a);
                if (ff.f == 0.0) return onevalue(nil);
                return onevalue(((uint32_t)ff.i & 0x7f800000U) == 0 ?
                    lisp_true : nil);
            }
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    {   Float_union ff;
                        ff.f = single_float_val(a);
                        if (ff.f == 0.0) return onevalue(nil);
                        return onevalue(((uint32_t)ff.i & 0x7f800000U) == 0 ?
                            lisp_true : nil);
                    }
                case TYPE_LONG_FLOAT:
                    if (f128M_subnorm(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) == 0.0) return onevalue(nil);
                    {   Double_union ff;
                        ff.f = double_float_val(a);
                        if (ff.f == 0.0) return onevalue(nil);
                        uint64_t x = ff.i64 & UINT64_C(0x7ff0000000000000);
                        return onevalue(x == 0 ? lisp_true : nil);
                    }
            }
        default:
            break;
    }
    return onevalue(nil);
}

//
// This will return T if its argument has its sign bit set. Note that this
// NOT the same a test (x < 0) because this function returns T for -0.0.
//

static LispObject Lfp_signbit(LispObject env, LispObject a)
{
#ifndef HAVE_SIGNBIT
    int32_t x = 0;
#endif
    switch ((int)a & XTAG_BITS)
    {
        case XTAG_SFLOAT:
            if ((intptr_t)a < 0) return onevalue(lisp_true);
            else return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
#ifdef HAVE_SIGNBIT
                    return onevalue(signbit(single_float_val(a)) ? lisp_true : nil);
#else
                    {   Float_union ff;
                        ff.f = single_float_val(a);
                        return onevalue((int32_t)ff.i < 0 ? lisp_true : nil);
                    }
#endif
                case TYPE_LONG_FLOAT:
                    return onevalue(f128M_negative(&long_float_val(a)) ?
                                    lisp_true : nil);
                case TYPE_DOUBLE_FLOAT:
#ifdef HAVE_SIGNBIT
                    return onevalue(signbit(double_float_val(a)) ? lisp_true : nil);
#else
                    {   Double_union ff;
                        ff.f = double_float_val(a);
                        return onevalue((int64_t)ff.i64 < 0 ? lisp_true : nil);
                    }
#endif
            }
        default:
            break;
    }
    return onevalue(nil);
}


//
// The functions such as float-digits, float-precision, float-radix are
// coded here assuming that IEEE-style arithmetic is being used. If this is
// not so then all the code in this file needs review.  Furthermore I will
// be lazy about NaNs and denormalised numbers for now and come back to
// worry about them later on if I am really forced to.
//

static LispObject Lfloat_digits(LispObject, LispObject a)
{   int tag = (int)a & XTAG_BITS;
    switch (tag)
    {   case XTAG_SFLOAT:
            return onevalue(fixnum_of_int(20));
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return onevalue(fixnum_of_int(24));
                default:
                    return onevalue(fixnum_of_int(53));
                case TYPE_LONG_FLOAT:
                    return onevalue(fixnum_of_int(113));
            }
        default:
            aerror("float-digits");
    }
}

static LispObject Lfloat_precision(LispObject, LispObject a)
{   int tag = (int)a & XTAG_BITS;
    double d = float_of_number(a);
    if (d == 0.0) return onevalue(fixnum_of_int(0));
    switch (tag)
    {   case XTAG_SFLOAT:
            return onevalue(fixnum_of_int(20));
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    return onevalue(fixnum_of_int(24));
                default:
                    return onevalue(fixnum_of_int(53));
                case TYPE_LONG_FLOAT:
                    return onevalue(fixnum_of_int(113));
            }
        default:
            aerror("float-precision");
    }
}

static LispObject Lfloat_radix(LispObject, LispObject)
{   return onevalue(fixnum_of_int(FLT_RADIX));
}

static LispObject Lfloat_sign2(LispObject, LispObject a, LispObject b)
{   if (is_bfloat(b) &&
        type_of_header(flthdr(b)) == TYPE_LONG_FLOAT)
    {   float128_t d = float128_of_number(b);
// If a is another long float then float_of_number may overflow, but
// here I am only interested in its sign, and -infinity is still negative.
        if (float_of_number(a) < 0.0) f128M_negate(&d);
        return onevalue(make_boxfloat128(d));
    }
    double d = float_of_number(b);
// Worry a bit about -0.0 here
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return onevalue(pack_immediate_float(d, b));
    else if (!is_bfloat(b)) aerror1("bad arg for float-sign",  b);
// make_boxfloat may detect infinity or NaN.
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
}

static LispObject Lfloat_sign1(LispObject, LispObject a)
{   if (is_bfloat(1) &&
        type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
    {   float128_t d = float128_of_number(a);
        float128_t r = f128_1;
        if (f128M_negative(&d)) f128M_negate(&r);
        return onevalue(make_boxfloat128(r));
    }
    double d = float_of_number(a);
// worry a bit about -0.0 here
    if (d < 0.0) d = -1.0; else d = 1.0;
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) aerror1("bad arg for float-sign",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

static LispObject Lfround(LispObject, LispObject, LispObject)
{   aerror("fround");
}

static LispObject Lftruncate(LispObject, LispObject, LispObject)
{   aerror("ftruncate");
}

//
// This may need to worry about NaNs and infinities.
//

static LispObject Linteger_decode_float(LispObject env, LispObject a)
{   double d;
    int tag = (int)a & TAG_BITS;
    int x, neg = 0;
    int32_t a1, a2;
    if (!is_float(a)) aerror("integer-decode-float");
// @@@ Here I should support float128_t...
    if (is_bfloat(a) && type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
    {   aerror("long floats i integer-decode-float not yet coded");
    }
    d = float_of_number(a);
    if (!(d == d)) return onevalue(nil);
    if (d == 0.0)
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(d<0 ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(d<0 ? -1 : 1));
#endif
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = 1;
    if (1.0/d == 0.0)
    {   a = fixnum_of_int(1);
        x = 1000000;
    }
    else
    {   d = frexp(d, &x);
        if (d == 1.0) d = 0.5, x++;
        if (tag == (XTAG_SFLOAT & TAG_BITS))
        {   d *= TWO_20;
            x -= 20;
            a1 = (int32_t)d;
            a = fixnum_of_int(a1);
        }
        else
        if (tag == TAG_BOXFLOAT &&
                 type_of_header(flthdr(a)) == TYPE_SINGLE_FLOAT)
        {   d *= TWO_24;
            x -= 24;
            a1 = (int32_t)d;
            a = fixnum_of_int(a1);
        }
        else
        {   d *= TWO_22;
            a1 = (int32_t)d;
            d -= (double)a1;
            a2 = (int32_t)(d*TWO_31);  // This conversion should be exact
            x -= 53;
            a = make_two_word_bignum(a1, a2);
        }
    }
#ifdef COMMON
    {   mv_2 = fixnum_of_int(x);
        mv_3 = neg ? fixnum_of_int(-1) : fixnum_of_int(1);
        return nvalues(a, 3);
    }
#else
    return list3(a, fixnum_of_int(x),
                 neg ? fixnum_of_int(-1) : fixnum_of_int(1));
#endif
}

static LispObject Linteger_length(LispObject env, LispObject a)
{   return Lmsd(nil, Labsval(nil, a));
}

static LispObject Llogbitp(LispObject, LispObject, LispObject)
{   aerror("logbitp");
}

static LispObject Llogcount(LispObject, LispObject)
{   aerror("logcount");
}

static LispObject Llogtest(LispObject, LispObject, LispObject)
{   aerror("logtest");
}

static LispObject Lmask_field(LispObject, LispObject, LispObject)
{   aerror("mask-field");
}

static LispObject Lscale_float(LispObject, LispObject a, LispObject b)
{
// @@@ long floats not supported here yet.
    double d = float_of_number(a);
    if (!is_fixnum(b)) aerror("scale-float");
    d = ldexp(d, int_of_fixnum(b));
// Overflows etc handled by make_boxfloat. 128-bit floats not supported.
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

#define FIX_TRUNCATE 0
#define FIX_ROUND    1
#define FIX_FLOOR    2
#define FIX_CEILING  3

static LispObject lisp_fix_sub(LispObject a, int roundmode)
//
// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate. This does not support long (ie 128-bit)
// floats (yet!). @@@
//
{   bool negative;
    double d = float_of_number(a), d1;
    if (!(d == d)) aerror("NaN in fix");
    if (1.0/d == 0.0) aerror("infinity in fix");
    int x;
    d1 = frexp(d, &x);
    if (x < 63)  // i.e. |d| < 2^63
    {   int64_t n = (int64_t)d;
// Here the absolute value of d was strictly smaller than 2^63 and it
// was truncated towards zero in the conversion to an integer, so n
// is a value that would fit in a 64-bit integer. Fixing the rounding mode
// can only possibly change its value by +1 or -1, and that means that the
// only possibility for overflow is if it starts of as 0x7fffffffffffffff and
// has to be rounded up. If d is negative then the range of negative integers
// is such that rounding can not overflow.
        double f;   // The fraction part that is left over...
        switch (roundmode)
        {   default:
            case FIX_TRUNCATE:  // The cast truncated so I am done.
                return make_lisp_integer64(n);
            case FIX_ROUND:
                f = d - (double)n;
                if (f > 0.5) n++;
                else if (f < -0.5) n--;
                else if (f == 0.5) n = (n+1) & ~1;
                else if (f == -0.5) n = n & ~1;
// By converting positive values as unsigned integers I avoid overflow.
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
            case FIX_FLOOR:
                f = d - (double)n;
                if (f < 0.0) n--;  // no overflow possible
                return make_lisp_integer64(n);
                break;
            case FIX_CEILING:
                f = d - (double)n;
                if (f > 0.0) n++;
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
        }
    }        
// Now I know that the result will be at least a 63-bit integer, which means
// it will be at least a 3-word bignum. Life is even better than that. If
// the input as that large then since a double precision float only has 56
// bits for its mantissa I know now that I will not need to do any rounding,
// and so all the complication regarding the rounding mode does not apply.
    if (d1 < 0.0) d1 = -d1, negative = true;
    else negative = false;
    if (d1 == 1.0) d1 = 0.5, x++;
    d1 *= TWO_31;
    int32_t a1 = (int32_t)d1;      // 2^31 > d1 >= 2^30
    d1 -= (double)a1;
    uint32_t a2 = (uint32_t)(d1*TWO_31);  // This conversion should be exact
    if (negative)
    {   if (a2 == 0) a1 = -a1;
        else a2 = clear_top_bit(-a2), a1 = ~a1;
    }
    x -= 62;
// Now the double-length value (a1,a2) is correct and exact, and it
// needs shifting left by x bits.  This will give a 3 or more word bignum.
// Note that no rounding etc is needed at all here since there are no
// fractional bits in the representation.
//
    int32_t a0;
    if (a1 < 0)
    {   a0 = -1;
        a1 = clear_top_bit(a1);
    }
    else a0 = 0;
    int x1 = x / 31;
    x = x % 31;
    a0 = (a0 << x) | (a1 >> (31-x));
    a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
    a2 = clear_top_bit(a2 << x);
    return make_n_word_bignum(a0, a1, a2, x1);
}

static LispObject lisp_fix_ratio(LispObject a, int roundmode)
//
// This converts from a ratio to a Lisp integer.  It has to apply
// the specified rounding regime.
//
{   LispObject p, q, r;
    p = numerator(a);
    q = denominator(a);
    push2(q, p);
    r = quot2(p, q);
    p = stack[0];
    stack[0] = r;
    p = Cremainder(p, stack[-1]);
    pop2(r, q);
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
            // /* This case unfinished at present
            break;
        case FIX_FLOOR:
            if (minusp(p))
            {   push(r);
                p = plus2(p, q);
                pop(r);
                r = sub1(r);
            }
            break;
        case FIX_CEILING:
            if (plusp(p))
            {   push(r);
                p = difference2(p, q);
                pop(r);
                r = add1(r);
            }
            break;
    }
    mv_2 = p;
    return nvalues(r, 2);
}

static LispObject lisp_fix(LispObject a, int roundmode)
{   LispObject r;
    push(a);
    r = lisp_fix_sub(a, roundmode);
    a = stack[0];
    stack[0] = r;
    a = difference2(a, r);
    pop(r);
    mv_2 = a;
    return nvalues(r, 2);
}

static LispObject lisp_ifix(LispObject a, LispObject b, int roundmode)
{   LispObject q, r;
    if (is_float(a) || is_float(b))
    {   double p = float_of_number(a), q = float_of_number(b), d = p/q;
        a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
        r = lisp_fix(a, roundmode);
        push(r);
        a = make_boxfloat(float_of_number(mv_2)*q, TYPE_DOUBLE_FLOAT);
        pop(r);
        mv_2 = a;
        return nvalues(r, 2);
    }
    push2(a, b);
    q = quot2(a, b);
    a = stack[-1];
    b = stack[0];
    push(q);
    r = Cremainder(a, b);
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
            popv(3); aerror("two-arg ROUND");
        case FIX_FLOOR:
            if (!minusp(r)) break;
            r = plus2(r, stack[-1]);
            q = stack[0];
            push(r);
            q = sub1(q);
            pop(r);
            stack[0] = q;
            break;
        case FIX_CEILING:
            if (!plusp(r)) break;
            r = difference2(r, stack[-1]);
            q = stack[0];
            push(r);
            q = add1(q);
            pop(r);
            stack[0] = q;
            break;
    }
    pop3(q, b, a);
    mv_2 = r;
    return nvalues(q, 2);
}

//
// So far I have not implemented support for rational numbers in the 2-arg
// versions of these functions. /*
//

static LispObject Lceiling_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("ceiling", a);
    return lisp_ifix(a, b, FIX_CEILING);
}

static LispObject Lfloor_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("floor", a);
    return lisp_ifix(a, b, FIX_FLOOR);
}

static LispObject Lround_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("round", a);
    return lisp_ifix(a, b, FIX_ROUND);
}

LispObject Ltruncate_2(LispObject, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("truncate", a);
    return lisp_ifix(a, b, FIX_TRUNCATE);
}

static LispObject Lceiling(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("ceiling", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_CEILING);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_CEILING);
}

static LispObject Lfloor(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("floor", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_FLOOR);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_FLOOR);
}

static LispObject Lround(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("round", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_ROUND);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_ROUND);
}

LispObject Ltruncate(LispObject, LispObject a)
{   if (!is_number(a)) aerror1("fix", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_TRUNCATE);
    if (!is_float(a))
    {   mv_2 = fixnum_of_int(0);
        return nvalues(a, 2);
    }
    return lisp_fix(a, FIX_TRUNCATE);
}

setup_type const arith08_setup[] =
{   {"ceiling",                 Lceiling, Lceiling_2, WRONG_NO_1},
    {"floor",                   Lfloor, Lfloor_2, WRONG_NO_1},
    {"round",                   Lround, Lround_2, WRONG_NO_1},
    {"fix",                     Ltruncate, Ltruncate_2, WRONG_NO_1},
    {"truncate",                Ltruncate, Ltruncate_2, WRONG_NO_1},
    {"decode-float",            Ldecode_float, TOO_MANY_1, WRONG_NO_1},
// The next two are old names for these functions, retained just for
// backwards compatibility
    {"float-denormalized-p",    Lfp_subnorm, TOO_MANY_1, WRONG_NO_1},
    {"float-infinity-p",        Lfp_infinite, TOO_MANY_1, WRONG_NO_1},
    {"fp-infinite",             Lfp_infinite, TOO_MANY_1, WRONG_NO_1},
    {"fp-nan",                  Lfp_nan, TOO_MANY_1, WRONG_NO_1},
    {"fp-finite",               Lfp_finite, TOO_MANY_1, WRONG_NO_1},
    {"fp-subnorm",              Lfp_subnorm, TOO_MANY_1, WRONG_NO_1},
    {"fp-signbit",              Lfp_signbit, TOO_MANY_1, WRONG_NO_1},
    {"integer-decode-float",    Linteger_decode_float, TOO_MANY_1, WRONG_NO_1},
    {"integer-length",          Linteger_length, TOO_MANY_1, WRONG_NO_1},
    {"float-digits",            Lfloat_digits, TOO_MANY_1, WRONG_NO_1},
    {"float-precision",         Lfloat_precision, TOO_MANY_1, WRONG_NO_1},
    {"float-radix",             Lfloat_radix, TOO_MANY_1, WRONG_NO_1},
    {"float-sign",              Lfloat_sign1, Lfloat_sign2, WRONG_NO_2},
    {"fround",                  TOO_FEW_2, Lfround, WRONG_NO_2},
    {"ftruncate",               TOO_FEW_2, Lftruncate, WRONG_NO_2},
    {"logbitp",                 TOO_FEW_2, Llogbitp, WRONG_NO_2},
    {"logcount",                Llogcount, TOO_MANY_1, WRONG_NO_1},
    {"logtest",                 TOO_FEW_2, Llogtest, WRONG_NO_2},
    {"mask-field",              TOO_FEW_2, Lmask_field, WRONG_NO_2},
    {"scale-float",             TOO_FEW_2, Lscale_float, WRONG_NO_2},
    {"boole",                   WRONG_NO_NA, WRONG_NO_NB, Lboole},
    {"byte",                    TOO_FEW_2, Lbyte, WRONG_NO_2},
    {"byte-position",           Lbyte_position, TOO_MANY_1, WRONG_NO_1},
    {"byte-size",               Lbyte_size, TOO_MANY_1, WRONG_NO_1},
    {"complex",                 Lcomplex_1, Lcomplex_2, WRONG_NO_2},
    {"conjugate",               Lconjugate, TOO_MANY_1, WRONG_NO_1},
    {"decode-float",            Ldecode_float, TOO_MANY_1, WRONG_NO_1},
    {"denominator",             Ldenominator, TOO_MANY_1, WRONG_NO_1},
    {"deposit-field",           WRONG_NO_NA, WRONG_NO_NB, Ldeposit_field},
    {"dpb",                     WRONG_NO_NA, WRONG_NO_NB, Ldpb},
    {"ffloor",                  TOO_FEW_2, Lffloor, WRONG_NO_2},
    {"imagpart",                Limagpart, TOO_MANY_1, WRONG_NO_1},
    {"ldb",                     TOO_FEW_2, Lldb, WRONG_NO_2},
    {"ldb-test",                TOO_FEW_2, Lldb_test, WRONG_NO_2},
    {"numerator",               Lnumerator, TOO_MANY_1, WRONG_NO_1},
    {"realpart",                Lrealpart, TOO_MANY_1, WRONG_NO_1},
    {"gcd",                     Lgcd_1, Lgcd, Lgcd_n},
    {"gcdn",                    Lgcd_1, Lgcd, Lgcd_n},
    {"lcmn",                    Llcm_1, Llcm, Llcm_n},
    {NULL,                      0,0,0}
};

// end of arith08.cpp
