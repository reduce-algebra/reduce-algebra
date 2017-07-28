
// $destdir/u09.c        Machine generated C code

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



// Code for talp_candp

static LispObject CC_talp_candp(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    v_4287 = stack[0];
    fn = elt(env, 2); // talp_arg2l
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    stack[-1] = v_4287;
    v_4287 = stack[0];
    fn = elt(env, 3); // talp_arg2r
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    stack[0] = v_4287;
    v_4287 = stack[-1];
    if (!consp(v_4287)) goto v_4222;
    else goto v_4223;
v_4222:
    v_4287 = stack[0];
    v_4287 = (consp(v_4287) ? nil : lisp_true);
    goto v_4221;
v_4223:
    v_4287 = nil;
    goto v_4221;
    v_4287 = nil;
v_4221:
    if (v_4287 == nil) goto v_4219;
    v_4287 = nil;
    goto v_4211;
v_4219:
    v_4287 = stack[-1];
    if (!consp(v_4287)) goto v_4233;
    else goto v_4234;
v_4233:
    v_4287 = stack[0];
    fn = elt(env, 4); // talp_invp
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    if (v_4287 == nil) goto v_4238;
    else goto v_4239;
v_4238:
    v_4287 = nil;
    goto v_4211;
v_4239:
    goto v_4253;
v_4249:
    goto v_4250;
v_4251:
    v_4287 = stack[0];
    fn = elt(env, 5); // talp_invarg
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    goto v_4252;
v_4253:
    goto v_4249;
v_4250:
    goto v_4251;
v_4252:
    if (equal(stack[-1], v_4287)) goto v_4248;
    v_4287 = nil;
    goto v_4211;
v_4248:
    goto v_4237;
v_4237:
    goto v_4232;
v_4234:
    v_4287 = stack[0];
    if (!consp(v_4287)) goto v_4258;
    else goto v_4259;
v_4258:
    v_4287 = stack[-1];
    fn = elt(env, 4); // talp_invp
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    if (v_4287 == nil) goto v_4263;
    else goto v_4264;
v_4263:
    v_4287 = nil;
    goto v_4211;
v_4264:
    goto v_4278;
v_4274:
    goto v_4275;
v_4276:
    v_4287 = stack[-1];
    fn = elt(env, 5); // talp_invarg
    v_4287 = (*qfn1(fn))(fn, v_4287);
    env = stack[-2];
    goto v_4277;
v_4278:
    goto v_4274;
v_4275:
    goto v_4276;
v_4277:
    if (equal(stack[0], v_4287)) goto v_4273;
    v_4287 = nil;
    goto v_4211;
v_4273:
    goto v_4262;
v_4262:
    goto v_4232;
v_4259:
    v_4287 = nil;
    goto v_4211;
v_4232:
    v_4287 = elt(env, 1); // true
v_4211:
    return onevalue(v_4287);
}



// Code for pasf_deci

static LispObject CC_pasf_deci(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4232, v_4233, v_4234;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
// copy arguments values to proper place
    v_4232 = v_4206;
// end of prologue
    fn = elt(env, 1); // pasf_dec
    v_4232 = (*qfn1(fn))(fn, v_4232);
    v_4234 = v_4232;
    goto v_4218;
v_4214:
    v_4232 = v_4234;
    v_4233 = qcar(v_4232);
    goto v_4215;
v_4216:
    v_4232 = v_4234;
    v_4232 = qcdr(v_4232);
    if (v_4232 == nil) goto v_4223;
    else goto v_4224;
v_4223:
    v_4232 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4222;
v_4224:
    v_4232 = v_4234;
    v_4232 = qcdr(v_4232);
    goto v_4222;
    v_4232 = nil;
v_4222:
    goto v_4217;
v_4218:
    goto v_4214;
v_4215:
    goto v_4216;
v_4217:
    return cons(v_4233, v_4232);
    return onevalue(v_4232);
}



// Code for ibalp_istotal

static LispObject CC_ibalp_istotal(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4231, v_4232;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4231 = v_4206;
// end of prologue
v_4205:
    v_4232 = v_4231;
    if (v_4232 == nil) goto v_4210;
    else goto v_4211;
v_4210:
    v_4231 = lisp_true;
    goto v_4209;
v_4211:
    v_4232 = v_4231;
    v_4232 = qcar(v_4232);
    v_4232 = qcdr(v_4232);
    v_4232 = qcdr(v_4232);
    v_4232 = qcar(v_4232);
    if (v_4232 == nil) goto v_4218;
    else goto v_4219;
v_4218:
    v_4231 = nil;
    goto v_4217;
v_4219:
    v_4231 = qcdr(v_4231);
    goto v_4205;
    v_4231 = nil;
v_4217:
    goto v_4209;
    v_4231 = nil;
v_4209:
    return onevalue(v_4231);
}



// Code for isarb_compl

static LispObject CC_isarb_compl(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4235, v_4236, v_4237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4236 = v_4206;
// end of prologue
    v_4235 = v_4236;
    v_4235 = Lconsp(nil, v_4235);
    env = stack[0];
    if (v_4235 == nil) goto v_4213;
    goto v_4224;
v_4220:
    v_4235 = v_4236;
    v_4237 = qcar(v_4235);
    goto v_4221;
v_4222:
    v_4235 = elt(env, 1); // arbcomplex
    goto v_4223;
v_4224:
    goto v_4220;
v_4221:
    goto v_4222;
v_4223:
    if (v_4237 == v_4235) goto v_4218;
    else goto v_4219;
v_4218:
    v_4235 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 2)) = v_4235; // found_compl
    goto v_4217;
v_4219:
    v_4235 = v_4236;
    v_4235 = qcdr(v_4235);
    fn = elt(env, 3); // multi_isarb_compl
    v_4235 = (*qfn1(fn))(fn, v_4235);
    goto v_4217;
v_4217:
    goto v_4211;
v_4213:
v_4211:
    v_4235 = nil;
    return onevalue(v_4235);
}



// Code for ps!:order

static LispObject CC_psTorder(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4249, v_4250, v_4251;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4251 = v_4206;
// end of prologue
    v_4249 = v_4251;
    if (!consp(v_4249)) goto v_4214;
    else goto v_4215;
v_4214:
    v_4249 = lisp_true;
    goto v_4213;
v_4215:
    goto v_4228;
v_4224:
    v_4249 = v_4251;
    v_4250 = qcar(v_4249);
    goto v_4225;
v_4226:
    v_4249 = elt(env, 1); // !:ps!:
    goto v_4227;
v_4228:
    goto v_4224;
v_4225:
    goto v_4226;
v_4227:
    if (v_4250 == v_4249) goto v_4223;
    v_4249 = v_4251;
    v_4249 = qcar(v_4249);
    if (!symbolp(v_4249)) v_4249 = nil;
    else { v_4249 = qfastgets(v_4249);
           if (v_4249 != nil) { v_4249 = elt(v_4249, 8); // dname
#ifdef RECORD_GET
             if (v_4249 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_4249 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_4249 == SPID_NOPROP) v_4249 = nil; }}
#endif
    goto v_4221;
v_4223:
    v_4249 = nil;
    goto v_4221;
    v_4249 = nil;
v_4221:
    goto v_4213;
    v_4249 = nil;
v_4213:
    if (v_4249 == nil) goto v_4211;
    v_4249 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4209;
v_4211:
    goto v_4246;
v_4242:
    v_4250 = v_4251;
    goto v_4243;
v_4244:
    v_4249 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4245;
v_4246:
    goto v_4242;
v_4243:
    goto v_4244;
v_4245:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_4250, v_4249);
    }
    v_4249 = nil;
v_4209:
    return onevalue(v_4249);
}



// Code for symtabget

static LispObject CC_symtabget(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4255, v_4256, v_4257, v_4258;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4257 = v_4207;
    v_4256 = v_4206;
// end of prologue
    v_4255 = v_4257;
    if (v_4255 == nil) goto v_4212;
    v_4255 = v_4256;
    if (v_4255 == nil) goto v_4216;
    else goto v_4215;
v_4216:
    v_4255 = qvalue(elt(env, 1)); // !*symboltable!*
    v_4255 = qcar(v_4255);
v_4215:
    v_4256 = v_4255;
    goto v_4210;
v_4212:
v_4210:
    v_4255 = v_4256;
    if (v_4255 == nil) goto v_4222;
    else goto v_4223;
v_4222:
    v_4255 = qvalue(elt(env, 1)); // !*symboltable!*
    goto v_4221;
v_4223:
    goto v_4232;
v_4228:
    v_4255 = v_4257;
    goto v_4229;
v_4230:
    v_4258 = elt(env, 2); // (!*type!* !*params!* !*decs!*)
    goto v_4231;
v_4232:
    goto v_4228;
v_4229:
    goto v_4230;
v_4231:
    v_4255 = Lmemq(nil, v_4255, v_4258);
    if (v_4255 == nil) goto v_4227;
    goto v_4241;
v_4237:
    v_4255 = v_4256;
    goto v_4238;
v_4239:
    v_4256 = v_4257;
    goto v_4240;
v_4241:
    goto v_4237;
v_4238:
    goto v_4239;
v_4240:
    return get(v_4255, v_4256);
v_4227:
    goto v_4250;
v_4246:
    v_4255 = v_4257;
    goto v_4247;
v_4248:
    if (!symbolp(v_4256)) v_4256 = nil;
    else { v_4256 = qfastgets(v_4256);
           if (v_4256 != nil) { v_4256 = elt(v_4256, 58); // !*decs!*
#ifdef RECORD_GET
             if (v_4256 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v_4256 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v_4256 == SPID_NOPROP) v_4256 = nil; }}
#endif
    goto v_4249;
v_4250:
    goto v_4246;
v_4247:
    goto v_4248;
v_4249:
    v_4255 = Lassoc(nil, v_4255, v_4256);
    goto v_4221;
    v_4255 = nil;
v_4221:
    return onevalue(v_4255);
}



// Code for vdpsave

static LispObject CC_vdpsave(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4209;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4209 = v_4206;
// end of prologue
    return onevalue(v_4209);
}



// Code for noncomp2f

static LispObject CC_noncomp2f(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4256, v_4257;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
v_4211:
    v_4256 = stack[0];
    if (!consp(v_4256)) goto v_4218;
    else goto v_4219;
v_4218:
    v_4256 = lisp_true;
    goto v_4217;
v_4219:
    v_4256 = stack[0];
    v_4256 = qcar(v_4256);
    v_4256 = (consp(v_4256) ? nil : lisp_true);
    goto v_4217;
    v_4256 = nil;
v_4217:
    if (v_4256 == nil) goto v_4215;
    v_4256 = nil;
    goto v_4210;
v_4215:
    v_4256 = stack[0];
    v_4256 = qcar(v_4256);
    v_4256 = qcar(v_4256);
    v_4256 = qcar(v_4256);
    v_4257 = v_4256;
    if (!consp(v_4256)) goto v_4228;
    else goto v_4229;
v_4228:
    v_4256 = v_4257;
    if (!symbolp(v_4256)) v_4256 = nil;
    else { v_4256 = qfastgets(v_4256);
           if (v_4256 != nil) { v_4256 = elt(v_4256, 0); // noncom
#ifdef RECORD_GET
             if (v_4256 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_4256 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_4256 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_4256 == SPID_NOPROP) v_4256 = nil; else v_4256 = lisp_true; }}
#endif
    if (v_4256 == nil) goto v_4237;
    v_4256 = lisp_true;
    goto v_4210;
v_4237:
    goto v_4213;
v_4229:
    v_4256 = v_4257;
    v_4256 = qcar(v_4256);
    if (!symbolp(v_4256)) v_4256 = nil;
    else { v_4256 = qfastgets(v_4256);
           if (v_4256 != nil) { v_4256 = elt(v_4256, 0); // noncom
#ifdef RECORD_GET
             if (v_4256 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_4256 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_4256 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_4256 == SPID_NOPROP) v_4256 = nil; else v_4256 = lisp_true; }}
#endif
    if (v_4256 == nil) goto v_4242;
    v_4256 = lisp_true;
    goto v_4210;
v_4242:
    v_4256 = stack[0];
    v_4256 = qcar(v_4256);
    v_4256 = qcdr(v_4256);
    v_4256 = CC_noncomp2f(elt(env, 0), v_4256);
    env = stack[-1];
    if (v_4256 == nil) goto v_4248;
    v_4256 = lisp_true;
    goto v_4210;
v_4248:
v_4213:
    v_4256 = stack[0];
    v_4256 = qcdr(v_4256);
    stack[0] = v_4256;
    goto v_4211;
v_4210:
    return onevalue(v_4256);
}



// Code for add2inputbuf

static LispObject CC_add2inputbuf(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4243, v_4244, v_4245;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    fn = elt(env, 4); // terminalp
    v_4243 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_4243 == nil) goto v_4217;
    else goto v_4218;
v_4217:
    v_4243 = lisp_true;
    goto v_4216;
v_4218:
    v_4243 = qvalue(elt(env, 1)); // !*nosave!*
    goto v_4216;
    v_4243 = nil;
v_4216:
    if (v_4243 == nil) goto v_4214;
    v_4243 = nil;
    goto v_4210;
v_4214:
    goto v_4230;
v_4226:
    goto v_4238;
v_4232:
    v_4245 = qvalue(elt(env, 2)); // statcounter
    goto v_4233;
v_4234:
    v_4244 = stack[0];
    goto v_4235;
v_4236:
    v_4243 = stack[-1];
    goto v_4237;
v_4238:
    goto v_4232;
v_4233:
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    v_4244 = list3(v_4245, v_4244, v_4243);
    env = stack[-2];
    goto v_4227;
v_4228:
    v_4243 = qvalue(elt(env, 3)); // inputbuflis!*
    goto v_4229;
v_4230:
    goto v_4226;
v_4227:
    goto v_4228;
v_4229:
    v_4243 = cons(v_4244, v_4243);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_4243; // inputbuflis!*
    v_4243 = nil;
v_4210:
    return onevalue(v_4243);
}



// Code for ckpreci!#

static LispObject CC_ckpreciC(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4263, v_4264, v_4265;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    v_4263 = stack[0];
    v_4263 = qcar(v_4263);
    fn = elt(env, 2); // timesip
    stack[-1] = (*qfn1(fn))(fn, v_4263);
    env = stack[-2];
    v_4263 = stack[0];
    v_4263 = qcdr(v_4263);
    v_4263 = qcar(v_4263);
    fn = elt(env, 2); // timesip
    v_4263 = (*qfn1(fn))(fn, v_4263);
    env = stack[-2];
    v_4265 = stack[-1];
    v_4264 = v_4263;
    v_4263 = qvalue(elt(env, 1)); // !*complex
    if (v_4263 == nil) goto v_4219;
    else goto v_4220;
v_4219:
    v_4263 = nil;
    goto v_4218;
v_4220:
    v_4263 = v_4265;
    if (v_4263 == nil) goto v_4228;
    v_4263 = v_4264;
    if (v_4263 == nil) goto v_4231;
    else goto v_4228;
v_4231:
    goto v_4238;
v_4234:
    v_4263 = stack[0];
    v_4263 = qcar(v_4263);
    v_4264 = qcdr(v_4263);
    goto v_4235;
v_4236:
    v_4263 = stack[0];
    v_4263 = qcdr(v_4263);
    v_4263 = qcar(v_4263);
    goto v_4237;
v_4238:
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    {
        fn = elt(env, 3); // ckprec2!#
        return (*qfn2(fn))(fn, v_4264, v_4263);
    }
v_4228:
    v_4263 = v_4264;
    if (v_4263 == nil) goto v_4246;
    v_4263 = v_4265;
    if (v_4263 == nil) goto v_4249;
    else goto v_4246;
v_4249:
    goto v_4256;
v_4252:
    v_4263 = stack[0];
    v_4263 = qcdr(v_4263);
    v_4263 = qcar(v_4263);
    v_4264 = qcdr(v_4263);
    goto v_4253;
v_4254:
    v_4263 = stack[0];
    v_4263 = qcar(v_4263);
    goto v_4255;
v_4256:
    goto v_4252;
v_4253:
    goto v_4254;
v_4255:
    {
        fn = elt(env, 3); // ckprec2!#
        return (*qfn2(fn))(fn, v_4264, v_4263);
    }
v_4246:
    v_4263 = nil;
    goto v_4218;
    v_4263 = nil;
v_4218:
    return onevalue(v_4263);
}



// Code for mv!-pow!-minusp

static LispObject CC_mvKpowKminusp(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4231, v_4232;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
v_4205:
    v_4231 = stack[0];
    if (v_4231 == nil) goto v_4210;
    else goto v_4211;
v_4210:
    v_4231 = nil;
    goto v_4209;
v_4211:
    goto v_4224;
v_4220:
    v_4231 = stack[0];
    v_4232 = qcar(v_4231);
    goto v_4221;
v_4222:
    v_4231 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4223;
v_4224:
    goto v_4220;
v_4221:
    goto v_4222;
v_4223:
    v_4231 = (LispObject)lessp2(v_4232, v_4231);
    v_4231 = v_4231 ? lisp_true : nil;
    env = stack[-1];
    if (v_4231 == nil) goto v_4218;
    else goto v_4217;
v_4218:
    v_4231 = stack[0];
    v_4231 = qcdr(v_4231);
    stack[0] = v_4231;
    goto v_4205;
v_4217:
    goto v_4209;
    v_4231 = nil;
v_4209:
    return onevalue(v_4231);
}



// Code for mo!=deglist

