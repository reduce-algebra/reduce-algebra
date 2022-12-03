// arith.h                                Copyright (C) Codemist, 1990-2022


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

#ifndef header_arith_h
#define header_arith_h 1

#define TWO_32    4294967296.0      // 2^32
#define TWO_31    2147483648.0      // 2^31
#define TWO_24    16777216.0        // 2^24
#define TWO_22    4194304.0         // 2^22
#define TWO_21    2097152.0         // 2^21
#define TWO_20    1048576.0         // 2^20

//
// I am going to need to rely on my C compiler turning these strings
// into well-rounded versions of the relevant numbers. To increase the
// changes of that I will write the constants as
//    ((A + B)/C)
// where A will be an integer and hence representable exactly, B will be
// be much smaller and C will be a power of two, so dividing by it should
// not introduce any additional error at all.
//
// #define _pi       3.14159265358979323846
// #define _half_pi  1.57079632679489661923

#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)

#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15

extern unsigned char msd_table[256], lsd_table[256];

//
// Bignums are represented as vectors of digits, where each digit
// uses 31 bits, and all but the most significant digit are unsigned
// (and thus do not use the 0x80000000L bit).  The most significant
// digit of a bignum is a signed 2-s complement value in 31 bits that
// has been sign extended into the 0x80000000L bit, and thus its top
// two bits (in the 32 bit word) will be either '00' or '11'.
// NOTE that even on a 64-bit machine I will work with 32-bit values
// as digits in bignums.
//

// NOTE please that these are all using 32-bit arthmetic. They are only
// intended for use on values that are digits making up parts of bignums.
// Note that some C++ compilers try to be VERY clever about assuming that
// integer arithmetic will never overflow, so I need to do things in
// unsigned mode if the top bit is liable to arise as a carry-bit.

#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n)     ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n)   ((int32_t)((uint32_t)(n) & 0x7fffffff))

// As with fixnum_of_int I need to take care here that the arithmetic I do
// here can not overflow, since if it did the behaviour would be undefined
// and a modern optimising compiler would be entitled to do pretty much
// whatever it felt like. I hope that good compilers will observe that the
// mask operation as written here is not really needed on most machines.

#define signed_overflow(n) \
  top_bit_set(static_cast<uint32_t>(n) ^ (static_cast<uint32_t>(n) << 1))

// ADD32 forces and addition to be done as unsigned arithmetic, and may be
// useful when this avoids risk of a carry into the most significant bit
// being interpreted as overflow and hence undefined behaviour.

#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))


// The following all take an intptr_t or int64_t values (as per their name)
// and check if their argument would fit in a 29 or 31-bit signed value. I
// try fairly hard to avoid overflow and keep the code here so that the
// only way in which it goes beyond what the C/C++ standards guarantee is
// an assumption that numbers are 2s complement and that casts between
// signed and unsigned values leave the bitwise representations unchanged.

#if 0
#define signed29_in_64(n)                                                   \
  ((static_cast<int64_t>(                                                   \
      (static_cast<uint64_t>(n) & 0x1fffffffU) << 35) / (1LLU << 35)) ==    \
   static_cast<int64_t>(n))
#endif

inline bool signed29_in_64(int64_t n)
{   return (n >= -(1<<28)) && (n <= (1<<28)-1);
}

#if 0
#define signed31_in_64(n)                                                   \
  ((static_cast<int64_t>(                                                   \
      (static_cast<uint64_t>(n) & 0x7fffffffU) << 33) / (1ULL << 33)) ==    \
   static_cast<int64_t>(n))
#endif

inline bool signed31_in_64(int64_t n)
{   return (n >= -(1<<30)) && (n <= (1<<30)-1);
}

