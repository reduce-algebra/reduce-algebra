// dispatch.h                                   Copyright (C) 2019 Codemist

#ifndef header_dispatch_h
#define header_dispatch_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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
// 128-bit floats.     A class LFlt containing a LispObject.

// Because that leaves 8 different sorts of number a general operation like
// "plus" will need to provide 64 fragments of code to cover all the
// combinations. Oh dear that feels like a lot. They will be expressed as
// methods within a class, all called "op" but covering all combinations of
// overloads, as in
//    LispObject Plus::op(Rat a1, LFlt a2) { ... }
//    LispObject Plus::op(intptr_t a1, uint64_t *a2) { ... }
// and within a mathos that takes an argument of type Rat, Cplx, SFlt, Flt
// or LFlt the code will go something along the lines of
//    LispObject Plus::op(Cplx a1, Cplx a2)
//    {   LispObject rpart = plus(real_part(a1.v), real_part(a2,v));
//        LispObject ipart = plus(imag_part(a1.v), imag_part(a2,v));
//        return make_complex(rpart, ipart);
//    }
// where a1.v and a2.v are of type LispObject and are whatever internal
// representation the Lisp uses for the sort of data involved.

#include "softfloat.h"
#define softfloat_h 1

// arithlib.hpp needs to know that it will be being used in a way that
// interfaces with a Lisp system rather than being used as a free-standing
// C++ library.

#define LISP 1

#ifndef CSL
#define CSL 1
#endif // CSL

#include "arithlib.hpp"

namespace number_dispatcher
{

// Bignums are passed as uintptr_t* pointers to a block of digits
// Doubles are passed using the C++ type double
// and I expect the above three cases to be the most common. Other types
// are wrapped in almost trivial class objects so the object-type captures
// what they represent. The value() accessor gets the tagged LispObject back
// while more specialist accessors get at the real data.

// Fixnum
// uint64_t*
// Rat
// Cpx
// Sflt
// Flt
// double
// LFlt         only of softfloat_h defined.

class Fixnum // for small integers
{
public:
    LispObject v;
    Fixnum(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    intptr_t intval()
    {   return int_of_fixnum(v);
    }
};
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
    {   return ::numerator(v);
    }
    LispObject denominator()
    {   return ::denominator(v);
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
    {   return ::real_part(v);
    }
    LispObject imag_part()
    {   return ::imag_part(v);
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
#ifdef softfloat_h

// This case only supported if softfloat_h is defined, that signalling
// availability of the 128-bit type float128_t.

class LFlt // for long floats
{
public:
    LispObject v;
    LFlt(LispObject a)
    {   v = a;
    }
    LispObject value()
    {   return v;
    }
    float128_t floatval()
    {   return *long_float_addr(v);
    }
};
#endif // softfloat_h

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

template <class R, class T, typename V>
inline R binaryL(const char *fname, V lhsVal, LispObject b)
{   using namespace number_dispatcher;
    switch (b & XTAG_BITS)
    {
    default:
        aerror2("Non-numeric argument", fname, b);
    case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
        switch (type_of_header(flthdr(b)))
        {
        case TYPE_SINGLE_FLOAT:
            return T::op(lhsVal, Flt(b));
        case TYPE_DOUBLE_FLOAT:
// 64-bit floats passed as native data not via a wrapper class.
            return T::op(lhsVal, double_float_val(b));
        case TYPE_LONG_FLOAT:
            return T::op(lhsVal, LFlt(b));
        default:
            aerror2("Non-numeric argument", fname, b);
        }
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(b)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
        case TYPE_RATNUM:
            return T::op(lhsVal, Rat(b));
        case TYPE_COMPLEX_NUM:
            return T::op(lhsVal, Cpx(b));
        default:
            aerror2("Non-numeric argument", fname, b);
        }
    case TAG_FIXNUM:
        return T::op(lhsVal, Fixnum(b));
    case XTAG_SFLOAT:
        return T::op(lhsVal, SFlt(b));
    }
}

template <class R, class T, typename V>
inline R binaryR(const char *fname, LispObject a, V rhsval)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-numeric argument", fname, a);
    case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
        switch (type_of_header(flthdr(a)))
        {
        case TYPE_SINGLE_FLOAT:
            return T::op(Flt(a), rhsval);
        case TYPE_DOUBLE_FLOAT:
// 64-bit floats passed as native data not via a wrapper class.
            return T::op(double_float_val(a), rhsval);
        case TYPE_LONG_FLOAT:
            return T::op(LFlt(a), rhsval);
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), rhsval);
        case TYPE_RATNUM:
            return T::op(Rat(a), rhsval);
        case TYPE_COMPLEX_NUM:
            return T::op(Cpx(a), rhsval);
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_FIXNUM:
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
inline R binary(const char *fname, LispObject a, LispObject b)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-numeric argument", fname, a);
    case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_SINGLE_FLOAT:
            return binaryL<R,T,Flt>(fname, Flt(a), b);
        case TYPE_DOUBLE_FLOAT:
            return binaryL<R,T,double>(fname, double_float_val(a), b);
        case TYPE_LONG_FLOAT:
            return binaryL<R,T,LFlt>(fname, LFlt(a), b);
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return binaryL<R,T,uint64_t *>(fname,
                (uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
        case TYPE_RATNUM:
            return binaryL<R,T,Rat>(fname, Rat(a), b);
        case TYPE_COMPLEX_NUM:
            return binaryL<R,T,Cpx>(fname, Cpx(a), b);
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_FIXNUM:
        return binaryL<R,T,Fixnum>(fname, Fixnum(a), b);
    case XTAG_SFLOAT:
        return binaryL<R,T,SFlt>(fname, SFlt(a), b);
    }
}

// Now the same sort of things but for functions that will only accept
// integer arguments, and so which have lighter weight dispatch.

template <class R, class T, typename V>
inline R ibinaryL(const char *fname, V lhsVal, LispObject b)
{   using namespace number_dispatcher;
    switch (b & XTAG_BITS)
    {
    default:
        aerror2("Non-integer argument", fname, b);
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(b)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op(lhsVal, (uint64_t *)((char *)b + 8 - TAG_NUMBERS));
        default:
            aerror2("Non-integer argument", fname, b);
        }
    case TAG_FIXNUM:
        return T::op(lhsVal, Fixnum(b));
    }
}

template <class R, class T, typename V>
inline R ibinaryR(const char *fname, LispObject a, V rhsval)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-integer argument", fname, a);
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), rhsval);
        default:
            aerror2("Non-integer argument", fname, a);
        }
    case TAG_FIXNUM:
        return T::op(Fixnum(a), rhsval);
    }
}

