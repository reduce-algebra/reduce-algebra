
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



// Code for pst_d1

static LispObject CC_pst_d1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31406;
    LispObject fn;
    LispObject v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pst_d1");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31214,v_31215,v_31216);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_31216;
    stack[-11] = v_31215;
    v_31406 = v_31214;
// end of prologue
    goto v_31228;
v_31224:
    stack[0] = stack[-10];
    goto v_31225;
v_31226:
    v_31406 = sub1(v_31406);
    env = stack[-13];
    goto v_31227;
v_31228:
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    v_31406 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_31406-TAG_FIXNUM)/(16/CELL)));
    stack[-12] = v_31406;
    v_31406 = stack[-12];
    if (v_31406 == nil) goto v_31235;
    else goto v_31236;
v_31235:
    v_31406 = nil;
    goto v_31222;
v_31236:
    v_31406 = stack[-12];
    v_31406 = qcar(v_31406);
    stack[-6] = v_31406;
    goto v_31254;
v_31250:
    stack[0] = stack[-10];
    goto v_31251;
v_31252:
    v_31406 = stack[-11];
    v_31406 = sub1(v_31406);
    env = stack[-13];
    goto v_31253;
v_31254:
    goto v_31250;
v_31251:
    goto v_31252;
v_31253:
    v_31406 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_31406-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_31406;
    v_31406 = stack[-5];
    if (v_31406 == nil) goto v_31261;
    else goto v_31262;
v_31261:
    v_31406 = nil;
    goto v_31248;
v_31262:
    v_31406 = stack[-5];
    v_31406 = qcar(v_31406);
    stack[-1] = v_31406;
    goto v_31275;
v_31271:
    v_31406 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31272;
v_31273:
    v_31406 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31274;
v_31275:
    goto v_31271;
v_31272:
    goto v_31273;
v_31274:
    fn = elt(env, 2); // pa_coinc_split
    v_31406 = (*qfn2(fn))(fn, stack[0], v_31406);
    env = stack[-13];
    v_31406 = qcar(v_31406);
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    stack[-3] = v_31406;
    stack[-4] = v_31406;
v_31249:
    v_31406 = stack[-5];
    v_31406 = qcdr(v_31406);
    stack[-5] = v_31406;
    v_31406 = stack[-5];
    if (v_31406 == nil) goto v_31285;
    else goto v_31286;
v_31285:
    v_31406 = stack[-4];
    goto v_31248;
v_31286:
    goto v_31294;
v_31290:
    stack[-2] = stack[-3];
    goto v_31291;
v_31292:
    v_31406 = stack[-5];
    v_31406 = qcar(v_31406);
    stack[-1] = v_31406;
    goto v_31306;
v_31302:
    v_31406 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31303;
v_31304:
    v_31406 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31305;
v_31306:
    goto v_31302;
v_31303:
    goto v_31304;
v_31305:
    fn = elt(env, 2); // pa_coinc_split
    v_31406 = (*qfn2(fn))(fn, stack[0], v_31406);
    env = stack[-13];
    v_31406 = qcar(v_31406);
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    goto v_31293;
v_31294:
    goto v_31290;
v_31291:
    goto v_31292;
v_31293:
    v_31406 = Lrplacd(nil, stack[-2], v_31406);
    env = stack[-13];
    v_31406 = stack[-3];
    v_31406 = qcdr(v_31406);
    stack[-3] = v_31406;
    goto v_31249;
v_31248:
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    stack[-8] = v_31406;
    stack[-9] = v_31406;
v_31223:
    v_31406 = stack[-12];
    v_31406 = qcdr(v_31406);
    stack[-12] = v_31406;
    v_31406 = stack[-12];
    if (v_31406 == nil) goto v_31318;
    else goto v_31319;
v_31318:
    v_31406 = stack[-9];
    goto v_31222;
v_31319:
    goto v_31327;
v_31323:
    stack[-7] = stack[-8];
    goto v_31324;
v_31325:
    v_31406 = stack[-12];
    v_31406 = qcar(v_31406);
    stack[-6] = v_31406;
    goto v_31344;
v_31340:
    stack[0] = stack[-10];
    goto v_31341;
v_31342:
    v_31406 = stack[-11];
    v_31406 = sub1(v_31406);
    env = stack[-13];
    goto v_31343;
v_31344:
    goto v_31340;
v_31341:
    goto v_31342;
v_31343:
    v_31406 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_31406-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_31406;
    v_31406 = stack[-5];
    if (v_31406 == nil) goto v_31351;
    else goto v_31352;
v_31351:
    v_31406 = nil;
    goto v_31338;
v_31352:
    v_31406 = stack[-5];
    v_31406 = qcar(v_31406);
    stack[-1] = v_31406;
    goto v_31365;
v_31361:
    v_31406 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31362;
v_31363:
    v_31406 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31364;
v_31365:
    goto v_31361;
v_31362:
    goto v_31363;
v_31364:
    fn = elt(env, 2); // pa_coinc_split
    v_31406 = (*qfn2(fn))(fn, stack[0], v_31406);
    env = stack[-13];
    v_31406 = qcar(v_31406);
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    stack[-3] = v_31406;
    stack[-4] = v_31406;
v_31339:
    v_31406 = stack[-5];
    v_31406 = qcdr(v_31406);
    stack[-5] = v_31406;
    v_31406 = stack[-5];
    if (v_31406 == nil) goto v_31375;
    else goto v_31376;
v_31375:
    v_31406 = stack[-4];
    goto v_31338;
v_31376:
    goto v_31384;
v_31380:
    stack[-2] = stack[-3];
    goto v_31381;
v_31382:
    v_31406 = stack[-5];
    v_31406 = qcar(v_31406);
    stack[-1] = v_31406;
    goto v_31396;
v_31392:
    v_31406 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31393;
v_31394:
    v_31406 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    goto v_31395;
v_31396:
    goto v_31392;
v_31393:
    goto v_31394;
v_31395:
    fn = elt(env, 2); // pa_coinc_split
    v_31406 = (*qfn2(fn))(fn, stack[0], v_31406);
    env = stack[-13];
    v_31406 = qcar(v_31406);
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    goto v_31383;
v_31384:
    goto v_31380;
v_31381:
    goto v_31382;
v_31383:
    v_31406 = Lrplacd(nil, stack[-2], v_31406);
    env = stack[-13];
    v_31406 = stack[-3];
    v_31406 = qcdr(v_31406);
    stack[-3] = v_31406;
    goto v_31339;
v_31338:
    fn = elt(env, 3); // ordn
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-13];
    v_31406 = ncons(v_31406);
    env = stack[-13];
    goto v_31326;
v_31327:
    goto v_31323;
v_31324:
    goto v_31325;
v_31326:
    v_31406 = Lrplacd(nil, stack[-7], v_31406);
    env = stack[-13];
    v_31406 = stack[-8];
    v_31406 = qcdr(v_31406);
    stack[-8] = v_31406;
    goto v_31223;
v_31222:
    return onevalue(v_31406);
}



// Code for baglistp

static LispObject CC_baglistp(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31248, v_31249, v_31250;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31250 = v_31214;
// end of prologue
    v_31248 = v_31250;
    if (!consp(v_31248)) goto v_31219;
    goto v_31229;
v_31225:
    v_31248 = v_31250;
    v_31249 = qcar(v_31248);
    goto v_31226;
v_31227:
    v_31248 = elt(env, 1); // list
    goto v_31228;
v_31229:
    goto v_31225;
v_31226:
    goto v_31227;
v_31228:
    if (v_31249 == v_31248) goto v_31223;
    else goto v_31224;
v_31223:
    v_31248 = lisp_true;
    goto v_31222;
v_31224:
    goto v_31241;
v_31237:
    v_31248 = v_31250;
    v_31248 = qcar(v_31248);
    goto v_31238;
v_31239:
    v_31249 = elt(env, 2); // bag
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
        return Lflagp(nil, v_31248, v_31249);
    v_31248 = nil;
v_31222:
    goto v_31217;
v_31219:
    v_31248 = nil;
    goto v_31217;
    v_31248 = nil;
v_31217:
    return onevalue(v_31248);
}



// Code for general!-difference!-mod!-p

static LispObject CC_generalKdifferenceKmodKp(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31226, v_31227;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31226 = v_31215;
    v_31227 = v_31214;
// end of prologue
    goto v_31222;
v_31218:
    stack[0] = v_31227;
    goto v_31219;
v_31220:
    fn = elt(env, 1); // general!-minus!-mod!-p
    v_31226 = (*qfn1(fn))(fn, v_31226);
    env = stack[-1];
    goto v_31221;
v_31222:
    goto v_31218;
v_31219:
    goto v_31220;
v_31221:
    {
        LispObject v_31229 = stack[0];
        fn = elt(env, 2); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_31229, v_31226);
    }
}



// Code for constructinvolutivebasis

static LispObject CC_constructinvolutivebasis(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31507, v_31508, v_31509;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_31215;
    stack[0] = v_31214;
// end of prologue
    goto v_31231;
v_31227:
    v_31508 = stack[0];
    goto v_31228;
v_31229:
    v_31507 = lisp_true;
    goto v_31230;
v_31231:
    goto v_31227;
v_31228:
    goto v_31229;
v_31230:
    fn = elt(env, 5); // polynomlistautoreduce
    v_31507 = (*qfn2(fn))(fn, v_31508, v_31507);
    env = stack[-7];
    stack[0] = v_31507;
v_31236:
    v_31507 = stack[0];
    v_31507 = qcar(v_31507);
    if (v_31507 == nil) goto v_31239;
    else goto v_31240;
v_31239:
    goto v_31235;
v_31240:
    goto v_31249;
v_31245:
    stack[-1] = qvalue(elt(env, 2)); // fluidbibasissetq
    goto v_31246;
v_31247:
    v_31507 = stack[0];
    v_31507 = qcar(v_31507);
    fn = elt(env, 6); // createtriple
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31248;
v_31249:
    goto v_31245;
v_31246:
    goto v_31247;
v_31248:
    fn = elt(env, 7); // sortedtriplelistinsert
    v_31507 = (*qfn2(fn))(fn, stack[-1], v_31507);
    env = stack[-7];
    v_31507 = stack[0];
    v_31507 = qcdr(v_31507);
    stack[0] = v_31507;
    goto v_31236;
v_31235:
v_31259:
    v_31507 = qvalue(elt(env, 2)); // fluidbibasissetq
    v_31507 = qcar(v_31507);
    if (v_31507 == nil) goto v_31262;
    else goto v_31263;
v_31262:
    goto v_31258;
v_31263:
    fn = elt(env, 8); // setqget
    v_31507 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[-6] = v_31507;
    goto v_31272;
v_31268:
    v_31508 = stack[-6];
    goto v_31269;
v_31270:
    v_31507 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31271;
v_31272:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    v_31507 = qcar(v_31507);
    stack[-4] = v_31507;
    goto v_31282;
v_31278:
    v_31508 = stack[-6];
    goto v_31279;
v_31280:
    v_31507 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31281;
v_31282:
    goto v_31278;
v_31279:
    goto v_31280;
v_31281:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 9); // normalform
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    stack[-3] = v_31507;
    v_31507 = stack[-3];
    v_31507 = qcar(v_31507);
    stack[-2] = v_31507;
    v_31507 = stack[-2];
    if (v_31507 == nil) goto v_31291;
    v_31507 = qvalue(elt(env, 3)); // fluidbibasisnonzeronormalforms
    v_31507 = (LispObject)((intptr_t)(v_31507) + 0x10);
    qvalue(elt(env, 3)) = v_31507; // fluidbibasisnonzeronormalforms
    v_31507 = nil;
    v_31507 = ncons(v_31507);
    env = stack[-7];
    stack[0] = v_31507;
    v_31507 = qvalue(elt(env, 4)); // fluidbibasissett
    stack[-1] = v_31507;
v_31300:
    v_31507 = stack[-1];
    v_31507 = qcar(v_31507);
    if (v_31507 == nil) goto v_31303;
    else goto v_31304;
v_31303:
    goto v_31299;
v_31304:
    goto v_31317;
v_31313:
    goto v_31322;
v_31318:
    v_31507 = stack[-1];
    v_31508 = qcar(v_31507);
    goto v_31319;
v_31320:
    v_31507 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31321;
v_31322:
    goto v_31318;
v_31319:
    goto v_31320;
v_31321:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    v_31508 = qcar(v_31507);
    goto v_31314;
v_31315:
    v_31507 = stack[-2];
    goto v_31316;
v_31317:
    goto v_31313;
v_31314:
    goto v_31315;
v_31316:
    fn = elt(env, 10); // monomisdivisibleby
    v_31507 = (*qfn2(fn))(fn, v_31508, v_31507);
    env = stack[-7];
    if (v_31507 == nil) goto v_31311;
    goto v_31334;
v_31330:
    v_31507 = stack[-1];
    v_31508 = qcar(v_31507);
    goto v_31331;
v_31332:
    v_31507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31333;
v_31334:
    goto v_31330;
v_31331:
    goto v_31332;
v_31333:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 11); // setqdeletedescendants
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31344;
v_31340:
    v_31508 = stack[0];
    goto v_31341;
v_31342:
    v_31507 = stack[-1];
    v_31507 = qcar(v_31507);
    goto v_31343;
v_31344:
    goto v_31340;
v_31341:
    goto v_31342;
v_31343:
    fn = elt(env, 7); // sortedtriplelistinsert
    v_31507 = (*qfn2(fn))(fn, v_31508, v_31507);
    env = stack[-7];
    goto v_31353;
v_31349:
    v_31507 = stack[-1];
    v_31508 = qcar(v_31507);
    goto v_31350;
v_31351:
    v_31507 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31352;
v_31353:
    goto v_31349;
v_31350:
    goto v_31351;
v_31352:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    v_31507 = qcar(v_31507);
    fn = elt(env, 12); // janettreedelete
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31364;
v_31360:
    goto v_31370;
v_31366:
    v_31508 = stack[-1];
    goto v_31367;
v_31368:
    v_31507 = stack[-1];
    v_31507 = qcdr(v_31507);
    v_31507 = qcar(v_31507);
    goto v_31369;
v_31370:
    goto v_31366;
v_31367:
    goto v_31368;
v_31369:
    v_31508 = Lrplaca(nil, v_31508, v_31507);
    env = stack[-7];
    goto v_31361;
v_31362:
    v_31507 = stack[-1];
    v_31507 = qcdr(v_31507);
    v_31507 = qcdr(v_31507);
    goto v_31363;
v_31364:
    goto v_31360;
v_31361:
    goto v_31362;
v_31363:
    v_31507 = Lrplacd(nil, v_31508, v_31507);
    env = stack[-7];
    goto v_31309;
v_31311:
    v_31507 = stack[-1];
    v_31507 = qcdr(v_31507);
    stack[-1] = v_31507;
    goto v_31309;
v_31309:
    goto v_31300;
v_31299:
    goto v_31393;
v_31389:
    v_31508 = stack[-4];
    goto v_31390;
v_31391:
    v_31507 = stack[-2];
    goto v_31392;
v_31393:
    goto v_31389;
v_31390:
    goto v_31391;
v_31392:
    if (v_31508 == v_31507) goto v_31387;
    else goto v_31388;
v_31387:
    goto v_31402;
v_31398:
    v_31509 = stack[-3];
    goto v_31399;
v_31400:
    goto v_31408;
v_31404:
    v_31508 = stack[-6];
    goto v_31405;
v_31406:
    v_31507 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31407;
v_31408:
    goto v_31404;
v_31405:
    goto v_31406;
v_31407:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    goto v_31401;
v_31402:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    fn = elt(env, 13); // createtriplewithancestor
    v_31507 = (*qfn2(fn))(fn, v_31509, v_31507);
    env = stack[-7];
    fn = elt(env, 14); // settinsert
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31417;
v_31413:
    v_31507 = qvalue(elt(env, 4)); // fluidbibasissett
    v_31509 = qcar(v_31507);
    goto v_31414;
v_31415:
    goto v_31424;
v_31420:
    v_31508 = stack[-6];
    goto v_31421;
v_31422:
    v_31507 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31423;
v_31424:
    goto v_31420;
v_31421:
    goto v_31422;
v_31423:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    goto v_31416;
v_31417:
    goto v_31413;
v_31414:
    goto v_31415;
v_31416:
    fn = elt(env, 15); // triplesetprolongset
    v_31507 = (*qfn2(fn))(fn, v_31509, v_31507);
    env = stack[-7];
    goto v_31386;
v_31388:
    v_31507 = stack[-3];
    fn = elt(env, 6); // createtriple
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    fn = elt(env, 14); // settinsert
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31386;
v_31386:
    v_31507 = stack[0];
    fn = elt(env, 16); // settcollectnonmultiprolongations
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31446;
v_31442:
    goto v_31451;
v_31447:
    v_31508 = stack[-2];
    goto v_31448;
v_31449:
    v_31507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31450;
v_31451:
    goto v_31447;
v_31448:
    goto v_31449;
v_31450:
    v_31508 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    goto v_31443;
v_31444:
    v_31507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31445;
v_31446:
    goto v_31442;
v_31443:
    goto v_31444;
v_31445:
    v_31507 = Leqn(nil, v_31508, v_31507);
    env = stack[-7];
    if (v_31507 == nil) goto v_31440;
    v_31507 = nil;
    v_31507 = ncons(v_31507);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_31507; // fluidbibasissetq
    goto v_31438;
v_31440:
    v_31507 = stack[0];
    fn = elt(env, 17); // setqinsertlist
    v_31507 = (*qfn1(fn))(fn, v_31507);
    env = stack[-7];
    goto v_31438;
v_31438:
    goto v_31289;
v_31291:
v_31289:
    goto v_31259;
v_31258:
    v_31507 = nil;
    v_31507 = ncons(v_31507);
    env = stack[-7];
    stack[0] = v_31507;
    v_31507 = qvalue(elt(env, 4)); // fluidbibasissett
    stack[-1] = v_31507;
v_31471:
    v_31507 = stack[-1];
    v_31507 = qcar(v_31507);
    if (v_31507 == nil) goto v_31474;
    else goto v_31475;
v_31474:
    goto v_31470;
v_31475:
    goto v_31484;
v_31480:
    v_31509 = stack[0];
    goto v_31481;
v_31482:
    goto v_31490;
v_31486:
    v_31507 = stack[-1];
    v_31508 = qcar(v_31507);
    goto v_31487;
v_31488:
    v_31507 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31489;
v_31490:
    goto v_31486;
v_31487:
    goto v_31488;
v_31489:
    v_31507 = *(LispObject *)((char *)v_31508 + (CELL-TAG_VECTOR) + (((intptr_t)v_31507-TAG_FIXNUM)/(16/CELL)));
    goto v_31483;
v_31484:
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    fn = elt(env, 18); // sortedpolynomlistinsert
    v_31507 = (*qfn2(fn))(fn, v_31509, v_31507);
    env = stack[-7];
    v_31507 = stack[-1];
    v_31507 = qcdr(v_31507);
    stack[-1] = v_31507;
    goto v_31471;
v_31470:
    goto v_31503;
v_31499:
    v_31508 = stack[0];
    goto v_31500;
v_31501:
    v_31507 = stack[-5];
    goto v_31502;
v_31503:
    goto v_31499;
v_31500:
    goto v_31501;
v_31502:
    {
        fn = elt(env, 5); // polynomlistautoreduce
        return (*qfn2(fn))(fn, v_31508, v_31507);
    }
    return onevalue(v_31507);
}



// Code for talp_cocc

