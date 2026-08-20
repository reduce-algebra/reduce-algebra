// generic.h                                  Copyright (C) A C Norman 2026

#ifndef __header_generic_h
#define __header_generic_h 1

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


namespace CSL_LISP
{
using namespace arithlib_implementation;

// In CSL arithmetic is generic in the sense that the functions such as
// plus and times will accept integers or floats and work out what to
// do at runtime. I favour the case of arithmetic on small integers.
// The full set of types supported is as follows:
// Fixnum:       small integers (28 or 60 bits)
// Bignum:       arbitrary precision integers
// DoubleFloat:  IEEE-format 64-bit floats
// ShortFloat:   28-bit floats always stored as immediate date
// SingleFloat:  IEEE-format 32-bit floats (immediate on 64-bit platforms)
// LongFloat:    IEEE-format 120-bit floats
// Rationals:    stored as pairs of integers, with 1/0, -1/0 and 0/0 special
// Complex:      stored as real and imaginary parts.
//
// When asked to operator on Short or Single Floats I will generally perform
// the calculation using DoubleFloat and then reduce to the shorter form.
//
// For aritmetic calculations floating point contagion applies - ie all
// operands are converted to the widest floating point style seen. However
// for comparisons there is rational contagion so a comparison such as
// (lessp 1.2345 6/5) starts by converting the floating point value to
// a rational value such that the is no loss of information. The effect of
// this is also needed for eg (leq 17 17.0) where at least notionally both
// arguments must be converted to rational numbers before being compared.
// If an integer argument to a numeric comprison is at most 2^52 then it
// can be converted to (double precision) floating point with no loss, and
// so comparisons between a floating point number and a modest size integer
// can use floating point comparison.


// The class "op" must have a (static) "flags" component which can
// tune the precise behaviour of G as follows:
//
// op_fixnum                Only fixnum operands are acceptable. This
//                             is for iplus, idifference etc.
// op_int                   Only fixnum and bignum are allowed. Eg logand,
//                             logor, shifts.
// op_commutes              G<op>(a,b) can be implemented as G<op>(b,a).
//                             So eg for Plus only IB is needed, while
//                             without this flag Difference needs both
//                             IB and BI.
// op_compare               In "normal" cases G<op>(float, rational) will
//                             convert the rational number to a float and
//                             use the FF method. If this flag is set
//                             in such cases the float is converted to
//                             a rational number and a RR method is used.
//                             This is necessary for numeric comparisons
//                             such as lessp, greaterp etc. For this to
//                             work the conversion from float to rational
//                             will convert infinities into (1/0) or (-1/0)
//                             and NaNs into (0/0).
//                             The non-commuting comparisons will not accept
//                             complex values (ie >, >=, < and <). These can
//                             be indentified using a combinationm of the
//                             commutes and compare bits.
//
// The next two are constraints probably better hanndles using ad hoc code.
// op_no_complex             Do not accept complex arguments. Eg hypot
//                           and atan2 would use this if handled by this
//                           code. Note that <, <=, => and > are handled
//                           in another way.
// op_arg2int                If the second arg is a fixnum or a bignum
//                           do something special with an XI or XB method
//                           in all messy cases (including arg1 complex)
//                           so that A^N can be done by repeated
//                           multiplication. This is liable to make sense
//                           for expt and ldexp.

// Usually if either argument is complex an operator CC is called with 4
// arguments that are the real and imaginary parts of each argument, and
// if one of the arguments is not given as complex it gets passed with a
// zero imaginary part tagged on.

// The operations to be supported are
//      Abs
//      Add1
//      Bitand
//      Biteqv
//      Bitneqv
//      Bitnot
//      Bitor
//      CLeqn
//      CLquotient
//      Ceiling
//      ClassicalTimes
//      Difference
//      Divide
//      Eqn
//      Expt
//      Fceiling
//      Ffloor
//      Fix
//      Float
//      Floor
//      Fround
//      Ftrunc
//      Gcdn
//      Geq
//      Greaterp
//      Idifference
//      Iplus
//      Isqrt
//      Itimes
//      Lcmn
//      Leftshift
//      Leq
//      Lessp
//      Logbitp
//      Long_float
//      Minus
//      Minusonep
//      Minusp
//      Mod
//      Modular_difference
//      Modular_expt
//      Modular_minus
//      Modular_plus
//      Modular_quotient
//      Modular_reciprocal
//      Modular_times
//      Modularnumber
//      Neq
//      Onep
//      Plus
//      Quotient
//      Reciprocal
//      Remainder
//      Rightshift
//      Round
//      Safe_modular_reciprocal
//      Setmodulus
//      Short_float
//      Single_float
//      Sqrt
//      Square
//      Sub1
//      Times
//      Trunc
//      Zerop

// Here I am going to use a mnemonic in function names:
//    I integer
//    B bignum
//    S short float   (28 bits)
//    G single float  (32 bits)
//    D double float  (64 bits)
//    L long float    (128 bits)
//    C complex
//    R rational

enum
{   op_fixnum   = 1,
    op_int      = 2,
    op_commutes = 4,
    op_compare  = 8
};

// There is a dispatch scheme for unary operators.
// Well here I will view the dispatch code as compact enough that I
// will not split it into inline and regular parts. But I still put the
// cases I care about most first.

template <typename op>
[[gnu::always_inline]]
inline auto G(LispObject a)
{   if (is_fixnum(a)) LIKELY return op::I(a);
    else if constexpr (op::flags & op_fixnum)
        return aerror(op::name, "given non-fixnum argument", a);
    else
    {   if (is_bignum(a)) LIKELY return op::B(a);
        else if constexpr (op::flags & op_int)
        {   (void)aerror(op::name, "given non-integer argument", a);
            return op::I(fixnum_of_int(0));
        }
        else
        {   if (is_double_float(a)) LIKELY return op::L(double_float_val(a));
            else if (is_ratio(a)) LIKELY return op::R(numerator(a), denominator(a));
            else if (is_long_float(a)) LIKELY return op::L(long_float_val(a));
            else if (is_single_float(a)) LIKELY return op::S(single_float_val(a));
            else if (is_short_float(a)) LIKELY return op::F(short_float_val(a));
            if constexpr ((op::flags & op_compare) == 0)
            {   if (is_complex(a)) return op::C(real_part(a), imag_part(a));
            }
            (void)aerror(op::name, a);
// I need to appear to return a result of the correct type eben though
// aerror() should not return. Every operation should support fixnums, so
// I can use the "I" method to get things in a satisfactory state.
            return op::I(fixnum_of_int(0));
        }
    }
}

// For GX<op>(a, b) at least one of a, b is complex, rational or
// a float that is not the simple double precision sort. I view these
// as less performance critical than the cases handled in G<op>.

extern void float_to_rational(double f, LispObject& p, LispObject& q);
extern void float128_to_rational(FLOAT_128 f, LispObject& p, LispObject& q);

class Long_float_val
{
public:
    static constexpr const char* name = "long-float-val";
    static constexpr const unsigned int flags = 0;
    static FLOAT_128 error(LispObject a)
    {   (void) aerror(name, " given non-number", a);
        return NAN128();
    }

