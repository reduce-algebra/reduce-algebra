
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



// Code for letexprn

static LispObject CC_letexprn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19158, v_19159, v_19160;
    LispObject fn;
    LispObject v_18590, v_18589, v_18588, v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "letexprn");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    v_18588 = va_arg(aa, LispObject);
    v_18589 = va_arg(aa, LispObject);
    v_18590 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_18590,v_18589,v_18588,v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_18585,v_18586,v_18587,v_18588,v_18589,v_18590);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_18590;
    stack[-2] = v_18589;
    stack[-3] = v_18588;
    stack[-4] = v_18587;
    stack[-5] = v_18586;
    stack[-6] = v_18585;
// end of prologue
    goto v_18604;
v_18600:
    v_19158 = stack[-3];
    v_19159 = qcdr(v_19158);
    goto v_18601;
v_18602:
    v_19158 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18603;
v_18604:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    if (v_19159 == v_19158) goto v_18599;
    goto v_18617;
v_18609:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18610;
v_18611:
    goto v_18628;
v_18622:
    stack[0] = elt(env, 1); // times
    goto v_18623;
v_18624:
    v_19158 = stack[-3];
    v_19158 = qcdr(v_19158);
    fn = elt(env, 14); // let!-prepf
    v_19159 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18625;
v_18626:
    v_19158 = stack[-5];
    goto v_18627;
v_18628:
    goto v_18622;
v_18623:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    v_19160 = list3(stack[0], v_19159, v_19158);
    env = stack[-8];
    goto v_18612;
v_18613:
    v_19159 = stack[-4];
    goto v_18614;
v_18615:
    v_19158 = stack[-2];
    goto v_18616;
v_18617:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    {
        LispObject v_19169 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19169, v_19160, v_19159, v_19158);
    }
v_18599:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    stack[-3] = v_19158;
    v_19158 = qcdr(v_19158);
    if (v_19158 == nil) goto v_18637;
    goto v_18650;
v_18642:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19158 = ncons(v_19158);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18643;
v_18644:
    goto v_18662;
v_18656:
    stack[0] = elt(env, 2); // difference
    goto v_18657;
v_18658:
    goto v_18659;
v_18660:
    v_19158 = stack[-3];
    v_19158 = qcdr(v_19158);
    fn = elt(env, 14); // let!-prepf
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18661;
v_18662:
    goto v_18656;
v_18657:
    goto v_18658;
v_18659:
    goto v_18660;
v_18661:
    v_19160 = list3(stack[0], stack[-5], v_19158);
    env = stack[-8];
    goto v_18645;
v_18646:
    v_19159 = stack[-4];
    goto v_18647;
v_18648:
    v_19158 = stack[-2];
    goto v_18649;
v_18650:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    goto v_18646;
v_18647:
    goto v_18648;
v_18649:
    {
        LispObject v_19170 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19170, v_19160, v_19159, v_19158);
    }
v_18637:
    v_19158 = stack[-3];
    fn = elt(env, 16); // kernlp
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    stack[0] = v_19158;
    if (v_19158 == nil) goto v_18670;
    else goto v_18671;
v_18670:
    v_19158 = stack[-3];
    fn = elt(env, 17); // term!-split
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    stack[0] = v_19158;
    goto v_18685;
v_18677:
    v_19158 = stack[0];
    v_19158 = qcar(v_19158);
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18678;
v_18679:
    goto v_18696;
v_18690:
    stack[-1] = elt(env, 2); // difference
    goto v_18691;
v_18692:
    goto v_18693;
v_18694:
    v_19158 = stack[0];
    v_19158 = qcdr(v_19158);
    fn = elt(env, 14); // let!-prepf
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18695;
v_18696:
    goto v_18690;
v_18691:
    goto v_18692;
v_18693:
    goto v_18694;
v_18695:
    v_19160 = list3(stack[-1], stack[-5], v_19158);
    env = stack[-8];
    goto v_18680;
v_18681:
    v_19159 = stack[-4];
    goto v_18682;
v_18683:
    v_19158 = stack[-2];
    goto v_18684;
v_18685:
    goto v_18677;
v_18678:
    goto v_18679;
v_18680:
    goto v_18681;
v_18682:
    goto v_18683;
v_18684:
    {
        LispObject v_19171 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19171, v_19160, v_19159, v_19158);
    }
v_18671:
    goto v_18710;
v_18706:
    v_19159 = stack[0];
    goto v_18707;
v_18708:
    v_19158 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18709;
v_18710:
    goto v_18706;
v_18707:
    goto v_18708;
v_18709:
    if (v_19159 == v_19158) goto v_18705;
    goto v_18722;
v_18714:
    goto v_18729;
v_18725:
    v_19159 = stack[-3];
    goto v_18726;
v_18727:
    v_19158 = stack[0];
    goto v_18728;
v_18729:
    goto v_18725;
v_18726:
    goto v_18727;
v_18728:
    fn = elt(env, 18); // quotf!*
    v_19158 = (*qfn2(fn))(fn, v_19159, v_19158);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18715;
v_18716:
    goto v_18739;
v_18733:
    stack[-1] = elt(env, 3); // quotient
    goto v_18734;
v_18735:
    goto v_18736;
v_18737:
    v_19158 = stack[0];
    fn = elt(env, 14); // let!-prepf
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    goto v_18738;
v_18739:
    goto v_18733;
v_18734:
    goto v_18735;
v_18736:
    goto v_18737;
v_18738:
    v_19160 = list3(stack[-1], stack[-5], v_19158);
    env = stack[-8];
    goto v_18717;
v_18718:
    v_19159 = stack[-4];
    goto v_18719;
v_18720:
    v_19158 = stack[-2];
    goto v_18721;
v_18722:
    goto v_18714;
v_18715:
    goto v_18716;
v_18717:
    goto v_18718;
v_18719:
    goto v_18720;
v_18721:
    {
        LispObject v_19172 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19172, v_19160, v_19159, v_19158);
    }
v_18705:
    v_19158 = stack[-3];
    fn = elt(env, 19); // klistt
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    stack[-3] = v_19158;
    goto v_18755;
v_18749:
    stack[-7] = stack[-4];
    goto v_18750;
v_18751:
    v_19158 = qvalue(elt(env, 4)); // mcond!*
    if (v_19158 == nil) goto v_18760;
    v_19158 = qvalue(elt(env, 4)); // mcond!*
    stack[0] = v_19158;
    goto v_18758;
v_18760:
    v_19158 = lisp_true;
    stack[0] = v_19158;
    goto v_18758;
    stack[0] = nil;
v_18758:
    goto v_18752;
v_18753:
    goto v_18771;
v_18767:
    v_19159 = stack[-5];
    goto v_18768;
v_18769:
    v_19158 = nil;
    goto v_18770;
v_18771:
    goto v_18767;
v_18768:
    goto v_18769;
v_18770:
    v_19158 = list2(v_19159, v_19158);
    env = stack[-8];
    goto v_18754;
v_18755:
    goto v_18749;
v_18750:
    goto v_18751;
v_18752:
    goto v_18753;
v_18754:
    v_19158 = acons(stack[-7], stack[0], v_19158);
    env = stack[-8];
    stack[0] = v_19158;
    v_19158 = stack[-3];
    v_19158 = qcdr(v_19158);
    if (v_19158 == nil) goto v_18777;
    fn = elt(env, 20); // rmsubs
    v_19158 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18788;
v_18782:
    goto v_18794;
v_18790:
    v_19159 = stack[-3];
    goto v_18791;
v_18792:
    v_19158 = stack[0];
    goto v_18793;
v_18794:
    goto v_18790;
v_18791:
    goto v_18792;
v_18793:
    v_19160 = cons(v_19159, v_19158);
    env = stack[-8];
    goto v_18783;
v_18784:
    v_19159 = qvalue(elt(env, 5)); // !*match
    goto v_18785;
v_18786:
    v_19158 = stack[-2];
    goto v_18787;
v_18788:
    goto v_18782;
v_18783:
    goto v_18784;
v_18785:
    goto v_18786;
v_18787:
    fn = elt(env, 21); // xadd!*
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 5)) = v_19158; // !*match
    goto v_18595;
v_18777:
    v_19158 = stack[-4];
    if (v_19158 == nil) goto v_18803;
    else goto v_18804;
v_18803:
    goto v_18810;
v_18806:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcdr(v_19158);
    goto v_18807;
v_18808:
    v_19158 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18809;
v_18810:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    v_19158 = (v_19159 == v_19158 ? lisp_true : nil);
    goto v_18802;
v_18804:
    v_19158 = nil;
    goto v_18802;
    v_19158 = nil;
v_18802:
    if (v_19158 == nil) goto v_18800;
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19158 = qcar(v_19158);
    stack[-3] = v_19158;
    v_19158 = stack[-1];
    if (v_19158 == nil) goto v_18828;
    else goto v_18829;
v_18828:
    v_19158 = qvalue(elt(env, 4)); // mcond!*
    if (v_19158 == nil) goto v_18833;
    else goto v_18834;
v_18833:
    v_19158 = lisp_true;
    goto v_18832;
v_18834:
    goto v_18847;
v_18843:
    v_19159 = qvalue(elt(env, 4)); // mcond!*
    goto v_18844;
v_18845:
    v_19158 = lisp_true;
    goto v_18846;
v_18847:
    goto v_18843;
v_18844:
    goto v_18845;
v_18846:
    if (v_19159 == v_19158) goto v_18841;
    else goto v_18842;
v_18841:
    v_19158 = lisp_true;
    goto v_18840;
v_18842:
    goto v_18858;
v_18854:
    v_19159 = stack[-3];
    goto v_18855;
v_18856:
    v_19158 = qvalue(elt(env, 4)); // mcond!*
    goto v_18857;
v_18858:
    goto v_18854;
v_18855:
    goto v_18856;
v_18857:
    fn = elt(env, 22); // smember
    v_19158 = (*qfn2(fn))(fn, v_19159, v_19158);
    env = stack[-8];
    v_19158 = (v_19158 == nil ? lisp_true : nil);
    goto v_18840;
    v_19158 = nil;
v_18840:
    goto v_18832;
    v_19158 = nil;
v_18832:
    goto v_18827;
v_18829:
    v_19158 = nil;
    goto v_18827;
    v_19158 = nil;
v_18827:
    if (v_19158 == nil) goto v_18825;
    v_19158 = stack[-3];
    if (!consp(v_19158)) goto v_18867;
    else goto v_18868;
v_18867:
    goto v_18879;
v_18875:
    v_19159 = stack[-3];
    goto v_18876;
v_18877:
    v_19158 = elt(env, 6); // used!*
    goto v_18878;
v_18879:
    goto v_18875;
v_18876:
    goto v_18877;
v_18878:
    v_19158 = Lflagp(nil, v_19159, v_19158);
    env = stack[-8];
    if (v_19158 == nil) goto v_18873;
    fn = elt(env, 20); // rmsubs
    v_19158 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18871;
v_18873:
    goto v_18871;
v_18871:
    goto v_18866;
v_18868:
    goto v_18893;
v_18889:
    stack[0] = elt(env, 6); // used!*
    goto v_18890;
v_18891:
    v_19158 = stack[-3];
    fn = elt(env, 23); // fkern
    v_19158 = (*qfn1(fn))(fn, v_19158);
    env = stack[-8];
    v_19158 = qcdr(v_19158);
    v_19158 = qcdr(v_19158);
    goto v_18892;
v_18893:
    goto v_18889;
v_18890:
    goto v_18891;
v_18892:
    v_19158 = Lmemq(nil, stack[0], v_19158);
    if (v_19158 == nil) goto v_18888;
    else goto v_18886;
v_18888:
    goto v_18905;
v_18901:
    v_19158 = stack[-3];
    v_19159 = qcar(v_19158);
    goto v_18902;
v_18903:
    v_19158 = elt(env, 7); // df
    goto v_18904;
v_18905:
    goto v_18901;
v_18902:
    goto v_18903;
v_18904:
    if (v_19159 == v_19158) goto v_18886;
    goto v_18887;
v_18886:
    fn = elt(env, 20); // rmsubs
    v_19158 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18866;
v_18887:
v_18866:
    goto v_18917;
v_18911:
    v_19160 = stack[-3];
    goto v_18912;
v_18913:
    v_19159 = stack[-5];
    goto v_18914;
v_18915:
    v_19158 = stack[-2];
    goto v_18916;
v_18917:
    goto v_18911;
v_18912:
    goto v_18913;
v_18914:
    goto v_18915;
v_18916:
    fn = elt(env, 24); // setk1
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    goto v_18823;
v_18825:
    v_19158 = stack[-3];
    if (!consp(v_19158)) goto v_18921;
    else goto v_18922;
v_18921:
    v_19158 = stack[-6];
    {
        fn = elt(env, 25); // errpri1
        return (*qfn1(fn))(fn, v_19158);
    }
v_18922:
    fn = elt(env, 20); // rmsubs
    v_19158 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18936;
v_18930:
    v_19158 = stack[-3];
    stack[-4] = qcar(v_19158);
    goto v_18931;
v_18932:
    stack[-1] = elt(env, 8); // opmtch
    goto v_18933;
v_18934:
    goto v_18947;
v_18941:
    goto v_18953;
v_18949:
    v_19158 = stack[-3];
    v_19159 = qcdr(v_19158);
    goto v_18950;
v_18951:
    v_19158 = stack[0];
    goto v_18952;
v_18953:
    goto v_18949;
v_18950:
    goto v_18951;
v_18952:
    v_19160 = cons(v_19159, v_19158);
    env = stack[-8];
    goto v_18942;
v_18943:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    if (!symbolp(v_19158)) v_19159 = nil;
    else { v_19159 = qfastgets(v_19158);
           if (v_19159 != nil) { v_19159 = elt(v_19159, 9); // opmtch
#ifdef RECORD_GET
             if (v_19159 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_19159 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_19159 == SPID_NOPROP) v_19159 = nil; }}
#endif
    goto v_18944;
v_18945:
    v_19158 = stack[-2];
    goto v_18946;
v_18947:
    goto v_18941;
v_18942:
    goto v_18943;
v_18944:
    goto v_18945;
v_18946:
    fn = elt(env, 21); // xadd!*
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    goto v_18935;
v_18936:
    goto v_18930;
v_18931:
    goto v_18932;
v_18933:
    goto v_18934;
v_18935:
    v_19158 = Lputprop(nil, 3, stack[-4], stack[-1], v_19158);
    goto v_18823;
v_18823:
    goto v_18775;
v_18800:
    fn = elt(env, 20); // rmsubs
    v_19158 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18976;
v_18972:
    v_19159 = stack[-5];
    goto v_18973;
v_18974:
    v_19158 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18975;
v_18976:
    goto v_18972;
v_18973:
    goto v_18974;
v_18975:
    if (v_19159 == v_19158) goto v_18970;
    else goto v_18971;
v_18970:
    v_19158 = stack[-4];
    if (v_19158 == nil) goto v_18981;
    else goto v_18982;
v_18981:
    v_19158 = stack[-1];
    v_19158 = (v_19158 == nil ? lisp_true : nil);
    goto v_18980;
v_18982:
    v_19158 = nil;
    goto v_18980;
    v_19158 = nil;
v_18980:
    goto v_18969;
v_18971:
    v_19158 = nil;
    goto v_18969;
    v_19158 = nil;
v_18969:
    if (v_19158 == nil) goto v_18967;
    goto v_18999;
v_18993:
    v_19158 = stack[-3];
    v_19160 = qcar(v_19158);
    goto v_18994;
v_18995:
    v_19159 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18996;
v_18997:
    v_19158 = stack[-2];
    goto v_18998;
v_18999:
    goto v_18993;
v_18994:
    goto v_18995;
v_18996:
    goto v_18997;
v_18998:
    fn = elt(env, 26); // xadd
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19158; // asymplis!*
    goto v_19011;
v_19005:
    goto v_19019;
v_19013:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19160 = qcar(v_19158);
    goto v_19014;
v_19015:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcdr(v_19158);
    goto v_19016;
v_19017:
    v_19158 = stack[0];
    goto v_19018;
v_19019:
    goto v_19013;
v_19014:
    goto v_19015;
v_19016:
    goto v_19017;
v_19018:
    v_19160 = list2star(v_19160, v_19159, v_19158);
    env = stack[-8];
    goto v_19006;
v_19007:
    v_19159 = qvalue(elt(env, 10)); // powlis!*
    goto v_19008;
v_19009:
    v_19158 = elt(env, 11); // replace
    goto v_19010;
v_19011:
    goto v_19005;
v_19006:
    goto v_19007;
v_19008:
    goto v_19009;
v_19010:
    fn = elt(env, 26); // xadd
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_19158; // powlis!*
    goto v_18965;
v_18967:
    v_19158 = stack[-4];
    if (v_19158 == nil) goto v_19031;
    else goto v_19029;
v_19031:
    goto v_19042;
v_19038:
    v_19158 = stack[0];
    v_19158 = qcar(v_19158);
    v_19159 = qcdr(v_19158);
    goto v_19039;
v_19040:
    v_19158 = lisp_true;
    goto v_19041;
v_19042:
    goto v_19038;
v_19039:
    goto v_19040;
v_19041:
    if (v_19159 == v_19158) goto v_19037;
    v_19158 = lisp_true;
    goto v_19035;
v_19037:
    v_19158 = qvalue(elt(env, 12)); // frasc!*
    goto v_19035;
    v_19158 = nil;
v_19035:
    if (v_19158 == nil) goto v_19033;
    else goto v_19029;
v_19033:
    goto v_19030;
v_19029:
    goto v_19058;
v_19052:
    goto v_19064;
v_19060:
    v_19158 = stack[-3];
    v_19159 = qcar(v_19158);
    goto v_19061;
v_19062:
    v_19158 = stack[0];
    goto v_19063;
v_19064:
    goto v_19060;
v_19061:
    goto v_19062;
v_19063:
    v_19160 = cons(v_19159, v_19158);
    env = stack[-8];
    goto v_19053;
v_19054:
    v_19159 = qvalue(elt(env, 13)); // powlis1!*
    goto v_19055;
v_19056:
    v_19158 = stack[-2];
    goto v_19057;
v_19058:
    goto v_19052;
v_19053:
    goto v_19054;
v_19055:
    goto v_19056;
v_19057:
    fn = elt(env, 26); // xadd
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 13)) = v_19158; // powlis1!*
    goto v_18965;
v_19030:
    v_19158 = stack[-2];
    if (v_19158 == nil) goto v_19074;
    else goto v_19075;
v_19074:
    goto v_19085;
v_19081:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcar(v_19158);
    goto v_19082;
v_19083:
    v_19158 = qvalue(elt(env, 9)); // asymplis!*
    goto v_19084;
v_19085:
    goto v_19081;
v_19082:
    goto v_19083;
v_19084:
    v_19158 = Lassoc(nil, v_19159, v_19158);
    v_19159 = v_19158;
    if (v_19158 == nil) goto v_19079;
    else goto v_19080;
v_19079:
    v_19158 = nil;
    goto v_19078;
v_19080:
    goto v_19098;
v_19094:
    goto v_19095;
v_19096:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    goto v_19097;
v_19098:
    goto v_19094;
v_19095:
    goto v_19096;
v_19097:
    v_19158 = (equal(v_19159, v_19158) ? lisp_true : nil);
    goto v_19078;
    v_19158 = nil;
v_19078:
    goto v_19073;
v_19075:
    v_19158 = nil;
    goto v_19073;
    v_19158 = nil;
v_19073:
    if (v_19158 == nil) goto v_19071;
    goto v_19111;
v_19107:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcar(v_19158);
    goto v_19108;
v_19109:
    v_19158 = qvalue(elt(env, 9)); // asymplis!*
    goto v_19110;
v_19111:
    goto v_19107;
v_19108:
    goto v_19109;
