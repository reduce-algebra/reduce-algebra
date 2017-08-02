
// $destdir/u33.c        Machine generated C code

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



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17241, v_17242, v_17243;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17130,v_17131);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_17131;
    stack[-4] = v_17130;
// end of prologue
    stack[-5] = nil;
    goto v_17148;
v_17144:
    v_17242 = stack[-3];
    goto v_17145;
v_17146:
    v_17241 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17147;
v_17148:
    goto v_17144;
v_17145:
    goto v_17146;
v_17147:
    if (v_17242 == v_17241) goto v_17142;
    else goto v_17143;
v_17142:
    v_17241 = nil;
    return ncons(v_17241);
v_17143:
    goto v_17160;
v_17156:
    goto v_17166;
v_17162:
    v_17241 = stack[-4];
    v_17242 = Llength(nil, v_17241);
    env = stack[-6];
    goto v_17163;
v_17164:
    v_17241 = stack[-3];
    goto v_17165;
v_17166:
    goto v_17162;
v_17163:
    goto v_17164;
v_17165:
    v_17242 = difference2(v_17242, v_17241);
    env = stack[-6];
    stack[-2] = v_17242;
    goto v_17157;
v_17158:
    v_17241 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17159;
v_17160:
    goto v_17156;
v_17157:
    goto v_17158;
v_17159:
    v_17241 = (LispObject)lessp2(v_17242, v_17241);
    v_17241 = v_17241 ? lisp_true : nil;
    env = stack[-6];
    if (v_17241 == nil) goto v_17154;
    v_17241 = nil;
    goto v_17137;
v_17154:
    v_17241 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_17241;
v_17175:
    goto v_17187;
v_17183:
    v_17242 = stack[-2];
    goto v_17184;
v_17185:
    v_17241 = stack[-1];
    goto v_17186;
v_17187:
    goto v_17183;
v_17184:
    goto v_17185;
v_17186:
    v_17241 = difference2(v_17242, v_17241);
    env = stack[-6];
    v_17241 = Lminusp(nil, v_17241);
    env = stack[-6];
    if (v_17241 == nil) goto v_17180;
    goto v_17174;
v_17180:
    goto v_17196;
v_17192:
    v_17241 = stack[-4];
    stack[0] = qcdr(v_17241);
    goto v_17193;
v_17194:
    v_17241 = stack[-3];
    v_17241 = sub1(v_17241);
    env = stack[-6];
    goto v_17195;
v_17196:
    goto v_17192;
v_17193:
    goto v_17194;
v_17195:
    v_17241 = CC_comb(elt(env, 0), stack[0], v_17241);
    env = stack[-6];
    stack[0] = v_17241;
v_17204:
    v_17241 = stack[0];
    if (v_17241 == nil) goto v_17208;
    else goto v_17209;
v_17208:
    goto v_17203;
v_17209:
    v_17241 = stack[0];
    v_17241 = qcar(v_17241);
    goto v_17222;
v_17216:
    v_17242 = stack[-4];
    v_17243 = qcar(v_17242);
    goto v_17217;
v_17218:
    v_17242 = v_17241;
    goto v_17219;
v_17220:
    v_17241 = stack[-5];
    goto v_17221;
v_17222:
    goto v_17216;
v_17217:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    v_17241 = acons(v_17243, v_17242, v_17241);
    env = stack[-6];
    stack[-5] = v_17241;
    v_17241 = stack[0];
    v_17241 = qcdr(v_17241);
    stack[0] = v_17241;
    goto v_17204;
v_17203:
    v_17241 = stack[-4];
    v_17241 = qcdr(v_17241);
    stack[-4] = v_17241;
    v_17241 = stack[-1];
    v_17241 = add1(v_17241);
    env = stack[-6];
    stack[-1] = v_17241;
    goto v_17175;
v_17174:
    goto v_17238;
v_17234:
    v_17242 = stack[-4];
    goto v_17235;
v_17236:
    v_17241 = stack[-5];
    goto v_17237;
v_17238:
    goto v_17234;
v_17235:
    goto v_17236;
v_17237:
    return cons(v_17242, v_17241);
v_17137:
    return onevalue(v_17241);
}



// Code for horner!-rule!-for!-one!-var

static LispObject CC_hornerKruleKforKoneKvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17272, v_17273, v_17274, v_17275, v_17276, v_17277, v_17278;
    LispObject fn;
    LispObject v_17134, v_17133, v_17132, v_17131, v_17130;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v_17130 = va_arg(aa, LispObject);
    v_17131 = va_arg(aa, LispObject);
    v_17132 = va_arg(aa, LispObject);
    v_17133 = va_arg(aa, LispObject);
    v_17134 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_17134,v_17133,v_17132,v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_17130,v_17131,v_17132,v_17133,v_17134);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_17273 = v_17134;
    v_17274 = v_17133;
    v_17275 = v_17132;
    v_17276 = v_17131;
    v_17277 = v_17130;
// end of prologue
v_17129:
    v_17272 = v_17277;
    if (!consp(v_17272)) goto v_17146;
    else goto v_17147;
v_17146:
    v_17272 = lisp_true;
    goto v_17145;
v_17147:
    v_17272 = v_17277;
    v_17272 = qcar(v_17272);
    v_17272 = (consp(v_17272) ? nil : lisp_true);
    goto v_17145;
    v_17272 = nil;
v_17145:
    if (v_17272 == nil) goto v_17143;
    v_17272 = lisp_true;
    goto v_17141;
v_17143:
    goto v_17162;
v_17158:
    v_17272 = v_17277;
    v_17272 = qcar(v_17272);
    v_17272 = qcar(v_17272);
    v_17278 = qcar(v_17272);
    goto v_17159;
v_17160:
    v_17272 = v_17276;
    goto v_17161;
v_17162:
    goto v_17158;
v_17159:
    goto v_17160;
v_17161:
    v_17272 = (equal(v_17278, v_17272) ? lisp_true : nil);
    v_17272 = (v_17272 == nil ? lisp_true : nil);
    goto v_17141;
    v_17272 = nil;
v_17141:
    if (v_17272 == nil) goto v_17139;
    v_17272 = v_17275;
    v_17272 = (LispObject)zerop(v_17272);
    v_17272 = v_17272 ? lisp_true : nil;
    env = stack[-6];
    if (v_17272 == nil) goto v_17173;
    v_17272 = v_17277;
    goto v_17171;
v_17173:
    goto v_17184;
v_17180:
    stack[-1] = v_17277;
    goto v_17181;
v_17182:
    goto v_17191;
v_17187:
    stack[0] = v_17274;
    goto v_17188;
v_17189:
    goto v_17199;
v_17195:
    v_17272 = v_17275;
    goto v_17196;
v_17197:
    goto v_17198;
v_17199:
    goto v_17195;
v_17196:
    goto v_17197;
v_17198:
    v_17272 = Lexpt(nil, v_17272, v_17273);
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v_17272 = (*qfn1(fn))(fn, v_17272);
    env = stack[-6];
    goto v_17190;
v_17191:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    fn = elt(env, 3); // multf
    v_17272 = (*qfn2(fn))(fn, stack[0], v_17272);
    env = stack[-6];
    goto v_17183;
v_17184:
    goto v_17180;
v_17181:
    goto v_17182;
v_17183:
    {
        LispObject v_17285 = stack[-1];
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_17285, v_17272);
    }
    v_17272 = nil;
v_17171:
    goto v_17137;
v_17139:
    v_17272 = v_17277;
    v_17272 = qcar(v_17272);
    v_17272 = qcar(v_17272);
    v_17272 = qcdr(v_17272);
    stack[-5] = v_17272;
    goto v_17223;
v_17213:
    v_17272 = v_17277;
    stack[-4] = qcdr(v_17272);
    goto v_17214;
v_17215:
    stack[-3] = v_17276;
    goto v_17216;
v_17217:
    stack[-2] = v_17275;
    goto v_17218;
v_17219:
    v_17272 = v_17275;
    v_17272 = (LispObject)zerop(v_17272);
    v_17272 = v_17272 ? lisp_true : nil;
    env = stack[-6];
    if (v_17272 == nil) goto v_17231;
    v_17272 = v_17277;
    v_17272 = qcar(v_17272);
    v_17272 = qcdr(v_17272);
    v_17273 = v_17272;
    goto v_17229;
v_17231:
    goto v_17244;
v_17240:
    v_17272 = v_17277;
    v_17272 = qcar(v_17272);
    stack[-1] = qcdr(v_17272);
    goto v_17241;
v_17242:
    goto v_17253;
v_17249:
    stack[0] = v_17274;
    goto v_17250;
v_17251:
    goto v_17261;
v_17257:
    v_17274 = v_17275;
    goto v_17258;
v_17259:
    goto v_17267;
v_17263:
    goto v_17264;
v_17265:
    v_17272 = stack[-5];
    goto v_17266;
v_17267:
    goto v_17263;
v_17264:
    goto v_17265;
v_17266:
    v_17272 = (LispObject)(intptr_t)((intptr_t)v_17273 - (intptr_t)v_17272 + TAG_FIXNUM);
    goto v_17260;
v_17261:
    goto v_17257;
v_17258:
    goto v_17259;
v_17260:
    v_17272 = Lexpt(nil, v_17274, v_17272);
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v_17272 = (*qfn1(fn))(fn, v_17272);
    env = stack[-6];
    goto v_17252;
v_17253:
    goto v_17249;
v_17250:
    goto v_17251;
v_17252:
    fn = elt(env, 3); // multf
    v_17272 = (*qfn2(fn))(fn, stack[0], v_17272);
    env = stack[-6];
    goto v_17243;
v_17244:
    goto v_17240;
v_17241:
    goto v_17242;
v_17243:
    fn = elt(env, 4); // addf
    v_17272 = (*qfn2(fn))(fn, stack[-1], v_17272);
    env = stack[-6];
    v_17273 = v_17272;
    goto v_17229;
    v_17273 = nil;
v_17229:
    goto v_17220;
v_17221:
    v_17272 = stack[-5];
    goto v_17222;
v_17223:
    goto v_17213;
v_17214:
    goto v_17215;
v_17216:
    goto v_17217;
v_17218:
    goto v_17219;
v_17220:
    goto v_17221;
v_17222:
    v_17277 = stack[-4];
    v_17276 = stack[-3];
    v_17275 = stack[-2];
    v_17274 = v_17273;
    v_17273 = v_17272;
    goto v_17129;
    goto v_17137;
    v_17272 = nil;
v_17137:
    return onevalue(v_17272);
}



// Code for make!-x!-to!-p

static LispObject CC_makeKxKtoKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17356, v_17357, v_17358, v_17359, v_17360;
    LispObject fn;
    LispObject v_17132, v_17131, v_17130;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-x-to-p");
    va_start(aa, nargs);
    v_17130 = va_arg(aa, LispObject);
    v_17131 = va_arg(aa, LispObject);
    v_17132 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_17132,v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_17130,v_17131,v_17132);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_17132;
    stack[-1] = v_17131;
    stack[-2] = v_17130;
// end of prologue
    goto v_17147;
v_17143:
    v_17357 = stack[-2];
    goto v_17144;
v_17145:
    v_17356 = qvalue(elt(env, 2)); // dpoly
    goto v_17146;
v_17147:
    goto v_17143;
v_17144:
    goto v_17145;
v_17146:
    if (((intptr_t)(v_17357)) < ((intptr_t)(v_17356))) goto v_17141;
    else goto v_17142;
v_17141:
    v_17356 = (LispObject)0+TAG_FIXNUM; // 0
    v_17359 = v_17356;
v_17153:
    goto v_17163;
v_17159:
    v_17356 = stack[-2];
    v_17357 = (LispObject)((intptr_t)(v_17356) - 0x10);
    goto v_17160;
v_17161:
    v_17356 = v_17359;
    goto v_17162;
v_17163:
    goto v_17159;
v_17160:
    goto v_17161;
v_17162:
    v_17356 = (LispObject)(intptr_t)((intptr_t)v_17357 - (intptr_t)v_17356 + TAG_FIXNUM);
    v_17356 = ((intptr_t)(v_17356) < 0 ? lisp_true : nil);
    if (v_17356 == nil) goto v_17158;
    goto v_17152;
v_17158:
    goto v_17176;
v_17170:
    v_17358 = stack[0];
    goto v_17171;
v_17172:
    v_17357 = v_17359;
    goto v_17173;
v_17174:
    v_17356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17175;
v_17176:
    goto v_17170;
v_17171:
    goto v_17172;
v_17173:
    goto v_17174;
v_17175:
    *(LispObject *)((char *)v_17358 + (CELL-TAG_VECTOR) + (((intptr_t)v_17357-TAG_FIXNUM)/(16/CELL))) = v_17356;
    v_17356 = v_17359;
    v_17356 = (LispObject)((intptr_t)(v_17356) + 0x10);
    v_17359 = v_17356;
    goto v_17153;
v_17152:
    goto v_17188;
v_17182:
    v_17358 = stack[0];
    goto v_17183;
v_17184:
    v_17357 = stack[-2];
    goto v_17185;
v_17186:
    v_17356 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17187;
v_17188:
    goto v_17182;
v_17183:
    goto v_17184;
v_17185:
    goto v_17186;
v_17187:
    *(LispObject *)((char *)v_17358 + (CELL-TAG_VECTOR) + (((intptr_t)v_17357-TAG_FIXNUM)/(16/CELL))) = v_17356;
    v_17356 = stack[-2];
    goto v_17137;
v_17142:
    goto v_17200;
v_17194:
    goto v_17206;
v_17202:
    v_17357 = stack[-2];
    goto v_17203;
v_17204:
    v_17356 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17205;
v_17206:
    goto v_17202;
v_17203:
    goto v_17204;
v_17205:
    v_17358 = quot2(v_17357, v_17356);
    env = stack[-4];
    goto v_17195;
v_17196:
    v_17357 = stack[-1];
    goto v_17197;
v_17198:
    v_17356 = stack[0];
    goto v_17199;
v_17200:
    goto v_17194;
v_17195:
    goto v_17196;
v_17197:
    goto v_17198;
v_17199:
    v_17356 = CC_makeKxKtoKp(elt(env, 0), 3, v_17358, v_17357, v_17356);
    env = stack[-4];
    goto v_17222;
v_17212:
    v_17360 = stack[0];
    goto v_17213;
v_17214:
    v_17359 = v_17356;
    goto v_17215;
v_17216:
    v_17358 = stack[0];
    goto v_17217;
v_17218:
    v_17357 = v_17356;
    goto v_17219;
v_17220:
    v_17356 = stack[-1];
    goto v_17221;
v_17222:
    goto v_17212;
v_17213:
    goto v_17214;
v_17215:
    goto v_17216;
v_17217:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    fn = elt(env, 4); // times!-in!-vector
    v_17356 = (*qfnn(fn))(fn, 5, v_17360, v_17359, v_17358, v_17357, v_17356);
    env = stack[-4];
    stack[-3] = v_17356;
    goto v_17237;
v_17229:
    v_17359 = stack[-1];
    goto v_17230;
v_17231:
    v_17358 = stack[-3];
    goto v_17232;
v_17233:
    v_17357 = qvalue(elt(env, 3)); // poly!-vector
    goto v_17234;
v_17235:
    v_17356 = qvalue(elt(env, 2)); // dpoly
    goto v_17236;
v_17237:
    goto v_17229;
v_17230:
    goto v_17231;
v_17232:
    goto v_17233;
v_17234:
    goto v_17235;
v_17236:
    fn = elt(env, 5); // remainder!-in!-vector
    v_17356 = (*qfnn(fn))(fn, 4, v_17359, v_17358, v_17357, v_17356);
    env = stack[-4];
    stack[-3] = v_17356;
    goto v_17250;
v_17246:
    goto v_17256;
v_17252:
    v_17357 = stack[-2];
    goto v_17253;
v_17254:
    v_17356 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17255;
v_17256:
    goto v_17252;
v_17253:
    goto v_17254;
v_17255:
    v_17357 = Liremainder(nil, v_17357, v_17356);
    env = stack[-4];
    goto v_17247;
v_17248:
    v_17356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17249;
v_17250:
    goto v_17246;
v_17247:
    goto v_17248;
v_17249:
    if (v_17357 == v_17356) goto v_17245;
    v_17356 = stack[-3];
    v_17360 = v_17356;
v_17263:
    v_17356 = v_17360;
    v_17356 = ((intptr_t)(v_17356) < 0 ? lisp_true : nil);
    if (v_17356 == nil) goto v_17268;
    goto v_17262;
v_17268:
    goto v_17278;
v_17272:
    v_17359 = stack[-1];
    goto v_17273;
v_17274:
    v_17356 = v_17360;
    v_17358 = (LispObject)((intptr_t)(v_17356) + 0x10);
    goto v_17275;
v_17276:
    goto v_17286;
v_17282:
    v_17357 = stack[-1];
    goto v_17283;
v_17284:
    v_17356 = v_17360;
    goto v_17285;
v_17286:
    goto v_17282;
v_17283:
    goto v_17284;
v_17285:
    v_17356 = *(LispObject *)((char *)v_17357 + (CELL-TAG_VECTOR) + (((intptr_t)v_17356-TAG_FIXNUM)/(16/CELL)));
    goto v_17277;
v_17278:
    goto v_17272;
v_17273:
    goto v_17274;
v_17275:
    goto v_17276;
v_17277:
    *(LispObject *)((char *)v_17359 + (CELL-TAG_VECTOR) + (((intptr_t)v_17358-TAG_FIXNUM)/(16/CELL))) = v_17356;
    v_17356 = v_17360;
    v_17356 = (LispObject)((intptr_t)(v_17356) - 0x10);
    v_17360 = v_17356;
    goto v_17263;
v_17262:
    goto v_17298;
v_17292:
    v_17358 = stack[-1];
    goto v_17293;
v_17294:
    v_17357 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17295;
v_17296:
    v_17356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17297;
v_17298:
    goto v_17292;
v_17293:
    goto v_17294;
v_17295:
    goto v_17296;
v_17297:
    *(LispObject *)((char *)v_17358 + (CELL-TAG_VECTOR) + (((intptr_t)v_17357-TAG_FIXNUM)/(16/CELL))) = v_17356;
    goto v_17311;
v_17303:
    v_17359 = stack[-1];
    goto v_17304;
v_17305:
    v_17356 = stack[-3];
    v_17358 = (LispObject)((intptr_t)(v_17356) + 0x10);
    goto v_17306;
v_17307:
    v_17357 = qvalue(elt(env, 3)); // poly!-vector
    goto v_17308;
v_17309:
    v_17356 = qvalue(elt(env, 2)); // dpoly
    goto v_17310;
v_17311:
    goto v_17303;
v_17304:
    goto v_17305;
v_17306:
    goto v_17307;
v_17308:
    goto v_17309;
v_17310:
    fn = elt(env, 5); // remainder!-in!-vector
    v_17356 = (*qfnn(fn))(fn, 4, v_17359, v_17358, v_17357, v_17356);
    stack[-3] = v_17356;
    goto v_17243;
v_17245:
v_17243:
    v_17356 = (LispObject)0+TAG_FIXNUM; // 0
    v_17360 = v_17356;
v_17320:
    goto v_17330;
v_17326:
    v_17357 = stack[-3];
    goto v_17327;
v_17328:
    v_17356 = v_17360;
    goto v_17329;
v_17330:
    goto v_17326;
v_17327:
    goto v_17328;
v_17329:
    v_17356 = (LispObject)(intptr_t)((intptr_t)v_17357 - (intptr_t)v_17356 + TAG_FIXNUM);
    v_17356 = ((intptr_t)(v_17356) < 0 ? lisp_true : nil);
    if (v_17356 == nil) goto v_17325;
    goto v_17319;
