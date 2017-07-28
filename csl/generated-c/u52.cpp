
// $destdir/u52.c        Machine generated C code

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



// Code for rand!-mons!-sparse

static LispObject CC_randKmonsKsparse(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31252, v_31253;
    LispObject fn;
    LispObject v_30922, v_30921, v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rand-mons-sparse");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    v_30921 = va_arg(aa, LispObject);
    v_30922 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30922,v_30921,v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30918,v_30919,v_30920,v_30921,v_30922);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[0] = v_30922;
    stack[-1] = v_30921;
    stack[-2] = v_30920;
    stack[-3] = v_30919;
    stack[-8] = v_30918;
// end of prologue
    stack[-9] = nil;
    stack[-7] = nil;
    v_31252 = stack[0];
    if (v_31252 == nil) goto v_30934;
    goto v_30941;
v_30937:
    goto v_30938;
v_30939:
    goto v_30948;
v_30944:
    v_31253 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30945;
v_30946:
    v_31252 = stack[-1];
    goto v_30947;
v_30948:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    v_31252 = difference2(v_31253, v_31252);
    env = stack[-10];
    goto v_30940;
v_30941:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    v_31252 = plus2(stack[-2], v_31252);
    env = stack[-10];
    goto v_30932;
v_30934:
    v_31252 = stack[-8];
    v_31252 = Llength(nil, v_31252);
    env = stack[-10];
    stack[-9] = v_31252;
    v_31252 = stack[-1];
    v_31252 = (LispObject)zerop(v_31252);
    v_31252 = v_31252 ? lisp_true : nil;
    env = stack[-10];
    if (v_31252 == nil) goto v_30960;
    v_31252 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30958;
v_30960:
    goto v_30971;
v_30967:
    goto v_30977;
v_30973:
    stack[-4] = stack[-9];
    goto v_30974;
v_30975:
    v_31252 = stack[-1];
    v_31252 = sub1(v_31252);
    env = stack[-10];
    goto v_30976;
v_30977:
    goto v_30973;
v_30974:
    goto v_30975;
v_30976:
    v_31253 = plus2(stack[-4], v_31252);
    env = stack[-10];
    goto v_30968;
v_30969:
    v_31252 = stack[-9];
    goto v_30970;
v_30971:
    goto v_30967;
v_30968:
    goto v_30969;
v_30970:
    fn = elt(env, 1); // binomial
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_30958;
    v_31252 = nil;
v_30958:
    stack[-7] = v_31252;
    goto v_30987;
v_30983:
    goto v_30993;
v_30989:
    goto v_30999;
v_30995:
    v_31253 = stack[-9];
    goto v_30996;
v_30997:
    v_31252 = stack[-2];
    goto v_30998;
v_30999:
    goto v_30995;
v_30996:
    goto v_30997;
v_30998:
    v_31253 = plus2(v_31253, v_31252);
    env = stack[-10];
    goto v_30990;
v_30991:
    v_31252 = stack[-9];
    goto v_30992;
v_30993:
    goto v_30989;
v_30990:
    goto v_30991;
v_30992:
    fn = elt(env, 1); // binomial
    v_31253 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_30984;
v_30985:
    v_31252 = stack[-7];
    goto v_30986;
v_30987:
    goto v_30983;
v_30984:
    goto v_30985;
v_30986:
    v_31252 = difference2(v_31253, v_31252);
    env = stack[-10];
    goto v_30932;
v_30932:
    goto v_31009;
v_31005:
    stack[-2] = v_31252;
    goto v_31006;
v_31007:
    goto v_31016;
v_31012:
    v_31253 = v_31252;
    goto v_31013;
v_31014:
    v_31252 = stack[-3];
    goto v_31015;
v_31016:
    goto v_31012;
v_31013:
    goto v_31014;
v_31015:
    fn = elt(env, 2); // min
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_31008;
v_31009:
    goto v_31005;
v_31006:
    goto v_31007;
v_31008:
    fn = elt(env, 3); // rand!-comb
    v_31252 = (*qfn2(fn))(fn, stack[-2], v_31252);
    env = stack[-10];
    v_31253 = v_31252;
    v_31252 = stack[0];
    if (v_31252 == nil) goto v_31022;
    v_31252 = v_31253;
    stack[-5] = v_31252;
    v_31252 = stack[-5];
    if (v_31252 == nil) goto v_31033;
    else goto v_31034;
v_31033:
    v_31252 = nil;
    goto v_31028;
v_31034:
    v_31252 = stack[-5];
    v_31252 = qcar(v_31252);
    goto v_31046;
v_31042:
    stack[0] = stack[-8];
    goto v_31043;
v_31044:
    goto v_31053;
v_31049:
    v_31253 = v_31252;
    goto v_31050;
v_31051:
    v_31252 = stack[-1];
    goto v_31052;
v_31053:
    goto v_31049;
v_31050:
    goto v_31051;
v_31052:
    v_31252 = plus2(v_31253, v_31252);
    env = stack[-10];
    goto v_31045;
v_31046:
    goto v_31042;
v_31043:
    goto v_31044;
v_31045:
    fn = elt(env, 4); // !*kp2f
    v_31252 = (*qfn2(fn))(fn, stack[0], v_31252);
    env = stack[-10];
    v_31252 = ncons(v_31252);
    env = stack[-10];
    stack[-3] = v_31252;
    stack[-4] = v_31252;
v_31029:
    v_31252 = stack[-5];
    v_31252 = qcdr(v_31252);
    stack[-5] = v_31252;
    v_31252 = stack[-5];
    if (v_31252 == nil) goto v_31060;
    else goto v_31061;
v_31060:
    v_31252 = stack[-4];
    goto v_31028;
v_31061:
    goto v_31069;
v_31065:
    stack[-2] = stack[-3];
    goto v_31066;
v_31067:
    v_31252 = stack[-5];
    v_31252 = qcar(v_31252);
    goto v_31080;
v_31076:
    stack[0] = stack[-8];
    goto v_31077;
v_31078:
    goto v_31087;
v_31083:
    v_31253 = v_31252;
    goto v_31084;
v_31085:
    v_31252 = stack[-1];
    goto v_31086;
v_31087:
    goto v_31083;
v_31084:
    goto v_31085;
v_31086:
    v_31252 = plus2(v_31253, v_31252);
    env = stack[-10];
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    fn = elt(env, 4); // !*kp2f
    v_31252 = (*qfn2(fn))(fn, stack[0], v_31252);
    env = stack[-10];
    v_31252 = ncons(v_31252);
    env = stack[-10];
    goto v_31068;
v_31069:
    goto v_31065;
v_31066:
    goto v_31067;
v_31068:
    v_31252 = Lrplacd(nil, stack[-2], v_31252);
    env = stack[-10];
    v_31252 = stack[-3];
    v_31252 = qcdr(v_31252);
    stack[-3] = v_31252;
    goto v_31029;
v_31028:
    goto v_31020;
v_31022:
    v_31252 = v_31253;
    stack[-6] = v_31252;
    v_31252 = stack[-6];
    if (v_31252 == nil) goto v_31103;
    else goto v_31104;
v_31103:
    v_31252 = nil;
    goto v_31098;
v_31104:
    v_31252 = stack[-6];
    v_31252 = qcar(v_31252);
    stack[-2] = v_31252;
    v_31252 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31252;
    goto v_31120;
v_31116:
    stack[0] = nil;
    goto v_31117;
v_31118:
    goto v_31127;
v_31123:
    goto v_31133;
v_31129:
    v_31253 = stack[-2];
    goto v_31130;
v_31131:
    v_31252 = stack[-7];
    goto v_31132;
v_31133:
    goto v_31129;
v_31130:
    goto v_31131;
v_31132:
    v_31253 = plus2(v_31253, v_31252);
    env = stack[-10];
    goto v_31124;
v_31125:
    v_31252 = stack[-9];
    goto v_31126;
v_31127:
    goto v_31123;
v_31124:
    goto v_31125;
v_31126:
    fn = elt(env, 5); // inttovec
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_31119;
v_31120:
    goto v_31116;
v_31117:
    goto v_31118;
v_31119:
    v_31252 = cons(stack[0], v_31252);
    env = stack[-10];
    stack[-2] = v_31252;
    v_31252 = stack[-8];
    stack[0] = v_31252;
v_31140:
    v_31252 = stack[0];
    if (v_31252 == nil) goto v_31144;
    else goto v_31145;
v_31144:
    goto v_31139;
v_31145:
    v_31252 = stack[0];
    v_31252 = qcar(v_31252);
    goto v_31156;
v_31152:
    goto v_31162;
v_31158:
    v_31253 = v_31252;
    goto v_31159;
v_31160:
    v_31252 = stack[-2];
    v_31252 = qcdr(v_31252);
    stack[-2] = v_31252;
    v_31252 = qcar(v_31252);
    goto v_31161;
v_31162:
    goto v_31158;
v_31159:
    goto v_31160;
v_31161:
    fn = elt(env, 4); // !*kp2f
    v_31253 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_31153;
v_31154:
    v_31252 = stack[-1];
    goto v_31155;
v_31156:
    goto v_31152;
v_31153:
    goto v_31154;
v_31155:
    fn = elt(env, 6); // multf
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    stack[-1] = v_31252;
    v_31252 = stack[0];
    v_31252 = qcdr(v_31252);
    stack[0] = v_31252;
    goto v_31140;
v_31139:
    v_31252 = stack[-1];
    v_31252 = ncons(v_31252);
    env = stack[-10];
    stack[-4] = v_31252;
    stack[-5] = v_31252;
v_31099:
    v_31252 = stack[-6];
    v_31252 = qcdr(v_31252);
    stack[-6] = v_31252;
    v_31252 = stack[-6];
    if (v_31252 == nil) goto v_31175;
    else goto v_31176;
v_31175:
    v_31252 = stack[-5];
    goto v_31098;
v_31176:
    goto v_31184;
v_31180:
    stack[-3] = stack[-4];
    goto v_31181;
v_31182:
    v_31252 = stack[-6];
    v_31252 = qcar(v_31252);
    stack[-2] = v_31252;
    v_31252 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31252;
    goto v_31199;
v_31195:
    stack[0] = nil;
    goto v_31196;
v_31197:
    goto v_31206;
v_31202:
    goto v_31212;
v_31208:
    v_31253 = stack[-2];
    goto v_31209;
v_31210:
    v_31252 = stack[-7];
    goto v_31211;
v_31212:
    goto v_31208;
v_31209:
    goto v_31210;
v_31211:
    v_31253 = plus2(v_31253, v_31252);
    env = stack[-10];
    goto v_31203;
v_31204:
    v_31252 = stack[-9];
    goto v_31205;
v_31206:
    goto v_31202;
v_31203:
    goto v_31204;
v_31205:
    fn = elt(env, 5); // inttovec
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_31198;
v_31199:
    goto v_31195;
v_31196:
    goto v_31197;
v_31198:
    v_31252 = cons(stack[0], v_31252);
    env = stack[-10];
    stack[-2] = v_31252;
    v_31252 = stack[-8];
    stack[0] = v_31252;
v_31219:
    v_31252 = stack[0];
    if (v_31252 == nil) goto v_31223;
    else goto v_31224;
v_31223:
    goto v_31218;
v_31224:
    v_31252 = stack[0];
    v_31252 = qcar(v_31252);
    goto v_31235;
v_31231:
    goto v_31241;
v_31237:
    v_31253 = v_31252;
    goto v_31238;
v_31239:
    v_31252 = stack[-2];
    v_31252 = qcdr(v_31252);
    stack[-2] = v_31252;
    v_31252 = qcar(v_31252);
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    fn = elt(env, 4); // !*kp2f
    v_31253 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    goto v_31232;
v_31233:
    v_31252 = stack[-1];
    goto v_31234;
v_31235:
    goto v_31231;
v_31232:
    goto v_31233;
v_31234:
    fn = elt(env, 6); // multf
    v_31252 = (*qfn2(fn))(fn, v_31253, v_31252);
    env = stack[-10];
    stack[-1] = v_31252;
    v_31252 = stack[0];
    v_31252 = qcdr(v_31252);
    stack[0] = v_31252;
    goto v_31219;
v_31218:
    v_31252 = stack[-1];
    v_31252 = ncons(v_31252);
    env = stack[-10];
    goto v_31183;
v_31184:
    goto v_31180;
v_31181:
    goto v_31182;
v_31183:
    v_31252 = Lrplacd(nil, stack[-3], v_31252);
    env = stack[-10];
    v_31252 = stack[-4];
    v_31252 = qcdr(v_31252);
    stack[-4] = v_31252;
    goto v_31099;
v_31098:
    goto v_31020;
    v_31252 = nil;
v_31020:
    return onevalue(v_31252);
}



// Code for redassignp

static LispObject CC_redassignp(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30940, v_30941, v_30942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30942 = v_30918;
// end of prologue
    goto v_30929;
v_30925:
    v_30941 = v_30942;
    goto v_30926;
v_30927:
    v_30940 = elt(env, 1); // setq
    goto v_30928;
v_30929:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    if (!consp(v_30941)) goto v_30923;
    v_30941 = qcar(v_30941);
    if (v_30941 == v_30940) goto v_30922;
    else goto v_30923;
v_30922:
    v_30940 = v_30942;
    v_30940 = qcdr(v_30940);
    v_30940 = qcdr(v_30940);
    v_30940 = qcar(v_30940);
    {
        fn = elt(env, 2); // redassign1p
        return (*qfn1(fn))(fn, v_30940);
    }
v_30923:
    v_30940 = nil;
    goto v_30921;
    v_30940 = nil;
v_30921:
    return onevalue(v_30940);
}



// Code for coeff1_calc

static LispObject CC_coeff1_calc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30963, v_30964, v_30965;
    LispObject fn;
    LispObject v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff1_calc");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30918,v_30919,v_30920);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_30920;
    stack[-1] = v_30919;
    stack[-2] = v_30918;
// end of prologue
    stack[-3] = nil;
v_30925:
    v_30963 = stack[0];
    if (v_30963 == nil) goto v_30928;
    else goto v_30929;
v_30928:
    goto v_30936;
v_30932:
    stack[0] = stack[-3];
    goto v_30933;
v_30934:
    v_30963 = (LispObject)0+TAG_FIXNUM; // 0
    v_30963 = ncons(v_30963);
    env = stack[-4];
    goto v_30935;
v_30936:
    goto v_30932;
v_30933:
    goto v_30934;
v_30935:
    {
        LispObject v_30970 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_30970, v_30963);
    }
v_30929:
    goto v_30947;
v_30943:
    goto v_30955;
v_30949:
    v_30965 = stack[-2];
    goto v_30950;
v_30951:
    v_30964 = stack[-1];
    goto v_30952;
v_30953:
    v_30963 = stack[0];
    v_30963 = qcar(v_30963);
    goto v_30954;
v_30955:
    goto v_30949;
v_30950:
    goto v_30951;
v_30952:
    goto v_30953;
v_30954:
    fn = elt(env, 2); // calc_coeffmap_
    v_30964 = (*qfnn(fn))(fn, 3, v_30965, v_30964, v_30963);
    env = stack[-4];
    goto v_30944;
v_30945:
    v_30963 = stack[-3];
    goto v_30946;
v_30947:
    goto v_30943;
v_30944:
    goto v_30945;
v_30946:
    v_30963 = cons(v_30964, v_30963);
    env = stack[-4];
    stack[-3] = v_30963;
    v_30963 = stack[0];
    v_30963 = qcdr(v_30963);
    stack[0] = v_30963;
    goto v_30925;
    v_30963 = nil;
    return onevalue(v_30963);
}



// Code for clogsq

static LispObject CC_clogsq(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30918;
// end of prologue
    goto v_30925;
v_30921:
    v_30932 = stack[0];
    v_30932 = qcar(v_30932);
    fn = elt(env, 1); // clogf
    stack[-1] = (*qfn1(fn))(fn, v_30932);
    env = stack[-2];
    goto v_30922;
v_30923:
    v_30932 = stack[0];
    v_30932 = qcdr(v_30932);
    fn = elt(env, 1); // clogf
    v_30932 = (*qfn1(fn))(fn, v_30932);
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    {
        LispObject v_30935 = stack[-1];
        return cons(v_30935, v_30932);
    }
}



// Code for dp_2a

static LispObject CC_dp_2a(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30931, v_30932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30932 = v_30918;
// end of prologue
    v_30931 = v_30932;
    if (v_30931 == nil) goto v_30922;
    else goto v_30923;
v_30922:
    v_30931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30921;
v_30923:
    v_30931 = v_30932;
    fn = elt(env, 1); // dp!=2a
    v_30931 = (*qfn1(fn))(fn, v_30931);
    env = stack[0];
    {
        fn = elt(env, 2); // dp!=replus
        return (*qfn1(fn))(fn, v_30931);
    }
    v_30931 = nil;
v_30921:
    return onevalue(v_30931);
}



// Code for mod!/

static LispObject CC_modV(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30949, v_30950, v_30951, v_30952;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30949 = v_30919;
    v_30950 = v_30918;
// end of prologue
    goto v_30926;
v_30922:
    goto v_30932;
v_30928:
    stack[0] = v_30950;
    goto v_30929;
v_30930:
    goto v_30943;
v_30935:
    v_30952 = qvalue(elt(env, 1)); // current!-modulus
    goto v_30936;
v_30937:
    v_30951 = v_30949;
    goto v_30938;
v_30939:
    v_30950 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30940;
v_30941:
    v_30949 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30942;
v_30943:
    goto v_30935;
v_30936:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    goto v_30941;
v_30942:
    fn = elt(env, 2); // general!-reciprocal!-by!-gcd
    v_30949 = (*qfnn(fn))(fn, 4, v_30952, v_30951, v_30950, v_30949);
    env = stack[-1];
    goto v_30931;
v_30932:
    goto v_30928;
v_30929:
    goto v_30930;
v_30931:
    v_30949 = times2(stack[0], v_30949);
    env = stack[-1];
    goto v_30923;
v_30924:
    v_30950 = qvalue(elt(env, 1)); // current!-modulus
    goto v_30925;
v_30926:
    goto v_30922;
v_30923:
    goto v_30924;
v_30925:
    return Cremainder(v_30949, v_30950);
}



// Code for cde_alglistp

static LispObject CC_cde_alglistp(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30938, v_30939;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30918;
// end of prologue
    v_30938 = stack[0];
    fn = elt(env, 2); // listp
    v_30938 = (*qfn1(fn))(fn, v_30938);
    env = stack[-1];
    if (v_30938 == nil) goto v_30922;
    else goto v_30923;
v_30922:
    v_30938 = nil;
    goto v_30921;
v_30923:
    goto v_30933;
v_30929:
    v_30938 = stack[0];
    v_30938 = qcar(v_30938);
    goto v_30930;
v_30931:
    v_30939 = elt(env, 1); // list
    goto v_30932;
v_30933:
    goto v_30929;
v_30930:
    goto v_30931;
v_30932:
    v_30938 = (v_30938 == v_30939 ? lisp_true : nil);
    goto v_30921;
    v_30938 = nil;
v_30921:
    return onevalue(v_30938);
}



// Code for ofsf_sminsert

