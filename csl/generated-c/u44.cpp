
// $destdir/u44.c        Machine generated C code

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



// Code for bc_sum

static LispObject CC_bc_sum(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24661, v_24662, v_24663, v_24664;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
// copy arguments values to proper place
    v_24663 = v_24565;
    v_24664 = v_24564;
// end of prologue
    goto v_24579;
v_24575:
    v_24661 = v_24664;
    v_24662 = qcdr(v_24661);
    goto v_24576;
v_24577:
    v_24661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24578;
v_24579:
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    if (v_24662 == v_24661) goto v_24573;
    else goto v_24574;
v_24573:
    v_24661 = v_24664;
    v_24661 = qcar(v_24661);
    if (is_number(v_24661)) goto v_24586;
    v_24661 = nil;
    goto v_24584;
v_24586:
    goto v_24600;
v_24596:
    v_24661 = v_24663;
    v_24662 = qcdr(v_24661);
    goto v_24597;
v_24598:
    v_24661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24599;
v_24600:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    if (v_24662 == v_24661) goto v_24594;
    else goto v_24595;
v_24594:
    v_24661 = v_24663;
    v_24661 = qcar(v_24661);
    v_24661 = (is_number(v_24661) ? lisp_true : nil);
    goto v_24593;
v_24595:
    v_24661 = nil;
    goto v_24593;
    v_24661 = nil;
v_24593:
    goto v_24584;
    v_24661 = nil;
v_24584:
    goto v_24572;
v_24574:
    v_24661 = nil;
    goto v_24572;
    v_24661 = nil;
v_24572:
    if (v_24661 == nil) goto v_24570;
    goto v_24621;
v_24617:
    goto v_24627;
v_24623:
    v_24661 = v_24664;
    v_24661 = qcar(v_24661);
    goto v_24624;
v_24625:
    v_24662 = v_24663;
    v_24662 = qcar(v_24662);
    goto v_24626;
v_24627:
    goto v_24623;
v_24624:
    goto v_24625;
v_24626:
    v_24662 = plus2(v_24661, v_24662);
    v_24664 = v_24662;
    goto v_24618;
v_24619:
    v_24661 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24620;
v_24621:
    goto v_24617;
v_24618:
    goto v_24619;
v_24620:
    if (v_24662 == v_24661) goto v_24615;
    else goto v_24616;
v_24615:
    goto v_24638;
v_24634:
    v_24662 = nil;
    goto v_24635;
v_24636:
    v_24661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24637;
v_24638:
    goto v_24634;
v_24635:
    goto v_24636;
v_24637:
    return cons(v_24662, v_24661);
v_24616:
    goto v_24648;
v_24644:
    v_24662 = v_24664;
    goto v_24645;
v_24646:
    v_24661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24647;
v_24648:
    goto v_24644;
v_24645:
    goto v_24646;
v_24647:
    return cons(v_24662, v_24661);
    v_24661 = nil;
    goto v_24568;
v_24570:
    goto v_24658;
v_24654:
    v_24661 = v_24664;
    goto v_24655;
v_24656:
    v_24662 = v_24663;
    goto v_24657;
v_24658:
    goto v_24654;
v_24655:
    goto v_24656;
v_24657:
    {
        fn = elt(env, 1); // addsq
        return (*qfn2(fn))(fn, v_24661, v_24662);
    }
    v_24661 = nil;
v_24568:
    return onevalue(v_24661);
}



// Code for symbolsrd

static LispObject CC_symbolsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24739, v_24740, v_24741;
    LispObject fn;
    argcheck(nargs, 0, "symbolsrd");
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
    stack_popper stack_popper_var(6);
// end of prologue
    stack[-4] = nil;
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_24590;
v_24586:
    v_24740 = qvalue(elt(env, 2)); // char
    goto v_24587;
v_24588:
    v_24739 = elt(env, 3); // (b v a r)
    goto v_24589;
v_24590:
    goto v_24586;
v_24587:
    goto v_24588;
v_24589:
    if (equal(v_24740, v_24739)) goto v_24584;
    else goto v_24585;
v_24584:
    fn = elt(env, 10); // bvarrd
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-4] = v_24739;
    goto v_24602;
v_24598:
    v_24739 = stack[-4];
    v_24739 = qcdr(v_24739);
    v_24739 = qcdr(v_24739);
    v_24740 = qcar(v_24739);
    goto v_24599;
v_24600:
    v_24739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24601;
v_24602:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    if (v_24740 == v_24739) goto v_24596;
    else goto v_24597;
v_24596:
    v_24739 = stack[-4];
    stack[-4] = v_24739;
    goto v_24595;
v_24597:
    goto v_24616;
v_24612:
    v_24740 = elt(env, 4); // ""
    goto v_24613;
v_24614:
    v_24739 = (LispObject)208+TAG_FIXNUM; // 13
    goto v_24615;
v_24616:
    goto v_24612;
v_24613:
    goto v_24614;
v_24615:
    fn = elt(env, 11); // errorml
    v_24739 = (*qfn2(fn))(fn, v_24740, v_24739);
    env = stack[-5];
    goto v_24595;
v_24595:
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_24583;
v_24585:
    goto v_24627;
v_24623:
    v_24740 = elt(env, 5); // "<bvar>"
    goto v_24624;
v_24625:
    v_24739 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_24626;
v_24627:
    goto v_24623;
v_24624:
    goto v_24625;
v_24626:
    fn = elt(env, 11); // errorml
    v_24739 = (*qfn2(fn))(fn, v_24740, v_24739);
    env = stack[-5];
    goto v_24583;
v_24583:
    goto v_24638;
v_24634:
    v_24740 = qvalue(elt(env, 2)); // char
    goto v_24635;
v_24636:
    v_24739 = elt(env, 6); // (l o w l i m i t)
    goto v_24637;
v_24638:
    goto v_24634;
v_24635:
    goto v_24636;
v_24637:
    if (equal(v_24740, v_24739)) goto v_24632;
    else goto v_24633;
v_24632:
    fn = elt(env, 12); // lowupperlimitrd
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-3] = v_24739;
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_24631;
v_24633:
    v_24739 = nil;
    stack[-3] = v_24739;
    goto v_24631;
v_24631:
    goto v_24654;
v_24650:
    v_24740 = qvalue(elt(env, 2)); // char
    goto v_24651;
v_24652:
    v_24739 = elt(env, 7); // (i n t e r v a l)
    goto v_24653;
v_24654:
    goto v_24650;
v_24651:
    goto v_24652;
v_24653:
    if (equal(v_24740, v_24739)) goto v_24648;
    else goto v_24649;
v_24648:
    fn = elt(env, 13); // intervalrd
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_24739;
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_24647;
v_24649:
    v_24739 = nil;
    stack[-2] = v_24739;
    goto v_24647;
v_24647:
    goto v_24670;
v_24666:
    v_24740 = qvalue(elt(env, 2)); // char
    goto v_24667;
v_24668:
    v_24739 = elt(env, 8); // (c o n d i t i o n)
    goto v_24669;
v_24670:
    goto v_24666;
v_24667:
    goto v_24668;
v_24669:
    if (equal(v_24740, v_24739)) goto v_24664;
    else goto v_24665;
v_24664:
    fn = elt(env, 14); // conditionrd
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[0] = v_24739;
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_24663;
v_24665:
    v_24739 = nil;
    stack[0] = v_24739;
    goto v_24663;
v_24663:
    fn = elt(env, 15); // mathml2
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-1] = v_24739;
    fn = elt(env, 9); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    v_24739 = stack[-3];
    if (v_24739 == nil) goto v_24683;
    goto v_24692;
v_24686:
    v_24741 = stack[-4];
    goto v_24687;
v_24688:
    v_24740 = stack[-3];
    goto v_24689;
v_24690:
    v_24739 = stack[-1];
    goto v_24691;
v_24692:
    goto v_24686;
v_24687:
    goto v_24688;
v_24689:
    goto v_24690;
v_24691:
    return list3(v_24741, v_24740, v_24739);
v_24683:
    v_24739 = stack[-2];
    if (v_24739 == nil) goto v_24699;
    goto v_24708;
v_24702:
    v_24741 = stack[-4];
    goto v_24703;
v_24704:
    v_24740 = stack[-2];
    goto v_24705;
v_24706:
    v_24739 = stack[-1];
    goto v_24707;
v_24708:
    goto v_24702;
v_24703:
    goto v_24704;
v_24705:
    goto v_24706;
v_24707:
    return list3(v_24741, v_24740, v_24739);
v_24699:
    v_24739 = stack[0];
    if (v_24739 == nil) goto v_24715;
    goto v_24724;
v_24718:
    v_24741 = stack[-4];
    goto v_24719;
v_24720:
    v_24740 = stack[0];
    goto v_24721;
v_24722:
    v_24739 = stack[-1];
    goto v_24723;
v_24724:
    goto v_24718;
v_24719:
    goto v_24720;
v_24721:
    goto v_24722;
v_24723:
    return list3(v_24741, v_24740, v_24739);
v_24715:
    goto v_24735;
v_24729:
    v_24741 = stack[-4];
    goto v_24730;
v_24731:
    v_24740 = nil;
    goto v_24732;
v_24733:
    v_24739 = stack[-1];
    goto v_24734;
v_24735:
    goto v_24729;
v_24730:
    goto v_24731;
v_24732:
    goto v_24733;
v_24734:
    return list3(v_24741, v_24740, v_24739);
    return onevalue(v_24739);
}



// Code for simpsqrtsq

static LispObject CC_simpsqrtsq(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24578;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    goto v_24571;
v_24567:
    v_24578 = stack[0];
    v_24578 = qcar(v_24578);
    fn = elt(env, 1); // simpsqrt2
    stack[-1] = (*qfn1(fn))(fn, v_24578);
    env = stack[-2];
    goto v_24568;
v_24569:
    v_24578 = stack[0];
    v_24578 = qcdr(v_24578);
    fn = elt(env, 1); // simpsqrt2
    v_24578 = (*qfn1(fn))(fn, v_24578);
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    {
        LispObject v_24581 = stack[-1];
        return cons(v_24581, v_24578);
    }
}



// Code for spcol_dim

static LispObject CC_spcol_dim(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24593;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    v_24593 = qvalue(elt(env, 2)); // !*fast_la
    if (v_24593 == nil) goto v_24576;
    else goto v_24577;
v_24576:
    v_24593 = stack[0];
    fn = elt(env, 4); // matrixp
    v_24593 = (*qfn1(fn))(fn, v_24593);
    env = stack[-1];
    v_24593 = (v_24593 == nil ? lisp_true : nil);
    goto v_24575;
v_24577:
    v_24593 = nil;
    goto v_24575;
    v_24593 = nil;
v_24575:
    if (v_24593 == nil) goto v_24573;
    v_24593 = elt(env, 3); // "Error in spcol_dim: input should be a matrix."
    fn = elt(env, 5); // rederr
    v_24593 = (*qfn1(fn))(fn, v_24593);
    env = stack[-1];
    goto v_24571;
v_24573:
v_24571:
    v_24593 = stack[0];
    fn = elt(env, 6); // spmatlength
    v_24593 = (*qfn1(fn))(fn, v_24593);
    v_24593 = qcdr(v_24593);
    v_24593 = qcdr(v_24593);
    v_24593 = qcar(v_24593);
    return onevalue(v_24593);
}



// Code for on!-double1

static LispObject CC_onKdouble1(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24593;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
v_24568:
    v_24593 = stack[0];
    v_24593 = Lconsp(nil, v_24593);
    env = stack[-1];
    if (v_24593 == nil) goto v_24572;
    v_24593 = stack[0];
    v_24593 = qcar(v_24593);
    fn = elt(env, 2); // doublep
    v_24593 = (*qfn1(fn))(fn, v_24593);
    env = stack[-1];
    if (v_24593 == nil) goto v_24578;
    v_24593 = lisp_true;
    qvalue(elt(env, 1)) = v_24593; // !*double
    goto v_24567;
v_24578:
    v_24593 = stack[0];
    v_24593 = qcar(v_24593);
    v_24593 = CC_onKdouble1(elt(env, 0), v_24593);
    env = stack[-1];
    v_24593 = stack[0];
    v_24593 = qcdr(v_24593);
    stack[0] = v_24593;
    goto v_24568;
    goto v_24570;
v_24572:
    v_24593 = nil;
    goto v_24567;
v_24570:
    v_24593 = nil;
v_24567:
    return onevalue(v_24593);
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24591, v_24592, v_24593;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24592 = v_24565;
    v_24593 = v_24564;
// end of prologue
    v_24591 = v_24593;
    v_24591 = qcar(v_24591);
    if (!consp(v_24591)) goto v_24569;
    else goto v_24570;
v_24569:
    goto v_24578;
v_24574:
    v_24591 = v_24593;
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    {
        fn = elt(env, 1); // gffdiff
        return (*qfn2(fn))(fn, v_24591, v_24592);
    }
v_24570:
    goto v_24588;
v_24584:
    v_24591 = v_24593;
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    {
        fn = elt(env, 2); // gbfdiff
        return (*qfn2(fn))(fn, v_24591, v_24592);
    }
    v_24591 = nil;
    return onevalue(v_24591);
}



// Code for r2speclist1

static LispObject CC_r2speclist1(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24607, v_24608, v_24609;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24607 = v_24564;
// end of prologue
    goto v_24575;
v_24571:
    v_24609 = v_24607;
    goto v_24572;
v_24573:
    v_24608 = elt(env, 1); // times
    goto v_24574;
v_24575:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    if (!consp(v_24609)) goto v_24569;
    v_24609 = qcar(v_24609);
    if (v_24609 == v_24608) goto v_24568;
    else goto v_24569;
v_24568:
    goto v_24585;
v_24579:
    v_24608 = v_24607;
    v_24608 = qcdr(v_24608);
    v_24609 = qcar(v_24608);
    goto v_24580;
v_24581:
    v_24608 = v_24607;
    v_24608 = qcdr(v_24608);
    v_24608 = qcdr(v_24608);
    v_24608 = qcar(v_24608);
    goto v_24582;
v_24583:
    v_24607 = qcdr(v_24607);
    v_24607 = qcdr(v_24607);
    v_24607 = qcdr(v_24607);
    goto v_24584;
v_24585:
    goto v_24579;
v_24580:
    goto v_24581;
v_24582:
    goto v_24583;
v_24584:
    {
        fn = elt(env, 2); // r2speclist2
        return (*qfnn(fn))(fn, 3, v_24609, v_24608, v_24607);
    }
v_24569:
    goto v_24604;
v_24600:
    v_24608 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24601;
v_24602:
    goto v_24603;
v_24604:
    goto v_24600;
v_24601:
    goto v_24602;
v_24603:
    return cons(v_24608, v_24607);
    v_24607 = nil;
    return onevalue(v_24607);
}



// Code for mkassign

static LispObject CC_mkassign(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24578, v_24579, v_24580;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24578 = v_24565;
    v_24579 = v_24564;
// end of prologue
    goto v_24574;
v_24568:
    v_24580 = elt(env, 1); // setq
    goto v_24569;
v_24570:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    goto v_24572;
v_24573:
    return list3(v_24580, v_24579, v_24578);
}



// Code for consrecip

static LispObject CC_consrecip(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24606, v_24607, v_24608;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24608 = v_24564;
// end of prologue
    goto v_24578;
v_24574:
    v_24606 = v_24608;
    v_24607 = qcar(v_24606);
    goto v_24575;
v_24576:
    v_24606 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24577;
v_24578:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    if (v_24607 == v_24606) goto v_24572;
    else goto v_24573;
v_24572:
    v_24606 = lisp_true;
    goto v_24571;
v_24573:
    goto v_24589;
v_24585:
    v_24606 = v_24608;
    v_24607 = qcar(v_24606);
    goto v_24586;
v_24587:
    v_24606 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_24588;
v_24589:
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    v_24606 = (v_24607 == v_24606 ? lisp_true : nil);
    goto v_24571;
    v_24606 = nil;
v_24571:
    if (v_24606 == nil) goto v_24569;
    v_24606 = v_24608;
    v_24606 = qcar(v_24606);
    goto v_24567;
v_24569:
    goto v_24603;
v_24599:
    v_24606 = elt(env, 1); // recip
    goto v_24600;
v_24601:
    v_24607 = v_24608;
    goto v_24602;
v_24603:
    goto v_24599;
v_24600:
    goto v_24601;
v_24602:
    return cons(v_24606, v_24607);
    v_24606 = nil;
v_24567:
    return onevalue(v_24606);
}



// Code for simpdfp

