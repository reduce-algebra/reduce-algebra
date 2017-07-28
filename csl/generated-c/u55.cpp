
// $destdir/u55.c        Machine generated C code

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



// Code for chrstrem

static LispObject CC_chrstrem(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34295, v_34296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_33954;
// end of prologue
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_33966;
    else goto v_33964;
v_33966:
    v_34295 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_34295 == nil) goto v_33968;
    else goto v_33964;
v_33968:
    goto v_33965;
v_33964:
    v_34295 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = elt(env, 3); // "--------------------------------------------------------"
    fn = elt(env, 14); // prin2t!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_33963;
v_33965:
v_33963:
v_33977:
    v_34295 = stack[-3];
    fn = elt(env, 15); // wusort
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    stack[-3] = v_34295;
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_33984;
    else goto v_33982;
v_33984:
    v_34295 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_34295 == nil) goto v_33986;
    else goto v_33982;
v_33986:
    goto v_33983;
v_33982:
    v_34295 = elt(env, 4); // "The new pol-set in ascending order is"
    fn = elt(env, 14); // prin2t!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[-3];
    stack[0] = v_34295;
v_33993:
    v_34295 = stack[0];
    if (v_34295 == nil) goto v_33997;
    else goto v_33998;
v_33997:
    goto v_33992;
v_33998:
    v_34295 = stack[0];
    v_34295 = qcar(v_34295);
    fn = elt(env, 16); // printsf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[0];
    v_34295 = qcdr(v_34295);
    stack[0] = v_34295;
    goto v_33993;
v_33992:
    v_34295 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_33981;
v_33983:
v_33981:
    v_34295 = stack[-3];
    v_34295 = qcar(v_34295);
    fn = elt(env, 17); // wuconstantp
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    if (v_34295 == nil) goto v_34014;
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34021;
    v_34295 = elt(env, 5); // "which is trivially trivial"
    fn = elt(env, 14); // prin2t!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_34019;
v_34021:
v_34019:
    v_34295 = elt(env, 6); // inconsistent
    stack[-2] = v_34295;
    v_34295 = (LispObject)16+TAG_FIXNUM; // 1
    v_34295 = ncons(v_34295);
    env = stack[-5];
    stack[-4] = v_34295;
    goto v_34012;
v_34014:
    v_34295 = nil;
    stack[-2] = v_34295;
    v_34295 = stack[-3];
    fn = elt(env, 18); // pickbasicset
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = Lnreverse(nil, v_34295);
    env = stack[-5];
    stack[-4] = v_34295;
    goto v_34012;
v_34012:
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34039;
    v_34295 = stack[-2];
    if (v_34295 == nil) goto v_34042;
    else goto v_34039;
v_34042:
    v_34295 = elt(env, 7); // "A basic set is"
    fn = elt(env, 14); // prin2t!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[-4];
    v_34295 = Lreverse(nil, v_34295);
    env = stack[-5];
    stack[0] = v_34295;
v_34049:
    v_34295 = stack[0];
    if (v_34295 == nil) goto v_34054;
    else goto v_34055;
v_34054:
    goto v_34048;
v_34055:
    v_34295 = stack[0];
    v_34295 = qcar(v_34295);
    fn = elt(env, 16); // printsf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[0];
    v_34295 = qcdr(v_34295);
    stack[0] = v_34295;
    goto v_34049;
v_34048:
    v_34295 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_34037;
v_34039:
v_34037:
    goto v_34073;
v_34069:
    v_34296 = stack[-3];
    goto v_34070;
v_34071:
    v_34295 = stack[-4];
    goto v_34072;
v_34073:
    goto v_34069;
v_34070:
    goto v_34071;
v_34072:
    fn = elt(env, 19); // setdiff
    v_34295 = (*qfn2(fn))(fn, v_34296, v_34295);
    env = stack[-5];
    stack[-1] = v_34295;
v_34079:
    v_34295 = stack[-1];
    if (v_34295 == nil) goto v_34083;
    else goto v_34084;
v_34083:
    goto v_34078;
v_34084:
    v_34295 = stack[-1];
    v_34295 = qcar(v_34295);
    stack[0] = v_34295;
    goto v_34098;
v_34094:
    v_34296 = stack[-2];
    goto v_34095;
v_34096:
    v_34295 = elt(env, 6); // inconsistent
    goto v_34097;
v_34098:
    goto v_34094;
v_34095:
    goto v_34096;
v_34097:
    if (v_34296 == v_34295) goto v_34093;
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34104;
    v_34295 = elt(env, 8); // "The remainder of "
    fn = elt(env, 20); // prin2!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[0];
    fn = elt(env, 16); // printsf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = elt(env, 9); // "wrt the basic set is "
    fn = elt(env, 20); // prin2!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_34102;
v_34104:
v_34102:
    goto v_34117;
v_34113:
    v_34296 = stack[0];
    goto v_34114;
v_34115:
    v_34295 = stack[-4];
    goto v_34116;
v_34117:
    goto v_34113;
v_34114:
    goto v_34115;
v_34116:
    fn = elt(env, 21); // findremainder
    v_34295 = (*qfn2(fn))(fn, v_34296, v_34295);
    env = stack[-5];
    stack[0] = v_34295;
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34123;
    v_34295 = stack[0];
    fn = elt(env, 16); // printsf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_34121;
v_34123:
v_34121:
    v_34295 = stack[0];
    if (v_34295 == nil) goto v_34131;
    v_34295 = stack[0];
    fn = elt(env, 17); // wuconstantp
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    if (v_34295 == nil) goto v_34136;
    v_34295 = elt(env, 6); // inconsistent
    stack[-2] = v_34295;
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34143;
    v_34295 = elt(env, 10); // "which is a non-zero constant, and so"
    fn = elt(env, 22); // prin2t
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = elt(env, 11); // "the equations are inconsistent."
    fn = elt(env, 22); // prin2t
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    goto v_34141;
v_34143:
v_34141:
    goto v_34134;
v_34136:
    goto v_34156;
v_34152:
    v_34295 = stack[0];
    fn = elt(env, 23); // absf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34296 = ncons(v_34295);
    env = stack[-5];
    goto v_34153;
v_34154:
    v_34295 = stack[-2];
    goto v_34155;
v_34156:
    goto v_34152;
v_34153:
    goto v_34154;
v_34155:
    fn = elt(env, 24); // union
    v_34295 = (*qfn2(fn))(fn, v_34296, v_34295);
    env = stack[-5];
    stack[-2] = v_34295;
    goto v_34134;
v_34134:
    goto v_34129;
v_34131:
v_34129:
    goto v_34091;
v_34093:
v_34091:
    v_34295 = stack[-1];
    v_34295 = qcdr(v_34295);
    stack[-1] = v_34295;
    goto v_34079;
v_34078:
    v_34295 = stack[-2];
    if (v_34295 == nil) goto v_34167;
    goto v_34175;
v_34171:
    v_34296 = stack[-2];
    goto v_34172;
v_34173:
    v_34295 = elt(env, 6); // inconsistent
    goto v_34174;
v_34175:
    goto v_34171;
v_34172:
    goto v_34173;
v_34174:
    if (v_34296 == v_34295) goto v_34167;
    goto v_34183;
v_34179:
    v_34296 = stack[-3];
    goto v_34180;
v_34181:
    v_34295 = stack[-2];
    goto v_34182;
v_34183:
    goto v_34179;
v_34180:
    goto v_34181;
v_34182:
    v_34295 = Lappend(nil, v_34296, v_34295);
    env = stack[-5];
    stack[-3] = v_34295;
    goto v_34165;
v_34167:
v_34165:
    v_34295 = stack[-2];
    if (v_34295 == nil) goto v_34192;
    else goto v_34193;
v_34192:
    v_34295 = lisp_true;
    goto v_34191;
v_34193:
    goto v_34202;
v_34198:
    v_34296 = stack[-2];
    goto v_34199;
v_34200:
    v_34295 = elt(env, 6); // inconsistent
    goto v_34201;
v_34202:
    goto v_34198;
v_34199:
    goto v_34200;
v_34201:
    v_34295 = (v_34296 == v_34295 ? lisp_true : nil);
    goto v_34191;
    v_34295 = nil;
v_34191:
    if (v_34295 == nil) goto v_34188;
    else goto v_34189;
v_34188:
    goto v_33977;
v_34189:
    goto v_34214;
v_34210:
    v_34296 = stack[-2];
    goto v_34211;
v_34212:
    v_34295 = elt(env, 6); // inconsistent
    goto v_34213;
v_34214:
    goto v_34210;
v_34211:
    goto v_34212;
v_34213:
    if (v_34296 == v_34295) goto v_34208;
    else goto v_34209;
v_34208:
    v_34295 = (LispObject)16+TAG_FIXNUM; // 1
    v_34295 = ncons(v_34295);
    env = stack[-5];
    stack[-4] = v_34295;
    goto v_34207;
v_34209:
v_34207:
    v_34295 = qvalue(elt(env, 1)); // !*trwu
    if (v_34295 == nil) goto v_34223;
    else goto v_34221;
v_34223:
    v_34295 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_34295 == nil) goto v_34225;
    else goto v_34221;
v_34225:
    goto v_34222;
v_34221:
    v_34295 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = elt(env, 12); // "The final characteristic set is:"
    fn = elt(env, 14); // prin2t!*
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[-4];
    v_34295 = Lreverse(nil, v_34295);
    env = stack[-5];
    stack[0] = v_34295;
v_34236:
    v_34295 = stack[0];
    if (v_34295 == nil) goto v_34241;
    else goto v_34242;
v_34241:
    goto v_34235;
v_34242:
    v_34295 = stack[0];
    v_34295 = qcar(v_34295);
    fn = elt(env, 16); // printsf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = stack[0];
    v_34295 = qcdr(v_34295);
    stack[0] = v_34295;
    goto v_34236;
v_34235:
    goto v_34220;
v_34222:
v_34220:
    v_34295 = stack[-4];
    stack[-3] = v_34295;
    v_34295 = stack[-3];
    if (v_34295 == nil) goto v_34262;
    else goto v_34263;
v_34262:
    v_34295 = nil;
    goto v_34257;
v_34263:
    v_34295 = stack[-3];
    v_34295 = qcar(v_34295);
    fn = elt(env, 23); // absf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = ncons(v_34295);
    env = stack[-5];
    stack[-1] = v_34295;
    stack[-2] = v_34295;
v_34258:
    v_34295 = stack[-3];
    v_34295 = qcdr(v_34295);
    stack[-3] = v_34295;
    v_34295 = stack[-3];
    if (v_34295 == nil) goto v_34276;
    else goto v_34277;
v_34276:
    v_34295 = stack[-2];
    goto v_34257;
v_34277:
    goto v_34285;
v_34281:
    stack[0] = stack[-1];
    goto v_34282;
v_34283:
    v_34295 = stack[-3];
    v_34295 = qcar(v_34295);
    fn = elt(env, 23); // absf
    v_34295 = (*qfn1(fn))(fn, v_34295);
    env = stack[-5];
    v_34295 = ncons(v_34295);
    env = stack[-5];
    goto v_34284;
v_34285:
    goto v_34281;
v_34282:
    goto v_34283;
v_34284:
    v_34295 = Lrplacd(nil, stack[0], v_34295);
    env = stack[-5];
    v_34295 = stack[-1];
    v_34295 = qcdr(v_34295);
    stack[-1] = v_34295;
    goto v_34258;
v_34257:
        return Lnreverse(nil, v_34295);
    return onevalue(v_34295);
}



// Code for quotfexf!*1

static LispObject CC_quotfexfH1(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34034, v_34035, v_34036;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    v_34034 = stack[-1];
    if (v_34034 == nil) goto v_33959;
    else goto v_33960;
v_33959:
    v_34034 = nil;
    goto v_33958;
v_33960:
    goto v_33970;
v_33966:
    v_34035 = stack[-1];
    goto v_33967;
v_33968:
    v_34034 = stack[0];
    goto v_33969;
v_33970:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    fn = elt(env, 4); // quotf
    v_34034 = (*qfn2(fn))(fn, v_34035, v_34034);
    env = stack[-2];
    v_34035 = v_34034;
    v_34034 = v_34035;
    if (v_34034 == nil) goto v_33977;
    v_34034 = v_34035;
    goto v_33975;
v_33977:
    goto v_33988;
v_33984:
    v_34035 = stack[-1];
    goto v_33985;
v_33986:
    v_34034 = stack[0];
    goto v_33987;
v_33988:
    goto v_33984;
v_33985:
    goto v_33986;
v_33987:
    v_34034 = cons(v_34035, v_34034);
    env = stack[-2];
    fn = elt(env, 5); // rationalizesq
    v_34034 = (*qfn1(fn))(fn, v_34034);
    env = stack[-2];
    v_34036 = v_34034;
    goto v_34000;
v_33996:
    v_34034 = v_34036;
    v_34035 = qcdr(v_34034);
    goto v_33997;
v_33998:
    v_34034 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33999;
v_34000:
    goto v_33996;
v_33997:
    goto v_33998;
v_33999:
    if (v_34035 == v_34034) goto v_33994;
    else goto v_33995;
v_33994:
    v_34034 = v_34036;
    v_34034 = qcar(v_34034);
    goto v_33993;
v_33995:
    goto v_34012;
v_34008:
    v_34034 = lisp_true;
// Binding !*rationalize
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 1, 0);
    qvalue(elt(env, 1)) = v_34034; // !*rationalize
    v_34034 = v_34036;
    fn = elt(env, 5); // rationalizesq
    v_34034 = (*qfn1(fn))(fn, v_34034);
    env = stack[-2];
    ;}  // end of a binding scope
    v_34036 = v_34034;
    v_34035 = qcdr(v_34034);
    goto v_34009;
v_34010:
    v_34034 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34011;
v_34012:
    goto v_34008;
v_34009:
    goto v_34010;
v_34011:
    if (v_34035 == v_34034) goto v_34006;
    else goto v_34007;
v_34006:
    v_34034 = v_34036;
    v_34034 = qcar(v_34034);
    goto v_33993;
v_34007:
    goto v_34030;
v_34024:
    v_34036 = elt(env, 2); // matrix
    goto v_34025;
v_34026:
    v_34035 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_34027;
v_34028:
    v_34034 = elt(env, 3); // "Catastrophic division failure"
    goto v_34029;
v_34030:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    goto v_34028;
v_34029:
    {
        fn = elt(env, 6); // rerror
        return (*qfnn(fn))(fn, 3, v_34036, v_34035, v_34034);
    }
    v_34034 = nil;
v_33993:
    goto v_33975;
    v_34034 = nil;
v_33975:
    goto v_33958;
    v_34034 = nil;
v_33958:
    return onevalue(v_34034);
}



// Code for vdelete

static LispObject CC_vdelete(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34002, v_34003, v_34004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    v_34004 = nil;
v_33960:
    v_34002 = stack[0];
    if (v_34002 == nil) goto v_33963;
    else goto v_33964;
v_33963:
    v_34002 = v_34004;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_34002);
    }
v_33964:
    goto v_33974;
v_33970:
    v_34002 = stack[-1];
    v_34003 = qcar(v_34002);
    goto v_33971;
v_33972:
    v_34002 = stack[0];
    v_34002 = qcar(v_34002);
    v_34002 = qcar(v_34002);
    goto v_33973;
v_33974:
    goto v_33970;
v_33971:
    goto v_33972;
v_33973:
    if (equal(v_34003, v_34002)) goto v_33968;
    else goto v_33969;
v_33968:
    goto v_33985;
v_33981:
    v_34003 = v_34004;
    goto v_33982;
v_33983:
    v_34002 = stack[0];
    v_34002 = qcdr(v_34002);
    goto v_33984;
v_33985:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34003, v_34002);
    }
v_33969:
    goto v_33996;
v_33992:
    v_34002 = stack[0];
    v_34002 = qcar(v_34002);
    goto v_33993;
v_33994:
    v_34003 = v_34004;
    goto v_33995;
v_33996:
    goto v_33992;
v_33993:
    goto v_33994;
v_33995:
    v_34002 = cons(v_34002, v_34003);
    env = stack[-2];
    v_34004 = v_34002;
    v_34002 = stack[0];
    v_34002 = qcdr(v_34002);
    stack[0] = v_34002;
    goto v_33960;
    v_34002 = nil;
    return onevalue(v_34002);
}



// Code for search_att

static LispObject CC_search_att(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34187, v_34188;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33955;
    stack[-2] = v_33954;
// end of prologue
    v_34187 = nil;
    stack[0] = v_34187;
    v_34187 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_34187;
    goto v_33970;
v_33966:
    v_34188 = stack[-2];
    goto v_33967;
v_33968:
    v_34187 = stack[-1];
    goto v_33969;
v_33970:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    fn = elt(env, 6); // find2
    v_34187 = (*qfn2(fn))(fn, v_34188, v_34187);
    env = stack[-4];
    stack[-2] = v_34187;
    goto v_33981;
v_33977:
    v_34188 = stack[-2];
    goto v_33978;
v_33979:
    v_34187 = elt(env, 1); // (stop)
    goto v_33980;
v_33981:
    goto v_33977;
v_33978:
    goto v_33979;
v_33980:
    if (equal(v_34188, v_34187)) goto v_33976;
v_33986:
    goto v_33995;
v_33991:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_33992;
v_33993:
    v_34187 = elt(env, 2); // ! 
    goto v_33994;
v_33995:
    goto v_33991;
v_33992:
    goto v_33993;
v_33994:
    if (v_34188 == v_34187) goto v_33990;
    goto v_33985;
v_33990:
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
    goto v_33986;
v_33985:
    goto v_34010;
v_34006:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34007;
v_34008:
    v_34187 = elt(env, 3); // !=
    goto v_34009;
v_34010:
    goto v_34006;
v_34007:
    goto v_34008;
v_34009:
    if (v_34188 == v_34187) goto v_34004;
    else goto v_34005;
v_34004:
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
v_34018:
    goto v_34027;
v_34023:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34024;
v_34025:
    v_34187 = elt(env, 2); // ! 
    goto v_34026;
v_34027:
    goto v_34023;
v_34024:
    goto v_34025;
v_34026:
    if (v_34188 == v_34187) goto v_34022;
    goto v_34017;
v_34022:
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
    goto v_34018;
v_34017:
    goto v_34042;
v_34038:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34039;
v_34040:
    v_34187 = elt(env, 4); // !"
    goto v_34041;
v_34042:
    goto v_34038;
v_34039:
    goto v_34040;
v_34041:
    if (v_34188 == v_34187) goto v_34036;
    else goto v_34037;
v_34036:
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
v_34050:
    goto v_34059;
v_34055:
    v_34188 = stack[-3];
    goto v_34056;
v_34057:
    v_34187 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34058;
v_34059:
    goto v_34055;
v_34056:
    goto v_34057;
v_34058:
    if (v_34188 == v_34187) goto v_34054;
    goto v_34049;
v_34054:
    goto v_34068;
v_34064:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34065;
v_34066:
    v_34187 = stack[0];
    goto v_34067;
v_34068:
    goto v_34064;
v_34065:
    goto v_34066;
v_34067:
    v_34187 = cons(v_34188, v_34187);
    env = stack[-4];
    stack[0] = v_34187;
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
    goto v_34086;
v_34082:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34083;
v_34084:
    v_34187 = elt(env, 2); // ! 
    goto v_34085;
v_34086:
    goto v_34082;
v_34083:
    goto v_34084;
v_34085:
    if (v_34188 == v_34187) goto v_34080;
    else goto v_34081;
v_34080:
    v_34187 = lisp_true;
    goto v_34079;
v_34081:
    goto v_34097;
v_34093:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34094;
v_34095:
    v_34187 = elt(env, 5); // !$
    goto v_34096;
v_34097:
    goto v_34093;
v_34094:
    goto v_34095;
v_34096:
    v_34187 = (v_34188 == v_34187 ? lisp_true : nil);
    goto v_34079;
    v_34187 = nil;
v_34079:
    if (v_34187 == nil) goto v_34077;
    v_34187 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_34187;
    goto v_34075;
v_34077:
v_34075:
    goto v_34050;
v_34049:
    goto v_34035;
v_34037:
v_34107:
    goto v_34116;
v_34112:
    v_34188 = stack[-3];
    goto v_34113;
v_34114:
    v_34187 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34115;
v_34116:
    goto v_34112;
v_34113:
    goto v_34114;
v_34115:
    if (v_34188 == v_34187) goto v_34111;
    goto v_34106;
v_34111:
    goto v_34125;
v_34121:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34122;
v_34123:
    v_34187 = stack[0];
    goto v_34124;
v_34125:
    goto v_34121;
v_34122:
    goto v_34123;
v_34124:
    v_34187 = cons(v_34188, v_34187);
    env = stack[-4];
    stack[0] = v_34187;
    v_34187 = stack[-2];
    v_34187 = qcdr(v_34187);
    stack[-2] = v_34187;
    goto v_34143;
v_34139:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34140;
v_34141:
    v_34187 = elt(env, 2); // ! 
    goto v_34142;
v_34143:
    goto v_34139;
v_34140:
    goto v_34141;
v_34142:
    if (v_34188 == v_34187) goto v_34137;
    else goto v_34138;
v_34137:
    v_34187 = lisp_true;
    goto v_34136;
v_34138:
    goto v_34154;
v_34150:
    v_34187 = stack[-2];
    v_34188 = qcar(v_34187);
    goto v_34151;
v_34152:
    v_34187 = elt(env, 5); // !$
    goto v_34153;
v_34154:
    goto v_34150;
v_34151:
    goto v_34152;
v_34153:
    v_34187 = (v_34188 == v_34187 ? lisp_true : nil);
    goto v_34136;
    v_34187 = nil;
v_34136:
    if (v_34187 == nil) goto v_34134;
    v_34187 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_34187;
    goto v_34132;
v_34134:
v_34132:
    goto v_34107;
v_34106:
    goto v_34035;
v_34035:
    goto v_34003;
v_34005:
    goto v_34167;
v_34163:
    v_34187 = stack[-1];
    v_34188 = Lcompress(nil, v_34187);
    env = stack[-4];
    goto v_34164;
v_34165:
    v_34187 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34166;
v_34167:
    goto v_34163;
v_34164:
    goto v_34165;
v_34166:
    fn = elt(env, 7); // errorml
    v_34187 = (*qfn2(fn))(fn, v_34188, v_34187);
    env = stack[-4];
    goto v_34003;
v_34003:
    goto v_34179;
v_34175:
    v_34187 = stack[0];
    v_34187 = qcar(v_34187);
    goto v_34176;
v_34177:
    v_34188 = elt(env, 4); // !"
    goto v_34178;
v_34179:
    goto v_34175;
v_34176:
    goto v_34177;
v_34178:
    if (v_34187 == v_34188) goto v_34173;
    else goto v_34174;
v_34173:
    v_34187 = stack[0];
    v_34187 = qcdr(v_34187);
    stack[0] = v_34187;
    goto v_34172;
v_34174:
v_34172:
    v_34187 = stack[0];
        return Lreverse(nil, v_34187);
v_33976:
    v_34187 = nil;
    return onevalue(v_34187);
}



