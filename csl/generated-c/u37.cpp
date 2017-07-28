
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



// Code for internal!-factorf

static LispObject CC_internalKfactorf(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21444, v_21445;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_21158;
// end of prologue
    v_21444 = qvalue(elt(env, 1)); // current!-modulus
// Binding current!-modulus
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = v_21444; // current!-modulus
// Binding m!-image!-variable
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=7
{   bind_fluid_stack bind_fluid_var(-10, 2, -7);
    qvalue(elt(env, 2)) = nil; // m!-image!-variable
    stack[-6] = nil;
    v_21444 = stack[-8];
    if (!consp(v_21444)) goto v_21177;
    else goto v_21178;
v_21177:
    v_21444 = lisp_true;
    goto v_21176;
v_21178:
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    v_21444 = (consp(v_21444) ? nil : lisp_true);
    goto v_21176;
    v_21444 = nil;
v_21176:
    if (v_21444 == nil) goto v_21174;
    v_21444 = stack[-8];
    v_21444 = ncons(v_21444);
    goto v_21170;
v_21174:
    goto v_21193;
v_21189:
    v_21445 = stack[-8];
    goto v_21190;
v_21191:
    v_21444 = nil;
    goto v_21192;
v_21193:
    goto v_21189;
v_21190:
    goto v_21191;
v_21192:
    fn = elt(env, 4); // kernord
    v_21444 = (*qfn2(fn))(fn, v_21445, v_21444);
    env = stack[-10];
    v_21445 = v_21444;
    v_21444 = qvalue(elt(env, 3)); // !*kernreverse
    if (v_21444 == nil) goto v_21199;
    v_21444 = v_21445;
    v_21444 = Lreverse(nil, v_21444);
    env = stack[-10];
    v_21445 = v_21444;
    goto v_21197;
v_21199:
v_21197:
    v_21444 = v_21445;
    fn = elt(env, 5); // setkorder
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-3] = v_21444;
    v_21444 = stack[-8];
    fn = elt(env, 6); // reorder
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-8] = v_21444;
    v_21444 = stack[-8];
    fn = elt(env, 7); // minusf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    if (v_21444 == nil) goto v_21210;
    v_21444 = stack[-6];
    v_21444 = (v_21444 == nil ? lisp_true : nil);
    stack[-6] = v_21444;
    v_21444 = stack[-8];
    fn = elt(env, 8); // negf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-8] = v_21444;
    goto v_21208;
v_21210:
v_21208:
    v_21444 = stack[-8];
    fn = elt(env, 9); // comfac
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-2] = v_21444;
    goto v_21224;
v_21220:
    stack[0] = stack[-8];
    goto v_21221;
v_21222:
    v_21444 = stack[-2];
    fn = elt(env, 10); // comfac!-to!-poly
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    goto v_21223;
v_21224:
    goto v_21220;
v_21221:
    goto v_21222;
v_21223:
    fn = elt(env, 11); // quotf1
    v_21444 = (*qfn2(fn))(fn, stack[0], v_21444);
    env = stack[-10];
    stack[-8] = v_21444;
    v_21444 = stack[-8];
    if (!consp(v_21444)) goto v_21234;
    else goto v_21235;
v_21234:
    v_21444 = lisp_true;
    goto v_21233;
v_21235:
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    v_21444 = (consp(v_21444) ? nil : lisp_true);
    goto v_21233;
    v_21444 = nil;
v_21233:
    if (v_21444 == nil) goto v_21231;
    v_21444 = stack[-8];
    stack[-5] = v_21444;
    v_21444 = nil;
    stack[-8] = v_21444;
    goto v_21229;
v_21231:
    v_21444 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21444;
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    v_21444 = qcar(v_21444);
    v_21444 = qcar(v_21444);
    qvalue(elt(env, 2)) = v_21444; // m!-image!-variable
    goto v_21257;
v_21253:
    v_21444 = stack[-8];
    fn = elt(env, 12); // factorize!-primitive!-polynomial
    v_21445 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    goto v_21254;
v_21255:
    v_21444 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21256;
v_21257:
    goto v_21253;
v_21254:
    goto v_21255;
v_21256:
    fn = elt(env, 13); // distribute!.multiplicity
    v_21444 = (*qfn2(fn))(fn, v_21445, v_21444);
    env = stack[-10];
    stack[-8] = v_21444;
    goto v_21229;
v_21229:
    v_21444 = stack[-2];
    v_21444 = qcar(v_21444);
    stack[-1] = v_21444;
    v_21444 = stack[-2];
    v_21444 = qcdr(v_21444);
    fn = elt(env, 14); // fctrf1
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-2] = v_21444;
    v_21444 = stack[-1];
    if (v_21444 == nil) goto v_21269;
    goto v_21278;
v_21272:
    v_21444 = stack[-2];
    stack[0] = qcar(v_21444);
    goto v_21273;
v_21274:
    goto v_21286;
v_21282:
    goto v_21293;
v_21289:
    goto v_21299;
v_21295:
    v_21444 = stack[-1];
    v_21445 = qcar(v_21444);
    goto v_21296;
v_21297:
    v_21444 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21298;
v_21299:
    goto v_21295;
v_21296:
    goto v_21297;
v_21298:
    fn = elt(env, 15); // to
    v_21445 = (*qfn2(fn))(fn, v_21445, v_21444);
    env = stack[-10];
    goto v_21290;
v_21291:
    v_21444 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21292;
v_21293:
    goto v_21289;
v_21290:
    goto v_21291;
v_21292:
    v_21444 = cons(v_21445, v_21444);
    env = stack[-10];
    v_21445 = ncons(v_21444);
    env = stack[-10];
    goto v_21283;
v_21284:
    v_21444 = stack[-1];
    v_21444 = qcdr(v_21444);
    goto v_21285;
v_21286:
    goto v_21282;
v_21283:
    goto v_21284;
v_21285:
    v_21445 = cons(v_21445, v_21444);
    env = stack[-10];
    goto v_21275;
v_21276:
    v_21444 = stack[-2];
    v_21444 = qcdr(v_21444);
    goto v_21277;
v_21278:
    goto v_21272;
v_21273:
    goto v_21274;
v_21275:
    goto v_21276;
v_21277:
    v_21444 = list2star(stack[0], v_21445, v_21444);
    env = stack[-10];
    stack[-2] = v_21444;
    goto v_21267;
v_21269:
v_21267:
    v_21444 = stack[-6];
    if (v_21444 == nil) goto v_21311;
    v_21444 = stack[-5];
    fn = elt(env, 8); // negf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-5] = v_21444;
    goto v_21309;
v_21311:
v_21309:
    goto v_21320;
v_21316:
    stack[0] = stack[-2];
    goto v_21317;
v_21318:
    goto v_21327;
v_21323:
    v_21445 = stack[-5];
    goto v_21324;
v_21325:
    v_21444 = stack[-8];
    goto v_21326;
v_21327:
    goto v_21323;
v_21324:
    goto v_21325;
v_21326:
    v_21444 = cons(v_21445, v_21444);
    env = stack[-10];
    goto v_21319;
v_21320:
    goto v_21316;
v_21317:
    goto v_21318;
v_21319:
    fn = elt(env, 16); // fac!-merge
    v_21444 = (*qfn2(fn))(fn, stack[0], v_21444);
    env = stack[-10];
    stack[-8] = v_21444;
    v_21444 = stack[-3];
    fn = elt(env, 5); // setkorder
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    v_21444 = stack[-8];
    v_21444 = qcdr(v_21444);
    stack[-4] = v_21444;
    v_21444 = stack[-4];
    if (v_21444 == nil) goto v_21342;
    else goto v_21343;
v_21342:
    v_21444 = nil;
    goto v_21336;
v_21343:
    v_21444 = stack[-4];
    v_21444 = qcar(v_21444);
    stack[0] = v_21444;
    goto v_21355;
v_21351:
    v_21444 = stack[0];
    v_21444 = qcar(v_21444);
    fn = elt(env, 6); // reorder
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-5] = v_21444;
    fn = elt(env, 7); // minusf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    if (v_21444 == nil) goto v_21359;
    v_21444 = stack[-6];
    v_21444 = (v_21444 == nil ? lisp_true : nil);
    stack[-6] = v_21444;
    v_21444 = stack[-5];
    fn = elt(env, 8); // negf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    v_21445 = v_21444;
    goto v_21357;
v_21359:
    v_21444 = stack[-5];
    v_21445 = v_21444;
    goto v_21357;
    v_21445 = nil;
v_21357:
    goto v_21352;
v_21353:
    v_21444 = stack[0];
    v_21444 = qcdr(v_21444);
    goto v_21354;
v_21355:
    goto v_21351;
v_21352:
    goto v_21353;
v_21354:
    v_21444 = cons(v_21445, v_21444);
    env = stack[-10];
    v_21444 = ncons(v_21444);
    env = stack[-10];
    stack[-2] = v_21444;
    stack[-3] = v_21444;
v_21337:
    v_21444 = stack[-4];
    v_21444 = qcdr(v_21444);
    stack[-4] = v_21444;
    v_21444 = stack[-4];
    if (v_21444 == nil) goto v_21377;
    else goto v_21378;
v_21377:
    v_21444 = stack[-3];
    goto v_21336;
v_21378:
    goto v_21386;
v_21382:
    stack[-1] = stack[-2];
    goto v_21383;
v_21384:
    v_21444 = stack[-4];
    v_21444 = qcar(v_21444);
    stack[0] = v_21444;
    goto v_21397;
v_21393:
    v_21444 = stack[0];
    v_21444 = qcar(v_21444);
    fn = elt(env, 6); // reorder
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    stack[-5] = v_21444;
    fn = elt(env, 7); // minusf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    if (v_21444 == nil) goto v_21401;
    v_21444 = stack[-6];
    v_21444 = (v_21444 == nil ? lisp_true : nil);
    stack[-6] = v_21444;
    v_21444 = stack[-5];
    fn = elt(env, 8); // negf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    v_21445 = v_21444;
    goto v_21399;
v_21401:
    v_21444 = stack[-5];
    v_21445 = v_21444;
    goto v_21399;
    v_21445 = nil;
v_21399:
    goto v_21394;
v_21395:
    v_21444 = stack[0];
    v_21444 = qcdr(v_21444);
    goto v_21396;
v_21397:
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    v_21444 = cons(v_21445, v_21444);
    env = stack[-10];
    v_21444 = ncons(v_21444);
    env = stack[-10];
    goto v_21385;
v_21386:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    v_21444 = Lrplacd(nil, stack[-1], v_21444);
    env = stack[-10];
    v_21444 = stack[-2];
    v_21444 = qcdr(v_21444);
    stack[-2] = v_21444;
    goto v_21337;
v_21336:
    stack[-2] = v_21444;
    goto v_21422;
v_21418:
    goto v_21431;
v_21427:
    stack[0] = stack[-6];
    goto v_21428;
v_21429:
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    fn = elt(env, 7); // minusf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    goto v_21430;
v_21431:
    goto v_21427;
v_21428:
    goto v_21429;
v_21430:
    if (equal(stack[0], v_21444)) goto v_21426;
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    fn = elt(env, 8); // negf
    v_21444 = (*qfn1(fn))(fn, v_21444);
    env = stack[-10];
    v_21445 = v_21444;
    goto v_21424;
v_21426:
    v_21444 = stack[-8];
    v_21444 = qcar(v_21444);
    v_21445 = v_21444;
    goto v_21424;
    v_21445 = nil;
v_21424:
    goto v_21419;
v_21420:
    v_21444 = stack[-2];
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    v_21444 = cons(v_21445, v_21444);
v_21170:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21444);
}



// Code for ioto_smaprinbuf

static LispObject CC_ioto_smaprinbuf(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21178, v_21179;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
    goto v_21165;
v_21161:
    v_21179 = elt(env, 1); // !!
    goto v_21162;
v_21163:
    v_21178 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21164;
v_21165:
    goto v_21161;
v_21162:
    goto v_21163;
v_21164:
    v_21178 = cons(v_21179, v_21178);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21178; // rlsmaprinbuf!*
    goto v_21174;
v_21170:
    v_21179 = stack[0];
    goto v_21171;
v_21172:
    v_21178 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21173;
v_21174:
    goto v_21170;
v_21171:
    goto v_21172;
v_21173:
    v_21178 = cons(v_21179, v_21178);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21178; // rlsmaprinbuf!*
    v_21178 = stack[0];
    return onevalue(v_21178);
}



// Code for setfuncsnaryrd

static LispObject CC_setfuncsnaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21211, v_21212;
    LispObject fn;
    argcheck(nargs, 0, "setfuncsnaryrd");
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
    fn = elt(env, 3); // mathml
    v_21211 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21211;
    v_21211 = stack[0];
    v_21211 = Lconsp(nil, v_21211);
    env = stack[-1];
    if (v_21211 == nil) goto v_21166;
    v_21211 = stack[0];
    v_21211 = qcdr(v_21211);
    v_21211 = qcar(v_21211);
    if (v_21211 == nil) goto v_21172;
    goto v_21184;
v_21180:
    v_21211 = stack[0];
    v_21211 = qcdr(v_21211);
    v_21211 = qcar(v_21211);
    v_21211 = qcar(v_21211);
    v_21211 = qcdr(v_21211);
    v_21211 = qcar(v_21211);
    v_21212 = Lintern(nil, v_21211);
    env = stack[-1];
    goto v_21181;
v_21182:
    v_21211 = elt(env, 1); // multiset
    goto v_21183;
v_21184:
    goto v_21180;
v_21181:
    goto v_21182;
v_21183:
    if (v_21212 == v_21211) goto v_21178;
    else goto v_21179;
v_21178:
    v_21211 = elt(env, 1); // multiset
    qvalue(elt(env, 2)) = v_21211; // mmlatts
    goto v_21177;
v_21179:
v_21177:
    goto v_21170;
v_21172:
v_21170:
    goto v_21164;
v_21166:
v_21164:
    v_21211 = stack[0];
    if (v_21211 == nil) goto v_21197;
    else goto v_21198;
v_21197:
    v_21211 = nil;
    goto v_21196;
v_21198:
    goto v_21208;
v_21204:
    goto v_21205;
v_21206:
    v_21211 = CC_setfuncsnaryrd(elt(env, 0), 0);
    goto v_21207;
v_21208:
    goto v_21204;
v_21205:
    goto v_21206;
v_21207:
    {
        LispObject v_21214 = stack[0];
        return cons(v_21214, v_21211);
    }
    v_21211 = nil;
v_21196:
    return onevalue(v_21211);
}



// Code for rewrite

static LispObject CC_rewrite(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21556, v_21557, v_21558;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-4] = v_21158;
// end of prologue
    v_21556 = elt(env, 1); // list
    v_21556 = ncons(v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-9] = v_21556;
    goto v_21179;
v_21173:
    v_21558 = elt(env, 2); // part
    goto v_21174;
v_21175:
    v_21557 = stack[-4];
    goto v_21176;
v_21177:
    v_21556 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21178;
v_21179:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-8] = v_21556;
    goto v_21190;
v_21184:
    goto v_21197;
v_21193:
    v_21557 = elt(env, 3); // length
    goto v_21194;
v_21195:
    v_21556 = stack[-8];
    goto v_21196;
v_21197:
    goto v_21193;
v_21194:
    goto v_21195;
v_21196:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21558 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21185;
v_21186:
    v_21557 = nil;
    goto v_21187;
v_21188:
    v_21556 = elt(env, 4); // only
    goto v_21189;
v_21190:
    goto v_21184;
v_21185:
    goto v_21186;
v_21187:
    goto v_21188;
v_21189:
    fn = elt(env, 24); // assgnpri
    v_21556 = (*qfnn(fn))(fn, 3, v_21558, v_21557, v_21556);
    env = stack[-10];
    v_21556 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21556;
v_21205:
    goto v_21219;
v_21213:
    stack[0] = elt(env, 5); // difference
    goto v_21214;
v_21215:
    goto v_21227;
v_21223:
    v_21557 = elt(env, 6); // arglength
    goto v_21224;
v_21225:
    v_21556 = stack[-4];
    goto v_21226;
v_21227:
    goto v_21223;
v_21224:
    goto v_21225;
v_21226:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21557 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21216;
v_21217:
    v_21556 = stack[-5];
    goto v_21218;
v_21219:
    goto v_21213;
v_21214:
    goto v_21215;
v_21216:
    goto v_21217;
v_21218:
    v_21556 = list3(stack[0], v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 26); // aminusp!:
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    if (v_21556 == nil) goto v_21210;
    goto v_21204;
v_21210:
    goto v_21240;
v_21234:
    stack[-3] = elt(env, 7); // plus
    goto v_21235;
v_21236:
    goto v_21247;
v_21243:
    stack[-1] = elt(env, 3); // length
    goto v_21244;
v_21245:
    goto v_21254;
v_21250:
    stack[0] = elt(env, 8); // den
    goto v_21251;
v_21252:
    goto v_21263;
v_21257:
    v_21558 = elt(env, 2); // part
    goto v_21258;
v_21259:
    v_21557 = stack[-4];
    goto v_21260;
v_21261:
    v_21556 = stack[-5];
    goto v_21262;
v_21263:
    goto v_21257;
v_21258:
    goto v_21259;
v_21260:
    goto v_21261;
v_21262:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    goto v_21253;
v_21254:
    goto v_21250;
v_21251:
    goto v_21252;
v_21253:
    v_21556 = list2(stack[0], v_21556);
    env = stack[-10];
    goto v_21246;
v_21247:
    goto v_21243;
v_21244:
    goto v_21245;
v_21246:
    stack[-2] = list2(stack[-1], v_21556);
    env = stack[-10];
    goto v_21237;
v_21238:
    goto v_21272;
v_21268:
    stack[-1] = elt(env, 3); // length
    goto v_21269;
v_21270:
    goto v_21279;
v_21275:
    stack[0] = elt(env, 9); // num
    goto v_21276;
v_21277:
    goto v_21288;
v_21282:
    v_21558 = elt(env, 2); // part
    goto v_21283;
v_21284:
    v_21557 = stack[-4];
    goto v_21285;
v_21286:
    v_21556 = stack[-5];
    goto v_21287;
v_21288:
    goto v_21282;
v_21283:
    goto v_21284;
v_21285:
    goto v_21286;
v_21287:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    goto v_21278;
v_21279:
    goto v_21275;
v_21276:
    goto v_21277;
v_21278:
    v_21556 = list2(stack[0], v_21556);
    env = stack[-10];
    goto v_21271;
v_21272:
    goto v_21268;
v_21269:
    goto v_21270;
v_21271:
    v_21556 = list2(stack[-1], v_21556);
    env = stack[-10];
    goto v_21239;
v_21240:
    goto v_21234;
v_21235:
    goto v_21236;
v_21237:
    goto v_21238;
v_21239:
    v_21556 = list3(stack[-3], stack[-2], v_21556);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[0] = v_21556;
    goto v_21299;
v_21293:
    v_21556 = stack[0];
    fn = elt(env, 25); // aeval!*
    v_21558 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21294;
v_21295:
    v_21557 = nil;
    goto v_21296;
v_21297:
    v_21556 = elt(env, 4); // only
    goto v_21298;
v_21299:
    goto v_21293;
v_21294:
    goto v_21295;
v_21296:
    goto v_21297;
v_21298:
    fn = elt(env, 24); // assgnpri
    v_21556 = (*qfnn(fn))(fn, 3, v_21558, v_21557, v_21556);
    env = stack[-10];
    goto v_21313;
v_21309:
    v_21556 = stack[0];
    fn = elt(env, 25); // aeval!*
    stack[-3] = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21310;
v_21311:
    goto v_21324;
v_21318:
    stack[-2] = elt(env, 7); // plus
    goto v_21319;
v_21320:
    goto v_21331;
v_21327:
    stack[0] = elt(env, 3); // length
    goto v_21328;
v_21329:
    goto v_21338;
v_21334:
    v_21557 = elt(env, 8); // den
    goto v_21335;
v_21336:
    v_21556 = stack[-8];
    goto v_21337;
v_21338:
    goto v_21334;
v_21335:
    goto v_21336;
v_21337:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21330;
v_21331:
    goto v_21327;
v_21328:
    goto v_21329;
v_21330:
    stack[-1] = list2(stack[0], v_21556);
    env = stack[-10];
    goto v_21321;
v_21322:
    goto v_21346;
v_21342:
    stack[0] = elt(env, 3); // length
    goto v_21343;
v_21344:
    goto v_21353;
v_21349:
    v_21557 = elt(env, 9); // num
    goto v_21350;
v_21351:
    v_21556 = stack[-8];
    goto v_21352;
v_21353:
    goto v_21349;
v_21350:
    goto v_21351;
v_21352:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21345;
v_21346:
    goto v_21342;
v_21343:
    goto v_21344;
