
// $destdir/u10.c        Machine generated C code

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



// Code for pneg

static LispObject CC_pneg(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4774, v_4775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_4774 = v_4712;
// end of prologue
    stack[-4] = v_4774;
    v_4774 = stack[-4];
    if (v_4774 == nil) goto v_4723;
    else goto v_4724;
v_4723:
    v_4774 = nil;
    goto v_4718;
v_4724:
    v_4774 = stack[-4];
    v_4774 = qcar(v_4774);
    v_4775 = v_4774;
    goto v_4736;
v_4732:
    v_4774 = v_4775;
    stack[0] = qcar(v_4774);
    goto v_4733;
v_4734:
    v_4774 = v_4775;
    v_4774 = qcdr(v_4774);
    fn = elt(env, 1); // cneg
    v_4774 = (*qfn1(fn))(fn, v_4774);
    env = stack[-5];
    goto v_4735;
v_4736:
    goto v_4732;
v_4733:
    goto v_4734;
v_4735:
    v_4774 = cons(stack[0], v_4774);
    env = stack[-5];
    v_4774 = ncons(v_4774);
    env = stack[-5];
    stack[-2] = v_4774;
    stack[-3] = v_4774;
v_4719:
    v_4774 = stack[-4];
    v_4774 = qcdr(v_4774);
    stack[-4] = v_4774;
    v_4774 = stack[-4];
    if (v_4774 == nil) goto v_4746;
    else goto v_4747;
v_4746:
    v_4774 = stack[-3];
    goto v_4718;
v_4747:
    goto v_4755;
v_4751:
    stack[-1] = stack[-2];
    goto v_4752;
v_4753:
    v_4774 = stack[-4];
    v_4774 = qcar(v_4774);
    v_4775 = v_4774;
    goto v_4766;
v_4762:
    v_4774 = v_4775;
    stack[0] = qcar(v_4774);
    goto v_4763;
v_4764:
    v_4774 = v_4775;
    v_4774 = qcdr(v_4774);
    fn = elt(env, 1); // cneg
    v_4774 = (*qfn1(fn))(fn, v_4774);
    env = stack[-5];
    goto v_4765;
v_4766:
    goto v_4762;
v_4763:
    goto v_4764;
v_4765:
    v_4774 = cons(stack[0], v_4774);
    env = stack[-5];
    v_4774 = ncons(v_4774);
    env = stack[-5];
    goto v_4754;
v_4755:
    goto v_4751;
v_4752:
    goto v_4753;
v_4754:
    v_4774 = Lrplacd(nil, stack[-1], v_4774);
    env = stack[-5];
    v_4774 = stack[-2];
    v_4774 = qcdr(v_4774);
    stack[-2] = v_4774;
    goto v_4719;
v_4718:
    return onevalue(v_4774);
}



// Code for gintequiv!:

static LispObject CC_gintequivT(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4733, v_4734, v_4735;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4734 = v_4712;
// end of prologue
    goto v_4722;
v_4718:
    v_4733 = v_4734;
    v_4733 = qcdr(v_4733);
    v_4735 = qcdr(v_4733);
    goto v_4719;
v_4720:
    v_4733 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4721;
v_4722:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    if (v_4735 == v_4733) goto v_4716;
    else goto v_4717;
v_4716:
    v_4733 = v_4734;
    v_4733 = qcdr(v_4733);
    v_4733 = qcar(v_4733);
    goto v_4715;
v_4717:
    v_4733 = nil;
    goto v_4715;
    v_4733 = nil;
v_4715:
    return onevalue(v_4733);
}



// Code for carx

static LispObject CC_carx(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4743, v_4744, v_4745;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_4744 = v_4713;
    v_4745 = v_4712;
// end of prologue
    v_4743 = v_4745;
    v_4743 = qcdr(v_4743);
    if (v_4743 == nil) goto v_4717;
    else goto v_4718;
v_4717:
    v_4743 = v_4745;
    v_4743 = qcar(v_4743);
    goto v_4716;
v_4718:
    goto v_4732;
v_4726:
    stack[-1] = elt(env, 1); // alg
    goto v_4727;
v_4728:
    stack[0] = (LispObject)80+TAG_FIXNUM; // 5
    goto v_4729;
v_4730:
    goto v_4740;
v_4736:
    v_4743 = elt(env, 2); // "Wrong number of arguments to"
    goto v_4737;
v_4738:
    goto v_4739;
v_4740:
    goto v_4736;
v_4737:
    goto v_4738;
v_4739:
    v_4743 = list2(v_4743, v_4744);
    env = stack[-2];
    goto v_4731;
v_4732:
    goto v_4726;
v_4727:
    goto v_4728;
v_4729:
    goto v_4730;
v_4731:
    {
        LispObject v_4748 = stack[-1];
        LispObject v_4749 = stack[0];
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_4748, v_4749, v_4743);
    }
    v_4743 = nil;
v_4716:
    return onevalue(v_4743);
}



// Code for xread

static LispObject CC_xread(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4745, v_4746;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
v_4719:
    fn = elt(env, 4); // scan
    v_4745 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_4745 = qvalue(elt(env, 1)); // !*eoldelimp
    if (v_4745 == nil) goto v_4728;
    else goto v_4729;
v_4728:
    v_4745 = nil;
    goto v_4727;
v_4729:
    goto v_4738;
v_4734:
    v_4746 = qvalue(elt(env, 2)); // cursym!*
    goto v_4735;
v_4736:
    v_4745 = elt(env, 3); // !*semicol!*
    goto v_4737;
v_4738:
    goto v_4734;
v_4735:
    goto v_4736;
v_4737:
    v_4745 = (v_4746 == v_4745 ? lisp_true : nil);
    goto v_4727;
    v_4745 = nil;
v_4727:
    if (v_4745 == nil) goto v_4723;
    else goto v_4724;
v_4723:
    goto v_4718;
v_4724:
    goto v_4719;
v_4718:
    v_4745 = stack[0];
    {
        fn = elt(env, 5); // xread1
        return (*qfn1(fn))(fn, v_4745);
    }
    return onevalue(v_4745);
}



// Code for prepsq!*2

static LispObject CC_prepsqH2(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4726, v_4727, v_4728;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4726 = v_4712;
// end of prologue
    goto v_4722;
v_4716:
    v_4728 = v_4726;
    goto v_4717;
v_4718:
    v_4727 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4719;
v_4720:
    v_4726 = nil;
    goto v_4721;
v_4722:
    goto v_4716;
v_4717:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    fn = elt(env, 1); // prepsq!*1
    v_4726 = (*qfnn(fn))(fn, 3, v_4728, v_4727, v_4726);
    env = stack[0];
    {
        fn = elt(env, 2); // replus
        return (*qfn1(fn))(fn, v_4726);
    }
}



// Code for comfac

static LispObject CC_comfac(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4876, v_4877;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_4712;
// end of prologue
    stack[-3] = nil;
    v_4876 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v_4876)) v_4876 = nil;
    else { v_4876 = qfastgets(v_4876);
           if (v_4876 != nil) { v_4876 = elt(v_4876, 3); // field
#ifdef RECORD_GET
             if (v_4876 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_4876 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_4876 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_4876 == SPID_NOPROP) v_4876 = nil; else v_4876 = lisp_true; }}
#endif
    if (v_4876 == nil) goto v_4727;
    goto v_4735;
v_4731:
    v_4876 = stack[-2];
    fn = elt(env, 3); // lnc
    v_4877 = (*qfn1(fn))(fn, v_4876);
    env = stack[-4];
    stack[-3] = v_4877;
    goto v_4732;
v_4733:
    v_4876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    v_4876 = Lneq(nil, v_4877, v_4876);
    env = stack[-4];
    goto v_4725;
v_4727:
    v_4876 = nil;
    goto v_4725;
    v_4876 = nil;
v_4725:
    if (v_4876 == nil) goto v_4723;
    goto v_4747;
v_4743:
    v_4876 = stack[-3];
    fn = elt(env, 4); // !:recip
    v_4877 = (*qfn1(fn))(fn, v_4876);
    env = stack[-4];
    goto v_4744;
v_4745:
    v_4876 = stack[-2];
    goto v_4746;
v_4747:
    goto v_4743;
v_4744:
    goto v_4745;
v_4746:
    fn = elt(env, 5); // multd
    v_4876 = (*qfn2(fn))(fn, v_4877, v_4876);
    env = stack[-4];
    stack[-2] = v_4876;
    goto v_4721;
v_4723:
v_4721:
    v_4876 = stack[-2];
    v_4876 = qcdr(v_4876);
    if (v_4876 == nil) goto v_4753;
    else goto v_4754;
v_4753:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    goto v_4717;
v_4754:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4876 = qcdr(v_4876);
    stack[-3] = v_4876;
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4876 = qcar(v_4876);
    v_4876 = qcar(v_4876);
    stack[-1] = v_4876;
v_4718:
    v_4876 = stack[-2];
    v_4876 = qcdr(v_4876);
    stack[-2] = v_4876;
    goto v_4776;
v_4772:
    goto v_4782;
v_4778:
    v_4877 = stack[-2];
    goto v_4779;
v_4780:
    v_4876 = stack[-1];
    goto v_4781;
v_4782:
    goto v_4778;
v_4779:
    goto v_4780;
v_4781:
    fn = elt(env, 6); // degr
    v_4877 = (*qfn2(fn))(fn, v_4877, v_4876);
    env = stack[-4];
    goto v_4773;
v_4774:
    v_4876 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4775;
v_4776:
    goto v_4772;
v_4773:
    goto v_4774;
v_4775:
    if (v_4877 == v_4876) goto v_4770;
    else goto v_4771;
v_4770:
    goto v_4791;
v_4787:
    stack[0] = nil;
    goto v_4788;
v_4789:
    v_4876 = stack[-2];
    if (!consp(v_4876)) goto v_4803;
    else goto v_4804;
v_4803:
    v_4876 = lisp_true;
    goto v_4802;
v_4804:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4876 = (consp(v_4876) ? nil : lisp_true);
    goto v_4802;
    v_4876 = nil;
v_4802:
    if (v_4876 == nil) goto v_4800;
    v_4876 = lisp_true;
    goto v_4798;
v_4800:
    v_4876 = stack[-1];
    fn = elt(env, 7); // noncomp
    v_4876 = (*qfn1(fn))(fn, v_4876);
    env = stack[-4];
    if (v_4876 == nil) goto v_4817;
    else goto v_4818;
v_4817:
    v_4876 = nil;
    goto v_4816;
v_4818:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4876 = qcar(v_4876);
    v_4876 = qcar(v_4876);
    fn = elt(env, 7); // noncomp
    v_4876 = (*qfn1(fn))(fn, v_4876);
    env = stack[-4];
    goto v_4816;
    v_4876 = nil;
v_4816:
    v_4876 = (v_4876 == nil ? lisp_true : nil);
    goto v_4798;
    v_4876 = nil;
v_4798:
    if (v_4876 == nil) goto v_4796;
    goto v_4835;
v_4831:
    v_4877 = stack[-3];
    goto v_4832;
v_4833:
    v_4876 = stack[-2];
    goto v_4834;
v_4835:
    goto v_4831;
v_4832:
    goto v_4833;
v_4834:
    fn = elt(env, 8); // gcdf
    v_4876 = (*qfn2(fn))(fn, v_4877, v_4876);
    goto v_4794;
v_4796:
    v_4876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4794;
    v_4876 = nil;
v_4794:
    goto v_4790;
v_4791:
    goto v_4787;
v_4788:
    goto v_4789;
v_4790:
    {
        LispObject v_4882 = stack[0];
        return cons(v_4882, v_4876);
    }
v_4771:
    v_4876 = stack[-2];
    v_4876 = qcdr(v_4876);
    if (v_4876 == nil) goto v_4841;
    else goto v_4842;
v_4841:
    goto v_4850;
v_4846:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    stack[0] = qcar(v_4876);
    goto v_4847;
v_4848:
    goto v_4859;
v_4855:
    v_4877 = stack[-3];
    goto v_4856;
v_4857:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4876 = qcdr(v_4876);
    goto v_4858;
v_4859:
    goto v_4855;
v_4856:
    goto v_4857;
v_4858:
    fn = elt(env, 8); // gcdf
    v_4876 = (*qfn2(fn))(fn, v_4877, v_4876);
    goto v_4849;
v_4850:
    goto v_4846;
v_4847:
    goto v_4848;
v_4849:
    {
        LispObject v_4883 = stack[0];
        return cons(v_4883, v_4876);
    }
v_4842:
    goto v_4871;
v_4867:
    v_4876 = stack[-2];
    v_4876 = qcar(v_4876);
    v_4877 = qcdr(v_4876);
    goto v_4868;
v_4869:
    v_4876 = stack[-3];
    goto v_4870;
v_4871:
    goto v_4867;
v_4868:
    goto v_4869;
v_4870:
    fn = elt(env, 8); // gcdf
    v_4876 = (*qfn2(fn))(fn, v_4877, v_4876);
    env = stack[-4];
    stack[-3] = v_4876;
    goto v_4769;
v_4769:
    goto v_4718;
v_4717:
    return onevalue(v_4876);
}



// Code for freevarinexptchk

static LispObject CC_freevarinexptchk(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4753;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
v_4711:
    v_4753 = stack[0];
    if (!consp(v_4753)) goto v_4720;
    else goto v_4721;
v_4720:
    v_4753 = lisp_true;
    goto v_4719;
v_4721:
    v_4753 = stack[0];
    v_4753 = qcar(v_4753);
    v_4753 = (consp(v_4753) ? nil : lisp_true);
    goto v_4719;
    v_4753 = nil;
v_4719:
    if (v_4753 == nil) goto v_4716;
    else goto v_4717;
v_4716:
    v_4753 = stack[0];
    v_4753 = qcar(v_4753);
    v_4753 = qcar(v_4753);
    v_4753 = qcdr(v_4753);
    if (is_number(v_4753)) goto v_4732;
    v_4753 = lisp_true;
    goto v_4730;
v_4732:
    v_4753 = stack[0];
    v_4753 = qcar(v_4753);
    v_4753 = qcdr(v_4753);
    v_4753 = CC_freevarinexptchk(elt(env, 0), v_4753);
    env = stack[-1];
    if (v_4753 == nil) goto v_4742;
    else goto v_4741;
v_4742:
    v_4753 = stack[0];
    v_4753 = qcdr(v_4753);
    stack[0] = v_4753;
    goto v_4711;
v_4741:
    goto v_4730;
    v_4753 = nil;
v_4730:
    goto v_4715;
v_4717:
    v_4753 = nil;
    goto v_4715;
    v_4753 = nil;
v_4715:
    return onevalue(v_4753);
}



// Code for talp_simplat2

static LispObject CC_talp_simplat2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4775, v_4776, v_4777;
    LispObject fn;
    LispObject v_4714, v_4713, v_4712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplat2");
    va_start(aa, nargs);
    v_4712 = va_arg(aa, LispObject);
    v_4713 = va_arg(aa, LispObject);
    v_4714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4714,v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4712,v_4713,v_4714);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4714;
    stack[-1] = v_4713;
    stack[-2] = v_4712;
// end of prologue
    v_4775 = stack[0];
    fn = elt(env, 1); // talp_invp
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    if (v_4775 == nil) goto v_4719;
    goto v_4729;
v_4723:
    v_4777 = stack[-2];
    goto v_4724;
v_4725:
    v_4776 = stack[-1];
    goto v_4726;
v_4727:
    v_4775 = stack[0];
    goto v_4728;
v_4729:
    goto v_4723;
v_4724:
    goto v_4725;
v_4726:
    goto v_4727;
v_4728:
    {
        fn = elt(env, 2); // talp_simplatrinv
        return (*qfnn(fn))(fn, 3, v_4777, v_4776, v_4775);
    }
v_4719:
    v_4775 = stack[-1];
    if (!consp(v_4775)) goto v_4733;
    else goto v_4734;
v_4733:
    goto v_4743;
v_4737:
    v_4777 = stack[-2];
    goto v_4738;
v_4739:
    v_4776 = stack[-1];
    goto v_4740;
v_4741:
    v_4775 = stack[0];
    goto v_4742;
v_4743:
    goto v_4737;
v_4738:
    goto v_4739;
v_4740:
    goto v_4741;
v_4742:
    {
        fn = elt(env, 3); // talp_simplatat
        return (*qfnn(fn))(fn, 3, v_4777, v_4776, v_4775);
    }
v_4734:
    v_4775 = stack[-1];
    fn = elt(env, 1); // talp_invp
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    if (v_4775 == nil) goto v_4748;
    goto v_4758;
v_4752:
    v_4777 = stack[-2];
    goto v_4753;
v_4754:
    v_4776 = stack[-1];
    goto v_4755;
v_4756:
    v_4775 = stack[0];
    goto v_4757;
v_4758:
    goto v_4752;
v_4753:
    goto v_4754;
v_4755:
    goto v_4756;
v_4757:
    {
        fn = elt(env, 4); // talp_simplatlinv
        return (*qfnn(fn))(fn, 3, v_4777, v_4776, v_4775);
    }
v_4748:
    goto v_4771;
v_4765:
    v_4777 = stack[-2];
    goto v_4766;
v_4767:
    v_4776 = stack[-1];
    goto v_4768;
v_4769:
    v_4775 = stack[0];
    goto v_4770;
v_4771:
    goto v_4765;
v_4766:
    goto v_4767;
v_4768:
    goto v_4769;
v_4770:
    {
        fn = elt(env, 5); // talp_simplatfn
        return (*qfnn(fn))(fn, 3, v_4777, v_4776, v_4775);
    }
    v_4775 = nil;
    return onevalue(v_4775);
}



// Code for searchtm

static LispObject CC_searchtm(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4744, v_4745;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4745 = v_4712;
// end of prologue
    v_4744 = v_4745;
    if (!consp(v_4744)) goto v_4720;
    else goto v_4721;
v_4720:
    v_4744 = lisp_true;
    goto v_4719;
v_4721:
    v_4744 = v_4745;
    v_4744 = qcar(v_4744);
    v_4744 = (consp(v_4744) ? nil : lisp_true);
    goto v_4719;
    v_4744 = nil;
v_4719:
    if (v_4744 == nil) goto v_4717;
    v_4744 = nil;
    goto v_4715;
v_4717:
    goto v_4737;
v_4733:
    v_4744 = v_4745;
    v_4744 = qcar(v_4744);
    stack[0] = qcar(v_4744);
    goto v_4734;
v_4735:
    v_4744 = v_4745;
    v_4744 = qcdr(v_4744);
    fn = elt(env, 1); // searchpl
    v_4744 = (*qfn1(fn))(fn, v_4744);
    goto v_4736;
v_4737:
    goto v_4733;
v_4734:
    goto v_4735;
v_4736:
    {
        LispObject v_4747 = stack[0];
        return cons(v_4747, v_4744);
    }
    v_4744 = nil;
v_4715:
    return onevalue(v_4744);
}



