//  arith11.cpp                       Copyright (C) 1990-2016 Codemist    

//
// Arithmetic functions.
//    remainder, =,
//    minusp, plusp
//
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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



LispObject rembi(LispObject a, LispObject b)
{   LispObject nil;
    if (b == fixnum_of_int(0)) return aerror2("bad arg for remainder", a, b);
    else if (b == fixnum_of_int(1) ||
             b == fixnum_of_int(-1)) return fixnum_of_int(0);
    quotbn1(a, int_of_fixnum(b));
//
// If the divisor was a fixnum then the remainder will be a fixnum too.
//
    errexit();
    return fixnum_of_int(nwork);
}

LispObject rembb(LispObject a, LispObject b)
{   LispObject nil;
    quotbb(a, b);
    errexit();
    return mv_2;
}

static LispObject remis(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remir(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remif(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remsi(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remsb(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remsr(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remsf(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject rembs(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject rembr(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject rembf(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remri(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remrs(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remrb(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remrr(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remrf(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remfi(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remfs(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remfb(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remfr(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

static LispObject remff(LispObject a, LispObject b)
{   return aerror2("bad arg for remainder", a, b);
}

LispObject Cremainder(LispObject a, LispObject b)
{   int32_t c;
    switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum % fixnum arithmetic happens - the case I most want to
// make efficient.
//
                    if (b == fixnum_of_int(0))
                        return aerror2("bad arg for remainder", a, b);
                    // No overflow is possible in a remaindering operation
                    {   int32_t aa = int_of_fixnum(a);
                        int32_t bb = int_of_fixnum(b);
                        c = aa % bb;
//
// C does not specify just what happens when % is used with negative
// operands (except maybe if the division went exactly), so here I do
// some adjusting, assuming that the quotient returned was one of the
// integral values surrounding the exact result.
//
                        if (aa < 0)
                        {   if (c > 0) c -= bb;
                        }
                        else if (c < 0) c += bb;
                        return fixnum_of_int(c);
                    }
//
// Common Lisp defines a meaning for the remainder function when applied
// to floating point values - so there is a whole pile of mess here to
// support that.  Standard Lisp is only concerned with fixnums and
// bignums, but can tolerate the extra generality.
//
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return remis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
//
// When I divide a fixnum a by a bignum b the remainder is a except in
// the case that a = 0xf8000000 and b = 0x08000000 in which case the
// answer is zero.
//
                            if (int_of_fixnum(a) == fix_mask &&
                                bignum_length(b) == CELL+4 &&
                                bignum_digits(b)[0] == 0x08000000)
                                return fixnum_of_int(0);
                            else return a;
                        case TYPE_RATNUM:
                            return remir(a, b);
                        default:
                            return aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return remif(a, b);
//
//  case TAG_BOXFLOAT:
//      {   double v = (double) int_of_fixnum(a);
//          double u = float_of_number(b);
//          v = v - (v/u)*u;
//          return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
//      }
//
                default:
                    return aerror1("Bad arg for remainder",  b);
            }
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return remsi(a, b);
                case TAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - TAG_SFLOAT;
                    bb.i = b - TAG_SFLOAT;
                    aa.f = (float) (aa.f + bb.f);
                    return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return remsb(a, b);
                        case TYPE_RATNUM:
                            return remsr(a, b);
                        default:
                            return aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return remsf(a, b);
                default:
                    return aerror1("Bad arg for remainder",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return rembi(a, b);
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return rembs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return rembb(a, b);
                                case TYPE_RATNUM:
                                    return rembr(a, b);
                                default:
                                    return aerror1("Bad arg for remainder",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return rembf(a, b);
                        default:
                            return aerror1("Bad arg for remainder",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return remri(a, b);
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return remrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return remrb(a, b);
                                case TYPE_RATNUM:
                                    return remrr(a, b);
                                default:
                                    return aerror1("Bad arg for remainder",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return remrf(a, b);
                        default:
                            return aerror1("Bad arg for remainder",  b);
                    }
                default:    return aerror1("Bad arg for remainder",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {
//
//  case TAG_FIXNUM:
//          {   double u = (double) int_of_fixnum(b);
//              double v = float_of_number(a);
//              v = v - (v/u)*u;
//              return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
//          }
//  case TAG_BOXFLOAT:
//          {   double u = float_of_number(b);
//              double v = float_of_number(a);
//              v = v - (v/u)*u;
//              return make_boxfloat(v, TYPE_DOUBLE_FLOAT);
//          }
//
                case TAG_FIXNUM:
                    return remfi(a, b);
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return remfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return remfb(a, b);
                        case TYPE_RATNUM:
                            return remfr(a, b);
                        default:
                            return aerror1("Bad arg for remainder",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return remff(a, b);
                default:
                    return aerror1("Bad arg for remainder",  b);
            }
        default:
            return aerror1("Bad arg for remainder",  a);
    }
}

//
// In the cases that I expect to be most speed-critical I will
// implement "mod" directly. But in a load of other cases I will just
// activate the existing "remainder" code and then make a few final
// adjustments.  This MAY lead to error messages (on modulus by zero)
// mentioning remainder rather than mod....
// I will leave in the whole structure of separate functions for each
// case since that will be useful if I ever need to come back here and
// fine-tune more of the type-combinations. As a first pass I give
// special treatment to (fixnum,fixnum) and (bignum,fixnum)
//

static LispObject mod_by_rem(LispObject a, LispObject b)
{   LispObject nil;
    bool sb = minusp(b);
    errexit();
    a = Cremainder(a, b);   // Repeats dispatch on argument type. Sorry
    errexit();
    if (sb)
    {   if (plusp(a))
        {   errexit();
            a = plus2(a, b);
        }
    }
    else if (minusp(a))
    {   errexit();
        a = plus2(a, b);
    }
    return a;
}

static LispObject modib(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbi(LispObject a, LispObject b)
{   LispObject nil = C_nil;
    int32_t bb = int_of_fixnum(b);
    if (b == fixnum_of_int(0)) return aerror2("bad arg for mod", a, b);
    if (bb == 1 || bb == -1) nwork = 0;
    else quotbn1(a, bb);
//
// If the divisor was a fixnum then the remainder will be a fixnum too.
//
    errexit();
    if (bb < 0)
    {   if (nwork > 0) nwork += bb;
    }
    else if (nwork < 0) nwork += bb;
    return fixnum_of_int(nwork);
}

static LispObject modbb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modis(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modir(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modif(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsi(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modsf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modbf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modri(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modrf(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfi(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfs(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfb(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject modfr(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

static LispObject ccl_modff(LispObject a, LispObject b)
{   return mod_by_rem(a, b);
}

LispObject modulus(LispObject a, LispObject b)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
//
// This is where fixnum % fixnum arithmetic happens - the case I most want to
// make efficient.
//
                {   int32_t p = int_of_fixnum(a);
                    int32_t q = int_of_fixnum(b);
                    if (q == 0) return aerror2("bad arg for mod", a, b);
                    p = p % q;
                    if (q < 0)
                    {   if (p > 0) p += q;
                    }
                    else if (p < 0) p += q;
                    // No overflow is possible in a modulus operation
                    return fixnum_of_int(p);
                }
//
// Common Lisp defines a meaning for the modulus function when applied
// to floating point values - so there is a whole pile of mess here to
// support that.  Standard Lisp is only concerned with fixnums and
// bignums.
//
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return modis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modib(a, b);
                        case TYPE_RATNUM:
                            return modir(a, b);
                        default:
                            return aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return modif(a, b);
                default:
                    return aerror1("Bad arg for mod",  b);
            }
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return modsi(a, b);
                case TAG_SFLOAT:
                {   Float_union aa, bb;
                    aa.i = a - TAG_SFLOAT;
                    bb.i = b - TAG_SFLOAT;
                    aa.f = (float) (aa.f + bb.f);
                    return (aa.i & ~(int32_t)0xf) + TAG_SFLOAT;
                }
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modsb(a, b);
                        case TYPE_RATNUM:
                            return modsr(a, b);
                        default:
                            return aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return modsf(a, b);
                default:
                    return aerror1("Bad arg for mod",  b);
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return modbi(a, b);
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return modbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return modbb(a, b);
                                case TYPE_RATNUM:
                                    return modbr(a, b);
                                default:
                                    return aerror1("Bad arg for mod",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return modbf(a, b);
                        default:
                            return aerror1("Bad arg for mod",  b);
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return modri(a, b);
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return modrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return modrb(a, b);
                                case TYPE_RATNUM:
                                    return modrr(a, b);
                                default:
                                    return aerror1("Bad arg for mod",  b);
                            }
                        }
                        case TAG_BOXFLOAT:
                            return modrf(a, b);
                        default:
                            return aerror1("Bad arg for mod",  b);
                    }
                default:    return aerror1("Bad arg for mod",  a);
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return modfi(a, b);
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return modfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return modfb(a, b);
                        case TYPE_RATNUM:
                            return modfr(a, b);
                        default:
                            return aerror1("Bad arg for mod",  b);
                    }
                }
                case TAG_BOXFLOAT:
                    return ccl_modff(a, b);
                default:
                    return aerror1("Bad arg for mod",  b);
            }
        default:
            return aerror1("Bad arg for mod",  a);
    }
}

bool zerop(LispObject a)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return (a == fixnum_of_int(0));
        case TAG_NUMBERS:
            // #C(r i) must satisfy zerop is r and i both do
            if (is_complex(a) && zerop(real_part(a)))
                return zerop(imag_part(a));
            else return false;
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
//
// The code here assumes that the the floating point number zero
// is represented by a zero bit-pattern... see onep() for a more
// cautious way of coding things.
//
            return ((a & 0x7ffffff8) == 0); // Strip sign bit as well as tags
#endif
        case TAG_BOXFLOAT:
            return (float_of_number(a) == 0.0);
        default:
            return false;
    }
}

bool onep(LispObject a)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return (a == fixnum_of_int(1));
        case TAG_NUMBERS:
            // #C(r i) must satisfy onep(r) and zerop(i)
            if (is_complex(a) && onep(real_part(a)))
                return zerop(imag_part(a));
            else return false;
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
        {   Float_union w;
            w.f = (float)1.0;
            return (a == (w.i & ~(int32_t)0xf) + TAG_SFLOAT);
        }
#endif
        case TAG_BOXFLOAT:
            return (float_of_number(a) == 1.0);
        default:
            return false;
    }
}

//
// sign testing
//

bool minusp(LispObject a)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return ((int32_t)a < 0);
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return (aa.f < 0.0);
        }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                {   int32_t l = (bignum_length(a)-CELL-4)/4;
                    return ((int32_t)bignum_digits(a)[l] < (int32_t)0);
                }
                case TYPE_RATNUM:
                    return minusp(numerator(a));
                default:
                    aerror1("Bad arg for minusp",  a);
                    return 0;
            }
        }
        case TAG_BOXFLOAT:
        {   double d = float_of_number(a);
            return (d < 0.0);
        }
        default:
            aerror1("Bad arg for minusp",  a);
            return 0;
    }
}


bool plusp(LispObject a)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            return (a > fixnum_of_int(0));
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
        {   Float_union aa;
            aa.i = a - TAG_SFLOAT;
            return (aa.f > 0.0);
        }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                {   int32_t l = (bignum_length(a)-CELL-4)/4;
// This is OK because a bignum can never have the value zero
                    return ((int32_t)bignum_digits(a)[l] >= (int32_t)0);
                }
                case TYPE_RATNUM:
                    return plusp(numerator(a));
                default:
                    aerror1("Bad arg for plusp",  a);
                    return 0;
            }
        }
        case TAG_BOXFLOAT:
        {   double d = float_of_number(a);
            return (d > 0.0);
        }
        default:
            aerror1("Bad arg for plusp",  a);
            return 0;
    }
}


//
// Numeric equality - note that comparisons involving non-numbers
// are errors here (unlike the position in eql, equal, equalp).  Also
// this must be coded so that it never provokes garbage collection.
//

static bool numeqis(LispObject a, LispObject b)
{
#ifndef SHORT_FLOAT
    return 0;
#else
    Float_union bb;
    bb.i = b - TAG_SFLOAT;
    return ((double)int_of_fixnum(a) == (double)bb.f);
#endif
}

static bool numeqic(LispObject a, LispObject b)
{   if (!zerop(imag_part(b))) return false;
    else return numeq2(a, real_part(b));
}

#define numeqif(a,b) ((double)int_of_fixnum(a) == float_of_number(b))

#define numeqsi(a, b) numeqis(b, a)

static bool numeqsb(LispObject a, LispObject b)
//
// This is coded to allow comparison of any floating type
// with a bignum
//
{   double d = float_of_number(a), d1;
    int x;
    int32_t w, len;
    uint32_t u;
    if (-1.0e8 < d && d < 1.0e8) return false; // fixnum range (approx)
    len = (bignum_length(b)-CELL-4)/4;
    if (len == 0)   // One word bignums can be treated specially
    {   int32_t v = bignum_digits(b)[0];
        return (d == (double)v);
    }
    d1 = frexp(d, &x);  // separate exponent from mantissa
    if (d1 == 1.0) d1 = 0.5, x++;  // For Zortech
// The exponent x must be positive here, hence the % operation is defined
    d1 = ldexp(d1, x % 31);
//
// At most 3 words in the bignum may contain nonzero data - I subtract
// the (double) value of those bits off and check that (a) the floating
// result left is zero and (b) there are no more bits left.
//
    x = x / 31;
    if (x != len) return false;
    w = bignum_digits(b)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(b)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(b)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return false;
    while (--len >= 0)
        if (bignum_digits(b)[len] != 0) return false;
    return true;
}

static bool numeqsr(LispObject a, LispObject b)
//
// Here I will rely somewhat on the use of IEEE floating point values
// (an in particular the weaker supposition that I have floating point
// with a binary radix).  Then for equality the denominator of b must
// be a power of 2, which I can test for and then account for.
//
{   LispObject nb = numerator(b), db = denominator(b);
    double d = float_of_number(a), d1;
    int x;
    int32_t dx, w, len;
    uint32_t u, bit;
//
// first I will check that db (which will be positive) is a power of 2,
// and set dx to indicate what power of two it is.
// Note that db != 0 and that one of the top two words of a bignum
// must be nonzero (for normalisation) so I end up with a nonzero
// value in the variable 'bit'
//
    if (is_fixnum(db))
    {   bit = int_of_fixnum(db);
        w = bit;
        if (w != (w & (-w))) return false;   // not a power of 2
        dx = 0;
    }
    else if (is_numbers(db) && is_bignum(db))
    {   int32_t lenb = (bignum_length(db)-CELL-4)/4;
        bit = bignum_digits(db)[lenb];
//
// I need to cope with bignums where the leading digits is zero because
// the 0x80000000 bit of the next word down is 1.  To do this I treat
// the number as having one fewer digits.
//
        if (bit == 0) bit = bignum_digits(db)[--lenb];
        w = bit;
        if (w != (w & (-w))) return false;   // not a power of 2
        dx = 31*lenb;
        while (--lenb >= 0)     // check that the rest of db is zero
            if (bignum_digits(db)[lenb] != 0) return false;
    }
    else return false; // Odd - what type IS db here?  Maybe error.
    if ((bit & 0xffffU) == 0) dx += 16, bit = bit >> 16;
    if ((bit & 0xff) == 0) dx += 8, bit = bit >> 8;
    if ((bit & 0xf) == 0) dx += 4, bit = bit >> 4;
    if ((bit & 0x3) == 0) dx += 2, bit = bit >> 2;
    if ((bit & 0x1) == 0) dx += 1;
    if (is_fixnum(nb))
    {   double d1 = (double)int_of_fixnum(nb);
//
// The ldexp on the next line could potentially underflow.  In that case C
// defines that the result 0.0 be returned.  To avoid trouble I put in a
// special test the relies on that fact that a value represented as a rational
// would not have been zero.
//
        if (dx > 10000) return false;  // Avoid gross underflow
        d1 = ldexp(d1, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    len = (bignum_length(nb)-CELL-4)/4;
    if (len == 0)   // One word bignums can be treated specially
    {   int32_t v = bignum_digits(nb)[0];
        double d1;
        if (dx > 10000) return false;  // Avoid gross underflow
        d1 = ldexp((double)v, (int)-dx);
        return (d == d1 && d != 0.0);
    }
    d1 = frexp(d, &x);    // separate exponent from mantissa
    if (d1 == 1.0) d1 = 0.5, x++; // For Zortech
    dx += x;              // adjust to allow for the denominator
    d1 = ldexp(d1, (int)(dx % 31));
    // can neither underflow nor overflow here
//
// At most 3 words in the bignum may contain nonzero data - I subtract
// the (double) value of those bits off and check that (a) the floating
// result left is zero and (b) there are no more bits left.
//
    dx = dx / 31;
    if (dx != len) return false;
    w = bignum_digits(nb)[len];
    d1 = (d1 - (double)w) * TWO_31;
    u = bignum_digits(nb)[--len];
    d1 = (d1 - (double)u) * TWO_31;
    if (len > 0)
    {   u = bignum_digits(nb)[--len];
        d1 = d1 - (double)u;
    }
    if (d1 != 0.0) return false;
    while (--len >= 0)
        if (bignum_digits(nb)[len] != 0) return false;
    return true;
}

#define numeqsc(a, b) numeqic(a, b)

static bool numeqsf(LispObject a, LispObject b)
{
#ifndef SHORT_FLOAT
    return 0;
#else
    Float_union aa;
    aa.i = a - TAG_SFLOAT;
    return ((double)aa.f == float_of_number(b));
#endif
}

#define numeqbs(a, b) numeqsb(b, a)

static bool numeqbb(LispObject a, LispObject b)
{   int32_t la = bignum_length(a);
    if (la != (int32_t)bignum_length(b)) return false;
    la = (la-CELL-4)/4;
    while (la >= 0)
    {   if (bignum_digits(a)[la] != bignum_digits(b)[la]) return false;
        else la--;
    }
    return true;
}

#define numeqbc(a, b) numeqic(a, b)

#define numeqbf(a, b) numeqsb(b, a)

#define numeqrs(a, b) numeqsr(b, a)

static bool numeqrr(LispObject a, LispObject b)
{   return numeq2(numerator(a), numerator(b)) &&
           numeq2(denominator(a), denominator(b));
}

#define numeqrc(a, b) numeqic(a, b)

#define numeqrf(a, b) numeqsr(b, a)

#define numeqci(a, b) numeqic(b, a)

#define numeqcs(a, b) numeqic(b, a)

#define numeqcb(a, b) numeqic(b, a)

#define numeqcr(a, b) numeqic(b, a)

static bool numeqcc(LispObject a, LispObject b)
{   return numeq2(real_part(a), real_part(b)) &&
           numeq2(imag_part(a), imag_part(b));
}

#define numeqcf(a, b) numeqic(b, a)

#define numeqfi(a, b) numeqif(b, a)

#define numeqfs(a, b) numeqsf(b, a)

#define numeqfb(a, b) numeqbf(b, a)

#define numeqfr(a, b) numeqrf(b, a)

#define numeqfc(a, b) numeqic(a, b)

static bool numeqff(LispObject a, LispObject b)
{   return (float_of_number(a) == float_of_number(b));
}

//
// This comparison must signal an error on non-numeric operands in
// Common Lisp mode, but behave as EQ in CSL mode.
//

#ifdef COMMON
#  define differenta aerror1("Bad arg for =",  a); return false
#  define differentb aerror1("Bad arg for =",  b); return false
#else
#  define differenta return false
#  define differentb return false
#endif

bool numeq2(LispObject a, LispObject b)
{   switch ((int)a & TAG_BITS)
    {   case TAG_FIXNUM:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return (a == b);
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return numeqis(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return 0; // fixnum can not be equal to a bignum
                        case TYPE_RATNUM:
                            return 0;
                        case TYPE_COMPLEX_NUM:
                            return numeqic(a, b);   // (= 2 #C(2.0 0.0))?  Yuk
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                    return numeqif(a, b);
                default:
                    differentb;
            }
#ifdef SHORT_FLOAT
        case TAG_SFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return numeqsi(a, b);
                case TAG_SFLOAT:
//
// I take a decision here that short floats will not honour the idea
// of NaNs in this comparison.
//
                    return (a == b) ||
                           (a == TAG_SFLOAT &&
                            b == (LispObject)(TAG_SFLOAT|0x80000000)) ||
                           (a == (LispObject)(TAG_SFLOAT|0x80000000) &&
                            b == TAG_SFLOAT); // !!!
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return numeqsb(a, b);
                        case TYPE_RATNUM:
                            return numeqsr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return numeqsc(a, b);
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                    return numeqsf(a, b);
                default:
                    differentb;
            }
#endif
        case TAG_NUMBERS:
        {   int32_t ha = type_of_header(numhdr(a));
            switch (ha)
            {   case TYPE_BIGNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return 0;
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return numeqbs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return numeqbb(a, b);
                                case TYPE_RATNUM:
                                    return 0;
                                case TYPE_COMPLEX_NUM:
                                    return numeqbc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                            return numeqbf(a, b);
                        default:
                            differentb;
                    }
                case TYPE_RATNUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return 0;
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return numeqrs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return 0;
                                case TYPE_RATNUM:
                                    return numeqrr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return numeqrc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                            return numeqrf(a, b);
                        default:
                            differentb;
                    }
                case TYPE_COMPLEX_NUM:
                    switch ((int)b & TAG_BITS)
                    {   case TAG_FIXNUM:
                            return numeqci(a, b);
#ifdef SHORT_FLOAT
                        case TAG_SFLOAT:
                            return numeqcs(a, b);
#endif
                        case TAG_NUMBERS:
                        {   int32_t hb = type_of_header(numhdr(b));
                            switch (hb)
                            {   case TYPE_BIGNUM:
                                    return numeqcb(a, b);
                                case TYPE_RATNUM:
                                    return numeqcr(a, b);
                                case TYPE_COMPLEX_NUM:
                                    return numeqcc(a, b);
                                default:
                                    differentb;
                            }
                        }
                        case TAG_BOXFLOAT:
                            return numeqcf(a, b);
                        default:
                            differentb;
                    }
                default:    differenta;
            }
        }
        case TAG_BOXFLOAT:
            switch ((int)b & TAG_BITS)
            {   case TAG_FIXNUM:
                    return numeqfi(a, b);
#ifdef SHORT_FLOAT
                case TAG_SFLOAT:
                    return numeqfs(a, b);
#endif
                case TAG_NUMBERS:
                {   int32_t hb = type_of_header(numhdr(b));
                    switch (hb)
                    {   case TYPE_BIGNUM:
                            return numeqfb(a, b);
                        case TYPE_RATNUM:
                            return numeqfr(a, b);
                        case TYPE_COMPLEX_NUM:
                            return numeqfc(a, b);
                        default:
                            differentb;
                    }
                }
                case TAG_BOXFLOAT:
                    return numeqff(a, b);
                default:
                    differentb;
            }
        default:
            differenta;
    }
}

// end of arith11.cpp