#if 0
#define signed31_in_ptr(n)                                                    \
  ((static_cast<intptr_t>(                                                    \
      (static_cast<uintptr_t>(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
      (1LL << (8*sizeof(intptr_t) - 31))) ==                                  \
   static_cast<intptr_t>(n))
#endif

inline bool signed31_in_ptr(intptr_t n)
{   return (n >= -(1<<30)) && (n <= (1<<30)-1);
}

#ifdef HAVE_SOFTFLOAT
// I use rounding-direction specifiers from SoftFloat because I can then
// pass them down to the float128_t functions when I need to
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND    softfloat_round_near_even
#define FIX_FLOOR    softfloat_round_min
#define FIX_CEILING  softfloat_round_max
#else
// If I do not have SoftFloat I will use values that in fact match those I
// would be using if I did!
#define FIX_TRUNCATE 1
#define FIX_ROUND    0
#define FIX_FLOOR    2
#define FIX_CEILING  3
#endif // HAVE_SOFTFLOAT

extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b,
                            int roundmode);


// The following tests for IEEE infinities and NaNs.

inline bool floating_edge_case(double r)
{   return !std::isfinite(r);
}

inline void floating_clear_flags()
{}

// An alternative possible implementation could go
//    #include <fenv.h>
//    {
//    #pragma STDC FENV_ACCESS ON
//        <arithmetic>
//        if (fetestexcept(FE_OVERFLOW | FE_INVALID | FE_DIVBYZERO))
//        {   feclearexcept(FE_ALL_EXCEPT);
//            ..
//        }
//    }
// The STDC_FENV_ACCESS pragma came in with C99 and C++11, but at the time
// of writing gcc and g++ do not support it on quite enought platforms.
// When and if they do I may move to exploit it. Meanwhile I will use the
// version that is probably more portable.

//
// Here I do some arithmetic in-line. In the following macros I need to
// take care that the names used for local variables do not clash with
// those used in the body of the code. Hence the names r64 and c64, which
// I must agree not to use elsewhere.  Note also the "do {} while (0)" idiom
// to avoid nasty problems with C syntax and the need for semicolons.
// I should make a transition to use of inline functions!

#define Dmultiply(hi, lo, a, b, c)                           \
 do { uint64_t r64 = static_cast<uint64_t>(a) *    \
                          static_cast<uint64_t>(b) +    \
                      static_cast<uint32_t>(c);         \
      (lo) = 0x7fffffffu & static_cast<uint32_t>(r64);  \
      (hi) = static_cast<uint32_t>(r64 >> 31); } while (0)

#define Ddivide(r, q, a, b, c)                                        \
 do { uint64_t r64 = (static_cast<uint64_t>(a) << 31) |     \
                          static_cast<uint64_t>(b);              \
      uint64_t c64 = static_cast<uint64_t>(                 \
                          static_cast<uint32_t>(c));             \
      q = static_cast<uint32_t>(r64 / c64);                      \
      r = static_cast<uint32_t>(r64 % c64); } while (0)

#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)

#define Ddivideq(q, a, b, c)                                  \
 do { uint64_t r64 = ((static_cast<uint64_t>(a)) << 31) | static_cast<uint64_t>(b); \
      uint64_t c64 = static_cast<uint64_t>(static_cast<uint32_t>(c));                 \
      q = static_cast<uint32_t>(r64 / c64); } while (0)

#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)

#define Ddivider(r, a, b, c)                                  \
 do { uint64_t r64 = ((static_cast<uint64_t>(a)) << 31) | static_cast<uint64_t>(b); \
      uint64_t c64 = static_cast<uint64_t>(static_cast<uint32_t>(c));                 \
      r = static_cast<uint32_t>(r64 % c64); } while (0)

#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)

#define fixnum_minusp(a) (static_cast<intptr_t>(a) < 0)

#define bignum_minusp(a) \
    (static_cast<int32_t>(bignum_digits(a)[((bignum_length(a)-CELL)/4)-1])<0)

inline double value_of_immediate_float(LispObject a)
{   Float_union aa;
    if (SIXTY_FOUR_BIT)
        aa.i = static_cast<int32_t>(static_cast<uint64_t>(a)>>32);
    else aa.i = static_cast<int32_t>(a - XTAG_SFLOAT);
    std::memmove(&aa.f, &aa.i, sizeof(aa.f)); // defeat strict aliasing!
    return aa.f;
}

extern LispObject make_boxfloat(double a, FloatType type=WANT_DOUBLE_FLOAT);
#ifdef HAVE_SOFTFLOAT
extern LispObject make_boxfloat128(float128_t a);
#endif // HAVE_SOFTFLOAT

inline FloatType floatWant(Header h)
{   switch (h)
    {
    case SINGLE_FLOAT_HEADER:
        return WANT_SINGLE_FLOAT;
    case DOUBLE_FLOAT_HEADER:
        return WANT_DOUBLE_FLOAT;
    case LONG_FLOAT_HEADER:
        return WANT_LONG_FLOAT;
    default:
        my_abort("bad header for boxed floating point number");
    }
}

// Pack something as a short (28-bit) float

inline LispObject pack_short_float(double d)
{   Float_union aa;
    aa.f = d;
    if (trap_floating_overflow &&
        floating_edge_case(aa.f))
    {   floating_clear_flags();
        return aerror("exception with short float");
    }
    std::memmove(&aa.i, &aa.f, sizeof(aa.f)); // defeat strict aliasing!
    if ((aa.i & 0x1f) != 0x08) aa.i += 8;
    aa.i &= ~0xf;
    if (SIXTY_FOUR_BIT)
        return static_cast<LispObject>(
            (static_cast<uint64_t>(aa.i)) << 32) + XTAG_SFLOAT;
    else return aa.i + XTAG_SFLOAT;
}

// Create a single (32-bit) float. Just like make_single_float but inlined
// in the 64-bit case

inline LispObject pack_single_float(double d)
{   if (SIXTY_FOUR_BIT)
    {   Float_union aa;
        aa.f = d;
        if (trap_floating_overflow &&
            floating_edge_case(aa.f))
        {   floating_clear_flags();
            return aerror("exception with single float");
        }
        std::memmove(&aa.i, &aa.f, sizeof(aa.f)); // defeat strict aliasing!
        return static_cast<LispObject>(
            static_cast<uint64_t>(aa.i) << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
    }
    else
    {   LispObject r = get_basic_vector(TAG_BOXFLOAT,
                                        TYPE_SINGLE_FLOAT,
                                        sizeof(Single_Float));
        single_float_val(r) = static_cast<float>(d);
        if (trap_floating_overflow &&
            floating_edge_case(single_float_val(r)))
        {   floating_clear_flags();
            return aerror("exception with single float");
        }
        return r;
    }
}

// Pack either a 28 or 32-bit float with type Lisp value "l1" indicating
// whether 28 or 32 bits are relevant. On a 32-bit machine l1 will always
// be a 28-bit value. If a second argument l2 is provided the width of the
// result will match the wider of the two.

inline LispObject pack_immediate_float(double d, LispObject l1,
                                                 LispObject l2=0)
{   Float_union aa;
    aa.f = d;
// The next line is intended to make this safe with regard to strict aliasing!
    std::memmove(&aa.i, &aa.f, sizeof(aa.f));
    if (trap_floating_overflow &&
        floating_edge_case(aa.f))
    {   floating_clear_flags();
        if (((l1 | l2) & XTAG_FLOAT32) != 0)
            return aerror("exception with single float");
        else return aerror("exception with short float");
    }
// Note the amazing fact that in IEEE floating point formats adding
// a small integer value to the representation of a float increments that
// float in "units in the last place". The amazing thing is that the
// still applies if the value added causes carries that lead to a change
// in the exponent field. So when I add 8 and then mask by ~0xf I achieve
// rounding. If I was even more fussy I would go
//       if ((aa.i & 0x1f) != 0x08) aa.i += 8;
//       aa.i &= ~0xf;
// which rounds up on the half-way case only of without rounding the result
// would be odd. Hah that is streaightforward enough that I will do it!
    if (SIXTY_FOUR_BIT)
    {   if (((l1 | l2) & XTAG_FLOAT32) == 0)
        {   if ((aa.i & 0x1f) != 0x08)  aa.i += 8;
            aa.i &= ~0xf;
        }
        return static_cast<LispObject>(
            (static_cast<uint64_t>(aa.i) << 32) +
            XTAG_SFLOAT + ((l1 | l2) & XTAG_FLOAT32));
    }
    if ((aa.i & 0x1f) != 0x08)  aa.i += 8;
    aa.i &= ~0xf;
    return aa.i + XTAG_SFLOAT;
}

// double floats 

inline LispObject make_boxfloat(double a, FloatType type)
// Make a boxed float (single, double according to the type specifier)
// if type==0 this makes a short float.
// 128-bit floats must be made using make_boxfloat128.
{   LispObject r;
    switch (type)
    {   case WANT_SHORT_FLOAT:
            return pack_short_float(a);
        case WANT_SINGLE_FLOAT:
            return pack_single_float(a);
        case WANT_DOUBLE_FLOAT:
#ifdef CONSERVATIVE
// double precision floats always consume 16 bytes in all. On a 64
// bit machines that is an 8 byte header than the 8 bytes of the double
// itself. With 32-bits the header only uses 4 bytes, but then there has
// to be a 4 byte padder so that the double is properly aligned. With
// 64-bit words the size matches that of cons cells, and so I can allocate
// in cons-space which is a cheaper operation than allocating in vector
// space.
            if (SIXTY_FOUR_BIT) r = get2Words();
            else r = getNBytes(16);
            indirect(r) = DOUBLE_FLOAT_HEADER;
            r += TAG_BOXFLOAT;
#else // CONSERVATIVE
            r = get_basic_vector(TAG_BOXFLOAT,TYPE_FLOAT,SIZEOF_DOUBLE_FLOAT);
#endif // CONSERVATIVE
            errexit();
            if (!SIXTY_FOUR_BIT) double_float_pad(r) = 0;
            double_float_val(r) = a;
// I hope that trap_floating_overflow will almost always be false and
// so the extra mess here will hardly add any overhead.
            if (trap_floating_overflow &&
                floating_edge_case(double_float_val(r)))
            {   floating_clear_flags();
                return aerror("exception with double float");
            }
            return r;
        default:
            my_abort("coding error in support of long floats");
    }
}

// comparing 64-bit integers against (double precision) is perhaps
// unexpectedly delicate. Here is some code to help. You can find two
// sources of extra commentary about this. One is by Andrew Koenig in
// a Dr Dobbs article in 2013, the other is in (MIT Licensed) Julia and
// a discussion at https://github.com/JuliaLang/julia/issues/257.

inline bool eq_i64d(int64_t a, double b)
{
// The integer can always be converted to a double, but of course
// sometimes there will be rounding involved. But if the value does not
// match the double even after rounding then the two values are certainly
// different. Also if the double happens to be a NaN this will lead to
// a returned value of false (as required).
    if (b != static_cast<double>(a)) return false;
// Now the two values differ by at most the rounding that happened when
// the integer was converted to a double. This ALMOST means that the double
// has a value that fits in the range of integers. However if a has a value
// just less than 2^63 and b is (double)(2^63) then b can not be cast to
// an integer safely. In C++ the consequence of trying to cast a double to
// and int where the result would not fit is undefined, and so could
// include arbitrary bad behaviour. So I have to filter that case out.
    if (b == static_cast<double>(1ULL<<63)) return false;
// With the special case out of the way I can afford to case from double to
// int64_t. The negative end of the range is safe!
    return a == static_cast<int64_t>(b);
}

inline bool lessp_i64d(int64_t a, double b)
{
// If the integer is <= 2^53 then converting it to a double does not
// introduce any error at all, so I can perform the comparison reliably
// on doubles. If d ia a NaN this is still OK.
    if (a <= (1LL<<53) &&
        a >= -(1LL<<53))
        return static_cast<double>(a) < b;
// If the float is outside the range of int64_t I can tell how the
// comparison must play out. Note that near the value 2^63 the next
// double value lower than 2^63 is in integer, as we can not have any
// floating point value larger than the largest positive int64_t value
// and less then 2^63. I make these tests of the form "if (!xxx)" because
// then if b is a NaN the comparison returns false and I end up exiting.
    if (!(b >= -static_cast<double>(1ULL<<63)))
        return false;
    if (!(b < static_cast<double>(1ULL<<63)))
        return true;
// Now we know that a is large and b is not huge. I will just discuss the
// case of two positive numbers here, but mixed signs and negative values
// follow the same.
// I am going to convert b to an integer and then compare. Because I have
// ensures that b is not too big (including knowing it is not an infinity
// or a NaN) I will not get overflow or failure in that conversion. So the
// only concern is the effect of rounding in the conversion.
// Well if b >= 2^52 it has an exact integer as its value so the conversion
// will be exact and the comparison reliable.
// if b < 2^52 but a > 2^53 then rounding of b that leaves a fractional part
// less than 1 does not matter and again the comparison is reliable.
    return a < static_cast<int64_t>(b);
}

inline bool lessp_di64(double a, int64_t b)
{
// The logic here is much as above - by omitting all the commentary
// you can see much more clearly just how long the code is.
    if (b <= (1LL<<53) &&
        b >= -(1LL<<53)) return a < static_cast<double>(b);
    if (!(a < static_cast<double>(1ULL<<63)))
        return false;
    if (!(a >= -static_cast<double>(1ULL<<63)))
        return true;
    return static_cast<int64_t>(a) < b;
}

extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED    1
#define QUOTBB_REMAINDER_NEEDED   2
extern LispObject quotbb(LispObject a, LispObject b, int needs);
extern LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, size_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern bool numeq2(LispObject a, LispObject b);
extern bool SL_numeq2(LispObject a, LispObject b);
extern bool zerop(LispObject a);
extern bool onep(LispObject a);
extern bool minusp(LispObject a);
extern bool plusp(LispObject a);

extern LispObject integer_decode_long_float(LispObject a);
extern LispObject Linteger_decode_float(LispObject env, LispObject a);

extern LispObject validate_number(const char *s, LispObject a,
                                  LispObject b, LispObject c);

extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b,
        uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
                                        uint32_t c, uint32_t d);
extern LispObject make_five_word_bignum(int32_t a, uint32_t b,
                                        uint32_t c, uint32_t d, uint32_t e);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
                                     uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
                                      uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
                                      uint32_t a2, uint32_t a1,
                                      uint32_t a0, size_t n);

extern LispObject make_power_of_two(size_t n);

// For each of the next few I have an inline version that works for
// small enough arguments then a version whose name has the suffix "_fn"
// that gets called in the larger case.

extern LispObject make_lisp_integer32_fn(int32_t n);
inline LispObject make_lisp_integer32(int32_t n)
{   if (SIXTY_FOUR_BIT ||
        valid_as_fixnum(n)) return fixnum_of_int(static_cast<intptr_t>(n));
    else return make_lisp_integer32_fn(n);
}

extern LispObject make_lisp_integer64_fn(int64_t n);
inline LispObject make_lisp_integer64(int64_t n)
{   if (valid_as_fixnum(n)) return fixnum_of_int(static_cast<intptr_t>(n));
    else return make_lisp_integer64_fn(n);
}

extern LispObject make_lisp_unsigned64_fn(uint64_t n);
inline LispObject make_lisp_unsigned64(uint64_t n)
{   if (n < (1ULL<<(8*sizeof(intptr_t)-5)))
        return fixnum_of_int(static_cast<intptr_t>(n));
    else return make_lisp_unsigned64_fn(n);
}

// There is a little C++ joke here.
// If I try to provide overloads for arguments that are int32_t, int64_t and
// also intptr_t then on some platforms intptr_t is viewed as identical to
// one of the others and I get a complaint about multiple definition. While
// on others it is a distinct type and is OK. If I then try omitting the
// overload from it and call the function with an intptr_t I may get moans
// about ambiguity. So I use a different name (ending in "ptr") here. Ugh.
// I may need to understand the C++ specification in greater depth, but
// while I get confused others could too... so safety is good.

inline LispObject make_lisp_integerptr(intptr_t n)
{   if (valid_as_fixnum(static_cast<int64_t>(n))) return fixnum_of_int(n);
    else return make_lisp_integer64_fn(static_cast<intptr_t>(n));
}

inline LispObject make_lisp_unsignedptr(uintptr_t n)
{   if (n < (1LL<<(8*sizeof(intptr_t)-5)))
        return fixnum_of_int(static_cast<int64_t>(n));
    else return make_lisp_unsigned64_fn(n);
}

extern LispObject make_lisp_integer128_fn(int128_t n);

inline LispObject make_lisp_integer128(int128_t n)
{   if (valid_as_fixnum(n)) return fixnum_of_int(static_cast<int64_t>(n));
    else return make_lisp_integer128_fn(n);
}

extern LispObject make_lisp_unsigned128_fn(uint128_t n);

inline LispObject make_lisp_unsigned128(uint128_t n)
{   if (uint128_valid_as_fixnum(n))
        return fixnum_of_int(static_cast<uint64_t>(static_cast<uint64_t>(n)));
    else return make_lisp_unsigned128_fn(n);
}

inline void validate_number(LispObject n)
{
// Can be used while debugging!
}

extern double float_of_integer(LispObject a);
extern LispObject add1(LispObject p);
extern LispObject sub1(LispObject p);
extern LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
#ifdef HAVE_SOFTFLOAT
extern float128_t float128_of_number(LispObject a);
#endif // HAVE_SOFTFLOAT
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q,
                                    int bits);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
