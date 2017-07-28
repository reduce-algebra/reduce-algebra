
// $destdir/u54.c        Machine generated C code

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



// Code for dip!-nc!-ev!-prod

static LispObject CC_dipKncKevKprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33018, v_33019, v_33020, v_33021;
    LispObject fn;
    LispObject v_32988, v_32987, v_32986, v_32985;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dip-nc-ev-prod");
    va_start(aa, nargs);
    v_32985 = va_arg(aa, LispObject);
    v_32986 = va_arg(aa, LispObject);
    v_32987 = va_arg(aa, LispObject);
    v_32988 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_32988,v_32987,v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_32985,v_32986,v_32987,v_32988);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_33018 = v_32988;
    v_33019 = v_32987;
    v_33020 = v_32986;
    v_33021 = v_32985;
// end of prologue
    goto v_32997;
v_32991:
    stack[-2] = v_33020;
    goto v_32992;
v_32993:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32994;
v_32995:
    goto v_33007;
v_33001:
    stack[0] = v_33018;
    goto v_33002;
v_33003:
    goto v_33014;
v_33010:
    v_33018 = v_33021;
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    fn = elt(env, 1); // bcprod
    v_33019 = (*qfn2(fn))(fn, v_33018, v_33019);
    env = stack[-3];
    goto v_33004;
v_33005:
    v_33018 = nil;
    goto v_33006;
v_33007:
    goto v_33001;
v_33002:
    goto v_33003;
v_33004:
    goto v_33005;
v_33006:
    v_33018 = list2star(stack[0], v_33019, v_33018);
    env = stack[-3];
    goto v_32996;
v_32997:
    goto v_32991;
v_32992:
    goto v_32993;
v_32994:
    goto v_32995;
v_32996:
    {
        LispObject v_33025 = stack[-2];
        LispObject v_33026 = stack[-1];
        fn = elt(env, 2); // dip!-nc!-ev!-prod1
        return (*qfnn(fn))(fn, 3, v_33025, v_33026, v_33018);
    }
}



// Code for row_dim

static LispObject CC_row_dim(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33009;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
    v_33009 = qvalue(elt(env, 1)); // !*fast_la
    if (v_33009 == nil) goto v_32995;
    else goto v_32996;
v_32995:
    v_33009 = stack[0];
    fn = elt(env, 3); // matrixp
    v_33009 = (*qfn1(fn))(fn, v_33009);
    env = stack[-1];
    v_33009 = (v_33009 == nil ? lisp_true : nil);
    goto v_32994;
v_32996:
    v_33009 = nil;
    goto v_32994;
    v_33009 = nil;
v_32994:
    if (v_33009 == nil) goto v_32992;
    v_33009 = elt(env, 2); // "Error in row_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_33009 = (*qfn1(fn))(fn, v_33009);
    env = stack[-1];
    goto v_32990;
v_32992:
v_32990:
    v_33009 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_33009 = (*qfn1(fn))(fn, v_33009);
    v_33009 = qcar(v_33009);
    return onevalue(v_33009);
}



// Code for all_defined

static LispObject CC_all_defined(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33004, v_33005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32986;
    v_33004 = v_32985;
// end of prologue
    goto v_32993;
v_32989:
    stack[-1] = v_33004;
    goto v_32990;
v_32991:
    goto v_33000;
v_32996:
    fn = elt(env, 1); // map__edges
    v_33005 = (*qfn1(fn))(fn, v_33004);
    env = stack[-2];
    goto v_32997;
v_32998:
    v_33004 = stack[0];
    goto v_32999;
v_33000:
    goto v_32996;
v_32997:
    goto v_32998;
v_32999:
    fn = elt(env, 2); // defined_append
    v_33004 = (*qfn2(fn))(fn, v_33005, v_33004);
    env = stack[-2];
    goto v_32992;
v_32993:
    goto v_32989;
v_32990:
    goto v_32991;
v_32992:
    {
        LispObject v_33008 = stack[-1];
        fn = elt(env, 3); // all_defined_map_
        return (*qfn2(fn))(fn, v_33008, v_33004);
    }
}



// Code for radd

static LispObject CC_radd(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33115, v_33116;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32986;
    stack[-1] = v_32985;
// end of prologue
    stack[-2] = nil;
    v_33115 = stack[-1];
    if (!consp(v_33115)) goto v_32996;
    goto v_33003;
v_32999:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33000;
v_33001:
    v_33115 = stack[-1];
    fn = elt(env, 3); // prepf
    v_33115 = (*qfn1(fn))(fn, v_33115);
    goto v_33002;
v_33003:
    goto v_32999;
v_33000:
    goto v_33001;
v_33002:
    {
        LispObject v_33120 = stack[0];
        return list2(v_33120, v_33115);
    }
v_32996:
    goto v_33017;
v_33013:
    v_33116 = stack[-1];
    goto v_33014;
v_33015:
    v_33115 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    v_33115 = (LispObject)lessp2(v_33116, v_33115);
    v_33115 = v_33115 ? lisp_true : nil;
    env = stack[-3];
    if (v_33115 == nil) goto v_33010;
    v_33115 = stack[0];
    v_33115 = Levenp(nil, v_33115);
    env = stack[-3];
    if (v_33115 == nil) goto v_33010;
    v_33115 = lisp_true;
    stack[-2] = v_33115;
    v_33115 = stack[-1];
    v_33115 = negate(v_33115);
    env = stack[-3];
    stack[-1] = v_33115;
    goto v_33008;
v_33010:
v_33008:
    goto v_33031;
v_33027:
    v_33116 = stack[-1];
    goto v_33028;
v_33029:
    v_33115 = stack[0];
    goto v_33030;
v_33031:
    goto v_33027;
v_33028:
    goto v_33029;
v_33030:
    fn = elt(env, 4); // nrootnn
    v_33115 = (*qfn2(fn))(fn, v_33116, v_33115);
    env = stack[-3];
    stack[-1] = v_33115;
    v_33115 = stack[-2];
    if (v_33115 == nil) goto v_33037;
    v_33115 = qvalue(elt(env, 1)); // !*reduced
    if (v_33115 == nil) goto v_33042;
    goto v_33050;
v_33046:
    v_33116 = stack[0];
    goto v_33047;
v_33048:
    v_33115 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33049;
v_33050:
    goto v_33046;
v_33047:
    goto v_33048;
v_33049:
    if (v_33116 == v_33115) goto v_33045;
    else goto v_33042;
v_33045:
    goto v_33058;
v_33054:
    v_33115 = stack[-1];
    stack[0] = qcar(v_33115);
    goto v_33055;
v_33056:
    goto v_33067;
v_33063:
    goto v_33073;
v_33069:
    v_33116 = elt(env, 2); // i
    goto v_33070;
v_33071:
    v_33115 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33072;
v_33073:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    fn = elt(env, 5); // to
    v_33116 = (*qfn2(fn))(fn, v_33116, v_33115);
    env = stack[-3];
    goto v_33064;
v_33065:
    v_33115 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33066;
v_33067:
    goto v_33063;
v_33064:
    goto v_33065;
v_33066:
    v_33115 = cons(v_33116, v_33115);
    env = stack[-3];
    v_33115 = ncons(v_33115);
    env = stack[-3];
    goto v_33057;
v_33058:
    goto v_33054;
v_33055:
    goto v_33056;
v_33057:
    fn = elt(env, 6); // multd
    v_33115 = (*qfn2(fn))(fn, stack[0], v_33115);
    stack[0] = v_33115;
    v_33115 = stack[-1];
    v_33115 = qcdr(v_33115);
    stack[-1] = v_33115;
    goto v_33040;
v_33042:
    v_33115 = stack[-1];
    v_33115 = qcar(v_33115);
    stack[0] = v_33115;
    v_33115 = stack[-1];
    v_33115 = qcdr(v_33115);
    v_33115 = negate(v_33115);
    stack[-1] = v_33115;
    goto v_33040;
v_33040:
    goto v_33035;
v_33037:
    v_33115 = stack[-1];
    v_33115 = qcar(v_33115);
    stack[0] = v_33115;
    v_33115 = stack[-1];
    v_33115 = qcdr(v_33115);
    stack[-1] = v_33115;
    goto v_33035;
v_33035:
    goto v_33100;
v_33096:
    v_33116 = stack[-1];
    goto v_33097;
v_33098:
    v_33115 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33099;
v_33100:
    goto v_33096;
v_33097:
    goto v_33098;
v_33099:
    if (v_33116 == v_33115) goto v_33094;
    else goto v_33095;
v_33094:
    v_33115 = stack[0];
    return ncons(v_33115);
v_33095:
    goto v_33112;
v_33108:
    v_33116 = stack[0];
    goto v_33109;
v_33110:
    v_33115 = stack[-1];
    goto v_33111;
v_33112:
    goto v_33108;
v_33109:
    goto v_33110;
v_33111:
    return list2(v_33116, v_33115);
    v_33115 = nil;
    return onevalue(v_33115);
}



// Code for gak

static LispObject CC_gak(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33083, v_33084, v_33085, v_33086, v_33087;
    LispObject fn;
    LispObject v_32987, v_32986, v_32985;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gak");
    va_start(aa, nargs);
    v_32985 = va_arg(aa, LispObject);
    v_32986 = va_arg(aa, LispObject);
    v_32987 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32987,v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32985,v_32986,v_32987);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_33084 = v_32987;
    v_33085 = v_32986;
    v_33086 = v_32985;
// end of prologue
v_32984:
    v_33083 = v_33086;
    if (!consp(v_33083)) goto v_32995;
    else goto v_32996;
v_32995:
    v_33083 = lisp_true;
    goto v_32994;
v_32996:
    v_33083 = v_33086;
    v_33083 = qcar(v_33083);
    v_33083 = (consp(v_33083) ? nil : lisp_true);
    goto v_32994;
    v_33083 = nil;
v_32994:
    if (v_33083 == nil) goto v_32992;
    v_33083 = v_33084;
    goto v_32990;
v_32992:
    v_33083 = v_33086;
    v_33083 = qcar(v_33083);
    v_33083 = qcar(v_33083);
    v_33083 = qcar(v_33083);
    v_33087 = v_33083;
    goto v_33019;
v_33013:
    v_33083 = v_33086;
    stack[-3] = qcdr(v_33083);
    goto v_33014;
v_33015:
    stack[-2] = v_33085;
    goto v_33016;
v_33017:
    goto v_33030;
v_33024:
    v_33083 = v_33086;
    v_33083 = qcar(v_33083);
    stack[-1] = qcdr(v_33083);
    goto v_33025;
v_33026:
    stack[0] = v_33085;
    goto v_33027;
v_33028:
    v_33083 = v_33087;
    if (!consp(v_33083)) goto v_33042;
    goto v_33052;
v_33048:
    v_33083 = v_33087;
    v_33083 = qcar(v_33083);
    goto v_33049;
v_33050:
    goto v_33051;
v_33052:
    goto v_33048;
v_33049:
    goto v_33050;
v_33051:
    v_33083 = Lmember(nil, v_33083, v_33085);
    if (v_33083 == nil) goto v_33046;
    else goto v_33047;
v_33046:
    v_33083 = nil;
    goto v_33045;
v_33047:
    goto v_33064;
v_33060:
    v_33085 = v_33087;
    goto v_33061;
v_33062:
    v_33083 = v_33084;
    goto v_33063;
v_33064:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    v_33083 = Lmember(nil, v_33085, v_33083);
    v_33083 = (v_33083 == nil ? lisp_true : nil);
    goto v_33045;
    v_33083 = nil;
v_33045:
    goto v_33040;
v_33042:
    v_33083 = nil;
    goto v_33040;
    v_33083 = nil;
v_33040:
    if (v_33083 == nil) goto v_33038;
    goto v_33077;
v_33073:
    v_33083 = v_33084;
    goto v_33074;
v_33075:
    v_33084 = v_33087;
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    fn = elt(env, 1); // aconc
    v_33083 = (*qfn2(fn))(fn, v_33083, v_33084);
    env = stack[-4];
    goto v_33036;
v_33038:
    v_33083 = v_33084;
    goto v_33036;
    v_33083 = nil;
v_33036:
    goto v_33029;
v_33030:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    goto v_33028;
v_33029:
    v_33083 = CC_gak(elt(env, 0), 3, stack[-1], stack[0], v_33083);
    env = stack[-4];
    goto v_33018;
v_33019:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    goto v_33017;
v_33018:
    v_33086 = stack[-3];
    v_33085 = stack[-2];
    v_33084 = v_33083;
    goto v_32984;
    v_33083 = nil;
v_32990:
    return onevalue(v_33083);
}



// Code for resetparser

static LispObject CC_resetparser(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32993;
    LispObject fn;
    argcheck(nargs, 0, "resetparser");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_32993 = qvalue(elt(env, 1)); // !*slin
    if (v_32993 == nil) goto v_32988;
    else goto v_32989;
v_32988:
    v_32993 = lisp_true;
    {
        fn = elt(env, 2); // comm1
        return (*qfn1(fn))(fn, v_32993);
    }
v_32989:
    v_32993 = nil;
    return onevalue(v_32993);
}



// Code for giminusp!:

static LispObject CC_giminuspT(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33010, v_33011, v_33012;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33011 = v_32985;
// end of prologue
    goto v_32995;
v_32991:
    v_33010 = v_33011;
    v_33010 = qcdr(v_33010);
    v_33012 = qcar(v_33010);
    goto v_32992;
v_32993:
    v_33010 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32994;
v_32995:
    goto v_32991;
v_32992:
    goto v_32993;
v_32994:
    if (v_33012 == v_33010) goto v_32989;
    else goto v_32990;
v_32989:
    v_33010 = v_33011;
    v_33010 = qcdr(v_33010);
    v_33010 = qcdr(v_33010);
        return Lminusp(nil, v_33010);
v_32990:
    v_33010 = v_33011;
    v_33010 = qcdr(v_33010);
    v_33010 = qcar(v_33010);
        return Lminusp(nil, v_33010);
    v_33010 = nil;
    return onevalue(v_33010);
}



// Code for opfchk!!