v_19110:
    fn = elt(env, 27); // delasc
    v_19158 = (*qfn2(fn))(fn, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19158; // asymplis!*
    goto v_18965;
v_19071:
    goto v_19125;
v_19119:
    goto v_19133;
v_19127:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19160 = qcar(v_19158);
    goto v_19128;
v_19129:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcdr(v_19158);
    goto v_19130;
v_19131:
    v_19158 = stack[0];
    goto v_19132;
v_19133:
    goto v_19127;
v_19128:
    goto v_19129;
v_19130:
    goto v_19131;
v_19132:
    v_19160 = list2star(v_19160, v_19159, v_19158);
    env = stack[-8];
    goto v_19120;
v_19121:
    v_19159 = qvalue(elt(env, 10)); // powlis!*
    goto v_19122;
v_19123:
    v_19158 = stack[-2];
    goto v_19124;
v_19125:
    goto v_19119;
v_19120:
    goto v_19121;
v_19122:
    goto v_19123;
v_19124:
    fn = elt(env, 26); // xadd
    v_19158 = (*qfnn(fn))(fn, 3, v_19160, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_19158; // powlis!*
    v_19158 = stack[-2];
    if (v_19158 == nil) goto v_19146;
    goto v_19153;
v_19149:
    v_19158 = stack[-3];
    v_19158 = qcar(v_19158);
    v_19159 = qcar(v_19158);
    goto v_19150;
v_19151:
    v_19158 = qvalue(elt(env, 9)); // asymplis!*
    goto v_19152;
v_19153:
    goto v_19149;
v_19150:
    goto v_19151;
v_19152:
    fn = elt(env, 27); // delasc
    v_19158 = (*qfn2(fn))(fn, v_19159, v_19158);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19158; // asymplis!*
    goto v_19144;
v_19146:
v_19144:
    goto v_18965;
v_18965:
    goto v_18775;
v_18775:
    v_19158 = nil;
v_18595:
    return onevalue(v_19158);
}



// Code for triplesetprolongedby

static LispObject CC_triplesetprolongedby(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18664, v_18665;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18586;
    v_18664 = v_18585;
// end of prologue
    goto v_18595;
v_18591:
    v_18665 = v_18664;
    goto v_18592;
v_18593:
    v_18664 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_18594;
v_18595:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    v_18664 = *(LispObject *)((char *)v_18665 + (CELL-TAG_VECTOR) + (((intptr_t)v_18664-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_18664;
v_18601:
    v_18664 = stack[-2];
    v_18664 = qcar(v_18664);
    if (v_18664 == nil) goto v_18604;
    goto v_18615;
v_18611:
    v_18664 = stack[-2];
    v_18665 = qcar(v_18664);
    goto v_18612;
v_18613:
    v_18664 = stack[-1];
    goto v_18614;
v_18615:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    v_18664 = (LispObject)greaterp2(v_18665, v_18664);
    v_18664 = v_18664 ? lisp_true : nil;
    env = stack[-3];
    if (v_18664 == nil) goto v_18604;
    goto v_18605;
v_18604:
    goto v_18600;
v_18605:
    v_18664 = stack[-2];
    v_18664 = qcdr(v_18664);
    stack[-2] = v_18664;
    goto v_18601;
v_18600:
    v_18664 = stack[-2];
    v_18664 = qcar(v_18664);
    if (v_18664 == nil) goto v_18625;
    goto v_18635;
v_18631:
    v_18664 = stack[-2];
    v_18665 = qcar(v_18664);
    goto v_18632;
v_18633:
    v_18664 = stack[-1];
    goto v_18634;
v_18635:
    goto v_18631;
v_18632:
    goto v_18633;
v_18634:
    if (equal(v_18665, v_18664)) goto v_18630;
    else goto v_18625;
v_18630:
    goto v_18626;
v_18625:
    goto v_18644;
v_18640:
    goto v_18650;
v_18646:
    stack[0] = stack[-2];
    goto v_18647;
v_18648:
    goto v_18657;
v_18653:
    v_18664 = stack[-2];
    v_18665 = qcar(v_18664);
    goto v_18654;
v_18655:
    v_18664 = stack[-2];
    v_18664 = qcdr(v_18664);
    goto v_18656;
v_18657:
    goto v_18653;
v_18654:
    goto v_18655;
v_18656:
    v_18664 = cons(v_18665, v_18664);
    env = stack[-3];
    goto v_18649;
v_18650:
    goto v_18646;
v_18647:
    goto v_18648;
v_18649:
    v_18665 = Lrplacd(nil, stack[0], v_18664);
    env = stack[-3];
    goto v_18641;
v_18642:
    v_18664 = stack[-1];
    goto v_18643;
v_18644:
    goto v_18640;
v_18641:
    goto v_18642;
v_18643:
    v_18664 = Lrplaca(nil, v_18665, v_18664);
    goto v_18624;
v_18626:
v_18624:
    v_18664 = nil;
    return onevalue(v_18664);
}



// Code for ofsf_lnegrel

static LispObject CC_ofsf_lnegrel(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18660, v_18661, v_18662;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18662 = v_18585;
// end of prologue
    goto v_18595;
v_18591:
    v_18661 = v_18662;
    goto v_18592;
v_18593:
    v_18660 = elt(env, 1); // equal
    goto v_18594;
v_18595:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    if (v_18661 == v_18660) goto v_18589;
    else goto v_18590;
v_18589:
    v_18660 = elt(env, 2); // neq
    goto v_18588;
v_18590:
    goto v_18605;
v_18601:
    v_18661 = v_18662;
    goto v_18602;
v_18603:
    v_18660 = elt(env, 2); // neq
    goto v_18604;
v_18605:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    if (v_18661 == v_18660) goto v_18599;
    else goto v_18600;
v_18599:
    v_18660 = elt(env, 1); // equal
    goto v_18588;
v_18600:
    goto v_18615;
v_18611:
    v_18661 = v_18662;
    goto v_18612;
v_18613:
    v_18660 = elt(env, 3); // leq
    goto v_18614;
v_18615:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    if (v_18661 == v_18660) goto v_18609;
    else goto v_18610;
v_18609:
    v_18660 = elt(env, 4); // greaterp
    goto v_18588;
v_18610:
    goto v_18625;
v_18621:
    v_18661 = v_18662;
    goto v_18622;
v_18623:
    v_18660 = elt(env, 5); // lessp
    goto v_18624;
v_18625:
    goto v_18621;
v_18622:
    goto v_18623;
v_18624:
    if (v_18661 == v_18660) goto v_18619;
    else goto v_18620;
v_18619:
    v_18660 = elt(env, 6); // geq
    goto v_18588;
v_18620:
    goto v_18635;
v_18631:
    v_18661 = v_18662;
    goto v_18632;
v_18633:
    v_18660 = elt(env, 6); // geq
    goto v_18634;
v_18635:
    goto v_18631;
v_18632:
    goto v_18633;
v_18634:
    if (v_18661 == v_18660) goto v_18629;
    else goto v_18630;
v_18629:
    v_18660 = elt(env, 5); // lessp
    goto v_18588;
v_18630:
    goto v_18645;
v_18641:
    v_18661 = v_18662;
    goto v_18642;
v_18643:
    v_18660 = elt(env, 4); // greaterp
    goto v_18644;
v_18645:
    goto v_18641;
v_18642:
    goto v_18643;
v_18644:
    if (v_18661 == v_18660) goto v_18639;
    else goto v_18640;
v_18639:
    v_18660 = elt(env, 3); // leq
    goto v_18588;
v_18640:
    goto v_18657;
v_18653:
    v_18660 = elt(env, 7); // "ofsf_lnegrel: unknown operator "
    goto v_18654;
v_18655:
    v_18661 = v_18662;
    goto v_18656;
v_18657:
    goto v_18653;
v_18654:
    goto v_18655;
v_18656:
    v_18660 = list2(v_18660, v_18661);
    env = stack[0];
    {
        fn = elt(env, 8); // rederr
        return (*qfn1(fn))(fn, v_18660);
    }
    v_18660 = nil;
v_18588:
    return onevalue(v_18660);
}



// Code for pasf_floor

static LispObject CC_pasf_floor(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18707, v_18708, v_18709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18586;
    stack[-1] = v_18585;
// end of prologue
    v_18707 = stack[-1];
    if (!consp(v_18707)) goto v_18598;
    else goto v_18599;
v_18598:
    v_18707 = lisp_true;
    goto v_18597;
v_18599:
    v_18707 = stack[-1];
    v_18707 = qcar(v_18707);
    v_18707 = (consp(v_18707) ? nil : lisp_true);
    goto v_18597;
    v_18707 = nil;
v_18597:
    if (v_18707 == nil) goto v_18595;
    v_18707 = stack[0];
    if (!consp(v_18707)) goto v_18609;
    else goto v_18610;
v_18609:
    v_18707 = lisp_true;
    goto v_18608;
v_18610:
    v_18707 = stack[0];
    v_18707 = qcar(v_18707);
    v_18707 = (consp(v_18707) ? nil : lisp_true);
    goto v_18608;
    v_18707 = nil;
v_18608:
    goto v_18593;
v_18595:
    v_18707 = nil;
    goto v_18593;
    v_18707 = nil;
v_18593:
    if (v_18707 == nil) goto v_18591;
    v_18707 = stack[-1];
    if (v_18707 == nil) goto v_18623;
    else goto v_18624;
v_18623:
    v_18707 = nil;
    goto v_18622;
v_18624:
    goto v_18638;
v_18634:
    goto v_18644;
v_18640:
    v_18708 = stack[-1];
    goto v_18641;
v_18642:
    v_18707 = stack[0];
    goto v_18643;
v_18644:
    goto v_18640;
v_18641:
    goto v_18642;
v_18643:
    v_18708 = Cremainder(v_18708, v_18707);
    env = stack[-2];
    goto v_18635;
v_18636:
    v_18707 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18637;
v_18638:
    goto v_18634;
v_18635:
    goto v_18636;
v_18637:
    if (v_18708 == v_18707) goto v_18632;
    else goto v_18633;
v_18632:
    goto v_18653;
v_18649:
    v_18708 = stack[-1];
    goto v_18650;
v_18651:
    v_18707 = stack[0];
    goto v_18652;
v_18653:
    goto v_18649;
v_18650:
    goto v_18651;
v_18652:
    v_18707 = quot2(v_18708, v_18707);
    env = stack[-2];
    goto v_18631;
v_18633:
    goto v_18663;
v_18659:
    goto v_18669;
v_18665:
    v_18708 = stack[-1];
    goto v_18666;
v_18667:
    v_18707 = stack[0];
    goto v_18668;
v_18669:
    goto v_18665;
v_18666:
    goto v_18667;
v_18668:
    v_18708 = times2(v_18708, v_18707);
    env = stack[-2];
    goto v_18660;
v_18661:
    v_18707 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18662;
v_18663:
    goto v_18659;
v_18660:
    goto v_18661;
v_18662:
    v_18707 = (LispObject)greaterp2(v_18708, v_18707);
    v_18707 = v_18707 ? lisp_true : nil;
    env = stack[-2];
    if (v_18707 == nil) goto v_18657;
    goto v_18678;
v_18674:
    v_18708 = stack[-1];
    goto v_18675;
v_18676:
    v_18707 = stack[0];
    goto v_18677;
v_18678:
    goto v_18674;
v_18675:
    goto v_18676;
v_18677:
    v_18707 = quot2(v_18708, v_18707);
    env = stack[-2];
    goto v_18631;
v_18657:
    goto v_18689;
v_18685:
    v_18708 = stack[-1];
    goto v_18686;
v_18687:
    v_18707 = stack[0];
    goto v_18688;
v_18689:
    goto v_18685;
v_18686:
    goto v_18687;
v_18688:
    v_18707 = quot2(v_18708, v_18707);
    env = stack[-2];
    v_18707 = sub1(v_18707);
    env = stack[-2];
    goto v_18631;
    v_18707 = nil;
v_18631:
    fn = elt(env, 2); // simp
    v_18707 = (*qfn1(fn))(fn, v_18707);
    v_18707 = qcar(v_18707);
    goto v_18622;
    v_18707 = nil;
v_18622:
    goto v_18589;
v_18591:
    goto v_18703;
v_18697:
    v_18709 = elt(env, 1); // "pasf_floor: not a domain valued sf in input"
    goto v_18698;
v_18699:
    v_18708 = stack[-1];
    goto v_18700;
v_18701:
    v_18707 = stack[0];
    goto v_18702;
v_18703:
    goto v_18697;
v_18698:
    goto v_18699;
v_18700:
    goto v_18701;
v_18702:
    v_18707 = list3(v_18709, v_18708, v_18707);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_18707);
    }
    v_18707 = nil;
v_18589:
    return onevalue(v_18707);
}



// Code for bvarrd

static LispObject CC_bvarrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18681, v_18682;
    LispObject fn;
    argcheck(nargs, 0, "bvarrd");
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
    fn = elt(env, 9); // lex
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18599;
v_18595:
    v_18682 = qvalue(elt(env, 1)); // char
    goto v_18596;
v_18597:
    v_18681 = elt(env, 2); // (d e g r e e)
    goto v_18598;
v_18599:
    goto v_18595;
v_18596:
    goto v_18597;
v_18598:
    if (equal(v_18682, v_18681)) goto v_18593;
    else goto v_18594;
v_18593:
    goto v_18607;
v_18603:
    v_18682 = elt(env, 3); // "<bvar>"
    goto v_18604;
v_18605:
    v_18681 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_18606;
v_18607:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    fn = elt(env, 10); // errorml
    v_18681 = (*qfn2(fn))(fn, v_18682, v_18681);
    env = stack[-3];
    goto v_18592;
v_18594:
v_18592:
    fn = elt(env, 11); // mathml2
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_18681;
    fn = elt(env, 9); // lex
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18620;
v_18616:
    v_18682 = qvalue(elt(env, 1)); // char
    goto v_18617;
v_18618:
    v_18681 = elt(env, 2); // (d e g r e e)
    goto v_18619;
v_18620:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    if (equal(v_18682, v_18681)) goto v_18614;
    else goto v_18615;
v_18614:
    fn = elt(env, 12); // mathml
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_18681;
    fn = elt(env, 9); // lex
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18633;
v_18629:
    v_18682 = qvalue(elt(env, 1)); // char
    goto v_18630;
v_18631:
    v_18681 = elt(env, 4); // (!/ d e g r e e)
    goto v_18632;
v_18633:
    goto v_18629;
v_18630:
    goto v_18631;
v_18632:
    if (equal(v_18682, v_18681)) goto v_18628;
    goto v_18641;
v_18637:
    v_18682 = elt(env, 5); // "</degree>"
    goto v_18638;
v_18639:
    v_18681 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18640;
v_18641:
    goto v_18637;
v_18638:
    goto v_18639;
v_18640:
    fn = elt(env, 13); // error
    v_18681 = (*qfn2(fn))(fn, v_18682, v_18681);
    env = stack[-3];
    goto v_18626;
v_18628:
v_18626:
    fn = elt(env, 9); // lex
    v_18681 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18613;
v_18615:
    v_18681 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_18681;
    goto v_18613;
v_18613:
    goto v_18656;
v_18652:
    v_18682 = qvalue(elt(env, 1)); // char
    goto v_18653;
v_18654:
    v_18681 = elt(env, 6); // (!/ b v a r)
    goto v_18655;
v_18656:
    goto v_18652;
v_18653:
    goto v_18654;
v_18655:
    if (equal(v_18682, v_18681)) goto v_18650;
    else goto v_18651;
v_18650:
    goto v_18666;
v_18660:
    stack[-1] = elt(env, 7); // bvar
    goto v_18661;
v_18662:
    goto v_18663;
v_18664:
    v_18681 = stack[-2];
    v_18681 = ncons(v_18681);
    goto v_18665;
v_18666:
    goto v_18660;
v_18661:
    goto v_18662;
v_18663:
    goto v_18664;
v_18665:
    {
        LispObject v_18686 = stack[-1];
        LispObject v_18687 = stack[0];
        return list2star(v_18686, v_18687, v_18681);
    }
v_18651:
    goto v_18678;
v_18674:
    v_18682 = elt(env, 8); // "</bvar>"
    goto v_18675;
v_18676:
    v_18681 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18677;
v_18678:
    goto v_18674;
v_18675:
    goto v_18676;
v_18677:
    fn = elt(env, 10); // errorml
    v_18681 = (*qfn2(fn))(fn, v_18682, v_18681);
    goto v_18649;
v_18649:
    v_18681 = nil;
    return onevalue(v_18681);
}



// Code for module

static LispObject CC_module(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18600, v_18601;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18600 = v_18585;
// end of prologue
    goto v_18594;
v_18590:
    v_18601 = qvalue(elt(env, 1)); // !*mode
    goto v_18591;
v_18592:
    v_18600 = qvalue(elt(env, 2)); // mode!-list!*
    goto v_18593;
v_18594:
    goto v_18590;
v_18591:
    goto v_18592;
v_18593:
    v_18600 = cons(v_18601, v_18600);
    env = stack[0];
    qvalue(elt(env, 2)) = v_18600; // mode!-list!*
    v_18600 = nil;
    v_18600 = ncons(v_18600);
    env = stack[0];
    qvalue(elt(env, 3)) = v_18600; // alglist!*
    v_18600 = elt(env, 4); // symbolic
    qvalue(elt(env, 1)) = v_18600; // !*mode
    v_18600 = nil;
    return onevalue(v_18600);
}



// Code for log_freevars_list

static LispObject CC_log_freevars_list(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18624, v_18625;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "log_freevars_list");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_18587;
    stack[-1] = v_18586;
    stack[-2] = v_18585;
// end of prologue
v_18591:
    v_18624 = stack[-1];
    if (!consp(v_18624)) goto v_18594;
    else goto v_18595;
v_18594:
    v_18624 = nil;
    goto v_18590;
v_18595:
    v_18624 = stack[0];
    if (v_18624 == nil) goto v_18599;
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    if (!consp(v_18624)) goto v_18602;
    else goto v_18599;
v_18602:
    v_18624 = stack[-1];
    v_18624 = qcdr(v_18624);
    stack[-1] = v_18624;
    v_18624 = lisp_true;
    stack[0] = v_18624;
    goto v_18591;
v_18599:
    goto v_18615;
v_18611:
    v_18625 = stack[-2];
    goto v_18612;
v_18613:
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    goto v_18614;
v_18615:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    fn = elt(env, 1); // log_freevars
    v_18624 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-3];
    if (v_18624 == nil) goto v_18609;
    v_18624 = lisp_true;
    goto v_18590;
v_18609:
    v_18624 = stack[-1];
    v_18624 = qcdr(v_18624);
    stack[-1] = v_18624;
    goto v_18591;
    v_18624 = nil;
v_18590:
    return onevalue(v_18624);
}



// Code for simp!-prop!-condense

static LispObject CC_simpKpropKcondense(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18659, v_18660;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_18585;
// end of prologue
    stack[-2] = nil;
    goto v_18596;
v_18592:
    v_18660 = stack[-3];
    goto v_18593;
v_18594:
    v_18659 = elt(env, 1); // lambda_rfde09ec49c92
    goto v_18595;
v_18596:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    fn = elt(env, 2); // sort
    v_18659 = (*qfn2(fn))(fn, v_18660, v_18659);
    env = stack[-5];
    stack[-3] = v_18659;
v_18601:
    v_18659 = stack[-3];
    if (v_18659 == nil) goto v_18604;
    else goto v_18605;
v_18604:
    goto v_18600;
v_18605:
    v_18659 = stack[-3];
    v_18659 = qcar(v_18659);
    stack[-4] = v_18659;
    v_18659 = stack[-3];
    v_18659 = qcdr(v_18659);
    stack[-3] = v_18659;
    goto v_18617;
v_18613:
    v_18660 = stack[-4];
    goto v_18614;
v_18615:
    v_18659 = stack[-2];
    goto v_18616;
v_18617:
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    v_18659 = cons(v_18660, v_18659);
    env = stack[-5];
    stack[-2] = v_18659;
    v_18659 = stack[-3];
    stack[-1] = v_18659;
v_18623:
    v_18659 = stack[-1];
    if (v_18659 == nil) goto v_18627;
    else goto v_18628;
v_18627:
    goto v_18622;
v_18628:
    v_18659 = stack[-1];
    v_18659 = qcar(v_18659);
    stack[0] = v_18659;
    goto v_18643;
v_18639:
    v_18660 = stack[-4];
    goto v_18640;
v_18641:
    v_18659 = stack[0];
    goto v_18642;
v_18643:
    goto v_18639;
v_18640:
    goto v_18641;
v_18642:
    fn = elt(env, 3); // subsetp
    v_18659 = (*qfn2(fn))(fn, v_18660, v_18659);
    env = stack[-5];
    if (v_18659 == nil) goto v_18637;
    goto v_18651;
v_18647:
    v_18660 = stack[0];
    goto v_18648;
v_18649:
    v_18659 = stack[-3];
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    v_18659 = Ldelete(nil, v_18660, v_18659);
    env = stack[-5];
    stack[-3] = v_18659;
    goto v_18635;
v_18637:
v_18635:
    v_18659 = stack[-1];
    v_18659 = qcdr(v_18659);
    stack[-1] = v_18659;
    goto v_18623;
v_18622:
    goto v_18601;
v_18600:
    v_18659 = stack[-2];
    {
        fn = elt(env, 4); // ordn
        return (*qfn1(fn))(fn, v_18659);
    }
    return onevalue(v_18659);
}



// Code for lambda_rfde09ec49c92

static LispObject CC_lambda_rfde09ec49c92(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18598;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18586;
    v_18598 = v_18585;
// end of prologue
    goto v_18593;
v_18589:
    stack[-1] = Llength(nil, v_18598);
    env = stack[-2];
    goto v_18590;
v_18591:
    v_18598 = stack[0];
    v_18598 = Llength(nil, v_18598);
    goto v_18592;
v_18593:
    goto v_18589;
v_18590:
    goto v_18591;
v_18592:
    {
        LispObject v_18601 = stack[-1];
        return Llessp(nil, v_18601, v_18598);
    }
}



// Code for skp_ordp

static LispObject CC_skp_ordp(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18601, v_18602, v_18603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18601 = v_18586;
    v_18602 = v_18585;
// end of prologue
    goto v_18595;
v_18589:
    v_18603 = qcar(v_18602);
    goto v_18590;
v_18591:
    v_18602 = qcar(v_18601);
    goto v_18592;
v_18593:
    v_18601 = elt(env, 1); // atom_compare
    goto v_18594;
v_18595:
    goto v_18589;
v_18590:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_18603, v_18602, v_18601);
    }
}



