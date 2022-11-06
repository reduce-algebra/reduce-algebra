//  arith12.cpp                            Copyright (C) 1990-2022 Codemist

//
// Arithmetic functions... specials for Reduce (esp. factoriser)
//
//


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


LispObject Lfrexp(LispObject env, LispObject a)
{
#ifdef HAVE_SOFTFLOAT
    if (is_long_float(a))
    {   float128_t d;
        int x;
        f128_frexp(*bit_cast<float128_t *>(long_float_addr(a)), &d, &x);
        return cons(fixnum_of_int(x), make_boxfloat128(d));
    }
    else
#endif // HAVE_SOFTFLOAT
        if (is_single_float(a))
        {   int x;
            float d = std::frexp(single_float_val(a), &x);
            return cons(fixnum_of_int(x), pack_single_float(d));
        }
        else if (is_short_float(a))
        {   int x;
// I can afford to do the frexp on a double here.
            double d = std::frexp(value_of_immediate_float(a), &x);
            return cons(fixnum_of_int(x), pack_short_float(d));
        }
        else
        {   int x;
            double d = std::frexp(float_of_number(a), &x);
// I clearly once encountered a C library that failed on this edge case!
            if (d == 1.0) d = 0.5, x++;
            return cons(fixnum_of_int(x),make_boxfloat(d));
        }
}

// N.B. that the modular arithmetic functions must cope with any small
// modulus that could fit in a fixnum.

LispObject Lmodular_difference(LispObject env, LispObject a,
                               LispObject b)
{   intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-difference", a);
        if (!is_fixnum(b)) return aerror1("modular-difference", b);
        r = int_of_fixnum(a) - int_of_fixnum(b);
        if (r < 0) r += current_modulus;
        return onevalue(fixnum_of_int(r));
    }
    a = difference2(a, b);
    return modulus(a, large_modulus);
}

