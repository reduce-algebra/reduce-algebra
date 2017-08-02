
// $destdir/u57.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <setjmp.h>
#include <exception>
#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#ifndef DEBUG
#define NDEBUG 1
#endif
#if defined HAVE_COMPLEX_H && \
 defined HAVE_COMPLEX_DOUBLE && \
 defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#endif
#ifdef WIN32
#include <winsock.h>
#include <semaphore.h>
#include <windows.h>
#else 
#define unix_posix 1 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError() errno 
#define WSACleanup() 
#define closesocket(a) close(a)
#define SOCKET int
#define SOCKET_ERROR (-1)
#ifndef INADDR_NONE
# define INADDR_NONE 0xffffffff
#endif
#ifdef HAVE_LIBPTHREAD
#include <semaphore.h>
#include <pthread.h>
#endif
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>
#include <errno.h>
#include <assert.h>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
extern "C"
{
#include "softfloat.h"
}
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 4)
typedef int32_t intptr_t;
#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 8)
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 4)
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 8)
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#ifndef UINTPTR_MAX
#define UINTPTR_MAX ((uintptr_t)(-1))
#endif
#ifndef INTPTR_MAX
#define INTPTR_MAX ((intptr_t)((UINTPTR_MAX-1)/2))
#endif
#ifndef INTPTR_MIN
#define INTPTR_MIN (-1-INTPTR_MAX)
#endif
#define MAXSHIFT(n, a) ((n) >= (int)(8*sizeof(a)) || (n) < 0 ? 0 : (n))
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
#define ASR(a, n) ((a) >> MAXSHIFT((n), a))
#else 
#include <type_traits>
template <typename T>
static inline T ASR(T a, int n)
{ typedef typename std::make_signed<T>::type ST;
 return ((ST)(a&~(((T)1<<MAXSHIFT(n,T))-1)))/((ST)1<<MAXSHIFT(n,T));
}
#endif 
#define ASL32(a,n) ((int32_t)((uint32_t)(a)<<MAXSHIFT((n),uint32_t)))
#define ASLptr(a,n) ((intptr_t)((uintptr_t)(a)<<MAXSHIFT((n),uintptr_t)))
#define ASL64(a,n) ((int64_t)((uint64_t)(a)<<MAXSHIFT((n),uint64_t)))
#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h" 
#endif
#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
static inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
static inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
static inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
static inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
static inline int128_t ASL128(int128_t a, int n)
{ return (uint128_t)a << MAXSHIFT(n, int128_t);
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
static inline int128_t ASR128(int128_t a, int n)
{ return a >> MAXSHIFT(n, int128_t);
}
#else 
static inline int128_t ASR128(int128_t a, int n)
{ n = MAXSHIFT(n, int128_t);
 return (a & ~((uint128_t)1<<n - 1))/(int128_t)1<<n;
}
#endif 
static inline int64_t NARROW128(int128_t a)
{ return (int64_t)a;
}
static inline void divrem128(int128_t a, int128_t b,
 int128_t & q, int128_t & r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
static inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
static inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
static inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
static inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
static inline int128_t ASL128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
static inline int128_t ASR128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
 a.upper());
 else return int128_t(-(int64_t)(a.upper()<0),
 ASR(((int64_t)a.upper()), n-64));
}
static inline int64_t NARROW128(const int128_t & a)
{ return (int64_t)a.lower();
}
static inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((int64_t)a.upper() < 0)
 { if ((int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
typedef intptr_t LispObject;
#define CELL ((size_t)sizeof(LispObject))
#define TAG_BITS 7
#define XTAG_BITS 15
#define TAG_CONS 0 
#define TAG_VECTOR 1 
#define TAG_HDR_IMMED 2 
#define TAG_FORWARD 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_BOXFLOAT 6 
#define TAG_FIXNUM 7 
#define TAG_XBIT 8 
#define XTAG_SFLOAT 15 
#define XTAG_FLOAT32 16
static inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
static inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
static inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
static inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
static inline LispObject fixnum_of_int(intptr_t x)
{ return (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}
static inline intptr_t int_of_fixnum(LispObject x)
{ return ((intptr_t)x & ~(intptr_t)15)/16;
}
static inline bool valid_as_fixnum(int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
static inline bool intptr_valid_as_fixnum(intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((uintptr_t)1) << 28);
}
static inline bool valid_as_fixnum(uint64_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
static inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED) 
#define is_sfloat(p) ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#define car_legal(p) is_cons(p)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef LispObject four_args(LispObject, size_t, LispObject, LispObject,
 LispObject, LispObject);
typedef uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) ((((size_t)(h)) >> (Tw+7)) << 2)
#define length_of_bitheader(h) ((((size_t)(h)) >> (Tw+2)) - 31)
#define length_of_byteheader(h) ((((size_t)(h)) >> (Tw+5)) - 3)
#define length_of_hwordheader(h) ((((size_t)(h)) >> (Tw+6)) - 1)
#define bitvechdr_(n) (TYPE_BITVEC_1 + ((((n)+31)&31)<<(Tw+2)))
#define TYPE_SYMBOL 0x00000000 
#define SYM_SPECIAL_VAR 0x00000080 
#define SYM_FLUID_VAR 0x00000080 
#define SYM_GLOBAL_VAR 0x00000100 
#define SYM_KEYWORD_VAR 0x00000180 
#define SYM_SPECIAL_FORM 0x00000200 
#define SYM_MACRO 0x00000400 
#define SYM_C_DEF 0x00000800 
#define SYM_CODEPTR 0x00001000 
#define SYM_ANY_GENSYM 0x00002000 
#define SYM_TRACED 0x00004000 
#define SYM_TRACESET 0x00008000 
#define SYM_TAGGED 0x00010000 
#define SYM_FASTGET_MASK 0x007e0000 
#define SYM_FASTGET_SHIFT 17
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00800000 
#define SYM_IN_PACKAGE 0xff000000U 
#define SYM_IN_PKG_SHIFT 24
#define SYM_IN_PKG_COUNT 8
#else 
#define SYM_UNPRINTED_GENSYM 0x00800000 
#endif 
#define symhdr_length (doubleword_align_up(sizeof(Symbol_Head)))
#define is_symbol_header(h) (((int)h & (0xf<<Tw)) == TYPE_SYMBOL)
#define is_symbol_header_full_test(h) \
 (((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED))
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define is_number_header_full_test(h) \
 (((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED))
#define is_vector_header_full_test(h) \
 (is_odds(h) && (((int)h & (0x3<<Tw)) != 0))
#define is_array_header(h) (type_of_header(h) == TYPE_ARRAY)
#define vector_i8(h) (((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i16(h) (((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i32(h) (((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i64(h) (((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i128(h) (((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f32(h) (((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f64(h) (((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f128(h) (((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define is_string_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1)
#define is_string(n) is_string_header(vechdr(n))
#define is_vec8_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1)
#define is_vec8(n) is_vec8_header(vechdr(n))
#define is_bps_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1)
#define is_bps(n) is_bps_header(vechdr(n))
#define is_vec16_header(h) ((type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1)
#define is_vec16(n) is_vec16_header(vechdr(n))
#define is_bitvec_header(h) ((type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1)
#define is_bitvec(n) is_bitvec_header(vechdr(n))
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))*sizeof(LispObject))))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define data_of_bps(v) ((unsigned char *)(v) + (CELL-TAG_VECTOR))
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
#define vselt(v, n) (*(LispObject *)(((intptr_t)(v) & ~((intptr_t)TAG_BITS)) + \
 ((1 + (intptr_t)(n))*sizeof(LispObject))))
#define helt(v, n) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)))
#define sethelt(v, n, x) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)) = (x))
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(intptr_t))))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(int32_t))))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(float))))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(double))))
#define TYPE_BITVEC_1 ( 0x02 <<Tw) 
#define TYPE_BITVEC_2 ( 0x06 <<Tw) 
#define TYPE_BITVEC_3 ( 0x0a <<Tw) 
#define TYPE_BITVEC_4 ( 0x0c <<Tw) 
#define TYPE_BITVEC_5 ( 0x12 <<Tw) 
#define TYPE_BITVEC_6 ( 0x16 <<Tw) 
#define TYPE_BITVEC_7 ( 0x1a <<Tw) 
#define TYPE_BITVEC_8 ( 0x1c <<Tw) 
#define TYPE_BITVEC_9 ( 0x22 <<Tw) 
#define TYPE_BITVEC_10 ( 0x26 <<Tw) 
#define TYPE_BITVEC_11 ( 0x2a <<Tw) 
#define TYPE_BITVEC_12 ( 0x2c <<Tw) 
#define TYPE_BITVEC_13 ( 0x32 <<Tw) 
#define TYPE_BITVEC_14 ( 0x36 <<Tw) 
#define TYPE_BITVEC_15 ( 0x3a <<Tw) 
#define TYPE_BITVEC_16 ( 0x3c <<Tw) 
#define TYPE_BITVEC_17 ( 0x42 <<Tw) 
#define TYPE_BITVEC_18 ( 0x46 <<Tw) 
#define TYPE_BITVEC_19 ( 0x4a <<Tw) 
#define TYPE_BITVEC_20 ( 0x4c <<Tw) 
#define TYPE_BITVEC_21 ( 0x52 <<Tw) 
#define TYPE_BITVEC_22 ( 0x56 <<Tw) 
#define TYPE_BITVEC_23 ( 0x5a <<Tw) 
#define TYPE_BITVEC_24 ( 0x5c <<Tw) 
#define TYPE_BITVEC_25 ( 0x62 <<Tw) 
#define TYPE_BITVEC_26 ( 0x66 <<Tw) 
#define TYPE_BITVEC_27 ( 0x6a <<Tw) 
#define TYPE_BITVEC_28 ( 0x6c <<Tw) 
#define TYPE_BITVEC_29 ( 0x72 <<Tw) 
#define TYPE_BITVEC_30 ( 0x76 <<Tw) 
#define TYPE_BITVEC_31 ( 0x7a <<Tw) 
#define TYPE_BITVEC_32 ( 0x7c <<Tw) 
#define TYPE_STRING_1 ( 0x07 <<Tw) 
#define TYPE_STRING_2 ( 0x27 <<Tw) 
#define TYPE_STRING_3 ( 0x47 <<Tw) 
#define TYPE_STRING_4 ( 0x67 <<Tw) 
#define TYPE_VEC8_1 ( 0x03 <<Tw) 
#define TYPE_VEC8_2 ( 0x23 <<Tw) 
#define TYPE_VEC8_3 ( 0x43 <<Tw) 
#define TYPE_VEC8_4 ( 0x63 <<Tw) 
#define TYPE_BPS_1 ( 0x0b <<Tw) 
#define TYPE_BPS_2 ( 0x2b <<Tw) 
#define TYPE_BPS_3 ( 0x4b <<Tw) 
#define TYPE_BPS_4 ( 0x6b <<Tw) 
#define TYPE_VEC16_1 ( 0x0f <<Tw) 
#define TYPE_VEC16_2 ( 0x4f <<Tw) 
#if 0
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#endif
#define TYPE_FOREIGN ( 0x33 <<Tw) 
#define TYPE_SP ( 0x37 <<Tw) 
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) 
#define vector_holds_binary(h) (((h) & (0x2<<Tw)) != 0)
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_NEWHASH ( 0x15 <<Tw) 
#define TYPE_NEWHASHX ( 0x19 <<Tw) 
#define TYPE_HASH ( 0x21 <<Tw) 
#define TYPE_ARRAY ( 0x05 <<Tw) 
#define TYPE_STRUCTURE ( 0x09 <<Tw) 
#define TYPE_OBJECT ( 0x0d <<Tw) 
#define TYPE_VEC32 ( 0x13 <<Tw) 
#define TYPE_VEC64 ( 0x17 <<Tw) 
#define TYPE_VEC128 ( 0x1b <<Tw) 
#define TYPE_VECFLOAT32 ( 0x53 <<Tw) 
#define TYPE_VECFLOAT64 ( 0x57 <<Tw) 
#define TYPE_VECFLOAT128 ( 0x5b <<Tw) 
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)
#define TYPE_MIXED1 ( 0x41 <<Tw) 
#define TYPE_MIXED2 ( 0x45 <<Tw) 
#define TYPE_MIXED3 ( 0x49 <<Tw) 
#define TYPE_STREAM ( 0x4d <<Tw) 
#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) 
#define HDR_IMMED_MASK (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR (( 0x4 <<Tw) | TAG_HDR_IMMED) 
#define TAG_SPID (( 0xc <<Tw) | TAG_HDR_IMMED) 
#define SPID_NIL (TAG_SPID+(0x00<<(Tw+4))) 
#define SPID_FBIND (TAG_SPID+(0x01<<(Tw+4))) 
#define SPID_CATCH (TAG_SPID+(0x02<<(Tw+4))) 
#define SPID_PROTECT (TAG_SPID+(0x03<<(Tw+4))) 
#define SPID_HASHEMPTY (TAG_SPID+(0x04<<(Tw+4))) 
#define SPID_HASHTOMB (TAG_SPID+(0x05<<(Tw+4))) 
#define SPID_GCMARK (TAG_SPID+(0x06<<(Tw+4))) 
#define SPID_NOINPUT (TAG_SPID+(0x07<<(Tw+4))) 
#define SPID_ERROR (TAG_SPID+(0x08<<(Tw+4))) 
#define SPID_PVBIND (TAG_SPID+(0x09<<(Tw+4))) 
#define SPID_NOARG (TAG_SPID+(0x0a<<(Tw+4))) 
#define SPID_NOPROP (TAG_SPID+(0x0b<<(Tw+4))) 
#define SPID_LIBRARY (TAG_SPID+(0x0c<<(Tw+4))) 
#define is_header(x) (((int)(x) & (0x3<<Tw)) != 0) 
#define is_char(x) (((int)(x) & HDR_IMMED_MASK) == TAG_CHAR)
#define is_spid(x) (((int)(x) & HDR_IMMED_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xfffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> (21+4+Tw)) & 0xf)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> (4+Tw)) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << (21+4+Tw)) | \
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 union {
 intptr_t functionn; 
 intptr_t function4; 
 intptr_t function5up;
 };
 uint64_t count; 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#define qheader(p) (*(Header *)((char *)(p) + (0*CELL-TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)((char *)(p) + (1*CELL-TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)((char *)(p) + (2*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define qpackage(p) (*(LispObject *)((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define ifn0(p) (*(intptr_t *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define ifn1(p) (*(intptr_t *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define ifn3(p) (*(intptr_t *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define ifn4(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn0(p) (*(no_args **)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfn1(p) (*(one_args **)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qfn2(p) (*(two_args **)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define qfn3(p) (*(three_args **)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define qfnn(p) (*(n_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn4(p) (*(four_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uint64_t *)((char *)(p) + (12*CELL-TAG_SYMBOL)))
typedef union _Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
#define low32(a) ((LispObject)(uint32_t)(a))
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#define bignum_digits(b) \
 ((uint32_t *)((char *)(b) + (CELL-TAG_NUMBERS)))
#define bignum_digits64(b, n) \
 ((int64_t)((int32_t *)((char *)(b)+(CELL-TAG_NUMBERS)))[n])
#define make_bighdr(n) (TAG_HDR_IMMED+TYPE_BIGNUM+(((intptr_t)(n))<<(Tw+7)))
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define float32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f32)
#define intfloat32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.i)
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float64_t_val(v) (*(float64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat64_t_val(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 24
#define long_float_addr(v) ((float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define long_float_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float128_t_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val0(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val1(v) (*(int64_t *)((char *)(v) + \
 (16-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((uintptr_t)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_SIGNAL 0x6 
#define UNWIND_SIGINT 0x7 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" NORETURN void error(int nargs, int code, ...);
extern "C" NORETURN void cerror(int nargs, int code1, int code2, ...);
extern "C" NORETURN void too_few_2(LispObject env, LispObject a1);
extern "C" NORETURN void too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_0a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_3a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_na(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_1(LispObject env, int nargs, ...);
extern "C" NORETURN void wrong_no_2(LispObject env, int nargs, ...);
extern "C" NORETURN void bad_specialn(LispObject env, int nargs, ...);
#define TOO_FEW_2 ((one_args *)too_few_2)
#define TOO_MANY_1 ((two_args *)too_many_1)
#define WRONG_NO_0A ((one_args *)wrong_no_0a)
#define WRONG_NO_0B ((two_args *)wrong_no_0b)
#define WRONG_NO_3A ((one_args *)wrong_no_3a)
#define WRONG_NO_3B ((two_args *)wrong_no_3b)
#define WRONG_NO_NA ((one_args *)wrong_no_na)
#define WRONG_NO_NB ((two_args *)wrong_no_nb)
#define WRONG_NO_1 ((n_args *)wrong_no_1)
#define WRONG_NO_2 ((n_args *)wrong_no_2)
#define BAD_SPECIALN ((n_args *)bad_specialn)
extern "C" NORETURN void aerror(const char *s); 
extern "C" NORETURN void aerror0(const char *s);
extern "C" NORETURN void aerror1(const char *s, LispObject a);
extern "C" NORETURN void aerror2(const char *s, LispObject a, LispObject b);
extern "C" NORETURN void fatal_error(int code, ...);
extern "C" LispObject carerror(LispObject a);
extern "C" LispObject cdrerror(LispObject a);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_0 3 
#define err_undefined_function_1 4 
#define err_undefined_function_2 5 
#define err_undefined_function_3 6 
#define err_undefined_function_4 7 
#define err_undefined_function_n 7 
#define err_wrong_no_args 8 
#define err_unbound_lexical 9 
#define err_bad_rplac 10 
#define err_bad_arith 11 
#define err_redef_special 12 
#define err_bad_arg 13 
#define err_bad_declare 14 
#define err_bad_fn 15 
#define err_unset_var 16 
#define err_too_many_args0 17 
#define err_too_many_args1 18 
#define err_too_many_args2 19 
#define err_too_many_args3 20 
#define err_bad_apply 21 
#define err_macroex_hook 22 
#define err_block_tag 23 
#define err_go_tag 24 
#define err_excess_args 25
#define err_insufficient_args 26
#define err_bad_bvl 27 
#define err_bad_keyargs 28
#define err_write_err 29
#define err_bad_endp 30 
#define err_no_fasldir 31
#define err_no_fasl 32 
#define err_open_failed 33 
#define err_pipe_failed 34 
#define err_stack_overflow 35
#define err_top_bit 36
#define err_mem_spans_zero 37
#define err_no_longer_used 38 
#define err_no_tempdir 39
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (0 arg)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 arg)",
 "undefined function", 
 "wrong number of arguments",
 "unbound lexical variable",
 "bad rplaca/rplacd",
 "bad argument for an arithmetic function",
 "attempt to redefine a special form",
 "not a variable",
 "bad use of declare",
 "attempt to apply non-function",
 "unset variable",
 "too many arguments for 0-arg function",
 "too many arguments for 1-arg function",
 "too many arguments for 2-arg function",
 "too many arguments for 3-arg function",
 "object not valid as a function (apply,",
 "macroexpand-hook failure",
 "block tag not found",
 "go tag not found",
 "too many arguments provided",
 "not enough arguments provided",
 "bad item in bound variable list",
 "bad keyword arguments",
 "write-error on file",
 "endp used on badly terminated list",
 "environment parameter 'fasldir' not set",
 "loadable module not found for loading",
 "file could not be opened",
 "unable to establish pipe",
 "stack overflow",
 "top bit of address has unexpected value",
 "memory block spans the zero address",
 "this error code available for re-use",
 "unable to find a directory for temporary files",
 "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
 (long long unsigned)(s)); \
 fflush(stderr); \
 } while (0)
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count, heap_pages_count, vheap_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *stack;
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern bool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *_p_ = (char *)&_p_; \
 if (_p_ < C_stack_limit) aerror("stack overflow"); \
 }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 }
extern LispObject nil;
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
extern intptr_t byteflip;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol, gcknt_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol; 
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, int nargs, ...);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) 
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables, equal_hash_tables;
extern uint32_t hash_equal(LispObject key);
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;
extern LispObject *repeat_heap;
extern size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern FILE *binary_write_file;
extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif
extern void report_file(const char *s);
extern bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern bool next_gc_is_hard;
extern uint64_t force_cons, force_vec;
static inline bool cons_forced(size_t n)
{
#ifdef DEBUG
 if (force_cons == 0) return false;
 if (force_cons <= n)
 { force_cons = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_cons -= n;
#endif
 return false;
}
static inline bool vec_forced(size_t n)
{
#ifdef DEBUG
 if (force_vec == 0) return false;
 if (force_vec <= n)
 { force_vec = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_vec -= n;
#endif
 return false;
}
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
#define CODESIZE 0x1000
typedef struct _entry_point0
{ no_args *p;
 const char *s;
} entry_point0;
typedef struct _entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct _entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct _entry_point3
{ three_args *p;
 const char *s;
} entry_point3;
typedef struct _entry_point4
{ four_args *p;
 const char *s;
} entry_point4;
typedef struct _entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4 entries_table4[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_tableio[];
extern void set_up_entry_lookup();
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep(const char *name, size_t len, char *datestamp,
 size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, size_t *lenp);
extern bool Icopy(const char *name, size_t len);
extern bool Idelete(const char *name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen();
extern int window_heading;
extern void my_abort();
extern "C" NORETURN void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern int deal_with_tick();
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern "C" void low_level_signal_handler(int code);
extern "C" void sigint_handler(int code);
extern "C" int async_interrupt(int a);
extern "C" void record_get(LispObject tag, bool found);
extern bool isprime(uint64_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" bool eql_fn(LispObject a, LispObject b);
extern "C" bool cl_equal_fn(LispObject a, LispObject b);
extern "C" bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern "C" LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" bool geq2(LispObject a, LispObject b);
extern "C" bool greaterp2(LispObject a, LispObject b);
extern "C" bool lesseq2(LispObject a, LispObject b);
extern "C" bool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, size_t len);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, bool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject quotrem2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern int64_t sixty_four_bits(LispObject a);
extern uint64_t sixty_four_bits_unsigned(LispObject a);
extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
static inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
static inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
static inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
static inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
static inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#define argcheck(var, n, msg) if ((var)!=(n)) aerror(msg);
extern n_args *no_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern four_args *four_arg_functions[];
extern n_args *three_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool four_arg_traceflags[];
extern bool three_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *four_arg_names[];
extern const char *three_arg_names[];
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
 arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 lisphash_setup[], newhash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
extern setup_type const
 u01_setup[], u02_setup[], u03_setup[], u04_setup[],
 u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
 u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
 u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
 u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
 u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
 u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
 u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
 u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
 u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
 u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
 u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
 u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
NORETURN extern void resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
extern unsigned char msd_table[256], lsd_table[256];
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n) ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n) ((int32_t)(n) & 0x7fffffff)
#define signed_overflow(n) \
 top_bit_set((uint32_t)(n) ^ ((uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x1fffffffU) << 35) / ((int64_t)1 << 35)) == \
 (int64_t)(n))
#define signed31_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x7fffffffU) << 33) / ((int64_t)1 << 33)) == \
 (int64_t)(n))