// Code for vp2

static LispObject CC_vp2(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18610, v_18611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18585;
// end of prologue
    v_18611 = nil;
v_18590:
    v_18610 = stack[0];
    if (v_18610 == nil) goto v_18593;
    else goto v_18594;
v_18593:
    v_18610 = v_18611;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18610);
    }
v_18594:
    goto v_18605;
v_18601:
    v_18610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18602;
v_18603:
    goto v_18604;
v_18605:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    v_18610 = cons(v_18610, v_18611);
    env = stack[-1];
    v_18611 = v_18610;
    v_18610 = stack[0];
    v_18610 = qcdr(v_18610);
    stack[0] = v_18610;
    goto v_18590;
    v_18610 = nil;
    return onevalue(v_18610);
}



// Code for talp_specsubt

static LispObject CC_talp_specsubt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18695, v_18696, v_18697;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_specsubt");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_18587;
    stack[-4] = v_18586;
    stack[-5] = v_18585;
// end of prologue
    v_18695 = stack[0];
    if (!consp(v_18695)) goto v_18594;
    else goto v_18595;
v_18594:
    goto v_18605;
v_18601:
    v_18696 = stack[0];
    goto v_18602;
v_18603:
    v_18695 = stack[-5];
    goto v_18604;
v_18605:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    if (v_18696 == v_18695) goto v_18599;
    else goto v_18600;
v_18599:
    v_18695 = stack[-4];
    goto v_18598;
v_18600:
    v_18695 = stack[0];
    goto v_18598;
    v_18695 = nil;
v_18598:
    goto v_18591;
v_18595:
    goto v_18621;
v_18617:
    v_18696 = stack[-5];
    goto v_18618;
v_18619:
    v_18695 = stack[0];
    goto v_18620;
v_18621:
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    fn = elt(env, 1); // talp_eqtp
    v_18695 = (*qfn2(fn))(fn, v_18696, v_18695);
    env = stack[-7];
    if (v_18695 == nil) goto v_18615;
    v_18695 = stack[-4];
    goto v_18591;
v_18615:
    goto v_18630;
v_18626:
    v_18695 = stack[0];
    stack[-6] = qcar(v_18695);
    goto v_18627;
v_18628:
    v_18695 = stack[0];
    v_18695 = qcdr(v_18695);
    stack[-3] = v_18695;
    v_18695 = stack[-3];
    if (v_18695 == nil) goto v_18643;
    else goto v_18644;
v_18643:
    v_18695 = nil;
    goto v_18637;
v_18644:
    v_18695 = stack[-3];
    v_18695 = qcar(v_18695);
    goto v_18658;
v_18652:
    v_18697 = stack[-5];
    goto v_18653;
v_18654:
    v_18696 = stack[-4];
    goto v_18655;
v_18656:
    goto v_18657;
v_18658:
    goto v_18652;
v_18653:
    goto v_18654;
v_18655:
    goto v_18656;
v_18657:
    v_18695 = CC_talp_specsubt(elt(env, 0), 3, v_18697, v_18696, v_18695);
    env = stack[-7];
    v_18695 = ncons(v_18695);
    env = stack[-7];
    stack[-1] = v_18695;
    stack[-2] = v_18695;
v_18638:
    v_18695 = stack[-3];
    v_18695 = qcdr(v_18695);
    stack[-3] = v_18695;
    v_18695 = stack[-3];
    if (v_18695 == nil) goto v_18666;
    else goto v_18667;
v_18666:
    v_18695 = stack[-2];
    goto v_18637;
v_18667:
    goto v_18675;
v_18671:
    stack[0] = stack[-1];
    goto v_18672;
v_18673:
    v_18695 = stack[-3];
    v_18695 = qcar(v_18695);
    goto v_18688;
v_18682:
    v_18697 = stack[-5];
    goto v_18683;
v_18684:
    v_18696 = stack[-4];
    goto v_18685;
v_18686:
    goto v_18687;
v_18688:
    goto v_18682;
v_18683:
    goto v_18684;
v_18685:
    goto v_18686;
v_18687:
    v_18695 = CC_talp_specsubt(elt(env, 0), 3, v_18697, v_18696, v_18695);
    env = stack[-7];
    v_18695 = ncons(v_18695);
    env = stack[-7];
    goto v_18674;
v_18675:
    goto v_18671;
v_18672:
    goto v_18673;
v_18674:
    v_18695 = Lrplacd(nil, stack[0], v_18695);
    env = stack[-7];
    v_18695 = stack[-1];
    v_18695 = qcdr(v_18695);
    stack[-1] = v_18695;
    goto v_18638;
v_18637:
    goto v_18629;
v_18630:
    goto v_18626;
v_18627:
    goto v_18628;
v_18629:
    {
        LispObject v_18705 = stack[-6];
        return cons(v_18705, v_18695);
    }
v_18591:
    return onevalue(v_18695);
}



// Code for pasf_cein

static LispObject CC_pasf_cein(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18827, v_18828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_18585;
// end of prologue
    goto v_18607;
v_18603:
    v_18828 = stack[-3];
    goto v_18604;
v_18605:
    v_18827 = elt(env, 1); // true
    goto v_18606;
v_18607:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    if (v_18828 == v_18827) goto v_18601;
    else goto v_18602;
v_18601:
    v_18827 = lisp_true;
    goto v_18600;
v_18602:
    goto v_18617;
v_18613:
    v_18828 = stack[-3];
    goto v_18614;
v_18615:
    v_18827 = elt(env, 2); // false
    goto v_18616;
v_18617:
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    v_18827 = (v_18828 == v_18827 ? lisp_true : nil);
    goto v_18600;
    v_18827 = nil;
v_18600:
    if (v_18827 == nil) goto v_18598;
    v_18827 = lisp_true;
    goto v_18596;
v_18598:
    goto v_18628;
v_18624:
    goto v_18641;
v_18637:
    v_18828 = stack[-3];
    goto v_18638;
v_18639:
    v_18827 = elt(env, 1); // true
    goto v_18640;
v_18641:
    goto v_18637;
v_18638:
    goto v_18639;
v_18640:
    if (v_18828 == v_18827) goto v_18635;
    else goto v_18636;
v_18635:
    v_18827 = lisp_true;
    goto v_18634;
v_18636:
    goto v_18651;
v_18647:
    v_18828 = stack[-3];
    goto v_18648;
v_18649:
    v_18827 = elt(env, 2); // false
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    v_18827 = (v_18828 == v_18827 ? lisp_true : nil);
    goto v_18634;
    v_18827 = nil;
v_18634:
    if (v_18827 == nil) goto v_18632;
    v_18827 = stack[-3];
    v_18828 = v_18827;
    goto v_18630;
v_18632:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = Lconsp(nil, v_18827);
    env = stack[-5];
    if (v_18827 == nil) goto v_18657;
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18630;
v_18657:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18630;
    v_18828 = nil;
v_18630:
    goto v_18625;
v_18626:
    v_18827 = elt(env, 3); // (leq greaterp geq lessp)
    goto v_18627;
v_18628:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    v_18827 = Lmemq(nil, v_18828, v_18827);
    v_18827 = (v_18827 == nil ? lisp_true : nil);
    goto v_18596;
    v_18827 = nil;
v_18596:
    if (v_18827 == nil) goto v_18594;
    v_18827 = stack[-3];
    goto v_18590;
v_18594:
    v_18827 = stack[-3];
    v_18827 = qcdr(v_18827);
    v_18827 = qcar(v_18827);
    fn = elt(env, 6); // pasf_deci
    v_18827 = (*qfn1(fn))(fn, v_18827);
    env = stack[-5];
    stack[-2] = v_18827;
    v_18827 = stack[-2];
    v_18827 = qcar(v_18827);
    fn = elt(env, 7); // sfto_dcontentf
    v_18827 = (*qfn1(fn))(fn, v_18827);
    env = stack[-5];
    stack[-4] = v_18827;
    goto v_18686;
v_18680:
    v_18827 = stack[-3];
    stack[-1] = qcar(v_18827);
    goto v_18681;
v_18682:
    goto v_18694;
v_18690:
    goto v_18700;
v_18696:
    v_18827 = stack[-2];
    stack[0] = qcar(v_18827);
    goto v_18697;
v_18698:
    v_18827 = stack[-4];
    fn = elt(env, 8); // simp
    v_18827 = (*qfn1(fn))(fn, v_18827);
    env = stack[-5];
    v_18827 = qcar(v_18827);
    goto v_18699;
v_18700:
    goto v_18696;
v_18697:
    goto v_18698;
v_18699:
    fn = elt(env, 9); // quotfx
    stack[0] = (*qfn2(fn))(fn, stack[0], v_18827);
    env = stack[-5];
    goto v_18691;
v_18692:
    goto v_18714;
v_18710:
    goto v_18727;
v_18723:
    v_18828 = stack[-3];
    goto v_18724;
v_18725:
    v_18827 = elt(env, 1); // true
    goto v_18726;
v_18727:
    goto v_18723;
v_18724:
    goto v_18725;
v_18726:
    if (v_18828 == v_18827) goto v_18721;
    else goto v_18722;
v_18721:
    v_18827 = lisp_true;
    goto v_18720;
v_18722:
    goto v_18737;
v_18733:
    v_18828 = stack[-3];
    goto v_18734;
v_18735:
    v_18827 = elt(env, 2); // false
    goto v_18736;
v_18737:
    goto v_18733;
v_18734:
    goto v_18735;
v_18736:
    v_18827 = (v_18828 == v_18827 ? lisp_true : nil);
    goto v_18720;
    v_18827 = nil;
v_18720:
    if (v_18827 == nil) goto v_18718;
    v_18827 = stack[-3];
    v_18828 = v_18827;
    goto v_18716;
v_18718:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = Lconsp(nil, v_18827);
    env = stack[-5];
    if (v_18827 == nil) goto v_18743;
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18716;
v_18743:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18716;
    v_18828 = nil;
v_18716:
    goto v_18711;
v_18712:
    v_18827 = elt(env, 4); // (leq greaterp)
    goto v_18713;
v_18714:
    goto v_18710;
v_18711:
    goto v_18712;
v_18713:
    v_18827 = Lmemq(nil, v_18828, v_18827);
    if (v_18827 == nil) goto v_18709;
    goto v_18762;
v_18758:
    v_18827 = stack[-2];
    v_18827 = qcdr(v_18827);
    v_18828 = negate(v_18827);
    env = stack[-5];
    goto v_18759;
v_18760:
    v_18827 = stack[-4];
    goto v_18761;
v_18762:
    goto v_18758;
v_18759:
    goto v_18760;
v_18761:
    fn = elt(env, 10); // pasf_floor
    v_18827 = (*qfn2(fn))(fn, v_18828, v_18827);
    env = stack[-5];
    fn = elt(env, 11); // negf
    v_18827 = (*qfn1(fn))(fn, v_18827);
    env = stack[-5];
    goto v_18707;
v_18709:
    goto v_18773;
v_18769:
    goto v_18786;
v_18782:
    v_18828 = stack[-3];
    goto v_18783;
v_18784:
    v_18827 = elt(env, 1); // true
    goto v_18785;
v_18786:
    goto v_18782;
v_18783:
    goto v_18784;
v_18785:
    if (v_18828 == v_18827) goto v_18780;
    else goto v_18781;
v_18780:
    v_18827 = lisp_true;
    goto v_18779;
v_18781:
    goto v_18796;
v_18792:
    v_18828 = stack[-3];
    goto v_18793;
v_18794:
    v_18827 = elt(env, 2); // false
    goto v_18795;
v_18796:
    goto v_18792;
v_18793:
    goto v_18794;
v_18795:
    v_18827 = (v_18828 == v_18827 ? lisp_true : nil);
    goto v_18779;
    v_18827 = nil;
v_18779:
    if (v_18827 == nil) goto v_18777;
    v_18827 = stack[-3];
    v_18828 = v_18827;
    goto v_18775;
v_18777:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = Lconsp(nil, v_18827);
    env = stack[-5];
    if (v_18827 == nil) goto v_18802;
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18775;
v_18802:
    v_18827 = stack[-3];
    v_18827 = qcar(v_18827);
    v_18828 = v_18827;
    goto v_18775;
    v_18828 = nil;
v_18775:
    goto v_18770;
v_18771:
    v_18827 = elt(env, 5); // (geq lessp)
    goto v_18772;
v_18773:
    goto v_18769;
v_18770:
    goto v_18771;
v_18772:
    v_18827 = Lmemq(nil, v_18828, v_18827);
    if (v_18827 == nil) goto v_18768;
    goto v_18821;
v_18817:
    v_18827 = stack[-2];
    v_18827 = qcdr(v_18827);
    v_18828 = negate(v_18827);
    env = stack[-5];
    goto v_18818;
v_18819:
    v_18827 = stack[-4];
    goto v_18820;
v_18821:
    goto v_18817;
v_18818:
    goto v_18819;
v_18820:
    fn = elt(env, 12); // pasf_ceil
    v_18827 = (*qfn2(fn))(fn, v_18828, v_18827);
    env = stack[-5];
    fn = elt(env, 11); // negf
    v_18827 = (*qfn1(fn))(fn, v_18827);
    env = stack[-5];
    goto v_18707;
v_18768:
    v_18827 = nil;
v_18707:
    goto v_18693;
v_18694:
    goto v_18690;
v_18691:
    goto v_18692;
v_18693:
    fn = elt(env, 13); // addf
    v_18828 = (*qfn2(fn))(fn, stack[0], v_18827);
    goto v_18683;
v_18684:
    v_18827 = nil;
    goto v_18685;
v_18686:
    goto v_18680;
v_18681:
    goto v_18682;
v_18683:
    goto v_18684;
v_18685:
    {
        LispObject v_18834 = stack[-1];
        return list3(v_18834, v_18828, v_18827);
    }
v_18590:
    return onevalue(v_18827);
}



// Code for sets

static LispObject CC_sets(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18614, v_18615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18586;
    stack[-1] = v_18585;
// end of prologue
    v_18614 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_18614 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    v_18614 = elt(env, 2); // "<"
    v_18614 = Lprinc(nil, v_18614);
    env = stack[-2];
    v_18614 = stack[0];
    v_18614 = Lprinc(nil, v_18614);
    env = stack[-2];
    goto v_18601;
v_18597:
    v_18614 = stack[-1];
    v_18615 = qcar(v_18614);
    goto v_18598;
v_18599:
    v_18614 = elt(env, 3); // "/"
    goto v_18600;
v_18601:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    fn = elt(env, 6); // attributesml
    v_18614 = (*qfn2(fn))(fn, v_18615, v_18614);
    env = stack[-2];
    v_18614 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_18614 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    v_18614 = stack[-1];
    v_18614 = qcdr(v_18614);
    fn = elt(env, 8); // multi_elem
    v_18614 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    v_18614 = nil;
    fn = elt(env, 7); // indent!*
    v_18614 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    v_18614 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_18614 = (*qfn1(fn))(fn, v_18614);
    v_18614 = nil;
    return onevalue(v_18614);
}



// Code for resume

static LispObject CC_resume(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18625, v_18626, v_18627, v_18628;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18625 = v_18586;
    v_18626 = v_18585;
// end of prologue
    v_18627 = v_18625;
    if (v_18627 == nil) goto v_18591;
    goto v_18602;
v_18594:
    v_18627 = v_18625;
    v_18627 = qcar(v_18627);
    v_18628 = qcar(v_18627);
    goto v_18595;
v_18596:
    v_18627 = v_18625;
    v_18627 = qcar(v_18627);
    v_18627 = qcdr(v_18627);
    v_18627 = qcar(v_18627);
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    v_18625 = qcdr(v_18625);
    goto v_18601;
v_18602:
    goto v_18594;
v_18595:
    goto v_18596;
v_18597:
    goto v_18598;
v_18599:
    goto v_18600;
v_18601:
    {
        fn = elt(env, 2); // amatch
        return (*qfnn(fn))(fn, 4, v_18628, v_18627, v_18626, v_18625);
    }
v_18591:
    goto v_18619;
v_18615:
    v_18625 = v_18626;
    fn = elt(env, 3); // chk
    v_18626 = (*qfn1(fn))(fn, v_18625);
    env = stack[0];
    goto v_18616;
v_18617:
    v_18625 = lisp_true;
    goto v_18618;
v_18619:
    goto v_18615;
v_18616:
    goto v_18617;
v_18618:
    if (v_18626 == v_18625) goto v_18613;
    else goto v_18614;
v_18613:
    v_18625 = qvalue(elt(env, 1)); // substitution
    {
        fn = elt(env, 4); // bsubs
        return (*qfn1(fn))(fn, v_18625);
    }
v_18614:
    v_18625 = nil;
    return onevalue(v_18625);
}



// Code for evaluate

static LispObject CC_evaluate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18642, v_18643, v_18644;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_18643 = v_18587;
    v_18644 = v_18586;
    stack[-5] = v_18585;
// end of prologue
// Binding !*evaluateerror
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*evaluateerror
    v_18642 = qvalue(elt(env, 2)); // !*protfg
    v_18642 = (v_18642 == nil ? lisp_true : nil);
    stack[-3] = v_18642;
    goto v_18602;
v_18598:
    v_18642 = v_18644;
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    goto v_18598;
v_18599:
    goto v_18600;
v_18601:
    fn = elt(env, 6); // pair
    v_18642 = (*qfn2(fn))(fn, v_18642, v_18643);
    env = stack[-7];
    stack[-6] = v_18642;
    v_18643 = nil;
    v_18642 = lisp_true;
// Binding !*msg
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 3, -2);
    qvalue(elt(env, 3)) = v_18643; // !*msg
// Binding !*protfg
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 2, -1);
    qvalue(elt(env, 2)) = v_18642; // !*protfg
    goto v_18616;
v_18610:
    goto v_18624;
v_18618:
    stack[0] = elt(env, 4); // evaluate0
    goto v_18619;
v_18620:
    v_18642 = stack[-5];
    stack[-5] = Lmkquote(nil, v_18642);
    env = stack[-7];
    goto v_18621;
v_18622:
    v_18642 = stack[-6];
    v_18642 = Lmkquote(nil, v_18642);
    env = stack[-7];
    goto v_18623;
v_18624:
    goto v_18618;
v_18619:
    goto v_18620;
v_18621:
    goto v_18622;
v_18623:
    v_18644 = list3(stack[0], stack[-5], v_18642);
    env = stack[-7];
    goto v_18611;
v_18612:
    v_18643 = stack[-3];
    goto v_18613;
v_18614:
    v_18642 = nil;
    goto v_18615;
v_18616:
    goto v_18610;
v_18611:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    fn = elt(env, 7); // errorset
    v_18642 = (*qfnn(fn))(fn, 3, v_18644, v_18643, v_18642);
    env = stack[-7];
    stack[0] = v_18642;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18642 = stack[0];
    fn = elt(env, 8); // errorp
    v_18642 = (*qfn1(fn))(fn, v_18642);
    env = stack[-7];
    if (v_18642 == nil) goto v_18635;
    v_18642 = elt(env, 5); // "error during function evaluation (e.g. singularity)"
    fn = elt(env, 9); // rederr
    v_18642 = (*qfn1(fn))(fn, v_18642);
    goto v_18633;
v_18635:
v_18633:
    v_18642 = stack[0];
    v_18642 = qcar(v_18642);
    ;}  // end of a binding scope
    return onevalue(v_18642);
}



// Code for toolongexpp

static LispObject CC_toolongexpp(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18596, v_18597;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18596 = v_18585;
// end of prologue
    goto v_18592;
v_18588:
    fn = elt(env, 2); // numprintlen
    v_18596 = (*qfn1(fn))(fn, v_18596);
    env = stack[0];
    goto v_18589;
v_18590:
    v_18597 = qvalue(elt(env, 1)); // maxexpprintlen!*
    goto v_18591;
v_18592:
    goto v_18588;
v_18589:
    goto v_18590;
v_18591:
        return Lgreaterp(nil, v_18596, v_18597);
}



// Code for reval3

static LispObject CC_reval3(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18592;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18592 = v_18585;
// end of prologue
    fn = elt(env, 1); // simp
    v_18592 = (*qfn1(fn))(fn, v_18592);
    env = stack[0];
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_18592);
    }
}



// Code for incident

static LispObject CC_incident(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18639, v_18640, v_18641;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "incident");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18587;
    stack[0] = v_18586;
    stack[-2] = v_18585;
// end of prologue
v_18584:
    v_18639 = stack[0];
    if (v_18639 == nil) goto v_18591;
    else goto v_18592;
v_18591:
    v_18639 = nil;
    goto v_18590;
v_18592:
    goto v_18604;
v_18598:
    v_18641 = stack[-2];
    goto v_18599;
v_18600:
    v_18639 = stack[0];
    v_18640 = qcar(v_18639);
    goto v_18601;
v_18602:
    v_18639 = stack[-1];
    goto v_18603;
v_18604:
    goto v_18598;