static LispObject CC_moMdeglist(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4340, v_4341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_4206;
// end of prologue
    v_4340 = stack[-4];
    if (v_4340 == nil) goto v_4210;
    else goto v_4211;
v_4210:
    v_4340 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_degrees
    v_4340 = (*qfn1(fn))(fn, v_4340);
    env = stack[-6];
    stack[-3] = v_4340;
    v_4340 = stack[-3];
    if (v_4340 == nil) goto v_4223;
    else goto v_4224;
v_4223:
    v_4340 = nil;
    goto v_4217;
v_4224:
    v_4340 = (LispObject)0+TAG_FIXNUM; // 0
    v_4340 = ncons(v_4340);
    env = stack[-6];
    stack[-1] = v_4340;
    stack[-2] = v_4340;
v_4218:
    v_4340 = stack[-3];
    v_4340 = qcdr(v_4340);
    stack[-3] = v_4340;
    v_4340 = stack[-3];
    if (v_4340 == nil) goto v_4236;
    else goto v_4237;
v_4236:
    v_4340 = stack[-2];
    goto v_4217;
v_4237:
    goto v_4245;
v_4241:
    stack[0] = stack[-1];
    goto v_4242;
v_4243:
    v_4340 = (LispObject)0+TAG_FIXNUM; // 0
    v_4340 = ncons(v_4340);
    env = stack[-6];
    goto v_4244;
v_4245:
    goto v_4241;
v_4242:
    goto v_4243;
v_4244:
    v_4340 = Lrplacd(nil, stack[0], v_4340);
    env = stack[-6];
    v_4340 = stack[-1];
    v_4340 = qcdr(v_4340);
    stack[-1] = v_4340;
    goto v_4218;
v_4217:
    goto v_4209;
v_4211:
    goto v_4260;
v_4256:
    v_4340 = stack[-4];
    v_4341 = qcar(v_4340);
    goto v_4257;
v_4258:
    v_4340 = qvalue(elt(env, 2)); // cali!=degrees
    goto v_4259;
v_4260:
    goto v_4256;
v_4257:
    goto v_4258;
v_4259:
    v_4340 = Lassoc(nil, v_4341, v_4340);
    stack[-5] = v_4340;
    goto v_4271;
v_4267:
    v_4340 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_degrees
    v_4340 = (*qfn1(fn))(fn, v_4340);
    env = stack[-6];
    stack[-3] = v_4340;
    v_4340 = stack[-3];
    if (v_4340 == nil) goto v_4282;
    else goto v_4283;
v_4282:
    v_4340 = nil;
    v_4341 = v_4340;
    goto v_4276;
v_4283:
    v_4340 = stack[-3];
    v_4340 = qcar(v_4340);
    goto v_4295;
v_4291:
    v_4341 = stack[-4];
    v_4341 = qcdr(v_4341);
    goto v_4292;
v_4293:
    goto v_4294;
v_4295:
    goto v_4291;
v_4292:
    goto v_4293;
v_4294:
    fn = elt(env, 4); // mo!=sprod
    v_4340 = (*qfn2(fn))(fn, v_4341, v_4340);
    env = stack[-6];
    v_4340 = ncons(v_4340);
    env = stack[-6];
    stack[-1] = v_4340;
    stack[-2] = v_4340;
v_4277:
    v_4340 = stack[-3];
    v_4340 = qcdr(v_4340);
    stack[-3] = v_4340;
    v_4340 = stack[-3];
    if (v_4340 == nil) goto v_4303;
    else goto v_4304;
v_4303:
    v_4340 = stack[-2];
    v_4341 = v_4340;
    goto v_4276;
v_4304:
    goto v_4312;
v_4308:
    stack[0] = stack[-1];
    goto v_4309;
v_4310:
    v_4340 = stack[-3];
    v_4340 = qcar(v_4340);
    goto v_4323;
v_4319:
    v_4341 = stack[-4];
    v_4341 = qcdr(v_4341);
    goto v_4320;
v_4321:
    goto v_4322;
v_4323:
    goto v_4319;
v_4320:
    goto v_4321;
v_4322:
    fn = elt(env, 4); // mo!=sprod
    v_4340 = (*qfn2(fn))(fn, v_4341, v_4340);
    env = stack[-6];
    v_4340 = ncons(v_4340);
    env = stack[-6];
    goto v_4311;
v_4312:
    goto v_4308;
v_4309:
    goto v_4310;
v_4311:
    v_4340 = Lrplacd(nil, stack[0], v_4340);
    env = stack[-6];
    v_4340 = stack[-1];
    v_4340 = qcdr(v_4340);
    stack[-1] = v_4340;
    goto v_4277;
v_4276:
    goto v_4268;
v_4269:
    v_4340 = stack[-5];
    if (v_4340 == nil) goto v_4332;
    v_4340 = stack[-5];
    v_4340 = qcdr(v_4340);
    v_4340 = qcdr(v_4340);
    goto v_4330;
v_4332:
    v_4340 = nil;
    goto v_4330;
    v_4340 = nil;
v_4330:
    goto v_4270;
v_4271:
    goto v_4267;
v_4268:
    goto v_4269;
v_4270:
    {
        fn = elt(env, 5); // mo!=sum
        return (*qfn2(fn))(fn, v_4341, v_4340);
    }
    v_4340 = nil;
v_4209:
    return onevalue(v_4340);
}



// Code for general!-times!-term!-mod!-p

static LispObject CC_generalKtimesKtermKmodKp(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4427, v_4428, v_4429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_4207;
    stack[-2] = v_4206;
// end of prologue
    v_4427 = stack[-1];
    if (v_4427 == nil) goto v_4211;
    else goto v_4212;
v_4211:
    v_4427 = nil;
    goto v_4210;
v_4212:
    v_4427 = stack[-1];
    if (!consp(v_4427)) goto v_4219;
    else goto v_4220;
v_4219:
    v_4427 = lisp_true;
    goto v_4218;
v_4220:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = (consp(v_4427) ? nil : lisp_true);
    goto v_4218;
    v_4427 = nil;
v_4218:
    if (v_4427 == nil) goto v_4216;
    goto v_4233;
v_4229:
    v_4427 = stack[-2];
    v_4428 = qcdr(v_4427);
    goto v_4230;
v_4231:
    v_4427 = stack[-1];
    goto v_4232;
v_4233:
    goto v_4229;
v_4230:
    goto v_4231;
v_4232:
    fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
    v_4428 = (*qfn2(fn))(fn, v_4428, v_4427);
    v_4427 = nil;
    v_4429 = v_4428;
    if (v_4429 == nil) goto v_4242;
    else goto v_4243;
v_4242:
    goto v_4241;
v_4243:
    goto v_4255;
v_4249:
    v_4429 = stack[-2];
    v_4429 = qcar(v_4429);
    goto v_4250;
v_4251:
    goto v_4252;
v_4253:
    goto v_4254;
v_4255:
    goto v_4249;
v_4250:
    goto v_4251;
v_4252:
    goto v_4253;
v_4254:
    return acons(v_4429, v_4428, v_4427);
    v_4427 = nil;
v_4241:
    goto v_4210;
v_4216:
    goto v_4266;
v_4262:
    v_4427 = stack[-2];
    v_4427 = qcar(v_4427);
    v_4428 = qcar(v_4427);
    goto v_4263;
v_4264:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = qcar(v_4427);
    v_4427 = qcar(v_4427);
    goto v_4265;
v_4266:
    goto v_4262;
v_4263:
    goto v_4264;
v_4265:
    if (equal(v_4428, v_4427)) goto v_4260;
    else goto v_4261;
v_4260:
    goto v_4279;
v_4275:
    v_4427 = stack[-2];
    v_4428 = qcdr(v_4427);
    goto v_4276;
v_4277:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = qcdr(v_4427);
    goto v_4278;
v_4279:
    goto v_4275;
v_4276:
    goto v_4277;
v_4278:
    fn = elt(env, 2); // general!-times!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_4428, v_4427);
    env = stack[-4];
    goto v_4290;
v_4286:
    v_4428 = stack[-2];
    goto v_4287;
v_4288:
    v_4427 = stack[-1];
    v_4427 = qcdr(v_4427);
    goto v_4289;
v_4290:
    goto v_4286;
v_4287:
    goto v_4288;
v_4289:
    v_4427 = CC_generalKtimesKtermKmodKp(elt(env, 0), v_4428, v_4427);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_4427;
    v_4427 = stack[-3];
    if (v_4427 == nil) goto v_4298;
    else goto v_4299;
v_4298:
    v_4427 = stack[0];
    goto v_4297;
v_4299:
    goto v_4311;
v_4305:
    goto v_4317;
v_4313:
    v_4427 = stack[-2];
    v_4427 = qcar(v_4427);
    v_4429 = qcar(v_4427);
    goto v_4314;
v_4315:
    goto v_4325;
v_4321:
    v_4427 = stack[-2];
    v_4427 = qcar(v_4427);
    v_4428 = qcdr(v_4427);
    goto v_4322;
v_4323:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = qcar(v_4427);
    v_4427 = qcdr(v_4427);
    goto v_4324;
v_4325:
    goto v_4321;
v_4322:
    goto v_4323;
v_4324:
    v_4427 = (LispObject)(intptr_t)((intptr_t)v_4428 + (intptr_t)v_4427 - TAG_FIXNUM);
    goto v_4316;
v_4317:
    goto v_4313;
v_4314:
    goto v_4315;
v_4316:
    fn = elt(env, 3); // mksp
    v_4429 = (*qfn2(fn))(fn, v_4429, v_4427);
    goto v_4306;
v_4307:
    v_4428 = stack[-3];
    goto v_4308;
v_4309:
    v_4427 = stack[0];
    goto v_4310;
v_4311:
    goto v_4305;
v_4306:
    goto v_4307;
v_4308:
    goto v_4309;
v_4310:
    return acons(v_4429, v_4428, v_4427);
    v_4427 = nil;
v_4297:
    goto v_4210;
v_4261:
    goto v_4343;
v_4339:
    v_4427 = stack[-2];
    v_4427 = qcar(v_4427);
    v_4428 = qcar(v_4427);
    goto v_4340;
v_4341:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = qcar(v_4427);
    v_4427 = qcar(v_4427);
    goto v_4342;
v_4343:
    goto v_4339;
v_4340:
    goto v_4341;
v_4342:
    fn = elt(env, 4); // ordop
    v_4427 = (*qfn2(fn))(fn, v_4428, v_4427);
    env = stack[-4];
    if (v_4427 == nil) goto v_4337;
    goto v_4356;
v_4352:
    v_4427 = stack[-2];
    v_4428 = qcdr(v_4427);
    goto v_4353;
v_4354:
    v_4427 = stack[-1];
    goto v_4355;
v_4356:
    goto v_4352;
v_4353:
    goto v_4354;
v_4355:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_4428 = (*qfn2(fn))(fn, v_4428, v_4427);
    v_4427 = nil;
    v_4429 = v_4428;
    if (v_4429 == nil) goto v_4365;
    else goto v_4366;
v_4365:
    goto v_4364;
v_4366:
    goto v_4378;
v_4372:
    v_4429 = stack[-2];
    v_4429 = qcar(v_4429);
    goto v_4373;
v_4374:
    goto v_4375;
v_4376:
    goto v_4377;
v_4378:
    goto v_4372;
v_4373:
    goto v_4374;
v_4375:
    goto v_4376;
v_4377:
    return acons(v_4429, v_4428, v_4427);
    v_4427 = nil;
v_4364:
    goto v_4210;
v_4337:
    goto v_4390;
v_4386:
    v_4428 = stack[-2];
    goto v_4387;
v_4388:
    v_4427 = stack[-1];
    v_4427 = qcar(v_4427);
    v_4427 = qcdr(v_4427);
    goto v_4389;
v_4390:
    goto v_4386;
v_4387:
    goto v_4388;
v_4389:
    stack[0] = CC_generalKtimesKtermKmodKp(elt(env, 0), v_4428, v_4427);
    env = stack[-4];
    goto v_4400;
v_4396:
    v_4428 = stack[-2];
    goto v_4397;
v_4398:
    v_4427 = stack[-1];
    v_4427 = qcdr(v_4427);
    goto v_4399;
v_4400:
    goto v_4396;
v_4397:
    goto v_4398;
v_4399:
    v_4427 = CC_generalKtimesKtermKmodKp(elt(env, 0), v_4428, v_4427);
    v_4428 = stack[0];
    v_4429 = v_4428;
    if (v_4429 == nil) goto v_4408;
    else goto v_4409;
v_4408:
    goto v_4407;
v_4409:
    goto v_4421;
v_4415:
    v_4429 = stack[-1];
    v_4429 = qcar(v_4429);
    v_4429 = qcar(v_4429);
    goto v_4416;
v_4417:
    goto v_4418;
v_4419:
    goto v_4420;
v_4421:
    goto v_4415;
v_4416:
    goto v_4417;
v_4418:
    goto v_4419;
v_4420:
    return acons(v_4429, v_4428, v_4427);
    v_4427 = nil;
v_4407:
    goto v_4210;
    v_4427 = nil;
v_4210:
    return onevalue(v_4427);
}



// Code for gionep!:

static LispObject CC_gionepT(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4234, v_4235, v_4236;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4235 = v_4206;
// end of prologue
    goto v_4216;
v_4212:
    v_4234 = v_4235;
    v_4234 = qcdr(v_4234);
    v_4236 = qcar(v_4234);
    goto v_4213;
v_4214:
    v_4234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4215;
v_4216:
    goto v_4212;
v_4213:
    goto v_4214;
v_4215:
    if (v_4236 == v_4234) goto v_4210;
    else goto v_4211;
v_4210:
    goto v_4225;
v_4221:
    v_4234 = v_4235;
    v_4234 = qcdr(v_4234);
    v_4235 = qcdr(v_4234);
    goto v_4222;
v_4223:
    v_4234 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4224;
v_4225:
    goto v_4221;
v_4222:
    goto v_4223;
v_4224:
    v_4234 = (v_4235 == v_4234 ? lisp_true : nil);
    goto v_4209;
v_4211:
    v_4234 = nil;
    goto v_4209;
    v_4234 = nil;
v_4209:
    return onevalue(v_4234);
}



// Code for cde_position2

static LispObject CC_cde_position2(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4256, v_4257;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    stack[-2] = nil;
v_4213:
    goto v_4224;
v_4220:
    v_4257 = stack[-1];
    goto v_4221;
v_4222:
    v_4256 = stack[0];
    v_4256 = qcar(v_4256);
    goto v_4223;
v_4224:
    goto v_4220;
v_4221:
    goto v_4222;
v_4223:
    if (equal(v_4257, v_4256)) goto v_4218;
    else goto v_4219;
v_4218:
    goto v_4214;
v_4219:
    goto v_4233;
v_4229:
    v_4257 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4230;
v_4231:
    v_4256 = stack[-2];
    goto v_4232;
v_4233:
    goto v_4229;
v_4230:
    goto v_4231;
v_4232:
    v_4256 = cons(v_4257, v_4256);
    env = stack[-3];
    stack[-2] = v_4256;
    v_4256 = stack[0];
    v_4256 = qcdr(v_4256);
    stack[0] = v_4256;
    goto v_4213;
v_4214:
    v_4256 = (LispObject)16+TAG_FIXNUM; // 1
    v_4257 = v_4256;
v_4215:
    v_4256 = stack[-2];
    if (v_4256 == nil) goto v_4241;
    else goto v_4242;
v_4241:
    v_4256 = v_4257;
    goto v_4212;
v_4242:
    goto v_4250;
v_4246:
    v_4256 = stack[-2];
    v_4256 = qcar(v_4256);
    goto v_4247;
v_4248:
    goto v_4249;
v_4250:
    goto v_4246;
v_4247:
    goto v_4248;
v_4249:
    v_4256 = plus2(v_4256, v_4257);
    env = stack[-3];
    v_4257 = v_4256;
    v_4256 = stack[-2];
    v_4256 = qcdr(v_4256);
    stack[-2] = v_4256;
    goto v_4215;
v_4212:
    return onevalue(v_4256);
}



// Code for prepsq!*2

static LispObject CC_prepsqH2(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4220, v_4221, v_4222;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4220 = v_4206;
// end of prologue
    goto v_4216;
v_4210:
    v_4222 = v_4220;
    goto v_4211;
v_4212:
    v_4221 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4213;
v_4214:
    v_4220 = nil;
    goto v_4215;
v_4216:
    goto v_4210;
v_4211:
    goto v_4212;
v_4213:
    goto v_4214;
v_4215:
    fn = elt(env, 1); // prepsq!*1
    v_4220 = (*qfnn(fn))(fn, 3, v_4222, v_4221, v_4220);
    env = stack[0];
    {
        fn = elt(env, 2); // replus
        return (*qfn1(fn))(fn, v_4220);
    }
}



// Code for ordpa

static LispObject CC_ordpa(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4217, v_4218;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4217 = v_4207;
    v_4218 = v_4206;
// end of prologue
    goto v_4214;
v_4210:
    goto v_4211;
v_4212:
    goto v_4213;
v_4214:
    goto v_4210;
v_4211:
    goto v_4212;
v_4213:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_4218, v_4217);
    }
}



// Code for talp_smwmkatl

static LispObject CC_talp_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4246, v_4247, v_4248, v_4249, v_4250;
    LispObject fn;
    LispObject v_4209, v_4208, v_4207, v_4206;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smwmkatl");
    va_start(aa, nargs);
    v_4206 = va_arg(aa, LispObject);
    v_4207 = va_arg(aa, LispObject);
    v_4208 = va_arg(aa, LispObject);
    v_4209 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4247 = v_4209;
    v_4248 = v_4208;
    v_4249 = v_4207;
    v_4250 = v_4206;
// end of prologue
    v_4246 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_4246 == nil) goto v_4214;
    goto v_4225;
v_4217:
    v_4246 = v_4250;
    goto v_4218;
v_4219:
    goto v_4220;
v_4221:
    goto v_4222;
v_4223:
    goto v_4224;
v_4225:
    goto v_4217;
v_4218:
    goto v_4219;
v_4220:
    goto v_4221;
v_4222:
    goto v_4223;
v_4224:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_4246, v_4249, v_4248, v_4247);
    }
v_4214:
    goto v_4241;
v_4233:
    v_4246 = v_4250;
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    goto v_4238;
v_4239:
    goto v_4240;
v_4241:
    goto v_4233;
v_4234:
    goto v_4235;
v_4236:
    goto v_4237;
v_4238:
    goto v_4239;
v_4240:
    {
        fn = elt(env, 3); // cl_smmkatl
        return (*qfnn(fn))(fn, 4, v_4246, v_4249, v_4248, v_4247);
    }
    v_4246 = nil;
    return onevalue(v_4246);
}



// Code for ibalp_litlp

static LispObject CC_ibalp_litlp(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
v_4205:
    v_4229 = stack[0];
    if (v_4229 == nil) goto v_4210;
    else goto v_4211;
v_4210:
    v_4229 = lisp_true;
    goto v_4209;
v_4211:
    v_4229 = stack[0];
    v_4229 = qcar(v_4229);
    fn = elt(env, 1); // ibalp_litp
    v_4229 = (*qfn1(fn))(fn, v_4229);
    env = stack[-1];
    if (v_4229 == nil) goto v_4218;
    else goto v_4219;
v_4218:
    v_4229 = nil;
    goto v_4217;
v_4219:
    v_4229 = stack[0];
    v_4229 = qcdr(v_4229);
    stack[0] = v_4229;
    goto v_4205;
    v_4229 = nil;
v_4217:
    goto v_4209;
    v_4229 = nil;
v_4209:
    return onevalue(v_4229);
}



// Code for multiom

static LispObject CC_multiom(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4234, v_4235;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    goto v_4218;
v_4214:
    v_4234 = stack[0];
    v_4235 = Llength(nil, v_4234);
    env = stack[-1];
    goto v_4215;
v_4216:
    v_4234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4217;
v_4218:
    goto v_4214;
v_4215:
    goto v_4216;
v_4217:
    if (v_4235 == v_4234) goto v_4212;
    else goto v_4213;
v_4212:
    v_4234 = stack[0];
    v_4234 = qcar(v_4234);
    fn = elt(env, 1); // objectom
    v_4234 = (*qfn1(fn))(fn, v_4234);
    goto v_4211;
v_4213:
    v_4234 = stack[0];
    v_4234 = qcar(v_4234);
    fn = elt(env, 1); // objectom
    v_4234 = (*qfn1(fn))(fn, v_4234);
    env = stack[-1];
    v_4234 = stack[0];
    v_4234 = qcdr(v_4234);
    v_4234 = CC_multiom(elt(env, 0), v_4234);
    goto v_4211;
v_4211:
    v_4234 = nil;
    return onevalue(v_4234);
}



// Code for rdprep1