static LispObject CC_ofsf_sminsert(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31133, v_31134, v_31135, v_31136, v_31137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_30919;
    stack[-4] = v_30918;
// end of prologue
    stack[-5] = nil;
v_30929:
    goto v_30941;
v_30931:
    v_31133 = stack[-3];
    v_31133 = qcar(v_31133);
    v_31133 = qcdr(v_31133);
    v_31137 = qcar(v_31133);
    goto v_30932;
v_30933:
    v_31133 = stack[-3];
    v_31133 = qcar(v_31133);
    v_31133 = qcdr(v_31133);
    v_31136 = qcdr(v_31133);
    goto v_30934;
v_30935:
    v_31133 = stack[-4];
    v_31133 = qcdr(v_31133);
    v_31135 = qcar(v_31133);
    goto v_30936;
v_30937:
    v_31133 = stack[-4];
    v_31133 = qcdr(v_31133);
    v_31134 = qcdr(v_31133);
    goto v_30938;
v_30939:
    v_31133 = stack[-4];
    v_31133 = qcar(v_31133);
    goto v_30940;
v_30941:
    goto v_30931;
v_30932:
    goto v_30933;
v_30934:
    goto v_30935;
v_30936:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    fn = elt(env, 3); // ofsf_sminsert1
    v_31133 = (*qfnn(fn))(fn, 5, v_31137, v_31136, v_31135, v_31134, v_31133);
    env = stack[-6];
    stack[-2] = v_31133;
    v_31133 = stack[-2];
    if (v_31133 == nil) goto v_30961;
    v_31133 = stack[-2];
    if (symbolp(v_31133)) goto v_30961;
    v_31133 = stack[-3];
    v_31133 = qcdr(v_31133);
    stack[-3] = v_31133;
    v_31133 = stack[-2];
    stack[-4] = v_31133;
    goto v_30959;
v_30961:
v_30959:
    v_31133 = stack[-2];
    if (v_31133 == nil) goto v_30975;
    else goto v_30976;
v_30975:
    v_31133 = lisp_true;
    goto v_30974;
v_30976:
    v_31133 = stack[-2];
    v_31133 = Lsymbolp(nil, v_31133);
    env = stack[-6];
    if (v_31133 == nil) goto v_30983;
    else goto v_30982;
v_30983:
    v_31133 = stack[-3];
    v_31133 = (v_31133 == nil ? lisp_true : nil);
v_30982:
    goto v_30974;
    v_31133 = nil;
v_30974:
    if (v_31133 == nil) goto v_30971;
    else goto v_30972;
v_30971:
    goto v_30929;
v_30972:
    goto v_30996;
v_30992:
    v_31134 = stack[-2];
    goto v_30993;
v_30994:
    v_31133 = elt(env, 1); // false
    goto v_30995;
v_30996:
    goto v_30992;
v_30993:
    goto v_30994;
v_30995:
    if (v_31134 == v_31133) goto v_30990;
    else goto v_30991;
v_30990:
    v_31133 = elt(env, 1); // false
    goto v_30926;
v_30991:
    goto v_31008;
v_31004:
    v_31134 = stack[-2];
    goto v_31005;
v_31006:
    v_31133 = elt(env, 2); // true
    goto v_31007;
v_31008:
    goto v_31004;
v_31005:
    goto v_31006;
v_31007:
    if (v_31134 == v_31133) goto v_31002;
    else goto v_31003;
v_31002:
    v_31133 = stack[-3];
    goto v_30926;
v_31003:
    v_31133 = stack[-3];
    if (v_31133 == nil) goto v_31014;
    else goto v_31015;
v_31014:
    v_31133 = stack[-4];
    return ncons(v_31133);
v_31015:
    v_31133 = stack[-3];
    stack[0] = v_31133;
    v_31133 = stack[-3];
    v_31133 = qcdr(v_31133);
    stack[-1] = v_31133;
v_31024:
    v_31133 = stack[-1];
    if (v_31133 == nil) goto v_31027;
    else goto v_31028;
v_31027:
    goto v_31023;
v_31028:
    v_31133 = stack[-1];
    v_31133 = qcar(v_31133);
    stack[-5] = v_31133;
    v_31133 = stack[-1];
    v_31133 = qcdr(v_31133);
    stack[-1] = v_31133;
    goto v_31046;
v_31036:
    v_31133 = stack[-5];
    v_31133 = qcdr(v_31133);
    v_31137 = qcar(v_31133);
    goto v_31037;
v_31038:
    v_31133 = stack[-5];
    v_31133 = qcdr(v_31133);
    v_31136 = qcdr(v_31133);
    goto v_31039;
v_31040:
    v_31133 = stack[-4];
    v_31133 = qcdr(v_31133);
    v_31135 = qcar(v_31133);
    goto v_31041;
v_31042:
    v_31133 = stack[-4];
    v_31133 = qcdr(v_31133);
    v_31134 = qcdr(v_31133);
    goto v_31043;
v_31044:
    v_31133 = stack[-4];
    v_31133 = qcar(v_31133);
    goto v_31045;
v_31046:
    goto v_31036;
v_31037:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    goto v_31042;
v_31043:
    goto v_31044;
v_31045:
    fn = elt(env, 3); // ofsf_sminsert1
    v_31133 = (*qfnn(fn))(fn, 5, v_31137, v_31136, v_31135, v_31134, v_31133);
    env = stack[-6];
    stack[-2] = v_31133;
    goto v_31069;
v_31065:
    v_31134 = stack[-2];
    goto v_31066;
v_31067:
    v_31133 = elt(env, 2); // true
    goto v_31068;
v_31069:
    goto v_31065;
v_31066:
    goto v_31067;
v_31068:
    if (v_31134 == v_31133) goto v_31063;
    else goto v_31064;
v_31063:
    v_31133 = nil;
    stack[-1] = v_31133;
    v_31133 = elt(env, 2); // true
    stack[-5] = v_31133;
    goto v_31062;
v_31064:
    goto v_31080;
v_31076:
    v_31134 = stack[-2];
    goto v_31077;
v_31078:
    v_31133 = elt(env, 1); // false
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    if (v_31134 == v_31133) goto v_31074;
    else goto v_31075;
v_31074:
    v_31133 = nil;
    stack[-1] = v_31133;
    v_31133 = elt(env, 1); // false
    stack[-5] = v_31133;
    goto v_31062;
v_31075:
    v_31133 = stack[-2];
    if (v_31133 == nil) goto v_31086;
    goto v_31093;
v_31089:
    v_31134 = stack[0];
    goto v_31090;
v_31091:
    v_31133 = stack[-1];
    goto v_31092;
v_31093:
    goto v_31089;
v_31090:
    goto v_31091;
v_31092:
    fn = elt(env, 4); // setcdr
    v_31133 = (*qfn2(fn))(fn, v_31134, v_31133);
    env = stack[-6];
    v_31133 = stack[-2];
    stack[-4] = v_31133;
    goto v_31062;
v_31086:
    v_31133 = stack[0];
    v_31133 = qcdr(v_31133);
    stack[0] = v_31133;
    goto v_31062;
v_31062:
    goto v_31024;
v_31023:
    goto v_31109;
v_31105:
    v_31134 = stack[-5];
    goto v_31106;
v_31107:
    v_31133 = elt(env, 1); // false
    goto v_31108;
v_31109:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    if (v_31134 == v_31133) goto v_31103;
    else goto v_31104;
v_31103:
    v_31133 = elt(env, 1); // false
    goto v_30926;
v_31104:
    goto v_31121;
v_31117:
    v_31133 = stack[-5];
    goto v_31118;
v_31119:
    v_31134 = elt(env, 2); // true
    goto v_31120;
v_31121:
    goto v_31117;
v_31118:
    goto v_31119;
v_31120:
    if (v_31133 == v_31134) goto v_31115;
    else goto v_31116;
v_31115:
    v_31133 = stack[-3];
    goto v_30926;
v_31116:
    goto v_31130;
v_31126:
    v_31134 = stack[-4];
    goto v_31127;
v_31128:
    v_31133 = stack[-3];
    goto v_31129;
v_31130:
    goto v_31126;
v_31127:
    goto v_31128;
v_31129:
    return cons(v_31134, v_31133);
v_30926:
    return onevalue(v_31133);
}



// Code for addfactors

static LispObject CC_addfactors(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30983, v_30984, v_30985, v_30986;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_30985 = v_30919;
    v_30986 = v_30918;
// end of prologue
    goto v_30929;
v_30925:
    v_30984 = v_30986;
    goto v_30926;
v_30927:
    v_30983 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30928;
v_30929:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    if (v_30984 == v_30983) goto v_30923;
    else goto v_30924;
v_30923:
    v_30983 = v_30985;
    {
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(fn, v_30983);
    }
v_30924:
    goto v_30940;
v_30936:
    v_30984 = v_30985;
    goto v_30937;
v_30938:
    v_30983 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    if (v_30984 == v_30983) goto v_30934;
    else goto v_30935;
v_30934:
    v_30983 = v_30986;
    goto v_30922;
v_30935:
    goto v_30951;
v_30947:
    v_30984 = v_30986;
    goto v_30948;
v_30949:
    v_30983 = elt(env, 1); // times
    goto v_30950;
v_30951:
    goto v_30947;
v_30948:
    goto v_30949;
v_30950:
    if (!consp(v_30984)) goto v_30945;
    v_30984 = qcar(v_30984);
    if (v_30984 == v_30983) goto v_30944;
    else goto v_30945;
v_30944:
    goto v_30959;
v_30955:
    stack[-1] = elt(env, 1); // times
    goto v_30956;
v_30957:
    goto v_30966;
v_30962:
    v_30983 = v_30986;
    stack[0] = qcdr(v_30983);
    goto v_30963;
v_30964:
    v_30983 = v_30985;
    fn = elt(env, 2); // prepf
    v_30983 = (*qfn1(fn))(fn, v_30983);
    env = stack[-2];
    goto v_30965;
v_30966:
    goto v_30962;
v_30963:
    goto v_30964;
v_30965:
    fn = elt(env, 3); // aconc!*
    v_30983 = (*qfn2(fn))(fn, stack[0], v_30983);
    goto v_30958;
v_30959:
    goto v_30955;
v_30956:
    goto v_30957;
v_30958:
    {
        LispObject v_30989 = stack[-1];
        return cons(v_30989, v_30983);
    }
v_30945:
    goto v_30979;
v_30975:
    stack[0] = v_30986;
    goto v_30976;
v_30977:
    v_30983 = v_30985;
    fn = elt(env, 2); // prepf
    v_30983 = (*qfn1(fn))(fn, v_30983);
    env = stack[-2];
    goto v_30978;
v_30979:
    goto v_30975;
v_30976:
    goto v_30977;
v_30978:
    v_30983 = list2(stack[0], v_30983);
    env = stack[-2];
    {
        fn = elt(env, 4); // retimes
        return (*qfn1(fn))(fn, v_30983);
    }
    v_30983 = nil;
v_30922:
    return onevalue(v_30983);
}



// Code for subdf

static LispObject CC_subdf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31029, v_31030, v_31031;
    LispObject fn;
    LispObject v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subdf");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30918,v_30919,v_30920);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_30920;
    stack[-3] = v_30919;
    stack[-4] = v_30918;
// end of prologue
v_30917:
    v_31029 = stack[-4];
    if (v_31029 == nil) goto v_30924;
    else goto v_30925;
v_30924:
    v_31029 = nil;
    goto v_30923;
v_30925:
    goto v_30939;
v_30935:
    v_31029 = stack[-4];
    v_31029 = qcar(v_31029);
    v_31029 = qcdr(v_31029);
    stack[0] = qcar(v_31029);
    goto v_30936;
v_30937:
    goto v_30950;
v_30946:
    v_31030 = stack[-2];
    goto v_30947;
v_30948:
    v_31029 = stack[-3];
    goto v_30949;
v_30950:
    goto v_30946;
v_30947:
    goto v_30948;
v_30949:
    v_31029 = cons(v_31030, v_31029);
    env = stack[-6];
    v_31029 = ncons(v_31029);
    env = stack[-6];
    goto v_30938;
v_30939:
    goto v_30935;
v_30936:
    goto v_30937;
v_30938:
    fn = elt(env, 1); // subf
    v_31029 = (*qfn2(fn))(fn, stack[0], v_31029);
    env = stack[-6];
    fn = elt(env, 2); // subs2q
    v_31029 = (*qfn1(fn))(fn, v_31029);
    env = stack[-6];
    stack[-5] = v_31029;
    goto v_30961;
v_30957:
    stack[0] = stack[-5];
    goto v_30958;
v_30959:
    goto v_30968;
v_30964:
    v_31030 = nil;
    goto v_30965;
v_30966:
    v_31029 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30967;
v_30968:
    goto v_30964;
v_30965:
    goto v_30966;
v_30967:
    v_31029 = cons(v_31030, v_31029);
    env = stack[-6];
    goto v_30960;
v_30961:
    goto v_30957;
v_30958:
    goto v_30959;
v_30960:
    if (equal(stack[0], v_31029)) goto v_30955;
    else goto v_30956;
v_30955:
    goto v_30978;
v_30972:
    v_31029 = stack[-4];
    v_31031 = qcdr(v_31029);
    goto v_30973;
v_30974:
    v_31030 = stack[-3];
    goto v_30975;
v_30976:
    v_31029 = stack[-2];
    goto v_30977;
v_30978:
    goto v_30972;
v_30973:
    goto v_30974;
v_30975:
    goto v_30976;
v_30977:
    stack[-4] = v_31031;
    stack[-3] = v_31030;
    stack[-2] = v_31029;
    goto v_30917;
v_30956:
    goto v_30990;
v_30986:
    goto v_30999;
v_30993:
    v_31029 = stack[-4];
    v_31029 = qcar(v_31029);
    stack[-1] = qcar(v_31029);
    goto v_30994;
v_30995:
    v_31029 = stack[-5];
    stack[0] = qcar(v_31029);
    goto v_30996;
v_30997:
    goto v_31010;
v_31006:
    v_31029 = stack[-5];
    v_31030 = qcdr(v_31029);
    goto v_31007;
v_31008:
    v_31029 = stack[-4];
    v_31029 = qcar(v_31029);
    v_31029 = qcdr(v_31029);
    v_31029 = qcdr(v_31029);
    goto v_31009;
v_31010:
    goto v_31006;
v_31007:
    goto v_31008;
v_31009:
    fn = elt(env, 3); // !*multf
    v_31029 = (*qfn2(fn))(fn, v_31030, v_31029);
    env = stack[-6];
    goto v_30998;
v_30999:
    goto v_30993;
v_30994:
    goto v_30995;
v_30996:
    goto v_30997;
v_30998:
    v_31029 = list2star(stack[-1], stack[0], v_31029);
    env = stack[-6];
    stack[0] = ncons(v_31029);
    env = stack[-6];
    goto v_30987;
v_30988:
    goto v_31024;
v_31018:
    v_31029 = stack[-4];
    v_31031 = qcdr(v_31029);
    goto v_31019;
v_31020:
    v_31030 = stack[-3];
    goto v_31021;
v_31022:
    v_31029 = stack[-2];
    goto v_31023;
v_31024:
    goto v_31018;
v_31019:
    goto v_31020;
v_31021:
    goto v_31022;
v_31023:
    v_31029 = CC_subdf(elt(env, 0), 3, v_31031, v_31030, v_31029);
    env = stack[-6];
    goto v_30989;
v_30990:
    goto v_30986;
v_30987:
    goto v_30988;
v_30989:
    {
        LispObject v_31038 = stack[0];
        fn = elt(env, 4); // plusdf
        return (*qfn2(fn))(fn, v_31038, v_31029);
    }
    v_31029 = nil;
    goto v_30923;
    v_31029 = nil;
v_30923:
    return onevalue(v_31029);
}



// Code for cl_strict!-gdnf

static LispObject CC_cl_strictKgdnf(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30957, v_30958, v_30959;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30919;
    v_30957 = v_30918;
// end of prologue
    goto v_30929;
v_30925:
    goto v_30937;
v_30931:
    goto v_30943;
v_30939:
    v_30958 = v_30957;
    goto v_30940;
v_30941:
    v_30957 = stack[0];
    goto v_30942;
v_30943:
    goto v_30939;
v_30940:
    goto v_30941;
v_30942:
    fn = elt(env, 1); // cl_strict!-gdnf1
    v_30959 = (*qfn2(fn))(fn, v_30958, v_30957);
    env = stack[-1];
    goto v_30932;
v_30933:
    v_30958 = nil;
    goto v_30934;
v_30935:
    v_30957 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_30936;
v_30937:
    goto v_30931;
v_30932:
    goto v_30933;
v_30934:
    goto v_30935;
v_30936:
    fn = elt(env, 2); // rl_simpl
    v_30958 = (*qfnn(fn))(fn, 3, v_30959, v_30958, v_30957);
    env = stack[-1];
    goto v_30926;
v_30927:
    v_30957 = stack[0];
    goto v_30928;
v_30929:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    fn = elt(env, 3); // cl_mkstrict
    v_30957 = (*qfn2(fn))(fn, v_30958, v_30957);
    env = stack[-1];
    goto v_30954;
v_30950:
    v_30958 = v_30957;
    goto v_30951;
v_30952:
    v_30957 = stack[0];
    goto v_30953;
v_30954:
    goto v_30950;
v_30951:
    goto v_30952;
v_30953:
    {
        fn = elt(env, 4); // rl_bnfsimpl
        return (*qfn2(fn))(fn, v_30958, v_30957);
    }
    return onevalue(v_30957);
}



// Code for make!-image!-mod!-p

static LispObject CC_makeKimageKmodKp(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30960, v_30961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30919;
    stack[-1] = v_30918;
// end of prologue
    goto v_30929;
v_30925:
    v_30961 = stack[-1];
    goto v_30926;
v_30927:
    v_30960 = stack[0];
    goto v_30928;
v_30929:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    fn = elt(env, 2); // degree!-in!-variable
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-3];
    stack[-2] = v_30960;
    goto v_30937;
v_30933:
    v_30961 = stack[-1];
    goto v_30934;
v_30935:
    v_30960 = stack[0];
    goto v_30936;
v_30937:
    goto v_30933;
v_30934:
    goto v_30935;
v_30936:
    fn = elt(env, 3); // make!-univariate!-image!-mod!-p
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-3];
    stack[-1] = v_30960;
    goto v_30948;
v_30944:
    goto v_30954;
v_30950:
    v_30961 = stack[-1];
    goto v_30951;
v_30952:
    v_30960 = stack[0];
    goto v_30953;
v_30954:
    goto v_30950;
v_30951:
    goto v_30952;
v_30953:
    fn = elt(env, 2); // degree!-in!-variable
    v_30961 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-3];
    goto v_30945;
v_30946:
    v_30960 = stack[-2];
    goto v_30947;
v_30948:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    if (equal(v_30961, v_30960)) goto v_30943;
    v_30960 = lisp_true;
    qvalue(elt(env, 1)) = v_30960; // unlucky!-case
    goto v_30941;
v_30943:
v_30941:
    v_30960 = stack[-1];
    return onevalue(v_30960);
}



// Code for getvariables

static LispObject CC_getvariables(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30937, v_30938;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30938 = v_30918;
// end of prologue
    goto v_30925;
v_30921:
    v_30937 = v_30938;
    stack[0] = qcar(v_30937);
    goto v_30922;
v_30923:
    goto v_30933;
v_30929:
    v_30937 = v_30938;
    v_30938 = qcdr(v_30937);
    goto v_30930;
v_30931:
    v_30937 = nil;
    goto v_30932;
v_30933:
    goto v_30929;
v_30930:
    goto v_30931;
v_30932:
    fn = elt(env, 1); // varsinsf
    v_30937 = (*qfn2(fn))(fn, v_30938, v_30937);
    env = stack[-1];
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    {
        LispObject v_30940 = stack[0];
        fn = elt(env, 1); // varsinsf
        return (*qfn2(fn))(fn, v_30940, v_30937);
    }
}



// Code for indordlp

static LispObject CC_indordlp(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30993, v_30994, v_30995, v_30996;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30994 = v_30919;
    v_30995 = v_30918;
// end of prologue
v_30923:
    v_30993 = v_30995;
    if (v_30993 == nil) goto v_30926;
    else goto v_30927;
v_30926:
    v_30993 = nil;
    goto v_30922;
v_30927:
    v_30993 = v_30994;
    if (v_30993 == nil) goto v_30930;
    else goto v_30931;
v_30930:
    v_30993 = lisp_true;
    goto v_30922;
v_30931:
    goto v_30940;
v_30936:
    v_30993 = v_30995;
    v_30996 = qcar(v_30993);
    goto v_30937;
v_30938:
    v_30993 = v_30994;
    v_30993 = qcar(v_30993);
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    if (equal(v_30996, v_30993)) goto v_30934;
    else goto v_30935;
v_30934:
    v_30993 = v_30995;
    v_30993 = qcdr(v_30993);
    v_30995 = v_30993;
    v_30993 = v_30994;
    v_30993 = qcdr(v_30993);
    v_30994 = v_30993;
    goto v_30923;
v_30935:
    v_30993 = v_30995;
    v_30993 = qcar(v_30993);
    if (!consp(v_30993)) goto v_30949;
    else goto v_30950;
v_30949:
    v_30993 = v_30994;
    v_30993 = qcar(v_30993);
    if (!consp(v_30993)) goto v_30955;
    else goto v_30956;
v_30955:
    goto v_30964;
v_30960:
    v_30993 = v_30995;
    v_30993 = qcar(v_30993);
    goto v_30961;
v_30962:
    v_30994 = qcar(v_30994);
    goto v_30963;
v_30964:
    goto v_30960;
v_30961:
    goto v_30962;
v_30963:
    {
        fn = elt(env, 1); // indordp
        return (*qfn2(fn))(fn, v_30993, v_30994);
    }
v_30956:
    v_30993 = lisp_true;
    goto v_30922;
    goto v_30925;
v_30950:
    v_30993 = v_30994;
    v_30993 = qcar(v_30993);
    if (!consp(v_30993)) goto v_30972;
    else goto v_30973;
v_30972:
    v_30993 = nil;
    goto v_30922;
v_30973:
    goto v_30984;
v_30980:
    v_30993 = v_30995;
    v_30993 = qcar(v_30993);
    v_30993 = qcdr(v_30993);
    v_30993 = qcar(v_30993);
    goto v_30981;
v_30982:
    v_30994 = qcar(v_30994);
    v_30994 = qcdr(v_30994);
    v_30994 = qcar(v_30994);
    goto v_30983;
v_30984:
    goto v_30980;
v_30981:
    goto v_30982;
v_30983:
    {
        fn = elt(env, 1); // indordp
        return (*qfn2(fn))(fn, v_30993, v_30994);
    }
v_30925:
    v_30993 = nil;
v_30922:
    return onevalue(v_30993);
}