// Code for setprev

static LispObject CC_setprev(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34062, v_34063;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-3] = v_33954;
// end of prologue
v_33959:
    goto v_33968;
v_33964:
    goto v_33973;
v_33969:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_33970;
v_33971:
    goto v_33980;
v_33976:
    v_34063 = qvalue(elt(env, 2)); // maxvar
    goto v_33977;
v_33978:
    v_34062 = stack[-3];
    goto v_33979;
v_33980:
    goto v_33976;
v_33977:
    goto v_33978;
v_33979:
    v_34062 = plus2(v_34063, v_34062);
    env = stack[-5];
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    v_34063 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    goto v_33965;
v_33966:
    v_34062 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33967;
v_33968:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    v_34062 = *(LispObject *)((char *)v_34063 + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    if (is_number(v_34062)) goto v_33962;
    else goto v_33963;
v_33962:
    goto v_33990;
v_33986:
    goto v_33995;
v_33991:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_33992;
v_33993:
    goto v_34002;
v_33998:
    v_34063 = qvalue(elt(env, 2)); // maxvar
    goto v_33999;
v_34000:
    v_34062 = stack[-3];
    goto v_34001;
v_34002:
    goto v_33998;
v_33999:
    goto v_34000;
v_34001:
    v_34062 = plus2(v_34063, v_34062);
    env = stack[-5];
    goto v_33994;
v_33995:
    goto v_33991;
v_33992:
    goto v_33993;
v_33994:
    v_34063 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    goto v_33987;
v_33988:
    v_34062 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33989;
v_33990:
    goto v_33986;
v_33987:
    goto v_33988;
v_33989:
    v_34062 = *(LispObject *)((char *)v_34063 + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_34062;
    goto v_33959;
v_33963:
    goto v_34016;
v_34010:
    goto v_34021;
v_34017:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_34018;
v_34019:
    goto v_34028;
v_34024:
    v_34063 = qvalue(elt(env, 2)); // maxvar
    goto v_34025;
v_34026:
    v_34062 = stack[-3];
    goto v_34027;
v_34028:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    v_34062 = plus2(v_34063, v_34062);
    env = stack[-5];
    goto v_34020;
v_34021:
    goto v_34017;
v_34018:
    goto v_34019;
v_34020:
    stack[-4] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    goto v_34011;
v_34012:
    stack[-2] = (LispObject)128+TAG_FIXNUM; // 8
    goto v_34013;
v_34014:
    goto v_34038;
v_34034:
    stack[-1] = stack[0];
    goto v_34035;
v_34036:
    goto v_34044;
v_34040:
    goto v_34049;
v_34045:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_34046;
v_34047:
    goto v_34056;
v_34052:
    v_34063 = qvalue(elt(env, 2)); // maxvar
    goto v_34053;
v_34054:
    v_34062 = stack[-3];
    goto v_34055;
v_34056:
    goto v_34052;
v_34053:
    goto v_34054;
v_34055:
    v_34062 = plus2(v_34063, v_34062);
    env = stack[-5];
    goto v_34048;
v_34049:
    goto v_34045;
v_34046:
    goto v_34047;
v_34048:
    v_34063 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    goto v_34041;
v_34042:
    v_34062 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_34043;
v_34044:
    goto v_34040;
v_34041:
    goto v_34042;
v_34043:
    v_34062 = *(LispObject *)((char *)v_34063 + (CELL-TAG_VECTOR) + (((intptr_t)v_34062-TAG_FIXNUM)/(16/CELL)));
    goto v_34037;
v_34038:
    goto v_34034;
v_34035:
    goto v_34036;
v_34037:
    v_34062 = cons(stack[-1], v_34062);
    goto v_34015;
v_34016:
    goto v_34010;
v_34011:
    goto v_34012;
v_34013:
    goto v_34014;
v_34015:
    *(LispObject *)((char *)stack[-4] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_34062;
    goto v_33958;
    v_34062 = nil;
v_33958:
    return onevalue(v_34062);
}



// Code for poly!-remainder

static LispObject CC_polyKremainder(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33967, v_33968, v_33969;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33967 = v_33954;
// end of prologue
    goto v_33963;
v_33957:
    v_33969 = v_33967;
    goto v_33958;
v_33959:
    v_33968 = elt(env, 1); // remainder
    goto v_33960;
v_33961:
    v_33967 = nil;
    goto v_33962;
v_33963:
    goto v_33957;
v_33958:
    goto v_33959;
v_33960:
    goto v_33961;
v_33962:
    {
        fn = elt(env, 2); // poly!-divide!*
        return (*qfnn(fn))(fn, 3, v_33969, v_33968, v_33967);
    }
}



// Code for mkuniquewedge

static LispObject CC_mkuniquewedge(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34008, v_34009;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    stack[-1] = nil;
v_33960:
    v_34008 = stack[0];
    if (v_34008 == nil) goto v_33965;
    else goto v_33966;
v_33965:
    goto v_33961;
v_33966:
    goto v_33973;
v_33969:
    goto v_33979;
v_33975:
    v_34008 = stack[0];
    v_34008 = qcar(v_34008);
    v_34008 = qcar(v_34008);
    fn = elt(env, 1); // mkuniquewedge1
    v_34009 = (*qfn1(fn))(fn, v_34008);
    env = stack[-2];
    goto v_33976;
v_33977:
    v_34008 = stack[0];
    v_34008 = qcar(v_34008);
    v_34008 = qcdr(v_34008);
    goto v_33978;
v_33979:
    goto v_33975;
v_33976:
    goto v_33977;
v_33978:
    fn = elt(env, 2); // multpfsq
    v_34009 = (*qfn2(fn))(fn, v_34009, v_34008);
    env = stack[-2];
    goto v_33970;
v_33971:
    v_34008 = stack[-1];
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    v_34008 = cons(v_34009, v_34008);
    env = stack[-2];
    stack[-1] = v_34008;
    v_34008 = stack[0];
    v_34008 = qcdr(v_34008);
    stack[0] = v_34008;
    goto v_33960;
v_33961:
    v_34008 = nil;
    v_34009 = v_34008;
v_33962:
    v_34008 = stack[-1];
    if (v_34008 == nil) goto v_33993;
    else goto v_33994;
v_33993:
    v_34008 = v_34009;
    goto v_33959;
v_33994:
    goto v_34002;
v_33998:
    v_34008 = stack[-1];
    v_34008 = qcar(v_34008);
    goto v_33999;
v_34000:
    goto v_34001;
v_34002:
    goto v_33998;
v_33999:
    goto v_34000;
v_34001:
    fn = elt(env, 3); // addpf
    v_34008 = (*qfn2(fn))(fn, v_34008, v_34009);
    env = stack[-2];
    v_34009 = v_34008;
    v_34008 = stack[-1];
    v_34008 = qcdr(v_34008);
    stack[-1] = v_34008;
    goto v_33962;
v_33959:
    return onevalue(v_34008);
}



// Code for new_provev

static LispObject CC_new_provev(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34000, v_34001, v_34002, v_34003;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34001 = v_33955;
    v_34002 = v_33954;
// end of prologue
    goto v_33965;
v_33961:
    v_34003 = v_34002;
    goto v_33962;
v_33963:
    v_34000 = v_34001;
    goto v_33964;
v_33965:
    goto v_33961;
v_33962:
    goto v_33963;
v_33964:
    v_34000 = Lmember(nil, v_34003, v_34000);
    if (v_34000 == nil) goto v_33959;
    else goto v_33960;
v_33959:
    v_34000 = nil;
    goto v_33958;
v_33960:
    goto v_33977;
v_33973:
    v_34000 = v_34002;
    v_34000 = qcdr(v_34000);
    v_34000 = qcar(v_34000);
    v_34003 = qcar(v_34000);
    goto v_33974;
v_33975:
    v_34000 = v_34001;
    goto v_33976;
v_33977:
    goto v_33973;
v_33974:
    goto v_33975;
v_33976:
    v_34000 = Lassoc(nil, v_34003, v_34000);
    if (v_34000 == nil) goto v_33971;
    goto v_33989;
v_33985:
    v_34000 = v_34002;
    v_34000 = qcdr(v_34000);
    v_34000 = qcar(v_34000);
    v_34002 = qcdr(v_34000);
    goto v_33986;
v_33987:
    v_34000 = v_34001;
    goto v_33988;
v_33989:
    goto v_33985;
v_33986:
    goto v_33987;
v_33988:
    v_34000 = Lassoc(nil, v_34002, v_34000);
    if (v_34000 == nil) goto v_33971;
    v_34000 = nil;
    goto v_33958;
v_33971:
    v_34000 = v_34001;
    goto v_33958;
    v_34000 = nil;
v_33958:
    return onevalue(v_34000);
}



// Code for prepsqyy

static LispObject CC_prepsqyy(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33975, v_33976, v_33977;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33977 = v_33954;
// end of prologue
    goto v_33965;
v_33961:
    v_33976 = v_33977;
    goto v_33962;
v_33963:
    v_33975 = elt(env, 1); // !*sq
    goto v_33964;
v_33965:
    goto v_33961;
v_33962:
    goto v_33963;
v_33964:
    if (!consp(v_33976)) goto v_33959;
    v_33976 = qcar(v_33976);
    if (v_33976 == v_33975) goto v_33958;
    else goto v_33959;
v_33958:
    v_33975 = v_33977;
    v_33975 = qcdr(v_33975);
    v_33975 = qcar(v_33975);
    {
        fn = elt(env, 2); // prepsqxx
        return (*qfn1(fn))(fn, v_33975);
    }
v_33959:
    v_33975 = v_33977;
    goto v_33957;
    v_33975 = nil;
v_33957:
    return onevalue(v_33975);
}



// Code for no_of_tm_sf

static LispObject CC_no_of_tm_sf(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33993;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    v_33993 = stack[0];
    if (v_33993 == nil) goto v_33958;
    else goto v_33959;
v_33958:
    v_33993 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33957;
v_33959:
    v_33993 = stack[0];
    v_33993 = Lconsp(nil, v_33993);
    env = stack[-2];
    if (v_33993 == nil) goto v_33966;
    else goto v_33967;
v_33966:
    v_33993 = lisp_true;
    goto v_33965;
v_33967:
    v_33993 = stack[0];
    v_33993 = qcar(v_33993);
    v_33993 = Lconsp(nil, v_33993);
    env = stack[-2];
    v_33993 = (v_33993 == nil ? lisp_true : nil);
    goto v_33965;
    v_33993 = nil;
v_33965:
    if (v_33993 == nil) goto v_33963;
    v_33993 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33957;
v_33963:
    goto v_33985;
v_33981:
    v_33993 = stack[0];
    v_33993 = qcar(v_33993);
    v_33993 = qcdr(v_33993);
    stack[-1] = CC_no_of_tm_sf(elt(env, 0), v_33993);
    env = stack[-2];
    goto v_33982;
v_33983:
    v_33993 = stack[0];
    v_33993 = qcdr(v_33993);
    v_33993 = CC_no_of_tm_sf(elt(env, 0), v_33993);
    goto v_33984;
v_33985:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    {
        LispObject v_33996 = stack[-1];
        return plus2(v_33996, v_33993);
    }
    v_33993 = nil;
v_33957:
    return onevalue(v_33993);
}



// Code for cde_mkset

static LispObject CC_cde_mkset(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33998, v_33999, v_34000;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    v_34000 = nil;
v_33959:
    v_33998 = stack[0];
    if (v_33998 == nil) goto v_33963;
    goto v_33973;
v_33969:
    v_33998 = stack[0];
    v_33999 = qcar(v_33998);
    goto v_33970;
v_33971:
    v_33998 = stack[0];
    v_33998 = qcdr(v_33998);
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    v_33998 = Lmember(nil, v_33999, v_33998);
    if (v_33998 == nil) goto v_33968;
    v_33998 = stack[0];
    v_33998 = qcdr(v_33998);
    stack[0] = v_33998;
    goto v_33959;
v_33968:
    goto v_33988;
v_33984:
    v_33998 = stack[0];
    v_33998 = qcar(v_33998);
    goto v_33985;
v_33986:
    v_33999 = v_34000;
    goto v_33987;
v_33988:
    goto v_33984;
v_33985:
    goto v_33986;
v_33987:
    v_33998 = cons(v_33998, v_33999);
    env = stack[-1];
    v_34000 = v_33998;
    v_33998 = stack[0];
    v_33998 = qcdr(v_33998);
    stack[0] = v_33998;
    goto v_33959;
    goto v_33961;
v_33963:
    v_33998 = v_34000;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_33998);
    }
v_33961:
    v_33998 = nil;
    return onevalue(v_33998);
}



// Code for sfto_b!:cquot

static LispObject CC_sfto_bTcquot(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33994, v_33995;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33955;
    stack[-2] = v_33954;
// end of prologue
    stack[-3] = nil;
v_33960:
    v_33994 = stack[-2];
    if (v_33994 == nil) goto v_33963;
    else goto v_33964;
v_33963:
    v_33994 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_33994);
    }
v_33964:
    goto v_33977;
v_33971:
    v_33994 = stack[-2];
    v_33994 = qcar(v_33994);
    stack[0] = qcar(v_33994);
    goto v_33972;
v_33973:
    goto v_33986;
v_33982:
    v_33994 = stack[-2];
    v_33994 = qcar(v_33994);
    v_33995 = qcdr(v_33994);
    goto v_33983;
v_33984:
    v_33994 = stack[-1];
    goto v_33985;
v_33986:
    goto v_33982;
v_33983:
    goto v_33984;
v_33985:
    fn = elt(env, 2); // quotf1
    v_33995 = (*qfn2(fn))(fn, v_33995, v_33994);
    env = stack[-4];
    goto v_33974;
v_33975:
    v_33994 = stack[-3];
    goto v_33976;
v_33977:
    goto v_33971;
v_33972:
    goto v_33973;
v_33974:
    goto v_33975;
v_33976:
    v_33994 = acons(stack[0], v_33995, v_33994);
    env = stack[-4];
    stack[-3] = v_33994;
    v_33994 = stack[-2];
    v_33994 = qcdr(v_33994);
    stack[-2] = v_33994;
    goto v_33960;
    v_33994 = nil;
    return onevalue(v_33994);
}



// Code for getsetvarlis

