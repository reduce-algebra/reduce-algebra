
// $destdir/u03.c        Machine generated C code

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



// Code for get_content

static LispObject CC_get_content(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_877, v_878;
    LispObject fn;
    argcheck(nargs, 0, "get_content");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    v_877 = nil;
    stack[-1] = v_877;
v_763:
    goto v_776;
v_772:
    v_878 = Lreadch(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_878; // ch
    goto v_773;
v_774:
    v_877 = elt(env, 2); // !<
    goto v_775;
v_776:
    goto v_772;
v_773:
    goto v_774;
v_775:
    if (v_878 == v_877) goto v_771;
    goto v_784;
v_780:
    v_878 = qvalue(elt(env, 1)); // ch
    goto v_781;
v_782:
    v_877 = qvalue(elt(env, 3)); // !$eof!$
    goto v_783;
v_784:
    goto v_780;
v_781:
    goto v_782;
v_783:
    v_877 = Lneq(nil, v_878, v_877);
    env = stack[-2];
    goto v_769;
v_771:
    v_877 = nil;
    goto v_769;
    v_877 = nil;
v_769:
    if (v_877 == nil) goto v_766;
    else goto v_767;
v_766:
    goto v_762;
v_767:
    goto v_799;
v_795:
    stack[0] = qvalue(elt(env, 1)); // ch
    goto v_796;
v_797:
    v_877 = (LispObject)160+TAG_FIXNUM; // 10
    v_877 = ncons(v_877);
    env = stack[-2];
    fn = elt(env, 7); // list2string
    v_877 = (*qfn1(fn))(fn, v_877);
    env = stack[-2];
    v_877 = Lintern(nil, v_877);
    env = stack[-2];
    goto v_798;
v_799:
    goto v_795;
v_796:
    goto v_797;
v_798:
    if (equal(stack[0], v_877)) goto v_794;
    goto v_810;
v_806:
    v_878 = qvalue(elt(env, 1)); // ch
    goto v_807;
v_808:
    v_877 = stack[-1];
    goto v_809;
v_810:
    goto v_806;
v_807:
    goto v_808;
v_809:
    v_877 = cons(v_878, v_877);
    env = stack[-2];
    stack[-1] = v_877;
    goto v_792;
v_794:
v_792:
    goto v_763;
v_762:
    goto v_818;
v_814:
    v_878 = elt(env, 4); // ! 
    goto v_815;
v_816:
    v_877 = stack[-1];
    goto v_817;
v_818:
    goto v_814;
v_815:
    goto v_816;
v_817:
    fn = elt(env, 8); // delall
    v_877 = (*qfn2(fn))(fn, v_878, v_877);
    env = stack[-2];
    stack[0] = v_877;
    v_877 = stack[0];
    if (v_877 == nil) goto v_823;
    else goto v_824;
v_823:
    v_877 = nil;
    stack[-1] = v_877;
    goto v_822;
v_824:
    goto v_841;
v_837:
    v_877 = stack[0];
    v_878 = qcar(v_877);
    goto v_838;
v_839:
    v_877 = elt(env, 5); // !"
    goto v_840;
v_841:
    goto v_837;
v_838:
    goto v_839;
v_840:
    if (v_878 == v_877) goto v_836;
    goto v_850;
v_846:
    v_877 = stack[0];
    v_877 = Lreverse(nil, v_877);
    env = stack[-2];
    v_878 = qcar(v_877);
    goto v_847;
v_848:
    v_877 = elt(env, 5); // !"
    goto v_849;
v_850:
    goto v_846;
v_847:
    goto v_848;
v_849:
    v_877 = Lneq(nil, v_878, v_877);
    env = stack[-2];
    goto v_834;
v_836:
    v_877 = nil;
    goto v_834;
    v_877 = nil;
v_834:
    if (v_877 == nil) goto v_832;
    v_877 = stack[0];
    stack[-1] = v_877;
    goto v_830;
v_832:
    v_877 = stack[-1];
        return Lreverse(nil, v_877);
v_830:
    goto v_822;
v_822:
    v_877 = stack[-1];
    if (v_877 == nil) goto v_866;
    goto v_873;
v_869:
    v_878 = elt(env, 6); // !$
    goto v_870;
v_871:
    v_877 = stack[-1];
    goto v_872;
v_873:
    goto v_869;
v_870:
    goto v_871;
v_872:
    v_877 = cons(v_878, v_877);
    stack[-1] = v_877;
    goto v_864;
v_866:
v_864:
    v_877 = stack[-1];
    return onevalue(v_877);
}



// Code for !:zerop

static LispObject CC_Tzerop(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_794, v_795, v_796;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_795 = v_755;
// end of prologue
    v_794 = v_795;
    if (v_794 == nil) goto v_763;
    else goto v_764;
v_763:
    v_794 = lisp_true;
    goto v_762;
v_764:
    goto v_773;
v_769:
    v_796 = v_795;
    goto v_770;
v_771:
    v_794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_772;
v_773:
    goto v_769;
v_770:
    goto v_771;
v_772:
    v_794 = (v_796 == v_794 ? lisp_true : nil);
    goto v_762;
    v_794 = nil;
v_762:
    if (v_794 == nil) goto v_760;
    v_794 = lisp_true;
    goto v_758;
v_760:
    v_794 = v_795;
    if (!consp(v_794)) goto v_778;
    else goto v_779;
v_778:
    v_794 = nil;
    goto v_758;
v_779:
    goto v_789;
v_785:
    v_794 = v_795;
    v_794 = qcar(v_794);
    if (!symbolp(v_794)) v_794 = nil;
    else { v_794 = qfastgets(v_794);
           if (v_794 != nil) { v_794 = elt(v_794, 15); // zerop
#ifdef RECORD_GET
             if (v_794 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v_794 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v_794 == SPID_NOPROP) v_794 = nil; }}
#endif
    goto v_786;
v_787:
    goto v_788;
v_789:
    goto v_785;
v_786:
    goto v_787;
v_788:
        return Lapply1(nil, v_794, v_795);
    v_794 = nil;
v_758:
    return onevalue(v_794);
}



// Code for rd!:zerop

static LispObject CC_rdTzerop(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_778, v_779;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_778 = v_755;
// end of prologue
    v_779 = v_778;
    v_779 = qcdr(v_779);
    if (!consp(v_779)) goto v_759;
    else goto v_760;
v_759:
    v_778 = qcdr(v_778);
        return Lzerop(nil, v_778);
v_760:
    goto v_772;
v_768:
    v_778 = qcdr(v_778);
    v_779 = qcar(v_778);
    goto v_769;
v_770:
    v_778 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_771;
v_772:
    goto v_768;
v_769:
    goto v_770;
v_771:
    v_778 = (v_779 == v_778 ? lisp_true : nil);
    goto v_758;
    v_778 = nil;
v_758:
    return onevalue(v_778);
}



// Code for wedgepf2

static LispObject CC_wedgepf2(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_817, v_818;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_756;
    stack[-2] = v_755;
// end of prologue
    v_817 = stack[-2];
    if (v_817 == nil) goto v_764;
    else goto v_765;
v_764:
    v_817 = lisp_true;
    goto v_763;
v_765:
    v_817 = stack[-1];
    v_817 = (v_817 == nil ? lisp_true : nil);
    goto v_763;
    v_817 = nil;
v_763:
    if (v_817 == nil) goto v_761;
    v_817 = nil;
    goto v_759;
v_761:
    goto v_780;
v_776:
    goto v_786;
v_782:
    v_817 = stack[-2];
    v_818 = qcar(v_817);
    goto v_783;
v_784:
    v_817 = stack[-1];
    v_817 = qcar(v_817);
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    fn = elt(env, 1); // wedget2
    stack[-3] = (*qfn2(fn))(fn, v_818, v_817);
    env = stack[-4];
    goto v_777;
v_778:
    goto v_796;
v_792:
    goto v_802;
v_798:
    v_817 = stack[-2];
    v_817 = qcar(v_817);
    v_818 = ncons(v_817);
    env = stack[-4];
    goto v_799;
v_800:
    v_817 = stack[-1];
    v_817 = qcdr(v_817);
    goto v_801;
v_802:
    goto v_798;
v_799:
    goto v_800;
v_801:
    stack[0] = CC_wedgepf2(elt(env, 0), v_818, v_817);
    env = stack[-4];
    goto v_793;
v_794:
    goto v_813;
v_809:
    v_817 = stack[-2];
    v_818 = qcdr(v_817);
    goto v_810;
v_811:
    v_817 = stack[-1];
    goto v_812;
v_813:
    goto v_809;
v_810:
    goto v_811;
v_812:
    v_817 = CC_wedgepf2(elt(env, 0), v_818, v_817);
    env = stack[-4];
    goto v_795;
v_796:
    goto v_792;
v_793:
    goto v_794;
v_795:
    fn = elt(env, 2); // addpf
    v_817 = (*qfn2(fn))(fn, stack[0], v_817);
    env = stack[-4];
    goto v_779;
v_780:
    goto v_776;
v_777:
    goto v_778;
v_779:
    {
        LispObject v_823 = stack[-3];
        fn = elt(env, 2); // addpf
        return (*qfn2(fn))(fn, v_823, v_817);
    }
    v_817 = nil;
v_759:
    return onevalue(v_817);
}



// Code for !*physopp!*

static LispObject CC_HphysoppH(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_764;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    v_764 = stack[0];
    fn = elt(env, 1); // physopp!*
    v_764 = (*qfn1(fn))(fn, v_764);
    env = stack[-1];
    if (v_764 == nil) goto v_759;
    else goto v_758;
v_759:
    v_764 = stack[0];
    {
        fn = elt(env, 2); // getphystype
        return (*qfn1(fn))(fn, v_764);
    }
v_758:
    return onevalue(v_764);
}



// Code for union_edges

static LispObject CC_union_edges(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_782, v_783, v_784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_782 = v_756;
    v_783 = v_755;
// end of prologue
v_761:
    v_784 = v_783;
    if (v_784 == nil) goto v_764;
    else goto v_765;
v_764:
    goto v_760;
v_765:
    v_784 = v_783;
    v_784 = qcdr(v_784);
    stack[0] = v_784;
    goto v_777;
v_773:
    v_783 = qcar(v_783);
    goto v_774;
v_775:
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    fn = elt(env, 1); // union_edge
    v_782 = (*qfn2(fn))(fn, v_783, v_782);
    env = stack[-1];
    v_783 = stack[0];
    goto v_761;
    v_782 = nil;
v_760:
    return onevalue(v_782);
}



// Code for errorp

static LispObject CC_errorp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_767, v_768;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_767 = v_755;
// end of prologue
    v_768 = v_767;
    if (!consp(v_768)) goto v_759;
    else goto v_760;
v_759:
    v_767 = lisp_true;
    goto v_758;
v_760:
    v_767 = qcdr(v_767);
    goto v_758;
    v_767 = nil;
v_758:
    return onevalue(v_767);
}



// Code for cdiv

static LispObject CC_cdiv(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_768, v_769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_768 = v_756;
    v_769 = v_755;
// end of prologue
    goto v_764;
v_760:
    goto v_761;
v_762:
    goto v_763;
v_764:
    goto v_760;
v_761:
    goto v_762;
v_763:
    v_768 = cons(v_769, v_768);
    env = stack[0];
    fn = elt(env, 1); // resimp
    v_768 = (*qfn1(fn))(fn, v_768);
    v_768 = qcar(v_768);
    return onevalue(v_768);
}



// Code for add_prin_char

static LispObject CC_add_prin_char(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_813, v_814, v_815;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_813 = qvalue(elt(env, 1)); // !*nat
    if (v_813 == nil) goto v_760;
    else goto v_761;
v_760:
    v_813 = stack[-1];
    v_813 = Lstringp(nil, v_813);
    env = stack[-2];
    if (v_813 == nil) goto v_767;
    else goto v_765;
v_767:
    v_813 = stack[-1];
    if (!symbolp(v_813)) v_813 = nil;
    else { v_813 = qfastgets(v_813);
           if (v_813 != nil) { v_813 = elt(v_813, 11); // switch!*
#ifdef RECORD_GET
             if (v_813 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_813 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_813 == SPID_NOPROP) v_813 = nil; }}
#endif
    if (v_813 == nil) goto v_771;
    else goto v_765;
v_771:
    v_813 = stack[-1];
    v_813 = Ldigitp(nil, v_813);
    env = stack[-2];
    if (v_813 == nil) goto v_775;
    else goto v_765;
v_775:
    v_813 = stack[-1];
    v_813 = Lexplodec(nil, v_813);
    v_813 = qcar(v_813);
    if (!symbolp(v_813)) v_813 = nil;
    else { v_813 = qfastgets(v_813);
           if (v_813 != nil) { v_813 = elt(v_813, 11); // switch!*
#ifdef RECORD_GET
             if (v_813 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_813 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_813 == SPID_NOPROP) v_813 = nil; }}
#endif
    if (v_813 == nil) goto v_778;
    else goto v_765;
v_778:
    goto v_766;
v_765:
    v_813 = stack[-1];
        return Lprinc(nil, v_813);
v_766:
    v_813 = stack[-1];
        return Lprin(nil, v_813);
    v_813 = nil;
    goto v_759;
v_761:
    goto v_798;
v_792:
    goto v_806;
v_800:
    v_815 = qvalue(elt(env, 2)); // posn!*
    goto v_801;
v_802:
    v_814 = stack[0];
    goto v_803;
v_804:
    v_813 = qvalue(elt(env, 3)); // ycoord!*
    goto v_805;
v_806:
    goto v_800;
v_801:
    goto v_802;
v_803:
    goto v_804;
v_805:
    v_815 = acons(v_815, v_814, v_813);
    env = stack[-2];
    goto v_793;
v_794:
    v_814 = stack[-1];
    goto v_795;
v_796:
    v_813 = qvalue(elt(env, 4)); // pline!*
    goto v_797;
v_798:
    goto v_792;
v_793:
    goto v_794;
v_795:
    goto v_796;
v_797:
    v_813 = acons(v_815, v_814, v_813);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_813; // pline!*
    v_813 = stack[0];
    qvalue(elt(env, 2)) = v_813; // posn!*
    goto v_759;
    v_813 = nil;
v_759:
    return onevalue(v_813);
}



// Code for pv_multc

static LispObject CC_pv_multc(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_843, v_844, v_845;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    goto v_770;
v_766:
    v_844 = stack[0];
    goto v_767;
v_768:
    v_843 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    if (v_844 == v_843) goto v_764;
    else goto v_765;
v_764:
    v_843 = lisp_true;
    goto v_763;
v_765:
    v_843 = stack[-1];
    v_843 = (v_843 == nil ? lisp_true : nil);
    goto v_763;
    v_843 = nil;
v_763:
    if (v_843 == nil) goto v_761;
    v_843 = nil;
    goto v_759;
v_761:
    goto v_785;
v_781:
    v_844 = stack[0];
    goto v_782;
v_783:
    v_843 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_784;
v_785:
    goto v_781;
v_782:
    goto v_783;
v_784:
    if (v_844 == v_843) goto v_779;
    else goto v_780;
v_779:
    v_843 = stack[-1];
    goto v_759;
v_780:
    stack[-2] = nil;
v_796:
    v_843 = stack[-1];
    if (v_843 == nil) goto v_799;
    else goto v_800;
v_799:
    goto v_795;
v_800:
    goto v_811;
v_807:
    v_843 = stack[-1];
    v_843 = qcar(v_843);
    v_844 = qcar(v_843);
    goto v_808;
v_809:
    v_843 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_810;
v_811:
    goto v_807;
v_808:
    goto v_809;
v_810:
    if (v_844 == v_843) goto v_806;
    goto v_823;
v_817:
    goto v_829;
v_825:
    v_844 = stack[0];
    goto v_826;
v_827:
    v_843 = stack[-1];
    v_843 = qcar(v_843);
    v_843 = qcar(v_843);
    goto v_828;
v_829:
    goto v_825;
v_826:
    goto v_827;
v_828:
    v_845 = times2(v_844, v_843);
    env = stack[-3];
    goto v_818;
v_819:
    v_843 = stack[-1];
    v_843 = qcar(v_843);
    v_844 = qcdr(v_843);
    goto v_820;
v_821:
    v_843 = stack[-2];
    goto v_822;
v_823:
    goto v_817;
v_818:
    goto v_819;
v_820:
    goto v_821;
v_822:
    v_843 = acons(v_845, v_844, v_843);
    env = stack[-3];
    stack[-2] = v_843;
    goto v_804;
v_806:
v_804:
    v_843 = stack[-1];
    v_843 = qcdr(v_843);
    stack[-1] = v_843;
    goto v_796;
v_795:
    v_843 = stack[-2];
        return Lnreverse(nil, v_843);
    goto v_759;
    v_843 = nil;
v_759:
    return onevalue(v_843);
}



// Code for upbve

static LispObject CC_upbve(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_769;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    v_769 = stack[0];
    v_769 = Lupbv(nil, v_769);
    env = stack[-1];
    if (v_769 == nil) goto v_759;
    else goto v_760;
v_759:
    v_769 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_760:
    v_769 = stack[0];
    v_769 = Lupbv(nil, v_769);
    return add1(v_769);
    v_769 = nil;
v_758:
    return onevalue(v_769);
}



// Code for striptag

static LispObject CC_striptag(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_767, v_768;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_767 = v_755;
// end of prologue
    v_768 = v_767;
    if (!consp(v_768)) goto v_759;
    else goto v_760;
v_759:
    goto v_758;
v_760:
    v_767 = qcdr(v_767);
    goto v_758;
    v_767 = nil;
v_758:
    return onevalue(v_767);
}



// Code for lalr_compute_lr0_goto

static LispObject CC_lalr_compute_lr0_goto(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_800, v_801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_756;
    v_800 = v_755;
// end of prologue
    stack[-2] = nil;
    stack[0] = v_800;
v_765:
    v_800 = stack[0];
    if (v_800 == nil) goto v_769;
    else goto v_770;
v_769:
    goto v_764;
v_770:
    v_800 = stack[0];
    v_800 = qcar(v_800);
    goto v_785;
v_781:
    v_801 = v_800;
    goto v_782;
v_783:
    v_800 = stack[-1];
    goto v_784;
v_785:
    goto v_781;
v_782:
    goto v_783;
v_784:
    fn = elt(env, 1); // lalr_lr0_move_dot
    v_800 = (*qfn2(fn))(fn, v_801, v_800);
    env = stack[-3];
    v_801 = v_800;
    if (v_800 == nil) goto v_779;
    goto v_793;
v_789:
    goto v_790;
v_791:
    v_800 = stack[-2];
    goto v_792;
v_793:
    goto v_789;
v_790:
    goto v_791;
v_792:
    v_800 = cons(v_801, v_800);
    env = stack[-3];
    stack[-2] = v_800;
    goto v_777;
v_779:
v_777:
    v_800 = stack[0];
    v_800 = qcdr(v_800);
    stack[0] = v_800;
    goto v_765;
v_764:
    v_800 = stack[-2];
    {
        fn = elt(env, 2); // lalr_lr0_closure
        return (*qfn1(fn))(fn, v_800);
    }
    return onevalue(v_800);
}



// Code for toknump

static LispObject CC_toknump(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_785, v_786, v_787;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_787 = v_755;
// end of prologue
    v_785 = v_787;
    v_785 = (is_number(v_785) ? lisp_true : nil);
    if (v_785 == nil) goto v_759;
    else goto v_758;
v_759:
    goto v_771;
v_767:
    v_786 = v_787;
    goto v_768;
v_769:
    v_785 = elt(env, 1); // !:dn!:
    goto v_770;
v_771:
    goto v_767;
v_768:
    goto v_769;
v_770:
    if (!consp(v_786)) goto v_765;
    v_786 = qcar(v_786);
    if (v_786 == v_785) goto v_764;
    else goto v_765;
v_764:
    v_785 = lisp_true;
    goto v_763;
v_765:
    goto v_782;
v_778:
    v_785 = v_787;
    goto v_779;
v_780:
    v_786 = elt(env, 2); // !:int!:
    goto v_781;
v_782:
    goto v_778;
v_779:
    goto v_780;
v_781:
        return Leqcar(nil, v_785, v_786);
    v_785 = nil;
v_763:
v_758:
    return onevalue(v_785);
}



// Code for symbollessp

