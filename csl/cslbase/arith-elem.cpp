// arith-elem.cpp                               Copyright (C) 2026 Codemist

//
// Support for elementary functions with the arithlib.cpp package.
//

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


// $Id$


#include "headers.h"

/*****************************************************************************/
//**              Transcendental functions etcetera.                       **
/*****************************************************************************/

namespace CSL_LISP
{

// where the imaginary part is zero ought I to reduce it to a real
// value?

static LispObject make_complex_float(std::complex<double> v, LispObject a)
// Here a complex result has been been computed (with double precision values
// for both real and imag parts).  Squash to the required floating point
// types and package up as a complex value, where (a) was the original input
// value and so should defined the type needed.  Note that both
// components of a will have the same type so only one needs testing.
//
// Note that regardless of their input type the elementary functions deliver
// at most double precision results.
{   FloatType type;
    LispObject a1, a2;
    a = real_part(a);
    if (is_sfloat(a))
        return make_complex(pack_immediate_float(real(v), a),
                            pack_immediate_float(imag(v), a));
    if (is_bfloat(a)) type = floatWant(flthdr(a));
    else type = WANT_SINGLE_FLOAT;
    if (type == WANT_LONG_FLOAT) type = WANT_DOUBLE_FLOAT;
// There are MANY uses of make_boxfloat here. In pretty well all cases I let
// make_boxfloat do any overflow checks, and I do not support 128-bit floats.
    a1 = make_boxfloat(real(v), type);
    a2 = make_boxfloat(imag(v), type);
    a1 = make_complex(a1, a2);
    return a1;
}

static LispObject make_complex128(COMPLEX_128 v)
{   LispObject a1, a2;
    a1 = make_boxfloat128(v.real());
    a2 = make_boxfloat128(v.imag());
    a1 = make_complex(a1, a2);
    return a1;
}

static LispObject trigfn(unsigned int which_one, LispObject a);

static LispObject makenum(LispObject a, int32_t n)
// Make the value n, but type-consistent with the object a.  Usually
// used with n=0 or n=1
{
#ifndef COMMON
    FloatType restype = WANT_DOUBLE_FLOAT;
#else
    FloatType restype = WANT_SINGLE_FLOAT;
#endif
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            if (is_sfloat(a))
                return pack_immediate_float(static_cast<double>(n), a);
            else return fixnum_of_int(n);
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_NEW_BIGNUM:
                case TYPE_RATNUM:
                    return fixnum_of_int(n);
                case TYPE_COMPLEX_NUM:
                {   LispObject rr, ii;
                    a = real_part(a);
                    rr = makenum(a, 1);
                    ii = makenum(a, 0);
                    a = make_complex(rr, ii);
                    return a;
                }
            }
            return aerror1("bad arg for makenumber",  a);
        }
        case TAG_BOXFLOAT:
            restype = floatWant(flthdr(a));
            if (restype == WANT_LONG_FLOAT)
                return make_boxfloat128(
                    float128_of_number(fixnum_of_int(n)));
            return make_boxfloat(static_cast<double>(n), restype);
        default:
            return aerror1("bad arg for makenumber",  a);
    }
}

static std::complex<double> complex_of_number(LispObject a)
{   std::complex<double> z;
    if (is_numbers(a) && is_complex(a))
    {   z.real(float_of_number(real_part(a)));
        z.imag(float_of_number(imag_part(a)));
    }
    else
    {   z.real(float_of_number(a));
        z.imag(0.0);
    }
    return z;
}

static LispObject CSLpowi(LispObject a, uint64_t n)
// Raise a to the power n by repeated multiplication. The name is CSLpowi
// rather than just powi because some miserable C compilers come with an
// external function called powi in <cmath> and then moan about the
// name clash.
{   if (n == 0) return makenum(a, 1); // value 1 of appropriate type
    else if (n == 1) return a;
    else if ((n & 1) == 0)
    {   a = CSLpowi(a, n/2);
        errexit();
        return Times::op(a, a);
    }
    else
    {   LispObject b;
        b = CSLpowi(a, n/2);
        errexit();
        b = Times::op(b, b);
        errexit();
        return Times::op(a, b);
    }
}