// Code for adjp

static LispObject CC_adjp(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_31018, v_31019;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30918;
// end of prologue
    goto v_30928;
v_30924:
    v_31019 = stack[-1];
    goto v_30925;
v_30926:
    v_31018 = elt(env, 1); // unit
    goto v_30927;
v_30928:
    goto v_30924;
v_30925:
    goto v_30926;
v_30927:
    if (v_31019 == v_31018) goto v_30922;
    else goto v_30923;
v_30922:
    v_31018 = stack[-1];
    goto v_30921;
v_30923:
    v_31018 = stack[-1];
    if (!consp(v_31018)) goto v_30932;
    else goto v_30933;
v_30932:
    goto v_30940;
v_30936:
    v_31018 = stack[-1];
    goto v_30937;
v_30938:
    v_31019 = elt(env, 2); // adjoint
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    return get(v_31018, v_31019);
v_30933:
    goto v_30949;
v_30945:
    v_31018 = stack[-1];
    v_31019 = qcar(v_31018);
    goto v_30946;
v_30947:
    v_31018 = elt(env, 3); // comm
    goto v_30948;
v_30949:
    goto v_30945;
v_30946:
    goto v_30947;
v_30948:
    if (v_31019 == v_31018) goto v_30943;
    else goto v_30944;
v_30943:
    goto v_30960;
v_30954:
    stack[-2] = elt(env, 3); // comm
    goto v_30955;
v_30956:
    v_31018 = stack[-1];
    v_31018 = qcdr(v_31018);
    v_31018 = qcdr(v_31018);
    v_31018 = qcar(v_31018);
    stack[0] = CC_adjp(elt(env, 0), v_31018);
    env = stack[-3];
    goto v_30957;
v_30958:
    v_31018 = stack[-1];
    v_31018 = qcdr(v_31018);
    v_31018 = qcar(v_31018);
    v_31018 = CC_adjp(elt(env, 0), v_31018);
    goto v_30959;
v_30960:
    goto v_30954;
v_30955:
    goto v_30956;
v_30957:
    goto v_30958;
v_30959:
    {
        LispObject v_31023 = stack[-2];
        LispObject v_31024 = stack[0];
        return list3(v_31023, v_31024, v_31018);
    }
v_30944:
    goto v_30977;
v_30973:
    v_31018 = stack[-1];
    v_31019 = qcar(v_31018);
    goto v_30974;
v_30975:
    v_31018 = elt(env, 4); // anticomm
    goto v_30976;
v_30977:
    goto v_30973;
v_30974:
    goto v_30975;
v_30976:
    if (v_31019 == v_31018) goto v_30971;
    else goto v_30972;
v_30971:
    goto v_30988;
v_30982:
    stack[-2] = elt(env, 4); // anticomm
    goto v_30983;
v_30984:
    v_31018 = stack[-1];
    v_31018 = qcdr(v_31018);
    v_31018 = qcar(v_31018);
    stack[0] = CC_adjp(elt(env, 0), v_31018);
    env = stack[-3];
    goto v_30985;
v_30986:
    v_31018 = stack[-1];
    v_31018 = qcdr(v_31018);
    v_31018 = qcdr(v_31018);
    v_31018 = qcar(v_31018);
    v_31018 = CC_adjp(elt(env, 0), v_31018);
    goto v_30987;
v_30988:
    goto v_30982;
v_30983:
    goto v_30984;
v_30985:
    goto v_30986;
v_30987:
    {
        LispObject v_31025 = stack[-2];
        LispObject v_31026 = stack[0];
        return list3(v_31025, v_31026, v_31018);
    }
v_30972:
    goto v_31006;
v_31002:
    goto v_31012;
v_31008:
    v_31018 = stack[-1];
    v_31019 = qcar(v_31018);
    goto v_31009;
v_31010:
    v_31018 = elt(env, 2); // adjoint
    goto v_31011;
v_31012:
    goto v_31008;
v_31009:
    goto v_31010;
v_31011:
    v_31019 = get(v_31019, v_31018);
    goto v_31003;
v_31004:
    v_31018 = stack[-1];
    v_31018 = qcdr(v_31018);
    goto v_31005;
v_31006:
    goto v_31002;
v_31003:
    goto v_31004;
v_31005:
    return cons(v_31019, v_31018);
    v_31018 = nil;
v_30921:
    return onevalue(v_31018);
}



// Code for store_edges

static LispObject CC_store_edges(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30978, v_30979;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_30978 = v_30918;
// end of prologue
    stack[-3] = v_30978;
    v_30978 = stack[-3];
    if (v_30978 == nil) goto v_30929;
    else goto v_30930;
v_30929:
    v_30978 = nil;
    goto v_30924;
v_30930:
    v_30978 = stack[-3];
    v_30978 = qcar(v_30978);
    goto v_30942;
v_30938:
    v_30979 = v_30978;
    v_30979 = qcar(v_30979);
    goto v_30939;
v_30940:
    v_30978 = qcdr(v_30978);
    goto v_30941;
v_30942:
    goto v_30938;
v_30939:
    goto v_30940;
v_30941:
    v_30978 = cons(v_30979, v_30978);
    env = stack[-4];
    v_30978 = ncons(v_30978);
    env = stack[-4];
    stack[-1] = v_30978;
    stack[-2] = v_30978;
v_30925:
    v_30978 = stack[-3];
    v_30978 = qcdr(v_30978);
    stack[-3] = v_30978;
    v_30978 = stack[-3];
    if (v_30978 == nil) goto v_30951;
    else goto v_30952;
v_30951:
    v_30978 = stack[-2];
    goto v_30924;
v_30952:
    goto v_30960;
v_30956:
    stack[0] = stack[-1];
    goto v_30957;
v_30958:
    v_30978 = stack[-3];
    v_30978 = qcar(v_30978);
    goto v_30971;
v_30967:
    v_30979 = v_30978;
    v_30979 = qcar(v_30979);
    goto v_30968;
v_30969:
    v_30978 = qcdr(v_30978);
    goto v_30970;
v_30971:
    goto v_30967;
v_30968:
    goto v_30969;
v_30970:
    v_30978 = cons(v_30979, v_30978);
    env = stack[-4];
    v_30978 = ncons(v_30978);
    env = stack[-4];
    goto v_30959;
v_30960:
    goto v_30956;
v_30957:
    goto v_30958;
v_30959:
    v_30978 = Lrplacd(nil, stack[0], v_30978);
    env = stack[-4];
    v_30978 = stack[-1];
    v_30978 = qcdr(v_30978);
    stack[-1] = v_30978;
    goto v_30925;
v_30924:
    return onevalue(v_30978);
}



// Code for lchk

static LispObject CC_lchk(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30981, v_30982;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30918;
// end of prologue
    v_30981 = stack[0];
    if (v_30981 == nil) goto v_30930;
    else goto v_30931;
v_30930:
    v_30981 = lisp_true;
    goto v_30929;
v_30931:
    v_30981 = stack[0];
    v_30981 = qcar(v_30981);
    v_30981 = (consp(v_30981) ? nil : lisp_true);
    goto v_30929;
    v_30981 = nil;
v_30929:
    if (v_30981 == nil) goto v_30927;
    v_30981 = nil;
    goto v_30922;
v_30927:
    v_30981 = stack[0];
    v_30981 = qcar(v_30981);
    v_30981 = Llength(nil, v_30981);
    env = stack[-2];
    stack[-1] = v_30981;
v_30945:
    v_30981 = stack[0];
    v_30981 = qcdr(v_30981);
    stack[0] = v_30981;
    v_30981 = stack[0];
    if (v_30981 == nil) goto v_30954;
    else goto v_30955;
v_30954:
    v_30981 = lisp_true;
    goto v_30953;
v_30955:
    v_30981 = stack[0];
    v_30981 = qcar(v_30981);
    if (!consp(v_30981)) goto v_30962;
    else goto v_30963;
v_30962:
    v_30981 = lisp_true;
    goto v_30961;
v_30963:
    goto v_30974;
v_30970:
    v_30981 = stack[0];
    v_30981 = qcar(v_30981);
    v_30982 = Llength(nil, v_30981);
    env = stack[-2];
    goto v_30971;
v_30972:
    v_30981 = stack[-1];
    goto v_30973;
v_30974:
    goto v_30970;
v_30971:
    goto v_30972;
v_30973:
    v_30981 = Lneq(nil, v_30982, v_30981);
    env = stack[-2];
    goto v_30961;
    v_30981 = nil;
v_30961:
    goto v_30953;
    v_30981 = nil;
v_30953:
    if (v_30981 == nil) goto v_30950;
    else goto v_30951;
v_30950:
    goto v_30945;
v_30951:
    v_30981 = stack[0];
    v_30981 = (v_30981 == nil ? lisp_true : nil);
v_30922:
    return onevalue(v_30981);
}



// Code for cr2rderr

static LispObject CC_cr2rderr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30927, v_30928;
    LispObject fn;
    argcheck(nargs, 0, "cr2rderr");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_30924;
v_30920:
    v_30928 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30921;
v_30922:
    v_30927 = elt(env, 1); // "complex to real type conversion requires zero imaginary part"
    goto v_30923;
v_30924:
    goto v_30920;
v_30921:
    goto v_30922;
v_30923:
    {
        fn = elt(env, 2); // error
        return (*qfn2(fn))(fn, v_30928, v_30927);
    }
}



// Code for cde_list2id

static LispObject CC_cde_list2id(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30981, v_30982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_30982 = v_30918;
// end of prologue
    v_30981 = v_30982;
    if (!consp(v_30981)) goto v_30922;
    else goto v_30923;
v_30922:
    v_30981 = elt(env, 1); // "argument for cde_list2id must be a list"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_30981);
    }
v_30923:
    v_30981 = v_30982;
    stack[-3] = v_30981;
v_30936:
    v_30981 = stack[-3];
    if (v_30981 == nil) goto v_30941;
    else goto v_30942;
v_30941:
    v_30981 = nil;
    goto v_30935;
v_30942:
    v_30981 = stack[-3];
    v_30981 = qcar(v_30981);
    v_30981 = Lexplode(nil, v_30981);
    env = stack[-4];
    stack[-2] = v_30981;
    v_30981 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_30981 = (*qfn1(fn))(fn, v_30981);
    env = stack[-4];
    stack[-1] = v_30981;
    v_30981 = stack[-3];
    v_30981 = qcdr(v_30981);
    stack[-3] = v_30981;
    v_30981 = stack[-1];
    if (!consp(v_30981)) goto v_30956;
    else goto v_30957;
v_30956:
    goto v_30936;
v_30957:
v_30937:
    v_30981 = stack[-3];
    if (v_30981 == nil) goto v_30961;
    else goto v_30962;
v_30961:
    v_30981 = stack[-2];
    goto v_30935;
v_30962:
    goto v_30970;
v_30966:
    stack[0] = stack[-1];
    goto v_30967;
v_30968:
    v_30981 = stack[-3];
    v_30981 = qcar(v_30981);
    v_30981 = Lexplode(nil, v_30981);
    env = stack[-4];
    goto v_30969;
v_30970:
    goto v_30966;
v_30967:
    goto v_30968;
v_30969:
    v_30981 = Lrplacd(nil, stack[0], v_30981);
    env = stack[-4];
    v_30981 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_30981 = (*qfn1(fn))(fn, v_30981);
    env = stack[-4];
    stack[-1] = v_30981;
    v_30981 = stack[-3];
    v_30981 = qcdr(v_30981);
    stack[-3] = v_30981;
    goto v_30937;
v_30935:
    v_30981 = Lcompress(nil, v_30981);
        return Lintern(nil, v_30981);
    v_30981 = nil;
    return onevalue(v_30981);
}



// Code for sfto_deggcd1

static LispObject CC_sfto_deggcd1(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31010, v_31011, v_31012;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30919;
    stack[-2] = v_30918;
// end of prologue
    v_31010 = (LispObject)0+TAG_FIXNUM; // 0
    v_31012 = v_31010;
    v_31010 = lisp_true;
    stack[-3] = v_31010;
v_30929:
    v_31010 = stack[-3];
    if (v_31010 == nil) goto v_30932;
    goto v_30941;
v_30937:
    v_31011 = v_31012;
    goto v_30938;
v_30939:
    v_31010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30940;
v_30941:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    if (v_31011 == v_31010) goto v_30932;
    goto v_30933;
v_30932:
    goto v_30928;
v_30933:
    v_31010 = stack[-2];
    if (!consp(v_31010)) goto v_30951;
    else goto v_30952;
v_30951:
    v_31010 = lisp_true;
    goto v_30950;
v_30952:
    v_31010 = stack[-2];
    v_31010 = qcar(v_31010);
    v_31010 = (consp(v_31010) ? nil : lisp_true);
    goto v_30950;
    v_31010 = nil;
v_30950:
    if (v_31010 == nil) goto v_30948;
    v_31010 = nil;
    stack[-3] = v_31010;
    goto v_30946;
v_30948:
    goto v_30971;
v_30967:
    v_31010 = stack[-2];
    v_31010 = qcar(v_31010);
    v_31010 = qcar(v_31010);
    v_31011 = qcar(v_31010);
    goto v_30968;
v_30969:
    v_31010 = stack[-1];
    goto v_30970;
v_30971:
    goto v_30967;
v_30968:
    goto v_30969;
v_30970:
    if (v_31011 == v_31010) goto v_30965;
    else goto v_30966;
v_30965:
    goto v_30982;
v_30978:
    v_31011 = v_31012;
    goto v_30979;
v_30980:
    v_31010 = stack[-2];
    v_31010 = qcar(v_31010);
    v_31010 = qcar(v_31010);
    v_31010 = qcdr(v_31010);
    goto v_30981;
v_30982:
    goto v_30978;
v_30979:
    goto v_30980;
v_30981:
    v_31010 = Lgcd(nil, v_31011, v_31010);
    env = stack[-4];
    v_31012 = v_31010;
    goto v_30964;
v_30966:
    goto v_30995;
v_30991:
    stack[0] = v_31012;
    goto v_30992;
v_30993:
    goto v_31002;
v_30998:
    v_31010 = stack[-2];
    v_31010 = qcar(v_31010);
    v_31011 = qcdr(v_31010);
    goto v_30999;
v_31000:
    v_31010 = stack[-1];
    goto v_31001;
v_31002:
    goto v_30998;
v_30999:
    goto v_31000;
v_31001:
    v_31010 = CC_sfto_deggcd1(elt(env, 0), v_31011, v_31010);
    env = stack[-4];
    goto v_30994;
v_30995:
    goto v_30991;
v_30992:
    goto v_30993;
v_30994:
    v_31010 = Lgcd(nil, stack[0], v_31010);
    env = stack[-4];
    v_31012 = v_31010;
    goto v_30964;
v_30964:
    v_31010 = stack[-2];
    v_31010 = qcdr(v_31010);
    stack[-2] = v_31010;
    goto v_30946;
v_30946:
    goto v_30929;
v_30928:
    v_31010 = v_31012;
    return onevalue(v_31010);
}



// Code for preptaylor!*!*

static LispObject CC_preptaylorHH(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30930, v_30931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30931 = v_30918;
// end of prologue
    v_30930 = qvalue(elt(env, 1)); // convert!-taylor!*
    if (v_30930 == nil) goto v_30922;
    else goto v_30923;
v_30922:
    v_30930 = v_30931;
    goto v_30921;
v_30923:
    v_30930 = v_30931;
    {
        fn = elt(env, 2); // preptaylor!*
        return (*qfn1(fn))(fn, v_30930);
    }
    v_30930 = nil;
v_30921:
    return onevalue(v_30930);
}



// Code for simpx1

static LispObject CC_simpx1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31807, v_31808, v_31809;
    LispObject fn;
    LispObject v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpx1");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30918,v_30919,v_30920);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_30920;
    stack[-1] = v_30919;
    stack[-4] = v_30918;
// end of prologue
    stack[-6] = nil;
    goto v_30938;
v_30934:
    v_31808 = stack[-4];
    goto v_30935;
v_30936:
    v_31807 = elt(env, 1); // !*minus!*
    goto v_30937;
v_30938:
    goto v_30934;
v_30935:
    goto v_30936;
v_30937:
    if (!consp(v_31808)) goto v_30932;
    v_31808 = qcar(v_31808);
    if (v_31808 == v_31807) goto v_30931;
    else goto v_30932;
v_30931:
    goto v_30954;
v_30950:
    v_31808 = stack[-1];
    goto v_30951;
v_30952:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30953;
v_30954:
    goto v_30950;
v_30951:
    goto v_30952;
v_30953:
    if (v_31808 == v_31807) goto v_30948;
    else goto v_30949;
v_30948:
    v_31807 = stack[-3];
    v_31807 = integerp(v_31807);
    if (v_31807 == nil) goto v_30959;
    else goto v_30960;
v_30959:
    v_31807 = nil;
    goto v_30958;
v_30960:
    goto v_30970;
v_30966:
    goto v_30976;
v_30972:
    v_31808 = stack[-3];
    goto v_30973;
v_30974:
    v_31807 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30975;
v_30976:
    goto v_30972;
v_30973:
    goto v_30974;
v_30975:
    v_31808 = Cremainder(v_31808, v_31807);
    env = stack[-7];
    goto v_30967;
v_30968:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30969;
v_30970:
    goto v_30966;
v_30967:
    goto v_30968;
v_30969:
    v_31807 = (v_31808 == v_31807 ? lisp_true : nil);
    goto v_30958;
    v_31807 = nil;
v_30958:
    goto v_30947;
v_30949:
    v_31807 = nil;
    goto v_30947;
    v_31807 = nil;
v_30947:
    if (v_31807 == nil) goto v_30945;
    else goto v_30943;
v_30945:
    goto v_30993;
v_30989:
    v_31808 = stack[-3];
    goto v_30990;
v_30991:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30992;
v_30993:
    goto v_30989;
v_30990:
    goto v_30991;
v_30992:
    if (v_31808 == v_31807) goto v_30987;
    else goto v_30988;
v_30987:
    goto v_31005;
v_31001:
    v_31808 = stack[-1];
    goto v_31002;
v_31003:
    v_31807 = elt(env, 2); // quotient
    goto v_31004;
v_31005:
    goto v_31001;
v_31002:
    goto v_31003;
v_31004:
    if (!consp(v_31808)) goto v_30999;
    v_31808 = qcar(v_31808);
    if (v_31808 == v_31807) goto v_30998;
    else goto v_30999;
v_30998:
    goto v_31016;
v_31012:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31808 = qcar(v_31807);
    goto v_31013;
v_31014:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31015;
v_31016:
    goto v_31012;
v_31013:
    goto v_31014;
v_31015:
    if (v_31808 == v_31807) goto v_31010;
    else goto v_31011;
v_31010:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    v_31807 = integerp(v_31807);
    if (v_31807 == nil) goto v_31023;
    else goto v_31024;
v_31023:
    v_31807 = nil;
    goto v_31022;
v_31024:
    goto v_31037;
v_31033:
    goto v_31043;
v_31039:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    v_31808 = qcar(v_31807);
    goto v_31040;
v_31041:
    v_31807 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31042;
v_31043:
    goto v_31039;
v_31040:
    goto v_31041;
v_31042:
    v_31808 = Cremainder(v_31808, v_31807);
    env = stack[-7];
    goto v_31034;
v_31035:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31036;
v_31037:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    v_31807 = (v_31808 == v_31807 ? lisp_true : nil);
    goto v_31022;
    v_31807 = nil;
