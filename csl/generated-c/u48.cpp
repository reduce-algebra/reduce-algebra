
// $destdir/u48.c        Machine generated C code

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



// Code for merge_lists

static LispObject CC_merge_lists(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29343, v_29344;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_29158;
    stack[-5] = v_29157;
// end of prologue
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v_29343 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_29343;
    v_29343 = stack[-5];
    v_29343 = Lreverse(nil, v_29343);
    env = stack[-7];
    stack[-5] = v_29343;
    v_29343 = stack[-5];
    if (v_29343 == nil) goto v_29177;
    v_29343 = stack[-5];
    v_29343 = qcar(v_29343);
    stack[-6] = v_29343;
    goto v_29175;
v_29177:
    goto v_29169;
v_29175:
v_29168:
    v_29343 = stack[-4];
    if (v_29343 == nil) goto v_29186;
    v_29343 = stack[-4];
    v_29343 = qcar(v_29343);
    stack[-2] = v_29343;
    goto v_29184;
v_29186:
    goto v_29169;
v_29184:
    goto v_29201;
v_29197:
    v_29344 = stack[-6];
    goto v_29198;
v_29199:
    v_29343 = stack[-2];
    goto v_29200;
v_29201:
    goto v_29197;
v_29198:
    goto v_29199;
v_29200:
    v_29343 = (LispObject)lessp2(v_29344, v_29343);
    v_29343 = v_29343 ? lisp_true : nil;
    env = stack[-7];
    if (v_29343 == nil) goto v_29195;
    goto v_29169;
v_29195:
    goto v_29209;
v_29205:
    v_29344 = stack[-2];
    goto v_29206;
v_29207:
    v_29343 = stack[-3];
    goto v_29208;
v_29209:
    goto v_29205;
v_29206:
    goto v_29207;
v_29208:
    v_29343 = cons(v_29344, v_29343);
    env = stack[-7];
    stack[-3] = v_29343;
    v_29343 = stack[-1];
    v_29343 = (v_29343 == nil ? lisp_true : nil);
    stack[-1] = v_29343;
    v_29343 = stack[-4];
    v_29343 = qcdr(v_29343);
    stack[-4] = v_29343;
    goto v_29168;
v_29169:
    v_29343 = stack[-5];
    if (v_29343 == nil) goto v_29218;
    else goto v_29219;
v_29218:
    goto v_29226;
v_29222:
    goto v_29223;
v_29224:
    goto v_29233;
v_29229:
    v_29344 = stack[-3];
    goto v_29230;
v_29231:
    v_29343 = stack[-4];
    goto v_29232;
v_29233:
    goto v_29229;
v_29230:
    goto v_29231;
v_29232:
    fn = elt(env, 1); // reversip2
    v_29343 = (*qfn2(fn))(fn, v_29344, v_29343);
    goto v_29225;
v_29226:
    goto v_29222;
v_29223:
    goto v_29224;
v_29225:
    {
        LispObject v_29352 = stack[0];
        return cons(v_29352, v_29343);
    }
v_29219:
    v_29343 = stack[-3];
    if (v_29343 == nil) goto v_29238;
    else goto v_29239;
v_29238:
    goto v_29246;
v_29242:
    goto v_29243;
v_29244:
    goto v_29253;
v_29249:
    v_29344 = stack[-5];
    goto v_29250;
v_29251:
    v_29343 = stack[-4];
    goto v_29252;
v_29253:
    goto v_29249;
v_29250:
    goto v_29251;
v_29252:
    fn = elt(env, 1); // reversip2
    v_29343 = (*qfn2(fn))(fn, v_29344, v_29343);
    goto v_29245;
v_29246:
    goto v_29242;
v_29243:
    goto v_29244;
v_29245:
    {
        LispObject v_29353 = stack[0];
        return cons(v_29353, v_29343);
    }
v_29239:
    v_29343 = stack[-3];
    v_29343 = qcar(v_29343);
    stack[-2] = v_29343;
    goto v_29270;
v_29266:
    v_29344 = stack[-6];
    goto v_29267;
v_29268:
    v_29343 = stack[-2];
    goto v_29269;
v_29270:
    goto v_29266;
v_29267:
    goto v_29268;
v_29269:
    if (equal(v_29344, v_29343)) goto v_29264;
    else goto v_29265;
v_29264:
    goto v_29278;
v_29274:
    v_29344 = stack[-6];
    goto v_29275;
v_29276:
    v_29343 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29277;
v_29278:
    goto v_29274;
v_29275:
    goto v_29276;
v_29277:
    v_29343 = (LispObject)greaterp2(v_29344, v_29343);
    v_29343 = v_29343 ? lisp_true : nil;
    env = stack[-7];
    goto v_29263;
v_29265:
    v_29343 = nil;
    goto v_29263;
    v_29343 = nil;
v_29263:
    if (v_29343 == nil) goto v_29261;
    v_29343 = nil;
    goto v_29167;
v_29261:
    goto v_29294;
v_29290:
    v_29344 = stack[-6];
    goto v_29291;
v_29292:
    v_29343 = stack[-2];
    goto v_29293;
v_29294:
    goto v_29290;
v_29291:
    goto v_29292;
v_29293:
    v_29343 = (LispObject)greaterp2(v_29344, v_29343);
    v_29343 = v_29343 ? lisp_true : nil;
    env = stack[-7];
    if (v_29343 == nil) goto v_29288;
    goto v_29170;
v_29288:
    goto v_29302;
v_29298:
    v_29344 = stack[-2];
    goto v_29299;
v_29300:
    v_29343 = stack[-4];
    goto v_29301;
v_29302:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    v_29343 = cons(v_29344, v_29343);
    env = stack[-7];
    stack[-4] = v_29343;
    v_29343 = stack[-3];
    v_29343 = qcdr(v_29343);
    stack[-3] = v_29343;
    v_29343 = stack[-1];
    v_29343 = (v_29343 == nil ? lisp_true : nil);
    stack[-1] = v_29343;
    goto v_29169;
v_29170:
    goto v_29314;
v_29310:
    v_29344 = stack[-6];
    goto v_29311;
v_29312:
    v_29343 = stack[-4];
    goto v_29313;
v_29314:
    goto v_29310;
v_29311:
    goto v_29312;
v_29313:
    v_29343 = cons(v_29344, v_29343);
    env = stack[-7];
    stack[-4] = v_29343;
    v_29343 = stack[-5];
    v_29343 = qcdr(v_29343);
    stack[-5] = v_29343;
    v_29343 = stack[-1];
    if (v_29343 == nil) goto v_29322;
    goto v_29331;
v_29327:
    v_29344 = stack[-6];
    goto v_29328;
v_29329:
    v_29343 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29330;
v_29331:
    goto v_29327;
v_29328:
    goto v_29329;
v_29330:
    v_29343 = (LispObject)greaterp2(v_29344, v_29343);
    v_29343 = v_29343 ? lisp_true : nil;
    env = stack[-7];
    if (v_29343 == nil) goto v_29322;
    v_29343 = stack[0];
    v_29343 = negate(v_29343);
    env = stack[-7];
    stack[0] = v_29343;
    goto v_29320;
v_29322:
v_29320:
    v_29343 = stack[-5];
    if (v_29343 == nil) goto v_29339;
    v_29343 = stack[-5];
    v_29343 = qcar(v_29343);
    stack[-6] = v_29343;
    goto v_29337;
v_29339:
v_29337:
    goto v_29169;
v_29167:
    return onevalue(v_29343);
}



// Code for talp_lssimpl

static LispObject CC_talp_lssimpl(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29288, v_29289, v_29290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    v_29288 = stack[0];
    fn = elt(env, 4); // talp_rnf
    v_29288 = (*qfn1(fn))(fn, v_29288);
    env = stack[-5];
    stack[0] = v_29288;
    v_29288 = stack[0];
    if (!consp(v_29288)) goto v_29170;
    else goto v_29171;
v_29170:
    v_29288 = lisp_true;
    goto v_29169;
v_29171:
    v_29288 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_29288 = (*qfn1(fn))(fn, v_29288);
    env = stack[-5];
    goto v_29169;
    v_29288 = nil;
v_29169:
    if (v_29288 == nil) goto v_29167;
    v_29288 = stack[0];
    goto v_29161;
v_29167:
    v_29288 = stack[0];
    fn = elt(env, 6); // talp_op
    v_29288 = (*qfn1(fn))(fn, v_29288);
    env = stack[-5];
    v_29290 = v_29288;
    goto v_29193;
v_29189:
    v_29289 = v_29290;
    goto v_29190;
v_29191:
    v_29288 = elt(env, 1); // or
    goto v_29192;
v_29193:
    goto v_29189;
v_29190:
    goto v_29191;
v_29192:
    if (v_29289 == v_29288) goto v_29187;
    else goto v_29188;
v_29187:
    v_29288 = lisp_true;
    goto v_29186;
v_29188:
    goto v_29203;
v_29199:
    v_29289 = v_29290;
    goto v_29200;
v_29201:
    v_29288 = elt(env, 2); // and
    goto v_29202;
v_29203:
    goto v_29199;
v_29200:
    goto v_29201;
v_29202:
    v_29288 = (v_29289 == v_29288 ? lisp_true : nil);
    goto v_29186;
    v_29288 = nil;
v_29186:
    if (v_29288 == nil) goto v_29184;
    goto v_29214;
v_29210:
    stack[-4] = v_29290;
    goto v_29211;
v_29212:
    v_29288 = stack[0];
    fn = elt(env, 7); // talp_argl
    v_29288 = (*qfn1(fn))(fn, v_29288);
    env = stack[-5];
    stack[-3] = v_29288;
    v_29288 = stack[-3];
    if (v_29288 == nil) goto v_29226;
    else goto v_29227;
v_29226:
    v_29288 = nil;
    goto v_29220;
v_29227:
    v_29288 = stack[-3];
    v_29288 = qcar(v_29288);
    v_29288 = CC_talp_lssimpl(elt(env, 0), v_29288);
    env = stack[-5];
    v_29288 = ncons(v_29288);
    env = stack[-5];
    stack[-1] = v_29288;
    stack[-2] = v_29288;
v_29221:
    v_29288 = stack[-3];
    v_29288 = qcdr(v_29288);
    stack[-3] = v_29288;
    v_29288 = stack[-3];
    if (v_29288 == nil) goto v_29240;
    else goto v_29241;
v_29240:
    v_29288 = stack[-2];
    goto v_29220;
v_29241:
    goto v_29249;
v_29245:
    stack[0] = stack[-1];
    goto v_29246;
v_29247:
    v_29288 = stack[-3];
    v_29288 = qcar(v_29288);
    v_29288 = CC_talp_lssimpl(elt(env, 0), v_29288);
    env = stack[-5];
    v_29288 = ncons(v_29288);
    env = stack[-5];
    goto v_29248;
v_29249:
    goto v_29245;
v_29246:
    goto v_29247;
v_29248:
    v_29288 = Lrplacd(nil, stack[0], v_29288);
    env = stack[-5];
    v_29288 = stack[-1];
    v_29288 = qcdr(v_29288);
    stack[-1] = v_29288;
    goto v_29221;
v_29220:
    goto v_29213;
v_29214:
    goto v_29210;
v_29211:
    goto v_29212;
v_29213:
    v_29288 = cons(stack[-4], v_29288);
    env = stack[-5];
    fn = elt(env, 8); // talp_lssimpl1
    v_29288 = (*qfn1(fn))(fn, v_29288);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_29288);
    }
v_29184:
    goto v_29265;
v_29261:
    v_29289 = v_29290;
    goto v_29262;
v_29263:
    v_29288 = elt(env, 3); // (ex all)
    goto v_29264;
v_29265:
    goto v_29261;
v_29262:
    goto v_29263;
v_29264:
    v_29288 = Lmemq(nil, v_29289, v_29288);
    if (v_29288 == nil) goto v_29260;
    goto v_29277;
v_29271:
    stack[-2] = v_29290;
    goto v_29272;
v_29273:
    v_29288 = stack[0];
    v_29288 = qcdr(v_29288);
    stack[-1] = qcar(v_29288);
    goto v_29274;
v_29275:
    v_29288 = stack[0];
    v_29288 = qcdr(v_29288);
    v_29288 = qcdr(v_29288);
    v_29288 = qcar(v_29288);
    v_29288 = CC_talp_lssimpl(elt(env, 0), v_29288);
    env = stack[-5];
    v_29288 = ncons(v_29288);
    env = stack[-5];
    goto v_29276;
v_29277:
    goto v_29271;
v_29272:
    goto v_29273;
v_29274:
    goto v_29275;
v_29276:
    v_29288 = list2star(stack[-2], stack[-1], v_29288);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_29288);
    }
v_29260:
    v_29288 = nil;
v_29161:
    return onevalue(v_29288);
}



// Code for pasf_lnegrel

static LispObject CC_pasf_lnegrel(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29252, v_29253, v_29254;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29254 = v_29157;
// end of prologue
    goto v_29167;
v_29163:
    v_29253 = v_29254;
    goto v_29164;
v_29165:
    v_29252 = elt(env, 1); // equal
    goto v_29166;
v_29167:
    goto v_29163;
v_29164:
    goto v_29165;
v_29166:
    if (v_29253 == v_29252) goto v_29161;
    else goto v_29162;
v_29161:
    v_29252 = elt(env, 2); // neq
    goto v_29160;
v_29162:
    goto v_29177;
v_29173:
    v_29253 = v_29254;
    goto v_29174;
v_29175:
    v_29252 = elt(env, 2); // neq
    goto v_29176;
v_29177:
    goto v_29173;
v_29174:
    goto v_29175;
v_29176:
    if (v_29253 == v_29252) goto v_29171;
    else goto v_29172;
v_29171:
    v_29252 = elt(env, 1); // equal
    goto v_29160;
v_29172:
    goto v_29187;
v_29183:
    v_29253 = v_29254;
    goto v_29184;
v_29185:
    v_29252 = elt(env, 3); // leq
    goto v_29186;
v_29187:
    goto v_29183;
v_29184:
    goto v_29185;
v_29186:
    if (v_29253 == v_29252) goto v_29181;
    else goto v_29182;
v_29181:
    v_29252 = elt(env, 4); // greaterp
    goto v_29160;
v_29182:
    goto v_29197;
v_29193:
    v_29253 = v_29254;
    goto v_29194;
v_29195:
    v_29252 = elt(env, 5); // lessp
    goto v_29196;
v_29197:
    goto v_29193;
v_29194:
    goto v_29195;
v_29196:
    if (v_29253 == v_29252) goto v_29191;
    else goto v_29192;
v_29191:
    v_29252 = elt(env, 6); // geq
    goto v_29160;
v_29192:
    goto v_29207;
v_29203:
    v_29253 = v_29254;
    goto v_29204;
v_29205:
    v_29252 = elt(env, 6); // geq
    goto v_29206;
v_29207:
    goto v_29203;
v_29204:
    goto v_29205;
v_29206:
    if (v_29253 == v_29252) goto v_29201;
    else goto v_29202;
v_29201:
    v_29252 = elt(env, 5); // lessp
    goto v_29160;
v_29202:
    goto v_29217;
v_29213:
    v_29253 = v_29254;
    goto v_29214;
v_29215:
    v_29252 = elt(env, 4); // greaterp
    goto v_29216;
v_29217:
    goto v_29213;
v_29214:
    goto v_29215;
v_29216:
    if (v_29253 == v_29252) goto v_29211;
    else goto v_29212;
v_29211:
    v_29252 = elt(env, 3); // leq
    goto v_29160;
v_29212:
    goto v_29227;
v_29223:
    v_29253 = v_29254;
    goto v_29224;
v_29225:
    v_29252 = elt(env, 7); // cong
    goto v_29226;
v_29227:
    goto v_29223;
v_29224:
    goto v_29225;
v_29226:
    if (v_29253 == v_29252) goto v_29221;
    else goto v_29222;
v_29221:
    v_29252 = elt(env, 8); // ncong
    goto v_29160;
v_29222:
    goto v_29237;
v_29233:
    v_29253 = v_29254;
    goto v_29234;
v_29235:
    v_29252 = elt(env, 8); // ncong
    goto v_29236;
v_29237:
    goto v_29233;
v_29234:
    goto v_29235;
v_29236:
    if (v_29253 == v_29252) goto v_29231;
    else goto v_29232;
v_29231:
    v_29252 = elt(env, 7); // cong
    goto v_29160;
v_29232:
    goto v_29249;
v_29245:
    v_29252 = elt(env, 9); // "pasf_lnegrel: unknown operator"
    goto v_29246;
v_29247:
    v_29253 = v_29254;
    goto v_29248;
v_29249:
    goto v_29245;
v_29246:
    goto v_29247;
v_29248:
    v_29252 = list2(v_29252, v_29253);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_29252);
    }
    v_29252 = nil;
v_29160:
    return onevalue(v_29252);
}



// Code for addexptsdf

static LispObject CC_addexptsdf(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29222, v_29223;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29158;
    stack[-1] = v_29157;
// end of prologue
    stack[-2] = nil;
v_29163:
    v_29222 = stack[-1];
    if (v_29222 == nil) goto v_29166;
    else goto v_29167;
v_29166:
    v_29222 = stack[0];
    if (v_29222 == nil) goto v_29171;
    else goto v_29172;
v_29171:
    v_29222 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_29222);
    }
v_29172:
    goto v_29183;
v_29179:
    stack[0] = stack[-2];
    goto v_29180;
v_29181:
    v_29222 = elt(env, 1); // "X too long"
    fn = elt(env, 4); // interr
    v_29222 = (*qfn1(fn))(fn, v_29222);
    env = stack[-3];
    goto v_29182;
v_29183:
    goto v_29179;
v_29180:
    goto v_29181;
v_29182:
    {
        LispObject v_29227 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_29227, v_29222);
    }
    goto v_29165;
v_29167:
    v_29222 = stack[0];
    if (v_29222 == nil) goto v_29187;
    else goto v_29188;
v_29187:
    goto v_29195;
v_29191:
    stack[0] = stack[-2];
    goto v_29192;
v_29193:
    v_29222 = elt(env, 2); // "Y too long"
    fn = elt(env, 4); // interr
    v_29222 = (*qfn1(fn))(fn, v_29222);
    env = stack[-3];
    goto v_29194;
v_29195:
    goto v_29191;
v_29192:
    goto v_29193;
v_29194:
    {
        LispObject v_29228 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_29228, v_29222);
    }
v_29188:
    goto v_29206;
v_29202:
    goto v_29212;
v_29208:
    v_29222 = stack[-1];
    v_29223 = qcar(v_29222);
    goto v_29209;
v_29210:
    v_29222 = stack[0];
    v_29222 = qcar(v_29222);
    goto v_29211;
v_29212:
    goto v_29208;
v_29209:
    goto v_29210;
v_29211:
    fn = elt(env, 5); // exptplus
    v_29223 = (*qfn2(fn))(fn, v_29223, v_29222);
    env = stack[-3];
    goto v_29203;
v_29204:
    v_29222 = stack[-2];
    goto v_29205;
v_29206:
    goto v_29202;
v_29203:
    goto v_29204;
v_29205:
    v_29222 = cons(v_29223, v_29222);
    env = stack[-3];
    stack[-2] = v_29222;
    v_29222 = stack[-1];
    v_29222 = qcdr(v_29222);
    stack[-1] = v_29222;
    v_29222 = stack[0];
    v_29222 = qcdr(v_29222);
    stack[0] = v_29222;
    goto v_29163;
v_29165:
    v_29222 = nil;
    return onevalue(v_29222);
}



// Code for lengthn

static LispObject CC_lengthn(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29187;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    v_29187 = stack[0];
    if (v_29187 == nil) goto v_29161;
    else goto v_29162;
v_29161:
    v_29187 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29160;
v_29162:
    v_29187 = stack[0];
    v_29187 = qcar(v_29187);
    if (is_number(v_29187)) goto v_29165;
    else goto v_29166;
v_29165:
    goto v_29174;
v_29170:
    v_29187 = stack[0];
    v_29187 = qcar(v_29187);
    stack[-1] = sub1(v_29187);
    env = stack[-2];
    goto v_29171;
v_29172:
    v_29187 = stack[0];
    v_29187 = qcdr(v_29187);
    v_29187 = CC_lengthn(elt(env, 0), v_29187);
    goto v_29173;
v_29174:
    goto v_29170;
v_29171:
    goto v_29172;
v_29173:
    {
        LispObject v_29190 = stack[-1];
        return plus2(v_29190, v_29187);
    }
v_29166:
    v_29187 = stack[0];
    v_29187 = qcdr(v_29187);
    v_29187 = CC_lengthn(elt(env, 0), v_29187);
    return add1(v_29187);
    v_29187 = nil;
v_29160:
    return onevalue(v_29187);
}



// Code for spmatlength