static LispObject CC_symbollessp(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_790, v_791, v_792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
// copy arguments values to proper place
    v_791 = v_756;
    v_792 = v_755;
// end of prologue
    v_790 = v_791;
    if (v_790 == nil) goto v_760;
    else goto v_761;
v_760:
    v_790 = nil;
    goto v_759;
v_761:
    v_790 = v_792;
    if (v_790 == nil) goto v_764;
    else goto v_765;
v_764:
    v_790 = lisp_true;
    goto v_759;
v_765:
    v_790 = qvalue(elt(env, 1)); // wukord!*
    if (v_790 == nil) goto v_769;
    goto v_776;
v_772:
    v_790 = v_792;
    goto v_773;
v_774:
    goto v_775;
v_776:
    goto v_772;
v_773:
    goto v_774;
v_775:
    {
        fn = elt(env, 2); // wuorderp
        return (*qfn2(fn))(fn, v_790, v_791);
    }
v_769:
    goto v_786;
v_782:
    v_790 = v_792;
    goto v_783;
v_784:
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    v_790 = Lorderp(nil, v_790, v_791);
    v_790 = (v_790 == nil ? lisp_true : nil);
    goto v_759;
    v_790 = nil;
v_759:
    return onevalue(v_790);
}



// Code for lt!*

static LispObject CC_ltH(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_825, v_826, v_827;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_755;
// end of prologue
    v_825 = qvalue(elt(env, 1)); // !*mcd
    if (v_825 == nil) goto v_761;
    else goto v_759;
v_761:
    goto v_769;
v_765:
    v_825 = stack[-1];
    v_825 = qcar(v_825);
    v_825 = qcar(v_825);
    v_826 = qcdr(v_825);
    goto v_766;
v_767:
    v_825 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_768;
v_769:
    goto v_765;
v_766:
    goto v_767;
v_768:
    v_825 = (LispObject)greaterp2(v_826, v_825);
    v_825 = v_825 ? lisp_true : nil;
    env = stack[-3];
    if (v_825 == nil) goto v_763;
    else goto v_759;
v_763:
    goto v_760;
v_759:
    v_825 = stack[-1];
    v_825 = qcar(v_825);
    goto v_758;
v_760:
    v_825 = stack[-1];
    v_825 = qcar(v_825);
    stack[-2] = v_825;
    v_825 = stack[-1];
    v_825 = qcar(v_825);
    v_825 = qcar(v_825);
    v_825 = qcar(v_825);
    stack[0] = v_825;
v_783:
    v_825 = stack[-1];
    v_825 = qcdr(v_825);
    stack[-1] = v_825;
    v_825 = stack[-1];
    if (v_825 == nil) goto v_794;
    else goto v_795;
v_794:
    v_825 = stack[-2];
    goto v_782;
v_795:
    goto v_804;
v_800:
    goto v_810;
v_806:
    v_826 = stack[-1];
    goto v_807;
v_808:
    v_825 = stack[0];
    goto v_809;
v_810:
    goto v_806;
v_807:
    goto v_808;
v_809:
    fn = elt(env, 2); // degr
    v_826 = (*qfn2(fn))(fn, v_826, v_825);
    env = stack[-3];
    goto v_801;
v_802:
    v_825 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_803;
v_804:
    goto v_800;
v_801:
    goto v_802;
v_803:
    if (v_826 == v_825) goto v_798;
    else goto v_799;
v_798:
    goto v_821;
v_815:
    v_827 = stack[0];
    goto v_816;
v_817:
    v_826 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_818;
v_819:
    v_825 = stack[-1];
    goto v_820;
v_821:
    goto v_815;
v_816:
    goto v_817;
v_818:
    goto v_819;
v_820:
    return acons(v_827, v_826, v_825);
v_799:
    goto v_783;
v_782:
    goto v_758;
    v_825 = nil;
v_758:
    return onevalue(v_825);
}



// Code for nocp

static LispObject CC_nocp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
v_754:
    v_779 = stack[0];
    if (v_779 == nil) goto v_759;
    else goto v_760;
v_759:
    v_779 = lisp_true;
    goto v_758;
v_760:
    v_779 = stack[0];
    v_779 = qcar(v_779);
    v_779 = qcar(v_779);
    fn = elt(env, 1); // noncomp
    v_779 = (*qfn1(fn))(fn, v_779);
    env = stack[-1];
    if (v_779 == nil) goto v_767;
    else goto v_768;
v_767:
    v_779 = nil;
    goto v_766;
v_768:
    v_779 = stack[0];
    v_779 = qcdr(v_779);
    stack[0] = v_779;
    goto v_754;
    v_779 = nil;
v_766:
    goto v_758;
    v_779 = nil;
v_758:
    return onevalue(v_779);
}



// Code for subs2f

static LispObject CC_subs2f(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_836, v_837, v_838;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    goto v_769;
v_765:
    v_837 = qvalue(elt(env, 1)); // simpcount!*
    goto v_766;
v_767:
    v_836 = qvalue(elt(env, 2)); // simplimit!*
    goto v_768;
v_769:
    goto v_765;
v_766:
    goto v_767;
v_768:
    v_836 = (LispObject)greaterp2(v_837, v_836);
    v_836 = v_836 ? lisp_true : nil;
    env = stack[-2];
    if (v_836 == nil) goto v_763;
    v_836 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_836; // simpcount!*
    goto v_780;
v_774:
    v_838 = elt(env, 3); // poly
    goto v_775;
v_776:
    v_837 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_777;
v_778:
    v_836 = elt(env, 4); // "Simplification recursion too deep"
    goto v_779;
v_780:
    goto v_774;
v_775:
    goto v_776;
v_777:
    goto v_778;
v_779:
    fn = elt(env, 8); // rerror
    v_836 = (*qfnn(fn))(fn, 3, v_838, v_837, v_836);
    env = stack[-2];
    goto v_761;
v_763:
v_761:
    v_836 = qvalue(elt(env, 1)); // simpcount!*
    v_836 = add1(v_836);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_836; // simpcount!*
    v_836 = nil;
    qvalue(elt(env, 5)) = v_836; // !*sub2
    v_836 = stack[0];
    fn = elt(env, 9); // subs2f1
    v_836 = (*qfn1(fn))(fn, v_836);
    env = stack[-2];
    stack[-1] = v_836;
    v_836 = qvalue(elt(env, 5)); // !*sub2
    if (v_836 == nil) goto v_794;
    else goto v_793;
v_794:
    v_836 = qvalue(elt(env, 6)); // powlis1!*
    if (v_836 == nil) goto v_796;
    else goto v_793;
v_796:
    goto v_792;
v_793:
    v_836 = qvalue(elt(env, 7)); // !*resubs
    if (v_836 == nil) goto v_792;
    goto v_812;
v_808:
    v_836 = stack[-1];
    v_837 = qcar(v_836);
    goto v_809;
v_810:
    v_836 = stack[0];
    goto v_811;
v_812:
    goto v_808;
v_809:
    goto v_810;
v_811:
    if (equal(v_837, v_836)) goto v_806;
    else goto v_807;
v_806:
    goto v_820;
v_816:
    v_836 = stack[-1];
    v_837 = qcdr(v_836);
    goto v_817;
v_818:
    v_836 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_819;
v_820:
    goto v_816;
v_817:
    goto v_818;
v_819:
    v_836 = (v_837 == v_836 ? lisp_true : nil);
    goto v_805;
v_807:
    v_836 = nil;
    goto v_805;
    v_836 = nil;
v_805:
    if (v_836 == nil) goto v_803;
    v_836 = nil;
    qvalue(elt(env, 5)) = v_836; // !*sub2
    goto v_801;
v_803:
    v_836 = stack[-1];
    fn = elt(env, 10); // subs2q
    v_836 = (*qfn1(fn))(fn, v_836);
    env = stack[-2];
    stack[-1] = v_836;
    goto v_801;
v_801:
    goto v_790;
v_792:
v_790:
    v_836 = qvalue(elt(env, 1)); // simpcount!*
    v_836 = sub1(v_836);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_836; // simpcount!*
    v_836 = stack[-1];
    return onevalue(v_836);
}



// Code for talp_simpat

static LispObject CC_talp_simpat(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_797, v_798, v_799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_755;
// end of prologue
    goto v_770;
v_766:
    v_797 = stack[-1];
    fn = elt(env, 1); // talp_arg2l
    stack[0] = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    goto v_767;
v_768:
    v_797 = stack[-1];
    fn = elt(env, 2); // talp_arg2r
    v_797 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    fn = elt(env, 3); // talp_tordp
    v_797 = (*qfn2(fn))(fn, stack[0], v_797);
    env = stack[-3];
    if (v_797 == nil) goto v_764;
    v_797 = stack[-1];
    fn = elt(env, 1); // talp_arg2l
    v_797 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    stack[0] = v_797;
    v_797 = stack[-1];
    fn = elt(env, 2); // talp_arg2r
    v_797 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    stack[-2] = v_797;
    goto v_762;
v_764:
    v_797 = stack[-1];
    fn = elt(env, 2); // talp_arg2r
    v_797 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    stack[0] = v_797;
    v_797 = stack[-1];
    fn = elt(env, 1); // talp_arg2l
    v_797 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    stack[-2] = v_797;
    goto v_762;
v_762:
    goto v_792;
v_786:
    v_797 = stack[-1];
    fn = elt(env, 4); // talp_op
    v_799 = (*qfn1(fn))(fn, v_797);
    env = stack[-3];
    goto v_787;
v_788:
    v_798 = stack[-2];
    goto v_789;
v_790:
    v_797 = stack[0];
    goto v_791;
v_792:
    goto v_786;
v_787:
    goto v_788;
v_789:
    goto v_790;
v_791:
    {
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_799, v_798, v_797);
    }
    return onevalue(v_797);
}



// Code for pasf_susitf

static LispObject CC_pasf_susitf(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_759, v_760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_759 = v_756;
    v_760 = v_755;
// end of prologue
    v_759 = v_760;
    return onevalue(v_759);
}



// Code for gcdfd

static LispObject CC_gcdfd(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_775, v_776, v_777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_776 = v_756;
    v_777 = v_755;
// end of prologue
    v_775 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_775)) v_775 = nil;
    else { v_775 = qfastgets(v_775);
           if (v_775 != nil) { v_775 = elt(v_775, 3); // field
#ifdef RECORD_GET
             if (v_775 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_775 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_775 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_775 == SPID_NOPROP) v_775 = nil; else v_775 = lisp_true; }}
#endif
    if (v_775 == nil) goto v_761;
    v_775 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_759;
v_761:
    goto v_772;
v_768:
    v_775 = v_777;
    goto v_769;
v_770:
    goto v_771;
v_772:
    goto v_768;
v_769:
    goto v_770;
v_771:
    {
        fn = elt(env, 2); // gcdfd1
        return (*qfn2(fn))(fn, v_775, v_776);
    }
    v_775 = nil;
v_759:
    return onevalue(v_775);
}



// Code for printout

static LispObject CC_printout(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_837, v_838;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    v_837 = qvalue(elt(env, 1)); // !*web
    if (v_837 == nil) goto v_761;
    else goto v_762;
v_761:
    v_837 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_760;
v_762:
v_760:
    v_837 = qvalue(elt(env, 1)); // !*web
    if (v_837 == nil) goto v_767;
    else goto v_768;
v_767:
    v_837 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_837;
v_773:
    goto v_785;
v_781:
    v_838 = qvalue(elt(env, 2)); // indent
    goto v_782;
v_783:
    v_837 = stack[-1];
    goto v_784;
v_785:
    goto v_781;
v_782:
    goto v_783;
v_784:
    v_837 = difference2(v_838, v_837);
    env = stack[-2];
    v_837 = Lminusp(nil, v_837);
    env = stack[-2];
    if (v_837 == nil) goto v_778;
    goto v_772;
v_778:
    v_837 = elt(env, 3); // " "
    v_837 = Lprinc(nil, v_837);
    env = stack[-2];
    v_837 = stack[-1];
    v_837 = add1(v_837);
    env = stack[-2];
    stack[-1] = v_837;
    goto v_773;
v_772:
    goto v_766;
v_768:
v_766:
    v_837 = stack[0];
    v_837 = Lconsp(nil, v_837);
    env = stack[-2];
    if (v_837 == nil) goto v_796;
    goto v_811;
v_807:
    v_837 = stack[0];
    v_838 = qcar(v_837);
    goto v_808;
v_809:
    v_837 = elt(env, 4); // !:rd!:
    goto v_810;
v_811:
    goto v_807;
v_808:
    goto v_809;
v_810:
    if (v_838 == v_837) goto v_805;
    else goto v_806;
v_805:
    v_837 = lisp_true;
    goto v_804;
v_806:
    goto v_822;
v_818:
    v_837 = stack[0];
    v_838 = qcar(v_837);
    goto v_819;
v_820:
    v_837 = elt(env, 5); // !:rn!:
    goto v_821;
v_822:
    goto v_818;
v_819:
    goto v_820;
v_821:
    v_837 = (v_838 == v_837 ? lisp_true : nil);
    goto v_804;
    v_837 = nil;
v_804:
    if (v_837 == nil) goto v_802;
    v_837 = stack[0];
    fn = elt(env, 6); // ma_print
    v_837 = (*qfn1(fn))(fn, v_837);
    goto v_800;
v_802:
    v_837 = stack[0];
    v_837 = Lprinc(nil, v_837);
    goto v_800;
v_800:
    goto v_794;
v_796:
    v_837 = stack[0];
    v_837 = Lprinc(nil, v_837);
    goto v_794;
v_794:
    v_837 = nil;
    return onevalue(v_837);
}



// Code for initcomb

static LispObject CC_initcomb(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_759;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_759 = v_755;
// end of prologue
    return ncons(v_759);
}



// Code for evcompless!?

static LispObject CC_evcomplessW(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_773, v_774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_774 = v_756;
    v_773 = v_755;
// end of prologue
    goto v_762;
v_758:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_759;
v_760:
    goto v_769;
v_765:
    goto v_766;
v_767:
    goto v_768;
v_769:
    goto v_765;
v_766:
    goto v_767;
v_768:
    fn = elt(env, 1); // evcomp
    v_773 = (*qfn2(fn))(fn, v_774, v_773);
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    v_773 = (stack[0] == v_773 ? lisp_true : nil);
    return onevalue(v_773);
}



// Code for evmatrixcomp

static LispObject CC_evmatrixcomp(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_769, v_770, v_771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_769 = v_756;
    v_770 = v_755;
// end of prologue
    goto v_765;
v_759:
    v_771 = v_770;
    goto v_760;
v_761:
    v_770 = v_769;
    goto v_762;
v_763:
    v_769 = qvalue(elt(env, 1)); // vdpmatrix!*
    goto v_764;
v_765:
    goto v_759;
v_760:
    goto v_761;
v_762:
    goto v_763;
v_764:
    {
        fn = elt(env, 2); // evmatrixcomp1
        return (*qfnn(fn))(fn, 3, v_771, v_770, v_769);
    }
}



// Code for pprin2

static LispObject CC_pprin2(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_777, v_778;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    goto v_764;
v_760:
    v_778 = stack[0];
    goto v_761;
v_762:
    v_777 = qvalue(elt(env, 1)); // !*pprinbuf!*
    goto v_763;
v_764:
    goto v_760;
v_761:
    goto v_762;
v_763:
    v_777 = cons(v_778, v_777);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_777; // !*pprinbuf!*
    goto v_772;
v_768:
    stack[-1] = qvalue(elt(env, 2)); // !*posn!*
    goto v_769;
v_770:
    v_777 = stack[0];
    v_777 = Lexplodec(nil, v_777);
    env = stack[-2];
    v_777 = Llength(nil, v_777);
    env = stack[-2];
    goto v_771;
v_772:
    goto v_768;
v_769:
    goto v_770;
v_771:
    v_777 = plus2(stack[-1], v_777);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_777; // !*posn!*
    v_777 = nil;
    return onevalue(v_777);
}



// Code for opmtch!*

static LispObject CC_opmtchH(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_767, v_768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_768 = v_755;
// end of prologue
    v_767 = qvalue(elt(env, 1)); // subfg!*
    stack[0] = v_767;
    v_767 = lisp_true;
    qvalue(elt(env, 1)) = v_767; // subfg!*
    v_767 = v_768;
    fn = elt(env, 2); // opmtch
    v_767 = (*qfn1(fn))(fn, v_767);
    env = stack[-1];
    v_768 = v_767;
    v_767 = stack[0];
    qvalue(elt(env, 1)) = v_767; // subfg!*
    v_767 = v_768;
    return onevalue(v_767);
}



// Code for timesip

static LispObject CC_timesip(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_781, v_782, v_783;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_783 = v_755;
// end of prologue
    goto v_766;
v_762:
    v_782 = v_783;
    goto v_763;
v_764:
    v_781 = elt(env, 1); // times
    goto v_765;
v_766:
    goto v_762;
v_763:
    goto v_764;
v_765:
    if (!consp(v_782)) goto v_760;
    v_782 = qcar(v_782);
    if (v_782 == v_781) goto v_759;
    else goto v_760;
v_759:
    goto v_773;
v_769:
    v_781 = elt(env, 2); // i
    goto v_770;
v_771:
    v_782 = v_783;
    v_782 = qcdr(v_782);
    goto v_772;
v_773:
    goto v_769;
v_770:
    goto v_771;
v_772:
    v_781 = Lmemq(nil, v_781, v_782);
    goto v_758;
v_760:
    v_781 = nil;
    goto v_758;
    v_781 = nil;
v_758:
    return onevalue(v_781);
}



// Code for fs!:timestermterm

