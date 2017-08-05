//  arith12.cpp                            Copyright (C) 1990-2017 Codemist    

//
// Arithmetic functions... specials for Reduce (esp. factoriser)
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


#define FP_EVALUATE   1


LispObject Lfrexp(LispObject env, LispObject a)
{   double d;
    int x;
    d = float_of_number(a);
    d = frexp(d, &x);
    if (d == 1.0) d = 0.5, x++;
    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
    return Lcons(nil, fixnum_of_int((int32_t)x), a);
}

// N.B. that the moduklar arithmetic functions must cope with any small
// modulus that could fit in a fixnum.

LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b)
{   intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) aerror1("modular-difference", a);
        if (!is_fixnum(b)) aerror1("modular-difference", b);
        r = int_of_fixnum(a) - int_of_fixnum(b);
        if (r < 0) r += current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    a = difference2(a, b);
    return modulus(a, large_modulus);
}

LispObject Lmodular_minus(LispObject env, LispObject a)
{   if (!modulus_is_large)
    {   if (!is_fixnum(a)) aerror1("modular-minus", a);
        if (a != fixnum_of_int(0))
        {   intptr_t r = current_modulus - int_of_fixnum(a);
            a = fixnum_of_int(r);
        }
        return onevalue(a);
    }
    a = negate(a);
    return modulus(a, large_modulus);
}

LispObject Lmodular_number(LispObject env, LispObject a)
{   intptr_t r;
    if (!modulus_is_large)
    {   a = Cremainder(a, fixnum_of_int(current_modulus));
        r = int_of_fixnum(a);
        if (r < 0) r += current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    return modulus(a, large_modulus);
}

LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b)
{   intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) aerror1("modular-plus", a);
        if (!is_fixnum(b)) aerror1("modular-plus", b);
        r = int_of_fixnum(a) + int_of_fixnum(b);
        if (r >= current_modulus) r -= current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    a = plus2(a, b);
    return modulus(a, large_modulus);
}

LispObject large_modular_reciprocal(LispObject n, bool safe)
{   LispObject a, b, x, y;
    b = n;
    x = fixnum_of_int(0);
    y = fixnum_of_int(1);
    if (b == fixnum_of_int(0))
    {   if (safe) return onevalue(nil);
        else aerror1("modular-reciprocal", n);
    }
    b = modulus(b, large_modulus);
    a = large_modulus;
    while (b != fixnum_of_int(1))
    {   LispObject w, t;
        if (b == fixnum_of_int(0))
        {   if (safe) return onevalue(nil);
            else aerror2("non-prime modulus in modular-reciprocal",
                                    large_modulus, n);
        }
        push2(x, y);
        w = quot2(a, b);
        pop2(y, x);
        t = b;
        push5(a, x, y, w, t);
        b = times2(b, w);
        pop5(t, w, y, x, a);
        push4(x, y, w, t);
        b = difference2(a, b);
        pop4(t, w, y, x);
        a = t;
        t = y;
        push4(a, b, x, t);
        y = times2(y, w);
        pop4(t, x, b, a);
        push3(a, b, t);
        y = difference2(x, y);
        pop3(t, b, a);
        x = t;
    }
    y = modulus(y, large_modulus);
    return onevalue(y);
}