static LispObject CC_spmatlength(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29230, v_29231, v_29232, v_29233;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29232 = v_29157;
// end of prologue
    v_29230 = v_29232;
    v_29230 = Lconsp(nil, v_29230);
    env = stack[-2];
    if (v_29230 == nil) goto v_29166;
    v_29230 = v_29232;
    goto v_29164;
v_29166:
    v_29230 = v_29232;
    if (!symbolp(v_29230)) v_29230 = nil;
    else { v_29230 = qfastgets(v_29230);
           if (v_29230 != nil) { v_29230 = elt(v_29230, 4); // avalue
#ifdef RECORD_GET
             if (v_29230 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_29230 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_29230 == SPID_NOPROP) v_29230 = nil; }}
#endif
    v_29230 = qcdr(v_29230);
    v_29230 = qcar(v_29230);
    goto v_29164;
v_29164:
    v_29231 = v_29230;
    v_29231 = qcdr(v_29231);
    v_29231 = qcdr(v_29231);
    v_29231 = qcar(v_29231);
    v_29231 = qcdr(v_29231);
    v_29233 = v_29231;
    goto v_29190;
v_29186:
    v_29231 = v_29230;
    goto v_29187;
v_29188:
    v_29230 = elt(env, 1); // sparsemat
    goto v_29189;
v_29190:
    goto v_29186;
v_29187:
    goto v_29188;
v_29189:
    if (!consp(v_29231)) goto v_29183;
    v_29231 = qcar(v_29231);
    if (v_29231 == v_29230) goto v_29184;
v_29183:
    goto v_29200;
v_29194:
    stack[-1] = elt(env, 2); // matrix
    goto v_29195;
v_29196:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_29197;
v_29198:
    goto v_29210;
v_29204:
    v_29231 = elt(env, 3); // "Matrix"
    goto v_29205;
v_29206:
    goto v_29207;
v_29208:
    v_29230 = elt(env, 4); // "not set"
    goto v_29209;
v_29210:
    goto v_29204;
v_29205:
    goto v_29206;
v_29207:
    goto v_29208;
v_29209:
    v_29230 = list3(v_29231, v_29232, v_29230);
    env = stack[-2];
    goto v_29199;
v_29200:
    goto v_29194;
v_29195:
    goto v_29196;
v_29197:
    goto v_29198;
v_29199:
    fn = elt(env, 6); // rerror
    v_29230 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_29230);
    goto v_29182;
v_29184:
    goto v_29223;
v_29217:
    v_29231 = elt(env, 5); // list
    goto v_29218;
v_29219:
    v_29230 = v_29233;
    v_29230 = qcar(v_29230);
    goto v_29220;
v_29221:
    v_29232 = v_29233;
    v_29232 = qcdr(v_29232);
    v_29232 = qcar(v_29232);
    goto v_29222;
v_29223:
    goto v_29217;
v_29218:
    goto v_29219;
v_29220:
    goto v_29221;
v_29222:
    return list3(v_29231, v_29230, v_29232);
v_29182:
    v_29230 = nil;
    return onevalue(v_29230);
}



// Code for groebcplistsort

static LispObject CC_groebcplistsort(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29186, v_29187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29186 = v_29157;
// end of prologue
    v_29187 = nil;
    stack[0] = v_29186;
v_29164:
    v_29186 = stack[0];
    if (v_29186 == nil) goto v_29168;
    else goto v_29169;
v_29168:
    goto v_29163;
v_29169:
    v_29186 = stack[0];
    v_29186 = qcar(v_29186);
    goto v_29180;
v_29176:
    goto v_29177;
v_29178:
    goto v_29179;
v_29180:
    goto v_29176;
v_29177:
    goto v_29178;
v_29179:
    fn = elt(env, 1); // groebcplistsortin
    v_29186 = (*qfn2(fn))(fn, v_29186, v_29187);
    env = stack[-1];
    v_29187 = v_29186;
    v_29186 = stack[0];
    v_29186 = qcdr(v_29186);
    stack[0] = v_29186;
    goto v_29164;
v_29163:
    v_29186 = v_29187;
    return onevalue(v_29186);
}



// Code for maprintla

static LispObject CC_maprintla(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29522, v_29523, v_29524;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29158;
    stack[-2] = v_29157;
// end of prologue
v_29156:
    v_29522 = stack[-2];
    if (v_29522 == nil) goto v_29168;
    else goto v_29169;
v_29168:
    v_29522 = nil;
    goto v_29162;
v_29169:
    v_29522 = stack[-2];
    if (is_number(v_29522)) goto v_29172;
    else goto v_29173;
v_29172:
    goto v_29165;
v_29173:
    v_29522 = stack[-2];
    if (!consp(v_29522)) goto v_29175;
    else goto v_29176;
v_29175:
    v_29522 = stack[-2];
    {
        fn = elt(env, 15); // prinlatom
        return (*qfn1(fn))(fn, v_29522);
    }
v_29176:
    v_29522 = stack[-2];
    v_29522 = Lstringp(nil, v_29522);
    env = stack[-4];
    if (v_29522 == nil) goto v_29181;
    v_29522 = stack[-2];
    {
        fn = elt(env, 16); // prin2la
        return (*qfn1(fn))(fn, v_29522);
    }
v_29181:
    v_29522 = stack[-2];
    v_29522 = qcar(v_29522);
    if (!consp(v_29522)) goto v_29187;
    goto v_29195;
v_29191:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29192;
v_29193:
    v_29522 = stack[-1];
    goto v_29194;
v_29195:
    goto v_29191;
v_29192:
    goto v_29193;
v_29194:
    stack[-2] = v_29523;
    stack[-1] = v_29522;
    goto v_29156;
v_29187:
    goto v_29207;
v_29203:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29204;
v_29205:
    v_29522 = elt(env, 1); // laprifn
    goto v_29206;
v_29207:
    goto v_29203;
v_29204:
    goto v_29205;
v_29206:
    v_29522 = get(v_29523, v_29522);
    env = stack[-4];
    stack[-3] = v_29522;
    if (v_29522 == nil) goto v_29200;
    goto v_29225;
v_29221:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29222;
v_29223:
    v_29522 = elt(env, 2); // fulla
    goto v_29224;
v_29225:
    goto v_29221;
v_29222:
    goto v_29223;
v_29224:
    v_29522 = Lflagp(nil, v_29523, v_29522);
    env = stack[-4];
    if (v_29522 == nil) goto v_29218;
    else goto v_29219;
v_29218:
    goto v_29233;
v_29229:
    goto v_29239;
v_29235:
    stack[0] = stack[-3];
    goto v_29236;
v_29237:
    goto v_29246;
v_29242:
    v_29522 = stack[-2];
    v_29523 = qcdr(v_29522);
    goto v_29243;
v_29244:
    v_29522 = stack[-1];
    goto v_29245;
v_29246:
    goto v_29242;
v_29243:
    goto v_29244;
v_29245:
    v_29522 = list2(v_29523, v_29522);
    env = stack[-4];
    goto v_29238;
v_29239:
    goto v_29235;
v_29236:
    goto v_29237;
v_29238:
    fn = elt(env, 17); // apply
    v_29523 = (*qfn2(fn))(fn, stack[0], v_29522);
    env = stack[-4];
    goto v_29230;
v_29231:
    v_29522 = elt(env, 3); // failed
    goto v_29232;
v_29233:
    goto v_29229;
v_29230:
    goto v_29231;
v_29232:
    v_29522 = (v_29523 == v_29522 ? lisp_true : nil);
    v_29522 = (v_29522 == nil ? lisp_true : nil);
    goto v_29217;
v_29219:
    v_29522 = nil;
    goto v_29217;
    v_29522 = nil;
v_29217:
    if (v_29522 == nil) goto v_29215;
    v_29522 = lisp_true;
    goto v_29213;
v_29215:
    goto v_29268;
v_29264:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29265;
v_29266:
    v_29522 = elt(env, 2); // fulla
    goto v_29267;
v_29268:
    goto v_29264;
v_29265:
    goto v_29266;
v_29267:
    v_29522 = Lflagp(nil, v_29523, v_29522);
    env = stack[-4];
    if (v_29522 == nil) goto v_29262;
    goto v_29276;
v_29272:
    goto v_29282;
v_29278:
    stack[0] = stack[-3];
    goto v_29279;
v_29280:
    goto v_29289;
v_29285:
    v_29523 = stack[-2];
    goto v_29286;
v_29287:
    v_29522 = stack[-1];
    goto v_29288;
v_29289:
    goto v_29285;
v_29286:
    goto v_29287;
v_29288:
    v_29522 = list2(v_29523, v_29522);
    env = stack[-4];
    goto v_29281;
v_29282:
    goto v_29278;
v_29279:
    goto v_29280;
v_29281:
    fn = elt(env, 17); // apply
    v_29523 = (*qfn2(fn))(fn, stack[0], v_29522);
    env = stack[-4];
    goto v_29273;
v_29274:
    v_29522 = elt(env, 3); // failed
    goto v_29275;
v_29276:
    goto v_29272;
v_29273:
    goto v_29274;
v_29275:
    v_29522 = (v_29523 == v_29522 ? lisp_true : nil);
    v_29522 = (v_29522 == nil ? lisp_true : nil);
    goto v_29260;
v_29262:
    v_29522 = nil;
    goto v_29260;
    v_29522 = nil;
v_29260:
    goto v_29213;
    v_29522 = nil;
v_29213:
    if (v_29522 == nil) goto v_29200;
    v_29522 = stack[-2];
    goto v_29162;
v_29200:
    goto v_29306;
v_29302:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29303;
v_29304:
    v_29522 = elt(env, 4); // indexed
    goto v_29305;
v_29306:
    goto v_29302;
v_29303:
    goto v_29304;
v_29305:
    v_29522 = get(v_29523, v_29522);
    env = stack[-4];
    stack[-3] = v_29522;
    if (v_29522 == nil) goto v_29300;
    goto v_29317;
v_29311:
    v_29522 = stack[-2];
    v_29524 = qcar(v_29522);
    goto v_29312;
v_29313:
    v_29522 = stack[-2];
    v_29523 = qcdr(v_29522);
    goto v_29314;
v_29315:
    v_29522 = stack[-3];
    goto v_29316;
v_29317:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    goto v_29315;
v_29316:
    {
        fn = elt(env, 18); // prinidop
        return (*qfnn(fn))(fn, 3, v_29524, v_29523, v_29522);
    }
v_29300:
    v_29522 = stack[-2];
    v_29522 = qcar(v_29522);
    if (!symbolp(v_29522)) v_29522 = nil;
    else { v_29522 = qfastgets(v_29522);
           if (v_29522 != nil) { v_29522 = elt(v_29522, 23); // infix
#ifdef RECORD_GET
             if (v_29522 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_29522 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_29522 == SPID_NOPROP) v_29522 = nil; }}
#endif
    stack[-3] = v_29522;
    if (v_29522 == nil) goto v_29324;
    goto v_29163;
v_29324:
    goto v_29334;
v_29330:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29331;
v_29332:
    v_29522 = elt(env, 5); // !:rd!:
    goto v_29333;
v_29334:
    goto v_29330;
v_29331:
    goto v_29332;
v_29333:
    if (v_29523 == v_29522) goto v_29328;
    else goto v_29329;
v_29328:
// Binding !*nat
// FLUIDBIND: reloadenv=4 litvec-offset=6 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 6, -1);
    qvalue(elt(env, 6)) = nil; // !*nat
    v_29522 = stack[-2];
    v_29522 = qcdr(v_29522);
    v_29522 = Lfloatp(nil, v_29522);
    env = stack[-4];
    if (v_29522 == nil) goto v_29345;
    v_29522 = stack[-2];
    v_29522 = qcdr(v_29522);
    v_29522 = Llengthc(nil, v_29522);
    env = stack[-4];
    goto v_29343;
v_29345:
    goto v_29359;
v_29355:
    v_29522 = stack[-2];
    v_29522 = qcdr(v_29522);
    v_29522 = qcar(v_29522);
    stack[0] = Llengthc(nil, v_29522);
    env = stack[-4];
    goto v_29356;
v_29357:
    goto v_29369;
v_29365:
    v_29522 = stack[-2];
    v_29522 = qcdr(v_29522);
    v_29522 = qcdr(v_29522);
    v_29523 = Llengthc(nil, v_29522);
    env = stack[-4];
    goto v_29366;
v_29367:
    v_29522 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_29368;
v_29369:
    goto v_29365;
v_29366:
    goto v_29367;
v_29368:
    v_29522 = plus2(v_29523, v_29522);
    env = stack[-4];
    goto v_29358;
v_29359:
    goto v_29355;
v_29356:
    goto v_29357;
v_29358:
    v_29522 = plus2(stack[0], v_29522);
    env = stack[-4];
    goto v_29343;
    v_29522 = nil;
v_29343:
    stack[0] = v_29522;
    goto v_29384;
v_29380:
    goto v_29390;
v_29386:
    v_29523 = qvalue(elt(env, 7)); // ncharspr!*
    goto v_29387;
v_29388:
    v_29522 = stack[0];
    goto v_29389;
v_29390:
    goto v_29386;
v_29387:
    goto v_29388;
v_29389:
    v_29523 = plus2(v_29523, v_29522);
    env = stack[-4];
    goto v_29381;
v_29382:
    v_29522 = qvalue(elt(env, 8)); // laline!*
    goto v_29383;
v_29384:
    goto v_29380;
v_29381:
    goto v_29382;
v_29383:
    v_29522 = (LispObject)greaterp2(v_29523, v_29522);
    v_29522 = v_29522 ? lisp_true : nil;
    env = stack[-4];
    if (v_29522 == nil) goto v_29378;
    v_29522 = Lterpri(nil, 0);
    env = stack[-4];
    v_29522 = stack[0];
    qvalue(elt(env, 7)) = v_29522; // ncharspr!*
    goto v_29376;
v_29378:
    goto v_29403;
v_29399:
    v_29523 = qvalue(elt(env, 7)); // ncharspr!*
    goto v_29400;
v_29401:
    v_29522 = stack[0];
    goto v_29402;
v_29403:
    goto v_29399;
v_29400:
    goto v_29401;
v_29402:
    v_29522 = plus2(v_29523, v_29522);
    env = stack[-4];
    qvalue(elt(env, 7)) = v_29522; // ncharspr!*
    goto v_29376;
v_29376:
    v_29522 = qvalue(elt(env, 9)); // orig!*
    qvalue(elt(env, 10)) = v_29522; // posn!*
    v_29522 = stack[-2];
    fn = elt(env, 19); // rd!:prin
    v_29522 = (*qfn1(fn))(fn, v_29522);
    v_29522 = nil;
    ;}  // end of a binding scope
    goto v_29162;
v_29329:
    v_29522 = stack[-2];
    v_29522 = qcar(v_29522);
    fn = elt(env, 20); // oprinla
    v_29522 = (*qfn1(fn))(fn, v_29522);
    env = stack[-4];
    goto v_29419;
v_29413:
    v_29522 = stack[-2];
    v_29524 = qcar(v_29522);
    goto v_29414;
v_29415:
    v_29522 = stack[-2];
    v_29523 = qcdr(v_29522);
    goto v_29416;
v_29417:
    v_29522 = stack[-1];
    goto v_29418;
v_29419:
    goto v_29413;
v_29414:
    goto v_29415;
v_29416:
    goto v_29417;
v_29418:
    fn = elt(env, 21); // prinpopargs
    v_29522 = (*qfnn(fn))(fn, 3, v_29524, v_29523, v_29522);
    v_29522 = stack[-2];
    goto v_29162;
v_29163:
    goto v_29431;
v_29427:
    v_29523 = stack[-3];
    goto v_29428;
v_29429:
    v_29522 = stack[-1];
    goto v_29430;
v_29431:
    goto v_29427;
v_29428:
    goto v_29429;
v_29430:
    v_29522 = (LispObject)greaterp2(v_29523, v_29522);
    v_29522 = v_29522 ? lisp_true : nil;
    env = stack[-4];
    stack[-1] = v_29522;
    v_29522 = stack[-1];
    if (v_29522 == nil) goto v_29440;
    else goto v_29441;
v_29440:
    goto v_29447;
v_29443:
    v_29522 = stack[-2];
    v_29523 = qcar(v_29522);
    goto v_29444;
v_29445:
    v_29522 = elt(env, 11); // equal
    goto v_29446;
v_29447:
    goto v_29443;
v_29444:
    goto v_29445;
v_29446:
    v_29522 = (v_29523 == v_29522 ? lisp_true : nil);
    goto v_29439;
v_29441:
    v_29522 = nil;
    goto v_29439;
    v_29522 = nil;
v_29439:
    if (v_29522 == nil) goto v_29437;
    v_29522 = lisp_true;
    stack[-1] = v_29522;
    goto v_29435;
v_29437:
v_29435:
    v_29522 = stack[-1];
    if (v_29522 == nil) goto v_29459;
    goto v_29164;
v_29459:
    v_29522 = elt(env, 12); // !(
    fn = elt(env, 15); // prinlatom
    v_29522 = (*qfn1(fn))(fn, v_29522);
    env = stack[-4];
v_29164:
    goto v_29470;
v_29464:
    v_29522 = stack[-2];
    v_29524 = qcar(v_29522);
    goto v_29465;
v_29466:
    v_29523 = stack[-3];
    goto v_29467;
v_29468:
    v_29522 = stack[-2];
    v_29522 = qcdr(v_29522);
    goto v_29469;
v_29470:
    goto v_29464;
v_29465:
    goto v_29466;
v_29467:
    goto v_29468;
v_29469:
    fn = elt(env, 22); // inprinla
    v_29522 = (*qfnn(fn))(fn, 3, v_29524, v_29523, v_29522);
    env = stack[-4];
    v_29522 = stack[-1];
    if (v_29522 == nil) goto v_29479;
    v_29522 = stack[-2];
    goto v_29162;
v_29479:
    v_29522 = elt(env, 13); // !)
    fn = elt(env, 15); // prinlatom
    v_29522 = (*qfn1(fn))(fn, v_29522);
    v_29522 = stack[-2];
    goto v_29162;
v_29165:
    goto v_29498;
v_29494:
    v_29523 = stack[-2];
    goto v_29495;
v_29496:
    v_29522 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29497;
v_29498:
    goto v_29494;
v_29495:
    goto v_29496;
v_29497:
    v_29522 = (LispObject)lessp2(v_29523, v_29522);
    v_29522 = v_29522 ? lisp_true : nil;
    env = stack[-4];
    if (v_29522 == nil) goto v_29491;
    else goto v_29492;
v_29491:
    v_29522 = lisp_true;
    goto v_29490;
v_29492:
    goto v_29509;
v_29505:
    v_29523 = stack[-1];
    goto v_29506;
v_29507:
    v_29522 = elt(env, 14); // minus
    if (!symbolp(v_29522)) v_29522 = nil;
    else { v_29522 = qfastgets(v_29522);
           if (v_29522 != nil) { v_29522 = elt(v_29522, 23); // infix
#ifdef RECORD_GET
             if (v_29522 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_29522 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_29522 == SPID_NOPROP) v_29522 = nil; }}
#endif
    goto v_29508;
v_29509:
    goto v_29505;
v_29506:
    goto v_29507;
v_29508:
    v_29522 = (LispObject)lessp2(v_29523, v_29522);
    v_29522 = v_29522 ? lisp_true : nil;
    env = stack[-4];
    goto v_29490;
    v_29522 = nil;
v_29490:
    if (v_29522 == nil) goto v_29488;
    v_29522 = stack[-2];
    {
        fn = elt(env, 16); // prin2la
        return (*qfn1(fn))(fn, v_29522);
    }
v_29488:
    v_29522 = elt(env, 12); // !(
    fn = elt(env, 16); // prin2la
    v_29522 = (*qfn1(fn))(fn, v_29522);
    env = stack[-4];
    v_29522 = stack[-2];
    fn = elt(env, 16); // prin2la
    v_29522 = (*qfn1(fn))(fn, v_29522);
    env = stack[-4];
    v_29522 = elt(env, 13); // !)
    fn = elt(env, 16); // prin2la
    v_29522 = (*qfn1(fn))(fn, v_29522);
    v_29522 = stack[-2];
v_29162:
    return onevalue(v_29522);
}



// Code for !:log10

static LispObject CC_Tlog10(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29199, v_29200;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    goto v_29167;
v_29163:
    v_29200 = elt(env, 0); // !:log10
    goto v_29164;
v_29165:
    v_29199 = stack[0];
    goto v_29166;
v_29167:
    goto v_29163;
v_29164:
    goto v_29165;
v_29166:
    fn = elt(env, 3); // get!:const
    v_29199 = (*qfn2(fn))(fn, v_29200, v_29199);
    env = stack[-2];
    stack[-1] = v_29199;
    goto v_29178;
v_29174:
    v_29200 = stack[-1];
    goto v_29175;
v_29176:
    v_29199 = elt(env, 1); // not_found
    goto v_29177;
v_29178:
    goto v_29174;
v_29175:
    goto v_29176;
v_29177:
    if (v_29200 == v_29199) goto v_29173;
    v_29199 = stack[-1];
    goto v_29161;
v_29173:
    goto v_29187;
v_29183:
    v_29200 = qvalue(elt(env, 2)); // bften!*
    goto v_29184;
v_29185:
    v_29199 = stack[0];
    goto v_29186;
v_29187:
    goto v_29183;
v_29184:
    goto v_29185;
v_29186:
    fn = elt(env, 4); // log!:
    v_29199 = (*qfn2(fn))(fn, v_29200, v_29199);
    env = stack[-2];
    stack[-1] = v_29199;
    goto v_29195;
v_29191:
    v_29200 = elt(env, 0); // !:log10
    goto v_29192;
v_29193:
    v_29199 = stack[-1];
    goto v_29194;
v_29195:
    goto v_29191;
v_29192:
    goto v_29193;
v_29194:
    fn = elt(env, 5); // save!:const
    v_29199 = (*qfn2(fn))(fn, v_29200, v_29199);
    v_29199 = stack[-1];
v_29161:
    return onevalue(v_29199);
}