static LispObject CC_talp_cocc(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31292, v_31293, v_31294;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31215;
    v_31292 = v_31214;
// end of prologue
    v_31293 = (LispObject)0+TAG_FIXNUM; // 0
    v_31294 = v_31293;
    v_31293 = v_31292;
    v_31293 = Lconsp(nil, v_31293);
    env = stack[-3];
    if (v_31293 == nil) goto v_31226;
    stack[-2] = v_31292;
v_31232:
    v_31292 = stack[-2];
    if (v_31292 == nil) goto v_31236;
    else goto v_31237;
v_31236:
    goto v_31231;
v_31237:
    v_31292 = stack[-2];
    v_31292 = qcar(v_31292);
    v_31293 = v_31292;
    v_31292 = v_31293;
    v_31292 = Lconsp(nil, v_31292);
    env = stack[-3];
    if (v_31292 == nil) goto v_31246;
    goto v_31254;
v_31250:
    stack[0] = v_31294;
    goto v_31251;
v_31252:
    goto v_31261;
v_31257:
    goto v_31258;
v_31259:
    v_31292 = stack[-1];
    goto v_31260;
v_31261:
    goto v_31257;
v_31258:
    goto v_31259;
v_31260:
    v_31292 = CC_talp_cocc(elt(env, 0), v_31293, v_31292);
    env = stack[-3];
    goto v_31253;
v_31254:
    goto v_31250;
v_31251:
    goto v_31252;
v_31253:
    v_31292 = plus2(stack[0], v_31292);
    env = stack[-3];
    v_31294 = v_31292;
    goto v_31244;
v_31246:
    goto v_31274;
v_31270:
    goto v_31271;
v_31272:
    v_31292 = stack[-1];
    goto v_31273;
v_31274:
    goto v_31270;
v_31271:
    goto v_31272;
v_31273:
    if (v_31293 == v_31292) goto v_31268;
    else goto v_31269;
v_31268:
    v_31292 = v_31294;
    v_31292 = add1(v_31292);
    env = stack[-3];
    v_31294 = v_31292;
    goto v_31267;
v_31269:
v_31267:
    goto v_31244;
v_31244:
    v_31292 = stack[-2];
    v_31292 = qcdr(v_31292);
    stack[-2] = v_31292;
    goto v_31232;
v_31231:
    goto v_31224;
v_31226:
    goto v_31287;
v_31283:
    v_31293 = stack[-1];
    goto v_31284;
v_31285:
    goto v_31286;
v_31287:
    goto v_31283;
v_31284:
    goto v_31285;
v_31286:
    if (v_31293 == v_31292) goto v_31281;
    else goto v_31282;
v_31281:
    v_31292 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31219;
v_31282:
v_31224:
    v_31292 = v_31294;
v_31219:
    return onevalue(v_31292);
}



// Code for qqe_length!-graph!-marked

static LispObject CC_qqe_lengthKgraphKmarked(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31224, v_31225;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31224 = v_31214;
// end of prologue
    goto v_31221;
v_31217:
    goto v_31218;
v_31219:
    v_31225 = elt(env, 1); // blockmark
    goto v_31220;
v_31221:
    goto v_31217;
v_31218:
    goto v_31219;
v_31220:
    return get(v_31224, v_31225);
}



// Code for dipreplus

static LispObject CC_dipreplus(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31238, v_31239;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31239 = v_31214;
// end of prologue
    v_31238 = v_31239;
    if (!consp(v_31238)) goto v_31218;
    else goto v_31219;
v_31218:
    v_31238 = v_31239;
    goto v_31217;
v_31219:
    v_31238 = v_31239;
    v_31238 = qcdr(v_31238);
    if (v_31238 == nil) goto v_31222;
    else goto v_31223;
v_31222:
    v_31238 = v_31239;
    v_31238 = qcar(v_31238);
    goto v_31217;
v_31223:
    goto v_31235;
v_31231:
    v_31238 = elt(env, 1); // plus
    goto v_31232;
v_31233:
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    return cons(v_31238, v_31239);
    v_31238 = nil;
v_31217:
    return onevalue(v_31238);
}



// Code for make_wedge_pair

static LispObject CC_make_wedge_pair(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31306, v_31307, v_31308;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31215;
    stack[-2] = v_31214;
// end of prologue
    goto v_31222;
v_31218:
    goto v_31228;
v_31224:
    v_31307 = stack[-2];
    goto v_31225;
v_31226:
    v_31306 = stack[-2];
    goto v_31227;
v_31228:
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    stack[0] = list2(v_31307, v_31306);
    env = stack[-4];
    goto v_31219;
v_31220:
    v_31306 = stack[-1];
    fn = elt(env, 4); // xval
    v_31306 = (*qfn1(fn))(fn, v_31306);
    env = stack[-4];
    goto v_31221;
v_31222:
    goto v_31218;
v_31219:
    goto v_31220;
v_31221:
    fn = elt(env, 5); // xlcm
    v_31306 = (*qfn2(fn))(fn, stack[0], v_31306);
    env = stack[-4];
    stack[-3] = v_31306;
    v_31306 = qvalue(elt(env, 1)); // !*twosided
    if (v_31306 == nil) goto v_31238;
    v_31306 = qvalue(elt(env, 2)); // xtruncate!*
    if (v_31306 == nil) goto v_31241;
    else goto v_31238;
v_31241:
    goto v_31237;
v_31238:
    goto v_31248;
v_31244:
    stack[0] = stack[-2];
    goto v_31245;
v_31246:
    v_31306 = stack[-1];
    fn = elt(env, 4); // xval
    v_31306 = (*qfn1(fn))(fn, v_31306);
    env = stack[-4];
    goto v_31247;
v_31248:
    goto v_31244;
v_31245:
    goto v_31246;
v_31247:
    v_31306 = Lmemq(nil, stack[0], v_31306);
    if (v_31306 == nil) goto v_31243;
    else goto v_31237;
v_31243:
    v_31306 = nil;
    goto v_31235;
v_31237:
    goto v_31265;
v_31261:
    v_31307 = stack[-2];
    goto v_31262;
v_31263:
    v_31306 = stack[-1];
    goto v_31264;
v_31265:
    goto v_31261;
v_31262:
    goto v_31263;
v_31264:
    fn = elt(env, 6); // overall_factor
    v_31306 = (*qfn2(fn))(fn, v_31307, v_31306);
    env = stack[-4];
    if (v_31306 == nil) goto v_31258;
    else goto v_31259;
v_31258:
    v_31306 = stack[-3];
    fn = elt(env, 7); // mknwedge
    v_31306 = (*qfn1(fn))(fn, v_31306);
    env = stack[-4];
    fn = elt(env, 8); // xdegreecheck
    v_31306 = (*qfn1(fn))(fn, v_31306);
    env = stack[-4];
    if (v_31306 == nil) goto v_31270;
    else goto v_31271;
v_31270:
    goto v_31284;
v_31276:
    goto v_31277;
v_31278:
    stack[0] = elt(env, 3); // wedge_pair
    goto v_31279;
v_31280:
    goto v_31295;
v_31289:
    v_31308 = stack[-2];
    goto v_31290;
v_31291:
    v_31307 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31292;
v_31293:
    v_31306 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31294;
v_31295:
    goto v_31289;
v_31290:
    goto v_31291;
v_31292:
    goto v_31293;
v_31294:
    v_31306 = list2star(v_31308, v_31307, v_31306);
    env = stack[-4];
    v_31307 = ncons(v_31306);
    goto v_31281;
v_31282:
    v_31306 = stack[-1];
    goto v_31283;
v_31284:
    goto v_31276;
v_31277:
    goto v_31278;
v_31279:
    goto v_31280;
v_31281:
    goto v_31282;
v_31283:
    {
        LispObject v_31313 = stack[-3];
        LispObject v_31314 = stack[0];
        return list4(v_31313, v_31314, v_31307, v_31306);
    }
v_31271:
    v_31306 = nil;
    goto v_31269;
    v_31306 = nil;
v_31269:
    goto v_31257;
v_31259:
    v_31306 = nil;
    goto v_31257;
    v_31306 = nil;
v_31257:
    goto v_31235;
    v_31306 = nil;
v_31235:
    return onevalue(v_31306);
}



// Code for decimal2internal

static LispObject CC_decimal2internal(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31275, v_31276, v_31277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    goto v_31226;
v_31222:
    v_31276 = stack[0];
    goto v_31223;
v_31224:
    v_31275 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31225;
v_31226:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    v_31275 = (LispObject)geq2(v_31276, v_31275);
    v_31275 = v_31275 ? lisp_true : nil;
    env = stack[-3];
    if (v_31275 == nil) goto v_31220;
    goto v_31236;
v_31230:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_31231;
v_31232:
    goto v_31243;
v_31239:
    goto v_31240;
v_31241:
    goto v_31250;
v_31246:
    v_31276 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_31247;
v_31248:
    v_31275 = stack[0];
    goto v_31249;
v_31250:
    goto v_31246;
v_31247:
    goto v_31248;
v_31249:
    v_31275 = Lexpt(nil, v_31276, v_31275);
    env = stack[-3];
    goto v_31242;
v_31243:
    goto v_31239;
v_31240:
    goto v_31241;
v_31242:
    v_31276 = times2(stack[-1], v_31275);
    goto v_31233;
v_31234:
    v_31275 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31235;
v_31236:
    goto v_31230;
v_31231:
    goto v_31232;
v_31233:
    goto v_31234;
v_31235:
    {
        LispObject v_31281 = stack[-2];
        return list2star(v_31281, v_31276, v_31275);
    }
v_31220:
    goto v_31261;
v_31257:
    goto v_31269;
v_31263:
    v_31277 = elt(env, 1); // !:rd!:
    goto v_31264;
v_31265:
    v_31276 = stack[-1];
    goto v_31266;
v_31267:
    v_31275 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31268;
v_31269:
    goto v_31263;
v_31264:
    goto v_31265;
v_31266:
    goto v_31267;
v_31268:
    stack[-1] = list2star(v_31277, v_31276, v_31275);
    env = stack[-3];
    goto v_31258;
v_31259:
    v_31275 = stack[0];
    v_31275 = negate(v_31275);
    env = stack[-3];
    goto v_31260;
v_31261:
    goto v_31257;
v_31258:
    goto v_31259;
v_31260:
    {
        LispObject v_31282 = stack[-1];
        fn = elt(env, 2); // divide!-by!-power!-of!-ten
        return (*qfn2(fn))(fn, v_31282, v_31275);
    }
    v_31275 = nil;
    return onevalue(v_31275);
}



// Code for gpexpp

static LispObject CC_gpexpp(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31451, v_31452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31214;
// end of prologue
v_31219:
    v_31451 = stack[0];
    if (!consp(v_31451)) goto v_31222;
    else goto v_31223;
v_31222:
    v_31451 = stack[0];
    v_31451 = Lsymbolp(nil, v_31451);
    v_31452 = v_31451;
    if (v_31451 == nil) goto v_31228;
    v_31451 = v_31452;
    goto v_31218;
v_31228:
    v_31451 = stack[0];
    v_31451 = (is_number(v_31451) ? lisp_true : nil);
    v_31452 = v_31451;
    if (v_31451 == nil) goto v_31233;
    v_31451 = v_31452;
    goto v_31218;
v_31233:
    v_31451 = nil;
    goto v_31218;
    goto v_31221;
v_31223:
    goto v_31246;
v_31242:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31243;
v_31244:
    v_31451 = elt(env, 1); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    goto v_31245;
v_31246:
    goto v_31242;
v_31243:
    goto v_31244;
v_31245:
    v_31451 = Lmemq(nil, v_31452, v_31451);
    if (v_31451 == nil) goto v_31241;
    v_31451 = lisp_true;
    goto v_31218;
v_31241:
    goto v_31258;
v_31254:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31255;
v_31256:
    v_31451 = elt(env, 2); // plus
    goto v_31257;
v_31258:
    goto v_31254;
v_31255:
    goto v_31256;
v_31257:
    if (v_31452 == v_31451) goto v_31252;
    else goto v_31253;
v_31252:
    goto v_31271;
v_31267:
    v_31451 = stack[0];
    v_31452 = Llength(nil, v_31451);
    env = stack[-1];
    goto v_31268;
v_31269:
    v_31451 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31270;
v_31271:
    goto v_31267;
v_31268:
    goto v_31269;
v_31270:
    v_31451 = (LispObject)geq2(v_31452, v_31451);
    v_31451 = v_31451 ? lisp_true : nil;
    env = stack[-1];
    if (v_31451 == nil) goto v_31265;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    v_31451 = CC_gpexpp(elt(env, 0), v_31451);
    env = stack[-1];
    if (v_31451 == nil) goto v_31278;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcdr(v_31451);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_31451);
    }
v_31278:
    v_31451 = nil;
    goto v_31218;
    goto v_31263;
v_31265:
    v_31451 = nil;
    goto v_31218;
v_31263:
    goto v_31221;
v_31253:
    goto v_31299;
v_31295:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31296;
v_31297:
    v_31451 = elt(env, 3); // (minus recip)
    goto v_31298;
v_31299:
    goto v_31295;
v_31296:
    goto v_31297;
v_31298:
    v_31451 = Lmemq(nil, v_31452, v_31451);
    if (v_31451 == nil) goto v_31294;
    goto v_31312;
v_31308:
    v_31451 = stack[0];
    v_31452 = Llength(nil, v_31451);
    env = stack[-1];
    goto v_31309;
v_31310:
    v_31451 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31311;
v_31312:
    goto v_31308;
v_31309:
    goto v_31310;
v_31311:
    if (v_31452 == v_31451) goto v_31306;
    else goto v_31307;
v_31306:
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    stack[0] = v_31451;
    goto v_31219;
v_31307:
    v_31451 = nil;
    goto v_31218;
    goto v_31221;
v_31294:
    goto v_31328;
v_31324:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31325;
v_31326:
    v_31451 = elt(env, 4); // (difference quotient expt)
    goto v_31327;
v_31328:
    goto v_31324;
v_31325:
    goto v_31326;
v_31327:
    v_31451 = Lmemq(nil, v_31452, v_31451);
    if (v_31451 == nil) goto v_31323;
    goto v_31341;
v_31337:
    v_31451 = stack[0];
    v_31452 = Llength(nil, v_31451);
    env = stack[-1];
    goto v_31338;
v_31339:
    v_31451 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31340;
v_31341:
    goto v_31337;
v_31338:
    goto v_31339;
v_31340:
    if (v_31452 == v_31451) goto v_31335;
    else goto v_31336;
v_31335:
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    v_31451 = CC_gpexpp(elt(env, 0), v_31451);
    env = stack[-1];
    if (v_31451 == nil) goto v_31348;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    stack[0] = v_31451;
    goto v_31219;
v_31348:
    v_31451 = nil;
    goto v_31218;
    goto v_31334;
v_31336:
    v_31451 = nil;
    goto v_31218;
v_31334:
    goto v_31221;
v_31323:
    goto v_31369;
v_31365:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31366;
v_31367:
    v_31451 = elt(env, 5); // times
    goto v_31368;
v_31369:
    goto v_31365;
v_31366:
    goto v_31367;
v_31368:
    if (v_31452 == v_31451) goto v_31363;
    else goto v_31364;
v_31363:
    goto v_31382;
v_31378:
    v_31451 = stack[0];
    v_31452 = Llength(nil, v_31451);
    env = stack[-1];
    goto v_31379;
v_31380:
    v_31451 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31381;
v_31382:
    goto v_31378;
v_31379:
    goto v_31380;
v_31381:
    v_31451 = (LispObject)geq2(v_31452, v_31451);
    v_31451 = v_31451 ? lisp_true : nil;
    env = stack[-1];
    if (v_31451 == nil) goto v_31376;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    v_31451 = CC_gpexpp(elt(env, 0), v_31451);
    env = stack[-1];
    if (v_31451 == nil) goto v_31389;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcdr(v_31451);
    v_31451 = qcar(v_31451);
    v_31451 = CC_gpexpp(elt(env, 0), v_31451);
    env = stack[-1];
    if (v_31451 == nil) goto v_31397;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    v_31451 = qcdr(v_31451);
    v_31451 = qcdr(v_31451);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_31451);
    }
v_31397:
    v_31451 = nil;
    goto v_31218;
    goto v_31387;
v_31389:
    v_31451 = nil;
    goto v_31218;
v_31387:
    goto v_31374;
v_31376:
    v_31451 = nil;
    goto v_31218;
v_31374:
    goto v_31221;
v_31364:
    goto v_31423;
v_31419:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31420;
v_31421:
    v_31451 = elt(env, 6); // !:rd!:
    goto v_31422;
v_31423:
    goto v_31419;
v_31420:
    goto v_31421;
v_31422:
    if (v_31452 == v_31451) goto v_31417;
    else goto v_31418;
v_31417:
    v_31451 = lisp_true;
    goto v_31218;
v_31418:
    goto v_31434;
v_31430:
    v_31451 = stack[0];
    v_31452 = qcar(v_31451);
    goto v_31431;
v_31432:
    v_31451 = elt(env, 7); // (!:cr!: !:crn!: !:gi!:)
    goto v_31433;
v_31434:
    goto v_31430;
v_31431:
    goto v_31432;
v_31433:
    v_31451 = Lmemq(nil, v_31452, v_31451);
    if (v_31451 == nil) goto v_31429;
    v_31451 = lisp_true;
    goto v_31218;
v_31429:
    v_31451 = stack[0];
    v_31451 = qcar(v_31451);
    fn = elt(env, 9); // unresidp
    v_31451 = (*qfn1(fn))(fn, v_31451);
    env = stack[-1];
    if (v_31451 == nil) goto v_31441;
    v_31451 = stack[0];
    v_31451 = qcdr(v_31451);
    {
        fn = elt(env, 10); // gparg1p
        return (*qfn1(fn))(fn, v_31451);
    }
v_31441:
    v_31451 = nil;
    goto v_31218;
v_31221:
    v_31451 = nil;
v_31218:
    return onevalue(v_31451);
}



// Code for rule!-list

