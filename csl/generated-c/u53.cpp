
// $destdir/u53.c        Machine generated C code

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



// Code for pasf_exprng

static LispObject CC_pasf_exprng(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_32147, v_32148, v_32149, v_32150, v_32151, v_32152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_32147 = v_31821;
// end of prologue
// Binding !*rlsism
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-6, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*rlsism
    v_32148 = v_32147;
    if (!consp(v_32148)) goto v_31830;
    else goto v_31831;
v_31830:
    v_32148 = v_32147;
    goto v_31829;
v_31831:
    v_32148 = v_32147;
    v_32148 = qcar(v_32148);
    goto v_31829;
    v_32148 = nil;
v_31829:
    stack[-5] = v_32148;
    goto v_31846;
v_31842:
    v_32149 = stack[-5];
    goto v_31843;
v_31844:
    v_32148 = elt(env, 2); // and
    goto v_31845;
v_31846:
    goto v_31842;
v_31843:
    goto v_31844;
v_31845:
    if (v_32149 == v_32148) goto v_31840;
    else goto v_31841;
v_31840:
    goto v_31858;
v_31850:
    v_32149 = elt(env, 2); // and
    goto v_31851;
v_31852:
    v_32150 = qcdr(v_32147);
    goto v_31853;
v_31854:
    v_32148 = elt(env, 3); // true
    goto v_31855;
v_31856:
    v_32147 = elt(env, 4); // false
    goto v_31857;
v_31858:
    goto v_31850;
v_31851:
    goto v_31852;
v_31853:
    goto v_31854;
v_31855:
    goto v_31856;
v_31857:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_32147 = (*qfnn(fn))(fn, 4, v_32149, v_32150, v_32148, v_32147);
    goto v_31827;
v_31841:
    goto v_31872;
v_31868:
    v_32149 = stack[-5];
    goto v_31869;
v_31870:
    v_32148 = elt(env, 5); // or
    goto v_31871;
v_31872:
    goto v_31868;
v_31869:
    goto v_31870;
v_31871:
    if (v_32149 == v_32148) goto v_31866;
    else goto v_31867;
v_31866:
    goto v_31884;
v_31876:
    v_32149 = elt(env, 5); // or
    goto v_31877;
v_31878:
    v_32150 = qcdr(v_32147);
    goto v_31879;
v_31880:
    v_32148 = elt(env, 4); // false
    goto v_31881;
v_31882:
    v_32147 = elt(env, 3); // true
    goto v_31883;
v_31884:
    goto v_31876;
v_31877:
    goto v_31878;
v_31879:
    goto v_31880;
v_31881:
    goto v_31882;
v_31883:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_32147 = (*qfnn(fn))(fn, 4, v_32149, v_32150, v_32148, v_32147);
    goto v_31827;
v_31867:
    goto v_31898;
v_31894:
    v_32149 = stack[-5];
    goto v_31895;
v_31896:
    v_32148 = elt(env, 6); // ball
    goto v_31897;
v_31898:
    goto v_31894;
v_31895:
    goto v_31896;
v_31897:
    if (v_32149 == v_32148) goto v_31892;
    else goto v_31893;
v_31892:
    goto v_31914;
v_31902:
    v_32148 = v_32147;
    v_32148 = qcdr(v_32148);
    v_32152 = qcar(v_32148);
    goto v_31903;
v_31904:
    v_32148 = v_32147;
    v_32148 = qcdr(v_32148);
    v_32148 = qcdr(v_32148);
    v_32148 = qcdr(v_32148);
    v_32151 = qcar(v_32148);
    goto v_31905;
v_31906:
    v_32147 = qcdr(v_32147);
    v_32147 = qcdr(v_32147);
    v_32150 = qcar(v_32147);
    goto v_31907;
v_31908:
    v_32149 = elt(env, 2); // and
    goto v_31909;
v_31910:
    v_32148 = elt(env, 3); // true
    goto v_31911;
v_31912:
    v_32147 = elt(env, 4); // false
    goto v_31913;
v_31914:
    goto v_31902;
v_31903:
    goto v_31904;
v_31905:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    goto v_31912;
v_31913:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_32147 = (*qfnn(fn))(fn, 6, v_32152, v_32151, v_32150, v_32149, v_32148, v_32147);
    goto v_31827;
v_31893:
    goto v_31938;
v_31934:
    v_32149 = stack[-5];
    goto v_31935;
v_31936:
    v_32148 = elt(env, 7); // bex
    goto v_31937;
v_31938:
    goto v_31934;
v_31935:
    goto v_31936;
v_31937:
    if (v_32149 == v_32148) goto v_31932;
    else goto v_31933;
v_31932:
    goto v_31954;
v_31942:
    v_32148 = v_32147;
    v_32148 = qcdr(v_32148);
    v_32152 = qcar(v_32148);
    goto v_31943;
v_31944:
    v_32148 = v_32147;
    v_32148 = qcdr(v_32148);
    v_32148 = qcdr(v_32148);
    v_32148 = qcdr(v_32148);
    v_32151 = qcar(v_32148);
    goto v_31945;
v_31946:
    v_32147 = qcdr(v_32147);
    v_32147 = qcdr(v_32147);
    v_32150 = qcar(v_32147);
    goto v_31947;
v_31948:
    v_32149 = elt(env, 5); // or
    goto v_31949;
v_31950:
    v_32148 = elt(env, 4); // false
    goto v_31951;
v_31952:
    v_32147 = elt(env, 3); // true
    goto v_31953;
v_31954:
    goto v_31942;
v_31943:
    goto v_31944;
v_31945:
    goto v_31946;
v_31947:
    goto v_31948;
v_31949:
    goto v_31950;
v_31951:
    goto v_31952;
v_31953:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_32147 = (*qfnn(fn))(fn, 6, v_32152, v_32151, v_32150, v_32149, v_32148, v_32147);
    goto v_31827;
v_31933:
    goto v_31990;
v_31986:
    v_32149 = stack[-5];
    goto v_31987;
v_31988:
    v_32148 = elt(env, 5); // or
    goto v_31989;
v_31990:
    goto v_31986;
v_31987:
    goto v_31988;
v_31989:
    if (v_32149 == v_32148) goto v_31984;
    else goto v_31985;
v_31984:
    v_32148 = lisp_true;
    goto v_31983;
v_31985:
    goto v_32000;
v_31996:
    v_32149 = stack[-5];
    goto v_31997;
v_31998:
    v_32148 = elt(env, 2); // and
    goto v_31999;
v_32000:
    goto v_31996;
v_31997:
    goto v_31998;
v_31999:
    v_32148 = (v_32149 == v_32148 ? lisp_true : nil);
    goto v_31983;
    v_32148 = nil;
v_31983:
    if (v_32148 == nil) goto v_31981;
    v_32148 = lisp_true;
    goto v_31979;
v_31981:
    goto v_32011;
v_32007:
    v_32149 = stack[-5];
    goto v_32008;
v_32009:
    v_32148 = elt(env, 8); // not
    goto v_32010;
v_32011:
    goto v_32007;
v_32008:
    goto v_32009;
v_32010:
    v_32148 = (v_32149 == v_32148 ? lisp_true : nil);
    goto v_31979;
    v_32148 = nil;
v_31979:
    if (v_32148 == nil) goto v_31977;
    v_32148 = lisp_true;
    goto v_31975;
v_31977:
    goto v_32026;
v_32022:
    v_32149 = stack[-5];
    goto v_32023;
v_32024:
    v_32148 = elt(env, 9); // impl
    goto v_32025;
v_32026:
    goto v_32022;
v_32023:
    goto v_32024;
v_32025:
    if (v_32149 == v_32148) goto v_32020;
    else goto v_32021;
v_32020:
    v_32148 = lisp_true;
    goto v_32019;
v_32021:
    goto v_32040;
v_32036:
    v_32149 = stack[-5];
    goto v_32037;
v_32038:
    v_32148 = elt(env, 10); // repl
    goto v_32039;
v_32040:
    goto v_32036;
v_32037:
    goto v_32038;
v_32039:
    if (v_32149 == v_32148) goto v_32034;
    else goto v_32035;
v_32034:
    v_32148 = lisp_true;
    goto v_32033;
v_32035:
    goto v_32050;
v_32046:
    v_32149 = stack[-5];
    goto v_32047;
v_32048:
    v_32148 = elt(env, 11); // equiv
    goto v_32049;
v_32050:
    goto v_32046;
v_32047:
    goto v_32048;
v_32049:
    v_32148 = (v_32149 == v_32148 ? lisp_true : nil);
    goto v_32033;
    v_32148 = nil;
v_32033:
    goto v_32019;
    v_32148 = nil;
v_32019:
    goto v_31975;
    v_32148 = nil;
v_31975:
    if (v_32148 == nil) goto v_31973;
    v_32147 = qcdr(v_32147);
    stack[-3] = v_32147;
    v_32147 = stack[-3];
    if (v_32147 == nil) goto v_32064;
    else goto v_32065;
v_32064:
    v_32147 = nil;
    goto v_32058;
v_32065:
    v_32147 = stack[-3];
    v_32147 = qcar(v_32147);
    v_32147 = CC_pasf_exprng(elt(env, 0), v_32147);
    env = stack[-6];
    v_32147 = ncons(v_32147);
    env = stack[-6];
    stack[-1] = v_32147;
    stack[-2] = v_32147;
v_32059:
    v_32147 = stack[-3];
    v_32147 = qcdr(v_32147);
    stack[-3] = v_32147;
    v_32147 = stack[-3];
    if (v_32147 == nil) goto v_32078;
    else goto v_32079;
v_32078:
    v_32147 = stack[-2];
    goto v_32058;
v_32079:
    goto v_32087;
v_32083:
    stack[0] = stack[-1];
    goto v_32084;
v_32085:
    v_32147 = stack[-3];
    v_32147 = qcar(v_32147);
    v_32147 = CC_pasf_exprng(elt(env, 0), v_32147);
    env = stack[-6];
    v_32147 = ncons(v_32147);
    env = stack[-6];
    goto v_32086;
v_32087:
    goto v_32083;
v_32084:
    goto v_32085;
v_32086:
    v_32147 = Lrplacd(nil, stack[0], v_32147);
    env = stack[-6];
    v_32147 = stack[-1];
    v_32147 = qcdr(v_32147);
    stack[-1] = v_32147;
    goto v_32059;
v_32058:
    v_32148 = v_32147;
    goto v_32104;
v_32098:
    v_32147 = v_32148;
    if (v_32147 == nil) goto v_32108;
    v_32147 = v_32148;
    v_32147 = qcdr(v_32147);
    if (v_32147 == nil) goto v_32108;
    goto v_32119;
v_32115:
    v_32147 = stack[-5];
    goto v_32116;
v_32117:
    goto v_32118;
v_32119:
    goto v_32115;
v_32116:
    goto v_32117;
v_32118:
    v_32147 = cons(v_32147, v_32148);
    env = stack[-6];
    v_32149 = v_32147;
    goto v_32106;
v_32108:
    v_32147 = v_32148;
    if (v_32147 == nil) goto v_32122;
    else goto v_32123;
v_32122:
    goto v_32133;
v_32129:
    v_32148 = stack[-5];
    goto v_32130;
v_32131:
    v_32147 = elt(env, 2); // and
    goto v_32132;
v_32133:
    goto v_32129;
v_32130:
    goto v_32131;
v_32132:
    if (v_32148 == v_32147) goto v_32127;
    else goto v_32128;
v_32127:
    v_32147 = elt(env, 3); // true
    goto v_32126;
v_32128:
    v_32147 = elt(env, 4); // false
    goto v_32126;
    v_32147 = nil;
v_32126:
    v_32149 = v_32147;
    goto v_32106;
v_32123:
    v_32147 = v_32148;
    v_32147 = qcar(v_32147);
    v_32149 = v_32147;
    goto v_32106;
    v_32149 = nil;
v_32106:
    goto v_32099;
v_32100:
    v_32148 = nil;
    goto v_32101;
v_32102:
    v_32147 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_32103;
v_32104:
    goto v_32098;
v_32099:
    goto v_32100;
v_32101:
    goto v_32102;
v_32103:
    fn = elt(env, 14); // cl_simpl
    v_32147 = (*qfnn(fn))(fn, 3, v_32149, v_32148, v_32147);
    goto v_31827;
v_31973:
v_31827:
    ;}  // end of a binding scope
    return onevalue(v_32147);
}



// Code for aex_neg

static LispObject CC_aex_neg(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31834;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    goto v_31828;
v_31824:
    v_31834 = stack[0];
    fn = elt(env, 1); // aex_ex
    v_31834 = (*qfn1(fn))(fn, v_31834);
    env = stack[-2];
    fn = elt(env, 2); // negsq
    stack[-1] = (*qfn1(fn))(fn, v_31834);
    env = stack[-2];
    goto v_31825;
v_31826:
    v_31834 = stack[0];
    fn = elt(env, 3); // aex_ctx
    v_31834 = (*qfn1(fn))(fn, v_31834);
    env = stack[-2];
    goto v_31827;
v_31828:
    goto v_31824;
v_31825:
    goto v_31826;
v_31827:
    {
        LispObject v_31837 = stack[-1];
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(fn, v_31837, v_31834);
    }
}



// Code for varsinsf

static LispObject CC_varsinsf(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31887, v_31888;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31887 = v_31822;
    stack[-1] = v_31821;
// end of prologue
    v_31888 = stack[-1];
    if (!consp(v_31888)) goto v_31830;
    else goto v_31831;
v_31830:
    v_31888 = lisp_true;
    goto v_31829;
v_31831:
    v_31888 = stack[-1];
    v_31888 = qcar(v_31888);
    v_31888 = (consp(v_31888) ? nil : lisp_true);
    goto v_31829;
    v_31888 = nil;
v_31829:
    if (v_31888 == nil) goto v_31827;
    goto v_31825;
v_31827:
v_31846:
    v_31888 = stack[-1];
    if (!consp(v_31888)) goto v_31853;
    else goto v_31854;
v_31853:
    v_31888 = lisp_true;
    goto v_31852;
v_31854:
    v_31888 = stack[-1];
    v_31888 = qcar(v_31888);
    v_31888 = (consp(v_31888) ? nil : lisp_true);
    goto v_31852;
    v_31888 = nil;
v_31852:
    if (v_31888 == nil) goto v_31850;
    goto v_31845;
v_31850:
    goto v_31868;
v_31864:
    v_31888 = stack[-1];
    v_31888 = qcar(v_31888);
    stack[-2] = qcdr(v_31888);
    goto v_31865;
v_31866:
    goto v_31877;
v_31873:
    stack[0] = v_31887;
    goto v_31874;
v_31875:
    v_31887 = stack[-1];
    v_31887 = qcar(v_31887);
    v_31887 = qcar(v_31887);
    v_31887 = qcar(v_31887);
    v_31887 = ncons(v_31887);
    env = stack[-3];
    goto v_31876;
v_31877:
    goto v_31873;
v_31874:
    goto v_31875;
v_31876:
    fn = elt(env, 1); // union
    v_31887 = (*qfn2(fn))(fn, stack[0], v_31887);
    env = stack[-3];
    goto v_31867;
v_31868:
    goto v_31864;
v_31865:
    goto v_31866;
v_31867:
    v_31887 = CC_varsinsf(elt(env, 0), stack[-2], v_31887);
    env = stack[-3];
    v_31888 = stack[-1];
    v_31888 = qcdr(v_31888);
    stack[-1] = v_31888;
    goto v_31846;
v_31845:
    goto v_31825;
    v_31887 = nil;
v_31825:
    return onevalue(v_31887);
}



// Code for mkratnum

static LispObject CC_mkratnum(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31873, v_31874, v_31875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
// copy arguments values to proper place
    v_31875 = v_31821;
// end of prologue
    v_31873 = v_31875;
    if (!consp(v_31873)) goto v_31825;
    else goto v_31826;
v_31825:
    v_31873 = v_31875;
    {
        fn = elt(env, 4); // !*i2rn
        return (*qfn1(fn))(fn, v_31873);
    }
v_31826:
    goto v_31836;
v_31832:
    v_31873 = v_31875;
    v_31874 = qcar(v_31873);
    goto v_31833;
v_31834:
    v_31873 = elt(env, 1); // !:gi!:
    goto v_31835;
v_31836:
    goto v_31832;
v_31833:
    goto v_31834;
v_31835:
    if (v_31874 == v_31873) goto v_31830;
    else goto v_31831;
v_31830:
    goto v_31845;
v_31841:
    goto v_31851;
v_31847:
    v_31874 = elt(env, 1); // !:gi!:
    goto v_31848;
v_31849:
    v_31873 = elt(env, 2); // !:crn!:
    goto v_31850;
v_31851:
    goto v_31847;
v_31848:
    goto v_31849;
v_31850:
    v_31873 = get(v_31874, v_31873);
    goto v_31842;
v_31843:
    v_31874 = v_31875;
    goto v_31844;
v_31845:
    goto v_31841;
v_31842:
    goto v_31843;
v_31844:
        return Lapply1(nil, v_31873, v_31874);
v_31831:
    goto v_31862;
v_31858:
    goto v_31868;
v_31864:
    v_31873 = v_31875;
    v_31874 = qcar(v_31873);
    goto v_31865;
v_31866:
    v_31873 = elt(env, 3); // !:rn!:
    goto v_31867;
v_31868:
    goto v_31864;
v_31865:
    goto v_31866;
v_31867:
    v_31873 = get(v_31874, v_31873);
    goto v_31859;
v_31860:
    v_31874 = v_31875;
    goto v_31861;
v_31862:
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
        return Lapply1(nil, v_31873, v_31874);
    v_31873 = nil;
    return onevalue(v_31873);
}



// Code for xpartitsq

static LispObject CC_xpartitsq(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_32002, v_32003, v_32004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_32004 = v_31821;
// end of prologue
    v_32002 = v_32004;
    v_32003 = qcar(v_32002);
    v_32002 = v_32004;
    v_32002 = qcdr(v_32002);
    stack[-2] = v_32003;
    stack[-1] = v_32002;
    v_32002 = stack[-2];
    if (v_32002 == nil) goto v_31831;
    else goto v_31832;
v_31831:
    v_32002 = nil;
    goto v_31830;
v_31832:
    v_32002 = stack[-2];
    if (!consp(v_32002)) goto v_31839;
    else goto v_31840;
v_31839:
    v_32002 = lisp_true;
    goto v_31838;
v_31840:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = (consp(v_32002) ? nil : lisp_true);
    goto v_31838;
    v_32002 = nil;
v_31838:
    if (v_32002 == nil) goto v_31836;
    goto v_31854;
v_31850:
    v_32002 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31851;
v_31852:
    v_32003 = v_32004;
    goto v_31853;
v_31854:
    goto v_31850;
v_31851:
    goto v_31852;
v_31853:
    v_32002 = cons(v_32002, v_32003);
    return ncons(v_32002);
v_31836:
    goto v_31864;
v_31860:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    fn = elt(env, 1); // sfp
    v_32002 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    if (v_32002 == nil) goto v_31868;
    goto v_31879;
v_31875:
    goto v_31885;
v_31881:
    goto v_31892;
v_31888:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32003 = qcar(v_32002);
    goto v_31889;
v_31890:
    v_32002 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31891;
v_31892:
    goto v_31888;
v_31889:
    goto v_31890;
v_31891:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    v_32003 = CC_xpartitsq(elt(env, 0), v_32002);
    env = stack[-3];
    goto v_31882;
v_31883:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32002 = qcdr(v_32002);
    goto v_31884;
v_31885:
    goto v_31881;
v_31882:
    goto v_31883;
v_31884:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_32003, v_32002);
    env = stack[-3];
    goto v_31876;
v_31877:
    goto v_31909;
v_31905:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32003 = qcdr(v_32002);
    goto v_31906;
v_31907:
    v_32002 = stack[-1];
    goto v_31908;
v_31909:
    goto v_31905;
v_31906:
    goto v_31907;
v_31908:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32002 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    v_32002 = CC_xpartitsq(elt(env, 0), v_32002);
    env = stack[-3];
    goto v_31878;
v_31879:
    goto v_31875;
v_31876:
    goto v_31877;
v_31878:
    fn = elt(env, 4); // wedgepf
    v_32002 = (*qfn2(fn))(fn, stack[0], v_32002);
    env = stack[-3];
    stack[0] = v_32002;
    goto v_31866;
