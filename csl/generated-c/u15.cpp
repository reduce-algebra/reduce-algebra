
// $destdir/u15.c        Machine generated C code

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



// Code for bc2a

static LispObject CC_bc2a(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7724, v_7725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7725 = v_7712;
// end of prologue
    v_7724 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_7724 == nil) goto v_7717;
    v_7724 = v_7725;
    goto v_7715;
v_7717:
    v_7724 = v_7725;
    {
        fn = elt(env, 2); // prepsq
        return (*qfn1(fn))(fn, v_7724);
    }
    v_7724 = nil;
v_7715:
    return onevalue(v_7724);
}



// Code for vevdif

static LispObject CC_vevdif(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7837, v_7838, v_7839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_7713;
    stack[-4] = v_7712;
// end of prologue
    stack[-5] = nil;
    v_7838 = nil;
    v_7837 = stack[-4];
    stack[-1] = v_7837;
    v_7837 = stack[-3];
    stack[0] = v_7837;
v_7727:
    v_7837 = stack[-1];
    if (v_7837 == nil) goto v_7730;
    v_7837 = stack[0];
    if (v_7837 == nil) goto v_7730;
    v_7837 = v_7838;
    if (v_7837 == nil) goto v_7737;
    else goto v_7730;
v_7737:
    goto v_7731;
v_7730:
    goto v_7726;
v_7731:
    goto v_7744;
v_7740:
    v_7837 = stack[-1];
    v_7838 = qcar(v_7837);
    goto v_7741;
v_7742:
    v_7837 = stack[0];
    v_7837 = qcar(v_7837);
    goto v_7743;
v_7744:
    goto v_7740;
v_7741:
    goto v_7742;
v_7743:
    v_7837 = (LispObject)(intptr_t)((intptr_t)v_7838 - (intptr_t)v_7837 + TAG_FIXNUM);
    stack[-2] = v_7837;
    goto v_7755;
v_7751:
    v_7838 = stack[-2];
    goto v_7752;
v_7753:
    v_7837 = stack[-5];
    goto v_7754;
v_7755:
    goto v_7751;
v_7752:
    goto v_7753;
v_7754:
    v_7837 = cons(v_7838, v_7837);
    env = stack[-6];
    stack[-5] = v_7837;
    goto v_7762;
v_7758:
    v_7838 = stack[-2];
    goto v_7759;
v_7760:
    v_7837 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7761;
v_7762:
    goto v_7758;
v_7759:
    goto v_7760;
v_7761:
    v_7837 = ((intptr_t)v_7838 < (intptr_t)v_7837) ? lisp_true : nil;
    v_7838 = v_7837;
    v_7837 = stack[-1];
    v_7837 = qcdr(v_7837);
    stack[-1] = v_7837;
    v_7837 = stack[0];
    v_7837 = qcdr(v_7837);
    stack[0] = v_7837;
    goto v_7727;
v_7726:
    v_7837 = v_7838;
    if (v_7837 == nil) goto v_7774;
    else goto v_7772;
v_7774:
    v_7837 = stack[0];
    if (v_7837 == nil) goto v_7776;
    v_7837 = stack[0];
    if (v_7837 == nil) goto v_7782;
    else goto v_7783;
v_7782:
    v_7837 = lisp_true;
    goto v_7781;
v_7783:
    goto v_7796;
v_7792:
    v_7837 = stack[0];
    v_7838 = qcar(v_7837);
    goto v_7793;
v_7794:
    v_7837 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7795;
v_7796:
    goto v_7792;
v_7793:
    goto v_7794;
v_7795:
    if (v_7838 == v_7837) goto v_7790;
    else goto v_7791;
v_7790:
    v_7837 = stack[0];
    v_7837 = qcdr(v_7837);
    fn = elt(env, 5); // vevzero!?1
    v_7837 = (*qfn1(fn))(fn, v_7837);
    env = stack[-6];
    goto v_7789;
v_7791:
    v_7837 = nil;
    goto v_7789;
    v_7837 = nil;
v_7789:
    goto v_7781;
    v_7837 = nil;
v_7781:
    if (v_7837 == nil) goto v_7779;
    else goto v_7776;
v_7779:
    goto v_7772;
v_7776:
    goto v_7773;
v_7772:
    v_7837 = stack[-4];
    v_7837 = Lprint(nil, v_7837);
    env = stack[-6];
    v_7837 = stack[-3];
    v_7837 = Lprint(nil, v_7837);
    env = stack[-6];
    v_7837 = elt(env, 2); // backtrace
    fn = elt(env, 6); // getd
    v_7837 = (*qfn1(fn))(fn, v_7837);
    env = stack[-6];
    if (v_7837 == nil) goto v_7813;
    fn = elt(env, 2); // backtrace
    v_7837 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    goto v_7811;
v_7813:
v_7811:
    goto v_7824;
v_7818:
    v_7839 = elt(env, 3); // dipoly
    goto v_7819;
v_7820:
    v_7838 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_7821;
v_7822:
    v_7837 = elt(env, 4); // "Vevdif, difference would be < 0"
    goto v_7823;
v_7824:
    goto v_7818;
v_7819:
    goto v_7820;
v_7821:
    goto v_7822;
v_7823:
    {
        fn = elt(env, 7); // rerror
        return (*qfnn(fn))(fn, 3, v_7839, v_7838, v_7837);
    }
v_7773:
    goto v_7833;
v_7829:
    v_7837 = stack[-5];
    v_7838 = Lnreverse(nil, v_7837);
    goto v_7830;
v_7831:
    v_7837 = stack[-1];
    goto v_7832;
v_7833:
    goto v_7829;
v_7830:
    goto v_7831;
v_7832:
        return Lnconc(nil, v_7838, v_7837);
    return onevalue(v_7837);
}



// Code for map__edges

static LispObject CC_map__edges(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7755, v_7756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
    stack[-1] = nil;
v_7718:
    v_7755 = stack[0];
    if (v_7755 == nil) goto v_7723;
    else goto v_7724;
v_7723:
    goto v_7719;
v_7724:
    goto v_7731;
v_7727:
    v_7755 = stack[0];
    v_7756 = qcar(v_7755);
    goto v_7728;
v_7729:
    v_7755 = stack[-1];
    goto v_7730;
v_7731:
    goto v_7727;
v_7728:
    goto v_7729;
v_7730:
    v_7755 = cons(v_7756, v_7755);
    env = stack[-2];
    stack[-1] = v_7755;
    v_7755 = stack[0];
    v_7755 = qcdr(v_7755);
    stack[0] = v_7755;
    goto v_7718;
v_7719:
    v_7755 = nil;
    v_7756 = v_7755;
v_7720:
    v_7755 = stack[-1];
    if (v_7755 == nil) goto v_7740;
    else goto v_7741;
v_7740:
    v_7755 = v_7756;
    goto v_7717;
v_7741:
    goto v_7749;
v_7745:
    v_7755 = stack[-1];
    v_7755 = qcar(v_7755);
    goto v_7746;
v_7747:
    goto v_7748;
v_7749:
    goto v_7745;
v_7746:
    goto v_7747;
v_7748:
    fn = elt(env, 1); // union_edges
    v_7755 = (*qfn2(fn))(fn, v_7755, v_7756);
    env = stack[-2];
    v_7756 = v_7755;
    v_7755 = stack[-1];
    v_7755 = qcdr(v_7755);
    stack[-1] = v_7755;
    goto v_7720;
v_7717:
    return onevalue(v_7755);
}



// Code for evalneq

static LispObject CC_evalneq(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7724, v_7725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
// copy arguments values to proper place
    v_7724 = v_7713;
    v_7725 = v_7712;
// end of prologue
    goto v_7720;
v_7716:
    goto v_7717;
v_7718:
    goto v_7719;
v_7720:
    goto v_7716;
v_7717:
    goto v_7718;
v_7719:
    fn = elt(env, 1); // evalequal
    v_7724 = (*qfn2(fn))(fn, v_7725, v_7724);
    v_7724 = (v_7724 == nil ? lisp_true : nil);
    return onevalue(v_7724);
}



// Code for red!-ratios2

static LispObject CC_redKratios2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7822, v_7823, v_7824, v_7825;
    LispObject fn;
    LispObject v_7715, v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "red-ratios2");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    v_7715 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_7715,v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_7712,v_7713,v_7714,v_7715);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_7715;
    stack[-2] = v_7714;
    stack[-3] = v_7713;
    stack[-4] = v_7712;
// end of prologue
v_7711:
    v_7822 = stack[-4];
    if (v_7822 == nil) goto v_7724;
    else goto v_7725;
v_7724:
    v_7822 = nil;
    goto v_7723;
v_7725:
    goto v_7738;
v_7734:
    goto v_7744;
v_7740:
    v_7823 = stack[-2];
    goto v_7741;
v_7742:
    v_7822 = stack[-3];
    v_7822 = qcar(v_7822);
    goto v_7743;
v_7744:
    goto v_7740;
v_7741:
    goto v_7742;
v_7743:
    stack[0] = times2(v_7823, v_7822);
    env = stack[-6];
    stack[-5] = stack[0];
    goto v_7735;
v_7736:
    goto v_7753;
v_7749:
    v_7823 = stack[-1];
    goto v_7750;
v_7751:
    v_7822 = stack[-4];
    v_7822 = qcar(v_7822);
    goto v_7752;
v_7753:
    goto v_7749;
v_7750:
    goto v_7751;
v_7752:
    v_7822 = times2(v_7823, v_7822);
    env = stack[-6];
    goto v_7737;
v_7738:
    goto v_7734;
v_7735:
    goto v_7736;
v_7737:
    if (equal(stack[0], v_7822)) goto v_7732;
    else goto v_7733;
v_7732:
    goto v_7765;
v_7761:
    v_7823 = stack[-5];
    goto v_7762;
v_7763:
    v_7822 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7764;
v_7765:
    goto v_7761;
v_7762:
    goto v_7763;
v_7764:
    if (v_7823 == v_7822) goto v_7760;
    goto v_7772;
v_7768:
    goto v_7778;
v_7774:
    goto v_7784;
v_7780:
    v_7823 = stack[-1];
    goto v_7781;
v_7782:
    v_7822 = stack[-2];
    goto v_7783;
v_7784:
    goto v_7780;
v_7781:
    goto v_7782;
v_7783:
    v_7823 = Lgcd(nil, v_7823, v_7822);
    env = stack[-6];
    goto v_7775;
v_7776:
    v_7822 = stack[-1];
    goto v_7777;
v_7778:
    goto v_7774;
v_7775:
    goto v_7776;
v_7777:
    v_7823 = Cremainder(v_7823, v_7822);
    env = stack[-6];
    goto v_7769;
v_7770:
    v_7822 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7771;
v_7772:
    goto v_7768;
v_7769:
    goto v_7770;
v_7771:
    v_7822 = (v_7823 == v_7822 ? lisp_true : nil);
    goto v_7758;
v_7760:
    v_7822 = nil;
    goto v_7758;
    v_7822 = nil;
v_7758:
    goto v_7731;
v_7733:
    v_7822 = nil;
    goto v_7731;
    v_7822 = nil;
v_7731:
    if (v_7822 == nil) goto v_7729;
    goto v_7801;
v_7797:
    v_7823 = stack[-1];
    goto v_7798;
v_7799:
    v_7822 = stack[-2];
    goto v_7800;
v_7801:
    goto v_7797;
v_7798:
    goto v_7799;
v_7800:
    {
        fn = elt(env, 2); // red!-lowest!-terms
        return (*qfn2(fn))(fn, v_7823, v_7822);
    }
v_7729:
    goto v_7815;
v_7807:
    v_7822 = stack[-4];
    v_7825 = qcdr(v_7822);
    goto v_7808;
v_7809:
    v_7822 = stack[-3];
    v_7824 = qcdr(v_7822);
    goto v_7810;
v_7811:
    v_7823 = stack[-2];
    goto v_7812;
v_7813:
    v_7822 = stack[-1];
    goto v_7814;
v_7815:
    goto v_7807;
v_7808:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    goto v_7813;
v_7814:
    stack[-4] = v_7825;
    stack[-3] = v_7824;
    stack[-2] = v_7823;
    stack[-1] = v_7822;
    goto v_7711;
    v_7822 = nil;
v_7723:
    return onevalue(v_7822);
}



// Code for dp_neg

static LispObject CC_dp_neg(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7774, v_7775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_7774 = v_7712;
// end of prologue
    stack[-4] = v_7774;
    v_7774 = stack[-4];
    if (v_7774 == nil) goto v_7723;
    else goto v_7724;
v_7723:
    v_7774 = nil;
    goto v_7718;
v_7724:
    v_7774 = stack[-4];
    v_7774 = qcar(v_7774);
    v_7775 = v_7774;
    goto v_7736;
v_7732:
    v_7774 = v_7775;
    stack[0] = qcar(v_7774);
    goto v_7733;
v_7734:
    v_7774 = v_7775;
    v_7774 = qcdr(v_7774);
    fn = elt(env, 1); // cali_bc_neg
    v_7774 = (*qfn1(fn))(fn, v_7774);
    env = stack[-5];
    goto v_7735;
v_7736:
    goto v_7732;
v_7733:
    goto v_7734;
v_7735:
    v_7774 = cons(stack[0], v_7774);
    env = stack[-5];
    v_7774 = ncons(v_7774);
    env = stack[-5];
    stack[-2] = v_7774;
    stack[-3] = v_7774;
v_7719:
    v_7774 = stack[-4];
    v_7774 = qcdr(v_7774);
    stack[-4] = v_7774;
    v_7774 = stack[-4];
    if (v_7774 == nil) goto v_7746;
    else goto v_7747;
v_7746:
    v_7774 = stack[-3];
    goto v_7718;
v_7747:
    goto v_7755;
v_7751:
    stack[-1] = stack[-2];
    goto v_7752;
v_7753:
    v_7774 = stack[-4];
    v_7774 = qcar(v_7774);
    v_7775 = v_7774;
    goto v_7766;
v_7762:
    v_7774 = v_7775;
    stack[0] = qcar(v_7774);
    goto v_7763;
v_7764:
    v_7774 = v_7775;
    v_7774 = qcdr(v_7774);
    fn = elt(env, 1); // cali_bc_neg
    v_7774 = (*qfn1(fn))(fn, v_7774);
    env = stack[-5];
    goto v_7765;
v_7766:
    goto v_7762;
v_7763:
    goto v_7764;
v_7765:
    v_7774 = cons(stack[0], v_7774);
    env = stack[-5];
    v_7774 = ncons(v_7774);
    env = stack[-5];
    goto v_7754;
v_7755:
    goto v_7751;
v_7752:
    goto v_7753;
v_7754:
    v_7774 = Lrplacd(nil, stack[-1], v_7774);
    env = stack[-5];
    v_7774 = stack[-2];
    v_7774 = qcdr(v_7774);
    stack[-2] = v_7774;
    goto v_7719;
v_7718:
    return onevalue(v_7774);
}



// Code for gperm3

static LispObject CC_gperm3(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7742, v_7743, v_7744;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7743 = v_7713;
    v_7742 = v_7712;
// end of prologue
v_7718:
    v_7744 = v_7742;
    if (v_7744 == nil) goto v_7721;
    else goto v_7722;
v_7721:
    v_7742 = v_7743;
    goto v_7717;
v_7722:
    v_7744 = v_7742;
    v_7744 = qcdr(v_7744);
    stack[0] = v_7744;
    goto v_7736;
v_7730:
    v_7744 = v_7743;
    goto v_7731;
v_7732:
    v_7743 = qcar(v_7742);
    goto v_7733;
v_7734:
    v_7742 = nil;
    goto v_7735;
v_7736:
    goto v_7730;
v_7731:
    goto v_7732;
v_7733:
    goto v_7734;
v_7735:
    fn = elt(env, 1); // gperm2
    v_7742 = (*qfnn(fn))(fn, 3, v_7744, v_7743, v_7742);
    env = stack[-1];
    v_7743 = v_7742;
    v_7742 = stack[0];
    goto v_7718;
    v_7742 = nil;
v_7717:
    return onevalue(v_7742);
}



// Code for exptsq

static LispObject CC_exptsq(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7980, v_7981, v_7982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7713;
    stack[-2] = v_7712;
// end of prologue
    goto v_7727;
v_7723:
    v_7981 = stack[-1];
    goto v_7724;
v_7725:
    v_7980 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7726;
v_7727:
    goto v_7723;
v_7724:
    goto v_7725;
v_7726:
    if (v_7981 == v_7980) goto v_7721;
    else goto v_7722;
v_7721:
    v_7980 = stack[-2];
    goto v_7717;
v_7722:
    goto v_7737;
v_7733:
    v_7981 = stack[-1];
    goto v_7734;
v_7735:
    v_7980 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7736;
v_7737:
    goto v_7733;
v_7734:
    goto v_7735;
v_7736:
    if (v_7981 == v_7980) goto v_7731;
    else goto v_7732;
v_7731:
    v_7980 = stack[-2];
    v_7980 = qcar(v_7980);
    if (v_7980 == nil) goto v_7742;
    else goto v_7743;
v_7742:
    goto v_7753;
v_7747:
    v_7982 = elt(env, 2); // poly
    goto v_7748;
v_7749:
    v_7981 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_7750;
v_7751:
    v_7980 = elt(env, 3); // " 0**0 formed"
    goto v_7752;
v_7753:
    goto v_7747;
v_7748:
    goto v_7749;
v_7750:
    goto v_7751;
v_7752:
    {
        fn = elt(env, 6); // rerror
        return (*qfnn(fn))(fn, 3, v_7982, v_7981, v_7980);
    }
v_7743:
    goto v_7764;
v_7760:
    v_7981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7761;
v_7762:
    v_7980 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7763;
v_7764:
    goto v_7760;
v_7761:
    goto v_7762;
v_7763:
    return cons(v_7981, v_7980);
    v_7980 = nil;
    goto v_7717;
v_7732:
    v_7980 = stack[-2];
    v_7980 = qcar(v_7980);
    if (v_7980 == nil) goto v_7767;
    else goto v_7768;
v_7767:
    v_7980 = stack[-2];
    goto v_7717;
v_7768:
    goto v_7779;
v_7775:
    v_7981 = stack[-1];
    goto v_7776;
v_7777:
    v_7980 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7778;
v_7779:
    goto v_7775;
v_7776:
    goto v_7777;
v_7778:
    v_7980 = (LispObject)lessp2(v_7981, v_7980);
    v_7980 = v_7980 ? lisp_true : nil;
    env = stack[-4];
    if (v_7980 == nil) goto v_7773;
    goto v_7788;
v_7784:
    v_7980 = stack[-2];
    fn = elt(env, 7); // mk!*sq
    v_7981 = (*qfn1(fn))(fn, v_7980);
    env = stack[-4];
    goto v_7785;
v_7786:
    v_7980 = stack[-1];
    goto v_7787;
v_7788:
    goto v_7784;
v_7785:
    goto v_7786;
v_7787:
    v_7980 = list2(v_7981, v_7980);
    env = stack[-4];
    {
        fn = elt(env, 8); // simpexpt
        return (*qfn1(fn))(fn, v_7980);
    }
v_7773:
    v_7980 = qvalue(elt(env, 4)); // !*exp
    if (v_7980 == nil) goto v_7792;
    else goto v_7793;
v_7792:
    goto v_7800;
v_7796:
    goto v_7806;
v_7802:
    v_7980 = stack[-2];
    v_7981 = qcar(v_7980);
    goto v_7803;
v_7804:
    v_7980 = stack[-1];
    goto v_7805;
v_7806:
    goto v_7802;
v_7803:
    goto v_7804;
v_7805:
    fn = elt(env, 9); // mksfpf
    stack[0] = (*qfn2(fn))(fn, v_7981, v_7980);
    env = stack[-4];
    goto v_7797;
v_7798:
    goto v_7815;
v_7811:
    v_7980 = stack[-2];
    v_7981 = qcdr(v_7980);
    goto v_7812;
v_7813:
    v_7980 = stack[-1];
    goto v_7814;
v_7815:
    goto v_7811;
v_7812:
    goto v_7813;
v_7814:
    fn = elt(env, 9); // mksfpf
    v_7980 = (*qfn2(fn))(fn, v_7981, v_7980);
    goto v_7799;
v_7800:
    goto v_7796;
v_7797:
    goto v_7798;
v_7799:
    {
        LispObject v_7987 = stack[0];
        return cons(v_7987, v_7980);
    }
v_7793:
    v_7980 = stack[-2];
    fn = elt(env, 10); // kernp
    v_7980 = (*qfn1(fn))(fn, v_7980);
    env = stack[-4];
    if (v_7980 == nil) goto v_7820;
    goto v_7828;
v_7824:
    v_7980 = stack[-2];
    v_7980 = qcar(v_7980);
    v_7980 = qcar(v_7980);
    v_7980 = qcar(v_7980);
    v_7981 = qcar(v_7980);
    goto v_7825;
v_7826:
    v_7980 = stack[-1];
    goto v_7827;
v_7828:
    goto v_7824;
v_7825:
    goto v_7826;
v_7827:
    {
        fn = elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_7981, v_7980);
    }
v_7820:
    goto v_7841;