v_21345:
    v_21556 = list2(stack[0], v_21556);
    env = stack[-10];
    goto v_21323;
v_21324:
    goto v_21318;
v_21319:
    goto v_21320;
v_21321:
    goto v_21322;
v_21323:
    v_21556 = list3(stack[-2], stack[-1], v_21556);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21312;
v_21313:
    goto v_21309;
v_21310:
    goto v_21311;
v_21312:
    fn = elt(env, 27); // evallessp
    v_21556 = (*qfn2(fn))(fn, stack[-3], v_21556);
    env = stack[-10];
    if (v_21556 == nil) goto v_21307;
    goto v_21364;
v_21358:
    v_21558 = elt(env, 2); // part
    goto v_21359;
v_21360:
    v_21557 = stack[-4];
    goto v_21361;
v_21362:
    v_21556 = stack[-5];
    goto v_21363;
v_21364:
    goto v_21358;
v_21359:
    goto v_21360;
v_21361:
    goto v_21362;
v_21363:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-8] = v_21556;
    goto v_21305;
v_21307:
v_21305:
    v_21556 = nil;
    fn = elt(env, 25); // aeval!*
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    v_21556 = stack[-5];
    goto v_21380;
v_21374:
    v_21558 = elt(env, 7); // plus
    goto v_21375;
v_21376:
    v_21557 = v_21556;
    goto v_21377;
v_21378:
    v_21556 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21379;
v_21380:
    goto v_21374;
v_21375:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-5] = v_21556;
    goto v_21205;
v_21204:
    goto v_21391;
v_21385:
    v_21556 = elt(env, 10); // "g is "
    fn = elt(env, 23); // aeval
    v_21558 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21386;
v_21387:
    v_21557 = nil;
    goto v_21388;
v_21389:
    v_21556 = elt(env, 11); // first
    goto v_21390;
v_21391:
    goto v_21385;
v_21386:
    goto v_21387;
v_21388:
    goto v_21389;
v_21390:
    fn = elt(env, 24); // assgnpri
    v_21556 = (*qfnn(fn))(fn, 3, v_21558, v_21557, v_21556);
    env = stack[-10];
    goto v_21403;
v_21397:
    v_21556 = stack[-8];
    fn = elt(env, 23); // aeval
    v_21558 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21398;
v_21399:
    v_21557 = nil;
    goto v_21400;
v_21401:
    v_21556 = elt(env, 12); // last
    goto v_21402;
v_21403:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    fn = elt(env, 24); // assgnpri
    v_21556 = (*qfnn(fn))(fn, 3, v_21558, v_21557, v_21556);
    env = stack[-10];
    v_21556 = stack[-4];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    fn = elt(env, 28); // getrlist
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-6] = v_21556;
v_21411:
    v_21556 = stack[-6];
    if (v_21556 == nil) goto v_21417;
    else goto v_21418;
v_21417:
    goto v_21410;
v_21418:
    v_21556 = stack[-6];
    v_21556 = qcar(v_21556);
    stack[0] = v_21556;
    goto v_21434;
v_21426:
    stack[-3] = elt(env, 13); // limit
    goto v_21427;
v_21428:
    goto v_21443;
v_21437:
    stack[-2] = elt(env, 14); // quotient
    goto v_21438;
v_21439:
    goto v_21450;
v_21446:
    v_21557 = elt(env, 15); // log
    goto v_21447;
v_21448:
    v_21556 = stack[0];
    goto v_21449;
v_21450:
    goto v_21446;
v_21447:
    goto v_21448;
v_21449:
    stack[-1] = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21440;
v_21441:
    goto v_21458;
v_21454:
    v_21557 = elt(env, 15); // log
    goto v_21455;
v_21456:
    v_21556 = stack[-8];
    goto v_21457;
v_21458:
    goto v_21454;
v_21455:
    goto v_21456;
v_21457:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21442;
v_21443:
    goto v_21437;
v_21438:
    goto v_21439;
v_21440:
    goto v_21441;
v_21442:
    v_21558 = list3(stack[-2], stack[-1], v_21556);
    env = stack[-10];
    goto v_21429;
v_21430:
    v_21557 = elt(env, 16); // x
    goto v_21431;
v_21432:
    v_21556 = elt(env, 17); // infinity
    goto v_21433;
v_21434:
    goto v_21426;
v_21427:
    goto v_21428;
v_21429:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    v_21556 = list4(stack[-3], v_21558, v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-7] = v_21556;
    goto v_21471;
v_21465:
    stack[-5] = elt(env, 18); // expt
    goto v_21466;
v_21467:
    stack[-4] = elt(env, 19); // e
    goto v_21468;
v_21469:
    goto v_21481;
v_21475:
    stack[-3] = elt(env, 5); // difference
    goto v_21476;
v_21477:
    goto v_21488;
v_21484:
    v_21557 = elt(env, 15); // log
    goto v_21485;
v_21486:
    v_21556 = stack[0];
    goto v_21487;
v_21488:
    goto v_21484;
v_21485:
    goto v_21486;
v_21487:
    stack[-2] = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21478;
v_21479:
    goto v_21498;
v_21492:
    stack[-1] = elt(env, 20); // times
    goto v_21493;
v_21494:
    stack[0] = stack[-7];
    goto v_21495;
v_21496:
    goto v_21506;
v_21502:
    v_21557 = elt(env, 15); // log
    goto v_21503;
v_21504:
    v_21556 = stack[-8];
    goto v_21505;
v_21506:
    goto v_21502;
v_21503:
    goto v_21504;
v_21505:
    v_21556 = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21497;
v_21498:
    goto v_21492;
v_21493:
    goto v_21494;
v_21495:
    goto v_21496;
v_21497:
    v_21556 = list3(stack[-1], stack[0], v_21556);
    env = stack[-10];
    goto v_21480;
v_21481:
    goto v_21475;
v_21476:
    goto v_21477;
v_21478:
    goto v_21479;
v_21480:
    v_21556 = list3(stack[-3], stack[-2], v_21556);
    env = stack[-10];
    goto v_21470;
v_21471:
    goto v_21465;
v_21466:
    goto v_21467;
v_21468:
    goto v_21469;
v_21470:
    v_21556 = list3(stack[-5], stack[-4], v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    goto v_21517;
v_21511:
    stack[-1] = elt(env, 20); // times
    goto v_21512;
v_21513:
    stack[0] = v_21556;
    goto v_21514;
v_21515:
    goto v_21527;
v_21521:
    v_21558 = elt(env, 18); // expt
    goto v_21522;
v_21523:
    v_21557 = elt(env, 21); // w
    goto v_21524;
v_21525:
    v_21556 = stack[-7];
    goto v_21526;
v_21527:
    goto v_21521;
v_21522:
    goto v_21523;
v_21524:
    goto v_21525;
v_21526:
    v_21556 = list3(v_21558, v_21557, v_21556);
    env = stack[-10];
    goto v_21516;
v_21517:
    goto v_21511;
v_21512:
    goto v_21513;
v_21514:
    goto v_21515;
v_21516:
    v_21556 = list3(stack[-1], stack[0], v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[0] = v_21556;
    goto v_21539;
v_21533:
    stack[-1] = elt(env, 22); // append
    goto v_21534;
v_21535:
    goto v_21546;
v_21542:
    v_21557 = elt(env, 1); // list
    goto v_21543;
v_21544:
    v_21556 = stack[0];
    goto v_21545;
v_21546:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    v_21557 = list2(v_21557, v_21556);
    env = stack[-10];
    goto v_21536;
v_21537:
    v_21556 = stack[-9];
    goto v_21538;
v_21539:
    goto v_21533;
v_21534:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    v_21556 = list3(stack[-1], v_21557, v_21556);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    stack[-9] = v_21556;
    v_21556 = nil;
    fn = elt(env, 23); // aeval
    v_21556 = (*qfn1(fn))(fn, v_21556);
    env = stack[-10];
    v_21556 = stack[-6];
    v_21556 = qcdr(v_21556);
    stack[-6] = v_21556;
    goto v_21411;
v_21410:
    v_21556 = stack[-9];
    {
        fn = elt(env, 23); // aeval
        return (*qfn1(fn))(fn, v_21556);
    }
    return onevalue(v_21556);
}



// Code for evalnumberp

static LispObject CC_evalnumberp(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21218, v_21219, v_21220;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21218 = v_21158;
// end of prologue
    fn = elt(env, 3); // aeval
    v_21218 = (*qfn1(fn))(fn, v_21218);
    env = stack[0];
    v_21220 = v_21218;
    v_21218 = v_21220;
    if (!consp(v_21218)) goto v_21165;
    else goto v_21166;
v_21165:
    v_21218 = v_21220;
    v_21218 = (is_number(v_21218) ? lisp_true : nil);
    goto v_21164;
v_21166:
    goto v_21180;
v_21176:
    v_21218 = v_21220;
    v_21219 = qcar(v_21218);
    goto v_21177;
v_21178:
    v_21218 = elt(env, 1); // !*sq
    goto v_21179;
v_21180:
    goto v_21176;
v_21177:
    goto v_21178;
v_21179:
    if (v_21219 == v_21218) goto v_21175;
    v_21218 = lisp_true;
    goto v_21173;
v_21175:
    v_21218 = v_21220;
    v_21218 = qcdr(v_21218);
    v_21218 = qcar(v_21218);
    v_21218 = qcdr(v_21218);
    v_21218 = (consp(v_21218) ? nil : lisp_true);
    v_21218 = (v_21218 == nil ? lisp_true : nil);
    goto v_21173;
    v_21218 = nil;
v_21173:
    if (v_21218 == nil) goto v_21171;
    v_21218 = nil;
    goto v_21164;
v_21171:
    v_21218 = v_21220;
    v_21218 = qcdr(v_21218);
    v_21218 = qcar(v_21218);
    v_21218 = qcar(v_21218);
    v_21219 = v_21218;
    v_21218 = v_21219;
    if (!consp(v_21218)) goto v_21203;
    else goto v_21204;
v_21203:
    v_21218 = lisp_true;
    goto v_21202;
v_21204:
    goto v_21214;
v_21210:
    v_21218 = v_21219;
    v_21218 = qcar(v_21218);
    goto v_21211;
v_21212:
    v_21219 = elt(env, 2); // numbertag
    goto v_21213;
v_21214:
    goto v_21210;
v_21211:
    goto v_21212;
v_21213:
        return Lflagp(nil, v_21218, v_21219);
    v_21218 = nil;
v_21202:
    goto v_21164;
    v_21218 = nil;
v_21164:
    return onevalue(v_21218);
}



// Code for contposp

static LispObject CC_contposp(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21180, v_21181;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21180 = v_21158;
// end of prologue
v_21157:
    v_21181 = v_21180;
    if (v_21181 == nil) goto v_21162;
    else goto v_21163;
v_21162:
    v_21180 = lisp_true;
    goto v_21161;
v_21163:
    v_21181 = v_21180;
    v_21181 = qcar(v_21181);
    if (!consp(v_21181)) goto v_21170;
    else goto v_21171;
v_21170:
    v_21180 = qcdr(v_21180);
    goto v_21157;
v_21171:
    v_21180 = nil;
    goto v_21169;
    v_21180 = nil;
v_21169:
    goto v_21161;
    v_21180 = nil;
v_21161:
    return onevalue(v_21180);
}



// Code for diff_vertex

static LispObject CC_diff_vertex(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21211, v_21212, v_21213;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
    v_21213 = nil;
v_21164:
    v_21211 = stack[-1];
    if (v_21211 == nil) goto v_21167;
    else goto v_21168;
v_21167:
    v_21211 = v_21213;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21211);
    }
v_21168:
    goto v_21179;
v_21175:
    v_21211 = stack[-1];
    v_21211 = qcar(v_21211);
    v_21212 = qcar(v_21211);
    goto v_21176;
v_21177:
    v_21211 = stack[0];
    goto v_21178;
v_21179:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    v_21211 = Lassoc(nil, v_21212, v_21211);
    if (v_21211 == nil) goto v_21173;
    goto v_21190;
v_21186:
    v_21211 = stack[-1];
    v_21211 = qcar(v_21211);
    v_21212 = qcar(v_21211);
    goto v_21187;
v_21188:
    v_21211 = qvalue(elt(env, 1)); // !_0edge
    v_21211 = qcar(v_21211);
    goto v_21189;
v_21190:
    goto v_21186;
v_21187:
    goto v_21188;
v_21189:
    if (v_21212 == v_21211) goto v_21173;
    v_21211 = stack[-1];
    v_21211 = qcdr(v_21211);
    stack[-1] = v_21211;
    goto v_21164;
v_21173:
    goto v_21205;
v_21201:
    v_21211 = stack[-1];
    v_21211 = qcar(v_21211);
    goto v_21202;
v_21203:
    v_21212 = v_21213;
    goto v_21204;
v_21205:
    goto v_21201;
v_21202:
    goto v_21203;
v_21204:
    v_21211 = cons(v_21211, v_21212);
    env = stack[-2];
    v_21213 = v_21211;
    v_21211 = stack[-1];
    v_21211 = qcdr(v_21211);
    stack[-1] = v_21211;
    goto v_21164;
    v_21211 = nil;
    return onevalue(v_21211);
}



// Code for dp_from_ei

static LispObject CC_dp_from_ei(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21171;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
    goto v_21166;
v_21162:
    v_21171 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // cali_bc_fi
    stack[-1] = (*qfn1(fn))(fn, v_21171);
    env = stack[-2];
    goto v_21163;
v_21164:
    v_21171 = stack[0];
    fn = elt(env, 2); // mo_from_ei
    v_21171 = (*qfn1(fn))(fn, v_21171);
    env = stack[-2];
    goto v_21165;
v_21166:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    fn = elt(env, 3); // dp_term
    v_21171 = (*qfn2(fn))(fn, stack[-1], v_21171);
    return ncons(v_21171);
}



// Code for getavalue

static LispObject CC_getavalue(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21174, v_21175;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21174 = v_21158;
// end of prologue
    if (!symbolp(v_21174)) v_21174 = nil;
    else { v_21174 = qfastgets(v_21174);
           if (v_21174 != nil) { v_21174 = elt(v_21174, 4); // avalue
#ifdef RECORD_GET
             if (v_21174 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21174 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21174 == SPID_NOPROP) v_21174 = nil; }}
#endif
    v_21175 = v_21174;
    v_21174 = v_21175;
    if (v_21174 == nil) goto v_21166;
    v_21174 = v_21175;
    v_21174 = qcdr(v_21174);
    v_21174 = qcar(v_21174);
    goto v_21164;
v_21166:
    v_21174 = nil;
    goto v_21164;
    v_21174 = nil;
v_21164:
    return onevalue(v_21174);
}



// Code for msolve!-psys1

static LispObject CC_msolveKpsys1(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21282, v_21283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_21159;
    stack[0] = v_21158;
// end of prologue
    v_21282 = nil;
    v_21282 = ncons(v_21282);
    env = stack[-7];
    v_21283 = v_21282;
    v_21282 = stack[0];
    stack[-4] = v_21282;
v_21172:
    v_21282 = stack[-4];
    if (v_21282 == nil) goto v_21176;
    else goto v_21177;
v_21176:
    goto v_21171;
v_21177:
    v_21282 = stack[-4];
    v_21282 = qcar(v_21282);
    stack[-3] = v_21282;
    v_21282 = nil;
    stack[-6] = v_21282;
    v_21282 = v_21283;
    stack[-2] = v_21282;
v_21187:
    v_21282 = stack[-2];
    if (v_21282 == nil) goto v_21191;
    else goto v_21192;
v_21191:
    goto v_21186;
v_21192:
    v_21282 = stack[-2];
    v_21282 = qcar(v_21282);
    stack[-1] = v_21282;
    goto v_21205;
v_21201:
    v_21283 = stack[-3];
    goto v_21202;
v_21203:
    v_21282 = stack[-1];
    goto v_21204;
v_21205:
    goto v_21201;
v_21202:
    goto v_21203;
v_21204:
    fn = elt(env, 1); // subf
    v_21282 = (*qfn2(fn))(fn, v_21283, v_21282);
    env = stack[-7];
    v_21282 = qcar(v_21282);
    fn = elt(env, 2); // moduntag
    v_21282 = (*qfn1(fn))(fn, v_21282);
    env = stack[-7];
    fn = elt(env, 3); // general!-reduce!-mod!-p
    v_21282 = (*qfn1(fn))(fn, v_21282);
    env = stack[-7];
    v_21283 = v_21282;
    v_21282 = v_21283;
    if (v_21282 == nil) goto v_21211;
    else goto v_21212;
v_21211:
    goto v_21219;
v_21215:
    v_21283 = stack[-1];
    goto v_21216;
v_21217:
    v_21282 = stack[-6];
    goto v_21218;
v_21219:
    goto v_21215;
v_21216:
    goto v_21217;
v_21218:
    v_21282 = cons(v_21283, v_21282);
    env = stack[-7];
    stack[-6] = v_21282;
    goto v_21210;
v_21212:
    v_21282 = v_21283;
    if (!consp(v_21282)) goto v_21226;
    else goto v_21227;
v_21226:
    v_21282 = lisp_true;
    goto v_21225;
v_21227:
    v_21282 = v_21283;
    v_21282 = qcar(v_21282);
    v_21282 = (consp(v_21282) ? nil : lisp_true);
    goto v_21225;
    v_21282 = nil;
v_21225:
    if (v_21282 == nil) goto v_21223;
    goto v_21210;
v_21223:
    goto v_21247;
v_21243:
    goto v_21244;
v_21245:
    v_21282 = stack[-5];
    goto v_21246;
v_21247:
    goto v_21243;
v_21244:
    goto v_21245;
v_21246:
    fn = elt(env, 4); // msolve!-poly
    v_21282 = (*qfn2(fn))(fn, v_21283, v_21282);
    env = stack[-7];
    stack[0] = v_21282;
v_21241:
    v_21282 = stack[0];
    if (v_21282 == nil) goto v_21252;
    else goto v_21253;
v_21252:
    goto v_21240;
v_21253:
    v_21282 = stack[0];
    v_21282 = qcar(v_21282);
    goto v_21264;
v_21260:
    goto v_21270;
v_21266:
    v_21283 = stack[-1];
    goto v_21267;
v_21268:
    goto v_21269;
v_21270:
    goto v_21266;
v_21267:
    goto v_21268;
v_21269:
    v_21283 = Lappend(nil, v_21283, v_21282);
    env = stack[-7];
    goto v_21261;
v_21262:
    v_21282 = stack[-6];
    goto v_21263;
v_21264:
    goto v_21260;
v_21261:
    goto v_21262;
v_21263:
    v_21282 = cons(v_21283, v_21282);
    env = stack[-7];
    stack[-6] = v_21282;
    v_21282 = stack[0];
    v_21282 = qcdr(v_21282);
    stack[0] = v_21282;
    goto v_21241;
v_21240:
    goto v_21210;
v_21210:
    v_21282 = stack[-2];
    v_21282 = qcdr(v_21282);
    stack[-2] = v_21282;
    goto v_21187;
v_21186:
    v_21282 = stack[-6];
    v_21283 = v_21282;
    v_21282 = stack[-4];
    v_21282 = qcdr(v_21282);
    stack[-4] = v_21282;
    goto v_21172;
v_21171:
    v_21282 = v_21283;
    return onevalue(v_21282);
}



// Code for lalr_expand_grammar

static LispObject CC_lalr_expand_grammar(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21193, v_21194;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21193 = v_21158;
// end of prologue
// Binding pending_rules!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // pending_rules!*
    fn = elt(env, 2); // lalr_check_grammar
    v_21193 = (*qfn1(fn))(fn, v_21193);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_21193; // pending_rules!*
    v_21193 = nil;
    stack[0] = v_21193;
v_21171:
    v_21193 = qvalue(elt(env, 1)); // pending_rules!*
    if (v_21193 == nil) goto v_21174;
    else goto v_21175;
v_21174:
    goto v_21170;
v_21175:
    v_21193 = qvalue(elt(env, 1)); // pending_rules!*
    v_21193 = qcar(v_21193);
    v_21194 = v_21193;
    v_21193 = qvalue(elt(env, 1)); // pending_rules!*
    v_21193 = qcdr(v_21193);
    qvalue(elt(env, 1)) = v_21193; // pending_rules!*
    goto v_21187;
v_21183:
    v_21193 = v_21194;
    fn = elt(env, 3); // expand_rule
    v_21194 = (*qfn1(fn))(fn, v_21193);
    env = stack[-2];
    goto v_21184;
v_21185:
    v_21193 = stack[0];
    goto v_21186;
v_21187:
    goto v_21183;
v_21184:
    goto v_21185;
v_21186:
    v_21193 = cons(v_21194, v_21193);
    env = stack[-2];
    stack[0] = v_21193;
    goto v_21171;
v_21170:
    v_21193 = stack[0];
    v_21193 = Lreverse(nil, v_21193);
    ;}  // end of a binding scope
    return onevalue(v_21193);
}