v_31868:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    fn = elt(env, 5); // xvarp
    v_32002 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    if (v_32002 == nil) goto v_31915;
    goto v_31926;
v_31922:
    goto v_31932;
v_31928:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    fn = elt(env, 6); // xpartitk
    v_32003 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    goto v_31929;
v_31930:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32002 = qcar(v_32002);
    v_32002 = qcdr(v_32002);
    goto v_31931;
v_31932:
    goto v_31928;
v_31929:
    goto v_31930;
v_31931:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_32003, v_32002);
    env = stack[-3];
    goto v_31923;
v_31924:
    goto v_31949;
v_31945:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32003 = qcdr(v_32002);
    goto v_31946;
v_31947:
    v_32002 = stack[-1];
    goto v_31948;
v_31949:
    goto v_31945;
v_31946:
    goto v_31947;
v_31948:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32002 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    v_32002 = CC_xpartitsq(elt(env, 0), v_32002);
    env = stack[-3];
    goto v_31925;
v_31926:
    goto v_31922;
v_31923:
    goto v_31924;
v_31925:
    fn = elt(env, 4); // wedgepf
    v_32002 = (*qfn2(fn))(fn, stack[0], v_32002);
    env = stack[-3];
    stack[0] = v_32002;
    goto v_31866;
v_31915:
    goto v_31961;
v_31957:
    goto v_31969;
v_31965:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32003 = qcdr(v_32002);
    goto v_31966;
v_31967:
    v_32002 = stack[-1];
    goto v_31968;
v_31969:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32002 = (*qfn1(fn))(fn, v_32002);
    env = stack[-3];
    stack[0] = CC_xpartitsq(elt(env, 0), v_32002);
    env = stack[-3];
    goto v_31958;
v_31959:
    goto v_31979;
v_31975:
    goto v_31986;
v_31982:
    v_32002 = stack[-2];
    v_32002 = qcar(v_32002);
    v_32003 = qcar(v_32002);
    goto v_31983;
v_31984:
    v_32002 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31985;
v_31986:
    goto v_31982;
v_31983:
    goto v_31984;
v_31985:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    v_32003 = ncons(v_32002);
    env = stack[-3];
    goto v_31976;
v_31977:
    v_32002 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31978;
v_31979:
    goto v_31975;
v_31976:
    goto v_31977;
v_31978:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    goto v_31960;
v_31961:
    goto v_31957;
v_31958:
    goto v_31959;
v_31960:
    fn = elt(env, 7); // multpfsq
    v_32002 = (*qfn2(fn))(fn, stack[0], v_32002);
    env = stack[-3];
    stack[0] = v_32002;
    goto v_31866;
    stack[0] = nil;
v_31866:
    goto v_31861;
v_31862:
    goto v_31998;
v_31994:
    v_32002 = stack[-2];
    v_32003 = qcdr(v_32002);
    goto v_31995;
v_31996:
    v_32002 = stack[-1];
    goto v_31997;
v_31998:
    goto v_31994;
v_31995:
    goto v_31996;
v_31997:
    v_32002 = cons(v_32003, v_32002);
    env = stack[-3];
    v_32002 = CC_xpartitsq(elt(env, 0), v_32002);
    env = stack[-3];
    goto v_31863;
v_31864:
    goto v_31860;
v_31861:
    goto v_31862;
v_31863:
    {
        LispObject v_32008 = stack[0];
        fn = elt(env, 8); // addpf
        return (*qfn2(fn))(fn, v_32008, v_32002);
    }
    v_32002 = nil;
v_31830:
    return onevalue(v_32002);
}



// Code for binc

static LispObject CC_binc(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31858, v_31859, v_31860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31822;
    v_31860 = v_31821;
// end of prologue
    goto v_31832;
v_31828:
    v_31859 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31829;
v_31830:
    v_31858 = stack[0];
    goto v_31831;
v_31832:
    goto v_31828;
v_31829:
    goto v_31830;
v_31831:
    if (v_31859 == v_31858) goto v_31826;
    else goto v_31827;
v_31826:
    v_31858 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31825;
v_31827:
    goto v_31843;
v_31839:
    goto v_31852;
v_31846:
    goto v_31847;
v_31848:
    v_31859 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31849;
v_31850:
    v_31858 = stack[0];
    goto v_31851;
v_31852:
    goto v_31846;
v_31847:
    goto v_31848;
v_31849:
    goto v_31850;
v_31851:
    fn = elt(env, 1); // mk!-numr
    v_31858 = (*qfnn(fn))(fn, 3, v_31860, v_31859, v_31858);
    env = stack[-2];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(fn, v_31858);
    env = stack[-2];
    goto v_31840;
v_31841:
    v_31858 = stack[0];
    fn = elt(env, 3); // factorial
    v_31858 = (*qfn1(fn))(fn, v_31858);
    env = stack[-2];
    goto v_31842;
v_31843:
    goto v_31839;
v_31840:
    goto v_31841;
v_31842:
    {
        LispObject v_31863 = stack[-1];
        fn = elt(env, 4); // listquotient
        return (*qfn2(fn))(fn, v_31863, v_31858);
    }
    v_31858 = nil;
v_31825:
    return onevalue(v_31858);
}



// Code for gi

static LispObject CC_gi(LispObject env,
                         LispObject v_31822, LispObject v_31823)
{
    env = qenv(env);
    LispObject v_31870, v_31871;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31823,v_31822);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31822,v_31823);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_31823;
    v_31870 = v_31822;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_31870; // gg!*
    stack[-2] = nil;
    v_31870 = qvalue(elt(env, 1)); // gg!*
    stack[-1] = v_31870;
v_31835:
    v_31870 = stack[-1];
    if (v_31870 == nil) goto v_31839;
    else goto v_31840;
v_31839:
    goto v_31834;
v_31840:
    v_31870 = stack[-1];
    v_31870 = qcar(v_31870);
    stack[0] = v_31870;
    goto v_31854;
v_31850:
    v_31870 = stack[0];
    v_31870 = qcdr(v_31870);
    fn = elt(env, 2); // class
    v_31871 = (*qfn1(fn))(fn, v_31870);
    env = stack[-5];
    goto v_31851;
v_31852:
    v_31870 = stack[-3];
    goto v_31853;
v_31854:
    goto v_31850;
v_31851:
    goto v_31852;
v_31853:
    if (equal(v_31871, v_31870)) goto v_31848;
    else goto v_31849;
v_31848:
    goto v_31864;
v_31860:
    v_31871 = stack[0];
    goto v_31861;
v_31862:
    v_31870 = stack[-2];
    goto v_31863;
v_31864:
    goto v_31860;
v_31861:
    goto v_31862;
v_31863:
    v_31870 = cons(v_31871, v_31870);
    env = stack[-5];
    stack[-2] = v_31870;
    goto v_31847;
v_31849:
v_31847:
    v_31870 = stack[-1];
    v_31870 = qcdr(v_31870);
    stack[-1] = v_31870;
    goto v_31835;
v_31834:
    v_31870 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_31870);
}



// Code for exports

static LispObject CC_exports(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31833, v_31834;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31833 = v_31821;
// end of prologue
    goto v_31830;
v_31826:
    v_31834 = v_31833;
    goto v_31827;
v_31828:
    v_31833 = qvalue(elt(env, 1)); // exportslist!*
    goto v_31829;
v_31830:
    goto v_31826;
v_31827:
    goto v_31828;
v_31829:
    fn = elt(env, 2); // union
    v_31833 = (*qfn2(fn))(fn, v_31834, v_31833);
    env = stack[0];
    qvalue(elt(env, 1)) = v_31833; // exportslist!*
    v_31833 = nil;
    return onevalue(v_31833);
}



// Code for square!-free!-mod!-p

static LispObject CC_squareKfreeKmodKp(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31862, v_31863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31863 = v_31821;
// end of prologue
    v_31862 = v_31863;
    if (!consp(v_31862)) goto v_31829;
    else goto v_31830;
v_31829:
    v_31862 = lisp_true;
    goto v_31828;
v_31830:
    v_31862 = v_31863;
    v_31862 = qcar(v_31862);
    v_31862 = (consp(v_31862) ? nil : lisp_true);
    goto v_31828;
    v_31862 = nil;
v_31828:
    if (v_31862 == nil) goto v_31826;
    v_31862 = lisp_true;
    goto v_31824;
v_31826:
    goto v_31846;
v_31842:
    stack[0] = v_31863;
    goto v_31843;
v_31844:
    v_31862 = v_31863;
    fn = elt(env, 1); // derivative!-mod!-p
    v_31862 = (*qfn1(fn))(fn, v_31862);
    env = stack[-1];
    goto v_31845;
v_31846:
    goto v_31842;
v_31843:
    goto v_31844;
v_31845:
    fn = elt(env, 2); // gcd!-mod!-p
    v_31862 = (*qfn2(fn))(fn, stack[0], v_31862);
    v_31863 = v_31862;
    v_31862 = v_31863;
    if (!consp(v_31862)) goto v_31853;
    else goto v_31854;
v_31853:
    v_31862 = lisp_true;
    goto v_31852;
v_31854:
    v_31862 = v_31863;
    v_31862 = qcar(v_31862);
    v_31862 = (consp(v_31862) ? nil : lisp_true);
    goto v_31852;
    v_31862 = nil;
v_31852:
    goto v_31824;
    v_31862 = nil;
v_31824:
    return onevalue(v_31862);
}



// Code for addinds

static LispObject CC_addinds(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31887, v_31888;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31822;
    stack[-1] = v_31821;
// end of prologue
    stack[-2] = nil;
v_31827:
    v_31887 = stack[-1];
    if (v_31887 == nil) goto v_31830;
    else goto v_31831;
v_31830:
    v_31887 = stack[0];
    if (v_31887 == nil) goto v_31835;
    else goto v_31836;
v_31835:
    v_31887 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_31887);
    }
v_31836:
    goto v_31847;
v_31843:
    stack[0] = stack[-2];
    goto v_31844;
v_31845:
    v_31887 = elt(env, 1); // "Powrhs too long"
    fn = elt(env, 4); // interr
    v_31887 = (*qfn1(fn))(fn, v_31887);
    env = stack[-3];
    goto v_31846;
v_31847:
    goto v_31843;
v_31844:
    goto v_31845;
v_31846:
    {
        LispObject v_31892 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31892, v_31887);
    }
    goto v_31829;
v_31831:
    v_31887 = stack[0];
    if (v_31887 == nil) goto v_31851;
    else goto v_31852;
v_31851:
    goto v_31859;
v_31855:
    stack[0] = stack[-2];
    goto v_31856;
v_31857:
    v_31887 = elt(env, 2); // "Powu too long"
    fn = elt(env, 4); // interr
    v_31887 = (*qfn1(fn))(fn, v_31887);
    env = stack[-3];
    goto v_31858;
v_31859:
    goto v_31855;
v_31856:
    goto v_31857;
v_31858:
    {
        LispObject v_31893 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31893, v_31887);
    }
v_31852:
    goto v_31870;
v_31866:
    goto v_31876;
v_31872:
    v_31887 = stack[-1];
    v_31888 = qcar(v_31887);
    goto v_31873;
v_31874:
    v_31887 = stack[0];
    v_31887 = qcar(v_31887);
    v_31887 = qcar(v_31887);
    goto v_31875;
v_31876:
    goto v_31872;
v_31873:
    goto v_31874;
v_31875:
    v_31888 = plus2(v_31888, v_31887);
    env = stack[-3];
    goto v_31867;
v_31868:
    v_31887 = stack[-2];
    goto v_31869;
v_31870:
    goto v_31866;
v_31867:
    goto v_31868;
v_31869:
    v_31887 = cons(v_31888, v_31887);
    env = stack[-3];
    stack[-2] = v_31887;
    v_31887 = stack[-1];
    v_31887 = qcdr(v_31887);
    stack[-1] = v_31887;
    v_31887 = stack[0];
    v_31887 = qcdr(v_31887);
    stack[0] = v_31887;
    goto v_31827;
v_31829:
    v_31887 = nil;
    return onevalue(v_31887);
}



// Code for subscriptedvarp2

static LispObject CC_subscriptedvarp2(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31839, v_31840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31839 = v_31821;
// end of prologue
    goto v_31828;
v_31824:
    goto v_31835;
v_31831:
    v_31840 = nil;
    goto v_31832;
v_31833:
    goto v_31834;
v_31835:
    goto v_31831;
v_31832:
    goto v_31833;
v_31834:
    fn = elt(env, 1); // symtabget
    v_31839 = (*qfn2(fn))(fn, v_31840, v_31839);
    env = stack[0];
    v_31840 = Llength(nil, v_31839);
    goto v_31825;
v_31826:
    v_31839 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31827;
v_31828:
    goto v_31824;
v_31825:
    goto v_31826;
v_31827:
        return Lgreaterp(nil, v_31840, v_31839);
}



// Code for evalsubset

static LispObject CC_evalsubset(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31846, v_31847, v_31848;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31846 = v_31822;
    v_31847 = v_31821;
// end of prologue
    goto v_31831;
v_31825:
    v_31848 = elt(env, 1); // subset
    goto v_31826;
v_31827:
    goto v_31828;
v_31829:
    goto v_31830;
v_31831:
    goto v_31825;
v_31826:
    goto v_31827;
v_31828:
    goto v_31829;
v_31830:
    fn = elt(env, 2); // evalsetbool
    v_31846 = (*qfnn(fn))(fn, 3, v_31848, v_31847, v_31846);
    env = stack[0];
    v_31847 = v_31846;
    v_31846 = v_31847;
    if (!consp(v_31846)) goto v_31838;
    else goto v_31839;
v_31838:
    v_31846 = v_31847;
    goto v_31837;
v_31839:
    v_31846 = v_31847;
    {
        fn = elt(env, 3); // evalsymsubset
        return (*qfn1(fn))(fn, v_31846);
    }
    v_31846 = nil;
v_31837:
    return onevalue(v_31846);
}



// Code for !*kp2q

static LispObject CC_Hkp2q(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31874, v_31875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31822;
    stack[-1] = v_31821;
// end of prologue
    goto v_31833;
v_31829:
    v_31875 = stack[0];
    goto v_31830;
v_31831:
    v_31874 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31832;
v_31833:
    goto v_31829;
v_31830:
    goto v_31831;
v_31832:
    v_31874 = (LispObject)greaterp2(v_31875, v_31874);
    v_31874 = v_31874 ? lisp_true : nil;
    env = stack[-2];
    if (v_31874 == nil) goto v_31827;
    goto v_31841;
v_31837:
    v_31875 = stack[-1];
    goto v_31838;
v_31839:
    v_31874 = stack[0];
    goto v_31840;
v_31841:
    goto v_31837;
v_31838:
    goto v_31839;
v_31840:
    {
        fn = elt(env, 2); // mksq
        return (*qfn2(fn))(fn, v_31875, v_31874);
    }
v_31827:
    v_31874 = stack[0];
    v_31874 = (LispObject)zerop(v_31874);
    v_31874 = v_31874 ? lisp_true : nil;
    env = stack[-2];
    if (v_31874 == nil) goto v_31845;
    goto v_31853;
v_31849:
    v_31875 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31850;
v_31851:
    v_31874 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31852;
v_31853:
    goto v_31849;
v_31850:
    goto v_31851;
v_31852:
    return cons(v_31875, v_31874);
v_31845:
    goto v_31863;
v_31859:
    goto v_31860;
v_31861:
    v_31874 = stack[0];
    v_31874 = negate(v_31874);
    env = stack[-2];
    goto v_31862;
v_31863:
    goto v_31859;
v_31860:
    goto v_31861;
v_31862:
    fn = elt(env, 2); // mksq
    v_31874 = (*qfn2(fn))(fn, stack[-1], v_31874);
    env = stack[-2];
    stack[-1] = v_31874;
    v_31874 = qcar(v_31874);
    if (v_31874 == nil) goto v_31856;
    else goto v_31857;
v_31856:
    v_31874 = elt(env, 1); // "Zero divisor"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_31874);
    }
v_31857:
    v_31874 = stack[-1];
    {
        fn = elt(env, 4); // revpr
        return (*qfn1(fn))(fn, v_31874);
    }
    v_31874 = nil;
    return onevalue(v_31874);
}



// Code for calc_world

static LispObject CC_calc_world(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31885, v_31886;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31822;
    stack[-2] = v_31821;
// end of prologue
    goto v_31833;
v_31829:
    stack[0] = stack[-1];
    goto v_31830;
v_31831:
    v_31885 = stack[-2];
    fn = elt(env, 1); // s_world_names
    v_31885 = (*qfn1(fn))(fn, v_31885);
    env = stack[-4];
    goto v_31832;
v_31833:
    goto v_31829;
v_31830:
    goto v_31831;
v_31832:
    fn = elt(env, 2); // actual_alst
    v_31885 = (*qfn2(fn))(fn, stack[0], v_31885);
    env = stack[-4];
    stack[-1] = v_31885;
    v_31885 = stack[-2];
    v_31885 = qcdr(v_31885);
    v_31885 = qcar(v_31885);
    stack[0] = v_31885;
    goto v_31844;
v_31840:
    v_31886 = stack[-1];
    goto v_31841;
v_31842:
    v_31885 = stack[0];
    v_31885 = qcdr(v_31885);
    goto v_31843;
v_31844:
    goto v_31840;
v_31841:
    goto v_31842;
v_31843:
    v_31885 = Lassoc(nil, v_31886, v_31885);
    stack[-3] = v_31885;
    v_31885 = stack[-3];
    if (v_31885 == nil) goto v_31852;
    v_31885 = stack[-3];
    v_31885 = qcdr(v_31885);
    goto v_31827;
v_31852:
    goto v_31862;
v_31858:
    v_31885 = stack[-2];
    v_31885 = qcdr(v_31885);
    v_31885 = qcdr(v_31885);
    v_31886 = qcar(v_31885);
    goto v_31859;
v_31860:
    v_31885 = stack[-1];
    goto v_31861;
v_31862:
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
    fn = elt(env, 3); // calc_atlas
    v_31885 = (*qfn2(fn))(fn, v_31886, v_31885);
    env = stack[-4];
    fn = elt(env, 4); // reval
    v_31885 = (*qfn1(fn))(fn, v_31885);
    env = stack[-4];
    stack[-3] = v_31885;
    goto v_31873;
v_31869:
    goto v_31870;
v_31871:
    goto v_31881;
v_31877:
    v_31886 = stack[-1];
    goto v_31878;
v_31879:
    v_31885 = stack[-3];
    goto v_31880;
v_31881:
    goto v_31877;
v_31878:
    goto v_31879;
v_31880:
    v_31885 = cons(v_31886, v_31885);
    env = stack[-4];
    v_31885 = ncons(v_31885);
    env = stack[-4];
    goto v_31872;
v_31873:
    goto v_31869;
v_31870:
    goto v_31871;
v_31872:
    v_31885 = Lnconc(nil, stack[0], v_31885);
    v_31885 = stack[-3];
v_31827:
    return onevalue(v_31885);
}



// Code for liendimcom

static LispObject CC_liendimcom(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_32970, v_32971, v_32972, v_32973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_31821;
// end of prologue
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-9] = v_32970;
    goto v_31833;
v_31829:
    stack[0] = elt(env, 1); // lie_dim
    goto v_31830;
v_31831:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31832;
v_31833:
    goto v_31829;
v_31830:
    goto v_31831;
v_31832:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_32970;
v_31840:
    goto v_31854;
v_31848:
    stack[0] = elt(env, 2); // difference
    goto v_31849;
v_31850:
    goto v_31864;
v_31858:
    v_32972 = elt(env, 2); // difference
    goto v_31859;
v_31860:
    v_32971 = stack[-8];
    goto v_31861;
v_31862:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31863;
v_31864:
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
    goto v_31862;
v_31863:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31851;
v_31852:
    v_32970 = stack[-3];
    goto v_31853;
v_31854:
    goto v_31848;
v_31849:
    goto v_31850;
v_31851:
    goto v_31852;
v_31853:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_31845;
    goto v_31839;
v_31845:
    v_32970 = stack[-3];
    stack[-2] = v_32970;
v_31873:
    goto v_31887;
v_31881:
    stack[0] = elt(env, 2); // difference
    goto v_31882;
v_31883:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31884;
v_31885:
    v_32970 = stack[-2];
    goto v_31886;
v_31887:
    goto v_31881;