static LispObject CC_ruleKlist(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31415, v_31416, v_31417, v_31418, v_31419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31215;
    stack[-2] = v_31214;
// end of prologue
v_31223:
    v_31415 = nil;
    qvalue(elt(env, 2)) = v_31415; // frasc!*
    v_31415 = stack[-2];
    if (v_31415 == nil) goto v_31232;
    else goto v_31233;
v_31232:
    v_31415 = lisp_true;
    goto v_31231;
v_31233:
    goto v_31242;
v_31238:
    stack[0] = stack[-2];
    goto v_31239;
v_31240:
    v_31415 = nil;
    v_31415 = ncons(v_31415);
    env = stack[-4];
    goto v_31241;
v_31242:
    goto v_31238;
v_31239:
    goto v_31240;
v_31241:
    v_31415 = (equal(stack[0], v_31415) ? lisp_true : nil);
    goto v_31231;
    v_31415 = nil;
v_31231:
    if (v_31415 == nil) goto v_31229;
    v_31415 = nil;
    qvalue(elt(env, 3)) = v_31415; // mcond!*
    goto v_31222;
v_31229:
    v_31415 = lisp_true;
    qvalue(elt(env, 3)) = v_31415; // mcond!*
    v_31415 = stack[-2];
    v_31415 = qcar(v_31415);
    stack[-3] = v_31415;
    v_31415 = stack[-3];
    if (symbolp(v_31415)) goto v_31253;
    else goto v_31254;
v_31253:
    v_31415 = stack[-3];
    if (!symbolp(v_31415)) v_31415 = nil;
    else { v_31415 = qfastgets(v_31415);
           if (v_31415 != nil) { v_31415 = elt(v_31415, 4); // avalue
#ifdef RECORD_GET
             if (v_31415 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_31415 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_31415 == SPID_NOPROP) v_31415 = nil; }}
#endif
    v_31417 = v_31415;
    if (v_31415 == nil) goto v_31259;
    goto v_31268;
v_31264:
    v_31415 = v_31417;
    v_31416 = qcar(v_31415);
    goto v_31265;
v_31266:
    v_31415 = elt(env, 4); // list
    goto v_31267;
v_31268:
    goto v_31264;
v_31265:
    goto v_31266;
v_31267:
    if (v_31416 == v_31415) goto v_31263;
    else goto v_31259;
v_31263:
    goto v_31277;
v_31273:
    v_31415 = v_31417;
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    v_31415 = qcdr(v_31415);
    v_31416 = Lreverse(nil, v_31415);
    env = stack[-4];
    goto v_31274;
v_31275:
    v_31415 = stack[-2];
    v_31415 = qcdr(v_31415);
    goto v_31276;
v_31277:
    goto v_31273;
v_31274:
    goto v_31275;
v_31276:
    v_31415 = Lappend(nil, v_31416, v_31415);
    env = stack[-4];
    stack[-2] = v_31415;
    goto v_31223;
v_31259:
    goto v_31292;
v_31288:
    v_31416 = stack[-3];
    goto v_31289;
v_31290:
    v_31415 = elt(env, 5); // "rule list"
    goto v_31291;
v_31292:
    goto v_31288;
v_31289:
    goto v_31290;
v_31291:
    fn = elt(env, 12); // typerr
    v_31415 = (*qfn2(fn))(fn, v_31416, v_31415);
    env = stack[-4];
    goto v_31257;
v_31257:
    goto v_31252;
v_31254:
    goto v_31301;
v_31297:
    v_31415 = stack[-3];
    v_31416 = qcar(v_31415);
    goto v_31298;
v_31299:
    v_31415 = elt(env, 4); // list
    goto v_31300;
v_31301:
    goto v_31297;
v_31298:
    goto v_31299;
v_31300:
    if (v_31416 == v_31415) goto v_31295;
    else goto v_31296;
v_31295:
    goto v_31310;
v_31306:
    v_31415 = stack[-3];
    v_31416 = qcdr(v_31415);
    goto v_31307;
v_31308:
    v_31415 = stack[-2];
    v_31415 = qcdr(v_31415);
    goto v_31309;
v_31310:
    goto v_31306;
v_31307:
    goto v_31308;
v_31309:
    v_31415 = Lappend(nil, v_31416, v_31415);
    env = stack[-4];
    stack[-2] = v_31415;
    goto v_31223;
v_31296:
    goto v_31321;
v_31317:
    v_31415 = stack[-3];
    v_31416 = qcar(v_31415);
    goto v_31318;
v_31319:
    v_31415 = elt(env, 6); // equal
    goto v_31320;
v_31321:
    goto v_31317;
v_31318:
    goto v_31319;
v_31320:
    if (v_31416 == v_31415) goto v_31315;
    else goto v_31316;
v_31315:
    v_31415 = elt(env, 7); // "Please use => instead of = in rules"
    fn = elt(env, 13); // lprim
    v_31415 = (*qfn1(fn))(fn, v_31415);
    env = stack[-4];
    goto v_31252;
v_31316:
    goto v_31333;
v_31329:
    v_31415 = stack[-3];
    v_31416 = qcar(v_31415);
    goto v_31330;
v_31331:
    v_31415 = elt(env, 8); // replaceby
    goto v_31332;
v_31333:
    goto v_31329;
v_31330:
    goto v_31331;
v_31332:
    if (v_31416 == v_31415) goto v_31328;
    goto v_31342;
v_31338:
    v_31416 = stack[-3];
    goto v_31339;
v_31340:
    v_31415 = elt(env, 9); // "rule"
    goto v_31341;
v_31342:
    goto v_31338;
v_31339:
    goto v_31340;
v_31341:
    fn = elt(env, 12); // typerr
    v_31415 = (*qfn2(fn))(fn, v_31416, v_31415);
    env = stack[-4];
    goto v_31252;
v_31328:
v_31252:
    v_31415 = stack[-3];
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    fn = elt(env, 14); // remove!-free!-vars
    v_31415 = (*qfn1(fn))(fn, v_31415);
    env = stack[-4];
    stack[0] = v_31415;
    goto v_31358;
v_31354:
    v_31415 = stack[-3];
    v_31415 = qcdr(v_31415);
    v_31415 = qcdr(v_31415);
    v_31416 = qcar(v_31415);
    goto v_31355;
v_31356:
    v_31415 = elt(env, 10); // when
    goto v_31357;
v_31358:
    goto v_31354;
v_31355:
    goto v_31356;
v_31357:
    if (!consp(v_31416)) goto v_31352;
    v_31416 = qcar(v_31416);
    if (v_31416 == v_31415) goto v_31351;
    else goto v_31352;
v_31351:
    goto v_31371;
v_31365:
    v_31415 = stack[-3];
    v_31415 = qcdr(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    fn = elt(env, 15); // remove!-free!-vars!*
    v_31417 = (*qfn1(fn))(fn, v_31415);
    env = stack[-4];
    goto v_31366;
v_31367:
    v_31416 = nil;
    goto v_31368;
v_31369:
    v_31415 = elt(env, 11); // algebraic
    goto v_31370;
v_31371:
    goto v_31365;
v_31366:
    goto v_31367;
v_31368:
    goto v_31369;
v_31370:
    fn = elt(env, 16); // formbool
    v_31415 = (*qfnn(fn))(fn, 3, v_31417, v_31416, v_31415);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_31415; // mcond!*
    v_31415 = stack[-3];
    v_31415 = qcdr(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    fn = elt(env, 15); // remove!-free!-vars!*
    v_31415 = (*qfn1(fn))(fn, v_31415);
    env = stack[-4];
    goto v_31350;
v_31352:
    v_31415 = stack[-3];
    v_31415 = qcdr(v_31415);
    v_31415 = qcdr(v_31415);
    v_31415 = qcar(v_31415);
    fn = elt(env, 15); // remove!-free!-vars!*
    v_31415 = (*qfn1(fn))(fn, v_31415);
    env = stack[-4];
    goto v_31350;
v_31350:
    goto v_31407;
v_31397:
    v_31419 = stack[0];
    goto v_31398;
v_31399:
    v_31418 = v_31415;
    goto v_31400;
v_31401:
    v_31417 = qvalue(elt(env, 2)); // frasc!*
    goto v_31402;
v_31403:
    v_31416 = qvalue(elt(env, 3)); // mcond!*
    goto v_31404;
v_31405:
    v_31415 = stack[-1];
    goto v_31406;
v_31407:
    goto v_31397;
v_31398:
    goto v_31399;
v_31400:
    goto v_31401;
v_31402:
    goto v_31403;
v_31404:
    goto v_31405;
v_31406:
    fn = elt(env, 17); // rule!*
    v_31415 = (*qfnn(fn))(fn, 5, v_31419, v_31418, v_31417, v_31416, v_31415);
    env = stack[-4];
    v_31415 = stack[-2];
    v_31415 = qcdr(v_31415);
    stack[-2] = v_31415;
    goto v_31223;
v_31222:
    return onevalue(v_31415);
}



// Code for even_action_pow

static LispObject CC_even_action_pow(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31380, v_31381, v_31382, v_31383;
    LispObject fn;
    LispObject v_31217, v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_pow");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    v_31217 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_31217,v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_31214,v_31215,v_31216,v_31217);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_31217;
    stack[-3] = v_31216;
    stack[-4] = v_31215;
    v_31383 = v_31214;
// end of prologue
    v_31380 = stack[-4];
    v_31380 = qcar(v_31380);
    v_31382 = v_31380;
    v_31380 = stack[-4];
    v_31380 = qcdr(v_31380);
    stack[-1] = v_31380;
    goto v_31240;
v_31236:
    v_31381 = v_31382;
    goto v_31237;
v_31238:
    v_31380 = v_31383;
    goto v_31239;
v_31240:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    v_31380 = Lassoc(nil, v_31381, v_31380);
    stack[0] = v_31380;
    if (v_31380 == nil) goto v_31235;
    goto v_31252;
v_31248:
    v_31381 = stack[-1];
    goto v_31249;
v_31250:
    v_31380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31251;
v_31252:
    goto v_31248;
v_31249:
    goto v_31250;
v_31251:
    if (v_31381 == v_31380) goto v_31246;
    else goto v_31247;
v_31246:
    goto v_31260;
v_31256:
    v_31381 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31257;
v_31258:
    v_31380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31259;
v_31260:
    goto v_31256;
v_31257:
    goto v_31258;
v_31259:
    v_31380 = cons(v_31381, v_31380);
    env = stack[-6];
    goto v_31245;
v_31247:
    goto v_31272;
v_31266:
    goto v_31278;
v_31274:
    goto v_31284;
v_31280:
    stack[-4] = v_31382;
    goto v_31281;
v_31282:
    v_31380 = stack[-1];
    v_31380 = sub1(v_31380);
    env = stack[-6];
    goto v_31283;
v_31284:
    goto v_31280;
v_31281:
    goto v_31282;
v_31283:
    fn = elt(env, 2); // to
    v_31381 = (*qfn2(fn))(fn, stack[-4], v_31380);
    env = stack[-6];
    goto v_31275;
v_31276:
    v_31380 = stack[-1];
    goto v_31277;
v_31278:
    goto v_31274;
v_31275:
    goto v_31276;
v_31277:
    v_31382 = cons(v_31381, v_31380);
    env = stack[-6];
    goto v_31267;
v_31268:
    v_31381 = nil;
    goto v_31269;
v_31270:
    v_31380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31271;
v_31272:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    v_31380 = acons(v_31382, v_31381, v_31380);
    env = stack[-6];
    goto v_31245;
    v_31380 = nil;
v_31245:
    goto v_31298;
v_31292:
    v_31382 = stack[0];
    goto v_31293;
v_31294:
    v_31381 = stack[-3];
    goto v_31295;
v_31296:
    goto v_31297;
v_31298:
    goto v_31292;
v_31293:
    goto v_31294;
v_31295:
    goto v_31296;
v_31297:
    fn = elt(env, 3); // component_action
    v_31380 = (*qfnn(fn))(fn, 3, v_31382, v_31381, v_31380);
    env = stack[-6];
    stack[0] = v_31380;
    goto v_31307;
v_31303:
    v_31381 = stack[0];
    goto v_31304;
v_31305:
    v_31380 = stack[-2];
    goto v_31306;
v_31307:
    goto v_31303;
v_31304:
    goto v_31305;
v_31306:
    {
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_31381, v_31380);
    }
v_31235:
    goto v_31317;
v_31311:
    v_31381 = v_31382;
    goto v_31312;
v_31313:
    v_31382 = v_31383;
    goto v_31314;
v_31315:
    v_31380 = nil;
    goto v_31316;
v_31317:
    goto v_31311;
v_31312:
    goto v_31313;
v_31314:
    goto v_31315;
v_31316:
    fn = elt(env, 5); // find_active_components
    v_31380 = (*qfnn(fn))(fn, 3, v_31381, v_31382, v_31380);
    env = stack[-6];
    stack[-1] = v_31380;
    goto v_31326;
v_31322:
    v_31381 = nil;
    goto v_31323;
v_31324:
    v_31380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31325;
v_31326:
    goto v_31322;
v_31323:
    goto v_31324;
v_31325:
    v_31380 = cons(v_31381, v_31380);
    env = stack[-6];
    stack[0] = v_31380;
    v_31380 = stack[-1];
    stack[-5] = v_31380;
v_31332:
    v_31380 = stack[-5];
    if (v_31380 == nil) goto v_31336;
    else goto v_31337;
v_31336:
    goto v_31331;
v_31337:
    v_31380 = stack[-5];
    v_31380 = qcar(v_31380);
    stack[-1] = v_31380;
    goto v_31348;
v_31344:
    v_31381 = stack[-4];
    goto v_31345;
v_31346:
    v_31380 = stack[-1];
    v_31380 = qcar(v_31380);
    goto v_31347;
v_31348:
    goto v_31344;
v_31345:
    goto v_31346;
v_31347:
    fn = elt(env, 6); // diffp
    v_31380 = (*qfn2(fn))(fn, v_31381, v_31380);
    env = stack[-6];
    goto v_31357;
v_31353:
    goto v_31354;
v_31355:
    goto v_31366;
v_31360:
    v_31382 = stack[-1];
    goto v_31361;
v_31362:
    v_31381 = stack[-3];
    goto v_31363;
v_31364:
    goto v_31365;
v_31366:
    goto v_31360;
v_31361:
    goto v_31362;
v_31363:
    goto v_31364;
v_31365:
    fn = elt(env, 3); // component_action
    v_31380 = (*qfnn(fn))(fn, 3, v_31382, v_31381, v_31380);
    env = stack[-6];
    goto v_31356;
v_31357:
    goto v_31353;
v_31354:
    goto v_31355;
v_31356:
    fn = elt(env, 7); // addsq
    v_31380 = (*qfn2(fn))(fn, stack[0], v_31380);
    env = stack[-6];
    stack[0] = v_31380;
    v_31380 = stack[-5];
    v_31380 = qcdr(v_31380);
    stack[-5] = v_31380;
    goto v_31332;
v_31331:
    goto v_31377;
v_31373:
    v_31381 = stack[0];
    goto v_31374;
v_31375:
    v_31380 = stack[-2];
    goto v_31376;
v_31377:
    goto v_31373;
v_31374:
    goto v_31375;
v_31376:
    {
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_31381, v_31380);
    }
    return onevalue(v_31380);
}



// Code for !*multsq

static LispObject CC_Hmultsq(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31421, v_31422;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_31215;
    stack[-3] = v_31214;
// end of prologue
    v_31421 = stack[-3];
    v_31421 = qcar(v_31421);
    if (v_31421 == nil) goto v_31223;
    else goto v_31224;
v_31223:
    v_31421 = lisp_true;
    goto v_31222;
v_31224:
    v_31421 = stack[-2];
    v_31421 = qcar(v_31421);
    v_31421 = (v_31421 == nil ? lisp_true : nil);
    goto v_31222;
    v_31421 = nil;
v_31222:
    if (v_31421 == nil) goto v_31220;
    goto v_31238;
v_31234:
    v_31422 = nil;
    goto v_31235;
v_31236:
    v_31421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31237;
v_31238:
    goto v_31234;
v_31235:
    goto v_31236;
v_31237:
    return cons(v_31422, v_31421);
v_31220:
    goto v_31251;
v_31247:
    v_31421 = stack[-3];
    v_31422 = qcdr(v_31421);
    goto v_31248;
v_31249:
    v_31421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31250;
v_31251:
    goto v_31247;
v_31248:
    goto v_31249;
v_31250:
    if (v_31422 == v_31421) goto v_31245;
    else goto v_31246;
v_31245:
    goto v_31259;
v_31255:
    v_31421 = stack[-2];
    v_31422 = qcdr(v_31421);
    goto v_31256;
v_31257:
    v_31421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31258;
v_31259:
    goto v_31255;
v_31256:
    goto v_31257;
v_31258:
    v_31421 = (v_31422 == v_31421 ? lisp_true : nil);
    goto v_31244;
v_31246:
    v_31421 = nil;
    goto v_31244;
    v_31421 = nil;
v_31244:
    if (v_31421 == nil) goto v_31242;
    goto v_31272;
v_31268:
    goto v_31278;
v_31274:
    v_31421 = stack[-3];
    v_31422 = qcar(v_31421);
    goto v_31275;
v_31276:
    v_31421 = stack[-2];
    v_31421 = qcar(v_31421);
    goto v_31277;
v_31278:
    goto v_31274;
v_31275:
    goto v_31276;
v_31277:
    fn = elt(env, 2); // !*multf
    v_31422 = (*qfn2(fn))(fn, v_31422, v_31421);
    goto v_31269;
v_31270:
    v_31421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31271;
v_31272:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    return cons(v_31422, v_31421);
v_31242:
    goto v_31297;
v_31293:
    v_31421 = stack[-3];
    v_31422 = qcar(v_31421);
    goto v_31294;
v_31295:
    v_31421 = stack[-2];
    v_31421 = qcdr(v_31421);
    goto v_31296;
v_31297:
    goto v_31293;
v_31294:
    goto v_31295;
v_31296:
    fn = elt(env, 3); // gcdf
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    stack[-4] = v_31421;
    goto v_31307;
v_31303:
    v_31421 = stack[-2];
    v_31422 = qcar(v_31421);
    goto v_31304;
v_31305:
    v_31421 = stack[-3];
    v_31421 = qcdr(v_31421);
    goto v_31306;
v_31307:
    goto v_31303;
v_31304:
    goto v_31305;
v_31306:
    fn = elt(env, 3); // gcdf
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    stack[-1] = v_31421;
    goto v_31317;
v_31313:
    goto v_31323;
v_31319:
    v_31421 = stack[-3];
    v_31422 = qcar(v_31421);
    goto v_31320;
v_31321:
    v_31421 = stack[-4];
    goto v_31322;
v_31323:
    goto v_31319;
v_31320:
    goto v_31321;
v_31322:
    fn = elt(env, 4); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    goto v_31314;
v_31315:
    goto v_31332;
v_31328:
    v_31421 = stack[-2];
    v_31422 = qcar(v_31421);
    goto v_31329;
v_31330:
    v_31421 = stack[-1];
    goto v_31331;
v_31332:
    goto v_31328;
v_31329:
    goto v_31330;
v_31331:
    fn = elt(env, 4); // quotf!-fail
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    goto v_31316;
v_31317:
    goto v_31313;
v_31314:
    goto v_31315;
v_31316:
    fn = elt(env, 2); // !*multf
    v_31421 = (*qfn2(fn))(fn, stack[0], v_31421);
    env = stack[-5];
    stack[0] = v_31421;
    goto v_31341;
v_31337:
    goto v_31347;
v_31343:
    v_31421 = stack[-3];
    v_31422 = qcdr(v_31421);
    goto v_31344;
v_31345:
    v_31421 = stack[-1];
    goto v_31346;
v_31347:
    goto v_31343;
v_31344:
    goto v_31345;
v_31346:
    fn = elt(env, 4); // quotf!-fail
    stack[-1] = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    goto v_31338;
v_31339:
    goto v_31356;
v_31352:
    v_31421 = stack[-2];
    v_31422 = qcdr(v_31421);
    goto v_31353;
v_31354:
    v_31421 = stack[-4];
    goto v_31355;
v_31356:
    goto v_31352;
v_31353:
    goto v_31354;
v_31355:
    fn = elt(env, 4); // quotf!-fail
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    goto v_31340;
v_31341:
    goto v_31337;
v_31338:
    goto v_31339;
v_31340:
    fn = elt(env, 2); // !*multf
    v_31421 = (*qfn2(fn))(fn, stack[-1], v_31421);
    env = stack[-5];
    stack[-4] = v_31421;
    v_31421 = stack[-4];
    fn = elt(env, 5); // minusf
    v_31421 = (*qfn1(fn))(fn, v_31421);
    env = stack[-5];
    if (v_31421 == nil) goto v_31363;
    v_31421 = stack[0];
    fn = elt(env, 6); // negf
    v_31421 = (*qfn1(fn))(fn, v_31421);
    env = stack[-5];
    stack[0] = v_31421;
    v_31421 = stack[-4];
    fn = elt(env, 6); // negf
    v_31421 = (*qfn1(fn))(fn, v_31421);
    env = stack[-5];
    stack[-4] = v_31421;
    goto v_31361;
v_31363:
v_31361:
    goto v_31375;
v_31371:
    v_31422 = stack[0];
    goto v_31372;
v_31373:
    v_31421 = stack[-4];
    goto v_31374;
v_31375:
    goto v_31371;
v_31372:
    goto v_31373;
v_31374:
    fn = elt(env, 3); // gcdf
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    stack[-1] = v_31421;
    goto v_31386;
v_31382:
    v_31422 = stack[-1];
    goto v_31383;
v_31384:
    v_31421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31385;
v_31386:
    goto v_31382;
v_31383:
    goto v_31384;
v_31385:
    if (v_31422 == v_31421) goto v_31380;
    else goto v_31381;
v_31380:
    goto v_31394;
v_31390:
    v_31422 = stack[0];
    goto v_31391;
v_31392:
    v_31421 = stack[-4];
    goto v_31393;
v_31394:
    goto v_31390;
v_31391:
    goto v_31392;
v_31393:
    return cons(v_31422, v_31421);
v_31381:
    goto v_31404;
v_31400:
    goto v_31410;
v_31406:
    v_31422 = stack[0];
    goto v_31407;
v_31408:
    v_31421 = stack[-1];
    goto v_31409;
v_31410:
    goto v_31406;
v_31407:
    goto v_31408;
v_31409:
    fn = elt(env, 4); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_31422, v_31421);
    env = stack[-5];
    goto v_31401;