#define signed31_in_ptr(n) \
 (((intptr_t)(((uintptr_t)(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
 ((intptr_t)1 << (8*sizeof(intptr_t) - 31))) == (intptr_t)(n))
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
static inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
static inline void floating_clear_flags()
{}
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
static inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
 else aa.i = (int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type);
extern LispObject make_boxfloat128(float128_t a);
static inline LispObject pack_short_float(double d)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with short float");
 }
 aa.i &= ~0xf;
 if (SIXTY_FOUR_BIT)
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT;
 else return aa.i + XTAG_SFLOAT;
}
static inline LispObject pack_single_float(double d)
{ if (SIXTY_FOUR_BIT)
 { Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return (LispObject)((uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
 }
 else
 { LispObject r = getvector(TAG_BOXFLOAT,
 TYPE_SINGLE_FLOAT, sizeof(Single_Float));
 single_float_val(r) = (float)d;
 if (trap_floating_overflow &&
 floating_edge_case(single_float_val(r)))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return r;
 }
}
static inline LispObject pack_immediate_float(double d,
 LispObject l1, LispObject l2=0)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 if (((l1 | l2) & XTAG_FLOAT32) != 0)
 aerror("exception with single float");
 else aerror("exception with short float");
 }
 if (SIXTY_FOUR_BIT)
 { if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
static inline bool eq_i64d(int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((uint64_t)1<<63)) return false;
 return a == (int64_t)b;
}
static inline bool lessp_i64d(int64_t a, double b)
{
 if (a <= ((int64_t)1<<53) &&
 a >= -((int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((uint64_t)1<<63))) return false;
 if (!(b < (double)((uint64_t)1<<63))) return true;
 return a < (int64_t)b;
}
static inline bool lessp_di64(double a, int64_t b)
{
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
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
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
extern "C" LispObject integer_decode_long_float(LispObject a);
extern "C" LispObject Linteger_decode_float(LispObject env, LispObject a);
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
extern LispObject make_power_of_two(size_t n);
extern LispObject make_lisp_integer32_fn(int32_t n);
static inline LispObject make_lisp_integer32(int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(int64_t n);
static inline LispObject make_lisp_integer64(int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(uint64_t n);
static inline LispObject make_lisp_unsigned64(uint64_t n)
{ if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(intptr_t n);
static inline LispObject make_lisp_integerptr(intptr_t n)
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
static inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
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
extern LispObject rationalf128(float128_t *d);
extern int _reduced_exp(double, double *);
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#ifdef WIN32
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
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
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" void f128M_frexp(float128_t *p, float128_t *r, int *x);
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
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
static inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
static inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
static inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((int64_t)x->v[HIPART]) < 0;
}
static inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
static inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((uint64_t)n + 0x3fff) << 48);
}
static inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
static inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
extern int double_to_binary(double d, int64_t &m);
extern int float128_to_binary(const float128_t *d,
 int64_t &mhi, uint64_t &mlo);
extern intptr_t double_to_3_digits(double d,
 int32_t &a2, uint32_t &a1, uint32_t &a0);
extern intptr_t float128_to_5_digits(float128_t *d,
 int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);
extern "C" float128_t f128_0, 
 f128_half, 
 f128_mhalf, 
 f128_1, 
 f128_10, 
 f128_10_17, 
 f128_10_18, 
 f128_r10, 
 f128_N1; 
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
{ b->hi = *a;
 b->lo = f128_0;
} 
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(static inline, type, name##_i, name) \
 \
arith_dispatch_1a(static inline, type, name##_b, name) \
 \
arith_dispatch_1a(static inline, type, name##_r, name) \
 \
arith_dispatch_1a(static inline, type, name##_c, name) \
 \
arith_dispatch_1a(static inline, type, name##_s, name) \
 \
arith_dispatch_1a(static inline, type, name##_f, name) \
 \
arith_dispatch_1a(static inline, type, name##_d, name) \
 \
arith_dispatch_1a(static inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
}
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject env, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject env, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lall_symbols0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject env, int nargs, ...);
extern "C" LispObject Lgc0(LispObject env, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_selected_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_spid(LispObject, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject env, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject env, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject Lunserialize(LispObject env, int nargs, ...);
extern "C" LispObject undefined0(LispObject env);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lall_symbols(LispObject env, LispObject a1);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject env, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject env, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" NORETURN void Lerror1(LispObject env, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject env, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject env, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject env, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject env, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject env, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject env, LispObject a);
extern "C" LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject env, LispObject a);
extern "C" LispObject Lis_spid(LispObject env, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject env, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject env, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Lload_selected_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject env, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject env, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject env, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lrepresentation1(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lserialize(LispObject env, LispObject a);
extern "C" LispObject Lserialize1(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspid_to_nil(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" NORETURN void Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
extern "C" LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lerror2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject env, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern "C" LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject env, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject undefined3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject env, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
extern "C" LispObject Lappend_n(LispObject env, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject env, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject env, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject env, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject env, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject env, int nargs, ...);
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject env, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putError(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_putObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern "C" LispObject om_getApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getError(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_getObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getInt(LispObject env, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject env, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject env, LispObject ldev);
extern "C" LispObject om_getVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getString(LispObject env, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject env, LispObject ldev);
extern "C" LispObject om_getType(LispObject env, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern "C" LispObject om_read(LispObject env, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject env, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject env, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject env, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern "C" LispObject undefined4(LispObject env, size_t n, LispObject a1,
 LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
class stack_popper
{ int n;
public:
 stack_popper(int nn)
 { n = nn;
 }
 ~stack_popper()
 { popv(n);
 }
};
class stack_restorer
{ LispObject *stackSave;
public:
 stack_restorer()
 { stackSave = stack;
 }
 ~stack_restorer()
 { stack = stackSave;
 }
};
class save_current_function
{ LispObject *savestack;
public:
 save_current_function(LispObject newfn)
 { push(current_function);
 savestack = stack;
 current_function = newfn;
 }
 ~save_current_function()
 { stack = savestack;
 pop(current_function);
 }
};
class bind_fluid_stack
{ LispObject *savestack;
 int env_loc;
 int name_loc;
 int val_loc;
public:
 bind_fluid_stack(int e, int name, int val)
 { savestack = stack;
 env_loc = e;
 name_loc = name;
 val_loc = val;
#ifdef TRACE_FLUID
 debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
 debug_printf("name="); prin_to_debug(elt(savestack[e], name));
 debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
 debug_printf("\n");
#endif
 savestack[val] = qvalue(elt(savestack[e], name));
 }
 ~bind_fluid_stack()
 {
#ifdef TRACE_FLUID
 debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
 debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
 debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
 debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
 debug_printf("\n");
#endif
 qvalue(elt(savestack[env_loc], name_loc)) = savestack[val_loc];
 }
};
struct LispException : public std::exception
{ virtual const char *what() const throw()
 { return "Generic Lisp Exception";
 }
};
 struct LispError : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Error";
 }
 };
 struct LispSignal : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Signal";
 }
 };
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
 }
 };
 struct LispSigint : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Sigint";
 }
 };
 struct LispGo : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Go";
 }
 };
 struct LispReturnFrom : public LispException
 { virtual const char *what() const throw()
 { return "Lisp ReturnFrom";
 }
 };
 struct LispThrow : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Throw";
 }
 };
 struct LispRestart : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Restart";
 }
 };
class RAIIstack_sanity
{ LispObject *saveStack;
 const char *fname;
 const char *file;
 int line;
 LispObject w;
public:
 RAIIstack_sanity(const char *fn, const char *fi, int li)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = nil;
 }
 RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = ww;
 }
 ~RAIIstack_sanity()
 { if (saveStack != stack && !std::uncaught_exception())
 { printf("???SP %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 if (w != nil)
 { err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 }
 }
 }
};
static inline const char *tidy_filename(const char *a)
{ const char *b = strrchr(a, '/');
 return (b == NULL ? a : b+1);
}
#ifdef DEBUG
#define STACK_SANITY \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w) \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY ;
#define STACK_SANITY1(w) ;
#endif
class RAIIsave_codevec
{ LispObject *saveStack;
public:
 RAIIsave_codevec()
 { push2(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop2(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
extern LispObject *stack;
extern jmp_buf *global_jb;
class RAIIsave_stack_and_jb
{ LispObject *saveStack;
 jmp_buf *jbsave;
public:
 RAIIsave_stack_and_jb()
 { jbsave = global_jb; 
 saveStack = stack; 
 }
 ~RAIIsave_stack_and_jb()
 { global_jb = jbsave; 
 stack = saveStack; 
 }
};
class RAIIsave_stack
{ LispObject *saveStack;
public:
 RAIIsave_stack()
 { saveStack = stack; 
 }
 ~RAIIsave_stack()
 { stack = saveStack; 
 }
};
#define START_SETJMP_BLOCK \
 jmp_buf jb; \
 RAIIsave_stack_and_jb save_stack_Object; \
 switch (setjmp(jb)) \
 { default: \
 case 1: exit_reason = UNWIND_SIGNAL; \
 throw LispSignal(); \
 case 2: exit_reason = UNWIND_SIGINT; \
 throw LispSigint(); \
 case 0: break; \
 } \
 global_jb = &jb;
#define START_TRY_BLOCK \
 RAIIsave_stack save_stack_Object;
#define on_backtrace(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { int _reason = exit_reason; \
 b; \
 exit_reason = _reason; \
 throw; \
 }
#define if_error(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#endif 



// Code for unshift

static LispObject CC_unshift(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34232, v_34233, v_34234, v_34235;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34235 = v_34168;
// end of prologue
    v_34232 = qvalue(elt(env, 1)); // !*xo
    v_34234 = v_34232;
    v_34232 = v_34234;
    v_34232 = qcar(v_34232);
    if (!consp(v_34232)) goto v_34179;
    goto v_34190;
v_34186:
    v_34232 = v_34234;
    v_34232 = qcar(v_34232);
    v_34232 = qcdr(v_34232);
    v_34233 = qcar(v_34232);
    goto v_34187;
v_34188:
    v_34232 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34189;
v_34190:
    goto v_34186;
v_34187:
    goto v_34188;
v_34189:
    if (v_34233 == v_34232) goto v_34184;
    else goto v_34185;
v_34184:
    goto v_34200;
v_34196:
    v_34232 = v_34234;
    v_34232 = qcdr(v_34232);
    v_34232 = qcdr(v_34232);
    v_34233 = qcar(v_34232);
    goto v_34197;
v_34198:
    v_34232 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34199;
v_34200:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    v_34232 = (v_34233 == v_34232 ? lisp_true : nil);
    goto v_34183;
v_34185:
    v_34232 = nil;
    goto v_34183;
    v_34232 = nil;
v_34183:
    goto v_34177;
v_34179:
    goto v_34216;
v_34212:
    v_34233 = v_34234;
    goto v_34213;
v_34214:
    v_34232 = elt(env, 2); // (0.0 . 0.0)
    goto v_34215;
v_34216:
    goto v_34212;
v_34213:
    goto v_34214;
v_34215:
    v_34232 = (equal(v_34233, v_34232) ? lisp_true : nil);
    goto v_34177;
    v_34232 = nil;
v_34177:
    if (v_34232 == nil) goto v_34173;
    v_34232 = v_34235;
    goto v_34171;
v_34173:
    goto v_34229;
v_34225:
    v_34233 = v_34235;
    goto v_34226;
v_34227:
    v_34232 = qvalue(elt(env, 1)); // !*xo
    goto v_34228;
v_34229:
    goto v_34225;
v_34226:
    goto v_34227;
v_34228:
    fn = elt(env, 3); // gfplus
    v_34232 = (*qfn2(fn))(fn, v_34233, v_34232);
    env = stack[0];
    {
        fn = elt(env, 4); // gfadjust
        return (*qfn1(fn))(fn, v_34232);
    }
    v_34232 = nil;
v_34171:
    return onevalue(v_34232);
}



// Code for physopplus

static LispObject CC_physopplus(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34240, v_34241;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
    v_34240 = stack[0];
    v_34240 = qcar(v_34240);
    fn = elt(env, 3); // physopsim!*
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    stack[-3] = v_34240;
    v_34240 = stack[0];
    v_34240 = qcdr(v_34240);
    stack[0] = v_34240;
v_34183:
    v_34240 = stack[0];
    if (v_34240 == nil) goto v_34188;
    else goto v_34189;
v_34188:
    goto v_34182;
v_34189:
    v_34240 = stack[0];
    v_34240 = qcar(v_34240);
    fn = elt(env, 3); // physopsim!*
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    stack[-2] = v_34240;
    v_34240 = stack[-3];
    fn = elt(env, 4); // getphystype
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    stack[-1] = v_34240;
    v_34240 = stack[-2];
    fn = elt(env, 4); // getphystype
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    v_34241 = v_34240;
    if (v_34241 == nil) goto v_34204;
    v_34241 = stack[-1];
    if (v_34241 == nil) goto v_34204;
    goto v_34215;
v_34211:
    v_34241 = stack[-1];
    goto v_34212;
v_34213:
    goto v_34214;
v_34215:
    goto v_34211;
v_34212:
    goto v_34213;
v_34214:
    if (v_34241 == v_34240) goto v_34204;
    goto v_34223;
v_34219:
    v_34241 = elt(env, 0); // physopplus
    goto v_34220;
v_34221:
    v_34240 = elt(env, 2); // "type mismatch in plus "
    goto v_34222;
v_34223:
    goto v_34219;
v_34220:
    goto v_34221;
v_34222:
    fn = elt(env, 5); // rederr2
    v_34240 = (*qfn2(fn))(fn, v_34241, v_34240);
    env = stack[-4];
    goto v_34202;
v_34204:
v_34202:
    goto v_34232;
v_34228:
    v_34240 = stack[-3];
    fn = elt(env, 6); // physop2sq
    stack[-1] = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    goto v_34229;
v_34230:
    v_34240 = stack[-2];
    fn = elt(env, 6); // physop2sq
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    goto v_34231;
v_34232:
    goto v_34228;
v_34229:
    goto v_34230;
v_34231:
    fn = elt(env, 7); // addsq
    v_34240 = (*qfn2(fn))(fn, stack[-1], v_34240);
    env = stack[-4];
    fn = elt(env, 8); // mk!*sq
    v_34240 = (*qfn1(fn))(fn, v_34240);
    env = stack[-4];
    stack[-3] = v_34240;
    v_34240 = stack[0];
    v_34240 = qcdr(v_34240);
    stack[0] = v_34240;
    goto v_34183;
v_34182:
    v_34240 = stack[-3];
    return onevalue(v_34240);
}



// Code for bassoc

static LispObject CC_bassoc(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34197, v_34198;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34169;
    stack[-1] = v_34168;
// end of prologue
v_34173:
    v_34197 = stack[0];
    if (v_34197 == nil) goto v_34176;
    else goto v_34177;
v_34176:
    v_34197 = nil;
    goto v_34172;
v_34177:
    goto v_34187;
v_34183:
    v_34198 = stack[-1];
    goto v_34184;
v_34185:
    v_34197 = stack[0];
    v_34197 = qcar(v_34197);
    v_34197 = qcar(v_34197);
    goto v_34186;
v_34187:
    goto v_34183;
v_34184:
    goto v_34185;
v_34186:
    fn = elt(env, 1); // th_match
    v_34197 = (*qfn2(fn))(fn, v_34198, v_34197);
    env = stack[-2];
    if (v_34197 == nil) goto v_34181;
    v_34197 = stack[0];
    goto v_34172;
v_34181:
    v_34197 = stack[0];
    v_34197 = qcdr(v_34197);
    stack[0] = v_34197;
    goto v_34173;
    v_34197 = nil;
v_34172:
    return onevalue(v_34197);
}



// Code for !*sq2fourier

static LispObject CC_Hsq2fourier(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34240, v_34241, v_34242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
    v_34240 = stack[0];
    v_34240 = qcar(v_34240);
    if (v_34240 == nil) goto v_34172;
    else goto v_34173;
v_34172:
    v_34240 = nil;
    goto v_34171;
v_34173:
    v_34240 = (LispObject)48+TAG_FIXNUM; // 3
    v_34240 = Lmkvect(nil, v_34240);
    env = stack[-3];
    stack[-2] = v_34240;
    goto v_34191;
v_34185:
    v_34242 = stack[-2];
    goto v_34186;
v_34187:
    v_34241 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34188;
v_34189:
    v_34240 = stack[0];
    goto v_34190;
v_34191:
    goto v_34185;
v_34186:
    goto v_34187;
v_34188:
    goto v_34189;
v_34190:
    *(LispObject *)((char *)v_34242 + (CELL-TAG_VECTOR) + (((intptr_t)v_34241-TAG_FIXNUM)/(16/CELL))) = v_34240;
    goto v_34201;
v_34195:
    v_34242 = stack[-2];
    goto v_34196;
v_34197:
    v_34241 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34198;
v_34199:
    v_34240 = elt(env, 2); // cos
    goto v_34200;
v_34201:
    goto v_34195;
v_34196:
    goto v_34197;
v_34198:
    goto v_34199;
v_34200:
    *(LispObject *)((char *)v_34242 + (CELL-TAG_VECTOR) + (((intptr_t)v_34241-TAG_FIXNUM)/(16/CELL))) = v_34240;
    goto v_34211;
v_34205:
    stack[-1] = stack[-2];
    goto v_34206;
v_34207:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_34208;
v_34209:
    fn = elt(env, 5); // fs!:make!-nullangle
    v_34240 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_34210;
v_34211:
    goto v_34205;
v_34206:
    goto v_34207;
v_34208:
    goto v_34209;
v_34210:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_34240;
    goto v_34221;
v_34215:
    v_34242 = stack[-2];
    goto v_34216;
v_34217:
    v_34241 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_34218;
v_34219:
    v_34240 = nil;
    goto v_34220;
v_34221:
    goto v_34215;
v_34216:
    goto v_34217;
v_34218:
    goto v_34219;
v_34220:
    *(LispObject *)((char *)v_34242 + (CELL-TAG_VECTOR) + (((intptr_t)v_34241-TAG_FIXNUM)/(16/CELL))) = v_34240;
    goto v_34230;
v_34226:
    goto v_34236;
v_34232:
    v_34241 = elt(env, 3); // fourier
    goto v_34233;
v_34234:
    v_34240 = elt(env, 4); // tag
    goto v_34235;
v_34236:
    goto v_34232;
v_34233:
    goto v_34234;
v_34235:
    v_34241 = get(v_34241, v_34240);
    goto v_34227;
v_34228:
    v_34240 = stack[-2];
    goto v_34229;
v_34230:
    goto v_34226;
v_34227:
    goto v_34228;
v_34229:
    return cons(v_34241, v_34240);
    goto v_34171;
    v_34240 = nil;
v_34171:
    return onevalue(v_34240);
}



// Code for all_index_lst

static LispObject CC_all_index_lst(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34236, v_34237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_34168;
// end of prologue
    stack[-2] = nil;
v_34174:
    v_34236 = stack[-1];
    if (v_34236 == nil) goto v_34179;
    else goto v_34180;
v_34179:
    goto v_34175;
v_34180:
    goto v_34187;
v_34183:
    v_34236 = stack[-1];
    v_34236 = qcar(v_34236);
    v_34236 = qcdr(v_34236);
    stack[0] = v_34236;
    v_34236 = stack[0];
    v_34236 = qcar(v_34236);
    fn = elt(env, 2); // listp
    v_34236 = (*qfn1(fn))(fn, v_34236);
    env = stack[-3];
    if (v_34236 == nil) goto v_34195;
    goto v_34205;
v_34201:
    v_34236 = stack[0];
    v_34236 = qcar(v_34236);
    v_34237 = qcar(v_34236);
    goto v_34202;
v_34203:
    v_34236 = elt(env, 1); // list
    goto v_34204;
v_34205:
    goto v_34201;
v_34202:
    goto v_34203;
v_34204:
    if (v_34237 == v_34236) goto v_34200;
    else goto v_34195;
v_34200:
    v_34236 = stack[0];
    v_34236 = qcdr(v_34236);
    v_34237 = v_34236;
    goto v_34193;
v_34195:
    v_34236 = stack[0];
    v_34237 = v_34236;
    goto v_34193;
    v_34237 = nil;
v_34193:
    goto v_34184;
v_34185:
    v_34236 = stack[-2];
    goto v_34186;
v_34187:
    goto v_34183;
v_34184:
    goto v_34185;
v_34186:
    v_34236 = cons(v_34237, v_34236);
    env = stack[-3];
    stack[-2] = v_34236;
    v_34236 = stack[-1];
    v_34236 = qcdr(v_34236);
    stack[-1] = v_34236;
    goto v_34174;
v_34175:
    v_34236 = nil;
    v_34237 = v_34236;
v_34176:
    v_34236 = stack[-2];
    if (v_34236 == nil) goto v_34221;
    else goto v_34222;
v_34221:
    v_34236 = v_34237;
    goto v_34173;
v_34222:
    goto v_34230;
v_34226:
    v_34236 = stack[-2];
    v_34236 = qcar(v_34236);
    goto v_34227;
v_34228:
    goto v_34229;
v_34230:
    goto v_34226;
v_34227:
    goto v_34228;
v_34229:
    v_34236 = Lappend(nil, v_34236, v_34237);
    env = stack[-3];
    v_34237 = v_34236;
    v_34236 = stack[-2];
    v_34236 = qcdr(v_34236);
    stack[-2] = v_34236;
    goto v_34176;
v_34173:
    return onevalue(v_34236);
}



// Code for sc_create

static LispObject CC_sc_create(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34216, v_34217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_34168;
// end of prologue
    stack[-2] = nil;
    v_34216 = stack[-1];
    stack[0] = v_34216;
v_34179:
    v_34216 = stack[0];
    v_34216 = sub1(v_34216);
    env = stack[-3];
    v_34216 = Lminusp(nil, v_34216);
    env = stack[-3];
    if (v_34216 == nil) goto v_34184;
    goto v_34178;
v_34184:
    goto v_34194;
v_34190:
    v_34217 = stack[0];
    goto v_34191;
v_34192:
    v_34216 = stack[-2];
    goto v_34193;
v_34194:
    goto v_34190;
v_34191:
    goto v_34192;
v_34193:
    v_34216 = cons(v_34217, v_34216);
    env = stack[-3];
    stack[-2] = v_34216;
    v_34216 = stack[0];
    v_34216 = sub1(v_34216);
    env = stack[-3];
    stack[0] = v_34216;
    goto v_34179;
v_34178:
    goto v_34204;
v_34200:
    goto v_34210;
v_34206:
    v_34217 = stack[-2];
    goto v_34207;
v_34208:
    v_34216 = elt(env, 2); // symbolic
    goto v_34209;
v_34210:
    goto v_34206;
v_34207:
    goto v_34208;
v_34209:
    fn = elt(env, 3); // list2vect!*
    stack[0] = (*qfn2(fn))(fn, v_34217, v_34216);
    env = stack[-3];
    goto v_34201;
v_34202:
    v_34216 = stack[-1];
    v_34216 = sub1(v_34216);
    env = stack[-3];
    v_34216 = Lmkvect(nil, v_34216);
    goto v_34203;
v_34204:
    goto v_34200;
v_34201:
    goto v_34202;
v_34203:
    {
        LispObject v_34221 = stack[0];
        return cons(v_34221, v_34216);
    }
    return onevalue(v_34216);
}



// Code for change!+sq!+to!+int

static LispObject CC_changeLsqLtoLint(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34195, v_34196, v_34197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34195 = v_34168;
// end of prologue
    fn = elt(env, 3); // prepsq
    v_34195 = (*qfn1(fn))(fn, v_34195);
    env = stack[0];
    fn = elt(env, 4); // simp!*
    v_34195 = (*qfn1(fn))(fn, v_34195);
    env = stack[0];
    v_34197 = v_34195;
    goto v_34185;
v_34181:
    v_34195 = v_34197;
    v_34196 = qcdr(v_34195);
    goto v_34182;
v_34183:
    v_34195 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34184;
v_34185:
    goto v_34181;
v_34182:
    goto v_34183;
v_34184:
    if (v_34196 == v_34195) goto v_34179;
    else goto v_34180;
v_34179:
    v_34195 = v_34197;
    v_34195 = qcar(v_34195);
    goto v_34172;
v_34180:
    v_34195 = elt(env, 2); // "no integer in change!+sq!+to!+int"
    fn = elt(env, 5); // rederr
    v_34195 = (*qfn1(fn))(fn, v_34195);
    goto v_34178;
v_34178:
    v_34195 = nil;
v_34172:
    return onevalue(v_34195);
}



// Code for qqe_simpat

static LispObject CC_qqe_simpat(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34171;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34171 = v_34168;
// end of prologue
    return onevalue(v_34171);
}



// Code for operator

static LispObject CC_operator(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34188;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_34188 = v_34168;
// end of prologue
    stack[0] = v_34188;
v_34173:
    v_34188 = stack[0];
    if (v_34188 == nil) goto v_34177;
    else goto v_34178;
v_34177:
    v_34188 = nil;
    goto v_34172;
v_34178:
    v_34188 = stack[0];
    v_34188 = qcar(v_34188);
    fn = elt(env, 1); // mkop
    v_34188 = (*qfn1(fn))(fn, v_34188);
    env = stack[-1];
    v_34188 = stack[0];
    v_34188 = qcdr(v_34188);
    stack[0] = v_34188;
    goto v_34173;
v_34172:
    return onevalue(v_34188);
}



// Code for cr!:minusp

static LispObject CC_crTminusp(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34221, v_34222, v_34223;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
// copy arguments values to proper place
    v_34221 = v_34168;
// end of prologue
    v_34222 = v_34221;
    v_34222 = qcdr(v_34222);
    v_34222 = qcar(v_34222);
    v_34221 = qcdr(v_34221);
    v_34221 = qcdr(v_34221);
    v_34223 = v_34222;
    v_34222 = v_34221;
    v_34221 = v_34223;
    if (!consp(v_34221)) goto v_34180;
    else goto v_34181;
v_34180:
    v_34221 = v_34222;
    v_34221 = (LispObject)zerop(v_34221);
    v_34221 = v_34221 ? lisp_true : nil;
    if (v_34221 == nil) goto v_34185;
    else goto v_34186;
v_34185:
    v_34221 = nil;
    goto v_34184;
v_34186:
    goto v_34197;
v_34193:
    v_34222 = v_34223;
    goto v_34194;
v_34195:
    v_34221 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34196;
v_34197:
    goto v_34193;
v_34194:
    goto v_34195;
v_34196:
        return Llessp(nil, v_34222, v_34221);
    v_34221 = nil;
v_34184:
    goto v_34179;
v_34181:
    v_34221 = v_34222;
    v_34221 = qcar(v_34221);
    v_34221 = (LispObject)zerop(v_34221);
    v_34221 = v_34221 ? lisp_true : nil;
    if (v_34221 == nil) goto v_34204;
    else goto v_34205;
v_34204:
    v_34221 = nil;
    goto v_34203;
v_34205:
    goto v_34217;
v_34213:
    v_34221 = v_34223;
    v_34222 = qcar(v_34221);
    goto v_34214;
v_34215:
    v_34221 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34216;
v_34217:
    goto v_34213;
v_34214:
    goto v_34215;
v_34216:
        return Llessp(nil, v_34222, v_34221);
    v_34221 = nil;
v_34203:
    goto v_34179;
    v_34221 = nil;
v_34179:
    return onevalue(v_34221);
}



// Code for expttermp

static LispObject CC_expttermp(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34203, v_34204, v_34205, v_34206;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34205 = v_34169;
    v_34206 = v_34168;
// end of prologue
    goto v_34180;
v_34176:
    v_34204 = v_34206;
    goto v_34177;
v_34178:
    v_34203 = elt(env, 1); // expt
    goto v_34179;
v_34180:
    goto v_34176;
v_34177:
    goto v_34178;
v_34179:
    if (!consp(v_34204)) goto v_34174;
    v_34204 = qcar(v_34204);
    if (v_34204 == v_34203) goto v_34173;
    else goto v_34174;
v_34173:
    goto v_34188;
v_34184:
    v_34203 = v_34206;
    v_34203 = qcdr(v_34203);
    v_34203 = qcar(v_34203);
    goto v_34185;
v_34186:
    v_34204 = v_34205;
    goto v_34187;
v_34188:
    goto v_34184;
v_34185:
    goto v_34186;
v_34187:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_34203, v_34204);
    }
v_34174:
    goto v_34200;
v_34196:
    v_34203 = v_34206;
    goto v_34197;
v_34198:
    v_34204 = v_34205;
    goto v_34199;
v_34200:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_34203, v_34204);
    }
    v_34203 = nil;
    return onevalue(v_34203);
}



// Code for xpndwedge

static LispObject CC_xpndwedge(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34216, v_34217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
    stack[-1] = nil;
v_34174:
    v_34216 = stack[0];
    v_34216 = qcdr(v_34216);
    if (v_34216 == nil) goto v_34179;
    else goto v_34180;
v_34179:
    goto v_34175;
v_34180:
    goto v_34188;
v_34184:
    v_34216 = stack[0];
    v_34216 = qcar(v_34216);
    fn = elt(env, 1); // partitop
    v_34217 = (*qfn1(fn))(fn, v_34216);
    env = stack[-2];
    goto v_34185;
v_34186:
    v_34216 = stack[-1];
    goto v_34187;
v_34188:
    goto v_34184;
v_34185:
    goto v_34186;
v_34187:
    v_34216 = cons(v_34217, v_34216);
    env = stack[-2];
    stack[-1] = v_34216;
    v_34216 = stack[0];
    v_34216 = qcdr(v_34216);
    stack[0] = v_34216;
    goto v_34174;
v_34175:
    v_34216 = stack[0];
    v_34216 = qcar(v_34216);
    fn = elt(env, 1); // partitop
    v_34216 = (*qfn1(fn))(fn, v_34216);
    env = stack[-2];
    fn = elt(env, 2); // mkunarywedge
    v_34216 = (*qfn1(fn))(fn, v_34216);
    env = stack[-2];
    v_34217 = v_34216;
v_34176:
    v_34216 = stack[-1];
    if (v_34216 == nil) goto v_34201;
    else goto v_34202;
v_34201:
    v_34216 = v_34217;
    goto v_34173;
v_34202:
    goto v_34210;
v_34206:
    v_34216 = stack[-1];
    v_34216 = qcar(v_34216);
    goto v_34207;
v_34208:
    goto v_34209;
v_34210:
    goto v_34206;
v_34207:
    goto v_34208;
v_34209:
    fn = elt(env, 3); // wedgepf2
    v_34216 = (*qfn2(fn))(fn, v_34216, v_34217);
    env = stack[-2];
    v_34217 = v_34216;
    v_34216 = stack[-1];
    v_34216 = qcdr(v_34216);
    stack[-1] = v_34216;
    goto v_34176;
v_34173:
    return onevalue(v_34216);
}



// Code for acmemb

static LispObject CC_acmemb(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34197, v_34198;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34169;
    stack[-1] = v_34168;
// end of prologue
v_34173:
    v_34197 = stack[0];
    if (v_34197 == nil) goto v_34176;
    else goto v_34177;
v_34176:
    v_34197 = nil;
    goto v_34172;
v_34177:
    goto v_34187;
v_34183:
    v_34198 = stack[-1];
    goto v_34184;
v_34185:
    v_34197 = stack[0];
    v_34197 = qcar(v_34197);
    goto v_34186;
v_34187:
    goto v_34183;
v_34184:
    goto v_34185;
v_34186:
    fn = elt(env, 1); // aceq
    v_34197 = (*qfn2(fn))(fn, v_34198, v_34197);
    env = stack[-2];
    if (v_34197 == nil) goto v_34181;
    v_34197 = stack[0];
    v_34197 = qcar(v_34197);
    goto v_34172;
v_34181:
    v_34197 = stack[0];
    v_34197 = qcdr(v_34197);
    stack[0] = v_34197;
    goto v_34173;
    v_34197 = nil;
v_34172:
    return onevalue(v_34197);
}



// Code for noncom1

static LispObject CC_noncom1(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34180, v_34181;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34181 = v_34168;
// end of prologue
    v_34180 = lisp_true;
    qvalue(elt(env, 1)) = v_34180; // !*ncmp
    goto v_34176;
v_34172:
    v_34180 = v_34181;
    v_34180 = ncons(v_34180);
    env = stack[0];
    goto v_34173;
v_34174:
    v_34181 = elt(env, 2); // noncom
    goto v_34175;
v_34176:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
        return Lflag(nil, v_34180, v_34181);
}



// Code for rationalizef

static LispObject CC_rationalizef(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34394, v_34395;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_34168;
// end of prologue
    v_34394 = stack[-2];
    fn = elt(env, 9); // kernels
    v_34394 = (*qfn1(fn))(fn, v_34394);
    env = stack[-4];
    stack[0] = v_34394;
    stack[-3] = v_34394;
v_34175:
    v_34394 = stack[-3];
    if (v_34394 == nil) goto v_34181;
    else goto v_34182;
v_34181:
    v_34394 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34174;
v_34182:
    v_34394 = stack[-3];
    v_34394 = qcar(v_34394);
    stack[-1] = v_34394;
    goto v_34200;
v_34196:
    v_34395 = stack[-1];
    goto v_34197;
v_34198:
    v_34394 = elt(env, 2); // expt
    goto v_34199;
v_34200:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    if (!consp(v_34395)) goto v_34194;
    v_34395 = qcar(v_34395);
    if (v_34395 == v_34394) goto v_34193;
    else goto v_34194;
v_34193:
    goto v_34212;
v_34208:
    v_34394 = stack[-1];
    v_34394 = qcdr(v_34394);
    v_34394 = qcdr(v_34394);
    v_34395 = qcar(v_34394);
    goto v_34209;
v_34210:
    v_34394 = elt(env, 3); // quotient
    goto v_34211;
v_34212:
    goto v_34208;
v_34209:
    goto v_34210;
v_34211:
    if (!consp(v_34395)) goto v_34206;
    v_34395 = qcar(v_34395);
    if (v_34395 == v_34394) goto v_34205;
    else goto v_34206;
v_34205:
    goto v_34223;
v_34219:
    v_34395 = stack[0];
    goto v_34220;
v_34221:
    v_34394 = stack[-1];
    v_34394 = qcdr(v_34394);
    goto v_34222;
v_34223:
    goto v_34219;
v_34220:
    goto v_34221;
v_34222:
    fn = elt(env, 10); // lowertowerp
    v_34394 = (*qfn2(fn))(fn, v_34395, v_34394);
    env = stack[-4];
    goto v_34204;
v_34206:
    v_34394 = nil;
    goto v_34204;
    v_34394 = nil;
v_34204:
    goto v_34192;
v_34194:
    v_34394 = nil;
    goto v_34192;
    v_34394 = nil;
v_34192:
    if (v_34394 == nil) goto v_34190;
    goto v_34188;
v_34190:
    goto v_34244;
v_34240:
    v_34395 = stack[-1];
    goto v_34241;
v_34242:
    v_34394 = elt(env, 4); // i
    goto v_34243;
v_34244:
    goto v_34240;
v_34241:
    goto v_34242;
v_34243:
    if (v_34395 == v_34394) goto v_34238;
    else goto v_34239;
v_34238:
    v_34394 = lisp_true;
    goto v_34237;
v_34239:
    goto v_34263;
v_34259:
    v_34395 = stack[-1];
    goto v_34260;
v_34261:
    v_34394 = elt(env, 2); // expt
    goto v_34262;
v_34263:
    goto v_34259;
v_34260:
    goto v_34261;
v_34262:
    if (!consp(v_34395)) goto v_34257;
    v_34395 = qcar(v_34395);
    if (v_34395 == v_34394) goto v_34256;
    else goto v_34257;
v_34256:
    goto v_34270;
v_34266:
    v_34394 = stack[-1];
    v_34394 = qcdr(v_34394);
    v_34394 = qcdr(v_34394);
    v_34395 = qcar(v_34394);
    goto v_34267;
v_34268:
    v_34394 = elt(env, 5); // (quotient 1 2)
    goto v_34269;
v_34270:
    goto v_34266;
v_34267:
    goto v_34268;
v_34269:
    v_34394 = (equal(v_34395, v_34394) ? lisp_true : nil);
    goto v_34255;
v_34257:
    v_34394 = nil;
    goto v_34255;
    v_34394 = nil;
v_34255:
    if (v_34394 == nil) goto v_34253;
    v_34394 = lisp_true;
    goto v_34251;
v_34253:
    goto v_34288;
v_34284:
    v_34395 = stack[-1];
    goto v_34285;
v_34286:
    v_34394 = elt(env, 6); // sqrt
    goto v_34287;
v_34288:
    goto v_34284;
v_34285:
    goto v_34286;
v_34287:
    v_34394 = Leqcar(nil, v_34395, v_34394);
    env = stack[-4];
    goto v_34251;
    v_34394 = nil;
v_34251:
    goto v_34237;
    v_34394 = nil;
v_34237:
    if (v_34394 == nil) goto v_34235;
    goto v_34296;
v_34292:
    goto v_34302;
v_34298:
    v_34395 = stack[-2];
    goto v_34299;
v_34300:
    v_34394 = stack[-1];
    goto v_34301;
v_34302:
    goto v_34298;
v_34299:
    goto v_34300;
v_34301:
    fn = elt(env, 11); // mkmain
    v_34395 = (*qfn2(fn))(fn, v_34395, v_34394);
    env = stack[-4];
    goto v_34293;
v_34294:
    v_34394 = stack[-1];
    goto v_34295;
v_34296:
    goto v_34292;
v_34293:
    goto v_34294;
v_34295:
    {
        fn = elt(env, 12); // conjquadratic
        return (*qfn2(fn))(fn, v_34395, v_34394);
    }
v_34235:
    goto v_34317;
v_34313:
    v_34395 = stack[-1];
    goto v_34314;
v_34315:
    v_34394 = elt(env, 2); // expt
    goto v_34316;
v_34317:
    goto v_34313;
v_34314:
    goto v_34315;
v_34316:
    if (!consp(v_34395)) goto v_34311;
    v_34395 = qcar(v_34395);
    if (v_34395 == v_34394) goto v_34310;
    else goto v_34311;
v_34310:
    goto v_34324;
v_34320:
    v_34394 = stack[-1];
    v_34394 = qcdr(v_34394);
    v_34394 = qcdr(v_34394);
    v_34395 = qcar(v_34394);
    goto v_34321;
v_34322:
    v_34394 = elt(env, 7); // (quotient 1 3)
    goto v_34323;
v_34324:
    goto v_34320;
v_34321:
    goto v_34322;
v_34323:
    v_34394 = (equal(v_34395, v_34394) ? lisp_true : nil);
    goto v_34309;
v_34311:
    v_34394 = nil;
    goto v_34309;
    v_34394 = nil;
v_34309:
    if (v_34394 == nil) goto v_34307;
    goto v_34339;
v_34335:
    goto v_34345;
v_34341:
    v_34395 = stack[-2];
    goto v_34342;
v_34343:
    v_34394 = stack[-1];
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    fn = elt(env, 11); // mkmain
    v_34395 = (*qfn2(fn))(fn, v_34395, v_34394);
    env = stack[-4];
    goto v_34336;
v_34337:
    v_34394 = stack[-1];
    goto v_34338;
v_34339:
    goto v_34335;
v_34336:
    goto v_34337;
v_34338:
    {
        fn = elt(env, 13); // conjcubic
        return (*qfn2(fn))(fn, v_34395, v_34394);
    }
v_34307:
    goto v_34360;
v_34356:
    v_34395 = stack[-1];
    goto v_34357;
v_34358:
    v_34394 = elt(env, 2); // expt
    goto v_34359;
v_34360:
    goto v_34356;
v_34357:
    goto v_34358;
v_34359:
    if (!consp(v_34395)) goto v_34354;
    v_34395 = qcar(v_34395);
    if (v_34395 == v_34394) goto v_34353;
    else goto v_34354;
v_34353:
    goto v_34367;
v_34363:
    v_34394 = stack[-1];
    v_34394 = qcdr(v_34394);
    v_34394 = qcdr(v_34394);
    v_34395 = qcar(v_34394);
    goto v_34364;
v_34365:
    v_34394 = elt(env, 8); // (quotient 1 4)
    goto v_34366;
v_34367:
    goto v_34363;
v_34364:
    goto v_34365;
v_34366:
    v_34394 = (equal(v_34395, v_34394) ? lisp_true : nil);
    goto v_34352;
v_34354:
    v_34394 = nil;
    goto v_34352;
    v_34394 = nil;
v_34352:
    if (v_34394 == nil) goto v_34350;
    goto v_34382;
v_34378:
    goto v_34388;
v_34384:
    v_34395 = stack[-2];
    goto v_34385;
v_34386:
    v_34394 = stack[-1];
    goto v_34387;
v_34388:
    goto v_34384;
v_34385:
    goto v_34386;
v_34387:
    fn = elt(env, 11); // mkmain
    v_34395 = (*qfn2(fn))(fn, v_34395, v_34394);
    env = stack[-4];
    goto v_34379;
v_34380:
    v_34394 = stack[-1];
    goto v_34381;
v_34382:
    goto v_34378;
v_34379:
    goto v_34380;
v_34381:
    {
        fn = elt(env, 14); // conjquartic
        return (*qfn2(fn))(fn, v_34395, v_34394);
    }
v_34350:
v_34188:
    v_34394 = stack[-3];
    v_34394 = qcdr(v_34394);
    stack[-3] = v_34394;
    goto v_34175;
v_34174:
    return onevalue(v_34394);
}



// Code for red_extract

static LispObject CC_red_extract(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34208, v_34209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_34168;
// end of prologue
    goto v_34175;
v_34171:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34172;
v_34173:
    v_34208 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_34208 = (*qfn1(fn))(fn, v_34208);
    env = stack[-4];
    goto v_34174;
v_34175:
    goto v_34171;
v_34172:
    goto v_34173;
v_34174:
    fn = elt(env, 2); // dp_comp
    v_34208 = (*qfn2(fn))(fn, stack[0], v_34208);
    env = stack[-4];
    stack[-3] = v_34208;
    goto v_34185;
v_34181:
    goto v_34193;
v_34187:
    v_34208 = stack[-2];
    fn = elt(env, 3); // bas_nr
    stack[-1] = (*qfn1(fn))(fn, v_34208);
    env = stack[-4];
    goto v_34188;
v_34189:
    v_34208 = stack[-2];
    fn = elt(env, 4); // bas_dpoly
    stack[0] = (*qfn1(fn))(fn, v_34208);
    env = stack[-4];
    goto v_34190;
v_34191:
    goto v_34203;
v_34199:
    v_34208 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_34209 = (*qfn1(fn))(fn, v_34208);
    env = stack[-4];
    goto v_34200;
v_34201:
    v_34208 = stack[-3];
    goto v_34202;
v_34203:
    goto v_34199;
v_34200:
    goto v_34201;
v_34202:
    fn = elt(env, 5); // dp_diff
    v_34208 = (*qfn2(fn))(fn, v_34209, v_34208);
    env = stack[-4];
    goto v_34192;
v_34193:
    goto v_34187;
v_34188:
    goto v_34189;
v_34190:
    goto v_34191;
v_34192:
    fn = elt(env, 6); // bas_make1
    v_34209 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34208);
    goto v_34182;
v_34183:
    v_34208 = stack[-3];
    goto v_34184;
v_34185:
    goto v_34181;
v_34182:
    goto v_34183;
v_34184:
    return cons(v_34209, v_34208);
}



// Code for lowestdeg

static LispObject CC_lowestdeg(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34264, v_34265;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_34169;
    v_34264 = v_34168;
// end of prologue
    fn = elt(env, 4); // simp!*
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[-1] = v_34264;
    v_34264 = stack[-1];
    if (!consp(v_34264)) goto v_34186;
    else goto v_34187;
v_34186:
    v_34264 = lisp_true;
    goto v_34185;
v_34187:
    v_34264 = stack[-1];
    v_34264 = qcar(v_34264);
    v_34264 = (consp(v_34264) ? nil : lisp_true);
    goto v_34185;
    v_34264 = nil;
v_34185:
    if (v_34264 == nil) goto v_34183;
    v_34264 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34176;
v_34183:
    v_34264 = stack[-1];
    fn = elt(env, 5); // !*q2f
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[-1] = v_34264;
    v_34264 = stack[-1];
    fn = elt(env, 6); // erase_pol_cst
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[0] = v_34264;
    goto v_34208;
v_34204:
    v_34265 = stack[0];
    goto v_34205;
v_34206:
    v_34264 = stack[-1];
    goto v_34207;
v_34208:
    goto v_34204;
v_34205:
    goto v_34206;
v_34207:
    if (equal(v_34265, v_34264)) goto v_34203;
    v_34264 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34176;
v_34203:
    v_34264 = stack[-2];
    fn = elt(env, 7); // !*a2k
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[0] = v_34264;
    v_34264 = stack[-2];
    v_34264 = ncons(v_34264);
    env = stack[-4];
    fn = elt(env, 8); // setkorder
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[-3] = v_34264;
    v_34264 = stack[-1];
    fn = elt(env, 9); // reorder
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    stack[-2] = v_34264;
    v_34264 = stack[-3];
    fn = elt(env, 8); // setkorder
    v_34264 = (*qfn1(fn))(fn, v_34264);
    env = stack[-4];
    v_34264 = stack[-2];
    v_34264 = Lreverse(nil, v_34264);
    env = stack[-4];
    stack[-2] = v_34264;
    v_34264 = stack[-2];
    v_34264 = qcar(v_34264);
    v_34264 = qcar(v_34264);
    v_34264 = qcar(v_34264);
    stack[-1] = v_34264;
    v_34264 = stack[-1];
    if (!consp(v_34264)) goto v_34230;
    goto v_34240;
v_34236:
    v_34264 = stack[-1];
    v_34265 = qcar(v_34264);
    goto v_34237;
v_34238:
    v_34264 = elt(env, 2); // expt
    goto v_34239;
v_34240:
    goto v_34236;
v_34237:
    goto v_34238;
v_34239:
    if (v_34265 == v_34264) goto v_34234;
    else goto v_34235;
v_34234:
    v_34264 = elt(env, 3); // "exponents must be integers"
    fn = elt(env, 10); // rederr
    v_34264 = (*qfn1(fn))(fn, v_34264);
    goto v_34233;
v_34235:
v_34233:
    goto v_34228;
v_34230:
v_34228:
    goto v_34254;
v_34250:
    v_34265 = stack[-1];
    goto v_34251;
v_34252:
    v_34264 = stack[0];
    goto v_34253;
v_34254:
    goto v_34250;
v_34251:
    goto v_34252;
v_34253:
    if (equal(v_34265, v_34264)) goto v_34249;
    v_34264 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34176;
v_34249:
    v_34264 = stack[-2];
    v_34264 = qcar(v_34264);
    v_34264 = qcar(v_34264);
    v_34264 = qcdr(v_34264);
    goto v_34176;
    v_34264 = nil;
v_34176:
    return onevalue(v_34264);
}



// Code for radd

static LispObject CC_radd(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34299, v_34300;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_34169;
    stack[-1] = v_34168;
// end of prologue
    stack[-2] = nil;
    v_34299 = stack[-1];
    if (!consp(v_34299)) goto v_34180;
    goto v_34187;
v_34183:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34184;
v_34185:
    v_34299 = stack[-1];
    fn = elt(env, 4); // prepf
    v_34299 = (*qfn1(fn))(fn, v_34299);
    goto v_34186;
v_34187:
    goto v_34183;
v_34184:
    goto v_34185;
v_34186:
    {
        LispObject v_34304 = stack[0];
        return list2(v_34304, v_34299);
    }
v_34180:
    goto v_34201;
v_34197:
    v_34300 = stack[-1];
    goto v_34198;
v_34199:
    v_34299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34200;
v_34201:
    goto v_34197;
v_34198:
    goto v_34199;
v_34200:
    v_34299 = (LispObject)lessp2(v_34300, v_34299);
    v_34299 = v_34299 ? lisp_true : nil;
    env = stack[-3];
    if (v_34299 == nil) goto v_34194;
    v_34299 = stack[0];
    v_34299 = Levenp(nil, v_34299);
    env = stack[-3];
    if (v_34299 == nil) goto v_34194;
    v_34299 = lisp_true;
    stack[-2] = v_34299;
    v_34299 = stack[-1];
    v_34299 = negate(v_34299);
    env = stack[-3];
    stack[-1] = v_34299;
    goto v_34192;
v_34194:
v_34192:
    goto v_34215;
v_34211:
    v_34300 = stack[-1];
    goto v_34212;
v_34213:
    v_34299 = stack[0];
    goto v_34214;
v_34215:
    goto v_34211;
v_34212:
    goto v_34213;
v_34214:
    fn = elt(env, 5); // nrootnn
    v_34299 = (*qfn2(fn))(fn, v_34300, v_34299);
    env = stack[-3];
    stack[-1] = v_34299;
    v_34299 = stack[-2];
    if (v_34299 == nil) goto v_34221;
    v_34299 = qvalue(elt(env, 2)); // !*reduced
    if (v_34299 == nil) goto v_34226;
    goto v_34234;
v_34230:
    v_34300 = stack[0];
    goto v_34231;
v_34232:
    v_34299 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_34233;
v_34234:
    goto v_34230;
v_34231:
    goto v_34232;
v_34233:
    if (v_34300 == v_34299) goto v_34229;
    else goto v_34226;
v_34229:
    goto v_34242;
v_34238:
    v_34299 = stack[-1];
    stack[0] = qcar(v_34299);
    goto v_34239;
v_34240:
    goto v_34251;
v_34247:
    goto v_34257;
v_34253:
    v_34300 = elt(env, 3); // i
    goto v_34254;
v_34255:
    v_34299 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34256;
v_34257:
    goto v_34253;
v_34254:
    goto v_34255;
v_34256:
    fn = elt(env, 6); // to
    v_34300 = (*qfn2(fn))(fn, v_34300, v_34299);
    env = stack[-3];
    goto v_34248;
v_34249:
    v_34299 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34250;
v_34251:
    goto v_34247;
v_34248:
    goto v_34249;
v_34250:
    v_34299 = cons(v_34300, v_34299);
    env = stack[-3];
    v_34299 = ncons(v_34299);
    env = stack[-3];
    goto v_34241;
v_34242:
    goto v_34238;
v_34239:
    goto v_34240;
v_34241:
    fn = elt(env, 7); // multd
    v_34299 = (*qfn2(fn))(fn, stack[0], v_34299);
    stack[0] = v_34299;
    v_34299 = stack[-1];
    v_34299 = qcdr(v_34299);
    stack[-1] = v_34299;
    goto v_34224;
v_34226:
    v_34299 = stack[-1];
    v_34299 = qcar(v_34299);
    stack[0] = v_34299;
    v_34299 = stack[-1];
    v_34299 = qcdr(v_34299);
    v_34299 = negate(v_34299);
    stack[-1] = v_34299;
    goto v_34224;
v_34224:
    goto v_34219;
v_34221:
    v_34299 = stack[-1];
    v_34299 = qcar(v_34299);
    stack[0] = v_34299;
    v_34299 = stack[-1];
    v_34299 = qcdr(v_34299);
    stack[-1] = v_34299;
    goto v_34219;
v_34219:
    goto v_34284;
v_34280:
    v_34300 = stack[-1];
    goto v_34281;
v_34282:
    v_34299 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34283;
v_34284:
    goto v_34280;
v_34281:
    goto v_34282;
v_34283:
    if (v_34300 == v_34299) goto v_34278;
    else goto v_34279;
v_34278:
    v_34299 = stack[0];
    return ncons(v_34299);
v_34279:
    goto v_34296;
v_34292:
    v_34300 = stack[0];
    goto v_34293;
v_34294:
    v_34299 = stack[-1];
    goto v_34295;
v_34296:
    goto v_34292;
v_34293:
    goto v_34294;
v_34295:
    return list2(v_34300, v_34299);
    v_34299 = nil;
    return onevalue(v_34299);
}



// Code for no_of_tm_sf

static LispObject CC_no_of_tm_sf(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34207;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
    v_34207 = stack[0];
    if (v_34207 == nil) goto v_34172;
    else goto v_34173;
v_34172:
    v_34207 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34171;
v_34173:
    v_34207 = stack[0];
    v_34207 = Lconsp(nil, v_34207);
    env = stack[-2];
    if (v_34207 == nil) goto v_34180;
    else goto v_34181;
v_34180:
    v_34207 = lisp_true;
    goto v_34179;
v_34181:
    v_34207 = stack[0];
    v_34207 = qcar(v_34207);
    v_34207 = Lconsp(nil, v_34207);
    env = stack[-2];
    v_34207 = (v_34207 == nil ? lisp_true : nil);
    goto v_34179;
    v_34207 = nil;
v_34179:
    if (v_34207 == nil) goto v_34177;
    v_34207 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34171;
v_34177:
    goto v_34199;
v_34195:
    v_34207 = stack[0];
    v_34207 = qcar(v_34207);
    v_34207 = qcdr(v_34207);
    stack[-1] = CC_no_of_tm_sf(elt(env, 0), v_34207);
    env = stack[-2];
    goto v_34196;
v_34197:
    v_34207 = stack[0];
    v_34207 = qcdr(v_34207);
    v_34207 = CC_no_of_tm_sf(elt(env, 0), v_34207);
    goto v_34198;
v_34199:
    goto v_34195;
v_34196:
    goto v_34197;
v_34198:
    {
        LispObject v_34210 = stack[-1];
        return plus2(v_34210, v_34207);
    }
    v_34207 = nil;
v_34171:
    return onevalue(v_34207);
}



// Code for add!-to!-sorted!-tree

static LispObject CC_addKtoKsortedKtree(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34277, v_34278, v_34279;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_34169;
    stack[-1] = v_34168;
// end of prologue
    stack[-2] = nil;
v_34174:
    v_34277 = stack[0];
    if (v_34277 == nil) goto v_34177;
    else goto v_34178;
v_34177:
    goto v_34185;
v_34181:
    stack[0] = stack[-2];
    goto v_34182;
v_34183:
    goto v_34194;
v_34188:
    v_34279 = nil;
    goto v_34189;
v_34190:
    v_34278 = stack[-1];
    goto v_34191;
v_34192:
    v_34277 = nil;
    goto v_34193;
v_34194:
    goto v_34188;
v_34189:
    goto v_34190;
v_34191:
    goto v_34192;
v_34193:
    v_34277 = list2star(v_34279, v_34278, v_34277);
    env = stack[-3];
    goto v_34184;
v_34185:
    goto v_34181;
v_34182:
    goto v_34183;
v_34184:
    {
        LispObject v_34283 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34283, v_34277);
    }
v_34178:
    goto v_34204;
v_34200:
    v_34278 = stack[-1];
    goto v_34201;
v_34202:
    v_34277 = stack[0];
    v_34277 = qcdr(v_34277);
    v_34277 = qcar(v_34277);
    goto v_34203;
v_34204:
    goto v_34200;
v_34201:
    goto v_34202;
v_34203:
    if (equal(v_34278, v_34277)) goto v_34198;
    else goto v_34199;
v_34198:
    goto v_34214;
v_34210:
    v_34278 = stack[-2];
    goto v_34211;
v_34212:
    v_34277 = stack[0];
    goto v_34213;
v_34214:
    goto v_34210;
v_34211:
    goto v_34212;
v_34213:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34278, v_34277);
    }
v_34199:
    goto v_34224;
v_34220:
    v_34278 = stack[-1];
    goto v_34221;
v_34222:
    v_34277 = stack[0];
    v_34277 = qcdr(v_34277);
    v_34277 = qcar(v_34277);
    goto v_34223;
v_34224:
    goto v_34220;
v_34221:
    goto v_34222;
v_34223:
    v_34277 = Lorderp(nil, v_34278, v_34277);
    env = stack[-3];
    if (v_34277 == nil) goto v_34218;
    goto v_34234;
v_34230:
    goto v_34231;
v_34232:
    goto v_34241;
v_34237:
    goto v_34247;
v_34243:
    v_34278 = stack[-1];
    goto v_34244;
v_34245:
    v_34277 = stack[0];
    v_34277 = qcar(v_34277);
    goto v_34246;
v_34247:
    goto v_34243;
v_34244:
    goto v_34245;
v_34246:
    v_34278 = CC_addKtoKsortedKtree(elt(env, 0), v_34278, v_34277);
    env = stack[-3];
    goto v_34238;
v_34239:
    v_34277 = stack[0];
    v_34277 = qcdr(v_34277);
    goto v_34240;
v_34241:
    goto v_34237;
v_34238:
    goto v_34239;
v_34240:
    v_34277 = cons(v_34278, v_34277);
    env = stack[-3];
    goto v_34233;
v_34234:
    goto v_34230;
v_34231:
    goto v_34232;
v_34233:
    {
        LispObject v_34284 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34284, v_34277);
    }