template <class R, class T>
inline R ibinary(const char *fname, LispObject a, LispObject b)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-integer argument", fname, a);
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return ibinaryL<R,T,uint64_t *>(fname,
                (uint64_t *)((char *)a + 8 - TAG_NUMBERS), b);
        default:
            aerror2("Non-integer argument", fname, a);
        }
    case TAG_FIXNUM:
        return ibinaryL<R,T,Fixnum>(fname, Fixnum(a), b);
    }
}


// Unary operations


template <class R, class T>
inline R unary(const char *fname, LispObject a)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-numeric argument", fname, a);
    case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_SINGLE_FLOAT:
            return T::op(Flt(a));
        case TYPE_DOUBLE_FLOAT:
            return T::op(double_float_val(a));
        case TYPE_LONG_FLOAT:
            return T::op(LFlt(a));
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
        case TYPE_RATNUM:
            return T::op(Rat(a));
        case TYPE_COMPLEX_NUM:
            return T::op(Cpx(a));
        default:
            aerror2("Non-numeric argument", fname, a);
        }
    case TAG_FIXNUM:
        return T::op((intptr_t)int_of_fixnum(a));
    case XTAG_SFLOAT:
        return T::op(SFlt(a));
    }
}



// Integer unary operations

template <class R, class T>
inline R iunary(const char *fname, LispObject a)
{   using namespace number_dispatcher;
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-integer argument", fname, a);
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS));
        default:
            aerror2("Non-integer argument", fname, a);
        }
    case TAG_FIXNUM:
        return T::op((intptr_t)int_of_fixnum(a));
    }
}

// Things like "leftshift" that take and integer and a fixnum.


template <class R, class T>
inline R shiftlike(const char *fname, LispObject a, LispObject n)
{   using namespace number_dispatcher;
    if ((n & XTAG_BITS) != TAG_FIXNUM)
        aerror2("Non-integer argument", fname, n);
    intptr_t nv = int_of_fixnum(n);
    switch (a & XTAG_BITS)
    {
    default:
        aerror2("Non-integer argument", fname, a);
    case TAG_NUMBERS: case TAG_NUMBERS+TAG_XBIT:
        switch (type_of_header(numhdr(a)))
        {
        case TYPE_NEW_BIGNUM:
            return T::op((uint64_t *)((char *)a + 8 - TAG_NUMBERS), nv);
        default:
            aerror2("Non-integer argument", fname, a);
        }
    case TAG_FIXNUM:
        return T::op((intptr_t)int_of_fixnum(a), nv);
    }
}

} // end of number_dispatcher namespace.