v_31402:
    goto v_31418;
v_31414:
    v_31422 = stack[-4];
    goto v_31415;
v_31416:
    v_31421 = stack[-1];
    goto v_31417;
v_31418:
    goto v_31414;
v_31415:
    goto v_31416;
v_31417:
    fn = elt(env, 4); // quotf!-fail
    v_31421 = (*qfn2(fn))(fn, v_31422, v_31421);
    goto v_31403;
v_31404:
    goto v_31400;
v_31401:
    goto v_31402;
v_31403:
    {
        LispObject v_31428 = stack[0];
        return cons(v_31428, v_31421);
    }
    v_31421 = nil;
    goto v_31218;
    v_31421 = nil;
v_31218:
    return onevalue(v_31421);
}



// Code for taymindegreel

static LispObject CC_taymindegreel(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31276, v_31277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31215;
    stack[-2] = v_31214;
// end of prologue
    stack[-3] = nil;
v_31220:
    v_31276 = stack[-2];
    if (v_31276 == nil) goto v_31223;
    else goto v_31224;
v_31223:
    v_31276 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31276);
    }
v_31224:
    goto v_31235;
v_31231:
    goto v_31241;
v_31237:
    v_31276 = stack[-2];
    v_31276 = qcar(v_31276);
    stack[0] = v_31276;
    v_31276 = (LispObject)0+TAG_FIXNUM; // 0
    v_31277 = v_31276;
v_31246:
    v_31276 = stack[0];
    if (v_31276 == nil) goto v_31252;
    else goto v_31253;
v_31252:
    v_31276 = v_31277;
    v_31277 = v_31276;
    goto v_31245;
v_31253:
    goto v_31261;
v_31257:
    v_31276 = stack[0];
    v_31276 = qcar(v_31276);
    goto v_31258;
v_31259:
    goto v_31260;
v_31261:
    goto v_31257;
v_31258:
    goto v_31259;
v_31260:
    fn = elt(env, 2); // tayexp!-plus2
    v_31276 = (*qfn2(fn))(fn, v_31276, v_31277);
    env = stack[-4];
    v_31277 = v_31276;
    v_31276 = stack[0];
    v_31276 = qcdr(v_31276);
    stack[0] = v_31276;
    goto v_31246;
v_31245:
    goto v_31238;
v_31239:
    v_31276 = stack[-1];
    v_31276 = qcar(v_31276);
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    fn = elt(env, 3); // tayexp!-min2
    v_31277 = (*qfn2(fn))(fn, v_31277, v_31276);
    env = stack[-4];
    goto v_31232;
v_31233:
    v_31276 = stack[-3];
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    v_31276 = cons(v_31277, v_31276);
    env = stack[-4];
    stack[-3] = v_31276;
    v_31276 = stack[-2];
    v_31276 = qcdr(v_31276);
    stack[-2] = v_31276;
    v_31276 = stack[-1];
    v_31276 = qcdr(v_31276);
    stack[-1] = v_31276;
    goto v_31220;
    v_31276 = nil;
    return onevalue(v_31276);
}



// Code for vdp_zero

static LispObject CC_vdp_zero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31226, v_31227, v_31228;
    LispObject fn;
    argcheck(nargs, 0, "vdp_zero");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_31222;
v_31216:
    v_31228 = elt(env, 1); // invalid
    goto v_31217;
v_31218:
    v_31227 = elt(env, 1); // invalid
    goto v_31219;
v_31220:
    v_31226 = nil;
    goto v_31221;
v_31222:
    goto v_31216;
v_31217:
    goto v_31218;
v_31219:
    goto v_31220;
v_31221:
    {
        fn = elt(env, 2); // vdp_make
        return (*qfnn(fn))(fn, 3, v_31228, v_31227, v_31226);
    }
}



// Code for ldf!-spf!-var

static LispObject CC_ldfKspfKvar(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31322, v_31323;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_31322 = v_31214;
// end of prologue
    v_31323 = nil;
    stack[-3] = nil;
    stack[-1] = v_31322;
v_31224:
    v_31322 = stack[-1];
    if (v_31322 == nil) goto v_31228;
    else goto v_31229;
v_31228:
    goto v_31223;
v_31229:
    v_31322 = stack[-1];
    v_31322 = qcar(v_31322);
    goto v_31240;
v_31236:
    stack[0] = v_31323;
    goto v_31237;
v_31238:
    v_31322 = qcdr(v_31322);
    fn = elt(env, 4); // kernels
    v_31322 = (*qfn1(fn))(fn, v_31322);
    env = stack[-4];
    goto v_31239;
v_31240:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    v_31322 = Lappend(nil, stack[0], v_31322);
    env = stack[-4];
    v_31323 = v_31322;
    v_31322 = stack[-1];
    v_31322 = qcdr(v_31322);
    stack[-1] = v_31322;
    goto v_31224;
v_31223:
    v_31322 = v_31323;
    fn = elt(env, 5); // makeset
    v_31322 = (*qfn1(fn))(fn, v_31322);
    env = stack[-4];
    fn = elt(env, 6); // prlist
    v_31322 = (*qfn1(fn))(fn, v_31322);
    env = stack[-4];
    stack[-2] = v_31322;
v_31250:
    v_31322 = stack[-2];
    if (v_31322 == nil) goto v_31256;
    else goto v_31257;
v_31256:
    goto v_31249;
v_31257:
    v_31322 = stack[-2];
    v_31322 = qcar(v_31322);
    stack[-1] = v_31322;
    goto v_31276;
v_31272:
    v_31323 = stack[-1];
    goto v_31273;
v_31274:
    v_31322 = elt(env, 2); // x
    goto v_31275;
v_31276:
    goto v_31272;
v_31273:
    goto v_31274;
v_31275:
    if (!consp(v_31323)) goto v_31269;
    v_31323 = qcar(v_31323);
    if (v_31323 == v_31322) goto v_31270;
v_31269:
    goto v_31284;
v_31280:
    v_31323 = stack[-1];
    goto v_31281;
v_31282:
    v_31322 = elt(env, 3); // u
    goto v_31283;
v_31284:
    goto v_31280;
v_31281:
    goto v_31282;
v_31283:
    v_31322 = Leqcar(nil, v_31323, v_31322);
    env = stack[-4];
    v_31322 = (v_31322 == nil ? lisp_true : nil);
    goto v_31268;
v_31270:
    v_31322 = nil;
    goto v_31268;
    v_31322 = nil;
v_31268:
    if (v_31322 == nil) goto v_31266;
    goto v_31298;
v_31292:
    goto v_31304;
v_31300:
    v_31323 = elt(env, 2); // x
    goto v_31301;
v_31302:
    v_31322 = stack[-1];
    v_31322 = qcdr(v_31322);
    goto v_31303;
v_31304:
    goto v_31300;
v_31301:
    goto v_31302;
v_31303:
    fn = elt(env, 7); // sacar
    stack[0] = (*qfn2(fn))(fn, v_31323, v_31322);
    env = stack[-4];
    goto v_31293;
v_31294:
    goto v_31313;
v_31309:
    v_31323 = elt(env, 3); // u
    goto v_31310;
v_31311:
    v_31322 = stack[-1];
    v_31322 = qcdr(v_31322);
    goto v_31312;
v_31313:
    goto v_31309;
v_31310:
    goto v_31311;
v_31312:
    fn = elt(env, 7); // sacar
    v_31323 = (*qfn2(fn))(fn, v_31323, v_31322);
    env = stack[-4];
    goto v_31295;
v_31296:
    v_31322 = stack[-3];
    goto v_31297;
v_31298:
    goto v_31292;
v_31293:
    goto v_31294;
v_31295:
    goto v_31296;
v_31297:
    fn = elt(env, 8); // appends
    v_31322 = (*qfnn(fn))(fn, 3, stack[0], v_31323, v_31322);
    env = stack[-4];
    stack[-3] = v_31322;
    goto v_31264;
v_31266:
v_31264:
    v_31322 = stack[-2];
    v_31322 = qcdr(v_31322);
    stack[-2] = v_31322;
    goto v_31250;
v_31249:
    v_31322 = stack[-3];
    {
        fn = elt(env, 5); // makeset
        return (*qfn1(fn))(fn, v_31322);
    }
    return onevalue(v_31322);
}



// Code for solvealgtrig01

static LispObject CC_solvealgtrig01(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31274, v_31275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
v_31220:
    v_31274 = stack[-1];
    if (!consp(v_31274)) goto v_31223;
    else goto v_31224;
v_31223:
    v_31274 = stack[0];
    goto v_31219;
v_31224:
    goto v_31233;
v_31229:
    v_31274 = stack[-1];
    v_31275 = qcar(v_31274);
    goto v_31230;
v_31231:
    v_31274 = elt(env, 1); // (sin cos tan cot sinh cosh tanh coth)
    goto v_31232;
v_31233:
    goto v_31229;
v_31230:
    goto v_31231;
v_31232:
    v_31274 = Lmemq(nil, v_31275, v_31274);
    if (v_31274 == nil) goto v_31228;
    v_31274 = stack[-1];
    v_31274 = qcdr(v_31274);
    v_31274 = qcar(v_31274);
    fn = elt(env, 2); // constant_exprp
    v_31274 = (*qfn1(fn))(fn, v_31274);
    env = stack[-3];
    if (v_31274 == nil) goto v_31241;
    v_31274 = stack[0];
    goto v_31219;
v_31241:
    goto v_31254;
v_31250:
    v_31274 = stack[-1];
    v_31274 = qcdr(v_31274);
    v_31274 = qcar(v_31274);
    v_31275 = ncons(v_31274);
    env = stack[-3];
    goto v_31251;
v_31252:
    v_31274 = stack[0];
    goto v_31253;
v_31254:
    goto v_31250;
v_31251:
    goto v_31252;
v_31253:
    {
        fn = elt(env, 3); // union
        return (*qfn2(fn))(fn, v_31275, v_31274);
    }
    goto v_31222;
v_31228:
    v_31274 = stack[-1];
    v_31274 = qcdr(v_31274);
    stack[-2] = v_31274;
    goto v_31269;
v_31265:
    v_31274 = stack[-1];
    v_31275 = qcar(v_31274);
    goto v_31266;
v_31267:
    v_31274 = stack[0];
    goto v_31268;
v_31269:
    goto v_31265;
v_31266:
    goto v_31267;
v_31268:
    v_31274 = CC_solvealgtrig01(elt(env, 0), v_31275, v_31274);
    env = stack[-3];
    stack[0] = v_31274;
    v_31274 = stack[-2];
    stack[-1] = v_31274;
    goto v_31220;
v_31222:
    v_31274 = nil;
v_31219:
    return onevalue(v_31274);
}



// Code for latexprint

static LispObject CC_latexprint(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31220;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31214;
// end of prologue
    fn = elt(env, 1); // prinlabegin
    v_31220 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_31220 = stack[0];
    fn = elt(env, 2); // latexprin
    v_31220 = (*qfn1(fn))(fn, v_31220);
    env = stack[-1];
    {
        fn = elt(env, 3); // prinlaend
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for is_buble

static LispObject CC_is_buble(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31261, v_31262;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    goto v_31223;
v_31219:
    v_31262 = stack[-1];
    goto v_31220;
v_31221:
    v_31261 = stack[0];
    goto v_31222;
v_31223:
    goto v_31219;
v_31220:
    goto v_31221;
v_31222:
    fn = elt(env, 1); // diff_vertex
    v_31261 = (*qfn2(fn))(fn, v_31262, v_31261);
    env = stack[-3];
    v_31261 = Llength(nil, v_31261);
    env = stack[-3];
    stack[-2] = v_31261;
    goto v_31236;
v_31232:
    v_31262 = stack[-2];
    goto v_31233;
v_31234:
    v_31261 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31235;
v_31236:
    goto v_31232;
v_31233:
    goto v_31234;
v_31235:
    v_31261 = (LispObject)geq2(v_31262, v_31261);
    v_31261 = v_31261 ? lisp_true : nil;
    env = stack[-3];
    if (v_31261 == nil) goto v_31230;
    v_31261 = nil;
    goto v_31228;
v_31230:
    goto v_31249;
v_31243:
    goto v_31255;
v_31251:
    v_31262 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31252;
v_31253:
    v_31261 = stack[-2];
    goto v_31254;
v_31255:
    goto v_31251;
v_31252:
    goto v_31253;
v_31254:
    stack[-2] = times2(v_31262, v_31261);
    env = stack[-3];
    goto v_31244;
v_31245:
    goto v_31246;
v_31247:
    v_31261 = stack[0];
    v_31261 = ncons(v_31261);
    goto v_31248;
v_31249:
    goto v_31243;
v_31244:
    goto v_31245;
v_31246:
    goto v_31247;
v_31248:
    {
        LispObject v_31266 = stack[-2];
        LispObject v_31267 = stack[-1];
        return list2star(v_31266, v_31267, v_31261);
    }
    v_31261 = nil;
v_31228:
    return onevalue(v_31261);
}



// Code for dp!=comp

static LispObject CC_dpMcomp(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31255, v_31256;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    stack[-2] = nil;
v_31220:
    v_31255 = stack[0];
    if (v_31255 == nil) goto v_31223;
    else goto v_31224;
v_31223:
    v_31255 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31255);
    }
v_31224:
    goto v_31235;
v_31231:
    v_31255 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_31255 = (*qfn1(fn))(fn, v_31255);
    env = stack[-3];
    fn = elt(env, 3); // mo_comp
    v_31256 = (*qfn1(fn))(fn, v_31255);
    env = stack[-3];
    goto v_31232;
v_31233:
    v_31255 = stack[-1];
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    v_31255 = Leqn(nil, v_31256, v_31255);
    env = stack[-3];
    if (v_31255 == nil) goto v_31229;
    goto v_31245;
v_31241:
    v_31255 = stack[0];
    v_31256 = qcar(v_31255);
    goto v_31242;
v_31243:
    v_31255 = stack[-2];
    goto v_31244;
v_31245:
    goto v_31241;
v_31242:
    goto v_31243;
v_31244:
    v_31255 = cons(v_31256, v_31255);
    env = stack[-3];
    stack[-2] = v_31255;
    v_31255 = stack[0];
    v_31255 = qcdr(v_31255);
    stack[0] = v_31255;
    goto v_31220;
v_31229:
    v_31255 = stack[0];
    v_31255 = qcdr(v_31255);
    stack[0] = v_31255;
    goto v_31220;
    v_31255 = nil;
    return onevalue(v_31255);
}



// Code for simpsqrt3

static LispObject CC_simpsqrt3(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31287, v_31288, v_31289;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31214;
// end of prologue
    goto v_31225;
v_31221:
    v_31288 = stack[0];
    goto v_31222;
v_31223:
    v_31287 = qvalue(elt(env, 2)); // listofallsqrts
    goto v_31224;
v_31225:
    goto v_31221;
v_31222:
    goto v_31223;
v_31224:
    v_31287 = Lassoc(nil, v_31288, v_31287);
    stack[-1] = v_31287;
    v_31287 = stack[-1];
    if (v_31287 == nil) goto v_31232;
    v_31287 = stack[-1];
    v_31287 = qcdr(v_31287);
    goto v_31218;
v_31232:
    goto v_31240;
v_31236:
    v_31288 = qvalue(elt(env, 3)); // listofnewsqrts
    goto v_31237;
v_31238:
    v_31287 = qvalue(elt(env, 4)); // knowntobeindep
    goto v_31239;
v_31240:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    v_31287 = Latsoc(nil, v_31288, v_31287);
    stack[-1] = v_31287;
    v_31287 = stack[-1];
    if (v_31287 == nil) goto v_31246;
    else goto v_31247;
v_31246:
    goto v_31219;
v_31247:
    goto v_31253;
v_31249:
    v_31288 = stack[0];
    goto v_31250;
v_31251:
    v_31287 = stack[-1];
    v_31287 = qcdr(v_31287);
    goto v_31252;
v_31253:
    goto v_31249;
v_31250:
    goto v_31251;
v_31252:
    v_31287 = Lassoc(nil, v_31288, v_31287);
    stack[-1] = v_31287;
    v_31287 = stack[-1];
    if (v_31287 == nil) goto v_31261;
    goto v_31268;
v_31264:
    v_31288 = stack[-1];
    goto v_31265;
v_31266:
    v_31287 = qvalue(elt(env, 2)); // listofallsqrts
    goto v_31267;
v_31268:
    goto v_31264;
v_31265:
    goto v_31266;
v_31267:
    v_31287 = cons(v_31288, v_31287);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_31287; // listofallsqrts
    v_31287 = stack[-1];
    v_31287 = qcdr(v_31287);
    goto v_31218;
v_31261:
v_31219:
    v_31287 = stack[0];
    fn = elt(env, 5); // actualsimpsqrt
    v_31287 = (*qfn1(fn))(fn, v_31287);
    env = stack[-2];
    stack[-1] = v_31287;
    goto v_31282;
v_31276:
    v_31289 = stack[0];
    goto v_31277;
v_31278:
    v_31288 = stack[-1];
    goto v_31279;
v_31280:
    v_31287 = qvalue(elt(env, 2)); // listofallsqrts
    goto v_31281;
v_31282:
    goto v_31276;
v_31277:
    goto v_31278;
v_31279:
    goto v_31280;
v_31281:
    v_31287 = acons(v_31289, v_31288, v_31287);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_31287; // listofallsqrts
    v_31287 = stack[-1];
v_31218:
    return onevalue(v_31287);
}



// Code for qroundup

static LispObject CC_qroundup(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31257, v_31258;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    goto v_31226;
v_31222:
    v_31258 = stack[-1];
    goto v_31223;
v_31224:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31225;
v_31226:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    v_31257 = (LispObject)lessp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-2];
    if (v_31257 == nil) goto v_31220;
    goto v_31235;
v_31231:
    v_31257 = stack[-1];
    v_31258 = negate(v_31257);
    env = stack[-2];
    goto v_31232;
v_31233:
    v_31257 = stack[0];
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    v_31257 = quot2(v_31258, v_31257);
    return negate(v_31257);
