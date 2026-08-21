// arith-compare-cpp                       Copyright (C) 2022-2026 Codemist

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

// **** I now think that greaterp, geq, lessp and leq shoule not try
//      to do anything with complex numbers. At present they probably all
//      return false - but perhaps they should raise an error.

#include "headers.h"

namespace CSL_LISP
{

// (eqn a b) will be true if a and b are both numbers of the same
// type and their values match. So note that all the mixed mode variants
// here just return "nil" for false.

// fixnum == fixnum

bool Eqn::op(Fixnum a, Fixnum b)
{   return a == b;
}

// bignum == fixnum
bool Eqn::op(uint64_t *a, Fixnum b)
{   return false;
}

// rational == fixnum

// There may be an interesting question here as to whether a rational
// number of the form (1/1) can ever exist.

bool Eqn::op(Rat a, Fixnum b)
{   return false;
}

// complex == fixnum
bool Eqn::op(Cpx a, Fixnum b)
{   return false;
}

// short float == fixnum
bool Eqn::op(SFlt a, Fixnum b)
{   return false;
}

// single float == fixnum
bool Eqn::op(Flt a, Fixnum b)
{   return false;
}

// double float == fixnum
bool Eqn::op(double a, Fixnum b)
{   return false;
}

// long float == fixnum
bool Eqn::op(FLOAT_128 a, Fixnum b)
{   return false;
}

// fixnum == bignum
bool Eqn::op(Fixnum a, uint64_t *b)
{   return false;
}

// bignum == bignum
bool Eqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}

// rational == bignum
bool Eqn::op(Rat a, uint64_t *b)
{   return false;
}

// complex == bignum
bool Eqn::op(Cpx a, uint64_t *b)
{   return false;
}

// short float == bignum
bool Eqn::op(SFlt a, uint64_t *b)
{   return false;
}

// single float == bignum
bool Eqn::op(Flt a, uint64_t *b)
{   return false;
}

// double float == bignum
bool Eqn::op(double a, uint64_t *b)
{   return false;
}

// long float == bignum
bool Eqn::op(FLOAT_128 a, uint64_t *b)
{   return false;
}

// fixnum == rational
bool Eqn::op(Fixnum a, Rat b)
{   return false;
}

// bignum == rational
bool Eqn::op(uint64_t *a, Rat b)
{   return false;
}

// rational == rational
bool Eqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Eqn, p1, p2) && BoolBinary(Eqn, q1, q2);
}

// complex == rational
bool Eqn::op(Cpx a, Rat b)
{   return false;
}

// short float == rational
bool Eqn::op(SFlt a, Rat b)
{   return false;
}

// single float == rational
bool Eqn::op(Flt a, Rat b)
{   return false;
}

// double float == rational
bool Eqn::op(double a, Rat b)
{   return false;
}

// long float == rational
bool Eqn::op(FLOAT_128 a, Rat b)
{   return false;
}

// fixnum == complex
bool Eqn::op(Fixnum a, Cpx b)
{   return false;
}

// bignum == complex
bool Eqn::op(uint64_t *a, Cpx b)
{   return false;
}

// rational == complex
bool Eqn::op(Rat a, Cpx b)
{   return false;
}

// complex == complex
bool Eqn::op(Cpx a, Cpx b)
{   return (BoolBinary(Eqn, a.real_part(), b.real_part()) &&
            BoolBinary(Eqn, a.imag_part(), b.imag_part()));
}

// short float == complex
bool Eqn::op(SFlt a, Cpx b)
{   return false;
}

// single float == complex
bool Eqn::op(Flt a, Cpx b)
{   return false;
}

// double float == complex
bool Eqn::op(double a, Cpx b)
{   return false;
}

// long float == complex
bool Eqn::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum == short float
bool Eqn::op(Fixnum a, SFlt b)
{   return false;
}

// bignum == short float
bool Eqn::op(uint64_t *a, SFlt b)
{   return false;
}

// rational == short float
bool Eqn::op(Rat a, SFlt b)
{   return false;
}

// complex == short float
bool Eqn::op(Cpx a, SFlt b)
{   return false;
}

// short float == short float
bool Eqn::op(SFlt a, SFlt b)
{   return (a.floatval() == b.floatval());
}

// single float == short float
bool Eqn::op(Flt a, SFlt b)
{   return false;
}

// double float == short float
bool Eqn::op(double a, SFlt b)
{   return false;
}

// long float == short float
bool Eqn::op(FLOAT_128 a, SFlt b)
{   return false;
}

// fixnum == single float
bool Eqn::op(Fixnum a, Flt b)
{   return false;
}

// bignum == single float
bool Eqn::op(uint64_t *a, Flt b)
{   return false;
}

// rational == single float
bool Eqn::op(Rat a, Flt b)
{   return false;
}

// complex == single float
bool Eqn::op(Cpx a, Flt b)
{   return false;
}

// short float == single float
bool Eqn::op(SFlt a, Flt b)
{   return false;
}

// single float == single float
bool Eqn::op(Flt a, Flt b)
{   return (a.floatval() == b.floatval());
}

// double float == single float
bool Eqn::op(double a, Flt b)
{   return false;
}

// long float == single float
bool Eqn::op(FLOAT_128 a, Flt b)
{   return false;
}

// fixnum == double float
bool Eqn::op(Fixnum a, double b)
{   return false;
}

// bignum == double float
bool Eqn::op(uint64_t *a, double b)
{   return false;
}

// rational == double float
bool Eqn::op(Rat a, double b)
{   return false;
}

// complex == double float
bool Eqn::op(Cpx a, double b)
{   return false;
}

// short float == double float
bool Eqn::op(SFlt a, double b)
{   return false;
}

// single float == double float
bool Eqn::op(Flt a, double b)
{   return false;
}

// double float == double float
bool Eqn::op(double a, double b)
{   return (a == b);
}

// long float == double float
bool Eqn::op(FLOAT_128 a, double b)
{   return false;
}

// fixnum == long float
bool Eqn::op(Fixnum a, FLOAT_128 b)
{   return false;
}

// bignum == long float
bool Eqn::op(uint64_t *a, FLOAT_128 b)
{   return false;
}

// rational == long float
bool Eqn::op(Rat a, FLOAT_128 b)
{   return false;
}

// complex == long float
bool Eqn::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float == long float
bool Eqn::op(SFlt a, FLOAT_128 b)
{   return false;
}

// single float == long float
bool Eqn::op(Flt a, FLOAT_128 b)
{   return false;
}

// double float == long float
bool Eqn::op(double a, FLOAT_128 b)
{   return false;
}

// long float == long float
bool Eqn::op(FLOAT_128 a, FLOAT_128 b)
{   return a == b;
}

// (cleqn a b) compares two numbers and returns true if they have the same
// value even if their types differ. The common and sensible case here
// will be (cleqn 2 2.0) but it is also necessary to arrange that the
// following cases apply:
//   (cleqn 1.5 3/2)   (cleqn 2 2/1)   (cleqn 1 #x(1 0))
// and equality tests involving a mix of floating point values and
// rationals needs to take care lest (cleqn 1.0 10000000001/10000000000)
// and variants with huge numerators and denominators do not get confused.
// This is achieved by converting the floating point value to the exact
// rational that it stands for and performing comparison as between a
// pair of rational numbers.

// fixnum CL== fixnum

bool CLEqn::op(Fixnum a, Fixnum b)
{   return a == b;
}

// bignum CL== fixnum
bool CLEqn::op(uint64_t *a, Fixnum b)
{   return false;
}

// rational CL== fixnum
bool CLEqn::op(Rat a, Fixnum b)
{   return false;
}

// complex CL== fixnum
bool CLEqn::op(Cpx a, Fixnum b)
{   return false;
}

// short float CL== fixnum
// fixnums can always be converted to floating point without loss and
// so the test here is easy.

bool CLEqn::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>(a.floatval()),
                                      int_of_fixnum(b));
}

// single float CL== fixnum
bool CLEqn::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>(a.floatval()),
                                      int_of_fixnum(b));
}

