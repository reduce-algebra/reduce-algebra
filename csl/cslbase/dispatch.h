// dispatch.h                                   Copyright (C) 2026 Codemist

#ifndef header_dispatch_h
#define header_dispatch_h 1

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


// The classes here and the class objects associated with each are purely
// to help with C++ overloading as a way of coping with generic arithmetic
// where for instance I may need to add a rational number to a complex float
// or a big integer.
// I will support the types listed here:
// (small) integers.   I will pass these as intptr_t with the low 4 tag
//                     bits still in place.
// (big) integers.     Passed as (uint64_t *), ie pointers to arrays of
//                     digits.
// Rationals.          Uses a class Rat that has a single field in it that
//                     holds the LispObject denoting the ratio. The wrapper
//                     class exists only to carry confirmation of the type.
//                     I am expecting that a good c++ compiler will avoid
//                     overhead.
// Complex numbers.    A class Cpx containing a LispObject.
// 28-bit floats.      A class SFlt containing a LispObject.
// 32-bit floats.      A class Flt containing a LispObject. Note that on a
//                     32-bit platform this will be a reference to a boxed
//                     value while on a 64-bit one it can contain the bits
//                     that represent the floating point value.
// 64-bit floats.      Passed as "double" values, ie in native floating point.
// 128-bit floats.     An object of type FLOAT_128.

// Because that leaves 8 different sorts of number a general operation like
// "plus" will need to provide 64 fragments of code to cover all the
// combinations. Oh dear that feels like a lot. They will be expressed as
// methods within a class, all called "op" but covering all combinations of
// overloads, as in
//    LispObject Plus::op(Rat a1, FLOAT_128 a2) { ... }
//    LispObject Plus::op(intptr_t a1, uint64_t *a2) { ... }
// and within a method that takes an argument of type Rat, Cplx, SFlt, Flt
// or FLOAT_128 the code will go something along the lines of
//    LispObject Plus::op(Cplx a1, Cplx a2)
//    {   LispObject rpart = plus(real_part(a1.v), real_part(a2,v));
//        LispObject ipart = plus(imag_part(a1.v), imag_part(a2,v));
//        return make_complex(rpart, ipart);
//    }
// where a1.v and a2.v are of type LispObject and are whatever internal
// representation the Lisp uses for the sort of data involved.

// Reading this file ought to convince you just how messy having generic
// arithmetic with quite a few types can be!

#include "headers.h"
#include "arithlib.h"