static LispObject CC_opfchkB(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33271, v_33272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_32985;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_33271 = stack[-6];
    v_33271 = qcar(v_33271);
    stack[-7] = v_33271;
    stack[-5] = v_33271;
    v_33271 = stack[-6];
    v_33271 = qcdr(v_33271);
    stack[-6] = v_33271;
    goto v_33012;
v_33008:
    v_33272 = stack[-7];
    goto v_33009;
v_33010:
    v_33271 = elt(env, 1); // integer
    goto v_33011;
v_33012:
    goto v_33008;
v_33009:
    goto v_33010;
v_33011:
    v_33271 = Lflagp(nil, v_33272, v_33271);
    env = stack[-8];
    if (v_33271 == nil) goto v_33006;
    v_33271 = lisp_true;
    stack[-3] = v_33271;
    goto v_33021;
v_33017:
    v_33272 = stack[-7];
    goto v_33018;
v_33019:
    v_33271 = elt(env, 2); // !:rn!:
    goto v_33020;
v_33021:
    goto v_33017;
v_33018:
    goto v_33019;
v_33020:
    v_33271 = get(v_33272, v_33271);
    env = stack[-8];
    goto v_33004;
v_33006:
    v_33271 = qvalue(elt(env, 3)); // !*numval
    if (v_33271 == nil) goto v_33025;
    goto v_33033;
v_33029:
    v_33272 = qvalue(elt(env, 4)); // dmode!*
    goto v_33030;
v_33031:
    v_33271 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_33032;
v_33033:
    goto v_33029;
v_33030:
    goto v_33031;
v_33032:
    v_33271 = Lmemq(nil, v_33272, v_33271);
    if (v_33271 == nil) goto v_33025;
    goto v_33042;
v_33038:
    v_33272 = stack[-7];
    goto v_33039;
v_33040:
    v_33271 = elt(env, 6); // !:rd!:
    goto v_33041;
v_33042:
    goto v_33038;
v_33039:
    goto v_33040;
v_33041:
    v_33271 = get(v_33272, v_33271);
    env = stack[-8];
    goto v_33004;
v_33025:
    v_33271 = nil;
v_33004:
    stack[-7] = v_33271;
    v_33271 = stack[-7];
    if (v_33271 == nil) goto v_33047;
    else goto v_33048;
v_33047:
    v_33271 = nil;
    goto v_32994;
v_33048:
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33054;
    v_33271 = elt(env, 7); // simprn
    goto v_33052;
v_33054:
    goto v_33064;
v_33060:
    v_33272 = stack[-7];
    goto v_33061;
v_33062:
    v_33271 = elt(env, 8); // simparg
    goto v_33063;
v_33064:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    v_33271 = get(v_33272, v_33271);
    env = stack[-8];
    stack[-4] = v_33271;
    if (v_33271 == nil) goto v_33058;
    v_33271 = stack[-4];
    goto v_33052;
v_33058:
    v_33271 = elt(env, 9); // simprd
    goto v_33052;
    v_33271 = nil;
v_33052:
    stack[-4] = v_33271;
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33075;
    else goto v_33073;
v_33075:
    v_33271 = qvalue(elt(env, 10)); // !*complex
    if (v_33271 == nil) goto v_33073;
    goto v_33074;
v_33073:
    goto v_32997;
v_33074:
    goto v_33088;
v_33084:
    v_33271 = stack[-6];
    v_33272 = qcar(v_33271);
    goto v_33085;
v_33086:
    v_33271 = elt(env, 11); // list
    goto v_33087;
v_33088:
    goto v_33084;
v_33085:
    goto v_33086;
v_33087:
    if (!consp(v_33272)) goto v_33082;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33081;
    else goto v_33082;
v_33081:
    v_33271 = stack[-6];
    v_33271 = qcar(v_33271);
    v_33271 = qcdr(v_33271);
    fn = elt(env, 17); // revlis
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    v_33272 = v_33271;
    if (v_33271 == nil) goto v_33095;
    goto v_33108;
v_33104:
    goto v_33105;
v_33106:
    v_33271 = nil;
    goto v_33107;
v_33108:
    goto v_33104;
v_33105:
    goto v_33106;
v_33107:
    if (!consp(v_33272)) goto v_33095;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33102;
    else goto v_33095;
v_33102:
    goto v_32996;
v_33095:
    goto v_32997;
    goto v_33080;
v_33082:
v_33080:
    v_33271 = stack[-6];
    fn = elt(env, 17); // revlis
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    stack[-6] = v_33271;
    if (v_33271 == nil) goto v_33115;
    else goto v_33116;
v_33115:
    v_33271 = nil;
    goto v_32994;
v_33116:
    goto v_33132;
v_33128:
    v_33272 = stack[-6];
    goto v_33129;
v_33130:
    v_33271 = nil;
    goto v_33131;
v_33132:
    goto v_33128;
v_33129:
    goto v_33130;
v_33131:
    if (!consp(v_33272)) goto v_33126;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33125;
    else goto v_33126;
v_33125:
    v_33271 = lisp_true;
    goto v_33124;
v_33126:
    goto v_33146;
v_33142:
    v_33272 = stack[-5];
    goto v_33143;
v_33144:
    v_33271 = elt(env, 12); // expt
    goto v_33145;
v_33146:
    goto v_33142;
v_33143:
    goto v_33144;
v_33145:
    if (v_33272 == v_33271) goto v_33140;
    else goto v_33141;
v_33140:
    v_33271 = stack[-6];
    v_33271 = qcar(v_33271);
    v_33271 = qcar(v_33271);
    fn = elt(env, 19); // rd!:minusp
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    goto v_33139;
v_33141:
    v_33271 = nil;
    goto v_33139;
    v_33271 = nil;
v_33139:
    goto v_33124;
    v_33271 = nil;
v_33124:
    if (v_33271 == nil) goto v_33122;
    v_33271 = stack[-6];
    v_33271 = qcdr(v_33271);
    stack[-6] = v_33271;
    goto v_33114;
v_33122:
    v_33271 = stack[-6];
    v_33271 = qcdr(v_33271);
    stack[-2] = v_33271;
    v_33271 = stack[-6];
    v_33271 = qcar(v_33271);
    stack[-6] = v_33271;
    goto v_32997;
v_33114:
v_32995:
    goto v_33173;
v_33169:
    v_33272 = stack[-5];
    goto v_33170;
v_33171:
    v_33271 = elt(env, 13); // !:cr!:
    goto v_33172;
v_33173:
    goto v_33169;
v_33170:
    goto v_33171;
v_33172:
    v_33271 = get(v_33272, v_33271);
    env = stack[-8];
    stack[-7] = v_33271;
    if (v_33271 == nil) goto v_33167;
    goto v_32998;
v_33167:
v_32996:
    goto v_33183;
v_33177:
    stack[-1] = elt(env, 14); // alg
    goto v_33178;
v_33179:
    stack[0] = (LispObject)288+TAG_FIXNUM; // 18
    goto v_33180;
v_33181:
    goto v_33191;
v_33187:
    v_33272 = stack[-5];
    goto v_33188;
v_33189:
    v_33271 = elt(env, 15); // "is not defined as complex function"
    goto v_33190;
v_33191:
    goto v_33187;
v_33188:
    goto v_33189;
v_33190:
    v_33271 = list2(v_33272, v_33271);
    env = stack[-8];
    goto v_33182;
v_33183:
    goto v_33177;
v_33178:
    goto v_33179;
v_33180:
    goto v_33181;
v_33182:
    fn = elt(env, 20); // rerror
    v_33271 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33271);
    env = stack[-8];
v_32997:
    goto v_33203;
v_33199:
    stack[0] = stack[-4];
    goto v_33200;
v_33201:
    v_33271 = stack[-6];
    fn = elt(env, 17); // revlis
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    goto v_33202;
v_33203:
    goto v_33199;
v_33200:
    goto v_33201;
v_33202:
    v_33271 = Lapply1(nil, stack[0], v_33271);
    env = stack[-8];
    stack[-6] = v_33271;
    if (v_33271 == nil) goto v_33196;
    else goto v_33197;
v_33196:
    v_33271 = nil;
    goto v_32994;
v_33197:
v_32998:
    goto v_33216;
v_33210:
    stack[0] = elt(env, 16); // apply
    goto v_33211;
v_33212:
    v_33271 = stack[-7];
    stack[-1] = Lmkquote(nil, v_33271);
    env = stack[-8];
    goto v_33213;
v_33214:
    v_33271 = stack[-6];
    v_33271 = Lmkquote(nil, v_33271);
    env = stack[-8];
    goto v_33215;
v_33216:
    goto v_33210;
v_33211:
    goto v_33212;
v_33213:
    goto v_33214;
v_33215:
    v_33271 = list3(stack[0], stack[-1], v_33271);
    env = stack[-8];
    fn = elt(env, 21); // errorset2
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    stack[-6] = v_33271;
    v_33271 = stack[-6];
    fn = elt(env, 22); // errorp
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    if (v_33271 == nil) goto v_33226;
    else goto v_33224;
v_33226:
    goto v_33239;
v_33235:
    v_33271 = stack[-6];
    v_33272 = qcar(v_33271);
    stack[-6] = v_33272;
    goto v_33236;
v_33237:
    v_33271 = elt(env, 6); // !:rd!:
    goto v_33238;
v_33239:
    goto v_33235;
v_33236:
    goto v_33237;
v_33238:
    if (!consp(v_33272)) goto v_33233;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33232;
    else goto v_33233;
v_33232:
    v_33271 = stack[-6];
    v_33271 = qcdr(v_33271);
    fn = elt(env, 23); // complexp
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-8];
    goto v_33231;
v_33233:
    v_33271 = nil;
    goto v_33231;
    v_33271 = nil;
v_33231:
    if (v_33271 == nil) goto v_33229;
    else goto v_33224;
v_33229:
    goto v_33225;
v_33224:
    v_33271 = stack[-2];
    if (v_33271 == nil) goto v_33252;
    v_33271 = stack[-2];
    stack[-6] = v_33271;
    v_33271 = nil;
    stack[-2] = v_33271;
    goto v_32995;
v_33252:
    v_33271 = nil;
    goto v_32994;
    goto v_33223;
v_33225:
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33264;
    v_33271 = stack[-6];
    {
        fn = elt(env, 24); // intconv
        return (*qfn1(fn))(fn, v_33271);
    }
v_33264:
    v_33271 = stack[-6];
    goto v_33262;
    v_33271 = nil;
v_33262:
    goto v_32994;
v_33223:
    v_33271 = nil;
v_32994:
    return onevalue(v_33271);
}



// Code for constant_expr_listp

static LispObject CC_constant_expr_listp(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33055, v_33056;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
v_32990:
    v_33055 = stack[0];
    if (!consp(v_33055)) goto v_32993;
    else goto v_32994;
v_32993:
    v_33055 = stack[0];
    v_33055 = (v_33055 == nil ? lisp_true : nil);
    v_33056 = v_33055;
    if (v_33055 == nil) goto v_32999;
    v_33055 = v_33056;
    goto v_32989;
v_32999:
    v_33055 = stack[0];
    v_33055 = (is_number(v_33055) ? lisp_true : nil);
    v_33056 = v_33055;
    if (v_33055 == nil) goto v_33004;
    v_33055 = v_33056;
    goto v_32989;
v_33004:
    goto v_33015;
v_33011:
    v_33056 = stack[0];
    goto v_33012;
v_33013:
    v_33055 = elt(env, 1); // constant
    goto v_33014;
v_33015:
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    v_33055 = Lflagp(nil, v_33056, v_33055);
    env = stack[-1];
    v_33056 = v_33055;
    if (v_33055 == nil) goto v_33009;
    v_33055 = v_33056;
    goto v_32989;
v_33009:
    goto v_33029;
v_33025:
    v_33056 = stack[0];
    goto v_33026;
v_33027:
    v_33055 = elt(env, 2); // i
    goto v_33028;
v_33029:
    goto v_33025;
v_33026:
    goto v_33027;
v_33028:
    if (v_33056 == v_33055) goto v_33023;
    else goto v_33024;
v_33023:
    v_33055 = elt(env, 2); // i
    if (!symbolp(v_33055)) v_33055 = nil;
    else { v_33055 = qfastgets(v_33055);
           if (v_33055 != nil) { v_33055 = elt(v_33055, 56); // idvalfn
#ifdef RECORD_GET
             if (v_33055 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_33055 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_33055 == SPID_NOPROP) v_33055 = nil; }}
#endif
    goto v_33022;
v_33024:
    v_33055 = nil;
    goto v_33022;
    v_33055 = nil;
v_33022:
    v_33056 = v_33055;
    if (v_33055 == nil) goto v_33020;
    v_33055 = v_33056;
    goto v_32989;
v_33020:
    v_33055 = nil;
    goto v_32989;
    goto v_32992;
v_32994:
    v_33055 = stack[0];
    v_33055 = qcar(v_33055);
    fn = elt(env, 3); // constant_exprp
    v_33055 = (*qfn1(fn))(fn, v_33055);
    env = stack[-1];
    if (v_33055 == nil) goto v_33046;
    v_33055 = stack[0];
    v_33055 = qcdr(v_33055);
    stack[0] = v_33055;
    goto v_32990;
v_33046:
    v_33055 = nil;
    goto v_32989;
    goto v_32992;
v_32992:
    v_33055 = nil;
v_32989:
    return onevalue(v_33055);
}



// Code for talp_nextt

static LispObject CC_talp_nextt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33271, v_33272, v_33273, v_33274, v_33275, v_33276, v_33277, v_33278;
    LispObject fn;
    LispObject v_32987, v_32986, v_32985;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_nextt");
    va_start(aa, nargs);
    v_32985 = va_arg(aa, LispObject);
    v_32986 = va_arg(aa, LispObject);
    v_32987 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32987,v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32985,v_32986,v_32987);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_32987;
    stack[-7] = v_32986;
    stack[-8] = v_32985;
// end of prologue
    stack[-9] = nil;
    fn = elt(env, 1); // talp_getl
    v_33271 = (*qfnn(fn))(fn, 0);
    env = stack[-10];
    stack[-3] = v_33271;
v_33002:
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33007;
    else goto v_33008;
v_33007:
    v_33271 = nil;
    goto v_33001;
v_33008:
    v_33271 = stack[-3];
    v_33271 = qcar(v_33271);
    v_33273 = v_33271;
    goto v_33022;
v_33018:
    v_33271 = v_33273;
    v_33272 = qcdr(v_33271);
    goto v_33019;
v_33020:
    v_33271 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33021;
v_33022:
    goto v_33018;
v_33019:
    goto v_33020;
v_33021:
    if (v_33272 == v_33271) goto v_33016;
    else goto v_33017;
v_33016:
    goto v_33031;
v_33027:
    v_33271 = v_33273;
    v_33272 = qcar(v_33271);
    goto v_33028;
v_33029:
    v_33271 = stack[-9];
    goto v_33030;
v_33031:
    goto v_33027;
v_33028:
    goto v_33029;
v_33030:
    v_33271 = cons(v_33272, v_33271);
    env = stack[-10];
    stack[-9] = v_33271;
    v_33271 = nil;
    goto v_33015;
v_33017:
    goto v_33043;
v_33039:
    v_33271 = stack[-6];
    goto v_33040;
v_33041:
    v_33272 = v_33273;
    goto v_33042;
v_33043:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    fn = elt(env, 2); // talp_mk!-invs
    v_33271 = (*qfn2(fn))(fn, v_33271, v_33272);
    env = stack[-10];
    goto v_33015;
    v_33271 = nil;
v_33015:
    stack[-2] = v_33271;
    v_33271 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-1] = v_33271;
    v_33271 = stack[-3];
    v_33271 = qcdr(v_33271);
    stack[-3] = v_33271;
    v_33271 = stack[-1];
    if (!consp(v_33271)) goto v_33052;
    else goto v_33053;
v_33052:
    goto v_33002;
v_33053:
v_33003:
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33057;
    else goto v_33058;
v_33057:
    v_33271 = stack[-2];
    goto v_33001;
v_33058:
    goto v_33066;
v_33062:
    stack[0] = stack[-1];
    goto v_33063;
v_33064:
    v_33271 = stack[-3];
    v_33271 = qcar(v_33271);
    v_33273 = v_33271;
    goto v_33079;
v_33075:
    v_33271 = v_33273;
    v_33272 = qcdr(v_33271);
    goto v_33076;
v_33077:
    v_33271 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33078;
v_33079:
    goto v_33075;
v_33076:
    goto v_33077;
v_33078:
    if (v_33272 == v_33271) goto v_33073;
    else goto v_33074;
v_33073:
    goto v_33088;
v_33084:
    v_33271 = v_33273;
    v_33272 = qcar(v_33271);
    goto v_33085;
v_33086:
    v_33271 = stack[-9];
    goto v_33087;
v_33088:
    goto v_33084;
v_33085:
    goto v_33086;
v_33087:
    v_33271 = cons(v_33272, v_33271);
    env = stack[-10];
    stack[-9] = v_33271;
    v_33271 = nil;
    goto v_33072;
v_33074:
    goto v_33100;
v_33096:
    v_33271 = stack[-6];
    goto v_33097;
v_33098:
    v_33272 = v_33273;
    goto v_33099;
v_33100:
    goto v_33096;
v_33097:
    goto v_33098;
v_33099:
    fn = elt(env, 2); // talp_mk!-invs
    v_33271 = (*qfn2(fn))(fn, v_33271, v_33272);
    env = stack[-10];
    goto v_33072;
    v_33271 = nil;
v_33072:
    goto v_33065;
v_33066:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    v_33271 = Lrplacd(nil, stack[0], v_33271);
    env = stack[-10];
    v_33271 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-1] = v_33271;
    v_33271 = stack[-3];
    v_33271 = qcdr(v_33271);
    stack[-3] = v_33271;
    goto v_33003;
v_33001:
    fn = elt(env, 4); // talp_list2vec
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-5] = v_33271;
    v_33271 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_33271;
v_33113:
    goto v_33126;
v_33122:
    v_33271 = stack[-5];
    v_33272 = Lupbv(nil, v_33271);
    env = stack[-10];
    goto v_33123;
v_33124:
    v_33271 = stack[-4];
    goto v_33125;
v_33126:
    goto v_33122;
v_33123:
    goto v_33124;
v_33125:
    v_33271 = difference2(v_33272, v_33271);
    env = stack[-10];
    v_33271 = Lminusp(nil, v_33271);
    env = stack[-10];
    if (v_33271 == nil) goto v_33119;
    v_33271 = nil;
    goto v_33112;
v_33119:
    goto v_33135;
v_33131:
    v_33272 = stack[-5];
    goto v_33132;
v_33133:
    v_33271 = stack[-4];
    goto v_33134;
v_33135:
    goto v_33131;
v_33132:
    goto v_33133;