// double float CL== fixnum
bool CLEqn::op(double a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(a, int_of_fixnum(b));
}

// long float CL== fixnum
bool CLEqn::op(FLOAT_128 a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(a, int_of_fixnum(b));
}

// fixnum CL== bignum
bool CLEqn::op(Fixnum a, uint64_t *b)
{   return false;
}

// bignum CL== bignum
bool CLEqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}

// rational CL== bignum
bool CLEqn::op(Rat a, uint64_t *b)
{   return false;
}

// complex CL== bignum
bool CLEqn::op(Cpx a, uint64_t *b)
{   return false;
}

// short float CL== bignum
// arithlib.cpp has somewhat contorted code so that it can perform
// reliable comparisons between floats and bignums.

bool CLEqn::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b);
}

// single float CL== bignum
bool CLEqn::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b);
}

// double float CL== bignum
bool CLEqn::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}

// long float CL== bignum
bool CLEqn::op(FLOAT_128 a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}

// fixnum CL== rational
bool CLEqn::op(Fixnum a, Rat b)
{   return false;
}

// bignum CL== rational
bool CLEqn::op(uint64_t *a, Rat b)
{   return false;
}

// rational CL== rational
bool CLEqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Eqn, p1, p2) && BoolBinary(Eqn, q1, q2);
}

// complex CL== rational
bool CLEqn::op(Cpx a, Rat b)
{   return false;
}

// short float CL== rational
// This is where I needs to convert the floating point value to a
// rational value (which may in fact turn out to be an integer, so I
// then have a dispatch as between integer and rational converted value).

bool CLEqn::op(SFlt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return false;
    LispObject aa = N_rationalf(d);
    return CLEqn::op(Rat(aa), b);
}

// single float CL== rational
bool CLEqn::op(Flt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return false;
    LispObject aa = N_rationalf(d);
    return CLEqn::op(Rat(aa), b);
}

// double float CL== rational
bool CLEqn::op(double a, Rat b)
{   if (std::isnan(a)) return false;
    if (std::isinf(a)) return false;
    LispObject aa = N_rationalf(a);
    return CLEqn::op(Rat(aa), b);
}

extern LispObject N_rationalf128(FLOAT_128 d);

// long float CL== rational
bool CLEqn::op(FLOAT_128 aa, Rat b)
{   FLOAT_128 a = aa;
    if (isnan(a) || isinf(a)) return false;
    LispObject aaa = N_rationalf128(a);
    return CLEqn::op(Rat(aaa), b);
}

// fixnum CL== complex
bool CLEqn::op(Fixnum a, Cpx b)
{   return false;
}

// bignum CL== complex
bool CLEqn::op(uint64_t *a, Cpx b)
{   return false;
}

// rational CL== complex
bool CLEqn::op(Rat a, Cpx b)
{   return false;
}

// complex CL== complex
bool CLEqn::op(Cpx a, Cpx b)
{   return (BoolBinary(Eqn, a.real_part(), b.real_part()) &&
            BoolBinary(Eqn, a.imag_part(), b.imag_part()));
}

// short float CL== complex
bool CLEqn::op(SFlt a, Cpx b)
{   return false;
}

// single float CL== complex
bool CLEqn::op(Flt a, Cpx b)
{   return false;
}

// double float CL== complex
bool CLEqn::op(double a, Cpx b)
{   return false;
}

// long float CL== complex
bool CLEqn::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum CL== short float
bool CLEqn::op(Fixnum a, SFlt b)
{   return Eqn::op(b, a);
}

// bignum CL== short float
bool CLEqn::op(uint64_t *a, SFlt b)
{   return Eqn::op(b, a);
}

// rational CL== short float
bool CLEqn::op(Rat a, SFlt b)
{   return Eqn::op(b, a);
}

// complex CL== short float
bool CLEqn::op(Cpx a, SFlt b)
{   return Eqn::op(b, a);
}

// short float CL== short float
bool CLEqn::op(SFlt a, SFlt b)
{   return (a.floatval() == b.floatval());
}

// single float CL== short float
bool CLEqn::op(Flt a, SFlt b)
{   return (a.floatval() == b.floatval());
}

// double float CL== short float
bool CLEqn::op(double a, SFlt b)
{   return (a == b.floatval());
}

// long float CL== short float
bool CLEqn::op(FLOAT_128 a, SFlt b)
{   return a == Float128::op(b);
}

// fixnum CL== single float
bool CLEqn::op(Fixnum a, Flt b)
{   return Eqn::op(b, a);
}

// bignum CL== single float
bool CLEqn::op(uint64_t *a, Flt b)
{   return Eqn::op(b, a);
}

// rational CL== single float
bool CLEqn::op(Rat a, Flt b)
{   return Eqn::op(b, a);
}

// complex CL== single float
bool CLEqn::op(Cpx a, Flt b)
{   return Eqn::op(b, a);
}

// short float CL== single float
bool CLEqn::op(SFlt a, Flt b)
{   return Eqn::op(b, a);
}

// single float CL== single float
bool CLEqn::op(Flt a, Flt b)
{   return (a.floatval() == b.floatval());
}

// double float CL== single float
bool CLEqn::op(double a, Flt b)
{   return (a == b.floatval());
}

// long float CL== single float
bool CLEqn::op(FLOAT_128 a, Flt b)
{   return a == Float128::op(b);
}

// fixnum CL== double float
bool CLEqn::op(Fixnum a, double b)
{   return Eqn::op(b, a);
}

// bignum CL== double float
bool CLEqn::op(uint64_t *a, double b)
{   return Eqn::op(b, a);
}

// rational CL== double float
bool CLEqn::op(Rat a, double b)
{   return Eqn::op(b, a);
}

// complex CL== double float
bool CLEqn::op(Cpx a, double b)
{   return false;
}

// short float CL== double float
bool CLEqn::op(SFlt a, double b)
{   return Eqn::op(b, a);
}

// single float CL== double float
bool CLEqn::op(Flt a, double b)
{   return Eqn::op(b, a);
}

// double float CL== double float
bool CLEqn::op(double a, double b)
{   return (a == b);
}

// long float CL== double float
bool CLEqn::op(FLOAT_128 a, double b)
{   return a == Float128::op(b);
}