namespace CSL_LISP
{

// Bignums are passed as uintptr_t* pointers to a block of digits
// Doubles are passed using the C++ type double
// Long doubles are passed as FLOAT_128.
// Other types are wrapped in trivial class objects so the object-type
// captures what they represent. The value() accessor gets the tagged
// LispObject back while more specialist accessors get at the real data.
//
// I VERY much hope that a good C++ c ompiler can optimise away all the
// mechanics of the wrapper classes, especially those for fixnums.

// intptr_t   (a small integer)
// uint64_t*  (a big integer)
// Rat
// Cpx
// Sflt       (28-bit float, always stored as immediate data)
// Flt        (32-bit float)
// double     (64 bit float)
// FLOAT_128  (128 bit float)

using Fixnum = std::intptr_t; // So I can use this name for it for clarity.

[[gnu::always_inline]]
inline LispObject bignum_value(uint64_t *a)
{   return TAG_NUMBERS + (uintptr_t)a - 8;
}

[[gnu::always_inline]]
inline uint64_t *bignum_intval(LispObject a)
{   return (uint64_t *)(a - TAG_NUMBERS + 8);
}

class Rat // for rational numbers
{
public:
    LispObject v;
    Rat(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    LispObject numerator()
    {   return CSL_LISP::numerator(v);
    }
    LispObject denominator()
    {   return CSL_LISP::denominator(v);
    }
};
class Cpx // for complex numbers
{
public:
    LispObject v;
    Cpx(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    LispObject real_part()
    {   return CSL_LISP::real_part(v);
    }
    LispObject imag_part()
    {   return CSL_LISP::imag_part(v);
    }
};
class SFlt// for short floats
{
public:
    LispObject v;
    SFlt(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    double floatval()
    {   return value_of_immediate_float(v);
    }
};
class Flt // for single-precision floats
{
public:
    LispObject v;
    Flt(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    double floatval()
    {   if (is_sfloat(v)) return value_of_immediate_float(v);
        else return single_float_val(v);
    }
};

// Type-dispatch for binary functions happens in two parts - one on the
// first operand and on on the seoond. This overload of the function "binary"
// does the dispatch on argument 2 and ends up calling a function "op" from
// the operation-specific class, with a call of the form
//   op(lhsVal, rhsVal)
// where the types are distinct for all interesting case - using the wrapper
// classes defined above where that is necessary.

// So for instance...
//     Nplus(a1, a2)
// =>  Binary(Plus, a1, a2)
//     which is a #define macro expanding to...
// =>  binary<LispObject,Plus>(a1, a2)
//     ... this dispatches on type of a1. Suppose it is a fixnum...
// =>  binaryL<LispObject,Plus,Fixnum>("plus", (Fixnum)a1, a2)
//     now the type of a1 is clear so dispatch on a2
// =>  Plus::op((Fixnum)a1, (Fixnum)a2)
// =>  the low level code that actually performs the arithmetic
//

// I put in explicit casts to (Fixnum) as a matter of care and clarity
// even though the cast is not liable to be doing anything at all!


#define Binary(operation, a1, a2) \
   binary<LispObject,operation>(a1, a2)

// IBinary is for operations that will only accept integer arguments, while
// BoolBinary is for ones that return a truth value rather than a LispObject.

#define IBinary(operation, a1, a2) \
   ibinary<LispObject,operation>(a1, a2)

#define BoolBinary(operation, a1, a2) \
   binary<bool,operation>(a1, a2)

#define Unary(operation, a) \
   unary<LispObject, operation>(a)

#define IUnary(operation, a) \
   iunary<LispObject, operation>(a)

#define BoolUnary(operation, a) \
   unary<bool, operation>(a)

#define IBoolUnary(operation, a) \
   iunary<bool, operation>(a)

// For this template R is the type of result to be delivered. This is
// often LispObject, but for comparisons it will be bool. T is a class that
// contains all the code to implement an operation, so it will have a name
// such as "Plus" where then overloads of Plus::op support all the various
// cases of addition. V carries type information about the first argument.

// Well I provide two versions, one dispatching if the first argument type is
// already decoded and one for when the second argument is decoded.

// This code tries as best I can to optimise the cases of fixnums
// and bignums by testing for them first. This seems to matter!!

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R binaryL(V lhsVal, LispObject b)
{   using namespace CSL_LISP;
    if (is_fixnum(b)) LIKELY
    {   return T::op(lhsVal, (Fixnum)b);
    }
    else if (is_numbers(b)) LIKELY
    {   unsigned int ty = type_of_header(numhdr(b));
        if (ty == TYPE_NEW_BIGNUM) LIKELY
            return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
        else if (ty == TYPE_RATNUM)
            return T::op(lhsVal, Rat(b));
        else if (ty == TYPE_COMPLEX_NUM)
            return T::op(lhsVal, Cpx(b));
        else UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", T::name, b));
    }
    else if (is_bfloat(b))
    {   Header h = flthdr(b);
        if (h == DOUBLE_FLOAT_HEADER) LIKELY
            return T::op(lhsVal, double_float_val(b));
        else if (h == SINGLE_FLOAT_HEADER)
            return T::op(lhsVal, Flt(b));
        else if (h == LONG_FLOAT_HEADER)
            return T::op(lhsVal, long_float_val(b));
        else UNLIKELY
            return static_cast<R>(
                aerror2("Non-numeric argument", T::name, b));
    }
    else if (is_sfloat(b))
        return T::op(lhsVal, SFlt(b));
    else UNLIKELY
        return static_cast<R>(aerror2("Non-numeric argument", T::name, b));
}

// binary is the dispatcher on the left operand of a binary operator.
// The template has two parameters. The first is the result typeof the
// function we want, the second is a class that contains all the overloads
// op op() that implement it.

template <class R, class T>
[[gnu::always_inline]]
inline R binary(LispObject a, LispObject b)
{   if (is_fixnum(a)) LIKELY
        return binaryL<R,T,Fixnum>((Fixnum)a, b);
    else if (is_numbers(a)) LIKELY
    {   unsigned int ty = type_of_header(numhdr(a));
        if (ty == TYPE_NEW_BIGNUM) LIKELY
            return binaryL<R,T,uint64_t *>((uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
        else if (ty == TYPE_RATNUM)
            return binaryL<R,T,Rat>(Rat(a), b);
        else if (ty == TYPE_COMPLEX_NUM)
            return binaryL<R,T,Cpx>(Cpx(a), b);
        else UNLIKELY
            return static_cast<R>(
                aerror2("Non-numeric argument", T::name, a));
    }
    else if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h == DOUBLE_FLOAT_HEADER) LIKELY
            return binaryL<R,T,double>(double_float_val(a), b);
        else if (h == SINGLE_FLOAT_HEADER)
            return binaryL<R,T,Flt>(Flt(a), b);
        else if (h == LONG_FLOAT_HEADER)
            return binaryL<R,T,FLOAT_128>(long_float_val(a), b);
        else UNLIKELY
            return static_cast<R>(
                aerror2("Non-numeric argument", T::name, a));
    }
    else if (is_sfloat(a))
        return binaryL<R,T,SFlt>(SFlt(a), b);
    else UNLIKELY
        return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
}

// Now the same sort of things but for functions that will only accept
// integer arguments, and so which have lighter weight dispatch.

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R ibinaryL(V lhsVal, LispObject b)
{   if (is_fixnum(b)) LIKELY
        return T::op(lhsVal, (Fixnum)b);
    else if (is_numbers(b) &&
             type_of_header(numhdr(b)) == TYPE_NEW_BIGNUM) LIKELY
        return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
    else UNLIKELY
        return static_cast<R>(aerror2("Non-integer argument", T::name, b));
}

template <class R, class T>
[[gnu::always_inline]]
inline R ibinary(LispObject a, LispObject b)
{   if (is_fixnum(a)) LIKELY
        return ibinaryL<R,T,Fixnum>((Fixnum)a, b);
    else if (is_numbers(a) &&
             type_of_header(numhdr(a)) == TYPE_NEW_BIGNUM) LIKELY
        return ibinaryL<R,T,uint64_t *>((uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
    else UNLIKELY
        return static_cast<R>(aerror2("Non-integer argument", T::name, a));
}


// Unary operations


template <class R, class T>
[[gnu::always_inline]]
inline R unary(LispObject a)
{   if (is_fixnum(a)) LIKELY
        return T::op((Fixnum)a);
    else if (is_numbers(a))
    {   unsigned int ty = type_of_header(numhdr(a));
        if (ty == TYPE_NEW_BIGNUM) LIKELY
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
        else if (ty == TYPE_RATNUM)
             return T::op(Rat(a));
        else if (ty == TYPE_COMPLEX_NUM)
             return T::op(Cpx(a));
        else UNLIKELY
             return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
    }
    else if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h == DOUBLE_FLOAT_HEADER) LIKELY
            return T::op(double_float_val(a));
        else if (h == SINGLE_FLOAT_HEADER)
            return T::op(Flt(a));
        else if (h == LONG_FLOAT_HEADER)
            return T::op(long_float_val(a));
        else UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
    }
    else if (is_sfloat(a))
        return T::op(SFlt(a));
    else UNLIKELY
        return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
}



// Integer unary operations

template <class R, class T>
[[gnu::always_inline]]
inline R iunary(LispObject a)
{   if (is_fixnum(a)) LIKELY
        return T::op((Fixnum)a);
    else if (is_numbers(a) && type_of_header(numhdr(a)) == TYPE_NEW_BIGNUM)
        LIKELY
        return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
    else UNLIKELY
        return static_cast<R>(aerror2("Non-integer argument", T::name, a));
}

template <class R, class T>
[[gnu::always_inline]]
inline R unary(LispObject a, int64_t &xx)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return T::op(Flt(a), xx);
                case DOUBLE_FLOAT_HEADER:
                    return T::op(double_float_val(a), xx);
                case LONG_FLOAT_HEADER:
                    return T::op(long_float_val(a), xx);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), xx);
                case TYPE_RATNUM:
                    return T::op(Rat(a), xx);
                case TYPE_COMPLEX_NUM:
                    return T::op(Cpx(a), xx);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", T::name, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op((Fixnum)a, xx);
        case XTAG_SFLOAT:
            return T::op(SFlt(a), xx);
    }
}


// I declare a class for each operation that is to be supported... The
// huge bulk of all the declarations here makes a real statement or reminder
// of just how much work it is to support Lisp generic arithmetic!
// And this is just the declarations, not the implementation.


// Basic generic arithmetic

// The signature for each function is
//       LispObject XXX.op(LispObject, LispObject);


// Note that for some of the operators not all of the variants on the "op"
// method will be implemented or used. For instance functions that require
// integer arguments will not use the floating point cases. But declaring
// the methods should not hurt.

// Each class here needs to have the same set of method declarations.
// The best way I have found of doing this is to put the set of
// declarations in an include file. This feels really ugly, but not
// quite as ugly as writing them out repeatedly in each instance.

#define OP(classname, stringname)                  \
    class classname                                \
    {                                              \
    public:                                        \
    static constexpr const char* name = stringname; 

OP(Plus, "plus")
#include "dispatch-class.h"

OP(Difference, "difference")
#include "dispatch-class.h"

OP(Times, "times")
#include "dispatch-class.h"

OP(ClassicalTimes, "classicaltimes")
#include "dispatch-class.h"

OP(Quotient, "quotient")
#include "dispatch-class.h"

// CLquotient is for (/ 3 6) => 1/2 with a rational number result.

OP(CLQuotient, "clquotient")
#include "dispatch-class.h"

// I provide Remainder for all combinations of type, taking the view that
// remainder(a, b) = a - b*quotient(a, b).

OP(Remainder, "remainder")
#include "dispatch-class.h"

OP(Mod, "mod")
#include "dispatch-class.h"

OP(Divide, "divide")
#include "dispatch-class.h"

OP(Expt, "expt")
#include "dispatch-class.h"

// Comparisons. Note that these return a boolean result rather than
// a LispObject. So while they need declarations of "op" it will return
// a boolean value rather tham a LispObject. So I have a separate
// includse file for that.

OP(Eqn, "eqn")
#include "boolean-dispatch-class.h"

// CLEqn is for Common Lisp style (= a b) where eg (= 1 1.0) => true

OP(CLEqn, "cleqn")
#include "boolean-dispatch-class.h"

OP(Neqn, "neqn")
#include "boolean-dispatch-class.h"

// Comparing complex values using Greaterp (and friends) may not be useful.

OP(Greaterp, "greaterp")
#include "boolean-dispatch-class.h"

OP(Geq, "geq")
#include "boolean-dispatch-class.h"

OP(Lessp, "lessp")
#include "boolean-dispatch-class.h"

OP(Leq, "leq")
#include "boolean-dispatch-class.h"

// Bitwise operations, including shifts. Note that these will only
// accept integers (ie Fixnum and Bignum) so the number of cases to
// consider is much smaller than for the general situation.

OP(Logand, "logand")
#include "dispatch-class.h"

OP(Logor, "Logor")
#include "dispatch-class.h"

OP(Logxor, "logxor")
#include "dispatch-class.h"

OP(Logeqv, "logeqv")
#include "dispatch-class.h"

OP(Lognot, "lognot")
#include "dispatch-class.h"

OP(Logbitp, "logbitp")
#include "boolean-dispatch-class.h"

class LowBit
{
public:
    static constexpr const char* name = "lowbit";

    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

class IntegerLength
{
public:
    static constexpr const char* name = "integerlength";
   
    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

class Low64Bits
{
public:
    static constexpr const char* name = "low64bits";

