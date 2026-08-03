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
// (small) integers.   I will pass these as an instance of a class Fixnum,
//                     with a single intptr_t field. Note that this will
//                     be either 32 or 64 bits depending on the platform.
//                     (and machines with pointers that are neither 32 nor
//                     64 bits are not supported!)
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

// LispObject
// Fixnum
// uint64_t*
// Rat
// Cpx
// Sflt
// Flt
// double
// FLOAT_128

class Fixnum // for small integers
{
public:
    LispObject v;
    [[gnu::always_inline]]
    Fixnum(LispObject a)
    {   v = a;
    }
    [[gnu::always_inline]]
    LispObject value()
    {   return v;
    }
    [[gnu::always_inline]]
    intptr_t intval()
    {   return int_of_fixnum(v);
    }
};

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
    {   return single_float_val(v);
    }
};

// Type-dispatch for binary functions happens in two parts - one on the
// first operand and on on the seoond. This overload of the function "binary"
// does the dispatch on argument 2 and ends up calling a function "op" from
// the operation-specific class, with a call of the form
//   op(lhsVal, rhsVal)
// where the types are distinct for all interesting case - using the wrapper
// classes defined above where that is necessary.

// For this template R is the type of result to be delivered. This is
// often LispObject, but for comparisons it will be bool. T is a class that
// contains all the code to implement an operation, so it will have a name
// such as "Plus" where then overloads of Plus::op support all the various
// cases of addition. V carries type information about the first argument.

// Well I provide two versions, one dispatching if the first argument type is
// already decoded and one for when the second argument is decoded.

#ifdef OLD
template <class R, class T, typename V>
[[gnu::always_inline]]
inline R binaryL(const char *fname, V lhsVal, LispObject b)
{   switch (b & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", fname, b));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(b))
            {   case SINGLE_FLOAT_HEADER:
                    return T::op(lhsVal, Flt(b));
                case DOUBLE_FLOAT_HEADER:
                    LIKELY
// 64-bit floats passed as native data not via a wrapper class.
                    return T::op(lhsVal, double_float_val(b));
                case LONG_FLOAT_HEADER:
                    return T::op(lhsVal, long_float_val(b));
                default:
                    UNLIKELY
                    return static_cast<R>(static_cast<R>(aerror2("Non-numeric argument", fname, b)));
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(b)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
                case TYPE_RATNUM:
                    return T::op(lhsVal, Rat(b));
                case TYPE_COMPLEX_NUM:
                    return T::op(lhsVal, Cpx(b));
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, b));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(lhsVal, Fixnum(b));
        case XTAG_SFLOAT:
            return T::op(lhsVal, SFlt(b));
    }
}
#else // OLD

// This "new" version tries as best I can to optimise the cases of fixnums
// and bignums.

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R binaryL(const char *fname, V lhsVal, LispObject b)
{   using namespace CSL_LISP;
    if (is_fixnum(b)) LIKELY
    {   return T::op(lhsVal, Fixnum(b));
    }
    else if (is_numbers(b)) LIKELY
    {   unsigned int ty = type_of_header(numhdr(b));
        if (ty == TYPE_NEW_BIGNUM) LIKELY
        {   return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
        }
        else if (ty == TYPE_RATNUM)
        {   return T::op(lhsVal, Rat(b));
        }
        else if (ty == TYPE_COMPLEX_NUM)
        {   return T::op(lhsVal, Cpx(b));
        }
        else UNLIKELY
        {   return static_cast<R>(aerror2("Non-numeric argument", fname, b));
        }
    }
    else if (is_bfloat(b))
    {   switch (flthdr(b))
        {   case SINGLE_FLOAT_HEADER:
                return T::op(lhsVal, Flt(b));
            case DOUBLE_FLOAT_HEADER:
                LIKELY
// 64-bit floats passed as native data not via a wrapper class.
                return T::op(lhsVal, double_float_val(b));
            case LONG_FLOAT_HEADER:
                return T::op(lhsVal, long_float_val(b));
            default:
                UNLIKELY
                return static_cast<R>(
                    aerror2("Non-numeric argument", fname, b));
        }
    }
    else if (is_sfloat(b))
    {   return T::op(lhsVal, SFlt(b));
    }
    else UNLIKELY
        return static_cast<R>(aerror2("Non-numeric argument", fname, b));
}
#endif // OLD

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R binaryR(const char *fname, LispObject a, V rhsval)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", fname, a));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return T::op(Flt(a), rhsval);
                case DOUBLE_FLOAT_HEADER:
// 64-bit floats passed as native data not via a wrapper class.
                    LIKELY
                    return T::op(double_float_val(a), rhsval);
                case LONG_FLOAT_HEADER:
                    return T::op(long_float_val(a), rhsval);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), rhsval);
                case TYPE_RATNUM:
                    return T::op(Rat(a), rhsval);
                case TYPE_COMPLEX_NUM:
                    return T::op(Cpx(a), rhsval);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(Fixnum(a), rhsval);
        case XTAG_SFLOAT:
            return T::op(SFlt(a), rhsval);
    }
}

// binary is the dispatcher on the left operand of a binary operator.
// The template has two parameters. The first is the result typeof the
// function we want, the second is a class that contains all the overloads
// op op() that implement it.

template <class R, class T>
[[gnu::always_inline]]
inline R binary(const char *fname, LispObject a, LispObject b)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", fname, a));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return binaryL<R,T,Flt>(fname, Flt(a), b);
                case DOUBLE_FLOAT_HEADER:
                    LIKELY
                    return binaryL<R,T,double>(fname, double_float_val(a), b);
                case LONG_FLOAT_HEADER:
                    return binaryL<R,T,FLOAT_128>(fname, long_float_val(a), b);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return binaryL<R,T,uint64_t *>(fname,
                                                   (uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
                case TYPE_RATNUM:
                    return binaryL<R,T,Rat>(fname, Rat(a), b);
                case TYPE_COMPLEX_NUM:
                    return binaryL<R,T,Cpx>(fname, Cpx(a), b);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return binaryL<R,T,Fixnum>(fname, Fixnum(a), b);
        case XTAG_SFLOAT:
            return binaryL<R,T,SFlt>(fname, SFlt(a), b);
    }
}

// Now the same sort of things but for functions that will only accept
// integer arguments, and so which have lighter weight dispatch.

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R ibinaryL(const char *fname, V lhsVal, LispObject b)
{   switch (b & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-integer argument", fname, b));
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(b)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-integer argument", fname, b));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(lhsVal, Fixnum(b));
    }
}

template <class R, class T, typename V>
[[gnu::always_inline]]
inline R ibinaryR(const char *fname, LispObject a, V rhsval)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-integer argument", fname, a));
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), rhsval);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-integer argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(Fixnum(a), rhsval);
    }
}

template <class R, class T>
[[gnu::always_inline]]
inline R ibinary(const char *fname, LispObject a, LispObject b)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-integer argument", fname, a));
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return ibinaryL<R,T,uint64_t *>(fname,
                                                    (uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-integer argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return ibinaryL<R,T,Fixnum>(fname, Fixnum(a), b);
    }
}


// Unary operations


template <class R, class T>
[[gnu::always_inline]]
inline R unary(const char *fname, LispObject a)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", fname, a));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a))
            {   case SINGLE_FLOAT_HEADER:
                    return T::op(Flt(a));
                case DOUBLE_FLOAT_HEADER:
                    return T::op(double_float_val(a));
                case LONG_FLOAT_HEADER:
                    return T::op(long_float_val(a));
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
                case TYPE_RATNUM:
                    return T::op(Rat(a));
                case TYPE_COMPLEX_NUM:
                    return T::op(Cpx(a));
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(Fixnum(a));
        case XTAG_SFLOAT:
            return T::op(SFlt(a));
    }
}



// Integer unary operations

