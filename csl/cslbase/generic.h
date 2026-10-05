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
//                             be indentified using a combination of the
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
//      CLQuotient
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
//      Ftruncuncate
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
//      Plusp
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
//      Truncate

//      Zerop

// Here I am going to use a mnemonic in function names:
//    I integer
//    B bignum
//    S short float   (28 bits)
//    F single float  (32 bits)
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
// cases I care about the most first.

template <typename op>
[[gnu::always_inline]]
inline auto G(LispObject a)
{   if (is_fixnum(a)) LIKELY return op::I(a);
    else if constexpr (op::flags & op_fixnum)
        aerror(op::name, "given non-fixnum argument", a);
    else
    {   if (is_new_bignum(a)) LIKELY return op::B(a);
        else if constexpr (op::flags & op_int)
            aerror(op::name, "given non-integer argument", a);
        else
        {   if (is_double_float(a)) LIKELY return op::D(double_float_val(a));
            else if (is_ratio(a)) LIKELY return op::R(numerator(a), denominator(a));
            else if (is_long_float(a)) LIKELY return op::L(long_float_val(a));
            else if (is_single_float(a)) LIKELY return op::S(single_float_val(a));
            else if (is_short_float(a)) LIKELY return op::F(short_float_val(a));
            if constexpr ((op::flags & op_compare) == 0)
            {   if (is_complex(a)) return op::C(real_part(a), imag_part(a));
            }
            aerror(op::name, a);
        }
    }
}

// For GX<op>(a, b) at least one of a, b is complex, rational or
// a float that is not the simple double precision sort. I view these
// as less performance critical than the cases handled in G<op>.

extern void float_to_rational(double f, LispObject& p, LispObject& q);
extern void float128_to_rational(FLOAT_128 f, LispObject& p, LispObject& q);

#define pending() { Lenable_errorset(nil,                \
                                     fixnum_of_int(3),   \
                                     fixnum_of_int(3));  \
                    aerror(where(name)); }

class Long_float_val
{
public:
    static constexpr const char* name = "long-float-val";
    static constexpr const unsigned int flags = 0;
    static FLOAT_128 error(LispObject a)
    {   aerror(name, " given non-number", a);
    }
    static FLOAT_128 I(LispObject a)
    {   return (FLOAT_128)int_of_fixnum(a);
    }
    static FLOAT_128 B(LispObject a)
    {   pending();
    }
    static FLOAT_128 S(double a)
    {   return (FLOAT_128)a;
    }
    static FLOAT_128 F(double a)
    {   return (FLOAT_128)a;
    }
    static FLOAT_128 D(double a)
    {   return (FLOAT_128)a;
    }
    static FLOAT_128 L(FLOAT_128 a)
    {   return a;
    }
    static FLOAT_128 R(LispObject p, LispObject q)
    {   pending();
    }
    static FLOAT_128 C(LispObject r, LispObject i)
    {   pending();
    }
};

