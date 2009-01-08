/*  arith08.c                         Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Arithmetic functions.
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



/* Signature: 11450fc6 24-May-2008 */

#include "headers.h"


#ifdef COMMON

static Lisp_Object MS_CDECL Lboole(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object r, op, a, b;
    va_list aa;
    argcheck(nargs, 3, "boole");
    va_start(aa, nargs);
    op = va_arg(aa, Lisp_Object);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    va_end(aa);
    switch (op)
    {
case fixnum_of_int(boole_clr):
        return onevalue(fixnum_of_int(0));
case fixnum_of_int(boole_and):
        r = logand2(a, b);
        break;
case fixnum_of_int(boole_andc2):
        push(a);
        b = lognot(b);
        pop(a);
        errexit();
        r = logand2(a, b);
        break;
case fixnum_of_int(boole_1):
        return onevalue(a);
case fixnum_of_int(boole_andc1):
        push(b);
        a = lognot(a);
        pop(b);
        errexit();
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
        errexit();
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
        errexit();
        r = logior2(a, b);
        break;
case fixnum_of_int(boole_c1):
        r = lognot(a);
        break;
case fixnum_of_int(boole_orc1):
        push(b);
        a = lognot(a);
        pop(b);
        errexit();
        r = logior2(a, b);
        break;
case fixnum_of_int(boole_nand):
        a = logand2(a, b);
        errexit();
        r = lognot(a);
        break;
case fixnum_of_int(boole_set):
        return onevalue(fixnum_of_int(-1));
default:
        return aerror1("bad arg for boole",  op);
    }
    errexit();
    return onevalue(r);
}