// fixnum CL== long float
bool CLEqn::op(Fixnum a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// bignum CL== long float
bool CLEqn::op(uint64_t *a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// rational CL== long float
bool CLEqn::op(Rat a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// complex CL== long float
bool CLEqn::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float CL== long float
bool CLEqn::op(SFlt a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// single float CL== long float
bool CLEqn::op(Flt a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// double float CL== long float
bool CLEqn::op(double a, FLOAT_128 b)
{   return Eqn::op(b, a);
}

// long float CL== long float
bool CLEqn::op(FLOAT_128 a, FLOAT_128 b)
{   return a == b;
}

// (neqn a b) is defined as (not (eqn a b)) so if the two operands are
// not the same sort of number it will return true.

// fixnum != fixnum

bool Neqn::op(Fixnum a, Fixnum b)
{   return a != b;
}

// bignum != fixnum
bool Neqn::op(uint64_t *a, Fixnum b)
{   return true;
}

// rational != fixnum
bool Neqn::op(Rat a, Fixnum b)
{   return true;
}

// complex != fixnum
bool Neqn::op(Cpx a, Fixnum b)
{   return true;
}

// short float != fixnum
bool Neqn::op(SFlt a, Fixnum b)
{   return true;
}

// single float != fixnum
bool Neqn::op(Flt a, Fixnum b)
{   return true;
}

// double float != fixnum
bool Neqn::op(double a, Fixnum b)
{   return true;
}

// long float != fixnum
bool Neqn::op(FLOAT_128 a, Fixnum b)
{   return true;
}

// fixnum != bignum
bool Neqn::op(Fixnum a, uint64_t *b)
{   return true;
}

// bignum != bignum
bool Neqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Neqn::op(a, b);
}

// rational != bignum
bool Neqn::op(Rat a, uint64_t *b)
{   return true;
}

// complex != bignum
bool Neqn::op(Cpx a, uint64_t *b)
{   return true;
}

// short float != bignum
bool Neqn::op(SFlt a, uint64_t *b)
{   return (a.floatval() != arithlib_lowlevel::Double::op(b));
}

// single float != bignum
bool Neqn::op(Flt a, uint64_t *b)
{   return true;
}

// double float != bignum
bool Neqn::op(double a, uint64_t *b)
{   return true;
}

// long float != bignum
bool Neqn::op(FLOAT_128 a, uint64_t *b)
{   return true;
}

// fixnum != rational
bool Neqn::op(Fixnum a, Rat b)
{   return true;
}

// bignum != rational
bool Neqn::op(uint64_t *a, Rat b)
{   return true;
}

// rational != rational
bool Neqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Neqn, p1, p2) || BoolBinary(Neqn, q1, q2);
}

// complex != rational
bool Neqn::op(Cpx a, Rat b)
{   return true;
}

// short float != rational
bool Neqn::op(SFlt a, Rat b)
{   return true;
}

// single float != rational
bool Neqn::op(Flt a, Rat b)
{   return true;
}

// double float != rational
bool Neqn::op(double a, Rat b)
{   return true;
}

// long float != rational
bool Neqn::op(FLOAT_128 a, Rat b)
{   return true;
}

// fixnum != complex
bool Neqn::op(Fixnum a, Cpx b)
{   return true;
}

// bignum != complex
bool Neqn::op(uint64_t *a, Cpx b)
{   return true;
}

// rational != complex
bool Neqn::op(Rat a, Cpx b)
{   return true;
}

// complex != complex
bool Neqn::op(Cpx a, Cpx b)
{   return (BoolBinary(Neqn, a.real_part(), b.real_part()) ||
            BoolBinary(Neqn, a.imag_part(), b.imag_part()));
}

// short float != complex
bool Neqn::op(SFlt a, Cpx b)
{   return true;
}

// single float != complex
bool Neqn::op(Flt a, Cpx b)
{   return true;
}

// double float != complex
bool Neqn::op(double a, Cpx b)
{   return true;
}

// long float != complex
bool Neqn::op(FLOAT_128 a, Cpx b)
{   return true;
}

// fixnum != short float
bool Neqn::op(Fixnum a, SFlt b)
{   return true;
}

// bignum != short float
bool Neqn::op(uint64_t *a, SFlt b)
{   return true;
}

// rational != short float
bool Neqn::op(Rat a, SFlt b)
{   return true;
}

// complex != short float
bool Neqn::op(Cpx a, SFlt b)
{   return true;
}

// short float != short float
bool Neqn::op(SFlt a, SFlt b)
{   return (a.floatval() != b.floatval());
}

// single float != short float
bool Neqn::op(Flt a, SFlt b)
{   return true;
}

// double float != short float
bool Neqn::op(double a, SFlt b)
{   return true;
}

// long float != short float
bool Neqn::op(FLOAT_128 a, SFlt b)
{   return true;
}

// fixnum != single float
bool Neqn::op(Fixnum a, Flt b)
{   return true;
}

// bignum != single float
bool Neqn::op(uint64_t *a, Flt b)
{   return true;
}

// rational != single float
bool Neqn::op(Rat a, Flt b)
{   return true;
}

// complex != single float
bool Neqn::op(Cpx a, Flt b)
{   return true;
}

// short float != single float
bool Neqn::op(SFlt a, Flt b)
{   return true;
}

// single float != single float
bool Neqn::op(Flt a, Flt b)
{   return (a.floatval() != b.floatval());
}

// double float != single float
bool Neqn::op(double a, Flt b)
{   return true;
}

// long float != single float
bool Neqn::op(FLOAT_128 a, Flt b)
{   return true;
}

// fixnum != double float
bool Neqn::op(Fixnum a, double b)
{   return true;
}

// bignum != double float
bool Neqn::op(uint64_t *a, double b)
{   return true;
}

// rational != double float
bool Neqn::op(Rat a, double b)
{   return true;
}

// complex != double float
bool Neqn::op(Cpx a, double b)
{   return true;
}

// short float != double float
bool Neqn::op(SFlt a, double b)
{   return true;
}

// single float != double float
bool Neqn::op(Flt a, double b)
{   return true;
}

// double float != double float
bool Neqn::op(double a, double b)
{   return (a != b);
}

// long float != double float
bool Neqn::op(FLOAT_128 a, double b)
{   return true;
}

// fixnum != long float
bool Neqn::op(Fixnum a, FLOAT_128 b)
{   return true;
}

// bignum != long float
bool Neqn::op(uint64_t *a, FLOAT_128 b)
{   return true;
}

// rational != long float
bool Neqn::op(Rat a, FLOAT_128 b)
{   return true;
}

// complex != long float
bool Neqn::op(Cpx a, FLOAT_128 b)
{   return true;
}

// short float != long float
bool Neqn::op(SFlt a, FLOAT_128 b)
{   return true;
}

// single float != long float
bool Neqn::op(Flt a, FLOAT_128 b)
{   return true;
}

// double float != long float
bool Neqn::op(double a, FLOAT_128 b)
{   return true;
}

// long float != long float
bool Neqn::op(FLOAT_128 a, FLOAT_128 b)
{   return a != b;
}

// (greaterp a b) is reasonably straightforward for integers and floats.
// It is not meaningful for complex numbers, and for rationals it is
// slightly messy in general and very messy for floating point.

// fixnum > fixnum

bool Greaterp::op(Fixnum a, Fixnum b)
{   return a > b;
}

// bignum > fixnum
bool Greaterp::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a, (int64_t)int_of_fixnum(b));
}

// rational > fixnum
bool Greaterp::op(Rat a, Fixnum b)
{   // p/q > b if p > q*b
    return BoolBinary(Greaterp, a.numerator(), Binary(Times, a.denominator(), b));
}

// complex > fixnum
bool Greaterp::op(Cpx a, Fixnum b)
{   return false;      // really this is meaningless in general, and
                       // I am not going to make special provision for the
                       // special case where the complex value happens
                       // to have a zero imaginary part.
}

// short float > fixnum
// Note that a fixnum may be up to 60 bits wide while double precision
// floats only hold 53 bits of precision, so I can not compare by
// just converting the fixnum to a double. If I tried going the other
// way I could run into issues with floating values that had fractional
// parts or that had values well beyond 2^60. But arithlib.cpp deals
// with all that - including the cases of NaNs and infinities.

bool Greaterp::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>(a.floatval()),
                                           int_of_fixnum(b));
}

// single float > fixnum
bool Greaterp::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>(a.floatval()),
                                           int_of_fixnum(b));
}

// double float > fixnum
bool Greaterp::op(double a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a, int_of_fixnum(b));
}

// long float > fixnum
bool Greaterp::op(FLOAT_128 a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a, (int64_t)int_of_fixnum(b));
}

// fixnum > bignum
bool Greaterp::op(Fixnum a, uint64_t *b)
{   return Lessp::op(b, a);
}

// bignum > bignum
bool Greaterp::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a, b);
}

// rational > bignum
bool Greaterp::op(Rat a, uint64_t *b)
{   return BoolBinary(Greaterp, a.numerator(), Binary(Times, a.denominator(), bignum_value(b)));

}

// complex > bignum
bool Greaterp::op(Cpx a, uint64_t *b)
{   return false;
}

// short float > bignum
bool Greaterp::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>(a.floatval()),
                                           b);
}

// single float > bignum
bool Greaterp::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>(a.floatval()),
                                           b);
}

// double float > bignum
bool Greaterp::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a, b);
}

// long float > bignum
bool Greaterp::op(FLOAT_128 a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a, b);
}

// fixnum > rational
bool Greaterp::op(Fixnum a, Rat b)
{   return BoolBinary(Greaterp, Binary(Times, a, b.denominator()), b.numerator());
}

// bignum > rational
bool Greaterp::op(uint64_t *a, Rat b)
{   return BoolBinary(Greaterp, Binary(Times, bignum_value(a), b.denominator()), b.numerator());
}

// rational > rational
bool Greaterp::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Greaterp, Binary(Times, p1, q2), Binary(Times, p2, q1));
}