static LispObject CC_getsetvarlis(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34065, v_34066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    stack[-1] = nil;
v_33959:
    v_34065 = stack[0];
    if (v_34065 == nil) goto v_33962;
    else goto v_33963;
v_33962:
    v_34065 = stack[-1];
    {
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(fn, v_34065);
    }
v_33963:
    v_34065 = stack[0];
    if (!consp(v_34065)) goto v_33967;
    else goto v_33968;
v_33967:
    goto v_33975;
v_33971:
    goto v_33972;
v_33973:
    goto v_33983;
v_33979:
    v_34066 = elt(env, 1); // "getsetvarlis"
    goto v_33980;
v_33981:
    v_34065 = stack[0];
    goto v_33982;
v_33983:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    v_34065 = list2(v_34066, v_34065);
    env = stack[-2];
    fn = elt(env, 5); // errach
    v_34065 = (*qfn1(fn))(fn, v_34065);
    env = stack[-2];
    goto v_33974;
v_33975:
    goto v_33971;
v_33972:
    goto v_33973;
v_33974:
    {
        LispObject v_34069 = stack[-1];
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(fn, v_34069, v_34065);
    }
v_33968:
    v_34065 = stack[0];
    v_34065 = qcar(v_34065);
    if (!consp(v_34065)) goto v_33986;
    else goto v_33987;
v_33986:
    goto v_33995;
v_33991:
    v_34065 = stack[0];
    v_34066 = qcar(v_34065);
    goto v_33992;
v_33993:
    v_34065 = stack[-1];
    goto v_33994;
v_33995:
    goto v_33991;
v_33992:
    goto v_33993;
v_33994:
    v_34065 = cons(v_34066, v_34065);
    env = stack[-2];
    stack[-1] = v_34065;
    v_34065 = stack[0];
    v_34065 = qcdr(v_34065);
    stack[0] = v_34065;
    goto v_33959;
v_33987:
    goto v_34007;
v_34003:
    v_34065 = stack[0];
    v_34065 = qcar(v_34065);
    v_34066 = qcar(v_34065);
    goto v_34004;
v_34005:
    v_34065 = elt(env, 2); // (setel setk)
    goto v_34006;
v_34007:
    goto v_34003;
v_34004:
    goto v_34005;
v_34006:
    v_34065 = Lmemq(nil, v_34066, v_34065);
    if (v_34065 == nil) goto v_34002;
    goto v_34018;
v_34014:
    v_34065 = stack[0];
    v_34065 = qcar(v_34065);
    v_34065 = qcdr(v_34065);
    v_34065 = qcar(v_34065);
    v_34066 = CC_getsetvarlis(elt(env, 0), v_34065);
    env = stack[-2];
    goto v_34015;
v_34016:
    v_34065 = stack[-1];
    goto v_34017;
v_34018:
    goto v_34014;
v_34015:
    goto v_34016;
v_34017:
    v_34065 = cons(v_34066, v_34065);
    env = stack[-2];
    stack[-1] = v_34065;
    v_34065 = stack[0];
    v_34065 = qcdr(v_34065);
    stack[0] = v_34065;
    goto v_33959;
v_34002:
    goto v_34033;
v_34029:
    v_34065 = stack[0];
    v_34065 = qcar(v_34065);
    v_34066 = qcar(v_34065);
    goto v_34030;
v_34031:
    v_34065 = elt(env, 3); // setq
    goto v_34032;
v_34033:
    goto v_34029;
v_34030:
    goto v_34031;
v_34032:
    if (v_34066 == v_34065) goto v_34027;
    else goto v_34028;
v_34027:
    goto v_34043;
v_34039:
    v_34065 = stack[0];
    v_34065 = qcar(v_34065);
    v_34065 = qcdr(v_34065);
    v_34065 = qcar(v_34065);
    v_34066 = Lmkquote(nil, v_34065);
    env = stack[-2];
    goto v_34040;
v_34041:
    v_34065 = stack[-1];
    goto v_34042;
v_34043:
    goto v_34039;
v_34040:
    goto v_34041;
v_34042:
    v_34065 = cons(v_34066, v_34065);
    env = stack[-2];
    stack[-1] = v_34065;
    v_34065 = stack[0];
    v_34065 = qcdr(v_34065);
    stack[0] = v_34065;
    goto v_33959;
v_34028:
    goto v_34059;
v_34055:
    v_34065 = stack[0];
    v_34066 = qcar(v_34065);
    goto v_34056;
v_34057:
    v_34065 = stack[-1];
    goto v_34058;
v_34059:
    goto v_34055;
v_34056:
    goto v_34057;
v_34058:
    v_34065 = cons(v_34066, v_34065);
    env = stack[-2];
    stack[-1] = v_34065;
    v_34065 = stack[0];
    v_34065 = qcdr(v_34065);
    stack[0] = v_34065;
    goto v_33959;
    v_34065 = nil;
    return onevalue(v_34065);
}



// Code for dfmax

static LispObject CC_dfmax(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33977, v_33978, v_33979;
    LispObject fn;
    LispObject v_33956, v_33955, v_33954;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dfmax");
    va_start(aa, nargs);
    v_33954 = va_arg(aa, LispObject);
    v_33955 = va_arg(aa, LispObject);
    v_33956 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33956,v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33954,v_33955,v_33956);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33977 = v_33956;
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    goto v_33969;
v_33963:
    v_33979 = stack[-1];
    goto v_33964;
v_33965:
    v_33978 = stack[0];
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    goto v_33967;
v_33968:
    fn = elt(env, 1); // dfrel
    v_33977 = (*qfnn(fn))(fn, 3, v_33979, v_33978, v_33977);
    if (v_33977 == nil) goto v_33961;
    v_33977 = stack[0];
    goto v_33959;
v_33961:
    v_33977 = stack[-1];
    goto v_33959;
    v_33977 = nil;
v_33959:
    return onevalue(v_33977);
}



// Code for rl_!*qe

static LispObject CC_rl_Hqe(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33972, v_33973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33972 = v_33955;
    v_33973 = v_33954;
// end of prologue
    goto v_33962;
v_33958:
    stack[0] = elt(env, 1); // rl_qe
    goto v_33959;
v_33960:
    goto v_33969;
v_33965:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    goto v_33965;
v_33966:
    goto v_33967;
v_33968:
    v_33972 = list2(v_33973, v_33972);
    env = stack[-1];
    goto v_33961;
v_33962:
    goto v_33958;
v_33959:
    goto v_33960;
v_33961:
    {
        LispObject v_33975 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_33975, v_33972);
    }
}



// Code for dip_comp1

static LispObject CC_dip_comp1(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33967;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33955;
    v_33967 = v_33954;
// end of prologue
    goto v_33962;
v_33958:
    fn = elt(env, 1); // dip_evlmon
    stack[-1] = (*qfn1(fn))(fn, v_33967);
    env = stack[-2];
    goto v_33959;
v_33960:
    v_33967 = stack[0];
    fn = elt(env, 1); // dip_evlmon
    v_33967 = (*qfn1(fn))(fn, v_33967);
    env = stack[-2];
    goto v_33961;
v_33962:
    goto v_33958;
v_33959:
    goto v_33960;
v_33961:
    {
        LispObject v_33970 = stack[-1];
        fn = elt(env, 2); // ev_comp
        return (*qfn2(fn))(fn, v_33970, v_33967);
    }
}



// Code for search4facf

static LispObject CC_search4facf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34014, v_34015;
    LispObject fn;
    LispObject v_33956, v_33955, v_33954;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "search4facf");
    va_start(aa, nargs);
    v_33954 = va_arg(aa, LispObject);
    v_33955 = va_arg(aa, LispObject);
    v_33956 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33956,v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33954,v_33955,v_33956);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_33956;
    stack[-3] = v_33955;
    stack[-4] = v_33954;
// end of prologue
    v_34014 = stack[-3];
    if (v_34014 == nil) goto v_33960;
    else goto v_33961;
v_33960:
    goto v_33968;
v_33964:
    v_34015 = stack[-4];
    goto v_33965;
v_33966:
    v_34014 = stack[-2];
    goto v_33967;
v_33968:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    {
        fn = elt(env, 1); // tryfactorf
        return (*qfn2(fn))(fn, v_34015, v_34014);
    }
v_33961:
    v_34014 = stack[-3];
    v_34014 = qcar(v_34014);
    stack[-5] = v_34014;
v_33977:
    v_34014 = stack[-5];
    if (v_34014 == nil) goto v_33982;
    else goto v_33983;
v_33982:
    v_34014 = nil;
    goto v_33976;
v_33983:
    goto v_33993;
v_33987:
    stack[-1] = stack[-4];
    goto v_33988;
v_33989:
    v_34014 = stack[-3];
    stack[0] = qcdr(v_34014);
    goto v_33990;
v_33991:
    goto v_34002;
v_33998:
    v_34014 = stack[-5];
    v_34015 = qcar(v_34014);
    goto v_33999;
v_34000:
    v_34014 = stack[-2];
    goto v_34001;
v_34002:
    goto v_33998;
v_33999:
    goto v_34000;
v_34001:
    v_34014 = cons(v_34015, v_34014);
    env = stack[-6];
    goto v_33992;
v_33993:
    goto v_33987;
v_33988:
    goto v_33989;
v_33990:
    goto v_33991;
v_33992:
    v_34014 = CC_search4facf(elt(env, 0), 3, stack[-1], stack[0], v_34014);
    env = stack[-6];
    v_34015 = v_34014;
    v_34014 = v_34015;
    if (v_34014 == nil) goto v_34008;
    else goto v_34009;
v_34008:
    v_34014 = stack[-5];
    v_34014 = qcdr(v_34014);
    stack[-5] = v_34014;
    goto v_33977;
v_34009:
    v_34014 = v_34015;
v_33976:
    goto v_33959;
    v_34014 = nil;
v_33959:
    return onevalue(v_34014);
}



// Code for rewrite2

static LispObject CC_rewrite2(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34010, v_34011;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33955;
    v_34010 = v_33954;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_34010;
v_33966:
    v_34010 = stack[0];
    if (v_34010 == nil) goto v_33970;
    else goto v_33971;
v_33970:
    goto v_33965;
v_33971:
    v_34010 = stack[0];
    v_34010 = qcar(v_34010);
    v_34011 = v_34010;
    v_34010 = v_34011;
    v_34010 = qcdr(v_34010);
    stack[-3] = v_34010;
    v_34010 = v_34011;
    v_34010 = qcar(v_34010);
    goto v_33986;
v_33982:
    v_34011 = v_34010;
    goto v_33983;
v_33984:
    v_34010 = stack[-2];
    goto v_33985;
v_33986:
    goto v_33982;
v_33983:
    goto v_33984;
v_33985:
    v_34010 = plus2(v_34011, v_34010);
    env = stack[-4];
    goto v_33994;
v_33990:
    v_34011 = v_34010;
    goto v_33991;
v_33992:
    v_34010 = stack[-3];
    goto v_33993;
v_33994:
    goto v_33990;
v_33991:
    goto v_33992;
v_33993:
    v_34010 = cons(v_34011, v_34010);
    env = stack[-4];
    goto v_34002;
v_33998:
    v_34011 = v_34010;
    goto v_33999;
v_34000:
    v_34010 = stack[-1];
    goto v_34001;
v_34002:
    goto v_33998;
v_33999:
    goto v_34000;
v_34001:
    v_34010 = cons(v_34011, v_34010);
    env = stack[-4];
    stack[-1] = v_34010;
    v_34010 = stack[0];
    v_34010 = qcdr(v_34010);
    stack[0] = v_34010;
    goto v_33966;
v_33965:
    v_34010 = stack[-1];
        return Lreverse(nil, v_34010);
    return onevalue(v_34010);
}



// Code for column_dim

static LispObject CC_column_dim(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33979;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    v_33979 = qvalue(elt(env, 1)); // !*fast_la
    if (v_33979 == nil) goto v_33964;
    else goto v_33965;
v_33964:
    v_33979 = stack[0];
    fn = elt(env, 3); // matrixp
    v_33979 = (*qfn1(fn))(fn, v_33979);
    env = stack[-1];
    v_33979 = (v_33979 == nil ? lisp_true : nil);
    goto v_33963;
v_33965:
    v_33979 = nil;
    goto v_33963;
    v_33979 = nil;
v_33963:
    if (v_33979 == nil) goto v_33961;
    v_33979 = elt(env, 2); // "Error in column_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_33979 = (*qfn1(fn))(fn, v_33979);
    env = stack[-1];
    goto v_33959;
v_33961:
v_33959:
    v_33979 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_33979 = (*qfn1(fn))(fn, v_33979);
    v_33979 = qcdr(v_33979);
    v_33979 = qcar(v_33979);
    return onevalue(v_33979);
}



// Code for gvarlis

static LispObject CC_gvarlis(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33971, v_33972;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33971 = v_33954;
// end of prologue
    goto v_33961;
v_33957:
    goto v_33967;
v_33963:
    v_33972 = v_33971;
    goto v_33964;
v_33965:
    v_33971 = nil;
    goto v_33966;
v_33967:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    fn = elt(env, 2); // gvarlis1
    v_33972 = (*qfn2(fn))(fn, v_33972, v_33971);
    env = stack[0];
    goto v_33958;
v_33959:
    v_33971 = elt(env, 1); // ordop
    goto v_33960;
v_33961:
    goto v_33957;
v_33958:
    goto v_33959;
v_33960:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_33972, v_33971);
    }
}



// Code for weak_xreduce

static LispObject CC_weak_xreduce(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34021, v_34022, v_34023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    v_34021 = nil;
    v_34021 = ncons(v_34021);
    env = stack[-3];
    stack[-2] = v_34021;
    v_34021 = qvalue(elt(env, 1)); // !*trxmod
    if (v_34021 == nil) goto v_33966;
    goto v_33973;
v_33969:
    v_34021 = stack[-1];
    fn = elt(env, 6); // preppf
    v_34021 = (*qfn1(fn))(fn, v_34021);
    env = stack[-3];
    v_34022 = Lmkquote(nil, v_34021);
    env = stack[-3];
    goto v_33970;
v_33971:
    v_34021 = nil;
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    fn = elt(env, 7); // writepri
    v_34021 = (*qfn2(fn))(fn, v_34022, v_34021);
    env = stack[-3];
    goto v_33983;
v_33979:
    v_34022 = elt(env, 2); // " ="
    goto v_33980;
v_33981:
    v_34021 = elt(env, 3); // last
    goto v_33982;
v_33983:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    fn = elt(env, 7); // writepri
    v_34021 = (*qfn2(fn))(fn, v_34022, v_34021);
    env = stack[-3];
    goto v_33964;
v_33966:
v_33964:
    goto v_33993;
v_33987:
    v_34023 = stack[-1];
    goto v_33988;
v_33989:
    v_34022 = stack[0];
    goto v_33990;
v_33991:
    v_34021 = stack[-2];
    goto v_33992;
v_33993:
    goto v_33987;
v_33988:
    goto v_33989;
v_33990:
    goto v_33991;
v_33992:
    fn = elt(env, 8); // weak_xreduce1
    v_34021 = (*qfnn(fn))(fn, 3, v_34023, v_34022, v_34021);
    env = stack[-3];
    stack[0] = v_34021;
    v_34021 = qvalue(elt(env, 1)); // !*trxmod
    if (v_34021 == nil) goto v_34000;
    goto v_34007;
v_34003:
    v_34022 = elt(env, 4); // "   "
    goto v_34004;
v_34005:
    v_34021 = elt(env, 5); // first
    goto v_34006;
v_34007:
    goto v_34003;
v_34004:
    goto v_34005;
v_34006:
    fn = elt(env, 7); // writepri
    v_34021 = (*qfn2(fn))(fn, v_34022, v_34021);
    env = stack[-3];
    goto v_34015;
v_34011:
    v_34021 = stack[0];
    fn = elt(env, 6); // preppf
    v_34021 = (*qfn1(fn))(fn, v_34021);
    env = stack[-3];
    v_34022 = Lmkquote(nil, v_34021);
    env = stack[-3];
    goto v_34012;
v_34013:
    v_34021 = elt(env, 3); // last
    goto v_34014;
v_34015:
    goto v_34011;
v_34012:
    goto v_34013;
v_34014:
    fn = elt(env, 7); // writepri
    v_34021 = (*qfn2(fn))(fn, v_34022, v_34021);
    goto v_33998;
v_34000:
v_33998:
    v_34021 = stack[0];
    return onevalue(v_34021);
}



// Code for tvectorp

static LispObject CC_tvectorp(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33977, v_33978;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
// copy arguments values to proper place
    v_33977 = v_33954;
// end of prologue
    v_33977 = qcar(v_33977);
    v_33977 = qcar(v_33977);
    fn = elt(env, 1); // deg!*form
    v_33977 = (*qfn1(fn))(fn, v_33977);
    v_33978 = v_33977;
    v_33977 = v_33978;
    if (is_number(v_33977)) goto v_33964;
    v_33977 = nil;
    goto v_33962;
v_33964:
    goto v_33974;
v_33970:
    goto v_33971;
v_33972:
    v_33977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33973;
v_33974:
    goto v_33970;
v_33971:
    goto v_33972;
v_33973:
        return Llessp(nil, v_33978, v_33977);
    v_33977 = nil;
v_33962:
    return onevalue(v_33977);
}



// Code for ev!-tades

static LispObject CC_evKtades(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34003, v_34004, v_34005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    stack[-2] = nil;
v_33960:
    v_34003 = stack[-1];
    if (v_34003 == nil) goto v_33963;
    else goto v_33964;
v_33963:
    goto v_33971;
v_33967:
    stack[0] = stack[-2];
    goto v_33968;
v_33969:
    v_34003 = (LispObject)16+TAG_FIXNUM; // 1
    v_34003 = ncons(v_34003);
    env = stack[-3];
    goto v_33970;
v_33971:
    goto v_33967;
v_33968:
    goto v_33969;
v_33970:
    {
        LispObject v_34009 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_34009, v_34003);
    }
v_33964:
    goto v_33982;
v_33978:
    goto v_33988;
v_33984:
    v_34005 = qvalue(elt(env, 1)); // ndim!*
    goto v_33985;
v_33986:
    goto v_33994;
v_33990:
    v_34003 = stack[-1];
    v_34004 = qcar(v_34003);
    goto v_33991;
v_33992:
    v_34003 = stack[0];
    goto v_33993;
v_33994:
    goto v_33990;
v_33991:
    goto v_33992;
v_33993:
    v_34003 = Lassoc(nil, v_34004, v_34003);
    v_34003 = qcdr(v_34003);
    goto v_33987;
v_33988:
    goto v_33984;
v_33985:
    goto v_33986;
v_33987:
    fn = elt(env, 3); // binc
    v_34004 = (*qfn2(fn))(fn, v_34005, v_34003);
    env = stack[-3];
    goto v_33979;
v_33980:
    v_34003 = stack[-2];
    goto v_33981;
v_33982:
    goto v_33978;
v_33979:
    goto v_33980;
v_33981:
    v_34003 = cons(v_34004, v_34003);
    env = stack[-3];
    stack[-2] = v_34003;
    v_34003 = stack[-1];
    v_34003 = qcdr(v_34003);
    stack[-1] = v_34003;
    goto v_33960;
    v_34003 = nil;
    return onevalue(v_34003);
}



// Code for reprod

static LispObject CC_reprod(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33986, v_33987;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
v_33959:
    v_33986 = stack[-1];
    if (v_33986 == nil) goto v_33962;
    else goto v_33963;
v_33962:
    goto v_33958;
v_33963:
    goto v_33971;
v_33967:
    goto v_33978;
v_33974:
    v_33986 = stack[-1];
    v_33987 = qcar(v_33986);
    goto v_33975;
v_33976:
    v_33986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33977;
v_33978:
    goto v_33974;
v_33975:
    goto v_33976;
v_33977:
    v_33986 = cons(v_33987, v_33986);
    env = stack[-2];
    v_33987 = ncons(v_33986);
    env = stack[-2];
    goto v_33968;
v_33969:
    v_33986 = stack[0];
    goto v_33970;
v_33971:
    goto v_33967;
v_33968:
    goto v_33969;
v_33970:
    fn = elt(env, 1); // multf
    v_33986 = (*qfn2(fn))(fn, v_33987, v_33986);
    env = stack[-2];
    stack[0] = v_33986;
    v_33986 = stack[-1];
    v_33986 = qcdr(v_33986);
    stack[-1] = v_33986;
    goto v_33959;
v_33958:
    v_33986 = stack[0];
    return onevalue(v_33986);
}



// Code for mo_from_ei

static LispObject CC_mo_from_ei(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33982, v_33983, v_33984;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33984 = v_33954;
// end of prologue
    goto v_33964;
v_33960:
    v_33983 = v_33984;
    goto v_33961;
v_33962:
    v_33982 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33963;
v_33964:
    goto v_33960;
v_33961:
    goto v_33962;
v_33963:
    if (v_33983 == v_33982) goto v_33958;
    else goto v_33959;
v_33958:
    {
        fn = elt(env, 1); // mo_zero
        return (*qfnn(fn))(fn, 0);
    }
v_33959:
    v_33982 = v_33984;
    v_33982 = ncons(v_33982);
    env = stack[-1];
    goto v_33978;
v_33974:
    stack[0] = v_33982;
    goto v_33975;
v_33976:
    fn = elt(env, 2); // mo!=deglist
    v_33982 = (*qfn1(fn))(fn, v_33982);
    goto v_33977;
v_33978:
    goto v_33974;
v_33975:
    goto v_33976;
v_33977:
    {
        LispObject v_33986 = stack[0];
        return cons(v_33986, v_33982);
    }
    v_33982 = nil;
    return onevalue(v_33982);
}



// Code for pa_vect2list