v_17325:
    goto v_17342;
v_17336:
    v_17359 = stack[0];
    goto v_17337;
v_17338:
    v_17358 = v_17360;
    goto v_17339;
v_17340:
    goto v_17349;
v_17345:
    v_17357 = stack[-1];
    goto v_17346;
v_17347:
    v_17356 = v_17360;
    goto v_17348;
v_17349:
    goto v_17345;
v_17346:
    goto v_17347;
v_17348:
    v_17356 = *(LispObject *)((char *)v_17357 + (CELL-TAG_VECTOR) + (((intptr_t)v_17356-TAG_FIXNUM)/(16/CELL)));
    goto v_17341;
v_17342:
    goto v_17336;
v_17337:
    goto v_17338;
v_17339:
    goto v_17340;
v_17341:
    *(LispObject *)((char *)v_17359 + (CELL-TAG_VECTOR) + (((intptr_t)v_17358-TAG_FIXNUM)/(16/CELL))) = v_17356;
    v_17356 = v_17360;
    v_17356 = (LispObject)((intptr_t)(v_17356) + 0x10);
    v_17360 = v_17356;
    goto v_17320;
v_17319:
    v_17356 = stack[-3];
v_17137:
    return onevalue(v_17356);
}



// Code for lalr_process_productions

static LispObject CC_lalr_process_productions(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17321, v_17322, v_17323;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17130,v_17131);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_17131;
    v_17321 = v_17130;
// end of prologue
    stack[-6] = v_17321;
v_17145:
    v_17321 = stack[-6];
    if (v_17321 == nil) goto v_17149;
    else goto v_17150;
v_17149:
    goto v_17144;
v_17150:
    v_17321 = stack[-6];
    v_17321 = qcar(v_17321);
    v_17322 = v_17321;
    v_17321 = v_17322;
    v_17321 = qcar(v_17321);
    stack[-10] = v_17321;
    v_17321 = nil;
    stack[-8] = v_17321;
    v_17321 = v_17322;
    v_17321 = qcdr(v_17321);
    stack[-5] = v_17321;
v_17162:
    v_17321 = stack[-5];
    if (v_17321 == nil) goto v_17167;
    else goto v_17168;
v_17167:
    goto v_17161;
v_17168:
    v_17321 = stack[-5];
    v_17321 = qcar(v_17321);
    v_17322 = v_17321;
    v_17322 = qcar(v_17322);
    v_17321 = qcdr(v_17321);
    stack[-7] = v_17321;
    v_17321 = v_17322;
    stack[-4] = v_17321;
    v_17321 = stack[-4];
    if (v_17321 == nil) goto v_17187;
    else goto v_17188;
v_17187:
    v_17321 = nil;
    goto v_17182;
v_17188:
    v_17321 = stack[-4];
    v_17321 = qcar(v_17321);
    stack[0] = v_17321;
    goto v_17203;
v_17199:
    v_17321 = stack[0];
    v_17322 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17200;
v_17201:
    v_17321 = qvalue(elt(env, 2)); // nonterminals
    goto v_17202;
v_17203:
    goto v_17199;
v_17200:
    goto v_17201;
v_17202:
    v_17321 = Lmember(nil, v_17322, v_17321);
    if (v_17321 == nil) goto v_17198;
    v_17321 = stack[0];
    v_17321 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17196;
v_17198:
    goto v_17217;
v_17213:
    v_17321 = stack[0];
    v_17322 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17214;
v_17215:
    v_17321 = stack[-9];
    goto v_17216;
v_17217:
    goto v_17213;
v_17214:
    goto v_17215;
v_17216:
    fn = elt(env, 4); // carrassoc
    v_17321 = (*qfn2(fn))(fn, v_17322, v_17321);
    env = stack[-11];
    goto v_17196;
    v_17321 = nil;
v_17196:
    v_17321 = ncons(v_17321);
    env = stack[-11];
    stack[-2] = v_17321;
    stack[-3] = v_17321;
v_17183:
    v_17321 = stack[-4];
    v_17321 = qcdr(v_17321);
    stack[-4] = v_17321;
    v_17321 = stack[-4];
    if (v_17321 == nil) goto v_17225;
    else goto v_17226;
v_17225:
    v_17321 = stack[-3];
    goto v_17182;
v_17226:
    goto v_17234;
v_17230:
    stack[-1] = stack[-2];
    goto v_17231;
v_17232:
    v_17321 = stack[-4];
    v_17321 = qcar(v_17321);
    stack[0] = v_17321;
    goto v_17248;
v_17244:
    v_17321 = stack[0];
    v_17322 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17245;
v_17246:
    v_17321 = qvalue(elt(env, 2)); // nonterminals
    goto v_17247;
v_17248:
    goto v_17244;
v_17245:
    goto v_17246;
v_17247:
    v_17321 = Lmember(nil, v_17322, v_17321);
    if (v_17321 == nil) goto v_17243;
    v_17321 = stack[0];
    v_17321 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17241;
v_17243:
    goto v_17262;
v_17258:
    v_17321 = stack[0];
    v_17322 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17259;
v_17260:
    v_17321 = stack[-9];
    goto v_17261;
v_17262:
    goto v_17258;
v_17259:
    goto v_17260;
v_17261:
    fn = elt(env, 4); // carrassoc
    v_17321 = (*qfn2(fn))(fn, v_17322, v_17321);
    env = stack[-11];
    goto v_17241;
    v_17321 = nil;
v_17241:
    v_17321 = ncons(v_17321);
    env = stack[-11];
    goto v_17233;
v_17234:
    goto v_17230;
v_17231:
    goto v_17232;
v_17233:
    v_17321 = Lrplacd(nil, stack[-1], v_17321);
    env = stack[-11];
    v_17321 = stack[-2];
    v_17321 = qcdr(v_17321);
    stack[-2] = v_17321;
    goto v_17183;
v_17182:
    v_17322 = v_17321;
    goto v_17273;
v_17269:
    goto v_17270;
v_17271:
    v_17321 = stack[-7];
    goto v_17272;
v_17273:
    goto v_17269;
v_17270:
    goto v_17271;
v_17272:
    v_17321 = cons(v_17322, v_17321);
    env = stack[-11];
    goto v_17281;
v_17277:
    v_17322 = v_17321;
    goto v_17278;
v_17279:
    v_17321 = stack[-8];
    goto v_17280;
v_17281:
    goto v_17277;
v_17278:
    goto v_17279;
v_17280:
    v_17321 = cons(v_17322, v_17321);
    env = stack[-11];
    stack[-8] = v_17321;
    v_17321 = stack[-5];
    v_17321 = qcdr(v_17321);
    stack[-5] = v_17321;
    goto v_17162;
v_17161:
    goto v_17295;
v_17291:
    v_17321 = stack[-10];
    v_17322 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17292;
v_17293:
    v_17321 = elt(env, 3); // lalr_produces
    goto v_17294;
v_17295:
    goto v_17291;
v_17292:
    goto v_17293;
v_17294:
    v_17321 = get(v_17322, v_17321);
    env = stack[-11];
    v_17322 = v_17321;
    if (v_17321 == nil) goto v_17289;
    goto v_17304;
v_17300:
    goto v_17301;
v_17302:
    v_17321 = stack[-8];
    goto v_17303;
v_17304:
    goto v_17300;
v_17301:
    goto v_17302;
v_17303:
    v_17321 = Lappend(nil, v_17322, v_17321);
    env = stack[-11];
    stack[-8] = v_17321;
    goto v_17287;
v_17289:
v_17287:
    goto v_17314;
v_17308:
    v_17321 = stack[-10];
    v_17323 = Lintern(nil, v_17321);
    env = stack[-11];
    goto v_17309;
v_17310:
    v_17322 = elt(env, 3); // lalr_produces
    goto v_17311;
v_17312:
    v_17321 = stack[-8];
    goto v_17313;
v_17314:
    goto v_17308;
v_17309:
    goto v_17310;
v_17311:
    goto v_17312;
v_17313:
    v_17321 = Lputprop(nil, 3, v_17323, v_17322, v_17321);
    env = stack[-11];
    v_17321 = stack[-6];
    v_17321 = qcdr(v_17321);
    stack[-6] = v_17321;
    goto v_17145;
v_17144:
    v_17321 = nil;
    return onevalue(v_17321);
}



// Code for read_signature

static LispObject CC_read_signature(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17387, v_17388;
    LispObject fn;
    argcheck(nargs, 0, "read_signature");
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
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    stack[-2] = v_17387;
    v_17387 = stack[-2];
    fn = elt(env, 11); // valid_as_variable
    v_17387 = (*qfn1(fn))(fn, v_17387);
    env = stack[-3];
    if (v_17387 == nil) goto v_17139;
    else goto v_17140;
v_17139:
    goto v_17150;
v_17144:
    stack[-1] = elt(env, 3); // rlisp
    goto v_17145;
v_17146:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_17147;
v_17148:
    goto v_17158;
v_17154:
    v_17388 = stack[-2];
    goto v_17155;
v_17156:
    v_17387 = elt(env, 4); // "invalid as formal parameter name"
    goto v_17157;
v_17158:
    goto v_17154;
v_17155:
    goto v_17156;
v_17157:
    v_17387 = list2(v_17388, v_17387);
    env = stack[-3];
    goto v_17149;
v_17150:
    goto v_17144;
v_17145:
    goto v_17146;
v_17147:
    goto v_17148;
v_17149:
    fn = elt(env, 12); // rerror
    v_17387 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_17387);
    env = stack[-3];
    goto v_17138;
v_17140:
v_17138:
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17170;
v_17166:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17167;
v_17168:
    v_17387 = elt(env, 5); // !*semicol!*
    goto v_17169;
v_17170:
    goto v_17166;
v_17167:
    goto v_17168;
v_17169:
    if (v_17388 == v_17387) goto v_17164;
    else goto v_17165;
v_17164:
    goto v_17178;
v_17174:
    v_17387 = stack[-2];
    v_17387 = ncons(v_17387);
    env = stack[-3];
    goto v_17175;
v_17176:
    v_17388 = elt(env, 6); // general
    goto v_17177;
v_17178:
    goto v_17174;
v_17175:
    goto v_17176;
v_17177:
    return list2(v_17387, v_17388);
v_17165:
    goto v_17190;
v_17186:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17187;
v_17188:
    v_17387 = elt(env, 7); // !*colon!*
    goto v_17189;
v_17190:
    goto v_17186;
v_17187:
    goto v_17188;
v_17189:
    if (v_17388 == v_17387) goto v_17184;
    else goto v_17185;
v_17184:
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 14); // read_type
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_17387;
    goto v_17203;
v_17199:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17200;
v_17201:
    v_17387 = elt(env, 5); // !*semicol!*
    goto v_17202;
v_17203:
    goto v_17199;
v_17200:
    goto v_17201;
v_17202:
    if (v_17388 == v_17387) goto v_17197;
    else goto v_17198;
v_17197:
    goto v_17211;
v_17207:
    v_17387 = stack[-2];
    v_17388 = ncons(v_17387);
    goto v_17208;
v_17209:
    v_17387 = stack[0];
    goto v_17210;
v_17211:
    goto v_17207;
v_17208:
    goto v_17209;
v_17210:
    return list2(v_17388, v_17387);
v_17198:
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    if (symbolp(v_17387)) goto v_17220;
    v_17387 = lisp_true;
    goto v_17218;
v_17220:
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    if (!symbolp(v_17387)) v_17387 = nil;
    else { v_17387 = qfastgets(v_17387);
           if (v_17387 != nil) { v_17387 = elt(v_17387, 23); // infix
#ifdef RECORD_GET
             if (v_17387 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_17387 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_17387 == SPID_NOPROP) v_17387 = nil; }}
#endif
    v_17387 = (v_17387 == nil ? lisp_true : nil);
    goto v_17218;
    v_17387 = nil;
v_17218:
    if (v_17387 == nil) goto v_17216;
    goto v_17233;
v_17229:
    v_17388 = nil;
    goto v_17230;
v_17231:
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    goto v_17232;
v_17233:
    goto v_17229;
v_17230:
    goto v_17231;
v_17232:
    fn = elt(env, 15); // symerr
    v_17387 = (*qfn2(fn))(fn, v_17388, v_17387);
    env = stack[-3];
    goto v_17196;
v_17216:
v_17196:
    goto v_17241;
v_17237:
    v_17388 = stack[-2];
    goto v_17238;
v_17239:
    v_17387 = stack[0];
    goto v_17240;
v_17241:
    goto v_17237;
v_17238:
    goto v_17239;
v_17240:
    v_17387 = cons(v_17388, v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    stack[0] = v_17387;
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17253;
v_17247:
    goto v_17248;
v_17249:
    stack[-1] = stack[-2];
    goto v_17250;
v_17251:
    fn = elt(env, 16); // read_typed_name
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17252;
v_17253:
    goto v_17247;
v_17248:
    goto v_17249;
v_17250:
    goto v_17251;
v_17252:
    v_17387 = list3(stack[0], stack[-1], v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    goto v_17183;
v_17185:
    goto v_17263;
v_17259:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17260;
v_17261:
    v_17387 = elt(env, 8); // !*lpar!*
    goto v_17262;
v_17263:
    goto v_17259;
v_17260:
    goto v_17261;
v_17262:
    if (v_17388 == v_17387) goto v_17257;
    else goto v_17258;
v_17257:
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17275;
v_17271:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17272;
v_17273:
    v_17387 = elt(env, 9); // !*rpar!*
    goto v_17274;
v_17275:
    goto v_17271;
v_17272:
    goto v_17273;
v_17274:
    if (v_17388 == v_17387) goto v_17269;
    else goto v_17270;
v_17269:
    v_17387 = stack[-2];
    v_17387 = ncons(v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    goto v_17268;
v_17270:
    goto v_17287;
v_17283:
    stack[0] = stack[-2];
    goto v_17284;
v_17285:
    fn = elt(env, 17); // read_namelist
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17286;
v_17287:
    goto v_17283;
v_17284:
    goto v_17285;
v_17286:
    v_17387 = cons(stack[0], v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    goto v_17298;
v_17294:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17295;
v_17296:
    v_17387 = elt(env, 9); // !*rpar!*
    goto v_17297;
v_17298:
    goto v_17294;
v_17295:
    goto v_17296;
v_17297:
    if (v_17388 == v_17387) goto v_17293;
    goto v_17308;
v_17302:
    stack[-1] = elt(env, 3); // rlisp
    goto v_17303;
v_17304:
    stack[0] = (LispObject)128+TAG_FIXNUM; // 8
    goto v_17305;
v_17306:
    goto v_17316;
v_17312:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17313;
v_17314:
    v_17387 = elt(env, 10); // "found where right parenthesis expected"
    goto v_17315;
v_17316:
    goto v_17312;
v_17313:
    goto v_17314;
v_17315:
    v_17387 = list2(v_17388, v_17387);
    env = stack[-3];
    goto v_17307;
v_17308:
    goto v_17302;
v_17303:
    goto v_17304;
v_17305:
    goto v_17306;
v_17307:
    fn = elt(env, 12); // rerror
    v_17387 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_17387);
    env = stack[-3];
    goto v_17291;
v_17293:
v_17291:
    goto v_17268;
v_17268:
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17183;
v_17258:
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    if (symbolp(v_17387)) goto v_17322;
    else goto v_17321;
v_17322:
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    if (!symbolp(v_17387)) v_17387 = nil;
    else { v_17387 = qfastgets(v_17387);
           if (v_17387 != nil) { v_17387 = elt(v_17387, 23); // infix
#ifdef RECORD_GET
             if (v_17387 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_17387 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_17387 == SPID_NOPROP) v_17387 = nil; }}
#endif
    if (v_17387 == nil) goto v_17321;
    v_17387 = qvalue(elt(env, 2)); // cursym!*
    stack[0] = v_17387;
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17336;
v_17330:
    goto v_17331;
v_17332:
    goto v_17343;
v_17339:
    v_17388 = stack[-2];
    goto v_17340;
v_17341:
    v_17387 = elt(env, 6); // general
    goto v_17342;
v_17343:
    goto v_17339;
v_17340:
    goto v_17341;
v_17342:
    stack[-1] = cons(v_17388, v_17387);
    env = stack[-3];
    goto v_17333;
v_17334:
    fn = elt(env, 16); // read_typed_name
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17335;
v_17336:
    goto v_17330;
v_17331:
    goto v_17332;
v_17333:
    goto v_17334;
v_17335:
    v_17387 = list3(stack[0], stack[-1], v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    goto v_17183;
v_17321:
    goto v_17354;
v_17350:
    stack[0] = stack[-2];
    goto v_17351;
v_17352:
    fn = elt(env, 16); // read_typed_name
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17353;
v_17354:
    goto v_17350;
v_17351:
    goto v_17352;
v_17353:
    v_17387 = list2(stack[0], v_17387);
    env = stack[-3];
    stack[-2] = v_17387;
    goto v_17183;
v_17183:
    goto v_17365;
v_17361:
    v_17388 = qvalue(elt(env, 2)); // cursym!*
    goto v_17362;
v_17363:
    v_17387 = elt(env, 7); // !*colon!*
    goto v_17364;
v_17365:
    goto v_17361;
v_17362:
    goto v_17363;
v_17364:
    if (v_17388 == v_17387) goto v_17359;
    else goto v_17360;
v_17359:
    fn = elt(env, 13); // scan
    v_17387 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17374;
v_17370:
    stack[0] = stack[-2];
    goto v_17371;
v_17372:
    fn = elt(env, 14); // read_type
    v_17387 = (*qfnn(fn))(fn, 0);
    goto v_17373;
v_17374:
    goto v_17370;
v_17371:
    goto v_17372;
v_17373:
    {
        LispObject v_17392 = stack[0];
        return list2(v_17392, v_17387);
    }
v_17360:
    goto v_17384;
v_17380:
    v_17387 = stack[-2];
    goto v_17381;
v_17382:
    v_17388 = elt(env, 6); // general
    goto v_17383;
v_17384:
    goto v_17380;
v_17381:
    goto v_17382;
v_17383:
    return list2(v_17387, v_17388);
    v_17387 = nil;
    return onevalue(v_17387);
}



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17582, v_17583, v_17584, v_17585, v_17586, v_17587;
    LispObject fn;
    LispObject v_17132, v_17131, v_17130;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sisub");
    va_start(aa, nargs);
    v_17130 = va_arg(aa, LispObject);
    v_17131 = va_arg(aa, LispObject);
    v_17132 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_17132,v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_17130,v_17131,v_17132);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_17132;
    stack[-5] = v_17131;
    stack[-1] = v_17130;
// end of prologue
    v_17582 = stack[-1];
    if (!consp(v_17582)) goto v_17140;
    else goto v_17141;
v_17140:
    v_17582 = stack[-1];
    goto v_17139;
v_17141:
    v_17582 = stack[-1];
    v_17582 = qcar(v_17582);
    goto v_17139;
    v_17582 = nil;
v_17139:
    stack[-6] = v_17582;
    goto v_17160;
v_17156:
    v_17583 = stack[-6];
    goto v_17157;
v_17158:
    v_17582 = elt(env, 2); // ex
    goto v_17159;
v_17160:
    goto v_17156;
v_17157:
    goto v_17158;
v_17159:
    if (v_17583 == v_17582) goto v_17154;
    else goto v_17155;
v_17154:
    v_17582 = lisp_true;
    goto v_17153;
v_17155:
    goto v_17170;
v_17166:
    v_17583 = stack[-6];
    goto v_17167;
v_17168:
    v_17582 = elt(env, 3); // all
    goto v_17169;
v_17170:
    goto v_17166;
v_17167:
    goto v_17168;
v_17169:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17153;
    v_17582 = nil;
v_17153:
    if (v_17582 == nil) goto v_17151;
    goto v_17181;
v_17175:
    stack[-2] = stack[-6];
    goto v_17176;
v_17177:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    stack[0] = qcar(v_17582);
    goto v_17178;
v_17179:
    goto v_17193;
v_17187:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    v_17582 = qcdr(v_17582);
    v_17584 = qcar(v_17582);
    goto v_17188;
v_17189:
    v_17583 = stack[-5];
    goto v_17190;
v_17191:
    v_17582 = stack[-4];
    goto v_17192;
v_17193:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    goto v_17191;
v_17192:
    v_17582 = CC_pasf_sisub(elt(env, 0), 3, v_17584, v_17583, v_17582);
    goto v_17180;
v_17181:
    goto v_17175;
v_17176:
    goto v_17177;
v_17178:
    goto v_17179;
v_17180:
    {
        LispObject v_17595 = stack[-2];
        LispObject v_17596 = stack[0];
        return list3(v_17595, v_17596, v_17582);
    }
v_17151:
    goto v_17212;
v_17208:
    v_17583 = stack[-6];
    goto v_17209;
v_17210:
    v_17582 = elt(env, 4); // bex
    goto v_17211;
v_17212:
    goto v_17208;
v_17209:
    goto v_17210;
v_17211:
    if (v_17583 == v_17582) goto v_17206;
    else goto v_17207;
v_17206:
    v_17582 = lisp_true;
    goto v_17205;
v_17207:
    goto v_17222;
v_17218:
    v_17583 = stack[-6];
    goto v_17219;
v_17220:
    v_17582 = elt(env, 5); // ball
    goto v_17221;
v_17222:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17205;
    v_17582 = nil;
v_17205:
    if (v_17582 == nil) goto v_17203;
    goto v_17235;
v_17227:
    stack[-3] = stack[-6];
    goto v_17228;
v_17229:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    stack[-2] = qcar(v_17582);
    goto v_17230;
v_17231:
    goto v_17247;
v_17241:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    v_17582 = qcdr(v_17582);
    v_17584 = qcar(v_17582);
    goto v_17242;
v_17243:
    v_17583 = stack[-5];
    goto v_17244;
v_17245:
    v_17582 = stack[-4];
    goto v_17246;
v_17247:
    goto v_17241;
v_17242:
    goto v_17243;
v_17244:
    goto v_17245;
v_17246:
    stack[0] = CC_pasf_sisub(elt(env, 0), 3, v_17584, v_17583, v_17582);
    env = stack[-7];
    goto v_17232;
v_17233:
    goto v_17261;
v_17255:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    v_17582 = qcdr(v_17582);
    v_17582 = qcdr(v_17582);
    v_17584 = qcar(v_17582);
    goto v_17256;
v_17257:
    v_17583 = stack[-5];
    goto v_17258;
v_17259:
    v_17582 = stack[-4];
    goto v_17260;
v_17261:
    goto v_17255;
v_17256:
    goto v_17257;
v_17258:
    goto v_17259;
v_17260:
    v_17582 = CC_pasf_sisub(elt(env, 0), 3, v_17584, v_17583, v_17582);
    goto v_17234;
v_17235:
    goto v_17227;
v_17228:
    goto v_17229;
v_17230:
    goto v_17231;
v_17232:
    goto v_17233;
v_17234:
    {
        LispObject v_17597 = stack[-3];
        LispObject v_17598 = stack[-2];
        LispObject v_17599 = stack[0];
        return list4(v_17597, v_17598, v_17599, v_17582);
    }
v_17203:
    goto v_17277;
v_17273:
    v_17583 = stack[-6];
    goto v_17274;
v_17275:
    v_17582 = elt(env, 6); // and
    goto v_17276;
v_17277:
    goto v_17273;
v_17274:
    goto v_17275;
v_17276:
    if (v_17583 == v_17582) goto v_17271;
    else goto v_17272;
v_17271:
    goto v_17293;
v_17281:
    v_17587 = elt(env, 6); // and
    goto v_17282;
v_17283:
    v_17582 = stack[-1];
    v_17586 = qcdr(v_17582);
    goto v_17284;
v_17285:
    v_17585 = stack[-5];
    goto v_17286;
v_17287:
    v_17584 = stack[-4];
    goto v_17288;
v_17289:
    v_17583 = elt(env, 7); // true
    goto v_17290;
v_17291:
    v_17582 = elt(env, 8); // false
    goto v_17292;
v_17293:
    goto v_17281;
v_17282:
    goto v_17283;
v_17284:
    goto v_17285;
v_17286:
    goto v_17287;
v_17288:
    goto v_17289;
v_17290:
    goto v_17291;
v_17292:
    {
        fn = elt(env, 14); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_17587, v_17586, v_17585, v_17584, v_17583, v_17582);
    }
v_17272:
    goto v_17309;
v_17305:
    v_17583 = stack[-6];
    goto v_17306;
v_17307:
    v_17582 = elt(env, 9); // or
    goto v_17308;
v_17309:
    goto v_17305;
v_17306:
    goto v_17307;
v_17308:
    if (v_17583 == v_17582) goto v_17303;
    else goto v_17304;
v_17303:
    goto v_17325;
v_17313:
    v_17587 = elt(env, 9); // or
    goto v_17314;
v_17315:
    v_17582 = stack[-1];
    v_17586 = qcdr(v_17582);
    goto v_17316;
v_17317:
    v_17585 = stack[-5];
    goto v_17318;
v_17319:
    v_17584 = stack[-4];
    goto v_17320;
v_17321:
    v_17583 = elt(env, 8); // false
    goto v_17322;
v_17323:
    v_17582 = elt(env, 7); // true
    goto v_17324;
v_17325:
    goto v_17313;
v_17314:
    goto v_17315;
v_17316:
    goto v_17317;
v_17318:
    goto v_17319;
v_17320:
    goto v_17321;
v_17322:
    goto v_17323;
v_17324:
    {
        fn = elt(env, 14); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_17587, v_17586, v_17585, v_17584, v_17583, v_17582);
    }