v_33134:
    v_33271 = *(LispObject *)((char *)v_33272 + (CELL-TAG_VECTOR) + (((intptr_t)v_33271-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_33271;
    v_33271 = stack[0];
    fn = elt(env, 5); // talp_invp
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    if (v_33271 == nil) goto v_33143;
    v_33271 = stack[0];
    v_33271 = ncons(v_33271);
    env = stack[-10];
    goto v_33141;
v_33143:
    v_33271 = nil;
v_33141:
    stack[-3] = v_33271;
    v_33271 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-2] = v_33271;
    v_33271 = stack[-4];
    v_33271 = add1(v_33271);
    env = stack[-10];
    stack[-4] = v_33271;
    v_33271 = stack[-2];
    if (!consp(v_33271)) goto v_33154;
    else goto v_33155;
v_33154:
    goto v_33113;
v_33155:
v_33114:
    goto v_33167;
v_33163:
    v_33271 = stack[-5];
    v_33272 = Lupbv(nil, v_33271);
    env = stack[-10];
    goto v_33164;
v_33165:
    v_33271 = stack[-4];
    goto v_33166;
v_33167:
    goto v_33163;
v_33164:
    goto v_33165;
v_33166:
    v_33271 = difference2(v_33272, v_33271);
    env = stack[-10];
    v_33271 = Lminusp(nil, v_33271);
    env = stack[-10];
    if (v_33271 == nil) goto v_33160;
    v_33271 = stack[-3];
    goto v_33112;
v_33160:
    goto v_33177;
v_33173:
    stack[-1] = stack[-2];
    goto v_33174;
v_33175:
    goto v_33183;
v_33179:
    v_33272 = stack[-5];
    goto v_33180;
v_33181:
    v_33271 = stack[-4];
    goto v_33182;
v_33183:
    goto v_33179;
v_33180:
    goto v_33181;
v_33182:
    v_33271 = *(LispObject *)((char *)v_33272 + (CELL-TAG_VECTOR) + (((intptr_t)v_33271-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_33271;
    v_33271 = stack[0];
    fn = elt(env, 5); // talp_invp
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    if (v_33271 == nil) goto v_33191;
    v_33271 = stack[0];
    v_33271 = ncons(v_33271);
    env = stack[-10];
    goto v_33189;
v_33191:
    v_33271 = nil;
v_33189:
    goto v_33176;
v_33177:
    goto v_33173;
v_33174:
    goto v_33175;
v_33176:
    v_33271 = Lrplacd(nil, stack[-1], v_33271);
    env = stack[-10];
    v_33271 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-2] = v_33271;
    v_33271 = stack[-4];
    v_33271 = add1(v_33271);
    env = stack[-10];
    stack[-4] = v_33271;
    goto v_33114;
v_33112:
    fn = elt(env, 4); // talp_list2vec
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[0] = v_33271;
    goto v_33206;
v_33202:
    v_33271 = stack[-9];
    v_33272 = Lnreverse(nil, v_33271);
    env = stack[-10];
    goto v_33203;
v_33204:
    v_33271 = stack[-6];
    goto v_33205;
v_33206:
    goto v_33202;
v_33203:
    goto v_33204;
v_33205:
    v_33271 = Lnconc(nil, v_33272, v_33271);
    env = stack[-10];
    fn = elt(env, 4); // talp_list2vec
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    stack[-1] = v_33271;
    v_33271 = stack[-6];
    fn = elt(env, 4); // talp_list2vec
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-10];
    v_33272 = stack[-8];
    if (v_33272 == nil) goto v_33215;
    goto v_33234;
v_33218:
    v_33278 = stack[-8];
    goto v_33219;
v_33220:
    v_33277 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33221;
v_33222:
    v_33276 = stack[-7];
    goto v_33223;
v_33224:
    v_33275 = stack[-1];
    goto v_33225;
v_33226:
    v_33274 = v_33271;
    goto v_33227;
v_33228:
    v_33273 = stack[-5];
    goto v_33229;
v_33230:
    v_33272 = stack[0];
    goto v_33231;
v_33232:
    v_33271 = nil;
    goto v_33233;
v_33234:
    goto v_33218;
v_33219:
    goto v_33220;
v_33221:
    goto v_33222;
v_33223:
    goto v_33224;
v_33225:
    goto v_33226;
v_33227:
    goto v_33228;
v_33229:
    goto v_33230;
v_33231:
    goto v_33232;
v_33233:
    fn = elt(env, 6); // talp_nextt1
    v_33271 = (*qfnn(fn))(fn, 8, v_33278, v_33277, v_33276, v_33275, v_33274, v_33273, v_33272, v_33271);
    v_33272 = v_33271;
    v_33271 = v_33272;
    v_33271 = qcar(v_33271);
    if (v_33271 == nil) goto v_33247;
    v_33271 = v_33272;
    v_33271 = qcdr(v_33271);
    goto v_33245;
v_33247:
    v_33271 = nil;
v_33245:
    goto v_33213;
v_33215:
    goto v_33259;
v_33255:
    v_33271 = stack[-1];
    v_33272 = Lupbv(nil, v_33271);
    env = stack[-10];
    goto v_33256;
v_33257:
    v_33271 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33258;
v_33259:
    goto v_33255;
v_33256:
    goto v_33257;
v_33258:
    v_33271 = (LispObject)greaterp2(v_33272, v_33271);
    v_33271 = v_33271 ? lisp_true : nil;
    if (v_33271 == nil) goto v_33253;
    goto v_33267;
v_33263:
    v_33272 = stack[-1];
    goto v_33264;
v_33265:
    v_33271 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33266;
v_33267:
    goto v_33263;
v_33264:
    goto v_33265;
v_33266:
    v_33271 = *(LispObject *)((char *)v_33272 + (CELL-TAG_VECTOR) + (((intptr_t)v_33271-TAG_FIXNUM)/(16/CELL)));
    goto v_33213;
v_33253:
    v_33271 = nil;
v_33213:
    return onevalue(v_33271);
}



// Code for qqe_qadd!-inside

static LispObject CC_qqe_qaddKinside(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33107, v_33108;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
    v_33107 = stack[0];
    if (v_33107 == nil) goto v_33000;
    else goto v_33001;
v_33000:
    v_33107 = lisp_true;
    goto v_32999;
v_33001:
    v_33107 = stack[0];
    v_33107 = (consp(v_33107) ? nil : lisp_true);
    goto v_32999;
    v_33107 = nil;
v_32999:
    if (v_33107 == nil) goto v_32997;
    v_33107 = nil;
    goto v_32993;
v_32997:
    v_33107 = stack[0];
    fn = elt(env, 4); // qqe_op
    v_33107 = (*qfn1(fn))(fn, v_33107);
    env = stack[-3];
    stack[-1] = v_33107;
    goto v_33016;
v_33012:
    v_33108 = elt(env, 1); // a
    goto v_33013;
v_33014:
    v_33107 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33107 = cons(v_33108, v_33107);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_33107; // qqe_qadd!-location!*
    v_33107 = stack[0];
    v_33107 = Lconsp(nil, v_33107);
    env = stack[-3];
    if (v_33107 == nil) goto v_33022;
    v_33107 = stack[-1];
    fn = elt(env, 5); // qqe_qopaddp
    v_33107 = (*qfn1(fn))(fn, v_33107);
    env = stack[-3];
    if (v_33107 == nil) goto v_33026;
    else goto v_33022;
v_33026:
    v_33107 = lisp_true;
    stack[-2] = v_33107;
    v_33107 = stack[-1];
    v_33108 = v_33107;
    v_33107 = stack[0];
    v_33107 = qcdr(v_33107);
    stack[-1] = v_33107;
    v_33107 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    stack[0] = v_33107;
v_33036:
    v_33107 = stack[-1];
    if (v_33107 == nil) goto v_33039;
    v_33107 = stack[-2];
    if (v_33107 == nil) goto v_33039;
    goto v_33040;
v_33039:
    goto v_33035;
v_33040:
    goto v_33051;
v_33047:
    v_33108 = elt(env, 3); // d
    goto v_33048;
v_33049:
    v_33107 = stack[0];
    goto v_33050;
v_33051:
    goto v_33047;
v_33048:
    goto v_33049;
v_33050:
    v_33107 = cons(v_33108, v_33107);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_33107; // qqe_qadd!-location!*
    v_33107 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    stack[0] = v_33107;
    v_33107 = stack[-1];
    if (!consp(v_33107)) goto v_33062;
    v_33107 = stack[-1];
    v_33107 = qcar(v_33107);
    v_33107 = Lconsp(nil, v_33107);
    env = stack[-3];
    if (v_33107 == nil) goto v_33066;
    else goto v_33067;
v_33066:
    v_33107 = nil;
    goto v_33065;
v_33067:
    v_33107 = stack[-1];
    v_33107 = qcar(v_33107);
    v_33107 = CC_qqe_qaddKinside(elt(env, 0), v_33107);
    env = stack[-3];
    goto v_33065;
    v_33107 = nil;
v_33065:
    goto v_33060;
v_33062:
    v_33107 = nil;
    goto v_33060;
    v_33107 = nil;
v_33060:
    if (v_33107 == nil) goto v_33058;
    v_33107 = nil;
    stack[-2] = v_33107;
    goto v_33056;
v_33058:
v_33056:
    v_33107 = stack[-1];
    v_33108 = v_33107;
    v_33107 = stack[-1];
    v_33107 = qcdr(v_33107);
    stack[-1] = v_33107;
    goto v_33036;
v_33035:
    v_33107 = stack[-2];
    if (v_33107 == nil) goto v_33087;
    else goto v_33088;
v_33087:
    v_33107 = v_33108;
    goto v_32993;
v_33088:
    v_33107 = nil;
    goto v_32993;
    goto v_33020;
v_33022:
    v_33107 = stack[0];
    v_33107 = Lconsp(nil, v_33107);
    env = stack[-3];
    if (v_33107 == nil) goto v_33096;
    v_33107 = stack[-1];
    fn = elt(env, 5); // qqe_qopaddp
    v_33107 = (*qfn1(fn))(fn, v_33107);
    if (v_33107 == nil) goto v_33096;
    v_33107 = lisp_true;
    goto v_32993;
v_33096:
    v_33107 = nil;
    goto v_32993;
v_33020:
    v_33107 = nil;
v_32993:
    return onevalue(v_33107);
}



// Code for tidysqrt

static LispObject CC_tidysqrt(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33019, v_33020;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
    v_33019 = stack[0];
    v_33019 = qcar(v_33019);
    fn = elt(env, 1); // tidysqrtf
    v_33019 = (*qfn1(fn))(fn, v_33019);
    env = stack[-2];
    stack[-1] = v_33019;
    v_33019 = stack[-1];
    if (v_33019 == nil) goto v_32996;
    else goto v_32997;
v_32996:
    goto v_33004;
v_33000:
    v_33020 = nil;
    goto v_33001;
v_33002:
    v_33019 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33003;
v_33004:
    goto v_33000;
v_33001:
    goto v_33002;
v_33003:
    return cons(v_33020, v_33019);
v_32997:
    v_33019 = stack[0];
    v_33019 = qcdr(v_33019);
    fn = elt(env, 1); // tidysqrtf
    v_33019 = (*qfn1(fn))(fn, v_33019);
    env = stack[-2];
    goto v_33015;
v_33011:
    stack[0] = stack[-1];
    goto v_33012;
v_33013:
    fn = elt(env, 2); // invsq
    v_33019 = (*qfn1(fn))(fn, v_33019);
    env = stack[-2];
    goto v_33014;
v_33015:
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    {
        LispObject v_33023 = stack[0];
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_33023, v_33019);
    }
    return onevalue(v_33019);
}



// Code for cr!:minusp

static LispObject CC_crTminusp(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33038, v_33039, v_33040;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
// copy arguments values to proper place
    v_33038 = v_32985;
// end of prologue
    v_33039 = v_33038;
    v_33039 = qcdr(v_33039);
    v_33039 = qcar(v_33039);
    v_33038 = qcdr(v_33038);
    v_33038 = qcdr(v_33038);
    v_33040 = v_33039;
    v_33039 = v_33038;
    v_33038 = v_33040;
    if (!consp(v_33038)) goto v_32997;
    else goto v_32998;
v_32997:
    v_33038 = v_33039;
    v_33038 = (LispObject)zerop(v_33038);
    v_33038 = v_33038 ? lisp_true : nil;
    if (v_33038 == nil) goto v_33002;
    else goto v_33003;
v_33002:
    v_33038 = nil;
    goto v_33001;
v_33003:
    goto v_33014;
v_33010:
    v_33039 = v_33040;
    goto v_33011;
v_33012:
    v_33038 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
        return Llessp(nil, v_33039, v_33038);
    v_33038 = nil;
v_33001:
    goto v_32996;
v_32998:
    v_33038 = v_33039;
    v_33038 = qcar(v_33038);
    v_33038 = (LispObject)zerop(v_33038);
    v_33038 = v_33038 ? lisp_true : nil;
    if (v_33038 == nil) goto v_33021;
    else goto v_33022;
v_33021:
    v_33038 = nil;
    goto v_33020;
v_33022:
    goto v_33034;
v_33030:
    v_33038 = v_33040;
    v_33039 = qcar(v_33038);
    goto v_33031;
v_33032:
    v_33038 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33033;
v_33034:
    goto v_33030;
v_33031:
    goto v_33032;
v_33033:
        return Llessp(nil, v_33039, v_33038);
    v_33038 = nil;
v_33020:
    goto v_32996;
    v_33038 = nil;
v_32996:
    return onevalue(v_33038);
}



// Code for expttermp

static LispObject CC_expttermp(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33020, v_33021, v_33022, v_33023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33022 = v_32986;
    v_33023 = v_32985;
// end of prologue
    goto v_32997;
v_32993:
    v_33021 = v_33023;
    goto v_32994;
v_32995:
    v_33020 = elt(env, 1); // expt
    goto v_32996;
v_32997:
    goto v_32993;
v_32994:
    goto v_32995;
v_32996:
    if (!consp(v_33021)) goto v_32991;
    v_33021 = qcar(v_33021);
    if (v_33021 == v_33020) goto v_32990;
    else goto v_32991;
v_32990:
    goto v_33005;
v_33001:
    v_33020 = v_33023;
    v_33020 = qcdr(v_33020);
    v_33020 = qcar(v_33020);
    goto v_33002;
v_33003:
    v_33021 = v_33022;
    goto v_33004;
v_33005:
    goto v_33001;
v_33002:
    goto v_33003;
v_33004:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_33020, v_33021);
    }
v_32991:
    goto v_33017;
v_33013:
    v_33020 = v_33023;
    goto v_33014;
v_33015:
    v_33021 = v_33022;
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_33020, v_33021);
    }
    v_33020 = nil;
    return onevalue(v_33020);
}



// Code for xriterion_2

static LispObject CC_xriterion_2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33129, v_33130, v_33131;
    LispObject fn;
    LispObject v_32987, v_32986, v_32985;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_2");
    va_start(aa, nargs);
    v_32985 = va_arg(aa, LispObject);
    v_32986 = va_arg(aa, LispObject);
    v_32987 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32987,v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32985,v_32986,v_32987);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_32987;
    stack[-1] = v_32986;
    stack[-2] = v_32985;
// end of prologue
v_32984:
    v_33129 = stack[-1];
    if (v_33129 == nil) goto v_32991;
    else goto v_32992;
v_32991:
    v_33129 = nil;
    goto v_32990;
v_32992:
    goto v_33001;
v_32997:
    v_33129 = stack[-2];
    v_33129 = qcdr(v_33129);
    v_33130 = qcar(v_33129);
    goto v_32998;
v_32999:
    v_33129 = elt(env, 1); // wedge_pair
    goto v_33000;
v_33001:
    goto v_32997;
v_32998:
    goto v_32999;
v_33000:
    if (v_33130 == v_33129) goto v_32996;
    v_33129 = nil;
    goto v_32990;
v_32996:
    v_33129 = stack[-1];
    v_33129 = qcar(v_33129);
    stack[-3] = v_33129;
    goto v_33023;
v_33019:
    goto v_33032;
v_33026:
    v_33131 = stack[-3];
    goto v_33027;
v_33028:
    v_33130 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33029;
v_33030:
    v_33129 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33031;
v_33032:
    goto v_33026;
v_33027:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    v_33129 = list2star(v_33131, v_33130, v_33129);
    env = stack[-4];
    v_33130 = ncons(v_33129);
    env = stack[-4];
    goto v_33020;
v_33021:
    v_33129 = stack[-2];
    v_33129 = qcdr(v_33129);
    v_33129 = qcdr(v_33129);
    v_33129 = qcar(v_33129);
    goto v_33022;
v_33023:
    goto v_33019;
v_33020:
    goto v_33021;
v_33022:
    if (equal(v_33130, v_33129)) goto v_33018;
    goto v_33049;
v_33045:
    goto v_33055;
v_33051:
    v_33130 = stack[-3];
    goto v_33052;
v_33053:
    v_33129 = stack[-3];
    goto v_33054;
v_33055:
    goto v_33051;
v_33052:
    goto v_33053;
v_33054:
    v_33130 = list2(v_33130, v_33129);
    env = stack[-4];
    goto v_33046;
v_33047:
    v_33129 = stack[-2];
    v_33129 = qcar(v_33129);
    goto v_33048;
v_33049:
    goto v_33045;
v_33046:
    goto v_33047;
v_33048:
    fn = elt(env, 5); // xdiv
    v_33129 = (*qfn2(fn))(fn, v_33130, v_33129);
    env = stack[-4];
    if (v_33129 == nil) goto v_33042;
    else goto v_33043;
v_33042:
    v_33129 = nil;
    goto v_33041;
v_33043:
    goto v_33072;
v_33068:
    v_33130 = stack[-3];
    goto v_33069;
v_33070:
    v_33129 = stack[-2];
    v_33129 = qcdr(v_33129);
    v_33129 = qcdr(v_33129);
    v_33129 = qcdr(v_33129);
    v_33129 = qcar(v_33129);
    goto v_33071;
v_33072:
    goto v_33068;
v_33069:
    goto v_33070;
v_33071:
    fn = elt(env, 6); // make_wedge_pair
    v_33129 = (*qfn2(fn))(fn, v_33130, v_33129);
    env = stack[-4];
    v_33130 = v_33129;
    v_33129 = v_33130;
    if (v_33129 == nil) goto v_33082;
    else goto v_33083;
v_33082:
    v_33129 = lisp_true;
    goto v_33081;
v_33083:
    goto v_33093;
v_33089:
    goto v_33090;
v_33091:
    v_33129 = stack[0];
    goto v_33092;
v_33093:
    goto v_33089;
v_33090:
    goto v_33091;
v_33092:
    fn = elt(env, 7); // find_item
    v_33129 = (*qfn2(fn))(fn, v_33130, v_33129);
    env = stack[-4];
    v_33129 = (v_33129 == nil ? lisp_true : nil);
    goto v_33081;
    v_33129 = nil;
v_33081:
    if (v_33129 == nil) goto v_33065;
    else goto v_33066;
v_33065:
    v_33129 = nil;
    goto v_33064;
v_33066:
    v_33129 = qvalue(elt(env, 2)); // !*trxideal
    if (v_33129 == nil) goto v_33103;
    goto v_33110;
v_33106:
    v_33130 = elt(env, 3); // "criterion 2 hit"
    goto v_33107;
