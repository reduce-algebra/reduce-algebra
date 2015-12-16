//  arith12.cpp                       Copyright (C) 1990-2015 Codemist Ltd

//
// Arithmetic functions... specials for Reduce (esp. factoriser)
//
//


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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


#define FP_EVALUATE   1


LispObject Lfrexp(LispObject nil, LispObject a)
{   double d;
    int x;
    d = float_of_number(a);
    d = frexp(d, &x);
    if (d == 1.0) d = 0.5, x++;
    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
    errexit();
    return Lcons(nil, fixnum_of_int((int32_t)x), a);
}

LispObject Lmodular_difference(LispObject nil, LispObject a, LispObject b)
{   int32_t r;
    if (!modulus_is_large)
    {   r = int_of_fixnum(a) - int_of_fixnum(b);
        if (r < 0) r += current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    a = difference2(a, b);
    errexit();
    return modulus(a, large_modulus);
}

LispObject Lmodular_minus(LispObject nil, LispObject a)
{   if (!modulus_is_large)
    {   if (a != fixnum_of_int(0))
        {   int32_t r = current_modulus - int_of_fixnum(a);
            a = fixnum_of_int(r);
        }
        return onevalue(a);
    }
    a = negate(a);
    errexit();
    return modulus(a, large_modulus);
}

LispObject Lmodular_number(LispObject nil, LispObject a)
{   int32_t r;
    if (!modulus_is_large)
    {   a = Cremainder(a, fixnum_of_int(current_modulus));
        errexit();
        r = int_of_fixnum(a);
        if (r < 0) r += current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    return modulus(a, large_modulus);
}

LispObject Lmodular_plus(LispObject nil, LispObject a, LispObject b)
{   int32_t r;
    if (!modulus_is_large)
    {   r = int_of_fixnum(a) + int_of_fixnum(b);
        if (r >= current_modulus) r -= current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    a = plus2(a, b);
    errexit();
    return modulus(a, large_modulus);
}

LispObject large_modular_reciprocal(LispObject n, int safe)
{   LispObject a, b, x, y, nil = C_nil;
    a = large_modulus;
    b = n;
    x = fixnum_of_int(0);
    y = fixnum_of_int(1);
    if (b == fixnum_of_int(0))
    {   if (safe) return onevalue(nil);
        else return aerror1("modular-reciprocal", n);
    }
//
// This code is not garbage-collector safe and also needs loads or errexit()
// escapes in case it is interrupted part way through. But even in this
// state it can be subjected to some initial testing.
//
    b = modulus(b, large_modulus);
    errexit();
    while (b != fixnum_of_int(1))
    {   LispObject w, t;
        if (b == fixnum_of_int(0))
        {   if (safe) return onevalue(nil);
            else return aerror2("non-prime modulus in modular-reciprocal",
                                    large_modulus, n);
        }
        w = quot2(a, b);
        t = b;
        b = difference2(a, times2(b, w));
        a = t;
        t = y;
        y = difference2(x, times2(y, w));
        x = t;
    }
    y = modulus(y, large_modulus);
    return onevalue(y);
}

LispObject Lmodular_reciprocal(LispObject, LispObject n)
{   int32_t a, b, x, y;
    if (modulus_is_large) return large_modular_reciprocal(n, 0);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return aerror1("modular-reciprocal", n);
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   int32_t w, t;
        if (b == 0)
            return aerror2("non-prime modulus in modular-reciprocal",
                           fixnum_of_int(current_modulus), n);
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += current_modulus;
    return onevalue(fixnum_of_int(y));
}

LispObject Lsafe_modular_reciprocal(LispObject nil, LispObject n)
{   int32_t a, b, x, y;
    if (modulus_is_large) return large_modular_reciprocal(n, 1);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return onevalue(nil);
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   int32_t w, t;
        if (b == 0) return onevalue(nil);
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += current_modulus;
    return onevalue(fixnum_of_int(y));
}

LispObject Lmodular_times(LispObject nil, LispObject a, LispObject b)
{
#ifndef HAVE_UINT64_T
    uint32_t h, l;
#endif
    uint32_t r, cm;
    int32_t aa, bb;
    if (!modulus_is_large)
    {   cm = (uint32_t)current_modulus;
        aa = int_of_fixnum(a);
        bb = int_of_fixnum(b);
//
// The constant 46341 is sqrt(2^31) suitable rounded - if my modulus
// is no bigger than that then a and b will both be strictly smaller,
// and hence a*b will be < 2^31 and hence in range for 32-bit signed
// arithmetic.  I make this test because I expect Imultiply and Idivide
// to be pretty painful, while regular C multiplication and division are
// (probably!) much better.
//
        if (cm <= 46341U) r = (aa * bb) % cm;
        else
        {
#ifdef HAVE_UINT64_T
            r = (uint32_t)(((uint64_t)aa * (uint64_t)bb) % (uint32_t)cm);
#else
            Dmultiply(h, l, aa, bb, 0);
            Ddivide(r, l, h, l, cm);
#endif
        }
        return onevalue(fixnum_of_int(r));
    }
    a = times2(a, b);
    errexit();
    return modulus(a, large_modulus);
}

LispObject Lmodular_quotient(LispObject nil, LispObject a, LispObject b)
{   push(a);
    b = Lmodular_reciprocal(nil, b);
    pop(a);
    errexit();
    return Lmodular_times(nil, a, b);
}

LispObject large_modular_expt(LispObject a, int x)
{   LispObject r, p, w, nil = C_nil;
    p = modulus(a, large_modulus);
    errexit();
//
// This is not yet GC safe.
//
    while ((x & 1) == 0)
    {   w = times2(p, p);
        errexit();
        p = modulus(p, large_modulus);
        errexit();
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   w = times2(p, p);
        p = modulus(w, large_modulus);
        x = x/2;
        if ((x & 1) != 0)
        {   w = times2(r, p);
            r = modulus(w, large_modulus);
        }
    }
    return onevalue(r);
}

LispObject Lmodular_expt(LispObject, LispObject a, LispObject b)
{   int32_t x, r, p;
    uint32_t h, l;
    x = int_of_fixnum(b);
    if (x == 0) return onevalue(fixnum_of_int(1));
    if (modulus_is_large) return large_modular_expt(a, x);
    p = int_of_fixnum(a);
//
// I could play games here on half-length current_modulus and use
// native C arithmetic, but I judge this case not to be quite that
// critically important. Also on 64-bit machines I could do more
// work in-line.
//
    p = p % current_modulus; // In case somebody is being silly!
    while ((x & 1) == 0)
    {   Dmultiply(h, l, p, p, 0);
        Ddivide(p, l, h, l, current_modulus);
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   Dmultiply(h, l, p, p, 0);
        Ddivide(p, l, h, l, current_modulus);
        x = x/2;
        if ((x & 1) != 0)
        {   Dmultiply(h, l, r, p, 0);
            Ddivide(r, l, h, l, current_modulus);
        }
    }
    return onevalue(fixnum_of_int(r));
}

LispObject Lset_small_modulus(LispObject nil, LispObject a)
{   int32_t r;
    LispObject old = modulus_is_large ? large_modulus :
                     fixnum_of_int(current_modulus);
    if (a==nil) return onevalue(old);
    else if (!is_fixnum(a))
    {   if (!is_numbers(a) || !is_bignum(a))
            return aerror1("set-small-modulus", a);
        modulus_is_large = 1;
        large_modulus = a;
        return old;
    }
    r = int_of_fixnum(a);
//
// I now allow a small modulus of up to 2^27. One I stopped at 2^24
// for compatibility with Cambridge Lisp, but that is now so long in the
// past that worrying about it seems unnecessary.
//
    if (r > 0x07ffffff)
    {   // return aerror1("set-small-modulus", a);
        modulus_is_large = 1;
        large_modulus = a;
        return old;
    }
    modulus_is_large = 0;
    current_modulus = r;
    return onevalue(old);
}

LispObject Liadd1(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("iadd1", a);
    return onevalue((LispObject)((int32_t)a + 0x10));
}

LispObject Lidifference(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("idifference", a, b);
    return onevalue((LispObject)((int32_t)a - (int32_t)b + TAG_FIXNUM));
}

//
// xdifference is provided just for the support of the CASE operator. It
// subtracts its arguments but returns NIL if either argument is not
// an small integer or if the result overflows.
//

LispObject Lxdifference(LispObject nil, LispObject a, LispObject b)
{   int32_t r;
    if (!is_fixnum(a) || !is_fixnum(b)) return onevalue(nil);
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < -0x08000000 || r > 0x07ffffff) return onevalue(nil);
    return onevalue(fixnum_of_int(r));
}

LispObject Ligreaterp(LispObject nil, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igreaterp", a, b);
    return onevalue(Lispify_predicate(a > b));
}

LispObject Lilessp(LispObject nil, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilessp", a, b);
    return onevalue(Lispify_predicate(a < b));
}

LispObject Ligeq(LispObject nil, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igeq", a, b);
    return onevalue(Lispify_predicate(a >= b));
}

LispObject Lileq(LispObject nil, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ileq", a, b);
    return onevalue(Lispify_predicate(a <= b));
}

static LispObject Lilogand(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(-1));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogand");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) return aerror1("ilogand", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogand", w);
        }
        r = (LispObject)((int32_t)r & (int32_t)w);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogor(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogor");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) return aerror1("ilogor", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogor", w);
        }
        r = (LispObject)((int32_t)r | (int32_t)w);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogxor(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogxor");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) return aerror1("ilogxor", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogxor", w);
        }
        r = (LispObject)(((int32_t)r ^ (int32_t)w) + TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogand2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogand", a, b);
    return onevalue(a & b);
}