v_17304:
    goto v_17353;
v_17349:
    v_17583 = stack[-6];
    goto v_17350;
v_17351:
    v_17582 = elt(env, 9); // or
    goto v_17352;
v_17353:
    goto v_17349;
v_17350:
    goto v_17351;
v_17352:
    if (v_17583 == v_17582) goto v_17347;
    else goto v_17348;
v_17347:
    v_17582 = lisp_true;
    goto v_17346;
v_17348:
    goto v_17363;
v_17359:
    v_17583 = stack[-6];
    goto v_17360;
v_17361:
    v_17582 = elt(env, 6); // and
    goto v_17362;
v_17363:
    goto v_17359;
v_17360:
    goto v_17361;
v_17362:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17346;
    v_17582 = nil;
v_17346:
    if (v_17582 == nil) goto v_17344;
    v_17582 = lisp_true;
    goto v_17342;
v_17344:
    goto v_17374;
v_17370:
    v_17583 = stack[-6];
    goto v_17371;
v_17372:
    v_17582 = elt(env, 10); // not
    goto v_17373;
v_17374:
    goto v_17370;
v_17371:
    goto v_17372;
v_17373:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17342;
    v_17582 = nil;
v_17342:
    if (v_17582 == nil) goto v_17340;
    v_17582 = lisp_true;
    goto v_17338;
v_17340:
    goto v_17389;
v_17385:
    v_17583 = stack[-6];
    goto v_17386;
v_17387:
    v_17582 = elt(env, 11); // impl
    goto v_17388;
v_17389:
    goto v_17385;
v_17386:
    goto v_17387;
v_17388:
    if (v_17583 == v_17582) goto v_17383;
    else goto v_17384;
v_17383:
    v_17582 = lisp_true;
    goto v_17382;
v_17384:
    goto v_17403;
v_17399:
    v_17583 = stack[-6];
    goto v_17400;
v_17401:
    v_17582 = elt(env, 12); // repl
    goto v_17402;
v_17403:
    goto v_17399;
v_17400:
    goto v_17401;
v_17402:
    if (v_17583 == v_17582) goto v_17397;
    else goto v_17398;
v_17397:
    v_17582 = lisp_true;
    goto v_17396;
v_17398:
    goto v_17413;
v_17409:
    v_17583 = stack[-6];
    goto v_17410;
v_17411:
    v_17582 = elt(env, 13); // equiv
    goto v_17412;
v_17413:
    goto v_17409;
v_17410:
    goto v_17411;
v_17412:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17396;
    v_17582 = nil;
v_17396:
    goto v_17382;
    v_17582 = nil;
v_17382:
    goto v_17338;
    v_17582 = nil;
v_17338:
    if (v_17582 == nil) goto v_17336;
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    stack[-3] = v_17582;
    v_17582 = stack[-3];
    if (v_17582 == nil) goto v_17427;
    else goto v_17428;
v_17427:
    v_17582 = nil;
    goto v_17421;
v_17428:
    v_17582 = stack[-3];
    v_17582 = qcar(v_17582);
    goto v_17442;
v_17436:
    v_17584 = v_17582;
    goto v_17437;
v_17438:
    v_17583 = stack[-5];
    goto v_17439;
v_17440:
    v_17582 = stack[-4];
    goto v_17441;
v_17442:
    goto v_17436;
v_17437:
    goto v_17438;
v_17439:
    goto v_17440;
v_17441:
    v_17582 = CC_pasf_sisub(elt(env, 0), 3, v_17584, v_17583, v_17582);
    env = stack[-7];
    v_17582 = ncons(v_17582);
    env = stack[-7];
    stack[-1] = v_17582;
    stack[-2] = v_17582;
v_17422:
    v_17582 = stack[-3];
    v_17582 = qcdr(v_17582);
    stack[-3] = v_17582;
    v_17582 = stack[-3];
    if (v_17582 == nil) goto v_17450;
    else goto v_17451;
v_17450:
    v_17582 = stack[-2];
    goto v_17421;
v_17451:
    goto v_17459;
v_17455:
    stack[0] = stack[-1];
    goto v_17456;
v_17457:
    v_17582 = stack[-3];
    v_17582 = qcar(v_17582);
    goto v_17472;
v_17466:
    v_17584 = v_17582;
    goto v_17467;
v_17468:
    v_17583 = stack[-5];
    goto v_17469;
v_17470:
    v_17582 = stack[-4];
    goto v_17471;
v_17472:
    goto v_17466;
v_17467:
    goto v_17468;
v_17469:
    goto v_17470;
v_17471:
    v_17582 = CC_pasf_sisub(elt(env, 0), 3, v_17584, v_17583, v_17582);
    env = stack[-7];
    v_17582 = ncons(v_17582);
    env = stack[-7];
    goto v_17458;
v_17459:
    goto v_17455;
v_17456:
    goto v_17457;
v_17458:
    v_17582 = Lrplacd(nil, stack[0], v_17582);
    env = stack[-7];
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    stack[-1] = v_17582;
    goto v_17422;
v_17421:
    v_17583 = v_17582;
    v_17582 = v_17583;
    if (v_17582 == nil) goto v_17482;
    v_17582 = v_17583;
    v_17582 = qcdr(v_17582);
    if (v_17582 == nil) goto v_17482;
    goto v_17493;
v_17489:
    v_17582 = stack[-6];
    goto v_17490;
v_17491:
    goto v_17492;
v_17493:
    goto v_17489;
v_17490:
    goto v_17491;
v_17492:
    return cons(v_17582, v_17583);
v_17482:
    v_17582 = v_17583;
    if (v_17582 == nil) goto v_17496;
    else goto v_17497;
v_17496:
    goto v_17507;
v_17503:
    v_17583 = stack[-6];
    goto v_17504;
v_17505:
    v_17582 = elt(env, 6); // and
    goto v_17506;
v_17507:
    goto v_17503;
v_17504:
    goto v_17505;
v_17506:
    if (v_17583 == v_17582) goto v_17501;
    else goto v_17502;
v_17501:
    v_17582 = elt(env, 7); // true
    goto v_17500;
v_17502:
    v_17582 = elt(env, 8); // false
    goto v_17500;
    v_17582 = nil;
v_17500:
    goto v_17480;
v_17497:
    v_17582 = v_17583;
    v_17582 = qcar(v_17582);
    goto v_17480;
    v_17582 = nil;
v_17480:
    goto v_17136;
v_17336:
    goto v_17530;
v_17526:
    v_17583 = stack[-6];
    goto v_17527;
v_17528:
    v_17582 = elt(env, 7); // true
    goto v_17529;
v_17530:
    goto v_17526;
v_17527:
    goto v_17528;
v_17529:
    if (v_17583 == v_17582) goto v_17524;
    else goto v_17525;
v_17524:
    v_17582 = lisp_true;
    goto v_17523;
v_17525:
    goto v_17540;
v_17536:
    v_17583 = stack[-6];
    goto v_17537;
v_17538:
    v_17582 = elt(env, 8); // false
    goto v_17539;
v_17540:
    goto v_17536;
v_17537:
    goto v_17538;
v_17539:
    v_17582 = (v_17583 == v_17582 ? lisp_true : nil);
    goto v_17523;
    v_17582 = nil;
v_17523:
    if (v_17582 == nil) goto v_17521;
    v_17582 = stack[-1];
    goto v_17136;
v_17521:
    goto v_17550;
v_17546:
    goto v_17558;
v_17552:
    v_17582 = stack[-1];
    stack[0] = qcar(v_17582);
    goto v_17553;
v_17554:
    goto v_17566;
v_17562:
    v_17582 = stack[-1];
    v_17582 = qcdr(v_17582);
    stack[-1] = qcar(v_17582);
    goto v_17563;
v_17564:
    goto v_17576;
v_17572:
    v_17583 = stack[-5];
    goto v_17573;
v_17574:
    v_17582 = stack[-4];
    goto v_17575;
v_17576:
    goto v_17572;
v_17573:
    goto v_17574;
v_17575:
    v_17582 = cons(v_17583, v_17582);
    env = stack[-7];
    v_17582 = ncons(v_17582);
    env = stack[-7];
    goto v_17565;
v_17566:
    goto v_17562;
v_17563:
    goto v_17564;
v_17565:
    fn = elt(env, 15); // subf
    v_17582 = (*qfn2(fn))(fn, stack[-1], v_17582);
    env = stack[-7];
    v_17583 = qcar(v_17582);
    goto v_17555;
v_17556:
    v_17582 = nil;
    goto v_17557;
v_17558:
    goto v_17552;
v_17553:
    goto v_17554;
v_17555:
    goto v_17556;
v_17557:
    v_17583 = list3(stack[0], v_17583, v_17582);
    env = stack[-7];
    goto v_17547;
v_17548:
    v_17582 = stack[-6];
    goto v_17549;
v_17550:
    goto v_17546;
v_17547:
    goto v_17548;
v_17549:
    {
        fn = elt(env, 16); // pasf_simplat1
        return (*qfn2(fn))(fn, v_17583, v_17582);
    }
v_17136:
    return onevalue(v_17582);
}



// Code for ev_max!#

static LispObject CC_ev_maxC(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17148, v_17149, v_17150, v_17151;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17149 = v_17131;
    v_17150 = v_17130;
// end of prologue
    goto v_17141;
v_17137:
    v_17151 = v_17150;
    goto v_17138;
v_17139:
    v_17148 = v_17149;
    goto v_17140;
v_17141:
    goto v_17137;
v_17138:
    goto v_17139;
v_17140:
    if (((intptr_t)(v_17151)) > ((intptr_t)(v_17148))) goto v_17135;
    else goto v_17136;
v_17135:
    v_17148 = v_17150;
    goto v_17134;
v_17136:
    v_17148 = v_17149;
    goto v_17134;
    v_17148 = nil;
v_17134:
    return onevalue(v_17148);
}



// Code for semanticml

static LispObject CC_semanticml(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17215, v_17216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17130);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_17130;
// end of prologue
    goto v_17144;
v_17140:
    v_17215 = stack[0];
    v_17216 = Llength(nil, v_17215);
    env = stack[-1];
    goto v_17141;
v_17142:
    v_17215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17143;
v_17144:
    goto v_17140;
v_17141:
    goto v_17142;
v_17143:
    v_17215 = (LispObject)greaterp2(v_17216, v_17215);
    v_17215 = v_17215 ? lisp_true : nil;
    env = stack[-1];
    if (v_17215 == nil) goto v_17138;
    v_17215 = elt(env, 1); // "<apply>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 2); // "<fn>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    goto v_17136;
v_17138:
v_17136:
    v_17215 = elt(env, 3); // "<semantic>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 4); // "<ci><mo>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = stack[0];
    v_17215 = qcar(v_17215);
    v_17215 = qcar(v_17215);
    v_17215 = Lprinc(nil, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 5); // "</mo></ci>"
    v_17215 = Lprinc(nil, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 6); // "<annotation-xml encoding=""OpenMath"">"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 7); // "<"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = stack[0];
    v_17215 = qcar(v_17215);
    v_17215 = qcdr(v_17215);
    v_17215 = qcar(v_17215);
    fn = elt(env, 15); // mathml_list2string
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 8); // ">"
    v_17215 = Lprinc(nil, v_17215);
    env = stack[-1];
    v_17215 = nil;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 9); // "</annotation-xml>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = nil;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 10); // "</semantic>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    goto v_17199;
v_17195:
    v_17215 = stack[0];
    v_17216 = Llength(nil, v_17215);
    env = stack[-1];
    goto v_17196;
v_17197:
    v_17215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17198;
v_17199:
    goto v_17195;
v_17196:
    goto v_17197;
v_17198:
    v_17215 = (LispObject)greaterp2(v_17216, v_17215);
    v_17215 = v_17215 ? lisp_true : nil;
    env = stack[-1];
    if (v_17215 == nil) goto v_17193;
    v_17215 = nil;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 11); // "</fn>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = stack[0];
    v_17215 = qcdr(v_17215);
    fn = elt(env, 16); // multi_elem
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = nil;
    fn = elt(env, 14); // indent!*
    v_17215 = (*qfn1(fn))(fn, v_17215);
    env = stack[-1];
    v_17215 = elt(env, 12); // "</apply>"
    fn = elt(env, 13); // printout
    v_17215 = (*qfn1(fn))(fn, v_17215);
    goto v_17191;
v_17193:
v_17191:
    v_17215 = nil;
    return onevalue(v_17215);
}



// Code for add_minus

static LispObject CC_add_minus(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17315, v_17316;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17130);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_17130;
// end of prologue
    v_17315 = stack[-1];
    if (!consp(v_17315)) goto v_17137;
    else goto v_17138;
v_17137:
    v_17315 = stack[-1];
    goto v_17133;
v_17138:
    goto v_17151;
v_17147:
    v_17315 = stack[-1];
    v_17316 = qcar(v_17315);
    goto v_17148;
v_17149:
    v_17315 = elt(env, 1); // !:rd!:
    goto v_17150;
v_17151:
    goto v_17147;
v_17148:
    goto v_17149;
v_17150:
    if (v_17316 == v_17315) goto v_17145;
    else goto v_17146;
v_17145:
    goto v_17160;
v_17156:
    v_17315 = stack[-1];
    v_17316 = qcdr(v_17315);
    goto v_17157;
v_17158:
    v_17315 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17159;
v_17160:
    goto v_17156;
v_17157:
    goto v_17158;
v_17159:
    v_17315 = (LispObject)geq2(v_17316, v_17315);
    v_17315 = v_17315 ? lisp_true : nil;
    env = stack[-3];
    goto v_17144;
v_17146:
    v_17315 = nil;
    goto v_17144;
    v_17315 = nil;