    static uint64_t op(Fixnum a);
    static uint64_t op(uint64_t *a);
};

class Top64Bits
{
public:
    static constexpr const char* name = "top64bits";

    static uint64_t op(Fixnum a);
    static uint64_t op(uint64_t *a);
};

class Logcount
{
public:
    static constexpr const char* name = "logcount";

    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

OP(LeftShift, "leftshift")
#include "dispatch-class.h"

OP(RightShift, "rightshift")
#include "dispatch-class.h"

OP(Gcdn, "gcdn")
#include "dispatch-class.h"

OP(Lcmn, "lcmn")
#include "dispatch-class.h"

OP(ModularPlus, "modularplus")
#include "dispatch-class.h"

OP(ModularDifference, "modulardifference")
#include "dispatch-class.h"

OP(ModularTimes, "modulartimes")
#include "dispatch-class.h"

OP(ModularExpt, "Modularexpt")
#include "dispatch-class.h"

OP(ModularQuotient, "modularquotient")
#include "dispatch-class.h"

// Now some unary things

OP(Add1, "add1")
#include "dispatch-class.h"

OP(Sub1, "sub1")
#include "dispatch-class.h"

OP(Minus, "minus")
#include "dispatch-class.h"

OP(Minusp, "minusp")
#include "boolean-dispatch-class.h"

OP(Plusp, "plusp")
#include "boolean-dispatch-class.h"

OP(Abs, "abs")
#include "dispatch-class.h"

OP(Square, "square")
#include "dispatch-class.h"

OP(Reciprocal, "reciprocal")
#include "dispatch-class.h"

OP(Zerop, "zerop")
#include "boolean-dispatch-class.h"

OP(Onep, "onep")
#include "boolean-dispatch-class.h"

OP(MinusOnep, "minusonep")
#include "boolean-dispatch-class.h"

// Some of these will only accept integer argumennts and so use hardly any
// of the vast number of possible signatures for "op".

OP(Oddp, "oddp")
#include "boolean-dispatch-class.h"

OP(Evenp, "evenp")
#include "boolean-dispatch-class.h"

OP(Bitnot, "bitnot")
#include "dispatch-class.h"

OP(SetModulus, "setmodulus")
#include "dispatch-class.h"

OP(ModularNumber, "modularnumber")
#include "dispatch-class.h"

OP(ModularMinus, "modularminus")
#include "dispatch-class.h"

OP(ModularReciprocal, "modularreciprocal")
#include "dispatch-class.h"

OP(SafeModularReciprocal, "safemodularreciprocal")
#include "dispatch-class.h"

// I make Float::op return a LispObject here not just a double
// because Common Lisp specifies a two-arg variant that can return
// one of the various widths of floating point values. I have a separate
// class RawFloat the always returns a double and that makes sense for
// some internal uses.

OP(Float, "float")
#include "dispatch-class.h"

class RawFloat32
{
public:
    static constexpr const char* name = "rawfloat32";