// Code for quotk

static LispObject CC_quotk(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4784, v_4785, v_4786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    goto v_4720;
v_4716:
    v_4784 = stack[-1];
    v_4784 = qcar(v_4784);
    v_4785 = qcdr(v_4784);
    goto v_4717;
v_4718:
    v_4784 = stack[0];
    goto v_4719;
v_4720:
    goto v_4716;
v_4717:
    goto v_4718;
v_4719:
    fn = elt(env, 1); // quotf1
    v_4784 = (*qfn2(fn))(fn, v_4785, v_4784);
    env = stack[-3];
    stack[-2] = v_4784;
    v_4784 = stack[-2];
    if (v_4784 == nil) goto v_4729;
    v_4784 = stack[-1];
    v_4784 = qcdr(v_4784);
    if (v_4784 == nil) goto v_4733;
    else goto v_4734;
v_4733:
    goto v_4743;
v_4739:
    v_4784 = stack[-1];
    v_4784 = qcar(v_4784);
    v_4785 = qcar(v_4784);
    goto v_4740;
v_4741:
    v_4784 = stack[-2];
    goto v_4742;
v_4743:
    goto v_4739;
v_4740:
    goto v_4741;
v_4742:
    v_4784 = cons(v_4785, v_4784);
    return ncons(v_4784);
v_4734:
    goto v_4755;
v_4751:
    v_4784 = stack[-1];
    v_4785 = qcdr(v_4784);
    goto v_4752;
v_4753:
    v_4784 = stack[0];
    goto v_4754;
v_4755:
    goto v_4751;
v_4752:
    goto v_4753;
v_4754:
    fn = elt(env, 1); // quotf1
    v_4784 = (*qfn2(fn))(fn, v_4785, v_4784);
    v_4785 = v_4784;
    if (v_4785 == nil) goto v_4763;
    goto v_4772;
v_4766:
    v_4785 = stack[-1];
    v_4785 = qcar(v_4785);
    v_4786 = qcar(v_4785);
    goto v_4767;
v_4768:
    v_4785 = stack[-2];
    goto v_4769;
v_4770:
    goto v_4771;
v_4772:
    goto v_4766;
v_4767:
    goto v_4768;
v_4769:
    goto v_4770;
v_4771:
    return acons(v_4786, v_4785, v_4784);
v_4763:
    v_4784 = nil;
    goto v_4761;
    v_4784 = nil;
v_4761:
    goto v_4732;
    v_4784 = nil;
v_4732:
    goto v_4727;
v_4729:
    v_4784 = nil;
    goto v_4727;
    v_4784 = nil;
v_4727:
    return onevalue(v_4784);
}



// Code for isarb_compl

static LispObject CC_isarb_compl(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4742, v_4743, v_4744;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4743 = v_4712;
// end of prologue
    v_4742 = v_4743;
    v_4742 = Lconsp(nil, v_4742);
    env = stack[0];
    if (v_4742 == nil) goto v_4720;
    goto v_4731;
v_4727:
    v_4742 = v_4743;
    v_4744 = qcar(v_4742);
    goto v_4728;
v_4729:
    v_4742 = elt(env, 1); // arbcomplex
    goto v_4730;
v_4731:
    goto v_4727;
v_4728:
    goto v_4729;
v_4730:
    if (v_4744 == v_4742) goto v_4725;
    else goto v_4726;
v_4725:
    v_4742 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 2)) = v_4742; // found_compl
    goto v_4724;
v_4726:
    v_4742 = v_4743;
    v_4742 = qcdr(v_4742);
    fn = elt(env, 3); // multi_isarb_compl
    v_4742 = (*qfn1(fn))(fn, v_4742);
    goto v_4724;
v_4724:
    goto v_4718;
v_4720:
v_4718:
    v_4742 = nil;
    return onevalue(v_4742);
}



// Code for equal!:

static LispObject CC_equalT(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4765, v_4766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    v_4765 = stack[-1];
    v_4765 = qcdr(v_4765);
    v_4765 = qcar(v_4765);
    v_4765 = (LispObject)zerop(v_4765);
    v_4765 = v_4765 ? lisp_true : nil;
    env = stack[-3];
    if (v_4765 == nil) goto v_4720;
    else goto v_4721;
v_4720:
    v_4765 = nil;
    goto v_4719;
v_4721:
    v_4765 = stack[0];
    v_4765 = qcdr(v_4765);
    v_4765 = qcar(v_4765);
    v_4765 = (LispObject)zerop(v_4765);
    v_4765 = v_4765 ? lisp_true : nil;
    env = stack[-3];
    goto v_4719;
    v_4765 = nil;
v_4719:
    if (v_4765 == nil) goto v_4717;
    else goto v_4716;
v_4717:
    goto v_4741;
v_4737:
    v_4765 = stack[-1];
    fn = elt(env, 1); // normbf
    v_4765 = (*qfn1(fn))(fn, v_4765);
    env = stack[-3];
    stack[-1] = v_4765;
    v_4765 = qcdr(v_4765);
    stack[-2] = qcdr(v_4765);
    goto v_4738;
v_4739:
    v_4765 = stack[0];
    fn = elt(env, 1); // normbf
    v_4765 = (*qfn1(fn))(fn, v_4765);
    stack[0] = v_4765;
    v_4765 = qcdr(v_4765);
    v_4765 = qcdr(v_4765);
    goto v_4740;
v_4741:
    goto v_4737;
v_4738:
    goto v_4739;
v_4740:
    if (equal(stack[-2], v_4765)) goto v_4735;
    else goto v_4736;
v_4735:
    goto v_4754;
v_4750:
    v_4765 = stack[-1];
    v_4765 = qcdr(v_4765);
    v_4766 = qcar(v_4765);
    goto v_4751;
v_4752:
    v_4765 = stack[0];
    v_4765 = qcdr(v_4765);
    v_4765 = qcar(v_4765);
    goto v_4753;
v_4754:
    goto v_4750;
v_4751:
    goto v_4752;
v_4753:
    v_4765 = (equal(v_4766, v_4765) ? lisp_true : nil);
    goto v_4734;
v_4736:
    v_4765 = nil;
    goto v_4734;
    v_4765 = nil;
v_4734:
v_4716:
    return onevalue(v_4765);
}



// Code for simpindexvar

static LispObject CC_simpindexvar(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4717 = v_4712;
// end of prologue
    fn = elt(env, 1); // partitindexvar
    v_4717 = (*qfn1(fn))(fn, v_4717);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_4717);
    }
}



// Code for sfpx

static LispObject CC_sfpx(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4731, v_4732, v_4733, v_4734, v_4735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4731 = v_4712;
// end of prologue
    goto v_4725;
v_4715:
    v_4735 = v_4731;
    goto v_4716;
v_4717:
    v_4734 = nil;
    goto v_4718;
v_4719:
    v_4733 = nil;
    goto v_4720;
v_4721:
    v_4732 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4722;
v_4723:
    v_4731 = lisp_true;
    goto v_4724;
v_4725:
    goto v_4715;
v_4716:
    goto v_4717;
v_4718:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    goto v_4723;
v_4724:
    {
        fn = elt(env, 1); // sfpx1
        return (*qfnn(fn))(fn, 5, v_4735, v_4734, v_4733, v_4732, v_4731);
    }
}



// Code for kernp

static LispObject CC_kernp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4786, v_4787, v_4788;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4787 = v_4712;
// end of prologue
    goto v_4722;
v_4718:
    v_4786 = v_4787;
    v_4788 = qcdr(v_4786);
    goto v_4719;
v_4720:
    v_4786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4721;
v_4722:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    if (v_4788 == v_4786) goto v_4716;
    else goto v_4717;
v_4716:
    v_4786 = v_4787;
    v_4786 = qcar(v_4786);
    v_4787 = v_4786;
    v_4788 = v_4786;
    v_4786 = v_4788;
    if (!consp(v_4786)) goto v_4735;
    else goto v_4736;
v_4735:
    v_4786 = lisp_true;
    goto v_4734;
v_4736:
    v_4786 = v_4788;
    v_4786 = qcar(v_4786);
    v_4786 = (consp(v_4786) ? nil : lisp_true);
    goto v_4734;
    v_4786 = nil;
v_4734:
    if (v_4786 == nil) goto v_4728;
    else goto v_4729;
v_4728:
    v_4786 = v_4787;
    v_4786 = qcdr(v_4786);
    if (v_4786 == nil) goto v_4746;
    else goto v_4747;
v_4746:
    goto v_4758;
v_4754:
    v_4786 = v_4787;
    v_4786 = qcar(v_4786);
    v_4788 = qcdr(v_4786);
    goto v_4755;
v_4756:
    v_4786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4757;
v_4758:
    goto v_4754;
v_4755:
    goto v_4756;
v_4757:
    if (v_4788 == v_4786) goto v_4752;
    else goto v_4753;
v_4752:
    goto v_4767;
v_4763:
    v_4786 = v_4787;
    v_4786 = qcar(v_4786);
    v_4786 = qcar(v_4786);
    v_4787 = qcdr(v_4786);
    goto v_4764;
v_4765:
    v_4786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4766;
v_4767:
    goto v_4763;
v_4764:
    goto v_4765;
v_4766:
    v_4786 = (v_4787 == v_4786 ? lisp_true : nil);
    goto v_4751;
v_4753:
    v_4786 = nil;
    goto v_4751;
    v_4786 = nil;
v_4751:
    goto v_4745;
v_4747:
    v_4786 = nil;
    goto v_4745;
    v_4786 = nil;
v_4745:
    goto v_4727;
v_4729:
    v_4786 = nil;
    goto v_4727;
    v_4786 = nil;
v_4727:
    goto v_4715;
v_4717:
    v_4786 = nil;
    goto v_4715;
    v_4786 = nil;
v_4715:
    return onevalue(v_4786);
}



// Code for exptf1

static LispObject CC_exptf1(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4760, v_4761;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    goto v_4723;
v_4719:
    v_4761 = stack[0];
    goto v_4720;
v_4721:
    v_4760 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4722;
v_4723:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    if (v_4761 == v_4760) goto v_4717;
    else goto v_4718;
v_4717:
    v_4760 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4716;
v_4718:
    v_4760 = stack[-1];
    stack[-2] = v_4760;
v_4736:
    goto v_4746;
v_4742:
    v_4760 = stack[0];
    v_4761 = sub1(v_4760);
    env = stack[-3];
    stack[0] = v_4761;
    goto v_4743;
v_4744:
    v_4760 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4745;
v_4746:
    goto v_4742;
v_4743:
    goto v_4744;
v_4745:
    v_4760 = (LispObject)greaterp2(v_4761, v_4760);
    v_4760 = v_4760 ? lisp_true : nil;
    env = stack[-3];
    if (v_4760 == nil) goto v_4739;
    else goto v_4740;
v_4739:
    goto v_4735;
v_4740:
    goto v_4756;
v_4752:
    v_4761 = stack[-1];
    goto v_4753;
v_4754:
    v_4760 = stack[-2];
    goto v_4755;
v_4756:
    goto v_4752;
v_4753:
    goto v_4754;
v_4755:
    fn = elt(env, 2); // multf
    v_4760 = (*qfn2(fn))(fn, v_4761, v_4760);
    env = stack[-3];
    stack[-2] = v_4760;
    goto v_4736;
v_4735:
    v_4760 = stack[-2];
    goto v_4716;
    v_4760 = nil;
v_4716:
    return onevalue(v_4760);
}



// Code for aex_simpleratp

static LispObject CC_aex_simpleratp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4742, v_4743;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_4742 = v_4712;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_4742 = (*qfn1(fn))(fn, v_4742);
    env = stack[-1];
    stack[0] = v_4742;
    v_4742 = stack[0];
    v_4742 = qcar(v_4742);
    if (is_number(v_4742)) goto v_4723;
    v_4742 = nil;
    goto v_4721;
v_4723:
    goto v_4734;
v_4730:
    v_4742 = stack[0];
    v_4743 = qcar(v_4742);
    goto v_4731;
v_4732:
    v_4742 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4733;
v_4734:
    goto v_4730;
v_4731:
    goto v_4732;
v_4733:
    v_4742 = Leqn(nil, v_4743, v_4742);
    v_4742 = (v_4742 == nil ? lisp_true : nil);
    goto v_4721;
    v_4742 = nil;
v_4721:
    if (v_4742 == nil) goto v_4719;
    else goto v_4718;
v_4719:
    v_4742 = stack[0];
    v_4742 = qcar(v_4742);
    v_4742 = (v_4742 == nil ? lisp_true : nil);
v_4718:
    return onevalue(v_4742);
}



// Code for wuorderp

static LispObject CC_wuorderp(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4829, v_4830, v_4831, v_4832, v_4833, v_4834;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
// copy arguments values to proper place
    v_4833 = v_4713;
    v_4834 = v_4712;
// end of prologue
    v_4831 = nil;
    goto v_4728;
v_4724:
    v_4830 = v_4834;
    goto v_4725;
v_4726:
    v_4829 = v_4833;
    goto v_4727;
v_4728:
    goto v_4724;
v_4725:
    goto v_4726;
v_4727:
    if (v_4830 == v_4829) goto v_4722;
    else goto v_4723;
v_4722:
    v_4829 = nil;
    goto v_4718;
v_4723:
    v_4829 = qvalue(elt(env, 2)); // wukord!*
    v_4832 = v_4829;
v_4735:
    v_4829 = v_4832;
    if (v_4829 == nil) goto v_4738;
    v_4829 = v_4831;
    if (v_4829 == nil) goto v_4742;
    else goto v_4738;
v_4742:
    goto v_4739;
v_4738:
    goto v_4734;
v_4739:
    goto v_4753;
v_4749:
    v_4830 = v_4834;
    goto v_4750;
v_4751:
    v_4829 = v_4832;
    v_4829 = qcar(v_4829);
    goto v_4752;
v_4753:
    goto v_4749;
v_4750:
    goto v_4751;
v_4752:
    if (v_4830 == v_4829) goto v_4747;
    else goto v_4748;
v_4747:
    goto v_4765;
v_4761:
    v_4830 = v_4833;
    goto v_4762;
v_4763:
    v_4829 = v_4832;
    v_4829 = qcdr(v_4829);
    goto v_4764;
v_4765:
    goto v_4761;
v_4762:
    goto v_4763;
v_4764:
    v_4829 = Lmemq(nil, v_4830, v_4829);
    if (v_4829 == nil) goto v_4760;
    v_4829 = elt(env, 3); // yes
    goto v_4758;
v_4760:
    v_4829 = elt(env, 4); // no
    goto v_4758;
    v_4829 = nil;
v_4758:
    v_4831 = v_4829;
    goto v_4746;
v_4748:
    goto v_4780;
v_4776:
    v_4830 = v_4833;
    goto v_4777;
v_4778:
    v_4829 = v_4832;
    v_4829 = qcar(v_4829);
    goto v_4779;
v_4780:
    goto v_4776;
v_4777:
    goto v_4778;
v_4779:
    if (v_4830 == v_4829) goto v_4774;
    else goto v_4775;
v_4774:
    goto v_4792;
v_4788:
    v_4830 = v_4834;
    goto v_4789;
v_4790:
    v_4829 = v_4832;
    v_4829 = qcdr(v_4829);
    goto v_4791;
v_4792:
    goto v_4788;
v_4789:
    goto v_4790;
v_4791:
    v_4829 = Lmemq(nil, v_4830, v_4829);
    if (v_4829 == nil) goto v_4787;
    v_4829 = elt(env, 4); // no
    goto v_4785;
v_4787:
    v_4829 = elt(env, 3); // yes
    goto v_4785;
    v_4829 = nil;
v_4785:
    v_4831 = v_4829;
    goto v_4746;
v_4775:
    v_4829 = v_4832;
    v_4829 = qcdr(v_4829);
    v_4832 = v_4829;
    goto v_4746;
v_4746:
    goto v_4735;
v_4734:
    v_4829 = v_4831;
    if (v_4829 == nil) goto v_4808;
    goto v_4814;
v_4810:
    v_4829 = v_4831;
    goto v_4811;
v_4812:
    v_4830 = elt(env, 3); // yes
    goto v_4813;
v_4814:
    goto v_4810;
v_4811:
    goto v_4812;
v_4813:
    v_4829 = (v_4829 == v_4830 ? lisp_true : nil);
    goto v_4806;
v_4808:
    goto v_4825;
v_4821:
    v_4829 = v_4834;
    goto v_4822;
v_4823:
    v_4830 = v_4833;
    goto v_4824;
v_4825:
    goto v_4821;
v_4822:
    goto v_4823;
v_4824:
    v_4829 = Lorderp(nil, v_4829, v_4830);
    v_4829 = (v_4829 == nil ? lisp_true : nil);
    goto v_4806;
    v_4829 = nil;
v_4806:
v_4718:
    return onevalue(v_4829);
}



// Code for talp_ordatp

static LispObject CC_talp_ordatp(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4775, v_4776;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    v_4775 = stack[-1];
    fn = elt(env, 3); // talp_simpat
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    stack[-1] = v_4775;
    v_4775 = stack[0];
    fn = elt(env, 3); // talp_simpat
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    stack[0] = v_4775;
    v_4775 = stack[-1];
    fn = elt(env, 4); // talp_arg2l
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    stack[-2] = v_4775;
    v_4775 = stack[0];
    fn = elt(env, 4); // talp_arg2l
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4736;
v_4732:
    v_4776 = stack[-2];
    goto v_4733;
v_4734:
    goto v_4735;
v_4736:
    goto v_4732;
v_4733:
    goto v_4734;
v_4735:
    if (equal(v_4776, v_4775)) goto v_4731;
    goto v_4744;
v_4740:
    v_4775 = stack[-1];
    fn = elt(env, 4); // talp_arg2l
    stack[-1] = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4741;
v_4742:
    v_4775 = stack[0];
    fn = elt(env, 4); // talp_arg2l
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4743;
v_4744:
    goto v_4740;
v_4741:
    goto v_4742;
v_4743:
    {
        LispObject v_4780 = stack[-1];
        fn = elt(env, 5); // talp_tordp
        return (*qfn2(fn))(fn, v_4780, v_4775);
    }
v_4731:
    v_4775 = stack[-1];
    fn = elt(env, 6); // talp_arg2r
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    stack[-2] = v_4775;
    v_4775 = stack[0];
    fn = elt(env, 6); // talp_arg2r
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4761;
v_4757:
    v_4776 = stack[-2];
    goto v_4758;
v_4759:
    goto v_4760;
v_4761:
    goto v_4757;
v_4758:
    goto v_4759;
v_4760:
    if (equal(v_4776, v_4775)) goto v_4756;
    goto v_4769;
v_4765:
    v_4775 = stack[-1];
    fn = elt(env, 6); // talp_arg2r
    stack[-1] = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4766;
v_4767:
    v_4775 = stack[0];
    fn = elt(env, 6); // talp_arg2r
    v_4775 = (*qfn1(fn))(fn, v_4775);
    env = stack[-3];
    goto v_4768;
v_4769:
    goto v_4765;
v_4766:
    goto v_4767;
v_4768:
    {
        LispObject v_4781 = stack[-1];
        fn = elt(env, 5); // talp_tordp
        return (*qfn2(fn))(fn, v_4781, v_4775);
    }
v_4756:
    v_4775 = elt(env, 2); // true
    return onevalue(v_4775);
}