v_18599:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    fn = elt(env, 1); // incident1
    v_18639 = (*qfnn(fn))(fn, 3, v_18641, v_18640, v_18639);
    env = stack[-3];
    v_18640 = v_18639;
    v_18639 = v_18640;
    if (v_18639 == nil) goto v_18613;
    goto v_18620;
v_18616:
    goto v_18617;
v_18618:
    v_18639 = stack[0];
    v_18639 = qcdr(v_18639);
    goto v_18619;
v_18620:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    return cons(v_18640, v_18639);
v_18613:
    goto v_18633;
v_18627:
    goto v_18628;
v_18629:
    v_18639 = stack[0];
    stack[0] = qcdr(v_18639);
    goto v_18630;
v_18631:
    v_18639 = stack[-1];
    v_18639 = add1(v_18639);
    env = stack[-3];
    goto v_18632;
v_18633:
    goto v_18627;
v_18628:
    goto v_18629;
v_18630:
    goto v_18631;
v_18632:
    stack[-1] = v_18639;
    goto v_18584;
    v_18639 = nil;
    goto v_18590;
    v_18639 = nil;
v_18590:
    return onevalue(v_18639);
}



// Code for assert_formproc

static LispObject CC_assert_formproc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18729, v_18730, v_18731;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_formproc");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_18587;
    stack[-8] = v_18586;
    stack[0] = v_18585;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    goto v_18607;
v_18603:
    v_18730 = stack[-7];
    goto v_18604;
v_18605:
    v_18729 = elt(env, 1); // symbolic
    goto v_18606;
v_18607:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    if (v_18730 == v_18729) goto v_18602;
    v_18729 = elt(env, 2); // "asserted procedures are available in symbolic mode only"
    v_18729 = ncons(v_18729);
    env = stack[-10];
    fn = elt(env, 7); // rederr
    v_18729 = (*qfn1(fn))(fn, v_18729);
    env = stack[-10];
    goto v_18600;
v_18602:
v_18600:
    v_18729 = stack[0];
    v_18729 = qcdr(v_18729);
    v_18729 = qcar(v_18729);
    stack[-9] = v_18729;
    v_18729 = stack[0];
    v_18729 = qcdr(v_18729);
    v_18729 = qcdr(v_18729);
    v_18729 = qcar(v_18729);
    v_18730 = v_18729;
    v_18729 = stack[0];
    v_18729 = qcdr(v_18729);
    v_18729 = qcdr(v_18729);
    v_18729 = qcdr(v_18729);
    v_18729 = qcar(v_18729);
    stack[-6] = v_18729;
    v_18729 = v_18730;
    v_18729 = Lreverse(nil, v_18729);
    env = stack[-10];
    v_18730 = v_18729;
    v_18729 = v_18730;
    v_18729 = qcar(v_18729);
    v_18729 = qcdr(v_18729);
    stack[-3] = v_18729;
    v_18729 = v_18730;
    v_18729 = qcdr(v_18729);
    v_18730 = v_18729;
    v_18729 = v_18730;
    stack[-1] = v_18729;
v_18635:
    v_18729 = stack[-1];
    if (v_18729 == nil) goto v_18639;
    else goto v_18640;
v_18639:
    goto v_18634;
v_18640:
    v_18729 = stack[-1];
    v_18729 = qcar(v_18729);
    stack[0] = v_18729;
    goto v_18651;
v_18647:
    v_18729 = stack[0];
    v_18730 = qcar(v_18729);
    goto v_18648;
v_18649:
    v_18729 = stack[-5];
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    v_18729 = cons(v_18730, v_18729);
    env = stack[-10];
    stack[-5] = v_18729;
    goto v_18660;
v_18656:
    v_18729 = stack[0];
    v_18730 = qcdr(v_18729);
    goto v_18657;
v_18658:
    v_18729 = stack[-4];
    goto v_18659;
v_18660:
    goto v_18656;
v_18657:
    goto v_18658;
v_18659:
    v_18729 = cons(v_18730, v_18729);
    env = stack[-10];
    stack[-4] = v_18729;
    v_18729 = stack[-1];
    v_18729 = qcdr(v_18729);
    stack[-1] = v_18729;
    goto v_18635;
v_18634:
    goto v_18673;
v_18667:
    goto v_18683;
v_18675:
    stack[-2] = elt(env, 3); // procedure
    goto v_18676;
v_18677:
    stack[-1] = stack[-9];
    goto v_18678;
v_18679:
    stack[0] = nil;
    goto v_18680;
v_18681:
    goto v_18694;
v_18688:
    v_18731 = elt(env, 4); // expr
    goto v_18689;
v_18690:
    v_18730 = stack[-5];
    goto v_18691;
v_18692:
    v_18729 = stack[-6];
    goto v_18693;
v_18694:
    goto v_18688;
v_18689:
    goto v_18690;
v_18691:
    goto v_18692;
v_18693:
    v_18729 = list3(v_18731, v_18730, v_18729);
    env = stack[-10];
    goto v_18682;
v_18683:
    goto v_18675;
v_18676:
    goto v_18677;
v_18678:
    goto v_18679;
v_18680:
    goto v_18681;
v_18682:
    v_18731 = list3star(stack[-2], stack[-1], stack[0], v_18729);
    env = stack[-10];
    goto v_18668;
v_18669:
    v_18730 = stack[-8];
    goto v_18670;
v_18671:
    v_18729 = stack[-7];
    goto v_18672;
v_18673:
    goto v_18667;
v_18668:
    goto v_18669;
v_18670:
    goto v_18671;
v_18672:
    fn = elt(env, 8); // formproc
    v_18729 = (*qfnn(fn))(fn, 3, v_18731, v_18730, v_18729);
    env = stack[-10];
    stack[0] = v_18729;
    v_18729 = qvalue(elt(env, 5)); // !*assert
    if (v_18729 == nil) goto v_18702;
    else goto v_18703;
v_18702:
    v_18729 = stack[0];
    goto v_18598;
v_18703:
    goto v_18714;
v_18708:
    v_18731 = stack[-9];
    goto v_18709;
v_18710:
    v_18730 = stack[-4];
    goto v_18711;
v_18712:
    v_18729 = stack[-3];
    goto v_18713;
v_18714:
    goto v_18708;
v_18709:
    goto v_18710;
v_18711:
    goto v_18712;
v_18713:
    v_18729 = list3(v_18731, v_18730, v_18729);
    env = stack[-10];
    fn = elt(env, 9); // assert_declarestat1
    v_18729 = (*qfn1(fn))(fn, v_18729);
    env = stack[-10];
    v_18730 = v_18729;
    goto v_18725;
v_18719:
    v_18731 = elt(env, 6); // progn
    goto v_18720;
v_18721:
    v_18729 = stack[0];
    goto v_18722;
v_18723:
    goto v_18724;
v_18725:
    goto v_18719;
v_18720:
    goto v_18721;
v_18722:
    goto v_18723;
v_18724:
    return list3(v_18731, v_18729, v_18730);
v_18598:
    return onevalue(v_18729);
}



// Code for fs!:onep!:

static LispObject CC_fsTonepT(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18590;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18590 = v_18585;
// end of prologue
    v_18590 = qcdr(v_18590);
    {
        fn = elt(env, 1); // fs!:onep
        return (*qfn1(fn))(fn, v_18590);
    }
}



// Code for ratdif

static LispObject CC_ratdif(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18600, v_18601;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18600 = v_18586;
    v_18601 = v_18585;
// end of prologue
    goto v_18595;
v_18589:
    stack[0] = v_18601;
    goto v_18590;
v_18591:
    fn = elt(env, 1); // ratminus
    v_18601 = (*qfn1(fn))(fn, v_18600);
    env = stack[-1];
    goto v_18592;
v_18593:
    v_18600 = nil;
    goto v_18594;
v_18595:
    goto v_18589;
v_18590:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    {
        LispObject v_18603 = stack[0];
        fn = elt(env, 2); // ratplusm
        return (*qfnn(fn))(fn, 3, v_18603, v_18601, v_18600);
    }
}



// Code for gcd!-with!-number

static LispObject CC_gcdKwithKnumber(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18668, v_18669, v_18670;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18586;
    v_18669 = v_18585;
// end of prologue
v_18590:
    goto v_18603;
v_18599:
    v_18670 = v_18669;
    goto v_18600;
v_18601:
    v_18668 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18602;
v_18603:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    if (v_18670 == v_18668) goto v_18597;
    else goto v_18598;
v_18597:
    v_18668 = lisp_true;
    goto v_18596;
v_18598:
    v_18668 = v_18669;
    if (!consp(v_18668)) goto v_18612;
    v_18668 = lisp_true;
    goto v_18610;
v_18612:
    v_18668 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_18668)) v_18668 = nil;
    else { v_18668 = qfastgets(v_18668);
           if (v_18668 != nil) { v_18668 = elt(v_18668, 3); // field
#ifdef RECORD_GET
             if (v_18668 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_18668 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_18668 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_18668 == SPID_NOPROP) v_18668 = nil; else v_18668 = lisp_true; }}
#endif
    goto v_18610;
    v_18668 = nil;
v_18610:
    goto v_18596;
    v_18668 = nil;
v_18596:
    if (v_18668 == nil) goto v_18594;
    v_18668 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18589;
v_18594:
    v_18668 = stack[0];
    if (!consp(v_18668)) goto v_18624;
    else goto v_18625;
v_18624:
    v_18668 = lisp_true;
    goto v_18623;
v_18625:
    v_18668 = stack[0];
    v_18668 = qcar(v_18668);
    v_18668 = (consp(v_18668) ? nil : lisp_true);
    goto v_18623;
    v_18668 = nil;
v_18623:
    if (v_18668 == nil) goto v_18621;
    v_18668 = stack[0];
    if (v_18668 == nil) goto v_18635;
    else goto v_18636;
v_18635:
    v_18668 = v_18669;
        return Labsval(nil, v_18668);
v_18636:
    v_18668 = stack[0];
    if (!consp(v_18668)) goto v_18641;
    v_18668 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18589;
v_18641:
    goto v_18651;
v_18647:
    goto v_18648;
v_18649:
    v_18668 = stack[0];
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    {
        fn = elt(env, 2); // gcddd
        return (*qfn2(fn))(fn, v_18669, v_18668);
    }
    goto v_18592;
v_18621:
    goto v_18661;
v_18657:
    goto v_18658;
v_18659:
    v_18668 = stack[0];
    v_18668 = qcar(v_18668);
    v_18668 = qcdr(v_18668);
    goto v_18660;
v_18661:
    goto v_18657;
v_18658:
    goto v_18659;
v_18660:
    v_18668 = CC_gcdKwithKnumber(elt(env, 0), v_18669, v_18668);
    env = stack[-1];
    v_18669 = v_18668;
    v_18668 = stack[0];
    v_18668 = qcdr(v_18668);
    stack[0] = v_18668;
    goto v_18590;
v_18592:
    v_18668 = nil;
v_18589:
    return onevalue(v_18668);
}



// Code for lex_skip_line_comment

static LispObject CC_lex_skip_line_comment(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18618, v_18619;
    LispObject fn;
    argcheck(nargs, 0, "lex_skip_line_comment");
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
v_18588:
    goto v_18601;
v_18597:
    v_18619 = qvalue(elt(env, 1)); // lex_char
    goto v_18598;
v_18599:
    v_18618 = qvalue(elt(env, 2)); // !$eol!$
    goto v_18600;
v_18601:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    if (equal(v_18619, v_18618)) goto v_18595;
    else goto v_18596;
v_18595:
    v_18618 = lisp_true;
    goto v_18594;
v_18596:
    goto v_18611;
v_18607:
    v_18619 = qvalue(elt(env, 1)); // lex_char
    goto v_18608;
v_18609:
    v_18618 = qvalue(elt(env, 3)); // !$eof!$
    goto v_18610;
v_18611:
    goto v_18607;
v_18608:
    goto v_18609;
v_18610:
    v_18618 = (equal(v_18619, v_18618) ? lisp_true : nil);
    goto v_18594;
    v_18618 = nil;
v_18594:
    if (v_18618 == nil) goto v_18592;
    goto v_18587;
v_18592:
    fn = elt(env, 4); // yyreadch
    v_18618 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    goto v_18588;
v_18587:
    v_18618 = lisp_true;
    return onevalue(v_18618);
}



// Code for multdfconst

static LispObject CC_multdfconst(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18636, v_18637;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18586;
    stack[-2] = v_18585;
// end of prologue
    stack[-3] = nil;
v_18591:
    v_18636 = stack[-1];
    if (v_18636 == nil) goto v_18598;
    else goto v_18599;
v_18598:
    v_18636 = lisp_true;
    goto v_18597;
v_18599:
    v_18636 = stack[-2];
    v_18636 = qcar(v_18636);
    v_18636 = (v_18636 == nil ? lisp_true : nil);
    goto v_18597;
    v_18636 = nil;
v_18597:
    if (v_18636 == nil) goto v_18595;
    v_18636 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18636);
    }
v_18595:
    goto v_18618;
v_18612:
    v_18636 = stack[-1];
    v_18636 = qcar(v_18636);
    stack[0] = qcar(v_18636);
    goto v_18613;
v_18614:
    goto v_18628;
v_18624:
    v_18637 = stack[-2];
    goto v_18625;
v_18626:
    v_18636 = stack[-1];
    v_18636 = qcar(v_18636);
    v_18636 = qcdr(v_18636);
    goto v_18627;
v_18628:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    fn = elt(env, 2); // multsq
    v_18636 = (*qfn2(fn))(fn, v_18637, v_18636);
    env = stack[-4];
    fn = elt(env, 3); // subs2q
    v_18637 = (*qfn1(fn))(fn, v_18636);
    env = stack[-4];
    goto v_18615;
v_18616:
    v_18636 = stack[-3];
    goto v_18617;
v_18618:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    v_18636 = acons(stack[0], v_18637, v_18636);
    env = stack[-4];
    stack[-3] = v_18636;
    v_18636 = stack[-1];
    v_18636 = qcdr(v_18636);
    stack[-1] = v_18636;
    goto v_18591;
    v_18636 = nil;
    return onevalue(v_18636);
}



// Code for mri_congp

static LispObject CC_mri_congp(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18596, v_18597;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18596 = v_18585;
// end of prologue
    goto v_18591;
v_18587:
    fn = elt(env, 2); // mri_opn
    v_18596 = (*qfn1(fn))(fn, v_18596);
    env = stack[0];
    goto v_18588;
v_18589:
    v_18597 = elt(env, 1); // (cong ncong)
    goto v_18590;
v_18591:
    goto v_18587;
v_18588:
    goto v_18589;
v_18590:
    v_18596 = Lmemq(nil, v_18596, v_18597);
    return onevalue(v_18596);
}



// Code for qqe_ofsf_varlat

static LispObject CC_qqe_ofsf_varlat(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18614, v_18615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18614 = v_18585;
// end of prologue
    fn = elt(env, 1); // qqe_ofsf_prepat
    v_18614 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    stack[-1] = v_18614;
    goto v_18595;
v_18591:
    goto v_18601;
v_18597:
    v_18614 = stack[-1];
    fn = elt(env, 2); // qqe_arg2l
    v_18615 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    goto v_18598;
v_18599:
    v_18614 = nil;
    goto v_18600;
v_18601:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    fn = elt(env, 3); // qqe_ofsf_varlterm
    stack[0] = (*qfn2(fn))(fn, v_18615, v_18614);
    env = stack[-2];
    goto v_18592;
v_18593:
    goto v_18610;
v_18606:
    v_18614 = stack[-1];
    fn = elt(env, 4); // qqe_arg2r
    v_18615 = (*qfn1(fn))(fn, v_18614);
    env = stack[-2];
    goto v_18607;
v_18608:
    v_18614 = nil;
    goto v_18609;
v_18610:
    goto v_18606;
v_18607:
    goto v_18608;
v_18609:
    fn = elt(env, 3); // qqe_ofsf_varlterm
    v_18614 = (*qfn2(fn))(fn, v_18615, v_18614);
    env = stack[-2];
    goto v_18594;
v_18595:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    {
        LispObject v_18618 = stack[0];
        fn = elt(env, 5); // union
        return (*qfn2(fn))(fn, v_18618, v_18614);
    }
}



// Code for cgp_mk

static LispObject CC_cgp_mk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18615, v_18616, v_18617, v_18618, v_18619;
    LispObject v_18589, v_18588, v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "cgp_mk");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    v_18588 = va_arg(aa, LispObject);
    v_18589 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_18589,v_18588,v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_18585,v_18586,v_18587,v_18588,v_18589);
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18615 = v_18589;
    v_18616 = v_18588;
    v_18617 = v_18587;
    v_18618 = v_18586;
    v_18619 = v_18585;
// end of prologue
    goto v_18600;
v_18592:
    stack[-2] = elt(env, 1); // cgp
    goto v_18593;
v_18594:
    stack[-1] = v_18619;
    goto v_18595;
v_18596:
    stack[0] = v_18618;
    goto v_18597;
v_18598:
    goto v_18611;
v_18605:
    goto v_18606;
v_18607:
    goto v_18608;
v_18609:
    goto v_18610;
v_18611:
    goto v_18605;
v_18606:
    goto v_18607;
v_18608:
    goto v_18609;
v_18610:
    v_18615 = list3(v_18617, v_18616, v_18615);
    goto v_18599;
v_18600:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    goto v_18596;
v_18597:
    goto v_18598;
v_18599:
    {
        LispObject v_18623 = stack[-2];
        LispObject v_18624 = stack[-1];
        LispObject v_18625 = stack[0];
        return list3star(v_18623, v_18624, v_18625, v_18615);
    }
}



// Code for matrixom

static LispObject CC_matrixom(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18605;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18585;
// end of prologue
    v_18605 = elt(env, 1); // "<OMA>"
    fn = elt(env, 4); // printout
    v_18605 = (*qfn1(fn))(fn, v_18605);
    env = stack[-1];
    v_18605 = lisp_true;
    fn = elt(env, 5); // indent!*
    v_18605 = (*qfn1(fn))(fn, v_18605);
    env = stack[-1];
    v_18605 = elt(env, 2); // "<OMS cd=""linalg1"" name=""matrix""/>"
    fn = elt(env, 4); // printout
    v_18605 = (*qfn1(fn))(fn, v_18605);
    env = stack[-1];
    v_18605 = stack[0];
    v_18605 = qcdr(v_18605);
    v_18605 = qcdr(v_18605);
    v_18605 = qcdr(v_18605);
    v_18605 = qcar(v_18605);
    fn = elt(env, 6); // matrixrowom
    v_18605 = (*qfn1(fn))(fn, v_18605);
    env = stack[-1];
    v_18605 = nil;
    fn = elt(env, 5); // indent!*
    v_18605 = (*qfn1(fn))(fn, v_18605);
    env = stack[-1];
    v_18605 = elt(env, 3); // "</OMA>"
    fn = elt(env, 4); // printout
    v_18605 = (*qfn1(fn))(fn, v_18605);
    v_18605 = nil;
    return onevalue(v_18605);
}



// Code for alg_plus

static LispObject CC_alg_plus(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18602, v_18603, v_18604;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18602 = v_18586;
    v_18603 = v_18585;
// end of prologue
    goto v_18598;
v_18592:
    v_18604 = elt(env, 1); // plus
    goto v_18593;
v_18594:
    goto v_18595;
v_18596:
    goto v_18597;
v_18598:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    goto v_18596;
v_18597:
    v_18602 = list3(v_18604, v_18603, v_18602);
    env = stack[0];
    {
        fn = elt(env, 2); // aeval
        return (*qfn1(fn))(fn, v_18602);
    }
    return onevalue(v_18602);
}



// Code for evaluate!-horner

static LispObject CC_evaluateKhorner(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18632, v_18633, v_18634;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18585;
// end of prologue
    goto v_18591;
v_18587:
    v_18633 = stack[-1];
    goto v_18588;
v_18589:
    v_18632 = qvalue(elt(env, 1)); // horner!-cache!*
    goto v_18590;
v_18591:
    goto v_18587;
v_18588:
    goto v_18589;
v_18590:
    v_18632 = Lassoc(nil, v_18633, v_18632);
    stack[-2] = v_18632;
    v_18632 = stack[-2];
    if (v_18632 == nil) goto v_18599;
    v_18632 = stack[-2];
    v_18632 = qcdr(v_18632);
    goto v_18597;
v_18599:
    v_18632 = stack[-1];
    fn = elt(env, 2); // simp!*
    v_18632 = (*qfn1(fn))(fn, v_18632);
    env = stack[-3];
    stack[-2] = v_18632;
    goto v_18613;
v_18609:
    v_18632 = stack[-2];
    v_18632 = qcar(v_18632);
    fn = elt(env, 3); // hornerf
    stack[0] = (*qfn1(fn))(fn, v_18632);
    env = stack[-3];
    goto v_18610;
v_18611:
    v_18632 = stack[-2];
    v_18632 = qcdr(v_18632);
    fn = elt(env, 3); // hornerf
    v_18632 = (*qfn1(fn))(fn, v_18632);
    env = stack[-3];
    goto v_18612;
v_18613:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    v_18632 = cons(stack[0], v_18632);
    env = stack[-3];
    fn = elt(env, 4); // prepsq
    v_18632 = (*qfn1(fn))(fn, v_18632);
    env = stack[-3];
    stack[-2] = v_18632;
    goto v_18627;
v_18621:
    v_18634 = stack[-1];
    goto v_18622;
v_18623:
    v_18633 = stack[-2];
    goto v_18624;
v_18625:
    v_18632 = qvalue(elt(env, 1)); // horner!-cache!*
    goto v_18626;
v_18627:
    goto v_18621;
v_18622:
    goto v_18623;
v_18624:
    goto v_18625;
v_18626:
    v_18632 = acons(v_18634, v_18633, v_18632);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_18632; // horner!-cache!*
    v_18632 = stack[-2];
    goto v_18597;
    v_18632 = nil;
v_18597:
    return onevalue(v_18632);
}