v_31220:
    goto v_31246;
v_31242:
    goto v_31252;
v_31248:
    goto v_31249;
v_31250:
    v_31257 = stack[0];
    v_31257 = sub1(v_31257);
    env = stack[-2];
    goto v_31251;
v_31252:
    goto v_31248;
v_31249:
    goto v_31250;
v_31251:
    v_31258 = plus2(stack[-1], v_31257);
    goto v_31243;
v_31244:
    v_31257 = stack[0];
    goto v_31245;
v_31246:
    goto v_31242;
v_31243:
    goto v_31244;
v_31245:
    return quot2(v_31258, v_31257);
    v_31257 = nil;
    return onevalue(v_31257);
}



// Code for ofsf_smmkatl!-and

static LispObject CC_ofsf_smmkatlKand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31368, v_31369, v_31370;
    LispObject fn;
    LispObject v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31214,v_31215,v_31216);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31216;
    v_31368 = v_31215;
    stack[-4] = v_31214;
// end of prologue
    v_31369 = qvalue(elt(env, 2)); // !*rlsipw
    if (v_31369 == nil) goto v_31228;
    else goto v_31229;
v_31228:
    v_31369 = qvalue(elt(env, 3)); // !*rlsipo
    goto v_31227;
v_31229:
    v_31369 = nil;
    goto v_31227;
    v_31369 = nil;
v_31227:
    if (v_31369 == nil) goto v_31225;
    goto v_31242;
v_31236:
    v_31370 = elt(env, 4); // and
    goto v_31237;
v_31238:
    v_31369 = v_31368;
    goto v_31239;
v_31240:
    v_31368 = stack[-3];
    goto v_31241;
v_31242:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    goto v_31240;
v_31241:
    {
        fn = elt(env, 5); // ofsf_irl2atl
        return (*qfnn(fn))(fn, 3, v_31370, v_31369, v_31368);
    }
v_31225:
    stack[-5] = v_31368;
v_31251:
    v_31368 = stack[-5];
    if (v_31368 == nil) goto v_31256;
    else goto v_31257;
v_31256:
    v_31368 = nil;
    goto v_31250;
v_31257:
    v_31368 = stack[-5];
    v_31368 = qcar(v_31368);
    goto v_31267;
v_31263:
    v_31369 = v_31368;
    v_31370 = qcar(v_31369);
    goto v_31264;
v_31265:
    v_31369 = stack[-4];
    goto v_31266;
v_31267:
    goto v_31263;
v_31264:
    goto v_31265;
v_31266:
    v_31369 = Latsoc(nil, v_31370, v_31369);
    v_31370 = v_31369;
    v_31369 = v_31370;
    if (v_31369 == nil) goto v_31274;
    else goto v_31275;
v_31274:
    goto v_31284;
v_31278:
    v_31369 = elt(env, 4); // and
    goto v_31279;
v_31280:
    v_31370 = v_31368;
    goto v_31281;
v_31282:
    v_31368 = stack[-3];
    goto v_31283;
v_31284:
    goto v_31278;
v_31279:
    goto v_31280;
v_31281:
    goto v_31282;
v_31283:
    fn = elt(env, 6); // ofsf_ir2atl
    v_31368 = (*qfnn(fn))(fn, 3, v_31369, v_31370, v_31368);
    env = stack[-6];
    goto v_31273;
v_31275:
    goto v_31297;
v_31291:
    goto v_31292;
v_31293:
    v_31369 = v_31368;
    goto v_31294;
v_31295:
    v_31368 = stack[-3];
    goto v_31296;
v_31297:
    goto v_31291;
v_31292:
    goto v_31293;
v_31294:
    goto v_31295;
v_31296:
    fn = elt(env, 7); // ofsf_smmkatl!-and1
    v_31368 = (*qfnn(fn))(fn, 3, v_31370, v_31369, v_31368);
    env = stack[-6];
    goto v_31273;
    v_31368 = nil;
v_31273:
    stack[-2] = v_31368;
    v_31368 = stack[-2];
    fn = elt(env, 8); // lastpair
    v_31368 = (*qfn1(fn))(fn, v_31368);
    env = stack[-6];
    stack[-1] = v_31368;
    v_31368 = stack[-5];
    v_31368 = qcdr(v_31368);
    stack[-5] = v_31368;
    v_31368 = stack[-1];
    if (!consp(v_31368)) goto v_31307;
    else goto v_31308;
v_31307:
    goto v_31251;
v_31308:
v_31252:
    v_31368 = stack[-5];
    if (v_31368 == nil) goto v_31312;
    else goto v_31313;
v_31312:
    v_31368 = stack[-2];
    goto v_31250;
v_31313:
    goto v_31321;
v_31317:
    stack[0] = stack[-1];
    goto v_31318;
v_31319:
    v_31368 = stack[-5];
    v_31368 = qcar(v_31368);
    goto v_31330;
v_31326:
    v_31369 = v_31368;
    v_31370 = qcar(v_31369);
    goto v_31327;
v_31328:
    v_31369 = stack[-4];
    goto v_31329;
v_31330:
    goto v_31326;
v_31327:
    goto v_31328;
v_31329:
    v_31369 = Latsoc(nil, v_31370, v_31369);
    v_31370 = v_31369;
    v_31369 = v_31370;
    if (v_31369 == nil) goto v_31337;
    else goto v_31338;
v_31337:
    goto v_31347;
v_31341:
    v_31370 = elt(env, 4); // and
    goto v_31342;
v_31343:
    v_31369 = v_31368;
    goto v_31344;
v_31345:
    v_31368 = stack[-3];
    goto v_31346;
v_31347:
    goto v_31341;
v_31342:
    goto v_31343;
v_31344:
    goto v_31345;
v_31346:
    fn = elt(env, 6); // ofsf_ir2atl
    v_31368 = (*qfnn(fn))(fn, 3, v_31370, v_31369, v_31368);
    env = stack[-6];
    goto v_31336;
v_31338:
    goto v_31360;
v_31354:
    goto v_31355;
v_31356:
    v_31369 = v_31368;
    goto v_31357;
v_31358:
    v_31368 = stack[-3];
    goto v_31359;
v_31360:
    goto v_31354;
v_31355:
    goto v_31356;
v_31357:
    goto v_31358;
v_31359:
    fn = elt(env, 7); // ofsf_smmkatl!-and1
    v_31368 = (*qfnn(fn))(fn, 3, v_31370, v_31369, v_31368);
    env = stack[-6];
    goto v_31336;
    v_31368 = nil;
v_31336:
    goto v_31320;
v_31321:
    goto v_31317;
v_31318:
    goto v_31319;
v_31320:
    v_31368 = Lrplacd(nil, stack[0], v_31368);
    env = stack[-6];
    v_31368 = stack[-1];
    fn = elt(env, 8); // lastpair
    v_31368 = (*qfn1(fn))(fn, v_31368);
    env = stack[-6];
    stack[-1] = v_31368;
    v_31368 = stack[-5];
    v_31368 = qcdr(v_31368);
    stack[-5] = v_31368;
    goto v_31252;
v_31250:
    return onevalue(v_31368);
}



// Code for ofsf_smwrmknowl

static LispObject CC_ofsf_smwrmknowl(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31240, v_31241, v_31242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31241 = v_31215;
    v_31242 = v_31214;
// end of prologue
    v_31240 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_31240 == nil) goto v_31220;
    goto v_31227;
v_31223:
    v_31240 = v_31242;
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    goto v_31223;
v_31224:
    goto v_31225;
v_31226:
    {
        fn = elt(env, 2); // ofsf_susirmknowl
        return (*qfn2(fn))(fn, v_31240, v_31241);
    }
v_31220:
    goto v_31237;
v_31233:
    v_31240 = v_31242;
    goto v_31234;
v_31235:
    goto v_31236;
v_31237:
    goto v_31233;
v_31234:
    goto v_31235;
v_31236:
    {
        fn = elt(env, 3); // ofsf_smrmknowl
        return (*qfn2(fn))(fn, v_31240, v_31241);
    }
    v_31240 = nil;
    return onevalue(v_31240);
}



// Code for ofsf_smmkatl!-or

static LispObject CC_ofsf_smmkatlKor(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31344, v_31345, v_31346;
    LispObject fn;
    LispObject v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31214,v_31215,v_31216);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31216;
    v_31344 = v_31215;
    stack[-4] = v_31214;
// end of prologue
    stack[-5] = v_31344;
v_31227:
    v_31344 = stack[-5];
    if (v_31344 == nil) goto v_31232;
    else goto v_31233;
v_31232:
    v_31344 = nil;
    goto v_31226;
v_31233:
    v_31344 = stack[-5];
    v_31344 = qcar(v_31344);
    goto v_31243;
v_31239:
    v_31345 = v_31344;
    v_31346 = qcar(v_31345);
    goto v_31240;
v_31241:
    v_31345 = stack[-4];
    goto v_31242;
v_31243:
    goto v_31239;
v_31240:
    goto v_31241;
v_31242:
    v_31345 = Latsoc(nil, v_31346, v_31345);
    v_31346 = v_31345;
    v_31345 = v_31346;
    if (v_31345 == nil) goto v_31250;
    else goto v_31251;
v_31250:
    goto v_31260;
v_31254:
    v_31345 = elt(env, 2); // or
    goto v_31255;
v_31256:
    v_31346 = v_31344;
    goto v_31257;
v_31258:
    v_31344 = stack[-3];
    goto v_31259;
v_31260:
    goto v_31254;
v_31255:
    goto v_31256;
v_31257:
    goto v_31258;
v_31259:
    fn = elt(env, 3); // ofsf_ir2atl
    v_31344 = (*qfnn(fn))(fn, 3, v_31345, v_31346, v_31344);
    env = stack[-6];
    goto v_31249;
v_31251:
    goto v_31273;
v_31267:
    goto v_31268;
v_31269:
    v_31345 = v_31344;
    goto v_31270;
v_31271:
    v_31344 = stack[-3];
    goto v_31272;
v_31273:
    goto v_31267;
v_31268:
    goto v_31269;
v_31270:
    goto v_31271;
v_31272:
    fn = elt(env, 4); // ofsf_smmkatl!-or1
    v_31344 = (*qfnn(fn))(fn, 3, v_31346, v_31345, v_31344);
    env = stack[-6];
    goto v_31249;
    v_31344 = nil;
v_31249:
    stack[-2] = v_31344;
    v_31344 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_31344 = (*qfn1(fn))(fn, v_31344);
    env = stack[-6];
    stack[-1] = v_31344;
    v_31344 = stack[-5];
    v_31344 = qcdr(v_31344);
    stack[-5] = v_31344;
    v_31344 = stack[-1];
    if (!consp(v_31344)) goto v_31283;
    else goto v_31284;
v_31283:
    goto v_31227;
v_31284:
v_31228:
    v_31344 = stack[-5];
    if (v_31344 == nil) goto v_31288;
    else goto v_31289;
v_31288:
    v_31344 = stack[-2];
    goto v_31226;
v_31289:
    goto v_31297;
v_31293:
    stack[0] = stack[-1];
    goto v_31294;
v_31295:
    v_31344 = stack[-5];
    v_31344 = qcar(v_31344);
    goto v_31306;
v_31302:
    v_31345 = v_31344;
    v_31346 = qcar(v_31345);
    goto v_31303;
v_31304:
    v_31345 = stack[-4];
    goto v_31305;
v_31306:
    goto v_31302;
v_31303:
    goto v_31304;
v_31305:
    v_31345 = Latsoc(nil, v_31346, v_31345);
    v_31346 = v_31345;
    v_31345 = v_31346;
    if (v_31345 == nil) goto v_31313;
    else goto v_31314;
v_31313:
    goto v_31323;
v_31317:
    v_31346 = elt(env, 2); // or
    goto v_31318;
v_31319:
    v_31345 = v_31344;
    goto v_31320;
v_31321:
    v_31344 = stack[-3];
    goto v_31322;
v_31323:
    goto v_31317;
v_31318:
    goto v_31319;
v_31320:
    goto v_31321;
v_31322:
    fn = elt(env, 3); // ofsf_ir2atl
    v_31344 = (*qfnn(fn))(fn, 3, v_31346, v_31345, v_31344);
    env = stack[-6];
    goto v_31312;
v_31314:
    goto v_31336;
v_31330:
    goto v_31331;
v_31332:
    v_31345 = v_31344;
    goto v_31333;
v_31334:
    v_31344 = stack[-3];
    goto v_31335;
v_31336:
    goto v_31330;
v_31331:
    goto v_31332;
v_31333:
    goto v_31334;
v_31335:
    fn = elt(env, 4); // ofsf_smmkatl!-or1
    v_31344 = (*qfnn(fn))(fn, 3, v_31346, v_31345, v_31344);
    env = stack[-6];
    goto v_31312;
    v_31344 = nil;
v_31312:
    goto v_31296;
v_31297:
    goto v_31293;
v_31294:
    goto v_31295;
v_31296:
    v_31344 = Lrplacd(nil, stack[0], v_31344);
    env = stack[-6];
    v_31344 = stack[-1];
    fn = elt(env, 5); // lastpair
    v_31344 = (*qfn1(fn))(fn, v_31344);
    env = stack[-6];
    stack[-1] = v_31344;
    v_31344 = stack[-5];
    v_31344 = qcdr(v_31344);
    stack[-5] = v_31344;
    goto v_31228;
v_31226:
    return onevalue(v_31344);
}



// Code for eval!-yetunknowntypeexpr

static LispObject CC_evalKyetunknowntypeexpr(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31371, v_31372;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_31215;
    stack[0] = v_31214;
// end of prologue
v_31213:
    v_31371 = stack[0];
    if (!consp(v_31371)) goto v_31219;
    else goto v_31220;
v_31219:
    v_31371 = stack[0];
    if (!symbolp(v_31371)) v_31371 = nil;
    else { v_31371 = qfastgets(v_31371);
           if (v_31371 != nil) { v_31371 = elt(v_31371, 4); // avalue
#ifdef RECORD_GET
             if (v_31371 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_31371 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_31371 == SPID_NOPROP) v_31371 = nil; }}
#endif
    v_31372 = v_31371;
    v_31371 = v_31372;
    if (v_31371 == nil) goto v_31228;
    goto v_31235;
v_31231:
    v_31371 = v_31372;
    v_31371 = qcdr(v_31371);
    v_31372 = qcar(v_31371);
    goto v_31232;
v_31233:
    v_31371 = stack[-4];
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    stack[0] = v_31372;
    stack[-4] = v_31371;
    goto v_31213;
v_31228:
    v_31371 = stack[0];
    goto v_31226;
    v_31371 = nil;
v_31226:
    goto v_31218;
v_31220:
    goto v_31253;
v_31249:
    v_31371 = stack[0];
    v_31372 = qcar(v_31371);
    goto v_31250;
v_31251:
    v_31371 = elt(env, 1); // !*sq
    goto v_31252;
v_31253:
    goto v_31249;
v_31250:
    goto v_31251;
v_31252:
    if (v_31372 == v_31371) goto v_31247;
    else goto v_31248;
v_31247:
    v_31371 = lisp_true;
    goto v_31246;
v_31248:
    v_31371 = stack[0];
    v_31371 = qcar(v_31371);
    if (!symbolp(v_31371)) v_31371 = nil;
    else { v_31371 = qfastgets(v_31371);
           if (v_31371 != nil) { v_31371 = elt(v_31371, 8); // dname
#ifdef RECORD_GET
             if (v_31371 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_31371 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_31371 == SPID_NOPROP) v_31371 = nil; }}
#endif
    if (v_31371 == nil) goto v_31262;
    else goto v_31261;
v_31262:
    goto v_31270;
v_31266:
    v_31371 = stack[0];
    v_31372 = qcar(v_31371);
    goto v_31267;
v_31268:
    v_31371 = elt(env, 2); // !:dn!:
    goto v_31269;
v_31270:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    v_31371 = (v_31372 == v_31371 ? lisp_true : nil);
v_31261:
    goto v_31246;
    v_31371 = nil;
v_31246:
    if (v_31371 == nil) goto v_31244;
    v_31371 = stack[0];
    goto v_31218;
v_31244:
    v_31371 = stack[0];
    v_31371 = qcar(v_31371);
    if (!symbolp(v_31371)) v_31371 = nil;
    else { v_31371 = qfastgets(v_31371);
           if (v_31371 != nil) { v_31371 = elt(v_31371, 45); // psopfn
#ifdef RECORD_GET
             if (v_31371 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_31371 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_31371 == SPID_NOPROP) v_31371 = nil; }}
#endif
    stack[-1] = v_31371;
    v_31371 = stack[-1];
    if (v_31371 == nil) goto v_31285;
    goto v_31293;
v_31289:
    v_31371 = stack[0];
    fn = elt(env, 4); // getrtype
    v_31372 = (*qfn1(fn))(fn, v_31371);
    env = stack[-6];
    goto v_31290;
v_31291:
    v_31371 = elt(env, 3); // yetunknowntype
    goto v_31292;
v_31293:
    goto v_31289;
v_31290:
    goto v_31291;
v_31292:
    if (v_31372 == v_31371) goto v_31288;
    else goto v_31285;
v_31288:
    goto v_31302;
v_31298:
    v_31372 = stack[-1];
    goto v_31299;
v_31300:
    v_31371 = stack[0];
    v_31371 = qcdr(v_31371);
    goto v_31301;
v_31302:
    goto v_31298;
v_31299:
    goto v_31300;
v_31301:
        return Lapply1(nil, v_31372, v_31371);
v_31285:
    goto v_31313;
v_31309:
    v_31371 = stack[0];
    stack[-5] = qcar(v_31371);
    goto v_31310;
v_31311:
    v_31371 = stack[0];
    v_31371 = qcdr(v_31371);
    stack[-3] = v_31371;
    v_31371 = stack[-3];
    if (v_31371 == nil) goto v_31326;
    else goto v_31327;
v_31326:
    v_31371 = nil;
    goto v_31320;
v_31327:
    v_31371 = stack[-3];
    v_31371 = qcar(v_31371);
    goto v_31339;
v_31335:
    v_31372 = v_31371;
    goto v_31336;
v_31337:
    v_31371 = stack[-4];
    goto v_31338;
v_31339:
    goto v_31335;
v_31336:
    goto v_31337;
v_31338:
    v_31371 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_31372, v_31371);
    env = stack[-6];
    v_31371 = ncons(v_31371);
    env = stack[-6];
    stack[-1] = v_31371;
    stack[-2] = v_31371;
v_31321:
    v_31371 = stack[-3];
    v_31371 = qcdr(v_31371);
    stack[-3] = v_31371;
    v_31371 = stack[-3];
    if (v_31371 == nil) goto v_31346;
    else goto v_31347;
v_31346:
    v_31371 = stack[-2];
    goto v_31320;
v_31347:
    goto v_31355;
v_31351:
    stack[0] = stack[-1];
    goto v_31352;
v_31353:
    v_31371 = stack[-3];
    v_31371 = qcar(v_31371);
    goto v_31366;
v_31362:
    v_31372 = v_31371;
    goto v_31363;
v_31364:
    v_31371 = stack[-4];
    goto v_31365;
v_31366:
    goto v_31362;
v_31363:
    goto v_31364;
v_31365:
    v_31371 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_31372, v_31371);
    env = stack[-6];
    v_31371 = ncons(v_31371);
    env = stack[-6];
    goto v_31354;
v_31355:
    goto v_31351;
v_31352:
    goto v_31353;