#ifdef HAVE_SOFTFLOAT
extern LispObject rationalf128(float128_t *d);
#endif // HAVE_SOFTFLOAT

extern int _reduced_exp(double, double *);
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);

//
// This is going to be a bit of a mess because I will want to use the C
// data-type "complex double" when that is available... what happens
// here will survive even without that.
//

typedef struct Complex
{   double real;
    double imag;
} Complex;

extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);

// For the parallel variant on Karatsuba I need thread support...

#ifndef HAVE_CILK

extern std::thread kara_thread[2];
#define KARA_0    (1<<0)
#define KARA_1    (1<<1)
#define KARA_QUIT (1<<2)
extern void kara_worker(int id);
extern std::mutex kara_mutex;
extern std::condition_variable cv_kara_ready,
       cv_kara_done;
extern unsigned int kara_ready;
extern int kara_done;

#endif

extern size_t kparallel, karatsuba_parallel;

//
// Tests on my Intel i7 4770K system running Windows 7 (64-bit) I find that
// on numbers over 10^1000 (or so) the use of a multi-threaded Karatsuba
// starts to pay off. By 2000 decimal digits it is quite useful.
// The threshold set here of 120 31-bit words represents about the
// break-even point.
//
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif

#ifndef KARATSUBA_CUTOFF
//
// I have conducted some experiments on one machine to find out what the
// best cut-off value here is.  The exact value chosen is not very
// critical, and the fancy techniques do not pay off until numbers get
// a lot bigger than this length (which is expressed in units of 31-bit
// words, i.e. about 10 decimals).  Anyone who wants may recompile with
// alternative values to try to get the system fine-tuned for their
// own computer - but I do not expect it to be possible to achieve much
// by so doing.
//
#ifdef ARITHLIB
#define KARATSUBA_CUTOFF 1000000  // Buggy at present!
#else // ARITHLIB
#define KARATSUBA_CUTOFF 12
#endif // ARITHLIB