v_7837:
    v_7980 = stack[-2];
    v_7981 = qcdr(v_7980);
    goto v_7838;
v_7839:
    v_7980 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7840;
v_7841:
    goto v_7837;
v_7838:
    goto v_7839;
v_7840:
    if (v_7981 == v_7980) goto v_7835;
    else goto v_7836;
v_7835:
    goto v_7850;
v_7846:
    goto v_7856;
v_7852:
    v_7980 = stack[-2];
    v_7981 = qcar(v_7980);
    goto v_7853;
v_7854:
    v_7980 = stack[-1];
    goto v_7855;
v_7856:
    goto v_7852;
v_7853:
    goto v_7854;
v_7855:
    fn = elt(env, 12); // exptf
    v_7981 = (*qfn2(fn))(fn, v_7981, v_7980);
    goto v_7847;
v_7848:
    v_7980 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7849;
v_7850:
    goto v_7846;
v_7847:
    goto v_7848;
v_7849:
    return cons(v_7981, v_7980);
v_7836:
    v_7980 = stack[-2];
    v_7980 = qcar(v_7980);
    if (!consp(v_7980)) goto v_7865;
    else goto v_7866;
v_7865:
    v_7980 = lisp_true;
    goto v_7864;
v_7866:
    v_7980 = stack[-2];
    v_7980 = qcar(v_7980);
    v_7980 = qcar(v_7980);
    v_7980 = (consp(v_7980) ? nil : lisp_true);
    goto v_7864;
    v_7980 = nil;
v_7864:
    if (v_7980 == nil) goto v_7862;
    goto v_7881;
v_7877:
    goto v_7887;
v_7883:
    goto v_7893;
v_7889:
    v_7980 = stack[-2];
    v_7981 = qcar(v_7980);
    goto v_7890;
v_7891:
    v_7980 = stack[-1];
    goto v_7892;
v_7893:
    goto v_7889;
v_7890:
    goto v_7891;
v_7892:
    fn = elt(env, 13); // !:expt
    v_7981 = (*qfn2(fn))(fn, v_7981, v_7980);
    env = stack[-4];
    goto v_7884;
v_7885:
    v_7980 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7886;
v_7887:
    goto v_7883;
v_7884:
    goto v_7885;
v_7886:
    stack[-3] = cons(v_7981, v_7980);
    env = stack[-4];
    goto v_7878;
v_7879:
    goto v_7903;
v_7899:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7900;
v_7901:
    goto v_7910;
v_7906:
    v_7980 = stack[-2];
    v_7981 = qcdr(v_7980);
    goto v_7907;
v_7908:
    v_7980 = stack[-1];
    goto v_7909;
v_7910:
    goto v_7906;
v_7907:
    goto v_7908;
v_7909:
    fn = elt(env, 12); // exptf
    v_7980 = (*qfn2(fn))(fn, v_7981, v_7980);
    env = stack[-4];
    goto v_7902;
v_7903:
    goto v_7899;
v_7900:
    goto v_7901;
v_7902:
    v_7980 = cons(stack[0], v_7980);
    env = stack[-4];
    goto v_7880;
v_7881:
    goto v_7877;
v_7878:
    goto v_7879;
v_7880:
    fn = elt(env, 14); // multsq
    v_7980 = (*qfn2(fn))(fn, stack[-3], v_7980);
    env = stack[-4];
    stack[-3] = v_7980;
    goto v_7720;
v_7862:
    v_7980 = stack[-2];
    stack[-3] = v_7980;
v_7919:
    goto v_7929;
v_7925:
    v_7980 = stack[-1];
    v_7981 = sub1(v_7980);
    env = stack[-4];
    stack[-1] = v_7981;
    goto v_7926;
v_7927:
    v_7980 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7928;
v_7929:
    goto v_7925;
v_7926:
    goto v_7927;
v_7928:
    v_7980 = (LispObject)greaterp2(v_7981, v_7980);
    v_7980 = v_7980 ? lisp_true : nil;
    env = stack[-4];
    if (v_7980 == nil) goto v_7922;
    else goto v_7923;
v_7922:
    goto v_7918;
v_7923:
    goto v_7939;
v_7935:
    goto v_7945;
v_7941:
    v_7980 = stack[-2];
    v_7981 = qcar(v_7980);
    goto v_7942;
v_7943:
    v_7980 = stack[-3];
    v_7980 = qcar(v_7980);
    goto v_7944;
v_7945:
    goto v_7941;
v_7942:
    goto v_7943;
v_7944:
    fn = elt(env, 15); // multf
    stack[0] = (*qfn2(fn))(fn, v_7981, v_7980);
    env = stack[-4];
    goto v_7936;
v_7937:
    goto v_7955;
v_7951:
    v_7980 = stack[-2];
    v_7981 = qcdr(v_7980);
    goto v_7952;
v_7953:
    v_7980 = stack[-3];
    v_7980 = qcdr(v_7980);
    goto v_7954;
v_7955:
    goto v_7951;
v_7952:
    goto v_7953;
v_7954:
    fn = elt(env, 15); // multf
    v_7980 = (*qfn2(fn))(fn, v_7981, v_7980);
    env = stack[-4];
    goto v_7938;
v_7939:
    goto v_7935;
v_7936:
    goto v_7937;
v_7938:
    v_7980 = cons(stack[0], v_7980);
    env = stack[-4];
    stack[-3] = v_7980;
    goto v_7919;
v_7918:
    v_7980 = stack[-3];
    fn = elt(env, 16); // canonsq
    v_7980 = (*qfn1(fn))(fn, v_7980);
    env = stack[-4];
    stack[-3] = v_7980;
    goto v_7720;
v_7720:
    v_7980 = stack[-3];
    v_7980 = qcdr(v_7980);
    if (v_7980 == nil) goto v_7964;
    else goto v_7965;
v_7964:
    goto v_7975;
v_7969:
    v_7982 = elt(env, 2); // poly
    goto v_7970;
v_7971:
    v_7981 = (LispObject)1616+TAG_FIXNUM; // 101
    goto v_7972;
v_7973:
    v_7980 = elt(env, 5); // "Zero divisor"
    goto v_7974;
v_7975:
    goto v_7969;
v_7970:
    goto v_7971;
v_7972:
    goto v_7973;
v_7974:
    fn = elt(env, 6); // rerror
    v_7980 = (*qfnn(fn))(fn, 3, v_7982, v_7981, v_7980);
    goto v_7963;
v_7965:
v_7963:
    v_7980 = stack[-3];
v_7717:
    return onevalue(v_7980);
}



// Code for gcref_mknode!-tgf

static LispObject CC_gcref_mknodeKtgf(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
    v_7721 = stack[0];
    v_7721 = Lprinc(nil, v_7721);
    env = stack[-1];
    v_7721 = elt(env, 1); // " "
    v_7721 = Lprinc(nil, v_7721);
    env = stack[-1];
    v_7721 = stack[0];
    fn = elt(env, 2); // prin2t
    v_7721 = (*qfn1(fn))(fn, v_7721);
    v_7721 = nil;
    return onevalue(v_7721);
}



// Code for rl_simpl

static LispObject CC_rl_simpl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7734, v_7735, v_7736;
    LispObject fn;
    LispObject v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_simpl");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7712,v_7713,v_7714);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7734 = v_7714;
    v_7735 = v_7713;
    v_7736 = v_7712;
// end of prologue
    goto v_7721;
v_7717:
    stack[0] = qvalue(elt(env, 1)); // rl_simpl!*
    goto v_7718;
v_7719:
    goto v_7730;
v_7724:
    goto v_7725;
v_7726:
    goto v_7727;
v_7728:
    goto v_7729;
v_7730:
    goto v_7724;
v_7725:
    goto v_7726;
v_7727:
    goto v_7728;
v_7729:
    v_7734 = list3(v_7736, v_7735, v_7734);
    env = stack[-1];
    goto v_7720;
v_7721:
    goto v_7717;
v_7718:
    goto v_7719;
v_7720:
    {
        LispObject v_7738 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_7738, v_7734);
    }
}



// Code for removeg2

static LispObject CC_removeg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7927, v_7928, v_7929, v_7930;
    LispObject fn;
    LispObject v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "removeg2");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7712,v_7713,v_7714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_7714;
    stack[-4] = v_7713;
    stack[-5] = v_7712;
// end of prologue
    v_7927 = stack[-4];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    v_7928 = v_7927;
    goto v_7741;
v_7737:
    v_7927 = stack[-3];
    v_7929 = qcar(v_7927);
    goto v_7738;
v_7739:
    v_7927 = elt(env, 2); // g3
    goto v_7740;
v_7741:
    goto v_7737;
v_7738:
    goto v_7739;
v_7740:
    if (v_7929 == v_7927) goto v_7736;
    v_7927 = lisp_true;
    goto v_7734;
v_7736:
    goto v_7752;
v_7748:
    v_7929 = v_7928;
    goto v_7749;
v_7750:
    v_7927 = stack[-3];
    v_7927 = qcdr(v_7927);
    goto v_7751;
v_7752:
    goto v_7748;
v_7749:
    goto v_7750;
v_7751:
    v_7927 = Lmemq(nil, v_7929, v_7927);
    v_7927 = (v_7927 == nil ? lisp_true : nil);
    goto v_7734;
    v_7927 = nil;
v_7734:
    if (v_7927 == nil) goto v_7732;
    goto v_7768;
v_7760:
    v_7930 = elt(env, 3); // "Edge"
    goto v_7761;
v_7762:
    v_7929 = v_7928;
    goto v_7763;
v_7764:
    v_7928 = elt(env, 4); // "is absent in vertex"
    goto v_7765;
v_7766:
    v_7927 = stack[-3];
    goto v_7767;
v_7768:
    goto v_7760;
v_7761:
    goto v_7762;
v_7763:
    goto v_7764;
v_7765:
    goto v_7766;
v_7767:
    v_7927 = list4(v_7930, v_7929, v_7928, v_7927);
    env = stack[-7];
    fn = elt(env, 6); // cerror
    v_7927 = (*qfn1(fn))(fn, v_7927);
    env = stack[-7];
    goto v_7730;
v_7732:
    goto v_7780;
v_7776:
    v_7927 = stack[-3];
    goto v_7777;
v_7778:
    goto v_7779;
v_7780:
    goto v_7776;
v_7777:
    goto v_7778;
v_7779:
    fn = elt(env, 7); // revv0
    v_7927 = (*qfn2(fn))(fn, v_7927, v_7928);
    env = stack[-7];
    goto v_7730;
    v_7927 = nil;
v_7730:
    stack[-3] = v_7927;
    goto v_7788;
v_7784:
    v_7928 = stack[-3];
    goto v_7785;
v_7786:
    v_7927 = elt(env, 5); // qg
    goto v_7787;
v_7788:
    goto v_7784;
v_7785:
    goto v_7786;
v_7787:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7796;
v_7792:
    v_7927 = stack[-5];
    stack[0] = qcar(v_7927);
    goto v_7793;
v_7794:
    v_7927 = stack[-5];
    v_7927 = qcdr(v_7927);
    fn = elt(env, 8); // mkcopy
    v_7927 = (*qfn1(fn))(fn, v_7927);
    env = stack[-7];
    goto v_7795;
v_7796:
    goto v_7792;
v_7793:
    goto v_7794;
v_7795:
    v_7927 = cons(stack[0], v_7927);
    env = stack[-7];
    stack[-6] = v_7927;
    goto v_7806;
v_7802:
    v_7928 = stack[-4];
    goto v_7803;
v_7804:
    v_7927 = stack[-6];
    goto v_7805;
v_7806:
    goto v_7802;
v_7803:
    goto v_7804;
v_7805:
    v_7927 = Lmember(nil, v_7928, v_7927);
    v_7927 = qcar(v_7927);
    stack[-1] = v_7927;
    goto v_7815;
v_7811:
    v_7928 = stack[-3];
    goto v_7812;
v_7813:
    v_7927 = stack[-6];
    goto v_7814;
v_7815:
    goto v_7811;
v_7812:
    goto v_7813;
v_7814:
    v_7927 = Lmember(nil, v_7928, v_7927);
    v_7927 = qcar(v_7927);
    stack[0] = v_7927;
    v_7927 = stack[-4];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    stack[-2] = v_7927;
    goto v_7829;
v_7825:
    v_7927 = stack[-4];
    v_7927 = qcdr(v_7927);
    v_7928 = qcdr(v_7927);
    goto v_7826;
v_7827:
    v_7927 = stack[-4];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    goto v_7828;
v_7829:
    goto v_7825;
v_7826:
    goto v_7827;
v_7828:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7843;
v_7839:
    v_7927 = stack[-4];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7928 = qcdr(v_7927);
    goto v_7840;
v_7841:
    v_7927 = stack[-3];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    goto v_7842;
v_7843:
    goto v_7839;
v_7840:
    goto v_7841;
v_7842:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7857;
v_7853:
    v_7927 = stack[-3];
    v_7927 = qcdr(v_7927);
    v_7928 = qcdr(v_7927);
    goto v_7854;
v_7855:
    v_7927 = stack[-2];
    goto v_7856;
v_7857:
    goto v_7853;
v_7854:
    goto v_7855;
v_7856:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    v_7927 = stack[-1];
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    stack[-2] = v_7927;
    goto v_7870;
v_7866:
    v_7927 = stack[-1];
    v_7928 = qcdr(v_7927);
    goto v_7867;
v_7868:
    v_7927 = stack[-1];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    goto v_7869;
v_7870:
    goto v_7866;
v_7867:
    goto v_7868;
v_7869:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7883;
v_7879:
    v_7927 = stack[-1];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7928 = qcdr(v_7927);
    goto v_7880;
v_7881:
    v_7927 = stack[0];
    v_7927 = qcdr(v_7927);
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    goto v_7882;
v_7883:
    goto v_7879;
v_7880:
    goto v_7881;
v_7882:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7897;
v_7893:
    v_7927 = stack[0];
    v_7927 = qcdr(v_7927);
    v_7928 = qcdr(v_7927);
    goto v_7894;
v_7895:
    v_7927 = stack[0];
    v_7927 = qcdr(v_7927);
    v_7927 = qcar(v_7927);
    goto v_7896;
v_7897:
    goto v_7893;
v_7894:
    goto v_7895;
v_7896:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7909;
v_7905:
    v_7927 = stack[0];
    v_7928 = qcdr(v_7927);
    goto v_7906;
v_7907:
    v_7927 = stack[-2];
    goto v_7908;
v_7909:
    goto v_7905;
v_7906:
    goto v_7907;
v_7908:
    v_7927 = Lrplaca(nil, v_7928, v_7927);
    env = stack[-7];
    goto v_7920;
v_7914:
    stack[0] = stack[-5];
    goto v_7915;
v_7916:
    v_7927 = stack[-6];
    v_7927 = qcar(v_7927);
    fn = elt(env, 9); // negsq
    v_7928 = (*qfn1(fn))(fn, v_7927);
    goto v_7917;
v_7918:
    v_7927 = stack[-6];
    v_7927 = qcdr(v_7927);
    goto v_7919;
v_7920:
    goto v_7914;
v_7915:
    goto v_7916;
v_7917:
    goto v_7918;
v_7919:
    {
        LispObject v_7938 = stack[0];
        return list2star(v_7938, v_7928, v_7927);
    }
    return onevalue(v_7927);
}



// Code for cl_smsimpl!-junct

static LispObject CC_cl_smsimplKjunct(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7869, v_7870, v_7871, v_7872, v_7873, v_7874, v_7875;
    LispObject fn;
    LispObject v_7715, v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_smsimpl-junct");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    v_7715 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_7715,v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_7712,v_7713,v_7714,v_7715);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_7715;
    stack[-6] = v_7714;
    stack[0] = v_7713;
    stack[-7] = v_7712;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v_7869 = qvalue(elt(env, 2)); // !*rlsism
    if (v_7869 == nil) goto v_7727;
    else goto v_7728;
v_7727:
    goto v_7739;
v_7731:
    v_7872 = stack[0];
    goto v_7732;
v_7733:
    v_7871 = stack[-5];
    goto v_7734;
v_7735:
    v_7870 = stack[-7];
    goto v_7736;
v_7737:
    v_7869 = nil;
    goto v_7738;
v_7739:
    goto v_7731;
v_7732:
    goto v_7733;
v_7734:
    goto v_7735;
v_7736:
    goto v_7737;
v_7738:
    {
        fn = elt(env, 5); // cl_gand!-col
        return (*qfnn(fn))(fn, 4, v_7872, v_7871, v_7870, v_7869);
    }
v_7728:
    v_7869 = stack[-6];
    fn = elt(env, 6); // rl_smcpknowl
    v_7869 = (*qfn1(fn))(fn, v_7869);
    env = stack[-9];
    stack[-2] = v_7869;
    goto v_7751;
v_7747:
    v_7871 = elt(env, 3); // false
    goto v_7748;
v_7749:
    goto v_7757;
v_7753:
    v_7870 = stack[-7];
    goto v_7754;
v_7755:
    v_7869 = elt(env, 4); // and
    goto v_7756;
v_7757:
    goto v_7753;
v_7754:
    goto v_7755;
v_7756:
    v_7869 = (v_7870 == v_7869 ? lisp_true : nil);
    goto v_7750;
v_7751:
    goto v_7747;
v_7748:
    goto v_7749;
v_7750:
    fn = elt(env, 7); // cl_cflip
    v_7869 = (*qfn2(fn))(fn, v_7871, v_7869);
    env = stack[-9];
    stack[-8] = v_7869;
    v_7869 = stack[0];
    stack[-1] = v_7869;
v_7764:
    v_7869 = stack[-1];
    if (v_7869 == nil) goto v_7768;
    else goto v_7769;
v_7768:
    goto v_7763;
v_7769:
    v_7869 = stack[-1];
    v_7869 = qcar(v_7869);
    stack[0] = v_7869;
    v_7869 = stack[0];
    fn = elt(env, 8); // cl_atfp
    v_7869 = (*qfn1(fn))(fn, v_7869);
    env = stack[-9];
    if (v_7869 == nil) goto v_7778;
    goto v_7786;
v_7782:
    v_7870 = stack[0];
    goto v_7783;
v_7784:
    v_7869 = stack[-7];
    goto v_7785;
v_7786:
    goto v_7782;
v_7783:
    goto v_7784;
v_7785:
    fn = elt(env, 9); // cl_simplat
    v_7869 = (*qfn2(fn))(fn, v_7870, v_7869);
    env = stack[-9];
    goto v_7776;
v_7778:
    v_7869 = stack[0];
    goto v_7776;
    v_7869 = nil;
v_7776:
    stack[0] = v_7869;
    v_7869 = stack[0];
    fn = elt(env, 8); // cl_atfp
    v_7869 = (*qfn1(fn))(fn, v_7869);
    env = stack[-9];
    if (v_7869 == nil) goto v_7795;
    goto v_7803;
v_7799:
    v_7870 = stack[0];
    goto v_7800;
v_7801:
    v_7869 = stack[-4];
    goto v_7802;
v_7803:
    goto v_7799;
v_7800:
    goto v_7801;
v_7802:
    v_7869 = cons(v_7870, v_7869);
    env = stack[-9];
    stack[-4] = v_7869;
    goto v_7793;
v_7795:
    goto v_7813;
v_7809:
    v_7870 = stack[0];
    goto v_7810;
v_7811:
    v_7869 = stack[-3];
    goto v_7812;
v_7813:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    v_7869 = cons(v_7870, v_7869);
    env = stack[-9];
    stack[-3] = v_7869;
    goto v_7793;
v_7793:
    v_7869 = stack[-1];
    v_7869 = qcdr(v_7869);
    stack[-1] = v_7869;
    goto v_7764;
v_7763:
    goto v_7827;
v_7819:
    v_7872 = stack[-7];
    goto v_7820;
v_7821:
    v_7871 = stack[-4];
    goto v_7822;
v_7823:
    v_7870 = stack[-2];
    goto v_7824;
v_7825:
    v_7869 = stack[-5];
    goto v_7826;
v_7827:
    goto v_7819;
v_7820:
    goto v_7821;
v_7822:
    goto v_7823;
v_7824:
    goto v_7825;
v_7826:
    fn = elt(env, 10); // rl_smupdknowl
    v_7869 = (*qfnn(fn))(fn, 4, v_7872, v_7871, v_7870, v_7869);
    env = stack[-9];
    stack[-2] = v_7869;
    goto v_7840;
v_7836:
    v_7870 = stack[-2];
    goto v_7837;
v_7838:
    v_7869 = elt(env, 3); // false
    goto v_7839;
v_7840:
    goto v_7836;
v_7837:
    goto v_7838;
v_7839:
    if (v_7870 == v_7869) goto v_7834;
    else goto v_7835;
v_7834:
    v_7869 = stack[-8];
    return ncons(v_7869);
v_7835:
    goto v_7860;
v_7846:
    v_7875 = stack[-7];
    goto v_7847;
v_7848:
    v_7874 = stack[-4];
    goto v_7849;
v_7850:
    v_7869 = stack[-3];
    v_7873 = Lnreverse(nil, v_7869);
    env = stack[-9];
    goto v_7851;
v_7852:
    v_7872 = stack[-6];
    goto v_7853;
v_7854:
    v_7871 = stack[-2];
    goto v_7855;
v_7856:
    v_7870 = stack[-5];
    goto v_7857;
v_7858:
    v_7869 = stack[-8];
    goto v_7859;
v_7860:
    goto v_7846;
v_7847:
    goto v_7848;
v_7849:
    goto v_7850;
v_7851:
    goto v_7852;
v_7853:
    goto v_7854;
v_7855:
    goto v_7856;
v_7857:
    goto v_7858;
v_7859:
    {
        fn = elt(env, 11); // cl_smsimpl!-junct1
        return (*qfnn(fn))(fn, 7, v_7875, v_7874, v_7873, v_7872, v_7871, v_7870, v_7869);
    }
    return onevalue(v_7869);
}