// complex > rational
bool Greaterp::op(Cpx a, Rat b)
{   return false;
}

// For comparisons between floats and rationals I will generally convery the
// float into a rational (which I can always do without any loss) and then
// do a comparison between the two rationals. That will perhaps be horribly
// expensive, but it should get perfectly correct results.

// short float > rational
bool Greaterp::op(SFlt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d > 0.0;
    LispObject aa = N_rationalf(d);
    return BoolBinary(Greaterp, aa, b.value());
}

// single float > rational
bool Greaterp::op(Flt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d > 0.0;
    LispObject aa = N_rationalf(d);
    return BoolBinary(Greaterp, aa, b.value());
}

// double float > rational
bool Greaterp::op(double a, Rat b)
{   if (std::isnan(a)) return false;
    if (std::isinf(a)) return a > 0.0;
    LispObject aa = N_rationalf(a);
    return BoolBinary(Greaterp, aa, b. value());
}

// long float > rational
bool Greaterp::op(FLOAT_128 a, Rat b)
{   FLOAT_128 d = a;
    if (isnan(d)) return false;         // a is a NaN
    if (isinf(d)) return !signbit(d);   // a is infinite
    LispObject aa = N_rationalf128(d);
    return BoolBinary(Greaterp, aa, b. value());
}

// fixnum > complex
bool Greaterp::op(Fixnum a, Cpx b)
{   return false;
}

// bignum > complex
bool Greaterp::op(uint64_t *a, Cpx b)
{   return false;
}

// rational > complex
bool Greaterp::op(Rat a, Cpx b)
{   return false;
}

// complex > complex
bool Greaterp::op(Cpx a, Cpx b)
{   return false;
}

// short float > complex
bool Greaterp::op(SFlt a, Cpx b)
{   return false;
}

// single float > complex
bool Greaterp::op(Flt a, Cpx b)
{   return false;
}

// double float > complex
bool Greaterp::op(double a, Cpx b)
{   return false;
}

// long float > complex
bool Greaterp::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum > short float
bool Greaterp::op(Fixnum a, SFlt b)
{   return Lessp::op(b, a);
}

// bignum > short float
bool Greaterp::op(uint64_t *a, SFlt b)
{   return Lessp::op(b, a);
}

// rational > short float
bool Greaterp::op(Rat a, SFlt b)
{   return Lessp::op(b, a);
}

// complex > short float
bool Greaterp::op(Cpx a, SFlt b)
{   return false;
}

// short float > short float
bool Greaterp::op(SFlt a, SFlt b)
{   return (a.floatval() > b.floatval());
}

// single float > short float
bool Greaterp::op(Flt a, SFlt b)
{   return (a.floatval() > b.floatval());
}

// double float > short float
bool Greaterp::op(double a, SFlt b)
{   return (a > b.floatval());
}

// long float > short float
bool Greaterp::op(FLOAT_128 a, SFlt b)
{   return Float128::op(b) < a;
}

// fixnum > single float
bool Greaterp::op(Fixnum a, Flt b)
{   return Lessp::op(b, a);
}

// bignum > single float
bool Greaterp::op(uint64_t *a, Flt b)
{   return Lessp::op(b, a);
}

// rational > single float
bool Greaterp::op(Rat a, Flt b)
{   return Lessp::op(b, a);
}

// complex > single float
bool Greaterp::op(Cpx a, Flt b)
{   return Lessp::op(b, a);
}

// short float > single float
bool Greaterp::op(SFlt a, Flt b)
{   return Lessp::op(b, a);
}

// single float > single float
bool Greaterp::op(Flt a, Flt b)
{   return (a.floatval() > b.floatval());
}

// double float > single float
bool Greaterp::op(double a, Flt b)
{   return (a > b.floatval());
}

// long float > single float
bool Greaterp::op(FLOAT_128 a, Flt b)
{   return Float128::op(b) < a;
}

// fixnum > double float
bool Greaterp::op(Fixnum a, double b)
{   return Lessp::op(b, a);
}

// bignum > double float
bool Greaterp::op(uint64_t *a, double b)
{   return Lessp::op(b, a);
}

// rational > double float
bool Greaterp::op(Rat a, double b)
{   return Lessp::op(b, a);
}

// complex > double float
bool Greaterp::op(Cpx a, double b)
{   return false;
}

// short float > double float
bool Greaterp::op(SFlt a, double b)
{   return Lessp::op(b, a);
}

// single float > double float
bool Greaterp::op(Flt a, double b)
{   return Lessp::op(b, a);
}

// double float > double float
bool Greaterp::op(double a, double b)
{   return (a > b);
}

// long float > double float
bool Greaterp::op(FLOAT_128 a, double b)
{   return Float128::op(b) < a;
}

// fixnum > long float
bool Greaterp::op(Fixnum a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// bignum > long float
bool Greaterp::op(uint64_t *a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// rational > long float
bool Greaterp::op(Rat a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// complex > long float
bool Greaterp::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float > long float
bool Greaterp::op(SFlt a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// single float > long float
bool Greaterp::op(Flt a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// double float > long float
bool Greaterp::op(double a, FLOAT_128 b)
{   return Lessp::op(b, a);
}

// long float > long float
bool Greaterp::op(FLOAT_128 a, FLOAT_128 b)
{   return b < a;
}

// (geq a b) is very much like (greaterp a b)...

// fixnum >= fixnum

bool Geq::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Geq::op((int64_t)int_of_fixnum(a),
                                      (int64_t)int_of_fixnum(b));
}

// bignum >= fixnum
bool Geq::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a, (int64_t)int_of_fixnum(b));
}

// rational >= fixnum
bool Geq::op(Rat a, Fixnum b)
{   // p/q >= b if p >= q*b
    return BoolBinary(Geq, a.numerator(), Binary(Times, a.denominator(), b));
}

// complex >= fixnum
bool Geq::op(Cpx a, Fixnum b)
{   return false;
}

// short float >= fixnum
bool Geq::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>(a.floatval()),
                                      (int64_t)int_of_fixnum(b));
}

// single float >= fixnum
bool Geq::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>(a.floatval()),
                                      (int64_t)int_of_fixnum(b));
}

// double float >= fixnum
bool Geq::op(double a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a, (int64_t)int_of_fixnum(b));
}

// long float >= fixnum
bool Geq::op(FLOAT_128 a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a, (int64_t)int_of_fixnum(b));
}

// fixnum >= bignum
bool Geq::op(Fixnum a, uint64_t *b)
{   return Leq::op(b, a);
}

// bignum >= bignum
bool Geq::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a, b);
}

// rational >= bignum
bool Geq::op(Rat a, uint64_t *b)
{   return BoolBinary(Geq, a.numerator(), Binary(Times, a.denominator(), bignum_value(b)));

}

// complex >= bignum
bool Geq::op(Cpx a, uint64_t *b)
{   return false;
}

// short float >= bignum
bool Geq::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>(a.floatval()), b);
}

// single float >= bignum
bool Geq::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>(a.floatval()), b);
}

// double float >= bignum
bool Geq::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a, b);
}

// long float >= bignum
bool Geq::op(FLOAT_128 a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a, b);
}

// fixnum >= rational
bool Geq::op(Fixnum a, Rat b)
{   return BoolBinary(Geq, Binary(Times, a, b.denominator()), b.numerator());
}

// bignum >= rational
bool Geq::op(uint64_t *a, Rat b)
{   return BoolBinary(Geq, Binary(Times, bignum_value(a), b.denominator()), b.numerator());
}

// rational >= rational
bool Geq::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Geq, Binary(Times, p1, q2), Binary(Times, p2, q1));
}

// complex >= rational
bool Geq::op(Cpx a, Rat b)
{   return false;
}

// short float >= rational
bool Geq::op(SFlt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d > 0.0;
    LispObject aa = N_rationalf(d);
    return Geq::op(Rat(aa), b);
}

// single float >= rational
bool Geq::op(Flt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d > 0.0;
    LispObject aa = N_rationalf(d);
    return Geq::op(Rat(aa), b);
}