LispObject Nexpt(LispObject env, LispObject a, LispObject b)
{   SingleValued fn;
    if (!is_number(a) || !is_number(b)) return aerror2("expt", a, b);
    double d, e;
    FloatType restype, n;
    int64_t nn;
    LispObject w;
    std::complex<double> c1, c2, c3;
// I take special action on 1, 0 and -1 raised to a power that is an integer
// or a bignum. In part this is because raising 1 to a power may be a fairly
// common case worthy of special care, but the main pressure came because
// these numbers raised to bignum powers can still have fixnum results, and
// the value can be computed fast. I am not doing this for -1.0, 0.0 or 1.0.
    if (a == fixnum_of_int(1) ||
        a == fixnum_of_int(0) ||
        a == fixnum_of_int(-1))
    {   if (is_fixnum(b))
        {   nn = int_of_fixnum(b);
            switch (int_of_fixnum(a))
            {   case 1:  return a;
                case 0:  if (nn < 0) return aerror2("expt", a, b);
                    // In Common Lisp (expt 0 0) is defined to be 0
                    else if (nn == 0) return fixnum_of_int(1);
                    else return a;
                case -1: if (nn & 1) return a;
                    else return fixnum_of_int(1);
            }
        }
        else if (is_numbers(b) && is_bignum(b))
        {   switch (int_of_fixnum(a))
            {   case 1:  return a;
                case 0:  nn = bignum_digits(b)[(bignum_length(b)-CELL-4)/4];
                    if (nn <= 0) return aerror2("expt", a, b);
                    else return a;
                case -1: nn = bignum_digits(b)[0];
                    if (nn & 1) return a;
                    else return fixnum_of_int(1);
            }
        }
    }
// In a similar vein I will take special action on #C(0 1) and #C(0 -1)
// raise to integer (including bignum) powers. Note that these are complex
// values with integer components.
    if (is_numbers(a) && is_complex(a) &&
        real_part(a)==fixnum_of_int(0) &&
        (imag_part(a) == fixnum_of_int(1) ||
         imag_part(a) == fixnum_of_int(-1)))
    {   nn = -1;
        if (is_fixnum(b)) nn = int_of_fixnum(b) & 3;
        else if (is_numbers(b) && is_bignum(b))
            nn = bignum_digits(b)[0] & 3;
        switch (nn)
        {   case 0:   return fixnum_of_int(1);
            case 2:   return fixnum_of_int(-1);
            case 1:
            case 3:   if (int_of_fixnum(imag_part(a)) == 1) nn ^= 2;
                a = make_complex(fixnum_of_int(0),
                                 fixnum_of_int((nn & 2) ? 1 : -1));
                return a;
            default:  break;
        }
    }
    if (is_fixnum(b))   // bignum exponents would yield silly values!
    {   nn = int_of_fixnum(b);
        if (nn == 1) return a;
        if (nn < 0)
        {
// With floating point value if I compute a^(-n) as 1.0/a^n then I can get
// premature overflow, and indeed an exception from overflow (if I am in
// exception-raising mode) when the result would be finite - in particular
// if the result is a denormalised value.
// I worry that if instead I compute (1.0/a)^n that rounding in computing
// 1.0/a could be amplified unduly. But still that is what I do.
#ifdef COMMON
            a = CLQuotient::op(fixnum_of_int(1), a);
#else
            a = Quotient::op(fixnum_of_int(1), a);
#endif
            a = CSLpowi(a, -nn);
        }
        else a = CSLpowi(a, nn);
        return a;
    }
    if (is_numbers(a) && is_complex(a)) w = real_part(a);
    else w = a;
    if (is_sfloat(w)) restype = WANT_SHORT_FLOAT;
    else if (is_bfloat(w)) restype = floatWant(flthdr(w));
    else restype = WANT_SINGLE_FLOAT;
    if (is_numbers(b) && is_complex(b)) w = real_part(b);
    else w = b;
    if (is_bfloat(w))
    {   n = floatWant(flthdr(w));
        if (restype == WANT_SHORT_FLOAT || restype == WANT_SINGLE_FLOAT ||
            (restype == WANT_DOUBLE_FLOAT && n == WANT_LONG_FLOAT))
            restype = n;
    }
    else if (restype == WANT_SHORT_FLOAT) restype = WANT_SINGLE_FLOAT;
    if (restype == WANT_LONG_FLOAT)
    {   FLOAT_128 aa = float128_of_number(a);
        FLOAT_128 bb = float128_of_number(b);
        FLOAT_128 rr = expt(aa, bb);
        return make_boxfloat128(rr);
    }
    if ((is_numbers(a) && is_complex(a)) ||
        (is_numbers(b) && is_complex(b)))
    {   c1 = complex_of_number(a);
        c2 = complex_of_number(b);
        c3 = std::pow(c1, c2);
        a = make_boxfloat(real(c3), restype);
        b = make_boxfloat(imag(c3), restype);
        a = make_complex(a, b);
        return a;
    }
    d = float_of_number(a);
    e = float_of_number(b);
// If I have a real number raised to a negative real power I will treat
// it as an error.
    if (d < 0.0) return aerror2("expt", a, b);
    d = CSLpow(d, e);
    a = make_boxfloat(d, restype);
    return a;
}