using number_dispatcher::Fixnum;     // Small integer
//                       uint64_t *  // Big integer
using number_dispatcher::Rat;        // Rational number
using number_dispatcher::Cpx;        // Complex number
using number_dispatcher::SFlt;       // 28 bit immediate float
using number_dispatcher::Flt;        // 32 bit float (immediate on 64-bit host)
//                       double      // 64 bit float
using number_dispatcher::LFlt;       // 128 bit float supported in software

// I declare a class for each operation that is to be supported... The
// bulk of all the declarations here represents a real statement or reminder
// of how much work it is to support Lisp generic arithmetic! Because this
// is just the declarations, not the implementation.


// Basic generic arithmetic

// The main generic addition function is
//       LispObject Plus.op(LispObject, LispObject);

class Plus
{
public:
// This overload that accepts two LispObject arguments is the only one that
// parts of the system outside the arithmetic code need worry about. All the
// rest are to do with specializations of the main generic version.
    static LispObject op(LispObject a, LispObject b);

// For a while I considered making all the following specializations of
// the operation private, with friend statements so that the implementation
// of eg Plus.op on type Rat{ional} could use Times.op and Gcdn.op (etc).
// Doing that was leading to basically all of the code to do arithmetic
// ending up in a haze of so much mutual friendship that the protection that
// "private" is there to provide was going to fade. So I now just keep
// everything public.

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

class Difference
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

class Times
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

class Quotient
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

// I provide Remainder for all combinations of type, taking the view that
// remainder(a, b) = a - b*quotient(a, b).

class Remainder
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

class Divide
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

// For raising things to powers I cover all combinations.

class Expt
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);
    static LispObject op(LispObject a, Rat b);
    static LispObject op(LispObject a, Cpx b);
    static LispObject op(LispObject a, SFlt b);
    static LispObject op(LispObject a, Flt b);
    static LispObject op(LispObject a, double b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);
    static LispObject op(Rat a, LispObject b);
    static LispObject op(Cpx a, LispObject b);
    static LispObject op(SFlt a, LispObject b);
    static LispObject op(Flt a, LispObject b);
    static LispObject op(double a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);
    static LispObject op(Rat a, Fixnum b);
    static LispObject op(Cpx a, Fixnum b);
    static LispObject op(SFlt a, Fixnum b);
    static LispObject op(Flt a, Fixnum b);
    static LispObject op(double a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
    static LispObject op(Rat a, uint64_t *b);
    static LispObject op(Cpx a, uint64_t *b);
    static LispObject op(SFlt a, uint64_t *b);
    static LispObject op(Flt a, uint64_t *b);
    static LispObject op(double a, uint64_t *b);

    static LispObject op(Fixnum a, Rat b);
    static LispObject op(uint64_t *a, Rat b);
    static LispObject op(Rat a, Rat b);
    static LispObject op(Cpx a, Rat b);
    static LispObject op(SFlt a, Rat b);
    static LispObject op(Flt a, Rat b);
    static LispObject op(double a, Rat b);

    static LispObject op(Fixnum a, Cpx b);
    static LispObject op(uint64_t *a, Cpx b);
    static LispObject op(Rat a, Cpx b);
    static LispObject op(Cpx a, Cpx b);
    static LispObject op(SFlt a, Cpx b);
    static LispObject op(Flt a, Cpx b);
    static LispObject op(double a, Cpx b);

    static LispObject op(Fixnum a, SFlt b);
    static LispObject op(uint64_t *a, SFlt b);
    static LispObject op(Rat a, SFlt b);
    static LispObject op(Cpx a, SFlt b);
    static LispObject op(SFlt a, SFlt b);
    static LispObject op(Flt a, SFlt b);
    static LispObject op(double a, SFlt b);

    static LispObject op(Fixnum a, Flt b);
    static LispObject op(uint64_t *a, Flt b);
    static LispObject op(Rat a, Flt b);
    static LispObject op(Cpx a, Flt b);
    static LispObject op(SFlt a, Flt b);
    static LispObject op(Flt a, Flt b);
    static LispObject op(double a, Flt b);

    static LispObject op(Fixnum a, double b);
    static LispObject op(uint64_t *a, double b);
    static LispObject op(Rat a, double b);
    static LispObject op(Cpx a, double b);
    static LispObject op(SFlt a, double b);
    static LispObject op(Flt a, double b);
    static LispObject op(double a, double b);

#ifdef softfloat_h
    static LispObject op(LispObject a, LFlt b);
    static LispObject op(LFlt a, LispObject b);

    static LispObject op(LFlt a, Fixnum b);
    static LispObject op(LFlt a, uint64_t *b);
    static LispObject op(LFlt a, Rat b);
    static LispObject op(LFlt a, Cpx b);
    static LispObject op(LFlt a, SFlt b);
    static LispObject op(LFlt a, Flt b);
    static LispObject op(LFlt a, double b);
    static LispObject op(LFlt a, LFlt b);

    static LispObject op(Fixnum a, LFlt b);
    static LispObject op(uint64_t *a, LFlt b);
    static LispObject op(Rat a, LFlt b);
    static LispObject op(Cpx a, LFlt b);
    static LispObject op(SFlt a, LFlt b);
    static LispObject op(Flt a, LFlt b);
    static LispObject op(double a, LFlt b);
#endif // softfloat_h
};