static LispObject CC_simpdfp(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24912, v_24913, v_24914, v_24915, v_24916;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    goto v_24585;
v_24581:
    v_24912 = stack[0];
    v_24913 = Llength(nil, v_24912);
    env = stack[-6];
    goto v_24582;
v_24583:
    v_24912 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24584;
v_24585:
    goto v_24581;
v_24582:
    goto v_24583;
v_24584:
    v_24912 = (LispObject)lessp2(v_24913, v_24912);
    v_24912 = v_24912 ? lisp_true : nil;
    env = stack[-6];
    if (v_24912 == nil) goto v_24579;
    goto v_24574;
v_24579:
    v_24912 = stack[0];
    v_24912 = qcar(v_24912);
    fn = elt(env, 11); // reval
    v_24912 = (*qfn1(fn))(fn, v_24912);
    env = stack[-6];
    stack[-5] = v_24912;
    v_24912 = stack[-5];
    v_24912 = Lconsp(nil, v_24912);
    env = stack[-6];
    if (v_24912 == nil) goto v_24594;
    else goto v_24595;
v_24594:
    goto v_24606;
v_24602:
    v_24912 = stack[0];
    v_24912 = qcdr(v_24912);
    v_24913 = qcar(v_24912);
    goto v_24603;
v_24604:
    v_24912 = qvalue(elt(env, 2)); // frlis!*
    goto v_24605;
v_24606:
    goto v_24602;
v_24603:
    goto v_24604;
v_24605:
    v_24912 = Lmember(nil, v_24913, v_24912);
    if (v_24912 == nil) goto v_24601;
    goto v_24617;
v_24613:
    goto v_24623;
v_24619:
    v_24913 = elt(env, 3); // dfp
    goto v_24620;
v_24621:
    v_24912 = stack[0];
    goto v_24622;
v_24623:
    goto v_24619;
v_24620:
    goto v_24621;
v_24622:
    v_24913 = cons(v_24913, v_24912);
    env = stack[-6];
    goto v_24614;
v_24615:
    v_24912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24616;
v_24617:
    goto v_24613;
v_24614:
    goto v_24615;
v_24616:
    {
        fn = elt(env, 12); // mksq
        return (*qfn2(fn))(fn, v_24913, v_24912);
    }
v_24601:
    goto v_24635;
v_24631:
    v_24913 = stack[-5];
    goto v_24632;
v_24633:
    v_24912 = stack[0];
    v_24912 = qcdr(v_24912);
    v_24912 = qcar(v_24912);
    v_24912 = qcdr(v_24912);
    goto v_24634;
v_24635:
    goto v_24631;
v_24632:
    goto v_24633;
v_24634:
    v_24912 = cons(v_24913, v_24912);
    env = stack[-6];
    {
        fn = elt(env, 13); // simpdf
        return (*qfn1(fn))(fn, v_24912);
    }
    v_24912 = nil;
    goto v_24573;
v_24595:
    v_24912 = stack[-5];
    v_24912 = qcar(v_24912);
    stack[-1] = v_24912;
    v_24912 = stack[0];
    v_24912 = qcdr(v_24912);
    v_24912 = qcar(v_24912);
    fn = elt(env, 11); // reval
    v_24912 = (*qfn1(fn))(fn, v_24912);
    env = stack[-6];
    v_24916 = v_24912;
    goto v_24661;
v_24657:
    v_24913 = v_24916;
    goto v_24658;
v_24659:
    v_24912 = qvalue(elt(env, 2)); // frlis!*
    goto v_24660;
v_24661:
    goto v_24657;
v_24658:
    goto v_24659;
v_24660:
    v_24912 = Lmember(nil, v_24913, v_24912);
    if (v_24912 == nil) goto v_24655;
    else goto v_24656;
v_24655:
    goto v_24670;
v_24666:
    v_24913 = v_24916;
    goto v_24667;
v_24668:
    v_24912 = elt(env, 4); // list
    goto v_24669;
v_24670:
    goto v_24666;
v_24667:
    goto v_24668;
v_24669:
    v_24912 = Leqcar(nil, v_24913, v_24912);
    env = stack[-6];
    v_24912 = (v_24912 == nil ? lisp_true : nil);
    goto v_24654;
v_24656:
    v_24912 = nil;
    goto v_24654;
    v_24912 = nil;
v_24654:
    if (v_24912 == nil) goto v_24652;
    goto v_24682;
v_24678:
    stack[-4] = v_24916;
    goto v_24679;
v_24680:
    v_24912 = stack[0];
    v_24912 = qcdr(v_24912);
    v_24912 = qcdr(v_24912);
    stack[-3] = v_24912;
    v_24912 = stack[-3];
    if (v_24912 == nil) goto v_24695;
    else goto v_24696;
v_24695:
    v_24912 = nil;
    goto v_24688;
v_24696:
    v_24912 = stack[-3];
    v_24912 = qcar(v_24912);
    fn = elt(env, 11); // reval
    v_24912 = (*qfn1(fn))(fn, v_24912);
    env = stack[-6];
    v_24912 = ncons(v_24912);
    env = stack[-6];
    stack[-1] = v_24912;
    stack[-2] = v_24912;
v_24689:
    v_24912 = stack[-3];
    v_24912 = qcdr(v_24912);
    stack[-3] = v_24912;
    v_24912 = stack[-3];
    if (v_24912 == nil) goto v_24709;
    else goto v_24710;
v_24709:
    v_24912 = stack[-2];
    goto v_24688;
v_24710:
    goto v_24718;
v_24714:
    stack[0] = stack[-1];
    goto v_24715;
v_24716:
    v_24912 = stack[-3];
    v_24912 = qcar(v_24912);
    fn = elt(env, 11); // reval
    v_24912 = (*qfn1(fn))(fn, v_24912);
    env = stack[-6];
    v_24912 = ncons(v_24912);
    env = stack[-6];
    goto v_24717;
v_24718:
    goto v_24714;
v_24715:
    goto v_24716;
v_24717:
    v_24912 = Lrplacd(nil, stack[0], v_24912);
    env = stack[-6];
    v_24912 = stack[-1];
    v_24912 = qcdr(v_24912);
    stack[-1] = v_24912;
    goto v_24689;
v_24688:
    goto v_24681;
v_24682:
    goto v_24678;
v_24679:
    goto v_24680;
v_24681:
    v_24912 = cons(stack[-4], v_24912);
    env = stack[-6];
    v_24916 = v_24912;
    goto v_24733;
v_24729:
    stack[0] = elt(env, 4); // list
    goto v_24730;
v_24731:
    goto v_24740;
v_24736:
    v_24913 = v_24916;
    goto v_24737;
v_24738:
    v_24912 = nil;
    goto v_24739;
v_24740:
    goto v_24736;
v_24737:
    goto v_24738;
v_24739:
    fn = elt(env, 14); // dfp!-normalize
    v_24912 = (*qfn2(fn))(fn, v_24913, v_24912);
    env = stack[-6];
    goto v_24732;
v_24733:
    goto v_24729;
v_24730:
    goto v_24731;
v_24732:
    v_24912 = cons(stack[0], v_24912);
    env = stack[-6];
    v_24916 = v_24912;
    goto v_24751;
v_24745:
    v_24913 = elt(env, 3); // dfp
    goto v_24746;
v_24747:
    v_24912 = stack[-5];
    goto v_24748;
v_24749:
    v_24914 = v_24916;
    goto v_24750;
v_24751:
    goto v_24745;
v_24746:
    goto v_24747;
v_24748:
    goto v_24749;
v_24750:
    v_24912 = list3(v_24913, v_24912, v_24914);
    env = stack[-6];
    {
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(fn, v_24912);
    }
v_24652:
    goto v_24761;
v_24757:
    v_24913 = stack[-1];
    goto v_24758;
v_24759:
    v_24912 = elt(env, 5); // generic_function
    goto v_24760;
v_24761:
    goto v_24757;
v_24758:
    goto v_24759;
v_24760:
    v_24912 = get(v_24913, v_24912);
    env = stack[-6];
    v_24915 = v_24912;
    v_24912 = lisp_true;
    v_24913 = v_24915;
    if (v_24913 == nil) goto v_24768;
    goto v_24777;
v_24773:
    v_24914 = v_24916;
    goto v_24774;
v_24775:
    v_24913 = elt(env, 4); // list
    goto v_24776;
v_24777:
    goto v_24773;
v_24774:
    goto v_24775;
v_24776:
    if (!consp(v_24914)) goto v_24768;
    v_24914 = qcar(v_24914);
    if (v_24914 == v_24913) goto v_24771;
    else goto v_24768;
v_24771:
    v_24913 = v_24916;
    v_24913 = qcdr(v_24913);
    v_24914 = v_24913;
v_24783:
    v_24913 = v_24914;
    if (v_24913 == nil) goto v_24788;
    else goto v_24789;
v_24788:
    goto v_24782;
v_24789:
    v_24913 = v_24914;
    v_24913 = qcar(v_24913);
    if (v_24912 == nil) goto v_24797;
    else goto v_24798;
v_24797:
    v_24912 = nil;
    goto v_24796;
v_24798:
    goto v_24807;
v_24803:
    goto v_24804;
v_24805:
    v_24912 = v_24915;
    goto v_24806;
v_24807:
    goto v_24803;
v_24804:
    goto v_24805;
v_24806:
    v_24912 = Lmember(nil, v_24913, v_24912);
    goto v_24796;
    v_24912 = nil;
v_24796:
    v_24913 = v_24914;
    v_24913 = qcdr(v_24913);
    v_24914 = v_24913;
    goto v_24783;
v_24782:
    goto v_24766;
v_24768:
v_24766:
    if (v_24912 == nil) goto v_24815;
    else goto v_24816;
v_24815:
    goto v_24823;
v_24819:
    v_24913 = nil;
    goto v_24820;
v_24821:
    v_24912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24822;
v_24823:
    goto v_24819;
v_24820:
    goto v_24821;
v_24822:
    return cons(v_24913, v_24912);
v_24816:
    goto v_24834;
v_24830:
    v_24913 = v_24916;
    goto v_24831;
v_24832:
    v_24912 = elt(env, 6); // (list)
    goto v_24833;
v_24834:
    goto v_24830;
v_24831:
    goto v_24832;
v_24833:
    if (equal(v_24913, v_24912)) goto v_24828;
    else goto v_24829;
v_24828:
    goto v_24842;
v_24838:
    v_24913 = stack[-5];
    goto v_24839;
v_24840:
    v_24912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24841;
v_24842:
    goto v_24838;
v_24839:
    goto v_24840;
v_24841:
    {
        fn = elt(env, 12); // mksq
        return (*qfn2(fn))(fn, v_24913, v_24912);
    }
v_24829:
    v_24912 = v_24915;
    if (v_24912 == nil) goto v_24848;
    goto v_24857;
v_24853:
    v_24913 = stack[-1];
    goto v_24854;
v_24855:
    v_24912 = elt(env, 7); // dfp_commute
    goto v_24856;
v_24857:
    goto v_24853;
v_24854:
    goto v_24855;
v_24856:
    v_24912 = Lflagp(nil, v_24913, v_24912);
    env = stack[-6];
    if (v_24912 == nil) goto v_24848;
    v_24912 = v_24915;
// Binding kord!*
// FLUIDBIND: reloadenv=6 litvec-offset=8 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 8, -1);
    qvalue(elt(env, 8)) = v_24912; // kord!*
    goto v_24867;
v_24863:
    stack[0] = elt(env, 4); // list
    goto v_24864;
v_24865:
    goto v_24874;
v_24870:
    v_24912 = v_24916;
    v_24913 = qcdr(v_24912);
    goto v_24871;
v_24872:
    v_24912 = elt(env, 9); // ordp
    goto v_24873;
v_24874:
    goto v_24870;
v_24871:
    goto v_24872;
v_24873:
    fn = elt(env, 16); // sort
    v_24912 = (*qfn2(fn))(fn, v_24913, v_24912);
    env = stack[-6];
    goto v_24866;
v_24867:
    goto v_24863;
v_24864:
    goto v_24865;
v_24866:
    v_24912 = cons(stack[0], v_24912);
    env = stack[-6];
    v_24916 = v_24912;
    ;}  // end of a binding scope
    goto v_24846;
v_24848:
v_24846:
    goto v_24885;
v_24879:
    v_24913 = elt(env, 3); // dfp
    goto v_24880;
v_24881:
    v_24912 = stack[-5];
    goto v_24882;
v_24883:
    v_24914 = v_24916;
    goto v_24884;
v_24885:
    goto v_24879;
v_24880:
    goto v_24881;
v_24882:
    goto v_24883;
v_24884:
    v_24912 = list3(v_24913, v_24912, v_24914);
    env = stack[-6];
    stack[0] = v_24912;
    goto v_24894;
v_24890:
    v_24913 = stack[0];
    goto v_24891;
v_24892:
    v_24912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24893;
v_24894:
    goto v_24890;
v_24891:
    goto v_24892;
v_24893:
    {
        fn = elt(env, 12); // mksq
        return (*qfn2(fn))(fn, v_24913, v_24912);
    }
v_24574:
    goto v_24902;
v_24898:
    goto v_24908;
v_24904:
    v_24913 = elt(env, 3); // dfp
    goto v_24905;
v_24906:
    v_24912 = stack[0];
    goto v_24907;
v_24908:
    goto v_24904;
v_24905:
    goto v_24906;
v_24907:
    v_24913 = cons(v_24913, v_24912);
    env = stack[-6];
    goto v_24899;
v_24900:
    v_24912 = elt(env, 10); // "generic differential"
    goto v_24901;
v_24902:
    goto v_24898;
v_24899:
    goto v_24900;
v_24901:
    fn = elt(env, 17); // typerr
    v_24912 = (*qfn2(fn))(fn, v_24913, v_24912);
    v_24912 = nil;
v_24573:
    return onevalue(v_24912);
}



// Code for set!-weights

static LispObject CC_setKweights(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24620;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_24620 = v_24564;
// end of prologue
    goto v_24577;
v_24573:
    stack[-4] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24574;
v_24575:
    v_24620 = qcdr(v_24620);
    stack[-3] = v_24620;
    v_24620 = stack[-3];
    if (v_24620 == nil) goto v_24589;
    else goto v_24590;
v_24589:
    v_24620 = nil;
    goto v_24583;
v_24590:
    v_24620 = (LispObject)16+TAG_FIXNUM; // 1
    v_24620 = ncons(v_24620);
    env = stack[-5];
    stack[-1] = v_24620;
    stack[-2] = v_24620;
v_24584:
    v_24620 = stack[-3];
    v_24620 = qcdr(v_24620);
    stack[-3] = v_24620;
    v_24620 = stack[-3];
    if (v_24620 == nil) goto v_24602;
    else goto v_24603;
v_24602:
    v_24620 = stack[-2];
    goto v_24583;
v_24603:
    goto v_24611;
v_24607:
    stack[0] = stack[-1];
    goto v_24608;
v_24609:
    v_24620 = (LispObject)16+TAG_FIXNUM; // 1
    v_24620 = ncons(v_24620);
    env = stack[-5];
    goto v_24610;
v_24611:
    goto v_24607;
v_24608:
    goto v_24609;
v_24610:
    v_24620 = Lrplacd(nil, stack[0], v_24620);
    env = stack[-5];
    v_24620 = stack[-1];
    v_24620 = qcdr(v_24620);
    stack[-1] = v_24620;
    goto v_24584;
v_24583:
    goto v_24576;
v_24577:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    v_24620 = cons(stack[-4], v_24620);
        return Lnreverse(nil, v_24620);
    return onevalue(v_24620);
}



// Code for simp!-prop!-dist

static LispObject CC_simpKpropKdist(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24698, v_24699, v_24700;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_24699 = v_24564;
// end of prologue
    goto v_24575;
v_24571:
    v_24700 = v_24699;
    goto v_24572;
v_24573:
    v_24698 = elt(env, 1); // plus
    goto v_24574;
v_24575:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    if (!consp(v_24700)) goto v_24569;
    v_24700 = qcar(v_24700);
    if (v_24700 == v_24698) goto v_24568;
    else goto v_24569;
v_24568:
    v_24698 = v_24699;
    v_24698 = qcdr(v_24698);
    v_24699 = v_24698;
    goto v_24567;
v_24569:
    v_24698 = v_24699;
    v_24698 = ncons(v_24698);
    env = stack[-4];
    v_24699 = v_24698;
    goto v_24567;
v_24567:
    v_24698 = v_24699;
    stack[-3] = v_24698;
    v_24698 = stack[-3];
    if (v_24698 == nil) goto v_24593;
    else goto v_24594;
v_24593:
    v_24698 = nil;
    goto v_24588;
v_24594:
    v_24698 = stack[-3];
    v_24698 = qcar(v_24698);
    v_24700 = v_24698;
    goto v_24610;
v_24606:
    v_24699 = v_24700;
    goto v_24607;
v_24608:
    v_24698 = elt(env, 2); // times
    goto v_24609;
v_24610:
    goto v_24606;
v_24607:
    goto v_24608;
v_24609:
    if (!consp(v_24699)) goto v_24604;
    v_24699 = qcar(v_24699);
    if (v_24699 == v_24698) goto v_24603;
    else goto v_24604;
v_24603:
    v_24698 = v_24700;
    v_24698 = qcdr(v_24698);
    goto v_24602;
v_24604:
    v_24698 = v_24700;
    v_24698 = ncons(v_24698);
    env = stack[-4];
    goto v_24602;
    v_24698 = nil;
v_24602:
    v_24700 = v_24698;
    v_24698 = v_24700;
    v_24698 = qcar(v_24698);
    if (is_number(v_24698)) goto v_24621;
    else goto v_24622;
v_24621:
    v_24698 = v_24700;
    v_24698 = qcdr(v_24698);
    v_24700 = v_24698;
    goto v_24620;
v_24622:
v_24620:
    goto v_24632;
v_24628:
    v_24699 = v_24700;
    goto v_24629;
v_24630:
    v_24698 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_24631;
v_24632:
    goto v_24628;
v_24629:
    goto v_24630;
v_24631:
    fn = elt(env, 5); // sort
    v_24698 = (*qfn2(fn))(fn, v_24699, v_24698);
    env = stack[-4];
    v_24698 = ncons(v_24698);
    env = stack[-4];
    stack[-1] = v_24698;
    stack[-2] = v_24698;
v_24589:
    v_24698 = stack[-3];
    v_24698 = qcdr(v_24698);
    stack[-3] = v_24698;
    v_24698 = stack[-3];
    if (v_24698 == nil) goto v_24639;
    else goto v_24640;
v_24639:
    v_24698 = stack[-2];
    goto v_24588;
v_24640:
    goto v_24648;
v_24644:
    stack[0] = stack[-1];
    goto v_24645;
v_24646:
    v_24698 = stack[-3];
    v_24698 = qcar(v_24698);
    v_24700 = v_24698;
    goto v_24663;
v_24659:
    v_24699 = v_24700;
    goto v_24660;
v_24661:
    v_24698 = elt(env, 2); // times
    goto v_24662;
v_24663:
    goto v_24659;
v_24660:
    goto v_24661;
v_24662:
    if (!consp(v_24699)) goto v_24657;
    v_24699 = qcar(v_24699);
    if (v_24699 == v_24698) goto v_24656;
    else goto v_24657;
v_24656:
    v_24698 = v_24700;
    v_24698 = qcdr(v_24698);
    goto v_24655;
v_24657:
    v_24698 = v_24700;
    v_24698 = ncons(v_24698);
    env = stack[-4];
    goto v_24655;
    v_24698 = nil;
v_24655:
    v_24700 = v_24698;
    v_24698 = v_24700;
    v_24698 = qcar(v_24698);
    if (is_number(v_24698)) goto v_24674;
    else goto v_24675;
v_24674:
    v_24698 = v_24700;
    v_24698 = qcdr(v_24698);
    v_24700 = v_24698;
    goto v_24673;
v_24675:
v_24673:
    goto v_24685;
v_24681:
    v_24699 = v_24700;
    goto v_24682;
v_24683:
    v_24698 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_24684;
v_24685:
    goto v_24681;
v_24682:
    goto v_24683;
v_24684:
    fn = elt(env, 5); // sort
    v_24698 = (*qfn2(fn))(fn, v_24699, v_24698);
    env = stack[-4];
    v_24698 = ncons(v_24698);
    env = stack[-4];
    goto v_24647;
v_24648:
    goto v_24644;
v_24645:
    goto v_24646;
v_24647:
    v_24698 = Lrplacd(nil, stack[0], v_24698);
    env = stack[-4];
    v_24698 = stack[-1];
    v_24698 = qcdr(v_24698);
    stack[-1] = v_24698;
    goto v_24589;
v_24588:
    v_24699 = v_24698;
    goto v_24695;
v_24691:
    goto v_24692;
v_24693:
    v_24698 = elt(env, 4); // simp!-prop!-order
    goto v_24694;
v_24695:
    goto v_24691;
v_24692:
    goto v_24693;
v_24694:
    {
        fn = elt(env, 5); // sort
        return (*qfn2(fn))(fn, v_24699, v_24698);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24579, v_24580;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24579 = v_24565;
    v_24580 = v_24564;
// end of prologue
    goto v_24572;
v_24568:
    v_24580 = qcdr(v_24580);
    v_24580 = qcar(v_24580);
    goto v_24569;
v_24570:
    v_24579 = qcdr(v_24579);
    v_24579 = qcar(v_24579);
    goto v_24571;
v_24572:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_24580, v_24579);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC1_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24579, v_24580;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24579 = v_24565;
    v_24580 = v_24564;
// end of prologue
    goto v_24572;
v_24568:
    v_24580 = qcdr(v_24580);
    v_24580 = qcar(v_24580);
    goto v_24569;
v_24570:
    v_24579 = qcdr(v_24579);
    v_24579 = qcar(v_24579);
    goto v_24571;
v_24572:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_24580, v_24579);
    }
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24577, v_24578;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24577 = v_24565;
    v_24578 = v_24564;
// end of prologue
    goto v_24572;
v_24568:
    v_24578 = qcar(v_24578);
    goto v_24569;
v_24570:
    v_24577 = qcar(v_24577);
    goto v_24571;
v_24572:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
        return Llessp(nil, v_24578, v_24577);
}



// Code for xquotient!-mod!-p

static LispObject CC_xquotientKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24770, v_24771, v_24772;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xquotient-mod-p");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_24566;
    stack[-1] = v_24565;
    stack[-2] = v_24564;
// end of prologue
    v_24770 = stack[-2];
    if (v_24770 == nil) goto v_24570;
    else goto v_24571;
v_24570:
    v_24770 = nil;
    goto v_24569;
v_24571:
    v_24770 = stack[-2];
    if (!consp(v_24770)) goto v_24582;
    else goto v_24583;
v_24582:
    v_24770 = lisp_true;
    goto v_24581;
v_24583:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = (consp(v_24770) ? nil : lisp_true);
    goto v_24581;
    v_24770 = nil;
v_24581:
    if (v_24770 == nil) goto v_24579;
    v_24770 = lisp_true;
    goto v_24577;
v_24579:
    goto v_24602;
v_24598:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24771 = qcar(v_24770);
    goto v_24599;