class Float_val
{
public:
    static constexpr const char* name = "float-val";
    static constexpr const unsigned int flags = 0;
    static double error(LispObject a)
    {   aerror(name, " given non-number", a);
    }
    static double I(LispObject a)
    {   return (double)int_of_fixnum(a);
    }
    static double B(LispObject a)
    {   return 999.999;
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
    {   pending();
    }
    static double C(LispObject r, LispObject i)
    {   pending();
    }
};


template <typename op>
auto GX(LispObject a, LispObject b)
{
// If one arg is complex and the other not I widen the simpler one to
// give it an explicit zero imaginary part, then I have two complex value
// to handle. The code that handles that may sometimes detect the case
// of a zero imaginary part and do something special...
    if (is_complex(a))
    {   if constexpr ((op::flags & (op_compare|op_commutes)) == op_compare)
             aerror(op::name, "given complex argument", a, b);
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
             aerror(op::name, "given complex argument", a, b);
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
// to the longest floating point type present. Well sorry, there is one more
// special case. If I do a comparison between any sort of float and an
// integer (big or smnall) I need to deal with that specially because
// promoting the integer to a float might lose accuuracy. So I will use
// methods called DI and DB. Note that the cases where th4e integer is the
// first argument had been handled earlier.
    if constexpr (op::flags & op_compare)
    {   if (is_fixnum(b))
        {   if (is_double_float(a)) return op::DI(double_float_val(a), b);
            else if (is_single_float(a)) return op::DI(single_float_val(a), b);
            else if (is_short_float(a)) return op::DI(short_float_val(a), b);
            else if (is_long_float(a)) return op::LI(long_float_val(a), b);
        }
        else if (is_new_bignum(b))
        {   if (is_double_float(a)) return op::DB(double_float_val(a), b);
            else if (is_single_float(a)) return op::DB(single_float_val(a), b);
            else if (is_short_float(a)) return op::DB(short_float_val(a), b);
            else if (is_long_float(a)) return op::LB(long_float_val(a), b);
        }
    }
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
    else aerror(op::name, "given non-integer argument", a, b);
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
// If I have a comparison operation between a small integer and a
// float I will use the ID method. If the integer value is small
// enough it can be cmverted to a float without loss, but if it is
// big I will need to work towards converting to float to and integer.
        if constexpr (op::flags & op_compare)
        {   if (is_double_float(b))
                return op::ID(a, double_float_val(b));
            if (is_single_float(b))
                return op::ID(a, single_float_val(b));
            if (is_short_float(b))
                return op::ID(a, short_float_val(b));
            if (is_long_float(b))
                return op::IL(a, long_float_val(b));
        }
        else if (is_double_float(b))
        {   if constexpr (op::flags & op_int)
                aerror(op::name, "given non-integer argument", a, b);
// For non-comparison floating point operations I pass two unboxed
// double precision values to DD.
            else return op::DD(
                (double)int_of_fixnum(a), double_float_val(b));
        }
    }
    else if (is_new_bignum(a)) LIKELY
    {   if (is_fixnum(b)) LIKELY
        {   if constexpr (op::flags & op_commutes) return op::IB(b, a);
            else return op::BI(a, b);
        }
        if (is_new_bignum(b)) return op::BB(a, b);
        if constexpr (op::flags & op_compare)
        {   if (is_double_float(b))
                return op::BD(a, double_float_val(b));
            if (is_single_float(b))
                return op::BD(a, single_float_val(b));
            if (is_short_float(b))
                return op::BD(a, short_float_val(b));
            if (is_long_float(b))
                return op::BL(a, long_float_val(b));
        }
        else if (is_double_float(b))
        {   if constexpr (op::flags & op_int)
                aerror(op::name, "given non-integer argument", a, b);
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
        aerror(op::name, "given non-integer argument", a, b);
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
        if (!__builtin_mul_overflow((intptr_t)(a-TAG_FIXNUM),
                                    int_of_fixnum(b),
                                    &c))
            LIKELY
            return c + TAG_FIXNUM;
// Here the prodict is at least 2^59 and occasionally it will fit into
// a 1-word bignum, but probably more often into a 2-word one.
        SignedDigit hi;
        Digit lo;
        signedMultiply64(int_of_fixnum(a), int_of_fixnum(b), hi, lo);
        if ((hi==0 && positive(lo)) ||
            (hi==-1 && negative(lo))) UNLIKELY
        {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
                LIKELY
                return intToHandle(static_cast<SignedDigit>(lo));
            std::uint64_t* r = reserve(1);
            r[0] = lo;
            return confirmSize(r, 1, 1);
        }
        std::uint64_t* r = reserve(2);
        r[0] = lo;
        r[1] = hi;
        return confirmSize(r, 2, 2);
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
// Well the most negative fixnum divided by -1 has to turn into a bignum.
// Yuk!

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   if (a == MOST_NEGATIVE_FIXNUM &&
            b == fixnum_of_int(-1))
        {   return make_lisp_integer64(-(int64_t)int_of_fixnum(a));
        }
        intptr_t aa = int_of_fixnum(a);
        intptr_t bb = int_of_fixnum(b);
        if (bb == 0) aerror("Attempt to divide by zero");
        return fixnum_of_int(aa / bb);
    }

// If you divide -N by N where -N is the most negative fixnum and hence N
// is a bignum you get the result -1. Otherwise dividing an integer by
// a bignum will yield zero;

    static LispObject IB(LispObject a, LispObject b)
    {   uint64_t* bb = arithlib_bignum(b);
        if (a == MOST_NEGATIVE_FIXNUM &&
            numberSize(bb) == 1 &&
            bb[0] == (uint64_t)(-int_of_fixnum(a)))
            return fixnum_of_int(-1);
        else return fixnum_of_int(0);
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
    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   return fixnum_of_int(
            int_of_fixnum(a) % int_of_fixnum(b));
    }

// In general when you divide a fixnum a by a bignum b you get a quotient
// that is zero, so the remainder will be just a. There is one special case
// where a is the most negative fixnum and b is its absolute value (which
// oveflows to become a bignum). Then the quotient is -1 and the remainder
// is 0.3
    static LispObject IB(LispObject a, LispObject b)
    {   uint64_t* bb = arithlib_bignum(b);
        if (a == MOST_NEGATIVE_FIXNUM &&
            numberSize(bb) == 1 &&
            bb[0] == (uint64_t)(-int_of_fixnum(a)))
            return fixnum_of_int(0);
        else return a;
    }

    static LispObject BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Remainder::op(arithlib_bignum(a),
                                               int_of_fixnum(b));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Remainder::op(arithlib_bignum(a),
                                               arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b)
    {   double q = round_to_short(a/b);
        return make_boxfloat(std::fma(b, -q, a), WANT_SHORT_FLOAT);
    }

    static LispObject FF(double a, double b)
    {   double q = (double)(float)(a/b);
        return make_boxfloat(std::fma(b, -q, a), WANT_SINGLE_FLOAT);
    }

    static LispObject DD(double a, double b)
    {   return make_boxfloat(std::fma(b, -a/b, a));
    }

    static FLOAT_128 remainder(FLOAT_128 p, FLOAT_128 q)
    {   FLOAT_128 r = p/q;
        return fma(q, -r, p);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   return make_boxfloat128(remainder(a, b));
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gExpt
{
public:
    static constexpr const char* name = "expt";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gCLQuotient
{
public:
    static constexpr const char* name = "CLQuotient";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

// This is for testing and comparison - it multiplies (just) integers
// and it uses simple classical algorithms for big arithmetic.

class gClassicalTimes
{
public:
    static constexpr const char* name = "classicaltimes";
    static constexpr const unsigned int flags = op_commutes | op_int;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   intptr_t c;
        if (!__builtin_mul_overflow((intptr_t)(a-TAG_FIXNUM),
                                    int_of_fixnum(b),
                                    &c))
            LIKELY
            return c + TAG_FIXNUM;
// Here the prodict is at least 2^59 and occasionally it will fit into
// a 1-word bignum, but probably more often into a 2-word one.
        SignedDigit hi;
        Digit lo;
        signedMultiply64(int_of_fixnum(a), int_of_fixnum(b), hi, lo);
        if ((hi==0 && positive(lo)) ||
            (hi==-1 && negative(lo))) UNLIKELY
        {   if (fitsIntoFixnum(static_cast<SignedDigit>(lo)))
                LIKELY
                return intToHandle(static_cast<SignedDigit>(lo));
            std::uint64_t* r = reserve(1);
            r[0] = lo;
            return confirmSize(r, 1, 1);
        }
        std::uint64_t* r = reserve(2);
        r[0] = lo;
        r[1] = hi;
        return confirmSize(r, 2, 2);
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::ClassicalTimes::op(int_of_fixnum(a),
                                                     arithlib_bignum(b));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::ClassicalTimes::op(arithlib_bignum(a),
                                                     arithlib_bignum(b));
    }
};

class gDivide
{
public:
    static constexpr const char* name = "divide";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   if (a == MOST_NEGATIVE_FIXNUM &&
            b == fixnum_of_int(-1))
        {   return cons(make_lisp_integer64(-(int64_t)int_of_fixnum(a)),
                        fixnum_of_int(0));
        }
        intptr_t aa = int_of_fixnum(a);
        intptr_t bb = int_of_fixnum(b);
        if (bb == 0) aerror("Attempt to divide by zero");
        intptr_t q = aa/bb;
        intptr_t r = aa%bb;
        return cons(fixnum_of_int(q), fixnum_of_int(r));
    }

    static LispObject IB(LispObject a, LispObject b)
    {      uint64_t* bb = arithlib_bignum(b);
        if (a == MOST_NEGATIVE_FIXNUM &&
            numberSize(bb) == 1 &&
            bb[0] == (uint64_t)(-int_of_fixnum(a)))
            return cons(fixnum_of_int(-1), fixnum_of_int(0));
        else return cons(fixnum_of_int(0), a);
    }

    static LispObject BI(LispObject a, LispObject b)
    {   return cons(arithlib_lowlevel::Quotient::op(arithlib_bignum(a),
                                                    int_of_fixnum(b)),
                    arithlib_lowlevel::Remainder::op(arithlib_bignum(a),
                                                     int_of_fixnum(b)));
    }

    static LispObject BB(LispObject a, LispObject b)
    {   return cons(arithlib_lowlevel::Quotient::op(arithlib_bignum(a),
                                                    arithlib_bignum(b)),
                    arithlib_lowlevel::Remainder::op(arithlib_bignum(a),
                                                    arithlib_bignum(b)));
    }   

    static double quotrem28(double p, double q, double& quotient)
    {   double r = round_to_short(p/q);
        return std::fma(q, -r, p);
    }

    static double quotrem32(double p, double q, double& quotient)
    {   quotient = (double)(float)(p/q);
        return std::fma(q, -quotient, p);
    }

    static double quotrem(double p, double q, double& quotient)
    {   quotient = p/q;
        return std::fma(q, -quotient, p);
    }

    static LispObject SS(double a, double b)
    {   double q, r;
        r = quotrem28(a, b, q);
        return cons(make_boxfloat(q, WANT_SHORT_FLOAT),
                    make_boxfloat(r, WANT_SHORT_FLOAT));
    }

    static LispObject FF(double a, double b)
    {   double q, r;
        r = quotrem32(a, b, q);
        return cons(make_boxfloat(q, WANT_SINGLE_FLOAT),
                    make_boxfloat(r, WANT_SINGLE_FLOAT));
    }

    static LispObject DD(double a, double b)
    {   double q, r;
        r = quotrem(a, b, q);
        return cons(make_boxfloat(q), make_boxfloat(r));
    }

    static FLOAT_128 quotrem(FLOAT_128 p, FLOAT_128 q, FLOAT_128& quotient)
    {   FLOAT_128 r = p/q;
        return fma(q, -r, p);
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   FLOAT_128 q, r;
        r = quotrem(a, b, q);
        return cons(make_boxfloat128(q), make_boxfloat128(r));
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gMod
{
public:
    static constexpr const char* name = "mod";
    static constexpr const unsigned int flags = op_int;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
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
    static constexpr const unsigned int flags = op_int | op_commutes;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   if (a == fixnum_of_int(0)) return b;
        if (b == fixnum_of_int(0)) return a;
        intptr_t aa = int_of_fixnum(a);
        intptr_t bb = int_of_fixnum(b);
        if (aa < 0) aa = -aa;
        if (bb < 0) bb = -bb;
        if (bb > aa) std::swap(aa, bb);
        while (bb != 0)
        {   intptr_t c = aa%bb;
            aa = bb;
            bb = c;
        }
        if ((a < 0) != (b<0)) aa = -aa;   // so sign of result is +ve.
// return a*(b/gcd(a,b))
        return gTimes::II(a, fixnum_of_int(int_of_fixnum(b)/aa));
    }

    static LispObject IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Plus::op(int_of_fixnum(a),
                                           arithlib_bignum(b));
    }

    static LispObject BI(LispObject a, LispObject b);

    static LispObject BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Lcm::op(arithlib_bignum(a),
                                          arithlib_bignum(b));
    }   

    static LispObject SS(double a, double b);

    static LispObject FF(double a, double b);

    static LispObject DD(double a, double b);

    static LispObject LL(FLOAT_128 a, FLOAT_128 b);
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gBitand
{
public:
    static constexpr const char* name = "bitand";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gBitor
{
public:
    static constexpr const char* name = "bitor";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gBiteqv
{
public:
    static constexpr const char* name = "biteqv";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gBitneqv
{
public:
    static constexpr const char* name = "bitneqv";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
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
    static constexpr const unsigned int flags = op_compare;

    [[gnu::always_inline]]
    static bool II(LispObject a, LispObject b)
    {   return a < b;
    }

    static bool IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Lessp::op(int_of_fixnum(a),
                                            arithlib_bignum(b));
    }

    static bool BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Lessp::op(arithlib_bignum(a),
                                            int_of_fixnum(b));
    }

    static bool BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Lessp::op(arithlib_bignum(a),
                                            arithlib_bignum(b));
    }   

    static bool ID(LispObject a, double b)
    {   int64_t aa = int_of_fixnum(a);
// I will provide a commentary here, but in later comparisons where I
// use similar code I will not even put a reference back to here. COmparing
// a 64-bit integer and a 64-bit float is not totally trivial. Start my
// mapping the integer to a float. It is value is greater than 2^53 this
// can lead to rounding. If the floating point value is not exactly equal
// to the true integer value it will be one of the pair of adjacent floating
// values one below and one above the true value.
        double da = (double)aa;
// ... thus if this value is strictly less than the floating point number b
// the integer will be. Here is a picture. If I is the integer and the two
// X symbols mark adjacent floating point numbers then any value strictly
// greater than the lower X must be at least the larget X and hence greater
// than I.
//               ...,,X.....I..X........X........X
//                    ?b       ?b       ?b       ?b
        if (da < b) return true;
// Conversely if da > b then a > b. But given that I know it is not < I will
// use a != test since that makes the case of b being a NaN work out correctly.
        if (da != b) return false;
// Now we know that da == b, with da being either a rounded up or down a bit.
// So b is very close to a. And we cal ALMOST go ib = (int64_t)b and then do
// an integer comparison. Howevert there is just one bad case, which is when
// b = 2^63 in which case turning it into an intewger would overflow. Note
// that b = -2^63 would be safe! SO I have to hanbdle the case b == 2^63
// specially!
        if (b == 0x1.0p+63) return true;
        else return aa < (int64_t)b;
    }

// Every fixnum can be converted to a FLOAT_128 without any loss, so this
// case is easy.

    static bool IL(LispObject a, FLOAT_128 b)
    {   return (FLOAT_128)a < b;
    }

    static bool BD(LispObject a, double b)
    {   return arithlib_lowlevel::Lessp::op(arithlib_bignum(a), b);
    }   

    static bool BL(LispObject a, FLOAT_128 b)
    {   aerror("not done yet");
    }

    static bool DI(double a, LispObject b)
    {   int64_t bb = int_of_fixnum(b);
        double db = (double)bb;
        if (a < db) return true;
        if (a != db) return false;
        if (a == 0x1.0p+63) return false;
        else return (int64_t)a < bb;
    }

    static bool LI(FLOAT_128 a, LispObject b)
    {   return a < (FLOAT_128)int_of_fixnum(b);
    }

    static bool DB(double a, LispObject b)
    {   return arithlib_lowlevel::Lessp::op(a, arithlib_bignum(b));
    }   

    static bool LB(FLOAT_128 a, LispObject b)
    {   pending();
    }

    static bool SS(double a, double b)
    {   return a < b;
    }

    static bool FF(double a, double b)
    {   return a < b;
    }

    static bool DD(double a, double b)
    {   return a < b;
    }

    static bool LL(FLOAT_128 a, FLOAT_128 b)
    {   return a < b;
    }
 
    static bool RR(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2)
    {   return G<gLessp>(
            G<gTimes>(p1, q2),
            G<gTimes>(p2, q1));
    }

    static bool CC(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2);   // Unused
};

class gLeq
{
public:
    static constexpr const char* name = "leq";
    static constexpr const unsigned int flags = op_compare;

    [[gnu::always_inline]]
    static bool II(LispObject a, LispObject b)
    {   return a <= b;
    }

    static bool IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Leq::op(int_of_fixnum(a),
                                          arithlib_bignum(b));
    }

    static bool BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Leq::op(arithlib_bignum(a),
                                          int_of_fixnum(b));
    }

    static bool BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Leq::op(arithlib_bignum(a),
                                          arithlib_bignum(b));
    }   

    static bool ID(LispObject a, double b)
    {   int64_t aa = int_of_fixnum(a);
// I will talk this case through line at a time.
        double da = (double)aa;
// da may either have a value exactly equal to aa, or it can be one of
// a pair of adjacent floating point numbers one below and one above the
// exact not not representable (as a float) value of aa. If da<b than
// it is certain that aa<b. Consider three cases. (1) da did not
// need rounding, then the test is clearly safe. (2) if da was rounded up
// then aa < da < b hence aa < b. And finally (3) if da was rounded down
// and da < b then b is at least as big as the next floating point number
// above da. If and that is not equal to aa (otherwise case (1) applied)
// so this value is greater than aa. And we are home.
        if (da < b) return true;
// Similarly if da > b we can return a clear result. Well if aa == b then
// (double)aa will be equal to be because the equality can only happen
// when aa is a number that maps without rounding onto floating point. And
// making this test used  "!=" deals with the NaN case.
        if (da != b) return false;
// b can still be JUST too large to convery to an integer...
        if (b == 0x1.0p+63) return true;
// .. but now b can turn into an integer without loss...
        else return aa <= (int64_t)b;
    }

    static bool IL(LispObject a, FLOAT_128 b)
    {   return (FLOAT_128)a <= b;
    }

    static bool BD(LispObject a, double b)
    {   return arithlib_lowlevel::Leq::op(arithlib_bignum(a), b);
    }   

    static bool BL(LispObject a, FLOAT_128 b)
    {   pending();
    }

    static bool DI(double a, LispObject b)
    {   int64_t bb = int_of_fixnum(b);
        double db = (double)bb;
        if (a < db) return true;
        if (a != db) return false;
        if (a == 0x1.0p+63) return false;
        else return (int64_t)a <= bb;
    }

    static bool LI(FLOAT_128 a, LispObject b)
    {   return a <= (FLOAT_128)int_of_fixnum(b);
    }

    static bool DB(double a, LispObject b)
    {   return arithlib_lowlevel::Leq::op(a, arithlib_bignum(b));
    }   

    static bool LB(FLOAT_128 a, LispObject b)
    {   aerror("not done yet");
    }

    static bool SS(double a, double b)
    {   return a <= b;
    }

    static bool FF(double a, double b)
    {   return a <= b;
    }

    static bool DD(double a, double b)
    {   return a <= b;
    }

    static bool LL(FLOAT_128 a, FLOAT_128 b)
    {   return a <= b;
    }
 
    static bool RR(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2)
    {   return G<gLeq>(
            G<gTimes>(p1, q2),
            G<gTimes>(p2, q1));
    }
    static bool CC(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2);
};

class gEqn
{
public:
    static constexpr const char* name = "eqn";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gCLeqn
{
public:
    static constexpr const char* name = "CLeqn";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gNeq
{
public:
    static constexpr const char* name = "neqn";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gGeq
{
public:
    static constexpr const char* name = "geq";
    static constexpr const unsigned int flags = op_compare;

    [[gnu::always_inline]]
    static bool II(LispObject a, LispObject b)
    {   return a >= b;
    }

    static bool IB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Geq::op(int_of_fixnum(a),
                                          arithlib_bignum(b));
    }

    static bool BI(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Geq::op(arithlib_bignum(a),
                                          int_of_fixnum(b));
    }

    static bool BB(LispObject a, LispObject b)
    {   return arithlib_lowlevel::Geq::op(arithlib_bignum(a),
                                          arithlib_bignum(b));
    }   

    static bool ID(LispObject a, double b)
    {   return gLeq::DI(b, a);
    }

    static bool IL(LispObject a, FLOAT_128 b)
    {   return (FLOAT_128)a >= b;
    }

    static bool BD(LispObject a, double b)
    {   return arithlib_lowlevel::Geq::op(arithlib_bignum(a), b);
    }   

    static bool BL(LispObject a, FLOAT_128 b)
    {   aerror("not done yet");
    }

    static bool DI(double a, LispObject b)
    {   return gLeq::ID(b, a);
    }

    static bool LI(FLOAT_128 a, LispObject b)
    {   return a >= (FLOAT_128)int_of_fixnum(b);
    }

    static bool DB(double a, LispObject b)
    {   return arithlib_lowlevel::Geq::op(a, arithlib_bignum(b));
    }   

    static bool LB(FLOAT_128 a, LispObject b)
    {   aerror("not done yet");
    }

    static bool SS(double a, double b)
    {   return a >= b;
    }

    static bool FF(double a, double b)
    {   return a >= b;
    }

    static bool DD(double a, double b)
    {   return a >= b;
    }

    static bool LL(FLOAT_128 a, FLOAT_128 b)
    {   return a >= b;
    }
 
    static bool RR(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2)
    {   return gLeq::RR(p2, q2, p1, q1);
    }

    static bool CC(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2);
};

class gGreaterp
{
public:
    static constexpr const char* name = "greaterp";
    static constexpr const unsigned int flags = op_compare;


    [[gnu::always_inline]]
    static bool II(LispObject a, LispObject b)
    {   return a > b;
    }

    static bool IB(LispObject a, LispObject b)
    {   return gLessp::BI(b, a);
    }

    static bool BI(LispObject a, LispObject b)
    {   return gLessp::IB(b, a);
    }

    static bool BB(LispObject a, LispObject b)
    {   return gLessp::BB(b, a);
    }   

    static bool ID(LispObject a, double b)
    {   return gLessp::DI(b, a);
    }

    static bool IL(LispObject a, FLOAT_128 b)
    {   return (FLOAT_128)a > b;
    }

    static bool BD(LispObject a, double b)
    {   return gLessp::DB(b, a);
    }   

    static bool BL(LispObject a, FLOAT_128 b)
    {   return gLessp::LB(b, a);
    }

    static bool DI(double a, LispObject b)
    {   return gLessp::ID(b, a);
    }

    static bool LI(FLOAT_128 a, LispObject b)
    {   return a > (FLOAT_128)int_of_fixnum(b);
    }

    static bool DB(double a, LispObject b)
    {   return gLessp::BD(b, a);
    }   

    static bool LB(FLOAT_128 a, LispObject b)
    {   return gLessp::BL(b, a);
    }

    static bool SS(double a, double b)
    {   return a > b;
    }

    static bool FF(double a, double b)
    {   return a > b;
    }

    static bool DD(double a, double b)
    {   return a > b;
    }

    static bool LL(FLOAT_128 a, FLOAT_128 b)
    {   return a > b;
    }
 
    static bool RR(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2)
    {   return gLessp::RR(p2, q2, p1, q1);
    }

    static bool CC(LispObject p1, LispObject q1,
                   LispObject p2, LispObject q2);
};

class gLeftshift
{
public:
    static constexpr const char* name = "leftshift";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gRightshift
{
public:
    static constexpr const char* name = "rightshift";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIplus
{
public:
    static constexpr const char* name = "iplus";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIdifference
{
public:
    static constexpr const char* name = "idifference";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gItimes
{
public:
    static constexpr const char* name = "itimes";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIquotient
{
public:
    static constexpr const char* name = "iquotient";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIlessp
{
public:
    static constexpr const char* name = "ilessp";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIleq
{
public:
    static constexpr const char* name = "ileq";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIgreaterp
{
public:
    static constexpr const char* name = "igreaterp";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gIgeq
{
public:
    static constexpr const char* name = "igeq";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gModular_plus
{
public:
    static constexpr const char* name = "modular-plus";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gModular_difference
{
public:
    static constexpr const char* name = "modular-difference";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gModular_times
{
public:
    static constexpr const char* name = "modular-times";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gModular_quotient
{
public:
    static constexpr const char* name = "modular-quotient";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gModular_expt
{
public:
    static constexpr const char* name = "modular-expt";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gFloor
{
public:
    static constexpr const char* name = "floor";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gCeiling
{
public:
    static constexpr const char* name = "ceiling";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gTruncate
{
public:
    static constexpr const char* name = "trunc";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gRound
{
public:
    static constexpr const char* name = "round";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gFfloor
{
public:
    static constexpr const char* name = "ffloor";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gFceiling
{
public:
    static constexpr const char* name = "fceiling";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gFtruncate
{
public:
    static constexpr const char* name = "ftrunc";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gFround
{
public:
    static constexpr const char* name = "fround";
    static constexpr const unsigned int flags = 0;

    [[gnu::always_inline]]
    static LispObject II(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject IB(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BI(LispObject a, LispObject b)
    {   pending();
    }

    static LispObject BB(LispObject a, LispObject b)
    {   pending();
    }   

    static LispObject SS(double a, double b)
    {   pending();
    }

    static LispObject FF(double a, double b)
    {   pending();
    }

    static LispObject DD(double a, double b)
    {   pending();
    }

    static LispObject LL(FLOAT_128 a, FLOAT_128 b)
    {   pending();
    }
 
    static LispObject RR(LispObject p1, LispObject q1,
                         LispObject p2, LispObject q2);

    static LispObject CC(LispObject r1, LispObject i1,
                         LispObject r2, LispObject i2);
};

class gAdd1
{
public:
    static constexpr const char* name = "add1";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSub1
{
public:
    static constexpr const char* name = "sub1";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
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

    static bool S(double a)
    {   return a == 0.0;
    }

    static bool F(double a)
    {   return a == 0.0;
    }

    static bool D(double a)
    {   return a == 0.0;
    }

    static bool L(FLOAT_128 a)
    {   return a == LF_C(0.0); 
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

    static bool S(double a)
    {   return a == 1.0;
    }

    static bool F(double a)
    {   return a == 1.0;
    }

    static bool D(double a)
    {   return a == 1.0;
    }

    static bool L(FLOAT_128 a)
    {   return a == LF_C(1.0); 
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

    static bool S(double a)
    {   return a == -1.0;
    }

    static bool F(double a)
    {   return a == -1.0;
    }

    static bool D(double a)
    {   return a == -1.0;
    }

    static bool L(FLOAT_128 a)
    {   return a == -LF_C(1.0); 
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

    static LispObject S(double a)
    {   return pack_short_float(-a);
    }

    static LispObject F(double a)
    {   return pack_single_float(-a);
    }

    static LispObject D(double a)
    {   return make_boxfloat(-a);
    }

    static LispObject L(FLOAT_128 a)
    {   return make_boxfloat128(-a); 
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
        return (SignedDigit)p[numberSize(p)-1] < 0;
    }

    static bool S(double a)
    {   return a < 0.0;
    }

    static bool F(double a)
    {   return a < 0.0;
    }

    static bool D(double a)
    {   return a < 0.0;
    }

    static bool L(FLOAT_128 a)
    {   return a < LF_C(0.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return G<gMinusp>(p);
    }

    static bool C(LispObject R, LispObject i);
};

class gPlusp
{
public:
    static constexpr const char* name = "minusp";
    static constexpr const unsigned int flags = op_compare;

    static bool I(LispObject a)
    {   return (int64_t)a > 0;
    }

    static bool B(LispObject a)
    {   uint64_t* p = arithlib_bignum(a);
// Note this is ">=" because a bignum can not be zero, but if its top
// digit was about to have its top bit set even though the number is
// positive it has a padding zero as an extra top digit.
        return (SignedDigit)p[numberSize(p)-1] >= 0;
    }

    static bool S(double a)
    {   return a > 0.0;
    }

    static bool F(double a)
    {   return a > 0.0;
    }

    static bool D(double a)
    {   return a > 0.0;
    }

    static bool L(FLOAT_128 a)
    {   return a > LF_C(0.0); 
    }

    static bool R(LispObject p, LispObject q)
    {   return G<gPlusp>(p);
    }

    static bool C(LispObject R, LispObject i);
};

class gAbs
{
public:
    static constexpr const char* name = "abs";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSquare
{
public:
    static constexpr const char* name = "square";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gBitnot
{
public:
    static constexpr const char* name = "bitnot";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gReciprocal
{
public:
    static constexpr const char* name = "reciprocal";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gModular_minus
{
public:
    static constexpr const char* name = "modular-minus";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gModular_reciprocal
{
public:
    static constexpr const char* name = "modular-reciprocal";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSafe_modular_reciprocal
{
public:
    static constexpr const char* name = "safe-modular6-reciprocal";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSetmodulus
{
public:
    static constexpr const char* name = "setmodulua";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gModularnumber
{
public:
    static constexpr const char* name = "modular-number";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gFix
{
public:
    static constexpr const char* name = "fix";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gFloat
{
public:
    static constexpr const char* name = "float";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gShort_float
{
public:
    static constexpr const char* name = "short-float";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSingle_float
{
public:
    static constexpr const char* name = "single-float";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gLong_float
{
public:
    static constexpr const char* name = "long-float";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gSqrt
{
public:
    static constexpr const char* name = "sqrt";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};

class gIsqrt
{
public:
    static constexpr const char* name = "isqrt";
    static constexpr const unsigned int flags = 0;
    static LispObject I(LispObject a)
    {   pending();
    }

    static LispObject B(LispObject a)
    {   pending();
    }

    static LispObject S(double a)
    {   pending();
    }

    static LispObject F(double a)
    {   pending();
    }

    static LispObject D(double a)
    {   pending();
    }

    static LispObject L(FLOAT_128 a)
    {   pending();
    }

    static LispObject R(LispObject p, LispObject q)
    {   pending();
    }

    static LispObject C(LispObject r, LispObject i)
    {   pending();
    }
};


} // end of namespace

#endif // __header_generic_h

// end of generic.h