#endif // KARATSUBA_CUTOFF

extern int double_to_binary(double d, int64_t &m);
extern intptr_t double_to_3_digits(double d,
                                   int32_t &a2, uint32_t &a1, uint32_t &a0);


// Now let me provide a macro to do full type-dispatch for the implementation
// of a generic arithmetic operator. This is a pretty hideously large macro
// and it does a full dispatch in every single case, but still writing it
// just once is probably a good idea. Well if HAVE_SOFTFLOAT is not defined
// I will want the "long float" cases to be supressed!

// This checks for
//   i    fixnum
//   b    bignum
//   r    ratio
//   c    complex
//   s    short float
//   f    single float
//   d    double float
//   l    long float
//


#ifdef HAVE_SOFTFLOAT

// arith_dispatch_1 switches into one of 8 sub-functions whose names are
// got be suffixing the top-level name with one of the above letters.
// arith_dispatch_2 ends up with 64 sub-functions to call.

// First for 1-arg functions

#define arith_dispatch_1(stgclass, type, name)                      \
stgclass type name(LispObject a1)                                   \
{   if (is_fixnum(a1)) return name##_i(a1);                         \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a1)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1);                                    \
        case TYPE_RATNUM:                                           \
            return name##_r(a1);                                    \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1);                                    \
        default:                                                    \
            return static_cast<type>(                               \
                aerror1("bad arg for " #name, a1));                 \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a1))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1);                                    \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1);                                    \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1);                                    \
        default:                                                    \
            return static_cast<type>(                               \
                aerror1("bad arg for " #name, a1));                 \
        }                                                           \
    default:                                                        \
        return static_cast<type>(                                   \
            aerror1("bad arg for " #name, a1));                     \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)            \
            return name##_f(a1);                                    \
        else return name##_s(a1);                                   \
    }                                                               \
}

// Now a helper macro for 2-arg functions

#define arith_dispatch_1a(stgclass, type, name, rawname)            \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a2)) return name##_i(a1, a2);                     \
    switch (a2 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a2)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1, a2);                                \
        case TYPE_RATNUM:                                           \
            return name##_r(a1, a2);                                \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #rawname, a1, a2));          \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a2))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1, a2);                                \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1, a2);                                \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #rawname, a1, a2));          \
        }                                                           \
    default:                                                        \
        return static_cast<type>(                                   \
            aerror2("bad arg for " #rawname, a1, a2));              \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0))           \
            return name##_f(a1, a2);                                \
        else return name##_s(a1, a2);                               \
    }                                                               \
}

#define arith_dispatch_2(stgclass, type, name)                      \
arith_dispatch_1a(inline, type, name##_i, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_b, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_r, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_c, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_s, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_f, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_d, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_l, name)                     \
                                                                    \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a1)) return name##_i(a1, a2);                     \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a1)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1, a2);                                \
        case TYPE_RATNUM:                                           \
            return name##_r(a1, a2);                                \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #name, a1, a2));             \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a1))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1, a2);                                \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1, a2);                                \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #name, a1, a2));             \
        }                                                           \
    default:                                                        \
        return static_cast<type>(                                   \
            aerror2("bad arg for " #name, a1, a2));                 \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))           \
            return name##_f(a1, a2);                                \
        else return name##_s(a1, a2);                               \
    }                                                               \
}