static LispObject CC_pa_vect2list(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34087, v_34088;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_33954;
// end of prologue
    v_34087 = stack[-6];
    v_34087 = qcdr(v_34087);
    fn = elt(env, 1); // upbve
    v_34087 = (*qfn1(fn))(fn, v_34087);
    env = stack[-8];
    v_34087 = sub1(v_34087);
    env = stack[-8];
    v_34087 = Lmkvect(nil, v_34087);
    env = stack[-8];
    stack[-7] = v_34087;
    v_34087 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_34087;
v_33971:
    goto v_33983;
v_33979:
    v_34087 = stack[-6];
    v_34087 = qcdr(v_34087);
    fn = elt(env, 1); // upbve
    v_34088 = (*qfn1(fn))(fn, v_34087);
    env = stack[-8];
    goto v_33980;
v_33981:
    v_34087 = stack[-4];
    goto v_33982;
v_33983:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    v_34087 = difference2(v_34088, v_34087);
    env = stack[-8];
    v_34087 = Lminusp(nil, v_34087);
    env = stack[-8];
    if (v_34087 == nil) goto v_33976;
    goto v_33970;
v_33976:
    goto v_33993;
v_33989:
    v_34087 = stack[-6];
    stack[0] = qcdr(v_34087);
    goto v_33990;
v_33991:
    v_34087 = stack[-4];
    v_34087 = sub1(v_34087);
    env = stack[-8];
    goto v_33992;
v_33993:
    goto v_33989;
v_33990:
    goto v_33991;
v_33992:
    v_34087 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_34087-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_34087;
    goto v_34005;
v_33999:
    stack[-3] = stack[-7];
    goto v_34000;
v_34001:
    v_34087 = stack[-5];
    stack[-2] = sub1(v_34087);
    env = stack[-8];
    goto v_34002;
v_34003:
    goto v_34014;
v_34010:
    stack[-1] = stack[-4];
    goto v_34011;
v_34012:
    goto v_34020;
v_34016:
    stack[0] = stack[-7];
    goto v_34017;
v_34018:
    v_34087 = stack[-5];
    v_34087 = sub1(v_34087);
    env = stack[-8];
    goto v_34019;
v_34020:
    goto v_34016;
v_34017:
    goto v_34018;
v_34019:
    v_34087 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_34087-TAG_FIXNUM)/(16/CELL)));
    goto v_34013;
v_34014:
    goto v_34010;
v_34011:
    goto v_34012;
v_34013:
    v_34087 = cons(stack[-1], v_34087);
    env = stack[-8];
    goto v_34004;
v_34005:
    goto v_33999;
v_34000:
    goto v_34001;
v_34002:
    goto v_34003;
v_34004:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_34087;
    v_34087 = stack[-4];
    v_34087 = add1(v_34087);
    env = stack[-8];
    stack[-4] = v_34087;
    goto v_33971;
v_33970:
    v_34087 = stack[-6];
    v_34087 = qcar(v_34087);
    stack[-4] = v_34087;
    v_34087 = stack[-4];
    if (v_34087 == nil) goto v_34038;
    else goto v_34039;
v_34038:
    v_34087 = nil;
    goto v_34032;
v_34039:
    v_34087 = stack[-4];
    v_34087 = qcar(v_34087);
    goto v_34051;
v_34047:
    stack[0] = stack[-7];
    goto v_34048;
v_34049:
    v_34087 = sub1(v_34087);
    env = stack[-8];
    goto v_34050;
v_34051:
    goto v_34047;
v_34048:
    goto v_34049;
v_34050:
    v_34087 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_34087-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // ordn
    v_34087 = (*qfn1(fn))(fn, v_34087);
    env = stack[-8];
    v_34087 = ncons(v_34087);
    env = stack[-8];
    stack[-2] = v_34087;
    stack[-3] = v_34087;
v_34033:
    v_34087 = stack[-4];
    v_34087 = qcdr(v_34087);
    stack[-4] = v_34087;
    v_34087 = stack[-4];
    if (v_34087 == nil) goto v_34060;
    else goto v_34061;
v_34060:
    v_34087 = stack[-3];
    goto v_34032;
v_34061:
    goto v_34069;
v_34065:
    stack[-1] = stack[-2];
    goto v_34066;
v_34067:
    v_34087 = stack[-4];
    v_34087 = qcar(v_34087);
    goto v_34080;
v_34076:
    stack[0] = stack[-7];
    goto v_34077;
v_34078:
    v_34087 = sub1(v_34087);
    env = stack[-8];
    goto v_34079;
v_34080:
    goto v_34076;
v_34077:
    goto v_34078;
v_34079:
    v_34087 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_34087-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // ordn
    v_34087 = (*qfn1(fn))(fn, v_34087);
    env = stack[-8];
    v_34087 = ncons(v_34087);
    env = stack[-8];
    goto v_34068;
v_34069:
    goto v_34065;
v_34066:
    goto v_34067;
v_34068:
    v_34087 = Lrplacd(nil, stack[-1], v_34087);
    env = stack[-8];
    v_34087 = stack[-2];
    v_34087 = qcdr(v_34087);
    stack[-2] = v_34087;
    goto v_34033;
v_34032:
    return onevalue(v_34087);
}



// Code for remk

static LispObject CC_remk(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34071, v_34072;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_33955;
    stack[-5] = v_33954;
// end of prologue
    v_34071 = stack[-4];
    v_34071 = qcar(v_34071);
    v_34071 = qcdr(v_34071);
    stack[-6] = v_34071;
    v_34071 = stack[-4];
    v_34071 = qcar(v_34071);
    v_34071 = qcar(v_34071);
    v_34071 = qcar(v_34071);
    stack[-3] = v_34071;
    v_34071 = stack[-4];
    v_34071 = qcar(v_34071);
    v_34071 = qcar(v_34071);
    v_34071 = qcdr(v_34071);
    stack[0] = v_34071;
v_33979:
    goto v_33989;
v_33985:
    goto v_33995;
v_33991:
    goto v_34001;
v_33997:
    v_34072 = stack[-5];
    goto v_33998;
v_33999:
    v_34071 = stack[-3];
    goto v_34000;
v_34001:
    goto v_33997;
v_33998:
    goto v_33999;
v_34000:
    fn = elt(env, 1); // degr
    v_34072 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    goto v_33992;
v_33993:
    v_34071 = stack[0];
    goto v_33994;
v_33995:
    goto v_33991;
v_33992:
    goto v_33993;
v_33994:
    v_34072 = difference2(v_34072, v_34071);
    env = stack[-7];
    stack[-1] = v_34072;
    goto v_33986;
v_33987:
    v_34071 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33988;
v_33989:
    goto v_33985;
v_33986:
    goto v_33987;
v_33988:
    v_34071 = (LispObject)geq2(v_34072, v_34071);
    v_34071 = v_34071 ? lisp_true : nil;
    env = stack[-7];
    if (v_34071 == nil) goto v_33982;
    else goto v_33983;
v_33982:
    goto v_33978;
v_33983:
    goto v_34013;
v_34009:
    v_34071 = stack[-5];
    v_34071 = qcar(v_34071);
    v_34072 = qcdr(v_34071);
    goto v_34010;
v_34011:
    v_34071 = stack[-4];
    v_34071 = qcdr(v_34071);
    goto v_34012;
v_34013:
    goto v_34009;
v_34010:
    goto v_34011;
v_34012:
    fn = elt(env, 2); // multf
    v_34071 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    fn = elt(env, 3); // negf
    v_34071 = (*qfn1(fn))(fn, v_34071);
    env = stack[-7];
    stack[-2] = v_34071;
    goto v_34028;
v_34024:
    v_34072 = stack[-1];
    goto v_34025;
v_34026:
    v_34071 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34027;
v_34028:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    v_34071 = (LispObject)greaterp2(v_34072, v_34071);
    v_34071 = v_34071 ? lisp_true : nil;
    env = stack[-7];
    if (v_34071 == nil) goto v_34022;
    goto v_34036;
v_34032:
    goto v_34043;
v_34039:
    goto v_34049;
v_34045:
    v_34072 = stack[-3];
    goto v_34046;
v_34047:
    v_34071 = stack[-1];
    goto v_34048;
v_34049:
    goto v_34045;
v_34046:
    goto v_34047;
v_34048:
    fn = elt(env, 4); // to
    v_34072 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    goto v_34040;
v_34041:
    v_34071 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34042;
v_34043:
    goto v_34039;
v_34040:
    goto v_34041;
v_34042:
    v_34071 = cons(v_34072, v_34071);
    env = stack[-7];
    v_34072 = ncons(v_34071);
    env = stack[-7];
    goto v_34033;
v_34034:
    v_34071 = stack[-2];
    goto v_34035;
v_34036:
    goto v_34032;
v_34033:
    goto v_34034;
v_34035:
    fn = elt(env, 2); // multf
    v_34071 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    stack[-2] = v_34071;
    goto v_34020;
v_34022:
v_34020:
    goto v_34059;
v_34055:
    goto v_34065;
v_34061:
    v_34072 = stack[-6];
    goto v_34062;
v_34063:
    v_34071 = stack[-5];
    v_34071 = qcdr(v_34071);
    goto v_34064;
v_34065:
    goto v_34061;
v_34062:
    goto v_34063;
v_34064:
    fn = elt(env, 2); // multf
    v_34072 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    goto v_34056;
v_34057:
    v_34071 = stack[-2];
    goto v_34058;
v_34059:
    goto v_34055;
v_34056:
    goto v_34057;
v_34058:
    fn = elt(env, 5); // addf
    v_34071 = (*qfn2(fn))(fn, v_34072, v_34071);
    env = stack[-7];
    stack[-5] = v_34071;
    goto v_33979;
v_33978:
    v_34071 = stack[-5];
    return onevalue(v_34071);
}



// Code for modroots1

static LispObject CC_modroots1(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34207, v_34208, v_34209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-1] = v_33955;
    stack[-10] = v_33954;
// end of prologue
    v_34207 = stack[-1];
    v_34207 = qcdr(v_34207);
    if (v_34207 == nil) goto v_33959;
    else goto v_33960;
v_33959:
    goto v_33970;
v_33964:
    v_34209 = stack[-10];
    goto v_33965;
v_33966:
    v_34207 = stack[-1];
    v_34208 = qcar(v_34207);
    goto v_33967;
v_33968:
    v_34207 = nil;
    goto v_33969;
v_33970:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    {
        fn = elt(env, 4); // modroots2
        return (*qfnn(fn))(fn, 3, v_34209, v_34208, v_34207);
    }
v_33960:
    stack[-7] = nil;
    v_34207 = stack[-1];
    v_34207 = qcar(v_34207);
    stack[-11] = v_34207;
    v_34207 = stack[-1];
    v_34207 = qcdr(v_34207);
    stack[-1] = v_34207;
    goto v_33996;
v_33992:
    v_34208 = stack[-10];
    goto v_33993;
v_33994:
    v_34207 = stack[-1];
    goto v_33995;
v_33996:
    goto v_33992;
v_33993:
    goto v_33994;
v_33995:
    v_34207 = CC_modroots1(elt(env, 0), v_34208, v_34207);
    env = stack[-12];
    stack[0] = v_34207;
    v_34207 = stack[0];
    if (v_34207 == nil) goto v_34001;
    else goto v_34002;
v_34001:
    v_34207 = nil;
    goto v_33986;
v_34002:
    v_34207 = stack[-10];
    v_34207 = qcar(v_34207);
    v_34207 = qcar(v_34207);
    v_34207 = qcar(v_34207);
    stack[-6] = v_34207;
    v_34207 = elt(env, 1); // g
    v_34207 = Lgensym1(nil, v_34207);
    env = stack[-12];
    stack[-5] = v_34207;
    v_34207 = stack[-1];
    stack[-1] = v_34207;
    v_34207 = (LispObject)16+TAG_FIXNUM; // 1
    v_34208 = v_34207;
v_34015:
    v_34207 = stack[-1];
    if (v_34207 == nil) goto v_34020;
    else goto v_34021;
v_34020:
    v_34207 = v_34208;
    goto v_34014;
v_34021:
    goto v_34029;
v_34025:
    v_34207 = stack[-1];
    v_34207 = qcar(v_34207);
    goto v_34026;
v_34027:
    goto v_34028;
v_34029:
    goto v_34025;
v_34026:
    goto v_34027;
v_34028:
    v_34207 = times2(v_34207, v_34208);
    env = stack[-12];
    v_34208 = v_34207;
    v_34207 = stack[-1];
    v_34207 = qcdr(v_34207);
    stack[-1] = v_34207;
    goto v_34015;
v_34014:
    stack[-9] = v_34207;
    goto v_34042;
v_34038:
    v_34208 = stack[-11];
    goto v_34039;
v_34040:
    v_34207 = stack[-9];
    goto v_34041;
v_34042:
    goto v_34038;
v_34039:
    goto v_34040;
v_34041:
    v_34207 = times2(v_34208, v_34207);
    env = stack[-12];
    stack[-8] = v_34207;
    v_34207 = stack[0];
    stack[-4] = v_34207;
v_34048:
    v_34207 = stack[-4];
    if (v_34207 == nil) goto v_34052;
    else goto v_34053;
v_34052:
    goto v_34047;
v_34053:
    v_34207 = stack[-4];
    v_34207 = qcar(v_34207);
    stack[-3] = v_34207;
    goto v_34064;
v_34060:
    stack[-2] = stack[-10];
    goto v_34061;
v_34062:
    goto v_34074;
v_34068:
    stack[-1] = stack[-6];
    goto v_34069;
v_34070:
    stack[0] = elt(env, 2); // plus
    goto v_34071;
v_34072:
    goto v_34082;
v_34078:
    goto v_34090;
v_34084:
    v_34209 = elt(env, 3); // times
    goto v_34085;
v_34086:
    v_34208 = stack[-5];
    goto v_34087;
v_34088:
    v_34207 = stack[-9];
    goto v_34089;
v_34090:
    goto v_34084;
v_34085:
    goto v_34086;
v_34087:
    goto v_34088;
v_34089:
    v_34208 = list3(v_34209, v_34208, v_34207);
    env = stack[-12];
    goto v_34079;
v_34080:
    v_34207 = stack[-3];
    goto v_34081;
v_34082:
    goto v_34078;
v_34079:
    goto v_34080;
v_34081:
    v_34207 = list2(v_34208, v_34207);
    env = stack[-12];
    goto v_34073;
v_34074:
    goto v_34068;
v_34069:
    goto v_34070;
v_34071:
    goto v_34072;
v_34073:
    v_34207 = list2star(stack[-1], stack[0], v_34207);
    env = stack[-12];
    v_34207 = ncons(v_34207);
    env = stack[-12];
    goto v_34063;
v_34064:
    goto v_34060;
v_34061:
    goto v_34062;
v_34063:
    fn = elt(env, 5); // subf
    v_34207 = (*qfn2(fn))(fn, stack[-2], v_34207);
    env = stack[-12];
    v_34207 = qcar(v_34207);
    goto v_34107;
v_34101:
    goto v_34113;
v_34109:
    v_34208 = v_34207;
    goto v_34110;
v_34111:
    v_34207 = stack[-11];
    goto v_34112;
v_34113:
    goto v_34109;
v_34110:
    goto v_34111;
v_34112:
    fn = elt(env, 6); // reduce!-mod!-p!*
    v_34209 = (*qfn2(fn))(fn, v_34208, v_34207);
    env = stack[-12];
    goto v_34102;
v_34103:
    v_34208 = stack[-11];
    goto v_34104;
v_34105:
    v_34207 = lisp_true;
    goto v_34106;
v_34107:
    goto v_34101;
v_34102:
    goto v_34103;
v_34104:
    goto v_34105;
v_34106:
    fn = elt(env, 4); // modroots2
    v_34207 = (*qfnn(fn))(fn, 3, v_34209, v_34208, v_34207);
    env = stack[-12];
    stack[-2] = v_34207;
v_34099:
    v_34207 = stack[-2];
    if (v_34207 == nil) goto v_34120;
    else goto v_34121;
v_34120:
    goto v_34098;
v_34121:
    v_34207 = stack[-2];
    v_34207 = qcar(v_34207);
    stack[-1] = v_34207;
    goto v_34132;
v_34128:
    goto v_34138;
v_34134:
    goto v_34144;
v_34140:
    v_34208 = stack[-1];
    goto v_34141;
v_34142:
    v_34207 = stack[-9];
    goto v_34143;
v_34144:
    goto v_34140;
v_34141:
    goto v_34142;
v_34143:
    v_34208 = times2(v_34208, v_34207);
    env = stack[-12];
    goto v_34135;
v_34136:
    v_34207 = stack[-3];
    goto v_34137;
v_34138:
    goto v_34134;
v_34135:
    goto v_34136;
v_34137:
    v_34208 = plus2(v_34208, v_34207);
    env = stack[-12];
    goto v_34129;
v_34130:
    v_34207 = stack[-8];
    goto v_34131;
v_34132:
    goto v_34128;
v_34129:
    goto v_34130;
v_34131:
    fn = elt(env, 7); // modp
    v_34207 = (*qfn2(fn))(fn, v_34208, v_34207);
    env = stack[-12];
    stack[-1] = v_34207;
    goto v_34162;
v_34158:
    goto v_34168;
v_34164:
    stack[0] = stack[-10];
    goto v_34165;
v_34166:
    goto v_34176;
v_34172:
    v_34208 = stack[-6];
    goto v_34173;
v_34174:
    v_34207 = stack[-1];
    goto v_34175;
v_34176:
    goto v_34172;
v_34173:
    goto v_34174;
v_34175:
    v_34207 = cons(v_34208, v_34207);
    env = stack[-12];
    v_34207 = ncons(v_34207);
    env = stack[-12];
    goto v_34167;
v_34168:
    goto v_34164;
v_34165:
    goto v_34166;
v_34167:
    fn = elt(env, 5); // subf
    v_34207 = (*qfn2(fn))(fn, stack[0], v_34207);
    env = stack[-12];
    v_34208 = qcar(v_34207);
    goto v_34159;
v_34160:
    v_34207 = stack[-8];
    goto v_34161;
v_34162:
    goto v_34158;
v_34159:
    goto v_34160;
v_34161:
    fn = elt(env, 6); // reduce!-mod!-p!*
    v_34207 = (*qfn2(fn))(fn, v_34208, v_34207);
    env = stack[-12];
    if (v_34207 == nil) goto v_34155;
    else goto v_34156;
v_34155:
    goto v_34185;
v_34181:
    v_34208 = stack[-1];
    goto v_34182;
v_34183:
    v_34207 = stack[-7];
    goto v_34184;
v_34185:
    goto v_34181;
v_34182:
    goto v_34183;
v_34184:
    v_34207 = Lmember(nil, v_34208, v_34207);
    v_34207 = (v_34207 == nil ? lisp_true : nil);
    goto v_34154;
v_34156:
    v_34207 = nil;
    goto v_34154;
    v_34207 = nil;
v_34154:
    if (v_34207 == nil) goto v_34152;
    goto v_34198;
v_34194:
    v_34208 = stack[-1];
    goto v_34195;
v_34196:
    v_34207 = stack[-7];
    goto v_34197;
v_34198:
    goto v_34194;
v_34195:
    goto v_34196;
v_34197:
    v_34207 = cons(v_34208, v_34207);
    env = stack[-12];
    stack[-7] = v_34207;
    goto v_34150;
v_34152:
v_34150:
    v_34207 = stack[-2];
    v_34207 = qcdr(v_34207);
    stack[-2] = v_34207;
    goto v_34099;
v_34098:
    v_34207 = stack[-4];
    v_34207 = qcdr(v_34207);
    stack[-4] = v_34207;
    goto v_34048;
v_34047:
    v_34207 = stack[-7];
v_33986:
    goto v_33958;
    v_34207 = nil;
v_33958:
    return onevalue(v_34207);
}



// Code for simprad