v_31882:
    goto v_31883;
v_31884:
    goto v_31885;
v_31886:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_31878;
    goto v_31872;
v_31878:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32970;
v_31896:
    goto v_31910;
v_31904:
    stack[0] = elt(env, 2); // difference
    goto v_31905;
v_31906:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31907;
v_31908:
    v_32970 = stack[-1];
    goto v_31909;
v_31910:
    goto v_31904;
v_31905:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_31901;
    goto v_31895;
v_31901:
    goto v_31925;
v_31921:
    goto v_31936;
v_31928:
    v_32973 = elt(env, 3); // lie_cc
    goto v_31929;
v_31930:
    v_32972 = stack[-3];
    goto v_31931;
v_31932:
    v_32971 = stack[-2];
    goto v_31933;
v_31934:
    v_32970 = stack[-1];
    goto v_31935;
v_31936:
    goto v_31928;
v_31929:
    goto v_31930;
v_31931:
    goto v_31932;
v_31933:
    goto v_31934;
v_31935:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31922;
v_31923:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31924;
v_31925:
    goto v_31921;
v_31922:
    goto v_31923;
v_31924:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_31919;
    goto v_31947;
v_31943:
    stack[0] = elt(env, 1); // lie_dim
    goto v_31944;
v_31945:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31946;
v_31947:
    goto v_31943;
v_31944:
    goto v_31945;
v_31946:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_31956;
v_31952:
    stack[0] = elt(env, 4); // lie_p
    goto v_31953;
v_31954:
    v_32970 = stack[-3];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31955;
v_31956:
    goto v_31952;
v_31953:
    goto v_31954;
v_31955:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_31965;
v_31961:
    stack[0] = elt(env, 5); // lie_q
    goto v_31962;
v_31963:
    v_32970 = stack[-2];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_31964;
v_31965:
    goto v_31961;
v_31962:
    goto v_31963;
v_31964:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-9] = v_32970;
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    goto v_31981;
v_31975:
    v_32972 = elt(env, 6); // plus
    goto v_31976;
v_31977:
    v_32971 = stack[-8];
    goto v_31978;
v_31979:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31980;
v_31981:
    goto v_31975;
v_31976:
    goto v_31977;
v_31978:
    goto v_31979;
v_31980:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    stack[-2] = v_32970;
    goto v_31917;
v_31919:
v_31917:
    v_32970 = stack[-1];
    goto v_31995;
v_31989:
    v_32972 = elt(env, 6); // plus
    goto v_31990;
v_31991:
    v_32971 = v_32970;
    goto v_31992;
v_31993:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31994;
v_31995:
    goto v_31989;
v_31990:
    goto v_31991;
v_31992:
    goto v_31993;
v_31994:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_31896;
v_31895:
    v_32970 = stack[-2];
    goto v_32009;
v_32003:
    v_32972 = elt(env, 6); // plus
    goto v_32004;
v_32005:
    v_32971 = v_32970;
    goto v_32006;
v_32007:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32008;
v_32009:
    goto v_32003;
v_32004:
    goto v_32005;
v_32006:
    goto v_32007;
v_32008:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-2] = v_32970;
    goto v_31873;
v_31872:
    v_32970 = stack[-3];
    goto v_32023;
v_32017:
    v_32972 = elt(env, 6); // plus
    goto v_32018;
v_32019:
    v_32971 = v_32970;
    goto v_32020;
v_32021:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32022;
v_32023:
    goto v_32017;
v_32018:
    goto v_32019;
v_32020:
    goto v_32021;
v_32022:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    goto v_31840;
v_31839:
    goto v_32036;
v_32032:
    v_32970 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32033;
v_32034:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32035;
v_32036:
    goto v_32032;
v_32033:
    goto v_32034;
v_32035:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32030;
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32970;
v_32043:
    goto v_32057;
v_32051:
    stack[0] = elt(env, 2); // difference
    goto v_32052;
v_32053:
    goto v_32067;
v_32061:
    v_32972 = elt(env, 2); // difference
    goto v_32062;
v_32063:
    v_32971 = stack[-8];
    goto v_32064;
v_32065:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32066;
v_32067:
    goto v_32061;
v_32062:
    goto v_32063;
v_32064:
    goto v_32065;
v_32066:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32054;
v_32055:
    v_32970 = stack[-5];
    goto v_32056;
v_32057:
    goto v_32051;
v_32052:
    goto v_32053;
v_32054:
    goto v_32055;
v_32056:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32048;
    goto v_32042;
v_32048:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_32970;
v_32076:
    goto v_32090;
v_32084:
    stack[0] = elt(env, 2); // difference
    goto v_32085;
v_32086:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32087;
v_32088:
    v_32970 = stack[-4];
    goto v_32089;
v_32090:
    goto v_32084;
v_32085:
    goto v_32086;
v_32087:
    goto v_32088;
v_32089:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32081;
    goto v_32075;
v_32081:
    goto v_32104;
v_32098:
    stack[-1] = elt(env, 7); // quotient
    goto v_32099;
v_32100:
    goto v_32115;
v_32107:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32108;
v_32109:
    v_32972 = stack[-5];
    goto v_32110;
v_32111:
    v_32971 = stack[-4];
    goto v_32112;
v_32113:
    v_32970 = stack[-9];
    goto v_32114;
v_32115:
    goto v_32107;
v_32108:
    goto v_32109;
v_32110:
    goto v_32111;
v_32112:
    goto v_32113;
v_32114:
    stack[0] = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32101;
v_32102:
    goto v_32129;
v_32121:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32122;
v_32123:
    v_32972 = elt(env, 4); // lie_p
    goto v_32124;
v_32125:
    v_32971 = elt(env, 5); // lie_q
    goto v_32126;
v_32127:
    v_32970 = stack[-9];
    goto v_32128;
v_32129:
    goto v_32121;
v_32122:
    goto v_32123;
v_32124:
    goto v_32125;
v_32126:
    goto v_32127;
v_32128:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32103;
v_32104:
    goto v_32098;
v_32099:
    goto v_32100;
v_32101:
    goto v_32102;
v_32103:
    v_32970 = list3(stack[-1], stack[0], v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-6] = v_32970;
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_32970;
v_32137:
    goto v_32151;
v_32145:
    stack[0] = elt(env, 2); // difference
    goto v_32146;
v_32147:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32148;
v_32149:
    v_32970 = stack[-3];
    goto v_32150;
v_32151:
    goto v_32145;
v_32146:
    goto v_32147;
v_32148:
    goto v_32149;
v_32150:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32142;
    goto v_32136;
v_32142:
    goto v_32166;
v_32162:
    goto v_32177;
v_32169:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32170;
v_32171:
    v_32972 = stack[-5];
    goto v_32172;
v_32173:
    v_32971 = stack[-4];
    goto v_32174;
v_32175:
    v_32970 = stack[-3];
    goto v_32176;
v_32177:
    goto v_32169;
v_32170:
    goto v_32171;
v_32172:
    goto v_32173;
v_32174:
    goto v_32175;
v_32176:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    stack[-2] = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32163;
v_32164:
    goto v_32190;
v_32184:
    stack[-1] = elt(env, 8); // times
    goto v_32185;
v_32186:
    stack[0] = stack[-6];
    goto v_32187;
v_32188:
    goto v_32202;
v_32194:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32195;
v_32196:
    v_32972 = elt(env, 4); // lie_p
    goto v_32197;
v_32198:
    v_32971 = elt(env, 5); // lie_q
    goto v_32199;
v_32200:
    v_32970 = stack[-3];
    goto v_32201;
v_32202:
    goto v_32194;
v_32195:
    goto v_32196;
v_32197:
    goto v_32198;
v_32199:
    goto v_32200;
v_32201:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32189;
v_32190:
    goto v_32184;
v_32185:
    goto v_32186;
v_32187:
    goto v_32188;
v_32189:
    v_32970 = list3(stack[-1], stack[0], v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32165;
v_32166:
    goto v_32162;
v_32163:
    goto v_32164;
v_32165:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, stack[-2], v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32160;
    goto v_32212;
v_32208:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32209;
v_32210:
    v_32970 = (LispObject)32+TAG_FIXNUM; // 2
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32211;
v_32212:
    goto v_32208;
v_32209:
    goto v_32210;
v_32211:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-5] = v_32970;
    goto v_32226;
v_32220:
    v_32972 = elt(env, 6); // plus
    goto v_32221;
v_32222:
    v_32971 = stack[-8];
    goto v_32223;
v_32224:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32225;
v_32226:
    goto v_32220;
v_32221:
    goto v_32222;
v_32223:
    goto v_32224;
v_32225:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-4] = v_32970;
    goto v_32238;
v_32232:
    v_32972 = elt(env, 6); // plus
    goto v_32233;
v_32234:
    v_32971 = stack[-8];
    goto v_32235;
v_32236:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32237;
v_32238:
    goto v_32232;
v_32233:
    goto v_32234;
v_32235:
    goto v_32236;
v_32237:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    goto v_32158;
v_32160:
v_32158:
    v_32970 = stack[-3];
    goto v_32252;
v_32246:
    v_32972 = elt(env, 6); // plus
    goto v_32247;
v_32248:
    v_32971 = v_32970;
    goto v_32249;
v_32250:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32251;
v_32252:
    goto v_32246;
v_32247:
    goto v_32248;
v_32249:
    goto v_32250;
v_32251:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    goto v_32137;
v_32136:
    v_32970 = stack[-4];
    goto v_32266;
v_32260:
    v_32972 = elt(env, 6); // plus
    goto v_32261;
v_32262:
    v_32971 = v_32970;
    goto v_32263;
v_32264:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32265;
v_32266:
    goto v_32260;
v_32261:
    goto v_32262;
v_32263:
    goto v_32264;
v_32265:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-4] = v_32970;
    goto v_32076;
v_32075:
    v_32970 = stack[-5];
    goto v_32280;
v_32274:
    v_32972 = elt(env, 6); // plus
    goto v_32275;
v_32276:
    v_32971 = v_32970;
    goto v_32277;
v_32278:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32279;
v_32280:
    goto v_32274;
v_32275:
    goto v_32276;
v_32277:
    goto v_32278;
v_32279:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-5] = v_32970;
    goto v_32043;
v_32042:
    goto v_32293;
v_32289:
    v_32970 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32290;
v_32291:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32292;
v_32293:
    goto v_32289;
v_32290:
    goto v_32291;
v_32292:
    fn = elt(env, 19); // evalequal
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32287;
    goto v_32302;
v_32298:
    stack[0] = elt(env, 9); // lie_help
    goto v_32299;
v_32300:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32301;
v_32302:
    goto v_32298;
v_32299:
    goto v_32300;
v_32301:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_32970;
v_32309:
    goto v_32323;
v_32317:
    stack[0] = elt(env, 2); // difference
    goto v_32318;
v_32319:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32320;
v_32321:
    v_32970 = stack[-6];
    goto v_32322;
v_32323:
    goto v_32317;
v_32318:
    goto v_32319;
v_32320:
    goto v_32321;
v_32322:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32314;
    goto v_32308;
v_32314:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32970;
v_32332:
    goto v_32346;
v_32340:
    stack[0] = elt(env, 2); // difference
    goto v_32341;
v_32342:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32343;
v_32344:
    v_32970 = stack[-5];
    goto v_32345;
v_32346:
    goto v_32340;
v_32341:
    goto v_32342;
v_32343:
    goto v_32344;
v_32345:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32337;
    goto v_32331;
v_32337:
    goto v_32361;
v_32357:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_32970;
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_32970;
v_32366:
    goto v_32381;
v_32375:
    stack[0] = elt(env, 2); // difference
    goto v_32376;
v_32377:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32378;
v_32379:
    v_32970 = stack[-4];
    goto v_32380;
v_32381:
    goto v_32375;
v_32376:
    goto v_32377;
v_32378:
    goto v_32379;
v_32380:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32372;
    v_32970 = stack[-3];
    v_32971 = v_32970;
    goto v_32365;
v_32372:
    goto v_32395;
v_32389:
    stack[-2] = elt(env, 6); // plus
    goto v_32390;
v_32391:
    goto v_32405;
v_32399:
    stack[-1] = elt(env, 8); // times
    goto v_32400;
v_32401:
    goto v_32416;
v_32408:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32409;
v_32410:
    v_32972 = elt(env, 4); // lie_p
    goto v_32411;
v_32412:
    v_32971 = elt(env, 5); // lie_q
    goto v_32413;
v_32414:
    v_32970 = stack[-4];
    goto v_32415;
v_32416:
    goto v_32408;
v_32409:
    goto v_32410;
v_32411:
    goto v_32412;
v_32413:
    goto v_32414;
v_32415:
    stack[0] = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32402;
v_32403:
    goto v_32430;
v_32422:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32423;
v_32424:
    v_32972 = stack[-4];
    goto v_32425;
v_32426:
    v_32971 = stack[-6];
    goto v_32427;
v_32428:
    v_32970 = stack[-5];
    goto v_32429;
v_32430:
    goto v_32422;
v_32423:
    goto v_32424;
v_32425:
    goto v_32426;
v_32427:
    goto v_32428;
v_32429:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32404;
v_32405:
    goto v_32399;
v_32400:
    goto v_32401;
v_32402:
    goto v_32403;
v_32404:
    v_32970 = list3(stack[-1], stack[0], v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32392;
v_32393:
    v_32970 = stack[-3];
    goto v_32394;
v_32395:
    goto v_32389;
v_32390:
    goto v_32391;
v_32392:
    goto v_32393;
v_32394:
    v_32970 = list3(stack[-2], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    v_32970 = stack[-4];
    goto v_32446;
v_32440:
    v_32972 = elt(env, 6); // plus
    goto v_32441;
v_32442:
    v_32971 = v_32970;
    goto v_32443;
v_32444:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32445;
v_32446:
    goto v_32440;
v_32441:
    goto v_32442;
v_32443:
    goto v_32444;
v_32445:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-4] = v_32970;
    goto v_32366;
v_32365:
    goto v_32358;
v_32359:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32360;
v_32361:
    goto v_32357;
v_32358:
    goto v_32359;
v_32360:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32355;
    goto v_32456;
v_32452:
    stack[0] = elt(env, 9); // lie_help
    goto v_32453;
v_32454:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32455;
v_32456:
    goto v_32452;
v_32453:
    goto v_32454;
v_32455:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_32465;
v_32461:
    stack[0] = elt(env, 10); // lie_s
    goto v_32462;
v_32463:
    v_32970 = stack[-6];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32464;
v_32465:
    goto v_32461;
v_32462:
    goto v_32463;
v_32464:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = stack[-5];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-9] = v_32970;
    goto v_32479;
v_32473:
    v_32972 = elt(env, 6); // plus
    goto v_32474;
v_32475:
    v_32971 = stack[-8];
    goto v_32476;
v_32477:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32478;
v_32479:
    goto v_32473;
v_32474:
    goto v_32475;
v_32476:
    goto v_32477;
v_32478:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-5] = v_32970;
    stack[-6] = v_32970;
    goto v_32353;
v_32355:
v_32353:
    v_32970 = stack[-5];
    goto v_32493;
v_32487:
    v_32972 = elt(env, 6); // plus
    goto v_32488;
v_32489:
    v_32971 = v_32970;
    goto v_32490;
v_32491:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32492;
v_32493:
    goto v_32487;
v_32488:
    goto v_32489;
v_32490:
    goto v_32491;
v_32492:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-5] = v_32970;
    goto v_32332;
v_32331:
    v_32970 = stack[-6];
    goto v_32507;
v_32501:
    v_32972 = elt(env, 6); // plus
    goto v_32502;
v_32503:
    v_32971 = v_32970;
    goto v_32504;
v_32505:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32506;
v_32507:
    goto v_32501;
v_32502:
    goto v_32503;
v_32504:
    goto v_32505;
v_32506:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-6] = v_32970;
    goto v_32309;
v_32308:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32970;
v_32514:
    goto v_32528;
v_32522:
    stack[0] = elt(env, 2); // difference
    goto v_32523;
v_32524:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32525;
v_32526:
    v_32970 = stack[-1];
    goto v_32527;
v_32528:
    goto v_32522;
v_32523:
    goto v_32524;
v_32525:
    goto v_32526;
v_32527:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32519;
    goto v_32513;
v_32519:
    goto v_32539;
v_32535:
    goto v_32547;
v_32541:
    v_32972 = elt(env, 11); // lientrans
    goto v_32542;
v_32543:
    v_32971 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32544;
v_32545:
    v_32970 = stack[-1];
    goto v_32546;
v_32547:
    goto v_32541;
v_32542:
    goto v_32543;
v_32544:
    goto v_32545;
v_32546:
    stack[0] = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32536;
v_32537:
    goto v_32561;
v_32553:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32554;
v_32555:
    v_32972 = elt(env, 4); // lie_p
    goto v_32556;
v_32557:
    v_32971 = elt(env, 5); // lie_q
    goto v_32558;
v_32559:
    v_32970 = stack[-1];
    goto v_32560;
v_32561:
    goto v_32553;
v_32554:
    goto v_32555;
v_32556:
    goto v_32557;
v_32558:
    goto v_32559;
v_32560:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32538;
v_32539:
    goto v_32535;
v_32536:
    goto v_32537;
v_32538:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = stack[-1];
    goto v_32576;
v_32570:
    v_32972 = elt(env, 6); // plus
    goto v_32571;
v_32572:
    v_32971 = v_32970;
    goto v_32573;
v_32574:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32575;
v_32576:
    goto v_32570;
v_32571:
    goto v_32572;
v_32573:
    goto v_32574;
v_32575:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_32514;
v_32513:
    goto v_32589;
v_32585:
    v_32970 = elt(env, 9); // lie_help
    fn = elt(env, 14); // aeval
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32586;
v_32587:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32588;
v_32589:
    goto v_32585;
v_32586:
    goto v_32587;
v_32588:
    fn = elt(env, 19); // evalequal
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32583;
    goto v_32598;
v_32594:
    goto v_32606;
v_32600:
    v_32972 = elt(env, 11); // lientrans
    goto v_32601;
v_32602:
    v_32971 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32603;
v_32604:
    v_32970 = elt(env, 4); // lie_p
    goto v_32605;
v_32606:
    goto v_32600;
v_32601:
    goto v_32602;
v_32603:
    goto v_32604;
v_32605:
    stack[-1] = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32595;
v_32596:
    goto v_32615;
v_32611:
    goto v_32623;
v_32617:
    v_32972 = elt(env, 11); // lientrans
    goto v_32618;
v_32619:
    v_32971 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_32620;
v_32621:
    v_32970 = elt(env, 5); // lie_q
    goto v_32622;
v_32623:
    goto v_32617;
v_32618:
    goto v_32619;
v_32620:
    goto v_32621;
v_32622:
    stack[0] = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32612;
v_32613:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32614;
v_32615:
    goto v_32611;
v_32612:
    goto v_32613;
v_32614:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_32597;
v_32598:
    goto v_32594;
v_32595:
    goto v_32596;
v_32597:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[-1], v_32970);
    env = stack[-10];
    goto v_32634;
v_32630:
    stack[0] = elt(env, 12); // lie_kk!*
    goto v_32631;
v_32632:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32633;
v_32634:
    goto v_32630;
v_32631:
    goto v_32632;
v_32633:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32970;
v_32641:
    goto v_32655;
v_32649:
    stack[0] = elt(env, 2); // difference
    goto v_32650;
v_32651:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32652;
v_32653:
    v_32970 = stack[-1];
    goto v_32654;
v_32655:
    goto v_32649;
v_32650:
    goto v_32651;
v_32652:
    goto v_32653;
v_32654:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32646;
    goto v_32640;
v_32646:
    goto v_32671;
v_32667:
    goto v_32682;
v_32674:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32675;
v_32676:
    v_32972 = elt(env, 4); // lie_p
    goto v_32677;
v_32678:
    v_32971 = elt(env, 5); // lie_q
    goto v_32679;
v_32680:
    v_32970 = stack[-1];
    goto v_32681;
v_32682:
    goto v_32674;
v_32675:
    goto v_32676;
v_32677:
    goto v_32678;
v_32679:
    goto v_32680;
v_32681:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32668;
v_32669:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32670;
v_32671:
    goto v_32667;
v_32668:
    goto v_32669;
v_32670:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32664;
    goto v_32695;
v_32691:
    stack[0] = stack[-1];
    goto v_32692;
