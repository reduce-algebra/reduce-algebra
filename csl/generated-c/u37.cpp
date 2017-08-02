
// $destdir/u37.c        Machine generated C code

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



// Code for pasf_smordtable1

static LispObject CC_pasf_smordtable1(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20625, v_20626, v_20627;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20625 = v_20602;
    v_20626 = v_20601;
// end of prologue
    v_20627 = elt(env, 2); // ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1)
// (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1)
// (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2)
// (cong nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp
// (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)))
    goto v_20613;
v_20609:
    goto v_20610;
v_20611:
    goto v_20619;
v_20615:
    goto v_20616;
v_20617:
    goto v_20618;
v_20619:
    goto v_20615;
v_20616:
    goto v_20617;
v_20618:
    v_20626 = Latsoc(nil, v_20626, v_20627);
    goto v_20612;
v_20613:
    goto v_20609;
v_20610:
    goto v_20611;
v_20612:
    v_20625 = Latsoc(nil, v_20625, v_20626);
    v_20625 = qcdr(v_20625);
    return onevalue(v_20625);
}



// Code for ofsf_sippsignchkf

static LispObject CC_ofsf_sippsignchkf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20783, v_20784, v_20785, v_20786, v_20787, v_20788, v_20789;
    LispObject fn;
    LispObject v_20607, v_20606, v_20605, v_20604, v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    v_20604 = va_arg(aa, LispObject);
    v_20605 = va_arg(aa, LispObject);
    v_20606 = va_arg(aa, LispObject);
    v_20607 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_20607,v_20606,v_20605,v_20604,v_20603,v_20602);
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_20601,v_20602,v_20603,v_20604,v_20605,v_20606);
        pop(v_20607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-1] = v_20607;
    stack[-2] = v_20606;
    stack[-3] = v_20605;
    stack[-4] = v_20604;
    stack[-5] = v_20603;
    stack[-6] = v_20602;
    stack[-7] = v_20601;
// end of prologue
    v_20783 = stack[-7];
    if (!consp(v_20783)) goto v_20622;
    else goto v_20623;
v_20622:
    v_20783 = lisp_true;
    goto v_20621;
v_20623:
    v_20783 = stack[-7];
    v_20783 = qcar(v_20783);
    v_20783 = (consp(v_20783) ? nil : lisp_true);
    goto v_20621;
    v_20783 = nil;
v_20621:
    if (v_20783 == nil) goto v_20619;
    v_20783 = stack[-7];
    {
        fn = elt(env, 3); // ofsf_updsigndom
        return (*qfn1(fn))(fn, v_20783);
    }
v_20619:
    goto v_20648;
v_20634:
    v_20783 = stack[-7];
    v_20783 = qcar(v_20783);
    v_20783 = qcar(v_20783);
    v_20789 = qcar(v_20783);
    goto v_20635;
v_20636:
    v_20788 = stack[-6];
    goto v_20637;
v_20638:
    v_20787 = stack[-5];
    goto v_20639;
v_20640:
    v_20786 = stack[-4];
    goto v_20641;
v_20642:
    v_20785 = stack[-3];
    goto v_20643;
v_20644:
    v_20784 = stack[-2];
    goto v_20645;
v_20646:
    v_20783 = stack[-1];
    goto v_20647;
v_20648:
    goto v_20634;
v_20635:
    goto v_20636;
v_20637:
    goto v_20638;
v_20639:
    goto v_20640;
v_20641:
    goto v_20642;
v_20643:
    goto v_20644;
v_20645:
    goto v_20646;
v_20647:
    fn = elt(env, 4); // ofsf_updsignvar
    v_20783 = (*qfnn(fn))(fn, 7, v_20789, v_20788, v_20787, v_20786, v_20785, v_20784, v_20783);
    env = stack[-9];
    stack[0] = v_20783;
    goto v_20667;
v_20663:
    v_20784 = stack[0];
    goto v_20664;
v_20665:
    v_20783 = elt(env, 2); // unknown
    goto v_20666;
v_20667:
    goto v_20663;
v_20664:
    goto v_20665;
v_20666:
    if (v_20784 == v_20783) goto v_20661;
    else goto v_20662;
v_20661:
    v_20783 = elt(env, 2); // unknown
    goto v_20614;
v_20662:
    goto v_20686;
v_20672:
    v_20783 = stack[-7];
    v_20783 = qcar(v_20783);
    v_20789 = qcdr(v_20783);
    goto v_20673;
v_20674:
    v_20788 = stack[-6];
    goto v_20675;
v_20676:
    v_20787 = stack[-5];
    goto v_20677;
v_20678:
    v_20786 = stack[-4];
    goto v_20679;
v_20680:
    v_20785 = stack[-3];
    goto v_20681;
v_20682:
    v_20784 = stack[-2];
    goto v_20683;
v_20684:
    v_20783 = stack[-1];
    goto v_20685;
v_20686:
    goto v_20672;
v_20673:
    goto v_20674;
v_20675:
    goto v_20676;
v_20677:
    goto v_20678;
v_20679:
    goto v_20680;
v_20681:
    goto v_20682;
v_20683:
    goto v_20684;
v_20685:
    v_20783 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20789, v_20788, v_20787, v_20786, v_20785, v_20784, v_20783);
    env = stack[-9];
    stack[-8] = v_20783;
    goto v_20704;
v_20700:
    v_20784 = stack[-8];
    goto v_20701;
v_20702:
    v_20783 = elt(env, 2); // unknown
    goto v_20703;
v_20704:
    goto v_20700;
v_20701:
    goto v_20702;
v_20703:
    if (v_20784 == v_20783) goto v_20698;
    else goto v_20699;
v_20698:
    v_20783 = elt(env, 2); // unknown
    goto v_20614;
v_20699:
    goto v_20723;
v_20709:
    v_20783 = stack[-7];
    v_20789 = qcdr(v_20783);
    goto v_20710;
v_20711:
    v_20788 = stack[-6];
    goto v_20712;
v_20713:
    v_20787 = stack[-5];
    goto v_20714;
v_20715:
    v_20786 = stack[-4];
    goto v_20716;
v_20717:
    v_20785 = stack[-3];
    goto v_20718;
v_20719:
    v_20784 = stack[-2];
    goto v_20720;
v_20721:
    v_20783 = stack[-1];
    goto v_20722;
v_20723:
    goto v_20709;
v_20710:
    goto v_20711;
v_20712:
    goto v_20713;
v_20714:
    goto v_20715;
v_20716:
    goto v_20717;
v_20718:
    goto v_20719;
v_20720:
    goto v_20721;
v_20722:
    v_20783 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20789, v_20788, v_20787, v_20786, v_20785, v_20784, v_20783);
    env = stack[-9];
    stack[-1] = v_20783;
    goto v_20740;
v_20736:
    v_20784 = stack[-1];
    goto v_20737;
v_20738:
    v_20783 = elt(env, 2); // unknown
    goto v_20739;
v_20740:
    goto v_20736;
v_20737:
    goto v_20738;
v_20739:
    if (v_20784 == v_20783) goto v_20734;
    else goto v_20735;
v_20734:
    v_20783 = elt(env, 2); // unknown
    goto v_20614;
v_20735:
    goto v_20749;
v_20745:
    v_20784 = stack[0];
    goto v_20746;
v_20747:
    v_20783 = stack[-7];
    v_20783 = qcar(v_20783);
    v_20783 = qcar(v_20783);
    v_20783 = qcdr(v_20783);
    goto v_20748;
v_20749:
    goto v_20745;
v_20746:
    goto v_20747;
v_20748:
    fn = elt(env, 5); // ofsf_updsignpow
    v_20783 = (*qfn2(fn))(fn, v_20784, v_20783);
    env = stack[-9];
    stack[0] = v_20783;
    goto v_20760;
v_20756:
    v_20784 = stack[-8];
    goto v_20757;
v_20758:
    v_20783 = stack[0];
    goto v_20759;
v_20760:
    goto v_20756;
v_20757:
    goto v_20758;
v_20759:
    fn = elt(env, 6); // ofsf_updsignmult
    v_20783 = (*qfn2(fn))(fn, v_20784, v_20783);
    env = stack[-9];
    v_20785 = v_20783;
    goto v_20771;
v_20767:
    v_20784 = v_20785;
    goto v_20768;
v_20769:
    v_20783 = elt(env, 2); // unknown
    goto v_20770;
v_20771:
    goto v_20767;
v_20768:
    goto v_20769;
v_20770:
    if (v_20784 == v_20783) goto v_20765;
    else goto v_20766;
v_20765:
    v_20783 = elt(env, 2); // unknown
    goto v_20614;
v_20766:
    goto v_20780;
v_20776:
    v_20784 = v_20785;
    goto v_20777;
v_20778:
    v_20783 = stack[-1];
    goto v_20779;
v_20780:
    goto v_20776;
v_20777:
    goto v_20778;
v_20779:
    {
        fn = elt(env, 7); // ofsf_updsignadd
        return (*qfn2(fn))(fn, v_20784, v_20783);
    }
v_20614:
    return onevalue(v_20783);
}



// Code for vectorml

static LispObject CC_vectorml(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20626, v_20627;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20601;
// end of prologue
    v_20626 = elt(env, 1); // "<vector"
    fn = elt(env, 4); // printout
    v_20626 = (*qfn1(fn))(fn, v_20626);
    env = stack[-1];
    goto v_20613;
v_20609:
    v_20626 = stack[0];
    v_20627 = qcar(v_20626);
    goto v_20610;
v_20611:
    v_20626 = elt(env, 2); // ""
    goto v_20612;
v_20613:
    goto v_20609;
v_20610:
    goto v_20611;
v_20612:
    fn = elt(env, 5); // attributesml
    v_20626 = (*qfn2(fn))(fn, v_20627, v_20626);
    env = stack[-1];
    v_20626 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_20626 = (*qfn1(fn))(fn, v_20626);
    env = stack[-1];
    v_20626 = stack[0];
    v_20626 = qcdr(v_20626);
    fn = elt(env, 7); // multi_elem
    v_20626 = (*qfn1(fn))(fn, v_20626);
    env = stack[-1];
    v_20626 = nil;
    fn = elt(env, 6); // indent!*
    v_20626 = (*qfn1(fn))(fn, v_20626);
    env = stack[-1];
    v_20626 = elt(env, 3); // "</vector>"
    fn = elt(env, 4); // printout
    v_20626 = (*qfn1(fn))(fn, v_20626);
    v_20626 = nil;
    return onevalue(v_20626);
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20643, v_20644, v_20645;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20602;
    stack[-1] = v_20601;
// end of prologue
    v_20645 = nil;
v_20607:
    goto v_20616;
v_20612:
    v_20644 = stack[-1];
    goto v_20613;
v_20614:
    v_20643 = stack[0];
    v_20643 = qcar(v_20643);
    v_20643 = qcar(v_20643);
    goto v_20615;
v_20616:
    goto v_20612;
v_20613:
    goto v_20614;
v_20615:
    if (equal(v_20644, v_20643)) goto v_20610;
    else goto v_20611;
v_20610:
    goto v_20626;
v_20622:
    v_20644 = v_20645;
    goto v_20623;
v_20624:
    v_20643 = stack[0];
    v_20643 = qcdr(v_20643);
    goto v_20625;
v_20626:
    goto v_20622;
v_20623:
    goto v_20624;
v_20625:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_20644, v_20643);
    }
v_20611:
    goto v_20637;
v_20633:
    v_20643 = stack[0];
    v_20643 = qcar(v_20643);
    goto v_20634;
v_20635:
    v_20644 = v_20645;
    goto v_20636;
v_20637:
    goto v_20633;
v_20634:
    goto v_20635;
v_20636:
    v_20643 = cons(v_20643, v_20644);
    env = stack[-2];
    v_20645 = v_20643;
    v_20643 = stack[0];
    v_20643 = qcdr(v_20643);
    stack[0] = v_20643;
    goto v_20607;
    v_20643 = nil;
    return onevalue(v_20643);
}



// Code for evinvlexcomp

static LispObject CC_evinvlexcomp(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20689, v_20690;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20602;
    stack[-1] = v_20601;
// end of prologue
v_20606:
    v_20689 = stack[-1];
    if (v_20689 == nil) goto v_20609;
    else goto v_20610;
v_20609:
    v_20689 = stack[0];
    if (v_20689 == nil) goto v_20614;
    else goto v_20615;
v_20614:
    v_20689 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20605;
v_20615:
    v_20689 = elt(env, 1); // (0)
    stack[-1] = v_20689;
    goto v_20606;
    goto v_20608;
v_20610:
    v_20689 = stack[0];
    if (v_20689 == nil) goto v_20621;
    else goto v_20622;
v_20621:
    goto v_20629;
v_20625:
    v_20690 = stack[-1];
    goto v_20626;
v_20627:
    v_20689 = elt(env, 1); // (0)
    goto v_20628;
v_20629:
    goto v_20625;
v_20626:
    goto v_20627;
v_20628:
    {
        fn = elt(env, 2); // evlexcomp
        return (*qfn2(fn))(fn, v_20690, v_20689);
    }
v_20622:
    goto v_20639;
v_20635:
    v_20689 = stack[-1];
    v_20690 = qcar(v_20689);
    goto v_20636;
v_20637:
    v_20689 = stack[0];
    v_20689 = qcar(v_20689);
    goto v_20638;
v_20639:
    goto v_20635;
v_20636:
    goto v_20637;
v_20638:
    fn = elt(env, 3); // iequal
    v_20689 = (*qfn2(fn))(fn, v_20690, v_20689);
    env = stack[-3];
    if (v_20689 == nil) goto v_20633;
    v_20689 = stack[-1];
    v_20689 = qcdr(v_20689);
    stack[-1] = v_20689;
    v_20689 = stack[0];
    v_20689 = qcdr(v_20689);
    stack[0] = v_20689;
    goto v_20606;
v_20633:
    goto v_20655;
v_20651:
    v_20689 = stack[-1];
    v_20690 = qcdr(v_20689);
    goto v_20652;
v_20653:
    v_20689 = stack[0];
    v_20689 = qcdr(v_20689);
    goto v_20654;
v_20655:
    goto v_20651;
v_20652:
    goto v_20653;
v_20654:
    v_20689 = CC_evinvlexcomp(elt(env, 0), v_20690, v_20689);
    env = stack[-3];
    stack[-2] = v_20689;
    goto v_20670;
v_20666:
    v_20690 = stack[-2];
    goto v_20667;
v_20668:
    v_20689 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20669;
v_20670:
    goto v_20666;
v_20667:
    goto v_20668;
v_20669:
    fn = elt(env, 3); // iequal
    v_20689 = (*qfn2(fn))(fn, v_20690, v_20689);
    if (v_20689 == nil) goto v_20663;
    else goto v_20664;
v_20663:
    v_20689 = stack[-2];
    goto v_20662;
v_20664:
    goto v_20680;
v_20676:
    v_20689 = stack[0];
    v_20690 = qcar(v_20689);
    goto v_20677;
v_20678:
    v_20689 = stack[-1];
    v_20689 = qcar(v_20689);
    goto v_20679;
v_20680:
    goto v_20676;
v_20677:
    goto v_20678;
v_20679:
    if (((intptr_t)(v_20690)) > ((intptr_t)(v_20689))) goto v_20674;
    else goto v_20675;
v_20674:
    v_20689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20662;
v_20675:
    v_20689 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20662;
    v_20689 = nil;
v_20662:
    goto v_20605;
v_20608:
    v_20689 = nil;
v_20605:
    return onevalue(v_20689);
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20685, v_20686, v_20687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_20601;
// end of prologue
    v_20687 = nil;
v_20606:
    v_20685 = stack[-1];
    if (!consp(v_20685)) goto v_20609;
    else goto v_20610;
v_20609:
    goto v_20617;
v_20613:
    v_20686 = v_20687;
    goto v_20614;
v_20615:
    v_20685 = stack[-1];
    goto v_20616;
v_20617:
    goto v_20613;
v_20614:
    goto v_20615;
v_20616:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20686, v_20685);
    }
v_20610:
    goto v_20626;
v_20622:
    v_20685 = stack[-1];
    v_20686 = qcar(v_20685);
    goto v_20623;
v_20624:
    v_20685 = elt(env, 1); // plus
    goto v_20625;
v_20626:
    goto v_20622;
v_20623:
    goto v_20624;
v_20625:
    if (v_20686 == v_20685) goto v_20620;
    else goto v_20621;
v_20620:
    v_20685 = stack[-1];
    v_20685 = qcdr(v_20685);
    stack[-1] = v_20685;
    goto v_20606;
v_20621:
    v_20685 = stack[-1];
    v_20685 = qcar(v_20685);
    if (!consp(v_20685)) goto v_20636;
    else goto v_20637;
v_20636:
    v_20685 = lisp_true;
    goto v_20635;
v_20637:
    goto v_20648;
v_20644:
    v_20685 = stack[-1];
    v_20686 = qcar(v_20685);
    goto v_20645;
v_20646:
    v_20685 = elt(env, 1); // plus
    goto v_20647;
v_20648:
    goto v_20644;
v_20645:
    goto v_20646;
v_20647:
    v_20685 = Leqcar(nil, v_20686, v_20685);
    env = stack[-3];
    v_20685 = (v_20685 == nil ? lisp_true : nil);
    goto v_20635;
    v_20685 = nil;
v_20635:
    if (v_20685 == nil) goto v_20633;
    goto v_20658;
v_20654:
    v_20685 = stack[-1];
    v_20685 = qcar(v_20685);
    goto v_20655;
v_20656:
    v_20686 = v_20687;
    goto v_20657;
v_20658:
    goto v_20654;
v_20655:
    goto v_20656;
v_20657:
    v_20685 = cons(v_20685, v_20686);
    env = stack[-3];
    v_20687 = v_20685;
    v_20685 = stack[-1];
    v_20685 = qcdr(v_20685);
    stack[-1] = v_20685;
    goto v_20606;
v_20633:
    goto v_20671;
v_20667:
    stack[-2] = v_20687;
    goto v_20668;
v_20669:
    goto v_20678;
v_20674:
    v_20685 = stack[-1];
    v_20685 = qcar(v_20685);
    stack[0] = qcdr(v_20685);
    goto v_20675;
v_20676:
    v_20685 = stack[-1];
    v_20685 = qcdr(v_20685);
    v_20685 = CC_unplus(elt(env, 0), v_20685);
    env = stack[-3];
    goto v_20677;
v_20678:
    goto v_20674;
v_20675:
    goto v_20676;
v_20677:
    v_20685 = Lappend(nil, stack[0], v_20685);
    env = stack[-3];
    goto v_20670;
v_20671:
    goto v_20667;
v_20668:
    goto v_20669;