// Code for pnth!*

static LispObject CC_pnthH(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29185, v_29186, v_29187;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29186 = v_29158;
    stack[0] = v_29157;
// end of prologue
v_29162:
    v_29185 = stack[0];
    if (v_29185 == nil) goto v_29165;
    else goto v_29166;
v_29165:
    v_29185 = nil;
    goto v_29161;
v_29166:
    goto v_29175;
v_29171:
    v_29187 = v_29186;
    goto v_29172;
v_29173:
    v_29185 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29174;
v_29175:
    goto v_29171;
v_29172:
    goto v_29173;
v_29174:
    if (v_29187 == v_29185) goto v_29169;
    else goto v_29170;
v_29169:
    v_29185 = stack[0];
    goto v_29161;
v_29170:
    v_29185 = stack[0];
    v_29185 = qcdr(v_29185);
    stack[0] = v_29185;
    v_29185 = v_29186;
    v_29185 = sub1(v_29185);
    env = stack[-1];
    v_29186 = v_29185;
    goto v_29162;
    v_29185 = nil;
v_29161:
    return onevalue(v_29185);
}



// Code for sub01

static LispObject CC_sub01(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29198, v_29199, v_29200;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29158;
    stack[-1] = v_29157;
// end of prologue
    v_29200 = nil;
v_29163:
    v_29198 = stack[0];
    if (v_29198 == nil) goto v_29167;
    goto v_29174;
v_29170:
    goto v_29183;
v_29179:
    v_29198 = stack[0];
    v_29199 = qcar(v_29198);
    goto v_29180;
v_29181:
    v_29198 = stack[-1];
    goto v_29182;
v_29183:
    goto v_29179;
v_29180:
    goto v_29181;
v_29182:
    if (equal(v_29199, v_29198)) goto v_29177;
    else goto v_29178;
v_29177:
    v_29198 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29176;
v_29178:
    v_29198 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29176;
    v_29198 = nil;
v_29176:
    goto v_29171;
v_29172:
    v_29199 = v_29200;
    goto v_29173;
v_29174:
    goto v_29170;
v_29171:
    goto v_29172;
v_29173:
    v_29198 = cons(v_29198, v_29199);
    env = stack[-2];
    v_29200 = v_29198;
    v_29198 = stack[0];
    v_29198 = qcdr(v_29198);
    stack[0] = v_29198;
    goto v_29163;
v_29167:
    v_29198 = v_29200;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29198);
    }
    v_29198 = nil;
    return onevalue(v_29198);
}



// Code for replace!-next

static LispObject CC_replaceKnext(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29208, v_29209, v_29210, v_29211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29158;
    stack[-1] = v_29157;
// end of prologue
    stack[-2] = nil;
v_29163:
    v_29208 = stack[-1];
    if (v_29208 == nil) goto v_29166;
    else goto v_29167;
v_29166:
    v_29208 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29208);
    }
v_29167:
    goto v_29178;
v_29174:
    goto v_29188;
v_29180:
    v_29208 = stack[-1];
    v_29208 = qcar(v_29208);
    v_29211 = qcar(v_29208);
    goto v_29181;
v_29182:
    v_29208 = stack[-1];
    v_29208 = qcar(v_29208);
    v_29208 = qcdr(v_29208);
    v_29210 = qcar(v_29208);
    goto v_29183;
v_29184:
    v_29208 = stack[-1];
    v_29208 = qcar(v_29208);
    v_29208 = qcdr(v_29208);
    v_29208 = qcdr(v_29208);
    v_29209 = qcar(v_29208);
    goto v_29185;
v_29186:
    v_29208 = stack[0];
    v_29208 = qcar(v_29208);
    goto v_29187;
v_29188:
    goto v_29180;
v_29181:
    goto v_29182;
v_29183:
    goto v_29184;
v_29185:
    goto v_29186;
v_29187:
    v_29209 = list4(v_29211, v_29210, v_29209, v_29208);
    env = stack[-3];
    goto v_29175;
v_29176:
    v_29208 = stack[-2];
    goto v_29177;
v_29178:
    goto v_29174;
v_29175:
    goto v_29176;
v_29177:
    v_29208 = cons(v_29209, v_29208);
    env = stack[-3];
    stack[-2] = v_29208;
    v_29208 = stack[-1];
    v_29208 = qcdr(v_29208);
    stack[-1] = v_29208;
    v_29208 = stack[0];
    v_29208 = qcdr(v_29208);
    stack[0] = v_29208;
    goto v_29163;
    v_29208 = nil;
    return onevalue(v_29208);
}



// Code for mk!+inner!+product

static LispObject CC_mkLinnerLproduct(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29254, v_29255;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_29158;
    stack[-3] = v_29157;
// end of prologue
    goto v_29173;
v_29169:
    v_29254 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(fn, v_29254);
    env = stack[-5];
    goto v_29170;
v_29171:
    v_29254 = stack[-1];
    fn = elt(env, 4); // get!+vec!+dim
    v_29254 = (*qfn1(fn))(fn, v_29254);
    env = stack[-5];
    goto v_29172;
v_29173:
    goto v_29169;
v_29170:
    goto v_29171;
v_29172:
    if (equal(stack[0], v_29254)) goto v_29168;
    v_29254 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 5); // rederr
    v_29254 = (*qfn1(fn))(fn, v_29254);
    env = stack[-5];
    goto v_29166;
v_29168:
v_29166:
    goto v_29185;
v_29181:
    v_29255 = nil;
    goto v_29182;
v_29183:
    v_29254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29184;
v_29185:
    goto v_29181;
v_29182:
    goto v_29183;
v_29184:
    v_29254 = cons(v_29255, v_29254);
    env = stack[-5];
    stack[0] = v_29254;
    v_29254 = qvalue(elt(env, 2)); // !*complex
    if (v_29254 == nil) goto v_29191;
    v_29254 = stack[-1];
    fn = elt(env, 6); // mk!+conjugate!+vec
    v_29254 = (*qfn1(fn))(fn, v_29254);
    env = stack[-5];
    stack[-4] = v_29254;
    goto v_29189;
v_29191:
    v_29254 = stack[-1];
    stack[-4] = v_29254;
    goto v_29189;
v_29189:
    v_29254 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_29254;
v_29201:
    goto v_29213;
v_29209:
    v_29254 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    v_29255 = (*qfn1(fn))(fn, v_29254);
    env = stack[-5];
    goto v_29210;
v_29211:
    v_29254 = stack[-2];
    goto v_29212;
v_29213:
    goto v_29209;
v_29210:
    goto v_29211;
v_29212:
    v_29254 = difference2(v_29255, v_29254);
    env = stack[-5];
    v_29254 = Lminusp(nil, v_29254);
    env = stack[-5];
    if (v_29254 == nil) goto v_29206;
    goto v_29200;
v_29206:
    goto v_29223;
v_29219:
    stack[-1] = stack[0];
    goto v_29220;
v_29221:
    goto v_29230;
v_29226:
    goto v_29236;
v_29232:
    v_29255 = stack[-3];
    goto v_29233;
v_29234:
    v_29254 = stack[-2];
    goto v_29235;
v_29236:
    goto v_29232;
v_29233:
    goto v_29234;
v_29235:
    fn = elt(env, 7); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(fn, v_29255, v_29254);
    env = stack[-5];
    goto v_29227;
v_29228:
    goto v_29244;
v_29240:
    v_29255 = stack[-4];
    goto v_29241;
v_29242:
    v_29254 = stack[-2];
    goto v_29243;
v_29244:
    goto v_29240;
v_29241:
    goto v_29242;
v_29243:
    fn = elt(env, 7); // get!+vec!+entry
    v_29254 = (*qfn2(fn))(fn, v_29255, v_29254);
    env = stack[-5];
    goto v_29229;
v_29230:
    goto v_29226;
v_29227:
    goto v_29228;
v_29229:
    fn = elt(env, 8); // multsq
    v_29254 = (*qfn2(fn))(fn, stack[0], v_29254);
    env = stack[-5];
    goto v_29222;
v_29223:
    goto v_29219;
v_29220:
    goto v_29221;
v_29222:
    fn = elt(env, 9); // addsq
    v_29254 = (*qfn2(fn))(fn, stack[-1], v_29254);
    env = stack[-5];
    stack[0] = v_29254;
    v_29254 = stack[-2];
    v_29254 = add1(v_29254);
    env = stack[-5];
    stack[-2] = v_29254;
    goto v_29201;
v_29200:
    v_29254 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 3, -1);
    qvalue(elt(env, 3)) = v_29254; // !*sub2
    v_29254 = stack[0];
    fn = elt(env, 10); // subs2
    v_29254 = (*qfn1(fn))(fn, v_29254);
    stack[0] = v_29254;
    ;}  // end of a binding scope
    v_29254 = stack[0];
    return onevalue(v_29254);
}



// Code for dim!<!=deg

static LispObject CC_dimRMdeg(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29195, v_29196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29195 = v_29157;
// end of prologue
    goto v_29164;
v_29160:
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    goto v_29161;
v_29162:
    fn = elt(env, 2); // deg!*form
    v_29195 = (*qfn1(fn))(fn, v_29195);
    env = stack[-1];
    fn = elt(env, 3); // negf
    v_29195 = (*qfn1(fn))(fn, v_29195);
    env = stack[-1];
    goto v_29163;
v_29164:
    goto v_29160;
v_29161:
    goto v_29162;
v_29163:
    fn = elt(env, 4); // addf
    v_29195 = (*qfn2(fn))(fn, stack[0], v_29195);
    v_29196 = v_29195;
    v_29195 = v_29196;
    if (v_29195 == nil) goto v_29172;
    else goto v_29173;
v_29172:
    v_29195 = lisp_true;
    goto v_29171;
v_29173:
    v_29195 = v_29196;
    v_29195 = integerp(v_29195);
    if (v_29195 == nil) goto v_29180;
    else goto v_29181;
v_29180:
    v_29195 = nil;
    goto v_29179;
v_29181:
    goto v_29192;
v_29188:
    goto v_29189;
v_29190:
    v_29195 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29191;
v_29192:
    goto v_29188;
v_29189:
    goto v_29190;
v_29191:
        return Lleq(nil, v_29196, v_29195);
    v_29195 = nil;
v_29179:
    goto v_29171;
    v_29195 = nil;
v_29171:
    return onevalue(v_29195);
}



// Code for endofstmtp

static LispObject CC_endofstmtp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29171, v_29172;
    argcheck(nargs, 0, "endofstmtp");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_29166;
v_29162:
    v_29171 = qvalue(elt(env, 1)); // cursym!*
    goto v_29163;
v_29164:
    v_29172 = elt(env, 2); // (!*semicol!* !*rsqbkt!* end)
    goto v_29165;
v_29166:
    goto v_29162;
v_29163:
    goto v_29164;
v_29165:
    v_29171 = Lmember(nil, v_29171, v_29172);
    if (v_29171 == nil) goto v_29161;
    v_29171 = lisp_true;
    goto v_29159;
v_29161:
    v_29171 = nil;
v_29159:
    return onevalue(v_29171);
}



// Code for mk_parents_prim

static LispObject CC_mk_parents_prim(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29195, v_29196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    goto v_29167;
v_29163:
    v_29195 = stack[0];
    v_29196 = Llength(nil, v_29195);
    env = stack[-1];
    goto v_29164;
v_29165:
    v_29195 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_29166;
v_29167:
    goto v_29163;
v_29164:
    goto v_29165;
v_29166:
    if (v_29196 == v_29195) goto v_29162;
    v_29195 = stack[0];
    goto v_29160;
v_29162:
    v_29195 = stack[0];
    fn = elt(env, 1); // s_noparents
    v_29195 = (*qfn1(fn))(fn, v_29195);
    env = stack[-1];
    v_29196 = v_29195;
    if (v_29196 == nil) goto v_29179;
    else goto v_29180;
v_29179:
    v_29195 = stack[0];
    goto v_29178;
v_29180:
    goto v_29190;
v_29186:
    v_29196 = stack[0];
    goto v_29187;
v_29188:
    v_29195 = qcar(v_29195);
    goto v_29189;
v_29190:
    goto v_29186;
v_29187:
    goto v_29188;
v_29189:
    fn = elt(env, 2); // mk_edge_parents
    v_29195 = (*qfn2(fn))(fn, v_29196, v_29195);
    v_29195 = stack[0];
    goto v_29178;
    v_29195 = nil;
v_29178:
    goto v_29160;
    v_29195 = nil;
v_29160:
    return onevalue(v_29195);
}



// Code for fs!:zerop!:

static LispObject CC_fsTzeropT(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29221, v_29222, v_29223;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29222 = v_29157;
// end of prologue
    v_29221 = v_29222;
    if (v_29221 == nil) goto v_29161;
    else goto v_29162;
v_29161:
    v_29221 = lisp_true;
    goto v_29160;
v_29162:
    v_29221 = v_29222;
    if (is_number(v_29221)) goto v_29174;
    v_29221 = v_29222;
    v_29221 = qcdr(v_29221);
    v_29221 = (v_29221 == nil ? lisp_true : nil);
    goto v_29172;
v_29174:
    v_29221 = nil;
    goto v_29172;
    v_29221 = nil;
v_29172:
    if (v_29221 == nil) goto v_29170;
    v_29221 = lisp_true;
    goto v_29168;
v_29170:
    goto v_29193;
v_29189:
    v_29221 = v_29222;
    v_29223 = qcdr(v_29221);
    goto v_29190;
v_29191:
    v_29221 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_29192;
v_29193:
    goto v_29189;
v_29190:
    goto v_29191;
v_29192:
    v_29221 = *(LispObject *)((char *)v_29223 + (CELL-TAG_VECTOR) + (((intptr_t)v_29221-TAG_FIXNUM)/(16/CELL)));
    if (v_29221 == nil) goto v_29187;
    else goto v_29188;
v_29187:
    goto v_29202;
v_29198:
    v_29221 = v_29222;
    v_29222 = qcdr(v_29221);
    goto v_29199;
v_29200:
    v_29221 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29201;
v_29202:
    goto v_29198;
v_29199:
    goto v_29200;
v_29201:
    v_29221 = *(LispObject *)((char *)v_29222 + (CELL-TAG_VECTOR) + (((intptr_t)v_29221-TAG_FIXNUM)/(16/CELL)));
    v_29222 = v_29221;
    v_29221 = v_29222;
    if (is_number(v_29221)) goto v_29211;
    v_29221 = nil;
    goto v_29209;
v_29211:
    v_29221 = v_29222;
        return Lzerop(nil, v_29221);
    v_29221 = nil;
v_29209:
    goto v_29186;
v_29188:
    v_29221 = nil;
    goto v_29186;
    v_29221 = nil;
v_29186:
    goto v_29168;
    v_29221 = nil;
v_29168:
    goto v_29160;
    v_29221 = nil;
v_29160:
    return onevalue(v_29221);
}



// Code for monic

static LispObject CC_monic(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29190, v_29191, v_29192;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29190 = v_29158;
    stack[0] = v_29157;
// end of prologue
    goto v_29172;
v_29166:
    v_29192 = elt(env, 1); // lcof
    goto v_29167;
v_29168:
    v_29191 = stack[0];
    goto v_29169;
v_29170:
    goto v_29171;
v_29172:
    goto v_29166;
v_29167:
    goto v_29168;
v_29169:
    goto v_29170;
v_29171:
    v_29190 = list3(v_29192, v_29191, v_29190);
    env = stack[-1];
    fn = elt(env, 3); // aeval
    v_29190 = (*qfn1(fn))(fn, v_29190);
    env = stack[-1];
    goto v_29184;
v_29178:
    v_29192 = elt(env, 2); // quotient
    goto v_29179;
v_29180:
    v_29191 = stack[0];
    goto v_29181;
v_29182:
    goto v_29183;
v_29184:
    goto v_29178;
v_29179:
    goto v_29180;
v_29181:
    goto v_29182;
v_29183:
    v_29190 = list3(v_29192, v_29191, v_29190);
    env = stack[-1];
    fn = elt(env, 3); // aeval
    v_29190 = (*qfn1(fn))(fn, v_29190);
    env = stack[-1];
    stack[0] = v_29190;
    v_29190 = stack[0];
    {
        fn = elt(env, 3); // aeval
        return (*qfn1(fn))(fn, v_29190);
    }
    return onevalue(v_29190);
}



// Code for st_sorttree1

static LispObject CC_st_sorttree1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29667, v_29668, v_29669;
    LispObject fn;
    LispObject v_29159, v_29158, v_29157;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_sorttree1");
    va_start(aa, nargs);
    v_29157 = va_arg(aa, LispObject);
    v_29158 = va_arg(aa, LispObject);
    v_29159 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29159,v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29157,v_29158,v_29159);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-8] = v_29159;
    stack[-9] = v_29158;
    stack[-10] = v_29157;
// end of prologue
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v_29667 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_29667;
    v_29667 = stack[-10];
    v_29667 = qcdr(v_29667);
    v_29667 = qcar(v_29667);
    if (is_number(v_29667)) goto v_29171;
    else goto v_29172;
v_29171:
    goto v_29184;
v_29180:
    v_29667 = stack[-10];
    v_29668 = qcar(v_29667);
    goto v_29181;
v_29182:
    v_29667 = elt(env, 1); // !*
    goto v_29183;
v_29184:
    goto v_29180;
v_29181:
    goto v_29182;
v_29183:
    if (v_29668 == v_29667) goto v_29178;
    else goto v_29179;
v_29178:
    v_29667 = stack[-10];
    v_29667 = qcdr(v_29667);
    stack[-4] = v_29667;
    v_29667 = stack[-4];
    if (v_29667 == nil) goto v_29198;
    else goto v_29199;
v_29198:
    v_29667 = nil;
    goto v_29192;
v_29199:
    v_29667 = stack[-4];
    v_29667 = qcar(v_29667);
    goto v_29210;
v_29206:
    stack[0] = stack[-9];
    goto v_29207;
v_29208:
    v_29667 = sub1(v_29667);
    env = stack[-12];
    goto v_29209;
v_29210:
    goto v_29206;
v_29207:
    goto v_29208;
v_29209:
    v_29667 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29667-TAG_FIXNUM)/(16/CELL)));
    v_29667 = ncons(v_29667);
    env = stack[-12];
    stack[-2] = v_29667;
    stack[-3] = v_29667;
v_29193:
    v_29667 = stack[-4];
    v_29667 = qcdr(v_29667);
    stack[-4] = v_29667;
    v_29667 = stack[-4];
    if (v_29667 == nil) goto v_29219;
    else goto v_29220;
v_29219:
    v_29667 = stack[-3];
    goto v_29192;
v_29220:
    goto v_29228;
v_29224:
    stack[-1] = stack[-2];
    goto v_29225;
v_29226:
    v_29667 = stack[-4];
    v_29667 = qcar(v_29667);
    goto v_29238;
v_29234:
    stack[0] = stack[-9];
    goto v_29235;
v_29236:
    v_29667 = sub1(v_29667);
    env = stack[-12];
    goto v_29237;
v_29238:
    goto v_29234;
v_29235:
    goto v_29236;
v_29237:
    v_29667 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29667-TAG_FIXNUM)/(16/CELL)));
    v_29667 = ncons(v_29667);
    env = stack[-12];
    goto v_29227;
v_29228:
    goto v_29224;
v_29225:
    goto v_29226;
v_29227:
    v_29667 = Lrplacd(nil, stack[-1], v_29667);
    env = stack[-12];
    v_29667 = stack[-2];
    v_29667 = qcdr(v_29667);
    stack[-2] = v_29667;
    goto v_29193;
v_29192:
    stack[-11] = v_29667;
    goto v_29252;
v_29246:
    v_29669 = stack[-11];
    goto v_29247;
v_29248:
    v_29668 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29249;
v_29250:
    v_29667 = stack[-10];
    goto v_29251;
v_29252:
    goto v_29246;
v_29247:
    goto v_29248;
v_29249:
    goto v_29250;
v_29251:
    return list2star(v_29669, v_29668, v_29667);
v_29179:
    v_29667 = stack[-10];
    v_29667 = qcdr(v_29667);
    stack[-5] = v_29667;
    v_29667 = stack[-5];
    if (v_29667 == nil) goto v_29266;
    else goto v_29267;