// Comparisons. Note that these return a boolean result rather than
// a LispObject.

class Eqn
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

// Neqn is provided because for floating point values NaN != NaN => false
// but also NanN == NaN => false. For non-floating types this will just be
// a negation over Eqn.

class Neqn
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

// Comparing complex values using Greaterp (and friends) may not be useful.

class Greaterp
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

class Geq
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

class Lessp
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

class Leq
{
public:
    static bool op(LispObject a, LispObject b);

    static bool op(LispObject a, Fixnum b);
    static bool op(LispObject a, uint64_t *b);
    static bool op(LispObject a, Rat b);
    static bool op(LispObject a, Cpx b);
    static bool op(LispObject a, SFlt b);
    static bool op(LispObject a, Flt b);
    static bool op(LispObject a, double b);

    static bool op(Fixnum a, LispObject b);
    static bool op(uint64_t *a, LispObject b);
    static bool op(Rat a, LispObject b);
    static bool op(Cpx a, LispObject b);
    static bool op(SFlt a, LispObject b);
    static bool op(Flt a, LispObject b);
    static bool op(double a, LispObject b);

    static bool op(Fixnum a, Fixnum b);
    static bool op(uint64_t *a, Fixnum b);
    static bool op(Rat a, Fixnum b);
    static bool op(Cpx a, Fixnum b);
    static bool op(SFlt a, Fixnum b);
    static bool op(Flt a, Fixnum b);
    static bool op(double a, Fixnum b);

    static bool op(Fixnum a, uint64_t *b);
    static bool op(uint64_t *a, uint64_t *b);
    static bool op(Rat a, uint64_t *b);
    static bool op(Cpx a, uint64_t *b);
    static bool op(SFlt a, uint64_t *b);
    static bool op(Flt a, uint64_t *b);
    static bool op(double a, uint64_t *b);

    static bool op(Fixnum a, Rat b);
    static bool op(uint64_t *a, Rat b);
    static bool op(Rat a, Rat b);
    static bool op(Cpx a, Rat b);
    static bool op(SFlt a, Rat b);
    static bool op(Flt a, Rat b);
    static bool op(double a, Rat b);

    static bool op(Fixnum a, Cpx b);
    static bool op(uint64_t *a, Cpx b);
    static bool op(Rat a, Cpx b);
    static bool op(Cpx a, Cpx b);
    static bool op(SFlt a, Cpx b);
    static bool op(Flt a, Cpx b);
    static bool op(double a, Cpx b);

    static bool op(Fixnum a, SFlt b);
    static bool op(uint64_t *a, SFlt b);
    static bool op(Rat a, SFlt b);
    static bool op(Cpx a, SFlt b);
    static bool op(SFlt a, SFlt b);
    static bool op(Flt a, SFlt b);
    static bool op(double a, SFlt b);

    static bool op(Fixnum a, Flt b);
    static bool op(uint64_t *a, Flt b);
    static bool op(Rat a, Flt b);
    static bool op(Cpx a, Flt b);
    static bool op(SFlt a, Flt b);
    static bool op(Flt a, Flt b);
    static bool op(double a, Flt b);