v_20670:
    {
        LispObject v_20691 = stack[-2];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20691, v_20685);
    }
    v_20685 = nil;
    return onevalue(v_20685);
}



// Code for indordl2

static LispObject CC_indordl2(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20634, v_20635;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20602;
    stack[-1] = v_20601;
// end of prologue
    goto v_20613;
v_20609:
    v_20635 = stack[-1];
    goto v_20610;
v_20611:
    v_20634 = stack[0];
    goto v_20612;
v_20613:
    goto v_20609;
v_20610:
    goto v_20611;
v_20612:
    fn = elt(env, 1); // indordlp
    v_20634 = (*qfn2(fn))(fn, v_20635, v_20634);
    if (v_20634 == nil) goto v_20607;
    goto v_20621;
v_20617:
    v_20635 = stack[-1];
    goto v_20618;
v_20619:
    v_20634 = stack[0];
    goto v_20620;
v_20621:
    goto v_20617;
v_20618:
    goto v_20619;
v_20620:
    return list2(v_20635, v_20634);
v_20607:
    goto v_20631;
v_20627:
    v_20635 = stack[0];
    goto v_20628;
v_20629:
    v_20634 = stack[-1];
    goto v_20630;
v_20631:
    goto v_20627;
v_20628:
    goto v_20629;
v_20630:
    return list2(v_20635, v_20634);
    v_20634 = nil;
    return onevalue(v_20634);
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20654, v_20655, v_20656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20602;
    stack[-1] = v_20601;
// end of prologue
    v_20654 = stack[-1];
    if (v_20654 == nil) goto v_20606;
    else goto v_20607;
v_20606:
    v_20654 = (LispObject)16+TAG_FIXNUM; // 1
    return ncons(v_20654);
v_20607:
    goto v_20618;
v_20614:
    v_20654 = stack[-1];
    v_20655 = qcar(v_20654);
    goto v_20615;
v_20616:
    v_20654 = stack[0];
    goto v_20617;
v_20618:
    goto v_20614;
v_20615:
    goto v_20616;
v_20617:
    fn = elt(env, 1); // calc_world
    v_20654 = (*qfn2(fn))(fn, v_20655, v_20654);
    env = stack[-3];
    v_20656 = v_20654;
    goto v_20631;
v_20627:
    v_20655 = v_20656;
    goto v_20628;
v_20629:
    v_20654 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20630;
v_20631:
    goto v_20627;
v_20628:
    goto v_20629;
v_20630:
    if (v_20655 == v_20654) goto v_20625;
    else goto v_20626;
v_20625:
    v_20654 = (LispObject)0+TAG_FIXNUM; // 0
    return ncons(v_20654);
v_20626:
    goto v_20643;
v_20639:
    stack[-2] = v_20656;
    goto v_20640;
v_20641:
    goto v_20650;
v_20646:
    v_20654 = stack[-1];
    v_20655 = qcdr(v_20654);
    goto v_20647;
v_20648:
    v_20654 = stack[0];
    goto v_20649;
v_20650:
    goto v_20646;
v_20647:
    goto v_20648;
v_20649:
    v_20654 = CC_calc_coeff(elt(env, 0), v_20655, v_20654);
    goto v_20642;
v_20643:
    goto v_20639;
v_20640:
    goto v_20641;
v_20642:
    {
        LispObject v_20660 = stack[-2];
        return cons(v_20660, v_20654);
    }
    v_20654 = nil;
    goto v_20605;
    v_20654 = nil;
v_20605:
    return onevalue(v_20654);
}



// Code for listsub

static LispObject CC_listsub(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20660, v_20661;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20660 = v_20602;
    stack[-3] = v_20601;
// end of prologue
    v_20660 = qcdr(v_20660);
    stack[-4] = v_20660;
    v_20660 = stack[-4];
    if (v_20660 == nil) goto v_20615;
    else goto v_20616;
v_20615:
    v_20660 = nil;
    goto v_20609;
v_20616:
    v_20660 = stack[-4];
    v_20660 = qcar(v_20660);
    goto v_20628;
v_20624:
    v_20661 = stack[-3];
    goto v_20625;
v_20626:
    goto v_20627;
v_20628:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    fn = elt(env, 1); // subeval1
    v_20660 = (*qfn2(fn))(fn, v_20661, v_20660);
    env = stack[-5];
    v_20660 = ncons(v_20660);
    env = stack[-5];
    stack[-1] = v_20660;
    stack[-2] = v_20660;
v_20610:
    v_20660 = stack[-4];
    v_20660 = qcdr(v_20660);
    stack[-4] = v_20660;
    v_20660 = stack[-4];
    if (v_20660 == nil) goto v_20635;
    else goto v_20636;
v_20635:
    v_20660 = stack[-2];
    goto v_20609;
v_20636:
    goto v_20644;
v_20640:
    stack[0] = stack[-1];
    goto v_20641;
v_20642:
    v_20660 = stack[-4];
    v_20660 = qcar(v_20660);
    goto v_20655;
v_20651:
    v_20661 = stack[-3];
    goto v_20652;
v_20653:
    goto v_20654;
v_20655:
    goto v_20651;
v_20652:
    goto v_20653;
v_20654:
    fn = elt(env, 1); // subeval1
    v_20660 = (*qfn2(fn))(fn, v_20661, v_20660);
    env = stack[-5];
    v_20660 = ncons(v_20660);
    env = stack[-5];
    goto v_20643;
v_20644:
    goto v_20640;
v_20641:
    goto v_20642;
v_20643:
    v_20660 = Lrplacd(nil, stack[0], v_20660);
    env = stack[-5];
    v_20660 = stack[-1];
    v_20660 = qcdr(v_20660);
    stack[-1] = v_20660;
    goto v_20610;
v_20609:
    {
        fn = elt(env, 2); // makelist
        return (*qfn1(fn))(fn, v_20660);
    }
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_21019, v_21020, v_21021;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_20601;
// end of prologue
    goto v_20628;
v_20624:
    v_21020 = qvalue(elt(env, 2)); // spare!*
    goto v_20625;
v_20626:
    v_21019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20627;
v_20628:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    v_21019 = plus2(v_21020, v_21019);
    env = stack[-8];
    qvalue(elt(env, 2)) = v_21019; // spare!*
    goto v_20643;
v_20637:
    v_21019 = stack[0];
    v_21019 = qcdr(v_21019);
    v_21021 = qcar(v_21019);
    goto v_20638;
v_20639:
    v_21020 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20640;
v_20641:
    v_21019 = nil;
    goto v_20642;
v_20643:
    goto v_20637;
v_20638:
    goto v_20639;
v_20640:
    goto v_20641;
v_20642:
    fn = elt(env, 14); // layout!-formula
    v_21019 = (*qfnn(fn))(fn, 3, v_21021, v_21020, v_21019);
    env = stack[-8];
    stack[-7] = v_21019;
    if (v_21019 == nil) goto v_20634;
    goto v_20657;
v_20651:
    v_21019 = stack[0];
    v_21019 = qcdr(v_21019);
    v_21019 = qcdr(v_21019);
    v_21021 = qcar(v_21019);
    goto v_20652;
v_20653:
    v_21020 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20654;
v_20655:
    v_21019 = nil;
    goto v_20656;
v_20657:
    goto v_20651;
v_20652:
    goto v_20653;
v_20654:
    goto v_20655;
v_20656:
    fn = elt(env, 14); // layout!-formula
    v_21019 = (*qfnn(fn))(fn, 3, v_21021, v_21020, v_21019);
    env = stack[-8];
    stack[-6] = v_21019;
    if (v_21019 == nil) goto v_20634;
    goto v_20669;
v_20665:
    v_21020 = qvalue(elt(env, 2)); // spare!*
    goto v_20666;
v_20667:
    v_21019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20668;
v_20669:
    goto v_20665;
v_20666:
    goto v_20667;
v_20668:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    qvalue(elt(env, 2)) = v_21019; // spare!*
    goto v_20677;
v_20673:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20674;
v_20675:
    goto v_20684;
v_20680:
    v_21019 = stack[-7];
    v_21019 = qcar(v_21019);
    v_21020 = qcdr(v_21019);
    goto v_20681;
v_20682:
    v_21019 = stack[-6];
    v_21019 = qcar(v_21019);
    v_21019 = qcdr(v_21019);
    goto v_20683;
v_20684:
    goto v_20680;
v_20681:
    goto v_20682;
v_20683:
    fn = elt(env, 15); // max
    v_21019 = (*qfn2(fn))(fn, v_21020, v_21019);
    env = stack[-8];
    goto v_20676;
v_20677:
    goto v_20673;
v_20674:
    goto v_20675;
v_20676:
    v_21019 = plus2(stack[0], v_21019);
    env = stack[-8];
    stack[-2] = v_21019;
    goto v_20700;
v_20696:
    stack[0] = stack[-2];
    goto v_20697;
v_20698:
    goto v_20707;
v_20703:
    goto v_20713;
v_20709:
    v_21019 = nil;
    v_21020 = Llinelength(nil, v_21019);
    env = stack[-8];
    goto v_20710;
v_20711:
    v_21019 = qvalue(elt(env, 2)); // spare!*
    goto v_20712;
v_20713:
    goto v_20709;
v_20710:
    goto v_20711;
v_20712:
    v_21020 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20704;
v_20705:
    v_21019 = qvalue(elt(env, 3)); // posn!*
    goto v_20706;
v_20707:
    goto v_20703;
v_20704:
    goto v_20705;
v_20706:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20699;
v_20700:
    goto v_20696;
v_20697:
    goto v_20698;
v_20699:
    v_21019 = (LispObject)greaterp2(stack[0], v_21019);
    v_21019 = v_21019 ? lisp_true : nil;
    env = stack[-8];
    if (v_21019 == nil) goto v_20694;
    v_21019 = lisp_true;
    fn = elt(env, 16); // terpri!*
    v_21019 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    goto v_20692;
v_20694:
v_20692:
    goto v_20725;
v_20721:
    v_21019 = stack[-7];
    v_21019 = qcar(v_21019);
    v_21020 = qcdr(v_21019);
    goto v_20722;
v_20723:
    v_21019 = stack[-6];
    v_21019 = qcar(v_21019);
    v_21019 = qcdr(v_21019);
    goto v_20724;
v_20725:
    goto v_20721;
v_20722:
    goto v_20723;
v_20724:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    stack[-1] = v_21019;
    goto v_20741;
v_20737:
    v_21020 = stack[-1];
    goto v_20738;
v_20739:
    v_21019 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20740;
v_20741:
    goto v_20737;
v_20738:
    goto v_20739;
v_20740:
    v_21019 = (LispObject)greaterp2(v_21020, v_21019);
    v_21019 = v_21019 ? lisp_true : nil;
    env = stack[-8];
    if (v_21019 == nil) goto v_20735;
    v_21019 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21019;
    goto v_20750;
v_20746:
    v_21020 = stack[-1];
    goto v_20747;
v_20748:
    v_21019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20749;
v_20750:
    goto v_20746;
v_20747:
    goto v_20748;
v_20749:
    v_21019 = quot2(v_21020, v_21019);
    env = stack[-8];
    stack[-3] = v_21019;
    goto v_20733;
v_20735:
    goto v_20760;
v_20756:
    v_21019 = stack[-1];
    v_21020 = negate(v_21019);
    env = stack[-8];
    goto v_20757;
v_20758:
    v_21019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20759;
v_20760:
    goto v_20756;
v_20757:
    goto v_20758;
v_20759:
    v_21019 = quot2(v_21020, v_21019);
    env = stack[-8];
    stack[0] = v_21019;
    v_21019 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_21019;
    goto v_20733;
v_20733:
    goto v_20771;
v_20767:
    v_21019 = stack[-7];
    v_21019 = qcdr(v_21019);
    v_21020 = qcdr(v_21019);
    goto v_20768;
v_20769:
    v_21019 = stack[-7];
    v_21019 = qcdr(v_21019);
    v_21019 = qcar(v_21019);
    goto v_20770;
v_20771:
    goto v_20767;
v_20768:
    goto v_20769;
v_20770:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    v_21019 = add1(v_21019);
    env = stack[-8];
    stack[-5] = v_21019;
    goto v_20784;
v_20780:
    v_21019 = stack[-6];
    v_21019 = qcdr(v_21019);
    v_21020 = qcdr(v_21019);
    goto v_20781;
v_20782:
    v_21019 = stack[-6];
    v_21019 = qcdr(v_21019);
    v_21019 = qcar(v_21019);
    goto v_20783;
v_20784:
    goto v_20780;
v_20781:
    goto v_20782;
v_20783:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    v_21019 = add1(v_21019);
    env = stack[-8];
    stack[-4] = v_21019;
    goto v_20796;
v_20792:
    goto v_20804;
v_20798:
    goto v_20810;
v_20806:
    stack[-1] = stack[0];
    goto v_20807;
v_20808:
    goto v_20817;
v_20813:
    stack[0] = qvalue(elt(env, 3)); // posn!*
    goto v_20814;
v_20815:
    goto v_20824;
v_20820:
    v_21020 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20821;
v_20822:
    v_21019 = qvalue(elt(env, 4)); // orig!*
    goto v_20823;
v_20824:
    goto v_20820;
v_20821:
    goto v_20822;
v_20823:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20816;
v_20817:
    goto v_20813;
v_20814:
    goto v_20815;
v_20816:
    v_21019 = plus2(stack[0], v_21019);
    env = stack[-8];
    goto v_20809;
v_20810:
    goto v_20806;
v_20807:
    goto v_20808;
v_20809:
    stack[0] = plus2(stack[-1], v_21019);
    env = stack[-8];
    goto v_20799;
v_20800:
    goto v_20832;
v_20828:
    goto v_20838;
v_20834:
    v_21020 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20835;
v_20836:
    v_21019 = stack[-7];
    v_21019 = qcdr(v_21019);
    v_21019 = qcar(v_21019);
    goto v_20837;
v_20838:
    goto v_20834;
v_20835:
    goto v_20836;
v_20837:
    v_21020 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20829;
v_20830:
    v_21019 = qvalue(elt(env, 5)); // ycoord!*
    goto v_20831;
v_20832:
    goto v_20828;
v_20829:
    goto v_20830;
v_20831:
    v_21020 = plus2(v_21020, v_21019);
    env = stack[-8];
    goto v_20801;
v_20802:
    v_21019 = stack[-7];
    v_21019 = qcar(v_21019);
    v_21019 = qcar(v_21019);
    goto v_20803;
v_20804:
    goto v_20798;
v_20799:
    goto v_20800;
v_20801:
    goto v_20802;
v_20803:
    fn = elt(env, 17); // update!-pline
    stack[-1] = (*qfnn(fn))(fn, 3, stack[0], v_21020, v_21019);
    env = stack[-8];
    goto v_20793;
v_20794:
    goto v_20852;
v_20848:
    goto v_20860;
v_20854:
    goto v_20866;
v_20862:
    goto v_20863;
v_20864:
    goto v_20873;
v_20869:
    stack[0] = qvalue(elt(env, 3)); // posn!*
    goto v_20870;
v_20871:
    goto v_20880;
v_20876:
    v_21020 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20877;
v_20878:
    v_21019 = qvalue(elt(env, 4)); // orig!*
    goto v_20879;
v_20880:
    goto v_20876;
v_20877:
    goto v_20878;
v_20879:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20872;
v_20873:
    goto v_20869;
v_20870:
    goto v_20871;
v_20872:
    v_21019 = plus2(stack[0], v_21019);
    env = stack[-8];
    goto v_20865;
v_20866:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    stack[0] = plus2(stack[-3], v_21019);
    env = stack[-8];
    goto v_20855;
v_20856:
    goto v_20889;
v_20885:
    v_21020 = qvalue(elt(env, 5)); // ycoord!*
    goto v_20886;
v_20887:
    v_21019 = stack[-6];
    v_21019 = qcdr(v_21019);
    v_21019 = qcdr(v_21019);
    goto v_20888;
v_20889:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    v_21020 = sub1(v_21019);
    env = stack[-8];
    goto v_20857;
v_20858:
    v_21019 = stack[-6];
    v_21019 = qcar(v_21019);
    v_21019 = qcar(v_21019);
    goto v_20859;
v_20860:
    goto v_20854;
v_20855:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    fn = elt(env, 17); // update!-pline
    v_21020 = (*qfnn(fn))(fn, 3, stack[0], v_21020, v_21019);
    env = stack[-8];
    goto v_20849;
v_20850:
    v_21019 = qvalue(elt(env, 6)); // pline!*
    goto v_20851;
v_20852:
    goto v_20848;
v_20849:
    goto v_20850;
v_20851:
    v_21019 = Lappend(nil, v_21020, v_21019);
    env = stack[-8];
    goto v_20795;
v_20796:
    goto v_20792;
v_20793:
    goto v_20794;
v_20795:
    v_21019 = Lappend(nil, stack[-1], v_21019);
    env = stack[-8];
    qvalue(elt(env, 6)) = v_21019; // pline!*
    goto v_20903;
v_20899:
    stack[0] = qvalue(elt(env, 7)); // ymin!*
    goto v_20900;
v_20901:
    goto v_20910;
v_20906:
    v_21020 = qvalue(elt(env, 5)); // ycoord!*
    goto v_20907;
v_20908:
    v_21019 = stack[-4];
    goto v_20909;
v_20910:
    goto v_20906;
v_20907:
    goto v_20908;
v_20909:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    goto v_20902;
v_20903:
    goto v_20899;
v_20900:
    goto v_20901;
v_20902:
    fn = elt(env, 18); // min
    v_21019 = (*qfn2(fn))(fn, stack[0], v_21019);
    env = stack[-8];
    qvalue(elt(env, 7)) = v_21019; // ymin!*
    goto v_20918;
v_20914:
    stack[0] = qvalue(elt(env, 8)); // ymax!*
    goto v_20915;
v_20916:
    goto v_20925;
v_20921:
    v_21020 = qvalue(elt(env, 5)); // ycoord!*
    goto v_20922;
v_20923:
    v_21019 = stack[-5];
    goto v_20924;
v_20925:
    goto v_20921;
v_20922:
    goto v_20923;
v_20924:
    v_21019 = plus2(v_21020, v_21019);
    env = stack[-8];
    goto v_20917;
v_20918:
    goto v_20914;
v_20915:
    goto v_20916;
v_20917:
    fn = elt(env, 15); // max
    v_21019 = (*qfn2(fn))(fn, stack[0], v_21019);
    env = stack[-8];
    qvalue(elt(env, 8)) = v_21019; // ymax!*
    v_21019 = elt(env, 9); // bar
    fn = elt(env, 19); // symbol
    v_21019 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    stack[-1] = v_21019;
    v_21019 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_21019;
v_20933:
    goto v_20945;
v_20941:
    v_21020 = stack[-2];
    goto v_20942;
v_20943:
    v_21019 = stack[0];
    goto v_20944;
v_20945:
    goto v_20941;
v_20942:
    goto v_20943;
v_20944:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    v_21019 = Lminusp(nil, v_21019);
    env = stack[-8];
    if (v_21019 == nil) goto v_20938;
    goto v_20932;
v_20938:
    v_21019 = stack[-1];
    fn = elt(env, 20); // prin2!*
    v_21019 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    v_21019 = stack[0];
    v_21019 = add1(v_21019);
    env = stack[-8];
    stack[0] = v_21019;
    goto v_20933;
v_20932:
    goto v_20632;
v_20634:
    goto v_20960;
v_20956:
    v_21020 = qvalue(elt(env, 2)); // spare!*
    goto v_20957;
v_20958:
    v_21019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20959;
v_20960:
    goto v_20956;
v_20957:
    goto v_20958;
v_20959:
    v_21019 = difference2(v_21020, v_21019);
    env = stack[-8];
    qvalue(elt(env, 2)) = v_21019; // spare!*
    v_21019 = stack[0];
    v_21019 = qcdr(v_21019);
    stack[0] = v_21019;
    v_21019 = elt(env, 10); // quotient
    if (!symbolp(v_21019)) v_21019 = nil;
    else { v_21019 = qfastgets(v_21019);
           if (v_21019 != nil) { v_21019 = elt(v_21019, 23); // infix
#ifdef RECORD_GET
             if (v_21019 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_21019 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_21019 == SPID_NOPROP) v_21019 = nil; }}
#endif
    stack[-2] = v_21019;
    v_21019 = qvalue(elt(env, 11)); // p!*!*
    if (v_21019 == nil) goto v_20970;
    goto v_20977;
v_20973:
    v_21020 = qvalue(elt(env, 11)); // p!*!*
    goto v_20974;
v_20975:
    v_21019 = stack[-2];
    goto v_20976;
v_20977:
    goto v_20973;
v_20974:
    goto v_20975;
v_20976:
    v_21019 = (LispObject)greaterp2(v_21020, v_21019);
    v_21019 = v_21019 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v_21019;
    goto v_20968;
v_20970:
    v_21019 = nil;
    stack[-1] = v_21019;
    goto v_20968;
v_20968:
    v_21019 = stack[-1];
    if (v_21019 == nil) goto v_20986;
    v_21019 = elt(env, 12); // "("
    fn = elt(env, 20); // prin2!*
    v_21019 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    goto v_20984;
v_20986:
v_20984:
    goto v_20995;
v_20991:
    v_21019 = stack[0];
    v_21020 = qcar(v_21019);
    goto v_20992;
v_20993:
    v_21019 = stack[-2];
    goto v_20994;
v_20995:
    goto v_20991;
v_20992:
    goto v_20993;
v_20994:
    fn = elt(env, 21); // maprint
    v_21019 = (*qfn2(fn))(fn, v_21020, v_21019);
    env = stack[-8];
    v_21019 = elt(env, 10); // quotient
    fn = elt(env, 22); // oprin
    v_21019 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    goto v_21006;
v_21002:
    v_21019 = stack[0];
    v_21019 = qcdr(v_21019);
    v_21019 = qcar(v_21019);
    fn = elt(env, 23); // negnumberchk
    v_21020 = (*qfn1(fn))(fn, v_21019);
    env = stack[-8];
    goto v_21003;
v_21004:
    v_21019 = stack[-2];
    goto v_21005;
v_21006:
    goto v_21002;
v_21003:
    goto v_21004;
v_21005:
    fn = elt(env, 21); // maprint
    v_21019 = (*qfn2(fn))(fn, v_21020, v_21019);
    env = stack[-8];
    v_21019 = stack[-1];
    if (v_21019 == nil) goto v_21015;
    v_21019 = elt(env, 13); // ")"
    fn = elt(env, 20); // prin2!*
    v_21019 = (*qfn1(fn))(fn, v_21019);
    goto v_21013;
v_21015:
v_21013:
    goto v_20632;
v_20632:
    v_21019 = nil;
    return onevalue(v_21019);
}