v_31022:
    goto v_31009;
v_31011:
    v_31807 = nil;
    goto v_31009;
    v_31807 = nil;
v_31009:
    goto v_30997;
v_30999:
    v_31807 = nil;
    goto v_30997;
    v_31807 = nil;
v_30997:
    goto v_30986;
v_30988:
    v_31807 = nil;
    goto v_30986;
    v_31807 = nil;
v_30986:
    if (v_31807 == nil) goto v_30984;
    else goto v_30943;
v_30984:
    goto v_30944;
v_30943:
    goto v_31065;
v_31061:
    goto v_31074;
v_31068:
    stack[-6] = elt(env, 3); // expt
    goto v_31069;
v_31070:
    stack[-5] = elt(env, 4); // i
    goto v_31071;
v_31072:
    goto v_31084;
v_31078:
    stack[-2] = elt(env, 2); // quotient
    goto v_31079;
v_31080:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31081;
v_31082:
    goto v_31092;
v_31088:
    v_31808 = stack[-3];
    goto v_31089;
v_31090:
    v_31807 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31091;
v_31092:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    v_31807 = quot2(v_31808, v_31807);
    env = stack[-7];
    goto v_31083;
v_31084:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    goto v_31082;
v_31083:
    v_31807 = list3(stack[-2], stack[0], v_31807);
    env = stack[-7];
    goto v_31073;
v_31074:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    goto v_31072;
v_31073:
    v_31807 = list3(stack[-6], stack[-5], v_31807);
    env = stack[-7];
    fn = elt(env, 18); // simp
    stack[0] = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    goto v_31062;
v_31063:
    goto v_31101;
v_31097:
    v_31807 = stack[-4];
    v_31807 = qcdr(v_31807);
    stack[-2] = qcar(v_31807);
    goto v_31098;
v_31099:
    goto v_31112;
v_31106:
    v_31809 = elt(env, 2); // quotient
    goto v_31107;
v_31108:
    v_31808 = stack[-1];
    goto v_31109;
v_31110:
    v_31807 = stack[-3];
    goto v_31111;
v_31112:
    goto v_31106;
v_31107:
    goto v_31108;
v_31109:
    goto v_31110;
v_31111:
    v_31807 = list3(v_31809, v_31808, v_31807);
    env = stack[-7];
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    v_31807 = list2(stack[-2], v_31807);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    goto v_31064;
v_31065:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    {
        LispObject v_31817 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_31817, v_31807);
    }
v_30944:
    goto v_31126;
v_31122:
    v_31808 = stack[-1];
    goto v_31123;
v_31124:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31125;
v_31126:
    goto v_31122;
v_31123:
    goto v_31124;
v_31125:
    if (v_31808 == v_31807) goto v_31120;
    else goto v_31121;
v_31120:
    v_31807 = stack[-3];
    v_31807 = integerp(v_31807);
    goto v_31119;
v_31121:
    v_31807 = nil;
    goto v_31119;
    v_31807 = nil;
v_31119:
    if (v_31807 == nil) goto v_31117;
    goto v_31141;
v_31137:
    v_31807 = stack[-4];
    v_31807 = qcdr(v_31807);
    stack[0] = qcar(v_31807);
    goto v_31138;
v_31139:
    goto v_31152;
v_31146:
    v_31809 = elt(env, 2); // quotient
    goto v_31147;
v_31148:
    v_31808 = stack[-1];
    goto v_31149;
v_31150:
    v_31807 = stack[-3];
    goto v_31151;
v_31152:
    goto v_31146;
v_31147:
    goto v_31148;
v_31149:
    goto v_31150;
v_31151:
    v_31807 = list3(v_31809, v_31808, v_31807);
    env = stack[-7];
    goto v_31140;
v_31141:
    goto v_31137;
v_31138:
    goto v_31139;
v_31140:
    v_31807 = list2(stack[0], v_31807);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_31807);
    }
v_31117:
    goto v_30930;
v_30932:
v_30930:
    v_31807 = stack[-1];
    if (is_number(v_31807)) goto v_31161;
    else goto v_31160;
v_31161:
    v_31807 = stack[-3];
    if (is_number(v_31807)) goto v_31163;
    else goto v_31160;
v_31163:
    goto v_31158;
v_31160:
    goto v_31172;
v_31168:
    v_31808 = qvalue(elt(env, 5)); // frlis!*
    goto v_31169;
v_31170:
    v_31807 = stack[-1];
    goto v_31171;
v_31172:
    goto v_31168;
v_31169:
    goto v_31170;
v_31171:
    fn = elt(env, 22); // smemqlp
    v_31807 = (*qfn2(fn))(fn, v_31808, v_31807);
    env = stack[-7];
    if (v_31807 == nil) goto v_31166;
    else goto v_31165;
v_31166:
    goto v_31181;
v_31177:
    v_31808 = qvalue(elt(env, 5)); // frlis!*
    goto v_31178;
v_31179:
    v_31807 = stack[-3];
    goto v_31180;
v_31181:
    goto v_31177;
v_31178:
    goto v_31179;
v_31180:
    fn = elt(env, 22); // smemqlp
    v_31807 = (*qfn2(fn))(fn, v_31808, v_31807);
    env = stack[-7];
    if (v_31807 == nil) goto v_31175;
    else goto v_31165;
v_31175:
    goto v_31158;
v_31165:
    goto v_31159;
v_31158:
    goto v_30927;
v_31159:
    goto v_31189;
v_31185:
    goto v_31197;
v_31191:
    stack[0] = elt(env, 3); // expt
    goto v_31192;
v_31193:
    stack[-2] = stack[-4];
    goto v_31194;
v_31195:
    goto v_31208;
v_31204:
    v_31808 = stack[-3];
    goto v_31205;
v_31206:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31207;
v_31208:
    goto v_31204;
v_31205:
    goto v_31206;
v_31207:
    if (v_31808 == v_31807) goto v_31202;
    else goto v_31203;
v_31202:
    v_31807 = stack[-1];
    goto v_31201;
v_31203:
    goto v_31221;
v_31215:
    v_31809 = elt(env, 2); // quotient
    goto v_31216;
v_31217:
    v_31808 = stack[-1];
    goto v_31218;
v_31219:
    v_31807 = stack[-3];
    goto v_31220;
v_31221:
    goto v_31215;
v_31216:
    goto v_31217;
v_31218:
    goto v_31219;
v_31220:
    v_31807 = list3(v_31809, v_31808, v_31807);
    env = stack[-7];
    goto v_31201;
    v_31807 = nil;
v_31201:
    goto v_31196;
v_31197:
    goto v_31191;
v_31192:
    goto v_31193;
v_31194:
    goto v_31195;
v_31196:
    v_31808 = list3(stack[0], stack[-2], v_31807);
    env = stack[-7];
    goto v_31186;
v_31187:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31188;
v_31189:
    goto v_31185;
v_31186:
    goto v_31187;
v_31188:
    {
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_31808, v_31807);
    }
v_30927:
    v_31807 = stack[-1];
    if (is_number(v_31807)) goto v_31228;
    else goto v_31229;
v_31228:
    v_31807 = stack[-1];
    v_31807 = Lminusp(nil, v_31807);
    env = stack[-7];
    if (v_31807 == nil) goto v_31234;
    v_31807 = stack[-1];
    v_31807 = negate(v_31807);
    env = stack[-7];
    stack[-1] = v_31807;
    goto v_30928;
v_31234:
    v_31807 = stack[-1];
    v_31807 = integerp(v_31807);
    if (v_31807 == nil) goto v_31240;
    v_31807 = stack[-3];
    v_31807 = integerp(v_31807);
    if (v_31807 == nil) goto v_31246;
    v_31807 = stack[-6];
    if (v_31807 == nil) goto v_31252;
    v_31807 = stack[-1];
    v_31807 = negate(v_31807);
    env = stack[-7];
    stack[-1] = v_31807;
    goto v_31250;
v_31252:
v_31250:
    v_31807 = stack[-1];
    stack[-5] = v_31807;
    v_31807 = qvalue(elt(env, 6)); // !*mcd
    if (v_31807 == nil) goto v_31260;
    v_31807 = stack[-4];
    v_31807 = integerp(v_31807);
    if (v_31807 == nil) goto v_31264;
    else goto v_31263;
v_31264:
    v_31807 = qvalue(elt(env, 7)); // !*notseparate
    if (v_31807 == nil) goto v_31263;
    goto v_31260;
v_31263:
    goto v_31274;
v_31270:
    stack[-2] = stack[-5];
    goto v_31271;
v_31272:
    goto v_31281;
v_31277:
    stack[0] = stack[-3];
    goto v_31278;
v_31279:
    goto v_31288;
v_31284:
    v_31808 = stack[-1];
    goto v_31285;
v_31286:
    v_31807 = stack[-3];
    goto v_31287;
v_31288:
    goto v_31284;
v_31285:
    goto v_31286;
v_31287:
    v_31807 = quot2(v_31808, v_31807);
    env = stack[-7];
    stack[-1] = v_31807;
    goto v_31280;
v_31281:
    goto v_31277;
v_31278:
    goto v_31279;
v_31280:
    v_31807 = times2(stack[0], v_31807);
    env = stack[-7];
    goto v_31273;
v_31274:
    goto v_31270;
v_31271:
    goto v_31272;