v_29266:
    v_29667 = nil;
    goto v_29260;
v_29267:
    v_29667 = stack[-5];
    v_29667 = qcar(v_29667);
    goto v_29279;
v_29275:
    stack[-1] = v_29667;
    goto v_29276;
v_29277:
    goto v_29285;
v_29281:
    stack[0] = stack[-9];
    goto v_29282;
v_29283:
    v_29667 = sub1(v_29667);
    env = stack[-12];
    goto v_29284;
v_29285:
    goto v_29281;
v_29282:
    goto v_29283;
v_29284:
    v_29667 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29667-TAG_FIXNUM)/(16/CELL)));
    goto v_29278;
v_29279:
    goto v_29275;
v_29276:
    goto v_29277;
v_29278:
    v_29667 = cons(stack[-1], v_29667);
    env = stack[-12];
    v_29667 = ncons(v_29667);
    env = stack[-12];
    stack[-3] = v_29667;
    stack[-4] = v_29667;
v_29261:
    v_29667 = stack[-5];
    v_29667 = qcdr(v_29667);
    stack[-5] = v_29667;
    v_29667 = stack[-5];
    if (v_29667 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    v_29667 = stack[-4];
    goto v_29260;
v_29295:
    goto v_29303;
v_29299:
    stack[-2] = stack[-3];
    goto v_29300;
v_29301:
    v_29667 = stack[-5];
    v_29667 = qcar(v_29667);
    goto v_29314;
v_29310:
    stack[-1] = v_29667;
    goto v_29311;
v_29312:
    goto v_29320;
v_29316:
    stack[0] = stack[-9];
    goto v_29317;
v_29318:
    v_29667 = sub1(v_29667);
    env = stack[-12];
    goto v_29319;
v_29320:
    goto v_29316;
v_29317:
    goto v_29318;
v_29319:
    v_29667 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29667-TAG_FIXNUM)/(16/CELL)));
    goto v_29313;
v_29314:
    goto v_29310;
v_29311:
    goto v_29312;
v_29313:
    v_29667 = cons(stack[-1], v_29667);
    env = stack[-12];
    v_29667 = ncons(v_29667);
    env = stack[-12];
    goto v_29302;
v_29303:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    v_29667 = Lrplacd(nil, stack[-2], v_29667);
    env = stack[-12];
    v_29667 = stack[-3];
    v_29667 = qcdr(v_29667);
    stack[-3] = v_29667;
    goto v_29261;
v_29260:
    stack[-1] = v_29667;
    goto v_29170;
v_29172:
    goto v_29338;
v_29334:
    v_29667 = stack[-10];
    v_29668 = qcar(v_29667);
    goto v_29335;
v_29336:
    v_29667 = elt(env, 1); // !*
    goto v_29337;
v_29338:
    goto v_29334;
v_29335:
    goto v_29336;
v_29337:
    if (v_29668 == v_29667) goto v_29332;
    else goto v_29333;
v_29332:
    v_29667 = stack[-10];
    v_29667 = qcdr(v_29667);
    stack[0] = v_29667;
v_29345:
    v_29667 = stack[0];
    if (v_29667 == nil) goto v_29350;
    else goto v_29351;
v_29350:
    goto v_29344;
v_29351:
    v_29667 = stack[0];
    v_29667 = qcar(v_29667);
    v_29669 = v_29667;
    goto v_29365;
v_29361:
    v_29668 = stack[-6];
    goto v_29362;
v_29363:
    v_29667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29364;
v_29365:
    goto v_29361;
v_29362:
    goto v_29363;
v_29364:
    if (v_29668 == v_29667) goto v_29360;
    goto v_29375;
v_29369:
    goto v_29370;
v_29371:
    v_29668 = stack[-9];
    goto v_29372;
v_29373:
    v_29667 = stack[-8];
    goto v_29374;
v_29375:
    goto v_29369;
v_29370:
    goto v_29371;
v_29372:
    goto v_29373;
v_29374:
    v_29667 = CC_st_sorttree1(elt(env, 0), 3, v_29669, v_29668, v_29667);
    env = stack[-12];
    stack[-2] = v_29667;
    goto v_29384;
v_29380:
    v_29668 = stack[-6];
    goto v_29381;
v_29382:
    v_29667 = stack[-2];
    v_29667 = qcdr(v_29667);
    v_29667 = qcar(v_29667);
    goto v_29383;
v_29384:
    goto v_29380;
v_29381:
    goto v_29382;
v_29383:
    v_29667 = times2(v_29668, v_29667);
    env = stack[-12];
    stack[-6] = v_29667;
    goto v_29394;
v_29390:
    v_29667 = stack[-2];
    v_29668 = qcar(v_29667);
    goto v_29391;
v_29392:
    v_29667 = stack[-11];
    goto v_29393;
v_29394:
    goto v_29390;
v_29391:
    goto v_29392;
v_29393:
    v_29667 = cons(v_29668, v_29667);
    env = stack[-12];
    stack[-11] = v_29667;
    goto v_29403;
v_29399:
    v_29667 = stack[-2];
    v_29667 = qcdr(v_29667);
    v_29668 = qcdr(v_29667);
    goto v_29400;
v_29401:
    v_29667 = stack[-7];
    goto v_29402;
v_29403:
    goto v_29399;
v_29400:
    goto v_29401;
v_29402:
    v_29667 = cons(v_29668, v_29667);
    env = stack[-12];
    stack[-7] = v_29667;
    goto v_29358;
v_29360:
v_29358:
    v_29667 = stack[0];
    v_29667 = qcdr(v_29667);
    stack[0] = v_29667;
    goto v_29345;
v_29344:
    goto v_29419;
v_29415:
    v_29668 = stack[-6];
    goto v_29416;
v_29417:
    v_29667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29418;
v_29419:
    goto v_29415;
v_29416:
    goto v_29417;
v_29418:
    if (v_29668 == v_29667) goto v_29413;
    else goto v_29414;
v_29413:
    goto v_29429;
v_29423:
    v_29669 = nil;
    goto v_29424;
v_29425:
    v_29668 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29426;
v_29427:
    v_29667 = nil;
    goto v_29428;
v_29429:
    goto v_29423;
v_29424:
    goto v_29425;
v_29426:
    goto v_29427;
v_29428:
    return list2star(v_29669, v_29668, v_29667);
v_29414:
    v_29667 = stack[-7];
    v_29667 = Lreverse(nil, v_29667);
    env = stack[-12];
    stack[-7] = v_29667;
    v_29667 = stack[-11];
    v_29667 = Lreverse(nil, v_29667);
    env = stack[-12];
    stack[-11] = v_29667;
    goto v_29446;
v_29440:
    stack[0] = stack[-11];
    goto v_29441;
v_29442:
    stack[-1] = stack[-6];
    goto v_29443;
v_29444:
    goto v_29454;
v_29450:
    v_29668 = elt(env, 1); // !*
    goto v_29451;
v_29452:
    v_29667 = stack[-7];
    goto v_29453;
v_29454:
    goto v_29450;
v_29451:
    goto v_29452;
v_29453:
    v_29667 = cons(v_29668, v_29667);
    goto v_29445;
v_29446:
    goto v_29440;
v_29441:
    goto v_29442;
v_29443:
    goto v_29444;
v_29445:
    {
        LispObject v_29682 = stack[0];
        LispObject v_29683 = stack[-1];
        return list2star(v_29682, v_29683, v_29667);
    }
    goto v_29331;
v_29333:
v_29331:
    v_29667 = stack[-10];
    v_29667 = qcdr(v_29667);
    stack[0] = v_29667;
v_29461:
    v_29667 = stack[0];
    if (v_29667 == nil) goto v_29466;
    else goto v_29467;
v_29466:
    goto v_29460;
v_29467:
    v_29667 = stack[0];
    v_29667 = qcar(v_29667);
    v_29669 = v_29667;
    goto v_29481;
v_29477:
    v_29668 = stack[-6];
    goto v_29478;
v_29479:
    v_29667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29480;
v_29481:
    goto v_29477;
v_29478:
    goto v_29479;
v_29480:
    if (v_29668 == v_29667) goto v_29476;
    goto v_29491;
v_29485:
    goto v_29486;
v_29487:
    v_29668 = stack[-9];
    goto v_29488;
v_29489:
    v_29667 = stack[-8];
    goto v_29490;
v_29491:
    goto v_29485;
v_29486:
    goto v_29487;
v_29488:
    goto v_29489;
v_29490:
    v_29667 = CC_st_sorttree1(elt(env, 0), 3, v_29669, v_29668, v_29667);
    env = stack[-12];
    stack[-2] = v_29667;
    goto v_29500;
v_29496:
    v_29668 = stack[-6];
    goto v_29497;
v_29498:
    v_29667 = stack[-2];
    v_29667 = qcdr(v_29667);
    v_29667 = qcar(v_29667);
    goto v_29499;
v_29500:
    goto v_29496;
v_29497:
    goto v_29498;
v_29499:
    v_29667 = times2(v_29668, v_29667);
    env = stack[-12];
    stack[-6] = v_29667;
    goto v_29512;
v_29506:
    v_29667 = stack[-2];
    v_29667 = qcdr(v_29667);
    v_29669 = qcdr(v_29667);
    goto v_29507;
v_29508:
    v_29667 = stack[-2];
    v_29668 = qcar(v_29667);
    goto v_29509;
v_29510:
    v_29667 = stack[-1];
    goto v_29511;
v_29512:
    goto v_29506;
v_29507:
    goto v_29508;
v_29509:
    goto v_29510;
v_29511:
    v_29667 = acons(v_29669, v_29668, v_29667);
    env = stack[-12];
    stack[-1] = v_29667;
    goto v_29474;
v_29476:
v_29474:
    v_29667 = stack[0];
    v_29667 = qcdr(v_29667);
    stack[0] = v_29667;
    goto v_29461;
v_29460:
    goto v_29170;
v_29170:
    goto v_29531;
v_29527:
    v_29668 = stack[-6];
    goto v_29528;
v_29529:
    v_29667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29530;
v_29531:
    goto v_29527;
v_29528:
    goto v_29529;
v_29530:
    if (v_29668 == v_29667) goto v_29525;
    else goto v_29526;
v_29525:
    goto v_29541;
v_29535:
    v_29669 = nil;
    goto v_29536;
v_29537:
    v_29668 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29538;
v_29539:
    v_29667 = nil;
    goto v_29540;
v_29541:
    goto v_29535;
v_29536:
    goto v_29537;
v_29538:
    goto v_29539;
v_29540:
    return list2star(v_29669, v_29668, v_29667);
v_29526:
    goto v_29553;
v_29549:
    v_29667 = stack[-10];
    v_29668 = qcar(v_29667);
    goto v_29550;
v_29551:
    v_29667 = elt(env, 2); // !+
    goto v_29552;
v_29553:
    goto v_29549;
v_29550:
    goto v_29551;
v_29552:
    if (v_29668 == v_29667) goto v_29547;
    else goto v_29548;
v_29547:
    goto v_29562;
v_29558:
    v_29668 = stack[-1];
    goto v_29559;
v_29560:
    v_29667 = stack[-8];
    goto v_29561;
v_29562:
    goto v_29558;
v_29559:
    goto v_29560;
v_29561:
    fn = elt(env, 3); // cdr_sort
    v_29667 = (*qfn2(fn))(fn, v_29668, v_29667);
    env = stack[-12];
    stack[-1] = v_29667;
    goto v_29546;
v_29548:
    goto v_29572;
v_29568:
    v_29668 = stack[-1];
    goto v_29569;
v_29570:
    v_29667 = stack[-8];
    goto v_29571;
v_29572:
    goto v_29568;
v_29569:
    goto v_29570;
v_29571:
    fn = elt(env, 4); // cdr_signsort
    v_29667 = (*qfn2(fn))(fn, v_29668, v_29667);
    env = stack[-12];
    stack[-1] = v_29667;
    goto v_29583;
v_29579:
    v_29667 = stack[-1];
    v_29668 = qcar(v_29667);
    goto v_29580;
v_29581:
    v_29667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29582;
v_29583:
    goto v_29579;
v_29580:
    goto v_29581;
v_29582:
    if (v_29668 == v_29667) goto v_29577;
    else goto v_29578;
v_29577:
    goto v_29594;
v_29588:
    v_29669 = nil;
    goto v_29589;
v_29590:
    v_29668 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29591;
v_29592:
    v_29667 = nil;
    goto v_29593;
v_29594:
    goto v_29588;
v_29589:
    goto v_29590;
v_29591:
    goto v_29592;
v_29593:
    return list2star(v_29669, v_29668, v_29667);
v_29578:
    goto v_29605;
v_29601:
    v_29668 = stack[-6];
    goto v_29602;
v_29603:
    v_29667 = stack[-1];
    v_29667 = qcar(v_29667);
    goto v_29604;
v_29605:
    goto v_29601;
v_29602:
    goto v_29603;
v_29604:
    v_29667 = times2(v_29668, v_29667);
    env = stack[-12];
    stack[-6] = v_29667;
    goto v_29576;
v_29576:
    v_29667 = stack[-1];
    v_29667 = qcdr(v_29667);
    stack[-1] = v_29667;
    goto v_29546;
v_29546:
v_29614:
    v_29667 = stack[-1];
    if (v_29667 == nil) goto v_29617;
    else goto v_29618;
v_29617:
    goto v_29613;
v_29618:
    goto v_29626;
v_29622:
    v_29667 = stack[-1];
    v_29667 = qcar(v_29667);
    v_29668 = qcar(v_29667);
    goto v_29623;
v_29624:
    v_29667 = stack[-7];
    goto v_29625;
v_29626:
    goto v_29622;
v_29623:
    goto v_29624;
v_29625:
    v_29667 = cons(v_29668, v_29667);
    env = stack[-12];
    stack[-7] = v_29667;
    goto v_29636;
v_29632:
    v_29667 = stack[-1];
    v_29667 = qcar(v_29667);
    v_29668 = qcdr(v_29667);
    goto v_29633;
v_29634:
    v_29667 = stack[-11];
    goto v_29635;
v_29636:
    goto v_29632;
v_29633:
    goto v_29634;
v_29635:
    v_29667 = cons(v_29668, v_29667);
    env = stack[-12];
    stack[-11] = v_29667;
    v_29667 = stack[-1];
    v_29667 = qcdr(v_29667);
    stack[-1] = v_29667;
    goto v_29614;
v_29613:
    goto v_29649;
v_29645:
    v_29667 = stack[-10];
    stack[0] = qcar(v_29667);
    goto v_29646;
v_29647:
    v_29667 = stack[-7];
    v_29667 = Lreverse(nil, v_29667);
    env = stack[-12];
    goto v_29648;
v_29649:
    goto v_29645;
v_29646:
    goto v_29647;
v_29648:
    v_29667 = cons(stack[0], v_29667);
    env = stack[-12];
    stack[-7] = v_29667;
    v_29667 = stack[-11];
    v_29667 = Lreverse(nil, v_29667);
    stack[-11] = v_29667;
    goto v_29663;
v_29657:
    v_29669 = stack[-11];
    goto v_29658;
v_29659:
    v_29668 = stack[-6];
    goto v_29660;
v_29661:
    v_29667 = stack[-7];
    goto v_29662;
v_29663:
    goto v_29657;
v_29658:
    goto v_29659;
v_29660:
    goto v_29661;
v_29662:
    return list2star(v_29669, v_29668, v_29667);
    return onevalue(v_29667);
}



// Code for evaluate!-in!-vector

static LispObject CC_evaluateKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29210, v_29211, v_29212, v_29213, v_29214, v_29215;
    LispObject v_29159, v_29158, v_29157;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate-in-vector");
    va_start(aa, nargs);
    v_29157 = va_arg(aa, LispObject);
    v_29158 = va_arg(aa, LispObject);
    v_29159 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29159,v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29157,v_29158,v_29159);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29213 = v_29159;
    v_29212 = v_29158;
    v_29214 = v_29157;
// end of prologue
    goto v_29168;
v_29164:
    v_29211 = v_29214;
    goto v_29165;
v_29166:
    v_29210 = v_29212;
    goto v_29167;
v_29168:
    goto v_29164;
v_29165:
    goto v_29166;
v_29167:
    v_29210 = *(LispObject *)((char *)v_29211 + (CELL-TAG_VECTOR) + (((intptr_t)v_29210-TAG_FIXNUM)/(16/CELL)));
    v_29211 = v_29210;
    v_29210 = v_29212;
    v_29210 = (LispObject)((intptr_t)(v_29210) - 0x10);
    v_29215 = v_29210;
v_29175:
    v_29210 = v_29215;
    v_29210 = ((intptr_t)(v_29210) < 0 ? lisp_true : nil);
    if (v_29210 == nil) goto v_29181;
    goto v_29174;
v_29181:
    goto v_29189;
v_29185:
    goto v_29194;
v_29190:
    v_29212 = v_29214;
    goto v_29191;
v_29192:
    v_29210 = v_29215;
    goto v_29193;
v_29194:
    goto v_29190;
v_29191:
    goto v_29192;
v_29193:
    v_29212 = *(LispObject *)((char *)v_29212 + (CELL-TAG_VECTOR) + (((intptr_t)v_29210-TAG_FIXNUM)/(16/CELL)));
    goto v_29186;
v_29187:
    goto v_29203;
v_29199:
    goto v_29200;
v_29201:
    v_29210 = v_29213;
    goto v_29202;
v_29203:
    goto v_29199;
v_29200:
    goto v_29201;
v_29202:
    v_29210 = Lmodular_times(nil, v_29211, v_29210);
    env = stack[0];
    goto v_29188;
v_29189:
    goto v_29185;
v_29186:
    goto v_29187;
v_29188:
    {   intptr_t w = int_of_fixnum(v_29212) + int_of_fixnum(v_29210);
        if (w >= current_modulus) w -= current_modulus;
        v_29210 = fixnum_of_int(w);
    }
    v_29211 = v_29210;
    v_29210 = v_29215;
    v_29210 = (LispObject)((intptr_t)(v_29210) - 0x10);
    v_29215 = v_29210;
    goto v_29175;
v_29174:
    v_29210 = v_29211;
    return onevalue(v_29210);
}



// Code for bfrsq

static LispObject CC_bfrsq(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29216, v_29217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29217 = v_29157;
// end of prologue
    v_29216 = v_29217;
    v_29216 = qcar(v_29216);
    v_29217 = qcdr(v_29217);
    stack[-1] = v_29217;
    v_29217 = v_29216;
    if (!consp(v_29217)) goto v_29167;
    else goto v_29168;
v_29167:
    goto v_29175;
v_29171:
    goto v_29181;
v_29177:
    v_29217 = v_29216;
    goto v_29178;
v_29179:
    goto v_29180;
v_29181:
    goto v_29177;
v_29178:
    goto v_29179;
v_29180:
    stack[0] = times2(v_29217, v_29216);
    env = stack[-2];
    goto v_29172;
v_29173:
    goto v_29189;
v_29185:
    v_29217 = stack[-1];
    goto v_29186;
v_29187:
    v_29216 = stack[-1];
    goto v_29188;
v_29189:
    goto v_29185;
v_29186:
    goto v_29187;
v_29188:
    v_29216 = times2(v_29217, v_29216);
    goto v_29174;
v_29175:
    goto v_29171;
v_29172:
    goto v_29173;
v_29174:
    {
        LispObject v_29220 = stack[0];
        return plus2(v_29220, v_29216);
    }
v_29168:
    goto v_29199;
v_29195:
    goto v_29205;
v_29201:
    v_29217 = v_29216;
    goto v_29202;
v_29203:
    goto v_29204;
v_29205:
    goto v_29201;
v_29202:
    goto v_29203;
v_29204:
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(fn, v_29217, v_29216);
    env = stack[-2];
    goto v_29196;
v_29197:
    goto v_29213;
v_29209:
    v_29217 = stack[-1];
    goto v_29210;
v_29211:
    v_29216 = stack[-1];
    goto v_29212;
v_29213:
    goto v_29209;
v_29210:
    goto v_29211;
v_29212:
    fn = elt(env, 1); // csl_timbf
    v_29216 = (*qfn2(fn))(fn, v_29217, v_29216);
    env = stack[-2];
    goto v_29198;
v_29199:
    goto v_29195;
v_29196:
    goto v_29197;
v_29198:
    {
        LispObject v_29221 = stack[0];
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(fn, v_29221, v_29216);
    }
    v_29216 = nil;
    return onevalue(v_29216);
}



// Code for nextu