// Code for chknewnam

static LispObject CC_chknewnam(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7748, v_7749, v_7750, v_7751;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7750 = v_7712;
// end of prologue
v_7711:
    v_7748 = v_7750;
    if (!symbolp(v_7748)) v_7748 = nil;
    else { v_7748 = qfastgets(v_7748);
           if (v_7748 != nil) { v_7748 = elt(v_7748, 28); // newnam
#ifdef RECORD_GET
             if (v_7748 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v_7748 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v_7748 == SPID_NOPROP) v_7748 = nil; }}
#endif
    v_7751 = v_7748;
    if (v_7748 == nil) goto v_7724;
    else goto v_7725;
v_7724:
    v_7748 = lisp_true;
    goto v_7723;
v_7725:
    goto v_7735;
v_7731:
    v_7749 = v_7751;
    goto v_7732;
v_7733:
    v_7748 = v_7750;
    goto v_7734;
v_7735:
    goto v_7731;
v_7732:
    goto v_7733;
v_7734:
    v_7748 = (v_7749 == v_7748 ? lisp_true : nil);
    goto v_7723;
    v_7748 = nil;
v_7723:
    if (v_7748 == nil) goto v_7721;
    v_7748 = v_7750;
    goto v_7719;
v_7721:
    v_7748 = v_7751;
    if (symbolp(v_7748)) goto v_7740;
    else goto v_7741;
v_7740:
    v_7748 = v_7751;
    v_7750 = v_7748;
    goto v_7711;
v_7741:
    v_7748 = v_7751;
    goto v_7719;
    v_7748 = nil;
v_7719:
    return onevalue(v_7748);
}



// Code for sq2sscfpl

static LispObject CC_sq2sscfpl(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7772, v_7773;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    v_7772 = stack[-1];
    if (v_7772 == nil) goto v_7717;
    else goto v_7718;
v_7717:
    v_7772 = nil;
    goto v_7716;
v_7718:
    v_7772 = stack[-1];
    if (!consp(v_7772)) goto v_7725;
    else goto v_7726;
v_7725:
    v_7772 = lisp_true;
    goto v_7724;
v_7726:
    v_7772 = stack[-1];
    v_7772 = qcar(v_7772);
    v_7772 = (consp(v_7772) ? nil : lisp_true);
    goto v_7724;
    v_7772 = nil;
v_7724:
    if (v_7772 == nil) goto v_7722;
    goto v_7740;
v_7736:
    v_7772 = stack[0];
    v_7772 = qcdr(v_7772);
    v_7772 = add1(v_7772);
    env = stack[-3];
    fn = elt(env, 1); // mkzl
    v_7773 = (*qfn1(fn))(fn, v_7772);
    env = stack[-3];
    goto v_7737;
v_7738:
    v_7772 = stack[-1];
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    v_7772 = cons(v_7773, v_7772);
    return ncons(v_7772);
v_7722:
    goto v_7753;
v_7749:
    goto v_7759;
v_7755:
    v_7772 = stack[-1];
    v_7773 = qcar(v_7772);
    goto v_7756;
v_7757:
    v_7772 = stack[0];
    goto v_7758;
v_7759:
    goto v_7755;
v_7756:
    goto v_7757;
v_7758:
    fn = elt(env, 2); // sq2sstm
    stack[-2] = (*qfn2(fn))(fn, v_7773, v_7772);
    env = stack[-3];
    goto v_7750;
v_7751:
    goto v_7768;
v_7764:
    v_7772 = stack[-1];
    v_7773 = qcdr(v_7772);
    goto v_7765;
v_7766:
    v_7772 = stack[0];
    goto v_7767;
v_7768:
    goto v_7764;
v_7765:
    goto v_7766;
v_7767:
    v_7772 = CC_sq2sscfpl(elt(env, 0), v_7773, v_7772);
    goto v_7752;
v_7753:
    goto v_7749;
v_7750:
    goto v_7751;
v_7752:
    {
        LispObject v_7777 = stack[-2];
        return Lappend(nil, v_7777, v_7772);
    }
    v_7772 = nil;
v_7716:
    return onevalue(v_7772);
}



// Code for ofsf_pow2q

static LispObject CC_ofsf_pow2q(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7740, v_7741, v_7742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7740 = v_7713;
    v_7741 = v_7712;
// end of prologue
    goto v_7722;
v_7716:
    goto v_7728;
v_7724:
    goto v_7734;
v_7730:
    goto v_7731;
v_7732:
    goto v_7733;
v_7734:
    goto v_7730;
v_7731:
    goto v_7732;
v_7733:
    fn = elt(env, 1); // to
    v_7741 = (*qfn2(fn))(fn, v_7741, v_7740);
    env = stack[0];
    goto v_7725;
v_7726:
    v_7740 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7727;
v_7728:
    goto v_7724;
v_7725:
    goto v_7726;
v_7727:
    v_7742 = cons(v_7741, v_7740);
    goto v_7717;
v_7718:
    v_7741 = nil;
    goto v_7719;
v_7720:
    v_7740 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7721;
v_7722:
    goto v_7716;
v_7717:
    goto v_7718;
v_7719:
    goto v_7720;
v_7721:
    return acons(v_7742, v_7741, v_7740);
}



// Code for sc_minussq

static LispObject CC_sc_minussq(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7717 = v_7712;
// end of prologue
    v_7717 = qcar(v_7717);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_7717);
    }
}



// Code for mksgnsq

static LispObject CC_mksgnsq(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7764, v_7765, v_7766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7765 = v_7712;
// end of prologue
    v_7764 = v_7765;
    fn = elt(env, 1); // evenfree
    v_7764 = (*qfn1(fn))(fn, v_7764);
    env = stack[-1];
    v_7765 = v_7764;
    if (v_7764 == nil) goto v_7716;
    else goto v_7717;
v_7716:
    goto v_7725;
v_7721:
    v_7765 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7722;
v_7723:
    v_7764 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7724;
v_7725:
    goto v_7721;
v_7722:
    goto v_7723;
v_7724:
    return cons(v_7765, v_7764);
v_7717:
    goto v_7734;
v_7730:
    v_7766 = v_7765;
    goto v_7731;
v_7732:
    v_7764 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7733;
v_7734:
    goto v_7730;
v_7731:
    goto v_7732;
v_7733:
    if (v_7766 == v_7764) goto v_7728;
    else goto v_7729;
v_7728:
    goto v_7742;
v_7738:
    v_7765 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7739;
v_7740:
    v_7764 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7741;
v_7742:
    goto v_7738;
v_7739:
    goto v_7740;
v_7741:
    return cons(v_7765, v_7764);
v_7729:
    goto v_7753;
v_7749:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7750;
v_7751:
    goto v_7761;
v_7757:
    goto v_7758;
v_7759:
    v_7764 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7760;
v_7761:
    goto v_7757;
v_7758:
    goto v_7759;
v_7760:
    v_7764 = cons(v_7765, v_7764);
    env = stack[-1];
    fn = elt(env, 2); // mk!*sq
    v_7764 = (*qfn1(fn))(fn, v_7764);
    env = stack[-1];
    goto v_7752;
v_7753:
    goto v_7749;
v_7750:
    goto v_7751;
v_7752:
    v_7764 = list2(stack[0], v_7764);
    env = stack[-1];
    {
        fn = elt(env, 3); // simpexpt
        return (*qfn1(fn))(fn, v_7764);
    }
    v_7764 = nil;
    return onevalue(v_7764);
}



// Code for set!-ordp

static LispObject CC_setKordp(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7741, v_7742, v_7743;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7742 = v_7713;
    v_7743 = v_7712;
// end of prologue
    v_7741 = v_7743;
    if (is_number(v_7741)) goto v_7719;
    else goto v_7718;
v_7719:
    v_7741 = v_7742;
    if (is_number(v_7741)) goto v_7721;
    else goto v_7718;
v_7721:
    goto v_7728;
v_7724:
    v_7741 = v_7743;
    goto v_7725;
v_7726:
    goto v_7727;
v_7728:
    goto v_7724;
v_7725:
    goto v_7726;
v_7727:
        return Llessp(nil, v_7741, v_7742);
v_7718:
    goto v_7738;
v_7734:
    v_7741 = v_7743;
    goto v_7735;
v_7736:
    goto v_7737;
v_7738:
    goto v_7734;
v_7735:
    goto v_7736;
v_7737:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_7741, v_7742);
    }
    v_7741 = nil;
    return onevalue(v_7741);
}



// Code for !*kp2f

static LispObject CC_Hkp2f(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7739, v_7740;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    goto v_7724;
v_7720:
    v_7740 = stack[0];
    goto v_7721;
v_7722:
    v_7739 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7723;
v_7724:
    goto v_7720;
v_7721:
    goto v_7722;
v_7723:
    v_7739 = (LispObject)greaterp2(v_7740, v_7739);
    v_7739 = v_7739 ? lisp_true : nil;
    env = stack[-2];
    if (v_7739 == nil) goto v_7718;
    goto v_7732;
v_7728:
    v_7740 = stack[-1];
    goto v_7729;
v_7730:
    v_7739 = stack[0];
    goto v_7731;
v_7732:
    goto v_7728;
v_7729:
    goto v_7730;
v_7731:
    fn = elt(env, 1); // mksq
    v_7739 = (*qfn2(fn))(fn, v_7740, v_7739);
    v_7739 = qcar(v_7739);
    goto v_7716;
v_7718:
    v_7739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7716;
    v_7739 = nil;
v_7716:
    return onevalue(v_7739);
}



// Code for rnconc

static LispObject CC_rnconc(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7768, v_7769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    v_7768 = stack[-1];
    if (v_7768 == nil) goto v_7717;
    else goto v_7718;
v_7717:
    v_7768 = stack[0];
    goto v_7716;
v_7718:
    v_7768 = qvalue(elt(env, 1)); // !*ncmp
    if (v_7768 == nil) goto v_7722;
    v_7768 = stack[-1];
    fn = elt(env, 3); // noncomfp1
    v_7768 = (*qfn1(fn))(fn, v_7768);
    env = stack[-2];
    if (v_7768 == nil) goto v_7722;
    v_7768 = stack[0];
    fn = elt(env, 3); // noncomfp1
    v_7768 = (*qfn1(fn))(fn, v_7768);
    env = stack[-2];
    if (v_7768 == nil) goto v_7722;
    goto v_7737;
v_7733:
    v_7769 = stack[-1];
    goto v_7734;
v_7735:
    v_7768 = stack[0];
    goto v_7736;
v_7737:
    goto v_7733;
v_7734:
    goto v_7735;
v_7736:
    {
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_7769, v_7768);
    }
v_7722:
    v_7768 = stack[-1];
    v_7769 = v_7768;
v_7749:
    v_7768 = v_7769;
    v_7768 = qcdr(v_7768);
    if (v_7768 == nil) goto v_7752;
    else goto v_7753;
v_7752:
    goto v_7748;
v_7753:
    v_7768 = v_7769;
    v_7768 = qcdr(v_7768);
    v_7769 = v_7768;
    goto v_7749;
v_7748:
    goto v_7764;
v_7760:
    goto v_7761;
v_7762:
    v_7768 = stack[0];
    goto v_7763;
v_7764:
    goto v_7760;
v_7761:
    goto v_7762;
v_7763:
    v_7768 = Lrplacd(nil, v_7769, v_7768);
    v_7768 = stack[-1];
    goto v_7716;
    v_7768 = nil;
v_7716:
    return onevalue(v_7768);
}



// Code for mo_neworder

static LispObject CC_mo_neworder(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7727;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7727 = v_7712;
// end of prologue
    v_7727 = qcar(v_7727);
    fn = elt(env, 1); // mo!=shorten
    v_7727 = (*qfn1(fn))(fn, v_7727);
    env = stack[-1];
    goto v_7723;
v_7719:
    stack[0] = v_7727;
    goto v_7720;
v_7721:
    fn = elt(env, 2); // mo!=deglist
    v_7727 = (*qfn1(fn))(fn, v_7727);
    goto v_7722;
v_7723:
    goto v_7719;
v_7720:
    goto v_7721;
v_7722:
    {
        LispObject v_7729 = stack[0];
        return cons(v_7729, v_7727);
    }
}



// Code for pv_intequiv

static LispObject CC_pv_intequiv(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7725, v_7726;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7725 = v_7712;
// end of prologue
    v_7726 = v_7725;
    v_7726 = qcdr(v_7726);
    if (!consp(v_7726)) goto v_7716;
    else goto v_7717;
v_7716:
    v_7725 = qcdr(v_7725);
    goto v_7715;
v_7717:
    v_7725 = nil;
    goto v_7715;
    v_7725 = nil;
v_7715:
    return onevalue(v_7725);
}



// Code for use!-berlekamp

static LispObject CC_useKberlekamp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8070, v_8071, v_8072, v_8073, v_8074, v_8075, v_8076;
    LispObject fn;
    LispObject v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "use-berlekamp");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7712,v_7713,v_7714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_7714;
    stack[-5] = v_7713;
    stack[-6] = v_7712;
// end of prologue
    v_8070 = qvalue(elt(env, 2)); // dpoly
    v_8070 = (LispObject)((intptr_t)(v_8070) - 0x10);
    stack[-3] = v_8070;
    v_8070 = stack[-3];
    v_8070 = Lmkvect(nil, v_8070);
    env = stack[-8];
    stack[-7] = v_8070;
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_8070;
v_7731:
    goto v_7741;
v_7737:
    v_8071 = stack[-3];
    goto v_7738;
v_7739:
    v_8070 = stack[0];
    goto v_7740;
v_7741:
    goto v_7737;
v_7738:
    goto v_7739;
v_7740:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7736;
    goto v_7730;
v_7736:
    v_8070 = stack[-3];
    v_8070 = Lmkvect(nil, v_8070);
    env = stack[-8];
    v_8074 = v_8070;
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    v_8073 = v_8070;
v_7752:
    goto v_7762;
v_7758:
    v_8071 = stack[-3];
    goto v_7759;
v_7760:
    v_8070 = v_8073;
    goto v_7761;
v_7762:
    goto v_7758;
v_7759:
    goto v_7760;
v_7761:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7757;
    goto v_7751;
v_7757:
    goto v_7774;
v_7768:
    v_8072 = v_8074;
    goto v_7769;
v_7770:
    v_8071 = v_8073;
    goto v_7771;
v_7772:
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7773;
v_7774:
    goto v_7768;
v_7769:
    goto v_7770;
v_7771:
    goto v_7772;
v_7773:
    *(LispObject *)((char *)v_8072 + (CELL-TAG_VECTOR) + (((intptr_t)v_8071-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = v_8073;
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    v_8073 = v_8070;
    goto v_7752;
v_7751:
    goto v_7786;
v_7780:
    v_8071 = stack[-7];
    goto v_7781;
v_7782:
    v_8070 = stack[0];
    goto v_7783;
v_7784:
    v_8072 = v_8074;
    goto v_7785;
v_7786:
    goto v_7780;
v_7781:
    goto v_7782;
v_7783:
    goto v_7784;
v_7785:
    *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL))) = v_8072;
    v_8070 = stack[0];
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    stack[0] = v_8070;
    goto v_7731;
v_7730:
    goto v_7801;
v_7793:
    v_8073 = stack[-6];
    goto v_7794;
v_7795:
    v_8072 = stack[-5];
    goto v_7796;
v_7797:
    v_8071 = qvalue(elt(env, 3)); // poly!-vector
    goto v_7798;
v_7799:
    v_8070 = qvalue(elt(env, 2)); // dpoly
    goto v_7800;
v_7801:
    goto v_7793;
v_7794:
    goto v_7795;
v_7796:
    goto v_7797;
v_7798:
    goto v_7799;
v_7800:
    fn = elt(env, 5); // remainder!-in!-vector
    v_8070 = (*qfnn(fn))(fn, 4, v_8073, v_8072, v_8071, v_8070);
    env = stack[-8];
    stack[-5] = v_8070;
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_8070;
    v_8070 = stack[-3];
    v_8070 = Lmkvect(nil, v_8070);
    env = stack[-8];
    stack[-1] = v_8070;
    goto v_7815;
v_7809:
    v_8072 = stack[-1];
    goto v_7810;
v_7811:
    v_8071 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7812;
v_7813:
    v_8070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7814;