// Code for cl_atnum

static LispObject CC_cl_atnum(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21409, v_21410, v_21411;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
v_21157:
    v_21409 = stack[0];
    if (!consp(v_21409)) goto v_21166;
    else goto v_21167;
v_21166:
    v_21409 = stack[0];
    goto v_21165;
v_21167:
    v_21409 = stack[0];
    v_21409 = qcar(v_21409);
    goto v_21165;
    v_21409 = nil;
v_21165:
    v_21411 = v_21409;
    goto v_21194;
v_21190:
    v_21410 = v_21411;
    goto v_21191;
v_21192:
    v_21409 = elt(env, 1); // or
    goto v_21193;
v_21194:
    goto v_21190;
v_21191:
    goto v_21192;
v_21193:
    if (v_21410 == v_21409) goto v_21188;
    else goto v_21189;
v_21188:
    v_21409 = lisp_true;
    goto v_21187;
v_21189:
    goto v_21204;
v_21200:
    v_21410 = v_21411;
    goto v_21201;
v_21202:
    v_21409 = elt(env, 2); // and
    goto v_21203;
v_21204:
    goto v_21200;
v_21201:
    goto v_21202;
v_21203:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21187;
    v_21409 = nil;
v_21187:
    if (v_21409 == nil) goto v_21185;
    v_21409 = lisp_true;
    goto v_21183;
v_21185:
    goto v_21215;
v_21211:
    v_21410 = v_21411;
    goto v_21212;
v_21213:
    v_21409 = elt(env, 3); // not
    goto v_21214;
v_21215:
    goto v_21211;
v_21212:
    goto v_21213;
v_21214:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21183;
    v_21409 = nil;
v_21183:
    if (v_21409 == nil) goto v_21181;
    v_21409 = lisp_true;
    goto v_21179;
v_21181:
    goto v_21230;
v_21226:
    v_21410 = v_21411;
    goto v_21227;
v_21228:
    v_21409 = elt(env, 4); // impl
    goto v_21229;
v_21230:
    goto v_21226;
v_21227:
    goto v_21228;
v_21229:
    if (v_21410 == v_21409) goto v_21224;
    else goto v_21225;
v_21224:
    v_21409 = lisp_true;
    goto v_21223;
v_21225:
    goto v_21244;
v_21240:
    v_21410 = v_21411;
    goto v_21241;
v_21242:
    v_21409 = elt(env, 5); // repl
    goto v_21243;
v_21244:
    goto v_21240;
v_21241:
    goto v_21242;
v_21243:
    if (v_21410 == v_21409) goto v_21238;
    else goto v_21239;
v_21238:
    v_21409 = lisp_true;
    goto v_21237;
v_21239:
    goto v_21254;
v_21250:
    v_21410 = v_21411;
    goto v_21251;
v_21252:
    v_21409 = elt(env, 6); // equiv
    goto v_21253;
v_21254:
    goto v_21250;
v_21251:
    goto v_21252;
v_21253:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21237;
    v_21409 = nil;
v_21237:
    goto v_21223;
    v_21409 = nil;
v_21223:
    goto v_21179;
    v_21409 = nil;
v_21179:
    if (v_21409 == nil) goto v_21177;
    v_21409 = stack[0];
    v_21409 = qcdr(v_21409);
    stack[-1] = v_21409;
    v_21409 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21409;
v_21262:
    v_21409 = stack[-1];
    if (v_21409 == nil) goto v_21268;
    else goto v_21269;
v_21268:
    v_21409 = stack[0];
    goto v_21261;
v_21269:
    goto v_21277;
v_21273:
    v_21409 = stack[-1];
    v_21409 = qcar(v_21409);
    v_21410 = CC_cl_atnum(elt(env, 0), v_21409);
    env = stack[-2];
    goto v_21274;
v_21275:
    v_21409 = stack[0];
    goto v_21276;
v_21277:
    goto v_21273;
v_21274:
    goto v_21275;
v_21276:
    v_21409 = plus2(v_21410, v_21409);
    env = stack[-2];
    stack[0] = v_21409;
    v_21409 = stack[-1];
    v_21409 = qcdr(v_21409);
    stack[-1] = v_21409;
    goto v_21262;
v_21261:
    goto v_21163;
v_21177:
    goto v_21298;
v_21294:
    v_21410 = v_21411;
    goto v_21295;
v_21296:
    v_21409 = elt(env, 7); // ex
    goto v_21297;
v_21298:
    goto v_21294;
v_21295:
    goto v_21296;
v_21297:
    if (v_21410 == v_21409) goto v_21292;
    else goto v_21293;
v_21292:
    v_21409 = lisp_true;
    goto v_21291;
v_21293:
    goto v_21308;
v_21304:
    v_21410 = v_21411;
    goto v_21305;
v_21306:
    v_21409 = elt(env, 8); // all
    goto v_21307;
v_21308:
    goto v_21304;
v_21305:
    goto v_21306;
v_21307:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21291;
    v_21409 = nil;
v_21291:
    if (v_21409 == nil) goto v_21289;
    v_21409 = stack[0];
    v_21409 = qcdr(v_21409);
    v_21409 = qcdr(v_21409);
    v_21409 = qcar(v_21409);
    stack[0] = v_21409;
    goto v_21157;
v_21289:
    goto v_21329;
v_21325:
    v_21410 = v_21411;
    goto v_21326;
v_21327:
    v_21409 = elt(env, 9); // bex
    goto v_21328;
v_21329:
    goto v_21325;
v_21326:
    goto v_21327;
v_21328:
    if (v_21410 == v_21409) goto v_21323;
    else goto v_21324;
v_21323:
    v_21409 = lisp_true;
    goto v_21322;
v_21324:
    goto v_21339;
v_21335:
    v_21410 = v_21411;
    goto v_21336;
v_21337:
    v_21409 = elt(env, 10); // ball
    goto v_21338;
v_21339:
    goto v_21335;
v_21336:
    goto v_21337;
v_21338:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21322;
    v_21409 = nil;
v_21322:
    if (v_21409 == nil) goto v_21320;
    goto v_21348;
v_21344:
    v_21409 = stack[0];
    v_21409 = qcdr(v_21409);
    v_21409 = qcdr(v_21409);
    v_21409 = qcar(v_21409);
    stack[-1] = CC_cl_atnum(elt(env, 0), v_21409);
    env = stack[-2];
    goto v_21345;
v_21346:
    v_21409 = stack[0];
    v_21409 = qcdr(v_21409);
    v_21409 = qcdr(v_21409);
    v_21409 = qcdr(v_21409);
    v_21409 = qcar(v_21409);
    v_21409 = CC_cl_atnum(elt(env, 0), v_21409);
    goto v_21347;
v_21348:
    goto v_21344;
v_21345:
    goto v_21346;
v_21347:
    {
        LispObject v_21414 = stack[-1];
        return plus2(v_21414, v_21409);
    }
v_21320:
    goto v_21372;
v_21368:
    v_21410 = v_21411;
    goto v_21369;
v_21370:
    v_21409 = elt(env, 11); // true
    goto v_21371;
v_21372:
    goto v_21368;
v_21369:
    goto v_21370;
v_21371:
    if (v_21410 == v_21409) goto v_21366;
    else goto v_21367;
v_21366:
    v_21409 = lisp_true;
    goto v_21365;
v_21367:
    goto v_21382;
v_21378:
    v_21410 = v_21411;
    goto v_21379;
v_21380:
    v_21409 = elt(env, 12); // false
    goto v_21381;
v_21382:
    goto v_21378;
v_21379:
    goto v_21380;
v_21381:
    v_21409 = (v_21410 == v_21409 ? lisp_true : nil);
    goto v_21365;
    v_21409 = nil;
v_21365:
    if (v_21409 == nil) goto v_21363;
    v_21409 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21163;
v_21363:
    goto v_21396;
v_21392:
    v_21410 = v_21411;
    goto v_21393;
v_21394:
    v_21409 = elt(env, 0); // cl_atnum
    goto v_21395;
v_21396:
    goto v_21392;
v_21393:
    goto v_21394;
v_21395:
    fn = elt(env, 13); // rl_external
    v_21409 = (*qfn2(fn))(fn, v_21410, v_21409);
    env = stack[-2];
    v_21410 = v_21409;
    if (v_21409 == nil) goto v_21390;
    goto v_21404;
v_21400:
    stack[-1] = v_21410;
    goto v_21401;
v_21402:
    v_21409 = stack[0];
    v_21409 = ncons(v_21409);
    env = stack[-2];
    goto v_21403;
v_21404:
    goto v_21400;
v_21401:
    goto v_21402;
v_21403:
    {
        LispObject v_21415 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_21415, v_21409);
    }
v_21390:
    v_21409 = (LispObject)16+TAG_FIXNUM; // 1
v_21163:
    return onevalue(v_21409);
}



// Code for simpexpt1

static LispObject CC_simpexpt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21708, v_21709, v_21710;
    LispObject fn;
    LispObject v_21160, v_21159, v_21158;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt1");
    va_start(aa, nargs);
    v_21158 = va_arg(aa, LispObject);
    v_21159 = va_arg(aa, LispObject);
    v_21160 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21160,v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21158,v_21159,v_21160);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21160;
    stack[-5] = v_21159;
    stack[-6] = v_21158;
// end of prologue
// Binding !*allfac
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*allfac
// Binding !*div
// FLUIDBIND: reloadenv=8 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-8, 2, -3);
    qvalue(elt(env, 2)) = nil; // !*div
    v_21708 = stack[-6];
    v_21708 = Lonep(nil, v_21708);
    env = stack[-8];
    if (v_21708 == nil) goto v_21172;
    goto v_21180;
v_21176:
    v_21709 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21177;
v_21178:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21179;
v_21180:
    goto v_21176;
v_21177:
    goto v_21178;
v_21179:
    v_21708 = cons(v_21709, v_21708);
    goto v_21168;
v_21172:
    v_21708 = lisp_true;
    qvalue(elt(env, 1)) = v_21708; // !*allfac
    v_21708 = stack[-5];
    v_21708 = qcar(v_21708);
    stack[-2] = v_21708;
    goto v_21198;
v_21194:
    v_21709 = stack[-2];
    goto v_21195;
v_21196:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21197;
v_21198:
    goto v_21194;
v_21195:
    goto v_21196;
v_21197:
    if (v_21709 == v_21708) goto v_21192;
    else goto v_21193;
v_21192:
    goto v_21205;
v_21201:
    v_21708 = stack[-5];
    v_21709 = qcdr(v_21708);
    goto v_21202;
v_21203:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21204;
v_21205:
    goto v_21201;
v_21202:
    goto v_21203;
v_21204:
    v_21708 = (v_21709 == v_21708 ? lisp_true : nil);
    goto v_21191;
v_21193:
    v_21708 = nil;
    goto v_21191;
    v_21708 = nil;
v_21191:
    if (v_21708 == nil) goto v_21189;
    v_21708 = stack[-6];
    fn = elt(env, 10); // simp
    v_21708 = (*qfn1(fn))(fn, v_21708);
    goto v_21168;
v_21189:
    goto v_21227;
v_21223:
    v_21709 = stack[-6];
    goto v_21224;
v_21225:
    v_21708 = elt(env, 3); // e
    goto v_21226;
v_21227:
    goto v_21223;
v_21224:
    goto v_21225;
v_21226:
    if (v_21709 == v_21708) goto v_21221;
    else goto v_21222;
v_21221:
    v_21708 = stack[-5];
    v_21708 = qcdr(v_21708);
    if (!consp(v_21708)) goto v_21236;
    else goto v_21237;
v_21236:
    v_21708 = lisp_true;
    goto v_21235;
v_21237:
    v_21708 = stack[-5];
    v_21708 = qcdr(v_21708);
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21235;
    v_21708 = nil;
v_21235:
    if (v_21708 == nil) goto v_21233;
    v_21708 = stack[-2];
    if (!consp(v_21708)) goto v_21253;
    else goto v_21254;
v_21253:
    v_21708 = lisp_true;
    goto v_21252;
v_21254:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21252;
    v_21708 = nil;
v_21252:
    if (v_21708 == nil) goto v_21249;
    else goto v_21250;
v_21249:
    goto v_21270;
v_21266:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = qcar(v_21708);
    v_21709 = qcdr(v_21708);
    goto v_21267;
v_21268:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21269;
v_21270:
    goto v_21266;
v_21267:
    goto v_21268;
v_21269:
    if (v_21709 == v_21708) goto v_21264;
    else goto v_21265;
v_21264:
    v_21708 = stack[-2];
    v_21708 = qcdr(v_21708);
    if (v_21708 == nil) goto v_21278;
    else goto v_21279;
v_21278:
    goto v_21287;
v_21283:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = qcar(v_21708);
    v_21709 = qcar(v_21708);
    goto v_21284;
v_21285:
    v_21708 = elt(env, 4); // log
    goto v_21286;
v_21287:
    goto v_21283;
v_21284:
    goto v_21285;
v_21286:
    v_21708 = Leqcar(nil, v_21709, v_21708);
    env = stack[-8];
    goto v_21277;
v_21279:
    v_21708 = nil;
    goto v_21277;
    v_21708 = nil;
v_21277:
    goto v_21263;
v_21265:
    v_21708 = nil;
    goto v_21263;
    v_21708 = nil;
v_21263:
    goto v_21248;
v_21250:
    v_21708 = nil;
    goto v_21248;
    v_21708 = nil;
v_21248:
    goto v_21231;
v_21233:
    v_21708 = nil;
    goto v_21231;
    v_21708 = nil;
v_21231:
    goto v_21220;
v_21222:
    v_21708 = nil;
    goto v_21220;
    v_21708 = nil;
v_21220:
    if (v_21708 == nil) goto v_21218;
    goto v_21315;
v_21309:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = qcar(v_21708);
    v_21708 = qcar(v_21708);
    v_21708 = qcdr(v_21708);
    v_21708 = qcar(v_21708);
    fn = elt(env, 11); // simp!*
    v_21708 = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    stack[0] = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    goto v_21310;
v_21311:
    goto v_21329;
v_21325:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21709 = qcdr(v_21708);
    goto v_21326;
v_21327:
    v_21708 = stack[-5];
    v_21708 = qcdr(v_21708);
    goto v_21328;
v_21329:
    goto v_21325;
v_21326:
    goto v_21327;
v_21328:
    v_21709 = cons(v_21709, v_21708);
    env = stack[-8];
    goto v_21312;
v_21313:
    v_21708 = nil;
    goto v_21314;
v_21315:
    goto v_21309;
v_21310:
    goto v_21311;
v_21312:
    goto v_21313;
v_21314:
    v_21708 = CC_simpexpt1(elt(env, 0), 3, stack[0], v_21709, v_21708);
    goto v_21168;
v_21218:
    v_21708 = stack[-2];
    if (!consp(v_21708)) goto v_21346;
    else goto v_21347;
v_21346:
    v_21708 = lisp_true;
    goto v_21345;
v_21347:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21345;
    v_21708 = nil;
v_21345:
    if (v_21708 == nil) goto v_21342;
    else goto v_21343;
v_21342:
    v_21708 = lisp_true;
    goto v_21341;
v_21343:
    v_21708 = stack[-5];
    v_21708 = qcdr(v_21708);
    if (!consp(v_21708)) goto v_21360;
    else goto v_21361;
v_21360:
    v_21708 = lisp_true;
    goto v_21359;
v_21361:
    v_21708 = stack[-5];
    v_21708 = qcdr(v_21708);
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21359;
    v_21708 = nil;
v_21359:
    v_21708 = (v_21708 == nil ? lisp_true : nil);
    goto v_21341;
    v_21708 = nil;
v_21341:
    if (v_21708 == nil) goto v_21339;
    goto v_21379;
v_21373:
    v_21710 = stack[-6];
    goto v_21374;
v_21375:
    v_21709 = stack[-5];
    goto v_21376;
v_21377:
    v_21708 = stack[-4];
    goto v_21378;
v_21379:
    goto v_21373;
v_21374:
    goto v_21375;
v_21376:
    goto v_21377;
v_21378:
    fn = elt(env, 13); // simpexpt11
    v_21708 = (*qfnn(fn))(fn, 3, v_21710, v_21709, v_21708);
    goto v_21168;
v_21339:
    v_21708 = stack[-6];
    fn = elt(env, 10); // simp
    v_21708 = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    stack[-1] = v_21708;
    v_21708 = stack[-2];
    if (v_21708 == nil) goto v_21387;
    else goto v_21388;
v_21387:
    v_21708 = stack[-1];
    v_21708 = qcar(v_21708);
    if (v_21708 == nil) goto v_21392;
    else goto v_21393;
v_21392:
    goto v_21403;
v_21397:
    v_21710 = elt(env, 5); // alg
    goto v_21398;
v_21399:
    v_21709 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_21400;
v_21401:
    v_21708 = elt(env, 6); // "0**0 formed"
    goto v_21402;
v_21403:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    fn = elt(env, 14); // rerror
    v_21708 = (*qfnn(fn))(fn, 3, v_21710, v_21709, v_21708);
    goto v_21391;
v_21393:
    goto v_21414;
v_21410:
    v_21709 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21411;
v_21412:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    v_21708 = cons(v_21709, v_21708);
    goto v_21391;
    v_21708 = nil;
v_21391:
    goto v_21168;
v_21388:
    v_21708 = stack[-1];
    v_21708 = qcar(v_21708);
    if (v_21708 == nil) goto v_21419;
    else goto v_21420;
v_21419:
    v_21708 = stack[-2];
    if (!consp(v_21708)) goto v_21433;
    else goto v_21434;
v_21433:
    v_21708 = lisp_true;
    goto v_21432;
v_21434:
    v_21708 = stack[-2];
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21432;
    v_21708 = nil;
v_21432:
    if (v_21708 == nil) goto v_21430;
    v_21708 = stack[-2];
    fn = elt(env, 15); // minusf
    v_21708 = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    goto v_21428;
v_21430:
    v_21708 = nil;
    goto v_21428;
    v_21708 = nil;
v_21428:
    if (v_21708 == nil) goto v_21426;
    goto v_21454;
v_21448:
    v_21710 = elt(env, 5); // alg
    goto v_21449;
v_21450:
    v_21709 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_21451;
v_21452:
    v_21708 = elt(env, 7); // "Zero divisor"
    goto v_21453;
v_21454:
    goto v_21448;
v_21449:
    goto v_21450;
v_21451:
    goto v_21452;
v_21453:
    fn = elt(env, 14); // rerror
    v_21708 = (*qfnn(fn))(fn, 3, v_21710, v_21709, v_21708);
    goto v_21424;
v_21426:
    goto v_21465;
v_21461:
    v_21709 = nil;
    goto v_21462;
v_21463:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21464;
v_21465:
    goto v_21461;
v_21462:
    goto v_21463;
v_21464:
    v_21708 = cons(v_21709, v_21708);
    goto v_21424;
    v_21708 = nil;
v_21424:
    goto v_21418;
v_21420:
    v_21708 = stack[-2];
    if (!consp(v_21708)) goto v_21472;
    else goto v_21473;
v_21472:
    goto v_21483;
v_21479:
    v_21708 = stack[-5];
    v_21709 = qcdr(v_21708);
    goto v_21480;
v_21481:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21482;
v_21483:
    goto v_21479;
v_21480:
    goto v_21481;
v_21482:
    if (v_21709 == v_21708) goto v_21477;
    else goto v_21478;
v_21477:
    v_21708 = stack[-1];
    v_21708 = qcar(v_21708);
    if (!consp(v_21708)) goto v_21493;
    else goto v_21494;
v_21493:
    v_21708 = lisp_true;
    goto v_21492;
v_21494:
    v_21708 = stack[-1];
    v_21708 = qcar(v_21708);
    v_21708 = qcar(v_21708);
    v_21708 = (consp(v_21708) ? nil : lisp_true);
    goto v_21492;
    v_21708 = nil;
v_21492:
    if (v_21708 == nil) goto v_21490;
    goto v_21508;
v_21504:
    v_21708 = stack[-1];
    v_21709 = qcdr(v_21708);
    goto v_21505;
v_21506:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21507;
v_21508:
    goto v_21504;
v_21505:
    goto v_21506;
v_21507:
    v_21708 = (v_21709 == v_21708 ? lisp_true : nil);
    goto v_21488;
v_21490:
    v_21708 = nil;
    goto v_21488;
    v_21708 = nil;
v_21488:
    goto v_21476;
v_21478:
    v_21708 = nil;
    goto v_21476;
    v_21708 = nil;
v_21476:
    goto v_21471;
v_21473:
    v_21708 = nil;
    goto v_21471;
    v_21708 = nil;