v_31354:
    v_31371 = Lrplacd(nil, stack[0], v_31371);
    env = stack[-6];
    v_31371 = stack[-1];
    v_31371 = qcdr(v_31371);
    stack[-1] = v_31371;
    goto v_31321;
v_31320:
    goto v_31312;
v_31313:
    goto v_31309;
v_31310:
    goto v_31311;
v_31312:
    {
        LispObject v_31379 = stack[-5];
        return cons(v_31379, v_31371);
    }
    v_31371 = nil;
    goto v_31218;
    v_31371 = nil;
v_31218:
    return onevalue(v_31371);
}



// Code for division!-test

static LispObject CC_divisionKtest(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31242, v_31243;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
v_31219:
    v_31242 = stack[0];
    if (v_31242 == nil) goto v_31222;
    else goto v_31223;
v_31222:
    v_31242 = lisp_true;
    goto v_31218;
v_31223:
    goto v_31233;
v_31229:
    v_31242 = stack[0];
    v_31243 = qcar(v_31242);
    goto v_31230;
v_31231:
    v_31242 = stack[-1];
    goto v_31232;
v_31233:
    goto v_31229;
v_31230:
    goto v_31231;
v_31232:
    fn = elt(env, 1); // quotf
    v_31242 = (*qfn2(fn))(fn, v_31243, v_31242);
    env = stack[-2];
    if (v_31242 == nil) goto v_31226;
    else goto v_31227;
v_31226:
    v_31242 = nil;
    goto v_31218;
v_31227:
    v_31242 = stack[0];
    v_31242 = qcdr(v_31242);
    stack[0] = v_31242;
    goto v_31219;
    v_31242 = nil;
v_31218:
    return onevalue(v_31242);
}



// Code for vsl_boundtype1

static LispObject CC_vsl_boundtype1(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31264, v_31265, v_31266, v_31267;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31267 = v_31215;
    v_31266 = v_31214;
// end of prologue
v_31219:
    v_31264 = v_31266;
    if (!consp(v_31264)) goto v_31226;
    else goto v_31227;
v_31226:
    v_31264 = lisp_true;
    goto v_31225;
v_31227:
    v_31264 = v_31266;
    v_31264 = qcar(v_31264);
    v_31264 = (consp(v_31264) ? nil : lisp_true);
    goto v_31225;
    v_31264 = nil;
v_31225:
    if (v_31264 == nil) goto v_31223;
    v_31264 = nil;
    goto v_31218;
v_31223:
    goto v_31242;
v_31238:
    v_31264 = v_31266;
    v_31264 = qcar(v_31264);
    v_31264 = qcar(v_31264);
    v_31265 = qcar(v_31264);
    goto v_31239;
v_31240:
    v_31264 = v_31267;
    goto v_31241;
v_31242:
    goto v_31238;
v_31239:
    goto v_31240;
v_31241:
    if (v_31265 == v_31264) goto v_31236;
    else goto v_31237;
v_31236:
    v_31264 = v_31266;
    v_31264 = qcar(v_31264);
    v_31264 = qcdr(v_31264);
    fn = elt(env, 3); // minusf
    v_31264 = (*qfn1(fn))(fn, v_31264);
    env = stack[0];
    if (v_31264 == nil) goto v_31251;
    v_31264 = elt(env, 1); // ub
    goto v_31218;
v_31251:
    v_31264 = elt(env, 2); // lb
    goto v_31218;
    goto v_31221;
v_31237:
    v_31264 = v_31266;
    v_31264 = qcdr(v_31264);
    v_31266 = v_31264;
    goto v_31219;
v_31221:
    v_31264 = nil;
v_31218:
    return onevalue(v_31264);
}



// Code for ps!:value

static LispObject CC_psTvalue(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31265, v_31266, v_31267;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31267 = v_31214;
// end of prologue
    v_31265 = v_31267;
    if (!consp(v_31265)) goto v_31222;
    else goto v_31223;
v_31222:
    v_31265 = lisp_true;
    goto v_31221;
v_31223:
    goto v_31236;
v_31232:
    v_31265 = v_31267;
    v_31266 = qcar(v_31265);
    goto v_31233;
v_31234:
    v_31265 = elt(env, 1); // !:ps!:
    goto v_31235;
v_31236:
    goto v_31232;
v_31233:
    goto v_31234;
v_31235:
    if (v_31266 == v_31265) goto v_31231;
    v_31265 = v_31267;
    v_31265 = qcar(v_31265);
    if (!symbolp(v_31265)) v_31265 = nil;
    else { v_31265 = qfastgets(v_31265);
           if (v_31265 != nil) { v_31265 = elt(v_31265, 8); // dname
#ifdef RECORD_GET
             if (v_31265 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_31265 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_31265 == SPID_NOPROP) v_31265 = nil; }}
#endif
    goto v_31229;
v_31231:
    v_31265 = nil;
    goto v_31229;
    v_31265 = nil;
v_31229:
    goto v_31221;
    v_31265 = nil;
v_31221:
    if (v_31265 == nil) goto v_31219;
    v_31265 = v_31267;
    if (v_31265 == nil) goto v_31249;
    v_31265 = v_31267;
    goto v_31247;
v_31249:
    v_31265 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31247;
    v_31265 = nil;
v_31247:
    goto v_31217;
v_31219:
    goto v_31262;
v_31258:
    v_31266 = v_31267;
    goto v_31259;
v_31260:
    v_31265 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_31261;
v_31262:
    goto v_31258;
v_31259:
    goto v_31260;
v_31261:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_31266, v_31265);
    }
    v_31265 = nil;
v_31217:
    return onevalue(v_31265);
}



// Code for vdpfmon

static LispObject CC_vdpfmon(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31262;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_31215;
    v_31262 = v_31214;
// end of prologue
    goto v_31230;
v_31222:
    stack[-5] = elt(env, 2); // vdp
    goto v_31223;
v_31224:
    stack[-3] = stack[-4];
    goto v_31225;
v_31226:
    stack[-2] = v_31262;
    goto v_31227;
v_31228:
    goto v_31241;
v_31235:
    stack[-1] = stack[-4];
    goto v_31236;
v_31237:
    stack[0] = ncons(v_31262);
    env = stack[-6];
    goto v_31238;
v_31239:
    v_31262 = nil;
    v_31262 = ncons(v_31262);
    env = stack[-6];
    goto v_31240;
v_31241:
    goto v_31235;
v_31236:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    v_31262 = acons(stack[-1], stack[0], v_31262);
    env = stack[-6];
    goto v_31229;
v_31230:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    goto v_31228;
v_31229:
    v_31262 = list3star(stack[-5], stack[-3], stack[-2], v_31262);
    env = stack[-6];
    stack[-1] = v_31262;
    v_31262 = qvalue(elt(env, 3)); // !*gsugar
    if (v_31262 == nil) goto v_31250;
    goto v_31257;
v_31253:
    stack[0] = stack[-1];
    goto v_31254;
v_31255:
    v_31262 = stack[-4];
    fn = elt(env, 4); // vevtdeg
    v_31262 = (*qfn1(fn))(fn, v_31262);
    env = stack[-6];
    goto v_31256;
v_31257:
    goto v_31253;
v_31254:
    goto v_31255;
v_31256:
    fn = elt(env, 5); // gsetsugar
    v_31262 = (*qfn2(fn))(fn, stack[0], v_31262);
    goto v_31248;
v_31250:
v_31248:
    v_31262 = stack[-1];
    return onevalue(v_31262);
}



// Code for xexptpf

static LispObject CC_xexptpf(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31263, v_31264;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    stack[-2] = nil;
v_31221:
    goto v_31232;
v_31228:
    v_31264 = stack[0];
    goto v_31229;
v_31230:
    v_31263 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31231;
v_31232:
    goto v_31228;
v_31229:
    goto v_31230;
v_31231:
    if (v_31264 == v_31263) goto v_31226;
    else goto v_31227;
v_31226:
    goto v_31222;
v_31227:
    goto v_31240;
v_31236:
    v_31264 = stack[-1];
    goto v_31237;
v_31238:
    v_31263 = stack[-2];
    goto v_31239;
v_31240:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    v_31263 = cons(v_31264, v_31263);
    env = stack[-3];
    stack[-2] = v_31263;
    v_31263 = stack[0];
    v_31263 = sub1(v_31263);
    env = stack[-3];
    stack[0] = v_31263;
    goto v_31221;
v_31222:
    v_31263 = stack[-1];
    v_31264 = v_31263;
v_31223:
    v_31263 = stack[-2];
    if (v_31263 == nil) goto v_31248;
    else goto v_31249;
v_31248:
    v_31263 = v_31264;
    goto v_31220;
v_31249:
    goto v_31257;
v_31253:
    v_31263 = stack[-2];
    v_31263 = qcar(v_31263);
    goto v_31254;
v_31255:
    goto v_31256;
v_31257:
    goto v_31253;
v_31254:
    goto v_31255;
v_31256:
    fn = elt(env, 1); // wedgepf
    v_31263 = (*qfn2(fn))(fn, v_31263, v_31264);
    env = stack[-3];
    v_31264 = v_31263;
    v_31263 = stack[-2];
    v_31263 = qcdr(v_31263);
    stack[-2] = v_31263;
    goto v_31223;
v_31220:
    return onevalue(v_31263);
}



// Code for mk!-contract!-coeff

static LispObject CC_mkKcontractKcoeff(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31276, v_31277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_31214;
// end of prologue
    goto v_31224;
v_31220:
    v_31276 = stack[0];
    v_31276 = qcar(v_31276);
    v_31277 = qcar(v_31276);
    goto v_31221;
v_31222:
    v_31276 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31223;
v_31224:
    goto v_31220;
v_31221:
    goto v_31222;
v_31223:
    if (v_31277 == v_31276) goto v_31218;
    else goto v_31219;
v_31218:
    v_31276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31217;
v_31219:
    v_31276 = stack[0];
    v_31276 = qcar(v_31276);
    v_31276 = qcar(v_31276);
    stack[-3] = v_31276;
    v_31276 = stack[0];
    v_31276 = qcdr(v_31276);
    v_31276 = qcar(v_31276);
    v_31276 = Llength(nil, v_31276);
    env = stack[-4];
    v_31277 = v_31276;
    goto v_31252;
v_31248:
    v_31276 = stack[0];
    v_31276 = qcar(v_31276);
    v_31276 = qcdr(v_31276);
    stack[-2] = qcar(v_31276);
    goto v_31249;
v_31250:
    goto v_31264;
v_31258:
    stack[-1] = qvalue(elt(env, 2)); // ndim!*
    goto v_31259;
v_31260:
    stack[0] = v_31277;
    goto v_31261;
v_31262:
    goto v_31272;
v_31268:
    goto v_31269;
v_31270:
    v_31276 = stack[-3];
    goto v_31271;
v_31272:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    v_31276 = plus2(v_31277, v_31276);
    env = stack[-4];
    goto v_31263;
v_31264:
    goto v_31258;
v_31259:
    goto v_31260;
v_31261:
    goto v_31262;
v_31263:
    fn = elt(env, 3); // mk!-numr
    v_31276 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_31276);
    env = stack[-4];
    goto v_31251;
v_31252:
    goto v_31248;
v_31249:
    goto v_31250;
v_31251:
    v_31276 = cons(stack[-2], v_31276);
    env = stack[-4];
    {
        fn = elt(env, 4); // constimes
        return (*qfn1(fn))(fn, v_31276);
    }
    goto v_31217;
    v_31276 = nil;
v_31217:
    return onevalue(v_31276);
}



// Code for hdiff

static LispObject CC_hdiff(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31254, v_31255;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    v_31254 = stack[-1];
    if (v_31254 == nil) goto v_31219;
    else goto v_31220;
v_31219:
    v_31254 = nil;
    goto v_31218;
v_31220:
    goto v_31230;
v_31226:
    goto v_31236;
v_31232:
    goto v_31241;
v_31237:
    v_31255 = stack[-1];
    goto v_31238;
v_31239:
    v_31254 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    v_31255 = *(LispObject *)((char *)v_31255 + (CELL-TAG_VECTOR) + (((intptr_t)v_31254-TAG_FIXNUM)/(16/CELL)));
    goto v_31233;
v_31234:
    v_31254 = stack[0];
    goto v_31235;
v_31236:
    goto v_31232;
v_31233:
    goto v_31234;
v_31235:
    stack[-2] = CC_hdiff(elt(env, 0), v_31255, v_31254);
    env = stack[-3];
    goto v_31227;
v_31228:
    goto v_31251;
v_31247:
    v_31255 = stack[-1];
    goto v_31248;
v_31249:
    v_31254 = stack[0];
    goto v_31250;
v_31251:
    goto v_31247;
v_31248:
    goto v_31249;
v_31250:
    fn = elt(env, 1); // hdiffterm
    v_31254 = (*qfn2(fn))(fn, v_31255, v_31254);
    env = stack[-3];
    goto v_31229;
v_31230:
    goto v_31226;
v_31227:
    goto v_31228;
v_31229:
    {
        LispObject v_31259 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_31259, v_31254);
    }
    v_31254 = nil;
v_31218:
    return onevalue(v_31254);
}



// Code for test!-bool

static LispObject CC_testKbool(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31222;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31222 = v_31214;
// end of prologue
    v_31222 = qcar(v_31222);
    fn = elt(env, 1); // boolean!-eval1
    v_31222 = (*qfn1(fn))(fn, v_31222);
    env = stack[0];
    v_31222 = ncons(v_31222);
    env = stack[0];
    fn = elt(env, 2); // simp!-prop
    v_31222 = (*qfn1(fn))(fn, v_31222);
    env = stack[0];
    {
        fn = elt(env, 3); // mk!*sq
        return (*qfn1(fn))(fn, v_31222);
    }
}



// Code for combin

static LispObject CC_combin(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31314, v_31315;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_31215;
    stack[-3] = v_31214;
// end of prologue
    goto v_31226;
v_31222:
    v_31315 = stack[-3];
    goto v_31223;
v_31224:
    v_31314 = stack[-2];
    goto v_31225;
v_31226:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    v_31314 = (LispObject)greaterp2(v_31315, v_31314);
    v_31314 = v_31314 ? lisp_true : nil;
    env = stack[-5];
    if (v_31314 == nil) goto v_31220;
    v_31314 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31218;
v_31220:
    v_31314 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31314;
    stack[-4] = v_31314;
    goto v_31250;
v_31246:
    v_31315 = stack[-2];
    goto v_31247;
v_31248:
    v_31314 = stack[-3];
    goto v_31249;
v_31250:
    goto v_31246;
v_31247:
    goto v_31248;
v_31249:
    v_31314 = difference2(v_31315, v_31314);
    env = stack[-5];
    v_31314 = add1(v_31314);
    env = stack[-5];
    stack[0] = v_31314;
v_31243:
    goto v_31263;
v_31259:
    v_31315 = stack[-2];
    goto v_31260;
v_31261:
    v_31314 = stack[0];
    goto v_31262;
v_31263:
    goto v_31259;
v_31260:
    goto v_31261;
v_31262:
    v_31314 = difference2(v_31315, v_31314);
    env = stack[-5];
    v_31314 = Lminusp(nil, v_31314);
    env = stack[-5];
    if (v_31314 == nil) goto v_31256;
    goto v_31242;
v_31256:
    goto v_31272;
v_31268:
    v_31315 = stack[-4];
    goto v_31269;
v_31270:
    v_31314 = stack[0];
    goto v_31271;
v_31272:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    v_31314 = times2(v_31315, v_31314);
    env = stack[-5];
    stack[-4] = v_31314;
    v_31314 = stack[0];
    v_31314 = add1(v_31314);
    env = stack[-5];
    stack[0] = v_31314;
    goto v_31243;
v_31242:
    v_31314 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_31314;
v_31280:
    goto v_31292;
v_31288:
    v_31315 = stack[-3];
    goto v_31289;
v_31290:
    v_31314 = stack[0];
    goto v_31291;
v_31292:
    goto v_31288;
v_31289:
    goto v_31290;
v_31291:
    v_31314 = difference2(v_31315, v_31314);
    env = stack[-5];
    v_31314 = Lminusp(nil, v_31314);
    env = stack[-5];
    if (v_31314 == nil) goto v_31285;
    goto v_31279;
v_31285:
    goto v_31301;
v_31297:
    v_31315 = stack[-1];
    goto v_31298;
v_31299:
    v_31314 = stack[0];
    goto v_31300;
v_31301:
    goto v_31297;
v_31298:
    goto v_31299;
v_31300:
    v_31314 = times2(v_31315, v_31314);
    env = stack[-5];
    stack[-1] = v_31314;
    v_31314 = stack[0];
    v_31314 = add1(v_31314);
    env = stack[-5];
    stack[0] = v_31314;
    goto v_31280;
v_31279:
    goto v_31311;
v_31307:
    v_31315 = stack[-4];
    goto v_31308;
v_31309:
    v_31314 = stack[-1];
    goto v_31310;
v_31311:
    goto v_31307;
v_31308:
    goto v_31309;
v_31310:
    return quot2(v_31315, v_31314);
    goto v_31218;
    v_31314 = nil;
v_31218:
    return onevalue(v_31314);
}



// Code for coeffs!-to!-form1

static LispObject CC_coeffsKtoKform1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31276, v_31277, v_31278;
    LispObject fn;
    LispObject v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31214,v_31215,v_31216);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_31216;
    stack[-2] = v_31215;
    stack[-3] = v_31214;
// end of prologue
    goto v_31227;
v_31223:
    v_31277 = stack[-1];
    goto v_31224;
v_31225:
    v_31276 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31226;
v_31227:
    goto v_31223;
v_31224:
    goto v_31225;
v_31226:
    v_31276 = (LispObject)greaterp2(v_31277, v_31276);
    v_31276 = v_31276 ? lisp_true : nil;
    env = stack[-5];
    if (v_31276 == nil) goto v_31221;
    goto v_31237;
v_31231:
    v_31276 = stack[-3];
    stack[-4] = qcdr(v_31276);
    goto v_31232;
v_31233:
    stack[0] = stack[-2];
    goto v_31234;
v_31235:
    v_31276 = stack[-1];
    v_31276 = sub1(v_31276);
    env = stack[-5];
    goto v_31236;
v_31237:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    goto v_31235;
v_31236:
    v_31276 = CC_coeffsKtoKform1(elt(env, 0), 3, stack[-4], stack[0], v_31276);
    env = stack[-5];
    stack[0] = v_31276;
    v_31276 = stack[-3];
    v_31276 = qcar(v_31276);
    if (v_31276 == nil) goto v_31247;
    goto v_31257;
v_31251:
    goto v_31263;
v_31259:
    v_31277 = stack[-2];
    goto v_31260;
v_31261:
    v_31276 = stack[-1];
    goto v_31262;
v_31263:
    goto v_31259;
v_31260:
    goto v_31261;
v_31262:
    fn = elt(env, 1); // to
    v_31278 = (*qfn2(fn))(fn, v_31277, v_31276);
    goto v_31252;
v_31253:
    v_31276 = stack[-3];
    v_31277 = qcar(v_31276);
    goto v_31254;
v_31255:
    v_31276 = stack[0];
    goto v_31256;
v_31257:
    goto v_31251;
v_31252:
    goto v_31253;
v_31254:
    goto v_31255;
v_31256:
    return acons(v_31278, v_31277, v_31276);
v_31247:
    v_31276 = stack[0];
    goto v_31245;
    v_31276 = nil;
v_31245:
    goto v_31219;
v_31221:
    v_31276 = stack[-3];
    v_31276 = qcar(v_31276);
    goto v_31219;
    v_31276 = nil;