v_34218:
    goto v_34260;
v_34256:
    v_34277 = stack[0];
    v_34278 = qcar(v_34277);
    goto v_34257;
v_34258:
    v_34277 = stack[-2];
    goto v_34259;
v_34260:
    goto v_34256;
v_34257:
    goto v_34258;
v_34259:
    v_34277 = cons(v_34278, v_34277);
    env = stack[-3];
    stack[-2] = v_34277;
    goto v_34269;
v_34265:
    v_34277 = stack[0];
    v_34277 = qcdr(v_34277);
    v_34278 = qcar(v_34277);
    goto v_34266;
v_34267:
    v_34277 = stack[-2];
    goto v_34268;
v_34269:
    goto v_34265;
v_34266:
    goto v_34267;
v_34268:
    v_34277 = cons(v_34278, v_34277);
    env = stack[-3];
    stack[-2] = v_34277;
    v_34277 = stack[0];
    v_34277 = qcdr(v_34277);
    v_34277 = qcdr(v_34277);
    stack[0] = v_34277;
    goto v_34174;
    v_34277 = nil;
    return onevalue(v_34277);
}



// Code for giminusp!:

static LispObject CC_giminuspT(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34193, v_34194, v_34195;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34194 = v_34168;
// end of prologue
    goto v_34178;
v_34174:
    v_34193 = v_34194;
    v_34193 = qcdr(v_34193);
    v_34195 = qcar(v_34193);
    goto v_34175;
v_34176:
    v_34193 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34177;
v_34178:
    goto v_34174;
v_34175:
    goto v_34176;
v_34177:
    if (v_34195 == v_34193) goto v_34172;
    else goto v_34173;
v_34172:
    v_34193 = v_34194;
    v_34193 = qcdr(v_34193);
    v_34193 = qcdr(v_34193);
        return Lminusp(nil, v_34193);
v_34173:
    v_34193 = v_34194;
    v_34193 = qcdr(v_34193);
    v_34193 = qcar(v_34193);
        return Lminusp(nil, v_34193);
    v_34193 = nil;
    return onevalue(v_34193);
}