v_32693:
    v_32970 = elt(env, 4); // lie_p
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32694;
v_32695:
    goto v_32691;
v_32692:
    goto v_32693;
v_32694:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32664;
    goto v_32705;
v_32701:
    stack[0] = stack[-1];
    goto v_32702;
v_32703:
    v_32970 = elt(env, 5); // lie_q
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32704;
v_32705:
    goto v_32701;
v_32702:
    goto v_32703;
v_32704:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32664;
    goto v_32714;
v_32710:
    stack[0] = elt(env, 13); // lie_tt
    goto v_32711;
v_32712:
    v_32970 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32713;
v_32714:
    goto v_32710;
v_32711:
    goto v_32712;
v_32713:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_32726;
v_32720:
    v_32972 = elt(env, 6); // plus
    goto v_32721;
v_32722:
    v_32971 = stack[-8];
    goto v_32723;
v_32724:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32725;
v_32726:
    goto v_32720;
v_32721:
    goto v_32722;
v_32723:
    goto v_32724;
v_32725:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_32662;
v_32664:
v_32662:
    v_32970 = stack[-1];
    goto v_32740;
v_32734:
    v_32972 = elt(env, 6); // plus
    goto v_32735;
v_32736:
    v_32971 = v_32970;
    goto v_32737;
v_32738:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32739;
v_32740:
    goto v_32734;
v_32735:
    goto v_32736;
v_32737:
    goto v_32738;
v_32739:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_32641;
v_32640:
    goto v_32581;
v_32583:
    goto v_32751;
v_32747:
    goto v_32759;
v_32753:
    v_32972 = elt(env, 11); // lientrans
    goto v_32754;
v_32755:
    v_32971 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32756;
v_32757:
    v_32970 = elt(env, 10); // lie_s
    goto v_32758;
v_32759:
    goto v_32753;
v_32754:
    goto v_32755;
v_32756:
    goto v_32757;
v_32758:
    stack[-7] = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32748;
v_32749:
    goto v_32771;
v_32765:
    stack[-6] = elt(env, 7); // quotient
    goto v_32766;
v_32767:
    goto v_32782;
v_32774:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32775;
v_32776:
    v_32972 = elt(env, 4); // lie_p
    goto v_32777;
v_32778:
    v_32971 = elt(env, 5); // lie_q
    goto v_32779;
v_32780:
    v_32970 = stack[-9];
    goto v_32781;
v_32782:
    goto v_32774;
v_32775:
    goto v_32776;
v_32777:
    goto v_32778;
v_32779:
    goto v_32780;
v_32781:
    stack[-5] = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32768;
v_32769:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_32970;
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_32970;
v_32791:
    goto v_32806;
v_32800:
    stack[0] = elt(env, 2); // difference
    goto v_32801;
v_32802:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32803;
v_32804:
    v_32970 = stack[-4];
    goto v_32805;
v_32806:
    goto v_32800;
v_32801:
    goto v_32802;
v_32803:
    goto v_32804;
v_32805:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32797;
    v_32970 = stack[-3];
    goto v_32790;
v_32797:
    goto v_32820;
v_32814:
    stack[-2] = elt(env, 6); // plus
    goto v_32815;
v_32816:
    goto v_32830;
v_32824:
    stack[-1] = elt(env, 8); // times
    goto v_32825;
v_32826:
    goto v_32841;
v_32833:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32834;
v_32835:
    v_32972 = elt(env, 4); // lie_p
    goto v_32836;
v_32837:
    v_32971 = elt(env, 5); // lie_q
    goto v_32838;
v_32839:
    v_32970 = stack[-4];
    goto v_32840;
v_32841:
    goto v_32833;
v_32834:
    goto v_32835;
v_32836:
    goto v_32837;
v_32838:
    goto v_32839;
v_32840:
    stack[0] = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32827;
v_32828:
    goto v_32855;
v_32847:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32848;
v_32849:
    v_32972 = stack[-4];
    goto v_32850;
v_32851:
    v_32971 = elt(env, 10); // lie_s
    goto v_32852;
v_32853:
    v_32970 = stack[-9];
    goto v_32854;
v_32855:
    goto v_32847;
v_32848:
    goto v_32849;
v_32850:
    goto v_32851;
v_32852:
    goto v_32853;
v_32854:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    goto v_32829;
v_32830:
    goto v_32824;
v_32825:
    goto v_32826;
v_32827:
    goto v_32828;
v_32829:
    v_32970 = list3(stack[-1], stack[0], v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32817;
v_32818:
    v_32970 = stack[-3];
    goto v_32819;
v_32820:
    goto v_32814;
v_32815:
    goto v_32816;
v_32817:
    goto v_32818;
v_32819:
    v_32970 = list3(stack[-2], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-3] = v_32970;
    v_32970 = stack[-4];
    goto v_32871;
v_32865:
    v_32972 = elt(env, 6); // plus
    goto v_32866;
v_32867:
    v_32971 = v_32970;
    goto v_32868;
v_32869:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32870;
v_32871:
    goto v_32865;
v_32866:
    goto v_32867;
v_32868:
    goto v_32869;
v_32870:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-4] = v_32970;
    goto v_32791;
v_32790:
    goto v_32770;
v_32771:
    goto v_32765;
v_32766:
    goto v_32767;
v_32768:
    goto v_32769;
v_32770:
    v_32970 = list3(stack[-6], stack[-5], v_32970);
    env = stack[-10];
    fn = elt(env, 14); // aeval
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32750;
v_32751:
    goto v_32747;
v_32748:
    goto v_32749;
v_32750:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[-7], v_32970);
    env = stack[-10];
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32970;
v_32878:
    goto v_32892;
v_32886:
    stack[0] = elt(env, 2); // difference
    goto v_32887;
v_32888:
    v_32970 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32889;
v_32890:
    v_32970 = stack[-1];
    goto v_32891;
v_32892:
    goto v_32886;
v_32887:
    goto v_32888;
v_32889:
    goto v_32890;
v_32891:
    v_32970 = list3(stack[0], v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32883;
    goto v_32877;
v_32883:
    goto v_32908;
v_32904:
    goto v_32919;
v_32911:
    v_32973 = elt(env, 3); // lie_cc
    goto v_32912;
v_32913:
    v_32972 = elt(env, 4); // lie_p
    goto v_32914;
v_32915:
    v_32971 = elt(env, 5); // lie_q
    goto v_32916;
v_32917:
    v_32970 = stack[-1];
    goto v_32918;
v_32919:
    goto v_32911;
v_32912:
    goto v_32913;
v_32914:
    goto v_32915;
v_32916:
    goto v_32917;
v_32918:
    v_32970 = list4(v_32973, v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32971 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32905;
v_32906:
    v_32970 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32907;
v_32908:
    goto v_32904;
v_32905:
    goto v_32906;
v_32907:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, v_32971, v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32901;
    goto v_32931;
v_32927:
    stack[0] = stack[-1];
    goto v_32928;
v_32929:
    v_32970 = elt(env, 10); // lie_s
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32930;
v_32931:
    goto v_32927;
v_32928:
    goto v_32929;
v_32930:
    fn = elt(env, 18); // evalneq
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    if (v_32970 == nil) goto v_32901;
    goto v_32940;
v_32936:
    stack[0] = elt(env, 13); // lie_tt
    goto v_32937;
v_32938:
    v_32970 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    goto v_32939;
v_32940:
    goto v_32936;
v_32937:
    goto v_32938;
v_32939:
    fn = elt(env, 15); // setk
    v_32970 = (*qfn2(fn))(fn, stack[0], v_32970);
    env = stack[-10];
    goto v_32952;
v_32946:
    v_32972 = elt(env, 6); // plus
    goto v_32947;
v_32948:
    v_32971 = stack[-8];
    goto v_32949;
v_32950:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32951;
v_32952:
    goto v_32946;
v_32947:
    goto v_32948;
v_32949:
    goto v_32950;
v_32951:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_32899;
v_32901:
v_32899:
    v_32970 = stack[-1];
    goto v_32966;
v_32960:
    v_32972 = elt(env, 6); // plus
    goto v_32961;
v_32962:
    v_32971 = v_32970;
    goto v_32963;
v_32964:
    v_32970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32965;
v_32966:
    goto v_32960;
v_32961:
    goto v_32962;
v_32963:
    goto v_32964;
v_32965:
    v_32970 = list3(v_32972, v_32971, v_32970);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_32970 = (*qfn1(fn))(fn, v_32970);
    env = stack[-10];
    stack[-1] = v_32970;
    goto v_32878;
v_32877:
    goto v_32581;
v_32581:
    goto v_32285;
v_32287:
v_32285:
    goto v_32028;
v_32030:
v_32028:
    v_32970 = nil;
    return onevalue(v_32970);
}



// Code for dpmat_gbtag

static LispObject CC_dpmat_gbtag(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31831, v_31832;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31831 = v_31821;
// end of prologue
    goto v_31828;
v_31824:
    v_31832 = v_31831;
    goto v_31825;
v_31826:
    v_31831 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_31827;
v_31828:
    goto v_31824;
v_31825:
    goto v_31826;
v_31827:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_31832, v_31831);
    }
}



// Code for st_extract_symcells1

static LispObject CC_st_extract_symcells1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31990, v_31991, v_31992;
    LispObject fn;
    LispObject v_31823, v_31822, v_31821;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_extract_symcells1");
    va_start(aa, nargs);
    v_31821 = va_arg(aa, LispObject);
    v_31822 = va_arg(aa, LispObject);
    v_31823 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31823,v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31821,v_31822,v_31823);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_31823;
    stack[-5] = v_31822;
    stack[0] = v_31821;
// end of prologue
    v_31990 = stack[0];
    v_31990 = qcdr(v_31990);
    v_31990 = qcar(v_31990);
    fn = elt(env, 2); // listp
    v_31990 = (*qfn1(fn))(fn, v_31990);
    env = stack[-7];
    if (v_31990 == nil) goto v_31831;
    else goto v_31832;
v_31831:
    goto v_31844;
v_31838:
    stack[-1] = stack[-4];
    goto v_31839;
v_31840:
    goto v_31851;
v_31847:
    v_31991 = stack[0];
    goto v_31848;
v_31849:
    v_31990 = stack[-5];
    goto v_31850;
v_31851:
    goto v_31847;
v_31848:
    goto v_31849;
v_31850:
    stack[0] = cons(v_31991, v_31990);
    env = stack[-7];
    goto v_31841;
v_31842:
    v_31990 = stack[-4];
    v_31990 = add1(v_31990);
    goto v_31843;
v_31844:
    goto v_31838;
v_31839:
    goto v_31840;
v_31841:
    goto v_31842;
v_31843:
    {
        LispObject v_32000 = stack[-1];
        LispObject v_32001 = stack[0];
        return list3(v_32000, v_32001, v_31990);
    }
v_31832:
    goto v_31863;
v_31859:
    v_31990 = stack[0];
    stack[-6] = qcar(v_31990);
    goto v_31860;
v_31861:
    v_31990 = stack[0];
    v_31990 = qcdr(v_31990);
    stack[-3] = v_31990;
    v_31990 = stack[-3];
    if (v_31990 == nil) goto v_31876;
    else goto v_31877;
v_31876:
    v_31990 = nil;
    goto v_31870;
v_31877:
    v_31990 = stack[-3];
    v_31990 = qcar(v_31990);
    goto v_31891;
v_31885:
    v_31992 = v_31990;
    goto v_31886;
v_31887:
    v_31991 = stack[-5];
    goto v_31888;
v_31889:
    v_31990 = stack[-4];
    goto v_31890;
v_31891:
    goto v_31885;
v_31886:
    goto v_31887;
v_31888:
    goto v_31889;
v_31890:
    v_31990 = CC_st_extract_symcells1(elt(env, 0), 3, v_31992, v_31991, v_31990);
    env = stack[-7];
    v_31991 = v_31990;
    v_31991 = qcdr(v_31991);
    v_31991 = qcar(v_31991);
    stack[-5] = v_31991;
    v_31991 = v_31990;
    v_31991 = qcdr(v_31991);
    v_31991 = qcdr(v_31991);
    v_31991 = qcar(v_31991);
    stack[-4] = v_31991;
    v_31991 = v_31990;
    v_31991 = qcar(v_31991);
    if (is_number(v_31991)) goto v_31904;
    else goto v_31905;
v_31904:
    goto v_31913;
v_31909:
    v_31991 = elt(env, 1); // !*
    goto v_31910;
v_31911:
    v_31990 = qcar(v_31990);
    goto v_31912;
v_31913:
    goto v_31909;
v_31910:
    goto v_31911;
v_31912:
    v_31990 = list2(v_31991, v_31990);
    env = stack[-7];
    goto v_31903;
v_31905:
    v_31990 = qcar(v_31990);
    goto v_31903;
    v_31990 = nil;
v_31903:
    v_31990 = ncons(v_31990);
    env = stack[-7];
    stack[-1] = v_31990;
    stack[-2] = v_31990;
v_31871:
    v_31990 = stack[-3];
    v_31990 = qcdr(v_31990);
    stack[-3] = v_31990;
    v_31990 = stack[-3];
    if (v_31990 == nil) goto v_31925;
    else goto v_31926;
v_31925:
    v_31990 = stack[-2];
    goto v_31870;
v_31926:
    goto v_31934;
v_31930:
    stack[0] = stack[-1];
    goto v_31931;
v_31932:
    v_31990 = stack[-3];
    v_31990 = qcar(v_31990);
    goto v_31947;
v_31941:
    v_31992 = v_31990;
    goto v_31942;
v_31943:
    v_31991 = stack[-5];
    goto v_31944;
v_31945:
    v_31990 = stack[-4];
    goto v_31946;
v_31947:
    goto v_31941;
v_31942:
    goto v_31943;
v_31944:
    goto v_31945;
v_31946:
    v_31990 = CC_st_extract_symcells1(elt(env, 0), 3, v_31992, v_31991, v_31990);
    env = stack[-7];
    v_31991 = v_31990;
    v_31991 = qcdr(v_31991);
    v_31991 = qcar(v_31991);
    stack[-5] = v_31991;
    v_31991 = v_31990;
    v_31991 = qcdr(v_31991);
    v_31991 = qcdr(v_31991);
    v_31991 = qcar(v_31991);
    stack[-4] = v_31991;
    v_31991 = v_31990;
    v_31991 = qcar(v_31991);
    if (is_number(v_31991)) goto v_31960;
    else goto v_31961;
v_31960:
    goto v_31969;
v_31965:
    v_31991 = elt(env, 1); // !*
    goto v_31966;
v_31967:
    v_31990 = qcar(v_31990);
    goto v_31968;
v_31969:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    v_31990 = list2(v_31991, v_31990);
    env = stack[-7];
    goto v_31959;
v_31961:
    v_31990 = qcar(v_31990);
    goto v_31959;
    v_31990 = nil;
v_31959:
    v_31990 = ncons(v_31990);
    env = stack[-7];
    goto v_31933;
v_31934:
    goto v_31930;
v_31931:
    goto v_31932;
v_31933:
    v_31990 = Lrplacd(nil, stack[0], v_31990);
    env = stack[-7];
    v_31990 = stack[-1];
    v_31990 = qcdr(v_31990);
    stack[-1] = v_31990;
    goto v_31871;
v_31870:
    goto v_31862;
v_31863:
    goto v_31859;
v_31860:
    goto v_31861;
v_31862:
    v_31990 = cons(stack[-6], v_31990);
    goto v_31986;
v_31980:
    v_31992 = v_31990;
    goto v_31981;
v_31982:
    v_31991 = stack[-5];
    goto v_31983;
v_31984:
    v_31990 = stack[-4];
    goto v_31985;
v_31986:
    goto v_31980;
v_31981:
    goto v_31982;
v_31983:
    goto v_31984;
v_31985:
    return list3(v_31992, v_31991, v_31990);
    v_31990 = nil;
    return onevalue(v_31990);
}



// Code for addcoeffs

static LispObject CC_addcoeffs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31947, v_31948, v_31949, v_31950;
    LispObject fn;
    LispObject v_31824, v_31823, v_31822, v_31821;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "addcoeffs");
    va_start(aa, nargs);
    v_31821 = va_arg(aa, LispObject);
    v_31822 = va_arg(aa, LispObject);
    v_31823 = va_arg(aa, LispObject);
    v_31824 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_31824,v_31823,v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_31821,v_31822,v_31823,v_31824);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_31824;
    stack[-2] = v_31823;
    stack[-3] = v_31822;
    stack[-4] = v_31821;
// end of prologue
    goto v_31835;
v_31831:
    v_31948 = nil;
    goto v_31832;
v_31833:
    v_31947 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31834;
v_31835:
    goto v_31831;
v_31832:
    goto v_31833;
v_31834:
    v_31947 = cons(v_31948, v_31947);
    env = stack[-6];
    stack[0] = v_31947;
    goto v_31843;
v_31839:
    v_31947 = stack[-4];
    fn = elt(env, 1); // smallest!-increment
    stack[-5] = (*qfn1(fn))(fn, v_31947);
    env = stack[-6];
    goto v_31840;
v_31841:
    v_31947 = stack[-3];
    fn = elt(env, 1); // smallest!-increment
    v_31947 = (*qfn1(fn))(fn, v_31947);
    env = stack[-6];
    goto v_31842;
v_31843:
    goto v_31839;
v_31840:
    goto v_31841;
v_31842:
    fn = elt(env, 2); // common!-increment
    v_31947 = (*qfn2(fn))(fn, stack[-5], v_31947);
    env = stack[-6];
    goto v_31861;
v_31853:
    v_31950 = stack[-2];
    goto v_31854;
v_31855:
    v_31949 = stack[-1];
    goto v_31856;
v_31857:
    v_31948 = stack[-3];
    v_31948 = qcar(v_31948);
    v_31948 = qcar(v_31948);
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
    goto v_31853;
v_31854:
    goto v_31855;
v_31856:
    goto v_31857;
v_31858:
    goto v_31859;
v_31860:
    fn = elt(env, 3); // makecoeffpairs
    v_31947 = (*qfnn(fn))(fn, 4, v_31950, v_31949, v_31948, v_31947);
    env = stack[-6];
    stack[-5] = v_31947;
v_31851:
    v_31947 = stack[-5];
    if (v_31947 == nil) goto v_31870;
    else goto v_31871;
v_31870:
    goto v_31850;
v_31871:
    v_31947 = stack[-5];
    v_31947 = qcar(v_31947);
    stack[-2] = v_31947;
    goto v_31882;
v_31878:
    stack[-1] = stack[0];
    goto v_31879;
v_31880:
    goto v_31889;
v_31885:
    goto v_31894;
v_31890:
    v_31947 = stack[-2];
    v_31948 = qcar(v_31947);
    goto v_31891;
v_31892:
    v_31947 = stack[-4];
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    v_31947 = Lassoc(nil, v_31948, v_31947);
    v_31948 = v_31947;
    v_31947 = v_31948;
    if (v_31947 == nil) goto v_31902;
    else goto v_31903;
v_31902:
    goto v_31910;
v_31906:
    v_31948 = nil;
    goto v_31907;
v_31908:
    v_31947 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31909;
v_31910:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    v_31947 = cons(v_31948, v_31947);
    env = stack[-6];
    stack[0] = v_31947;
    goto v_31901;
v_31903:
    v_31947 = v_31948;
    v_31947 = qcdr(v_31947);
    stack[0] = v_31947;
    goto v_31901;
    stack[0] = nil;
v_31901:
    goto v_31886;
v_31887:
    goto v_31921;
v_31917:
    v_31947 = stack[-2];
    v_31948 = qcdr(v_31947);
    goto v_31918;
v_31919:
    v_31947 = stack[-3];
    goto v_31920;
v_31921:
    goto v_31917;
v_31918:
    goto v_31919;
v_31920:
    v_31947 = Lassoc(nil, v_31948, v_31947);
    v_31948 = v_31947;
    v_31947 = v_31948;
    if (v_31947 == nil) goto v_31929;
    else goto v_31930;
v_31929:
    goto v_31937;
v_31933:
    v_31948 = nil;
    goto v_31934;
v_31935:
    v_31947 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31936;
v_31937:
    goto v_31933;
v_31934:
    goto v_31935;
v_31936:
    v_31947 = cons(v_31948, v_31947);
    env = stack[-6];
    goto v_31928;