static Lisp_Object Lbyte(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    a = cons(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lbyte_position(Lisp_Object nil, Lisp_Object a)
{
    if (!consp(a)) return aerror1("byte-position", a);
    else return onevalue(qcdr(a));
}

static Lisp_Object Lbyte_size(Lisp_Object nil, Lisp_Object a)
{
    if (!consp(a)) return aerror1("byte-size", a);
    else return onevalue(qcar(a));
}

static Lisp_Object Lcomplex_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
/* /* Need to coerce a and b to the same type here... */
    a = make_complex(a, b);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lcomplex_1(Lisp_Object nil, Lisp_Object a)
{
/* /* Need to make zero of same type as a */
    a = make_complex(a, fixnum_of_int(0));
    errexit();
    return onevalue(a);
}

static Lisp_Object Lconjugate(Lisp_Object nil, Lisp_Object a)
{
    if (!is_number(a)) return aerror1("conjugate", a);
    if (is_numbers(a) && is_complex(a))
    {   Lisp_Object r = real_part(a),
                    i = imag_part(a);
        push(r);
        i = negate(i);
        pop(r);
        errexit();
        a = make_complex(r, i);
        errexit();
        return onevalue(a);
    }
    else return onevalue(a);
}

static Lisp_Object Ldecode_float(Lisp_Object nil, Lisp_Object a)
{
    double d = float_of_number(a), neg = 1.0;
    int x;
    Lisp_Object sign;
    if (!is_float(a)) return aerror("decode-float");
    if (d < 0.0) d = -d, neg = -1.0;
    if (d == 0.0) x = 0;
    else
    {   d = frexp(d, &x);
        if (d == 1.0) d = 0.5, x++;
    }
    if (is_sfloat(a)) sign = make_sfloat(neg);
    else sign = make_boxfloat(neg, type_of_header(flthdr(a)));
    errexit();
    push(sign);
    if (is_sfloat(a)) a = make_sfloat(d);
    else a = make_boxfloat(d, type_of_header(flthdr(a)));
    pop(sign);
    errexit();
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
}

/*
 * The next two functions depend on IEEE-format floating point numbers.
 * They are (thus?) potentially a portability trap, but may suffice for
 * MOST systems. I need to test the handling of double precision values
 * on computers that store the two words of a double in each of the
 * possible orders. If the exponent field in floats was not stored in the
 * position that would be 0x7f800000 in an integer my treatment of short
 * floats would fail, so I have already assumed that that is so. I think.
 */

static Lisp_Object Lfloat_denormalized_p(Lisp_Object nil, Lisp_Object a)
{
    int x = 0;
    switch ((int)a & TAG_BITS)
    {
#ifdef COMMON
case TAG_SFLOAT:
        if ((a & 0x7fffffff) == TAG_SFLOAT) return onevalue(nil);  /* 0.0 */
        x = (int32_t)a & 0x7f800000;
        return onevalue(x == 0 ? lisp_true : nil);
#endif
case TAG_BOXFLOAT:
        switch (type_of_header(flthdr(a)))
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            if (single_float_val(a) == 0.0) return onevalue(nil);
            x = ((Single_Float *)((char *)a-TAG_BOXFLOAT))->f.i & 0x7f800000;
            return onevalue(x == 0 ? lisp_true : nil);
    case TYPE_LONG_FLOAT:
            if (long_float_val(a) == 0.0) return onevalue(nil);
            x = ((int32_t *)long_float_addr(a))[
                    current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
            return onevalue(x == 0 ? lisp_true : nil);
#endif
    case TYPE_DOUBLE_FLOAT:
            if (double_float_val(a) == 0.0) return onevalue(nil);
            x = ((int32_t *)double_float_addr(a))[
                    current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
            return onevalue(x == 0 ? lisp_true : nil);
        }
default:
        break;
    }
    return onevalue(nil);
}

static Lisp_Object Lfloat_infinity_p(Lisp_Object nil, Lisp_Object a)
{
/*
 * The issue of NaN values is one I do not want to worry about at present.
 * I deem anything with the largest possibl exponent value to be infinite.
 */
    int x = 0;
    switch ((int)a & TAG_BITS)
    {
#ifdef COMMON
case TAG_SFLOAT:
        x = (int32_t)a & 0x7f800000;
        return onevalue(x == 0x7f800000 ? lisp_true : nil);
#endif
case TAG_BOXFLOAT:
        switch (type_of_header(flthdr(a)))
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            if (single_float_val(a) == 0.0) return onevalue(nil);
            x = ((Single_Float *)((char *)a-TAG_BOXFLOAT))->f.i & 0x7f800000;
            return onevalue(x == 0x7f800000 ? lisp_true : nil);
    case TYPE_LONG_FLOAT:
            if (long_float_val(a) == 0.0) return onevalue(nil);
            x = ((int32_t *)long_float_addr(a))[
                    current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
            return onevalue(x == 0x7ff00000 ? lisp_true : nil);
#endif
    case TYPE_DOUBLE_FLOAT:
            if (double_float_val(a) == 0.0) return onevalue(nil);
            x = ((int32_t *)double_float_addr(a))[
                    current_fp_rep&FP_WORD_ORDER ? 0 : 1] & 0x7ff00000;
            return onevalue(x == 0x7ff00000 ? lisp_true : nil);
        }
default:
        break;
    }
    return onevalue(nil);
}

static Lisp_Object Ldenominator(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("denominator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(denominator(a));
    else return onevalue(fixnum_of_int(1));
}

static Lisp_Object MS_CDECL Ldeposit_field(Lisp_Object nil, int nargs, ...)
{
    va_list aa;
    Lisp_Object a, b, c;
    CSL_IGNORE(nil);
    CSL_IGNORE(nargs);
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    return aerror("deposit-field");
}

static Lisp_Object MS_CDECL Ldpb(Lisp_Object nil, int nargs, ...)
{
    va_list aa;
    Lisp_Object a, b, c;
    CSL_IGNORE(nil);
    CSL_IGNORE(nargs);
    va_start(aa, nargs);
    a = va_arg(aa, Lisp_Object);
    b = va_arg(aa, Lisp_Object);
    c = va_arg(aa, Lisp_Object);
    va_end(aa);
    return aerror("dpb");
}

static Lisp_Object Lffloor(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("ffloor");
}

/*
 * The functions such as float-digits, float-precision, float-radix are
 * coded here assuming that IEEE-style arithmetic is being used. If this is
 * not so then all the code in this file needs review.  Furthermore I will
 * be lazy about NaNs and denormalised numbers for now and come back to
 * worry about them later on if I am really forced to.
 */

static Lisp_Object Lfloat_digits(Lisp_Object nil, Lisp_Object a)
{
    int tag = (int)a & TAG_BITS;
    CSL_IGNORE(nil);
    switch (tag)
    {
#ifdef COMMON
case TAG_SFLOAT:
        return onevalue(fixnum_of_int(20));
#endif
case TAG_BOXFLOAT:
        switch (type_of_header(flthdr(a)))
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            return onevalue(fixnum_of_int(24));
#endif
    default:
            return onevalue(fixnum_of_int(53));
        }
default:
        return aerror("float-digits");
    }
}

static Lisp_Object Lfloat_precision(Lisp_Object nil, Lisp_Object a)
{
    int tag = (int)a & TAG_BITS;
    double d = float_of_number(a);
    CSL_IGNORE(nil);
    if (d == 0.0) return onevalue(fixnum_of_int(0));
/* /* I do not cope with de-normalised numbers here */
    switch (tag)
    {
#ifdef COMMON
case TAG_SFLOAT:
        return onevalue(fixnum_of_int(20));
#endif
case TAG_BOXFLOAT:
        switch (type_of_header(flthdr(a)))
        {
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            return onevalue(fixnum_of_int(24));
#endif
    default:
            return onevalue(fixnum_of_int(53));
        }
default:
        return aerror("float-precision");
    }
}

static Lisp_Object Lfloat_radix(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    return onevalue(fixnum_of_int(FLT_RADIX));
}

static Lisp_Object Lfloat_sign2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(b);
    CSL_IGNORE(nil);
    if (float_of_number(a) < 0.0) d = -d;
    if (is_sfloat(b)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(b)) return aerror1("bad arg for float-sign",  b);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
}

static Lisp_Object Lfloat_sign1(Lisp_Object nil, Lisp_Object a)
{
    double d = float_of_number(a);
    CSL_IGNORE(nil);
    if (d < 0.0) d = -1.0; else d = 1.0;
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(a)) return aerror1("bad arg for float-sign",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

static Lisp_Object Lfround(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("fround");
}

static Lisp_Object Lftruncate(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("ftruncate");
}

Lisp_Object MS_CDECL Lgcd_n(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    int i;
    Lisp_Object r;
    if (nargs == 0) return fixnum_of_int(0);
    va_start(a, nargs);
    push_args(a, nargs);
/*
 * The actual args have been passed a C args - I can not afford to
 * risk garbage collection until they have all been moved somewhere safe,
 * and here that safe place is the Lisp stack.  I have to delay checking for
 * overflow on same until all args have been pushed.
 */
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   Lisp_Object w;
        if (r == fixnum_of_int(1))
        {   popv(nargs-i);
            break;
        }
        pop(w);
        r = gcd(r, w);
        errexitn(nargs-i-1);
    }
    return onevalue(r);
}

Lisp_Object Lgcd(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    a = gcd(a, b);
    errexit();
    return onevalue(a);
}

Lisp_Object Lgcd_1(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(a);
}

static Lisp_Object Limagpart(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("imagpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(imag_part(a));
/* /* the 0.0 returned here ought to be the same type as a has */
    else return onevalue(fixnum_of_int(0));
}

static Lisp_Object Linteger_decode_float(Lisp_Object nil, Lisp_Object a)
{
    double d = float_of_number(a);
    int tag = (int)a & TAG_BITS, x, neg = 0;
    int32_t a1, a2;
    CSL_IGNORE(nil);
    if (!is_float(a)) return aerror("integer-decode-float");
    if (d == 0.0)
#ifdef COMMON
    {   mv_2 = fixnum_of_int(0);
        mv_3 = fixnum_of_int(1);
        nvalues(a, 3);
    }
#else
        return list3(a, fixnum_of_int(0), fixnum_of_int(1));
#endif
    if (d < 0.0) d = -d, neg = 1;
    d = frexp(d, &x);
    if (d == 1.0) d = 0.5, x++;
#ifdef COMMON
    if (tag == TAG_SFLOAT)
    {   d *= TWO_20;
        x -= 20;
        a1 = (int32_t)d;
        a = fixnum_of_int(a1);
    }
    else if (tag == TAG_BOXFLOAT &&
             type_of_header(flthdr(a)) == TYPE_SINGLE_FLOAT)
    {   d *= TWO_24;
        x -= 24;
        a1 = (int32_t)d;
        a = fixnum_of_int(a1);
    }
    else
#endif
    {   d *= TWO_22;
        a1 = (int32_t)d;
        d -= (double)a1;
        a2 = (int32_t)(d*TWO_31);  /* This conversion should be exact */
        x -= 53;
        a = make_two_word_bignum(a1, a2);
        errexit();
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

static Lisp_Object Linteger_length(Lisp_Object nil, Lisp_Object a)
{
    a = Labsval(nil, a);
    errexit();
    return Lmsd(nil, a);
}

static Lisp_Object Lldb(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("ldb");
}

Lisp_Object MS_CDECL Llcm_n(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    int i;
    Lisp_Object r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    va_start(a, nargs);
    push_args(a, nargs);
    stackcheck0(nargs);
    pop(r);
    for (i = 1; i<nargs; i++)
    {   Lisp_Object w;
        pop(w);
        r = lcm(r, w);
        errexitn(nargs-i-1);
    }
    return onevalue(r);
}

Lisp_Object Llcm(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    a = lcm(a, b);
    errexit();
    return onevalue(a);
}

Lisp_Object Llcm_1(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(a);
}

static Lisp_Object Lldb_test(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("ldb-test");
}

static Lisp_Object Llogbitp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("logbitp");
}

static Lisp_Object Llogcount(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    return aerror("logcount");
}

static Lisp_Object Llogtest(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("logtest");
}

static Lisp_Object Lmask_field(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    CSL_IGNORE(a);
    CSL_IGNORE(b);
    return aerror("mask-field");
}

static Lisp_Object Lnumerator(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("numerator", a);
    if (is_numbers(a) && is_ratio(a))
        return onevalue(numerator(a));
    else return onevalue(a);
}

static Lisp_Object Lrealpart(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("realpart", a);
    if (is_numbers(a) && is_complex(a))
        return onevalue(real_part(a));
    else return onevalue(a);
}

static Lisp_Object Lscale_float(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(a);
    CSL_IGNORE(nil);
    if (!is_fixnum(b)) return aerror("scale-float");
    d = ldexp(d, int_of_fixnum(b));
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else if (!is_bfloat(a)) return aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

#else /* COMMON */

Lisp_Object Lgcd(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    a = gcd(a, b);
    errexit();
    return onevalue(a);
}

Lisp_Object Llcm(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object g;
    push2(b, a);
    g = gcd(a, b);
    errexitn(2);
    pop(a);
    a = quot2(a, g);
    pop(b);
    errexit();
    a = times2(a, b);
    errexit();
    return onevalue(a);
}

#endif /* COMMON */

#define FIX_TRUNCATE 0
#define FIX_ROUND    1
#define FIX_FLOOR    2
#define FIX_CEILING  3

static Lisp_Object lisp_fix_sub(Lisp_Object a, int roundmode)
/*
 * This converts from a double to a Lisp integer, which will
 * quite often have to be a bignum.  No overflow is permitted - the
 * result can always be accurate.
 */
{
    int32_t a0, a1, a2, a3;
    int x, x1;
    CSLbool negative;
    double d = float_of_number(a);
    if (M2_31_1 < d && d < TWO_31)
    {   int32_t a = (int32_t)d;
/*
 * If my floating point value is in the range -(2^31+1) to +2^31 (exclusive)
 * then when C truncates it I will get an integer in the inclusive range
 * from -2^31 to 2^31-1, i.e. the whole range of C 32-bit integers.
 * If I then apply a rounding mode other than truncation I may just have
 * overflow, which I have to detect specially.
 */
        int32_t w;
        double f;
        switch (roundmode)
        {
    case FIX_TRUNCATE:
            break;          /* C casts truncate, so this is OK */
    case FIX_ROUND:
            f = d - (double)a;
            if (f > 0.5)
            {   if (a == 0x7fffffff) return make_two_word_bignum(1, 0);
                else a++;
            }
            else if (f < -0.5)
            {   if (a == ~0x7fffffff)
                    return make_two_word_bignum(-2, 0x7fffffff);
                else a--;
            }
   /* The rounding rule on the next lines show what I do in 1/2ulp cases */
            else if (f == 0.5) a = (a+1) & ~1;
            else if (f == -0.5)
            {   if (a == ~0x7fffffff)
                    return make_two_word_bignum(-2, 0x7fffffff);
                else a = a & ~1;
            }
            break;
    case FIX_FLOOR:
            f = d - (double)a;
            if (f < 0.0)
            {   if (a == ~0x7fffffff)
                    return make_two_word_bignum(-2, 0x7fffffff);
                else a--;
            }
            break;
    case FIX_CEILING:
            f = d - (double)a;
            if (f > 0.0)
            {   if (a == 0x7fffffff) return make_two_word_bignum(1, 0);
                else a++;
            }
            break;
        }
        w = a & fix_mask;
        if (w == 0 || w == fix_mask) return fixnum_of_int(a);
        else if (!signed_overflow(a)) return make_one_word_bignum(a);
        else if (a > 0) return make_two_word_bignum(0, a);
        else return make_two_word_bignum(-1, clear_top_bit(a));
    }
    if (d < 0.0) d = -d, negative = YES;
    else negative = NO;
    d = frexp(d, &x); /* 0.5 <= abs(d) < 1.0, x = the (binary) exponent */
    if (d == 1.0) d = 0.5, x++;
    d *= TWO_31;
    a1 = (int32_t)d;      /* 2^31 > d >= 2^30 */
    d -= (double)a1;
    a2 = (uint32_t)(d*TWO_31);  /* This conversion should be exact */
    if (negative)
    {   if (a2 == 0) a1 = -a1;
        else a2 = clear_top_bit(-a2), a1 = ~a1;
    }
    x -= 62;
    if (x < 0)              /* Need to shift right x places */
    {   x = -x;             /* The shift amount here can be 31 at most... */
        a3 = a2 << (32 - x);
        a2 = clear_top_bit((a2 >> x) | (a1 << (31 - x)));
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
        if (a1 < 0) a1 = (a1 >> x) | (((int32_t)-1) << (31 - x));
        else a1 = a1 >> x;
#else
        a1 = a1 >> x;
#endif
        switch (roundmode)
        {
    case FIX_TRUNCATE:
            if (a1 < 0 && a3 != 0)  /* proper rounding on -ve values */
            {   a2++;
                if (a2 < 0) /* carry */
                {   a2 = 0;
                    a1++;
                }
            }
            break;
    case FIX_ROUND:
            if ((a3 & 0x80000000U) != 0 &&
               (a3 != ~0x7fffffff || (a2 & 1) != 0))
            {   a2++;
                if (a2 < 0) /* carry */
                {   a2 = 0;
                    a1++;
                }
            }
            break;
    case FIX_FLOOR: /* Comes out in wash of 2's complement */
            break;
    case FIX_CEILING:
            if (a3 != 0)
            {   a2++;
                if (a2 < 0) /* carry */
                {   a2 = 0;
                    a1++;
                }
            }
            break;
        }
        return make_two_word_bignum(a1, a2);
    }
/* Now the double-length value (a1,a2) is correct and exact, and it
 * needs shifting left by x bits.  This will give a 3 or more word bignum.
 * Note that no rounding etc is needed at all here since there are no
 * fractional bits in the representation.
 */
    if (a1 < 0)
    {   a0 = -1;
        a1 = clear_top_bit(a1);
    }
    else a0 = 0;
    x1 = x / 31;
    x = x % 31;
    a0 = (a0 << x) | (a1 >> (31-x));
    a1 = clear_top_bit(a1 << x) | (a2 >> (31-x));
    a2 = clear_top_bit(a2 << x);
    return make_n_word_bignum(a0, a1, a2, x1);
}

#ifdef COMMON

static Lisp_Object lisp_fix_ratio(Lisp_Object a, int roundmode)
/*
 * This converts from a ratio to a Lisp integer.  It has to apply
 * the specified rounding regime.
 */
{
    Lisp_Object p, q, r, nil = C_nil;;
    p = numerator(a);
    q = denominator(a);
    push2(q, p);
    r = quot2(p, q);
    errexitn(2);
    p = stack[0];
    stack[0] = r;
    p = Cremainder(p, stack[-1]);
    pop2(r, q);
    errexit();
    switch (roundmode)
    {
case FIX_TRUNCATE:
        break;
case FIX_ROUND:
        /* /* This case unfinished at present */
        break;
case FIX_FLOOR:
        if (minusp(p))
        {   push(r);
            p = plus2(p, q);
            pop(r);
            errexit();
            r = sub1(r);
            errexit();
        }
        break;
case FIX_CEILING:
        if (plusp(p))
        {   push(r);
            p = difference2(p, q);
            pop(r);
            errexit();
            r = add1(r);
            errexit();
        }
        break;
    }
    mv_2 = p;
    return nvalues(r, 2);
}
#endif


static Lisp_Object lisp_fix(Lisp_Object a, int roundmode)
{
    Lisp_Object r, nil;
    push(a);
    r = lisp_fix_sub(a, roundmode);
    errexitn(1);
    a = stack[0];
    stack[0] = r;
    a = difference2(a, r);
    pop(r);
    errexit();
    mv_2 = a;
    return nvalues(r, 2);
}

static Lisp_Object lisp_ifix(Lisp_Object a, Lisp_Object b, int roundmode)
{
    Lisp_Object q, r, nil;
    if (is_float(a) || is_float(b))
    {   double p = float_of_number(a), q = float_of_number(b), d = p/q;
        a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
        errexit();
        r = lisp_fix(a, roundmode);
        errexit();
        push(r);
        a = make_boxfloat(float_of_number(mv_2)*q, TYPE_DOUBLE_FLOAT);
        pop(r);
        errexit();
        mv_2 = a;
        return nvalues(r, 2);
    }
    push2(a, b);
    q = quot2(a, b);
    errexitn(2);
    a = stack[-1];
    b = stack[0];
    push(q);
    r = Cremainder(a, b);
    errexitn(3);
    switch (roundmode)
    {
case FIX_TRUNCATE:
        break;
case FIX_ROUND:
        popv(3); return aerror("two-arg ROUND");
case FIX_FLOOR:
        if (!minusp(r)) break;
        r = plus2(r, stack[-1]);
        errexitn(3);
        q = stack[0];
        push(r);
        q = sub1(q);
        pop(r);
        errexitn(3);
        stack[0] = q;
        break;
case FIX_CEILING:
        if (!plusp(r)) break;
        r = difference2(r, stack[-1]);
        errexitn(3);
        q = stack[0];
        push(r);
        q = add1(q);
        pop(r);
        errexitn(3);
        stack[0] = q;
        break;
    }
    pop3(q, b, a);
    mv_2 = r;
    return nvalues(q, 2);
}

/*
 * So far I have not implemented support for rational numbers in the 2-arg
 * versions of these functions. /*
 */

static Lisp_Object Lceiling_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_number(a) || !is_number(b)) return aerror1("ceiling", a);
    return lisp_ifix(a, b, FIX_CEILING);
}

static Lisp_Object Lfloor_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_number(a) || !is_number(b)) return aerror1("floor", a);
    return lisp_ifix(a, b, FIX_FLOOR);
}

static Lisp_Object Lround_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_number(a) || !is_number(b)) return aerror1("round", a);
    return lisp_ifix(a, b, FIX_ROUND);
}