LispObject Lmodular_minus(LispObject env, LispObject a)
{   if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-minus", a);
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
    {   if (!is_fixnum(a)) return aerror1("modular-plus", a);
        if (!is_fixnum(b)) return aerror1("modular-plus", b);
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
        else return aerror1("modular-reciprocal", n);
    }
    b = modulus(b, large_modulus);
    a = large_modulus;
    THREADID;
    while (b != fixnum_of_int(1))
    {   LispObject w, t;
        if (b == fixnum_of_int(0))
        {   if (safe) return onevalue(nil);
            else return aerror2("non-prime modulus in modular-reciprocal",
                             large_modulus, n);
        }
        {   Save save(THREADARG x, y);
            w = quot2(a, b);
            save.restore(x, y);
        }
        t = b;
        {   Save save(THREADARG a, x, y, w, t);
            b = times2(b, w);
            save.restore(a, x, y, w, t);
        }
        {   Save save(THREADARG x, y, w, t);
            b = difference2(a, b);
            save.restore(x, y, w, t);
        }
        a = t;
        t = y;
        {   Save save(THREADARG a, b, x, t);
            y = times2(y, w);
            save.restore(a, b, x, t);
        }
        {   Save save(THREADARG a, b, t);
            y = difference2(x, y);
            save.restore(a, b, t);
        }
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
    if (!is_fixnum(n)) return aerror1("modular-reciprocal", n);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return aerror1("modular-reciprocal", n);
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   intptr_t w, t;
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

LispObject Lsafe_modular_reciprocal(LispObject env, LispObject n)
{   intptr_t a, b, x, y;
    if (modulus_is_large) return large_modular_reciprocal(n, true);
    if (!is_fixnum(n)) return aerror1("modular-reciprocal", n);
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
{   uintptr_t cm;
    intptr_t aa, bb;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-times", a);
        if (!is_fixnum(b)) return aerror1("modular-times", b);
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
        {   int64_t r = static_cast<int64_t>(
                (static_cast<int128_t>(aa) * static_cast<int128_t>(bb)) %
                static_cast<int128_t>(cm));
            return onevalue(fixnum_of_int((intptr_t)r));
        }
    }
    a = times2(a, b);
    return modulus(a, large_modulus);
}

LispObject Lmodular_quotient(LispObject env, LispObject a,
                             LispObject b)
{   {   THREADID;
        Save save(THREADARG a);
        b = Lmodular_reciprocal(nil, b);
        errexit();
        save.restore(a);
    }
    return Lmodular_times(nil, a, b);
}

LispObject large_modular_expt(LispObject a, int x)
{   LispObject r, p, w;
    p = modulus(a, large_modulus);
    errexit();
    while ((x & 1) == 0)
    {   p = times2(p, p);
        errexit();
        p = modulus(p, large_modulus);
        errexit();
        x = x/2;
    }
    r = p;
    THREADID;
    while (x != 1)
    {   Save save(THREADARG r);
        w = times2(p, p);
        errexit();
        p = modulus(w, large_modulus);
        errexit();
        save.restore(r);
        x = x/2;
        if ((x & 1) != 0)
        {   Save save1(THREADARG p);
            w = times2(r, p);
            errexit();
            r = modulus(w, large_modulus);
            errexit();
            save1.restore(p);
        }
    }
    return onevalue(r);
}

inline intptr_t muldivptr(uintptr_t a, uintptr_t b, uintptr_t c)
{   if (!SIXTY_FOUR_BIT || c <= 0xffffffffU)
        return ((uint64_t)a*(uint64_t)b)%(uintptr_t)c;
    else return (intptr_t)static_cast<int64_t>(
        (uint128((uint64_t)a) * uint128((uint64_t)a)) % (uintptr_t)c);
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
    {   p = muldivptr((uintptr_t)p, (uintptr_t)p,
                      (uintptr_t)current_modulus);
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   p = muldivptr((uintptr_t)p, (uintptr_t)p,
                      (uintptr_t)current_modulus);
        x = x/2;
        if ((x & 1) != 0)
        {   r = muldivptr((uintptr_t)r, (uintptr_t)p,
                          (uintptr_t)current_modulus);
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
            return aerror1("set-small-modulus", a);
        modulus_is_large = 1;
        current_modulus = 0;   // should not be referenced.
        large_modulus = a;
        return old;
    }
    if ((intptr_t)a < 0 || a == fixnum_of_int(0))
        return aerror1("set!-small!-modulus", a);
    modulus_is_large = 0;
    large_modulus = nil; // Should not be referenced.
    current_modulus = int_of_fixnum(a);;
    return onevalue(old);
}

LispObject Liadd1(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("iadd1", a);
    return onevalue(static_cast<LispObject>((intptr_t)a + 0x10));
}

LispObject Lidifference_2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("idifference", a, b);
    return onevalue(static_cast<LispObject>((intptr_t)a -
                                            (intptr_t)b + TAG_FIXNUM));
}

// xdifference is provided just for the support of the CASE operator. It
// subtracts its arguments but returns NIL if either argument is not
// an small integer or if the result overflows. Small is 28-bits in this
// context at present, which is maybe strange!

LispObject Lxdifference(LispObject env, LispObject a, LispObject b)
{   int32_t r;
    if (!is_fixnum(a) || !is_fixnum(b)) return onevalue(nil);
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < -0x08000000 || r > 0x07ffffff) return onevalue(nil);
    return onevalue(fixnum_of_int(r));
}

LispObject Ligreaterp_2(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igreaterp", a, b);
    return onevalue(Lispify_predicate(a > b));
}

LispObject Lilessp_2(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilessp", a, b);
    return onevalue(Lispify_predicate(a < b));
}

LispObject Ligeq_2(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igeq", a, b);
    return onevalue(Lispify_predicate(a >= b));
}

LispObject Lileq_2(LispObject env, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ileq", a, b);
    return onevalue(Lispify_predicate(a <= b));
}

static LispObject Lilogand_0(LispObject)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Lilogor_0(LispObject)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Lilogxor_0(LispObject)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Lilogeqv_0(LispObject)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Lilognot_1(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("ilognot", a);
    return onevalue (~(a - TAG_FIXNUM)) + TAG_FIXNUM;
}

static LispObject Lilogand_1(LispObject, LispObject a1)
{   if (!is_fixnum(a1)) return aerror1("ilogand", a1);
    return onevalue(a1);
}

static LispObject Lilogor_1(LispObject, LispObject a1)
{   if (!is_fixnum(a1)) return aerror1("ilogor", a1);
    return onevalue(a1);
}

static LispObject Lilogxor_1(LispObject, LispObject a1)
{   if (!is_fixnum(a1)) return aerror1("ilogxor", a1);
    return onevalue(a1);
}

static LispObject Lilogeqv_1(LispObject, LispObject a1)
{   if (!is_fixnum(a1)) return aerror1("ilogeqv", a1);
    return onevalue(a1);
}

static LispObject Lilogand_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("ilogand", a1, a2);
    return onevalue(a1 & a2);
}