static LispObject CC_rdprep1(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4225, v_4226;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4226 = v_4206;
// end of prologue
    v_4225 = v_4226;
    v_4225 = qcdr(v_4225);
    if (!consp(v_4225)) goto v_4210;
    else goto v_4211;
v_4210:
    v_4225 = v_4226;
    goto v_4209;
v_4211:
    goto v_4222;
v_4218:
    goto v_4219;
v_4220:
    v_4225 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_4221;
v_4222:
    goto v_4218;
v_4219:
    goto v_4220;
v_4221:
    {
        fn = elt(env, 2); // round!:mt
        return (*qfn2(fn))(fn, v_4226, v_4225);
    }
    v_4225 = nil;
v_4209:
    return onevalue(v_4225);
}



// Code for difff

static LispObject CC_difff(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4472, v_4473, v_4474;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_4207;
    stack[-2] = v_4206;
// end of prologue
    v_4472 = stack[-2];
    if (!consp(v_4472)) goto v_4211;
    else goto v_4212;
v_4211:
    goto v_4219;
v_4215:
    v_4473 = nil;
    goto v_4216;
v_4217:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4218;
v_4219:
    goto v_4215;
v_4216:
    goto v_4217;
v_4218:
    return cons(v_4473, v_4472);
v_4212:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    if (!consp(v_4472)) goto v_4222;
    else goto v_4223;
v_4222:
    goto v_4231;
v_4227:
    v_4472 = stack[-2];
    v_4473 = qcar(v_4472);
    goto v_4228;
v_4229:
    v_4472 = elt(env, 1); // domain!-diff!-fn
    goto v_4230;
v_4231:
    goto v_4227;
v_4228:
    goto v_4229;
v_4230:
    v_4472 = get(v_4473, v_4472);
    v_4473 = v_4472;
    v_4472 = v_4473;
    if (v_4472 == nil) goto v_4239;
    goto v_4248;
v_4242:
    v_4474 = v_4473;
    goto v_4243;
v_4244:
    v_4473 = stack[-2];
    goto v_4245;
v_4246:
    v_4472 = stack[-1];
    goto v_4247;
v_4248:
    goto v_4242;
v_4243:
    goto v_4244;
v_4245:
    goto v_4246;
v_4247:
        return Lapply2(nil, 3, v_4474, v_4473, v_4472);
v_4239:
    goto v_4259;
v_4255:
    v_4473 = nil;
    goto v_4256;
v_4257:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4258;
v_4259:
    goto v_4255;
v_4256:
    goto v_4257;
v_4258:
    return cons(v_4473, v_4472);
    v_4472 = nil;
    goto v_4210;
v_4223:
    goto v_4269;
v_4265:
    goto v_4275;
v_4271:
    goto v_4281;
v_4277:
    goto v_4287;
v_4283:
    goto v_4294;
v_4290:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4473 = qcar(v_4472);
    goto v_4291;
v_4292:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4293;
v_4294:
    goto v_4290;
v_4291:
    goto v_4292;
v_4293:
    v_4472 = cons(v_4473, v_4472);
    env = stack[-4];
    v_4473 = ncons(v_4472);
    env = stack[-4];
    goto v_4284;
v_4285:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4286;
v_4287:
    goto v_4283;
v_4284:
    goto v_4285;
v_4286:
    stack[0] = cons(v_4473, v_4472);
    env = stack[-4];
    goto v_4278;
v_4279:
    goto v_4305;
v_4301:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4472 = qcar(v_4472);
    v_4472 = qcar(v_4472);
    fn = elt(env, 5); // fermionicp
    v_4472 = (*qfn1(fn))(fn, v_4472);
    env = stack[-4];
    if (v_4472 == nil) goto v_4309;
    goto v_4326;
v_4322:
    v_4473 = stack[-1];
    goto v_4323;
v_4324:
    v_4472 = elt(env, 2); // s
    goto v_4325;
v_4326:
    goto v_4322;
v_4323:
    goto v_4324;
v_4325:
    if (v_4473 == v_4472) goto v_4320;
    else goto v_4321;
v_4320:
    v_4472 = qvalue(elt(env, 3)); // s_changes_parity
    goto v_4319;
v_4321:
    v_4472 = nil;
    goto v_4319;
    v_4472 = nil;
v_4319:
    if (v_4472 == nil) goto v_4317;
    else goto v_4316;
v_4317:
    goto v_4343;
v_4339:
    v_4473 = stack[-1];
    goto v_4340;
v_4341:
    v_4472 = lisp_true;
    goto v_4342;
v_4343:
    goto v_4339;
v_4340:
    goto v_4341;
v_4342:
    if (v_4473 == v_4472) goto v_4337;
    else goto v_4338;
v_4337:
    v_4472 = qvalue(elt(env, 4)); // t_changes_parity
    goto v_4336;
v_4338:
    v_4472 = nil;
    goto v_4336;
    v_4472 = nil;
v_4336:
    if (v_4472 == nil) goto v_4334;
    else goto v_4316;
v_4334:
    v_4472 = stack[-1];
    fn = elt(env, 5); // fermionicp
    v_4472 = (*qfn1(fn))(fn, v_4472);
    env = stack[-4];
    if (v_4472 == nil) goto v_4350;
    else goto v_4316;
v_4350:
    goto v_4309;
v_4316:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4472 = qcdr(v_4472);
    fn = elt(env, 6); // negf
    v_4472 = (*qfn1(fn))(fn, v_4472);
    env = stack[-4];
    v_4473 = v_4472;
    goto v_4307;
v_4309:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4472 = qcdr(v_4472);
    v_4473 = v_4472;
    goto v_4307;
    v_4473 = nil;
v_4307:
    goto v_4302;
v_4303:
    v_4472 = stack[-1];
    goto v_4304;
v_4305:
    goto v_4301;
v_4302:
    goto v_4303;
v_4304:
    v_4472 = CC_difff(elt(env, 0), v_4473, v_4472);
    env = stack[-4];
    goto v_4280;
v_4281:
    goto v_4277;
v_4278:
    goto v_4279;
v_4280:
    fn = elt(env, 7); // multsq
    stack[-3] = (*qfn2(fn))(fn, stack[0], v_4472);
    env = stack[-4];
    goto v_4272;
v_4273:
    goto v_4368;
v_4364:
    goto v_4381;
v_4377:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4472 = qcar(v_4472);
    v_4473 = qcdr(v_4472);
    goto v_4378;
v_4379:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4380;
v_4381:
    goto v_4377;
v_4378:
    goto v_4379;
v_4380:
    if (v_4473 == v_4472) goto v_4375;
    else goto v_4376;
v_4375:
    goto v_4398;
v_4394:
    v_4473 = stack[-1];
    goto v_4395;
v_4396:
    v_4472 = elt(env, 2); // s
    goto v_4397;
v_4398:
    goto v_4394;
v_4395:
    goto v_4396;
v_4397:
    if (v_4473 == v_4472) goto v_4392;
    else goto v_4393;
v_4392:
    v_4472 = qvalue(elt(env, 3)); // s_changes_parity
    goto v_4391;
v_4393:
    v_4472 = nil;
    goto v_4391;
    v_4472 = nil;
v_4391:
    if (v_4472 == nil) goto v_4389;
    else goto v_4388;
v_4389:
    goto v_4416;
v_4412:
    v_4473 = stack[-1];
    goto v_4413;
v_4414:
    v_4472 = lisp_true;
    goto v_4415;
v_4416:
    goto v_4412;
v_4413:
    goto v_4414;
v_4415:
    if (v_4473 == v_4472) goto v_4410;
    else goto v_4411;
v_4410:
    v_4472 = qvalue(elt(env, 4)); // t_changes_parity
    goto v_4409;
v_4411:
    v_4472 = nil;
    goto v_4409;
    v_4472 = nil;
v_4409:
    if (v_4472 == nil) goto v_4407;
    else goto v_4406;
v_4407:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4472 = qcar(v_4472);
    v_4472 = qcar(v_4472);
    fn = elt(env, 5); // fermionicp
    v_4472 = (*qfn1(fn))(fn, v_4472);
    env = stack[-4];
v_4406:
v_4388:
    goto v_4374;
v_4376:
    v_4472 = nil;
    goto v_4374;
    v_4472 = nil;
v_4374:
    if (v_4472 == nil) goto v_4372;
    goto v_4436;
v_4432:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4473 = qcar(v_4472);
    goto v_4433;
v_4434:
    v_4472 = stack[-1];
    goto v_4435;
v_4436:
    goto v_4432;
v_4433:
    goto v_4434;
v_4435:
    fn = elt(env, 8); // diffdp
    v_4472 = (*qfn2(fn))(fn, v_4473, v_4472);
    env = stack[-4];
    stack[0] = v_4472;
    goto v_4370;
v_4372:
    goto v_4448;
v_4444:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4473 = qcar(v_4472);
    goto v_4445;
v_4446:
    v_4472 = stack[-1];
    goto v_4447;
v_4448:
    goto v_4444;
v_4445:
    goto v_4446;
v_4447:
    fn = elt(env, 9); // diffp
    v_4472 = (*qfn2(fn))(fn, v_4473, v_4472);
    env = stack[-4];
    stack[0] = v_4472;
    goto v_4370;
    stack[0] = nil;
v_4370:
    goto v_4365;
v_4366:
    goto v_4458;
v_4454:
    v_4472 = stack[-2];
    v_4472 = qcar(v_4472);
    v_4473 = qcdr(v_4472);
    goto v_4455;
v_4456:
    v_4472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4457;
v_4458:
    goto v_4454;
v_4455:
    goto v_4456;
v_4457:
    v_4472 = cons(v_4473, v_4472);
    env = stack[-4];
    goto v_4367;
v_4368:
    goto v_4364;
v_4365:
    goto v_4366;
v_4367:
    fn = elt(env, 7); // multsq
    v_4472 = (*qfn2(fn))(fn, stack[0], v_4472);
    env = stack[-4];
    goto v_4274;
v_4275:
    goto v_4271;
v_4272:
    goto v_4273;
v_4274:
    fn = elt(env, 10); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[-3], v_4472);
    env = stack[-4];
    goto v_4266;
v_4267:
    goto v_4468;
v_4464:
    v_4472 = stack[-2];
    v_4473 = qcdr(v_4472);
    goto v_4465;
v_4466:
    v_4472 = stack[-1];
    goto v_4467;
v_4468:
    goto v_4464;
v_4465:
    goto v_4466;
v_4467:
    v_4472 = CC_difff(elt(env, 0), v_4473, v_4472);
    env = stack[-4];
    goto v_4268;
v_4269:
    goto v_4265;
v_4266:
    goto v_4267;
v_4268:
    {
        LispObject v_4479 = stack[0];
        fn = elt(env, 10); // addsq
        return (*qfn2(fn))(fn, v_4479, v_4472);
    }
    v_4472 = nil;
v_4210:
    return onevalue(v_4472);
}



// Code for take!-realpart

static LispObject CC_takeKrealpart(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4233, v_4234;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    goto v_4213;
v_4209:
    goto v_4219;
v_4215:
    v_4233 = stack[0];
    v_4233 = qcar(v_4233);
    fn = elt(env, 1); // repartf
    v_4234 = (*qfn1(fn))(fn, v_4233);
    env = stack[-2];
    goto v_4216;
v_4217:
    v_4233 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4218;
v_4219:
    goto v_4215;
v_4216:
    goto v_4217;
v_4218:
    stack[-1] = cons(v_4234, v_4233);
    env = stack[-2];
    goto v_4210;
v_4211:
    goto v_4229;
v_4225:
    v_4234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4226;
v_4227:
    v_4233 = stack[0];
    v_4233 = qcdr(v_4233);
    goto v_4228;
v_4229:
    goto v_4225;
v_4226:
    goto v_4227;
v_4228:
    v_4233 = cons(v_4234, v_4233);
    env = stack[-2];
    goto v_4212;
v_4213:
    goto v_4209;
v_4210:
    goto v_4211;
v_4212:
    {
        LispObject v_4237 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_4237, v_4233);
    }
}



// Code for token1

static LispObject CC_token1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5120, v_5121;
    LispObject fn;
    argcheck(nargs, 0, "token1");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// end of prologue
    stack[-2] = nil;
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    stack[-3] = v_5120;
v_4212:
    goto v_4249;
v_4245:
    v_5121 = stack[-3];
    goto v_4246;
v_4247:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4248;
v_4249:
    goto v_4245;
v_4246:
    goto v_4247;
v_4248:
    if (v_5121 == v_5120) goto v_4243;
    else goto v_4244;
v_4243:
    v_5120 = lisp_true;
    goto v_4242;
v_4244:
    goto v_4259;
v_4255:
    v_5120 = stack[-3];
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4256;
v_4257:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4258;
v_4259:
    goto v_4255;
v_4256:
    goto v_4257;
v_4258:
    v_5120 = (v_5121 == v_5120 ? lisp_true : nil);
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4242;
    v_5120 = nil;
v_4242:
    if (v_5120 == nil) goto v_4240;
    goto v_4213;
v_4240:
    v_5120 = stack[-3];
    v_5120 = Lwhitespace_char_p(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4269;
    goto v_4282;
v_4278:
    v_5121 = stack[-3];
    goto v_4279;
v_4280:
    v_5120 = qvalue(elt(env, 3)); // !$eol!$
    goto v_4281;
v_4282:
    goto v_4278;
v_4279:
    goto v_4280;
v_4281:
    if (v_5121 == v_5120) goto v_4276;
    else goto v_4277;
v_4276:
    v_5120 = qvalue(elt(env, 4)); // !*eoldelimp
    goto v_4275;
v_4277:
    v_5120 = nil;
    goto v_4275;
    v_5120 = nil;
v_4275:
    if (v_5120 == nil) goto v_4273;
    else goto v_4269;
v_4273:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4212;
v_4269:
    v_5120 = stack[-3];
    v_5120 = Ldigitp(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4291;
    v_5120 = stack[-3];
    {
        fn = elt(env, 38); // token!-number
        return (*qfn1(fn))(fn, v_5120);
    }
v_4291:
    v_5120 = stack[-3];
    v_5120 = Lalpha_char_p(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4297;
    goto v_4215;
v_4297:
    goto v_4307;
v_4303:
    v_5121 = stack[-3];
    goto v_4304;
v_4305:
    v_5120 = elt(env, 5); // tokprop
    goto v_4306;
v_4307:
    goto v_4303;
v_4304:
    goto v_4305;
v_4306:
    v_5120 = get(v_5121, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    if (v_5120 == nil) goto v_4301;
    goto v_4315;
v_4311:
    v_5121 = stack[-2];
    goto v_4312;
v_4313:
    v_5120 = nil;
    goto v_4314;
v_4315:
    goto v_4311;
v_4312:
    goto v_4313;
v_4314:
    {
        fn = elt(env, 39); // lispapply
        return (*qfn2(fn))(fn, v_5121, v_5120);
    }
v_4301:
    goto v_4328;
v_4324:
    v_5121 = stack[-3];
    goto v_4325;
v_4326:
    v_5120 = elt(env, 6); // !%
    goto v_4327;
v_4328:
    goto v_4324;
v_4325:
    goto v_4326;
v_4327:
    if (v_5121 == v_5120) goto v_4322;
    else goto v_4323;
v_4322:
    v_5120 = qvalue(elt(env, 7)); // !*savecomments!*
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4321;
v_4323:
    v_5120 = nil;
    goto v_4321;
    v_5120 = nil;
v_4321:
    if (v_5120 == nil) goto v_4319;
    goto v_4235;
v_4319:
    goto v_4346;
v_4342:
    v_5121 = stack[-3];
    goto v_4343;
v_4344:
    v_5120 = elt(env, 8); // !!
    goto v_4345;
v_4346:
    goto v_4342;
v_4343:
    goto v_4344;
v_4345:
    if (v_5121 == v_5120) goto v_4340;
    else goto v_4341;
v_4340:
    v_5120 = qvalue(elt(env, 9)); // !*micro!-version
    if (v_5120 == nil) goto v_4351;
    else goto v_4352;
v_4351:
    v_5120 = nil;
    goto v_4350;
v_4352:
    v_5120 = qvalue(elt(env, 10)); // !*defn
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4350;
    v_5120 = nil;
v_4350:
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4339;
v_4341:
    v_5120 = nil;
    goto v_4339;
    v_5120 = nil;
v_4339:
    if (v_5120 == nil) goto v_4337;
    goto v_4214;
v_4337:
    goto v_4369;
v_4365:
    v_5121 = stack[-3];
    goto v_4366;
v_4367:
    v_5120 = elt(env, 11); // !"
    goto v_4368;
v_4369:
    goto v_4365;
v_4366:
    goto v_4367;
v_4368:
    if (v_5121 == v_5120) goto v_4363;
    else goto v_4364;
v_4363:
    goto v_4234;
v_4364:
    goto v_4378;
v_4374:
    v_5121 = stack[-3];
    goto v_4375;
v_4376:
    v_5120 = elt(env, 12); // !\ (backslash)
    goto v_4377;
v_4378:
    goto v_4374;
v_4375:
    goto v_4376;
v_4377:
    if (v_5121 == v_5120) goto v_4372;
    else goto v_4373;
v_4372:
    goto v_4221;
v_4373:
v_4213:
    v_5120 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 13)) = v_5120; // ttype!*
    goto v_4390;
v_4386:
    v_5121 = stack[-3];
    goto v_4387;
v_4388:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4389;
v_4390:
    goto v_4386;
v_4387:
    goto v_4388;
v_4389:
    if (v_5121 == v_5120) goto v_4384;
    else goto v_4385;
v_4384:
    v_5120 = elt(env, 14); // ! 
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    fn = elt(env, 40); // filenderr
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_4383;
v_4385:
v_4383:
    v_5120 = stack[-3];
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    goto v_4410;
v_4406:
    v_5121 = stack[-3];
    goto v_4407;
v_4408:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4409;
v_4410:
    goto v_4406;
v_4407:
    goto v_4408;
v_4409:
    if (v_5121 == v_5120) goto v_4405;
    goto v_4425;
v_4421:
    v_5120 = stack[-3];
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4422;
v_4423:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4424;
v_4425:
    goto v_4421;
v_4422:
    goto v_4423;
v_4424:
    if (v_5121 == v_5120) goto v_4419;
    else goto v_4420;
v_4419:
    v_5120 = stack[-3];
    fn = elt(env, 41); // delcp
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4418;
v_4420:
    v_5120 = nil;
    goto v_4418;
    v_5120 = nil;
v_4418:
    if (v_5120 == nil) goto v_4416;
    v_5120 = elt(env, 14); // ! 
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    goto v_4414;
v_4416:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    goto v_4414;
v_4414:
    goto v_4403;
v_4405:
v_4403:
    goto v_4451;
v_4447:
    v_5121 = stack[-3];
    goto v_4448;
v_4449:
    v_5120 = elt(env, 16); // !-
    goto v_4450;
v_4451:
    goto v_4447;
v_4448:
    goto v_4449;
v_4450:
    if (v_5121 == v_5120) goto v_4445;
    else goto v_4446;
v_4445:
    goto v_4462;
v_4458:
    v_5121 = qvalue(elt(env, 1)); // crchar!*
    goto v_4459;
v_4460:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4461;
v_4462:
    goto v_4458;
v_4459:
    goto v_4460;
v_4461:
    if (v_5121 == v_5120) goto v_4457;
    goto v_4473;
v_4469:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4470;
v_4471:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4472;
v_4473:
    goto v_4469;
v_4470:
    goto v_4471;
v_4472:
    if (v_5121 == v_5120) goto v_4467;
    else goto v_4468;
v_4467:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    v_5120 = Ldigitp(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4480;
    else goto v_4481;
v_4480:
    v_5120 = nil;
    goto v_4479;
v_4481:
    v_5120 = qvalue(elt(env, 17)); // !*minusliter
    goto v_4479;
    v_5120 = nil;
v_4479:
    goto v_4466;
v_4468:
    v_5120 = nil;
    goto v_4466;
    v_5120 = nil;
v_4466:
    goto v_4455;
v_4457:
    v_5120 = nil;
    goto v_4455;
    v_5120 = nil;
v_4455:
    goto v_4444;
v_4446:
    v_5120 = nil;
    goto v_4444;
    v_5120 = nil;
v_4444:
    if (v_5120 == nil) goto v_4441;
    else goto v_4442;
v_4441:
    goto v_4220;
v_4442:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 38); // token!-number
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-3] = v_5120;
    v_5120 = stack[-3];
    if (is_number(v_5120)) goto v_4501;
    else goto v_4502;
v_4501:
    goto v_4509;
v_4505:
    v_5121 = elt(env, 18); // minus
    goto v_4506;
v_4507:
    v_5120 = stack[-3];
    goto v_4508;
v_4509:
    goto v_4505;
v_4506:
    goto v_4507;
v_4508:
        return Lapply1(nil, v_5121, v_5120);
v_4502:
    goto v_4517;
v_4513:
    v_5120 = stack[-3];
    stack[0] = qcdr(v_5120);
    goto v_4514;
v_4515:
    goto v_4525;
v_4521:
    v_5121 = elt(env, 18); // minus
    goto v_4522;
v_4523:
    v_5120 = stack[-3];
    v_5120 = qcdr(v_5120);
    v_5120 = qcar(v_5120);
    goto v_4524;
v_4525:
    goto v_4521;
v_4522:
    goto v_4523;
v_4524:
    v_5120 = Lapply1(nil, v_5121, v_5120);
    env = stack[-4];
    goto v_4516;
v_4517:
    goto v_4513;
v_4514:
    goto v_4515;
v_4516:
    v_5120 = Lrplaca(nil, stack[0], v_5120);
    v_5120 = stack[-3];
    goto v_4211;
v_4214:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=19 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 19, -1);
    qvalue(elt(env, 19)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 20, 0);
    qvalue(elt(env, 20)) = nil; // !*lower
    v_5120 = lisp_true;
    qvalue(elt(env, 21)) = v_5120; // escaped!*
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    v_5120 = stack[-3];
    v_5120 = Lalpha_char_p(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4540;
    v_5120 = lisp_true;
    qvalue(elt(env, 21)) = v_5120; // escaped!*
    goto v_4538;
v_4540:
v_4538:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
v_4215:
    v_5120 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 13)) = v_5120; // ttype!*