v_7815:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    goto v_7813;
v_7814:
    *(LispObject *)((char *)v_8072 + (CELL-TAG_VECTOR) + (((intptr_t)v_8071-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_8070;
v_7822:
    goto v_7832;
v_7828:
    v_8071 = stack[-3];
    goto v_7829;
v_7830:
    v_8070 = stack[0];
    goto v_7831;
v_7832:
    goto v_7828;
v_7829:
    goto v_7830;
v_7831:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7827;
    goto v_7821;
v_7827:
    goto v_7846;
v_7842:
    v_8071 = qvalue(elt(env, 4)); // current!-modulus
    goto v_7843;
v_7844:
    v_8070 = qvalue(elt(env, 2)); // dpoly
    goto v_7845;
v_7846:
    goto v_7842;
v_7843:
    goto v_7844;
v_7845:
    if (((intptr_t)(v_8071)) > ((intptr_t)(v_8070))) goto v_7840;
    else goto v_7841;
v_7840:
    goto v_7860;
v_7850:
    v_8074 = stack[-1];
    goto v_7851;
v_7852:
    v_8073 = stack[-2];
    goto v_7853;
v_7854:
    v_8072 = stack[-6];
    goto v_7855;
v_7856:
    v_8071 = stack[-5];
    goto v_7857;
v_7858:
    v_8070 = stack[-4];
    goto v_7859;
v_7860:
    goto v_7850;
v_7851:
    goto v_7852;
v_7853:
    goto v_7854;
v_7855:
    goto v_7856;
v_7857:
    goto v_7858;
v_7859:
    fn = elt(env, 6); // times!-in!-vector
    v_8070 = (*qfnn(fn))(fn, 5, v_8074, v_8073, v_8072, v_8071, v_8070);
    env = stack[-8];
    stack[-2] = v_8070;
    goto v_7839;
v_7841:
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    v_8073 = v_8070;
v_7871:
    goto v_7881;
v_7877:
    v_8070 = qvalue(elt(env, 4)); // current!-modulus
    v_8071 = (LispObject)((intptr_t)(v_8070) - 0x10);
    goto v_7878;
v_7879:
    v_8070 = v_8073;
    goto v_7880;
v_7881:
    goto v_7877;
v_7878:
    goto v_7879;
v_7880:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7876;
    goto v_7870;
v_7876:
    goto v_7894;
v_7888:
    v_8072 = stack[-4];
    goto v_7889;
v_7890:
    v_8071 = v_8073;
    goto v_7891;
v_7892:
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7893;
v_7894:
    goto v_7888;
v_7889:
    goto v_7890;
v_7891:
    goto v_7892;
v_7893:
    *(LispObject *)((char *)v_8072 + (CELL-TAG_VECTOR) + (((intptr_t)v_8071-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = v_8073;
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    v_8073 = v_8070;
    goto v_7871;
v_7870:
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    v_8074 = v_8070;
v_7903:
    goto v_7913;
v_7909:
    v_8071 = stack[-2];
    goto v_7910;
v_7911:
    v_8070 = v_8074;
    goto v_7912;
v_7913:
    goto v_7909;
v_7910:
    goto v_7911;
v_7912:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7908;
    goto v_7902;
v_7908:
    goto v_7925;
v_7919:
    v_8073 = stack[-4];
    goto v_7920;
v_7921:
    goto v_7931;
v_7927:
    v_8071 = qvalue(elt(env, 4)); // current!-modulus
    goto v_7928;
v_7929:
    v_8070 = v_8074;
    goto v_7930;
v_7931:
    goto v_7927;
v_7928:
    goto v_7929;
v_7930:
    v_8072 = (LispObject)(intptr_t)((intptr_t)v_8071 + (intptr_t)v_8070 - TAG_FIXNUM);
    goto v_7922;
v_7923:
    goto v_7939;
v_7935:
    v_8071 = stack[-1];
    goto v_7936;
v_7937:
    v_8070 = v_8074;
    goto v_7938;
v_7939:
    goto v_7935;
v_7936:
    goto v_7937;
v_7938:
    v_8070 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_7924;
v_7925:
    goto v_7919;
v_7920:
    goto v_7921;
v_7922:
    goto v_7923;
v_7924:
    *(LispObject *)((char *)v_8073 + (CELL-TAG_VECTOR) + (((intptr_t)v_8072-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = v_8074;
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    v_8074 = v_8070;
    goto v_7903;
v_7902:
    goto v_7949;
v_7945:
    v_8071 = stack[-2];
    goto v_7946;
v_7947:
    v_8070 = qvalue(elt(env, 4)); // current!-modulus
    goto v_7948;
v_7949:
    goto v_7945;
v_7946:
    goto v_7947;
v_7948:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 + (intptr_t)v_8070 - TAG_FIXNUM);
    stack[-2] = v_8070;
    goto v_7839;
v_7839:
    goto v_7962;
v_7954:
    v_8073 = stack[-4];
    goto v_7955;
v_7956:
    v_8072 = stack[-2];
    goto v_7957;
v_7958:
    v_8071 = qvalue(elt(env, 3)); // poly!-vector
    goto v_7959;
v_7960:
    v_8070 = qvalue(elt(env, 2)); // dpoly
    goto v_7961;
v_7962:
    goto v_7954;
v_7955:
    goto v_7956;
v_7957:
    goto v_7958;
v_7959:
    goto v_7960;
v_7961:
    fn = elt(env, 5); // remainder!-in!-vector
    v_8070 = (*qfnn(fn))(fn, 4, v_8073, v_8072, v_8071, v_8070);
    env = stack[-8];
    stack[-2] = v_8070;
    v_8070 = (LispObject)0+TAG_FIXNUM; // 0
    v_8076 = v_8070;
v_7970:
    goto v_7980;
v_7976:
    v_8071 = stack[-2];
    goto v_7977;
v_7978:
    v_8070 = v_8076;
    goto v_7979;
v_7980:
    goto v_7976;
v_7977:
    goto v_7978;
v_7979:
    v_8070 = (LispObject)(intptr_t)((intptr_t)v_8071 - (intptr_t)v_8070 + TAG_FIXNUM);
    v_8070 = ((intptr_t)(v_8070) < 0 ? lisp_true : nil);
    if (v_8070 == nil) goto v_7975;
    goto v_7969;
v_7975:
    goto v_7992;
v_7986:
    goto v_7997;
v_7993:
    v_8071 = stack[-7];
    goto v_7994;
v_7995:
    v_8070 = v_8076;
    goto v_7996;
v_7997:
    goto v_7993;
v_7994:
    goto v_7995;
v_7996:
    v_8075 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_7987;
v_7988:
    v_8074 = stack[0];
    goto v_7989;
v_7990:
    goto v_8008;
v_8002:
    v_8073 = stack[-1];
    goto v_8003;
v_8004:
    v_8072 = v_8076;
    goto v_8005;
v_8006:
    goto v_8015;
v_8011:
    v_8071 = stack[-4];
    goto v_8012;
v_8013:
    v_8070 = v_8076;
    goto v_8014;
v_8015:
    goto v_8011;
v_8012:
    goto v_8013;
v_8014:
    v_8070 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_8007;
v_8008:
    goto v_8002;
v_8003:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    *(LispObject *)((char *)v_8073 + (CELL-TAG_VECTOR) + (((intptr_t)v_8072-TAG_FIXNUM)/(16/CELL))) = v_8070;
    goto v_7991;
v_7992:
    goto v_7986;
v_7987:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    *(LispObject *)((char *)v_8075 + (CELL-TAG_VECTOR) + (((intptr_t)v_8074-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = v_8076;
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    v_8076 = v_8070;
    goto v_7970;
v_7969:
    goto v_8027;
v_8021:
    goto v_8032;
v_8028:
    v_8071 = stack[-7];
    goto v_8029;
v_8030:
    v_8070 = stack[0];
    goto v_8031;
v_8032:
    goto v_8028;
v_8029:
    goto v_8030;
v_8031:
    v_8073 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_8022;
v_8023:
    v_8072 = stack[0];
    goto v_8024;
v_8025:
    goto v_8041;
v_8037:
    goto v_8046;
v_8042:
    goto v_8051;
v_8047:
    v_8071 = stack[-7];
    goto v_8048;
v_8049:
    v_8070 = stack[0];
    goto v_8050;
v_8051:
    goto v_8047;
v_8048:
    goto v_8049;
v_8050:
    v_8071 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_8043;
v_8044:
    v_8070 = stack[0];
    goto v_8045;
v_8046:
    goto v_8042;
v_8043:
    goto v_8044;
v_8045:
    v_8071 = *(LispObject *)((char *)v_8071 + (CELL-TAG_VECTOR) + (((intptr_t)v_8070-TAG_FIXNUM)/(16/CELL)));
    goto v_8038;
v_8039:
    v_8070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8040;
v_8041:
    goto v_8037;
v_8038:
    goto v_8039;
v_8040:
    {   intptr_t w = int_of_fixnum(v_8071) - int_of_fixnum(v_8070);
        if (w < 0) w += current_modulus;
        v_8070 = fixnum_of_int(w);
    }
    goto v_8026;
v_8027:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    goto v_8025;
v_8026:
    *(LispObject *)((char *)v_8073 + (CELL-TAG_VECTOR) + (((intptr_t)v_8072-TAG_FIXNUM)/(16/CELL))) = v_8070;
    v_8070 = stack[0];
    v_8070 = (LispObject)((intptr_t)(v_8070) + 0x10);
    stack[0] = v_8070;
    goto v_7822;
v_7821:
    goto v_8066;
v_8062:
    v_8071 = stack[-7];
    goto v_8063;
v_8064:
    v_8070 = stack[-3];
    goto v_8065;
v_8066:
    goto v_8062;
v_8063:
    goto v_8064;
v_8065:
    {
        fn = elt(env, 7); // find!-null!-space
        return (*qfn2(fn))(fn, v_8071, v_8070);
    }
    return onevalue(v_8070);
}



// Code for lalr_reduction_index

static LispObject CC_lalr_reduction_index(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7725, v_7726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7726 = v_7712;
// end of prologue
    goto v_7719;
v_7715:
    v_7725 = v_7726;
    stack[0] = qcdr(v_7725);
    goto v_7716;
v_7717:
    v_7725 = v_7726;
    v_7725 = qcar(v_7725);
    fn = elt(env, 1); // lalr_productions
    v_7725 = (*qfn1(fn))(fn, v_7725);
    env = stack[-1];
    goto v_7718;
v_7719:
    goto v_7715;
v_7716:
    goto v_7717;
v_7718:
    {
        LispObject v_7728 = stack[0];
        fn = elt(env, 2); // cdrassoc
        return (*qfn2(fn))(fn, v_7728, v_7725);
    }
}



// Code for aex_varl

static LispObject CC_aex_varl(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7718;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7718 = v_7712;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_7718 = (*qfn1(fn))(fn, v_7718);
    env = stack[0];
    v_7718 = qcar(v_7718);
    {
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(fn, v_7718);
    }
}



// Code for rempropss

static LispObject CC_rempropss(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7755, v_7756, v_7757, v_7758, v_7759, v_7760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7759 = v_7713;
    v_7755 = v_7712;
// end of prologue
    v_7760 = v_7755;
v_7718:
    v_7755 = v_7760;
    if (v_7755 == nil) goto v_7722;
    else goto v_7723;
v_7722:
    v_7755 = nil;
    goto v_7717;
v_7723:
    v_7755 = v_7760;
    v_7755 = qcar(v_7755);
    v_7758 = v_7755;
    v_7755 = v_7759;
    v_7757 = v_7755;
v_7732:
    v_7755 = v_7757;
    if (v_7755 == nil) goto v_7736;
    else goto v_7737;
v_7736:
    goto v_7731;
v_7737:
    v_7755 = v_7757;
    v_7755 = qcar(v_7755);
    goto v_7748;
v_7744:
    v_7756 = v_7758;
    goto v_7745;
v_7746:
    goto v_7747;
v_7748:
    goto v_7744;
v_7745:
    goto v_7746;
v_7747:
    v_7755 = Lremprop(nil, v_7756, v_7755);
    env = stack[0];
    v_7755 = v_7757;
    v_7755 = qcdr(v_7755);
    v_7757 = v_7755;
    goto v_7732;
v_7731:
    v_7755 = v_7760;
    v_7755 = qcdr(v_7755);
    v_7760 = v_7755;
    goto v_7718;
v_7717:
    return onevalue(v_7755);
}



// Code for ofsf_entry2at1

static LispObject CC_ofsf_entry2at1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7751, v_7752, v_7753;
    LispObject fn;
    LispObject v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at1");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7712,v_7713,v_7714);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7714;
    stack[-1] = v_7713;
    v_7751 = v_7712;
// end of prologue
    goto v_7723;
v_7717:
    goto v_7729;
v_7725:
    v_7752 = stack[-1];
    v_7753 = qcar(v_7752);
    goto v_7726;
v_7727:
    goto v_7736;
v_7732:
    v_7752 = v_7751;
    goto v_7733;
v_7734:
    v_7751 = elt(env, 1); // and
    goto v_7735;
v_7736:
    goto v_7732;
v_7733:
    goto v_7734;
v_7735:
    v_7751 = (v_7752 == v_7751 ? lisp_true : nil);
    goto v_7728;
v_7729:
    goto v_7725;
v_7726:
    goto v_7727;
v_7728:
    fn = elt(env, 2); // ofsf_clnegrel
    stack[-2] = (*qfn2(fn))(fn, v_7753, v_7751);
    env = stack[-3];
    goto v_7718;
v_7719:
    goto v_7745;
v_7741:
    v_7752 = stack[0];
    goto v_7742;
v_7743:
    v_7751 = stack[-1];
    v_7751 = qcdr(v_7751);
    goto v_7744;
v_7745:
    goto v_7741;
v_7742:
    goto v_7743;
v_7744:
    fn = elt(env, 3); // addsq
    v_7751 = (*qfn2(fn))(fn, v_7752, v_7751);
    v_7752 = qcar(v_7751);
    goto v_7720;
v_7721:
    v_7751 = nil;
    goto v_7722;
v_7723:
    goto v_7717;
v_7718:
    goto v_7719;
v_7720:
    goto v_7721;
v_7722:
    {
        LispObject v_7757 = stack[-2];
        return list3(v_7757, v_7752, v_7751);
    }
}



// Code for intexprlisp

static LispObject CC_intexprlisp(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7748, v_7749;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
v_7711:
    v_7748 = stack[-1];
    if (v_7748 == nil) goto v_7717;
    else goto v_7718;
v_7717:
    v_7748 = lisp_true;
    goto v_7716;
v_7718:
    goto v_7732;
v_7728:
    v_7748 = stack[-1];
    v_7749 = qcar(v_7748);
    goto v_7729;
v_7730:
    v_7748 = stack[0];
    goto v_7731;
v_7732:
    goto v_7728;
v_7729:
    goto v_7730;
v_7731:
    fn = elt(env, 1); // intexprnp
    v_7748 = (*qfn2(fn))(fn, v_7749, v_7748);
    env = stack[-2];
    if (v_7748 == nil) goto v_7725;
    else goto v_7726;
v_7725:
    v_7748 = nil;
    goto v_7724;
v_7726:
    goto v_7744;
v_7740:
    v_7748 = stack[-1];
    v_7749 = qcdr(v_7748);
    goto v_7741;
v_7742:
    v_7748 = stack[0];
    goto v_7743;
v_7744:
    goto v_7740;
v_7741:
    goto v_7742;
v_7743:
    stack[-1] = v_7749;
    stack[0] = v_7748;
    goto v_7711;
    v_7748 = nil;
v_7724:
    goto v_7716;
    v_7748 = nil;
v_7716:
    return onevalue(v_7748);
}



// Code for rl_simpbop

static LispObject CC_rl_simpbop(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7765, v_7766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_7766 = v_7712;
// end of prologue
    goto v_7719;
v_7715:
    v_7765 = v_7766;
    stack[-4] = qcar(v_7765);
    goto v_7716;
v_7717:
    v_7765 = v_7766;
    v_7765 = qcdr(v_7765);
    stack[-3] = v_7765;
    v_7765 = stack[-3];
    if (v_7765 == nil) goto v_7732;
    else goto v_7733;
v_7732:
    v_7765 = nil;
    goto v_7726;
v_7733:
    v_7765 = stack[-3];
    v_7765 = qcar(v_7765);
    fn = elt(env, 1); // rl_simp1
    v_7765 = (*qfn1(fn))(fn, v_7765);
    env = stack[-5];
    v_7765 = ncons(v_7765);
    env = stack[-5];
    stack[-1] = v_7765;
    stack[-2] = v_7765;
v_7727:
    v_7765 = stack[-3];
    v_7765 = qcdr(v_7765);
    stack[-3] = v_7765;
    v_7765 = stack[-3];
    if (v_7765 == nil) goto v_7746;
    else goto v_7747;
v_7746:
    v_7765 = stack[-2];
    goto v_7726;
v_7747:
    goto v_7755;
v_7751:
    stack[0] = stack[-1];
    goto v_7752;
v_7753:
    v_7765 = stack[-3];
    v_7765 = qcar(v_7765);
    fn = elt(env, 1); // rl_simp1
    v_7765 = (*qfn1(fn))(fn, v_7765);
    env = stack[-5];
    v_7765 = ncons(v_7765);
    env = stack[-5];
    goto v_7754;
v_7755:
    goto v_7751;
v_7752:
    goto v_7753;
v_7754:
    v_7765 = Lrplacd(nil, stack[0], v_7765);
    env = stack[-5];
    v_7765 = stack[-1];
    v_7765 = qcdr(v_7765);
    stack[-1] = v_7765;
    goto v_7727;
v_7726:
    goto v_7718;
v_7719:
    goto v_7715;
v_7716:
    goto v_7717;
v_7718:
    {
        LispObject v_7772 = stack[-4];
        return cons(v_7772, v_7765);
    }
}



// Code for gb_buch!-ev_divides!?

static LispObject CC_gb_buchKev_dividesW(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7723, v_7724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7724 = v_7713;
    v_7723 = v_7712;
// end of prologue
    goto v_7720;
v_7716:
    goto v_7717;
v_7718:
    goto v_7719;
v_7720:
    goto v_7716;
v_7717:
    goto v_7718;
v_7719:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_7724, v_7723);
    }
}



// Code for c!:subs2multf

static LispObject CC_cTsubs2multf(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7761, v_7762, v_7763;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7762 = v_7713;
    v_7763 = v_7712;
// end of prologue
    v_7761 = qvalue(elt(env, 1)); // !*sub2
// Binding !*sub2
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_7761; // !*sub2
    goto v_7723;
v_7719:
    goto v_7729;
v_7725:
    v_7761 = v_7763;
    goto v_7726;
v_7727:
    goto v_7728;
v_7729:
    goto v_7725;
v_7726:
    goto v_7727;
v_7728:
    fn = elt(env, 4); // multf
    v_7762 = (*qfn2(fn))(fn, v_7761, v_7762);
    env = stack[-1];
    goto v_7720;
v_7721:
    v_7761 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7722;
v_7723:
    goto v_7719;
v_7720:
    goto v_7721;
v_7722:
    v_7761 = cons(v_7762, v_7761);
    env = stack[-1];
    fn = elt(env, 5); // subs2
    v_7761 = (*qfn1(fn))(fn, v_7761);
    env = stack[-1];
    v_7763 = v_7761;
    goto v_7742;
v_7738:
    v_7761 = v_7763;
    v_7762 = qcdr(v_7761);
    goto v_7739;
v_7740:
    v_7761 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7741;
v_7742:
    goto v_7738;
v_7739:
    goto v_7740;
v_7741:
    if (v_7762 == v_7761) goto v_7737;
    goto v_7753;
v_7747:
    v_7763 = elt(env, 2); // matrix
    goto v_7748;
v_7749:
    v_7762 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_7750;
v_7751:
    v_7761 = elt(env, 3); // "Sub error in glnrsolve"
    goto v_7752;
v_7753:
    goto v_7747;
v_7748:
    goto v_7749;
v_7750:
    goto v_7751;
v_7752:
    fn = elt(env, 6); // rerror
    v_7761 = (*qfnn(fn))(fn, 3, v_7763, v_7762, v_7761);
    goto v_7735;
v_7737:
    v_7761 = v_7763;
    v_7761 = qcar(v_7761);
    goto v_7735;
    v_7761 = nil;
v_7735:
    ;}  // end of a binding scope
    return onevalue(v_7761);
}



// Code for lid

static LispObject CC_lid(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7724, v_7725;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7724 = v_7712;
// end of prologue
    v_7725 = v_7724;
    if (!consp(v_7725)) goto v_7716;
    else goto v_7717;
v_7716:
    goto v_7715;
v_7717:
    v_7724 = qcar(v_7724);
    goto v_7715;
    v_7724 = nil;
v_7715:
    return onevalue(v_7724);
}



// Code for physop!-multf

static LispObject CC_physopKmultf(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_8102, v_8103, v_8104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7713;
    stack[-2] = v_7712;
// end of prologue
    stack[-3] = nil;
v_7719:
    v_8102 = stack[-2];
    if (v_8102 == nil) goto v_7727;
    else goto v_7728;
v_7727:
    v_8102 = lisp_true;
    goto v_7726;
v_7728:
    v_8102 = stack[-1];
    v_8102 = (v_8102 == nil ? lisp_true : nil);
    goto v_7726;
    v_8102 = nil;
v_7726:
    if (v_8102 == nil) goto v_7724;
    v_8102 = nil;
    goto v_7718;
v_7724:
    goto v_7742;
v_7738:
    v_8103 = stack[-2];
    goto v_7739;
v_7740:
    v_8102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7741;
v_7742:
    goto v_7738;
v_7739:
    goto v_7740;
v_7741:
    if (v_8103 == v_8102) goto v_7736;
    else goto v_7737;
v_7736:
    v_8102 = stack[-1];
    goto v_7718;
v_7737:
    goto v_7752;
v_7748:
    v_8103 = stack[-1];
    goto v_7749;
v_7750:
    v_8102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7751;
v_7752:
    goto v_7748;
v_7749:
    goto v_7750;
v_7751:
    if (v_8103 == v_8102) goto v_7746;
    else goto v_7747;
v_7746:
    v_8102 = stack[-2];
    goto v_7718;
v_7747:
    v_8102 = stack[-2];
    if (!consp(v_8102)) goto v_7760;
    else goto v_7761;
v_7760:
    v_8102 = lisp_true;
    goto v_7759;
v_7761:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8102 = (consp(v_8102) ? nil : lisp_true);
    goto v_7759;
    v_8102 = nil;
v_7759:
    if (v_8102 == nil) goto v_7757;
    goto v_7774;
v_7770:
    v_8103 = stack[-2];
    goto v_7771;
v_7772:
    v_8102 = stack[-1];
    goto v_7773;
v_7774:
    goto v_7770;
v_7771:
    goto v_7772;
v_7773:
    {
        fn = elt(env, 9); // multd
        return (*qfn2(fn))(fn, v_8103, v_8102);
    }
v_7757:
    v_8102 = stack[-1];
    if (!consp(v_8102)) goto v_7781;
    else goto v_7782;
v_7781:
    v_8102 = lisp_true;
    goto v_7780;
v_7782:
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8102 = (consp(v_8102) ? nil : lisp_true);
    goto v_7780;
    v_8102 = nil;
v_7780:
    if (v_8102 == nil) goto v_7778;
    goto v_7795;
v_7791:
    v_8103 = stack[-1];
    goto v_7792;
v_7793:
    v_8102 = stack[-2];
    goto v_7794;
v_7795:
    goto v_7791;
v_7792:
    goto v_7793;
v_7794:
    {
        fn = elt(env, 9); // multd
        return (*qfn2(fn))(fn, v_8103, v_8102);
    }
v_7778:
    v_8102 = qvalue(elt(env, 2)); // !*exp
    if (v_8102 == nil) goto v_7800;
    else goto v_7799;
v_7800:
    v_8102 = qvalue(elt(env, 3)); // ncmp!*
    if (v_8102 == nil) goto v_7803;
    else goto v_7799;
v_7803:
    v_8102 = qvalue(elt(env, 4)); // wtl!*
    if (v_8102 == nil) goto v_7806;
    else goto v_7799;
v_7806:
    v_8102 = stack[-3];
    if (v_8102 == nil) goto v_7808;
    else goto v_7799;
v_7808:
    v_8102 = stack[-2];
    fn = elt(env, 10); // mkprod
    v_8102 = (*qfn1(fn))(fn, v_8102);
    env = stack[-4];
    stack[-2] = v_8102;
    v_8102 = stack[-1];
    fn = elt(env, 10); // mkprod
    v_8102 = (*qfn1(fn))(fn, v_8102);
    env = stack[-4];
    stack[-1] = v_8102;
    v_8102 = lisp_true;
    stack[-3] = v_8102;
    goto v_7719;
v_7799:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    stack[-3] = v_8102;
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    stack[0] = v_8102;
    v_8102 = stack[-1];
    fn = elt(env, 11); // noncomp2f
    v_8102 = (*qfn1(fn))(fn, v_8102);
    env = stack[-4];
    if (v_8102 == nil) goto v_7826;
    v_8102 = stack[-3];
    if (!consp(v_8102)) goto v_7834;
    else goto v_7835;
v_7834:
    v_8102 = stack[-3];
    if (!symbolp(v_8102)) v_8102 = nil;
    else { v_8102 = qfastgets(v_8102);
           if (v_8102 != nil) { v_8102 = elt(v_8102, 0); // noncom
#ifdef RECORD_GET
             if (v_8102 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8102 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8102 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8102 == SPID_NOPROP) v_8102 = nil; else v_8102 = lisp_true; }}
#endif
    goto v_7833;
v_7835:
    v_8102 = stack[-3];
    v_8102 = qcar(v_8102);
    if (!symbolp(v_8102)) v_8102 = nil;
    else { v_8102 = qfastgets(v_8102);
           if (v_8102 != nil) { v_8102 = elt(v_8102, 0); // noncom
#ifdef RECORD_GET
             if (v_8102 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8102 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8102 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8102 == SPID_NOPROP) v_8102 = nil; else v_8102 = lisp_true; }}
#endif
    goto v_7833;
    v_8102 = nil;
v_7833:
    if (v_8102 == nil) goto v_7831;
    else goto v_7830;
v_7831:
    v_8102 = qvalue(elt(env, 5)); // !*!*processed
    if (v_8102 == nil) goto v_7830;
    goto v_7826;
v_7830:
    goto v_7851;
v_7847:
    v_8103 = stack[-2];
    goto v_7848;
v_7849:
    v_8102 = stack[-1];
    goto v_7850;
v_7851:
    goto v_7847;
v_7848:
    goto v_7849;
v_7850:
    {
        fn = elt(env, 12); // physop!-multfnc
        return (*qfn2(fn))(fn, v_8103, v_8102);
    }
v_7826:
    goto v_7862;
v_7858:
    v_8103 = stack[-3];
    goto v_7859;
v_7860:
    v_8102 = stack[0];
    goto v_7861;
v_7862:
    goto v_7858;
v_7859:
    goto v_7860;
v_7861:
    fn = elt(env, 13); // physop!-ordop
    v_8102 = (*qfn2(fn))(fn, v_8103, v_8102);
    env = stack[-4];
    if (v_8102 == nil) goto v_7855;
    goto v_7870;
v_7866:
    v_8103 = stack[-3];
    goto v_7867;
v_7868:
    v_8102 = stack[0];
    goto v_7869;
v_7870:
    goto v_7866;
v_7867:
    goto v_7868;
v_7869:
    if (equal(v_8103, v_8102)) goto v_7855;
    goto v_7878;
v_7874:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8103 = qcdr(v_8102);
    goto v_7875;
v_7876:
    v_8102 = stack[-1];
    goto v_7877;
v_7878:
    goto v_7874;
v_7875:
    goto v_7876;
v_7877:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    env = stack[-4];
    stack[-3] = v_8102;
    goto v_7888;
v_7884:
    v_8102 = stack[-2];
    v_8103 = qcdr(v_8102);
    goto v_7885;
v_7886:
    v_8102 = stack[-1];
    goto v_7887;
v_7888:
    goto v_7884;
v_7885:
    goto v_7886;
v_7887:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    stack[0] = v_8102;
    v_8102 = stack[-3];
    if (v_8102 == nil) goto v_7894;
    else goto v_7895;
v_7894:
    v_8102 = stack[0];
    goto v_7893;
v_7895:
    goto v_7907;
v_7901:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8104 = qcar(v_8102);
    goto v_7902;
v_7903:
    v_8103 = stack[-3];
    goto v_7904;
v_7905:
    v_8102 = stack[0];
    goto v_7906;
v_7907:
    goto v_7901;
v_7902:
    goto v_7903;
v_7904:
    goto v_7905;
v_7906:
    return acons(v_8104, v_8103, v_8102);
    v_8102 = nil;
v_7893:
    goto v_7718;
v_7855:
    goto v_7923;
v_7919:
    v_8103 = stack[-3];
    goto v_7920;
v_7921:
    v_8102 = stack[0];
    goto v_7922;
v_7923:
    goto v_7919;
v_7920:
    goto v_7921;
v_7922:
    if (equal(v_8103, v_8102)) goto v_7917;
    else goto v_7918;
v_7917:
    v_8102 = stack[-3];
    fn = elt(env, 14); // physopp
    v_8102 = (*qfn1(fn))(fn, v_8102);
    env = stack[-4];
    if (v_8102 == nil) goto v_7928;
    else goto v_7929;
v_7928:
    v_8102 = lisp_true;
    goto v_7927;
v_7929:
    v_8102 = qvalue(elt(env, 6)); // !*contract2
    goto v_7927;
    v_8102 = nil;
v_7927:
    goto v_7916;
v_7918:
    v_8102 = nil;
    goto v_7916;
    v_8102 = nil;
v_7916:
    if (v_8102 == nil) goto v_7914;
    goto v_7944;
v_7940:
    stack[0] = stack[-3];
    goto v_7941;
v_7942:
    goto v_7951;
v_7947:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    v_8103 = qcdr(v_8102);
    goto v_7948;
v_7949:
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8102 = qcar(v_8102);
    v_8102 = qcdr(v_8102);
    goto v_7950;
v_7951:
    goto v_7947;
v_7948:
    goto v_7949;
v_7950:
    v_8102 = plus2(v_8103, v_8102);
    env = stack[-4];
    goto v_7943;
v_7944:
    goto v_7940;
v_7941:
    goto v_7942;
v_7943:
    fn = elt(env, 15); // mkspm
    v_8102 = (*qfn2(fn))(fn, stack[0], v_8102);
    env = stack[-4];
    stack[-3] = v_8102;
    goto v_7965;
v_7961:
    goto v_7971;
v_7967:
    v_8102 = stack[-2];
    v_8103 = qcdr(v_8102);
    goto v_7968;
v_7969:
    v_8102 = stack[-1];
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    stack[0] = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    env = stack[-4];
    goto v_7962;
v_7963:
    goto v_7980;
v_7976:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8103 = ncons(v_8102);
    env = stack[-4];
    goto v_7977;
v_7978:
    v_8102 = stack[-1];
    v_8102 = qcdr(v_8102);
    goto v_7979;
v_7980:
    goto v_7976;
v_7977:
    goto v_7978;
v_7979:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    env = stack[-4];
    goto v_7964;
v_7965:
    goto v_7961;
v_7962:
    goto v_7963;
v_7964:
    fn = elt(env, 16); // addf
    v_8102 = (*qfn2(fn))(fn, stack[0], v_8102);
    env = stack[-4];
    stack[0] = v_8102;
    v_8102 = stack[-3];
    if (v_8102 == nil) goto v_7992;
    else goto v_7993;
v_7992:
    v_8102 = lisp_true;
    goto v_7991;
v_7993:
    goto v_8003;
v_7999:
    v_8102 = stack[-2];
    v_8102 = qcar(v_8102);
    v_8103 = qcdr(v_8102);
    goto v_8000;
v_8001:
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8102 = qcdr(v_8102);
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    env = stack[-4];
    stack[-2] = v_8102;
    v_8102 = (v_8102 == nil ? lisp_true : nil);
    goto v_7991;
    v_8102 = nil;
v_7991:
    if (v_8102 == nil) goto v_7989;
    v_8102 = lisp_true;
    qvalue(elt(env, 7)) = v_8102; // !*asymp!*
    v_8102 = stack[0];
    goto v_7987;
v_7989:
    goto v_8019;
v_8015:
    v_8103 = stack[-3];
    goto v_8016;
v_8017:
    v_8102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8018;
v_8019:
    goto v_8015;
v_8016:
    goto v_8017;
v_8018:
    if (v_8103 == v_8102) goto v_8013;
    else goto v_8014;
v_8013:
    goto v_8027;
v_8023:
    v_8103 = stack[-2];
    goto v_8024;
v_8025:
    v_8102 = stack[0];
    goto v_8026;
v_8027:
    goto v_8023;
v_8024:
    goto v_8025;
v_8026:
    {
        fn = elt(env, 16); // addf
        return (*qfn2(fn))(fn, v_8103, v_8102);
    }
v_8014:
    v_8102 = qvalue(elt(env, 8)); // !*mcd
    if (v_8102 == nil) goto v_8030;
    else goto v_8031;
v_8030:
    goto v_8038;
v_8034:
    goto v_8045;
v_8041:
    v_8103 = stack[-3];
    goto v_8042;
v_8043:
    v_8102 = stack[-2];
    goto v_8044;
v_8045:
    goto v_8041;
v_8042:
    goto v_8043;
v_8044:
    v_8102 = cons(v_8103, v_8102);
    env = stack[-4];
    v_8103 = ncons(v_8102);
    env = stack[-4];
    goto v_8035;
v_8036:
    v_8102 = stack[0];
    goto v_8037;
v_8038:
    goto v_8034;
v_8035:
    goto v_8036;
v_8037:
    {
        fn = elt(env, 16); // addf
        return (*qfn2(fn))(fn, v_8103, v_8102);
    }
v_8031:
    goto v_8058;
v_8052:
    v_8104 = stack[-3];
    goto v_8053;
v_8054:
    v_8103 = stack[-2];
    goto v_8055;
v_8056:
    v_8102 = stack[0];
    goto v_8057;
v_8058:
    goto v_8052;
v_8053:
    goto v_8054;
v_8055:
    goto v_8056;
v_8057:
    return acons(v_8104, v_8103, v_8102);
    v_8102 = nil;
v_7987:
    goto v_7718;
v_7914:
    goto v_8067;
v_8063:
    v_8103 = stack[-2];
    goto v_8064;
v_8065:
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8102 = qcdr(v_8102);
    goto v_8066;
v_8067:
    goto v_8063;
v_8064:
    goto v_8065;
v_8066:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    env = stack[-4];
    stack[-3] = v_8102;
    goto v_8077;
v_8073:
    v_8103 = stack[-2];
    goto v_8074;
v_8075:
    v_8102 = stack[-1];
    v_8102 = qcdr(v_8102);
    goto v_8076;
v_8077:
    goto v_8073;
v_8074:
    goto v_8075;
v_8076:
    v_8102 = CC_physopKmultf(elt(env, 0), v_8103, v_8102);
    stack[0] = v_8102;
    v_8102 = stack[-3];
    if (v_8102 == nil) goto v_8083;
    else goto v_8084;
v_8083:
    v_8102 = stack[0];
    goto v_8082;
v_8084:
    goto v_8096;
v_8090:
    v_8102 = stack[-1];
    v_8102 = qcar(v_8102);
    v_8104 = qcar(v_8102);
    goto v_8091;
v_8092:
    v_8103 = stack[-3];
    goto v_8093;
v_8094:
    v_8102 = stack[0];
    goto v_8095;
v_8096:
    goto v_8090;
v_8091:
    goto v_8092;
v_8093:
    goto v_8094;
v_8095:
    return acons(v_8104, v_8103, v_8102);
    v_8102 = nil;
v_8082:
v_7718:
    return onevalue(v_8102);
}



// Code for defined_edge

static LispObject CC_defined_edge(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7746, v_7747, v_7748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7713;
    v_7748 = v_7712;
// end of prologue
    goto v_7722;
v_7718:
    v_7746 = v_7748;
    v_7747 = qcar(v_7746);
    goto v_7719;
v_7720:
    v_7746 = qvalue(elt(env, 1)); // old_edge_list
    goto v_7721;
v_7722:
    goto v_7718;
v_7719:
    goto v_7720;
v_7721:
    v_7746 = Lassoc(nil, v_7747, v_7746);
    if (v_7746 == nil) goto v_7717;
    else goto v_7716;
v_7717:
    goto v_7734;
v_7728:
    goto v_7740;
v_7736:
    v_7746 = v_7748;
    v_7747 = qcar(v_7746);
    goto v_7737;
v_7738:
    v_7746 = qvalue(elt(env, 2)); // new_edge_list
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    fn = elt(env, 3); // all_edge
    v_7748 = (*qfn2(fn))(fn, v_7747, v_7746);
    env = stack[-1];
    goto v_7729;
v_7730:
    v_7747 = nil;
    goto v_7731;
v_7732:
    v_7746 = stack[0];
    goto v_7733;
v_7734:
    goto v_7728;
v_7729:
    goto v_7730;
v_7731:
    goto v_7732;
v_7733:
    {
        fn = elt(env, 4); // defined_all_edge
        return (*qfnn(fn))(fn, 3, v_7748, v_7747, v_7746);
    }
v_7716:
    return onevalue(v_7746);
}



// Code for groeb!=better

static LispObject CC_groebMbetter(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7777, v_7778;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    goto v_7724;
v_7720:
    v_7777 = stack[-1];
    v_7777 = qcdr(v_7777);
    v_7778 = qcar(v_7777);
    goto v_7721;
v_7722:
    v_7777 = stack[0];
    v_7777 = qcdr(v_7777);
    v_7777 = qcar(v_7777);
    goto v_7723;
v_7724:
    goto v_7720;
v_7721:
    goto v_7722;
v_7723:
    v_7777 = (LispObject)lessp2(v_7778, v_7777);
    v_7777 = v_7777 ? lisp_true : nil;
    env = stack[-2];
    if (v_7777 == nil) goto v_7718;
    v_7777 = lisp_true;
    goto v_7716;
v_7718:
    goto v_7738;
v_7734:
    v_7777 = stack[-1];
    v_7777 = qcdr(v_7777);
    v_7778 = qcar(v_7777);
    goto v_7735;
v_7736:
    v_7777 = stack[0];
    v_7777 = qcdr(v_7777);
    v_7777 = qcar(v_7777);
    goto v_7737;
v_7738:
    goto v_7734;
v_7735:
    goto v_7736;
v_7737:
    if (equal(v_7778, v_7777)) goto v_7732;
    else goto v_7733;
v_7732:
    goto v_7750;
v_7746:
    goto v_7756;
v_7752:
    goto v_7762;
v_7758:
    v_7778 = stack[-1];
    goto v_7759;
v_7760:
    v_7777 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_7761;
v_7762:
    goto v_7758;
v_7759:
    goto v_7760;
v_7761:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_7778, v_7777);
    env = stack[-2];
    goto v_7753;
v_7754:
    goto v_7770;
v_7766:
    v_7778 = stack[0];
    goto v_7767;
v_7768:
    v_7777 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_7769;
v_7770:
    goto v_7766;
v_7767:
    goto v_7768;
v_7769:
    fn = elt(env, 1); // nth
    v_7777 = (*qfn2(fn))(fn, v_7778, v_7777);
    env = stack[-2];
    goto v_7755;
v_7756:
    goto v_7752;
v_7753:
    goto v_7754;
v_7755:
    fn = elt(env, 2); // mo_compare
    v_7778 = (*qfn2(fn))(fn, stack[-1], v_7777);
    goto v_7747;
v_7748:
    v_7777 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7749;
v_7750:
    goto v_7746;
v_7747:
    goto v_7748;
v_7749:
        return Lleq(nil, v_7778, v_7777);
v_7733:
    v_7777 = nil;
    goto v_7716;
    v_7777 = nil;
v_7716:
    return onevalue(v_7777);
}



// Code for ra_budan!-0!-1

static LispObject CC_ra_budanK0K1(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7794, v_7795;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_7795 = v_7712;
// end of prologue
    v_7794 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_7794;
    v_7794 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_7794;
    v_7794 = v_7795;
    fn = elt(env, 2); // ra_budan!-transform
    v_7794 = (*qfn1(fn))(fn, v_7794);
    env = stack[-4];
    stack[-3] = v_7794;
v_7729:
    v_7794 = stack[-3];
    if (v_7794 == nil) goto v_7732;
    else goto v_7733;
v_7732:
    goto v_7728;
v_7733:
    v_7794 = stack[-3];
    if (!consp(v_7794)) goto v_7742;
    else goto v_7743;
v_7742:
    v_7794 = lisp_true;
    goto v_7741;
v_7743:
    v_7794 = stack[-3];
    v_7794 = qcar(v_7794);
    v_7794 = (consp(v_7794) ? nil : lisp_true);
    goto v_7741;
    v_7794 = nil;
v_7741:
    if (v_7794 == nil) goto v_7739;
    v_7794 = stack[-3];
    v_7795 = v_7794;
    v_7794 = nil;
    stack[-3] = v_7794;
    goto v_7737;
v_7739:
    v_7794 = stack[-3];
    v_7794 = qcar(v_7794);
    v_7794 = qcdr(v_7794);
    v_7795 = v_7794;
    v_7794 = stack[-3];
    v_7794 = qcdr(v_7794);
    stack[-3] = v_7794;
    goto v_7737;
v_7737:
    v_7794 = v_7795;
    fn = elt(env, 3); // minusf
    v_7794 = (*qfn1(fn))(fn, v_7794);
    env = stack[-4];
    if (v_7794 == nil) goto v_7763;
    v_7794 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7761;
v_7763:
    v_7794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7761;
    v_7794 = nil;
v_7761:
    stack[-2] = v_7794;
    goto v_7779;
v_7775:
    goto v_7785;
v_7781:
    v_7795 = stack[-2];
    goto v_7782;
v_7783:
    v_7794 = stack[-1];
    goto v_7784;
v_7785:
    goto v_7781;
v_7782:
    goto v_7783;
v_7784:
    v_7795 = times2(v_7795, v_7794);
    env = stack[-4];
    goto v_7776;
v_7777:
    v_7794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7778;
v_7779:
    goto v_7775;
v_7776:
    goto v_7777;
v_7778:
    v_7794 = (LispObject)lessp2(v_7795, v_7794);
    v_7794 = v_7794 ? lisp_true : nil;
    env = stack[-4];
    if (v_7794 == nil) goto v_7773;
    v_7794 = stack[0];
    v_7794 = add1(v_7794);
    env = stack[-4];
    stack[0] = v_7794;
    goto v_7771;
v_7773:
v_7771:
    v_7794 = stack[-2];
    stack[-1] = v_7794;
    goto v_7729;
v_7728:
    v_7794 = stack[0];
    return onevalue(v_7794);
}



// Code for portable_prin

static LispObject CC_portable_prin(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7742, v_7743, v_7744, v_7745;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
// Binding !*ll!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // !*ll!*
    goto v_7723;
v_7719:
    v_7742 = nil;
    v_7743 = Llinelength(nil, v_7742);
    env = stack[-2];
    goto v_7720;
v_7721:
    v_7742 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7722;
v_7723:
    goto v_7719;
v_7720:
    goto v_7721;
v_7722:
    v_7742 = difference2(v_7743, v_7742);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_7742; // !*ll!*
    goto v_7736;
v_7728:
    v_7745 = stack[0];
    goto v_7729;
v_7730:
    v_7744 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7731;
v_7732:
    v_7743 = lisp_true;
    goto v_7733;
v_7734:
    v_7742 = nil;
    goto v_7735;
v_7736:
    goto v_7728;
v_7729:
    goto v_7730;
v_7731:
    goto v_7732;
v_7733:
    goto v_7734;
v_7735:
    fn = elt(env, 3); // p_prinl2
    v_7742 = (*qfnn(fn))(fn, 4, v_7745, v_7744, v_7743, v_7742);
    v_7742 = stack[0];
    ;}  // end of a binding scope
    return onevalue(v_7742);
}



// Code for polynommultiplybyvariable

static LispObject CC_polynommultiplybyvariable(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7827, v_7828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7713;
    stack[-2] = v_7712;
// end of prologue
    stack[-3] = nil;
    v_7827 = stack[-2];
    stack[0] = v_7827;
v_7723:
    v_7827 = stack[0];
    v_7827 = qcar(v_7827);
    if (v_7827 == nil) goto v_7726;
    else goto v_7727;
v_7726:
    goto v_7722;
v_7727:
    goto v_7740;
v_7736:
    goto v_7746;
v_7742:
    v_7827 = stack[0];
    v_7828 = qcar(v_7827);
    goto v_7743;
v_7744:
    v_7827 = stack[-1];
    goto v_7745;
v_7746:
    goto v_7742;
v_7743:
    goto v_7744;
v_7745:
    fn = elt(env, 2); // monomgetvariabledegree
    v_7828 = (*qfn2(fn))(fn, v_7828, v_7827);
    env = stack[-4];
    goto v_7737;
v_7738:
    v_7827 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    v_7827 = Leqn(nil, v_7828, v_7827);
    env = stack[-4];
    if (v_7827 == nil) goto v_7734;
    goto v_7756;
v_7752:
    v_7827 = stack[0];
    v_7828 = qcar(v_7827);
    goto v_7753;
v_7754:
    v_7827 = stack[-3];
    goto v_7755;
v_7756:
    goto v_7752;
v_7753:
    goto v_7754;
v_7755:
    v_7827 = cons(v_7828, v_7827);
    env = stack[-4];
    stack[-3] = v_7827;
    goto v_7765;
v_7761:
    goto v_7771;
v_7767:
    v_7828 = stack[0];
    goto v_7768;
v_7769:
    v_7827 = stack[0];
    v_7827 = qcdr(v_7827);
    v_7827 = qcar(v_7827);
    goto v_7770;
v_7771:
    goto v_7767;
v_7768:
    goto v_7769;
v_7770:
    v_7828 = Lrplaca(nil, v_7828, v_7827);
    env = stack[-4];
    goto v_7762;
v_7763:
    v_7827 = stack[0];
    v_7827 = qcdr(v_7827);
    v_7827 = qcdr(v_7827);
    goto v_7764;
v_7765:
    goto v_7761;
v_7762:
    goto v_7763;
v_7764:
    v_7827 = Lrplacd(nil, v_7828, v_7827);
    env = stack[-4];
    goto v_7732;
v_7734:
    v_7827 = stack[0];
    v_7827 = qcdr(v_7827);
    stack[0] = v_7827;
    goto v_7732;
v_7732:
    goto v_7723;
v_7722:
    goto v_7791;
v_7787:
    v_7828 = nil;
    goto v_7788;
v_7789:
    v_7827 = stack[-3];
    goto v_7790;
v_7791:
    goto v_7787;
v_7788:
    goto v_7789;
v_7790:
    v_7827 = cons(v_7828, v_7827);
    env = stack[-4];
    stack[-3] = v_7827;
    v_7827 = stack[-3];
    v_7827 = Lreverse(nil, v_7827);
    env = stack[-4];
    stack[-3] = v_7827;
    v_7827 = stack[-3];
    stack[0] = v_7827;
v_7799:
    v_7827 = stack[0];
    v_7827 = qcar(v_7827);
    if (v_7827 == nil) goto v_7802;
    else goto v_7803;
v_7802:
    goto v_7798;
v_7803:
    goto v_7812;
v_7808:
    v_7827 = stack[0];
    v_7828 = qcar(v_7827);
    goto v_7809;
v_7810:
    v_7827 = stack[-1];
    goto v_7811;
v_7812:
    goto v_7808;
v_7809:
    goto v_7810;
v_7811:
    fn = elt(env, 3); // monommultiplybyvariable
    v_7827 = (*qfn2(fn))(fn, v_7828, v_7827);
    env = stack[-4];
    v_7827 = stack[0];
    v_7827 = qcdr(v_7827);
    stack[0] = v_7827;
    goto v_7799;
v_7798:
    goto v_7824;
v_7820:
    v_7828 = stack[-2];
    goto v_7821;
v_7822:
    v_7827 = stack[-3];
    goto v_7823;
v_7824:
    goto v_7820;
v_7821:
    goto v_7822;
v_7823:
    fn = elt(env, 4); // polynomadd
    v_7827 = (*qfn2(fn))(fn, v_7828, v_7827);
    v_7827 = nil;
    return onevalue(v_7827);
}



// Code for kernord!-split

static LispObject CC_kernordKsplit(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7828, v_7829, v_7830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_7713;
    stack[-3] = v_7712;
// end of prologue
    stack[-4] = nil;
    stack[-1] = nil;
    v_7828 = stack[-3];
    fn = elt(env, 2); // powers
    v_7828 = (*qfn1(fn))(fn, v_7828);
    env = stack[-5];
    stack[-3] = v_7828;
    v_7828 = stack[-2];
    fn = elt(env, 2); // powers
    v_7828 = (*qfn1(fn))(fn, v_7828);
    env = stack[-5];
    stack[-2] = v_7828;
    v_7828 = stack[-3];
    stack[0] = v_7828;
v_7727:
    v_7828 = stack[0];
    if (v_7828 == nil) goto v_7731;
    else goto v_7732;
v_7731:
    goto v_7726;
v_7732:
    v_7828 = stack[0];
    v_7828 = qcar(v_7828);
    v_7830 = v_7828;
    goto v_7746;
v_7742:
    v_7828 = v_7830;
    v_7829 = qcar(v_7828);
    goto v_7743;
v_7744:
    v_7828 = stack[-2];
    goto v_7745;
v_7746:
    goto v_7742;
v_7743:
    goto v_7744;
v_7745:
    v_7828 = Lassoc(nil, v_7829, v_7828);
    if (v_7828 == nil) goto v_7741;
    goto v_7756;
v_7752:
    v_7829 = v_7830;
    goto v_7753;
v_7754:
    v_7828 = stack[-1];
    goto v_7755;
v_7756:
    goto v_7752;
v_7753:
    goto v_7754;
v_7755:
    v_7828 = cons(v_7829, v_7828);
    env = stack[-5];
    stack[-1] = v_7828;
    goto v_7739;
v_7741:
    goto v_7766;
v_7762:
    v_7829 = v_7830;
    goto v_7763;
v_7764:
    v_7828 = stack[-4];
    goto v_7765;
v_7766:
    goto v_7762;
v_7763:
    goto v_7764;
v_7765:
    v_7828 = cons(v_7829, v_7828);
    env = stack[-5];
    stack[-4] = v_7828;
    goto v_7739;
v_7739:
    v_7828 = stack[0];
    v_7828 = qcdr(v_7828);
    stack[0] = v_7828;
    goto v_7727;
v_7726:
    v_7828 = stack[-2];
    stack[0] = v_7828;
v_7774:
    v_7828 = stack[0];
    if (v_7828 == nil) goto v_7778;
    else goto v_7779;
v_7778:
    goto v_7773;
v_7779:
    v_7828 = stack[0];
    v_7828 = qcar(v_7828);
    v_7830 = v_7828;
    goto v_7793;
v_7789:
    v_7828 = v_7830;
    v_7829 = qcar(v_7828);
    goto v_7790;
v_7791:
    v_7828 = stack[-3];
    goto v_7792;
v_7793:
    goto v_7789;
v_7790:
    goto v_7791;
v_7792:
    v_7828 = Lassoc(nil, v_7829, v_7828);
    if (v_7828 == nil) goto v_7788;
    goto v_7803;
v_7799:
    v_7829 = v_7830;
    goto v_7800;
v_7801:
    v_7828 = stack[-1];
    goto v_7802;
v_7803:
    goto v_7799;
v_7800:
    goto v_7801;
v_7802:
    v_7828 = cons(v_7829, v_7828);
    env = stack[-5];
    stack[-1] = v_7828;
    goto v_7786;
v_7788:
    goto v_7813;
v_7809:
    v_7829 = v_7830;
    goto v_7810;
v_7811:
    v_7828 = stack[-4];
    goto v_7812;
v_7813:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    v_7828 = cons(v_7829, v_7828);
    env = stack[-5];
    stack[-4] = v_7828;
    goto v_7786;
v_7786:
    v_7828 = stack[0];
    v_7828 = qcdr(v_7828);
    stack[0] = v_7828;
    goto v_7774;
v_7773:
    goto v_7823;
v_7819:
    v_7828 = stack[-4];
    v_7829 = Lnreverse(nil, v_7828);
    env = stack[-5];
    goto v_7820;
v_7821:
    v_7828 = stack[-1];
    v_7828 = Lnreverse(nil, v_7828);
    goto v_7822;
v_7823:
    goto v_7819;
v_7820:
    goto v_7821;
v_7822:
    return cons(v_7829, v_7828);
    return onevalue(v_7828);
}



// Code for ibalp_simpatom

static LispObject CC_ibalp_simpatom(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7823, v_7824;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
    goto v_7730;
v_7726:
    v_7824 = stack[0];
    goto v_7727;
v_7728:
    v_7823 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7729;
v_7730:
    goto v_7726;
v_7727:
    goto v_7728;
v_7729:
    if (v_7824 == v_7823) goto v_7724;
    else goto v_7725;
v_7724:
    v_7823 = lisp_true;
    goto v_7723;
v_7725:
    goto v_7740;
v_7736:
    v_7824 = stack[0];
    goto v_7737;
v_7738:
    v_7823 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    v_7823 = (v_7824 == v_7823 ? lisp_true : nil);
    goto v_7723;
    v_7823 = nil;
v_7723:
    if (v_7823 == nil) goto v_7721;
    v_7823 = stack[0];
    goto v_7716;
v_7721:
    v_7823 = stack[0];
    if (symbolp(v_7823)) goto v_7747;
    else goto v_7748;
v_7747:
    v_7823 = stack[0];
    fn = elt(env, 7); // rl_gettype
    v_7823 = (*qfn1(fn))(fn, v_7823);
    env = stack[-1];
    if (v_7823 == nil) goto v_7753;
    v_7823 = stack[0];
    fn = elt(env, 8); // reval
    v_7823 = (*qfn1(fn))(fn, v_7823);
    env = stack[-1];
    {
        fn = elt(env, 9); // ibalp_simpterm
        return (*qfn1(fn))(fn, v_7823);
    }
v_7753:
    goto v_7764;
v_7760:
    v_7823 = stack[0];
    v_7824 = ncons(v_7823);
    env = stack[-1];
    goto v_7761;
v_7762:
    v_7823 = elt(env, 2); // used!*
    goto v_7763;
v_7764:
    goto v_7760;
v_7761:
    goto v_7762;
v_7763:
    v_7823 = Lflag(nil, v_7824, v_7823);
    v_7823 = stack[0];
    goto v_7716;
v_7748:
    v_7823 = stack[0];
    if (v_7823 == nil) goto v_7771;
    else goto v_7772;
v_7771:
    goto v_7779;
v_7775:
    v_7824 = elt(env, 3); // "nil"
    goto v_7776;
v_7777:
    v_7823 = elt(env, 4); // "Boolean term"
    goto v_7778;
v_7779:
    goto v_7775;
v_7776:
    goto v_7777;
v_7778:
    fn = elt(env, 10); // typerr
    v_7823 = (*qfn2(fn))(fn, v_7824, v_7823);
    env = stack[-1];
    goto v_7770;
v_7772:
v_7770:
    v_7823 = stack[0];
    if (is_number(v_7823)) goto v_7784;
    else goto v_7785;
v_7784:
    goto v_7792;
v_7788:
    goto v_7798;
v_7794:
    v_7824 = elt(env, 5); // "number"
    goto v_7795;
v_7796:
    v_7823 = stack[0];
    goto v_7797;
v_7798:
    goto v_7794;
v_7795:
    goto v_7796;
v_7797:
    v_7824 = list2(v_7824, v_7823);
    env = stack[-1];
    goto v_7789;
v_7790:
    v_7823 = elt(env, 4); // "Boolean term"
    goto v_7791;
v_7792:
    goto v_7788;
v_7789:
    goto v_7790;
v_7791:
    fn = elt(env, 10); // typerr
    v_7823 = (*qfn2(fn))(fn, v_7824, v_7823);
    env = stack[-1];
    goto v_7783;
v_7785:
v_7783:
    v_7823 = stack[0];
    v_7823 = Lstringp(nil, v_7823);
    env = stack[-1];
    if (v_7823 == nil) goto v_7805;
    goto v_7813;
v_7809:
    goto v_7819;
v_7815:
    v_7824 = elt(env, 6); // "string"
    goto v_7816;
v_7817:
    v_7823 = stack[0];
    goto v_7818;
v_7819:
    goto v_7815;
v_7816:
    goto v_7817;
v_7818:
    v_7824 = list2(v_7824, v_7823);
    env = stack[-1];
    goto v_7810;
v_7811:
    v_7823 = elt(env, 4); // "Boolean term"
    goto v_7812;
v_7813:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    fn = elt(env, 10); // typerr
    v_7823 = (*qfn2(fn))(fn, v_7824, v_7823);
    goto v_7803;
v_7805:
v_7803:
    v_7823 = nil;
v_7716:
    return onevalue(v_7823);
}



// Code for mathml2

static LispObject CC_mathml2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7719;
    LispObject fn;
    argcheck(nargs, 0, "mathml2");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    {
        fn = elt(env, 2); // sub_math
        return (*qfnn(fn))(fn, 0);
    }
    return onevalue(v_7719);
}



// Code for testredh

static LispObject CC_testredh(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7777, v_7778;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
    goto v_7723;
v_7719:
    goto v_7728;
v_7724:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_7725;
v_7726:
    goto v_7735;
v_7731:
    v_7778 = qvalue(elt(env, 2)); // maxvar
    goto v_7732;
v_7733:
    v_7777 = stack[0];
    goto v_7734;
v_7735:
    goto v_7731;
v_7732:
    goto v_7733;
v_7734:
    v_7777 = plus2(v_7778, v_7777);
    env = stack[-2];
    goto v_7727;
v_7728:
    goto v_7724;
v_7725:
    goto v_7726;
v_7727:
    v_7778 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_7777-TAG_FIXNUM)/(16/CELL)));
    goto v_7720;
v_7721:
    v_7777 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7722;
v_7723:
    goto v_7719;
v_7720:
    goto v_7721;
v_7722:
    v_7777 = *(LispObject *)((char *)v_7778 + (CELL-TAG_VECTOR) + (((intptr_t)v_7777-TAG_FIXNUM)/(16/CELL)));
    if (v_7777 == nil) goto v_7717;
    goto v_7747;
v_7743:
    goto v_7752;
v_7748:
    goto v_7757;
v_7753:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_7754;
v_7755:
    goto v_7764;
v_7760:
    v_7778 = qvalue(elt(env, 2)); // maxvar
    goto v_7761;
v_7762:
    v_7777 = stack[0];
    goto v_7763;
v_7764:
    goto v_7760;
v_7761:
    goto v_7762;
v_7763:
    v_7777 = plus2(v_7778, v_7777);
    env = stack[-2];
    goto v_7756;
v_7757:
    goto v_7753;
v_7754:
    goto v_7755;
v_7756:
    v_7778 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_7777-TAG_FIXNUM)/(16/CELL)));
    goto v_7749;
