// arith.h                                Copyright (C) Codemist, 1990-2017


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// Tidy up re possible 128-bit arithemetic support.

#if defined HAVE___INT128 && !defined __HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif

#if defined HAVE_UNSIGNED___INT128 && !defined __HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif

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
#define clear_top_bit(n)   ((int32_t)(n) & 0x7fffffff)

// As with fixnum_of_int I need to take care here that the arithmetic I do
// here can not overflow, since if it did the behaviour would be undefined
// and a modern optimising compiler would be entitled to do pretty much
// whatever it felt like. I hope that good compilers will observe that the
// mask operation as written here is not really needed on most machines.

#define signed_overflow(n) \
  top_bit_set((uint32_t)(n) ^ ((uint32_t)(n) << 1))

// ADD32 forces and addition to be done as unsigned arithmetic, and may be
// useful when this avoids risk of a carry into the most significant bit
// being interpreted as overflow and hence undefined behaviour.

#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))


// The following all take an intptr_t or int64_t values (as per their name)
// and check if their argument would bit in a 29 or 31-bit signed value. I
// try fairly hard to avoid overflow and keep the code here so that the
// only way in which it goes beyond what the C/C++ standards guarantee is
// an assumption that numbers are 2s complement and that casts between
// signed and unsigned values leave the bitwise representations unchanged.

#define signed29_in_64(n)                                                   \
  (((int64_t)(((uint64_t)(n) & 0x1fffffffU) << 35) / ((int64_t)1 << 35)) == \
   (int64_t)(n))

#define signed31_in_64(n)                                                   \
  (((int64_t)(((uint64_t)(n) & 0x7fffffffU) << 33) / ((int64_t)1 << 33)) == \
   (int64_t)(n))