static LispObject CC_fsTtimestermterm(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_1097, v_1098, v_1099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_756;
    stack[-7] = v_755;
// end of prologue
    v_1097 = (LispObject)112+TAG_FIXNUM; // 7
    v_1097 = Lmkvect(nil, v_1097);
    env = stack[-9];
    stack[-8] = v_1097;
    goto v_772;
v_768:
    v_1098 = stack[-7];
    goto v_769;
v_770:
    v_1097 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_771;
v_772:
    goto v_768;
v_769:
    goto v_770;
v_771:
    v_1097 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_1097;
    goto v_780;
v_776:
    v_1098 = stack[-6];
    goto v_777;
v_778:
    v_1097 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_779;
v_780:
    goto v_776;
v_777:
    goto v_778;
v_779:
    v_1097 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_1097;
    v_1097 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_1097;
v_787:
    goto v_799;
v_795:
    v_1098 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_796;
v_797:
    v_1097 = stack[-2];
    goto v_798;
v_799:
    goto v_795;
v_796:
    goto v_797;
v_798:
    v_1097 = difference2(v_1098, v_1097);
    env = stack[-9];
    v_1097 = Lminusp(nil, v_1097);
    env = stack[-9];
    if (v_1097 == nil) goto v_792;
    goto v_786;
v_792:
    goto v_809;
v_803:
    stack[-1] = stack[-8];
    goto v_804;
v_805:
    stack[0] = stack[-2];
    goto v_806;
v_807:
    goto v_817;
v_813:
    goto v_822;
v_818:
    v_1098 = stack[-4];
    goto v_819;
v_820:
    v_1097 = stack[-2];
    goto v_821;
v_822:
    goto v_818;
v_819:
    goto v_820;
v_821:
    v_1099 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_814;
v_815:
    goto v_830;
v_826:
    v_1098 = stack[-3];
    goto v_827;
v_828:
    v_1097 = stack[-2];
    goto v_829;
v_830:
    goto v_826;
v_827:
    goto v_828;
v_829:
    v_1097 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_816;
v_817:
    goto v_813;
v_814:
    goto v_815;
v_816:
    v_1097 = plus2(v_1099, v_1097);
    env = stack[-9];
    goto v_808;
v_809:
    goto v_803;
v_804:
    goto v_805;
v_806:
    goto v_807;
v_808:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_1097;
    v_1097 = stack[-2];
    v_1097 = add1(v_1097);
    env = stack[-9];
    stack[-2] = v_1097;
    goto v_787;
v_786:
    v_1097 = (LispObject)112+TAG_FIXNUM; // 7
    v_1097 = Lmkvect(nil, v_1097);
    env = stack[-9];
    stack[-5] = v_1097;
    v_1097 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_1097;
v_841:
    goto v_853;
v_849:
    v_1098 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_850;
v_851:
    v_1097 = stack[-2];
    goto v_852;
v_853:
    goto v_849;
v_850:
    goto v_851;
v_852:
    v_1097 = difference2(v_1098, v_1097);
    env = stack[-9];
    v_1097 = Lminusp(nil, v_1097);
    env = stack[-9];
    if (v_1097 == nil) goto v_846;
    goto v_840;
v_846:
    goto v_863;
v_857:
    stack[-1] = stack[-5];
    goto v_858;
v_859:
    stack[0] = stack[-2];
    goto v_860;
v_861:
    goto v_871;
v_867:
    goto v_876;
v_872:
    v_1098 = stack[-4];
    goto v_873;
v_874:
    v_1097 = stack[-2];
    goto v_875;
v_876:
    goto v_872;
v_873:
    goto v_874;
v_875:
    v_1099 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_868;
v_869:
    goto v_884;
v_880:
    v_1098 = stack[-3];
    goto v_881;
v_882:
    v_1097 = stack[-2];
    goto v_883;
v_884:
    goto v_880;
v_881:
    goto v_882;
v_883:
    v_1097 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_870;
v_871:
    goto v_867;
v_868:
    goto v_869;
v_870:
    v_1097 = difference2(v_1099, v_1097);
    env = stack[-9];
    goto v_862;
v_863:
    goto v_857;
v_858:
    goto v_859;
v_860:
    goto v_861;
v_862:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_1097;
    v_1097 = stack[-2];
    v_1097 = add1(v_1097);
    env = stack[-9];
    stack[-2] = v_1097;
    goto v_841;
v_840:
    goto v_895;
v_891:
    goto v_900;
v_896:
    v_1098 = stack[-7];
    goto v_897;
v_898:
    v_1097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_899;
v_900:
    goto v_896;
v_897:
    goto v_898;
v_899:
    v_1099 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_892;
v_893:
    goto v_908;
v_904:
    v_1098 = stack[-6];
    goto v_905;
v_906:
    v_1097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_907;
v_908:
    goto v_904;
v_905:
    goto v_906;
v_907:
    v_1097 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_894;
v_895:
    goto v_891;
v_892:
    goto v_893;
v_894:
    fn = elt(env, 4); // multsq
    v_1097 = (*qfn2(fn))(fn, v_1099, v_1097);
    env = stack[-9];
    stack[0] = v_1097;
    goto v_917;
v_913:
    v_1098 = stack[0];
    goto v_914;
v_915:
    v_1097 = elt(env, 1); // (1 . 2)
    goto v_916;
v_917:
    goto v_913;
v_914:
    goto v_915;
v_916:
    fn = elt(env, 4); // multsq
    v_1097 = (*qfn2(fn))(fn, v_1098, v_1097);
    env = stack[-9];
    stack[0] = v_1097;
    v_1097 = stack[0];
    v_1097 = qcar(v_1097);
    if (v_1097 == nil) goto v_922;
    else goto v_923;
v_922:
    v_1097 = nil;
    goto v_765;
v_923:
    goto v_935;
v_931:
    goto v_940;
v_936:
    v_1098 = stack[-7];
    goto v_937;
v_938:
    v_1097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_939;
v_940:
    goto v_936;
v_937:
    goto v_938;
v_939:
    v_1098 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_932;
v_933:
    v_1097 = elt(env, 2); // sin
    goto v_934;
v_935:
    goto v_931;
v_932:
    goto v_933;
v_934:
    if (v_1098 == v_1097) goto v_929;
    else goto v_930;
v_929:
    goto v_953;
v_949:
    goto v_958;
v_954:
    v_1098 = stack[-6];
    goto v_955;
v_956:
    v_1097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_957;
v_958:
    goto v_954;
v_955:
    goto v_956;
v_957:
    v_1098 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_950;
v_951:
    v_1097 = elt(env, 2); // sin
    goto v_952;
v_953:
    goto v_949;
v_950:
    goto v_951;
v_952:
    if (v_1098 == v_1097) goto v_947;
    else goto v_948;
v_947:
    goto v_968;
v_964:
    goto v_976;
v_970:
    stack[-1] = elt(env, 3); // cos
    goto v_971;
v_972:
    stack[-2] = stack[-8];
    goto v_973;
v_974:
    v_1097 = stack[0];
    fn = elt(env, 5); // negsq
    v_1097 = (*qfn1(fn))(fn, v_1097);
    env = stack[-9];
    goto v_975;
v_976:
    goto v_970;
v_971:
    goto v_972;
v_973:
    goto v_974;
v_975:
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(fn, 3, stack[-1], stack[-2], v_1097);
    env = stack[-9];
    goto v_965;
v_966:
    goto v_988;
v_982:
    v_1099 = elt(env, 3); // cos
    goto v_983;
v_984:
    v_1098 = stack[-5];
    goto v_985;
v_986:
    v_1097 = stack[0];
    goto v_987;
v_988:
    goto v_982;
v_983:
    goto v_984;
v_985:
    goto v_986;
v_987:
    fn = elt(env, 6); // make!-term
    v_1097 = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_967;
v_968:
    goto v_964;
v_965:
    goto v_966;
v_967:
    {
        LispObject v_1109 = stack[-1];
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(fn, v_1109, v_1097);
    }
v_948:
    goto v_999;
v_995:
    goto v_1007;
v_1001:
    v_1099 = elt(env, 2); // sin
    goto v_1002;
v_1003:
    v_1098 = stack[-8];
    goto v_1004;
v_1005:
    v_1097 = stack[0];
    goto v_1006;
v_1007:
    goto v_1001;
v_1002:
    goto v_1003;
v_1004:
    goto v_1005;
v_1006:
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_996;
v_997:
    goto v_1018;
v_1012:
    v_1099 = elt(env, 2); // sin
    goto v_1013;
v_1014:
    v_1098 = stack[-5];
    goto v_1015;
v_1016:
    v_1097 = stack[0];
    goto v_1017;
v_1018:
    goto v_1012;
v_1013:
    goto v_1014;
v_1015:
    goto v_1016;
v_1017:
    fn = elt(env, 6); // make!-term
    v_1097 = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_998;
v_999:
    goto v_995;
v_996:
    goto v_997;
v_998:
    {
        LispObject v_1110 = stack[-1];
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(fn, v_1110, v_1097);
    }
    goto v_928;
v_930:
    goto v_1028;
v_1024:
    goto v_1033;
v_1029:
    v_1098 = stack[-6];
    goto v_1030;
v_1031:
    v_1097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1032;
v_1033:
    goto v_1029;
v_1030:
    goto v_1031;
v_1032:
    v_1098 = *(LispObject *)((char *)v_1098 + (CELL-TAG_VECTOR) + (((intptr_t)v_1097-TAG_FIXNUM)/(16/CELL)));
    goto v_1025;
v_1026:
    v_1097 = elt(env, 2); // sin
    goto v_1027;
v_1028:
    goto v_1024;
v_1025:
    goto v_1026;
v_1027:
    if (v_1098 == v_1097) goto v_1022;
    else goto v_1023;
v_1022:
    goto v_1043;
v_1039:
    goto v_1051;
v_1045:
    v_1099 = elt(env, 2); // sin
    goto v_1046;
v_1047:
    v_1098 = stack[-8];
    goto v_1048;
v_1049:
    v_1097 = stack[0];
    goto v_1050;
v_1051:
    goto v_1045;
v_1046:
    goto v_1047;
v_1048:
    goto v_1049;
v_1050:
    fn = elt(env, 6); // make!-term
    stack[-2] = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_1040;
v_1041:
    goto v_1062;
v_1056:
    stack[-1] = elt(env, 2); // sin
    goto v_1057;
v_1058:
    stack[-3] = stack[-5];
    goto v_1059;
v_1060:
    v_1097 = stack[0];
    fn = elt(env, 5); // negsq
    v_1097 = (*qfn1(fn))(fn, v_1097);
    env = stack[-9];
    goto v_1061;
v_1062:
    goto v_1056;
v_1057:
    goto v_1058;
v_1059:
    goto v_1060;
v_1061:
    fn = elt(env, 6); // make!-term
    v_1097 = (*qfnn(fn))(fn, 3, stack[-1], stack[-3], v_1097);
    env = stack[-9];
    goto v_1042;
v_1043:
    goto v_1039;
v_1040:
    goto v_1041;
v_1042:
    {
        LispObject v_1111 = stack[-2];
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(fn, v_1111, v_1097);
    }
v_1023:
    goto v_1074;
v_1070:
    goto v_1082;
v_1076:
    v_1099 = elt(env, 3); // cos
    goto v_1077;
v_1078:
    v_1098 = stack[-8];
    goto v_1079;
v_1080:
    v_1097 = stack[0];
    goto v_1081;
v_1082:
    goto v_1076;
v_1077:
    goto v_1078;
v_1079:
    goto v_1080;
v_1081:
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_1071;
v_1072:
    goto v_1093;
v_1087:
    v_1099 = elt(env, 3); // cos
    goto v_1088;
v_1089:
    v_1098 = stack[-5];
    goto v_1090;
v_1091:
    v_1097 = stack[0];
    goto v_1092;
v_1093:
    goto v_1087;
v_1088:
    goto v_1089;
v_1090:
    goto v_1091;
v_1092:
    fn = elt(env, 6); // make!-term
    v_1097 = (*qfnn(fn))(fn, 3, v_1099, v_1098, v_1097);
    env = stack[-9];
    goto v_1073;
v_1074:
    goto v_1070;
v_1071:
    goto v_1072;
v_1073:
    {
        LispObject v_1112 = stack[-1];
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(fn, v_1112, v_1097);
    }
v_928:
    v_1097 = nil;
v_765:
    return onevalue(v_1097);
}



// Code for mo_vdivides!?

static LispObject CC_mo_vdividesW(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_783, v_784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    goto v_767;
v_763:
    v_783 = stack[-1];
    fn = elt(env, 1); // mo_comp
    stack[-2] = (*qfn1(fn))(fn, v_783);
    env = stack[-3];
    goto v_764;
v_765:
    v_783 = stack[0];
    fn = elt(env, 1); // mo_comp
    v_783 = (*qfn1(fn))(fn, v_783);
    env = stack[-3];
    goto v_766;
v_767:
    goto v_763;
v_764:
    goto v_765;
v_766:
    v_783 = Leqn(nil, stack[-2], v_783);
    env = stack[-3];
    if (v_783 == nil) goto v_760;
    else goto v_761;
v_760:
    v_783 = nil;
    goto v_759;
v_761:
    goto v_780;
v_776:
    v_784 = stack[-1];
    goto v_777;
v_778:
    v_783 = stack[0];
    goto v_779;
v_780:
    goto v_776;
v_777:
    goto v_778;
v_779:
    {
        fn = elt(env, 2); // mo_divides!?
        return (*qfn2(fn))(fn, v_784, v_783);
    }
    v_783 = nil;
v_759:
    return onevalue(v_783);
}



// Code for dless

static LispObject CC_dless(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_841, v_842, v_843;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_843 = v_756;
    stack[0] = v_755;
// end of prologue
    goto v_766;
v_762:
    v_842 = qvalue(elt(env, 1)); // ordering
    goto v_763;
v_764:
    v_841 = elt(env, 2); // lex
    goto v_765;
v_766:
    goto v_762;
v_763:
    goto v_764;
v_765:
    if (v_842 == v_841) goto v_760;
    else goto v_761;
v_760:
    goto v_774;
v_770:
    v_841 = stack[0];
    goto v_771;
v_772:
    v_842 = v_843;
    goto v_773;
v_774:
    goto v_770;
v_771:
    goto v_772;
v_773:
    {
        fn = elt(env, 5); // dlesslex
        return (*qfn2(fn))(fn, v_841, v_842);
    }
v_761:
    goto v_783;
v_779:
    v_841 = stack[0];
    v_842 = qcar(v_841);
    goto v_780;
v_781:
    v_841 = v_843;
    v_841 = qcar(v_841);
    goto v_782;
v_783:
    goto v_779;
v_780:
    goto v_781;
v_782:
    if (((intptr_t)(v_842)) < ((intptr_t)(v_841))) goto v_777;
    else goto v_778;
v_777:
    v_841 = lisp_true;
    goto v_759;
v_778:
    goto v_795;
v_791:
    v_841 = stack[0];
    v_842 = qcar(v_841);
    goto v_792;
v_793:
    v_841 = v_843;
    v_841 = qcar(v_841);
    goto v_794;
v_795:
    goto v_791;
v_792:
    goto v_793;
v_794:
    if (((intptr_t)(v_842)) > ((intptr_t)(v_841))) goto v_789;
    else goto v_790;
v_789:
    v_841 = nil;
    goto v_759;
v_790:
    goto v_807;
v_803:
    v_842 = qvalue(elt(env, 1)); // ordering
    goto v_804;
v_805:
    v_841 = elt(env, 3); // glex
    goto v_806;
v_807:
    goto v_803;
v_804:
    goto v_805;
v_806:
    if (v_842 == v_841) goto v_801;
    else goto v_802;
v_801:
    goto v_815;
v_811:
    v_841 = stack[0];
    v_841 = qcdr(v_841);
    goto v_812;
v_813:
    v_842 = v_843;
    v_842 = qcdr(v_842);
    goto v_814;
v_815:
    goto v_811;
v_812:
    goto v_813;
v_814:
    {
        fn = elt(env, 5); // dlesslex
        return (*qfn2(fn))(fn, v_841, v_842);
    }
v_802:
    goto v_826;
v_822:
    v_842 = qvalue(elt(env, 1)); // ordering
    goto v_823;
v_824:
    v_841 = elt(env, 4); // grev
    goto v_825;
v_826:
    goto v_822;
v_823:
    goto v_824;
v_825:
    if (v_842 == v_841) goto v_820;
    else goto v_821;
v_820:
    goto v_834;
v_830:
    v_841 = v_843;
    v_841 = qcdr(v_841);
    stack[-1] = Lreverse(nil, v_841);
    env = stack[-2];
    goto v_831;
v_832:
    v_841 = stack[0];
    v_841 = qcdr(v_841);
    v_841 = Lreverse(nil, v_841);
    env = stack[-2];
    goto v_833;
v_834:
    goto v_830;
v_831:
    goto v_832;
v_833:
    {
        LispObject v_846 = stack[-1];
        fn = elt(env, 5); // dlesslex
        return (*qfn2(fn))(fn, v_846, v_841);
    }
v_821:
    v_841 = nil;
v_759:
    return onevalue(v_841);
}



// Code for pv_sort2

static LispObject CC_pv_sort2(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_767, v_768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_756;
    v_767 = v_755;
// end of prologue
    goto v_763;
v_759:
    v_768 = v_767;
    goto v_760;
v_761:
    v_767 = stack[0];
    goto v_762;
v_763:
    goto v_759;
v_760:
    goto v_761;
v_762:
    fn = elt(env, 1); // pv_sort2a
    v_767 = (*qfn2(fn))(fn, v_768, v_767);
    v_767 = stack[0];
    return onevalue(v_767);
}



// Code for !*i2rn

static LispObject CC_Hi2rn(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_768, v_769, v_770;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_768 = v_755;
// end of prologue
    goto v_764;
v_758:
    v_770 = elt(env, 1); // !:rn!:
    goto v_759;
v_760:
    v_769 = v_768;
    goto v_761;
v_762:
    v_768 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_763;
v_764:
    goto v_758;
v_759:
    goto v_760;
v_761:
    goto v_762;
v_763:
    return list2star(v_770, v_769, v_768);
}



// Code for lalr_propagate_lookaheads

static LispObject CC_lalr_propagate_lookaheads(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_830, v_831, v_832, v_833;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_755;
// end of prologue
v_764:
    v_830 = nil;
    v_833 = v_830;
    v_830 = stack[-2];
    stack[-1] = v_830;
v_769:
    v_830 = stack[-1];
    if (v_830 == nil) goto v_773;
    else goto v_774;
v_773:
    goto v_768;
v_774:
    v_830 = stack[-1];
    v_830 = qcar(v_830);
    v_831 = v_830;
    v_831 = qcar(v_831);
    v_830 = qcdr(v_830);
    stack[-3] = v_830;
    v_830 = v_831;
    v_830 = qcdr(v_830);
    stack[0] = v_830;
v_787:
    v_830 = stack[0];
    if (v_830 == nil) goto v_792;
    else goto v_793;
v_792:
    goto v_786;
v_793:
    v_830 = stack[0];
    v_830 = qcar(v_830);
    v_832 = v_830;
    goto v_807;
v_803:
    v_831 = v_832;
    goto v_804;
v_805:
    v_830 = stack[-3];
    v_830 = qcdr(v_830);
    goto v_806;
v_807:
    goto v_803;
v_804:
    goto v_805;
v_806:
    v_830 = Lmember(nil, v_831, v_830);
    if (v_830 == nil) goto v_801;
    else goto v_802;
v_801:
    goto v_817;
v_813:
    v_830 = stack[-3];
    goto v_814;
v_815:
    v_831 = v_832;
    goto v_816;
v_817:
    goto v_813;
v_814:
    goto v_815;
v_816:
    fn = elt(env, 1); // lalr_add_lookahead
    v_830 = (*qfn2(fn))(fn, v_830, v_831);
    env = stack[-4];
    v_830 = lisp_true;
    v_833 = v_830;
    goto v_800;
v_802:
v_800:
    v_830 = stack[0];
    v_830 = qcdr(v_830);
    stack[0] = v_830;
    goto v_787;
v_786:
    v_830 = stack[-1];
    v_830 = qcdr(v_830);
    stack[-1] = v_830;
    goto v_769;
v_768:
    v_830 = v_833;
    if (v_830 == nil) goto v_828;
    goto v_764;
v_828:
    v_830 = nil;
    return onevalue(v_830);
}



// Code for monomcomparedegrevlex

static LispObject CC_monomcomparedegrevlex(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_898, v_899, v_900;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_898;
    goto v_773;
v_769:
    goto v_778;
v_774:
    v_899 = stack[-1];
    goto v_775;
v_776:
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_777;
v_778:
    goto v_774;
v_775:
    goto v_776;
v_777:
    v_900 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    goto v_770;
v_771:
    goto v_786;
v_782:
    v_899 = stack[0];
    goto v_783;
v_784:
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    v_898 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    goto v_772;
v_773:
    goto v_769;
v_770:
    goto v_771;
v_772:
    v_898 = (LispObject)greaterp2(v_900, v_898);
    v_898 = v_898 ? lisp_true : nil;
    env = stack[-3];
    if (v_898 == nil) goto v_767;
    v_898 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_898;
    goto v_765;
v_767:
    goto v_799;
v_795:
    goto v_804;
v_800:
    v_899 = stack[-1];
    goto v_801;
v_802:
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_803;
v_804:
    goto v_800;
v_801:
    goto v_802;
v_803:
    v_900 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    goto v_796;
v_797:
    goto v_812;
v_808:
    v_899 = stack[0];
    goto v_809;
v_810:
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_811;
v_812:
    goto v_808;
v_809:
    goto v_810;
v_811:
    v_898 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    goto v_798;
v_799:
    goto v_795;
v_796:
    goto v_797;
v_798:
    v_898 = (LispObject)lessp2(v_900, v_898);
    v_898 = v_898 ? lisp_true : nil;
    env = stack[-3];
    if (v_898 == nil) goto v_793;
    v_898 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-2] = v_898;
    goto v_765;
v_793:
    goto v_824;
v_820:
    v_899 = stack[-1];
    goto v_821;
v_822:
    v_898 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_823;
v_824:
    goto v_820;
v_821:
    goto v_822;
v_823:
    v_898 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_898;
    goto v_832;
v_828:
    v_899 = stack[0];
    goto v_829;
v_830:
    v_898 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_831;
v_832:
    goto v_828;
v_829:
    goto v_830;