v_33108:
    v_33129 = elt(env, 4); // last
    goto v_33109;
v_33110:
    goto v_33106;
v_33107:
    goto v_33108;
v_33109:
    fn = elt(env, 8); // writepri
    v_33129 = (*qfn2(fn))(fn, v_33130, v_33129);
    env = stack[-4];
    goto v_33101;
v_33103:
v_33101:
    v_33129 = lisp_true;
    goto v_33064;
    v_33129 = nil;
v_33064:
    goto v_33041;
    v_33129 = nil;
v_33041:
    goto v_33016;
v_33018:
    v_33129 = nil;
    goto v_33016;
    v_33129 = nil;
v_33016:
    if (v_33129 == nil) goto v_33014;
    else goto v_33013;
v_33014:
    goto v_33124;
v_33118:
    v_33131 = stack[-2];
    goto v_33119;
v_33120:
    v_33129 = stack[-1];
    v_33130 = qcdr(v_33129);
    goto v_33121;
v_33122:
    v_33129 = stack[0];
    goto v_33123;
v_33124:
    goto v_33118;
v_33119:
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    stack[-2] = v_33131;
    stack[-1] = v_33130;
    stack[0] = v_33129;
    goto v_32984;
v_33013:
    goto v_32990;
    v_33129 = nil;
v_32990:
    return onevalue(v_33129);
}



// Code for preproc

static LispObject CC_preproc(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33002, v_33003;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
// copy arguments values to proper place
    v_33002 = v_32985;
// end of prologue
    fn = elt(env, 1); // preproc1
    v_33002 = (*qfn1(fn))(fn, v_33002);
    v_33003 = v_33002;
    v_33002 = v_33003;
    if (v_33002 == nil) goto v_32995;
    v_33002 = v_33003;
    v_33002 = qcar(v_33002);
    goto v_32989;
v_32995:
    v_33002 = v_33003;
    goto v_32989;
    v_33002 = nil;
v_32989:
    return onevalue(v_33002);
}



// Code for dvertex!-to!-projector

static LispObject CC_dvertexKtoKprojector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33076, v_33077, v_33078;
    LispObject fn;
    LispObject v_32987, v_32986, v_32985;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvertex-to-projector");
    va_start(aa, nargs);
    v_32985 = va_arg(aa, LispObject);
    v_32986 = va_arg(aa, LispObject);
    v_32987 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32987,v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32985,v_32986,v_32987);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_32987;
    stack[-1] = v_32986;
    stack[-2] = v_32985;
// end of prologue
    goto v_33002;
v_32996:
    v_33076 = stack[-2];
    v_33076 = qcdr(v_33076);
    v_33078 = qcar(v_33076);
    goto v_32997;
v_32998:
    v_33077 = stack[-1];
    goto v_32999;
v_33000:
    v_33076 = stack[0];
    goto v_33001;
v_33002:
    goto v_32996;
v_32997:
    goto v_32998;
v_32999:
    goto v_33000;
v_33001:
    fn = elt(env, 1); // mktails
    v_33076 = (*qfnn(fn))(fn, 3, v_33078, v_33077, v_33076);
    env = stack[-4];
    stack[-3] = v_33076;
    v_33076 = stack[-3];
    v_33076 = qcar(v_33076);
    fn = elt(env, 2); // repeatsp
    v_33076 = (*qfn1(fn))(fn, v_33076);
    env = stack[-4];
    if (v_33076 == nil) goto v_33011;
    v_33076 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32994;
v_33011:
    goto v_33023;
v_33017:
    v_33076 = stack[-2];
    v_33076 = qcdr(v_33076);
    v_33076 = qcdr(v_33076);
    v_33078 = qcar(v_33076);
    goto v_33018;
v_33019:
    v_33077 = stack[-1];
    goto v_33020;
v_33021:
    v_33076 = stack[-3];
    v_33076 = qcdr(v_33076);
    goto v_33022;
v_33023:
    goto v_33017;
v_33018:
    goto v_33019;
v_33020:
    goto v_33021;
v_33022:
    fn = elt(env, 1); // mktails
    v_33076 = (*qfnn(fn))(fn, 3, v_33078, v_33077, v_33076);
    env = stack[-4];
    stack[-1] = v_33076;
    v_33076 = stack[-1];
    v_33076 = qcar(v_33076);
    fn = elt(env, 2); // repeatsp
    v_33076 = (*qfn1(fn))(fn, v_33076);
    env = stack[-4];
    if (v_33076 == nil) goto v_33034;
    v_33076 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32994;
v_33034:
    v_33076 = stack[-1];
    v_33076 = qcdr(v_33076);
    stack[0] = v_33076;
    goto v_33046;
v_33042:
    v_33076 = stack[-3];
    stack[-2] = qcar(v_33076);
    goto v_33043;
v_33044:
    v_33076 = stack[-1];
    v_33076 = qcar(v_33076);
    v_33076 = Lreverse(nil, v_33076);
    env = stack[-4];
    goto v_33045;
v_33046:
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    fn = elt(env, 3); // prop!-simp
    v_33076 = (*qfn2(fn))(fn, stack[-2], v_33076);
    env = stack[-4];
    stack[-2] = v_33076;
    v_33076 = stack[-2];
    fn = elt(env, 4); // mk!-contract!-coeff
    v_33076 = (*qfn1(fn))(fn, v_33076);
    env = stack[-4];
    goto v_33059;
v_33055:
    stack[-1] = v_33076;
    goto v_33056;
v_33057:
    goto v_33068;
v_33062:
    v_33076 = stack[-2];
    v_33076 = qcdr(v_33076);
    v_33078 = qcar(v_33076);
    goto v_33063;
v_33064:
    v_33076 = stack[-2];
    v_33076 = qcdr(v_33076);
    v_33077 = qcdr(v_33076);
    goto v_33065;
v_33066:
    v_33076 = stack[0];
    goto v_33067;
v_33068:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    fn = elt(env, 5); // dpropagator
    v_33076 = (*qfnn(fn))(fn, 3, v_33078, v_33077, v_33076);
    goto v_33058;
v_33059:
    goto v_33055;
v_33056:
    goto v_33057;
v_33058:
    {
        LispObject v_33083 = stack[-1];
        return cons(v_33083, v_33076);
    }
v_32994:
    return onevalue(v_33076);
}



// Code for red_extract

static LispObject CC_red_extract(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33025, v_33026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_32985;
// end of prologue
    goto v_32992;
v_32988:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32989;
v_32990:
    v_33025 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_33025 = (*qfn1(fn))(fn, v_33025);
    env = stack[-4];
    goto v_32991;
v_32992:
    goto v_32988;
v_32989:
    goto v_32990;
v_32991:
    fn = elt(env, 2); // dp_comp
    v_33025 = (*qfn2(fn))(fn, stack[0], v_33025);
    env = stack[-4];
    stack[-3] = v_33025;
    goto v_33002;
v_32998:
    goto v_33010;
v_33004:
    v_33025 = stack[-2];
    fn = elt(env, 3); // bas_nr
    stack[-1] = (*qfn1(fn))(fn, v_33025);
    env = stack[-4];
    goto v_33005;
v_33006:
    v_33025 = stack[-2];
    fn = elt(env, 4); // bas_dpoly
    stack[0] = (*qfn1(fn))(fn, v_33025);
    env = stack[-4];
    goto v_33007;
v_33008:
    goto v_33020;
v_33016:
    v_33025 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_33026 = (*qfn1(fn))(fn, v_33025);
    env = stack[-4];
    goto v_33017;
v_33018:
    v_33025 = stack[-3];
    goto v_33019;
v_33020:
    goto v_33016;
v_33017:
    goto v_33018;
v_33019:
    fn = elt(env, 5); // dp_diff
    v_33025 = (*qfn2(fn))(fn, v_33026, v_33025);
    env = stack[-4];
    goto v_33009;
v_33010:
    goto v_33004;
v_33005:
    goto v_33006;
v_33007:
    goto v_33008;
v_33009:
    fn = elt(env, 6); // bas_make1
    v_33026 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33025);
    goto v_32999;
v_33000:
    v_33025 = stack[-3];
    goto v_33001;
v_33002:
    goto v_32998;
v_32999:
    goto v_33000;
v_33001:
    return cons(v_33026, v_33025);
}



// Code for !*hfac

static LispObject CC_Hhfac(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33041, v_33042, v_33043;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
    v_33041 = stack[0];
    v_33041 = integerp(v_33041);
    if (v_33041 == nil) goto v_32993;
    else goto v_32994;
v_32993:
    v_33041 = lisp_true;
    goto v_32992;
v_32994:
    goto v_33008;
v_33004:
    v_33042 = stack[0];
    goto v_33005;
v_33006:
    v_33041 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33007;
v_33008:
    goto v_33004;
v_33005:
    goto v_33006;
v_33007:
    v_33041 = (LispObject)lessp2(v_33042, v_33041);
    v_33041 = v_33041 ? lisp_true : nil;
    env = stack[-1];
    if (v_33041 == nil) goto v_33002;
    else goto v_33001;
v_33002:
    goto v_33016;
v_33012:
    v_33042 = stack[0];
    goto v_33013;
v_33014:
    v_33041 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33041 = (LispObject)greaterp2(v_33042, v_33041);
    v_33041 = v_33041 ? lisp_true : nil;
    env = stack[-1];
v_33001:
    goto v_32992;
    v_33041 = nil;
v_32992:
    if (v_33041 == nil) goto v_32990;
    goto v_33026;
v_33020:
    v_33043 = elt(env, 1); // avector
    goto v_33021;
v_33022:
    v_33042 = (LispObject)208+TAG_FIXNUM; // 13
    goto v_33023;
v_33024:
    v_33041 = elt(env, 2); // "Invalid index"
    goto v_33025;
v_33026:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_33043, v_33042, v_33041);
    }
v_32990:
    goto v_33036;
v_33032:
    v_33041 = elt(env, 3); // hfactors
    fn = elt(env, 5); // getavalue
    v_33042 = (*qfn1(fn))(fn, v_33041);
    goto v_33033;
v_33034:
    v_33041 = stack[0];
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    v_33041 = *(LispObject *)((char *)v_33042 + (CELL-TAG_VECTOR) + (((intptr_t)v_33041-TAG_FIXNUM)/(16/CELL)));
    goto v_32988;
    v_33041 = nil;
v_32988:
    return onevalue(v_33041);
}



// Code for rtrnda

static LispObject CC_rtrnda(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33041, v_33042, v_33043;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33042 = v_32986;
    stack[0] = v_32985;
// end of prologue
    v_33041 = stack[0];
    if (!consp(v_33041)) goto v_32994;
    else goto v_32995;
v_32994:
    v_33041 = stack[0];
    v_33041 = (LispObject)zerop(v_33041);
    v_33041 = v_33041 ? lisp_true : nil;
    env = stack[-1];
    goto v_32993;
v_32995:
    goto v_33005;
v_33001:
    v_33041 = stack[0];
    v_33041 = qcdr(v_33041);
    v_33043 = qcar(v_33041);
    goto v_33002;
v_33003:
    v_33041 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33004;
v_33005:
    goto v_33001;
v_33002:
    goto v_33003;
v_33004:
    v_33041 = (v_33043 == v_33041 ? lisp_true : nil);
    goto v_32993;
    v_33041 = nil;
v_32993:
    if (v_33041 == nil) goto v_32991;
    goto v_33016;
v_33012:
    v_33042 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33013;
v_33014:
    v_33041 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33041 = cons(v_33042, v_33041);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_33041; // rlval!#
    v_33041 = stack[0];
    goto v_32989;
v_32991:
    goto v_33027;
v_33023:
    v_33041 = stack[0];
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    fn = elt(env, 2); // round!:dec1
    v_33041 = (*qfn2(fn))(fn, v_33041, v_33042);
    env = stack[-1];
    goto v_33036;
v_33032:
    v_33042 = v_33041;
    qvalue(elt(env, 1)) = v_33042; // rlval!#
    v_33042 = qcar(v_33042);
    goto v_33033;
v_33034:
    v_33041 = qcdr(v_33041);
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    {
        fn = elt(env, 3); // decimal2internal
        return (*qfn2(fn))(fn, v_33042, v_33041);
    }
    v_33041 = nil;
v_32989:
    return onevalue(v_33041);
}



// Code for gd_newtype

static LispObject CC_gd_newtype(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33047, v_33048, v_33049, v_33050;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33049 = v_32986;
    v_33050 = v_32985;
// end of prologue
    goto v_32996;
v_32992:
    v_33048 = v_33050;
    goto v_32993;
v_32994:
    v_33047 = v_33049;
    goto v_32995;
v_32996:
    goto v_32992;
v_32993:
    goto v_32994;
v_32995:
    if (v_33048 == v_33047) goto v_32990;
    else goto v_32991;
v_32990:
    v_33047 = v_33050;
    goto v_32989;
v_32991:
    goto v_33006;
v_33002:
    v_33048 = v_33050;
    goto v_33003;
v_33004:
    v_33047 = elt(env, 1); // gec
    goto v_33005;
v_33006:
    goto v_33002;
v_33003:
    goto v_33004;
v_33005:
    if (v_33048 == v_33047) goto v_33000;
    else goto v_33001;
v_33000:
    goto v_33017;
v_33013:
    v_33048 = v_33049;
    goto v_33014;
v_33015:
    v_33047 = elt(env, 2); // geg
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    if (v_33048 == v_33047) goto v_33011;
    else goto v_33012;
v_33011:
    v_33047 = elt(env, 1); // gec
    goto v_33010;
v_33012:
    v_33047 = nil;
    goto v_33010;
    v_33047 = nil;
v_33010:
    goto v_32989;
v_33001:
    goto v_33030;
v_33026:
    v_33048 = v_33050;
    goto v_33027;
v_33028:
    v_33047 = elt(env, 2); // geg
    goto v_33029;
v_33030:
    goto v_33026;
v_33027:
    goto v_33028;
v_33029:
    if (v_33048 == v_33047) goto v_33024;
    else goto v_33025;
v_33024:
    v_33047 = v_33049;
    goto v_32989;
v_33025:
    goto v_33040;
v_33036:
    v_33048 = v_33049;
    goto v_33037;
v_33038:
    v_33047 = elt(env, 1); // gec
    goto v_33039;
v_33040:
    goto v_33036;
v_33037:
    goto v_33038;
v_33039:
    if (v_33048 == v_33047) goto v_33034;
    else goto v_33035;
v_33034:
    v_33047 = nil;
    goto v_32989;
v_33035:
    v_33047 = elt(env, 3); // ger
    goto v_32989;
    v_33047 = nil;
v_32989:
    return onevalue(v_33047);
}



// Code for subsubf