// Code for lispreadp

static LispObject CC_lispreadp(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18595, v_18596;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18595 = v_18585;
// end of prologue
    goto v_18592;
v_18588:
    goto v_18589;
v_18590:
    v_18596 = elt(env, 1); // read
    goto v_18591;
v_18592:
    goto v_18588;
v_18589:
    goto v_18590;
v_18591:
        return Leqcar(nil, v_18595, v_18596);
}



// Code for indexsymmetrize

static LispObject CC_indexsymmetrize(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18658, v_18659, v_18660;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_18585;
// end of prologue
    goto v_18599;
v_18595:
    v_18658 = stack[-2];
    v_18659 = qcar(v_18658);
    goto v_18596;
v_18597:
    v_18658 = elt(env, 1); // indxsymmetrize
    goto v_18598;
v_18599:
    goto v_18595;
v_18596:
    goto v_18597;
v_18598:
    v_18658 = get(v_18659, v_18658);
    env = stack[-4];
    stack[-3] = v_18658;
    v_18658 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18658;
    goto v_18609;
v_18605:
    v_18659 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18606;
v_18607:
    v_18658 = stack[-2];
    v_18658 = qcdr(v_18658);
    goto v_18608;
v_18609:
    goto v_18605;
v_18606:
    goto v_18607;
v_18608:
    v_18658 = cons(v_18659, v_18658);
    env = stack[-4];
    stack[-1] = v_18658;
v_18592:
    v_18658 = stack[-3];
    if (v_18658 == nil) goto v_18615;
    else goto v_18616;
v_18615:
    goto v_18625;
v_18619:
    v_18660 = stack[0];
    goto v_18620;
v_18621:
    v_18658 = stack[-2];
    v_18659 = qcar(v_18658);
    goto v_18622;
v_18623:
    v_18658 = stack[-1];
    v_18658 = qcdr(v_18658);
    goto v_18624;
v_18625:
    goto v_18619;
v_18620:
    goto v_18621;
v_18622:
    goto v_18623;
v_18624:
    return list2star(v_18660, v_18659, v_18658);
v_18616:
    goto v_18636;
v_18632:
    v_18658 = stack[-3];
    v_18659 = qcar(v_18658);
    goto v_18633;
v_18634:
    v_18658 = stack[-1];
    v_18658 = qcdr(v_18658);
    goto v_18635;
v_18636:
    goto v_18632;
v_18633:
    goto v_18634;
v_18635:
    v_18658 = Lapply1(nil, v_18659, v_18658);
    env = stack[-4];
    stack[-1] = v_18658;
    v_18658 = stack[-1];
    if (v_18658 == nil) goto v_18643;
    else goto v_18644;
v_18643:
    v_18658 = nil;
    goto v_18591;
v_18644:
    goto v_18652;
v_18648:
    v_18658 = stack[-1];
    v_18659 = qcar(v_18658);
    goto v_18649;
v_18650:
    v_18658 = stack[0];
    goto v_18651;
v_18652:
    goto v_18648;
v_18649:
    goto v_18650;
v_18651:
    v_18658 = times2(v_18659, v_18658);
    env = stack[-4];
    stack[0] = v_18658;
    v_18658 = stack[-3];
    v_18658 = qcdr(v_18658);
    stack[-3] = v_18658;
    goto v_18592;
v_18591:
    return onevalue(v_18658);
}



// Code for s_actual_world1

static LispObject CC_s_actual_world1(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18591;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18591 = v_18585;
// end of prologue
    v_18591 = qcar(v_18591);
    v_18591 = qcar(v_18591);
    v_18591 = qcar(v_18591);
    return onevalue(v_18591);
}



// Code for assert_procstat!-argl

static LispObject CC_assert_procstatKargl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18757, v_18758, v_18759;
    LispObject fn;
    argcheck(nargs, 0, "assert_procstat-argl");
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
    stack[0] = nil;
v_18594:
    goto v_18603;
v_18599:
    v_18758 = qvalue(elt(env, 1)); // cursym!*
    goto v_18600;
v_18601:
    v_18757 = elt(env, 2); // !*rpar!*
    goto v_18602;
v_18603:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    if (v_18758 == v_18757) goto v_18597;
    else goto v_18598;
v_18597:
    goto v_18593;
v_18598:
    fn = elt(env, 12); // eolcheck
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    if (symbolp(v_18757)) goto v_18611;
    goto v_18619;
v_18615:
    v_18758 = elt(env, 3); // "Expecting identifier but found"
    goto v_18616;
v_18617:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    goto v_18618;
v_18619:
    goto v_18615;
v_18616:
    goto v_18617;
v_18618:
    v_18757 = list2(v_18758, v_18757);
    env = stack[-3];
    fn = elt(env, 13); // assert_rederr
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    goto v_18609;
v_18611:
v_18609:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    stack[-2] = v_18757;
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18632;
v_18628:
    v_18758 = qvalue(elt(env, 1)); // cursym!*
    goto v_18629;
v_18630:
    v_18757 = elt(env, 4); // !*colon!*
    goto v_18631;
v_18632:
    goto v_18628;
v_18629:
    goto v_18630;
v_18631:
    if (v_18758 == v_18757) goto v_18626;
    else goto v_18627;
v_18626:
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    fn = elt(env, 15); // assert_typesyntaxp
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    if (v_18757 == nil) goto v_18638;
    else goto v_18639;
v_18638:
    goto v_18648;
v_18644:
    v_18758 = elt(env, 5); // "Expecting type but found"
    goto v_18645;
v_18646:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    goto v_18647;
v_18648:
    goto v_18644;
v_18645:
    goto v_18646;
v_18647:
    v_18757 = list2(v_18758, v_18757);
    env = stack[-3];
    fn = elt(env, 13); // assert_rederr
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    goto v_18637;
v_18639:
v_18637:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    stack[-1] = v_18757;
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_18757 = stack[-1];
    goto v_18625;
v_18627:
    v_18757 = nil;
v_18625:
    goto v_18661;
v_18655:
    v_18759 = stack[-2];
    goto v_18656;
v_18657:
    v_18758 = v_18757;
    goto v_18658;
v_18659:
    v_18757 = stack[0];
    goto v_18660;
v_18661:
    goto v_18655;
v_18656:
    goto v_18657;
v_18658:
    goto v_18659;
v_18660:
    v_18757 = acons(v_18759, v_18758, v_18757);
    env = stack[-3];
    stack[0] = v_18757;
    goto v_18673;
v_18669:
    v_18758 = qvalue(elt(env, 1)); // cursym!*
    goto v_18670;
v_18671:
    v_18757 = elt(env, 6); // (!*comma!* !*rpar!*)
    goto v_18672;
v_18673:
    goto v_18669;
v_18670:
    goto v_18671;
v_18672:
    v_18757 = Lmemq(nil, v_18758, v_18757);
    if (v_18757 == nil) goto v_18667;
    else goto v_18668;
v_18667:
    goto v_18683;
v_18679:
    v_18758 = elt(env, 7); // "Expecting ',' or ')' but found"
    goto v_18680;
v_18681:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    goto v_18682;
v_18683:
    goto v_18679;
v_18680:
    goto v_18681;
v_18682:
    v_18757 = list2(v_18758, v_18757);
    env = stack[-3];
    fn = elt(env, 13); // assert_rederr
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    goto v_18666;
v_18668:
v_18666:
    goto v_18694;
v_18690:
    v_18758 = qvalue(elt(env, 1)); // cursym!*
    goto v_18691;
v_18692:
    v_18757 = elt(env, 8); // !*comma!*
    goto v_18693;
v_18694:
    goto v_18690;
v_18691:
    goto v_18692;
v_18693:
    if (v_18758 == v_18757) goto v_18688;
    else goto v_18689;
v_18688:
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18687;
v_18689:
v_18687:
    goto v_18594;
v_18593:
    goto v_18711;
v_18707:
    v_18758 = qvalue(elt(env, 9)); // nxtsym!*
    goto v_18708;
v_18709:
    v_18757 = elt(env, 4); // !*colon!*
    goto v_18710;
v_18711:
    goto v_18707;
v_18708:
    goto v_18709;
v_18710:
    if (v_18758 == v_18757) goto v_18705;
    else goto v_18706;
v_18705:
    v_18757 = lisp_true;
    goto v_18704;
v_18706:
    goto v_18721;
v_18717:
    v_18758 = qvalue(elt(env, 9)); // nxtsym!*
    goto v_18718;
v_18719:
    v_18757 = elt(env, 10); // !:
    goto v_18720;
v_18721:
    goto v_18717;
v_18718:
    goto v_18719;
v_18720:
    v_18757 = (v_18758 == v_18757 ? lisp_true : nil);
    goto v_18704;
    v_18757 = nil;
v_18704:
    if (v_18757 == nil) goto v_18702;
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 14); // scan
    v_18757 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    fn = elt(env, 15); // assert_typesyntaxp
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    if (v_18757 == nil) goto v_18729;
    else goto v_18730;
v_18729:
    goto v_18739;
v_18735:
    v_18758 = elt(env, 5); // "Expecting type but found"
    goto v_18736;
v_18737:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    goto v_18738;
v_18739:
    goto v_18735;
v_18736:
    goto v_18737;
v_18738:
    v_18757 = list2(v_18758, v_18757);
    env = stack[-3];
    fn = elt(env, 13); // assert_rederr
    v_18757 = (*qfn1(fn))(fn, v_18757);
    env = stack[-3];
    goto v_18728;
v_18730:
v_18728:
    v_18757 = qvalue(elt(env, 1)); // cursym!*
    goto v_18700;
v_18702:
    v_18757 = nil;
v_18700:
    goto v_18750;
v_18744:
    v_18759 = elt(env, 11); // returnvalue
    goto v_18745;
v_18746:
    v_18758 = v_18757;
    goto v_18747;
v_18748:
    v_18757 = stack[0];
    goto v_18749;
v_18750:
    goto v_18744;
v_18745:
    goto v_18746;
v_18747:
    goto v_18748;
v_18749:
    v_18757 = acons(v_18759, v_18758, v_18757);
    stack[0] = v_18757;
    v_18757 = stack[0];
        return Lnreverse(nil, v_18757);
    return onevalue(v_18757);
}



// Code for cde_replace_nth

static LispObject CC_cde_replace_nth(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18644, v_18645;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cde_replace_nth");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18587;
    stack[-1] = v_18586;
    stack[-2] = v_18585;
// end of prologue
    stack[-3] = nil;
v_18592:
    v_18644 = stack[-2];
    if (v_18644 == nil) goto v_18596;
    goto v_18606;
v_18602:
    v_18645 = stack[-1];
    goto v_18603;
v_18604:
    v_18644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18605;
v_18606:
    goto v_18602;
v_18603:
    goto v_18604;
v_18605:
    if (v_18645 == v_18644) goto v_18600;
    else goto v_18601;
v_18600:
    goto v_18614;
v_18610:
    stack[-1] = stack[-3];
    goto v_18611;
v_18612:
    goto v_18621;
v_18617:
    v_18645 = stack[0];
    goto v_18618;
v_18619:
    v_18644 = stack[-2];
    v_18644 = qcdr(v_18644);
    goto v_18620;
v_18621:
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    v_18644 = cons(v_18645, v_18644);
    env = stack[-4];
    goto v_18613;
v_18614:
    goto v_18610;
v_18611:
    goto v_18612;
v_18613:
    {
        LispObject v_18650 = stack[-1];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_18650, v_18644);
    }
v_18601:
    goto v_18632;
v_18628:
    v_18644 = stack[-2];
    v_18645 = qcar(v_18644);
    goto v_18629;
v_18630:
    v_18644 = stack[-3];
    goto v_18631;
v_18632:
    goto v_18628;
v_18629:
    goto v_18630;
v_18631:
    v_18644 = cons(v_18645, v_18644);
    env = stack[-4];
    stack[-3] = v_18644;
    v_18644 = stack[-2];
    v_18644 = qcdr(v_18644);
    stack[-2] = v_18644;
    v_18644 = stack[-1];
    v_18644 = sub1(v_18644);
    env = stack[-4];
    stack[-1] = v_18644;
    goto v_18592;
    goto v_18594;
v_18596:
    v_18644 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18644);
    }
v_18594:
    v_18644 = nil;
    return onevalue(v_18644);
}



// Code for lex_process_directive

static LispObject CC_lex_process_directive(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18693, v_18694, v_18695;
    LispObject fn;
    argcheck(nargs, 0, "lex_process_directive");
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
    goto v_18597;
v_18593:
    v_18694 = qvalue(elt(env, 1)); // yylval
    goto v_18594;
v_18595:
    v_18693 = elt(env, 2); // !#endif
    goto v_18596;
v_18597:
    goto v_18593;
v_18594:
    goto v_18595;
v_18596:
    if (v_18694 == v_18693) goto v_18591;
    else goto v_18592;
v_18591:
    v_18693 = qvalue(elt(env, 3)); // if_depth
    v_18693 = (LispObject)zerop(v_18693);
    v_18693 = v_18693 ? lisp_true : nil;
    env = stack[-1];
    if (v_18693 == nil) goto v_18603;
    v_18693 = elt(env, 4); // "+++ #endif not follopwing #if"
    v_18693 = Lprintc(nil, v_18693);
    env = stack[-1];
    goto v_18601;
v_18603:
v_18601:
    v_18693 = qvalue(elt(env, 3)); // if_depth
    v_18693 = sub1(v_18693);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_18693; // if_depth
    v_18693 = lisp_true;
    goto v_18588;
v_18592:
    goto v_18617;
v_18613:
    v_18694 = qvalue(elt(env, 1)); // yylval
    goto v_18614;
v_18615:
    v_18693 = qvalue(elt(env, 5)); // !$eof!$
    goto v_18616;
v_18617:
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    if (equal(v_18694, v_18693)) goto v_18611;
    else goto v_18612;
v_18611:
    v_18693 = qvalue(elt(env, 3)); // if_depth
    v_18693 = (LispObject)zerop(v_18693);
    v_18693 = v_18693 ? lisp_true : nil;
    env = stack[-1];
    if (v_18693 == nil) goto v_18622;
    else goto v_18623;
v_18622:
    v_18693 = elt(env, 6); // "+++ #endif missing at end of file"
    v_18693 = Lprintc(nil, v_18693);
    goto v_18621;
v_18623:
v_18621:
    v_18693 = lisp_true;
    goto v_18588;
v_18612:
    goto v_18635;
v_18631:
    v_18694 = qvalue(elt(env, 1)); // yylval
    goto v_18632;
v_18633:
    v_18693 = elt(env, 7); // !#if
    goto v_18634;
v_18635:
    goto v_18631;
v_18632:
    goto v_18633;
v_18634:
    if (v_18694 == v_18693) goto v_18629;
    else goto v_18630;
v_18629:
    v_18693 = qvalue(elt(env, 3)); // if_depth
    v_18693 = add1(v_18693);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_18693; // if_depth
    fn = elt(env, 10); // read_s_expression
    v_18693 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_18648;
v_18642:
    v_18695 = qvalue(elt(env, 1)); // yylval
    goto v_18643;
v_18644:
    v_18694 = nil;
    goto v_18645;
v_18646:
    v_18693 = nil;
    goto v_18647;
v_18648:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    goto v_18646;
v_18647:
    fn = elt(env, 11); // errorset
    v_18693 = (*qfnn(fn))(fn, 3, v_18695, v_18694, v_18693);
    env = stack[-1];
    stack[0] = v_18693;
    v_18693 = stack[0];
    fn = elt(env, 12); // errorp
    v_18693 = (*qfn1(fn))(fn, v_18693);
    env = stack[-1];
    if (v_18693 == nil) goto v_18656;
    else goto v_18654;
v_18656:
    v_18693 = stack[0];
    v_18693 = qcar(v_18693);
    if (v_18693 == nil) goto v_18654;
    goto v_18655;
v_18654:
    v_18693 = lisp_true;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18693);
    }
v_18655:
    v_18693 = lisp_true;
    goto v_18588;
    goto v_18590;
v_18630:
    goto v_18673;
v_18669:
    v_18694 = qvalue(elt(env, 1)); // yylval
    goto v_18670;
v_18671:
    v_18693 = elt(env, 8); // !#else
    goto v_18672;
v_18673:
    goto v_18669;
v_18670:
    goto v_18671;
v_18672:
    if (v_18694 == v_18693) goto v_18667;
    else goto v_18668;
v_18667:
    v_18693 = nil;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18693);
    }
v_18668:
    goto v_18684;
v_18680:
    v_18694 = qvalue(elt(env, 1)); // yylval
    goto v_18681;
v_18682:
    v_18693 = elt(env, 9); // !#elif
    goto v_18683;
v_18684:
    goto v_18680;
v_18681:
    goto v_18682;
v_18683:
    if (v_18694 == v_18693) goto v_18678;
    else goto v_18679;
v_18678:
    fn = elt(env, 10); // read_s_expression
    v_18693 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_18693 = nil;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18693);
    }
v_18679:
    v_18693 = nil;
    goto v_18588;
v_18590:
    v_18693 = nil;
v_18588:
    return onevalue(v_18693);
}



// Code for ofsf_ir2atl

static LispObject CC_ofsf_ir2atl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18696, v_18697, v_18698;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_ir2atl");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_18587;
    stack[0] = v_18586;
    stack[-5] = v_18585;
// end of prologue
    goto v_18594;
v_18590:
    v_18696 = stack[0];
    v_18697 = qcar(v_18696);
    goto v_18591;
v_18592:
    v_18696 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18593;
v_18594:
    goto v_18590;
v_18591:
    goto v_18592;
v_18593:
    v_18696 = cons(v_18697, v_18696);
    env = stack[-7];
    stack[-6] = v_18696;
    v_18696 = stack[0];
    v_18696 = qcdr(v_18696);
    stack[-3] = v_18696;
v_18604:
    v_18696 = stack[-3];
    if (v_18696 == nil) goto v_18610;
    else goto v_18611;
v_18610:
    v_18696 = nil;
    goto v_18603;
v_18611:
    v_18696 = stack[-3];
    v_18696 = qcar(v_18696);
    v_18697 = v_18696;
    goto v_18625;
v_18621:
    v_18696 = v_18697;
    v_18698 = qcar(v_18696);
    goto v_18622;
v_18623:
    v_18696 = stack[-4];
    goto v_18624;
v_18625:
    goto v_18621;
v_18622:
    goto v_18623;
v_18624:
    if (equal(v_18698, v_18696)) goto v_18619;
    else goto v_18620;
v_18619:
    goto v_18637;
v_18631:
    v_18698 = stack[-5];
    goto v_18632;
v_18633:
    v_18696 = v_18697;
    v_18697 = qcdr(v_18696);
    goto v_18634;
v_18635:
    v_18696 = stack[-6];
    goto v_18636;
v_18637:
    goto v_18631;
v_18632:
    goto v_18633;
v_18634:
    goto v_18635;
v_18636:
    fn = elt(env, 1); // ofsf_entry2at
    v_18696 = (*qfnn(fn))(fn, 3, v_18698, v_18697, v_18696);
    env = stack[-7];
    v_18696 = ncons(v_18696);
    env = stack[-7];
    goto v_18618;
v_18620:
    v_18696 = nil;
v_18618:
    stack[-2] = v_18696;
    v_18696 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_18696 = (*qfn1(fn))(fn, v_18696);
    env = stack[-7];
    stack[-1] = v_18696;
    v_18696 = stack[-3];
    v_18696 = qcdr(v_18696);
    stack[-3] = v_18696;
    v_18696 = stack[-1];
    if (!consp(v_18696)) goto v_18648;
    else goto v_18649;
v_18648:
    goto v_18604;
v_18649:
v_18605:
    v_18696 = stack[-3];
    if (v_18696 == nil) goto v_18653;
    else goto v_18654;
v_18653:
    v_18696 = stack[-2];
    goto v_18603;
v_18654:
    goto v_18662;
v_18658:
    stack[0] = stack[-1];
    goto v_18659;
v_18660:
    v_18696 = stack[-3];
    v_18696 = qcar(v_18696);
    v_18697 = v_18696;
    goto v_18675;
v_18671:
    v_18696 = v_18697;
    v_18698 = qcar(v_18696);
    goto v_18672;
v_18673:
    v_18696 = stack[-4];
    goto v_18674;
v_18675:
    goto v_18671;
v_18672:
    goto v_18673;
v_18674:
    if (equal(v_18698, v_18696)) goto v_18669;
    else goto v_18670;