// This list of functions gets used several times.
// (1) it sets up enum_acos = 0, enum_acosd = 0 etc
// (2) Lacos(LispObject a) { return trigfn(enum_acos, a); }
// (3) a table such that accessing the enum_acos entry gives you
//     a struct containing versions of that function for double,
//     complex double, FLOAT_128 and COMPLEX_128 arguments.

// NB where there may be a "crlibm" version of the double->double
// function available I use eg CSLsin etc which will map to it.

#define functions \
    FF(acos,     CSLacos,      std::acos,      acos,      acos) \
    FF(acosd,    acosd,        nullptr,        acosd,     nullptr) \
    FF(acosh,    std::acosh,   std::acosh,     acosh,     acosh) \
    FF(acot,     acot,         acot,           acot,      acot) \
    FF(acotd,    acotd,        nullptr,        acotd,     nullptr) \
    FF(acoth,    acoth,        acoth,          acoth,     acoth) \
    FF(acsc,     acsc,         acsc,           acsc,      acsc) \
    FF(acscd,    acscd,        nullptr,        acscd,     nullptr) \
    FF(acsch,    acsch,        acsch,          acsch,     acsch) \
    FF(asec,     asec,         asec,           asec,      asec) \
    FF(asecd,    asecd,        nullptr,        asecd,     nullptr) \
    FF(asech,    asech,        asech,          asech,     asech) \
    FF(asin,     CSLasin,      std::asin,      asin,      asin) \
    FF(asind,    asind,        nullptr,        asind,     nullptr) \
    FF(asinh,    std::asinh,   std::asinh,     asinh,     asinh) \
    FF(atan,     CSLatan,      std::atan,      atan,      atan) \
    FF(atand,    atand,        nullptr,        atand,     nullptr) \
    FF(atanh,    std::atanh,   std::atanh,     atanh,     atanh) \
    FF(cbrt,     std::cbrt,    cbrt,           cbrt,      cbrt) \
    FF(cos,      CSLcos,       std::cos,       cos,       cos) \
    FF(cosd,     cosd,         nullptr,        cosd,      nullptr) \
    FF(cosh,     CSLcosh,      std::cosh,      cosh,      cosh) \
    FF(cot,      cot,          cot,            cot,       cot) \
    FF(cotd,     cotd,         nullptr,        cotd,      nullptr) \
    FF(coth,     coth,         coth,           coth,      coth) \
    FF(csc,      csc,          csc,            csc,       csc) \
    FF(cscd,     cscd,         nullptr,        cscd,      nullptr) \
    FF(csch,     csch,         csch,           csch,      csch) \
    FF(exp,      CSLexp,       std::exp,       exp,       exp) \
    FF(expm1,    std::expm1,   expm1,          expm1,     expm1) \
    FF(ln,       ln,           ln,             ln,        ln) \
    FF(log,      CSLlog,       std::log,       log,       log) \
    FF(log10,    CSLlog10,     log10,          log10,     log10) \
    FF(log1p,    std::log1p,   nullptr,        log1p,     nullptr) \
    FF(log2,     CSLlog2,      nullptr,        log2,      nullptr) \
    FF(sec,      sec,          sec,            sec,       sec) \
    FF(secd,     secd,         nullptr,        secd,      nullptr) \
    FF(sech,     sech,         sech,           sech,      sech) \
    FF(sin,      CSLsin,       std::sin,       sin,       sin) \
    FF(sind,     sind,         nullptr,        sind,      nullptr) \
    FF(sinh,     CSLsinh,      std::sinh,      sinh,      sinh) \
    FF(sqrt,     std::sqrt,    std::sqrt,      sqrt,      sqrt) \
    FF(rsqrt,    rsqrt,        rsqrt,          rsqrt,     rsqrt) \
    FF(tan,      CSLtan,       std::tan,       tan,       tan) \
    FF(tand,     tand,         nullptr,        tand,      nullptr) \
    FF(tanh,     std::tanh,    std::tanh,      tanh,      tanh)

#define FF(a,b,c,d,e) enum_ ## a,

enum
{   functions
    FFend
};
#undef FF