    static FLOAT_128 I(LispObject a)
    {   return (FLOAT_128)int_of_fixnum(a);
    }
    static FLOAT_128 B(LispObject a)
    {   return LF_C(999.999);
    }
    static FLOAT_128 S(LispObject a)
    {   return (FLOAT_128)short_float_val(a);
    }
    static FLOAT_128 F(LispObject a)
    {   return (FLOAT_128)single_float_val(a);
    }
    static FLOAT_128 D(LispObject a)
    {   return (FLOAT_128)double_float_val(a);
    }
    static FLOAT_128 L(LispObject a)
    {   return long_float_val(a);
    }
    static FLOAT_128 R(LispObject p, LispObject q)
    {   return LF_C(888.999);
    }
    static FLOAT_128 C(LispObject r, LispObject i)
    {   return LF_C(888.999);
    }
};

class Float_val
{
public:
    static constexpr const char* name = "float-val";
    static constexpr const unsigned int flags = 0;
    static double error(LispObject a)
    {   (void) aerror(name, " given non-number", a);
        return 0.0/0.0;
    }

    static double I(LispObject a)
    {   return (double)int_of_fixnum(a);
    }
    static double B(LispObject a)
    {   return 999.999;
    }
    static double S(LispObject a)
    {   return (double)short_float_val(a);
    }
    static double F(LispObject a)
    {   return (double)single_float_val(a);
    }
    static double D(LispObject a)
    {   return double_float_val(a);
    }
    static double L(LispObject a)
    {   return (double)long_float_val(a);
    }

    static double S(double a)
    {   return (double)a;
    }
    static double F(double a)
    {   return (double)a;
    }
    static double D(double a)
    {   return a;
    }
    static double L(FLOAT_128 a)
    {   return (double)a;
    }