v_24600:
    v_24770 = stack[0];
    goto v_24601;
v_24602:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    if (equal(v_24771, v_24770)) goto v_24597;
    v_24770 = lisp_true;
    goto v_24595;
v_24597:
    goto v_24615;
v_24611:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24771 = qcdr(v_24770);
    goto v_24612;
v_24613:
    v_24770 = stack[-1];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24770 = qcdr(v_24770);
    goto v_24614;
v_24615:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    v_24770 = ((intptr_t)v_24771 < (intptr_t)v_24770) ? lisp_true : nil;
    goto v_24595;
    v_24770 = nil;
v_24595:
    goto v_24577;
    v_24770 = nil;
v_24577:
    if (v_24770 == nil) goto v_24575;
    v_24770 = nil;
    qvalue(elt(env, 1)) = v_24770; // exact!-quotient!-flag
    goto v_24569;
v_24575:
    goto v_24632;
v_24628:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24771 = qcdr(v_24770);
    goto v_24629;
v_24630:
    v_24770 = stack[-1];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24770 = qcdr(v_24770);
    goto v_24631;
v_24632:
    goto v_24628;
v_24629:
    goto v_24630;
v_24631:
    if (equal(v_24771, v_24770)) goto v_24626;
    else goto v_24627;
v_24626:
    goto v_24650;
v_24646:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24771 = qcdr(v_24770);
    goto v_24647;
v_24648:
    v_24770 = stack[-1];
    v_24770 = qcar(v_24770);
    v_24770 = qcdr(v_24770);
    goto v_24649;
v_24650:
    goto v_24646;
v_24647:
    goto v_24648;
v_24649:
    fn = elt(env, 4); // quotient!-mod!-p
    v_24770 = (*qfn2(fn))(fn, v_24771, v_24770);
    env = stack[-4];
    stack[0] = v_24770;
    v_24770 = stack[0];
    if (v_24770 == nil) goto v_24663;
    else goto v_24664;
v_24663:
    v_24770 = lisp_true;
    goto v_24662;
v_24664:
    goto v_24674;
v_24670:
    goto v_24671;
v_24672:
    goto v_24681;
v_24677:
    v_24771 = stack[0];
    goto v_24678;
v_24679:
    v_24770 = stack[-1];
    goto v_24680;
v_24681:
    goto v_24677;
v_24678:
    goto v_24679;
v_24680:
    fn = elt(env, 5); // times!-mod!-p
    v_24770 = (*qfn2(fn))(fn, v_24771, v_24770);
    env = stack[-4];
    goto v_24673;
v_24674:
    goto v_24670;
v_24671:
    goto v_24672;
v_24673:
    fn = elt(env, 6); // difference!-mod!-p
    v_24770 = (*qfn2(fn))(fn, stack[-2], v_24770);
    env = stack[-4];
    goto v_24662;
    v_24770 = nil;
v_24662:
    if (v_24770 == nil) goto v_24660;
    v_24770 = nil;
    qvalue(elt(env, 1)) = v_24770; // exact!-quotient!-flag
    goto v_24658;
v_24660:
v_24658:
    v_24770 = stack[0];
    goto v_24569;
v_24627:
    goto v_24697;
v_24693:
    goto v_24703;
v_24699:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24772 = qcar(v_24770);
    goto v_24700;
v_24701:
    goto v_24712;
v_24708:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24771 = qcdr(v_24770);
    goto v_24709;
v_24710:
    v_24770 = stack[-1];
    v_24770 = qcar(v_24770);
    v_24770 = qcar(v_24770);
    v_24770 = qcdr(v_24770);
    goto v_24711;
v_24712:
    goto v_24708;
v_24709:
    goto v_24710;
v_24711:
    v_24770 = (LispObject)(intptr_t)((intptr_t)v_24771 - (intptr_t)v_24770 + TAG_FIXNUM);
    goto v_24702;
v_24703:
    goto v_24699;
v_24700:
    goto v_24701;
v_24702:
    fn = elt(env, 7); // mksp
    stack[-3] = (*qfn2(fn))(fn, v_24772, v_24770);
    env = stack[-4];
    goto v_24694;
v_24695:
    goto v_24727;
v_24723:
    v_24770 = stack[-2];
    v_24770 = qcar(v_24770);
    v_24771 = qcdr(v_24770);
    goto v_24724;
v_24725:
    v_24770 = stack[-1];
    v_24770 = qcar(v_24770);
    v_24770 = qcdr(v_24770);
    goto v_24726;
v_24727:
    goto v_24723;
v_24724:
    goto v_24725;
v_24726:
    fn = elt(env, 4); // quotient!-mod!-p
    v_24770 = (*qfn2(fn))(fn, v_24771, v_24770);
    env = stack[-4];
    goto v_24696;
v_24697:
    goto v_24693;
v_24694:
    goto v_24695;
v_24696:
    v_24770 = cons(stack[-3], v_24770);
    env = stack[-4];
    stack[-3] = v_24770;
    goto v_24739;
v_24735:
    v_24770 = stack[-2];
    stack[-2] = qcdr(v_24770);
    goto v_24736;
v_24737:
    goto v_24747;
v_24743:
    v_24770 = stack[-3];
    fn = elt(env, 8); // negate!-term
    v_24771 = (*qfn1(fn))(fn, v_24770);
    env = stack[-4];
    goto v_24744;
v_24745:
    v_24770 = stack[-1];
    v_24770 = qcdr(v_24770);
    goto v_24746;
v_24747:
    goto v_24743;
v_24744:
    goto v_24745;
v_24746:
    fn = elt(env, 9); // times!-term!-mod!-p
    v_24770 = (*qfn2(fn))(fn, v_24771, v_24770);
    env = stack[-4];
    goto v_24738;
v_24739:
    goto v_24735;
v_24736:
    goto v_24737;
v_24738:
    fn = elt(env, 10); // plus!-mod!-p
    v_24770 = (*qfn2(fn))(fn, stack[-2], v_24770);
    env = stack[-4];
    stack[-2] = v_24770;
    goto v_24757;
v_24753:
    goto v_24754;
v_24755:
    goto v_24766;
v_24760:
    v_24772 = stack[-2];
    goto v_24761;
v_24762:
    v_24771 = stack[-1];
    goto v_24763;
v_24764:
    v_24770 = stack[0];
    goto v_24765;
v_24766:
    goto v_24760;
v_24761:
    goto v_24762;
v_24763:
    goto v_24764;
v_24765:
    v_24770 = CC_xquotientKmodKp(elt(env, 0), 3, v_24772, v_24771, v_24770);
    goto v_24756;
v_24757:
    goto v_24753;
v_24754:
    goto v_24755;
v_24756:
    {
        LispObject v_24777 = stack[-3];
        return cons(v_24777, v_24770);
    }
    goto v_24569;
    v_24770 = nil;
v_24569:
    return onevalue(v_24770);
}



// Code for fctargs

static LispObject CC_fctargs(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24580, v_24581;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24580 = v_24564;
// end of prologue
    goto v_24574;
v_24570:
    goto v_24571;
v_24572:
    v_24581 = qvalue(elt(env, 1)); // depl!*
    goto v_24573;
v_24574:
    goto v_24570;
v_24571:
    goto v_24572;
v_24573:
    v_24581 = Lassoc(nil, v_24580, v_24581);
    v_24580 = v_24581;
    if (v_24581 == nil) goto v_24569;
    v_24580 = qcdr(v_24580);
    goto v_24567;
v_24569:
    v_24580 = nil;
v_24567:
    return onevalue(v_24580);
}



// Code for talp_trygaussvar

static LispObject CC_talp_trygaussvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24645, v_24646, v_24647;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_trygaussvar");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24566;
    stack[-1] = v_24565;
    stack[-2] = v_24564;
// end of prologue
    v_24645 = stack[-1];
    fn = elt(env, 4); // talp_atfp
    v_24645 = (*qfn1(fn))(fn, v_24645);
    env = stack[-3];
    if (v_24645 == nil) goto v_24571;
    goto v_24579;
v_24575:
    v_24646 = stack[-2];
    goto v_24576;
v_24577:
    v_24645 = stack[-1];
    goto v_24578;
v_24579:
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    {
        fn = elt(env, 5); // talp_qesolset
        return (*qfn2(fn))(fn, v_24646, v_24645);
    }
v_24571:
    goto v_24588;
v_24584:
    v_24645 = stack[-1];
    if (!consp(v_24645)) goto v_24591;
    else goto v_24592;
v_24591:
    v_24645 = stack[-1];
    v_24646 = v_24645;
    goto v_24590;
v_24592:
    v_24645 = stack[-1];
    v_24645 = qcar(v_24645);
    v_24646 = v_24645;
    goto v_24590;
    v_24646 = nil;
v_24590:
    goto v_24585;
v_24586:
    v_24645 = elt(env, 1); // and
    goto v_24587;
v_24588:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    if (v_24646 == v_24645) goto v_24582;
    else goto v_24583;
v_24582:
    goto v_24607;
v_24601:
    v_24647 = stack[-2];
    goto v_24602;
v_24603:
    v_24645 = stack[-1];
    v_24646 = qcdr(v_24645);
    goto v_24604;
v_24605:
    v_24645 = stack[0];
    goto v_24606;
v_24607:
    goto v_24601;
v_24602:
    goto v_24603;
v_24604:
    goto v_24605;
v_24606:
    {
        fn = elt(env, 6); // talp_gaussand
        return (*qfnn(fn))(fn, 3, v_24647, v_24646, v_24645);
    }
v_24583:
    goto v_24618;
v_24614:
    v_24645 = stack[-1];
    if (!consp(v_24645)) goto v_24621;
    else goto v_24622;
v_24621:
    v_24645 = stack[-1];
    v_24646 = v_24645;
    goto v_24620;
v_24622:
    v_24645 = stack[-1];
    v_24645 = qcar(v_24645);
    v_24646 = v_24645;
    goto v_24620;
    v_24646 = nil;
v_24620:
    goto v_24615;
v_24616:
    v_24645 = elt(env, 2); // or
    goto v_24617;
v_24618:
    goto v_24614;
v_24615:
    goto v_24616;
v_24617:
    if (v_24646 == v_24645) goto v_24612;
    else goto v_24613;
v_24612:
    goto v_24637;
v_24631:
    v_24647 = stack[-2];
    goto v_24632;
v_24633:
    v_24645 = stack[-1];
    v_24646 = qcdr(v_24645);
    goto v_24634;
v_24635:
    v_24645 = stack[0];
    goto v_24636;
v_24637:
    goto v_24631;
v_24632:
    goto v_24633;
v_24634:
    goto v_24635;
v_24636:
    {
        fn = elt(env, 7); // talp_gaussor
        return (*qfnn(fn))(fn, 3, v_24647, v_24646, v_24645);
    }
v_24613:
    v_24645 = elt(env, 3); // failed
    goto v_24569;
    v_24645 = nil;
v_24569:
    return onevalue(v_24645);
}



// Code for transposerd

static LispObject CC_transposerd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24573;
    LispObject fn;
    argcheck(nargs, 0, "transposerd");
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
    fn = elt(env, 2); // mathml
    v_24573 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_24573;
    fn = elt(env, 3); // lex
    v_24573 = (*qfnn(fn))(fn, 0);
    v_24573 = stack[0];
    return ncons(v_24573);
    return onevalue(v_24573);
}



// Code for findelem2

static LispObject CC_findelem2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24624, v_24625, v_24626, v_24627, v_24628;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findelem2");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24624 = v_24566;
    v_24625 = v_24565;
    v_24626 = v_24564;
// end of prologue
    v_24627 = v_24626;
    v_24627 = Lconsp(nil, v_24627);
    env = stack[0];
    if (v_24627 == nil) goto v_24578;
    goto v_24587;
v_24583:
    v_24627 = v_24626;
    v_24627 = qcar(v_24627);
    goto v_24584;
v_24585:
    v_24628 = elt(env, 2); // sparsemat
    goto v_24586;
v_24587:
    goto v_24583;
v_24584:
    goto v_24585;
v_24586:
    if (v_24627 == v_24628) goto v_24582;
    else goto v_24578;
v_24582:
    v_24626 = qcdr(v_24626);
    v_24626 = qcar(v_24626);
    goto v_24576;
v_24578:
    goto v_24576;
v_24576:
    goto v_24601;
v_24597:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    goto v_24597;
v_24598:
    goto v_24599;
v_24600:
    v_24625 = *(LispObject *)((char *)v_24626 + (CELL-TAG_VECTOR) + (((intptr_t)v_24625-TAG_FIXNUM)/(16/CELL)));
    goto v_24609;
v_24605:
    goto v_24606;
v_24607:
    goto v_24608;
v_24609:
    goto v_24605;
v_24606:
    goto v_24607;
v_24608:
    v_24624 = Latsoc(nil, v_24624, v_24625);
    v_24625 = v_24624;
    v_24624 = v_24625;
    if (v_24624 == nil) goto v_24615;
    else goto v_24616;
v_24615:
    v_24624 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24614;
v_24616:
    v_24624 = v_24625;
    v_24624 = qcdr(v_24624);
    goto v_24614;
v_24614:
    return onevalue(v_24624);
}



// Code for inszzz

static LispObject CC_inszzz(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24684, v_24685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24565;
    stack[-2] = v_24564;
// end of prologue
    stack[-3] = nil;
v_24570:
    v_24684 = stack[-1];
    if (v_24684 == nil) goto v_24577;
    else goto v_24578;
v_24577:
    v_24684 = lisp_true;
    goto v_24576;
v_24578:
    goto v_24588;
v_24584:
    v_24684 = stack[-1];
    v_24684 = qcar(v_24684);
    v_24685 = qcar(v_24684);
    goto v_24585;
v_24586:
    v_24684 = stack[-2];
    v_24684 = qcar(v_24684);
    goto v_24587;
v_24588:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    v_24684 = (LispObject)lessp2(v_24685, v_24684);
    v_24684 = v_24684 ? lisp_true : nil;
    env = stack[-4];
    goto v_24576;
    v_24684 = nil;
v_24576:
    if (v_24684 == nil) goto v_24574;
    goto v_24599;
v_24595:
    stack[0] = stack[-3];
    goto v_24596;
v_24597:
    goto v_24606;
v_24602:
    v_24685 = stack[-2];
    goto v_24603;
v_24604:
    v_24684 = stack[-1];
    goto v_24605;
v_24606:
    goto v_24602;
v_24603:
    goto v_24604;
v_24605:
    v_24684 = cons(v_24685, v_24684);
    env = stack[-4];
    goto v_24598;
v_24599:
    goto v_24595;
v_24596:
    goto v_24597;
v_24598:
    {
        LispObject v_24690 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_24690, v_24684);
    }
v_24574:
    goto v_24615;
v_24611:
    v_24684 = stack[-1];
    v_24684 = qcar(v_24684);
    v_24685 = qcar(v_24684);
    goto v_24612;
v_24613:
    v_24684 = stack[-2];
    v_24684 = qcar(v_24684);
    goto v_24614;
v_24615:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    if (equal(v_24685, v_24684)) goto v_24609;
    else goto v_24610;
v_24609:
    goto v_24626;
v_24622:
    v_24684 = stack[-1];
    v_24684 = qcar(v_24684);
    stack[0] = qcdr(v_24684);
    goto v_24623;
v_24624:
    goto v_24635;
v_24631:
    v_24684 = stack[-1];
    v_24684 = qcar(v_24684);
    v_24684 = qcdr(v_24684);
    v_24685 = qcar(v_24684);
    goto v_24632;
v_24633:
    v_24684 = stack[-2];
    v_24684 = qcdr(v_24684);
    v_24684 = qcar(v_24684);
    goto v_24634;
v_24635:
    goto v_24631;
v_24632:
    goto v_24633;
v_24634:
    fn = elt(env, 2); // dm!-plus
    v_24684 = (*qfn2(fn))(fn, v_24685, v_24684);
    env = stack[-4];
    goto v_24625;
v_24626:
    goto v_24622;
v_24623:
    goto v_24624;
v_24625:
    v_24684 = Lrplaca(nil, stack[0], v_24684);
    env = stack[-4];
    v_24684 = stack[-1];
    v_24684 = qcar(v_24684);
    v_24684 = qcdr(v_24684);
    v_24684 = qcar(v_24684);
    fn = elt(env, 3); // zeropp
    v_24684 = (*qfn1(fn))(fn, v_24684);
    env = stack[-4];
    if (v_24684 == nil) goto v_24646;
    goto v_24657;
v_24653:
    v_24685 = stack[-3];
    goto v_24654;
v_24655:
    v_24684 = stack[-1];
    v_24684 = qcdr(v_24684);
    goto v_24656;
v_24657:
    goto v_24653;
v_24654:
    goto v_24655;
v_24656:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_24685, v_24684);
    }
v_24646:
    goto v_24668;
v_24664:
    v_24685 = stack[-3];
    goto v_24665;
v_24666:
    v_24684 = stack[-1];
    goto v_24667;
v_24668:
    goto v_24664;
v_24665:
    goto v_24666;
v_24667:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_24685, v_24684);
    }
    goto v_24572;
v_24610:
    goto v_24678;
v_24674:
    v_24684 = stack[-1];
    v_24685 = qcar(v_24684);
    goto v_24675;
v_24676:
    v_24684 = stack[-3];
    goto v_24677;
v_24678:
    goto v_24674;
v_24675:
    goto v_24676;
v_24677:
    v_24684 = cons(v_24685, v_24684);
    env = stack[-4];
    stack[-3] = v_24684;
    v_24684 = stack[-1];
    v_24684 = qcdr(v_24684);
    stack[-1] = v_24684;
    goto v_24570;
v_24572:
    v_24684 = nil;
    return onevalue(v_24684);
}



// Code for size_of_matrix

static LispObject CC_size_of_matrix(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24596, v_24597;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    v_24596 = stack[0];
    fn = elt(env, 2); // matrix_input_test
    v_24596 = (*qfn1(fn))(fn, v_24596);
    env = stack[-2];
    goto v_24580;
v_24576:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_24577;
v_24578:
    v_24596 = stack[0];
    v_24596 = Llength(nil, v_24596);
    env = stack[-2];
    goto v_24579;
v_24580:
    goto v_24576;
v_24577:
    goto v_24578;
v_24579:
    v_24596 = plus2(stack[-1], v_24596);
    env = stack[-2];
    stack[-1] = v_24596;
    v_24596 = stack[0];
    v_24596 = qcdr(v_24596);
    v_24596 = qcar(v_24596);
    v_24596 = Llength(nil, v_24596);
    goto v_24593;
v_24589:
    v_24597 = stack[-1];
    goto v_24590;
v_24591:
    goto v_24592;
v_24593:
    goto v_24589;
v_24590:
    goto v_24591;
v_24592:
    return list2(v_24597, v_24596);
    return onevalue(v_24596);
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24643, v_24644, v_24645;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_24645 = v_24564;
// end of prologue
    goto v_24578;
v_24574:
    v_24644 = v_24645;
    goto v_24575;
v_24576:
    v_24643 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24577;
v_24578:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    if (v_24644 == v_24643) goto v_24572;
    else goto v_24573;
v_24572:
    v_24643 = lisp_true;
    goto v_24571;
v_24573:
    v_24643 = v_24645;
    v_24643 = (v_24643 == nil ? lisp_true : nil);
    goto v_24571;
    v_24643 = nil;
v_24571:
    if (v_24643 == nil) goto v_24569;
    goto v_24595;
v_24587:
    stack[-2] = elt(env, 1); // vdp
    goto v_24588;
v_24589:
    stack[-1] = nil;
    goto v_24590;
v_24591:
    goto v_24603;
v_24599:
    v_24644 = nil;
    goto v_24600;
v_24601:
    v_24643 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24602;
v_24603:
    goto v_24599;
v_24600:
    goto v_24601;
v_24602:
    stack[0] = cons(v_24644, v_24643);
    env = stack[-3];
    goto v_24592;
v_24593:
    goto v_24611;
v_24607:
    v_24644 = nil;
    goto v_24608;
v_24609:
    v_24643 = nil;
    goto v_24610;
v_24611:
    goto v_24607;
v_24608:
    goto v_24609;
v_24610:
    v_24643 = list2(v_24644, v_24643);
    goto v_24594;
v_24595:
    goto v_24587;
v_24588:
    goto v_24589;
v_24590:
    goto v_24591;
v_24592:
    goto v_24593;
v_24594:
    {
        LispObject v_24649 = stack[-2];
        LispObject v_24650 = stack[-1];
        LispObject v_24651 = stack[0];
        return list3star(v_24649, v_24650, v_24651, v_24643);
    }
v_24569:
    v_24643 = v_24645;
    fn = elt(env, 2); // a2dip
    v_24643 = (*qfn1(fn))(fn, v_24643);
    env = stack[-3];
    v_24644 = v_24643;
    goto v_24628;
v_24620:
    stack[-2] = elt(env, 1); // vdp
    goto v_24621;
v_24622:
    v_24643 = v_24644;
    stack[-1] = qcar(v_24643);
    goto v_24623;
v_24624:
    v_24643 = v_24644;
    v_24643 = qcdr(v_24643);
    stack[0] = qcar(v_24643);
    goto v_24625;
v_24626:
    goto v_24640;
v_24636:
    goto v_24637;
v_24638:
    v_24643 = nil;
    goto v_24639;
v_24640:
    goto v_24636;
v_24637:
    goto v_24638;
v_24639:
    v_24643 = list2(v_24644, v_24643);
    goto v_24627;
v_24628:
    goto v_24620;
v_24621:
    goto v_24622;
v_24623:
    goto v_24624;
v_24625:
    goto v_24626;
v_24627:
    {
        LispObject v_24652 = stack[-2];
        LispObject v_24653 = stack[-1];
        LispObject v_24654 = stack[0];
        return list3star(v_24652, v_24653, v_24654, v_24643);
    }
    v_24643 = nil;
    return onevalue(v_24643);
}