// double float >= rational
bool Geq::op(double a, Rat b)
{   if (std::isnan(a)) return false;
    if (std::isinf(a)) return a > 0.0;
    LispObject aa = N_rationalf(a);
    return Geq::op(Rat(aa), b);
}

// long float >= rational
bool Geq::op(FLOAT_128 a, Rat b)
{   FLOAT_128 d = a;
    if (isnan(d)) return false;         // a is a NaN
    if (isinf(d)) return !signbit(d);   // a is infinite
    LispObject aa = N_rationalf128(d);
    return Geq::op(Rat(aa), b);
}

// fixnum >= complex
bool Geq::op(Fixnum a, Cpx b)
{   return false;
}

// bignum >= complex
bool Geq::op(uint64_t *a, Cpx b)
{   return false;
}

// rational >= complex
bool Geq::op(Rat a, Cpx b)
{   return false;
}

// complex >= complex
bool Geq::op(Cpx a, Cpx b)
{   return false;
}

// short float >= complex
bool Geq::op(SFlt a, Cpx b)
{   return false;
}

// single float >= complex
bool Geq::op(Flt a, Cpx b)
{   return false;
}

// double float >= complex
bool Geq::op(double a, Cpx b)
{   return false;
}

// long float >= complex
bool Geq::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum >= short float
bool Geq::op(Fixnum a, SFlt b)
{   return Leq::op(b, a);
}

// bignum >= short float
bool Geq::op(uint64_t *a, SFlt b)
{   return Leq::op(b, a);
}

// rational >= short float
bool Geq::op(Rat a, SFlt b)
{   return Leq::op(b, a);
}

// complex >= short float
bool Geq::op(Cpx a, SFlt b)
{   return false;
}

// short float >= short float
bool Geq::op(SFlt a, SFlt b)
{   return (a.floatval() >= b.floatval());
}

// single float >= short float
bool Geq::op(Flt a, SFlt b)
{   return (a.floatval() >= b.floatval());
}

// double float >= short float
bool Geq::op(double a, SFlt b)
{   return (a >= b.floatval());
}

// long float >= short float
bool Geq::op(FLOAT_128 a, SFlt b)
{   return Float128::op(b) <= a;
}

// fixnum >= single float
bool Geq::op(Fixnum a, Flt b)
{   return Leq::op(b, a);
}

// bignum >= single float
bool Geq::op(uint64_t *a, Flt b)
{   return Leq::op(b, a);
}

// rational >= single float
bool Geq::op(Rat a, Flt b)
{   return Leq::op(b, a);
}

// complex >= single float
bool Geq::op(Cpx a, Flt b)
{   return Leq::op(b, a);
}

// short float >= single float
bool Geq::op(SFlt a, Flt b)
{   return Leq::op(b, a);
}

// single float >= single float
bool Geq::op(Flt a, Flt b)
{   return (a.floatval() >= b.floatval());
}

// double float >= single float
bool Geq::op(double a, Flt b)
{   return (a >= b.floatval());
}

// long float >= single float
bool Geq::op(FLOAT_128 a, Flt b)
{   return Float128::op(b) <= a;
}

// fixnum >= double float
bool Geq::op(Fixnum a, double b)
{   return Leq::op(b, a);
}

// bignum >= double float
bool Geq::op(uint64_t *a, double b)
{   return Leq::op(b, a);
}

// rational >= double float
bool Geq::op(Rat a, double b)
{   return Leq::op(b, a);
}

// complex >= double float
bool Geq::op(Cpx a, double b)
{   return false;
}

// short float >= double float
bool Geq::op(SFlt a, double b)
{   return Leq::op(b, a);
}

// single float >= double float
bool Geq::op(Flt a, double b)
{   return Leq::op(b, a);
}

// double float >= double float
bool Geq::op(double a, double b)
{   return (a >= b);
}

// long float >= double float
bool Geq::op(FLOAT_128 a, double b)
{   return Float128::op(b) <= a;
}

// fixnum >= long float
bool Geq::op(Fixnum a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// bignum >= long float
bool Geq::op(uint64_t *a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// rational >= long float
bool Geq::op(Rat a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// complex >= long float
bool Geq::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float >= long float
bool Geq::op(SFlt a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// single float >= long float
bool Geq::op(Flt a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// double float >= long float
bool Geq::op(double a, FLOAT_128 b)
{   return Leq::op(b, a);
}

// long float >= long float
bool Geq::op(FLOAT_128 a, FLOAT_128 b)
{   return b <= a;
}

// fixnum < fixnum

bool Lessp::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op((int64_t)int_of_fixnum(a),
                                        (int64_t)int_of_fixnum(b));
}

// bignum < fixnum
bool Lessp::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a, (int64_t)int_of_fixnum(b));
}

// rational < fixnum
bool Lessp::op(Rat a, Fixnum b)
{   // p/q < b if p < q*b
    return BoolBinary(Lessp, a.numerator(), Binary(Times, a.denominator(), int_of_fixnum(b)));
}

// complex < fixnum
bool Lessp::op(Cpx a, Fixnum b)
{   return false;
}

// short float < fixnum
bool Lessp::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), (int64_t)int_of_fixnum(b));
}

// single float < fixnum
bool Lessp::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), (int64_t)int_of_fixnum(b));
}

// double float < fixnum
bool Lessp::op(double a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a, (int64_t)int_of_fixnum(b));
}

// long float < fixnum
bool Lessp::op(FLOAT_128 a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a, (int64_t)int_of_fixnum(b));
}

// fixnum < bignum
bool Lessp::op(Fixnum a, uint64_t *b)
{   return Greaterp::op(b, a);
}

// bignum < bignum
bool Lessp::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a, b);
}

// rational < bignum
bool Lessp::op(Rat a, uint64_t *b)
{   return BoolBinary(Lessp, a.numerator(), Binary(Times, a.denominator(), bignum_value(b)));

}

// complex < bignum
bool Lessp::op(Cpx a, uint64_t *b)
{   return false;
}

// short float < bignum
bool Lessp::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>(a.floatval()), b);
}

// single float < bignum
bool Lessp::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>(a.floatval()), b);
}

// double float < bignum
bool Lessp::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a, b);
}

// long float < bignum
bool Lessp::op(FLOAT_128 a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a, b);
}

// fixnum < rational
bool Lessp::op(Fixnum a, Rat b)
{   return BoolBinary(Lessp, Binary(Times, a, b.denominator()), b.numerator());
}

// bignum < rational
bool Lessp::op(uint64_t *a, Rat b)
{   return BoolBinary(Lessp, Binary(Times, bignum_value(a), b.denominator()),
                             b.numerator());
}

// rational < rational
bool Lessp::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Lessp, Binary(Times, p1, q2), Binary(Times, p2, q1));
}

// complex < rational
bool Lessp::op(Cpx a, Rat b)
{   return false;
}

// short float < rational
bool Lessp::op(SFlt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d < 0.0;
    LispObject aa = N_rationalf(d);
    return Lessp::op(Rat(aa), b);
}

// single float < rational
bool Lessp::op(Flt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d < 0.0;
    LispObject aa = N_rationalf(d);
    return Lessp::op(Rat(aa), b);
}

// double float < rational
bool Lessp::op(double a, Rat b)
{   if (std::isnan(a)) return false;
    if (std::isinf(a)) return a < 0.0;
    LispObject aa = N_rationalf(a);
    return Lessp::op(Rat(aa), b);
}

// long float < rational
bool Lessp::op(FLOAT_128 a, Rat b)
{   FLOAT_128 d = a;
    if (isnan(d)) return false;         // a is a NaN
    if (isinf(d)) return signbit(d);    // a is infinite
    LispObject aa = N_rationalf128(d);
    return Lessp::op(Rat(aa), b);
}

// fixnum < complex
bool Lessp::op(Fixnum a, Cpx b)
{   return false;
}

// bignum < complex
bool Lessp::op(uint64_t *a, Cpx b)
{   return false;
}

// rational < complex
bool Lessp::op(Rat a, Cpx b)
{   return false;
}