v_7750:
    v_7777 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7751;
v_7752:
    goto v_7748;
v_7749:
    goto v_7750;
v_7751:
    v_7777 = *(LispObject *)((char *)v_7778 + (CELL-TAG_VECTOR) + (((intptr_t)v_7777-TAG_FIXNUM)/(16/CELL)));
    v_7777 = qcar(v_7777);
    v_7778 = qcar(v_7777);
    goto v_7744;
v_7745:
    v_7777 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7746;
v_7747:
    goto v_7743;
v_7744:
    goto v_7745;
v_7746:
    v_7777 = (LispObject)lessp2(v_7778, v_7777);
    v_7777 = v_7777 ? lisp_true : nil;
    env = stack[-2];
    if (v_7777 == nil) goto v_7717;
    v_7777 = stack[0];
    fn = elt(env, 3); // rowdel
    v_7777 = (*qfn1(fn))(fn, v_7777);
    env = stack[-2];
    v_7777 = stack[0];
    {
        fn = elt(env, 4); // testredzz
        return (*qfn1(fn))(fn, v_7777);
    }
v_7717:
    v_7777 = nil;
    return onevalue(v_7777);
}



// Code for evenfree

static LispObject CC_evenfree(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7756, v_7757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
    v_7756 = stack[0];
    if (v_7756 == nil) goto v_7716;
    else goto v_7717;
v_7716:
    v_7756 = nil;
    goto v_7715;
v_7717:
    v_7756 = stack[0];
    if (is_number(v_7756)) goto v_7720;
    else goto v_7721;
v_7720:
    goto v_7729;
v_7725:
    v_7757 = stack[0];
    goto v_7726;
v_7727:
    v_7756 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7728;
v_7729:
    goto v_7725;
v_7726:
    goto v_7727;
v_7728:
    fn = elt(env, 1); // qremd
    v_7756 = (*qfn2(fn))(fn, v_7757, v_7756);
    env = stack[-2];
    v_7756 = qcdr(v_7756);
    {
        fn = elt(env, 2); // absf
        return (*qfn1(fn))(fn, v_7756);
    }
v_7721:
    goto v_7740;
v_7736:
    goto v_7747;
v_7743:
    v_7756 = stack[0];
    v_7756 = qcar(v_7756);
    v_7757 = ncons(v_7756);
    env = stack[-2];
    goto v_7744;
v_7745:
    v_7756 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7746;
v_7747:
    goto v_7743;
v_7744:
    goto v_7745;
v_7746:
    fn = elt(env, 1); // qremd
    v_7756 = (*qfn2(fn))(fn, v_7757, v_7756);
    env = stack[-2];
    v_7756 = qcdr(v_7756);
    fn = elt(env, 2); // absf
    stack[-1] = (*qfn1(fn))(fn, v_7756);
    env = stack[-2];
    goto v_7737;
v_7738:
    v_7756 = stack[0];
    v_7756 = qcdr(v_7756);
    v_7756 = CC_evenfree(elt(env, 0), v_7756);
    env = stack[-2];
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    {
        LispObject v_7760 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_7760, v_7756);
    }
    v_7756 = nil;