// Code for red_tailreddriver

static LispObject CC_red_tailreddriver(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20660;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_20603;
    stack[-2] = v_20602;
    stack[-3] = v_20601;
// end of prologue
    v_20660 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20660 = (*qfn1(fn))(fn, v_20660);
    env = stack[-5];
    if (v_20660 == nil) goto v_20611;
    else goto v_20612;
v_20611:
    v_20660 = lisp_true;
    goto v_20610;
v_20612:
    v_20660 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20660 = (*qfn1(fn))(fn, v_20660);
    env = stack[-5];
    v_20660 = qcdr(v_20660);
    if (v_20660 == nil) goto v_20620;
    else goto v_20621;
v_20620:
    v_20660 = lisp_true;
    goto v_20619;
v_20621:
    v_20660 = stack[-3];
    v_20660 = (v_20660 == nil ? lisp_true : nil);
    goto v_20619;
    v_20660 = nil;
v_20619:
    goto v_20610;
    v_20660 = nil;
v_20610:
    if (v_20660 == nil) goto v_20608;
    v_20660 = stack[-2];
    goto v_20606;
v_20608:
v_20638:
    v_20660 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20660 = (*qfn1(fn))(fn, v_20660);
    env = stack[-5];
    if (v_20660 == nil) goto v_20641;
    else goto v_20642;
v_20641:
    goto v_20637;
v_20642:
    goto v_20653;
v_20647:
    stack[-4] = stack[-1];
    goto v_20648;
v_20649:
    stack[0] = stack[-3];
    goto v_20650;
v_20651:
    v_20660 = stack[-2];
    fn = elt(env, 2); // red!=hidelt
    v_20660 = (*qfn1(fn))(fn, v_20660);
    env = stack[-5];
    goto v_20652;
v_20653:
    goto v_20647;
v_20648:
    goto v_20649;
v_20650:
    goto v_20651;
v_20652:
    v_20660 = Lapply2(nil, 3, stack[-4], stack[0], v_20660);
    env = stack[-5];
    stack[-2] = v_20660;
    goto v_20638;
v_20637:
    v_20660 = stack[-2];
    {
        fn = elt(env, 3); // red!=recover
        return (*qfn1(fn))(fn, v_20660);
    }
    goto v_20606;
    v_20660 = nil;
v_20606:
    return onevalue(v_20660);
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20657, v_20658, v_20659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20657 = v_20601;
// end of prologue
    v_20658 = qvalue(elt(env, 1)); // !*nat
    if (v_20658 == nil) goto v_20609;
    else goto v_20610;
v_20609:
    v_20658 = lisp_true;
    goto v_20608;
v_20610:
    v_20658 = qvalue(elt(env, 2)); // !*fort
    if (v_20658 == nil) goto v_20617;
    else goto v_20616;
v_20617:
    v_20658 = qvalue(elt(env, 3)); // !*dfprint
    v_20658 = (v_20658 == nil ? lisp_true : nil);
v_20616:
    goto v_20608;
    v_20658 = nil;
v_20608:
    if (v_20658 == nil) goto v_20606;
    v_20657 = elt(env, 4); // failed
    goto v_20604;
v_20606:
    goto v_20635;
v_20629:
    goto v_20641;
v_20637:
    v_20658 = elt(env, 6); // !!df!!
    goto v_20638;
v_20639:
    v_20657 = qcdr(v_20657);
    goto v_20640;
v_20641:
    goto v_20637;
v_20638:
    goto v_20639;
v_20640:
    v_20659 = cons(v_20658, v_20657);
    env = stack[0];
    goto v_20630;
v_20631:
    v_20658 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20632;
v_20633:
    v_20657 = nil;
    goto v_20634;
v_20635:
    goto v_20629;
v_20630:
    goto v_20631;
v_20632:
    goto v_20633;
v_20634:
    fn = elt(env, 7); // layout!-formula
    v_20657 = (*qfnn(fn))(fn, 3, v_20659, v_20658, v_20657);
    env = stack[0];
    v_20658 = v_20657;
    v_20657 = v_20658;
    if (v_20657 == nil) goto v_20649;
    else goto v_20650;
v_20649:
    v_20657 = elt(env, 4); // failed
    goto v_20626;
v_20650:
    v_20657 = v_20658;
    fn = elt(env, 8); // putpline
    v_20657 = (*qfn1(fn))(fn, v_20657);
    goto v_20648;
v_20648:
    v_20657 = nil;
v_20626:
    goto v_20604;
    v_20657 = nil;
v_20604:
    return onevalue(v_20657);
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20622;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20601;
// end of prologue
v_20605:
    v_20622 = stack[0];
    if (v_20622 == nil) goto v_20608;
    else goto v_20609;
v_20608:
    v_20622 = lisp_true;
    goto v_20604;
v_20609:
    v_20622 = stack[0];
    v_20622 = qcar(v_20622);
    fn = elt(env, 1); // nodum_varp
    v_20622 = (*qfn1(fn))(fn, v_20622);
    env = stack[-1];
    if (v_20622 == nil) goto v_20613;
    v_20622 = stack[0];
    v_20622 = qcdr(v_20622);
    stack[0] = v_20622;
    goto v_20605;
v_20613:
    v_20622 = nil;
    goto v_20604;
    v_20622 = nil;
v_20604:
    return onevalue(v_20622);
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20906, v_20907, v_20908;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_20602;
    stack[-5] = v_20601;
// end of prologue
    v_20906 = stack[-5];
    if (!consp(v_20906)) goto v_20617;
    else goto v_20618;
v_20617:
    v_20906 = lisp_true;
    goto v_20616;
v_20618:
    v_20906 = stack[-5];
    v_20906 = qcar(v_20906);
    v_20906 = (consp(v_20906) ? nil : lisp_true);
    goto v_20616;
    v_20906 = nil;
v_20616:
    if (v_20906 == nil) goto v_20614;
    goto v_20612;
v_20614:
    goto v_20633;
v_20629:
    v_20906 = stack[-5];
    v_20906 = qcar(v_20906);
    v_20906 = qcar(v_20906);
    v_20907 = qcdr(v_20906);
    goto v_20630;
v_20631:
    v_20906 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20632;
v_20633:
    goto v_20629;
v_20630:
    goto v_20631;
v_20632:
    if (v_20907 == v_20906) goto v_20627;
    else goto v_20628;
v_20627:
    v_20906 = stack[-5];
    v_20906 = qcar(v_20906);
    v_20906 = qcdr(v_20906);
    fn = elt(env, 5); // safe!-modrecip
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[0] = v_20906;
    v_20906 = nil;
    qvalue(elt(env, 2)) = v_20906; // erfg!*
    v_20906 = stack[0];
    if (v_20906 == nil) goto v_20646;
    else goto v_20647;
v_20646:
    goto v_20608;
v_20647:
    goto v_20655;
v_20651:
    goto v_20652;
v_20653:
    v_20906 = stack[-5];
    v_20906 = qcdr(v_20906);
    fn = elt(env, 6); // negf
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    goto v_20654;
v_20655:
    goto v_20651;
v_20652:
    goto v_20653;
v_20654:
    fn = elt(env, 7); // multf
    v_20906 = (*qfn2(fn))(fn, stack[0], v_20906);
    env = stack[-7];
    fn = elt(env, 8); // moduntag
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[0] = v_20906;
    v_20906 = stack[0];
    if (v_20906 == nil) goto v_20663;
    goto v_20673;
v_20669:
    v_20907 = stack[0];
    goto v_20670;
v_20671:
    v_20906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20672;
v_20673:
    goto v_20669;
v_20670:
    goto v_20671;
v_20672:
    v_20906 = (LispObject)lessp2(v_20907, v_20906);
    v_20906 = v_20906 ? lisp_true : nil;
    env = stack[-7];
    if (v_20906 == nil) goto v_20667;
    else goto v_20666;
v_20667:
    goto v_20682;
v_20678:
    v_20907 = stack[0];
    goto v_20679;
v_20680:
    v_20906 = qvalue(elt(env, 3)); // current!-modulus
    goto v_20681;
v_20682:
    goto v_20678;
v_20679:
    goto v_20680;
v_20681:
    v_20906 = (LispObject)greaterp2(v_20907, v_20906);
    v_20906 = v_20906 ? lisp_true : nil;
    env = stack[-7];
    if (v_20906 == nil) goto v_20676;
    else goto v_20666;
v_20676:
    goto v_20663;
v_20666:
    v_20906 = stack[0];
    fn = elt(env, 9); // general!-modular!-number
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[0] = v_20906;
    goto v_20661;
v_20663:
v_20661:
    v_20906 = stack[0];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    stack[0] = v_20906;
    goto v_20609;
v_20628:
v_20612:
v_20608:
    goto v_20696;
v_20690:
    v_20908 = stack[-5];
    goto v_20691;
v_20692:
    v_20907 = stack[-4];
    goto v_20693;
v_20694:
    v_20906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20695;
v_20696:
    goto v_20690;
v_20691:
    goto v_20692;
v_20693:
    goto v_20694;
v_20695:
    fn = elt(env, 10); // lowestdeg
    v_20906 = (*qfnn(fn))(fn, 3, v_20908, v_20907, v_20906);
    env = stack[-7];
    stack[-6] = v_20906;
    goto v_20709;
v_20705:
    v_20907 = stack[-6];
    goto v_20706;
v_20707:
    v_20906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20708;
v_20709:
    goto v_20705;
v_20706:
    goto v_20707;
v_20708:
    v_20906 = (LispObject)greaterp2(v_20907, v_20906);
    v_20906 = v_20906 ? lisp_true : nil;
    env = stack[-7];
    if (v_20906 == nil) goto v_20703;
    goto v_20717;
v_20713:
    stack[0] = stack[-5];
    goto v_20714;
v_20715:
    goto v_20727;
v_20721:
    v_20908 = elt(env, 4); // expt
    goto v_20722;
v_20723:
    v_20907 = stack[-4];
    goto v_20724;
v_20725:
    v_20906 = stack[-6];
    goto v_20726;
v_20727:
    goto v_20721;
v_20722:
    goto v_20723;
v_20724:
    goto v_20725;
v_20726:
    v_20906 = list3(v_20908, v_20907, v_20906);
    env = stack[-7];
    fn = elt(env, 11); // simp
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    v_20906 = qcar(v_20906);
    goto v_20716;
v_20717:
    goto v_20713;
v_20714:
    goto v_20715;
v_20716:
    fn = elt(env, 12); // quotf
    v_20906 = (*qfn2(fn))(fn, stack[0], v_20906);
    env = stack[-7];
    stack[-5] = v_20906;
    goto v_20701;
v_20703:
v_20701:
    v_20906 = stack[-5];
    fn = elt(env, 8); // moduntag
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    fn = elt(env, 13); // general!-reduce!-mod!-p
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[-5] = v_20906;
    v_20906 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_20906;
v_20740:
    goto v_20753;
v_20749:
    v_20906 = qvalue(elt(env, 3)); // current!-modulus
    v_20907 = sub1(v_20906);
    env = stack[-7];
    goto v_20750;
v_20751:
    v_20906 = stack[-3];
    goto v_20752;
v_20753:
    goto v_20749;
v_20750:
    goto v_20751;
v_20752:
    v_20906 = difference2(v_20907, v_20906);
    env = stack[-7];
    v_20906 = Lminusp(nil, v_20906);
    env = stack[-7];
    if (v_20906 == nil) goto v_20746;
    v_20906 = nil;
    goto v_20739;
v_20746:
    goto v_20769;
v_20763:
    v_20908 = stack[-5];
    goto v_20764;
v_20765:
    v_20907 = stack[-4];
    goto v_20766;
v_20767:
    v_20906 = stack[-3];
    goto v_20768;
v_20769:
    goto v_20763;
v_20764:
    goto v_20765;
v_20766:
    goto v_20767;
v_20768:
    fn = elt(env, 14); // general!-evaluate!-mod!-p
    v_20906 = (*qfnn(fn))(fn, 3, v_20908, v_20907, v_20906);
    env = stack[-7];
    if (v_20906 == nil) goto v_20760;
    else goto v_20761;
v_20760:
    v_20906 = stack[-3];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    goto v_20759;
v_20761:
    v_20906 = nil;
v_20759:
    stack[-2] = v_20906;
    v_20906 = stack[-2];
    fn = elt(env, 15); // lastpair
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[-1] = v_20906;
    v_20906 = stack[-3];
    v_20906 = add1(v_20906);
    env = stack[-7];
    stack[-3] = v_20906;
    v_20906 = stack[-1];
    if (!consp(v_20906)) goto v_20781;
    else goto v_20782;
v_20781:
    goto v_20740;
v_20782:
v_20741:
    goto v_20794;
v_20790:
    v_20906 = qvalue(elt(env, 3)); // current!-modulus
    v_20907 = sub1(v_20906);
    env = stack[-7];
    goto v_20791;
v_20792:
    v_20906 = stack[-3];
    goto v_20793;
v_20794:
    goto v_20790;
v_20791:
    goto v_20792;
v_20793:
    v_20906 = difference2(v_20907, v_20906);
    env = stack[-7];
    v_20906 = Lminusp(nil, v_20906);
    env = stack[-7];
    if (v_20906 == nil) goto v_20787;
    v_20906 = stack[-2];
    goto v_20739;
v_20787:
    goto v_20804;
v_20800:
    stack[0] = stack[-1];
    goto v_20801;
v_20802:
    goto v_20817;
v_20811:
    v_20908 = stack[-5];
    goto v_20812;
v_20813:
    v_20907 = stack[-4];
    goto v_20814;
v_20815:
    v_20906 = stack[-3];
    goto v_20816;
v_20817:
    goto v_20811;
v_20812:
    goto v_20813;
v_20814:
    goto v_20815;
v_20816:
    fn = elt(env, 14); // general!-evaluate!-mod!-p
    v_20906 = (*qfnn(fn))(fn, 3, v_20908, v_20907, v_20906);
    env = stack[-7];
    if (v_20906 == nil) goto v_20808;
    else goto v_20809;
v_20808:
    v_20906 = stack[-3];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    goto v_20807;
v_20809:
    v_20906 = nil;
v_20807:
    goto v_20803;
v_20804:
    goto v_20800;
v_20801:
    goto v_20802;
v_20803:
    v_20906 = Lrplacd(nil, stack[0], v_20906);
    env = stack[-7];
    v_20906 = stack[-1];
    fn = elt(env, 15); // lastpair
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    stack[-1] = v_20906;
    v_20906 = stack[-3];
    v_20906 = add1(v_20906);
    env = stack[-7];
    stack[-3] = v_20906;
    goto v_20741;
v_20739:
    stack[0] = v_20906;
    goto v_20836;
v_20832:
    v_20907 = stack[-6];
    goto v_20833;
v_20834:
    v_20906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20835;
v_20836:
    goto v_20832;
v_20833:
    goto v_20834;
v_20835:
    v_20906 = (LispObject)greaterp2(v_20907, v_20906);
    v_20906 = v_20906 ? lisp_true : nil;
    env = stack[-7];
    if (v_20906 == nil) goto v_20830;
    goto v_20844;
v_20840:
    goto v_20841;
v_20842:
    v_20906 = nil;
    v_20906 = ncons(v_20906);
    env = stack[-7];
    goto v_20843;
v_20844:
    goto v_20840;
v_20841:
    goto v_20842;
v_20843:
    v_20906 = Lappend(nil, stack[0], v_20906);
    env = stack[-7];
    stack[0] = v_20906;
    goto v_20828;
v_20830:
v_20828:
v_20609:
    v_20906 = stack[0];
    stack[-5] = v_20906;
    v_20906 = stack[-5];
    if (v_20906 == nil) goto v_20857;
    else goto v_20858;
v_20857:
    v_20906 = nil;
    goto v_20852;
v_20858:
    v_20906 = stack[-5];
    v_20906 = qcar(v_20906);
    goto v_20871;
v_20867:
    stack[0] = stack[-4];
    goto v_20868;
v_20869:
    fn = elt(env, 16); // prepf
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    goto v_20870;
v_20871:
    goto v_20867;
v_20868:
    goto v_20869;
v_20870:
    v_20906 = cons(stack[0], v_20906);
    env = stack[-7];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    stack[-2] = v_20906;
    stack[-3] = v_20906;
v_20853:
    v_20906 = stack[-5];
    v_20906 = qcdr(v_20906);
    stack[-5] = v_20906;
    v_20906 = stack[-5];
    if (v_20906 == nil) goto v_20879;
    else goto v_20880;
v_20879:
    v_20906 = stack[-3];
    goto v_20852;
v_20880:
    goto v_20888;
v_20884:
    stack[-1] = stack[-2];
    goto v_20885;
v_20886:
    v_20906 = stack[-5];
    v_20906 = qcar(v_20906);
    goto v_20900;
v_20896:
    stack[0] = stack[-4];
    goto v_20897;
v_20898:
    fn = elt(env, 16); // prepf
    v_20906 = (*qfn1(fn))(fn, v_20906);
    env = stack[-7];
    goto v_20899;
v_20900:
    goto v_20896;
v_20897:
    goto v_20898;
v_20899:
    v_20906 = cons(stack[0], v_20906);
    env = stack[-7];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    v_20906 = ncons(v_20906);
    env = stack[-7];
    goto v_20887;
v_20888:
    goto v_20884;
v_20885:
    goto v_20886;
v_20887:
    v_20906 = Lrplacd(nil, stack[-1], v_20906);
    env = stack[-7];
    v_20906 = stack[-2];
    v_20906 = qcdr(v_20906);
    stack[-2] = v_20906;
    goto v_20853;
v_20852:
    return onevalue(v_20906);
}