v_31930:
    v_31947 = v_31948;
    v_31947 = qcdr(v_31947);
    goto v_31928;
    v_31947 = nil;
v_31928:
    goto v_31888;
v_31889:
    goto v_31885;
v_31886:
    goto v_31887;
v_31888:
    fn = elt(env, 4); // multsq
    v_31947 = (*qfn2(fn))(fn, stack[0], v_31947);
    env = stack[-6];
    goto v_31881;
v_31882:
    goto v_31878;
v_31879:
    goto v_31880;
v_31881:
    fn = elt(env, 5); // addsq
    v_31947 = (*qfn2(fn))(fn, stack[-1], v_31947);
    env = stack[-6];
    stack[0] = v_31947;
    v_31947 = stack[-5];
    v_31947 = qcdr(v_31947);
    stack[-5] = v_31947;
    goto v_31851;
v_31850:
    v_31947 = stack[0];
    return onevalue(v_31947);
}



// Code for qqe_simpat

static LispObject CC_qqe_simpat(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31824;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31824 = v_31821;
// end of prologue
    return onevalue(v_31824);
}



// Code for bc_minus!?

static LispObject CC_bc_minusW(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31844, v_31845;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31845 = v_31821;
// end of prologue
    v_31844 = v_31845;
    v_31844 = qcar(v_31844);
    v_31844 = integerp(v_31844);
    if (v_31844 == nil) goto v_31826;
    goto v_31835;
v_31831:
    v_31844 = v_31845;
    v_31845 = qcar(v_31844);
    goto v_31832;
v_31833:
    v_31844 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31834;
v_31835:
    goto v_31831;
v_31832:
    goto v_31833;
v_31834:
        return Llessp(nil, v_31845, v_31844);
v_31826:
    v_31844 = v_31845;
    v_31844 = qcar(v_31844);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_31844);
    }
    v_31844 = nil;
    return onevalue(v_31844);
}



// Code for crprimp

static LispObject CC_crprimp(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31865, v_31866, v_31867;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31867 = v_31821;
// end of prologue
    goto v_31831;
v_31827:
    v_31866 = v_31867;
    goto v_31828;
v_31829:
    v_31865 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31830;
v_31831:
    goto v_31827;
v_31828:
    goto v_31829;
v_31830:
    if (v_31866 == v_31865) goto v_31825;
    else goto v_31826;
v_31825:
    v_31865 = elt(env, 1); // i
    goto v_31824;
v_31826:
    goto v_31841;
v_31837:
    v_31866 = v_31867;
    goto v_31838;
v_31839:
    v_31865 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31840;
v_31841:
    goto v_31837;
v_31838:
    goto v_31839;
v_31840:
    if (v_31866 == v_31865) goto v_31835;
    else goto v_31836;
v_31835:
    goto v_31849;
v_31845:
    v_31865 = elt(env, 2); // minus
    goto v_31846;
v_31847:
    v_31866 = elt(env, 1); // i
    goto v_31848;
v_31849:
    goto v_31845;
v_31846:
    goto v_31847;
v_31848:
    return list2(v_31865, v_31866);
v_31836:
    goto v_31861;
v_31855:
    v_31865 = elt(env, 3); // times
    goto v_31856;
v_31857:
    v_31866 = v_31867;
    goto v_31858;
v_31859:
    v_31867 = elt(env, 1); // i
    goto v_31860;
v_31861:
    goto v_31855;
v_31856:
    goto v_31857;
v_31858:
    goto v_31859;
v_31860:
    return list3(v_31865, v_31866, v_31867);
    v_31865 = nil;
v_31824:
    return onevalue(v_31865);
}



// Code for remove_critical_pairs

static LispObject CC_remove_critical_pairs(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31838, v_31839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_31822;
    v_31838 = v_31821;
// end of prologue
    v_31839 = v_31838;
    if (v_31839 == nil) goto v_31827;
    goto v_31834;
v_31830:
    v_31839 = stack[0];
    goto v_31831;
v_31832:
    goto v_31833;
v_31834:
    goto v_31830;
v_31831:
    goto v_31832;
v_31833:
    fn = elt(env, 1); // remove_items
    v_31838 = (*qfn2(fn))(fn, v_31839, v_31838);
    goto v_31825;
v_31827:
v_31825:
    v_31838 = stack[0];
    return onevalue(v_31838);
}



// Code for acmemb

static LispObject CC_acmemb(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31850, v_31851;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31822;
    stack[-1] = v_31821;
// end of prologue
v_31826:
    v_31850 = stack[0];
    if (v_31850 == nil) goto v_31829;
    else goto v_31830;
v_31829:
    v_31850 = nil;
    goto v_31825;
v_31830:
    goto v_31840;
v_31836:
    v_31851 = stack[-1];
    goto v_31837;
v_31838:
    v_31850 = stack[0];
    v_31850 = qcar(v_31850);
    goto v_31839;
v_31840:
    goto v_31836;
v_31837:
    goto v_31838;
v_31839:
    fn = elt(env, 1); // aceq
    v_31850 = (*qfn2(fn))(fn, v_31851, v_31850);
    env = stack[-2];
    if (v_31850 == nil) goto v_31834;
    v_31850 = stack[0];
    v_31850 = qcar(v_31850);
    goto v_31825;
v_31834:
    v_31850 = stack[0];
    v_31850 = qcdr(v_31850);
    stack[0] = v_31850;
    goto v_31826;
    v_31850 = nil;
v_31825:
    return onevalue(v_31850);
}



// Code for physopplus

static LispObject CC_physopplus(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31892, v_31893;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    v_31892 = stack[0];
    v_31892 = qcar(v_31892);
    fn = elt(env, 2); // physopsim!*
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    stack[-3] = v_31892;
    v_31892 = stack[0];
    v_31892 = qcdr(v_31892);
    stack[0] = v_31892;
v_31835:
    v_31892 = stack[0];
    if (v_31892 == nil) goto v_31840;
    else goto v_31841;
v_31840:
    goto v_31834;
v_31841:
    v_31892 = stack[0];
    v_31892 = qcar(v_31892);
    fn = elt(env, 2); // physopsim!*
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    stack[-2] = v_31892;
    v_31892 = stack[-3];
    fn = elt(env, 3); // getphystype
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    stack[-1] = v_31892;
    v_31892 = stack[-2];
    fn = elt(env, 3); // getphystype
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    v_31893 = v_31892;
    if (v_31893 == nil) goto v_31856;
    v_31893 = stack[-1];
    if (v_31893 == nil) goto v_31856;
    goto v_31867;
v_31863:
    v_31893 = stack[-1];
    goto v_31864;
v_31865:
    goto v_31866;
v_31867:
    goto v_31863;
v_31864:
    goto v_31865;
v_31866:
    if (v_31893 == v_31892) goto v_31856;
    goto v_31875;
v_31871:
    v_31893 = elt(env, 0); // physopplus
    goto v_31872;
v_31873:
    v_31892 = elt(env, 1); // "type mismatch in plus "
    goto v_31874;
v_31875:
    goto v_31871;
v_31872:
    goto v_31873;
v_31874:
    fn = elt(env, 4); // rederr2
    v_31892 = (*qfn2(fn))(fn, v_31893, v_31892);
    env = stack[-4];
    goto v_31854;
v_31856:
v_31854:
    goto v_31884;
v_31880:
    v_31892 = stack[-3];
    fn = elt(env, 5); // physop2sq
    stack[-1] = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    goto v_31881;
v_31882:
    v_31892 = stack[-2];
    fn = elt(env, 5); // physop2sq
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    goto v_31883;
v_31884:
    goto v_31880;
v_31881:
    goto v_31882;
v_31883:
    fn = elt(env, 6); // addsq
    v_31892 = (*qfn2(fn))(fn, stack[-1], v_31892);
    env = stack[-4];
    fn = elt(env, 7); // mk!*sq
    v_31892 = (*qfn1(fn))(fn, v_31892);
    env = stack[-4];
    stack[-3] = v_31892;
    v_31892 = stack[0];
    v_31892 = qcdr(v_31892);
    stack[0] = v_31892;
    goto v_31835;
v_31834:
    v_31892 = stack[-3];
    return onevalue(v_31892);
}



// Code for bassoc

static LispObject CC_bassoc(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31850, v_31851;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31822;
    stack[-1] = v_31821;
// end of prologue
v_31826:
    v_31850 = stack[0];
    if (v_31850 == nil) goto v_31829;
    else goto v_31830;
v_31829:
    v_31850 = nil;
    goto v_31825;
v_31830:
    goto v_31840;
v_31836:
    v_31851 = stack[-1];
    goto v_31837;
v_31838:
    v_31850 = stack[0];
    v_31850 = qcar(v_31850);
    v_31850 = qcar(v_31850);
    goto v_31839;
v_31840:
    goto v_31836;
v_31837:
    goto v_31838;
v_31839:
    fn = elt(env, 1); // th_match
    v_31850 = (*qfn2(fn))(fn, v_31851, v_31850);
    env = stack[-2];
    if (v_31850 == nil) goto v_31834;
    v_31850 = stack[0];
    goto v_31825;
v_31834:
    v_31850 = stack[0];
    v_31850 = qcdr(v_31850);
    stack[0] = v_31850;
    goto v_31826;
    v_31850 = nil;
v_31825:
    return onevalue(v_31850);
}



// Code for !*sq2fourier

static LispObject CC_Hsq2fourier(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31892, v_31893, v_31894;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    v_31892 = stack[0];
    v_31892 = qcar(v_31892);
    if (v_31892 == nil) goto v_31825;
    else goto v_31826;
v_31825:
    v_31892 = nil;
    goto v_31824;
v_31826:
    v_31892 = (LispObject)48+TAG_FIXNUM; // 3
    v_31892 = Lmkvect(nil, v_31892);
    env = stack[-3];
    stack[-2] = v_31892;
    goto v_31843;
v_31837:
    v_31894 = stack[-2];
    goto v_31838;
v_31839:
    v_31893 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31840;
v_31841:
    v_31892 = stack[0];
    goto v_31842;
v_31843:
    goto v_31837;
v_31838:
    goto v_31839;
v_31840:
    goto v_31841;
v_31842:
    *(LispObject *)((char *)v_31894 + (CELL-TAG_VECTOR) + (((intptr_t)v_31893-TAG_FIXNUM)/(16/CELL))) = v_31892;
    goto v_31853;
v_31847:
    v_31894 = stack[-2];
    goto v_31848;
v_31849:
    v_31893 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31850;
v_31851:
    v_31892 = elt(env, 1); // cos
    goto v_31852;
v_31853:
    goto v_31847;
v_31848:
    goto v_31849;
v_31850:
    goto v_31851;
v_31852:
    *(LispObject *)((char *)v_31894 + (CELL-TAG_VECTOR) + (((intptr_t)v_31893-TAG_FIXNUM)/(16/CELL))) = v_31892;
    goto v_31863;
v_31857:
    stack[-1] = stack[-2];
    goto v_31858;
v_31859:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31860;
v_31861:
    fn = elt(env, 4); // fs!:make!-nullangle
    v_31892 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_31862;
v_31863:
    goto v_31857;
v_31858:
    goto v_31859;
v_31860:
    goto v_31861;
v_31862:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_31892;
    goto v_31873;
v_31867:
    v_31894 = stack[-2];
    goto v_31868;
v_31869:
    v_31893 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31870;
v_31871:
    v_31892 = nil;
    goto v_31872;
v_31873:
    goto v_31867;
v_31868:
    goto v_31869;
v_31870:
    goto v_31871;
v_31872:
    *(LispObject *)((char *)v_31894 + (CELL-TAG_VECTOR) + (((intptr_t)v_31893-TAG_FIXNUM)/(16/CELL))) = v_31892;
    goto v_31882;
v_31878:
    goto v_31888;
v_31884:
    v_31893 = elt(env, 2); // fourier
    goto v_31885;
v_31886:
    v_31892 = elt(env, 3); // tag
    goto v_31887;
v_31888:
    goto v_31884;
v_31885:
    goto v_31886;
v_31887:
    v_31893 = get(v_31893, v_31892);
    goto v_31879;
v_31880:
    v_31892 = stack[-2];
    goto v_31881;
v_31882:
    goto v_31878;
v_31879:
    goto v_31880;
v_31881:
    return cons(v_31893, v_31892);
    goto v_31824;
    v_31892 = nil;
v_31824:
    return onevalue(v_31892);
}



// Code for all_index_lst

static LispObject CC_all_index_lst(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31889, v_31890;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31821;
// end of prologue
    stack[-2] = nil;
v_31827:
    v_31889 = stack[-1];
    if (v_31889 == nil) goto v_31832;
    else goto v_31833;
v_31832:
    goto v_31828;
v_31833:
    goto v_31840;
v_31836:
    v_31889 = stack[-1];
    v_31889 = qcar(v_31889);
    v_31889 = qcdr(v_31889);
    stack[0] = v_31889;
    v_31889 = stack[0];
    v_31889 = qcar(v_31889);
    fn = elt(env, 2); // listp
    v_31889 = (*qfn1(fn))(fn, v_31889);
    env = stack[-3];
    if (v_31889 == nil) goto v_31848;
    goto v_31858;
v_31854:
    v_31889 = stack[0];
    v_31889 = qcar(v_31889);
    v_31890 = qcar(v_31889);
    goto v_31855;
v_31856:
    v_31889 = elt(env, 1); // list
    goto v_31857;
v_31858:
    goto v_31854;
v_31855:
    goto v_31856;
v_31857:
    if (v_31890 == v_31889) goto v_31853;
    else goto v_31848;
v_31853:
    v_31889 = stack[0];
    v_31889 = qcdr(v_31889);
    v_31890 = v_31889;
    goto v_31846;
v_31848:
    v_31889 = stack[0];
    v_31890 = v_31889;
    goto v_31846;
    v_31890 = nil;
v_31846:
    goto v_31837;
v_31838:
    v_31889 = stack[-2];
    goto v_31839;
v_31840:
    goto v_31836;
v_31837:
    goto v_31838;
v_31839:
    v_31889 = cons(v_31890, v_31889);
    env = stack[-3];
    stack[-2] = v_31889;
    v_31889 = stack[-1];
    v_31889 = qcdr(v_31889);
    stack[-1] = v_31889;
    goto v_31827;
v_31828:
    v_31889 = nil;
    v_31890 = v_31889;
v_31829:
    v_31889 = stack[-2];
    if (v_31889 == nil) goto v_31874;
    else goto v_31875;
v_31874:
    v_31889 = v_31890;
    goto v_31826;
v_31875:
    goto v_31883;
v_31879:
    v_31889 = stack[-2];
    v_31889 = qcar(v_31889);
    goto v_31880;
v_31881:
    goto v_31882;
v_31883:
    goto v_31879;
v_31880:
    goto v_31881;
v_31882:
    v_31889 = Lappend(nil, v_31889, v_31890);
    env = stack[-3];
    v_31890 = v_31889;
    v_31889 = stack[-2];
    v_31889 = qcdr(v_31889);
    stack[-2] = v_31889;
    goto v_31829;
v_31826:
    return onevalue(v_31889);
}



// Code for sc_create

static LispObject CC_sc_create(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31868, v_31869;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31821;
// end of prologue
    stack[-2] = nil;
    v_31868 = stack[-1];
    stack[0] = v_31868;
v_31831:
    v_31868 = stack[0];
    v_31868 = sub1(v_31868);
    env = stack[-3];
    v_31868 = Lminusp(nil, v_31868);
    env = stack[-3];
    if (v_31868 == nil) goto v_31836;
    goto v_31830;
v_31836:
    goto v_31846;
v_31842:
    v_31869 = stack[0];
    goto v_31843;
v_31844:
    v_31868 = stack[-2];
    goto v_31845;
v_31846:
    goto v_31842;
v_31843:
    goto v_31844;
v_31845:
    v_31868 = cons(v_31869, v_31868);
    env = stack[-3];
    stack[-2] = v_31868;
    v_31868 = stack[0];
    v_31868 = sub1(v_31868);
    env = stack[-3];
    stack[0] = v_31868;
    goto v_31831;
v_31830:
    goto v_31856;
v_31852:
    goto v_31862;
v_31858:
    v_31869 = stack[-2];
    goto v_31859;
v_31860:
    v_31868 = elt(env, 1); // symbolic
    goto v_31861;
v_31862:
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
    fn = elt(env, 2); // list2vect!*
    stack[0] = (*qfn2(fn))(fn, v_31869, v_31868);
    env = stack[-3];
    goto v_31853;
v_31854:
    v_31868 = stack[-1];
    v_31868 = sub1(v_31868);
    env = stack[-3];
    v_31868 = Lmkvect(nil, v_31868);
    goto v_31855;
v_31856:
    goto v_31852;
v_31853:
    goto v_31854;
v_31855:
    {
        LispObject v_31873 = stack[0];
        return cons(v_31873, v_31868);
    }
    return onevalue(v_31868);
}



// Code for ofsf_exploitknowl

static LispObject CC_ofsf_exploitknowl(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_32188, v_32189, v_32190, v_32191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    v_32188 = v_31821;
// end of prologue
    stack[-11] = nil;
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-1] = v_32188;
v_31840:
    v_32188 = stack[-1];
    if (v_32188 == nil) goto v_31844;
    else goto v_31845;
v_31844:
    goto v_31839;
v_31845:
    v_32188 = stack[-1];
    v_32188 = qcar(v_32188);
    stack[0] = v_32188;
    v_32188 = stack[0];
    v_32188 = qcar(v_32188);
    fn = elt(env, 8); // sfto_varp
    v_32188 = (*qfn1(fn))(fn, v_32188);
    env = stack[-12];
    stack[-4] = v_32188;
    if (v_32188 == nil) goto v_31854;
    v_32188 = stack[0];
    v_32188 = qcdr(v_32188);
    stack[0] = v_32188;
v_31861:
    v_32188 = stack[0];
    if (v_32188 == nil) goto v_31866;
    else goto v_31867;
v_31866:
    goto v_31860;
v_31867:
    v_32188 = stack[0];
    v_32188 = qcar(v_32188);
    v_32188 = qcdr(v_32188);
    v_32189 = v_32188;
    v_32188 = v_32189;
    v_32188 = qcar(v_32188);
    stack[-3] = v_32188;
    v_32188 = v_32189;
    v_32188 = qcdr(v_32188);
    v_32189 = v_32188;
    v_32188 = v_32189;
    fn = elt(env, 9); // negsq
    v_32188 = (*qfn1(fn))(fn, v_32188);
    env = stack[-12];
    v_32189 = v_32188;
    v_32188 = v_32189;
    v_32188 = qcar(v_32188);
    if (v_32188 == nil) goto v_31887;
    else goto v_31886;
v_31887:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
v_31886:
    stack[-2] = v_32188;
    goto v_31899;
v_31895:
    v_32190 = stack[-3];
    goto v_31896;
v_31897:
    v_32188 = elt(env, 1); // equal
    goto v_31898;
v_31899:
    goto v_31895;
v_31896:
    goto v_31897;
v_31898:
    if (v_32190 == v_32188) goto v_31893;
    else goto v_31894;
v_31893:
    v_32188 = qvalue(elt(env, 2)); // !*rlsippsubst
    if (v_32188 == nil) goto v_31905;
    goto v_31914;
v_31908:
    v_32190 = stack[-4];
    goto v_31909;
v_31910:
    goto v_31911;
v_31912:
    v_32188 = stack[-11];
    goto v_31913;
v_31914:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    goto v_31912;
v_31913:
    v_32188 = acons(v_32190, v_32189, v_32188);
    env = stack[-12];
    stack[-11] = v_32188;
    goto v_31903;
v_31905:
    goto v_31929;
v_31925:
    v_32189 = stack[-2];
    goto v_31926;
v_31927:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31928;
v_31929:
    goto v_31925;
v_31926:
    goto v_31927;
v_31928:
    v_32188 = (LispObject)greaterp2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_31923;
    goto v_31937;
v_31933:
    v_32189 = stack[-4];
    goto v_31934;
v_31935:
    v_32188 = stack[-9];
    goto v_31936;
v_31937:
    goto v_31933;
v_31934:
    goto v_31935;
v_31936:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-9] = v_32188;
    goto v_31921;
v_31923:
    goto v_31947;
v_31943:
    v_32189 = stack[-2];
    goto v_31944;
v_31945:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31946;
v_31947:
    goto v_31943;
v_31944:
    goto v_31945;