// Code for ibalp_varlt1

static LispObject CC_ibalp_varlt1(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4784, v_4785, v_4786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4713;
    v_4786 = v_4712;
// end of prologue
    goto v_4730;
v_4726:
    v_4785 = v_4786;
    goto v_4727;
v_4728:
    v_4784 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4729;
v_4730:
    goto v_4726;
v_4727:
    goto v_4728;
v_4729:
    if (v_4785 == v_4784) goto v_4724;
    else goto v_4725;
v_4724:
    v_4784 = lisp_true;
    goto v_4723;
v_4725:
    goto v_4740;
v_4736:
    v_4785 = v_4786;
    goto v_4737;
v_4738:
    v_4784 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4739;
v_4740:
    goto v_4736;
v_4737:
    goto v_4738;
v_4739:
    v_4784 = (v_4785 == v_4784 ? lisp_true : nil);
    goto v_4723;
    v_4784 = nil;
v_4723:
    if (v_4784 == nil) goto v_4721;
    v_4784 = nil;
    goto v_4716;
v_4721:
    v_4784 = v_4786;
    if (symbolp(v_4784)) goto v_4747;
    else goto v_4748;
v_4747:
    goto v_4755;
v_4751:
    v_4785 = v_4786;
    goto v_4752;
v_4753:
    v_4784 = stack[0];
    goto v_4754;
v_4755:
    goto v_4751;
v_4752:
    goto v_4753;
v_4754:
    {
        fn = elt(env, 1); // lto_insertq
        return (*qfn2(fn))(fn, v_4785, v_4784);
    }
v_4748:
    v_4784 = v_4786;
    fn = elt(env, 2); // ibalp_argn
    v_4784 = (*qfn1(fn))(fn, v_4784);
    env = stack[-2];
    stack[-1] = v_4784;
v_4761:
    v_4784 = stack[-1];
    if (v_4784 == nil) goto v_4766;
    else goto v_4767;
v_4766:
    goto v_4760;
v_4767:
    v_4784 = stack[-1];
    v_4784 = qcar(v_4784);
    goto v_4778;
v_4774:
    v_4785 = v_4784;
    goto v_4775;
v_4776:
    v_4784 = stack[0];
    goto v_4777;
v_4778:
    goto v_4774;
v_4775:
    goto v_4776;
v_4777:
    v_4784 = CC_ibalp_varlt1(elt(env, 0), v_4785, v_4784);
    env = stack[-2];
    stack[0] = v_4784;
    v_4784 = stack[-1];
    v_4784 = qcdr(v_4784);
    stack[-1] = v_4784;
    goto v_4761;
v_4760:
    v_4784 = stack[0];
v_4716:
    return onevalue(v_4784);
}



// Code for multiom

static LispObject CC_multiom(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4741, v_4742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    goto v_4725;
v_4721:
    v_4741 = stack[0];
    v_4742 = Llength(nil, v_4741);
    env = stack[-1];
    goto v_4722;
v_4723:
    v_4741 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4724;
v_4725:
    goto v_4721;
v_4722:
    goto v_4723;
v_4724:
    if (v_4742 == v_4741) goto v_4719;
    else goto v_4720;
v_4719:
    v_4741 = stack[0];
    v_4741 = qcar(v_4741);
    fn = elt(env, 1); // objectom
    v_4741 = (*qfn1(fn))(fn, v_4741);
    goto v_4718;
v_4720:
    v_4741 = stack[0];
    v_4741 = qcar(v_4741);
    fn = elt(env, 1); // objectom
    v_4741 = (*qfn1(fn))(fn, v_4741);
    env = stack[-1];
    v_4741 = stack[0];
    v_4741 = qcdr(v_4741);
    v_4741 = CC_multiom(elt(env, 0), v_4741);
    goto v_4718;
v_4718:
    v_4741 = nil;
    return onevalue(v_4741);
}



// Code for symtabget

static LispObject CC_symtabget(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4761, v_4762, v_4763, v_4764;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4763 = v_4713;
    v_4762 = v_4712;
// end of prologue
    v_4761 = v_4763;
    if (v_4761 == nil) goto v_4718;
    v_4761 = v_4762;
    if (v_4761 == nil) goto v_4722;
    else goto v_4721;
v_4722:
    v_4761 = qvalue(elt(env, 1)); // !*symboltable!*
    v_4761 = qcar(v_4761);
v_4721:
    v_4762 = v_4761;
    goto v_4716;
v_4718:
v_4716:
    v_4761 = v_4762;
    if (v_4761 == nil) goto v_4728;
    else goto v_4729;
v_4728:
    v_4761 = qvalue(elt(env, 1)); // !*symboltable!*
    goto v_4727;
v_4729:
    goto v_4738;
v_4734:
    v_4761 = v_4763;
    goto v_4735;
v_4736:
    v_4764 = elt(env, 2); // (!*type!* !*params!* !*decs!*)
    goto v_4737;
v_4738:
    goto v_4734;
v_4735:
    goto v_4736;
v_4737:
    v_4761 = Lmemq(nil, v_4761, v_4764);
    if (v_4761 == nil) goto v_4733;
    goto v_4747;
v_4743:
    v_4761 = v_4762;
    goto v_4744;
v_4745:
    v_4762 = v_4763;
    goto v_4746;
v_4747:
    goto v_4743;
v_4744:
    goto v_4745;
v_4746:
    return get(v_4761, v_4762);
v_4733:
    goto v_4756;
v_4752:
    v_4761 = v_4763;
    goto v_4753;
v_4754:
    if (!symbolp(v_4762)) v_4762 = nil;
    else { v_4762 = qfastgets(v_4762);
           if (v_4762 != nil) { v_4762 = elt(v_4762, 58); // !*decs!*
#ifdef RECORD_GET
             if (v_4762 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v_4762 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v_4762 == SPID_NOPROP) v_4762 = nil; }}
#endif
    goto v_4755;
v_4756:
    goto v_4752;
v_4753:
    goto v_4754;
v_4755:
    v_4761 = Lassoc(nil, v_4761, v_4762);
    goto v_4727;
    v_4761 = nil;
v_4727:
    return onevalue(v_4761);
}



// Code for covposp

static LispObject CC_covposp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4734, v_4735;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4734 = v_4712;
// end of prologue
v_4711:
    v_4735 = v_4734;
    if (v_4735 == nil) goto v_4716;
    else goto v_4717;
v_4716:
    v_4734 = lisp_true;
    goto v_4715;
v_4717:
    v_4735 = v_4734;
    v_4735 = qcar(v_4735);
    if (!consp(v_4735)) goto v_4725;
    v_4734 = qcdr(v_4734);
    goto v_4711;
v_4725:
    v_4734 = nil;
    goto v_4723;
    v_4734 = nil;
v_4723:
    goto v_4715;
    v_4734 = nil;
v_4715:
    return onevalue(v_4734);
}



// Code for take!-realpart

static LispObject CC_takeKrealpart(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4739, v_4740;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    goto v_4719;
v_4715:
    goto v_4725;
v_4721:
    v_4739 = stack[0];
    v_4739 = qcar(v_4739);
    fn = elt(env, 1); // repartf
    v_4740 = (*qfn1(fn))(fn, v_4739);
    env = stack[-2];
    goto v_4722;
v_4723:
    v_4739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4724;
v_4725:
    goto v_4721;
v_4722:
    goto v_4723;
v_4724:
    stack[-1] = cons(v_4740, v_4739);
    env = stack[-2];
    goto v_4716;
v_4717:
    goto v_4735;
v_4731:
    v_4740 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4732;
v_4733:
    v_4739 = stack[0];
    v_4739 = qcdr(v_4739);
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    v_4739 = cons(v_4740, v_4739);
    env = stack[-2];
    goto v_4718;
v_4719:
    goto v_4715;
v_4716:
    goto v_4717;
v_4718:
    {
        LispObject v_4743 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_4743, v_4739);
    }
}



// Code for add2inputbuf

static LispObject CC_add2inputbuf(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4750, v_4751, v_4752;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    fn = elt(env, 4); // terminalp
    v_4750 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_4750 == nil) goto v_4724;
    else goto v_4725;
v_4724:
    v_4750 = lisp_true;
    goto v_4723;
v_4725:
    v_4750 = qvalue(elt(env, 1)); // !*nosave!*
    goto v_4723;
    v_4750 = nil;
v_4723:
    if (v_4750 == nil) goto v_4721;
    v_4750 = nil;
    goto v_4716;
v_4721:
    goto v_4737;
v_4733:
    goto v_4745;
v_4739:
    v_4752 = qvalue(elt(env, 2)); // statcounter
    goto v_4740;
v_4741:
    v_4751 = stack[0];
    goto v_4742;
v_4743:
    v_4750 = stack[-1];
    goto v_4744;
v_4745:
    goto v_4739;
v_4740:
    goto v_4741;
v_4742:
    goto v_4743;
v_4744:
    v_4751 = list3(v_4752, v_4751, v_4750);
    env = stack[-2];
    goto v_4734;
v_4735:
    v_4750 = qvalue(elt(env, 3)); // inputbuflis!*
    goto v_4736;
v_4737:
    goto v_4733;
v_4734:
    goto v_4735;
v_4736:
    v_4750 = cons(v_4751, v_4750);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_4750; // inputbuflis!*
    v_4750 = nil;
v_4716:
    return onevalue(v_4750);
}



// Code for mv!-pow!-!+

static LispObject CC_mvKpowKL(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4749, v_4750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    stack[-2] = nil;
v_4718:
    v_4749 = stack[-1];
    if (v_4749 == nil) goto v_4721;
    else goto v_4722;
v_4721:
    v_4749 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_4749);
    }
v_4722:
    goto v_4733;
v_4729:
    goto v_4739;
v_4735:
    v_4749 = stack[-1];
    v_4750 = qcar(v_4749);
    goto v_4736;
v_4737:
    v_4749 = stack[0];
    v_4749 = qcar(v_4749);
    goto v_4738;
v_4739:
    goto v_4735;
v_4736:
    goto v_4737;
v_4738:
    v_4750 = plus2(v_4750, v_4749);
    env = stack[-3];
    goto v_4730;
v_4731:
    v_4749 = stack[-2];
    goto v_4732;
v_4733:
    goto v_4729;
v_4730:
    goto v_4731;
v_4732:
    v_4749 = cons(v_4750, v_4749);
    env = stack[-3];
    stack[-2] = v_4749;
    v_4749 = stack[-1];
    v_4749 = qcdr(v_4749);
    stack[-1] = v_4749;
    v_4749 = stack[0];
    v_4749 = qcdr(v_4749);
    stack[0] = v_4749;
    goto v_4718;
    v_4749 = nil;
    return onevalue(v_4749);
}



// Code for conv!:bf2i

static LispObject CC_convTbf2i(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4726, v_4727;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4726 = v_4712;
// end of prologue
    goto v_4719;
v_4715:
    v_4727 = v_4726;
    v_4727 = qcdr(v_4727);
    v_4727 = qcar(v_4727);
    goto v_4716;
v_4717:
    v_4726 = qcdr(v_4726);
    v_4726 = qcdr(v_4726);
    goto v_4718;
v_4719:
    goto v_4715;
v_4716:
    goto v_4717;
v_4718:
    {
        fn = elt(env, 1); // ashift
        return (*qfn2(fn))(fn, v_4727, v_4726);
    }
}



// Code for gionep!:

static LispObject CC_gionepT(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4740, v_4741, v_4742;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4741 = v_4712;
// end of prologue
    goto v_4722;
v_4718:
    v_4740 = v_4741;
    v_4740 = qcdr(v_4740);
    v_4742 = qcar(v_4740);
    goto v_4719;
v_4720:
    v_4740 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4721;
v_4722:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    if (v_4742 == v_4740) goto v_4716;
    else goto v_4717;
v_4716:
    goto v_4731;
v_4727:
    v_4740 = v_4741;
    v_4740 = qcdr(v_4740);
    v_4741 = qcdr(v_4740);
    goto v_4728;
v_4729:
    v_4740 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4730;
v_4731:
    goto v_4727;
v_4728:
    goto v_4729;
v_4730:
    v_4740 = (v_4741 == v_4740 ? lisp_true : nil);
    goto v_4715;
v_4717:
    v_4740 = nil;
    goto v_4715;
    v_4740 = nil;
v_4715:
    return onevalue(v_4740);
}



// Code for valid_as_variable

static LispObject CC_valid_as_variable(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4731, v_4732;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
// copy arguments values to proper place
    v_4732 = v_4712;
// end of prologue
    v_4731 = v_4732;
    if (symbolp(v_4731)) goto v_4717;
    v_4731 = nil;
    goto v_4715;
v_4717:
    goto v_4727;
v_4723:
    goto v_4724;
v_4725:
    v_4731 = elt(env, 1); // invalid_as_variable
    goto v_4726;
v_4727:
    goto v_4723;
v_4724:
    goto v_4725;
v_4726:
    v_4731 = Lflagp(nil, v_4732, v_4731);
    v_4731 = (v_4731 == nil ? lisp_true : nil);
    goto v_4715;
    v_4731 = nil;
v_4715:
    return onevalue(v_4731);
}



// Code for wulessp!*

static LispObject CC_wulesspH(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4749, v_4750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    goto v_4724;
v_4720:
    v_4750 = stack[-1];
    goto v_4721;
v_4722:
    v_4749 = stack[0];
    goto v_4723;
v_4724:
    goto v_4720;
v_4721:
    goto v_4722;
v_4723:
    fn = elt(env, 1); // wulessp
    v_4749 = (*qfn2(fn))(fn, v_4750, v_4749);
    env = stack[-2];
    if (v_4749 == nil) goto v_4718;
    v_4749 = lisp_true;
    goto v_4716;
v_4718:
    goto v_4735;
v_4731:
    v_4750 = stack[0];
    goto v_4732;
v_4733:
    v_4749 = stack[-1];
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    fn = elt(env, 1); // wulessp
    v_4749 = (*qfn2(fn))(fn, v_4750, v_4749);
    env = stack[-2];
    if (v_4749 == nil) goto v_4729;
    v_4749 = nil;
    goto v_4716;
v_4729:
    goto v_4746;
v_4742:
    v_4750 = stack[-1];
    goto v_4743;
v_4744:
    v_4749 = stack[0];
    goto v_4745;
v_4746:
    goto v_4742;
v_4743:
    goto v_4744;
v_4745:
    {
        fn = elt(env, 2); // totallessp
        return (*qfn2(fn))(fn, v_4750, v_4749);
    }
    v_4749 = nil;
v_4716:
    return onevalue(v_4749);
}



// Code for matrix!+p

static LispObject CC_matrixLp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4769, v_4770;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    goto v_4729;
v_4725:
    v_4769 = stack[0];
    v_4770 = Llength(nil, v_4769);
    env = stack[-4];
    goto v_4726;
v_4727:
    v_4769 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4728;
v_4729:
    goto v_4725;
v_4726:
    goto v_4727;
v_4728:
    v_4769 = (LispObject)lessp2(v_4770, v_4769);
    v_4769 = v_4769 ? lisp_true : nil;
    env = stack[-4];
    if (v_4769 == nil) goto v_4723;
    v_4769 = nil;
    goto v_4718;
v_4723:
    v_4769 = stack[0];
    v_4769 = qcar(v_4769);
    v_4769 = Llength(nil, v_4769);
    env = stack[-4];
    stack[-3] = v_4769;
    v_4769 = lisp_true;
    stack[-2] = v_4769;
    v_4769 = stack[0];
    v_4769 = qcdr(v_4769);
    stack[-1] = v_4769;
v_4741:
    v_4769 = stack[-1];
    if (v_4769 == nil) goto v_4746;
    else goto v_4747;
v_4746:
    goto v_4740;
v_4747:
    v_4769 = stack[-1];
    v_4769 = qcar(v_4769);
    goto v_4761;
v_4757:
    stack[0] = stack[-3];
    goto v_4758;
v_4759:
    v_4769 = Llength(nil, v_4769);
    env = stack[-4];
    goto v_4760;
v_4761:
    goto v_4757;
v_4758:
    goto v_4759;
v_4760:
    if (equal(stack[0], v_4769)) goto v_4756;
    v_4769 = nil;
    stack[-2] = v_4769;
    goto v_4754;
v_4756:
v_4754:
    v_4769 = stack[-1];
    v_4769 = qcdr(v_4769);
    stack[-1] = v_4769;
    goto v_4741;
v_4740:
    v_4769 = stack[-2];
v_4718:
    return onevalue(v_4769);
}



// Code for cl_fvarl1

static LispObject CC_cl_fvarl1(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
// copy arguments values to proper place
    v_4717 = v_4712;
// end of prologue
    fn = elt(env, 1); // cl_varl1
    v_4717 = (*qfn1(fn))(fn, v_4717);
    v_4717 = qcar(v_4717);
    return onevalue(v_4717);
}



// Code for ibalp_istotal

static LispObject CC_ibalp_istotal(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4737, v_4738;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4737 = v_4712;
// end of prologue
v_4711:
    v_4738 = v_4737;
    if (v_4738 == nil) goto v_4716;
    else goto v_4717;
v_4716:
    v_4737 = lisp_true;
    goto v_4715;
v_4717:
    v_4738 = v_4737;
    v_4738 = qcar(v_4738);
    v_4738 = qcdr(v_4738);
    v_4738 = qcdr(v_4738);
    v_4738 = qcar(v_4738);
    if (v_4738 == nil) goto v_4724;
    else goto v_4725;
v_4724:
    v_4737 = nil;
    goto v_4723;
v_4725:
    v_4737 = qcdr(v_4737);
    goto v_4711;
    v_4737 = nil;
v_4723:
    goto v_4715;
    v_4737 = nil;
v_4715:
    return onevalue(v_4737);
}



// Code for initbrsea