    static float op(Fixnum b);
    static float op(uint64_t *b);
    static float op(Rat b);
    static float op(Cpx b);
    static float op(SFlt b);
    static float op(Flt b);
    static float op(double b);
    static float op(FLOAT_128 b);
};

class RawFloat
{
public:
    static constexpr const char* name = "rawfloat";

    static double op(Fixnum b);
    static double op(uint64_t *b);
    static double op(Rat b);
    static double op(Cpx b);
    static double op(SFlt b);
    static double op(Flt b);
    static double op(double b);
    static double op(FLOAT_128 b);
};

// Float128 always returns a FLOAT_128, so it is sort of RawFloat128

class Float128
{
public:
    static constexpr const char* name = "float128";

    static FLOAT_128 op(Fixnum b);
    static FLOAT_128 op(uint64_t *b);
    static FLOAT_128 op(Rat b);
    static FLOAT_128 op(Cpx b);
    static FLOAT_128 op(SFlt b);
    static FLOAT_128 op(Flt b);
    static FLOAT_128 op(double b);
    static FLOAT_128 op(FLOAT_128 b);
};


OP(Fix, "fix")
#include "dispatch-class.h"

OP(Truncate, "truncate")
#include "dispatch-class.h"

OP(Floor, "floor")
#include "dispatch-class.h"

OP(Ceiling, "ceiling")
#include "dispatch-class.h"

OP(Ftruncate, "ftruncate")
#include "dispatch-class.h"

OP(Ffloor, "ffloor")
#include "dispatch-class.h"

OP(Fceiling, "fceiling")
#include "dispatch-class.h"

// The first batch are for support of Lisp-level functions, while the
// rest are for internal use. so I can not just derive from public Generic.

class Frexp
{
public:
    static constexpr const char* name = "frexp";