static LispObject CC_nextu(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29234, v_29235, v_29236;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29235 = v_29158;
    stack[0] = v_29157;
// end of prologue
    v_29234 = stack[0];
    if (v_29234 == nil) goto v_29162;
    else goto v_29163;
v_29162:
    v_29234 = nil;
    goto v_29161;
v_29163:
    goto v_29179;
v_29173:
    v_29236 = v_29235;
    goto v_29174;
v_29175:
    v_29234 = stack[0];
    v_29235 = qcar(v_29234);
    goto v_29176;
v_29177:
    v_29234 = nil;
    goto v_29178;
v_29179:
    goto v_29173;
v_29174:
    goto v_29175;
v_29176:
    goto v_29177;
v_29178:
    fn = elt(env, 1); // subtractinds
    v_29234 = (*qfnn(fn))(fn, 3, v_29236, v_29235, v_29234);
    env = stack[-2];
    stack[-1] = v_29234;
    v_29234 = stack[-1];
    if (v_29234 == nil) goto v_29186;
    else goto v_29187;
v_29186:
    v_29234 = nil;
    goto v_29171;
v_29187:
    goto v_29195;
v_29191:
    v_29234 = stack[0];
    v_29234 = qcdr(v_29234);
    v_29235 = qcar(v_29234);
    goto v_29192;
v_29193:
    v_29234 = stack[-1];
    goto v_29194;
v_29195:
    goto v_29191;
v_29192:
    goto v_29193;
v_29194:
    fn = elt(env, 2); // evaluatecoeffts
    v_29234 = (*qfn2(fn))(fn, v_29235, v_29234);
    v_29235 = v_29234;
    v_29234 = v_29235;
    if (v_29234 == nil) goto v_29206;
    else goto v_29207;
v_29206:
    v_29234 = lisp_true;
    goto v_29205;
v_29207:
    goto v_29216;
v_29212:
    v_29236 = v_29235;
    goto v_29213;
v_29214:
    v_29234 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29215;
v_29216:
    goto v_29212;
v_29213:
    goto v_29214;
v_29215:
    v_29234 = (v_29236 == v_29234 ? lisp_true : nil);
    goto v_29205;
    v_29234 = nil;
v_29205:
    if (v_29234 == nil) goto v_29203;
    v_29234 = nil;
    goto v_29171;
v_29203:
    goto v_29228;
v_29222:
    v_29236 = stack[-1];
    goto v_29223;
v_29224:
    goto v_29225;
v_29226:
    v_29234 = stack[0];
    v_29234 = qcdr(v_29234);
    v_29234 = qcdr(v_29234);
    goto v_29227;
v_29228:
    goto v_29222;
v_29223:
    goto v_29224;
v_29225:
    goto v_29226;
v_29227:
    return list2star(v_29236, v_29235, v_29234);
v_29171:
    goto v_29161;
    v_29234 = nil;
v_29161:
    return onevalue(v_29234);
}



// Code for talp_get!-idx