v_18669:
    goto v_18687;
v_18681:
    v_18698 = stack[-5];
    goto v_18682;
v_18683:
    v_18696 = v_18697;
    v_18697 = qcdr(v_18696);
    goto v_18684;
v_18685:
    v_18696 = stack[-6];
    goto v_18686;
v_18687:
    goto v_18681;
v_18682:
    goto v_18683;
v_18684:
    goto v_18685;
v_18686:
    fn = elt(env, 1); // ofsf_entry2at
    v_18696 = (*qfnn(fn))(fn, 3, v_18698, v_18697, v_18696);
    env = stack[-7];
    v_18696 = ncons(v_18696);
    env = stack[-7];
    goto v_18668;
v_18670:
    v_18696 = nil;
v_18668:
    goto v_18661;
v_18662:
    goto v_18658;
v_18659:
    goto v_18660;
v_18661:
    v_18696 = Lrplacd(nil, stack[0], v_18696);
    env = stack[-7];
    v_18696 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_18696 = (*qfn1(fn))(fn, v_18696);
    env = stack[-7];
    stack[-1] = v_18696;
    v_18696 = stack[-3];
    v_18696 = qcdr(v_18696);
    stack[-3] = v_18696;
    goto v_18605;
v_18603:
    return onevalue(v_18696);
}



// Code for sortedpolynomlistinsert

static LispObject CC_sortedpolynomlistinsert(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18646, v_18647;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18586;
    v_18646 = v_18585;
// end of prologue
    stack[-2] = v_18646;
v_18594:
    v_18646 = stack[-2];
    v_18646 = qcar(v_18646);
    if (v_18646 == nil) goto v_18597;
    goto v_18607;
v_18603:
    goto v_18613;
v_18609:
    v_18646 = stack[-2];
    v_18647 = qcar(v_18646);
    goto v_18610;
v_18611:
    v_18646 = stack[-1];
    goto v_18612;
v_18613:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    fn = elt(env, 1); // polynomcompare
    v_18647 = (*qfn2(fn))(fn, v_18647, v_18646);
    env = stack[-3];
    goto v_18604;
v_18605:
    v_18646 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18606;
v_18607:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    if (v_18647 == v_18646) goto v_18597;
    goto v_18598;
v_18597:
    goto v_18593;
v_18598:
    v_18646 = stack[-2];
    v_18646 = qcdr(v_18646);
    stack[-2] = v_18646;
    goto v_18594;
v_18593:
    goto v_18627;
v_18623:
    goto v_18633;
v_18629:
    stack[0] = stack[-2];
    goto v_18630;
v_18631:
    goto v_18640;
v_18636:
    v_18646 = stack[-2];
    v_18647 = qcar(v_18646);
    goto v_18637;
v_18638:
    v_18646 = stack[-2];
    v_18646 = qcdr(v_18646);
    goto v_18639;
v_18640:
    goto v_18636;
v_18637:
    goto v_18638;
v_18639:
    v_18646 = cons(v_18647, v_18646);
    env = stack[-3];
    goto v_18632;
v_18633:
    goto v_18629;
v_18630:
    goto v_18631;
v_18632:
    v_18647 = Lrplacd(nil, stack[0], v_18646);
    env = stack[-3];
    goto v_18624;
v_18625:
    v_18646 = stack[-1];
    goto v_18626;
v_18627:
    goto v_18623;
v_18624:
    goto v_18625;
v_18626:
    v_18646 = Lrplaca(nil, v_18647, v_18646);
    v_18646 = nil;
    return onevalue(v_18646);
}



// Code for !*tayexp2q

static LispObject CC_Htayexp2q(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18613, v_18614;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
// copy arguments values to proper place
    v_18614 = v_18585;
// end of prologue
    v_18613 = v_18614;
    if (!consp(v_18613)) goto v_18589;
    else goto v_18590;
v_18589:
    goto v_18597;
v_18593:
    v_18613 = v_18614;
    v_18613 = (LispObject)zerop(v_18613);
    v_18613 = v_18613 ? lisp_true : nil;
    if (v_18613 == nil) goto v_18601;
    v_18613 = nil;
    v_18614 = v_18613;
    goto v_18599;
v_18601:
    v_18613 = v_18614;
    v_18614 = v_18613;
    goto v_18599;
    v_18614 = nil;
v_18599:
    goto v_18594;
v_18595:
    v_18613 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18596;
v_18597:
    goto v_18593;
v_18594:
    goto v_18595;
v_18596:
    return cons(v_18614, v_18613);
v_18590:
    v_18613 = v_18614;
    v_18613 = qcdr(v_18613);
    goto v_18588;
    v_18613 = nil;
v_18588:
    return onevalue(v_18613);
}



// Code for pasf_smwmkatl

static LispObject CC_pasf_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18625, v_18626, v_18627, v_18628, v_18629;
    LispObject fn;
    LispObject v_18588, v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smwmkatl");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    v_18588 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18626 = v_18588;
    v_18627 = v_18587;
    v_18628 = v_18586;
    v_18629 = v_18585;
// end of prologue
    v_18625 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_18625 == nil) goto v_18593;
    goto v_18604;
v_18596:
    v_18625 = v_18629;
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    goto v_18596;
v_18597:
    goto v_18598;
v_18599:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_18625, v_18628, v_18627, v_18626);
    }
v_18593:
    goto v_18620;
v_18612:
    v_18625 = v_18629;
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    {
        fn = elt(env, 3); // cl_smmkatl
        return (*qfnn(fn))(fn, 4, v_18625, v_18628, v_18627, v_18626);
    }
    v_18625 = nil;
    return onevalue(v_18625);
}



// Code for ev_2a

static LispObject CC_ev_2a(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18595, v_18596;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18595 = v_18585;
// end of prologue
    goto v_18592;
v_18588:
    v_18596 = v_18595;
    goto v_18589;
v_18590:
    v_18595 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_18591;
v_18592:
    goto v_18588;
v_18589:
    goto v_18590;
v_18591:
    {
        fn = elt(env, 2); // ev_2a1
        return (*qfn2(fn))(fn, v_18596, v_18595);
    }
}



// Code for applyfnrd

static LispObject CC_applyfnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18607, v_18608, v_18609;
    LispObject fn;
    argcheck(nargs, 0, "applyfnrd");
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
    fn = elt(env, 1); // fnrd
    v_18607 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_18607;
    fn = elt(env, 2); // stats_getargs
    v_18607 = (*qfnn(fn))(fn, 0);
    goto v_18603;
v_18597:
    v_18609 = stack[0];
    goto v_18598;
v_18599:
    v_18608 = nil;
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    return list2star(v_18609, v_18608, v_18607);
    return onevalue(v_18607);
}



// Code for lessppair

static LispObject CC_lessppair(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18623, v_18624, v_18625, v_18626;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18624 = v_18586;
    v_18625 = v_18585;
// end of prologue
    goto v_18596;
v_18592:
    v_18623 = v_18625;
    v_18626 = qcar(v_18623);
    goto v_18593;
v_18594:
    v_18623 = v_18624;
    v_18623 = qcar(v_18623);
    goto v_18595;
v_18596:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    if (equal(v_18626, v_18623)) goto v_18590;
    else goto v_18591;
v_18590:
    goto v_18606;
v_18602:
    v_18623 = v_18625;
    v_18623 = qcdr(v_18623);
    goto v_18603;
v_18604:
    v_18624 = qcdr(v_18624);
    goto v_18605;
v_18606:
    goto v_18602;
v_18603:
    goto v_18604;
v_18605:
        return Llessp(nil, v_18623, v_18624);
v_18591:
    goto v_18618;
v_18614:
    v_18623 = v_18625;
    v_18623 = qcar(v_18623);
    goto v_18615;
v_18616:
    v_18624 = qcar(v_18624);
    goto v_18617;
v_18618:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
        return Llessp(nil, v_18623, v_18624);
    v_18623 = nil;
    return onevalue(v_18623);
}



// Code for dipsimpcont

static LispObject CC_dipsimpcont(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18601, v_18602;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18602 = v_18585;
// end of prologue
    v_18601 = qvalue(elt(env, 1)); // !*vdpinteger
    if (v_18601 == nil) goto v_18591;
    else goto v_18589;
v_18591:
    v_18601 = qvalue(elt(env, 2)); // !*groebdivide
    if (v_18601 == nil) goto v_18589;
    goto v_18590;
v_18589:
    v_18601 = v_18602;
    {
        fn = elt(env, 3); // dipsimpconti
        return (*qfn1(fn))(fn, v_18601);
    }
v_18590:
    v_18601 = v_18602;
    {
        fn = elt(env, 4); // dipsimpcontr
        return (*qfn1(fn))(fn, v_18601);
    }
    v_18601 = nil;
    return onevalue(v_18601);
}



// Code for dipprodin

static LispObject CC_dipprodin(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18651, v_18652, v_18653;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_18586;
    stack[-1] = v_18585;
// end of prologue
    stack[-2] = nil;
v_18592:
    v_18651 = stack[-1];
    if (v_18651 == nil) goto v_18601;
    else goto v_18602;
v_18601:
    v_18651 = lisp_true;
    goto v_18600;
v_18602:
    v_18651 = stack[0];
    v_18651 = (v_18651 == nil ? lisp_true : nil);
    goto v_18600;
    v_18651 = nil;
v_18600:
    if (v_18651 == nil) goto v_18598;
    goto v_18593;
v_18598:
    goto v_18614;
v_18610:
    goto v_18622;
v_18616:
    v_18651 = stack[-1];
    v_18651 = qcdr(v_18651);
    v_18653 = qcar(v_18651);
    goto v_18617;
v_18618:
    v_18651 = stack[-1];
    v_18652 = qcar(v_18651);
    goto v_18619;
v_18620:
    v_18651 = stack[0];
    goto v_18621;
v_18622:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    goto v_18620;
v_18621:
    fn = elt(env, 2); // dipprodin1
    v_18652 = (*qfnn(fn))(fn, 3, v_18653, v_18652, v_18651);
    env = stack[-3];
    goto v_18611;
v_18612:
    v_18651 = stack[-2];
    goto v_18613;
v_18614:
    goto v_18610;
v_18611:
    goto v_18612;
v_18613:
    v_18651 = cons(v_18652, v_18651);
    env = stack[-3];
    stack[-2] = v_18651;
    v_18651 = stack[-1];
    v_18651 = qcdr(v_18651);
    v_18651 = qcdr(v_18651);
    stack[-1] = v_18651;
    goto v_18592;
v_18593:
    v_18651 = qvalue(elt(env, 1)); // dipzero
    v_18652 = v_18651;
v_18594:
    v_18651 = stack[-2];
    if (v_18651 == nil) goto v_18636;
    else goto v_18637;
v_18636:
    v_18651 = v_18652;
    goto v_18591;
v_18637:
    goto v_18645;
v_18641:
    v_18651 = stack[-2];
    v_18651 = qcar(v_18651);
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    goto v_18641;
v_18642:
    goto v_18643;
v_18644:
    fn = elt(env, 3); // dipsum
    v_18651 = (*qfn2(fn))(fn, v_18651, v_18652);
    env = stack[-3];
    v_18652 = v_18651;
    v_18651 = stack[-2];
    v_18651 = qcdr(v_18651);
    stack[-2] = v_18651;
    goto v_18594;
v_18591:
    return onevalue(v_18651);
}



// Code for difference!:

static LispObject CC_differenceT(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18723, v_18724, v_18725, v_18726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18725 = v_18586;
    v_18726 = v_18585;
// end of prologue
    goto v_18603;
v_18599:
    v_18723 = v_18726;
    v_18723 = qcdr(v_18723);
    v_18724 = qcar(v_18723);
    stack[-1] = v_18724;
    goto v_18600;
v_18601:
    v_18723 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18602;
v_18603:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    if (v_18724 == v_18723) goto v_18597;
    else goto v_18598;
v_18597:
    v_18723 = v_18725;
    {
        fn = elt(env, 2); // minus!:
        return (*qfn1(fn))(fn, v_18723);
    }
v_18598:
    goto v_18616;
v_18612:
    v_18723 = v_18725;
    v_18723 = qcdr(v_18723);
    v_18724 = qcar(v_18723);
    stack[0] = v_18724;
    goto v_18613;
v_18614:
    v_18723 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18615;
v_18616:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    if (v_18724 == v_18723) goto v_18610;
    else goto v_18611;
v_18610:
    v_18723 = v_18726;
    goto v_18596;
v_18611:
    goto v_18628;
v_18624:
    goto v_18634;
v_18630:
    v_18723 = v_18726;
    v_18723 = qcdr(v_18723);
    v_18723 = qcdr(v_18723);
    stack[-4] = v_18723;
    goto v_18631;
v_18632:
    v_18724 = v_18725;
    v_18724 = qcdr(v_18724);
    v_18724 = qcdr(v_18724);
    stack[-2] = v_18724;
    goto v_18633;
v_18634:
    goto v_18630;
v_18631:
    goto v_18632;
v_18633:
    v_18724 = difference2(v_18723, v_18724);
    env = stack[-5];
    stack[-3] = v_18724;
    goto v_18625;
v_18626:
    v_18723 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18627;
v_18628:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    if (v_18724 == v_18723) goto v_18622;
    else goto v_18623;
v_18622:
    goto v_18649;
v_18643:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_18644;
v_18645:
    goto v_18656;
v_18652:
    v_18724 = stack[-1];
    goto v_18653;
v_18654:
    v_18723 = stack[0];
    goto v_18655;
v_18656:
    goto v_18652;
v_18653:
    goto v_18654;
v_18655:
    v_18724 = difference2(v_18724, v_18723);
    goto v_18646;
v_18647:
    v_18723 = stack[-4];
    goto v_18648;
v_18649:
    goto v_18643;
v_18644:
    goto v_18645;
v_18646:
    goto v_18647;
v_18648:
    {
        LispObject v_18732 = stack[-2];
        return list2star(v_18732, v_18724, v_18723);
    }
v_18623:
    goto v_18667;
v_18663:
    v_18724 = stack[-3];
    goto v_18664;
v_18665:
    v_18723 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18666;
v_18667:
    goto v_18663;
v_18664:
    goto v_18665;
v_18666:
    v_18723 = (LispObject)greaterp2(v_18724, v_18723);
    v_18723 = v_18723 ? lisp_true : nil;
    env = stack[-5];
    if (v_18723 == nil) goto v_18661;
    goto v_18677;
v_18671:
    stack[-4] = elt(env, 1); // !:rd!:
    goto v_18672;
v_18673:
    goto v_18684;
v_18680:
    goto v_18690;
v_18686:
    v_18724 = stack[-1];
    goto v_18687;
v_18688:
    v_18723 = stack[-3];
    goto v_18689;
v_18690:
    goto v_18686;
v_18687:
    goto v_18688;
v_18689:
    fn = elt(env, 3); // ashift
    v_18724 = (*qfn2(fn))(fn, v_18724, v_18723);
    env = stack[-5];
    goto v_18681;
v_18682:
    v_18723 = stack[0];
    goto v_18683;
v_18684:
    goto v_18680;
v_18681:
    goto v_18682;
v_18683:
    v_18724 = difference2(v_18724, v_18723);
    goto v_18674;
v_18675:
    v_18723 = stack[-2];
    goto v_18676;
v_18677:
    goto v_18671;
v_18672:
    goto v_18673;
v_18674:
    goto v_18675;
v_18676:
    {
        LispObject v_18733 = stack[-4];
        return list2star(v_18733, v_18724, v_18723);
    }
v_18661:
    goto v_18704;
v_18698:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_18699;
v_18700:
    goto v_18711;
v_18707:
    goto v_18708;
v_18709:
    goto v_18718;
v_18714:
    goto v_18715;
v_18716:
    v_18723 = stack[-3];
    v_18723 = negate(v_18723);
    env = stack[-5];
    goto v_18717;
v_18718:
    goto v_18714;
v_18715:
    goto v_18716;
v_18717:
    fn = elt(env, 3); // ashift
    v_18723 = (*qfn2(fn))(fn, stack[0], v_18723);
    env = stack[-5];
    goto v_18710;
v_18711:
    goto v_18707;
v_18708:
    goto v_18709;
v_18710:
    v_18724 = difference2(stack[-1], v_18723);
    goto v_18701;
v_18702:
    v_18723 = stack[-4];
    goto v_18703;
v_18704:
    goto v_18698;
v_18699:
    goto v_18700;
v_18701:
    goto v_18702;
v_18703:
    {
        LispObject v_18734 = stack[-2];
        return list2star(v_18734, v_18724, v_18723);
    }
    v_18723 = nil;
v_18596:
    return onevalue(v_18723);
}



// Code for find_buble

static LispObject CC_find_buble(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18617, v_18618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18586;
    stack[-1] = v_18585;
// end of prologue
v_18584:
    v_18617 = stack[0];
    if (v_18617 == nil) goto v_18590;
    else goto v_18591;
v_18590:
    v_18617 = nil;
    goto v_18589;
v_18591:
    goto v_18604;
v_18600:
    v_18618 = stack[-1];
    goto v_18601;
v_18602:
    v_18617 = stack[0];
    v_18617 = qcar(v_18617);
    goto v_18603;
v_18604:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    fn = elt(env, 1); // is_buble
    v_18617 = (*qfn2(fn))(fn, v_18618, v_18617);
    env = stack[-2];
    if (v_18617 == nil) goto v_18598;
    else goto v_18597;
v_18598:
    goto v_18613;
v_18609:
    v_18618 = stack[-1];
    goto v_18610;
v_18611:
    v_18617 = stack[0];
    v_18617 = qcdr(v_18617);
    goto v_18612;
v_18613:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    stack[-1] = v_18618;
    stack[0] = v_18617;
    goto v_18584;
v_18597:
    goto v_18589;
    v_18617 = nil;
v_18589:
    return onevalue(v_18617);
}



// Code for remchkf

static LispObject CC_remchkf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18653, v_18654, v_18655;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "remchkf");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18587;
    stack[-1] = v_18586;
    stack[-2] = v_18585;
// end of prologue
    goto v_18594;
v_18590:
    v_18654 = stack[-2];
    goto v_18591;
v_18592:
    v_18653 = stack[-1];
    goto v_18593;
v_18594:
    goto v_18590;
v_18591:
    goto v_18592;
v_18593:
    fn = elt(env, 1); // remchkf1
    v_18653 = (*qfn2(fn))(fn, v_18654, v_18653);
    env = stack[-4];
    stack[-3] = v_18653;
    v_18653 = stack[-3];
    if (!consp(v_18653)) goto v_18608;
    else goto v_18609;
v_18608:
    v_18653 = lisp_true;
    goto v_18607;
v_18609:
    v_18653 = stack[-3];
    v_18653 = qcar(v_18653);
    v_18653 = (consp(v_18653) ? nil : lisp_true);
    goto v_18607;
    v_18653 = nil;
v_18607:
    if (v_18653 == nil) goto v_18605;
    v_18653 = lisp_true;
    goto v_18603;
v_18605:
    goto v_18625;
v_18621:
    v_18653 = stack[-2];
    fn = elt(env, 2); // kernels
    v_18654 = (*qfn1(fn))(fn, v_18653);
    env = stack[-4];
    goto v_18622;
v_18623:
    v_18653 = stack[0];
    goto v_18624;
v_18625:
    goto v_18621;
v_18622:
    goto v_18623;
v_18624:
    fn = elt(env, 3); // intersection
    v_18653 = (*qfn2(fn))(fn, v_18654, v_18653);
    env = stack[-4];
    v_18653 = (v_18653 == nil ? lisp_true : nil);
    goto v_18603;
    v_18653 = nil;
v_18603:
    if (v_18653 == nil) goto v_18601;
    v_18653 = stack[-3];
    goto v_18599;
v_18601:
    goto v_18638;
v_18634:
    v_18653 = stack[-3];
    stack[-2] = qcar(v_18653);
    goto v_18635;
v_18636:
    goto v_18648;
v_18642:
    v_18653 = stack[-3];
    v_18655 = qcdr(v_18653);
    goto v_18643;
v_18644:
    v_18654 = stack[-1];
    goto v_18645;
v_18646:
    v_18653 = stack[0];
    goto v_18647;
v_18648:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    goto v_18646;
v_18647:
    v_18653 = CC_remchkf(elt(env, 0), 3, v_18655, v_18654, v_18653);
    goto v_18637;
v_18638:
    goto v_18634;
v_18635:
    goto v_18636;
v_18637:
    {
        LispObject v_18660 = stack[-2];
        return cons(v_18660, v_18653);
    }
    v_18653 = nil;
v_18599:
    return onevalue(v_18653);
}



// Code for ad_splitname