Lisp_Object Ltruncate_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_number(a) || !is_number(b)) return aerror1("truncate", a);
    return lisp_ifix(a, b, FIX_TRUNCATE);
}

static Lisp_Object Lceiling(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("ceiling", a);
#ifdef COMMON
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_CEILING);
#endif
    if (!is_float(a)) { mv_2 = fixnum_of_int(0); return nvalues(a, 2); }
    return lisp_fix(a, FIX_CEILING);
}

static Lisp_Object Lfloor(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("floor", a);
#ifdef COMMON
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_FLOOR);
#endif
    if (!is_float(a)) { mv_2 = fixnum_of_int(0); return nvalues(a, 2); }
    return lisp_fix(a, FIX_FLOOR);
}

static Lisp_Object Lround(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("round", a);
#ifdef COMMON
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_ROUND);
#endif
    if (!is_float(a)) { mv_2 = fixnum_of_int(0); return nvalues(a, 2); }
    return lisp_fix(a, FIX_ROUND);
}

Lisp_Object Ltruncate(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_number(a)) return aerror1("fix", a);
#ifdef COMMON
    if (is_numbers(a) && is_ratio(a)) return lisp_fix_ratio(a, FIX_TRUNCATE);
#endif
    if (!is_float(a)) { mv_2 = fixnum_of_int(0); return nvalues(a, 2); }
    return lisp_fix(a, FIX_TRUNCATE);
}