v_4216:
    v_5120 = stack[-3];
    fn = elt(env, 42); // wideid2list
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-3] = v_5120;
v_4217:
    v_5120 = stack[-3];
    if (v_5120 == nil) goto v_4549;
    else goto v_4550;
v_4549:
    goto v_4218;
v_4550:
    goto v_4557;
v_4553:
    v_5120 = stack[-3];
    v_5121 = qcar(v_5120);
    goto v_4554;
v_4555:
    v_5120 = stack[-2];
    goto v_4556;
v_4557:
    goto v_4553;
v_4554:
    goto v_4555;
v_4556:
    v_5120 = cons(v_5121, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    v_5120 = stack[-3];
    v_5120 = qcdr(v_5120);
    stack[-3] = v_5120;
    goto v_4217;
v_4218:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4576;
v_4572:
    v_5121 = stack[-3];
    goto v_4573;
v_4574:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4575;
v_4576:
    goto v_4572;
v_4573:
    goto v_4574;
v_4575:
    if (v_5121 == v_5120) goto v_4570;
    else goto v_4571;
v_4570:
    v_5120 = lisp_true;
    goto v_4569;
v_4571:
    goto v_4586;
v_4582:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4583;
v_4584:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4585;
v_4586:
    goto v_4582;
v_4583:
    goto v_4584;
v_4585:
    v_5120 = (v_5121 == v_5120 ? lisp_true : nil);
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4569;
    v_5120 = nil;
v_4569:
    if (v_5120 == nil) goto v_4567;
    goto v_4219;
v_4567:
    v_5120 = stack[-3];
    v_5120 = Ldigitp(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4595;
    else goto v_4593;
v_4595:
    v_5120 = stack[-3];
    v_5120 = Lalpha_char_p(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4598;
    else goto v_4593;
v_4598:
    goto v_4594;
v_4593:
    goto v_4216;
v_4594:
    goto v_4607;
v_4603:
    v_5121 = stack[-3];
    goto v_4604;
v_4605:
    v_5120 = elt(env, 8); // !!
    goto v_4606;
v_4607:
    goto v_4603;
v_4604:
    goto v_4605;
v_4606:
    if (v_5121 == v_5120) goto v_4601;
    else goto v_4602;
v_4601:
    goto v_4214;
v_4602:
    goto v_4620;
v_4616:
    v_5121 = stack[-3];
    goto v_4617;
v_4618:
    v_5120 = elt(env, 16); // !-
    goto v_4619;
v_4620:
    goto v_4616;
v_4617:
    goto v_4618;
v_4619:
    if (v_5121 == v_5120) goto v_4614;
    else goto v_4615;
v_4614:
    v_5120 = qvalue(elt(env, 17)); // !*minusliter
    goto v_4613;
v_4615:
    v_5120 = nil;
    goto v_4613;
    v_5120 = nil;
v_4613:
    if (v_5120 == nil) goto v_4611;
    goto v_4216;
v_4611:
    goto v_4633;
v_4629:
    v_5121 = stack[-3];
    goto v_4630;
v_4631:
    v_5120 = elt(env, 22); // !_
    goto v_4632;
v_4633:
    goto v_4629;
v_4630:
    goto v_4631;
v_4632:
    if (v_5121 == v_5120) goto v_4627;
    else goto v_4628;
v_4627:
    goto v_4216;
v_4628:
    goto v_4642;
v_4638:
    v_5121 = stack[-3];
    goto v_4639;
v_4640:
    v_5120 = elt(env, 23); // !:
    goto v_4641;
v_4642:
    goto v_4638;
v_4639:
    goto v_4640;
v_4641:
    if (v_5121 == v_5120) goto v_4636;
    else goto v_4637;
v_4636:
    goto v_4226;
v_4637:
v_4219:
    v_5120 = stack[-2];
    fn = elt(env, 43); // reversip!*
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 44); // list2wideid
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    goto v_4656;
v_4652:
    v_5121 = stack[-2];
    goto v_4653;
v_4654:
    v_5120 = qvalue(elt(env, 24)); // !*line!-marker
    goto v_4655;
v_4656:
    goto v_4652;
v_4653:
    goto v_4654;
v_4655:
    if (equal(v_5121, v_5120)) goto v_4650;
    else goto v_4651;
v_4650:
    v_5120 = qvalue(elt(env, 25)); // curline!*
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    goto v_4649;
v_4651:
    goto v_4666;
v_4662:
    v_5121 = stack[-2];
    goto v_4663;
v_4664:
    v_5120 = qvalue(elt(env, 26)); // !*file!-marker
    goto v_4665;
v_4666:
    goto v_4662;
v_4663:
    goto v_4664;
v_4665:
    if (equal(v_5121, v_5120)) goto v_4660;
    else goto v_4661;
v_4660:
    v_5120 = qvalue(elt(env, 27)); // ifl!*
    if (v_5120 == nil) goto v_4671;
    else goto v_4672;
v_4671:
    v_5120 = elt(env, 28); // "Terminal"
    goto v_4670;
v_4672:
    v_5120 = qvalue(elt(env, 27)); // ifl!*
    v_5120 = qcar(v_5120);
    goto v_4670;
    v_5120 = nil;
v_4670:
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    goto v_4649;
v_4661:
    v_5120 = stack[-2];
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    goto v_4649;
v_4649:
    v_5120 = stack[-3];
    qvalue(elt(env, 1)) = v_5120; // crchar!*
v_4220:
    v_5120 = qvalue(elt(env, 15)); // nxtsym!*
    goto v_4211;
v_4221:
    v_5120 = elt(env, 29); // (!\ e n d !{ r e d u c e !})
    stack[-2] = v_5120;
    v_5120 = nil;
    stack[0] = v_5120;
v_4222:
    goto v_4691;
v_4687:
    v_5121 = stack[-3];
    goto v_4688;
v_4689:
    v_5120 = stack[0];
    goto v_4690;
v_4691:
    goto v_4687;
v_4688:
    goto v_4689;
v_4690:
    v_5120 = cons(v_5121, v_5120);
    env = stack[-4];
    stack[0] = v_5120;
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    v_5120 = stack[-2];
    v_5120 = qcdr(v_5120);
    stack[-2] = v_5120;
    v_5120 = stack[-2];
    if (v_5120 == nil) goto v_4699;
    else goto v_4700;
v_4699:
    goto v_4223;
v_4700:
    goto v_4708;
v_4704:
    v_5121 = stack[-3];
    goto v_4705;
v_4706:
    v_5120 = stack[-2];
    v_5120 = qcar(v_5120);
    goto v_4707;
v_4708:
    goto v_4704;
v_4705:
    goto v_4706;
v_4707:
    if (v_5121 == v_5120) goto v_4702;
    else goto v_4703;
v_4702:
    goto v_4222;
v_4703:
    goto v_4718;
v_4714:
    v_5121 = stack[-3];
    goto v_4715;
v_4716:
    v_5120 = stack[0];
    goto v_4717;
v_4718:
    goto v_4714;
v_4715:
    goto v_4716;
v_4717:
    v_5120 = cons(v_5121, v_5120);
    env = stack[-4];
    v_5120 = Lreverse(nil, v_5120);
    env = stack[-4];
    v_5120 = qcdr(v_5120);
    qvalue(elt(env, 30)) = v_5120; // peekchar!*
    v_5120 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 13)) = v_5120; // ttype!*
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    v_5120 = elt(env, 12); // !\ (backslash)
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    v_5120 = qvalue(elt(env, 15)); // nxtsym!*
    goto v_4211;
v_4223:
    v_5120 = elt(env, 31); // (!\ b e g i n !{ r e d u c e !})
    stack[-2] = v_5120;
    v_5120 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 13)) = v_5120; // ttype!*
v_4224:
    goto v_4736;
v_4732:
    v_5121 = stack[-3];
    goto v_4733;
v_4734:
    v_5120 = elt(env, 6); // !%
    goto v_4735;
v_4736:
    goto v_4732;
v_4733:
    goto v_4734;
v_4735:
    if (v_5121 == v_5120) goto v_4730;
    else goto v_4731;
v_4730:
    goto v_4225;
v_4731:
    goto v_4745;
v_4741:
    v_5121 = stack[-3];
    goto v_4742;
v_4743:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4744;
v_4745:
    goto v_4741;
v_4742:
    goto v_4743;
v_4744:
    if (v_5121 == v_5120) goto v_4739;
    else goto v_4740;
v_4739:
    v_5120 = elt(env, 14); // ! 
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    fn = elt(env, 40); // filenderr
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_5120 = stack[-3];
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    v_5120 = stack[-3];
    goto v_4211;
v_4740:
    v_5120 = stack[-2];
    if (v_5120 == nil) goto v_4754;
    else goto v_4755;
v_4754:
    goto v_4212;
v_4755:
    v_5120 = stack[-3];
    stack[0] = v_5120;
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4767;
v_4763:
    v_5121 = stack[0];
    goto v_4764;
v_4765:
    v_5120 = stack[-2];
    v_5120 = qcar(v_5120);
    goto v_4766;
v_4767:
    goto v_4763;
v_4764:
    goto v_4765;
v_4766:
    if (v_5121 == v_5120) goto v_4762;
    goto v_4223;
v_4762:
    v_5120 = stack[-2];
    v_5120 = qcdr(v_5120);
    stack[-2] = v_5120;
    goto v_4224;
v_4225:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4782;
v_4778:
    v_5121 = stack[-3];
    goto v_4779;
v_4780:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4781;
v_4782:
    goto v_4778;
v_4779:
    goto v_4780;
v_4781:
    if (v_5121 == v_5120) goto v_4776;
    else goto v_4777;
v_4776:
    goto v_4224;
v_4777:
    goto v_4791;
v_4787:
    v_5121 = stack[-3];
    goto v_4788;
v_4789:
    v_5120 = qvalue(elt(env, 3)); // !$eol!$
    goto v_4790;
v_4791:
    goto v_4787;
v_4788:
    goto v_4789;
v_4790:
    if (v_5121 == v_5120) goto v_4785;
    else goto v_4786;
v_4785:
    goto v_4223;
v_4786:
    goto v_4225;
v_4226:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4805;
v_4801:
    v_5121 = stack[-3];
    goto v_4802;
v_4803:
    v_5120 = elt(env, 23); // !:
    goto v_4804;
v_4805:
    goto v_4801;
v_4802:
    goto v_4803;
v_4804:
    if (v_5121 == v_5120) goto v_4799;
    else goto v_4800;
v_4799:
    goto v_4227;
v_4800:
    v_5120 = stack[-3];
    v_5120 = ncons(v_5120);
    env = stack[-4];
    qvalue(elt(env, 30)) = v_5120; // peekchar!*
    v_5120 = elt(env, 23); // !:
    stack[-3] = v_5120;
    goto v_4219;
v_4227:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4824;
v_4820:
    v_5121 = stack[-3];
    goto v_4821;
v_4822:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4823;
v_4824:
    goto v_4820;
v_4821:
    goto v_4822;
v_4823:
    if (v_5121 == v_5120) goto v_4819;
    goto v_4835;
v_4831:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4832;
v_4833:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4834;
v_4835:
    goto v_4831;
v_4832:
    goto v_4833;
v_4834:
    if (v_5121 == v_5120) goto v_4829;
    else goto v_4830;
v_4829:
    v_5120 = stack[-3];
    v_5120 = Lalpha_char_p(nil, v_5120);
    env = stack[-4];
    goto v_4828;
v_4830:
    v_5120 = nil;
    goto v_4828;
    v_5120 = nil;
v_4828:
    goto v_4817;
v_4819:
    v_5120 = nil;
    goto v_4817;
    v_5120 = nil;
v_4817:
    if (v_5120 == nil) goto v_4815;
    goto v_4228;
v_4815:
    goto v_4853;
v_4849:
    v_5121 = elt(env, 23); // !:
    goto v_4850;
v_4851:
    v_5120 = stack[-3];
    goto v_4852;
v_4853:
    goto v_4849;
v_4850:
    goto v_4851;
v_4852:
    v_5120 = list2(v_5121, v_5120);
    env = stack[-4];
    qvalue(elt(env, 30)) = v_5120; // peekchar!*
    v_5120 = elt(env, 23); // !:
    stack[-3] = v_5120;
    goto v_4219;
v_4228:
    v_5120 = stack[-2];
    v_5120 = Lreverse(nil, v_5120);
    env = stack[-4];
    fn = elt(env, 44); // list2wideid
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4867;
v_4861:
    v_5120 = elt(env, 23); // !:
    fn = elt(env, 45); // string2list
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[0] = qcar(v_5120);
    goto v_4862;
v_4863:
    v_5120 = elt(env, 23); // !:
    fn = elt(env, 45); // string2list
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    v_5121 = qcar(v_5120);
    goto v_4864;
v_4865:
    v_5120 = stack[-2];
    goto v_4866;
v_4867:
    goto v_4861;
v_4862:
    goto v_4863;
v_4864:
    goto v_4865;
v_4866:
    v_5120 = list2star(stack[0], v_5121, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
v_4229:
    v_5120 = stack[-3];
    fn = elt(env, 42); // wideid2list
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-3] = v_5120;
v_4230:
    v_5120 = stack[-3];
    if (v_5120 == nil) goto v_4879;
    else goto v_4880;
v_4879:
    goto v_4231;
v_4880:
    goto v_4887;
v_4883:
    v_5120 = stack[-3];
    v_5121 = qcar(v_5120);
    goto v_4884;
v_4885:
    v_5120 = stack[-2];
    goto v_4886;
v_4887:
    goto v_4883;
v_4884:
    goto v_4885;
v_4886:
    v_5120 = cons(v_5121, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    v_5120 = stack[-3];
    v_5120 = qcdr(v_5120);
    stack[-3] = v_5120;
    goto v_4230;
v_4231:
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4906;
v_4902:
    v_5121 = stack[-3];
    goto v_4903;
v_4904:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_4905;
v_4906:
    goto v_4902;
v_4903:
    goto v_4904;
v_4905:
    if (v_5121 == v_5120) goto v_4900;
    else goto v_4901;
v_4900:
    v_5120 = lisp_true;
    goto v_4899;
v_4901:
    goto v_4916;
v_4912:
    v_5120 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 35); // id2string
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 36); // string!-length
    v_5121 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    goto v_4913;
v_4914:
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4915;
v_4916:
    goto v_4912;
v_4913:
    goto v_4914;
v_4915:
    v_5120 = (v_5121 == v_5120 ? lisp_true : nil);
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_4899;
    v_5120 = nil;
v_4899:
    if (v_5120 == nil) goto v_4897;
    goto v_4232;
v_4897:
    v_5120 = stack[-3];
    v_5120 = Ldigitp(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4925;
    else goto v_4923;
v_4925:
    v_5120 = stack[-3];
    v_5120 = Lalpha_char_p(nil, v_5120);
    env = stack[-4];
    if (v_5120 == nil) goto v_4928;
    else goto v_4923;
v_4928:
    goto v_4924;
v_4923:
    goto v_4229;
v_4924:
    goto v_4937;
v_4933:
    v_5121 = stack[-3];
    goto v_4934;
v_4935:
    v_5120 = elt(env, 8); // !!
    goto v_4936;
v_4937:
    goto v_4933;
v_4934:
    goto v_4935;
v_4936:
    if (v_5121 == v_5120) goto v_4931;
    else goto v_4932;
v_4931:
    goto v_4233;
v_4932:
    goto v_4950;
v_4946:
    v_5121 = stack[-3];
    goto v_4947;
v_4948:
    v_5120 = elt(env, 16); // !-
    goto v_4949;
v_4950:
    goto v_4946;
v_4947:
    goto v_4948;
v_4949:
    if (v_5121 == v_5120) goto v_4944;
    else goto v_4945;
v_4944:
    v_5120 = qvalue(elt(env, 17)); // !*minusliter
    goto v_4943;
v_4945:
    v_5120 = nil;
    goto v_4943;
    v_5120 = nil;
v_4943:
    if (v_5120 == nil) goto v_4941;
    goto v_4229;
v_4941:
    goto v_4963;
v_4959:
    v_5121 = stack[-3];
    goto v_4960;
v_4961:
    v_5120 = elt(env, 22); // !_
    goto v_4962;
v_4963:
    goto v_4959;
v_4960:
    goto v_4961;
v_4962:
    if (v_5121 == v_5120) goto v_4957;
    else goto v_4958;
v_4957:
    goto v_4229;
v_4958:
v_4232:
    v_5120 = stack[-2];
    fn = elt(env, 43); // reversip!*
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    fn = elt(env, 44); // list2wideid
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    goto v_4975;
v_4971:
    v_5121 = elt(env, 32); // "Name with double colon in detected:"
    goto v_4972;
v_4973:
    v_5120 = stack[-2];
    goto v_4974;
v_4975:
    goto v_4971;
v_4972:
    goto v_4973;
v_4974:
    v_5120 = list2(v_5121, v_5120);
    env = stack[-4];
    fn = elt(env, 46); // lprim
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    v_5120 = stack[-2];
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    v_5120 = stack[-3];
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    v_5120 = qvalue(elt(env, 15)); // nxtsym!*
    goto v_4211;
v_4233:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=19 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 19, -1);
    qvalue(elt(env, 19)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 20, 0);
    qvalue(elt(env, 20)) = nil; // !*lower
    v_5120 = lisp_true;
    qvalue(elt(env, 21)) = v_5120; // escaped!*
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_4229;
v_4234:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=19 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 19, -1);
    qvalue(elt(env, 19)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 20, 0);
    qvalue(elt(env, 20)) = nil; // !*lower