static LispObject CC_talp_getKidx(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29303, v_29304;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_29158;
    stack[-4] = v_29157;
// end of prologue
    stack[-5] = nil;
    v_29303 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_29303;
v_29167:
    goto v_29178;
v_29174:
    stack[0] = stack[-2];
    goto v_29175;
v_29176:
    v_29303 = stack[-3];
    v_29303 = Lupbv(nil, v_29303);
    env = stack[-6];
    goto v_29177;
v_29178:
    goto v_29174;
v_29175:
    goto v_29176;
v_29177:
    v_29303 = (LispObject)lesseq2(stack[0], v_29303);
    v_29303 = v_29303 ? lisp_true : nil;
    env = stack[-6];
    if (v_29303 == nil) goto v_29170;
    v_29303 = stack[-5];
    if (v_29303 == nil) goto v_29182;
    else goto v_29170;
v_29182:
    goto v_29171;
v_29170:
    goto v_29166;
v_29171:
    v_29303 = stack[-4];
    if (!consp(v_29303)) goto v_29187;
    else goto v_29188;
v_29187:
    goto v_29198;
v_29194:
    goto v_29203;
v_29199:
    v_29304 = stack[-3];
    goto v_29200;
v_29201:
    v_29303 = stack[-2];
    goto v_29202;
v_29203:
    goto v_29199;
v_29200:
    goto v_29201;
v_29202:
    v_29304 = *(LispObject *)((char *)v_29304 + (CELL-TAG_VECTOR) + (((intptr_t)v_29303-TAG_FIXNUM)/(16/CELL)));
    goto v_29195;
v_29196:
    v_29303 = stack[-4];
    goto v_29197;
v_29198:
    goto v_29194;
v_29195:
    goto v_29196;
v_29197:
    if (v_29304 == v_29303) goto v_29192;
    else goto v_29193;
v_29192:
    v_29303 = lisp_true;
    stack[-5] = v_29303;
    goto v_29191;
v_29193:
    v_29303 = stack[-2];
    v_29303 = add1(v_29303);
    env = stack[-6];
    stack[-2] = v_29303;
    goto v_29191;
v_29191:
    goto v_29186;
v_29188:
    v_29303 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    v_29303 = Lconsp(nil, v_29303);
    env = stack[-6];
    if (v_29303 == nil) goto v_29214;
    goto v_29222;
v_29218:
    v_29304 = stack[-3];
    goto v_29219;
v_29220:
    v_29303 = stack[-2];
    goto v_29221;
v_29222:
    goto v_29218;
v_29219:
    goto v_29220;
v_29221:
    v_29303 = *(LispObject *)((char *)v_29304 + (CELL-TAG_VECTOR) + (((intptr_t)v_29303-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_29303;
    v_29303 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    v_29303 = Lconsp(nil, v_29303);
    env = stack[-6];
    if (v_29303 == nil) goto v_29230;
    goto v_29244;
v_29240:
    v_29303 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    fn = elt(env, 2); // talp_invf
    stack[0] = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29241;
v_29242:
    v_29303 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    fn = elt(env, 2); // talp_invf
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29243;
v_29244:
    goto v_29240;
v_29241:
    goto v_29242;
v_29243:
    if (stack[0] == v_29303) goto v_29238;
    else goto v_29239;
v_29238:
    goto v_29255;
v_29251:
    v_29303 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    fn = elt(env, 3); // talp_invn
    stack[0] = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29252;
v_29253:
    v_29303 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    fn = elt(env, 3); // talp_invn
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29254;
v_29255:
    goto v_29251;
v_29252:
    goto v_29253;
v_29254:
    v_29303 = (stack[0] == v_29303 ? lisp_true : nil);
    goto v_29237;
v_29239:
    v_29303 = nil;
    goto v_29237;
    v_29303 = nil;
v_29237:
    if (v_29303 == nil) goto v_29230;
    v_29303 = lisp_true;
    stack[-5] = v_29303;
    goto v_29228;
v_29230:
    v_29303 = stack[-2];
    v_29303 = add1(v_29303);
    env = stack[-6];
    stack[-2] = v_29303;
    goto v_29228;
v_29228:
    goto v_29186;
v_29214:
    goto v_29277;
v_29273:
    goto v_29283;
v_29279:
    v_29304 = stack[-3];
    goto v_29280;
v_29281:
    v_29303 = stack[-2];
    goto v_29282;
v_29283:
    goto v_29279;
v_29280:
    goto v_29281;
v_29282:
    v_29303 = *(LispObject *)((char *)v_29304 + (CELL-TAG_VECTOR) + (((intptr_t)v_29303-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 1); // talp_fop
    stack[0] = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29274;
v_29275:
    v_29303 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29303 = (*qfn1(fn))(fn, v_29303);
    env = stack[-6];
    goto v_29276;
v_29277:
    goto v_29273;
v_29274:
    goto v_29275;
v_29276:
    if (stack[0] == v_29303) goto v_29271;
    else goto v_29272;
v_29271:
    v_29303 = lisp_true;
    stack[-5] = v_29303;
    goto v_29186;
v_29272:
    v_29303 = stack[-2];
    v_29303 = add1(v_29303);
    env = stack[-6];
    stack[-2] = v_29303;
    goto v_29186;
v_29186:
    goto v_29167;
v_29166:
    v_29303 = stack[-5];
    if (v_29303 == nil) goto v_29297;
    v_29303 = stack[-2];
    goto v_29295;
v_29297:
    v_29303 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_29295;
    v_29303 = nil;
v_29295:
    return onevalue(v_29303);
}



// Code for qqe_length!-graph!-neighbor!-edge

static LispObject CC_qqe_lengthKgraphKneighborKedge(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29163;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29163 = v_29157;
// end of prologue
    v_29163 = qcdr(v_29163);
    v_29163 = qcdr(v_29163);
    v_29163 = qcar(v_29163);
    return onevalue(v_29163);
}



// Code for pasf_dnf

static LispObject CC_pasf_dnf(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29183, v_29184;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    goto v_29168;
v_29164:
    v_29184 = stack[0];
    goto v_29165;
v_29166:
    v_29183 = elt(env, 1); // and
    goto v_29167;
v_29168:
    goto v_29164;
v_29165:
    goto v_29166;
v_29167:
    fn = elt(env, 3); // pasf_puregconp
    v_29183 = (*qfn2(fn))(fn, v_29184, v_29183);
    env = stack[-1];
    if (v_29183 == nil) goto v_29162;
    v_29183 = stack[0];
    goto v_29160;
v_29162:
    goto v_29179;
v_29175:
    v_29183 = stack[0];
    fn = elt(env, 4); // pasf_pnf
    v_29184 = (*qfn1(fn))(fn, v_29183);
    env = stack[-1];
    goto v_29176;
v_29177:
    v_29183 = elt(env, 2); // dnf
    goto v_29178;
v_29179:
    goto v_29175;
v_29176:
    goto v_29177;
v_29178:
    {
        fn = elt(env, 5); // pasf_pbnf
        return (*qfn2(fn))(fn, v_29184, v_29183);
    }
    v_29183 = nil;
v_29160:
    return onevalue(v_29183);
}



// Code for ofsf_pop

static LispObject CC_ofsf_pop(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29160;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29160 = v_29157;
// end of prologue
    return onevalue(v_29160);
}



// Code for ezgcd!-comfac

static LispObject CC_ezgcdKcomfac(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29325, v_29326, v_29327;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_29157;
// end of prologue
    v_29325 = stack[-1];
    if (!consp(v_29325)) goto v_29165;
    else goto v_29166;
v_29165:
    v_29325 = lisp_true;
    goto v_29164;
v_29166:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = (consp(v_29325) ? nil : lisp_true);
    goto v_29164;
    v_29325 = nil;
v_29164:
    if (v_29325 == nil) goto v_29162;
    goto v_29179;
v_29175:
    stack[0] = nil;
    goto v_29176;
v_29177:
    v_29325 = stack[-1];
    fn = elt(env, 1); // poly!-abs
    v_29325 = (*qfn1(fn))(fn, v_29325);
    goto v_29178;
v_29179:
    goto v_29175;
v_29176:
    goto v_29177;
v_29178:
    {
        LispObject v_29331 = stack[0];
        return cons(v_29331, v_29325);
    }
v_29162:
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    if (v_29325 == nil) goto v_29183;
    else goto v_29184;
v_29183:
    goto v_29192;
v_29188:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    stack[0] = qcar(v_29325);
    goto v_29189;
v_29190:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcdr(v_29325);
    fn = elt(env, 1); // poly!-abs
    v_29325 = (*qfn1(fn))(fn, v_29325);
    goto v_29191;
v_29192:
    goto v_29188;
v_29189:
    goto v_29190;
v_29191:
    {
        LispObject v_29332 = stack[0];
        return cons(v_29332, v_29325);
    }
v_29184:
    stack[-2] = nil;
    v_29327 = nil;
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcar(v_29325);
    v_29325 = qcar(v_29325);
    stack[0] = v_29325;
v_29213:
    goto v_29226;
v_29222:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcar(v_29325);
    v_29326 = qcar(v_29325);
    goto v_29223;
v_29224:
    v_29325 = stack[0];
    goto v_29225;
v_29226:
    goto v_29222;
v_29223:
    goto v_29224;
v_29225:
    if (equal(v_29326, v_29325)) goto v_29220;
    else goto v_29221;
v_29220:
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    if (!consp(v_29325)) goto v_29234;
    else goto v_29235;
v_29234:
    v_29325 = lisp_true;
    goto v_29233;
v_29235:
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    v_29325 = qcar(v_29325);
    v_29325 = (consp(v_29325) ? nil : lisp_true);
    goto v_29233;
    v_29325 = nil;
v_29233:
    v_29325 = (v_29325 == nil ? lisp_true : nil);
    goto v_29219;
v_29221:
    v_29325 = nil;
    goto v_29219;
    v_29325 = nil;
v_29219:
    if (v_29325 == nil) goto v_29216;
    else goto v_29217;
v_29216:
    goto v_29212;
v_29217:
    goto v_29255;
v_29251:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcdr(v_29325);
    goto v_29252;
v_29253:
    v_29326 = v_29327;
    goto v_29254;
v_29255:
    goto v_29251;
v_29252:
    goto v_29253;
v_29254:
    v_29325 = cons(v_29325, v_29326);
    env = stack[-3];
    v_29327 = v_29325;
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    stack[-1] = v_29325;
    goto v_29213;
v_29212:
    goto v_29270;
v_29266:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcar(v_29325);
    v_29326 = qcar(v_29325);
    goto v_29267;
v_29268:
    v_29325 = stack[0];
    goto v_29269;
v_29270:
    goto v_29266;
v_29267:
    goto v_29268;
v_29269:
    if (equal(v_29326, v_29325)) goto v_29264;
    else goto v_29265;
v_29264:
    goto v_29281;
v_29277:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcdr(v_29325);
    goto v_29278;
v_29279:
    v_29326 = v_29327;
    goto v_29280;
v_29281:
    goto v_29277;
v_29278:
    goto v_29279;
v_29280:
    v_29325 = cons(v_29325, v_29326);
    env = stack[-3];
    v_29327 = v_29325;
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    if (v_29325 == nil) goto v_29288;
    else goto v_29289;
v_29288:
    v_29325 = stack[-1];
    v_29325 = qcar(v_29325);
    v_29325 = qcar(v_29325);
    stack[-2] = v_29325;
    goto v_29287;
v_29289:
    goto v_29302;
v_29298:
    v_29325 = stack[-1];
    v_29325 = qcdr(v_29325);
    goto v_29299;
v_29300:
    v_29326 = v_29327;
    goto v_29301;
v_29302:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    v_29325 = cons(v_29325, v_29326);
    env = stack[-3];
    v_29327 = v_29325;
    goto v_29287;
v_29287:
    goto v_29263;
v_29265:
    goto v_29313;
v_29309:
    v_29325 = stack[-1];
    goto v_29310;
v_29311:
    v_29326 = v_29327;
    goto v_29312;
v_29313:
    goto v_29309;
v_29310:
    goto v_29311;
v_29312:
    v_29325 = cons(v_29325, v_29326);
    env = stack[-3];
    v_29327 = v_29325;
    goto v_29263;
v_29263:
    goto v_29321;
v_29317:
    stack[0] = stack[-2];
    goto v_29318;
v_29319:
    v_29325 = v_29327;
    fn = elt(env, 2); // gcdlist
    v_29325 = (*qfn1(fn))(fn, v_29325);
    goto v_29320;
v_29321:
    goto v_29317;
v_29318:
    goto v_29319;
v_29320:
    {
        LispObject v_29333 = stack[0];
        return cons(v_29333, v_29325);
    }
    goto v_29160;
    v_29325 = nil;
v_29160:
    return onevalue(v_29325);
}



// Code for dipcontenti

static LispObject CC_dipcontenti(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29219, v_29220, v_29221, v_29222;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29222 = v_29157;
// end of prologue
    v_29219 = v_29222;
    if (v_29219 == nil) goto v_29161;
    else goto v_29162;
v_29161:
    v_29219 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29160;
v_29162:
    v_29219 = v_29222;
    v_29219 = qcdr(v_29219);
    v_29219 = qcdr(v_29219);
    v_29221 = v_29219;
    v_29219 = v_29221;
    if (v_29219 == nil) goto v_29173;
    else goto v_29174;
v_29173:
    goto v_29181;
v_29177:
    v_29219 = v_29222;
    v_29219 = qcdr(v_29219);
    v_29219 = qcar(v_29219);
    goto v_29178;
v_29179:
    v_29220 = qvalue(elt(env, 1)); // !*groebrm
    if (v_29220 == nil) goto v_29188;
    v_29220 = v_29222;
    v_29220 = qcar(v_29220);
    goto v_29186;
v_29188:
    v_29220 = nil;
    goto v_29186;
    v_29220 = nil;
v_29186:
    goto v_29180;
v_29181:
    goto v_29177;
v_29178:
    goto v_29179;
v_29180:
    return cons(v_29219, v_29220);
v_29174:
    goto v_29204;
v_29198:
    v_29219 = v_29222;
    v_29219 = qcdr(v_29219);
    v_29220 = qcar(v_29219);
    goto v_29199;
v_29200:
    v_29219 = qvalue(elt(env, 1)); // !*groebrm
    if (v_29219 == nil) goto v_29211;
    v_29219 = v_29222;
    v_29219 = qcar(v_29219);
    goto v_29209;
v_29211:
    v_29219 = nil;
    goto v_29209;
    v_29219 = nil;
v_29209:
    goto v_29201;
v_29202:
    goto v_29203;
v_29204:
    goto v_29198;
v_29199:
    goto v_29200;
v_29201:
    goto v_29202;
v_29203:
    {
        fn = elt(env, 2); // dipcontenti1
        return (*qfnn(fn))(fn, 3, v_29220, v_29219, v_29221);
    }
    v_29219 = nil;
    goto v_29160;
    v_29219 = nil;
v_29160:
    return onevalue(v_29219);
}



// Code for ratmean

static LispObject CC_ratmean(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29171, v_29172, v_29173;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29171 = v_29158;
    v_29172 = v_29157;
// end of prologue
    goto v_29167;
v_29161:
    v_29173 = v_29172;
    goto v_29162;
v_29163:
    v_29172 = v_29171;
    goto v_29164;
v_29165:
    v_29171 = lisp_true;
    goto v_29166;
v_29167:
    goto v_29161;
v_29162:
    goto v_29163;
v_29164:
    goto v_29165;
v_29166:
    {
        fn = elt(env, 1); // ratplusm
        return (*qfnn(fn))(fn, 3, v_29173, v_29172, v_29171);
    }
}



// Code for lispcodeexp

static LispObject CC_lispcodeexp(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29709, v_29710, v_29711;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_29158;
    stack[-2] = v_29157;
// end of prologue
v_29156:
    v_29709 = stack[-2];
    if (is_number(v_29709)) goto v_29164;
    else goto v_29165;
v_29164:
    v_29709 = stack[-3];
    if (v_29709 == nil) goto v_29170;
    v_29709 = stack[-2];
        return Lfloat(nil, v_29709);
v_29170:
    v_29709 = stack[-2];
    goto v_29168;
    v_29709 = nil;
v_29168:
    goto v_29163;
v_29165:
    goto v_29183;
v_29179:
    v_29710 = stack[-2];
    goto v_29180;
v_29181:
    v_29709 = elt(env, 1); // e
    goto v_29182;
v_29183:
    goto v_29179;
v_29180:
    goto v_29181;
v_29182:
    if (v_29710 == v_29709) goto v_29177;
    else goto v_29178;
v_29177:
    goto v_29191;
v_29187:
    goto v_29197;
v_29193:
    v_29710 = elt(env, 2); // exp
    goto v_29194;
v_29195:
    v_29709 = elt(env, 3); // 1.0
    goto v_29196;
v_29197:
    goto v_29193;
v_29194:
    goto v_29195;
v_29196:
    v_29710 = list2(v_29710, v_29709);
    env = stack[-5];
    goto v_29188;
v_29189:
    v_29709 = stack[-3];
    goto v_29190;
v_29191:
    goto v_29187;
v_29188:
    goto v_29189;
v_29190:
    stack[-2] = v_29710;
    stack[-3] = v_29709;
    goto v_29156;
v_29178:
    v_29709 = stack[-2];
    if (!consp(v_29709)) goto v_29205;
    else goto v_29206;
v_29205:
    v_29709 = lisp_true;
    goto v_29204;
v_29206:
    goto v_29215;
v_29211:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29212;
v_29213:
    v_29709 = elt(env, 4); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    goto v_29214;
v_29215:
    goto v_29211;
v_29212:
    goto v_29213;
v_29214:
    v_29709 = Lmemq(nil, v_29710, v_29709);
    goto v_29204;
    v_29709 = nil;
v_29204:
    if (v_29709 == nil) goto v_29202;
    v_29709 = qvalue(elt(env, 5)); // irena!-constants
    if (v_29709 == nil) goto v_29223;
    v_29709 = stack[-2];
    if (v_29709 == nil) goto v_29223;
    v_29709 = stack[-2];
    v_29709 = Lstringp(nil, v_29709);
    env = stack[-5];
    if (v_29709 == nil) goto v_29229;
    else goto v_29223;
v_29229:
    v_29709 = stack[-2];
    fn = elt(env, 19); // check!-for!-irena!-constants
    v_29709 = (*qfn1(fn))(fn, v_29709);
    goto v_29221;
v_29223:
v_29221:
    v_29709 = stack[-2];
    goto v_29163;
v_29202:
    goto v_29241;
v_29237:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29238;
v_29239:
    v_29709 = elt(env, 6); // expt
    goto v_29240;
v_29241:
    goto v_29237;
v_29238:
    goto v_29239;
v_29240:
    if (v_29710 == v_29709) goto v_29235;
    else goto v_29236;
v_29235:
    goto v_29253;
v_29249:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29250;
v_29251:
    v_29709 = elt(env, 1); // e
    goto v_29252;
v_29253:
    goto v_29249;
v_29250:
    goto v_29251;
v_29252:
    if (v_29710 == v_29709) goto v_29247;
    else goto v_29248;
v_29247:
    goto v_29263;
v_29259:
    goto v_29269;
v_29265:
    v_29710 = elt(env, 2); // exp
    goto v_29266;
v_29267:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29709 = qcar(v_29709);
    goto v_29268;
v_29269:
    goto v_29265;
v_29266:
    goto v_29267;
v_29268:
    v_29710 = list2(v_29710, v_29709);
    env = stack[-5];
    goto v_29260;
v_29261:
    v_29709 = stack[-3];
    goto v_29262;
v_29263:
    goto v_29259;
v_29260:
    goto v_29261;
v_29262:
    stack[-2] = v_29710;
    stack[-3] = v_29709;
    goto v_29156;
v_29248:
    goto v_29282;
v_29278:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29279;
v_29280:
    v_29709 = elt(env, 7); // (quotient 1 2)
    goto v_29281;
v_29282:
    goto v_29278;
v_29279:
    goto v_29280;
v_29281:
    if (equal(v_29710, v_29709)) goto v_29276;
    else goto v_29277;
v_29276:
    goto v_29293;
v_29289:
    goto v_29299;
v_29295:
    v_29710 = elt(env, 8); // sqrt
    goto v_29296;
v_29297:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcar(v_29709);
    goto v_29298;
v_29299:
    goto v_29295;
v_29296:
    goto v_29297;
v_29298:
    v_29710 = list2(v_29710, v_29709);
    env = stack[-5];
    goto v_29290;
v_29291:
    v_29709 = stack[-3];
    goto v_29292;
v_29293:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    stack[-2] = v_29710;
    stack[-3] = v_29709;
    goto v_29156;
v_29277:
    goto v_29312;
v_29308:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29309;
v_29310:
    v_29709 = elt(env, 9); // !:rd!:
    goto v_29311;
v_29312:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    if (!consp(v_29710)) goto v_29306;
    v_29710 = qcar(v_29710);
    if (v_29710 == v_29709) goto v_29305;
    else goto v_29306;
v_29305:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29709 = qcar(v_29709);
    fn = elt(env, 20); // realrat
    v_29709 = (*qfn1(fn))(fn, v_29709);
    env = stack[-5];
    stack[-1] = v_29709;
    goto v_29334;
v_29330:
    v_29710 = stack[-1];
    goto v_29331;
v_29332:
    v_29709 = elt(env, 10); // (1 . 2)
    goto v_29333;
v_29334:
    goto v_29330;
v_29331:
    goto v_29332;
v_29333:
    if (equal(v_29710, v_29709)) goto v_29328;
    else goto v_29329;
v_29328:
    goto v_29342;
v_29338:
    stack[0] = elt(env, 8); // sqrt
    goto v_29339;
v_29340:
    goto v_29349;
v_29345:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29346;
v_29347:
    v_29709 = stack[-3];
    goto v_29348;
v_29349:
    goto v_29345;
v_29346:
    goto v_29347;
v_29348:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29341;
v_29342:
    goto v_29338;
v_29339:
    goto v_29340;
v_29341:
    {
        LispObject v_29717 = stack[0];
        return list2(v_29717, v_29709);
    }
v_29329:
    goto v_29363;
v_29357:
    stack[0] = elt(env, 6); // expt
    goto v_29358;
v_29359:
    goto v_29370;
v_29366:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29367;
v_29368:
    v_29709 = stack[-3];
    goto v_29369;
v_29370:
    goto v_29366;
v_29367:
    goto v_29368;
v_29369:
    stack[-2] = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    goto v_29360;
v_29361:
    goto v_29380;
v_29376:
    goto v_29388;
v_29382:
    v_29711 = elt(env, 11); // quotient
    goto v_29383;
v_29384:
    v_29709 = stack[-1];
    v_29710 = qcar(v_29709);
    goto v_29385;
v_29386:
    v_29709 = stack[-1];
    v_29709 = qcdr(v_29709);
    goto v_29387;
v_29388:
    goto v_29382;
v_29383:
    goto v_29384;
v_29385:
    goto v_29386;
v_29387:
    v_29710 = list3(v_29711, v_29710, v_29709);
    env = stack[-5];
    goto v_29377;
v_29378:
    v_29709 = nil;
    goto v_29379;
v_29380:
    goto v_29376;
v_29377:
    goto v_29378;
v_29379:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29362;
v_29363:
    goto v_29357;
v_29358:
    goto v_29359;
v_29360:
    goto v_29361;
v_29362:
    {
        LispObject v_29718 = stack[0];
        LispObject v_29719 = stack[-2];
        return list3(v_29718, v_29719, v_29709);
    }
    v_29709 = nil;
    goto v_29246;
v_29306:
    goto v_29404;
v_29398:
    stack[0] = elt(env, 6); // expt
    goto v_29399;
v_29400:
    goto v_29411;
v_29407:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29408;
v_29409:
    v_29709 = stack[-3];
    goto v_29410;
v_29411:
    goto v_29407;
v_29408:
    goto v_29409;
v_29410:
    stack[-1] = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    goto v_29401;
v_29402:
    goto v_29421;
v_29417:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29418;
v_29419:
    v_29709 = nil;
    goto v_29420;
v_29421:
    goto v_29417;
v_29418:
    goto v_29419;
v_29420:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29403;
v_29404:
    goto v_29398;
v_29399:
    goto v_29400;
v_29401:
    goto v_29402;
v_29403:
    {
        LispObject v_29720 = stack[0];
        LispObject v_29721 = stack[-1];
        return list3(v_29720, v_29721, v_29709);
    }
    v_29709 = nil;
v_29246:
    goto v_29163;
v_29236:
    goto v_29433;
v_29429:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29430;
v_29431:
    v_29709 = elt(env, 11); // quotient
    goto v_29432;
v_29433:
    goto v_29429;
v_29430:
    goto v_29431;
v_29432:
    if (v_29710 == v_29709) goto v_29427;
    else goto v_29428;
v_29427:
    goto v_29444;
v_29438:
    stack[-1] = elt(env, 11); // quotient
    goto v_29439;
v_29440:
    goto v_29451;
v_29447:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29448;
v_29449:
    v_29709 = lisp_true;
    goto v_29450;
v_29451:
    goto v_29447;
v_29448:
    goto v_29449;
v_29450:
    stack[0] = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    goto v_29441;
v_29442:
    goto v_29461;
v_29457:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29458;
v_29459:
    v_29709 = lisp_true;
    goto v_29460;
v_29461:
    goto v_29457;
v_29458:
    goto v_29459;
v_29460:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29443;
v_29444:
    goto v_29438;
v_29439:
    goto v_29440;
v_29441:
    goto v_29442;
v_29443:
    {
        LispObject v_29722 = stack[-1];
        LispObject v_29723 = stack[0];
        return list3(v_29722, v_29723, v_29709);
    }
v_29428:
    goto v_29473;
v_29469:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29470;
v_29471:
    v_29709 = elt(env, 12); // recip
    goto v_29472;
v_29473:
    goto v_29469;
v_29470:
    goto v_29471;
v_29472:
    if (v_29710 == v_29709) goto v_29467;
    else goto v_29468;
v_29467:
    v_29709 = qvalue(elt(env, 13)); // !*period
    if (v_29709 == nil) goto v_29480;
    goto v_29489;
v_29483:
    stack[-1] = elt(env, 11); // quotient
    goto v_29484;
v_29485:
    stack[0] = elt(env, 3); // 1.0
    goto v_29486;
v_29487:
    goto v_29497;
v_29493:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29494;
v_29495:
    v_29709 = stack[-3];
    goto v_29496;
v_29497:
    goto v_29493;
v_29494:
    goto v_29495;
v_29496:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29488;
v_29489:
    goto v_29483;
v_29484:
    goto v_29485;
v_29486:
    goto v_29487;
v_29488:
    {
        LispObject v_29724 = stack[-1];
        LispObject v_29725 = stack[0];
        return list3(v_29724, v_29725, v_29709);
    }
v_29480:
    goto v_29511;
v_29505:
    stack[-1] = elt(env, 11); // quotient
    goto v_29506;
v_29507:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29508;
v_29509:
    goto v_29519;
v_29515:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29516;
v_29517:
    v_29709 = stack[-3];
    goto v_29518;
v_29519:
    goto v_29515;
v_29516:
    goto v_29517;
v_29518:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    goto v_29510;
v_29511:
    goto v_29505;
v_29506:
    goto v_29507;
v_29508:
    goto v_29509;
v_29510:
    {
        LispObject v_29726 = stack[-1];
        LispObject v_29727 = stack[0];
        return list3(v_29726, v_29727, v_29709);
    }
    v_29709 = nil;
    goto v_29163;
v_29468:
    goto v_29530;
v_29526:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29527;
v_29528:
    v_29709 = elt(env, 14); // difference
    goto v_29529;
v_29530:
    goto v_29526;
v_29527:
    goto v_29528;
v_29529:
    if (v_29710 == v_29709) goto v_29524;
    else goto v_29525;
v_29524:
    goto v_29541;
v_29535:
    stack[-4] = elt(env, 15); // plus
    goto v_29536;
v_29537:
    goto v_29548;
v_29544:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29545;
v_29546:
    v_29709 = stack[-3];
    goto v_29547;
v_29548:
    goto v_29544;
v_29545:
    goto v_29546;
v_29547:
    stack[-1] = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    goto v_29538;
v_29539:
    goto v_29558;
v_29554:
    stack[0] = elt(env, 16); // minus
    goto v_29555;
v_29556:
    goto v_29565;
v_29561:
    v_29709 = stack[-2];
    v_29709 = qcdr(v_29709);
    v_29709 = qcdr(v_29709);
    v_29710 = qcar(v_29709);
    goto v_29562;
v_29563:
    v_29709 = stack[-3];
    goto v_29564;
v_29565:
    goto v_29561;
v_29562:
    goto v_29563;
v_29564:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    goto v_29557;
v_29558:
    goto v_29554;
v_29555:
    goto v_29556;
v_29557:
    v_29709 = list2(stack[0], v_29709);
    goto v_29540;
v_29541:
    goto v_29535;
v_29536:
    goto v_29537;
v_29538:
    goto v_29539;
v_29540:
    {
        LispObject v_29728 = stack[-4];
        LispObject v_29729 = stack[-1];
        return list3(v_29728, v_29729, v_29709);
    }
v_29525:
    goto v_29581;
v_29577:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29578;
v_29579:
    v_29709 = qvalue(elt(env, 17)); // !*lisparithexpops!*
    goto v_29580;
v_29581:
    goto v_29577;
v_29578:
    goto v_29579;
v_29580:
    v_29709 = Lmemq(nil, v_29710, v_29709);
    if (v_29709 == nil) goto v_29575;
    else goto v_29576;
v_29575:
    goto v_29590;
v_29586:
    v_29709 = stack[-2];
    v_29710 = qcar(v_29709);
    goto v_29587;
v_29588:
    v_29709 = qvalue(elt(env, 18)); // !*lisplogexpops!*
    goto v_29589;
v_29590:
    goto v_29586;
v_29587:
    goto v_29588;
v_29589:
    v_29709 = Lmemq(nil, v_29710, v_29709);
    v_29709 = (v_29709 == nil ? lisp_true : nil);
    goto v_29574;
v_29576:
    v_29709 = nil;
    goto v_29574;
    v_29709 = nil;
v_29574:
    if (v_29709 == nil) goto v_29572;
    v_29709 = stack[-2];
    stack[-3] = v_29709;
    v_29709 = stack[-3];
    if (v_29709 == nil) goto v_29608;
    else goto v_29609;
v_29608:
    v_29709 = nil;
    goto v_29603;
v_29609:
    v_29709 = stack[-3];
    v_29709 = qcar(v_29709);
    goto v_29621;
v_29617:
    v_29710 = v_29709;
    goto v_29618;
v_29619:
    v_29709 = nil;
    goto v_29620;
v_29621:
    goto v_29617;
v_29618:
    goto v_29619;
v_29620:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    v_29709 = ncons(v_29709);
    env = stack[-5];
    stack[-1] = v_29709;
    stack[-2] = v_29709;
v_29604:
    v_29709 = stack[-3];
    v_29709 = qcdr(v_29709);
    stack[-3] = v_29709;
    v_29709 = stack[-3];
    if (v_29709 == nil) goto v_29628;
    else goto v_29629;
v_29628:
    v_29709 = stack[-2];
    goto v_29603;
v_29629:
    goto v_29637;
v_29633:
    stack[0] = stack[-1];
    goto v_29634;
v_29635:
    v_29709 = stack[-3];
    v_29709 = qcar(v_29709);
    goto v_29648;
v_29644:
    v_29710 = v_29709;
    goto v_29645;
v_29646:
    v_29709 = nil;
    goto v_29647;
v_29648:
    goto v_29644;
v_29645:
    goto v_29646;
v_29647:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    v_29709 = ncons(v_29709);
    env = stack[-5];
    goto v_29636;
v_29637:
    goto v_29633;
v_29634:
    goto v_29635;
v_29636:
    v_29709 = Lrplacd(nil, stack[0], v_29709);
    env = stack[-5];
    v_29709 = stack[-1];
    v_29709 = qcdr(v_29709);
    stack[-1] = v_29709;
    goto v_29604;
v_29603:
    goto v_29163;
v_29572:
    v_29709 = stack[-2];
    stack[-4] = v_29709;
    v_29709 = stack[-4];
    if (v_29709 == nil) goto v_29664;
    else goto v_29665;
v_29664:
    v_29709 = nil;
    goto v_29659;
v_29665:
    v_29709 = stack[-4];
    v_29709 = qcar(v_29709);
    goto v_29677;
v_29673:
    v_29710 = v_29709;
    goto v_29674;
v_29675:
    v_29709 = stack[-3];
    goto v_29676;
v_29677:
    goto v_29673;
v_29674:
    goto v_29675;
v_29676:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    v_29709 = ncons(v_29709);
    env = stack[-5];
    stack[-1] = v_29709;
    stack[-2] = v_29709;
v_29660:
    v_29709 = stack[-4];
    v_29709 = qcdr(v_29709);
    stack[-4] = v_29709;
    v_29709 = stack[-4];
    if (v_29709 == nil) goto v_29684;
    else goto v_29685;
v_29684:
    v_29709 = stack[-2];
    goto v_29659;
v_29685:
    goto v_29693;
v_29689:
    stack[0] = stack[-1];
    goto v_29690;
v_29691:
    v_29709 = stack[-4];
    v_29709 = qcar(v_29709);
    goto v_29704;
v_29700:
    v_29710 = v_29709;
    goto v_29701;
v_29702:
    v_29709 = stack[-3];
    goto v_29703;
v_29704:
    goto v_29700;
v_29701:
    goto v_29702;
v_29703:
    v_29709 = CC_lispcodeexp(elt(env, 0), v_29710, v_29709);
    env = stack[-5];
    v_29709 = ncons(v_29709);
    env = stack[-5];
    goto v_29692;
v_29693:
    goto v_29689;
v_29690:
    goto v_29691;
v_29692:
    v_29709 = Lrplacd(nil, stack[0], v_29709);
    env = stack[-5];
    v_29709 = stack[-1];
    v_29709 = qcdr(v_29709);
    stack[-1] = v_29709;
    goto v_29660;
v_29659:
    goto v_29163;
    v_29709 = nil;
v_29163:
    return onevalue(v_29709);
}



// Code for defined_vertex

static LispObject CC_defined_vertex(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29189, v_29190;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29158;
    stack[-1] = v_29157;
// end of prologue
v_29162:
    v_29189 = stack[-1];
    if (v_29189 == nil) goto v_29165;
    else goto v_29166;
v_29165:
    v_29189 = lisp_true;
    goto v_29161;
v_29166:
    goto v_29180;
v_29176:
    v_29189 = stack[-1];
    v_29190 = qcar(v_29189);
    goto v_29177;
v_29178:
    v_29189 = stack[0];
    goto v_29179;
v_29180:
    goto v_29176;
v_29177:
    goto v_29178;
v_29179:
    fn = elt(env, 1); // memq_edgelist
    v_29189 = (*qfn2(fn))(fn, v_29190, v_29189);
    env = stack[-2];
    if (v_29189 == nil) goto v_29174;
    v_29189 = stack[-1];
    v_29189 = qcdr(v_29189);
    stack[-1] = v_29189;
    goto v_29162;
v_29174:
    v_29189 = nil;
    goto v_29161;
    goto v_29164;
v_29164:
    v_29189 = nil;
v_29161:
    return onevalue(v_29189);
}



// Code for mo!=expvec2a1

static LispObject CC_moMexpvec2a1(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29234, v_29235, v_29236;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29158;
    stack[-1] = v_29157;
// end of prologue
    stack[-2] = nil;
v_29163:
    v_29234 = stack[-1];
    if (v_29234 == nil) goto v_29166;
    else goto v_29167;
v_29166:
    v_29234 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_29234);
    }
v_29167:
    goto v_29177;
v_29173:
    v_29234 = stack[-1];
    v_29235 = qcar(v_29234);
    goto v_29174;
v_29175:
    v_29234 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29176;
v_29177:
    goto v_29173;
v_29174:
    goto v_29175;
v_29176:
    if (v_29235 == v_29234) goto v_29171;
    else goto v_29172;
v_29171:
    v_29234 = stack[-1];
    v_29234 = qcdr(v_29234);
    stack[-1] = v_29234;
    v_29234 = stack[0];
    v_29234 = qcdr(v_29234);
    stack[0] = v_29234;
    goto v_29163;
v_29172:
    goto v_29191;
v_29187:
    v_29234 = stack[-1];
    v_29235 = qcar(v_29234);
    goto v_29188;
v_29189:
    v_29234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29190;
v_29191:
    goto v_29187;
v_29188:
    goto v_29189;
v_29190:
    if (v_29235 == v_29234) goto v_29185;
    else goto v_29186;
v_29185:
    goto v_29200;
v_29196:
    v_29234 = stack[0];
    v_29235 = qcar(v_29234);
    goto v_29197;
v_29198:
    v_29234 = stack[-2];
    goto v_29199;
v_29200:
    goto v_29196;
v_29197:
    goto v_29198;
v_29199:
    v_29234 = cons(v_29235, v_29234);
    env = stack[-3];
    stack[-2] = v_29234;
    v_29234 = stack[-1];
    v_29234 = qcdr(v_29234);
    stack[-1] = v_29234;
    v_29234 = stack[0];
    v_29234 = qcdr(v_29234);
    stack[0] = v_29234;
    goto v_29163;
v_29186:
    goto v_29215;
v_29211:
    goto v_29223;
v_29217:
    v_29236 = elt(env, 1); // expt
    goto v_29218;
v_29219:
    v_29234 = stack[0];
    v_29235 = qcar(v_29234);
    goto v_29220;
v_29221:
    v_29234 = stack[-1];
    v_29234 = qcar(v_29234);
    goto v_29222;
v_29223:
    goto v_29217;
v_29218:
    goto v_29219;
v_29220:
    goto v_29221;
v_29222:
    v_29235 = list3(v_29236, v_29235, v_29234);
    env = stack[-3];
    goto v_29212;
v_29213:
    v_29234 = stack[-2];
    goto v_29214;
v_29215:
    goto v_29211;
v_29212:
    goto v_29213;
v_29214:
    v_29234 = cons(v_29235, v_29234);
    env = stack[-3];
    stack[-2] = v_29234;
    v_29234 = stack[-1];
    v_29234 = qcdr(v_29234);
    stack[-1] = v_29234;
    v_29234 = stack[0];
    v_29234 = qcdr(v_29234);
    stack[0] = v_29234;
    goto v_29163;
    v_29234 = nil;
    return onevalue(v_29234);
}



// Code for impartsq

static LispObject CC_impartsq(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29231, v_29232, v_29233, v_29234;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    v_29231 = stack[0];
    v_29231 = qcar(v_29231);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(fn, v_29231);
    env = stack[-4];
    v_29231 = stack[0];
    v_29231 = qcdr(v_29231);
    fn = elt(env, 1); // splitcomplex
    v_29231 = (*qfn1(fn))(fn, v_29231);
    env = stack[-4];
    v_29232 = stack[-1];
    v_29233 = v_29232;
    v_29234 = qcar(v_29233);
    v_29233 = qcdr(v_29232);
    v_29232 = v_29231;
    v_29232 = qcar(v_29232);
    v_29231 = qcdr(v_29231);
    stack[-3] = v_29234;
    stack[-2] = v_29232;
    stack[-1] = v_29231;
    goto v_29184;
v_29180:
    goto v_29190;
v_29186:
    goto v_29196;
v_29192:
    v_29232 = v_29233;
    goto v_29193;
v_29194:
    v_29231 = stack[-2];
    goto v_29195;
v_29196:
    goto v_29192;
v_29193:
    goto v_29194;
v_29195:
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(fn, v_29232, v_29231);
    env = stack[-4];
    goto v_29187;
v_29188:
    goto v_29205;
v_29201:
    v_29232 = stack[-3];
    goto v_29202;
v_29203:
    v_29231 = stack[-1];
    goto v_29204;
v_29205:
    goto v_29201;
v_29202:
    goto v_29203;
v_29204:
    fn = elt(env, 2); // multsq
    v_29231 = (*qfn2(fn))(fn, v_29232, v_29231);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_29231 = (*qfn1(fn))(fn, v_29231);
    env = stack[-4];
    goto v_29189;
v_29190:
    goto v_29186;
v_29187:
    goto v_29188;
v_29189:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_29231);
    env = stack[-4];
    goto v_29181;
v_29182:
    goto v_29214;
v_29210:
    goto v_29220;
v_29216:
    v_29232 = stack[-2];
    goto v_29217;
v_29218:
    v_29231 = stack[-2];
    goto v_29219;
v_29220:
    goto v_29216;
v_29217:
    goto v_29218;
v_29219:
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_29232, v_29231);
    env = stack[-4];
    goto v_29211;
v_29212:
    goto v_29228;
v_29224:
    v_29232 = stack[-1];
    goto v_29225;
v_29226:
    v_29231 = stack[-1];
    goto v_29227;
v_29228:
    goto v_29224;
v_29225:
    goto v_29226;
v_29227:
    fn = elt(env, 2); // multsq
    v_29231 = (*qfn2(fn))(fn, v_29232, v_29231);
    env = stack[-4];
    goto v_29213;
v_29214:
    goto v_29210;
v_29211:
    goto v_29212;
v_29213:
    fn = elt(env, 4); // addsq
    v_29231 = (*qfn2(fn))(fn, stack[-2], v_29231);
    env = stack[-4];
    fn = elt(env, 5); // invsq
    v_29231 = (*qfn1(fn))(fn, v_29231);
    env = stack[-4];
    goto v_29183;
v_29184:
    goto v_29180;
v_29181:
    goto v_29182;
v_29183:
    {
        LispObject v_29239 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_29239, v_29231);
    }
}



