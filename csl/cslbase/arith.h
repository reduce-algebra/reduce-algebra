// arith.h                         Copyright (C) Codemist Ltd, 1990-2015


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

#define M2_31_1   -2147483649.0     // -(2^31 + 1)

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

#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))

#ifdef HAVE_UINT64_T
//
// Here I do some arithmetic in-line. In the following macros I need to
// take care that the names used for local variables do not clash with
// those used in the body of the code. Hence the names r64 and c64, which
// I must agree not to use elsewhere.  Note also the "do {} while (0)" idiom
// to avoid nasty problems with C syntax and the need for semicolons.
//
#define IMULTIPLY 1      // External function not needed
#define Dmultiply(hi, lo, a, b, c)                        \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +      \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
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
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#define Ddivideq(q, a, b, c) (Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9q(q, a, b)   (Idiv10_9(&(q), (a), (b)))
#define Ddivider(r, a, b, c) ((r) = Idivide(NULL, (a), (b), (c)))
#define Ddiv10_9r(r, a, b)   ((r) = Idiv10_9(NULL, (a), (b)))
#endif

#define fix_mask (-0x08000000)

#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)

extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
extern LispObject quotbb(LispObject a, LispObject b);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, int32_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern CSLbool numeq2(LispObject a, LispObject b);
extern "C" CSLbool zerop(LispObject a);
extern CSLbool onep(LispObject a);
extern CSLbool minusp(LispObject a);
extern CSLbool plusp(LispObject a);
extern CSLbool lesspbd(LispObject a, double b);
extern CSLbool lessprd(LispObject a, double b);
extern CSLbool lesspdb(double a, LispObject b);
extern CSLbool lesspdr(double a, LispObject b);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
                                     uint32_t a3, int32_t n);
extern LispObject make_lisp_integer32(int32_t n);
extern LispObject make_lisp_integer64(int64_t n);
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);

extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(LispObject a, LispObject b);
extern CSLbool lesspib(LispObject a, LispObject b);

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

extern int karatsuba_parallel;

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

#endif // header_arith_h

// end of arith.h