// Code for order_of_der_mind

static LispObject CC_order_of_der_mind(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20607;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20607 = v_20601;
// end of prologue
    v_20607 = qcdr(v_20607);
    v_20607 = qcar(v_20607);
    {
        fn = elt(env, 1); // length_multiindex
        return (*qfn1(fn))(fn, v_20607);
    }
}



// Code for lalr_warn_shift_reduce_conflict

static LispObject CC_lalr_warn_shift_reduce_conflict(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20643;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lalr_warn_shift_reduce_conflict");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20603;
    stack[-1] = v_20602;
    stack[-2] = v_20601;
// end of prologue
    v_20643 = Lposn(nil, 0);
    env = stack[-3];
    v_20643 = (LispObject)zerop(v_20643);
    v_20643 = v_20643 ? lisp_true : nil;
    env = stack[-3];
    if (v_20643 == nil) goto v_20607;
    else goto v_20608;
v_20607:
    v_20643 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_20606;
v_20608:
v_20606:
    v_20643 = elt(env, 1); // "+++ Shift/reduce conflict in itemset #"
    v_20643 = Lprinc(nil, v_20643);
    env = stack[-3];
    v_20643 = stack[0];
    v_20643 = Lprin(nil, v_20643);
    env = stack[-3];
    v_20643 = elt(env, 2); // " on lookahead "
    v_20643 = Lprinc(nil, v_20643);
    env = stack[-3];
    v_20643 = stack[-2];
    v_20643 = qcar(v_20643);
    fn = elt(env, 6); // lalr_prin_symbol
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    v_20643 = Lterpri(nil, 0);
    env = stack[-3];
    v_20643 = elt(env, 3); // "Reduce: "
    v_20643 = Lprinc(nil, v_20643);
    env = stack[-3];
    v_20643 = stack[-1];
    v_20643 = qcdr(v_20643);
    v_20643 = qcar(v_20643);
    v_20643 = qcdr(v_20643);
    v_20643 = qcar(v_20643);
    fn = elt(env, 7); // lalr_prin_production
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    v_20643 = Lterpri(nil, 0);
    env = stack[-3];
    v_20643 = elt(env, 4); // "Shift: to state #"
    v_20643 = Lprinc(nil, v_20643);
    env = stack[-3];
    v_20643 = stack[-2];
    v_20643 = qcdr(v_20643);
    v_20643 = qcar(v_20643);
    v_20643 = qcdr(v_20643);
    v_20643 = qcar(v_20643);
    v_20643 = Lprin(nil, v_20643);
    env = stack[-3];
    v_20643 = Lterpri(nil, 0);
    env = stack[-3];
    v_20643 = elt(env, 5); // "Resolved in favour of the shift operation"
    v_20643 = Lprintc(nil, v_20643);
        return Lterpri(nil, 0);
}



// Code for aex_mult

static LispObject CC_aex_mult(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20643;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20602;
    stack[-1] = v_20601;
// end of prologue
    v_20643 = stack[-1];
    fn = elt(env, 1); // aex_simplenullp
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    if (v_20643 == nil) goto v_20608;
    else goto v_20606;
v_20608:
    v_20643 = stack[0];
    fn = elt(env, 1); // aex_simplenullp
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    if (v_20643 == nil) goto v_20611;
    else goto v_20606;
v_20611:
    goto v_20607;
v_20606:
    {
        fn = elt(env, 2); // aex_0
        return (*qfnn(fn))(fn, 0);
    }
v_20607:
    goto v_20622;
v_20618:
    goto v_20628;
v_20624:
    v_20643 = stack[-1];
    fn = elt(env, 3); // aex_ex
    stack[-2] = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    goto v_20625;
v_20626:
    v_20643 = stack[0];
    fn = elt(env, 3); // aex_ex
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    goto v_20627;
v_20628:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    fn = elt(env, 4); // multsq
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_20643);
    env = stack[-3];
    goto v_20619;
v_20620:
    goto v_20638;
v_20634:
    v_20643 = stack[-1];
    fn = elt(env, 5); // aex_ctx
    stack[-1] = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    goto v_20635;
v_20636:
    v_20643 = stack[0];
    fn = elt(env, 5); // aex_ctx
    v_20643 = (*qfn1(fn))(fn, v_20643);
    env = stack[-3];
    goto v_20637;
v_20638:
    goto v_20634;
v_20635:
    goto v_20636;
v_20637:
    fn = elt(env, 6); // ctx_union
    v_20643 = (*qfn2(fn))(fn, stack[-1], v_20643);
    env = stack[-3];
    goto v_20621;
v_20622:
    goto v_20618;
v_20619:
    goto v_20620;
v_20621:
    {
        LispObject v_20647 = stack[-2];
        fn = elt(env, 7); // aex_mk
        return (*qfn2(fn))(fn, v_20647, v_20643);
    }
    v_20643 = nil;
    return onevalue(v_20643);
}



// Code for cl_bvarl1

static LispObject CC_cl_bvarl1(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20606;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
// copy arguments values to proper place
    v_20606 = v_20601;
// end of prologue
    fn = elt(env, 1); // cl_varl1
    v_20606 = (*qfn1(fn))(fn, v_20606);
    v_20606 = qcdr(v_20606);
    return onevalue(v_20606);
}



// Code for pasf_uprap

static LispObject CC_pasf_uprap(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20611, v_20612;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20611 = v_20601;
// end of prologue
    goto v_20608;
v_20604:
    v_20612 = v_20611;
    goto v_20605;
v_20606:
    v_20611 = nil;
    goto v_20607;
v_20608:
    goto v_20604;
v_20605:
    goto v_20606;
v_20607:
    {
        fn = elt(env, 1); // pasf_uprap1
        return (*qfn2(fn))(fn, v_20612, v_20611);
    }
}



// Code for cgp_lbc

static LispObject CC_cgp_lbc(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20606;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20606 = v_20601;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_20606 = (*qfn1(fn))(fn, v_20606);
    env = stack[0];
    {
        fn = elt(env, 2); // dip_lbc
        return (*qfn1(fn))(fn, v_20606);
    }
}



// Code for listrd

static LispObject CC_listrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20625, v_20626;
    LispObject fn;
    argcheck(nargs, 0, "listrd");
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
    goto v_20611;
v_20607:
    v_20626 = qvalue(elt(env, 2)); // atts
    goto v_20608;
v_20609:
    v_20625 = elt(env, 3); // (order)
    goto v_20610;
v_20611:
    goto v_20607;
v_20608:
    goto v_20609;
v_20610:
    fn = elt(env, 5); // retattributes
    v_20625 = (*qfn2(fn))(fn, v_20626, v_20625);
    env = stack[-2];
    goto v_20621;
v_20615:
    stack[-1] = elt(env, 4); // list
    goto v_20616;
v_20617:
    stack[0] = v_20625;
    goto v_20618;
v_20619:
    fn = elt(env, 6); // stats_getargs
    v_20625 = (*qfnn(fn))(fn, 0);
    goto v_20620;
v_20621:
    goto v_20615;
v_20616:
    goto v_20617;
v_20618:
    goto v_20619;
v_20620:
    {
        LispObject v_20629 = stack[-1];
        LispObject v_20630 = stack[0];
        return list2star(v_20629, v_20630, v_20625);
    }
    return onevalue(v_20625);
}



// Code for evequal

static LispObject CC_evequal(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20659, v_20660, v_20661, v_20662, v_20663;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20661 = v_20602;
    v_20662 = v_20601;
// end of prologue
v_20606:
    v_20659 = v_20662;
    if (v_20659 == nil) goto v_20613;
    else goto v_20614;
v_20613:
    v_20659 = v_20661;
    v_20659 = (v_20659 == nil ? lisp_true : nil);
    goto v_20612;
v_20614:
    v_20659 = nil;
    goto v_20612;
    v_20659 = nil;
v_20612:
    if (v_20659 == nil) goto v_20610;
    v_20659 = lisp_true;
    goto v_20605;
v_20610:
    v_20659 = v_20662;
    if (v_20659 == nil) goto v_20622;
    else goto v_20623;
v_20622:
    v_20659 = elt(env, 1); // (0)
    v_20662 = v_20659;
    goto v_20606;
v_20623:
    v_20659 = v_20661;
    if (v_20659 == nil) goto v_20626;
    else goto v_20627;
v_20626:
    v_20659 = elt(env, 1); // (0)
    v_20661 = v_20659;
    goto v_20606;
v_20627:
    goto v_20640;
v_20636:
    v_20663 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20637;
v_20638:
    goto v_20646;
v_20642:
    v_20659 = v_20662;
    v_20660 = qcar(v_20659);
    goto v_20643;
v_20644:
    v_20659 = v_20661;
    v_20659 = qcar(v_20659);
    goto v_20645;
v_20646:
    goto v_20642;
v_20643:
    goto v_20644;
v_20645:
    v_20659 = (LispObject)(intptr_t)((intptr_t)v_20660 - (intptr_t)v_20659 + TAG_FIXNUM);
    goto v_20639;
v_20640:
    goto v_20636;
v_20637:
    goto v_20638;
v_20639:
    if (v_20663 == v_20659) goto v_20634;
    else goto v_20635;
v_20634:
    v_20659 = v_20662;
    v_20659 = qcdr(v_20659);
    v_20662 = v_20659;
    v_20659 = v_20661;
    v_20659 = qcdr(v_20659);
    v_20661 = v_20659;
    goto v_20606;
v_20635:
    v_20659 = nil;
    goto v_20605;
    goto v_20608;
v_20608:
    v_20659 = nil;
v_20605:
    return onevalue(v_20659);
}



// Code for log_freevars_list

static LispObject CC_log_freevars_list(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20640, v_20641;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "log_freevars_list");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20603;
    stack[-1] = v_20602;
    stack[-2] = v_20601;
// end of prologue
v_20607:
    v_20640 = stack[-1];
    if (!consp(v_20640)) goto v_20610;
    else goto v_20611;
v_20610:
    v_20640 = nil;
    goto v_20606;
v_20611:
    v_20640 = stack[0];
    if (v_20640 == nil) goto v_20615;
    v_20640 = stack[-1];
    v_20640 = qcar(v_20640);
    if (!consp(v_20640)) goto v_20618;
    else goto v_20615;
v_20618:
    v_20640 = stack[-1];
    v_20640 = qcdr(v_20640);
    stack[-1] = v_20640;
    v_20640 = lisp_true;
    stack[0] = v_20640;
    goto v_20607;
v_20615:
    goto v_20631;
v_20627:
    v_20641 = stack[-2];
    goto v_20628;
v_20629:
    v_20640 = stack[-1];
    v_20640 = qcar(v_20640);
    goto v_20630;
v_20631:
    goto v_20627;
v_20628:
    goto v_20629;
v_20630:
    fn = elt(env, 1); // log_freevars
    v_20640 = (*qfn2(fn))(fn, v_20641, v_20640);
    env = stack[-3];
    if (v_20640 == nil) goto v_20625;
    v_20640 = lisp_true;
    goto v_20606;
v_20625:
    v_20640 = stack[-1];
    v_20640 = qcdr(v_20640);
    stack[-1] = v_20640;
    goto v_20607;
    v_20640 = nil;
v_20606:
    return onevalue(v_20640);
}



// Code for clean_numid

static LispObject CC_clean_numid(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20634, v_20635;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20601;
// end of prologue
    stack[-1] = nil;
v_20606:
    v_20634 = stack[0];
    if (v_20634 == nil) goto v_20609;
    else goto v_20610;
v_20609:
    v_20634 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_20634);
    }
v_20610:
    v_20634 = stack[0];
    v_20634 = qcar(v_20634);
    fn = elt(env, 2); // !*id2num
    v_20634 = (*qfn1(fn))(fn, v_20634);
    env = stack[-2];
    if (v_20634 == nil) goto v_20615;
    v_20634 = stack[0];
    v_20634 = qcdr(v_20634);
    stack[0] = v_20634;
    goto v_20606;
v_20615:
    goto v_20628;
v_20624:
    v_20634 = stack[0];
    v_20635 = qcar(v_20634);
    goto v_20625;
v_20626:
    v_20634 = stack[-1];
    goto v_20627;
v_20628:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    v_20634 = cons(v_20635, v_20634);
    env = stack[-2];
    stack[-1] = v_20634;
    v_20634 = stack[0];
    v_20634 = qcdr(v_20634);
    stack[0] = v_20634;
    goto v_20606;
    v_20634 = nil;
    return onevalue(v_20634);
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20721, v_20722, v_20723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_20601;
// end of prologue
    v_20721 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_20721;
    v_20721 = stack[-3];
    fn = elt(env, 5); // listp
    v_20721 = (*qfn1(fn))(fn, v_20721);
    env = stack[-5];
    if (v_20721 == nil) goto v_20614;
    goto v_20626;
v_20622:
    v_20722 = stack[-3];
    goto v_20623;
v_20624:
    v_20721 = elt(env, 2); // minus
    goto v_20625;
v_20626:
    goto v_20622;
v_20623:
    goto v_20624;
v_20625:
    if (!consp(v_20722)) goto v_20620;
    v_20722 = qcar(v_20722);
    if (v_20722 == v_20721) goto v_20619;
    else goto v_20620;
v_20619:
    v_20721 = stack[-3];
    v_20721 = qcdr(v_20721);
    v_20721 = qcar(v_20721);
    stack[-3] = v_20721;
    goto v_20618;
v_20620:
    v_20721 = nil;
    goto v_20607;
v_20618:
    goto v_20612;
v_20614:
v_20612:
    v_20721 = stack[-3];
    if (is_number(v_20721)) goto v_20637;
    v_20721 = stack[-3];
    fn = elt(env, 6); // !*id2num
    v_20721 = (*qfn1(fn))(fn, v_20721);
    env = stack[-5];
    if (v_20721 == nil) goto v_20641;
    else goto v_20637;
v_20641:
    goto v_20638;
v_20637:
    v_20721 = nil;
    goto v_20607;
v_20638:
    v_20721 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20721;
v_20648:
    goto v_20658;
v_20654:
    stack[0] = stack[-4];
    goto v_20655;
v_20656:
    v_20721 = qvalue(elt(env, 3)); // g_dvnames
    fn = elt(env, 7); // upbve
    v_20721 = (*qfn1(fn))(fn, v_20721);
    env = stack[-5];
    goto v_20657;
v_20658:
    goto v_20654;
v_20655:
    goto v_20656;
v_20657:
    v_20721 = (LispObject)lesseq2(stack[0], v_20721);
    v_20721 = v_20721 ? lisp_true : nil;
    env = stack[-5];
    if (v_20721 == nil) goto v_20651;
    else goto v_20652;
v_20651:
    goto v_20647;
v_20652:
    goto v_20671;
v_20667:
    stack[-1] = stack[-3];
    goto v_20668;
v_20669:
    goto v_20677;
v_20673:
    stack[0] = qvalue(elt(env, 3)); // g_dvnames
    goto v_20674;
v_20675:
    v_20721 = stack[-4];
    v_20721 = sub1(v_20721);
    env = stack[-5];
    goto v_20676;
v_20677:
    goto v_20673;
v_20674:
    goto v_20675;
v_20676:
    v_20721 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_20721-TAG_FIXNUM)/(16/CELL)));
    goto v_20670;
v_20671:
    goto v_20667;
v_20668:
    goto v_20669;
v_20670:
    if (equal(stack[-1], v_20721)) goto v_20665;
    else goto v_20666;
v_20665:
    v_20721 = stack[-4];
    stack[-2] = v_20721;
    v_20721 = qvalue(elt(env, 3)); // g_dvnames
    fn = elt(env, 7); // upbve
    v_20721 = (*qfn1(fn))(fn, v_20721);
    env = stack[-5];
    v_20721 = add1(v_20721);
    env = stack[-5];
    stack[-4] = v_20721;
    goto v_20664;