static LispObject CC_ad_splitname(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18649, v_18650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18650 = v_18585;
// end of prologue
    v_18649 = v_18650;
    if (symbolp(v_18649)) goto v_18589;
    else goto v_18590;
v_18589:
    stack[0] = nil;
    v_18649 = v_18650;
    v_18649 = Lexplode(nil, v_18649);
    env = stack[-2];
    v_18649 = Lreverse(nil, v_18649);
    env = stack[-2];
    stack[-1] = v_18649;
v_18601:
    v_18649 = stack[-1];
    if (v_18649 == nil) goto v_18604;
    v_18649 = stack[-1];
    v_18649 = qcar(v_18649);
    fn = elt(env, 1); // charnump!:
    v_18649 = (*qfn1(fn))(fn, v_18649);
    env = stack[-2];
    if (v_18649 == nil) goto v_18604;
    goto v_18605;
v_18604:
    goto v_18600;
v_18605:
    goto v_18618;
v_18614:
    v_18649 = stack[-1];
    v_18650 = qcar(v_18649);
    goto v_18615;
v_18616:
    v_18649 = stack[0];
    goto v_18617;
v_18618:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    v_18649 = cons(v_18650, v_18649);
    env = stack[-2];
    stack[0] = v_18649;
    v_18649 = stack[-1];
    v_18649 = qcdr(v_18649);
    stack[-1] = v_18649;
    goto v_18601;
v_18600:
    v_18649 = stack[-1];
    if (v_18649 == nil) goto v_18628;
    v_18649 = stack[-1];
    v_18649 = Lreverse(nil, v_18649);
    env = stack[-2];
    v_18649 = Lcompress(nil, v_18649);
    env = stack[-2];
    v_18649 = Lintern(nil, v_18649);
    env = stack[-2];
    stack[-1] = v_18649;
    goto v_18626;
v_18628:
v_18626:
    v_18649 = stack[0];
    if (v_18649 == nil) goto v_18637;
    v_18649 = stack[0];
    v_18649 = Lcompress(nil, v_18649);
    stack[0] = v_18649;
    goto v_18635;
v_18637:
v_18635:
    goto v_18646;
v_18642:
    v_18650 = stack[-1];
    goto v_18643;
v_18644:
    v_18649 = stack[0];
    goto v_18645;
v_18646:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    return cons(v_18650, v_18649);
    goto v_18588;
v_18590:
    v_18649 = nil;
v_18588:
    return onevalue(v_18649);
}



// Code for find!-null!-space

static LispObject CC_findKnullKspace(LispObject env,
                         LispObject v_18585, LispObject v_18586)
{
    env = qenv(env);
    LispObject v_18637, v_18638, v_18639, v_18640;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18585,v_18586);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18586;
    stack[-2] = v_18585;
// end of prologue
// Binding null!-space!-basis
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // null!-space!-basis
    v_18637 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18637;
v_18594:
    goto v_18604;
v_18600:
    v_18638 = stack[-1];
    goto v_18601;
v_18602:
    v_18637 = stack[0];
    goto v_18603;
v_18604:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    v_18637 = (LispObject)(intptr_t)((intptr_t)v_18638 - (intptr_t)v_18637 + TAG_FIXNUM);
    v_18637 = ((intptr_t)(v_18637) < 0 ? lisp_true : nil);
    if (v_18637 == nil) goto v_18599;
    goto v_18593;
v_18599:
    goto v_18619;
v_18611:
    v_18640 = stack[0];
    goto v_18612;
v_18613:
    v_18639 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v_18614;
v_18615:
    v_18638 = stack[-2];
    goto v_18616;
v_18617:
    v_18637 = stack[-1];
    goto v_18618;
v_18619:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    goto v_18615;
v_18616:
    goto v_18617;
v_18618:
    fn = elt(env, 2); // clear!-column
    v_18637 = (*qfnn(fn))(fn, 4, v_18640, v_18639, v_18638, v_18637);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_18637; // null!-space!-basis
    v_18637 = stack[0];
    v_18637 = (LispObject)((intptr_t)(v_18637) + 0x10);
    stack[0] = v_18637;
    goto v_18594;
v_18593:
    goto v_18633;
v_18627:
    v_18639 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v_18628;
v_18629:
    v_18638 = stack[-2];
    goto v_18630;
v_18631:
    v_18637 = stack[-1];
    goto v_18632;
v_18633:
    goto v_18627;
v_18628:
    goto v_18629;
v_18630:
    goto v_18631;
v_18632:
    fn = elt(env, 3); // tidy!-up!-null!-vectors
    v_18637 = (*qfnn(fn))(fn, 3, v_18639, v_18638, v_18637);
    ;}  // end of a binding scope
    return onevalue(v_18637);
}



// Code for rl_transform

static LispObject CC_rl_transform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18627, v_18628, v_18629, v_18630, v_18631, v_18632, v_18633;
    LispObject fn;
    LispObject v_18591, v_18590, v_18589, v_18588, v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "rl_transform");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    v_18588 = va_arg(aa, LispObject);
    v_18589 = va_arg(aa, LispObject);
    v_18590 = va_arg(aa, LispObject);
    v_18591 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_18591,v_18590,v_18589,v_18588,v_18587,v_18586);
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_18585,v_18586,v_18587,v_18588,v_18589,v_18590);
        pop(v_18591);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_18627 = v_18591;
    v_18628 = v_18590;
    v_18629 = v_18589;
    v_18630 = v_18588;
    v_18631 = v_18587;
    v_18632 = v_18586;
    v_18633 = v_18585;
// end of prologue
    goto v_18598;
v_18594:
    stack[-3] = qvalue(elt(env, 1)); // rl_transform!*
    goto v_18595;
v_18596:
    goto v_18609;
v_18601:
    stack[-2] = v_18633;
    goto v_18602;
v_18603:
    stack[-1] = v_18632;
    goto v_18604;
v_18605:
    stack[0] = v_18631;
    goto v_18606;
v_18607:
    goto v_18622;
v_18614:
    goto v_18615;
v_18616:
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    goto v_18621;
v_18622:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    goto v_18620;
v_18621:
    v_18627 = list4(v_18630, v_18629, v_18628, v_18627);
    env = stack[-4];
    goto v_18608;
v_18609:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    goto v_18607;
v_18608:
    v_18627 = list3star(stack[-2], stack[-1], stack[0], v_18627);
    env = stack[-4];
    goto v_18597;
v_18598:
    goto v_18594;
v_18595:
    goto v_18596;
v_18597:
    {
        LispObject v_18638 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_18638, v_18627);
    }
}



// Code for polynomwrite

static LispObject CC_polynomwrite(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18638, v_18639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18585;
// end of prologue
    stack[-1] = nil;
v_18590:
    v_18638 = stack[0];
    v_18638 = qcar(v_18638);
    if (v_18638 == nil) goto v_18593;
    else goto v_18594;
v_18593:
    v_18638 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18638);
    }
v_18594:
    goto v_18605;
v_18601:
    goto v_18610;
v_18606:
    v_18638 = stack[0];
    v_18639 = qcar(v_18638);
    goto v_18607;
v_18608:
    v_18638 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18609;
v_18610:
    goto v_18606;
v_18607:
    goto v_18608;
v_18609:
    v_18639 = *(LispObject *)((char *)v_18639 + (CELL-TAG_VECTOR) + (((intptr_t)v_18638-TAG_FIXNUM)/(16/CELL)));
    goto v_18602;
v_18603:
    v_18638 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18604;
v_18605:
    goto v_18601;
v_18602:
    goto v_18603;
v_18604:
    if (v_18639 == v_18638) goto v_18599;
    else goto v_18600;
v_18599:
    goto v_18621;
v_18617:
    v_18639 = stack[-1];
    goto v_18618;
v_18619:
    v_18638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18620;
v_18621:
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_18639, v_18638);
    }
v_18600:
    goto v_18631;
v_18627:
    v_18638 = stack[0];
    v_18638 = qcar(v_18638);
    fn = elt(env, 2); // monomwrite
    v_18639 = (*qfn1(fn))(fn, v_18638);
    env = stack[-2];
    goto v_18628;
v_18629:
    v_18638 = stack[-1];
    goto v_18630;
v_18631:
    goto v_18627;
v_18628:
    goto v_18629;
v_18630:
    v_18638 = cons(v_18639, v_18638);
    env = stack[-2];
    stack[-1] = v_18638;
    v_18638 = stack[0];
    v_18638 = qcdr(v_18638);
    stack[0] = v_18638;
    goto v_18590;
    v_18638 = nil;
    return onevalue(v_18638);
}



// Code for cl_apply2ats1

static LispObject CC_cl_apply2ats1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18917, v_18918, v_18919;
    LispObject fn;
    LispObject v_18587, v_18586, v_18585;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_apply2ats1");
    va_start(aa, nargs);
    v_18585 = va_arg(aa, LispObject);
    v_18586 = va_arg(aa, LispObject);
    v_18587 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18587,v_18586,v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18585,v_18586,v_18587);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_18587;
    stack[-5] = v_18586;
    stack[-1] = v_18585;
// end of prologue
    v_18917 = stack[-1];
    if (!consp(v_18917)) goto v_18594;
    else goto v_18595;
v_18594:
    v_18917 = stack[-1];
    goto v_18593;
v_18595:
    v_18917 = stack[-1];
    v_18917 = qcar(v_18917);
    goto v_18593;
    v_18917 = nil;
v_18593:
    v_18919 = v_18917;
    goto v_18614;
v_18610:
    v_18918 = v_18919;
    goto v_18611;
v_18612:
    v_18917 = elt(env, 1); // true
    goto v_18613;
v_18614:
    goto v_18610;
v_18611:
    goto v_18612;
v_18613:
    if (v_18918 == v_18917) goto v_18608;
    else goto v_18609;
v_18608:
    v_18917 = lisp_true;
    goto v_18607;
v_18609:
    goto v_18624;
v_18620:
    v_18918 = v_18919;
    goto v_18621;
v_18622:
    v_18917 = elt(env, 2); // false
    goto v_18623;
v_18624:
    goto v_18620;
v_18621:
    goto v_18622;
v_18623:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18607;
    v_18917 = nil;
v_18607:
    if (v_18917 == nil) goto v_18605;
    v_18917 = stack[-1];
    goto v_18591;
v_18605:
    goto v_18641;
v_18637:
    v_18918 = v_18919;
    goto v_18638;
v_18639:
    v_18917 = elt(env, 3); // ex
    goto v_18640;
v_18641:
    goto v_18637;
v_18638:
    goto v_18639;
v_18640:
    if (v_18918 == v_18917) goto v_18635;
    else goto v_18636;
v_18635:
    v_18917 = lisp_true;
    goto v_18634;
v_18636:
    goto v_18651;
v_18647:
    v_18918 = v_18919;
    goto v_18648;
v_18649:
    v_18917 = elt(env, 4); // all
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18634;
    v_18917 = nil;
v_18634:
    if (v_18917 == nil) goto v_18632;
    goto v_18662;
v_18656:
    stack[-2] = v_18919;
    goto v_18657;
v_18658:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    stack[0] = qcar(v_18917);
    goto v_18659;
v_18660:
    goto v_18674;
v_18668:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    v_18917 = qcdr(v_18917);
    v_18919 = qcar(v_18917);
    goto v_18669;
v_18670:
    v_18918 = stack[-5];
    goto v_18671;
v_18672:
    v_18917 = stack[-4];
    goto v_18673;
v_18674:
    goto v_18668;
v_18669:
    goto v_18670;
v_18671:
    goto v_18672;
v_18673:
    v_18917 = CC_cl_apply2ats1(elt(env, 0), 3, v_18919, v_18918, v_18917);
    goto v_18661;
v_18662:
    goto v_18656;
v_18657:
    goto v_18658;
v_18659:
    goto v_18660;
v_18661:
    {
        LispObject v_18927 = stack[-2];
        LispObject v_18928 = stack[0];
        return list3(v_18927, v_18928, v_18917);
    }
v_18632:
    goto v_18693;
v_18689:
    v_18918 = v_18919;
    goto v_18690;
v_18691:
    v_18917 = elt(env, 5); // bex
    goto v_18692;
v_18693:
    goto v_18689;
v_18690:
    goto v_18691;
v_18692:
    if (v_18918 == v_18917) goto v_18687;
    else goto v_18688;
v_18687:
    v_18917 = lisp_true;
    goto v_18686;
v_18688:
    goto v_18703;
v_18699:
    v_18918 = v_18919;
    goto v_18700;
v_18701:
    v_18917 = elt(env, 6); // ball
    goto v_18702;
v_18703:
    goto v_18699;
v_18700:
    goto v_18701;
v_18702:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18686;
    v_18917 = nil;
v_18686:
    if (v_18917 == nil) goto v_18684;
    goto v_18716;
v_18708:
    stack[-3] = v_18919;
    goto v_18709;
v_18710:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    stack[-2] = qcar(v_18917);
    goto v_18711;
v_18712:
    goto v_18728;
v_18722:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    v_18917 = qcdr(v_18917);
    v_18919 = qcar(v_18917);
    goto v_18723;
v_18724:
    v_18918 = stack[-5];
    goto v_18725;
v_18726:
    v_18917 = stack[-4];
    goto v_18727;
v_18728:
    goto v_18722;
v_18723:
    goto v_18724;
v_18725:
    goto v_18726;
v_18727:
    stack[0] = CC_cl_apply2ats1(elt(env, 0), 3, v_18919, v_18918, v_18917);
    env = stack[-7];
    goto v_18713;
v_18714:
    goto v_18742;
v_18736:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    v_18917 = qcdr(v_18917);
    v_18917 = qcdr(v_18917);
    v_18919 = qcar(v_18917);
    goto v_18737;
v_18738:
    v_18918 = stack[-5];
    goto v_18739;
v_18740:
    v_18917 = stack[-4];
    goto v_18741;
v_18742:
    goto v_18736;
v_18737:
    goto v_18738;
v_18739:
    goto v_18740;
v_18741:
    v_18917 = CC_cl_apply2ats1(elt(env, 0), 3, v_18919, v_18918, v_18917);
    goto v_18715;
v_18716:
    goto v_18708;
v_18709:
    goto v_18710;
v_18711:
    goto v_18712;
v_18713:
    goto v_18714;
v_18715:
    {
        LispObject v_18929 = stack[-3];
        LispObject v_18930 = stack[-2];
        LispObject v_18931 = stack[0];
        return list4(v_18929, v_18930, v_18931, v_18917);
    }
v_18684:
    goto v_18770;
v_18766:
    v_18918 = v_18919;
    goto v_18767;
v_18768:
    v_18917 = elt(env, 7); // or
    goto v_18769;
v_18770:
    goto v_18766;
v_18767:
    goto v_18768;
v_18769:
    if (v_18918 == v_18917) goto v_18764;
    else goto v_18765;
v_18764:
    v_18917 = lisp_true;
    goto v_18763;
v_18765:
    goto v_18780;
v_18776:
    v_18918 = v_18919;
    goto v_18777;
v_18778:
    v_18917 = elt(env, 8); // and
    goto v_18779;
v_18780:
    goto v_18776;
v_18777:
    goto v_18778;
v_18779:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18763;
    v_18917 = nil;
v_18763:
    if (v_18917 == nil) goto v_18761;
    v_18917 = lisp_true;
    goto v_18759;
v_18761:
    goto v_18791;
v_18787:
    v_18918 = v_18919;
    goto v_18788;
v_18789:
    v_18917 = elt(env, 9); // not
    goto v_18790;
v_18791:
    goto v_18787;
v_18788:
    goto v_18789;
v_18790:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18759;
    v_18917 = nil;
v_18759:
    if (v_18917 == nil) goto v_18757;
    v_18917 = lisp_true;
    goto v_18755;
v_18757:
    goto v_18806;
v_18802:
    v_18918 = v_18919;
    goto v_18803;
v_18804:
    v_18917 = elt(env, 10); // impl
    goto v_18805;
v_18806:
    goto v_18802;
v_18803:
    goto v_18804;
v_18805:
    if (v_18918 == v_18917) goto v_18800;
    else goto v_18801;
v_18800:
    v_18917 = lisp_true;
    goto v_18799;
v_18801:
    goto v_18820;
v_18816:
    v_18918 = v_18919;
    goto v_18817;
v_18818:
    v_18917 = elt(env, 11); // repl
    goto v_18819;
v_18820:
    goto v_18816;
v_18817:
    goto v_18818;
v_18819:
    if (v_18918 == v_18917) goto v_18814;
    else goto v_18815;
v_18814:
    v_18917 = lisp_true;
    goto v_18813;
v_18815:
    goto v_18830;
v_18826:
    v_18918 = v_18919;
    goto v_18827;
v_18828:
    v_18917 = elt(env, 12); // equiv
    goto v_18829;
v_18830:
    goto v_18826;
v_18827:
    goto v_18828;
v_18829:
    v_18917 = (v_18918 == v_18917 ? lisp_true : nil);
    goto v_18813;
    v_18917 = nil;
v_18813:
    goto v_18799;
    v_18917 = nil;
v_18799:
    goto v_18755;
    v_18917 = nil;
v_18755:
    if (v_18917 == nil) goto v_18753;
    goto v_18839;
v_18835:
    stack[-6] = v_18919;
    goto v_18836;
v_18837:
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    stack[-3] = v_18917;
    v_18917 = stack[-3];
    if (v_18917 == nil) goto v_18851;
    else goto v_18852;
v_18851:
    v_18917 = nil;
    goto v_18845;
v_18852:
    v_18917 = stack[-3];
    v_18917 = qcar(v_18917);
    goto v_18866;
v_18860:
    v_18919 = v_18917;
    goto v_18861;
v_18862:
    v_18918 = stack[-5];
    goto v_18863;
v_18864:
    v_18917 = stack[-4];
    goto v_18865;
v_18866:
    goto v_18860;
v_18861:
    goto v_18862;
v_18863:
    goto v_18864;
v_18865:
    v_18917 = CC_cl_apply2ats1(elt(env, 0), 3, v_18919, v_18918, v_18917);
    env = stack[-7];
    v_18917 = ncons(v_18917);
    env = stack[-7];
    stack[-1] = v_18917;
    stack[-2] = v_18917;
v_18846:
    v_18917 = stack[-3];
    v_18917 = qcdr(v_18917);
    stack[-3] = v_18917;
    v_18917 = stack[-3];
    if (v_18917 == nil) goto v_18874;
    else goto v_18875;
v_18874:
    v_18917 = stack[-2];
    goto v_18845;
v_18875:
    goto v_18883;
v_18879:
    stack[0] = stack[-1];
    goto v_18880;
v_18881:
    v_18917 = stack[-3];
    v_18917 = qcar(v_18917);
    goto v_18896;
v_18890:
    v_18919 = v_18917;
    goto v_18891;
v_18892:
    v_18918 = stack[-5];
    goto v_18893;
v_18894:
    v_18917 = stack[-4];
    goto v_18895;
v_18896:
    goto v_18890;
v_18891:
    goto v_18892;
v_18893:
    goto v_18894;
v_18895:
    v_18917 = CC_cl_apply2ats1(elt(env, 0), 3, v_18919, v_18918, v_18917);
    env = stack[-7];
    v_18917 = ncons(v_18917);
    env = stack[-7];
    goto v_18882;
v_18883:
    goto v_18879;
v_18880:
    goto v_18881;
v_18882:
    v_18917 = Lrplacd(nil, stack[0], v_18917);
    env = stack[-7];
    v_18917 = stack[-1];
    v_18917 = qcdr(v_18917);
    stack[-1] = v_18917;
    goto v_18846;
v_18845:
    goto v_18838;
v_18839:
    goto v_18835;
v_18836:
    goto v_18837;
v_18838:
    {
        LispObject v_18932 = stack[-6];
        return cons(v_18932, v_18917);
    }
v_18753:
    goto v_18907;
v_18903:
    stack[0] = stack[-5];
    goto v_18904;
v_18905:
    goto v_18914;
v_18910:
    v_18918 = stack[-1];
    goto v_18911;
v_18912:
    v_18917 = stack[-4];
    goto v_18913;
v_18914:
    goto v_18910;
v_18911:
    goto v_18912;
v_18913:
    v_18917 = cons(v_18918, v_18917);
    env = stack[-7];
    goto v_18906;
v_18907:
    goto v_18903;
v_18904:
    goto v_18905;
v_18906:
    {
        LispObject v_18933 = stack[0];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_18933, v_18917);
    }
v_18591:
    return onevalue(v_18917);
}



// Code for gen!+can!+bas