static LispObject CC_initbrsea(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4832, v_4833, v_4834;
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
    v_4832 = (LispObject)3200+TAG_FIXNUM; // 200
    stack[-2] = v_4832;
    v_4832 = qvalue(elt(env, 2)); // rowmin
    stack[-1] = v_4832;
v_4721:
    goto v_4733;
v_4729:
    v_4833 = qvalue(elt(env, 3)); // rowmax
    goto v_4730;
v_4731:
    v_4832 = stack[-1];
    goto v_4732;
v_4733:
    goto v_4729;
v_4730:
    goto v_4731;
v_4732:
    v_4832 = difference2(v_4833, v_4832);
    env = stack[-3];
    v_4832 = Lminusp(nil, v_4832);
    env = stack[-3];
    if (v_4832 == nil) goto v_4726;
    goto v_4720;
v_4726:
    goto v_4745;
v_4741:
    goto v_4750;
v_4746:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_4747;
v_4748:
    goto v_4757;
v_4753:
    v_4833 = qvalue(elt(env, 5)); // maxvar
    goto v_4754;
v_4755:
    v_4832 = stack[-1];
    goto v_4756;
v_4757:
    goto v_4753;
v_4754:
    goto v_4755;
v_4756:
    v_4832 = plus2(v_4833, v_4832);
    env = stack[-3];
    goto v_4749;
v_4750:
    goto v_4746;
v_4747:
    goto v_4748;
v_4749:
    v_4833 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_4832-TAG_FIXNUM)/(16/CELL)));
    goto v_4742;
v_4743:
    v_4832 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4744;
v_4745:
    goto v_4741;
v_4742:
    goto v_4743;
v_4744:
    v_4832 = *(LispObject *)((char *)v_4833 + (CELL-TAG_VECTOR) + (((intptr_t)v_4832-TAG_FIXNUM)/(16/CELL)));
    if (v_4832 == nil) goto v_4740;
    v_4832 = stack[-1];
    fn = elt(env, 8); // initwght
    v_4832 = (*qfn1(fn))(fn, v_4832);
    env = stack[-3];
    goto v_4738;
v_4740:
v_4738:
    v_4832 = stack[-1];
    v_4832 = add1(v_4832);
    env = stack[-3];
    stack[-1] = v_4832;
    goto v_4721;
v_4720:
    fn = elt(env, 9); // redcodmat
    v_4832 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_4832 = qvalue(elt(env, 6)); // codhisto
    if (v_4832 == nil) goto v_4771;
    v_4832 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_4832;
v_4776:
    goto v_4788;
v_4784:
    v_4833 = (LispObject)3200+TAG_FIXNUM; // 200
    goto v_4785;
v_4786:
    v_4832 = stack[0];
    goto v_4787;
v_4788:
    goto v_4784;
v_4785:
    goto v_4786;
v_4787:
    v_4832 = difference2(v_4833, v_4832);
    env = stack[-3];
    v_4832 = Lminusp(nil, v_4832);
    env = stack[-3];
    if (v_4832 == nil) goto v_4781;
    goto v_4775;
v_4781:
    goto v_4798;
v_4792:
    v_4834 = qvalue(elt(env, 6)); // codhisto
    goto v_4793;
v_4794:
    v_4833 = stack[0];
    goto v_4795;
v_4796:
    v_4832 = nil;
    goto v_4797;
v_4798:
    goto v_4792;
v_4793:
    goto v_4794;
v_4795:
    goto v_4796;
v_4797:
    *(LispObject *)((char *)v_4834 + (CELL-TAG_VECTOR) + (((intptr_t)v_4833-TAG_FIXNUM)/(16/CELL))) = v_4832;
    v_4832 = stack[0];
    v_4832 = add1(v_4832);
    env = stack[-3];
    stack[0] = v_4832;
    goto v_4776;
v_4775:
    goto v_4769;
v_4771:
    v_4832 = stack[-2];
    v_4832 = Lmkvect(nil, v_4832);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_4832; // codhisto
    goto v_4769;
v_4769:
    v_4832 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_4832; // headhisto
    v_4832 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_4832;
v_4812:
    goto v_4824;
v_4820:
    v_4833 = qvalue(elt(env, 3)); // rowmax
    goto v_4821;
v_4822:
    v_4832 = stack[0];
    goto v_4823;
v_4824:
    goto v_4820;
v_4821:
    goto v_4822;
v_4823:
    v_4832 = difference2(v_4833, v_4832);
    env = stack[-3];
    v_4832 = Lminusp(nil, v_4832);
    env = stack[-3];
    if (v_4832 == nil) goto v_4817;
    goto v_4811;
v_4817:
    v_4832 = stack[0];
    fn = elt(env, 10); // inshisto
    v_4832 = (*qfn1(fn))(fn, v_4832);
    env = stack[-3];
    v_4832 = stack[0];
    v_4832 = add1(v_4832);
    env = stack[-3];
    stack[0] = v_4832;
    goto v_4812;
v_4811:
    v_4832 = nil;
    return onevalue(v_4832);
}



// Code for dim!<deg

static LispObject CC_dimRdeg(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4741, v_4742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_4741 = v_4712;
// end of prologue
    goto v_4723;
v_4719:
    stack[0] = qvalue(elt(env, 2)); // dimex!*
    goto v_4720;
v_4721:
    fn = elt(env, 3); // deg!*farg
    v_4741 = (*qfn1(fn))(fn, v_4741);
    env = stack[-1];
    fn = elt(env, 4); // negf
    v_4741 = (*qfn1(fn))(fn, v_4741);
    env = stack[-1];
    goto v_4722;
v_4723:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    fn = elt(env, 5); // addf
    v_4741 = (*qfn2(fn))(fn, stack[0], v_4741);
    env = stack[-1];
    v_4742 = v_4741;
    v_4741 = v_4742;
    if (is_number(v_4741)) goto v_4732;
    else goto v_4731;
v_4732:
    v_4741 = v_4742;
    v_4741 = Lminusp(nil, v_4741);
    if (v_4741 == nil) goto v_4731;
    v_4741 = lisp_true;
    goto v_4729;
v_4731:
    v_4741 = nil;
    goto v_4729;
    v_4741 = nil;
v_4729:
    return onevalue(v_4741);
}



// Code for opnum!*

static LispObject CC_opnumH(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4780, v_4781, v_4782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_4780 = v_4712;
// end of prologue
    stack[-1] = nil;
    v_4781 = v_4780;
    if (symbolp(v_4781)) goto v_4723;
    goto v_4730;
v_4726:
    stack[0] = v_4780;
    goto v_4727;
v_4728:
    fn = elt(env, 3); // collectindices
    v_4780 = (*qfn1(fn))(fn, v_4780);
    env = stack[-2];
    goto v_4729;
v_4730:
    goto v_4726;
v_4727:
    goto v_4728;
v_4729:
    fn = elt(env, 4); // removeindices
    v_4780 = (*qfn2(fn))(fn, stack[0], v_4780);
    env = stack[-2];
    goto v_4721;
v_4723:
v_4721:
    v_4781 = v_4780;
    if (symbolp(v_4781)) goto v_4736;
    else goto v_4737;
v_4736:
    v_4781 = v_4780;
    goto v_4735;
v_4737:
    v_4781 = v_4780;
    v_4781 = qcar(v_4781);
    v_4780 = qcdr(v_4780);
    stack[-1] = v_4780;
    goto v_4735;
v_4735:
    goto v_4752;
v_4748:
    goto v_4749;
v_4750:
    v_4780 = elt(env, 2); // opnum
    goto v_4751;
v_4752:
    goto v_4748;
v_4749:
    goto v_4750;
v_4751:
    v_4780 = get(v_4781, v_4780);
    v_4782 = v_4780;
    goto v_4763;
v_4759:
    v_4781 = stack[-1];
    goto v_4760;
v_4761:
    v_4780 = v_4782;
    goto v_4762;
v_4763:
    goto v_4759;
v_4760:
    goto v_4761;
v_4762:
    v_4781 = Lassoc(nil, v_4781, v_4780);
    v_4780 = v_4781;
    if (v_4781 == nil) goto v_4758;
    v_4780 = qcdr(v_4780);
    goto v_4718;
v_4758:
    goto v_4775;
v_4771:
    v_4780 = nil;
    goto v_4772;
v_4773:
    v_4781 = v_4782;
    goto v_4774;
v_4775:
    goto v_4771;
v_4772:
    goto v_4773;
v_4774:
    v_4780 = Lassoc(nil, v_4780, v_4781);
    v_4780 = qcdr(v_4780);
    goto v_4718;
    v_4780 = nil;
v_4718:
    return onevalue(v_4780);
}



// Code for take!-impart

static LispObject CC_takeKimpart(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4739, v_4740;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    goto v_4719;
v_4715:
    goto v_4725;
v_4721:
    v_4739 = stack[0];
    v_4739 = qcar(v_4739);
    fn = elt(env, 1); // impartf
    v_4740 = (*qfn1(fn))(fn, v_4739);
    env = stack[-2];
    goto v_4722;
v_4723:
    v_4739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4724;
v_4725:
    goto v_4721;
v_4722:
    goto v_4723;
v_4724:
    stack[-1] = cons(v_4740, v_4739);
    env = stack[-2];
    goto v_4716;
v_4717:
    goto v_4735;
v_4731:
    v_4740 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4732;
v_4733:
    v_4739 = stack[0];
    v_4739 = qcdr(v_4739);
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    v_4739 = cons(v_4740, v_4739);
    env = stack[-2];
    goto v_4718;
v_4719:
    goto v_4715;
v_4716:
    goto v_4717;
v_4718:
    {
        LispObject v_4743 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_4743, v_4739);
    }
}



// Code for token1

static LispObject CC_token1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5631, v_5632;
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
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    stack[-3] = v_5631;
v_4718:
    goto v_4756;
v_4752:
    v_5632 = stack[-3];
    goto v_4753;
v_4754:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_4755;
v_4756:
    goto v_4752;
v_4753:
    goto v_4754;
v_4755:
    if (v_5632 == v_5631) goto v_4750;
    else goto v_4751;
v_4750:
    v_5631 = lisp_true;
    goto v_4749;
v_4751:
    goto v_4766;
v_4762:
    v_5631 = stack[-3];
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_4763;
v_4764:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4765;
v_4766:
    goto v_4762;
v_4763:
    goto v_4764;
v_4765:
    v_5631 = (v_5632 == v_5631 ? lisp_true : nil);
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_4749;
    v_5631 = nil;
v_4749:
    if (v_5631 == nil) goto v_4747;
    goto v_4719;
v_4747:
    v_5631 = stack[-3];
    v_5631 = Lwhitespace_char_p(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_4776;
    goto v_4789;
v_4785:
    v_5632 = stack[-3];
    goto v_4786;
v_4787:
    v_5631 = qvalue(elt(env, 4)); // !$eol!$
    goto v_4788;
v_4789:
    goto v_4785;
v_4786:
    goto v_4787;
v_4788:
    if (v_5632 == v_5631) goto v_4783;
    else goto v_4784;
v_4783:
    v_5631 = qvalue(elt(env, 5)); // !*eoldelimp
    goto v_4782;
v_4784:
    v_5631 = nil;
    goto v_4782;
    v_5631 = nil;
v_4782:
    if (v_5631 == nil) goto v_4780;
    else goto v_4776;
v_4780:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_4718;
v_4776:
    v_5631 = stack[-3];
    v_5631 = Ldigitp(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_4798;
    v_5631 = stack[-3];
    {
        fn = elt(env, 40); // token!-number
        return (*qfn1(fn))(fn, v_5631);
    }
v_4798:
    v_5631 = stack[-3];
    v_5631 = Lalpha_char_p(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_4804;
    goto v_4721;
v_4804:
    goto v_4814;
v_4810:
    v_5632 = stack[-3];
    goto v_4811;
v_4812:
    v_5631 = elt(env, 6); // tokprop
    goto v_4813;
v_4814:
    goto v_4810;
v_4811:
    goto v_4812;
v_4813:
    v_5631 = get(v_5632, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    if (v_5631 == nil) goto v_4808;
    goto v_4822;
v_4818:
    v_5632 = stack[-2];
    goto v_4819;
v_4820:
    v_5631 = nil;
    goto v_4821;
v_4822:
    goto v_4818;
v_4819:
    goto v_4820;
v_4821:
    {
        fn = elt(env, 41); // lispapply
        return (*qfn2(fn))(fn, v_5632, v_5631);
    }
v_4808:
    goto v_4835;
v_4831:
    v_5632 = stack[-3];
    goto v_4832;
v_4833:
    v_5631 = elt(env, 7); // !%
    goto v_4834;
v_4835:
    goto v_4831;
v_4832:
    goto v_4833;
v_4834:
    if (v_5632 == v_5631) goto v_4829;
    else goto v_4830;
v_4829:
    v_5631 = qvalue(elt(env, 8)); // !*savecomments!*
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_4828;
v_4830:
    v_5631 = nil;
    goto v_4828;
    v_5631 = nil;
v_4828:
    if (v_5631 == nil) goto v_4826;
    goto v_4741;
v_4826:
    goto v_4853;
v_4849:
    v_5632 = stack[-3];
    goto v_4850;
v_4851:
    v_5631 = elt(env, 9); // !!
    goto v_4852;
v_4853:
    goto v_4849;
v_4850:
    goto v_4851;
v_4852:
    if (v_5632 == v_5631) goto v_4847;
    else goto v_4848;
v_4847:
    v_5631 = qvalue(elt(env, 10)); // !*micro!-version
    if (v_5631 == nil) goto v_4858;
    else goto v_4859;
v_4858:
    v_5631 = nil;
    goto v_4857;
v_4859:
    v_5631 = qvalue(elt(env, 11)); // !*defn
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_4857;
    v_5631 = nil;
v_4857:
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_4846;
v_4848:
    v_5631 = nil;
    goto v_4846;
    v_5631 = nil;
v_4846:
    if (v_5631 == nil) goto v_4844;
    goto v_4720;
v_4844:
    goto v_4876;
v_4872:
    v_5632 = stack[-3];
    goto v_4873;
v_4874:
    v_5631 = elt(env, 12); // !"
    goto v_4875;
v_4876:
    goto v_4872;
v_4873:
    goto v_4874;
v_4875:
    if (v_5632 == v_5631) goto v_4870;
    else goto v_4871;
v_4870:
    goto v_4740;
v_4871:
    goto v_4885;
v_4881:
    v_5632 = stack[-3];
    goto v_4882;
v_4883:
    v_5631 = elt(env, 13); // !\ (backslash)
    goto v_4884;
v_4885:
    goto v_4881;
v_4882:
    goto v_4883;
v_4884:
    if (v_5632 == v_5631) goto v_4879;
    else goto v_4880;
v_4879:
    goto v_4727;
v_4880:
v_4719:
    v_5631 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 14)) = v_5631; // ttype!*
    goto v_4897;
v_4893:
    v_5632 = stack[-3];
    goto v_4894;
v_4895:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_4896;
v_4897:
    goto v_4893;
v_4894:
    goto v_4895;
v_4896:
    if (v_5632 == v_5631) goto v_4891;
    else goto v_4892;
v_4891:
    v_5631 = elt(env, 15); // ! 
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    fn = elt(env, 42); // filenderr
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_4890;
v_4892:
v_4890:
    v_5631 = stack[-3];
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    goto v_4917;
v_4913:
    v_5632 = stack[-3];
    goto v_4914;
v_4915:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_4916;
v_4917:
    goto v_4913;
v_4914:
    goto v_4915;
v_4916:
    if (v_5632 == v_5631) goto v_4912;
    goto v_4932;
v_4928:
    v_5631 = stack[-3];
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_4929;
v_4930:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4931;
v_4932:
    goto v_4928;
v_4929:
    goto v_4930;
v_4931:
    if (v_5632 == v_5631) goto v_4926;
    else goto v_4927;
v_4926:
    v_5631 = stack[-3];
    fn = elt(env, 43); // delcp
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_4925;
v_4927:
    v_5631 = nil;
    goto v_4925;
    v_5631 = nil;
v_4925:
    if (v_5631 == nil) goto v_4923;
    v_5631 = elt(env, 15); // ! 
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    goto v_4921;
v_4923:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    goto v_4921;
v_4921:
    goto v_4910;
v_4912:
v_4910:
    goto v_4958;
v_4954:
    v_5632 = stack[-3];
    goto v_4955;
v_4956:
    v_5631 = elt(env, 17); // !-
    goto v_4957;
v_4958:
    goto v_4954;
v_4955:
    goto v_4956;
v_4957:
    if (v_5632 == v_5631) goto v_4952;
    else goto v_4953;
v_4952:
    goto v_4969;
v_4965:
    v_5632 = qvalue(elt(env, 2)); // crchar!*
    goto v_4966;
v_4967:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_4968;
v_4969:
    goto v_4965;
v_4966:
    goto v_4967;
v_4968:
    if (v_5632 == v_5631) goto v_4964;
    goto v_4980;
v_4976:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_4977;
v_4978:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4979;
v_4980:
    goto v_4976;
v_4977:
    goto v_4978;
v_4979:
    if (v_5632 == v_5631) goto v_4974;
    else goto v_4975;
v_4974:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    v_5631 = Ldigitp(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_4987;
    else goto v_4988;
v_4987:
    v_5631 = nil;
    goto v_4986;
v_4988:
    v_5631 = qvalue(elt(env, 18)); // !*minusliter
    goto v_4986;
    v_5631 = nil;
v_4986:
    goto v_4973;
v_4975:
    v_5631 = nil;
    goto v_4973;
    v_5631 = nil;
v_4973:
    goto v_4962;
v_4964:
    v_5631 = nil;
    goto v_4962;
    v_5631 = nil;
v_4962:
    goto v_4951;
v_4953:
    v_5631 = nil;
    goto v_4951;
    v_5631 = nil;
v_4951:
    if (v_5631 == nil) goto v_4948;
    else goto v_4949;
v_4948:
    goto v_4726;
v_4949:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    fn = elt(env, 40); // token!-number
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-3] = v_5631;
    v_5631 = stack[-3];
    if (is_number(v_5631)) goto v_5008;
    else goto v_5009;
v_5008:
    goto v_5016;
v_5012:
    v_5632 = elt(env, 19); // minus
    goto v_5013;
v_5014:
    v_5631 = stack[-3];
    goto v_5015;
v_5016:
    goto v_5012;
v_5013:
    goto v_5014;
v_5015:
        return Lapply1(nil, v_5632, v_5631);
v_5009:
    goto v_5024;
v_5020:
    v_5631 = stack[-3];
    stack[0] = qcdr(v_5631);
    goto v_5021;
v_5022:
    goto v_5032;
v_5028:
    v_5632 = elt(env, 19); // minus
    goto v_5029;
v_5030:
    v_5631 = stack[-3];
    v_5631 = qcdr(v_5631);
    v_5631 = qcar(v_5631);
    goto v_5031;
v_5032:
    goto v_5028;
v_5029:
    goto v_5030;
v_5031:
    v_5631 = Lapply1(nil, v_5632, v_5631);
    env = stack[-4];
    goto v_5023;
v_5024:
    goto v_5020;
v_5021:
    goto v_5022;
v_5023:
    v_5631 = Lrplaca(nil, stack[0], v_5631);
    v_5631 = stack[-3];
    goto v_4717;
v_4720:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 20, -1);
    qvalue(elt(env, 20)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=21 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 21, 0);
    qvalue(elt(env, 21)) = nil; // !*lower
    v_5631 = lisp_true;
    qvalue(elt(env, 23)) = v_5631; // escaped!*
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    v_5631 = stack[-3];
    v_5631 = Lalpha_char_p(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_5048;
    v_5631 = lisp_true;
    qvalue(elt(env, 23)) = v_5631; // escaped!*
    goto v_5046;
v_5048:
v_5046:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
v_4721:
    v_5631 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 14)) = v_5631; // ttype!*