// complex < complex
bool Lessp::op(Cpx a, Cpx b)
{   return false;
}

// short float < complex
bool Lessp::op(SFlt a, Cpx b)
{   return false;
}

// single float < complex
bool Lessp::op(Flt a, Cpx b)
{   return false;
}

// double float < complex
bool Lessp::op(double a, Cpx b)
{   return false;
}

// long float < complex
bool Lessp::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum < short float
bool Lessp::op(Fixnum a, SFlt b)
{   return Greaterp::op(b, a);
}

// bignum < short float
bool Lessp::op(uint64_t *a, SFlt b)
{   return Greaterp::op(b, a);
}

// rational < short float
bool Lessp::op(Rat a, SFlt b)
{   return Greaterp::op(b, a);
}

// complex < short float
bool Lessp::op(Cpx a, SFlt b)
{   return false;
}

// short float < short float
bool Lessp::op(SFlt a, SFlt b)
{   return (a.floatval() < b.floatval());
}

// single float < short float
bool Lessp::op(Flt a, SFlt b)
{   return (a.floatval() < b.floatval());
}

// double float < short float
bool Lessp::op(double a, SFlt b)
{   return (a < b.floatval());
}

// long float < short float
bool Lessp::op(FLOAT_128 a, SFlt b)
{   return a < Float128::op(b);
}

// fixnum < single float
bool Lessp::op(Fixnum a, Flt b)
{   return Greaterp::op(b, a);
}

// bignum < single float
bool Lessp::op(uint64_t *a, Flt b)
{   return Greaterp::op(b, a);
}

// rational < single float
bool Lessp::op(Rat a, Flt b)
{   return Greaterp::op(b, a);
}

// complex < single float
bool Lessp::op(Cpx a, Flt b)
{   return Greaterp::op(b, a);
}

// short float < single float
bool Lessp::op(SFlt a, Flt b)
{   return Greaterp::op(b, a);
}

// single float < single float
bool Lessp::op(Flt a, Flt b)
{   return (a.floatval() < b.floatval());
}

// double float < single float
bool Lessp::op(double a, Flt b)
{   return (a < b.floatval());
}

// long float < single float
bool Lessp::op(FLOAT_128 a, Flt b)
{   return a < Float128::op(b);
}

// fixnum < double float
bool Lessp::op(Fixnum a, double b)
{   return Greaterp::op(b, a);
}

// bignum < double float
bool Lessp::op(uint64_t *a, double b)
{   return Greaterp::op(b, a);
}

// rational < double float
bool Lessp::op(Rat a, double b)
{   return Greaterp::op(b, a);
}

// complex < double float
bool Lessp::op(Cpx a, double b)
{   return false;
}

// short float < double float
bool Lessp::op(SFlt a, double b)
{   return Greaterp::op(b, a);
}

// single float < double float
bool Lessp::op(Flt a, double b)
{   return Greaterp::op(b, a);
}

// double float < double float
bool Lessp::op(double a, double b)
{   return (a < b);
}

// long float < double float
bool Lessp::op(FLOAT_128 a, double b)
{   return a < Float128::op(b);
}

// fixnum < long float
bool Lessp::op(Fixnum a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// bignum < long float
bool Lessp::op(uint64_t *a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// rational < long float
bool Lessp::op(Rat a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// complex < long float
bool Lessp::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float < long float
bool Lessp::op(SFlt a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// single float < long float
bool Lessp::op(Flt a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// double float < long float
bool Lessp::op(double a, FLOAT_128 b)
{   return Greaterp::op(b, a);
}

// long float < long float
bool Lessp::op(FLOAT_128 a, FLOAT_128 b)
{   return a < b;
}

// fixnum <= fixnum

bool Leq::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Leq::op((int64_t)int_of_fixnum(a),
                                      (int64_t)int_of_fixnum(b));
}

// bignum <= fixnum
bool Leq::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a, (int64_t)int_of_fixnum(b));
}

// rational <= fixnum
bool Leq::op(Rat a, Fixnum b)
{   // p/q <= b if p <= q*b
    return BoolBinary(Leq, a.numerator(), Binary(Times, a.denominator(), int_of_fixnum(b)));
}

// complex <= fixnum
bool Leq::op(Cpx a, Fixnum b)
{   return false;
}

// short float <= fixnum
bool Leq::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>(a.floatval()),
                                      (int64_t)int_of_fixnum(b));
}

// single float <= fixnum
bool Leq::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>(a.floatval()),
                                     (int64_t)int_of_fixnum(b));
}

// double float <= fixnum
bool Leq::op(double a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a, (int64_t)int_of_fixnum(b));
}

// long float <= fixnum
bool Leq::op(FLOAT_128 a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a, (int64_t)int_of_fixnum(b));
}

// fixnum <= bignum
bool Leq::op(Fixnum a, uint64_t *b)
{   return Geq::op(b, a);
}

// bignum <= bignum
bool Leq::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a, b);
}

// rational <= bignum
bool Leq::op(Rat a, uint64_t *b)
{   return BoolBinary(Leq, a.numerator(), Binary(Times, a.denominator(), bignum_value(b)));

}

// complex <= bignum
bool Leq::op(Cpx a, uint64_t *b)
{   return false;
}

// short float <= bignum
bool Leq::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), b);
}

// single float <= bignum
bool Leq::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), b);
}

// double float <= bignum
bool Leq::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a, b);
}

// long float <= bignum
bool Leq::op(FLOAT_128 a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a, b);
}

// fixnum <= rational
bool Leq::op(Fixnum a, Rat b)
{   return BoolBinary(Leq, Binary(Times, a, b.denominator()), b.numerator());
}

// bignum <= rational
bool Leq::op(uint64_t *a, Rat b)
{   return BoolBinary(Leq, Binary(Times, bignum_value(a), b.denominator()), b.numerator());
}

// rational <= rational
bool Leq::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return BoolBinary(Leq, Binary(Times, p1, q2), Binary(Times, p2, q1));
}

// complex <= rational
bool Leq::op(Cpx a, Rat b)
{   return false;
}

// short float <= rational
bool Leq::op(SFlt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d < 0.0;
    LispObject aa = N_rationalf(d);
    return Leq::op(Rat(aa), b);
}

// single float <= rational
bool Leq::op(Flt a, Rat b)
{   double d = a.floatval();
    if (std::isnan(d)) return false;
    if (std::isinf(d)) return d < 0.0;
    LispObject aa = N_rationalf(d);
    return Leq::op(Rat(aa), b);
}

// double float <= rational
bool Leq::op(double a, Rat b)
{   if (std::isnan(a)) return false;
    if (std::isinf(a)) return a < 0.0;
    LispObject aa = N_rationalf(a);
    return Leq::op(Rat(aa), b);
}

// long float <= rational
bool Leq::op(FLOAT_128 a, Rat b)
{   FLOAT_128 d = a;
    if (isnan(d)) return false;          // a is a NaN
    if (isinf(d)) return signbit(d);     // a is infinite
    LispObject aa = N_rationalf128(d);
    return Leq::op(Rat(aa), b);
}

// fixnum <= complex
bool Leq::op(Fixnum a, Cpx b)
{   return false;
}

// bignum <= complex
bool Leq::op(uint64_t *a, Cpx b)
{   return false;
}

// rational <= complex
bool Leq::op(Rat a, Cpx b)
{   return false;
}

// complex <= complex
bool Leq::op(Cpx a, Cpx b)
{   return false;
}

// short float <= complex
bool Leq::op(SFlt a, Cpx b)
{   return false;
}

// single float <= complex
bool Leq::op(Flt a, Cpx b)
{   return false;
}

// double float <= complex
bool Leq::op(double a, Cpx b)
{   return false;
}

// long float <= complex
bool Leq::op(FLOAT_128 a, Cpx b)
{   return false;
}

// fixnum <= short float
bool Leq::op(Fixnum a, SFlt b)
{   return Geq::op(b, a);
}

// bignum <= short float
bool Leq::op(uint64_t *a, SFlt b)
{   return Geq::op(b, a);
}

// rational <= short float
bool Leq::op(Rat a, SFlt b)
{   return Geq::op(b, a);
}