LispObject Lmodular_reciprocal(LispObject, LispObject n)
{   intptr_t a, b, x, y;
    if (modulus_is_large) return large_modular_reciprocal(n, false);
// If the modulus is "small" I can do all this using native integer
// arithmetic.
    if (!is_fixnum(n)) aerror1("modular-reciprocal", n);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) aerror1("modular-reciprocal", n);
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   intptr_t w, t;
        if (b == 0)
            aerror2("non-prime modulus in modular-reciprocal",
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

LispObject Lsafe_modular_reciprocal(LispObject env, LispObject n)
{   intptr_t a, b, x, y;
    if (modulus_is_large) return large_modular_reciprocal(n, true);
    if (!is_fixnum(n)) aerror1("modular-reciprocal", n);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return onevalue(nil);
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   intptr_t w, t;
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

LispObject Lmodular_times(LispObject env, LispObject a, LispObject b)
{
    uintptr_t cm;
    intptr_t aa, bb;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) aerror1("modular-times", a);
        if (!is_fixnum(b)) aerror1("modular-times", b);
        cm = (uintptr_t)current_modulus;
        aa = int_of_fixnum(a);
        bb = int_of_fixnum(b);
// If I am on a 32-bit machine and the modulus is at worst 16 bits I can use
// 32-bit arithmetic to complete the job.
        if (!SIXTY_FOUR_BIT && cm <= 0xffffU)
        {   uint32_t r = ((uint32_t)aa * (uint32_t)bb) % (uint32_t)cm;
            return onevalue(fixnum_of_int((intptr_t)r));
        }
// On a 32 or 64-bit machine if the modulus is at worst 32 bits I can do
// a 64-bit (unsigned) multiplication and remainder step.
        else if (cm <= 0xffffffffU)
        {   uint64_t r = ((uint64_t)aa*(uint64_t)bb) % (uint64_t)cm;
// Because I am in a state where modulus_is_large is not set I know that the
// modulus fits in a fixnum, hence the result will. So even though all value
// that are of type uint64_t might not be valid as fixnums the one I have
// here will be.
            return onevalue(fixnum_of_int((intptr_t)r));
        }
// Now my modulus is over 32-bits...
// Using an int128_t bit type I can use it and the code is really neat!
// On some platforms this goes via C++ templates and operator overloading
// into a software implementation of 128-bit integer arithmetic!
        else
        {   int64_t r = NARROW128(((int128_t)aa*(int128_t)bb) % (int128_t)cm);
            return onevalue(fixnum_of_int((intptr_t)r));
        }
    }
    a = times2(a, b);
    return modulus(a, large_modulus);
}

LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b)
{   push(a);
    b = Lmodular_reciprocal(nil, b);
    pop(a);
    return Lmodular_times(nil, a, b);
}

LispObject large_modular_expt(LispObject a, int x)
{   LispObject r, p, w;
    p = modulus(a, large_modulus);
    while ((x & 1) == 0)
    {   p = times2(p, p);
        p = modulus(p, large_modulus);
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   push(r);
        w = times2(p, p);
        pop(r);
        push(r);
        p = modulus(w, large_modulus);
        pop(r);
        x = x/2;
        if ((x & 1) != 0)
        {   push(p);
            w = times2(r, p);
            pop(p);
            push(p);
            r = modulus(w, large_modulus);
            pop(p);
        }
    }
    return onevalue(r);
}

static inline intptr_t muldivptr(uintptr_t a, uintptr_t b, uintptr_t c)
{   if (!SIXTY_FOUR_BIT || c <= 0xffffffffU)
        return ((uint64_t)a*(uint64_t)b)%(uintptr_t)c;
    else return (intptr_t)NARROW128(((uint128_t)a*(uint128_t)a)%(uintptr_t)c);
}

LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b)
{   intptr_t x, r, p;
    x = int_of_fixnum(b);
    if (x == 0) return onevalue(fixnum_of_int(1));
    if (modulus_is_large) return large_modular_expt(a, x);
    p = int_of_fixnum(a);
    p = p % current_modulus; // In case somebody is being silly!
// I now want this to work for any modulus up to the size of the largest
// fixnum. That could be 60-bits in the newer world. The function
// muldivptr takes unsigned arguments but that should be OK because any
// valid modulus and any valid modular number will be positive.
    while ((x & 1) == 0)
    {   p = muldivptr((uintptr_t)p, (uintptr_t)p, (uintptr_t)current_modulus);
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   p = muldivptr((uintptr_t)p, (uintptr_t)p, (uintptr_t)current_modulus);
        x = x/2;
        if ((x & 1) != 0)
        {   r = muldivptr((uintptr_t)r, (uintptr_t)p, (uintptr_t)current_modulus);
        }
    }
    return onevalue(fixnum_of_int(r));
}

// I can set any (positive) integer as a modulus here. I will treat it
// internally as "small" if it fits in a fixnum.

LispObject Lset_small_modulus(LispObject env, LispObject a)
{   LispObject old = modulus_is_large ? large_modulus :
                     fixnum_of_int(current_modulus);
    if (a==nil) return onevalue(old);
    else if (!is_fixnum(a))
    {   if (!is_numbers(a) ||
            !is_bignum(a) ||
            minusp(a))
            aerror1("set-small-modulus", a);
        modulus_is_large = 1;
        current_modulus = 0;   // should not be referenced.
        large_modulus = a;
        return old;
    }
    if ((intptr_t)a < 0 || a == fixnum_of_int(0))
        aerror1("set!-small!-modulus", a);
    modulus_is_large = 0;
    large_modulus = nil; // Should not be referenced.
    current_modulus = int_of_fixnum(a);;
    return onevalue(old);
}