// Code for uterm

static LispObject CC_uterm(LispObject env,
                         LispObject v_34169, LispObject v_34170)
{
    env = qenv(env);
    LispObject v_34259, v_34260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34170,v_34169);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_34259 = v_34170;
    stack[-1] = v_34169;
// end of prologue
// Binding rhs!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_34259; // rhs!*
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    if (v_34259 == nil) goto v_34178;
    else goto v_34179;
v_34178:
    v_34259 = nil;
    goto v_34177;
v_34179:
    goto v_34194;
v_34190:
    v_34260 = stack[-1];
    goto v_34191;
v_34192:
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    v_34259 = qcar(v_34259);
    v_34259 = qcar(v_34259);
    goto v_34193;
v_34194:
    goto v_34190;
v_34191:
    goto v_34192;
v_34193:
    fn = elt(env, 3); // addinds
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-3];
    stack[0] = v_34259;
    goto v_34204;
v_34200:
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    v_34259 = qcar(v_34259);
    v_34259 = qcdr(v_34259);
    v_34260 = qcar(v_34259);
    goto v_34201;
v_34202:
    v_34259 = stack[-1];
    goto v_34203;
v_34204:
    goto v_34200;
v_34201:
    goto v_34202;
v_34203:
    fn = elt(env, 4); // evaluatecoeffts
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-3];
    v_34260 = v_34259;
    if (v_34260 == nil) goto v_34212;
    else goto v_34213;
v_34212:
    goto v_34220;
v_34216:
    v_34260 = stack[-1];
    goto v_34217;
v_34218:
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    v_34259 = qcdr(v_34259);
    goto v_34219;
v_34220:
    goto v_34216;
v_34217:
    goto v_34218;
v_34219:
    v_34259 = CC_uterm(elt(env, 0), v_34260, v_34259);
    goto v_34187;
v_34213:
    goto v_34229;
v_34225:
    v_34260 = v_34259;
    goto v_34226;
v_34227:
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    v_34259 = qcar(v_34259);
    v_34259 = qcdr(v_34259);
    v_34259 = qcdr(v_34259);
    goto v_34228;
v_34229:
    goto v_34225;
v_34226:
    goto v_34227;
v_34228:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-3];
    goto v_34240;
v_34236:
    goto v_34247;
v_34243:
    v_34260 = stack[0];
    goto v_34244;
v_34245:
    goto v_34246;
v_34247:
    goto v_34243;
v_34244:
    goto v_34245;
v_34246:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-3];
    stack[0] = ncons(v_34259);
    env = stack[-3];
    goto v_34237;
v_34238:
    goto v_34255;
v_34251:
    v_34260 = stack[-1];
    goto v_34252;
v_34253:
    v_34259 = qvalue(elt(env, 1)); // rhs!*
    v_34259 = qcdr(v_34259);
    goto v_34254;
v_34255:
    goto v_34251;
v_34252:
    goto v_34253;
v_34254:
    v_34259 = CC_uterm(elt(env, 0), v_34260, v_34259);
    env = stack[-3];
    goto v_34239;
v_34240:
    goto v_34236;
v_34237:
    goto v_34238;
v_34239:
    fn = elt(env, 5); // plusdf
    v_34259 = (*qfn2(fn))(fn, stack[0], v_34259);
v_34187:
    goto v_34177;
    v_34259 = nil;
v_34177:
    ;}  // end of a binding scope
    return onevalue(v_34259);
}



// Code for get!*nr!*real!*irred!*reps

static LispObject CC_getHnrHrealHirredHreps(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34181, v_34182;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34181 = v_34168;
// end of prologue
    goto v_34178;
v_34174:
    goto v_34175;
v_34176:
    v_34182 = elt(env, 1); // realrepnumber
    goto v_34177;
v_34178:
    goto v_34174;
v_34175:
    goto v_34176;
v_34177:
    return get(v_34181, v_34182);
    return onevalue(v_34181);
}



// Code for dip_comp1

static LispObject CC_dip_comp1(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34181;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34169;
    v_34181 = v_34168;
// end of prologue
    goto v_34176;
v_34172:
    fn = elt(env, 1); // dip_evlmon
    stack[-1] = (*qfn1(fn))(fn, v_34181);
    env = stack[-2];
    goto v_34173;
v_34174:
    v_34181 = stack[0];
    fn = elt(env, 1); // dip_evlmon
    v_34181 = (*qfn1(fn))(fn, v_34181);
    env = stack[-2];
    goto v_34175;
v_34176:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
    {
        LispObject v_34184 = stack[-1];
        fn = elt(env, 2); // ev_comp
        return (*qfn2(fn))(fn, v_34184, v_34181);
    }
}



// Code for search4facf

static LispObject CC_search4facf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34229, v_34230;
    LispObject fn;
    LispObject v_34170, v_34169, v_34168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "search4facf");
    va_start(aa, nargs);
    v_34168 = va_arg(aa, LispObject);
    v_34169 = va_arg(aa, LispObject);
    v_34170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34170,v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34168,v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_34170;
    stack[-3] = v_34169;
    stack[-4] = v_34168;
// end of prologue
    v_34229 = stack[-3];
    if (v_34229 == nil) goto v_34174;
    else goto v_34175;
v_34174:
    goto v_34182;
v_34178:
    v_34230 = stack[-4];
    goto v_34179;
v_34180:
    v_34229 = stack[-2];
    goto v_34181;
v_34182:
    goto v_34178;
v_34179:
    goto v_34180;
v_34181:
    {
        fn = elt(env, 2); // tryfactorf
        return (*qfn2(fn))(fn, v_34230, v_34229);
    }
v_34175:
    v_34229 = stack[-3];
    v_34229 = qcar(v_34229);
    stack[-5] = v_34229;
v_34191:
    v_34229 = stack[-5];
    if (v_34229 == nil) goto v_34197;
    else goto v_34198;
v_34197:
    v_34229 = nil;
    goto v_34190;
v_34198:
    goto v_34208;
v_34202:
    stack[-1] = stack[-4];
    goto v_34203;
v_34204:
    v_34229 = stack[-3];
    stack[0] = qcdr(v_34229);
    goto v_34205;
v_34206:
    goto v_34217;
v_34213:
    v_34229 = stack[-5];
    v_34230 = qcar(v_34229);
    goto v_34214;
v_34215:
    v_34229 = stack[-2];
    goto v_34216;
v_34217:
    goto v_34213;
v_34214:
    goto v_34215;
v_34216:
    v_34229 = cons(v_34230, v_34229);
    env = stack[-6];
    goto v_34207;
v_34208:
    goto v_34202;
v_34203:
    goto v_34204;
v_34205:
    goto v_34206;
v_34207:
    v_34229 = CC_search4facf(elt(env, 0), 3, stack[-1], stack[0], v_34229);
    env = stack[-6];
    v_34230 = v_34229;
    v_34229 = v_34230;
    if (v_34229 == nil) goto v_34223;
    else goto v_34224;
v_34223:
    v_34229 = stack[-5];
    v_34229 = qcdr(v_34229);
    stack[-5] = v_34229;
    goto v_34191;
v_34224:
    v_34229 = v_34230;
v_34190:
    goto v_34173;
    v_34229 = nil;
v_34173:
    return onevalue(v_34229);
}



// Code for subsubf