v_21471:
    if (v_21708 == nil) goto v_21469;
    v_21708 = stack[-1];
    v_21708 = qcar(v_21708);
    if (!consp(v_21708)) goto v_21528;
    else goto v_21529;
v_21528:
    goto v_21537;
v_21533:
    v_21709 = stack[-2];
    goto v_21534;
v_21535:
    v_21708 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21536;
v_21537:
    goto v_21533;
v_21534:
    goto v_21535;
v_21536:
    v_21708 = (LispObject)greaterp2(v_21709, v_21708);
    v_21708 = v_21708 ? lisp_true : nil;
    env = stack[-8];
    goto v_21527;
v_21529:
    v_21708 = nil;
    goto v_21527;
    v_21708 = nil;
v_21527:
    if (v_21708 == nil) goto v_21525;
    goto v_21549;
v_21545:
    v_21708 = stack[-1];
    v_21709 = qcar(v_21708);
    goto v_21546;
v_21547:
    v_21708 = stack[-2];
    goto v_21548;
v_21549:
    goto v_21545;
v_21546:
    goto v_21547;
v_21548:
    v_21708 = Lexpt(nil, v_21709, v_21708);
    env = stack[-8];
    fn = elt(env, 16); // !*d2q
    v_21708 = (*qfn1(fn))(fn, v_21708);
    goto v_21523;
v_21525:
    goto v_21560;
v_21556:
    goto v_21566;
v_21562:
    v_21708 = stack[-1];
    v_21709 = qcar(v_21708);
    goto v_21563;
v_21564:
    v_21708 = stack[-2];
    goto v_21565;
v_21566:
    goto v_21562;
v_21563:
    goto v_21564;
v_21565:
    fn = elt(env, 17); // !:expt
    v_21709 = (*qfn2(fn))(fn, v_21709, v_21708);
    env = stack[-8];
    goto v_21557;
v_21558:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21559;
v_21560:
    goto v_21556;
v_21557:
    goto v_21558;
v_21559:
    v_21708 = cons(v_21709, v_21708);
    env = stack[-8];
    stack[-1] = v_21708;
    v_21708 = qvalue(elt(env, 8)); // !*mcd
    if (v_21708 == nil) goto v_21574;
    v_21708 = stack[-1];
    fn = elt(env, 18); // resimp
    v_21708 = (*qfn1(fn))(fn, v_21708);
    goto v_21572;
v_21574:
    v_21708 = stack[-1];
    goto v_21572;
    v_21708 = nil;
v_21572:
    goto v_21523;
    v_21708 = nil;
v_21523:
    goto v_21418;
v_21469:
    goto v_21588;
v_21584:
    stack[0] = elt(env, 9); // expt
    goto v_21585;
v_21586:
    goto v_21595;
v_21591:
    v_21709 = stack[-1];
    goto v_21592;
v_21593:
    v_21708 = stack[-5];
    goto v_21594;
v_21595:
    goto v_21591;
v_21592:
    goto v_21593;
v_21594:
    v_21708 = list2(v_21709, v_21708);
    env = stack[-8];
    goto v_21587;
v_21588:
    goto v_21584;
v_21585:
    goto v_21586;
v_21587:
    fn = elt(env, 19); // domainvalchk
    v_21708 = (*qfn2(fn))(fn, stack[0], v_21708);
    env = stack[-8];
    v_21709 = v_21708;
    if (v_21708 == nil) goto v_21582;
    v_21708 = v_21709;
    goto v_21418;
v_21582:
    v_21708 = stack[-2];
    if (!consp(v_21708)) goto v_21603;
    else goto v_21604;
v_21603:
    goto v_21610;
v_21606:
    v_21708 = stack[-5];
    v_21709 = qcdr(v_21708);
    goto v_21607;
v_21608:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21609;
v_21610:
    goto v_21606;
v_21607:
    goto v_21608;
v_21609:
    v_21708 = (v_21709 == v_21708 ? lisp_true : nil);
    goto v_21602;
v_21604:
    v_21708 = nil;
    goto v_21602;
    v_21708 = nil;
v_21602:
    if (v_21708 == nil) goto v_21600;
    goto v_21627;
v_21623:
    v_21709 = stack[-2];
    goto v_21624;
v_21625:
    v_21708 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21626;
v_21627:
    goto v_21623;
v_21624:
    goto v_21625;
v_21626:
    v_21708 = (LispObject)lessp2(v_21709, v_21708);
    v_21708 = v_21708 ? lisp_true : nil;
    env = stack[-8];
    if (v_21708 == nil) goto v_21620;
    else goto v_21621;
v_21620:
    goto v_21635;
v_21631:
    v_21709 = stack[-1];
    goto v_21632;
v_21633:
    v_21708 = stack[-2];
    goto v_21634;
v_21635:
    goto v_21631;
v_21632:
    goto v_21633;
v_21634:
    fn = elt(env, 20); // exptsq
    v_21708 = (*qfn2(fn))(fn, v_21709, v_21708);
    goto v_21619;
v_21621:
    v_21708 = qvalue(elt(env, 8)); // !*mcd
    if (v_21708 == nil) goto v_21639;
    goto v_21647;
v_21643:
    stack[0] = stack[-1];
    goto v_21644;
v_21645:
    v_21708 = stack[-2];
    v_21708 = negate(v_21708);
    env = stack[-8];
    goto v_21646;
v_21647:
    goto v_21643;
v_21644:
    goto v_21645;
v_21646:
    fn = elt(env, 20); // exptsq
    v_21708 = (*qfn2(fn))(fn, stack[0], v_21708);
    env = stack[-8];
    fn = elt(env, 21); // invsq
    v_21708 = (*qfn1(fn))(fn, v_21708);
    goto v_21619;
v_21639:
    goto v_21658;
v_21654:
    goto v_21664;
v_21660:
    goto v_21670;
v_21666:
    v_21708 = stack[-1];
    v_21709 = qcar(v_21708);
    goto v_21667;
v_21668:
    v_21708 = stack[-2];
    goto v_21669;
v_21670:
    goto v_21666;
v_21667:
    goto v_21668;
v_21669:
    fn = elt(env, 22); // expf
    stack[0] = (*qfn2(fn))(fn, v_21709, v_21708);
    env = stack[-8];
    goto v_21661;
v_21662:
    goto v_21679;
v_21675:
    v_21708 = stack[-1];
    stack[-1] = qcdr(v_21708);
    goto v_21676;
v_21677:
    v_21708 = stack[-2];
    v_21708 = negate(v_21708);
    env = stack[-8];
    goto v_21678;
v_21679:
    goto v_21675;
v_21676:
    goto v_21677;
v_21678:
    fn = elt(env, 23); // mksfpf
    v_21708 = (*qfn2(fn))(fn, stack[-1], v_21708);
    env = stack[-8];
    goto v_21663;
v_21664:
    goto v_21660;
v_21661:
    goto v_21662;
v_21663:
    fn = elt(env, 24); // multf
    v_21709 = (*qfn2(fn))(fn, stack[0], v_21708);
    env = stack[-8];
    goto v_21655;
v_21656:
    v_21708 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21657;
v_21658:
    goto v_21654;
v_21655:
    goto v_21656;
v_21657:
    v_21708 = cons(v_21709, v_21708);
    goto v_21619;
    v_21708 = nil;
v_21619:
    goto v_21418;
v_21600:
    goto v_21694;
v_21688:
    v_21708 = stack[-4];
    if (v_21708 == nil) goto v_21698;
    v_21708 = stack[-6];
    v_21710 = v_21708;
    goto v_21696;
v_21698:
    v_21708 = stack[-1];
    fn = elt(env, 25); // subs2!*
    v_21708 = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    v_21708 = (*qfn1(fn))(fn, v_21708);
    env = stack[-8];
    v_21710 = v_21708;
    goto v_21696;
    v_21710 = nil;
v_21696:
    goto v_21689;
v_21690:
    v_21709 = stack[-5];
    goto v_21691;
v_21692:
    v_21708 = lisp_true;
    goto v_21693;
v_21694:
    goto v_21688;
v_21689:
    goto v_21690;
v_21691:
    goto v_21692;
v_21693:
    fn = elt(env, 13); // simpexpt11
    v_21708 = (*qfnn(fn))(fn, 3, v_21710, v_21709, v_21708);
    goto v_21418;
    v_21708 = nil;
v_21418:
v_21168:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21708);
}



// Code for rl_bnfsimpl

static LispObject CC_rl_bnfsimpl(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21176, v_21177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21176 = v_21159;
    v_21177 = v_21158;
// end of prologue
    goto v_21166;
v_21162:
    stack[0] = qvalue(elt(env, 1)); // rl_bnfsimpl!*
    goto v_21163;
v_21164:
    goto v_21173;
v_21169:
    goto v_21170;
v_21171:
    goto v_21172;
v_21173:
    goto v_21169;
v_21170:
    goto v_21171;
v_21172:
    v_21176 = list2(v_21177, v_21176);
    env = stack[-1];
    goto v_21165;
v_21166:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    {
        LispObject v_21179 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21179, v_21176);
    }
}



// Code for dvfsf_smupdknowl

static LispObject CC_dvfsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21198, v_21199, v_21200, v_21201, v_21202;
    LispObject fn;
    LispObject v_21161, v_21160, v_21159, v_21158;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
    va_start(aa, nargs);
    v_21158 = va_arg(aa, LispObject);
    v_21159 = va_arg(aa, LispObject);
    v_21160 = va_arg(aa, LispObject);
    v_21161 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21199 = v_21161;
    v_21200 = v_21160;
    v_21201 = v_21159;
    v_21202 = v_21158;
// end of prologue
    v_21198 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_21198 == nil) goto v_21166;
    goto v_21177;
v_21169:
    v_21198 = v_21202;
    goto v_21170;
v_21171:
    goto v_21172;
v_21173:
    goto v_21174;
v_21175:
    goto v_21176;
v_21177:
    goto v_21169;
v_21170:
    goto v_21171;
v_21172:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_21198, v_21201, v_21200, v_21199);
    }
v_21166:
    goto v_21193;
v_21185:
    v_21198 = v_21202;
    goto v_21186;
v_21187:
    goto v_21188;
v_21189:
    goto v_21190;
v_21191:
    goto v_21192;
v_21193:
    goto v_21185;
v_21186:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
    goto v_21191;
v_21192:
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(fn, 4, v_21198, v_21201, v_21200, v_21199);
    }
    v_21198 = nil;
    return onevalue(v_21198);
}



// Code for groebinvokecritm

static LispObject CC_groebinvokecritm(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21202, v_21203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21159;
    stack[-2] = v_21158;
// end of prologue
    v_21202 = stack[-1];
    stack[-3] = v_21202;
v_21164:
    v_21202 = stack[-3];
    if (v_21202 == nil) goto v_21168;
    else goto v_21169;
v_21168:
    goto v_21163;
v_21169:
    v_21202 = stack[-3];
    v_21202 = qcar(v_21202);
    stack[0] = v_21202;
    goto v_21184;
v_21180:
    v_21202 = stack[-2];
    v_21203 = qcar(v_21202);
    goto v_21181;
v_21182:
    v_21202 = stack[0];
    v_21202 = qcar(v_21202);
    goto v_21183;
v_21184:
    goto v_21180;
v_21181:
    goto v_21182;
v_21183:
    fn = elt(env, 2); // buchvevdivides!?
    v_21202 = (*qfn2(fn))(fn, v_21203, v_21202);
    env = stack[-4];
    if (v_21202 == nil) goto v_21178;
    v_21202 = qvalue(elt(env, 1)); // mcount!*
    v_21202 = add1(v_21202);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_21202; // mcount!*
    goto v_21196;
v_21192:
    v_21203 = stack[0];
    goto v_21193;
v_21194:
    v_21202 = stack[-1];
    goto v_21195;
v_21196:
    goto v_21192;
v_21193:
    goto v_21194;
v_21195:
    fn = elt(env, 3); // groedeletip
    v_21202 = (*qfn2(fn))(fn, v_21203, v_21202);
    env = stack[-4];
    stack[-1] = v_21202;
    goto v_21176;
v_21178:
v_21176:
    v_21202 = stack[-3];
    v_21202 = qcdr(v_21202);
    stack[-3] = v_21202;
    goto v_21164;
v_21163:
    v_21202 = stack[-1];
    return onevalue(v_21202);
}



// Code for vdpcleanup

static LispObject CC_vdpcleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21161;
    argcheck(nargs, 0, "vdpcleanup");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    v_21161 = nil;
    v_21161 = ncons(v_21161);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21161; // dipevlist!*
    return onevalue(v_21161);
}



// Code for bflessp

static LispObject CC_bflessp(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21184, v_21185, v_21186;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21185 = v_21159;
    v_21186 = v_21158;
// end of prologue
    v_21184 = v_21186;
    if (!consp(v_21184)) goto v_21163;
    else goto v_21164;
v_21163:
    goto v_21171;
v_21167:
    v_21184 = v_21186;
    goto v_21168;
v_21169:
    goto v_21170;
v_21171:
    goto v_21167;
v_21168:
    goto v_21169;
v_21170:
        return Llessp(nil, v_21184, v_21185);
v_21164:
    goto v_21181;
v_21177:
    v_21184 = v_21185;
    goto v_21178;
v_21179:
    v_21185 = v_21186;
    goto v_21180;
v_21181:
    goto v_21177;
v_21178:
    goto v_21179;
v_21180:
    {
        fn = elt(env, 1); // grpbf
        return (*qfn2(fn))(fn, v_21184, v_21185);
    }
    v_21184 = nil;
    return onevalue(v_21184);
}



// Code for intrdsortin

static LispObject CC_intrdsortin(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21225, v_21226;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
    stack[-2] = nil;
v_21164:
    v_21225 = stack[0];
    if (v_21225 == nil) goto v_21167;
    else goto v_21168;
v_21167:
    goto v_21175;
v_21171:
    stack[0] = stack[-2];
    goto v_21172;
v_21173:
    v_21225 = stack[-1];
    v_21225 = ncons(v_21225);
    env = stack[-3];
    goto v_21174;
v_21175:
    goto v_21171;
v_21172:
    goto v_21173;
v_21174:
    {
        LispObject v_21230 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21230, v_21225);
    }
v_21168:
    v_21225 = stack[-1];
    v_21226 = qcar(v_21225);
    v_21225 = stack[0];
    v_21225 = qcar(v_21225);
    v_21225 = qcar(v_21225);
    goto v_21194;
v_21190:
    goto v_21191;
v_21192:
    goto v_21193;
v_21194:
    goto v_21190;
v_21191:
    goto v_21192;
v_21193:
    fn = elt(env, 2); // !:difference
    v_21225 = (*qfn2(fn))(fn, v_21226, v_21225);
    env = stack[-3];
    fn = elt(env, 3); // !:minusp
    v_21225 = (*qfn1(fn))(fn, v_21225);
    env = stack[-3];
    if (v_21225 == nil) goto v_21180;
    goto v_21202;
v_21198:
    v_21225 = stack[0];
    v_21226 = qcar(v_21225);
    goto v_21199;
v_21200:
    v_21225 = stack[-2];
    goto v_21201;
v_21202:
    goto v_21198;
v_21199:
    goto v_21200;
v_21201:
    v_21225 = cons(v_21226, v_21225);
    env = stack[-3];
    stack[-2] = v_21225;
    v_21225 = stack[0];
    v_21225 = qcdr(v_21225);
    stack[0] = v_21225;
    goto v_21164;
v_21180:
    goto v_21215;
v_21211:
    goto v_21212;
v_21213:
    goto v_21222;
v_21218:
    v_21226 = stack[-1];
    goto v_21219;
v_21220:
    v_21225 = stack[0];
    goto v_21221;
v_21222:
    goto v_21218;
v_21219:
    goto v_21220;
v_21221:
    v_21225 = cons(v_21226, v_21225);
    env = stack[-3];
    goto v_21214;
v_21215:
    goto v_21211;
v_21212:
    goto v_21213;
v_21214:
    {
        LispObject v_21231 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21231, v_21225);
    }
    v_21225 = nil;
    return onevalue(v_21225);
}



// Code for z!-roads

static LispObject CC_zKroads(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21235, v_21236, v_21237;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21236 = v_21158;
// end of prologue
    goto v_21168;
v_21164:
    v_21237 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21165;
v_21166:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    goto v_21167;
v_21168:
    goto v_21164;
v_21165:
    goto v_21166;
v_21167:
    if (v_21237 == v_21235) goto v_21162;
    else goto v_21163;
v_21162:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcar(v_21235);
    goto v_21161;
v_21163:
    goto v_21183;
v_21179:
    v_21237 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21180;
v_21181:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    goto v_21182;
v_21183:
    goto v_21179;
v_21180:
    goto v_21181;
v_21182:
    if (v_21237 == v_21235) goto v_21177;
    else goto v_21178;
v_21177:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcar(v_21235);
    goto v_21161;
v_21178:
    goto v_21200;
v_21196:
    v_21237 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21197;
v_21198:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    goto v_21199;
v_21200:
    goto v_21196;
v_21197:
    goto v_21198;
v_21199:
    if (v_21237 == v_21235) goto v_21194;
    else goto v_21195;
v_21194:
    v_21235 = v_21236;
    v_21235 = qcar(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcdr(v_21235);
    v_21235 = qcar(v_21235);
    goto v_21161;
v_21195:
    v_21235 = nil;
    goto v_21161;
    v_21235 = nil;
v_21161:
    v_21237 = v_21235;
    v_21235 = v_21237;
    if (v_21235 == nil) goto v_21219;
    else goto v_21220;
v_21219:
    v_21235 = nil;
    goto v_21218;
v_21220:
    goto v_21230;
v_21226:
    v_21235 = v_21237;
    v_21235 = qcar(v_21235);
    goto v_21227;
v_21228:
    v_21236 = qcdr(v_21236);
    goto v_21229;
v_21230:
    goto v_21226;
v_21227:
    goto v_21228;
v_21229:
    return cons(v_21235, v_21236);
    v_21235 = nil;
v_21218:
    return onevalue(v_21235);
}



// Code for janettreenodebuild

static LispObject CC_janettreenodebuild(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21276, v_21277;
    LispObject fn;
    LispObject v_21160, v_21159, v_21158;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "janettreenodebuild");
    va_start(aa, nargs);
    v_21158 = va_arg(aa, LispObject);
    v_21159 = va_arg(aa, LispObject);
    v_21160 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21160,v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21158,v_21159,v_21160);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_21160;
    stack[-6] = v_21159;
    stack[-7] = v_21158;
// end of prologue
    goto v_21171;
v_21167:
    v_21277 = stack[-5];
    goto v_21168;
v_21169:
    v_21276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21170;
v_21171:
    goto v_21167;
v_21168:
    goto v_21169;
v_21170:
    v_21276 = *(LispObject *)((char *)v_21277 + (CELL-TAG_VECTOR) + (((intptr_t)v_21276-TAG_FIXNUM)/(16/CELL)));
    v_21276 = qcar(v_21276);
    stack[-3] = v_21276;
    goto v_21183;
v_21177:
    goto v_21189;
v_21185:
    v_21277 = stack[-3];
    goto v_21186;
v_21187:
    v_21276 = stack[-6];
    goto v_21188;
v_21189:
    goto v_21185;
v_21186:
    goto v_21187;
v_21188:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21277, v_21276);
    env = stack[-9];
    goto v_21178;
v_21179:
    stack[0] = nil;
    goto v_21180;
v_21181:
    v_21276 = nil;
    v_21276 = ncons(v_21276);
    env = stack[-9];
    goto v_21182;
v_21183:
    goto v_21177;
v_21178:
    goto v_21179;
v_21180:
    goto v_21181;
v_21182:
    v_21276 = acons(stack[-1], stack[0], v_21276);
    env = stack[-9];
    stack[-8] = v_21276;
    v_21276 = stack[-8];
    stack[-4] = v_21276;
v_21198:
    goto v_21207;
v_21203:
    stack[0] = stack[-7];
    goto v_21204;
v_21205:
    goto v_21214;
v_21210:
    v_21277 = stack[-3];
    goto v_21211;
v_21212:
    v_21276 = stack[-6];
    goto v_21213;
v_21214:
    goto v_21210;
v_21211:
    goto v_21212;
v_21213:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21276 = (*qfn2(fn))(fn, v_21277, v_21276);
    env = stack[-9];
    goto v_21206;
v_21207:
    goto v_21203;
v_21204:
    goto v_21205;
v_21206:
    if (((intptr_t)(stack[0])) > ((intptr_t)(v_21276))) goto v_21202;
    goto v_21197;
v_21202:
    goto v_21222;
v_21218:
    stack[0] = stack[-7];
    goto v_21219;
v_21220:
    goto v_21229;
v_21225:
    v_21277 = stack[-3];
    goto v_21226;
v_21227:
    v_21276 = stack[-6];
    goto v_21228;