static LispObject CC_subsubf(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33228, v_33229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_32986;
    stack[-6] = v_32985;
// end of prologue
    stack[-4] = nil;
    v_33228 = stack[-5];
    v_33228 = qcdr(v_33228);
    v_33228 = qcdr(v_33228);
    stack[0] = v_33228;
v_32995:
    v_33228 = stack[0];
    if (v_33228 == nil) goto v_33001;
    else goto v_33002;
v_33001:
    goto v_32994;
v_33002:
    v_33228 = stack[0];
    v_33228 = qcar(v_33228);
    goto v_33016;
v_33012:
    v_33229 = v_33228;
    goto v_33013;
v_33014:
    v_33228 = stack[-6];
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33228 = Lassoc(nil, v_33229, v_33228);
    stack[-1] = v_33228;
    if (v_33228 == nil) goto v_33011;
    goto v_33025;
v_33021:
    v_33229 = stack[-1];
    goto v_33022;
v_33023:
    v_33228 = stack[-4];
    goto v_33024;
v_33025:
    goto v_33021;
v_33022:
    goto v_33023;
v_33024:
    v_33228 = cons(v_33229, v_33228);
    env = stack[-8];
    stack[-4] = v_33228;
    goto v_33033;
v_33029:
    v_33229 = stack[-1];
    goto v_33030;
v_33031:
    v_33228 = stack[-6];
    goto v_33032;
v_33033:
    goto v_33029;
v_33030:
    goto v_33031;
v_33032:
    v_33228 = Ldelete(nil, v_33229, v_33228);
    env = stack[-8];
    stack[-6] = v_33228;
    goto v_33009;
v_33011:
v_33009:
    v_33228 = stack[0];
    v_33228 = qcdr(v_33228);
    stack[0] = v_33228;
    goto v_32995;
v_32994:
    goto v_33043;
v_33039:
    goto v_33049;
v_33045:
    v_33229 = stack[-6];
    goto v_33046;
v_33047:
    v_33228 = stack[-5];
    v_33228 = qcar(v_33228);
    goto v_33048;
v_33049:
    goto v_33045;
v_33046:
    goto v_33047;
v_33048:
    stack[-3] = Lsublis(nil, v_33229, v_33228);
    env = stack[-8];
    goto v_33040;
v_33041:
    v_33228 = stack[-5];
    v_33228 = qcdr(v_33228);
    stack[-5] = v_33228;
    v_33228 = stack[-5];
    if (v_33228 == nil) goto v_33063;
    else goto v_33064;
v_33063:
    v_33228 = nil;
    goto v_33057;
v_33064:
    v_33228 = stack[-5];
    v_33228 = qcar(v_33228);
    goto v_33076;
v_33072:
    v_33229 = stack[-6];
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    goto v_33072;
v_33073:
    goto v_33074;
v_33075:
    fn = elt(env, 3); // subsublis
    v_33228 = (*qfn2(fn))(fn, v_33229, v_33228);
    env = stack[-8];
    v_33228 = ncons(v_33228);
    env = stack[-8];
    stack[-1] = v_33228;
    stack[-2] = v_33228;
v_33058:
    v_33228 = stack[-5];
    v_33228 = qcdr(v_33228);
    stack[-5] = v_33228;
    v_33228 = stack[-5];
    if (v_33228 == nil) goto v_33083;
    else goto v_33084;
v_33083:
    v_33228 = stack[-2];
    goto v_33057;
v_33084:
    goto v_33092;
v_33088:
    stack[0] = stack[-1];
    goto v_33089;
v_33090:
    v_33228 = stack[-5];
    v_33228 = qcar(v_33228);
    goto v_33103;
v_33099:
    v_33229 = stack[-6];
    goto v_33100;
v_33101:
    goto v_33102;
v_33103:
    goto v_33099;
v_33100:
    goto v_33101;
v_33102:
    fn = elt(env, 3); // subsublis
    v_33228 = (*qfn2(fn))(fn, v_33229, v_33228);
    env = stack[-8];
    v_33228 = ncons(v_33228);
    env = stack[-8];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    v_33228 = Lrplacd(nil, stack[0], v_33228);
    env = stack[-8];
    v_33228 = stack[-1];
    v_33228 = qcdr(v_33228);
    stack[-1] = v_33228;
    goto v_33058;
v_33057:
    goto v_33042;
v_33043:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    v_33228 = cons(stack[-3], v_33228);
    env = stack[-8];
    stack[-5] = v_33228;
    v_33228 = stack[-4];
    if (v_33228 == nil) goto v_33110;
    else goto v_33111;
v_33110:
    v_33228 = stack[-5];
    goto v_32991;
v_33111:
    goto v_33119;
v_33115:
    v_33228 = stack[-4];
    fn = elt(env, 4); // reversip!*
    v_33228 = (*qfn1(fn))(fn, v_33228);
    env = stack[-8];
    stack[-7] = v_33228;
    v_33228 = stack[-7];
    if (v_33228 == nil) goto v_33130;
    else goto v_33131;
v_33130:
    v_33228 = nil;
    v_33229 = v_33228;
    goto v_33124;
v_33131:
    v_33228 = stack[-7];
    v_33228 = qcar(v_33228);
    v_33229 = v_33228;
    goto v_33145;
v_33139:
    stack[-1] = elt(env, 1); // equal
    goto v_33140;
v_33141:
    v_33228 = v_33229;
    stack[0] = qcar(v_33228);
    goto v_33142;
v_33143:
    v_33228 = v_33229;
    v_33228 = qcdr(v_33228);
    fn = elt(env, 5); // aeval
    v_33228 = (*qfn1(fn))(fn, v_33228);
    env = stack[-8];
    goto v_33144;
v_33145:
    goto v_33139;
v_33140:
    goto v_33141;
v_33142:
    goto v_33143;
v_33144:
    v_33228 = list3(stack[-1], stack[0], v_33228);
    env = stack[-8];
    v_33228 = ncons(v_33228);
    env = stack[-8];
    stack[-3] = v_33228;
    stack[-4] = v_33228;
v_33125:
    v_33228 = stack[-7];
    v_33228 = qcdr(v_33228);
    stack[-7] = v_33228;
    v_33228 = stack[-7];
    if (v_33228 == nil) goto v_33156;
    else goto v_33157;
v_33156:
    v_33228 = stack[-4];
    v_33229 = v_33228;
    goto v_33124;
v_33157:
    goto v_33165;
v_33161:
    stack[-2] = stack[-3];
    goto v_33162;
v_33163:
    v_33228 = stack[-7];
    v_33228 = qcar(v_33228);
    v_33229 = v_33228;
    goto v_33178;
v_33172:
    stack[-1] = elt(env, 1); // equal
    goto v_33173;
v_33174:
    v_33228 = v_33229;
    stack[0] = qcar(v_33228);
    goto v_33175;
v_33176:
    v_33228 = v_33229;
    v_33228 = qcdr(v_33228);
    fn = elt(env, 5); // aeval
    v_33228 = (*qfn1(fn))(fn, v_33228);
    env = stack[-8];
    goto v_33177;
v_33178:
    goto v_33172;
v_33173:
    goto v_33174;
v_33175:
    goto v_33176;
v_33177:
    v_33228 = list3(stack[-1], stack[0], v_33228);
    env = stack[-8];
    v_33228 = ncons(v_33228);
    env = stack[-8];
    goto v_33164;
v_33165:
    goto v_33161;
v_33162:
    goto v_33163;
v_33164:
    v_33228 = Lrplacd(nil, stack[-2], v_33228);
    env = stack[-8];
    v_33228 = stack[-3];
    v_33228 = qcdr(v_33228);
    stack[-3] = v_33228;
    goto v_33125;
v_33124:
    goto v_33116;
v_33117:
    v_33228 = stack[-5];
    goto v_33118;
v_33119:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    fn = elt(env, 6); // aconc!*
    v_33228 = (*qfn2(fn))(fn, v_33229, v_33228);
    env = stack[-8];
    stack[-5] = v_33228;
    v_33228 = stack[-6];
    if (v_33228 == nil) goto v_33191;
    v_33228 = stack[-5];
    {
        fn = elt(env, 7); // subeval
        return (*qfn1(fn))(fn, v_33228);
    }
v_33191:
    goto v_33203;
v_33199:
    goto v_33210;
v_33206:
    goto v_33216;
v_33212:
    goto v_33222;
v_33218:
    v_33229 = elt(env, 2); // sub
    goto v_33219;
v_33220:
    v_33228 = stack[-5];
    goto v_33221;
v_33222:
    goto v_33218;
v_33219:
    goto v_33220;
v_33221:
    v_33229 = cons(v_33229, v_33228);
    env = stack[-8];
    goto v_33213;
v_33214:
    v_33228 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33215;
v_33216:
    goto v_33212;
v_33213:
    goto v_33214;
v_33215:
    fn = elt(env, 8); // mksp
    v_33229 = (*qfn2(fn))(fn, v_33229, v_33228);
    env = stack[-8];
    goto v_33207;
v_33208:
    v_33228 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33209;
v_33210:
    goto v_33206;
v_33207:
    goto v_33208;
v_33209:
    v_33228 = cons(v_33229, v_33228);
    env = stack[-8];
    v_33229 = ncons(v_33228);
    env = stack[-8];
    goto v_33200;
v_33201:
    v_33228 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33202;
v_33203:
    goto v_33199;
v_33200:
    goto v_33201;
v_33202:
    v_33228 = cons(v_33229, v_33228);
    env = stack[-8];
    {
        fn = elt(env, 9); // mk!*sq
        return (*qfn1(fn))(fn, v_33228);
    }
    v_33228 = nil;
v_32991:
    return onevalue(v_33228);
}



// Code for rand!-comb

static LispObject CC_randKcomb(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33189, v_33190, v_33191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_32986;
    stack[-1] = v_32985;
// end of prologue
    goto v_32996;
v_32992:
    v_33190 = stack[-3];
    goto v_32993;
v_32994:
    v_33189 = stack[-1];
    goto v_32995;
v_32996:
    goto v_32992;
v_32993:
    goto v_32994;
v_32995:
    if (equal(v_33190, v_33189)) goto v_32990;
    else goto v_32991;
v_32990:
    v_33189 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_33189;
    goto v_33016;
v_33012:
    v_33189 = stack[-3];
    v_33190 = sub1(v_33189);
    env = stack[-5];
    goto v_33013;
v_33014:
    v_33189 = stack[-4];
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33189 = difference2(v_33190, v_33189);
    env = stack[-5];
    v_33189 = Lminusp(nil, v_33189);
    env = stack[-5];
    if (v_33189 == nil) goto v_33009;
    v_33189 = nil;
    goto v_33003;
v_33009:
    v_33189 = stack[-4];
    v_33189 = ncons(v_33189);
    env = stack[-5];
    stack[-1] = v_33189;
    stack[-2] = v_33189;
v_33004:
    v_33189 = stack[-4];
    v_33189 = add1(v_33189);
    env = stack[-5];
    stack[-4] = v_33189;
    goto v_33035;
v_33031:
    v_33189 = stack[-3];
    v_33190 = sub1(v_33189);
    env = stack[-5];
    goto v_33032;
v_33033:
    v_33189 = stack[-4];
    goto v_33034;
v_33035:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    v_33189 = difference2(v_33190, v_33189);
    env = stack[-5];
    v_33189 = Lminusp(nil, v_33189);
    env = stack[-5];
    if (v_33189 == nil) goto v_33028;
    v_33189 = stack[-2];
    goto v_33003;
v_33028:
    goto v_33045;
v_33041:
    stack[0] = stack[-1];
    goto v_33042;
v_33043:
    v_33189 = stack[-4];
    v_33189 = ncons(v_33189);
    env = stack[-5];
    goto v_33044;
v_33045:
    goto v_33041;
v_33042:
    goto v_33043;
v_33044:
    v_33189 = Lrplacd(nil, stack[0], v_33189);
    env = stack[-5];
    v_33189 = stack[-1];
    v_33189 = qcdr(v_33189);
    stack[-1] = v_33189;
    goto v_33004;
v_33003:
    goto v_32989;
v_32991:
    stack[-2] = nil;
    goto v_33065;
v_33061:
    goto v_33071;
v_33067:
    v_33190 = stack[-1];
    goto v_33068;
v_33069:
    v_33189 = stack[-3];
    goto v_33070;
v_33071:
    goto v_33067;
v_33068:
    goto v_33069;
v_33070:
    v_33190 = difference2(v_33190, v_33189);
    env = stack[-5];
    goto v_33062;
v_33063:
    v_33189 = stack[-3];
    goto v_33064;
v_33065:
    goto v_33061;
v_33062:
    goto v_33063;
v_33064:
    v_33189 = (LispObject)lessp2(v_33190, v_33189);
    v_33189 = v_33189 ? lisp_true : nil;
    env = stack[-5];
    if (v_33189 == nil) goto v_33059;
    goto v_33083;
v_33079:
    stack[0] = stack[-1];
    goto v_33080;
v_33081:
    goto v_33090;
v_33086:
    v_33190 = stack[-1];
    goto v_33087;
v_33088:
    v_33189 = stack[-3];
    goto v_33089;
v_33090:
    goto v_33086;
v_33087:
    goto v_33088;
v_33089:
    v_33189 = difference2(v_33190, v_33189);
    env = stack[-5];
    goto v_33082;
v_33083:
    goto v_33079;
v_33080:
    goto v_33081;
v_33082:
    v_33189 = CC_randKcomb(elt(env, 0), stack[0], v_33189);
    env = stack[-5];
    stack[-3] = v_33189;
    v_33189 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_33189;
v_33096:
    goto v_33108;
v_33104:
    v_33189 = stack[-1];
    v_33190 = sub1(v_33189);
    env = stack[-5];
    goto v_33105;
v_33106:
    v_33189 = stack[0];
    goto v_33107;
v_33108:
    goto v_33104;
v_33105:
    goto v_33106;
v_33107:
    v_33189 = difference2(v_33190, v_33189);
    env = stack[-5];
    v_33189 = Lminusp(nil, v_33189);
    env = stack[-5];
    if (v_33189 == nil) goto v_33101;
    goto v_33095;
v_33101:
    goto v_33121;
v_33117:
    v_33190 = stack[0];
    goto v_33118;
v_33119:
    v_33189 = stack[-3];
    goto v_33120;
v_33121:
    goto v_33117;
v_33118:
    goto v_33119;
v_33120:
    v_33189 = Lmember(nil, v_33190, v_33189);
    if (v_33189 == nil) goto v_33115;
    else goto v_33116;
v_33115:
    goto v_33130;
v_33126:
    v_33190 = stack[0];
    goto v_33127;
v_33128:
    v_33189 = stack[-2];
    goto v_33129;
v_33130:
    goto v_33126;
v_33127:
    goto v_33128;
v_33129:
    v_33189 = cons(v_33190, v_33189);
    env = stack[-5];
    stack[-2] = v_33189;
    goto v_33114;
v_33116:
v_33114:
    v_33189 = stack[0];
    v_33189 = add1(v_33189);
    env = stack[-5];
    stack[0] = v_33189;
    goto v_33096;
v_33095:
    goto v_33057;
v_33059:
    v_33189 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_33189;
v_33140:
    goto v_33152;
v_33148:
    v_33189 = stack[-3];
    v_33190 = sub1(v_33189);
    env = stack[-5];
    goto v_33149;
v_33150:
    v_33189 = stack[0];
    goto v_33151;
v_33152:
    goto v_33148;
v_33149:
    goto v_33150;
v_33151:
    v_33189 = difference2(v_33190, v_33189);
    env = stack[-5];
    v_33189 = Lminusp(nil, v_33189);
    env = stack[-5];
    if (v_33189 == nil) goto v_33145;
    goto v_33139;
v_33145:
v_33162:
    goto v_33172;
v_33168:
    v_33189 = stack[-1];
    fn = elt(env, 1); // random
    v_33190 = (*qfn1(fn))(fn, v_33189);
    env = stack[-5];
    v_33191 = v_33190;
    goto v_33169;
v_33170:
    v_33189 = stack[-2];
    goto v_33171;
v_33172:
    goto v_33168;
v_33169:
    goto v_33170;
v_33171:
    v_33189 = Lmember(nil, v_33190, v_33189);
    if (v_33189 == nil) goto v_33166;
    else goto v_33167;
v_33166:
    goto v_33161;
v_33167:
    goto v_33162;
v_33161:
    goto v_33183;
v_33179:
    v_33190 = v_33191;
    goto v_33180;
v_33181:
    v_33189 = stack[-2];
    goto v_33182;
v_33183:
    goto v_33179;
v_33180:
    goto v_33181;
v_33182:
    v_33189 = cons(v_33190, v_33189);
    env = stack[-5];
    stack[-2] = v_33189;
    v_33189 = stack[0];
    v_33189 = add1(v_33189);
    env = stack[-5];
    stack[0] = v_33189;
    goto v_33140;
v_33139:
    goto v_33057;
v_33057:
    v_33189 = stack[-2];
    goto v_32989;
    v_33189 = nil;
v_32989:
    return onevalue(v_33189);
}



// Code for partitindexvar