static LispObject CC_simprad(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34259, v_34260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_33955;
    stack[0] = v_33954;
// end of prologue
    v_34259 = qvalue(elt(env, 1)); // !*reduced
    if (v_34259 == nil) goto v_33960;
    goto v_33967;
v_33963:
    goto v_33973;
v_33969:
    v_34259 = stack[0];
    v_34260 = qcar(v_34259);
    goto v_33970;
v_33971:
    v_34259 = stack[-3];
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    fn = elt(env, 5); // radfa
    stack[-1] = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    goto v_33964;
v_33965:
    goto v_33983;
v_33979:
    v_34259 = stack[0];
    v_34260 = qcdr(v_34259);
    goto v_33980;
v_33981:
    v_34259 = stack[-3];
    goto v_33982;
v_33983:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    fn = elt(env, 5); // radfa
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    fn = elt(env, 6); // invsq
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_33966;
v_33967:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    {
        LispObject v_34267 = stack[-1];
        fn = elt(env, 7); // multsq
        return (*qfn2(fn))(fn, v_34267, v_34259);
    }
v_33960:
    stack[-4] = nil;
    v_34259 = qvalue(elt(env, 2)); // !*rationalize
    if (v_34259 == nil) goto v_33998;
    goto v_34005;
v_34001:
    v_34259 = stack[0];
    v_34260 = qcdr(v_34259);
    goto v_34002;
v_34003:
    v_34259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34004;
v_34005:
    goto v_34001;
v_34002:
    goto v_34003;
v_34004:
    v_34259 = list2(v_34260, v_34259);
    env = stack[-6];
    stack[-1] = v_34259;
    goto v_34014;
v_34010:
    goto v_34020;
v_34016:
    v_34259 = stack[0];
    stack[-2] = qcar(v_34259);
    goto v_34017;
v_34018:
    goto v_34028;
v_34024:
    v_34259 = stack[0];
    stack[0] = qcdr(v_34259);
    goto v_34025;
v_34026:
    v_34259 = stack[-3];
    v_34259 = sub1(v_34259);
    env = stack[-6];
    goto v_34027;
v_34028:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    fn = elt(env, 8); // exptf
    v_34259 = (*qfn2(fn))(fn, stack[0], v_34259);
    env = stack[-6];
    goto v_34019;
v_34020:
    goto v_34016;
v_34017:
    goto v_34018;
v_34019:
    fn = elt(env, 9); // multf
    v_34260 = (*qfn2(fn))(fn, stack[-2], v_34259);
    env = stack[-6];
    goto v_34011;
v_34012:
    v_34259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34013;
v_34014:
    goto v_34010;
v_34011:
    goto v_34012;
v_34013:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-6];
    stack[0] = v_34259;
    goto v_33996;
v_33998:
    goto v_34041;
v_34037:
    v_34259 = stack[0];
    v_34260 = qcdr(v_34259);
    goto v_34038;
v_34039:
    v_34259 = stack[-3];
    goto v_34040;
v_34041:
    goto v_34037;
v_34038:
    goto v_34039;
v_34040:
    fn = elt(env, 10); // radf
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    stack[-1] = v_34259;
    goto v_33996;
v_33996:
    goto v_34057;
v_34053:
    v_34260 = stack[-3];
    goto v_34054;
v_34055:
    v_34259 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_34056;
v_34057:
    goto v_34053;
v_34054:
    goto v_34055;
v_34056:
    if (v_34260 == v_34259) goto v_34051;
    else goto v_34052;
v_34051:
    v_34259 = stack[0];
    v_34259 = qcar(v_34259);
    fn = elt(env, 11); // minusf
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34050;
v_34052:
    v_34259 = nil;
    goto v_34050;
    v_34259 = nil;
v_34050:
    if (v_34259 == nil) goto v_34048;
    v_34259 = lisp_true;
    stack[-4] = v_34259;
    goto v_34072;
v_34068:
    v_34259 = stack[0];
    v_34259 = qcar(v_34259);
    fn = elt(env, 12); // negf
    v_34260 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34069;
v_34070:
    v_34259 = stack[-3];
    goto v_34071;
v_34072:
    goto v_34068;
v_34069:
    goto v_34070;
v_34071:
    fn = elt(env, 10); // radf
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    stack[-2] = v_34259;
    goto v_34046;
v_34048:
    goto v_34084;
v_34080:
    v_34259 = stack[0];
    v_34260 = qcar(v_34259);
    goto v_34081;
v_34082:
    v_34259 = stack[-3];
    goto v_34083;
v_34084:
    goto v_34080;
v_34081:
    goto v_34082;
v_34083:
    fn = elt(env, 10); // radf
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    stack[-2] = v_34259;
    goto v_34046;
v_34046:
    goto v_34096;
v_34090:
    stack[-5] = elt(env, 3); // quotient
    goto v_34091;
v_34092:
    v_34259 = stack[-2];
    v_34259 = qcdr(v_34259);
    fn = elt(env, 13); // retimes
    stack[0] = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34093;
v_34094:
    v_34259 = stack[-1];
    v_34259 = qcdr(v_34259);
    fn = elt(env, 13); // retimes
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34095;
v_34096:
    goto v_34090;
v_34091:
    goto v_34092;
v_34093:
    goto v_34094;
v_34095:
    v_34259 = list3(stack[-5], stack[0], v_34259);
    env = stack[-6];
    fn = elt(env, 14); // simp
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    stack[-5] = v_34259;
    v_34259 = stack[-5];
    v_34259 = qcar(v_34259);
    if (!consp(v_34259)) goto v_34114;
    else goto v_34115;
v_34114:
    v_34259 = lisp_true;
    goto v_34113;
v_34115:
    v_34259 = stack[-5];
    v_34259 = qcar(v_34259);
    v_34259 = qcar(v_34259);
    v_34259 = (consp(v_34259) ? nil : lisp_true);
    goto v_34113;
    v_34259 = nil;
v_34113:
    if (v_34259 == nil) goto v_34111;
    v_34259 = stack[-5];
    v_34259 = qcdr(v_34259);
    if (!consp(v_34259)) goto v_34127;
    else goto v_34128;
v_34127:
    v_34259 = lisp_true;
    goto v_34126;
v_34128:
    v_34259 = stack[-5];
    v_34259 = qcdr(v_34259);
    v_34259 = qcar(v_34259);
    v_34259 = (consp(v_34259) ? nil : lisp_true);
    goto v_34126;
    v_34259 = nil;
v_34126:
    goto v_34109;
v_34111:
    v_34259 = nil;
    goto v_34109;
    v_34259 = nil;
v_34109:
    if (v_34259 == nil) goto v_34107;
    goto v_34146;
v_34142:
    goto v_34152;
v_34148:
    v_34259 = stack[-5];
    v_34259 = qcar(v_34259);
    fn = elt(env, 15); // prepf
    v_34260 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34149;
v_34150:
    v_34259 = stack[-3];
    goto v_34151;
v_34152:
    goto v_34148;
v_34149:
    goto v_34150;
v_34151:
    fn = elt(env, 16); // mkrootsq
    stack[0] = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    goto v_34143;
v_34144:
    goto v_34163;
v_34159:
    v_34259 = stack[-5];
    v_34259 = qcdr(v_34259);
    fn = elt(env, 15); // prepf
    v_34260 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34160;
v_34161:
    v_34259 = stack[-3];
    goto v_34162;
v_34163:
    goto v_34159;
v_34160:
    goto v_34161;
v_34162:
    fn = elt(env, 16); // mkrootsq
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    fn = elt(env, 6); // invsq
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34145;
v_34146:
    goto v_34142;
v_34143:
    goto v_34144;
v_34145:
    fn = elt(env, 7); // multsq
    v_34259 = (*qfn2(fn))(fn, stack[0], v_34259);
    env = stack[-6];
    stack[-5] = v_34259;
    goto v_34105;
v_34107:
    v_34259 = stack[-4];
    if (v_34259 == nil) goto v_34173;
    v_34259 = nil;
    stack[-4] = v_34259;
    v_34259 = stack[-5];
    fn = elt(env, 17); // negsq
    v_34259 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    stack[-5] = v_34259;
    goto v_34171;
v_34173:
v_34171:
    goto v_34183;
v_34179:
    v_34259 = stack[-5];
    fn = elt(env, 18); // prepsq
    v_34260 = (*qfn1(fn))(fn, v_34259);
    env = stack[-6];
    goto v_34180;
v_34181:
    v_34259 = stack[-3];
    goto v_34182;
v_34183:
    goto v_34179;
v_34180:
    goto v_34181;
v_34182:
    fn = elt(env, 16); // mkrootsq
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    stack[-5] = v_34259;
    goto v_34105;
v_34105:
    goto v_34192;
v_34188:
    goto v_34198;
v_34194:
    v_34259 = qvalue(elt(env, 4)); // !*precise
    if (v_34259 == nil) goto v_34202;
    v_34259 = stack[-3];
    v_34259 = Levenp(nil, v_34259);
    env = stack[-6];
    if (v_34259 == nil) goto v_34202;
    goto v_34213;
v_34209:
    v_34259 = stack[-2];
    v_34260 = qcar(v_34259);
    goto v_34210;
v_34211:
    v_34259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34212;
v_34213:
    goto v_34209;
v_34210:
    goto v_34211;
v_34212:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-6];
    stack[0] = v_34259;
    goto v_34200;
v_34202:
    goto v_34224;
v_34220:
    v_34259 = stack[-2];
    v_34260 = qcar(v_34259);
    goto v_34221;
v_34222:
    v_34259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34223;
v_34224:
    goto v_34220;
v_34221:
    goto v_34222;
v_34223:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-6];
    stack[0] = v_34259;
    goto v_34200;
    stack[0] = nil;
v_34200:
    goto v_34195;
v_34196:
    goto v_34233;
v_34229:
    v_34260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34230;
v_34231:
    v_34259 = stack[-1];
    v_34259 = qcar(v_34259);
    goto v_34232;
v_34233:
    goto v_34229;
v_34230:
    goto v_34231;
v_34232:
    v_34259 = cons(v_34260, v_34259);
    env = stack[-6];
    goto v_34197;
v_34198:
    goto v_34194;
v_34195:
    goto v_34196;
v_34197:
    fn = elt(env, 7); // multsq
    v_34260 = (*qfn2(fn))(fn, stack[0], v_34259);
    env = stack[-6];
    goto v_34189;
v_34190:
    v_34259 = stack[-5];
    goto v_34191;
v_34192:
    goto v_34188;
v_34189:
    goto v_34190;
v_34191:
    fn = elt(env, 7); // multsq
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    stack[-5] = v_34259;
    v_34259 = stack[-4];
    if (v_34259 == nil) goto v_34241;
    goto v_34248;
v_34244:
    stack[0] = stack[-5];
    goto v_34245;
v_34246:
    goto v_34255;
v_34251:
    v_34260 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_34252;
v_34253:
    v_34259 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_34254;
v_34255:
    goto v_34251;
v_34252:
    goto v_34253;
v_34254:
    fn = elt(env, 16); // mkrootsq
    v_34259 = (*qfn2(fn))(fn, v_34260, v_34259);
    env = stack[-6];
    goto v_34247;
v_34248:
    goto v_34244;
v_34245:
    goto v_34246;
v_34247:
    fn = elt(env, 7); // multsq
    v_34259 = (*qfn2(fn))(fn, stack[0], v_34259);
    stack[-5] = v_34259;
    goto v_34239;
v_34241:
v_34239:
    v_34259 = stack[-5];
    goto v_33958;
    v_34259 = nil;
v_33958:
    return onevalue(v_34259);
}



// Code for ev_max!#

static LispObject CC_ev_maxC(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33972, v_33973, v_33974, v_33975;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33973 = v_33955;
    v_33974 = v_33954;
// end of prologue
    goto v_33965;
v_33961:
    v_33975 = v_33974;
    goto v_33962;
v_33963:
    v_33972 = v_33973;
    goto v_33964;
v_33965:
    goto v_33961;
v_33962:
    goto v_33963;
v_33964:
    if (((intptr_t)(v_33975)) > ((intptr_t)(v_33972))) goto v_33959;
    else goto v_33960;
v_33959:
    v_33972 = v_33974;
    goto v_33958;
v_33960:
    v_33972 = v_33973;
    goto v_33958;
    v_33972 = nil;
v_33958:
    return onevalue(v_33972);
}



// Code for ps!:constmult!-erule

static LispObject CC_psTconstmultKerule(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33977, v_33978, v_33979;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33978 = v_33955;
    v_33979 = v_33954;
// end of prologue
    goto v_33962;
v_33958:
    v_33977 = v_33979;
    v_33977 = qcdr(v_33977);
    stack[0] = qcar(v_33977);
    goto v_33959;
v_33960:
    goto v_33971;
v_33967:
    v_33977 = v_33979;
    v_33977 = qcdr(v_33977);
    v_33977 = qcdr(v_33977);
    v_33977 = qcar(v_33977);
    goto v_33968;
v_33969:
    goto v_33970;
v_33971:
    goto v_33967;
v_33968:
    goto v_33969;
v_33970:
    fn = elt(env, 1); // ps!:evaluate
    v_33977 = (*qfn2(fn))(fn, v_33977, v_33978);
    env = stack[-1];
    goto v_33961;
v_33962:
    goto v_33958;
v_33959:
    goto v_33960;
v_33961:
    {
        LispObject v_33981 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_33981, v_33977);
    }
}



// Code for redpar

static LispObject CC_redpar(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34013, v_34014;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    stack[-2] = nil;
v_33962:
    v_34013 = stack[0];
    if (v_34013 == nil) goto v_33965;
    else goto v_33966;
v_33965:
    goto v_33961;
v_33966:
    goto v_33977;
v_33973:
    v_34013 = stack[0];
    v_34014 = qcar(v_34013);
    goto v_33974;
v_33975:
    v_34013 = stack[-1];
    goto v_33976;
v_33977:
    goto v_33973;
v_33974:
    goto v_33975;
v_33976:
    v_34013 = Lmember(nil, v_34014, v_34013);
    if (v_34013 == nil) goto v_33972;
    goto v_33987;
v_33983:
    v_34013 = stack[0];
    v_34014 = qcar(v_34013);
    goto v_33984;
v_33985:
    v_34013 = stack[-1];
    goto v_33986;
v_33987:
    goto v_33983;
v_33984:
    goto v_33985;
v_33986:
    v_34013 = Ldelete(nil, v_34014, v_34013);
    env = stack[-3];
    stack[-1] = v_34013;
    goto v_33970;
v_33972:
    goto v_33998;
v_33994:
    v_34013 = stack[0];
    v_34014 = qcar(v_34013);
    goto v_33995;
v_33996:
    v_34013 = stack[-2];
    goto v_33997;
v_33998:
    goto v_33994;
v_33995:
    goto v_33996;
v_33997:
    v_34013 = cons(v_34014, v_34013);
    env = stack[-3];
    stack[-2] = v_34013;
    goto v_33970;
v_33970:
    v_34013 = stack[0];
    v_34013 = qcdr(v_34013);
    stack[0] = v_34013;
    goto v_33962;
v_33961:
    goto v_34009;
v_34005:
    stack[0] = stack[-1];
    goto v_34006;
v_34007:
    v_34013 = stack[-2];
    v_34013 = Lreverse(nil, v_34013);
    goto v_34008;
v_34009:
    goto v_34005;
v_34006:
    goto v_34007;
v_34008:
    {
        LispObject v_34018 = stack[0];
        return list2(v_34018, v_34013);
    }
    return onevalue(v_34013);
}



// Code for remove_root_item

static LispObject CC_remove_root_item(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34025, v_34026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_33954;
// end of prologue
    v_34025 = stack[-1];
    v_34025 = qcdr(v_34025);
    v_34025 = qcar(v_34025);
    stack[-2] = v_34025;
    v_34025 = stack[-1];
    v_34025 = qcar(v_34025);
    stack[0] = v_34025;
    goto v_33970;
v_33966:
    v_34026 = stack[-1];
    goto v_33967;
v_33968:
    v_34025 = stack[-1];
    v_34025 = qcdr(v_34025);
    v_34025 = qcdr(v_34025);
    v_34025 = qcar(v_34025);
    goto v_33969;
v_33970:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    fn = elt(env, 1); // setcar
    v_34025 = (*qfn2(fn))(fn, v_34026, v_34025);
    env = stack[-3];
    goto v_33981;
v_33977:
    v_34026 = stack[-1];
    goto v_33978;
v_33979:
    v_34025 = stack[-1];
    v_34025 = qcdr(v_34025);
    v_34025 = qcdr(v_34025);
    v_34025 = qcdr(v_34025);
    goto v_33980;
v_33981:
    goto v_33977;
v_33978:
    goto v_33979;
v_33980:
    fn = elt(env, 2); // setcdr
    v_34025 = (*qfn2(fn))(fn, v_34026, v_34025);
    env = stack[-3];
    v_34025 = stack[-2];
    v_34025 = qcdr(v_34025);
    if (v_34025 == nil) goto v_33990;
v_33995:
    v_34025 = stack[-1];
    v_34025 = qcdr(v_34025);
    if (v_34025 == nil) goto v_33998;
    else goto v_33999;
v_33998:
    goto v_33994;
v_33999:
    v_34025 = stack[-1];
    v_34025 = qcdr(v_34025);
    v_34025 = qcar(v_34025);
    stack[-1] = v_34025;
    goto v_33995;
v_33994:
    goto v_34011;
v_34007:
    v_34026 = stack[-1];
    goto v_34008;
v_34009:
    v_34025 = stack[-2];
    v_34025 = qcar(v_34025);
    goto v_34010;
v_34011:
    goto v_34007;
v_34008:
    goto v_34009;
v_34010:
    fn = elt(env, 1); // setcar
    v_34025 = (*qfn2(fn))(fn, v_34026, v_34025);
    env = stack[-3];
    goto v_34020;
v_34016:
    v_34026 = stack[-1];
    goto v_34017;
v_34018:
    v_34025 = stack[-2];
    v_34025 = qcdr(v_34025);
    goto v_34019;
v_34020:
    goto v_34016;
v_34017:
    goto v_34018;
v_34019:
    fn = elt(env, 2); // setcdr
    v_34025 = (*qfn2(fn))(fn, v_34026, v_34025);
    goto v_33988;
v_33990:
v_33988:
    v_34025 = stack[0];
    return onevalue(v_34025);
}



// Code for bfdivide

static LispObject CC_bfdivide(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33984, v_33985, v_33986;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33985 = v_33955;
    v_33986 = v_33954;
// end of prologue
    v_33984 = v_33986;
    if (!consp(v_33984)) goto v_33959;
    else goto v_33960;
v_33959:
    goto v_33967;
v_33963:
    v_33984 = v_33986;
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    return quot2(v_33984, v_33985);
v_33960:
    goto v_33980;
v_33974:
    goto v_33975;
v_33976:
    goto v_33977;
v_33978:
    v_33984 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_33979;
v_33980:
    goto v_33974;
v_33975:
    goto v_33976;
v_33977:
    goto v_33978;
v_33979:
    fn = elt(env, 2); // divide!:
    v_33984 = (*qfnn(fn))(fn, 3, v_33986, v_33985, v_33984);
    env = stack[0];
    {
        fn = elt(env, 3); // normbf
        return (*qfn1(fn))(fn, v_33984);
    }
    v_33984 = nil;
    return onevalue(v_33984);
}



// Code for ext_edges

static LispObject CC_ext_edges(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34015, v_34016;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    stack[-1] = nil;
v_33959:
    v_34015 = stack[0];
    if (v_34015 == nil) goto v_33962;
    else goto v_33963;
v_33962:
    v_34015 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_34015);
    }
v_33963:
    goto v_33974;
v_33970:
    v_34015 = stack[0];
    v_34015 = qcar(v_34015);
    v_34016 = qcar(v_34015);
    goto v_33971;
v_33972:
    v_34015 = stack[0];
    v_34015 = qcdr(v_34015);
    goto v_33973;
v_33974:
    goto v_33970;
v_33971:
    goto v_33972;
v_33973:
    v_34015 = Lassoc(nil, v_34016, v_34015);
    if (v_34015 == nil) goto v_33969;
    else goto v_33967;
v_33969:
    goto v_33986;