v_31273:
    v_31807 = difference2(stack[-2], v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    goto v_31300;
v_31296:
    v_31808 = stack[-5];
    goto v_31297;
v_31298:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31299;
v_31300:
    goto v_31296;
v_31297:
    goto v_31298;
v_31299:
    v_31807 = (LispObject)lessp2(v_31808, v_31807);
    v_31807 = v_31807 ? lisp_true : nil;
    env = stack[-7];
    if (v_31807 == nil) goto v_31294;
    v_31807 = stack[-1];
    v_31807 = sub1(v_31807);
    env = stack[-7];
    stack[-1] = v_31807;
    goto v_31310;
v_31306:
    v_31808 = stack[-5];
    goto v_31307;
v_31308:
    v_31807 = stack[-3];
    goto v_31309;
v_31310:
    goto v_31306;
v_31307:
    goto v_31308;
v_31309:
    v_31807 = plus2(v_31808, v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    goto v_31292;
v_31294:
v_31292:
    goto v_31258;
v_31260:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_31807;
    goto v_31258;
v_31258:
    goto v_31322;
v_31318:
    v_31808 = stack[-4];
    goto v_31319;
v_31320:
    v_31807 = stack[-1];
    goto v_31321;
v_31322:
    goto v_31318;
v_31319:
    goto v_31320;
v_31321:
    v_31807 = list2(v_31808, v_31807);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    stack[0] = v_31807;
    goto v_31333;
v_31329:
    v_31808 = stack[-5];
    goto v_31330;
v_31331:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31332;
v_31333:
    goto v_31329;
v_31330:
    goto v_31331;
v_31332:
    if (v_31808 == v_31807) goto v_31327;
    else goto v_31328;
v_31327:
    v_31807 = stack[0];
    goto v_30926;
v_31328:
    goto v_31347;
v_31343:
    v_31808 = stack[-3];
    goto v_31344;
v_31345:
    v_31807 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31346;
v_31347:
    goto v_31343;
v_31344:
    goto v_31345;
v_31346:
    if (v_31808 == v_31807) goto v_31341;
    else goto v_31342;
v_31341:
    v_31807 = qvalue(elt(env, 8)); // !*keepsqrts
    goto v_31340;
v_31342:
    v_31807 = nil;
    goto v_31340;
    v_31807 = nil;
v_31340:
    if (v_31807 == nil) goto v_31338;
    goto v_31359;
v_31355:
    stack[-1] = stack[0];
    goto v_31356;
v_31357:
    goto v_31366;
v_31362:
    v_31807 = elt(env, 9); // sqrt
    if (!symbolp(v_31807)) stack[0] = nil;
    else { stack[0] = qfastgets(v_31807);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 22); // simpfn
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    goto v_31363;
v_31364:
    v_31807 = stack[-4];
    v_31807 = ncons(v_31807);
    env = stack[-7];
    goto v_31365;
v_31366:
    goto v_31362;
v_31363:
    goto v_31364;
v_31365:
    v_31807 = Lapply1(nil, stack[0], v_31807);
    env = stack[-7];
    goto v_31358;
v_31359:
    goto v_31355;
v_31356:
    goto v_31357;
v_31358:
    fn = elt(env, 20); // multsq
    v_31807 = (*qfn2(fn))(fn, stack[-1], v_31807);
    env = stack[-7];
    stack[0] = v_31807;
    goto v_31380;
v_31376:
    v_31808 = stack[-5];
    goto v_31377;
v_31378:
    v_31807 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31379;
v_31380:
    goto v_31376;
v_31377:
    goto v_31378;
v_31379:
    v_31807 = (LispObject)lessp2(v_31808, v_31807);
    v_31807 = v_31807 ? lisp_true : nil;
    env = stack[-7];
    if (v_31807 == nil) goto v_31374;
    v_31807 = stack[0];
    fn = elt(env, 24); // invsq
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    stack[0] = v_31807;
    v_31807 = stack[-5];
    v_31807 = negate(v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    goto v_31372;
v_31374:
v_31372:
    goto v_31392;
v_31388:
    v_31808 = stack[0];
    goto v_31389;
v_31390:
    v_31807 = stack[-5];
    goto v_31391;
v_31392:
    goto v_31388;
v_31389:
    goto v_31390;
v_31391:
    {
        fn = elt(env, 25); // exptsq
        return (*qfn2(fn))(fn, v_31808, v_31807);
    }
v_31338:
    goto v_31402;
v_31398:
    goto v_31399;
v_31400:
    goto v_31409;
v_31405:
    goto v_31415;
v_31411:
    v_31807 = stack[-4];
    fn = elt(env, 26); // simp!*
    v_31808 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    goto v_31412;
v_31413:
    v_31807 = stack[-3];
    goto v_31414;
v_31415:
    goto v_31411;
v_31412:
    goto v_31413;
v_31414:
    fn = elt(env, 27); // simprad
    v_31808 = (*qfn2(fn))(fn, v_31808, v_31807);
    env = stack[-7];
    goto v_31406;
v_31407:
    v_31807 = stack[-5];
    goto v_31408;
v_31409:
    goto v_31405;
v_31406:
    goto v_31407;
v_31408:
    fn = elt(env, 25); // exptsq
    v_31807 = (*qfn2(fn))(fn, v_31808, v_31807);
    env = stack[-7];
    goto v_31401;
v_31402:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    {
        LispObject v_31818 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_31818, v_31807);
    }
    goto v_31244;
v_31246:
    v_31807 = stack[-1];
    stack[-5] = v_31807;
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31807;
    goto v_31244;
v_31244:
    goto v_31232;
v_31240:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_31807;
    goto v_31232;
v_31232:
    goto v_31227;
v_31229:
    v_31807 = stack[-1];
    if (!consp(v_31807)) goto v_31427;
    else goto v_31428;
v_31427:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_31807;
    goto v_31227;
v_31428:
    goto v_31437;
v_31433:
    v_31807 = stack[-1];
    v_31808 = qcar(v_31807);
    goto v_31434;
v_31435:
    v_31807 = elt(env, 10); // minus
    goto v_31436;
v_31437:
    goto v_31433;
v_31434:
    goto v_31435;
v_31436:
    if (v_31808 == v_31807) goto v_31431;
    else goto v_31432;
v_31431:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    stack[-1] = v_31807;
    goto v_30928;
v_31432:
    goto v_31454;
v_31450:
    v_31807 = stack[-1];
    v_31808 = qcar(v_31807);
    goto v_31451;
v_31452:
    v_31807 = elt(env, 11); // plus
    goto v_31453;
v_31454:
    goto v_31450;
v_31451:
    goto v_31452;
v_31453:
    if (v_31808 == v_31807) goto v_31448;
    else goto v_31449;
v_31448:
    v_31807 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_31447;
v_31449:
    v_31807 = nil;
    goto v_31447;
    v_31807 = nil;
v_31447:
    if (v_31807 == nil) goto v_31445;
    goto v_31467;
v_31463:
    v_31808 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31464;
v_31465:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31466;
v_31467:
    goto v_31463;
v_31464:
    goto v_31465;
v_31466:
    v_31807 = cons(v_31808, v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    stack[-2] = v_31807;
v_31473:
    v_31807 = stack[-2];
    if (v_31807 == nil) goto v_31478;
    else goto v_31479;
v_31478:
    goto v_31472;
v_31479:
    v_31807 = stack[-2];
    v_31807 = qcar(v_31807);
    goto v_31490;
v_31486:
    goto v_31497;
v_31493:
    stack[-1] = stack[-4];
    goto v_31494;
v_31495:
    goto v_31506;
v_31500:
    stack[0] = elt(env, 2); // quotient
    goto v_31501;
v_31502:
    v_31808 = stack[-6];
    if (v_31808 == nil) goto v_31511;
    goto v_31518;
v_31514:
    v_31808 = elt(env, 10); // minus
    goto v_31515;
v_31516:
    goto v_31517;
v_31518:
    goto v_31514;
v_31515:
    goto v_31516;
v_31517:
    v_31807 = list2(v_31808, v_31807);
    env = stack[-7];
    v_31808 = v_31807;
    goto v_31509;
v_31511:
    v_31808 = v_31807;
    goto v_31509;
    v_31808 = nil;
v_31509:
    goto v_31503;
v_31504:
    v_31807 = stack[-3];
    goto v_31505;
v_31506:
    goto v_31500;
v_31501:
    goto v_31502;
v_31503:
    goto v_31504;
v_31505:
    v_31807 = list3(stack[0], v_31808, v_31807);
    env = stack[-7];
    goto v_31496;
v_31497:
    goto v_31493;
v_31494:
    goto v_31495;
v_31496:
    v_31807 = list2(stack[-1], v_31807);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_31808 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    goto v_31487;
v_31488:
    v_31807 = stack[-5];
    goto v_31489;
v_31490:
    goto v_31486;
v_31487:
    goto v_31488;
v_31489:
    fn = elt(env, 20); // multsq
    v_31807 = (*qfn2(fn))(fn, v_31808, v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    v_31807 = stack[-2];
    v_31807 = qcdr(v_31807);
    stack[-2] = v_31807;
    goto v_31473;
v_31472:
    v_31807 = stack[-5];
    goto v_30926;
v_31445:
    goto v_31539;
v_31535:
    v_31807 = stack[-1];
    v_31808 = qcar(v_31807);
    goto v_31536;
v_31537:
    v_31807 = elt(env, 13); // times
    goto v_31538;
v_31539:
    goto v_31535;
v_31536:
    goto v_31537;
v_31538:
    if (v_31808 == v_31807) goto v_31533;
    else goto v_31534;
v_31533:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    v_31807 = integerp(v_31807);
    goto v_31532;
v_31534:
    v_31807 = nil;
    goto v_31532;
    v_31807 = nil;
v_31532:
    if (v_31807 == nil) goto v_31530;
    v_31807 = stack[-3];
    if (is_number(v_31807)) goto v_31552;
    else goto v_31553;
v_31552:
    goto v_31560;
v_31556:
    v_31808 = stack[-3];
    goto v_31557;
v_31558:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    goto v_31559;
v_31560:
    goto v_31556;
v_31557:
    goto v_31558;
v_31559:
    v_31807 = Lgcd(nil, v_31808, v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    goto v_31570;
v_31566:
    v_31808 = stack[-3];
    goto v_31567;
v_31568:
    v_31807 = stack[-5];
    goto v_31569;
v_31570:
    goto v_31566;
v_31567:
    goto v_31568;
v_31569:
    v_31807 = quot2(v_31808, v_31807);
    env = stack[-7];
    stack[-3] = v_31807;
    goto v_31578;
v_31574:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31808 = qcar(v_31807);
    goto v_31575;
v_31576:
    v_31807 = stack[-5];
    goto v_31577;
v_31578:
    goto v_31574;
v_31575:
    goto v_31576;
v_31577:
    v_31807 = quot2(v_31808, v_31807);
    env = stack[-7];
    stack[-5] = v_31807;
    goto v_31551;
v_31553:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    stack[-5] = v_31807;
    goto v_31551;
v_31551:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    if (v_31807 == nil) goto v_31591;
    goto v_31601;
v_31597:
    v_31808 = elt(env, 13); // times
    goto v_31598;
v_31599:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    goto v_31600;
v_31601:
    goto v_31597;
v_31598:
    goto v_31599;
v_31600:
    v_31807 = cons(v_31808, v_31807);
    env = stack[-7];
    goto v_31589;
v_31591:
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    goto v_31589;
    v_31807 = nil;
v_31589:
    stack[-1] = v_31807;
    goto v_31227;
v_31530:
    goto v_31622;
v_31618:
    v_31807 = stack[-1];
    v_31808 = qcar(v_31807);
    goto v_31619;
v_31620:
    v_31807 = elt(env, 2); // quotient
    goto v_31621;
v_31622:
    goto v_31618;
v_31619:
    goto v_31620;
v_31621:
    if (v_31808 == v_31807) goto v_31616;
    else goto v_31617;
v_31616:
    goto v_31634;
v_31630:
    v_31808 = stack[-3];
    goto v_31631;
v_31632:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31633;
v_31634:
    goto v_31630;
v_31631:
    goto v_31632;
v_31633:
    if (v_31808 == v_31807) goto v_31628;
    else goto v_31629;
v_31628:
    v_31807 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_31627;
v_31629:
    v_31807 = nil;
    goto v_31627;
    v_31807 = nil;
v_31627:
    goto v_31615;
v_31617:
    v_31807 = nil;
    goto v_31615;
    v_31807 = nil;
v_31615:
    if (v_31807 == nil) goto v_31613;
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    stack[-3] = v_31807;
    v_31807 = stack[-1];
    v_31807 = qcdr(v_31807);
    v_31807 = qcar(v_31807);
    stack[-1] = v_31807;
    goto v_30927;
v_31613:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_31807;
    goto v_31227;
v_31227:
    v_31807 = stack[-4];
    if (symbolp(v_31807)) goto v_31658;
    else goto v_31657;
v_31658:
    goto v_31666;
v_31662:
    v_31808 = stack[-4];
    goto v_31663;
v_31664:
    v_31807 = elt(env, 14); // used!*
    goto v_31665;
v_31666:
    goto v_31662;
v_31663:
    goto v_31664;
v_31665:
    v_31807 = Lflagp(nil, v_31808, v_31807);
    env = stack[-7];
    if (v_31807 == nil) goto v_31660;
    else goto v_31657;
v_31660:
    goto v_31674;
v_31670:
    v_31807 = stack[-4];
    v_31808 = ncons(v_31807);
    env = stack[-7];
    goto v_31671;
v_31672:
    v_31807 = elt(env, 14); // used!*
    goto v_31673;
v_31674:
    goto v_31670;
v_31671:
    goto v_31672;
v_31673:
    v_31807 = Lflag(nil, v_31808, v_31807);
    env = stack[-7];
    goto v_31655;
v_31657:
v_31655:
    goto v_31690;
v_31686:
    v_31808 = stack[-4];
    goto v_31687;
v_31688:
    v_31807 = elt(env, 15); // (minus 1)
    goto v_31689;
v_31690:
    goto v_31686;
v_31687:
    goto v_31688;
v_31689:
    if (equal(v_31808, v_31807)) goto v_31684;
    else goto v_31685;
v_31684:
    goto v_31701;
v_31697:
    v_31808 = stack[-3];
    goto v_31698;
v_31699:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31700;
v_31701:
    goto v_31697;
v_31698:
    goto v_31699;
v_31700:
    if (v_31808 == v_31807) goto v_31695;
    else goto v_31696;
v_31695:
    goto v_31712;
v_31706:
    v_31809 = elt(env, 16); // difference
    goto v_31707;
v_31708:
    v_31808 = stack[-1];
    goto v_31709;
v_31710:
    v_31807 = elt(env, 17); // (quotient 1 2)
    goto v_31711;
v_31712:
    goto v_31706;
v_31707:
    goto v_31708;
v_31709:
    goto v_31710;
v_31711:
    v_31807 = list3(v_31809, v_31808, v_31807);
    env = stack[-7];
    fn = elt(env, 18); // simp
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    v_31807 = qcar(v_31807);
    v_31807 = (v_31807 == nil ? lisp_true : nil);
    goto v_31694;
v_31696:
    v_31807 = nil;
    goto v_31694;
    v_31807 = nil;
v_31694:
    goto v_31683;
v_31685:
    v_31807 = nil;
    goto v_31683;
    v_31807 = nil;
v_31683:
    if (v_31807 == nil) goto v_31681;
    v_31807 = elt(env, 4); // i
    fn = elt(env, 18); // simp
    v_31807 = (*qfn1(fn))(fn, v_31807);
    env = stack[-7];
    stack[-4] = v_31807;
    v_31807 = stack[-6];
    if (v_31807 == nil) goto v_31729;
    v_31807 = stack[-4];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_31807);
    }
v_31729:
    v_31807 = stack[-4];
    goto v_31727;
    v_31807 = nil;
v_31727:
    goto v_30926;
v_31681:
    goto v_31743;
v_31737:
    stack[0] = elt(env, 3); // expt
    goto v_31738;
v_31739:
    stack[-2] = stack[-4];
    goto v_31740;
v_31741:
    goto v_31754;
v_31750:
    v_31808 = stack[-3];
    goto v_31751;
v_31752:
    v_31807 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31753;
v_31754:
    goto v_31750;
v_31751:
    goto v_31752;
v_31753:
    if (v_31808 == v_31807) goto v_31748;
    else goto v_31749;
v_31748:
    v_31807 = stack[-1];
    goto v_31747;
v_31749:
    goto v_31767;
v_31761:
    v_31809 = elt(env, 2); // quotient
    goto v_31762;
v_31763:
    v_31808 = stack[-1];
    goto v_31764;
v_31765:
    v_31807 = stack[-3];
    goto v_31766;
v_31767:
    goto v_31761;
v_31762:
    goto v_31763;
v_31764:
    goto v_31765;
v_31766:
    v_31807 = list3(v_31809, v_31808, v_31807);
    env = stack[-7];
    goto v_31747;
    v_31807 = nil;
v_31747:
    goto v_31742;
v_31743:
    goto v_31737;
v_31738:
    goto v_31739;
v_31740:
    goto v_31741;
v_31742:
    v_31807 = list3(stack[0], stack[-2], v_31807);
    env = stack[-7];
    stack[-4] = v_31807;
    goto v_31776;
v_31772:
    stack[0] = stack[-4];
    goto v_31773;
v_31774:
    v_31807 = stack[-6];
    if (v_31807 == nil) goto v_31781;
    v_31807 = stack[-5];
    v_31807 = negate(v_31807);
    env = stack[-7];
    goto v_31779;
v_31781:
    v_31807 = stack[-5];
    goto v_31779;
    v_31807 = nil;
v_31779:
    goto v_31775;
v_31776:
    goto v_31772;
v_31773:
    goto v_31774;
v_31775:
    {
        LispObject v_31819 = stack[0];
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_31819, v_31807);
    }
v_30928:
    v_31807 = qvalue(elt(env, 6)); // !*mcd
    if (v_31807 == nil) goto v_31791;
    goto v_31801;
v_31795:
    v_31809 = stack[-4];
    goto v_31796;
v_31797:
    v_31808 = stack[-1];
    goto v_31798;
v_31799:
    v_31807 = stack[-3];
    goto v_31800;
v_31801:
    goto v_31795;
v_31796:
    goto v_31797;
v_31798:
    goto v_31799;
v_31800:
    v_31807 = CC_simpx1(elt(env, 0), 3, v_31809, v_31808, v_31807);
    env = stack[-7];
    {
        fn = elt(env, 24); // invsq
        return (*qfn1(fn))(fn, v_31807);
    }
v_31791:
    v_31807 = stack[-6];
    v_31807 = (v_31807 == nil ? lisp_true : nil);
    stack[-6] = v_31807;
    goto v_30927;
v_30926:
    return onevalue(v_31807);
}



// Code for equal!+matrices!+p

static LispObject CC_equalLmatricesLp(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31065, v_31066, v_31067;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_30919;
    stack[-1] = v_30918;
// end of prologue
    goto v_30940;
v_30936:
    v_31066 = stack[-1];
    goto v_30937;
v_30938:
    v_31065 = stack[0];
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    fn = elt(env, 2); // same!+dim!+squared!+p
    v_31065 = (*qfn2(fn))(fn, v_31066, v_31065);
    env = stack[-4];
    if (v_31065 == nil) goto v_30934;
    goto v_30948;
v_30944:
    goto v_30945;
v_30946:
    goto v_30955;
v_30951:
    goto v_30961;
v_30957:
    v_31066 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_30958;
v_30959:
    v_31065 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30960;
v_30961:
    goto v_30957;
v_30958:
    goto v_30959;
v_30960:
    v_31066 = cons(v_31066, v_31065);
    env = stack[-4];
    goto v_30952;
v_30953:
    v_31065 = stack[0];
    goto v_30954;
v_30955:
    goto v_30951;
v_30952:
    goto v_30953;
v_30954:
    fn = elt(env, 3); // mk!+scal!+mult!+mat
    v_31065 = (*qfn2(fn))(fn, v_31066, v_31065);
    env = stack[-4];
    goto v_30947;
v_30948:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    fn = elt(env, 4); // mk!+mat!+plus!+mat
    v_31065 = (*qfn2(fn))(fn, stack[-1], v_31065);
    env = stack[-4];
    stack[0] = v_31065;
    goto v_30970;
v_30966:
    v_31066 = nil;
    goto v_30967;
v_30968:
    v_31065 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30969;
v_30970:
    goto v_30966;
v_30967:
    goto v_30968;
v_30969:
    v_31065 = cons(v_31066, v_31065);
    env = stack[-4];
    v_31067 = v_31065;
    v_31065 = stack[0];
    stack[-3] = v_31065;
v_30976:
    v_31065 = stack[-3];
    if (v_31065 == nil) goto v_30980;
    else goto v_30981;
v_30980:
    goto v_30975;
v_30981:
    v_31065 = stack[-3];
    v_31065 = qcar(v_31065);
    stack[-2] = v_31065;
v_30990:
    v_31065 = stack[-2];
    if (v_31065 == nil) goto v_30994;
    else goto v_30995;
v_30994:
    goto v_30989;
v_30995:
    v_31065 = stack[-2];
    v_31065 = qcar(v_31065);
    v_31066 = v_31065;
    v_31065 = qvalue(elt(env, 1)); // !*complex
    if (v_31065 == nil) goto v_31004;
    goto v_31011;
v_31007:
    stack[-1] = v_31067;
    goto v_31008;
v_31009:
    goto v_31018;
v_31014:
    stack[0] = v_31066;
    goto v_31015;
v_31016:
    v_31065 = v_31066;
    fn = elt(env, 5); // mk!+conjugate!+sq
    v_31065 = (*qfn1(fn))(fn, v_31065);
    env = stack[-4];
    goto v_31017;
v_31018:
    goto v_31014;
v_31015:
    goto v_31016;
v_31017:
    fn = elt(env, 6); // multsq
    v_31065 = (*qfn2(fn))(fn, stack[0], v_31065);
    env = stack[-4];
    goto v_31010;
v_31011:
    goto v_31007;
v_31008:
    goto v_31009;
v_31010:
    fn = elt(env, 7); // addsq
    v_31065 = (*qfn2(fn))(fn, stack[-1], v_31065);
    env = stack[-4];
    v_31067 = v_31065;
    goto v_31002;
v_31004:
    goto v_31029;
v_31025:
    stack[0] = v_31067;
    goto v_31026;
v_31027:
    goto v_31036;
v_31032:
    v_31065 = v_31066;
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    goto v_31032;
v_31033:
    goto v_31034;
v_31035:
    fn = elt(env, 6); // multsq
    v_31065 = (*qfn2(fn))(fn, v_31065, v_31066);
    env = stack[-4];
    goto v_31028;
v_31029:
    goto v_31025;
v_31026:
    goto v_31027;
v_31028:
    fn = elt(env, 7); // addsq
    v_31065 = (*qfn2(fn))(fn, stack[0], v_31065);
    env = stack[-4];
    v_31067 = v_31065;
    goto v_31002;
v_31002:
    v_31065 = stack[-2];
    v_31065 = qcdr(v_31065);
    stack[-2] = v_31065;
    goto v_30990;
v_30989:
    v_31065 = stack[-3];
    v_31065 = qcdr(v_31065);
    stack[-3] = v_31065;
    goto v_30976;
v_30975:
    v_31065 = v_31067;
    fn = elt(env, 8); // change!+sq!+to!+algnull
    v_31065 = (*qfn1(fn))(fn, v_31065);
    goto v_31053;
v_31049:
    v_31066 = v_31065;
    goto v_31050;
v_31051:
    v_31065 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31052;
v_31053:
    goto v_31049;
v_31050:
    goto v_31051;
v_31052:
    if (v_31066 == v_31065) goto v_31047;
    else goto v_31048;
v_31047:
    v_31065 = lisp_true;
    goto v_31046;
v_31048:
    v_31065 = nil;
    goto v_31046;
v_31046:
    goto v_30932;
v_30934:
    v_31065 = nil;
    goto v_30932;
v_30932:
    return onevalue(v_31065);
}



// Code for talp_try2

static LispObject CC_talp_try2(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30953, v_30954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30918;
// end of prologue
    v_30953 = stack[0];
    fn = elt(env, 1); // cl_bvarl
    v_30953 = (*qfn1(fn))(fn, v_30953);
    env = stack[-2];
    stack[-1] = v_30953;
    v_30953 = stack[0];
    fn = elt(env, 2); // cl_fvarl
    v_30953 = (*qfn1(fn))(fn, v_30953);
    env = stack[-2];
    goto v_30934;
v_30930:
    v_30954 = stack[-1];
    goto v_30931;
v_30932:
    goto v_30933;
v_30934:
    goto v_30930;
v_30931:
    goto v_30932;
v_30933:
    v_30953 = Lappend(nil, v_30954, v_30953);
    env = stack[-2];
    v_30954 = v_30953;
    if (v_30954 == nil) goto v_30940;
    goto v_30947;
v_30943:
    v_30954 = stack[0];
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    goto v_30943;
v_30944:
    goto v_30945;
v_30946:
    {
        fn = elt(env, 3); // talp_try3
        return (*qfn2(fn))(fn, v_30954, v_30953);
    }
v_30940:
    v_30953 = stack[0];
    goto v_30938;
    v_30953 = nil;
v_30938:
    return onevalue(v_30953);
}



// Code for ofsf_simpat

static LispObject CC_ofsf_simpat(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_31200, v_31201, v_31202;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_30918;
// end of prologue
    v_31200 = stack[-2];
    v_31200 = qcar(v_31200);
    stack[-3] = v_31200;
    v_31200 = stack[-2];
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    fn = elt(env, 9); // simp
    v_31200 = (*qfn1(fn))(fn, v_31200);
    env = stack[-4];
    stack[-1] = v_31200;
    v_31200 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31200 == nil) goto v_30937;
    else goto v_30936;
v_30937:
    v_31200 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31200 == nil) goto v_30940;
    else goto v_30936;
v_30940:
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    if (!consp(v_31200)) goto v_30945;
    else goto v_30946;
v_30945:
    v_31200 = lisp_true;
    goto v_30944;
v_30946:
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    v_31200 = (consp(v_31200) ? nil : lisp_true);
    goto v_30944;
    v_31200 = nil;
v_30944:
    if (v_31200 == nil) goto v_30942;
    else goto v_30936;
v_30942:
    goto v_30961;
v_30957:
    v_31201 = stack[-2];
    goto v_30958;
v_30959:
    v_31200 = elt(env, 3); // "atomic formula"
    goto v_30960;
v_30961:
    goto v_30957;
v_30958:
    goto v_30959;
v_30960:
    fn = elt(env, 10); // typerr
    v_31200 = (*qfn2(fn))(fn, v_31201, v_31200);
    env = stack[-4];
    goto v_30934;
v_30936:
v_30934:
    v_31200 = stack[-2];
    v_31200 = qcdr(v_31200);
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    fn = elt(env, 9); // simp
    v_31200 = (*qfn1(fn))(fn, v_31200);
    env = stack[-4];
    stack[0] = v_31200;
    v_31200 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31200 == nil) goto v_30973;
    else goto v_30972;
v_30973:
    v_31200 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31200 == nil) goto v_30976;
    else goto v_30972;
v_30976:
    v_31200 = stack[0];
    v_31200 = qcdr(v_31200);
    if (!consp(v_31200)) goto v_30981;
    else goto v_30982;
v_30981:
    v_31200 = lisp_true;
    goto v_30980;
v_30982:
    v_31200 = stack[0];
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    v_31200 = (consp(v_31200) ? nil : lisp_true);
    goto v_30980;
    v_31200 = nil;
v_30980:
    if (v_31200 == nil) goto v_30978;
    else goto v_30972;
v_30978:
    goto v_30997;
v_30993:
    v_31201 = stack[-2];
    goto v_30994;
v_30995:
    v_31200 = elt(env, 3); // "atomic formula"
    goto v_30996;
v_30997:
    goto v_30993;
v_30994:
    goto v_30995;
v_30996:
    fn = elt(env, 10); // typerr
    v_31200 = (*qfn2(fn))(fn, v_31201, v_31200);
    env = stack[-4];
    goto v_30970;
v_30972:
v_30970:
    goto v_31005;
v_31001:
    goto v_31002;
v_31003:
    v_31200 = stack[0];
    fn = elt(env, 11); // negsq
    v_31200 = (*qfn1(fn))(fn, v_31200);
    env = stack[-4];
    goto v_31004;
v_31005:
    goto v_31001;
v_31002:
    goto v_31003;
v_31004:
    fn = elt(env, 12); // addsq
    v_31200 = (*qfn2(fn))(fn, stack[-1], v_31200);
    env = stack[-4];
    stack[-1] = v_31200;
    v_31200 = stack[-1];
    v_31200 = qcar(v_31200);
    v_31201 = v_31200;
    v_31200 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31200 == nil) goto v_31014;
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    if (!consp(v_31200)) goto v_31020;
    else goto v_31021;
v_31020:
    v_31200 = lisp_true;
    goto v_31019;
v_31021:
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    v_31200 = (consp(v_31200) ? nil : lisp_true);
    goto v_31019;
    v_31200 = nil;
v_31019:
    if (v_31200 == nil) goto v_31017;
    else goto v_31014;
v_31017:
    goto v_31038;
v_31032:
    v_31202 = stack[-3];
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    v_31200 = nil;
    goto v_31037;
v_31038:
    goto v_31032;
v_31033:
    goto v_31034;
v_31035:
    goto v_31036;
v_31037:
    v_31200 = list3(v_31202, v_31201, v_31200);
    env = stack[-4];
    stack[0] = v_31200;
    v_31200 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_31200 == nil) goto v_31045;
    goto v_31055;
v_31051:
    v_31201 = stack[-3];
    goto v_31052;
v_31053:
    v_31200 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    v_31200 = Lmemq(nil, v_31201, v_31200);
    if (v_31200 == nil) goto v_31050;
    goto v_31066;
v_31060:
    stack[-2] = elt(env, 6); // and
    goto v_31061;
v_31062:
    goto v_31075;
v_31069:
    v_31202 = elt(env, 7); // greaterp
    goto v_31070;
v_31071:
    v_31200 = stack[-1];
    v_31201 = qcdr(v_31200);
    goto v_31072;
v_31073:
    v_31200 = nil;
    goto v_31074;
v_31075:
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    goto v_31073;
v_31074:
    stack[-1] = list3(v_31202, v_31201, v_31200);
    env = stack[-4];
    goto v_31063;
v_31064:
    v_31200 = stack[0];
    v_31200 = ncons(v_31200);
    env = stack[-4];
    goto v_31065;
v_31066:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    v_31200 = list2star(stack[-2], stack[-1], v_31200);
    goto v_31048;
v_31050:
    goto v_31091;
v_31085:
    stack[-2] = elt(env, 6); // and
    goto v_31086;
v_31087:
    goto v_31100;
v_31094:
    v_31202 = elt(env, 8); // neq
    goto v_31095;
v_31096:
    v_31200 = stack[-1];
    v_31201 = qcdr(v_31200);
    goto v_31097;
v_31098:
    v_31200 = nil;
    goto v_31099;
v_31100:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    stack[-1] = list3(v_31202, v_31201, v_31200);
    env = stack[-4];
    goto v_31088;
v_31089:
    v_31200 = stack[0];
    v_31200 = ncons(v_31200);
    env = stack[-4];
    goto v_31090;
v_31091:
    goto v_31085;
v_31086:
    goto v_31087;
v_31088:
    goto v_31089;
v_31090:
    v_31200 = list2star(stack[-2], stack[-1], v_31200);
    goto v_31048;
    v_31200 = nil;