static LispObject CC_subsubf(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34412, v_34413;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_34169;
    stack[-6] = v_34168;
// end of prologue
    stack[-4] = nil;
    v_34412 = stack[-5];
    v_34412 = qcdr(v_34412);
    v_34412 = qcdr(v_34412);
    stack[0] = v_34412;
v_34179:
    v_34412 = stack[0];
    if (v_34412 == nil) goto v_34185;
    else goto v_34186;
v_34185:
    goto v_34178;
v_34186:
    v_34412 = stack[0];
    v_34412 = qcar(v_34412);
    goto v_34200;
v_34196:
    v_34413 = v_34412;
    goto v_34197;
v_34198:
    v_34412 = stack[-6];
    goto v_34199;
v_34200:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    v_34412 = Lassoc(nil, v_34413, v_34412);
    stack[-1] = v_34412;
    if (v_34412 == nil) goto v_34195;
    goto v_34209;
v_34205:
    v_34413 = stack[-1];
    goto v_34206;
v_34207:
    v_34412 = stack[-4];
    goto v_34208;
v_34209:
    goto v_34205;
v_34206:
    goto v_34207;
v_34208:
    v_34412 = cons(v_34413, v_34412);
    env = stack[-8];
    stack[-4] = v_34412;
    goto v_34217;
v_34213:
    v_34413 = stack[-1];
    goto v_34214;
v_34215:
    v_34412 = stack[-6];
    goto v_34216;
v_34217:
    goto v_34213;
v_34214:
    goto v_34215;
v_34216:
    v_34412 = Ldelete(nil, v_34413, v_34412);
    env = stack[-8];
    stack[-6] = v_34412;
    goto v_34193;
v_34195:
v_34193:
    v_34412 = stack[0];
    v_34412 = qcdr(v_34412);
    stack[0] = v_34412;
    goto v_34179;
v_34178:
    goto v_34227;
v_34223:
    goto v_34233;
v_34229:
    v_34413 = stack[-6];
    goto v_34230;
v_34231:
    v_34412 = stack[-5];
    v_34412 = qcar(v_34412);
    goto v_34232;
v_34233:
    goto v_34229;
v_34230:
    goto v_34231;
v_34232:
    stack[-3] = Lsublis(nil, v_34413, v_34412);
    env = stack[-8];
    goto v_34224;
v_34225:
    v_34412 = stack[-5];
    v_34412 = qcdr(v_34412);
    stack[-5] = v_34412;
    v_34412 = stack[-5];
    if (v_34412 == nil) goto v_34247;
    else goto v_34248;
v_34247:
    v_34412 = nil;
    goto v_34241;
v_34248:
    v_34412 = stack[-5];
    v_34412 = qcar(v_34412);
    goto v_34260;
v_34256:
    v_34413 = stack[-6];
    goto v_34257;
v_34258:
    goto v_34259;
v_34260:
    goto v_34256;
v_34257:
    goto v_34258;
v_34259:
    fn = elt(env, 4); // subsublis
    v_34412 = (*qfn2(fn))(fn, v_34413, v_34412);
    env = stack[-8];
    v_34412 = ncons(v_34412);
    env = stack[-8];
    stack[-1] = v_34412;
    stack[-2] = v_34412;
v_34242:
    v_34412 = stack[-5];
    v_34412 = qcdr(v_34412);
    stack[-5] = v_34412;
    v_34412 = stack[-5];
    if (v_34412 == nil) goto v_34267;
    else goto v_34268;
v_34267:
    v_34412 = stack[-2];
    goto v_34241;
v_34268:
    goto v_34276;
v_34272:
    stack[0] = stack[-1];
    goto v_34273;
v_34274:
    v_34412 = stack[-5];
    v_34412 = qcar(v_34412);
    goto v_34287;
v_34283:
    v_34413 = stack[-6];
    goto v_34284;
v_34285:
    goto v_34286;
v_34287:
    goto v_34283;
v_34284:
    goto v_34285;
v_34286:
    fn = elt(env, 4); // subsublis
    v_34412 = (*qfn2(fn))(fn, v_34413, v_34412);
    env = stack[-8];
    v_34412 = ncons(v_34412);
    env = stack[-8];
    goto v_34275;
v_34276:
    goto v_34272;
v_34273:
    goto v_34274;
v_34275:
    v_34412 = Lrplacd(nil, stack[0], v_34412);
    env = stack[-8];
    v_34412 = stack[-1];
    v_34412 = qcdr(v_34412);
    stack[-1] = v_34412;
    goto v_34242;
v_34241:
    goto v_34226;
v_34227:
    goto v_34223;
v_34224:
    goto v_34225;
v_34226:
    v_34412 = cons(stack[-3], v_34412);
    env = stack[-8];
    stack[-5] = v_34412;
    v_34412 = stack[-4];
    if (v_34412 == nil) goto v_34294;
    else goto v_34295;
v_34294:
    v_34412 = stack[-5];
    goto v_34174;
v_34295:
    goto v_34303;
v_34299:
    v_34412 = stack[-4];
    fn = elt(env, 5); // reversip!*
    v_34412 = (*qfn1(fn))(fn, v_34412);
    env = stack[-8];
    stack[-7] = v_34412;
    v_34412 = stack[-7];
    if (v_34412 == nil) goto v_34314;
    else goto v_34315;
v_34314:
    v_34412 = nil;
    v_34413 = v_34412;
    goto v_34308;
v_34315:
    v_34412 = stack[-7];
    v_34412 = qcar(v_34412);
    v_34413 = v_34412;
    goto v_34329;
v_34323:
    stack[-1] = elt(env, 2); // equal
    goto v_34324;
v_34325:
    v_34412 = v_34413;
    stack[0] = qcar(v_34412);
    goto v_34326;
v_34327:
    v_34412 = v_34413;
    v_34412 = qcdr(v_34412);
    fn = elt(env, 6); // aeval
    v_34412 = (*qfn1(fn))(fn, v_34412);
    env = stack[-8];
    goto v_34328;
v_34329:
    goto v_34323;
v_34324:
    goto v_34325;
v_34326:
    goto v_34327;
v_34328:
    v_34412 = list3(stack[-1], stack[0], v_34412);
    env = stack[-8];
    v_34412 = ncons(v_34412);
    env = stack[-8];
    stack[-3] = v_34412;
    stack[-4] = v_34412;
v_34309:
    v_34412 = stack[-7];
    v_34412 = qcdr(v_34412);
    stack[-7] = v_34412;
    v_34412 = stack[-7];
    if (v_34412 == nil) goto v_34340;
    else goto v_34341;
v_34340:
    v_34412 = stack[-4];
    v_34413 = v_34412;
    goto v_34308;
v_34341:
    goto v_34349;
v_34345:
    stack[-2] = stack[-3];
    goto v_34346;
v_34347:
    v_34412 = stack[-7];
    v_34412 = qcar(v_34412);
    v_34413 = v_34412;
    goto v_34362;
v_34356:
    stack[-1] = elt(env, 2); // equal
    goto v_34357;
v_34358:
    v_34412 = v_34413;
    stack[0] = qcar(v_34412);
    goto v_34359;
v_34360:
    v_34412 = v_34413;
    v_34412 = qcdr(v_34412);
    fn = elt(env, 6); // aeval
    v_34412 = (*qfn1(fn))(fn, v_34412);
    env = stack[-8];
    goto v_34361;
v_34362:
    goto v_34356;
v_34357:
    goto v_34358;
v_34359:
    goto v_34360;
v_34361:
    v_34412 = list3(stack[-1], stack[0], v_34412);
    env = stack[-8];
    v_34412 = ncons(v_34412);
    env = stack[-8];
    goto v_34348;
v_34349:
    goto v_34345;
v_34346:
    goto v_34347;
v_34348:
    v_34412 = Lrplacd(nil, stack[-2], v_34412);
    env = stack[-8];
    v_34412 = stack[-3];
    v_34412 = qcdr(v_34412);
    stack[-3] = v_34412;
    goto v_34309;
v_34308:
    goto v_34300;
v_34301:
    v_34412 = stack[-5];
    goto v_34302;
v_34303:
    goto v_34299;
v_34300:
    goto v_34301;
v_34302:
    fn = elt(env, 7); // aconc!*
    v_34412 = (*qfn2(fn))(fn, v_34413, v_34412);
    env = stack[-8];
    stack[-5] = v_34412;
    v_34412 = stack[-6];
    if (v_34412 == nil) goto v_34375;
    v_34412 = stack[-5];
    {
        fn = elt(env, 8); // subeval
        return (*qfn1(fn))(fn, v_34412);
    }
v_34375:
    goto v_34387;
v_34383:
    goto v_34394;
v_34390:
    goto v_34400;
v_34396:
    goto v_34406;
v_34402:
    v_34413 = elt(env, 3); // sub
    goto v_34403;
v_34404:
    v_34412 = stack[-5];
    goto v_34405;
v_34406:
    goto v_34402;
v_34403:
    goto v_34404;
v_34405:
    v_34413 = cons(v_34413, v_34412);
    env = stack[-8];
    goto v_34397;
v_34398:
    v_34412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34399;
v_34400:
    goto v_34396;
v_34397:
    goto v_34398;
v_34399:
    fn = elt(env, 9); // mksp
    v_34413 = (*qfn2(fn))(fn, v_34413, v_34412);
    env = stack[-8];
    goto v_34391;
v_34392:
    v_34412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34393;
v_34394:
    goto v_34390;
v_34391:
    goto v_34392;
v_34393:
    v_34412 = cons(v_34413, v_34412);
    env = stack[-8];
    v_34413 = ncons(v_34412);
    env = stack[-8];
    goto v_34384;
v_34385:
    v_34412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34386;
v_34387:
    goto v_34383;
v_34384:
    goto v_34385;
v_34386:
    v_34412 = cons(v_34413, v_34412);
    env = stack[-8];
    {
        fn = elt(env, 10); // mk!*sq
        return (*qfn1(fn))(fn, v_34412);
    }
    v_34412 = nil;
v_34174:
    return onevalue(v_34412);
}



// Code for row_dim

static LispObject CC_row_dim(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34193;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
    v_34193 = qvalue(elt(env, 1)); // !*fast_la
    if (v_34193 == nil) goto v_34179;
    else goto v_34180;
v_34179:
    v_34193 = stack[0];
    fn = elt(env, 3); // matrixp
    v_34193 = (*qfn1(fn))(fn, v_34193);
    env = stack[-1];
    v_34193 = (v_34193 == nil ? lisp_true : nil);
    goto v_34178;
v_34180:
    v_34193 = nil;
    goto v_34178;
    v_34193 = nil;
v_34178:
    if (v_34193 == nil) goto v_34176;
    v_34193 = elt(env, 2); // "Error in row_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_34193 = (*qfn1(fn))(fn, v_34193);
    env = stack[-1];
    goto v_34174;
v_34176:
v_34174:
    v_34193 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_34193 = (*qfn1(fn))(fn, v_34193);
    v_34193 = qcar(v_34193);
    return onevalue(v_34193);
}



// Code for r2speclist

static LispObject CC_r2speclist(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34230, v_34231, v_34232;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_34231 = v_34168;
// end of prologue
    goto v_34179;
v_34175:
    v_34232 = v_34231;
    goto v_34176;
v_34177:
    v_34230 = elt(env, 1); // plus
    goto v_34178;
v_34179:
    goto v_34175;
v_34176:
    goto v_34177;
v_34178:
    if (!consp(v_34232)) goto v_34173;
    v_34232 = qcar(v_34232);
    if (v_34232 == v_34230) goto v_34172;
    else goto v_34173;
v_34172:
    v_34230 = v_34231;
    v_34230 = qcdr(v_34230);
    goto v_34171;
v_34173:
    v_34230 = v_34231;
    v_34230 = ncons(v_34230);
    env = stack[-4];
    goto v_34171;
    v_34230 = nil;
v_34171:
    v_34231 = v_34230;
    v_34230 = v_34231;
    stack[-3] = v_34230;
    v_34230 = stack[-3];
    if (v_34230 == nil) goto v_34197;
    else goto v_34198;
v_34197:
    v_34230 = nil;
    goto v_34192;
v_34198:
    v_34230 = stack[-3];
    v_34230 = qcar(v_34230);
    fn = elt(env, 2); // r2speclist1
    v_34230 = (*qfn1(fn))(fn, v_34230);
    env = stack[-4];
    v_34230 = ncons(v_34230);
    env = stack[-4];
    stack[-1] = v_34230;
    stack[-2] = v_34230;
v_34193:
    v_34230 = stack[-3];
    v_34230 = qcdr(v_34230);
    stack[-3] = v_34230;
    v_34230 = stack[-3];
    if (v_34230 == nil) goto v_34211;
    else goto v_34212;
v_34211:
    v_34230 = stack[-2];
    goto v_34192;
v_34212:
    goto v_34220;
v_34216:
    stack[0] = stack[-1];
    goto v_34217;
v_34218:
    v_34230 = stack[-3];
    v_34230 = qcar(v_34230);
    fn = elt(env, 2); // r2speclist1
    v_34230 = (*qfn1(fn))(fn, v_34230);
    env = stack[-4];
    v_34230 = ncons(v_34230);
    env = stack[-4];
    goto v_34219;
v_34220:
    goto v_34216;
v_34217:
    goto v_34218;
v_34219:
    v_34230 = Lrplacd(nil, stack[0], v_34230);
    env = stack[-4];
    v_34230 = stack[-1];
    v_34230 = qcdr(v_34230);
    stack[-1] = v_34230;
    goto v_34193;
v_34192:
    return onevalue(v_34230);
}



// Code for all_defined

static LispObject CC_all_defined(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34187, v_34188;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34169;
    v_34187 = v_34168;
// end of prologue
    goto v_34176;
v_34172:
    stack[-1] = v_34187;
    goto v_34173;
v_34174:
    goto v_34183;
v_34179:
    fn = elt(env, 1); // map__edges
    v_34188 = (*qfn1(fn))(fn, v_34187);
    env = stack[-2];
    goto v_34180;
v_34181:
    v_34187 = stack[0];
    goto v_34182;
v_34183:
    goto v_34179;
v_34180:
    goto v_34181;
v_34182:
    fn = elt(env, 2); // defined_append
    v_34187 = (*qfn2(fn))(fn, v_34188, v_34187);
    env = stack[-2];
    goto v_34175;
v_34176:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
    {
        LispObject v_34191 = stack[-1];
        fn = elt(env, 3); // all_defined_map_
        return (*qfn2(fn))(fn, v_34191, v_34187);
    }
}



// Code for simprd

static LispObject CC_simprd(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34182, v_34183;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_34183 = v_34168;
// end of prologue
    v_34182 = v_34183;
    if (!consp(v_34182)) goto v_34172;
    else goto v_34173;
v_34172:
    v_34182 = nil;
    goto v_34171;
v_34173:
    v_34182 = elt(env, 1); // !:rd!:
// Binding dmode!*
// FLUIDBIND: reloadenv=1 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 2, 0);
    qvalue(elt(env, 2)) = v_34182; // dmode!*
    v_34182 = v_34183;
    fn = elt(env, 3); // simplist
    v_34182 = (*qfn1(fn))(fn, v_34182);
    ;}  // end of a binding scope
    goto v_34171;
    v_34182 = nil;
v_34171:
    return onevalue(v_34182);
}



// Code for gak

static LispObject CC_gak(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34266, v_34267, v_34268, v_34269, v_34270;
    LispObject fn;
    LispObject v_34170, v_34169, v_34168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gak");
    va_start(aa, nargs);
    v_34168 = va_arg(aa, LispObject);
    v_34169 = va_arg(aa, LispObject);
    v_34170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34170,v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34168,v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_34267 = v_34170;
    v_34268 = v_34169;
    v_34269 = v_34168;
// end of prologue
v_34167:
    v_34266 = v_34269;
    if (!consp(v_34266)) goto v_34178;
    else goto v_34179;
v_34178:
    v_34266 = lisp_true;
    goto v_34177;
v_34179:
    v_34266 = v_34269;
    v_34266 = qcar(v_34266);
    v_34266 = (consp(v_34266) ? nil : lisp_true);
    goto v_34177;
    v_34266 = nil;
v_34177:
    if (v_34266 == nil) goto v_34175;
    v_34266 = v_34267;
    goto v_34173;
v_34175:
    v_34266 = v_34269;
    v_34266 = qcar(v_34266);
    v_34266 = qcar(v_34266);
    v_34266 = qcar(v_34266);
    v_34270 = v_34266;
    goto v_34202;
v_34196:
    v_34266 = v_34269;
    stack[-3] = qcdr(v_34266);
    goto v_34197;
v_34198:
    stack[-2] = v_34268;
    goto v_34199;
v_34200:
    goto v_34213;
v_34207:
    v_34266 = v_34269;
    v_34266 = qcar(v_34266);
    stack[-1] = qcdr(v_34266);
    goto v_34208;
v_34209:
    stack[0] = v_34268;
    goto v_34210;
v_34211:
    v_34266 = v_34270;
    if (!consp(v_34266)) goto v_34225;
    goto v_34235;
v_34231:
    v_34266 = v_34270;
    v_34266 = qcar(v_34266);
    goto v_34232;
v_34233:
    goto v_34234;
v_34235:
    goto v_34231;
v_34232:
    goto v_34233;
v_34234:
    v_34266 = Lmember(nil, v_34266, v_34268);
    if (v_34266 == nil) goto v_34229;
    else goto v_34230;
v_34229:
    v_34266 = nil;
    goto v_34228;
v_34230:
    goto v_34247;
v_34243:
    v_34268 = v_34270;
    goto v_34244;
v_34245:
    v_34266 = v_34267;
    goto v_34246;
v_34247:
    goto v_34243;
v_34244:
    goto v_34245;
v_34246:
    v_34266 = Lmember(nil, v_34268, v_34266);
    v_34266 = (v_34266 == nil ? lisp_true : nil);
    goto v_34228;
    v_34266 = nil;
v_34228:
    goto v_34223;
v_34225:
    v_34266 = nil;
    goto v_34223;
    v_34266 = nil;
v_34223:
    if (v_34266 == nil) goto v_34221;
    goto v_34260;
v_34256:
    v_34266 = v_34267;
    goto v_34257;
v_34258:
    v_34267 = v_34270;
    goto v_34259;
v_34260:
    goto v_34256;
v_34257:
    goto v_34258;
v_34259:
    fn = elt(env, 1); // aconc
    v_34266 = (*qfn2(fn))(fn, v_34266, v_34267);
    env = stack[-4];
    goto v_34219;
v_34221:
    v_34266 = v_34267;
    goto v_34219;
    v_34266 = nil;
v_34219:
    goto v_34212;
v_34213:
    goto v_34207;
v_34208:
    goto v_34209;
v_34210:
    goto v_34211;
v_34212:
    v_34266 = CC_gak(elt(env, 0), 3, stack[-1], stack[0], v_34266);
    env = stack[-4];
    goto v_34201;
v_34202:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    goto v_34200;
v_34201:
    v_34269 = stack[-3];
    v_34268 = stack[-2];
    v_34267 = v_34266;
    goto v_34167;
    v_34266 = nil;
v_34173:
    return onevalue(v_34266);
}



// Code for anu_mk

static LispObject CC_anu_mk(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34182, v_34183, v_34184;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34182 = v_34169;
    v_34183 = v_34168;
// end of prologue
    goto v_34178;
v_34172:
    v_34184 = elt(env, 1); // anu
    goto v_34173;
v_34174:
    goto v_34175;
v_34176:
    goto v_34177;
v_34178:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
    goto v_34176;
v_34177:
    return list3(v_34184, v_34183, v_34182);
}



// Code for opfchk!!

static LispObject CC_opfchkB(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34455, v_34456;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_34168;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_34455 = stack[-6];
    v_34455 = qcar(v_34455);
    stack[-7] = v_34455;
    stack[-5] = v_34455;
    v_34455 = stack[-6];
    v_34455 = qcdr(v_34455);
    stack[-6] = v_34455;
    goto v_34196;
v_34192:
    v_34456 = stack[-7];
    goto v_34193;
v_34194:
    v_34455 = elt(env, 2); // integer
    goto v_34195;
v_34196:
    goto v_34192;
v_34193:
    goto v_34194;
v_34195:
    v_34455 = Lflagp(nil, v_34456, v_34455);
    env = stack[-8];
    if (v_34455 == nil) goto v_34190;
    v_34455 = lisp_true;
    stack[-3] = v_34455;
    goto v_34205;
v_34201:
    v_34456 = stack[-7];
    goto v_34202;
v_34203:
    v_34455 = elt(env, 3); // !:rn!:
    goto v_34204;
v_34205:
    goto v_34201;
v_34202:
    goto v_34203;
v_34204:
    v_34455 = get(v_34456, v_34455);
    env = stack[-8];
    goto v_34188;
v_34190:
    v_34455 = qvalue(elt(env, 4)); // !*numval
    if (v_34455 == nil) goto v_34209;
    goto v_34217;
v_34213:
    v_34456 = qvalue(elt(env, 5)); // dmode!*
    goto v_34214;
v_34215:
    v_34455 = elt(env, 6); // (!:rd!: !:cr!:)
    goto v_34216;
v_34217:
    goto v_34213;
v_34214:
    goto v_34215;
v_34216:
    v_34455 = Lmemq(nil, v_34456, v_34455);
    if (v_34455 == nil) goto v_34209;
    goto v_34226;
v_34222:
    v_34456 = stack[-7];
    goto v_34223;
v_34224:
    v_34455 = elt(env, 7); // !:rd!:
    goto v_34225;
v_34226:
    goto v_34222;
v_34223:
    goto v_34224;
v_34225:
    v_34455 = get(v_34456, v_34455);
    env = stack[-8];
    goto v_34188;
v_34209:
    v_34455 = nil;
v_34188:
    stack[-7] = v_34455;
    v_34455 = stack[-7];
    if (v_34455 == nil) goto v_34231;
    else goto v_34232;
v_34231:
    v_34455 = nil;
    goto v_34177;
v_34232:
    v_34455 = stack[-3];
    if (v_34455 == nil) goto v_34238;
    v_34455 = elt(env, 8); // simprn
    goto v_34236;
v_34238:
    goto v_34248;
v_34244:
    v_34456 = stack[-7];
    goto v_34245;
v_34246:
    v_34455 = elt(env, 9); // simparg
    goto v_34247;
v_34248:
    goto v_34244;
v_34245:
    goto v_34246;
v_34247:
    v_34455 = get(v_34456, v_34455);
    env = stack[-8];
    stack[-4] = v_34455;
    if (v_34455 == nil) goto v_34242;
    v_34455 = stack[-4];
    goto v_34236;
v_34242:
    v_34455 = elt(env, 10); // simprd
    goto v_34236;
    v_34455 = nil;
v_34236:
    stack[-4] = v_34455;
    v_34455 = stack[-3];
    if (v_34455 == nil) goto v_34259;
    else goto v_34257;
v_34259:
    v_34455 = qvalue(elt(env, 11)); // !*complex
    if (v_34455 == nil) goto v_34257;
    goto v_34258;
v_34257:
    goto v_34180;
v_34258:
    goto v_34272;
v_34268:
    v_34455 = stack[-6];
    v_34456 = qcar(v_34455);
    goto v_34269;
v_34270:
    v_34455 = elt(env, 12); // list
    goto v_34271;
v_34272:
    goto v_34268;
v_34269:
    goto v_34270;
v_34271:
    if (!consp(v_34456)) goto v_34266;
    v_34456 = qcar(v_34456);
    if (v_34456 == v_34455) goto v_34265;
    else goto v_34266;
v_34265:
    v_34455 = stack[-6];
    v_34455 = qcar(v_34455);
    v_34455 = qcdr(v_34455);
    fn = elt(env, 18); // revlis
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    fn = elt(env, 19); // simpcr
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    v_34456 = v_34455;
    if (v_34455 == nil) goto v_34279;
    goto v_34292;
v_34288:
    goto v_34289;
v_34290:
    v_34455 = nil;
    goto v_34291;
v_34292:
    goto v_34288;
v_34289:
    goto v_34290;
v_34291:
    if (!consp(v_34456)) goto v_34279;
    v_34456 = qcar(v_34456);
    if (v_34456 == v_34455) goto v_34286;
    else goto v_34279;
v_34286:
    goto v_34179;
v_34279:
    goto v_34180;
    goto v_34264;
v_34266:
v_34264:
    v_34455 = stack[-6];
    fn = elt(env, 18); // revlis
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    fn = elt(env, 19); // simpcr
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    stack[-6] = v_34455;
    if (v_34455 == nil) goto v_34299;
    else goto v_34300;
v_34299:
    v_34455 = nil;
    goto v_34177;
v_34300:
    goto v_34316;
v_34312:
    v_34456 = stack[-6];
    goto v_34313;
v_34314:
    v_34455 = nil;
    goto v_34315;
v_34316:
    goto v_34312;
v_34313:
    goto v_34314;
v_34315:
    if (!consp(v_34456)) goto v_34310;
    v_34456 = qcar(v_34456);
    if (v_34456 == v_34455) goto v_34309;
    else goto v_34310;
v_34309:
    v_34455 = lisp_true;
    goto v_34308;
v_34310:
    goto v_34330;
v_34326:
    v_34456 = stack[-5];
    goto v_34327;
v_34328:
    v_34455 = elt(env, 13); // expt
    goto v_34329;
v_34330:
    goto v_34326;
v_34327:
    goto v_34328;
v_34329:
    if (v_34456 == v_34455) goto v_34324;
    else goto v_34325;
v_34324:
    v_34455 = stack[-6];
    v_34455 = qcar(v_34455);
    v_34455 = qcar(v_34455);
    fn = elt(env, 20); // rd!:minusp
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    goto v_34323;
v_34325:
    v_34455 = nil;
    goto v_34323;
    v_34455 = nil;
v_34323:
    goto v_34308;
    v_34455 = nil;
v_34308:
    if (v_34455 == nil) goto v_34306;
    v_34455 = stack[-6];
    v_34455 = qcdr(v_34455);
    stack[-6] = v_34455;
    goto v_34298;
v_34306:
    v_34455 = stack[-6];
    v_34455 = qcdr(v_34455);
    stack[-2] = v_34455;
    v_34455 = stack[-6];
    v_34455 = qcar(v_34455);
    stack[-6] = v_34455;
    goto v_34180;
v_34298:
v_34178:
    goto v_34357;
v_34353:
    v_34456 = stack[-5];
    goto v_34354;
v_34355:
    v_34455 = elt(env, 14); // !:cr!:
    goto v_34356;
v_34357:
    goto v_34353;
v_34354:
    goto v_34355;
v_34356:
    v_34455 = get(v_34456, v_34455);
    env = stack[-8];
    stack[-7] = v_34455;
    if (v_34455 == nil) goto v_34351;
    goto v_34181;
v_34351:
v_34179:
    goto v_34367;
v_34361:
    stack[-1] = elt(env, 15); // alg
    goto v_34362;
v_34363:
    stack[0] = (LispObject)288+TAG_FIXNUM; // 18
    goto v_34364;
v_34365:
    goto v_34375;
v_34371:
    v_34456 = stack[-5];
    goto v_34372;
v_34373:
    v_34455 = elt(env, 16); // "is not defined as complex function"
    goto v_34374;
v_34375:
    goto v_34371;
v_34372:
    goto v_34373;
v_34374:
    v_34455 = list2(v_34456, v_34455);
    env = stack[-8];
    goto v_34366;
v_34367:
    goto v_34361;
v_34362:
    goto v_34363;
v_34364:
    goto v_34365;
v_34366:
    fn = elt(env, 21); // rerror
    v_34455 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34455);
    env = stack[-8];