v_33982:
    v_34015 = stack[0];
    v_34015 = qcar(v_34015);
    v_34016 = qcar(v_34015);
    goto v_33983;
v_33984:
    v_34015 = qvalue(elt(env, 1)); // !_0edge
    v_34015 = qcar(v_34015);
    goto v_33985;
v_33986:
    goto v_33982;
v_33983:
    goto v_33984;
v_33985:
    if (v_34016 == v_34015) goto v_33967;
    goto v_33968;
v_33967:
    goto v_33997;
v_33993:
    v_34015 = stack[0];
    v_34016 = qcar(v_34015);
    goto v_33994;
v_33995:
    v_34015 = stack[0];
    v_34015 = qcdr(v_34015);
    goto v_33996;
v_33997:
    goto v_33993;
v_33994:
    goto v_33995;
v_33996:
    fn = elt(env, 3); // delete_edge
    v_34015 = (*qfn2(fn))(fn, v_34016, v_34015);
    env = stack[-2];
    stack[0] = v_34015;
    goto v_33959;
v_33968:
    goto v_34009;
v_34005:
    v_34015 = stack[0];
    v_34016 = qcar(v_34015);
    goto v_34006;
v_34007:
    v_34015 = stack[-1];
    goto v_34008;
v_34009:
    goto v_34005;
v_34006:
    goto v_34007;
v_34008:
    v_34015 = cons(v_34016, v_34015);
    env = stack[-2];
    stack[-1] = v_34015;
    v_34015 = stack[0];
    v_34015 = qcdr(v_34015);
    stack[0] = v_34015;
    goto v_33959;
    v_34015 = nil;
    return onevalue(v_34015);
}



// Code for !*ex2sf

static LispObject CC_Hex2sf(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34012, v_34013;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_33954;
// end of prologue
    stack[-2] = nil;
v_33959:
    v_34012 = stack[-1];
    if (v_34012 == nil) goto v_33962;
    else goto v_33963;
v_33962:
    v_34012 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_34012);
    }
v_33963:
    v_34012 = stack[-1];
    v_34012 = qcar(v_34012);
    v_34012 = qcar(v_34012);
    v_34012 = qcar(v_34012);
    if (v_34012 == nil) goto v_33967;
    else goto v_33968;
v_33967:
    goto v_33978;
v_33974:
    stack[0] = stack[-2];
    goto v_33975;
v_33976:
    v_34012 = stack[-1];
    v_34012 = qcar(v_34012);
    v_34012 = qcdr(v_34012);
    fn = elt(env, 2); // subs2chk
    v_34012 = (*qfn1(fn))(fn, v_34012);
    env = stack[-3];
    goto v_33977;
v_33978:
    goto v_33974;
v_33975:
    goto v_33976;
v_33977:
    {
        LispObject v_34017 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34017, v_34012);
    }
v_33968:
    goto v_33993;
v_33987:
    goto v_33999;
v_33995:
    v_34012 = stack[-1];
    v_34012 = qcar(v_34012);
    v_34012 = qcar(v_34012);
    v_34013 = qcar(v_34012);
    goto v_33996;
v_33997:
    v_34012 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33998;
v_33999:
    goto v_33995;
v_33996:
    goto v_33997;
v_33998:
    fn = elt(env, 3); // to
    stack[0] = (*qfn2(fn))(fn, v_34013, v_34012);
    env = stack[-3];
    goto v_33988;
v_33989:
    v_34012 = stack[-1];
    v_34012 = qcar(v_34012);
    v_34012 = qcdr(v_34012);
    fn = elt(env, 2); // subs2chk
    v_34013 = (*qfn1(fn))(fn, v_34012);
    env = stack[-3];
    goto v_33990;
v_33991:
    v_34012 = stack[-2];
    goto v_33992;
v_33993:
    goto v_33987;
v_33988:
    goto v_33989;
v_33990:
    goto v_33991;
v_33992:
    v_34012 = acons(stack[0], v_34013, v_34012);
    env = stack[-3];
    stack[-2] = v_34012;
    v_34012 = stack[-1];
    v_34012 = qcdr(v_34012);
    stack[-1] = v_34012;
    goto v_33959;
    v_34012 = nil;
    return onevalue(v_34012);
}



// Code for lf!=tovarlessp

static LispObject CC_lfMtovarlessp(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33972, v_33973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
// copy arguments values to proper place
    v_33972 = v_33955;
    v_33973 = v_33954;
// end of prologue
    goto v_33961;
v_33957:
    goto v_33967;
v_33963:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    fn = elt(env, 1); // mo_compare
    v_33973 = (*qfn2(fn))(fn, v_33973, v_33972);
    goto v_33958;
v_33959:
    v_33972 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33960;
v_33961:
    goto v_33957;
v_33958:
    goto v_33959;
v_33960:
    v_33972 = (v_33973 == v_33972 ? lisp_true : nil);
    return onevalue(v_33972);
}



// Code for boolean!-eval2

static LispObject CC_booleanKeval2(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34105, v_34106, v_34107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
v_33958:
    goto v_33968;
v_33964:
    v_34106 = stack[0];
    goto v_33965;
v_33966:
    v_34105 = elt(env, 1); // boolean
    goto v_33967;
v_33968:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    if (!consp(v_34106)) goto v_33962;
    v_34106 = qcar(v_34106);
    if (v_34106 == v_34105) goto v_33961;
    else goto v_33962;
v_33961:
    v_34105 = stack[0];
    v_34105 = qcdr(v_34105);
    v_34105 = qcar(v_34105);
    stack[0] = v_34105;
    goto v_33958;
v_33962:
    goto v_33985;
v_33981:
    v_34106 = stack[0];
    goto v_33982;
v_33983:
    v_34105 = elt(env, 2); // and
    goto v_33984;
v_33985:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    if (!consp(v_34106)) goto v_33979;
    v_34106 = qcar(v_34106);
    if (v_34106 == v_34105) goto v_33978;
    else goto v_33979;
v_33978:
    v_34105 = lisp_true;
    goto v_33977;
v_33979:
    goto v_34000;
v_33996:
    v_34106 = stack[0];
    goto v_33997;
v_33998:
    v_34105 = elt(env, 3); // or
    goto v_33999;
v_34000:
    goto v_33996;
v_33997:
    goto v_33998;
v_33999:
    if (!consp(v_34106)) goto v_33994;
    v_34106 = qcar(v_34106);
    if (v_34106 == v_34105) goto v_33993;
    else goto v_33994;
v_33993:
    v_34105 = lisp_true;
    goto v_33992;
v_33994:
    goto v_34011;
v_34007:
    v_34106 = stack[0];
    goto v_34008;
v_34009:
    v_34105 = elt(env, 4); // not
    goto v_34010;
v_34011:
    goto v_34007;
v_34008:
    goto v_34009;
v_34010:
    v_34105 = Leqcar(nil, v_34106, v_34105);
    env = stack[-5];
    goto v_33992;
    v_34105 = nil;
v_33992:
    goto v_33977;
    v_34105 = nil;
v_33977:
    if (v_34105 == nil) goto v_33975;
    goto v_34019;
v_34015:
    v_34105 = stack[0];
    stack[-4] = qcar(v_34105);
    goto v_34016;
v_34017:
    v_34105 = stack[0];
    v_34105 = qcdr(v_34105);
    stack[-3] = v_34105;
    v_34105 = stack[-3];
    if (v_34105 == nil) goto v_34032;
    else goto v_34033;
v_34032:
    v_34105 = nil;
    goto v_34026;
v_34033:
    v_34105 = stack[-3];
    v_34105 = qcar(v_34105);
    v_34105 = CC_booleanKeval2(elt(env, 0), v_34105);
    env = stack[-5];
    v_34105 = ncons(v_34105);
    env = stack[-5];
    stack[-1] = v_34105;
    stack[-2] = v_34105;
v_34027:
    v_34105 = stack[-3];
    v_34105 = qcdr(v_34105);
    stack[-3] = v_34105;
    v_34105 = stack[-3];
    if (v_34105 == nil) goto v_34046;
    else goto v_34047;
v_34046:
    v_34105 = stack[-2];
    goto v_34026;
v_34047:
    goto v_34055;
v_34051:
    stack[0] = stack[-1];
    goto v_34052;
v_34053:
    v_34105 = stack[-3];
    v_34105 = qcar(v_34105);
    v_34105 = CC_booleanKeval2(elt(env, 0), v_34105);
    env = stack[-5];
    v_34105 = ncons(v_34105);
    env = stack[-5];
    goto v_34054;
v_34055:
    goto v_34051;
v_34052:
    goto v_34053;
v_34054:
    v_34105 = Lrplacd(nil, stack[0], v_34105);
    env = stack[-5];
    v_34105 = stack[-1];
    v_34105 = qcdr(v_34105);
    stack[-1] = v_34105;
    goto v_34027;
v_34026:
    goto v_34018;
v_34019:
    goto v_34015;
v_34016:
    goto v_34017;
v_34018:
    {
        LispObject v_34113 = stack[-4];
        return cons(v_34113, v_34105);
    }
v_33975:
    v_34105 = lisp_true;
// Binding !*protfg
// FLUIDBIND: reloadenv=5 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 5, -1);
    qvalue(elt(env, 5)) = v_34105; // !*protfg
    goto v_34078;
v_34072:
    goto v_34086;
v_34080:
    v_34107 = stack[0];
    goto v_34081;
v_34082:
    v_34106 = nil;
    goto v_34083;
v_34084:
    v_34105 = elt(env, 6); // algebraic
    goto v_34085;
v_34086:
    goto v_34080;
v_34081:
    goto v_34082;
v_34083:
    goto v_34084;
v_34085:
    fn = elt(env, 9); // formbool
    v_34107 = (*qfnn(fn))(fn, 3, v_34107, v_34106, v_34105);
    env = stack[-5];
    goto v_34073;
v_34074:
    v_34106 = nil;
    goto v_34075;
v_34076:
    v_34105 = nil;
    goto v_34077;
v_34078:
    goto v_34072;
v_34073:
    goto v_34074;
v_34075:
    goto v_34076;
v_34077:
    fn = elt(env, 10); // errorset
    v_34105 = (*qfnn(fn))(fn, 3, v_34107, v_34106, v_34105);
    env = stack[-5];
    stack[-2] = v_34105;
    ;}  // end of a binding scope
    v_34105 = stack[-2];
    fn = elt(env, 11); // errorp
    v_34105 = (*qfn1(fn))(fn, v_34105);
    env = stack[-5];
    if (v_34105 == nil) goto v_34095;
    v_34105 = lisp_true;
    qvalue(elt(env, 7)) = v_34105; // bool!-break!*
    v_34105 = nil;
    qvalue(elt(env, 8)) = v_34105; // erfg!*
    v_34105 = stack[0];
    goto v_34093;
v_34095:
    v_34105 = stack[-2];
    v_34105 = qcar(v_34105);
    goto v_34093;
    v_34105 = nil;
v_34093:
    goto v_33957;
    v_34105 = nil;
v_33957:
    return onevalue(v_34105);
}



// Code for sqlessp

static LispObject CC_sqlessp(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33978, v_33979;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33978 = v_33955;
    v_33979 = v_33954;
// end of prologue
    goto v_33962;
v_33958:
    stack[0] = v_33979;
    goto v_33959;
v_33960:
    fn = elt(env, 1); // negsq
    v_33978 = (*qfn1(fn))(fn, v_33978);
    env = stack[-1];
    goto v_33961;
v_33962:
    goto v_33958;
v_33959:
    goto v_33960;
v_33961:
    fn = elt(env, 2); // addsq
    v_33978 = (*qfn2(fn))(fn, stack[0], v_33978);
    env = stack[-1];
    v_33978 = qcar(v_33978);
    v_33979 = v_33978;
    v_33978 = v_33979;
    if (v_33978 == nil) goto v_33970;
    else goto v_33971;
v_33970:
    v_33978 = nil;
    goto v_33969;
v_33971:
    v_33978 = v_33979;
    {
        fn = elt(env, 3); // !:minusp
        return (*qfn1(fn))(fn, v_33978);
    }
    v_33978 = nil;
v_33969:
    return onevalue(v_33978);
}



// Code for crn!:zerop

static LispObject CC_crnTzerop(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33984, v_33985, v_33986;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33985 = v_33954;
// end of prologue
    goto v_33964;
v_33960:
    v_33984 = v_33985;
    v_33984 = qcdr(v_33984);
    v_33984 = qcar(v_33984);
    v_33986 = qcar(v_33984);
    goto v_33961;
v_33962:
    v_33984 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33963;
v_33964:
    goto v_33960;
v_33961:
    goto v_33962;
v_33963:
    if (v_33986 == v_33984) goto v_33958;
    else goto v_33959;
v_33958:
    goto v_33974;
v_33970:
    v_33984 = v_33985;
    v_33984 = qcdr(v_33984);
    v_33984 = qcdr(v_33984);
    v_33985 = qcar(v_33984);
    goto v_33971;
v_33972:
    v_33984 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33973;
v_33974:
    goto v_33970;
v_33971:
    goto v_33972;
v_33973:
    v_33984 = (v_33985 == v_33984 ? lisp_true : nil);
    goto v_33957;
v_33959:
    v_33984 = nil;
    goto v_33957;
    v_33984 = nil;
v_33957:
    return onevalue(v_33984);
}



// Code for mkg1

static LispObject CC_mkg1(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33995, v_33996, v_33997, v_33998;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33996 = v_33955;
    v_33997 = v_33954;
// end of prologue
    goto v_33966;
v_33962:
    v_33998 = v_33996;
    goto v_33963;
v_33964:
    v_33995 = elt(env, 1); // nospur
    goto v_33965;
v_33966:
    goto v_33962;
v_33963:
    goto v_33964;
v_33965:
    v_33995 = Lflagp(nil, v_33998, v_33995);
    env = stack[0];
    if (v_33995 == nil) goto v_33959;
    else goto v_33960;
v_33959:
    goto v_33977;
v_33971:
    v_33995 = elt(env, 2); // g
    goto v_33972;
v_33973:
    goto v_33974;
v_33975:
    goto v_33976;
v_33977:
    goto v_33971;
v_33972:
    goto v_33973;
v_33974:
    goto v_33975;
v_33976:
    v_33995 = list2star(v_33995, v_33996, v_33997);
    env = stack[0];
    {
        fn = elt(env, 3); // mksf
        return (*qfn1(fn))(fn, v_33995);
    }
v_33960:
    goto v_33991;
v_33985:
    v_33995 = elt(env, 2); // g
    goto v_33986;
v_33987:
    goto v_33988;
v_33989:
    goto v_33990;
v_33991:
    goto v_33985;
v_33986:
    goto v_33987;
v_33988:
    goto v_33989;
v_33990:
    v_33995 = list2star(v_33995, v_33996, v_33997);
    env = stack[0];
    {
        fn = elt(env, 3); // mksf
        return (*qfn1(fn))(fn, v_33995);
    }
    v_33995 = nil;
    return onevalue(v_33995);
}



// Code for uniquifyf

static LispObject CC_uniquifyf(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33954;
// end of prologue
    v_34005 = stack[0];
    if (!consp(v_34005)) goto v_33964;
    else goto v_33965;
v_33964:
    v_34005 = lisp_true;
    goto v_33963;
v_33965:
    v_34005 = stack[0];
    v_34005 = qcar(v_34005);
    v_34005 = (consp(v_34005) ? nil : lisp_true);
    goto v_33963;
    v_34005 = nil;
v_33963:
    if (v_34005 == nil) goto v_33961;
    v_34005 = nil;
    goto v_33957;
v_33961:
    v_34005 = stack[0];
    v_34005 = qcar(v_34005);
    v_34005 = qcar(v_34005);
    v_34005 = qcar(v_34005);
    if (!consp(v_34005)) goto v_33974;
    else goto v_33975;
v_33974:
    goto v_33959;
v_33975:
    goto v_33988;
v_33984:
    v_34005 = stack[0];
    v_34005 = qcar(v_34005);
    stack[-1] = qcar(v_34005);
    goto v_33985;
v_33986:
    v_34005 = stack[0];
    v_34005 = qcar(v_34005);
    v_34005 = qcar(v_34005);
    v_34005 = qcar(v_34005);
    fn = elt(env, 1); // uniquifyk
    v_34005 = (*qfn1(fn))(fn, v_34005);
    env = stack[-2];
    goto v_33987;
v_33988:
    goto v_33984;
v_33985:
    goto v_33986;
v_33987:
    v_34005 = Lrplaca(nil, stack[-1], v_34005);
    env = stack[-2];
    goto v_33959;
v_33959:
    v_34005 = stack[0];
    v_34005 = qcar(v_34005);
    v_34005 = qcdr(v_34005);
    v_34005 = CC_uniquifyf(elt(env, 0), v_34005);
    env = stack[-2];
    v_34005 = stack[0];
    v_34005 = qcdr(v_34005);
    v_34005 = CC_uniquifyf(elt(env, 0), v_34005);
    v_34005 = stack[0];
v_33957:
    return onevalue(v_34005);
}



// Code for generate_multiindex

static LispObject CC_generate_multiindex(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34042, v_34043;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_33954;
// end of prologue
    v_34042 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_34042;
    goto v_33973;
v_33969:
    v_34043 = qvalue(elt(env, 1)); // n_indep_var
    goto v_33970;
v_33971:
    v_34042 = stack[-6];
    goto v_33972;
v_33973:
    goto v_33969;
v_33970:
    goto v_33971;
v_33972:
    v_34042 = difference2(v_34043, v_34042);
    env = stack[-7];
    v_34042 = Lminusp(nil, v_34042);
    env = stack[-7];
    if (v_34042 == nil) goto v_33966;
    v_34042 = nil;
    goto v_33960;
v_33966:
    goto v_33985;
v_33979:
    stack[-1] = stack[-5];
    goto v_33980;
v_33981:
    stack[0] = stack[-6];
    goto v_33982;
v_33983:
    goto v_33994;
v_33990:
    v_34043 = stack[-5];
    goto v_33991;
v_33992:
    v_34042 = stack[-6];
    goto v_33993;
v_33994:
    goto v_33990;
v_33991:
    goto v_33992;
v_33993:
    fn = elt(env, 2); // nth
    v_34042 = (*qfn2(fn))(fn, v_34043, v_34042);
    env = stack[-7];
    v_34042 = add1(v_34042);
    env = stack[-7];
    goto v_33984;
v_33985:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    fn = elt(env, 3); // cde_replace_nth
    v_34042 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34042);
    env = stack[-7];
    v_34042 = ncons(v_34042);
    env = stack[-7];
    stack[-3] = v_34042;
    stack[-4] = v_34042;
v_33961:
    v_34042 = stack[-6];
    v_34042 = add1(v_34042);
    env = stack[-7];
    stack[-6] = v_34042;
    goto v_34009;
v_34005:
    v_34043 = qvalue(elt(env, 1)); // n_indep_var
    goto v_34006;
v_34007:
    v_34042 = stack[-6];
    goto v_34008;
v_34009:
    goto v_34005;
v_34006:
    goto v_34007;
v_34008:
    v_34042 = difference2(v_34043, v_34042);
    env = stack[-7];
    v_34042 = Lminusp(nil, v_34042);
    env = stack[-7];
    if (v_34042 == nil) goto v_34002;
    v_34042 = stack[-4];
    goto v_33960;
v_34002:
    goto v_34018;
v_34014:
    stack[-2] = stack[-3];
    goto v_34015;
v_34016:
    goto v_34028;
v_34022:
    stack[-1] = stack[-5];
    goto v_34023;
v_34024:
    stack[0] = stack[-6];
    goto v_34025;
v_34026:
    goto v_34037;
v_34033:
    v_34043 = stack[-5];
    goto v_34034;
v_34035:
    v_34042 = stack[-6];
    goto v_34036;
v_34037:
    goto v_34033;
v_34034:
    goto v_34035;