v_831:
    v_898 = *(LispObject *)((char *)v_899 + (CELL-TAG_VECTOR) + (((intptr_t)v_898-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_898;
v_838:
    v_898 = stack[-1];
    v_898 = qcar(v_898);
    if (v_898 == nil) goto v_841;
    else goto v_842;
v_841:
    goto v_837;
v_842:
    goto v_855;
v_851:
    v_898 = stack[-1];
    v_899 = qcar(v_898);
    goto v_852;
v_853:
    v_898 = stack[0];
    v_898 = qcar(v_898);
    goto v_854;
v_855:
    goto v_851;
v_852:
    goto v_853;
v_854:
    v_898 = (LispObject)lessp2(v_899, v_898);
    v_898 = v_898 ? lisp_true : nil;
    env = stack[-3];
    if (v_898 == nil) goto v_849;
    v_898 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_898;
    v_898 = nil;
    v_898 = ncons(v_898);
    env = stack[-3];
    stack[-1] = v_898;
    goto v_847;
v_849:
    goto v_871;
v_867:
    v_898 = stack[-1];
    v_899 = qcar(v_898);
    goto v_868;
v_869:
    v_898 = stack[0];
    v_898 = qcar(v_898);
    goto v_870;
v_871:
    goto v_867;
v_868:
    goto v_869;
v_870:
    v_898 = (LispObject)greaterp2(v_899, v_898);
    v_898 = v_898 ? lisp_true : nil;
    env = stack[-3];
    if (v_898 == nil) goto v_865;
    v_898 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-2] = v_898;
    v_898 = nil;
    v_898 = ncons(v_898);
    env = stack[-3];
    stack[-1] = v_898;
    goto v_847;
v_865:
    v_898 = stack[-1];
    v_898 = qcdr(v_898);
    stack[-1] = v_898;
    v_898 = stack[0];
    v_898 = qcdr(v_898);
    stack[0] = v_898;
    goto v_847;
v_847:
    goto v_838;
v_837:
    v_898 = stack[0];
    v_898 = qcar(v_898);
    if (v_898 == nil) goto v_890;
    else goto v_891;
v_890:
    v_898 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_898;
    goto v_889;
v_891:
v_889:
    goto v_765;
v_765:
    v_898 = stack[-2];
    return onevalue(v_898);
}



// Code for reordsq

static LispObject CC_reordsq(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    goto v_762;
v_758:
    v_769 = stack[0];
    v_769 = qcar(v_769);
    fn = elt(env, 1); // reorder
    stack[-1] = (*qfn1(fn))(fn, v_769);
    env = stack[-2];
    goto v_759;
v_760:
    v_769 = stack[0];
    v_769 = qcdr(v_769);
    fn = elt(env, 1); // reorder
    v_769 = (*qfn1(fn))(fn, v_769);
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    {
        LispObject v_772 = stack[-1];
        return cons(v_772, v_769);
    }
}



// Code for delallasc

static LispObject CC_delallasc(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_795, v_796, v_797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_797 = nil;
v_761:
    v_795 = stack[0];
    if (v_795 == nil) goto v_764;
    else goto v_765;
v_764:
    v_795 = v_797;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_795);
    }
v_765:
    goto v_775;
v_771:
    v_796 = stack[-1];
    goto v_772;
v_773:
    v_795 = stack[0];
    v_795 = qcar(v_795);
    v_795 = qcar(v_795);
    goto v_774;
v_775:
    goto v_771;
v_772:
    goto v_773;
v_774:
    if (v_796 == v_795) goto v_769;
    else goto v_770;
v_769:
    v_795 = stack[0];
    v_795 = qcdr(v_795);
    stack[0] = v_795;
    goto v_761;
v_770:
    goto v_789;
v_785:
    v_795 = stack[0];
    v_795 = qcar(v_795);
    goto v_786;
v_787:
    v_796 = v_797;
    goto v_788;
v_789:
    goto v_785;
v_786:
    goto v_787;
v_788:
    v_795 = cons(v_795, v_796);
    env = stack[-2];
    v_797 = v_795;
    v_795 = stack[0];
    v_795 = qcdr(v_795);
    stack[0] = v_795;
    goto v_761;
    v_795 = nil;
    return onevalue(v_795);
}



// Code for rmultpf

static LispObject CC_rmultpf(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_770, v_771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_770 = v_756;
    v_771 = v_755;
// end of prologue
    goto v_767;
v_763:
    goto v_764;
v_765:
    goto v_766;
v_767:
    goto v_763;
v_764:
    goto v_765;
v_766:
    v_770 = cons(v_771, v_770);
    env = stack[0];
    v_770 = ncons(v_770);
    env = stack[0];
    fn = elt(env, 1); // prepf
    v_770 = (*qfn1(fn))(fn, v_770);
    env = stack[0];
    fn = elt(env, 2); // simp!*
    v_770 = (*qfn1(fn))(fn, v_770);
    env = stack[0];
    {
        fn = elt(env, 3); // !*q2f
        return (*qfn1(fn))(fn, v_770);
    }
}



// Code for gcdfd1

static LispObject CC_gcdfd1(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_802, v_803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_756;
    v_802 = v_755;
// end of prologue
v_760:
    v_803 = stack[0];
    if (v_803 == nil) goto v_763;
    else goto v_764;
v_763:
    goto v_759;
v_764:
    v_803 = stack[0];
    if (!consp(v_803)) goto v_771;
    else goto v_772;
v_771:
    v_803 = lisp_true;
    goto v_770;
v_772:
    v_803 = stack[0];
    v_803 = qcar(v_803);
    v_803 = (consp(v_803) ? nil : lisp_true);
    goto v_770;
    v_803 = nil;
v_770:
    if (v_803 == nil) goto v_768;
    goto v_785;
v_781:
    v_803 = v_802;
    goto v_782;
v_783:
    v_802 = stack[0];
    goto v_784;
v_785:
    goto v_781;
v_782:
    goto v_783;
v_784:
    {
        fn = elt(env, 1); // gcddd
        return (*qfn2(fn))(fn, v_803, v_802);
    }
v_768:
    goto v_795;
v_791:
    v_803 = v_802;
    goto v_792;
v_793:
    v_802 = stack[0];
    v_802 = qcar(v_802);
    v_802 = qcdr(v_802);
    goto v_794;
v_795:
    goto v_791;
v_792:
    goto v_793;
v_794:
    v_802 = CC_gcdfd1(elt(env, 0), v_803, v_802);
    env = stack[-1];
    v_803 = stack[0];
    v_803 = qcdr(v_803);
    stack[0] = v_803;
    goto v_760;
    v_802 = nil;
v_759:
    return onevalue(v_802);
}



// Code for multsq

static LispObject CC_multsq(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_909, v_910;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_756;
    stack[-3] = v_755;
// end of prologue
    v_909 = stack[-3];
    v_909 = qcar(v_909);
    if (v_909 == nil) goto v_764;
    else goto v_765;
v_764:
    v_909 = lisp_true;
    goto v_763;
v_765:
    v_909 = stack[-2];
    v_909 = qcar(v_909);
    v_909 = (v_909 == nil ? lisp_true : nil);
    goto v_763;
    v_909 = nil;
v_763:
    if (v_909 == nil) goto v_761;
    goto v_779;
v_775:
    v_910 = nil;
    goto v_776;
v_777:
    v_909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_778;
v_779:
    goto v_775;
v_776:
    goto v_777;
v_778:
    return cons(v_910, v_909);
v_761:
    goto v_792;
v_788:
    v_909 = stack[-3];
    v_910 = qcdr(v_909);
    goto v_789;
v_790:
    v_909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_791;
v_792:
    goto v_788;
v_789:
    goto v_790;
v_791:
    if (v_910 == v_909) goto v_786;
    else goto v_787;
v_786:
    goto v_800;
v_796:
    v_909 = stack[-2];
    v_910 = qcdr(v_909);
    goto v_797;
v_798:
    v_909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_799;
v_800:
    goto v_796;
v_797:
    goto v_798;
v_799:
    v_909 = (v_910 == v_909 ? lisp_true : nil);
    goto v_785;
v_787:
    v_909 = nil;
    goto v_785;
    v_909 = nil;
v_785:
    if (v_909 == nil) goto v_783;
    goto v_813;
v_809:
    goto v_819;
v_815:
    v_909 = stack[-3];
    v_910 = qcar(v_909);
    goto v_816;
v_817:
    v_909 = stack[-2];
    v_909 = qcar(v_909);
    goto v_818;
v_819:
    goto v_815;
v_816:
    goto v_817;
v_818:
    fn = elt(env, 1); // multf
    v_910 = (*qfn2(fn))(fn, v_910, v_909);
    goto v_810;
v_811:
    v_909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_812;
v_813:
    goto v_809;
v_810:
    goto v_811;
v_812:
    return cons(v_910, v_909);
v_783:
    goto v_837;
v_833:
    v_909 = stack[-3];
    v_910 = qcar(v_909);
    goto v_834;
v_835:
    v_909 = stack[-2];
    v_909 = qcdr(v_909);
    goto v_836;
v_837:
    goto v_833;
v_834:
    goto v_835;
v_836:
    fn = elt(env, 2); // gcdf
    v_909 = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    stack[-4] = v_909;
    goto v_847;
v_843:
    v_909 = stack[-2];
    v_910 = qcar(v_909);
    goto v_844;
v_845:
    v_909 = stack[-3];
    v_909 = qcdr(v_909);
    goto v_846;
v_847:
    goto v_843;
v_844:
    goto v_845;
v_846:
    fn = elt(env, 2); // gcdf
    v_909 = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    stack[-1] = v_909;
    goto v_857;
v_853:
    goto v_863;
v_859:
    v_909 = stack[-3];
    v_910 = qcar(v_909);
    goto v_860;
v_861:
    v_909 = stack[-4];
    goto v_862;
v_863:
    goto v_859;
v_860:
    goto v_861;
v_862:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    goto v_854;
v_855:
    goto v_872;
v_868:
    v_909 = stack[-2];
    v_910 = qcar(v_909);
    goto v_869;
v_870:
    v_909 = stack[-1];
    goto v_871;
v_872:
    goto v_868;
v_869:
    goto v_870;
v_871:
    fn = elt(env, 3); // quotf!-fail
    v_909 = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    goto v_856;
v_857:
    goto v_853;
v_854:
    goto v_855;
v_856:
    fn = elt(env, 1); // multf
    v_909 = (*qfn2(fn))(fn, stack[0], v_909);
    env = stack[-5];
    stack[0] = v_909;
    goto v_881;
v_877:
    goto v_887;
v_883:
    v_909 = stack[-3];
    v_910 = qcdr(v_909);
    goto v_884;
v_885:
    v_909 = stack[-1];
    goto v_886;
v_887:
    goto v_883;
v_884:
    goto v_885;
v_886:
    fn = elt(env, 3); // quotf!-fail
    stack[-1] = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    goto v_878;
v_879:
    goto v_896;
v_892:
    v_909 = stack[-2];
    v_910 = qcdr(v_909);
    goto v_893;
v_894:
    v_909 = stack[-4];
    goto v_895;
v_896:
    goto v_892;
v_893:
    goto v_894;
v_895:
    fn = elt(env, 3); // quotf!-fail
    v_909 = (*qfn2(fn))(fn, v_910, v_909);
    env = stack[-5];
    goto v_880;
v_881:
    goto v_877;
v_878:
    goto v_879;
v_880:
    fn = elt(env, 1); // multf
    v_909 = (*qfn2(fn))(fn, stack[-1], v_909);
    env = stack[-5];
    stack[-4] = v_909;
    goto v_906;
v_902:
    v_910 = stack[0];
    goto v_903;
v_904:
    v_909 = stack[-4];
    goto v_905;
v_906:
    goto v_902;
v_903:
    goto v_904;
v_905:
    v_909 = cons(v_910, v_909);
    env = stack[-5];
    {
        fn = elt(env, 4); // canonsq
        return (*qfn1(fn))(fn, v_909);
    }
    goto v_759;
    v_909 = nil;
v_759:
    return onevalue(v_909);
}



// Code for rl_smupdknowl

static LispObject CC_rl_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_781, v_782, v_783, v_784;
    LispObject fn;
    LispObject v_758, v_757, v_756, v_755;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rl_smupdknowl");
    va_start(aa, nargs);
    v_755 = va_arg(aa, LispObject);
    v_756 = va_arg(aa, LispObject);
    v_757 = va_arg(aa, LispObject);
    v_758 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_758,v_757,v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_755,v_756,v_757,v_758);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_781 = v_758;
    v_782 = v_757;
    v_783 = v_756;
    v_784 = v_755;
// end of prologue
    goto v_765;
v_761:
    stack[0] = qvalue(elt(env, 1)); // rl_smupdknowl!*
    goto v_762;
v_763:
    goto v_776;
v_768:
    goto v_769;
v_770:
    goto v_771;
v_772:
    goto v_773;
v_774:
    goto v_775;
v_776:
    goto v_768;
v_769:
    goto v_770;
v_771:
    goto v_772;
v_773:
    goto v_774;
v_775:
    v_781 = list4(v_784, v_783, v_782, v_781);
    env = stack[-1];
    goto v_764;
v_765:
    goto v_761;
v_762:
    goto v_763;
v_764:
    {
        LispObject v_786 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_786, v_781);
    }
}



// Code for qqe_nytidp

static LispObject CC_qqe_nytidp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_760 = v_755;
// end of prologue
    if (!symbolp(v_760)) v_760 = nil;
    else { v_760 = qfastgets(v_760);
           if (v_760 != nil) { v_760 = elt(v_760, 10); // idtype
#ifdef RECORD_GET
             if (v_760 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v_760 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v_760 == SPID_NOPROP) v_760 = nil; }}
#endif
    v_760 = (v_760 == nil ? lisp_true : nil);
    return onevalue(v_760);
}



// Code for bftrim!:

static LispObject CC_bftrimT(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_773, v_774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_773 = v_755;
// end of prologue
    goto v_763;
v_759:
    stack[0] = v_773;
    goto v_760;
v_761:
    goto v_770;
v_766:
    v_774 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_767;
v_768:
    v_773 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    v_773 = difference2(v_774, v_773);
    env = stack[-1];
    goto v_762;
v_763:
    goto v_759;
v_760:
    goto v_761;
v_762:
    fn = elt(env, 2); // round!:mt
    v_773 = (*qfn2(fn))(fn, stack[0], v_773);
    env = stack[-1];
    {
        fn = elt(env, 3); // normbf
        return (*qfn1(fn))(fn, v_773);
    }
}



// Code for off1

static LispObject CC_off1(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_765, v_766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_765 = v_755;
// end of prologue
    goto v_762;
v_758:
    v_766 = v_765;
    goto v_759;
v_760:
    v_765 = nil;
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    {
        fn = elt(env, 1); // onoff
        return (*qfn2(fn))(fn, v_766, v_765);
    }
}



// Code for mgenp

static LispObject CC_mgenp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_773, v_774;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_774 = v_755;
// end of prologue
    v_773 = v_774;
    if (!consp(v_773)) goto v_759;
    else goto v_760;
v_759:
    goto v_767;
v_763:
    v_773 = v_774;
    goto v_764;
v_765:
    v_774 = elt(env, 1); // mgen
    goto v_766;
v_767:
    goto v_763;
v_764:
    goto v_765;
v_766:
    return get(v_773, v_774);
v_760:
    v_773 = nil;
    goto v_758;
    v_773 = nil;
v_758:
    return onevalue(v_773);
}



// Code for on1

static LispObject CC_on1(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_765, v_766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_765 = v_755;
// end of prologue
    goto v_762;
v_758:
    v_766 = v_765;
    goto v_759;
v_760:
    v_765 = lisp_true;
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    {
        fn = elt(env, 1); // onoff
        return (*qfn2(fn))(fn, v_766, v_765);
    }
}



// Code for evsum

static LispObject CC_evsum(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_823, v_824, v_825;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_825 = nil;
v_763:
    v_823 = stack[-1];
    if (v_823 == nil) goto v_766;
    v_823 = stack[0];
    if (v_823 == nil) goto v_766;
    goto v_767;
v_766:
    goto v_762;
v_767:
    goto v_778;
v_774:
    goto v_783;
v_779:
    v_823 = stack[-1];
    v_824 = qcar(v_823);
    goto v_780;
v_781:
    v_823 = stack[0];
    v_823 = qcar(v_823);
    goto v_782;
v_783:
    goto v_779;
v_780:
    goto v_781;
v_782:
    v_823 = (LispObject)(intptr_t)((intptr_t)v_824 + (intptr_t)v_823 - TAG_FIXNUM);
    goto v_775;
v_776:
    v_824 = v_825;
    goto v_777;
v_778:
    goto v_774;
v_775:
    goto v_776;
v_777:
    v_823 = cons(v_823, v_824);
    env = stack[-2];
    v_825 = v_823;
    v_823 = stack[-1];
    v_823 = qcdr(v_823);
    stack[-1] = v_823;
    v_823 = stack[0];
    v_823 = qcdr(v_823);
    stack[0] = v_823;
    goto v_763;
v_762:
    v_823 = v_825;
    v_823 = Lnreverse(nil, v_823);
    v_825 = v_823;
    v_823 = stack[-1];
    if (v_823 == nil) goto v_799;
    goto v_806;
v_802:
    v_824 = v_825;
    goto v_803;
v_804:
    v_823 = stack[-1];
    goto v_805;
v_806:
    goto v_802;
v_803:
    goto v_804;
v_805:
        return Lnconc(nil, v_824, v_823);
v_799:
    v_823 = stack[0];
    if (v_823 == nil) goto v_810;
    goto v_817;
v_813:
    v_824 = v_825;
    goto v_814;
v_815:
    v_823 = stack[0];
    goto v_816;
v_817:
    goto v_813;
v_814:
    goto v_815;
v_816:
        return Lnconc(nil, v_824, v_823);
v_810:
    v_823 = v_825;
    goto v_797;
    v_823 = nil;
v_797:
    return onevalue(v_823);
}



// Code for bcint2op

static LispObject CC_bcint2op(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_890, v_891, v_892, v_893, v_894;
    LispObject v_757, v_756, v_755;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "bcint2op");
    va_start(aa, nargs);
    v_755 = va_arg(aa, LispObject);
    v_756 = va_arg(aa, LispObject);
    v_757 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_757,v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_755,v_756,v_757);
    }
// copy arguments values to proper place
    v_894 = v_757;
    v_892 = v_756;
    v_893 = v_755;
// end of prologue
    v_890 = qvalue(elt(env, 1)); // dmode!*
    if (v_890 == nil) goto v_765;
    else goto v_766;
v_765:
    goto v_776;
v_772:
    v_891 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_773;
v_774:
    v_890 = v_893;
    v_890 = qcdr(v_890);
    goto v_775;
v_776:
    goto v_772;
v_773:
    goto v_774;
v_775:
    if (v_891 == v_890) goto v_770;
    else goto v_771;
v_770:
    v_890 = v_893;
    v_890 = qcar(v_890);
    v_893 = v_890;
    if (is_number(v_890)) goto v_783;
    v_890 = nil;
    goto v_781;
v_783:
    goto v_797;
v_793:
    v_891 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_794;
v_795:
    v_890 = v_892;
    v_890 = qcdr(v_890);
    goto v_796;
v_797:
    goto v_793;
v_794:
    goto v_795;
v_796:
    if (v_891 == v_890) goto v_791;
    else goto v_792;
v_791:
    v_890 = v_892;
    v_890 = qcar(v_890);
    v_892 = v_890;
    if (is_number(v_890)) goto v_804;
    v_890 = nil;
    goto v_802;
v_804:
    goto v_818;
v_814:
    v_891 = v_894;
    goto v_815;
v_816:
    v_890 = elt(env, 2); // times
    goto v_817;
v_818:
    goto v_814;
v_815:
    goto v_816;
v_817:
    if (v_891 == v_890) goto v_812;
    else goto v_813;
v_812:
    goto v_826;
v_822:
    v_890 = v_893;
    goto v_823;
v_824:
    v_891 = v_892;
    goto v_825;
v_826:
    goto v_822;
v_823:
    goto v_824;
v_825:
    v_890 = times2(v_890, v_891);
    goto v_811;
v_813:
    goto v_835;
v_831:
    v_891 = v_894;
    goto v_832;
v_833:
    v_890 = elt(env, 3); // plus
    goto v_834;
v_835:
    goto v_831;
v_832:
    goto v_833;
v_834:
    if (v_891 == v_890) goto v_829;
    else goto v_830;
v_829:
    goto v_843;
v_839:
    v_890 = v_893;
    goto v_840;
v_841:
    v_891 = v_892;
    goto v_842;
v_843:
    goto v_839;
v_840:
    goto v_841;
v_842:
    v_890 = plus2(v_890, v_891);
    goto v_811;
v_830:
    goto v_855;
v_849:
    v_890 = v_894;
    goto v_850;
v_851:
    v_891 = v_893;
    goto v_852;
v_853:
    goto v_854;
v_855:
    goto v_849;
v_850:
    goto v_851;
v_852:
    goto v_853;
v_854:
    v_890 = Lapply2(nil, 3, v_890, v_891, v_892);
    goto v_811;
    v_890 = nil;
v_811:
    v_893 = v_890;
    goto v_802;
    v_890 = nil;
v_802:
    goto v_790;
v_792:
    v_890 = nil;
    goto v_790;
    v_890 = nil;
v_790:
    goto v_781;
    v_890 = nil;
v_781:
    goto v_769;
v_771:
    v_890 = nil;
    goto v_769;
    v_890 = nil;
v_769:
    goto v_764;
v_766:
    v_890 = nil;
    goto v_764;
    v_890 = nil;
v_764:
    if (v_890 == nil) goto v_762;
    goto v_873;
v_869:
    goto v_882;
v_878:
    v_891 = v_893;
    goto v_879;
v_880:
    v_890 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_881;
v_882:
    goto v_878;
v_879:
    goto v_880;
v_881:
    if (v_891 == v_890) goto v_876;
    else goto v_877;