static LispObject CC_partitindexvar(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33940, v_33941, v_33942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_32985;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    v_33940 = stack[-7];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33007;
    else goto v_33008;
v_33007:
    v_33940 = nil;
    goto v_33001;
v_33008:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    fn = elt(env, 5); // revalind
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    v_33941 = v_33940;
    v_33940 = v_33941;
    if (!consp(v_33940)) goto v_33020;
    else goto v_33021;
v_33020:
    v_33940 = v_33941;
    if (is_number(v_33940)) goto v_33025;
    else goto v_33026;
v_33025:
    v_33940 = v_33941;
    v_33940 = Lminusp(nil, v_33940);
    env = stack[-9];
    if (v_33940 == nil) goto v_33031;
    goto v_33039;
v_33035:
    stack[0] = elt(env, 1); // minus
    goto v_33036;
v_33037:
    v_33940 = v_33941;
    v_33940 = Labsval(nil, v_33940);
    env = stack[-9];
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33038;
v_33039:
    goto v_33035;
v_33036:
    goto v_33037;
v_33038:
    v_33940 = list2(stack[0], v_33940);
    env = stack[-9];
    goto v_33029;
v_33031:
    v_33940 = v_33941;
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33029;
    v_33940 = nil;
v_33029:
    goto v_33024;
v_33026:
    v_33940 = v_33941;
    goto v_33024;
    v_33940 = nil;
v_33024:
    goto v_33019;
v_33021:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    if (is_number(v_33940)) goto v_33051;
    else goto v_33052;
v_33051:
    goto v_33061;
v_33057:
    stack[0] = elt(env, 1); // minus
    goto v_33058;
v_33059:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33060;
v_33061:
    goto v_33057;
v_33058:
    goto v_33059;
v_33060:
    v_33940 = list2(stack[0], v_33940);
    env = stack[-9];
    goto v_33019;
v_33052:
    v_33940 = v_33941;
    goto v_33019;
    v_33940 = nil;
v_33019:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    stack[-2] = v_33940;
    stack[-3] = v_33940;
v_33002:
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33074;
    else goto v_33075;
v_33074:
    v_33940 = stack[-3];
    goto v_33001;
v_33075:
    goto v_33083;
v_33079:
    stack[-1] = stack[-2];
    goto v_33080;
v_33081:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    fn = elt(env, 5); // revalind
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    v_33941 = v_33940;
    v_33940 = v_33941;
    if (!consp(v_33940)) goto v_33094;
    else goto v_33095;
v_33094:
    v_33940 = v_33941;
    if (is_number(v_33940)) goto v_33099;
    else goto v_33100;
v_33099:
    v_33940 = v_33941;
    v_33940 = Lminusp(nil, v_33940);
    env = stack[-9];
    if (v_33940 == nil) goto v_33105;
    goto v_33113;
v_33109:
    stack[0] = elt(env, 1); // minus
    goto v_33110;
v_33111:
    v_33940 = v_33941;
    v_33940 = Labsval(nil, v_33940);
    env = stack[-9];
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33112;
v_33113:
    goto v_33109;
v_33110:
    goto v_33111;
v_33112:
    v_33940 = list2(stack[0], v_33940);
    env = stack[-9];
    goto v_33103;
v_33105:
    v_33940 = v_33941;
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33103;
    v_33940 = nil;
v_33103:
    goto v_33098;
v_33100:
    v_33940 = v_33941;
    goto v_33098;
    v_33940 = nil;
v_33098:
    goto v_33093;
v_33095:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    if (is_number(v_33940)) goto v_33125;
    else goto v_33126;
v_33125:
    goto v_33135;
v_33131:
    stack[0] = elt(env, 1); // minus
    goto v_33132;
v_33133:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    fn = elt(env, 6); // !*num2id
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33134;
v_33135:
    goto v_33131;
v_33132:
    goto v_33133;
v_33134:
    v_33940 = list2(stack[0], v_33940);
    env = stack[-9];
    goto v_33093;
v_33126:
    v_33940 = v_33941;
    goto v_33093;
    v_33940 = nil;
v_33093:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    goto v_33082;
v_33083:
    goto v_33079;
v_33080:
    goto v_33081;
v_33082:
    v_33940 = Lrplacd(nil, stack[-1], v_33940);
    env = stack[-9];
    v_33940 = stack[-2];
    v_33940 = qcdr(v_33940);
    stack[-2] = v_33940;
    goto v_33002;
v_33001:
    stack[0] = v_33940;
    v_33940 = stack[-7];
    fn = elt(env, 7); // deg!*form
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    stack[-3] = v_33940;
    v_33940 = qvalue(elt(env, 2)); // metricu!*
    if (v_33940 == nil) goto v_33150;
    else goto v_33151;
v_33150:
    goto v_32996;
v_33151:
    v_33940 = stack[0];
    stack[-2] = v_33940;
    goto v_33163;
v_33159:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33160;
v_33161:
    v_33940 = elt(env, 3); // covariant
    goto v_33162;
v_33163:
    goto v_33159;
v_33160:
    goto v_33161;
v_33162:
    v_33940 = Lflagp(nil, v_33941, v_33940);
    env = stack[-9];
    if (v_33940 == nil) goto v_33156;
    else goto v_33157;
v_33156:
v_33169:
    v_33940 = stack[-2];
    if (v_33940 == nil) goto v_33172;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    if (!consp(v_33940)) goto v_33179;
    else goto v_33180;
v_33179:
    v_33940 = lisp_true;
    goto v_33178;
v_33180:
    goto v_33190;
v_33186:
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    v_33940 = qcdr(v_33940);
    v_33941 = qcar(v_33940);
    goto v_33187;
v_33188:
    v_33940 = qvalue(elt(env, 2)); // metricu!*
    goto v_33189;
v_33190:
    goto v_33186;
v_33187:
    goto v_33188;
v_33189:
    v_33940 = Latsoc(nil, v_33941, v_33940);
    v_33940 = (v_33940 == nil ? lisp_true : nil);
    goto v_33178;
    v_33940 = nil;
v_33178:
    if (v_33940 == nil) goto v_33172;
    goto v_33173;
v_33172:
    goto v_33168;
v_33173:
    goto v_33204;
v_33200:
    v_33940 = stack[-2];
    v_33941 = qcar(v_33940);
    goto v_33201;
v_33202:
    v_33940 = stack[-6];
    goto v_33203;
v_33204:
    goto v_33200;
v_33201:
    goto v_33202;
v_33203:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    stack[-6] = v_33940;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    if (!consp(v_33940)) goto v_33211;
    goto v_33219;
v_33215:
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    v_33940 = qcdr(v_33940);
    v_33941 = qcar(v_33940);
    goto v_33216;
v_33217:
    v_33940 = stack[-8];
    goto v_33218;
v_33219:
    goto v_33215;
v_33216:
    goto v_33217;
v_33218:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    stack[-8] = v_33940;
    goto v_33209;
v_33211:
v_33209:
    v_33940 = stack[-2];
    v_33940 = qcdr(v_33940);
    stack[-2] = v_33940;
    goto v_33169;
v_33168:
    v_33940 = stack[-2];
    if (v_33940 == nil) goto v_33230;
    v_33940 = nil;
    stack[-5] = v_33940;
    v_33940 = stack[-6];
    v_33940 = Lreverse(nil, v_33940);
    env = stack[-9];
    stack[-6] = v_33940;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    fn = elt(env, 8); // getlower
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    stack[-4] = v_33940;
v_33238:
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33246;
    else goto v_33247;
v_33246:
    goto v_33237;
v_33247:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    stack[-3] = v_33940;
    goto v_33258;
v_33254:
    goto v_33264;
v_33260:
    goto v_33271;
v_33267:
    v_33940 = stack[-7];
    stack[-1] = qcar(v_33940);
    goto v_33268;
v_33269:
    goto v_33279;
v_33275:
    stack[0] = stack[-6];
    goto v_33276;
v_33277:
    goto v_33286;
v_33282:
    v_33940 = stack[-3];
    v_33941 = qcar(v_33940);
    goto v_33283;
v_33284:
    v_33940 = stack[-2];
    v_33940 = qcdr(v_33940);
    goto v_33285;
v_33286:
    goto v_33282;
v_33283:
    goto v_33284;
v_33285:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33278;
v_33279:
    goto v_33275;
v_33276:
    goto v_33277;
v_33278:
    v_33940 = Lappend(nil, stack[0], v_33940);
    env = stack[-9];
    goto v_33270;
v_33271:
    goto v_33267;
v_33268:
    goto v_33269;
v_33270:
    v_33940 = cons(stack[-1], v_33940);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_33940);
    env = stack[-9];
    goto v_33261;
v_33262:
    v_33940 = stack[-3];
    v_33940 = qcdr(v_33940);
    fn = elt(env, 9); // simp
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33263;
v_33264:
    goto v_33260;
v_33261:
    goto v_33262;
v_33263:
    fn = elt(env, 10); // multpfsq
    v_33941 = (*qfn2(fn))(fn, stack[0], v_33940);
    env = stack[-9];
    goto v_33255;
v_33256:
    v_33940 = stack[-5];
    goto v_33257;
v_33258:
    goto v_33254;
v_33255:
    goto v_33256;
v_33257:
    fn = elt(env, 11); // addpf
    v_33940 = (*qfn2(fn))(fn, v_33941, v_33940);
    env = stack[-9];
    stack[-5] = v_33940;
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    goto v_33238;
v_33237:
    v_33940 = stack[-5];
    goto v_32995;
v_33230:
    goto v_33155;
v_33157:
v_33302:
    v_33940 = stack[-2];
    if (v_33940 == nil) goto v_33305;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    if (!consp(v_33940)) goto v_33313;
    v_33940 = lisp_true;
    goto v_33311;
v_33313:
    goto v_33323;
v_33319:
    v_33940 = stack[-2];
    v_33941 = qcar(v_33940);
    goto v_33320;
v_33321:
    v_33940 = qvalue(elt(env, 2)); // metricu!*
    goto v_33322;
v_33323:
    goto v_33319;
v_33320:
    goto v_33321;
v_33322:
    v_33940 = Latsoc(nil, v_33941, v_33940);
    v_33940 = (v_33940 == nil ? lisp_true : nil);
    goto v_33311;
    v_33940 = nil;
v_33311:
    if (v_33940 == nil) goto v_33305;
    goto v_33306;
v_33305:
    goto v_33301;
v_33306:
    goto v_33335;
v_33331:
    v_33940 = stack[-2];
    v_33941 = qcar(v_33940);
    goto v_33332;
v_33333:
    v_33940 = stack[-6];
    goto v_33334;
v_33335:
    goto v_33331;
v_33332:
    goto v_33333;
v_33334:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    stack[-6] = v_33940;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    if (!consp(v_33940)) goto v_33341;
    else goto v_33342;
v_33341:
    goto v_33350;
v_33346:
    v_33940 = stack[-2];
    v_33941 = qcar(v_33940);
    goto v_33347;
v_33348:
    v_33940 = stack[-8];
    goto v_33349;
v_33350:
    goto v_33346;
v_33347:
    goto v_33348;
v_33349:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    stack[-8] = v_33940;
    goto v_33340;
v_33342:
v_33340:
    v_33940 = stack[-2];
    v_33940 = qcdr(v_33940);
    stack[-2] = v_33940;
    goto v_33302;
v_33301:
    v_33940 = stack[-2];
    if (v_33940 == nil) goto v_33359;
    v_33940 = nil;
    stack[-5] = v_33940;
    v_33940 = stack[-6];
    v_33940 = Lreverse(nil, v_33940);
    env = stack[-9];
    stack[-6] = v_33940;
    v_33940 = stack[-2];
    v_33940 = qcar(v_33940);
    fn = elt(env, 12); // getupper
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    stack[-4] = v_33940;
v_33367:
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33373;
    else goto v_33374;
v_33373:
    goto v_33366;
v_33374:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    stack[-3] = v_33940;
    goto v_33385;
v_33381:
    goto v_33391;
v_33387:
    goto v_33398;
v_33394:
    v_33940 = stack[-7];
    stack[-1] = qcar(v_33940);
    goto v_33395;
v_33396:
    goto v_33406;
v_33402:
    stack[0] = stack[-6];
    goto v_33403;
v_33404:
    goto v_33413;
v_33409:
    goto v_33419;
v_33415:
    v_33941 = elt(env, 1); // minus
    goto v_33416;
v_33417:
    v_33940 = stack[-3];
    v_33940 = qcar(v_33940);
    goto v_33418;
v_33419:
    goto v_33415;
v_33416:
    goto v_33417;
v_33418:
    v_33941 = list2(v_33941, v_33940);
    env = stack[-9];
    goto v_33410;
v_33411:
    v_33940 = stack[-2];
    v_33940 = qcdr(v_33940);
    goto v_33412;
v_33413:
    goto v_33409;
v_33410:
    goto v_33411;
v_33412:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33405;
v_33406:
    goto v_33402;
v_33403:
    goto v_33404;
v_33405:
    v_33940 = Lappend(nil, stack[0], v_33940);
    env = stack[-9];
    goto v_33397;
v_33398:
    goto v_33394;
v_33395:
    goto v_33396;
v_33397:
    v_33940 = cons(stack[-1], v_33940);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_33940);
    env = stack[-9];
    goto v_33388;
v_33389:
    v_33940 = stack[-3];
    v_33940 = qcdr(v_33940);
    fn = elt(env, 9); // simp
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33390;
v_33391:
    goto v_33387;
v_33388:
    goto v_33389;
v_33390:
    fn = elt(env, 10); // multpfsq
    v_33941 = (*qfn2(fn))(fn, stack[0], v_33940);
    env = stack[-9];
    goto v_33382;
v_33383:
    v_33940 = stack[-5];
    goto v_33384;
v_33385:
    goto v_33381;
v_33382:
    goto v_33383;
v_33384:
    fn = elt(env, 11); // addpf
    v_33940 = (*qfn2(fn))(fn, v_33941, v_33940);
    env = stack[-9];
    stack[-5] = v_33940;
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    goto v_33367;
v_33366:
    v_33940 = stack[-5];
    goto v_32995;
v_33359:
    goto v_33155;
v_33155:
v_32996:
    v_33940 = stack[0];
    fn = elt(env, 13); // coposp
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    if (v_33940 == nil) goto v_33438;
    else goto v_33439;
v_33438:
    v_33940 = lisp_true;
    goto v_33437;
v_33439:
    goto v_33450;
v_33446:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33447;
v_33448:
    v_33940 = elt(env, 4); // indxsymmetries
    goto v_33449;
v_33450:
    goto v_33446;
v_33447:
    goto v_33448;
v_33449:
    v_33940 = get(v_33941, v_33940);
    env = stack[-9];
    v_33940 = (v_33940 == nil ? lisp_true : nil);
    goto v_33437;
    v_33940 = nil;
v_33437:
    if (v_33940 == nil) goto v_33435;
    v_33940 = stack[-3];
    if (v_33940 == nil) goto v_33458;
    goto v_33466;
v_33462:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33463;
v_33464:
    v_33940 = stack[0];
    goto v_33465;
v_33466:
    goto v_33462;
v_33463:
    goto v_33464;
v_33465:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    {
        fn = elt(env, 14); // mkupf
        return (*qfn1(fn))(fn, v_33940);
    }
v_33458:
    goto v_33478;
v_33474:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33475;
v_33476:
    goto v_33485;
v_33481:
    goto v_33491;
v_33487:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33488;
v_33489:
    v_33940 = stack[0];
    goto v_33490;
v_33491:
    goto v_33487;
v_33488:
    goto v_33489;
v_33490:
    v_33941 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33482;
v_33483:
    v_33940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33484;
v_33485:
    goto v_33481;
v_33482:
    goto v_33483;
v_33484:
    fn = elt(env, 15); // mksq
    v_33940 = (*qfn2(fn))(fn, v_33941, v_33940);
    env = stack[-9];
    goto v_33477;
v_33478:
    goto v_33474;
v_33475:
    goto v_33476;
v_33477:
    v_33940 = cons(stack[-1], v_33940);
    return ncons(v_33940);
    v_33940 = nil;
    goto v_32995;
v_33435:
    v_33940 = stack[0];
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33505;
    else goto v_33506;
v_33505:
    v_33940 = nil;
    goto v_33500;
v_33506:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33941 = v_33940;
    v_33940 = v_33941;
    if (!consp(v_33940)) goto v_33515;
    else goto v_33516;
v_33515:
    v_33940 = v_33941;
    goto v_33514;
v_33516:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    goto v_33514;
    v_33940 = nil;
v_33514:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    stack[-1] = v_33940;
    stack[-2] = v_33940;
v_33501:
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33528;
    else goto v_33529;
v_33528:
    v_33940 = stack[-2];
    goto v_33500;
v_33529:
    goto v_33537;
v_33533:
    stack[0] = stack[-1];
    goto v_33534;
v_33535:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33941 = v_33940;
    v_33940 = v_33941;
    if (!consp(v_33940)) goto v_33545;
    else goto v_33546;
v_33545:
    v_33940 = v_33941;
    goto v_33544;
v_33546:
    v_33940 = v_33941;
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    goto v_33544;
    v_33940 = nil;
v_33544:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    goto v_33536;
v_33537:
    goto v_33533;
v_33534:
    goto v_33535;
v_33536:
    v_33940 = Lrplacd(nil, stack[0], v_33940);
    env = stack[-9];
    v_33940 = stack[-1];
    v_33940 = qcdr(v_33940);
    stack[-1] = v_33940;
    goto v_33501;
v_33500:
    stack[0] = v_33940;
    goto v_33562;
v_33558:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33559;
v_33560:
    v_33940 = stack[0];
    goto v_33561;
v_33562:
    goto v_33558;
v_33559:
    goto v_33560;
v_33561:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    fn = elt(env, 16); // indexsymmetrize
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    stack[0] = v_33940;
    v_33940 = stack[0];
    if (v_33940 == nil) goto v_33568;
    else goto v_33569;
v_33568:
    v_33940 = nil;
    goto v_32995;
v_33569:
    goto v_33580;
v_33576:
    v_33940 = stack[0];
    v_33941 = qcar(v_33940);
    goto v_33577;
v_33578:
    v_33940 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33579;
v_33580:
    goto v_33576;
v_33577:
    goto v_33578;
v_33579:
    if (v_33941 == v_33940) goto v_33574;
    else goto v_33575;
v_33574:
    v_33940 = lisp_true;
    stack[-5] = v_33940;
    goto v_33573;
v_33575:
v_33573:
    v_33940 = stack[0];
    v_33940 = qcdr(v_33940);
    v_33940 = qcdr(v_33940);
    stack[0] = v_33940;
    goto v_33597;
v_33593:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33594;
v_33595:
    v_33940 = elt(env, 3); // covariant
    goto v_33596;
v_33597:
    goto v_33593;
v_33594:
    goto v_33595;
v_33596:
    v_33940 = Lflagp(nil, v_33941, v_33940);
    env = stack[-9];
    if (v_33940 == nil) goto v_33591;
    v_33940 = stack[0];
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33610;
    else goto v_33611;
v_33610:
    v_33940 = nil;
    goto v_33605;
v_33611:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33942 = v_33940;
    goto v_33626;
v_33622:
    v_33941 = v_33942;
    goto v_33623;
v_33624:
    v_33940 = stack[-8];
    goto v_33625;
v_33626:
    goto v_33622;
v_33623:
    goto v_33624;
v_33625:
    v_33940 = Lmemq(nil, v_33941, v_33940);
    if (v_33940 == nil) goto v_33621;
    v_33940 = v_33942;
    goto v_33619;
v_33621:
    goto v_33638;
v_33634:
    v_33940 = elt(env, 1); // minus
    goto v_33635;
v_33636:
    v_33941 = v_33942;
    goto v_33637;
v_33638:
    goto v_33634;
v_33635:
    goto v_33636;
v_33637:
    v_33940 = list2(v_33940, v_33941);
    env = stack[-9];
    goto v_33619;
    v_33940 = nil;
v_33619:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    stack[-1] = v_33940;
    stack[-2] = v_33940;
v_33606:
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33645;
    else goto v_33646;
v_33645:
    v_33940 = stack[-2];
    goto v_33605;
v_33646:
    goto v_33654;
v_33650:
    stack[0] = stack[-1];
    goto v_33651;
v_33652:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33942 = v_33940;
    goto v_33668;
v_33664:
    v_33941 = v_33942;
    goto v_33665;