    static LispObject op(Fixnum b);
    static LispObject op(uint64_t *b);
    static LispObject op(Rat b);
    static LispObject op(Cpx b);
    static LispObject op(SFlt b);
    static LispObject op(Flt b);
    static LispObject op(double b);
    static LispObject op(FLOAT_128 b);

    static double op(Fixnum b, int64_t &x);
    static double op(uint64_t *b, int64_t &x);
    static double op(Rat b, int64_t &x);
    static double op(Cpx b, int64_t &x);
    static double op(SFlt b, int64_t &x);
    static double op(Flt b, int64_t &x);
    static double op(double b, int64_t &x);
    static double op(FLOAT_128 b, int64_t &x);
};

class Frexp128
{
public:
    static constexpr const char* name = "frexp128";

    static LispObject op(Fixnum b);
    static LispObject op(uint64_t *b);
    static LispObject op(Rat b);
    static LispObject op(Cpx b);
    static LispObject op(SFlt b);
    static LispObject op(Flt b);
    static LispObject op(double b);
    static LispObject op(FLOAT_128 b);

    static FLOAT_128 op(Fixnum b, int64_t &x);
    static FLOAT_128 op(uint64_t *b, int64_t &x);
    static FLOAT_128 op(Rat b, int64_t &x);
    static FLOAT_128 op(Cpx b, int64_t &x);
    static FLOAT_128 op(SFlt b, int64_t &x);
    static FLOAT_128 op(Flt b, int64_t &x);
    static FLOAT_128 op(double b, int64_t &x);
    static FLOAT_128 op(FLOAT_128 b, int64_t &x);
};

OP(Sqrt, "sqrt")
#include "dispatch-class.h"

OP(Isqrt, "isqrt")
#include "dispatch-class.h"


#ifdef OLD
[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(int_of_fixnum(a), int_of_fixnum(b));
}
#else
[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, Fixnum b)
{   using namespace arithlib_implementation;
    int64_t c;
    if (!__builtin_add_overflow((int64_t)(a-TAG_FIXNUM), b, &c)) return c;
// Here there was signed overflow in the addition, so I need to return a
// bignum.
    uint64_t* r = reserve(1);
    r[0] = int_of_fixnum(a) + int_of_fixnum(b);
    return confirmSize(r, 1, 1);
}
#endif

// bignum + fixnum
[[gnu::always_inline]]
inline LispObject Plus::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(a, int_of_fixnum(b));
}

// fixnum + bignum
[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Plus::op(b, int_of_fixnum(a));
}

// bignum + bignum
[[gnu::always_inline]]
inline LispObject Plus::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Plus::op(a, b);
}

#ifdef OLD
[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(int_of_fixnum(a), int_of_fixnum(b));
}
#else
[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, Fixnum b)
{   using namespace arithlib_implementation;
    int64_t c;
    if (!__builtin_sub_overflow(a, b, &c)) return c+TAG_FIXNUM;
// Here there was signed overflow in the subtraction, so I need to return a
// bignum.
    uint64_t* r = reserve(1);
    r[0] = int_of_fixnum(a) - int_of_fixnum(b);
    return confirmSize(r, 1, 1);
}
#endif

// bignum - fixnum
[[gnu::always_inline]]
inline LispObject Difference::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(a, int_of_fixnum(b));
}

// fixnum - bignum
[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(int_of_fixnum(a), b);
}

// bignum - bignum
[[gnu::always_inline]]
inline LispObject Difference::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(a, b);
}

#ifdef OLD
[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Times::op(int_of_fixnum(a), int_of_fixnum(b));
}
#else
[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, Fixnum b)
{   using namespace arithlib_implementation;
    countmul(0, 0);
    int64_t c;
    if (!__builtin_mul_overflow((int64_t)(a&~XTAG_BITS), int_of_fixnum(b), &c))
    {
#ifdef DEBUG
        fix_stays_fix++;
#endif // DEBUG
        return c + TAG_BITS;
    }
#ifdef DEBUG
        fix_becomes_big++;
#endif // DEBUG
    SignedDigit hi;
    Digit lo;
    signedMultiply64(int_of_fixnum(a), int_of_fixnum(b), hi, lo);
    if ((hi == 0 && positive(lo)) ||
        (hi == -1 && negative(lo)))
    {   uint64_t* r = reserve(1);
        r[0] = lo;
        return confirmSize(r, 1, 1);
    }   
    uint64_t* r = reserve(2);
    r[0] = lo;
    r[1] = hi;
    return confirmSize(r, 2, 2);
}
#endif

// bignum * fixnum
[[gnu::always_inline]]
inline LispObject Times::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Times::op(a, int_of_fixnum(b));
}

// fixnum * bignum
[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Times::op(b, int_of_fixnum(a));
}

// bignum * bignum
[[gnu::always_inline]]
inline LispObject Times::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Times::op(a, b);
}

#undef OP

} // end namespace


#endif // header_dispatch_h

// end of dispatch.h