v_31219:
    return onevalue(v_31276);
}



// Code for giprim

static LispObject CC_giprim(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31241, v_31242, v_31243;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31243 = v_31214;
// end of prologue
    goto v_31224;
v_31220:
    v_31242 = v_31243;
    goto v_31221;
v_31222:
    v_31241 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31223;
v_31224:
    goto v_31220;
v_31221:
    goto v_31222;
v_31223:
    if (v_31242 == v_31241) goto v_31218;
    else goto v_31219;
v_31218:
    v_31241 = elt(env, 1); // i
    goto v_31217;
v_31219:
    goto v_31237;
v_31231:
    v_31241 = elt(env, 2); // times
    goto v_31232;
v_31233:
    v_31242 = v_31243;
    goto v_31234;
v_31235:
    v_31243 = elt(env, 1); // i
    goto v_31236;
v_31237:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    goto v_31235;
v_31236:
    return list3(v_31241, v_31242, v_31243);
    v_31241 = nil;
v_31217:
    return onevalue(v_31241);
}



// Code for quotf!*

static LispObject CC_quotfH(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31280, v_31281, v_31282;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31215;
    stack[-1] = v_31214;
// end of prologue
    v_31280 = stack[-1];
    if (v_31280 == nil) goto v_31219;
    else goto v_31220;
v_31219:
    v_31280 = nil;
    goto v_31218;
v_31220:
    goto v_31230;
v_31226:
    v_31281 = stack[-1];
    goto v_31227;
v_31228:
    v_31280 = stack[0];
    goto v_31229;
v_31230:
    goto v_31226;
v_31227:
    goto v_31228;
v_31229:
    fn = elt(env, 2); // quotf
    v_31280 = (*qfn2(fn))(fn, v_31281, v_31280);
    env = stack[-2];
    v_31281 = v_31280;
    v_31280 = v_31281;
    if (v_31280 == nil) goto v_31237;
    v_31280 = v_31281;
    goto v_31235;
v_31237:
    goto v_31248;
v_31244:
    v_31281 = stack[-1];
    goto v_31245;
v_31246:
    v_31280 = stack[0];
    goto v_31247;
v_31248:
    goto v_31244;
v_31245:
    goto v_31246;
v_31247:
    v_31280 = cons(v_31281, v_31280);
    env = stack[-2];
    fn = elt(env, 3); // rationalizesq
    v_31280 = (*qfn1(fn))(fn, v_31280);
    env = stack[-2];
    v_31282 = v_31280;
    goto v_31260;
v_31256:
    v_31280 = v_31282;
    v_31281 = qcdr(v_31280);
    goto v_31257;
v_31258:
    v_31280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31259;
v_31260:
    goto v_31256;
v_31257:
    goto v_31258;
v_31259:
    if (v_31281 == v_31280) goto v_31254;
    else goto v_31255;
v_31254:
    v_31280 = v_31282;
    v_31280 = qcar(v_31280);
    goto v_31253;
v_31255:
    goto v_31276;
v_31270:
    v_31282 = elt(env, 1); // "DIVISION FAILED"
    goto v_31271;
v_31272:
    v_31281 = stack[-1];
    goto v_31273;
v_31274:
    v_31280 = stack[0];
    goto v_31275;
v_31276:
    goto v_31270;
v_31271:
    goto v_31272;
v_31273:
    goto v_31274;
v_31275:
    v_31280 = list3(v_31282, v_31281, v_31280);
    env = stack[-2];
    {
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(fn, v_31280);
    }
    v_31280 = nil;
v_31253:
    goto v_31235;
    v_31280 = nil;
v_31235:
    goto v_31218;
    v_31280 = nil;
v_31218:
    return onevalue(v_31280);
}



// Code for qqe_simplqequal

static LispObject CC_qqe_simplqequal(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31609, v_31610, v_31611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_31609 = v_31215;
    stack[0] = v_31214;
// end of prologue
v_31213:
    v_31609 = stack[0];
    fn = elt(env, 6); // qqe_arg2r
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-7] = v_31609;
    v_31609 = stack[0];
    fn = elt(env, 7); // qqe_arg2l
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-8] = v_31609;
    goto v_31242;
v_31238:
    v_31610 = stack[-7];
    goto v_31239;
v_31240:
    v_31609 = stack[-8];
    goto v_31241;
v_31242:
    goto v_31238;
v_31239:
    goto v_31240;
v_31241:
    if (equal(v_31610, v_31609)) goto v_31236;
    else goto v_31237;
v_31236:
    v_31609 = elt(env, 2); // true
    goto v_31228;
v_31237:
    v_31609 = stack[-8];
    fn = elt(env, 8); // qqe_qprefix!-var
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-6] = v_31609;
    v_31609 = stack[-7];
    fn = elt(env, 8); // qqe_qprefix!-var
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-5] = v_31609;
    goto v_31262;
v_31258:
    v_31610 = stack[-6];
    goto v_31259;
v_31260:
    v_31609 = stack[-5];
    goto v_31261;
v_31262:
    goto v_31258;
v_31259:
    goto v_31260;
v_31261:
    if (v_31610 == v_31609) goto v_31256;
    else goto v_31257;
v_31256:
    v_31609 = lisp_true;
    goto v_31255;
v_31257:
    goto v_31276;
v_31272:
    v_31610 = stack[-6];
    goto v_31273;
v_31274:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31275;
v_31276:
    goto v_31272;
v_31273:
    goto v_31274;
v_31275:
    if (v_31610 == v_31609) goto v_31270;
    else goto v_31271;
v_31270:
    v_31609 = lisp_true;
    goto v_31269;
v_31271:
    goto v_31286;
v_31282:
    v_31610 = stack[-5];
    goto v_31283;
v_31284:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31285;
v_31286:
    goto v_31282;
v_31283:
    goto v_31284;
v_31285:
    v_31609 = (v_31610 == v_31609 ? lisp_true : nil);
    goto v_31269;
    v_31609 = nil;
v_31269:
    goto v_31255;
    v_31609 = nil;
v_31255:
    if (v_31609 == nil) goto v_31253;
    v_31609 = stack[-7];
    fn = elt(env, 9); // qqe_number!-of!-adds!-in!-qterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-3] = v_31609;
    v_31609 = stack[-8];
    fn = elt(env, 9); // qqe_number!-of!-adds!-in!-qterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-4] = v_31609;
    v_31609 = stack[-7];
    fn = elt(env, 10); // qqe_number!-of!-tails!-in!-qterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-1] = v_31609;
    v_31609 = stack[-8];
    fn = elt(env, 10); // qqe_number!-of!-tails!-in!-qterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[-2] = v_31609;
    goto v_31310;
v_31306:
    v_31610 = stack[-6];
    goto v_31307;
v_31308:
    v_31609 = stack[-5];
    goto v_31309;
v_31310:
    goto v_31306;
v_31307:
    goto v_31308;
v_31309:
    if (v_31610 == v_31609) goto v_31304;
    else goto v_31305;
v_31304:
    goto v_31323;
v_31319:
    v_31610 = stack[-3];
    goto v_31320;
v_31321:
    v_31609 = stack[-1];
    goto v_31322;
v_31323:
    goto v_31319;
v_31320:
    goto v_31321;
v_31322:
    v_31609 = (LispObject)geq2(v_31610, v_31609);
    v_31609 = v_31609 ? lisp_true : nil;
    env = stack[-9];
    if (v_31609 == nil) goto v_31317;
    else goto v_31316;
v_31317:
    goto v_31332;
v_31328:
    v_31610 = stack[-4];
    goto v_31329;
v_31330:
    v_31609 = stack[-2];
    goto v_31331;
v_31332:
    goto v_31328;
v_31329:
    goto v_31330;
v_31331:
    v_31609 = (LispObject)geq2(v_31610, v_31609);
    v_31609 = v_31609 ? lisp_true : nil;
    env = stack[-9];
    if (v_31609 == nil) goto v_31326;
    else goto v_31316;
v_31326:
    v_31609 = nil;
    goto v_31314;
v_31316:
    goto v_31342;
v_31338:
    goto v_31348;
v_31344:
    v_31610 = stack[-3];
    goto v_31345;
v_31346:
    v_31609 = stack[-1];
    goto v_31347;
v_31348:
    goto v_31344;
v_31345:
    goto v_31346;
v_31347:
    stack[0] = difference2(v_31610, v_31609);
    env = stack[-9];
    goto v_31339;
v_31340:
    goto v_31356;
v_31352:
    v_31610 = stack[-4];
    goto v_31353;
v_31354:
    v_31609 = stack[-2];
    goto v_31355;
v_31356:
    goto v_31352;
v_31353:
    goto v_31354;
v_31355:
    v_31609 = difference2(v_31610, v_31609);
    env = stack[-9];
    goto v_31341;
v_31342:
    goto v_31338;
v_31339:
    goto v_31340;
v_31341:
    v_31609 = (equal(stack[0], v_31609) ? lisp_true : nil);
    v_31609 = (v_31609 == nil ? lisp_true : nil);
    goto v_31314;
    v_31609 = nil;
v_31314:
    goto v_31303;
v_31305:
    v_31609 = nil;
    goto v_31303;
    v_31609 = nil;
v_31303:
    if (v_31609 == nil) goto v_31301;
    v_31609 = elt(env, 4); // false
    goto v_31228;
v_31301:
    goto v_31376;
v_31372:
    v_31610 = stack[-7];
    goto v_31373;
v_31374:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31375;
v_31376:
    goto v_31372;
v_31373:
    goto v_31374;
v_31375:
    if (v_31610 == v_31609) goto v_31370;
    else goto v_31371;
v_31370:
    goto v_31384;
v_31380:
    v_31610 = stack[-4];
    goto v_31381;
v_31382:
    v_31609 = stack[-2];
    goto v_31383;
v_31384:
    goto v_31380;
v_31381:
    goto v_31382;
v_31383:
    v_31609 = (LispObject)greaterp2(v_31610, v_31609);
    v_31609 = v_31609 ? lisp_true : nil;
    env = stack[-9];
    goto v_31369;
v_31371:
    v_31609 = nil;
    goto v_31369;
    v_31609 = nil;
v_31369:
    if (v_31609 == nil) goto v_31367;
    v_31609 = elt(env, 4); // false
    goto v_31228;
v_31367:
    goto v_31401;
v_31397:
    v_31610 = stack[-8];
    goto v_31398;
v_31399:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31400;
v_31401:
    goto v_31397;
v_31398:
    goto v_31399;
v_31400:
    if (v_31610 == v_31609) goto v_31395;
    else goto v_31396;
v_31395:
    goto v_31409;
v_31405:
    v_31610 = stack[-3];
    goto v_31406;
v_31407:
    v_31609 = stack[-1];
    goto v_31408;
v_31409:
    goto v_31405;
v_31406:
    goto v_31407;
v_31408:
    v_31609 = (LispObject)greaterp2(v_31610, v_31609);
    v_31609 = v_31609 ? lisp_true : nil;
    env = stack[-9];
    goto v_31394;
v_31396:
    v_31609 = nil;
    goto v_31394;
    v_31609 = nil;
v_31394:
    if (v_31609 == nil) goto v_31392;
    v_31609 = elt(env, 4); // false
    goto v_31228;
v_31392:
    goto v_31426;
v_31422:
    v_31610 = stack[-7];
    goto v_31423;
v_31424:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31425;
v_31426:
    goto v_31422;
v_31423:
    goto v_31424;
v_31425:
    if (v_31610 == v_31609) goto v_31420;
    else goto v_31421;
v_31420:
    goto v_31437;
v_31433:
    v_31610 = stack[-3];
    goto v_31434;
v_31435:
    v_31609 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31436;
v_31437:
    goto v_31433;
v_31434:
    goto v_31435;
v_31436:
    if (v_31610 == v_31609) goto v_31431;
    else goto v_31432;
v_31431:
    goto v_31444;
v_31440:
    v_31610 = stack[-4];
    goto v_31441;
v_31442:
    v_31609 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31443;
v_31444:
    goto v_31440;
v_31441:
    goto v_31442;
v_31443:
    v_31609 = (v_31610 == v_31609 ? lisp_true : nil);
    goto v_31430;
v_31432:
    v_31609 = nil;
    goto v_31430;
    v_31609 = nil;
v_31430:
    goto v_31419;
v_31421:
    v_31609 = nil;
    goto v_31419;
    v_31609 = nil;
v_31419:
    if (v_31609 == nil) goto v_31417;
    goto v_31462;
v_31458:
    v_31610 = stack[-6];
    goto v_31459;
v_31460:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31461;
v_31462:
    goto v_31458;
v_31459:
    goto v_31460;
v_31461:
    if (v_31610 == v_31609) goto v_31456;
    else goto v_31457;
v_31456:
    v_31609 = elt(env, 2); // true
    goto v_31228;
v_31457:
    v_31609 = stack[-8];
    fn = elt(env, 11); // qqe_simplterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    goto v_31455;
v_31455:
    goto v_31477;
v_31471:
    v_31610 = elt(env, 5); // qequal
    goto v_31472;
v_31473:
    v_31611 = v_31609;
    goto v_31474;
v_31475:
    v_31609 = stack[-7];
    goto v_31476;
v_31477:
    goto v_31471;
v_31472:
    goto v_31473;
v_31474:
    goto v_31475;
v_31476:
    {
        fn = elt(env, 12); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31610, v_31611, v_31609);
    }
v_31417:
    goto v_31492;
v_31488:
    v_31610 = stack[-8];
    goto v_31489;
v_31490:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31491;
v_31492:
    goto v_31488;
v_31489:
    goto v_31490;
v_31491:
    if (v_31610 == v_31609) goto v_31486;
    else goto v_31487;
v_31486:
    goto v_31503;
v_31499:
    v_31610 = stack[-3];
    goto v_31500;
v_31501:
    v_31609 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31502;
v_31503:
    goto v_31499;
v_31500:
    goto v_31501;
v_31502:
    if (v_31610 == v_31609) goto v_31497;
    else goto v_31498;
v_31497:
    goto v_31510;
v_31506:
    v_31610 = stack[-4];
    goto v_31507;
v_31508:
    v_31609 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31509;
v_31510:
    goto v_31506;
v_31507:
    goto v_31508;
v_31509:
    v_31609 = (v_31610 == v_31609 ? lisp_true : nil);
    goto v_31496;
v_31498:
    v_31609 = nil;
    goto v_31496;
    v_31609 = nil;
v_31496:
    goto v_31485;
v_31487:
    v_31609 = nil;
    goto v_31485;
    v_31609 = nil;
v_31485:
    if (v_31609 == nil) goto v_31483;
    goto v_31528;
v_31524:
    v_31610 = stack[-5];
    goto v_31525;
v_31526:
    v_31609 = elt(env, 3); // qepsilon
    goto v_31527;
v_31528:
    goto v_31524;
v_31525:
    goto v_31526;
v_31527:
    if (v_31610 == v_31609) goto v_31522;
    else goto v_31523;
v_31522:
    v_31609 = elt(env, 2); // true
    goto v_31228;
v_31523:
    v_31609 = stack[-7];
    fn = elt(env, 11); // qqe_simplterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[0] = v_31609;
    goto v_31521;
v_31521:
    goto v_31543;
v_31537:
    v_31611 = elt(env, 5); // qequal
    goto v_31538;
v_31539:
    v_31610 = stack[-8];
    goto v_31540;
v_31541:
    v_31609 = stack[0];
    goto v_31542;
v_31543:
    goto v_31537;
v_31538:
    goto v_31539;
v_31540:
    goto v_31541;
v_31542:
    {
        fn = elt(env, 12); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31611, v_31610, v_31609);
    }
v_31483:
    goto v_31251;
v_31253:
v_31251:
    v_31609 = stack[-7];
    fn = elt(env, 11); // qqe_simplterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    stack[0] = v_31609;
    v_31609 = stack[-8];
    fn = elt(env, 11); // qqe_simplterm
    v_31609 = (*qfn1(fn))(fn, v_31609);
    env = stack[-9];
    goto v_31564;
v_31560:
    v_31611 = stack[-7];
    goto v_31561;
v_31562:
    v_31610 = stack[0];
    goto v_31563;
v_31564:
    goto v_31560;
v_31561:
    goto v_31562;
v_31563:
    if (equal(v_31611, v_31610)) goto v_31558;
    else goto v_31559;
v_31558:
    goto v_31571;
v_31567:
    v_31611 = stack[-8];
    goto v_31568;
v_31569:
    v_31610 = v_31609;
    goto v_31570;
v_31571:
    goto v_31567;
v_31568:
    goto v_31569;
v_31570:
    v_31610 = (equal(v_31611, v_31610) ? lisp_true : nil);
    goto v_31557;
v_31559:
    v_31610 = nil;
    goto v_31557;
    v_31610 = nil;
v_31557:
    if (v_31610 == nil) goto v_31555;
    goto v_31585;
v_31579:
    v_31611 = elt(env, 5); // qequal
    goto v_31580;
v_31581:
    v_31610 = v_31609;
    goto v_31582;
v_31583:
    v_31609 = stack[0];
    goto v_31584;
v_31585:
    goto v_31579;
v_31580:
    goto v_31581;
v_31582:
    goto v_31583;
v_31584:
    {
        fn = elt(env, 12); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31611, v_31610, v_31609);
    }
v_31555:
    goto v_31596;
v_31592:
    goto v_31604;
v_31598:
    v_31611 = elt(env, 5); // qequal
    goto v_31599;
v_31600:
    v_31610 = v_31609;
    goto v_31601;
v_31602:
    v_31609 = stack[0];
    goto v_31603;
v_31604:
    goto v_31598;
v_31599:
    goto v_31600;
v_31601:
    goto v_31602;
v_31603:
    fn = elt(env, 12); // qqe_mk2
    v_31609 = (*qfnn(fn))(fn, 3, v_31611, v_31610, v_31609);
    env = stack[-9];
    goto v_31593;
v_31594:
    goto v_31595;
v_31596:
    goto v_31592;
v_31593:
    goto v_31594;
v_31595:
    stack[0] = v_31609;
    goto v_31213;
    v_31609 = nil;
v_31228:
    return onevalue(v_31609);
}



// Code for rl_simplb

static LispObject CC_rl_simplb(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31232, v_31233;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31232 = v_31215;
    v_31233 = v_31214;
// end of prologue
    goto v_31222;
v_31218:
    stack[0] = qvalue(elt(env, 1)); // rl_simplb!*
    goto v_31219;
v_31220:
    goto v_31229;
v_31225:
    goto v_31226;
v_31227:
    goto v_31228;
v_31229:
    goto v_31225;
v_31226:
    goto v_31227;
v_31228:
    v_31232 = list2(v_31233, v_31232);
    env = stack[-1];
    goto v_31221;
v_31222:
    goto v_31218;
v_31219:
    goto v_31220;
v_31221:
    {
        LispObject v_31235 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31235, v_31232);
    }
}



// Code for acfsf_varlat

static LispObject CC_acfsf_varlat(LispObject env,
                         LispObject v_31214)
{
    env = qenv(env);
    LispObject v_31219;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31214);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31219 = v_31214;
// end of prologue
    fn = elt(env, 1); // acfsf_arg2l
    v_31219 = (*qfn1(fn))(fn, v_31219);
    env = stack[0];
    {
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(fn, v_31219);
    }
}



// Code for symmetrize!-inds

static LispObject CC_symmetrizeKinds(LispObject env,
                         LispObject v_31214, LispObject v_31215)
{
    env = qenv(env);
    LispObject v_31527, v_31528;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31214,v_31215);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_31215;
    stack[-9] = v_31214;