// Code for talp_qesolset

static LispObject CC_talp_qesolset(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29286, v_29287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29158;
    stack[-2] = v_29157;
// end of prologue
    v_29286 = stack[-1];
    fn = elt(env, 4); // talp_arg2l
    v_29286 = (*qfn1(fn))(fn, v_29286);
    env = stack[-4];
    stack[-3] = v_29286;
    v_29286 = stack[-1];
    fn = elt(env, 5); // talp_arg2r
    v_29286 = (*qfn1(fn))(fn, v_29286);
    env = stack[-4];
    stack[0] = v_29286;
    goto v_29179;
v_29175:
    v_29287 = stack[-3];
    goto v_29176;
v_29177:
    v_29286 = stack[-2];
    goto v_29178;
v_29179:
    goto v_29175;
v_29176:
    goto v_29177;
v_29178:
    fn = elt(env, 6); // talp_contains
    v_29286 = (*qfn2(fn))(fn, v_29287, v_29286);
    env = stack[-4];
    if (v_29286 == nil) goto v_29173;
    else goto v_29172;
v_29173:
    goto v_29188;
v_29184:
    v_29287 = stack[0];
    goto v_29185;
v_29186:
    v_29286 = stack[-2];
    goto v_29187;
v_29188:
    goto v_29184;
v_29185:
    goto v_29186;
v_29187:
    fn = elt(env, 6); // talp_contains
    v_29286 = (*qfn2(fn))(fn, v_29287, v_29286);
    env = stack[-4];
    if (v_29286 == nil) goto v_29182;
    else goto v_29172;
v_29182:
    v_29286 = elt(env, 1); // ignore
    goto v_29164;
v_29172:
    goto v_29200;
v_29196:
    v_29286 = stack[-1];
    if (!consp(v_29286)) goto v_29203;
    else goto v_29204;
v_29203:
    v_29286 = stack[-1];
    v_29287 = v_29286;
    goto v_29202;
v_29204:
    v_29286 = stack[-1];
    v_29286 = qcar(v_29286);
    v_29287 = v_29286;
    goto v_29202;
    v_29287 = nil;
v_29202:
    goto v_29197;
v_29198:
    v_29286 = elt(env, 2); // equal
    goto v_29199;
v_29200:
    goto v_29196;
v_29197:
    goto v_29198;
v_29199:
    if (v_29287 == v_29286) goto v_29195;
    v_29286 = elt(env, 3); // failed
    goto v_29164;
v_29195:
    goto v_29223;
v_29219:
    v_29287 = stack[-3];
    goto v_29220;
v_29221:
    v_29286 = stack[-2];
    goto v_29222;
v_29223:
    goto v_29219;
v_29220:
    goto v_29221;
v_29222:
    fn = elt(env, 6); // talp_contains
    v_29286 = (*qfn2(fn))(fn, v_29287, v_29286);
    env = stack[-4];
    if (v_29286 == nil) goto v_29216;
    goto v_29232;
v_29228:
    v_29287 = stack[0];
    goto v_29229;
v_29230:
    v_29286 = stack[-2];
    goto v_29231;
v_29232:
    goto v_29228;
v_29229:
    goto v_29230;
v_29231:
    fn = elt(env, 6); // talp_contains
    v_29286 = (*qfn2(fn))(fn, v_29287, v_29286);
    env = stack[-4];
    if (v_29286 == nil) goto v_29216;
    v_29286 = elt(env, 3); // failed
    goto v_29164;
v_29216:
    goto v_29248;
v_29244:
    v_29287 = stack[-3];
    goto v_29245;
v_29246:
    v_29286 = stack[-2];
    goto v_29247;
v_29248:
    goto v_29244;
v_29245:
    goto v_29246;
v_29247:
    if (equal(v_29287, v_29286)) goto v_29243;
    goto v_29256;
v_29252:
    v_29287 = stack[0];
    goto v_29253;
v_29254:
    v_29286 = stack[-2];
    goto v_29255;
v_29256:
    goto v_29252;
v_29253:
    goto v_29254;
v_29255:
    v_29286 = Lneq(nil, v_29287, v_29286);
    env = stack[-4];
    goto v_29241;
v_29243:
    v_29286 = nil;
    goto v_29241;
    v_29286 = nil;
v_29241:
    if (v_29286 == nil) goto v_29239;
    v_29286 = elt(env, 3); // failed
    goto v_29164;
v_29239:
    goto v_29271;
v_29267:
    v_29287 = stack[-3];
    goto v_29268;
v_29269:
    v_29286 = stack[-2];
    goto v_29270;
v_29271:
    goto v_29267;
v_29268:
    goto v_29269;
v_29270:
    if (v_29287 == v_29286) goto v_29265;
    else goto v_29266;
v_29265:
    v_29286 = stack[0];
    goto v_29264;
v_29266:
    v_29286 = stack[-3];
    goto v_29264;
    v_29286 = nil;
v_29264:
    goto v_29283;
v_29279:
    v_29287 = stack[-2];
    goto v_29280;
v_29281:
    goto v_29282;
v_29283:
    goto v_29279;
v_29280:
    goto v_29281;
v_29282:
    return cons(v_29287, v_29286);
v_29164:
    return onevalue(v_29286);
}



// Code for mri_irsplit1

static LispObject CC_mri_irsplit1(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29295, v_29296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    v_29295 = stack[0];
    if (!consp(v_29295)) goto v_29172;
    else goto v_29173;
v_29172:
    v_29295 = lisp_true;
    goto v_29171;
v_29173:
    v_29295 = stack[0];
    v_29295 = qcar(v_29295);
    v_29295 = (consp(v_29295) ? nil : lisp_true);
    goto v_29171;
    v_29295 = nil;
v_29171:
    if (v_29295 == nil) goto v_29169;
    v_29295 = stack[0];
    return ncons(v_29295);
v_29169:
    v_29295 = stack[0];
    v_29295 = qcdr(v_29295);
    v_29295 = CC_mri_irsplit1(elt(env, 0), v_29295);
    env = stack[-4];
    stack[-2] = v_29295;
    v_29295 = stack[0];
    v_29295 = qcar(v_29295);
    v_29295 = qcar(v_29295);
    v_29295 = qcdr(v_29295);
    stack[-1] = v_29295;
    goto v_29195;
v_29191:
    goto v_29202;
v_29198:
    goto v_29208;
v_29204:
    v_29295 = stack[0];
    v_29295 = qcar(v_29295);
    v_29295 = qcar(v_29295);
    v_29296 = qcar(v_29295);
    goto v_29205;
v_29206:
    v_29295 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29207;
v_29208:
    goto v_29204;
v_29205:
    goto v_29206;
v_29207:
    fn = elt(env, 1); // to
    v_29296 = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    goto v_29199;
v_29200:
    v_29295 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29201;
v_29202:
    goto v_29198;
v_29199:
    goto v_29200;
v_29201:
    v_29295 = cons(v_29296, v_29295);
    env = stack[-4];
    v_29296 = ncons(v_29295);
    env = stack[-4];
    goto v_29192;
v_29193:
    v_29295 = stack[-1];
    goto v_29194;
v_29195:
    goto v_29191;
v_29192:
    goto v_29193;
v_29194:
    fn = elt(env, 2); // exptf
    v_29295 = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    stack[-1] = v_29295;
    v_29295 = stack[-1];
    v_29295 = qcar(v_29295);
    v_29295 = qcar(v_29295);
    v_29295 = qcar(v_29295);
    fn = elt(env, 3); // mri_realvarp
    v_29295 = (*qfn1(fn))(fn, v_29295);
    env = stack[-4];
    if (v_29295 == nil) goto v_29219;
    goto v_29230;
v_29226:
    v_29295 = stack[-2];
    stack[-3] = qcar(v_29295);
    goto v_29227;
v_29228:
    goto v_29238;
v_29234:
    goto v_29244;
v_29240:
    v_29295 = stack[0];
    v_29295 = qcar(v_29295);
    v_29296 = qcdr(v_29295);
    goto v_29241;
v_29242:
    v_29295 = stack[-1];
    goto v_29243;
v_29244:
    goto v_29240;
v_29241:
    goto v_29242;
v_29243:
    fn = elt(env, 4); // multf
    v_29296 = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    goto v_29235;
v_29236:
    v_29295 = stack[-2];
    v_29295 = qcdr(v_29295);
    goto v_29237;
v_29238:
    goto v_29234;
v_29235:
    goto v_29236;
v_29237:
    fn = elt(env, 5); // addf
    v_29295 = (*qfn2(fn))(fn, v_29296, v_29295);
    goto v_29229;
v_29230:
    goto v_29226;
v_29227:
    goto v_29228;
v_29229:
    {
        LispObject v_29301 = stack[-3];
        return cons(v_29301, v_29295);
    }
v_29219:
    v_29295 = stack[0];
    v_29295 = qcar(v_29295);
    v_29295 = qcdr(v_29295);
    v_29295 = CC_mri_irsplit1(elt(env, 0), v_29295);
    env = stack[-4];
    stack[-3] = v_29295;
    goto v_29260;
v_29256:
    goto v_29266;
v_29262:
    goto v_29272;
v_29268:
    v_29295 = stack[-3];
    v_29296 = qcar(v_29295);
    goto v_29269;
v_29270:
    v_29295 = stack[-1];
    goto v_29271;
v_29272:
    goto v_29268;
v_29269:
    goto v_29270;
v_29271:
    fn = elt(env, 4); // multf
    v_29296 = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    goto v_29263;
v_29264:
    v_29295 = stack[-2];
    v_29295 = qcar(v_29295);
    goto v_29265;
v_29266:
    goto v_29262;
v_29263:
    goto v_29264;
v_29265:
    fn = elt(env, 5); // addf
    stack[0] = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    goto v_29257;
v_29258:
    goto v_29283;
v_29279:
    goto v_29289;
v_29285:
    v_29295 = stack[-3];
    v_29296 = qcdr(v_29295);
    goto v_29286;
v_29287:
    v_29295 = stack[-1];
    goto v_29288;
v_29289:
    goto v_29285;
v_29286:
    goto v_29287;
v_29288:
    fn = elt(env, 4); // multf
    v_29296 = (*qfn2(fn))(fn, v_29296, v_29295);
    env = stack[-4];
    goto v_29280;
v_29281:
    v_29295 = stack[-2];
    v_29295 = qcdr(v_29295);
    goto v_29282;
v_29283:
    goto v_29279;
v_29280:
    goto v_29281;
v_29282:
    fn = elt(env, 5); // addf
    v_29295 = (*qfn2(fn))(fn, v_29296, v_29295);
    goto v_29259;
v_29260:
    goto v_29256;
v_29257:
    goto v_29258;
v_29259:
    {
        LispObject v_29302 = stack[0];
        return cons(v_29302, v_29295);
    }
    return onevalue(v_29295);
}



// Code for sqfrf

static LispObject CC_sqfrf(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29597, v_29598, v_29599, v_29600;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_29157;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-11, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-7] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
// Binding !*msg
// FLUIDBIND: reloadenv=11 litvec-offset=2 saveloc=5
{   bind_fluid_stack bind_fluid_var(-11, 2, -5);
    qvalue(elt(env, 2)) = nil; // !*msg
    v_29597 = lisp_true;
    qvalue(elt(env, 1)) = v_29597; // !*gcd
    v_29597 = qvalue(elt(env, 3)); // !*rounded
    stack[-1] = v_29597;
    if (v_29597 == nil) goto v_29176;
    v_29597 = elt(env, 4); // rational
    v_29597 = ncons(v_29597);
    env = stack[-11];
    fn = elt(env, 10); // on
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    goto v_29187;
v_29183:
    v_29598 = stack[-9];
    goto v_29184;
v_29185:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29186;
v_29187:
    goto v_29183;
v_29184:
    goto v_29185;
v_29186:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    v_29597 = qcar(v_29597);
    stack[-9] = v_29597;
    goto v_29174;
v_29176:
v_29174:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_29597;
    v_29597 = stack[-9];
    v_29597 = qcar(v_29597);
    v_29597 = qcar(v_29597);
    v_29597 = qcar(v_29597);
    stack[-4] = v_29597;
    v_29597 = lisp_true;
// Binding !*ezgcd
// FLUIDBIND: reloadenv=11 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-11, 5, 0);
    qvalue(elt(env, 5)) = v_29597; // !*ezgcd
    goto v_29203;
v_29199:
    stack[-6] = stack[-9];
    goto v_29200;
v_29201:
    goto v_29210;
v_29206:
    v_29598 = stack[-9];
    goto v_29207;
v_29208:
    v_29597 = stack[-4];
    goto v_29209;
v_29210:
    goto v_29206;
v_29207:
    goto v_29208;
v_29209:
    fn = elt(env, 12); // diff
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    goto v_29202;
v_29203:
    goto v_29199;
v_29200:
    goto v_29201;
v_29202:
    fn = elt(env, 13); // gcdf
    v_29597 = (*qfn2(fn))(fn, stack[-6], v_29597);
    env = stack[-11];
    stack[-6] = v_29597;
    ;}  // end of a binding scope
    goto v_29218;
v_29214:
    v_29598 = stack[-9];
    goto v_29215;
v_29216:
    v_29597 = stack[-6];
    goto v_29217;
v_29218:
    goto v_29214;
v_29215:
    goto v_29216;
v_29217:
    fn = elt(env, 14); // quotf!-fail
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-9] = v_29597;
    v_29597 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_29597)) v_29597 = nil;
    else { v_29597 = qfastgets(v_29597);
           if (v_29597 != nil) { v_29597 = elt(v_29597, 3); // field
#ifdef RECORD_GET
             if (v_29597 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_29597 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_29597 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_29597 == SPID_NOPROP) v_29597 = nil; else v_29597 = lisp_true; }}
#endif
    if (v_29597 == nil) goto v_29228;
    goto v_29236;
v_29232:
    v_29597 = stack[-9];
    fn = elt(env, 15); // lnc
    v_29598 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    stack[-3] = v_29598;
    goto v_29233;
v_29234:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29235;
v_29236:
    goto v_29232;
v_29233:
    goto v_29234;
v_29235:
    v_29597 = Lneq(nil, v_29598, v_29597);
    env = stack[-11];
    goto v_29226;
v_29228:
    v_29597 = nil;
    goto v_29226;
    v_29597 = nil;
v_29226:
    if (v_29597 == nil) goto v_29224;
    goto v_29248;
v_29244:
    v_29597 = stack[-3];
    fn = elt(env, 16); // !:recip
    v_29598 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    goto v_29245;
v_29246:
    v_29597 = stack[-9];
    goto v_29247;
v_29248:
    goto v_29244;
v_29245:
    goto v_29246;
v_29247:
    fn = elt(env, 17); // multd
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-9] = v_29597;
    goto v_29257;
v_29253:
    v_29598 = stack[-3];
    goto v_29254;
v_29255:
    v_29597 = stack[-6];
    goto v_29256;
v_29257:
    goto v_29253;
v_29254:
    goto v_29255;
v_29256:
    fn = elt(env, 17); // multd
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-6] = v_29597;
    goto v_29222;
v_29224:
v_29222:
v_29262:
    goto v_29272;
v_29268:
    goto v_29278;
v_29274:
    v_29598 = stack[-6];
    goto v_29275;
v_29276:
    v_29597 = stack[-4];
    goto v_29277;
v_29278:
    goto v_29274;
v_29275:
    goto v_29276;
v_29277:
    fn = elt(env, 18); // degr
    v_29598 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    goto v_29269;
v_29270:
    v_29597 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29271;
v_29272:
    goto v_29268;
v_29269:
    goto v_29270;
v_29271:
    v_29597 = (LispObject)greaterp2(v_29598, v_29597);
    v_29597 = v_29597 ? lisp_true : nil;
    env = stack[-11];
    if (v_29597 == nil) goto v_29265;
    else goto v_29266;
v_29265:
    goto v_29261;
v_29266:
    goto v_29288;
v_29284:
    v_29598 = stack[-6];
    goto v_29285;
v_29286:
    v_29597 = stack[-9];
    goto v_29287;
v_29288:
    goto v_29284;
v_29285:
    goto v_29286;
v_29287:
    fn = elt(env, 13); // gcdf
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[0] = v_29597;
    goto v_29299;
v_29295:
    v_29598 = stack[-9];
    goto v_29296;
v_29297:
    v_29597 = stack[0];
    goto v_29298;
v_29299:
    goto v_29295;
v_29296:
    goto v_29297;
v_29298:
    if (equal(v_29598, v_29597)) goto v_29294;
    goto v_29309;
v_29303:
    goto v_29315;
v_29311:
    v_29598 = stack[-9];
    goto v_29312;
v_29313:
    v_29597 = stack[0];
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    fn = elt(env, 19); // quotf
    v_29599 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    goto v_29304;
v_29305:
    v_29598 = stack[-10];
    goto v_29306;
v_29307:
    v_29597 = stack[-2];
    goto v_29308;
v_29309:
    goto v_29303;
v_29304:
    goto v_29305;
v_29306:
    goto v_29307;
v_29308:
    v_29597 = acons(v_29599, v_29598, v_29597);
    env = stack[-11];
    stack[-2] = v_29597;
    goto v_29292;
v_29294:
v_29292:
    goto v_29325;
v_29321:
    v_29598 = stack[-6];
    goto v_29322;
v_29323:
    v_29597 = stack[0];
    goto v_29324;
v_29325:
    goto v_29321;
v_29322:
    goto v_29323;
v_29324:
    fn = elt(env, 19); // quotf
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-6] = v_29597;
    v_29597 = stack[0];
    stack[-9] = v_29597;
    v_29597 = stack[-10];
    v_29597 = add1(v_29597);
    env = stack[-11];
    stack[-10] = v_29597;
    goto v_29262;
v_29261:
    v_29597 = stack[-1];
    if (v_29597 == nil) goto v_29334;
    v_29597 = elt(env, 7); // rounded
    v_29597 = ncons(v_29597);
    env = stack[-11];
    fn = elt(env, 10); // on
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    goto v_29345;
v_29341:
    v_29598 = stack[-9];
    goto v_29342;
v_29343:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    v_29597 = qcar(v_29597);
    stack[-9] = v_29597;
    v_29597 = stack[-2];
    stack[-4] = v_29597;
    v_29597 = stack[-4];
    if (v_29597 == nil) goto v_29358;
    else goto v_29359;
v_29358:
    v_29597 = nil;
    goto v_29353;
v_29359:
    v_29597 = stack[-4];
    v_29597 = qcar(v_29597);
    stack[0] = v_29597;
    goto v_29371;
v_29367:
    goto v_29378;
v_29374:
    v_29597 = stack[0];
    v_29598 = qcar(v_29597);
    goto v_29375;
v_29376:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29377;
v_29378:
    goto v_29374;