LispObject Liadd1(LispObject, LispObject a)
{   if (!is_fixnum(a)) aerror1("iadd1", a);
    return onevalue((LispObject)((intptr_t)a + 0x10));
}

LispObject Lidifference(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("idifference", a, b);
    return onevalue((LispObject)((intptr_t)a - (intptr_t)b + TAG_FIXNUM));
}

//
// xdifference is provided just for the support of the CASE operator. It
// subtracts its arguments but returns NIL if either argument is not
// an small integer or if the result overflows. Small is 28-bits in this
// context at present, which is maybe strange!
//

LispObject Lxdifference(LispObject env, LispObject a, LispObject b)
{   int32_t r;
    if (!is_fixnum(a) || !is_fixnum(b)) return onevalue(nil);
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < -0x08000000 || r > 0x07ffffff) return onevalue(nil);
    return onevalue(fixnum_of_int(r));
}

LispObject Ligreaterp(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("igreaterp", a, b);
    return onevalue(Lispify_predicate(a > b));
}

LispObject Lilessp(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("ilessp", a, b);
    return onevalue(Lispify_predicate(a < b));
}

LispObject Ligeq(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("igeq", a, b);
    return onevalue(Lispify_predicate(a >= b));
}

LispObject Lileq(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("ileq", a, b);
    return onevalue(Lispify_predicate(a <= b));
}

static LispObject Lilogand(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(-1));
    if (nargs > ARG_CUT_OFF) aerror("too many args for ilogand");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) aerror1("ilogand", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            aerror1("ilogand", w);
        }
        r = (LispObject)((intptr_t)r & (intptr_t)w);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogor(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) aerror("too many args for ilogor");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) aerror1("ilogor", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            aerror1("ilogor", w);
        }
        r = (LispObject)((intptr_t)r | (intptr_t)w);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogxor(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) aerror("too many args for ilogxor");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) aerror1("ilogxor", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            aerror1("ilogxor", w);
        }
        r = (LispObject)(((intptr_t)r ^ (intptr_t)w) + TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

static LispObject Lilogand2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("ilogand", a, b);
    return onevalue(a & b);
}

static LispObject Lilogor2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("ilogor", a, b);
    return onevalue(a | b);
}

static LispObject Lilogxor2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("ilogxor", a, b);
    return onevalue((a ^ b) + TAG_FIXNUM);
}

LispObject Limin(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("imin", a, b);
    return onevalue(a < b ? a : b);
}

LispObject Limax(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("imax", a, b);
    return onevalue(a > b ? a : b);
}

LispObject Liminus(LispObject, LispObject a)
{   if (!is_fixnum(a)) aerror1("iminus", a);
    return onevalue((LispObject)(2*TAG_FIXNUM - (intptr_t)a));
}

LispObject Liminusp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a < (intptr_t)fixnum_of_int(0)));
}

static LispObject Liplus(LispObject, int nargs, ...)
{   va_list a;
    LispObject r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) aerror("too many args for iplus");
    va_start(a, nargs);
    r = va_arg(a, LispObject);
    if (!is_fixnum(r)) aerror1("iplus", r);
    while (--nargs != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            aerror1("iplus", w);
        }
        r = (LispObject)((intptr_t)r + (intptr_t)w - TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

LispObject Liplus2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("iplus2", a, b);
    return onevalue((LispObject)((intptr_t)a + (intptr_t)b - TAG_FIXNUM));
}

LispObject Liquotient(LispObject, LispObject a, LispObject b)
{   intptr_t aa, bb, c;
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) aerror2("iquotient", a, b);
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
{   intptr_t aa, bb, c;
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) aerror2("iremainder", a, b);
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
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("irightshift", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) >> int_of_fixnum(b)));
}

LispObject Lisub1(LispObject, LispObject a)
{   if (!is_fixnum(a)) aerror1("isub1", a);
    return onevalue((LispObject)((intptr_t)a - 0x10));
}