v_17144:
    if (v_17315 == nil) goto v_17142;
    v_17315 = stack[-1];
    goto v_17133;
v_17142:
    goto v_17178;
v_17174:
    v_17315 = stack[-1];
    v_17316 = qcar(v_17315);
    goto v_17175;
v_17176:
    v_17315 = elt(env, 1); // !:rd!:
    goto v_17177;
v_17178:
    goto v_17174;
v_17175:
    goto v_17176;
v_17177:
    if (v_17316 == v_17315) goto v_17172;
    else goto v_17173;
v_17172:
    goto v_17187;
v_17183:
    v_17315 = stack[-1];
    v_17316 = qcdr(v_17315);
    goto v_17184;
v_17185:
    v_17315 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17186;
v_17187:
    goto v_17183;
v_17184:
    goto v_17185;
v_17186:
    v_17315 = (LispObject)lessp2(v_17316, v_17315);
    v_17315 = v_17315 ? lisp_true : nil;
    env = stack[-3];
    goto v_17171;
v_17173:
    v_17315 = nil;
    goto v_17171;
    v_17315 = nil;
v_17171:
    if (v_17315 == nil) goto v_17169;
    goto v_17199;
v_17195:
    stack[-2] = elt(env, 2); // minus
    goto v_17196;
v_17197:
    goto v_17206;
v_17202:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17203;
v_17204:
    v_17315 = stack[-1];
    v_17315 = qcdr(v_17315);
    v_17315 = Labsval(nil, v_17315);
    env = stack[-3];
    goto v_17205;
v_17206:
    goto v_17202;
v_17203:
    goto v_17204;
v_17205:
    v_17315 = cons(stack[0], v_17315);
    goto v_17198;
v_17199:
    goto v_17195;
v_17196:
    goto v_17197;
v_17198:
    {
        LispObject v_17320 = stack[-2];
        return list2(v_17320, v_17315);
    }
v_17169:
    goto v_17221;
v_17217:
    v_17315 = stack[-1];
    v_17316 = qcar(v_17315);
    goto v_17218;
v_17219:
    v_17315 = elt(env, 2); // minus
    goto v_17220;
v_17221:
    goto v_17217;
v_17218:
    goto v_17219;
v_17220:
    if (v_17316 == v_17315) goto v_17215;
    else goto v_17216;
v_17215:
    v_17315 = stack[-1];
    v_17315 = qcdr(v_17315);
    v_17315 = qcar(v_17315);
    v_17315 = (is_number(v_17315) ? lisp_true : nil);
    goto v_17214;
v_17216:
    v_17315 = nil;
    goto v_17214;
    v_17315 = nil;
v_17214:
    if (v_17315 == nil) goto v_17212;
    v_17315 = stack[-1];
    goto v_17133;
v_17212:
    goto v_17243;
v_17239:
    v_17315 = stack[-1];
    v_17316 = qcar(v_17315);
    goto v_17240;
v_17241:
    v_17315 = elt(env, 2); // minus
    goto v_17242;
v_17243:
    goto v_17239;
v_17240:
    goto v_17241;
v_17242:
    if (v_17316 == v_17315) goto v_17237;
    else goto v_17238;
v_17237:
    goto v_17252;
v_17248:
    v_17315 = stack[-1];
    v_17315 = qcdr(v_17315);
    v_17315 = qcar(v_17315);
    v_17316 = qcdr(v_17315);
    goto v_17249;
v_17250:
    v_17315 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17251;
v_17252:
    goto v_17248;
v_17249:
    goto v_17250;
v_17251:
    v_17315 = (LispObject)lessp2(v_17316, v_17315);
    v_17315 = v_17315 ? lisp_true : nil;
    env = stack[-3];
    goto v_17236;
v_17238:
    v_17315 = nil;
    goto v_17236;
    v_17315 = nil;
v_17236:
    if (v_17315 == nil) goto v_17234;
    goto v_17266;
v_17262:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17263;
v_17264:
    v_17315 = stack[-1];
    v_17315 = qcdr(v_17315);
    v_17315 = qcar(v_17315);
    v_17315 = qcdr(v_17315);
    v_17315 = Labsval(nil, v_17315);
    goto v_17265;
v_17266:
    goto v_17262;
v_17263:
    goto v_17264;
v_17265:
    {
        LispObject v_17321 = stack[0];
        return cons(v_17321, v_17315);
    }
v_17234:
    goto v_17279;
v_17275:
    v_17315 = stack[-1];
    v_17316 = qcar(v_17315);
    goto v_17276;
v_17277:
    v_17315 = elt(env, 2); // minus
    goto v_17278;
v_17279:
    goto v_17275;
v_17276:
    goto v_17277;
v_17278:
    if (v_17316 == v_17315) goto v_17273;
    else goto v_17274;
v_17273:
    v_17315 = stack[-1];
    goto v_17133;
v_17274:
    goto v_17291;
v_17287:
    v_17315 = stack[-1];
    v_17316 = qcdr(v_17315);
    goto v_17288;
v_17289:
    v_17315 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17290;
v_17291:
    goto v_17287;
v_17288:
    goto v_17289;
v_17290:
    v_17315 = (LispObject)lessp2(v_17316, v_17315);
    v_17315 = v_17315 ? lisp_true : nil;
    env = stack[-3];
    if (v_17315 == nil) goto v_17285;
    goto v_17300;
v_17296:
    stack[-2] = elt(env, 2); // minus
    goto v_17297;
v_17298:
    goto v_17307;
v_17303:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17304;
v_17305:
    v_17315 = stack[-1];
    v_17315 = qcdr(v_17315);
    v_17315 = Labsval(nil, v_17315);
    env = stack[-3];
    goto v_17306;
v_17307:
    goto v_17303;
v_17304:
    goto v_17305;
v_17306:
    v_17315 = cons(stack[0], v_17315);
    goto v_17299;
v_17300:
    goto v_17296;
v_17297:
    goto v_17298;
v_17299:
    {
        LispObject v_17322 = stack[-2];
        return list2(v_17322, v_17315);
    }
v_17285:
    v_17315 = stack[-1];
    goto v_17133;
    v_17315 = nil;
v_17133:
    return onevalue(v_17315);
}



// Code for dipequal

static LispObject CC_dipequal(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17190, v_17191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17130,v_17131);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17131;
    stack[-1] = v_17130;
// end of prologue
v_17135:
    v_17190 = stack[-1];
    if (v_17190 == nil) goto v_17138;
    else goto v_17139;
v_17138:
    v_17190 = stack[0];
    v_17190 = (v_17190 == nil ? lisp_true : nil);
    goto v_17134;
v_17139:
    v_17190 = stack[0];
    if (v_17190 == nil) goto v_17143;
    else goto v_17144;
v_17143:
    v_17190 = nil;
    goto v_17134;
v_17144:
    goto v_17157;
v_17153:
    v_17190 = stack[-1];
    v_17190 = qcdr(v_17190);
    v_17191 = qcar(v_17190);
    goto v_17154;
v_17155:
    v_17190 = stack[0];
    v_17190 = qcdr(v_17190);
    v_17190 = qcar(v_17190);
    goto v_17156;
v_17157:
    goto v_17153;
v_17154:
    goto v_17155;
v_17156:
    if (equal(v_17191, v_17190)) goto v_17151;
    else goto v_17152;
v_17151:
    goto v_17173;
v_17169:
    v_17190 = stack[-1];
    v_17191 = qcar(v_17190);
    goto v_17170;
v_17171:
    v_17190 = stack[0];
    v_17190 = qcar(v_17190);
    goto v_17172;
v_17173:
    goto v_17169;
v_17170:
    goto v_17171;
v_17172:
    fn = elt(env, 1); // evequal
    v_17190 = (*qfn2(fn))(fn, v_17191, v_17190);
    env = stack[-2];
    if (v_17190 == nil) goto v_17167;
    v_17190 = stack[-1];
    v_17190 = qcdr(v_17190);
    v_17190 = qcdr(v_17190);
    stack[-1] = v_17190;
    v_17190 = stack[0];
    v_17190 = qcdr(v_17190);
    v_17190 = qcdr(v_17190);
    stack[0] = v_17190;
    goto v_17135;
v_17167:
    v_17190 = nil;
    goto v_17134;
    goto v_17150;
v_17152:
    v_17190 = nil;
    goto v_17134;
v_17150:
    goto v_17137;
v_17137:
    v_17190 = nil;
v_17134:
    return onevalue(v_17190);
}



// Code for vdp2a

static LispObject CC_vdp2a(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17138;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17138 = v_17130;
// end of prologue
    v_17138 = qcdr(v_17138);
    v_17138 = qcdr(v_17138);
    v_17138 = qcdr(v_17138);
    v_17138 = qcar(v_17138);
    {
        fn = elt(env, 1); // dip2a
        return (*qfn1(fn))(fn, v_17138);
    }
}



// Code for overall_factor

static LispObject CC_overall_factor(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17166, v_17167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17130,v_17131);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_17131;
    stack[-1] = v_17130;
// end of prologue
v_17129:
    v_17166 = stack[0];
    if (v_17166 == nil) goto v_17135;
    else goto v_17136;
v_17135:
    v_17166 = lisp_true;
    goto v_17134;
v_17136:
    goto v_17149;
v_17145:
    stack[-2] = stack[-1];
    goto v_17146;
v_17147:
    v_17166 = stack[0];
    fn = elt(env, 1); // xval
    v_17166 = (*qfn1(fn))(fn, v_17166);
    env = stack[-3];
    goto v_17148;
v_17149:
    goto v_17145;
v_17146:
    goto v_17147;
v_17148:
    v_17166 = Lmemq(nil, stack[-2], v_17166);
    if (v_17166 == nil) goto v_17143;
    else goto v_17144;
v_17143:
    v_17166 = nil;
    goto v_17142;
v_17144:
    goto v_17162;
v_17158:
    v_17167 = stack[-1];
    goto v_17159;
v_17160:
    v_17166 = stack[0];
    v_17166 = qcdr(v_17166);
    goto v_17161;
v_17162:
    goto v_17158;
v_17159:
    goto v_17160;
v_17161:
    stack[-1] = v_17167;
    stack[0] = v_17166;
    goto v_17129;
    v_17166 = nil;
v_17142:
    goto v_17134;
    v_17166 = nil;
v_17134:
    return onevalue(v_17166);
}



// Code for !:dmtimeslst

static LispObject CC_Tdmtimeslst(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17157, v_17158;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17130);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_17158 = v_17130;
// end of prologue
    v_17157 = v_17158;
    if (v_17157 == nil) goto v_17134;
    else goto v_17135;
v_17134:
    v_17157 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17133;
v_17135:
    v_17157 = v_17158;
    v_17157 = qcdr(v_17157);
    if (v_17157 == nil) goto v_17138;
    else goto v_17139;
v_17138:
    v_17157 = v_17158;
    v_17157 = qcar(v_17157);
    goto v_17133;
v_17139:
    goto v_17151;
v_17147:
    v_17157 = v_17158;
    stack[0] = qcar(v_17157);
    goto v_17148;
v_17149:
    v_17157 = v_17158;
    v_17157 = qcdr(v_17157);
    v_17157 = CC_Tdmtimeslst(elt(env, 0), v_17157);
    env = stack[-1];
    goto v_17150;
v_17151:
    goto v_17147;
v_17148:
    goto v_17149;
v_17150:
    {
        LispObject v_17160 = stack[0];
        fn = elt(env, 1); // !:times
        return (*qfn2(fn))(fn, v_17160, v_17157);
    }
    v_17157 = nil;
v_17133:
    return onevalue(v_17157);
}



// Code for gparg1p

static LispObject CC_gparg1p(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17153;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17130);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_17130;
// end of prologue
v_17129:
    v_17153 = stack[0];
    if (v_17153 == nil) goto v_17134;
    else goto v_17135;
v_17134:
    v_17153 = lisp_true;
    goto v_17133;
v_17135:
    v_17153 = stack[0];
    v_17153 = qcar(v_17153);
    fn = elt(env, 1); // gpargp
    v_17153 = (*qfn1(fn))(fn, v_17153);
    env = stack[-1];
    if (v_17153 == nil) goto v_17142;
    else goto v_17143;
v_17142:
    v_17153 = nil;
    goto v_17141;
v_17143:
    v_17153 = stack[0];
    v_17153 = qcdr(v_17153);
    stack[0] = v_17153;
    goto v_17129;
    v_17153 = nil;
v_17141:
    goto v_17133;
    v_17153 = nil;
v_17133:
    return onevalue(v_17153);
}



// Code for formsetq

static LispObject CC_formsetq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17215, v_17216, v_17217, v_17218, v_17219;
    LispObject fn;
    LispObject v_17132, v_17131, v_17130;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq");
    va_start(aa, nargs);
    v_17130 = va_arg(aa, LispObject);
    v_17131 = va_arg(aa, LispObject);
    v_17132 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17217 = v_17132;
    v_17218 = v_17131;
    v_17219 = v_17130;
// end of prologue
    goto v_17142;
v_17138:
    v_17216 = v_17217;
    goto v_17139;
v_17140:
    v_17215 = elt(env, 1); // symbolic
    goto v_17141;
v_17142:
    goto v_17138;
v_17139:
    goto v_17140;
v_17141:
    if (v_17216 == v_17215) goto v_17137;
    goto v_17152;
v_17146:
    v_17215 = v_17219;
    goto v_17147;
v_17148:
    v_17216 = v_17218;
    goto v_17149;
v_17150:
    goto v_17151;
v_17152:
    goto v_17146;
v_17147:
    goto v_17148;
v_17149:
    goto v_17150;
v_17151:
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(fn, 3, v_17215, v_17216, v_17217);
    }
v_17137:
    goto v_17163;
v_17159:
    v_17215 = v_17219;
    v_17215 = qcdr(v_17215);
    v_17216 = qcar(v_17215);
    goto v_17160;
v_17161:
    v_17215 = elt(env, 2); // list
    goto v_17162;
v_17163:
    goto v_17159;
v_17160:
    goto v_17161;
v_17162:
    if (!consp(v_17216)) goto v_17157;
    v_17216 = qcar(v_17216);
    if (v_17216 == v_17215) goto v_17156;
    else goto v_17157;
v_17156:
    goto v_17175;
v_17169:
    v_17215 = v_17219;
    goto v_17170;
v_17171:
    v_17216 = v_17218;
    goto v_17172;
v_17173:
    goto v_17174;
v_17175:
    goto v_17169;
v_17170:
    goto v_17171;
v_17172:
    goto v_17173;
v_17174:
    {
        fn = elt(env, 5); // formsetq1
        return (*qfnn(fn))(fn, 3, v_17215, v_17216, v_17217);
    }
v_17157:
    goto v_17186;
v_17182:
    v_17215 = v_17219;
    v_17215 = qcdr(v_17215);
    v_17216 = qcar(v_17215);
    goto v_17183;
v_17184:
    v_17215 = elt(env, 3); // cons
    goto v_17185;
v_17186:
    goto v_17182;
v_17183:
    goto v_17184;
v_17185:
    if (!consp(v_17216)) goto v_17180;
    v_17216 = qcar(v_17216);
    if (v_17216 == v_17215) goto v_17179;
    else goto v_17180;
v_17179:
    goto v_17198;
v_17192:
    v_17215 = v_17219;
    goto v_17193;
v_17194:
    v_17216 = v_17218;
    goto v_17195;
v_17196:
    goto v_17197;
v_17198:
    goto v_17192;
v_17193:
    goto v_17194;
v_17195:
    goto v_17196;
v_17197:
    {
        fn = elt(env, 6); // formsetq2
        return (*qfnn(fn))(fn, 3, v_17215, v_17216, v_17217);
    }
v_17180:
    goto v_17211;
v_17205:
    v_17215 = v_17219;
    goto v_17206;
v_17207:
    v_17216 = v_17218;
    goto v_17208;
v_17209:
    goto v_17210;
v_17211:
    goto v_17205;
v_17206:
    goto v_17207;
v_17208:
    goto v_17209;
v_17210:
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(fn, 3, v_17215, v_17216, v_17217);
    }
    v_17215 = nil;
    return onevalue(v_17215);
}



// Code for length_multiindex

static LispObject CC_length_multiindex(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17158, v_17159;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17130);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_17158 = v_17130;
// end of prologue
    stack[0] = v_17158;
    v_17158 = (LispObject)0+TAG_FIXNUM; // 0
    v_17159 = v_17158;
v_17136:
    v_17158 = stack[0];
    if (v_17158 == nil) goto v_17141;
    else goto v_17142;
v_17141:
    v_17158 = v_17159;
    goto v_17135;
v_17142:
    goto v_17150;
v_17146:
    v_17158 = stack[0];
    v_17158 = qcar(v_17158);
    goto v_17147;
v_17148:
    goto v_17149;
v_17150:
    goto v_17146;
v_17147:
    goto v_17148;
v_17149:
    v_17158 = plus2(v_17158, v_17159);
    env = stack[-1];
    v_17159 = v_17158;
    v_17158 = stack[0];
    v_17158 = qcdr(v_17158);
    stack[0] = v_17158;
    goto v_17136;
v_17135:
    return onevalue(v_17158);
}



// Code for lex_basic_token

static LispObject CC_lex_basic_token(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18373, v_18374, v_18375;
    LispObject fn;
    argcheck(nargs, 0, "lex_basic_token");
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
v_17129:
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v_18373 = qvalue(elt(env, 2)); // lex_peeked
    if (v_18373 == nil) goto v_17140;
    v_18373 = qvalue(elt(env, 2)); // lex_peeked
    stack[-4] = v_18373;
    v_18373 = qvalue(elt(env, 3)); // lex_peeked_yylval
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 5)); // lex_peeked_escaped
    qvalue(elt(env, 6)) = v_18373; // lex_escaped
    v_18373 = nil;
    qvalue(elt(env, 5)) = v_18373; // lex_peeked_escaped
    qvalue(elt(env, 3)) = v_18373; // lex_peeked_yylval
    qvalue(elt(env, 2)) = v_18373; // lex_peeked
    v_18373 = stack[-4];
    goto v_17135;
v_17140:
    v_18373 = nil;
    qvalue(elt(env, 6)) = v_18373; // lex_escaped
v_17150:
    goto v_17163;
v_17159:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17160;
v_17161:
    v_18373 = elt(env, 8); // ! 
    goto v_17162;
v_17163:
    goto v_17159;
v_17160:
    goto v_17161;
v_17162:
    if (v_18374 == v_18373) goto v_17157;
    else goto v_17158;
v_17157:
    v_18373 = lisp_true;
    goto v_17156;
v_17158:
    goto v_17177;
v_17173:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17174;
v_17175:
    v_18373 = qvalue(elt(env, 9)); // !$eol!$
    goto v_17176;
v_17177:
    goto v_17173;
v_17174:
    goto v_17175;
v_17176:
    if (equal(v_18374, v_18373)) goto v_17171;
    else goto v_17172;
v_17171:
    v_18373 = lisp_true;
    goto v_17170;
v_17172:
    goto v_17191;
v_17187:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17188;
v_17189:
    v_18373 = elt(env, 10); // !	
    goto v_17190;
v_17191:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    if (v_18374 == v_18373) goto v_17185;
    else goto v_17186;
v_17185:
    v_18373 = lisp_true;
    goto v_17184;
v_17186:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    fn = elt(env, 49); // lex_start_line_comment
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17202;
    else goto v_17203;
v_17202:
    v_18373 = nil;
    goto v_17201;
v_17203:
    fn = elt(env, 50); // lex_skip_line_comment
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17201;
    v_18373 = nil;
v_17201:
    if (v_18373 == nil) goto v_17199;
    else goto v_17198;