// end of prologue
    v_31527 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_31527;
    v_31527 = stack[-9];
    stack[-7] = v_31527;
    v_31527 = stack[-7];
    if (v_31527 == nil) goto v_31234;
    else goto v_31235;
v_31234:
    v_31527 = nil;
    goto v_31229;
v_31235:
    v_31527 = stack[-7];
    v_31527 = qcar(v_31527);
    v_31528 = v_31527;
    if (!consp(v_31528)) goto v_31244;
    else goto v_31245;
v_31244:
    goto v_31252;
v_31248:
    v_31528 = stack[-8];
    goto v_31249;
v_31250:
    goto v_31251;
v_31252:
    goto v_31248;
v_31249:
    goto v_31250;
v_31251:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    goto v_31243;
v_31245:
    stack[-3] = v_31527;
    v_31527 = stack[-3];
    if (v_31527 == nil) goto v_31266;
    else goto v_31267;
v_31266:
    v_31527 = nil;
    goto v_31261;
v_31267:
    v_31527 = stack[-3];
    v_31527 = qcar(v_31527);
    goto v_31279;
v_31275:
    v_31528 = stack[-8];
    goto v_31276;
v_31277:
    goto v_31278;
v_31279:
    goto v_31275;
v_31276:
    goto v_31277;
v_31278:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    v_31527 = ncons(v_31527);
    env = stack[-11];
    stack[-1] = v_31527;
    stack[-2] = v_31527;
v_31262:
    v_31527 = stack[-3];
    v_31527 = qcdr(v_31527);
    stack[-3] = v_31527;
    v_31527 = stack[-3];
    if (v_31527 == nil) goto v_31286;
    else goto v_31287;
v_31286:
    v_31527 = stack[-2];
    goto v_31261;
v_31287:
    goto v_31295;
v_31291:
    stack[0] = stack[-1];
    goto v_31292;
v_31293:
    v_31527 = stack[-3];
    v_31527 = qcar(v_31527);
    goto v_31306;
v_31302:
    v_31528 = stack[-8];
    goto v_31303;
v_31304:
    goto v_31305;
v_31306:
    goto v_31302;
v_31303:
    goto v_31304;
v_31305:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    v_31527 = ncons(v_31527);
    env = stack[-11];
    goto v_31294;
v_31295:
    goto v_31291;
v_31292:
    goto v_31293;
v_31294:
    v_31527 = Lrplacd(nil, stack[0], v_31527);
    env = stack[-11];
    v_31527 = stack[-1];
    v_31527 = qcdr(v_31527);
    stack[-1] = v_31527;
    goto v_31262;
v_31261:
    goto v_31243;
    v_31527 = nil;
v_31243:
    v_31527 = ncons(v_31527);
    env = stack[-11];
    stack[-5] = v_31527;
    stack[-6] = v_31527;
v_31230:
    v_31527 = stack[-7];
    v_31527 = qcdr(v_31527);
    stack[-7] = v_31527;
    v_31527 = stack[-7];
    if (v_31527 == nil) goto v_31315;
    else goto v_31316;
v_31315:
    v_31527 = stack[-6];
    goto v_31229;
v_31316:
    goto v_31324;
v_31320:
    stack[-4] = stack[-5];
    goto v_31321;
v_31322:
    v_31527 = stack[-7];
    v_31527 = qcar(v_31527);
    v_31528 = v_31527;
    if (!consp(v_31528)) goto v_31332;
    else goto v_31333;
v_31332:
    goto v_31340;
v_31336:
    v_31528 = stack[-8];
    goto v_31337;
v_31338:
    goto v_31339;
v_31340:
    goto v_31336;
v_31337:
    goto v_31338;
v_31339:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    goto v_31331;
v_31333:
    stack[-3] = v_31527;
    v_31527 = stack[-3];
    if (v_31527 == nil) goto v_31354;
    else goto v_31355;
v_31354:
    v_31527 = nil;
    goto v_31349;
v_31355:
    v_31527 = stack[-3];
    v_31527 = qcar(v_31527);
    goto v_31367;
v_31363:
    v_31528 = stack[-8];
    goto v_31364;
v_31365:
    goto v_31366;
v_31367:
    goto v_31363;
v_31364:
    goto v_31365;
v_31366:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    v_31527 = ncons(v_31527);
    env = stack[-11];
    stack[-1] = v_31527;
    stack[-2] = v_31527;
v_31350:
    v_31527 = stack[-3];
    v_31527 = qcdr(v_31527);
    stack[-3] = v_31527;
    v_31527 = stack[-3];
    if (v_31527 == nil) goto v_31374;
    else goto v_31375;
v_31374:
    v_31527 = stack[-2];
    goto v_31349;
v_31375:
    goto v_31383;
v_31379:
    stack[0] = stack[-1];
    goto v_31380;
v_31381:
    v_31527 = stack[-3];
    v_31527 = qcar(v_31527);
    goto v_31394;
v_31390:
    v_31528 = stack[-8];
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    goto v_31390;
v_31391:
    goto v_31392;
v_31393:
    fn = elt(env, 2); // nth
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    v_31527 = ncons(v_31527);
    env = stack[-11];
    goto v_31382;
v_31383:
    goto v_31379;
v_31380:
    goto v_31381;
v_31382:
    v_31527 = Lrplacd(nil, stack[0], v_31527);
    env = stack[-11];
    v_31527 = stack[-1];
    v_31527 = qcdr(v_31527);
    stack[-1] = v_31527;
    goto v_31350;
v_31349:
    goto v_31331;
    v_31527 = nil;
v_31331:
    v_31527 = ncons(v_31527);
    env = stack[-11];
    goto v_31323;
v_31324:
    goto v_31320;
v_31321:
    goto v_31322;
v_31323:
    v_31527 = Lrplacd(nil, stack[-4], v_31527);
    env = stack[-11];
    v_31527 = stack[-5];
    v_31527 = qcdr(v_31527);
    stack[-5] = v_31527;
    goto v_31230;
v_31229:
    stack[-5] = v_31527;
    v_31527 = stack[-5];
    v_31527 = qcar(v_31527);
    if (!consp(v_31527)) goto v_31403;
    else goto v_31404;
v_31403:
    v_31527 = stack[-5];
    fn = elt(env, 3); // indordn
    v_31527 = (*qfn1(fn))(fn, v_31527);
    env = stack[-11];
    goto v_31402;
v_31404:
    v_31527 = stack[-5];
    fn = elt(env, 4); // indordln
    v_31527 = (*qfn1(fn))(fn, v_31527);
    env = stack[-11];
    fn = elt(env, 5); // flatindl
    v_31527 = (*qfn1(fn))(fn, v_31527);
    env = stack[-11];
    goto v_31402;
    v_31527 = nil;
v_31402:
    stack[0] = v_31527;
    v_31527 = stack[-9];
    v_31527 = qcar(v_31527);
    if (!consp(v_31527)) goto v_31417;
    v_31527 = stack[-9];
    fn = elt(env, 5); // flatindl
    v_31527 = (*qfn1(fn))(fn, v_31527);
    env = stack[-11];
    stack[-9] = v_31527;
    goto v_31415;
v_31417:
v_31415:
    goto v_31427;
v_31423:
    v_31528 = stack[-9];
    goto v_31424;
v_31425:
    v_31527 = stack[0];
    goto v_31426;
v_31427:
    goto v_31423;
v_31424:
    goto v_31425;
v_31426:
    fn = elt(env, 6); // pair
    v_31527 = (*qfn2(fn))(fn, v_31528, v_31527);
    env = stack[-11];
    stack[-5] = v_31527;
    goto v_31435;
v_31431:
    stack[-6] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31432;
v_31433:
    v_31527 = stack[-8];
    stack[-7] = v_31527;
    v_31527 = stack[-7];
    if (v_31527 == nil) goto v_31446;
    else goto v_31447;
v_31446:
    v_31527 = nil;
    goto v_31441;
v_31447:
    v_31527 = stack[-7];
    v_31527 = qcar(v_31527);
    stack[-1] = v_31527;
    v_31527 = stack[-5];
    if (v_31527 == nil) goto v_31457;
    goto v_31465;
v_31461:
    v_31527 = stack[-5];
    v_31527 = qcar(v_31527);
    stack[0] = qcar(v_31527);
    goto v_31462;
v_31463:
    v_31527 = stack[-10];
    v_31527 = add1(v_31527);
    env = stack[-11];
    stack[-10] = v_31527;
    goto v_31464;
v_31465:
    goto v_31461;
v_31462:
    goto v_31463;
v_31464:
    if (equal(stack[0], v_31527)) goto v_31460;
    else goto v_31457;
v_31460:
    v_31527 = stack[-5];
    v_31527 = qcar(v_31527);
    v_31527 = qcdr(v_31527);
    v_31528 = v_31527;
    v_31527 = stack[-5];
    v_31527 = qcdr(v_31527);
    stack[-5] = v_31527;
    v_31527 = v_31528;
    goto v_31455;
v_31457:
    v_31527 = stack[-1];
    goto v_31455;
    v_31527 = nil;
v_31455:
    v_31527 = ncons(v_31527);
    env = stack[-11];
    stack[-3] = v_31527;
    stack[-4] = v_31527;
v_31442:
    v_31527 = stack[-7];
    v_31527 = qcdr(v_31527);
    stack[-7] = v_31527;
    v_31527 = stack[-7];
    if (v_31527 == nil) goto v_31484;
    else goto v_31485;
v_31484:
    v_31527 = stack[-4];
    goto v_31441;
v_31485:
    goto v_31493;
v_31489:
    stack[-2] = stack[-3];
    goto v_31490;
v_31491:
    v_31527 = stack[-7];
    v_31527 = qcar(v_31527);
    stack[-1] = v_31527;
    v_31527 = stack[-5];
    if (v_31527 == nil) goto v_31502;
    goto v_31510;
v_31506:
    v_31527 = stack[-5];
    v_31527 = qcar(v_31527);
    stack[0] = qcar(v_31527);
    goto v_31507;
v_31508:
    v_31527 = stack[-10];
    v_31527 = add1(v_31527);
    env = stack[-11];
    stack[-10] = v_31527;
    goto v_31509;
v_31510:
    goto v_31506;
v_31507:
    goto v_31508;
v_31509:
    if (equal(stack[0], v_31527)) goto v_31505;
    else goto v_31502;
v_31505:
    v_31527 = stack[-5];
    v_31527 = qcar(v_31527);
    v_31527 = qcdr(v_31527);
    v_31528 = v_31527;
    v_31527 = stack[-5];
    v_31527 = qcdr(v_31527);
    stack[-5] = v_31527;
    v_31527 = v_31528;
    goto v_31500;
v_31502:
    v_31527 = stack[-1];
    goto v_31500;
    v_31527 = nil;
v_31500:
    v_31527 = ncons(v_31527);
    env = stack[-11];
    goto v_31492;
v_31493:
    goto v_31489;
v_31490:
    goto v_31491;
v_31492:
    v_31527 = Lrplacd(nil, stack[-2], v_31527);
    env = stack[-11];
    v_31527 = stack[-3];
    v_31527 = qcdr(v_31527);
    stack[-3] = v_31527;
    goto v_31442;
v_31441:
    goto v_31434;
v_31435:
    goto v_31431;
v_31432:
    goto v_31433;
v_31434:
    {
        LispObject v_31540 = stack[-6];
        return cons(v_31540, v_31527);
    }
    return onevalue(v_31527);
}



// Code for al1_defined_vertex

static LispObject CC_al1_defined_vertex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31298, v_31299;
    LispObject fn;
    LispObject v_31217, v_31216, v_31215, v_31214;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "al1_defined_vertex");
    va_start(aa, nargs);
    v_31214 = va_arg(aa, LispObject);
    v_31215 = va_arg(aa, LispObject);
    v_31216 = va_arg(aa, LispObject);
    v_31217 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_31217,v_31216,v_31215,v_31214);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_31214,v_31215,v_31216,v_31217);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_31217;
    stack[-1] = v_31216;
    stack[-2] = v_31215;
    stack[-3] = v_31214;
// end of prologue
v_31222:
    v_31298 = stack[-3];
    if (v_31298 == nil) goto v_31225;
    else goto v_31226;
v_31225:
    v_31298 = stack[-2];
    if (v_31298 == nil) goto v_31230;
    else goto v_31231;
v_31230:
    v_31298 = lisp_true;
    goto v_31221;
v_31231:
    goto v_31241;
v_31237:
    v_31299 = stack[-2];
    goto v_31238;
v_31239:
    v_31298 = stack[-1];
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    {
        fn = elt(env, 1); // re_parents
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
    goto v_31224;
v_31226:
    goto v_31251;
v_31247:
    v_31298 = stack[-3];
    v_31299 = qcar(v_31298);
    goto v_31248;
v_31249:
    v_31298 = stack[0];
    goto v_31250;
v_31251:
    goto v_31247;
v_31248:
    goto v_31249;
v_31250:
    fn = elt(env, 2); // defined_edge
    v_31298 = (*qfn2(fn))(fn, v_31299, v_31298);
    env = stack[-5];
    if (v_31298 == nil) goto v_31245;
    goto v_31260;
v_31256:
    v_31299 = stack[-2];
    goto v_31257;
v_31258:
    v_31298 = stack[-3];
    v_31298 = qcdr(v_31298);
    goto v_31259;
v_31260:
    goto v_31256;
v_31257:
    goto v_31258;
v_31259:
    v_31298 = Lnconc(nil, v_31299, v_31298);
    env = stack[-5];
    stack[-4] = v_31298;
    v_31298 = nil;
    stack[-2] = v_31298;
    goto v_31270;
v_31266:
    v_31298 = stack[-3];
    v_31299 = qcar(v_31298);
    goto v_31267;
v_31268:
    v_31298 = stack[-1];
    goto v_31269;
v_31270:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    v_31298 = cons(v_31299, v_31298);
    env = stack[-5];
    stack[-1] = v_31298;
    goto v_31279;
v_31275:
    v_31298 = stack[-3];
    v_31299 = qcar(v_31298);
    goto v_31276;
v_31277:
    v_31298 = stack[0];
    goto v_31278;
v_31279:
    goto v_31275;
v_31276:
    goto v_31277;
v_31278:
    v_31298 = cons(v_31299, v_31298);
    env = stack[-5];
    stack[0] = v_31298;
    v_31298 = stack[-4];
    stack[-3] = v_31298;
    goto v_31222;
v_31245:
    v_31298 = stack[-3];
    v_31298 = qcdr(v_31298);
    stack[-4] = v_31298;
    goto v_31293;
v_31289:
    v_31298 = stack[-3];
    v_31299 = qcar(v_31298);
    goto v_31290;
v_31291:
    v_31298 = stack[-2];
    goto v_31292;
v_31293:
    goto v_31289;
v_31290:
    goto v_31291;
v_31292:
    v_31298 = cons(v_31299, v_31298);
    env = stack[-5];
    stack[-2] = v_31298;
    v_31298 = stack[-4];
    stack[-3] = v_31298;
    goto v_31222;
v_31224:
    v_31298 = nil;
v_31221:
    return onevalue(v_31298);
}



setup_type const u53_setup[] =
{
    {"pst_d1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pst_d1},
    {"baglistp",                CC_baglistp,    TOO_MANY_1,    WRONG_NO_1},
    {"general-difference-mod-p",TOO_FEW_2,      CC_generalKdifferenceKmodKp,WRONG_NO_2},
    {"constructinvolutivebasis",TOO_FEW_2,      CC_constructinvolutivebasis,WRONG_NO_2},
    {"talp_cocc",               TOO_FEW_2,      CC_talp_cocc,  WRONG_NO_2},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,TOO_MANY_1,WRONG_NO_1},
    {"dipreplus",               CC_dipreplus,   TOO_MANY_1,    WRONG_NO_1},
    {"make_wedge_pair",         TOO_FEW_2,      CC_make_wedge_pair,WRONG_NO_2},
    {"decimal2internal",        TOO_FEW_2,      CC_decimal2internal,WRONG_NO_2},
    {"gpexpp",                  CC_gpexpp,      TOO_MANY_1,    WRONG_NO_1},
    {"rule-list",               TOO_FEW_2,      CC_ruleKlist,  WRONG_NO_2},
    {"even_action_pow",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_pow},
    {"*multsq",                 TOO_FEW_2,      CC_Hmultsq,    WRONG_NO_2},
    {"taymindegreel",           TOO_FEW_2,      CC_taymindegreel,WRONG_NO_2},
    {"vdp_zero",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdp_zero},
    {"ldf-spf-var",             CC_ldfKspfKvar, TOO_MANY_1,    WRONG_NO_1},
    {"solvealgtrig01",          TOO_FEW_2,      CC_solvealgtrig01,WRONG_NO_2},
    {"latexprint",              CC_latexprint,  TOO_MANY_1,    WRONG_NO_1},
    {"is_buble",                TOO_FEW_2,      CC_is_buble,   WRONG_NO_2},
    {"dp=comp",                 TOO_FEW_2,      CC_dpMcomp,    WRONG_NO_2},
    {"simpsqrt3",               CC_simpsqrt3,   TOO_MANY_1,    WRONG_NO_1},
    {"qroundup",                TOO_FEW_2,      CC_qroundup,   WRONG_NO_2},
    {"ofsf_smmkatl-and",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand},
    {"ofsf_smwrmknowl",         TOO_FEW_2,      CC_ofsf_smwrmknowl,WRONG_NO_2},
    {"ofsf_smmkatl-or",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKor},
    {"eval-yetunknowntypeexpr", TOO_FEW_2,      CC_evalKyetunknowntypeexpr,WRONG_NO_2},
    {"division-test",           TOO_FEW_2,      CC_divisionKtest,WRONG_NO_2},
    {"vsl_boundtype1",          TOO_FEW_2,      CC_vsl_boundtype1,WRONG_NO_2},
    {"ps:value",                CC_psTvalue,    TOO_MANY_1,    WRONG_NO_1},
    {"vdpfmon",                 TOO_FEW_2,      CC_vdpfmon,    WRONG_NO_2},
    {"xexptpf",                 TOO_FEW_2,      CC_xexptpf,    WRONG_NO_2},
    {"mk-contract-coeff",       CC_mkKcontractKcoeff,TOO_MANY_1,WRONG_NO_1},
    {"hdiff",                   TOO_FEW_2,      CC_hdiff,      WRONG_NO_2},
    {"test-bool",               CC_testKbool,   TOO_MANY_1,    WRONG_NO_1},
    {"combin",                  TOO_FEW_2,      CC_combin,     WRONG_NO_2},
    {"coeffs-to-form1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeffsKtoKform1},
    {"giprim",                  CC_giprim,      TOO_MANY_1,    WRONG_NO_1},
    {"quotf*",                  TOO_FEW_2,      CC_quotfH,     WRONG_NO_2},
    {"qqe_simplqequal",         TOO_FEW_2,      CC_qqe_simplqequal,WRONG_NO_2},
    {"rl_simplb",               TOO_FEW_2,      CC_rl_simplb,  WRONG_NO_2},
    {"acfsf_varlat",            CC_acfsf_varlat,TOO_MANY_1,    WRONG_NO_1},
    {"symmetrize-inds",         TOO_FEW_2,      CC_symmetrizeKinds,WRONG_NO_2},
    {"al1_defined_vertex",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_al1_defined_vertex},
    {NULL, (one_args *)"u53", (two_args *)"124171 8887589 9458327", 0}
};

// end of generated code