v_4722:
    v_5631 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-3] = v_5631;
v_4723:
    v_5631 = stack[-3];
    if (v_5631 == nil) goto v_5057;
    else goto v_5058;
v_5057:
    goto v_4724;
v_5058:
    goto v_5065;
v_5061:
    v_5631 = stack[-3];
    v_5632 = qcar(v_5631);
    goto v_5062;
v_5063:
    v_5631 = stack[-2];
    goto v_5064;
v_5065:
    goto v_5061;
v_5062:
    goto v_5063;
v_5064:
    v_5631 = cons(v_5632, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    v_5631 = stack[-3];
    v_5631 = qcdr(v_5631);
    stack[-3] = v_5631;
    goto v_4723;
v_4724:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5084;
v_5080:
    v_5632 = stack[-3];
    goto v_5081;
v_5082:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5083;
v_5084:
    goto v_5080;
v_5081:
    goto v_5082;
v_5083:
    if (v_5632 == v_5631) goto v_5078;
    else goto v_5079;
v_5078:
    v_5631 = lisp_true;
    goto v_5077;
v_5079:
    goto v_5094;
v_5090:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_5091;
v_5092:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5093;
v_5094:
    goto v_5090;
v_5091:
    goto v_5092;
v_5093:
    v_5631 = (v_5632 == v_5631 ? lisp_true : nil);
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_5077;
    v_5631 = nil;
v_5077:
    if (v_5631 == nil) goto v_5075;
    goto v_4725;
v_5075:
    v_5631 = stack[-3];
    v_5631 = Ldigitp(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_5103;
    else goto v_5101;
v_5103:
    v_5631 = stack[-3];
    v_5631 = Lalpha_char_p(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_5106;
    else goto v_5101;
v_5106:
    goto v_5102;
v_5101:
    goto v_4722;
v_5102:
    goto v_5115;
v_5111:
    v_5632 = stack[-3];
    goto v_5112;
v_5113:
    v_5631 = elt(env, 9); // !!
    goto v_5114;
v_5115:
    goto v_5111;
v_5112:
    goto v_5113;
v_5114:
    if (v_5632 == v_5631) goto v_5109;
    else goto v_5110;
v_5109:
    goto v_4720;
v_5110:
    goto v_5128;
v_5124:
    v_5632 = stack[-3];
    goto v_5125;
v_5126:
    v_5631 = elt(env, 17); // !-
    goto v_5127;
v_5128:
    goto v_5124;
v_5125:
    goto v_5126;
v_5127:
    if (v_5632 == v_5631) goto v_5122;
    else goto v_5123;
v_5122:
    v_5631 = qvalue(elt(env, 18)); // !*minusliter
    goto v_5121;
v_5123:
    v_5631 = nil;
    goto v_5121;
    v_5631 = nil;
v_5121:
    if (v_5631 == nil) goto v_5119;
    goto v_4722;
v_5119:
    goto v_5141;
v_5137:
    v_5632 = stack[-3];
    goto v_5138;
v_5139:
    v_5631 = elt(env, 24); // !_
    goto v_5140;
v_5141:
    goto v_5137;
v_5138:
    goto v_5139;
v_5140:
    if (v_5632 == v_5631) goto v_5135;
    else goto v_5136;
v_5135:
    goto v_4722;
v_5136:
    goto v_5150;
v_5146:
    v_5632 = stack[-3];
    goto v_5147;
v_5148:
    v_5631 = elt(env, 25); // !:
    goto v_5149;
v_5150:
    goto v_5146;
v_5147:
    goto v_5148;
v_5149:
    if (v_5632 == v_5631) goto v_5144;
    else goto v_5145;
v_5144:
    goto v_4732;
v_5145:
v_4725:
    v_5631 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 46); // list2wideid
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    goto v_5164;
v_5160:
    v_5632 = stack[-2];
    goto v_5161;
v_5162:
    v_5631 = qvalue(elt(env, 26)); // !*line!-marker
    goto v_5163;
v_5164:
    goto v_5160;
v_5161:
    goto v_5162;
v_5163:
    if (equal(v_5632, v_5631)) goto v_5158;
    else goto v_5159;
v_5158:
    v_5631 = qvalue(elt(env, 27)); // curline!*
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    goto v_5157;
v_5159:
    goto v_5174;
v_5170:
    v_5632 = stack[-2];
    goto v_5171;
v_5172:
    v_5631 = qvalue(elt(env, 28)); // !*file!-marker
    goto v_5173;
v_5174:
    goto v_5170;
v_5171:
    goto v_5172;
v_5173:
    if (equal(v_5632, v_5631)) goto v_5168;
    else goto v_5169;
v_5168:
    v_5631 = qvalue(elt(env, 29)); // ifl!*
    if (v_5631 == nil) goto v_5179;
    else goto v_5180;
v_5179:
    v_5631 = elt(env, 30); // "Terminal"
    goto v_5178;
v_5180:
    v_5631 = qvalue(elt(env, 29)); // ifl!*
    v_5631 = qcar(v_5631);
    goto v_5178;
    v_5631 = nil;
v_5178:
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    goto v_5157;
v_5169:
    v_5631 = stack[-2];
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    goto v_5157;
v_5157:
    v_5631 = stack[-3];
    qvalue(elt(env, 2)) = v_5631; // crchar!*
v_4726:
    v_5631 = qvalue(elt(env, 16)); // nxtsym!*
    goto v_4717;
v_4727:
    v_5631 = elt(env, 31); // (!\ e n d !{ r e d u c e !})
    stack[-2] = v_5631;
    v_5631 = nil;
    stack[0] = v_5631;
v_4728:
    goto v_5199;
v_5195:
    v_5632 = stack[-3];
    goto v_5196;
v_5197:
    v_5631 = stack[0];
    goto v_5198;
v_5199:
    goto v_5195;
v_5196:
    goto v_5197;
v_5198:
    v_5631 = cons(v_5632, v_5631);
    env = stack[-4];
    stack[0] = v_5631;
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    v_5631 = stack[-2];
    v_5631 = qcdr(v_5631);
    stack[-2] = v_5631;
    v_5631 = stack[-2];
    if (v_5631 == nil) goto v_5207;
    else goto v_5208;
v_5207:
    goto v_4729;
v_5208:
    goto v_5216;
v_5212:
    v_5632 = stack[-3];
    goto v_5213;
v_5214:
    v_5631 = stack[-2];
    v_5631 = qcar(v_5631);
    goto v_5215;
v_5216:
    goto v_5212;
v_5213:
    goto v_5214;
v_5215:
    if (v_5632 == v_5631) goto v_5210;
    else goto v_5211;
v_5210:
    goto v_4728;
v_5211:
    goto v_5226;
v_5222:
    v_5632 = stack[-3];
    goto v_5223;
v_5224:
    v_5631 = stack[0];
    goto v_5225;
v_5226:
    goto v_5222;
v_5223:
    goto v_5224;
v_5225:
    v_5631 = cons(v_5632, v_5631);
    env = stack[-4];
    v_5631 = Lreverse(nil, v_5631);
    env = stack[-4];
    v_5631 = qcdr(v_5631);
    qvalue(elt(env, 32)) = v_5631; // peekchar!*
    v_5631 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 14)) = v_5631; // ttype!*
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    v_5631 = elt(env, 13); // !\ (backslash)
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    v_5631 = qvalue(elt(env, 16)); // nxtsym!*
    goto v_4717;
v_4729:
    v_5631 = elt(env, 33); // (!\ b e g i n !{ r e d u c e !})
    stack[-2] = v_5631;
    v_5631 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 14)) = v_5631; // ttype!*
v_4730:
    goto v_5244;
v_5240:
    v_5632 = stack[-3];
    goto v_5241;
v_5242:
    v_5631 = elt(env, 7); // !%
    goto v_5243;
v_5244:
    goto v_5240;
v_5241:
    goto v_5242;
v_5243:
    if (v_5632 == v_5631) goto v_5238;
    else goto v_5239;
v_5238:
    goto v_4731;
v_5239:
    goto v_5253;
v_5249:
    v_5632 = stack[-3];
    goto v_5250;
v_5251:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5252;
v_5253:
    goto v_5249;
v_5250:
    goto v_5251;
v_5252:
    if (v_5632 == v_5631) goto v_5247;
    else goto v_5248;
v_5247:
    v_5631 = elt(env, 15); // ! 
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    fn = elt(env, 42); // filenderr
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_5631 = stack[-3];
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    v_5631 = stack[-3];
    goto v_4717;
v_5248:
    v_5631 = stack[-2];
    if (v_5631 == nil) goto v_5262;
    else goto v_5263;
v_5262:
    goto v_4718;
v_5263:
    v_5631 = stack[-3];
    stack[0] = v_5631;
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5275;
v_5271:
    v_5632 = stack[0];
    goto v_5272;
v_5273:
    v_5631 = stack[-2];
    v_5631 = qcar(v_5631);
    goto v_5274;
v_5275:
    goto v_5271;
v_5272:
    goto v_5273;
v_5274:
    if (v_5632 == v_5631) goto v_5270;
    goto v_4729;
v_5270:
    v_5631 = stack[-2];
    v_5631 = qcdr(v_5631);
    stack[-2] = v_5631;
    goto v_4730;
v_4731:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5290;
v_5286:
    v_5632 = stack[-3];
    goto v_5287;
v_5288:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5289;
v_5290:
    goto v_5286;
v_5287:
    goto v_5288;
v_5289:
    if (v_5632 == v_5631) goto v_5284;
    else goto v_5285;
v_5284:
    goto v_4730;
v_5285:
    goto v_5299;
v_5295:
    v_5632 = stack[-3];
    goto v_5296;
v_5297:
    v_5631 = qvalue(elt(env, 4)); // !$eol!$
    goto v_5298;
v_5299:
    goto v_5295;
v_5296:
    goto v_5297;
v_5298:
    if (v_5632 == v_5631) goto v_5293;
    else goto v_5294;
v_5293:
    goto v_4729;
v_5294:
    goto v_4731;
v_4732:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5313;
v_5309:
    v_5632 = stack[-3];
    goto v_5310;
v_5311:
    v_5631 = elt(env, 25); // !:
    goto v_5312;
v_5313:
    goto v_5309;
v_5310:
    goto v_5311;
v_5312:
    if (v_5632 == v_5631) goto v_5307;
    else goto v_5308;
v_5307:
    goto v_4733;
v_5308:
    v_5631 = stack[-3];
    v_5631 = ncons(v_5631);
    env = stack[-4];
    qvalue(elt(env, 32)) = v_5631; // peekchar!*
    v_5631 = elt(env, 25); // !:
    stack[-3] = v_5631;
    goto v_4725;
v_4733:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5332;
v_5328:
    v_5632 = stack[-3];
    goto v_5329;
v_5330:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5331;
v_5332:
    goto v_5328;
v_5329:
    goto v_5330;
v_5331:
    if (v_5632 == v_5631) goto v_5327;
    goto v_5343;
v_5339:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_5340;
v_5341:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5342;
v_5343:
    goto v_5339;
v_5340:
    goto v_5341;
v_5342:
    if (v_5632 == v_5631) goto v_5337;
    else goto v_5338;
v_5337:
    v_5631 = stack[-3];
    v_5631 = Lalpha_char_p(nil, v_5631);
    env = stack[-4];
    goto v_5336;
v_5338:
    v_5631 = nil;
    goto v_5336;
    v_5631 = nil;
v_5336:
    goto v_5325;
v_5327:
    v_5631 = nil;
    goto v_5325;
    v_5631 = nil;
v_5325:
    if (v_5631 == nil) goto v_5323;
    goto v_4734;
v_5323:
    goto v_5361;
v_5357:
    v_5632 = elt(env, 25); // !:
    goto v_5358;
v_5359:
    v_5631 = stack[-3];
    goto v_5360;
v_5361:
    goto v_5357;
v_5358:
    goto v_5359;
v_5360:
    v_5631 = list2(v_5632, v_5631);
    env = stack[-4];
    qvalue(elt(env, 32)) = v_5631; // peekchar!*
    v_5631 = elt(env, 25); // !:
    stack[-3] = v_5631;
    goto v_4725;
v_4734:
    v_5631 = stack[-2];
    v_5631 = Lreverse(nil, v_5631);
    env = stack[-4];
    fn = elt(env, 46); // list2wideid
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_5375;
v_5369:
    v_5631 = elt(env, 25); // !:
    fn = elt(env, 47); // string2list
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[0] = qcar(v_5631);
    goto v_5370;
v_5371:
    v_5631 = elt(env, 25); // !:
    fn = elt(env, 47); // string2list
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    v_5632 = qcar(v_5631);
    goto v_5372;
v_5373:
    v_5631 = stack[-2];
    goto v_5374;
v_5375:
    goto v_5369;
v_5370:
    goto v_5371;
v_5372:
    goto v_5373;
v_5374:
    v_5631 = list2star(stack[0], v_5632, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
v_4735:
    v_5631 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-3] = v_5631;
v_4736:
    v_5631 = stack[-3];
    if (v_5631 == nil) goto v_5387;
    else goto v_5388;
v_5387:
    goto v_4737;
v_5388:
    goto v_5395;
v_5391:
    v_5631 = stack[-3];
    v_5632 = qcar(v_5631);
    goto v_5392;
v_5393:
    v_5631 = stack[-2];
    goto v_5394;
v_5395:
    goto v_5391;
v_5392:
    goto v_5393;
v_5394:
    v_5631 = cons(v_5632, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    v_5631 = stack[-3];
    v_5631 = qcdr(v_5631);
    stack[-3] = v_5631;
    goto v_4736;
v_4737:
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5414;
v_5410:
    v_5632 = stack[-3];
    goto v_5411;
v_5412:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5413;
v_5414:
    goto v_5410;
v_5411:
    goto v_5412;
v_5413:
    if (v_5632 == v_5631) goto v_5408;
    else goto v_5409;
v_5408:
    v_5631 = lisp_true;
    goto v_5407;
v_5409:
    goto v_5424;
v_5420:
    v_5631 = qvalue(elt(env, 2)); // crchar!*
    fn = elt(env, 37); // id2string
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v_5632 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    goto v_5421;
v_5422:
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5423;
v_5424:
    goto v_5420;
v_5421:
    goto v_5422;
v_5423:
    v_5631 = (v_5632 == v_5631 ? lisp_true : nil);
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_5407;
    v_5631 = nil;
v_5407:
    if (v_5631 == nil) goto v_5405;
    goto v_4738;
v_5405:
    v_5631 = stack[-3];
    v_5631 = Ldigitp(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_5433;
    else goto v_5431;
v_5433:
    v_5631 = stack[-3];
    v_5631 = Lalpha_char_p(nil, v_5631);
    env = stack[-4];
    if (v_5631 == nil) goto v_5436;
    else goto v_5431;
v_5436:
    goto v_5432;
v_5431:
    goto v_4735;
v_5432:
    goto v_5445;
v_5441:
    v_5632 = stack[-3];
    goto v_5442;
v_5443:
    v_5631 = elt(env, 9); // !!
    goto v_5444;
v_5445:
    goto v_5441;
v_5442:
    goto v_5443;
v_5444:
    if (v_5632 == v_5631) goto v_5439;
    else goto v_5440;
v_5439:
    goto v_4739;
v_5440:
    goto v_5458;
v_5454:
    v_5632 = stack[-3];
    goto v_5455;
v_5456:
    v_5631 = elt(env, 17); // !-
    goto v_5457;
v_5458:
    goto v_5454;
v_5455:
    goto v_5456;
v_5457:
    if (v_5632 == v_5631) goto v_5452;
    else goto v_5453;
v_5452:
    v_5631 = qvalue(elt(env, 18)); // !*minusliter
    goto v_5451;
v_5453:
    v_5631 = nil;
    goto v_5451;
    v_5631 = nil;
v_5451:
    if (v_5631 == nil) goto v_5449;
    goto v_4735;
v_5449:
    goto v_5471;
v_5467:
    v_5632 = stack[-3];
    goto v_5468;
v_5469:
    v_5631 = elt(env, 24); // !_
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    if (v_5632 == v_5631) goto v_5465;
    else goto v_5466;
v_5465:
    goto v_4735;
v_5466:
v_4738:
    v_5631 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    fn = elt(env, 46); // list2wideid
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    goto v_5483;
v_5479:
    v_5632 = elt(env, 34); // "Name with double colon in detected:"
    goto v_5480;
v_5481:
    v_5631 = stack[-2];
    goto v_5482;
v_5483:
    goto v_5479;
v_5480:
    goto v_5481;
v_5482:
    v_5631 = list2(v_5632, v_5631);
    env = stack[-4];
    fn = elt(env, 48); // lprim
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    v_5631 = stack[-2];
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    v_5631 = stack[-3];
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    v_5631 = qvalue(elt(env, 16)); // nxtsym!*
    goto v_4717;
v_4739:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 20, -1);
    qvalue(elt(env, 20)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=21 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 21, 0);
    qvalue(elt(env, 21)) = nil; // !*lower
    v_5631 = lisp_true;
    qvalue(elt(env, 23)) = v_5631; // escaped!*
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_4735;
v_4740:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 20, -1);
    qvalue(elt(env, 20)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=21 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 21, 0);
    qvalue(elt(env, 21)) = nil; // !*lower
v_5500:
    v_5631 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    stack[-3] = v_5631;
v_5501:
    v_5631 = stack[-3];
    if (v_5631 == nil) goto v_5508;
    else goto v_5509;
v_5508:
    goto v_5502;
v_5509:
    goto v_5516;
v_5512:
    v_5631 = stack[-3];
    v_5632 = qcar(v_5631);
    goto v_5513;
v_5514:
    v_5631 = stack[-2];
    goto v_5515;
v_5516:
    goto v_5512;
v_5513:
    goto v_5514;
v_5515:
    v_5631 = cons(v_5632, v_5631);
    env = stack[-4];
    stack[-2] = v_5631;
    v_5631 = stack[-3];
    v_5631 = qcdr(v_5631);
    stack[-3] = v_5631;
    goto v_5501;
v_5502:
    v_5631 = nil;
    qvalue(elt(env, 35)) = v_5631; // named!-character!*
    goto v_5531;
v_5527:
    fn = elt(env, 39); // readch1
    v_5632 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5632;
    goto v_5528;