v_17199:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    fn = elt(env, 51); // lex_start_block_comment
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17212;
    else goto v_17213;
v_17212:
    v_18373 = nil;
    goto v_17211;
v_17213:
    fn = elt(env, 52); // lex_skip_block_comment
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17211;
    v_18373 = nil;
v_17211:
v_17198:
    goto v_17184;
    v_18373 = nil;
v_17184:
    goto v_17170;
    v_18373 = nil;
v_17170:
    goto v_17156;
    v_18373 = nil;
v_17156:
    if (v_18373 == nil) goto v_17153;
    else goto v_17154;
v_17153:
    goto v_17149;
v_17154:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17150;
v_17149:
    goto v_17230;
v_17226:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17227;
v_17228:
    v_18373 = qvalue(elt(env, 11)); // !$eof!$
    goto v_17229;
v_17230:
    goto v_17226;
v_17227:
    goto v_17228;
v_17229:
    if (equal(v_18374, v_18373)) goto v_17224;
    else goto v_17225;
v_17224:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 12)); // lex_eof_code
    goto v_17135;
v_17225:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    fn = elt(env, 54); // lexer_word_starter
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17239;
    else goto v_17237;
v_17239:
    goto v_17251;
v_17247:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17248;
v_17249:
    v_18373 = elt(env, 13); // !!
    goto v_17250;
v_17251:
    goto v_17247;
v_17248:
    goto v_17249;
v_17250:
    if (v_18374 == v_18373) goto v_17245;
    else goto v_17246;
v_17245:
    goto v_17264;
v_17260:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17261;
v_17262:
    v_18373 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17263;
v_17264:
    goto v_17260;
v_17261:
    goto v_17262;
v_17263:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_17256;
    else goto v_17257;
v_17256:
    v_18374 = nil;
    v_18373 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = v_18374; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=16 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 16, 0);
    qvalue(elt(env, 16)) = v_18373; // !*lower
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18373 = lisp_true;
    qvalue(elt(env, 6)) = v_18373; // lex_escaped
    goto v_17255;
v_17257:
    v_18373 = nil;
    goto v_17255;
    v_18373 = nil;
v_17255:
    goto v_17244;
v_17246:
    v_18373 = nil;
    goto v_17244;
    v_18373 = nil;
v_17244:
    if (v_18373 == nil) goto v_17242;
    else goto v_17237;
v_17242:
    goto v_17238;
v_17237:
    goto v_17284;
v_17280:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17281;
v_17282:
    v_18373 = stack[-4];
    goto v_17283;
v_17284:
    goto v_17280;
v_17281:
    goto v_17282;
v_17283:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
v_17289:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 56); // lexer_word_continues
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17294;
    else goto v_17293;
v_17294:
    goto v_17306;
v_17302:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17303;
v_17304:
    v_18373 = elt(env, 13); // !!
    goto v_17305;
v_17306:
    goto v_17302;
v_17303:
    goto v_17304;
v_17305:
    if (v_18374 == v_18373) goto v_17300;
    else goto v_17301;
v_17300:
    goto v_17319;
v_17315:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17316;
v_17317:
    v_18373 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17318;
v_17319:
    goto v_17315;
v_17316:
    goto v_17317;
v_17318:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_17311;
    else goto v_17312;
v_17311:
    v_18374 = nil;
    v_18373 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = v_18374; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=16 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 16, 0);
    qvalue(elt(env, 16)) = v_18373; // !*lower
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18373 = lisp_true;
    qvalue(elt(env, 6)) = v_18373; // lex_escaped
    goto v_17310;
v_17312:
    v_18373 = nil;
    goto v_17310;
    v_18373 = nil;
v_17310:
    goto v_17299;
v_17301:
    v_18373 = nil;
    goto v_17299;
    v_18373 = nil;
v_17299:
    if (v_18373 == nil) goto v_17297;
    else goto v_17293;
v_17297:
    goto v_17288;
v_17293:
    goto v_17340;
v_17336:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17337;
v_17338:
    v_18373 = stack[-4];
    goto v_17339;
v_17340:
    goto v_17336;
v_17337:
    goto v_17338;
v_17339:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17289;
v_17288:
    v_18373 = stack[-4];
    v_18373 = Lnreverse(nil, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    fn = elt(env, 57); // list2widestring
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    v_18373 = Lintern(nil, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_17359;
v_17355:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_17356;
v_17357:
    v_18373 = elt(env, 17); // comment
    goto v_17358;
v_17359:
    goto v_17355;
v_17356:
    goto v_17357;
v_17358:
    if (v_18374 == v_18373) goto v_17353;
    else goto v_17354;
v_17353:
    goto v_17372;
v_17368:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17369;
v_17370:
    v_18373 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17371;
v_17372:
    goto v_17368;
v_17369:
    goto v_17370;
v_17371:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_17364;
    else goto v_17365;
v_17364:
    v_18373 = qvalue(elt(env, 6)); // lex_escaped
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_17363;
v_17365:
    v_18373 = nil;
    goto v_17363;
    v_18373 = nil;
v_17363:
    goto v_17352;
v_17354:
    v_18373 = nil;
    goto v_17352;
    v_18373 = nil;
v_17352:
    if (v_18373 == nil) goto v_17350;
v_17385:
    goto v_17398;
v_17394:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17395;
v_17396:
    v_18373 = elt(env, 18); // !;
    goto v_17397;
v_17398:
    goto v_17394;
v_17395:
    goto v_17396;
v_17397:
    if (v_18374 == v_18373) goto v_17392;
    else goto v_17393;
v_17392:
    v_18373 = lisp_true;
    goto v_17391;
v_17393:
    goto v_17408;
v_17404:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17405;
v_17406:
    v_18373 = elt(env, 19); // !$
    goto v_17407;
v_17408:
    goto v_17404;
v_17405:
    goto v_17406;
v_17407:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17391;
    v_18373 = nil;
v_17391:
    if (v_18373 == nil) goto v_17389;
    goto v_17384;
v_17389:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17385;
v_17384:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17129;
v_17350:
    v_18373 = qvalue(elt(env, 6)); // lex_escaped
    if (v_18373 == nil) goto v_17422;
    else goto v_17423;
v_17422:
    goto v_17430;
v_17426:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_17427;
v_17428:
    v_18373 = elt(env, 20); // lex_code
    goto v_17429;
v_17430:
    goto v_17426;
v_17427:
    goto v_17428;
v_17429:
    v_18373 = get(v_18374, v_18373);
    env = stack[-5];
    stack[-3] = v_18373;
    goto v_17421;
v_17423:
    v_18373 = nil;
    goto v_17421;
    v_18373 = nil;
v_17421:
    if (v_18373 == nil) goto v_17419;
    v_18373 = stack[-3];
    goto v_17135;
v_17419:
    goto v_17448;
v_17444:
    v_18374 = stack[-4];
    goto v_17445;
v_17446:
    v_18373 = elt(env, 21); // !'
    goto v_17447;
v_17448:
    goto v_17444;
v_17445:
    goto v_17446;
v_17447:
    if (!consp(v_18374)) goto v_17442;
    v_18374 = qcar(v_18374);
    if (v_18374 == v_18373) goto v_17441;
    else goto v_17442;
v_17441:
    v_18373 = lisp_true;
    goto v_17440;
v_17442:
    goto v_17459;
v_17455:
    v_18374 = stack[-4];
    goto v_17456;
v_17457:
    v_18373 = elt(env, 22); // lex_is_typename
    goto v_17458;
v_17459:
    goto v_17455;
v_17456:
    goto v_17457;
v_17458:
    v_18373 = get(v_18374, v_18373);
    env = stack[-5];
    goto v_17440;
    v_18373 = nil;
v_17440:
    if (v_18373 == nil) goto v_17438;
    v_18373 = qvalue(elt(env, 23)); // lex_typename_code
    goto v_17135;
v_17438:
    v_18373 = qvalue(elt(env, 24)); // lex_symbol_code
    goto v_17135;
    goto v_17236;
v_17238:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17468;
    else goto v_17466;
v_17468:
    goto v_17480;
v_17476:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17477;
v_17478:
    v_18373 = elt(env, 25); // !~
    goto v_17479;
v_17480:
    goto v_17476;
v_17477:
    goto v_17478;
v_17479:
    if (v_18374 == v_18373) goto v_17474;
    else goto v_17475;
v_17474:
    goto v_17493;
v_17489:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17490;
v_17491:
    v_18373 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17492;
v_17493:
    goto v_17489;
v_17490:
    goto v_17491;
v_17492:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_17485;
    else goto v_17486;
v_17485:
    fn = elt(env, 58); // yypeek
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    goto v_17484;
v_17486:
    v_18373 = nil;
    goto v_17484;
    v_18373 = nil;
v_17484:
    goto v_17473;
v_17475:
    v_18373 = nil;
    goto v_17473;
    v_18373 = nil;
v_17473:
    if (v_18373 == nil) goto v_17471;
    else goto v_17466;
v_17471:
    goto v_17467;
v_17466:
    goto v_17512;
v_17508:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17509;
v_17510:
    v_18373 = elt(env, 25); // !~
    goto v_17511;
v_17512:
    goto v_17508;
v_17509:
    goto v_17510;
v_17511:
    if (v_18374 == v_18373) goto v_17506;
    else goto v_17507;
v_17506:
    v_18373 = lisp_true;
    stack[-2] = v_18373;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17505;
v_17507:
v_17505:
    goto v_17529;
v_17525:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17526;
v_17527:
    v_18373 = elt(env, 26); // !0
    goto v_17528;
v_17529:
    goto v_17525;
v_17526:
    goto v_17527;
v_17528:
    if (v_18374 == v_18373) goto v_17523;
    else goto v_17524;
v_17523:
    goto v_17540;
v_17536:
    fn = elt(env, 58); // yypeek
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17537;
v_17538:
    v_18373 = elt(env, 27); // x
    goto v_17539;
v_17540:
    goto v_17536;
v_17537:
    goto v_17538;
v_17539:
    if (v_18374 == v_18373) goto v_17534;
    else goto v_17535;
v_17534:
    v_18373 = lisp_true;
    goto v_17533;
v_17535:
    goto v_17550;
v_17546:
    fn = elt(env, 58); // yypeek
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17547;
v_17548:
    v_18373 = elt(env, 28); // !X
    goto v_17549;
v_17550:
    goto v_17546;
v_17547:
    goto v_17548;
v_17549:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17533;
    v_18373 = nil;
v_17533:
    goto v_17522;
v_17524:
    v_18373 = nil;
    goto v_17522;
    v_18373 = nil;
v_17522:
    if (v_18373 == nil) goto v_17520;
    v_18373 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_18373; // yylval
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
v_17561:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 59); // lex_hexval
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    stack[-3] = v_18373;
    if (v_18373 == nil) goto v_17564;
    else goto v_17565;
v_17564:
    goto v_17560;
v_17565:
    goto v_17574;
v_17570:
    goto v_17580;
v_17576:
    v_18374 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_17577;
v_17578:
    v_18373 = qvalue(elt(env, 4)); // yylval
    goto v_17579;
v_17580:
    goto v_17576;
v_17577:
    goto v_17578;
v_17579:
    v_18374 = times2(v_18374, v_18373);
    env = stack[-5];
    goto v_17571;
v_17572:
    v_18373 = stack[-3];
    goto v_17573;
v_17574:
    goto v_17570;
v_17571:
    goto v_17572;
v_17573:
    v_18373 = plus2(v_18374, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_17561;
v_17560:
    v_18373 = stack[-2];
    if (v_18373 == nil) goto v_17587;
    v_18373 = qvalue(elt(env, 4)); // yylval
    v_18373 = negate(v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_17585;
v_17587:
v_17585:
    v_18373 = qvalue(elt(env, 29)); // lex_number_code
    goto v_17135;
v_17520:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = ncons(v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
v_17596:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17599;
    else goto v_17600;
v_17599:
    goto v_17595;
v_17600:
    goto v_17610;
v_17606:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17607;
v_17608:
    v_18373 = stack[-4];
    goto v_17609;
v_17610:
    goto v_17606;
v_17607:
    goto v_17608;
v_17609:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17596;
v_17595:
    goto v_17621;
v_17617:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17618;
v_17619:
    v_18373 = elt(env, 30); // !.
    goto v_17620;
v_17621:
    goto v_17617;
v_17618:
    goto v_17619;
v_17620:
    if (v_18374 == v_18373) goto v_17615;
    else goto v_17616;
v_17615:
    v_18373 = lisp_true;
    stack[-3] = v_18373;
    goto v_17630;
v_17626:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17627;
v_17628:
    v_18373 = stack[-4];
    goto v_17629;
v_17630:
    goto v_17626;
v_17627:
    goto v_17628;
v_17629:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
v_17635:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17638;
    else goto v_17639;
v_17638:
    goto v_17634;
v_17639:
    goto v_17649;
v_17645:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17646;
v_17647:
    v_18373 = stack[-4];
    goto v_17648;
v_17649:
    goto v_17645;
v_17646:
    goto v_17647;
v_17648:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17635;
v_17634:
    goto v_17614;
v_17616:
v_17614:
    goto v_17664;
v_17660:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17661;
v_17662:
    v_18373 = elt(env, 31); // e
    goto v_17663;
v_17664:
    goto v_17660;
v_17661:
    goto v_17662;
v_17663:
    if (v_18374 == v_18373) goto v_17658;
    else goto v_17659;
v_17658:
    v_18373 = lisp_true;
    goto v_17657;
v_17659:
    goto v_17674;
v_17670:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17671;
v_17672:
    v_18373 = elt(env, 32); // !E
    goto v_17673;
v_17674:
    goto v_17670;
v_17671:
    goto v_17672;
v_17673:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17657;
    v_18373 = nil;
v_17657:
    if (v_18373 == nil) goto v_17655;
    v_18373 = stack[-3];
    if (v_18373 == nil) goto v_17680;
    else goto v_17681;
v_17680:
    goto v_17690;
v_17684:
    v_18375 = elt(env, 26); // !0
    goto v_17685;
v_17686:
    v_18374 = elt(env, 30); // !.
    goto v_17687;
v_17688:
    v_18373 = stack[-4];
    goto v_17689;
v_17690:
    goto v_17684;
v_17685:
    goto v_17686;
v_17687:
    goto v_17688;
v_17689:
    v_18373 = list2star(v_18375, v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17679;
v_17681:
v_17679:
    goto v_17700;
v_17696:
    v_18374 = elt(env, 31); // e
    goto v_17697;
v_17698:
    v_18373 = stack[-4];
    goto v_17699;
v_17700:
    goto v_17696;
v_17697:
    goto v_17698;
v_17699:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17716;
v_17712:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17713;
v_17714:
    v_18373 = elt(env, 33); // !+
    goto v_17715;
v_17716:
    goto v_17712;
v_17713:
    goto v_17714;
v_17715:
    if (v_18374 == v_18373) goto v_17710;
    else goto v_17711;
v_17710:
    v_18373 = lisp_true;
    goto v_17709;
v_17711:
    goto v_17726;
v_17722:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17723;
v_17724:
    v_18373 = elt(env, 34); // !-
    goto v_17725;
v_17726:
    goto v_17722;
v_17723:
    goto v_17724;
v_17725:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17709;
    v_18373 = nil;
v_17709:
    if (v_18373 == nil) goto v_17707;
    goto v_17735;
v_17731:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17732;
v_17733:
    v_18373 = stack[-4];
    goto v_17734;
v_17735:
    goto v_17731;
v_17732:
    goto v_17733;
v_17734:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17705;
v_17707:
v_17705:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17741;
    else goto v_17742;
v_17741:
    goto v_17750;
v_17746:
    v_18374 = elt(env, 26); // !0
    goto v_17747;
v_17748:
    v_18373 = stack[-4];
    goto v_17749;
v_17750:
    goto v_17746;
v_17747:
    goto v_17748;
v_17749:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17740;
v_17742:
    goto v_17760;
v_17756:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17757;
v_17758:
    v_18373 = stack[-4];
    goto v_17759;
v_17760:
    goto v_17756;
v_17757:
    goto v_17758;
v_17759:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
v_17765:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Ldigitp(nil, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_17768;
    else goto v_17769;
v_17768:
    goto v_17764;
v_17769:
    goto v_17779;
v_17775:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17776;
v_17777:
    v_18373 = stack[-4];
    goto v_17778;
v_17779:
    goto v_17775;
v_17776:
    goto v_17777;
v_17778:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17765;
v_17764:
    goto v_17740;
v_17740:
    goto v_17653;
v_17655:
v_17653:
    v_18373 = stack[-4];
    v_18373 = Lnreverse(nil, v_18373);
    env = stack[-5];
    v_18373 = Lcompress(nil, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = stack[-2];
    if (v_18373 == nil) goto v_17788;
    v_18373 = qvalue(elt(env, 4)); // yylval
    v_18373 = negate(v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_17786;
v_17788:
v_17786:
    v_18373 = qvalue(elt(env, 29)); // lex_number_code
    goto v_17135;
v_17467:
    goto v_17803;
v_17799:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17800;
v_17801:
    v_18373 = elt(env, 35); // !"
    goto v_17802;
v_17803:
    goto v_17799;
v_17800:
    goto v_17801;
v_17802:
    if (v_18374 == v_18373) goto v_17797;
    else goto v_17798;
v_17797:
    goto v_17812;
v_17808:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17809;
v_17810:
    v_18373 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_17811;
v_17812:
    goto v_17808;
v_17809:
    goto v_17810;
v_17811:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_17796;
v_17798:
    v_18373 = nil;
    goto v_17796;
    v_18373 = nil;
v_17796:
    if (v_18373 == nil) goto v_17794;
    goto v_17829;
v_17825:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17826;
v_17827:
    v_18373 = (LispObject)16384+TAG_FIXNUM; // 1024
    goto v_17828;
v_17829:
    goto v_17825;
v_17826:
    goto v_17827;
v_17828:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_17821;
    else goto v_17822;
v_17821:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=16 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 16, 0);
    qvalue(elt(env, 16)) = nil; // !*lower
v_17839:
    goto v_17852;
v_17848:
    fn = elt(env, 53); // yyreadch
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17849;
v_17850:
    v_18373 = elt(env, 35); // !"
    goto v_17851;
v_17852:
    goto v_17848;
v_17849:
    goto v_17850;
v_17851:
    if (v_18374 == v_18373) goto v_17847;
    v_18373 = lisp_true;
    goto v_17845;
v_17847:
    goto v_17866;
v_17862:
    fn = elt(env, 58); // yypeek
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17863;
v_17864:
    v_18373 = elt(env, 35); // !"
    goto v_17865;
v_17866:
    goto v_17862;
v_17863:
    goto v_17864;
v_17865:
    if (v_18374 == v_18373) goto v_17860;
    else goto v_17861;
v_17860:
    goto v_17873;
v_17869:
    fn = elt(env, 53); // yyreadch
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17870;
v_17871:
    v_18373 = elt(env, 35); // !"
    goto v_17872;
v_17873:
    goto v_17869;
v_17870:
    goto v_17871;
v_17872:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17859;
v_17861:
    v_18373 = nil;
    goto v_17859;
    v_18373 = nil;
v_17859:
    goto v_17845;
    v_18373 = nil;
v_17845:
    if (v_18373 == nil) goto v_17842;
    else goto v_17843;
v_17842:
    goto v_17838;
v_17843:
    goto v_17886;
v_17882:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17883;
v_17884:
    v_18373 = stack[-4];
    goto v_17885;
v_17886:
    goto v_17882;
v_17883:
    goto v_17884;
v_17885:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17839;
v_17838:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17820;
v_17822:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 15, -2);
    qvalue(elt(env, 15)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=16 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 16, -1);
    qvalue(elt(env, 16)) = nil; // !*lower
    stack[0] = nil;
v_17899:
    goto v_17912;
v_17908:
    fn = elt(env, 53); // yyreadch
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17909;
v_17910:
    v_18373 = elt(env, 35); // !"
    goto v_17911;
v_17912:
    goto v_17908;
v_17909:
    goto v_17910;
v_17911:
    if (v_18374 == v_18373) goto v_17907;
    v_18373 = lisp_true;
    goto v_17905;
v_17907:
    goto v_17922;
v_17918:
    v_18374 = stack[0];
    goto v_17919;
v_17920:
    v_18373 = elt(env, 38); // !\ (backslash)
    goto v_17921;
v_17922:
    goto v_17918;
v_17919:
    goto v_17920;
v_17921:
    v_18373 = (v_18374 == v_18373 ? lisp_true : nil);
    goto v_17905;
    v_18373 = nil;
v_17905:
    if (v_18373 == nil) goto v_17902;
    else goto v_17903;
v_17902:
    goto v_17898;
v_17903:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    stack[0] = v_18373;
    goto v_17933;
v_17929:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17930;
v_17931:
    v_18373 = stack[-4];
    goto v_17932;
v_17933:
    goto v_17929;
v_17930:
    goto v_17931;
v_17932:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17899;
v_17898:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17820;
v_17820:
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18373 = stack[-4];
    v_18373 = Lnreverse(nil, v_18373);
    env = stack[-5];
    fn = elt(env, 57); // list2widestring
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 39)); // lex_string_code
    goto v_17135;
v_17794:
    goto v_17951;
v_17947:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17948;
v_17949:
    v_18373 = elt(env, 21); // !'
    goto v_17950;
v_17951:
    goto v_17947;
v_17948:
    goto v_17949;
v_17950:
    if (v_18374 == v_18373) goto v_17945;
    else goto v_17946;
v_17945:
    goto v_17960;
v_17956:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_17957;
v_17958:
    v_18373 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_17959;
v_17960:
    goto v_17956;
v_17957:
    goto v_17958;
v_17959:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_17944;
v_17946:
    v_18373 = nil;
    goto v_17944;
    v_18373 = nil;
v_17944:
    if (v_18373 == nil) goto v_17942;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=16 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 16, 0);
    qvalue(elt(env, 16)) = nil; // !*lower
v_17974:
v_17977:
    goto v_17986;
v_17982:
    fn = elt(env, 53); // yyreadch
    v_18374 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17983;
v_17984:
    v_18373 = elt(env, 21); // !'
    goto v_17985;
v_17986:
    goto v_17982;
v_17983:
    goto v_17984;
v_17985:
    if (v_18374 == v_18373) goto v_17980;
    else goto v_17981;
v_17980:
    goto v_17976;
v_17981:
    goto v_17995;
v_17991:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_17992;
v_17993:
    v_18373 = stack[-4];
    goto v_17994;
v_17995:
    goto v_17991;
v_17992:
    goto v_17993;
v_17994:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_17977;
v_17976:
    goto v_18003;
v_17999:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18000;
v_18001:
    v_18373 = stack[-4];
    goto v_18002;
v_18003:
    goto v_17999;
v_18000:
    goto v_18001;
v_18002:
    v_18373 = cons(v_18374, v_18373);
    env = stack[-5];
    stack[-4] = v_18373;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18015;
v_18011:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18012;
v_18013:
    v_18373 = elt(env, 21); // !'
    goto v_18014;
v_18015:
    goto v_18011;
v_18012:
    goto v_18013;
v_18014:
    if (v_18374 == v_18373) goto v_18009;
    else goto v_18010;
v_18009:
    goto v_17974;
v_18010:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18373 = stack[-4];
    v_18373 = qcdr(v_18373);
    v_18373 = Lnreverse(nil, v_18373);
    env = stack[-5];
    fn = elt(env, 57); // list2widestring
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 40)); // lex_char_code
    goto v_17135;
v_17942:
    goto v_18033;
v_18029:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18030;
v_18031:
    v_18373 = elt(env, 21); // !'
    goto v_18032;
v_18033:
    goto v_18029;
v_18030:
    goto v_18031;
v_18032:
    if (v_18374 == v_18373) goto v_18027;
    else goto v_18028;
v_18027:
    goto v_18042;
v_18038:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18039;
v_18040:
    v_18373 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_18041;
v_18042:
    goto v_18038;
v_18039:
    goto v_18040;
v_18041:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_18026;
v_18028:
    v_18373 = nil;
    goto v_18026;
    v_18373 = nil;
v_18026:
    if (v_18373 == nil) goto v_18024;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 60); // read_s_expression
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18056;
v_18052:
    v_18374 = elt(env, 41); // quote
    goto v_18053;