v_21229:
    goto v_21225;
v_21226:
    goto v_21227;
v_21228:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21276 = (*qfn2(fn))(fn, v_21277, v_21276);
    env = stack[-9];
    goto v_21221;
v_21222:
    goto v_21218;
v_21219:
    goto v_21220;
v_21221:
    v_21276 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_21276 + TAG_FIXNUM);
    stack[-7] = v_21276;
    v_21276 = stack[-6];
    v_21276 = (LispObject)((intptr_t)(v_21276) + 0x10);
    stack[-6] = v_21276;
    goto v_21240;
v_21236:
    v_21276 = stack[-4];
    stack[-2] = qcdr(v_21276);
    goto v_21237;
v_21238:
    goto v_21250;
v_21244:
    goto v_21256;
v_21252:
    v_21277 = stack[-3];
    goto v_21253;
v_21254:
    v_21276 = stack[-6];
    goto v_21255;
v_21256:
    goto v_21252;
v_21253:
    goto v_21254;
v_21255:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21277, v_21276);
    env = stack[-9];
    goto v_21245;
v_21246:
    stack[0] = nil;
    goto v_21247;
v_21248:
    v_21276 = nil;
    v_21276 = ncons(v_21276);
    env = stack[-9];
    goto v_21249;
v_21250:
    goto v_21244;
v_21245:
    goto v_21246;
v_21247:
    goto v_21248;
v_21249:
    v_21276 = acons(stack[-1], stack[0], v_21276);
    env = stack[-9];
    goto v_21239;
v_21240:
    goto v_21236;
v_21237:
    goto v_21238;
v_21239:
    fn = elt(env, 2); // setcdr
    v_21276 = (*qfn2(fn))(fn, stack[-2], v_21276);
    env = stack[-9];
    v_21276 = stack[-4];
    v_21276 = qcdr(v_21276);
    v_21276 = qcdr(v_21276);
    stack[-4] = v_21276;
    goto v_21198;
v_21197:
    goto v_21271;
v_21267:
    v_21276 = stack[-4];
    v_21277 = qcar(v_21276);
    goto v_21268;
v_21269:
    v_21276 = stack[-5];
    goto v_21270;
v_21271:
    goto v_21267;
v_21268:
    goto v_21269;
v_21270:
    fn = elt(env, 2); // setcdr
    v_21276 = (*qfn2(fn))(fn, v_21277, v_21276);
    v_21276 = stack[-8];
    return onevalue(v_21276);
}



// Code for ofsf_qesubqat

static LispObject CC_ofsf_qesubqat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21355, v_21356, v_21357;
    LispObject fn;
    LispObject v_21160, v_21159, v_21158;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_qesubqat");
    va_start(aa, nargs);
    v_21158 = va_arg(aa, LispObject);
    v_21159 = va_arg(aa, LispObject);
    v_21160 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21160,v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21158,v_21159,v_21160);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21160;
    stack[-1] = v_21159;
    stack[-2] = v_21158;
// end of prologue
    goto v_21175;
v_21171:
    stack[-3] = stack[-1];
    goto v_21172;
v_21173:
    v_21355 = stack[-2];
    fn = elt(env, 6); // ofsf_varlat
    v_21355 = (*qfn1(fn))(fn, v_21355);
    env = stack[-4];
    goto v_21174;
v_21175:
    goto v_21171;
v_21172:
    goto v_21173;
v_21174:
    v_21355 = Lmemq(nil, stack[-3], v_21355);
    if (v_21355 == nil) goto v_21169;
    else goto v_21170;
v_21169:
    v_21355 = stack[-2];
    goto v_21166;
v_21170:
    v_21355 = qvalue(elt(env, 1)); // !*rlqesubf
    if (v_21355 == nil) goto v_21184;
    goto v_21191;
v_21187:
    v_21355 = stack[-2];
    v_21355 = qcdr(v_21355);
    stack[-3] = qcar(v_21355);
    goto v_21188;
v_21189:
    goto v_21201;
v_21197:
    goto v_21198;
v_21199:
    v_21355 = stack[0];
    fn = elt(env, 7); // prepsq
    v_21355 = (*qfn1(fn))(fn, v_21355);
    env = stack[-4];
    goto v_21200;
v_21201:
    goto v_21197;
v_21198:
    goto v_21199;
v_21200:
    v_21355 = cons(stack[-1], v_21355);
    env = stack[-4];
    v_21355 = ncons(v_21355);
    env = stack[-4];
    goto v_21190;
v_21191:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
    fn = elt(env, 8); // subf
    v_21355 = (*qfn2(fn))(fn, stack[-3], v_21355);
    env = stack[-4];
    goto v_21182;
v_21184:
    goto v_21214;
v_21208:
    v_21355 = stack[-2];
    v_21355 = qcdr(v_21355);
    v_21357 = qcar(v_21355);
    goto v_21209;
v_21210:
    v_21356 = stack[-1];
    goto v_21211;
v_21212:
    v_21355 = stack[0];
    goto v_21213;
v_21214:
    goto v_21208;
v_21209:
    goto v_21210;
v_21211:
    goto v_21212;
v_21213:
    fn = elt(env, 9); // ofsf_subf
    v_21355 = (*qfnn(fn))(fn, 3, v_21357, v_21356, v_21355);
    env = stack[-4];
    goto v_21182;
    v_21355 = nil;
v_21182:
    stack[-1] = v_21355;
    v_21355 = stack[-2];
    v_21355 = qcar(v_21355);
    stack[0] = v_21355;
    v_21355 = qvalue(elt(env, 2)); // !*rlqelocal
    if (v_21355 == nil) goto v_21225;
    goto v_21232;
v_21228:
    v_21356 = stack[0];
    goto v_21229;
v_21230:
    v_21355 = stack[-1];
    goto v_21231;
v_21232:
    goto v_21228;
v_21229:
    goto v_21230;
v_21231:
    {
        fn = elt(env, 10); // ofsf_qesubqat!-local
        return (*qfn2(fn))(fn, v_21356, v_21355);
    }
v_21225:
    goto v_21247;
v_21243:
    v_21356 = stack[0];
    goto v_21244;
v_21245:
    v_21355 = elt(env, 3); // equal
    goto v_21246;
v_21247:
    goto v_21243;
v_21244:
    goto v_21245;
v_21246:
    if (v_21356 == v_21355) goto v_21241;
    else goto v_21242;
v_21241:
    v_21355 = lisp_true;
    goto v_21240;
v_21242:
    goto v_21261;
v_21257:
    v_21356 = stack[0];
    goto v_21258;
v_21259:
    v_21355 = elt(env, 4); // neq
    goto v_21260;
v_21261:
    goto v_21257;
v_21258:
    goto v_21259;
v_21260:
    if (v_21356 == v_21355) goto v_21255;
    else goto v_21256;
v_21255:
    v_21355 = lisp_true;
    goto v_21254;
v_21256:
    goto v_21272;
v_21268:
    goto v_21280;
v_21274:
    v_21357 = elt(env, 5); // geq
    goto v_21275;
v_21276:
    v_21355 = stack[-1];
    v_21356 = qcdr(v_21355);
    goto v_21277;
v_21278:
    v_21355 = nil;
    goto v_21279;
v_21280:
    goto v_21274;
v_21275:
    goto v_21276;
v_21277:
    goto v_21278;
v_21279:
    v_21356 = list3(v_21357, v_21356, v_21355);
    env = stack[-4];
    goto v_21269;
v_21270:
    v_21355 = nil;
    goto v_21271;
v_21272:
    goto v_21268;
v_21269:
    goto v_21270;
v_21271:
    fn = elt(env, 11); // ofsf_surep
    v_21355 = (*qfn2(fn))(fn, v_21356, v_21355);
    env = stack[-4];
    goto v_21254;
    v_21355 = nil;
v_21254:
    goto v_21240;
    v_21355 = nil;
v_21240:
    if (v_21355 == nil) goto v_21238;
    goto v_21293;
v_21287:
    v_21357 = stack[0];
    goto v_21288;
v_21289:
    v_21355 = stack[-1];
    v_21356 = qcar(v_21355);
    goto v_21290;
v_21291:
    v_21355 = nil;
    goto v_21292;
v_21293:
    goto v_21287;
v_21288:
    goto v_21289;
v_21290:
    goto v_21291;
v_21292:
    return list3(v_21357, v_21356, v_21355);
v_21238:
    v_21355 = stack[-1];
    v_21355 = qcdr(v_21355);
    fn = elt(env, 12); // sfto_pdecf
    v_21355 = (*qfn1(fn))(fn, v_21355);
    env = stack[-4];
    v_21355 = qcar(v_21355);
    stack[-2] = v_21355;
    goto v_21311;
v_21307:
    goto v_21319;
v_21313:
    v_21357 = elt(env, 5); // geq
    goto v_21314;
v_21315:
    v_21356 = stack[-2];
    goto v_21316;
v_21317:
    v_21355 = nil;
    goto v_21318;
v_21319:
    goto v_21313;
v_21314:
    goto v_21315;
v_21316:
    goto v_21317;
v_21318:
    v_21356 = list3(v_21357, v_21356, v_21355);
    env = stack[-4];
    goto v_21308;
v_21309:
    v_21355 = nil;
    goto v_21310;
v_21311:
    goto v_21307;
v_21308:
    goto v_21309;
v_21310:
    fn = elt(env, 11); // ofsf_surep
    v_21355 = (*qfn2(fn))(fn, v_21356, v_21355);
    env = stack[-4];
    if (v_21355 == nil) goto v_21305;
    goto v_21331;
v_21325:
    v_21357 = stack[0];
    goto v_21326;
v_21327:
    v_21355 = stack[-1];
    v_21356 = qcar(v_21355);
    goto v_21328;
v_21329:
    v_21355 = nil;
    goto v_21330;
v_21331:
    goto v_21325;
v_21326:
    goto v_21327;
v_21328:
    goto v_21329;
v_21330:
    return list3(v_21357, v_21356, v_21355);
v_21305:
    goto v_21343;
v_21337:
    goto v_21338;
v_21339:
    goto v_21350;
v_21346:
    v_21355 = stack[-1];
    v_21356 = qcar(v_21355);
    goto v_21347;
v_21348:
    v_21355 = stack[-2];
    goto v_21349;
v_21350:
    goto v_21346;
v_21347:
    goto v_21348;
v_21349:
    fn = elt(env, 13); // multf
    v_21356 = (*qfn2(fn))(fn, v_21356, v_21355);
    goto v_21340;
v_21341:
    v_21355 = nil;
    goto v_21342;
v_21343:
    goto v_21337;
v_21338:
    goto v_21339;
v_21340:
    goto v_21341;
v_21342:
    {
        LispObject v_21362 = stack[0];
        return list3(v_21362, v_21356, v_21355);
    }
v_21166:
    return onevalue(v_21355);
}



// Code for testord

static LispObject CC_testord(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21189, v_21190;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
v_21163:
    v_21189 = stack[-1];
    if (v_21189 == nil) goto v_21166;
    else goto v_21167;
v_21166:
    v_21189 = lisp_true;
    goto v_21162;
v_21167:
    goto v_21177;
v_21173:
    v_21189 = stack[-1];
    v_21190 = qcar(v_21189);
    goto v_21174;
v_21175:
    v_21189 = stack[0];
    v_21189 = qcar(v_21189);
    goto v_21176;
v_21177:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    v_21189 = (LispObject)lesseq2(v_21190, v_21189);
    v_21189 = v_21189 ? lisp_true : nil;
    env = stack[-2];
    if (v_21189 == nil) goto v_21171;
    v_21189 = stack[-1];
    v_21189 = qcdr(v_21189);
    stack[-1] = v_21189;
    v_21189 = stack[0];
    v_21189 = qcdr(v_21189);
    stack[0] = v_21189;
    goto v_21163;
v_21171:
    v_21189 = nil;
    goto v_21162;
    v_21189 = nil;
v_21162:
    return onevalue(v_21189);
}



// Code for tayfkern

static LispObject CC_tayfkern(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21221, v_21222, v_21223;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21223 = v_21158;
// end of prologue
    v_21221 = qvalue(elt(env, 1)); // !*tayinternal!*
    if (v_21221 == nil) goto v_21167;
    v_21221 = v_21223;
    goto v_21163;
v_21167:
    v_21221 = elt(env, 2); // taylor!*
    if (!symbolp(v_21221)) v_21221 = nil;
    else { v_21221 = qfastgets(v_21221);
           if (v_21221 != nil) { v_21221 = elt(v_21221, 24); // klist
#ifdef RECORD_GET
             if (v_21221 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_21221 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_21221 == SPID_NOPROP) v_21221 = nil; }}
#endif
    stack[0] = v_21221;
    goto v_21176;
v_21172:
    v_21222 = v_21223;
    goto v_21173;
v_21174:
    v_21221 = stack[0];
    goto v_21175;
v_21176:
    goto v_21172;
v_21173:
    goto v_21174;
v_21175:
    v_21221 = Lassoc(nil, v_21222, v_21221);
    stack[-1] = v_21221;
    v_21221 = stack[-1];
    if (v_21221 == nil) goto v_21182;
    else goto v_21183;
v_21182:
    goto v_21190;
v_21186:
    v_21222 = v_21223;
    goto v_21187;
v_21188:
    v_21221 = nil;
    goto v_21189;
v_21190:
    goto v_21186;
v_21187:
    goto v_21188;
v_21189:
    v_21221 = list2(v_21222, v_21221);
    env = stack[-2];
    stack[-1] = v_21221;
    goto v_21198;
v_21194:
    v_21222 = stack[-1];
    goto v_21195;
v_21196:
    v_21221 = stack[0];
    goto v_21197;
v_21198:
    goto v_21194;
v_21195:
    goto v_21196;
v_21197:
    fn = elt(env, 6); // ordad
    v_21221 = (*qfn2(fn))(fn, v_21222, v_21221);
    env = stack[-2];
    stack[0] = v_21221;
    goto v_21206;
v_21202:
    v_21222 = elt(env, 3); // (taylor!*)
    goto v_21203;
v_21204:
    v_21221 = qvalue(elt(env, 4)); // kprops!*
    goto v_21205;
v_21206:
    goto v_21202;
v_21203:
    goto v_21204;
v_21205:
    fn = elt(env, 7); // union
    v_21221 = (*qfn2(fn))(fn, v_21222, v_21221);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_21221; // kprops!*
    goto v_21216;
v_21210:
    v_21223 = elt(env, 2); // taylor!*
    goto v_21211;
v_21212:
    v_21222 = elt(env, 5); // klist
    goto v_21213;
v_21214:
    v_21221 = stack[0];
    goto v_21215;
v_21216:
    goto v_21210;
v_21211:
    goto v_21212;
v_21213:
    goto v_21214;
v_21215:
    v_21221 = Lputprop(nil, 3, v_21223, v_21222, v_21221);
    goto v_21181;
v_21183:
v_21181:
    v_21221 = stack[-1];
v_21163:
    return onevalue(v_21221);
}



// Code for mk!+outer!+list

static LispObject CC_mkLouterLlist(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21171, v_21172;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
    goto v_21167;
v_21163:
    v_21171 = elt(env, 1); // list
    v_21172 = ncons(v_21171);
    goto v_21164;
v_21165:
    v_21171 = stack[0];
    goto v_21166;
v_21167:
    goto v_21163;
v_21164:
    goto v_21165;
v_21166:
        return Lappend(nil, v_21172, v_21171);
    return onevalue(v_21171);
}



// Code for repr_n

static LispObject CC_repr_n(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21194, v_21195, v_21196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21195 = v_21158;
// end of prologue
    v_21194 = v_21195;
    v_21194 = qcdr(v_21194);
    v_21194 = qcdr(v_21194);
    v_21194 = qcar(v_21194);
    if (v_21194 == nil) goto v_21162;
    else goto v_21163;
v_21162:
    v_21194 = elt(env, 1); // "repr_n : invalid REPR structure"
    v_21194 = ncons(v_21194);
    env = stack[0];
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21194);
    }
v_21163:
    goto v_21177;
v_21173:
    v_21194 = v_21195;
    v_21194 = qcdr(v_21194);
    v_21194 = qcdr(v_21194);
    v_21194 = qcdr(v_21194);
    v_21194 = qcdr(v_21194);
    v_21196 = qcar(v_21194);
    goto v_21174;
v_21175:
    v_21194 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21176;
v_21177:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    if (v_21196 == v_21194) goto v_21171;
    else goto v_21172;
v_21171:
    v_21194 = nil;
    goto v_21161;
v_21172:
    v_21194 = v_21195;
    v_21194 = qcdr(v_21194);
    v_21194 = qcdr(v_21194);
    v_21194 = qcar(v_21194);
    v_21194 = qcar(v_21194);
    v_21194 = qcar(v_21194);
    goto v_21161;
    v_21194 = nil;
v_21161:
    return onevalue(v_21194);
}



// Code for minusrd

static LispObject CC_minusrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21187, v_21188, v_21189;
    LispObject fn;
    argcheck(nargs, 0, "minusrd");
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
    fn = elt(env, 1); // mathml
    v_21187 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21187;
    fn = elt(env, 1); // mathml
    v_21187 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_21188 = v_21187;
    if (v_21188 == nil) goto v_21167;
    else goto v_21168;
v_21167:
    v_21187 = stack[0];
    v_21187 = ncons(v_21187);
    stack[0] = v_21187;
    goto v_21166;
v_21168:
    goto v_21181;
v_21175:
    v_21189 = stack[0];
    goto v_21176;
v_21177:
    v_21188 = v_21187;
    goto v_21178;
v_21179:
    v_21187 = nil;
    goto v_21180;
v_21181:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    goto v_21179;
v_21180:
    v_21187 = list2star(v_21189, v_21188, v_21187);
    env = stack[-1];
    stack[0] = v_21187;
    fn = elt(env, 2); // lex
    v_21187 = (*qfnn(fn))(fn, 0);
    goto v_21166;
v_21166:
    v_21187 = stack[0];
    return onevalue(v_21187);
}



// Code for divide!-by!-power!-of!-ten

static LispObject CC_divideKbyKpowerKofKten(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21238, v_21239, v_21240;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
    goto v_21170;
v_21166:
    v_21239 = stack[0];
    goto v_21167;
v_21168:
    v_21238 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21169;
v_21170:
    goto v_21166;
v_21167:
    goto v_21168;
v_21169:
    v_21238 = (LispObject)lessp2(v_21239, v_21238);
    v_21238 = v_21238 ? lisp_true : nil;
    env = stack[-3];
    if (v_21238 == nil) goto v_21164;
    v_21238 = elt(env, 0); // divide!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21238);
    }
v_21164:
    v_21238 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21238;
v_21181:
    goto v_21191;
v_21187:
    v_21239 = stack[0];
    goto v_21188;
v_21189:
    v_21238 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21190;
v_21191:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
    v_21238 = (LispObject)greaterp2(v_21239, v_21238);
    v_21238 = v_21238 ? lisp_true : nil;
    env = stack[-3];
    if (v_21238 == nil) goto v_21184;
    else goto v_21185;
v_21184:
    goto v_21180;
v_21185:
    v_21238 = stack[0];
    v_21238 = Levenp(nil, v_21238);
    env = stack[-3];
    if (v_21238 == nil) goto v_21197;
    else goto v_21198;
v_21197:
    goto v_21209;
v_21203:
    v_21240 = stack[-1];
    goto v_21204;
v_21205:
    v_21239 = stack[-2];
    goto v_21206;
v_21207:
    v_21238 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21208;
v_21209:
    goto v_21203;
v_21204:
    goto v_21205;
v_21206:
    goto v_21207;
v_21208:
    fn = elt(env, 4); // divide!:
    v_21238 = (*qfnn(fn))(fn, 3, v_21240, v_21239, v_21238);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21238 = (*qfn1(fn))(fn, v_21238);
    env = stack[-3];
    stack[-1] = v_21238;
    goto v_21196;
v_21198:
v_21196:
    goto v_21218;
v_21214:
    v_21239 = stack[0];
    goto v_21215;
v_21216:
    v_21238 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21217;
v_21218:
    goto v_21214;
v_21215:
    goto v_21216;
v_21217:
    fn = elt(env, 6); // lshift
    v_21238 = (*qfn2(fn))(fn, v_21239, v_21238);
    env = stack[-3];
    stack[0] = v_21238;
    goto v_21227;
v_21223:
    goto v_21233;
v_21229:
    v_21239 = stack[-2];
    goto v_21230;
v_21231:
    v_21238 = stack[-2];
    goto v_21232;
v_21233:
    goto v_21229;
v_21230:
    goto v_21231;
v_21232:
    fn = elt(env, 7); // times!:
    v_21239 = (*qfn2(fn))(fn, v_21239, v_21238);
    env = stack[-3];
    goto v_21224;
v_21225:
    v_21238 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21226;