// Code for splitup

static LispObject CC_splitup(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24639, v_24640, v_24641;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24641 = v_24565;
    stack[0] = v_24564;
// end of prologue
    v_24639 = stack[0];
    if (v_24639 == nil) goto v_24569;
    else goto v_24570;
v_24569:
    goto v_24577;
v_24573:
    v_24640 = nil;
    goto v_24574;
v_24575:
    v_24639 = nil;
    goto v_24576;
v_24577:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    return list2(v_24640, v_24639);
v_24570:
    v_24639 = stack[0];
    v_24639 = qcar(v_24639);
    v_24639 = qcar(v_24639);
    v_24639 = qcar(v_24639);
    v_24640 = v_24639;
    v_24639 = v_24640;
    if (v_24639 == nil) goto v_24589;
    else goto v_24590;
v_24589:
    v_24639 = lisp_true;
    goto v_24588;
v_24590:
    goto v_24599;
v_24595:
    goto v_24596;
v_24597:
    v_24639 = v_24641;
    goto v_24598;
v_24599:
    goto v_24595;
v_24596:
    goto v_24597;
v_24598:
    v_24639 = Lmemq(nil, v_24640, v_24639);
    goto v_24588;
    v_24639 = nil;
v_24588:
    if (v_24639 == nil) goto v_24581;
    goto v_24608;
v_24604:
    v_24640 = nil;
    goto v_24605;
v_24606:
    v_24639 = stack[0];
    goto v_24607;
v_24608:
    goto v_24604;
v_24605:
    goto v_24606;
v_24607:
    return list2(v_24640, v_24639);
v_24581:
    goto v_24618;
v_24614:
    v_24639 = stack[0];
    v_24639 = qcdr(v_24639);
    goto v_24615;
v_24616:
    v_24640 = v_24641;
    goto v_24617;
v_24618:
    goto v_24614;
v_24615:
    goto v_24616;
v_24617:
    v_24639 = CC_splitup(elt(env, 0), v_24639, v_24640);
    env = stack[-2];
    v_24640 = v_24639;
    goto v_24630;
v_24624:
    v_24639 = stack[0];
    stack[-1] = qcar(v_24639);
    goto v_24625;
v_24626:
    v_24639 = v_24640;
    stack[0] = qcar(v_24639);
    goto v_24627;
v_24628:
    v_24639 = v_24640;
    v_24639 = qcdr(v_24639);
    v_24639 = qcar(v_24639);
    v_24639 = ncons(v_24639);
    goto v_24629;
v_24630:
    goto v_24624;
v_24625:
    goto v_24626;
v_24627:
    goto v_24628;
v_24629:
    {
        LispObject v_24644 = stack[-1];
        LispObject v_24645 = stack[0];
        return acons(v_24644, v_24645, v_24639);
    }
    v_24639 = nil;
    return onevalue(v_24639);
}



// Code for list2vect!*

static LispObject CC_list2vectH(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24639, v_24640;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_24565;
    stack[-4] = v_24564;
// end of prologue
    v_24639 = stack[-4];
    v_24639 = Llength(nil, v_24639);
    env = stack[-6];
    v_24639 = sub1(v_24639);
    env = stack[-6];
    v_24639 = Lmkvect(nil, v_24639);
    env = stack[-6];
    stack[-5] = v_24639;
    v_24639 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_24639;
v_24578:
    goto v_24590;
v_24586:
    v_24639 = stack[-5];
    v_24639 = Lupbv(nil, v_24639);
    env = stack[-6];
    v_24640 = add1(v_24639);
    env = stack[-6];
    goto v_24587;
v_24588:
    v_24639 = stack[-2];
    goto v_24589;
v_24590:
    goto v_24586;
v_24587:
    goto v_24588;
v_24589:
    v_24639 = difference2(v_24640, v_24639);
    env = stack[-6];
    v_24639 = Lminusp(nil, v_24639);
    env = stack[-6];
    if (v_24639 == nil) goto v_24583;
    goto v_24577;
v_24583:
    goto v_24602;
v_24596:
    stack[-1] = stack[-5];
    goto v_24597;
v_24598:
    v_24639 = stack[-2];
    stack[0] = sub1(v_24639);
    env = stack[-6];
    goto v_24599;
v_24600:
    goto v_24614;
v_24610:
    v_24640 = stack[-3];
    goto v_24611;
v_24612:
    v_24639 = elt(env, 2); // algebraic
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    if (v_24640 == v_24639) goto v_24608;
    else goto v_24609;
v_24608:
    goto v_24623;
v_24619:
    v_24640 = stack[-4];
    goto v_24620;
v_24621:
    v_24639 = stack[-2];
    goto v_24622;
v_24623:
    goto v_24619;
v_24620:
    goto v_24621;
v_24622:
    fn = elt(env, 3); // nth
    v_24639 = (*qfn2(fn))(fn, v_24640, v_24639);
    env = stack[-6];
    fn = elt(env, 4); // symb_to_alg
    v_24639 = (*qfn1(fn))(fn, v_24639);
    env = stack[-6];
    goto v_24607;
v_24609:
    goto v_24633;
v_24629:
    v_24640 = stack[-4];
    goto v_24630;
v_24631:
    v_24639 = stack[-2];
    goto v_24632;
v_24633:
    goto v_24629;
v_24630:
    goto v_24631;
v_24632:
    fn = elt(env, 3); // nth
    v_24639 = (*qfn2(fn))(fn, v_24640, v_24639);
    env = stack[-6];
    goto v_24607;
    v_24639 = nil;
v_24607:
    goto v_24601;
v_24602:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_24639;
    v_24639 = stack[-2];
    v_24639 = add1(v_24639);
    env = stack[-6];
    stack[-2] = v_24639;
    goto v_24578;
v_24577:
    v_24639 = stack[-5];
    return onevalue(v_24639);
}



// Code for basic!-kern

static LispObject CC_basicKkern(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24594, v_24595;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24595 = v_24564;
// end of prologue
    v_24594 = nil;
    stack[-1] = v_24594;
    v_24594 = v_24595;
    stack[0] = v_24594;
v_24571:
    v_24594 = stack[0];
    if (v_24594 == nil) goto v_24575;
    else goto v_24576;
v_24575:
    goto v_24570;
v_24576:
    v_24594 = stack[0];
    v_24594 = qcar(v_24594);
    goto v_24587;
v_24583:
    fn = elt(env, 1); // basic!-kern1
    v_24595 = (*qfn1(fn))(fn, v_24594);
    env = stack[-2];
    goto v_24584;
v_24585:
    v_24594 = stack[-1];
    goto v_24586;
v_24587:
    goto v_24583;
v_24584:
    goto v_24585;
v_24586:
    fn = elt(env, 2); // union
    v_24594 = (*qfn2(fn))(fn, v_24595, v_24594);
    env = stack[-2];
    stack[-1] = v_24594;
    v_24594 = stack[0];
    v_24594 = qcdr(v_24594);
    stack[0] = v_24594;
    goto v_24571;
v_24570:
    v_24594 = stack[-1];
    return onevalue(v_24594);
}



// Code for algmodep

static LispObject CC_algmodep(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24583, v_24584;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24584 = v_24564;
// end of prologue
    v_24583 = v_24584;
    if (!consp(v_24583)) goto v_24569;
    goto v_24575;
v_24571:
    v_24583 = v_24584;
    v_24583 = qcar(v_24583);
    goto v_24572;
v_24573:
    v_24584 = elt(env, 1); // (aeval aeval!*)
    goto v_24574;
v_24575:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    v_24583 = Lmemq(nil, v_24583, v_24584);
    goto v_24567;
v_24569:
    v_24583 = nil;
    goto v_24567;
    v_24583 = nil;
v_24567:
    return onevalue(v_24583);
}



// Code for xnp

static LispObject CC_xnp(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24596, v_24597, v_24598, v_24599;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24597 = v_24565;
    v_24598 = v_24564;
// end of prologue
v_24563:
    v_24596 = v_24598;
    if (v_24596 == nil) goto v_24569;
    else goto v_24570;
v_24569:
    v_24596 = nil;
    goto v_24568;
v_24570:
    goto v_24582;
v_24578:
    v_24596 = v_24598;
    v_24599 = qcar(v_24596);
    goto v_24579;
v_24580:
    v_24596 = v_24597;
    goto v_24581;
v_24582:
    goto v_24578;
v_24579:
    goto v_24580;
v_24581:
    v_24596 = Lmemq(nil, v_24599, v_24596);
    if (v_24596 == nil) goto v_24577;
    else goto v_24576;
v_24577:
    goto v_24592;
v_24588:
    v_24596 = v_24598;
    v_24598 = qcdr(v_24596);
    goto v_24589;
v_24590:
    v_24596 = v_24597;
    goto v_24591;
v_24592:
    goto v_24588;
v_24589:
    goto v_24590;
v_24591:
    v_24597 = v_24596;
    goto v_24563;
v_24576:
    goto v_24568;
    v_24596 = nil;
v_24568:
    return onevalue(v_24596);
}



// Code for lalr_set_nonterminal_codes

static LispObject CC_lalr_set_nonterminal_codes(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24655, v_24656, v_24657;
    argcheck(nargs, 0, "lalr_set_nonterminal_codes");
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
    v_24655 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_24655;
    v_24655 = qvalue(elt(env, 2)); // nonterminals
    stack[-1] = v_24655;
v_24573:
    v_24655 = stack[-1];
    if (v_24655 == nil) goto v_24577;
    else goto v_24578;
v_24577:
    goto v_24572;
v_24578:
    v_24655 = stack[-1];
    v_24655 = qcar(v_24655);
    stack[0] = v_24655;
    goto v_24592;
v_24588:
    v_24656 = stack[0];
    goto v_24589;
v_24590:
    v_24655 = elt(env, 3); // !S!'
    goto v_24591;
v_24592:
    goto v_24588;
v_24589:
    goto v_24590;
v_24591:
    if (v_24656 == v_24655) goto v_24586;
    else goto v_24587;
v_24586:
    goto v_24602;
v_24596:
    v_24657 = stack[0];
    goto v_24597;
v_24598:
    v_24656 = elt(env, 4); // lalr_nonterminal_code
    goto v_24599;
v_24600:
    v_24655 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_24601;
v_24602:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    v_24655 = Lputprop(nil, 3, v_24657, v_24656, v_24655);
    env = stack[-3];
    goto v_24585;
v_24587:
    goto v_24615;
v_24609:
    v_24657 = stack[0];
    goto v_24610;
v_24611:
    v_24656 = elt(env, 4); // lalr_nonterminal_code
    goto v_24612;
v_24613:
    v_24655 = stack[-2];
    goto v_24614;
v_24615:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    v_24655 = Lputprop(nil, 3, v_24657, v_24656, v_24655);
    env = stack[-3];
    v_24655 = qvalue(elt(env, 5)); // !*lalr_verbose
    if (v_24655 == nil) goto v_24622;
    goto v_24631;
v_24625:
    v_24657 = stack[-2];
    goto v_24626;
v_24627:
    v_24656 = stack[0];
    goto v_24628;
v_24629:
    v_24655 = qvalue(elt(env, 6)); // nonterminal_codes
    goto v_24630;
v_24631:
    goto v_24625;
v_24626:
    goto v_24627;
v_24628:
    goto v_24629;
v_24630:
    v_24655 = acons(v_24657, v_24656, v_24655);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_24655; // nonterminal_codes
    goto v_24620;
v_24622:
v_24620:
    v_24655 = stack[-2];
    v_24655 = add1(v_24655);
    env = stack[-3];
    stack[-2] = v_24655;
    goto v_24585;
v_24585:
    v_24655 = stack[-1];
    v_24655 = qcdr(v_24655);
    stack[-1] = v_24655;
    goto v_24573;
v_24572:
    v_24655 = qvalue(elt(env, 5)); // !*lalr_verbose
    if (v_24655 == nil) goto v_24642;
    goto v_24651;
v_24645:
    v_24657 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_24646;
v_24647:
    v_24656 = elt(env, 3); // !S!'
    goto v_24648;
v_24649:
    v_24655 = qvalue(elt(env, 6)); // nonterminal_codes
    goto v_24650;
v_24651:
    goto v_24645;
v_24646:
    goto v_24647;
v_24648:
    goto v_24649;
v_24650:
    v_24655 = acons(v_24657, v_24656, v_24655);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_24655; // nonterminal_codes
    goto v_24640;
v_24642:
v_24640:
    v_24655 = nil;
    return onevalue(v_24655);
}



// Code for co_hfn

static LispObject CC_co_hfn(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24578;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    goto v_24571;
v_24567:
    v_24578 = stack[0];
    v_24578 = qcdr(v_24578);
    fn = elt(env, 1); // cl_fvarl1
    stack[-1] = (*qfn1(fn))(fn, v_24578);
    env = stack[-2];
    goto v_24568;
v_24569:
    v_24578 = stack[0];
    v_24578 = qcdr(v_24578);
    fn = elt(env, 2); // rl_atnum
    v_24578 = (*qfn1(fn))(fn, v_24578);
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    {
        LispObject v_24581 = stack[-1];
        return list2(v_24581, v_24578);
    }
}



// Code for cl_subfof

static LispObject CC_cl_subfof(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24657, v_24658, v_24659, v_24660;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_24565;
    stack[-5] = v_24564;
// end of prologue
    stack[-6] = nil;
    stack[-2] = nil;
    v_24657 = stack[-5];
    fn = elt(env, 2); // rl_subalchk
    v_24657 = (*qfn1(fn))(fn, v_24657);
    env = stack[-7];
    v_24657 = stack[-5];
    stack[-1] = v_24657;
v_24578:
    v_24657 = stack[-1];
    if (v_24657 == nil) goto v_24582;
    else goto v_24583;
v_24582:
    goto v_24577;
v_24583:
    v_24657 = stack[-1];
    v_24657 = qcar(v_24657);
    stack[0] = v_24657;
    v_24657 = stack[0];
    fn = elt(env, 3); // rl_eqnrhskernels
    v_24657 = (*qfn1(fn))(fn, v_24657);
    env = stack[-7];
    stack[-3] = v_24657;
    goto v_24597;
v_24593:
    goto v_24604;
v_24600:
    v_24657 = stack[0];
    v_24658 = qcar(v_24657);
    goto v_24601;
v_24602:
    v_24657 = stack[-3];
    goto v_24603;
v_24604:
    goto v_24600;
v_24601:
    goto v_24602;
v_24603:
    v_24657 = cons(v_24658, v_24657);
    env = stack[-7];
    v_24658 = ncons(v_24657);
    env = stack[-7];
    goto v_24594;
v_24595:
    v_24657 = stack[-6];
    goto v_24596;
v_24597:
    goto v_24593;
v_24594:
    goto v_24595;
v_24596:
    v_24657 = list2(v_24658, v_24657);
    env = stack[-7];
    fn = elt(env, 4); // lto_alunion
    v_24657 = (*qfn1(fn))(fn, v_24657);
    env = stack[-7];
    stack[-6] = v_24657;
    goto v_24614;
v_24610:
    v_24657 = stack[0];
    stack[0] = qcar(v_24657);
    goto v_24611;
v_24612:
    goto v_24622;
v_24618:
    v_24658 = stack[-3];
    goto v_24619;
v_24620:
    v_24657 = stack[-2];
    goto v_24621;
v_24622:
    goto v_24618;
v_24619:
    goto v_24620;
v_24621:
    v_24657 = Lappend(nil, v_24658, v_24657);
    env = stack[-7];
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    v_24657 = cons(stack[0], v_24657);
    env = stack[-7];
    stack[-2] = v_24657;
    v_24657 = stack[-1];
    v_24657 = qcdr(v_24657);
    stack[-1] = v_24657;
    goto v_24578;
v_24577:
    v_24657 = stack[-4];
    fn = elt(env, 5); // cl_varl1
    v_24657 = (*qfn1(fn))(fn, v_24657);
    env = stack[-7];
    stack[-3] = v_24657;
    goto v_24637;
v_24631:
    v_24659 = stack[-2];
    goto v_24632;
v_24633:
    v_24657 = stack[-3];
    v_24658 = qcar(v_24657);
    goto v_24634;
v_24635:
    v_24657 = stack[-3];
    v_24657 = qcdr(v_24657);
    goto v_24636;
v_24637:
    goto v_24631;
v_24632:
    goto v_24633;
v_24634:
    goto v_24635;
v_24636:
    v_24657 = list3(v_24659, v_24658, v_24657);
    env = stack[-7];
    fn = elt(env, 6); // lto_nconcn
    v_24657 = (*qfn1(fn))(fn, v_24657);
    env = stack[-7];
    stack[-2] = v_24657;
    goto v_24652;
v_24644:
    v_24660 = stack[-5];
    goto v_24645;
v_24646:
    v_24659 = stack[-4];
    goto v_24647;
v_24648:
    v_24658 = stack[-6];
    goto v_24649;
v_24650:
    v_24657 = stack[-2];
    goto v_24651;
v_24652:
    goto v_24644;
v_24645:
    goto v_24646;
v_24647:
    goto v_24648;
v_24649:
    goto v_24650;
v_24651:
    {
        fn = elt(env, 7); // cl_subfof1
        return (*qfnn(fn))(fn, 4, v_24660, v_24659, v_24658, v_24657);
    }
    return onevalue(v_24657);
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24582, v_24583;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24582 = v_24565;
    v_24583 = v_24564;
// end of prologue
    goto v_24572;
v_24568:
    stack[0] = qvalue(elt(env, 1)); // rl_sacatlp!*
    goto v_24569;
v_24570:
    goto v_24579;
v_24575:
    goto v_24576;
v_24577:
    goto v_24578;
v_24579:
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    v_24582 = list2(v_24583, v_24582);
    env = stack[-1];
    goto v_24571;
v_24572:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    {
        LispObject v_24585 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_24585, v_24582);
    }
}