#define FF(a,b,c,d,e) \
LispObject N ## a (LispObject env, LispObject a1) \
{   SingleValued fn; \
    return trigfn(enum_ ## a, a1); \
}

functions

#undef FF

using f64f64 = double (*)(double);
using c64c64 = std::complex<double> (*)(const std::complex<double>&);

using f128f128 = FLOAT_128 (*)(FLOAT_128);
using c128c128 = COMPLEX_128 (*)(COMPLEX_128);

struct fn_definitions
{
    f64f64 f64;
    c64c64 c64;
    f128f128 f128;
    c128c128 c128;
};

#define FF(a,b,c,d,e) {b, c, d, e},

fn_definitions function_table[] =
{   functions
    {nullptr, nullptr, nullptr, nullptr}
};

//  {"atan",     f64atan2,     c64atan2,       f128atan,      c128atan},
//  {"atand",    f64atan2d,    nullptr,        f128atand,     nullptr},
//  {"expt",     f64expt,      c64expt,        f128expt,      c128expt},
//  {"hypot",    f64hypot,     c64hypot,       f128hypot,     c128hypot},


// At present atan9 and atan2d do not handle FLOAT_128 and that is bad.
// But for now I just want files that lead to code that links!

LispObject Natan2(LispObject env, LispObject y, LispObject x)
{   SingleValued fn;
    double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
// Here I am assuming IEEE arithmetic and hence that a division by zero
// just yields an infinity, not an error.
    else if (u >= 0.0) r = CSLatan(v/u);
// On the next line x was negative so I will be careful about the sign
// of a zero value for y because the negative real axis is a branch cut.
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
// The adjustment here is done by computing pi/2+atan(-u/v) rather
// than as pi-atan(-v/u) to reduce risk of cancellation errors.
        r = M_PI_2 + CSLatan(-u/v);
    else r = -M_PI_2 - CSLatan(u/v);
    x = make_boxfloat(r, WANT_DOUBLE_FLOAT);
    return x;
}

LispObject Natan2d(LispObject env, LispObject y, LispObject x)
{   SingleValued fn;
    double u, v, r;
    u = float_of_number(x);
    v = float_of_number(y);
    if (u == 0.0 && v == 0.0) r = 0.0; // really an error case
    else if (u >= 0.0) r = (180.0*M_1_PI)*CSLatan(v/u);
    else if (v > 0.0 || (v == 0.0 && 1.0/v > 0.0))
        r = 90.0 + (180.0*M_1_PI)*CSLatan(-u/v);
    else r = -90.0 - (180.0*M_1_PI)*CSLatan(u/v);
    x = make_boxfloat(r, WANT_DOUBLE_FLOAT);
    return x;
}

// 2-arg log is logarithm to a specified base.

LispObject Nlog_2(LispObject env, LispObject a, LispObject b)
// Log with specified base.
{   SingleValued fn;
    a = Nlog(nil, a);
    errexit();
    b = Nlog(nil, b);
    errexit();
    return Quotient::op(a, b);
}

// hypotenuse is not done yet

LispObject Nhypot(LispObject env, LispObject x, LispObject y)
{   SingleValued fn;
// This version does not avoid premature underfow or overflow when the
// arguments are floating point.
    x = Plus::op(Square::op(x), Square::op(y));
    return Nsqrt(nil, x);
}

LispObject Nisqrt(LispObject, LispObject a)
{   SingleValued fn;
    double d;
// This makes some pretence at computing an integer square root, but it
// does so incredibly clumsily by mapping onto a floating point value and
// then expecting the square root computed that way to fit into a fixnum,
// ie to be at worst 27 or 60 bits long. That is not at all good enough for
// serious use.
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
            d = static_cast<double>(int_of_fixnum(a));
            break;
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_NEW_BIGNUM:
                    d = float_of_number(a);
                    break;
                default:
                    return aerror1("bad arg for isqrt",  a);
            }
            break;
        }
        default:
            return aerror1("bad arg for isqrt",  a);
    }
    d = std::sqrt(d);
// /* This is not anything like good enough yet
    return fixnum_of_int((int32_t)d);
}