v_4991:
    v_5120 = stack[-3];
    fn = elt(env, 42); // wideid2list
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    stack[-3] = v_5120;
v_4992:
    v_5120 = stack[-3];
    if (v_5120 == nil) goto v_4998;
    else goto v_4999;
v_4998:
    goto v_4993;
v_4999:
    goto v_5006;
v_5002:
    v_5120 = stack[-3];
    v_5121 = qcar(v_5120);
    goto v_5003;
v_5004:
    v_5120 = stack[-2];
    goto v_5005;
v_5006:
    goto v_5002;
v_5003:
    goto v_5004;
v_5005:
    v_5120 = cons(v_5121, v_5120);
    env = stack[-4];
    stack[-2] = v_5120;
    v_5120 = stack[-3];
    v_5120 = qcdr(v_5120);
    stack[-3] = v_5120;
    goto v_4992;
v_4993:
    v_5120 = nil;
    qvalue(elt(env, 33)) = v_5120; // named!-character!*
    goto v_5021;
v_5017:
    fn = elt(env, 37); // readch1
    v_5121 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5121;
    goto v_5018;
v_5019:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_5020;
v_5021:
    goto v_5017;
v_5018:
    goto v_5019;
v_5020:
    if (v_5121 == v_5120) goto v_5015;
    else goto v_5016;
v_5015:
    v_5120 = elt(env, 14); // ! 
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    goto v_5030;
v_5026:
    v_5121 = elt(env, 34); // "***** End-of-file in string"
    goto v_5027;
v_5028:
    v_5120 = nil;
    goto v_5029;
v_5030:
    goto v_5026;
v_5027:
    goto v_5028;
v_5029:
    fn = elt(env, 47); // lpriw
    v_5120 = (*qfn2(fn))(fn, v_5121, v_5120);
    env = stack[-4];
    fn = elt(env, 40); // filenderr
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_5014;
v_5016:
    goto v_5044;
v_5040:
    v_5121 = stack[-3];
    goto v_5041;
v_5042:
    v_5120 = elt(env, 11); // !"
    goto v_5043;
v_5044:
    goto v_5040;
v_5041:
    goto v_5042;
v_5043:
    if (v_5121 == v_5120) goto v_5039;
    v_5120 = lisp_true;
    goto v_5037;
v_5039:
    v_5120 = qvalue(elt(env, 33)); // named!-character!*
    goto v_5037;
    v_5120 = nil;
v_5037:
    if (v_5120 == nil) goto v_5035;
    goto v_4991;
v_5035:
v_5014:
    v_5120 = nil;
    qvalue(elt(env, 33)) = v_5120; // named!-character!*
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_5065;
v_5061:
    v_5121 = stack[-3];
    goto v_5062;
v_5063:
    v_5120 = elt(env, 11); // !"
    goto v_5064;
v_5065:
    goto v_5061;
v_5062:
    goto v_5063;
v_5064:
    if (v_5121 == v_5120) goto v_5059;
    else goto v_5060;
v_5059:
    v_5120 = qvalue(elt(env, 33)); // named!-character!*
    v_5120 = (v_5120 == nil ? lisp_true : nil);
    goto v_5058;
v_5060:
    v_5120 = nil;
    goto v_5058;
    v_5120 = nil;
v_5058:
    if (v_5120 == nil) goto v_5056;
    goto v_4991;
v_5056:
    v_5120 = stack[-2];
    fn = elt(env, 43); // reversip!*
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    v_5120 = qcdr(v_5120);
    fn = elt(env, 48); // list2widestring
    v_5120 = (*qfn1(fn))(fn, v_5120);
    env = stack[-4];
    qvalue(elt(env, 15)) = v_5120; // nxtsym!*
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_5120 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 13)) = v_5120; // ttype!*
    v_5120 = stack[-3];
    qvalue(elt(env, 1)) = v_5120; // crchar!*
    goto v_4220;
v_4235:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=19 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 19, -1);
    qvalue(elt(env, 19)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 20, 0);
    qvalue(elt(env, 20)) = nil; // !*lower
v_5083:
    v_5120 = nil;
    qvalue(elt(env, 33)) = v_5120; // named!-character!*
    goto v_5101;
v_5097:
    fn = elt(env, 37); // readch1
    v_5121 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5121;
    goto v_5098;
v_5099:
    v_5120 = qvalue(elt(env, 3)); // !$eol!$
    goto v_5100;
v_5101:
    goto v_5097;
v_5098:
    goto v_5099;
v_5100:
    if (v_5121 == v_5120) goto v_5095;
    else goto v_5096;
v_5095:
    v_5120 = lisp_true;
    goto v_5094;
v_5096:
    goto v_5111;
v_5107:
    v_5121 = stack[-3];
    goto v_5108;
v_5109:
    v_5120 = qvalue(elt(env, 2)); // !$eof!$
    goto v_5110;
v_5111:
    goto v_5107;
v_5108:
    goto v_5109;
v_5110:
    v_5120 = (v_5121 == v_5120 ? lisp_true : nil);
    goto v_5094;
    v_5120 = nil;
v_5094:
    if (v_5120 == nil) goto v_5091;
    else goto v_5092;
v_5091:
    v_5120 = lisp_true;
    goto v_5090;
v_5092:
    v_5120 = qvalue(elt(env, 33)); // named!-character!*
    goto v_5090;
    v_5120 = nil;
v_5090:
    if (v_5120 == nil) goto v_5088;
    goto v_5083;
v_5088:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    fn = elt(env, 37); // readch1
    v_5120 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5120;
    goto v_4212;
v_4211:
    return onevalue(v_5120);
}



// Code for dp_sum

static LispObject CC_dp_sum(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4344, v_4345, v_4346;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
v_4205:
    v_4344 = stack[-1];
    if (v_4344 == nil) goto v_4211;
    else goto v_4212;
v_4211:
    v_4344 = stack[0];
    goto v_4210;
v_4212:
    v_4344 = stack[0];
    if (v_4344 == nil) goto v_4215;
    else goto v_4216;
v_4215:
    v_4344 = stack[-1];
    goto v_4210;
v_4216:
    goto v_4230;
v_4226:
    v_4344 = stack[-1];
    fn = elt(env, 1); // dp_lmon
    stack[-2] = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    goto v_4227;
v_4228:
    v_4344 = stack[0];
    fn = elt(env, 1); // dp_lmon
    v_4344 = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    goto v_4229;
v_4230:
    goto v_4226;
v_4227:
    goto v_4228;
v_4229:
    fn = elt(env, 2); // mo_compare
    v_4344 = (*qfn2(fn))(fn, stack[-2], v_4344);
    env = stack[-3];
    v_4346 = v_4344;
    goto v_4243;
v_4239:
    v_4345 = v_4346;
    goto v_4240;
v_4241:
    v_4344 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4242;
v_4243:
    goto v_4239;
v_4240:
    goto v_4241;
v_4242:
    if (v_4345 == v_4344) goto v_4237;
    else goto v_4238;
v_4237:
    goto v_4251;
v_4247:
    v_4344 = stack[-1];
    stack[-2] = qcar(v_4344);
    goto v_4248;
v_4249:
    goto v_4259;
v_4255:
    v_4344 = stack[-1];
    v_4345 = qcdr(v_4344);
    goto v_4256;
v_4257:
    v_4344 = stack[0];
    goto v_4258;
v_4259:
    goto v_4255;
v_4256:
    goto v_4257;
v_4258:
    v_4344 = CC_dp_sum(elt(env, 0), v_4345, v_4344);
    goto v_4250;
v_4251:
    goto v_4247;
v_4248:
    goto v_4249;
v_4250:
    {
        LispObject v_4350 = stack[-2];
        return cons(v_4350, v_4344);
    }
v_4238:
    goto v_4271;
v_4267:
    v_4345 = v_4346;
    goto v_4268;
v_4269:
    v_4344 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_4270;
v_4271:
    goto v_4267;
v_4268:
    goto v_4269;
v_4270:
    if (v_4345 == v_4344) goto v_4265;
    else goto v_4266;
v_4265:
    goto v_4279;
v_4275:
    v_4344 = stack[0];
    stack[-2] = qcar(v_4344);
    goto v_4276;
v_4277:
    goto v_4287;
v_4283:
    v_4345 = stack[-1];
    goto v_4284;
v_4285:
    v_4344 = stack[0];
    v_4344 = qcdr(v_4344);
    goto v_4286;
v_4287:
    goto v_4283;
v_4284:
    goto v_4285;
v_4286:
    v_4344 = CC_dp_sum(elt(env, 0), v_4345, v_4344);
    goto v_4278;
v_4279:
    goto v_4275;
v_4276:
    goto v_4277;
v_4278:
    {
        LispObject v_4351 = stack[-2];
        return cons(v_4351, v_4344);
    }
v_4266:
    goto v_4296;
v_4292:
    v_4344 = stack[-1];
    fn = elt(env, 3); // dp_lc
    stack[-2] = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    goto v_4293;
v_4294:
    v_4344 = stack[0];
    fn = elt(env, 3); // dp_lc
    v_4344 = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    goto v_4295;
v_4296:
    goto v_4292;
v_4293:
    goto v_4294;
v_4295:
    fn = elt(env, 4); // cali_bc_sum
    v_4344 = (*qfn2(fn))(fn, stack[-2], v_4344);
    env = stack[-3];
    stack[-2] = v_4344;
    v_4344 = stack[-2];
    fn = elt(env, 5); // cali_bc_zero!?
    v_4344 = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    if (v_4344 == nil) goto v_4304;
    goto v_4312;
v_4308:
    v_4344 = stack[-1];
    v_4345 = qcdr(v_4344);
    goto v_4309;
v_4310:
    v_4344 = stack[0];
    v_4344 = qcdr(v_4344);
    goto v_4311;
v_4312:
    goto v_4308;
v_4309:
    goto v_4310;
v_4311:
    stack[-1] = v_4345;
    stack[0] = v_4344;
    goto v_4205;
v_4304:
    goto v_4324;
v_4320:
    goto v_4330;
v_4326:
    goto v_4327;
v_4328:
    v_4344 = stack[-1];
    fn = elt(env, 1); // dp_lmon
    v_4344 = (*qfn1(fn))(fn, v_4344);
    env = stack[-3];
    goto v_4329;
v_4330:
    goto v_4326;
v_4327:
    goto v_4328;
v_4329:
    fn = elt(env, 6); // dp_term
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_4344);
    env = stack[-3];
    goto v_4321;
v_4322:
    goto v_4339;
v_4335:
    v_4344 = stack[-1];
    v_4345 = qcdr(v_4344);
    goto v_4336;
v_4337:
    v_4344 = stack[0];
    v_4344 = qcdr(v_4344);
    goto v_4338;
v_4339:
    goto v_4335;
v_4336:
    goto v_4337;
v_4338:
    v_4344 = CC_dp_sum(elt(env, 0), v_4345, v_4344);
    goto v_4323;
v_4324:
    goto v_4320;
v_4321:
    goto v_4322;
v_4323:
    {
        LispObject v_4352 = stack[-2];
        return cons(v_4352, v_4344);
    }
    v_4344 = nil;
    goto v_4210;
    v_4344 = nil;
v_4210:
    return onevalue(v_4344);
}



// Code for pneg

static LispObject CC_pneg(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4268, v_4269;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_4268 = v_4206;
// end of prologue
    stack[-4] = v_4268;
    v_4268 = stack[-4];
    if (v_4268 == nil) goto v_4217;
    else goto v_4218;
v_4217:
    v_4268 = nil;
    goto v_4212;
v_4218:
    v_4268 = stack[-4];
    v_4268 = qcar(v_4268);
    v_4269 = v_4268;
    goto v_4230;
v_4226:
    v_4268 = v_4269;
    stack[0] = qcar(v_4268);
    goto v_4227;
v_4228:
    v_4268 = v_4269;
    v_4268 = qcdr(v_4268);
    fn = elt(env, 1); // cneg
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-5];
    goto v_4229;
v_4230:
    goto v_4226;
v_4227:
    goto v_4228;
v_4229:
    v_4268 = cons(stack[0], v_4268);
    env = stack[-5];
    v_4268 = ncons(v_4268);
    env = stack[-5];
    stack[-2] = v_4268;
    stack[-3] = v_4268;
v_4213:
    v_4268 = stack[-4];
    v_4268 = qcdr(v_4268);
    stack[-4] = v_4268;
    v_4268 = stack[-4];
    if (v_4268 == nil) goto v_4240;
    else goto v_4241;
v_4240:
    v_4268 = stack[-3];
    goto v_4212;
v_4241:
    goto v_4249;
v_4245:
    stack[-1] = stack[-2];
    goto v_4246;
v_4247:
    v_4268 = stack[-4];
    v_4268 = qcar(v_4268);
    v_4269 = v_4268;
    goto v_4260;
v_4256:
    v_4268 = v_4269;
    stack[0] = qcar(v_4268);
    goto v_4257;
v_4258:
    v_4268 = v_4269;
    v_4268 = qcdr(v_4268);
    fn = elt(env, 1); // cneg
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-5];
    goto v_4259;
v_4260:
    goto v_4256;
v_4257:
    goto v_4258;
v_4259:
    v_4268 = cons(stack[0], v_4268);
    env = stack[-5];
    v_4268 = ncons(v_4268);
    env = stack[-5];
    goto v_4248;
v_4249:
    goto v_4245;
v_4246:
    goto v_4247;
v_4248:
    v_4268 = Lrplacd(nil, stack[-1], v_4268);
    env = stack[-5];
    v_4268 = stack[-2];
    v_4268 = qcdr(v_4268);
    stack[-2] = v_4268;
    goto v_4213;
v_4212:
    return onevalue(v_4268);
}



// Code for kernp

static LispObject CC_kernp(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4280, v_4281, v_4282;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4281 = v_4206;
// end of prologue
    goto v_4216;
v_4212:
    v_4280 = v_4281;
    v_4282 = qcdr(v_4280);
    goto v_4213;
v_4214:
    v_4280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4215;
v_4216:
    goto v_4212;
v_4213:
    goto v_4214;
v_4215:
    if (v_4282 == v_4280) goto v_4210;
    else goto v_4211;
v_4210:
    v_4280 = v_4281;
    v_4280 = qcar(v_4280);
    v_4281 = v_4280;
    v_4282 = v_4280;
    v_4280 = v_4282;
    if (!consp(v_4280)) goto v_4229;
    else goto v_4230;
v_4229:
    v_4280 = lisp_true;
    goto v_4228;
v_4230:
    v_4280 = v_4282;
    v_4280 = qcar(v_4280);
    v_4280 = (consp(v_4280) ? nil : lisp_true);
    goto v_4228;
    v_4280 = nil;
v_4228:
    if (v_4280 == nil) goto v_4222;
    else goto v_4223;
v_4222:
    v_4280 = v_4281;
    v_4280 = qcdr(v_4280);
    if (v_4280 == nil) goto v_4240;
    else goto v_4241;
v_4240:
    goto v_4252;
v_4248:
    v_4280 = v_4281;
    v_4280 = qcar(v_4280);
    v_4282 = qcdr(v_4280);
    goto v_4249;
v_4250:
    v_4280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4251;
v_4252:
    goto v_4248;
v_4249:
    goto v_4250;
v_4251:
    if (v_4282 == v_4280) goto v_4246;
    else goto v_4247;
v_4246:
    goto v_4261;
v_4257:
    v_4280 = v_4281;
    v_4280 = qcar(v_4280);
    v_4280 = qcar(v_4280);
    v_4281 = qcdr(v_4280);
    goto v_4258;
v_4259:
    v_4280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4260;
v_4261:
    goto v_4257;
v_4258:
    goto v_4259;
v_4260:
    v_4280 = (v_4281 == v_4280 ? lisp_true : nil);
    goto v_4245;
v_4247:
    v_4280 = nil;
    goto v_4245;
    v_4280 = nil;
v_4245:
    goto v_4239;
v_4241:
    v_4280 = nil;
    goto v_4239;
    v_4280 = nil;
v_4239:
    goto v_4221;
v_4223:
    v_4280 = nil;
    goto v_4221;
    v_4280 = nil;
v_4221:
    goto v_4209;
v_4211:
    v_4280 = nil;
    goto v_4209;
    v_4280 = nil;
v_4209:
    return onevalue(v_4280);
}



// Code for conv!:bf2i

static LispObject CC_convTbf2i(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4220, v_4221;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4220 = v_4206;
// end of prologue
    goto v_4213;
v_4209:
    v_4221 = v_4220;
    v_4221 = qcdr(v_4221);
    v_4221 = qcar(v_4221);
    goto v_4210;
v_4211:
    v_4220 = qcdr(v_4220);
    v_4220 = qcdr(v_4220);
    goto v_4212;
v_4213:
    goto v_4209;
v_4210:
    goto v_4211;
v_4212:
    {
        fn = elt(env, 1); // ashift
        return (*qfn2(fn))(fn, v_4221, v_4220);
    }
}



// Code for carx

static LispObject CC_carx(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4237, v_4238, v_4239;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_4238 = v_4207;
    v_4239 = v_4206;
// end of prologue
    v_4237 = v_4239;
    v_4237 = qcdr(v_4237);
    if (v_4237 == nil) goto v_4211;
    else goto v_4212;
v_4211:
    v_4237 = v_4239;
    v_4237 = qcar(v_4237);
    goto v_4210;
v_4212:
    goto v_4226;
v_4220:
    stack[-1] = elt(env, 1); // alg
    goto v_4221;
v_4222:
    stack[0] = (LispObject)80+TAG_FIXNUM; // 5
    goto v_4223;
v_4224:
    goto v_4234;
v_4230:
    v_4237 = elt(env, 2); // "Wrong number of arguments to"
    goto v_4231;
v_4232:
    goto v_4233;
v_4234:
    goto v_4230;
v_4231:
    goto v_4232;
v_4233:
    v_4237 = list2(v_4237, v_4238);
    env = stack[-2];
    goto v_4225;
v_4226:
    goto v_4220;
v_4221:
    goto v_4222;
v_4223:
    goto v_4224;
v_4225:
    {
        LispObject v_4242 = stack[-1];
        LispObject v_4243 = stack[0];
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_4242, v_4243, v_4237);
    }
    v_4237 = nil;
v_4210:
    return onevalue(v_4237);
}



// Code for quotdd