    static bool op(Fixnum a, double b);
    static bool op(uint64_t *a, double b);
    static bool op(Rat a, double b);
    static bool op(Cpx a, double b);
    static bool op(SFlt a, double b);
    static bool op(Flt a, double b);
    static bool op(double a, double b);

#ifdef softfloat_h
    static bool op(LispObject a, LFlt b);
    static bool op(LFlt a, LispObject b);

    static bool op(LFlt a, Fixnum b);
    static bool op(LFlt a, uint64_t *b);
    static bool op(LFlt a, Rat b);
    static bool op(LFlt a, Cpx b);
    static bool op(LFlt a, SFlt b);
    static bool op(LFlt a, Flt b);
    static bool op(LFlt a, double b);
    static bool op(LFlt a, LFlt b);

    static bool op(Fixnum a, LFlt b);
    static bool op(uint64_t *a, LFlt b);
    static bool op(Rat a, LFlt b);
    static bool op(Cpx a, LFlt b);
    static bool op(SFlt a, LFlt b);
    static bool op(Flt a, LFlt b);
    static bool op(double a, LFlt b);
#endif // softfloat_h
};

// Bitwise operations, including shifts. Note that these will only
// accept integers (ie Fixnum and Bignum) so the number of cases to
// consider is much smaller than for the general situation.

class Logand
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Logor
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Logxor
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Logeqv
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Lshift
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Rshift
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Gcdn
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Lcmn
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Modular_plus
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Modular_difference
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Modular_times
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

class Modular_quotient
{
public:
    static LispObject op(LispObject a, LispObject b);

    static LispObject op(LispObject a, Fixnum b);
    static LispObject op(LispObject a, uint64_t *b);

    static LispObject op(Fixnum a, LispObject b);
    static LispObject op(uint64_t *a, LispObject b);

    static LispObject op(Fixnum a, Fixnum b);
    static LispObject op(uint64_t *a, Fixnum b);

    static LispObject op(Fixnum a, uint64_t *b);
    static LispObject op(uint64_t *a, uint64_t *b);
};

// Now some unary things

class Minus
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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

class Minusp
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
    static bool op(Rat b);
// While MINUSP may not be very sensible on a complex number I will
// still include that case in the dispatch.
    static bool op(Cpx b);
    static bool op(SFlt b);
    static bool op(Flt b);
    static bool op(double b);
#ifdef softfloat_h
    static bool op(LFlt b);
#endif // softfloat_h
};

class Reciprocal
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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

class Zerop
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
    static bool op(Rat b);
    static bool op(Cpx b);
    static bool op(SFlt b);
    static bool op(Flt b);
    static bool op(double b);
#ifdef softfloat_h
    static bool op(LFlt b);
#endif // softfloat_h
};

class Onep
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
    static bool op(Rat b);
    static bool op(Cpx b);
    static bool op(SFlt b);
    static bool op(Flt b);
    static bool op(double b);
#ifdef softfloat_h
    static bool op(LFlt b);
#endif // softfloat_h
};

class Oddp
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
};

class Evenp
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
};

class Bitnot
{
public:
    static LispObject op(LispObject a);

    static LispObject op(Fixnum b);
    static LispObject op(uint64_t *b);
};

class Set_Modulus
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
};

class Modular_number
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
};

class Modular_minus
{
public:
    static bool op(LispObject a);

    static bool op(Fixnum b);
    static bool op(uint64_t *b);
};

class Float
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
#ifdef softfloat_h
    static double op(LFlt b);
#endif // softfloat_h
};

class Float128
{
public:
    static float128_t op(LispObject a);

    static float128_t op(Fixnum b);
    static float128_t op(uint64_t *b);
    static float128_t op(Rat b);
    static float128_t op(Cpx b);
    static float128_t op(SFlt b);
    static float128_t op(Flt b);
    static float128_t op(double b);
#ifdef softfloat_h
    static float128_t op(LFlt b);
#endif // softfloat_h
};

class Fix
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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

class Floor
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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

class Ceiling
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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

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
#ifdef softfloat_h
    static LispObject op(LFlt b);
#endif // softfloat_h
};

class Ldexp
{
public:
    static LispObject op(LispObject a, int n);

    static LispObject op(Fixnum b, int n);
    static LispObject op(uint64_t *b, int n);
    static LispObject op(Rat b, int n);
    static LispObject op(Cpx b, int n);
    static LispObject op(SFlt b, int n);
    static LispObject op(Flt b, int n);
    static LispObject op(double b, int n);
#ifdef softfloat_h
    static LispObject op(LFlt b, int n);
#endif // softfloat_h
};

#endif // header_dispatch_h

// end of dispatch.h
