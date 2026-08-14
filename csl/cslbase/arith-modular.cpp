// arith-modular.cpp                       Copyright (C) 2022-2026 Codemist

#ifdef ARITHLIB

// $Id$


/**************************************************************************
 * Copyright (C) 2026, Codemist.                         A C Norman       *
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

#include "arith-headers.h"

namespace CSL_LISP
{

// fixnum + fixnum
LispObject ModularPlus::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularPlus::op(int_of_fixnum(a),
                                              int_of_fixnum(b));
}
// bignum + fixnum
LispObject ModularPlus::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularPlus::op(a, int_of_fixnum(b));
}
// fixnum + bignum
LispObject ModularPlus::op(Fixnum a, uint64_t *b)
{   return ModularPlus::op(b, a);
}
// bignum + bignum
LispObject ModularPlus::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularPlus::op(a, b);
}

// fixnum * fixnum
LispObject ModularTimes::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularTimes::op(int_of_fixnum(a),
                                               int_of_fixnum(b));
}

// bignum * fixnum
LispObject ModularTimes::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularTimes::op(a, int_of_fixnum(b));
}
// fixnum * bignum
LispObject ModularTimes::op(Fixnum a, uint64_t *b)
{   return ModularTimes::op(b, a);
}
// bignum * bignum
LispObject ModularTimes::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularTimes::op(a, b);
}

// fixnum - fixnum
LispObject ModularDifference::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularDifference::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum - fixnum
LispObject ModularDifference::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularDifference::op(a, int_of_fixnum(b));
}
// fixnum - bignum
LispObject ModularDifference::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::ModularDifference::op(int_of_fixnum(a), b);
}
// bignum - bignum
LispObject ModularDifference::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularDifference::op(a, b);
}

// fixnum / fixnum
LispObject ModularQuotient::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::ModularQuotient::op(int_of_fixnum(a), int_of_fixnum(b));
}
// bignum / fixnum
LispObject ModularQuotient::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::ModularQuotient::op(a, int_of_fixnum(b));
}
// fixnum / bignum
LispObject ModularQuotient::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::ModularQuotient::op(int_of_fixnum(a), b);
}
// bignum / bignum
LispObject ModularQuotient::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::ModularQuotient::op(a, b);
}

// -fixnum
LispObject ModularReciprocal::op(Fixnum a)
{   return arithlib_lowlevel::ModularReciprocal::op(int_of_fixnum(a));
}
// -bignum
LispObject ModularReciprocal::op(uint64_t *a)
{   return arithlib_lowlevel::ModularReciprocal::op(a);
}

// -fixnum
LispObject SafeModularReciprocal::op(Fixnum a)
{   return arithlib_lowlevel::SafeModularReciprocal::op(int_of_fixnum(a));
}
// -bignum
LispObject SafeModularReciprocal::op(uint64_t *a)
{   return arithlib_lowlevel::SafeModularReciprocal::op(a);
}

// -fixnum
LispObject ModularMinus::op(Fixnum a)
{   return arithlib_lowlevel::ModularMinus::op(int_of_fixnum(a));
}
// -bignum
LispObject ModularMinus::op(uint64_t *a)
{   return arithlib_lowlevel::ModularMinus::op(a);
}

LispObject SetModulus::op(Fixnum a)
{   return arithlib_lowlevel::SetModulus::op(int_of_fixnum(a));
}
// bignum
LispObject SetModulus::op(uint64_t *a)
{   return arithlib_lowlevel::SetModulus::op(a);
}

// fixnum
LispObject ModularNumber::op(Fixnum a)
{   return arithlib_lowlevel::ModularNumber::op(int_of_fixnum(a));
}
// bignum
LispObject ModularNumber::op(uint64_t *a)
{   return arithlib_lowlevel::ModularNumber::op(a);
}


//===================

// N.B. that the modular arithmetic functions must cope with any small
// modulus that could fit in a fixnum.

LispObject Nmodular_difference(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-difference", a);
        if (!is_fixnum(b)) return aerror1("modular-difference", b);
        r = int_of_fixnum(a) - int_of_fixnum(b);
        if (r < 0) r += current_modulus;
        return fixnum_of_int(r);
    }
    a = Binary(Difference, a, b);
    if (BoolUnary(Minusp, a)) a = Binary(Plus, a, large_modulus);
    return a;
}

LispObject Nmodular_minus(LispObject env, LispObject a)
{   SingleValued fn;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-minus", a);
        if (a != fixnum_of_int(0))
        {   intptr_t r = current_modulus - int_of_fixnum(a);
            a = fixnum_of_int(r);
        }
        return a;
    }
    a = Unary(Minus, a);
    if (a != fixnum_of_int(0)) a = Binary(Difference, large_modulus, a);
    return a;
}

LispObject Nmodular_number(LispObject env, LispObject a)
{   SingleValued fn;
    if (!modulus_is_large)
        return IBinary(Mod, a, fixnum_of_int(current_modulus));
    return IBinary(Mod, a, large_modulus);
}

LispObject Nmodular_plus(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nmodular_plus(LispObject env, LispObject a)
{   SingleValued fn;
    return a;
}

LispObject Nmodular_plus(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a)) return aerror1("modular-plus", a);
        if (!is_fixnum(b)) return aerror1("modular-plus", b);
        r = int_of_fixnum(a) + int_of_fixnum(b);
        if (r >= current_modulus) r -= current_modulus;
        return fixnum_of_int(r);
    }
    a = Binary(Plus, a, b);
    if (BoolBinary(Geq, a, large_modulus)) a = Binary(Difference, a, large_modulus);
    return a;
}

LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   SingleValued fn;
    intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a1)) return aerror1("modular-plus", a1);
        if (!is_fixnum(a2)) return aerror1("modular-plus", a2);
        if (!is_fixnum(a3)) return aerror1("modular-plus", a3);
        r = int_of_fixnum(a1) + int_of_fixnum(a2) + int_of_fixnum(a3);
        if (r >= current_modulus) r -= current_modulus;
        if (r >= current_modulus) r -= current_modulus;
        return fixnum_of_int(r);
    }
    a1 = Binary(Plus, Binary(Plus, a1, a2), a3);
    if (BoolBinary(Geq, a1, large_modulus)) a1 = Binary(Difference, a1, large_modulus);
    if (BoolBinary(Geq, a1, large_modulus)) a1 = Binary(Difference, a1, large_modulus);
    return a1;
}

LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   SingleValued fn;
    intptr_t r;
    if (!modulus_is_large)
    {   if (!is_fixnum(a1)) return aerror1("modular-plus", a1);
        if (!is_fixnum(a2)) return aerror1("modular-plus", a2);
        if (!is_fixnum(a3)) return aerror1("modular-plus", a3);
        r = int_of_fixnum(a1) + int_of_fixnum(a2) + int_of_fixnum(a3);
        if (r >= current_modulus) r -= current_modulus;
        if (r >= current_modulus) r -= current_modulus;
        while (a4plus != nil)
        {   LispObject w = car(a4plus);
            a4plus = cdr(a4plus);
            if (!is_fixnum(w)) return aerror1("modular-plus", w);
            r = r + int_of_fixnum(w);
            if (r >= current_modulus) r -= current_modulus;
        }
        return fixnum_of_int(r);
    }
    a1 = Binary(Plus, Binary(Plus, a1, a2), a3);
    if (BoolBinary(Geq, a1, large_modulus)) a1 = Binary(Difference, a1, large_modulus);
    if (BoolBinary(Geq, a1, large_modulus)) a1 = Binary(Difference, a1, large_modulus);
    while (a4plus != nil)
    {   LispObject w = car(a4plus);
        a4plus = cdr(a4plus);
        a1 = Binary(Plus, a1, w);
        if (BoolBinary(Geq, a1, current_modulus))
            a1 = Binary(Difference, a1, current_modulus);
    }
    return a1;
}

LispObject Nlarge_modular_reciprocal(LispObject n, bool safe=false)
{   SingleValued fn;
    LispObject a, b, x, y;
    b = n;
    x = fixnum_of_int(0);
    y = fixnum_of_int(1);
    if (b == fixnum_of_int(0))
    {   if (safe) return nil;
        else return aerror1("modular-reciprocal", n);
    }
    b = IBinary(Mod, b, large_modulus);
    a = large_modulus;
    while (b != fixnum_of_int(1))
    {   LispObject w, t;
        if (b == fixnum_of_int(0))
        {   if (safe) return nil;
            else return aerror2("non-prime modulus in modular-reciprocal",
                             large_modulus, n);
        }
        w = Binary(Quotient, a, b);
        t = b;
        b = Binary(Times, b, w);
        b = Binary(Difference, a, b);
        a = t;
        t = y;
        y = Binary(Times, y, w);
        y = Binary(Difference, x, y);
        x = t;
    }
    y = IBinary(Mod, y, large_modulus);
    return y;
}

LispObject Nmodular_reciprocal(LispObject, LispObject n)
{   SingleValued fn;
    intptr_t a, b, x, y;
    if (modulus_is_large) return Nlarge_modular_reciprocal(n);
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
    return fixnum_of_int(y);
}

LispObject Nsafe_modular_reciprocal(LispObject env, LispObject n)
{   SingleValued fn;
    intptr_t a, b, x, y;
    if (modulus_is_large) return Nlarge_modular_reciprocal(n, true);
    if (!is_fixnum(n)) return aerror1("modular-reciprocal", n);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return nil;
    if (b < 0) b = current_modulus - ((-b)%current_modulus);
    while (b != 1)
    {   intptr_t w, t;
        if (b == 0) return nil;
        w = a / b;
        t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += current_modulus;
    return fixnum_of_int(y);
}

LispObject Nmodular_times(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Nmodular_times(LispObject env, LispObject a)
{   SingleValued fn;
    return a;
}

LispObject Nmodular_times(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    uintptr_t cm;
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
            return fixnum_of_int((intptr_t)r);
        }
// If the modulus is at worst 32 bits I can do a 64-bit (unsigned)
// multiplication and remainder step.
        else if (cm <= 0xffffffffU)
        {   uint64_t r = ((uint64_t)aa*(uint64_t)bb) % (uint64_t)cm;
// Because I am in a state where modulus_is_large is not set I know that the
// modulus fits in a fixnum, hence the result will. So even though all value
// that are of type uint64_t might not be valid as fixnums the one I have
// here will be.
            return fixnum_of_int((intptr_t)r);
        }
// Now my modulus is over 32-bits...
// Using an int128_t bit type I can use it and the code is really neat!
// On some platforms this goes via C++ templates and operator overloading
// into a software implementation of 128-bit integer arithmetic!
        else
        {   int64_t r = static_cast<int64_t>(
                (static_cast<int128_t>(aa) * static_cast<int128_t>(bb)) %
                static_cast<int128_t>(cm));
            return fixnum_of_int((intptr_t)r);
        }
    }
    a = Binary(Times, a, b);
    return IBinary(Mod, a, large_modulus);
}

LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3)
{   SingleValued fn;
    return Nmodular_times(env, Nmodular_times(env, a1, a2), a3);
}

LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus)
{   SingleValued fn;
    a1 = Nmodular_times(env, Nmodular_times(env, a1, a2), a3);
    while (a4plus != nil)
    {   a1 = Nmodular_times(env, a2, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return a1;
}

LispObject Nmodular_quotient(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    b = Nmodular_reciprocal(nil, b);
    return Nmodular_times(nil, a, b);
}

LispObject Nlarge_modular_expt(LispObject a, int x)
{   LispObject r, p, w;
    p = IBinary(Mod, a, large_modulus);
    errexit();
    while ((x & 1) == 0)
    {   p = Binary(Times, p, p);
        errexit();
        p = IBinary(Mod, p, large_modulus);
        errexit();
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   w = Binary(Times, p, p);
        errexit();
        p = IBinary(Mod, w, large_modulus);
        errexit();
        x = x/2;
        if ((x & 1) != 0)
        {   w = Binary(Times, r, p);
            errexit();
            r = IBinary(Mod, w, large_modulus);
            errexit();
        }
    }
    return r;
}

inline intptr_t muldivptr(uintptr_t a, uintptr_t b, uintptr_t c)
{   if (!SIXTY_FOUR_BIT || c <= 0xffffffffU)
        return ((uint64_t)a*(uint64_t)b)%(uintptr_t)c;
    else return (intptr_t)static_cast<int64_t>(
        (uint128_t((uint64_t)a) * uint128_t((uint64_t)a)) % (uintptr_t)c);
}

LispObject Nmodular_expt(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    intptr_t x, r, p;
    x = int_of_fixnum(b);
    if (x == 0) return fixnum_of_int(1);
    if (modulus_is_large) return Nlarge_modular_expt(a, x);
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
    return fixnum_of_int(r);
}

// I can set any (positive) integer as a modulus here. I will treat it
// internally as "small" if it fits in a fixnum.

LispObject Nset_small_modulus(LispObject env, LispObject a)
{   SingleValued fn;
    LispObject old = modulus_is_large ? large_modulus :
                     fixnum_of_int(current_modulus);
    if (a==nil) return old;
    else if (!is_fixnum(a))
    {   if (!is_new_bignum(a) || BoolUnary(Minusp, a))
            return aerror1("set-small-modulus", a);
        modulus_is_large = true;
        current_modulus = 0;   // should not be referenced.
        large_modulus = a;
        return old;
    }
    if ((intptr_t)a < 0 || a == fixnum_of_int(0))
        return aerror1("set!-small!-modulus", a);
    modulus_is_large = false;
    large_modulus = nil; // Should not be referenced.
    current_modulus = int_of_fixnum(a);;
    return old;
}

#ifdef NOT_YET

LispObject Nmodular_plus(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(0);
}

LispObject Nmodular_plus(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return ModularPlus::op(a1, a2);
}

LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3)
{   SingleValued fn;
    return ModularPlus::op(ModularPlus::op(a1, a2), a3);
}

LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = ModularPlus::op(ModularPlus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularPlus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nmodular_times(LispObject env)
{   SingleValued fn;
    return fixnum_of_int(1);
}

LispObject Nmodular_times(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2)
{   SingleValued fn;
    return ModularTimes::op(a1, a2);
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3)
{   SingleValued fn;
    return ModularTimes::op(ModularTimes::op(a1, a2), a3);
}

LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    LispObject w = ModularTimes::op(ModularTimes::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularTimes::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return w;
}

LispObject Nmodular_expt(LispObject env, LispObject a, LispObject n)
{   SingleValued fn;
    if (!is_fixnum(a) && !is_new_bignum(a))
        return aerror1("bad argument to modular-expt", a);
    if (!is_fixnum(n) && !is_new_bignum(n) && !Minusp::op(n))
        return aerror1("bad argument to modular-expt", n);
    if (n == fixnum_of_int(0)) return fixnum_of_int(1);
    else if (n == fixnum_of_int(1)) return a;        // a simple special case.
    size_t len = int_of_fixnum(IntegerLength::op(n));
    uint64_t i;
    uint64_t* nn;
// I do a deep dive into arithlib.cpp to exploit data respresentation.
// This code should probably migrate to be within arithlib.
    if (arithlib_implementation::stored_as_fixnum(n))
    {   i = arithlib_implementation::int_of_handle(n);
        nn = &i;
    }
    else nn = arithlib_implementation::vector_of_handle(n);
    LispObject r = fixnum_of_int(1);
    for (size_t k=0; k<len-1; k++)
    {   int bit = (nn[k/64]>>(k%64)) & 1;
        if (bit != 0) r = ModularTimes::op(r, a);
        a = ModularTimes::op(a, a);
    }
    return ModularTimes::op(r, a);
}

LispObject Nmodular_difference(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return ModularDifference::op(a1, a2);
}

LispObject Nmodular_quotient(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return ModularQuotient::op(a1, a2);
}

LispObject Nmodular_reciprocal(LispObject env, LispObject a1)
{   SingleValued fn;
    return ModularReciprocal::op(a1);
}

LispObject Nsafe_modular_reciprocal(LispObject env, LispObject a1)
{   SingleValued fn;
    return SafeModularReciprocal::op(a1);
}

LispObject Nmodular_minus(LispObject env, LispObject a1)
{   SingleValued fn;
    return ModularMinus::op(a1);
}

LispObject Nset_modulus(LispObject env, LispObject a1)
{   SingleValued fn;
    return SetModulus::op(a1);
}

LispObject Nmodular_number(LispObject env, LispObject a1)
{   SingleValued fn;
    return ModularNumber::op(a1);
}

#endif // NOT_YET

} // end of namespace

#endif // ARITHLIB

// end of arith-modular.cpp