v_18054:
    v_18373 = qvalue(elt(env, 4)); // yylval
    goto v_18055;
v_18056:
    goto v_18052;
v_18053:
    goto v_18054;
v_18055:
    v_18373 = list2(v_18374, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 42)); // lex_list_code
    goto v_17135;
v_18024:
    goto v_18070;
v_18066:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18067;
v_18068:
    v_18373 = elt(env, 43); // !`
    goto v_18069;
v_18070:
    goto v_18066;
v_18067:
    goto v_18068;
v_18069:
    if (v_18374 == v_18373) goto v_18064;
    else goto v_18065;
v_18064:
    goto v_18079;
v_18075:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18076;
v_18077:
    v_18373 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_18078;
v_18079:
    goto v_18075;
v_18076:
    goto v_18077;
v_18078:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_18063;
v_18065:
    v_18373 = nil;
    goto v_18063;
    v_18373 = nil;
v_18063:
    if (v_18373 == nil) goto v_18061;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 60); // read_s_expression
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18093;
v_18089:
    v_18374 = elt(env, 44); // backquote
    goto v_18090;
v_18091:
    v_18373 = qvalue(elt(env, 4)); // yylval
    goto v_18092;
v_18093:
    goto v_18089;
v_18090:
    goto v_18091;
v_18092:
    v_18373 = list2(v_18374, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = qvalue(elt(env, 42)); // lex_list_code
    goto v_17135;
v_18061:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_18108;
v_18104:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18105;
v_18106:
    v_18373 = qvalue(elt(env, 11)); // !$eof!$
    goto v_18107;
v_18108:
    goto v_18104;
v_18105:
    goto v_18106;
v_18107:
    if (equal(v_18374, v_18373)) goto v_18102;
    else goto v_18103;
v_18102:
    v_18373 = qvalue(elt(env, 12)); // lex_eof_code
    goto v_17135;
v_18103:
    goto v_18128;
v_18124:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18125;
v_18126:
    v_18373 = elt(env, 45); // !#
    goto v_18127;
v_18128:
    goto v_18124;
v_18125:
    goto v_18126;
v_18127:
    if (v_18374 == v_18373) goto v_18122;
    else goto v_18123;
v_18122:
    goto v_18137;
v_18133:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18134;
v_18135:
    v_18373 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_18136;
v_18137:
    goto v_18133;
v_18134:
    goto v_18135;
v_18136:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    v_18373 = (v_18373 == nil ? lisp_true : nil);
    goto v_18121;
v_18123:
    v_18373 = nil;
    goto v_18121;
    v_18373 = nil;
v_18121:
    if (v_18373 == nil) goto v_18119;
    v_18373 = lisp_true;
    goto v_18117;
v_18119:
    goto v_18155;
v_18151:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18152;
v_18153:
    v_18373 = elt(env, 46); // lex_dipthong
    goto v_18154;
v_18155:
    goto v_18151;
v_18152:
    goto v_18153;
v_18154:
    v_18373 = get(v_18374, v_18373);
    env = stack[-5];
    if (v_18373 == nil) goto v_18149;
    else goto v_18148;
v_18149:
    goto v_18168;
v_18164:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18165;
v_18166:
    v_18373 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18167;
v_18168:
    goto v_18164;
v_18165:
    goto v_18166;
v_18167:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_18160;
    else goto v_18161;
v_18160:
    goto v_18176;
v_18172:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18173;
v_18174:
    v_18373 = elt(env, 47); // sml_opchar
    goto v_18175;
v_18176:
    goto v_18172;
v_18173:
    goto v_18174;
v_18175:
    v_18373 = Lflagp(nil, v_18374, v_18373);
    env = stack[-5];
    goto v_18159;
v_18161:
    v_18373 = nil;
    goto v_18159;
    v_18373 = nil;
v_18159:
v_18148:
    goto v_18117;
    v_18373 = nil;
v_18117:
    if (v_18373 == nil) goto v_18115;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18113;
v_18115:
    v_18373 = elt(env, 8); // ! 
    qvalue(elt(env, 7)) = v_18373; // lex_char
    goto v_18113;
v_18113:
    goto v_18199;
v_18195:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18196;
v_18197:
    v_18373 = elt(env, 45); // !#
    goto v_18198;
v_18199:
    goto v_18195;
v_18196:
    goto v_18197;
v_18198:
    if (v_18374 == v_18373) goto v_18193;
    else goto v_18194;
v_18193:
    goto v_18212;
v_18208:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18209;
v_18210:
    v_18373 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_18211;
v_18212:
    goto v_18208;
v_18209:
    goto v_18210;
v_18211:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_18204;
    else goto v_18205;
v_18204:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = Lalpha_char_p(nil, v_18373);
    env = stack[-5];
    goto v_18203;
v_18205:
    v_18373 = nil;
    goto v_18203;
    v_18373 = nil;
v_18203:
    goto v_18192;
v_18194:
    v_18373 = nil;
    goto v_18192;
    v_18373 = nil;
v_18192:
    if (v_18373 == nil) goto v_18190;
    else goto v_18188;
v_18190:
    goto v_18228;
v_18224:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18225;
v_18226:
    v_18373 = elt(env, 13); // !!
    goto v_18227;
v_18228:
    goto v_18224;
v_18225:
    goto v_18226;
v_18227:
    if (v_18374 == v_18373) goto v_18188;
    goto v_18189;
v_18188:
    v_18373 = CC_lex_basic_token(elt(env, 0), 0);
    env = stack[-5];
    stack[-4] = v_18373;
    goto v_18240;
v_18236:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18237;
v_18238:
    v_18373 = elt(env, 48); // (if else elif endif define eval)
    goto v_18239;
v_18240:
    goto v_18236;
v_18237:
    goto v_18238;
v_18239:
    v_18373 = Lmemq(nil, v_18374, v_18373);
    if (v_18373 == nil) goto v_18235;
    goto v_18251;
v_18247:
    stack[0] = elt(env, 45); // !#
    goto v_18248;
v_18249:
    v_18373 = qvalue(elt(env, 4)); // yylval
    v_18373 = Lsymbol_name(nil, v_18373);
    env = stack[-5];
    fn = elt(env, 61); // widestring2list
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    goto v_18250;
v_18251:
    goto v_18247;
v_18248:
    goto v_18249;
v_18250:
    v_18373 = cons(stack[0], v_18373);
    env = stack[-5];
    fn = elt(env, 57); // list2widestring
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    v_18373 = Lintern(nil, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_18233;
v_18235:
    v_18373 = stack[-4];
    qvalue(elt(env, 2)) = v_18373; // lex_peeked
    v_18373 = qvalue(elt(env, 4)); // yylval
    qvalue(elt(env, 3)) = v_18373; // lex_peeked_yylval
    v_18373 = qvalue(elt(env, 6)); // lex_escaped
    qvalue(elt(env, 5)) = v_18373; // lex_peeked_escaped
    v_18373 = elt(env, 45); // !#
    qvalue(elt(env, 4)) = v_18373; // yylval
    v_18373 = nil;
    qvalue(elt(env, 6)) = v_18373; // lex_escaped
    goto v_18233;
v_18233:
    goto v_18187;
v_18189:
v_18187:
v_18265:
    goto v_18274;
v_18270:
    v_18375 = qvalue(elt(env, 7)); // lex_char
    goto v_18271;
v_18272:
    goto v_18281;
v_18277:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18278;
v_18279:
    v_18373 = elt(env, 46); // lex_dipthong
    goto v_18280;
v_18281:
    goto v_18277;
v_18278:
    goto v_18279;
v_18280:
    v_18373 = get(v_18374, v_18373);
    env = stack[-5];
    goto v_18273;
v_18274:
    goto v_18270;
v_18271:
    goto v_18272;
v_18273:
    v_18373 = Latsoc(nil, v_18375, v_18373);
    stack[-3] = v_18373;
    if (v_18373 == nil) goto v_18268;
    else goto v_18269;
v_18268:
    goto v_18264;
v_18269:
    v_18373 = stack[-3];
    v_18373 = qcdr(v_18373);
    qvalue(elt(env, 4)) = v_18373; // yylval
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18265;
v_18264:
    goto v_18303;
v_18299:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18300;
v_18301:
    v_18373 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18302;
v_18303:
    goto v_18299;
v_18300:
    goto v_18301;
v_18302:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_18295;
    else goto v_18296;
v_18295:
    v_18373 = qvalue(elt(env, 4)); // yylval
    v_18373 = Lexplodec(nil, v_18373);
    env = stack[-5];
    stack[-3] = v_18373;
    fn = elt(env, 62); // all_sml_opchar
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    goto v_18294;
v_18296:
    v_18373 = nil;
    goto v_18294;
    v_18373 = nil;
v_18294:
    if (v_18373 == nil) goto v_18292;
v_18314:
    goto v_18329;
v_18325:
    v_18374 = qvalue(elt(env, 14)); // lexer_style!*
    goto v_18326;
v_18327:
    v_18373 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18328;
v_18329:
    goto v_18325;
v_18326:
    goto v_18327;
v_18328:
    fn = elt(env, 55); // land
    v_18373 = (*qfn2(fn))(fn, v_18374, v_18373);
    env = stack[-5];
    v_18373 = (LispObject)zerop(v_18373);
    v_18373 = v_18373 ? lisp_true : nil;
    env = stack[-5];
    if (v_18373 == nil) goto v_18321;
    else goto v_18322;
v_18321:
    goto v_18337;
v_18333:
    v_18374 = qvalue(elt(env, 7)); // lex_char
    goto v_18334;
v_18335:
    v_18373 = elt(env, 47); // sml_opchar
    goto v_18336;
v_18337:
    goto v_18333;
v_18334:
    goto v_18335;
v_18336:
    v_18373 = Lflagp(nil, v_18374, v_18373);
    env = stack[-5];
    goto v_18320;
v_18322:
    v_18373 = nil;
    goto v_18320;
    v_18373 = nil;
v_18320:
    if (v_18373 == nil) goto v_18317;
    else goto v_18318;
v_18317:
    goto v_18313;
v_18318:
    goto v_18349;
v_18345:
    stack[0] = stack[-3];
    goto v_18346;
v_18347:
    v_18373 = qvalue(elt(env, 7)); // lex_char
    v_18373 = ncons(v_18373);
    env = stack[-5];
    goto v_18348;
v_18349:
    goto v_18345;
v_18346:
    goto v_18347;
v_18348:
    v_18373 = Lappend(nil, stack[0], v_18373);
    env = stack[-5];
    stack[-3] = v_18373;
    fn = elt(env, 53); // yyreadch
    v_18373 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18314;
v_18313:
    v_18373 = stack[-3];
    fn = elt(env, 63); // list2string
    v_18373 = (*qfn1(fn))(fn, v_18373);
    env = stack[-5];
    v_18373 = Lintern(nil, v_18373);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_18373; // yylval
    goto v_18290;
v_18292:
v_18290:
    goto v_18366;
v_18362:
    v_18374 = qvalue(elt(env, 4)); // yylval
    goto v_18363;
v_18364:
    v_18373 = elt(env, 20); // lex_code
    goto v_18365;
v_18366:
    goto v_18362;
v_18363:
    goto v_18364;
v_18365:
    v_18373 = get(v_18374, v_18373);
    env = stack[-5];
    stack[-3] = v_18373;
    if (v_18373 == nil) goto v_18360;
    v_18373 = stack[-3];
    goto v_17135;
v_18360:
    v_18373 = qvalue(elt(env, 24)); // lex_symbol_code
    goto v_17135;
    goto v_17236;
v_17236:
    v_18373 = nil;
v_17135:
    return onevalue(v_18373);
}



// Code for formproc

static LispObject CC_formproc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17935, v_17936, v_17937, v_17938;
    LispObject fn;
    LispObject v_17132, v_17131, v_17130;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formproc");
    va_start(aa, nargs);
    v_17130 = va_arg(aa, LispObject);
    v_17131 = va_arg(aa, LispObject);
    v_17132 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_17132,v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_17130,v_17131,v_17132);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-2] = v_17132;
    stack[-1] = v_17131;
    stack[0] = v_17130;
// end of prologue
// Binding fname!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-10, 1, -6);
    qvalue(elt(env, 1)) = nil; // fname!*
    stack[-8] = nil;
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    stack[0] = v_17935;
    v_17935 = stack[0];
    v_17935 = qcar(v_17935);
    qvalue(elt(env, 1)) = v_17935; // fname!*
    stack[-5] = v_17935;
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    if (v_17935 == nil) goto v_17154;
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    stack[-2] = v_17935;
    goto v_17152;
v_17154:
v_17152:
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcdr(v_17935);
    stack[0] = v_17935;
    v_17935 = stack[0];
    v_17935 = qcar(v_17935);
    qvalue(elt(env, 3)) = v_17935; // ftype!*
    stack[-4] = v_17935;
    v_17935 = stack[-5];
    if (!symbolp(v_17935)) v_17935 = nil;
    else { v_17935 = qfastgets(v_17935);
           if (v_17935 != nil) { v_17935 = elt(v_17935, 1); // lose
#ifdef RECORD_GET
             if (v_17935 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_17935 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_17935 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_17935 == SPID_NOPROP) v_17935 = nil; else v_17935 = lisp_true; }}
#endif
    if (v_17935 == nil) goto v_17173;
    v_17935 = qvalue(elt(env, 4)); // !*lose
    if (v_17935 == nil) goto v_17178;
    else goto v_17177;
v_17178:
    v_17935 = qvalue(elt(env, 5)); // !*defn
    v_17935 = (v_17935 == nil ? lisp_true : nil);
v_17177:
    goto v_17171;
v_17173:
    v_17935 = nil;
    goto v_17171;
    v_17935 = nil;
v_17171:
    if (v_17935 == nil) goto v_17169;
    goto v_17191;
v_17187:
    v_17936 = stack[-5];
    goto v_17188;
v_17189:
    v_17935 = elt(env, 6); // "not defined (LOSE flag)"
    goto v_17190;
v_17191:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    v_17935 = list2(v_17936, v_17935);
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    v_17935 = elt(env, 7); // (quote nil)
    goto v_17145;
v_17169:
    v_17935 = qvalue(elt(env, 8)); // !*redeflg!*
    if (v_17935 == nil) goto v_17196;
    v_17935 = stack[-5];
    fn = elt(env, 50); // getd
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    if (v_17935 == nil) goto v_17196;
    goto v_17208;
v_17204:
    v_17936 = stack[-5];
    goto v_17205;
v_17206:
    v_17935 = elt(env, 9); // "redefined"
    goto v_17207;
v_17208:
    goto v_17204;
v_17205:
    goto v_17206;
v_17207:
    v_17935 = list2(v_17936, v_17935);
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17167;
v_17196:
v_17167:
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    stack[-3] = v_17935;
v_17216:
    v_17935 = stack[-3];
    if (v_17935 == nil) goto v_17219;
    else goto v_17220;
v_17219:
    goto v_17215;
v_17220:
    v_17935 = stack[-3];
    v_17935 = qcar(v_17935);
    if (v_17935 == nil) goto v_17229;
    else goto v_17230;