#else // HAVE_SOFTFLOAT

// arith_dispatch_1 switches into one of 7 sub-functions whose names are
// got be suffixing the top-level name with one of the above letters.
// arith_dispatch_2 ends up with 49 sub-functions to call.

// First for 1-arg functions

#define arith_dispatch_1(stgclass, type, name)                      \
stgclass type name(LispObject a1)                                   \
{   if (is_fixnum(a1)) return name##_i(a1);                         \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a1)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1);                                    \
        case TYPE_RATNUM:                                           \
            return name##_r(a1);                                    \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1);                                    \
        default:                                                    \
            return static_cast<type>(                               \
                aerror1("bad arg for " #name, a1));                 \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a1))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1);                                    \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1);                                    \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1);                                    \
        default:                                                    \
            return static_cast<type>(                               \
                aerror1("bad arg for " #name, a1));                 \
        }                                                           \
    default:                                                        \
        return static_cast<type>(                                   \
            aerror1("bad arg for " #name, a1));                     \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))           \
            return name##_f(a1);                                    \
        else return name##_s(a1);                                   \
    }                                                               \
}

// Now a helper macro for 2-arg functions

#define arith_dispatch_1a(stgclass, type, name, rawname)            \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a2)) return name##_i(a1, a2);                     \
    switch (a2 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a2)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1, a2);                                \
        case TYPE_RATNUM:                                           \
            return name##_r(a1, a2);                                \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(aerror2("bad arg for " #rawname, a1, a2)); \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a2))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1, a2);                                \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1, a2);                                \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(aerror2("bad arg for " #rawname, a1, a2)); \
        }                                                           \
    default:                                                        \
        return static_cast<type>(aerror2("bad arg for " #rawname, a1, a2)); \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0))           \
            return name##_f(a1, a2);                                \
        else return name##_s(a1, a2);                               \
    }                                                               \
}

#define arith_dispatch_2(stgclass, type, name)                      \
arith_dispatch_1a(inline, type, name##_i, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_b, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_r, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_c, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_s, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_f, name)                     \
                                                                    \
arith_dispatch_1a(inline, type, name##_d, name)                     \
                                                                    \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a1)) return name##_i(a1, a2);                     \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case TAG_NUMBERS:                                               \
        switch (type_of_header(numhdr(a1)))                         \
        {                                                           \
        case TYPE_BIGNUM:                                           \
            return name##_b(a1, a2);                                \
        case TYPE_RATNUM:                                           \
            return name##_r(a1, a2);                                \
        case TYPE_COMPLEX_NUM:                                      \
            return name##_c(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #name, a1, a2));             \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (flthdr(a1))                                         \
        {                                                           \
        case SINGLE_FLOAT_HEADER:                                   \
            return name##_f(a1, a2);                                \
        case DOUBLE_FLOAT_HEADER:                                   \
            return name##_d(a1, a2);                                \
        case LONG_FLOAT_HEADER:                                     \
            return name##_l(a1, a2);                                \
        default:                                                    \
            return static_cast<type>(                               \
                aerror2("bad arg for " #name, a1, a2));             \
        }                                                           \
    default:                                                        \
        return static_cast<type>(                                   \
            aerror2("bad arg for " #name, a1, a2));                 \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))           \
            return name##_f(a1, a2);                                \
        else return name##_s(a1, a2);                               \
    }                                                               \
}

#endif // HAVE_SOFTFLOAT

#ifdef HAVE_SOFTFLOAT

extern float128_t f128_epsilon;
extern float128_t f128_half_epsilon;
extern float128_t f128_max;
extern float128_t f128_negmax;
extern float128_t f128_min;
extern float128_t f128_negmin;
extern float128_t f128_normmin;
extern float128_t f128_negnormmin;  

// The following may eventually provide support for elementary functions
// on 128-bit floats.

extern float128_t qatan2(float128_t a, float128_t b);
extern float128_t qatan2d(float128_t a, float128_t b);
extern float128_t qexpt(float128_t a, float128_t b);
extern float128_t qlog(float128_t a, float128_t b);
extern float128_t qhypot(float128_t a, float128_t b);

extern float128_t qacos(float128_t a);
extern float128_t qacosd(float128_t a);
extern float128_t qacosh(float128_t a);
extern float128_t qacot(float128_t a);
extern float128_t qacotd(float128_t a);
extern float128_t qacoth(float128_t a);
extern float128_t qacsc(float128_t a);
extern float128_t qacscd(float128_t a);
extern float128_t qacsch(float128_t a);
extern float128_t qasec(float128_t a);
extern float128_t qasecd(float128_t a);
extern float128_t qasech(float128_t a);
extern float128_t qasin(float128_t a);
extern float128_t qasind(float128_t a);
extern float128_t qasinh(float128_t a);
extern float128_t qatan(float128_t a);
extern float128_t qatand(float128_t a);
extern float128_t qatanh(float128_t a);
extern float128_t qcbrt(float128_t a);
extern float128_t qcos(float128_t a);
extern float128_t qcosd(float128_t a);
extern float128_t qcosh(float128_t a);
extern float128_t qcot(float128_t a);
extern float128_t qcotd(float128_t a);
extern float128_t qcoth(float128_t a);
extern float128_t qcsc(float128_t a);
extern float128_t qcscd(float128_t a);
extern float128_t qcsch(float128_t a);
extern float128_t qexp(float128_t a);
extern float128_t qln(float128_t a);
extern float128_t qlog10(float128_t a);
extern float128_t qsec(float128_t a);
extern float128_t qsecd(float128_t a);
extern float128_t qsech(float128_t a);
extern float128_t qsin(float128_t a);
extern float128_t qsind(float128_t a);
extern float128_t qsinh(float128_t a);
extern float128_t qsqrt(float128_t a);
extern float128_t qtan(float128_t a);
extern float128_t qtand(float128_t a);
extern float128_t qtanh(float128_t a);
extern float128_t qlog2(float128_t a);

#endif // HAVE_SOFTFLOAT

// The names here are for the benefit of code compiled into C++ using
// ccomp.red.

#ifdef ARITHLIB

#define GABSVAL                 Nabs
#define GADD1                   Nadd1
#define GASH                    Nleftshift
#define GASH1                   Nash1
#define GATAN                   Natan
#define GDIFFER                 Ndifference
#define GEQN                    Neqn_a
#define GEVENP                  Nevenp
#define GEXPT                   Nexpt
#define GTRUNCATE               Ntruncate
#define GFLOAT                  Nfloat
#define GGCD                    Ngcdn
#define GGEQ                    Ngeq
#define GGREATERP               Ngreaterp
#define GIADD1                  Niadd1
#define GIDIFFERENCE            Nidifference
#define GIGREATERP              Nigreaterp
#define GILESSP                 Nilessp
#define GIMIMUS                 Niminus
#define GIMINUSP                Niminusp
#define GIPLUS                  Niplus
#define GIQUOTIENT              Niquotient
#define GIREMAINDER             Nremainder
#define GIRIGHTSHIFT            Nirightshift
#define GISUB1                  Nisub1
#define GITIMES                 Nitimes
#define GLCM                    Nlcm
#define GLEQ                    Nleq
#define GLESSP                  Nlessp
#define GLOGNOT                 Mlognot
#define GMAX                    Nmax
#define GMIN                    Nmin
#define GMINUS                  Nminus
#define GMINUSP                 Nminusp
#define GMOD                    Nmod
#define GSET_SMALL_MODULUS      Nset_small_modulus
#define GMODULAR_DIFFERENCE     Nmodular_difference
#define GMODULAR_EXPT           Nmodular_expt
#define GMODULAR_MINUS          Nmodular_minus
#define GMODULAR_NUMBER         Nmodular_number
#define GMODULAR_PLUS           Nmodular_plus
#define GMODULAR_QUOTIENT       Nmodular_quotient
#define GMODULAR_RECIPROCAL     Nmodular_reciprocal
#define GMODULAR_TIMES          Nmodular_times
#define GNEXT_RANDOM            Nnext_random
#define GODDP                   Noddp
#define GONEP                   Nonep
#define GPLUS                   Nplus
#define GPLUSP                  Nplusp
#define GQUOTIENT               Nquotient
#define GDIVIDE                 Ndivide
#define GRANDOM                 Nrandom
#define GRATIONAL               Nrational
#define GREM                    Nrem
#define GSUB1                   Nsub1
#define GTIMES                  Ntimes
#define GZEROP                  Nzerop
#define DPLUS2                  Plus::op
#define DDIFFERENCE2            Difference::op
#define DADD1                   Add1::op
#define DSUB1                   Sub1::op
#define DLOGNOT                 Lognot::op
#define DASH                    Leftshift::op
#define DQUOT                   Quotient::op
#define DCREMAINDER             Remainder::op
#define DTIMES2                 Times::op
#define DNEGATE                 Minus::op
#define DRATIONAL               Rational::op
#define DLESSP2                 Lessp::op
#define DLESSEQ2                Leq::op
#define DGREATERP2              Greaterp::op
#define DGEQ2                   Geq::op
#define DZEROP                  Dzerop     // must accept non-numbers

#include "dispatch.h"

inline bool Dzerop(LispObject n)
{   return is_number(n) && Zerop::op(n);
}

#else // ARITHLIB

#define GABSVAL                 Labsval
#define GADD1                   Ladd1
#define GASH                    Lash
#define GASH1                   Lash1
#define GATAN                   Latan
#define GDIFFER                 Ldifference_2
#define GEQN                    Leqn_2
#define GEVENP                  Levenp
#define GEXPT                   Lexpt
#define GTRUNCATE               Ltruncate
#define GFLOAT                  Lfloat
#define GGCD                    Lgcd_2
#define GGEQ                    Lgeq_2
#define GGREATERP               Lgreaterp_2
#define GIADD1                  Liadd1
#define GIDIFFERENCE            Lidifference_2
#define GIGREATERP              Ligreaterp_2
#define GILESSP                 Lilessp
#define GIMIMUS                 Liminus
#define GIMINUSP                Liminusp
#define GIPLUS                  Liplus_2
#define GIQUOTIENT              Liquotient_2
#define GIREMAINDER             Liremainder_2
#define GIRIGHTSHIFT            Lirightshift
#define GISUB1                  Lisub1
#define GITIMES                 Litimes_2
#define GLCM                    Llcm_2
#define GLEQ                    Lleq_2
#define GLESSP                  Llessp_2
#define GLOGNOT                 Llognot
#define GMAX                    Lmax_2
#define GMIN                    Lmin_2
#define GMINUS                  Lminus
#define GMINUSP                 Lminusp
#define GMOD                    Lmod_2
#define GSET_SMALL_MODULUS      Lset_small_modulus
#define GMODULAR_DIFFERENCE     Lmodular_difference
#define GMODULAR_EXPT           Lmodular_expt
#define GMODULAR_MINUS          Lmodular_minus
#define GMODULAR_NUMBER         Lmodular_number
#define GMODULAR_PLUS           Lmodular_plus
#define GMODULAR_QUOTIENT       Lmodular_quotient
#define GMODULAR_RECIPROCAL     Lmodular_reciprocal
#define GMODULAR_TIMES          Lmodular_times
#define GNEXT_RANDOM            Lnext_random
#define GODDP                   Loddp
#define GONEP                   Lonep
#define GPLUS                   Lplus_2
#define GPLUSP                  Lplusp
#define GQUOTIENT               Lquotient_2
#define GDIVIDE                 Ldivide_2
#define GRANDOM                 Lrandom
#define GRATIONAL               Lrational
#define GREM                    Lrem_2
#define GSUB1                   Lsub1
#define GTIMES                  Ltimes_2
#define GZEROP                  Lzerop
#define DPLUS2                  plus2
#define DDIFFERENCE2            difference2
#define DADD1                   add1
#define DSUB1                   sub1
#define DLOGNOT                 lognot
#define DASH                    ash
#define DQUOT                   quot2
#define DCREMAINDER             Cremainder
#define DTIMES2                 times2
#define DNEGATE                 negate
#define DRATIONAL               rational
#define DLESSP2                 lessp2
#define DLESSEQ2                lesseq2
#define DGREATERP2              greaterp2
#define DGEQ2                   geq2
#define DZEROP                  zerop

#endif // ARITHLIB

#endif // header_arith_h

// end of arith.h