v_34036:
    fn = elt(env, 2); // nth
    v_34042 = (*qfn2(fn))(fn, v_34043, v_34042);
    env = stack[-7];
    v_34042 = add1(v_34042);
    env = stack[-7];
    goto v_34027;
v_34028:
    goto v_34022;
v_34023:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    fn = elt(env, 3); // cde_replace_nth
    v_34042 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34042);
    env = stack[-7];
    v_34042 = ncons(v_34042);
    env = stack[-7];
    goto v_34017;
v_34018:
    goto v_34014;
v_34015:
    goto v_34016;
v_34017:
    v_34042 = Lrplacd(nil, stack[-2], v_34042);
    env = stack[-7];
    v_34042 = stack[-3];
    v_34042 = qcdr(v_34042);
    stack[-3] = v_34042;
    goto v_33961;
v_33960:
    return onevalue(v_34042);
}



// Code for gd_applyscheme

static LispObject CC_gd_applyscheme(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34016, v_34017, v_34018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_33955;
    stack[-3] = v_33954;
// end of prologue
    stack[-4] = nil;
    v_34016 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_34016;
    v_34016 = stack[-2];
    stack[0] = v_34016;
v_33965:
    v_34016 = stack[0];
    if (v_34016 == nil) goto v_33969;
    else goto v_33970;
v_33969:
    goto v_33964;
v_33970:
    v_34016 = stack[-1];
    v_34016 = add1(v_34016);
    env = stack[-5];
    stack[-1] = v_34016;
    goto v_33985;
v_33979:
    goto v_33991;
v_33987:
    v_34017 = elt(env, 1); // a
    goto v_33988;
v_33989:
    v_34016 = stack[-1];
    goto v_33990;
v_33991:
    goto v_33987;
v_33988:
    goto v_33989;
v_33990:
    fn = elt(env, 2); // mkid
    v_34018 = (*qfn2(fn))(fn, v_34017, v_34016);
    env = stack[-5];
    goto v_33980;
v_33981:
    v_34016 = stack[-2];
    v_34017 = qcar(v_34016);
    goto v_33982;
v_33983:
    v_34016 = stack[-4];
    goto v_33984;
v_33985:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    v_34016 = acons(v_34018, v_34017, v_34016);
    env = stack[-5];
    stack[-4] = v_34016;
    v_34016 = stack[-2];
    v_34016 = qcdr(v_34016);
    stack[-2] = v_34016;
    v_34016 = stack[0];
    v_34016 = qcdr(v_34016);
    stack[0] = v_34016;
    goto v_33965;
v_33964:
    goto v_34006;
v_34002:
    stack[0] = stack[-4];
    goto v_34003;
v_34004:
    goto v_34013;
v_34009:
    v_34017 = stack[-3];
    goto v_34010;
v_34011:
    v_34016 = stack[-1];
    goto v_34012;
v_34013:
    goto v_34009;
v_34010:
    goto v_34011;
v_34012:
    fn = elt(env, 3); // gd_getscheme
    v_34016 = (*qfn2(fn))(fn, v_34017, v_34016);
    goto v_34005;
v_34006:
    goto v_34002;
v_34003:
    goto v_34004;
v_34005:
    {
        LispObject v_34024 = stack[0];
        return Lsublis(nil, v_34024, v_34016);
    }
    return onevalue(v_34016);
}



// Code for get_rep_of_generator

static LispObject CC_get_rep_of_generator(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34038, v_34039, v_34040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_34040 = v_33955;
    stack[-2] = v_33954;
// end of prologue
    stack[-1] = nil;
    goto v_33970;
v_33966:
    v_34039 = stack[-2];
    goto v_33967;
v_33968:
    v_34038 = elt(env, 1); // id
    goto v_33969;
v_33970:
    goto v_33966;
v_33967:
    goto v_33968;
v_33969:
    if (v_34039 == v_34038) goto v_33964;
    else goto v_33965;
v_33964:
    v_34038 = v_34040;
    v_34038 = qcar(v_34038);
    v_34038 = qcdr(v_34038);
    v_34038 = qcar(v_34038);
    fn = elt(env, 3); // get!+row!+nr
    v_34038 = (*qfn1(fn))(fn, v_34038);
    env = stack[-4];
    {
        fn = elt(env, 4); // mk!+unit!+mat
        return (*qfn1(fn))(fn, v_34038);
    }
v_33965:
    v_34038 = nil;
    stack[-3] = v_34038;
    v_34038 = v_34040;
    stack[0] = v_34038;
v_33983:
    v_34038 = stack[-3];
    if (v_34038 == nil) goto v_33990;
    else goto v_33991;
v_33990:
    goto v_33998;
v_33994:
    v_34038 = stack[0];
    v_34039 = Llength(nil, v_34038);
    env = stack[-4];
    goto v_33995;
v_33996:
    v_34038 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33997;
v_33998:
    goto v_33994;
v_33995:
    goto v_33996;
v_33997:
    v_34038 = (LispObject)greaterp2(v_34039, v_34038);
    v_34038 = v_34038 ? lisp_true : nil;
    env = stack[-4];
    goto v_33989;
v_33991:
    v_34038 = nil;
    goto v_33989;
    v_34038 = nil;
v_33989:
    if (v_34038 == nil) goto v_33986;
    else goto v_33987;
v_33986:
    goto v_33982;
v_33987:
    goto v_34014;
v_34010:
    v_34038 = stack[0];
    v_34038 = qcar(v_34038);
    v_34039 = qcar(v_34038);
    goto v_34011;
v_34012:
    v_34038 = stack[-2];
    goto v_34013;
v_34014:
    goto v_34010;
v_34011:
    goto v_34012;
v_34013:
    if (equal(v_34039, v_34038)) goto v_34008;
    else goto v_34009;
v_34008:
    v_34038 = lisp_true;
    stack[-3] = v_34038;
    v_34038 = stack[0];
    v_34038 = qcar(v_34038);
    v_34038 = qcdr(v_34038);
    v_34038 = qcar(v_34038);
    stack[-1] = v_34038;
    goto v_34007;
v_34009:
v_34007:
    v_34038 = stack[0];
    v_34038 = qcdr(v_34038);
    stack[0] = v_34038;
    goto v_33983;
v_33982:
    v_34038 = stack[-3];
    if (v_34038 == nil) goto v_34031;
    v_34038 = stack[-1];
    goto v_33961;
v_34031:
    v_34038 = elt(env, 2); // " error in get rep of generators"
    fn = elt(env, 5); // rederr
    v_34038 = (*qfn1(fn))(fn, v_34038);
    goto v_34029;
v_34029:
    v_34038 = nil;
v_33961:
    return onevalue(v_34038);
}



// Code for talp_try3

static LispObject CC_talp_try3(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34258, v_34259, v_34260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-11] = v_33955;
    stack[0] = v_33954;
// end of prologue
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    goto v_33983;
v_33979:
    v_34259 = stack[0];
    goto v_33980;
v_33981:
    v_34258 = elt(env, 1); // true
    goto v_33982;
v_33983:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    if (v_34259 == v_34258) goto v_33977;
    else goto v_33978;
v_33977:
    v_34258 = lisp_true;
    goto v_33976;
v_33978:
    goto v_33993;
v_33989:
    v_34259 = stack[0];
    goto v_33990;
v_33991:
    v_34258 = elt(env, 2); // false
    goto v_33992;
v_33993:
    goto v_33989;
v_33990:
    goto v_33991;
v_33992:
    v_34258 = (v_34259 == v_34258 ? lisp_true : nil);
    goto v_33976;
    v_34258 = nil;
v_33976:
    if (v_34258 == nil) goto v_33974;
    v_34258 = lisp_true;
    goto v_33972;
v_33974:
    v_34258 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_33972;
    v_34258 = nil;
v_33972:
    if (v_34258 == nil) goto v_33970;
    v_34258 = stack[0];
    goto v_33966;
v_33970:
    v_34258 = stack[0];
    stack[-12] = v_34258;
    goto v_34012;
v_34008:
    v_34258 = stack[-12];
    if (!consp(v_34258)) goto v_34015;
    else goto v_34016;
v_34015:
    v_34258 = stack[-12];
    v_34259 = v_34258;
    goto v_34014;
v_34016:
    v_34258 = stack[-12];
    v_34258 = qcar(v_34258);
    v_34259 = v_34258;
    goto v_34014;
    v_34259 = nil;
v_34014:
    goto v_34009;
v_34010:
    v_34258 = elt(env, 3); // and
    goto v_34011;
v_34012:
    goto v_34008;
v_34009:
    goto v_34010;
v_34011:
    if (v_34259 == v_34258) goto v_34006;
    else goto v_34007;
v_34006:
    v_34258 = stack[-12];
    fn = elt(env, 6); // talp_argl
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    stack[-4] = v_34258;
v_34027:
    v_34258 = stack[-4];
    if (v_34258 == nil) goto v_34032;
    else goto v_34033;
v_34032:
    goto v_34026;
v_34033:
    v_34258 = stack[-4];
    v_34258 = qcar(v_34258);
    stack[-3] = v_34258;
    v_34258 = stack[-3];
    if (!consp(v_34258)) goto v_34046;
    goto v_34052;
v_34048:
    v_34258 = stack[-3];
    fn = elt(env, 7); // talp_op
    v_34259 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34049;
v_34050:
    v_34258 = elt(env, 4); // equal
    goto v_34051;
v_34052:
    goto v_34048;
v_34049:
    goto v_34050;
v_34051:
    v_34258 = (v_34259 == v_34258 ? lisp_true : nil);
    goto v_34044;
v_34046:
    v_34258 = nil;
    goto v_34044;
    v_34258 = nil;
v_34044:
    if (v_34258 == nil) goto v_34042;
    v_34258 = stack[-3];
    fn = elt(env, 8); // talp_arg2l
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    stack[-6] = v_34258;
    v_34258 = stack[-3];
    fn = elt(env, 9); // talp_arg2r
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    stack[-5] = v_34258;
    v_34258 = stack[-11];
    stack[-2] = v_34258;
v_34067:
    v_34258 = stack[-2];
    if (v_34258 == nil) goto v_34071;
    else goto v_34072;
v_34071:
    goto v_34066;
v_34072:
    v_34258 = stack[-2];
    v_34258 = qcar(v_34258);
    stack[-1] = v_34258;
    v_34258 = stack[-6];
    if (!consp(v_34258)) goto v_34085;
    else goto v_34086;
v_34085:
    goto v_34093;
v_34089:
    v_34259 = stack[-5];
    goto v_34090;
v_34091:
    v_34258 = stack[-1];
    goto v_34092;
v_34093:
    goto v_34089;
v_34090:
    goto v_34091;
v_34092:
    fn = elt(env, 10); // talp_contains
    v_34258 = (*qfn2(fn))(fn, v_34259, v_34258);
    env = stack[-13];
    goto v_34084;
v_34086:
    v_34258 = nil;
    goto v_34084;
    v_34258 = nil;
v_34084:
    if (v_34258 == nil) goto v_34082;
    else goto v_34080;
v_34082:
    goto v_34105;
v_34101:
    v_34258 = stack[-6];
    fn = elt(env, 11); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34102;
v_34103:
    v_34258 = stack[-5];
    fn = elt(env, 11); // talp_td
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34104;
v_34105:
    goto v_34101;
v_34102:
    goto v_34103;
v_34104:
    v_34258 = (LispObject)lessp2(stack[0], v_34258);
    v_34258 = v_34258 ? lisp_true : nil;
    env = stack[-13];
    if (v_34258 == nil) goto v_34099;
    else goto v_34080;
v_34099:
    goto v_34081;
v_34080:
    v_34258 = lisp_true;
    stack[-7] = v_34258;
    goto v_34079;
v_34081:
v_34079:
    v_34258 = stack[-5];
    if (!consp(v_34258)) goto v_34118;
    else goto v_34119;
v_34118:
    goto v_34126;
v_34122:
    v_34259 = stack[-6];
    goto v_34123;
v_34124:
    v_34258 = stack[-1];
    goto v_34125;
v_34126:
    goto v_34122;
v_34123:
    goto v_34124;
v_34125:
    fn = elt(env, 10); // talp_contains
    v_34258 = (*qfn2(fn))(fn, v_34259, v_34258);
    env = stack[-13];
    goto v_34117;
v_34119:
    v_34258 = nil;
    goto v_34117;
    v_34258 = nil;
v_34117:
    if (v_34258 == nil) goto v_34115;
    else goto v_34113;
v_34115:
    goto v_34138;
v_34134:
    v_34258 = stack[-5];
    fn = elt(env, 11); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34135;
v_34136:
    v_34258 = stack[-6];
    fn = elt(env, 11); // talp_td
    v_34258 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34137;
v_34138:
    goto v_34134;
v_34135:
    goto v_34136;
v_34137:
    v_34258 = (LispObject)lessp2(stack[0], v_34258);
    v_34258 = v_34258 ? lisp_true : nil;
    env = stack[-13];
    if (v_34258 == nil) goto v_34132;
    else goto v_34113;
v_34132:
    goto v_34114;
v_34113:
    v_34258 = lisp_true;
    stack[-8] = v_34258;
    goto v_34112;
v_34114:
v_34112:
    v_34258 = stack[-2];
    v_34258 = qcdr(v_34258);
    stack[-2] = v_34258;
    goto v_34067;
v_34066:
    v_34258 = stack[-8];
    if (v_34258 == nil) goto v_34149;
    goto v_34156;
v_34152:
    v_34259 = stack[-3];
    goto v_34153;
v_34154:
    v_34258 = stack[-9];
    goto v_34155;
v_34156:
    goto v_34152;
v_34153:
    goto v_34154;
v_34155:
    v_34258 = cons(v_34259, v_34258);
    env = stack[-13];
    stack[-9] = v_34258;
    goto v_34166;
v_34160:
    v_34258 = stack[-3];
    fn = elt(env, 8); // talp_arg2l
    stack[0] = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34161;
v_34162:
    v_34258 = stack[-3];
    fn = elt(env, 9); // talp_arg2r
    v_34259 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34163;
v_34164:
    v_34258 = stack[-10];
    goto v_34165;
v_34166:
    goto v_34160;
v_34161:
    goto v_34162;
v_34163:
    goto v_34164;
v_34165:
    v_34258 = acons(stack[0], v_34259, v_34258);
    env = stack[-13];
    stack[-10] = v_34258;
    goto v_34147;
v_34149:
v_34147:
    v_34258 = stack[-7];
    if (v_34258 == nil) goto v_34175;
    goto v_34182;
v_34178:
    v_34259 = stack[-3];
    goto v_34179;
v_34180:
    v_34258 = stack[-9];
    goto v_34181;
v_34182:
    goto v_34178;
v_34179:
    goto v_34180;
v_34181:
    v_34258 = cons(v_34259, v_34258);
    env = stack[-13];
    stack[-9] = v_34258;
    goto v_34192;
v_34186:
    v_34258 = stack[-3];
    fn = elt(env, 9); // talp_arg2r
    stack[0] = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34187;
v_34188:
    v_34258 = stack[-3];
    fn = elt(env, 8); // talp_arg2l
    v_34259 = (*qfn1(fn))(fn, v_34258);
    env = stack[-13];
    goto v_34189;
v_34190:
    v_34258 = stack[-10];
    goto v_34191;
v_34192:
    goto v_34186;
v_34187:
    goto v_34188;
v_34189:
    goto v_34190;
v_34191:
    v_34258 = acons(stack[0], v_34259, v_34258);
    env = stack[-13];
    stack[-10] = v_34258;
    goto v_34173;
v_34175:
v_34173:
    v_34258 = nil;
    stack[-8] = v_34258;
    v_34258 = nil;
    stack[-7] = v_34258;
    goto v_34040;
v_34042:
v_34040:
    v_34258 = stack[-4];
    v_34258 = qcdr(v_34258);
    stack[-4] = v_34258;
    goto v_34027;
v_34026:
    goto v_34005;
v_34007:
v_34005:
    v_34258 = stack[-10];
    if (v_34258 == nil) goto v_34206;
    goto v_34215;
v_34209:
    v_34260 = stack[-10];
    goto v_34210;
v_34211:
    v_34259 = stack[-9];
    goto v_34212;
v_34213:
    v_34258 = stack[-11];
    goto v_34214;
v_34215:
    goto v_34209;
v_34210:
    goto v_34211;
v_34212:
    goto v_34213;
v_34214:
    fn = elt(env, 12); // talp_extlftrs
    v_34258 = (*qfnn(fn))(fn, 3, v_34260, v_34259, v_34258);
    env = stack[-13];
    v_34259 = v_34258;
    v_34258 = v_34259;
    v_34258 = qcar(v_34258);
    stack[-10] = v_34258;
    v_34258 = v_34259;
    v_34258 = qcdr(v_34258);
    stack[-9] = v_34258;
    goto v_34204;
v_34206:
v_34204:
    v_34258 = stack[-10];
    if (v_34258 == nil) goto v_34227;
    goto v_34236;
v_34230:
    v_34260 = stack[-12];
    goto v_34231;
v_34232:
    v_34259 = stack[-10];
    goto v_34233;
v_34234:
    v_34258 = stack[-9];
    goto v_34235;
v_34236:
    goto v_34230;
v_34231:
    goto v_34232;
v_34233:
    goto v_34234;
v_34235:
    fn = elt(env, 13); // talp_chsbstres
    v_34258 = (*qfnn(fn))(fn, 3, v_34260, v_34259, v_34258);
    env = stack[-13];
    v_34259 = v_34258;
    v_34258 = v_34259;
    v_34258 = qcdr(v_34258);
    if (v_34258 == nil) goto v_34244;
    v_34258 = v_34259;
    v_34258 = qcar(v_34258);
    {
        fn = elt(env, 14); // talp_try1
        return (*qfn1(fn))(fn, v_34258);
    }
v_34244:
    v_34258 = v_34259;
    v_34258 = qcar(v_34258);
    goto v_34242;
    v_34258 = nil;
v_34242:
    goto v_34225;
v_34227:
    v_34258 = stack[-12];
    {
        fn = elt(env, 15); // talp_rnf
        return (*qfn1(fn))(fn, v_34258);
    }
    v_34258 = nil;
v_34225:
v_33966:
    return onevalue(v_34258);
}



// Code for implicitdec

static LispObject CC_implicitdec(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_34022, v_34023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_33954;
// end of prologue
    v_34022 = nil;
    stack[0] = v_34022;
    goto v_33966;
v_33962:
    v_34023 = nil;
    goto v_33963;
v_33964:
    v_34022 = elt(env, 1); // !*decs!*
    goto v_33965;
v_33966:
    goto v_33962;
v_33963:
    goto v_33964;
v_33965:
    fn = elt(env, 2); // symtabget
    v_34022 = (*qfn2(fn))(fn, v_34023, v_34022);
    env = stack[-3];
    stack[-2] = v_34022;
v_33971:
    v_34022 = stack[0];
    if (v_34022 == nil) goto v_33978;
    else goto v_33979;
v_33978:
    v_34022 = stack[-2];
    goto v_33977;
v_33979:
    v_34022 = nil;
    goto v_33977;
    v_34022 = nil;
v_33977:
    if (v_34022 == nil) goto v_33974;
    else goto v_33975;
v_33974:
    goto v_33970;
v_33975:
    v_34022 = stack[-2];
    v_34022 = qcar(v_34022);
    v_34022 = qcdr(v_34022);
    v_34022 = qcar(v_34022);
    fn = elt(env, 3); // isimplicit
    v_34022 = (*qfn1(fn))(fn, v_34022);
    env = stack[-3];
    if (v_34022 == nil) goto v_33989;
    goto v_34002;
v_33998:
    v_34023 = stack[-1];
    goto v_33999;
v_34000:
    v_34022 = stack[-2];
    v_34022 = qcar(v_34022);
    v_34022 = qcar(v_34022);
    goto v_34001;
v_34002:
    goto v_33998;
v_33999:
    goto v_34000;
v_34001:
    fn = elt(env, 4); // firstmatch
    v_34022 = (*qfn2(fn))(fn, v_34023, v_34022);
    env = stack[-3];
    if (v_34022 == nil) goto v_33989;
    goto v_34012;
v_34008:
    stack[0] = stack[-1];
    goto v_34009;
v_34010:
    v_34022 = stack[-2];
    v_34022 = qcar(v_34022);
    v_34022 = qcdr(v_34022);
    v_34022 = qcar(v_34022);
    fn = elt(env, 5); // implicittype
    v_34022 = (*qfn1(fn))(fn, v_34022);
    env = stack[-3];
    goto v_34011;
v_34012:
    goto v_34008;
v_34009:
    goto v_34010;
v_34011:
    v_34022 = list2(stack[0], v_34022);
    env = stack[-3];
    stack[0] = v_34022;
    goto v_33987;
v_33989:
v_33987:
    v_34022 = stack[-2];
    v_34022 = qcdr(v_34022);
    stack[-2] = v_34022;
    goto v_33971;
v_33970:
    v_34022 = stack[0];
    return onevalue(v_34022);
}