#define signed31_in_ptr(n)                                                  \
  (((intptr_t)(((uintptr_t)(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
    ((intptr_t)1 << (8*sizeof(intptr_t) - 31))) == (intptr_t)(n))

#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND    softfloat_round_near_even
#define FIX_FLOOR    softfloat_round_min
#define FIX_CEILING  softfloat_round_max

extern LispObject lisp_fix(LispObject a, int roundmode);


// The following tests for IEEE infinities and NaNs depends on arithmetic
// being regular double-precision rounded to a 64-bit double at each stage.
// An old-enough Intel system might have used the 8087-style 80-bit floating
// point and hance could cause trouble. I hope that all modern compilers
// for that architecture will use SSE instructions that behave in a more
// obvious IEEE manner.

static inline bool floating_edge_case(double r)
{   return (1.0/r == 0.0 || r != r);
}

static inline void floating_clear_flags()
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

#define Dmultiply(hi, lo, a, b, c)                        \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +      \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)

#define Ddivide(r, q, a, b, c)                                \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                              \
      r = (uint32_t)(r64 % c64); } while (0)

#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)

#define Ddivideq(q, a, b, c)                                  \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64); } while (0)

#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)

#define Ddivider(r, a, b, c)                                  \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      r = (uint32_t)(r64 % c64); } while (0)

#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)

//#define fixnum_minusp(a) ((intptr_t)(a) < 0)

#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)

static inline double value_of_immediate_float(LispObject a)
{   Float_union aa;
    if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
    else aa.i = (int32_t)(a - XTAG_SFLOAT);
    return aa.f;
}

extern LispObject make_boxfloat(double a, int type);
extern LispObject make_boxfloat128(float128_t a);

// Pack something as a short (28-bit) float

static inline LispObject pack_short_float(double d)
{   Float_union aa;
    aa.f = d;
    if (trap_floating_overflow &&
        floating_edge_case(aa.f))
    {   floating_clear_flags();
        aerror("exception with short float");
    }
    aa.i &= ~0xf;
    if (SIXTY_FOUR_BIT)
        return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT;
    else return aa.i + XTAG_SFLOAT;
}

// Create a single (32-bit) float. Just like make_single_float but inlined
// in the 64-bit case

static inline LispObject pack_single_float(double d)
{   if (SIXTY_FOUR_BIT)
    {   Float_union aa;
        aa.f = d;
        if (trap_floating_overflow &&
            floating_edge_case(aa.f))
        {   floating_clear_flags();
            aerror("exception with short float");
        }
        return (LispObject)((uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
    }
    else
    {   LispObject r = getvector(TAG_BOXFLOAT,
            TYPE_SINGLE_FLOAT, sizeof(Single_Float));
        single_float_val(r) = (float)d;
        if (trap_floating_overflow &&
            floating_edge_case(single_float_val(r)))
        {   floating_clear_flags();
            aerror("exception with single float");
        }
        return r;
    }
}

// Pack either a 28 or 32-bit float with type Lisp value "l1" indicating
// whether 28 or 32 bits are relevant. On a 32-bit machine like will always
// be a 28-bit value. If a second argument l2 is provided the width of the
// result will match the wider of the two.

static inline LispObject pack_immediate_float(double d,
                                              LispObject l1, LispObject l2=0)
{   Float_union aa;
    aa.f = d;
    if (trap_floating_overflow &&
        floating_edge_case(aa.f))
    {   floating_clear_flags();
        aerror("exception with short float");
    }
    if (SIXTY_FOUR_BIT)
    {   if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
        return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT +
            ((l1 | l2) & XTAG_FLOAT32);
    }
    aa.i &= ~0xf;
    return aa.i + XTAG_SFLOAT;
}

// comparing 64-bit integers against (double precision) is perhaps
// unexpectedly delicate. Here is some code to help. You can find two
// sources of extra commentary about this. One is by Andrew Koenig in
// a Dr Doobs article in 2013, the other is in (MIT Licensed) Julia and
// a discussion at https://github.com/JuliaLang/julia/issues/257.

static inline bool eq_i64d(int64_t a, double b)
{
// The integer can always be converted to a double, but of course
// sometimes there will be rounding involved. But if the value does not
// match the double even after rounding then the two values are certainly
// different. Also if the double happens to be a NaN this will lead to
// a returned value of false (as required).
    if (b != (double)a) return false;
// Now the two values differ by at most the rounding that happened when
// the integer was converted to a double. This ALMOST means that the double
// has a value that fits in the range of integers. However if a has a value
// just less than 2^63 and b is (double)(2^63) then b can not be cast to
// an integer safely. In C++ the consequence of trying to cast a double to
// and int where the result would not fit is undefined, and so could
// include arbitrary bad behaviour. So I have to filter that case out.
    if (b == (double)((uint64_t)1<<63)) return false;
// With the special case out of the way I can afford to case from double to
// int64_t. The negative end of the range is safe!
    return a == (int64_t)b;
}

static inline bool lessp_i64d(int64_t a, double b)
{
// If the integer is <= 2^53 then converting it to a double does not
// introduce any error at all, so I can perform the comparison reliably
// on doubles. If d ia a NaN this is still OK.
    if (a <= ((int64_t)1<<53) &&
        a >= -((int64_t)1<<53)) return (double)a < b;
// If the float is outside the range of int64_t I can tell how the
// comparison must play out. Note that near the value 2^63 the next
// double value lower than 2^63 is in integer, as we can not have any
// floating point value larger than the largest positive int64_t value
// and less then 2^63. I make these tests of the form "if (!xxx)" because
// then if b is a NaN the comparison returns false and I end up exiting.
    if (!(b >= -(double)((uint64_t)1<<63))) return false;
    if (!(b < (double)((uint64_t)1<<63))) return true;
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
    return a < (int64_t)b;
}

static inline bool lessp_di64(double a, int64_t b)
{
// The logic here is much as above - by omitting all the commentary
// you can see much more clearly just how long the code is.
    if (b <= ((int64_t)1<<53) &&
        b >= -((int64_t)1<<53)) return a < (double)b;
    if (!(a < (double)((uint64_t)1<<63))) return false;
    if (!(a >= -(double)((uint64_t)1<<63))) return true;
    return (int64_t)a < b;
}

extern "C" LispObject negateb(LispObject);
extern "C" LispObject copyb(LispObject);
extern "C" LispObject negate(LispObject);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern "C" LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject CLquot2(LispObject a, LispObject b);
extern "C" LispObject quotbn(LispObject a, int32_t n);
extern "C" LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED    1
#define QUOTBB_REMAINDER_NEEDED   2
extern "C" LispObject quotbb(LispObject a, LispObject b, int needs);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern "C" LispObject rembi(LispObject a, LispObject b);
extern "C" LispObject rembb(LispObject a, LispObject b);
extern "C" LispObject shrink_bignum(LispObject a, size_t lena);
extern "C" LispObject modulus(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern "C" LispObject rationalize(LispObject a);
extern "C" LispObject lcm(LispObject a, LispObject b);
extern "C" LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern "C" bool numeq2(LispObject a, LispObject b);
extern "C" bool zerop(LispObject a);
extern "C" bool onep(LispObject a);
extern "C" bool minusp(LispObject a);
extern "C" bool plusp(LispObject a);

extern LispObject validate_number(const char *s, LispObject a,
                                  LispObject b, LispObject c);

extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
                                        uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
                                     uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
                                      uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
                                      uint32_t a2, uint32_t a1,
                                      uint32_t a0, size_t n);

extern LispObject make_lisp_integer32_fn(int32_t n);
static inline LispObject make_lisp_integer32(int32_t n)
{   if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
    else return make_lisp_integer32_fn(n);
}

extern LispObject make_lisp_integer64_fn(int64_t n);
static inline LispObject make_lisp_integer64(int64_t n)
{   if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
    else return make_lisp_integer64_fn(n);
}

extern LispObject make_lisp_unsigned64_fn(uint64_t n);
static inline LispObject make_lisp_unsigned64(uint64_t n)
{   if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
        return fixnum_of_int((intptr_t)n);
    else return make_lisp_unsigned64_fn(n);
}

extern LispObject make_lisp_integerptr_fn(intptr_t n);
static inline LispObject make_lisp_integerptr(intptr_t n)
{   if (valid_as_fixnum(n)) return fixnum_of_int(n);
    else return make_lisp_integerptr_fn(n);
}

extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{   if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
        return fixnum_of_int((intptr_t)n);
    else return make_lisp_unsignedptr_fn(n);
}

#ifdef HAVE_INT128_T

extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{   if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
    else return make_lisp_integer128_fn(n);
}

#endif

extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);

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

#if defined HAVE_LIBPTHREAD || defined WIN32

//
// For the parallel variant on Karatsuba I need thread support and
// semaphores.
//

#include <semaphore.h>

#ifdef WIN32
#include <windows.h>

extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);

#else
#include <pthread.h>

extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);

#endif

#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
       *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
       kara_sem2a, kara_sem2b, kara_sem2c;
#endif

extern size_t karatsuba_parallel;

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

#endif // Thread support

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
#define KARATSUBA_CUTOFF 12

#endif


// Now some stuff relating to the float128_t type

static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern "C" void f128M_split(
    const float128_t *x, float128_t *yhi, float128_t *ylo);

#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif

static inline bool f128M_zero(const float128_t *p)
{   return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
            (p->v[LOPART] == 0);
}

static inline bool f128M_infinite(const float128_t *p)
{   return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
            ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
            (p->v[LOPART] == 0);
}

static inline bool f128M_finite(const float128_t *p)
{   return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}

static inline void f128M_make_infinite(float128_t *p)
{   p->v[HIPART] |= UINT64_C(0x7fff000000000000);
    p->v[HIPART] &= UINT64_C(0xffff000000000000);
    p->v[LOPART] = 0;
}

static inline void f128M_make_zero(float128_t *p)
{   p->v[HIPART] &= UINT64_C(0x8000000000000000);
    p->v[LOPART] = 0;
}

// Here I do not count 0.0 (or -0.0) as sub-normal.

static inline bool f128M_subnorm(const float128_t *p)
{   return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
            (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
             (p->v[LOPART] != 0));
}

static inline bool f128M_nan(const float128_t *p)
{   return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
            (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
             (p->v[LOPART] != 0));
}

static inline bool f128M_negative(const float128_t *x)
{   if (f128M_nan(x)) return false;
    return ((int64_t)x->v[HIPART]) < 0;
}

static inline int f128M_exponent(const float128_t *p)
{   return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}

static inline void f128M_set_exponent(float128_t *p, int n)
{   p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
        (((uint64_t)n + 0x3fff) << 48);
}

static inline void f128M_negate(float128_t *x)
{   x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}

static inline bool floating_edge_case128(float128_t *r)
{   return f128M_infinite(r) || f128M_nan(r);
}

extern int double_to_binary(double d, int64_t &m);
extern int float128_to_binary(const float128_t *d,
                              int64_t &mhi, uint64_t &mlo);

extern intptr_t double_to_3_digits(double d,
    int32_t &a2, uint32_t &a1, uint32_t &a0);
extern intptr_t float128_to_5_digits(float128_t *d,
    int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);


extern "C" float128_t f128_0,      // 0.0L0
                      f128_half,   // 0.5L0
                      f128_mhalf,  // -0.5L0
                      f128_1,      // 1.0L0
                      f128_10,     // 10.0L0
                      f128_10_17,  // 1.0L17
                      f128_10_18,  // 1.0L18
                      f128_r10,    // 0.1L0
                      f128_N1;     // 2.0L0^4096

typedef struct _float256_t
{
#ifdef LITTLEENDIAN
    float128_t lo;
    float128_t hi;
#else
    float128_t hi;
    float128_t lo;
#endif
} float256_t;

static inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{   b->hi = *a;
    b->lo = f128_0;
} 

extern "C" void f256M_add(
    const float256_t *x, const float256_t *y, float256_t *z);

extern "C" void f256M_mul(
    const float256_t *x, const float256_t *y, float256_t *z);

extern "C" void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);

extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;

// These print 128-bit floats in the various standard styles, returning the
// number of characters used. The "sprint" versions put their result in
// a buffer, while "print" goes to stdout.

extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);

extern "C" float128_t atof128(const char *s);

// Now let me provide a macro to do full type-dispatch for the implementation
// of a generic arithmetic operator. This is a pretty hideously large macro
// and it does a full dispatch in every single case, but still writing it
// just once is probably a good idea.

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

// arith_dispatch_1 switches into one of 8 sub-functions whose names are
// got be suffixing the top-level name with one of the above letters.
// arith_dispatch_2 ends up with 64 sub-functions to call.

// First for 1-arg functions

#define arith_dispatch_1(stgclass, type, name)                      \
stgclass type name(LispObject a1)                                   \
{   if (is_fixnum(a1)) return name##_i(a1);                         \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        return name##_s(a1);                                        \
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
            aerror1("bad arg for " #name, a1);                      \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (type_of_header(flthdr(a1)))                         \
        {                                                           \
        case TYPE_SINGLE_FLOAT:                                     \
            return name##_f(a1);                                    \
        case TYPE_DOUBLE_FLOAT:                                     \
            return name##_d(a1);                                    \
        case TYPE_LONG_FLOAT:                                       \
            return name##_l(a1);                                    \
        default:                                                    \
            aerror1("bad arg for " #name, a1);                      \
        }                                                           \
    default:                                                        \
        aerror1("bad arg for " #name, a1);                          \
    }                                                               \
}

// Now a helper macro for 2-arg functions

#define arith_dispatch_1a(stgclass, type, name, rawname)            \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a2)) return name##_i(a1, a2);                     \
    switch (a2 & TAG_BITS)                                          \
    {                                                               \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        return name##_s(a1, a2);                                    \
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
            aerror2("bad arg for " #rawname, a1, a2);               \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (type_of_header(flthdr(a2)))                         \
        {                                                           \
        case TYPE_SINGLE_FLOAT:                                     \
            return name##_f(a1, a2);                                \
        case TYPE_DOUBLE_FLOAT:                                     \
            return name##_d(a1, a2);                                \
        case TYPE_LONG_FLOAT:                                       \
            return name##_l(a1, a2);                                \
        default:                                                    \
            aerror2("bad arg for " #rawname, a1, a2);               \
        }                                                           \
    default:                                                        \
        aerror2("bad arg for " #rawname, a1, a2);                   \
    }                                                               \
}

#define arith_dispatch_2(stgclass, type, name)                      \
arith_dispatch_1a(static inline, type, name##_i, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_b, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_r, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_c, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_s, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_f, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_d, name)              \
                                                                    \
arith_dispatch_1a(static inline, type, name##_l, name)              \
                                                                    \
stgclass type name(LispObject a1, LispObject a2)                    \
{   if (is_fixnum(a1)) return name##_i(a1, a2);                     \
    switch (a1 & TAG_BITS)                                          \
    {                                                               \
    case (XTAG_SFLOAT & TAG_BITS):                                  \
        return name##_s(a1, a2);                                    \
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
            aerror2("bad arg for " #name, a1, a2);                  \
        }                                                           \
    case TAG_BOXFLOAT:                                              \
        switch (type_of_header(flthdr(a1)))                         \
        {                                                           \
        case TYPE_SINGLE_FLOAT:                                     \
            return name##_f(a1, a2);                                \
        case TYPE_DOUBLE_FLOAT:                                     \
            return name##_d(a1, a2);                                \
        case TYPE_LONG_FLOAT:                                       \
            return name##_l(a1, a2);                                \
        default:                                                    \
            aerror2("bad arg for " #name, a1, a2);                  \
        }                                                           \
    default:                                                        \
        aerror2("bad arg for " #name, a1, a2);                      \
    }                                                               \
}

#endif // header_arith_h

// end of arith.h