v_17229:
    v_17935 = lisp_true;
    goto v_17228;
v_17230:
    goto v_17240;
v_17236:
    v_17935 = stack[-3];
    v_17936 = qcar(v_17935);
    goto v_17237;
v_17238:
    v_17935 = lisp_true;
    goto v_17239;
v_17240:
    goto v_17236;
v_17237:
    goto v_17238;
v_17239:
    v_17935 = (v_17936 == v_17935 ? lisp_true : nil);
    goto v_17228;
    v_17935 = nil;
v_17228:
    if (v_17935 == nil) goto v_17226;
    v_17935 = stack[-3];
    v_17935 = qcar(v_17935);
    fn = elt(env, 51); // rsverr
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17224;
v_17226:
v_17224:
    v_17935 = stack[-3];
    v_17935 = qcdr(v_17935);
    stack[-3] = v_17935;
    goto v_17216;
v_17215:
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    stack[-3] = v_17935;
v_17255:
    v_17935 = stack[-3];
    if (v_17935 == nil) goto v_17258;
    else goto v_17259;
v_17258:
    goto v_17254;
v_17259:
    v_17935 = stack[-3];
    v_17935 = qcar(v_17935);
    v_17935 = Lsymbol_specialp(nil, v_17935);
    env = stack[-10];
    if (v_17935 == nil) goto v_17266;
    else goto v_17264;
v_17266:
    v_17935 = stack[-3];
    v_17935 = qcar(v_17935);
    v_17935 = Lsymbol_globalp(nil, v_17935);
    env = stack[-10];
    if (v_17935 == nil) goto v_17270;
    else goto v_17264;
v_17270:
    goto v_17265;
v_17264:
    goto v_17279;
v_17275:
    v_17935 = stack[-3];
    v_17936 = qcar(v_17935);
    goto v_17276;
v_17277:
    v_17935 = stack[-8];
    goto v_17278;
v_17279:
    goto v_17275;
v_17276:
    goto v_17277;
v_17278:
    v_17935 = cons(v_17936, v_17935);
    env = stack[-10];
    stack[-8] = v_17935;
    goto v_17263;
v_17265:
v_17263:
    v_17935 = stack[-3];
    v_17935 = qcdr(v_17935);
    stack[-3] = v_17935;
    goto v_17255;
v_17254:
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    stack[-3] = v_17935;
    v_17935 = stack[0];
    v_17935 = qcdr(v_17935);
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    stack[-7] = v_17935;
    goto v_17301;
v_17297:
    v_17936 = stack[-7];
    goto v_17298;
v_17299:
    v_17935 = elt(env, 10); // rblock
    goto v_17300;
v_17301:
    goto v_17297;
v_17298:
    goto v_17299;
v_17300:
    if (!consp(v_17936)) goto v_17295;
    v_17936 = qcar(v_17936);
    if (v_17936 == v_17935) goto v_17294;
    else goto v_17295;
v_17294:
    v_17935 = stack[-7];
    v_17935 = qcdr(v_17935);
    v_17935 = qcar(v_17935);
    goto v_17293;
v_17295:
    v_17935 = nil;
    goto v_17293;
    v_17935 = nil;
v_17293:
    stack[0] = v_17935;
    goto v_17319;
v_17311:
    v_17938 = stack[-3];
    goto v_17312;
v_17313:
    v_17937 = stack[0];
    goto v_17314;
v_17315:
    v_17936 = stack[-1];
    goto v_17316;
v_17317:
    v_17935 = stack[-2];
    goto v_17318;
v_17319:
    goto v_17311;
v_17312:
    goto v_17313;
v_17314:
    goto v_17315;
v_17316:
    goto v_17317;