LispObject Nabsval(LispObject env, LispObject a)
// I call this Labsval not Labs because a non-case-sensitive linker
// would confuse Labs with labs, and labs is defined in the C libraries...
// Of course I do not think that case-insensitive linkers should be allowed
// to remain in service....
{   SingleValued fn;
    switch (static_cast<int>(a) & TAG_BITS)
    {   case TAG_FIXNUM:
//      case XTAG_SFLOAT:
            break;
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_RATNUM:
                case TYPE_NEW_BIGNUM:
                    break;
                case TYPE_COMPLEX_NUM:
                {   std::complex<double> c1;
                    double d;
                    c1.real(float_of_number(real_part(a)));
                    c1.imag(float_of_number(imag_part(a)));
                    d = std::abs(c1);
// /* I wonder if I am allowed to promote short or single values to
//    double precision here?
                    a = make_boxfloat(d, WANT_DOUBLE_FLOAT);
                    return a;
                }
                default:
                    return aerror1("bad arg for abs",  a);
            }
            break;
        }
        case TAG_BOXFLOAT:
            break;
        default:
            return aerror1("bad arg for abs",  a);
    }
    if (Minusp::op(a)) a = Minus::op(a);
    return a;
}

LispObject Nphase(LispObject env, LispObject a)
{   SingleValued fn;
    bool s;
    double d;
    if (is_numbers(a) && is_complex(a))
        return Natan2(nil, imag_part(a), real_part(a));
    s = Minusp::op(a);
    if (s) d = -M_PI;
    else d = M_PI;
    a = make_boxfloat(d, WANT_DOUBLE_FLOAT);
    return a;
// /* Wrong precision, I suspect! If I have a short, single or long float as
// input that should set the type of the output.
}

LispObject Nsignum(LispObject env, LispObject a)
{   SingleValued fn;
//* This seems an expensive way of doing things - huh? Maybe complex values?
    bool z;
    LispObject w;
    z = Nzerop(nil, a);
    if (z != nil) return a;
    w = Nabsval(nil, a);
    errexit();
    a = Quotient::op(a, w);
    return a;
}

LispObject Ncis(LispObject, LispObject a)
// Implement as exp(i*a) - this permits complex args which goes
// beyond the specification of Common Lisp.
{   SingleValued fn;
    LispObject ii;
    ii = make_complex(fixnum_of_int(0), fixnum_of_int(1));
    errexit();
// it seems a bit gross to multiply by i by calling times2(), but
// doing so avoids loads of messy type dispatch code here and
// I am not over-worried about performance at this level (yet).
    a = Times::op(a, ii);
    return Nexp(nil, a);
}


// This one piece of code does the type-dispatch for the main collection
// of elementary functions.

static LispObject trigfn(unsigned int which_one, LispObject a)
{   double d;
#ifndef COMMON
    FloatType restype = WANT_DOUBLE_FLOAT;
#else
// single floats seem to me to be a bad idea! But they are the default
// for Common Lisp. Boo Hiss. Well that may be re-settable.
    FloatType restype = WANT_SINGLE_FLOAT;
#endif
    switch (static_cast<int>(a) & TAG_BITS)
    {
// In almost all cases I will convert the argument to a double.
        case TAG_FIXNUM:
            if (is_sfloat(a))
            {   d = value_of_immediate_float(a);
                restype = WANT_SHORT_FLOAT;
                break;
            }
            else d = static_cast<double>(int_of_fixnum(a));
            break;
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                case TYPE_NEW_BIGNUM:
                case TYPE_RATNUM:
                    d = float_of_number(a);
                    break;
                case TYPE_COMPLEX_NUM:
                {   if (is_long_float(real_part(a)) ||
                        is_long_float(imag_part(a)))
                    {   COMPLEX_128 c1, c2;
                        c1 = COMPLEX_128(
                            float128_of_number(real_part(a)),
                            float128_of_number(imag_part(a)));
                        c2 = (*function_table[which_one].c128)(c1);
                        return make_complex128(c2);
                    }
                    std::complex<double> c1 = {
                        float_of_number(real_part(a)),
                        float_of_number(imag_part(a))};
                    std::complex<double> c2 =
                        (*function_table[which_one].c64)(c1);
                    return make_complex_float(c2, a);
                }
                default:
                    return aerror1("bad arg for trig function",  a);
            }
            break;
        }
        case TAG_BOXFLOAT:
            restype = floatWant(flthdr(a));
            if (restype == WANT_LONG_FLOAT)
            {   FLOAT_128 dd = float128_of_number(a);
                FLOAT_128 (*rl)(FLOAT_128) = function_table[which_one].f128;
                FLOAT_128 r = (*rl)(dd);
                if (isnan(r)) return aerror("argument out of range");
                return make_boxfloat128(r);
            }
            d = float_of_number(a);
            break;
        default:
            return aerror1("bad arg for trig function",  a);
    }
    {   double (*rl)(double) = function_table[which_one].f64;
        double r = (*rl)(d);
        if (std::isnan(r)) return aerror("argument out of range");
        return make_boxfloat(r, restype);
    }
}

} // end of namespace

// end of arith-elem.cpp