v_31048:
    stack[0] = v_31200;
    goto v_31043;
v_31045:
v_31043:
    v_31200 = stack[0];
    goto v_30926;
v_31014:
    v_31200 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31200 == nil) goto v_31111;
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    if (!consp(v_31200)) goto v_31117;
    else goto v_31118;
v_31117:
    v_31200 = lisp_true;
    goto v_31116;
v_31118:
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    v_31200 = qcar(v_31200);
    v_31200 = (consp(v_31200) ? nil : lisp_true);
    goto v_31116;
    v_31200 = nil;
v_31116:
    if (v_31200 == nil) goto v_31114;
    else goto v_31111;
v_31114:
    goto v_31136;
v_31132:
    v_31202 = stack[-3];
    goto v_31133;
v_31134:
    v_31200 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_31135;
v_31136:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    v_31200 = Lmemq(nil, v_31202, v_31200);
    if (v_31200 == nil) goto v_31131;
    goto v_31145;
v_31141:
    goto v_31142;
v_31143:
    v_31200 = stack[-1];
    v_31200 = qcdr(v_31200);
    goto v_31144;
v_31145:
    goto v_31141;
v_31142:
    goto v_31143;
v_31144:
    fn = elt(env, 13); // multf
    v_31200 = (*qfn2(fn))(fn, v_31201, v_31200);
    env = stack[-4];
    v_31201 = v_31200;
    goto v_31129;
v_31131:
v_31129:
    goto v_31156;
v_31150:
    v_31202 = stack[-3];
    goto v_31151;
v_31152:
    goto v_31153;
v_31154:
    v_31200 = nil;
    goto v_31155;
v_31156:
    goto v_31150;
v_31151:
    goto v_31152;
v_31153:
    goto v_31154;
v_31155:
    v_31200 = list3(v_31202, v_31201, v_31200);
    env = stack[-4];
    stack[0] = v_31200;
    v_31200 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_31200 == nil) goto v_31163;
    goto v_31172;
v_31166:
    stack[-2] = elt(env, 6); // and
    goto v_31167;
v_31168:
    goto v_31181;
v_31175:
    v_31202 = elt(env, 8); // neq
    goto v_31176;
v_31177:
    v_31200 = stack[-1];
    v_31201 = qcdr(v_31200);
    goto v_31178;
v_31179:
    v_31200 = nil;
    goto v_31180;
v_31181:
    goto v_31175;
v_31176:
    goto v_31177;
v_31178:
    goto v_31179;
v_31180:
    stack[-1] = list3(v_31202, v_31201, v_31200);
    env = stack[-4];
    goto v_31169;
v_31170:
    v_31200 = stack[0];
    v_31200 = ncons(v_31200);
    env = stack[-4];
    goto v_31171;
v_31172:
    goto v_31166;
v_31167:
    goto v_31168;
v_31169:
    goto v_31170;
v_31171:
    v_31200 = list2star(stack[-2], stack[-1], v_31200);
    stack[0] = v_31200;
    goto v_31161;
v_31163:
v_31161:
    v_31200 = stack[0];
    goto v_30926;
v_31111:
    goto v_31196;
v_31190:
    v_31202 = stack[-3];
    goto v_31191;
v_31192:
    goto v_31193;
v_31194:
    v_31200 = nil;
    goto v_31195;
v_31196:
    goto v_31190;
v_31191:
    goto v_31192;
v_31193:
    goto v_31194;
v_31195:
    return list3(v_31202, v_31201, v_31200);
v_30926:
    return onevalue(v_31200);
}



// Code for quotfx1

static LispObject CC_quotfx1(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31298, v_31299, v_31300, v_31301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_30919;
    stack[-8] = v_30918;
// end of prologue
    v_31298 = stack[-8];
    if (v_31298 == nil) goto v_30923;
    else goto v_30924;
v_30923:
    goto v_30931;
v_30927:
    v_31299 = stack[-8];
    goto v_30928;
v_30929:
    v_31298 = stack[-7];
    goto v_30930;
v_30931:
    goto v_30927;
v_30928:
    goto v_30929;
v_30930:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_30924:
    goto v_30940;
v_30936:
    v_31299 = stack[-8];
    goto v_30937;
v_30938:
    v_31298 = stack[-7];
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    if (equal(v_31299, v_31298)) goto v_30934;
    else goto v_30935;
v_30934:
    v_31298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30922;
v_30935:
    goto v_30950;
v_30946:
    v_31299 = stack[-7];
    goto v_30947;
v_30948:
    v_31298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30949;
v_30950:
    goto v_30946;
v_30947:
    goto v_30948;
v_30949:
    if (v_31299 == v_31298) goto v_30944;
    else goto v_30945;
v_30944:
    v_31298 = stack[-8];
    goto v_30922;
v_30945:
    v_31298 = stack[-7];
    if (!consp(v_31298)) goto v_30958;
    else goto v_30959;
v_30958:
    v_31298 = lisp_true;
    goto v_30957;
v_30959:
    v_31298 = stack[-7];
    v_31298 = qcar(v_31298);
    v_31298 = (consp(v_31298) ? nil : lisp_true);
    goto v_30957;
    v_31298 = nil;
v_30957:
    if (v_31298 == nil) goto v_30955;
    goto v_30972;
v_30968:
    v_31299 = stack[-8];
    goto v_30969;
v_30970:
    v_31298 = stack[-7];
    goto v_30971;
v_30972:
    goto v_30968;
v_30969:
    goto v_30970;
v_30971:
    {
        fn = elt(env, 2); // quotfdx
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_30955:
    v_31298 = stack[-8];
    if (!consp(v_31298)) goto v_30979;
    else goto v_30980;
v_30979:
    v_31298 = lisp_true;
    goto v_30978;
v_30980:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = (consp(v_31298) ? nil : lisp_true);
    goto v_30978;
    v_31298 = nil;
v_30978:
    if (v_31298 == nil) goto v_30976;
    goto v_30993;
v_30989:
    v_31299 = stack[-8];
    goto v_30990;
v_30991:
    v_31298 = stack[-7];
    goto v_30992;
v_30993:
    goto v_30989;
v_30990:
    goto v_30991;
v_30992:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_30976:
    goto v_31002;
v_30998:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31299 = qcar(v_31298);
    goto v_30999;
v_31000:
    v_31298 = stack[-7];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    goto v_31001;
v_31002:
    goto v_30998;
v_30999:
    goto v_31000;
v_31001:
    if (v_31299 == v_31298) goto v_30996;
    else goto v_30997;
v_30996:
    stack[-9] = nil;
    stack[-1] = nil;
    v_31298 = stack[-7];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31298 = qcdr(v_31298);
    stack[-5] = v_31298;
v_31023:
    goto v_31042;
v_31038:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31299 = qcdr(v_31298);
    stack[-6] = v_31299;
    goto v_31039;
v_31040:
    v_31298 = stack[-5];
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    v_31298 = (LispObject)lessp2(v_31299, v_31298);
    v_31298 = v_31298 ? lisp_true : nil;
    env = stack[-10];
    if (v_31298 == nil) goto v_31036;
    goto v_31053;
v_31049:
    v_31299 = stack[-8];
    goto v_31050;
v_31051:
    v_31298 = stack[-7];
    goto v_31052;
v_31053:
    goto v_31049;
v_31050:
    goto v_31051;
v_31052:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_31036:
    v_31298 = stack[-8];
    fn = elt(env, 3); // lt!*
    v_31298 = (*qfn1(fn))(fn, v_31298);
    env = stack[-10];
    stack[0] = v_31298;
    v_31298 = stack[-7];
    fn = elt(env, 3); // lt!*
    v_31298 = (*qfn1(fn))(fn, v_31298);
    env = stack[-10];
    v_31299 = stack[-7];
    v_31299 = qcar(v_31299);
    v_31299 = qcar(v_31299);
    v_31299 = qcar(v_31299);
    stack[-4] = v_31299;
    goto v_31069;
v_31065:
    v_31299 = stack[0];
    v_31299 = qcdr(v_31299);
    goto v_31066;
v_31067:
    v_31298 = qcdr(v_31298);
    goto v_31068;
v_31069:
    goto v_31065;
v_31066:
    goto v_31067;
v_31068:
    v_31298 = CC_quotfx1(elt(env, 0), v_31299, v_31298);
    env = stack[-10];
    stack[-3] = v_31298;
    goto v_31078;
v_31074:
    v_31299 = stack[-6];
    goto v_31075;
v_31076:
    v_31298 = stack[-5];
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    v_31298 = (LispObject)(intptr_t)((intptr_t)v_31299 - (intptr_t)v_31298 + TAG_FIXNUM);
    stack[0] = v_31298;
    goto v_31090;
v_31086:
    v_31299 = stack[0];
    goto v_31087;
v_31088:
    v_31298 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    if (v_31299 == v_31298) goto v_31084;
    else goto v_31085;
v_31084:
    goto v_31098;
v_31094:
    v_31299 = stack[-1];
    goto v_31095;
v_31096:
    v_31298 = stack[-3];
    goto v_31097;
v_31098:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    {
        fn = elt(env, 4); // rnconc
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_31085:
    goto v_31106;
v_31102:
    v_31299 = stack[-4];
    goto v_31103;
v_31104:
    v_31298 = stack[0];
    goto v_31105;
v_31106:
    goto v_31102;
v_31103:
    goto v_31104;
v_31105:
    fn = elt(env, 5); // to
    v_31298 = (*qfn2(fn))(fn, v_31299, v_31298);
    env = stack[-10];
    stack[-2] = v_31298;
    v_31298 = stack[-9];
    if (v_31298 == nil) goto v_31111;
    else goto v_31112;
v_31111:
    goto v_31121;
v_31115:
    v_31301 = stack[-8];
    goto v_31116;
v_31117:
    v_31300 = stack[-4];
    goto v_31118;
v_31119:
    goto v_31128;
v_31124:
    v_31299 = stack[-6];
    goto v_31125;
v_31126:
    v_31298 = stack[0];
    goto v_31127;
v_31128:
    goto v_31124;
v_31125:
    goto v_31126;
v_31127:
    v_31298 = (LispObject)(intptr_t)((intptr_t)v_31299 - (intptr_t)v_31298 + TAG_FIXNUM);
    v_31298 = (LispObject)((intptr_t)(v_31298) - 0x10);
    goto v_31120;
v_31121:
    goto v_31115;
v_31116:
    goto v_31117;
v_31118:
    goto v_31119;
v_31120:
    fn = elt(env, 6); // cutf
    v_31298 = (*qfnn(fn))(fn, 3, v_31301, v_31300, v_31298);
    env = stack[-10];
    stack[-8] = v_31298;
    goto v_31110;
v_31112:
v_31110:
    v_31298 = lisp_true;
    stack[-9] = v_31298;
    goto v_31141;
v_31135:
    v_31301 = stack[-7];
    goto v_31136;
v_31137:
    v_31300 = stack[-4];
    goto v_31138;
v_31139:
    goto v_31148;
v_31144:
    v_31299 = stack[-5];
    goto v_31145;
v_31146:
    v_31298 = stack[0];
    goto v_31147;
v_31148:
    goto v_31144;
v_31145:
    goto v_31146;
v_31147:
    v_31298 = (LispObject)(intptr_t)((intptr_t)v_31299 - (intptr_t)v_31298 + TAG_FIXNUM);
    v_31298 = (LispObject)((intptr_t)(v_31298) - 0x10);
    goto v_31140;
v_31141:
    goto v_31135;
v_31136:
    goto v_31137;
v_31138:
    goto v_31139;
v_31140:
    fn = elt(env, 6); // cutf
    v_31298 = (*qfnn(fn))(fn, 3, v_31301, v_31300, v_31298);
    env = stack[-10];
    stack[-7] = v_31298;
    goto v_31158;
v_31154:
    stack[-6] = stack[-8];
    goto v_31155;
v_31156:
    goto v_31165;
v_31161:
    goto v_31174;
v_31170:
    v_31299 = stack[0];
    goto v_31171;
v_31172:
    v_31298 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31173;
v_31174:
    goto v_31170;
v_31171:
    goto v_31172;
v_31173:
    if (v_31299 == v_31298) goto v_31168;
    else goto v_31169;
v_31168:
    v_31298 = stack[-7];
    stack[0] = v_31298;
    goto v_31167;
v_31169:
    goto v_31185;
v_31181:
    goto v_31192;
v_31188:
    v_31299 = stack[-2];
    goto v_31189;
v_31190:
    v_31298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31191;
v_31192:
    goto v_31188;
v_31189:
    goto v_31190;
v_31191:
    v_31298 = cons(v_31299, v_31298);
    env = stack[-10];
    v_31299 = ncons(v_31298);
    env = stack[-10];
    goto v_31182;
v_31183:
    v_31298 = stack[-7];
    goto v_31184;
v_31185:
    goto v_31181;
v_31182:
    goto v_31183;
v_31184:
    fn = elt(env, 7); // multf
    v_31298 = (*qfn2(fn))(fn, v_31299, v_31298);
    env = stack[-10];
    stack[0] = v_31298;
    goto v_31167;
    stack[0] = nil;
v_31167:
    goto v_31162;
v_31163:
    v_31298 = stack[-3];
    fn = elt(env, 8); // negf
    v_31298 = (*qfn1(fn))(fn, v_31298);
    env = stack[-10];
    goto v_31164;
v_31165:
    goto v_31161;
v_31162:
    goto v_31163;
v_31164:
    fn = elt(env, 7); // multf
    v_31298 = (*qfn2(fn))(fn, stack[0], v_31298);
    env = stack[-10];
    goto v_31157;
v_31158:
    goto v_31154;
v_31155:
    goto v_31156;
v_31157:
    fn = elt(env, 9); // addf
    v_31298 = (*qfn2(fn))(fn, stack[-6], v_31298);
    env = stack[-10];
    stack[-8] = v_31298;
    v_31298 = stack[-8];
    if (v_31298 == nil) goto v_31201;
    v_31298 = stack[-8];
    if (!consp(v_31298)) goto v_31211;
    else goto v_31212;
v_31211:
    v_31298 = lisp_true;
    goto v_31210;
v_31212:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = (consp(v_31298) ? nil : lisp_true);
    goto v_31210;
    v_31298 = nil;
v_31210:
    if (v_31298 == nil) goto v_31208;
    v_31298 = lisp_true;
    goto v_31206;
v_31208:
    goto v_31227;
v_31223:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31299 = qcar(v_31298);
    goto v_31224;
v_31225:
    v_31298 = stack[-4];
    goto v_31226;
v_31227:
    goto v_31223;
v_31224:
    goto v_31225;
v_31226:
    v_31298 = (v_31299 == v_31298 ? lisp_true : nil);
    v_31298 = (v_31298 == nil ? lisp_true : nil);
    goto v_31206;
    v_31298 = nil;
v_31206:
    if (v_31298 == nil) goto v_31201;
    goto v_31240;
v_31236:
    v_31299 = stack[-8];
    goto v_31237;
v_31238:
    v_31298 = stack[-7];
    goto v_31239;
v_31240:
    goto v_31236;
v_31237:
    goto v_31238;
v_31239:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_31201:
    goto v_31248;
v_31244:
    stack[0] = stack[-1];
    goto v_31245;
v_31246:
    goto v_31255;
v_31251:
    v_31299 = stack[-2];
    goto v_31252;
v_31253:
    v_31298 = stack[-3];
    goto v_31254;
v_31255:
    goto v_31251;
v_31252:
    goto v_31253;
v_31254:
    v_31298 = cons(v_31299, v_31298);
    env = stack[-10];
    goto v_31247;
v_31248:
    goto v_31244;
v_31245:
    goto v_31246;
v_31247:
    fn = elt(env, 10); // aconc!*
    v_31298 = (*qfn2(fn))(fn, stack[0], v_31298);
    env = stack[-10];
    stack[-1] = v_31298;
    v_31298 = stack[-8];
    if (v_31298 == nil) goto v_31260;
    else goto v_31261;
v_31260:
    v_31298 = stack[-1];
    goto v_31022;
v_31261:
    goto v_31023;
v_31022:
    goto v_30922;
v_30997:
    goto v_31271;
v_31267:
    v_31298 = stack[-8];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31299 = qcar(v_31298);
    goto v_31268;
v_31269:
    v_31298 = stack[-7];
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    v_31298 = qcar(v_31298);
    goto v_31270;
v_31271:
    goto v_31267;
v_31268:
    goto v_31269;
v_31270:
    fn = elt(env, 11); // ordop
    v_31298 = (*qfn2(fn))(fn, v_31299, v_31298);
    env = stack[-10];
    if (v_31298 == nil) goto v_31265;
    goto v_31285;
v_31281:
    v_31299 = stack[-8];
    goto v_31282;
v_31283:
    v_31298 = stack[-7];
    goto v_31284;
v_31285:
    goto v_31281;
v_31282:
    goto v_31283;
v_31284:
    {
        fn = elt(env, 12); // quotkx
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
v_31265:
    goto v_31295;
v_31291:
    v_31299 = stack[-8];
    goto v_31292;
v_31293:
    v_31298 = stack[-7];
    goto v_31294;
v_31295:
    goto v_31291;
v_31292:
    goto v_31293;
v_31294:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31299, v_31298);
    }
    v_31298 = nil;
v_30922:
    return onevalue(v_31298);
}



// Code for sfto_dprpartf1

static LispObject CC_sfto_dprpartf1(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30941, v_30942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30941 = v_30919;
    v_30942 = v_30918;
// end of prologue
    goto v_30926;
v_30922:
    goto v_30923;
v_30924:
    goto v_30925;
v_30926:
    goto v_30922;
v_30923:
    goto v_30924;
v_30925:
    fn = elt(env, 1); // quotf
    v_30941 = (*qfn2(fn))(fn, v_30942, v_30941);
    env = stack[-1];
    stack[0] = v_30941;
    v_30941 = stack[0];
    fn = elt(env, 2); // minusf
    v_30941 = (*qfn1(fn))(fn, v_30941);
    env = stack[-1];
    if (v_30941 == nil) goto v_30933;
    v_30941 = stack[0];
    {
        fn = elt(env, 3); // negf
        return (*qfn1(fn))(fn, v_30941);
    }
v_30933:
    v_30941 = stack[0];
    goto v_30931;
    v_30941 = nil;
v_30931:
    return onevalue(v_30941);
}



// Code for parseml

static LispObject CC_parseml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30980, v_30981;
    LispObject fn;
    argcheck(nargs, 0, "parseml");
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
    v_30980 = nil;
    stack[0] = v_30980;
    v_30980 = (LispObject)512+TAG_FIXNUM; // 32
    v_30980 = ncons(v_30980);
    env = stack[-1];
    fn = elt(env, 10); // list2string
    v_30980 = (*qfn1(fn))(fn, v_30980);
    env = stack[-1];
    v_30980 = Lintern(nil, v_30980);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_30980; // space
    v_30980 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_30980; // count
    v_30980 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_30980; // ch
    v_30980 = nil;
    qvalue(elt(env, 4)) = v_30980; // temp2
    fn = elt(env, 11); // lex
    v_30980 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_30941;
v_30937:
    v_30981 = qvalue(elt(env, 5)); // char
    goto v_30938;
v_30939:
    v_30980 = elt(env, 6); // (m a t h)
    goto v_30940;
v_30941:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    if (equal(v_30981, v_30980)) goto v_30935;
    else goto v_30936;
v_30935:
    fn = elt(env, 12); // mathml
    v_30980 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_30980;
    goto v_30934;
v_30936:
    goto v_30952;
v_30948:
    v_30981 = elt(env, 7); // "<math>"
    goto v_30949;
v_30950:
    v_30980 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30951;
v_30952:
    goto v_30948;
v_30949:
    goto v_30950;
v_30951:
    fn = elt(env, 13); // errorml
    v_30980 = (*qfn2(fn))(fn, v_30981, v_30980);
    env = stack[-1];
    goto v_30934;
v_30934:
    fn = elt(env, 11); // lex
    v_30980 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_30964;
v_30960:
    v_30981 = qvalue(elt(env, 5)); // char
    goto v_30961;
v_30962:
    v_30980 = elt(env, 8); // (!/ m a t h)
    goto v_30963;
v_30964:
    goto v_30960;
v_30961:
    goto v_30962;
v_30963:
    if (equal(v_30981, v_30980)) goto v_30958;
    else goto v_30959;
v_30958:
    v_30980 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_30957;
v_30959:
    goto v_30975;
v_30971:
    v_30981 = elt(env, 9); // "</math>"
    goto v_30972;
v_30973:
    v_30980 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_30974;
v_30975:
    goto v_30971;
v_30972:
    goto v_30973;
v_30974:
    fn = elt(env, 13); // errorml
    v_30980 = (*qfn2(fn))(fn, v_30981, v_30980);
    env = stack[-1];
    goto v_30957;
v_30957:
    v_30980 = stack[0];
    {
        fn = elt(env, 14); // aeval
        return (*qfn1(fn))(fn, v_30980);
    }
    return onevalue(v_30980);
}