v_17318:
    fn = elt(env, 52); // pairxvars
    v_17935 = (*qfnn(fn))(fn, 4, v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    stack[-1] = v_17935;
    v_17935 = stack[0];
    if (v_17935 == nil) goto v_17327;
    goto v_17334;
v_17330:
    v_17935 = stack[-7];
    stack[0] = qcar(v_17935);
    goto v_17331;
v_17332:
    goto v_17342;
v_17338:
    v_17935 = stack[-7];
    v_17936 = qcdr(v_17935);
    goto v_17339;
v_17340:
    v_17935 = stack[-1];
    v_17935 = qcdr(v_17935);
    goto v_17341;
v_17342:
    goto v_17338;
v_17339:
    goto v_17340;
v_17341:
    fn = elt(env, 53); // rplaca!*
    v_17935 = (*qfn2(fn))(fn, v_17936, v_17935);
    env = stack[-10];
    goto v_17333;
v_17334:
    goto v_17330;
v_17331:
    goto v_17332;
v_17333:
    v_17935 = cons(stack[0], v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17325;
v_17327:
v_17325:
    goto v_17356;
v_17352:
    v_17936 = stack[-5];
    goto v_17353;
v_17354:
    v_17935 = elt(env, 11); // formc
    goto v_17355;
v_17356:
    goto v_17352;
v_17353:
    goto v_17354;
v_17355:
    v_17935 = Lflagp(nil, v_17936, v_17935);
    env = stack[-10];
    if (v_17935 == nil) goto v_17350;
    goto v_17366;
v_17360:
    v_17937 = stack[-7];
    goto v_17361;
v_17362:
    v_17935 = stack[-1];
    v_17936 = qcar(v_17935);
    goto v_17363;
v_17364:
    v_17935 = stack[-2];
    goto v_17365;
v_17366:
    goto v_17360;
v_17361:
    goto v_17362;
v_17363:
    goto v_17364;
v_17365:
    fn = elt(env, 11); // formc
    v_17935 = (*qfnn(fn))(fn, 3, v_17937, v_17936, v_17935);
    env = stack[-10];
    goto v_17348;
v_17350:
    goto v_17380;
v_17374:
    v_17937 = stack[-7];
    goto v_17375;
v_17376:
    v_17935 = stack[-1];
    v_17936 = qcar(v_17935);
    goto v_17377;
v_17378:
    v_17935 = stack[-2];
    goto v_17379;
v_17380:
    goto v_17374;
v_17375:
    goto v_17376;
v_17377:
    goto v_17378;
v_17379:
    fn = elt(env, 54); // form1
    v_17935 = (*qfnn(fn))(fn, 3, v_17937, v_17936, v_17935);
    env = stack[-10];
    goto v_17348;
    v_17935 = nil;
v_17348:
    stack[-7] = v_17935;
    v_17935 = qvalue(elt(env, 12)); // !*noinlines
    if (v_17935 == nil) goto v_17388;
    goto v_17396;
v_17392:
    v_17936 = stack[-4];
    goto v_17393;
v_17394:
    v_17935 = elt(env, 13); // inline
    goto v_17395;
v_17396:
    goto v_17392;
v_17393:
    goto v_17394;
v_17395:
    if (v_17936 == v_17935) goto v_17391;
    else goto v_17388;
v_17391:
    v_17935 = elt(env, 14); // expr
    stack[-4] = v_17935;
    goto v_17386;
v_17388:
v_17386:
    v_17935 = stack[-8];
    if (v_17935 == nil) goto v_17403;
    goto v_17411;
v_17407:
    v_17936 = stack[-4];
    goto v_17408;
v_17409:
    v_17935 = elt(env, 15); // (expr fexpr macro)
    goto v_17410;
v_17411:
    goto v_17407;
v_17408:
    goto v_17409;
v_17410:
    v_17935 = Lmemq(nil, v_17936, v_17935);
    if (v_17935 == nil) goto v_17403;
    goto v_17422;
v_17416:
    stack[-1] = elt(env, 16); // progn
    goto v_17417;
v_17418:
    goto v_17429;
v_17425:
    stack[0] = elt(env, 17); // declare
    goto v_17426;
v_17427:
    goto v_17436;
v_17432:
    v_17936 = elt(env, 18); // special
    goto v_17433;
v_17434:
    v_17935 = stack[-8];
    goto v_17435;
v_17436:
    goto v_17432;
v_17433:
    goto v_17434;
v_17435:
    v_17935 = cons(v_17936, v_17935);
    env = stack[-10];
    goto v_17428;
v_17429:
    goto v_17425;
v_17426:
    goto v_17427;
v_17428:
    v_17936 = list2(stack[0], v_17935);
    env = stack[-10];
    goto v_17419;
v_17420:
    v_17935 = stack[-7];
    goto v_17421;
v_17422:
    goto v_17416;
v_17417:
    goto v_17418;
v_17419:
    goto v_17420;
v_17421:
    v_17935 = list3(stack[-1], v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17401;
v_17403:
v_17401:
    v_17935 = stack[-7];
    stack[-8] = v_17935;
    goto v_17449;
v_17445:
    v_17936 = stack[-4];
    goto v_17446;
v_17447:
    v_17935 = elt(env, 13); // inline
    goto v_17448;
v_17449:
    goto v_17445;
v_17446:
    goto v_17447;
v_17448:
    if (v_17936 == v_17935) goto v_17443;
    else goto v_17444;
v_17443:
    goto v_17463;
v_17457:
    v_17937 = elt(env, 20); // lambda
    goto v_17458;
v_17459:
    v_17936 = stack[-3];
    goto v_17460;
v_17461:
    v_17935 = stack[-7];
    goto v_17462;
v_17463:
    goto v_17457;
v_17458:
    goto v_17459;
v_17460:
    goto v_17461;
v_17462:
    v_17935 = list3(v_17937, v_17936, v_17935);
    env = stack[-10];
    stack[0] = v_17935;
    goto v_17475;
v_17471:
    v_17937 = stack[0];
    goto v_17472;
v_17473:
    goto v_17482;
v_17478:
    v_17936 = stack[-5];
    goto v_17479;
v_17480:
    v_17935 = elt(env, 13); // inline
    goto v_17481;
v_17482:
    goto v_17478;
v_17479:
    goto v_17480;
v_17481:
    v_17935 = get(v_17936, v_17935);
    env = stack[-10];
    goto v_17474;
v_17475:
    goto v_17471;
v_17472:
    goto v_17473;
v_17474:
    if (equal(v_17937, v_17935)) goto v_17470;
    v_17935 = Lposn(nil, 0);
    env = stack[-10];
    v_17935 = (LispObject)zerop(v_17935);
    v_17935 = v_17935 ? lisp_true : nil;
    env = stack[-10];
    if (v_17935 == nil) goto v_17487;
    else goto v_17488;
v_17487:
    v_17935 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_17486;
v_17488:
v_17486:
    v_17935 = elt(env, 21); // "+++ Record new inline definition:"
    v_17935 = Lprinc(nil, v_17935);
    env = stack[-10];
    v_17935 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_17505;
v_17497:
    v_17938 = elt(env, 22); // de
    goto v_17498;
v_17499:
    v_17937 = stack[-5];
    goto v_17500;
v_17501:
    v_17936 = stack[-3];
    goto v_17502;
v_17503:
    v_17935 = stack[-7];
    goto v_17504;
v_17505:
    goto v_17497;
v_17498:
    goto v_17499;
v_17500:
    goto v_17501;
v_17502:
    goto v_17503;
v_17504:
    v_17935 = list4(v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    v_17935 = Lprint(nil, v_17935);
    env = stack[-10];
    goto v_17517;
v_17511:
    v_17937 = stack[-5];
    goto v_17512;
v_17513:
    v_17936 = stack[0];
    goto v_17514;
v_17515:
    v_17935 = qvalue(elt(env, 23)); // new_inline_definitions
    goto v_17516;
v_17517:
    goto v_17511;
v_17512:
    goto v_17513;
v_17514:
    goto v_17515;
v_17516:
    v_17935 = acons(v_17937, v_17936, v_17935);
    env = stack[-10];
    qvalue(elt(env, 23)) = v_17935; // new_inline_definitions
    goto v_17468;
v_17470:
v_17468:
    goto v_17442;
v_17444:
v_17442:
    goto v_17534;
v_17530:
    v_17936 = stack[-4];
    goto v_17531;
v_17532:
    v_17935 = elt(env, 13); // inline
    goto v_17533;
v_17534:
    goto v_17530;
v_17531:
    goto v_17532;
v_17533:
    if (v_17936 == v_17935) goto v_17529;
    goto v_17542;
v_17538:
    v_17936 = stack[-5];
    goto v_17539;
v_17540:
    v_17935 = elt(env, 13); // inline
    goto v_17541;
v_17542:
    goto v_17538;
v_17539:
    goto v_17540;
v_17541:
    v_17935 = get(v_17936, v_17935);
    env = stack[-10];
    goto v_17527;
v_17529:
    v_17935 = nil;
    goto v_17527;
    v_17935 = nil;
v_17527:
    if (v_17935 == nil) goto v_17525;
    else goto v_17523;
v_17525:
    goto v_17557;
v_17553:
    v_17936 = stack[-4];
    goto v_17554;
v_17555:
    v_17935 = elt(env, 24); // smacro
    goto v_17556;
v_17557:
    goto v_17553;
v_17554:
    goto v_17555;
v_17556:
    if (v_17936 == v_17935) goto v_17552;
    goto v_17565;
v_17561:
    v_17936 = stack[-5];
    goto v_17562;
v_17563:
    v_17935 = elt(env, 24); // smacro
    goto v_17564;
v_17565:
    goto v_17561;
v_17562:
    goto v_17563;
v_17564:
    v_17935 = get(v_17936, v_17935);
    env = stack[-10];
    goto v_17550;
v_17552:
    v_17935 = nil;
    goto v_17550;
    v_17935 = nil;
v_17550:
    if (v_17935 == nil) goto v_17548;
    else goto v_17523;
v_17548:
    goto v_17524;
v_17523:
    goto v_17579;
v_17573:
    v_17937 = elt(env, 25); // "SMACRO/INLINE"
    goto v_17574;
v_17575:
    v_17936 = stack[-5];
    goto v_17576;
v_17577:
    v_17935 = elt(env, 9); // "redefined"
    goto v_17578;
v_17579:
    goto v_17573;
v_17574:
    goto v_17575;
v_17576:
    goto v_17577;
v_17578:
    v_17935 = list3(v_17937, v_17936, v_17935);
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17522;
v_17524:
v_17522:
    goto v_17590;
v_17584:
    v_17937 = stack[-3];
    goto v_17585;
v_17586:
    v_17936 = stack[-7];
    goto v_17587;
v_17588:
    v_17935 = stack[-2];
    goto v_17589;
v_17590:
    goto v_17584;
v_17585:
    goto v_17586;
v_17587:
    goto v_17588;
v_17589:
    fn = elt(env, 55); // symbvarlst
    v_17935 = (*qfnn(fn))(fn, 3, v_17937, v_17936, v_17935);
    env = stack[-10];
    goto v_17602;
v_17598:
    v_17936 = stack[-4];
    goto v_17599;
v_17600:
    v_17935 = elt(env, 14); // expr
    goto v_17601;
v_17602:
    goto v_17598;
v_17599:
    goto v_17600;
v_17601:
    if (v_17936 == v_17935) goto v_17596;
    else goto v_17597;
v_17596:
    goto v_17614;
v_17606:
    v_17938 = elt(env, 22); // de
    goto v_17607;
v_17608:
    v_17937 = stack[-5];
    goto v_17609;
v_17610:
    v_17936 = stack[-3];
    goto v_17611;
v_17612:
    v_17935 = stack[-7];
    goto v_17613;
v_17614:
    goto v_17606;
v_17607:
    goto v_17608;
v_17609:
    goto v_17610;
v_17611:
    goto v_17612;
v_17613:
    v_17935 = list4(v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17595;
v_17597:
    goto v_17625;
v_17621:
    v_17936 = stack[-4];
    goto v_17622;
v_17623:
    v_17935 = elt(env, 26); // fexpr
    goto v_17624;
v_17625:
    goto v_17621;
v_17622:
    goto v_17623;
v_17624:
    if (v_17936 == v_17935) goto v_17619;
    else goto v_17620;
v_17619:
    goto v_17637;
v_17629:
    v_17938 = elt(env, 27); // df
    goto v_17630;
v_17631:
    v_17937 = stack[-5];
    goto v_17632;
v_17633:
    v_17936 = stack[-3];
    goto v_17634;
v_17635:
    v_17935 = stack[-7];
    goto v_17636;
v_17637:
    goto v_17629;
v_17630:
    goto v_17631;
v_17632:
    goto v_17633;
v_17634:
    goto v_17635;
v_17636:
    v_17935 = list4(v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17595;
v_17620:
    goto v_17648;
v_17644:
    v_17936 = stack[-4];
    goto v_17645;
v_17646:
    v_17935 = elt(env, 28); // macro
    goto v_17647;
v_17648:
    goto v_17644;
v_17645:
    goto v_17646;
v_17647:
    if (v_17936 == v_17935) goto v_17642;
    else goto v_17643;
v_17642:
    goto v_17660;
v_17652:
    v_17938 = elt(env, 29); // dm
    goto v_17653;
v_17654:
    v_17937 = stack[-5];
    goto v_17655;
v_17656:
    v_17936 = stack[-3];
    goto v_17657;
v_17658:
    v_17935 = stack[-7];
    goto v_17659;
v_17660:
    goto v_17652;
v_17653:
    goto v_17654;
v_17655:
    goto v_17656;
v_17657:
    goto v_17658;
v_17659:
    v_17935 = list4(v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17595;
v_17643:
    goto v_17672;
v_17668:
    v_17936 = stack[-4];
    goto v_17669;
v_17670:
    v_17935 = elt(env, 30); // procfn
    goto v_17671;
v_17672:
    goto v_17668;
v_17669:
    goto v_17670;
v_17671:
    v_17935 = get(v_17936, v_17935);
    env = stack[-10];
    stack[0] = v_17935;
    if (v_17935 == nil) goto v_17666;
    goto v_17684;
v_17676:
    v_17938 = stack[0];
    goto v_17677;
v_17678:
    v_17937 = stack[-5];
    goto v_17679;
v_17680:
    v_17936 = stack[-3];
    goto v_17681;
v_17682:
    v_17935 = stack[-7];
    goto v_17683;
v_17684:
    goto v_17676;
v_17677:
    goto v_17678;
v_17679:
    goto v_17680;
v_17681:
    goto v_17682;
v_17683:
    v_17935 = Lapply3(nil, 4, v_17938, v_17937, v_17936, v_17935);
    goto v_17145;
v_17666:
    goto v_17700;
v_17692:
    stack[-9] = elt(env, 31); // putc
    goto v_17693;
v_17694:
    v_17935 = stack[-5];
    stack[-1] = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17695;
v_17696:
    v_17935 = stack[-4];
    stack[0] = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17697;
v_17698:
    goto v_17714;
v_17708:
    v_17937 = elt(env, 20); // lambda
    goto v_17709;
v_17710:
    v_17936 = stack[-3];
    goto v_17711;
v_17712:
    v_17935 = stack[-7];
    goto v_17713;
v_17714:
    goto v_17708;
v_17709:
    goto v_17710;
v_17711:
    goto v_17712;
v_17713:
    v_17935 = list3(v_17937, v_17936, v_17935);
    env = stack[-10];
    v_17935 = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17699;
v_17700:
    goto v_17692;
v_17693:
    goto v_17694;
v_17695:
    goto v_17696;
v_17697:
    goto v_17698;
v_17699:
    v_17935 = list4(stack[-9], stack[-1], stack[0], v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17595;
v_17595:
    goto v_17726;
v_17722:
    v_17936 = stack[-2];
    goto v_17723;
v_17724:
    v_17935 = elt(env, 32); // symbolic
    goto v_17725;
v_17726:
    goto v_17722;
v_17723:
    goto v_17724;
v_17725:
    if (v_17936 == v_17935) goto v_17721;
    goto v_17734;
v_17730:
    goto v_17742;
v_17736:
    stack[-1] = elt(env, 33); // flag
    goto v_17737;
v_17738:
    v_17935 = stack[-5];
    v_17935 = ncons(v_17935);
    env = stack[-10];
    stack[0] = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17739;
v_17740:
    v_17935 = elt(env, 34); // opfn
    v_17935 = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17741;
v_17742:
    goto v_17736;
v_17737:
    goto v_17738;
v_17739:
    goto v_17740;
v_17741:
    v_17936 = list3(stack[-1], stack[0], v_17935);
    env = stack[-10];
    goto v_17731;
v_17732:
    v_17935 = stack[-7];
    goto v_17733;
v_17734:
    goto v_17730;
v_17731:
    goto v_17732;
v_17733:
    fn = elt(env, 56); // mkprogn
    v_17935 = (*qfn2(fn))(fn, v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17719;
v_17721:
v_17719:
    v_17935 = qvalue(elt(env, 35)); // !*argnochk
    if (v_17935 == nil) goto v_17753;
    goto v_17761;
v_17757:
    v_17936 = stack[-4];
    goto v_17758;
v_17759:
    v_17935 = elt(env, 36); // (expr inline smacro)
    goto v_17760;
v_17761:
    goto v_17757;
v_17758:
    goto v_17759;
v_17760:
    v_17935 = Lmemq(nil, v_17936, v_17935);
    if (v_17935 == nil) goto v_17753;
    v_17935 = stack[-5];
    if (!symbolp(v_17935)) v_17935 = nil;
    else { v_17935 = qfastgets(v_17935);
           if (v_17935 != nil) { v_17935 = elt(v_17935, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_17935 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_17935 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_17935 == SPID_NOPROP) v_17935 = nil; }}
#endif
    stack[-9] = v_17935;
    if (v_17935 == nil) goto v_17768;
    goto v_17782;
v_17778:
    v_17936 = stack[-5];
    goto v_17779;
v_17780:
    v_17935 = elt(env, 37); // variadic
    goto v_17781;
v_17782:
    goto v_17778;
v_17779:
    goto v_17780;
v_17781:
    v_17935 = Lflagp(nil, v_17936, v_17935);
    env = stack[-10];
    if (v_17935 == nil) goto v_17775;
    else goto v_17776;
v_17775:
    goto v_17790;
v_17786:
    stack[0] = stack[-9];
    goto v_17787;
v_17788:
    v_17935 = stack[-3];
    v_17935 = Llength(nil, v_17935);
    env = stack[-10];
    goto v_17789;
v_17790:
    goto v_17786;
v_17787:
    goto v_17788;
v_17789:
    v_17935 = Lneq(nil, stack[0], v_17935);
    env = stack[-10];
    goto v_17774;
v_17776:
    v_17935 = nil;
    goto v_17774;
    v_17935 = nil;
v_17774:
    if (v_17935 == nil) goto v_17768;
    v_17935 = qvalue(elt(env, 38)); // !*strict_argcount
    if (v_17935 == nil) goto v_17800;
    goto v_17810;
v_17804:
    v_17937 = elt(env, 39); // "Definition of"
    goto v_17805;
v_17806:
    v_17936 = stack[-5];
    goto v_17807;
v_17808:
    v_17935 = elt(env, 40); // "different count from args previously called with"
    goto v_17809;
v_17810:
    goto v_17804;
v_17805:
    goto v_17806;
v_17807:
    goto v_17808;
v_17809:
    v_17935 = list3(v_17937, v_17936, v_17935);
    env = stack[-10];
    fn = elt(env, 57); // lprie
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17798;
v_17800:
    goto v_17826;
v_17818:
    stack[-2] = stack[-5];
    goto v_17819;
v_17820:
    stack[-1] = elt(env, 41); // "defined with"
    goto v_17821;
v_17822:
    v_17935 = stack[-3];
    stack[0] = Llength(nil, v_17935);
    env = stack[-10];
    goto v_17823;
v_17824:
    goto v_17838;
v_17832:
    v_17937 = elt(env, 42); // "but previously called with"
    goto v_17833;
v_17834:
    v_17936 = stack[-9];
    goto v_17835;
v_17836:
    v_17935 = elt(env, 43); // "arguments"
    goto v_17837;
v_17838:
    goto v_17832;
v_17833:
    goto v_17834;
v_17835:
    goto v_17836;
v_17837:
    v_17935 = list3(v_17937, v_17936, v_17935);
    env = stack[-10];
    goto v_17825;
v_17826:
    goto v_17818;
v_17819:
    goto v_17820;
v_17821:
    goto v_17822;
v_17823:
    goto v_17824;
v_17825:
    v_17935 = list3star(stack[-2], stack[-1], stack[0], v_17935);
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17798;
v_17798:
    goto v_17766;
v_17768:
v_17766:
    goto v_17847;
v_17843:
    goto v_17857;
v_17849:
    stack[-2] = elt(env, 44); // put
    goto v_17850;
v_17851:
    v_17935 = stack[-5];
    stack[-1] = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17852;
v_17853:
    v_17935 = elt(env, 45); // number!-of!-args
    stack[0] = Lmkquote(nil, v_17935);
    env = stack[-10];
    goto v_17854;
v_17855:
    v_17935 = stack[-3];
    v_17935 = Llength(nil, v_17935);
    env = stack[-10];
    goto v_17856;
v_17857:
    goto v_17849;
v_17850:
    goto v_17851;
v_17852:
    goto v_17853;
v_17854:
    goto v_17855;
v_17856:
    v_17936 = list4(stack[-2], stack[-1], stack[0], v_17935);
    env = stack[-10];
    goto v_17844;
v_17845:
    v_17935 = stack[-7];
    goto v_17846;
v_17847:
    goto v_17843;
v_17844:
    goto v_17845;
v_17846:
    fn = elt(env, 56); // mkprogn
    v_17935 = (*qfn2(fn))(fn, v_17936, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17751;
v_17753:
v_17751:
    v_17935 = qvalue(elt(env, 5)); // !*defn
    if (v_17935 == nil) goto v_17869;
    goto v_17877;
v_17873:
    v_17936 = stack[-4];
    goto v_17874;
v_17875:
    v_17935 = elt(env, 46); // (fexpr macro inline smacro)
    goto v_17876;
v_17877:
    goto v_17873;
v_17874:
    goto v_17875;
v_17876:
    v_17935 = Lmemq(nil, v_17936, v_17935);
    if (v_17935 == nil) goto v_17869;
    v_17935 = stack[-7];
    fn = elt(env, 58); // lispeval
    v_17935 = (*qfn1(fn))(fn, v_17935);
    env = stack[-10];
    goto v_17867;
v_17869:
v_17867:
    goto v_17891;
v_17887:
    v_17936 = stack[-4];
    goto v_17888;
v_17889:
    v_17935 = elt(env, 13); // inline
    goto v_17890;
v_17891:
    goto v_17887;
v_17888:
    goto v_17889;
v_17890:
    if (v_17936 == v_17935) goto v_17885;
    else goto v_17886;
v_17885:
    goto v_17900;
v_17896:
    goto v_17910;
v_17902:
    v_17938 = elt(env, 22); // de
    goto v_17903;
v_17904:
    v_17937 = stack[-5];
    goto v_17905;
v_17906:
    v_17936 = stack[-3];
    goto v_17907;
v_17908:
    v_17935 = stack[-8];
    goto v_17909;
v_17910:
    goto v_17902;
v_17903:
    goto v_17904;
v_17905:
    goto v_17906;
v_17907:
    goto v_17908;
v_17909:
    v_17936 = list4(v_17938, v_17937, v_17936, v_17935);
    env = stack[-10];
    goto v_17897;
v_17898:
    v_17935 = stack[-7];
    goto v_17899;
v_17900:
    goto v_17896;
v_17897:
    goto v_17898;
v_17899:
    fn = elt(env, 56); // mkprogn
    v_17935 = (*qfn2(fn))(fn, v_17936, v_17935);
    env = stack[-10];
    v_17935 = Lprint(nil, v_17935);
    env = stack[-10];
    stack[-7] = v_17935;
    goto v_17884;
v_17886:
v_17884:
    v_17935 = qvalue(elt(env, 47)); // !*micro!-version
    if (v_17935 == nil) goto v_17919;
    goto v_17927;
v_17923:
    v_17935 = stack[-4];
    goto v_17924;
v_17925:
    v_17936 = elt(env, 48); // (fexpr macro smacro)
    goto v_17926;
v_17927:
    goto v_17923;
v_17924:
    goto v_17925;
v_17926:
    v_17935 = Lmemq(nil, v_17935, v_17936);
    if (v_17935 == nil) goto v_17919;
    v_17935 = nil;
    goto v_17917;
v_17919:
    v_17935 = stack[-7];
    goto v_17917;
    v_17935 = nil;
v_17917:
v_17145:
    ;}  // end of a binding scope
    return onevalue(v_17935);
}



// Code for monomgetfirstmultivar

static LispObject CC_monomgetfirstmultivar(LispObject env,
                         LispObject v_17130)
{
    env = qenv(env);
    LispObject v_17160, v_17161, v_17162;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17161 = v_17130;
// end of prologue
    goto v_17143;
v_17139:
    v_17162 = v_17161;
    goto v_17140;
v_17141:
    v_17160 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17142;
v_17143:
    goto v_17139;
v_17140:
    goto v_17141;
v_17142:
    v_17160 = *(LispObject *)((char *)v_17162 + (CELL-TAG_VECTOR) + (((intptr_t)v_17160-TAG_FIXNUM)/(16/CELL)));
    v_17160 = qcar(v_17160);
    if (v_17160 == nil) goto v_17138;
    goto v_17152;
v_17148:
    goto v_17149;
v_17150:
    v_17160 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17151;
v_17152:
    goto v_17148;
v_17149:
    goto v_17150;
v_17151:
    v_17160 = *(LispObject *)((char *)v_17161 + (CELL-TAG_VECTOR) + (((intptr_t)v_17160-TAG_FIXNUM)/(16/CELL)));
    v_17160 = qcar(v_17160);
    goto v_17136;
v_17138:
    v_17160 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17136;
    v_17160 = nil;
v_17136:
    return onevalue(v_17160);
}



// Code for ofsf_facequal!*

static LispObject CC_ofsf_facequalH(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17168, v_17169, v_17170;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17169 = v_17131;
    v_17170 = v_17130;
// end of prologue
    v_17168 = qvalue(elt(env, 1)); // !*rlsifac
    if (v_17168 == nil) goto v_17136;
    v_17168 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (v_17168 == nil) goto v_17140;
    else goto v_17139;
v_17140:
    v_17168 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v_17168 == nil) goto v_17142;
    goto v_17150;
v_17146:
    goto v_17147;
v_17148:
    v_17168 = elt(env, 4); // or
    goto v_17149;
v_17150:
    goto v_17146;
v_17147:
    goto v_17148;
v_17149:
    if (v_17169 == v_17168) goto v_17145;
    else goto v_17142;
v_17145:
    goto v_17139;
v_17142:
    goto v_17136;
v_17139:
    v_17168 = v_17170;
    {
        fn = elt(env, 6); // ofsf_facequal
        return (*qfn1(fn))(fn, v_17168);
    }
v_17136:
    goto v_17164;
v_17158:
    v_17169 = elt(env, 5); // equal
    goto v_17159;
v_17160:
    goto v_17161;
v_17162:
    v_17168 = nil;
    goto v_17163;
v_17164:
    goto v_17158;
v_17159:
    goto v_17160;
v_17161:
    goto v_17162;
v_17163:
    return list3(v_17169, v_17170, v_17168);
    v_17168 = nil;
    return onevalue(v_17168);
}



// Code for talp_noffcts

static LispObject CC_talp_noffcts(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17168, v_17169;
    LispObject fn;
    argcheck(nargs, 0, "talp_noffcts");
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
    v_17168 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_17168;
    fn = elt(env, 2); // talp_getl
    v_17168 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_17168;
v_17139:
    v_17168 = stack[0];
    if (v_17168 == nil) goto v_17143;
    else goto v_17144;
v_17143:
    goto v_17138;
v_17144:
    v_17168 = stack[0];
    v_17168 = qcar(v_17168);
    goto v_17159;
v_17155:
    v_17169 = qcdr(v_17168);
    goto v_17156;
v_17157:
    v_17168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17158;
v_17159:
    goto v_17155;
v_17156:
    goto v_17157;
v_17158:
    v_17168 = (LispObject)greaterp2(v_17169, v_17168);
    v_17168 = v_17168 ? lisp_true : nil;
    env = stack[-2];
    if (v_17168 == nil) goto v_17153;
    v_17168 = stack[-1];
    v_17168 = add1(v_17168);
    env = stack[-2];
    stack[-1] = v_17168;
    goto v_17151;
v_17153:
v_17151:
    v_17168 = stack[0];
    v_17168 = qcdr(v_17168);
    stack[0] = v_17168;
    goto v_17139;
v_17138:
    v_17168 = stack[-1];
    return onevalue(v_17168);
}



// Code for pasf_floor

static LispObject CC_pasf_floor(LispObject env,
                         LispObject v_17130, LispObject v_17131)
{
    env = qenv(env);
    LispObject v_17252, v_17253, v_17254;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17131,v_17130);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17130,v_17131);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17131;
    stack[-1] = v_17130;
// end of prologue
    v_17252 = stack[-1];
    if (!consp(v_17252)) goto v_17143;
    else goto v_17144;
v_17143:
    v_17252 = lisp_true;
    goto v_17142;
v_17144:
    v_17252 = stack[-1];
    v_17252 = qcar(v_17252);
    v_17252 = (consp(v_17252) ? nil : lisp_true);
    goto v_17142;
    v_17252 = nil;
v_17142:
    if (v_17252 == nil) goto v_17140;
    v_17252 = stack[0];
    if (!consp(v_17252)) goto v_17154;
    else goto v_17155;
v_17154:
    v_17252 = lisp_true;
    goto v_17153;
v_17155:
    v_17252 = stack[0];
    v_17252 = qcar(v_17252);
    v_17252 = (consp(v_17252) ? nil : lisp_true);
    goto v_17153;
    v_17252 = nil;
v_17153:
    goto v_17138;
v_17140:
    v_17252 = nil;
    goto v_17138;
    v_17252 = nil;
v_17138:
    if (v_17252 == nil) goto v_17136;
    v_17252 = stack[-1];
    if (v_17252 == nil) goto v_17168;
    else goto v_17169;
v_17168:
    v_17252 = nil;
    goto v_17167;
v_17169:
    goto v_17183;
v_17179:
    goto v_17189;
v_17185:
    v_17253 = stack[-1];
    goto v_17186;
v_17187:
    v_17252 = stack[0];
    goto v_17188;
v_17189:
    goto v_17185;
v_17186:
    goto v_17187;
v_17188:
    v_17253 = Cremainder(v_17253, v_17252);
    env = stack[-2];
    goto v_17180;
v_17181:
    v_17252 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17182;
v_17183:
    goto v_17179;
v_17180:
    goto v_17181;
v_17182:
    if (v_17253 == v_17252) goto v_17177;
    else goto v_17178;
v_17177:
    goto v_17198;
v_17194:
    v_17253 = stack[-1];
    goto v_17195;
v_17196:
    v_17252 = stack[0];
    goto v_17197;
v_17198:
    goto v_17194;
v_17195:
    goto v_17196;
v_17197:
    v_17252 = quot2(v_17253, v_17252);
    env = stack[-2];
    goto v_17176;
v_17178:
    goto v_17208;
v_17204:
    goto v_17214;
v_17210:
    v_17253 = stack[-1];
    goto v_17211;
v_17212:
    v_17252 = stack[0];
    goto v_17213;
v_17214:
    goto v_17210;
v_17211:
    goto v_17212;
v_17213:
    v_17253 = times2(v_17253, v_17252);
    env = stack[-2];
    goto v_17205;
v_17206:
    v_17252 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17207;
v_17208:
    goto v_17204;
v_17205:
    goto v_17206;
v_17207:
    v_17252 = (LispObject)greaterp2(v_17253, v_17252);
    v_17252 = v_17252 ? lisp_true : nil;
    env = stack[-2];
    if (v_17252 == nil) goto v_17202;
    goto v_17223;
v_17219:
    v_17253 = stack[-1];
    goto v_17220;
v_17221:
    v_17252 = stack[0];
    goto v_17222;
v_17223:
    goto v_17219;
v_17220:
    goto v_17221;
v_17222:
    v_17252 = quot2(v_17253, v_17252);
    env = stack[-2];
    goto v_17176;
v_17202:
    goto v_17234;
v_17230:
    v_17253 = stack[-1];
    goto v_17231;
v_17232:
    v_17252 = stack[0];
    goto v_17233;
v_17234:
    goto v_17230;
v_17231:
    goto v_17232;
v_17233:
    v_17252 = quot2(v_17253, v_17252);
    env = stack[-2];
    v_17252 = sub1(v_17252);
    env = stack[-2];
    goto v_17176;
    v_17252 = nil;
v_17176:
    fn = elt(env, 2); // simp
    v_17252 = (*qfn1(fn))(fn, v_17252);
    v_17252 = qcar(v_17252);
    goto v_17167;
    v_17252 = nil;
v_17167:
    goto v_17134;
v_17136:
    goto v_17248;
v_17242:
    v_17254 = elt(env, 1); // "pasf_floor: not a domain valued sf in input"
    goto v_17243;
v_17244:
    v_17253 = stack[-1];
    goto v_17245;
v_17246:
    v_17252 = stack[0];
    goto v_17247;
v_17248:
    goto v_17242;
v_17243:
    goto v_17244;
v_17245:
    goto v_17246;
v_17247:
    v_17252 = list3(v_17254, v_17253, v_17252);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_17252);
    }
    v_17252 = nil;
v_17134:
    return onevalue(v_17252);
}



setup_type const u33_setup[] =
{
    {"comb",                    TOO_FEW_2,      CC_comb,       WRONG_NO_2},
    {"horner-rule-for-one-var", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"make-x-to-p",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKxKtoKp},
    {"lalr_process_productions",TOO_FEW_2,      CC_lalr_process_productions,WRONG_NO_2},
    {"read_signature",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_read_signature},
    {"pasf_sisub",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisub},
    {"ev_max#",                 TOO_FEW_2,      CC_ev_maxC,    WRONG_NO_2},
    {"semanticml",              CC_semanticml,  TOO_MANY_1,    WRONG_NO_1},
    {"add_minus",               CC_add_minus,   TOO_MANY_1,    WRONG_NO_1},
    {"dipequal",                TOO_FEW_2,      CC_dipequal,   WRONG_NO_2},
    {"vdp2a",                   CC_vdp2a,       TOO_MANY_1,    WRONG_NO_1},
    {"overall_factor",          TOO_FEW_2,      CC_overall_factor,WRONG_NO_2},
    {":dmtimeslst",             CC_Tdmtimeslst, TOO_MANY_1,    WRONG_NO_1},
    {"gparg1p",                 CC_gparg1p,     TOO_MANY_1,    WRONG_NO_1},
    {"formsetq",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formsetq},
    {"length_multiindex",       CC_length_multiindex,TOO_MANY_1,WRONG_NO_1},
    {"lex_basic_token",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_basic_token},
    {"formproc",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formproc},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_facequal*",          TOO_FEW_2,      CC_ofsf_facequalH,WRONG_NO_2},
    {"talp_noffcts",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_noffcts},
    {"pasf_floor",              TOO_FEW_2,      CC_pasf_floor, WRONG_NO_2},
    {NULL, (one_args *)"u33", (two_args *)"84490 1690216 6173107", 0}
};

// end of generated code