v_20666:
    v_20721 = stack[-4];
    v_20721 = add1(v_20721);
    env = stack[-5];
    stack[-4] = v_20721;
    goto v_20664;
v_20664:
    goto v_20648;
v_20647:
    goto v_20699;
v_20695:
    v_20722 = stack[-2];
    goto v_20696;
v_20697:
    v_20721 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20698;
v_20699:
    goto v_20695;
v_20696:
    goto v_20697;
v_20698:
    if (v_20722 == v_20721) goto v_20693;
    else goto v_20694;
v_20693:
    v_20721 = stack[-3];
    fn = elt(env, 8); // ad_splitname
    v_20721 = (*qfn1(fn))(fn, v_20721);
    env = stack[-5];
    v_20722 = v_20721;
    goto v_20712;
v_20708:
    v_20721 = v_20722;
    v_20721 = qcar(v_20721);
    goto v_20709;
v_20710:
    v_20723 = qvalue(elt(env, 4)); // g_dvbase
    goto v_20711;
v_20712:
    goto v_20708;
v_20709:
    goto v_20710;
v_20711:
    if (v_20721 == v_20723) goto v_20706;
    else goto v_20707;
v_20706:
    v_20721 = v_20722;
    v_20721 = qcdr(v_20721);
    goto v_20607;
v_20707:
    goto v_20692;
v_20694:
    v_20721 = stack[-2];
    goto v_20607;
v_20692:
    v_20721 = nil;
v_20607:
    return onevalue(v_20721);
}



// Code for dvfsf_v

static LispObject CC_dvfsf_v(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20625, v_20626;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20625 = v_20601;
// end of prologue
    goto v_20608;
v_20604:
    v_20626 = v_20625;
    goto v_20605;
v_20606:
    v_20625 = qvalue(elt(env, 1)); // dvfsf_p!*
    goto v_20607;
v_20608:
    goto v_20604;
v_20605:
    goto v_20606;
v_20607:
    fn = elt(env, 2); // qremf
    v_20625 = (*qfn2(fn))(fn, v_20626, v_20625);
    env = stack[0];
    v_20626 = v_20625;
    v_20625 = v_20626;
    v_20625 = qcdr(v_20625);
    if (v_20625 == nil) goto v_20614;
    else goto v_20615;
v_20614:
    v_20625 = v_20626;
    v_20625 = qcar(v_20625);
    v_20625 = CC_dvfsf_v(elt(env, 0), v_20625);
    return add1(v_20625);
v_20615:
    v_20625 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20613;
    v_20625 = nil;
v_20613:
    return onevalue(v_20625);
}



// Code for maxfrom1

static LispObject CC_maxfrom1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20635, v_20636;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20603;
    stack[-1] = v_20602;
    stack[-2] = v_20601;
// end of prologue
v_20607:
    v_20635 = stack[-2];
    if (v_20635 == nil) goto v_20610;
    else goto v_20611;
v_20610:
    v_20635 = stack[0];
    goto v_20606;
v_20611:
    goto v_20621;
v_20617:
    goto v_20627;
v_20623:
    v_20635 = stack[-2];
    v_20635 = qcar(v_20635);
    v_20636 = qcar(v_20635);
    goto v_20624;
v_20625:
    v_20635 = stack[-1];
    goto v_20626;
v_20627:
    goto v_20623;
v_20624:
    goto v_20625;
v_20626:
    fn = elt(env, 1); // nth
    v_20636 = (*qfn2(fn))(fn, v_20636, v_20635);
    env = stack[-3];
    goto v_20618;
v_20619:
    v_20635 = stack[0];
    goto v_20620;
v_20621:
    goto v_20617;
v_20618:
    goto v_20619;
v_20620:
    fn = elt(env, 2); // max
    v_20635 = (*qfn2(fn))(fn, v_20636, v_20635);
    env = stack[-3];
    stack[0] = v_20635;
    v_20635 = stack[-2];
    v_20635 = qcdr(v_20635);
    stack[-2] = v_20635;
    goto v_20607;
    v_20635 = nil;
v_20606:
    return onevalue(v_20635);
}



// Code for get!-denom!-l

static LispObject CC_getKdenomKl(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20653, v_20654, v_20655;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20654 = v_20601;
// end of prologue
    v_20653 = v_20654;
    v_20653 = qcar(v_20653);
    if (!consp(v_20653)) goto v_20605;
    else goto v_20606;
v_20605:
    v_20653 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20604;
v_20606:
    v_20653 = v_20654;
    v_20653 = qcar(v_20653);
    v_20653 = qcdr(v_20653);
    v_20653 = qcdr(v_20653);
    goto v_20604;
    v_20653 = nil;
v_20604:
    v_20654 = qcdr(v_20654);
    stack[0] = v_20654;
v_20620:
    v_20654 = stack[0];
    if (v_20654 == nil) goto v_20625;
    else goto v_20626;
v_20625:
    goto v_20619;
v_20626:
    v_20654 = stack[0];
    v_20654 = qcar(v_20654);
    v_20655 = v_20654;
    goto v_20637;
v_20633:
    v_20654 = v_20653;
    goto v_20634;
v_20635:
    v_20653 = v_20655;
    if (!consp(v_20653)) goto v_20641;
    else goto v_20642;
v_20641:
    v_20653 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20640;
v_20642:
    v_20653 = v_20655;
    v_20653 = qcdr(v_20653);
    v_20653 = qcdr(v_20653);
    goto v_20640;
    v_20653 = nil;
v_20640:
    goto v_20636;
v_20637:
    goto v_20633;
v_20634:
    goto v_20635;
v_20636:
    fn = elt(env, 1); // lcmn
    v_20653 = (*qfn2(fn))(fn, v_20654, v_20653);
    env = stack[-1];
    v_20654 = stack[0];
    v_20654 = qcdr(v_20654);
    stack[0] = v_20654;
    goto v_20620;
v_20619:
    return onevalue(v_20653);
}



// Code for fnrd

static LispObject CC_fnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20632, v_20633;
    LispObject fn;
    argcheck(nargs, 0, "fnrd");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    stack[0] = nil;
    fn = elt(env, 4); // lex
    v_20632 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_20615;
v_20611:
    v_20633 = qvalue(elt(env, 2)); // char
    goto v_20612;
v_20613:
    v_20632 = elt(env, 3); // (c i)
    goto v_20614;
v_20615:
    goto v_20611;
v_20612:
    goto v_20613;
v_20614:
    if (equal(v_20633, v_20632)) goto v_20610;
    goto v_20623;
v_20619:
    v_20632 = qvalue(elt(env, 2)); // char
    v_20633 = Lcompress(nil, v_20632);
    env = stack[-1];
    goto v_20620;
v_20621:
    v_20632 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_20622;
v_20623:
    goto v_20619;
v_20620:
    goto v_20621;
v_20622:
    fn = elt(env, 5); // errorml
    v_20632 = (*qfn2(fn))(fn, v_20633, v_20632);
    env = stack[-1];
    goto v_20608;
v_20610:
    fn = elt(env, 6); // mathml2
    v_20632 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_20632;
    goto v_20608;
v_20608:
    fn = elt(env, 4); // lex
    v_20632 = (*qfnn(fn))(fn, 0);
    v_20632 = stack[0];
    return onevalue(v_20632);
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20651, v_20652;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_20601;
// end of prologue
    stack[-2] = nil;
v_20606:
    v_20651 = stack[-1];
    if (!consp(v_20651)) goto v_20613;
    else goto v_20614;
v_20613:
    v_20651 = lisp_true;
    goto v_20612;
v_20614:
    v_20651 = stack[-1];
    v_20651 = qcar(v_20651);
    v_20651 = (consp(v_20651) ? nil : lisp_true);
    goto v_20612;
    v_20651 = nil;
v_20612:
    if (v_20651 == nil) goto v_20610;
    goto v_20627;
v_20623:
    stack[0] = stack[-2];
    goto v_20624;
v_20625:
    v_20651 = stack[-1];
    fn = elt(env, 1); // drnconv
    v_20651 = (*qfn1(fn))(fn, v_20651);
    env = stack[-3];
    goto v_20626;
v_20627:
    goto v_20623;
v_20624:
    goto v_20625;
v_20626:
    {
        LispObject v_20656 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20656, v_20651);
    }
v_20610:
    goto v_20640;
v_20634:
    v_20651 = stack[-1];
    v_20651 = qcar(v_20651);
    stack[0] = qcar(v_20651);
    goto v_20635;
v_20636:
    v_20651 = stack[-1];
    v_20651 = qcar(v_20651);
    v_20651 = qcdr(v_20651);
    v_20652 = CC_mconv1(elt(env, 0), v_20651);
    env = stack[-3];
    goto v_20637;
v_20638:
    v_20651 = stack[-2];
    goto v_20639;
v_20640:
    goto v_20634;
v_20635:
    goto v_20636;
v_20637:
    goto v_20638;
v_20639:
    v_20651 = acons(stack[0], v_20652, v_20651);
    env = stack[-3];
    stack[-2] = v_20651;
    v_20651 = stack[-1];
    v_20651 = qcdr(v_20651);
    stack[-1] = v_20651;
    goto v_20606;
    v_20651 = nil;
    return onevalue(v_20651);
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20714, v_20715, v_20716;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_20715 = v_20601;
// end of prologue
    v_20714 = v_20715;
    if (!consp(v_20714)) goto v_20605;
    else goto v_20606;
v_20605:
    goto v_20617;
v_20613:
    v_20716 = v_20715;
    goto v_20614;
v_20615:
    v_20714 = elt(env, 1); // gen
    goto v_20616;
v_20617:
    goto v_20613;
v_20614:
    goto v_20615;
v_20616:
    v_20714 = get(v_20716, v_20714);
    env = stack[-4];
    if (v_20714 == nil) goto v_20611;
    goto v_20628;
v_20624:
    v_20716 = v_20715;
    goto v_20625;
v_20626:
    v_20714 = qvalue(elt(env, 3)); // freevarlist!*
    goto v_20627;
v_20628:
    goto v_20624;
v_20625:
    goto v_20626;
v_20627:
    v_20714 = Latsoc(nil, v_20716, v_20714);
    stack[0] = v_20714;
    v_20714 = stack[0];
    if (v_20714 == nil) goto v_20634;
    else goto v_20635;
v_20634:
    goto v_20642;
v_20638:
    stack[0] = v_20715;
    goto v_20639;
v_20640:
    fn = elt(env, 4); // pm!:gensym
    v_20714 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_20641;
v_20642:
    goto v_20638;
v_20639:
    goto v_20640;
v_20641:
    v_20714 = cons(stack[0], v_20714);
    env = stack[-4];
    stack[0] = v_20714;
    goto v_20652;
v_20646:
    v_20714 = stack[0];
    v_20716 = qcdr(v_20714);
    goto v_20647;
v_20648:
    v_20715 = elt(env, 1); // gen
    goto v_20649;
v_20650:
    v_20714 = lisp_true;
    goto v_20651;
v_20652:
    goto v_20646;
v_20647:
    goto v_20648;
v_20649:
    goto v_20650;
v_20651:
    v_20714 = Lputprop(nil, 3, v_20716, v_20715, v_20714);
    env = stack[-4];
    goto v_20662;
v_20658:
    v_20715 = stack[0];
    goto v_20659;
v_20660:
    v_20714 = qvalue(elt(env, 3)); // freevarlist!*
    goto v_20661;
v_20662:
    goto v_20658;
v_20659:
    goto v_20660;
v_20661:
    v_20714 = cons(v_20715, v_20714);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_20714; // freevarlist!*
    goto v_20633;
v_20635:
v_20633:
    v_20714 = stack[0];
    v_20714 = qcdr(v_20714);
    goto v_20609;
v_20611:
    v_20714 = v_20715;
    goto v_20609;
    v_20714 = nil;
v_20609:
    goto v_20604;
v_20606:
    v_20714 = v_20715;
    stack[-3] = v_20714;
    v_20714 = stack[-3];
    if (v_20714 == nil) goto v_20681;
    else goto v_20682;
v_20681:
    v_20714 = nil;
    goto v_20676;
v_20682:
    v_20714 = stack[-3];
    v_20714 = qcar(v_20714);
    v_20714 = CC_makeKuniqueKfreevars(elt(env, 0), v_20714);
    env = stack[-4];
    v_20714 = ncons(v_20714);
    env = stack[-4];
    stack[-1] = v_20714;
    stack[-2] = v_20714;
v_20677:
    v_20714 = stack[-3];
    v_20714 = qcdr(v_20714);
    stack[-3] = v_20714;
    v_20714 = stack[-3];
    if (v_20714 == nil) goto v_20695;
    else goto v_20696;
v_20695:
    v_20714 = stack[-2];
    goto v_20676;
v_20696:
    goto v_20704;
v_20700:
    stack[0] = stack[-1];
    goto v_20701;
v_20702:
    v_20714 = stack[-3];
    v_20714 = qcar(v_20714);
    v_20714 = CC_makeKuniqueKfreevars(elt(env, 0), v_20714);
    env = stack[-4];
    v_20714 = ncons(v_20714);
    env = stack[-4];
    goto v_20703;
v_20704:
    goto v_20700;
v_20701:
    goto v_20702;
v_20703:
    v_20714 = Lrplacd(nil, stack[0], v_20714);
    env = stack[-4];
    v_20714 = stack[-1];
    v_20714 = qcdr(v_20714);
    stack[-1] = v_20714;
    goto v_20677;
v_20676:
    goto v_20604;
    v_20714 = nil;
v_20604:
    return onevalue(v_20714);
}



// Code for sc_subtrsq

static LispObject CC_sc_subtrsq(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20613, v_20614;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20613 = v_20602;
    v_20614 = v_20601;
// end of prologue
    goto v_20609;
v_20605:
    stack[0] = v_20614;
    goto v_20606;
v_20607:
    fn = elt(env, 1); // negsq
    v_20613 = (*qfn1(fn))(fn, v_20613);
    env = stack[-1];
    goto v_20608;
v_20609:
    goto v_20605;
v_20606:
    goto v_20607;
v_20608:
    {
        LispObject v_20616 = stack[0];
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(fn, v_20616, v_20613);
    }
}



// Code for getrlist

static LispObject CC_getrlist(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20645, v_20646, v_20647;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20647 = v_20601;
// end of prologue
    goto v_20612;
v_20608:
    v_20646 = v_20647;
    goto v_20609;
v_20610:
    v_20645 = elt(env, 1); // list
    goto v_20611;
v_20612:
    goto v_20608;
v_20609:
    goto v_20610;
v_20611:
    if (!consp(v_20646)) goto v_20606;
    v_20646 = qcar(v_20646);
    if (v_20646 == v_20645) goto v_20605;
    else goto v_20606;
v_20605:
    v_20645 = v_20647;
    v_20645 = qcdr(v_20645);
    goto v_20604;
v_20606:
    goto v_20624;
v_20620:
    goto v_20634;
v_20630:
    v_20646 = v_20647;
    goto v_20631;
v_20632:
    v_20645 = elt(env, 2); // !*sq
    goto v_20633;
v_20634:
    goto v_20630;
v_20631:
    goto v_20632;
v_20633:
    if (!consp(v_20646)) goto v_20628;
    v_20646 = qcar(v_20646);
    if (v_20646 == v_20645) goto v_20627;
    else goto v_20628;
v_20627:
    v_20645 = v_20647;
    v_20645 = qcdr(v_20645);
    v_20645 = qcar(v_20645);
    fn = elt(env, 4); // prepsq
    v_20645 = (*qfn1(fn))(fn, v_20645);
    env = stack[0];
    v_20646 = v_20645;
    goto v_20626;
v_20628:
    v_20645 = v_20647;
    v_20646 = v_20645;
    goto v_20626;
    v_20646 = nil;
v_20626:
    goto v_20621;
v_20622:
    v_20645 = elt(env, 3); // "list"
    goto v_20623;
v_20624:
    goto v_20620;
v_20621:
    goto v_20622;
v_20623:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_20646, v_20645);
    }
    v_20645 = nil;
v_20604:
    return onevalue(v_20645);
}



// Code for prop!-simp1

static LispObject CC_propKsimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20719, v_20720, v_20721;
    LispObject fn;
    LispObject v_20605, v_20604, v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "prop-simp1");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    v_20604 = va_arg(aa, LispObject);
    v_20605 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_20605,v_20604,v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_20601,v_20602,v_20603,v_20604,v_20605);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_20605;
    stack[0] = v_20604;
    stack[-5] = v_20603;
    stack[-2] = v_20602;
    stack[-6] = v_20601;
// end of prologue
v_20600:
    v_20719 = stack[-2];
    if (v_20719 == nil) goto v_20609;
    else goto v_20610;
v_20609:
    goto v_20619;
v_20613:
    goto v_20625;
v_20621:
    v_20720 = stack[0];
    goto v_20622;
v_20623:
    v_20719 = stack[-4];
    goto v_20624;
v_20625:
    goto v_20621;
v_20622:
    goto v_20623;
v_20624:
    stack[0] = list2(v_20720, v_20719);
    env = stack[-8];
    goto v_20614;
v_20615:
    stack[-1] = stack[-6];
    goto v_20616;
v_20617:
    v_20719 = stack[-5];
    v_20719 = Lreverse(nil, v_20719);
    goto v_20618;
v_20619:
    goto v_20613;
v_20614:
    goto v_20615;
v_20616:
    goto v_20617;
v_20618:
    {
        LispObject v_20730 = stack[0];
        LispObject v_20731 = stack[-1];
        return list2star(v_20730, v_20731, v_20719);
    }
v_20610:
    goto v_20638;
v_20634:
    v_20720 = stack[-6];
    goto v_20635;
v_20636:
    v_20719 = stack[-2];
    v_20719 = qcar(v_20719);
    goto v_20637;
v_20638:
    goto v_20634;
v_20635:
    goto v_20636;
v_20637:
    fn = elt(env, 1); // prop!-simp2
    v_20719 = (*qfn2(fn))(fn, v_20720, v_20719);
    env = stack[-8];
    stack[-3] = v_20719;
    v_20719 = stack[-3];
    if (v_20719 == nil) goto v_20645;
    else goto v_20646;
v_20645:
    goto v_20659;
v_20649:
    stack[-3] = stack[-6];
    goto v_20650;
v_20651:
    v_20719 = stack[-2];
    stack[-1] = qcdr(v_20719);
    goto v_20652;
v_20653:
    goto v_20668;
v_20664:
    v_20719 = stack[-2];
    v_20720 = qcar(v_20719);
    goto v_20665;
v_20666:
    v_20719 = stack[-5];
    goto v_20667;