v_876:
    v_890 = nil;
    v_891 = v_890;
    goto v_875;
v_877:
    v_890 = v_893;
    v_891 = v_890;
    goto v_875;
    v_891 = nil;
v_875:
    goto v_870;
v_871:
    v_890 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_872;
v_873:
    goto v_869;
v_870:
    goto v_871;
v_872:
    return cons(v_891, v_890);
v_762:
    v_890 = nil;
    return onevalue(v_890);
}



// Code for quotfm

static LispObject CC_quotfm(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_770, v_771, v_772;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_771 = v_756;
    v_772 = v_755;
// end of prologue
// Binding !*mcd
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*mcd
    v_770 = lisp_true;
    qvalue(elt(env, 1)) = v_770; // !*mcd
    goto v_767;
v_763:
    v_770 = v_772;
    goto v_764;
v_765:
    goto v_766;
v_767:
    goto v_763;
v_764:
    goto v_765;
v_766:
    fn = elt(env, 2); // quotf
    v_770 = (*qfn2(fn))(fn, v_770, v_771);
    ;}  // end of a binding scope
    return onevalue(v_770);
}



// Code for !*collectphysops_reversed

static LispObject CC_Hcollectphysops_reversed(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_795, v_796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_795 = stack[-1];
    fn = elt(env, 1); // physopp
    v_795 = (*qfn1(fn))(fn, v_795);
    env = stack[-2];
    if (v_795 == nil) goto v_763;
    goto v_771;
v_767:
    v_796 = stack[-1];
    goto v_768;
v_769:
    v_795 = stack[0];
    goto v_770;
v_771:
    goto v_767;
v_768:
    goto v_769;
v_770:
    return cons(v_796, v_795);
v_763:
v_776:
    v_795 = stack[-1];
    if (!consp(v_795)) goto v_779;
    else goto v_780;
v_779:
    goto v_775;
v_780:
    goto v_788;
v_784:
    v_795 = stack[-1];
    v_796 = qcar(v_795);
    goto v_785;
v_786:
    v_795 = stack[0];
    goto v_787;
v_788:
    goto v_784;
v_785:
    goto v_786;
v_787:
    v_795 = CC_Hcollectphysops_reversed(elt(env, 0), v_796, v_795);
    env = stack[-2];
    stack[0] = v_795;
    v_795 = stack[-1];
    v_795 = qcdr(v_795);
    stack[-1] = v_795;
    goto v_776;
v_775:
    v_795 = stack[0];
    return onevalue(v_795);
}



// Code for constimes

static LispObject CC_constimes(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_765, v_766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_765 = v_755;
// end of prologue
    goto v_762;
v_758:
    v_766 = v_765;
    goto v_759;
v_760:
    v_765 = nil;
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    {
        fn = elt(env, 1); // cstimes
        return (*qfn2(fn))(fn, v_766, v_765);
    }
}



// Code for arraychk

static LispObject CC_arraychk(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_766;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_766 = v_755;
// end of prologue
    if (v_766 == nil) goto v_759;
    else goto v_760;
v_759:
    v_766 = elt(env, 1); // array
    goto v_758;
v_760:
    v_766 = nil;
    goto v_758;
    v_766 = nil;
v_758:
    return onevalue(v_766);
}



// Code for fs!:angle!-order

static LispObject CC_fsTangleKorder(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_883, v_884, v_885;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_756;
    stack[-3] = v_755;
// end of prologue
    v_883 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_883;
    goto v_770;
v_766:
    v_884 = stack[-3];
    goto v_767;
v_768:
    v_883 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    v_883 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_883;
    goto v_778;
v_774:
    v_884 = stack[-2];
    goto v_775;
v_776:
    v_883 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_777;
v_778:
    goto v_774;
v_775:
    goto v_776;
v_777:
    v_883 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_883;
v_764:
    goto v_787;
v_783:
    goto v_792;
v_788:
    v_884 = stack[-1];
    goto v_789;
v_790:
    v_883 = stack[-4];
    goto v_791;
v_792:
    goto v_788;
v_789:
    goto v_790;
v_791:
    v_885 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    goto v_784;
v_785:
    goto v_800;
v_796:
    v_884 = stack[0];
    goto v_797;
v_798:
    v_883 = stack[-4];
    goto v_799;
v_800:
    goto v_796;
v_797:
    goto v_798;
v_799:
    v_883 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    goto v_786;
v_787:
    goto v_783;
v_784:
    goto v_785;
v_786:
    v_883 = difference2(v_885, v_883);
    env = stack[-5];
    v_885 = v_883;
    goto v_812;
v_808:
    v_884 = v_885;
    goto v_809;
v_810:
    v_883 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_811;
v_812:
    goto v_808;
v_809:
    goto v_810;
v_811:
    if (v_884 == v_883) goto v_807;
    goto v_820;
v_816:
    v_884 = v_885;
    goto v_817;
v_818:
    v_883 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_819;
v_820:
    goto v_816;
v_817:
    goto v_818;
v_819:
        return Lgreaterp(nil, v_884, v_883);
v_807:
    v_883 = stack[-4];
    v_883 = add1(v_883);
    env = stack[-5];
    stack[-4] = v_883;
    goto v_834;
v_830:
    v_884 = stack[-4];
    goto v_831;
v_832:
    v_883 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_833;
v_834:
    goto v_830;
v_831:
    goto v_832;
v_833:
    v_883 = (LispObject)lessp2(v_884, v_883);
    v_883 = v_883 ? lisp_true : nil;
    env = stack[-5];
    if (v_883 == nil) goto v_828;
    goto v_764;
v_828:
    goto v_845;
v_841:
    goto v_850;
v_846:
    v_884 = stack[-3];
    goto v_847;
v_848:
    v_883 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_849;
v_850:
    goto v_846;
v_847:
    goto v_848;
v_849:
    v_885 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    goto v_842;
v_843:
    goto v_858;
v_854:
    v_884 = stack[-2];
    goto v_855;
v_856:
    v_883 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_857;
v_858:
    goto v_854;
v_855:
    goto v_856;
v_857:
    v_883 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    goto v_844;
v_845:
    goto v_841;
v_842:
    goto v_843;
v_844:
    if (equal(v_885, v_883)) goto v_839;
    else goto v_840;
v_839:
    v_883 = nil;
    goto v_838;
v_840:
    goto v_869;
v_865:
    goto v_874;
v_870:
    v_884 = stack[-3];
    goto v_871;
v_872:
    v_883 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_873;
v_874:
    goto v_870;
v_871:
    goto v_872;
v_873:
    v_883 = *(LispObject *)((char *)v_884 + (CELL-TAG_VECTOR) + (((intptr_t)v_883-TAG_FIXNUM)/(16/CELL)));
    goto v_866;
v_867:
    v_884 = elt(env, 1); // sin
    goto v_868;
v_869:
    goto v_865;
v_866:
    goto v_867;
v_868:
    if (v_883 == v_884) goto v_863;
    else goto v_864;
v_863:
    v_883 = nil;
    goto v_838;
v_864:
    v_883 = lisp_true;
    goto v_838;
    v_883 = nil;
v_838:
    return onevalue(v_883);
}



// Code for cali_trace

static LispObject CC_cali_trace(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_758;
    argcheck(nargs, 0, "cali_trace");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_758 = elt(env, 1); // cali
    if (!symbolp(v_758)) v_758 = nil;
    else { v_758 = qfastgets(v_758);
           if (v_758 != nil) { v_758 = elt(v_758, 31); // trace
#ifdef RECORD_GET
             if (v_758 != SPID_NOPROP)
                record_get(elt(fastget_names, 31), 1);
             else record_get(elt(fastget_names, 31), 0),
                v_758 = nil; }
           else record_get(elt(fastget_names, 31), 0); }
#else
             if (v_758 == SPID_NOPROP) v_758 = nil; }}
#endif
    return onevalue(v_758);
}



// Code for pcmult

static LispObject CC_pcmult(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_830, v_831;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_756;
    v_830 = v_755;
// end of prologue
    stack[-5] = v_830;
    v_830 = stack[-5];
    if (v_830 == nil) goto v_767;
    else goto v_768;
v_767:
    v_830 = nil;
    goto v_762;
v_768:
    v_830 = stack[-5];
    v_830 = qcar(v_830);
    goto v_780;
v_776:
    v_831 = v_830;
    stack[0] = qcar(v_831);
    goto v_777;
v_778:
    goto v_788;
v_784:
    v_831 = stack[-4];
    goto v_785;
v_786:
    v_830 = qcdr(v_830);
    goto v_787;
v_788:
    goto v_784;
v_785:
    goto v_786;
v_787:
    fn = elt(env, 1); // cprod
    v_830 = (*qfn2(fn))(fn, v_831, v_830);
    env = stack[-6];
    goto v_779;
v_780:
    goto v_776;
v_777:
    goto v_778;
v_779:
    v_830 = cons(stack[0], v_830);
    env = stack[-6];
    v_830 = ncons(v_830);
    env = stack[-6];
    stack[-2] = v_830;
    stack[-3] = v_830;
v_763:
    v_830 = stack[-5];
    v_830 = qcdr(v_830);
    stack[-5] = v_830;
    v_830 = stack[-5];
    if (v_830 == nil) goto v_796;
    else goto v_797;
v_796:
    v_830 = stack[-3];
    goto v_762;
v_797:
    goto v_805;
v_801:
    stack[-1] = stack[-2];
    goto v_802;
v_803:
    v_830 = stack[-5];
    v_830 = qcar(v_830);
    goto v_816;
v_812:
    v_831 = v_830;
    stack[0] = qcar(v_831);
    goto v_813;
v_814:
    goto v_824;
v_820:
    v_831 = stack[-4];
    goto v_821;
v_822:
    v_830 = qcdr(v_830);
    goto v_823;
v_824:
    goto v_820;
v_821:
    goto v_822;
v_823:
    fn = elt(env, 1); // cprod
    v_830 = (*qfn2(fn))(fn, v_831, v_830);
    env = stack[-6];
    goto v_815;
v_816:
    goto v_812;
v_813:
    goto v_814;
v_815:
    v_830 = cons(stack[0], v_830);
    env = stack[-6];
    v_830 = ncons(v_830);
    env = stack[-6];
    goto v_804;
v_805:
    goto v_801;
v_802:
    goto v_803;
v_804:
    v_830 = Lrplacd(nil, stack[-1], v_830);
    env = stack[-6];
    v_830 = stack[-2];
    v_830 = qcdr(v_830);
    stack[-2] = v_830;
    goto v_763;
v_762:
    return onevalue(v_830);
}



// Code for pkp

static LispObject CC_pkp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_905, v_906, v_907;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    stack[-3] = nil;
    v_905 = stack[0];
    if (!consp(v_905)) goto v_768;
    else goto v_769;
v_768:
    v_905 = lisp_true;
    goto v_767;
v_769:
    v_905 = qvalue(elt(env, 1)); // !*ppacked
    v_905 = (v_905 == nil ? lisp_true : nil);
    goto v_767;
    v_905 = nil;
v_767:
    if (v_905 == nil) goto v_765;
    v_905 = stack[0];
    goto v_761;
v_765:
    goto v_782;
v_778:
    v_905 = stack[0];
    v_906 = Llength(nil, v_905);
    env = stack[-4];
    goto v_779;
v_780:
    v_905 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_781;
v_782:
    goto v_778;
v_779:
    goto v_780;
v_781:
    v_905 = (LispObject)geq2(v_906, v_905);
    v_905 = v_905 ? lisp_true : nil;
    env = stack[-4];
    stack[-2] = v_905;
    v_905 = stack[0];
    stack[-1] = v_905;
v_789:
    v_905 = stack[-1];
    if (v_905 == nil) goto v_793;
    else goto v_794;
v_793:
    goto v_788;
v_794:
    v_905 = stack[-1];
    v_905 = qcar(v_905);
    stack[0] = v_905;
    v_905 = stack[-2];
    if (v_905 == nil) goto v_803;
    goto v_814;
v_810:
    v_906 = stack[0];
    goto v_811;
v_812:
    v_905 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_813;
v_814:
    goto v_810;
v_811:
    goto v_812;
v_813:
    v_905 = (LispObject)lessp2(v_906, v_905);
    v_905 = v_905 ? lisp_true : nil;
    env = stack[-4];
    if (v_905 == nil) goto v_808;
    goto v_824;
v_818:
    goto v_830;
v_826:
    v_906 = stack[0];
    goto v_827;
v_828:
    v_905 = qvalue(elt(env, 2)); // diglist!*
    goto v_829;
v_830:
    goto v_826;
v_827:
    goto v_828;
v_829:
    fn = elt(env, 4); // dssoc
    v_905 = (*qfn2(fn))(fn, v_906, v_905);
    env = stack[-4];
    v_907 = qcar(v_905);
    goto v_819;
v_820:
    v_906 = elt(env, 3); // !0
    goto v_821;
v_822:
    v_905 = stack[-3];
    goto v_823;
v_824:
    goto v_818;
v_819:
    goto v_820;
v_821:
    goto v_822;
v_823:
    v_905 = list2star(v_907, v_906, v_905);
    env = stack[-4];
    stack[-3] = v_905;
    goto v_806;
v_808:
    goto v_843;
v_839:
    v_906 = stack[0];
    goto v_840;
v_841:
    v_905 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_842;
v_843:
    goto v_839;
v_840:
    goto v_841;
v_842:
    v_905 = Ldivide(nil, v_906, v_905);
    env = stack[-4];
    stack[0] = v_905;
    goto v_851;
v_847:
    goto v_857;
v_853:
    v_905 = stack[0];
    v_906 = qcar(v_905);
    goto v_854;
v_855:
    v_905 = qvalue(elt(env, 2)); // diglist!*
    goto v_856;
v_857:
    goto v_853;
v_854:
    goto v_855;
v_856:
    fn = elt(env, 4); // dssoc
    v_905 = (*qfn2(fn))(fn, v_906, v_905);
    env = stack[-4];
    v_906 = qcar(v_905);
    goto v_848;
v_849:
    v_905 = stack[-3];
    goto v_850;
v_851:
    goto v_847;
v_848:
    goto v_849;
v_850:
    v_905 = cons(v_906, v_905);
    env = stack[-4];
    stack[-3] = v_905;
    goto v_868;
v_864:
    goto v_874;
v_870:
    v_905 = stack[0];
    v_906 = qcdr(v_905);
    goto v_871;
v_872:
    v_905 = qvalue(elt(env, 2)); // diglist!*
    goto v_873;
v_874:
    goto v_870;
v_871:
    goto v_872;
v_873:
    fn = elt(env, 4); // dssoc
    v_905 = (*qfn2(fn))(fn, v_906, v_905);
    env = stack[-4];
    v_906 = qcar(v_905);
    goto v_865;
v_866:
    v_905 = stack[-3];
    goto v_867;
v_868:
    goto v_864;
v_865:
    goto v_866;
v_867:
    v_905 = cons(v_906, v_905);
    env = stack[-4];
    stack[-3] = v_905;
    goto v_806;
v_806:
    goto v_801;
v_803:
    goto v_889;
v_885:
    goto v_895;
v_891:
    v_906 = stack[0];
    goto v_892;
v_893:
    v_905 = qvalue(elt(env, 2)); // diglist!*
    goto v_894;
v_895:
    goto v_891;
v_892:
    goto v_893;
v_894:
    fn = elt(env, 4); // dssoc
    v_905 = (*qfn2(fn))(fn, v_906, v_905);
    env = stack[-4];
    v_906 = qcar(v_905);
    goto v_886;
v_887:
    v_905 = stack[-3];
    goto v_888;
v_889:
    goto v_885;
v_886:
    goto v_887;
v_888:
    v_905 = cons(v_906, v_905);
    env = stack[-4];
    stack[-3] = v_905;
    goto v_801;
v_801:
    v_905 = stack[-1];
    v_905 = qcdr(v_905);
    stack[-1] = v_905;
    goto v_789;
v_788:
    v_905 = stack[-3];
    v_905 = Lnreverse(nil, v_905);
        return Lcompress(nil, v_905);
v_761:
    return onevalue(v_905);
}



// Code for noncomp1

static LispObject CC_noncomp1(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_812, v_813, v_814;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_813 = v_755;
// end of prologue
    v_812 = v_813;
    v_812 = Lconsp(nil, v_812);
    env = stack[0];
    if (v_812 == nil) goto v_759;
    else goto v_760;
v_759:
    v_812 = nil;
    goto v_758;
v_760:
    v_812 = v_813;
    v_812 = qcar(v_812);
    v_812 = Lconsp(nil, v_812);
    env = stack[0];
    if (v_812 == nil) goto v_765;
    v_812 = v_813;
    {
        fn = elt(env, 3); // noncomfp
        return (*qfn1(fn))(fn, v_812);
    }
v_765:
    goto v_777;
v_773:
    v_812 = v_813;
    v_814 = qcar(v_812);
    goto v_774;
v_775:
    v_812 = elt(env, 1); // !*sq
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    if (v_814 == v_812) goto v_771;
    else goto v_772;
v_771:
    v_812 = v_813;
    v_812 = qcdr(v_812);
    v_812 = qcar(v_812);
    v_812 = qcar(v_812);
    {
        fn = elt(env, 3); // noncomfp
        return (*qfn1(fn))(fn, v_812);
    }
v_772:
    goto v_792;
v_788:
    v_812 = v_813;
    v_814 = qcar(v_812);
    goto v_789;
v_790:
    v_812 = elt(env, 2); // taylor!*
    goto v_791;
v_792:
    goto v_788;
v_789:
    goto v_790;
v_791:
    if (v_814 == v_812) goto v_786;
    else goto v_787;
v_786:
    v_812 = nil;
    goto v_758;
v_787:
    v_812 = v_813;
    v_812 = qcar(v_812);
    if (!symbolp(v_812)) v_812 = nil;
    else { v_812 = qfastgets(v_812);
           if (v_812 != nil) { v_812 = elt(v_812, 0); // noncom
#ifdef RECORD_GET
             if (v_812 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_812 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_812 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_812 == SPID_NOPROP) v_812 = nil; else v_812 = lisp_true; }}
#endif
    if (v_812 == nil) goto v_802;
    v_812 = lisp_true;
    goto v_800;
v_802:
    v_812 = v_813;
    v_812 = qcdr(v_812);
    {
        fn = elt(env, 4); // noncomlistp
        return (*qfn1(fn))(fn, v_812);
    }
    v_812 = nil;
v_800:
    goto v_758;
    v_812 = nil;
v_758:
    return onevalue(v_812);
}



// Code for plus!-mod!-p