v_33666:
    v_33940 = stack[-8];
    goto v_33667;
v_33668:
    goto v_33664;
v_33665:
    goto v_33666;
v_33667:
    v_33940 = Lmemq(nil, v_33941, v_33940);
    if (v_33940 == nil) goto v_33663;
    v_33940 = v_33942;
    goto v_33661;
v_33663:
    goto v_33680;
v_33676:
    v_33940 = elt(env, 1); // minus
    goto v_33677;
v_33678:
    v_33941 = v_33942;
    goto v_33679;
v_33680:
    goto v_33676;
v_33677:
    goto v_33678;
v_33679:
    v_33940 = list2(v_33940, v_33941);
    env = stack[-9];
    goto v_33661;
    v_33940 = nil;
v_33661:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    goto v_33653;
v_33654:
    goto v_33650;
v_33651:
    goto v_33652;
v_33653:
    v_33940 = Lrplacd(nil, stack[0], v_33940);
    env = stack[-9];
    v_33940 = stack[-1];
    v_33940 = qcdr(v_33940);
    stack[-1] = v_33940;
    goto v_33606;
v_33605:
    stack[0] = v_33940;
    goto v_33589;
v_33591:
    v_33940 = qvalue(elt(env, 2)); // metricu!*
    if (v_33940 == nil) goto v_33689;
    else goto v_33690;
v_33689:
    v_33940 = stack[-7];
    v_33940 = qcdr(v_33940);
    v_33940 = qcar(v_33940);
    v_33940 = (consp(v_33940) ? nil : lisp_true);
    v_33940 = (v_33940 == nil ? lisp_true : nil);
    goto v_33688;
v_33690:
    v_33940 = nil;
    goto v_33688;
    v_33940 = nil;
v_33688:
    if (v_33940 == nil) goto v_33686;
    v_33940 = stack[0];
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33709;
    else goto v_33710;
v_33709:
    v_33940 = nil;
    goto v_33704;
v_33710:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    goto v_33722;
v_33718:
    v_33941 = elt(env, 1); // minus
    goto v_33719;
v_33720:
    goto v_33721;
v_33722:
    goto v_33718;
v_33719:
    goto v_33720;
v_33721:
    v_33940 = list2(v_33941, v_33940);
    env = stack[-9];
    v_33940 = ncons(v_33940);
    env = stack[-9];
    stack[-1] = v_33940;
    stack[-2] = v_33940;
v_33705:
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33729;
    else goto v_33730;
v_33729:
    v_33940 = stack[-2];
    goto v_33704;
v_33730:
    goto v_33738;
v_33734:
    stack[0] = stack[-1];
    goto v_33735;
v_33736:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    goto v_33749;
v_33745:
    v_33941 = elt(env, 1); // minus
    goto v_33746;
v_33747:
    goto v_33748;
v_33749:
    goto v_33745;
v_33746:
    goto v_33747;
v_33748:
    v_33940 = list2(v_33941, v_33940);
    env = stack[-9];
    v_33940 = ncons(v_33940);
    env = stack[-9];
    goto v_33737;
v_33738:
    goto v_33734;
v_33735:
    goto v_33736;
v_33737:
    v_33940 = Lrplacd(nil, stack[0], v_33940);
    env = stack[-9];
    v_33940 = stack[-1];
    v_33940 = qcdr(v_33940);
    stack[-1] = v_33940;
    goto v_33705;
v_33704:
    stack[0] = v_33940;
    goto v_33589;
v_33686:
    v_33940 = stack[0];
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33765;
    else goto v_33766;
v_33765:
    v_33940 = nil;
    goto v_33760;
v_33766:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33942 = v_33940;
    goto v_33781;
v_33777:
    v_33941 = v_33942;
    goto v_33778;
v_33779:
    v_33940 = stack[-8];
    goto v_33780;
v_33781:
    goto v_33777;
v_33778:
    goto v_33779;
v_33780:
    v_33940 = Lmemq(nil, v_33941, v_33940);
    if (v_33940 == nil) goto v_33776;
    goto v_33790;
v_33786:
    v_33940 = elt(env, 1); // minus
    goto v_33787;
v_33788:
    v_33941 = v_33942;
    goto v_33789;
v_33790:
    goto v_33786;
v_33787:
    goto v_33788;
v_33789:
    v_33940 = list2(v_33940, v_33941);
    env = stack[-9];
    goto v_33774;
v_33776:
    v_33940 = v_33942;
    goto v_33774;
    v_33940 = nil;
v_33774:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    stack[-1] = v_33940;
    stack[-2] = v_33940;
v_33761:
    v_33940 = stack[-4];
    v_33940 = qcdr(v_33940);
    stack[-4] = v_33940;
    v_33940 = stack[-4];
    if (v_33940 == nil) goto v_33800;
    else goto v_33801;
v_33800:
    v_33940 = stack[-2];
    goto v_33760;
v_33801:
    goto v_33809;
v_33805:
    stack[0] = stack[-1];
    goto v_33806;
v_33807:
    v_33940 = stack[-4];
    v_33940 = qcar(v_33940);
    v_33942 = v_33940;
    goto v_33823;
v_33819:
    v_33941 = v_33942;
    goto v_33820;
v_33821:
    v_33940 = stack[-8];
    goto v_33822;
v_33823:
    goto v_33819;
v_33820:
    goto v_33821;
v_33822:
    v_33940 = Lmemq(nil, v_33941, v_33940);
    if (v_33940 == nil) goto v_33818;
    goto v_33832;
v_33828:
    v_33940 = elt(env, 1); // minus
    goto v_33829;
v_33830:
    v_33941 = v_33942;
    goto v_33831;
v_33832:
    goto v_33828;
v_33829:
    goto v_33830;
v_33831:
    v_33940 = list2(v_33940, v_33941);
    env = stack[-9];
    goto v_33816;
v_33818:
    v_33940 = v_33942;
    goto v_33816;
    v_33940 = nil;
v_33816:
    v_33940 = ncons(v_33940);
    env = stack[-9];
    goto v_33808;
v_33809:
    goto v_33805;
v_33806:
    goto v_33807;
v_33808:
    v_33940 = Lrplacd(nil, stack[0], v_33940);
    env = stack[-9];
    v_33940 = stack[-1];
    v_33940 = qcdr(v_33940);
    stack[-1] = v_33940;
    goto v_33761;
v_33760:
    stack[0] = v_33940;
    goto v_33589;
v_33589:
    v_33940 = stack[-3];
    if (v_33940 == nil) goto v_33843;
    v_33940 = stack[-5];
    if (v_33940 == nil) goto v_33848;
    goto v_33855;
v_33851:
    goto v_33862;
v_33858:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33859;
v_33860:
    v_33940 = stack[0];
    goto v_33861;
v_33862:
    goto v_33858;
v_33859:
    goto v_33860;
v_33861:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    fn = elt(env, 14); // mkupf
    stack[0] = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33852;
v_33853:
    goto v_33871;
v_33867:
    v_33941 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33868;
v_33869:
    v_33940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33870;
v_33871:
    goto v_33867;
v_33868:
    goto v_33869;
v_33870:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33854;
v_33855:
    goto v_33851;
v_33852:
    goto v_33853;
v_33854:
    {
        LispObject v_33952 = stack[0];
        fn = elt(env, 10); // multpfsq
        return (*qfn2(fn))(fn, v_33952, v_33940);
    }
v_33848:
    goto v_33882;
v_33878:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33879;
v_33880:
    v_33940 = stack[0];
    goto v_33881;
v_33882:
    goto v_33878;
v_33879:
    goto v_33880;
v_33881:
    v_33940 = cons(v_33941, v_33940);
    env = stack[-9];
    {
        fn = elt(env, 14); // mkupf
        return (*qfn1(fn))(fn, v_33940);
    }
    v_33940 = nil;
    goto v_33841;
v_33843:
    v_33940 = stack[-5];
    if (v_33940 == nil) goto v_33887;
    goto v_33895;
v_33891:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33892;
v_33893:
    goto v_33903;
v_33899:
    goto v_33909;
v_33905:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33906;
v_33907:
    v_33940 = stack[0];
    goto v_33908;
v_33909:
    goto v_33905;
v_33906:
    goto v_33907;
v_33908:
    v_33941 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33900;
v_33901:
    v_33940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33902;
v_33903:
    goto v_33899;
v_33900:
    goto v_33901;
v_33902:
    fn = elt(env, 15); // mksq
    v_33940 = (*qfn2(fn))(fn, v_33941, v_33940);
    env = stack[-9];
    fn = elt(env, 17); // negsq
    v_33940 = (*qfn1(fn))(fn, v_33940);
    env = stack[-9];
    goto v_33894;
v_33895:
    goto v_33891;
v_33892:
    goto v_33893;
v_33894:
    v_33940 = cons(stack[-1], v_33940);
    return ncons(v_33940);
v_33887:
    goto v_33922;
v_33918:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33919;
v_33920:
    goto v_33929;
v_33925:
    goto v_33935;
v_33931:
    v_33940 = stack[-7];
    v_33941 = qcar(v_33940);
    goto v_33932;
v_33933:
    v_33940 = stack[0];
    goto v_33934;
v_33935:
    goto v_33931;
v_33932:
    goto v_33933;
v_33934:
    v_33941 = cons(v_33941, v_33940);
    env = stack[-9];
    goto v_33926;
v_33927:
    v_33940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33928;
v_33929:
    goto v_33925;
v_33926:
    goto v_33927;
v_33928:
    fn = elt(env, 15); // mksq
    v_33940 = (*qfn2(fn))(fn, v_33941, v_33940);
    env = stack[-9];
    goto v_33921;
v_33922:
    goto v_33918;
v_33919:
    goto v_33920;
v_33921:
    v_33940 = cons(stack[-1], v_33940);
    return ncons(v_33940);
    v_33940 = nil;
v_33841:
v_32995:
    return onevalue(v_33940);
}



// Code for physop!*sq

static LispObject CC_physopHsq(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33003;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33003 = v_32985;
// end of prologue
    v_33003 = qcar(v_33003);
    fn = elt(env, 2); // !*q2a
    v_33003 = (*qfn1(fn))(fn, v_33003);
    env = stack[0];
    fn = elt(env, 3); // !*collectphysops
    v_33003 = (*qfn1(fn))(fn, v_33003);
    env = stack[0];
    if (v_33003 == nil) goto v_32996;
    else goto v_32997;
v_32996:
    v_33003 = nil;
    goto v_32995;
v_32997:
    v_33003 = elt(env, 1); // physop
    goto v_32995;
    v_33003 = nil;
v_32995:
    return onevalue(v_33003);
}



// Code for mk!-strand!-vertex

static LispObject CC_mkKstrandKvertex(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33050, v_33051, v_33052;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_33050 = v_32986;
    stack[-2] = v_32985;
// end of prologue
    goto v_33000;
v_32994:
    v_33052 = stack[-2];
    goto v_32995;
v_32996:
    v_33051 = v_33050;
    goto v_32997;
v_32998:
    v_33050 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32999;
v_33000:
    goto v_32994;
v_32995:
    goto v_32996;
v_32997:
    goto v_32998;
v_32999:
    fn = elt(env, 1); // incident
    v_33050 = (*qfnn(fn))(fn, 3, v_33052, v_33051, v_33050);
    env = stack[-4];
    v_33051 = v_33050;
    v_33050 = v_33051;
    v_33050 = qcar(v_33050);
    stack[-3] = v_33050;
    goto v_33013;
v_33007:
    stack[-1] = stack[-2];
    goto v_33008;
v_33009:
    v_33050 = v_33051;
    stack[0] = qcdr(v_33050);
    goto v_33010;
v_33011:
    v_33050 = stack[-3];
    v_33050 = qcar(v_33050);
    v_33050 = qcdr(v_33050);
    v_33050 = add1(v_33050);
    env = stack[-4];
    goto v_33012;
v_33013:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    goto v_33011;
v_33012:
    fn = elt(env, 1); // incident
    v_33050 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33050);
    env = stack[-4];
    v_33051 = v_33050;
    v_33050 = v_33051;
    if (v_33050 == nil) goto v_33023;
    else goto v_33024;
v_33023:
    goto v_33032;
v_33028:
    v_33051 = stack[-2];
    goto v_33029;
v_33030:
    v_33050 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33031;
v_33032:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    v_33050 = cons(v_33051, v_33050);
    env = stack[-4];
    v_33050 = ncons(v_33050);
    env = stack[-4];
    goto v_33022;
v_33024:
    v_33050 = v_33051;
    v_33050 = qcar(v_33050);
    goto v_33022;
    v_33050 = nil;
v_33022:
    goto v_33046;
v_33040:
    v_33052 = stack[-2];
    goto v_33041;
v_33042:
    v_33051 = stack[-3];
    goto v_33043;
v_33044:
    goto v_33045;
v_33046:
    goto v_33040;
v_33041:
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    {
        fn = elt(env, 2); // mk!-strand!-vertex2
        return (*qfnn(fn))(fn, 3, v_33052, v_33051, v_33050);
    }
    return onevalue(v_33050);
}



// Code for general!-minus!-mod!-p

static LispObject CC_generalKminusKmodKp(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33040, v_33041;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_32985;
// end of prologue
    stack[-2] = nil;
v_32990:
    v_33040 = stack[-1];
    if (v_33040 == nil) goto v_32993;
    else goto v_32994;
v_32993:
    v_33040 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_33040);
    }
v_32994:
    v_33040 = stack[-1];
    if (!consp(v_33040)) goto v_33002;
    else goto v_33003;
v_33002:
    v_33040 = lisp_true;
    goto v_33001;
v_33003:
    v_33040 = stack[-1];
    v_33040 = qcar(v_33040);
    v_33040 = (consp(v_33040) ? nil : lisp_true);
    goto v_33001;
    v_33040 = nil;
v_33001:
    if (v_33040 == nil) goto v_32999;
    goto v_33016;
v_33012:
    stack[0] = stack[-2];
    goto v_33013;
v_33014:
    v_33040 = stack[-1];
    fn = elt(env, 2); // general!-modular!-minus
    v_33040 = (*qfn1(fn))(fn, v_33040);
    env = stack[-3];
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    {
        LispObject v_33045 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_33045, v_33040);
    }
v_32999:
    goto v_33029;
v_33023:
    v_33040 = stack[-1];
    v_33040 = qcar(v_33040);
    stack[0] = qcar(v_33040);
    goto v_33024;
v_33025:
    v_33040 = stack[-1];
    v_33040 = qcar(v_33040);
    v_33040 = qcdr(v_33040);
    v_33041 = CC_generalKminusKmodKp(elt(env, 0), v_33040);
    env = stack[-3];
    goto v_33026;
v_33027:
    v_33040 = stack[-2];
    goto v_33028;
v_33029:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    goto v_33027;
v_33028:
    v_33040 = acons(stack[0], v_33041, v_33040);
    env = stack[-3];
    stack[-2] = v_33040;
    v_33040 = stack[-1];
    v_33040 = qcdr(v_33040);
    stack[-1] = v_33040;
    goto v_32990;
    v_33040 = nil;
    return onevalue(v_33040);
}



// Code for allbkern

static LispObject CC_allbkern(LispObject env,
                         LispObject v_32985)
{
    env = qenv(env);
    LispObject v_33031, v_33032;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32985);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32985;
// end of prologue
    stack[-1] = nil;
v_32991:
    v_33031 = stack[0];
    if (v_33031 == nil) goto v_32996;
    else goto v_32997;
v_32996:
    goto v_32992;
v_32997:
    goto v_33004;
v_33000:
    v_33031 = stack[0];
    v_33031 = qcar(v_33031);
    v_33031 = qcar(v_33031);
    fn = elt(env, 1); // kernels
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-2];
    fn = elt(env, 2); // basic!-kern
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-2];
    goto v_33001;
v_33002:
    v_33031 = stack[-1];
    goto v_33003;
v_33004:
    goto v_33000;
v_33001:
    goto v_33002;
v_33003:
    v_33031 = cons(v_33032, v_33031);
    env = stack[-2];
    stack[-1] = v_33031;
    v_33031 = stack[0];
    v_33031 = qcdr(v_33031);
    stack[0] = v_33031;
    goto v_32991;
v_32992:
    v_33031 = nil;
    v_33032 = v_33031;
v_32993:
    v_33031 = stack[-1];
    if (v_33031 == nil) goto v_33016;
    else goto v_33017;
v_33016:
    v_33031 = v_33032;
    goto v_32990;
v_33017:
    goto v_33025;
v_33021:
    v_33031 = stack[-1];
    v_33031 = qcar(v_33031);
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    goto v_33021;
v_33022:
    goto v_33023;
v_33024:
    fn = elt(env, 3); // union
    v_33031 = (*qfn2(fn))(fn, v_33031, v_33032);
    env = stack[-2];
    v_33032 = v_33031;
    v_33031 = stack[-1];
    v_33031 = qcdr(v_33031);
    stack[-1] = v_33031;
    goto v_32993;
v_32990:
    return onevalue(v_33031);
}



// Code for coeffs!-to!-form