    static double R(LispObject p, LispObject q)
    {   return LF_C(888.999);
    }
    static double C(LispObject r, LispObject i)
    {   return 999.999;
    }
};


template <typename op>
auto GX(LispObject a, LispObject b)
{   if (is_complex(a))
    {   if constexpr ((op::flags & (op_compare|op_commutes)) == op_compare)
             return aerror(op::name, "given complex argument", a, b);
        else
        {   if (is_complex(b))
                return op::CC(real_part(a), imag_part(a),
                              real_part(b), imag_part(b));
                else return op::CC(real_part(a), imag_part(a),
                                   b, fixnum_of_int(0));
        }
    }
    else if (is_complex(b))
    {   if constexpr ((op::flags & (op_compare|op_commutes)) == op_compare)
             return aerror(op::name, "given complex argument", a, b);
        else return op::CC(a, fixnum_of_int(0),
                           real_part(b), imag_part(b));
    }
// Now all cases of complex numbers have been handled. What is left are
// rational numbers and such floating point types as are not the simple
// double precision ones. For comparisons involving a mix of floating
// and rational values I make sure both args are rationals.
    if constexpr (op::flags & op_compare)
    {   if (is_ratio(a) && is_float(b))
        {   LispObject p, q;
            float_to_rational(G<Float_val>(b), p, q);
            return op::RR(numerator(a), denominator(a), p, q);
        }
        else if (is_float(a) && is_ratio(b))
        {   LispObject p, q;
            float_to_rational(G<Float_val>(a), p, q);
            return op::RR(p, q, numerator(b), denominator(b));
        }
    }
// Now that floating point comparisons have been sorted I can apply contagion
// to the longest floating point type present.
    if (is_long_float(a))
    {   if (is_long_float(b)) return op::LL(long_float_val(a), long_float_val(b));
        else return op::LL(long_float_val(a), G<Long_float_val>(b));
    }
    else if (is_long_float(b))
        return op::LL(G<Long_float_val>(a), long_float_val(b));
    if (is_double_float(a))
    {   if (is_double_float(b)) return op::DD(double_float_val(a), double_float_val(b));
        else return op::DD(double_float_val(a), G<Float_val>(b));
    }
    else if (is_double_float(b))
        return op::DD(G<Float_val>(a), double_float_val(b));
    if (is_single_float(a))
    {   if (is_single_float(b)) return op::FF(single_float_val(a), single_float_val(b));
        else return op::FF(single_float_val(a), G<Float_val>(b));
    }
    else if (is_single_float(b))
        return op::FF(G<Float_val>(a), single_float_val(b));
    if (is_short_float(a))
    {   if (is_short_float(b)) return op::SS(short_float_val(a), short_float_val(b));
        else return op::SS(short_float_val(a), G<Float_val>(b));
    }
    else if (is_short_float(b))
        return op::SS(G<Float_val>(a), short_float_val(b));
// The only legal cases that should remain involve rational numbers, combined
// either with others of the same sort or with integers.
    if (is_ratio(a))
    {   if (is_ratio(b)) return op::RR(numerator(a), denominator(a),
                                       numerator(b), denominator(b));
        else return op::RR(numerator(a), denominator(a),
                           b, fixnum_of_int(1));
    }
    else if (is_ratio(b))
        return op::RR(a, fixnum_of_int(1), numerator(a), denominator(a));
    else return aerror(op::name, "given non-integer argument", a, b);
}

// This function - G<op> - is always expanded in-line and tests for and
// dispatches on fixnums, bignums and double precision floats. If nothing
//  else is found it uses the II, IB, BI, BB or DD method in the class op.
//
// All other combinations and varieties of number are passed to the function
// GX which will not be forced inline. That knows that at least one argument
// is not one of the common cases, but it may need to repeat some tests since
// eg Fixnum+Rational and Bignum+Rational are passed down undeifferentiated.
// The intent is that integer arithmetic, and especially fixnum (ie small
// integer) work is performed as fast as possible.

inline LispObject float_to_bignum(double a)
{   return roundDoubleToInt(a);
}

inline LispObject float128_to_bignum(FLOAT_128 a)
{   return roundFloat128ToInt(a);
}

template <typename op>
[[gnu::always_inline]]
inline auto G(LispObject a, LispObject b)
{   if (is_fixnum(a)) LIKELY
    {
// My expectation is that op::II that combines two small integers will
// be the most heavily used path. 
        if (is_fixnum(b)) LIKELY  return op::II(a, b);
        else if (is_new_bignum(b)) return op::IB(a, b);
        else if (is_double_float(b))
        {   if constexpr (op::flags & op_int)
                return aerror(op::name, "given non-integer argument", a, b);
            else
            {
// If I have a comparison operation between a small integer and a
// float I will use the ID method. If the integer value is small
// enough it can be cmverted to a float without loss, but if it is
// big I will need to work towards converting to float to and integer.
                if constexpr (op::flags & op_compare)
                    return op::ID(int_of_fixnum(a), double_float_val(b));
// For non-comparison floating point operations I pass two unboxed
// double precision values to DD.
                else return op::DD(
                    (double)int_of_fixnum(a), double_float_val(b));
            }
        }
    }
    else if (is_new_bignum(a)) LIKELY
    {   if (is_fixnum(b)) LIKELY
            if constexpr (op::flags & op_commutes) return op::IB(b, a);
            else return op::BI(a, b);
        else if (is_new_bignum(b)) return op::BB(a, b);
        else if (is_double_float(b))
        {   if constexpr (op::flags & op_int)
                return aerror(op::name, "given non-integer argument", a, b);
            else
            {
// When I bignum is compared against a float I will use BD.
                if constexpr (op::flags & op_compare)
                    return op::BD(a, double_float_val(b));
// "ordinary" combinations of bignums and floats start by converting the
// bignum to a float - even if that overflows. There are of course cases
// where a bignum value is larger than the largest finite floating point
// number but the end-result of the calculation would have been in
// range. I am not going to go to the trouble of handling such cases
// in the way that I might view as ideal (but also as rather expensive).
                else return op::DD(
                    float_to_bignum(a), double_float_val(b));
            }
        }
    }
    if constexpr (op::flags & op_int)
    {   (void)aerror(op::name, "given non-integer argument", a, b);
        return op::II(fixnum_of_int(0), fixnum_of_int(0));
    }
    else
    {   if (is_double_float(a)) LIKELY
        {   if (is_double_float(b)) LIKELY
            {   return op::DD(
                    double_float_val(a), double_float_val(b));
            }
            else if (!is_complex(b))   
            {   return op::DD(
                    double_float_val(a), G<Float_val>(b));
            }
        }
        else if (is_double_float(b)) LIKELY
        {   if (!is_complex(a))   
            {   return op::DD(
                    G<Float_val>(a), double_float_val(b));
            }
        }
        return GX<op>(a, b);
    }
}

inline LispObject csl_bignum(uint64_t* a)
{   return TAG_NUMBERS + (uintptr_t)a - 8;
}

inline uint64_t* arithlib_bignum(LispObject a)
{   return (uint64_t*)(a - TAG_NUMBERS + 8);
}



// Now the cases that are in general top-level use.

class gPlus
{
public:
    static constexpr const char* name = "plus";
    static constexpr const unsigned int flags = op_commutes;

// Add two Fixnums - this is the case that I expect to be most common,
// and the path where there is no overflow so that the result is also
// a fixnum is the one to be most careful about.

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   intptr_t c;
        if (!__builtin_add_overflow((intptr_t)(a-TAG_FIXNUM), b, &c))
            LIKELY
            return c;
        uint64_t* r = reserve(1);
        r[0] = int_of_fixnum(a) + int_of_fixnum(b);
        return confirmSize(r, 1, 1);
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Plus::op(arithlib_bignum(b),
                                           int_of_fixnum(a));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Plus::op(arithlib_bignum(a),
                                           arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b)
    {   return make_boxfloat(a + b, WANT_SHORT_FLOAT);
    }

