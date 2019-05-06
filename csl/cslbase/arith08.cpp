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


static LispObject Lboole_3(LispObject env, LispObject op,
        LispObject a1, LispObject a2)
{   LispObject r;
    switch (is_fixnum(op) ? int_of_fixnum(op) : -1)
    {   case boole_clr:
            return onevalue(fixnum_of_int(0));
        case boole_and:
            r = logand2(a1, a2);
            break;
        case boole_andc2:
            push(a1);
            a2 = lognot(a2);
            pop(a1);
            r = logand2(a1, a2);
            break;
        case boole_1:
            return onevalue(a1);
        case boole_andc1:
            push(a2);
            a1 = lognot(a1);
            pop(a2);
            r = logand2(a1, a2);
            break;
        case boole_2:
            return onevalue(a2);
        case boole_xor:
            r = logxor2(a1, a2);
            break;
        case boole_ior:
            r = logior2(a1, a2);
            break;
        case boole_nor:
            a1 = logior2(a1, a2);
            r = lognot(a1);
            break;
        case boole_eqv:
            r = logeqv2(a1, a2);
            break;
        case boole_c2:
            r = lognot(a2);
            break;
        case boole_orc2:
            a2 = lognot(a2);
            r = logior2(a1, a2);
            break;
        case boole_c1:
            r = lognot(a1);
            break;
        case boole_orc1:
            push(a2);
            a1 = lognot(a1);
            pop(a2);
            r = logior2(a1, a2);
            break;
        case boole_nand:
            a1 = logand2(a1, a2);
            r = lognot(a1);
            break;
        case boole_set:
            return onevalue(fixnum_of_int(-1));
        default:
            aerror1("bad arg for boole",  op);
    }
    return onevalue(r);
}

static LispObject Lbyte(LispObject env, LispObject a, LispObject b)
{   a = cons(a, b);
    return onevalue(a);
}

static LispObject Lbyte_position(LispObject env, LispObject a)
{   if (!consp(a)) aerror1("byte-position", a);
    else return onevalue(qcdr(a));
}

static LispObject Lbyte_size(LispObject env, LispObject a)
{   if (!consp(a)) aerror1("byte-size", a);
    else return onevalue(qcar(a));
}

static LispObject Lcomplex_2(LispObject env, LispObject a, LispObject b)
{
// /* Need to coerce a and b to the same type here...
    a = make_complex(a, b);
    return onevalue(a);
}

static LispObject Lcomplex_1(LispObject env, LispObject a)
{
// /* Need to make zero of same type as a
    a = make_complex(a, fixnum_of_int(0));
    return onevalue(a);
}

static LispObject Lconjugate(LispObject env, LispObject a)
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