v_7715:
    return onevalue(v_7756);
}



// Code for aminusp!:1

static LispObject CC_aminuspT1(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7833, v_7834, v_7835, v_7836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7712;
// end of prologue
    v_7833 = stack[-1];
    fn = elt(env, 5); // aeval!*
    v_7833 = (*qfn1(fn))(fn, v_7833);
    env = stack[-3];
    stack[-1] = v_7833;
    v_7833 = stack[-1];
    stack[-2] = v_7833;
    v_7833 = stack[-2];
    v_7833 = integerp(v_7833);
    if (v_7833 == nil) goto v_7724;
    v_7833 = stack[-2];
        return Lminusp(nil, v_7833);
v_7724:
    goto v_7736;
v_7732:
    v_7834 = stack[-2];
    goto v_7733;
v_7734:
    v_7833 = elt(env, 2); // !*sq
    goto v_7735;
v_7736:
    goto v_7732;
v_7733:
    goto v_7734;
v_7735:
    if (!consp(v_7834)) goto v_7729;
    v_7834 = qcar(v_7834);
    if (v_7834 == v_7833) goto v_7730;
v_7729:
    goto v_7750;
v_7740:
    stack[0] = nil;
    goto v_7741;
v_7742:
    v_7833 = stack[-1];
    fn = elt(env, 6); // reval
    v_7836 = (*qfn1(fn))(fn, v_7833);
    env = stack[-3];
    goto v_7743;
v_7744:
    v_7835 = elt(env, 3); // "invalid in FOR statement"
    goto v_7745;
v_7746:
    v_7834 = nil;
    goto v_7747;
v_7748:
    v_7833 = lisp_true;
    goto v_7749;
v_7750:
    goto v_7740;
v_7741:
    goto v_7742;
v_7743:
    goto v_7744;
v_7745:
    goto v_7746;
v_7747:
    goto v_7748;
v_7749:
    fn = elt(env, 7); // msgpri
    v_7833 = (*qfnn(fn))(fn, 5, stack[0], v_7836, v_7835, v_7834, v_7833);
    env = stack[-3];
    goto v_7722;
v_7730:
v_7722:
    v_7833 = stack[-2];
    v_7833 = qcdr(v_7833);
    v_7833 = qcar(v_7833);
    stack[-2] = v_7833;
    v_7833 = stack[-2];
    v_7833 = qcar(v_7833);
    v_7833 = integerp(v_7833);
    if (v_7833 == nil) goto v_7763;
    v_7833 = stack[-2];
    v_7833 = qcdr(v_7833);
    v_7833 = integerp(v_7833);
    if (v_7833 == nil) goto v_7763;
    v_7833 = stack[-2];
    v_7833 = qcar(v_7833);
        return Lminusp(nil, v_7833);
v_7763:
    goto v_7785;
v_7781:
    v_7833 = stack[-2];
    v_7834 = qcdr(v_7833);
    goto v_7782;
v_7783:
    v_7833 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7784;
v_7785:
    goto v_7781;
v_7782:
    goto v_7783;
v_7784:
    if (v_7834 == v_7833) goto v_7780;
    v_7833 = lisp_true;
    goto v_7778;
v_7780:
    v_7833 = stack[-2];
    v_7833 = qcar(v_7833);
    stack[-2] = v_7833;
    if (!consp(v_7833)) goto v_7794;
    else goto v_7795;
v_7794:
    v_7833 = lisp_true;
    goto v_7793;
v_7795:
    v_7833 = stack[-2];
    v_7833 = qcar(v_7833);
    v_7833 = (consp(v_7833) ? nil : lisp_true);
    goto v_7793;
    v_7833 = nil;
v_7793:
    v_7833 = (v_7833 == nil ? lisp_true : nil);
    goto v_7778;
    v_7833 = nil;
v_7778:
    if (v_7833 == nil) goto v_7776;
    goto v_7816;
v_7806:
    stack[0] = nil;
    goto v_7807;
v_7808:
    v_7833 = stack[-1];
    fn = elt(env, 6); // reval
    v_7836 = (*qfn1(fn))(fn, v_7833);
    env = stack[-3];
    goto v_7809;
v_7810:
    v_7835 = elt(env, 3); // "invalid in FOR statement"
    goto v_7811;
v_7812:
    v_7834 = nil;
    goto v_7813;
v_7814:
    v_7833 = lisp_true;
    goto v_7815;
v_7816:
    goto v_7806;
v_7807:
    goto v_7808;
v_7809:
    goto v_7810;
v_7811:
    goto v_7812;
v_7813:
    goto v_7814;
v_7815:
    fn = elt(env, 7); // msgpri
    v_7833 = (*qfnn(fn))(fn, 5, stack[0], v_7836, v_7835, v_7834, v_7833);
    goto v_7761;
v_7776:
    goto v_7830;
v_7826:
    v_7834 = elt(env, 4); // !:minusp
    goto v_7827;
v_7828:
    v_7833 = stack[-2];
    goto v_7829;
v_7830:
    goto v_7826;
v_7827:
    goto v_7828;
v_7829:
        return Lapply1(nil, v_7834, v_7833);
v_7761:
    v_7833 = nil;
    return onevalue(v_7833);
}