v_20668:
    goto v_20664;
v_20665:
    goto v_20666;
v_20667:
    v_20721 = cons(v_20720, v_20719);
    env = stack[-8];
    goto v_20654;
v_20655:
    v_20720 = stack[0];
    goto v_20656;
v_20657:
    v_20719 = stack[-4];
    goto v_20658;
v_20659:
    goto v_20649;
v_20650:
    goto v_20651;
v_20652:
    goto v_20653;
v_20654:
    goto v_20655;
v_20656:
    goto v_20657;
v_20658:
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v_20721;
    stack[0] = v_20720;
    stack[-4] = v_20719;
    goto v_20600;
v_20646:
    goto v_20687;
v_20677:
    v_20719 = stack[-3];
    stack[-6] = qcdr(v_20719);
    goto v_20678;
v_20679:
    v_20719 = stack[-2];
    stack[-2] = qcdr(v_20719);
    goto v_20680;
v_20681:
    stack[-1] = stack[-5];
    goto v_20682;
v_20683:
    v_20719 = stack[0];
    stack[0] = add1(v_20719);
    env = stack[-8];
    goto v_20684;
v_20685:
    goto v_20700;
v_20696:
    v_20719 = stack[-3];
    stack[-7] = qcar(v_20719);
    goto v_20697;
v_20698:
    goto v_20708;
v_20704:
    goto v_20705;
v_20706:
    goto v_20715;
v_20711:
    stack[-3] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20712;
v_20713:
    v_20719 = stack[-5];
    v_20719 = Llength(nil, v_20719);
    env = stack[-8];
    goto v_20714;
v_20715:
    goto v_20711;
v_20712:
    goto v_20713;
v_20714:
    v_20719 = Lexpt(nil, stack[-3], v_20719);
    env = stack[-8];
    goto v_20707;
v_20708:
    goto v_20704;
v_20705:
    goto v_20706;
v_20707:
    v_20719 = times2(stack[-4], v_20719);
    env = stack[-8];
    goto v_20699;
v_20700:
    goto v_20696;
v_20697:
    goto v_20698;
v_20699:
    v_20719 = times2(stack[-7], v_20719);
    env = stack[-8];
    goto v_20686;
v_20687:
    goto v_20677;
v_20678:
    goto v_20679;
v_20680:
    goto v_20681;
v_20682:
    goto v_20683;
v_20684:
    goto v_20685;
v_20686:
    stack[-5] = stack[-1];
    stack[-4] = v_20719;
    goto v_20600;
    v_20719 = nil;
    goto v_20608;
    v_20719 = nil;
v_20608:
    return onevalue(v_20719);
}



// Code for assert_formproc

static LispObject CC_assert_formproc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20746, v_20747, v_20748;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_formproc");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_20603;
    stack[-8] = v_20602;
    stack[0] = v_20601;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    goto v_20624;
v_20620:
    v_20747 = stack[-7];
    goto v_20621;
v_20622:
    v_20746 = elt(env, 2); // symbolic
    goto v_20623;
v_20624:
    goto v_20620;
v_20621:
    goto v_20622;
v_20623:
    if (v_20747 == v_20746) goto v_20619;
    v_20746 = elt(env, 3); // "asserted procedures are available in symbolic mode only"
    v_20746 = ncons(v_20746);
    env = stack[-10];
    fn = elt(env, 8); // rederr
    v_20746 = (*qfn1(fn))(fn, v_20746);
    env = stack[-10];
    goto v_20617;
v_20619:
v_20617:
    v_20746 = stack[0];
    v_20746 = qcdr(v_20746);
    v_20746 = qcar(v_20746);
    stack[-9] = v_20746;
    v_20746 = stack[0];
    v_20746 = qcdr(v_20746);
    v_20746 = qcdr(v_20746);
    v_20746 = qcar(v_20746);
    v_20747 = v_20746;
    v_20746 = stack[0];
    v_20746 = qcdr(v_20746);
    v_20746 = qcdr(v_20746);
    v_20746 = qcdr(v_20746);
    v_20746 = qcar(v_20746);
    stack[-6] = v_20746;
    v_20746 = v_20747;
    v_20746 = Lreverse(nil, v_20746);
    env = stack[-10];
    v_20747 = v_20746;
    v_20746 = v_20747;
    v_20746 = qcar(v_20746);
    v_20746 = qcdr(v_20746);
    stack[-3] = v_20746;
    v_20746 = v_20747;
    v_20746 = qcdr(v_20746);
    v_20747 = v_20746;
    v_20746 = v_20747;
    stack[-1] = v_20746;
v_20652:
    v_20746 = stack[-1];
    if (v_20746 == nil) goto v_20656;
    else goto v_20657;
v_20656:
    goto v_20651;
v_20657:
    v_20746 = stack[-1];
    v_20746 = qcar(v_20746);
    stack[0] = v_20746;
    goto v_20668;
v_20664:
    v_20746 = stack[0];
    v_20747 = qcar(v_20746);
    goto v_20665;
v_20666:
    v_20746 = stack[-5];
    goto v_20667;
v_20668:
    goto v_20664;
v_20665:
    goto v_20666;
v_20667:
    v_20746 = cons(v_20747, v_20746);
    env = stack[-10];
    stack[-5] = v_20746;
    goto v_20677;
v_20673:
    v_20746 = stack[0];
    v_20747 = qcdr(v_20746);
    goto v_20674;
v_20675:
    v_20746 = stack[-4];
    goto v_20676;
v_20677:
    goto v_20673;
v_20674:
    goto v_20675;
v_20676:
    v_20746 = cons(v_20747, v_20746);
    env = stack[-10];
    stack[-4] = v_20746;
    v_20746 = stack[-1];
    v_20746 = qcdr(v_20746);
    stack[-1] = v_20746;
    goto v_20652;
v_20651:
    goto v_20690;
v_20684:
    goto v_20700;
v_20692:
    stack[-2] = elt(env, 4); // procedure
    goto v_20693;
v_20694:
    stack[-1] = stack[-9];
    goto v_20695;
v_20696:
    stack[0] = nil;
    goto v_20697;
v_20698:
    goto v_20711;
v_20705:
    v_20748 = elt(env, 5); // expr
    goto v_20706;
v_20707:
    v_20747 = stack[-5];
    goto v_20708;
v_20709:
    v_20746 = stack[-6];
    goto v_20710;
v_20711:
    goto v_20705;
v_20706:
    goto v_20707;
v_20708:
    goto v_20709;
v_20710:
    v_20746 = list3(v_20748, v_20747, v_20746);
    env = stack[-10];
    goto v_20699;
v_20700:
    goto v_20692;
v_20693:
    goto v_20694;
v_20695:
    goto v_20696;
v_20697:
    goto v_20698;
v_20699:
    v_20748 = list3star(stack[-2], stack[-1], stack[0], v_20746);
    env = stack[-10];
    goto v_20685;
v_20686:
    v_20747 = stack[-8];
    goto v_20687;
v_20688:
    v_20746 = stack[-7];
    goto v_20689;
v_20690:
    goto v_20684;
v_20685:
    goto v_20686;
v_20687:
    goto v_20688;
v_20689:
    fn = elt(env, 9); // formproc
    v_20746 = (*qfnn(fn))(fn, 3, v_20748, v_20747, v_20746);
    env = stack[-10];
    stack[0] = v_20746;
    v_20746 = qvalue(elt(env, 6)); // !*assert
    if (v_20746 == nil) goto v_20719;
    else goto v_20720;
v_20719:
    v_20746 = stack[0];
    goto v_20614;
v_20720:
    goto v_20731;
v_20725:
    v_20748 = stack[-9];
    goto v_20726;
v_20727:
    v_20747 = stack[-4];
    goto v_20728;
v_20729:
    v_20746 = stack[-3];
    goto v_20730;
v_20731:
    goto v_20725;
v_20726:
    goto v_20727;
v_20728:
    goto v_20729;
v_20730:
    v_20746 = list3(v_20748, v_20747, v_20746);
    env = stack[-10];
    fn = elt(env, 10); // assert_declarestat1
    v_20746 = (*qfn1(fn))(fn, v_20746);
    env = stack[-10];
    v_20747 = v_20746;
    goto v_20742;
v_20736:
    v_20748 = elt(env, 7); // progn
    goto v_20737;
v_20738:
    v_20746 = stack[0];
    goto v_20739;
v_20740:
    goto v_20741;
v_20742:
    goto v_20736;
v_20737:
    goto v_20738;
v_20739:
    goto v_20740;
v_20741:
    return list3(v_20748, v_20746, v_20747);
v_20614:
    return onevalue(v_20746);
}



// Code for liennewstruc

static LispObject CC_liennewstruc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21370, v_21371, v_21372, v_21373;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "liennewstruc");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-12] = v_20603;
    stack[-13] = v_20602;
    stack[-14] = v_20601;
// end of prologue
    goto v_20617;
v_20611:
    v_21372 = elt(env, 1); // lie_a
    goto v_20612;
v_20613:
    v_21371 = stack[-14];
    goto v_20614;
v_20615:
    v_21370 = stack[-14];
    goto v_20616;
v_20617:
    goto v_20611;
v_20612:
    goto v_20613;
v_20614:
    goto v_20615;
v_20616:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    v_21370 = ncons(v_21370);
    env = stack[-16];
    fn = elt(env, 11); // matrix
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20626;
v_20622:
    stack[0] = elt(env, 1); // lie_a
    goto v_20623;
v_20624:
    goto v_20636;
v_20630:
    v_21372 = elt(env, 2); // expt
    goto v_20631;
v_20632:
    v_21371 = elt(env, 1); // lie_a
    goto v_20633;
v_20634:
    v_21370 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20635;
v_20636:
    goto v_20630;
v_20631:
    goto v_20632;
v_20633:
    goto v_20634;
v_20635:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20625;
v_20626:
    goto v_20622;
v_20623:
    goto v_20624;
v_20625:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[0], v_21370);
    env = stack[-16];
    v_21370 = stack[-13];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-15] = v_21370;
v_20643:
    goto v_20658;
v_20652:
    stack[0] = elt(env, 3); // difference
    goto v_20653;
v_20654:
    goto v_20668;
v_20662:
    v_21372 = elt(env, 3); // difference
    goto v_20663;
v_20664:
    v_21371 = stack[-14];
    goto v_20665;
v_20666:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20667;
v_20668:
    goto v_20662;
v_20663:
    goto v_20664;
v_20665:
    goto v_20666;
v_20667:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20655;
v_20656:
    v_21370 = stack[-15];
    goto v_20657;
v_20658:
    goto v_20652;
v_20653:
    goto v_20654;
v_20655:
    goto v_20656;
v_20657:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_20649;
    goto v_20642;
v_20649:
    goto v_20686;
v_20680:
    v_21372 = elt(env, 4); // plus
    goto v_20681;
v_20682:
    v_21371 = stack[-15];
    goto v_20683;
v_20684:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20685;
v_20686:
    goto v_20680;
v_20681:
    goto v_20682;
v_20683:
    goto v_20684;
v_20685:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-11] = v_21370;
v_20677:
    goto v_20702;
v_20696:
    stack[0] = elt(env, 3); // difference
    goto v_20697;
v_20698:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20699;
v_20700:
    v_21370 = stack[-11];
    goto v_20701;
v_20702:
    goto v_20696;
v_20697:
    goto v_20698;
v_20699:
    goto v_20700;
v_20701:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_20693;
    goto v_20676;
v_20693:
    goto v_20713;
v_20709:
    goto v_20721;
v_20715:
    v_21372 = elt(env, 5); // lie_lamb
    goto v_20716;
v_20717:
    v_21371 = stack[-15];
    goto v_20718;
v_20719:
    v_21370 = stack[-11];
    goto v_20720;
v_20721:
    goto v_20715;
v_20716:
    goto v_20717;
v_20718:
    goto v_20719;
v_20720:
    stack[-10] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20710;
v_20711:
    goto v_20733;
v_20727:
    stack[-9] = elt(env, 6); // quotient
    goto v_20728;
v_20729:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_21370;
    v_21370 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_21370;
v_20739:
    goto v_20754;
v_20748:
    stack[0] = elt(env, 3); // difference
    goto v_20749;
v_20750:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20751;
v_20752:
    v_21370 = stack[-8];
    goto v_20753;
v_20754:
    goto v_20748;
v_20749:
    goto v_20750;
v_20751:
    goto v_20752;
v_20753:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_20745;
    v_21370 = stack[-7];
    stack[0] = v_21370;
    goto v_20738;
v_20745:
    goto v_20768;
v_20762:
    stack[-6] = elt(env, 4); // plus
    goto v_20763;
v_20764:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21370;
    v_21370 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_21370;
v_20774:
    goto v_20789;
v_20783:
    stack[0] = elt(env, 3); // difference
    goto v_20784;
v_20785:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20786;
v_20787:
    v_21370 = stack[-5];
    goto v_20788;
v_20789:
    goto v_20783;
v_20784:
    goto v_20785;
v_20786:
    goto v_20787;
v_20788:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_20780;
    v_21370 = stack[-4];
    v_21371 = v_21370;
    goto v_20773;
v_20780:
    goto v_20803;
v_20797:
    stack[-3] = elt(env, 4); // plus
    goto v_20798;
v_20799:
    goto v_20815;
v_20807:
    stack[-2] = elt(env, 7); // times
    goto v_20808;
v_20809:
    goto v_20824;
v_20818:
    v_21372 = elt(env, 8); // lientrans
    goto v_20819;
v_20820:
    v_21371 = stack[-15];
    goto v_20821;
v_20822:
    v_21370 = stack[-8];
    goto v_20823;
v_20824:
    goto v_20818;
v_20819:
    goto v_20820;
v_20821:
    goto v_20822;
v_20823:
    stack[-1] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20810;
v_20811:
    goto v_20835;
v_20829:
    v_21372 = elt(env, 8); // lientrans
    goto v_20830;
v_20831:
    v_21371 = stack[-11];
    goto v_20832;
v_20833:
    v_21370 = stack[-5];
    goto v_20834;
v_20835:
    goto v_20829;
v_20830:
    goto v_20831;
v_20832:
    goto v_20833;
v_20834:
    stack[0] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20812;
v_20813:
    goto v_20848;
v_20840:
    v_21373 = elt(env, 9); // lie_cc
    goto v_20841;
v_20842:
    v_21372 = stack[-8];
    goto v_20843;
v_20844:
    v_21371 = stack[-5];
    goto v_20845;
v_20846:
    v_21370 = stack[-12];
    goto v_20847;
v_20848:
    goto v_20840;
v_20841:
    goto v_20842;
v_20843:
    goto v_20844;
v_20845:
    goto v_20846;
v_20847:
    v_21370 = list4(v_21373, v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20814;
v_20815:
    goto v_20807;
v_20808:
    goto v_20809;
v_20810:
    goto v_20811;
v_20812:
    goto v_20813;
v_20814:
    v_21370 = list4(stack[-2], stack[-1], stack[0], v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20800;
v_20801:
    v_21370 = stack[-4];
    goto v_20802;
v_20803:
    goto v_20797;
v_20798:
    goto v_20799;
v_20800:
    goto v_20801;
v_20802:
    v_21370 = list3(stack[-3], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-4] = v_21370;
    v_21370 = stack[-5];
    goto v_20864;
v_20858:
    v_21372 = elt(env, 4); // plus
    goto v_20859;
v_20860:
    v_21371 = v_21370;
    goto v_20861;
v_20862:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20863;
v_20864:
    goto v_20858;
v_20859:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-5] = v_21370;
    goto v_20774;
v_20773:
    goto v_20765;
v_20766:
    v_21370 = stack[-7];
    goto v_20767;
v_20768:
    goto v_20762;
v_20763:
    goto v_20764;
v_20765:
    goto v_20766;
v_20767:
    v_21370 = list3(stack[-6], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-7] = v_21370;
    v_21370 = stack[-8];
    goto v_20879;
v_20873:
    v_21372 = elt(env, 4); // plus
    goto v_20874;
v_20875:
    v_21371 = v_21370;
    goto v_20876;
v_20877:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20878;
v_20879:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-8] = v_21370;
    goto v_20739;
v_20738:
    goto v_20730;
v_20731:
    goto v_20890;
v_20884:
    v_21372 = elt(env, 8); // lientrans
    goto v_20885;
v_20886:
    v_21371 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20887;
v_20888:
    v_21370 = stack[-12];
    goto v_20889;
v_20890:
    goto v_20884;
v_20885:
    goto v_20886;
v_20887:
    goto v_20888;
v_20889:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20732;
v_20733:
    goto v_20727;
v_20728:
    goto v_20729;
v_20730:
    goto v_20731;
v_20732:
    v_21370 = list3(stack[-9], stack[0], v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20712;
v_20713:
    goto v_20709;
v_20710:
    goto v_20711;
v_20712:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[-10], v_21370);
    env = stack[-16];
    v_21370 = stack[-11];
    goto v_20904;
v_20898:
    v_21372 = elt(env, 4); // plus
    goto v_20899;
v_20900:
    v_21371 = v_21370;
    goto v_20901;
v_20902:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20903;
v_20904:
    goto v_20898;
v_20899:
    goto v_20900;
v_20901:
    goto v_20902;
v_20903:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-11] = v_21370;
    goto v_20677;
v_20676:
    v_21370 = stack[-15];
    goto v_20918;
v_20912:
    v_21372 = elt(env, 4); // plus
    goto v_20913;
v_20914:
    v_21371 = v_21370;
    goto v_20915;
v_20916:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20917;
v_20918:
    goto v_20912;
v_20913:
    goto v_20914;
v_20915:
    goto v_20916;
v_20917:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-15] = v_21370;
    goto v_20643;
v_20642:
    goto v_20934;
v_20928:
    v_21372 = elt(env, 4); // plus
    goto v_20929;
v_20930:
    v_21371 = stack[-13];
    goto v_20931;
v_20932:
    v_21370 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20933;
v_20934:
    goto v_20928;
v_20929:
    goto v_20930;
v_20931:
    goto v_20932;
v_20933:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-2] = v_21370;
v_20925:
    goto v_20950;
v_20944:
    stack[0] = elt(env, 3); // difference
    goto v_20945;
v_20946:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20947;
v_20948:
    v_21370 = stack[-2];
    goto v_20949;
v_20950:
    goto v_20944;
v_20945:
    goto v_20946;
v_20947:
    goto v_20948;
v_20949:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_20941;
    goto v_20924;
v_20941:
    goto v_20961;
v_20957:
    goto v_20969;
v_20963:
    stack[-1] = elt(env, 1); // lie_a
    goto v_20964;
v_20965:
    stack[0] = stack[-2];
    goto v_20966;
v_20967:
    goto v_20979;