v_34180:
    goto v_34387;
v_34383:
    stack[0] = stack[-4];
    goto v_34384;
v_34385:
    v_34455 = stack[-6];
    fn = elt(env, 18); // revlis
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    goto v_34386;
v_34387:
    goto v_34383;
v_34384:
    goto v_34385;
v_34386:
    v_34455 = Lapply1(nil, stack[0], v_34455);
    env = stack[-8];
    stack[-6] = v_34455;
    if (v_34455 == nil) goto v_34380;
    else goto v_34381;
v_34380:
    v_34455 = nil;
    goto v_34177;
v_34381:
v_34181:
    goto v_34400;
v_34394:
    stack[0] = elt(env, 17); // apply
    goto v_34395;
v_34396:
    v_34455 = stack[-7];
    stack[-1] = Lmkquote(nil, v_34455);
    env = stack[-8];
    goto v_34397;
v_34398:
    v_34455 = stack[-6];
    v_34455 = Lmkquote(nil, v_34455);
    env = stack[-8];
    goto v_34399;
v_34400:
    goto v_34394;
v_34395:
    goto v_34396;
v_34397:
    goto v_34398;
v_34399:
    v_34455 = list3(stack[0], stack[-1], v_34455);
    env = stack[-8];
    fn = elt(env, 22); // errorset2
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    stack[-6] = v_34455;
    v_34455 = stack[-6];
    fn = elt(env, 23); // errorp
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    if (v_34455 == nil) goto v_34410;
    else goto v_34408;
v_34410:
    goto v_34423;
v_34419:
    v_34455 = stack[-6];
    v_34456 = qcar(v_34455);
    stack[-6] = v_34456;
    goto v_34420;
v_34421:
    v_34455 = elt(env, 7); // !:rd!:
    goto v_34422;
v_34423:
    goto v_34419;
v_34420:
    goto v_34421;
v_34422:
    if (!consp(v_34456)) goto v_34417;
    v_34456 = qcar(v_34456);
    if (v_34456 == v_34455) goto v_34416;
    else goto v_34417;
v_34416:
    v_34455 = stack[-6];
    v_34455 = qcdr(v_34455);
    fn = elt(env, 24); // complexp
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-8];
    goto v_34415;
v_34417:
    v_34455 = nil;
    goto v_34415;
    v_34455 = nil;
v_34415:
    if (v_34455 == nil) goto v_34413;
    else goto v_34408;
v_34413:
    goto v_34409;
v_34408:
    v_34455 = stack[-2];
    if (v_34455 == nil) goto v_34436;
    v_34455 = stack[-2];
    stack[-6] = v_34455;
    v_34455 = nil;
    stack[-2] = v_34455;
    goto v_34178;
v_34436:
    v_34455 = nil;
    goto v_34177;
    goto v_34407;
v_34409:
    v_34455 = stack[-3];
    if (v_34455 == nil) goto v_34448;
    v_34455 = stack[-6];
    {
        fn = elt(env, 25); // intconv
        return (*qfn1(fn))(fn, v_34455);
    }
v_34448:
    v_34455 = stack[-6];
    goto v_34446;
    v_34455 = nil;
v_34446:
    goto v_34177;
v_34407:
    v_34455 = nil;
v_34177:
    return onevalue(v_34455);
}



// Code for constant_expr_listp

static LispObject CC_constant_expr_listp(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34238, v_34239;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_34168;
// end of prologue
v_34173:
    v_34238 = stack[0];
    if (!consp(v_34238)) goto v_34176;
    else goto v_34177;
v_34176:
    v_34238 = stack[0];
    v_34238 = (v_34238 == nil ? lisp_true : nil);
    v_34239 = v_34238;
    if (v_34238 == nil) goto v_34182;
    v_34238 = v_34239;
    goto v_34172;
v_34182:
    v_34238 = stack[0];
    v_34238 = (is_number(v_34238) ? lisp_true : nil);
    v_34239 = v_34238;
    if (v_34238 == nil) goto v_34187;
    v_34238 = v_34239;
    goto v_34172;
v_34187:
    goto v_34198;
v_34194:
    v_34239 = stack[0];
    goto v_34195;
v_34196:
    v_34238 = elt(env, 1); // constant
    goto v_34197;
v_34198:
    goto v_34194;
v_34195:
    goto v_34196;
v_34197:
    v_34238 = Lflagp(nil, v_34239, v_34238);
    env = stack[-1];
    v_34239 = v_34238;
    if (v_34238 == nil) goto v_34192;
    v_34238 = v_34239;
    goto v_34172;
v_34192:
    goto v_34212;
v_34208:
    v_34239 = stack[0];
    goto v_34209;
v_34210:
    v_34238 = elt(env, 2); // i
    goto v_34211;
v_34212:
    goto v_34208;
v_34209:
    goto v_34210;
v_34211:
    if (v_34239 == v_34238) goto v_34206;
    else goto v_34207;
v_34206:
    v_34238 = elt(env, 2); // i
    if (!symbolp(v_34238)) v_34238 = nil;
    else { v_34238 = qfastgets(v_34238);
           if (v_34238 != nil) { v_34238 = elt(v_34238, 56); // idvalfn
#ifdef RECORD_GET
             if (v_34238 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_34238 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_34238 == SPID_NOPROP) v_34238 = nil; }}
#endif
    goto v_34205;
v_34207:
    v_34238 = nil;
    goto v_34205;
    v_34238 = nil;
v_34205:
    v_34239 = v_34238;
    if (v_34238 == nil) goto v_34203;
    v_34238 = v_34239;
    goto v_34172;
v_34203:
    v_34238 = nil;
    goto v_34172;
    goto v_34175;
v_34177:
    v_34238 = stack[0];
    v_34238 = qcar(v_34238);
    fn = elt(env, 3); // constant_exprp
    v_34238 = (*qfn1(fn))(fn, v_34238);
    env = stack[-1];
    if (v_34238 == nil) goto v_34229;
    v_34238 = stack[0];
    v_34238 = qcdr(v_34238);
    stack[0] = v_34238;
    goto v_34173;
v_34229:
    v_34238 = nil;
    goto v_34172;
    goto v_34175;
v_34175:
    v_34238 = nil;
v_34172:
    return onevalue(v_34238);
}



// Code for talp_nextt

static LispObject CC_talp_nextt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34455, v_34456, v_34457, v_34458, v_34459, v_34460, v_34461, v_34462;
    LispObject fn;
    LispObject v_34170, v_34169, v_34168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_nextt");
    va_start(aa, nargs);
    v_34168 = va_arg(aa, LispObject);
    v_34169 = va_arg(aa, LispObject);
    v_34170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34170,v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34168,v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_34170;
    stack[-7] = v_34169;
    stack[-8] = v_34168;
// end of prologue
    stack[-9] = nil;
    fn = elt(env, 2); // talp_getl
    v_34455 = (*qfnn(fn))(fn, 0);
    env = stack[-10];
    stack[-3] = v_34455;
v_34186:
    v_34455 = stack[-3];
    if (v_34455 == nil) goto v_34191;
    else goto v_34192;
v_34191:
    v_34455 = nil;
    goto v_34185;
v_34192:
    v_34455 = stack[-3];
    v_34455 = qcar(v_34455);
    v_34457 = v_34455;
    goto v_34206;
v_34202:
    v_34455 = v_34457;
    v_34456 = qcdr(v_34455);
    goto v_34203;
v_34204:
    v_34455 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34205;
v_34206:
    goto v_34202;
v_34203:
    goto v_34204;
v_34205:
    if (v_34456 == v_34455) goto v_34200;
    else goto v_34201;
v_34200:
    goto v_34215;
v_34211:
    v_34455 = v_34457;
    v_34456 = qcar(v_34455);
    goto v_34212;
v_34213:
    v_34455 = stack[-9];
    goto v_34214;
v_34215:
    goto v_34211;
v_34212:
    goto v_34213;
v_34214:
    v_34455 = cons(v_34456, v_34455);
    env = stack[-10];
    stack[-9] = v_34455;
    v_34455 = nil;
    goto v_34199;
v_34201:
    goto v_34227;
v_34223:
    v_34455 = stack[-6];
    goto v_34224;
v_34225:
    v_34456 = v_34457;
    goto v_34226;
v_34227:
    goto v_34223;
v_34224:
    goto v_34225;
v_34226:
    fn = elt(env, 3); // talp_mk!-invs
    v_34455 = (*qfn2(fn))(fn, v_34455, v_34456);
    env = stack[-10];
    goto v_34199;
    v_34455 = nil;
v_34199:
    stack[-2] = v_34455;
    v_34455 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-1] = v_34455;
    v_34455 = stack[-3];
    v_34455 = qcdr(v_34455);
    stack[-3] = v_34455;
    v_34455 = stack[-1];
    if (!consp(v_34455)) goto v_34236;
    else goto v_34237;
v_34236:
    goto v_34186;
v_34237:
v_34187:
    v_34455 = stack[-3];
    if (v_34455 == nil) goto v_34241;
    else goto v_34242;
v_34241:
    v_34455 = stack[-2];
    goto v_34185;
v_34242:
    goto v_34250;
v_34246:
    stack[0] = stack[-1];
    goto v_34247;
v_34248:
    v_34455 = stack[-3];
    v_34455 = qcar(v_34455);
    v_34457 = v_34455;
    goto v_34263;
v_34259:
    v_34455 = v_34457;
    v_34456 = qcdr(v_34455);
    goto v_34260;
v_34261:
    v_34455 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34262;
v_34263:
    goto v_34259;
v_34260:
    goto v_34261;
v_34262:
    if (v_34456 == v_34455) goto v_34257;
    else goto v_34258;
v_34257:
    goto v_34272;
v_34268:
    v_34455 = v_34457;
    v_34456 = qcar(v_34455);
    goto v_34269;
v_34270:
    v_34455 = stack[-9];
    goto v_34271;
v_34272:
    goto v_34268;
v_34269:
    goto v_34270;
v_34271:
    v_34455 = cons(v_34456, v_34455);
    env = stack[-10];
    stack[-9] = v_34455;
    v_34455 = nil;
    goto v_34256;
v_34258:
    goto v_34284;
v_34280:
    v_34455 = stack[-6];
    goto v_34281;
v_34282:
    v_34456 = v_34457;
    goto v_34283;
v_34284:
    goto v_34280;
v_34281:
    goto v_34282;
v_34283:
    fn = elt(env, 3); // talp_mk!-invs
    v_34455 = (*qfn2(fn))(fn, v_34455, v_34456);
    env = stack[-10];
    goto v_34256;
    v_34455 = nil;
v_34256:
    goto v_34249;
v_34250:
    goto v_34246;
v_34247:
    goto v_34248;
v_34249:
    v_34455 = Lrplacd(nil, stack[0], v_34455);
    env = stack[-10];
    v_34455 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-1] = v_34455;
    v_34455 = stack[-3];
    v_34455 = qcdr(v_34455);
    stack[-3] = v_34455;
    goto v_34187;
v_34185:
    fn = elt(env, 5); // talp_list2vec
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-5] = v_34455;
    v_34455 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_34455;
v_34297:
    goto v_34310;
v_34306:
    v_34455 = stack[-5];
    v_34456 = Lupbv(nil, v_34455);
    env = stack[-10];
    goto v_34307;
v_34308:
    v_34455 = stack[-4];
    goto v_34309;
v_34310:
    goto v_34306;
v_34307:
    goto v_34308;
v_34309:
    v_34455 = difference2(v_34456, v_34455);
    env = stack[-10];
    v_34455 = Lminusp(nil, v_34455);
    env = stack[-10];
    if (v_34455 == nil) goto v_34303;
    v_34455 = nil;
    goto v_34296;
v_34303:
    goto v_34319;
v_34315:
    v_34456 = stack[-5];
    goto v_34316;
v_34317:
    v_34455 = stack[-4];
    goto v_34318;
v_34319:
    goto v_34315;
v_34316:
    goto v_34317;