v_21227:
    goto v_21223;
v_21224:
    goto v_21225;
v_21226:
    fn = elt(env, 8); // cut!:mt
    v_21238 = (*qfn2(fn))(fn, v_21239, v_21238);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21238 = (*qfn1(fn))(fn, v_21238);
    env = stack[-3];
    stack[-2] = v_21238;
    goto v_21181;
v_21180:
    v_21238 = stack[-1];
    goto v_21162;
    v_21238 = nil;
v_21162:
    return onevalue(v_21238);
}



// Code for atom_compare

static LispObject CC_atom_compare(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21198, v_21199, v_21200;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
// copy arguments values to proper place
    v_21199 = v_21159;
    v_21200 = v_21158;
// end of prologue
    v_21198 = v_21200;
    if (is_number(v_21198)) goto v_21163;
    else goto v_21164;
v_21163:
    v_21198 = v_21199;
    if (is_number(v_21198)) goto v_21169;
    v_21198 = nil;
    goto v_21167;
v_21169:
    goto v_21179;
v_21175:
    v_21198 = v_21200;
    goto v_21176;
v_21177:
    goto v_21178;
v_21179:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    v_21198 = (LispObject)lessp2(v_21198, v_21199);
    v_21198 = v_21198 ? lisp_true : nil;
    v_21198 = (v_21198 == nil ? lisp_true : nil);
    goto v_21167;
    v_21198 = nil;
v_21167:
    goto v_21162;
v_21164:
    v_21198 = v_21199;
    if (symbolp(v_21198)) goto v_21183;
    else goto v_21184;
v_21183:
    goto v_21191;
v_21187:
    v_21198 = v_21200;
    goto v_21188;
v_21189:
    goto v_21190;
v_21191:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
        return Lorderp(nil, v_21198, v_21199);
v_21184:
    v_21198 = v_21199;
    v_21198 = (is_number(v_21198) ? lisp_true : nil);
    goto v_21162;
    v_21198 = nil;
v_21162:
    return onevalue(v_21198);
}



// Code for set_parser

static LispObject CC_set_parser(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21190, v_21191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
    v_21190 = stack[0];
    v_21190 = qcar(v_21190);
    fn = elt(env, 8); // lex_restore_context
    v_21190 = (*qfn1(fn))(fn, v_21190);
    env = stack[-1];
    v_21190 = stack[0];
    v_21190 = qcdr(v_21190);
    stack[0] = v_21190;
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 1)) = v_21190; // parser_action_table
    v_21190 = stack[0];
    v_21190 = qcdr(v_21190);
    stack[0] = v_21190;
    v_21190 = qcar(v_21190);
    v_21191 = v_21190;
    v_21190 = v_21191;
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 2)) = v_21190; // reduction_fn
    v_21190 = v_21191;
    v_21190 = qcdr(v_21190);
    v_21191 = v_21190;
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 3)) = v_21190; // reduction_rhs_n
    v_21190 = v_21191;
    v_21190 = qcdr(v_21190);
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 4)) = v_21190; // reduction_lhs
    v_21190 = stack[0];
    v_21190 = qcdr(v_21190);
    stack[0] = v_21190;
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 5)) = v_21190; // parser_goto_table
    v_21190 = stack[0];
    v_21190 = qcdr(v_21190);
    stack[0] = v_21190;
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 6)) = v_21190; // nonterminal_codes
    v_21190 = stack[0];
    v_21190 = qcdr(v_21190);
    v_21190 = qcar(v_21190);
    qvalue(elt(env, 7)) = v_21190; // terminal_codes
    v_21190 = nil;
    return onevalue(v_21190);
}



// Code for sq_member

static LispObject CC_sq_member(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21182, v_21183;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
    goto v_21169;
v_21165:
    v_21183 = stack[-1];
    goto v_21166;
v_21167:
    v_21182 = stack[0];
    v_21182 = qcar(v_21182);
    goto v_21168;
v_21169:
    goto v_21165;
v_21166:
    goto v_21167;
v_21168:
    fn = elt(env, 1); // sf_member
    v_21182 = (*qfn2(fn))(fn, v_21183, v_21182);
    env = stack[-2];
    if (v_21182 == nil) goto v_21163;
    else goto v_21162;
v_21163:
    goto v_21178;
v_21174:
    v_21183 = stack[-1];
    goto v_21175;
v_21176:
    v_21182 = stack[0];
    v_21182 = qcdr(v_21182);
    goto v_21177;
v_21178:
    goto v_21174;
v_21175:
    goto v_21176;
v_21177:
    {
        fn = elt(env, 1); // sf_member
        return (*qfn2(fn))(fn, v_21183, v_21182);
    }
v_21162:
    return onevalue(v_21182);
}



// Code for mri_ofsf2mriat

static LispObject CC_mri_ofsf2mriat(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21175, v_21176, v_21177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21175 = v_21159;
    v_21176 = v_21158;
// end of prologue
    goto v_21168;
v_21162:
    v_21177 = v_21176;
    v_21177 = qcar(v_21177);
    goto v_21163;
v_21164:
    v_21176 = qcdr(v_21176);
    v_21176 = qcar(v_21176);
    goto v_21165;
v_21166:
    goto v_21167;
v_21168:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    goto v_21166;
v_21167:
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_21177, v_21176, v_21175);
    }
}



// Code for rl_surep

static LispObject CC_rl_surep(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21176, v_21177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21176 = v_21159;
    v_21177 = v_21158;
// end of prologue
    goto v_21166;
v_21162:
    stack[0] = qvalue(elt(env, 1)); // rl_surep!*
    goto v_21163;
v_21164:
    goto v_21173;
v_21169:
    goto v_21170;
v_21171:
    goto v_21172;
v_21173:
    goto v_21169;
v_21170:
    goto v_21171;
v_21172:
    v_21176 = list2(v_21177, v_21176);
    env = stack[-1];
    goto v_21165;
v_21166:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    {
        LispObject v_21179 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21179, v_21176);
    }
}



// Code for sfto_b!:ordexp

static LispObject CC_sfto_bTordexp(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21201, v_21202;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
v_21163:
    v_21201 = stack[-1];
    if (v_21201 == nil) goto v_21166;
    else goto v_21167;
v_21166:
    v_21201 = lisp_true;
    goto v_21162;
v_21167:
    goto v_21177;
v_21173:
    v_21201 = stack[-1];
    v_21202 = qcar(v_21201);
    goto v_21174;
v_21175:
    v_21201 = stack[0];
    v_21201 = qcar(v_21201);
    goto v_21176;
v_21177:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    v_21201 = (LispObject)greaterp2(v_21202, v_21201);
    v_21201 = v_21201 ? lisp_true : nil;
    env = stack[-2];
    if (v_21201 == nil) goto v_21171;
    v_21201 = lisp_true;
    goto v_21162;
v_21171:
    goto v_21189;
v_21185:
    v_21201 = stack[-1];
    v_21202 = qcar(v_21201);
    goto v_21186;
v_21187:
    v_21201 = stack[0];
    v_21201 = qcar(v_21201);
    goto v_21188;
v_21189:
    goto v_21185;
v_21186:
    goto v_21187;
v_21188:
    if (equal(v_21202, v_21201)) goto v_21183;
    else goto v_21184;
v_21183:
    v_21201 = stack[-1];
    v_21201 = qcdr(v_21201);
    stack[-1] = v_21201;
    v_21201 = stack[0];
    v_21201 = qcdr(v_21201);
    stack[0] = v_21201;
    goto v_21163;
v_21184:
    v_21201 = nil;
    goto v_21162;
    v_21201 = nil;
v_21162:
    return onevalue(v_21201);
}



// Code for intervalom

static LispObject CC_intervalom(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21250, v_21251, v_21252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21158;
// end of prologue
    v_21250 = stack[-2];
    v_21250 = qcdr(v_21250);
    v_21250 = qcar(v_21250);
    stack[-3] = v_21250;
    v_21250 = stack[-2];
    v_21250 = qcar(v_21250);
    stack[-1] = v_21250;
    goto v_21179;
v_21175:
    v_21251 = stack[-1];
    goto v_21176;
v_21177:
    v_21250 = elt(env, 1); // lowupperlimit
    goto v_21178;
v_21179:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    if (v_21251 == v_21250) goto v_21173;
    else goto v_21174;
v_21173:
    v_21250 = elt(env, 2); // integer_interval
    stack[-1] = v_21250;
    v_21250 = nil;
    stack[-3] = v_21250;
    goto v_21191;
v_21185:
    v_21250 = stack[-2];
    v_21252 = qcar(v_21250);
    goto v_21186;
v_21187:
    v_21251 = nil;
    goto v_21188;
v_21189:
    v_21250 = stack[-2];
    v_21250 = qcdr(v_21250);
    goto v_21190;
v_21191:
    goto v_21185;
v_21186:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
    v_21250 = list2star(v_21252, v_21251, v_21250);
    env = stack[-4];
    stack[-2] = v_21250;
    goto v_21172;
v_21174:
v_21172:
    goto v_21201;
v_21197:
    v_21251 = stack[-1];
    goto v_21198;
v_21199:
    v_21250 = qvalue(elt(env, 3)); // valid_om!*
    goto v_21200;
v_21201:
    goto v_21197;
v_21198:
    goto v_21199;
v_21200:
    v_21250 = Lassoc(nil, v_21251, v_21250);
    v_21250 = qcdr(v_21250);
    v_21250 = qcar(v_21250);
    stack[0] = v_21250;
    v_21250 = stack[-3];
    if (v_21250 == nil) goto v_21210;
    goto v_21216;
v_21212:
    v_21250 = stack[-3];
    v_21250 = qcar(v_21250);
    v_21250 = qcdr(v_21250);
    v_21250 = qcar(v_21250);
    v_21251 = Lintern(nil, v_21250);
    env = stack[-4];
    goto v_21213;
v_21214:
    v_21250 = qvalue(elt(env, 4)); // interval!*
    goto v_21215;
v_21216:
    goto v_21212;
v_21213:
    goto v_21214;
v_21215:
    v_21250 = Lassoc(nil, v_21251, v_21250);
    v_21250 = qcdr(v_21250);
    v_21250 = qcar(v_21250);
    stack[-1] = v_21250;
    goto v_21208;
v_21210:
v_21208:
    v_21250 = elt(env, 5); // "<OMA>"
    fn = elt(env, 10); // printout
    v_21250 = (*qfn1(fn))(fn, v_21250);
    env = stack[-4];
    v_21250 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_21250 = (*qfn1(fn))(fn, v_21250);
    env = stack[-4];
    v_21250 = elt(env, 6); // "<OMS cd="""
    fn = elt(env, 10); // printout
    v_21250 = (*qfn1(fn))(fn, v_21250);
    env = stack[-4];
    v_21250 = stack[0];
    v_21250 = Lprinc(nil, v_21250);
    env = stack[-4];
    v_21250 = elt(env, 7); // """ name="""
    v_21250 = Lprinc(nil, v_21250);
    env = stack[-4];
    v_21250 = stack[-1];
    v_21250 = Lprinc(nil, v_21250);
    env = stack[-4];
    v_21250 = elt(env, 8); // """/>"
    v_21250 = Lprinc(nil, v_21250);
    env = stack[-4];
    v_21250 = stack[-2];
    v_21250 = qcdr(v_21250);
    v_21250 = qcdr(v_21250);
    fn = elt(env, 12); // multiom
    v_21250 = (*qfn1(fn))(fn, v_21250);
    env = stack[-4];
    v_21250 = nil;
    fn = elt(env, 11); // indent!*
    v_21250 = (*qfn1(fn))(fn, v_21250);
    env = stack[-4];
    v_21250 = elt(env, 9); // "</OMA>"
    fn = elt(env, 10); // printout
    v_21250 = (*qfn1(fn))(fn, v_21250);
    v_21250 = nil;
    return onevalue(v_21250);
}



// Code for greatertype

static LispObject CC_greatertype(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21348, v_21349, v_21350;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_21159;
    stack[-6] = v_21158;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_21175;
v_21171:
    v_21348 = qvalue(elt(env, 1)); // optlang!*
    if (v_21348 == nil) goto v_21179;
    v_21348 = qvalue(elt(env, 1)); // optlang!*
    v_21349 = v_21348;
    goto v_21177;
v_21179:
    v_21348 = elt(env, 2); // fortran
    v_21349 = v_21348;
    goto v_21177;
    v_21349 = nil;
v_21177:
    goto v_21172;
v_21173:
    v_21348 = elt(env, 3); // conversion
    goto v_21174;
v_21175:
    goto v_21171;
v_21172:
    goto v_21173;
v_21174:
    v_21348 = get(v_21349, v_21348);
    env = stack[-8];
    fn = elt(env, 4); // eval
    v_21348 = (*qfn1(fn))(fn, v_21348);
    env = stack[-8];
    stack[-7] = v_21348;
    goto v_21194;
v_21190:
    v_21348 = stack[-7];
    v_21349 = qcar(v_21348);
    goto v_21191;
v_21192:
    v_21348 = stack[-5];
    goto v_21193;
v_21194:
    goto v_21190;
v_21191:
    goto v_21192;
v_21193:
    if (equal(v_21349, v_21348)) goto v_21188;
    else goto v_21189;
v_21188:
    v_21348 = lisp_true;
    stack[-1] = v_21348;
    goto v_21187;
v_21189:
    goto v_21205;
v_21201:
    v_21348 = stack[-7];
    v_21349 = qcar(v_21348);
    goto v_21202;
v_21203:
    v_21348 = stack[-6];
    goto v_21204;
v_21205:
    goto v_21201;
v_21202:
    goto v_21203;
v_21204:
    if (equal(v_21349, v_21348)) goto v_21199;
    else goto v_21200;
v_21199:
    v_21348 = nil;
    stack[-1] = v_21348;
    goto v_21187;
v_21200:
v_21214:
    v_21348 = stack[-7];
    v_21348 = qcdr(v_21348);
    stack[-7] = v_21348;
    if (v_21348 == nil) goto v_21217;
    v_21348 = stack[-4];
    if (v_21348 == nil) goto v_21222;
    else goto v_21217;
v_21222:
    goto v_21218;
v_21217:
    goto v_21213;
v_21218:
    v_21348 = stack[-7];
    v_21348 = qcar(v_21348);
    v_21350 = v_21348;
v_21229:
    v_21348 = v_21350;
    if (v_21348 == nil) goto v_21232;
    v_21348 = stack[-2];
    if (v_21348 == nil) goto v_21236;
    else goto v_21232;
v_21236:
    goto v_21233;
v_21232:
    goto v_21228;
v_21233:
    goto v_21247;
v_21243:
    v_21348 = v_21350;
    v_21349 = qcar(v_21348);
    goto v_21244;
v_21245:
    v_21348 = stack[-6];
    goto v_21246;
v_21247:
    goto v_21243;
v_21244:
    goto v_21245;
v_21246:
    if (equal(v_21349, v_21348)) goto v_21241;
    else goto v_21242;
v_21241:
    v_21348 = lisp_true;
    stack[-3] = v_21348;
    goto v_21240;
v_21242:
v_21240:
    goto v_21260;
v_21256:
    v_21348 = v_21350;
    v_21349 = qcar(v_21348);
    goto v_21257;
v_21258:
    v_21348 = stack[-5];
    goto v_21259;
v_21260:
    goto v_21256;
v_21257:
    goto v_21258;
v_21259:
    if (equal(v_21349, v_21348)) goto v_21254;
    else goto v_21255;
v_21254:
    v_21348 = lisp_true;
    stack[-2] = v_21348;
    goto v_21253;
v_21255:
    v_21348 = v_21350;
    v_21348 = qcdr(v_21348);
    v_21350 = v_21348;
    goto v_21253;
v_21253:
    goto v_21229;
v_21228:
    v_21348 = stack[-2];
    if (v_21348 == nil) goto v_21272;
    v_21348 = v_21350;
    v_21348 = qcdr(v_21348);
    v_21350 = v_21348;
v_21278:
    v_21348 = v_21350;
    if (v_21348 == nil) goto v_21281;
    v_21348 = stack[-1];
    if (v_21348 == nil) goto v_21285;
    else goto v_21281;
v_21285:
    goto v_21282;
v_21281:
    goto v_21277;
v_21282:
    goto v_21296;
v_21292:
    v_21348 = v_21350;
    v_21349 = qcar(v_21348);
    goto v_21293;
v_21294:
    v_21348 = stack[-6];
    goto v_21295;
v_21296:
    goto v_21292;
v_21293:
    goto v_21294;
v_21295:
    if (equal(v_21349, v_21348)) goto v_21290;
    else goto v_21291;
v_21290:
    v_21348 = lisp_true;
    stack[-1] = v_21348;
    stack[-3] = v_21348;
    goto v_21289;
v_21291:
    v_21348 = v_21350;
    v_21348 = qcdr(v_21348);
    v_21350 = v_21348;
    goto v_21289;
v_21289:
    goto v_21278;
v_21277:
    goto v_21270;
v_21272:
v_21270:
    v_21348 = stack[-3];
    if (v_21348 == nil) goto v_21310;
    v_21348 = stack[-2];
    if (v_21348 == nil) goto v_21313;
    else goto v_21310;
v_21313:
    goto v_21308;
v_21310:
    v_21348 = stack[-3];
    if (v_21348 == nil) goto v_21318;
    else goto v_21319;
v_21318:
    v_21348 = stack[-2];
    goto v_21317;
v_21319:
    v_21348 = nil;
    goto v_21317;
    v_21348 = nil;
v_21317:
    if (v_21348 == nil) goto v_21315;
    else goto v_21308;
v_21315:
    goto v_21309;
v_21308:
    goto v_21330;
v_21326:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_21327;
v_21328:
    goto v_21337;
v_21333:
    v_21349 = stack[-6];
    goto v_21334;
v_21335:
    v_21348 = stack[-5];
    goto v_21336;
v_21337:
    goto v_21333;
v_21334:
    goto v_21335;
v_21336:
    v_21348 = cons(v_21349, v_21348);
    env = stack[-8];
    goto v_21329;
v_21330:
    goto v_21326;
v_21327:
    goto v_21328;
v_21329:
    fn = elt(env, 5); // typerror
    v_21348 = (*qfn2(fn))(fn, stack[0], v_21348);
    env = stack[-8];
    goto v_21307;
v_21309:
    v_21348 = stack[-3];
    if (v_21348 == nil) goto v_21341;
    v_21348 = stack[-2];
    if (v_21348 == nil) goto v_21341;
    v_21348 = lisp_true;
    stack[-4] = v_21348;
    goto v_21307;
v_21341:
v_21307:
    goto v_21214;
v_21213:
    goto v_21187;
v_21187:
    v_21348 = stack[-1];
    return onevalue(v_21348);
}



// Code for groebspolynom3

static LispObject CC_groebspolynom3(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21175, v_21176;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21175 = v_21159;
    v_21176 = v_21158;
// end of prologue
    goto v_21169;
v_21165:
    goto v_21166;
v_21167:
    goto v_21168;
v_21169:
    goto v_21165;
v_21166:
    goto v_21167;
v_21168:
    fn = elt(env, 1); // groebspolynom4
    v_21175 = (*qfn2(fn))(fn, v_21176, v_21175);
    env = stack[-1];
    stack[0] = v_21175;
    v_21175 = stack[0];
    fn = elt(env, 2); // groebsavelterm
    v_21175 = (*qfn1(fn))(fn, v_21175);
    v_21175 = stack[0];
    return onevalue(v_21175);
}



// Code for exdfprn

static LispObject CC_exdfprn(LispObject env,
                         LispObject v_21158)
{
    env = qenv(env);
    LispObject v_21166;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21158);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21158;
// end of prologue
    v_21166 = elt(env, 1); // "d"
    fn = elt(env, 2); // prin2!*
    v_21166 = (*qfn1(fn))(fn, v_21166);
    env = stack[-1];
    v_21166 = stack[0];
    v_21166 = qcdr(v_21166);
    v_21166 = qcar(v_21166);
    {
        fn = elt(env, 3); // rembras
        return (*qfn1(fn))(fn, v_21166);
    }
}



// Code for multiply!-by!-power!-of!-ten

static LispObject CC_multiplyKbyKpowerKofKten(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21243, v_21244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21159;
    stack[-1] = v_21158;
// end of prologue
    goto v_21170;
v_21166:
    v_21244 = stack[0];
    goto v_21167;
v_21168:
    v_21243 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21169;
v_21170:
    goto v_21166;
v_21167:
    goto v_21168;
v_21169:
    v_21243 = (LispObject)lessp2(v_21244, v_21243);
    v_21243 = v_21243 ? lisp_true : nil;
    env = stack[-3];
    if (v_21243 == nil) goto v_21164;
    v_21243 = elt(env, 0); // multiply!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21243);
    }
v_21164:
    v_21243 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21243;