/*
 * The following macro is expected to select out the 32-bit word within a
 * floating point number that has the exponent field packed within it.
 * On IEEE-format machines I expect to find the exponent in the
 * 0x7ff00000 bits within this word. It sets i to the top half of the
 * floating value d, and worries somewhat about GCCs strict aliasing
 * optimisation!! Specifically it avoids the use of pointers in the
 * punning that has to go on.
 */

#define top_half(ii, d)                          \
  { union { double f; int32_t i[2]; } w;         \
    w.f = d;                                     \
    ii = w.i[(~current_fp_rep) & FP_WORD_ORDER]; \
  }

/*
 *  symbolic procedure safe!-fp!-plus(x,y);
 *     if zerop x then y else if zerop y then x else
 *     begin scalar u;
 *        if x>0.0 and y>0.0 then
 *           if x<!!plumax and y<!!plumax then go to ret else return nil;
 *        if x<0.0 and y<0.0 then
 *           if -x<!!plumax and -y<!!plumax then go to ret else return nil;
 *        if abs x<!!plumin and abs y<!!plumin then return nil;
 *   ret: return
 *          if (u := plus2(x,y))=0.0
 *             or x>0.0 and y>0.0 or x<0.0 and y<0.0 then u
 *          else if abs u<(abs x)*!!fleps1 then 0.0 else u end;
 */