v_34318:
    v_34455 = *(LispObject *)((char *)v_34456 + (CELL-TAG_VECTOR) + (((intptr_t)v_34455-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_34455;
    v_34455 = stack[0];
    fn = elt(env, 6); // talp_invp
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    if (v_34455 == nil) goto v_34327;
    v_34455 = stack[0];
    v_34455 = ncons(v_34455);
    env = stack[-10];
    goto v_34325;
v_34327:
    v_34455 = nil;
v_34325:
    stack[-3] = v_34455;
    v_34455 = stack[-3];
    fn = elt(env, 4); // lastpair
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-2] = v_34455;
    v_34455 = stack[-4];
    v_34455 = add1(v_34455);
    env = stack[-10];
    stack[-4] = v_34455;
    v_34455 = stack[-2];
    if (!consp(v_34455)) goto v_34338;
    else goto v_34339;
v_34338:
    goto v_34297;
v_34339:
v_34298:
    goto v_34351;
v_34347:
    v_34455 = stack[-5];
    v_34456 = Lupbv(nil, v_34455);
    env = stack[-10];
    goto v_34348;
v_34349:
    v_34455 = stack[-4];
    goto v_34350;
v_34351:
    goto v_34347;
v_34348:
    goto v_34349;
v_34350:
    v_34455 = difference2(v_34456, v_34455);
    env = stack[-10];
    v_34455 = Lminusp(nil, v_34455);
    env = stack[-10];
    if (v_34455 == nil) goto v_34344;
    v_34455 = stack[-3];
    goto v_34296;
v_34344:
    goto v_34361;
v_34357:
    stack[-1] = stack[-2];
    goto v_34358;
v_34359:
    goto v_34367;
v_34363:
    v_34456 = stack[-5];
    goto v_34364;
v_34365:
    v_34455 = stack[-4];
    goto v_34366;
v_34367:
    goto v_34363;
v_34364:
    goto v_34365;
v_34366:
    v_34455 = *(LispObject *)((char *)v_34456 + (CELL-TAG_VECTOR) + (((intptr_t)v_34455-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_34455;
    v_34455 = stack[0];
    fn = elt(env, 6); // talp_invp
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    if (v_34455 == nil) goto v_34375;
    v_34455 = stack[0];
    v_34455 = ncons(v_34455);
    env = stack[-10];
    goto v_34373;
v_34375:
    v_34455 = nil;
v_34373:
    goto v_34360;
v_34361:
    goto v_34357;
v_34358:
    goto v_34359;
v_34360:
    v_34455 = Lrplacd(nil, stack[-1], v_34455);
    env = stack[-10];
    v_34455 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-2] = v_34455;
    v_34455 = stack[-4];
    v_34455 = add1(v_34455);
    env = stack[-10];
    stack[-4] = v_34455;
    goto v_34298;
v_34296:
    fn = elt(env, 5); // talp_list2vec
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[0] = v_34455;
    goto v_34390;
v_34386:
    v_34455 = stack[-9];
    v_34456 = Lnreverse(nil, v_34455);
    env = stack[-10];
    goto v_34387;
v_34388:
    v_34455 = stack[-6];
    goto v_34389;
v_34390:
    goto v_34386;
v_34387:
    goto v_34388;
v_34389:
    v_34455 = Lnconc(nil, v_34456, v_34455);
    env = stack[-10];
    fn = elt(env, 5); // talp_list2vec
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    stack[-1] = v_34455;
    v_34455 = stack[-6];
    fn = elt(env, 5); // talp_list2vec
    v_34455 = (*qfn1(fn))(fn, v_34455);
    env = stack[-10];
    v_34456 = stack[-8];
    if (v_34456 == nil) goto v_34399;
    goto v_34418;
v_34402:
    v_34462 = stack[-8];
    goto v_34403;
v_34404:
    v_34461 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34405;
v_34406:
    v_34460 = stack[-7];
    goto v_34407;
v_34408:
    v_34459 = stack[-1];
    goto v_34409;
v_34410:
    v_34458 = v_34455;
    goto v_34411;
v_34412:
    v_34457 = stack[-5];
    goto v_34413;
v_34414:
    v_34456 = stack[0];
    goto v_34415;
v_34416:
    v_34455 = nil;
    goto v_34417;
v_34418:
    goto v_34402;
v_34403:
    goto v_34404;
v_34405:
    goto v_34406;
v_34407:
    goto v_34408;
v_34409:
    goto v_34410;
v_34411:
    goto v_34412;
v_34413:
    goto v_34414;
v_34415:
    goto v_34416;
v_34417:
    fn = elt(env, 7); // talp_nextt1
    v_34455 = (*qfnn(fn))(fn, 8, v_34462, v_34461, v_34460, v_34459, v_34458, v_34457, v_34456, v_34455);
    v_34456 = v_34455;
    v_34455 = v_34456;
    v_34455 = qcar(v_34455);
    if (v_34455 == nil) goto v_34431;
    v_34455 = v_34456;
    v_34455 = qcdr(v_34455);
    goto v_34429;
v_34431:
    v_34455 = nil;
v_34429:
    goto v_34397;
v_34399:
    goto v_34443;
v_34439:
    v_34455 = stack[-1];
    v_34456 = Lupbv(nil, v_34455);
    env = stack[-10];
    goto v_34440;
v_34441:
    v_34455 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_34442;
v_34443:
    goto v_34439;
v_34440:
    goto v_34441;
v_34442:
    v_34455 = (LispObject)greaterp2(v_34456, v_34455);
    v_34455 = v_34455 ? lisp_true : nil;
    if (v_34455 == nil) goto v_34437;
    goto v_34451;
v_34447:
    v_34456 = stack[-1];
    goto v_34448;
v_34449:
    v_34455 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34450;
v_34451:
    goto v_34447;
v_34448:
    goto v_34449;
v_34450:
    v_34455 = *(LispObject *)((char *)v_34456 + (CELL-TAG_VECTOR) + (((intptr_t)v_34455-TAG_FIXNUM)/(16/CELL)));
    goto v_34397;
v_34437:
    v_34455 = nil;
v_34397:
    return onevalue(v_34455);
}



// Code for dip_reduceconti

static LispObject CC_dip_reduceconti(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34204, v_34205;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_34169;
    stack[-2] = v_34168;
// end of prologue
    v_34204 = stack[-2];
    if (v_34204 == nil) goto v_34174;
    goto v_34183;
v_34177:
    goto v_34189;
v_34185:
    v_34204 = stack[-2];
    fn = elt(env, 1); // dip_lbc
    v_34205 = (*qfn1(fn))(fn, v_34204);
    env = stack[-4];
    goto v_34186;
v_34187:
    v_34204 = stack[-1];
    goto v_34188;
v_34189:
    goto v_34185;
v_34186:
    goto v_34187;
v_34188:
    fn = elt(env, 2); // bc_quot
    stack[-3] = (*qfn2(fn))(fn, v_34205, v_34204);
    env = stack[-4];
    goto v_34178;
v_34179:
    v_34204 = stack[-2];
    fn = elt(env, 3); // dip_evlmon
    stack[0] = (*qfn1(fn))(fn, v_34204);
    env = stack[-4];
    goto v_34180;
v_34181:
    goto v_34200;
v_34196:
    v_34204 = stack[-2];
    fn = elt(env, 4); // dip_mred
    v_34205 = (*qfn1(fn))(fn, v_34204);
    env = stack[-4];
    goto v_34197;
v_34198:
    v_34204 = stack[-1];
    goto v_34199;
v_34200:
    goto v_34196;
v_34197:
    goto v_34198;
v_34199:
    v_34204 = CC_dip_reduceconti(elt(env, 0), v_34205, v_34204);
    env = stack[-4];
    goto v_34182;
v_34183:
    goto v_34177;
v_34178:
    goto v_34179;
v_34180:
    goto v_34181;
v_34182:
    {
        LispObject v_34210 = stack[-3];
        LispObject v_34211 = stack[0];
        fn = elt(env, 5); // dip_moncomp
        return (*qfnn(fn))(fn, 3, v_34210, v_34211, v_34204);
    }
v_34174:
    v_34204 = nil;
    return onevalue(v_34204);
}



// Code for poly!-remainder

static LispObject CC_polyKremainder(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34181, v_34182, v_34183;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34181 = v_34168;
// end of prologue
    goto v_34177;
v_34171:
    v_34183 = v_34181;
    goto v_34172;
v_34173:
    v_34182 = elt(env, 1); // remainder
    goto v_34174;
v_34175:
    v_34181 = nil;
    goto v_34176;
v_34177:
    goto v_34171;
v_34172:
    goto v_34173;
v_34174:
    goto v_34175;
v_34176:
    {
        fn = elt(env, 2); // poly!-divide!*
        return (*qfnn(fn))(fn, 3, v_34183, v_34182, v_34181);
    }
}



// Code for xriterion_2

static LispObject CC_xriterion_2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34312, v_34313, v_34314;
    LispObject fn;
    LispObject v_34170, v_34169, v_34168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_2");
    va_start(aa, nargs);
    v_34168 = va_arg(aa, LispObject);
    v_34169 = va_arg(aa, LispObject);
    v_34170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34170,v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34168,v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34170;
    stack[-1] = v_34169;
    stack[-2] = v_34168;
// end of prologue
v_34167:
    v_34312 = stack[-1];
    if (v_34312 == nil) goto v_34174;
    else goto v_34175;
v_34174:
    v_34312 = nil;
    goto v_34173;
v_34175:
    goto v_34184;
v_34180:
    v_34312 = stack[-2];
    v_34312 = qcdr(v_34312);
    v_34313 = qcar(v_34312);
    goto v_34181;
v_34182:
    v_34312 = elt(env, 1); // wedge_pair
    goto v_34183;
v_34184:
    goto v_34180;
v_34181:
    goto v_34182;
v_34183:
    if (v_34313 == v_34312) goto v_34179;
    v_34312 = nil;
    goto v_34173;
v_34179:
    v_34312 = stack[-1];
    v_34312 = qcar(v_34312);
    stack[-3] = v_34312;
    goto v_34206;
v_34202:
    goto v_34215;
v_34209:
    v_34314 = stack[-3];
    goto v_34210;
v_34211:
    v_34313 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34212;
v_34213:
    v_34312 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34214;
v_34215:
    goto v_34209;
v_34210:
    goto v_34211;
v_34212:
    goto v_34213;
v_34214:
    v_34312 = list2star(v_34314, v_34313, v_34312);
    env = stack[-4];
    v_34313 = ncons(v_34312);
    env = stack[-4];
    goto v_34203;
v_34204:
    v_34312 = stack[-2];
    v_34312 = qcdr(v_34312);
    v_34312 = qcdr(v_34312);
    v_34312 = qcar(v_34312);
    goto v_34205;
v_34206:
    goto v_34202;
v_34203:
    goto v_34204;
v_34205:
    if (equal(v_34313, v_34312)) goto v_34201;
    goto v_34232;
v_34228:
    goto v_34238;
v_34234:
    v_34313 = stack[-3];
    goto v_34235;
v_34236:
    v_34312 = stack[-3];
    goto v_34237;
v_34238:
    goto v_34234;
v_34235:
    goto v_34236;
v_34237:
    v_34313 = list2(v_34313, v_34312);
    env = stack[-4];
    goto v_34229;
v_34230:
    v_34312 = stack[-2];
    v_34312 = qcar(v_34312);
    goto v_34231;
v_34232:
    goto v_34228;
v_34229:
    goto v_34230;
v_34231:
    fn = elt(env, 5); // xdiv
    v_34312 = (*qfn2(fn))(fn, v_34313, v_34312);
    env = stack[-4];
    if (v_34312 == nil) goto v_34225;
    else goto v_34226;
v_34225:
    v_34312 = nil;
    goto v_34224;
v_34226:
    goto v_34255;
v_34251:
    v_34313 = stack[-3];
    goto v_34252;
v_34253:
    v_34312 = stack[-2];
    v_34312 = qcdr(v_34312);
    v_34312 = qcdr(v_34312);
    v_34312 = qcdr(v_34312);
    v_34312 = qcar(v_34312);
    goto v_34254;
v_34255:
    goto v_34251;
v_34252:
    goto v_34253;
v_34254:
    fn = elt(env, 6); // make_wedge_pair
    v_34312 = (*qfn2(fn))(fn, v_34313, v_34312);
    env = stack[-4];
    v_34313 = v_34312;
    v_34312 = v_34313;
    if (v_34312 == nil) goto v_34265;
    else goto v_34266;
v_34265:
    v_34312 = lisp_true;
    goto v_34264;
v_34266:
    goto v_34276;
v_34272:
    goto v_34273;
v_34274:
    v_34312 = stack[0];
    goto v_34275;
v_34276:
    goto v_34272;
v_34273:
    goto v_34274;
v_34275:
    fn = elt(env, 7); // find_item
    v_34312 = (*qfn2(fn))(fn, v_34313, v_34312);
    env = stack[-4];
    v_34312 = (v_34312 == nil ? lisp_true : nil);
    goto v_34264;
    v_34312 = nil;
v_34264:
    if (v_34312 == nil) goto v_34248;
    else goto v_34249;
v_34248:
    v_34312 = nil;
    goto v_34247;
v_34249:
    v_34312 = qvalue(elt(env, 2)); // !*trxideal
    if (v_34312 == nil) goto v_34286;
    goto v_34293;
v_34289:
    v_34313 = elt(env, 3); // "criterion 2 hit"
    goto v_34290;
v_34291:
    v_34312 = elt(env, 4); // last
    goto v_34292;
v_34293:
    goto v_34289;
v_34290:
    goto v_34291;
v_34292:
    fn = elt(env, 8); // writepri
    v_34312 = (*qfn2(fn))(fn, v_34313, v_34312);
    env = stack[-4];
    goto v_34284;
v_34286:
v_34284:
    v_34312 = lisp_true;
    goto v_34247;
    v_34312 = nil;
v_34247:
    goto v_34224;
    v_34312 = nil;
v_34224:
    goto v_34199;
v_34201:
    v_34312 = nil;
    goto v_34199;
    v_34312 = nil;
v_34199:
    if (v_34312 == nil) goto v_34197;
    else goto v_34196;
v_34197:
    goto v_34307;
v_34301:
    v_34314 = stack[-2];
    goto v_34302;
v_34303:
    v_34312 = stack[-1];
    v_34313 = qcdr(v_34312);
    goto v_34304;
v_34305:
    v_34312 = stack[0];
    goto v_34306;
v_34307:
    goto v_34301;
v_34302:
    goto v_34303;
v_34304:
    goto v_34305;
v_34306:
    stack[-2] = v_34314;
    stack[-1] = v_34313;
    stack[0] = v_34312;
    goto v_34167;
v_34196:
    goto v_34173;
    v_34312 = nil;
v_34173:
    return onevalue(v_34312);
}



// Code for evalsubset

static LispObject CC_evalsubset(LispObject env,
                         LispObject v_34168, LispObject v_34169)
{
    env = qenv(env);
    LispObject v_34193, v_34194, v_34195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34168,v_34169);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34193 = v_34169;
    v_34194 = v_34168;
// end of prologue
    goto v_34178;
v_34172:
    v_34195 = elt(env, 1); // subset
    goto v_34173;
v_34174:
    goto v_34175;
v_34176:
    goto v_34177;
v_34178:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
    goto v_34176;
v_34177:
    fn = elt(env, 2); // evalsetbool
    v_34193 = (*qfnn(fn))(fn, 3, v_34195, v_34194, v_34193);
    env = stack[0];
    v_34194 = v_34193;
    v_34193 = v_34194;
    if (!consp(v_34193)) goto v_34185;
    else goto v_34186;
v_34185:
    v_34193 = v_34194;
    goto v_34184;
v_34186:
    v_34193 = v_34194;
    {
        fn = elt(env, 3); // evalsymsubset
        return (*qfn1(fn))(fn, v_34193);
    }
    v_34193 = nil;
v_34184:
    return onevalue(v_34193);
}



// Code for preproc

static LispObject CC_preproc(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_34186, v_34187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
// copy arguments values to proper place
    v_34186 = v_34168;
// end of prologue
    fn = elt(env, 2); // preproc1
    v_34186 = (*qfn1(fn))(fn, v_34186);
    v_34187 = v_34186;
    v_34186 = v_34187;
    if (v_34186 == nil) goto v_34179;
    v_34186 = v_34187;
    v_34186 = qcar(v_34186);
    goto v_34172;
v_34179:
    v_34186 = v_34187;
    goto v_34172;
    v_34186 = nil;
v_34172:
    return onevalue(v_34186);
}



// Code for partitindexvar

static LispObject CC_partitindexvar(LispObject env,
                         LispObject v_34168)
{
    env = qenv(env);
    LispObject v_35124, v_35125, v_35126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34168);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_34168;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    v_35124 = stack[-7];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34191;
    else goto v_34192;
v_34191:
    v_35124 = nil;
    goto v_34185;
v_34192:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    fn = elt(env, 6); // revalind
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    v_35125 = v_35124;
    v_35124 = v_35125;
    if (!consp(v_35124)) goto v_34204;
    else goto v_34205;
v_34204:
    v_35124 = v_35125;
    if (is_number(v_35124)) goto v_34209;
    else goto v_34210;
v_34209:
    v_35124 = v_35125;
    v_35124 = Lminusp(nil, v_35124);
    env = stack[-9];
    if (v_35124 == nil) goto v_34215;
    goto v_34223;
v_34219:
    stack[0] = elt(env, 2); // minus
    goto v_34220;
v_34221:
    v_35124 = v_35125;
    v_35124 = Labsval(nil, v_35124);
    env = stack[-9];
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34222;
v_34223:
    goto v_34219;
v_34220:
    goto v_34221;
v_34222:
    v_35124 = list2(stack[0], v_35124);
    env = stack[-9];
    goto v_34213;
v_34215:
    v_35124 = v_35125;
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34213;
    v_35124 = nil;
v_34213:
    goto v_34208;
v_34210:
    v_35124 = v_35125;
    goto v_34208;
    v_35124 = nil;
v_34208:
    goto v_34203;
v_34205:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    if (is_number(v_35124)) goto v_34235;
    else goto v_34236;
v_34235:
    goto v_34245;
v_34241:
    stack[0] = elt(env, 2); // minus
    goto v_34242;
v_34243:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34244;
v_34245:
    goto v_34241;
v_34242:
    goto v_34243;
v_34244:
    v_35124 = list2(stack[0], v_35124);
    env = stack[-9];
    goto v_34203;
v_34236:
    v_35124 = v_35125;
    goto v_34203;
    v_35124 = nil;
v_34203:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    stack[-2] = v_35124;
    stack[-3] = v_35124;
v_34186:
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34258;
    else goto v_34259;
v_34258:
    v_35124 = stack[-3];
    goto v_34185;
v_34259:
    goto v_34267;
v_34263:
    stack[-1] = stack[-2];
    goto v_34264;
v_34265:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    fn = elt(env, 6); // revalind
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    v_35125 = v_35124;
    v_35124 = v_35125;
    if (!consp(v_35124)) goto v_34278;
    else goto v_34279;
v_34278:
    v_35124 = v_35125;
    if (is_number(v_35124)) goto v_34283;
    else goto v_34284;
v_34283:
    v_35124 = v_35125;
    v_35124 = Lminusp(nil, v_35124);
    env = stack[-9];
    if (v_35124 == nil) goto v_34289;
    goto v_34297;
v_34293:
    stack[0] = elt(env, 2); // minus
    goto v_34294;
v_34295:
    v_35124 = v_35125;
    v_35124 = Labsval(nil, v_35124);
    env = stack[-9];
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34296;
v_34297:
    goto v_34293;
v_34294:
    goto v_34295;
v_34296:
    v_35124 = list2(stack[0], v_35124);
    env = stack[-9];
    goto v_34287;
v_34289:
    v_35124 = v_35125;
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34287;
    v_35124 = nil;
v_34287:
    goto v_34282;
v_34284:
    v_35124 = v_35125;
    goto v_34282;
    v_35124 = nil;
v_34282:
    goto v_34277;
v_34279:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    if (is_number(v_35124)) goto v_34309;
    else goto v_34310;
v_34309:
    goto v_34319;
v_34315:
    stack[0] = elt(env, 2); // minus
    goto v_34316;
v_34317:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    fn = elt(env, 7); // !*num2id
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34318;
v_34319:
    goto v_34315;
v_34316:
    goto v_34317;
v_34318:
    v_35124 = list2(stack[0], v_35124);
    env = stack[-9];
    goto v_34277;
v_34310:
    v_35124 = v_35125;
    goto v_34277;
    v_35124 = nil;
v_34277:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    goto v_34266;
v_34267:
    goto v_34263;
v_34264:
    goto v_34265;
v_34266:
    v_35124 = Lrplacd(nil, stack[-1], v_35124);
    env = stack[-9];
    v_35124 = stack[-2];
    v_35124 = qcdr(v_35124);
    stack[-2] = v_35124;
    goto v_34186;
v_34185:
    stack[0] = v_35124;
    v_35124 = stack[-7];
    fn = elt(env, 8); // deg!*form
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    stack[-3] = v_35124;
    v_35124 = qvalue(elt(env, 3)); // metricu!*
    if (v_35124 == nil) goto v_34334;
    else goto v_34335;
v_34334:
    goto v_34179;
v_34335:
    v_35124 = stack[0];
    stack[-2] = v_35124;
    goto v_34347;
v_34343:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34344;
v_34345:
    v_35124 = elt(env, 4); // covariant
    goto v_34346;
v_34347:
    goto v_34343;
v_34344:
    goto v_34345;
v_34346:
    v_35124 = Lflagp(nil, v_35125, v_35124);
    env = stack[-9];
    if (v_35124 == nil) goto v_34340;
    else goto v_34341;
v_34340:
v_34353:
    v_35124 = stack[-2];
    if (v_35124 == nil) goto v_34356;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    if (!consp(v_35124)) goto v_34363;
    else goto v_34364;
v_34363:
    v_35124 = lisp_true;
    goto v_34362;
v_34364:
    goto v_34374;
v_34370:
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    v_35124 = qcdr(v_35124);
    v_35125 = qcar(v_35124);
    goto v_34371;
v_34372:
    v_35124 = qvalue(elt(env, 3)); // metricu!*
    goto v_34373;
v_34374:
    goto v_34370;
v_34371:
    goto v_34372;
v_34373:
    v_35124 = Latsoc(nil, v_35125, v_35124);
    v_35124 = (v_35124 == nil ? lisp_true : nil);
    goto v_34362;
    v_35124 = nil;
v_34362:
    if (v_35124 == nil) goto v_34356;
    goto v_34357;
v_34356:
    goto v_34352;
v_34357:
    goto v_34388;
v_34384:
    v_35124 = stack[-2];
    v_35125 = qcar(v_35124);
    goto v_34385;
v_34386:
    v_35124 = stack[-6];
    goto v_34387;
v_34388:
    goto v_34384;
v_34385:
    goto v_34386;
v_34387:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    stack[-6] = v_35124;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    if (!consp(v_35124)) goto v_34395;
    goto v_34403;
v_34399:
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    v_35124 = qcdr(v_35124);
    v_35125 = qcar(v_35124);
    goto v_34400;
v_34401:
    v_35124 = stack[-8];
    goto v_34402;
v_34403:
    goto v_34399;
v_34400:
    goto v_34401;
v_34402:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    stack[-8] = v_35124;
    goto v_34393;
v_34395:
v_34393:
    v_35124 = stack[-2];
    v_35124 = qcdr(v_35124);
    stack[-2] = v_35124;
    goto v_34353;
v_34352:
    v_35124 = stack[-2];
    if (v_35124 == nil) goto v_34414;
    v_35124 = nil;
    stack[-5] = v_35124;
    v_35124 = stack[-6];
    v_35124 = Lreverse(nil, v_35124);
    env = stack[-9];
    stack[-6] = v_35124;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    fn = elt(env, 9); // getlower
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    stack[-4] = v_35124;
v_34422:
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34430;
    else goto v_34431;
v_34430:
    goto v_34421;
v_34431:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    stack[-3] = v_35124;
    goto v_34442;
v_34438:
    goto v_34448;
v_34444:
    goto v_34455;
v_34451:
    v_35124 = stack[-7];
    stack[-1] = qcar(v_35124);
    goto v_34452;
v_34453:
    goto v_34463;
v_34459:
    stack[0] = stack[-6];
    goto v_34460;
v_34461:
    goto v_34470;
v_34466:
    v_35124 = stack[-3];
    v_35125 = qcar(v_35124);
    goto v_34467;
v_34468:
    v_35124 = stack[-2];
    v_35124 = qcdr(v_35124);
    goto v_34469;
v_34470:
    goto v_34466;
v_34467:
    goto v_34468;
v_34469:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_34462;
v_34463:
    goto v_34459;
v_34460:
    goto v_34461;
v_34462:
    v_35124 = Lappend(nil, stack[0], v_35124);
    env = stack[-9];
    goto v_34454;
v_34455:
    goto v_34451;
v_34452:
    goto v_34453;
v_34454:
    v_35124 = cons(stack[-1], v_35124);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_35124);
    env = stack[-9];
    goto v_34445;
v_34446:
    v_35124 = stack[-3];
    v_35124 = qcdr(v_35124);
    fn = elt(env, 10); // simp
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34447;
v_34448:
    goto v_34444;
v_34445:
    goto v_34446;
v_34447:
    fn = elt(env, 11); // multpfsq
    v_35125 = (*qfn2(fn))(fn, stack[0], v_35124);
    env = stack[-9];
    goto v_34439;
v_34440:
    v_35124 = stack[-5];
    goto v_34441;
v_34442:
    goto v_34438;
v_34439:
    goto v_34440;
v_34441:
    fn = elt(env, 12); // addpf
    v_35124 = (*qfn2(fn))(fn, v_35125, v_35124);
    env = stack[-9];
    stack[-5] = v_35124;
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    goto v_34422;
v_34421:
    v_35124 = stack[-5];
    goto v_34178;
v_34414:
    goto v_34339;
v_34341:
v_34486:
    v_35124 = stack[-2];
    if (v_35124 == nil) goto v_34489;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    if (!consp(v_35124)) goto v_34497;
    v_35124 = lisp_true;
    goto v_34495;
v_34497:
    goto v_34507;
v_34503:
    v_35124 = stack[-2];
    v_35125 = qcar(v_35124);
    goto v_34504;
v_34505:
    v_35124 = qvalue(elt(env, 3)); // metricu!*
    goto v_34506;
v_34507:
    goto v_34503;
v_34504:
    goto v_34505;
v_34506:
    v_35124 = Latsoc(nil, v_35125, v_35124);
    v_35124 = (v_35124 == nil ? lisp_true : nil);
    goto v_34495;
    v_35124 = nil;
v_34495:
    if (v_35124 == nil) goto v_34489;
    goto v_34490;
v_34489:
    goto v_34485;
v_34490:
    goto v_34519;
v_34515:
    v_35124 = stack[-2];
    v_35125 = qcar(v_35124);
    goto v_34516;
v_34517:
    v_35124 = stack[-6];
    goto v_34518;
v_34519:
    goto v_34515;
v_34516:
    goto v_34517;
v_34518:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    stack[-6] = v_35124;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    if (!consp(v_35124)) goto v_34525;
    else goto v_34526;
v_34525:
    goto v_34534;
v_34530:
    v_35124 = stack[-2];
    v_35125 = qcar(v_35124);
    goto v_34531;
v_34532:
    v_35124 = stack[-8];
    goto v_34533;
v_34534:
    goto v_34530;
v_34531:
    goto v_34532;
v_34533:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    stack[-8] = v_35124;
    goto v_34524;
v_34526:
v_34524:
    v_35124 = stack[-2];
    v_35124 = qcdr(v_35124);
    stack[-2] = v_35124;
    goto v_34486;
v_34485:
    v_35124 = stack[-2];
    if (v_35124 == nil) goto v_34543;
    v_35124 = nil;
    stack[-5] = v_35124;
    v_35124 = stack[-6];
    v_35124 = Lreverse(nil, v_35124);
    env = stack[-9];
    stack[-6] = v_35124;
    v_35124 = stack[-2];
    v_35124 = qcar(v_35124);
    fn = elt(env, 13); // getupper
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    stack[-4] = v_35124;
v_34551:
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34557;
    else goto v_34558;
v_34557:
    goto v_34550;
v_34558:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    stack[-3] = v_35124;
    goto v_34569;
v_34565:
    goto v_34575;
v_34571:
    goto v_34582;
v_34578:
    v_35124 = stack[-7];
    stack[-1] = qcar(v_35124);
    goto v_34579;
v_34580:
    goto v_34590;
v_34586:
    stack[0] = stack[-6];
    goto v_34587;
v_34588:
    goto v_34597;
v_34593:
    goto v_34603;
v_34599:
    v_35125 = elt(env, 2); // minus
    goto v_34600;
v_34601:
    v_35124 = stack[-3];
    v_35124 = qcar(v_35124);
    goto v_34602;
v_34603:
    goto v_34599;
v_34600:
    goto v_34601;
v_34602:
    v_35125 = list2(v_35125, v_35124);
    env = stack[-9];
    goto v_34594;
v_34595:
    v_35124 = stack[-2];
    v_35124 = qcdr(v_35124);
    goto v_34596;
v_34597:
    goto v_34593;
v_34594:
    goto v_34595;
v_34596:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_34589;
v_34590:
    goto v_34586;
v_34587:
    goto v_34588;
v_34589:
    v_35124 = Lappend(nil, stack[0], v_35124);
    env = stack[-9];
    goto v_34581;
v_34582:
    goto v_34578;
v_34579:
    goto v_34580;
v_34581:
    v_35124 = cons(stack[-1], v_35124);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_35124);
    env = stack[-9];
    goto v_34572;
v_34573:
    v_35124 = stack[-3];
    v_35124 = qcdr(v_35124);
    fn = elt(env, 10); // simp
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_34574;
v_34575:
    goto v_34571;
v_34572:
    goto v_34573;
v_34574:
    fn = elt(env, 11); // multpfsq
    v_35125 = (*qfn2(fn))(fn, stack[0], v_35124);
    env = stack[-9];
    goto v_34566;
v_34567:
    v_35124 = stack[-5];
    goto v_34568;
v_34569:
    goto v_34565;
v_34566:
    goto v_34567;
v_34568:
    fn = elt(env, 12); // addpf
    v_35124 = (*qfn2(fn))(fn, v_35125, v_35124);
    env = stack[-9];
    stack[-5] = v_35124;
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    goto v_34551;
v_34550:
    v_35124 = stack[-5];
    goto v_34178;
v_34543:
    goto v_34339;
v_34339:
v_34179:
    v_35124 = stack[0];
    fn = elt(env, 14); // coposp
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    if (v_35124 == nil) goto v_34622;
    else goto v_34623;
v_34622:
    v_35124 = lisp_true;
    goto v_34621;
v_34623:
    goto v_34634;
v_34630:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34631;
v_34632:
    v_35124 = elt(env, 5); // indxsymmetries
    goto v_34633;
v_34634:
    goto v_34630;
v_34631:
    goto v_34632;
v_34633:
    v_35124 = get(v_35125, v_35124);
    env = stack[-9];
    v_35124 = (v_35124 == nil ? lisp_true : nil);
    goto v_34621;
    v_35124 = nil;
v_34621:
    if (v_35124 == nil) goto v_34619;
    v_35124 = stack[-3];
    if (v_35124 == nil) goto v_34642;
    goto v_34650;
v_34646:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34647;
v_34648:
    v_35124 = stack[0];
    goto v_34649;
v_34650:
    goto v_34646;
v_34647:
    goto v_34648;
v_34649:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    {
        fn = elt(env, 15); // mkupf
        return (*qfn1(fn))(fn, v_35124);
    }
v_34642:
    goto v_34662;
v_34658:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34659;
v_34660:
    goto v_34669;
v_34665:
    goto v_34675;
v_34671:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34672;
v_34673:
    v_35124 = stack[0];
    goto v_34674;
v_34675:
    goto v_34671;
v_34672:
    goto v_34673;
v_34674:
    v_35125 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_34666;