v_29375:
    goto v_29376;
v_29377:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    v_29598 = qcar(v_29597);
    goto v_29368;
v_29369:
    v_29597 = stack[0];
    v_29597 = qcdr(v_29597);
    goto v_29370;
v_29371:
    goto v_29367;
v_29368:
    goto v_29369;
v_29370:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    v_29597 = ncons(v_29597);
    env = stack[-11];
    stack[-2] = v_29597;
    stack[-3] = v_29597;
v_29354:
    v_29597 = stack[-4];
    v_29597 = qcdr(v_29597);
    stack[-4] = v_29597;
    v_29597 = stack[-4];
    if (v_29597 == nil) goto v_29389;
    else goto v_29390;
v_29389:
    v_29597 = stack[-3];
    goto v_29353;
v_29390:
    goto v_29398;
v_29394:
    stack[-1] = stack[-2];
    goto v_29395;
v_29396:
    v_29597 = stack[-4];
    v_29597 = qcar(v_29597);
    stack[0] = v_29597;
    goto v_29409;
v_29405:
    goto v_29416;
v_29412:
    v_29597 = stack[0];
    v_29598 = qcar(v_29597);
    goto v_29413;
v_29414:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29415;
v_29416:
    goto v_29412;
v_29413:
    goto v_29414;
v_29415:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    v_29598 = qcar(v_29597);
    goto v_29406;
v_29407:
    v_29597 = stack[0];
    v_29597 = qcdr(v_29597);
    goto v_29408;
v_29409:
    goto v_29405;
v_29406:
    goto v_29407;
v_29408:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    v_29597 = ncons(v_29597);
    env = stack[-11];
    goto v_29397;
v_29398:
    goto v_29394;
v_29395:
    goto v_29396;
v_29397:
    v_29597 = Lrplacd(nil, stack[-1], v_29597);
    env = stack[-11];
    v_29597 = stack[-2];
    v_29597 = qcdr(v_29597);
    stack[-2] = v_29597;
    goto v_29354;
v_29353:
    stack[-2] = v_29597;
    goto v_29332;
v_29334:
v_29332:
    goto v_29437;
v_29433:
    v_29598 = stack[-6];
    goto v_29434;
v_29435:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29436;
v_29437:
    goto v_29433;
v_29434:
    goto v_29435;
v_29436:
    if (v_29598 == v_29597) goto v_29432;
    goto v_29444;
v_29440:
    v_29598 = stack[-6];
    goto v_29441;
v_29442:
    v_29597 = stack[-7];
    goto v_29443;
v_29444:
    goto v_29440;
v_29441:
    goto v_29442;
v_29443:
    v_29597 = Lassoc(nil, v_29598, v_29597);
    goto v_29430;
v_29432:
    v_29597 = nil;
    goto v_29430;
    v_29597 = nil;
v_29430:
    if (v_29597 == nil) goto v_29428;
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_29597;
    goto v_29426;
v_29428:
v_29426:
    goto v_29460;
v_29456:
    v_29598 = stack[-6];
    goto v_29457;
v_29458:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29459;
v_29460:
    goto v_29456;
v_29457:
    goto v_29458;
v_29459:
    if (v_29598 == v_29597) goto v_29455;
    goto v_29471;
v_29467:
    v_29598 = stack[-10];
    goto v_29468;
v_29469:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29470;
v_29471:
    goto v_29467;
v_29468:
    goto v_29469;
v_29470:
    if (v_29598 == v_29597) goto v_29465;
    else goto v_29466;
v_29465:
    goto v_29479;
v_29475:
    v_29598 = stack[-6];
    goto v_29476;
v_29477:
    v_29597 = stack[-9];
    goto v_29478;
v_29479:
    goto v_29475;
v_29476:
    goto v_29477;
v_29478:
    fn = elt(env, 20); // multf
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-9] = v_29597;
    goto v_29464;
v_29466:
    goto v_29489;
v_29485:
    v_29598 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29486;
v_29487:
    v_29597 = stack[-2];
    goto v_29488;
v_29489:
    goto v_29485;
v_29486:
    goto v_29487;
v_29488:
    fn = elt(env, 21); // rassoc
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[0] = v_29597;
    if (v_29597 == nil) goto v_29483;
    goto v_29497;
v_29493:
    stack[-1] = stack[0];
    goto v_29494;
v_29495:
    goto v_29504;
v_29500:
    v_29598 = stack[-6];
    goto v_29501;
v_29502:
    v_29597 = stack[0];
    v_29597 = qcar(v_29597);
    goto v_29503;
v_29504:
    goto v_29500;
v_29501:
    goto v_29502;
v_29503:
    fn = elt(env, 20); // multf
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    goto v_29496;
v_29497:
    goto v_29493;
v_29494:
    goto v_29495;
v_29496:
    v_29597 = Lrplaca(nil, stack[-1], v_29597);
    env = stack[-11];
    goto v_29464;
v_29483:
    v_29597 = stack[-2];
    if (v_29597 == nil) goto v_29512;
    else goto v_29513;
v_29512:
    goto v_29520;
v_29516:
    goto v_29526;
v_29522:
    v_29598 = stack[-6];
    goto v_29523;
v_29524:
    v_29597 = stack[-10];
    goto v_29525;
v_29526:
    goto v_29522;
v_29523:
    goto v_29524;
v_29525:
    fn = elt(env, 22); // rootxf
    v_29598 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[0] = v_29598;
    goto v_29517;
v_29518:
    v_29597 = elt(env, 8); // failed
    goto v_29519;
v_29520:
    goto v_29516;
v_29517:
    goto v_29518;
v_29519:
    v_29597 = Lneq(nil, v_29598, v_29597);
    env = stack[-11];
    goto v_29511;
v_29513:
    v_29597 = nil;
    goto v_29511;
    v_29597 = nil;
v_29511:
    if (v_29597 == nil) goto v_29509;
    goto v_29538;
v_29534:
    v_29598 = stack[0];
    goto v_29535;
v_29536:
    v_29597 = stack[-9];
    goto v_29537;
v_29538:
    goto v_29534;
v_29535:
    goto v_29536;
v_29537:
    fn = elt(env, 20); // multf
    v_29597 = (*qfn2(fn))(fn, v_29598, v_29597);
    env = stack[-11];
    stack[-9] = v_29597;
    goto v_29464;
v_29509:
    v_29597 = stack[-6];
    if (!consp(v_29597)) goto v_29545;
    else goto v_29546;
v_29545:
    v_29597 = lisp_true;
    goto v_29544;
v_29546:
    v_29597 = stack[-6];
    v_29597 = qcar(v_29597);
    v_29597 = (consp(v_29597) ? nil : lisp_true);
    goto v_29544;
    v_29597 = nil;
v_29544:
    if (v_29597 == nil) goto v_29541;
    else goto v_29542;
v_29541:
    goto v_29559;
v_29555:
    stack[0] = stack[-2];
    goto v_29556;
v_29557:
    goto v_29566;
v_29562:
    v_29598 = stack[-6];
    goto v_29563;
v_29564:
    v_29597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29565;
v_29566:
    goto v_29562;
v_29563:
    goto v_29564;
v_29565:
    v_29597 = cons(v_29598, v_29597);
    env = stack[-11];
    goto v_29558;
v_29559:
    goto v_29555;
v_29556:
    goto v_29557;
v_29558:
    fn = elt(env, 23); // aconc
    v_29597 = (*qfn2(fn))(fn, stack[0], v_29597);
    env = stack[-11];
    stack[-2] = v_29597;
    goto v_29464;
v_29542:
    goto v_29581;
v_29573:
    v_29600 = elt(env, 9); // "sqfrf failure"
    goto v_29574;
v_29575:
    v_29599 = stack[-9];
    goto v_29576;
v_29577:
    v_29598 = stack[-10];
    goto v_29578;
v_29579:
    v_29597 = stack[-2];
    goto v_29580;
v_29581:
    goto v_29573;
v_29574:
    goto v_29575;
v_29576:
    goto v_29577;
v_29578:
    goto v_29579;
v_29580:
    v_29597 = list4(v_29600, v_29599, v_29598, v_29597);
    env = stack[-11];
    fn = elt(env, 24); // errach
    v_29597 = (*qfn1(fn))(fn, v_29597);
    env = stack[-11];
    goto v_29464;
v_29464:
    goto v_29453;
v_29455:
v_29453:
    goto v_29593;
v_29587:
    v_29599 = stack[-9];
    goto v_29588;
v_29589:
    v_29598 = stack[-10];
    goto v_29590;
v_29591:
    v_29597 = stack[-2];
    goto v_29592;
v_29593:
    goto v_29587;
v_29588:
    goto v_29589;
v_29590:
    goto v_29591;
v_29592:
    v_29597 = acons(v_29599, v_29598, v_29597);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_29597);
}



// Code for ctx_get

static LispObject CC_ctx_get(LispObject env,
                         LispObject v_29157, LispObject v_29158)
{
    env = qenv(env);
    LispObject v_29197, v_29198, v_29199;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29158,v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29157,v_29158);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29158;
    v_29197 = v_29157;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // ctx_ial
    v_29197 = (*qfn1(fn))(fn, v_29197);
    v_29199 = v_29197;
v_29168:
    v_29197 = v_29199;
    if (v_29197 == nil) goto v_29171;
    v_29197 = stack[-1];
    if (v_29197 == nil) goto v_29175;
    else goto v_29171;
v_29175:
    goto v_29172;
v_29171:
    goto v_29167;
v_29172:
    goto v_29186;
v_29182:
    v_29197 = v_29199;
    v_29197 = qcar(v_29197);
    v_29198 = qcar(v_29197);
    goto v_29183;
v_29184:
    v_29197 = stack[0];
    goto v_29185;
v_29186:
    goto v_29182;
v_29183:
    goto v_29184;
v_29185:
    if (v_29198 == v_29197) goto v_29180;
    else goto v_29181;
v_29180:
    v_29197 = v_29199;
    v_29197 = qcar(v_29197);
    v_29197 = qcdr(v_29197);
    stack[-1] = v_29197;
    goto v_29179;
v_29181:
v_29179:
    v_29197 = v_29199;
    v_29197 = qcdr(v_29197);
    v_29199 = v_29197;
    goto v_29168;
v_29167:
    v_29197 = stack[-1];
    return onevalue(v_29197);
}



// Code for subs2pf

static LispObject CC_subs2pf(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29195, v_29196, v_29197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
v_29156:
    v_29195 = stack[0];
    if (v_29195 == nil) goto v_29162;
    v_29195 = stack[0];
    v_29195 = qcar(v_29195);
    v_29195 = qcdr(v_29195);
    fn = elt(env, 1); // resimp
    v_29195 = (*qfn1(fn))(fn, v_29195);
    env = stack[-1];
    fn = elt(env, 2); // subs2
    v_29195 = (*qfn1(fn))(fn, v_29195);
    env = stack[-1];
    v_29196 = v_29195;
    v_29196 = qcar(v_29196);
    if (v_29196 == nil) goto v_29173;
    goto v_29183;
v_29177:
    v_29196 = stack[0];
    v_29196 = qcar(v_29196);
    v_29197 = qcar(v_29196);
    goto v_29178;
v_29179:
    v_29196 = v_29195;
    goto v_29180;
v_29181:
    v_29195 = stack[0];
    v_29195 = qcdr(v_29195);
    goto v_29182;
v_29183:
    goto v_29177;
v_29178:
    goto v_29179;
v_29180:
    goto v_29181;
v_29182:
    return acons(v_29197, v_29196, v_29195);
v_29173:
    v_29195 = stack[0];
    v_29195 = qcdr(v_29195);
    stack[0] = v_29195;
    goto v_29156;
    v_29195 = nil;
    goto v_29160;
v_29162:
    v_29195 = nil;
v_29160:
    return onevalue(v_29195);
}



// Code for newvar

static LispObject CC_newvar(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29185, v_29186;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29157;
// end of prologue
    v_29185 = stack[0];
    if (symbolp(v_29185)) goto v_29162;
    goto v_29169;
v_29165:
    v_29186 = stack[0];
    goto v_29166;
v_29167:
    v_29185 = elt(env, 1); // "free variable"
    goto v_29168;
v_29169:
    goto v_29165;
v_29166:
    goto v_29167;
v_29168:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_29186, v_29185);
    }
v_29162:
    goto v_29180;
v_29176:
    v_29185 = elt(env, 2); // !=
    fn = elt(env, 4); // id2bytelist
    stack[-1] = (*qfn1(fn))(fn, v_29185);
    env = stack[-2];
    goto v_29177;
v_29178:
    v_29185 = stack[0];
    fn = elt(env, 4); // id2bytelist
    v_29185 = (*qfn1(fn))(fn, v_29185);
    env = stack[-2];
    goto v_29179;
v_29180:
    goto v_29176;
v_29177:
    goto v_29178;
v_29179:
    v_29185 = Lappend(nil, stack[-1], v_29185);
    env = stack[-2];
    {
        fn = elt(env, 5); // bytelist2id
        return (*qfn1(fn))(fn, v_29185);
    }
    v_29185 = nil;
    return onevalue(v_29185);
}



// Code for reddom_zeros

static LispObject CC_reddom_zeros(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29186, v_29187, v_29188;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
// copy arguments values to proper place
    v_29187 = v_29157;
// end of prologue
v_29161:
    v_29186 = v_29187;
    if (v_29186 == nil) goto v_29164;
    else goto v_29165;
v_29164:
    v_29186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29160;
v_29165:
    goto v_29174;
v_29170:
    v_29186 = v_29187;
    v_29188 = qcar(v_29186);
    goto v_29171;
v_29172:
    v_29186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29173;
v_29174:
    goto v_29170;
v_29171:
    goto v_29172;
v_29173:
    if (v_29188 == v_29186) goto v_29168;
    else goto v_29169;
v_29168:
    v_29186 = v_29187;
    v_29186 = qcdr(v_29186);
    v_29186 = CC_reddom_zeros(elt(env, 0), v_29186);
    return add1(v_29186);
v_29169:
    v_29186 = v_29187;
    v_29186 = qcdr(v_29186);
    v_29187 = v_29186;
    goto v_29161;
    v_29186 = nil;
v_29160:
    return onevalue(v_29186);
}



// Code for get!-all!-kernels

static LispObject CC_getKallKkernels(LispObject env,
                         LispObject v_29157)
{
    env = qenv(env);
    LispObject v_29214, v_29215;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29157);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29157);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_29157;
// end of prologue
    stack[-3] = nil;
v_29163:
    v_29214 = stack[-2];
    if (!consp(v_29214)) goto v_29168;
    else goto v_29169;
v_29168:
    goto v_29164;
v_29169:
    goto v_29176;
v_29172:
    v_29214 = stack[-2];
    v_29214 = qcar(v_29214);
    fn = elt(env, 1); // simp
    v_29214 = (*qfn1(fn))(fn, v_29214);
    env = stack[-4];
    stack[-1] = v_29214;
    goto v_29186;
v_29182:
    v_29214 = stack[-1];
    v_29214 = qcar(v_29214);
    fn = elt(env, 2); // kernels
    stack[0] = (*qfn1(fn))(fn, v_29214);
    env = stack[-4];
    goto v_29183;
v_29184:
    v_29214 = stack[-1];
    v_29214 = qcdr(v_29214);
    fn = elt(env, 2); // kernels
    v_29214 = (*qfn1(fn))(fn, v_29214);
    env = stack[-4];
    goto v_29185;
v_29186:
    goto v_29182;
v_29183:
    goto v_29184;
v_29185:
    fn = elt(env, 3); // union
    v_29215 = (*qfn2(fn))(fn, stack[0], v_29214);
    env = stack[-4];
    goto v_29173;
v_29174:
    v_29214 = stack[-3];
    goto v_29175;
v_29176:
    goto v_29172;
v_29173:
    goto v_29174;
v_29175:
    v_29214 = cons(v_29215, v_29214);
    env = stack[-4];
    stack[-3] = v_29214;
    v_29214 = stack[-2];
    v_29214 = qcdr(v_29214);
    stack[-2] = v_29214;
    goto v_29163;
v_29164:
    v_29214 = nil;
    v_29215 = v_29214;
v_29165:
    v_29214 = stack[-3];
    if (v_29214 == nil) goto v_29199;
    else goto v_29200;
v_29199:
    v_29214 = v_29215;
    goto v_29162;
v_29200:
    goto v_29208;
v_29204:
    v_29214 = stack[-3];
    v_29214 = qcar(v_29214);
    goto v_29205;
v_29206:
    goto v_29207;
v_29208:
    goto v_29204;
v_29205:
    goto v_29206;
v_29207:
    fn = elt(env, 3); // union
    v_29214 = (*qfn2(fn))(fn, v_29214, v_29215);
    env = stack[-4];
    v_29215 = v_29214;
    v_29214 = stack[-3];
    v_29214 = qcdr(v_29214);
    stack[-3] = v_29214;
    goto v_29165;
v_29162:
    return onevalue(v_29214);
}



setup_type const u48_setup[] =
{
    {"merge_lists",             TOO_FEW_2,      CC_merge_lists,WRONG_NO_2},
    {"talp_lssimpl",            CC_talp_lssimpl,TOO_MANY_1,    WRONG_NO_1},
    {"pasf_lnegrel",            CC_pasf_lnegrel,TOO_MANY_1,    WRONG_NO_1},
    {"addexptsdf",              TOO_FEW_2,      CC_addexptsdf, WRONG_NO_2},
    {"lengthn",                 CC_lengthn,     TOO_MANY_1,    WRONG_NO_1},
    {"spmatlength",             CC_spmatlength, TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsort",         CC_groebcplistsort,TOO_MANY_1, WRONG_NO_1},
    {"maprintla",               TOO_FEW_2,      CC_maprintla,  WRONG_NO_2},
    {":log10",                  CC_Tlog10,      TOO_MANY_1,    WRONG_NO_1},
    {"pnth*",                   TOO_FEW_2,      CC_pnthH,      WRONG_NO_2},
    {"sub01",                   TOO_FEW_2,      CC_sub01,      WRONG_NO_2},
    {"replace-next",            TOO_FEW_2,      CC_replaceKnext,WRONG_NO_2},
    {"mk+inner+product",        TOO_FEW_2,      CC_mkLinnerLproduct,WRONG_NO_2},
    {"dim<=deg",                CC_dimRMdeg,    TOO_MANY_1,    WRONG_NO_1},
    {"endofstmtp",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endofstmtp},
    {"mk_parents_prim",         CC_mk_parents_prim,TOO_MANY_1, WRONG_NO_1},
    {"fs:zerop:",               CC_fsTzeropT,   TOO_MANY_1,    WRONG_NO_1},
    {"monic",                   TOO_FEW_2,      CC_monic,      WRONG_NO_2},
    {"st_sorttree1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_sorttree1},
    {"evaluate-in-vector",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluateKinKvector},
    {"bfrsq",                   CC_bfrsq,       TOO_MANY_1,    WRONG_NO_1},
    {"nextu",                   TOO_FEW_2,      CC_nextu,      WRONG_NO_2},
    {"talp_get-idx",            TOO_FEW_2,      CC_talp_getKidx,WRONG_NO_2},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,TOO_MANY_1,WRONG_NO_1},
    {"pasf_dnf",                CC_pasf_dnf,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_pop",                CC_ofsf_pop,    TOO_MANY_1,    WRONG_NO_1},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,TOO_MANY_1,    WRONG_NO_1},
    {"dipcontenti",             CC_dipcontenti, TOO_MANY_1,    WRONG_NO_1},
    {"ratmean",                 TOO_FEW_2,      CC_ratmean,    WRONG_NO_2},
    {"lispcodeexp",             TOO_FEW_2,      CC_lispcodeexp,WRONG_NO_2},
    {"defined_vertex",          TOO_FEW_2,      CC_defined_vertex,WRONG_NO_2},
    {"mo=expvec2a1",            TOO_FEW_2,      CC_moMexpvec2a1,WRONG_NO_2},
    {"impartsq",                CC_impartsq,    TOO_MANY_1,    WRONG_NO_1},
    {"talp_qesolset",           TOO_FEW_2,      CC_talp_qesolset,WRONG_NO_2},
    {"mri_irsplit1",            CC_mri_irsplit1,TOO_MANY_1,    WRONG_NO_1},
    {"sqfrf",                   CC_sqfrf,       TOO_MANY_1,    WRONG_NO_1},
    {"ctx_get",                 TOO_FEW_2,      CC_ctx_get,    WRONG_NO_2},
    {"subs2pf",                 CC_subs2pf,     TOO_MANY_1,    WRONG_NO_1},
    {"newvar",                  CC_newvar,      TOO_MANY_1,    WRONG_NO_1},
    {"reddom_zeros",            CC_reddom_zeros,TOO_MANY_1,    WRONG_NO_1},
    {"get-all-kernels",         CC_getKallKkernels,TOO_MANY_1, WRONG_NO_1},
    {NULL, (one_args *)"u48", (two_args *)"5042 8821788 8603089", 0}
};

// end of generated code