// Code for pasf_coeflst

static LispObject CC_pasf_coeflst(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24648, v_24649, v_24650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24565;
    stack[-2] = v_24564;
// end of prologue
    stack[0] = nil;
    v_24648 = stack[-1];
    v_24648 = ncons(v_24648);
    env = stack[-4];
    fn = elt(env, 2); // setkorder
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    stack[-3] = v_24648;
    v_24648 = stack[-2];
    fn = elt(env, 3); // reorder
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    stack[-2] = v_24648;
v_24580:
    v_24648 = stack[-2];
    if (!consp(v_24648)) goto v_24591;
    else goto v_24592;
v_24591:
    v_24648 = lisp_true;
    goto v_24590;
v_24592:
    v_24648 = stack[-2];
    v_24648 = qcar(v_24648);
    v_24648 = (consp(v_24648) ? nil : lisp_true);
    goto v_24590;
    v_24648 = nil;
v_24590:
    if (v_24648 == nil) goto v_24587;
    else goto v_24588;
v_24587:
    goto v_24604;
v_24600:
    v_24648 = stack[-2];
    v_24648 = qcar(v_24648);
    v_24648 = qcar(v_24648);
    v_24649 = qcar(v_24648);
    goto v_24601;
v_24602:
    v_24648 = stack[-1];
    goto v_24603;
v_24604:
    goto v_24600;
v_24601:
    goto v_24602;
v_24603:
    v_24648 = (v_24649 == v_24648 ? lisp_true : nil);
    goto v_24586;
v_24588:
    v_24648 = nil;
    goto v_24586;
    v_24648 = nil;
v_24586:
    if (v_24648 == nil) goto v_24583;
    else goto v_24584;
v_24583:
    goto v_24579;
v_24584:
    goto v_24622;
v_24616:
    v_24648 = stack[-2];
    v_24648 = qcar(v_24648);
    v_24650 = qcdr(v_24648);
    goto v_24617;
v_24618:
    v_24648 = stack[-2];
    v_24648 = qcar(v_24648);
    v_24648 = qcar(v_24648);
    v_24649 = qcdr(v_24648);
    goto v_24619;
v_24620:
    v_24648 = stack[0];
    goto v_24621;
v_24622:
    goto v_24616;
v_24617:
    goto v_24618;
v_24619:
    goto v_24620;
v_24621:
    v_24648 = acons(v_24650, v_24649, v_24648);
    env = stack[-4];
    stack[0] = v_24648;
    v_24648 = stack[-2];
    v_24648 = qcdr(v_24648);
    stack[-2] = v_24648;
    goto v_24580;
v_24579:
    v_24648 = stack[-3];
    fn = elt(env, 2); // setkorder
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    goto v_24643;
v_24637:
    v_24648 = stack[-2];
    fn = elt(env, 4); // negf
    v_24650 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    goto v_24638;
v_24639:
    v_24649 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24640;
v_24641:
    v_24648 = stack[0];
    goto v_24642;
v_24643:
    goto v_24637;
v_24638:
    goto v_24639;
v_24640:
    goto v_24641;
v_24642:
    v_24648 = acons(v_24650, v_24649, v_24648);
        return Lnreverse(nil, v_24648);
    return onevalue(v_24648);
}



// Code for diffrd

static LispObject CC_diffrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24598, v_24599;
    LispObject fn;
    argcheck(nargs, 0, "diffrd");
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
    fn = elt(env, 4); // lex
    v_24598 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_24579;
v_24575:
    v_24599 = qvalue(elt(env, 2)); // char
    goto v_24576;
v_24577:
    v_24598 = elt(env, 3); // (b v a r)
    goto v_24578;
v_24579:
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    if (equal(v_24599, v_24598)) goto v_24573;
    else goto v_24574;
v_24573:
    fn = elt(env, 5); // bvarrd
    v_24598 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_24598;
    fn = elt(env, 4); // lex
    v_24598 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_24572;
v_24574:
    v_24598 = nil;
    stack[-1] = v_24598;
    goto v_24572;
v_24572:
    fn = elt(env, 6); // mathml2
    v_24598 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_24598;
    fn = elt(env, 4); // lex
    v_24598 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_24595;
v_24591:
    v_24599 = stack[-1];
    goto v_24592;
v_24593:
    v_24598 = stack[0];
    goto v_24594;
v_24595:
    goto v_24591;
v_24592:
    goto v_24593;
v_24594:
    v_24598 = list2(v_24599, v_24598);
    env = stack[-2];
    {
        fn = elt(env, 7); // diff2
        return (*qfn1(fn))(fn, v_24598);
    }
    return onevalue(v_24598);
}



// Code for insertocc

static LispObject CC_insertocc(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24617, v_24618, v_24619;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24564,v_24565);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_24619 = v_24565;
    stack[-1] = v_24564;
// end of prologue
    goto v_24579;
v_24575:
    v_24618 = v_24619;
    goto v_24576;
v_24577:
    v_24617 = stack[-1];
    goto v_24578;
v_24579:
    goto v_24575;
v_24576:
    goto v_24577;
v_24578:
    v_24617 = Lassoc(nil, v_24618, v_24617);
    stack[-2] = v_24617;
    if (v_24617 == nil) goto v_24574;
    goto v_24590;
v_24584:
    goto v_24596;
v_24592:
    stack[0] = v_24619;
    goto v_24593;
v_24594:
    v_24617 = stack[-2];
    v_24617 = qcdr(v_24617);
    v_24617 = add1(v_24617);
    env = stack[-3];
    goto v_24595;
v_24596:
    goto v_24592;
v_24593:
    goto v_24594;
v_24595:
    v_24619 = cons(stack[0], v_24617);
    env = stack[-3];
    goto v_24585;
v_24586:
    v_24618 = stack[-2];
    goto v_24587;
v_24588:
    v_24617 = stack[-1];
    goto v_24589;
v_24590:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    goto v_24588;
v_24589:
    v_24617 = Lsubst(nil, 3, v_24619, v_24618, v_24617);
    stack[-1] = v_24617;
    goto v_24572;
v_24574:
    goto v_24612;
v_24606:
    goto v_24607;
v_24608:
    v_24618 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24609;
v_24610:
    v_24617 = stack[-1];
    goto v_24611;
v_24612:
    goto v_24606;
v_24607:
    goto v_24608;
v_24609:
    goto v_24610;
v_24611:
    v_24617 = acons(v_24619, v_24618, v_24617);
    stack[-1] = v_24617;
    goto v_24572;
v_24572:
    v_24617 = stack[-1];
    return onevalue(v_24617);
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24648, v_24649;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_24564;
// end of prologue
    v_24648 = stack[-2];
    stack[0] = v_24648;
    v_24648 = stack[-2];
    v_24648 = qcdr(v_24648);
    stack[-2] = v_24648;
    v_24648 = elt(env, 2); // !*lcbkt!*
    if (!symbolp(v_24648)) v_24648 = nil;
    else { v_24648 = qfastgets(v_24648);
           if (v_24648 != nil) { v_24648 = elt(v_24648, 37); // prtch
#ifdef RECORD_GET
             if (v_24648 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_24648 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_24648 == SPID_NOPROP) v_24648 = nil; }}
#endif
    fn = elt(env, 8); // prin2!*
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    v_24648 = qvalue(elt(env, 3)); // orig!*
    stack[-3] = v_24648;
    goto v_24590;
v_24586:
    v_24649 = qvalue(elt(env, 4)); // posn!*
    goto v_24587;
v_24588:
    v_24648 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_24589;
v_24590:
    goto v_24586;
v_24587:
    goto v_24588;
v_24589:
    v_24648 = (LispObject)lessp2(v_24649, v_24648);
    v_24648 = v_24648 ? lisp_true : nil;
    env = stack[-4];
    if (v_24648 == nil) goto v_24584;
    v_24648 = qvalue(elt(env, 4)); // posn!*
    goto v_24582;
v_24584:
    goto v_24601;
v_24597:
    v_24649 = qvalue(elt(env, 3)); // orig!*
    goto v_24598;
v_24599:
    v_24648 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24600;
v_24601:
    goto v_24597;
v_24598:
    goto v_24599;
v_24600:
    v_24648 = plus2(v_24649, v_24648);
    env = stack[-4];
    goto v_24582;
    v_24648 = nil;
v_24582:
    qvalue(elt(env, 3)) = v_24648; // orig!*
    v_24648 = stack[-2];
    if (v_24648 == nil) goto v_24606;
    else goto v_24607;
v_24606:
    goto v_24572;
v_24607:
    goto v_24614;
v_24610:
    v_24649 = stack[-2];
    goto v_24611;
v_24612:
    v_24648 = qvalue(elt(env, 5)); // listpri_depth!*
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    fn = elt(env, 9); // treesizep
    v_24648 = (*qfn2(fn))(fn, v_24649, v_24648);
    env = stack[-4];
    stack[-1] = v_24648;
v_24571:
    goto v_24622;
v_24618:
    v_24648 = stack[-2];
    v_24648 = qcar(v_24648);
    fn = elt(env, 10); // negnumberchk
    v_24649 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    goto v_24619;
v_24620:
    v_24648 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24621;
v_24622:
    goto v_24618;
v_24619:
    goto v_24620;
v_24621:
    fn = elt(env, 11); // maprint
    v_24648 = (*qfn2(fn))(fn, v_24649, v_24648);
    env = stack[-4];
    v_24648 = stack[-2];
    v_24648 = qcdr(v_24648);
    stack[-2] = v_24648;
    v_24648 = stack[-2];
    if (v_24648 == nil) goto v_24631;
    else goto v_24632;
v_24631:
    goto v_24572;
v_24632:
    v_24648 = elt(env, 6); // !*comma!*
    fn = elt(env, 12); // oprin
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    v_24648 = stack[-1];
    if (v_24648 == nil) goto v_24639;
    v_24648 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    goto v_24637;
v_24639:
v_24637:
    goto v_24571;
v_24572:
    v_24648 = elt(env, 7); // !*rcbkt!*
    if (!symbolp(v_24648)) v_24648 = nil;
    else { v_24648 = qfastgets(v_24648);
           if (v_24648 != nil) { v_24648 = elt(v_24648, 37); // prtch
#ifdef RECORD_GET
             if (v_24648 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_24648 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_24648 == SPID_NOPROP) v_24648 = nil; }}
#endif
    fn = elt(env, 8); // prin2!*
    v_24648 = (*qfn1(fn))(fn, v_24648);
    env = stack[-4];
    v_24648 = stack[-3];
    qvalue(elt(env, 3)) = v_24648; // orig!*
    v_24648 = stack[0];
    return onevalue(v_24648);
}



// Code for physoppri

