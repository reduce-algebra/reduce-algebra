/*  arith08.c                         Copyright (C) 1990-2011 Codemist Ltd */

/*
 * Arithmetic functions.
 */

/**************************************************************************
 * Copyright (C) 2011, Codemist Ltd.                     A C Norman       *
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



/* Signature: 427f6fcf 26-Sep-2011 */

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
#ifdef COMMON
    if (is_sfloat(a)) sign = make_sfloat(neg);
    else
#endif
        sign = make_boxfloat(neg, type_of_header(flthdr(a)));
    errexit();
    push(sign);
#ifdef COMMON
    if (is_sfloat(a)) a = make_sfloat(d);
    else
#endif
        a = make_boxfloat(d, type_of_header(flthdr(a)));
    pop(sign);
    errexit();
#ifdef COMMON
    mv_2 = fixnum_of_int(x);
    mv_3 = sign;
    return nvalues(a, 3);
#else
    return list3(sign, fixnum_of_int(x), a);
#endif
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
#ifdef COMMON
    if (is_sfloat(b)) return onevalue(make_sfloat(d));
    else
#endif
    if (!is_bfloat(b)) return aerror1("bad arg for float-sign",  b);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(b))));
}

static Lisp_Object Lfloat_sign1(Lisp_Object nil, Lisp_Object a)
{
    double d = float_of_number(a);
    CSL_IGNORE(nil);
    if (d < 0.0) d = -1.0; else d = 1.0;
#ifdef COMMON
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else
#endif
    if (!is_bfloat(a)) return aerror1("bad arg for float-sign",  a);
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

static Lisp_Object Linteger_decode_float(Lisp_Object nil, Lisp_Object a)
{
    double d = float_of_number(a);
#ifdef COMMON
    int tag = (int)a & TAG_BITS;
#endif
    int x, neg = 0;
    int32_t a1, a2;
    CSL_IGNORE(nil);
    if (!is_float(a)) return aerror("integer-decode-float");
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

static Lisp_Object Lscale_float(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    double d = float_of_number(a);
    CSL_IGNORE(nil);
    if (!is_fixnum(b)) return aerror("scale-float");
    d = ldexp(d, int_of_fixnum(b));
#ifdef COMMON
    if (is_sfloat(a)) return onevalue(make_sfloat(d));
    else
#endif
    if (!is_bfloat(a)) return aerror1("bad arg for scale-float",  a);
    else return onevalue(make_boxfloat(d, type_of_header(flthdr(a))));
}

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
 * Commentary on these "safe" functions:
 *
 * The portable Reduce code is very conservative in the case of
 * multiplication and division, and this is perhaps the sort of
 * operation that can be speeded up by implementation at a kernel
 * level. But at present I am keeping C code that should EXACTLY
 * match the portable code in here - albeit "ifdef'd" out.
 */


#ifdef MATCH_REDUCE_CODE_IN_ROUNDED_RED

/*
 * This is the Reduce code - and perhaps I want to behave EXACTLY as it
 * indicates...
 *
 * symbolic procedure safe!-fp!-plus(x,y);
 *    if zerop x then y
 *     else if zerop y then x
 *     else if x>0.0 and y>0.0
 *      then if x<!!plumax and y<!!plumax then plus2(x,y) else nil
 *     else if x<0.0 and y<0.0
 *      then if -x<!!plumax and -y<!!plumax then plus2(x,y) else nil
 *     else if abs x<!!plumin and abs y<!!plumin then nil
 *     else (if u=0.0 then u else if abs u<!!fleps1*abs x then 0.0 else u)
 *          where u = plus2(x,y);
 */

static Lisp_Object Lsafe_fp_plus(Lisp_Object env, Lisp_Object x, Lisp_Object y)
{
    Lisp_Object nil = C_nil;
    double xx, yy, u;
    double fleps1 = 5.6843418860808e-14,
           plumax = 2.24711641857789e+307,
           plumin = 4.4501477170144e-296;
    Lisp_Object v;
// zerop x => y     zeropy => x
    if (!is_float(x) || !is_float(y)) return aerror2("safe-fp-plus", x, y);
    if ((xx = double_float_val(x)) == 0.0) return onevalue(y);
    if ((yy = double_float_val(y)) == 0.0) return onevalue(x);
    if (is_cons(env))
    {   if (is_symbol(v = qcar(env)) &&
            is_float(v = qvalue(v))) fleps1 = double_float_val(v);
        env = qcdr(env);
        if (is_cons(env))
        {   if (is_symbol(v = qcar(env)) &&
                is_float(v = qvalue(v))) plumax = double_float_val(v);
            if (is_symbol(v = qcdr(env)) &&
                is_float(v = qvalue(v))) plumin = double_float_val(v);
        }
    }
    if (xx > 0.0 && yy > 0.0)
    {   if (xx < plumax && yy < plumax)
        {   x = make_boxfloat(xx + yy, TYPE_DOUBLE_FLOAT);
            errexit();
            return onevalue(x);
        }
        else return onevalue(nil);
    }
    else if (xx < 0.0 && yy < 0.0)
    {   if (-xx < plumax && -yy < plumax)
        {   x = make_boxfloat(xx + yy, TYPE_DOUBLE_FLOAT);
            errexit();
            return onevalue(x);
        }
        else return onevalue(nil);

    }
    else if ((xx < 0.0 ? -xx : xx) < plumin &&
             (yy < 0.0 ? -yy : yy) < plumin) return onevalue(nil);
    u = xx + yy;
    if ((u < 0.0 ? -u : u) < fleps1*(xx < 0.0 ? -xx : xx)) u = 0.0;
    x = make_boxfloat(u, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(x);
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
 *
 * The new C code here is intended to match the above exactly!
 */

static Lisp_Object Lsafe_fp_times(Lisp_Object env,
                                  Lisp_Object x, Lisp_Object y)
{
    Lisp_Object nil = C_nil;
    double xx, yy, uu, vv;
    double timmax = 4.74037595405459e+153,
           timmin = 2.1095373229726e-154;
    Lisp_Object v;
    if (!is_float(x) || !is_float(y)) return aerror2("safe-fp-times", x, y);
    if ((xx = double_float_val(x)) == 0.0) return onevalue(x);
    if ((yy = double_float_val(y)) == 0.0) return onevalue(y);
    if (xx == 1.0) return onevalue(y);
    if (yy == 1.0) return onevalue(x);
    if (is_cons(env))
    {   if (is_symbol(v = qcar(env)) &&
            is_float(v = qvalue(v))) timmax = double_float_val(v);
        if (is_symbol(v = qcdr(env)) &&
            is_float(v = qvalue(v))) timmin = double_float_val(v);
    }
    uu = xx < 0.0 ? -xx : xx;
    vv = yy < 0.0 ? -yy : yy;
    if (uu >= 1.0 && uu <= timmax)
    {   if (vv <= timmax) goto ret;
        else return onevalue(nil);
    }
    if (uu > timmax)
    {   if (vv <= 1.0) goto ret;
        else return onevalue(nil);
    }
    if (uu < 1.0 && uu >= timmin)
    {   if (vv >= timmin) goto ret;
        else return onevalue(nil);
    }
    if (uu < timmin && vv < 1.0) return onevalue(nil);
ret:
    x = make_boxfloat(xx*yy, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(x);
}


/*
 *  symbolic procedure safe!-fp!-quot(x,y);
 *   if zerop y then rdqoterr()  % error(0, "zero divisor in quotient")
 *   else if zerop x then 0.0 else if y=1.0 then x else
 *     begin scalar u,v; u := abs x; v := abs y;
 *        if u>=1.0 and u<=!!timmax then
 *           if v>=!!timmin then go to ret else return nil;
 *        if u>!!timmax then if v>=1.0 then go to ret else return nil;
 *        if u<1.0 and u>=!!timmin then
 *           if v<=!!timmax then go to ret else return nil;
 *        if u<!!timmin and v>1.0 then return nil;
 *   ret: return quotient(x,y) end;
 *
 * New version intended to be exact match for above
 */

static Lisp_Object Lsafe_fp_quot(Lisp_Object env, Lisp_Object x, Lisp_Object y)
{
    Lisp_Object nil = C_nil;
    double xx, yy, uu, vv;
    double timmax = 4.74037595405459e+153,
           timmin = 2.1095373229726e-154;
    Lisp_Object v;
    if (!is_float(x) || !is_float(y)) return aerror2("safe-fp-quotient", x, y);
    if ((yy = double_float_val(y)) == 0.0)
        return aerror("zero divisor in quotient");
    if ((xx = double_float_val(x)) == 0.0) return onevalue(x);
    if (yy == 1.0) return onevalue(x);
    if (is_cons(env))
    {   if (is_symbol(v = qcar(env)) &&
            is_float(v = qvalue(v))) timmax = double_float_val(v);
        if (is_symbol(v = qcdr(env)) &&
            is_float(v = qvalue(v))) timmin = double_float_val(v);
    }
    uu = xx < 0.0 ? -xx : xx;
    vv = yy < 0.0 ? -yy : yy;
    if (uu>=1.0 && uu<=timmax)
    {   if (vv >= timmin) goto ret;
        else return onevalue(nil);
    }
    if (uu>timmax)
    {   if (vv >= 1.0) goto ret;
        else return onevalue(nil);
    }
    if (uu < 1.0 && uu >= timmin)
    {   if (vv <= timmax) goto ret;
        else return onevalue(nil);
    }
    if (uu < timmin && vv > 1.0) return nil;
ret:
    x = make_boxfloat(xx/yy, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(x);
}

#else /* Portable old code */

/*
 * Now some new code that is expected to manage to get closer to the
 * limit in exploiting the floating point hardware. Furthermore I hope
 * to bring PSL optimised versions and this code into exact agreement.
 */


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

#define BIAS   1023
/*
 * The MAX and MIN exponents indicated here are the limiting ones
 * for valid normalised numbers.
 */
#define MAXEXP 1023
#define MINEXP -1022

static Lisp_Object Lsafe_fp_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    double aa, bb, cc;
    int32_t ah, bh, ch, s;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-plus", a, b);
    if ((aa = double_float_val(a)) == 0.0) return onevalue(b);
    if ((bb = double_float_val(b)) == 0.0) return onevalue(a);
    top_half(ah, aa);
    top_half(bh, bb);
    s = (ah ^ bh) & 0x80000000;
    ah = ((ah >> 20) & 0x7ff) - BIAS;
    bh = ((bh >> 20) & 0x7ff) - BIAS;
/* I will reject infinities, NaNs and sub-normal numbers here. */
    if (ah == MAXEXP-1 || ah == MINEXP-1 ||
        bh == MAXEXP+1 || bh == MINEXP+1) return onevalue(nil);
/*
 * The sum of two numbers that have the same sign can overflow if either
 * has an exponent that is the maximum valid in a finite value. In
 * other cases I will always accept machine arithmetic.
 */
    if (s == 0)
    {   if (ah >= MAXEXP || bh >= MAXEXP) return onevalue(nil);
        a = make_boxfloat(aa+bb, TYPE_DOUBLE_FLOAT);
        errexit();
        return onevalue(a);
    }
/*
 * Sum might underflow into the range of subnormal numbers if the
 * two inputs have different signs and both are small
 */
    else if (ah <= MINEXP+52 && bh <= MINEXP+52) return onevalue(nil);
/*
 * Now I have two numbers whose signs differ and neither is utterly tiny.
 * The code in Reduce asks me to force the result to zero prematurely
 * based on a value !!fleps1. This is around 44 bits below the inputs...
 */
    cc = aa+bb;
    top_half(ch, cc);
    ch = ((ch >> 20) & 0x7ff) - BIAS;
    if (ch < ah-44) cc = 0.0;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lsafe_fp_times(Lisp_Object env, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-times", a, b);
    if ((aa = double_float_val(a)) == 0.0) return onevalue(a);
    if ((bb = double_float_val(b)) == 0.0) return onevalue(b);
    if (aa == 1.0) return onevalue(b);
    if (bb == 1.0) return onevalue(a);
    top_half(ah, aa);
    top_half(bh, bb);
    ah = ((ah >> 20) & 0x7ff) - BIAS;
    bh = ((bh >> 20) & 0x7ff) - BIAS;
/* I will reject infinities, NaNs and sub-normal numbers here. */
    if (ah == MAXEXP+1 || ah == MINEXP-1 ||
        bh == MAXEXP+1 || bh == MINEXP-1) return onevalue(nil);
    ah = ah + bh;
/*
 * When multiplying, the exponent of the result can be one higher than
 * the sum of the exponents of the operands, so to be certain that
 * I will not get overflow I stop one early here.
 */
    if (ah <= MINEXP+1 || ah >= MAXEXP-1) return onevalue(nil);
    cc = aa * bb;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

static Lisp_Object Lsafe_fp_quot(Lisp_Object env, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    double aa, bb, cc;
    int32_t ah, bh;
    if (!is_float(a) || !is_float(b)) return aerror2("safe-fp-quot", a, b);
    if ((aa = double_float_val(a)) == 0.0) return onevalue(a);
    if ((bb = double_float_val(b)) == 0.0)
        return aerror("divisor is zero in quotient");
    if (bb == 1.0) return onevalue(a);
    top_half(ah, aa);
    top_half(bh, bb);
    ah = ((ah >> 20) & 0x7ff) - BIAS;
    bh = ((bh >> 20) & 0x7ff) - BIAS;
    if (ah == MAXEXP+1 || ah == MINEXP-1 ||
        bh == MAXEXP+1 || bh == MINEXP-1) return onevalue(nil);
    ah = ah - bh;
    if (ah <= MINEXP+1 || ah >= MAXEXP-1) return onevalue(nil);
    cc = aa / bb;
    a = make_boxfloat(cc, TYPE_DOUBLE_FLOAT);
    errexit();
    return onevalue(a);
}

#endif /* Portable old code */



setup_type const arith08_setup[] =
{
/*
 * The next few are JUST for REDUCE, but they are expected to speed up
 * rounded-mode arithmetic rather a lot. I want them to match the behaviour
 * or corresponding specialist code for PSL...
 */
    {"safe-fp-plus",            too_few_2, Lsafe_fp_plus, wrong_no_2},
    {"safe-fp-times",           too_few_2, Lsafe_fp_times, wrong_no_2},
    {"safe-fp-quot",            too_few_2, Lsafe_fp_quot, wrong_no_2},
/* End of REDUCE specialities */
    {"ceiling",                 Lceiling, Lceiling_2, wrong_no_1},
    {"floor",                   Lfloor, Lfloor_2, wrong_no_1},
    {"round",                   Lround, Lround_2, wrong_no_1},
    {"truncate",                Ltruncate, Ltruncate_2, wrong_no_1},
    {"decode-float",            Ldecode_float, too_many_1, wrong_no_1},
    {"float-denormalized-p",    Lfloat_denormalized_p, too_many_1, wrong_no_1},
    {"float-infinity-p",        Lfloat_infinity_p, too_many_1, wrong_no_1},
    {"integer-decode-float",    Linteger_decode_float, too_many_1, wrong_no_1},
    {"integer-length",          Linteger_length, too_many_1, wrong_no_1},
    {"float-digits",            Lfloat_digits, too_many_1, wrong_no_1},
    {"float-precision",         Lfloat_precision, too_many_1, wrong_no_1},
    {"float-radix",             Lfloat_radix, too_many_1, wrong_no_1},
    {"float-sign",              Lfloat_sign1, Lfloat_sign2, wrong_no_2},
    {"fround",                  too_few_2, Lfround, wrong_no_2},
    {"ftruncate",               too_few_2, Lftruncate, wrong_no_2},
    {"logbitp",                 too_few_2, Llogbitp, wrong_no_2},
    {"logcount",                Llogcount, too_many_1, wrong_no_1},
    {"logtest",                 too_few_2, Llogtest, wrong_no_2},
    {"mask-field",              too_few_2, Lmask_field, wrong_no_2},
    {"scale-float",             too_few_2, Lscale_float, wrong_no_2},
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
    {"gcd",                     Lgcd_1, Lgcd, Lgcd_n},
    {"imagpart",                Limagpart, too_many_1, wrong_no_1},
    {"ldb",                     too_few_2, Lldb, wrong_no_2},
    {"ldb-test",                too_few_2, Lldb_test, wrong_no_2},
    {"lcm",                     Llcm_1, Llcm, Llcm_n},
    {"numerator",               Lnumerator, too_many_1, wrong_no_1},
    {"realpart",                Lrealpart, too_many_1, wrong_no_1},
#else
    {"fix",                     Ltruncate, too_many_1, wrong_no_1},
    {"gcdn",                    too_few_2, Lgcd, wrong_no_2},
    {"lcmn",                    too_few_2, Llcm, wrong_no_2},
#endif
    {NULL,                      0,0,0}
};

/* end of arith08.c */