template <class R, class T>
[[gnu::always_inline]]
inline R iunary(const char *fname, LispObject a)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-integer argument", fname, a));
        case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
            LIKELY
            switch (type_of_header(numhdr(a)))
            {   case TYPE_NEW_BIGNUM:
                    LIKELY
                    return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
                default:
                    UNLIKELY
                    return static_cast<R>(aerror2("Non-integer argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(Fixnum(a));
    }
}

template <class R, class T>
[[gnu::always_inline]]
inline R unary(const char *fname, LispObject a, int64_t &xx)
{   switch (a & XTAG_BITS)
    {   default:
            UNLIKELY
            return static_cast<R>(aerror2("Non-numeric argument", fname, a));
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
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
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
                    return static_cast<R>(aerror2("Non-numeric argument", fname, a));
            }
        case TAG_FIXNUM:
            LIKELY
            return T::op(Fixnum(a), xx);
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

class Plus
#include "dispatch-class.h"

class Difference
#include "dispatch-class.h"

class Times
#include "dispatch-class.h"

class ClassicalTimes
#include "dispatch-class.h"

class Quotient
#include "dispatch-class.h"

// CLquotient is for (/ 3 6) => 1/2 with a rational number result.

class CLQuotient
#include "dispatch-class.h"

// I provide Remainder for all combinations of type, taking the view that
// remainder(a, b) = a - b*quotient(a, b).

class Remainder
#include "dispatch-class.h"

class Mod
#include "dispatch-class.h"

class Divide
#include "dispatch-class.h"

class Expt
#include "dispatch-class.h"

// Comparisons. Note that these return a boolean result rather than
// a LispObject. So while they need declarations of "op" it will return
// a boolean value rather tham a LispObject. So I have a separate
// includse file for that.

class Eqn
#include "boolean-dispatch-class.h"

// CLEqn is for Common Lisp style (= a b) where eg (= 1 1.0) => true

class CLEqn
#include "boolean-dispatch-class.h"

class Neqn
#include "boolean-dispatch-class.h"

// Comparing complex values using Greaterp (and friends) may not be useful.

class Greaterp
#include "boolean-dispatch-class.h"

class Geq
#include "boolean-dispatch-class.h"

class Lessp
#include "boolean-dispatch-class.h"

class Leq
#include "boolean-dispatch-class.h"

// Bitwise operations, including shifts. Note that these will only
// accept integers (ie Fixnum and Bignum) so the number of cases to
// consider is much smaller than for the general situation.

class Logand
#include "dispatch-class.h"

class Logor
#include "dispatch-class.h"

class Logxor
#include "dispatch-class.h"

class Logeqv
#include "dispatch-class.h"

class Lognot
#include "dispatch-class.h"

class Logbitp
#include "boolean-dispatch-class.h"

class LowBit
{
public:
    static size_t op(LispObject a);

    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

class IntegerLength
{
public:
    static size_t op(LispObject a);

    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

class Low64Bits
{
public:
    static uint64_t op(LispObject a);

    static uint64_t op(Fixnum a);
    static uint64_t op(uint64_t *a);
};

class Top64Bits
{
public:
    static uint64_t op(LispObject a);

    static uint64_t op(Fixnum a);
    static uint64_t op(uint64_t *a);
};

class Logcount
{
public:
    static size_t op(LispObject a);

    static size_t op(Fixnum a);
    static size_t op(uint64_t *a);
};

class LeftShift
#include "dispatch-class.h"

class RightShift
#include "dispatch-class.h"

class Gcdn
#include "dispatch-class.h"

class Lcmn
#include "dispatch-class.h"

class ModularPlus
#include "dispatch-class.h"

class ModularDifference
#include "dispatch-class.h"

class ModularTimes
#include "dispatch-class.h"

class ModularExpt
#include "dispatch-class.h"

class ModularQuotient
#include "dispatch-class.h"

// Now some unary things

class Add1
#include "dispatch-class.h"

class Sub1
#include "dispatch-class.h"

class Minus
#include "dispatch-class.h"

class Minusp
#include "boolean-dispatch-class.h"

class Plusp
#include "boolean-dispatch-class.h"

class Abs
#include "dispatch-class.h"

class Square
#include "dispatch-class.h"

class Reciprocal
#include "dispatch-class.h"

class Zerop
#include "boolean-dispatch-class.h"

class Onep
#include "boolean-dispatch-class.h"

class MinusOnep
#include "boolean-dispatch-class.h"

// Some of these will only accept integer argumennts and so use hardly any
// of the vast number of possible signatures for "op".

class Oddp
#include "boolean-dispatch-class.h"

class Evenp
#include "boolean-dispatch-class.h"

class Bitnot
#include "dispatch-class.h"

class SetModulus
#include "dispatch-class.h"

class ModularNumber
#include "dispatch-class.h"

class ModularMinus
#include "dispatch-class.h"

class ModularReciprocal
#include "dispatch-class.h"

class SafeModularReciprocal
#include "dispatch-class.h"

// I make Float::op return a LispObject here not just a double
// because Common Lisp specifies a two-arg variant that can return
// one of the various widths of floating point values. I have a separate
// class RawFloat the always returns a double and that makes sense for
// some internal uses.

class Float
#include "dispatch-class.h"

class RawFloat32
{
public:
    static float op(LispObject a);

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
    static double op(LispObject a);

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
    static FLOAT_128 op(LispObject a);

    static FLOAT_128 op(Fixnum b);
    static FLOAT_128 op(uint64_t *b);
    static FLOAT_128 op(Rat b);
    static FLOAT_128 op(Cpx b);
    static FLOAT_128 op(SFlt b);
    static FLOAT_128 op(Flt b);
    static FLOAT_128 op(double b);
    static FLOAT_128 op(FLOAT_128 b);
};


class Fix
#include "dispatch-class.h"

class Truncate
#include "dispatch-class.h"

class Floor
#include "dispatch-class.h"

class Ceiling
#include "dispatch-class.h"

class Ftruncate
#include "dispatch-class.h"

class Ffloor
#include "dispatch-class.h"

class Fceiling
#include "dispatch-class.h"

// The first batch are for support of Lisp-level functions, while the
// rest are for internal use. so I can not just derive from public Generic.

class Frexp
{
public:
    static LispObject op(LispObject a);

    static LispObject op(Fixnum b);
    static LispObject op(uint64_t *b);
    static LispObject op(Rat b);
    static LispObject op(Cpx b);
    static LispObject op(SFlt b);
    static LispObject op(Flt b);
    static LispObject op(double b);
    static LispObject op(FLOAT_128 b);

    static double op(LispObject a, int64_t &x);

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
    static LispObject op(LispObject a);

    static LispObject op(Fixnum b);
    static LispObject op(uint64_t *b);
    static LispObject op(Rat b);
    static LispObject op(Cpx b);
    static LispObject op(SFlt b);
    static LispObject op(Flt b);
    static LispObject op(double b);
    static LispObject op(FLOAT_128 b);

    static FLOAT_128 op(LispObject a, int64_t &x);

    static FLOAT_128 op(Fixnum b, int64_t &x);
    static FLOAT_128 op(uint64_t *b, int64_t &x);
    static FLOAT_128 op(Rat b, int64_t &x);
    static FLOAT_128 op(Cpx b, int64_t &x);
    static FLOAT_128 op(SFlt b, int64_t &x);
    static FLOAT_128 op(Flt b, int64_t &x);
    static FLOAT_128 op(double b, int64_t &x);
    static FLOAT_128 op(FLOAT_128 b, int64_t &x);
};

class Ldexp
#include "dispatch-class.h"

class Sqrt
#include "dispatch-class.h"

class Isqrt
#include "dispatch-class.h"

// Now the cases I expect to be most performance-critical, ie
// Plus, Difference and Times on Fixnums and Bignums, are included
// here such that they get rendered inline.

[[gnu::always_inline]]
inline LispObject Plus::op(LispObject a, LispObject b)
{   return binary<LispObject,Plus>("plus", a, b);
}

[[gnu::always_inline]]
inline LispObject Plus::op(LispObject a, Fixnum b)
{   return binaryR<LispObject,Plus>("plus", a, b);
}

[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, LispObject b)
{   return binaryL<LispObject,Plus>("plus", a, b);
}

[[gnu::always_inline]]
inline LispObject Plus::op(LispObject a, uint64_t *b)
{   return binaryR<LispObject,Plus>("plus", a, b);
}

[[gnu::always_inline]]
inline LispObject Plus::op(uint64_t *a, LispObject b)
{   return binaryL<LispObject,Plus>("plus", a, b);
}

// Maybe I can use __builtin_sadd_overflow() here under g++.

[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(a.intval(), b.intval());
}

// bignum + fixnum
[[gnu::always_inline]]
inline LispObject Plus::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Plus::op(a, b.intval());
}

// fixnum + bignum
[[gnu::always_inline]]
inline LispObject Plus::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Plus::op(b, a.intval());
}

// bignum + bignum
[[gnu::always_inline]]
inline LispObject Plus::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Plus::op(a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(LispObject a, LispObject b)
{   return binary<LispObject,Difference>("difference", a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(LispObject a, Fixnum b)
{   return binaryR<LispObject,Difference>("difference", a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, LispObject b)
{   return binaryL<LispObject,Difference>("difference", a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(LispObject a, uint64_t *b)
{   return binaryR<LispObject,Difference>("difference", a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(uint64_t *a, LispObject b)
{   return binaryL<LispObject,Difference>("difference", a, b);
}

[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(a.intval(), b.intval());
}

// bignum - fixnum
[[gnu::always_inline]]
inline LispObject Difference::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Difference::op(a, b.intval());
}

// fixnum - bignum
[[gnu::always_inline]]
inline LispObject Difference::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(a.intval(), b);
}

// bignum - bignum
[[gnu::always_inline]]
inline LispObject Difference::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Difference::op(a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(LispObject a, LispObject b)
{   return binary<LispObject,Times>("times", a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(LispObject a, Fixnum b)
{   return binaryR<LispObject,Times>("times", a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, LispObject b)
{   return binaryL<LispObject,Times>("times", a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(LispObject a, uint64_t *b)
{   return binaryR<LispObject,Times>("times", a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(uint64_t *a, LispObject b)
{   return binaryL<LispObject,Times>("times", a, b);
}

[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Times::op(a.intval(), b.intval());
}

// bignum * fixnum
[[gnu::always_inline]]
inline LispObject Times::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Times::op(a, b.intval());
}

// fixnum * bignum
[[gnu::always_inline]]
inline LispObject Times::op(Fixnum a, uint64_t *b)
{   return arithlib_lowlevel::Times::op(b, a.intval());
}

// bignum * bignum
[[gnu::always_inline]]
inline LispObject Times::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Times::op(a, b);
}

} // end namespace


#endif // header_dispatch_h

// end of dispatch.h