static LispObject Lilogor2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogor", a, b);
    return onevalue(a | b);
}

static LispObject Lilogxor2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogxor", a, b);
    return onevalue((a ^ b) + TAG_FIXNUM);
}

LispObject Limin(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imin", a, b);
    return onevalue(a < b ? a : b);
}

LispObject Limax(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imax", a, b);
    return onevalue(a > b ? a : b);
}

LispObject Liminus(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("iminus", a);
    return onevalue((LispObject)(2*TAG_FIXNUM - (int32_t)a));
}

LispObject Liminusp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate((int32_t)a < (int32_t)fixnum_of_int(0)));
}

static LispObject Liplus(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for iplus");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) return aerror1("iplus", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("iplus", w);
        }
        r = (LispObject)((int32_t)r + (int32_t)w - TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

LispObject Liplus2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("iplus2", a, b);
    return onevalue((LispObject)((int32_t)a + (int32_t)b - TAG_FIXNUM));
}

LispObject Liquotient(LispObject, LispObject a, LispObject b)
{   int32_t aa, bb, c;
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) return aerror2("iquotient", a, b);
// C does not define the exact behaviour of /, % on -ve args
    aa = int_of_fixnum(a);
    bb = int_of_fixnum(b);
    c = aa % bb;
    if (aa < 0)
    {   if (c > 0) c -= bb;
    }
    else if (c < 0) c += bb;
    return onevalue(fixnum_of_int((aa-c)/bb));
}