// Code for ldf!-pow!-var

static LispObject CC_ldfKpowKvar(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_31005, v_31006, v_31007;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31005 = v_30918;
// end of prologue
    v_31006 = nil;
    stack[-2] = nil;
    stack[-1] = v_31005;
v_30927:
    v_31005 = stack[-1];
    if (v_31005 == nil) goto v_30931;
    else goto v_30932;
v_30931:
    goto v_30926;
v_30932:
    v_31005 = stack[-1];
    v_31005 = qcar(v_31005);
    goto v_30943;
v_30939:
    stack[0] = v_31006;
    goto v_30940;
v_30941:
    v_31005 = qcdr(v_31005);
    fn = elt(env, 3); // kernels
    v_31005 = (*qfn1(fn))(fn, v_31005);
    env = stack[-3];
    goto v_30942;
v_30943:
    goto v_30939;
v_30940:
    goto v_30941;
v_30942:
    v_31005 = Lappend(nil, stack[0], v_31005);
    env = stack[-3];
    v_31006 = v_31005;
    v_31005 = stack[-1];
    v_31005 = qcdr(v_31005);
    stack[-1] = v_31005;
    goto v_30927;
v_30926:
    v_31005 = v_31006;
    fn = elt(env, 4); // makeset
    v_31005 = (*qfn1(fn))(fn, v_31005);
    env = stack[-3];
    fn = elt(env, 5); // prlist
    v_31005 = (*qfn1(fn))(fn, v_31005);
    env = stack[-3];
    stack[0] = v_31005;
v_30953:
    v_31005 = stack[0];
    if (v_31005 == nil) goto v_30959;
    else goto v_30960;
v_30959:
    goto v_30952;
v_30960:
    v_31005 = stack[0];
    v_31005 = qcar(v_31005);
    v_31007 = v_31005;
    goto v_30979;
v_30975:
    v_31006 = v_31007;
    goto v_30976;
v_30977:
    v_31005 = elt(env, 1); // x
    goto v_30978;
v_30979:
    goto v_30975;
v_30976:
    goto v_30977;
v_30978:
    if (!consp(v_31006)) goto v_30973;
    v_31006 = qcar(v_31006);
    if (v_31006 == v_31005) goto v_30972;
    else goto v_30973;
v_30972:
    v_31005 = lisp_true;
    goto v_30971;
v_30973:
    goto v_30990;
v_30986:
    v_31006 = v_31007;
    goto v_30987;
v_30988:
    v_31005 = elt(env, 2); // u
    goto v_30989;
v_30990:
    goto v_30986;
v_30987:
    goto v_30988;
v_30989:
    v_31005 = Leqcar(nil, v_31006, v_31005);
    env = stack[-3];
    goto v_30971;
    v_31005 = nil;
v_30971:
    if (v_31005 == nil) goto v_30969;
    goto v_30998;
v_30994:
    v_31006 = v_31007;
    goto v_30995;
v_30996:
    v_31005 = stack[-2];
    goto v_30997;
v_30998:
    goto v_30994;
v_30995:
    goto v_30996;
v_30997:
    v_31005 = cons(v_31006, v_31005);
    env = stack[-3];
    stack[-2] = v_31005;
    goto v_30967;
v_30969:
v_30967:
    v_31005 = stack[0];
    v_31005 = qcdr(v_31005);
    stack[0] = v_31005;
    goto v_30953;
v_30952:
    v_31005 = stack[-2];
    {
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(fn, v_31005);
    }
    return onevalue(v_31005);
}



// Code for vdpappendmon

static LispObject CC_vdpappendmon(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31002, v_31003, v_31004;
    LispObject fn;
    LispObject v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpappendmon");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30918,v_30919,v_30920);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_30920;
    stack[-3] = v_30919;
    stack[-4] = v_30918;
// end of prologue
    v_31002 = stack[-4];
    if (v_31002 == nil) goto v_30928;
    else goto v_30929;
v_30928:
    v_31002 = lisp_true;
    goto v_30927;
v_30929:
    v_31002 = stack[-4];
    v_31002 = qcdr(v_31002);
    v_31002 = qcdr(v_31002);
    v_31002 = qcdr(v_31002);
    v_31002 = qcar(v_31002);
    v_31002 = (v_31002 == nil ? lisp_true : nil);
    goto v_30927;
    v_31002 = nil;
v_30927:
    if (v_31002 == nil) goto v_30925;
    goto v_30945;
v_30941:
    v_31003 = stack[-3];
    goto v_30942;
v_30943:
    v_31002 = stack[-2];
    goto v_30944;
v_30945:
    goto v_30941;
v_30942:
    goto v_30943;
v_30944:
    {
        fn = elt(env, 2); // vdpfmon
        return (*qfn2(fn))(fn, v_31003, v_31002);
    }
v_30925:
    v_31002 = stack[-3];
    fn = elt(env, 3); // vbczero!?
    v_31002 = (*qfn1(fn))(fn, v_31002);
    env = stack[-6];
    if (v_31002 == nil) goto v_30949;
    v_31002 = stack[-4];
    goto v_30923;
v_30949:
    goto v_30964;
v_30956:
    stack[-5] = elt(env, 1); // vdp
    goto v_30957;
v_30958:
    v_31002 = stack[-4];
    v_31002 = qcdr(v_31002);
    stack[-1] = qcar(v_31002);
    goto v_30959;
v_30960:
    v_31002 = stack[-4];
    v_31002 = qcdr(v_31002);
    v_31002 = qcdr(v_31002);
    stack[0] = qcar(v_31002);
    goto v_30961;
v_30962:
    goto v_30978;
v_30974:
    goto v_30984;
v_30980:
    v_31002 = stack[-4];
    v_31002 = qcdr(v_31002);
    v_31002 = qcdr(v_31002);
    v_31002 = qcdr(v_31002);
    stack[-4] = qcar(v_31002);
    goto v_30981;
v_30982:
    goto v_30997;
v_30991:
    v_31004 = stack[-2];
    goto v_30992;
v_30993:
    v_31003 = stack[-3];
    goto v_30994;
v_30995:
    v_31002 = nil;
    goto v_30996;
v_30997:
    goto v_30991;
v_30992:
    goto v_30993;
v_30994:
    goto v_30995;
v_30996:
    v_31002 = list2star(v_31004, v_31003, v_31002);
    env = stack[-6];
    goto v_30983;
v_30984:
    goto v_30980;
v_30981:
    goto v_30982;
v_30983:
    fn = elt(env, 4); // dipsum
    v_31003 = (*qfn2(fn))(fn, stack[-4], v_31002);
    env = stack[-6];
    goto v_30975;
v_30976:
    v_31002 = nil;
    goto v_30977;
v_30978:
    goto v_30974;
v_30975:
    goto v_30976;
v_30977:
    v_31002 = list2(v_31003, v_31002);
    goto v_30963;
v_30964:
    goto v_30956;
v_30957:
    goto v_30958;
v_30959:
    goto v_30960;
v_30961:
    goto v_30962;
v_30963:
    {
        LispObject v_31011 = stack[-5];
        LispObject v_31012 = stack[-1];
        LispObject v_31013 = stack[0];
        return list3star(v_31011, v_31012, v_31013, v_31002);
    }
    v_31002 = nil;
v_30923:
    return onevalue(v_31002);
}



// Code for fast!-augment!-columns

static LispObject CC_fastKaugmentKcolumns(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31094, v_31095, v_31096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-9] = v_30919;
    stack[-10] = v_30918;
// end of prologue
    v_31094 = stack[-10];
    fn = elt(env, 1); // fast!-row!-dim
    v_31094 = (*qfn1(fn))(fn, v_31094);
    env = stack[-12];
    stack[-8] = v_31094;
    v_31094 = stack[-9];
    v_31094 = Llength(nil, v_31094);
    env = stack[-12];
    stack[-6] = v_31094;
    v_31094 = stack[-8];
    v_31094 = sub1(v_31094);
    env = stack[-12];
    v_31094 = Lmkvect(nil, v_31094);
    env = stack[-12];
    stack[-11] = v_31094;
    v_31094 = stack[-9];
    if (!consp(v_31094)) goto v_30937;
    else goto v_30938;
v_30937:
    v_31094 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_31094;
v_30943:
    goto v_30955;
v_30951:
    v_31094 = stack[-8];
    v_31095 = sub1(v_31094);
    env = stack[-12];
    goto v_30952;
v_30953:
    v_31094 = stack[-3];
    goto v_30954;
v_30955:
    goto v_30951;
v_30952:
    goto v_30953;
v_30954:
    v_31094 = difference2(v_31095, v_31094);
    env = stack[-12];
    v_31094 = Lminusp(nil, v_31094);
    env = stack[-12];
    if (v_31094 == nil) goto v_30948;
    goto v_30942;
v_30948:
    v_31094 = (LispObject)0+TAG_FIXNUM; // 0
    v_31094 = Lmkvect(nil, v_31094);
    env = stack[-12];
    stack[-7] = v_31094;
    goto v_30969;
v_30963:
    stack[-2] = stack[-7];
    goto v_30964;
v_30965:
    stack[-1] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30966;
v_30967:
    goto v_30979;
v_30973:
    stack[0] = stack[-10];
    goto v_30974;
v_30975:
    v_31094 = stack[-3];
    v_31095 = add1(v_31094);
    env = stack[-12];
    goto v_30976;
v_30977:
    v_31094 = stack[-9];
    goto v_30978;
v_30979:
    goto v_30973;
v_30974:
    goto v_30975;
v_30976:
    goto v_30977;
v_30978:
    fn = elt(env, 2); // sc_getmat
    v_31094 = (*qfnn(fn))(fn, 3, stack[0], v_31095, v_31094);
    env = stack[-12];
    goto v_30968;
v_30969:
    goto v_30963;
v_30964:
    goto v_30965;
v_30966:
    goto v_30967;
v_30968:
    fn = elt(env, 3); // sc_iputv
    v_31094 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_31094);
    env = stack[-12];
    goto v_30991;
v_30985:
    v_31096 = stack[-11];
    goto v_30986;
v_30987:
    v_31095 = stack[-3];
    goto v_30988;
v_30989:
    v_31094 = stack[-7];
    goto v_30990;
v_30991:
    goto v_30985;
v_30986:
    goto v_30987;
v_30988:
    goto v_30989;
v_30990:
    fn = elt(env, 3); // sc_iputv
    v_31094 = (*qfnn(fn))(fn, 3, v_31096, v_31095, v_31094);
    env = stack[-12];
    v_31094 = stack[-3];
    v_31094 = add1(v_31094);
    env = stack[-12];
    stack[-3] = v_31094;
    goto v_30943;
v_30942:
    goto v_30936;
v_30938:
    v_31094 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_31094;
v_31002:
    goto v_31014;
v_31010:
    v_31094 = stack[-8];
    v_31095 = sub1(v_31094);
    env = stack[-12];
    goto v_31011;
v_31012:
    v_31094 = stack[-5];
    goto v_31013;
v_31014:
    goto v_31010;
v_31011:
    goto v_31012;
v_31013:
    v_31094 = difference2(v_31095, v_31094);
    env = stack[-12];
    v_31094 = Lminusp(nil, v_31094);
    env = stack[-12];
    if (v_31094 == nil) goto v_31007;
    goto v_31001;
v_31007:
    v_31094 = stack[-6];
    v_31094 = sub1(v_31094);
    env = stack[-12];
    v_31094 = Lmkvect(nil, v_31094);
    env = stack[-12];
    stack[-7] = v_31094;
    v_31094 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_31094;
v_31025:
    goto v_31037;
v_31033:
    v_31094 = stack[-6];
    v_31095 = sub1(v_31094);
    env = stack[-12];
    goto v_31034;
v_31035:
    v_31094 = stack[-4];
    goto v_31036;
v_31037:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    v_31094 = difference2(v_31095, v_31094);
    env = stack[-12];
    v_31094 = Lminusp(nil, v_31094);
    env = stack[-12];
    if (v_31094 == nil) goto v_31030;
    goto v_31024;
v_31030:
    goto v_31047;
v_31043:
    stack[0] = stack[-10];
    goto v_31044;
v_31045:
    v_31094 = stack[-5];
    v_31094 = add1(v_31094);
    env = stack[-12];
    goto v_31046;
v_31047:
    goto v_31043;
v_31044:
    goto v_31045;
v_31046:
    fn = elt(env, 4); // sc_getrow
    v_31094 = (*qfn2(fn))(fn, stack[0], v_31094);
    env = stack[-12];
    goto v_31058;
v_31052:
    stack[-3] = stack[-7];
    goto v_31053;
v_31054:
    stack[-2] = stack[-4];
    goto v_31055;
v_31056:
    goto v_31066;
v_31062:
    stack[-1] = v_31094;
    goto v_31063;
v_31064:
    goto v_31074;
v_31070:
    stack[0] = stack[-9];
    goto v_31071;
v_31072:
    v_31094 = stack[-4];
    v_31094 = add1(v_31094);
    env = stack[-12];
    goto v_31073;
v_31074:
    goto v_31070;
v_31071:
    goto v_31072;
v_31073:
    fn = elt(env, 5); // nth
    v_31094 = (*qfn2(fn))(fn, stack[0], v_31094);
    env = stack[-12];
    v_31094 = sub1(v_31094);
    env = stack[-12];
    goto v_31065;
v_31066:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    fn = elt(env, 6); // sc_igetv
    v_31094 = (*qfn2(fn))(fn, stack[-1], v_31094);
    env = stack[-12];
    goto v_31057;
v_31058:
    goto v_31052;
v_31053:
    goto v_31054;
v_31055:
    goto v_31056;
v_31057:
    fn = elt(env, 3); // sc_iputv
    v_31094 = (*qfnn(fn))(fn, 3, stack[-3], stack[-2], v_31094);
    env = stack[-12];
    v_31094 = stack[-4];
    v_31094 = add1(v_31094);
    env = stack[-12];
    stack[-4] = v_31094;
    goto v_31025;
v_31024:
    goto v_31087;
v_31081:
    v_31096 = stack[-11];
    goto v_31082;
v_31083:
    v_31095 = stack[-5];
    goto v_31084;
v_31085:
    v_31094 = stack[-7];
    goto v_31086;
v_31087:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    goto v_31085;
v_31086:
    fn = elt(env, 3); // sc_iputv
    v_31094 = (*qfnn(fn))(fn, 3, v_31096, v_31095, v_31094);
    env = stack[-12];
    v_31094 = stack[-5];
    v_31094 = add1(v_31094);
    env = stack[-12];
    stack[-5] = v_31094;
    goto v_31002;
v_31001:
    goto v_30936;
v_30936:
    v_31094 = stack[-11];
    return onevalue(v_31094);
}



// Code for atlas_edges

static LispObject CC_atlas_edges(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30944;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30918;
// end of prologue
    goto v_30925;
v_30921:
    goto v_30931;
v_30927:
    v_30944 = stack[0];
    v_30944 = qcar(v_30944);
    fn = elt(env, 1); // map__edges
    stack[-1] = (*qfn1(fn))(fn, v_30944);
    env = stack[-2];
    goto v_30928;
v_30929:
    v_30944 = stack[0];
    v_30944 = qcdr(v_30944);
    v_30944 = qcdr(v_30944);
    v_30944 = qcar(v_30944);
    fn = elt(env, 2); // den__edges
    v_30944 = (*qfn1(fn))(fn, v_30944);
    env = stack[-2];
    goto v_30930;
v_30931:
    goto v_30927;
v_30928:
    goto v_30929;
v_30930:
    fn = elt(env, 3); // union_edges
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_30944);
    env = stack[-2];
    goto v_30922;
v_30923:
    v_30944 = stack[0];
    v_30944 = qcdr(v_30944);
    v_30944 = qcar(v_30944);
    fn = elt(env, 4); // coeff_edges
    v_30944 = (*qfn1(fn))(fn, v_30944);
    env = stack[-2];
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    {
        LispObject v_30947 = stack[-1];
        fn = elt(env, 3); // union_edges
        return (*qfn2(fn))(fn, v_30947, v_30944);
    }
}



// Code for compactf3

static LispObject CC_compactf3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30951, v_30952, v_30953;
    LispObject fn;
    LispObject v_30920, v_30919, v_30918;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "compactf3");
    va_start(aa, nargs);
    v_30918 = va_arg(aa, LispObject);
    v_30919 = va_arg(aa, LispObject);
    v_30920 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30920,v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30918,v_30919,v_30920);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30920;
    stack[-1] = v_30919;
    v_30952 = v_30918;
// end of prologue
// Binding mv!-vars!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // mv!-vars!*
    v_30951 = stack[0];
    qvalue(elt(env, 1)) = v_30951; // mv!-vars!*
    goto v_30931;
v_30927:
    goto v_30939;
v_30933:
    goto v_30945;
v_30941:
    goto v_30942;
v_30943:
    v_30951 = stack[0];
    goto v_30944;
v_30945:
    goto v_30941;
v_30942:
    goto v_30943;
v_30944:
    fn = elt(env, 2); // sf2mv
    v_30953 = (*qfn2(fn))(fn, v_30952, v_30951);
    env = stack[-3];
    goto v_30934;
v_30935:
    v_30952 = stack[-1];
    goto v_30936;
v_30937:
    v_30951 = nil;
    goto v_30938;
v_30939:
    goto v_30933;
v_30934:
    goto v_30935;
v_30936:
    goto v_30937;
v_30938:
    fn = elt(env, 3); // mv!-compact
    v_30952 = (*qfnn(fn))(fn, 3, v_30953, v_30952, v_30951);
    env = stack[-3];
    goto v_30928;
v_30929:
    v_30951 = stack[0];
    goto v_30930;
v_30931:
    goto v_30927;
v_30928:
    goto v_30929;
v_30930:
    fn = elt(env, 4); // mv2sf
    v_30951 = (*qfn2(fn))(fn, v_30952, v_30951);
    ;}  // end of a binding scope
    return onevalue(v_30951);
}



// Code for mo!=pair

static LispObject CC_moMpair(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30960, v_30961, v_30962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30919;
    stack[-1] = v_30918;
// end of prologue
    v_30960 = nil;
v_30924:
    v_30961 = stack[-1];
    if (v_30961 == nil) goto v_30931;
    else goto v_30932;
v_30931:
    v_30961 = lisp_true;
    goto v_30930;
v_30932:
    v_30961 = stack[0];
    v_30961 = (v_30961 == nil ? lisp_true : nil);
    goto v_30930;
    v_30961 = nil;
v_30930:
    if (v_30961 == nil) goto v_30928;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30960);
    }
v_30928:
    goto v_30950;
v_30944:
    v_30961 = stack[-1];
    v_30962 = qcar(v_30961);
    goto v_30945;
v_30946:
    v_30961 = stack[0];
    v_30961 = qcar(v_30961);
    goto v_30947;
v_30948:
    goto v_30949;
v_30950:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    goto v_30948;
v_30949:
    v_30960 = acons(v_30962, v_30961, v_30960);
    env = stack[-2];
    v_30961 = stack[-1];
    v_30961 = qcdr(v_30961);
    stack[-1] = v_30961;
    v_30961 = stack[0];
    v_30961 = qcdr(v_30961);
    stack[0] = v_30961;
    goto v_30924;
    v_30960 = nil;
    return onevalue(v_30960);
}



// Code for !*v2j