static LispObject Ldenominator(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("denominator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(denominator(a));
    else return onevalue(fixnum_of_int(1));
}

static LispObject Ldeposit_field_3(LispObject env, LispObject a1,
        LispObject a2, LispObject a3)
{
//
// Not implemented yet!
//
#ifdef LATER
// Perhaps I will eventually implement this!
#endif
    aerror("deposit-field");
}

static LispObject Ldpb_3(LispObject env, LispObject a1,
        LispObject a2, LispObject a3)
{
//
// Not implemented yet!
//
#ifdef LATER
// Ha ha!
#endif
    aerror("dpb");
}

static LispObject Lffloor(LispObject env, LispObject a1, LispObject a2)
{
//
// Not implemented yet!
//
    aerror("ffloor");
}

LispObject Lgcd_0(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

LispObject Lgcd_1(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Lgcd_2(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(gcd(a1, a2));
}

LispObject Lgcd_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   push(a3);
    a1 = gcd(a1, a2);
    pop(a2);
    return onevalue(gcd(a1, a2));
}

LispObject Lgcd_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   push(a4up, a3);
    a1 = gcd(a1, a2);
    pop(a3);
    a1 = gcd(a1, a3);
    while (stack[0] != nil)
    {   a2 = stack[0];
        a3 = qcar(a2);
        stack[0] = qcdr(a2);
        a1 = gcd(a1, a3);
    }
    popv(1);
    return onevalue(a1);
}

static LispObject Limagpart(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("imagpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(imag_part(a));
// /* the 0.0 returned here ought to be the same type as a has
    else return onevalue(fixnum_of_int(0));
}

static LispObject Lldb(LispObject env, LispObject a1, LispObject a2)
{
//
// Not implemented yet!
//
    aerror("ldb");
}

LispObject Llcm_0(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

LispObject Llcm_1(LispObject env, LispObject a1)
{   return onevalue(a1);
}

LispObject Llcm_2(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(lcm(a1, a2));
}

LispObject Llcm_3(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   push(a3);
    a1 = lcm(a1, a2);
    pop(a2);
    return onevalue(lcm(a1, a2));
}

LispObject Llcm_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   push(a4up, a3);
    a1 = lcm(a1, a2);
    pop(a3);
    a1 = lcm(a1, a3);
    while (stack[0] != nil)
    {   a2 = stack[0];
        a3 = qcar(a2);
        stack[0] = qcdr(a2);
        a1 = lcm(a1, a3);
    }
    popv(1);
    return onevalue(a1);
}

static LispObject Lldb_test(LispObject env, LispObject a1, LispObject a2)
{
//
// Not implemented yet!
//
    aerror("ldb-test");
}

static LispObject Lnumerator(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("numerator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(numerator(a));
    else return onevalue(a);
}

static LispObject Lrealpart(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("realpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(real_part(a));
    else return onevalue(a);
}

#ifdef HAVE_SOFTFLOAT
LispObject decode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128M_infinite(&d) || f128M_nan(&d))
    {   if (trap_floating_overflow) aerror("decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    bool neg = false;
    int x = 0;
    if (f128M_negative(&d)) f128M_negate(&d), neg = true;
    if (f128M_eq(&d, &f128_0)) x = 0;
    else
    {   if (f128M_subnorm(&d))
        {   f128M_mul(&d, &f128_N1, &d);
            x -= 4096;
        }
        x += f128M_exponent(&d) - 0x3fff;
        f128M_set_exponent(&d, 0x3fff);
    }
    LispObject sign = make_boxfloat128(f128_1);
    if (neg) f128M_negate(long_float_addr(sign));
    push(sign);
    a = make_boxfloat128(d);
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
#endif // HAVE_SOFTFLOAT

LispObject Ldecode_float(LispObject env, LispObject a)
{   double d, neg = 1.0;
    int x;
    LispObject sign;
    if (!is_float(a)) aerror("decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
        return decode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) aerror("decode-float");
        else return onevalue(nil); // infinity or NaN
    }
// Ha ha ha - I detect -0.0 here.
    if (d < 0.0 || (d == 0.0 && 1.0/d < 0)) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else d = frexp(d, &x);
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
            {
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    if (f128M_infinite(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
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
            if (value_of_immediate_float(a) != value_of_immediate_float(a))
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {   case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a) != single_float_val(a))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    if (f128M_nan(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a) != double_float_val(a))
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

static LispObject Lfp_finite(LispObject env, LispObject a)
{   switch ((int)a & XTAG_BITS)
    {   case XTAG_SFLOAT:
            if (value_of_immediate_float(a)-value_of_immediate_float(a) == 0.0)
                return onevalue(lisp_true);
            return onevalue(nil);
        case TAG_BOXFLOAT:
        case TAG_BOXFLOAT+TAG_XBIT:
            switch (type_of_header(flthdr(a)))
            {
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    if (f128M_finite(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
                case TYPE_SINGLE_FLOAT:
                    if (single_float_val(a)-single_float_val(a) == 0.0)
                        return onevalue(lisp_true);
                    return onevalue(nil);
                case TYPE_DOUBLE_FLOAT:
                    if (double_float_val(a)-double_float_val(a) == 0.0)
                        return onevalue(lisp_true);
                    return onevalue(nil);
            }
        default:
            break;
    }
    return onevalue(nil);
}

static LispObject Lfp_subnorm(LispObject env, LispObject a)
{   switch ((int)a & XTAG_BITS)
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
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    if (f128M_subnorm(&long_float_val(a)))
                        return onevalue(lisp_true);
                    return onevalue(nil);
#endif // HAVE_SOFTFLOAT
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
#ifdef HAVE_SOFTFLOAT
                case TYPE_LONG_FLOAT:
                    return onevalue(f128M_negative(&long_float_val(a)) ?
                                    lisp_true : nil);
#endif // HAVE_SOFTFLOAT
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

static LispObject Lfloat_digits(LispObject env, LispObject a)
{   int tag = (int)a & XTAG_BITS;
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return onevalue(fixnum_of_int(24));
            else return onevalue(fixnum_of_int(20));
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

static LispObject Lfloat_precision(LispObject env, LispObject a)
{   int tag = (int)a & XTAG_BITS;
    double d = float_of_number(a);
    if (d == 0.0) return onevalue(fixnum_of_int(0));
    switch (tag)
    {   case XTAG_SFLOAT:
            if (SIXTY_FOUR_BIT && ((a & XTAG_FLOAT32) != 0))
                return onevalue(fixnum_of_int(24));
            else return onevalue(fixnum_of_int(20));
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

// In CSL all floats use the same radix (2) and so the function to
// find the radix does not need to look at its argument.

static LispObject Lfloat_radix(LispObject env, LispObject a2)
{   return onevalue(fixnum_of_int(FLT_RADIX));
}

static LispObject Lfloat_sign2(LispObject env, LispObject a, LispObject b)
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(b) &&
        type_of_header(flthdr(b)) == TYPE_LONG_FLOAT)
    {   float128_t d = float128_of_number(b);
// If a is another long float then float_of_number may overflow, but
// here I am only interested in its sign, and -infinity is still negative.
        if (float_of_number(a) < 0.0) f128M_negate(&d);
        return onevalue(make_boxfloat128(d));
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(b);
// Worry a bit about -0.0 here
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return onevalue(pack_immediate_float(d, b));
    else if (!is_bfloat(b)) aerror1("bad arg for float-sign",  b);
// make_boxfloat may detect infinity or NaN.
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
}

static LispObject Lfloat_sign1(LispObject env, LispObject a)
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(1) &&
        type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
    {   float128_t d = float128_of_number(a);
        float128_t r = f128_1;
        if (f128M_negative(&d)) f128M_negate(&r);
        return onevalue(make_boxfloat128(r));
    }
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
// worry a bit about -0.0 here
    if (d < 0.0) d = -1.0; else d = 1.0;
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) aerror1("bad arg for float-sign",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

static LispObject Lfround(LispObject env, LispObject a1, LispObject a2)
{   aerror("fround");
}

static LispObject Lftruncate(LispObject env, LispObject a1, LispObject a2)
{   aerror("ftruncate");
}

#ifdef HAVE_SOFTFLOAT
LispObject integer_decode_long_float(LispObject a)
{   float128_t d = long_float_val(a);
    if (f128M_infinite(&d) || f128M_nan(&d))
    {   if (trap_floating_overflow) aerror("integer-decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    if (f128M_eq(&d, &f128_0))
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(f128M_negative(&d) ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(f128M_negative(&d) ? -1 : 1));
#endif
    bool neg = false;
    if (f128M_negative(&d))
    {   f128M_negate(&d);
        neg = true;
    }
    int32_t d4;
    uint32_t d3, d2, d1, d0;
    intptr_t x = 31*float128_to_5_digits(&d, d4, d3, d2, d1, d0);
    a = make_n5_word_bignum(d4, d3, d2, d1, d0, 0);
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
#endif // HAVE_SOFTFLOAT


LispObject Linteger_decode_float(LispObject env, LispObject a)
{   double d;
    if (!is_float(a)) aerror("integer-decode-float");
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
        return integer_decode_long_float(a);
#endif // HAVE_SOFTFLOAT
    d = float_of_number(a);
    if (floating_edge_case(d))
    {   if (trap_floating_overflow) aerror("integer-decode-float");
        else return onevalue(nil); // infinity or NaN
    }
    if (d == 0.0)
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(1.0/d < 0.0 ? -1 : 1);
        nvalues(fixnum_of_int(0), 3);
    }
#else
        return list3(fixnum_of_int(0), fixnum_of_int(0),
                     fixnum_of_int(1.0/d < 0.0 ? -1 : 1));
#endif
    bool neg = 0;
    if (d < 0.0)
    {   d = -d;
        neg = true;
    }
    int32_t d2;
    uint32_t d1, d0;
    intptr_t x = 31*double_to_3_digits(d, d2, d1, d0);
    a = make_three_word_bignum(d2, d1, d0);
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
{   if (is_fixnum(a))
    {   intptr_t n = int_of_fixnum(a);
        if (n < 0) n = -n-1;
        if (n == 0) return onevalue(fixnum_of_int(0));
// Now n is strictly positive.
        int r = 0;
        if (SIXTY_FOUR_BIT &&
            n >= (intptr_t)INT64_C(0x100000000))
            r += 32, n = (intptr_t)((int64_t)n >> 32);
#ifdef HAVE___BUILTIN_CLZ
        return onevalue(fixnum_of_int(r + 32 - __builtin_clz((uint32_t)n)));
#else
        if (n >= 0x10000) r += 16, n >>= 16;
        if (n >= 0x100)   r += 8,  n >>= 8;
        return onevalue(fixnum_of_int(r + msd_table[n]));
#endif
    }
    if (!is_numbers(a) || !is_bignum(a)) aerror1("integer-length", a);
    if (minusp(a)) a = sub1(negate(a));
    return Lmsd(nil, a);
}

static LispObject Llogbitp(LispObject env, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || (intptr_t)a1 < 0)
        aerror1("logbitp", a1);
    uintptr_t n = int_of_fixnum(a1);
    if (is_fixnum(a2))
    {   intptr_t v = int_of_fixnum(a2);
        if (n < 8*sizeof(v)) return Lispify_predicate(((v>>n)&1) != 0);
        else return Lispify_predicate(v < 0);
    }
    else if (is_numbers(a2) && is_bignum(a2))
    {   size_t len = (length_of_header(numhdr(a2)) - CELL)/4;
        size_t word = n / 31;
        if (word > len)
            return Lispify_predicate(((int32_t)bignum_digits(a2)[len-1]) < 0);
        return Lispify_predicate((bignum_digits(a2)[word] & (1<<(n%31))) != 0);
    }
    else aerror1("logbitp", a2);
}

static LispObject Llogcount(LispObject env, LispObject a)
{   aerror("logcount");
}

static LispObject Llogtest(LispObject env, LispObject a1, LispObject a2)
{   aerror("logtest");
}

static LispObject Lmask_field(LispObject env, LispObject a1, LispObject a2)
{   aerror("mask-field");
}

#ifdef HAVE_SOFTFLOAT
static LispObject scale_float128(LispObject a, intptr_t x)
{   float128_t d = long_float_val(a);
    if (f128M_nan(&d)) return a;
    if (x >= 0x40000) x = 0x40000;
    else if (x <= -0x40000) x = -0x40000;
    if (f128M_subnorm(&d))
    {   f128M_mul(&d, &f128_N1, &d);
        x -= 4096;
    }
    x += f128M_exponent(&d);
    if (x >= 0x7fff)         // result will be infinite
        f128M_make_infinite(&d);
    else if (x <= 0)         // result underflows
    {   if (x < -113) f128M_make_zero(&d);
        else
        {   f128M_set_exponent(&d, x+4096);
// If there is a risk I need to generate a subnormal result do it this way.
            f128M_div(&d, &f128_N1, &d);
        }
    }
    else f128M_set_exponent(&d, x);
    return make_boxfloat128(d);
}
#endif // HAVE_SOFTFLOAT
        

static LispObject Lscale_float(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(b)) aerror("scale-float");
    intptr_t x = int_of_fixnum(b);
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && type_of_header(a) == TYPE_LONG_FLOAT)
       return scale_float128(a, x);
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
    if (x >= 4096) x = 4096;
    else if (x <= -4096) x = -4096;
    d = ldexp(d, (int)x);
// Overflows etc handled by make_boxfloat.
    if (is_sfloat(a)) return onevalue(pack_immediate_float(d, a));
    else if (!is_bfloat(a)) aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

#ifdef HAVE_SOFTFLOAT
// long float version of the following function. Commentary is in the
// double precision version.

static LispObject lisp_fix_sub128(LispObject a, int roundmode)
{   float128_t *d = long_float_addr(a);
    if (f128M_nan(d)) aerror("NaN in fix");
    if (f128M_infinite(d)) aerror("infinity in fix");
    int x = f128M_exponent(d);
// Here I will limit the range where I convert to an int64_t value because
// a long float could have a value of (say) INT64_MAX+0.75, and then the
// conversion would overflow and hence fail.
    if (x < 62)
    {   int64_t n = f128M_to_i64(d, roundmode, false);
// Here the softfloat library does rounding for me. Hoorah!
        return make_lisp_integer64(n);
    }        
// Now I know that the result will be at least a 62-bit integer, which means
// it will be at least a 3-word bignum.
// I may sometimes still need to worry about rounding.
    int32_t d4;
    uint32_t d3, d2, d1, d0;
    intptr_t x1 = float128_to_5_digits(d, d4, d3, d2, d1, d0);
    switch (x1)
    {
    case -2:
// The integer part is at present represented in 2s complement, so if I
// chop bits off its end that will decrease its value. Put another way, the
// raw value I have got is as for FLOOR.
        if (d1 != 0 || d0 != 0)
        {   switch (roundmode)
            {   default:
                case FIX_TRUNCATE:
                    if (d4 < 0) goto inc2; 
                    break;
                case FIX_ROUND:
                    if (d1 > 0x40000000 ||
                        (d1 == 0x40000000 && d0 != 0)) goto inc2;
                    if (d1 == 0x40000000 && ((d2 & 1) != 0)) goto inc2; 
                    break;
                case FIX_FLOOR:
                    break;          // Nothing more to do
                case FIX_CEILING:   // always need to increment here
                inc2:
                    d2++;
                    if (d2 == 0x40000000)
                    {   d2 = 0;
                        d3++;
                        if (d3 == 0x40000000)
                        {   d3 = 0;
                            d4++;
                            if (d4 == 0x40000000) // need an extra word
                                return make_four_word_bignum(0, d4, 0, 0);
                            else if (d4 == 0)
                                return make_two_word_bignum(0xc0000000,0);
                        }
                    }
                    break;
            }
        }
        return make_three_word_bignum(d4, d3, d2);
    case -1:
        if (d0 != 0)
        {   switch (roundmode)
            {   default:
                case FIX_TRUNCATE:
                    if (d4 < 0) goto inc1; 
                    break;
                case FIX_ROUND:
                    if (d0 > 0x40000000) goto inc1;
                    if (d0 == 0x40000000 && ((d1 & 1) != 0)) goto inc1; 
                    break;
                case FIX_FLOOR:
                    break;          // Nothing more to do
                case FIX_CEILING:   // always need to increment here
                inc1:
                    d1++;
                    if (d1 == 0x40000000)
                    {   d1 = 0;
                        d2++;
                        if (d2 == 0x40000000)
                        if (d2 == 0x40000000)
                        {   d2 = 0;
                            d3++;
                            if (d3 == 0x40000000)
                            {   d3 = 0;
                                d4++;
                                if (d4 == 0x40000000) // need an extra word
                                    return make_n_word_bignum(0, d4, 0, 2);
                                else if (d4 == 0)
                                    return make_three_word_bignum(0xc0000000, 0, 0);
                            }
                        }
                    }
                    break;
            }
        }
        return make_four_word_bignum(d4, d3, d2, d1);
    default:
        return make_n5_word_bignum(d4, d3, d2, d1, d0, x1);
    }
}
#endif // HAVE_SOFTFLOAT

static LispObject lisp_fix_sub(LispObject a, int roundmode)
// This converts from a double to a Lisp integer, which will
// quite often have to be a bignum.  No overflow is permitted - the
// result can always be accurate.
{
#ifdef HAVE_SOFTFLOAT
    if (is_bfloat(a) && type_of_header(flthdr(a)) == TYPE_LONG_FLOAT)
        return lisp_fix_sub128(a, roundmode);
#endif // HAVE_SOFTFLOAT
    double d = float_of_number(a);
    if (!(d == d)) aerror("NaN in fix");
    if (1.0/d == 0.0) aerror("infinity in fix");
// I will take a cheaper path if d is such that I can cast it to a 64-bit
// integer without that causing (integer) overflow.
    if (d >= (double)INT64_MIN && d < -(double)INT64_MIN)
    {   int64_t n = (int64_t)d;
// Here the absolute value of d was strictly smaller than 2^63 and it
// was truncated towards zero in the conversion to an integer, so n
// is a value that would fit in a 64-bit integer. Fixing the rounding mode
// can only possibly change its value by +1 or -1, and that means that the
// only imaginable possibility for overflow is if it starts of as
// 0x7fffffffffffffff and has to be rounded up. But because doubles only have
// 53 bits of mantissa any that are close to the ends of the range of 64-bit
// integers will convert exactly to integers without and need for rounding.
        double f;   // The fraction part that is left over...
        switch (roundmode)
        {   default:
            case FIX_TRUNCATE:  // The cast truncated so I am done.
                return make_lisp_integer64(n);
            case FIX_ROUND:
// In a more general situation you could worry that (double)n could introduce
// rounding for some values of n > 2^53. However in any such case n will have
// been derived from a float that had an exact integer value so there will
// not have been any rounding and will not need to be any on the return trip.
                f = d - (double)n;
                if (f > 0.5) n = (uint64_t)n + 1;
                else if (f < -0.5) n--;
                else if (f == 0.5) n = ((uint64_t)n+1) & ~1;
                else if (f == -0.5) n = n & ~1;
// If the original value of n was MAX_INT64 and I rounded up then I
// could have overflowed here, so in the case where that could arise
// I treat the value as unsigned.
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
            case FIX_FLOOR:
                f = d - (double)n;
                if (f < 0.0) n--;  // no overflow possible
                return make_lisp_integer64(n);
                break;
            case FIX_CEILING:
                f = d - (double)n;
                if (f > 0.0) n = (uint64_t)n + 1;
                if (d < 0.0) return make_lisp_integer64(n);
                else return make_lisp_unsigned64(n);
        }
    }        
// Now I know that the result will be at least a 63-bit integer, which means
// it will be at least a 3-word bignum. Life is even better than that. If
// the input as that large then since a double precision float only has 56
// bits for its mantissa I know now that I will not need to do any rounding,
// and so all the complication regarding the rounding mode does not apply.
    int32_t d2;
    uint32_t d1, d0;
    intptr_t x = double_to_3_digits(d, d2, d1, d0);
    return make_n_word_bignum(d2, d1, d0, x);
}

// This converts from a ratio to a Lisp integer.  It has to apply
// rounding in the desired direction.

static LispObject lisp_fix_ratio(LispObject a, int roundmode)
{   LispObject p, q, r, w, w1;
    p = numerator(a);
    q = denominator(a); // note that q will always be positive!
    push(q, p);
    r = quot2(p, q);
    p = stack[0];
    stack[0] = r;
    p = Cremainder(p, stack[-1]);
    pop(r, q);
// The quotient is now in r and the remainder in p. The original divisor
// is back in q.
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// Here p is the eventual remainder. If it is less then -q/2 or greater
// then q/2 I will need to adjust things. And if it is equal in either of
// those edge cases I need to think even harder!
            push(p, q, r);
            w = times2(p, fixnum_of_int(2));
            push(w);
            w1 = negate(w);
            pop(w);
            pop(r, q, p);
            if (greaterp2(w, q) ||
                (numeq2(w, q) && Loddp(nil, r)!=nil))
            {   push(r);
                p = difference2(p, q);
                pop(r);
                r = add1(r);
            }
            else if (greaterp2(w1, q) ||
                     (numeq2(w1, q) && Loddp(nil, r)!=nil))
            {   push(r);
                p = plus2(p, q);
                pop(r);
                r = sub1(r);
            }
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

// This fixes a value a and returns (a - fix(a)) as a second result. This is
// only ever called with a floating point argument.

LispObject lisp_fix(LispObject a, int roundmode)
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

// ifix is for the 2-arg variants of floor, truncate, round etc. For
// floating point values a and b it computes fix(a/b) and the residue
// returned as a second value is b times the residue in that fix operation.

LispObject lisp_ifix(LispObject a, LispObject b, int roundmode)
{   LispObject q, r, r2, negb;
    if (is_float(a) || is_float(b))
    {   push(b);
        a = quot2(a, b);
// If either argument was floating point then the quotient will be.
        r = lisp_fix(a, roundmode);
        a = stack[0];
        stack[0] = r;
        mv_2 = times2(mv_2, a);
        pop(r);
        return nvalues(r, 2);
    }
    push(a, b);
    q = quot2(a, b);
    a = stack[-1];
    b = stack[0];
    push(q);
    r = Cremainder(a, b);
    switch (roundmode)
    {   case FIX_TRUNCATE:
            break;
        case FIX_ROUND:
// I will apply a round-to-nearest, with round-to-even to break ties.
            push(r);
            negb = negate(stack[-2]);
            push(negb);
            r2 = times2(r, fixnum_of_int(2));
            pop(negb, r);
            q = stack[0];
            b = stack[-1];
            if (lessp2(b, r2) ||
                (numeq2(b, r2) && Loddp(nil, q)!=nil)) goto increase_q;
            if (lessp2(r2, negb) ||
                (numeq2(r2, negb) && Loddp(nil, q)!=nil)) goto decrease_q;
            break;
        case FIX_FLOOR:
            if (!minusp(r)) break;
        decrease_q:
            r = plus2(r, stack[-1]);
            q = stack[0];
            push(r);
            q = sub1(q);
            pop(r);
            stack[0] = q;
            break;
        case FIX_CEILING:
            if (!plusp(r)) break;
        increase_q:
            r = difference2(r, stack[-1]);
            q = stack[0];
            push(r);
            q = add1(q);
            pop(r);
            stack[0] = q;
            break;
    }
    pop(q, b, a);
    mv_2 = r;
    return nvalues(q, 2);
}

//
// So far I have not implemented support for rational numbers in the 2-arg
// versions of these functions. /*
//

static LispObject Lceiling_2(LispObject env, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("ceiling", a);
    return lisp_ifix(a, b, FIX_CEILING);
}

static LispObject Lfloor_2(LispObject env, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("floor", a);
    return lisp_ifix(a, b, FIX_FLOOR);
}

static LispObject Lround_2(LispObject env, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("round", a);
    return lisp_ifix(a, b, FIX_ROUND);
}

LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b)
{   if (!is_number(a) || !is_number(b)) aerror1("truncate", a);
    return lisp_ifix(a, b, FIX_TRUNCATE);
}

static LispObject Lceiling(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("ceiling", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_CEILING);
    if (is_float(a)) return lisp_fix(a, FIX_CEILING);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

static LispObject Lfloor(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("floor", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_FLOOR);
    if (is_float(a)) return lisp_fix(a, FIX_FLOOR);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

static LispObject Lround(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("round", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_ROUND);
    if (is_float(a)) return lisp_fix(a, FIX_ROUND);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

LispObject Ltruncate(LispObject env, LispObject a)
{   if (!is_number(a)) aerror1("fix", a);
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_TRUNCATE);
    if (is_float(a)) return lisp_fix(a, FIX_TRUNCATE);
    mv_2 = fixnum_of_int(0);
    return nvalues(a, 2);
}

setup_type const arith08_setup[] =
{   {"ceiling",                 G0Wother, Lceiling, Lceiling_2, G3W1, G4W1},
    {"floor",                   G0Wother, Lfloor, Lfloor_2, G3W1, G4W1},
    {"round",                   G0Wother, Lround, Lround_2, G3W1, G4W1},
    {"fix",                     G0Wother, Ltruncate, Ltruncate_2, G3W1, G4W1},
    {"truncate",                G0Wother, Ltruncate, Ltruncate_2, G3W1, G4W1},
    {"decode-float",            G0W1, Ldecode_float, G2W1, G3W1, G4W1},
// The next two are old names for these functions, retained just for
// backwards compatibility
    {"float-denormalized-p",    G0W1, Lfp_subnorm, G2W1, G3W1, G4W1},
    {"float-infinity-p",        G0W1, Lfp_infinite, G2W1, G3W1, G4W1},
    {"fp-infinite",             G0W1, Lfp_infinite, G2W1, G3W1, G4W1},
    {"fp-nan",                  G0W1, Lfp_nan, G2W1, G3W1, G4W1},
    {"fp-finite",               G0W1, Lfp_finite, G2W1, G3W1, G4W1},
    {"fp-subnorm",              G0W1, Lfp_subnorm, G2W1, G3W1, G4W1},
    {"fp-signbit",              G0W1, Lfp_signbit, G2W1, G3W1, G4W1},
    {"integer-decode-float",    G0W1, Linteger_decode_float, G2W1, G3W1, G4W1},
    {"integer-length",          G0W1, Linteger_length, G2W1, G3W1, G4W1},
    {"float-digits",            G0W1, Lfloat_digits, G2W1, G3W1, G4W1},
    {"float-precision",         G0W1, Lfloat_precision, G2W1, G3W1, G4W1},
    {"float-radix",             G0W1, Lfloat_radix, G2W1, G3W1, G4W1},
    {"float-sign",              G0Wother, Lfloat_sign1, Lfloat_sign2, G3Wother, G4Wother},
    {"fround",                  G0W2, G1W2, Lfround, G3W2, G4W2},
    {"ftruncate",               G0W2, G1W2, Lftruncate, G3W2, G4W2},
    {"logbitp",                 G0W2, G1W2, Llogbitp, G3W2, G4W2},
    {"logcount",                G0W1, Llogcount, G2W1, G3W1, G4W1},
    {"logtest",                 G0W2, G1W2, Llogtest, G3W2, G4W2},
    {"mask-field",              G0W2, G1W2, Lmask_field, G3W2, G4W2},
    {"scale-float",             G0W2, G1W2, Lscale_float, G3W2, G4W2},
    {"boole",                   G0W3, G1W3, G2W3, Lboole_3, G4W3},
    {"byte",                    G0W2, G1W2, Lbyte, G3W2, G4W2},
    {"byte-position",           G0W1, Lbyte_position, G2W1, G3W1, G4W1},
    {"byte-size",               G0W1, Lbyte_size, G2W1, G3W1, G4W1},
    {"complex",                 G0Wother, Lcomplex_1, Lcomplex_2, G3Wother, G4Wother},
    {"conjugate",               G0W1, Lconjugate, G2W1, G3W1, G4W1},
    {"decode-float",            G0W1, Ldecode_float, G2W1, G3W1, G4W1},
    {"denominator",             G0W1, Ldenominator, G2W1, G3W1, G4W1},
    {"deposit-field",           G0W3, G1W3, G2W3, Ldeposit_field_3, G4W3},
    {"dpb",                     G0W3, G1W3, G2W3, Ldpb_3, G4W3},
    {"ffloor",                  G0W1, G1W2, Lffloor, G3W2, G4W2},
    {"imagpart",                G0W1, Limagpart, G2W1, G3W1, G4W1},
    {"ldb",                     G0W2, G1W2, Lldb, G3W2, G4W2},
    {"ldb-test",                G0W2, G1W2, Lldb_test, G3W2, G4W2},
    {"numerator",               G0W1, Lnumerator, G2W1, G3W1, G4W1},
    {"realpart",                G0W1, Lrealpart, G2W1, G3W1, G4W1},
    {"gcd",                     Lgcd_0, Lgcd_1, Lgcd_2, Lgcd_3, Lgcd_4up},
    {"gcdn",                    Lgcd_0, Lgcd_1, Lgcd_2, Lgcd_3, Lgcd_4up},
    {"lcmn",                    Llcm_0, Llcm_1, Llcm_2, Llcm_3, Llcm_4up},
    {NULL,                      0,0,0,0,0}
};

// end of arith08.cpp