v_34667:
    v_35124 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34668;
v_34669:
    goto v_34665;
v_34666:
    goto v_34667;
v_34668:
    fn = elt(env, 16); // mksq
    v_35124 = (*qfn2(fn))(fn, v_35125, v_35124);
    env = stack[-9];
    goto v_34661;
v_34662:
    goto v_34658;
v_34659:
    goto v_34660;
v_34661:
    v_35124 = cons(stack[-1], v_35124);
    return ncons(v_35124);
    v_35124 = nil;
    goto v_34178;
v_34619:
    v_35124 = stack[0];
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34689;
    else goto v_34690;
v_34689:
    v_35124 = nil;
    goto v_34684;
v_34690:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35125 = v_35124;
    v_35124 = v_35125;
    if (!consp(v_35124)) goto v_34699;
    else goto v_34700;
v_34699:
    v_35124 = v_35125;
    goto v_34698;
v_34700:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    goto v_34698;
    v_35124 = nil;
v_34698:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    stack[-1] = v_35124;
    stack[-2] = v_35124;
v_34685:
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34712;
    else goto v_34713;
v_34712:
    v_35124 = stack[-2];
    goto v_34684;
v_34713:
    goto v_34721;
v_34717:
    stack[0] = stack[-1];
    goto v_34718;
v_34719:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35125 = v_35124;
    v_35124 = v_35125;
    if (!consp(v_35124)) goto v_34729;
    else goto v_34730;
v_34729:
    v_35124 = v_35125;
    goto v_34728;
v_34730:
    v_35124 = v_35125;
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    goto v_34728;
    v_35124 = nil;
v_34728:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    goto v_34720;
v_34721:
    goto v_34717;
v_34718:
    goto v_34719;
v_34720:
    v_35124 = Lrplacd(nil, stack[0], v_35124);
    env = stack[-9];
    v_35124 = stack[-1];
    v_35124 = qcdr(v_35124);
    stack[-1] = v_35124;
    goto v_34685;
v_34684:
    stack[0] = v_35124;
    goto v_34746;
v_34742:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34743;
v_34744:
    v_35124 = stack[0];
    goto v_34745;
v_34746:
    goto v_34742;
v_34743:
    goto v_34744;
v_34745:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    fn = elt(env, 17); // indexsymmetrize
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    stack[0] = v_35124;
    v_35124 = stack[0];
    if (v_35124 == nil) goto v_34752;
    else goto v_34753;
v_34752:
    v_35124 = nil;
    goto v_34178;
v_34753:
    goto v_34764;
v_34760:
    v_35124 = stack[0];
    v_35125 = qcar(v_35124);
    goto v_34761;
v_34762:
    v_35124 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_34763;
v_34764:
    goto v_34760;
v_34761:
    goto v_34762;
v_34763:
    if (v_35125 == v_35124) goto v_34758;
    else goto v_34759;
v_34758:
    v_35124 = lisp_true;
    stack[-5] = v_35124;
    goto v_34757;
v_34759:
v_34757:
    v_35124 = stack[0];
    v_35124 = qcdr(v_35124);
    v_35124 = qcdr(v_35124);
    stack[0] = v_35124;
    goto v_34781;
v_34777:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_34778;
v_34779:
    v_35124 = elt(env, 4); // covariant
    goto v_34780;
v_34781:
    goto v_34777;
v_34778:
    goto v_34779;
v_34780:
    v_35124 = Lflagp(nil, v_35125, v_35124);
    env = stack[-9];
    if (v_35124 == nil) goto v_34775;
    v_35124 = stack[0];
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34794;
    else goto v_34795;
v_34794:
    v_35124 = nil;
    goto v_34789;
v_34795:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35126 = v_35124;
    goto v_34810;
v_34806:
    v_35125 = v_35126;
    goto v_34807;
v_34808:
    v_35124 = stack[-8];
    goto v_34809;
v_34810:
    goto v_34806;
v_34807:
    goto v_34808;
v_34809:
    v_35124 = Lmemq(nil, v_35125, v_35124);
    if (v_35124 == nil) goto v_34805;
    v_35124 = v_35126;
    goto v_34803;
v_34805:
    goto v_34822;
v_34818:
    v_35124 = elt(env, 2); // minus
    goto v_34819;
v_34820:
    v_35125 = v_35126;
    goto v_34821;
v_34822:
    goto v_34818;
v_34819:
    goto v_34820;
v_34821:
    v_35124 = list2(v_35124, v_35125);
    env = stack[-9];
    goto v_34803;
    v_35124 = nil;
v_34803:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    stack[-1] = v_35124;
    stack[-2] = v_35124;
v_34790:
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34829;
    else goto v_34830;
v_34829:
    v_35124 = stack[-2];
    goto v_34789;
v_34830:
    goto v_34838;
v_34834:
    stack[0] = stack[-1];
    goto v_34835;
v_34836:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35126 = v_35124;
    goto v_34852;
v_34848:
    v_35125 = v_35126;
    goto v_34849;
v_34850:
    v_35124 = stack[-8];
    goto v_34851;
v_34852:
    goto v_34848;
v_34849:
    goto v_34850;
v_34851:
    v_35124 = Lmemq(nil, v_35125, v_35124);
    if (v_35124 == nil) goto v_34847;
    v_35124 = v_35126;
    goto v_34845;
v_34847:
    goto v_34864;
v_34860:
    v_35124 = elt(env, 2); // minus
    goto v_34861;
v_34862:
    v_35125 = v_35126;
    goto v_34863;
v_34864:
    goto v_34860;
v_34861:
    goto v_34862;
v_34863:
    v_35124 = list2(v_35124, v_35125);
    env = stack[-9];
    goto v_34845;
    v_35124 = nil;
v_34845:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    goto v_34837;
v_34838:
    goto v_34834;
v_34835:
    goto v_34836;
v_34837:
    v_35124 = Lrplacd(nil, stack[0], v_35124);
    env = stack[-9];
    v_35124 = stack[-1];
    v_35124 = qcdr(v_35124);
    stack[-1] = v_35124;
    goto v_34790;
v_34789:
    stack[0] = v_35124;
    goto v_34773;
v_34775:
    v_35124 = qvalue(elt(env, 3)); // metricu!*
    if (v_35124 == nil) goto v_34873;
    else goto v_34874;
v_34873:
    v_35124 = stack[-7];
    v_35124 = qcdr(v_35124);
    v_35124 = qcar(v_35124);
    v_35124 = (consp(v_35124) ? nil : lisp_true);
    v_35124 = (v_35124 == nil ? lisp_true : nil);
    goto v_34872;
v_34874:
    v_35124 = nil;
    goto v_34872;
    v_35124 = nil;
v_34872:
    if (v_35124 == nil) goto v_34870;
    v_35124 = stack[0];
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34893;
    else goto v_34894;
v_34893:
    v_35124 = nil;
    goto v_34888;
v_34894:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    goto v_34906;
v_34902:
    v_35125 = elt(env, 2); // minus
    goto v_34903;
v_34904:
    goto v_34905;
v_34906:
    goto v_34902;
v_34903:
    goto v_34904;
v_34905:
    v_35124 = list2(v_35125, v_35124);
    env = stack[-9];
    v_35124 = ncons(v_35124);
    env = stack[-9];
    stack[-1] = v_35124;
    stack[-2] = v_35124;
v_34889:
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34913;
    else goto v_34914;
v_34913:
    v_35124 = stack[-2];
    goto v_34888;
v_34914:
    goto v_34922;
v_34918:
    stack[0] = stack[-1];
    goto v_34919;
v_34920:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    goto v_34933;
v_34929:
    v_35125 = elt(env, 2); // minus
    goto v_34930;
v_34931:
    goto v_34932;
v_34933:
    goto v_34929;
v_34930:
    goto v_34931;
v_34932:
    v_35124 = list2(v_35125, v_35124);
    env = stack[-9];
    v_35124 = ncons(v_35124);
    env = stack[-9];
    goto v_34921;
v_34922:
    goto v_34918;
v_34919:
    goto v_34920;
v_34921:
    v_35124 = Lrplacd(nil, stack[0], v_35124);
    env = stack[-9];
    v_35124 = stack[-1];
    v_35124 = qcdr(v_35124);
    stack[-1] = v_35124;
    goto v_34889;
v_34888:
    stack[0] = v_35124;
    goto v_34773;
v_34870:
    v_35124 = stack[0];
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34949;
    else goto v_34950;
v_34949:
    v_35124 = nil;
    goto v_34944;
v_34950:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35126 = v_35124;
    goto v_34965;
v_34961:
    v_35125 = v_35126;
    goto v_34962;
v_34963:
    v_35124 = stack[-8];
    goto v_34964;
v_34965:
    goto v_34961;
v_34962:
    goto v_34963;
v_34964:
    v_35124 = Lmemq(nil, v_35125, v_35124);
    if (v_35124 == nil) goto v_34960;
    goto v_34974;
v_34970:
    v_35124 = elt(env, 2); // minus
    goto v_34971;
v_34972:
    v_35125 = v_35126;
    goto v_34973;
v_34974:
    goto v_34970;
v_34971:
    goto v_34972;
v_34973:
    v_35124 = list2(v_35124, v_35125);
    env = stack[-9];
    goto v_34958;
v_34960:
    v_35124 = v_35126;
    goto v_34958;
    v_35124 = nil;
v_34958:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    stack[-1] = v_35124;
    stack[-2] = v_35124;
v_34945:
    v_35124 = stack[-4];
    v_35124 = qcdr(v_35124);
    stack[-4] = v_35124;
    v_35124 = stack[-4];
    if (v_35124 == nil) goto v_34984;
    else goto v_34985;
v_34984:
    v_35124 = stack[-2];
    goto v_34944;
v_34985:
    goto v_34993;
v_34989:
    stack[0] = stack[-1];
    goto v_34990;
v_34991:
    v_35124 = stack[-4];
    v_35124 = qcar(v_35124);
    v_35126 = v_35124;
    goto v_35007;
v_35003:
    v_35125 = v_35126;
    goto v_35004;
v_35005:
    v_35124 = stack[-8];
    goto v_35006;
v_35007:
    goto v_35003;
v_35004:
    goto v_35005;
v_35006:
    v_35124 = Lmemq(nil, v_35125, v_35124);
    if (v_35124 == nil) goto v_35002;
    goto v_35016;
v_35012:
    v_35124 = elt(env, 2); // minus
    goto v_35013;
v_35014:
    v_35125 = v_35126;
    goto v_35015;
v_35016:
    goto v_35012;
v_35013:
    goto v_35014;
v_35015:
    v_35124 = list2(v_35124, v_35125);
    env = stack[-9];
    goto v_35000;
v_35002:
    v_35124 = v_35126;
    goto v_35000;
    v_35124 = nil;
v_35000:
    v_35124 = ncons(v_35124);
    env = stack[-9];
    goto v_34992;
v_34993:
    goto v_34989;
v_34990:
    goto v_34991;
v_34992:
    v_35124 = Lrplacd(nil, stack[0], v_35124);
    env = stack[-9];
    v_35124 = stack[-1];
    v_35124 = qcdr(v_35124);
    stack[-1] = v_35124;
    goto v_34945;
v_34944:
    stack[0] = v_35124;
    goto v_34773;
v_34773:
    v_35124 = stack[-3];
    if (v_35124 == nil) goto v_35027;
    v_35124 = stack[-5];
    if (v_35124 == nil) goto v_35032;
    goto v_35039;
v_35035:
    goto v_35046;
v_35042:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_35043;
v_35044:
    v_35124 = stack[0];
    goto v_35045;
v_35046:
    goto v_35042;
v_35043:
    goto v_35044;
v_35045:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    fn = elt(env, 15); // mkupf
    stack[0] = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_35036;
v_35037:
    goto v_35055;
v_35051:
    v_35125 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_35052;
v_35053:
    v_35124 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35054;
v_35055:
    goto v_35051;
v_35052:
    goto v_35053;
v_35054:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_35038;
v_35039:
    goto v_35035;
v_35036:
    goto v_35037;
v_35038:
    {
        LispObject v_35136 = stack[0];
        fn = elt(env, 11); // multpfsq
        return (*qfn2(fn))(fn, v_35136, v_35124);
    }
v_35032:
    goto v_35066;
v_35062:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_35063;
v_35064:
    v_35124 = stack[0];
    goto v_35065;
v_35066:
    goto v_35062;
v_35063:
    goto v_35064;
v_35065:
    v_35124 = cons(v_35125, v_35124);
    env = stack[-9];
    {
        fn = elt(env, 15); // mkupf
        return (*qfn1(fn))(fn, v_35124);
    }
    v_35124 = nil;
    goto v_35025;
v_35027:
    v_35124 = stack[-5];
    if (v_35124 == nil) goto v_35071;
    goto v_35079;
v_35075:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35076;
v_35077:
    goto v_35087;
v_35083:
    goto v_35093;
v_35089:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_35090;
v_35091:
    v_35124 = stack[0];
    goto v_35092;
v_35093:
    goto v_35089;
v_35090:
    goto v_35091;
v_35092:
    v_35125 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_35084;
v_35085:
    v_35124 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35086;
v_35087:
    goto v_35083;
v_35084:
    goto v_35085;
v_35086:
    fn = elt(env, 16); // mksq
    v_35124 = (*qfn2(fn))(fn, v_35125, v_35124);
    env = stack[-9];
    fn = elt(env, 18); // negsq
    v_35124 = (*qfn1(fn))(fn, v_35124);
    env = stack[-9];
    goto v_35078;
v_35079:
    goto v_35075;
v_35076:
    goto v_35077;
v_35078:
    v_35124 = cons(stack[-1], v_35124);
    return ncons(v_35124);
v_35071:
    goto v_35106;
v_35102:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35103;
v_35104:
    goto v_35113;
v_35109:
    goto v_35119;
v_35115:
    v_35124 = stack[-7];
    v_35125 = qcar(v_35124);
    goto v_35116;
v_35117:
    v_35124 = stack[0];
    goto v_35118;
v_35119:
    goto v_35115;
v_35116:
    goto v_35117;
v_35118:
    v_35125 = cons(v_35125, v_35124);
    env = stack[-9];
    goto v_35110;
v_35111:
    v_35124 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35112;
v_35113:
    goto v_35109;
v_35110:
    goto v_35111;
v_35112:
    fn = elt(env, 16); // mksq
    v_35124 = (*qfn2(fn))(fn, v_35125, v_35124);
    env = stack[-9];
    goto v_35105;
v_35106:
    goto v_35102;
v_35103:
    goto v_35104;
v_35105:
    v_35124 = cons(stack[-1], v_35124);
    return ncons(v_35124);
    v_35124 = nil;
v_35025:
v_34178:
    return onevalue(v_35124);
}



// Code for dvertex!-to!-projector

static LispObject CC_dvertexKtoKprojector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34260, v_34261, v_34262;
    LispObject fn;
    LispObject v_34170, v_34169, v_34168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvertex-to-projector");
    va_start(aa, nargs);
    v_34168 = va_arg(aa, LispObject);
    v_34169 = va_arg(aa, LispObject);
    v_34170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34170,v_34169,v_34168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34168,v_34169,v_34170);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34170;
    stack[-1] = v_34169;
    stack[-2] = v_34168;
// end of prologue
    goto v_34186;
v_34180:
    v_34260 = stack[-2];
    v_34260 = qcdr(v_34260);
    v_34262 = qcar(v_34260);
    goto v_34181;
v_34182:
    v_34261 = stack[-1];
    goto v_34183;
v_34184:
    v_34260 = stack[0];
    goto v_34185;
v_34186:
    goto v_34180;
v_34181:
    goto v_34182;
v_34183:
    goto v_34184;
v_34185:
    fn = elt(env, 2); // mktails
    v_34260 = (*qfnn(fn))(fn, 3, v_34262, v_34261, v_34260);
    env = stack[-4];
    stack[-3] = v_34260;
    v_34260 = stack[-3];
    v_34260 = qcar(v_34260);
    fn = elt(env, 3); // repeatsp
    v_34260 = (*qfn1(fn))(fn, v_34260);
    env = stack[-4];
    if (v_34260 == nil) goto v_34195;
    v_34260 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34177;
v_34195:
    goto v_34207;
v_34201:
    v_34260 = stack[-2];
    v_34260 = qcdr(v_34260);
    v_34260 = qcdr(v_34260);
    v_34262 = qcar(v_34260);
    goto v_34202;
v_34203:
    v_34261 = stack[-1];
    goto v_34204;
v_34205:
    v_34260 = stack[-3];
    v_34260 = qcdr(v_34260);
    goto v_34206;
v_34207:
    goto v_34201;
v_34202:
    goto v_34203;
v_34204:
    goto v_34205;
v_34206:
    fn = elt(env, 2); // mktails
    v_34260 = (*qfnn(fn))(fn, 3, v_34262, v_34261, v_34260);
    env = stack[-4];
    stack[-1] = v_34260;
    v_34260 = stack[-1];
    v_34260 = qcar(v_34260);
    fn = elt(env, 3); // repeatsp
    v_34260 = (*qfn1(fn))(fn, v_34260);
    env = stack[-4];
    if (v_34260 == nil) goto v_34218;
    v_34260 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34177;
v_34218:
    v_34260 = stack[-1];
    v_34260 = qcdr(v_34260);
    stack[0] = v_34260;
    goto v_34230;
v_34226:
    v_34260 = stack[-3];
    stack[-2] = qcar(v_34260);
    goto v_34227;
v_34228:
    v_34260 = stack[-1];
    v_34260 = qcar(v_34260);
    v_34260 = Lreverse(nil, v_34260);
    env = stack[-4];
    goto v_34229;
v_34230:
    goto v_34226;
v_34227:
    goto v_34228;
v_34229:
    fn = elt(env, 4); // prop!-simp
    v_34260 = (*qfn2(fn))(fn, stack[-2], v_34260);
    env = stack[-4];
    stack[-2] = v_34260;
    v_34260 = stack[-2];
    fn = elt(env, 5); // mk!-contract!-coeff
    v_34260 = (*qfn1(fn))(fn, v_34260);
    env = stack[-4];
    goto v_34243;
v_34239:
    stack[-1] = v_34260;
    goto v_34240;
v_34241:
    goto v_34252;
v_34246:
    v_34260 = stack[-2];
    v_34260 = qcdr(v_34260);
    v_34262 = qcar(v_34260);
    goto v_34247;
v_34248:
    v_34260 = stack[-2];
    v_34260 = qcdr(v_34260);
    v_34261 = qcdr(v_34260);
    goto v_34249;
v_34250:
    v_34260 = stack[0];
    goto v_34251;
v_34252:
    goto v_34246;
v_34247:
    goto v_34248;
v_34249:
    goto v_34250;
v_34251:
    fn = elt(env, 6); // dpropagator
    v_34260 = (*qfnn(fn))(fn, 3, v_34262, v_34261, v_34260);
    goto v_34242;
v_34243:
    goto v_34239;
v_34240:
    goto v_34241;
v_34242:
    {
        LispObject v_34267 = stack[-1];
        return cons(v_34267, v_34260);
    }
v_34177:
    return onevalue(v_34260);
}



setup_type const u57_setup[] =
{
    {"unshift",                 CC_unshift,     TOO_MANY_1,    WRONG_NO_1},
    {"physopplus",              CC_physopplus,  TOO_MANY_1,    WRONG_NO_1},
    {"bassoc",                  TOO_FEW_2,      CC_bassoc,     WRONG_NO_2},
    {"*sq2fourier",             CC_Hsq2fourier, TOO_MANY_1,    WRONG_NO_1},
    {"all_index_lst",           CC_all_index_lst,TOO_MANY_1,   WRONG_NO_1},
    {"sc_create",               CC_sc_create,   TOO_MANY_1,    WRONG_NO_1},
    {"change+sq+to+int",        CC_changeLsqLtoLint,TOO_MANY_1,WRONG_NO_1},
    {"qqe_simpat",              CC_qqe_simpat,  TOO_MANY_1,    WRONG_NO_1},
    {"operator",                CC_operator,    TOO_MANY_1,    WRONG_NO_1},
    {"cr:minusp",               CC_crTminusp,   TOO_MANY_1,    WRONG_NO_1},
    {"expttermp",               TOO_FEW_2,      CC_expttermp,  WRONG_NO_2},
    {"xpndwedge",               CC_xpndwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"acmemb",                  TOO_FEW_2,      CC_acmemb,     WRONG_NO_2},
    {"noncom1",                 CC_noncom1,     TOO_MANY_1,    WRONG_NO_1},
    {"rationalizef",            CC_rationalizef,TOO_MANY_1,    WRONG_NO_1},
    {"red_extract",             CC_red_extract, TOO_MANY_1,    WRONG_NO_1},
    {"lowestdeg",               TOO_FEW_2,      CC_lowestdeg,  WRONG_NO_2},
    {"radd",                    TOO_FEW_2,      CC_radd,       WRONG_NO_2},
    {"no_of_tm_sf",             CC_no_of_tm_sf, TOO_MANY_1,    WRONG_NO_1},
    {"add-to-sorted-tree",      TOO_FEW_2,      CC_addKtoKsortedKtree,WRONG_NO_2},
    {"giminusp:",               CC_giminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"uterm",                   TOO_FEW_2,      CC_uterm,      WRONG_NO_2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,TOO_MANY_1,WRONG_NO_1},
    {"dip_comp1",               TOO_FEW_2,      CC_dip_comp1,  WRONG_NO_2},
    {"search4facf",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_search4facf},
    {"subsubf",                 TOO_FEW_2,      CC_subsubf,    WRONG_NO_2},
    {"row_dim",                 CC_row_dim,     TOO_MANY_1,    WRONG_NO_1},
    {"r2speclist",              CC_r2speclist,  TOO_MANY_1,    WRONG_NO_1},
    {"all_defined",             TOO_FEW_2,      CC_all_defined,WRONG_NO_2},
    {"simprd",                  CC_simprd,      TOO_MANY_1,    WRONG_NO_1},
    {"gak",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gak},
    {"anu_mk",                  TOO_FEW_2,      CC_anu_mk,     WRONG_NO_2},
    {"opfchk!",                 CC_opfchkB,     TOO_MANY_1,    WRONG_NO_1},
    {"constant_expr_listp",     CC_constant_expr_listp,TOO_MANY_1,WRONG_NO_1},
    {"talp_nextt",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_nextt},
    {"dip_reduceconti",         TOO_FEW_2,      CC_dip_reduceconti,WRONG_NO_2},
    {"poly-remainder",          CC_polyKremainder,TOO_MANY_1,  WRONG_NO_1},
    {"xriterion_2",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_2},
    {"evalsubset",              TOO_FEW_2,      CC_evalsubset, WRONG_NO_2},
    {"preproc",                 CC_preproc,     TOO_MANY_1,    WRONG_NO_1},
    {"partitindexvar",          CC_partitindexvar,TOO_MANY_1,  WRONG_NO_1},
    {"dvertex-to-projector",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvertexKtoKprojector},
    {NULL, (one_args *)"u57", (two_args *)"180158 5268792 3413595", 0}
};

// end of generated code