v_5529:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5530;
v_5531:
    goto v_5527;
v_5528:
    goto v_5529;
v_5530:
    if (v_5632 == v_5631) goto v_5525;
    else goto v_5526;
v_5525:
    v_5631 = elt(env, 15); // ! 
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    goto v_5540;
v_5536:
    v_5632 = elt(env, 36); // "***** End-of-file in string"
    goto v_5537;
v_5538:
    v_5631 = nil;
    goto v_5539;
v_5540:
    goto v_5536;
v_5537:
    goto v_5538;
v_5539:
    fn = elt(env, 49); // lpriw
    v_5631 = (*qfn2(fn))(fn, v_5632, v_5631);
    env = stack[-4];
    fn = elt(env, 42); // filenderr
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_5524;
v_5526:
    goto v_5554;
v_5550:
    v_5632 = stack[-3];
    goto v_5551;
v_5552:
    v_5631 = elt(env, 12); // !"
    goto v_5553;
v_5554:
    goto v_5550;
v_5551:
    goto v_5552;
v_5553:
    if (v_5632 == v_5631) goto v_5549;
    v_5631 = lisp_true;
    goto v_5547;
v_5549:
    v_5631 = qvalue(elt(env, 35)); // named!-character!*
    goto v_5547;
    v_5631 = nil;
v_5547:
    if (v_5631 == nil) goto v_5545;
    goto v_5500;
v_5545:
v_5524:
    v_5631 = nil;
    qvalue(elt(env, 35)) = v_5631; // named!-character!*
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_5575;
v_5571:
    v_5632 = stack[-3];
    goto v_5572;
v_5573:
    v_5631 = elt(env, 12); // !"
    goto v_5574;
v_5575:
    goto v_5571;
v_5572:
    goto v_5573;
v_5574:
    if (v_5632 == v_5631) goto v_5569;
    else goto v_5570;
v_5569:
    v_5631 = qvalue(elt(env, 35)); // named!-character!*
    v_5631 = (v_5631 == nil ? lisp_true : nil);
    goto v_5568;
v_5570:
    v_5631 = nil;
    goto v_5568;
    v_5631 = nil;
v_5568:
    if (v_5631 == nil) goto v_5566;
    goto v_5500;
v_5566:
    v_5631 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    v_5631 = qcdr(v_5631);
    fn = elt(env, 50); // list2widestring
    v_5631 = (*qfn1(fn))(fn, v_5631);
    env = stack[-4];
    qvalue(elt(env, 16)) = v_5631; // nxtsym!*
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_5631 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 14)) = v_5631; // ttype!*
    v_5631 = stack[-3];
    qvalue(elt(env, 2)) = v_5631; // crchar!*
    goto v_4726;
v_4741:
// Binding !*raise
// FLUIDBIND: reloadenv=4 litvec-offset=20 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 20, -1);
    qvalue(elt(env, 20)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=4 litvec-offset=21 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 21, 0);
    qvalue(elt(env, 21)) = nil; // !*lower
v_5593:
    v_5631 = nil;
    qvalue(elt(env, 35)) = v_5631; // named!-character!*
    goto v_5612;
v_5608:
    fn = elt(env, 39); // readch1
    v_5632 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5632;
    goto v_5609;
v_5610:
    v_5631 = qvalue(elt(env, 4)); // !$eol!$
    goto v_5611;
v_5612:
    goto v_5608;
v_5609:
    goto v_5610;
v_5611:
    if (v_5632 == v_5631) goto v_5606;
    else goto v_5607;
v_5606:
    v_5631 = lisp_true;
    goto v_5605;
v_5607:
    goto v_5622;
v_5618:
    v_5632 = stack[-3];
    goto v_5619;
v_5620:
    v_5631 = qvalue(elt(env, 3)); // !$eof!$
    goto v_5621;
v_5622:
    goto v_5618;
v_5619:
    goto v_5620;
v_5621:
    v_5631 = (v_5632 == v_5631 ? lisp_true : nil);
    goto v_5605;
    v_5631 = nil;
v_5605:
    if (v_5631 == nil) goto v_5602;
    else goto v_5603;
v_5602:
    v_5631 = lisp_true;
    goto v_5601;
v_5603:
    v_5631 = qvalue(elt(env, 35)); // named!-character!*
    goto v_5601;
    v_5631 = nil;
v_5601:
    if (v_5631 == nil) goto v_5599;
    goto v_5593;
v_5599:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    fn = elt(env, 39); // readch1
    v_5631 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_5631;
    goto v_4718;
v_4717:
    return onevalue(v_5631);
}



// Code for cali_bc_fi

static LispObject CC_cali_bc_fi(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4729, v_4730, v_4731;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4730 = v_4712;
// end of prologue
    goto v_4722;
v_4718:
    v_4731 = v_4730;
    goto v_4719;
v_4720:
    v_4729 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4721;
v_4722:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    if (v_4731 == v_4729) goto v_4716;
    else goto v_4717;
v_4716:
    v_4729 = nil;
    goto v_4715;
v_4717:
    v_4729 = v_4730;
    goto v_4715;
    v_4729 = nil;
v_4715:
    return onevalue(v_4729);
}



// Code for maprint

static LispObject CC_maprint(LispObject env,
                         LispObject v_4713, LispObject v_4714)
{
    env = qenv(env);
    LispObject v_4988, v_4989, v_4990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4714,v_4713);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4713,v_4714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_4988 = v_4714;
    stack[-3] = v_4713;
// end of prologue
// Binding p!*!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_4988; // p!*!*
    stack[0] = nil;
    v_4988 = qvalue(elt(env, 1)); // p!*!*
    stack[-2] = v_4988;
    v_4988 = stack[-3];
    if (v_4988 == nil) goto v_4729;
    else goto v_4730;
v_4729:
    v_4988 = nil;
    goto v_4724;
v_4730:
    v_4988 = stack[-3];
    fn = elt(env, 12); // physopp
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    if (v_4988 == nil) goto v_4734;
    goto v_4742;
v_4738:
    v_4989 = elt(env, 3); // physoppri
    goto v_4739;
v_4740:
    v_4988 = stack[-3];
    goto v_4741;
v_4742:
    goto v_4738;
v_4739:
    goto v_4740;
v_4741:
    v_4988 = Lapply1(nil, v_4989, v_4988);
    goto v_4724;
v_4734:
    v_4988 = stack[-3];
    if (!consp(v_4988)) goto v_4745;
    else goto v_4746;
v_4745:
    v_4988 = stack[-3];
    v_4988 = Lsimple_vectorp(nil, v_4988);
    env = stack[-5];
    if (v_4988 == nil) goto v_4751;
    goto v_4759;
v_4755:
    v_4989 = stack[-3];
    goto v_4756;
v_4757:
    v_4988 = qvalue(elt(env, 1)); // p!*!*
    goto v_4758;
v_4759:
    goto v_4755;
v_4756:
    goto v_4757;
v_4758:
    fn = elt(env, 13); // vec!-maprin
    v_4988 = (*qfn2(fn))(fn, v_4989, v_4988);
    goto v_4749;
v_4751:
    v_4988 = stack[-3];
    if (is_number(v_4988)) goto v_4767;
    v_4988 = lisp_true;
    goto v_4765;
v_4767:
    goto v_4781;
v_4777:
    v_4989 = stack[-3];
    goto v_4778;
v_4779:
    v_4988 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4780;
v_4781:
    goto v_4777;
v_4778:
    goto v_4779;
v_4780:
    v_4988 = (LispObject)lessp2(v_4989, v_4988);
    v_4988 = v_4988 ? lisp_true : nil;
    env = stack[-5];
    if (v_4988 == nil) goto v_4774;
    else goto v_4775;
v_4774:
    v_4988 = lisp_true;
    goto v_4773;
v_4775:
    goto v_4792;
v_4788:
    v_4989 = stack[-2];
    goto v_4789;
v_4790:
    v_4988 = elt(env, 4); // minus
    if (!symbolp(v_4988)) v_4988 = nil;
    else { v_4988 = qfastgets(v_4988);
           if (v_4988 != nil) { v_4988 = elt(v_4988, 23); // infix
#ifdef RECORD_GET
             if (v_4988 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_4988 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_4988 == SPID_NOPROP) v_4988 = nil; }}
#endif
    goto v_4791;
v_4792:
    goto v_4788;
v_4789:
    goto v_4790;
v_4791:
    v_4988 = (LispObject)lesseq2(v_4989, v_4988);
    v_4988 = v_4988 ? lisp_true : nil;
    env = stack[-5];
    goto v_4773;
    v_4988 = nil;
v_4773:
    goto v_4765;
    v_4988 = nil;
v_4765:
    if (v_4988 == nil) goto v_4763;
    v_4988 = stack[-3];
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    goto v_4749;
v_4763:
    v_4988 = elt(env, 5); // "("
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    v_4988 = stack[-3];
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    v_4988 = elt(env, 6); // ")"
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    goto v_4749;
v_4749:
    v_4988 = stack[-3];
    goto v_4724;
v_4746:
    v_4988 = stack[-3];
    v_4988 = qcar(v_4988);
    if (!consp(v_4988)) goto v_4808;
    goto v_4816;
v_4812:
    v_4988 = stack[-3];
    v_4989 = qcar(v_4988);
    goto v_4813;
v_4814:
    v_4988 = stack[-2];
    goto v_4815;
v_4816:
    goto v_4812;
v_4813:
    goto v_4814;
v_4815:
    v_4988 = CC_maprint(elt(env, 0), v_4989, v_4988);
    env = stack[-5];
    goto v_4728;
v_4808:
    v_4988 = stack[-3];
    v_4988 = qcar(v_4988);
    if (!symbolp(v_4988)) v_4988 = nil;
    else { v_4988 = qfastgets(v_4988);
           if (v_4988 != nil) { v_4988 = elt(v_4988, 60); // pprifn
#ifdef RECORD_GET
             if (v_4988 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v_4988 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v_4988 == SPID_NOPROP) v_4988 = nil; }}
#endif
    stack[-1] = v_4988;
    if (v_4988 == nil) goto v_4822;
    goto v_4832;
v_4828:
    goto v_4840;
v_4834:
    v_4990 = stack[-1];
    goto v_4835;
v_4836:
    v_4989 = stack[-3];
    goto v_4837;
v_4838:
    v_4988 = stack[-2];
    goto v_4839;
v_4840:
    goto v_4834;
v_4835:
    goto v_4836;
v_4837:
    goto v_4838;
v_4839:
    v_4989 = Lapply2(nil, 3, v_4990, v_4989, v_4988);
    env = stack[-5];
    goto v_4829;
v_4830:
    v_4988 = elt(env, 7); // failed
    goto v_4831;
v_4832:
    goto v_4828;
v_4829:
    goto v_4830;
v_4831:
    if (v_4989 == v_4988) goto v_4822;
    goto v_4820;
v_4822:
    v_4988 = stack[-3];
    v_4988 = qcar(v_4988);
    if (!symbolp(v_4988)) v_4988 = nil;
    else { v_4988 = qfastgets(v_4988);
           if (v_4988 != nil) { v_4988 = elt(v_4988, 57); // prifn
#ifdef RECORD_GET
             if (v_4988 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_4988 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_4988 == SPID_NOPROP) v_4988 = nil; }}
#endif
    stack[-1] = v_4988;
    if (v_4988 == nil) goto v_4845;
    goto v_4855;
v_4851:
    goto v_4861;
v_4857:
    v_4989 = stack[-1];
    goto v_4858;
v_4859:
    v_4988 = stack[-3];
    goto v_4860;
v_4861:
    goto v_4857;
v_4858:
    goto v_4859;
v_4860:
    v_4989 = Lapply1(nil, v_4989, v_4988);
    env = stack[-5];
    goto v_4852;
v_4853:
    v_4988 = elt(env, 7); // failed
    goto v_4854;
v_4855:
    goto v_4851;
v_4852:
    goto v_4853;
v_4854:
    if (v_4989 == v_4988) goto v_4845;
    goto v_4820;
v_4845:
    goto v_4821;
v_4820:
    v_4988 = stack[-3];
    goto v_4724;
v_4821:
    v_4988 = stack[-3];
    v_4988 = qcar(v_4988);
    if (!symbolp(v_4988)) v_4988 = nil;
    else { v_4988 = qfastgets(v_4988);
           if (v_4988 != nil) { v_4988 = elt(v_4988, 23); // infix
#ifdef RECORD_GET
             if (v_4988 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_4988 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_4988 == SPID_NOPROP) v_4988 = nil; }}
#endif
    stack[-1] = v_4988;
    if (v_4988 == nil) goto v_4867;
    goto v_4876;
v_4872:
    v_4989 = stack[-1];
    goto v_4873;
v_4874:
    v_4988 = stack[-2];
    goto v_4875;
v_4876:
    goto v_4872;
v_4873:
    goto v_4874;
v_4875:
    v_4988 = (LispObject)greaterp2(v_4989, v_4988);
    v_4988 = v_4988 ? lisp_true : nil;
    env = stack[-5];
    v_4988 = (v_4988 == nil ? lisp_true : nil);
    stack[-2] = v_4988;
    v_4988 = stack[-2];
    if (v_4988 == nil) goto v_4883;
    v_4988 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v_4988;
    v_4988 = elt(env, 5); // "("
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    goto v_4897;
v_4893:
    v_4989 = qvalue(elt(env, 9)); // posn!*
    goto v_4894;
v_4895:
    v_4988 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_4896;
v_4897:
    goto v_4893;
v_4894:
    goto v_4895;
v_4896:
    v_4988 = (LispObject)lessp2(v_4989, v_4988);
    v_4988 = v_4988 ? lisp_true : nil;
    env = stack[-5];
    if (v_4988 == nil) goto v_4891;
    v_4988 = qvalue(elt(env, 9)); // posn!*
    goto v_4889;
v_4891:
    goto v_4908;
v_4904:
    v_4989 = qvalue(elt(env, 8)); // orig!*
    goto v_4905;
v_4906:
    v_4988 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_4907;
v_4908:
    goto v_4904;
v_4905:
    goto v_4906;
v_4907:
    v_4988 = plus2(v_4989, v_4988);
    env = stack[-5];
    goto v_4889;
    v_4988 = nil;
v_4889:
    qvalue(elt(env, 8)) = v_4988; // orig!*
    goto v_4881;
v_4883:
v_4881:
    goto v_4918;
v_4912:
    v_4988 = stack[-3];
    v_4990 = qcar(v_4988);
    goto v_4913;
v_4914:
    v_4989 = stack[-1];
    goto v_4915;
v_4916:
    v_4988 = stack[-3];
    v_4988 = qcdr(v_4988);
    goto v_4917;
v_4918:
    goto v_4912;
v_4913:
    goto v_4914;
v_4915:
    goto v_4916;
v_4917:
    fn = elt(env, 15); // inprint
    v_4988 = (*qfnn(fn))(fn, 3, v_4990, v_4989, v_4988);
    env = stack[-5];
    v_4988 = stack[-2];
    if (v_4988 == nil) goto v_4927;
    v_4988 = elt(env, 6); // ")"
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    v_4988 = stack[0];
    qvalue(elt(env, 8)) = v_4988; // orig!*
    goto v_4925;
v_4927:
v_4925:
    v_4988 = stack[-3];
    goto v_4724;
v_4867:
    v_4988 = stack[-3];
    v_4988 = qcar(v_4988);
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    goto v_4728;
v_4728:
    v_4988 = elt(env, 5); // "("
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    env = stack[-5];
    v_4988 = nil;
    qvalue(elt(env, 10)) = v_4988; // obrkp!*
    v_4988 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v_4988;
    goto v_4951;
v_4947:
    v_4989 = qvalue(elt(env, 9)); // posn!*
    goto v_4948;
v_4949:
    v_4988 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_4950;
v_4951:
    goto v_4947;
v_4948:
    goto v_4949;
v_4950:
    v_4988 = (LispObject)lessp2(v_4989, v_4988);
    v_4988 = v_4988 ? lisp_true : nil;
    env = stack[-5];
    if (v_4988 == nil) goto v_4945;
    v_4988 = qvalue(elt(env, 9)); // posn!*
    goto v_4943;
v_4945:
    goto v_4962;
v_4958:
    v_4989 = qvalue(elt(env, 8)); // orig!*
    goto v_4959;
v_4960:
    v_4988 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_4961;
v_4962:
    goto v_4958;
v_4959:
    goto v_4960;
v_4961:
    v_4988 = plus2(v_4989, v_4988);
    env = stack[-5];
    goto v_4943;
    v_4988 = nil;
v_4943:
    qvalue(elt(env, 8)) = v_4988; // orig!*
    v_4988 = stack[-3];
    v_4988 = qcdr(v_4988);
    if (v_4988 == nil) goto v_4968;
    goto v_4978;
v_4972:
    v_4990 = elt(env, 11); // !*comma!*
    goto v_4973;
v_4974:
    v_4989 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4975;
v_4976:
    v_4988 = stack[-3];
    v_4988 = qcdr(v_4988);
    goto v_4977;
v_4978:
    goto v_4972;
v_4973:
    goto v_4974;
v_4975:
    goto v_4976;
v_4977:
    fn = elt(env, 15); // inprint
    v_4988 = (*qfnn(fn))(fn, 3, v_4990, v_4989, v_4988);
    env = stack[-5];
    goto v_4966;
v_4968:
v_4966:
    v_4988 = lisp_true;
    qvalue(elt(env, 10)) = v_4988; // obrkp!*
    v_4988 = stack[0];
    qvalue(elt(env, 8)) = v_4988; // orig!*
    v_4988 = elt(env, 6); // ")"
    fn = elt(env, 14); // prin2!*
    v_4988 = (*qfn1(fn))(fn, v_4988);
    v_4988 = stack[-3];
v_4724:
    ;}  // end of a binding scope
    return onevalue(v_4988);
}



// Code for mapcons