    static LispObject FF(double a, double b)
    {   return make_boxfloat(a + b, WANT_SINGLE_FLOAT);
    }

    static LispObject DD(double a, double b)
    {   return make_boxfloat(a + b);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   return make_boxfloat128(a + b);
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
    {   return make_complex(G<gPlus>(r1, r2), G<gPlus>(i1, i2));
    }
};


class gDifference
{
public:
    static constexpr const char* name = "difference";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   intptr_t c;
        if (!__builtin_sub_overflow(a, b, &c))
            LIKELY
            return c + TAG_FIXNUM;
        uint64_t* r = reserve(1);
        r[0] = int_of_fixnum(a) - int_of_fixnum(b);
        return confirmSize(r, 1, 1);
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Difference::op(int_of_fixnum(a),
                                                 arithlib_bignum(b));
    }

    static LispObject BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Difference::op(arithlib_bignum(a),
                                                 int_of_fixnum(b));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Difference::op(arithlib_bignum(a),
                                                 arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b)
    {   return make_boxfloat(a - b, WANT_SHORT_FLOAT);
    }

    static LispObject FF(double a, double b)
    {   return make_boxfloat(a - b, WANT_SINGLE_FLOAT);
    }

    static LispObject DD(double a, double b)
    {   return make_boxfloat(a - b);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   return make_boxfloat128(a - b);
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
    {   return make_complex(G<gDifference>(r1, r2), G<gDifference>(i1, i2));
    }
};

class gTimes
{
public:
    static constexpr const char* name = "times";
    static constexpr const unsigned int flags = op_commutes;

// Multiply two Fixnums - this is the case that I expect to be most common,
// and the path where there is no overflow so that the result is also
// a fixnum is the one to be most careful about.

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   intptr_t c;
        if (!__builtin_add_overflow((intptr_t)(a-TAG_FIXNUM), b, &c))
            LIKELY
            return c;
        uint64_t* r = reserve(1);
        r[0] = int_of_fixnum(a) + int_of_fixnum(b);
        return confirmSize(r, 1, 1);
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Times::op(int_of_fixnum(a),
                                            arithlib_bignum(b));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Times::op(arithlib_bignum(a),
                                           arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b)
    {   return make_boxfloat(a * b, WANT_SHORT_FLOAT);
    }