LispObject Liremainder(LispObject, LispObject a, LispObject b)
{   int32_t aa, bb, c;
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) return aerror2("iremainder", a, b);
// C does not define the exact behaviour of /, % on -ve args
    aa = int_of_fixnum(a);
    bb = int_of_fixnum(b);
    c = aa % bb;
    if (aa < 0)
    {   if (c > 0) c -= bb;
    }
    else if (c < 0) c += bb;
    return onevalue(fixnum_of_int(c));
}

LispObject Lirightshift(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("irightshift", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) >> int_of_fixnum(b)));
}

LispObject Lisub1(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("isub1", a);
    return onevalue((LispObject)((int32_t)a - 0x10));
}

static LispObject Litimes(LispObject, int nargs, ...)
{   va_list a;
    LispObject rr;
    int32_t r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for itimes");
    va_start(a, nargs);
    rr = va_arg(a, LispObject);
    if (!is_fixnum(rr)) return aerror1("itimes", rr);
    r = int_of_fixnum(rr);
    while (nargs-- != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("itimes", w);
        }
        r = r * int_of_fixnum(w);
    }
    va_end(a);
    return onevalue(fixnum_of_int(r));
}

LispObject Litimes2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("itimes2", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) * int_of_fixnum(b)));
}

LispObject Lionep(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate((int32_t)a == (int32_t)fixnum_of_int(1)));
}

LispObject Lizerop(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate((int32_t)a == (int32_t)fixnum_of_int(0)));
}

#ifdef FP_EVALUATE

static double fp_args[32];
static double fp_stack[16];

// codes 0 to 31 just load up arguments
#define FP_RETURN        32
#define FP_PLUS          33
#define FP_DIFFERENCE    34
#define FP_TIMES         35
#define FP_QUOTIENT      36
#define FP_MINUS         37
#define FP_SQUARE        38
#define FP_CUBE          39
#define FP_SIN           40
#define FP_COS           41
#define FP_TAN           42
#define FP_EXP           43
#define FP_LOG           44
#define FP_SQRT          45


static LispObject Lfp_eval(LispObject nil, LispObject code,
                           LispObject args)