static LispObject CC_plusKmodKp(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_1014, v_1015, v_1016;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    stack[-2] = nil;
v_763:
    v_1014 = stack[-1];
    if (v_1014 == nil) goto v_767;
    else goto v_768;
v_767:
    v_1014 = stack[0];
    v_1015 = v_1014;
    goto v_764;
v_768:
    v_1014 = stack[0];
    if (v_1014 == nil) goto v_771;
    else goto v_772;
v_771:
    v_1014 = stack[-1];
    v_1015 = v_1014;
    goto v_764;
v_772:
    v_1014 = stack[-1];
    if (!consp(v_1014)) goto v_779;
    else goto v_780;
v_779:
    v_1014 = lisp_true;
    goto v_778;
v_780:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1014 = (consp(v_1014) ? nil : lisp_true);
    goto v_778;
    v_1014 = nil;
v_778:
    if (v_1014 == nil) goto v_776;
    v_1014 = stack[0];
    if (!consp(v_1014)) goto v_794;
    else goto v_795;
v_794:
    v_1014 = lisp_true;
    goto v_793;
v_795:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = (consp(v_1014) ? nil : lisp_true);
    goto v_793;
    v_1014 = nil;
v_793:
    if (v_1014 == nil) goto v_791;
    goto v_808;
v_804:
    v_1015 = stack[-1];
    goto v_805;
v_806:
    v_1014 = stack[0];
    goto v_807;
v_808:
    goto v_804;
v_805:
    goto v_806;
v_807:
    {   intptr_t w = int_of_fixnum(v_1015) + int_of_fixnum(v_1014);
        if (w >= current_modulus) w -= current_modulus;
        v_1014 = fixnum_of_int(w);
    }
    fn = elt(env, 1); // !*n2f
    v_1014 = (*qfn1(fn))(fn, v_1014);
    env = stack[-3];
    v_1015 = v_1014;
    goto v_764;
v_791:
    goto v_819;
v_815:
    v_1014 = stack[0];
    v_1015 = qcar(v_1014);
    goto v_816;
v_817:
    v_1014 = stack[-2];
    goto v_818;
v_819:
    goto v_815;
v_816:
    goto v_817;
v_818:
    v_1014 = cons(v_1015, v_1014);
    env = stack[-3];
    stack[-2] = v_1014;
    v_1014 = stack[0];
    v_1014 = qcdr(v_1014);
    stack[0] = v_1014;
    goto v_763;
    goto v_766;
v_776:
    v_1014 = stack[0];
    if (!consp(v_1014)) goto v_829;
    else goto v_830;
v_829:
    v_1014 = lisp_true;
    goto v_828;
v_830:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = (consp(v_1014) ? nil : lisp_true);
    goto v_828;
    v_1014 = nil;
v_828:
    if (v_1014 == nil) goto v_826;
    goto v_843;
v_839:
    v_1014 = stack[-1];
    v_1015 = qcar(v_1014);
    goto v_840;
v_841:
    v_1014 = stack[-2];
    goto v_842;
v_843:
    goto v_839;
v_840:
    goto v_841;
v_842:
    v_1014 = cons(v_1015, v_1014);
    env = stack[-3];
    stack[-2] = v_1014;
    v_1014 = stack[-1];
    v_1014 = qcdr(v_1014);
    stack[-1] = v_1014;
    goto v_763;
v_826:
    goto v_855;
v_851:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1015 = qcar(v_1014);
    goto v_852;
v_853:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    goto v_854;
v_855:
    goto v_851;
v_852:
    goto v_853;
v_854:
    if (equal(v_1015, v_1014)) goto v_849;
    else goto v_850;
v_849:
    goto v_867;
v_863:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1015 = qcdr(v_1014);
    goto v_864;
v_865:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcdr(v_1014);
    goto v_866;
v_867:
    goto v_863;
v_864:
    goto v_865;
v_866:
    v_1014 = CC_plusKmodKp(elt(env, 0), v_1015, v_1014);
    env = stack[-3];
    v_1015 = v_1014;
    if (v_1015 == nil) goto v_877;
    goto v_886;
v_880:
    v_1015 = stack[-1];
    v_1015 = qcar(v_1015);
    v_1016 = qcar(v_1015);
    goto v_881;
v_882:
    v_1015 = v_1014;
    goto v_883;
v_884:
    v_1014 = stack[-2];
    goto v_885;
v_886:
    goto v_880;
v_881:
    goto v_882;
v_883:
    goto v_884;
v_885:
    v_1014 = acons(v_1016, v_1015, v_1014);
    env = stack[-3];
    stack[-2] = v_1014;
    goto v_875;
v_877:
v_875:
    v_1014 = stack[-1];
    v_1014 = qcdr(v_1014);
    stack[-1] = v_1014;
    v_1014 = stack[0];
    v_1014 = qcdr(v_1014);
    stack[0] = v_1014;
    goto v_763;
v_850:
    goto v_907;
v_903:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1015 = qcar(v_1014);
    goto v_904;
v_905:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    goto v_906;
v_907:
    goto v_903;
v_904:
    goto v_905;
v_906:
    if (equal(v_1015, v_1014)) goto v_901;
    else goto v_902;
v_901:
    goto v_920;
v_916:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1015 = qcdr(v_1014);
    goto v_917;
v_918:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1014 = qcdr(v_1014);
    goto v_919;
v_920:
    goto v_916;
v_917:
    goto v_918;
v_919:
    v_1014 = ((intptr_t)v_1015 > (intptr_t)v_1014) ? lisp_true : nil;
    goto v_900;
v_902:
    v_1014 = nil;
    goto v_900;
    v_1014 = nil;
v_900:
    if (v_1014 == nil) goto v_898;
    else goto v_896;
v_898:
    goto v_942;
v_938:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1015 = qcar(v_1014);
    goto v_939;
v_940:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    goto v_941;
v_942:
    goto v_938;
v_939:
    goto v_940;
v_941:
    if (equal(v_1015, v_1014)) goto v_937;
    goto v_956;
v_952:
    v_1014 = stack[-1];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1015 = qcar(v_1014);
    goto v_953;
v_954:
    v_1014 = stack[0];
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    v_1014 = qcar(v_1014);
    goto v_955;
v_956:
    goto v_952;
v_953:
    goto v_954;
v_955:
    fn = elt(env, 2); // ordop
    v_1014 = (*qfn2(fn))(fn, v_1015, v_1014);
    env = stack[-3];
    goto v_935;
v_937:
    v_1014 = nil;
    goto v_935;
    v_1014 = nil;
v_935:
    if (v_1014 == nil) goto v_933;
    else goto v_896;
v_933:
    goto v_897;
v_896:
    goto v_973;
v_969:
    v_1014 = stack[-1];
    v_1015 = qcar(v_1014);
    goto v_970;
v_971:
    v_1014 = stack[-2];
    goto v_972;
v_973:
    goto v_969;
v_970:
    goto v_971;
v_972:
    v_1014 = cons(v_1015, v_1014);
    env = stack[-3];
    stack[-2] = v_1014;
    v_1014 = stack[-1];
    v_1014 = qcdr(v_1014);
    stack[-1] = v_1014;
    goto v_763;
v_897:
    goto v_986;
v_982:
    v_1014 = stack[0];
    v_1015 = qcar(v_1014);
    goto v_983;
v_984:
    v_1014 = stack[-2];
    goto v_985;
v_986:
    goto v_982;
v_983:
    goto v_984;
v_985:
    v_1014 = cons(v_1015, v_1014);
    env = stack[-3];
    stack[-2] = v_1014;
    v_1014 = stack[0];
    v_1014 = qcdr(v_1014);
    stack[0] = v_1014;
    goto v_763;
v_766:
v_764:
v_994:
    v_1014 = stack[-2];
    if (v_1014 == nil) goto v_997;
    else goto v_998;
v_997:
    goto v_993;
v_998:
    v_1014 = stack[-2];
    v_1014 = qcdr(v_1014);
    stack[-1] = v_1014;
    goto v_1008;
v_1004:
    v_1014 = stack[-2];
    goto v_1005;
v_1006:
    goto v_1007;
v_1008:
    goto v_1004;
v_1005:
    goto v_1006;
v_1007:
    v_1014 = Lrplacd(nil, v_1014, v_1015);
    env = stack[-3];
    v_1014 = stack[-2];
    v_1015 = v_1014;
    v_1014 = stack[-1];
    stack[-2] = v_1014;
    goto v_994;
v_993:
    v_1014 = v_1015;
    return onevalue(v_1014);
}



// Code for split_form

static LispObject CC_split_form(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_773, v_774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_773 = v_756;
    v_774 = v_755;
// end of prologue
    goto v_767;
v_759:
    stack[-2] = v_774;
    goto v_760;
v_761:
    stack[-1] = v_773;
    goto v_762;
v_763:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_764;
v_765:
    v_773 = nil;
    v_773 = ncons(v_773);
    env = stack[-3];
    goto v_766;
v_767:
    goto v_759;
v_760:
    goto v_761;
v_762:
    goto v_763;
v_764:
    goto v_765;
v_766:
    {
        LispObject v_778 = stack[-2];
        LispObject v_779 = stack[-1];
        LispObject v_780 = stack[0];
        fn = elt(env, 1); // split_f
        return (*qfnn(fn))(fn, 4, v_778, v_779, v_780, v_773);
    }
}



// Code for subs2q

static LispObject CC_subs2q(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_847, v_848, v_849, v_850;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_755;
// end of prologue
v_754:
    v_847 = stack[-2];
    v_848 = qcar(v_847);
    v_847 = stack[-2];
    v_847 = qcdr(v_847);
    stack[-3] = v_848;
    stack[-1] = v_847;
    v_847 = stack[-3];
    fn = elt(env, 1); // subs2f
    stack[0] = (*qfn1(fn))(fn, v_847);
    env = stack[-4];
    v_847 = stack[-1];
    fn = elt(env, 1); // subs2f
    v_847 = (*qfn1(fn))(fn, v_847);
    env = stack[-4];
    v_850 = stack[0];
    v_849 = v_847;
    goto v_781;
v_777:
    v_847 = v_850;
    v_848 = qcdr(v_847);
    goto v_778;
v_779:
    v_847 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_780;
v_781:
    goto v_777;
v_778:
    goto v_779;
v_780:
    if (v_848 == v_847) goto v_775;
    else goto v_776;
v_775:
    goto v_789;
v_785:
    v_847 = v_849;
    v_848 = qcdr(v_847);
    goto v_786;
v_787:
    v_847 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_788;
v_789:
    goto v_785;
v_786:
    goto v_787;
v_788:
    v_847 = (v_848 == v_847 ? lisp_true : nil);
    goto v_774;
v_776:
    v_847 = nil;
    goto v_774;
    v_847 = nil;
v_774:
    if (v_847 == nil) goto v_772;
    goto v_809;
v_805:
    v_847 = v_850;
    v_848 = qcar(v_847);
    goto v_806;
v_807:
    v_847 = stack[-3];
    goto v_808;
v_809:
    goto v_805;
v_806:
    goto v_807;
v_808:
    if (equal(v_848, v_847)) goto v_803;
    else goto v_804;
v_803:
    goto v_817;
v_813:
    v_847 = v_849;
    v_848 = qcar(v_847);
    goto v_814;
v_815:
    v_847 = stack[-1];
    goto v_816;
v_817:
    goto v_813;
v_814:
    goto v_815;
v_816:
    v_847 = (equal(v_848, v_847) ? lisp_true : nil);
    goto v_802;
v_804:
    v_847 = nil;
    goto v_802;
    v_847 = nil;
v_802:
    if (v_847 == nil) goto v_800;
    v_847 = stack[-2];
    goto v_798;
v_800:
    goto v_833;
v_829:
    v_847 = v_850;
    goto v_830;
v_831:
    v_848 = v_849;
    goto v_832;
v_833:
    goto v_829;
v_830:
    goto v_831;
v_832:
    {
        fn = elt(env, 2); // quotsq
        return (*qfn2(fn))(fn, v_847, v_848);
    }
    v_847 = nil;
v_798:
    goto v_770;
v_772:
    goto v_844;
v_840:
    v_847 = v_850;
    goto v_841;
v_842:
    v_848 = v_849;
    goto v_843;
v_844:
    goto v_840;
v_841:
    goto v_842;
v_843:
    fn = elt(env, 2); // quotsq
    v_847 = (*qfn2(fn))(fn, v_847, v_848);
    env = stack[-4];
    stack[-2] = v_847;
    goto v_754;
    v_847 = nil;
v_770:
    return onevalue(v_847);
}



// Code for qqe_btidp

static LispObject CC_qqe_btidp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_766, v_767;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_766 = v_755;
// end of prologue
    goto v_761;
v_757:
    if (!symbolp(v_766)) v_766 = nil;
    else { v_766 = qfastgets(v_766);
           if (v_766 != nil) { v_766 = elt(v_766, 10); // idtype
#ifdef RECORD_GET
             if (v_766 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v_766 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v_766 == SPID_NOPROP) v_766 = nil; }}
#endif
    goto v_758;
v_759:
    v_767 = elt(env, 1); // bt
    goto v_760;
v_761:
    goto v_757;
v_758:
    goto v_759;
v_760:
    v_766 = (v_766 == v_767 ? lisp_true : nil);
    return onevalue(v_766);
}



// Code for prepsq

static LispObject CC_prepsq(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_774, v_775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_775 = v_755;
// end of prologue
    v_774 = v_775;
    v_774 = qcar(v_774);
    if (v_774 == nil) goto v_759;
    else goto v_760;
v_759:
    v_774 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_760:
    goto v_771;
v_767:
    goto v_768;
v_769:
    v_774 = elt(env, 1); // prepf
    goto v_770;
v_771:
    goto v_767;
v_768:
    goto v_769;
v_770:
    {
        fn = elt(env, 2); // sqform
        return (*qfn2(fn))(fn, v_775, v_774);
    }
    v_774 = nil;
v_758:
    return onevalue(v_774);
}



// Code for subs2!*

static LispObject CC_subs2H(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_761, v_762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_762 = v_755;
// end of prologue
    v_761 = qvalue(elt(env, 1)); // !*sub2
// Binding !*sub2
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_761; // !*sub2
    v_761 = v_762;
    fn = elt(env, 2); // subs2
    v_761 = (*qfn1(fn))(fn, v_761);
    ;}  // end of a binding scope
    return onevalue(v_761);
}



// Code for negsq

static LispObject CC_negsq(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_768, v_769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    goto v_762;
v_758:
    v_768 = stack[0];
    v_768 = qcar(v_768);
    fn = elt(env, 1); // negf
    v_769 = (*qfn1(fn))(fn, v_768);
    goto v_759;
v_760:
    v_768 = stack[0];
    v_768 = qcdr(v_768);
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    return cons(v_769, v_768);
}



// Code for hasonephysop

static LispObject CC_hasonephysop(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
v_754:
    v_774 = stack[0];
    if (v_774 == nil) goto v_759;
    else goto v_760;
v_759:
    v_774 = nil;
    goto v_758;
v_760:
    v_774 = stack[0];
    v_774 = qcar(v_774);
    fn = elt(env, 1); // physopp!*
    v_774 = (*qfn1(fn))(fn, v_774);
    env = stack[-1];
    if (v_774 == nil) goto v_767;
    else goto v_766;
v_767:
    v_774 = stack[0];
    v_774 = qcdr(v_774);
    stack[0] = v_774;
    goto v_754;
v_766:
    goto v_758;
    v_774 = nil;
v_758:
    return onevalue(v_774);
}



// Code for errorset!*

static LispObject CC_errorsetH(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_769, v_770, v_771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_769 = v_756;
    v_770 = v_755;
// end of prologue
    goto v_765;
v_759:
    v_771 = v_770;
    goto v_760;
v_761:
    v_770 = v_769;
    goto v_762;
v_763:
    v_769 = qvalue(elt(env, 1)); // !*backtrace
    goto v_764;
v_765:
    goto v_759;
v_760:
    goto v_761;
v_762:
    goto v_763;
v_764:
    {
        fn = elt(env, 2); // errorset
        return (*qfnn(fn))(fn, 3, v_771, v_770, v_769);
    }
}



// Code for fs!:timesterm

static LispObject CC_fsTtimesterm(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_803, v_804, v_805;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    v_803 = stack[0];
    if (v_803 == nil) goto v_760;
    else goto v_761;
v_760:
    v_803 = nil;
    goto v_759;
v_761:
    v_803 = stack[-1];
    if (v_803 == nil) goto v_764;
    else goto v_765;
v_764:
    v_803 = nil;
    goto v_759;
v_765:
    goto v_778;
v_774:
    v_804 = stack[-1];
    goto v_775;
v_776:
    v_803 = stack[0];
    goto v_777;
v_778:
    goto v_774;
v_775:
    goto v_776;
v_777:
    fn = elt(env, 1); // fs!:timestermterm
    v_803 = (*qfn2(fn))(fn, v_804, v_803);
    env = stack[-3];
    goto v_786;
v_782:
    stack[-2] = v_803;
    goto v_783;
v_784:
    goto v_793;
v_789:
    v_805 = stack[-1];
    goto v_790;
v_791:
    goto v_799;
v_795:
    v_804 = stack[0];
    goto v_796;
v_797:
    v_803 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_798;
v_799:
    goto v_795;
v_796:
    goto v_797;
v_798:
    v_803 = *(LispObject *)((char *)v_804 + (CELL-TAG_VECTOR) + (((intptr_t)v_803-TAG_FIXNUM)/(16/CELL)));
    goto v_792;
v_793:
    goto v_789;
v_790:
    goto v_791;
v_792:
    v_803 = CC_fsTtimesterm(elt(env, 0), v_805, v_803);
    env = stack[-3];
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    {
        LispObject v_809 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_809, v_803);
    }
    goto v_759;
    v_803 = nil;
v_759:
    return onevalue(v_803);
}



// Code for bas_rep

static LispObject CC_bas_rep(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_765, v_766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_765 = v_755;
// end of prologue
    goto v_762;
v_758:
    v_766 = v_765;
    goto v_759;
v_760:
    v_765 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_761;
v_762:
    goto v_758;
v_759:
    goto v_760;
v_761:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_766, v_765);
    }
}



// Code for !:minus

static LispObject CC_Tminus(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_806, v_807, v_808;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_807 = v_755;
// end of prologue
    v_806 = v_807;
    if (v_806 == nil) goto v_759;
    else goto v_760;
v_759:
    v_806 = nil;
    goto v_758;
v_760:
    v_806 = v_807;
    if (!consp(v_806)) goto v_763;
    else goto v_764;
v_763:
    v_806 = v_807;
    return negate(v_806);
v_764:
    goto v_775;
v_771:
    v_806 = v_807;
    v_808 = qcar(v_806);
    goto v_772;
v_773:
    v_806 = elt(env, 1); // minus
    goto v_774;
v_775:
    goto v_771;
v_772:
    goto v_773;
v_774:
    v_806 = get(v_808, v_806);
    env = stack[0];
    v_808 = v_806;
    v_806 = v_808;
    if (v_806 == nil) goto v_783;
    goto v_790;
v_786:
    v_806 = v_808;
    goto v_787;
v_788:
    goto v_789;
v_790:
    goto v_786;
v_787:
    goto v_788;
v_789:
        return Lapply1(nil, v_806, v_807);
v_783:
    goto v_802;
v_796:
    v_808 = v_807;
    goto v_797;
v_798:
    v_807 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_799;
v_800:
    v_806 = elt(env, 2); // times
    goto v_801;
v_802:
    goto v_796;
v_797:
    goto v_798;
v_799:
    goto v_800;
v_801:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_808, v_807, v_806);
    }
    v_806 = nil;
    goto v_758;
    v_806 = nil;
v_758:
    return onevalue(v_806);
}



// Code for rev

static LispObject CC_rev(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_782, v_783, v_784;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_782 = v_756;
    v_783 = v_755;
// end of prologue
v_761:
    v_784 = v_783;
    if (v_784 == nil) goto v_764;
    else goto v_765;
v_764:
    goto v_760;
v_765:
    v_784 = v_783;
    v_784 = qcdr(v_784);
    stack[0] = v_784;
    goto v_777;
v_773:
    v_783 = qcar(v_783);
    goto v_774;
v_775:
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    v_782 = cons(v_783, v_782);
    env = stack[-1];
    v_783 = stack[0];
    goto v_761;
    v_782 = nil;
v_760:
    return onevalue(v_782);
}



// Code for lalr_goto

static LispObject CC_lalr_goto(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_785, v_786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_785 = v_756;
    v_786 = v_755;
// end of prologue
    goto v_769;
v_765:
    stack[0] = v_786;
    goto v_766;
v_767:
    goto v_776;
v_772:
    v_786 = v_785;
    goto v_773;
v_774:
    v_785 = qvalue(elt(env, 1)); // goto_table
    goto v_775;
v_776:
    goto v_772;
v_773:
    goto v_774;
v_775:
    fn = elt(env, 2); // gethash
    v_785 = (*qfn2(fn))(fn, v_786, v_785);
    goto v_768;
v_769:
    goto v_765;
v_766:
    goto v_767;
v_768:
    v_785 = Lassoc(nil, stack[0], v_785);
    v_786 = v_785;
    if (v_785 == nil) goto v_764;
    v_785 = v_786;
    v_785 = qcdr(v_785);
    goto v_760;
v_764:
    v_785 = nil;
    goto v_760;
    v_785 = nil;
v_760:
    return onevalue(v_785);
}



// Code for !*!*s2a

static LispObject CC_HHs2a(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_759, v_760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_759 = v_756;
    v_760 = v_755;
// end of prologue
    v_759 = v_760;
    return onevalue(v_759);
}



// Code for lnc

static LispObject CC_lnc(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_785, v_786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_785 = v_755;
// end of prologue
v_759:
    v_786 = v_785;
    if (v_786 == nil) goto v_762;
    else goto v_763;
v_762:
    v_785 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_763:
    v_786 = v_785;
    if (!consp(v_786)) goto v_770;
    else goto v_771;
v_770:
    v_786 = lisp_true;
    goto v_769;
v_771:
    v_786 = v_785;
    v_786 = qcar(v_786);
    v_786 = (consp(v_786) ? nil : lisp_true);
    goto v_769;
    v_786 = nil;
v_769:
    if (v_786 == nil) goto v_767;
    goto v_758;
v_767:
    v_785 = qcar(v_785);
    v_785 = qcdr(v_785);
    goto v_759;
    v_785 = nil;
v_758:
    return onevalue(v_785);
}



// Code for mtchp