static LispObject CC_physoppri(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24877, v_24878, v_24879, v_24880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_24564;
// end of prologue
    stack[-6] = nil;
    v_24877 = stack[-8];
    if (symbolp(v_24877)) goto v_24576;
    else goto v_24577;
v_24576:
    v_24877 = stack[-8];
    goto v_24575;
v_24577:
    v_24877 = stack[-8];
    v_24877 = qcar(v_24877);
    goto v_24575;
    v_24877 = nil;
v_24575:
    stack[-9] = v_24877;
    v_24877 = stack[-8];
    if (symbolp(v_24877)) goto v_24586;
    else goto v_24587;
v_24586:
    v_24877 = nil;
    goto v_24585;
v_24587:
    v_24877 = stack[-8];
    v_24877 = qcdr(v_24877);
    goto v_24585;
    v_24877 = nil;
v_24585:
    stack[-7] = v_24877;
    goto v_24604;
v_24596:
    stack[-5] = elt(env, 0); // physoppri
    goto v_24597;
v_24598:
    stack[-4] = elt(env, 2); // "x= "
    goto v_24599;
v_24600:
    stack[-3] = stack[-9];
    goto v_24601;
v_24602:
    goto v_24617;
v_24609:
    stack[-2] = elt(env, 3); // " y= "
    goto v_24610;
v_24611:
    stack[-1] = stack[-7];
    goto v_24612;
v_24613:
    stack[0] = elt(env, 4); // "nat= "
    goto v_24614;
v_24615:
    goto v_24628;
v_24622:
    v_24879 = elt(env, 5); // !*nat
    goto v_24623;
v_24624:
    v_24878 = elt(env, 6); // " contract= "
    goto v_24625;
v_24626:
    v_24877 = elt(env, 7); // !*contract
    goto v_24627;
v_24628:
    goto v_24622;
v_24623:
    goto v_24624;
v_24625:
    goto v_24626;
v_24627:
    v_24877 = list3(v_24879, v_24878, v_24877);
    env = stack[-10];
    goto v_24616;
v_24617:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    goto v_24615;
v_24616:
    v_24877 = list3star(stack[-2], stack[-1], stack[0], v_24877);
    env = stack[-10];
    goto v_24603;
v_24604:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    goto v_24602;
v_24603:
    v_24877 = list3star(stack[-5], stack[-4], stack[-3], v_24877);
    env = stack[-10];
    fn = elt(env, 19); // trwrite
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = qvalue(elt(env, 5)); // !*nat
    if (v_24877 == nil) goto v_24635;
    v_24877 = qvalue(elt(env, 7)); // !*contract
    if (v_24877 == nil) goto v_24638;
    else goto v_24635;
v_24638:
    goto v_24572;
v_24635:
    goto v_24646;
v_24642:
    goto v_24652;
v_24648:
    stack[0] = elt(env, 8); // !"
    goto v_24649;
v_24650:
    v_24877 = stack[-9];
    v_24877 = Lexplode(nil, v_24877);
    env = stack[-10];
    goto v_24651;
v_24652:
    goto v_24648;
v_24649:
    goto v_24650;
v_24651:
    stack[0] = cons(stack[0], v_24877);
    env = stack[-10];
    goto v_24643;
v_24644:
    v_24877 = elt(env, 8); // !"
    v_24877 = ncons(v_24877);
    env = stack[-10];
    goto v_24645;
v_24646:
    goto v_24642;
v_24643:
    goto v_24644;
v_24645:
    v_24877 = Lappend(nil, stack[0], v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    v_24877 = stack[-9];
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = stack[-7];
    if (v_24877 == nil) goto v_24663;
    v_24877 = elt(env, 9); // "("
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = nil;
    qvalue(elt(env, 10)) = v_24877; // obrkp!*
    goto v_24675;
v_24669:
    v_24879 = elt(env, 11); // !*comma!*
    goto v_24670;
v_24671:
    v_24878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24672;
v_24673:
    v_24877 = stack[-7];
    goto v_24674;
v_24675:
    goto v_24669;
v_24670:
    goto v_24671;
v_24672:
    goto v_24673;
v_24674:
    fn = elt(env, 21); // inprint
    v_24877 = (*qfnn(fn))(fn, 3, v_24879, v_24878, v_24877);
    env = stack[-10];
    v_24877 = lisp_true;
    qvalue(elt(env, 10)) = v_24877; // obrkp!*
    v_24877 = elt(env, 12); // ")"
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    goto v_24661;
v_24663:
v_24661:
    v_24877 = stack[-8];
    goto v_24571;
v_24572:
    v_24877 = stack[-9];
    v_24877 = Lexplode(nil, v_24877);
    env = stack[-10];
    v_24877 = Lreverse(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    goto v_24695;
v_24691:
    v_24877 = stack[-9];
    v_24878 = Llength(nil, v_24877);
    env = stack[-10];
    goto v_24692;
v_24693:
    v_24877 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24694;
v_24695:
    goto v_24691;
v_24692:
    goto v_24693;
v_24694:
    v_24877 = (LispObject)greaterp2(v_24878, v_24877);
    v_24877 = v_24877 ? lisp_true : nil;
    env = stack[-10];
    if (v_24877 == nil) goto v_24689;
    goto v_24707;
v_24703:
    v_24877 = stack[-9];
    v_24877 = qcdr(v_24877);
    v_24878 = qcar(v_24877);
    goto v_24704;
v_24705:
    v_24877 = elt(env, 13); // !-
    goto v_24706;
v_24707:
    goto v_24703;
v_24704:
    goto v_24705;
v_24706:
    if (v_24878 == v_24877) goto v_24701;
    else goto v_24702;
v_24701:
    goto v_24718;
v_24714:
    v_24878 = elt(env, 13); // !-
    goto v_24715;
v_24716:
    v_24877 = elt(env, 14); // !1
    goto v_24717;
v_24718:
    goto v_24714;
v_24715:
    goto v_24716;
v_24717:
    v_24877 = list2(v_24878, v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-6] = v_24877;
    goto v_24728;
v_24724:
    v_24878 = stack[-9];
    goto v_24725;
v_24726:
    v_24877 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24727;
v_24728:
    goto v_24724;
v_24725:
    goto v_24726;
v_24727:
    fn = elt(env, 22); // pnth
    v_24877 = (*qfn2(fn))(fn, v_24878, v_24877);
    env = stack[-10];
    v_24877 = Lreverse(nil, v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    goto v_24700;
v_24702:
    goto v_24738;
v_24734:
    v_24877 = stack[-9];
    v_24878 = qcar(v_24877);
    goto v_24735;
v_24736:
    v_24877 = elt(env, 15); // !+
    goto v_24737;
v_24738:
    goto v_24734;
v_24735:
    goto v_24736;
v_24737:
    if (v_24878 == v_24877) goto v_24732;
    else goto v_24733;
v_24732:
    v_24877 = elt(env, 15); // !+
    stack[-6] = v_24877;
    goto v_24750;
v_24746:
    v_24878 = stack[-9];
    goto v_24747;
v_24748:
    v_24877 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24749;
v_24750:
    goto v_24746;
v_24747:
    goto v_24748;
v_24749:
    fn = elt(env, 22); // pnth
    v_24877 = (*qfn2(fn))(fn, v_24878, v_24877);
    env = stack[-10];
    v_24877 = Lreverse(nil, v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    goto v_24700;
v_24733:
    v_24877 = stack[-9];
    v_24877 = Lreverse(nil, v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    goto v_24700;
v_24700:
    goto v_24687;
v_24689:
    v_24877 = stack[-9];
    v_24877 = Lreverse(nil, v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    goto v_24687;
v_24687:
    goto v_24770;
v_24766:
    goto v_24776;
v_24772:
    stack[0] = elt(env, 8); // !"
    goto v_24773;
v_24774:
    v_24877 = stack[-9];
    v_24877 = Lexplode(nil, v_24877);
    env = stack[-10];
    goto v_24775;
v_24776:
    goto v_24772;
v_24773:
    goto v_24774;
v_24775:
    stack[0] = cons(stack[0], v_24877);
    env = stack[-10];
    goto v_24767;
v_24768:
    v_24877 = elt(env, 8); // !"
    v_24877 = ncons(v_24877);
    env = stack[-10];
    goto v_24769;
v_24770:
    goto v_24766;
v_24767:
    goto v_24768;
v_24769:
    v_24877 = Lappend(nil, stack[0], v_24877);
    env = stack[-10];
    v_24877 = Lcompress(nil, v_24877);
    env = stack[-10];
    stack[-9] = v_24877;
    v_24877 = stack[-7];
    if (v_24877 == nil) goto v_24785;
    goto v_24792;
v_24788:
    v_24878 = stack[-9];
    goto v_24789;
v_24790:
    v_24877 = stack[-7];
    goto v_24791;
v_24792:
    goto v_24788;
v_24789:
    goto v_24790;
v_24791:
    v_24877 = cons(v_24878, v_24877);
    env = stack[-10];
    goto v_24783;
v_24785:
    v_24877 = stack[-9];
    goto v_24783;
    v_24877 = nil;
v_24783:
    stack[-3] = v_24877;
    goto v_24808;
v_24800:
    stack[-2] = elt(env, 0); // physoppri
    goto v_24801;
v_24802:
    stack[-1] = elt(env, 2); // "x= "
    goto v_24803;
v_24804:
    stack[0] = stack[-9];
    goto v_24805;
v_24806:
    goto v_24821;
v_24813:
    v_24880 = elt(env, 16); // " z= "
    goto v_24814;
v_24815:
    v_24879 = stack[-6];
    goto v_24816;
v_24817:
    v_24878 = elt(env, 17); // " x1= "
    goto v_24818;
v_24819:
    v_24877 = stack[-3];
    goto v_24820;
v_24821:
    goto v_24813;
v_24814:
    goto v_24815;
v_24816:
    goto v_24817;
v_24818:
    goto v_24819;
v_24820:
    v_24877 = list4(v_24880, v_24879, v_24878, v_24877);
    env = stack[-10];
    goto v_24807;
v_24808:
    goto v_24800;
v_24801:
    goto v_24802;
v_24803:
    goto v_24804;
v_24805:
    goto v_24806;
v_24807:
    v_24877 = list3star(stack[-2], stack[-1], stack[0], v_24877);
    env = stack[-10];
    fn = elt(env, 19); // trwrite
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = stack[-6];
    if (v_24877 == nil) goto v_24829;
    goto v_24836;
v_24832:
    goto v_24844;
v_24838:
    v_24879 = elt(env, 18); // expt
    goto v_24839;
v_24840:
    v_24878 = stack[-3];
    goto v_24841;
v_24842:
    v_24877 = stack[-6];
    goto v_24843;
v_24844:
    goto v_24838;
v_24839:
    goto v_24840;
v_24841:
    goto v_24842;
v_24843:
    v_24878 = list3(v_24879, v_24878, v_24877);
    env = stack[-10];
    goto v_24833;
v_24834:
    v_24877 = elt(env, 18); // expt
    if (!symbolp(v_24877)) v_24877 = nil;
    else { v_24877 = qfastgets(v_24877);
           if (v_24877 != nil) { v_24877 = elt(v_24877, 23); // infix
#ifdef RECORD_GET
             if (v_24877 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_24877 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_24877 == SPID_NOPROP) v_24877 = nil; }}
#endif
    goto v_24835;
v_24836:
    goto v_24832;
v_24833:
    goto v_24834;
v_24835:
    fn = elt(env, 23); // exptpri
    v_24877 = (*qfn2(fn))(fn, v_24878, v_24877);
    goto v_24827;
v_24829:
    v_24877 = stack[-9];
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = stack[-7];
    if (v_24877 == nil) goto v_24857;
    v_24877 = elt(env, 9); // "("
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    env = stack[-10];
    v_24877 = nil;
    qvalue(elt(env, 10)) = v_24877; // obrkp!*
    goto v_24869;
v_24863:
    v_24879 = elt(env, 11); // !*comma!*
    goto v_24864;
v_24865:
    v_24878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24866;
v_24867:
    v_24877 = stack[-7];
    goto v_24868;
v_24869:
    goto v_24863;
v_24864:
    goto v_24865;
v_24866:
    goto v_24867;
v_24868:
    fn = elt(env, 21); // inprint
    v_24877 = (*qfnn(fn))(fn, 3, v_24879, v_24878, v_24877);
    env = stack[-10];
    v_24877 = lisp_true;
    qvalue(elt(env, 10)) = v_24877; // obrkp!*
    v_24877 = elt(env, 12); // ")"
    fn = elt(env, 20); // prin2!*
    v_24877 = (*qfn1(fn))(fn, v_24877);
    goto v_24855;
v_24857:
v_24855:
    goto v_24827;
v_24827:
    v_24877 = stack[-8];
v_24571:
    return onevalue(v_24877);
}



// Code for find_bubles_coeff

static LispObject CC_find_bubles_coeff(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24582, v_24583, v_24584, v_24585;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_bubles_coeff");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24582 = v_24566;
    v_24583 = v_24565;
    v_24584 = v_24564;
// end of prologue
    goto v_24577;
v_24569:
    v_24585 = v_24584;
    goto v_24570;
v_24571:
    v_24584 = nil;
    goto v_24572;
v_24573:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    goto v_24569;
v_24570:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    {
        fn = elt(env, 1); // find_bubles1_coeff
        return (*qfnn(fn))(fn, 4, v_24585, v_24584, v_24583, v_24582);
    }
}



// Code for formsetq0

static LispObject CC_formsetq0(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25097, v_25098, v_25099, v_25100;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq0");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_24566;
    stack[-4] = v_24565;
    stack[0] = v_24564;
// end of prologue
    stack[-1] = nil;
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    stack[0] = v_25097;
    v_25097 = qcar(v_25097);
    stack[-2] = v_25097;
    if (symbolp(v_25097)) goto v_24576;
    else goto v_24577;
v_24576:
    goto v_24585;
v_24581:
    v_25098 = stack[-2];
    goto v_24582;
v_24583:
    v_25097 = stack[-4];
    goto v_24584;
v_24585:
    goto v_24581;
v_24582:
    goto v_24583;
v_24584:
    v_25097 = Latsoc(nil, v_25098, v_25097);
    stack[-1] = v_25097;
    goto v_24575;
v_24577:
v_24575:
    goto v_24598;
v_24594:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    v_25098 = qcar(v_25097);
    goto v_24595;
v_24596:
    v_25097 = elt(env, 2); // quote
    goto v_24597;
v_24598:
    goto v_24594;
v_24595:
    goto v_24596;
v_24597:
    if (!consp(v_25098)) goto v_24592;
    v_25098 = qcar(v_25098);
    if (v_25098 == v_25097) goto v_24591;
    else goto v_24592;
v_24591:
    v_25097 = elt(env, 3); // symbolic
    stack[-3] = v_25097;
    goto v_24590;
v_24592:
v_24590:
    goto v_24613;
v_24605:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    v_25100 = qcar(v_25097);
    goto v_24606;
v_24607:
    v_25099 = stack[-4];
    goto v_24608;
v_24609:
    v_25098 = elt(env, 3); // symbolic
    goto v_24610;
v_24611:
    v_25097 = stack[-3];
    goto v_24612;
v_24613:
    goto v_24605;
v_24606:
    goto v_24607;
v_24608:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    fn = elt(env, 23); // convertmode
    v_25097 = (*qfnn(fn))(fn, 4, v_25100, v_25099, v_25098, v_25097);
    env = stack[-6];
    stack[-5] = v_25097;
    v_25097 = stack[-2];
    if (!consp(v_25097)) goto v_24627;
    v_25097 = qvalue(elt(env, 4)); // !*savedef
    if (v_25097 == nil) goto v_24632;
    goto v_24642;
v_24638:
    v_25097 = stack[-2];
    v_25098 = qcar(v_25097);
    goto v_24639;
v_24640:
    v_25097 = elt(env, 5); // inline
    goto v_24641;
v_24642:
    goto v_24638;
v_24639:
    goto v_24640;
v_24641:
    v_25097 = get(v_25098, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_24636;
    else goto v_24635;
v_24636:
    goto v_24652;
v_24648:
    v_25097 = stack[-2];
    v_25098 = qcar(v_25097);
    goto v_24649;
v_24650:
    v_25097 = elt(env, 6); // smacro
    goto v_24651;
v_24652:
    goto v_24648;
v_24649:
    goto v_24650;
v_24651:
    v_25097 = get(v_25098, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_24646;
    else goto v_24635;
v_24646:
    goto v_24632;
v_24635:
    v_25097 = Lposn(nil, 0);
    env = stack[-6];
    v_25097 = (LispObject)zerop(v_25097);
    v_25097 = v_25097 ? lisp_true : nil;
    env = stack[-6];
    if (v_25097 == nil) goto v_24658;
    else goto v_24659;
v_24658:
    v_25097 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_24657;
v_24659:
v_24657:
    v_25097 = elt(env, 7); // "+++ Assign via inline or smacro: "
    v_25097 = Lprinc(nil, v_25097);
    env = stack[-6];
    v_25097 = stack[-2];
    v_25097 = Lprint(nil, v_25097);
    env = stack[-6];
    goto v_24630;
v_24632:
v_24630:
    v_25097 = lisp_true;
    goto v_24625;
v_24627:
    v_25097 = nil;
    goto v_24625;
    v_25097 = nil;
v_24625:
    if (v_25097 == nil) goto v_24623;
    v_25097 = stack[-2];
    v_25097 = qcar(v_25097);
    if (symbolp(v_25097)) goto v_24674;
    goto v_24682;
v_24678:
    v_25098 = stack[-2];
    goto v_24679;
v_24680:
    v_25097 = elt(env, 8); // "assignment"
    goto v_24681;
v_24682:
    goto v_24678;
v_24679:
    goto v_24680;
v_24681:
    {
        fn = elt(env, 24); // typerr
        return (*qfn2(fn))(fn, v_25098, v_25097);
    }
v_24674:
    goto v_24696;
v_24692:
    v_25098 = stack[-2];
    goto v_24693;
v_24694:
    v_25097 = stack[-3];
    goto v_24695;
v_24696:
    goto v_24692;
v_24693:
    goto v_24694;
v_24695:
    fn = elt(env, 25); // macrochk
    v_25097 = (*qfn2(fn))(fn, v_25098, v_25097);
    env = stack[-6];
    stack[-2] = v_25097;
    if (!consp(v_25097)) goto v_24690;
    v_25097 = stack[-2];
    v_25097 = qcar(v_25097);
    fn = elt(env, 26); // arrayp
    v_25097 = (*qfn1(fn))(fn, v_25097);
    env = stack[-6];
    goto v_24688;
v_24690:
    v_25097 = nil;
    goto v_24688;
    v_25097 = nil;
v_24688:
    if (v_25097 == nil) goto v_24686;
    goto v_24712;
v_24706:
    stack[0] = elt(env, 9); // setel
    goto v_24707;
v_24708:
    goto v_24721;
v_24715:
    v_25099 = stack[-2];
    goto v_24716;
v_24717:
    v_25098 = stack[-4];
    goto v_24718;
v_24719:
    v_25097 = stack[-3];
    goto v_24720;
v_24721:
    goto v_24715;
v_24716:
    goto v_24717;
v_24718:
    goto v_24719;
v_24720:
    fn = elt(env, 27); // intargfn
    v_25098 = (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    goto v_24709;
v_24710:
    v_25097 = stack[-5];
    goto v_24711;
v_24712:
    goto v_24706;
v_24707:
    goto v_24708;
v_24709:
    goto v_24710;
v_24711:
    {
        LispObject v_25107 = stack[0];
        return list3(v_25107, v_25098, v_25097);
    }
v_24686:
    v_25097 = stack[-2];
    if (!consp(v_25097)) goto v_24731;
    v_25097 = stack[-2];
    v_25097 = qcdr(v_25097);
    if (v_25097 == nil) goto v_24735;
    else goto v_24736;
v_24735:
    v_25097 = nil;
    goto v_24734;
v_24736:
    goto v_24750;
v_24746:
    v_25097 = stack[-2];
    v_25097 = qcar(v_25097);
    if (!symbolp(v_25097)) v_25098 = nil;
    else { v_25098 = qfastgets(v_25097);
           if (v_25098 != nil) { v_25098 = elt(v_25098, 2); // rtype
#ifdef RECORD_GET
             if (v_25098 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_25098 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_25098 == SPID_NOPROP) v_25098 = nil; }}
#endif
    goto v_24747;
v_24748:
    v_25097 = elt(env, 10); // vector
    goto v_24749;
v_24750:
    goto v_24746;
v_24747:
    goto v_24748;
v_24749:
    if (v_25098 == v_25097) goto v_24744;
    else goto v_24745;
v_24744:
    v_25097 = lisp_true;
    goto v_24743;
v_24745:
    v_25097 = stack[-2];
    v_25097 = qcdr(v_25097);
    v_25097 = qcar(v_25097);
    v_25097 = Lsimple_vectorp(nil, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_24760;
    else goto v_24759;
v_24760:
    goto v_24770;
v_24766:
    v_25097 = stack[-2];
    v_25097 = qcdr(v_25097);
    v_25098 = qcar(v_25097);
    goto v_24767;
v_24768:
    v_25097 = elt(env, 11); // vecfn
    goto v_24769;
v_24770:
    goto v_24766;
v_24767:
    goto v_24768;
v_24769:
    v_25097 = Lflagpcar(nil, v_25098, v_25097);
    env = stack[-6];
v_24759:
    goto v_24743;
    v_25097 = nil;
v_24743:
    goto v_24734;
    v_25097 = nil;
v_24734:
    goto v_24729;
v_24731:
    v_25097 = nil;
    goto v_24729;
    v_25097 = nil;
v_24729:
    if (v_25097 == nil) goto v_24727;
    goto v_24785;
v_24779:
    v_25099 = stack[0];
    goto v_24780;
v_24781:
    v_25098 = stack[-4];
    goto v_24782;
v_24783:
    v_25097 = stack[-3];
    goto v_24784;
v_24785:
    goto v_24779;
v_24780:
    goto v_24781;
v_24782:
    goto v_24783;
v_24784:
    {
        fn = elt(env, 28); // putvect
        return (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    }
v_24727:
    goto v_24796;
v_24792:
    v_25098 = stack[-2];
    goto v_24793;
v_24794:
    v_25097 = elt(env, 12); // part
    goto v_24795;
v_24796:
    goto v_24792;
v_24793:
    goto v_24794;
v_24795:
    if (!consp(v_25098)) goto v_24790;
    v_25098 = qcar(v_25098);
    if (v_25098 == v_25097) goto v_24789;
    else goto v_24790;
v_24789:
    goto v_24804;
v_24800:
    goto v_24812;
v_24806:
    stack[-1] = elt(env, 13); // list
    goto v_24807;
v_24808:
    v_25097 = elt(env, 14); // setpart!*
    stack[0] = Lmkquote(nil, v_25097);
    env = stack[-6];
    goto v_24809;
v_24810:
    goto v_24823;
v_24817:
    v_25097 = stack[-2];
    v_25099 = qcdr(v_25097);
    goto v_24818;
v_24819:
    v_25098 = stack[-4];
    goto v_24820;
v_24821:
    v_25097 = stack[-3];
    goto v_24822;
v_24823:
    goto v_24817;
v_24818:
    goto v_24819;
v_24820:
    goto v_24821;
v_24822:
    fn = elt(env, 29); // formlis
    v_25097 = (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    env = stack[-6];
    goto v_24811;
v_24812:
    goto v_24806;
v_24807:
    goto v_24808;
v_24809:
    goto v_24810;
v_24811:
    v_25098 = list2star(stack[-1], stack[0], v_25097);
    env = stack[-6];
    goto v_24801;
v_24802:
    v_25097 = stack[-5];
    goto v_24803;
v_24804:
    goto v_24800;
v_24801:
    goto v_24802;
v_24803:
    {
        fn = elt(env, 30); // aconc
        return (*qfn2(fn))(fn, v_25098, v_25097);
    }
v_24790:
    v_25097 = stack[-2];
    if (!consp(v_25097)) goto v_24834;
    goto v_24841;
v_24837:
    v_25097 = stack[-2];
    v_25098 = qcar(v_25097);
    goto v_24838;
v_24839:
    v_25097 = elt(env, 15); // setqfn
    goto v_24840;
v_24841:
    goto v_24837;
v_24838:
    goto v_24839;
v_24840:
    v_25097 = get(v_25098, v_25097);
    env = stack[-6];
    stack[-1] = v_25097;
    goto v_24832;
v_24834:
    v_25097 = nil;
    goto v_24832;
    v_25097 = nil;
v_24832:
    if (v_25097 == nil) goto v_24830;
    goto v_24855;
v_24849:
    goto v_24863;
v_24857:
    goto v_24858;
v_24859:
    goto v_24870;
v_24866:
    v_25097 = stack[-2];
    v_25098 = qcdr(v_25097);
    goto v_24867;
v_24868:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    goto v_24869;
v_24870:
    goto v_24866;
v_24867:
    goto v_24868;
v_24869:
    v_25098 = Lappend(nil, v_25098, v_25097);
    env = stack[-6];
    goto v_24860;
v_24861:
    v_25097 = nil;
    goto v_24862;
v_24863:
    goto v_24857;
v_24858:
    goto v_24859;
v_24860:
    goto v_24861;
v_24862:
    fn = elt(env, 31); // applsmacro
    v_25099 = (*qfnn(fn))(fn, 3, stack[-1], v_25098, v_25097);
    env = stack[-6];
    goto v_24850;
v_24851:
    v_25098 = stack[-4];
    goto v_24852;
v_24853:
    v_25097 = stack[-3];
    goto v_24854;
v_24855:
    goto v_24849;
v_24850:
    goto v_24851;
v_24852:
    goto v_24853;
v_24854:
    {
        fn = elt(env, 32); // form1
        return (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    }
v_24830:
    goto v_24888;
v_24884:
    v_25098 = stack[-3];
    goto v_24885;
v_24886:
    v_25097 = elt(env, 3); // symbolic
    goto v_24887;
v_24888:
    goto v_24884;
v_24885:
    goto v_24886;
v_24887:
    if (v_25098 == v_25097) goto v_24882;
    else goto v_24883;
v_24882:
    v_25097 = qvalue(elt(env, 16)); // !*rlisp88
    if (v_25097 == nil) goto v_24893;
    else goto v_24892;
v_24893:
    goto v_24900;
v_24896:
    v_25098 = stack[-2];
    goto v_24897;
v_24898:
    v_25097 = elt(env, 17); // structfetch
    goto v_24899;
v_24900:
    goto v_24896;
v_24897:
    goto v_24898;
v_24899:
    v_25097 = Leqcar(nil, v_25098, v_25097);
    env = stack[-6];
v_24892:
    goto v_24881;
v_24883:
    v_25097 = nil;
    goto v_24881;
    v_25097 = nil;
v_24881:
    if (v_25097 == nil) goto v_24879;
    goto v_24913;
v_24907:
    stack[0] = elt(env, 18); // rsetf
    goto v_24908;
v_24909:
    goto v_24922;
v_24916:
    v_25099 = stack[-2];
    goto v_24917;
v_24918:
    v_25098 = stack[-4];
    goto v_24919;
v_24920:
    v_25097 = stack[-3];
    goto v_24921;
v_24922:
    goto v_24916;
v_24917:
    goto v_24918;
v_24919:
    goto v_24920;
v_24921:
    fn = elt(env, 32); // form1
    v_25098 = (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    goto v_24910;
v_24911:
    v_25097 = stack[-5];
    goto v_24912;
v_24913:
    goto v_24907;
v_24908:
    goto v_24909;
v_24910:
    goto v_24911;
v_24912:
    {
        LispObject v_25108 = stack[0];
        return list3(v_25108, v_25098, v_25097);
    }
v_24879:
    goto v_24936;
v_24930:
    stack[0] = elt(env, 19); // setk
    goto v_24931;
v_24932:
    goto v_24945;
v_24939:
    v_25099 = stack[-2];
    goto v_24940;
v_24941:
    v_25098 = stack[-4];
    goto v_24942;
v_24943:
    v_25097 = elt(env, 20); // algebraic
    goto v_24944;
v_24945:
    goto v_24939;
v_24940:
    goto v_24941;
v_24942:
    goto v_24943;
v_24944:
    fn = elt(env, 32); // form1
    v_25098 = (*qfnn(fn))(fn, 3, v_25099, v_25098, v_25097);
    goto v_24933;
v_24934:
    v_25097 = stack[-5];
    goto v_24935;
v_24936:
    goto v_24930;
v_24931:
    goto v_24932;
v_24933:
    goto v_24934;
v_24935:
    {
        LispObject v_25109 = stack[0];
        return list3(v_25109, v_25098, v_25097);
    }
    v_25097 = nil;
    goto v_24621;
v_24623:
    v_25097 = stack[-2];
    if (symbolp(v_25097)) goto v_24951;
    goto v_24958;
v_24954:
    v_25098 = stack[-2];
    goto v_24955;
v_24956:
    v_25097 = elt(env, 8); // "assignment"
    goto v_24957;
v_24958:
    goto v_24954;
v_24955:
    goto v_24956;
v_24957:
    {
        fn = elt(env, 24); // typerr
        return (*qfn2(fn))(fn, v_25098, v_25097);
    }
v_24951:
    goto v_24972;
v_24968:
    v_25098 = stack[-2];
    goto v_24969;
v_24970:
    v_25097 = elt(env, 21); // reserved
    goto v_24971;
v_24972:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    v_25097 = Lflagp(nil, v_25098, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_24966;
    goto v_24979;
v_24975:
    v_25098 = stack[-2];
    goto v_24976;
v_24977:
    v_25097 = stack[-4];
    goto v_24978;
v_24979:
    goto v_24975;
v_24976:
    goto v_24977;
v_24978:
    v_25097 = Latsoc(nil, v_25098, v_25097);
    v_25097 = (v_25097 == nil ? lisp_true : nil);
    goto v_24964;
v_24966:
    v_25097 = nil;
    goto v_24964;
    v_25097 = nil;
v_24964:
    if (v_25097 == nil) goto v_24962;
    v_25097 = stack[-2];
    {
        fn = elt(env, 33); // rsverr
        return (*qfn1(fn))(fn, v_25097);
    }
v_24962:
    v_25097 = stack[-2];
    if (!symbolp(v_25097)) v_25097 = nil;
    else { v_25097 = qfastgets(v_25097);
           if (v_25097 != nil) { v_25097 = elt(v_25097, 17); // share
#ifdef RECORD_GET
             if (v_25097 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_25097 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_25097 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_25097 == SPID_NOPROP) v_25097 = nil; else v_25097 = lisp_true; }}
#endif
    if (v_25097 == nil) goto v_24990;
    goto v_24998;
v_24994:
    goto v_25004;
v_25000:
    v_25098 = stack[-2];
    goto v_25001;
v_25002:
    v_25097 = stack[-4];
    goto v_25003;
v_25004:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    fn = elt(env, 34); // symbid
    v_25098 = (*qfn2(fn))(fn, v_25098, v_25097);
    env = stack[-6];
    goto v_24995;
v_24996:
    v_25097 = stack[-5];
    goto v_24997;
v_24998:
    goto v_24994;
v_24995:
    goto v_24996;
v_24997:
    {
        fn = elt(env, 35); // mksetshare
        return (*qfn2(fn))(fn, v_25098, v_25097);
    }
v_24990:
    goto v_25018;
v_25014:
    v_25098 = stack[-3];
    goto v_25015;
v_25016:
    v_25097 = elt(env, 3); // symbolic
    goto v_25017;
v_25018:
    goto v_25014;
v_25015:
    goto v_25016;
v_25017:
    if (v_25098 == v_25097) goto v_25012;
    else goto v_25013;
v_25012:
    v_25097 = lisp_true;
    goto v_25011;
v_25013:
    v_25097 = stack[-1];
    if (v_25097 == nil) goto v_25026;
    else goto v_25025;
v_25026:
    goto v_25033;
v_25029:
    v_25098 = stack[-5];
    goto v_25030;
v_25031:
    v_25097 = elt(env, 2); // quote
    goto v_25032;
v_25033:
    goto v_25029;
v_25030:
    goto v_25031;
v_25032:
    v_25097 = Leqcar(nil, v_25098, v_25097);
    env = stack[-6];
v_25025:
    goto v_25011;
    v_25097 = nil;
v_25011:
    if (v_25097 == nil) goto v_25009;
    goto v_25041;
v_25037:
    goto v_25047;
v_25043:
    v_25098 = stack[-2];
    goto v_25044;
v_25045:
    v_25097 = stack[-4];
    goto v_25046;
v_25047:
    goto v_25043;
v_25044:
    goto v_25045;
v_25046:
    fn = elt(env, 34); // symbid
    v_25098 = (*qfn2(fn))(fn, v_25098, v_25097);
    env = stack[-6];
    goto v_25038;
v_25039:
    v_25097 = stack[-5];
    goto v_25040;
v_25041:
    goto v_25037;
v_25038:
    goto v_25039;
v_25040:
    {
        fn = elt(env, 36); // mksetq
        return (*qfn2(fn))(fn, v_25098, v_25097);
    }
v_25009:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    v_25097 = qcar(v_25097);
    v_25097 = Lsimple_vectorp(nil, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_25053;
    else goto v_25051;
v_25053:
    goto v_25064;
v_25060:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    v_25098 = qcar(v_25097);
    goto v_25061;
v_25062:
    v_25097 = elt(env, 11); // vecfn
    goto v_25063;
v_25064:
    goto v_25060;
v_25061:
    goto v_25062;
v_25063:
    v_25097 = Lflagpcar(nil, v_25098, v_25097);
    env = stack[-6];
    if (v_25097 == nil) goto v_25058;
    else goto v_25051;
v_25058:
    goto v_25052;
v_25051:
    goto v_25076;
v_25070:
    stack[-1] = elt(env, 22); // setv
    goto v_25071;
v_25072:
    v_25097 = stack[-2];
    v_25098 = Lmkquote(nil, v_25097);
    goto v_25073;
v_25074:
    v_25097 = stack[0];
    v_25097 = qcdr(v_25097);
    v_25097 = qcar(v_25097);
    goto v_25075;
v_25076:
    goto v_25070;
v_25071:
    goto v_25072;
v_25073:
    goto v_25074;
v_25075:
    {
        LispObject v_25110 = stack[-1];
        return list3(v_25110, v_25098, v_25097);
    }
v_25052:
    goto v_25092;
v_25086:
    stack[0] = elt(env, 19); // setk
    goto v_25087;
v_25088:
    v_25097 = stack[-2];
    v_25098 = Lmkquote(nil, v_25097);
    goto v_25089;
v_25090:
    v_25097 = stack[-5];
    goto v_25091;
v_25092:
    goto v_25086;
v_25087:
    goto v_25088;
v_25089:
    goto v_25090;
v_25091:
    {
        LispObject v_25111 = stack[0];
        return list3(v_25111, v_25098, v_25097);
    }
    v_25097 = nil;
v_24621:
    return onevalue(v_25097);
}



// Code for nonmult

static LispObject CC_nonmult(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24585, v_24586;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    goto v_24571;
v_24567:
    goto v_24577;
v_24573:
    v_24585 = qvalue(elt(env, 1)); // vjets!*
    v_24586 = Lreverse(nil, v_24585);
    env = stack[-1];
    goto v_24574;
v_24575:
    v_24585 = stack[0];
    goto v_24576;
v_24577:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(fn, v_24586, v_24585);
    env = stack[-1];
    goto v_24568;
v_24569:
    v_24585 = qvalue(elt(env, 1)); // vjets!*
    v_24585 = Lreverse(nil, v_24585);
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    v_24585 = Lmember(nil, stack[0], v_24585);
    v_24585 = qcdr(v_24585);
        return Lreverse(nil, v_24585);
}



// Code for gadd

static LispObject CC_gadd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24688, v_24689, v_24690;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gadd");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_24566;
    stack[-3] = v_24565;
    stack[-4] = v_24564;
// end of prologue
    stack[-5] = nil;
    v_24688 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_24688;
    goto v_24587;
v_24583:
    v_24689 = stack[-2];
    goto v_24584;
v_24585:
    v_24688 = stack[-3];
    goto v_24586;
v_24587:
    goto v_24583;
v_24584:
    goto v_24585;
v_24586:
    v_24688 = Latsoc(nil, v_24689, v_24688);
    stack[-1] = v_24688;
    if (v_24688 == nil) goto v_24581;
    else goto v_24582;
v_24581:
    goto v_24573;
v_24582:
    goto v_24596;
v_24592:
    v_24689 = stack[-1];
    goto v_24593;
v_24594:
    v_24688 = stack[-3];
    goto v_24595;
v_24596:
    goto v_24592;
v_24593:
    goto v_24594;
v_24595:
    v_24688 = Ldelete(nil, v_24689, v_24688);
    env = stack[-6];
    stack[-3] = v_24688;
    v_24688 = stack[-1];
    v_24688 = qcdr(v_24688);
    v_24688 = qcdr(v_24688);
    stack[-5] = v_24688;
    v_24688 = stack[-1];
    v_24688 = qcdr(v_24688);
    v_24688 = qcar(v_24688);
    stack[-1] = v_24688;
v_24573:
    v_24688 = stack[-4];
    if (v_24688 == nil) goto v_24607;
    else goto v_24608;
v_24607:
    goto v_24617;
v_24611:
    v_24688 = stack[0];
    stack[0] = Levenp(nil, v_24688);
    env = stack[-6];
    goto v_24612;
v_24613:
    goto v_24627;
v_24621:
    v_24690 = stack[-2];
    goto v_24622;
v_24623:
    v_24689 = stack[-1];
    goto v_24624;
v_24625:
    v_24688 = stack[-5];
    goto v_24626;
v_24627:
    goto v_24621;
v_24622:
    goto v_24623;
v_24624:
    goto v_24625;
v_24626:
    v_24689 = list2star(v_24690, v_24689, v_24688);
    goto v_24614;
v_24615:
    v_24688 = stack[-3];
    goto v_24616;
v_24617:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    goto v_24615;
v_24616:
    {
        LispObject v_24697 = stack[0];
        return list2star(v_24697, v_24689, v_24688);
    }
v_24608:
    goto v_24638;
v_24634:
    v_24688 = stack[-4];
    v_24689 = qcar(v_24688);
    goto v_24635;
v_24636:
    v_24688 = elt(env, 2); // a
    goto v_24637;
v_24638:
    goto v_24634;
v_24635:
    goto v_24636;
v_24637:
    if (v_24689 == v_24688) goto v_24632;
    else goto v_24633;
v_24632:
    goto v_24575;
v_24633:
    goto v_24649;
v_24645:
    v_24688 = stack[-4];
    v_24689 = qcar(v_24688);
    goto v_24646;
v_24647:
    v_24688 = stack[-5];
    goto v_24648;
v_24649:
    goto v_24645;
v_24646:
    goto v_24647;
v_24648:
    v_24688 = cons(v_24689, v_24688);
    env = stack[-6];
    stack[-5] = v_24688;
    goto v_24606;
v_24606:
v_24574:
    v_24688 = stack[-4];
    v_24688 = qcdr(v_24688);
    stack[-4] = v_24688;
    goto v_24573;
v_24575:
    goto v_24663;
v_24659:
    v_24689 = qvalue(elt(env, 3)); // ndims!*
    goto v_24660;
v_24661:
    v_24688 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24662;
v_24663:
    goto v_24659;
v_24660:
    goto v_24661;
v_24662:
    if (v_24689 == v_24688) goto v_24658;
    goto v_24673;
v_24667:
    v_24690 = elt(env, 4); // hephys
    goto v_24668;
v_24669:
    v_24689 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_24670;
v_24671:
    v_24688 = elt(env, 5); // "Gamma5 not allowed unless vecdim is 4"
    goto v_24672;
v_24673:
    goto v_24667;
v_24668:
    goto v_24669;
v_24670:
    goto v_24671;
v_24672:
    fn = elt(env, 6); // rerror
    v_24688 = (*qfnn(fn))(fn, 3, v_24690, v_24689, v_24688);
    env = stack[-6];
    goto v_24656;
v_24658:
v_24656:
    v_24688 = stack[-1];
    v_24688 = (v_24688 == nil ? lisp_true : nil);
    stack[-1] = v_24688;
    goto v_24684;
v_24680:
    v_24688 = stack[-5];
    v_24689 = Llength(nil, v_24688);
    env = stack[-6];
    goto v_24681;
v_24682:
    v_24688 = stack[0];
    goto v_24683;
v_24684:
    goto v_24680;
v_24681:
    goto v_24682;
v_24683:
    v_24688 = plus2(v_24689, v_24688);
    env = stack[-6];
    stack[0] = v_24688;
    goto v_24574;
    return onevalue(v_24688);
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24627, v_24628;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24566;
    stack[-2] = v_24565;
    stack[-3] = v_24564;
// end of prologue
v_24572:
    v_24627 = stack[-2];
    if (v_24627 == nil) goto v_24575;
    else goto v_24576;
v_24575:
    v_24627 = stack[-1];
        return Lnreverse(nil, v_24627);
v_24576:
    goto v_24587;
v_24583:
    goto v_24593;
v_24589:
    v_24627 = stack[-3];
    v_24628 = qcar(v_24627);
    goto v_24590;
v_24591:
    v_24627 = stack[-2];
    v_24627 = qcar(v_24627);
    v_24627 = qcar(v_24627);
    goto v_24592;
v_24593:
    goto v_24589;
v_24590:
    goto v_24591;
v_24592:
    v_24628 = difference2(v_24628, v_24627);
    env = stack[-5];
    goto v_24584;
v_24585:
    v_24627 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24586;
v_24587:
    goto v_24583;
v_24584:
    goto v_24585;
v_24586:
    v_24627 = (LispObject)lessp2(v_24628, v_24627);
    v_24627 = v_24627 ? lisp_true : nil;
    env = stack[-5];
    if (v_24627 == nil) goto v_24581;
    v_24627 = nil;
    goto v_24571;
v_24581:
    v_24627 = stack[-3];
    v_24627 = qcdr(v_24627);
    stack[-4] = v_24627;
    v_24627 = stack[-2];
    v_24627 = qcdr(v_24627);
    stack[0] = v_24627;
    goto v_24612;
v_24608:
    goto v_24618;
v_24614:
    v_24627 = stack[-3];
    v_24628 = qcar(v_24627);
    goto v_24615;
v_24616:
    v_24627 = stack[-2];
    v_24627 = qcar(v_24627);
    v_24627 = qcar(v_24627);
    goto v_24617;
v_24618:
    goto v_24614;
v_24615:
    goto v_24616;
v_24617:
    v_24628 = difference2(v_24628, v_24627);
    env = stack[-5];
    goto v_24609;
v_24610:
    v_24627 = stack[-1];
    goto v_24611;
v_24612:
    goto v_24608;
v_24609:
    goto v_24610;
v_24611:
    v_24627 = cons(v_24628, v_24627);
    env = stack[-5];
    stack[-1] = v_24627;
    v_24627 = stack[0];
    stack[-2] = v_24627;
    v_24627 = stack[-4];
    stack[-3] = v_24627;
    goto v_24572;
    v_24627 = nil;
v_24571:
    return onevalue(v_24627);
}



// Code for mk!+equation

static LispObject CC_mkLequation(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24581, v_24582, v_24583;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24581 = v_24565;
    v_24582 = v_24564;
// end of prologue
    goto v_24577;
v_24571:
    v_24583 = elt(env, 1); // equal
    goto v_24572;
v_24573:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    return list3(v_24583, v_24582, v_24581);
    return onevalue(v_24581);
}



// Code for rl_identity1

static LispObject CC_rl_identity1(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24567;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24567 = v_24564;
// end of prologue
    return onevalue(v_24567);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24569;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
// copy arguments values to proper place
    v_24569 = v_24564;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_24569 = (*qfn1(fn))(fn, v_24569);
    v_24569 = (v_24569 == nil ? lisp_true : nil);
    return onevalue(v_24569);
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24628, v_24629;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    v_24628 = elt(env, 1); // "<OMATTR>"
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = lisp_true;
    fn = elt(env, 10); // indent!*
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 2); // "<OMATP>"
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = lisp_true;
    fn = elt(env, 10); // indent!*
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 3); // "<OMS cd=""typmml"" name=""type"">"
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 4); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    goto v_24586;
v_24582:
    v_24628 = stack[0];
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    v_24628 = qcar(v_24628);
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    v_24629 = Lintern(nil, v_24628);
    env = stack[-1];
    goto v_24583;
v_24584:
    v_24628 = qvalue(elt(env, 5)); // mmltypes!*
    goto v_24585;
v_24586:
    goto v_24582;
v_24583:
    goto v_24584;
v_24585:
    v_24628 = Lassoc(nil, v_24629, v_24628);
    v_24628 = Lprinc(nil, v_24628);
    env = stack[-1];
    goto v_24601;
v_24597:
    v_24628 = stack[0];
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    v_24628 = qcar(v_24628);
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    v_24629 = Lintern(nil, v_24628);
    env = stack[-1];
    goto v_24598;
v_24599:
    v_24628 = qvalue(elt(env, 5)); // mmltypes!*
    goto v_24600;
v_24601:
    goto v_24597;
v_24598:
    goto v_24599;
v_24600:
    v_24628 = Lassoc(nil, v_24629, v_24628);
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    v_24628 = Lprinc(nil, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 6); // """>"
    v_24628 = Lprinc(nil, v_24628);
    env = stack[-1];
    v_24628 = nil;
    fn = elt(env, 10); // indent!*
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 7); // "</OMATP>"
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = stack[0];
    v_24628 = qcdr(v_24628);
    v_24628 = qcdr(v_24628);
    v_24628 = qcar(v_24628);
    fn = elt(env, 11); // objectom
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = nil;
    fn = elt(env, 10); // indent!*
    v_24628 = (*qfn1(fn))(fn, v_24628);
    env = stack[-1];
    v_24628 = elt(env, 8); // "</OMATTR>"
    fn = elt(env, 9); // printout
    v_24628 = (*qfn1(fn))(fn, v_24628);
    v_24628 = nil;
    return onevalue(v_24628);
}



// Code for f4

static LispObject CC_f4(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24803, v_24804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24564;
// end of prologue
    goto v_24577;
v_24573:
    v_24804 = stack[0];
    goto v_24574;
v_24575:
    v_24803 = elt(env, 1); // pi
    goto v_24576;
v_24577:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    if (v_24804 == v_24803) goto v_24571;
    else goto v_24572;
v_24571:
    v_24803 = elt(env, 2); // "<pi/>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24572:
    goto v_24588;
v_24584:
    v_24804 = stack[0];
    goto v_24585;
v_24586:
    v_24803 = elt(env, 3); // euler_gamma
    goto v_24587;
v_24588:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    if (v_24804 == v_24803) goto v_24582;
    else goto v_24583;
v_24582:
    v_24803 = elt(env, 4); // "<eulergamma/>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24583:
    goto v_24599;
v_24595:
    v_24804 = stack[0];
    goto v_24596;
v_24597:
    v_24803 = elt(env, 5); // true
    goto v_24598;
v_24599:
    goto v_24595;
v_24596:
    goto v_24597;
v_24598:
    if (v_24804 == v_24803) goto v_24593;
    else goto v_24594;
v_24593:
    v_24803 = elt(env, 6); // "<true/>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24594:
    goto v_24610;
v_24606:
    v_24804 = stack[0];
    goto v_24607;
v_24608:
    v_24803 = elt(env, 7); // false
    goto v_24609;
v_24610:
    goto v_24606;
v_24607:
    goto v_24608;
v_24609:
    if (v_24804 == v_24803) goto v_24604;
    else goto v_24605;
v_24604:
    v_24803 = elt(env, 8); // "<false/>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24605:
    goto v_24621;
v_24617:
    v_24804 = stack[0];
    goto v_24618;
v_24619:
    v_24803 = elt(env, 9); // !Na!N
    goto v_24620;
v_24621:
    goto v_24617;
v_24618:
    goto v_24619;
v_24620:
    if (v_24804 == v_24803) goto v_24615;
    else goto v_24616;
v_24615:
    v_24803 = elt(env, 10); // "<notanumber/>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24616:
    goto v_24632;
v_24628:
    v_24804 = stack[0];
    goto v_24629;
v_24630:
    v_24803 = elt(env, 11); // infinity
    goto v_24631;
v_24632:
    goto v_24628;
v_24629:
    goto v_24630;
v_24631:
    if (v_24804 == v_24803) goto v_24626;
    else goto v_24627;
v_24626:
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24637;
    else goto v_24638;
v_24637:
    v_24803 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24636;
v_24638:
    v_24803 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24636;
v_24636:
    v_24803 = elt(env, 15); // "&infin;"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    v_24803 = elt(env, 16); // "</cn>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24570;
v_24627:
    goto v_24660;
v_24656:
    v_24804 = stack[0];
    goto v_24657;
v_24658:
    v_24803 = elt(env, 17); // e
    goto v_24659;
v_24660:
    goto v_24656;
v_24657:
    goto v_24658;
v_24659:
    if (v_24804 == v_24803) goto v_24654;
    else goto v_24655;
v_24654:
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24665;
    else goto v_24666;
v_24665:
    v_24803 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24664;
v_24666:
    v_24803 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24664;
v_24664:
    v_24803 = elt(env, 18); // "&ExponentialE;"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    v_24803 = elt(env, 16); // "</cn>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24653;
v_24655:
    goto v_24688;
v_24684:
    v_24804 = stack[0];
    goto v_24685;
v_24686:
    v_24803 = elt(env, 19); // i
    goto v_24687;
v_24688:
    goto v_24684;
v_24685:
    goto v_24686;
v_24687:
    if (v_24804 == v_24803) goto v_24682;
    else goto v_24683;
v_24682:
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24693;
    else goto v_24694;
v_24693:
    v_24803 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24692;
v_24694:
    v_24803 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    goto v_24692;
v_24692:
    v_24803 = elt(env, 20); // "&ImaginaryI;"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    v_24803 = elt(env, 16); // "</cn>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24681;
v_24683:
    v_24803 = stack[0];
    if (is_number(v_24803)) goto v_24710;
    else goto v_24711;
v_24710:
    v_24803 = elt(env, 21); // "<cn"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    v_24803 = stack[0];
    v_24803 = Lfloatp(nil, v_24803);
    env = stack[-1];
    if (v_24803 == nil) goto v_24718;
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24723;
    else goto v_24724;
v_24723:
    v_24803 = elt(env, 22); // " type=""real"">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24722;
v_24724:
    v_24803 = elt(env, 23); // " type=&quot;real&quot;>"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24722;
v_24722:
    goto v_24716;
v_24718:
    v_24803 = stack[0];
    v_24803 = integerp(v_24803);
    if (v_24803 == nil) goto v_24733;
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24738;
    else goto v_24739;
v_24738:
    v_24803 = elt(env, 24); // " type=""integer"">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24737;
v_24739:
    v_24803 = elt(env, 25); // " type=&quot;integer&quot;>"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24737;
v_24737:
    goto v_24716;
v_24733:
    v_24803 = elt(env, 26); // ">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24716;
v_24716:
    v_24803 = stack[0];
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    v_24803 = elt(env, 16); // "</cn>"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24709;
v_24711:
v_24709:
    v_24803 = stack[0];
    if (symbolp(v_24803)) goto v_24757;
    else goto v_24758;
v_24757:
    v_24803 = elt(env, 27); // "<ci"
    fn = elt(env, 33); // printout
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    v_24803 = stack[0];
    fn = elt(env, 34); // listp
    v_24803 = (*qfn1(fn))(fn, v_24803);
    env = stack[-1];
    if (v_24803 == nil) goto v_24765;
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24770;
    else goto v_24771;
v_24770:
    v_24803 = elt(env, 28); // " type=""list"">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24769;
v_24771:
    v_24803 = elt(env, 29); // " type=&quot;list&quot;>"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24769;
v_24769:
    goto v_24763;
v_24765:
    v_24803 = stack[0];
    v_24803 = Lsimple_vectorp(nil, v_24803);
    env = stack[-1];
    if (v_24803 == nil) goto v_24780;
    v_24803 = qvalue(elt(env, 12)); // !*web
    if (v_24803 == nil) goto v_24785;
    else goto v_24786;
v_24785:
    v_24803 = elt(env, 30); // " type=""vector"">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24784;
v_24786:
    v_24803 = elt(env, 31); // " type=&quot;vector&quot;>"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24784;
v_24784:
    goto v_24763;
v_24780:
    v_24803 = elt(env, 26); // ">"
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    goto v_24763;
v_24763:
    v_24803 = stack[0];
    v_24803 = Lprinc(nil, v_24803);
    env = stack[-1];
    v_24803 = elt(env, 32); // "</ci>"
    v_24803 = Lprinc(nil, v_24803);
    goto v_24756;
v_24758:
v_24756:
    goto v_24681;
v_24681:
    goto v_24653;
v_24653:
    goto v_24570;
v_24570:
    v_24803 = nil;
    return onevalue(v_24803);
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v_24564, LispObject v_24565)
{
    env = qenv(env);
    LispObject v_24592, v_24593, v_24594, v_24595;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24594 = v_24565;
    v_24595 = v_24564;
// end of prologue
    goto v_24575;
v_24571:
    v_24593 = v_24594;
    goto v_24572;
v_24573:
    v_24592 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24574;
v_24575:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    if (v_24593 == v_24592) goto v_24569;
    else goto v_24570;
v_24569:
    v_24592 = v_24595;
    goto v_24568;
v_24570:
    goto v_24588;
v_24582:
    v_24592 = elt(env, 1); // expt
    goto v_24583;
v_24584:
    v_24593 = v_24595;
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    goto v_24582;
v_24583:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    return list3(v_24592, v_24593, v_24594);
    v_24592 = nil;
v_24568:
    return onevalue(v_24592);
}



// Code for rnfix!*

static LispObject CC_rnfixH(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24578, v_24579;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24578 = v_24564;
// end of prologue
    goto v_24571;
v_24567:
    v_24579 = v_24578;
    v_24579 = qcdr(v_24579);
    v_24579 = qcar(v_24579);
    goto v_24568;
v_24569:
    v_24578 = qcdr(v_24578);
    v_24578 = qcdr(v_24578);
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    return quot2(v_24579, v_24578);
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v_24564)
{
    env = qenv(env);
    LispObject v_24603, v_24604;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24564);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24604 = v_24564;
// end of prologue
    goto v_24571;
v_24567:
    goto v_24578;
v_24574:
    goto v_24584;
v_24580:
    goto v_24592;
v_24586:
    stack[-1] = elt(env, 1); // u
    goto v_24587;
v_24588:
    v_24603 = v_24604;
    stack[0] = qcar(v_24603);
    goto v_24589;
v_24590:
    v_24603 = v_24604;
    v_24603 = qcdr(v_24603);
    fn = elt(env, 2); // ordn
    v_24603 = (*qfn1(fn))(fn, v_24603);
    env = stack[-2];
    v_24603 = Lreverse(nil, v_24603);
    env = stack[-2];
    goto v_24591;
v_24592:
    goto v_24586;
v_24587:
    goto v_24588;
v_24589:
    goto v_24590;
v_24591:
    v_24604 = list2star(stack[-1], stack[0], v_24603);
    env = stack[-2];
    goto v_24581;
v_24582:
    v_24603 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24583;
v_24584:
    goto v_24580;
v_24581:
    goto v_24582;
v_24583:
    fn = elt(env, 3); // mksp
    v_24604 = (*qfn2(fn))(fn, v_24604, v_24603);
    env = stack[-2];
    goto v_24575;
v_24576:
    v_24603 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24577;
v_24578:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    v_24603 = cons(v_24604, v_24603);
    env = stack[-2];
    v_24604 = ncons(v_24603);
    goto v_24568;
v_24569:
    v_24603 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    return cons(v_24604, v_24603);
}



// Code for findoptrow

static LispObject CC_findoptrow(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24752, v_24753, v_24754, v_24755;
    LispObject fn;
    LispObject v_24566, v_24565, v_24564;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findoptrow");
    va_start(aa, nargs);
    v_24564 = va_arg(aa, LispObject);
    v_24565 = va_arg(aa, LispObject);
    v_24566 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24566,v_24565,v_24564);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24564,v_24565,v_24566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_24566;
    stack[0] = v_24565;
    stack[-6] = v_24564;
// end of prologue
    stack[-7] = nil;
    goto v_24581;
v_24577:
    stack[-2] = stack[0];
    goto v_24578;
v_24579:
    goto v_24587;
v_24583:
    goto v_24592;
v_24588:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_24589;
v_24590:
    goto v_24599;
v_24595:
    v_24753 = qvalue(elt(env, 3)); // maxvar
    goto v_24596;
v_24597:
    v_24752 = stack[-6];
    goto v_24598;
v_24599:
    goto v_24595;
v_24596:
    goto v_24597;
v_24598:
    v_24752 = plus2(v_24753, v_24752);
    env = stack[-8];
    goto v_24591;
v_24592:
    goto v_24588;
v_24589:
    goto v_24590;
v_24591:
    v_24753 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    goto v_24584;
v_24585:
    v_24752 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24586;
v_24587:
    goto v_24583;
v_24584:
    goto v_24585;
v_24586:
    v_24752 = *(LispObject *)((char *)v_24753 + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    goto v_24580;
v_24581:
    goto v_24577;
v_24578:
    goto v_24579;
v_24580:
    fn = elt(env, 8); // pnthxzz
    v_24752 = (*qfn2(fn))(fn, stack[-2], v_24752);
    env = stack[-8];
    v_24752 = qcar(v_24752);
    v_24752 = qcdr(v_24752);
    v_24752 = qcar(v_24752);
    stack[-3] = v_24752;
    goto v_24616;
v_24612:
    goto v_24621;
v_24617:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_24618;
v_24619:
    goto v_24628;
v_24624:
    v_24753 = qvalue(elt(env, 3)); // maxvar
    goto v_24625;
v_24626:
    v_24752 = stack[0];
    goto v_24627;
v_24628:
    goto v_24624;
v_24625:
    goto v_24626;
v_24627:
    v_24752 = plus2(v_24753, v_24752);
    env = stack[-8];
    goto v_24620;
v_24621:
    goto v_24617;
v_24618:
    goto v_24619;
v_24620:
    v_24753 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    goto v_24613;
v_24614:
    v_24752 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24615;
v_24616:
    goto v_24612;
v_24613:
    goto v_24614;
v_24615:
    v_24752 = *(LispObject *)((char *)v_24753 + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_24752;
v_24611:
    v_24752 = stack[-2];
    if (v_24752 == nil) goto v_24636;
    else goto v_24637;
v_24636:
    goto v_24610;
v_24637:
    v_24752 = stack[-2];
    v_24752 = qcar(v_24752);
    stack[-1] = v_24752;
    goto v_24651;
v_24647:
    goto v_24656;
v_24652:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_24653;
v_24654:
    goto v_24663;
v_24659:
    v_24753 = qvalue(elt(env, 3)); // maxvar
    goto v_24660;
v_24661:
    v_24752 = stack[-1];
    v_24752 = qcar(v_24752);
    stack[-4] = v_24752;
    goto v_24662;
v_24663:
    goto v_24659;
v_24660:
    goto v_24661;
v_24662:
    v_24752 = plus2(v_24753, v_24752);
    env = stack[-8];
    goto v_24655;
v_24656:
    goto v_24652;
v_24653:
    goto v_24654;
v_24655:
    v_24753 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    goto v_24648;
v_24649:
    v_24752 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24650;
v_24651:
    goto v_24647;
v_24648:
    goto v_24649;
v_24650:
    v_24752 = *(LispObject *)((char *)v_24753 + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    if (v_24752 == nil) goto v_24646;
    goto v_24683;
v_24675:
    v_24755 = stack[-4];
    goto v_24676;
v_24677:
    v_24754 = stack[-6];
    goto v_24678;
v_24679:
    v_24752 = stack[-1];
    v_24752 = qcdr(v_24752);
    v_24753 = qcar(v_24752);
    goto v_24680;
v_24681:
    v_24752 = stack[-3];
    goto v_24682;
v_24683:
    goto v_24675;
v_24676:
    goto v_24677;
v_24678:
    goto v_24679;
v_24680:
    goto v_24681;
v_24682:
    fn = elt(env, 9); // testpr
    v_24752 = (*qfnn(fn))(fn, 4, v_24755, v_24754, v_24753, v_24752);
    env = stack[-8];
    stack[0] = v_24752;
    v_24752 = qcdr(v_24752);
    if (v_24752 == nil) goto v_24672;
    else goto v_24673;
v_24672:
    goto v_24696;
v_24692:
    v_24753 = stack[-4];
    goto v_24693;
v_24694:
    v_24752 = qvalue(elt(env, 4)); // roccup1
    goto v_24695;
v_24696:
    goto v_24692;
v_24693:
    goto v_24694;
v_24695:
    v_24752 = cons(v_24753, v_24752);
    env = stack[-8];
    qvalue(elt(env, 4)) = v_24752; // roccup1
    goto v_24671;
v_24673:
    goto v_24710;
v_24706:
    v_24752 = stack[0];
    v_24753 = Llength(nil, v_24752);
    env = stack[-8];
    stack[-1] = v_24753;
    goto v_24707;
v_24708:
    v_24752 = stack[-5];
    goto v_24709;
v_24710:
    goto v_24706;
v_24707:
    goto v_24708;
v_24709:
    v_24752 = (LispObject)greaterp2(v_24753, v_24752);
    v_24752 = v_24752 ? lisp_true : nil;
    env = stack[-8];
    if (v_24752 == nil) goto v_24704;
    v_24752 = stack[-1];
    stack[-5] = v_24752;
    qvalue(elt(env, 5)) = v_24752; // newnjsi
    v_24752 = stack[-4];
    stack[-7] = v_24752;
    v_24752 = stack[0];
    qvalue(elt(env, 6)) = v_24752; // newjsi
    goto v_24702;
v_24704:
v_24702:
    goto v_24722;
v_24718:
    v_24753 = stack[-4];
    goto v_24719;
v_24720:
    v_24752 = qvalue(elt(env, 7)); // roccup2
    goto v_24721;
v_24722:
    goto v_24718;
v_24719:
    goto v_24720;
v_24721:
    v_24752 = cons(v_24753, v_24752);
    env = stack[-8];
    qvalue(elt(env, 7)) = v_24752; // roccup2
    goto v_24671;
v_24671:
    goto v_24731;
v_24725:
    goto v_24736;
v_24732:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_24733;
v_24734:
    goto v_24743;
v_24739:
    v_24753 = qvalue(elt(env, 3)); // maxvar
    goto v_24740;
v_24741:
    v_24752 = stack[-4];
    goto v_24742;
v_24743:
    goto v_24739;
v_24740:
    goto v_24741;
v_24742:
    v_24752 = plus2(v_24753, v_24752);
    env = stack[-8];
    goto v_24735;
v_24736:
    goto v_24732;
v_24733:
    goto v_24734;
v_24735:
    v_24754 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24752-TAG_FIXNUM)/(16/CELL)));
    goto v_24726;
v_24727:
    v_24753 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24728;
v_24729:
    v_24752 = nil;
    goto v_24730;
v_24731:
    goto v_24725;
v_24726:
    goto v_24727;
v_24728:
    goto v_24729;
v_24730:
    *(LispObject *)((char *)v_24754 + (CELL-TAG_VECTOR) + (((intptr_t)v_24753-TAG_FIXNUM)/(16/CELL))) = v_24752;
    goto v_24644;
v_24646:
v_24644:
    v_24752 = stack[-2];
    v_24752 = qcdr(v_24752);
    stack[-2] = v_24752;
    goto v_24611;
v_24610:
    v_24752 = stack[-7];
    return onevalue(v_24752);
}



setup_type const u44_setup[] =
{
    {"bc_sum",                  TOO_FEW_2,      CC_bc_sum,     WRONG_NO_2},
    {"symbolsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbolsrd},
    {"simpsqrtsq",              CC_simpsqrtsq,  TOO_MANY_1,    WRONG_NO_1},
    {"spcol_dim",               CC_spcol_dim,   TOO_MANY_1,    WRONG_NO_1},
    {"on-double1",              CC_onKdouble1,  TOO_MANY_1,    WRONG_NO_1},
    {"gfdiffer",                TOO_FEW_2,      CC_gfdiffer,   WRONG_NO_2},
    {"r2speclist1",             CC_r2speclist1, TOO_MANY_1,    WRONG_NO_1},
    {"mkassign",                TOO_FEW_2,      CC_mkassign,   WRONG_NO_2},
    {"consrecip",               CC_consrecip,   TOO_MANY_1,    WRONG_NO_1},
    {"simpdfp",                 CC_simpdfp,     TOO_MANY_1,    WRONG_NO_1},
    {"set-weights",             CC_setKweights, TOO_MANY_1,    WRONG_NO_1},
    {"simp-prop-dist",          CC_simpKpropKdist,TOO_MANY_1,  WRONG_NO_1},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC1_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lesspcar",                TOO_FEW_2,      CC_lesspcar,   WRONG_NO_2},
    {"xquotient-mod-p",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xquotientKmodKp},
    {"fctargs",                 CC_fctargs,     TOO_MANY_1,    WRONG_NO_1},
    {"talp_trygaussvar",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_trygaussvar},
    {"transposerd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_transposerd},
    {"findelem2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findelem2},
    {"inszzz",                  TOO_FEW_2,      CC_inszzz,     WRONG_NO_2},
    {"size_of_matrix",          CC_size_of_matrix,TOO_MANY_1,  WRONG_NO_1},
    {"a2vdp",                   CC_a2vdp,       TOO_MANY_1,    WRONG_NO_1},
    {"splitup",                 TOO_FEW_2,      CC_splitup,    WRONG_NO_2},
    {"list2vect*",              TOO_FEW_2,      CC_list2vectH, WRONG_NO_2},
    {"basic-kern",              CC_basicKkern,  TOO_MANY_1,    WRONG_NO_1},
    {"algmodep",                CC_algmodep,    TOO_MANY_1,    WRONG_NO_1},
    {"xnp",                     TOO_FEW_2,      CC_xnp,        WRONG_NO_2},
    {"lalr_set_nonterminal_codes",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_lalr_set_nonterminal_codes},
    {"co_hfn",                  CC_co_hfn,      TOO_MANY_1,    WRONG_NO_1},
    {"cl_subfof",               TOO_FEW_2,      CC_cl_subfof,  WRONG_NO_2},
    {"rl_sacatlp",              TOO_FEW_2,      CC_rl_sacatlp, WRONG_NO_2},
    {"pasf_coeflst",            TOO_FEW_2,      CC_pasf_coeflst,WRONG_NO_2},
    {"diffrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffrd},
    {"insertocc",               TOO_FEW_2,      CC_insertocc,  WRONG_NO_2},
    {"listpri",                 CC_listpri,     TOO_MANY_1,    WRONG_NO_1},
    {"physoppri",               CC_physoppri,   TOO_MANY_1,    WRONG_NO_1},
    {"find_bubles_coeff",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_find_bubles_coeff},
    {"formsetq0",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formsetq0},
    {"nonmult",                 CC_nonmult,     TOO_MANY_1,    WRONG_NO_1},
    {"gadd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gadd},
    {"subtractinds",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subtractinds},
    {"mk+equation",             TOO_FEW_2,      CC_mkLequation,WRONG_NO_2},
    {"rl_identity1",            CC_rl_identity1,TOO_MANY_1,    WRONG_NO_1},
    {"cgp_greenp",              CC_cgp_greenp,  TOO_MANY_1,    WRONG_NO_1},
    {"ciom",                    CC_ciom,        TOO_MANY_1,    WRONG_NO_1},
    {"f4",                      CC_f4,          TOO_MANY_1,    WRONG_NO_1},
    {"mkexpt",                  TOO_FEW_2,      CC_mkexpt,     WRONG_NO_2},
    {"rnfix*",                  CC_rnfixH,      TOO_MANY_1,    WRONG_NO_1},
    {"simpu",                   CC_simpu,       TOO_MANY_1,    WRONG_NO_1},
    {"findoptrow",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findoptrow},
    {NULL, (one_args *)"u44", (two_args *)"39339 5220155 5606765", 0}
};

// end of generated code