v_31946:
    v_32188 = (LispObject)lessp2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_31941;
    goto v_31955;
v_31951:
    v_32189 = stack[-4];
    goto v_31952;
v_31953:
    v_32188 = stack[-8];
    goto v_31954;
v_31955:
    goto v_31951;
v_31952:
    goto v_31953;
v_31954:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-8] = v_32188;
    goto v_31921;
v_31941:
    goto v_31965;
v_31961:
    v_32189 = stack[-2];
    goto v_31962;
v_31963:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31964;
v_31965:
    goto v_31961;
v_31962:
    goto v_31963;
v_31964:
    v_32188 = Leqn(nil, v_32189, v_32188);
    env = stack[-12];
    if (v_32188 == nil) goto v_31959;
    goto v_31973;
v_31969:
    v_32189 = stack[-4];
    goto v_31970;
v_31971:
    v_32188 = stack[-10];
    goto v_31972;
v_31973:
    goto v_31969;
v_31970:
    goto v_31971;
v_31972:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-10] = v_32188;
    goto v_31921;
v_31959:
v_31921:
    goto v_31903;
v_31903:
    goto v_31892;
v_31894:
    goto v_31982;
v_31978:
    v_32189 = stack[-3];
    goto v_31979;
v_31980:
    v_32188 = elt(env, 3); // greaterp
    goto v_31981;
v_31982:
    goto v_31978;
v_31979:
    goto v_31980;
v_31981:
    if (v_32189 == v_32188) goto v_31976;
    else goto v_31977;
v_31976:
    goto v_31994;
v_31990:
    v_32189 = stack[-2];
    goto v_31991;
v_31992:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31993;
v_31994:
    goto v_31990;
v_31991:
    goto v_31992;
v_31993:
    v_32188 = (LispObject)geq2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_31988;
    goto v_32002;
v_31998:
    v_32189 = stack[-4];
    goto v_31999;
v_32000:
    v_32188 = stack[-9];
    goto v_32001;
v_32002:
    goto v_31998;
v_31999:
    goto v_32000;
v_32001:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-9] = v_32188;
    goto v_31986;
v_31988:
v_31986:
    goto v_31892;
v_31977:
    goto v_32011;
v_32007:
    v_32189 = stack[-3];
    goto v_32008;
v_32009:
    v_32188 = elt(env, 4); // geq
    goto v_32010;
v_32011:
    goto v_32007;
v_32008:
    goto v_32009;
v_32010:
    if (v_32189 == v_32188) goto v_32005;
    else goto v_32006;
v_32005:
    goto v_32023;
v_32019:
    v_32189 = stack[-2];
    goto v_32020;
v_32021:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32022;
v_32023:
    goto v_32019;
v_32020:
    goto v_32021;
v_32022:
    v_32188 = (LispObject)greaterp2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_32017;
    goto v_32031;
v_32027:
    v_32189 = stack[-4];
    goto v_32028;
v_32029:
    v_32188 = stack[-9];
    goto v_32030;
v_32031:
    goto v_32027;
v_32028:
    goto v_32029;
v_32030:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-9] = v_32188;
    goto v_32015;
v_32017:
    goto v_32041;
v_32037:
    v_32189 = stack[-2];
    goto v_32038;
v_32039:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32040;
v_32041:
    goto v_32037;
v_32038:
    goto v_32039;
v_32040:
    v_32188 = Leqn(nil, v_32189, v_32188);
    env = stack[-12];
    if (v_32188 == nil) goto v_32035;
    goto v_32049;
v_32045:
    v_32189 = stack[-4];
    goto v_32046;
v_32047:
    v_32188 = stack[-7];
    goto v_32048;
v_32049:
    goto v_32045;
v_32046:
    goto v_32047;
v_32048:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-7] = v_32188;
    goto v_32015;
v_32035:
v_32015:
    goto v_31892;
v_32006:
    goto v_32058;
v_32054:
    v_32189 = stack[-3];
    goto v_32055;
v_32056:
    v_32188 = elt(env, 5); // lessp
    goto v_32057;
v_32058:
    goto v_32054;
v_32055:
    goto v_32056;
v_32057:
    if (v_32189 == v_32188) goto v_32052;
    else goto v_32053;
v_32052:
    goto v_32070;
v_32066:
    v_32189 = stack[-2];
    goto v_32067;
v_32068:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32069;
v_32070:
    goto v_32066;
v_32067:
    goto v_32068;
v_32069:
    v_32188 = (LispObject)lesseq2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_32064;
    goto v_32078;
v_32074:
    v_32189 = stack[-4];
    goto v_32075;
v_32076:
    v_32188 = stack[-8];
    goto v_32077;
v_32078:
    goto v_32074;
v_32075:
    goto v_32076;
v_32077:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-8] = v_32188;
    goto v_32062;
v_32064:
v_32062:
    goto v_31892;
v_32053:
    goto v_32087;
v_32083:
    v_32189 = stack[-3];
    goto v_32084;
v_32085:
    v_32188 = elt(env, 6); // leq
    goto v_32086;
v_32087:
    goto v_32083;
v_32084:
    goto v_32085;
v_32086:
    if (v_32189 == v_32188) goto v_32081;
    else goto v_32082;
v_32081:
    goto v_32099;
v_32095:
    v_32189 = stack[-2];
    goto v_32096;
v_32097:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32098;
v_32099:
    goto v_32095;
v_32096:
    goto v_32097;
v_32098:
    v_32188 = (LispObject)lessp2(v_32189, v_32188);
    v_32188 = v_32188 ? lisp_true : nil;
    env = stack[-12];
    if (v_32188 == nil) goto v_32093;
    goto v_32107;
v_32103:
    v_32189 = stack[-4];
    goto v_32104;
v_32105:
    v_32188 = stack[-8];
    goto v_32106;
v_32107:
    goto v_32103;
v_32104:
    goto v_32105;
v_32106:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-8] = v_32188;
    goto v_32091;
v_32093:
    goto v_32117;
v_32113:
    v_32189 = stack[-2];
    goto v_32114;
v_32115:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32116;
v_32117:
    goto v_32113;
v_32114:
    goto v_32115;
v_32116:
    v_32188 = Leqn(nil, v_32189, v_32188);
    env = stack[-12];
    if (v_32188 == nil) goto v_32111;
    goto v_32125;
v_32121:
    v_32189 = stack[-4];
    goto v_32122;
v_32123:
    v_32188 = stack[-6];
    goto v_32124;
v_32125:
    goto v_32121;
v_32122:
    goto v_32123;
v_32124:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-6] = v_32188;
    goto v_32091;
v_32111:
v_32091:
    goto v_31892;
v_32082:
    goto v_32134;
v_32130:
    v_32189 = stack[-3];
    goto v_32131;
v_32132:
    v_32188 = elt(env, 7); // neq
    goto v_32133;
v_32134:
    goto v_32130;
v_32131:
    goto v_32132;
v_32133:
    if (v_32189 == v_32188) goto v_32128;
    else goto v_32129;
v_32128:
    goto v_32146;
v_32142:
    v_32189 = stack[-2];
    goto v_32143;
v_32144:
    v_32188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32145;
v_32146:
    goto v_32142;
v_32143:
    goto v_32144;
v_32145:
    v_32188 = Leqn(nil, v_32189, v_32188);
    env = stack[-12];
    if (v_32188 == nil) goto v_32140;
    goto v_32154;
v_32150:
    v_32189 = stack[-4];
    goto v_32151;
v_32152:
    v_32188 = stack[-5];
    goto v_32153;
v_32154:
    goto v_32150;
v_32151:
    goto v_32152;
v_32153:
    fn = elt(env, 10); // lto_insertq
    v_32188 = (*qfn2(fn))(fn, v_32189, v_32188);
    env = stack[-12];
    stack[-5] = v_32188;
    goto v_32138;
v_32140:
v_32138:
    goto v_31892;
v_32129:
v_31892:
    v_32188 = stack[0];
    v_32188 = qcdr(v_32188);
    stack[0] = v_32188;
    goto v_31861;
v_31860:
    goto v_31852;
v_31854:
v_31852:
    v_32188 = stack[-1];
    v_32188 = qcdr(v_32188);
    stack[-1] = v_32188;
    goto v_31840;
v_31839:
    goto v_32170;
v_32162:
    stack[0] = stack[-11];
    goto v_32163;
v_32164:
    stack[-1] = stack[-10];
    goto v_32165;
v_32166:
    stack[-2] = stack[-9];
    goto v_32167;
v_32168:
    goto v_32183;
v_32175:
    v_32191 = stack[-8];
    goto v_32176;
v_32177:
    v_32190 = stack[-7];
    goto v_32178;
v_32179:
    v_32189 = stack[-6];
    goto v_32180;
v_32181:
    v_32188 = stack[-5];
    goto v_32182;
v_32183:
    goto v_32175;
v_32176:
    goto v_32177;
v_32178:
    goto v_32179;
v_32180:
    goto v_32181;
v_32182:
    v_32188 = list4(v_32191, v_32190, v_32189, v_32188);
    goto v_32169;
v_32170:
    goto v_32162;
v_32163:
    goto v_32164;
v_32165:
    goto v_32166;
v_32167:
    goto v_32168;
v_32169:
    {
        LispObject v_32204 = stack[0];
        LispObject v_32205 = stack[-1];
        LispObject v_32206 = stack[-2];
        return list3star(v_32204, v_32205, v_32206, v_32188);
    }
    return onevalue(v_32188);
}



// Code for uterm

static LispObject CC_uterm(LispObject env,
                         LispObject v_31822, LispObject v_31823)
{
    env = qenv(env);
    LispObject v_31911, v_31912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31823,v_31822);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31822,v_31823);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31911 = v_31823;
    stack[-1] = v_31822;
// end of prologue
// Binding rhs!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_31911; // rhs!*
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    if (v_31911 == nil) goto v_31831;
    else goto v_31832;
v_31831:
    v_31911 = nil;
    goto v_31830;
v_31832:
    goto v_31846;
v_31842:
    v_31912 = stack[-1];
    goto v_31843;
v_31844:
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    v_31911 = qcar(v_31911);
    v_31911 = qcar(v_31911);
    goto v_31845;
v_31846:
    goto v_31842;
v_31843:
    goto v_31844;
v_31845:
    fn = elt(env, 2); // addinds
    v_31911 = (*qfn2(fn))(fn, v_31912, v_31911);
    env = stack[-3];
    stack[0] = v_31911;
    goto v_31856;
v_31852:
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    v_31911 = qcar(v_31911);
    v_31911 = qcdr(v_31911);
    v_31912 = qcar(v_31911);
    goto v_31853;
v_31854:
    v_31911 = stack[-1];
    goto v_31855;
v_31856:
    goto v_31852;
v_31853:
    goto v_31854;
v_31855:
    fn = elt(env, 3); // evaluatecoeffts
    v_31911 = (*qfn2(fn))(fn, v_31912, v_31911);
    env = stack[-3];
    v_31912 = v_31911;
    if (v_31912 == nil) goto v_31864;
    else goto v_31865;
v_31864:
    goto v_31872;
v_31868:
    v_31912 = stack[-1];
    goto v_31869;
v_31870:
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    v_31911 = qcdr(v_31911);
    goto v_31871;
v_31872:
    goto v_31868;
v_31869:
    goto v_31870;
v_31871:
    v_31911 = CC_uterm(elt(env, 0), v_31912, v_31911);
    goto v_31840;
v_31865:
    goto v_31881;
v_31877:
    v_31912 = v_31911;
    goto v_31878;
v_31879:
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    v_31911 = qcar(v_31911);
    v_31911 = qcdr(v_31911);
    v_31911 = qcdr(v_31911);
    goto v_31880;
v_31881:
    goto v_31877;
v_31878:
    goto v_31879;
v_31880:
    v_31911 = cons(v_31912, v_31911);
    env = stack[-3];
    goto v_31892;
v_31888:
    goto v_31899;
v_31895:
    v_31912 = stack[0];
    goto v_31896;
v_31897:
    goto v_31898;
v_31899:
    goto v_31895;
v_31896:
    goto v_31897;
v_31898:
    v_31911 = cons(v_31912, v_31911);
    env = stack[-3];
    stack[0] = ncons(v_31911);
    env = stack[-3];
    goto v_31889;
v_31890:
    goto v_31907;
v_31903:
    v_31912 = stack[-1];
    goto v_31904;
v_31905:
    v_31911 = qvalue(elt(env, 1)); // rhs!*
    v_31911 = qcdr(v_31911);
    goto v_31906;
v_31907:
    goto v_31903;
v_31904:
    goto v_31905;
v_31906:
    v_31911 = CC_uterm(elt(env, 0), v_31912, v_31911);
    env = stack[-3];
    goto v_31891;
v_31892:
    goto v_31888;
v_31889:
    goto v_31890;
v_31891:
    fn = elt(env, 4); // plusdf
    v_31911 = (*qfn2(fn))(fn, stack[0], v_31911);
v_31840:
    goto v_31830;
    v_31911 = nil;
v_31830:
    ;}  // end of a binding scope
    return onevalue(v_31911);
}



// Code for change!+sq!+to!+int

static LispObject CC_changeLsqLtoLint(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31847, v_31848, v_31849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31847 = v_31821;
// end of prologue
    fn = elt(env, 2); // prepsq
    v_31847 = (*qfn1(fn))(fn, v_31847);
    env = stack[0];
    fn = elt(env, 3); // simp!*
    v_31847 = (*qfn1(fn))(fn, v_31847);
    env = stack[0];
    v_31849 = v_31847;
    goto v_31837;
v_31833:
    v_31847 = v_31849;
    v_31848 = qcdr(v_31847);
    goto v_31834;
v_31835:
    v_31847 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31836;
v_31837:
    goto v_31833;
v_31834:
    goto v_31835;
v_31836:
    if (v_31848 == v_31847) goto v_31831;
    else goto v_31832;
v_31831:
    v_31847 = v_31849;
    v_31847 = qcar(v_31847);
    goto v_31825;
v_31832:
    v_31847 = elt(env, 1); // "no integer in change!+sq!+to!+int"
    fn = elt(env, 4); // rederr
    v_31847 = (*qfn1(fn))(fn, v_31847);
    goto v_31830;
v_31830:
    v_31847 = nil;
v_31825:
    return onevalue(v_31847);
}



// Code for ofsf_factsf

static LispObject CC_ofsf_factsf(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31877, v_31878;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    stack[-1] = nil;
v_31827:
    goto v_31839;
v_31835:
    v_31878 = stack[0];
    goto v_31836;
v_31837:
    v_31877 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31838;
v_31839:
    goto v_31835;
v_31836:
    goto v_31837;
v_31838:
    v_31877 = (LispObject)lesseq2(v_31878, v_31877);
    v_31877 = v_31877 ? lisp_true : nil;
    env = stack[-2];
    if (v_31877 == nil) goto v_31833;
    goto v_31828;
v_31833:
    goto v_31847;
v_31843:
    v_31878 = stack[0];
    goto v_31844;
v_31845:
    v_31877 = stack[-1];
    goto v_31846;
v_31847:
    goto v_31843;
v_31844:
    goto v_31845;
v_31846:
    v_31877 = cons(v_31878, v_31877);
    env = stack[-2];
    stack[-1] = v_31877;
    goto v_31855;
v_31851:
    goto v_31852;
v_31853:
    v_31877 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // negf
    v_31877 = (*qfn1(fn))(fn, v_31877);
    env = stack[-2];
    goto v_31854;
v_31855:
    goto v_31851;
v_31852:
    goto v_31853;
v_31854:
    fn = elt(env, 2); // addf
    v_31877 = (*qfn2(fn))(fn, stack[0], v_31877);
    env = stack[-2];
    stack[0] = v_31877;
    goto v_31827;
v_31828:
    v_31877 = (LispObject)16+TAG_FIXNUM; // 1
    v_31878 = v_31877;
v_31829:
    v_31877 = stack[-1];
    if (v_31877 == nil) goto v_31862;
    else goto v_31863;
v_31862:
    v_31877 = v_31878;
    goto v_31826;
v_31863:
    goto v_31871;
v_31867:
    v_31877 = stack[-1];
    v_31877 = qcar(v_31877);
    goto v_31868;
v_31869:
    goto v_31870;
v_31871:
    goto v_31867;
v_31868:
    goto v_31869;
v_31870:
    fn = elt(env, 3); // multf
    v_31877 = (*qfn2(fn))(fn, v_31877, v_31878);
    env = stack[-2];
    v_31878 = v_31877;
    v_31877 = stack[-1];
    v_31877 = qcdr(v_31877);
    stack[-1] = v_31877;
    goto v_31829;
v_31826:
    return onevalue(v_31877);
}



// Code for operator

static LispObject CC_operator(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31841 = v_31821;
// end of prologue
    stack[0] = v_31841;
v_31826:
    v_31841 = stack[0];
    if (v_31841 == nil) goto v_31830;
    else goto v_31831;
v_31830:
    v_31841 = nil;
    goto v_31825;
v_31831:
    v_31841 = stack[0];
    v_31841 = qcar(v_31841);
    fn = elt(env, 1); // mkop
    v_31841 = (*qfn1(fn))(fn, v_31841);
    env = stack[-1];
    v_31841 = stack[0];
    v_31841 = qcdr(v_31841);
    stack[0] = v_31841;
    goto v_31826;
v_31825:
    return onevalue(v_31841);
}



// Code for look_for_rational

static LispObject CC_look_for_rational(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31980, v_31981, v_31982;
    LispObject fn;
    LispObject v_31823, v_31822, v_31821;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_rational");
    va_start(aa, nargs);
    v_31821 = va_arg(aa, LispObject);
    v_31822 = va_arg(aa, LispObject);
    v_31823 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31823,v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31821,v_31822,v_31823);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31823;
    stack[-1] = v_31822;
    stack[-2] = v_31821;
// end of prologue
    goto v_31834;
v_31830:
    v_31981 = stack[-1];
    goto v_31831;
v_31832:
    v_31980 = elt(env, 1); // look_for_exponential
    goto v_31833;
v_31834:
    goto v_31830;
v_31831:
    goto v_31832;
v_31833:
    v_31980 = get(v_31981, v_31980);
    env = stack[-3];
    if (v_31980 == nil) goto v_31828;
    v_31980 = nil;
    goto v_31826;
v_31828:
    goto v_31848;
v_31844:
    v_31980 = stack[0];
    v_31981 = qcar(v_31980);
    goto v_31845;
v_31846:
    v_31980 = elt(env, 2); // sqrt
    goto v_31847;
v_31848:
    goto v_31844;
v_31845:
    goto v_31846;
v_31847:
    if (v_31981 == v_31980) goto v_31842;
    else goto v_31843;
v_31842:
    goto v_31856;
v_31852:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31981 = qcar(v_31980);
    goto v_31853;
v_31854:
    v_31980 = stack[-1];
    goto v_31855;
v_31856:
    goto v_31852;
v_31853:
    goto v_31854;
v_31855:
    v_31980 = (equal(v_31981, v_31980) ? lisp_true : nil);
    goto v_31841;
v_31843:
    v_31980 = nil;
    goto v_31841;
    v_31980 = nil;
v_31841:
    if (v_31980 == nil) goto v_31839;
    goto v_31872;
v_31866:
    v_31982 = stack[-2];
    goto v_31867;
v_31868:
    v_31981 = stack[-1];
    goto v_31869;
v_31870:
    v_31980 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31871;
v_31872:
    goto v_31866;
v_31867:
    goto v_31868;
v_31869:
    goto v_31870;
v_31871:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_31982, v_31981, v_31980);
    }
v_31839:
    goto v_31886;
v_31882:
    v_31980 = stack[0];
    v_31981 = qcar(v_31980);
    goto v_31883;
v_31884:
    v_31980 = elt(env, 3); // expt
    goto v_31885;
v_31886:
    goto v_31882;
v_31883:
    goto v_31884;
v_31885:
    if (v_31981 == v_31980) goto v_31880;
    else goto v_31881;
v_31880:
    goto v_31898;
v_31894:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31981 = qcar(v_31980);
    goto v_31895;
v_31896:
    v_31980 = stack[-1];
    goto v_31897;
v_31898:
    goto v_31894;
v_31895:
    goto v_31896;
v_31897:
    if (equal(v_31981, v_31980)) goto v_31892;
    else goto v_31893;