    static LispObject FF(double a, double b)
    {   return make_boxfloat(a * b, WANT_SINGLE_FLOAT);
    }

    static LispObject DD(double a, double b)
    {   return make_boxfloat(a * b);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   return make_boxfloat128(a * b);
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2)
    {
// (a + ib)*(c + id) = (a*c - b*d) * i(a*d + b*c)
// but I should really use fused-multiply-add operations when computing
// those components when dealinmg with floating point cases. For now I will
// not! To deal with that I should introruce a new operator that
// computes u*v+x*y using
//      w = u*v;                  // approx first product.
//      w1 = fma(u, v, -w);       // correction to it.
//      r = fma(x, y, w);         // leading digit cancellation handled well.
//      r + w1;                   // accurate result.
// or perhaps more probably a fused,multiply-add operator.
        LispObject r = G<gDifference>(G<gTimes>(r1, r2), G<gTimes>(i1, i2));
        LispObject i = G<gPlus>(G<gTimes>(r2, r2), G<gTimes>(i2, i2));
        return make_complex(r, i);
    }
};

class gQuotient
{
public:
    static constexpr const char* name = "quotient";
    static constexpr const unsigned int flags = 0;

// Divide two Fixnums - this is the case that I expect to be most common,
// and the path where there is no overflow so that the result is also
// a fixnum is the one to be most careful about.

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   return fixnum_of_int(
            int_of_fixnum(a) / int_of_fixnum(b));
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Quotient::op(int_of_fixnum(a),
                                               arithlib_bignum(b));
    }

    static LispObject BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Quotient::op(arithlib_bignum(a),
                                               int_of_fixnum(b));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Quotient::op(arithlib_bignum(a),
                                             arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b)
    {   return make_boxfloat(a / b, WANT_SHORT_FLOAT);
    }

    static LispObject FF(double a, double b)
    {   return make_boxfloat(a / b, WANT_SINGLE_FLOAT);
    }