v_20973:
    v_21372 = elt(env, 4); // plus
    goto v_20974;
v_20975:
    v_21371 = stack[-13];
    goto v_20976;
v_20977:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20978;
v_20979:
    goto v_20973;
v_20974:
    goto v_20975;
v_20976:
    goto v_20977;
v_20978:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20968;
v_20969:
    goto v_20963;
v_20964:
    goto v_20965;
v_20966:
    goto v_20967;
v_20968:
    stack[-1] = list3(stack[-1], stack[0], v_21370);
    env = stack[-16];
    goto v_20958;
v_20959:
    goto v_20989;
v_20985:
    stack[0] = elt(env, 10); // minus
    goto v_20986;
v_20987:
    goto v_20998;
v_20992:
    v_21372 = elt(env, 5); // lie_lamb
    goto v_20993;
v_20994:
    v_21371 = stack[-13];
    goto v_20995;
v_20996:
    v_21370 = stack[-2];
    goto v_20997;
v_20998:
    goto v_20992;
v_20993:
    goto v_20994;
v_20995:
    goto v_20996;
v_20997:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_20988;
v_20989:
    goto v_20985;
v_20986:
    goto v_20987;
v_20988:
    v_21370 = list2(stack[0], v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_20960;
v_20961:
    goto v_20957;
v_20958:
    goto v_20959;
v_20960:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[-1], v_21370);
    env = stack[-16];
    goto v_21007;
v_21003:
    goto v_21015;
v_21009:
    v_21372 = elt(env, 1); // lie_a
    goto v_21010;
v_21011:
    v_21371 = stack[-2];
    goto v_21012;
v_21013:
    v_21370 = stack[-13];
    goto v_21014;
v_21015:
    goto v_21009;
v_21010:
    goto v_21011;
v_21012:
    goto v_21013;
v_21014:
    stack[-1] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21004;
v_21005:
    goto v_21027;
v_21021:
    stack[0] = elt(env, 5); // lie_lamb
    goto v_21022;
v_21023:
    goto v_21036;
v_21030:
    v_21372 = elt(env, 4); // plus
    goto v_21031;
v_21032:
    v_21371 = stack[-13];
    goto v_21033;
v_21034:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21035;
v_21036:
    goto v_21030;
v_21031:
    goto v_21032;
v_21033:
    goto v_21034;
v_21035:
    v_21371 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21024;
v_21025:
    v_21370 = stack[-2];
    goto v_21026;
v_21027:
    goto v_21021;
v_21022:
    goto v_21023;
v_21024:
    goto v_21025;
v_21026:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21006;
v_21007:
    goto v_21003;
v_21004:
    goto v_21005;
v_21006:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[-1], v_21370);
    env = stack[-16];
    v_21370 = stack[-2];
    goto v_21051;
v_21045:
    v_21372 = elt(env, 4); // plus
    goto v_21046;
v_21047:
    v_21371 = v_21370;
    goto v_21048;
v_21049:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21050;
v_21051:
    goto v_21045;
v_21046:
    goto v_21047;
v_21048:
    goto v_21049;
v_21050:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-2] = v_21370;
    goto v_20925;
v_20924:
    goto v_21060;
v_21056:
    stack[0] = elt(env, 8); // lientrans
    goto v_21057;
v_21058:
    goto v_21070;
v_21064:
    v_21372 = elt(env, 7); // times
    goto v_21065;
v_21066:
    v_21371 = elt(env, 1); // lie_a
    goto v_21067;
v_21068:
    v_21370 = elt(env, 8); // lientrans
    goto v_21069;
v_21070:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    goto v_21068;
v_21069:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21059;
v_21060:
    goto v_21056;
v_21057:
    goto v_21058;
v_21059:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[0], v_21370);
    env = stack[-16];
    goto v_21086;
v_21080:
    v_21372 = elt(env, 4); // plus
    goto v_21081;
v_21082:
    v_21371 = stack[-13];
    goto v_21083;
v_21084:
    v_21370 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21085;
v_21086:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-13] = v_21370;
v_21077:
    goto v_21102;
v_21096:
    stack[0] = elt(env, 3); // difference
    goto v_21097;
v_21098:
    goto v_21112;
v_21106:
    v_21372 = elt(env, 3); // difference
    goto v_21107;
v_21108:
    v_21371 = stack[-14];
    goto v_21109;
v_21110:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21111;
v_21112:
    goto v_21106;
v_21107:
    goto v_21108;
v_21109:
    goto v_21110;
v_21111:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21099;
v_21100:
    v_21370 = stack[-13];
    goto v_21101;
v_21102:
    goto v_21096;
v_21097:
    goto v_21098;
v_21099:
    goto v_21100;
v_21101:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_21093;
    goto v_21076;
v_21093:
    goto v_21130;
v_21124:
    v_21372 = elt(env, 4); // plus
    goto v_21125;
v_21126:
    v_21371 = stack[-13];
    goto v_21127;
v_21128:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21129;
v_21130:
    goto v_21124;
v_21125:
    goto v_21126;
v_21127:
    goto v_21128;
v_21129:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-11] = v_21370;
v_21121:
    goto v_21146;
v_21140:
    stack[0] = elt(env, 3); // difference
    goto v_21141;
v_21142:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21143;
v_21144:
    v_21370 = stack[-11];
    goto v_21145;
v_21146:
    goto v_21140;
v_21141:
    goto v_21142;
v_21143:
    goto v_21144;
v_21145:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_21137;
    goto v_21120;
v_21137:
    goto v_21157;
v_21153:
    goto v_21165;
v_21159:
    v_21372 = elt(env, 5); // lie_lamb
    goto v_21160;
v_21161:
    v_21371 = stack[-13];
    goto v_21162;
v_21163:
    v_21370 = stack[-11];
    goto v_21164;
v_21165:
    goto v_21159;
v_21160:
    goto v_21161;
v_21162:
    goto v_21163;
v_21164:
    stack[-10] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21154;
v_21155:
    goto v_21177;
v_21171:
    stack[-9] = elt(env, 6); // quotient
    goto v_21172;
v_21173:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_21370;
    v_21370 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_21370;
v_21183:
    goto v_21198;
v_21192:
    stack[0] = elt(env, 3); // difference
    goto v_21193;
v_21194:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21195;
v_21196:
    v_21370 = stack[-8];
    goto v_21197;
v_21198:
    goto v_21192;
v_21193:
    goto v_21194;
v_21195:
    goto v_21196;
v_21197:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_21189;
    v_21370 = stack[-7];
    stack[0] = v_21370;
    goto v_21182;
v_21189:
    goto v_21212;
v_21206:
    stack[-6] = elt(env, 4); // plus
    goto v_21207;
v_21208:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21370;
    v_21370 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_21370;
v_21218:
    goto v_21233;
v_21227:
    stack[0] = elt(env, 3); // difference
    goto v_21228;
v_21229:
    v_21370 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21230;
v_21231:
    v_21370 = stack[-5];
    goto v_21232;
v_21233:
    goto v_21227;
v_21228:
    goto v_21229;
v_21230:
    goto v_21231;
v_21232:
    v_21370 = list3(stack[0], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    if (v_21370 == nil) goto v_21224;
    v_21370 = stack[-4];
    v_21371 = v_21370;
    goto v_21217;
v_21224:
    goto v_21247;
v_21241:
    stack[-3] = elt(env, 4); // plus
    goto v_21242;
v_21243:
    goto v_21259;
v_21251:
    stack[-2] = elt(env, 7); // times
    goto v_21252;
v_21253:
    goto v_21268;
v_21262:
    v_21372 = elt(env, 8); // lientrans
    goto v_21263;
v_21264:
    v_21371 = stack[-13];
    goto v_21265;
v_21266:
    v_21370 = stack[-8];
    goto v_21267;
v_21268:
    goto v_21262;
v_21263:
    goto v_21264;
v_21265:
    goto v_21266;
v_21267:
    stack[-1] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21254;
v_21255:
    goto v_21279;
v_21273:
    v_21372 = elt(env, 8); // lientrans
    goto v_21274;
v_21275:
    v_21371 = stack[-11];
    goto v_21276;
v_21277:
    v_21370 = stack[-5];
    goto v_21278;
v_21279:
    goto v_21273;
v_21274:
    goto v_21275;
v_21276:
    goto v_21277;
v_21278:
    stack[0] = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21256;
v_21257:
    goto v_21292;
v_21284:
    v_21373 = elt(env, 9); // lie_cc
    goto v_21285;
v_21286:
    v_21372 = stack[-8];
    goto v_21287;
v_21288:
    v_21371 = stack[-5];
    goto v_21289;
v_21290:
    v_21370 = stack[-12];
    goto v_21291;
v_21292:
    goto v_21284;
v_21285:
    goto v_21286;
v_21287:
    goto v_21288;
v_21289:
    goto v_21290;
v_21291:
    v_21370 = list4(v_21373, v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21258;
v_21259:
    goto v_21251;
v_21252:
    goto v_21253;
v_21254:
    goto v_21255;
v_21256:
    goto v_21257;
v_21258:
    v_21370 = list4(stack[-2], stack[-1], stack[0], v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21371 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21244;
v_21245:
    v_21370 = stack[-4];
    goto v_21246;
v_21247:
    goto v_21241;
v_21242:
    goto v_21243;
v_21244:
    goto v_21245;
v_21246:
    v_21370 = list3(stack[-3], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-4] = v_21370;
    v_21370 = stack[-5];
    goto v_21308;
v_21302:
    v_21372 = elt(env, 4); // plus
    goto v_21303;
v_21304:
    v_21371 = v_21370;
    goto v_21305;
v_21306:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21307;
v_21308:
    goto v_21302;
v_21303:
    goto v_21304;
v_21305:
    goto v_21306;
v_21307:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-5] = v_21370;
    goto v_21218;
v_21217:
    goto v_21209;
v_21210:
    v_21370 = stack[-7];
    goto v_21211;
v_21212:
    goto v_21206;
v_21207:
    goto v_21208;
v_21209:
    goto v_21210;
v_21211:
    v_21370 = list3(stack[-6], v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-7] = v_21370;
    v_21370 = stack[-8];
    goto v_21323;
v_21317:
    v_21372 = elt(env, 4); // plus
    goto v_21318;
v_21319:
    v_21371 = v_21370;
    goto v_21320;
v_21321:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21322;
v_21323:
    goto v_21317;
v_21318:
    goto v_21319;
v_21320:
    goto v_21321;
v_21322:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-8] = v_21370;
    goto v_21183;
v_21182:
    goto v_21174;
v_21175:
    goto v_21334;
v_21328:
    v_21372 = elt(env, 8); // lientrans
    goto v_21329;
v_21330:
    v_21371 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21331;
v_21332:
    v_21370 = stack[-12];
    goto v_21333;
v_21334:
    goto v_21328;
v_21329:
    goto v_21330;
v_21331:
    goto v_21332;
v_21333:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    goto v_21176;
v_21177:
    goto v_21171;
v_21172:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    v_21370 = list3(stack[-9], stack[0], v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    goto v_21156;
v_21157:
    goto v_21153;
v_21154:
    goto v_21155;
v_21156:
    fn = elt(env, 13); // setk
    v_21370 = (*qfn2(fn))(fn, stack[-10], v_21370);
    env = stack[-16];
    v_21370 = stack[-11];
    goto v_21348;
v_21342:
    v_21372 = elt(env, 4); // plus
    goto v_21343;
v_21344:
    v_21371 = v_21370;
    goto v_21345;
v_21346:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21347;
v_21348:
    goto v_21342;
v_21343:
    goto v_21344;
v_21345:
    goto v_21346;
v_21347:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-11] = v_21370;
    goto v_21121;
v_21120:
    v_21370 = stack[-13];
    goto v_21362;
v_21356:
    v_21372 = elt(env, 4); // plus
    goto v_21357;
v_21358:
    v_21371 = v_21370;
    goto v_21359;
v_21360:
    v_21370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21361;
v_21362:
    goto v_21356;
v_21357:
    goto v_21358;
v_21359:
    goto v_21360;
v_21361:
    v_21370 = list3(v_21372, v_21371, v_21370);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    stack[-13] = v_21370;
    goto v_21077;
v_21076:
    v_21370 = elt(env, 1); // lie_a
    v_21370 = ncons(v_21370);
    env = stack[-16];
    fn = elt(env, 16); // clear
    v_21370 = (*qfn1(fn))(fn, v_21370);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_21370 = (*qfn1(fn))(fn, v_21370);
    v_21370 = nil;
    return onevalue(v_21370);
}



// Code for groeb!=crita

static LispObject CC_groebMcrita(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20611, v_20612;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20611 = v_20601;
// end of prologue
    goto v_20608;
v_20604:
    v_20612 = v_20611;
    goto v_20605;
v_20606:
    v_20611 = elt(env, 1); // groeb!=testa
    goto v_20607;
v_20608:
    goto v_20604;
v_20605:
    goto v_20606;
v_20607:
    {
        fn = elt(env, 2); // listminimize
        return (*qfn2(fn))(fn, v_20612, v_20611);
    }
}



// Code for difbf

static LispObject CC_difbf(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20857, v_20858, v_20859;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_20602;
    stack[-7] = v_20601;
// end of prologue
    goto v_20622;
v_20618:
    v_20857 = stack[-7];
    v_20857 = qcdr(v_20857);
    v_20858 = qcar(v_20857);
    stack[-8] = v_20858;
    goto v_20619;
v_20620:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20621;
v_20622:
    goto v_20618;
v_20619:
    goto v_20620;
v_20621:
    if (v_20858 == v_20857) goto v_20616;
    else goto v_20617;
v_20616:
    v_20857 = stack[-6];
    fn = elt(env, 5); // minus!:
    v_20857 = (*qfn1(fn))(fn, v_20857);
    env = stack[-9];
    goto v_20612;
v_20617:
    goto v_20637;
v_20633:
    v_20857 = stack[-6];
    v_20857 = qcdr(v_20857);
    v_20858 = qcar(v_20857);
    stack[-5] = v_20858;
    goto v_20634;
v_20635:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20636;
v_20637:
    goto v_20633;
v_20634:
    goto v_20635;
v_20636:
    if (v_20858 == v_20857) goto v_20631;
    else goto v_20632;
v_20631:
    v_20857 = stack[-7];
    goto v_20612;
v_20632:
    goto v_20651;
v_20647:
    goto v_20657;
v_20653:
    v_20857 = stack[-7];
    v_20857 = qcdr(v_20857);
    v_20858 = qcdr(v_20857);
    stack[-4] = v_20858;
    goto v_20654;
v_20655:
    v_20857 = stack[-6];
    v_20857 = qcdr(v_20857);
    v_20857 = qcdr(v_20857);
    stack[-3] = v_20857;
    goto v_20656;
v_20657:
    goto v_20653;
v_20654:
    goto v_20655;
v_20656:
    v_20858 = difference2(v_20858, v_20857);
    env = stack[-9];
    stack[-2] = v_20858;
    goto v_20648;
v_20649:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20650;
v_20651:
    goto v_20647;
v_20648:
    goto v_20649;
v_20650:
    if (v_20858 == v_20857) goto v_20645;
    else goto v_20646;
v_20645:
    goto v_20672;
v_20666:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20667;
v_20668:
    goto v_20679;
v_20675:
    v_20858 = stack[-8];
    goto v_20676;
v_20677:
    v_20857 = stack[-5];
    goto v_20678;
v_20679:
    goto v_20675;
v_20676:
    goto v_20677;
v_20678:
    v_20858 = difference2(v_20858, v_20857);
    env = stack[-9];
    goto v_20669;
v_20670:
    v_20857 = stack[-4];
    goto v_20671;
v_20672:
    goto v_20666;
v_20667:
    goto v_20668;
v_20669:
    goto v_20670;
v_20671:
    v_20857 = list2star(stack[0], v_20858, v_20857);
    env = stack[-9];
    goto v_20612;
v_20646:
    goto v_20688;
v_20684:
    stack[-1] = stack[-2];
    goto v_20685;
v_20686:
    goto v_20695;
v_20691:
    v_20857 = stack[-8];
    v_20857 = Labsval(nil, v_20857);
    env = stack[-9];
    fn = elt(env, 6); // msd
    stack[0] = (*qfn1(fn))(fn, v_20857);
    env = stack[-9];
    goto v_20692;
v_20693:
    v_20857 = stack[-5];
    v_20857 = Labsval(nil, v_20857);
    env = stack[-9];
    fn = elt(env, 6); // msd
    v_20857 = (*qfn1(fn))(fn, v_20857);
    env = stack[-9];
    goto v_20694;
v_20695:
    goto v_20691;
v_20692:
    goto v_20693;
v_20694:
    v_20857 = difference2(stack[0], v_20857);
    env = stack[-9];
    goto v_20687;
v_20688:
    goto v_20684;
v_20685:
    goto v_20686;
v_20687:
    v_20857 = plus2(stack[-1], v_20857);
    env = stack[-9];
    stack[-1] = v_20857;
    v_20857 = qvalue(elt(env, 3)); // !:bprec!:
    v_20857 = add1(v_20857);
    env = stack[-9];
    stack[0] = v_20857;
    goto v_20713;
v_20709:
    v_20858 = stack[-1];
    goto v_20710;
v_20711:
    v_20857 = stack[0];
    goto v_20712;
v_20713:
    goto v_20709;
v_20710:
    goto v_20711;
v_20712:
    v_20857 = (LispObject)greaterp2(v_20858, v_20857);
    v_20857 = v_20857 ? lisp_true : nil;
    env = stack[-9];
    if (v_20857 == nil) goto v_20707;
    v_20857 = stack[-7];
    goto v_20612;
v_20707:
    goto v_20726;
v_20722:
    goto v_20723;
v_20724:
    v_20857 = stack[0];
    v_20857 = negate(v_20857);
    env = stack[-9];
    goto v_20725;
v_20726:
    goto v_20722;
v_20723:
    goto v_20724;
v_20725:
    v_20857 = (LispObject)lessp2(stack[-1], v_20857);
    v_20857 = v_20857 ? lisp_true : nil;
    env = stack[-9];
    if (v_20857 == nil) goto v_20720;
    v_20857 = stack[-6];
    fn = elt(env, 5); // minus!:
    v_20857 = (*qfn1(fn))(fn, v_20857);
    env = stack[-9];
    goto v_20612;
v_20720:
    goto v_20741;
v_20737:
    v_20858 = stack[-2];
    goto v_20738;
v_20739:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20740;
v_20741:
    goto v_20737;
v_20738:
    goto v_20739;
v_20740:
    v_20857 = (LispObject)greaterp2(v_20858, v_20857);
    v_20857 = v_20857 ? lisp_true : nil;
    env = stack[-9];
    if (v_20857 == nil) goto v_20735;
    goto v_20751;
v_20745:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20746;
v_20747:
    goto v_20758;
v_20754:
    goto v_20764;
v_20760:
    v_20858 = stack[-8];
    goto v_20761;
v_20762:
    v_20857 = stack[-2];
    goto v_20763;
v_20764:
    goto v_20760;
v_20761:
    goto v_20762;
v_20763:
    fn = elt(env, 7); // ashift
    v_20858 = (*qfn2(fn))(fn, v_20858, v_20857);
    env = stack[-9];
    goto v_20755;
v_20756:
    v_20857 = stack[-5];
    goto v_20757;
v_20758:
    goto v_20754;
v_20755:
    goto v_20756;
v_20757:
    v_20858 = difference2(v_20858, v_20857);
    env = stack[-9];
    goto v_20748;
v_20749:
    v_20857 = stack[-3];
    goto v_20750;
v_20751:
    goto v_20745;
v_20746:
    goto v_20747;
v_20748:
    goto v_20749;
v_20750:
    v_20857 = list2star(stack[0], v_20858, v_20857);
    env = stack[-9];
    goto v_20612;
v_20735:
    goto v_20778;
v_20772:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_20773;
v_20774:
    goto v_20785;
v_20781:
    stack[-1] = stack[-8];
    goto v_20782;
v_20783:
    goto v_20792;
v_20788:
    stack[-3] = stack[-5];
    goto v_20789;
v_20790:
    v_20857 = stack[-2];
    v_20857 = negate(v_20857);
    env = stack[-9];
    goto v_20791;
v_20792:
    goto v_20788;
v_20789:
    goto v_20790;
v_20791:
    fn = elt(env, 7); // ashift
    v_20857 = (*qfn2(fn))(fn, stack[-3], v_20857);
    env = stack[-9];
    goto v_20784;
v_20785:
    goto v_20781;
v_20782:
    goto v_20783;
v_20784:
    v_20858 = difference2(stack[-1], v_20857);
    env = stack[-9];
    goto v_20775;
v_20776:
    v_20857 = stack[-4];
    goto v_20777;
v_20778:
    goto v_20772;
v_20773:
    goto v_20774;
v_20775:
    goto v_20776;
v_20777:
    v_20857 = list2star(stack[0], v_20858, v_20857);
    env = stack[-9];
    goto v_20612;
    v_20857 = nil;
v_20612:
    stack[-2] = v_20857;
    v_20857 = stack[-2];
    v_20857 = qcdr(v_20857);
    v_20857 = qcar(v_20857);
    v_20859 = v_20857;
    goto v_20813;
v_20809:
    v_20858 = v_20859;
    goto v_20810;
v_20811:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20812;
v_20813:
    goto v_20809;
v_20810:
    goto v_20811;
v_20812:
    if (v_20858 == v_20857) goto v_20807;
    else goto v_20808;
v_20807:
    goto v_20823;
v_20817:
    v_20859 = elt(env, 2); // !:rd!:
    goto v_20818;
v_20819:
    v_20858 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20820;
v_20821:
    v_20857 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20822;
v_20823:
    goto v_20817;
v_20818:
    goto v_20819;
v_20820:
    goto v_20821;
v_20822:
    return list2star(v_20859, v_20858, v_20857);
v_20808:
    goto v_20832;
v_20828:
    v_20858 = v_20859;
    goto v_20829;
v_20830:
    v_20857 = qvalue(elt(env, 3)); // !:bprec!:
    goto v_20831;
v_20832:
    goto v_20828;
v_20829:
    goto v_20830;
v_20831:
    fn = elt(env, 8); // inorm
    v_20857 = (*qfn2(fn))(fn, v_20858, v_20857);
    env = stack[-9];
    v_20859 = v_20857;
    goto v_20842;
v_20836:
    stack[-1] = elt(env, 2); // !:rd!:
    goto v_20837;
v_20838:
    v_20857 = v_20859;
    stack[0] = qcar(v_20857);
    goto v_20839;
v_20840:
    goto v_20851;
v_20847:
    v_20857 = v_20859;
    v_20858 = qcdr(v_20857);
    goto v_20848;
v_20849:
    v_20857 = stack[-2];
    v_20857 = qcdr(v_20857);
    v_20857 = qcdr(v_20857);
    goto v_20850;
v_20851:
    goto v_20847;
v_20848:
    goto v_20849;
v_20850:
    v_20857 = plus2(v_20858, v_20857);
    goto v_20841;
v_20842:
    goto v_20836;
v_20837:
    goto v_20838;
v_20839:
    goto v_20840;
v_20841:
    {
        LispObject v_20869 = stack[-1];
        LispObject v_20870 = stack[0];
        return list2star(v_20869, v_20870, v_20857);
    }
    return onevalue(v_20857);
}