// complex <= short float
bool Leq::op(Cpx a, SFlt b)
{   return false;
}

// short float <= short float
bool Leq::op(SFlt a, SFlt b)
{   return (a.floatval() <= b.floatval());
}

// single float <= short float
bool Leq::op(Flt a, SFlt b)
{   return (a.floatval() <= b.floatval());
}

// double float <= short float
bool Leq::op(double a, SFlt b)
{   return (a <= b.floatval());
}

// long float <= short float
bool Leq::op(FLOAT_128 a, SFlt b)
{   return a <= Float128::op(b);
}

// fixnum <= single float
bool Leq::op(Fixnum a, Flt b)
{   return Geq::op(b, a);
}

// bignum <= single float
bool Leq::op(uint64_t *a, Flt b)
{   return Geq::op(b, a);
}

// rational <= single float
bool Leq::op(Rat a, Flt b)
{   return Geq::op(b, a);
}

// complex <= single float
bool Leq::op(Cpx a, Flt b)
{   return Geq::op(b, a);
}

// short float <= single float
bool Leq::op(SFlt a, Flt b)
{   return Geq::op(b, a);
}

// single float <= single float
bool Leq::op(Flt a, Flt b)
{   return (a.floatval() <= b.floatval());
}

// double float <= single float
bool Leq::op(double a, Flt b)
{   return (a <= b.floatval());
}

// long float <= single float
bool Leq::op(FLOAT_128 a, Flt b)
{   return a <= Float128::op(b);
}

// fixnum <= double float
bool Leq::op(Fixnum a, double b)
{   return Geq::op(b, a);
}

// bignum <= double float
bool Leq::op(uint64_t *a, double b)
{   return Geq::op(b, a);
}

// rational <= double float
bool Leq::op(Rat a, double b)
{   return Geq::op(b, a);
}

// complex <= double float
bool Leq::op(Cpx a, double b)
{   return false;
}

// short float <= double float
bool Leq::op(SFlt a, double b)
{   return Geq::op(b, a);
}

// single float <= double float
bool Leq::op(Flt a, double b)
{   return Geq::op(b, a);
}

// double float <= double float
bool Leq::op(double a, double b)
{   return (a <= b);
}

// long float <= double float
bool Leq::op(FLOAT_128 a, double b)
{   return a <= Float128::op(b);
}

// fixnum <= long float
bool Leq::op(Fixnum a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// bignum <= long float
bool Leq::op(uint64_t *a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// rational <= long float
bool Leq::op(Rat a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// complex <= long float
bool Leq::op(Cpx a, FLOAT_128 b)
{   return false;
}

// short float <= long float
bool Leq::op(SFlt a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// single float <= long float
bool Leq::op(Flt a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// double float <= long float
bool Leq::op(double a, FLOAT_128 b)
{   return Geq::op(b, a);
}

// long float <= long float
bool Leq::op(FLOAT_128 a, FLOAT_128 b)
{   return a <= b;
}

bool Onep::op(Fixnum a)
{   return a == fixnum_of_int(1);
}

bool Onep::op(uint64_t *a)
{   return false;
}

bool Onep::op(Rat a)
{   return BoolUnary(Onep, a.numerator()) && BoolUnary(Onep, a.denominator());
}

bool Onep::op(Cpx a)
{   return BoolUnary(Onep, a.real_part()) && BoolUnary(Zerop, a.imag_part());
}

bool Onep::op(SFlt a)
{   return a.floatval() == 1.0;
}

bool Onep::op(Flt a)
{   return a.floatval() == 1.0;
}

bool Onep::op(double a)
{   return a == 1.0;
}

bool Onep::op(FLOAT_128 a)
{   return a == LF_C(1.0);
}

bool MinusOnep::op(Fixnum a)
{   return a == fixnum_of_int(-1);
}

bool MinusOnep::op(uint64_t *a)
{   return false;
}

bool MinusOnep::op(Rat a)
{   return BoolUnary(MinusOnep, a.numerator()) &&
           BoolUnary(Onep, a.denominator());
}

bool MinusOnep::op(Cpx a)
{   return BoolUnary(MinusOnep, a.real_part()) &&
           BoolUnary(Zerop, a.imag_part());
}

bool MinusOnep::op(SFlt a)
{   return a.floatval() == -1.0;
}

bool MinusOnep::op(Flt a)
{   return a.floatval() == -1.0;
}

bool MinusOnep::op(double a)
{   return a == -1.0;
}

bool MinusOnep::op(FLOAT_128 a)
{   return a == -LF_C(1.0);
}

bool Zerop::op(Fixnum a)
{   return a == fixnum_of_int(0);
}

bool Zerop::op(uint64_t *a)
{   return false;
}

bool Zerop::op(Rat a)
{   return BoolUnary(Zerop, a.numerator());
}

bool Zerop::op(Cpx a)
{   return BoolUnary(Zerop, a.real_part()) &&
           BoolUnary(Zerop, a.imag_part());
}

bool Zerop::op(SFlt a)
{   return a.floatval() == 0.0;
}

bool Zerop::op(Flt a)
{   return a.floatval() == 0.0;
}

bool Zerop::op(double a)
{   return a == 0.0;
}

bool Zerop::op(FLOAT_128 a)
{   return a == LF_C(0.0);
}

bool Oddp::op(Fixnum a)
{   return (int_of_fixnum(a) & 1) != 0;
}

bool Oddp::op(uint64_t *a)
{   return (a[0] & 1) != 0;
}

bool Evenp::op(Fixnum a)
{   return (int_of_fixnum(a) & 1) == 0;
}

bool Evenp::op(uint64_t *a)
{   return (a[0] & 1) == 0;
}

bool Minusp::op(Fixnum a)
{   return a < 0;
}

bool Minusp::op(uint64_t *a)
{   return arithlib_lowlevel::Minusp::op(a);
}

bool Minusp::op(Rat a )
{   return BoolUnary(Minusp, a.numerator());
}

bool Minusp::op(Cpx a)
{   return false;
}

bool Minusp::op(SFlt a)
{   return a.floatval() < 0.0;
}

bool Minusp::op(Flt a)
{   return a.floatval() < 0.0;
}

bool Minusp::op(double a)
{   return a < 0.0;
}

// Note that minusp (-0) will yield false here...
bool Minusp::op(FLOAT_128 a)
{   return a < LF_C(0.0);
}

bool Plusp::op(Fixnum a)
{   return a > fixnum_of_int(0);
}

bool Plusp::op(uint64_t *a)
{   return arithlib_lowlevel::Plusp::op(a);
}

bool Plusp::op(Rat a )
{   return BoolUnary(Plusp, a.numerator());
}

bool Plusp::op(Cpx a)
{   return false;
}

bool Plusp::op(SFlt a)
{   return a.floatval() > 0.0;
}

bool Plusp::op(Flt a)
{   return a.floatval() > 0.0;
}

bool Plusp::op(double a)
{   return a > 0.0;
}

bool Plusp::op(FLOAT_128 a)
{   return LF_C(0.0) < a;
}

LispObject Abs::op(Fixnum a)
{   if (a < 0) return Minus::op(a);
    else return a;
}

LispObject Abs::op(uint64_t *a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return static_cast<LispObject>((uintptr_t)a - 8 + TAG_NUMBERS);
}

LispObject Abs::op(Rat a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(Cpx a)
{   return Unary(Sqrt, Binary(Plus, Unary(Square, a.real_part()),
                                    Unary(Square, a.imag_part())));
}

LispObject Abs::op(SFlt a)
{   if (value_of_immediate_float(a.value()) < 0.0) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(Flt a)
{   if (a.floatval() < 0.0) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(double a)
{   if (a < 0.0) return make_boxfloat(-a);
    else return make_boxfloat(a);
}

LispObject Abs::op(FLOAT_128 a)
{   if (a.signbit()) return make_boxfloat128(-a);
    else return make_boxfloat128(a);
}

LispObject Nonep(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && BoolUnary(Onep, a1));
}

LispObject Nevenp(LispObject env, LispObject a1)
{   return onebool(IBoolUnary(Evenp, a1));
}

LispObject Noddp(LispObject env, LispObject a1)
{   return onebool(IBoolUnary(Oddp, a1));
}

LispObject Nzerop(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && BoolUnary(Zerop, a1));
}

LispObject Nminusp(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && BoolUnary(Minusp, a1));
}

LispObject Nplusp(LispObject env, LispObject a1)
{   return onebool(is_number(a1) && BoolUnary(Plusp, a1));
}

LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(BoolBinary(Greaterp, a1, a2));
}

LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                     LispObject a3)
{   return onebool(BoolBinary(Greaterp, a1, a2) &&
                   BoolBinary(Greaterp, a2, a3));
}

LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                     LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Greaterp, a1, a2)) return nil;
    if (!BoolBinary(Greaterp, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Greaterp, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Geq, a1, a2));
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Geq, a1, a2) && BoolBinary(Geq, a2, a3));
}

LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Geq, a1, a2)) return nil;
    if (!BoolBinary(Geq, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Geq, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Lessp, a1, a2));
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Lessp, a1, a2) && BoolBinary(Lessp, a2, a3));
}

LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Lessp, a1, a2)) return nil;
    if (!BoolBinary(Lessp, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Lessp, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Leq, a1, a2));
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Leq, a1, a2) &&
                   BoolBinary(Leq, a2, a3));
}

LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Leq, a1, a2)) return nil;
    if (!BoolBinary(Leq, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Leq, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    if (a1 == a2) return lisp_true;
    if (!is_number(a1) || !is_number(a2)) return nil;
    return onebool(BoolBinary(Eqn, a1, a2));
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    if (a1 == a2 && a2 == a3) return lisp_true;
    if (!is_number(a1) || !is_number(a2) || !is_number(a3)) return nil;
    return onebool(BoolBinary(Eqn, a1, a2) &&
                   BoolBinary(Eqn, a2, a3));
}

LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (a1 != a2 || !is_number(a1) || !is_number(a2) ||
       !BoolBinary(Eqn, a1, a2)) return nil;
    if (a2 != a3 || !is_number(a3) || !BoolBinary(Eqn, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   a3 = car(a4plus);
        if (a2 != a3 || !is_number(a3) || BoolBinary(Eqn, a2, a3)) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(CLEqn, a1, a2));
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(CLEqn, a1, a2) &&
                   BoolBinary(CLEqn, a2, a3));
}

LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(CLEqn, a1, a2)) return nil;
    if (!BoolBinary(CLEqn, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(CLEqn, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Neqn, a1, a2));
}

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Neqn, a1, a2) && BoolBinary(Neqn, a2, a3) &&
                   BoolBinary(Neqn, a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Neqn, a1, a2)) return nil;
    if (!BoolBinary(Neqn, a2, a3)) return nil;
    if (!BoolBinary(Neqn, a1, a3)) return nil;
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!BoolBinary(Neqn, a1, a)) return nil;
        if (!BoolBinary(Neqn, a2, a)) return nil;
        if (!BoolBinary(Neqn, a3, a)) return nil;
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!BoolBinary(Neqn, a, car(w))) return nil;
        }
    }
    return lisp_true;
}

LispObject Nmax(LispObject env)
{   SingleValued fn;
    return aerror("max called witout arguments");
}

LispObject Nmax(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    if (BoolBinary(Lessp, a1, a2)) return a2;
    return a1;
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    if (BoolBinary(Lessp, a1, a2)) a1 = a2;
    if (BoolBinary(Lessp, a1, a3)) a1 = a3;
    return a1;
}

LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (BoolBinary(Lessp, a1, a2)) a1 = a2;
    if (BoolBinary(Lessp, a1, a3)) a1 = a3;
    while (is_cons(a4plus))
    {   LispObject w = car(a4plus);
        if (BoolBinary(Lessp, a1, w)) a1 = w;
        a4plus = cdr(a4plus);
    }
    return a1;
}

LispObject Nmin(LispObject env)
{   SingleValued fn;
    return aerror("min called witout arguments");
}

LispObject Nmin(LispObject env, LispObject a1)
{   SingleValued fn;
    return a1;
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    if (BoolBinary(Greaterp, a1, a2)) return a2;
    return a1;
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    if (BoolBinary(Greaterp, a1, a2)) a1 = a2;
    if (BoolBinary(Greaterp, a1, a3)) a1 = a3;
    return a1;
}

LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (BoolBinary(Greaterp, a1, a2)) a1 = a2;
    if (BoolBinary(Greaterp, a1, a3)) a1 = a3;
    while (is_cons(a4plus))
    {   LispObject w = car(a4plus);
        if (BoolBinary(Greaterp, a1, w)) a1 = w;
        a4plus = cdr(a4plus);
    }
    return a1;
}

LispObject Nionep(LispObject env, LispObject a1)
{   SingleValued fn;
    return onebool(BoolUnary(Onep, a1));
}

LispObject Nievenp(LispObject env, LispObject a1)
{   SingleValued fn;
    return onebool(IBoolUnary(Evenp, a1));
}

LispObject Nioddp(LispObject env, LispObject a1)
{   SingleValued fn;
    return onebool(IBoolUnary(Oddp, a1));
}

LispObject Nizerop(LispObject env, LispObject a1)
{   SingleValued fn;
    return onebool(BoolUnary(Zerop, a1));
}

LispObject Niminusp(LispObject env, LispObject a1)
{   SingleValued fn;
    return onebool(BoolUnary(Minusp, a1));
}

LispObject Niminus(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Minus, a1);
}

LispObject Niabs(LispObject env, LispObject a1)
{   SingleValued fn;
    return Unary(Abs, a1);
}

LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Greaterp, a1, a2));
}

LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Greaterp, a1, a2) && BoolBinary(Greaterp, a2, a3));
}

LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2,
                                      LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Greaterp, a1, a2)) return nil;
    if (!BoolBinary(Greaterp, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Greaterp, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Geq, a1, a2));
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Geq, a1, a2) && BoolBinary(Geq, a2, a3));
}

LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Geq, a1, a2)) return nil;
    if (!BoolBinary(Geq, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Geq, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nilessp(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Lessp, a1, a2));
}

LispObject Nilessp(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Lessp, a1, a2) && BoolBinary(Lessp, a2, a3));
}

LispObject Nilessp(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Lessp, a1, a2)) return nil;
    if (!BoolBinary(Lessp, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Lessp, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Leq, a1, a2));
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Leq, a1, a2) && BoolBinary(Leq, a2, a3));
}

LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Leq, a1, a2)) return nil;
    if (!BoolBinary(Leq, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Leq, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Eqn, a1, a2));
}

LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Eqn, a1, a2) &&
                   BoolBinary(Eqn, a2, a3));
}

LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2,
                                   LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Eqn, a1, a2)) return nil;
    if (!BoolBinary(Eqn, a2, a3)) return nil;
    a2 = a3;
    while (is_cons(a4plus))
    {   if (BoolBinary(Eqn, a2, a3 = car(a4plus))) return nil;
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return lisp_true;
}

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2)
{   SingleValued fn;
    return onebool(BoolBinary(Neqn, a1, a2));
}

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2, LispObject a3)
{   SingleValued fn;
    return onebool(BoolBinary(Neqn, a1, a2) && BoolBinary(Neqn, a2, a3) &&
                   BoolBinary(Neqn, a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all are distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                                  LispObject a3, LispObject a4plus)
{   SingleValued fn;
    if (!BoolBinary(Neqn, a1, a2)) return nil;
    if (!BoolBinary(Neqn, a2, a3)) return nil;
    if (!BoolBinary(Neqn, a1, a3)) return nil;
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!BoolBinary(Neqn, a1, a)) return nil;
        if (!BoolBinary(Neqn, a2, a)) return nil;
        if (!BoolBinary(Neqn, a3, a)) return nil;
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!BoolBinary(Neqn, a, car(w))) return nil;
        }
    }
    return lisp_true;
}

#endif // ARITHLIB

} // end of namespace

// end of arith-compare.cpp