// Code for general!-times!-mod!-p

static LispObject CC_generalKtimesKmodKp(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7930, v_7931, v_7932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    v_7930 = stack[-1];
    if (v_7930 == nil) goto v_7721;
    else goto v_7722;
v_7721:
    v_7930 = lisp_true;
    goto v_7720;
v_7722:
    v_7930 = stack[0];
    v_7930 = (v_7930 == nil ? lisp_true : nil);
    goto v_7720;
    v_7930 = nil;
v_7720:
    if (v_7930 == nil) goto v_7718;
    v_7930 = nil;
    goto v_7716;
v_7718:
    v_7930 = stack[-1];
    if (!consp(v_7930)) goto v_7734;
    else goto v_7735;
v_7734:
    v_7930 = lisp_true;
    goto v_7733;
v_7735:
    v_7930 = stack[-1];
    v_7930 = qcar(v_7930);
    v_7930 = (consp(v_7930) ? nil : lisp_true);
    goto v_7733;
    v_7930 = nil;
v_7733:
    if (v_7930 == nil) goto v_7731;
    goto v_7748;
v_7744:
    v_7931 = stack[0];
    goto v_7745;
v_7746:
    v_7930 = stack[-1];
    goto v_7747;
v_7748:
    goto v_7744;
v_7745:
    goto v_7746;
v_7747:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_7931, v_7930);
    }
v_7731:
    v_7930 = stack[0];
    if (!consp(v_7930)) goto v_7755;
    else goto v_7756;
v_7755:
    v_7930 = lisp_true;
    goto v_7754;
v_7756:
    v_7930 = stack[0];
    v_7930 = qcar(v_7930);
    v_7930 = (consp(v_7930) ? nil : lisp_true);
    goto v_7754;
    v_7930 = nil;
v_7754:
    if (v_7930 == nil) goto v_7752;
    goto v_7769;
v_7765:
    v_7931 = stack[-1];
    goto v_7766;
v_7767:
    v_7930 = stack[0];
    goto v_7768;
v_7769:
    goto v_7765;
v_7766:
    goto v_7767;
v_7768:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_7931, v_7930);
    }
v_7752:
    goto v_7778;
v_7774:
    v_7930 = stack[-1];
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    v_7931 = qcar(v_7930);
    goto v_7775;
v_7776:
    v_7930 = stack[0];
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    goto v_7777;
v_7778:
    goto v_7774;
v_7775:
    goto v_7776;
v_7777:
    if (equal(v_7931, v_7930)) goto v_7772;
    else goto v_7773;
v_7772:
    goto v_7792;
v_7788:
    goto v_7798;
v_7794:
    goto v_7804;
v_7800:
    v_7930 = stack[-1];
    v_7931 = qcar(v_7930);
    goto v_7801;
v_7802:
    v_7930 = stack[0];
    goto v_7803;
v_7804:
    goto v_7800;
v_7801:
    goto v_7802;
v_7803:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, v_7931, v_7930);
    env = stack[-3];
    goto v_7795;
v_7796:
    goto v_7813;
v_7809:
    v_7930 = stack[0];
    v_7931 = qcar(v_7930);
    goto v_7810;
v_7811:
    v_7930 = stack[-1];
    v_7930 = qcdr(v_7930);
    goto v_7812;
v_7813:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    v_7930 = (*qfn2(fn))(fn, v_7931, v_7930);
    env = stack[-3];
    goto v_7797;
v_7798:
    goto v_7794;
v_7795:
    goto v_7796;
v_7797:
    fn = elt(env, 3); // general!-plus!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_7930);
    env = stack[-3];
    goto v_7789;
v_7790:
    goto v_7823;
v_7819:
    v_7930 = stack[-1];
    v_7931 = qcdr(v_7930);
    goto v_7820;
v_7821:
    v_7930 = stack[0];
    v_7930 = qcdr(v_7930);
    goto v_7822;
v_7823:
    goto v_7819;
v_7820:
    goto v_7821;
v_7822:
    v_7930 = CC_generalKtimesKmodKp(elt(env, 0), v_7931, v_7930);
    env = stack[-3];
    goto v_7791;
v_7792:
    goto v_7788;
v_7789:
    goto v_7790;
v_7791:
    {
        LispObject v_7936 = stack[-2];
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_7936, v_7930);
    }
v_7773:
    goto v_7835;
v_7831:
    v_7930 = stack[-1];
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    v_7931 = qcar(v_7930);
    goto v_7832;
v_7833:
    v_7930 = stack[0];
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    v_7930 = qcar(v_7930);
    goto v_7834;
v_7835:
    goto v_7831;
v_7832:
    goto v_7833;
v_7834:
    fn = elt(env, 4); // ordop
    v_7930 = (*qfn2(fn))(fn, v_7931, v_7930);
    env = stack[-3];
    if (v_7930 == nil) goto v_7829;
    goto v_7849;
v_7845:
    v_7930 = stack[-1];
    v_7930 = qcar(v_7930);
    v_7931 = qcdr(v_7930);
    goto v_7846;
v_7847:
    v_7930 = stack[0];
    goto v_7848;
v_7849:
    goto v_7845;
v_7846:
    goto v_7847;
v_7848:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_7931, v_7930);
    env = stack[-3];
    goto v_7859;
v_7855:
    v_7930 = stack[-1];
    v_7931 = qcdr(v_7930);
    goto v_7856;
v_7857:
    v_7930 = stack[0];
    goto v_7858;
v_7859:
    goto v_7855;
v_7856:
    goto v_7857;
v_7858:
    v_7930 = CC_generalKtimesKmodKp(elt(env, 0), v_7931, v_7930);
    v_7931 = stack[-2];
    v_7932 = v_7931;
    if (v_7932 == nil) goto v_7867;
    else goto v_7868;
v_7867:
    goto v_7866;
v_7868:
    goto v_7880;
v_7874:
    v_7932 = stack[-1];
    v_7932 = qcar(v_7932);
    v_7932 = qcar(v_7932);
    goto v_7875;
v_7876:
    goto v_7877;
v_7878:
    goto v_7879;
v_7880:
    goto v_7874;
v_7875:
    goto v_7876;
v_7877:
    goto v_7878;
v_7879:
    return acons(v_7932, v_7931, v_7930);
    v_7930 = nil;
v_7866:
    goto v_7716;
v_7829:
    goto v_7893;
v_7889:
    v_7931 = stack[-1];
    goto v_7890;
v_7891:
    v_7930 = stack[0];
    v_7930 = qcar(v_7930);
    v_7930 = qcdr(v_7930);
    goto v_7892;
v_7893:
    goto v_7889;
v_7890:
    goto v_7891;
v_7892:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_7931, v_7930);
    env = stack[-3];
    goto v_7903;
v_7899:
    v_7931 = stack[-1];
    goto v_7900;
v_7901:
    v_7930 = stack[0];
    v_7930 = qcdr(v_7930);
    goto v_7902;
v_7903:
    goto v_7899;
v_7900:
    goto v_7901;
v_7902:
    v_7930 = CC_generalKtimesKmodKp(elt(env, 0), v_7931, v_7930);
    v_7931 = stack[-2];
    v_7932 = v_7931;
    if (v_7932 == nil) goto v_7911;
    else goto v_7912;
v_7911:
    goto v_7910;
v_7912:
    goto v_7924;
v_7918:
    v_7932 = stack[0];
    v_7932 = qcar(v_7932);
    v_7932 = qcar(v_7932);
    goto v_7919;
v_7920:
    goto v_7921;
v_7922:
    goto v_7923;
v_7924:
    goto v_7918;
v_7919:
    goto v_7920;
v_7921:
    goto v_7922;
v_7923:
    return acons(v_7932, v_7931, v_7930);
    v_7930 = nil;
v_7910:
    goto v_7716;
    v_7930 = nil;
v_7716:
    return onevalue(v_7930);
}



// Code for setk

static LispObject CC_setk(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7808, v_7809, v_7810;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7713;
    v_7809 = v_7712;
// end of prologue
    v_7808 = v_7809;
    if (!consp(v_7808)) goto v_7718;
    goto v_7725;
v_7721:
    v_7808 = v_7809;
    v_7810 = qcar(v_7808);
    goto v_7722;
v_7723:
    v_7808 = elt(env, 1); // evalargfn
    goto v_7724;
v_7725:
    goto v_7721;
v_7722:
    goto v_7723;
v_7724:
    v_7808 = get(v_7810, v_7808);
    env = stack[-2];
    v_7810 = v_7808;
    v_7808 = v_7810;
    if (v_7808 == nil) goto v_7733;
    goto v_7740;
v_7736:
    goto v_7746;
v_7742:
    v_7808 = v_7809;
    stack[-1] = qcar(v_7808);
    goto v_7743;
v_7744:
    goto v_7754;
v_7750:
    v_7808 = v_7810;
    goto v_7751;
v_7752:
    v_7809 = qcdr(v_7809);
    goto v_7753;
v_7754:
    goto v_7750;
v_7751:
    goto v_7752;
v_7753:
    v_7808 = Lapply1(nil, v_7808, v_7809);
    env = stack[-2];
    goto v_7745;
v_7746:
    goto v_7742;
v_7743:
    goto v_7744;
v_7745:
    v_7809 = cons(stack[-1], v_7808);
    env = stack[-2];
    goto v_7737;
v_7738:
    v_7808 = stack[0];
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_7809, v_7808);
    }
v_7733:
    goto v_7765;
v_7761:
    v_7808 = v_7809;
    v_7808 = qcar(v_7808);
    if (!symbolp(v_7808)) v_7810 = nil;
    else { v_7810 = qfastgets(v_7808);
           if (v_7810 != nil) { v_7810 = elt(v_7810, 2); // rtype
#ifdef RECORD_GET
             if (v_7810 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_7810 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_7810 == SPID_NOPROP) v_7810 = nil; }}
#endif
    goto v_7762;
v_7763:
    v_7808 = elt(env, 2); // matrix
    goto v_7764;
v_7765:
    goto v_7761;
v_7762:
    goto v_7763;
v_7764:
    if (v_7810 == v_7808) goto v_7759;
    else goto v_7760;
v_7759:
    goto v_7775;
v_7771:
    goto v_7772;
v_7773:
    v_7808 = stack[0];
    goto v_7774;
v_7775:
    goto v_7771;
v_7772:
    goto v_7773;
v_7774:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_7809, v_7808);
    }
v_7760:
    goto v_7785;
v_7781:
    goto v_7791;
v_7787:
    v_7808 = v_7809;
    stack[-1] = qcar(v_7808);
    goto v_7788;
v_7789:
    v_7808 = v_7809;
    v_7808 = qcdr(v_7808);
    fn = elt(env, 4); // revlis
    v_7808 = (*qfn1(fn))(fn, v_7808);
    env = stack[-2];
    goto v_7790;
v_7791:
    goto v_7787;
v_7788:
    goto v_7789;
v_7790:
    v_7809 = cons(stack[-1], v_7808);
    env = stack[-2];
    goto v_7782;
v_7783:
    v_7808 = stack[0];
    goto v_7784;
v_7785:
    goto v_7781;
v_7782:
    goto v_7783;
v_7784:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_7809, v_7808);
    }
    v_7808 = nil;
    goto v_7716;
v_7718:
    goto v_7805;
v_7801:
    goto v_7802;
v_7803:
    v_7808 = stack[0];
    goto v_7804;
v_7805:
    goto v_7801;
v_7802:
    goto v_7803;
v_7804:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_7809, v_7808);
    }
    v_7808 = nil;
v_7716:
    return onevalue(v_7808);
}



// Code for efface1

static LispObject CC_efface1(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7751, v_7752, v_7753, v_7754;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7753 = v_7713;
    v_7754 = v_7712;
// end of prologue
    v_7751 = v_7753;
    if (v_7751 == nil) goto v_7717;
    else goto v_7718;
v_7717:
    v_7751 = nil;
    goto v_7716;
v_7718:
    goto v_7727;
v_7723:
    v_7752 = v_7754;
    goto v_7724;
v_7725:
    v_7751 = v_7753;
    v_7751 = qcar(v_7751);
    goto v_7726;
v_7727:
    goto v_7723;
v_7724:
    goto v_7725;
v_7726:
    if (v_7752 == v_7751) goto v_7721;
    else goto v_7722;
v_7721:
    v_7751 = v_7753;
    v_7751 = qcdr(v_7751);
    goto v_7716;
v_7722:
    goto v_7740;
v_7736:
    stack[0] = v_7753;
    goto v_7737;
v_7738:
    goto v_7747;
v_7743:
    v_7751 = v_7754;
    goto v_7744;
v_7745:
    v_7752 = v_7753;
    v_7752 = qcdr(v_7752);
    goto v_7746;
v_7747:
    goto v_7743;
v_7744:
    goto v_7745;
v_7746:
    v_7751 = CC_efface1(elt(env, 0), v_7751, v_7752);
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    {
        LispObject v_7756 = stack[0];
        return Lrplacd(nil, v_7756, v_7751);
    }
    v_7751 = nil;
v_7716:
    return onevalue(v_7751);
}



// Code for updtemplate

static LispObject CC_updtemplate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7837, v_7838, v_7839;
    LispObject fn;
    LispObject v_7714, v_7713, v_7712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "updtemplate");
    va_start(aa, nargs);
    v_7712 = va_arg(aa, LispObject);
    v_7713 = va_arg(aa, LispObject);
    v_7714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7714,v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7712,v_7713,v_7714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_7714;
    v_7837 = v_7713;
    stack[-6] = v_7712;
// end of prologue
    stack[-4] = v_7837;
    v_7837 = stack[-4];
    if (v_7837 == nil) goto v_7730;
    else goto v_7731;
v_7730:
    v_7837 = nil;
    goto v_7725;
v_7731:
    v_7837 = stack[-4];
    v_7837 = qcar(v_7837);
    stack[0] = v_7837;
    goto v_7746;
v_7742:
    goto v_7752;
v_7748:
    v_7838 = stack[-6];
    goto v_7749;
v_7750:
    v_7837 = stack[0];
    goto v_7751;
v_7752:
    goto v_7748;
v_7749:
    goto v_7750;
v_7751:
    v_7838 = Lsubla(nil, v_7838, v_7837);
    env = stack[-8];
    stack[-7] = v_7838;
    goto v_7743;
v_7744:
    v_7837 = stack[0];
    goto v_7745;
v_7746:
    goto v_7742;
v_7743:
    goto v_7744;
v_7745:
    if (equal(v_7838, v_7837)) goto v_7740;
    else goto v_7741;
v_7740:
    v_7837 = stack[0];
    goto v_7739;
v_7741:
    goto v_7763;
v_7759:
    goto v_7769;
v_7765:
    v_7838 = stack[-7];
    goto v_7766;
v_7767:
    v_7837 = stack[-5];
    goto v_7768;
v_7769:
    goto v_7765;
v_7766:
    goto v_7767;
v_7768:
    fn = elt(env, 2); // reval!-without
    v_7838 = (*qfn2(fn))(fn, v_7838, v_7837);
    env = stack[-8];
    v_7839 = v_7838;
    goto v_7760;
v_7761:
    v_7837 = stack[-7];
    goto v_7762;
v_7763:
    goto v_7759;
v_7760:
    goto v_7761;
v_7762:
    if (equal(v_7838, v_7837)) goto v_7758;
    v_7837 = v_7839;
    goto v_7739;
v_7758:
    v_7837 = stack[-7];
    goto v_7739;
    v_7837 = nil;
v_7739:
    v_7837 = ncons(v_7837);
    env = stack[-8];
    stack[-2] = v_7837;
    stack[-3] = v_7837;
v_7726:
    v_7837 = stack[-4];
    v_7837 = qcdr(v_7837);
    stack[-4] = v_7837;
    v_7837 = stack[-4];
    if (v_7837 == nil) goto v_7781;
    else goto v_7782;
v_7781:
    v_7837 = stack[-3];
    goto v_7725;
v_7782:
    goto v_7790;
v_7786:
    stack[-1] = stack[-2];
    goto v_7787;
v_7788:
    v_7837 = stack[-4];
    v_7837 = qcar(v_7837);
    stack[0] = v_7837;
    goto v_7804;
v_7800:
    goto v_7810;
v_7806:
    v_7838 = stack[-6];
    goto v_7807;
v_7808:
    v_7837 = stack[0];
    goto v_7809;
v_7810:
    goto v_7806;
v_7807:
    goto v_7808;
v_7809:
    v_7838 = Lsubla(nil, v_7838, v_7837);
    env = stack[-8];
    stack[-7] = v_7838;
    goto v_7801;
v_7802:
    v_7837 = stack[0];
    goto v_7803;
v_7804:
    goto v_7800;
v_7801:
    goto v_7802;
v_7803:
    if (equal(v_7838, v_7837)) goto v_7798;
    else goto v_7799;
v_7798:
    v_7837 = stack[0];
    goto v_7797;
v_7799:
    goto v_7821;
v_7817:
    goto v_7827;
v_7823:
    v_7838 = stack[-7];
    goto v_7824;
v_7825:
    v_7837 = stack[-5];
    goto v_7826;
v_7827:
    goto v_7823;
v_7824:
    goto v_7825;
v_7826:
    fn = elt(env, 2); // reval!-without
    v_7838 = (*qfn2(fn))(fn, v_7838, v_7837);
    env = stack[-8];
    v_7839 = v_7838;
    goto v_7818;
v_7819:
    v_7837 = stack[-7];
    goto v_7820;
v_7821:
    goto v_7817;
v_7818:
    goto v_7819;
v_7820:
    if (equal(v_7838, v_7837)) goto v_7816;
    v_7837 = v_7839;
    goto v_7797;
v_7816:
    v_7837 = stack[-7];
    goto v_7797;
    v_7837 = nil;
v_7797:
    v_7837 = ncons(v_7837);
    env = stack[-8];
    goto v_7789;
v_7790:
    goto v_7786;
v_7787:
    goto v_7788;
v_7789:
    v_7837 = Lrplacd(nil, stack[-1], v_7837);
    env = stack[-8];
    v_7837 = stack[-2];
    v_7837 = qcdr(v_7837);
    stack[-2] = v_7837;
    goto v_7726;
v_7725:
    return onevalue(v_7837);
}



// Code for qqe_ofsf_chsimpterm

static LispObject CC_qqe_ofsf_chsimpterm(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7806, v_7807;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_7807 = v_7712;
// end of prologue
    v_7806 = v_7807;
    if (!consp(v_7806)) goto v_7720;
    else goto v_7721;
v_7720:
    v_7806 = v_7807;
    goto v_7716;
v_7721:
    v_7806 = v_7807;
    v_7806 = qcdr(v_7806);
    stack[-1] = v_7806;
v_7730:
    v_7806 = stack[-1];
    if (v_7806 == nil) goto v_7733;
    else goto v_7734;
v_7733:
    goto v_7729;
v_7734:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    v_7806 = Lconsp(nil, v_7806);
    env = stack[-2];
    if (v_7806 == nil) goto v_7740;
    goto v_7754;
v_7750:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    fn = elt(env, 4); // qqe_op
    v_7807 = (*qfn1(fn))(fn, v_7806);
    env = stack[-2];
    goto v_7751;
v_7752:
    v_7806 = elt(env, 2); // expt
    goto v_7753;
v_7754:
    goto v_7750;
v_7751:
    goto v_7752;
v_7753:
    if (v_7807 == v_7806) goto v_7748;
    else goto v_7749;
v_7748:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    fn = elt(env, 5); // qqe_arg2l
    v_7806 = (*qfn1(fn))(fn, v_7806);
    env = stack[-2];
    v_7806 = Lconsp(nil, v_7806);
    env = stack[-2];
    if (v_7806 == nil) goto v_7761;
    else goto v_7762;
v_7761:
    v_7806 = nil;
    goto v_7760;
v_7762:
    goto v_7774;
v_7770:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    fn = elt(env, 5); // qqe_arg2l
    v_7806 = (*qfn1(fn))(fn, v_7806);
    env = stack[-2];
    fn = elt(env, 4); // qqe_op
    v_7807 = (*qfn1(fn))(fn, v_7806);
    env = stack[-2];
    goto v_7771;
v_7772:
    v_7806 = elt(env, 3); // (ltail rtail)
    goto v_7773;
v_7774:
    goto v_7770;
v_7771:
    goto v_7772;
v_7773:
    v_7806 = Lmemq(nil, v_7807, v_7806);
    goto v_7760;
    v_7806 = nil;
v_7760:
    goto v_7747;
v_7749:
    v_7806 = nil;
    goto v_7747;
    v_7806 = nil;
v_7747:
    if (v_7806 == nil) goto v_7740;
    goto v_7789;
v_7785:
    stack[0] = stack[-1];
    goto v_7786;
v_7787:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    fn = elt(env, 6); // qqe_chsimpterm
    v_7806 = (*qfn1(fn))(fn, v_7806);
    env = stack[-2];
    goto v_7788;
v_7789:
    goto v_7785;
v_7786:
    goto v_7787;
v_7788:
    fn = elt(env, 7); // setcar
    v_7806 = (*qfn2(fn))(fn, stack[0], v_7806);
    env = stack[-2];
    goto v_7738;
v_7740:
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    v_7806 = Lconsp(nil, v_7806);
    env = stack[-2];
    if (v_7806 == nil) goto v_7795;
    v_7806 = stack[-1];
    v_7806 = qcar(v_7806);
    v_7806 = CC_qqe_ofsf_chsimpterm(elt(env, 0), v_7806);
    env = stack[-2];
    goto v_7738;
v_7795:
v_7738:
    v_7806 = stack[-1];
    v_7806 = qcdr(v_7806);
    stack[-1] = v_7806;
    goto v_7730;
v_7729:
    goto v_7719;
v_7719:
    v_7806 = nil;
v_7716:
    return onevalue(v_7806);
}