static LispObject CC_quotdd(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4292, v_4293, v_4294;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    v_4292 = stack[-1];
    if (!consp(v_4292)) goto v_4214;
    else goto v_4215;
v_4214:
    v_4292 = stack[0];
    if (!consp(v_4292)) goto v_4219;
    else goto v_4220;
v_4219:
    goto v_4227;
v_4223:
    v_4293 = stack[-1];
    goto v_4224;
v_4225:
    v_4292 = stack[0];
    goto v_4226;
v_4227:
    goto v_4223;
v_4224:
    goto v_4225;
v_4226:
    v_4292 = Ldivide(nil, v_4293, v_4292);
    v_4293 = v_4292;
    goto v_4238;
v_4234:
    v_4292 = v_4293;
    v_4294 = qcdr(v_4292);
    goto v_4235;
v_4236:
    v_4292 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4237;
v_4238:
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    if (v_4294 == v_4292) goto v_4232;
    else goto v_4233;
v_4232:
    v_4292 = v_4293;
    v_4292 = qcar(v_4292);
    goto v_4231;
v_4233:
    v_4292 = nil;
    goto v_4231;
    v_4292 = nil;
v_4231:
    goto v_4211;
v_4220:
    v_4292 = stack[0];
    v_4292 = qcar(v_4292);
    if (!symbolp(v_4292)) v_4292 = nil;
    else { v_4292 = qfastgets(v_4292);
           if (v_4292 != nil) { v_4292 = elt(v_4292, 34); // i2d
#ifdef RECORD_GET
             if (v_4292 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_4292 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_4292 == SPID_NOPROP) v_4292 = nil; }}
#endif
    v_4293 = v_4292;
    if (v_4292 == nil) goto v_4248;
    goto v_4257;
v_4253:
    goto v_4254;
v_4255:
    v_4292 = stack[-1];
    goto v_4256;
v_4257:
    goto v_4253;
v_4254:
    goto v_4255;
v_4256:
    v_4292 = Lapply1(nil, v_4293, v_4292);
    env = stack[-2];
    stack[-1] = v_4292;
    goto v_4218;
v_4248:
    v_4292 = stack[0];
    if (!consp(v_4292)) goto v_4264;
    else goto v_4265;
v_4264:
    v_4292 = stack[-1];
    v_4292 = qcar(v_4292);
    if (!symbolp(v_4292)) v_4292 = nil;
    else { v_4292 = qfastgets(v_4292);
           if (v_4292 != nil) { v_4292 = elt(v_4292, 34); // i2d
#ifdef RECORD_GET
             if (v_4292 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_4292 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_4292 == SPID_NOPROP) v_4292 = nil; }}
#endif
    v_4293 = v_4292;
    goto v_4263;
v_4265:
    v_4292 = nil;
    goto v_4263;
    v_4292 = nil;
v_4263:
    if (v_4292 == nil) goto v_4261;
    goto v_4278;
v_4274:
    goto v_4275;
v_4276:
    v_4292 = stack[0];
    goto v_4277;
v_4278:
    goto v_4274;
v_4275:
    goto v_4276;
v_4277:
    v_4292 = Lapply1(nil, v_4293, v_4292);
    env = stack[-2];
    stack[0] = v_4292;
    goto v_4218;
v_4261:
v_4218:
    goto v_4213;
v_4215:
v_4213:
    goto v_4288;
v_4282:
    v_4294 = stack[-1];
    goto v_4283;
v_4284:
    v_4293 = stack[0];
    goto v_4285;
v_4286:
    v_4292 = elt(env, 1); // quotient
    goto v_4287;
v_4288:
    goto v_4282;
v_4283:
    goto v_4284;
v_4285:
    goto v_4286;
v_4287:
    {
        fn = elt(env, 2); // dcombine
        return (*qfnn(fn))(fn, 3, v_4294, v_4293, v_4292);
    }
v_4211:
    return onevalue(v_4292);
}



// Code for comfac

static LispObject CC_comfac(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4369, v_4370;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_4206;
// end of prologue
    stack[-3] = nil;
    v_4369 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_4369)) v_4369 = nil;
    else { v_4369 = qfastgets(v_4369);
           if (v_4369 != nil) { v_4369 = elt(v_4369, 3); // field
#ifdef RECORD_GET
             if (v_4369 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_4369 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_4369 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_4369 == SPID_NOPROP) v_4369 = nil; else v_4369 = lisp_true; }}
#endif
    if (v_4369 == nil) goto v_4220;
    goto v_4228;
v_4224:
    v_4369 = stack[-2];
    fn = elt(env, 2); // lnc
    v_4370 = (*qfn1(fn))(fn, v_4369);
    env = stack[-4];
    stack[-3] = v_4370;
    goto v_4225;
v_4226:
    v_4369 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4227;
v_4228:
    goto v_4224;
v_4225:
    goto v_4226;
v_4227:
    v_4369 = Lneq(nil, v_4370, v_4369);
    env = stack[-4];
    goto v_4218;
v_4220:
    v_4369 = nil;
    goto v_4218;
    v_4369 = nil;
v_4218:
    if (v_4369 == nil) goto v_4216;
    goto v_4240;
v_4236:
    v_4369 = stack[-3];
    fn = elt(env, 3); // !:recip
    v_4370 = (*qfn1(fn))(fn, v_4369);
    env = stack[-4];
    goto v_4237;
v_4238:
    v_4369 = stack[-2];
    goto v_4239;
v_4240:
    goto v_4236;
v_4237:
    goto v_4238;
v_4239:
    fn = elt(env, 4); // multd
    v_4369 = (*qfn2(fn))(fn, v_4370, v_4369);
    env = stack[-4];
    stack[-2] = v_4369;
    goto v_4214;
v_4216:
v_4214:
    v_4369 = stack[-2];
    v_4369 = qcdr(v_4369);
    if (v_4369 == nil) goto v_4246;
    else goto v_4247;
v_4246:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    goto v_4211;
v_4247:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4369 = qcdr(v_4369);
    stack[-3] = v_4369;
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4369 = qcar(v_4369);
    v_4369 = qcar(v_4369);
    stack[-1] = v_4369;
v_4212:
    v_4369 = stack[-2];
    v_4369 = qcdr(v_4369);
    stack[-2] = v_4369;
    goto v_4269;
v_4265:
    goto v_4275;
v_4271:
    v_4370 = stack[-2];
    goto v_4272;
v_4273:
    v_4369 = stack[-1];
    goto v_4274;
v_4275:
    goto v_4271;
v_4272:
    goto v_4273;
v_4274:
    fn = elt(env, 5); // degr
    v_4370 = (*qfn2(fn))(fn, v_4370, v_4369);
    env = stack[-4];
    goto v_4266;
v_4267:
    v_4369 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4268;
v_4269:
    goto v_4265;
v_4266:
    goto v_4267;
v_4268:
    if (v_4370 == v_4369) goto v_4263;
    else goto v_4264;
v_4263:
    goto v_4284;
v_4280:
    stack[0] = nil;
    goto v_4281;
v_4282:
    v_4369 = stack[-2];
    if (!consp(v_4369)) goto v_4296;
    else goto v_4297;
v_4296:
    v_4369 = lisp_true;
    goto v_4295;
v_4297:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4369 = (consp(v_4369) ? nil : lisp_true);
    goto v_4295;
    v_4369 = nil;
v_4295:
    if (v_4369 == nil) goto v_4293;
    v_4369 = lisp_true;
    goto v_4291;
v_4293:
    v_4369 = stack[-1];
    fn = elt(env, 6); // noncomp
    v_4369 = (*qfn1(fn))(fn, v_4369);
    env = stack[-4];
    if (v_4369 == nil) goto v_4310;
    else goto v_4311;
v_4310:
    v_4369 = nil;
    goto v_4309;
v_4311:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4369 = qcar(v_4369);
    v_4369 = qcar(v_4369);
    fn = elt(env, 6); // noncomp
    v_4369 = (*qfn1(fn))(fn, v_4369);
    env = stack[-4];
    goto v_4309;
    v_4369 = nil;
v_4309:
    v_4369 = (v_4369 == nil ? lisp_true : nil);
    goto v_4291;
    v_4369 = nil;
v_4291:
    if (v_4369 == nil) goto v_4289;
    goto v_4328;
v_4324:
    v_4370 = stack[-3];
    goto v_4325;
v_4326:
    v_4369 = stack[-2];
    goto v_4327;
v_4328:
    goto v_4324;
v_4325:
    goto v_4326;
v_4327:
    fn = elt(env, 7); // gcdf
    v_4369 = (*qfn2(fn))(fn, v_4370, v_4369);
    goto v_4287;
v_4289:
    v_4369 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4287;
    v_4369 = nil;
v_4287:
    goto v_4283;
v_4284:
    goto v_4280;
v_4281:
    goto v_4282;
v_4283:
    {
        LispObject v_4375 = stack[0];
        return cons(v_4375, v_4369);
    }
v_4264:
    v_4369 = stack[-2];
    v_4369 = qcdr(v_4369);
    if (v_4369 == nil) goto v_4334;
    else goto v_4335;
v_4334:
    goto v_4343;
v_4339:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    stack[0] = qcar(v_4369);
    goto v_4340;
v_4341:
    goto v_4352;
v_4348:
    v_4370 = stack[-3];
    goto v_4349;
v_4350:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4369 = qcdr(v_4369);
    goto v_4351;
v_4352:
    goto v_4348;
v_4349:
    goto v_4350;
v_4351:
    fn = elt(env, 7); // gcdf
    v_4369 = (*qfn2(fn))(fn, v_4370, v_4369);
    goto v_4342;
v_4343:
    goto v_4339;
v_4340:
    goto v_4341;
v_4342:
    {
        LispObject v_4376 = stack[0];
        return cons(v_4376, v_4369);
    }
v_4335:
    goto v_4364;
v_4360:
    v_4369 = stack[-2];
    v_4369 = qcar(v_4369);
    v_4370 = qcdr(v_4369);
    goto v_4361;
v_4362:
    v_4369 = stack[-3];
    goto v_4363;
v_4364:
    goto v_4360;
v_4361:
    goto v_4362;
v_4363:
    fn = elt(env, 7); // gcdf
    v_4369 = (*qfn2(fn))(fn, v_4370, v_4369);
    env = stack[-4];
    stack[-3] = v_4369;
    goto v_4262;
v_4262:
    goto v_4212;
v_4211:
    return onevalue(v_4369);
}



// Code for talp_simplat2

static LispObject CC_talp_simplat2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4269, v_4270, v_4271;
    LispObject fn;
    LispObject v_4208, v_4207, v_4206;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplat2");
    va_start(aa, nargs);
    v_4206 = va_arg(aa, LispObject);
    v_4207 = va_arg(aa, LispObject);
    v_4208 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4208,v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4206,v_4207,v_4208);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4208;
    stack[-1] = v_4207;
    stack[-2] = v_4206;
// end of prologue
    v_4269 = stack[0];
    fn = elt(env, 1); // talp_invp
    v_4269 = (*qfn1(fn))(fn, v_4269);
    env = stack[-3];
    if (v_4269 == nil) goto v_4213;
    goto v_4223;
v_4217:
    v_4271 = stack[-2];
    goto v_4218;
v_4219:
    v_4270 = stack[-1];
    goto v_4220;
v_4221:
    v_4269 = stack[0];
    goto v_4222;
v_4223:
    goto v_4217;
v_4218:
    goto v_4219;
v_4220:
    goto v_4221;
v_4222:
    {
        fn = elt(env, 2); // talp_simplatrinv
        return (*qfnn(fn))(fn, 3, v_4271, v_4270, v_4269);
    }
v_4213:
    v_4269 = stack[-1];
    if (!consp(v_4269)) goto v_4227;
    else goto v_4228;
v_4227:
    goto v_4237;
v_4231:
    v_4271 = stack[-2];
    goto v_4232;
v_4233:
    v_4270 = stack[-1];
    goto v_4234;
v_4235:
    v_4269 = stack[0];
    goto v_4236;
v_4237:
    goto v_4231;
v_4232:
    goto v_4233;
v_4234:
    goto v_4235;
v_4236:
    {
        fn = elt(env, 3); // talp_simplatat
        return (*qfnn(fn))(fn, 3, v_4271, v_4270, v_4269);
    }
v_4228:
    v_4269 = stack[-1];
    fn = elt(env, 1); // talp_invp
    v_4269 = (*qfn1(fn))(fn, v_4269);
    env = stack[-3];
    if (v_4269 == nil) goto v_4242;
    goto v_4252;
v_4246:
    v_4271 = stack[-2];
    goto v_4247;
v_4248:
    v_4270 = stack[-1];
    goto v_4249;
v_4250:
    v_4269 = stack[0];
    goto v_4251;
v_4252:
    goto v_4246;
v_4247:
    goto v_4248;
v_4249:
    goto v_4250;
v_4251:
    {
        fn = elt(env, 4); // talp_simplatlinv
        return (*qfnn(fn))(fn, 3, v_4271, v_4270, v_4269);
    }
v_4242:
    goto v_4265;
v_4259:
    v_4271 = stack[-2];
    goto v_4260;
v_4261:
    v_4270 = stack[-1];
    goto v_4262;
v_4263:
    v_4269 = stack[0];
    goto v_4264;
v_4265:
    goto v_4259;
v_4260:
    goto v_4261;
v_4262:
    goto v_4263;
v_4264:
    {
        fn = elt(env, 5); // talp_simplatfn
        return (*qfnn(fn))(fn, 3, v_4271, v_4270, v_4269);
    }
    v_4269 = nil;
    return onevalue(v_4269);
}



// Code for cl_susiminlevel

static LispObject CC_cl_susiminlevel(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4241, v_4242, v_4243, v_4244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4243 = v_4207;
    v_4244 = v_4206;
// end of prologue
    goto v_4217;
v_4213:
    v_4242 = v_4244;
    goto v_4214;
v_4215:
    v_4241 = elt(env, 1); // ignore
    goto v_4216;
v_4217:
    goto v_4213;
v_4214:
    goto v_4215;
v_4216:
    if (v_4242 == v_4241) goto v_4211;
    else goto v_4212;
v_4211:
    v_4241 = v_4243;
    goto v_4210;
v_4212:
    goto v_4227;
v_4223:
    v_4242 = v_4243;
    goto v_4224;
v_4225:
    v_4241 = elt(env, 1); // ignore
    goto v_4226;
v_4227:
    goto v_4223;
v_4224:
    goto v_4225;
v_4226:
    if (v_4242 == v_4241) goto v_4221;
    else goto v_4222;
v_4221:
    v_4241 = v_4244;
    goto v_4210;
v_4222:
    goto v_4238;
v_4234:
    v_4241 = v_4244;
    goto v_4235;
v_4236:
    v_4242 = v_4243;
    goto v_4237;
v_4238:
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    {
        fn = elt(env, 2); // min
        return (*qfn2(fn))(fn, v_4241, v_4242);
    }
    v_4241 = nil;
v_4210:
    return onevalue(v_4241);
}



// Code for ibalp_vequal

static LispObject CC_ibalp_vequal(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4219, v_4220;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4219 = v_4207;
    v_4220 = v_4206;
// end of prologue
    goto v_4213;
v_4209:
    v_4220 = qcar(v_4220);
    goto v_4210;
v_4211:
    v_4219 = qcar(v_4219);
    goto v_4212;
v_4213:
    goto v_4209;
v_4210:
    goto v_4211;
v_4212:
    v_4219 = (v_4220 == v_4219 ? lisp_true : nil);
    return onevalue(v_4219);
}



// Code for quotk

static LispObject CC_quotk(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4278, v_4279, v_4280;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    goto v_4214;
v_4210:
    v_4278 = stack[-1];
    v_4278 = qcar(v_4278);
    v_4279 = qcdr(v_4278);
    goto v_4211;
v_4212:
    v_4278 = stack[0];
    goto v_4213;
v_4214:
    goto v_4210;
v_4211:
    goto v_4212;
v_4213:
    fn = elt(env, 1); // quotf1
    v_4278 = (*qfn2(fn))(fn, v_4279, v_4278);
    env = stack[-3];
    stack[-2] = v_4278;
    v_4278 = stack[-2];
    if (v_4278 == nil) goto v_4223;
    v_4278 = stack[-1];
    v_4278 = qcdr(v_4278);
    if (v_4278 == nil) goto v_4227;
    else goto v_4228;
v_4227:
    goto v_4237;
v_4233:
    v_4278 = stack[-1];
    v_4278 = qcar(v_4278);
    v_4279 = qcar(v_4278);
    goto v_4234;
v_4235:
    v_4278 = stack[-2];
    goto v_4236;
v_4237:
    goto v_4233;
v_4234:
    goto v_4235;
v_4236:
    v_4278 = cons(v_4279, v_4278);
    return ncons(v_4278);
v_4228:
    goto v_4249;
v_4245:
    v_4278 = stack[-1];
    v_4279 = qcdr(v_4278);
    goto v_4246;
v_4247:
    v_4278 = stack[0];
    goto v_4248;
v_4249:
    goto v_4245;
v_4246:
    goto v_4247;
v_4248:
    fn = elt(env, 1); // quotf1
    v_4278 = (*qfn2(fn))(fn, v_4279, v_4278);
    v_4279 = v_4278;
    if (v_4279 == nil) goto v_4257;
    goto v_4266;
v_4260:
    v_4279 = stack[-1];
    v_4279 = qcar(v_4279);
    v_4280 = qcar(v_4279);
    goto v_4261;
v_4262:
    v_4279 = stack[-2];
    goto v_4263;
v_4264:
    goto v_4265;
v_4266:
    goto v_4260;
v_4261:
    goto v_4262;
v_4263:
    goto v_4264;
v_4265:
    return acons(v_4280, v_4279, v_4278);
v_4257:
    v_4278 = nil;
    goto v_4255;
    v_4278 = nil;
v_4255:
    goto v_4226;
    v_4278 = nil;
v_4226:
    goto v_4221;
v_4223:
    v_4278 = nil;
    goto v_4221;
    v_4278 = nil;
v_4221:
    return onevalue(v_4278);
}



// Code for ps!:last!-term

static LispObject CC_psTlastKterm(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4249, v_4250, v_4251;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4251 = v_4206;
// end of prologue
    v_4249 = v_4251;
    if (!consp(v_4249)) goto v_4214;
    else goto v_4215;
v_4214:
    v_4249 = lisp_true;
    goto v_4213;
v_4215:
    goto v_4228;
v_4224:
    v_4249 = v_4251;
    v_4250 = qcar(v_4249);
    goto v_4225;
v_4226:
    v_4249 = elt(env, 1); // !:ps!:
    goto v_4227;
v_4228:
    goto v_4224;
v_4225:
    goto v_4226;
v_4227:
    if (v_4250 == v_4249) goto v_4223;
    v_4249 = v_4251;
    v_4249 = qcar(v_4249);
    if (!symbolp(v_4249)) v_4249 = nil;
    else { v_4249 = qfastgets(v_4249);
           if (v_4249 != nil) { v_4249 = elt(v_4249, 8); // dname
#ifdef RECORD_GET
             if (v_4249 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_4249 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_4249 == SPID_NOPROP) v_4249 = nil; }}
#endif
    goto v_4221;
v_4223:
    v_4249 = nil;
    goto v_4221;
    v_4249 = nil;
v_4221:
    goto v_4213;
    v_4249 = nil;
v_4213:
    if (v_4249 == nil) goto v_4211;
    v_4249 = qvalue(elt(env, 2)); // ps!:max!-order
    goto v_4209;
v_4211:
    goto v_4246;
v_4242:
    v_4250 = v_4251;
    goto v_4243;
v_4244:
    v_4249 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4245;
v_4246:
    goto v_4242;
v_4243:
    goto v_4244;
v_4245:
    {
        fn = elt(env, 3); // ps!:getv
        return (*qfn2(fn))(fn, v_4250, v_4249);
    }
    v_4249 = nil;
v_4209:
    return onevalue(v_4249);
}