static LispObject CC_mtchp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_881, v_882, v_883, v_884;
    LispObject fn;
    LispObject v_759, v_758, v_757, v_756, v_755;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "mtchp");
    va_start(aa, nargs);
    v_755 = va_arg(aa, LispObject);
    v_756 = va_arg(aa, LispObject);
    v_757 = va_arg(aa, LispObject);
    v_758 = va_arg(aa, LispObject);
    v_759 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_759,v_758,v_757,v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_755,v_756,v_757,v_758,v_759);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_759;
    v_881 = v_758;
    stack[-1] = v_757;
    stack[-2] = v_756;
    stack[-3] = v_755;
// end of prologue
    goto v_775;
v_767:
    v_884 = stack[-3];
    goto v_768;
v_769:
    v_883 = stack[-2];
    goto v_770;
v_771:
    v_882 = v_881;
    goto v_772;
v_773:
    v_881 = stack[0];
    goto v_774;
v_775:
    goto v_767;
v_768:
    goto v_769;
v_770:
    goto v_771;
v_772:
    goto v_773;
v_774:
    fn = elt(env, 1); // mtchp1
    v_881 = (*qfnn(fn))(fn, 4, v_884, v_883, v_882, v_881);
    env = stack[-5];
    stack[-4] = v_881;
v_764:
    v_881 = stack[-4];
    if (v_881 == nil) goto v_782;
    else goto v_783;
v_782:
    v_881 = nil;
    goto v_763;
v_783:
    goto v_794;
v_790:
    v_881 = stack[-4];
    v_882 = qcar(v_881);
    goto v_791;
v_792:
    v_881 = stack[0];
    goto v_793;
v_794:
    goto v_790;
v_791:
    goto v_792;
v_793:
    v_881 = Lsubla(nil, v_882, v_881);
    env = stack[-5];
    fn = elt(env, 2); // lispeval
    v_881 = (*qfn1(fn))(fn, v_881);
    env = stack[-5];
    if (v_881 == nil) goto v_787;
    goto v_765;
v_787:
    v_881 = stack[-4];
    v_881 = qcdr(v_881);
    stack[-4] = v_881;
    goto v_764;
v_765:
    goto v_805;
v_801:
    v_881 = stack[-3];
    stack[0] = qcdr(v_881);
    goto v_802;
v_803:
    goto v_813;
v_809:
    v_881 = stack[-4];
    v_882 = qcar(v_881);
    goto v_810;
v_811:
    v_881 = stack[-2];
    v_881 = qcdr(v_881);
    goto v_812;
v_813:
    goto v_809;
v_810:
    goto v_811;
v_812:
    v_881 = Lsubla(nil, v_882, v_881);
    env = stack[-5];
    goto v_804;
v_805:
    goto v_801;
v_802:
    goto v_803;
v_804:
    v_881 = Ldivide(nil, stack[0], v_881);
    env = stack[-5];
    stack[-2] = v_881;
    goto v_823;
v_819:
    goto v_830;
v_826:
    v_881 = stack[-4];
    v_882 = qcar(v_881);
    goto v_827;
v_828:
    v_881 = stack[-1];
    goto v_829;
v_830:
    goto v_826;
v_827:
    goto v_828;
v_829:
    v_881 = Lsubla(nil, v_882, v_881);
    env = stack[-5];
    fn = elt(env, 3); // simp
    v_882 = (*qfn1(fn))(fn, v_881);
    env = stack[-5];
    goto v_820;
v_821:
    v_881 = stack[-2];
    v_881 = qcar(v_881);
    goto v_822;
v_823:
    goto v_819;
v_820:
    goto v_821;
v_822:
    fn = elt(env, 4); // exptsq
    v_881 = (*qfn2(fn))(fn, v_882, v_881);
    env = stack[-5];
    stack[-1] = v_881;
    goto v_844;
v_840:
    v_881 = stack[-2];
    v_882 = qcdr(v_881);
    goto v_841;
v_842:
    v_881 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_843;
v_844:
    goto v_840;
v_841:
    goto v_842;
v_843:
    if (v_882 == v_881) goto v_839;
    goto v_853;
v_849:
    goto v_859;
v_855:
    goto v_866;
v_862:
    goto v_872;
v_868:
    v_881 = stack[-3];
    v_882 = qcar(v_881);
    goto v_869;
v_870:
    v_881 = stack[-2];
    v_881 = qcdr(v_881);
    goto v_871;
v_872:
    goto v_868;
v_869:
    goto v_870;
v_871:
    fn = elt(env, 5); // to
    v_882 = (*qfn2(fn))(fn, v_882, v_881);
    env = stack[-5];
    goto v_863;
v_864:
    v_881 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_865;
v_866:
    goto v_862;
v_863:
    goto v_864;
v_865:
    v_881 = cons(v_882, v_881);
    env = stack[-5];
    v_882 = ncons(v_881);
    env = stack[-5];
    goto v_856;
v_857:
    v_881 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_858;
v_859:
    goto v_855;
v_856:
    goto v_857;
v_858:
    v_882 = cons(v_882, v_881);
    env = stack[-5];
    goto v_850;
v_851:
    v_881 = stack[-1];
    goto v_852;
v_853:
    goto v_849;
v_850:
    goto v_851;
v_852:
    fn = elt(env, 6); // multsq
    v_881 = (*qfn2(fn))(fn, v_882, v_881);
    stack[-1] = v_881;
    goto v_837;
v_839:
v_837:
    v_881 = stack[-1];
v_763:
    return onevalue(v_881);
}



// Code for absf

static LispObject CC_absf(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    v_768 = stack[0];
    fn = elt(env, 1); // minusf
    v_768 = (*qfn1(fn))(fn, v_768);
    env = stack[-1];
    if (v_768 == nil) goto v_760;
    v_768 = stack[0];
    {
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(fn, v_768);
    }
v_760:
    v_768 = stack[0];
    goto v_758;
    v_768 = nil;
v_758:
    return onevalue(v_768);
}



// Code for lex

static LispObject CC_lex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_866, v_867;
    LispObject fn;
    argcheck(nargs, 0, "lex");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
// Binding safe_atts
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // safe_atts
    v_866 = nil;
    qvalue(elt(env, 2)) = v_866; // char
    v_866 = qvalue(elt(env, 3)); // atts
    if (v_866 == nil) goto v_765;
    v_866 = qvalue(elt(env, 3)); // atts
    qvalue(elt(env, 1)) = v_866; // safe_atts
    goto v_763;
v_765:
v_763:
    v_866 = nil;
    qvalue(elt(env, 3)) = v_866; // atts
    goto v_777;
v_773:
    stack[0] = qvalue(elt(env, 4)); // ch
    goto v_774;
v_775:
    v_866 = (LispObject)160+TAG_FIXNUM; // 10
    v_866 = ncons(v_866);
    env = stack[-2];
    fn = elt(env, 9); // list2string
    v_866 = (*qfn1(fn))(fn, v_866);
    env = stack[-2];
    v_866 = Lintern(nil, v_866);
    env = stack[-2];
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    if (stack[0] == v_866) goto v_771;
    else goto v_772;
v_771:
    v_866 = Lreadch(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_866; // ch
    goto v_770;
v_772:
v_770:
    goto v_792;
v_788:
    v_867 = qvalue(elt(env, 4)); // ch
    goto v_789;
v_790:
    v_866 = qvalue(elt(env, 5)); // !$eof!$
    goto v_791;
v_792:
    goto v_788;
v_789:
    goto v_790;
v_791:
    if (equal(v_867, v_866)) goto v_787;
    goto v_803;
v_799:
    v_867 = qvalue(elt(env, 4)); // ch
    goto v_800;
v_801:
    v_866 = qvalue(elt(env, 6)); // space
    goto v_802;
v_803:
    goto v_799;
v_800:
    goto v_801;
v_802:
    if (equal(v_867, v_866)) goto v_797;
    else goto v_798;
v_797:
v_808:
    goto v_818;
v_814:
    v_867 = Lreadch(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_867; // ch
    goto v_815;
v_816:
    v_866 = qvalue(elt(env, 6)); // space
    goto v_817;
v_818:
    goto v_814;
v_815:
    goto v_816;
v_817:
    if (equal(v_867, v_866)) goto v_813;
    goto v_807;
v_813:
    goto v_808;
v_807:
    goto v_796;
v_798:
    goto v_828;
v_824:
    v_867 = qvalue(elt(env, 4)); // ch
    goto v_825;
v_826:
    v_866 = elt(env, 7); // !<
    goto v_827;
v_828:
    goto v_824;
v_825:
    goto v_826;
v_827:
    if (v_867 == v_866) goto v_822;
    else goto v_823;
v_822:
    fn = elt(env, 10); // get_token
    v_866 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_866; // char
    goto v_796;
v_823:
    fn = elt(env, 11); // get_content
    v_866 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_866; // char
    goto v_796;
v_796:
    v_866 = qvalue(elt(env, 2)); // char
    if (v_866 == nil) goto v_838;
    v_866 = qvalue(elt(env, 8)); // count
    v_866 = add1(v_866);
    env = stack[-2];
    qvalue(elt(env, 8)) = v_866; // count
    v_866 = qvalue(elt(env, 2)); // char
    v_866 = Lreverse(nil, v_866);
    env = stack[-2];
    stack[0] = v_866;
    v_866 = qvalue(elt(env, 2)); // char
    fn = elt(env, 12); // notstring
    v_866 = (*qfn1(fn))(fn, v_866);
    env = stack[-2];
    if (v_866 == nil) goto v_847;
    v_866 = stack[0];
    fn = elt(env, 13); // butes
    v_866 = (*qfn1(fn))(fn, v_866);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_866; // char
    v_866 = qvalue(elt(env, 2)); // char
    fn = elt(env, 14); // isvalid
    v_866 = (*qfn1(fn))(fn, v_866);
    env = stack[-2];
    goto v_859;
v_855:
    v_867 = qvalue(elt(env, 2)); // char
    goto v_856;
v_857:
    v_866 = stack[0];
    goto v_858;
v_859:
    goto v_855;
v_856:
    goto v_857;
v_858:
    fn = elt(env, 15); // attributes
    v_866 = (*qfn2(fn))(fn, v_867, v_866);
    goto v_845;
v_847:
v_845:
    goto v_836;
v_838:
    v_866 = CC_lex(elt(env, 0), 0);
    goto v_836;
v_836:
    goto v_785;
v_787:
v_785:
    v_866 = nil;
    ;}  // end of a binding scope
    return onevalue(v_866);
}



// Code for replus1

static LispObject CC_replus1(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_807, v_808, v_809;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_809 = v_755;
// end of prologue
    v_807 = v_809;
    if (v_807 == nil) goto v_759;
    else goto v_760;
v_759:
    v_807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_760:
    v_807 = v_809;
    if (!consp(v_807)) goto v_767;
    else goto v_768;
v_767:
    v_807 = lisp_true;
    goto v_766;
v_768:
    goto v_782;
v_778:
    v_808 = v_809;
    goto v_779;
v_780:
    v_807 = elt(env, 1); // plus
    goto v_781;
v_782:
    goto v_778;
v_779:
    goto v_780;
v_781:
    if (!consp(v_808)) goto v_776;
    v_808 = qcar(v_808);
    if (v_808 == v_807) goto v_775;
    else goto v_776;
v_775:
    v_807 = v_809;
    v_807 = qcdr(v_807);
    goto v_774;
v_776:
    v_807 = nil;
    goto v_774;
    v_807 = nil;
v_774:
    goto v_766;
    v_807 = nil;
v_766:
    if (v_807 == nil) goto v_764;
    v_807 = v_809;
    goto v_758;
v_764:
    v_807 = v_809;
    v_807 = qcdr(v_807);
    if (v_807 == nil) goto v_791;
    else goto v_792;
v_791:
    v_807 = v_809;
    v_807 = qcar(v_807);
    goto v_758;
v_792:
    goto v_804;
v_800:
    v_807 = elt(env, 1); // plus
    goto v_801;
v_802:
    v_808 = v_809;
    goto v_803;
v_804:
    goto v_800;
v_801:
    goto v_802;
v_803:
    return cons(v_807, v_808);
    v_807 = nil;
v_758:
    return onevalue(v_807);
}



// Code for !*q2a1

static LispObject CC_Hq2a1(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_769, v_770;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_769 = v_756;
    v_770 = v_755;
// end of prologue
    if (v_769 == nil) goto v_760;
    else goto v_761;
v_760:
    v_769 = v_770;
    {
        fn = elt(env, 1); // mk!*sq
        return (*qfn1(fn))(fn, v_769);
    }
v_761:
    v_769 = v_770;
    {
        fn = elt(env, 2); // prepsqxx
        return (*qfn1(fn))(fn, v_769);
    }
    v_769 = nil;
    return onevalue(v_769);
}



// Code for peel

static LispObject CC_peel(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_815, v_816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    goto v_765;
v_761:
    v_815 = stack[0];
    v_816 = qcar(v_815);
    goto v_762;
v_763:
    v_815 = elt(env, 1); // (liedf innerprod)
    goto v_764;
v_765:
    goto v_761;
v_762:
    goto v_763;
v_764:
    v_815 = Lmemq(nil, v_816, v_815);
    if (v_815 == nil) goto v_760;
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_815 = qcdr(v_815);
    v_815 = qcar(v_815);
    goto v_758;
v_760:
    goto v_780;
v_776:
    v_815 = stack[0];
    v_816 = qcar(v_815);
    goto v_777;
v_778:
    v_815 = elt(env, 2); // quotient
    goto v_779;
v_780:
    goto v_776;
v_777:
    goto v_778;
v_779:
    if (v_816 == v_815) goto v_774;
    else goto v_775;
v_774:
    goto v_793;
v_789:
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_816 = qcar(v_815);
    goto v_790;
v_791:
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_815 = qcdr(v_815);
    v_815 = qcar(v_815);
    goto v_792;
v_793:
    goto v_789;
v_790:
    goto v_791;
v_792:
    fn = elt(env, 3); // worderp
    v_815 = (*qfn2(fn))(fn, v_816, v_815);
    if (v_815 == nil) goto v_787;
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_815 = qcar(v_815);
    goto v_785;
v_787:
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_815 = qcdr(v_815);
    v_815 = qcar(v_815);
    goto v_785;
    v_815 = nil;
v_785:
    goto v_758;
v_775:
    v_815 = stack[0];
    v_815 = qcdr(v_815);
    v_815 = qcar(v_815);
    goto v_758;
    v_815 = nil;
v_758:
    return onevalue(v_815);
}



// Code for mo_ecart

static LispObject CC_mo_ecart(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_803, v_804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
    v_803 = stack[0];
    v_803 = qcar(v_803);
    if (v_803 == nil) goto v_759;
    else goto v_760;
v_759:
    v_803 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_760:
    goto v_770;
v_766:
    v_803 = stack[0];
    fn = elt(env, 3); // mo_comp
    v_804 = (*qfn1(fn))(fn, v_803);
    env = stack[-1];
    goto v_767;
v_768:
    v_803 = qvalue(elt(env, 1)); // cali!=degrees
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    v_803 = Latsoc(nil, v_804, v_803);
    v_804 = v_803;
    goto v_781;
v_777:
    v_803 = v_804;
    if (v_803 == nil) goto v_785;
    goto v_792;
v_788:
    v_803 = v_804;
    v_804 = qcdr(v_803);
    goto v_789;
v_790:
    v_803 = stack[0];
    goto v_791;
v_792:
    goto v_788;
v_789:
    goto v_790;
v_791:
    fn = elt(env, 4); // mo_sum
    v_803 = (*qfn2(fn))(fn, v_804, v_803);
    env = stack[-1];
    goto v_783;
v_785:
    v_803 = stack[0];
    goto v_783;
    v_803 = nil;
v_783:
    v_803 = qcar(v_803);
    stack[0] = qcdr(v_803);
    goto v_778;
v_779:
    v_803 = qvalue(elt(env, 2)); // cali!=basering
    fn = elt(env, 5); // ring_ecart
    v_803 = (*qfn1(fn))(fn, v_803);
    env = stack[-1];
    goto v_780;
v_781:
    goto v_777;
v_778:
    goto v_779;
v_780:
    {
        LispObject v_806 = stack[0];
        fn = elt(env, 6); // mo!=sprod
        return (*qfn2(fn))(fn, v_806, v_803);
    }
    v_803 = nil;
v_758:
    return onevalue(v_803);
}



// Code for pv_sort

static LispObject CC_pv_sort(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_776, v_777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_777 = v_755;
// end of prologue
    v_776 = v_777;
    if (v_776 == nil) goto v_759;
    else goto v_760;
v_759:
    v_776 = nil;
    goto v_758;
v_760:
    goto v_770;
v_766:
    v_776 = v_777;
    stack[0] = qcdr(v_776);
    goto v_767;
v_768:
    v_776 = v_777;
    v_776 = qcar(v_776);
    v_776 = ncons(v_776);
    env = stack[-1];
    goto v_769;
v_770:
    goto v_766;
v_767:
    goto v_768;
v_769:
    {
        LispObject v_779 = stack[0];
        fn = elt(env, 1); // pv_sort1
        return (*qfn2(fn))(fn, v_779, v_776);
    }
    v_776 = nil;
v_758:
    return onevalue(v_776);
}



// Code for flatten!-sorted!-tree

static LispObject CC_flattenKsortedKtree(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_792, v_793, v_794;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_792 = v_756;
    v_793 = v_755;
// end of prologue
v_761:
    v_794 = v_793;
    if (v_794 == nil) goto v_764;
    else goto v_765;
v_764:
    goto v_760;
v_765:
    v_794 = v_793;
    v_794 = qcar(v_794);
    stack[-1] = v_794;
    goto v_777;
v_773:
    v_794 = v_793;
    v_794 = qcdr(v_794);
    stack[0] = qcar(v_794);
    goto v_774;
v_775:
    goto v_786;
v_782:
    v_793 = qcdr(v_793);
    v_793 = qcdr(v_793);
    goto v_783;
v_784:
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    v_792 = CC_flattenKsortedKtree(elt(env, 0), v_793, v_792);
    env = stack[-2];
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    v_792 = cons(stack[0], v_792);
    env = stack[-2];
    v_793 = stack[-1];
    goto v_761;
    v_792 = nil;
v_760:
    return onevalue(v_792);
}



// Code for ofsf_posdefp

static LispObject CC_ofsf_posdefp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_768, v_769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_769 = v_755;
// end of prologue
    v_768 = qvalue(elt(env, 1)); // !*rlpos
    if (v_768 == nil) goto v_760;
    v_768 = v_769;
    {
        fn = elt(env, 2); // ofsf_posdefp!-pos
        return (*qfn1(fn))(fn, v_768);
    }
v_760:
    v_768 = v_769;
    {
        fn = elt(env, 3); // sfto_tsqsumf
        return (*qfn1(fn))(fn, v_768);
    }
    v_768 = nil;
    return onevalue(v_768);
}



// Code for reordop

static LispObject CC_reordop(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_810, v_811;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_755,v_756);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_756;
    stack[-1] = v_755;
// end of prologue
    goto v_767;
v_763:
    v_811 = stack[-1];
    goto v_764;
v_765:
    v_810 = stack[0];
    goto v_766;
v_767:
    goto v_763;
v_764:
    goto v_765;
v_766:
    fn = elt(env, 2); // reordablep
    v_810 = (*qfn2(fn))(fn, v_811, v_810);
    env = stack[-2];
    if (v_810 == nil) goto v_761;
    goto v_775;
v_771:
    v_811 = stack[-1];
    goto v_772;
v_773:
    v_810 = stack[0];
    goto v_774;
v_775:
    goto v_771;
v_772:
    goto v_773;
v_774:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_811, v_810);
    }
v_761:
    v_810 = qvalue(elt(env, 1)); // !*ncmp
    if (v_810 == nil) goto v_785;
    else goto v_786;
v_785:
    v_810 = nil;
    goto v_784;
v_786:
    v_810 = stack[-1];
    fn = elt(env, 4); // noncomp1
    v_810 = (*qfn1(fn))(fn, v_810);
    env = stack[-2];
    if (v_810 == nil) goto v_793;
    else goto v_794;
v_793:
    v_810 = nil;
    goto v_792;
v_794:
    v_810 = stack[0];
    fn = elt(env, 4); // noncomp1
    v_810 = (*qfn1(fn))(fn, v_810);
    env = stack[-2];
    goto v_792;
    v_810 = nil;
v_792:
    goto v_784;
    v_810 = nil;
v_784:
    if (v_810 == nil) goto v_782;
    else goto v_781;
v_782:
    goto v_807;
v_803:
    v_811 = stack[-1];
    goto v_804;
v_805:
    v_810 = stack[0];
    goto v_806;