v_31892:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    fn = elt(env, 6); // listp
    v_31980 = (*qfn1(fn))(fn, v_31980);
    env = stack[-3];
    if (v_31980 == nil) goto v_31905;
    else goto v_31906;
v_31905:
    v_31980 = nil;
    goto v_31904;
v_31906:
    goto v_31923;
v_31919:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    v_31981 = qcar(v_31980);
    goto v_31920;
v_31921:
    v_31980 = elt(env, 4); // quotient
    goto v_31922;
v_31923:
    goto v_31919;
v_31920:
    goto v_31921;
v_31922:
    if (v_31981 == v_31980) goto v_31917;
    else goto v_31918;
v_31917:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    if (is_number(v_31980)) goto v_31933;
    v_31980 = nil;
    goto v_31931;
v_31933:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    v_31980 = (is_number(v_31980) ? lisp_true : nil);
    goto v_31931;
    v_31980 = nil;
v_31931:
    goto v_31916;
v_31918:
    v_31980 = nil;
    goto v_31916;
    v_31980 = nil;
v_31916:
    goto v_31904;
    v_31980 = nil;
v_31904:
    goto v_31891;
v_31893:
    v_31980 = nil;
    goto v_31891;
    v_31980 = nil;
v_31891:
    goto v_31879;
v_31881:
    v_31980 = nil;
    goto v_31879;
    v_31980 = nil;
v_31879:
    if (v_31980 == nil) goto v_31877;
    goto v_31967;
v_31961:
    v_31982 = stack[-2];
    goto v_31962;
v_31963:
    v_31981 = stack[-1];
    goto v_31964;
v_31965:
    v_31980 = stack[0];
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcdr(v_31980);
    v_31980 = qcar(v_31980);
    goto v_31966;
v_31967:
    goto v_31961;
v_31962:
    goto v_31963;
v_31964:
    goto v_31965;
v_31966:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_31982, v_31981, v_31980);
    }
v_31877:
    v_31980 = nil;
    goto v_31826;
    v_31980 = nil;
v_31826:
    return onevalue(v_31980);
}



// Code for vevzero!?1

static LispObject CC_vevzeroW1(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31875, v_31876, v_31877;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31876 = v_31821;
// end of prologue
v_31820:
    v_31875 = v_31876;
    if (v_31875 == nil) goto v_31825;
    else goto v_31826;
v_31825:
    v_31875 = lisp_true;
    goto v_31824;
v_31826:
    goto v_31839;
v_31835:
    v_31875 = v_31876;
    v_31877 = qcar(v_31875);
    goto v_31836;
v_31837:
    v_31875 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31838;
v_31839:
    goto v_31835;
v_31836:
    goto v_31837;
v_31838:
    if (v_31877 == v_31875) goto v_31833;
    else goto v_31834;
v_31833:
    v_31875 = v_31876;
    v_31875 = qcdr(v_31875);
    if (v_31875 == nil) goto v_31845;
    else goto v_31846;
v_31845:
    v_31875 = lisp_true;
    goto v_31844;
v_31846:
    goto v_31860;
v_31856:
    v_31875 = v_31876;
    v_31875 = qcdr(v_31875);
    v_31877 = qcar(v_31875);
    goto v_31857;
v_31858:
    v_31875 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31859;
v_31860:
    goto v_31856;
v_31857:
    goto v_31858;
v_31859:
    if (v_31877 == v_31875) goto v_31854;
    else goto v_31855;
v_31854:
    v_31875 = v_31876;
    v_31875 = qcdr(v_31875);
    v_31875 = qcdr(v_31875);
    v_31876 = v_31875;
    goto v_31820;
v_31855:
    v_31875 = nil;
    goto v_31853;
    v_31875 = nil;
v_31853:
    goto v_31844;
    v_31875 = nil;
v_31844:
    goto v_31832;
v_31834:
    v_31875 = nil;
    goto v_31832;
    v_31875 = nil;
v_31832:
    goto v_31824;
    v_31875 = nil;
v_31824:
    return onevalue(v_31875);
}



// Code for xpndwedge

static LispObject CC_xpndwedge(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31869, v_31870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    stack[-1] = nil;
v_31827:
    v_31869 = stack[0];
    v_31869 = qcdr(v_31869);
    if (v_31869 == nil) goto v_31832;
    else goto v_31833;
v_31832:
    goto v_31828;
v_31833:
    goto v_31841;
v_31837:
    v_31869 = stack[0];
    v_31869 = qcar(v_31869);
    fn = elt(env, 1); // partitop
    v_31870 = (*qfn1(fn))(fn, v_31869);
    env = stack[-2];
    goto v_31838;
v_31839:
    v_31869 = stack[-1];
    goto v_31840;
v_31841:
    goto v_31837;
v_31838:
    goto v_31839;
v_31840:
    v_31869 = cons(v_31870, v_31869);
    env = stack[-2];
    stack[-1] = v_31869;
    v_31869 = stack[0];
    v_31869 = qcdr(v_31869);
    stack[0] = v_31869;
    goto v_31827;
v_31828:
    v_31869 = stack[0];
    v_31869 = qcar(v_31869);
    fn = elt(env, 1); // partitop
    v_31869 = (*qfn1(fn))(fn, v_31869);
    env = stack[-2];
    fn = elt(env, 2); // mkunarywedge
    v_31869 = (*qfn1(fn))(fn, v_31869);
    env = stack[-2];
    v_31870 = v_31869;
v_31829:
    v_31869 = stack[-1];
    if (v_31869 == nil) goto v_31854;
    else goto v_31855;
v_31854:
    v_31869 = v_31870;
    goto v_31826;
v_31855:
    goto v_31863;
v_31859:
    v_31869 = stack[-1];
    v_31869 = qcar(v_31869);
    goto v_31860;
v_31861:
    goto v_31862;
v_31863:
    goto v_31859;
v_31860:
    goto v_31861;
v_31862:
    fn = elt(env, 3); // wedgepf2
    v_31869 = (*qfn2(fn))(fn, v_31869, v_31870);
    env = stack[-2];
    v_31870 = v_31869;
    v_31869 = stack[-1];
    v_31869 = qcdr(v_31869);
    stack[-1] = v_31869;
    goto v_31829;
v_31826:
    return onevalue(v_31869);
}



// Code for unshift

static LispObject CC_unshift(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31885, v_31886, v_31887, v_31888;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31888 = v_31821;
// end of prologue
    v_31885 = qvalue(elt(env, 1)); // !*xo
    v_31887 = v_31885;
    v_31885 = v_31887;
    v_31885 = qcar(v_31885);
    if (!consp(v_31885)) goto v_31832;
    goto v_31843;
v_31839:
    v_31885 = v_31887;
    v_31885 = qcar(v_31885);
    v_31885 = qcdr(v_31885);
    v_31886 = qcar(v_31885);
    goto v_31840;
v_31841:
    v_31885 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31842;
v_31843:
    goto v_31839;
v_31840:
    goto v_31841;
v_31842:
    if (v_31886 == v_31885) goto v_31837;
    else goto v_31838;
v_31837:
    goto v_31853;
v_31849:
    v_31885 = v_31887;
    v_31885 = qcdr(v_31885);
    v_31885 = qcdr(v_31885);
    v_31886 = qcar(v_31885);
    goto v_31850;
v_31851:
    v_31885 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31852;
v_31853:
    goto v_31849;
v_31850:
    goto v_31851;
v_31852:
    v_31885 = (v_31886 == v_31885 ? lisp_true : nil);
    goto v_31836;
v_31838:
    v_31885 = nil;
    goto v_31836;
    v_31885 = nil;
v_31836:
    goto v_31830;
v_31832:
    goto v_31869;
v_31865:
    v_31886 = v_31887;
    goto v_31866;
v_31867:
    v_31885 = elt(env, 2); // (0.0 . 0.0)
    goto v_31868;
v_31869:
    goto v_31865;
v_31866:
    goto v_31867;
v_31868:
    v_31885 = (equal(v_31886, v_31885) ? lisp_true : nil);
    goto v_31830;
    v_31885 = nil;
v_31830:
    if (v_31885 == nil) goto v_31826;
    v_31885 = v_31888;
    goto v_31824;
v_31826:
    goto v_31882;
v_31878:
    v_31886 = v_31888;
    goto v_31879;
v_31880:
    v_31885 = qvalue(elt(env, 1)); // !*xo
    goto v_31881;
v_31882:
    goto v_31878;
v_31879:
    goto v_31880;
v_31881:
    fn = elt(env, 3); // gfplus
    v_31885 = (*qfn2(fn))(fn, v_31886, v_31885);
    env = stack[0];
    {
        fn = elt(env, 4); // gfadjust
        return (*qfn1(fn))(fn, v_31885);
    }
    v_31885 = nil;
v_31824:
    return onevalue(v_31885);
}



// Code for r2speclist

static LispObject CC_r2speclist(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31883, v_31884, v_31885;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_31884 = v_31821;
// end of prologue
    goto v_31832;
v_31828:
    v_31885 = v_31884;
    goto v_31829;
v_31830:
    v_31883 = elt(env, 1); // plus
    goto v_31831;
v_31832:
    goto v_31828;
v_31829:
    goto v_31830;
v_31831:
    if (!consp(v_31885)) goto v_31826;
    v_31885 = qcar(v_31885);
    if (v_31885 == v_31883) goto v_31825;
    else goto v_31826;
v_31825:
    v_31883 = v_31884;
    v_31883 = qcdr(v_31883);
    goto v_31824;
v_31826:
    v_31883 = v_31884;
    v_31883 = ncons(v_31883);
    env = stack[-4];
    goto v_31824;
    v_31883 = nil;
v_31824:
    v_31884 = v_31883;
    v_31883 = v_31884;
    stack[-3] = v_31883;
    v_31883 = stack[-3];
    if (v_31883 == nil) goto v_31850;
    else goto v_31851;
v_31850:
    v_31883 = nil;
    goto v_31845;
v_31851:
    v_31883 = stack[-3];
    v_31883 = qcar(v_31883);
    fn = elt(env, 2); // r2speclist1
    v_31883 = (*qfn1(fn))(fn, v_31883);
    env = stack[-4];
    v_31883 = ncons(v_31883);
    env = stack[-4];
    stack[-1] = v_31883;
    stack[-2] = v_31883;
v_31846:
    v_31883 = stack[-3];
    v_31883 = qcdr(v_31883);
    stack[-3] = v_31883;
    v_31883 = stack[-3];
    if (v_31883 == nil) goto v_31864;
    else goto v_31865;
v_31864:
    v_31883 = stack[-2];
    goto v_31845;
v_31865:
    goto v_31873;
v_31869:
    stack[0] = stack[-1];
    goto v_31870;
v_31871:
    v_31883 = stack[-3];
    v_31883 = qcar(v_31883);
    fn = elt(env, 2); // r2speclist1
    v_31883 = (*qfn1(fn))(fn, v_31883);
    env = stack[-4];
    v_31883 = ncons(v_31883);
    env = stack[-4];
    goto v_31872;
v_31873:
    goto v_31869;
v_31870:
    goto v_31871;
v_31872:
    v_31883 = Lrplacd(nil, stack[0], v_31883);
    env = stack[-4];
    v_31883 = stack[-1];
    v_31883 = qcdr(v_31883);
    stack[-1] = v_31883;
    goto v_31846;
v_31845:
    return onevalue(v_31883);
}



// Code for noncom1

static LispObject CC_noncom1(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31833, v_31834;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31834 = v_31821;
// end of prologue
    v_31833 = lisp_true;
    qvalue(elt(env, 1)) = v_31833; // !*ncmp
    goto v_31829;
v_31825:
    v_31833 = v_31834;
    v_31833 = ncons(v_31833);
    env = stack[0];
    goto v_31826;
v_31827:
    v_31834 = elt(env, 2); // noncom
    goto v_31828;
v_31829:
    goto v_31825;
v_31826:
    goto v_31827;
v_31828:
        return Lflag(nil, v_31833, v_31834);
}



// Code for rationalizef

static LispObject CC_rationalizef(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_32046, v_32047;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_31821;
// end of prologue
    v_32046 = stack[-2];
    fn = elt(env, 8); // kernels
    v_32046 = (*qfn1(fn))(fn, v_32046);
    env = stack[-4];
    stack[0] = v_32046;
    stack[-3] = v_32046;
v_31828:
    v_32046 = stack[-3];
    if (v_32046 == nil) goto v_31833;
    else goto v_31834;
v_31833:
    v_32046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31827;
v_31834:
    v_32046 = stack[-3];
    v_32046 = qcar(v_32046);
    stack[-1] = v_32046;
    goto v_31852;
v_31848:
    v_32047 = stack[-1];
    goto v_31849;
v_31850:
    v_32046 = elt(env, 1); // expt
    goto v_31851;
v_31852:
    goto v_31848;
v_31849:
    goto v_31850;
v_31851:
    if (!consp(v_32047)) goto v_31846;
    v_32047 = qcar(v_32047);
    if (v_32047 == v_32046) goto v_31845;
    else goto v_31846;
v_31845:
    goto v_31864;
v_31860:
    v_32046 = stack[-1];
    v_32046 = qcdr(v_32046);
    v_32046 = qcdr(v_32046);
    v_32047 = qcar(v_32046);
    goto v_31861;
v_31862:
    v_32046 = elt(env, 2); // quotient
    goto v_31863;
v_31864:
    goto v_31860;
v_31861:
    goto v_31862;
v_31863:
    if (!consp(v_32047)) goto v_31858;
    v_32047 = qcar(v_32047);
    if (v_32047 == v_32046) goto v_31857;
    else goto v_31858;
v_31857:
    goto v_31875;
v_31871:
    v_32047 = stack[0];
    goto v_31872;
v_31873:
    v_32046 = stack[-1];
    v_32046 = qcdr(v_32046);
    goto v_31874;
v_31875:
    goto v_31871;
v_31872:
    goto v_31873;
v_31874:
    fn = elt(env, 9); // lowertowerp
    v_32046 = (*qfn2(fn))(fn, v_32047, v_32046);
    env = stack[-4];
    goto v_31856;
v_31858:
    v_32046 = nil;
    goto v_31856;
    v_32046 = nil;
v_31856:
    goto v_31844;
v_31846:
    v_32046 = nil;
    goto v_31844;
    v_32046 = nil;
v_31844:
    if (v_32046 == nil) goto v_31842;
    goto v_31840;
v_31842:
    goto v_31896;
v_31892:
    v_32047 = stack[-1];
    goto v_31893;
v_31894:
    v_32046 = elt(env, 3); // i
    goto v_31895;
v_31896:
    goto v_31892;
v_31893:
    goto v_31894;
v_31895:
    if (v_32047 == v_32046) goto v_31890;
    else goto v_31891;
v_31890:
    v_32046 = lisp_true;
    goto v_31889;
v_31891:
    goto v_31915;
v_31911:
    v_32047 = stack[-1];
    goto v_31912;
v_31913:
    v_32046 = elt(env, 1); // expt
    goto v_31914;
v_31915:
    goto v_31911;
v_31912:
    goto v_31913;
v_31914:
    if (!consp(v_32047)) goto v_31909;
    v_32047 = qcar(v_32047);
    if (v_32047 == v_32046) goto v_31908;
    else goto v_31909;
v_31908:
    goto v_31922;
v_31918:
    v_32046 = stack[-1];
    v_32046 = qcdr(v_32046);
    v_32046 = qcdr(v_32046);
    v_32047 = qcar(v_32046);
    goto v_31919;
v_31920:
    v_32046 = elt(env, 4); // (quotient 1 2)
    goto v_31921;
v_31922:
    goto v_31918;
v_31919:
    goto v_31920;
v_31921:
    v_32046 = (equal(v_32047, v_32046) ? lisp_true : nil);
    goto v_31907;
v_31909:
    v_32046 = nil;
    goto v_31907;
    v_32046 = nil;
v_31907:
    if (v_32046 == nil) goto v_31905;
    v_32046 = lisp_true;
    goto v_31903;
v_31905:
    goto v_31940;
v_31936:
    v_32047 = stack[-1];
    goto v_31937;
v_31938:
    v_32046 = elt(env, 5); // sqrt
    goto v_31939;
v_31940:
    goto v_31936;
v_31937:
    goto v_31938;
v_31939:
    v_32046 = Leqcar(nil, v_32047, v_32046);
    env = stack[-4];
    goto v_31903;
    v_32046 = nil;
v_31903:
    goto v_31889;
    v_32046 = nil;
v_31889:
    if (v_32046 == nil) goto v_31887;
    goto v_31948;
v_31944:
    goto v_31954;
v_31950:
    v_32047 = stack[-2];
    goto v_31951;
v_31952:
    v_32046 = stack[-1];
    goto v_31953;
v_31954:
    goto v_31950;
v_31951:
    goto v_31952;
v_31953:
    fn = elt(env, 10); // mkmain
    v_32047 = (*qfn2(fn))(fn, v_32047, v_32046);
    env = stack[-4];
    goto v_31945;
v_31946:
    v_32046 = stack[-1];
    goto v_31947;
v_31948:
    goto v_31944;
v_31945:
    goto v_31946;
v_31947:
    {
        fn = elt(env, 11); // conjquadratic
        return (*qfn2(fn))(fn, v_32047, v_32046);
    }
v_31887:
    goto v_31969;
v_31965:
    v_32047 = stack[-1];
    goto v_31966;
v_31967:
    v_32046 = elt(env, 1); // expt
    goto v_31968;
v_31969:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    if (!consp(v_32047)) goto v_31963;
    v_32047 = qcar(v_32047);
    if (v_32047 == v_32046) goto v_31962;
    else goto v_31963;
v_31962:
    goto v_31976;
v_31972:
    v_32046 = stack[-1];
    v_32046 = qcdr(v_32046);
    v_32046 = qcdr(v_32046);
    v_32047 = qcar(v_32046);
    goto v_31973;
v_31974:
    v_32046 = elt(env, 6); // (quotient 1 3)
    goto v_31975;
v_31976:
    goto v_31972;
v_31973:
    goto v_31974;
v_31975:
    v_32046 = (equal(v_32047, v_32046) ? lisp_true : nil);
    goto v_31961;
v_31963:
    v_32046 = nil;
    goto v_31961;
    v_32046 = nil;
v_31961:
    if (v_32046 == nil) goto v_31959;
    goto v_31991;
v_31987:
    goto v_31997;
v_31993:
    v_32047 = stack[-2];
    goto v_31994;
v_31995:
    v_32046 = stack[-1];
    goto v_31996;
v_31997:
    goto v_31993;
v_31994:
    goto v_31995;
v_31996:
    fn = elt(env, 10); // mkmain
    v_32047 = (*qfn2(fn))(fn, v_32047, v_32046);
    env = stack[-4];
    goto v_31988;
v_31989:
    v_32046 = stack[-1];
    goto v_31990;
v_31991:
    goto v_31987;
v_31988:
    goto v_31989;
v_31990:
    {
        fn = elt(env, 12); // conjcubic
        return (*qfn2(fn))(fn, v_32047, v_32046);
    }
v_31959:
    goto v_32012;
v_32008:
    v_32047 = stack[-1];
    goto v_32009;
v_32010:
    v_32046 = elt(env, 1); // expt
    goto v_32011;
v_32012:
    goto v_32008;
v_32009:
    goto v_32010;
v_32011:
    if (!consp(v_32047)) goto v_32006;
    v_32047 = qcar(v_32047);
    if (v_32047 == v_32046) goto v_32005;
    else goto v_32006;
v_32005:
    goto v_32019;
v_32015:
    v_32046 = stack[-1];
    v_32046 = qcdr(v_32046);
    v_32046 = qcdr(v_32046);
    v_32047 = qcar(v_32046);
    goto v_32016;
v_32017:
    v_32046 = elt(env, 7); // (quotient 1 4)
    goto v_32018;
v_32019:
    goto v_32015;
v_32016:
    goto v_32017;
v_32018:
    v_32046 = (equal(v_32047, v_32046) ? lisp_true : nil);
    goto v_32004;
v_32006:
    v_32046 = nil;
    goto v_32004;
    v_32046 = nil;
v_32004:
    if (v_32046 == nil) goto v_32002;
    goto v_32034;
v_32030:
    goto v_32040;
v_32036:
    v_32047 = stack[-2];
    goto v_32037;
v_32038:
    v_32046 = stack[-1];
    goto v_32039;
v_32040:
    goto v_32036;
v_32037:
    goto v_32038;
v_32039:
    fn = elt(env, 10); // mkmain
    v_32047 = (*qfn2(fn))(fn, v_32047, v_32046);
    env = stack[-4];
    goto v_32031;
v_32032:
    v_32046 = stack[-1];
    goto v_32033;
v_32034:
    goto v_32030;
v_32031:
    goto v_32032;
v_32033:
    {
        fn = elt(env, 13); // conjquartic
        return (*qfn2(fn))(fn, v_32047, v_32046);
    }
v_32002:
v_31840:
    v_32046 = stack[-3];
    v_32046 = qcdr(v_32046);
    stack[-3] = v_32046;
    goto v_31828;
v_31827:
    return onevalue(v_32046);
}