static Lisp_Object Lsafe_fp_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b)
/*
 * safe!-fp!-plus must always be given floating point arguments.  In
 * most reasonable cases it just returns the floating point sum.  If
 * there was some chance that the sum might either overflow or underflow
 * then the value NIL is returned instead.  The exact place where this
 * function starts to report overflow is not precisely defined - all that
 * is guaranteed is that if a result is returned then it will be of full
 * precision.
 */
{
    Lisp_Object nil = C_nil;
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-plus", a, b);
/*
 * I accept here that adding 0.0 to anything is always possible without
 * problem.
 */
    if ((aa = double_float_val(a)) == 0.0) return onevalue(b);
    if ((bb = double_float_val(b)) == 0.0) return onevalue(a);
    top_half(ah, aa);
    top_half(bh, bb);
/*
 * Here I am going to assume IEEE-format numbers. I hope that I have
 * picked out the word containing the exponent and that it is positioned in
 * the word where I expect.
 */
/*
 * I deem overflow POSSIBLE if both numbers have the same sign and if at
 * least one of them has an exponent 0x7fe (i.e. the highest exponent that
 * a non-infinite number can have).
 */
    if (ah >= 0)
    {   if (bh >= 0)
        {   if (ah >= 0x7fe00000 || bh >= 0x7fe00000) return onevalue(nil);
            cc = aa + bb;
        }
        else
/*
 * I deem underflow POSSIBLE if the numbers have opposite signs and BOTH
 * of them have exponents less than 0x035 (which is 53 in decimal, and
 * IEEE-format numbers have 53-bit mantissas.  The critical case would
 * be the subtraction
 *   (53) 1 00000000000000000000 00000000000000000000000000000001
 * - (53) 1 00000000000000000000 00000000000000000000000000000000
 * where you see the LSB (which is all that is left after the subtraction)
 * has to be shifted left 52 bits to get to the position of the implied
 * leading 1 bit in the mantissa.  As that happens 52 gets subtracted
 * from the exponent, leaving it as 1, the smallest exponent for a normalised
 * non-zero value.
 */
        {   double eps, ra;
            bh &= 0x7fffffff;
            if (ah < 0x03500000 && bh < 0x03500000) return onevalue(nil);
/*
 * The next few lines check to see if addition has led to cancellation of
 * leading digits to an extent greater than !!fleps1.  The environent cell
 * of safe!-fp!-plus must be set to !!fleps, and then the value cell of
 * this symbol is accessed to obtain the limit.
 */
            eps = 0.0;
            if (is_symbol(env))
            {   Lisp_Object ve = qvalue(env);
                if (is_float(ve)) eps = double_float_val(ve);
            }
            cc = aa + bb;
            ra = cc/aa;
            if (ra < 0.0) ra = -ra;
            if (ra < eps) cc = 0.0; /* Force to zero if too small */
        }
    }
    else
    {   if (bh >= 0)
        {   double eps, ra;
            ah &= 0x7fffffff;
            if (ah < 0x03500000 && bh < 0x03500000) return onevalue(nil);
            eps = 0.0;
            if (is_symbol(env))
            {   Lisp_Object ve = qvalue(env);
                if (is_float(ve)) eps = double_float_val(ve);
            }
            cc = aa + bb;
            ra = cc/aa;
            if (ra < 0.0) ra = -ra;
            if (ra < eps) cc = 0.0;
        }
        else
        {   ah &= 0x7fffffff;
            bh &= 0x7fffffff;
            if (ah >= 0x7fe00000 || bh >= 0x7fe00000) return onevalue(nil);
            cc = aa + bb;
        }
    }
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

/*
 *  symbolic procedure safe!-fp!-times(x,y);
 *   if zerop x or zerop y then 0.0
 *   else if x=1.0 then y else if y=1.0 then x else
 *     begin scalar u,v; u := abs x; v := abs y;
 *        if u>=1.0 and u<=!!timmax then
 *           if v<=!!timmax then go to ret else return nil;
 *        if u>!!timmax then if v<=1.0 then go to ret else return nil;
 *        if u<1.0 and u>=!!timmin then
 *           if v>=!!timmin then go to ret else return nil;
 *        if u<!!timmin and v<1.0 then return nil;
 *   ret: return times2(x,y) end;
 */

static Lisp_Object Lsafe_fp_times(Lisp_Object nil,
                                  Lisp_Object a, Lisp_Object b)
/*
 * safe!-fp!-times must always be given floating point arguments.  In
 * most reasonable cases it just returns the floating point product.  If
 * there was some chance that the product might either overflow or underflow
 * then the value NIL is returned instead.  REDUCE requires that if this
 * function returns a non-overflow result than two such returned values
 * can be added witjout fear of overflow, as in a*b+c*d.  Hence I ought to
 * report trouble slightly earlier than I might otherwise. - but REDUCE is
 * being changed to remove this oddity, and it seems it could only cause
 * trouble in (1.0,max)*(max, 1.0) complex multiplication, so I am not
 * going to worry...
 */
{
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-times", a, b);
/*
 * Multiplication by zero is handled as a special case here - doing so
 * means that I do not have to worry about the special case of zero
 * exponents later on, and it also avoids allocating fresh space to hold
 * a new floating point zero value.
 */
    if ((aa = double_float_val(a)) == 0.0) return onevalue(a);
    if ((bb = double_float_val(b)) == 0.0) return onevalue(b);
    top_half(ah, aa);
    top_half(bh, bb);
/*
 * Here I am going to assume IEEE-format numbers. I hope that I have
 * picked out the word containing the exponent and that it is positioned in
 * the word where I expect.
 */
    ah = (ah >> 20) & 0x7ff;
    bh = (bh >> 20) & 0x7ff;
    ah = ah + bh;
/*
 * I can estimate the value of the product by adding the exponents of the
 * two operands.
 */
    if (ah < 0x400 || ah >= 0xbfd) return onevalue(nil);
    cc = aa * bb;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

/*
 *  symbolic procedure safe!-fp!-quot(x,y);
 *   if zerop y then rdqoterr()
 *   else if zerop x then 0.0 else if y=1.0 then x else
 *     begin scalar u,v; u := abs x; v := abs y;
 *        if u>=1.0 and u<=!!timmax then
 *           if v>=!!timmin then go to ret else return nil;
 *        if u>!!timmax then if v>=1.0 then go to ret else return nil;
 *        if u<1.0 and u>=!!timmin then
 *           if v<=!!timmax then go to ret else return nil;
 *        if u<!!timmin and v>1.0 then return nil;
 *   ret: return quotient(x,y) end;
 */

static Lisp_Object Lsafe_fp_quot(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-quot", a, b);
    if ((aa = double_float_val(a)) == 0.0) return onevalue(a);
/*
 * I pass division by zero back to the general case here.
 */
    if ((bb = double_float_val(b)) == 0.0) return onevalue(nil);
    top_half(ah, aa);
    top_half(bh, bb);
    ah = (ah >> 20) & 0x7ff;
    bh = (bh >> 20) & 0x7ff;
    ah = ah - bh;
    if (ah <= -0x3fe || ah >= 0x3fe) return onevalue(nil);
    cc = aa / bb;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

/*
 *  symbolic procedure safe!-fp!-pl(x,y);
 *    % floating plus protect from under- and over-flows but no zero
 *    % result check.
 *     if zerop x then y else if zerop y then x
 *     else if x>0 and y>0 then
 *        if x<!!plumax and y<!!plumax then plus2(x,y) else nil
 *     else if x<0 and y<0 then
 *        if (-x<!!plumax and -y<!!plumax) then plus2(x,y) else nil
 *     else if abs x<!!plumin or abs y<!!plumin then nil else plus2(x,y);
 */

static Lisp_Object Lsafe_fp_pl(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-pl", a, b);
    if ((aa = double_float_val(a)) == 0.0) return onevalue(b);
    if ((bb = double_float_val(b)) == 0.0) return onevalue(a);
    top_half(ah, aa);
    top_half(bh, bb);
    if (ah >= 0)
    {   if (bh >= 0)
        {   if (ah >= 0x7fe00000 || bh >= 0x7fe00000) return onevalue(nil);
        }
        else
        {   bh &= 0x7fffffff;
            if (ah < 0x03500000 && bh < 0x03500000) return onevalue(nil);
        }
    }
    else
    {   if (bh >= 0)
        {   ah &= 0x7fffffff;
            if (ah < 0x03500000 && bh < 0x03500000) return onevalue(nil);
        }
        else
        {   ah &= 0x7fffffff;
            bh &= 0x7fffffff;
            if (ah >= 0x7fe00000 || bh >= 0x7fe00000) return onevalue(nil);
        }
    }
    cc = aa + bb;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

/*
 *  symbolic procedure safe!-fp!-pl0(x,y);
 *    % protects floating plus against under-flow only.
 *     if zerop x then y else if zerop y then x
 *     else if abs x<!!plumin and abs y<!!plumin then nil else plus2(x,y);
 *
 * implement as safe!-fp!-pl without MUCH loss of speed.
 */  

static Lisp_Object Llose_precision(Lisp_Object nil,
                                   Lisp_Object a, Lisp_Object n)
{
    double aa;
    char buffer[64];
    int32_t nn;
    if (!is_float(a) || !is_fixnum(n)) return aerror2("lose_precision", a, n);
    nn = int_of_fixnum(n);
    if (nn <= 0 || nn >= 20) return onevalue(a);
    sprintf(buffer, "%.*g", (int)nn, double_float_val(a));
    if (sscanf(buffer, "%lg", &aa) != 1) return aerror("lose-precision");
    a = make_boxfloat(aa, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

setup_type const arith08_setup[] =
{
/*
 * The next few are JUST for REDUCE, but they are expected to speed up
 * rounded-mode arithmetic rather a lot.
 */
    {"lose-precision",          too_few_2, Llose_precision, wrong_no_2},
    {"safe-fp-plus",            too_few_2, Lsafe_fp_plus, wrong_no_2},
    {"safe-fp-times",           too_few_2, Lsafe_fp_times, wrong_no_2},
    {"safe-fp-quot",            too_few_2, Lsafe_fp_quot, wrong_no_2},
    {"safe-fp-pl",              too_few_2, Lsafe_fp_pl, wrong_no_2},
    {"safe-fp-pl0",             too_few_2, Lsafe_fp_pl, wrong_no_2},
/* End of REDUCE specialities */
    {"ceiling",                 Lceiling, Lceiling_2, wrong_no_1},
    {"floor",                   Lfloor, Lfloor_2, wrong_no_1},
    {"round",                   Lround, Lround_2, wrong_no_1},
    {"truncate",                Ltruncate, Ltruncate_2, wrong_no_1},
#ifdef COMMON
    {"boole",                   wrong_no_na, wrong_no_nb, Lboole},
    {"byte",                    too_few_2, Lbyte, wrong_no_2},
    {"byte-position",           Lbyte_position, too_many_1, wrong_no_1},
    {"byte-size",               Lbyte_size, too_many_1, wrong_no_1},
    {"complex",                 Lcomplex_1, Lcomplex_2, wrong_no_2},
    {"conjugate",               Lconjugate, too_many_1, wrong_no_1},
    {"decode-float",            Ldecode_float, too_many_1, wrong_no_1},
    {"float-denormalized-p",    Lfloat_denormalized_p, too_many_1, wrong_no_1},
    {"float-infinity-p",        Lfloat_infinity_p, too_many_1, wrong_no_1},
    {"denominator",             Ldenominator, too_many_1, wrong_no_1},
    {"deposit-field",           wrong_no_na, wrong_no_nb, Ldeposit_field},
    {"dpb",                     wrong_no_na, wrong_no_nb, Ldpb},
    {"ffloor",                  too_few_2, Lffloor, wrong_no_2},
    {"float-digits",            Lfloat_digits, too_many_1, wrong_no_1},
    {"float-precision",         Lfloat_precision, too_many_1, wrong_no_1},
    {"float-radix",             Lfloat_radix, too_many_1, wrong_no_1},
    {"float-sign",              Lfloat_sign1, Lfloat_sign2, wrong_no_2},
    {"fround",                  too_few_2, Lfround, wrong_no_2},
    {"ftruncate",               too_few_2, Lftruncate, wrong_no_2},
    {"gcd",                     Lgcd_1, Lgcd, Lgcd_n},
    {"imagpart",                Limagpart, too_many_1, wrong_no_1},
    {"integer-decode-float",    Linteger_decode_float, too_many_1, wrong_no_1},
    {"integer-length",          Linteger_length, too_many_1, wrong_no_1},
    {"ldb",                     too_few_2, Lldb, wrong_no_2},
    {"ldb-test",                too_few_2, Lldb_test, wrong_no_2},
    {"lcm",                     Llcm_1, Llcm, Llcm_n},
    {"logbitp",                 too_few_2, Llogbitp, wrong_no_2},
    {"logcount",                Llogcount, too_many_1, wrong_no_1},
    {"logtest",                 too_few_2, Llogtest, wrong_no_2},
    {"mask-field",              too_few_2, Lmask_field, wrong_no_2},
    {"numerator",               Lnumerator, too_many_1, wrong_no_1},
    {"realpart",                Lrealpart, too_many_1, wrong_no_1},
    {"scale-float",             too_few_2, Lscale_float, wrong_no_2},
#else
    {"fix",                     Ltruncate, too_many_1, wrong_no_1},
    {"gcdn",                    too_few_2, Lgcd, wrong_no_2},
    {"lcmn",                    too_few_2, Llcm, wrong_no_2},
#endif
    {NULL,                      0,0,0}
};

/* end of arith08.c */