static LispObject Litimes(LispObject, int nargs, ...)
{   va_list a;
    LispObject rr;
    intptr_t r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    if (nargs > ARG_CUT_OFF) aerror("too many args for itimes");
    va_start(a, nargs);
    rr = va_arg(a, LispObject);
    if (!is_fixnum(rr)) aerror1("itimes", rr);
    r = int_of_fixnum(rr);
    while (nargs-- != 0)
    {   LispObject w = va_arg(a, LispObject);
        if (!is_fixnum(w))
        {   va_end(a);
            aerror1("itimes", w);
        }
        r = r * int_of_fixnum(w);
    }
    va_end(a);
    return onevalue(fixnum_of_int(r));
}

LispObject Litimes2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) aerror2("itimes2", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) * int_of_fixnum(b)));
}

LispObject Lionep(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a == (intptr_t)fixnum_of_int(1)));
}

LispObject Lizerop(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a == (intptr_t)fixnum_of_int(0)));
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


static LispObject Lfp_eval(LispObject env, LispObject code,
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
    if (!is_vector(code)) aerror("fp-evaluate");
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
                aerror("Bad op in fp-evaluate");
            case FP_RETURN:
                args = make_boxfloat(fp_stack[0], TYPE_DOUBLE_FLOAT);
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
{   {"frexp",                   Lfrexp, TOO_MANY_1, WRONG_NO_1},
    {"modular-difference",      TOO_FEW_2, Lmodular_difference, WRONG_NO_2},
    {"modular-minus",           Lmodular_minus, TOO_MANY_1, WRONG_NO_1},
    {"modular-number",          Lmodular_number, TOO_MANY_1, WRONG_NO_1},
    {"modular-plus",            TOO_FEW_2, Lmodular_plus, WRONG_NO_2},
    {"modular-quotient",        TOO_FEW_2, Lmodular_quotient, WRONG_NO_2},
    {"modular-reciprocal",      Lmodular_reciprocal, TOO_MANY_1, WRONG_NO_1},
    {"safe-modular-reciprocal", Lsafe_modular_reciprocal, TOO_MANY_1, WRONG_NO_1},
    {"modular-times",           TOO_FEW_2, Lmodular_times, WRONG_NO_2},
    {"modular-expt",            TOO_FEW_2, Lmodular_expt, WRONG_NO_2},
    {"set-small-modulus",       Lset_small_modulus, TOO_MANY_1, WRONG_NO_1},
    {"iadd1",                   Liadd1, TOO_MANY_1, WRONG_NO_1},
    {"idifference",             TOO_FEW_2, Lidifference, WRONG_NO_2},
    {"xdifference",             TOO_FEW_2, Lxdifference, WRONG_NO_2},
    {"igeq",                    TOO_FEW_2, Ligeq, WRONG_NO_2},
    {"igreaterp",               TOO_FEW_2, Ligreaterp, WRONG_NO_2},
    {"ileq",                    TOO_FEW_2, Lileq, WRONG_NO_2},
    {"ilessp",                  TOO_FEW_2, Lilessp, WRONG_NO_2},
    {"ilogand",                 Lidentity, Lilogand2, Lilogand},
    {"ilogor",                  Lidentity, Lilogor2, Lilogor},
    {"ilogxor",                 Lidentity, Lilogxor2, Lilogxor},
    {"imax",                    TOO_FEW_2, Limax, WRONG_NO_2},
    {"imin",                    TOO_FEW_2, Limin, WRONG_NO_2},
    {"iminus",                  Liminus, TOO_MANY_1, WRONG_NO_1},
    {"iminusp",                 Liminusp, TOO_MANY_1, WRONG_NO_1},
    {"iplus",                   Lidentity, Liplus2, Liplus},
    {"iplus2",                  TOO_FEW_2, Liplus2, WRONG_NO_2},
    {"iquotient",               TOO_FEW_2, Liquotient, WRONG_NO_2},
    {"iremainder",              TOO_FEW_2, Liremainder, WRONG_NO_2},
    {"irightshift",             TOO_FEW_2, Lirightshift, WRONG_NO_2},
    {"isub1",                   Lisub1, TOO_MANY_1, WRONG_NO_1},
    {"itimes",                  Lidentity, Litimes2, Litimes},
    {"itimes2",                 TOO_FEW_2, Litimes2, WRONG_NO_2},
    {"ionep",                   Lionep, TOO_MANY_1, WRONG_NO_1},
    {"izerop",                  Lizerop, TOO_MANY_1, WRONG_NO_1},
#ifdef FP_EVALUATE
    {"fp-evaluate",             TOO_FEW_2, Lfp_eval, WRONG_NO_2},
#endif
    {NULL,                      0, 0, 0}
};

// end of arith12.cpp