static LispObject Lilogor_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("ilogor", a1, a2);
    return onevalue(a1 | a2);
}

static LispObject Lilogxor_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("ilogxor", a1, a2);
    return onevalue((a1 ^ a2) + TAG_FIXNUM);
}

static LispObject Lilogeqv_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("ilogeqv", a1, a2);
    return onevalue(~(a1 ^ a2) + TAG_FIXNUM);
}

static LispObject Lilogand_3(LispObject, LispObject a1, LispObject a2,
                             LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogand", a2, a2, a3);
    return onevalue(a1 & a2 & a3);
}

static LispObject Lilogor_3(LispObject, LispObject a1, LispObject a2,
                            LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogor", a2, a2, a3);
    return onevalue(a1 | a2 | a3);
}

static LispObject Lilogxor_3(LispObject, LispObject a1, LispObject a2,
                             LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogxor", a2, a2, a3);
    return onevalue(a1 ^ a2 ^ a3);
}

static LispObject Lilogeqv_3(LispObject, LispObject a1, LispObject a2,
                             LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogeqv", a2, a2, a3);
    return onevalue(~((a1 ^ a2 ^ a3) - TAG_FIXNUM) + TAG_FIXNUM);
}

static LispObject Lilogand_4up(LispObject env, LispObject a1,
                               LispObject a2,
                               LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogand", a2, a2, a3);
    a1 = a1 & a2 & a3;
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("ilogand", a2);
        a1 = a1 & a2;
    }
    return onevalue(a1);
}

static LispObject Lilogor_4up(LispObject env, LispObject a1,
                              LispObject a2,
                              LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogor", a2, a2, a3);
    a1 = a1 | a2 | a3;
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("ilogor", a2);
        a1 = a1 | a2;
    }
    return onevalue(a1);
}

static LispObject Lilogxor_4up(LispObject env, LispObject a1,
                               LispObject a2,
                               LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogxor", a2, a2, a3);
    a1 = a1 ^ a2 ^ a3;
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("ilogxor", a2);
        a1 = a1 ^ a2;
    }
    a1 = (a1 & ~static_cast<LispObject>(TAG_BITS)) | TAG_FIXNUM;
    return onevalue(a1);
}

static LispObject Lilogeqv_4up(LispObject env, LispObject a1,
                               LispObject a2,
                               LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("ilogeqv", a2, a2, a3);
    a1 = (a1 ^ a2 ^ a3) - TAG_FIXNUM;
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("ilogeqv", a2);
        a1 = a1 ^ (a2 - TAG_FIXNUM);
    }
    a1 = (~a1) + TAG_FIXNUM;
    return onevalue(a1);
}

LispObject Limin_2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imin", a, b);
    return onevalue(a < b ? a : b);
}

LispObject Limax_2(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imax", a, b);
    return onevalue(a > b ? a : b);
}

LispObject Liminus(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("iminus", a);
    return onevalue(static_cast<LispObject>(2*TAG_FIXNUM - (intptr_t)a));
}

LispObject Liminusp(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a <
                                      (intptr_t)fixnum_of_int(0)));
}

LispObject Liplus_0(LispObject)
{   return onevalue(fixnum_of_int(1));
}

LispObject Liplus_1(LispObject, LispObject a1)
{   return onevalue(a1);
}

LispObject Liplus_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("iplus2", a1, a2);
    return onevalue(static_cast<LispObject>((intptr_t)a1 +
                                            (intptr_t)a2 - TAG_FIXNUM));
}