v_21181:
    goto v_21191;
v_21187:
    v_21244 = stack[0];
    goto v_21188;
v_21189:
    v_21243 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21190;
v_21191:
    goto v_21187;
v_21188:
    goto v_21189;
v_21190:
    v_21243 = (LispObject)greaterp2(v_21244, v_21243);
    v_21243 = v_21243 ? lisp_true : nil;
    env = stack[-3];
    if (v_21243 == nil) goto v_21184;
    else goto v_21185;
v_21184:
    goto v_21180;
v_21185:
    v_21243 = stack[0];
    v_21243 = Levenp(nil, v_21243);
    env = stack[-3];
    if (v_21243 == nil) goto v_21197;
    else goto v_21198;
v_21197:
    goto v_21207;
v_21203:
    v_21244 = stack[-1];
    goto v_21204;
v_21205:
    v_21243 = stack[-2];
    goto v_21206;
v_21207:
    goto v_21203;
v_21204:
    goto v_21205;
v_21206:
    fn = elt(env, 4); // times!:
    v_21243 = (*qfn2(fn))(fn, v_21244, v_21243);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21243 = (*qfn1(fn))(fn, v_21243);
    env = stack[-3];
    stack[-1] = v_21243;
    goto v_21196;
v_21198:
v_21196:
    goto v_21215;
v_21211:
    v_21244 = stack[0];
    goto v_21212;
v_21213:
    v_21243 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21214;
v_21215:
    goto v_21211;
v_21212:
    goto v_21213;
v_21214:
    fn = elt(env, 6); // lshift
    v_21243 = (*qfn2(fn))(fn, v_21244, v_21243);
    env = stack[-3];
    stack[0] = v_21243;
    goto v_21224;
v_21220:
    goto v_21230;
v_21226:
    v_21244 = stack[-2];
    goto v_21227;
v_21228:
    v_21243 = stack[-2];
    goto v_21229;
v_21230:
    goto v_21226;
v_21227:
    goto v_21228;
v_21229:
    fn = elt(env, 4); // times!:
    v_21244 = (*qfn2(fn))(fn, v_21244, v_21243);
    env = stack[-3];
    goto v_21221;
v_21222:
    v_21243 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21223;
v_21224:
    goto v_21220;
v_21221:
    goto v_21222;
v_21223:
    fn = elt(env, 7); // cut!:mt
    v_21243 = (*qfn2(fn))(fn, v_21244, v_21243);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21243 = (*qfn1(fn))(fn, v_21243);
    env = stack[-3];
    stack[-2] = v_21243;
    goto v_21181;
v_21180:
    goto v_21240;
v_21236:
    v_21244 = stack[-1];
    goto v_21237;
v_21238:
    v_21243 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21239;
v_21240:
    goto v_21236;
v_21237:
    goto v_21238;
v_21239:
    fn = elt(env, 7); // cut!:mt
    v_21243 = (*qfn2(fn))(fn, v_21244, v_21243);
    env = stack[-3];
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_21243);
    }
    v_21243 = nil;
    return onevalue(v_21243);
}



// Code for calc_den_tar

static LispObject CC_calc_den_tar(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21186, v_21187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21186 = v_21159;
    v_21187 = v_21158;
// end of prologue
    goto v_21166;
v_21162:
    goto v_21163;
v_21164:
    goto v_21165;
v_21166:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    fn = elt(env, 1); // denlist
    v_21186 = (*qfn2(fn))(fn, v_21187, v_21186);
    env = stack[0];
    v_21187 = v_21186;
    v_21186 = v_21187;
    if (v_21186 == nil) goto v_21172;
    else goto v_21173;
v_21172:
    v_21186 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21171;
v_21173:
    v_21186 = v_21187;
    v_21186 = qcdr(v_21186);
    if (v_21186 == nil) goto v_21176;
    else goto v_21177;
v_21176:
    v_21186 = v_21187;
    v_21186 = qcar(v_21186);
    goto v_21171;
v_21177:
    v_21186 = v_21187;
    {
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(fn, v_21186);
    }
    v_21186 = nil;
v_21171:
    return onevalue(v_21186);
}



// Code for log_freevars

static LispObject CC_log_freevars(LispObject env,
                         LispObject v_21158, LispObject v_21159)
{
    env = qenv(env);
    LispObject v_21407, v_21408, v_21409;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21158,v_21159);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21159;
    v_21408 = v_21158;
// end of prologue
    v_21407 = stack[0];
    if (!consp(v_21407)) goto v_21163;
    else goto v_21164;
v_21163:
    v_21407 = stack[0];
    if (symbolp(v_21407)) goto v_21173;
    v_21407 = lisp_true;
    goto v_21171;
v_21173:
    goto v_21185;
v_21181:
    v_21407 = stack[0];
    goto v_21182;
v_21183:
    goto v_21184;
v_21185:
    goto v_21181;
v_21182:
    goto v_21183;
v_21184:
    v_21407 = Lmember(nil, v_21407, v_21408);
    if (v_21407 == nil) goto v_21180;
    else goto v_21179;
v_21180:
    v_21407 = stack[0];
    v_21407 = Lsymbol_globalp(nil, v_21407);
    env = stack[-1];
    if (v_21407 == nil) goto v_21191;
    else goto v_21190;
v_21191:
    v_21407 = stack[0];
    v_21407 = Lsymbol_specialp(nil, v_21407);
    env = stack[-1];
    if (v_21407 == nil) goto v_21196;
    else goto v_21195;
v_21196:
    goto v_21207;
v_21203:
    v_21408 = stack[0];
    goto v_21204;
v_21205:
    v_21407 = elt(env, 1); // constant!?
    goto v_21206;
v_21207:
    goto v_21203;
v_21204:
    goto v_21205;
v_21206:
    v_21407 = get(v_21408, v_21407);
    env = stack[-1];
    if (v_21407 == nil) goto v_21201;
    else goto v_21200;
v_21201:
    v_21407 = stack[0];
    if (v_21407 == nil) goto v_21212;
    else goto v_21213;
v_21212:
    v_21407 = lisp_true;
    goto v_21211;
v_21213:
    goto v_21222;
v_21218:
    v_21408 = stack[0];
    goto v_21219;
v_21220:
    v_21407 = lisp_true;
    goto v_21221;
v_21222:
    goto v_21218;
v_21219:
    goto v_21220;
v_21221:
    v_21407 = (equal(v_21408, v_21407) ? lisp_true : nil);
    goto v_21211;
    v_21407 = nil;
v_21211:
v_21200:
v_21195:
v_21190:
v_21179:
    goto v_21171;
    v_21407 = nil;
v_21171:
    if (v_21407 == nil) goto v_21169;
    v_21407 = nil;
    goto v_21167;
v_21169:
    v_21407 = Lposn(nil, 0);
    env = stack[-1];
    v_21407 = (LispObject)zerop(v_21407);
    v_21407 = v_21407 ? lisp_true : nil;
    env = stack[-1];
    if (v_21407 == nil) goto v_21231;
    else goto v_21232;
v_21231:
    v_21407 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_21230;
v_21232:
v_21230:
    v_21407 = elt(env, 2); // "+++ Use of free variable in smacro/inline body: "
    v_21407 = Lprinc(nil, v_21407);
    env = stack[-1];
    v_21407 = stack[0];
    v_21407 = Lprint(nil, v_21407);
    env = stack[-1];
    v_21407 = elt(env, 3); // "+++ Macro was: "
    v_21407 = Lprinc(nil, v_21407);
    env = stack[-1];
    v_21407 = qvalue(elt(env, 4)); // inlineinfo
    v_21407 = Lprint(nil, v_21407);
    v_21407 = lisp_true;
    goto v_21167;
    v_21407 = nil;
v_21167:
    goto v_21162;
v_21164:
    goto v_21256;
v_21252:
    v_21409 = stack[0];
    goto v_21253;
v_21254:
    v_21407 = elt(env, 5); // quote
    goto v_21255;
v_21256:
    goto v_21252;
v_21253:
    goto v_21254;
v_21255:
    if (!consp(v_21409)) goto v_21250;
    v_21409 = qcar(v_21409);
    if (v_21409 == v_21407) goto v_21249;
    else goto v_21250;
v_21249:
    v_21407 = lisp_true;
    goto v_21248;
v_21250:
    goto v_21275;
v_21271:
    v_21409 = stack[0];
    goto v_21272;
v_21273:
    v_21407 = elt(env, 6); // function
    goto v_21274;
v_21275:
    goto v_21271;
v_21272:
    goto v_21273;
v_21274:
    if (!consp(v_21409)) goto v_21269;
    v_21409 = qcar(v_21409);
    if (v_21409 == v_21407) goto v_21268;
    else goto v_21269;
v_21268:
    v_21407 = stack[0];
    v_21407 = qcdr(v_21407);
    v_21407 = qcar(v_21407);
    v_21407 = (consp(v_21407) ? nil : lisp_true);
    goto v_21267;
v_21269:
    v_21407 = nil;
    goto v_21267;
    v_21407 = nil;
v_21267:
    if (v_21407 == nil) goto v_21265;
    v_21407 = lisp_true;
    goto v_21263;
v_21265:
    goto v_21293;
v_21289:
    v_21409 = stack[0];
    goto v_21290;
v_21291:
    v_21407 = elt(env, 7); // go
    goto v_21292;
v_21293:
    goto v_21289;
v_21290:
    goto v_21291;
v_21292:
    v_21407 = Leqcar(nil, v_21409, v_21407);
    env = stack[-1];
    goto v_21263;
    v_21407 = nil;
v_21263:
    goto v_21248;
    v_21407 = nil;
v_21248:
    if (v_21407 == nil) goto v_21246;
    v_21407 = nil;
    goto v_21162;
v_21246:
    goto v_21304;
v_21300:
    v_21409 = stack[0];
    goto v_21301;
v_21302:
    v_21407 = elt(env, 8); // prog
    goto v_21303;
v_21304:
    goto v_21300;
v_21301:
    goto v_21302;
v_21303:
    if (!consp(v_21409)) goto v_21298;
    v_21409 = qcar(v_21409);
    if (v_21409 == v_21407) goto v_21297;
    else goto v_21298;
v_21297:
    goto v_21314;
v_21308:
    goto v_21320;
v_21316:
    v_21407 = stack[0];
    v_21407 = qcdr(v_21407);
    v_21407 = qcar(v_21407);
    goto v_21317;
v_21318:
    goto v_21319;
v_21320:
    goto v_21316;
v_21317:
    goto v_21318;
v_21319:
    v_21409 = Lappend(nil, v_21407, v_21408);
    env = stack[-1];
    goto v_21309;
v_21310:
    v_21407 = stack[0];
    v_21408 = qcdr(v_21407);
    goto v_21311;
v_21312:
    v_21407 = lisp_true;
    goto v_21313;
v_21314:
    goto v_21308;
v_21309:
    goto v_21310;
v_21311:
    goto v_21312;
v_21313:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21409, v_21408, v_21407);
    }
v_21298:
    goto v_21335;
v_21331:
    v_21409 = stack[0];
    goto v_21332;
v_21333:
    v_21407 = elt(env, 9); // lambda
    goto v_21334;
v_21335:
    goto v_21331;
v_21332:
    goto v_21333;
v_21334:
    if (!consp(v_21409)) goto v_21329;
    v_21409 = qcar(v_21409);
    if (v_21409 == v_21407) goto v_21328;
    else goto v_21329;
v_21328:
    goto v_21345;
v_21339:
    goto v_21351;
v_21347:
    v_21407 = stack[0];
    v_21407 = qcdr(v_21407);
    v_21407 = qcar(v_21407);
    goto v_21348;
v_21349:
    goto v_21350;
v_21351:
    goto v_21347;
v_21348:
    goto v_21349;
v_21350:
    v_21409 = Lappend(nil, v_21407, v_21408);
    env = stack[-1];
    goto v_21340;
v_21341:
    v_21407 = stack[0];
    v_21408 = qcdr(v_21407);
    goto v_21342;
v_21343:
    v_21407 = nil;
    goto v_21344;
v_21345:
    goto v_21339;
v_21340:
    goto v_21341;
v_21342:
    goto v_21343;
v_21344:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21409, v_21408, v_21407);
    }
v_21329:
    goto v_21366;
v_21362:
    v_21409 = stack[0];
    goto v_21363;
v_21364:
    v_21407 = elt(env, 10); // cond
    goto v_21365;
v_21366:
    goto v_21362;
v_21363:
    goto v_21364;
v_21365:
    if (!consp(v_21409)) goto v_21360;
    v_21409 = qcar(v_21409);
    if (v_21409 == v_21407) goto v_21359;
    else goto v_21360;
v_21359:
    goto v_21374;
v_21370:
    goto v_21371;
v_21372:
    v_21407 = stack[0];
    v_21407 = qcdr(v_21407);
    goto v_21373;
v_21374:
    goto v_21370;
v_21371:
    goto v_21372;
v_21373:
    {
        fn = elt(env, 12); // log_freevars_list_list
        return (*qfn2(fn))(fn, v_21408, v_21407);
    }
v_21360:
    v_21407 = stack[0];
    v_21407 = qcar(v_21407);
    if (!consp(v_21407)) goto v_21378;
    else goto v_21379;
v_21378:
    goto v_21389;
v_21383:
    v_21409 = v_21408;
    goto v_21384;
v_21385:
    v_21407 = stack[0];
    v_21408 = qcdr(v_21407);
    goto v_21386;
v_21387:
    v_21407 = nil;
    goto v_21388;
v_21389:
    goto v_21383;
v_21384:
    goto v_21385;
v_21386:
    goto v_21387;
v_21388:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21409, v_21408, v_21407);
    }
v_21379:
    goto v_21403;
v_21397:
    v_21409 = v_21408;
    goto v_21398;
v_21399:
    v_21408 = stack[0];
    goto v_21400;
v_21401:
    v_21407 = nil;
    goto v_21402;
v_21403:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21409, v_21408, v_21407);
    }
    v_21407 = nil;
v_21162:
    return onevalue(v_21407);
}



// Code for prepsq!*1

static LispObject CC_prepsqH1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21869, v_21870, v_21871;
    LispObject fn;
    LispObject v_21160, v_21159, v_21158;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prepsq*1");
    va_start(aa, nargs);
    v_21158 = va_arg(aa, LispObject);
    v_21159 = va_arg(aa, LispObject);
    v_21160 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21160,v_21159,v_21158);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21158,v_21159,v_21160);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21160;
    stack[-5] = v_21159;
    stack[-6] = v_21158;
// end of prologue
    v_21869 = stack[-6];
    if (!consp(v_21869)) goto v_21177;
    else goto v_21178;
v_21177:
    v_21869 = lisp_true;
    goto v_21176;
v_21178:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = (consp(v_21869) ? nil : lisp_true);
    goto v_21176;
    v_21869 = nil;
v_21176:
    if (v_21869 == nil) goto v_21173;
    else goto v_21174;
v_21173:
    goto v_21193;
v_21189:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21190;
v_21191:
    v_21869 = qvalue(elt(env, 1)); // factors!*
    goto v_21192;
v_21193:
    goto v_21189;
v_21190:
    goto v_21191;
v_21192:
    v_21869 = Lmember(nil, v_21870, v_21869);
    if (v_21869 == nil) goto v_21188;
    else goto v_21187;
v_21188:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    if (!consp(v_21869)) goto v_21203;
    goto v_21212;
v_21208:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21209;
v_21210:
    v_21869 = qvalue(elt(env, 1)); // factors!*
    goto v_21211;
v_21212:
    goto v_21208;
v_21209:
    goto v_21210;
v_21211:
    v_21869 = Lmember(nil, v_21870, v_21869);
    goto v_21201;
v_21203:
    v_21869 = nil;
    goto v_21201;
    v_21869 = nil;
v_21201:
v_21187:
    goto v_21172;
v_21174:
    v_21869 = nil;
    goto v_21172;
    v_21869 = nil;
v_21172:
    if (v_21869 == nil) goto v_21170;
    goto v_21231;
v_21227:
    goto v_21240;
v_21236:
    v_21870 = stack[-5];
    goto v_21237;
v_21238:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21239;
v_21240:
    goto v_21236;
v_21237:
    goto v_21238;
v_21239:
    if (v_21870 == v_21869) goto v_21234;
    else goto v_21235;
v_21234:
    goto v_21248;
v_21244:
    goto v_21254;
v_21250:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21870 = qcdr(v_21869);
    goto v_21251;
v_21252:
    v_21869 = stack[-5];
    goto v_21253;
v_21254:
    goto v_21250;
v_21251:
    goto v_21252;
v_21253:
    stack[0] = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21245;
v_21246:
    goto v_21264;
v_21260:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21261;
v_21262:
    v_21869 = stack[-4];
    goto v_21263;
v_21264:
    goto v_21260;
v_21261:
    goto v_21262;
v_21263:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21247;
v_21248:
    goto v_21244;
v_21245:
    goto v_21246;
v_21247:
    fn = elt(env, 10); // prepsq!*0
    v_21869 = (*qfn2(fn))(fn, stack[0], v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21233;
v_21235:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21869 = qcdr(v_21869);
    stack[-2] = v_21869;
    v_21869 = stack[-5];
    stack[-1] = v_21869;
    goto v_21287;
v_21283:
    goto v_21293;
v_21289:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21290;
v_21291:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21292;
v_21293:
    goto v_21289;
v_21290:
    goto v_21291;
v_21292:
    fn = elt(env, 11); // to
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21284;
v_21285:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21286;
v_21287:
    goto v_21283;
v_21284:
    goto v_21285;
v_21286:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    v_21869 = ncons(v_21869);
    env = stack[-8];
    stack[0] = v_21869;
v_21302:
    goto v_21312;
v_21308:
    v_21870 = stack[-1];
    goto v_21309;
v_21310:
    v_21869 = stack[0];
    goto v_21311;
v_21312:
    goto v_21308;
v_21309:
    goto v_21310;
v_21311:
    fn = elt(env, 12); // quotfm
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-7] = v_21869;
    if (v_21869 == nil) goto v_21305;
    else goto v_21306;
v_21305:
    goto v_21301;
v_21306:
    v_21869 = stack[-7];
    stack[-1] = v_21869;
    v_21869 = stack[-2];
    v_21869 = sub1(v_21869);
    env = stack[-8];
    stack[-2] = v_21869;
    goto v_21302;
v_21301:
    goto v_21324;
v_21320:
    goto v_21330;
v_21326:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21870 = qcdr(v_21869);
    goto v_21327;
v_21328:
    v_21869 = stack[-1];
    goto v_21329;
v_21330:
    goto v_21326;
v_21327:
    goto v_21328;
v_21329:
    stack[0] = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21321;
v_21322:
    goto v_21344;
v_21340:
    v_21870 = stack[-2];
    goto v_21341;
v_21342:
    v_21869 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21343;
v_21344:
    goto v_21340;
v_21341:
    goto v_21342;
v_21343:
    v_21869 = (LispObject)greaterp2(v_21870, v_21869);
    v_21869 = v_21869 ? lisp_true : nil;
    env = stack[-8];
    if (v_21869 == nil) goto v_21338;
    goto v_21352;
v_21348:
    goto v_21358;
v_21354:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21355;
v_21356:
    v_21869 = stack[-2];
    goto v_21357;
v_21358:
    goto v_21354;
v_21355:
    goto v_21356;
v_21357:
    fn = elt(env, 11); // to
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21349;
v_21350:
    v_21869 = stack[-4];
    goto v_21351;
v_21352:
    goto v_21348;
v_21349:
    goto v_21350;
v_21351:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21336;
v_21338:
    goto v_21372;
v_21368:
    v_21870 = stack[-2];
    goto v_21369;
v_21370:
    v_21869 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21371;
v_21372:
    goto v_21368;
v_21369:
    goto v_21370;
v_21371:
    v_21869 = (LispObject)lessp2(v_21870, v_21869);
    v_21869 = v_21869 ? lisp_true : nil;
    env = stack[-8];
    if (v_21869 == nil) goto v_21366;
    goto v_21380;
v_21376:
    goto v_21386;
v_21382:
    goto v_21394;
v_21388:
    v_21871 = elt(env, 2); // expt
    goto v_21389;