// Code for lowestdeg

static LispObject CC_lowestdeg(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31916, v_31917;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_31822;
    v_31916 = v_31821;
// end of prologue
    fn = elt(env, 3); // simp!*
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[-1] = v_31916;
    v_31916 = stack[-1];
    if (!consp(v_31916)) goto v_31838;
    else goto v_31839;
v_31838:
    v_31916 = lisp_true;
    goto v_31837;
v_31839:
    v_31916 = stack[-1];
    v_31916 = qcar(v_31916);
    v_31916 = (consp(v_31916) ? nil : lisp_true);
    goto v_31837;
    v_31916 = nil;
v_31837:
    if (v_31916 == nil) goto v_31835;
    v_31916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31829;
v_31835:
    v_31916 = stack[-1];
    fn = elt(env, 4); // !*q2f
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[-1] = v_31916;
    v_31916 = stack[-1];
    fn = elt(env, 5); // erase_pol_cst
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[0] = v_31916;
    goto v_31860;
v_31856:
    v_31917 = stack[0];
    goto v_31857;
v_31858:
    v_31916 = stack[-1];
    goto v_31859;
v_31860:
    goto v_31856;
v_31857:
    goto v_31858;
v_31859:
    if (equal(v_31917, v_31916)) goto v_31855;
    v_31916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31829;
v_31855:
    v_31916 = stack[-2];
    fn = elt(env, 6); // !*a2k
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[0] = v_31916;
    v_31916 = stack[-2];
    v_31916 = ncons(v_31916);
    env = stack[-4];
    fn = elt(env, 7); // setkorder
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[-3] = v_31916;
    v_31916 = stack[-1];
    fn = elt(env, 8); // reorder
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    stack[-2] = v_31916;
    v_31916 = stack[-3];
    fn = elt(env, 7); // setkorder
    v_31916 = (*qfn1(fn))(fn, v_31916);
    env = stack[-4];
    v_31916 = stack[-2];
    v_31916 = Lreverse(nil, v_31916);
    env = stack[-4];
    stack[-2] = v_31916;
    v_31916 = stack[-2];
    v_31916 = qcar(v_31916);
    v_31916 = qcar(v_31916);
    v_31916 = qcar(v_31916);
    stack[-1] = v_31916;
    v_31916 = stack[-1];
    if (!consp(v_31916)) goto v_31882;
    goto v_31892;
v_31888:
    v_31916 = stack[-1];
    v_31917 = qcar(v_31916);
    goto v_31889;
v_31890:
    v_31916 = elt(env, 1); // expt
    goto v_31891;
v_31892:
    goto v_31888;
v_31889:
    goto v_31890;
v_31891:
    if (v_31917 == v_31916) goto v_31886;
    else goto v_31887;
v_31886:
    v_31916 = elt(env, 2); // "exponents must be integers"
    fn = elt(env, 9); // rederr
    v_31916 = (*qfn1(fn))(fn, v_31916);
    goto v_31885;
v_31887:
v_31885:
    goto v_31880;
v_31882:
v_31880:
    goto v_31906;
v_31902:
    v_31917 = stack[-1];
    goto v_31903;
v_31904:
    v_31916 = stack[0];
    goto v_31905;
v_31906:
    goto v_31902;
v_31903:
    goto v_31904;
v_31905:
    if (equal(v_31917, v_31916)) goto v_31901;
    v_31916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31829;
v_31901:
    v_31916 = stack[-2];
    v_31916 = qcar(v_31916);
    v_31916 = qcar(v_31916);
    v_31916 = qcdr(v_31916);
    goto v_31829;
    v_31916 = nil;
v_31829:
    return onevalue(v_31916);
}



// Code for simprd

static LispObject CC_simprd(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31835, v_31836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31836 = v_31821;
// end of prologue
    v_31835 = v_31836;
    if (!consp(v_31835)) goto v_31825;
    else goto v_31826;
v_31825:
    v_31835 = nil;
    goto v_31824;
v_31826:
    v_31835 = elt(env, 1); // !:rd!:
// Binding dmode!*
// FLUIDBIND: reloadenv=1 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 2, 0);
    qvalue(elt(env, 2)) = v_31835; // dmode!*
    v_31835 = v_31836;
    fn = elt(env, 3); // simplist
    v_31835 = (*qfn1(fn))(fn, v_31835);
    ;}  // end of a binding scope
    goto v_31824;
    v_31835 = nil;
v_31824:
    return onevalue(v_31835);
}



// Code for add!-to!-sorted!-tree

static LispObject CC_addKtoKsortedKtree(LispObject env,
                         LispObject v_31821, LispObject v_31822)
{
    env = qenv(env);
    LispObject v_31930, v_31931, v_31932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31822,v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31821,v_31822);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31822;
    stack[-1] = v_31821;
// end of prologue
    stack[-2] = nil;
v_31827:
    v_31930 = stack[0];
    if (v_31930 == nil) goto v_31830;
    else goto v_31831;
v_31830:
    goto v_31838;
v_31834:
    stack[0] = stack[-2];
    goto v_31835;
v_31836:
    goto v_31847;
v_31841:
    v_31932 = nil;
    goto v_31842;
v_31843:
    v_31931 = stack[-1];
    goto v_31844;
v_31845:
    v_31930 = nil;
    goto v_31846;
v_31847:
    goto v_31841;
v_31842:
    goto v_31843;
v_31844:
    goto v_31845;
v_31846:
    v_31930 = list2star(v_31932, v_31931, v_31930);
    env = stack[-3];
    goto v_31837;
v_31838:
    goto v_31834;
v_31835:
    goto v_31836;
v_31837:
    {
        LispObject v_31936 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_31936, v_31930);
    }
v_31831:
    goto v_31857;
v_31853:
    v_31931 = stack[-1];
    goto v_31854;
v_31855:
    v_31930 = stack[0];
    v_31930 = qcdr(v_31930);
    v_31930 = qcar(v_31930);
    goto v_31856;
v_31857:
    goto v_31853;
v_31854:
    goto v_31855;
v_31856:
    if (equal(v_31931, v_31930)) goto v_31851;
    else goto v_31852;
v_31851:
    goto v_31867;
v_31863:
    v_31931 = stack[-2];
    goto v_31864;
v_31865:
    v_31930 = stack[0];
    goto v_31866;
v_31867:
    goto v_31863;
v_31864:
    goto v_31865;
v_31866:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_31931, v_31930);
    }
v_31852:
    goto v_31877;
v_31873:
    v_31931 = stack[-1];
    goto v_31874;
v_31875:
    v_31930 = stack[0];
    v_31930 = qcdr(v_31930);
    v_31930 = qcar(v_31930);
    goto v_31876;
v_31877:
    goto v_31873;
v_31874:
    goto v_31875;
v_31876:
    v_31930 = Lorderp(nil, v_31931, v_31930);
    env = stack[-3];
    if (v_31930 == nil) goto v_31871;
    goto v_31887;
v_31883:
    goto v_31884;
v_31885:
    goto v_31894;
v_31890:
    goto v_31900;
v_31896:
    v_31931 = stack[-1];
    goto v_31897;
v_31898:
    v_31930 = stack[0];
    v_31930 = qcar(v_31930);
    goto v_31899;
v_31900:
    goto v_31896;
v_31897:
    goto v_31898;
v_31899:
    v_31931 = CC_addKtoKsortedKtree(elt(env, 0), v_31931, v_31930);
    env = stack[-3];
    goto v_31891;
v_31892:
    v_31930 = stack[0];
    v_31930 = qcdr(v_31930);
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    v_31930 = cons(v_31931, v_31930);
    env = stack[-3];
    goto v_31886;
v_31887:
    goto v_31883;
v_31884:
    goto v_31885;
v_31886:
    {
        LispObject v_31937 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_31937, v_31930);
    }
v_31871:
    goto v_31913;
v_31909:
    v_31930 = stack[0];
    v_31931 = qcar(v_31930);
    goto v_31910;
v_31911:
    v_31930 = stack[-2];
    goto v_31912;
v_31913:
    goto v_31909;
v_31910:
    goto v_31911;
v_31912:
    v_31930 = cons(v_31931, v_31930);
    env = stack[-3];
    stack[-2] = v_31930;
    goto v_31922;
v_31918:
    v_31930 = stack[0];
    v_31930 = qcdr(v_31930);
    v_31931 = qcar(v_31930);
    goto v_31919;
v_31920:
    v_31930 = stack[-2];
    goto v_31921;
v_31922:
    goto v_31918;
v_31919:
    goto v_31920;
v_31921:
    v_31930 = cons(v_31931, v_31930);
    env = stack[-3];
    stack[-2] = v_31930;
    v_31930 = stack[0];
    v_31930 = qcdr(v_31930);
    v_31930 = qcdr(v_31930);
    stack[0] = v_31930;
    goto v_31827;
    v_31930 = nil;
    return onevalue(v_31930);
}



// Code for get!*nr!*real!*irred!*reps

static LispObject CC_getHnrHrealHirredHreps(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31833, v_31834;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31833 = v_31821;
// end of prologue
    goto v_31830;
v_31826:
    goto v_31827;
v_31828:
    v_31834 = elt(env, 1); // realrepnumber
    goto v_31829;
v_31830:
    goto v_31826;
v_31827:
    goto v_31828;
v_31829:
    return get(v_31833, v_31834);
    return onevalue(v_31833);
}



// Code for pasf_ceeq

static LispObject CC_pasf_ceeq(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31934, v_31935;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31821;
// end of prologue
    goto v_31842;
v_31838:
    v_31935 = stack[0];
    goto v_31839;
v_31840:
    v_31934 = elt(env, 1); // true
    goto v_31841;
v_31842:
    goto v_31838;
v_31839:
    goto v_31840;
v_31841:
    if (v_31935 == v_31934) goto v_31836;
    else goto v_31837;
v_31836:
    v_31934 = lisp_true;
    goto v_31835;
v_31837:
    goto v_31852;
v_31848:
    v_31935 = stack[0];
    goto v_31849;
v_31850:
    v_31934 = elt(env, 2); // false
    goto v_31851;
v_31852:
    goto v_31848;
v_31849:
    goto v_31850;
v_31851:
    v_31934 = (v_31935 == v_31934 ? lisp_true : nil);
    goto v_31835;
    v_31934 = nil;
v_31835:
    if (v_31934 == nil) goto v_31833;
    v_31934 = lisp_true;
    goto v_31831;
v_31833:
    goto v_31863;
v_31859:
    goto v_31876;
v_31872:
    v_31935 = stack[0];
    goto v_31873;
v_31874:
    v_31934 = elt(env, 1); // true
    goto v_31875;
v_31876:
    goto v_31872;
v_31873:
    goto v_31874;
v_31875:
    if (v_31935 == v_31934) goto v_31870;
    else goto v_31871;
v_31870:
    v_31934 = lisp_true;
    goto v_31869;
v_31871:
    goto v_31886;
v_31882:
    v_31935 = stack[0];
    goto v_31883;
v_31884:
    v_31934 = elt(env, 2); // false
    goto v_31885;
v_31886:
    goto v_31882;
v_31883:
    goto v_31884;
v_31885:
    v_31934 = (v_31935 == v_31934 ? lisp_true : nil);
    goto v_31869;
    v_31934 = nil;
v_31869:
    if (v_31934 == nil) goto v_31867;
    v_31934 = stack[0];
    v_31935 = v_31934;
    goto v_31865;
v_31867:
    v_31934 = stack[0];
    v_31934 = qcar(v_31934);
    v_31934 = Lconsp(nil, v_31934);
    env = stack[-2];
    if (v_31934 == nil) goto v_31892;
    v_31934 = stack[0];
    v_31934 = qcar(v_31934);
    v_31934 = qcar(v_31934);
    v_31935 = v_31934;
    goto v_31865;
v_31892:
    v_31934 = stack[0];
    v_31934 = qcar(v_31934);
    v_31935 = v_31934;
    goto v_31865;
    v_31935 = nil;
v_31865:
    goto v_31860;
v_31861:
    v_31934 = elt(env, 3); // (equal neq)
    goto v_31862;
v_31863:
    goto v_31859;
v_31860:
    goto v_31861;
v_31862:
    v_31934 = Lmemq(nil, v_31935, v_31934);
    v_31934 = (v_31934 == nil ? lisp_true : nil);
    goto v_31831;
    v_31934 = nil;
v_31831:
    if (v_31934 == nil) goto v_31829;
    v_31934 = stack[0];
    goto v_31825;
v_31829:
    v_31934 = stack[0];
    v_31934 = qcdr(v_31934);
    v_31934 = qcar(v_31934);
    fn = elt(env, 4); // sfto_dcontentf
    v_31934 = (*qfn1(fn))(fn, v_31934);
    env = stack[-2];
    v_31935 = v_31934;
    goto v_31918;
v_31912:
    v_31934 = stack[0];
    stack[-1] = qcar(v_31934);
    goto v_31913;
v_31914:
    goto v_31926;
v_31922:
    v_31934 = stack[0];
    v_31934 = qcdr(v_31934);
    stack[0] = qcar(v_31934);
    goto v_31923;
v_31924:
    v_31934 = v_31935;
    fn = elt(env, 5); // simp
    v_31934 = (*qfn1(fn))(fn, v_31934);
    env = stack[-2];
    v_31934 = qcar(v_31934);
    goto v_31925;
v_31926:
    goto v_31922;
v_31923:
    goto v_31924;
v_31925:
    fn = elt(env, 6); // quotfx
    v_31935 = (*qfn2(fn))(fn, stack[0], v_31934);
    goto v_31915;
v_31916:
    v_31934 = nil;
    goto v_31917;
v_31918:
    goto v_31912;
v_31913:
    goto v_31914;
v_31915:
    goto v_31916;
v_31917:
    {
        LispObject v_31938 = stack[-1];
        return list3(v_31938, v_31935, v_31934);
    }
v_31825:
    return onevalue(v_31934);
}



// Code for matrix_input_test

static LispObject CC_matrix_input_test(LispObject env,
                         LispObject v_31821)
{
    env = qenv(env);
    LispObject v_31852, v_31853, v_31854;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31821);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31821);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31853 = v_31821;
// end of prologue
    goto v_31834;
v_31830:
    v_31854 = v_31853;
    goto v_31831;
v_31832:
    v_31852 = elt(env, 1); // mat
    goto v_31833;
v_31834:
    goto v_31830;
v_31831:
    goto v_31832;
v_31833:
    if (!consp(v_31854)) goto v_31827;
    v_31854 = qcar(v_31854);
    if (v_31854 == v_31852) goto v_31828;
v_31827:
    goto v_31845;
v_31839:
    v_31854 = elt(env, 2); // "ERROR: `"
    goto v_31840;
v_31841:
    goto v_31842;
v_31843:
    v_31852 = elt(env, 3); // "' is non matrix input."
    goto v_31844;
v_31845:
    goto v_31839;
v_31840:
    goto v_31841;
v_31842:
    goto v_31843;
v_31844:
    v_31852 = list3(v_31854, v_31853, v_31852);
    env = stack[0];
    fn = elt(env, 4); // rederr
    v_31852 = (*qfn1(fn))(fn, v_31852);
    goto v_31826;
v_31828:
    v_31852 = v_31853;
    goto v_31824;
v_31826:
    v_31852 = nil;
v_31824:
    return onevalue(v_31852);
}



setup_type const u53_setup[] =
{
    {"pasf_exprng",             CC_pasf_exprng, TOO_MANY_1,    WRONG_NO_1},
    {"aex_neg",                 CC_aex_neg,     TOO_MANY_1,    WRONG_NO_1},
    {"varsinsf",                TOO_FEW_2,      CC_varsinsf,   WRONG_NO_2},
    {"mkratnum",                CC_mkratnum,    TOO_MANY_1,    WRONG_NO_1},
    {"xpartitsq",               CC_xpartitsq,   TOO_MANY_1,    WRONG_NO_1},
    {"binc",                    TOO_FEW_2,      CC_binc,       WRONG_NO_2},
    {"gi",                      TOO_FEW_2,      CC_gi,         WRONG_NO_2},
    {"exports",                 CC_exports,     TOO_MANY_1,    WRONG_NO_1},
    {"square-free-mod-p",       CC_squareKfreeKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"addinds",                 TOO_FEW_2,      CC_addinds,    WRONG_NO_2},
    {"subscriptedvarp2",        CC_subscriptedvarp2,TOO_MANY_1,WRONG_NO_1},
    {"evalsubset",              TOO_FEW_2,      CC_evalsubset, WRONG_NO_2},
    {"*kp2q",                   TOO_FEW_2,      CC_Hkp2q,      WRONG_NO_2},
    {"calc_world",              TOO_FEW_2,      CC_calc_world, WRONG_NO_2},
    {"liendimcom",              CC_liendimcom,  TOO_MANY_1,    WRONG_NO_1},
    {"dpmat_gbtag",             CC_dpmat_gbtag, TOO_MANY_1,    WRONG_NO_1},
    {"st_extract_symcells1",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_extract_symcells1},
    {"addcoeffs",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addcoeffs},
    {"qqe_simpat",              CC_qqe_simpat,  TOO_MANY_1,    WRONG_NO_1},
    {"bc_minus?",               CC_bc_minusW,   TOO_MANY_1,    WRONG_NO_1},
    {"crprimp",                 CC_crprimp,     TOO_MANY_1,    WRONG_NO_1},
    {"remove_critical_pairs",   TOO_FEW_2,      CC_remove_critical_pairs,WRONG_NO_2},
    {"acmemb",                  TOO_FEW_2,      CC_acmemb,     WRONG_NO_2},
    {"physopplus",              CC_physopplus,  TOO_MANY_1,    WRONG_NO_1},
    {"bassoc",                  TOO_FEW_2,      CC_bassoc,     WRONG_NO_2},
    {"*sq2fourier",             CC_Hsq2fourier, TOO_MANY_1,    WRONG_NO_1},
    {"all_index_lst",           CC_all_index_lst,TOO_MANY_1,   WRONG_NO_1},
    {"sc_create",               CC_sc_create,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_exploitknowl",       CC_ofsf_exploitknowl,TOO_MANY_1,WRONG_NO_1},
    {"uterm",                   TOO_FEW_2,      CC_uterm,      WRONG_NO_2},
    {"change+sq+to+int",        CC_changeLsqLtoLint,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_factsf",             CC_ofsf_factsf, TOO_MANY_1,    WRONG_NO_1},
    {"operator",                CC_operator,    TOO_MANY_1,    WRONG_NO_1},
    {"look_for_rational",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_look_for_rational},
    {"vevzero?1",               CC_vevzeroW1,   TOO_MANY_1,    WRONG_NO_1},
    {"xpndwedge",               CC_xpndwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"unshift",                 CC_unshift,     TOO_MANY_1,    WRONG_NO_1},
    {"r2speclist",              CC_r2speclist,  TOO_MANY_1,    WRONG_NO_1},
    {"noncom1",                 CC_noncom1,     TOO_MANY_1,    WRONG_NO_1},
    {"rationalizef",            CC_rationalizef,TOO_MANY_1,    WRONG_NO_1},
    {"lowestdeg",               TOO_FEW_2,      CC_lowestdeg,  WRONG_NO_2},
    {"simprd",                  CC_simprd,      TOO_MANY_1,    WRONG_NO_1},
    {"add-to-sorted-tree",      TOO_FEW_2,      CC_addKtoKsortedKtree,WRONG_NO_2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,TOO_MANY_1,WRONG_NO_1},
    {"pasf_ceeq",               CC_pasf_ceeq,   TOO_MANY_1,    WRONG_NO_1},
    {"matrix_input_test",       CC_matrix_input_test,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u53", (two_args *)"137633 7609280 6193553", 0}
};

// end of generated code