LispObject Liplus_3(LispObject, LispObject a1, LispObject a2,
                    LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("iplus", a1, a2, a3);
    return onevalue(static_cast<LispObject>((intptr_t)a1 +
                                            (intptr_t)a2 - 2*TAG_FIXNUM +
                                            (intptr_t)a3));
}

static LispObject Liplus_4up(LispObject, LispObject a1, LispObject a2,
                             LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("iplus", a1, a2, a3);
    a1 = (intptr_t)a1 + (intptr_t)a2 - 2*TAG_FIXNUM + (intptr_t)a3;
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("iplus", a2);
        a1 = a1 + (intptr_t)a2 - TAG_FIXNUM;
    }
    return onevalue(a1);
}

LispObject Liquotient_2(LispObject, LispObject a, LispObject b)
{   intptr_t aa, bb, c;
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

LispObject Liremainder_2(LispObject, LispObject a, LispObject b)
{   intptr_t aa, bb, c;
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

#ifdef SIXTY_FOUR
LispObject Lirightshift(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("irightshift", a, b);
    return onevalue(fixnum_of_int(ASR(
           static_cast<int64_t>(int_of_fixnum(a)), uint_of_fixnum(b))));
}
#else // SIXTY_FOUR
LispObject Lirightshift(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("irightshift", a, b);
    return onevalue(fixnum_of_int(ASR(
           static_cast<int32_t>(int_of_fixnum(a)), uint_of_fixnum(b))));
}
#endif // SIXTY_FOUR

LispObject Lileftshift(LispObject, LispObject a, LispObject b)
{   if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ileftshift", a, b);
    return onevalue(fixnum_of_int(uint_of_fixnum(a) << uint_of_fixnum(b)));
}

LispObject Lisub1(LispObject, LispObject a)
{   if (!is_fixnum(a)) return aerror1("isub1", a);
    return onevalue(static_cast<LispObject>((intptr_t)a - 0x10));
}

LispObject Litimes_0(LispObject)
{   return onevalue(fixnum_of_int(1));
}

LispObject Litimes_1(LispObject, LispObject a1)
{   return onevalue(a1);
}

LispObject Litimes_2(LispObject, LispObject a1, LispObject a2)
{   if (!is_fixnum(a1) || !is_fixnum(a2)) return aerror2("itimes2", a1, a2);
    return onevalue(fixnum_of_int(int_of_fixnum(a1) * int_of_fixnum(a2)));
}

LispObject Litimes_3(LispObject, LispObject a1, LispObject a2,
                     LispObject a3)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("itimes", a1, a2, a3);
    return onevalue(fixnum_of_int(int_of_fixnum(a1) *
                                  int_of_fixnum(a2) *
                                  int_of_fixnum(a3)));
}

static LispObject Litimes_4up(LispObject env, LispObject a1,
                              LispObject a2,
                              LispObject a3, LispObject a4up)
{   if (!is_fixnum(a1) || !is_fixnum(a2) || !is_fixnum(a3))
        return aerror3("iplus", a1, a2, a3);
    intptr_t r = int_of_fixnum(a1) * int_of_fixnum(a2) * int_of_fixnum(
                     a3);
    while (a4up != nil)
    {   a2 = car(a4up);
        a4up = cdr(a4up);
        if (!is_fixnum(a2)) return aerror1("itimes", a2);
        r = r * int_of_fixnum(a2);
    }
    return onevalue(fixnum_of_int(r));
}

LispObject Lionep(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a ==
                                      (intptr_t)fixnum_of_int(1)));
}