// Code for dipcontenti1

static LispObject CC_dipcontenti1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34026, v_34027, v_34028;
    LispObject fn;
    LispObject v_33956, v_33955, v_33954;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipcontenti1");
    va_start(aa, nargs);
    v_33954 = va_arg(aa, LispObject);
    v_33955 = va_arg(aa, LispObject);
    v_33956 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33956,v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33954,v_33955,v_33956);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33956;
    stack[-1] = v_33955;
    v_34027 = v_33954;
// end of prologue
v_33953:
    v_34026 = stack[0];
    if (v_34026 == nil) goto v_33960;
    else goto v_33961;
v_33960:
    goto v_33968;
v_33964:
    goto v_33965;
v_33966:
    v_34026 = stack[-1];
    goto v_33967;
v_33968:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    return cons(v_34027, v_34026);
v_33961:
    goto v_33981;
v_33977:
    goto v_33978;
v_33979:
    v_34026 = stack[0];
    v_34026 = qcdr(v_34026);
    v_34026 = qcar(v_34026);
    goto v_33980;
v_33981:
    goto v_33977;
v_33978:
    goto v_33979;
v_33980:
    fn = elt(env, 1); // vbcgcd
    v_34026 = (*qfn2(fn))(fn, v_34027, v_34026);
    env = stack[-3];
    stack[-2] = v_34026;
    v_34026 = stack[-1];
    if (v_34026 == nil) goto v_33989;
    goto v_33996;
v_33992:
    v_34026 = stack[0];
    v_34027 = qcar(v_34026);
    goto v_33993;
v_33994:
    v_34026 = stack[-1];
    goto v_33995;
v_33996:
    goto v_33992;
v_33993:
    goto v_33994;
v_33995:
    fn = elt(env, 2); // dipcontevmin
    v_34026 = (*qfn2(fn))(fn, v_34027, v_34026);
    env = stack[-3];
    stack[-1] = v_34026;
    goto v_33987;
v_33989:
v_33987:
    v_34026 = stack[-2];
    fn = elt(env, 3); // bcone!?
    v_34026 = (*qfn1(fn))(fn, v_34026);
    env = stack[-3];
    if (v_34026 == nil) goto v_34003;
    v_34026 = stack[-1];
    if (v_34026 == nil) goto v_34007;
    else goto v_34003;
v_34007:
    v_34026 = stack[-2];
    return ncons(v_34026);
v_34003:
    goto v_34020;
v_34014:
    v_34027 = stack[-2];
    goto v_34015;
v_34016:
    v_34028 = stack[-1];
    goto v_34017;
v_34018:
    v_34026 = stack[0];
    v_34026 = qcdr(v_34026);
    v_34026 = qcdr(v_34026);
    goto v_34019;
v_34020:
    goto v_34014;
v_34015:
    goto v_34016;
v_34017:
    goto v_34018;
v_34019:
    stack[-1] = v_34028;
    stack[0] = v_34026;
    goto v_33953;
    v_34026 = nil;
    goto v_33959;
    v_34026 = nil;
v_33959:
    return onevalue(v_34026);
}



// Code for validrule

static LispObject CC_validrule(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33969, v_33970;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
// copy arguments values to proper place
    v_33969 = v_33954;
// end of prologue
    fn = elt(env, 1); // validrule1
    v_33969 = (*qfn1(fn))(fn, v_33969);
    v_33970 = v_33969;
    v_33969 = v_33970;
    if (v_33969 == nil) goto v_33961;
    else goto v_33962;
v_33961:
    v_33969 = nil;
    goto v_33960;
v_33962:
    v_33969 = v_33970;
    return ncons(v_33969);
    v_33969 = nil;
v_33960:
    return onevalue(v_33969);
}



// Code for cflot

static LispObject CC_cflot(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33972, v_33973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33954);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33972 = v_33954;
// end of prologue
    v_33973 = v_33972;
    v_33973 = Lfloatp(nil, v_33973);
    env = stack[0];
    if (v_33973 == nil) goto v_33959;
    goto v_33957;
v_33959:
    v_33973 = v_33972;
    if (!consp(v_33973)) goto v_33963;
    else goto v_33964;
v_33963:
        return Lfloat(nil, v_33972);
v_33964:
    {
        fn = elt(env, 1); // bf2flr
        return (*qfn1(fn))(fn, v_33972);
    }
    v_33972 = nil;
v_33957:
    return onevalue(v_33972);
}



// Code for restore_props

static LispObject CC_restore_props(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34007, v_34008, v_34009;
    argcheck(nargs, 0, "restore_props");
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
    v_34007 = qvalue(elt(env, 1)); // props!*
    stack[-1] = v_34007;
v_33958:
    v_34007 = stack[-1];
    if (v_34007 == nil) goto v_33962;
    else goto v_33963;
v_33962:
    v_34007 = nil;
    goto v_33957;
v_33963:
    v_34007 = stack[-1];
    v_34007 = qcar(v_34007);
    stack[0] = v_34007;
    v_34007 = stack[0];
    v_34007 = qcdr(v_34007);
    v_34007 = Lconsp(nil, v_34007);
    env = stack[-2];
    if (v_34007 == nil) goto v_33972;
    goto v_33983;
v_33977:
    v_34007 = stack[0];
    v_34009 = qcar(v_34007);
    goto v_33978;
v_33979:
    v_34007 = stack[0];
    v_34007 = qcdr(v_34007);
    v_34008 = qcar(v_34007);
    goto v_33980;
v_33981:
    v_34007 = stack[0];
    v_34007 = qcdr(v_34007);
    v_34007 = qcdr(v_34007);
    goto v_33982;
v_33983:
    goto v_33977;
v_33978:
    goto v_33979;
v_33980:
    goto v_33981;
v_33982:
    v_34007 = Lputprop(nil, 3, v_34009, v_34008, v_34007);
    env = stack[-2];
    goto v_33970;
v_33972:
    goto v_33999;
v_33995:
    v_34007 = stack[0];
    v_34007 = qcar(v_34007);
    v_34008 = ncons(v_34007);
    env = stack[-2];
    goto v_33996;
v_33997:
    v_34007 = stack[0];
    v_34007 = qcdr(v_34007);
    goto v_33998;
v_33999:
    goto v_33995;
v_33996:
    goto v_33997;
v_33998:
    v_34007 = Lflag(nil, v_34008, v_34007);
    env = stack[-2];
    goto v_33970;
v_33970:
    v_34007 = stack[-1];
    v_34007 = qcdr(v_34007);
    stack[-1] = v_34007;
    goto v_33958;
v_33957:
    return onevalue(v_34007);
}



// Code for !*sf2ex

static LispObject CC_Hsf2ex(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_34038, v_34039, v_34040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    stack[-2] = nil;
v_33960:
    v_34038 = stack[-1];
    if (v_34038 == nil) goto v_33963;
    else goto v_33964;
v_33963:
    v_34038 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_34038);
    }
v_33964:
    v_34038 = stack[-1];
    if (!consp(v_34038)) goto v_33976;
    else goto v_33977;
v_33976:
    v_34038 = lisp_true;
    goto v_33975;
v_33977:
    v_34038 = stack[-1];
    v_34038 = qcar(v_34038);
    v_34038 = (consp(v_34038) ? nil : lisp_true);
    goto v_33975;
    v_34038 = nil;
v_33975:
    if (v_34038 == nil) goto v_33973;
    v_34038 = lisp_true;
    goto v_33971;
v_33973:
    goto v_33992;
v_33988:
    v_34038 = stack[-1];
    v_34038 = qcar(v_34038);
    v_34038 = qcar(v_34038);
    v_34039 = qcar(v_34038);
    goto v_33989;
v_33990:
    v_34038 = stack[0];
    goto v_33991;
v_33992:
    goto v_33988;
v_33989:
    goto v_33990;
v_33991:
    v_34038 = Lmemq(nil, v_34039, v_34038);
    v_34038 = (v_34038 == nil ? lisp_true : nil);
    goto v_33971;
    v_34038 = nil;
v_33971:
    if (v_34038 == nil) goto v_33969;
    goto v_34005;
v_34001:
    stack[0] = stack[-2];
    goto v_34002;
v_34003:
    goto v_34013;
v_34009:
    v_34038 = nil;
    v_34039 = ncons(v_34038);
    env = stack[-3];
    goto v_34010;
v_34011:
    v_34038 = stack[-1];
    goto v_34012;
v_34013:
    goto v_34009;
v_34010:
    goto v_34011;
v_34012:
    v_34038 = cons(v_34039, v_34038);
    env = stack[-3];
    v_34038 = ncons(v_34038);
    env = stack[-3];
    goto v_34004;
v_34005:
    goto v_34001;
v_34002:
    goto v_34003;
v_34004:
    {
        LispObject v_34044 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_34044, v_34038);
    }
v_33969:
    goto v_34026;
v_34020:
    v_34038 = stack[-1];
    v_34038 = qcar(v_34038);
    v_34038 = qcar(v_34038);
    v_34038 = qcar(v_34038);
    v_34040 = ncons(v_34038);
    env = stack[-3];
    goto v_34021;
v_34022:
    v_34038 = stack[-1];
    v_34038 = qcar(v_34038);
    v_34039 = qcdr(v_34038);
    goto v_34023;
v_34024:
    v_34038 = stack[-2];
    goto v_34025;
v_34026:
    goto v_34020;
v_34021:
    goto v_34022;
v_34023:
    goto v_34024;
v_34025:
    v_34038 = acons(v_34040, v_34039, v_34038);
    env = stack[-3];
    stack[-2] = v_34038;
    v_34038 = stack[-1];
    v_34038 = qcdr(v_34038);
    stack[-1] = v_34038;
    goto v_33960;
    v_34038 = nil;
    return onevalue(v_34038);
}



// Code for dp_prod

static LispObject CC_dp_prod(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33989, v_33990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33955;
    stack[-1] = v_33954;
// end of prologue
    goto v_33966;
v_33962:
    v_33989 = stack[-1];
    stack[-2] = Llength(nil, v_33989);
    env = stack[-3];
    goto v_33963;
v_33964:
    v_33989 = stack[0];
    v_33989 = Llength(nil, v_33989);
    env = stack[-3];
    goto v_33965;
v_33966:
    goto v_33962;
v_33963:
    goto v_33964;
v_33965:
    v_33989 = (LispObject)lesseq2(stack[-2], v_33989);
    v_33989 = v_33989 ? lisp_true : nil;
    env = stack[-3];
    if (v_33989 == nil) goto v_33960;
    goto v_33976;
v_33972:
    v_33990 = stack[-1];
    goto v_33973;
v_33974:
    v_33989 = stack[0];
    goto v_33975;
v_33976:
    goto v_33972;
v_33973:
    goto v_33974;
v_33975:
    {
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(fn, v_33990, v_33989);
    }
v_33960:
    goto v_33986;
v_33982:
    v_33990 = stack[0];
    goto v_33983;
v_33984:
    v_33989 = stack[-1];
    goto v_33985;
v_33986:
    goto v_33982;
v_33983:
    goto v_33984;
v_33985:
    {
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(fn, v_33990, v_33989);
    }
    v_33989 = nil;
    return onevalue(v_33989);
}



// Code for zfactor

static LispObject CC_zfactor(LispObject env,
                         LispObject v_33954)
{
    env = qenv(env);
    LispObject v_33964, v_33965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33964 = v_33954;
// end of prologue
    goto v_33961;
v_33957:
    v_33965 = v_33964;
    goto v_33958;
v_33959:
    v_33964 = lisp_true;
    goto v_33960;
v_33961:
    goto v_33957;
v_33958:
    goto v_33959;
v_33960:
    {
        fn = elt(env, 1); // zfactor1
        return (*qfn2(fn))(fn, v_33965, v_33964);
    }
}



// Code for bfprin0x

static LispObject CC_bfprin0x(LispObject env,
                         LispObject v_33954, LispObject v_33955)
{
    env = qenv(env);
    LispObject v_33990, v_33991, v_33992;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33955,v_33954);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33954,v_33955);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33991 = v_33955;
    v_33990 = v_33954;
// end of prologue
    goto v_33967;
v_33963:
    goto v_33964;
v_33965:
    goto v_33966;
v_33967:
    goto v_33963;
v_33964:
    goto v_33965;
v_33966:
    fn = elt(env, 1); // bfexplode0x
    v_33990 = (*qfn2(fn))(fn, v_33990, v_33991);
    env = stack[0];
    v_33991 = v_33990;
    v_33991 = qcdr(v_33991);
    v_33991 = qcar(v_33991);
    v_33992 = v_33990;
    v_33992 = qcdr(v_33992);
    v_33992 = qcdr(v_33992);
    v_33992 = qcar(v_33992);
    v_33990 = qcar(v_33990);
    goto v_33986;
v_33980:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    goto v_33985;
v_33986:
    goto v_33980;
v_33981:
    goto v_33982;
v_33983:
    goto v_33984;
v_33985:
    {
        fn = elt(env, 2); // bfprin!:lst
        return (*qfnn(fn))(fn, 3, v_33990, v_33991, v_33992);
    }
    return onevalue(v_33990);
}



setup_type const u55_setup[] =
{
    {"chrstrem",                CC_chrstrem,    TOO_MANY_1,    WRONG_NO_1},
    {"quotfexf*1",              TOO_FEW_2,      CC_quotfexfH1, WRONG_NO_2},
    {"vdelete",                 TOO_FEW_2,      CC_vdelete,    WRONG_NO_2},
    {"search_att",              TOO_FEW_2,      CC_search_att, WRONG_NO_2},
    {"setprev",                 TOO_FEW_2,      CC_setprev,    WRONG_NO_2},
    {"poly-remainder",          CC_polyKremainder,TOO_MANY_1,  WRONG_NO_1},
    {"mkuniquewedge",           CC_mkuniquewedge,TOO_MANY_1,   WRONG_NO_1},
    {"new_provev",              TOO_FEW_2,      CC_new_provev, WRONG_NO_2},
    {"prepsqyy",                CC_prepsqyy,    TOO_MANY_1,    WRONG_NO_1},
    {"no_of_tm_sf",             CC_no_of_tm_sf, TOO_MANY_1,    WRONG_NO_1},
    {"cde_mkset",               CC_cde_mkset,   TOO_MANY_1,    WRONG_NO_1},
    {"sfto_b:cquot",            TOO_FEW_2,      CC_sfto_bTcquot,WRONG_NO_2},
    {"getsetvarlis",            CC_getsetvarlis,TOO_MANY_1,    WRONG_NO_1},
    {"dfmax",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dfmax},
    {"rl_*qe",                  TOO_FEW_2,      CC_rl_Hqe,     WRONG_NO_2},
    {"dip_comp1",               TOO_FEW_2,      CC_dip_comp1,  WRONG_NO_2},
    {"search4facf",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_search4facf},
    {"rewrite2",                TOO_FEW_2,      CC_rewrite2,   WRONG_NO_2},
    {"column_dim",              CC_column_dim,  TOO_MANY_1,    WRONG_NO_1},
    {"gvarlis",                 CC_gvarlis,     TOO_MANY_1,    WRONG_NO_1},
    {"weak_xreduce",            TOO_FEW_2,      CC_weak_xreduce,WRONG_NO_2},
    {"tvectorp",                CC_tvectorp,    TOO_MANY_1,    WRONG_NO_1},
    {"ev-tades",                TOO_FEW_2,      CC_evKtades,   WRONG_NO_2},
    {"reprod",                  TOO_FEW_2,      CC_reprod,     WRONG_NO_2},
    {"mo_from_ei",              CC_mo_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"pa_vect2list",            CC_pa_vect2list,TOO_MANY_1,    WRONG_NO_1},
    {"remk",                    TOO_FEW_2,      CC_remk,       WRONG_NO_2},
    {"modroots1",               TOO_FEW_2,      CC_modroots1,  WRONG_NO_2},
    {"simprad",                 TOO_FEW_2,      CC_simprad,    WRONG_NO_2},
    {"ev_max#",                 TOO_FEW_2,      CC_ev_maxC,    WRONG_NO_2},
    {"ps:constmult-erule",      TOO_FEW_2,      CC_psTconstmultKerule,WRONG_NO_2},
    {"redpar",                  TOO_FEW_2,      CC_redpar,     WRONG_NO_2},
    {"remove_root_item",        CC_remove_root_item,TOO_MANY_1,WRONG_NO_1},
    {"bfdivide",                TOO_FEW_2,      CC_bfdivide,   WRONG_NO_2},
    {"ext_edges",               CC_ext_edges,   TOO_MANY_1,    WRONG_NO_1},
    {"*ex2sf",                  CC_Hex2sf,      TOO_MANY_1,    WRONG_NO_1},
    {"lf=tovarlessp",           TOO_FEW_2,      CC_lfMtovarlessp,WRONG_NO_2},
    {"boolean-eval2",           CC_booleanKeval2,TOO_MANY_1,   WRONG_NO_1},
    {"sqlessp",                 TOO_FEW_2,      CC_sqlessp,    WRONG_NO_2},
    {"crn:zerop",               CC_crnTzerop,   TOO_MANY_1,    WRONG_NO_1},
    {"mkg1",                    TOO_FEW_2,      CC_mkg1,       WRONG_NO_2},
    {"uniquifyf",               CC_uniquifyf,   TOO_MANY_1,    WRONG_NO_1},
    {"generate_multiindex",     CC_generate_multiindex,TOO_MANY_1,WRONG_NO_1},
    {"gd_applyscheme",          TOO_FEW_2,      CC_gd_applyscheme,WRONG_NO_2},
    {"get_rep_of_generator",    TOO_FEW_2,      CC_get_rep_of_generator,WRONG_NO_2},
    {"talp_try3",               TOO_FEW_2,      CC_talp_try3,  WRONG_NO_2},
    {"implicitdec",             CC_implicitdec, TOO_MANY_1,    WRONG_NO_1},
    {"dipcontenti1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipcontenti1},
    {"validrule",               CC_validrule,   TOO_MANY_1,    WRONG_NO_1},
    {"cflot",                   CC_cflot,       TOO_MANY_1,    WRONG_NO_1},
    {"restore_props",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_restore_props},
    {"*sf2ex",                  TOO_FEW_2,      CC_Hsf2ex,     WRONG_NO_2},
    {"dp_prod",                 TOO_FEW_2,      CC_dp_prod,    WRONG_NO_2},
    {"zfactor",                 CC_zfactor,     TOO_MANY_1,    WRONG_NO_1},
    {"bfprin0x",                TOO_FEW_2,      CC_bfprin0x,   WRONG_NO_2},
    {NULL, (one_args *)"u55", (two_args *)"89302 1436507 796490", 0}
};

// end of generated code