    static LispObject DD(double a, double b)
    {   return make_boxfloat(a / b);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   return make_boxfloat128(a / b);
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gRemainder
{
public:
    static constexpr const char* name = "remainder";
    static constexpr const unsigned int flags = 0;
};

class gExpt
{
public:
    static constexpr const char* name = "expt";
    static constexpr const unsigned int flags = 0;
};

class gCLquotient
{
public:
    static constexpr const char* name = "CLquotient";
    static constexpr const unsigned int flags = 0;
};

class gClassicalTimes
{
public:
    static constexpr const char* name = "classicaltimes";
    static constexpr const unsigned int flags = 0;
};

class gDivide
{
public:
    static constexpr const char* name = "divide";
    static constexpr const unsigned int flags = 0;
};

class gMod
{
public:
    static constexpr const char* name = "mod";
    static constexpr const unsigned int flags = 0;
};

class gGcdn
{
public:
    static constexpr const char* name = "gcdn";
    static constexpr const unsigned int flags = op_commutes | op_int;

// Form the GCD of two integers.

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   intptr_t aa = int_of_fixnum(a),
                 bb = int_of_fixnum(b);
        if (aa < 0) aa = -aa;
        if (bb < 0) bb = -bb;
        if (bb > aa) std::swap(aa, bb);
// Do simple Euclidean algorithm
        while (bb != 0)
        {   Digit cc = aa % bb;
            aa = bb;
            bb = cc;
        }
// A pathological case here is when both inputs had been the
// most negative fixnum, in which case the result will be the absolute
// value of that -- which has to be returned as a bignum.
        LispObject r = fixnum_of_int(aa);
        if ((intptr_t)r >= 0) LIKELY return r;
// here is the overflow case.
        uint64_t* big = reserve(1);
        big[0] = aa;
        return confirmSize(big, 1, 1);
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Gcd::op(arithlib_bignum(b),
                                          int_of_fixnum(a));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Gcd::op(arithlib_bignum(a),
                                          arithlib_bignum(b));
    }   
};

class gLcmn
{
public:
    static constexpr const char* name = "lcmn";
    static constexpr const unsigned int flags = 0;
};

class gBitand
{
public:
    static constexpr const char* name = "bitand";
    static constexpr const unsigned int flags = 0;
};

class gBitor
{
public:
    static constexpr const char* name = "bitor";
    static constexpr const unsigned int flags = 0;
};

class gBiteqv
{
public:
    static constexpr const char* name = "biteqv";
    static constexpr const unsigned int flags = 0;
};

class gBitneqv
{
public:
    static constexpr const char* name = "bitneqv";
    static constexpr const unsigned int flags = 0;
};

class gLogbitp
{
public:
    static constexpr const char* name = "logbitp";
    static constexpr const unsigned int flags = 0;
};

class gLessp
{
public:
    static constexpr const char* name = "lessp";
    static constexpr const unsigned int flags = 0;
};

class gLeq
{
public:
    static constexpr const char* name = "leq";
    static constexpr const unsigned int flags = 0;
};

class gEqn
{
public:
    static constexpr const char* name = "eqn";
    static constexpr const unsigned int flags = 0;
};

class gCLeqn
{
public:
    static constexpr const char* name = "CLeqn";
    static constexpr const unsigned int flags = 0;
};

class gNeq
{
public:
    static constexpr const char* name = "neqn";
    static constexpr const unsigned int flags = 0;
};

class gGeq
{
public:
    static constexpr const char* name = "geq";
    static constexpr const unsigned int flags = 0;
};

class gGreaterp
{
public:
    static constexpr const char* name = "greaterp";
    static constexpr const unsigned int flags = 0;
};

class gLeftshift
{
public:
    static constexpr const char* name = "leftshift";
    static constexpr const unsigned int flags = 0;
};

class gRightshift
{
public:
    static constexpr const char* name = "rightshift";
    static constexpr const unsigned int flags = 0;
};

class gIplus
{
public:
    static constexpr const char* name = "iplus";
    static constexpr const unsigned int flags = 0;
};

class gIdifference
{
public:
    static constexpr const char* name = "idifference";
    static constexpr const unsigned int flags = 0;
};

class gItimes
{
public:
    static constexpr const char* name = "itimes";
    static constexpr const unsigned int flags = 0;
};

class gIquotient
{
public:
    static constexpr const char* name = "iquotient";
    static constexpr const unsigned int flags = 0;
};

class gIlessp
{
public:
    static constexpr const char* name = "ilessp";
    static constexpr const unsigned int flags = 0;
};

class gIleq
{
public:
    static constexpr const char* name = "ileq";
    static constexpr const unsigned int flags = 0;
};

class gIgreaterp
{
public:
    static constexpr const char* name = "igreaterp";
    static constexpr const unsigned int flags = 0;
};

class gIgeq
{
public:
    static constexpr const char* name = "igeq";
    static constexpr const unsigned int flags = 0;
};

class gModular_plus
{
public:
    static constexpr const char* name = "modular-plus";
    static constexpr const unsigned int flags = 0;
};

class gModular_difference
{
public:
    static constexpr const char* name = "modular-difference";
    static constexpr const unsigned int flags = 0;
};

class gModular_times
{
public:
    static constexpr const char* name = "modular-times";
    static constexpr const unsigned int flags = 0;
};

class gModular_quotient
{
public:
    static constexpr const char* name = "modular-quotient";
    static constexpr const unsigned int flags = 0;
};

class gModular_expt
{
public:
    static constexpr const char* name = "modular-expt";
    static constexpr const unsigned int flags = 0;
};

class gFloor
{
public:
    static constexpr const char* name = "floor";
    static constexpr const unsigned int flags = 0;
};

class gCeiling
{
public:
    static constexpr const char* name = "ceiling";
    static constexpr const unsigned int flags = 0;
};

class gTrunc
{
public:
    static constexpr const char* name = "trunc";
    static constexpr const unsigned int flags = 0;
};

class gRound
{
public:
    static constexpr const char* name = "round";
    static constexpr const unsigned int flags = 0;
};

class gFfloor
{
public:
    static constexpr const char* name = "ffloor";
    static constexpr const unsigned int flags = 0;
};

class gFceiling
{
public:
    static constexpr const char* name = "fceiling";
    static constexpr const unsigned int flags = 0;
};

class gFtrunc
{
public:
    static constexpr const char* name = "ftrunc";
    static constexpr const unsigned int flags = 0;
};

class gFround
{
public:
    static constexpr const char* name = "fround";
    static constexpr const unsigned int flags = 0;
};

class gAdd1
{
public:
    static constexpr const char* name = "add1";
    static constexpr const unsigned int flags = 0;
};

class gSub1
{
public:
    static constexpr const char* name = "sub1";
    static constexpr const unsigned int flags = 0;
};

class gZerop
{
public:
    static constexpr const char* name = "zerop";
    static constexpr const unsigned int flags = 0;

    static bool I(LispObject a)
    {   return a == fixnum_of_int(0);
    }

    static bool B(LispObject a)
    {   return false;
    }

    static bool S(LispObject a)
    {   return short_float_val(a) == 0.0;
    }

    static bool F(LispObject a)
    {   return single_float_val(a) == 0.0;
    }

    static bool D(LispObject a)
    {   return double_float_val(a) == 0.0;
    }

    static bool L(LispObject a)
    {   return long_float_val(a) == LF_C(0.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return p == fixnum_of_int(0) &&
               q != fixnum_of_int(0);
    }

    static bool C(LispObject r, LispObject i)
    {   return G<gZerop>(r) && G<gZerop>(i);
    }
};

class gOnep
{
public:
    static constexpr const char* name = "onep";
    static constexpr const unsigned int flags = 0;