v_807:
    goto v_803;
v_804:
    goto v_805;
v_806:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_811, v_810);
    }
v_781:
    goto v_759;
    v_810 = nil;
v_759:
    return onevalue(v_810);
}



// Code for free!-powerp

static LispObject CC_freeKpowerp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_797;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_755;
// end of prologue
v_754:
    v_797 = stack[0];
    if (!consp(v_797)) goto v_763;
    else goto v_764;
v_763:
    v_797 = lisp_true;
    goto v_762;
v_764:
    v_797 = stack[0];
    v_797 = qcar(v_797);
    v_797 = (consp(v_797) ? nil : lisp_true);
    goto v_762;
    v_797 = nil;
v_762:
    if (v_797 == nil) goto v_759;
    else goto v_760;
v_759:
    v_797 = stack[0];
    v_797 = qcar(v_797);
    v_797 = qcar(v_797);
    v_797 = qcdr(v_797);
    v_797 = integerp(v_797);
    if (v_797 == nil) goto v_774;
    else goto v_775;
v_774:
    v_797 = lisp_true;
    goto v_773;
v_775:
    v_797 = stack[0];
    v_797 = qcar(v_797);
    v_797 = qcdr(v_797);
    v_797 = CC_freeKpowerp(elt(env, 0), v_797);
    env = stack[-1];
    if (v_797 == nil) goto v_786;
    else goto v_785;
v_786:
    v_797 = stack[0];
    v_797 = qcdr(v_797);
    stack[0] = v_797;
    goto v_754;
v_785:
    goto v_773;
    v_797 = nil;
v_773:
    goto v_758;
v_760:
    v_797 = nil;
    goto v_758;
    v_797 = nil;
v_758:
    return onevalue(v_797);
}



// Code for retimes

static LispObject CC_retimes(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_800, v_801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_800 = v_755;
// end of prologue
// Binding !*bool
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*bool
    fn = elt(env, 4); // retimes1
    v_800 = (*qfn1(fn))(fn, v_800);
    env = stack[-1];
    v_801 = v_800;
    if (v_801 == nil) goto v_764;
    else goto v_765;
v_764:
    v_800 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_763;
v_765:
    v_801 = v_800;
    v_801 = qcdr(v_801);
    if (v_801 == nil) goto v_769;
    goto v_777;
v_773:
    v_801 = elt(env, 2); // times
    goto v_774;
v_775:
    goto v_776;
v_777:
    goto v_773;
v_774:
    goto v_775;
v_776:
    v_800 = cons(v_801, v_800);
    env = stack[-1];
    goto v_763;
v_769:
    v_800 = qcar(v_800);
    goto v_763;
    v_800 = nil;
v_763:
    v_801 = qvalue(elt(env, 1)); // !*bool
    if (v_801 == nil) goto v_787;
    goto v_794;
v_790:
    v_801 = elt(env, 3); // minus
    goto v_791;
v_792:
    goto v_793;
v_794:
    goto v_790;
v_791:
    goto v_792;
v_793:
    v_800 = list2(v_801, v_800);
    goto v_785;
v_787:
    goto v_785;
    v_800 = nil;
v_785:
    ;}  // end of a binding scope
    return onevalue(v_800);
}



// Code for mkwedge

static LispObject CC_mkwedge(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_769, v_770, v_771;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
// copy arguments values to proper place
    v_769 = v_755;
// end of prologue
    goto v_765;
v_759:
    v_771 = v_769;
    goto v_760;
v_761:
    v_770 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_762;
v_763:
    v_769 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_764;
v_765:
    goto v_759;
v_760:
    goto v_761;
v_762:
    goto v_763;
v_764:
    v_769 = list2star(v_771, v_770, v_769);
    return ncons(v_769);
}



// Code for idlistp

static LispObject CC_idlistp(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_785, v_786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_785 = v_755;
// end of prologue
v_754:
    v_786 = v_785;
    if (v_786 == nil) goto v_759;
    else goto v_760;
v_759:
    v_785 = lisp_true;
    goto v_758;
v_760:
    v_786 = v_785;
    if (!consp(v_786)) goto v_768;
    v_786 = v_785;
    v_786 = qcar(v_786);
    if (symbolp(v_786)) goto v_773;
    v_785 = nil;
    goto v_771;
v_773:
    v_785 = qcdr(v_785);
    goto v_754;
    v_785 = nil;
v_771:
    goto v_766;
v_768:
    v_785 = nil;
    goto v_766;
    v_785 = nil;
v_766:
    goto v_758;
    v_785 = nil;
v_758:
    return onevalue(v_785);
}



// Code for qassoc

static LispObject CC_qassoc(LispObject env,
                         LispObject v_755, LispObject v_756)
{
    env = qenv(env);
    LispObject v_784, v_785, v_786, v_787;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_785 = v_756;
    v_786 = v_755;
// end of prologue
v_760:
    v_784 = v_785;
    if (v_784 == nil) goto v_763;
    else goto v_764;
v_763:
    v_784 = nil;
    goto v_759;
v_764:
    goto v_773;
v_769:
    v_787 = v_786;
    goto v_770;
v_771:
    v_784 = v_785;
    v_784 = qcar(v_784);
    v_784 = qcar(v_784);
    goto v_772;
v_773:
    goto v_769;
v_770:
    goto v_771;
v_772:
    if (v_787 == v_784) goto v_767;
    else goto v_768;
v_767:
    v_784 = v_785;
    v_784 = qcar(v_784);
    goto v_759;
v_768:
    v_784 = v_785;
    v_784 = qcdr(v_784);
    v_785 = v_784;
    goto v_760;
    v_784 = nil;
v_759:
    return onevalue(v_784);
}



// Code for negf

static LispObject CC_negf(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_835, v_836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_755;
// end of prologue
    stack[-2] = nil;
v_760:
    v_835 = stack[-1];
    if (v_835 == nil) goto v_763;
    else goto v_764;
v_763:
    v_835 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_835);
    }
v_764:
    v_835 = stack[-1];
    if (!consp(v_835)) goto v_772;
    else goto v_773;
v_772:
    v_835 = lisp_true;
    goto v_771;
v_773:
    v_835 = stack[-1];
    v_835 = qcar(v_835);
    v_835 = (consp(v_835) ? nil : lisp_true);
    goto v_771;
    v_835 = nil;
v_771:
    if (v_835 == nil) goto v_769;
    goto v_786;
v_782:
    stack[0] = stack[-2];
    goto v_783;
v_784:
    v_835 = stack[-1];
    if (!consp(v_835)) goto v_795;
    else goto v_796;
v_795:
    v_835 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_835)) v_835 = nil;
    else { v_835 = qfastgets(v_835);
           if (v_835 != nil) { v_835 = elt(v_835, 5); // convert
#ifdef RECORD_GET
             if (v_835 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_835 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_835 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_835 == SPID_NOPROP) v_835 = nil; else v_835 = lisp_true; }}
#endif
    goto v_794;
v_796:
    v_835 = nil;
    goto v_794;
    v_835 = nil;
v_794:
    if (v_835 == nil) goto v_792;
    goto v_808;
v_804:
    v_835 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_835)) v_836 = nil;
    else { v_836 = qfastgets(v_835);
           if (v_836 != nil) { v_836 = elt(v_836, 34); // i2d
#ifdef RECORD_GET
             if (v_836 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_836 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_836 == SPID_NOPROP) v_836 = nil; }}
#endif
    goto v_805;
v_806:
    v_835 = stack[-1];
    goto v_807;
v_808:
    goto v_804;
v_805:
    goto v_806;
v_807:
    v_835 = Lapply1(nil, v_836, v_835);
    env = stack[-3];
    goto v_790;
v_792:
    v_835 = stack[-1];
    goto v_790;
    v_835 = nil;
v_790:
    fn = elt(env, 3); // !:minus
    v_835 = (*qfn1(fn))(fn, v_835);
    env = stack[-3];
    goto v_785;
v_786:
    goto v_782;
v_783:
    goto v_784;
v_785:
    {
        LispObject v_840 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_840, v_835);
    }
v_769:
    goto v_824;
v_818:
    v_835 = stack[-1];
    v_835 = qcar(v_835);
    stack[0] = qcar(v_835);
    goto v_819;
v_820:
    v_835 = stack[-1];
    v_835 = qcar(v_835);
    v_835 = qcdr(v_835);
    v_836 = CC_negf(elt(env, 0), v_835);
    env = stack[-3];
    goto v_821;
v_822:
    v_835 = stack[-2];
    goto v_823;
v_824:
    goto v_818;
v_819:
    goto v_820;
v_821:
    goto v_822;
v_823:
    v_835 = acons(stack[0], v_836, v_835);
    env = stack[-3];
    stack[-2] = v_835;
    v_835 = stack[-1];
    v_835 = qcdr(v_835);
    stack[-1] = v_835;
    goto v_760;
    v_835 = nil;
    return onevalue(v_835);
}



// Code for formlis

static LispObject CC_formlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_794, v_795, v_796;
    LispObject fn;
    LispObject v_757, v_756, v_755;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formlis");
    va_start(aa, nargs);
    v_755 = va_arg(aa, LispObject);
    v_756 = va_arg(aa, LispObject);
    v_757 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_757,v_756,v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_755,v_756,v_757);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_757;
    stack[-1] = v_756;
    stack[-2] = v_755;
// end of prologue
    stack[-3] = nil;
v_764:
    v_794 = stack[-2];
    if (v_794 == nil) goto v_767;
    else goto v_768;
v_767:
    goto v_763;
v_768:
    goto v_776;
v_772:
    goto v_784;
v_778:
    v_794 = stack[-2];
    v_796 = qcar(v_794);
    goto v_779;
v_780:
    v_795 = stack[-1];
    goto v_781;
v_782:
    v_794 = stack[0];
    goto v_783;
v_784:
    goto v_778;
v_779:
    goto v_780;
v_781:
    goto v_782;
v_783:
    fn = elt(env, 1); // form1
    v_795 = (*qfnn(fn))(fn, 3, v_796, v_795, v_794);
    env = stack[-4];
    goto v_773;
v_774:
    v_794 = stack[-3];
    goto v_775;
v_776:
    goto v_772;
v_773:
    goto v_774;
v_775:
    v_794 = cons(v_795, v_794);
    env = stack[-4];
    stack[-3] = v_794;
    v_794 = stack[-2];
    v_794 = qcdr(v_794);
    stack[-2] = v_794;
    goto v_764;
v_763:
    v_794 = stack[-3];
    {
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(fn, v_794);
    }
    return onevalue(v_794);
}



// Code for nonzero!-length

static LispObject CC_nonzeroKlength(LispObject env,
                         LispObject v_755)
{
    env = qenv(env);
    LispObject v_784, v_785, v_786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_755);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_755);
    }
// copy arguments values to proper place
    v_785 = v_755;
// end of prologue
v_759:
    v_784 = v_785;
    if (v_784 == nil) goto v_762;
    else goto v_763;
v_762:
    v_784 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_758;
v_763:
    goto v_772;
v_768:
    v_784 = v_785;
    v_786 = qcar(v_784);
    goto v_769;
v_770:
    v_784 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_771;
v_772:
    goto v_768;
v_769:
    goto v_770;
v_771:
    if (v_786 == v_784) goto v_766;
    else goto v_767;
v_766:
    v_784 = v_785;
    v_784 = qcdr(v_784);
    v_785 = v_784;
    goto v_759;
v_767:
    v_784 = v_785;
    v_784 = qcdr(v_784);
    v_784 = CC_nonzeroKlength(elt(env, 0), v_784);
    return add1(v_784);
    v_784 = nil;
v_758:
    return onevalue(v_784);
}



setup_type const u03_setup[] =
{
    {"get_content",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_get_content},
    {":zerop",                  CC_Tzerop,      TOO_MANY_1,    WRONG_NO_1},
    {"rd:zerop",                CC_rdTzerop,    TOO_MANY_1,    WRONG_NO_1},
    {"wedgepf2",                TOO_FEW_2,      CC_wedgepf2,   WRONG_NO_2},
    {"*physopp*",               CC_HphysoppH,   TOO_MANY_1,    WRONG_NO_1},
    {"union_edges",             TOO_FEW_2,      CC_union_edges,WRONG_NO_2},
    {"errorp",                  CC_errorp,      TOO_MANY_1,    WRONG_NO_1},
    {"cdiv",                    TOO_FEW_2,      CC_cdiv,       WRONG_NO_2},
    {"add_prin_char",           TOO_FEW_2,      CC_add_prin_char,WRONG_NO_2},
    {"pv_multc",                TOO_FEW_2,      CC_pv_multc,   WRONG_NO_2},
    {"upbve",                   CC_upbve,       TOO_MANY_1,    WRONG_NO_1},
    {"striptag",                CC_striptag,    TOO_MANY_1,    WRONG_NO_1},
    {"lalr_compute_lr0_goto",   TOO_FEW_2,      CC_lalr_compute_lr0_goto,WRONG_NO_2},
    {"toknump",                 CC_toknump,     TOO_MANY_1,    WRONG_NO_1},
    {"symbollessp",             TOO_FEW_2,      CC_symbollessp,WRONG_NO_2},
    {"lt*",                     CC_ltH,         TOO_MANY_1,    WRONG_NO_1},
    {"nocp",                    CC_nocp,        TOO_MANY_1,    WRONG_NO_1},
    {"subs2f",                  CC_subs2f,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simpat",             CC_talp_simpat, TOO_MANY_1,    WRONG_NO_1},
    {"pasf_susitf",             TOO_FEW_2,      CC_pasf_susitf,WRONG_NO_2},
    {"gcdfd",                   TOO_FEW_2,      CC_gcdfd,      WRONG_NO_2},
    {"printout",                CC_printout,    TOO_MANY_1,    WRONG_NO_1},
    {"initcomb",                CC_initcomb,    TOO_MANY_1,    WRONG_NO_1},
    {"evcompless?",             TOO_FEW_2,      CC_evcomplessW,WRONG_NO_2},
    {"evmatrixcomp",            TOO_FEW_2,      CC_evmatrixcomp,WRONG_NO_2},
    {"pprin2",                  CC_pprin2,      TOO_MANY_1,    WRONG_NO_1},
    {"opmtch*",                 CC_opmtchH,     TOO_MANY_1,    WRONG_NO_1},
    {"timesip",                 CC_timesip,     TOO_MANY_1,    WRONG_NO_1},
    {"fs:timestermterm",        TOO_FEW_2,      CC_fsTtimestermterm,WRONG_NO_2},
    {"mo_vdivides?",            TOO_FEW_2,      CC_mo_vdividesW,WRONG_NO_2},
    {"dless",                   TOO_FEW_2,      CC_dless,      WRONG_NO_2},
    {"pv_sort2",                TOO_FEW_2,      CC_pv_sort2,   WRONG_NO_2},
    {"*i2rn",                   CC_Hi2rn,       TOO_MANY_1,    WRONG_NO_1},
    {"lalr_propagate_lookaheads",CC_lalr_propagate_lookaheads,TOO_MANY_1,WRONG_NO_1},
    {"monomcomparedegrevlex",   TOO_FEW_2,      CC_monomcomparedegrevlex,WRONG_NO_2},
    {"reordsq",                 CC_reordsq,     TOO_MANY_1,    WRONG_NO_1},
    {"delallasc",               TOO_FEW_2,      CC_delallasc,  WRONG_NO_2},
    {"rmultpf",                 TOO_FEW_2,      CC_rmultpf,    WRONG_NO_2},
    {"gcdfd1",                  TOO_FEW_2,      CC_gcdfd1,     WRONG_NO_2},
    {"multsq",                  TOO_FEW_2,      CC_multsq,     WRONG_NO_2},
    {"rl_smupdknowl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_smupdknowl},
    {"qqe_nytidp",              CC_qqe_nytidp,  TOO_MANY_1,    WRONG_NO_1},
    {"bftrim:",                 CC_bftrimT,     TOO_MANY_1,    WRONG_NO_1},
    {"off1",                    CC_off1,        TOO_MANY_1,    WRONG_NO_1},
    {"mgenp",                   CC_mgenp,       TOO_MANY_1,    WRONG_NO_1},
    {"on1",                     CC_on1,         TOO_MANY_1,    WRONG_NO_1},
    {"evsum",                   TOO_FEW_2,      CC_evsum,      WRONG_NO_2},
    {"bcint2op",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_bcint2op},
    {"quotfm",                  TOO_FEW_2,      CC_quotfm,     WRONG_NO_2},
    {"*collectphysops_reversed",TOO_FEW_2,      CC_Hcollectphysops_reversed,WRONG_NO_2},
    {"constimes",               CC_constimes,   TOO_MANY_1,    WRONG_NO_1},
    {"arraychk",                CC_arraychk,    TOO_MANY_1,    WRONG_NO_1},
    {"fs:angle-order",          TOO_FEW_2,      CC_fsTangleKorder,WRONG_NO_2},
    {"cali_trace",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cali_trace},
    {"pcmult",                  TOO_FEW_2,      CC_pcmult,     WRONG_NO_2},
    {"pkp",                     CC_pkp,         TOO_MANY_1,    WRONG_NO_1},
    {"noncomp1",                CC_noncomp1,    TOO_MANY_1,    WRONG_NO_1},
    {"plus-mod-p",              TOO_FEW_2,      CC_plusKmodKp, WRONG_NO_2},
    {"split_form",              TOO_FEW_2,      CC_split_form, WRONG_NO_2},
    {"subs2q",                  CC_subs2q,      TOO_MANY_1,    WRONG_NO_1},
    {"qqe_btidp",               CC_qqe_btidp,   TOO_MANY_1,    WRONG_NO_1},
    {"prepsq",                  CC_prepsq,      TOO_MANY_1,    WRONG_NO_1},
    {"subs2*",                  CC_subs2H,      TOO_MANY_1,    WRONG_NO_1},
    {"negsq",                   CC_negsq,       TOO_MANY_1,    WRONG_NO_1},
    {"hasonephysop",            CC_hasonephysop,TOO_MANY_1,    WRONG_NO_1},
    {"errorset*",               TOO_FEW_2,      CC_errorsetH,  WRONG_NO_2},
    {"fs:timesterm",            TOO_FEW_2,      CC_fsTtimesterm,WRONG_NO_2},
    {"bas_rep",                 CC_bas_rep,     TOO_MANY_1,    WRONG_NO_1},
    {":minus",                  CC_Tminus,      TOO_MANY_1,    WRONG_NO_1},
    {"rev",                     TOO_FEW_2,      CC_rev,        WRONG_NO_2},
    {"lalr_goto",               TOO_FEW_2,      CC_lalr_goto,  WRONG_NO_2},
    {"**s2a",                   TOO_FEW_2,      CC_HHs2a,      WRONG_NO_2},
    {"lnc",                     CC_lnc,         TOO_MANY_1,    WRONG_NO_1},
    {"mtchp",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mtchp},
    {"absf",                    CC_absf,        TOO_MANY_1,    WRONG_NO_1},
    {"lex",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex},
    {"replus1",                 CC_replus1,     TOO_MANY_1,    WRONG_NO_1},
    {"*q2a1",                   TOO_FEW_2,      CC_Hq2a1,      WRONG_NO_2},
    {"peel",                    CC_peel,        TOO_MANY_1,    WRONG_NO_1},
    {"mo_ecart",                CC_mo_ecart,    TOO_MANY_1,    WRONG_NO_1},
    {"pv_sort",                 CC_pv_sort,     TOO_MANY_1,    WRONG_NO_1},
    {"flatten-sorted-tree",     TOO_FEW_2,      CC_flattenKsortedKtree,WRONG_NO_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,TOO_MANY_1,    WRONG_NO_1},
    {"reordop",                 TOO_FEW_2,      CC_reordop,    WRONG_NO_2},
    {"free-powerp",             CC_freeKpowerp, TOO_MANY_1,    WRONG_NO_1},
    {"retimes",                 CC_retimes,     TOO_MANY_1,    WRONG_NO_1},
    {"mkwedge",                 CC_mkwedge,     TOO_MANY_1,    WRONG_NO_1},
    {"idlistp",                 CC_idlistp,     TOO_MANY_1,    WRONG_NO_1},
    {"qassoc",                  TOO_FEW_2,      CC_qassoc,     WRONG_NO_2},
    {"negf",                    CC_negf,        TOO_MANY_1,    WRONG_NO_1},
    {"formlis",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formlis},
    {"nonzero-length",          CC_nonzeroKlength,TOO_MANY_1,  WRONG_NO_1},
    {NULL, (one_args *)"u03", (two_args *)"70889 2443995 4863155", 0}
};

// end of generated code