// Code for initbrsea

static LispObject CC_initbrsea(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4325, v_4326, v_4327;
    LispObject fn;
    argcheck(nargs, 0, "initbrsea");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
    v_4325 = (LispObject)3200+TAG_FIXNUM; // 200
    stack[-2] = v_4325;
    v_4325 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v_4325;
v_4214:
    goto v_4226;
v_4222:
    v_4326 = qvalue(elt(env, 2)); // rowmax
    goto v_4223;
v_4224:
    v_4325 = stack[-1];
    goto v_4225;
v_4226:
    goto v_4222;
v_4223:
    goto v_4224;
v_4225:
    v_4325 = difference2(v_4326, v_4325);
    env = stack[-3];
    v_4325 = Lminusp(nil, v_4325);
    env = stack[-3];
    if (v_4325 == nil) goto v_4219;
    goto v_4213;
v_4219:
    goto v_4238;
v_4234:
    goto v_4243;
v_4239:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_4240;
v_4241:
    goto v_4250;
v_4246:
    v_4326 = qvalue(elt(env, 4)); // maxvar
    goto v_4247;
v_4248:
    v_4325 = stack[-1];
    goto v_4249;
v_4250:
    goto v_4246;
v_4247:
    goto v_4248;
v_4249:
    v_4325 = plus2(v_4326, v_4325);
    env = stack[-3];
    goto v_4242;
v_4243:
    goto v_4239;
v_4240:
    goto v_4241;
v_4242:
    v_4326 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_4325-TAG_FIXNUM)/(16/CELL)));
    goto v_4235;
v_4236:
    v_4325 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4237;
v_4238:
    goto v_4234;
v_4235:
    goto v_4236;
v_4237:
    v_4325 = *(LispObject *)((char *)v_4326 + (CELL-TAG_VECTOR) + (((intptr_t)v_4325-TAG_FIXNUM)/(16/CELL)));
    if (v_4325 == nil) goto v_4233;
    v_4325 = stack[-1];
    fn = elt(env, 7); // initwght
    v_4325 = (*qfn1(fn))(fn, v_4325);
    env = stack[-3];
    goto v_4231;
v_4233:
v_4231:
    v_4325 = stack[-1];
    v_4325 = add1(v_4325);
    env = stack[-3];
    stack[-1] = v_4325;
    goto v_4214;
v_4213:
    fn = elt(env, 8); // redcodmat
    v_4325 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_4325 = qvalue(elt(env, 5)); // codhisto
    if (v_4325 == nil) goto v_4264;
    v_4325 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_4325;
v_4269:
    goto v_4281;
v_4277:
    v_4326 = (LispObject)3200+TAG_FIXNUM; // 200
    goto v_4278;
v_4279:
    v_4325 = stack[0];
    goto v_4280;
v_4281:
    goto v_4277;
v_4278:
    goto v_4279;
v_4280:
    v_4325 = difference2(v_4326, v_4325);
    env = stack[-3];
    v_4325 = Lminusp(nil, v_4325);
    env = stack[-3];
    if (v_4325 == nil) goto v_4274;
    goto v_4268;
v_4274:
    goto v_4291;
v_4285:
    v_4327 = qvalue(elt(env, 5)); // codhisto
    goto v_4286;
v_4287:
    v_4326 = stack[0];
    goto v_4288;
v_4289:
    v_4325 = nil;
    goto v_4290;
v_4291:
    goto v_4285;
v_4286:
    goto v_4287;
v_4288:
    goto v_4289;
v_4290:
    *(LispObject *)((char *)v_4327 + (CELL-TAG_VECTOR) + (((intptr_t)v_4326-TAG_FIXNUM)/(16/CELL))) = v_4325;
    v_4325 = stack[0];
    v_4325 = add1(v_4325);
    env = stack[-3];
    stack[0] = v_4325;
    goto v_4269;
v_4268:
    goto v_4262;
v_4264:
    v_4325 = stack[-2];
    v_4325 = Lmkvect(nil, v_4325);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_4325; // codhisto
    goto v_4262;
v_4262:
    v_4325 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_4325; // headhisto
    v_4325 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_4325;
v_4305:
    goto v_4317;
v_4313:
    v_4326 = qvalue(elt(env, 2)); // rowmax
    goto v_4314;
v_4315:
    v_4325 = stack[0];
    goto v_4316;
v_4317:
    goto v_4313;
v_4314:
    goto v_4315;
v_4316:
    v_4325 = difference2(v_4326, v_4325);
    env = stack[-3];
    v_4325 = Lminusp(nil, v_4325);
    env = stack[-3];
    if (v_4325 == nil) goto v_4310;
    goto v_4304;
v_4310:
    v_4325 = stack[0];
    fn = elt(env, 9); // inshisto
    v_4325 = (*qfn1(fn))(fn, v_4325);
    env = stack[-3];
    v_4325 = stack[0];
    v_4325 = add1(v_4325);
    env = stack[-3];
    stack[0] = v_4325;
    goto v_4305;
v_4304:
    v_4325 = nil;
    return onevalue(v_4325);
}



// Code for take!-impart

static LispObject CC_takeKimpart(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4233, v_4234;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    goto v_4213;
v_4209:
    goto v_4219;
v_4215:
    v_4233 = stack[0];
    v_4233 = qcar(v_4233);
    fn = elt(env, 1); // impartf
    v_4234 = (*qfn1(fn))(fn, v_4233);
    env = stack[-2];
    goto v_4216;
v_4217:
    v_4233 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4218;
v_4219:
    goto v_4215;
v_4216:
    goto v_4217;
v_4218:
    stack[-1] = cons(v_4234, v_4233);
    env = stack[-2];
    goto v_4210;
v_4211:
    goto v_4229;
v_4225:
    v_4234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4226;
v_4227:
    v_4233 = stack[0];
    v_4233 = qcdr(v_4233);
    goto v_4228;
v_4229:
    goto v_4225;
v_4226:
    goto v_4227;
v_4228:
    v_4233 = cons(v_4234, v_4233);
    env = stack[-2];
    goto v_4212;
v_4213:
    goto v_4209;
v_4210:
    goto v_4211;
v_4212:
    {
        LispObject v_4237 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_4237, v_4233);
    }
}



// Code for errorset2

static LispObject CC_errorset2(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4223, v_4224, v_4225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_4224 = v_4206;
// end of prologue
// Binding !*protfg
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*protfg
    v_4223 = lisp_true;
    qvalue(elt(env, 1)) = v_4223; // !*protfg
    goto v_4219;
v_4213:
    v_4225 = v_4224;
    goto v_4214;
v_4215:
    v_4224 = nil;
    goto v_4216;
v_4217:
    v_4223 = nil;
    goto v_4218;
v_4219:
    goto v_4213;
v_4214:
    goto v_4215;
v_4216:
    goto v_4217;
v_4218:
    fn = elt(env, 2); // errorset
    v_4223 = (*qfnn(fn))(fn, 3, v_4225, v_4224, v_4223);
    ;}  // end of a binding scope
    return onevalue(v_4223);
}



// Code for mv!-pow!-!+

static LispObject CC_mvKpowKL(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4243, v_4244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    stack[-2] = nil;
v_4212:
    v_4243 = stack[-1];
    if (v_4243 == nil) goto v_4215;
    else goto v_4216;
v_4215:
    v_4243 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_4243);
    }
v_4216:
    goto v_4227;
v_4223:
    goto v_4233;
v_4229:
    v_4243 = stack[-1];
    v_4244 = qcar(v_4243);
    goto v_4230;
v_4231:
    v_4243 = stack[0];
    v_4243 = qcar(v_4243);
    goto v_4232;
v_4233:
    goto v_4229;
v_4230:
    goto v_4231;
v_4232:
    v_4244 = plus2(v_4244, v_4243);
    env = stack[-3];
    goto v_4224;
v_4225:
    v_4243 = stack[-2];
    goto v_4226;
v_4227:
    goto v_4223;
v_4224:
    goto v_4225;
v_4226:
    v_4243 = cons(v_4244, v_4243);
    env = stack[-3];
    stack[-2] = v_4243;
    v_4243 = stack[-1];
    v_4243 = qcdr(v_4243);
    stack[-1] = v_4243;
    v_4243 = stack[0];
    v_4243 = qcdr(v_4243);
    stack[0] = v_4243;
    goto v_4212;
    v_4243 = nil;
    return onevalue(v_4243);
}



// Code for !*i2gi

static LispObject CC_Hi2gi(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4219, v_4220, v_4221;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4219 = v_4206;
// end of prologue
    goto v_4215;
v_4209:
    v_4221 = elt(env, 1); // !:gi!:
    goto v_4210;
v_4211:
    v_4220 = v_4219;
    goto v_4212;
v_4213:
    v_4219 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4214;
v_4215:
    goto v_4209;
v_4210:
    goto v_4211;
v_4212:
    goto v_4213;
v_4214:
    return list2star(v_4221, v_4220, v_4219);
}



// Code for ptoken

static LispObject CC_ptoken(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4270, v_4271;
    LispObject fn;
    argcheck(nargs, 0, "ptoken");
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
    fn = elt(env, 5); // token
    v_4270 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_4270;
    goto v_4223;
v_4219:
    v_4271 = stack[0];
    goto v_4220;
v_4221:
    v_4270 = elt(env, 1); // !)
    goto v_4222;
v_4223:
    goto v_4219;
v_4220:
    goto v_4221;
v_4222:
    if (v_4271 == v_4270) goto v_4217;
    else goto v_4218;
v_4217:
    goto v_4231;
v_4227:
    v_4271 = qvalue(elt(env, 2)); // outl!*
    goto v_4228;
v_4229:
    v_4270 = elt(env, 3); // ! 
    goto v_4230;
v_4231:
    goto v_4227;
v_4228:
    goto v_4229;
v_4230:
    v_4270 = Leqcar(nil, v_4271, v_4270);
    env = stack[-1];
    goto v_4216;
v_4218:
    v_4270 = nil;
    goto v_4216;
    v_4270 = nil;
v_4216:
    if (v_4270 == nil) goto v_4214;
    v_4270 = qvalue(elt(env, 2)); // outl!*
    v_4270 = qcdr(v_4270);
    qvalue(elt(env, 2)) = v_4270; // outl!*
    goto v_4212;
v_4214:
v_4212:
    v_4270 = stack[0];
    fn = elt(env, 6); // prin2x
    v_4270 = (*qfn1(fn))(fn, v_4270);
    env = stack[-1];
    goto v_4253;
v_4249:
    v_4271 = stack[0];
    goto v_4250;
v_4251:
    v_4270 = elt(env, 4); // !(
    goto v_4252;
v_4253:
    goto v_4249;
v_4250:
    goto v_4251;
v_4252:
    if (v_4271 == v_4270) goto v_4247;
    else goto v_4248;
v_4247:
    v_4270 = lisp_true;
    goto v_4246;
v_4248:
    goto v_4263;
v_4259:
    v_4271 = stack[0];
    goto v_4260;
v_4261:
    v_4270 = elt(env, 1); // !)
    goto v_4262;
v_4263:
    goto v_4259;
v_4260:
    goto v_4261;
v_4262:
    v_4270 = (v_4271 == v_4270 ? lisp_true : nil);
    goto v_4246;
    v_4270 = nil;
v_4246:
    if (v_4270 == nil) goto v_4243;
    else goto v_4244;
v_4243:
    v_4270 = elt(env, 3); // ! 
    fn = elt(env, 6); // prin2x
    v_4270 = (*qfn1(fn))(fn, v_4270);
    goto v_4242;
v_4244:
v_4242:
    v_4270 = stack[0];
    return onevalue(v_4270);
}



// Code for wuorderp

static LispObject CC_wuorderp(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4322, v_4323, v_4324, v_4325, v_4326, v_4327;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
// copy arguments values to proper place
    v_4326 = v_4207;
    v_4327 = v_4206;
// end of prologue
    v_4324 = nil;
    goto v_4221;
v_4217:
    v_4323 = v_4327;
    goto v_4218;
v_4219:
    v_4322 = v_4326;
    goto v_4220;
v_4221:
    goto v_4217;
v_4218:
    goto v_4219;
v_4220:
    if (v_4323 == v_4322) goto v_4215;
    else goto v_4216;
v_4215:
    v_4322 = nil;
    goto v_4212;
v_4216:
    v_4322 = qvalue(elt(env, 1)); // wukord!*
    v_4325 = v_4322;
v_4228:
    v_4322 = v_4325;
    if (v_4322 == nil) goto v_4231;
    v_4322 = v_4324;
    if (v_4322 == nil) goto v_4235;
    else goto v_4231;
v_4235:
    goto v_4232;
v_4231:
    goto v_4227;
v_4232:
    goto v_4246;
v_4242:
    v_4323 = v_4327;
    goto v_4243;
v_4244:
    v_4322 = v_4325;
    v_4322 = qcar(v_4322);
    goto v_4245;
v_4246:
    goto v_4242;
v_4243:
    goto v_4244;
v_4245:
    if (v_4323 == v_4322) goto v_4240;
    else goto v_4241;
v_4240:
    goto v_4258;
v_4254:
    v_4323 = v_4326;
    goto v_4255;
v_4256:
    v_4322 = v_4325;
    v_4322 = qcdr(v_4322);
    goto v_4257;
v_4258:
    goto v_4254;
v_4255:
    goto v_4256;
v_4257:
    v_4322 = Lmemq(nil, v_4323, v_4322);
    if (v_4322 == nil) goto v_4253;
    v_4322 = elt(env, 2); // yes
    goto v_4251;
v_4253:
    v_4322 = elt(env, 3); // no
    goto v_4251;
    v_4322 = nil;
v_4251:
    v_4324 = v_4322;
    goto v_4239;
v_4241:
    goto v_4273;
v_4269:
    v_4323 = v_4326;
    goto v_4270;
v_4271:
    v_4322 = v_4325;
    v_4322 = qcar(v_4322);
    goto v_4272;
v_4273:
    goto v_4269;
v_4270:
    goto v_4271;
v_4272:
    if (v_4323 == v_4322) goto v_4267;
    else goto v_4268;
v_4267:
    goto v_4285;
v_4281:
    v_4323 = v_4327;
    goto v_4282;
v_4283:
    v_4322 = v_4325;
    v_4322 = qcdr(v_4322);
    goto v_4284;
v_4285:
    goto v_4281;
v_4282:
    goto v_4283;
v_4284:
    v_4322 = Lmemq(nil, v_4323, v_4322);
    if (v_4322 == nil) goto v_4280;
    v_4322 = elt(env, 3); // no
    goto v_4278;
v_4280:
    v_4322 = elt(env, 2); // yes
    goto v_4278;
    v_4322 = nil;
v_4278:
    v_4324 = v_4322;
    goto v_4239;
v_4268:
    v_4322 = v_4325;
    v_4322 = qcdr(v_4322);
    v_4325 = v_4322;
    goto v_4239;
v_4239:
    goto v_4228;
v_4227:
    v_4322 = v_4324;
    if (v_4322 == nil) goto v_4301;
    goto v_4307;
v_4303:
    v_4322 = v_4324;
    goto v_4304;
v_4305:
    v_4323 = elt(env, 2); // yes
    goto v_4306;
v_4307:
    goto v_4303;
v_4304:
    goto v_4305;
v_4306:
    v_4322 = (v_4322 == v_4323 ? lisp_true : nil);
    goto v_4299;
v_4301:
    goto v_4318;
v_4314:
    v_4322 = v_4327;
    goto v_4315;
v_4316:
    v_4323 = v_4326;
    goto v_4317;
v_4318:
    goto v_4314;
v_4315:
    goto v_4316;
v_4317:
    v_4322 = Lorderp(nil, v_4322, v_4323);
    v_4322 = (v_4322 == nil ? lisp_true : nil);
    goto v_4299;
    v_4322 = nil;
v_4299:
v_4212:
    return onevalue(v_4322);
}



// Code for freevarinexptchk

static LispObject CC_freevarinexptchk(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4247;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
v_4205:
    v_4247 = stack[0];
    if (!consp(v_4247)) goto v_4214;
    else goto v_4215;
v_4214:
    v_4247 = lisp_true;
    goto v_4213;
v_4215:
    v_4247 = stack[0];
    v_4247 = qcar(v_4247);
    v_4247 = (consp(v_4247) ? nil : lisp_true);
    goto v_4213;
    v_4247 = nil;
v_4213:
    if (v_4247 == nil) goto v_4210;
    else goto v_4211;
v_4210:
    v_4247 = stack[0];
    v_4247 = qcar(v_4247);
    v_4247 = qcar(v_4247);
    v_4247 = qcdr(v_4247);
    if (is_number(v_4247)) goto v_4226;
    v_4247 = lisp_true;
    goto v_4224;
v_4226:
    v_4247 = stack[0];
    v_4247 = qcar(v_4247);
    v_4247 = qcdr(v_4247);
    v_4247 = CC_freevarinexptchk(elt(env, 0), v_4247);
    env = stack[-1];
    if (v_4247 == nil) goto v_4236;
    else goto v_4235;
v_4236:
    v_4247 = stack[0];
    v_4247 = qcdr(v_4247);
    stack[0] = v_4247;
    goto v_4205;
v_4235:
    goto v_4224;
    v_4247 = nil;
v_4224:
    goto v_4209;
v_4211:
    v_4247 = nil;
    goto v_4209;
    v_4247 = nil;
v_4209:
    return onevalue(v_4247);
}



// Code for talp_ordatp

static LispObject CC_talp_ordatp(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4268, v_4269;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    v_4268 = stack[-1];
    fn = elt(env, 2); // talp_simpat
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    stack[-1] = v_4268;
    v_4268 = stack[0];
    fn = elt(env, 2); // talp_simpat
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    stack[0] = v_4268;
    v_4268 = stack[-1];
    fn = elt(env, 3); // talp_arg2l
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    stack[-2] = v_4268;
    v_4268 = stack[0];
    fn = elt(env, 3); // talp_arg2l
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4229;
v_4225:
    v_4269 = stack[-2];
    goto v_4226;
v_4227:
    goto v_4228;
v_4229:
    goto v_4225;
v_4226:
    goto v_4227;
v_4228:
    if (equal(v_4269, v_4268)) goto v_4224;
    goto v_4237;
v_4233:
    v_4268 = stack[-1];
    fn = elt(env, 3); // talp_arg2l
    stack[-1] = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4234;
v_4235:
    v_4268 = stack[0];
    fn = elt(env, 3); // talp_arg2l
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4236;
v_4237:
    goto v_4233;
v_4234:
    goto v_4235;
v_4236:
    {
        LispObject v_4273 = stack[-1];
        fn = elt(env, 4); // talp_tordp
        return (*qfn2(fn))(fn, v_4273, v_4268);
    }
v_4224:
    v_4268 = stack[-1];
    fn = elt(env, 5); // talp_arg2r
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    stack[-2] = v_4268;
    v_4268 = stack[0];
    fn = elt(env, 5); // talp_arg2r
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4254;
v_4250:
    v_4269 = stack[-2];
    goto v_4251;
v_4252:
    goto v_4253;
v_4254:
    goto v_4250;
v_4251:
    goto v_4252;
v_4253:
    if (equal(v_4269, v_4268)) goto v_4249;
    goto v_4262;
v_4258:
    v_4268 = stack[-1];
    fn = elt(env, 5); // talp_arg2r
    stack[-1] = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4259;
v_4260:
    v_4268 = stack[0];
    fn = elt(env, 5); // talp_arg2r
    v_4268 = (*qfn1(fn))(fn, v_4268);
    env = stack[-3];
    goto v_4261;
v_4262:
    goto v_4258;
v_4259:
    goto v_4260;
v_4261:
    {
        LispObject v_4274 = stack[-1];
        fn = elt(env, 4); // talp_tordp
        return (*qfn2(fn))(fn, v_4274, v_4268);
    }
v_4249:
    v_4268 = elt(env, 1); // true
    return onevalue(v_4268);
}