static LispObject CC_Hv2j(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30956, v_30957, v_30958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30958 = v_30918;
// end of prologue
    goto v_30928;
v_30924:
    v_30957 = qvalue(elt(env, 1)); // ordering
    goto v_30925;
v_30926:
    v_30956 = elt(env, 2); // lex
    goto v_30927;
v_30928:
    goto v_30924;
v_30925:
    goto v_30926;
v_30927:
    if (v_30957 == v_30956) goto v_30922;
    else goto v_30923;
v_30922:
    goto v_30936;
v_30932:
    v_30957 = v_30958;
    goto v_30933;
v_30934:
    v_30956 = qvalue(elt(env, 3)); // varlist!*
    goto v_30935;
v_30936:
    goto v_30932;
v_30933:
    goto v_30934;
v_30935:
    {
        fn = elt(env, 4); // sub01
        return (*qfn2(fn))(fn, v_30957, v_30956);
    }
v_30923:
    goto v_30946;
v_30942:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30943;
v_30944:
    goto v_30953;
v_30949:
    v_30957 = v_30958;
    goto v_30950;
v_30951:
    v_30956 = qvalue(elt(env, 3)); // varlist!*
    goto v_30952;
v_30953:
    goto v_30949;
v_30950:
    goto v_30951;
v_30952:
    fn = elt(env, 4); // sub01
    v_30956 = (*qfn2(fn))(fn, v_30957, v_30956);
    goto v_30945;
v_30946:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    {
        LispObject v_30960 = stack[0];
        return cons(v_30960, v_30956);
    }
    v_30956 = nil;
    return onevalue(v_30956);
}



// Code for dummy_nam

static LispObject CC_dummy_nam(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30930, v_30931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30930 = v_30918;
// end of prologue
    goto v_30925;
v_30921:
    fn = elt(env, 3); // ordn
    v_30931 = (*qfn1(fn))(fn, v_30930);
    env = stack[0];
    goto v_30922;
v_30923:
    v_30930 = elt(env, 1); // symbolic
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    fn = elt(env, 4); // list2vect!*
    v_30930 = (*qfn2(fn))(fn, v_30931, v_30930);
    env = stack[0];
    qvalue(elt(env, 2)) = v_30930; // g_dvnames
    v_30930 = lisp_true;
    return onevalue(v_30930);
}



// Code for general!-negate!-term

static LispObject CC_generalKnegateKterm(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30931, v_30932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30932 = v_30918;
// end of prologue
    goto v_30925;
v_30921:
    v_30931 = v_30932;
    stack[0] = qcar(v_30931);
    goto v_30922;
v_30923:
    v_30931 = v_30932;
    v_30931 = qcdr(v_30931);
    fn = elt(env, 1); // general!-minus!-mod!-p
    v_30931 = (*qfn1(fn))(fn, v_30931);
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    {
        LispObject v_30934 = stack[0];
        return cons(v_30934, v_30931);
    }
}



// Code for initmonomials

static LispObject CC_initmonomials(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30959, v_30960;
    LispObject fn;
    argcheck(nargs, 0, "initmonomials");
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
    v_30959 = qvalue(elt(env, 1)); // fluidbibasisvariables
    v_30959 = Llength(nil, v_30959);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_30959; // fluidbibasisnumberofvariables
    v_30959 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    v_30959 = Lmkvect(nil, v_30959);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_30959; // fluidbibasissinglevariablemonomialss
    v_30959 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_30959;
v_30928:
    goto v_30940;
v_30936:
    v_30960 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    goto v_30937;
v_30938:
    v_30959 = stack[-2];
    goto v_30939;
v_30940:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    v_30959 = difference2(v_30960, v_30959);
    env = stack[-3];
    v_30959 = Lminusp(nil, v_30959);
    env = stack[-3];
    if (v_30959 == nil) goto v_30933;
    goto v_30927;
v_30933:
    goto v_30950;
v_30944:
    stack[-1] = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_30945;
v_30946:
    stack[0] = stack[-2];
    goto v_30947;
v_30948:
    v_30959 = stack[-2];
    fn = elt(env, 5); // createsinglevariablemonom
    v_30959 = (*qfn1(fn))(fn, v_30959);
    env = stack[-3];
    goto v_30949;
v_30950:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    goto v_30948;
v_30949:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_30959;
    v_30959 = stack[-2];
    v_30959 = add1(v_30959);
    env = stack[-3];
    stack[-2] = v_30959;
    goto v_30928;
v_30927:
    v_30959 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_30959; // fluidbibasistripleid
    v_30959 = nil;
    return onevalue(v_30959);
}



// Code for rl_ex

static LispObject CC_rl_ex(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30936, v_30937;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30936 = v_30919;
    v_30937 = v_30918;
// end of prologue
    goto v_30926;
v_30922:
    stack[0] = qvalue(elt(env, 1)); // rl_ex!*
    goto v_30923;
v_30924:
    goto v_30933;
v_30929:
    goto v_30930;
v_30931:
    goto v_30932;
v_30933:
    goto v_30929;
v_30930:
    goto v_30931;
v_30932:
    v_30936 = list2(v_30937, v_30936);
    env = stack[-1];
    goto v_30925;
v_30926:
    goto v_30922;
v_30923:
    goto v_30924;
v_30925:
    {
        LispObject v_30939 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_30939, v_30936);
    }
}



// Code for !*invsq

static LispObject CC_Hinvsq(LispObject env,
                         LispObject v_30918)
{
    env = qenv(env);
    LispObject v_30932, v_30933;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30918);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30933 = v_30918;
// end of prologue
    v_30932 = qvalue(elt(env, 1)); // sqrtflag
    if (v_30932 == nil) goto v_30923;
    v_30932 = v_30933;
    fn = elt(env, 2); // invsq
    v_30932 = (*qfn1(fn))(fn, v_30932);
    env = stack[0];
    {
        fn = elt(env, 3); // sqrt2top
        return (*qfn1(fn))(fn, v_30932);
    }
v_30923:
    v_30932 = v_30933;
    {
        fn = elt(env, 2); // invsq
        return (*qfn1(fn))(fn, v_30932);
    }
    v_30932 = nil;
    return onevalue(v_30932);
}



// Code for multtaylorsq

static LispObject CC_multtaylorsq(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_31071, v_31072;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_30919;
    stack[-6] = v_30918;
// end of prologue
    v_31071 = stack[-6];
    if (v_31071 == nil) goto v_30927;
    else goto v_30928;
v_30927:
    v_31071 = lisp_true;
    goto v_30926;
v_30928:
    v_31071 = stack[-5];
    v_31071 = qcar(v_31071);
    v_31071 = (v_31071 == nil ? lisp_true : nil);
    goto v_30926;
    v_31071 = nil;
v_30926:
    if (v_31071 == nil) goto v_30924;
    v_31071 = nil;
    goto v_30922;
v_30924:
    goto v_30948;
v_30940:
    stack[-7] = elt(env, 1); // taylor!*
    goto v_30941;
v_30942:
    v_31071 = stack[-6];
    v_31071 = qcdr(v_31071);
    v_31071 = qcar(v_31071);
    stack[-4] = v_31071;
    v_31071 = stack[-4];
    if (v_31071 == nil) goto v_30961;
    else goto v_30962;
v_30961:
    v_31071 = nil;
    stack[-1] = v_31071;
    goto v_30954;
v_30962:
    v_31071 = stack[-4];
    v_31071 = qcar(v_31071);
    v_31072 = v_31071;
    goto v_30974;
v_30970:
    v_31071 = v_31072;
    stack[0] = qcar(v_31071);
    goto v_30971;
v_30972:
    goto v_30984;
v_30980:
    v_31071 = v_31072;
    v_31072 = qcdr(v_31071);
    goto v_30981;
v_30982:
    v_31071 = stack[-5];
    goto v_30983;
v_30984:
    goto v_30980;
v_30981:
    goto v_30982;
v_30983:
    fn = elt(env, 3); // multsq
    v_31071 = (*qfn2(fn))(fn, v_31072, v_31071);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_31071 = (*qfn1(fn))(fn, v_31071);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_31071 = (*qfn1(fn))(fn, v_31071);
    env = stack[-8];
    goto v_30973;
v_30974:
    goto v_30970;
v_30971:
    goto v_30972;
v_30973:
    v_31071 = cons(stack[0], v_31071);
    env = stack[-8];
    v_31071 = ncons(v_31071);
    env = stack[-8];
    stack[-2] = v_31071;
    stack[-3] = v_31071;
v_30955:
    v_31071 = stack[-4];
    v_31071 = qcdr(v_31071);
    stack[-4] = v_31071;
    v_31071 = stack[-4];
    if (v_31071 == nil) goto v_30992;
    else goto v_30993;
v_30992:
    v_31071 = stack[-3];
    stack[-1] = v_31071;
    goto v_30954;
v_30993:
    goto v_31001;
v_30997:
    stack[-1] = stack[-2];
    goto v_30998;
v_30999:
    v_31071 = stack[-4];
    v_31071 = qcar(v_31071);
    v_31072 = v_31071;
    goto v_31012;
v_31008:
    v_31071 = v_31072;
    stack[0] = qcar(v_31071);
    goto v_31009;
v_31010:
    goto v_31022;
v_31018:
    v_31071 = v_31072;
    v_31072 = qcdr(v_31071);
    goto v_31019;
v_31020:
    v_31071 = stack[-5];
    goto v_31021;
v_31022:
    goto v_31018;
v_31019:
    goto v_31020;
v_31021:
    fn = elt(env, 3); // multsq
    v_31071 = (*qfn2(fn))(fn, v_31072, v_31071);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_31071 = (*qfn1(fn))(fn, v_31071);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_31071 = (*qfn1(fn))(fn, v_31071);
    env = stack[-8];
    goto v_31011;
v_31012:
    goto v_31008;
v_31009:
    goto v_31010;
v_31011:
    v_31071 = cons(stack[0], v_31071);
    env = stack[-8];
    v_31071 = ncons(v_31071);
    env = stack[-8];
    goto v_31000;
v_31001:
    goto v_30997;
v_30998:
    goto v_30999;
v_31000:
    v_31071 = Lrplacd(nil, stack[-1], v_31071);
    env = stack[-8];
    v_31071 = stack[-2];
    v_31071 = qcdr(v_31071);
    stack[-2] = v_31071;
    goto v_30955;
v_30954:
    goto v_30943;
v_30944:
    v_31071 = stack[-6];
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    stack[0] = qcar(v_31071);
    goto v_30945;
v_30946:
    goto v_31037;
v_31033:
    v_31071 = qvalue(elt(env, 2)); // !*taylorkeeporiginal
    if (v_31071 == nil) goto v_31041;
    v_31071 = stack[-6];
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcar(v_31071);
    if (v_31071 == nil) goto v_31041;
    goto v_31055;
v_31051:
    v_31072 = stack[-5];
    goto v_31052;
v_31053:
    v_31071 = stack[-6];
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcar(v_31071);
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    fn = elt(env, 3); // multsq
    v_31071 = (*qfn2(fn))(fn, v_31072, v_31071);
    env = stack[-8];
    v_31072 = v_31071;
    goto v_31039;
v_31041:
    v_31071 = nil;
    v_31072 = v_31071;
    goto v_31039;
    v_31072 = nil;
v_31039:
    goto v_31034;
v_31035:
    v_31071 = stack[-6];
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcdr(v_31071);
    v_31071 = qcar(v_31071);
    goto v_31036;
v_31037:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    v_31071 = list2(v_31072, v_31071);
    goto v_30947;
v_30948:
    goto v_30940;
v_30941:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    {
        LispObject v_31081 = stack[-7];
        LispObject v_31082 = stack[-1];
        LispObject v_31083 = stack[0];
        return list3star(v_31081, v_31082, v_31083, v_31071);
    }
    v_31071 = nil;
v_30922:
    return onevalue(v_31071);
}



// Code for depend!-p

static LispObject CC_dependKp(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30980, v_30981, v_30982, v_30983;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30982 = v_30919;
    v_30983 = v_30918;
// end of prologue
    goto v_30929;
v_30925:
    v_30981 = v_30983;
    goto v_30926;
v_30927:
    v_30980 = v_30982;
    goto v_30928;
v_30929:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    if (v_30981 == v_30980) goto v_30923;
    else goto v_30924;
v_30923:
    v_30980 = lisp_true;
    goto v_30922;
v_30924:
    v_30980 = v_30983;
    if (!consp(v_30980)) goto v_30933;
    else goto v_30934;
v_30933:
    v_30980 = nil;
    goto v_30922;
v_30934:
    v_30980 = v_30983;
    v_30980 = qcar(v_30980);
    if (!consp(v_30980)) goto v_30938;
    goto v_30946;
v_30942:
    v_30980 = v_30983;
    goto v_30943;
v_30944:
    v_30981 = v_30982;
    goto v_30945;
v_30946:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    {
        fn = elt(env, 2); // depend!-f
        return (*qfn2(fn))(fn, v_30980, v_30981);
    }
v_30938:
    goto v_30955;
v_30951:
    v_30980 = v_30983;
    v_30981 = qcar(v_30980);
    goto v_30952;
v_30953:
    v_30980 = elt(env, 1); // !*sq
    goto v_30954;
v_30955:
    goto v_30951;
v_30952:
    goto v_30953;
v_30954:
    if (v_30981 == v_30980) goto v_30949;
    else goto v_30950;
v_30949:
    goto v_30964;
v_30960:
    v_30980 = v_30983;
    v_30980 = qcdr(v_30980);
    v_30980 = qcar(v_30980);
    goto v_30961;
v_30962:
    v_30981 = v_30982;
    goto v_30963;
v_30964:
    goto v_30960;
v_30961:
    goto v_30962;
v_30963:
    {
        fn = elt(env, 3); // depend!-sq
        return (*qfn2(fn))(fn, v_30980, v_30981);
    }
v_30950:
    goto v_30976;
v_30972:
    v_30980 = v_30983;
    v_30980 = qcdr(v_30980);
    goto v_30973;
v_30974:
    v_30981 = v_30982;
    goto v_30975;
v_30976:
    goto v_30972;
v_30973:
    goto v_30974;
v_30975:
    {
        fn = elt(env, 4); // depend!-l
        return (*qfn2(fn))(fn, v_30980, v_30981);
    }
    v_30980 = nil;
v_30922:
    return onevalue(v_30980);
}



// Code for qqe_length!-graph!-bterm

static LispObject CC_qqe_lengthKgraphKbterm(LispObject env,
                         LispObject v_30918, LispObject v_30919)
{
    env = qenv(env);
    LispObject v_30987, v_30988;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30919,v_30918);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30918,v_30919);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30919;
    stack[-1] = v_30918;
// end of prologue
    v_30987 = stack[-1];
    if (v_30987 == nil) goto v_30929;
    else goto v_30930;
v_30929:
    v_30987 = lisp_true;
    goto v_30928;
v_30930:
    v_30987 = stack[-1];
    v_30987 = (consp(v_30987) ? nil : lisp_true);
    goto v_30928;
    v_30987 = nil;
v_30928:
    if (v_30987 == nil) goto v_30926;
    v_30987 = stack[0];
    goto v_30922;
v_30926:
    goto v_30946;
v_30942:
    v_30987 = stack[-1];
    fn = elt(env, 2); // qqe_op
    v_30988 = (*qfn1(fn))(fn, v_30987);
    env = stack[-2];
    goto v_30943;
v_30944:
    v_30987 = elt(env, 1); // (lhead rhead)
    goto v_30945;
v_30946:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    v_30987 = Lmemq(nil, v_30988, v_30987);
    if (v_30987 == nil) goto v_30941;
    goto v_30956;
v_30952:
    v_30988 = stack[-1];
    goto v_30953;
v_30954:
    v_30987 = stack[0];
    goto v_30955;
v_30956:
    goto v_30952;
v_30953:
    goto v_30954;
v_30955:
    fn = elt(env, 3); // qqe_length!-graph!-bterm!-update!-headmin
    v_30987 = (*qfn2(fn))(fn, v_30988, v_30987);
    stack[0] = v_30987;
    goto v_30939;
v_30941:
    v_30987 = stack[-1];
    v_30987 = qcdr(v_30987);
    stack[-1] = v_30987;
v_30964:
    v_30987 = stack[-1];
    if (v_30987 == nil) goto v_30969;
    else goto v_30970;
v_30969:
    goto v_30963;
v_30970:
    v_30987 = stack[-1];
    v_30987 = qcar(v_30987);
    goto v_30981;
v_30977:
    v_30988 = v_30987;
    goto v_30978;
v_30979:
    v_30987 = stack[0];
    goto v_30980;
v_30981:
    goto v_30977;
v_30978:
    goto v_30979;
v_30980:
    v_30987 = CC_qqe_lengthKgraphKbterm(elt(env, 0), v_30988, v_30987);
    env = stack[-2];
    stack[0] = v_30987;
    v_30987 = stack[-1];
    v_30987 = qcdr(v_30987);
    stack[-1] = v_30987;
    goto v_30964;
v_30963:
    goto v_30939;
v_30939:
    v_30987 = stack[0];
v_30922:
    return onevalue(v_30987);
}



setup_type const u52_setup[] =
{
    {"rand-mons-sparse",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randKmonsKsparse},
    {"redassignp",              CC_redassignp,  TOO_MANY_1,    WRONG_NO_1},
    {"coeff1_calc",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff1_calc},
    {"clogsq",                  CC_clogsq,      TOO_MANY_1,    WRONG_NO_1},
    {"dp_2a",                   CC_dp_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"mod/",                    TOO_FEW_2,      CC_modV,       WRONG_NO_2},
    {"cde_alglistp",            CC_cde_alglistp,TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_sminsert",           TOO_FEW_2,      CC_ofsf_sminsert,WRONG_NO_2},
    {"addfactors",              TOO_FEW_2,      CC_addfactors, WRONG_NO_2},
    {"subdf",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subdf},
    {"cl_strict-gdnf",          TOO_FEW_2,      CC_cl_strictKgdnf,WRONG_NO_2},
    {"make-image-mod-p",        TOO_FEW_2,      CC_makeKimageKmodKp,WRONG_NO_2},
    {"getvariables",            CC_getvariables,TOO_MANY_1,    WRONG_NO_1},
    {"indordlp",                TOO_FEW_2,      CC_indordlp,   WRONG_NO_2},
    {"adjp",                    CC_adjp,        TOO_MANY_1,    WRONG_NO_1},
    {"store_edges",             CC_store_edges, TOO_MANY_1,    WRONG_NO_1},
    {"lchk",                    CC_lchk,        TOO_MANY_1,    WRONG_NO_1},
    {"cr2rderr",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cr2rderr},
    {"cde_list2id",             CC_cde_list2id, TOO_MANY_1,    WRONG_NO_1},
    {"sfto_deggcd1",            TOO_FEW_2,      CC_sfto_deggcd1,WRONG_NO_2},
    {"preptaylor**",            CC_preptaylorHH,TOO_MANY_1,    WRONG_NO_1},
    {"simpx1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpx1},
    {"equal+matrices+p",        TOO_FEW_2,      CC_equalLmatricesLp,WRONG_NO_2},
    {"talp_try2",               CC_talp_try2,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_simpat",             CC_ofsf_simpat, TOO_MANY_1,    WRONG_NO_1},
    {"quotfx1",                 TOO_FEW_2,      CC_quotfx1,    WRONG_NO_2},
    {"sfto_dprpartf1",          TOO_FEW_2,      CC_sfto_dprpartf1,WRONG_NO_2},
    {"parseml",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_parseml},
    {"ldf-pow-var",             CC_ldfKpowKvar, TOO_MANY_1,    WRONG_NO_1},
    {"vdpappendmon",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpappendmon},
    {"fast-augment-columns",    TOO_FEW_2,      CC_fastKaugmentKcolumns,WRONG_NO_2},
    {"atlas_edges",             CC_atlas_edges, TOO_MANY_1,    WRONG_NO_1},
    {"compactf3",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf3},
    {"mo=pair",                 TOO_FEW_2,      CC_moMpair,    WRONG_NO_2},
    {"*v2j",                    CC_Hv2j,        TOO_MANY_1,    WRONG_NO_1},
    {"dummy_nam",               CC_dummy_nam,   TOO_MANY_1,    WRONG_NO_1},
    {"general-negate-term",     CC_generalKnegateKterm,TOO_MANY_1,WRONG_NO_1},
    {"initmonomials",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_initmonomials},
    {"rl_ex",                   TOO_FEW_2,      CC_rl_ex,      WRONG_NO_2},
    {"*invsq",                  CC_Hinvsq,      TOO_MANY_1,    WRONG_NO_1},
    {"multtaylorsq",            TOO_FEW_2,      CC_multtaylorsq,WRONG_NO_2},
    {"depend-p",                TOO_FEW_2,      CC_dependKp,   WRONG_NO_2},
    {"qqe_length-graph-bterm",  TOO_FEW_2,      CC_qqe_lengthKgraphKbterm,WRONG_NO_2},
    {NULL, (one_args *)"u52", (two_args *)"101979 3141102 194764", 0}
};

// end of generated code