static LispObject CC_mapcons(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4769, v_4770;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_4713;
    v_4769 = v_4712;
// end of prologue
    stack[-4] = v_4769;
    v_4769 = stack[-4];
    if (v_4769 == nil) goto v_4724;
    else goto v_4725;
v_4724:
    v_4769 = nil;
    goto v_4719;
v_4725:
    v_4769 = stack[-4];
    v_4769 = qcar(v_4769);
    goto v_4737;
v_4733:
    v_4770 = stack[-3];
    goto v_4734;
v_4735:
    goto v_4736;
v_4737:
    goto v_4733;
v_4734:
    goto v_4735;
v_4736:
    v_4769 = cons(v_4770, v_4769);
    env = stack[-5];
    v_4769 = ncons(v_4769);
    env = stack[-5];
    stack[-1] = v_4769;
    stack[-2] = v_4769;
v_4720:
    v_4769 = stack[-4];
    v_4769 = qcdr(v_4769);
    stack[-4] = v_4769;
    v_4769 = stack[-4];
    if (v_4769 == nil) goto v_4744;
    else goto v_4745;
v_4744:
    v_4769 = stack[-2];
    goto v_4719;
v_4745:
    goto v_4753;
v_4749:
    stack[0] = stack[-1];
    goto v_4750;
v_4751:
    v_4769 = stack[-4];
    v_4769 = qcar(v_4769);
    goto v_4764;
v_4760:
    v_4770 = stack[-3];
    goto v_4761;
v_4762:
    goto v_4763;
v_4764:
    goto v_4760;
v_4761:
    goto v_4762;
v_4763:
    v_4769 = cons(v_4770, v_4769);
    env = stack[-5];
    v_4769 = ncons(v_4769);
    env = stack[-5];
    goto v_4752;
v_4753:
    goto v_4749;
v_4750:
    goto v_4751;
v_4752:
    v_4769 = Lrplacd(nil, stack[0], v_4769);
    env = stack[-5];
    v_4769 = stack[-1];
    v_4769 = qcdr(v_4769);
    stack[-1] = v_4769;
    goto v_4720;
v_4719:
    return onevalue(v_4769);
}



// Code for qcputx

static LispObject CC_qcputx(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4756, v_4757, v_4758;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4757 = v_4712;
// end of prologue
    goto v_4723;
v_4719:
    v_4758 = v_4757;
    goto v_4720;
v_4721:
    v_4756 = elt(env, 1); // quote
    goto v_4722;
v_4723:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    if (!consp(v_4758)) goto v_4717;
    v_4758 = qcar(v_4758);
    if (v_4758 == v_4756) goto v_4716;
    else goto v_4717;
v_4716:
    goto v_4735;
v_4731:
    v_4756 = v_4757;
    v_4756 = qcdr(v_4756);
    v_4758 = qcar(v_4756);
    goto v_4732;
v_4733:
    v_4756 = elt(env, 2); // cref
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    v_4756 = Lflagp(nil, v_4758, v_4756);
    env = stack[0];
    if (v_4756 == nil) goto v_4729;
    v_4756 = lisp_true;
    goto v_4727;
v_4729:
    goto v_4748;
v_4744:
    v_4756 = v_4757;
    v_4756 = qcdr(v_4756);
    v_4756 = qcar(v_4756);
    goto v_4745;
v_4746:
    v_4757 = elt(env, 3); // compile
    goto v_4747;
v_4748:
    goto v_4744;
v_4745:
    goto v_4746;
v_4747:
        return Lflagp(nil, v_4756, v_4757);
    v_4756 = nil;
v_4727:
    goto v_4715;
v_4717:
    v_4756 = nil;
    goto v_4715;
    v_4756 = nil;
v_4715:
    return onevalue(v_4756);
}



// Code for rmplus

static LispObject CC_rmplus(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4732, v_4733, v_4734;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4733 = v_4712;
// end of prologue
    goto v_4723;
v_4719:
    v_4732 = v_4733;
    goto v_4720;
v_4721:
    v_4734 = elt(env, 1); // plus
    goto v_4722;
v_4723:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    if (!consp(v_4732)) goto v_4717;
    v_4732 = qcar(v_4732);
    if (v_4732 == v_4734) goto v_4716;
    else goto v_4717;
v_4716:
    v_4732 = v_4733;
    v_4732 = qcdr(v_4732);
    goto v_4715;
v_4717:
    v_4732 = v_4733;
    return ncons(v_4732);
    v_4732 = nil;
v_4715:
    return onevalue(v_4732);
}



// Code for removeg

static LispObject CC_removeg(LispObject env,
                         LispObject v_4712, LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4906, v_4907, v_4908, v_4909;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4712,v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4713;
    stack[-1] = v_4712;
// end of prologue
    goto v_4724;
v_4720:
    v_4906 = stack[-1];
    v_4907 = qcdr(v_4906);
    goto v_4721;
v_4722:
    v_4906 = stack[0];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcar(v_4906);
    goto v_4723;
v_4724:
    goto v_4720;
v_4721:
    goto v_4722;
v_4723:
    fn = elt(env, 7); // finde
    v_4906 = (*qfn2(fn))(fn, v_4907, v_4906);
    env = stack[-3];
    stack[-2] = v_4906;
    goto v_4740;
v_4736:
    v_4906 = stack[-2];
    v_4907 = qcar(v_4906);
    goto v_4737;
v_4738:
    v_4906 = stack[0];
    goto v_4739;
v_4740:
    goto v_4736;
v_4737:
    goto v_4738;
v_4739:
    if (v_4907 == v_4906) goto v_4734;
    else goto v_4735;
v_4734:
    goto v_4749;
v_4745:
    v_4906 = stack[-2];
    v_4907 = qcdr(v_4906);
    goto v_4746;
v_4747:
    v_4906 = stack[0];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcar(v_4906);
    goto v_4748;
v_4749:
    goto v_4745;
v_4746:
    goto v_4747;
v_4748:
    fn = elt(env, 7); // finde
    v_4906 = (*qfn2(fn))(fn, v_4907, v_4906);
    env = stack[-3];
    stack[-2] = v_4906;
    goto v_4733;
v_4735:
v_4733:
    v_4906 = stack[-2];
    if (v_4906 == nil) goto v_4759;
    else goto v_4760;
v_4759:
    goto v_4772;
v_4764:
    v_4909 = elt(env, 2); // "Free edge"
    goto v_4765;
v_4766:
    v_4906 = stack[0];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4908 = qcar(v_4906);
    goto v_4767;
v_4768:
    v_4907 = elt(env, 3); // "in vertex"
    goto v_4769;
v_4770:
    v_4906 = stack[0];
    goto v_4771;
v_4772:
    goto v_4764;
v_4765:
    goto v_4766;
v_4767:
    goto v_4768;
v_4769:
    goto v_4770;
v_4771:
    v_4906 = list4(v_4909, v_4908, v_4907, v_4906);
    env = stack[-3];
    fn = elt(env, 8); // cerror
    v_4906 = (*qfn1(fn))(fn, v_4906);
    env = stack[-3];
    goto v_4758;
v_4760:
v_4758:
    v_4906 = stack[-2];
    v_4906 = qcar(v_4906);
    stack[-2] = v_4906;
    goto v_4795;
v_4791:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4907 = qcar(v_4906);
    goto v_4792;
v_4793:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcar(v_4906);
    goto v_4794;
v_4795:
    goto v_4791;
v_4792:
    goto v_4793;
v_4794:
    if (v_4907 == v_4906) goto v_4789;
    else goto v_4790;
v_4789:
    v_4906 = lisp_true;
    goto v_4788;
v_4790:
    goto v_4814;
v_4810:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4907 = qcar(v_4906);
    goto v_4811;
v_4812:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcar(v_4906);
    goto v_4813;
v_4814:
    goto v_4810;
v_4811:
    goto v_4812;
v_4813:
    if (v_4907 == v_4906) goto v_4808;
    else goto v_4809;
v_4808:
    v_4906 = lisp_true;
    goto v_4807;
v_4809:
    goto v_4830;
v_4826:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4907 = qcar(v_4906);
    goto v_4827;
v_4828:
    v_4906 = stack[-2];
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcdr(v_4906);
    v_4906 = qcar(v_4906);
    goto v_4829;
v_4830:
    goto v_4826;
v_4827:
    goto v_4828;
v_4829:
    v_4906 = (v_4907 == v_4906 ? lisp_true : nil);
    goto v_4807;
    v_4906 = nil;
v_4807:
    goto v_4788;
    v_4906 = nil;
v_4788:
    if (v_4906 == nil) goto v_4786;
    goto v_4848;
v_4844:
    v_4907 = nil;
    goto v_4845;
v_4846:
    v_4906 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4847;
v_4848:
    goto v_4844;
v_4845:
    goto v_4846;
v_4847:
    v_4906 = cons(v_4907, v_4906);
    env = stack[-3];
    v_4906 = ncons(v_4906);
    return ncons(v_4906);
v_4786:
    goto v_4859;
v_4855:
    v_4906 = stack[-2];
    v_4907 = qcar(v_4906);
    goto v_4856;
v_4857:
    v_4906 = elt(env, 4); // qg
    goto v_4858;
v_4859:
    goto v_4855;
v_4856:
    goto v_4857;
v_4858:
    if (v_4907 == v_4906) goto v_4853;
    else goto v_4854;
v_4853:
    goto v_4870;
v_4864:
    v_4908 = stack[-1];
    goto v_4865;
v_4866:
    v_4907 = stack[0];
    goto v_4867;
v_4868:
    v_4906 = stack[-2];
    goto v_4869;
v_4870:
    goto v_4864;
v_4865:
    goto v_4866;
v_4867:
    goto v_4868;
v_4869:
    {
        fn = elt(env, 9); // removeg1
        return (*qfnn(fn))(fn, 3, v_4908, v_4907, v_4906);
    }
v_4854:
    goto v_4880;
v_4876:
    v_4906 = stack[-2];
    v_4907 = qcar(v_4906);
    goto v_4877;
v_4878:
    v_4906 = elt(env, 5); // g3
    goto v_4879;
v_4880:
    goto v_4876;
v_4877:
    goto v_4878;
v_4879:
    if (v_4907 == v_4906) goto v_4874;
    else goto v_4875;
v_4874:
    goto v_4891;
v_4885:
    v_4908 = stack[-1];
    goto v_4886;
v_4887:
    v_4907 = stack[0];
    goto v_4888;
v_4889:
    v_4906 = stack[-2];
    goto v_4890;
v_4891:
    goto v_4885;
v_4886:
    goto v_4887;
v_4888:
    goto v_4889;
v_4890:
    {
        fn = elt(env, 10); // removeg2
        return (*qfnn(fn))(fn, 3, v_4908, v_4907, v_4906);
    }
v_4875:
    goto v_4903;
v_4899:
    v_4907 = elt(env, 6); // "Invalid type of vertex"
    goto v_4900;
v_4901:
    v_4906 = stack[0];
    goto v_4902;
v_4903:
    goto v_4899;
v_4900:
    goto v_4901;
v_4902:
    v_4906 = list2(v_4907, v_4906);
    env = stack[-3];
    fn = elt(env, 8); // cerror
    v_4906 = (*qfn1(fn))(fn, v_4906);
    goto v_4852;
v_4852:
    v_4906 = nil;
    return onevalue(v_4906);
}



// Code for poly!-abs

static LispObject CC_polyKabs(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    v_4725 = stack[0];
    fn = elt(env, 1); // poly!-minusp
    v_4725 = (*qfn1(fn))(fn, v_4725);
    env = stack[-1];
    if (v_4725 == nil) goto v_4717;
    v_4725 = stack[0];
    {
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(fn, v_4725);
    }
v_4717:
    v_4725 = stack[0];
    goto v_4715;
    v_4725 = nil;
v_4715:
    return onevalue(v_4725);
}



// Code for talp_acfrp

static LispObject CC_talp_acfrp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    v_4723 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_4723 = (*qfn1(fn))(fn, v_4723);
    env = stack[-1];
    fn = elt(env, 2); // talp_tcfrp
    v_4723 = (*qfn1(fn))(fn, v_4723);
    env = stack[-1];
    if (v_4723 == nil) goto v_4716;
    else goto v_4715;
v_4716:
    v_4723 = stack[0];
    fn = elt(env, 3); // talp_arg2r
    v_4723 = (*qfn1(fn))(fn, v_4723);
    env = stack[-1];
    {
        fn = elt(env, 2); // talp_tcfrp
        return (*qfn1(fn))(fn, v_4723);
    }
v_4715:
    return onevalue(v_4723);
}



// Code for searchpl

static LispObject CC_searchpl(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4766, v_4767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    stack[-1] = nil;
v_4718:
    v_4766 = stack[0];
    if (!consp(v_4766)) goto v_4727;
    else goto v_4728;
v_4727:
    v_4766 = lisp_true;
    goto v_4726;
v_4728:
    v_4766 = stack[0];
    v_4766 = qcar(v_4766);
    v_4766 = (consp(v_4766) ? nil : lisp_true);
    goto v_4726;
    v_4766 = nil;
v_4726:
    if (v_4766 == nil) goto v_4724;
    goto v_4719;
v_4724:
    goto v_4741;
v_4737:
    v_4766 = stack[0];
    v_4766 = qcar(v_4766);
    fn = elt(env, 1); // searchtm
    v_4767 = (*qfn1(fn))(fn, v_4766);
    env = stack[-2];
    goto v_4738;
v_4739:
    v_4766 = stack[-1];
    goto v_4740;
v_4741:
    goto v_4737;
v_4738:
    goto v_4739;
v_4740:
    v_4766 = cons(v_4767, v_4766);
    env = stack[-2];
    stack[-1] = v_4766;
    v_4766 = stack[0];
    v_4766 = qcdr(v_4766);
    stack[0] = v_4766;
    goto v_4718;
v_4719:
    v_4766 = nil;
    v_4767 = v_4766;
v_4720:
    v_4766 = stack[-1];
    if (v_4766 == nil) goto v_4751;
    else goto v_4752;
v_4751:
    v_4766 = v_4767;
    goto v_4717;
v_4752:
    goto v_4760;
v_4756:
    v_4766 = stack[-1];
    v_4766 = qcar(v_4766);
    goto v_4757;
v_4758:
    goto v_4759;
v_4760:
    goto v_4756;
v_4757:
    goto v_4758;
v_4759:
    fn = elt(env, 2); // setunion
    v_4766 = (*qfn2(fn))(fn, v_4766, v_4767);
    env = stack[-2];
    v_4767 = v_4766;
    v_4766 = stack[-1];
    v_4766 = qcdr(v_4766);
    stack[-1] = v_4766;
    goto v_4720;
v_4717:
    return onevalue(v_4766);
}



// Code for ibalp_litlp

static LispObject CC_ibalp_litlp(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
v_4711:
    v_4735 = stack[0];
    if (v_4735 == nil) goto v_4716;
    else goto v_4717;
v_4716:
    v_4735 = lisp_true;
    goto v_4715;
v_4717:
    v_4735 = stack[0];
    v_4735 = qcar(v_4735);
    fn = elt(env, 1); // ibalp_litp
    v_4735 = (*qfn1(fn))(fn, v_4735);
    env = stack[-1];
    if (v_4735 == nil) goto v_4724;
    else goto v_4725;
v_4724:
    v_4735 = nil;
    goto v_4723;
v_4725:
    v_4735 = stack[0];
    v_4735 = qcdr(v_4735);
    stack[0] = v_4735;
    goto v_4711;
    v_4735 = nil;
v_4723:
    goto v_4715;
    v_4735 = nil;
v_4715:
    return onevalue(v_4735);
}



// Code for dip_moncomp

static LispObject CC_dip_moncomp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4727, v_4728, v_4729;
    LispObject v_4714, v_4713, v_4712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip_moncomp");
    va_start(aa, nargs);
    v_4712 = va_arg(aa, LispObject);
    v_4713 = va_arg(aa, LispObject);
    v_4714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_4727 = v_4714;
    v_4728 = v_4713;
    v_4729 = v_4712;
// end of prologue
    goto v_4723;
v_4717:
    goto v_4718;
v_4719:
    goto v_4720;
v_4721:
    goto v_4722;
v_4723:
    goto v_4717;
v_4718:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    return list2star(v_4728, v_4729, v_4727);
}



// Code for spmultm2

static LispObject CC_spmultm2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4972, v_4973, v_4974, v_4975;
    LispObject fn;
    LispObject v_4714, v_4713, v_4712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "spmultm2");
    va_start(aa, nargs);
    v_4712 = va_arg(aa, LispObject);
    v_4713 = va_arg(aa, LispObject);
    v_4714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4714,v_4713,v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4712,v_4713,v_4714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    v_4972 = v_4714;
    stack[-10] = v_4713;
    stack[-11] = v_4712;
// end of prologue
    goto v_4734;
v_4730:
    v_4973 = v_4972;
    v_4973 = qcdr(v_4973);
    v_4973 = qcar(v_4973);
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    goto v_4730;
v_4731:
    goto v_4732;
v_4733:
    fn = elt(env, 2); // mkempspmat
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    stack[-12] = v_4972;
    goto v_4752;
v_4748:
    v_4972 = stack[-11];
    v_4972 = qcdr(v_4972);
    v_4973 = qcar(v_4972);
    goto v_4749;