// Code for ibalp_clauselp

static LispObject CC_ibalp_clauselp(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7712;
// end of prologue
v_7711:
    v_7735 = stack[0];
    if (v_7735 == nil) goto v_7716;
    else goto v_7717;
v_7716:
    v_7735 = lisp_true;
    goto v_7715;
v_7717:
    v_7735 = stack[0];
    v_7735 = qcar(v_7735);
    fn = elt(env, 1); // ibalp_clausep
    v_7735 = (*qfn1(fn))(fn, v_7735);
    env = stack[-1];
    if (v_7735 == nil) goto v_7724;
    else goto v_7725;
v_7724:
    v_7735 = nil;
    goto v_7723;
v_7725:
    v_7735 = stack[0];
    v_7735 = qcdr(v_7735);
    stack[0] = v_7735;
    goto v_7711;
    v_7735 = nil;
v_7723:
    goto v_7715;
    v_7735 = nil;
v_7715:
    return onevalue(v_7735);
}



// Code for mapins

static LispObject CC_mapins(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7752, v_7753, v_7754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7713;
    stack[-1] = v_7712;
// end of prologue
    stack[-2] = nil;
v_7718:
    v_7752 = stack[0];
    if (v_7752 == nil) goto v_7721;
    else goto v_7722;
v_7721:
    v_7752 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_7752);
    }
v_7722:
    goto v_7735;
v_7729:
    goto v_7741;
v_7737:
    v_7753 = stack[-1];
    goto v_7738;
v_7739:
    v_7752 = stack[0];
    v_7752 = qcar(v_7752);
    v_7752 = qcar(v_7752);
    goto v_7740;
v_7741:
    goto v_7737;
v_7738:
    goto v_7739;
v_7740:
    v_7754 = cons(v_7753, v_7752);
    env = stack[-3];
    goto v_7730;
v_7731:
    v_7752 = stack[0];
    v_7752 = qcar(v_7752);
    v_7753 = qcdr(v_7752);
    goto v_7732;
v_7733:
    v_7752 = stack[-2];
    goto v_7734;
v_7735:
    goto v_7729;
v_7730:
    goto v_7731;
v_7732:
    goto v_7733;
v_7734:
    v_7752 = acons(v_7754, v_7753, v_7752);
    env = stack[-3];
    stack[-2] = v_7752;
    v_7752 = stack[0];
    v_7752 = qcdr(v_7752);
    stack[0] = v_7752;
    goto v_7718;
    v_7752 = nil;
    return onevalue(v_7752);
}



// Code for matsm!*1

static LispObject CC_matsmH1(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7852, v_7853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7712);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_7852 = v_7712;
// end of prologue
    goto v_7722;
v_7718:
    stack[-8] = elt(env, 1); // mat
    goto v_7719;
v_7720:
    stack[-7] = v_7852;
    v_7852 = stack[-7];
    if (v_7852 == nil) goto v_7733;
    else goto v_7734;
v_7733:
    v_7852 = nil;
    goto v_7728;
v_7734:
    v_7852 = stack[-7];
    v_7852 = qcar(v_7852);
    stack[-3] = v_7852;
    v_7852 = stack[-3];
    if (v_7852 == nil) goto v_7750;
    else goto v_7751;
v_7750:
    v_7852 = nil;
    goto v_7745;
v_7751:
    v_7852 = stack[-3];
    v_7852 = qcar(v_7852);
    fn = elt(env, 3); // subs2!*
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    v_7852 = ncons(v_7852);
    env = stack[-9];
    stack[-1] = v_7852;
    stack[-2] = v_7852;
v_7746:
    v_7852 = stack[-3];
    v_7852 = qcdr(v_7852);
    stack[-3] = v_7852;
    v_7852 = stack[-3];
    if (v_7852 == nil) goto v_7765;
    else goto v_7766;
v_7765:
    v_7852 = stack[-2];
    goto v_7745;
v_7766:
    goto v_7774;
v_7770:
    stack[0] = stack[-1];
    goto v_7771;
v_7772:
    v_7852 = stack[-3];
    v_7852 = qcar(v_7852);
    fn = elt(env, 3); // subs2!*
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    v_7852 = ncons(v_7852);
    env = stack[-9];
    goto v_7773;
v_7774:
    goto v_7770;
v_7771:
    goto v_7772;
v_7773:
    v_7852 = Lrplacd(nil, stack[0], v_7852);
    env = stack[-9];
    v_7852 = stack[-1];
    v_7852 = qcdr(v_7852);
    stack[-1] = v_7852;
    goto v_7746;
v_7745:
    v_7852 = ncons(v_7852);
    env = stack[-9];
    stack[-5] = v_7852;
    stack[-6] = v_7852;
v_7729:
    v_7852 = stack[-7];
    v_7852 = qcdr(v_7852);
    stack[-7] = v_7852;
    v_7852 = stack[-7];
    if (v_7852 == nil) goto v_7789;
    else goto v_7790;
v_7789:
    v_7852 = stack[-6];
    goto v_7728;
v_7790:
    goto v_7798;
v_7794:
    stack[-4] = stack[-5];
    goto v_7795;
v_7796:
    v_7852 = stack[-7];
    v_7852 = qcar(v_7852);
    stack[-3] = v_7852;
    v_7852 = stack[-3];
    if (v_7852 == nil) goto v_7813;
    else goto v_7814;
v_7813:
    v_7852 = nil;
    goto v_7808;
v_7814:
    v_7852 = stack[-3];
    v_7852 = qcar(v_7852);
    fn = elt(env, 3); // subs2!*
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    v_7852 = ncons(v_7852);
    env = stack[-9];
    stack[-1] = v_7852;
    stack[-2] = v_7852;
v_7809:
    v_7852 = stack[-3];
    v_7852 = qcdr(v_7852);
    stack[-3] = v_7852;
    v_7852 = stack[-3];
    if (v_7852 == nil) goto v_7828;
    else goto v_7829;
v_7828:
    v_7852 = stack[-2];
    goto v_7808;
v_7829:
    goto v_7837;
v_7833:
    stack[0] = stack[-1];
    goto v_7834;
v_7835:
    v_7852 = stack[-3];
    v_7852 = qcar(v_7852);
    fn = elt(env, 3); // subs2!*
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_7852 = (*qfn1(fn))(fn, v_7852);
    env = stack[-9];
    v_7852 = ncons(v_7852);
    env = stack[-9];
    goto v_7836;
v_7837:
    goto v_7833;
v_7834:
    goto v_7835;
v_7836:
    v_7852 = Lrplacd(nil, stack[0], v_7852);
    env = stack[-9];
    v_7852 = stack[-1];
    v_7852 = qcdr(v_7852);
    stack[-1] = v_7852;
    goto v_7809;
v_7808:
    v_7852 = ncons(v_7852);
    env = stack[-9];
    goto v_7797;
v_7798:
    goto v_7794;
v_7795:
    goto v_7796;
v_7797:
    v_7852 = Lrplacd(nil, stack[-4], v_7852);
    env = stack[-9];
    v_7852 = stack[-5];
    v_7852 = qcdr(v_7852);
    stack[-5] = v_7852;
    goto v_7729;
v_7728:
    goto v_7721;
v_7722:
    goto v_7718;
v_7719:
    goto v_7720;
v_7721:
    v_7852 = cons(stack[-8], v_7852);
    env = stack[-9];
    v_7853 = nil;
    qvalue(elt(env, 2)) = v_7853; // !*sub2
    return onevalue(v_7852);
}



// Code for downwght1

static LispObject CC_downwght1(LispObject env,
                         LispObject v_7712, LispObject v_7713)
{
    env = qenv(env);
    LispObject v_7939, v_7940;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7713,v_7712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7712,v_7713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_7939 = v_7713;
    stack[-4] = v_7712;
// end of prologue
    fn = elt(env, 3); // dm!-abs
    v_7939 = (*qfn1(fn))(fn, v_7939);
    env = stack[-6];
    fn = elt(env, 4); // !:onep
    v_7939 = (*qfn1(fn))(fn, v_7939);
    env = stack[-6];
    if (v_7939 == nil) goto v_7717;
    else goto v_7718;
v_7717:
    goto v_7728;
v_7722:
    goto v_7733;
v_7729:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7730;
v_7731:
    goto v_7740;
v_7736:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7737;
v_7738:
    v_7939 = stack[-4];
    goto v_7739;
v_7740:
    goto v_7736;
v_7737:
    goto v_7738;
v_7739:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7732;
v_7733:
    goto v_7729;
v_7730:
    goto v_7731;
v_7732:
    stack[-5] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7723;
v_7724:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7725;
v_7726:
    goto v_7752;
v_7746:
    goto v_7758;
v_7754:
    goto v_7763;
v_7759:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7760;
v_7761:
    goto v_7770;
v_7766:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7767;
v_7768:
    v_7939 = stack[-4];
    goto v_7769;
v_7770:
    goto v_7766;
v_7767:
    goto v_7768;
v_7769:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7762;
v_7763:
    goto v_7759;
v_7760:
    goto v_7761;
v_7762:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7755;
v_7756:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7757;
v_7758:
    goto v_7754;
v_7755:
    goto v_7756;
v_7757:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7939 = qcar(v_7939);
    v_7939 = qcar(v_7939);
    stack[-2] = sub1(v_7939);
    env = stack[-6];
    goto v_7747;
v_7748:
    goto v_7783;
v_7779:
    goto v_7788;
v_7784:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7785;
v_7786:
    goto v_7795;
v_7791:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7792;
v_7793:
    v_7939 = stack[-4];
    goto v_7794;
v_7795:
    goto v_7791;
v_7792:
    goto v_7793;
v_7794:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7787;
v_7788:
    goto v_7784;
v_7785:
    goto v_7786;
v_7787:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7780;
v_7781:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7782;
v_7783:
    goto v_7779;
v_7780:
    goto v_7781;
v_7782:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7939 = qcar(v_7939);
    v_7939 = qcdr(v_7939);
    stack[-1] = sub1(v_7939);
    env = stack[-6];
    goto v_7749;
v_7750:
    goto v_7808;
v_7804:
    goto v_7813;
v_7809:
    goto v_7818;
v_7814:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7815;
v_7816:
    goto v_7825;
v_7821:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7822;
v_7823:
    v_7939 = stack[-4];
    goto v_7824;
v_7825:
    goto v_7821;
v_7822:
    goto v_7823;
v_7824:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7817;
v_7818:
    goto v_7814;
v_7815:
    goto v_7816;
v_7817:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7810;
v_7811:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7812;
v_7813:
    goto v_7809;
v_7810:
    goto v_7811;
v_7812:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7940 = qcdr(v_7939);
    goto v_7805;
v_7806:
    v_7939 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_7807;
v_7808:
    goto v_7804;
v_7805:
    goto v_7806;
v_7807:
    v_7939 = difference2(v_7940, v_7939);
    env = stack[-6];
    goto v_7751;
v_7752:
    goto v_7746;
v_7747:
    goto v_7748;
v_7749:
    goto v_7750;
v_7751:
    v_7939 = acons(stack[-2], stack[-1], v_7939);
    goto v_7727;
v_7728:
    goto v_7722;
v_7723:
    goto v_7724;
v_7725:
    goto v_7726;
v_7727:
    *(LispObject *)((char *)stack[-5] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_7939;
    goto v_7716;
v_7718:
    goto v_7841;
v_7835:
    goto v_7846;
v_7842:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7843;
v_7844:
    goto v_7853;
v_7849:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7850;
v_7851:
    v_7939 = stack[-4];
    goto v_7852;
v_7853:
    goto v_7849;
v_7850:
    goto v_7851;
v_7852:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7845;
v_7846:
    goto v_7842;
v_7843:
    goto v_7844;
v_7845:
    stack[-5] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7836;
v_7837:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7838;
v_7839:
    goto v_7865;
v_7859:
    goto v_7871;
v_7867:
    goto v_7876;
v_7872:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7873;
v_7874:
    goto v_7883;
v_7879:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7880;
v_7881:
    v_7939 = stack[-4];
    goto v_7882;
v_7883:
    goto v_7879;
v_7880:
    goto v_7881;
v_7882:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7875;
v_7876:
    goto v_7872;
v_7873:
    goto v_7874;
v_7875:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7868;
v_7869:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7870;
v_7871:
    goto v_7867;
v_7868:
    goto v_7869;
v_7870:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7939 = qcar(v_7939);
    v_7939 = qcar(v_7939);
    stack[-2] = sub1(v_7939);
    env = stack[-6];
    goto v_7860;
v_7861:
    goto v_7895;
v_7891:
    goto v_7900;
v_7896:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7897;
v_7898:
    goto v_7907;
v_7903:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7904;
v_7905:
    v_7939 = stack[-4];
    goto v_7906;
v_7907:
    goto v_7903;
v_7904:
    goto v_7905;
v_7906:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7899;
v_7900:
    goto v_7896;
v_7897:
    goto v_7898;
v_7899:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7892;
v_7893:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7894;
v_7895:
    goto v_7891;
v_7892:
    goto v_7893;
v_7894:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7939 = qcar(v_7939);
    stack[-1] = qcdr(v_7939);
    goto v_7862;
v_7863:
    goto v_7920;
v_7916:
    goto v_7925;
v_7921:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7922;
v_7923:
    goto v_7932;
v_7928:
    v_7940 = qvalue(elt(env, 2)); // maxvar
    goto v_7929;
v_7930:
    v_7939 = stack[-4];
    goto v_7931;
v_7932:
    goto v_7928;
v_7929:
    goto v_7930;
v_7931:
    v_7939 = plus2(v_7940, v_7939);
    env = stack[-6];
    goto v_7924;
v_7925:
    goto v_7921;
v_7922:
    goto v_7923;
v_7924:
    v_7940 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    goto v_7917;
v_7918:
    v_7939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7919;
v_7920:
    goto v_7916;
v_7917:
    goto v_7918;
v_7919:
    v_7939 = *(LispObject *)((char *)v_7940 + (CELL-TAG_VECTOR) + (((intptr_t)v_7939-TAG_FIXNUM)/(16/CELL)));
    v_7939 = qcdr(v_7939);
    v_7939 = sub1(v_7939);
    env = stack[-6];
    goto v_7864;
v_7865:
    goto v_7859;
v_7860:
    goto v_7861;
v_7862:
    goto v_7863;
v_7864:
    v_7939 = acons(stack[-2], stack[-1], v_7939);
    goto v_7840;
v_7841:
    goto v_7835;
v_7836:
    goto v_7837;
v_7838:
    goto v_7839;
v_7840:
    *(LispObject *)((char *)stack[-5] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_7939;
    goto v_7716;
    v_7939 = nil;
v_7716:
    return onevalue(v_7939);
}



// Code for newenv

static LispObject CC_newenv(LispObject env,
                         LispObject v_7712)
{
    env = qenv(env);
    LispObject v_7722, v_7723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7722 = v_7712;
// end of prologue
    goto v_7719;
v_7715:
    v_7723 = v_7722;
    goto v_7716;
v_7717:
    v_7722 = elt(env, 1); // unbound
    goto v_7718;
v_7719:
    goto v_7715;
v_7716:
    goto v_7717;
v_7718:
    {
        fn = elt(env, 2); // bind
        return (*qfn2(fn))(fn, v_7723, v_7722);
    }
}



setup_type const u15_setup[] =
{
    {"bc2a",                    CC_bc2a,        TOO_MANY_1,    WRONG_NO_1},
    {"vevdif",                  TOO_FEW_2,      CC_vevdif,     WRONG_NO_2},
    {"map__edges",              CC_map__edges,  TOO_MANY_1,    WRONG_NO_1},
    {"evalneq",                 TOO_FEW_2,      CC_evalneq,    WRONG_NO_2},
    {"red-ratios2",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_redKratios2},
    {"dp_neg",                  CC_dp_neg,      TOO_MANY_1,    WRONG_NO_1},
    {"gperm3",                  TOO_FEW_2,      CC_gperm3,     WRONG_NO_2},
    {"exptsq",                  TOO_FEW_2,      CC_exptsq,     WRONG_NO_2},
    {"gcref_mknode-tgf",        CC_gcref_mknodeKtgf,TOO_MANY_1,WRONG_NO_1},
    {"rl_simpl",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_simpl},
    {"removeg2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_removeg2},
    {"cl_smsimpl-junct",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct},
    {"chknewnam",               CC_chknewnam,   TOO_MANY_1,    WRONG_NO_1},
    {"sq2sscfpl",               TOO_FEW_2,      CC_sq2sscfpl,  WRONG_NO_2},
    {"ofsf_pow2q",              TOO_FEW_2,      CC_ofsf_pow2q, WRONG_NO_2},
    {"sc_minussq",              CC_sc_minussq,  TOO_MANY_1,    WRONG_NO_1},
    {"mksgnsq",                 CC_mksgnsq,     TOO_MANY_1,    WRONG_NO_1},
    {"set-ordp",                TOO_FEW_2,      CC_setKordp,   WRONG_NO_2},
    {"*kp2f",                   TOO_FEW_2,      CC_Hkp2f,      WRONG_NO_2},
    {"rnconc",                  TOO_FEW_2,      CC_rnconc,     WRONG_NO_2},
    {"mo_neworder",             CC_mo_neworder, TOO_MANY_1,    WRONG_NO_1},
    {"pv_intequiv",             CC_pv_intequiv, TOO_MANY_1,    WRONG_NO_1},
    {"use-berlekamp",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_useKberlekamp},
    {"lalr_reduction_index",    CC_lalr_reduction_index,TOO_MANY_1,WRONG_NO_1},
    {"aex_varl",                CC_aex_varl,    TOO_MANY_1,    WRONG_NO_1},
    {"rempropss",               TOO_FEW_2,      CC_rempropss,  WRONG_NO_2},
    {"ofsf_entry2at1",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_entry2at1},
    {"intexprlisp",             TOO_FEW_2,      CC_intexprlisp,WRONG_NO_2},
    {"rl_simpbop",              CC_rl_simpbop,  TOO_MANY_1,    WRONG_NO_1},
    {"gb_buch-ev_divides?",     TOO_FEW_2,      CC_gb_buchKev_dividesW,WRONG_NO_2},
    {"c:subs2multf",            TOO_FEW_2,      CC_cTsubs2multf,WRONG_NO_2},
    {"lid",                     CC_lid,         TOO_MANY_1,    WRONG_NO_1},
    {"physop-multf",            TOO_FEW_2,      CC_physopKmultf,WRONG_NO_2},
    {"defined_edge",            TOO_FEW_2,      CC_defined_edge,WRONG_NO_2},
    {"groeb=better",            TOO_FEW_2,      CC_groebMbetter,WRONG_NO_2},
    {"ra_budan-0-1",            CC_ra_budanK0K1,TOO_MANY_1,    WRONG_NO_1},
    {"portable_prin",           CC_portable_prin,TOO_MANY_1,   WRONG_NO_1},
    {"polynommultiplybyvariable",TOO_FEW_2,     CC_polynommultiplybyvariable,WRONG_NO_2},
    {"kernord-split",           TOO_FEW_2,      CC_kernordKsplit,WRONG_NO_2},
    {"ibalp_simpatom",          CC_ibalp_simpatom,TOO_MANY_1,  WRONG_NO_1},
    {"mathml2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mathml2},
    {"testredh",                CC_testredh,    TOO_MANY_1,    WRONG_NO_1},
    {"evenfree",                CC_evenfree,    TOO_MANY_1,    WRONG_NO_1},
    {"aminusp:1",               CC_aminuspT1,   TOO_MANY_1,    WRONG_NO_1},
    {"general-times-mod-p",     TOO_FEW_2,      CC_generalKtimesKmodKp,WRONG_NO_2},
    {"setk",                    TOO_FEW_2,      CC_setk,       WRONG_NO_2},
    {"efface1",                 TOO_FEW_2,      CC_efface1,    WRONG_NO_2},
    {"updtemplate",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_updtemplate},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,TOO_MANY_1,WRONG_NO_1},
    {"ibalp_clauselp",          CC_ibalp_clauselp,TOO_MANY_1,  WRONG_NO_1},
    {"mapins",                  TOO_FEW_2,      CC_mapins,     WRONG_NO_2},
    {"matsm*1",                 CC_matsmH1,     TOO_MANY_1,    WRONG_NO_1},
    {"downwght1",               TOO_FEW_2,      CC_downwght1,  WRONG_NO_2},
    {"newenv",                  CC_newenv,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u15", (two_args *)"4856 5311276 7243718", 0}
};

// end of generated code