    static bool I(LispObject a)
    {   return a == fixnum_of_int(1);
    }

    static bool B(LispObject a)
    {   return false;
    }

    static bool S(LispObject a)
    {   return short_float_val(a) == 1.0;
    }

    static bool F(LispObject a)
    {   return single_float_val(a) == 1.0;
    }

    static bool D(LispObject a)
    {   return double_float_val(a) == 1.0;
    }

    static bool L(LispObject a)
    {   return long_float_val(a) == LF_C(1.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return p == fixnum_of_int(1) &&
               q == fixnum_of_int(1);
    }

    static bool C(LispObject r, LispObject i)
    {   return G<gOnep>(r) && G<gZerop>(i);
    }
};

class gMinusonep
{
public:
    static constexpr const char* name = "minusonep";
    static constexpr const unsigned int flags = 0;

    static bool I(LispObject a)
    {   return a == fixnum_of_int(-1);
    }

    static bool B(LispObject a)
    {   return false;
    }

    static bool S(LispObject a)
    {   return short_float_val(a) == -1.0;
    }

    static bool F(LispObject a)
    {   return single_float_val(a) == -1.0;
    }

    static bool D(LispObject a)
    {   return double_float_val(a) == -1.0;
    }

    static bool L(LispObject a)
    {   return long_float_val(a) == -LF_C(1.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return p == fixnum_of_int(-1) &&
               q == fixnum_of_int(1);
    }

    static bool C(LispObject r, LispObject i)
    {   return G<gMinusonep>(r) && G<gZerop>(i);
    }
};

class gMinus
{
public:
    static constexpr const char* name = "minus";
    static constexpr const unsigned int flags = 0;

    static LispObject I(LispObject a)
    {
// If you negate the most-negative fixnum it has to turn into a bignum.
        intptr_t n = int_of_fixnum(a);
        if (n == int_of_fixnum(INTPTR_MIN)) UNLIKELY
        {   uintptr_t* r = reserve(1);
            r[0] = -n;
            return confirmSize(r, 1, 1);
        }
        else return fixnum_of_int(-n);
    }

    static LispObject B(LispObject a)
    {   return arithlib_implementation::Minus::op(arithlib_bignum(a));
    }

    static LispObject S(LispObject a)
    {   return pack_short_float(-short_float_val(a));
    }

    static LispObject F(LispObject a)
    {   return pack_single_float(-single_float_val(a));
    }

    static LispObject D(LispObject a)
    {   return make_boxfloat(-double_float_val(a));
    }

    static LispObject L(LispObject a)
    {   return make_boxfloat128(-long_float_val(a)); 
    }

    static LispObject R(LispObject p, LispObject q)
    {   return make_ratio(G<gMinus>(p), q);
    }

    static LispObject C(LispObject r, LispObject i)
    {   return make_complex(G<gMinus>(r), G<gMinus>(i));
    }

};

class gMinusp
{
public:
    static constexpr const char* name = "minusp";
    static constexpr const unsigned int flags = op_compare;

    static bool I(LispObject a)
    {   return (int64_t)a < 0;
    }

    static bool B(LispObject a)
    {   uint64_t* p = arithlib_bignum(a);
        return (SignedDigit)p[numberSize(p)-1] < 0;;
    }

    static bool S(LispObject a)
    {   return short_float_val(a) < 0.0;
    }

    static bool F(LispObject a)
    {   return single_float_val(a) < 0.0;
    }

    static bool D(LispObject a)
    {   return double_float_val(a) < 0.0;
    }