v_21390:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    v_21869 = qcar(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21391;
v_21392:
    v_21869 = stack[-2];
    goto v_21393;
v_21394:
    goto v_21388;
v_21389:
    goto v_21390;
v_21391:
    goto v_21392;
v_21393:
    v_21870 = list3(v_21871, v_21870, v_21869);
    env = stack[-8];
    goto v_21383;
v_21384:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21385;
v_21386:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    fn = elt(env, 13); // mksp
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21377;
v_21378:
    v_21869 = stack[-4];
    goto v_21379;
v_21380:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21336;
v_21366:
    v_21869 = stack[-4];
    goto v_21336;
    v_21869 = nil;
v_21336:
    goto v_21323;
v_21324:
    goto v_21320;
v_21321:
    goto v_21322;
v_21323:
    fn = elt(env, 10); // prepsq!*0
    v_21869 = (*qfn2(fn))(fn, stack[0], v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21233;
    stack[0] = nil;
v_21233:
    goto v_21228;
v_21229:
    goto v_21411;
v_21407:
    goto v_21417;
v_21413:
    v_21869 = stack[-6];
    v_21870 = qcdr(v_21869);
    goto v_21414;
v_21415:
    v_21869 = stack[-5];
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    v_21870 = cons(v_21870, v_21869);
    env = stack[-8];
    goto v_21408;
v_21409:
    v_21869 = stack[-4];
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    fn = elt(env, 10); // prepsq!*0
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21230;
v_21231:
    goto v_21227;
v_21228:
    goto v_21229;
v_21230:
    {
        LispObject v_21880 = stack[0];
        fn = elt(env, 14); // nconc!*
        return (*qfn2(fn))(fn, v_21880, v_21869);
    }
v_21170:
    v_21869 = stack[-5];
    if (!consp(v_21869)) goto v_21428;
    else goto v_21429;
v_21428:
    v_21869 = lisp_true;
    goto v_21427;
v_21429:
    v_21869 = stack[-5];
    v_21869 = qcar(v_21869);
    v_21869 = (consp(v_21869) ? nil : lisp_true);
    goto v_21427;
    v_21869 = nil;
v_21427:
    if (v_21869 == nil) goto v_21424;
    else goto v_21425;
v_21424:
    v_21869 = qvalue(elt(env, 3)); // kord!*
    stack[-3] = v_21869;
v_21440:
    v_21869 = stack[-3];
    if (v_21869 == nil) goto v_21444;
    else goto v_21445;
v_21444:
    goto v_21439;
v_21445:
    v_21869 = stack[-3];
    v_21869 = qcar(v_21869);
    stack[-2] = v_21869;
    v_21869 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_21869;
    goto v_21463;
v_21459:
    goto v_21469;
v_21465:
    v_21870 = stack[-2];
    goto v_21466;
v_21467:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21468;
v_21469:
    goto v_21465;
v_21466:
    goto v_21467;
v_21468:
    fn = elt(env, 11); // to
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21460;
v_21461:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21462;
v_21463:
    goto v_21459;
v_21460:
    goto v_21461;
v_21462:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    v_21869 = ncons(v_21869);
    env = stack[-8];
    stack[0] = v_21869;
v_21475:
    goto v_21485;
v_21481:
    v_21870 = stack[-5];
    goto v_21482;
v_21483:
    v_21869 = stack[0];
    goto v_21484;
v_21485:
    goto v_21481;
v_21482:
    goto v_21483;
v_21484:
    fn = elt(env, 12); // quotfm
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-7] = v_21869;
    if (v_21869 == nil) goto v_21478;
    else goto v_21479;
v_21478:
    goto v_21474;
v_21479:
    v_21869 = stack[-1];
    v_21869 = sub1(v_21869);
    env = stack[-8];
    stack[-1] = v_21869;
    v_21869 = stack[-7];
    stack[-5] = v_21869;
    goto v_21475;
v_21474:
    goto v_21501;
v_21497:
    v_21870 = stack[-1];
    goto v_21498;
v_21499:
    v_21869 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    v_21869 = (LispObject)lessp2(v_21870, v_21869);
    v_21869 = v_21869 ? lisp_true : nil;
    env = stack[-8];
    if (v_21869 == nil) goto v_21495;
    goto v_21509;
v_21505:
    goto v_21515;
v_21511:
    goto v_21523;
v_21517:
    v_21871 = elt(env, 2); // expt
    goto v_21518;
v_21519:
    v_21870 = stack[-2];
    goto v_21520;
v_21521:
    v_21869 = stack[-1];
    goto v_21522;
v_21523:
    goto v_21517;
v_21518:
    goto v_21519;
v_21520:
    goto v_21521;
v_21522:
    v_21870 = list3(v_21871, v_21870, v_21869);
    env = stack[-8];
    goto v_21512;
v_21513:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21514;
v_21515:
    goto v_21511;
v_21512:
    goto v_21513;
v_21514:
    fn = elt(env, 13); // mksp
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21506;
v_21507:
    v_21869 = stack[-4];
    goto v_21508;
v_21509:
    goto v_21505;
v_21506:
    goto v_21507;
v_21508:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    stack[-4] = v_21869;
    goto v_21493;
v_21495:
v_21493:
    v_21869 = stack[-3];
    v_21869 = qcdr(v_21869);
    stack[-3] = v_21869;
    goto v_21440;
v_21439:
    goto v_21423;
v_21425:
v_21423:
    v_21869 = stack[-6];
    fn = elt(env, 15); // kernlp
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    if (v_21869 == nil) goto v_21534;
    goto v_21542;
v_21538:
    v_21870 = stack[-4];
    goto v_21539;
v_21540:
    v_21869 = stack[-6];
    goto v_21541;
v_21542:
    goto v_21538;
v_21539:
    goto v_21540;
v_21541:
    fn = elt(env, 16); // mkkl
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    v_21869 = nil;
    stack[-4] = v_21869;
    goto v_21532;
v_21534:
v_21532:
    v_21869 = qvalue(elt(env, 4)); // dnl!*
    if (v_21869 == nil) goto v_21549;
    v_21869 = qvalue(elt(env, 5)); // !*allfac
    if (v_21869 == nil) goto v_21553;
    else goto v_21554;
v_21553:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21552;
v_21554:
    v_21869 = stack[-6];
    fn = elt(env, 17); // ckrn
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    goto v_21552;
    v_21869 = nil;
v_21552:
    stack[-1] = v_21869;
    goto v_21566;
v_21562:
    v_21870 = stack[-1];
    goto v_21563;
v_21564:
    v_21869 = qvalue(elt(env, 4)); // dnl!*
    goto v_21565;
v_21566:
    goto v_21562;
v_21563:
    goto v_21564;
v_21565:
    fn = elt(env, 18); // ckrn!*
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-7] = v_21869;
    goto v_21574;
v_21570:
    v_21870 = stack[-1];
    goto v_21571;
v_21572:
    v_21869 = stack[-7];
    goto v_21573;
v_21574:
    goto v_21570;
v_21571:
    goto v_21572;
v_21573:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21582;
v_21578:
    v_21870 = stack[-6];
    goto v_21579;
v_21580:
    v_21869 = stack[-7];
    goto v_21581;
v_21582:
    goto v_21578;
v_21579:
    goto v_21580;
v_21581:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    goto v_21590;
v_21586:
    v_21870 = stack[-5];
    goto v_21587;
v_21588:
    v_21869 = stack[-7];
    goto v_21589;
v_21590:
    goto v_21586;
v_21587:
    goto v_21588;
v_21589:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-5] = v_21869;
    goto v_21547;
v_21549:
v_21547:
    v_21869 = qvalue(elt(env, 6)); // upl!*
    if (v_21869 == nil) goto v_21596;
    v_21869 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21605;
v_21601:
    v_21870 = stack[0];
    goto v_21602;
v_21603:
    v_21869 = qvalue(elt(env, 6)); // upl!*
    goto v_21604;
v_21605:
    goto v_21601;
v_21602:
    goto v_21603;
v_21604:
    fn = elt(env, 18); // ckrn!*
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-7] = v_21869;
    goto v_21613;
v_21609:
    v_21870 = stack[0];
    goto v_21610;
v_21611:
    v_21869 = stack[-7];
    goto v_21612;
v_21613:
    goto v_21609;
v_21610:
    goto v_21611;
v_21612:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21621;
v_21617:
    v_21870 = stack[-6];
    goto v_21618;
v_21619:
    v_21869 = stack[-7];
    goto v_21620;
v_21621:
    goto v_21617;
v_21618:
    goto v_21619;
v_21620:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    goto v_21629;
v_21625:
    v_21870 = stack[-5];
    goto v_21626;
v_21627:
    v_21869 = stack[-7];
    goto v_21628;
v_21629:
    goto v_21625;
v_21626:
    goto v_21627;
v_21628:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-5] = v_21869;
    goto v_21594;
v_21596:
    v_21869 = qvalue(elt(env, 7)); // !*div
    if (v_21869 == nil) goto v_21633;
    v_21869 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21594;
v_21633:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_21869;
    goto v_21594;
v_21594:
    goto v_21646;
v_21642:
    stack[-1] = stack[-6];
    goto v_21643;
v_21644:
    goto v_21653;
v_21649:
    v_21870 = stack[-5];
    goto v_21650;
v_21651:
    v_21869 = stack[0];
    goto v_21652;
v_21653:
    goto v_21649;
v_21650:
    goto v_21651;
v_21652:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21645;
v_21646:
    goto v_21642;
v_21643:
    goto v_21644;
v_21645:
    v_21869 = cons(stack[-1], v_21869);
    env = stack[-8];
    fn = elt(env, 20); // canonsq
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    goto v_21661;
v_21657:
    goto v_21667;
v_21663:
    v_21869 = stack[-6];
    v_21870 = qcar(v_21869);
    goto v_21664;
v_21665:
    v_21869 = stack[0];
    goto v_21666;
v_21667:
    goto v_21663;
v_21664:
    goto v_21665;
v_21666:
    fn = elt(env, 19); // quotof
    v_21870 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    goto v_21658;
v_21659:
    v_21869 = stack[-6];
    v_21869 = qcdr(v_21869);
    goto v_21660;
v_21661:
    goto v_21657;
v_21658:
    goto v_21659;
v_21660:
    v_21869 = cons(v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    v_21869 = qvalue(elt(env, 5)); // !*allfac
    if (v_21869 == nil) goto v_21676;
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    fn = elt(env, 17); // ckrn
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[-1] = v_21869;
    v_21869 = stack[-6];
    v_21869 = qcdr(v_21869);
    fn = elt(env, 17); // ckrn
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[0] = v_21869;
    goto v_21700;
v_21696:
    v_21870 = stack[-1];
    goto v_21697;
v_21698:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21699;
v_21700:
    goto v_21696;
v_21697:
    goto v_21698;
v_21699:
    if (v_21870 == v_21869) goto v_21695;
    v_21869 = lisp_true;
    goto v_21693;
v_21695:
    goto v_21711;
v_21707:
    v_21870 = stack[0];
    goto v_21708;
v_21709:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21710;
v_21711:
    goto v_21707;
v_21708:
    goto v_21709;
v_21710:
    v_21869 = Lneq(nil, v_21870, v_21869);
    env = stack[-8];
    goto v_21693;
    v_21869 = nil;
v_21693:
    if (v_21869 == nil) goto v_21691;
    goto v_21722;
v_21718:
    v_21870 = stack[-1];
    goto v_21719;
v_21720:
    v_21869 = stack[-6];
    v_21869 = qcar(v_21869);
    goto v_21721;
v_21722:
    goto v_21718;
v_21719:
    goto v_21720;
v_21721:
    if (equal(v_21870, v_21869)) goto v_21717;
    v_21869 = lisp_true;
    goto v_21715;
v_21717:
    goto v_21734;
v_21730:
    v_21870 = stack[0];
    goto v_21731;
v_21732:
    v_21869 = stack[-6];
    v_21869 = qcdr(v_21869);
    goto v_21733;
v_21734:
    goto v_21730;
v_21731:
    goto v_21732;
v_21733:
    v_21869 = Lneq(nil, v_21870, v_21869);
    env = stack[-8];
    goto v_21715;
    v_21869 = nil;
v_21715:
    goto v_21689;
v_21691:
    v_21869 = nil;
    goto v_21689;
    v_21869 = nil;
v_21689:
    if (v_21869 == nil) goto v_21687;
    goto v_21746;
v_21742:
    v_21869 = stack[-6];
    v_21870 = qcdr(v_21869);
    goto v_21743;
v_21744:
    v_21869 = stack[0];
    goto v_21745;
v_21746:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-5] = v_21869;
    goto v_21755;
v_21751:
    v_21869 = stack[-6];
    v_21870 = qcar(v_21869);
    goto v_21752;
v_21753:
    v_21869 = stack[-1];
    goto v_21754;
v_21755:
    goto v_21751;
v_21752:
    goto v_21753;
v_21754:
    fn = elt(env, 19); // quotof
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    goto v_21765;
v_21761:
    v_21870 = stack[-4];
    goto v_21762;
v_21763:
    v_21869 = stack[-1];
    goto v_21764;
v_21765:
    goto v_21761;
v_21762:
    goto v_21763;
v_21764:
    fn = elt(env, 16); // mkkl
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    fn = elt(env, 21); // prepf
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[-4] = v_21869;
    v_21869 = stack[0];
    fn = elt(env, 21); // prepf
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    stack[-1] = v_21869;
    goto v_21775;
v_21771:
    v_21870 = stack[-4];
    goto v_21772;
v_21773:
    v_21869 = stack[-6];
    goto v_21774;
v_21775:
    goto v_21771;
v_21772:
    goto v_21773;
v_21774:
    fn = elt(env, 22); // addfactors
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-6] = v_21869;
    goto v_21783;
v_21779:
    v_21870 = stack[-1];
    goto v_21780;
v_21781:
    v_21869 = stack[-5];
    goto v_21782;
v_21783:
    goto v_21779;
v_21780:
    goto v_21781;
v_21782:
    fn = elt(env, 22); // addfactors
    v_21869 = (*qfn2(fn))(fn, v_21870, v_21869);
    env = stack[-8];
    stack[-5] = v_21869;
    goto v_21794;
v_21790:
    v_21870 = stack[-5];
    goto v_21791;
v_21792:
    v_21869 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21793;
v_21794:
    goto v_21790;
v_21791:
    goto v_21792;
v_21793:
    if (v_21870 == v_21869) goto v_21788;
    else goto v_21789;
v_21788:
    v_21869 = stack[-6];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_21869);
    }
v_21789:
    goto v_21811;
v_21807:
    v_21870 = stack[-6];
    goto v_21808;
v_21809:
    v_21869 = elt(env, 8); // minus
    goto v_21810;
v_21811:
    goto v_21807;
v_21808:
    goto v_21809;
v_21810:
    if (!consp(v_21870)) goto v_21805;
    v_21870 = qcar(v_21870);
    if (v_21870 == v_21869) goto v_21804;
    else goto v_21805;
v_21804:
    goto v_21819;
v_21815:
    stack[0] = elt(env, 8); // minus
    goto v_21816;
v_21817:
    goto v_21828;
v_21822:
    v_21871 = elt(env, 9); // quotient
    goto v_21823;
v_21824:
    v_21869 = stack[-6];
    v_21869 = qcdr(v_21869);
    v_21870 = qcar(v_21869);
    goto v_21825;
v_21826:
    v_21869 = stack[-5];
    goto v_21827;
v_21828:
    goto v_21822;
v_21823:
    goto v_21824;
v_21825:
    goto v_21826;
v_21827:
    v_21869 = list3(v_21871, v_21870, v_21869);
    env = stack[-8];
    goto v_21818;
v_21819:
    goto v_21815;
v_21816:
    goto v_21817;
v_21818:
    v_21869 = list2(stack[0], v_21869);
    goto v_21803;
v_21805:
    goto v_21843;
v_21837:
    v_21871 = elt(env, 9); // quotient
    goto v_21838;
v_21839:
    v_21870 = stack[-6];
    goto v_21840;
v_21841:
    v_21869 = stack[-5];
    goto v_21842;
v_21843:
    goto v_21837;
v_21838:
    goto v_21839;
v_21840:
    goto v_21841;
v_21842:
    v_21869 = list3(v_21871, v_21870, v_21869);
    goto v_21803;
    v_21869 = nil;
v_21803:
    return ncons(v_21869);
    v_21869 = nil;
    goto v_21166;
v_21687:
    goto v_21674;
v_21676:
v_21674:
    v_21869 = stack[-4];
    if (v_21869 == nil) goto v_21850;
    goto v_21859;
v_21855:
    v_21869 = stack[-4];
    fn = elt(env, 24); // exchk
    stack[0] = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    goto v_21856;
v_21857:
    v_21869 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    goto v_21858;
v_21859:
    goto v_21855;
v_21856:
    goto v_21857;
v_21858:
    fn = elt(env, 26); // aconc!*
    v_21869 = (*qfn2(fn))(fn, stack[0], v_21869);
    env = stack[-8];
    fn = elt(env, 27); // retimes
    v_21869 = (*qfn1(fn))(fn, v_21869);
    return ncons(v_21869);
v_21850:
    v_21869 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_21869 = (*qfn1(fn))(fn, v_21869);
    env = stack[-8];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_21869);
    }
    v_21869 = nil;
v_21166:
    return onevalue(v_21869);
}



setup_type const u37_setup[] =
{
    {"internal-factorf",        CC_internalKfactorf,TOO_MANY_1,WRONG_NO_1},
    {"ioto_smaprinbuf",         CC_ioto_smaprinbuf,TOO_MANY_1, WRONG_NO_1},
    {"setfuncsnaryrd",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setfuncsnaryrd},
    {"rewrite",                 CC_rewrite,     TOO_MANY_1,    WRONG_NO_1},
    {"evalnumberp",             CC_evalnumberp, TOO_MANY_1,    WRONG_NO_1},
    {"contposp",                CC_contposp,    TOO_MANY_1,    WRONG_NO_1},
    {"diff_vertex",             TOO_FEW_2,      CC_diff_vertex,WRONG_NO_2},
    {"dp_from_ei",              CC_dp_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"getavalue",               CC_getavalue,   TOO_MANY_1,    WRONG_NO_1},
    {"msolve-psys1",            TOO_FEW_2,      CC_msolveKpsys1,WRONG_NO_2},
    {"lalr_expand_grammar",     CC_lalr_expand_grammar,TOO_MANY_1,WRONG_NO_1},
    {"cl_atnum",                CC_cl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"simpexpt1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt1},
    {"rl_bnfsimpl",             TOO_FEW_2,      CC_rl_bnfsimpl,WRONG_NO_2},
    {"dvfsf_smupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvfsf_smupdknowl},
    {"groebinvokecritm",        TOO_FEW_2,      CC_groebinvokecritm,WRONG_NO_2},
    {"vdpcleanup",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpcleanup},
    {"bflessp",                 TOO_FEW_2,      CC_bflessp,    WRONG_NO_2},
    {"intrdsortin",             TOO_FEW_2,      CC_intrdsortin,WRONG_NO_2},
    {"z-roads",                 CC_zKroads,     TOO_MANY_1,    WRONG_NO_1},
    {"janettreenodebuild",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_janettreenodebuild},
    {"ofsf_qesubqat",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_qesubqat},
    {"testord",                 TOO_FEW_2,      CC_testord,    WRONG_NO_2},
    {"tayfkern",                CC_tayfkern,    TOO_MANY_1,    WRONG_NO_1},
    {"mk+outer+list",           CC_mkLouterLlist,TOO_MANY_1,   WRONG_NO_1},
    {"repr_n",                  CC_repr_n,      TOO_MANY_1,    WRONG_NO_1},
    {"minusrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_minusrd},
    {"divide-by-power-of-ten",  TOO_FEW_2,      CC_divideKbyKpowerKofKten,WRONG_NO_2},
    {"atom_compare",            TOO_FEW_2,      CC_atom_compare,WRONG_NO_2},
    {"set_parser",              CC_set_parser,  TOO_MANY_1,    WRONG_NO_1},
    {"sq_member",               TOO_FEW_2,      CC_sq_member,  WRONG_NO_2},
    {"mri_ofsf2mriat",          TOO_FEW_2,      CC_mri_ofsf2mriat,WRONG_NO_2},
    {"rl_surep",                TOO_FEW_2,      CC_rl_surep,   WRONG_NO_2},
    {"sfto_b:ordexp",           TOO_FEW_2,      CC_sfto_bTordexp,WRONG_NO_2},
    {"intervalom",              CC_intervalom,  TOO_MANY_1,    WRONG_NO_1},
    {"greatertype",             TOO_FEW_2,      CC_greatertype,WRONG_NO_2},
    {"groebspolynom3",          TOO_FEW_2,      CC_groebspolynom3,WRONG_NO_2},
    {"exdfprn",                 CC_exdfprn,     TOO_MANY_1,    WRONG_NO_1},
    {"multiply-by-power-of-ten",TOO_FEW_2,      CC_multiplyKbyKpowerKofKten,WRONG_NO_2},
    {"calc_den_tar",            TOO_FEW_2,      CC_calc_den_tar,WRONG_NO_2},
    {"log_freevars",            TOO_FEW_2,      CC_log_freevars,WRONG_NO_2},
    {"prepsq*1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prepsqH1},
    {NULL, (one_args *)"u37", (two_args *)"135245 9637152 2738476", 0}
};

// end of generated code