//
// The object of this code is to support fast evaluation of numeric
// expressions.  The first argument is a vector of byte opcodes, while
// the second arg is a list of floating point values whose value will (or
// at least may) be used.  There are at most 32 values in this list.
//
{   int n = 0;
    double w;
    unsigned char *p;
    if (!is_vector(code)) return aerror("fp-evaluate");
    while (consp(args))
    {   fp_args[n++] = float_of_number(qcar(args));
        args = qcdr(args);
    }
    n = 0;
    p = &ucelt(code, 0);
    for (;;)
    {   int op = *p++;
//
// Opcodes 0 to 31 just load up the corresponding input value.
//
        if (op < 32)
        {   fp_stack[n++] = fp_args[op];
            continue;
        }
        switch (op)
    {       default:
                return aerror("Bad op in fp-evaluate");
            case FP_RETURN:
                args = make_boxfloat(fp_stack[0], TYPE_DOUBLE_FLOAT);
                errexit();
                return onevalue(args);
            case FP_PLUS:
                n--;
                fp_stack[n] += fp_stack[n-1];
                continue;
            case FP_DIFFERENCE:
                n--;
                fp_stack[n] -= fp_stack[n-1];
                continue;
            case FP_TIMES:
                n--;
                fp_stack[n] *= fp_stack[n-1];
                continue;
            case FP_QUOTIENT:
                n--;
                fp_stack[n] /= fp_stack[n-1];
                continue;
            case FP_MINUS:
                fp_stack[n] = -fp_stack[n];
                continue;
            case FP_SQUARE:
                fp_stack[n] *= fp_stack[n];
                continue;
            case FP_CUBE:
                w = fp_stack[n];
                w *= w;
                fp_stack[n] *= w;
                continue;
            case FP_SIN:
                fp_stack[n] = sin(fp_stack[n]);
                continue;
            case FP_COS:
                fp_stack[n] = cos(fp_stack[n]);
                continue;
            case FP_TAN:
                fp_stack[n] = tan(fp_stack[n]);
                continue;
            case FP_EXP:
                fp_stack[n] = exp(fp_stack[n]);
                continue;
            case FP_LOG:
                fp_stack[n] = log(fp_stack[n]);
                continue;
            case FP_SQRT:
                fp_stack[n] = sqrt(fp_stack[n]);
                continue;
        }
    }
}

#endif

setup_type const arith12_setup[] =
{   {"frexp",                   Lfrexp, too_many_1, wrong_no_1},
    {"modular-difference",      too_few_2, Lmodular_difference, wrong_no_2},
    {"modular-minus",           Lmodular_minus, too_many_1, wrong_no_1},
    {"modular-number",          Lmodular_number, too_many_1, wrong_no_1},
    {"modular-plus",            too_few_2, Lmodular_plus, wrong_no_2},
    {"modular-quotient",        too_few_2, Lmodular_quotient, wrong_no_2},
    {"modular-reciprocal",      Lmodular_reciprocal, too_many_1, wrong_no_1},
    {"safe-modular-reciprocal", Lsafe_modular_reciprocal, too_many_1, wrong_no_1},
    {"modular-times",           too_few_2, Lmodular_times, wrong_no_2},
    {"modular-expt",            too_few_2, Lmodular_expt, wrong_no_2},
    {"set-small-modulus",       Lset_small_modulus, too_many_1, wrong_no_1},
    {"iadd1",                   Liadd1, too_many_1, wrong_no_1},
    {"idifference",             too_few_2, Lidifference, wrong_no_2},
    {"xdifference",             too_few_2, Lxdifference, wrong_no_2},
    {"igeq",                    too_few_2, Ligeq, wrong_no_2},
    {"igreaterp",               too_few_2, Ligreaterp, wrong_no_2},
    {"ileq",                    too_few_2, Lileq, wrong_no_2},
    {"ilessp",                  too_few_2, Lilessp, wrong_no_2},
    {"ilogand",                 Lidentity, Lilogand2, Lilogand},
    {"ilogor",                  Lidentity, Lilogor2, Lilogor},
    {"ilogxor",                 Lidentity, Lilogxor2, Lilogxor},
    {"imax",                    too_few_2, Limax, wrong_no_2},
    {"imin",                    too_few_2, Limin, wrong_no_2},
    {"iminus",                  Liminus, too_many_1, wrong_no_1},
    {"iminusp",                 Liminusp, too_many_1, wrong_no_1},
    {"iplus",                   Lidentity, Liplus2, Liplus},
    {"iplus2",                  too_few_2, Liplus2, wrong_no_2},
    {"iquotient",               too_few_2, Liquotient, wrong_no_2},
    {"iremainder",              too_few_2, Liremainder, wrong_no_2},
    {"irightshift",             too_few_2, Lirightshift, wrong_no_2},
    {"isub1",                   Lisub1, too_many_1, wrong_no_1},
    {"itimes",                  Lidentity, Litimes2, Litimes},
    {"itimes2",                 too_few_2, Litimes2, wrong_no_2},
    {"ionep",                   Lionep, too_many_1, wrong_no_1},
    {"izerop",                  Lizerop, too_many_1, wrong_no_1},
#ifdef FP_EVALUATE
    {"fp-evaluate",             too_few_2, Lfp_eval, wrong_no_2},
#endif
    {NULL,                      0, 0, 0}
};

// end of arith12.cpp