v_4750:
    v_4972 = stack[-11];
    v_4972 = qcdr(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    goto v_4751;
v_4752:
    goto v_4748;
v_4749:
    goto v_4750;
v_4751:
    fn = elt(env, 3); // empty
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    if (v_4972 == nil) goto v_4745;
    else goto v_4746;
v_4745:
    v_4972 = lisp_true;
    goto v_4744;
v_4746:
    goto v_4770;
v_4766:
    v_4972 = stack[-10];
    v_4972 = qcdr(v_4972);
    v_4973 = qcar(v_4972);
    goto v_4767;
v_4768:
    v_4972 = stack[-10];
    v_4972 = qcdr(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    goto v_4769;
v_4770:
    goto v_4766;
v_4767:
    goto v_4768;
v_4769:
    fn = elt(env, 3); // empty
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    v_4972 = (v_4972 == nil ? lisp_true : nil);
    goto v_4744;
    v_4972 = nil;
v_4744:
    if (v_4972 == nil) goto v_4742;
    v_4972 = stack[-12];
    goto v_4727;
v_4742:
    v_4972 = stack[-11];
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    stack[-9] = v_4972;
    v_4972 = stack[-10];
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    stack[-8] = v_4972;
    v_4972 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_4972;
v_4793:
    goto v_4805;
v_4801:
    v_4972 = stack[-11];
    v_4972 = qcdr(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    v_4972 = qcdr(v_4972);
    v_4973 = qcar(v_4972);
    goto v_4802;
v_4803:
    v_4972 = stack[-3];
    goto v_4804;
v_4805:
    goto v_4801;
v_4802:
    goto v_4803;
v_4804:
    v_4972 = difference2(v_4973, v_4972);
    env = stack[-13];
    v_4972 = Lminusp(nil, v_4972);
    env = stack[-13];
    if (v_4972 == nil) goto v_4798;
    goto v_4792;
v_4798:
    goto v_4819;
v_4815:
    v_4973 = stack[-9];
    goto v_4816;
v_4817:
    v_4972 = stack[-3];
    goto v_4818;
v_4819:
    goto v_4815;
v_4816:
    goto v_4817;
v_4818:
    fn = elt(env, 4); // findrow
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    stack[-7] = v_4972;
    v_4972 = stack[-7];
    if (v_4972 == nil) goto v_4825;
    v_4972 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_4972;
v_4830:
    goto v_4842;
v_4838:
    v_4972 = stack[-10];
    v_4972 = qcdr(v_4972);
    v_4972 = qcdr(v_4972);
    v_4972 = qcar(v_4972);
    v_4972 = qcdr(v_4972);
    v_4973 = qcar(v_4972);
    goto v_4839;
v_4840:
    v_4972 = stack[-2];
    goto v_4841;
v_4842:
    goto v_4838;
v_4839:
    goto v_4840;
v_4841:
    v_4972 = difference2(v_4973, v_4972);
    env = stack[-13];
    v_4972 = Lminusp(nil, v_4972);
    env = stack[-13];
    if (v_4972 == nil) goto v_4835;
    goto v_4829;
v_4835:
    goto v_4856;
v_4852:
    v_4973 = stack[-8];
    goto v_4853;
v_4854:
    v_4972 = stack[-2];
    goto v_4855;
v_4856:
    goto v_4852;
v_4853:
    goto v_4854;
v_4855:
    fn = elt(env, 4); // findrow
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    stack[-6] = v_4972;
    v_4972 = stack[-6];
    if (v_4972 == nil) goto v_4862;
    v_4972 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 5); // simp
    v_4972 = (*qfn1(fn))(fn, v_4972);
    env = stack[-13];
    stack[-4] = v_4972;
    v_4972 = stack[-7];
    v_4972 = qcdr(v_4972);
    stack[-1] = v_4972;
v_4869:
    v_4972 = stack[-1];
    if (v_4972 == nil) goto v_4874;
    else goto v_4875;
v_4874:
    goto v_4868;
v_4875:
    v_4972 = stack[-1];
    v_4972 = qcar(v_4972);
    v_4973 = v_4972;
    v_4972 = v_4973;
    v_4972 = qcar(v_4972);
    v_4973 = qcdr(v_4973);
    v_4974 = v_4973;
    goto v_4889;
v_4885:
    v_4973 = v_4972;
    goto v_4886;
v_4887:
    v_4972 = stack[-6];
    goto v_4888;
v_4889:
    goto v_4885;
v_4886:
    goto v_4887;
v_4888:
    v_4972 = Latsoc(nil, v_4973, v_4972);
    stack[-5] = v_4972;
    v_4972 = stack[-5];
    if (v_4972 == nil) goto v_4896;
    v_4972 = stack[-5];
    v_4972 = qcdr(v_4972);
    stack[-5] = v_4972;
    goto v_4905;
v_4901:
    v_4972 = v_4974;
    fn = elt(env, 5); // simp
    stack[0] = (*qfn1(fn))(fn, v_4972);
    env = stack[-13];
    goto v_4902;
v_4903:
    v_4972 = stack[-5];
    fn = elt(env, 5); // simp
    v_4972 = (*qfn1(fn))(fn, v_4972);
    env = stack[-13];
    goto v_4904;
v_4905:
    goto v_4901;
v_4902:
    goto v_4903;
v_4904:
    fn = elt(env, 6); // multsq
    v_4972 = (*qfn2(fn))(fn, stack[0], v_4972);
    env = stack[-13];
    stack[0] = v_4972;
    goto v_4915;
v_4911:
    v_4973 = stack[-4];
    goto v_4912;
v_4913:
    v_4972 = stack[0];
    goto v_4914;
v_4915:
    goto v_4911;
v_4912:
    goto v_4913;
v_4914:
    fn = elt(env, 7); // addsq
    v_4972 = (*qfn2(fn))(fn, v_4973, v_4972);
    env = stack[-13];
    stack[-4] = v_4972;
    goto v_4894;
v_4896:
    v_4972 = stack[-4];
    stack[-4] = v_4972;
    goto v_4894;
v_4894:
    v_4972 = stack[-1];
    v_4972 = qcdr(v_4972);
    stack[-1] = v_4972;
    goto v_4869;
v_4868:
    v_4972 = stack[-4];
    fn = elt(env, 8); // mk!*sq
    v_4972 = (*qfn1(fn))(fn, v_4972);
    env = stack[-13];
    stack[0] = v_4972;
    goto v_4935;
v_4931:
    v_4973 = stack[0];
    goto v_4932;
v_4933:
    v_4972 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4934;
v_4935:
    goto v_4931;
v_4932:
    goto v_4933;
v_4934:
    if (v_4973 == v_4972) goto v_4930;
    goto v_4947;
v_4939:
    goto v_4955;
v_4949:
    v_4974 = stack[-12];
    goto v_4950;
v_4951:
    v_4973 = stack[-3];
    goto v_4952;
v_4953:
    v_4972 = stack[-2];
    goto v_4954;
v_4955:
    goto v_4949;
v_4950:
    goto v_4951;
v_4952:
    goto v_4953;
v_4954:
    v_4975 = list3(v_4974, v_4973, v_4972);
    env = stack[-13];
    goto v_4940;
v_4941:
    v_4974 = stack[0];
    goto v_4942;
v_4943:
    v_4973 = stack[-12];
    goto v_4944;
v_4945:
    v_4972 = nil;
    goto v_4946;
v_4947:
    goto v_4939;
v_4940:
    goto v_4941;
v_4942:
    goto v_4943;
v_4944:
    goto v_4945;
v_4946:
    fn = elt(env, 9); // letmtr3
    v_4972 = (*qfnn(fn))(fn, 4, v_4975, v_4974, v_4973, v_4972);
    env = stack[-13];
    goto v_4928;
v_4930:
v_4928:
    goto v_4860;
v_4862:
v_4860:
    v_4972 = stack[-2];
    v_4972 = add1(v_4972);
    env = stack[-13];
    stack[-2] = v_4972;
    goto v_4830;
v_4829:
    goto v_4823;
v_4825:
v_4823:
    v_4972 = stack[-3];
    v_4972 = add1(v_4972);
    env = stack[-13];
    stack[-3] = v_4972;
    goto v_4793;
v_4792:
    v_4972 = stack[-12];
    goto v_4727;
    v_4972 = nil;
v_4727:
    return onevalue(v_4972);
}



// Code for testred

static LispObject CC_testred(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4848, v_4849, v_4850;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    goto v_4723;
v_4719:
    goto v_4728;
v_4724:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4725;
v_4726:
    goto v_4735;
v_4731:
    v_4849 = qvalue(elt(env, 2)); // maxvar
    goto v_4732;
v_4733:
    v_4848 = stack[0];
    goto v_4734;
v_4735:
    goto v_4731;
v_4732:
    goto v_4733;
v_4734:
    v_4848 = plus2(v_4849, v_4848);
    env = stack[-2];
    goto v_4727;
v_4728:
    goto v_4724;
v_4725:
    goto v_4726;
v_4727:
    v_4849 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    goto v_4720;
v_4721:
    v_4848 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4722;
v_4723:
    goto v_4719;
v_4720:
    goto v_4721;
v_4722:
    v_4848 = *(LispObject *)((char *)v_4849 + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    if (v_4848 == nil) goto v_4717;
    goto v_4747;
v_4743:
    goto v_4752;
v_4748:
    goto v_4757;
v_4753:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4754;
v_4755:
    goto v_4764;
v_4760:
    v_4849 = qvalue(elt(env, 2)); // maxvar
    goto v_4761;
v_4762:
    v_4848 = stack[0];
    goto v_4763;
v_4764:
    goto v_4760;
v_4761:
    goto v_4762;
v_4763:
    v_4848 = plus2(v_4849, v_4848);
    env = stack[-2];
    goto v_4756;
v_4757:
    goto v_4753;
v_4754:
    goto v_4755;
v_4756:
    v_4849 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    goto v_4749;
v_4750:
    v_4848 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4751;
v_4752:
    goto v_4748;
v_4749:
    goto v_4750;
v_4751:
    v_4848 = *(LispObject *)((char *)v_4849 + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    v_4848 = qcar(v_4848);
    v_4849 = qcar(v_4848);
    goto v_4744;
v_4745:
    v_4848 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_4746;
v_4747:
    goto v_4743;
v_4744:
    goto v_4745;
v_4746:
    v_4848 = (LispObject)lessp2(v_4849, v_4848);
    v_4848 = v_4848 ? lisp_true : nil;
    env = stack[-2];
    if (v_4848 == nil) goto v_4717;
    goto v_4779;
v_4773:
    goto v_4784;
v_4780:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4781;
v_4782:
    goto v_4791;
v_4787:
    v_4849 = qvalue(elt(env, 2)); // maxvar
    goto v_4788;
v_4789:
    v_4848 = stack[0];
    goto v_4790;
v_4791:
    goto v_4787;
v_4788:
    goto v_4789;
v_4790:
    v_4848 = plus2(v_4849, v_4848);
    env = stack[-2];
    goto v_4783;
v_4784:
    goto v_4780;
v_4781:
    goto v_4782;
v_4783:
    v_4850 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    goto v_4774;
v_4775:
    v_4849 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_4776;
v_4777:
    v_4848 = nil;
    goto v_4778;
v_4779:
    goto v_4773;
v_4774:
    goto v_4775;
v_4776:
    goto v_4777;
v_4778:
    *(LispObject *)((char *)v_4850 + (CELL-TAG_VECTOR) + (((intptr_t)v_4849-TAG_FIXNUM)/(16/CELL))) = v_4848;
    goto v_4805;
v_4801:
    goto v_4810;
v_4806:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_4807;
v_4808:
    goto v_4817;
v_4813:
    v_4849 = qvalue(elt(env, 2)); // maxvar
    goto v_4814;
v_4815:
    v_4848 = stack[0];
    goto v_4816;
v_4817:
    goto v_4813;
v_4814:
    goto v_4815;
v_4816:
    v_4848 = plus2(v_4849, v_4848);
    env = stack[-2];
    goto v_4809;
v_4810:
    goto v_4806;
v_4807:
    goto v_4808;
v_4809:
    v_4849 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    goto v_4802;
v_4803:
    v_4848 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_4804;
v_4805:
    goto v_4801;
v_4802:
    goto v_4803;
v_4804:
    v_4848 = *(LispObject *)((char *)v_4849 + (CELL-TAG_VECTOR) + (((intptr_t)v_4848-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_4848;
v_4800:
    v_4848 = stack[-1];
    if (v_4848 == nil) goto v_4825;
    else goto v_4826;
v_4825:
    v_4848 = nil;
    goto v_4799;
v_4826:
    v_4848 = stack[-1];
    v_4848 = qcar(v_4848);
    stack[0] = v_4848;
    goto v_4837;
v_4833:
    v_4848 = stack[0];
    v_4849 = qcar(v_4848);
    goto v_4834;
v_4835:
    v_4848 = stack[0];
    v_4848 = qcdr(v_4848);
    v_4848 = qcar(v_4848);
    goto v_4836;
v_4837:
    goto v_4833;
v_4834:
    goto v_4835;
v_4836:
    fn = elt(env, 3); // downwght1
    v_4848 = (*qfn2(fn))(fn, v_4849, v_4848);
    env = stack[-2];
    v_4848 = stack[0];
    v_4848 = qcar(v_4848);
    v_4848 = CC_testred(elt(env, 0), v_4848);
    env = stack[-2];
    v_4848 = stack[-1];
    v_4848 = qcdr(v_4848);
    stack[-1] = v_4848;
    goto v_4800;
v_4799:
    goto v_4715;
v_4717:
    v_4848 = nil;
v_4715:
    return onevalue(v_4848);
}



// Code for ident

static LispObject CC_ident(LispObject env,
                         LispObject v_4713)
{
    env = qenv(env);
    LispObject v_4727, v_4728;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4713);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4713);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_4727 = v_4713;
// end of prologue
// Binding op
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_4727; // op
    goto v_4724;
v_4720:
    v_4728 = qvalue(elt(env, 1)); // op
    goto v_4721;
v_4722:
    v_4727 = elt(env, 2); // identity
    goto v_4723;
v_4724:
    goto v_4720;
v_4721:
    goto v_4722;
v_4723:
    v_4727 = get(v_4728, v_4727);
    ;}  // end of a binding scope
    return onevalue(v_4727);
}



// Code for off_mod_reval

static LispObject CC_off_mod_reval(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4736;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4712;
// end of prologue
    v_4736 = qvalue(elt(env, 1)); // !*modular
    if (v_4736 == nil) goto v_4720;
    v_4736 = elt(env, 2); // modular
    v_4736 = ncons(v_4736);
    env = stack[-1];
    fn = elt(env, 3); // off
    v_4736 = (*qfn1(fn))(fn, v_4736);
    env = stack[-1];
    v_4736 = stack[0];
    fn = elt(env, 4); // reval
    v_4736 = (*qfn1(fn))(fn, v_4736);
    env = stack[-1];
    stack[0] = v_4736;
    v_4736 = elt(env, 2); // modular
    v_4736 = ncons(v_4736);
    env = stack[-1];
    fn = elt(env, 5); // on
    v_4736 = (*qfn1(fn))(fn, v_4736);
    goto v_4718;
v_4720:
    v_4736 = stack[0];
    fn = elt(env, 4); // reval
    v_4736 = (*qfn1(fn))(fn, v_4736);
    stack[0] = v_4736;
    goto v_4718;
v_4718:
    v_4736 = stack[0];
    return onevalue(v_4736);
}



// Code for statep!*

static LispObject CC_statepH(LispObject env,
                         LispObject v_4712)
{
    env = qenv(env);
    LispObject v_4723, v_4724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_4712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_4723 = v_4712;
// end of prologue
    goto v_4718;
v_4714:
    fn = elt(env, 2); // getphystype
    v_4723 = (*qfn1(fn))(fn, v_4723);
    env = stack[0];
    goto v_4715;
v_4716:
    v_4724 = elt(env, 1); // state
    goto v_4717;
v_4718:
    goto v_4714;
v_4715:
    goto v_4716;
v_4717:
    v_4723 = (v_4723 == v_4724 ? lisp_true : nil);
    return onevalue(v_4723);
}



setup_type const u10_setup[] =
{
    {"pneg",                    CC_pneg,        TOO_MANY_1,    WRONG_NO_1},
    {"gintequiv:",              CC_gintequivT,  TOO_MANY_1,    WRONG_NO_1},
    {"carx",                    TOO_FEW_2,      CC_carx,       WRONG_NO_2},
    {"xread",                   CC_xread,       TOO_MANY_1,    WRONG_NO_1},
    {"prepsq*2",                CC_prepsqH2,    TOO_MANY_1,    WRONG_NO_1},
    {"comfac",                  CC_comfac,      TOO_MANY_1,    WRONG_NO_1},
    {"freevarinexptchk",        CC_freevarinexptchk,TOO_MANY_1,WRONG_NO_1},
    {"talp_simplat2",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplat2},
    {"searchtm",                CC_searchtm,    TOO_MANY_1,    WRONG_NO_1},
    {"quotk",                   TOO_FEW_2,      CC_quotk,      WRONG_NO_2},
    {"isarb_compl",             CC_isarb_compl, TOO_MANY_1,    WRONG_NO_1},
    {"equal:",                  TOO_FEW_2,      CC_equalT,     WRONG_NO_2},
    {"simpindexvar",            CC_simpindexvar,TOO_MANY_1,    WRONG_NO_1},
    {"sfpx",                    CC_sfpx,        TOO_MANY_1,    WRONG_NO_1},
    {"kernp",                   CC_kernp,       TOO_MANY_1,    WRONG_NO_1},
    {"exptf1",                  TOO_FEW_2,      CC_exptf1,     WRONG_NO_2},
    {"aex_simpleratp",          CC_aex_simpleratp,TOO_MANY_1,  WRONG_NO_1},
    {"wuorderp",                TOO_FEW_2,      CC_wuorderp,   WRONG_NO_2},
    {"talp_ordatp",             TOO_FEW_2,      CC_talp_ordatp,WRONG_NO_2},
    {"ibalp_varlt1",            TOO_FEW_2,      CC_ibalp_varlt1,WRONG_NO_2},
    {"multiom",                 CC_multiom,     TOO_MANY_1,    WRONG_NO_1},
    {"symtabget",               TOO_FEW_2,      CC_symtabget,  WRONG_NO_2},
    {"covposp",                 CC_covposp,     TOO_MANY_1,    WRONG_NO_1},
    {"take-realpart",           CC_takeKrealpart,TOO_MANY_1,   WRONG_NO_1},
    {"add2inputbuf",            TOO_FEW_2,      CC_add2inputbuf,WRONG_NO_2},
    {"mv-pow-+",                TOO_FEW_2,      CC_mvKpowKL,   WRONG_NO_2},
    {"conv:bf2i",               CC_convTbf2i,   TOO_MANY_1,    WRONG_NO_1},
    {"gionep:",                 CC_gionepT,     TOO_MANY_1,    WRONG_NO_1},
    {"valid_as_variable",       CC_valid_as_variable,TOO_MANY_1,WRONG_NO_1},
    {"wulessp*",                TOO_FEW_2,      CC_wulesspH,   WRONG_NO_2},
    {"matrix+p",                CC_matrixLp,    TOO_MANY_1,    WRONG_NO_1},
    {"cl_fvarl1",               CC_cl_fvarl1,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_istotal",           CC_ibalp_istotal,TOO_MANY_1,   WRONG_NO_1},
    {"initbrsea",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_initbrsea},
    {"dim<deg",                 CC_dimRdeg,     TOO_MANY_1,    WRONG_NO_1},
    {"opnum*",                  CC_opnumH,      TOO_MANY_1,    WRONG_NO_1},
    {"take-impart",             CC_takeKimpart, TOO_MANY_1,    WRONG_NO_1},
    {"token1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_token1},
    {"cali_bc_fi",              CC_cali_bc_fi,  TOO_MANY_1,    WRONG_NO_1},
    {"maprint",                 TOO_FEW_2,      CC_maprint,    WRONG_NO_2},
    {"mapcons",                 TOO_FEW_2,      CC_mapcons,    WRONG_NO_2},
    {"qcputx",                  CC_qcputx,      TOO_MANY_1,    WRONG_NO_1},
    {"rmplus",                  CC_rmplus,      TOO_MANY_1,    WRONG_NO_1},
    {"removeg",                 TOO_FEW_2,      CC_removeg,    WRONG_NO_2},
    {"poly-abs",                CC_polyKabs,    TOO_MANY_1,    WRONG_NO_1},
    {"talp_acfrp",              CC_talp_acfrp,  TOO_MANY_1,    WRONG_NO_1},
    {"searchpl",                CC_searchpl,    TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_litlp",             CC_ibalp_litlp, TOO_MANY_1,    WRONG_NO_1},
    {"dip_moncomp",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_moncomp},
    {"spmultm2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_spmultm2},
    {"testred",                 CC_testred,     TOO_MANY_1,    WRONG_NO_1},
    {"ident",                   CC_ident,       TOO_MANY_1,    WRONG_NO_1},
    {"off_mod_reval",           CC_off_mod_reval,TOO_MANY_1,   WRONG_NO_1},
    {"statep*",                 CC_statepH,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u10", (two_args *)"149510 4220126 2656137", 0}
};

// end of generated code