LispObject Lizerop(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate((intptr_t)a ==
                                      (intptr_t)fixnum_of_int(0)));
}

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
// The object of this code is to support fast evaluation of numeric
// expressions.  The first argument is a vector of byte opcodes, while
// the second arg is a list of floating point values whose value will (or
// at least may) be used.  There are at most 32 values in this list.
{   int n = 0;
    double w;
    unsigned char *p;
    if (!is_vector(code)) return aerror("fp-evaluate");
    while (consp(args))
    {   fp_args[n++] = float_of_number(car(args));
        args = cdr(args);
    }
    n = 0;
    p = bit_cast<unsigned char *>(&ucelt(code, 0));
    for (;;)
    {   int op = *p++;
// Opcodes 0 to 31 just load up the corresponding input value.
        if (op < 32)
        {   fp_stack[n++] = fp_args[op];
            continue;
        }
        switch (op)
    {       default:
                return aerror("Bad op in fp-evaluate");
            case FP_RETURN:
                args = make_boxfloat(fp_stack[0], WANT_DOUBLE_FLOAT);
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
                fp_stack[n] = std::sin(fp_stack[n]);
                continue;
            case FP_COS:
                fp_stack[n] = std::cos(fp_stack[n]);
                continue;
            case FP_TAN:
                fp_stack[n] = std::tan(fp_stack[n]);
                continue;
            case FP_EXP:
                fp_stack[n] = std::exp(fp_stack[n]);
                continue;
            case FP_LOG:
                fp_stack[n] = std::log(fp_stack[n]);
                continue;
            case FP_SQRT:
                fp_stack[n] = std::sqrt(fp_stack[n]);
                continue;
        }
    }
}

// If ARITHLIB is enabled all these functions will have their names
// prefixed with "old" so that the versions from the arithlib code
// provide the default behaviour

#ifdef ARITHLIB
#define X "old"
#else // ARITHLIB
#define X
#endif // ARITHLIB

setup_type const arith12_setup[] =
{   DEF_1(X "frexp",              Lfrexp),
    DEF_2(X "modular-difference", Lmodular_difference),
    DEF_1(X "modular-minus",      Lmodular_minus),
    DEF_1(X "modular-number",     Lmodular_number),
    DEF_2(X "modular-plus",       Lmodular_plus),
    DEF_2(X "modular-quotient",   Lmodular_quotient),
    DEF_1(X "modular-reciprocal", Lmodular_reciprocal),
    DEF_1(X "safe-modular-reciprocal", Lsafe_modular_reciprocal),
    DEF_2(X "modular-times",      Lmodular_times),
    DEF_2(X "modular-expt",       Lmodular_expt),
    DEF_1(X "set-small-modulus",  Lset_small_modulus),
    DEF_1(X "iadd1",              Liadd1),
    DEF_2(X "idifference",        Lidifference_2),
    DEF_2(X "xdifference",        Lxdifference),
    DEF_2(X "igeq",               Ligeq_2),
    DEF_2(X "igreaterp",          Ligreaterp_2),
    DEF_2(X "ileq",               Lileq_2),
    DEF_2(X "ilessp",             Lilessp_2),
    DEF_1(X "ilognot",            Lilognot_1),
    {X "ilogand",                 Lilogand_0, Lilogand_1, Lilogand_2, Lilogand_3, Lilogand_4up},
    {X "ilogor",                  Lilogor_0, Lilogor_1, Lilogor_2, Lilogor_3, Lilogor_4up},
    {X "ilogxor",                 Lilogxor_0, Lilogxor_1, Lilogxor_2, Lilogxor_3, Lilogxor_4up},
    {X "ilogeqv",                 Lilogeqv_0, Lilogeqv_1, Lilogeqv_2, Lilogeqv_3, Lilogeqv_4up},
    DEF_2(X "imax",               Limax_2),
    DEF_2(X "imin",               Limin_2),
    DEF_1(X "iminus",             Liminus),
    DEF_1(X "iminusp",            Liminusp),
    {X "iplus",                   Liplus_0, Liplus_1, Liplus_2, Liplus_3, Liplus_4up},
    DEF_2(X "iplus2",             Liplus_2),
    DEF_2(X "iquotient",          Liquotient_2),
    DEF_2(X "iremainder",         Liremainder_2),
    DEF_2(X "irightshift",        Lirightshift),
    DEF_2(X "ileftshift",         Lileftshift),
    DEF_1(X "isub1",              Lisub1),
    {X "itimes",                  Litimes_0, Litimes_1, Litimes_2, Litimes_3, Litimes_4up},
    DEF_2(X "itimes2",            Litimes_2),
    DEF_1(X "ionep",              Lionep),
    DEF_1(X "izerop",             Lizerop),
    DEF_2(X "fp-evaluate",        Lfp_eval),
    {nullptr,                   nullptr, nullptr, nullptr, nullptr, nullptr}
};

// end of arith12.cpp