// Code for ra_qmk

static LispObject CC_ra_qmk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20623, v_20624, v_20625;
    LispObject fn;
    LispObject v_20603, v_20602, v_20601;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_qmk");
    va_start(aa, nargs);
    v_20601 = va_arg(aa, LispObject);
    v_20602 = va_arg(aa, LispObject);
    v_20603 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20603,v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20601,v_20602,v_20603);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20623 = v_20603;
    v_20624 = v_20602;
    v_20625 = v_20601;
// end of prologue
    goto v_20612;
v_20606:
    stack[-1] = elt(env, 1); // !:ra!:
    goto v_20607;
v_20608:
    stack[0] = v_20625;
    goto v_20609;
v_20610:
    goto v_20620;
v_20616:
    goto v_20617;
v_20618:
    goto v_20619;
v_20620:
    goto v_20616;
v_20617:
    goto v_20618;
v_20619:
    fn = elt(env, 2); // riv_mk
    v_20623 = (*qfn2(fn))(fn, v_20624, v_20623);
    goto v_20611;
v_20612:
    goto v_20606;
v_20607:
    goto v_20608;
v_20609:
    goto v_20610;
v_20611:
    {
        LispObject v_20628 = stack[-1];
        LispObject v_20629 = stack[0];
        return list3(v_20628, v_20629, v_20623);
    }
}



// Code for lalr_get_lex_codes

static LispObject CC_lalr_get_lex_codes(LispObject env,
                         LispObject v_20601)
{
    env = qenv(env);
    LispObject v_20648, v_20649;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20601);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20648 = v_20601;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_20648;
v_20612:
    v_20648 = stack[0];
    if (v_20648 == nil) goto v_20616;
    else goto v_20617;
v_20616:
    goto v_20611;
v_20617:
    v_20648 = stack[0];
    v_20648 = qcar(v_20648);
    v_20649 = v_20648;
    v_20648 = v_20649;
    v_20648 = Lstringp(nil, v_20648);
    env = stack[-2];
    if (v_20648 == nil) goto v_20626;
    goto v_20634;
v_20630:
    goto v_20631;
v_20632:
    v_20648 = stack[-1];
    goto v_20633;
v_20634:
    goto v_20630;
v_20631:
    goto v_20632;
v_20633:
    v_20648 = cons(v_20649, v_20648);
    env = stack[-2];
    stack[-1] = v_20648;
    goto v_20624;
v_20626:
v_20624:
    v_20648 = stack[0];
    v_20648 = qcdr(v_20648);
    stack[0] = v_20648;
    goto v_20612;
v_20611:
    fn = elt(env, 3); // lex_save_context
    v_20648 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_20648;
    fn = elt(env, 4); // lex_cleanup
    v_20648 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_20648 = stack[-1];
    fn = elt(env, 5); // lex_keywords
    v_20648 = (*qfn1(fn))(fn, v_20648);
    env = stack[-2];
    fn = elt(env, 3); // lex_save_context
    v_20648 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_20648; // lex_context
    fn = elt(env, 6); // lex_export_codes
    v_20648 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_20648;
    v_20648 = stack[0];
    fn = elt(env, 7); // lex_restore_context
    v_20648 = (*qfn1(fn))(fn, v_20648);
    v_20648 = stack[-1];
    return onevalue(v_20648);
}



// Code for polynomcompare

static LispObject CC_polynomcompare(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20689, v_20690, v_20691;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20690 = v_20602;
    v_20689 = v_20601;
// end of prologue
    stack[-1] = v_20689;
    v_20689 = v_20690;
    stack[0] = v_20689;
v_20615:
    v_20689 = stack[-1];
    v_20689 = qcar(v_20689);
    if (v_20689 == nil) goto v_20618;
    v_20689 = stack[0];
    v_20689 = qcar(v_20689);
    if (v_20689 == nil) goto v_20618;
    goto v_20619;
v_20618:
    goto v_20614;
v_20619:
    goto v_20632;
v_20628:
    v_20689 = stack[-1];
    v_20690 = qcar(v_20689);
    goto v_20629;
v_20630:
    v_20689 = stack[0];
    v_20689 = qcar(v_20689);
    goto v_20631;
v_20632:
    goto v_20628;
v_20629:
    goto v_20630;
v_20631:
    fn = elt(env, 2); // monomcompare
    v_20689 = (*qfn2(fn))(fn, v_20690, v_20689);
    env = stack[-2];
    v_20691 = v_20689;
    goto v_20645;
v_20641:
    v_20690 = v_20691;
    goto v_20642;
v_20643:
    v_20689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20644;
v_20645:
    goto v_20641;
v_20642:
    goto v_20643;
v_20644:
    if (v_20690 == v_20689) goto v_20639;
    else goto v_20640;
v_20639:
    v_20689 = nil;
    v_20689 = ncons(v_20689);
    env = stack[-2];
    stack[0] = v_20689;
    goto v_20638;
v_20640:
    goto v_20657;
v_20653:
    v_20690 = v_20691;
    goto v_20654;
v_20655:
    v_20689 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20656;
v_20657:
    goto v_20653;
v_20654:
    goto v_20655;
v_20656:
    if (v_20690 == v_20689) goto v_20651;
    else goto v_20652;
v_20651:
    v_20689 = nil;
    v_20689 = ncons(v_20689);
    env = stack[-2];
    stack[-1] = v_20689;
    goto v_20638;
v_20652:
    v_20689 = stack[-1];
    v_20689 = qcdr(v_20689);
    stack[-1] = v_20689;
    v_20689 = stack[0];
    v_20689 = qcdr(v_20689);
    stack[0] = v_20689;
    goto v_20638;
v_20638:
    goto v_20615;
v_20614:
    v_20689 = stack[-1];
    v_20689 = qcar(v_20689);
    if (v_20689 == nil) goto v_20674;
    v_20689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20608;
v_20674:
    v_20689 = stack[0];
    v_20689 = qcar(v_20689);
    if (v_20689 == nil) goto v_20680;
    v_20689 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20608;
v_20680:
    v_20689 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20608;
    v_20689 = nil;
v_20608:
    return onevalue(v_20689);
}



// Code for mk!+real!+inner!+product

static LispObject CC_mkLrealLinnerLproduct(LispObject env,
                         LispObject v_20601, LispObject v_20602)
{
    env = qenv(env);
    LispObject v_20688, v_20689;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20602,v_20601);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20601,v_20602);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_20602;
    stack[-3] = v_20601;
// end of prologue
    goto v_20617;
v_20613:
    v_20688 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(fn, v_20688);
    env = stack[-5];
    goto v_20614;
v_20615:
    v_20688 = stack[-2];
    fn = elt(env, 4); // get!+vec!+dim
    v_20688 = (*qfn1(fn))(fn, v_20688);
    env = stack[-5];
    goto v_20616;
v_20617:
    goto v_20613;
v_20614:
    goto v_20615;
v_20616:
    if (equal(stack[0], v_20688)) goto v_20612;
    v_20688 = elt(env, 2); // "wrong dimensions in innerproduct"
    fn = elt(env, 5); // rederr
    v_20688 = (*qfn1(fn))(fn, v_20688);
    env = stack[-5];
    goto v_20610;
v_20612:
v_20610:
    goto v_20629;
v_20625:
    v_20689 = nil;
    goto v_20626;
v_20627:
    v_20688 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20628;
v_20629:
    goto v_20625;
v_20626:
    goto v_20627;
v_20628:
    v_20688 = cons(v_20689, v_20688);
    env = stack[-5];
    stack[0] = v_20688;
    v_20688 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20688;
v_20635:
    goto v_20647;
v_20643:
    v_20688 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    v_20689 = (*qfn1(fn))(fn, v_20688);
    env = stack[-5];
    goto v_20644;
v_20645:
    v_20688 = stack[-4];
    goto v_20646;
v_20647:
    goto v_20643;
v_20644:
    goto v_20645;
v_20646:
    v_20688 = difference2(v_20689, v_20688);
    env = stack[-5];
    v_20688 = Lminusp(nil, v_20688);
    env = stack[-5];
    if (v_20688 == nil) goto v_20640;
    goto v_20634;
v_20640:
    goto v_20657;
v_20653:
    stack[-1] = stack[0];
    goto v_20654;
v_20655:
    goto v_20664;
v_20660:
    goto v_20670;
v_20666:
    v_20689 = stack[-3];
    goto v_20667;
v_20668:
    v_20688 = stack[-4];
    goto v_20669;
v_20670:
    goto v_20666;
v_20667:
    goto v_20668;
v_20669:
    fn = elt(env, 6); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(fn, v_20689, v_20688);
    env = stack[-5];
    goto v_20661;
v_20662:
    goto v_20678;
v_20674:
    v_20689 = stack[-2];
    goto v_20675;
v_20676:
    v_20688 = stack[-4];
    goto v_20677;
v_20678:
    goto v_20674;
v_20675:
    goto v_20676;
v_20677:
    fn = elt(env, 6); // get!+vec!+entry
    v_20688 = (*qfn2(fn))(fn, v_20689, v_20688);
    env = stack[-5];
    goto v_20663;
v_20664:
    goto v_20660;
v_20661:
    goto v_20662;
v_20663:
    fn = elt(env, 7); // multsq
    v_20688 = (*qfn2(fn))(fn, stack[0], v_20688);
    env = stack[-5];
    goto v_20656;
v_20657:
    goto v_20653;
v_20654:
    goto v_20655;
v_20656:
    fn = elt(env, 8); // addsq
    v_20688 = (*qfn2(fn))(fn, stack[-1], v_20688);
    env = stack[-5];
    stack[0] = v_20688;
    v_20688 = stack[-4];
    v_20688 = add1(v_20688);
    env = stack[-5];
    stack[-4] = v_20688;
    goto v_20635;
v_20634:
    v_20688 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 3, -1);
    qvalue(elt(env, 3)) = v_20688; // !*sub2
    v_20688 = stack[0];
    fn = elt(env, 9); // subs2
    v_20688 = (*qfn1(fn))(fn, v_20688);
    stack[0] = v_20688;
    ;}  // end of a binding scope
    v_20688 = stack[0];
    return onevalue(v_20688);
}



setup_type const u37_setup[] =
{
    {"pasf_smordtable1",        TOO_FEW_2,      CC_pasf_smordtable1,WRONG_NO_2},
    {"ofsf_sippsignchkf",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sippsignchkf},
    {"vectorml",                CC_vectorml,    TOO_MANY_1,    WRONG_NO_1},
    {"delyzz",                  TOO_FEW_2,      CC_delyzz,     WRONG_NO_2},
    {"evinvlexcomp",            TOO_FEW_2,      CC_evinvlexcomp,WRONG_NO_2},
    {"unplus",                  CC_unplus,      TOO_MANY_1,    WRONG_NO_1},
    {"indordl2",                TOO_FEW_2,      CC_indordl2,   WRONG_NO_2},
    {"calc_coeff",              TOO_FEW_2,      CC_calc_coeff, WRONG_NO_2},
    {"listsub",                 TOO_FEW_2,      CC_listsub,    WRONG_NO_2},
    {"ratfunpri1",              CC_ratfunpri1,  TOO_MANY_1,    WRONG_NO_1},
    {"red_tailreddriver",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_tailreddriver},
    {"dfprintfn",               CC_dfprintfn,   TOO_MANY_1,    WRONG_NO_1},
    {"list_is_all_free",        CC_list_is_all_free,TOO_MANY_1,WRONG_NO_1},
    {"msolve-poly1",            TOO_FEW_2,      CC_msolveKpoly1,WRONG_NO_2},
    {"order_of_der_mind",       CC_order_of_der_mind,TOO_MANY_1,WRONG_NO_1},
    {"lalr_warn_shift_reduce_conflict",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_warn_shift_reduce_conflict},
    {"aex_mult",                TOO_FEW_2,      CC_aex_mult,   WRONG_NO_2},
    {"cl_bvarl1",               CC_cl_bvarl1,   TOO_MANY_1,    WRONG_NO_1},
    {"pasf_uprap",              CC_pasf_uprap,  TOO_MANY_1,    WRONG_NO_1},
    {"cgp_lbc",                 CC_cgp_lbc,     TOO_MANY_1,    WRONG_NO_1},
    {"listrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listrd},
    {"evequal",                 TOO_FEW_2,      CC_evequal,    WRONG_NO_2},
    {"log_freevars_list",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_log_freevars_list},
    {"clean_numid",             CC_clean_numid, TOO_MANY_1,    WRONG_NO_1},
    {"dummyp",                  CC_dummyp,      TOO_MANY_1,    WRONG_NO_1},
    {"dvfsf_v",                 CC_dvfsf_v,     TOO_MANY_1,    WRONG_NO_1},
    {"maxfrom1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_maxfrom1},
    {"get-denom-l",             CC_getKdenomKl, TOO_MANY_1,    WRONG_NO_1},
    {"fnrd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fnrd},
    {"mconv1",                  CC_mconv1,      TOO_MANY_1,    WRONG_NO_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,TOO_MANY_1,WRONG_NO_1},
    {"sc_subtrsq",              TOO_FEW_2,      CC_sc_subtrsq, WRONG_NO_2},
    {"getrlist",                CC_getrlist,    TOO_MANY_1,    WRONG_NO_1},
    {"prop-simp1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_propKsimp1},
    {"assert_formproc",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_formproc},
    {"liennewstruc",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_liennewstruc},
    {"groeb=crita",             CC_groebMcrita, TOO_MANY_1,    WRONG_NO_1},
    {"difbf",                   TOO_FEW_2,      CC_difbf,      WRONG_NO_2},
    {"ra_qmk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_qmk},
    {"lalr_get_lex_codes",      CC_lalr_get_lex_codes,TOO_MANY_1,WRONG_NO_1},
    {"polynomcompare",          TOO_FEW_2,      CC_polynomcompare,WRONG_NO_2},
    {"mk+real+inner+product",   TOO_FEW_2,      CC_mkLrealLinnerLproduct,WRONG_NO_2},
    {NULL, (one_args *)"u37", (two_args *)"30380 9655246 7911839", 0}
};

// end of generated code