    static bool L(LispObject a)
    {   return long_float_val(a) , LF_C(0.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return G<gMinusp>(p);
    }
};

class gAbs
{
public:
    static constexpr const char* name = "abs";
    static constexpr const unsigned int flags = 0;
};

class gSquare
{
public:
    static constexpr const char* name = "square";
    static constexpr const unsigned int flags = 0;
};

class gBitnot
{
public:
    static constexpr const char* name = "bitnot";
    static constexpr const unsigned int flags = 0;
};

class gReciprocal
{
public:
    static constexpr const char* name = "reciprocal";
    static constexpr const unsigned int flags = 0;
};

class gModular_minus
{
public:
    static constexpr const char* name = "modular-minus";
    static constexpr const unsigned int flags = 0;
};

class gModular_reciprocal
{
public:
    static constexpr const char* name = "modular-reciprocal";
    static constexpr const unsigned int flags = 0;
};

class gSafe_modular_reciprocal
{
public:
    static constexpr const char* name = "safe-modular6-reciprocal";
    static constexpr const unsigned int flags = 0;
};

class gSetmodulus
{
public:
    static constexpr const char* name = "setmodulua";
    static constexpr const unsigned int flags = 0;
};

class gModularnumber
{
public:
    static constexpr const char* name = "modular-number";
    static constexpr const unsigned int flags = 0;
};

class gFix
{
public:
    static constexpr const char* name = "fix";
    static constexpr const unsigned int flags = 0;
};

class gFloat
{
public:
    static constexpr const char* name = "float";
    static constexpr const unsigned int flags = 0;
};

class gShort_float
{
public:
    static constexpr const char* name = "short-float";
    static constexpr const unsigned int flags = 0;
};

class gSingle_float
{
public:
    static constexpr const char* name = "single-float";
    static constexpr const unsigned int flags = 0;
};

class gLong_float
{
public:
    static constexpr const char* name = "long-float";
    static constexpr const unsigned int flags = 0;
};

class gSqrt
{
public:
    static constexpr const char* name = "sqrt";
    static constexpr const unsigned int flags = 0;
};

class gIsqrt
{
public:
    static constexpr const char* name = "isqrt";
    static constexpr const unsigned int flags = 0;
};

// Now some more implementation. Where it seems to make sense I have put
// method definitions within the classes, however to cope with what
// might be forward references I need to put some down here.


inline LispObject gPlus::RR(LispObject p1, LispObject q1,
                            LispObject p2, LispObject q2)
{
// p1/q1 + p2/q2 will have denominator (q1*q2)/g where g = gcd(q1,q2) and
// numerator (p1*(q2/g) - p2*(q1/g) but reduced to lowest terms.
    LispObject g = G<gGcdn>(q1, q2);
    LispObject q1a = G<gQuotient>(q1, g);
    LispObject q2a = G<gQuotient>(q2, g);
    LispObject p = G<gDifference>(G<gTimes>(p1, q2a), G<gTimes>(p2, q1a));
    LispObject q = G<gTimes>(q1, q2a);
    g = G<gGcdn>(p, q);
    return make_ratio(G<gQuotient>(p, g), G<gQuotient>(q, g));
}

inline LispObject gDifference::RR(LispObject p1, LispObject q1,
                                  LispObject p2, LispObject q2)
{
// p1/q1 + p2/q2 will have denominator (q1*q2)/g where g = gcd(q1,q2) and
// numerator (p1*(q2/g) + p2*(q1/g) but reduced to lowest terms.
    LispObject g = G<gGcdn>(q1, q2);
    LispObject q1a = G<gQuotient>(q1, g);
    LispObject q2a = G<gQuotient>(q2, g);
    LispObject p = G<gPlus>(G<gTimes>(p1, q2a), G<gTimes>(p2, q1a));
    LispObject q = G<gTimes>(q1, q2a);
    g = G<gGcdn>(p, q);
    return make_ratio(G<gQuotient>(p, g), G<gQuotient>(q, g));
}


inline LispObject gTimes::RR(LispObject p1, LispObject q1,
                             LispObject p2, LispObject q2)
{
// (p1/q1) * (p2/q2) => ((p1/g1)*(p2/g2)) / ((q1/g2)*(q2/g1))
// where g1=gcd(p1,q2) and g2=gcd(p2,q1)
    LispObject g1 = G<gGcdn>(p1, q2);
    LispObject g2 = G<gGcdn>(p2, q1);
    LispObject p = G<gTimes>(G<gQuotient>(p1, g1),
                             G<gQuotient>(p2, g2));
    LispObject q = G<gTimes>(G<gQuotient>(q1, g2),
                             G<gQuotient>(q2, g1));
    return make_ratio(p, q);
}

inline LispObject gQuotient::RR(LispObject p1, LispObject q1,
                                LispObject p2, LispObject q2)
{   if (G<gMinusp>(p2))
        return gTimes::RR(p1, q1, G<gMinus>(q2), G<gMinus>(p2));
    else return gTimes::RR(p1, q1, q2, p2);
}

inline LispObject gQuotient::CC(LispObject r1, LispObject i1,
                                LispObject r2, LispObject i2)
{
// (a+ib)/(c+id) can be calculated by multiplying numerator and
// denominator by (c-id) to get
//    ((a+ib)*(c-id)) / (c^2+d^2)
// Note that as for complex multiplication the numerator should be
// calculated using fused-multiply-add in floating point cases. Also
// if c or d are rather extreme values c^2+d^2 or the numerator may
// underfow or overflow prematurely, so a proper implementation
// will scale values early on.
// Also the code that dispatches will tend to pass values with
// zero imaginary part, so I deal with that specially here.
    if (G<gZerop>(i2))
        return make_complex(G<gQuotient>(r1, r2), G<gQuotient>(i1, r2));
    LispObject p = gTimes::CC(r1, i1, r2, G<gMinus>(i2));
    LispObject q = G<gPlus>(G<gTimes>(r1, r2), G<gTimes>(i1, i2));
    return make_complex(G<gQuotient>(real_part(p), q),
                        G<gQuotient>(imag_part(p), q));
}

} // end of namespace

#endif // __header_generic_h

// end of generic.h