static LispObject CC_coeffsKtoKform(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33009, v_33010, v_33011;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_33010 = v_32986;
    v_33011 = v_32985;
// end of prologue
    v_33009 = v_33011;
    if (v_33009 == nil) goto v_32990;
    else goto v_32991;
v_32990:
    v_33009 = nil;
    goto v_32989;
v_32991:
    goto v_33003;
v_32997:
    stack[-1] = v_33011;
    goto v_32998;
v_32999:
    stack[0] = v_33010;
    goto v_33000;
v_33001:
    v_33009 = v_33011;
    v_33009 = Llength(nil, v_33009);
    env = stack[-2];
    v_33009 = sub1(v_33009);
    env = stack[-2];
    goto v_33002;
v_33003:
    goto v_32997;
v_32998:
    goto v_32999;
v_33000:
    goto v_33001;
v_33002:
    {
        LispObject v_33014 = stack[-1];
        LispObject v_33015 = stack[0];
        fn = elt(env, 1); // coeffs!-to!-form1
        return (*qfnn(fn))(fn, 3, v_33014, v_33015, v_33009);
    }
    v_33009 = nil;
v_32989:
    return onevalue(v_33009);
}



// Code for modular!-factor!-count

static LispObject CC_modularKfactorKcount(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33181, v_33182, v_33183, v_33184;
    LispObject fn;
    argcheck(nargs, 0, "modular-factor-count");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// end of prologue
// Binding poly!-vector
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(elt(env, 1)) = nil; // poly!-vector
// Binding null!-space!-basis
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-6, 2, -4);
    qvalue(elt(env, 2)) = nil; // null!-space!-basis
    v_33181 = nil;
    qvalue(elt(env, 3)) = v_33181; // known!-factors
    v_33181 = qvalue(elt(env, 4)); // poly!-mod!-p
    v_33181 = qcar(v_33181);
    v_33181 = qcar(v_33181);
    v_33181 = qcdr(v_33181);
    qvalue(elt(env, 5)) = v_33181; // dpoly
    goto v_33006;
v_33002:
    v_33182 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33003;
v_33004:
    v_33181 = qvalue(elt(env, 5)); // dpoly
    goto v_33005;
v_33006:
    goto v_33002;
v_33003:
    goto v_33004;
v_33005:
    v_33181 = fixnum_of_int((intptr_t)(int_of_fixnum(v_33182) * int_of_fixnum(v_33181)));
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-6];
    stack[-3] = v_33181;
    goto v_33015;
v_33011:
    v_33182 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33012;
v_33013:
    v_33181 = qvalue(elt(env, 5)); // dpoly
    goto v_33014;
v_33015:
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    v_33181 = fixnum_of_int((intptr_t)(int_of_fixnum(v_33182) * int_of_fixnum(v_33181)));
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-6];
    stack[0] = v_33181;
    v_33181 = qvalue(elt(env, 5)); // dpoly
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-6];
    stack[-2] = v_33181;
    v_33181 = qvalue(elt(env, 5)); // dpoly
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-6];
    qvalue(elt(env, 1)) = v_33181; // poly!-vector
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    v_33184 = v_33181;
v_33026:
    goto v_33036;
v_33032:
    v_33182 = qvalue(elt(env, 5)); // dpoly
    goto v_33033;
v_33034:
    v_33181 = v_33184;
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    v_33181 = (LispObject)(intptr_t)((intptr_t)v_33182 - (intptr_t)v_33181 + TAG_FIXNUM);
    v_33181 = ((intptr_t)(v_33181) < 0 ? lisp_true : nil);
    if (v_33181 == nil) goto v_33031;
    goto v_33025;
v_33031:
    goto v_33048;
v_33042:
    v_33183 = qvalue(elt(env, 1)); // poly!-vector
    goto v_33043;
v_33044:
    v_33182 = v_33184;
    goto v_33045;
v_33046:
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33047;
v_33048:
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    goto v_33046;
v_33047:
    *(LispObject *)((char *)v_33183 + (CELL-TAG_VECTOR) + (((intptr_t)v_33182-TAG_FIXNUM)/(16/CELL))) = v_33181;
    v_33181 = v_33184;
    v_33181 = (LispObject)((intptr_t)(v_33181) + 0x10);
    v_33184 = v_33181;
    goto v_33026;
v_33025:
    v_33181 = qvalue(elt(env, 4)); // poly!-mod!-p
    fn = elt(env, 6); // poly!-to!-vector
    v_33181 = (*qfn1(fn))(fn, v_33181);
    env = stack[-6];
    goto v_33063;
v_33057:
    v_33183 = stack[-3];
    goto v_33058;
v_33059:
    v_33182 = stack[0];
    goto v_33060;
v_33061:
    v_33181 = stack[-2];
    goto v_33062;
v_33063:
    goto v_33057;
v_33058:
    goto v_33059;
v_33060:
    goto v_33061;
v_33062:
    fn = elt(env, 7); // count!-linear!-factors!-mod!-p
    v_33181 = (*qfnn(fn))(fn, 3, v_33183, v_33182, v_33181);
    env = stack[-6];
    stack[-1] = v_33181;
    v_33181 = stack[-1];
    v_33181 = qcar(v_33181);
    stack[0] = v_33181;
    goto v_33077;
v_33073:
    v_33182 = qvalue(elt(env, 5)); // dpoly
    goto v_33074;
v_33075:
    v_33181 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    if (((intptr_t)(v_33182)) < ((intptr_t)(v_33181))) goto v_33071;
    else goto v_33072;
v_33071:
    goto v_33087;
v_33081:
    goto v_33096;
v_33092:
    v_33182 = qvalue(elt(env, 5)); // dpoly
    goto v_33093;
v_33094:
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33095;
v_33096:
    goto v_33092;
v_33093:
    goto v_33094;
v_33095:
    if (v_33182 == v_33181) goto v_33090;
    else goto v_33091;
v_33090:
    v_33181 = stack[0];
    stack[-3] = v_33181;
    goto v_33089;
v_33091:
    v_33181 = stack[0];
    v_33181 = (LispObject)((intptr_t)(v_33181) + 0x10);
    stack[-3] = v_33181;
    goto v_33089;
    stack[-3] = nil;
v_33089:
    goto v_33082;
v_33083:
    goto v_33109;
v_33105:
    v_33182 = stack[0];
    goto v_33106;
v_33107:
    v_33181 = stack[-1];
    v_33181 = qcdr(v_33181);
    v_33181 = qcar(v_33181);
    goto v_33108;
v_33109:
    goto v_33105;
v_33106:
    goto v_33107;
v_33108:
    stack[-2] = cons(v_33182, v_33181);
    env = stack[-6];
    goto v_33084;
v_33085:
    goto v_33121;
v_33115:
    stack[-1] = qvalue(elt(env, 5)); // dpoly
    goto v_33116;
v_33117:
    stack[0] = qvalue(elt(env, 1)); // poly!-vector
    goto v_33118;
v_33119:
    v_33181 = nil;
    v_33181 = ncons(v_33181);
    env = stack[-6];
    goto v_33120;
v_33121:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    goto v_33119;
v_33120:
    v_33181 = acons(stack[-1], stack[0], v_33181);
    env = stack[-6];
    goto v_33086;
v_33087:
    goto v_33081;
v_33082:
    goto v_33083;
v_33084:
    goto v_33085;
v_33086:
    v_33181 = list2star(stack[-3], stack[-2], v_33181);
    goto v_32995;
v_33072:
    goto v_33133;
v_33127:
    v_33183 = stack[-2];
    goto v_33128;
v_33129:
    v_33181 = stack[-1];
    v_33181 = qcdr(v_33181);
    v_33181 = qcdr(v_33181);
    v_33182 = qcar(v_33181);
    goto v_33130;
v_33131:
    v_33181 = stack[-3];
    goto v_33132;
v_33133:
    goto v_33127;
v_33128:
    goto v_33129;
v_33130:
    goto v_33131;
v_33132:
    fn = elt(env, 8); // use!-berlekamp
    v_33181 = (*qfnn(fn))(fn, 3, v_33183, v_33182, v_33181);
    env = stack[-6];
    qvalue(elt(env, 2)) = v_33181; // null!-space!-basis
    goto v_33144;
v_33140:
    stack[-2] = stack[0];
    goto v_33141;
v_33142:
    v_33181 = qvalue(elt(env, 2)); // null!-space!-basis
    v_33181 = Llength(nil, v_33181);
    env = stack[-6];
    goto v_33143;
v_33144:
    goto v_33140;
v_33141:
    goto v_33142;
v_33143:
    v_33181 = (LispObject)(intptr_t)((intptr_t)stack[-2] + (intptr_t)v_33181 - TAG_FIXNUM);
    v_33181 = (LispObject)((intptr_t)(v_33181) + 0x10);
    goto v_33157;
v_33151:
    stack[-3] = v_33181;
    goto v_33152;
v_33153:
    goto v_33164;
v_33160:
    v_33182 = stack[0];
    goto v_33161;
v_33162:
    v_33181 = stack[-1];
    v_33181 = qcdr(v_33181);
    v_33181 = qcar(v_33181);
    goto v_33163;
v_33164:
    goto v_33160;
v_33161:
    goto v_33162;
v_33163:
    stack[-2] = cons(v_33182, v_33181);
    env = stack[-6];
    goto v_33154;
v_33155:
    goto v_33176;
v_33170:
    stack[-1] = qvalue(elt(env, 5)); // dpoly
    goto v_33171;
v_33172:
    stack[0] = qvalue(elt(env, 1)); // poly!-vector
    goto v_33173;
v_33174:
    v_33181 = qvalue(elt(env, 2)); // null!-space!-basis
    v_33181 = ncons(v_33181);
    env = stack[-6];
    goto v_33175;
v_33176:
    goto v_33170;
v_33171:
    goto v_33172;
v_33173:
    goto v_33174;
v_33175:
    v_33181 = acons(stack[-1], stack[0], v_33181);
    env = stack[-6];
    goto v_33156;
v_33157:
    goto v_33151;
v_33152:
    goto v_33153;
v_33154:
    goto v_33155;
v_33156:
    v_33181 = list2star(stack[-3], stack[-2], v_33181);
v_32995:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_33181);
}



// Code for super_product_sq

static LispObject CC_super_product_sq(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_33083, v_33084;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32986,v_32985);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32985,v_32986);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_32986;
    v_33083 = v_32985;
// end of prologue
    goto v_32998;
v_32994:
    v_33084 = v_33083;
    goto v_32995;
v_32996:
    v_33083 = elt(env, 1); // (ext)
    goto v_32997;
v_32998:
    goto v_32994;
v_32995:
    goto v_32996;
v_32997:
    fn = elt(env, 2); // split_ext
    v_33083 = (*qfn2(fn))(fn, v_33084, v_33083);
    env = stack[-7];
    stack[0] = v_33083;
    goto v_33006;
v_33002:
    v_33084 = stack[-1];
    goto v_33003;
v_33004:
    v_33083 = elt(env, 1); // (ext)
    goto v_33005;
v_33006:
    goto v_33002;
v_33003:
    goto v_33004;
v_33005:
    fn = elt(env, 2); // split_ext
    v_33083 = (*qfn2(fn))(fn, v_33084, v_33083);
    env = stack[-7];
    stack[-6] = v_33083;
    goto v_33014;
v_33010:
    v_33084 = nil;
    goto v_33011;
v_33012:
    v_33083 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    v_33083 = cons(v_33084, v_33083);
    env = stack[-7];
    v_33084 = v_33083;
    v_33083 = stack[0];
    stack[-5] = v_33083;
v_33020:
    v_33083 = stack[-5];
    if (v_33083 == nil) goto v_33024;
    else goto v_33025;
v_33024:
    goto v_33019;
v_33025:
    v_33083 = stack[-5];
    v_33083 = qcar(v_33083);
    stack[-4] = v_33083;
    v_33083 = stack[-6];
    stack[-3] = v_33083;
v_33034:
    v_33083 = stack[-3];
    if (v_33083 == nil) goto v_33038;
    else goto v_33039;
v_33038:
    goto v_33033;
v_33039:
    v_33083 = stack[-3];
    v_33083 = qcar(v_33083);
    stack[-2] = v_33083;
    goto v_33050;
v_33046:
    stack[-1] = v_33084;
    goto v_33047;
v_33048:
    goto v_33057;
v_33053:
    goto v_33063;
v_33059:
    v_33083 = stack[-4];
    v_33084 = qcdr(v_33083);
    goto v_33060;
v_33061:
    v_33083 = stack[-2];
    v_33083 = qcdr(v_33083);
    goto v_33062;
v_33063:
    goto v_33059;
v_33060:
    goto v_33061;
v_33062:
    fn = elt(env, 3); // multsq
    stack[0] = (*qfn2(fn))(fn, v_33084, v_33083);
    env = stack[-7];
    goto v_33054;
v_33055:
    goto v_33073;
v_33069:
    v_33083 = stack[-4];
    v_33084 = qcar(v_33083);
    goto v_33070;
v_33071:
    v_33083 = stack[-2];
    v_33083 = qcar(v_33083);
    goto v_33072;
v_33073:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    fn = elt(env, 4); // ext_mult
    v_33083 = (*qfn2(fn))(fn, v_33084, v_33083);
    env = stack[-7];
    goto v_33056;
v_33057:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    fn = elt(env, 3); // multsq
    v_33083 = (*qfn2(fn))(fn, stack[0], v_33083);
    env = stack[-7];
    goto v_33049;
v_33050:
    goto v_33046;
v_33047:
    goto v_33048;
v_33049:
    fn = elt(env, 5); // addsq
    v_33083 = (*qfn2(fn))(fn, stack[-1], v_33083);
    env = stack[-7];
    v_33084 = v_33083;
    v_33083 = stack[-3];
    v_33083 = qcdr(v_33083);
    stack[-3] = v_33083;
    goto v_33034;
v_33033:
    v_33083 = stack[-5];
    v_33083 = qcdr(v_33083);
    stack[-5] = v_33083;
    goto v_33020;
v_33019:
    v_33083 = v_33084;
    return onevalue(v_33083);
}



// Code for cl_ex

static LispObject CC_cl_ex(LispObject env,
                         LispObject v_32985, LispObject v_32986)
{
    env = qenv(env);
    LispObject v_32999, v_33000, v_33001;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32999 = v_32986;
    v_33000 = v_32985;
// end of prologue
    goto v_32995;
v_32989:
    v_33001 = elt(env, 1); // ex
    goto v_32990;
v_32991:
    goto v_32992;
v_32993:
    goto v_32994;
v_32995:
    goto v_32989;
v_32990:
    goto v_32991;
v_32992:
    goto v_32993;
v_32994:
    {
        fn = elt(env, 2); // cl_closure
        return (*qfnn(fn))(fn, 3, v_33001, v_33000, v_32999);
    }
}



setup_type const u54_setup[] =
{
    {"dip-nc-ev-prod",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod},
    {"row_dim",                 CC_row_dim,     TOO_MANY_1,    WRONG_NO_1},
    {"all_defined",             TOO_FEW_2,      CC_all_defined,WRONG_NO_2},
    {"radd",                    TOO_FEW_2,      CC_radd,       WRONG_NO_2},
    {"gak",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gak},
    {"resetparser",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_resetparser},
    {"giminusp:",               CC_giminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"opfchk!",                 CC_opfchkB,     TOO_MANY_1,    WRONG_NO_1},
    {"constant_expr_listp",     CC_constant_expr_listp,TOO_MANY_1,WRONG_NO_1},
    {"talp_nextt",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_nextt},
    {"qqe_qadd-inside",         CC_qqe_qaddKinside,TOO_MANY_1, WRONG_NO_1},
    {"tidysqrt",                CC_tidysqrt,    TOO_MANY_1,    WRONG_NO_1},
    {"cr:minusp",               CC_crTminusp,   TOO_MANY_1,    WRONG_NO_1},
    {"expttermp",               TOO_FEW_2,      CC_expttermp,  WRONG_NO_2},
    {"xriterion_2",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_2},
    {"preproc",                 CC_preproc,     TOO_MANY_1,    WRONG_NO_1},
    {"dvertex-to-projector",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvertexKtoKprojector},
    {"red_extract",             CC_red_extract, TOO_MANY_1,    WRONG_NO_1},
    {"*hfac",                   CC_Hhfac,       TOO_MANY_1,    WRONG_NO_1},
    {"rtrnda",                  TOO_FEW_2,      CC_rtrnda,     WRONG_NO_2},
    {"gd_newtype",              TOO_FEW_2,      CC_gd_newtype, WRONG_NO_2},
    {"subsubf",                 TOO_FEW_2,      CC_subsubf,    WRONG_NO_2},
    {"rand-comb",               TOO_FEW_2,      CC_randKcomb,  WRONG_NO_2},
    {"partitindexvar",          CC_partitindexvar,TOO_MANY_1,  WRONG_NO_1},
    {"physop*sq",               CC_physopHsq,   TOO_MANY_1,    WRONG_NO_1},
    {"mk-strand-vertex",        TOO_FEW_2,      CC_mkKstrandKvertex,WRONG_NO_2},
    {"general-minus-mod-p",     CC_generalKminusKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"allbkern",                CC_allbkern,    TOO_MANY_1,    WRONG_NO_1},
    {"coeffs-to-form",          TOO_FEW_2,      CC_coeffsKtoKform,WRONG_NO_2},
    {"modular-factor-count",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_modularKfactorKcount},
    {"super_product_sq",        TOO_FEW_2,      CC_super_product_sq,WRONG_NO_2},
    {"cl_ex",                   TOO_FEW_2,      CC_cl_ex,      WRONG_NO_2},
    {NULL, (one_args *)"u54", (two_args *)"126385 2862874 6719889", 0}
};

// end of generated code