// Code for searchtm

static LispObject CC_searchtm(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4238, v_4239;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4239 = v_4206;
// end of prologue
    v_4238 = v_4239;
    if (!consp(v_4238)) goto v_4214;
    else goto v_4215;
v_4214:
    v_4238 = lisp_true;
    goto v_4213;
v_4215:
    v_4238 = v_4239;
    v_4238 = qcar(v_4238);
    v_4238 = (consp(v_4238) ? nil : lisp_true);
    goto v_4213;
    v_4238 = nil;
v_4213:
    if (v_4238 == nil) goto v_4211;
    v_4238 = nil;
    goto v_4209;
v_4211:
    goto v_4231;
v_4227:
    v_4238 = v_4239;
    v_4238 = qcar(v_4238);
    stack[0] = qcar(v_4238);
    goto v_4228;
v_4229:
    v_4238 = v_4239;
    v_4238 = qcdr(v_4238);
    fn = elt(env, 1); // searchpl
    v_4238 = (*qfn1(fn))(fn, v_4238);
    goto v_4230;
v_4231:
    goto v_4227;
v_4228:
    goto v_4229;
v_4230:
    {
        LispObject v_4241 = stack[0];
        return cons(v_4241, v_4238);
    }
    v_4238 = nil;
v_4209:
    return onevalue(v_4238);
}



// Code for equal!:

static LispObject CC_equalT(LispObject env,
                         LispObject v_4206, LispObject v_4207)
{
    env = qenv(env);
    LispObject v_4259, v_4260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4207,v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4206,v_4207);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4207;
    stack[-1] = v_4206;
// end of prologue
    v_4259 = stack[-1];
    v_4259 = qcdr(v_4259);
    v_4259 = qcar(v_4259);
    v_4259 = (LispObject)zerop(v_4259);
    v_4259 = v_4259 ? lisp_true : nil;
    env = stack[-3];
    if (v_4259 == nil) goto v_4214;
    else goto v_4215;
v_4214:
    v_4259 = nil;
    goto v_4213;
v_4215:
    v_4259 = stack[0];
    v_4259 = qcdr(v_4259);
    v_4259 = qcar(v_4259);
    v_4259 = (LispObject)zerop(v_4259);
    v_4259 = v_4259 ? lisp_true : nil;
    env = stack[-3];
    goto v_4213;
    v_4259 = nil;
v_4213:
    if (v_4259 == nil) goto v_4211;
    else goto v_4210;
v_4211:
    goto v_4235;
v_4231:
    v_4259 = stack[-1];
    fn = elt(env, 1); // normbf
    v_4259 = (*qfn1(fn))(fn, v_4259);
    env = stack[-3];
    stack[-1] = v_4259;
    v_4259 = qcdr(v_4259);
    stack[-2] = qcdr(v_4259);
    goto v_4232;
v_4233:
    v_4259 = stack[0];
    fn = elt(env, 1); // normbf
    v_4259 = (*qfn1(fn))(fn, v_4259);
    stack[0] = v_4259;
    v_4259 = qcdr(v_4259);
    v_4259 = qcdr(v_4259);
    goto v_4234;
v_4235:
    goto v_4231;
v_4232:
    goto v_4233;
v_4234:
    if (equal(stack[-2], v_4259)) goto v_4229;
    else goto v_4230;
v_4229:
    goto v_4248;
v_4244:
    v_4259 = stack[-1];
    v_4259 = qcdr(v_4259);
    v_4260 = qcar(v_4259);
    goto v_4245;
v_4246:
    v_4259 = stack[0];
    v_4259 = qcdr(v_4259);
    v_4259 = qcar(v_4259);
    goto v_4247;
v_4248:
    goto v_4244;
v_4245:
    goto v_4246;
v_4247:
    v_4259 = (equal(v_4260, v_4259) ? lisp_true : nil);
    goto v_4228;
v_4230:
    v_4259 = nil;
    goto v_4228;
    v_4259 = nil;
v_4228:
v_4210:
    return onevalue(v_4259);
}



// Code for testred

static LispObject CC_testred(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4342, v_4343, v_4344;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4206;
// end of prologue
    goto v_4217;
v_4213:
    goto v_4222;
v_4218:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4219;
v_4220:
    goto v_4229;
v_4225:
    v_4343 = qvalue(elt(env, 2)); // maxvar
    goto v_4226;
v_4227:
    v_4342 = stack[0];
    goto v_4228;
v_4229:
    goto v_4225;
v_4226:
    goto v_4227;
v_4228:
    v_4342 = plus2(v_4343, v_4342);
    env = stack[-2];
    goto v_4221;
v_4222:
    goto v_4218;
v_4219:
    goto v_4220;
v_4221:
    v_4343 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    goto v_4214;
v_4215:
    v_4342 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4216;
v_4217:
    goto v_4213;
v_4214:
    goto v_4215;
v_4216:
    v_4342 = *(LispObject *)((char *)v_4343 + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    if (v_4342 == nil) goto v_4211;
    goto v_4241;
v_4237:
    goto v_4246;
v_4242:
    goto v_4251;
v_4247:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4248;
v_4249:
    goto v_4258;
v_4254:
    v_4343 = qvalue(elt(env, 2)); // maxvar
    goto v_4255;
v_4256:
    v_4342 = stack[0];
    goto v_4257;
v_4258:
    goto v_4254;
v_4255:
    goto v_4256;
v_4257:
    v_4342 = plus2(v_4343, v_4342);
    env = stack[-2];
    goto v_4250;
v_4251:
    goto v_4247;
v_4248:
    goto v_4249;
v_4250:
    v_4343 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    goto v_4243;
v_4244:
    v_4342 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4245;
v_4246:
    goto v_4242;
v_4243:
    goto v_4244;
v_4245:
    v_4342 = *(LispObject *)((char *)v_4343 + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    v_4342 = qcar(v_4342);
    v_4343 = qcar(v_4342);
    goto v_4238;
v_4239:
    v_4342 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_4240;
v_4241:
    goto v_4237;
v_4238:
    goto v_4239;
v_4240:
    v_4342 = (LispObject)lessp2(v_4343, v_4342);
    v_4342 = v_4342 ? lisp_true : nil;
    env = stack[-2];
    if (v_4342 == nil) goto v_4211;
    goto v_4273;
v_4267:
    goto v_4278;
v_4274:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4275;
v_4276:
    goto v_4285;
v_4281:
    v_4343 = qvalue(elt(env, 2)); // maxvar
    goto v_4282;
v_4283:
    v_4342 = stack[0];
    goto v_4284;
v_4285:
    goto v_4281;
v_4282:
    goto v_4283;
v_4284:
    v_4342 = plus2(v_4343, v_4342);
    env = stack[-2];
    goto v_4277;
v_4278:
    goto v_4274;
v_4275:
    goto v_4276;
v_4277:
    v_4344 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    goto v_4268;
v_4269:
    v_4343 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4270;
v_4271:
    v_4342 = nil;
    goto v_4272;
v_4273:
    goto v_4267;
v_4268:
    goto v_4269;
v_4270:
    goto v_4271;
v_4272:
    *(LispObject *)((char *)v_4344 + (CELL-TAG_VECTOR) + (((intptr_t)v_4343-TAG_FIXNUM)/(16/CELL))) = v_4342;
    goto v_4299;
v_4295:
    goto v_4304;
v_4300:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4301;
v_4302:
    goto v_4311;
v_4307:
    v_4343 = qvalue(elt(env, 2)); // maxvar
    goto v_4308;
v_4309:
    v_4342 = stack[0];
    goto v_4310;
v_4311:
    goto v_4307;
v_4308:
    goto v_4309;
v_4310:
    v_4342 = plus2(v_4343, v_4342);
    env = stack[-2];
    goto v_4303;
v_4304:
    goto v_4300;
v_4301:
    goto v_4302;
v_4303:
    v_4343 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    goto v_4296;
v_4297:
    v_4342 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_4298;
v_4299:
    goto v_4295;
v_4296:
    goto v_4297;
v_4298:
    v_4342 = *(LispObject *)((char *)v_4343 + (CELL-TAG_VECTOR) + (((intptr_t)v_4342-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_4342;
v_4294:
    v_4342 = stack[-1];
    if (v_4342 == nil) goto v_4319;
    else goto v_4320;
v_4319:
    v_4342 = nil;
    goto v_4293;
v_4320:
    v_4342 = stack[-1];
    v_4342 = qcar(v_4342);
    stack[0] = v_4342;
    goto v_4331;
v_4327:
    v_4342 = stack[0];
    v_4343 = qcar(v_4342);
    goto v_4328;
v_4329:
    v_4342 = stack[0];
    v_4342 = qcdr(v_4342);
    v_4342 = qcar(v_4342);
    goto v_4330;
v_4331:
    goto v_4327;
v_4328:
    goto v_4329;
v_4330:
    fn = elt(env, 3); // downwght1
    v_4342 = (*qfn2(fn))(fn, v_4343, v_4342);
    env = stack[-2];
    v_4342 = stack[0];
    v_4342 = qcar(v_4342);
    v_4342 = CC_testred(elt(env, 0), v_4342);
    env = stack[-2];
    v_4342 = stack[-1];
    v_4342 = qcdr(v_4342);
    stack[-1] = v_4342;
    goto v_4294;
v_4293:
    goto v_4209;
v_4211:
    v_4342 = nil;
v_4209:
    return onevalue(v_4342);
}



// Code for simpindexvar

static LispObject CC_simpindexvar(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4211 = v_4206;
// end of prologue
    fn = elt(env, 1); // partitindexvar
    v_4211 = (*qfn1(fn))(fn, v_4211);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_4211);
    }
}



// Code for dim!<deg

static LispObject CC_dimRdeg(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4234, v_4235;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_4234 = v_4206;
// end of prologue
    goto v_4216;
v_4212:
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    goto v_4213;
v_4214:
    fn = elt(env, 2); // deg!*farg
    v_4234 = (*qfn1(fn))(fn, v_4234);
    env = stack[-1];
    fn = elt(env, 3); // negf
    v_4234 = (*qfn1(fn))(fn, v_4234);
    env = stack[-1];
    goto v_4215;
v_4216:
    goto v_4212;
v_4213:
    goto v_4214;
v_4215:
    fn = elt(env, 4); // addf
    v_4234 = (*qfn2(fn))(fn, stack[0], v_4234);
    env = stack[-1];
    v_4235 = v_4234;
    v_4234 = v_4235;
    if (is_number(v_4234)) goto v_4225;
    else goto v_4224;
v_4225:
    v_4234 = v_4235;
    v_4234 = Lminusp(nil, v_4234);
    if (v_4234 == nil) goto v_4224;
    v_4234 = lisp_true;
    goto v_4222;
v_4224:
    v_4234 = nil;
    goto v_4222;
    v_4234 = nil;
v_4222:
    return onevalue(v_4234);
}



// Code for opnum!*

static LispObject CC_opnumH(LispObject env,
                         LispObject v_4206)
{
    env = qenv(env);
    LispObject v_4273, v_4274, v_4275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4206);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4206);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_4273 = v_4206;
// end of prologue
    stack[-1] = nil;
    v_4274 = v_4273;
    if (symbolp(v_4274)) goto v_4216;
    goto v_4223;
v_4219:
    stack[0] = v_4273;
    goto v_4220;
v_4221:
    fn = elt(env, 2); // collectindices
    v_4273 = (*qfn1(fn))(fn, v_4273);
    env = stack[-2];
    goto v_4222;
v_4223:
    goto v_4219;
v_4220:
    goto v_4221;
v_4222:
    fn = elt(env, 3); // removeindices
    v_4273 = (*qfn2(fn))(fn, stack[0], v_4273);
    env = stack[-2];
    goto v_4214;
v_4216:
v_4214:
    v_4274 = v_4273;
    if (symbolp(v_4274)) goto v_4229;
    else goto v_4230;
v_4229:
    v_4274 = v_4273;
    goto v_4228;
v_4230:
    v_4274 = v_4273;
    v_4274 = qcar(v_4274);
    v_4273 = qcdr(v_4273);
    stack[-1] = v_4273;
    goto v_4228;
v_4228:
    goto v_4245;
v_4241:
    goto v_4242;
v_4243:
    v_4273 = elt(env, 1); // opnum
    goto v_4244;
v_4245:
    goto v_4241;
v_4242:
    goto v_4243;
v_4244:
    v_4273 = get(v_4274, v_4273);
    v_4275 = v_4273;
    goto v_4256;
v_4252:
    v_4274 = stack[-1];
    goto v_4253;
v_4254:
    v_4273 = v_4275;
    goto v_4255;
v_4256:
    goto v_4252;
v_4253:
    goto v_4254;
v_4255:
    v_4274 = Lassoc(nil, v_4274, v_4273);
    v_4273 = v_4274;
    if (v_4274 == nil) goto v_4251;
    v_4273 = qcdr(v_4273);
    goto v_4212;
v_4251:
    goto v_4268;
v_4264:
    v_4273 = nil;
    goto v_4265;
v_4266:
    v_4274 = v_4275;
    goto v_4267;
v_4268:
    goto v_4264;
v_4265:
    goto v_4266;
v_4267:
    v_4273 = Lassoc(nil, v_4273, v_4274);
    v_4273 = qcdr(v_4273);
    goto v_4212;
    v_4273 = nil;
v_4212:
    return onevalue(v_4273);
}



setup_type const u09_setup[] =
{
    {"talp_candp",              CC_talp_candp,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_deci",               CC_pasf_deci,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_istotal",           CC_ibalp_istotal,TOO_MANY_1,   WRONG_NO_1},
    {"isarb_compl",             CC_isarb_compl, TOO_MANY_1,    WRONG_NO_1},
    {"ps:order",                CC_psTorder,    TOO_MANY_1,    WRONG_NO_1},
    {"symtabget",               TOO_FEW_2,      CC_symtabget,  WRONG_NO_2},
    {"vdpsave",                 CC_vdpsave,     TOO_MANY_1,    WRONG_NO_1},
    {"noncomp2f",               CC_noncomp2f,   TOO_MANY_1,    WRONG_NO_1},
    {"add2inputbuf",            TOO_FEW_2,      CC_add2inputbuf,WRONG_NO_2},
    {"ckpreci#",                CC_ckpreciC,    TOO_MANY_1,    WRONG_NO_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,TOO_MANY_1,   WRONG_NO_1},
    {"mo=deglist",              CC_moMdeglist,  TOO_MANY_1,    WRONG_NO_1},
    {"general-times-term-mod-p",TOO_FEW_2,      CC_generalKtimesKtermKmodKp,WRONG_NO_2},
    {"gionep:",                 CC_gionepT,     TOO_MANY_1,    WRONG_NO_1},
    {"cde_position2",           TOO_FEW_2,      CC_cde_position2,WRONG_NO_2},
    {"prepsq*2",                CC_prepsqH2,    TOO_MANY_1,    WRONG_NO_1},
    {"ordpa",                   TOO_FEW_2,      CC_ordpa,      WRONG_NO_2},
    {"talp_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smwmkatl},
    {"ibalp_litlp",             CC_ibalp_litlp, TOO_MANY_1,    WRONG_NO_1},
    {"multiom",                 CC_multiom,     TOO_MANY_1,    WRONG_NO_1},
    {"rdprep1",                 CC_rdprep1,     TOO_MANY_1,    WRONG_NO_1},
    {"difff",                   TOO_FEW_2,      CC_difff,      WRONG_NO_2},
    {"take-realpart",           CC_takeKrealpart,TOO_MANY_1,   WRONG_NO_1},
    {"token1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_token1},
    {"dp_sum",                  TOO_FEW_2,      CC_dp_sum,     WRONG_NO_2},
    {"pneg",                    CC_pneg,        TOO_MANY_1,    WRONG_NO_1},
    {"kernp",                   CC_kernp,       TOO_MANY_1,    WRONG_NO_1},
    {"conv:bf2i",               CC_convTbf2i,   TOO_MANY_1,    WRONG_NO_1},
    {"carx",                    TOO_FEW_2,      CC_carx,       WRONG_NO_2},
    {"quotdd",                  TOO_FEW_2,      CC_quotdd,     WRONG_NO_2},
    {"comfac",                  CC_comfac,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplat2",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplat2},
    {"cl_susiminlevel",         TOO_FEW_2,      CC_cl_susiminlevel,WRONG_NO_2},
    {"ibalp_vequal",            TOO_FEW_2,      CC_ibalp_vequal,WRONG_NO_2},
    {"quotk",                   TOO_FEW_2,      CC_quotk,      WRONG_NO_2},
    {"ps:last-term",            CC_psTlastKterm,TOO_MANY_1,    WRONG_NO_1},
    {"initbrsea",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_initbrsea},
    {"take-impart",             CC_takeKimpart, TOO_MANY_1,    WRONG_NO_1},
    {"errorset2",               CC_errorset2,   TOO_MANY_1,    WRONG_NO_1},
    {"mv-pow-+",                TOO_FEW_2,      CC_mvKpowKL,   WRONG_NO_2},
    {"*i2gi",                   CC_Hi2gi,       TOO_MANY_1,    WRONG_NO_1},
    {"ptoken",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ptoken},
    {"wuorderp",                TOO_FEW_2,      CC_wuorderp,   WRONG_NO_2},
    {"freevarinexptchk",        CC_freevarinexptchk,TOO_MANY_1,WRONG_NO_1},
    {"talp_ordatp",             TOO_FEW_2,      CC_talp_ordatp,WRONG_NO_2},
    {"searchtm",                CC_searchtm,    TOO_MANY_1,    WRONG_NO_1},
    {"equal:",                  TOO_FEW_2,      CC_equalT,     WRONG_NO_2},
    {"testred",                 CC_testred,     TOO_MANY_1,    WRONG_NO_1},
    {"simpindexvar",            CC_simpindexvar,TOO_MANY_1,    WRONG_NO_1},
    {"dim<deg",                 CC_dimRdeg,     TOO_MANY_1,    WRONG_NO_1},
    {"opnum*",                  CC_opnumH,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u09", (two_args *)"17346 7122378 8357065", 0}
};

// end of generated code