static LispObject CC_genLcanLbas(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18815, v_18816;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_18585;
// end of prologue
    goto v_18599;
v_18595:
    v_18816 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18596;
v_18597:
    v_18815 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18598;
v_18599:
    goto v_18595;
v_18596:
    goto v_18597;
v_18598:
    v_18815 = cons(v_18816, v_18815);
    env = stack[-11];
    stack[-10] = v_18815;
    goto v_18607;
v_18603:
    v_18816 = nil;
    goto v_18604;
v_18605:
    v_18815 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18606;
v_18607:
    goto v_18603;
v_18604:
    goto v_18605;
v_18606:
    v_18815 = cons(v_18816, v_18815);
    env = stack[-11];
    stack[-8] = v_18815;
    v_18815 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_18815;
    goto v_18627;
v_18623:
    v_18816 = stack[-9];
    goto v_18624;
v_18625:
    v_18815 = stack[-7];
    goto v_18626;
v_18627:
    goto v_18623;
v_18624:
    goto v_18625;
v_18626:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18620;
    v_18815 = nil;
    goto v_18614;
v_18620:
    v_18815 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_18815;
    goto v_18649;
v_18645:
    v_18816 = stack[-9];
    goto v_18646;
v_18647:
    v_18815 = stack[-3];
    goto v_18648;
v_18649:
    goto v_18645;
v_18646:
    goto v_18647;
v_18648:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18642;
    v_18815 = nil;
    goto v_18636;
v_18642:
    goto v_18662;
v_18658:
    v_18816 = stack[-7];
    goto v_18659;
v_18660:
    v_18815 = stack[-3];
    goto v_18661;
v_18662:
    goto v_18658;
v_18659:
    goto v_18660;
v_18661:
    if (equal(v_18816, v_18815)) goto v_18656;
    else goto v_18657;
v_18656:
    v_18815 = stack[-10];
    goto v_18655;
v_18657:
    v_18815 = stack[-8];
    goto v_18655;
    v_18815 = nil;
v_18655:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    stack[-1] = v_18815;
    stack[-2] = v_18815;
v_18637:
    v_18815 = stack[-3];
    v_18815 = add1(v_18815);
    env = stack[-11];
    stack[-3] = v_18815;
    goto v_18681;
v_18677:
    v_18816 = stack[-9];
    goto v_18678;
v_18679:
    v_18815 = stack[-3];
    goto v_18680;
v_18681:
    goto v_18677;
v_18678:
    goto v_18679;
v_18680:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18674;
    v_18815 = stack[-2];
    goto v_18636;
v_18674:
    goto v_18690;
v_18686:
    stack[0] = stack[-1];
    goto v_18687;
v_18688:
    goto v_18701;
v_18697:
    v_18816 = stack[-7];
    goto v_18698;
v_18699:
    v_18815 = stack[-3];
    goto v_18700;
v_18701:
    goto v_18697;
v_18698:
    goto v_18699;
v_18700:
    if (equal(v_18816, v_18815)) goto v_18695;
    else goto v_18696;
v_18695:
    v_18815 = stack[-10];
    goto v_18694;
v_18696:
    v_18815 = stack[-8];
    goto v_18694;
    v_18815 = nil;
v_18694:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    goto v_18689;
v_18690:
    goto v_18686;
v_18687:
    goto v_18688;
v_18689:
    v_18815 = Lrplacd(nil, stack[0], v_18815);
    env = stack[-11];
    v_18815 = stack[-1];
    v_18815 = qcdr(v_18815);
    stack[-1] = v_18815;
    goto v_18637;
v_18636:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    stack[-5] = v_18815;
    stack[-6] = v_18815;
v_18615:
    v_18815 = stack[-7];
    v_18815 = add1(v_18815);
    env = stack[-11];
    stack[-7] = v_18815;
    goto v_18722;
v_18718:
    v_18816 = stack[-9];
    goto v_18719;
v_18720:
    v_18815 = stack[-7];
    goto v_18721;
v_18722:
    goto v_18718;
v_18719:
    goto v_18720;
v_18721:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18715;
    v_18815 = stack[-6];
    goto v_18614;
v_18715:
    goto v_18731;
v_18727:
    stack[-4] = stack[-5];
    goto v_18728;
v_18729:
    v_18815 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_18815;
    goto v_18751;
v_18747:
    v_18816 = stack[-9];
    goto v_18748;
v_18749:
    v_18815 = stack[-3];
    goto v_18750;
v_18751:
    goto v_18747;
v_18748:
    goto v_18749;
v_18750:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18744;
    v_18815 = nil;
    goto v_18738;
v_18744:
    goto v_18764;
v_18760:
    v_18816 = stack[-7];
    goto v_18761;
v_18762:
    v_18815 = stack[-3];
    goto v_18763;
v_18764:
    goto v_18760;
v_18761:
    goto v_18762;
v_18763:
    if (equal(v_18816, v_18815)) goto v_18758;
    else goto v_18759;
v_18758:
    v_18815 = stack[-10];
    goto v_18757;
v_18759:
    v_18815 = stack[-8];
    goto v_18757;
    v_18815 = nil;
v_18757:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    stack[-1] = v_18815;
    stack[-2] = v_18815;
v_18739:
    v_18815 = stack[-3];
    v_18815 = add1(v_18815);
    env = stack[-11];
    stack[-3] = v_18815;
    goto v_18783;
v_18779:
    v_18816 = stack[-9];
    goto v_18780;
v_18781:
    v_18815 = stack[-3];
    goto v_18782;
v_18783:
    goto v_18779;
v_18780:
    goto v_18781;
v_18782:
    v_18815 = difference2(v_18816, v_18815);
    env = stack[-11];
    v_18815 = Lminusp(nil, v_18815);
    env = stack[-11];
    if (v_18815 == nil) goto v_18776;
    v_18815 = stack[-2];
    goto v_18738;
v_18776:
    goto v_18792;
v_18788:
    stack[0] = stack[-1];
    goto v_18789;
v_18790:
    goto v_18803;
v_18799:
    v_18816 = stack[-7];
    goto v_18800;
v_18801:
    v_18815 = stack[-3];
    goto v_18802;
v_18803:
    goto v_18799;
v_18800:
    goto v_18801;
v_18802:
    if (equal(v_18816, v_18815)) goto v_18797;
    else goto v_18798;
v_18797:
    v_18815 = stack[-10];
    goto v_18796;
v_18798:
    v_18815 = stack[-8];
    goto v_18796;
    v_18815 = nil;
v_18796:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    goto v_18791;
v_18792:
    goto v_18788;
v_18789:
    goto v_18790;
v_18791:
    v_18815 = Lrplacd(nil, stack[0], v_18815);
    env = stack[-11];
    v_18815 = stack[-1];
    v_18815 = qcdr(v_18815);
    stack[-1] = v_18815;
    goto v_18739;
v_18738:
    v_18815 = ncons(v_18815);
    env = stack[-11];
    goto v_18730;
v_18731:
    goto v_18727;
v_18728:
    goto v_18729;
v_18730:
    v_18815 = Lrplacd(nil, stack[-4], v_18815);
    env = stack[-11];
    v_18815 = stack[-5];
    v_18815 = qcdr(v_18815);
    stack[-5] = v_18815;
    goto v_18615;
v_18614:
    return onevalue(v_18815);
}



// Code for pasf_zcong

static LispObject CC_pasf_zcong(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18806, v_18807, v_18808;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18807 = v_18585;
// end of prologue
    v_18806 = v_18807;
    v_18806 = Lconsp(nil, v_18806);
    env = stack[0];
    if (v_18806 == nil) goto v_18590;
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = Lconsp(nil, v_18806);
    env = stack[0];
    if (v_18806 == nil) goto v_18590;
    goto v_18604;
v_18600:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18808 = qcar(v_18806);
    goto v_18601;
v_18602:
    v_18806 = elt(env, 1); // (cong ncong)
    goto v_18603;
v_18604:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    v_18806 = Lmemq(nil, v_18808, v_18806);
    if (v_18806 == nil) goto v_18590;
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = qcdr(v_18806);
    if (v_18806 == nil) goto v_18612;
    else goto v_18613;
v_18612:
    goto v_18624;
v_18618:
    goto v_18633;
v_18629:
    goto v_18646;
v_18642:
    v_18808 = v_18807;
    goto v_18643;
v_18644:
    v_18806 = elt(env, 2); // true
    goto v_18645;
v_18646:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    if (v_18808 == v_18806) goto v_18640;
    else goto v_18641;
v_18640:
    v_18806 = lisp_true;
    goto v_18639;
v_18641:
    goto v_18656;
v_18652:
    v_18808 = v_18807;
    goto v_18653;
v_18654:
    v_18806 = elt(env, 3); // false
    goto v_18655;
v_18656:
    goto v_18652;
v_18653:
    goto v_18654;
v_18655:
    v_18806 = (v_18808 == v_18806 ? lisp_true : nil);
    goto v_18639;
    v_18806 = nil;
v_18639:
    if (v_18806 == nil) goto v_18637;
    v_18806 = v_18807;
    v_18808 = v_18806;
    goto v_18635;
v_18637:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = Lconsp(nil, v_18806);
    env = stack[0];
    if (v_18806 == nil) goto v_18662;
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18635;
v_18662:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18635;
    v_18808 = nil;
v_18635:
    goto v_18630;
v_18631:
    v_18806 = elt(env, 4); // cong
    goto v_18632;
v_18633:
    goto v_18629;
v_18630:
    goto v_18631;
v_18632:
    if (v_18808 == v_18806) goto v_18627;
    else goto v_18628;
v_18627:
    v_18806 = elt(env, 5); // equal
    v_18808 = v_18806;
    goto v_18626;
v_18628:
    v_18806 = elt(env, 6); // neq
    v_18808 = v_18806;
    goto v_18626;
    v_18808 = nil;
v_18626:
    goto v_18619;
v_18620:
    v_18806 = v_18807;
    v_18806 = qcdr(v_18806);
    v_18807 = qcar(v_18806);
    goto v_18621;
v_18622:
    v_18806 = nil;
    goto v_18623;
v_18624:
    goto v_18618;
v_18619:
    goto v_18620;
v_18621:
    goto v_18622;
v_18623:
    return list3(v_18808, v_18807, v_18806);
v_18613:
    v_18806 = v_18807;
    v_18806 = qcdr(v_18806);
    v_18806 = qcar(v_18806);
    if (v_18806 == nil) goto v_18686;
    else goto v_18687;
v_18686:
    goto v_18695;
v_18691:
    goto v_18708;
v_18704:
    v_18808 = v_18807;
    goto v_18705;
v_18706:
    v_18806 = elt(env, 2); // true
    goto v_18707;
v_18708:
    goto v_18704;
v_18705:
    goto v_18706;
v_18707:
    if (v_18808 == v_18806) goto v_18702;
    else goto v_18703;
v_18702:
    v_18806 = lisp_true;
    goto v_18701;
v_18703:
    goto v_18718;
v_18714:
    v_18808 = v_18807;
    goto v_18715;
v_18716:
    v_18806 = elt(env, 3); // false
    goto v_18717;
v_18718:
    goto v_18714;
v_18715:
    goto v_18716;
v_18717:
    v_18806 = (v_18808 == v_18806 ? lisp_true : nil);
    goto v_18701;
    v_18806 = nil;
v_18701:
    if (v_18806 == nil) goto v_18699;
    v_18806 = v_18807;
    v_18808 = v_18806;
    goto v_18697;
v_18699:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = Lconsp(nil, v_18806);
    env = stack[0];
    if (v_18806 == nil) goto v_18724;
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18697;
v_18724:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18697;
    v_18808 = nil;
v_18697:
    goto v_18692;
v_18693:
    v_18806 = elt(env, 4); // cong
    goto v_18694;
v_18695:
    goto v_18691;
v_18692:
    goto v_18693;
v_18694:
    v_18806 = (v_18808 == v_18806 ? lisp_true : nil);
    goto v_18685;
v_18687:
    v_18806 = nil;
    goto v_18685;
    v_18806 = nil;
v_18685:
    if (v_18806 == nil) goto v_18683;
    v_18806 = elt(env, 2); // true
    goto v_18611;
v_18683:
    v_18806 = v_18807;
    v_18806 = qcdr(v_18806);
    v_18806 = qcar(v_18806);
    if (v_18806 == nil) goto v_18745;
    else goto v_18746;
v_18745:
    goto v_18754;
v_18750:
    goto v_18767;
v_18763:
    v_18808 = v_18807;
    goto v_18764;
v_18765:
    v_18806 = elt(env, 2); // true
    goto v_18766;
v_18767:
    goto v_18763;
v_18764:
    goto v_18765;
v_18766:
    if (v_18808 == v_18806) goto v_18761;
    else goto v_18762;
v_18761:
    v_18806 = lisp_true;
    goto v_18760;
v_18762:
    goto v_18777;
v_18773:
    v_18808 = v_18807;
    goto v_18774;
v_18775:
    v_18806 = elt(env, 3); // false
    goto v_18776;
v_18777:
    goto v_18773;
v_18774:
    goto v_18775;
v_18776:
    v_18806 = (v_18808 == v_18806 ? lisp_true : nil);
    goto v_18760;
    v_18806 = nil;
v_18760:
    if (v_18806 == nil) goto v_18758;
    v_18806 = v_18807;
    v_18808 = v_18806;
    goto v_18756;
v_18758:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = Lconsp(nil, v_18806);
    env = stack[0];
    if (v_18806 == nil) goto v_18783;
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18756;
v_18783:
    v_18806 = v_18807;
    v_18806 = qcar(v_18806);
    v_18808 = v_18806;
    goto v_18756;
    v_18808 = nil;
v_18756:
    goto v_18751;
v_18752:
    v_18806 = elt(env, 7); // ncong
    goto v_18753;
v_18754:
    goto v_18750;
v_18751:
    goto v_18752;
v_18753:
    v_18806 = (v_18808 == v_18806 ? lisp_true : nil);
    goto v_18744;
v_18746:
    v_18806 = nil;
    goto v_18744;
    v_18806 = nil;
v_18744:
    if (v_18806 == nil) goto v_18742;
    v_18806 = elt(env, 3); // false
    goto v_18611;
v_18742:
    v_18806 = v_18807;
    goto v_18611;
    v_18806 = nil;
v_18611:
    goto v_18588;
v_18590:
    v_18806 = v_18807;
    goto v_18588;
    v_18806 = nil;
v_18588:
    return onevalue(v_18806);
}



// Code for ctx_idl

static LispObject CC_ctx_idl(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18630;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_18630 = v_18585;
// end of prologue
    fn = elt(env, 1); // ctx_ial
    v_18630 = (*qfn1(fn))(fn, v_18630);
    env = stack[-4];
    stack[-3] = v_18630;
    v_18630 = stack[-3];
    if (v_18630 == nil) goto v_18597;
    else goto v_18598;
v_18597:
    v_18630 = nil;
    goto v_18591;
v_18598:
    v_18630 = stack[-3];
    v_18630 = qcar(v_18630);
    v_18630 = qcar(v_18630);
    v_18630 = ncons(v_18630);
    env = stack[-4];
    stack[-1] = v_18630;
    stack[-2] = v_18630;
v_18592:
    v_18630 = stack[-3];
    v_18630 = qcdr(v_18630);
    stack[-3] = v_18630;
    v_18630 = stack[-3];
    if (v_18630 == nil) goto v_18611;
    else goto v_18612;
v_18611:
    v_18630 = stack[-2];
    goto v_18591;
v_18612:
    goto v_18620;
v_18616:
    stack[0] = stack[-1];
    goto v_18617;
v_18618:
    v_18630 = stack[-3];
    v_18630 = qcar(v_18630);
    v_18630 = qcar(v_18630);
    v_18630 = ncons(v_18630);
    env = stack[-4];
    goto v_18619;
v_18620:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    v_18630 = Lrplacd(nil, stack[0], v_18630);
    env = stack[-4];
    v_18630 = stack[-1];
    v_18630 = qcdr(v_18630);
    stack[-1] = v_18630;
    goto v_18592;
v_18591:
    return onevalue(v_18630);
}



// Code for vectorml

static LispObject CC_vectorml(LispObject env,
                         LispObject v_18585)
{
    env = qenv(env);
    LispObject v_18609, v_18610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18585);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18585);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18585;
// end of prologue
    v_18609 = elt(env, 1); // "<vector"
    fn = elt(env, 4); // printout
    v_18609 = (*qfn1(fn))(fn, v_18609);
    env = stack[-1];
    goto v_18596;
v_18592:
    v_18609 = stack[0];
    v_18610 = qcar(v_18609);
    goto v_18593;
v_18594:
    v_18609 = elt(env, 2); // ""
    goto v_18595;
v_18596:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    fn = elt(env, 5); // attributesml
    v_18609 = (*qfn2(fn))(fn, v_18610, v_18609);
    env = stack[-1];
    v_18609 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_18609 = (*qfn1(fn))(fn, v_18609);
    env = stack[-1];
    v_18609 = stack[0];
    v_18609 = qcdr(v_18609);
    fn = elt(env, 7); // multi_elem
    v_18609 = (*qfn1(fn))(fn, v_18609);
    env = stack[-1];
    v_18609 = nil;
    fn = elt(env, 6); // indent!*
    v_18609 = (*qfn1(fn))(fn, v_18609);
    env = stack[-1];
    v_18609 = elt(env, 3); // "</vector>"
    fn = elt(env, 4); // printout
    v_18609 = (*qfn1(fn))(fn, v_18609);
    v_18609 = nil;
    return onevalue(v_18609);
}



setup_type const u33_setup[] =
{
    {"letexprn",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letexprn},
    {"triplesetprolongedby",    TOO_FEW_2,      CC_triplesetprolongedby,WRONG_NO_2},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,TOO_MANY_1,    WRONG_NO_1},
    {"pasf_floor",              TOO_FEW_2,      CC_pasf_floor, WRONG_NO_2},
    {"bvarrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_bvarrd},
    {"module",                  CC_module,      TOO_MANY_1,    WRONG_NO_1},
    {"log_freevars_list",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_log_freevars_list},
    {"simp-prop-condense",      CC_simpKpropKcondense,TOO_MANY_1,WRONG_NO_1},
    {"lambda_rfde09ec49c92",    TOO_FEW_2,      CC_lambda_rfde09ec49c92,WRONG_NO_2},
    {"skp_ordp",                TOO_FEW_2,      CC_skp_ordp,   WRONG_NO_2},
    {"vp2",                     CC_vp2,         TOO_MANY_1,    WRONG_NO_1},
    {"talp_specsubt",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_specsubt},
    {"pasf_cein",               CC_pasf_cein,   TOO_MANY_1,    WRONG_NO_1},
    {"sets",                    TOO_FEW_2,      CC_sets,       WRONG_NO_2},
    {"resume",                  TOO_FEW_2,      CC_resume,     WRONG_NO_2},
    {"evaluate",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluate},
    {"toolongexpp",             CC_toolongexpp, TOO_MANY_1,    WRONG_NO_1},
    {"reval3",                  CC_reval3,      TOO_MANY_1,    WRONG_NO_1},
    {"incident",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_incident},
    {"assert_formproc",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_formproc},
    {"fs:onep:",                CC_fsTonepT,    TOO_MANY_1,    WRONG_NO_1},
    {"ratdif",                  TOO_FEW_2,      CC_ratdif,     WRONG_NO_2},
    {"gcd-with-number",         TOO_FEW_2,      CC_gcdKwithKnumber,WRONG_NO_2},
    {"lex_skip_line_comment",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_skip_line_comment},
    {"multdfconst",             TOO_FEW_2,      CC_multdfconst,WRONG_NO_2},
    {"mri_congp",               CC_mri_congp,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,TOO_MANY_1, WRONG_NO_1},
    {"cgp_mk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cgp_mk},
    {"matrixom",                CC_matrixom,    TOO_MANY_1,    WRONG_NO_1},
    {"alg_plus",                TOO_FEW_2,      CC_alg_plus,   WRONG_NO_2},
    {"evaluate-horner",         CC_evaluateKhorner,TOO_MANY_1, WRONG_NO_1},
    {"lispreadp",               CC_lispreadp,   TOO_MANY_1,    WRONG_NO_1},
    {"indexsymmetrize",         CC_indexsymmetrize,TOO_MANY_1, WRONG_NO_1},
    {"s_actual_world1",         CC_s_actual_world1,TOO_MANY_1, WRONG_NO_1},
    {"assert_procstat-argl",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_procstatKargl},
    {"cde_replace_nth",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cde_replace_nth},
    {"lex_process_directive",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_process_directive},
    {"ofsf_ir2atl",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_ir2atl},
    {"sortedpolynomlistinsert", TOO_FEW_2,      CC_sortedpolynomlistinsert,WRONG_NO_2},
    {"*tayexp2q",               CC_Htayexp2q,   TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_smwmkatl},
    {"ev_2a",                   CC_ev_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"applyfnrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyfnrd},
    {"lessppair",               TOO_FEW_2,      CC_lessppair,  WRONG_NO_2},
    {"dipsimpcont",             CC_dipsimpcont, TOO_MANY_1,    WRONG_NO_1},
    {"dipprodin",               TOO_FEW_2,      CC_dipprodin,  WRONG_NO_2},
    {"difference:",             TOO_FEW_2,      CC_differenceT,WRONG_NO_2},
    {"find_buble",              TOO_FEW_2,      CC_find_buble, WRONG_NO_2},
    {"remchkf",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_remchkf},
    {"ad_splitname",            CC_ad_splitname,TOO_MANY_1,    WRONG_NO_1},
    {"find-null-space",         TOO_FEW_2,      CC_findKnullKspace,WRONG_NO_2},
    {"rl_transform",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_transform},
    {"polynomwrite",            CC_polynomwrite,TOO_MANY_1,    WRONG_NO_1},
    {"cl_apply2ats1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_apply2ats1},
    {"gen+can+bas",             CC_genLcanLbas, TOO_MANY_1,    WRONG_NO_1},
    {"pasf_zcong",              CC_pasf_zcong,  TOO_MANY_1,    WRONG_NO_1},
    {"ctx_idl",                 CC_ctx_idl,     TOO_MANY_1,    WRONG_NO_1},
    {"vectorml",                CC_vectorml,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u33", (two_args *)"12329 4776162 92009", 0}
};

// end of generated code
